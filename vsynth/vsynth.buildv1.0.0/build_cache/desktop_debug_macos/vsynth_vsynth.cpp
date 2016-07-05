
#include "vsynth_vsynth.h"

// ***** External *****

#include "../../../../../../monkey2/modules/mojo/mojo.buildv1.0.0/desktop_debug_macos/mojo_app_2app.h"
#include "../../../../../../monkey2/modules/mojo/mojo.buildv1.0.0/desktop_debug_macos/mojo_app_2event.h"
#include "../../../../../../monkey2/modules/mojo/mojo.buildv1.0.0/desktop_debug_macos/mojo_graphics_2canvas.h"
#include "../../../../../../monkey2/modules/mojo/mojo.buildv1.0.0/desktop_debug_macos/mojo_std_collections_2map.h"
#include "../../../../../../monkey2/modules/monkey/monkey.buildv1.0.0/desktop_debug_macos/monkey_math.h"
#include "../../../../../../monkey2/modules/portmidi/portmidi.buildv1.0.0/desktop_debug_macos/portmidi_portmidi.h"
#include "../../../../../../monkey2/modules/sdl2-mixer/sdl2-mixer.buildv1.0.0/desktop_debug_macos/sdl2_5mixer_sdl2_5mixer.h"
#include "../../../../../../monkey2/modules/std/std.buildv1.0.0/desktop_debug_macos/std_collections_2stack.h"
#include "../../../../../../monkey2/modules/std/std.buildv1.0.0/desktop_debug_macos/std_geom_2vec2.h"
#include "vsynth_audiopipe.h"
#include "vsynth_std_collections_2list.h"
#include "vsynth_std_collections_2map.h"
#include "vsynth_std_collections_2stack.h"

extern bbDouble g_monkey_math_Abs_1d(bbDouble l_x);
extern bbDouble g_std_random_Rnd();
extern bbInt g_monkey_math_Clamp_1i(bbInt l_value,bbInt l_min,bbInt l_max);

// ***** Internal *****

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
  bbDBFrame db_f{"Limit:Int(value:Int,lo:Int,hi:Int)","/Users/simon/nitrologic/m2/vsynth/vsynth.monkey2"};
  bbDBLocal("value",&l_value);
  bbDBLocal("lo",&l_lo);
  bbDBLocal("hi",&l_hi);
  bbDBStmt(2703362);
  if((l_value<l_lo)){
    bbDBBlock db_blk;
    bbDBStmt(2703374);
    return l_lo;
  }
  bbDBStmt(2707458);
  if((l_value>l_hi)){
    bbDBBlock db_blk;
    bbDBStmt(2707470);
    return l_hi;
  }
  bbDBStmt(2711554);
  return l_value;
}

void bbMain(){
  static bool done;
  if(done) return;
  done=true;
  void mx2_mojo_main();mx2_mojo_main();
  void mx2_std_main();mx2_std_main();
  bbDBFrame db_f{"Main:Void()","/Users/simon/nitrologic/m2/vsynth/vsynth.monkey2"};
  bbDBStmt(3080193);
  g_default_instance=bbGCNew<t_mojo_app_AppInstance>();
  bbDBStmt(3084289);
  bbGCNew<t_default_VSynthWindow>(g_default_AppTitle);
  bbDBStmt(3088385);
  g_mojo_app_App->m_Run();
}

bbInt g_default_Wrap(bbInt l_value,bbInt l_lower,bbInt l_upper){
  bbDBFrame db_f{"Wrap:Int(value:Int,lower:Int,upper:Int)","/Users/simon/nitrologic/m2/vsynth/vsynth.monkey2"};
  bbDBLocal("value",&l_value);
  bbDBLocal("lower",&l_lower);
  bbDBLocal("upper",&l_upper);
  bbDBStmt(3055617);
  if((l_value<l_lower)){
    bbDBBlock db_blk;
    bbDBStmt(3055632);
    l_value=(l_upper-1);
  }
  bbDBStmt(3059713);
  if((l_value>=l_upper)){
    bbDBBlock db_blk;
    bbDBStmt(3059729);
    l_value=l_lower;
  }
  bbDBStmt(3063809);
  return l_value;
}

