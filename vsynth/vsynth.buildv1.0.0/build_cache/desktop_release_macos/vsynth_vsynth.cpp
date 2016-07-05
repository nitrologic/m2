
#include "vsynth_vsynth.h"

// ***** External *****

#include "../../../../../../monkey2/modules/mojo/mojo.buildv1.0.0/desktop_release_macos/mojo_app_2app.h"
#include "../../../../../../monkey2/modules/mojo/mojo.buildv1.0.0/desktop_release_macos/mojo_app_2event.h"
#include "../../../../../../monkey2/modules/mojo/mojo.buildv1.0.0/desktop_release_macos/mojo_graphics_2canvas.h"
#include "../../../../../../monkey2/modules/mojo/mojo.buildv1.0.0/desktop_release_macos/mojo_std_collections_2map.h"
#include "../../../../../../monkey2/modules/monkey/monkey.buildv1.0.0/desktop_release_macos/monkey_math.h"
#include "../../../../../../monkey2/modules/portmidi/portmidi.buildv1.0.0/desktop_release_macos/portmidi_portmidi.h"
#include "../../../../../../monkey2/modules/sdl2-mixer/sdl2-mixer.buildv1.0.0/desktop_release_macos/sdl2_5mixer_sdl2_5mixer.h"
#include "../../../../../../monkey2/modules/std/std.buildv1.0.0/desktop_release_macos/std_collections_2stack.h"
#include "../../../../../../monkey2/modules/std/std.buildv1.0.0/desktop_release_macos/std_geom_2vec2.h"
#include "vsynth_audiopipe.h"
#include "vsynth_std_collections_2list.h"
#include "vsynth_std_collections_2map.h"
#include "vsynth_std_collections_2stack.h"

extern bbDouble g_monkey_math_Abs_1d(bbDouble l_x);
extern bbDouble g_std_random_Rnd();
extern bbInt g_monkey_math_Clamp_1i(bbInt l_value,bbInt l_min,bbInt l_max);

// ***** Internal *****

bbGCRootVar<t_portmidi_PortMidi> g_default_portMidi;
bbString g_default_AppTitle;
bbString g_default_Contact;
bbString g_default_About;
bbString g_default_Octave1;
bbString g_default_Octave0;
bbString g_default_Controls;
bbGCRootVar<bbArray<bbString>> g_default_OscillatorNames;
bbGCRootVar<bbArray<bbString>> g_default_EnvelopeNames;
bbGCRootVar<bbArray<bbString>> g_default_ArpNames;
bbGCRootVar<bbArray<bbString>> g_default_SynthNames;
bbGCRootVar<bbArray<bbString>> g_default_DivisorNames;
bbGCRootVar<t_mojo_app_AppInstance> g_default_instance;
bbGCRootVar<t_default_VSynth> g_default_vsynth;
bbInt g_default_Duration;
bbInt g_default_FragmentSize;
bbInt g_default_WriteAhead;
bbInt g_default_AudioFrequency;
bbInt g_default_MaxPolyphony;
bbInt g_default_MaxOctave;
bbGCRootVar<bbArray<bbInt>> g_default_VSynthWindow_MusicKeys;

bbInt g_default_VSynthWindow_Limit(bbInt l_value,bbInt l_lo,bbInt l_hi){
  if((l_value<l_lo)){
    return l_lo;
  }
  if((l_value>l_hi)){
    return l_hi;
  }
  return l_value;
}

void bbMain(){
  static bool done;
  if(done) return;
  done=true;
  void mx2_mojo_main();mx2_mojo_main();
  void mx2_std_main();mx2_std_main();
  g_default_instance=bbGCNew<t_mojo_app_AppInstance>();
  g_default_InitMidi();
  bbGCNew<t_default_VSynthWindow>(g_default_AppTitle);
  g_mojo_app_App->m_Run();
}

bbInt g_default_Wrap(bbInt l_value,bbInt l_lower,bbInt l_upper){
  if((l_value<l_lower)){
    l_value=(l_upper-1);
  }
  if((l_value>=l_upper)){
    l_value=l_lower;
  }
  return l_value;
}

bbString g_default_FloatString(bbFloat l_value,bbInt l_dp){
  bbString l_sign{};
  bbInt l_integral=bbInt((bbDouble(l_value)*std::pow(10.0,bbDouble(l_dp))));
  if((l_integral<bbInt(0))){
    l_sign=BB_T("-");
    l_integral=-l_integral;
  }
  bbString l_a=bbString(l_integral);
  bbInt l_l=((l_dp+1)-l_a.length());
  if((l_l>bbInt(0))){
    l_a=(BB_T("0000000000000").slice(bbInt(0),l_l)+l_a);
  }
  return (l_sign+l_a);
}

