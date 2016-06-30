
#include "vsynth_vsynth.h"

// ***** External *****

#include "../../../../../../monkey2/modules/mojo/mojo.buildv011/desktop_release_macos/mojo_app_2app.h"
#include "../../../../../../monkey2/modules/mojo/mojo.buildv011/desktop_release_macos/mojo_app_2event.h"
#include "../../../../../../monkey2/modules/monkey/monkey.buildv011/desktop_release_macos/monkey_math.h"
#include "../../../../../../monkey2/modules/sdl2-mixer/sdl2-mixer.buildv011/desktop_release_macos/sdl2_5mixer_sdl2_5mixer.h"
#include "../../../../../../monkey2/modules/std/std.buildv011/desktop_release_macos/std_geom_2vec2.h"
#include "vsynth_std_collections_2list.h"
#include "vsynth_std_collections_2map.h"

extern bbDouble g_monkey_math_Abs_1d(bbDouble l_x);

// ***** Internal *****

bbGCRootVar<t_mojo_app_AppInstance> g_default_instance;
bbGCRootVar<t_default_VSynth> g_default_vsynth;
bbFloat g_default_Pos;
bbInt g_default_FragmentSize;
bbInt g_default_AudioFrequency;
bbGCRootVar<bbArray<bbInt>> g_default_VSynth_MusicKeys;

void g_default_VSynth_audio_0callback(void* l_a,bbUByte* l_b,bbInt l_byteCount){
  struct f0_t : public bbGCFrame{
    bbArray<bbFloat>* l_buffer{};
    void gcMark(){
      bbGCMarkPtr(l_buffer);
    }
  }f0{};
  bbInt l_samples=(l_byteCount/4);
  if((l_samples>g_default_FragmentSize)){
    puts(BB_T("Audio Overrun").c_str());fflush( stdout );
    l_samples=g_default_FragmentSize;
  }
  f0.l_buffer=g_default_vsynth->m_FillAudioBuffer(l_samples);
  {
    bbInt l_i=bbInt(0);
    for(;(l_i<l_samples);l_i+=1){
      bbInt l_s0=bbInt((f0.l_buffer->at(((l_i*2)+bbInt(0)))*2000.0f));
      l_s0=g_default_VSynth_Limit(l_s0,-32767,32767);
      l_b[((l_i*4)+bbInt(0))]=bbUByte((l_s0&255));
      l_b[((l_i*4)+1)]=bbUByte((l_s0>>8));
      bbInt l_s1=bbInt((f0.l_buffer->at(((l_i*2)+1))*2000.0f));
      l_s1=g_default_VSynth_Limit(l_s1,-32767,32767);
      l_b[((l_i*4)+2)]=bbUByte((l_s1&255));
      l_b[((l_i*4)+3)]=bbUByte((l_s1>>8));
    }
  }
}

bbInt g_default_VSynth_Limit(bbInt l_value,bbInt l_lo,bbInt l_hi){
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
  bbGCNew<t_default_VSynth>(BB_T("VSynth0.01"));
  g_mojo_app_App->m_Run();
}

void t_default_VSynth::init(){
  m_audioPipe=CreateAudioPipe();
  m_keyNoteMap=bbGCNew<t_std_collections_Map_1TbbInt_2i>();
  m_voices=bbGCNew<t_std_collections_List_1Tt_default_Voice_2>();
  m_tone=bbGCNew<t_default_Voice>();
}

void t_default_VSynth::gcMark(){
  t_mojo_app_Window::gcMark();
  bbGCMark(m_keyNoteMap);
  bbGCMark(m_audioSpec);
  bbGCMark(m_buffer);
  bbGCMark(m_voices);
  bbGCMark(m_tone);
}

t_default_VSynth::t_default_VSynth(bbString l_title):t_mojo_app_Window(l_title,720,560,8){
  init();
  g_default_vsynth=this;
  this->m_OpenAudio();
}

void t_default_VSynth::m_UpdateSequence(){
  this->m_frame+=1;
  bbInt l_t=(this->m_frame/20);
  if((l_t!=this->m_tick)){
    if(bbBool((l_t&1))){
      this->m_tone->m_NoteOn((((l_t&15)*3)+40));
    }else{
      this->m_tone->m_NoteOff();
    }
    this->m_tick=l_t;
  }
}

void t_default_VSynth::m_OpenAudio(){
  struct f0_t : public bbGCFrame{
    SDL_AudioSpec l_spec{};
    t_default_Oscillator* t0{};
    t_default_Envelope* t1{};
    void gcMark(){
      bbGCMark(l_spec);
      bbGCMarkPtr(t0);
      bbGCMarkPtr(t1);
    }
  }f0{};
  this->m_buffer=bbArray<bbFloat>::create((g_default_FragmentSize*2));
  f0.l_spec.freq=g_default_AudioFrequency;
  f0.l_spec.format=bbShort(AUDIO_S16);
  f0.l_spec.channels=2;
  f0.l_spec.samples=bbShort(g_default_FragmentSize);
  f0.l_spec.callback=g_default_VSynth_audio_0callback;
  Mix_CloseAudio();
  bbInt l_error=SDL_OpenAudio(&f0.l_spec,&this->m_audioSpec);
  if(bbBool(l_error)){
    puts((((BB_T("error=")+bbString(l_error))+BB_T(" "))+bbString::fromCString(((void*)(SDL_GetError())))).c_str());fflush( stdout );
  }else{
    puts((BB_T("Audio Open freq=")+bbString(this->m_audioSpec.freq)).c_str());fflush( stdout );
    g_default_AudioFrequency=this->m_audioSpec.freq;
  }
  {
    bbInt l_i=bbInt(0);
    for(;(l_i<g_default_VSynth_MusicKeys->length());l_i+=1){
      this->m_keyNoteMap->m_Set(g_default_VSynth_MusicKeys->at(l_i),(60+l_i));
    }
  }
  this->m_tone->m_SetOscillator(f0.t0=((t_default_Oscillator*)(bbGCNew<t_default_Square>())));
  this->m_tone->m_SetEnvelope(f0.t1=((t_default_Envelope*)(bbGCNew<t_default_ADSR>(0.059999999999999998,0.01,0.92000000000000004,0.5))));
  this->m_voices->m_AddLast(this->m_tone);
  SDL_PauseAudio(bbInt(0));
}