bbString g_default_FloatString(bbFloat l_value,bbInt l_dp){
  bbDBFrame db_f{"FloatString:String(value:Float,dp:Int)","/Users/simon/nitrologic/m2/vsynth/vsynth.monkey2"};
  bbDBLocal("value",&l_value);
  bbDBLocal("dp",&l_dp);
  bbDBStmt(2998279);
  bbString l_sign{};
  bbDBLocal("sign",&l_sign);
  bbDBStmt(3002375);
  bbInt l_integral=bbInt((bbDouble(l_value)*std::pow(10.0,bbDouble(l_dp))));
  bbDBLocal("integral",&l_integral);
  bbDBStmt(3006465);
  if((l_integral<bbInt(0))){
    bbDBBlock db_blk;
    bbDBStmt(3010562);
    l_sign=BB_T("-");
    bbDBStmt(3014658);
    l_integral=-l_integral;
  }
  bbDBStmt(3022855);
  bbString l_a=bbString(l_integral);
  bbDBLocal("a",&l_a);
  bbDBStmt(3026951);
  bbInt l_l=((l_dp+1)-l_a.length());
  bbDBLocal("l",&l_l);
  bbDBStmt(3031041);
  if((l_l>bbInt(0))){
    bbDBBlock db_blk;
    bbDBStmt(3031048);
    l_a=(BB_T("0000000000000").slice(bbInt(0),l_l)+l_a);
  }
  bbDBStmt(3035143);
  bbInt l_r=l_a.length();
  bbDBLocal("r",&l_r);
  bbDBStmt(3039233);
  return (((l_sign+l_a.slice(bbInt(0),(l_r-l_dp)))+BB_T("."))+l_a.slice((l_r-l_dp),l_r));
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

void t_default_VSynth::dbEmit(){
  bbDBEmit("audioSpec",&m_audioSpec);
  bbDBEmit("audioPipe",&m_audioPipe);
  bbDBEmit("detune",&m_detune);
  bbDBEmit("poly",&m_poly);
  bbDBEmit("mono",&m_mono);
  bbDBEmit("root",&m_root);
  bbDBEmit("arp",&m_arp);
  bbDBEmit("buffer",&m_buffer);
}

t_default_VSynth::t_default_VSynth(){
  init();
  bbDBFrame db_f{"new:Void()","/Users/simon/nitrologic/m2/vsynth/vsynth.monkey2"};
  bbDBStmt(1802242);
  this->m_OpenAudio();
  bbDBStmt(1806338);
  this->m_arp->m_SetSynth(this->m_mono);
  bbDBStmt(1810434);
  this->m_root=((t_default_Synth*)(this->m_arp));
}

void t_default_VSynth::m_UpdateAudio(){
  bbDBFrame db_f{"UpdateAudio:Void()","/Users/simon/nitrologic/m2/vsynth/vsynth.monkey2"};
  t_default_VSynth*self=this;
  bbDBLocal("Self",&self);
  bbDBStmt(1953794);
  {
    bbDBLoop db_loop;
    while(true){
      bbDBBlock db_blk;
      bbDBStmt(1957897);
      bbInt l_buffered=(this->m_audioPipe->writePointer-this->m_audioPipe->readPointer);
      bbDBLocal("buffered",&l_buffered);
      bbDBStmt(1961987);
      if((l_buffered>=g_default_WriteAhead)){
        bbDBBlock db_blk;
        bbDBStmt(1962011);
        break;
      }
      bbDBStmt(1966083);
      {
        bbDBLoop db_loop;
        bbInt l_i=bbInt(0);
        bbDBLocal("i",&l_i);
        bbDBStmt(1966083);
        for(;(l_i<(g_default_FragmentSize*2));l_i+=1){
          bbDBBlock db_blk;
          bbDBStmt(1970180);
          this->m_buffer->at(l_i)=0.0;
        }
      }
      bbDBStmt(1982473);
      bbInt l_samples=g_default_FragmentSize;
      bbDBLocal("samples",&l_samples);
      bbDBStmt(1986563);
      g_default_vsynth->m_root->m_FillAudioBuffer(this->m_buffer,l_samples,this->m_detune);
      bbDBStmt(1990659);
      g_default_Duration+=l_samples;
      bbDBStmt(1998857);
      bbDouble* l_pointer=&this->m_buffer->at(bbInt(0));
      bbDBLocal("pointer",&l_pointer);
      bbDBStmt(2002947);
      this->m_audioPipe->WriteSamples(l_pointer,(g_default_FragmentSize*2));
    }
  }
}

void t_default_VSynth::m_SetTempo(bbInt l_tempo,bbInt l_divisor){
  bbDBFrame db_f{"SetTempo:Void(tempo:Tempo:Int,divisor:Int)","/Users/simon/nitrologic/m2/vsynth/vsynth.monkey2"};
  t_default_VSynth*self=this;
  bbDBLocal("Self",&self);
  bbDBLocal("tempo",&l_tempo);
  bbDBLocal("divisor",&l_divisor);
  bbDBStmt(1896450);
  this->m_arp->m_SetTempo(l_tempo,l_divisor);
}

void t_default_VSynth::m_SetSynth(bbInt l_synth){
  bbDBFrame db_f{"SetSynth:Void(synth:Int)","/Users/simon/nitrologic/m2/vsynth/vsynth.monkey2"};
  t_default_VSynth*self=this;
  bbDBLocal("Self",&self);
  bbDBLocal("synth",&l_synth);
  bbDBStmt(1859586);
  if(l_synth==bbInt(0)){
    bbDBBlock db_blk;
    bbDBStmt(1867780);
    this->m_arp->m_SetSynth(this->m_mono);
  }else if(l_synth==1){
    bbDBBlock db_blk;
    bbDBStmt(1875972);
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
  bbDBFrame db_f{"OpenAudio:Void()","/Users/simon/nitrologic/m2/vsynth/vsynth.monkey2"};
  t_default_VSynth*self=this;
  bbDBLocal("Self",&self);
  bbDBStmt(2023432);
  bbDBLocal("spec",&f0.l_spec);
  bbDBStmt(2027522);
  f0.l_spec.freq=g_default_AudioFrequency;
  bbDBStmt(2031618);
  f0.l_spec.format=bbShort(AUDIO_S16);
  bbDBStmt(2035714);
  f0.l_spec.channels=2;
  bbDBStmt(2039810);
  f0.l_spec.samples=bbShort(g_default_FragmentSize);
  bbDBStmt(2043906);
  f0.l_spec.callback=AudioPipe::Callback;
  bbDBStmt(2048002);
  f0.l_spec.userdata=this->m_audioPipe->Handle();
  bbDBStmt(2056194);
  Mix_CloseAudio();
  bbDBStmt(2060296);
  bbInt l_error=SDL_OpenAudio(&f0.l_spec,&this->m_audioSpec);
  bbDBLocal("error",&l_error);
  bbDBStmt(2064386);
  if(bbBool(l_error)){
    bbDBBlock db_blk;
    bbDBStmt(2068483);
    puts((((BB_T("error=")+bbString(l_error))+BB_T(" "))+bbString::fromCString(((void*)(SDL_GetError())))).c_str());fflush( stdout );
  }else{
    bbDBStmt(2072578);
    bbDBBlock db_blk;
    bbDBStmt(2076675);
    puts((BB_T("Audio Open freq=")+bbString(this->m_audioSpec.freq)).c_str());fflush( stdout );
    bbDBStmt(2080771);
    g_default_AudioFrequency=this->m_audioSpec.freq;
  }
  bbDBStmt(2093058);
  SDL_PauseAudio(bbInt(0));
}

void t_default_VSynth::m_NoteOn(bbInt l_note,bbInt l_oscillator,bbInt l_envelope){
  bbDBFrame db_f{"NoteOn:Void(note:Int,oscillator:Int,envelope:Int)","/Users/simon/nitrologic/m2/vsynth/vsynth.monkey2"};
  t_default_VSynth*self=this;
  bbDBLocal("Self",&self);
  bbDBLocal("note",&l_note);
  bbDBLocal("oscillator",&l_oscillator);
  bbDBLocal("envelope",&l_envelope);
  bbDBStmt(1826818);
  this->m_root->m_NoteOn(l_note,l_oscillator,l_envelope);
}

void t_default_VSynth::m_NoteOff(bbInt l_note){
  bbDBFrame db_f{"NoteOff:Void(note:Int)","/Users/simon/nitrologic/m2/vsynth/vsynth.monkey2"};
  t_default_VSynth*self=this;
  bbDBLocal("Self",&self);
  bbDBLocal("note",&l_note);
  bbDBStmt(1843202);
  this->m_root->m_NoteOff(l_note);
}

void t_default_VSynth::m_Detune(bbDouble l_bend){
  bbDBFrame db_f{"Detune:Void(bend:V:Double)","/Users/simon/nitrologic/m2/vsynth/vsynth.monkey2"};
  t_default_VSynth*self=this;
  bbDBLocal("Self",&self);
  bbDBLocal("bend",&l_bend);
  bbDBStmt(1912834);
  this->m_detune=l_bend;
}

void t_default_VSynth::m_ClearKeys(){
  bbDBFrame db_f{"ClearKeys:Void()","/Users/simon/nitrologic/m2/vsynth/vsynth.monkey2"};
  t_default_VSynth*self=this;
  bbDBLocal("Self",&self);
  bbDBStmt(1929218);
  this->m_root->m_Panic();
}
bbString bbDBType(t_default_VSynth**){
  return "default.VSynth";
}
bbString bbDBValue(t_default_VSynth**p){
  return bbDBObjectValue(*p);
}

void t_default_Envelope::dbEmit(){
  bbDBEmit("p",&m_p);
}

bbDouble t_default_Envelope::m_On(){
  bbDBFrame db_f{"On:V:Double()","/Users/simon/nitrologic/m2/vsynth/vsynth.monkey2"};
  t_default_Envelope*self=this;
  bbDBLocal("Self",&self);
  bbDBStmt(212994);
  return 1.0;
}

bbDouble t_default_Envelope::m_Off(){
  bbDBFrame db_f{"Off:V:Double()","/Users/simon/nitrologic/m2/vsynth/vsynth.monkey2"};
  t_default_Envelope*self=this;
  bbDBLocal("Self",&self);
  bbDBStmt(225282);
  return 0.0;
}
bbString bbDBType(t_default_Envelope**){
  return "default.Envelope";
}
bbString bbDBValue(t_default_Envelope**p){
  return bbDBObjectValue(*p);
}

void t_default_ADSR::dbEmit(){
  t_default_Envelope::dbEmit();
  bbDBEmit("attack",&m_attack);
  bbDBEmit("decay",&m_decay);
  bbDBEmit("sustain",&m_sustain);
  bbDBEmit("release",&m_release);
  bbDBEmit("t",&m_t);
  bbDBEmit("noteOn",&m_noteOn);
}

t_default_ADSR::t_default_ADSR(bbDouble l_a,bbDouble l_d,bbDouble l_s,bbDouble l_r){
  bbDBFrame db_f{"new:Void(a:T:Double,d:T:Double,s:V:Double,r:T:Double)","/Users/simon/nitrologic/m2/vsynth/vsynth.monkey2"};
  bbDBLocal("a",&l_a);
  bbDBLocal("d",&l_d);
  bbDBLocal("s",&l_s);
  bbDBLocal("r",&l_r);
  bbDBStmt(270338);
  this->m_attack=l_a;
  bbDBStmt(274434);
  this->m_decay=l_d;
  bbDBStmt(278530);
  this->m_sustain=l_s;
  bbDBStmt(282626);
  this->m_release=l_r;
}

bbDouble t_default_ADSR::m_On(){
  bbDBFrame db_f{"On:V:Double()","/Users/simon/nitrologic/m2/vsynth/vsynth.monkey2"};
  t_default_ADSR*self=this;
  bbDBLocal("Self",&self);
  bbDBStmt(311298);
  if(!this->m_noteOn){
    bbDBBlock db_blk;
    bbDBStmt(315395);
    this->m_t=0.0;
    bbDBStmt(319491);
    this->m_noteOn=true;
  }
  bbDBStmt(327682);
  this->m_t+=bbDouble((1.0f/bbFloat(g_default_AudioFrequency)));
  bbDBStmt(331778);
  if((this->m_t<this->m_attack)){
    bbDBBlock db_blk;
    bbDBStmt(331790);
    return (this->m_t/this->m_attack);
  }
  bbDBStmt(335874);
  if(((this->m_t-this->m_attack)<this->m_decay)){
    bbDBBlock db_blk;
    bbDBStmt(335892);
    return (1.0-(((1.0-this->m_sustain)*(this->m_t-this->m_attack))/this->m_decay));
  }
  bbDBStmt(339970);
  return this->m_sustain;
}

bbDouble t_default_ADSR::m_Off(){
  bbDBFrame db_f{"Off:V:Double()","/Users/simon/nitrologic/m2/vsynth/vsynth.monkey2"};
  t_default_ADSR*self=this;
  bbDBLocal("Self",&self);
  bbDBStmt(356354);
  this->m_noteOn=false;
  bbDBStmt(360450);
  this->m_t+=bbDouble((1.0f/bbFloat(g_default_AudioFrequency)));
  bbDBStmt(364546);
  if((this->m_t<this->m_release)){
    bbDBBlock db_blk;
    bbDBStmt(368643);
    return (1.0-(this->m_t/this->m_release));
  }
  bbDBStmt(376834);
  return 0.0;
}
bbString bbDBType(t_default_ADSR**){
  return "default.ADSR";
}
bbString bbDBValue(t_default_ADSR**p){
  return bbDBObjectValue(*p);
}

void t_default_Oscillator::dbEmit(){
  bbDBEmit("delta",&m_delta);
}

bbDouble t_default_Oscillator::m_Sample(bbDouble l_hz){
  bbDBFrame db_f{"Sample:V:Double(hz:F:Double)","/Users/simon/nitrologic/m2/vsynth/vsynth.monkey2"};
  t_default_Oscillator*self=this;
  bbDBLocal("Self",&self);
  bbDBLocal("hz",&l_hz);
  bbDBStmt(409602);
  return 0.0;
}
bbString bbDBType(t_default_Oscillator**){
  return "default.Oscillator";
}
bbString bbDBValue(t_default_Oscillator**p){
  return bbDBObjectValue(*p);
}

void t_default_Sine::dbEmit(){
  t_default_Oscillator::dbEmit();
}

bbDouble t_default_Sine::m_Sample(bbDouble l_hz){
  bbDBFrame db_f{"Sample:V:Double(hz:F:Double)","/Users/simon/nitrologic/m2/vsynth/vsynth.monkey2"};
  t_default_Sine*self=this;
  bbDBLocal("Self",&self);
  bbDBLocal("hz",&l_hz);
  bbDBStmt(434184);
  bbDouble l_t=(l_hz/bbDouble(g_default_AudioFrequency));
  bbDBLocal("t",&l_t);
  bbDBStmt(438274);
  this->m_delta+=l_t;
  bbDBStmt(442370);
  return std::sin((g_monkey_math_Pi*this->m_delta));
}
bbString bbDBType(t_default_Sine**){
  return "default.Sine";
}
bbString bbDBValue(t_default_Sine**p){
  return bbDBObjectValue(*p);
}

void t_default_Sawtooth::dbEmit(){
  t_default_Oscillator::dbEmit();
}

bbDouble t_default_Sawtooth::m_Sample(bbDouble l_hz){
  bbDBFrame db_f{"Sample:V:Double(hz:F:Double)","/Users/simon/nitrologic/m2/vsynth/vsynth.monkey2"};
  t_default_Sawtooth*self=this;
  bbDBLocal("Self",&self);
  bbDBLocal("hz",&l_hz);
  bbDBStmt(466952);
  bbDouble l_t=(l_hz/bbDouble(g_default_AudioFrequency));
  bbDBLocal("t",&l_t);
  bbDBStmt(471042);
  this->m_delta+=l_t;
  bbDBStmt(475138);
  return (std::fmod((this->m_delta+1.0),2.0)-1.0);
}
bbString bbDBType(t_default_Sawtooth**){
  return "default.Sawtooth";
}
bbString bbDBValue(t_default_Sawtooth**p){
  return bbDBObjectValue(*p);
}

void t_default_Triangle::dbEmit(){
  t_default_Oscillator::dbEmit();
}

bbDouble t_default_Triangle::m_Sample(bbDouble l_hz){
  bbDBFrame db_f{"Sample:V:Double(hz:F:Double)","/Users/simon/nitrologic/m2/vsynth/vsynth.monkey2"};
  t_default_Triangle*self=this;
  bbDBLocal("Self",&self);
  bbDBLocal("hz",&l_hz);
  bbDBStmt(499720);
  bbDouble l_t=((2.0*l_hz)/bbDouble(g_default_AudioFrequency));
  bbDBLocal("t",&l_t);
  bbDBStmt(503810);
  this->m_delta+=l_t;
  bbDBStmt(507906);
  return ((g_monkey_math_Abs_1d(std::fmod(this->m_delta,4.0))-2.0)-1.0);
}
bbString bbDBType(t_default_Triangle**){
  return "default.Triangle";
}
bbString bbDBValue(t_default_Triangle**p){
  return bbDBObjectValue(*p);
}

void t_default_Square::dbEmit(){
  t_default_Oscillator::dbEmit();
}

bbDouble t_default_Square::m_Sample(bbDouble l_hz){
  bbDBFrame db_f{"Sample:V:Double(hz:F:Double)","/Users/simon/nitrologic/m2/vsynth/vsynth.monkey2"};
  t_default_Square*self=this;
  bbDBLocal("Self",&self);
  bbDBLocal("hz",&l_hz);
  bbDBStmt(532488);
  bbDouble l_t=(l_hz/bbDouble(g_default_AudioFrequency));
  bbDBLocal("t",&l_t);
  bbDBStmt(536578);
  this->m_delta+=l_t;
  bbDBStmt(540674);
  return bbDouble((-1+(2*(bbInt(this->m_delta)&1))));
}
bbString bbDBType(t_default_Square**){
  return "default.Square";
}
bbString bbDBValue(t_default_Square**p){
  return bbDBObjectValue(*p);
}

void t_default_Noise::dbEmit(){
  t_default_Oscillator::dbEmit();
  bbDBEmit("a",&m_a);
}

bbDouble t_default_Noise::m_Sample(bbDouble l_hz){
  bbDBFrame db_f{"Sample:V:Double(hz:F:Double)","/Users/simon/nitrologic/m2/vsynth/vsynth.monkey2"};
  t_default_Noise*self=this;
  bbDBLocal("Self",&self);
  bbDBLocal("hz",&l_hz);
  bbDBStmt(569352);
  bbDouble l_t=(l_hz/bbDouble(g_default_AudioFrequency));
  bbDBLocal("t",&l_t);
  bbDBStmt(573448);
  bbDouble l_delta0=this->m_delta;
  bbDBLocal("delta0",&l_delta0);
  bbDBStmt(577538);
  this->m_delta+=l_t;
  bbDBStmt(581640);
  bbDouble l_f=std::fmod(this->m_delta,1.0);
  bbDBLocal("f",&l_f);
  bbDBStmt(585730);
  if((bbInt(l_delta0)!=bbInt(this->m_delta))){
    bbDBBlock db_blk;
    bbDBStmt(589827);
    this->m_a=g_std_random_Rnd();
  }
  bbDBStmt(598018);
  return (1.0-(2.0*this->m_a));
}
bbString bbDBType(t_default_Noise**){
  return "default.Noise";
}
bbString bbDBValue(t_default_Noise**p){
  return bbDBObjectValue(*p);
}

bbString bbDBType(t_default_NotePlayer**){
  return "default.NotePlayer";
}
bbString bbDBValue(t_default_NotePlayer**p){
  return bbDBInterfaceValue(*p);
}

void t_default_Voice::gcMark(){
  bbGCMark(m_oscillator);
  bbGCMark(m_envelope);
}

void t_default_Voice::dbEmit(){
  bbDBEmit("oscillator",&m_oscillator);
  bbDBEmit("envelope",&m_envelope);
  bbDBEmit("noteOn",&m_noteOn);
  bbDBEmit("hz",&m_hz);
  bbDBEmit("pan",&m_pan);
  bbDBEmit("gain",&m_gain);
}

void t_default_Voice::m_Stop(){
  bbDBFrame db_f{"Stop:Void()","/Users/simon/nitrologic/m2/vsynth/vsynth.monkey2"};
  t_default_Voice*self=this;
  bbDBLocal("Self",&self);
  bbDBStmt(831490);
  this->m_NoteOff();
  bbDBStmt(835586);
  this->m_envelope->m_Off();
}

void t_default_Voice::m_SetPan(bbDouble l_value){
  bbDBFrame db_f{"SetPan:Void(value:V:Double)","/Users/simon/nitrologic/m2/vsynth/vsynth.monkey2"};
  t_default_Voice*self=this;
  bbDBLocal("Self",&self);
  bbDBLocal("value",&l_value);
  bbDBStmt(798722);
  this->m_pan=l_value;
}

void t_default_Voice::m_SetOscillator(bbInt l_osc){
  bbDBFrame db_f{"SetOscillator:Void(osc:Int)","/Users/simon/nitrologic/m2/vsynth/vsynth.monkey2"};
  t_default_Voice*self=this;
  bbDBLocal("Self",&self);
  bbDBLocal("osc",&l_osc);
  bbDBStmt(696322);
  if(l_osc==bbInt(0)){
    bbDBBlock db_blk;
    bbDBStmt(700426);
    this->m_oscillator=((t_default_Oscillator*)(bbGCNew<t_default_Square>()));
  }else if(l_osc==1){
    bbDBBlock db_blk;
    bbDBStmt(704522);
    this->m_oscillator=((t_default_Oscillator*)(bbGCNew<t_default_Sine>()));
  }else if(l_osc==2){
    bbDBBlock db_blk;
    bbDBStmt(708618);
    this->m_oscillator=((t_default_Oscillator*)(bbGCNew<t_default_Sawtooth>()));
  }else if(l_osc==3){
    bbDBBlock db_blk;
    bbDBStmt(712714);
    this->m_oscillator=((t_default_Oscillator*)(bbGCNew<t_default_Triangle>()));
  }else if(l_osc==4){
    bbDBBlock db_blk;
    bbDBStmt(716810);
    this->m_oscillator=((t_default_Oscillator*)(bbGCNew<t_default_Noise>()));
  }
}

void t_default_Voice::m_SetGain(bbDouble l_value){
  bbDBFrame db_f{"SetGain:Void(value:V:Double)","/Users/simon/nitrologic/m2/vsynth/vsynth.monkey2"};
  t_default_Voice*self=this;
  bbDBLocal("Self",&self);
  bbDBLocal("value",&l_value);
  bbDBStmt(815106);
  this->m_gain=l_value;
}

void t_default_Voice::m_SetEnvelope(bbInt l_env){
  bbDBFrame db_f{"SetEnvelope:Void(env:Int)","/Users/simon/nitrologic/m2/vsynth/vsynth.monkey2"};
  t_default_Voice*self=this;
  bbDBLocal("Self",&self);
  bbDBLocal("env",&l_env);
  bbDBStmt(737282);
  if(l_env==bbInt(0)){
    bbDBBlock db_blk;
    bbDBStmt(745476);
    this->m_envelope=bbGCNew<t_default_Envelope>();
  }else if(l_env==1){
    bbDBBlock db_blk;
    bbDBStmt(753668);
    this->m_envelope=((t_default_Envelope*)(bbGCNew<t_default_ADSR>(0.050000000000000003,1.5,0.20000000000000001,0.29999999999999999)));
  }else if(l_env==2){
    bbDBBlock db_blk;
    bbDBStmt(761860);
    this->m_envelope=((t_default_Envelope*)(bbGCNew<t_default_ADSR>(0.059999999999999998,0.01,0.92000000000000004,0.20000000000000001)));
  }else if(l_env==3){
    bbDBBlock db_blk;
    bbDBStmt(770052);
    this->m_envelope=((t_default_Envelope*)(bbGCNew<t_default_ADSR>(0.059999999999999998,2.0,0.20000000000000001,1.2)));
  }else if(l_env==4){
    bbDBBlock db_blk;
    bbDBStmt(778244);
    this->m_envelope=((t_default_Envelope*)(bbGCNew<t_default_ADSR>(0.20000000000000001,0.20000000000000001,0.92000000000000004,0.40000000000000002)));
  }
}

void t_default_Voice::m_NoteOn(bbInt l_note){
  bbDBFrame db_f{"NoteOn:Void(note:Int)","/Users/simon/nitrologic/m2/vsynth/vsynth.monkey2"};
  t_default_Voice*self=this;
  bbDBLocal("Self",&self);
  bbDBLocal("note",&l_note);
  bbDBStmt(851970);
  this->m_hz=(440.0*std::pow(2.0,bbDouble(((bbFloat(l_note)-67.0f)/12.0f))));
  bbDBStmt(856066);
  this->m_noteOn=true;
}

void t_default_Voice::m_NoteOff(){
  bbDBFrame db_f{"NoteOff:Void()","/Users/simon/nitrologic/m2/vsynth/vsynth.monkey2"};
  t_default_Voice*self=this;
  bbDBLocal("Self",&self);
  bbDBStmt(872450);
  this->m_noteOn=false;
}

void t_default_Voice::m_Mix(bbArray<bbDouble>* l_buffer,bbInt l_samples,bbDouble l_detune){
  bbDBFrame db_f{"Mix:Void(buffer:Double[],samples:Int,detune:V:Double)","/Users/simon/nitrologic/m2/vsynth/vsynth.monkey2"};
  t_default_Voice*self=this;
  bbDBLocal("Self",&self);
  bbDBLocal("buffer",&l_buffer);
  bbDBLocal("samples",&l_samples);
  bbDBLocal("detune",&l_detune);
  bbDBStmt(888840);
  bbFloat l_left=1.0f;
  bbDBLocal("left",&l_left);
  bbDBStmt(892936);
  bbFloat l_right=1.0f;
  bbDBLocal("right",&l_right);
  bbDBStmt(897026);
  if((this->m_pan<0.0)){
    bbDBBlock db_blk;
    bbDBStmt(897035);
    l_right+=bbFloat(this->m_pan);
  }
  bbDBStmt(901122);
  if((this->m_pan>0.0)){
    bbDBBlock db_blk;
    bbDBStmt(901131);
    l_left-=bbFloat(this->m_pan);
  }
  bbDBStmt(905218);
  {
    bbDBLoop db_loop;
    bbInt l_i=bbInt(0);
    bbDBLocal("i",&l_i);
    bbDBStmt(905218);
    for(;(l_i<l_samples);l_i+=1){
      bbDBBlock db_blk;
      bbDBStmt(909321);
      bbDouble l_v=this->m_oscillator->m_Sample((this->m_hz*l_detune));
      bbDBLocal("v",&l_v);
      bbDBStmt(913417);
      bbDouble l_e{};
      bbDBLocal("e",&l_e);
      bbDBStmt(917507);
      if(this->m_noteOn){
        bbDBBlock db_blk;
        bbDBStmt(917517);
        l_e=this->m_envelope->m_On();
      }else{
        bbDBStmt(917533);
        bbDBBlock db_blk;
        bbDBStmt(917538);
        l_e=this->m_envelope->m_Off();
      }
      bbDBStmt(921603);
      l_e*=this->m_gain;
      bbDBStmt(925699);
      l_buffer->at(((l_i*2)+bbInt(0)))+=((l_e*bbDouble(l_left))*l_v);
      bbDBStmt(929795);
      l_buffer->at(((l_i*2)+1))+=((l_e*bbDouble(l_right))*l_v);
    }
  }
}
bbString bbDBType(t_default_Voice**){
  return "default.Voice";
}
bbString bbDBValue(t_default_Voice**p){
  return bbDBObjectValue(*p);
}

bbString bbDBType(t_default_Synth**){
  return "default.Synth";
}
bbString bbDBValue(t_default_Synth**p){
  return bbDBInterfaceValue(*p);
}

void t_default_BeatGenerator::gcMark(){
  bbGCMark(m_output);
}

void t_default_BeatGenerator::dbEmit(){
  bbDBEmit("bpm",&m_bpm);
  bbDBEmit("divisor",&m_divisor);
  bbDBEmit("output",&m_output);
  bbDBEmit("time",&m_time);
  bbDBEmit("clock",&m_clock);
  bbDBEmit("oscillator",&m_oscillator);
  bbDBEmit("envelope",&m_envelope);
  bbDBEmit("recent",&m_recent);
}

void t_default_BeatGenerator::m_Update(bbDouble l_duration){
  bbDBFrame db_f{"Update:Void(duration:T:Double)","/Users/simon/nitrologic/m2/vsynth/vsynth.monkey2"};
  t_default_BeatGenerator*self=this;
  bbDBLocal("Self",&self);
  bbDBLocal("duration",&l_duration);
  bbDBStmt(1134594);
  this->m_time+=l_duration;
  bbDBStmt(1138690);
  {
    bbDBLoop db_loop;
    while((this->m_clock<this->m_time)){
      bbDBBlock db_blk;
      bbDBStmt(1142787);
      this->m_Beat();
      bbDBStmt(1146883);
      this->m_clock+=bbDouble((60.0f/bbFloat((this->m_bpm*this->m_divisor))));
    }
  }
}

void t_default_BeatGenerator::m_SetTempo(bbInt l_tempo,bbInt l_div){
  bbDBFrame db_f{"SetTempo:Void(tempo:Tempo:Int,div:Int)","/Users/simon/nitrologic/m2/vsynth/vsynth.monkey2"};
  t_default_BeatGenerator*self=this;
  bbDBLocal("Self",&self);
  bbDBLocal("tempo",&l_tempo);
  bbDBLocal("div",&l_div);
  bbDBStmt(1032194);
  this->m_bpm=l_tempo;
  bbDBStmt(1036290);
  this->m_divisor=l_div;
}

void t_default_BeatGenerator::m_SetSynth(t_default_Synth* l_synth){
  bbDBFrame db_f{"SetSynth:Void(synth:default.Synth)","/Users/simon/nitrologic/m2/vsynth/vsynth.monkey2"};
  t_default_BeatGenerator*self=this;
  bbDBLocal("Self",&self);
  bbDBLocal("synth",&l_synth);
  bbDBStmt(1052674);
  this->m_output=l_synth;
}

void t_default_BeatGenerator::m_Panic(){
  bbDBFrame db_f{"Panic:Void()","/Users/simon/nitrologic/m2/vsynth/vsynth.monkey2"};
  t_default_BeatGenerator*self=this;
  bbDBLocal("Self",&self);
  bbDBStmt(1187842);
  this->m_output->m_Panic();
}

void t_default_BeatGenerator::m_NoteOn(bbInt l_note,bbInt l_osc,bbInt l_env){
  bbDBFrame db_f{"NoteOn:Void(note:Int,osc:Int,env:Int)","/Users/simon/nitrologic/m2/vsynth/vsynth.monkey2"};
  t_default_BeatGenerator*self=this;
  bbDBLocal("Self",&self);
  bbDBLocal("note",&l_note);
  bbDBLocal("osc",&l_osc);
  bbDBLocal("env",&l_env);
  bbDBStmt(1069058);
  this->m_recent=l_note;
  bbDBStmt(1073154);
  this->m_oscillator=l_osc;
  bbDBStmt(1077250);
  this->m_envelope=l_env;
}

void t_default_BeatGenerator::m_NoteOff(bbInt l_note){
  bbDBFrame db_f{"NoteOff:Void(note:Int)","/Users/simon/nitrologic/m2/vsynth/vsynth.monkey2"};
  t_default_BeatGenerator*self=this;
  bbDBLocal("Self",&self);
  bbDBLocal("note",&l_note);
  bbDBStmt(1093634);
  this->m_output->m_NoteOff(l_note);
}

void t_default_BeatGenerator::m_FillAudioBuffer(bbArray<bbDouble>* l_buffer,bbInt l_samples,bbDouble l_detune){
  bbDBFrame db_f{"FillAudioBuffer:Void(buffer:Double[],samples:Int,detune:V:Double)","/Users/simon/nitrologic/m2/vsynth/vsynth.monkey2"};
  t_default_BeatGenerator*self=this;
  bbDBLocal("Self",&self);
  bbDBLocal("buffer",&l_buffer);
  bbDBLocal("samples",&l_samples);
  bbDBLocal("detune",&l_detune);
  bbDBStmt(1167362);
  this->m_Update(bbDouble(((2.0f*bbFloat(l_samples))/bbFloat(g_default_AudioFrequency))));
  bbDBStmt(1171458);
  this->m_output->m_FillAudioBuffer(l_buffer,l_samples,l_detune);
}

void t_default_BeatGenerator::m_Beat(){
  bbDBFrame db_f{"Beat:Void()","/Users/simon/nitrologic/m2/vsynth/vsynth.monkey2"};
  t_default_BeatGenerator*self=this;
  bbDBLocal("Self",&self);
  bbDBStmt(1110018);
  if(bbBool(this->m_recent)){
    bbDBBlock db_blk;
    bbDBStmt(1114115);
    this->m_NoteOn(this->m_recent,this->m_oscillator,this->m_envelope);
  }
}
bbString bbDBType(t_default_BeatGenerator**){
  return "default.BeatGenerator";
}
bbString bbDBValue(t_default_BeatGenerator**p){
  return bbDBObjectValue(*p);
}

void t_default_Arpeggiator::init(){
  m_notes=bbGCNew<t_std_collections_Stack_1i>();
}

void t_default_Arpeggiator::gcMark(){
  t_default_BeatGenerator::gcMark();
  bbGCMark(m_notes);
}

void t_default_Arpeggiator::dbEmit(){
  t_default_BeatGenerator::dbEmit();
  bbDBEmit("notes",&m_notes);
  bbDBEmit("index",&m_index);
}

void t_default_Arpeggiator::m_NoteOn(bbInt l_note,bbInt l_osc,bbInt l_env){
  bbDBFrame db_f{"NoteOn:Void(note:Int,osc:Int,env:Int)","/Users/simon/nitrologic/m2/vsynth/vsynth.monkey2"};
  t_default_Arpeggiator*self=this;
  bbDBLocal("Self",&self);
  bbDBLocal("note",&l_note);
  bbDBLocal("osc",&l_osc);
  bbDBLocal("env",&l_env);
  bbDBStmt(1232898);
  t_default_BeatGenerator::m_NoteOn(l_note,l_osc,l_env);
  bbDBStmt(1236994);
  this->m_index=this->m_notes->m_Length();
  bbDBStmt(1241090);
  this->m_notes->m_Push(l_note);
}

void t_default_Arpeggiator::m_NoteOff(bbInt l_note){
  bbDBFrame db_f{"NoteOff:Void(note:Int)","/Users/simon/nitrologic/m2/vsynth/vsynth.monkey2"};
  t_default_Arpeggiator*self=this;
  bbDBLocal("Self",&self);
  bbDBLocal("note",&l_note);
  bbDBStmt(1257474);
  this->m_output->m_NoteOff(l_note);
  bbDBStmt(1261570);
  this->m_notes->m_Remove(l_note,bbInt(0));
}

void t_default_Arpeggiator::m_Beat(){
  bbDBFrame db_f{"Beat:Void()","/Users/simon/nitrologic/m2/vsynth/vsynth.monkey2"};
  t_default_Arpeggiator*self=this;
  bbDBLocal("Self",&self);
  bbDBStmt(1277954);
  if(bbBool(this->m_notes->m_Length())){
    bbDBBlock db_blk;
    bbDBStmt(1282051);
    this->m_index=(this->m_index%this->m_notes->m_Length());
    bbDBStmt(1286153);
    bbInt l_note=this->m_notes->m__idx(this->m_index);
    bbDBLocal("note",&l_note);
    bbDBStmt(1290243);
    this->m_output->m_NoteOn(l_note,this->m_oscillator,this->m_envelope);
  }
  bbDBStmt(1298434);
  this->m_index+=1;
}
bbString bbDBType(t_default_Arpeggiator**){
  return "default.Arpeggiator";
}
bbString bbDBValue(t_default_Arpeggiator**p){
  return bbDBObjectValue(*p);
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

void t_default_PolySynth::dbEmit(){
  bbDBEmit("polyList",&m_polyList);
  bbDBEmit("polyMap",&m_polyMap);
  bbDBEmit("voices",&m_voices);
}

t_default_PolySynth::t_default_PolySynth(){
  init();
  bbDBFrame db_f{"new:Void()","/Users/simon/nitrologic/m2/vsynth/vsynth.monkey2"};
  bbDBStmt(1343490);
  {
    bbDBLoop db_loop;
    bbInt l_i=bbInt(0);
    bbDBLocal("i",&l_i);
    bbDBStmt(1343490);
    for(;(l_i<g_default_MaxPolyphony);l_i+=1){
      struct f2_t : public bbGCFrame{
        t_default_Voice* l_tone{};
        void gcMark(){
          bbGCMarkPtr(l_tone);
        }
      }f2{};
      bbDBBlock db_blk;
      bbDBStmt(1347593);
      f2.l_tone=bbGCNew<t_default_Voice>();
      bbDBLocal("tone",&f2.l_tone);
      bbDBStmt(1351683);
      f2.l_tone->m_SetOscillator(bbInt(0));
      bbDBStmt(1355779);
      f2.l_tone->m_SetEnvelope(bbInt(0));
      bbDBStmt(1359875);
      this->m_polyList->m_AddLast(f2.l_tone);
    }
  }
}

void t_default_PolySynth::m_SetTempo(bbInt l_tempo,bbInt l_divisor){
  bbDBFrame db_f{"SetTempo:Void(tempo:Tempo:Int,divisor:Int)","/Users/simon/nitrologic/m2/vsynth/vsynth.monkey2"};
  t_default_PolySynth*self=this;
  bbDBLocal("Self",&self);
  bbDBLocal("tempo",&l_tempo);
  bbDBLocal("divisor",&l_divisor);
}

void t_default_PolySynth::m_Panic(){
  bbDBFrame db_f{"Panic:Void()","/Users/simon/nitrologic/m2/vsynth/vsynth.monkey2"};
  t_default_PolySynth*self=this;
  bbDBLocal("Self",&self);
  bbDBStmt(1392642);
  this->m_voices->m_Clear();
}

void t_default_PolySynth::m_NoteOn(bbInt l_note,bbInt l_oscillator,bbInt l_envelope){
  struct f0_t : public bbGCFrame{
    t_default_Voice* l_voice{};
    void gcMark(){
      bbGCMarkPtr(l_voice);
    }
  }f0{};
  bbDBFrame db_f{"NoteOn:Void(note:Int,oscillator:Int,envelope:Int)","/Users/simon/nitrologic/m2/vsynth/vsynth.monkey2"};
  t_default_PolySynth*self=this;
  bbDBLocal("Self",&self);
  bbDBLocal("note",&l_note);
  bbDBLocal("oscillator",&l_oscillator);
  bbDBLocal("envelope",&l_envelope);
  bbDBStmt(1409026);
  this->m_NoteOff(l_note);
  bbDBStmt(1413122);
  if(this->m_polyList->m_Empty()){
    bbDBBlock db_blk;
    bbDBStmt(1413140);
    return;
  }
  bbDBStmt(1417224);
  f0.l_voice=this->m_polyList->m_RemoveFirst();
  bbDBLocal("voice",&f0.l_voice);
  bbDBStmt(1421314);
  f0.l_voice->m_SetEnvelope(l_envelope);
  bbDBStmt(1425410);
  f0.l_voice->m_SetOscillator(l_oscillator);
  bbDBStmt(1429506);
  f0.l_voice->m_NoteOn(l_note);
  bbDBStmt(1433602);
  this->m_polyMap->m__idxeq(l_note,f0.l_voice);
  bbDBStmt(1437698);
  this->m_polyList->m_Remove(f0.l_voice);
  bbDBStmt(1441794);
  if(!this->m_voices->m_Contains(f0.l_voice)){
    bbDBBlock db_blk;
    bbDBStmt(1445891);
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
  bbDBFrame db_f{"NoteOff:Void(note:Int)","/Users/simon/nitrologic/m2/vsynth/vsynth.monkey2"};
  t_default_PolySynth*self=this;
  bbDBLocal("Self",&self);
  bbDBLocal("note",&l_note);
  bbDBStmt(1466376);
  f0.l_voice=this->m_polyMap->m__idx(l_note);
  bbDBLocal("voice",&f0.l_voice);
  bbDBStmt(1470466);
  if(bbBool(f0.l_voice)){
    bbDBBlock db_blk;
    bbDBStmt(1474563);
    f0.l_voice->m_Stop();
    bbDBStmt(1478659);
    this->m_polyMap->m_Remove(l_note);
    bbDBStmt(1482755);
    this->m_polyList->m_AddLast(f0.l_voice);
  }
}

void t_default_PolySynth::m_FillAudioBuffer(bbArray<bbDouble>* l_buffer,bbInt l_samples,bbDouble l_detune){
  bbDBFrame db_f{"FillAudioBuffer:Void(buffer:Double[],samples:Int,detune:V:Double)","/Users/simon/nitrologic/m2/vsynth/vsynth.monkey2"};
  t_default_PolySynth*self=this;
  bbDBLocal("Self",&self);
  bbDBLocal("buffer",&l_buffer);
  bbDBLocal("samples",&l_samples);
  bbDBLocal("detune",&l_detune);
  bbDBStmt(1503234);
  {
    struct f1_t : public bbGCFrame{
      t_std_collections_Stack_1Tt_default_Voice_2_Iterator l_0{};
      void gcMark(){
        bbGCMark(l_0);
      }
    }f1{};
    bbDBLoop db_loop;
    f1.l_0=this->m_voices->m_All();
    bbDBLocal("0",&f1.l_0);
    for(;!f1.l_0.m_AtEnd();f1.l_0.m_Bump()){
      struct f2_t : public bbGCFrame{
        t_default_Voice* l_voice{};
        void gcMark(){
          bbGCMarkPtr(l_voice);
        }
      }f2{};
      bbDBBlock db_blk;
      f2.l_voice=f1.l_0.m_Current();
      bbDBLocal("voice",&f2.l_voice);
      bbDBStmt(1507331);
      f2.l_voice->m_Mix(l_buffer,l_samples,l_detune);
    }
  }
}
bbString bbDBType(t_default_PolySynth**){
  return "default.PolySynth";
}
bbString bbDBValue(t_default_PolySynth**p){
  return bbDBObjectValue(*p);
}

void t_default_MonoSynth::init(){
  m_notes=bbGCNew<t_std_collections_Stack_1i>();
}

void t_default_MonoSynth::gcMark(){
  bbGCMark(m_tone);
  bbGCMark(m_notes);
}

void t_default_MonoSynth::dbEmit(){
  bbDBEmit("tone",&m_tone);
  bbDBEmit("monoNote",&m_monoNote);
  bbDBEmit("notes",&m_notes);
  bbDBEmit("oscillator",&m_oscillator);
}

t_default_MonoSynth::t_default_MonoSynth(){
  init();
  bbDBFrame db_f{"new:Void()","/Users/simon/nitrologic/m2/vsynth/vsynth.monkey2"};
  bbDBStmt(1560578);
  this->m_tone=bbGCNew<t_default_Voice>();
  bbDBStmt(1564674);
  this->m_tone->m_SetOscillator(bbInt(0));
  bbDBStmt(1568770);
  this->m_tone->m_SetEnvelope(bbInt(0));
}

void t_default_MonoSynth::m_SetTempo(bbInt l_tempo,bbInt l_divisor){
  bbDBFrame db_f{"SetTempo:Void(tempo:Tempo:Int,divisor:Int)","/Users/simon/nitrologic/m2/vsynth/vsynth.monkey2"};
  t_default_MonoSynth*self=this;
  bbDBLocal("Self",&self);
  bbDBLocal("tempo",&l_tempo);
  bbDBLocal("divisor",&l_divisor);
}

void t_default_MonoSynth::m_Panic(){
  bbDBFrame db_f{"Panic:Void()","/Users/simon/nitrologic/m2/vsynth/vsynth.monkey2"};
  t_default_MonoSynth*self=this;
  bbDBLocal("Self",&self);
  bbDBStmt(1597442);
  this->m_tone->m_NoteOff();
}

void t_default_MonoSynth::m_NoteOn(bbInt l_note,bbInt l_osc,bbInt l_envelope){
  bbDBFrame db_f{"NoteOn:Void(note:Int,osc:Int,envelope:Int)","/Users/simon/nitrologic/m2/vsynth/vsynth.monkey2"};
  t_default_MonoSynth*self=this;
  bbDBLocal("Self",&self);
  bbDBLocal("note",&l_note);
  bbDBLocal("osc",&l_osc);
  bbDBLocal("envelope",&l_envelope);
  bbDBStmt(1613826);
  this->m_monoNote=l_note;
  bbDBStmt(1617922);
  if(!this->m_notes->m_Contains(l_note)){
    bbDBBlock db_blk;
    bbDBStmt(1622019);
    this->m_notes->m_Push(l_note);
  }
  bbDBStmt(1630210);
  if((l_osc!=this->m_oscillator)){
    bbDBBlock db_blk;
    bbDBStmt(1634307);
    this->m_oscillator=l_osc;
    bbDBStmt(1638403);
    this->m_tone->m_SetOscillator(this->m_oscillator);
  }
  bbDBStmt(1646594);
  this->m_tone->m_SetEnvelope(l_envelope);
  bbDBStmt(1650690);
  this->m_tone->m_NoteOn(l_note);
}

void t_default_MonoSynth::m_NoteOff(bbInt l_note){
  bbDBFrame db_f{"NoteOff:Void(note:Int)","/Users/simon/nitrologic/m2/vsynth/vsynth.monkey2"};
  t_default_MonoSynth*self=this;
  bbDBLocal("Self",&self);
  bbDBLocal("note",&l_note);
  bbDBStmt(1667074);
  this->m_notes->m_Remove(l_note,bbInt(0));
  bbDBStmt(1671170);
  if(this->m_notes->m_Empty()){
    bbDBBlock db_blk;
    bbDBStmt(1675267);
    this->m_tone->m_NoteOff();
  }else{
    bbDBStmt(1679362);
    bbDBBlock db_blk;
    bbDBStmt(1683459);
    l_note=this->m_notes->m_Pop();
    bbDBStmt(1687555);
    this->m_monoNote=l_note;
    bbDBStmt(1691651);
    this->m_notes->m_Push(l_note);
    bbDBStmt(1695747);
    this->m_tone->m_NoteOn(l_note);
  }
}

void t_default_MonoSynth::m_FillAudioBuffer(bbArray<bbDouble>* l_buffer,bbInt l_samples,bbDouble l_detune){
  bbDBFrame db_f{"FillAudioBuffer:Void(buffer:Double[],samples:Int,detune:V:Double)","/Users/simon/nitrologic/m2/vsynth/vsynth.monkey2"};
  t_default_MonoSynth*self=this;
  bbDBLocal("Self",&self);
  bbDBLocal("buffer",&l_buffer);
  bbDBLocal("samples",&l_samples);
  bbDBLocal("detune",&l_detune);
  bbDBStmt(1716226);
  this->m_tone->m_Mix(l_buffer,l_samples,l_detune);
}
bbString bbDBType(t_default_MonoSynth**){
  return "default.MonoSynth";
}
bbString bbDBValue(t_default_MonoSynth**p){
  return bbDBObjectValue(*p);
}

void t_default_VSynthWindow::init(){
  m_keyNoteMap=bbGCNew<t_std_collections_Map_1TbbInt_2i>();
  m_noteMap=bbGCNew<t_std_collections_Map_1iz>();
}

void t_default_VSynthWindow::gcMark(){
  t_mojo_app_Window::gcMark();
  bbGCMark(m_keyNoteMap);
  bbGCMark(m_portMidi);
  bbGCMark(m_noteMap);
}

void t_default_VSynthWindow::dbEmit(){
  t_mojo_app_Window::dbEmit();
  bbDBEmit("frame",&m_frame);
  bbDBEmit("tick",&m_tick);
  bbDBEmit("mousex",&m_mousex);
  bbDBEmit("mousey",&m_mousey);
  bbDBEmit("synth",&m_synth);
  bbDBEmit("oscillator",&m_oscillator);
  bbDBEmit("envelope",&m_envelope);
  bbDBEmit("octave",&m_octave);
  bbDBEmit("mousebend",&m_mousebend);
  bbDBEmit("pitchbend",&m_pitchbend);
  bbDBEmit("arp",&m_arp);
  bbDBEmit("div",&m_div);
  bbDBEmit("tempo",&m_tempo);
  bbDBEmit("keyNoteMap",&m_keyNoteMap);
  bbDBEmit("portMidi",&m_portMidi);
  bbDBEmit("noteMap",&m_noteMap);
}

t_default_VSynthWindow::t_default_VSynthWindow(bbString l_title):t_mojo_app_Window(l_title,720,560,8){
  init();
  bbDBFrame db_f{"new:Void(title:String)","/Users/simon/nitrologic/m2/vsynth/vsynth.monkey2"};
  bbDBLocal("title",&l_title);
  bbDBStmt(2215938);
  this->m_InitMidi();
  bbDBStmt(2220034);
  {
    bbDBLoop db_loop;
    bbInt l_i=bbInt(0);
    bbDBLocal("i",&l_i);
    bbDBStmt(2220034);
    for(;(l_i<g_default_VSynthWindow_MusicKeys->length());l_i+=1){
      bbDBBlock db_blk;
      bbDBStmt(2224131);
      this->m_keyNoteMap->m_Set(g_default_VSynthWindow_MusicKeys->at(l_i),(l_i-1));
    }
  }
  bbDBStmt(2232322);
  g_default_vsynth=bbGCNew<t_default_VSynth>();
}

void t_default_VSynthWindow::m_UpdateSequence(){
  bbDBFrame db_f{"UpdateSequence:Void()","/Users/simon/nitrologic/m2/vsynth/vsynth.monkey2"};
  t_default_VSynthWindow*self=this;
  bbDBLocal("Self",&self);
  bbDBStmt(2641922);
  this->m_frame+=1;
  bbDBStmt(2646024);
  bbInt l_t=(this->m_frame/20);
  bbDBLocal("t",&l_t);
  bbDBStmt(2650114);
  if((l_t!=this->m_tick)){
    bbDBBlock db_blk;
    bbDBStmt(2654217);
    bbInt l_note=((((l_t>>1)&15)*3)+40);
    bbDBLocal("note",&l_note);
    bbDBStmt(2658307);
    if(bbBool((l_t&1))){
      bbDBBlock db_blk;
      bbDBStmt(2662404);
      g_default_vsynth->m_NoteOn(l_note,this->m_oscillator,this->m_envelope);
    }else{
      bbDBStmt(2666499);
      bbDBBlock db_blk;
      bbDBStmt(2670596);
      g_default_vsynth->m_NoteOff(l_note);
    }
    bbDBStmt(2678787);
    this->m_tick=l_t;
  }
}

void t_default_VSynthWindow::m_PollMidi(){
  bbDBFrame db_f{"PollMidi:Void()","/Users/simon/nitrologic/m2/vsynth/vsynth.monkey2"};
  t_default_VSynthWindow*self=this;
  bbDBLocal("Self",&self);
  bbDBStmt(2306056);
  static bbInt g_NoteOn=144;
  bbDBStmt(2310152);
  static bbInt g_NoteOff=128;
  bbDBStmt(2314248);
  static bbInt g_PitchWheel=224;
  bbDBStmt(2322434);
  {
    bbDBLoop db_loop;
    while(bbBool(this->m_portMidi->m_HasEvent())){
      struct f1_t : public bbGCFrame{
        bbArray<bbUByte>* l_b{};
        void gcMark(){
          bbGCMarkPtr(l_b);
        }
      }f1{};
      bbDBBlock db_blk;
      bbDBStmt(2326537);
      f1.l_b=this->m_portMidi->m_EventDataBytes();
      bbDBLocal("b",&f1.l_b);
      bbDBStmt(2330633);
      bbUByte l_note=f1.l_b->at(1);
      bbDBLocal("note",&l_note);
      bbDBStmt(2334729);
      bbUByte l_velocity=f1.l_b->at(2);
      bbDBLocal("velocity",&l_velocity);
      bbDBStmt(2338825);
      bbInt l_word=bbInt((bbUInt(l_note)+(bbUInt(l_velocity)<<7)));
      bbDBLocal("word",&l_word);
      bbDBStmt(2342915);
      if(f1.l_b->at(bbInt(0))==bbUByte(g_NoteOn)){
        bbDBBlock db_blk;
        bbDBStmt(2351109);
        g_default_vsynth->m_NoteOn(bbInt(l_note),this->m_oscillator,this->m_envelope);
      }else if(f1.l_b->at(bbInt(0))==bbUByte(g_NoteOff)){
        bbDBBlock db_blk;
        bbDBStmt(2359301);
        g_default_vsynth->m_NoteOff(bbInt(l_note));
      }else if(f1.l_b->at(bbInt(0))==bbUByte(g_PitchWheel)){
        bbDBBlock db_blk;
        bbDBStmt(2367493);
        this->m_pitchbend=bbDouble((1.0f+(bbFloat((l_word-8192))/8192.0f)));
      }else{
        bbDBBlock db_blk;
        bbDBStmt(2375685);
        puts(((((((bbString(f1.l_b->at(bbInt(0)))+BB_T(" "))+bbString(f1.l_b->at(1)))+BB_T(" "))+bbString(f1.l_b->at(2)))+BB_T(" "))+bbString(f1.l_b->at(3))).c_str());fflush( stdout );
      }
    }
  }
}

void t_default_VSynthWindow::m_OnRender(t_mojo_graphics_Canvas* l_display){
  bbDBFrame db_f{"OnRender:Void(display:mojo.graphics.Canvas)","/Users/simon/nitrologic/m2/vsynth/vsynth.monkey2"};
  t_default_VSynthWindow*self=this;
  bbDBLocal("Self",&self);
  bbDBLocal("display",&l_display);
  bbDBStmt(2412546);
  this->m_PollMidi();
  bbDBStmt(2420738);
  g_mojo_app_App->m_RequestRender();
  bbDBStmt(2428930);
  g_default_vsynth->m_Detune(this->m_pitchbend);
  bbDBStmt(2433026);
  g_default_vsynth->m_SetTempo(this->m_tempo,(1+this->m_div));
  bbDBStmt(2437122);
  g_default_vsynth->m_UpdateAudio();
  bbDBStmt(2445320);
  bbString l_text=(((((g_default_About+BB_T(",,"))+g_default_Octave1)+BB_T(","))+g_default_Octave0)+BB_T(","));
  bbDBLocal("text",&l_text);
  bbDBStmt(2449410);
  l_text+=(BB_T("Octave=< >=")+bbString(this->m_octave));
  bbDBStmt(2453506);
  l_text+=(BB_T(",Oscillator=1-5=")+g_default_OscillatorNames->at(this->m_oscillator));
  bbDBStmt(2457602);
  l_text+=(BB_T(",Envelope=[]=")+g_default_EnvelopeNames->at(this->m_envelope));
  bbDBStmt(2461698);
  l_text+=(BB_T(",PitchBend=Mouse Wheel=")+g_default_FloatString(bbFloat(this->m_pitchbend),2));
  bbDBStmt(2465794);
  l_text+=(BB_T(",,Arpeggiator=F5-F8=")+g_default_ArpNames->at(this->m_arp));
  bbDBStmt(2469890);
  l_text+=(BB_T(",Note Divisor=/=")+g_default_DivisorNames->at(this->m_div));
  bbDBStmt(2473986);
  l_text+=(BB_T(",,Synth=Enter Key=")+g_default_SynthNames->at(this->m_synth));
  bbDBStmt(2478082);
  l_text+=(BB_T(",,Tempo=- +=")+bbString(this->m_tempo));
  bbDBStmt(2482178);
  l_text+=(((BB_T(",,")+g_default_Controls)+BB_T(",,"))+g_default_Contact);
  bbDBStmt(2494472);
  bbInt l_cy=40;
  bbDBLocal("cy",&l_cy);
  bbDBStmt(2498562);
  {
    struct f1_t : public bbGCFrame{
      bbArray<bbString>* l_0{};
      void gcMark(){
        bbGCMarkPtr(l_0);
      }
    }f1{};
    bbDBLoop db_loop;
    f1.l_0=l_text.split(BB_T(","));
    bbDBLocal("0",&f1.l_0);
    bbInt l_1=bbInt(0);
    bbDBLocal("1",&l_1);
    bbInt l_2=f1.l_0->length();
    bbDBLocal("2",&l_2);
    for(;(l_1<l_2);l_1+=1){
      bbDBBlock db_blk;
      bbString l_line=f1.l_0->at(l_1);
      bbDBLocal("line",&l_line);
      bbDBStmt(2502665);
      bbInt l_cx=50;
      bbDBLocal("cx",&l_cx);
      bbDBStmt(2506755);
      {
        struct f3_t : public bbGCFrame{
          bbArray<bbString>* l_3{};
          void gcMark(){
            bbGCMarkPtr(l_3);
          }
        }f3{};
        bbDBLoop db_loop;
        f3.l_3=l_line.split(BB_T("="));
        bbDBLocal("3",&f3.l_3);
        bbInt l_4=bbInt(0);
        bbDBLocal("4",&l_4);
        bbInt l_5=f3.l_3->length();
        bbDBLocal("5",&l_5);
        for(;(l_4<l_5);l_4+=1){
          bbDBBlock db_blk;
          bbString l_tab=f3.l_3->at(l_4);
          bbDBLocal("tab",&l_tab);
          bbDBStmt(2510852);
          l_display->m_DrawText(l_tab,bbFloat(l_cx),bbFloat(l_cy),0.0f,0.0f);
          bbDBStmt(2514948);
          l_cx+=100;
        }
      }
      bbDBStmt(2523139);
      l_cy+=20;
    }
  }
}

void t_default_VSynthWindow::m_OnMouseEvent(t_mojo_app_MouseEvent* l_event){
  bbDBFrame db_f{"OnMouseEvent:Void(event:mojo.app.MouseEvent)","/Users/simon/nitrologic/m2/vsynth/vsynth.monkey2"};
  t_default_VSynthWindow*self=this;
  bbDBLocal("Self",&self);
  bbDBLocal("event",&l_event);
  bbDBStmt(2961410);
  this->m_mousex=l_event->m_Location().m_X();
  bbDBStmt(2965506);
  this->m_mousey=l_event->m_Location().m_Y();
  bbDBStmt(2969602);
  this->m_mousebend+=bbDouble((bbFloat(l_event->m_Wheel().m_Y())/48.0f));
  bbDBStmt(2973698);
  this->m_pitchbend=std::pow(2.0,this->m_mousebend);
}

void t_default_VSynthWindow::m_OnKeyEvent(t_mojo_app_KeyEvent* l_event){
  bbDBFrame db_f{"OnKeyEvent:Void(event:mojo.app.KeyEvent)","/Users/simon/nitrologic/m2/vsynth/vsynth.monkey2"};
  t_default_VSynthWindow*self=this;
  bbDBLocal("Self",&self);
  bbDBLocal("event",&l_event);
  bbInt l_0=l_event->m_Type();
  bbDBLocal("0",&l_0);
  bbDBStmt(2727938);
  if(l_0==0){
    bbDBBlock db_blk;
    bbInt l_1=l_event->m_Key();
    bbDBLocal("1",&l_1);
    bbDBStmt(2736131);
    if(l_1==47){
      bbDBBlock db_blk;
      bbDBStmt(2744324);
      this->m_div=g_default_Wrap((this->m_div+1),bbInt(0),g_default_DivisorNames->length());
    }else if(l_1==45){
      bbDBBlock db_blk;
      bbDBStmt(2752516);
      this->m_tempo-=1;
    }else if(l_1==48){
      bbDBBlock db_blk;
      bbDBStmt(2760708);
      this->m_tempo+=1;
    }else if(l_1==190){
      bbDBBlock db_blk;
      bbDBStmt(2768900);
      this->m_arp=bbInt(0);
    }else if(l_1==191){
      bbDBBlock db_blk;
      bbDBStmt(2777092);
      this->m_arp=1;
    }else if(l_1==192){
      bbDBBlock db_blk;
      bbDBStmt(2785284);
      this->m_arp=2;
    }else if(l_1==193){
      bbDBBlock db_blk;
      bbDBStmt(2793476);
      this->m_arp=3;
    }else if(l_1==194){
      bbDBBlock db_blk;
      bbDBStmt(2801668);
      this->m_arp=4;
    }else if(l_1==49){
      bbDBBlock db_blk;
      bbDBStmt(2809860);
      this->m_oscillator=bbInt(0);
    }else if(l_1==50){
      bbDBBlock db_blk;
      bbDBStmt(2818052);
      this->m_oscillator=1;
    }else if(l_1==51){
      bbDBBlock db_blk;
      bbDBStmt(2826244);
      this->m_oscillator=2;
    }else if(l_1==52){
      bbDBBlock db_blk;
      bbDBStmt(2834436);
      this->m_oscillator=3;
    }else if(l_1==53){
      bbDBBlock db_blk;
      bbDBStmt(2842628);
      this->m_oscillator=4;
    }else if(l_1==27){
      bbDBBlock db_blk;
      bbDBStmt(2850820);
      g_default_instance->m_Terminate();
    }else if(l_1==91){
      bbDBBlock db_blk;
      bbDBStmt(2859012);
      this->m_envelope=g_default_Wrap((this->m_envelope-1),bbInt(0),g_default_EnvelopeNames->length());
    }else if(l_1==93){
      bbDBBlock db_blk;
      bbDBStmt(2867204);
      this->m_envelope=g_default_Wrap((this->m_envelope+1),bbInt(0),g_default_EnvelopeNames->length());
    }else if(l_1==13){
      bbDBBlock db_blk;
      bbDBStmt(2875396);
      this->m_synth=g_default_Wrap((this->m_synth+1),bbInt(0),g_default_SynthNames->length());
      bbDBStmt(2879492);
      g_default_vsynth->m_SetSynth(this->m_synth);
    }else if(l_1==44){
      bbDBBlock db_blk;
      bbDBStmt(2887684);
      this->m_octave=g_monkey_math_Clamp_1i((this->m_octave-1),bbInt(0),g_default_MaxOctave);
    }else if(l_1==46){
      bbDBBlock db_blk;
      bbDBStmt(2895876);
      this->m_octave=g_monkey_math_Clamp_1i((this->m_octave+1),bbInt(0),g_default_MaxOctave);
    }else if(l_1==32){
      bbDBBlock db_blk;
      bbDBStmt(2904068);
      g_default_vsynth->m_ClearKeys();
    }else{
      bbDBBlock db_blk;
      bbDBStmt(2912260);
      this->m_KeyDown(l_event->m_Key());
    }
  }else if(l_0==2){
    bbDBBlock db_blk;
    bbInt l_2=l_event->m_Key();
    bbDBLocal("2",&l_2);
    bbDBStmt(2924547);
    if(l_2==27){
      bbDBBlock db_blk;
    }else{
      bbDBBlock db_blk;
      bbDBStmt(2936836);
      this->m_KeyUp(l_event->m_Key());
    }
  }
}

void t_default_VSynthWindow::m_KeyUp(bbInt l_key){
  bbDBFrame db_f{"KeyUp:Void(key:mojo.input.Key)","/Users/simon/nitrologic/m2/vsynth/vsynth.monkey2"};
  t_default_VSynthWindow*self=this;
  bbDBLocal("Self",&self);
  bbDBLocal("key",&l_key);
  bbDBStmt(2592770);
  if(this->m_keyNoteMap->m_Contains(l_key)){
    bbDBBlock db_blk;
    bbDBStmt(2596867);
    {
      bbDBLoop db_loop;
      bbInt l_octave=bbInt(0);
      bbDBLocal("octave",&l_octave);
      bbDBStmt(2596867);
      for(;(l_octave<g_default_MaxOctave);l_octave+=1){
        bbDBBlock db_blk;
        bbDBStmt(2600970);
        bbInt l_note=(this->m_keyNoteMap->m__idx(l_key)+(l_octave*12));
        bbDBLocal("note",&l_note);
        bbDBStmt(2605060);
        if(this->m_noteMap->m_Contains(l_note)){
          bbDBBlock db_blk;
          bbDBStmt(2609157);
          g_default_vsynth->m_NoteOff(l_note);
          bbDBStmt(2613253);
          this->m_noteMap->m_Remove(l_note);
        }
      }
    }
  }
}

void t_default_VSynthWindow::m_KeyDown(bbInt l_key){
  bbDBFrame db_f{"KeyDown:Void(key:mojo.input.Key)","/Users/simon/nitrologic/m2/vsynth/vsynth.monkey2"};
  t_default_VSynthWindow*self=this;
  bbDBLocal("Self",&self);
  bbDBLocal("key",&l_key);
  bbDBStmt(2555906);
  if(this->m_keyNoteMap->m_Contains(l_key)){
    bbDBBlock db_blk;
    bbDBStmt(2560003);
    this->m_KeyUp(l_key);
    bbDBStmt(2564105);
    bbInt l_note=(this->m_keyNoteMap->m__idx(l_key)+(this->m_octave*12));
    bbDBLocal("note",&l_note);
    bbDBStmt(2568195);
    this->m_noteMap->m__idxeq(l_note,true);
    bbDBStmt(2572291);
    g_default_vsynth->m_NoteOn(l_note,this->m_oscillator,this->m_envelope);
  }
}

void t_default_VSynthWindow::m_InitMidi(){
  bbDBFrame db_f{"InitMidi:Void()","/Users/simon/nitrologic/m2/vsynth/vsynth.monkey2"};
  t_default_VSynthWindow*self=this;
  bbDBLocal("Self",&self);
  bbDBStmt(2256898);
  puts(BB_T("PortMidi test 0.1").c_str());fflush( stdout );
  bbDBStmt(2260994);
  puts(BB_T("Scanning Midi Bus, please wait.").c_str());fflush( stdout );
  bbDBStmt(2265090);
  this->m_portMidi=bbGCNew<t_portmidi_PortMidi>();
  bbDBStmt(2269192);
  bbInt l_inputs=this->m_portMidi->m_inputDevices->m_Length();
  bbDBLocal("inputs",&l_inputs);
  bbDBStmt(2273282);
  puts((BB_T("inputs=")+bbString(l_inputs)).c_str());fflush( stdout );
  bbDBStmt(2277378);
  {
    bbDBLoop db_loop;
    bbInt l_i=bbInt(0);
    bbDBLocal("i",&l_i);
    bbDBStmt(2277378);
    for(;(l_i<l_inputs);l_i+=1){
      bbDBBlock db_blk;
      bbDBStmt(2281475);
      this->m_portMidi->m_OpenInput(l_i);
    }
  }
}
bbString bbDBType(t_default_VSynthWindow**){
  return "default.VSynthWindow";
}
bbString bbDBValue(t_default_VSynthWindow**p){
  return bbDBObjectValue(*p);
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