void g_default_InitMidi(){
  puts(BB_T("PortMidi test 0.1").c_str());fflush( stdout );
  puts(BB_T("Scanning Midi Bus, please wait.").c_str());fflush( stdout );
  g_default_portMidi=bbGCNew<t_portmidi_PortMidi>();
  bbInt l_inputs=g_default_portMidi->m_inputDevices->m_Length();
  puts((BB_T("inputs=")+bbString(l_inputs)).c_str());fflush( stdout );
  {
    bbInt l_i=bbInt(0);
    for(;(l_i<l_inputs);l_i+=1){
      g_default_portMidi->m_OpenInput(l_i);
    }
  }
}

void t_default_VSynth::init(){
  m_audioPipe=AudioPipe::Create();
  m_poly=bbGCNew<t_default_PolySynth>();
  m_mono=bbGCNew<t_default_MonoSynth>();
  m_arp=bbGCNew<t_default_Arpeggiator>();
  m_buffer=bbArray<bbDouble>::create((g_default_FragmentSize*2));
}

void t_default_VSynth::gcMark(){
  bbGCMark(m_audioSpec);
  bbGCMark(m_poly);
  bbGCMark(m_mono);
  bbGCMark(m_root);
  bbGCMark(m_arp);
  bbGCMark(m_buffer);
}

t_default_VSynth::t_default_VSynth(){
  init();
  this->m_OpenAudio();
  this->m_arp->m_SetSynth(this->m_mono);
  this->m_root=((t_default_Synth*)(this->m_arp));
}

void t_default_VSynth::m_UpdateAudio(){
  while(true){
    bbInt l_buffered=(this->m_audioPipe->writePointer-this->m_audioPipe->readPointer);
    if((l_buffered>=g_default_WriteAhead)){
      break;
    }
    {
      bbInt l_i=bbInt(0);
      for(;(l_i<(g_default_FragmentSize*2));l_i+=1){
        this->m_buffer->at(l_i)=0.0;
      }
    }
    bbInt l_samples=g_default_FragmentSize;
    g_default_vsynth->m_root->m_FillAudioBuffer(this->m_buffer,l_samples,this->m_detune);
    g_default_Duration+=l_samples;
    bbDouble* l_pointer=&this->m_buffer->at(bbInt(0));
    this->m_audioPipe->WriteSamples(l_pointer,(g_default_FragmentSize*2));
  }
}

void t_default_VSynth::m_SetTempo(bbInt l_tempo,bbInt l_divisor){
  this->m_arp->m_SetTempo(l_tempo,l_divisor);
}

void t_default_VSynth::m_SetSynth(bbInt l_synth){
  if(l_synth==bbInt(0)){
    this->m_arp->m_SetSynth(this->m_mono);
  }else if(l_synth==1){
    this->m_arp->m_SetSynth(this->m_poly);
  }
}

void t_default_VSynth::m_OpenAudio(){
  struct f0_t : public bbGCFrame{
    SDL_AudioSpec l_spec{};
    void gcMark(){
      bbGCMark(l_spec);
    }
  }f0{};
  f0.l_spec.freq=g_default_AudioFrequency;
  f0.l_spec.format=bbShort(AUDIO_S16);
  f0.l_spec.channels=2;
  f0.l_spec.samples=bbShort(g_default_FragmentSize);
  f0.l_spec.callback=AudioPipe::Callback;
  f0.l_spec.userdata=this->m_audioPipe->Handle();
  Mix_CloseAudio();
  bbInt l_error=SDL_OpenAudio(&f0.l_spec,&this->m_audioSpec);
  if(bbBool(l_error)){
    puts((((BB_T("error=")+bbString(l_error))+BB_T(" "))+bbString::fromCString(((void*)(SDL_GetError())))).c_str());fflush( stdout );
  }else{
    puts((BB_T("Audio Open freq=")+bbString(this->m_audioSpec.freq)).c_str());fflush( stdout );
    g_default_AudioFrequency=this->m_audioSpec.freq;
  }
  SDL_PauseAudio(bbInt(0));
}

void t_default_VSynth::m_NoteOn(bbInt l_note,bbInt l_oscillator,bbInt l_envelope){
  this->m_root->m_NoteOn(l_note,l_oscillator,l_envelope);
}

void t_default_VSynth::m_NoteOff(bbInt l_note){
  this->m_root->m_NoteOff(l_note);
}