void t_default_VSynth::m_OnRender(t_mojo_graphics_Canvas* l_display){
  g_mojo_app_App->m_RequestRender();
}

void t_default_VSynth::m_OnMouseEvent(t_mojo_app_MouseEvent* l_event){
  this->m_mousex=l_event->m_Location().m_X();
  this->m_mousey=l_event->m_Location().m_Y();
}

void t_default_VSynth::m_OnKeyEvent(t_mojo_app_KeyEvent* l_event){
  bbInt l_0=l_event->m_Type();
  if(l_0==0){
    bbInt l_1=l_event->m_Key();
    if(l_1==27){
      g_default_instance->m_Terminate();
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

void t_default_VSynth::m_KeyUp(bbInt l_key){
  if((l_key!=this->m_monoKey)){
    return;
  }
  bbInt l_note=this->m_keyNoteMap->m__idx(l_key);
  this->m_tone->m_NoteOff();
}

void t_default_VSynth::m_KeyDown(bbInt l_key){
  bbInt l_note=this->m_keyNoteMap->m__idx(l_key);
  this->m_tone->m_NoteOn(l_note);
  this->m_monoKey=l_key;
}

bbArray<bbFloat>* t_default_VSynth::m_FillAudioBuffer(bbInt l_samples){
  {
    bbInt l_i=bbInt(0);
    for(;(l_i<l_samples);l_i+=1){
      this->m_buffer->at(((l_i*2)+bbInt(0)))=0.0f;
      this->m_buffer->at(((l_i*2)+1))=0.0f;
    }
  }
  {
    struct f1_t : public bbGCFrame{
      t_std_collections_List_1Tt_default_Voice_2_Iterator l_0{};
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
      f2.l_voice->m_Mix(this->m_buffer,l_samples);
    }
  }
  g_default_Pos+=bbFloat(l_samples);
  return this->m_buffer;
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
  bbDouble l_t=(l_hz/bbDouble(g_default_AudioFrequency));
  this->m_delta+=l_t;
  return ((g_monkey_math_Abs_1d(std::fmod(this->m_delta,4.0))-2.0)-1.0);
}

bbDouble t_default_Square::m_Sample(bbDouble l_hz){
  bbDouble l_t=(l_hz/bbDouble(g_default_AudioFrequency));
  this->m_delta+=l_t;
  return bbDouble((-1+(2*(bbInt(this->m_delta)&1))));
}

void t_default_Voice::gcMark(){
  bbGCMark(m_oscillator);
  bbGCMark(m_envelope);
}

void t_default_Voice::m_SetPan(bbDouble l_value){
  this->m_pan=l_value;
}

void t_default_Voice::m_SetOscillator(t_default_Oscillator* l_osc){
  this->m_oscillator=l_osc;
}

void t_default_Voice::m_SetEnvelope(t_default_Envelope* l_env){
  this->m_envelope=l_env;
}

void t_default_Voice::m_NoteOn(bbInt l_note){
  this->m_hz=(440.0*std::pow(2.0,bbDouble(((bbFloat(l_note)-67.0f)/12.0f))));
  this->m_noteOn=true;
}

void t_default_Voice::m_NoteOff(){
  this->m_noteOn=false;
}

void t_default_Voice::m_Mix(bbArray<bbFloat>* l_buffer,bbInt l_samples){
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
      bbDouble l_v=this->m_oscillator->m_Sample(this->m_hz);
      bbDouble l_e{};
      if(this->m_noteOn){
        l_e=this->m_envelope->m_On();
      }else{
        l_e=this->m_envelope->m_Off();
      }
      l_buffer->at(((l_i*2)+bbInt(0)))+=bbFloat(((l_e*bbDouble(l_left))*l_v));
      l_buffer->at(((l_i*2)+1))+=bbFloat(((l_e*bbDouble(l_right))*l_v));
    }
  }
}

void mx2_vsynth_vsynth_init(){
  static bool done;
  if(done) return;
  done=true;
  g_default_FragmentSize=32;
  g_default_AudioFrequency=44100;
  g_default_VSynth_MusicKeys=bbArray<bbInt>::create({97,119,115,101,100,102,116,103,121,104,117,106,107},13);
}

bbInit mx2_vsynth_vsynth_init_v("vsynth_vsynth",&mx2_vsynth_vsynth_init);