void t_default_VSynth::m_Detune(bbDouble l_bend){
  this->m_detune=l_bend;
}

void t_default_VSynth::m_ClearKeys(){
  this->m_root->m_Panic();
}

bbDouble t_default_Envelope::m_On(){
  return 1.0;
}

bbDouble t_default_Envelope::m_Off(){
  return 0.0;
}

t_default_ADSR::t_default_ADSR(bbDouble l_a,bbDouble l_d,bbDouble l_s,bbDouble l_r){
  this->m_attack=l_a;
  this->m_decay=l_d;
  this->m_sustain=l_s;
  this->m_release=l_r;
}

bbDouble t_default_ADSR::m_On(){
  if(!this->m_noteOn){
    this->m_t=0.0;
    this->m_noteOn=true;
  }
  this->m_t+=bbDouble((1.0f/bbFloat(g_default_AudioFrequency)));
  if((this->m_t<this->m_attack)){
    return (this->m_t/this->m_attack);
  }
  if(((this->m_t-this->m_attack)<this->m_decay)){
    return (1.0-(((1.0-this->m_sustain)*(this->m_t-this->m_attack))/this->m_decay));
  }
  return this->m_sustain;
}

bbDouble t_default_ADSR::m_Off(){
  this->m_noteOn=false;
  this->m_t+=bbDouble((1.0f/bbFloat(g_default_AudioFrequency)));
  if((this->m_t<this->m_release)){
    return (1.0-(this->m_t/this->m_release));
  }
  return 0.0;
}

bbDouble t_default_Oscillator::m_Sample(bbDouble l_hz){
  return 0.0;
}

bbDouble t_default_Sine::m_Sample(bbDouble l_hz){
  bbDouble l_t=(l_hz/bbDouble(g_default_AudioFrequency));
  this->m_delta+=l_t;
  return std::sin((g_monkey_math_Pi*this->m_delta));
}

bbDouble t_default_Sawtooth::m_Sample(bbDouble l_hz){
  bbDouble l_t=(l_hz/bbDouble(g_default_AudioFrequency));
  this->m_delta+=l_t;
  return (std::fmod((this->m_delta+1.0),2.0)-1.0);
}

bbDouble t_default_Triangle::m_Sample(bbDouble l_hz){
  bbDouble l_t=((2.0*l_hz)/bbDouble(g_default_AudioFrequency));
  this->m_delta+=l_t;
  return ((g_monkey_math_Abs_1d(std::fmod(this->m_delta,4.0))-2.0)-1.0);
}

bbDouble t_default_Square::m_Sample(bbDouble l_hz){
  bbDouble l_t=(l_hz/bbDouble(g_default_AudioFrequency));
  this->m_delta+=l_t;
  return bbDouble((-1+(2*(bbInt(this->m_delta)&1))));
}

bbDouble t_default_Noise::m_Sample(bbDouble l_hz){
  bbDouble l_t=(l_hz/bbDouble(g_default_AudioFrequency));
  bbDouble l_delta0=this->m_delta;
  this->m_delta+=l_t;
  bbDouble l_f=std::fmod(this->m_delta,1.0);
  if((bbInt(l_delta0)!=bbInt(this->m_delta))){
    this->m_a=g_std_random_Rnd();
  }
  return (1.0-(2.0*this->m_a));
}

void t_default_Voice::gcMark(){
  bbGCMark(m_oscillator);
  bbGCMark(m_envelope);
}

void t_default_Voice::m_Stop(){
  this->m_NoteOff();
  this->m_envelope->m_Off();
}

void t_default_Voice::m_SetPan(bbDouble l_value){
  this->m_pan=l_value;
}

void t_default_Voice::m_SetOscillator(bbInt l_osc){
  if(l_osc==bbInt(0)){
    this->m_oscillator=((t_default_Oscillator*)(bbGCNew<t_default_Square>()));
  }else if(l_osc==1){
    this->m_oscillator=((t_default_Oscillator*)(bbGCNew<t_default_Sine>()));
  }else if(l_osc==2){
    this->m_oscillator=((t_default_Oscillator*)(bbGCNew<t_default_Sawtooth>()));
  }else if(l_osc==3){
    this->m_oscillator=((t_default_Oscillator*)(bbGCNew<t_default_Triangle>()));
  }else if(l_osc==4){
    this->m_oscillator=((t_default_Oscillator*)(bbGCNew<t_default_Noise>()));
  }
}

void t_default_Voice::m_SetGain(bbDouble l_value){
  this->m_gain=l_value;
}

void t_default_Voice::m_SetEnvelope(bbInt l_env){
  if(l_env==bbInt(0)){
    this->m_envelope=bbGCNew<t_default_Envelope>();
  }else if(l_env==1){
    this->m_envelope=((t_default_Envelope*)(bbGCNew<t_default_ADSR>(0.050000000000000003,1.5,0.20000000000000001,0.29999999999999999)));
  }else if(l_env==2){
    this->m_envelope=((t_default_Envelope*)(bbGCNew<t_default_ADSR>(0.059999999999999998,0.01,0.92000000000000004,0.20000000000000001)));
  }else if(l_env==3){
    this->m_envelope=((t_default_Envelope*)(bbGCNew<t_default_ADSR>(0.059999999999999998,2.0,0.20000000000000001,1.2)));
  }else if(l_env==4){
    this->m_envelope=((t_default_Envelope*)(bbGCNew<t_default_ADSR>(0.20000000000000001,0.20000000000000001,0.92000000000000004,0.40000000000000002)));
  }
}

void t_default_Voice::m_NoteOn(bbInt l_note){
  this->m_hz=(440.0*std::pow(2.0,bbDouble(((bbFloat(l_note)-67.0f)/12.0f))));
  this->m_noteOn=true;
}

void t_default_Voice::m_NoteOff(){
  this->m_noteOn=false;
}

void t_default_Voice::m_Mix(bbArray<bbDouble>* l_buffer,bbInt l_samples,bbDouble l_detune){
  bbFloat l_left=1.0f;
  bbFloat l_right=1.0f;
  if((this->m_pan<0.0)){
    l_right+=bbFloat(this->m_pan);
  }
  if((this->m_pan>0.0)){
    l_left-=bbFloat(this->m_pan);
  }
  {
    bbInt l_i=bbInt(0);
    for(;(l_i<l_samples);l_i+=1){
      bbDouble l_v=this->m_oscillator->m_Sample((this->m_hz*l_detune));
      bbDouble l_e{};
      if(this->m_noteOn){
        l_e=this->m_envelope->m_On();
      }else{
        l_e=this->m_envelope->m_Off();
      }
      l_e*=this->m_gain;
      l_buffer->at(((l_i*2)+bbInt(0)))+=((l_e*bbDouble(l_left))*l_v);
      l_buffer->at(((l_i*2)+1))+=((l_e*bbDouble(l_right))*l_v);
    }
  }
}

void t_default_BeatGenerator::gcMark(){
  bbGCMark(m_output);
}

void t_default_BeatGenerator::m_Update(bbDouble l_duration){
  this->m_time+=l_duration;
  while((this->m_clock<this->m_time)){
    this->m_Beat();
    this->m_clock+=bbDouble((60.0f/bbFloat((this->m_bpm*this->m_divisor))));
  }
}

void t_default_BeatGenerator::m_SetTempo(bbInt l_tempo,bbInt l_div){
  this->m_bpm=l_tempo;
  this->m_divisor=l_div;
}

void t_default_BeatGenerator::m_SetSynth(t_default_Synth* l_synth){
  this->m_output=l_synth;
}

void t_default_BeatGenerator::m_Panic(){
  this->m_output->m_Panic();
}

void t_default_BeatGenerator::m_NoteOn(bbInt l_note,bbInt l_osc,bbInt l_env){
  this->m_recent=l_note;
  this->m_oscillator=l_osc;
  this->m_envelope=l_env;
}

void t_default_BeatGenerator::m_NoteOff(bbInt l_note){
  this->m_output->m_NoteOff(l_note);
}

void t_default_BeatGenerator::m_FillAudioBuffer(bbArray<bbDouble>* l_buffer,bbInt l_samples,bbDouble l_detune){
  this->m_Update(bbDouble(((2.0f*bbFloat(l_samples))/bbFloat(g_default_AudioFrequency))));
  this->m_output->m_FillAudioBuffer(l_buffer,l_samples,l_detune);
}

void t_default_BeatGenerator::m_Beat(){
  if(bbBool(this->m_recent)){
    this->m_NoteOn(this->m_recent,this->m_oscillator,this->m_envelope);
  }
}

void t_default_Arpeggiator::init(){
  m_notes=bbGCNew<t_std_collections_Stack_1i>();
}

void t_default_Arpeggiator::gcMark(){
  t_default_BeatGenerator::gcMark();
  bbGCMark(m_notes);
}

void t_default_Arpeggiator::m_NoteOn(bbInt l_note,bbInt l_osc,bbInt l_env){
  t_default_BeatGenerator::m_NoteOn(l_note,l_osc,l_env);
  this->m_index=this->m_notes->m_Length();
  this->m_notes->m_Push(l_note);
}

void t_default_Arpeggiator::m_NoteOff(bbInt l_note){
  this->m_output->m_NoteOff(l_note);
  this->m_notes->m_Remove(l_note,bbInt(0));
}

void t_default_Arpeggiator::m_Beat(){
  if(bbBool(this->m_notes->m_Length())){
    this->m_index=(this->m_index%this->m_notes->m_Length());
    bbInt l_note=this->m_notes->m__idx(this->m_index);
    this->m_output->m_NoteOn(l_note,this->m_oscillator,this->m_envelope);
  }
  this->m_index+=1;
}

void t_default_PolySynth::init(){
  m_polyList=bbGCNew<t_std_collections_List_1Tt_default_Voice_2>();
  m_polyMap=bbGCNew<t_std_collections_Map_1iTt_default_Voice_2>();
  m_voices=bbGCNew<t_std_collections_Stack_1Tt_default_Voice_2>();
}

void t_default_PolySynth::gcMark(){
  bbGCMark(m_polyList);
  bbGCMark(m_polyMap);
  bbGCMark(m_voices);
}

t_default_PolySynth::t_default_PolySynth(){
  init();
  {
    bbInt l_i=bbInt(0);
    for(;(l_i<g_default_MaxPolyphony);l_i+=1){
      struct f2_t : public bbGCFrame{
        t_default_Voice* l_tone{};
        void gcMark(){
          bbGCMarkPtr(l_tone);
        }
      }f2{};
      f2.l_tone=bbGCNew<t_default_Voice>();
      f2.l_tone->m_SetOscillator(bbInt(0));
      f2.l_tone->m_SetEnvelope(bbInt(0));
      this->m_polyList->m_AddLast(f2.l_tone);
    }
  }
}

void t_default_PolySynth::m_SetTempo(bbInt l_tempo,bbInt l_divisor){
}

void t_default_PolySynth::m_Panic(){
  this->m_voices->m_Clear();
}

void t_default_PolySynth::m_NoteOn(bbInt l_note,bbInt l_oscillator,bbInt l_envelope){
  struct f0_t : public bbGCFrame{
    t_default_Voice* l_voice{};
    void gcMark(){
      bbGCMarkPtr(l_voice);
    }
  }f0{};
  this->m_NoteOff(l_note);
  if(this->m_polyList->m_Empty()){
    return;
  }
  f0.l_voice=this->m_polyList->m_RemoveFirst();
  f0.l_voice->m_SetEnvelope(l_envelope);
  f0.l_voice->m_SetOscillator(l_oscillator);
  f0.l_voice->m_NoteOn(l_note);
  this->m_polyMap->m__idxeq(l_note,f0.l_voice);
  this->m_polyList->m_Remove(f0.l_voice);
  if(!this->m_voices->m_Contains(f0.l_voice)){
    this->m_voices->m_Add(f0.l_voice);
  }
}

void t_default_PolySynth::m_NoteOff(bbInt l_note){
  struct f0_t : public bbGCFrame{
    t_default_Voice* l_voice{};
    void gcMark(){
      bbGCMarkPtr(l_voice);
    }
  }f0{};
  f0.l_voice=this->m_polyMap->m__idx(l_note);
  if(bbBool(f0.l_voice)){
    f0.l_voice->m_Stop();
    this->m_polyMap->m_Remove(l_note);
    this->m_polyList->m_AddLast(f0.l_voice);
  }
}

void t_default_PolySynth::m_FillAudioBuffer(bbArray<bbDouble>* l_buffer,bbInt l_samples,bbDouble l_detune){
  {
    struct f1_t : public bbGCFrame{
      t_std_collections_Stack_1Tt_default_Voice_2_Iterator l_0{};
      void gcMark(){
        bbGCMark(l_0);
      }
    }f1{};
    f1.l_0=this->m_voices->m_All();
    for(;!f1.l_0.m_AtEnd();f1.l_0.m_Bump()){
      struct f2_t : public bbGCFrame{
        t_default_Voice* l_voice{};
        void gcMark(){
          bbGCMarkPtr(l_voice);
        }
      }f2{};
      f2.l_voice=f1.l_0.m_Current();
      f2.l_voice->m_Mix(l_buffer,l_samples,l_detune);
    }
  }
}

void t_default_MonoSynth::init(){
  m_notes=bbGCNew<t_std_collections_Stack_1i>();
}

void t_default_MonoSynth::gcMark(){
  bbGCMark(m_tone);
  bbGCMark(m_notes);
}

t_default_MonoSynth::t_default_MonoSynth(){
  init();
  this->m_tone=bbGCNew<t_default_Voice>();
  this->m_tone->m_SetOscillator(bbInt(0));
  this->m_tone->m_SetEnvelope(bbInt(0));
}

void t_default_MonoSynth::m_SetTempo(bbInt l_tempo,bbInt l_divisor){
}

void t_default_MonoSynth::m_Panic(){
  this->m_tone->m_NoteOff();
}

void t_default_MonoSynth::m_NoteOn(bbInt l_note,bbInt l_oscillator,bbInt l_envelope){
  this->m_monoNote=l_note;
  if(!this->m_notes->m_Contains(l_note)){
    this->m_notes->m_Push(l_note);
  }
  this->m_tone->m_SetOscillator(l_oscillator);
  this->m_tone->m_SetEnvelope(l_envelope);
  this->m_tone->m_NoteOn(l_note);
}

void t_default_MonoSynth::m_NoteOff(bbInt l_note){
  this->m_notes->m_Remove(l_note,bbInt(0));
  if(this->m_notes->m_Empty()){
    this->m_tone->m_NoteOff();
  }else{
    l_note=this->m_notes->m_Pop();
    this->m_monoNote=l_note;
    this->m_notes->m_Push(l_note);
    this->m_tone->m_NoteOn(l_note);
  }
}

void t_default_MonoSynth::m_FillAudioBuffer(bbArray<bbDouble>* l_buffer,bbInt l_samples,bbDouble l_detune){
  this->m_tone->m_Mix(l_buffer,l_samples,l_detune);
}

void t_default_VSynthWindow::init(){
  m_keyNoteMap=bbGCNew<t_std_collections_Map_1TbbInt_2i>();
  m_noteMap=bbGCNew<t_std_collections_Map_1iz>();
}

void t_default_VSynthWindow::gcMark(){
  t_mojo_app_Window::gcMark();
  bbGCMark(m_keyNoteMap);
  bbGCMark(m_noteMap);
}

t_default_VSynthWindow::t_default_VSynthWindow(bbString l_title):t_mojo_app_Window(l_title,720,560,8){
  init();
  {
    bbInt l_i=bbInt(0);
    for(;(l_i<g_default_VSynthWindow_MusicKeys->length());l_i+=1){
      this->m_keyNoteMap->m_Set(g_default_VSynthWindow_MusicKeys->at(l_i),(l_i-1));
    }
  }
  g_default_vsynth=bbGCNew<t_default_VSynth>();
}

void t_default_VSynthWindow::m_UpdateSequence(){
  this->m_frame+=1;
  bbInt l_t=(this->m_frame/20);
  if((l_t!=this->m_tick)){
    bbInt l_note=((((l_t>>1)&15)*3)+40);
    if(bbBool((l_t&1))){
      g_default_vsynth->m_NoteOn(l_note,this->m_oscillator,this->m_envelope);
    }else{
      g_default_vsynth->m_NoteOff(l_note);
    }
    this->m_tick=l_t;
  }
}

void t_default_VSynthWindow::m_PollMidi(){
  static bbInt g_NoteOn=144;
  static bbInt g_NoteOff=128;
  static bbInt g_PitchWheel=224;
  while(bbBool(g_default_portMidi->m_HasEvent())){
    struct f1_t : public bbGCFrame{
      bbArray<bbUByte>* l_b{};
      void gcMark(){
        bbGCMarkPtr(l_b);
      }
    }f1{};
    f1.l_b=g_default_portMidi->m_EventDataBytes();
    puts(((((((bbString(f1.l_b->at(bbInt(0)))+BB_T(" "))+bbString(f1.l_b->at(1)))+BB_T(" "))+bbString(f1.l_b->at(2)))+BB_T(" "))+bbString(f1.l_b->at(3))).c_str());fflush( stdout );
    bbUByte l_note=f1.l_b->at(1);
    bbUByte l_velocity=f1.l_b->at(2);
    bbUInt l_word=((bbUInt(l_velocity)<<7)+bbUInt(l_note));
    if(f1.l_b->at(bbInt(0))==bbUByte(g_NoteOn)){
      g_default_vsynth->m_NoteOn(bbInt(l_note),this->m_oscillator,this->m_envelope);
    }else if(f1.l_b->at(bbInt(0))==bbUByte(g_NoteOff)){
      g_default_vsynth->m_NoteOff(bbInt(l_note));
    }else if(f1.l_b->at(bbInt(0))==bbUByte(g_PitchWheel)){
      puts((BB_T("Pitch=")+bbString(l_word)).c_str());fflush( stdout );
      this->m_pitchbend=bbDouble((1.0f+(bbFloat((l_word-8192))/8192.0f)));
    }
  }
}

void t_default_VSynthWindow::m_OnRender(t_mojo_graphics_Canvas* l_display){
  this->m_PollMidi();
  g_mojo_app_App->m_RequestRender();
  g_default_vsynth->m_Detune(std::pow(2.0,this->m_pitchbend));
  g_default_vsynth->m_SetTempo(this->m_tempo,(1+this->m_div));
  g_default_vsynth->m_UpdateAudio();
  bbString l_text=(((((g_default_About+BB_T(",,"))+g_default_Octave1)+BB_T(","))+g_default_Octave0)+BB_T(","));
  l_text+=(BB_T("Octave=< >=")+bbString(this->m_octave));
  l_text+=(BB_T(",Oscillator=1-5=")+g_default_OscillatorNames->at(this->m_oscillator));
  l_text+=(BB_T(",Envelope=[]=")+g_default_EnvelopeNames->at(this->m_envelope));
  l_text+=(BB_T(",PitchBend=Mouse Wheel=")+g_default_FloatString(bbFloat(this->m_pitchbend),2));
  l_text+=(BB_T(",,Arpeggiator=F5-F8=")+g_default_ArpNames->at(this->m_arp));
  l_text+=(BB_T(",Note Divisor=/=")+g_default_DivisorNames->at(this->m_div));
  l_text+=(BB_T(",,Synth=Enter Key=")+g_default_SynthNames->at(this->m_synth));
  l_text+=(BB_T(",,Tempo=- +=")+bbString(this->m_tempo));
  l_text+=(((BB_T(",,")+g_default_Controls)+BB_T(",,"))+g_default_Contact);
  bbInt l_cy=40;
  {
    struct f1_t : public bbGCFrame{
      bbArray<bbString>* l_0{};
      void gcMark(){
        bbGCMarkPtr(l_0);
      }
    }f1{};
    f1.l_0=l_text.split(BB_T(","));
    bbInt l_1=bbInt(0);
    bbInt l_2=f1.l_0->length();
    for(;(l_1<l_2);l_1+=1){
      bbString l_line=f1.l_0->at(l_1);
      bbInt l_cx=50;
      {
        struct f3_t : public bbGCFrame{
          bbArray<bbString>* l_3{};
          void gcMark(){
            bbGCMarkPtr(l_3);
          }
        }f3{};
        f3.l_3=l_line.split(BB_T("="));
        bbInt l_4=bbInt(0);
        bbInt l_5=f3.l_3->length();
        for(;(l_4<l_5);l_4+=1){
          bbString l_tab=f3.l_3->at(l_4);
          l_display->m_DrawText(l_tab,bbFloat(l_cx),bbFloat(l_cy),0.0f,0.0f);
          l_cx+=100;
        }
      }
      l_cy+=20;
    }
  }
}

void t_default_VSynthWindow::m_OnMouseEvent(t_mojo_app_MouseEvent* l_event){
  this->m_mousex=l_event->m_Location().m_X();
  this->m_mousey=l_event->m_Location().m_Y();
  this->m_pitchbend+=bbDouble((bbFloat(l_event->m_Wheel().m_Y())/48.0f));
}

void t_default_VSynthWindow::m_OnKeyEvent(t_mojo_app_KeyEvent* l_event){
  bbInt l_0=l_event->m_Type();
  if(l_0==0){
    bbInt l_1=l_event->m_Key();
    if(l_1==47){
      this->m_div=g_default_Wrap((this->m_div+1),bbInt(0),g_default_DivisorNames->length());
    }else if(l_1==45){
      this->m_tempo-=1;
    }else if(l_1==48){
      this->m_tempo+=1;
    }else if(l_1==190){
      this->m_arp=bbInt(0);
    }else if(l_1==191){
      this->m_arp=1;
    }else if(l_1==192){
      this->m_arp=2;
    }else if(l_1==193){
      this->m_arp=3;
    }else if(l_1==194){
      this->m_arp=4;
    }else if(l_1==49){
      this->m_oscillator=bbInt(0);
    }else if(l_1==50){
      this->m_oscillator=1;
    }else if(l_1==51){
      this->m_oscillator=2;
    }else if(l_1==52){
      this->m_oscillator=3;
    }else if(l_1==53){
      this->m_oscillator=4;
    }else if(l_1==27){
      g_default_instance->m_Terminate();
    }else if(l_1==91){
      this->m_envelope=g_default_Wrap((this->m_envelope-1),bbInt(0),g_default_EnvelopeNames->length());
    }else if(l_1==93){
      this->m_envelope=g_default_Wrap((this->m_envelope+1),bbInt(0),g_default_EnvelopeNames->length());
    }else if(l_1==13){
      this->m_synth=g_default_Wrap((this->m_synth+1),bbInt(0),g_default_SynthNames->length());
      g_default_vsynth->m_SetSynth(this->m_synth);
    }else if(l_1==44){
      this->m_octave=g_monkey_math_Clamp_1i((this->m_octave-1),bbInt(0),g_default_MaxOctave);
    }else if(l_1==46){
      this->m_octave=g_monkey_math_Clamp_1i((this->m_octave+1),bbInt(0),g_default_MaxOctave);
    }else if(l_1==32){
      g_default_vsynth->m_ClearKeys();
    }else{
      this->m_KeyDown(l_event->m_Key());
    }
  }else if(l_0==2){
    bbInt l_2=l_event->m_Key();
    if(l_2==27){
    }else{
      this->m_KeyUp(l_event->m_Key());
    }
  }
}

void t_default_VSynthWindow::m_KeyUp(bbInt l_key){
  if(this->m_keyNoteMap->m_Contains(l_key)){
    {
      bbInt l_octave=bbInt(0);
      for(;(l_octave<g_default_MaxOctave);l_octave+=1){
        bbInt l_note=(this->m_keyNoteMap->m__idx(l_key)+(l_octave*12));
        if(this->m_noteMap->m_Contains(l_note)){
          g_default_vsynth->m_NoteOff(l_note);
          this->m_noteMap->m_Remove(l_note);
        }
      }
    }
  }
}

void t_default_VSynthWindow::m_KeyDown(bbInt l_key){
  if(this->m_keyNoteMap->m_Contains(l_key)){
    this->m_KeyUp(l_key);
    bbInt l_note=(this->m_keyNoteMap->m__idx(l_key)+(this->m_octave*12));
    this->m_noteMap->m__idxeq(l_note,true);
    g_default_vsynth->m_NoteOn(l_note,this->m_oscillator,this->m_envelope);
  }
}

void mx2_vsynth_vsynth_init(){
  static bool done;
  if(done) return;
  done=true;
  g_default_AppTitle=BB_T("VSynth 0.02");
  g_default_Contact=BB_T("Latest Source=github.com/nitrologic/m2");
  g_default_About=BB_T("VSynth Control");
  g_default_Octave1=BB_T("Sharps=    W   E       T   Y   U      ");
  g_default_Octave0=BB_T("Notes=A   S   D  F   G   H    J  K");
  g_default_Controls=BB_T("Reset Keys=Space,Quit=Escape");
  g_default_OscillatorNames=bbArray<bbString>::create({BB_T("Square"),BB_T("Sine"),BB_T("Sawtooth"),BB_T("Triangle"),BB_T("Noise")},5);
  g_default_EnvelopeNames=bbArray<bbString>::create({BB_T("None"),BB_T("Plain"),BB_T("Punchy"),BB_T("SlowOut"),BB_T("SlowIn")},5);
  g_default_ArpNames=bbArray<bbString>::create({BB_T("None"),BB_T("Natural"),BB_T("Ascending"),BB_T("Descending"),BB_T("UpDown"),BB_T("Random")},6);
  g_default_SynthNames=bbArray<bbString>::create({BB_T("Mono1"),BB_T("Poly32")},2);
  g_default_DivisorNames=bbArray<bbString>::create({BB_T("Whole"),BB_T("Half"),BB_T("Third"),BB_T("Quarter"),BB_T("Fifth"),BB_T("Sixth"),BB_T("Seventh"),BB_T("Eighth")},8);
  g_default_Duration=bbInt(0);
  g_default_FragmentSize=1024;
  g_default_WriteAhead=8192;
  g_default_AudioFrequency=44100;
  g_default_MaxPolyphony=32;
  g_default_MaxOctave=12;
  g_default_VSynthWindow_MusicKeys=bbArray<bbInt>::create({113,97,119,115,101,100,102,116,103,121,104,117,106,107,111,108,112,59},18);
}

bbInit mx2_vsynth_vsynth_init_v("vsynth_vsynth",&mx2_vsynth_vsynth_init);
