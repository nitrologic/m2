
#include "vsynth_vsynth.h"

// ***** External *****

#include "../../../../../../monkey2/modules/mojo/mojo.buildv011/desktop_debug_macos/mojo_app_2app.h"
#include "../../../../../../monkey2/modules/mojo/mojo.buildv011/desktop_debug_macos/mojo_app_2event.h"
#include "../../../../../../monkey2/modules/mojo/mojo.buildv011/desktop_debug_macos/mojo_graphics_2canvas.h"
#include "../../../../../../monkey2/modules/monkey/monkey.buildv011/desktop_debug_macos/monkey_math.h"
#include "../../../../../../monkey2/modules/sdl2-mixer/sdl2-mixer.buildv011/desktop_debug_macos/sdl2_5mixer_sdl2_5mixer.h"
#include "../../../../../../monkey2/modules/std/std.buildv011/desktop_debug_macos/std_geom_2vec2.h"
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
bbGCRootVar<t_mojo_app_AppInstance> g_default_instance;
bbGCRootVar<t_default_VSynth> g_default_vsynth;
bbInt g_default_Duration;
bbInt g_default_FragmentSize;
bbInt g_default_WriteAhead;
bbInt g_default_AudioFrequency;
bbInt g_default_MaxPolyphony;
bbGCRootVar<bbArray<bbInt>> g_default_VSynthWindow_MusicKeys;

bbInt g_default_VSynthWindow_Limit(bbInt l_value,bbInt l_lo,bbInt l_hi){
  bbDBFrame db_f{"Limit:Int(value:Int,lo:Int,hi:Int)","/Users/simon/nitrologic/m2/vsynth/vsynth.monkey2"};
  bbDBLocal("value",&l_value);
  bbDBLocal("lo",&l_lo);
  bbDBLocal("hi",&l_hi);
  bbDBStmt(1916930);
  if((l_value<l_lo)){
    bbDBBlock db_blk;
    bbDBStmt(1916942);
    return l_lo;
  }
  bbDBStmt(1921026);
  if((l_value>l_hi)){
    bbDBBlock db_blk;
    bbDBStmt(1921038);
    return l_hi;
  }
  bbDBStmt(1925122);
  return l_value;
}

void bbMain(){
  static bool done;
  if(done) return;
  done=true;
  void mx2_mojo_main();mx2_mojo_main();
  void mx2_std_main();mx2_std_main();
  bbDBFrame db_f{"Main:Void()","/Users/simon/nitrologic/m2/vsynth/vsynth.monkey2"};
  bbDBStmt(2269185);
  g_default_instance=bbGCNew<t_mojo_app_AppInstance>();
  bbDBStmt(2273281);
  bbGCNew<t_default_VSynthWindow>(g_default_AppTitle);
  bbDBStmt(2277377);
  g_mojo_app_App->m_Run();
}

bbInt g_default_Wrap(bbInt l_value,bbInt l_lower,bbInt l_upper){
  bbDBFrame db_f{"Wrap:Int(value:Int,lower:Int,upper:Int)","/Users/simon/nitrologic/m2/vsynth/vsynth.monkey2"};
  bbDBLocal("value",&l_value);
  bbDBLocal("lower",&l_lower);
  bbDBLocal("upper",&l_upper);
  bbDBStmt(2244609);
  if((l_value<l_lower)){
    bbDBBlock db_blk;
    bbDBStmt(2244624);
    l_value=(l_upper-1);
  }
  bbDBStmt(2248705);
  if((l_value>=l_upper)){
    bbDBBlock db_blk;
    bbDBStmt(2248721);
    l_value=l_lower;
  }
  bbDBStmt(2252801);
  return l_value;
}

bbString g_default_FloatString(bbFloat l_value,bbInt l_dp){
  bbDBFrame db_f{"FloatString:String(value:Float,dp:Int)","/Users/simon/nitrologic/m2/vsynth/vsynth.monkey2"};
  bbDBLocal("value",&l_value);
  bbDBLocal("dp",&l_dp);
  bbDBStmt(2187271);
  bbString l_sign{};
  bbDBLocal("sign",&l_sign);
  bbDBStmt(2191367);
  bbInt l_integral=bbInt((bbDouble(l_value)*std::pow(10.0,bbDouble(l_dp))));
  bbDBLocal("integral",&l_integral);
  bbDBStmt(2195457);
  if((l_integral<bbInt(0))){
    bbDBBlock db_blk;
    bbDBStmt(2199554);
    l_sign=BB_T("-");
    bbDBStmt(2203650);
    l_integral=-l_integral;
  }
  bbDBStmt(2211847);
  bbString l_a=bbString(l_integral);
  bbDBLocal("a",&l_a);
  bbDBStmt(2215943);
  bbInt l_l=((l_dp+1)-l_a.length());
  bbDBLocal("l",&l_l);
  bbDBStmt(2220033);
  if((l_l>bbInt(0))){
    bbDBBlock db_blk;
    bbDBStmt(2220040);
    l_a=(BB_T("000000").slice(bbInt(0),l_l)+l_a);
  }
  bbDBStmt(2224135);
  bbInt l_r=l_a.length();
  bbDBLocal("r",&l_r);
  bbDBStmt(2228225);
  return (((l_sign+l_a.slice(bbInt(0),(l_r-l_dp)))+BB_T("."))+l_a.slice((l_r-l_dp)));
}

void t_default_VSynth::init(){
  m_audioPipe=AudioPipe::Create();
  m_root=bbGCNew<t_default_MonoSynth>();
  m_buffer=bbArray<bbDouble>::create((g_default_FragmentSize*2));
}

void t_default_VSynth::gcMark(){
  bbGCMark(m_audioSpec);
  bbGCMark(m_root);
  bbGCMark(m_buffer);
}

void t_default_VSynth::dbEmit(){
  bbDBEmit("audioSpec",&m_audioSpec);
  bbDBEmit("audioPipe",&m_audioPipe);
  bbDBEmit("detune",&m_detune);
  bbDBEmit("root",&m_root);
  bbDBEmit("buffer",&m_buffer);
}

t_default_VSynth::t_default_VSynth(){
  init();
  bbDBFrame db_f{"new:Void()","/Users/simon/nitrologic/m2/vsynth/vsynth.monkey2"};
  bbDBStmt(1359874);
  this->m_OpenAudio();
}

void t_default_VSynth::m_UpdateAudio(){
  bbDBFrame db_f{"UpdateAudio:Void()","/Users/simon/nitrologic/m2/vsynth/vsynth.monkey2"};
  t_default_VSynth*self=this;
  bbDBLocal("Self",&self);
  bbDBStmt(1417218);
  {
    bbDBLoop db_loop;
    while(true){
      bbDBBlock db_blk;
      bbDBStmt(1421321);
      bbInt l_buffered=(this->m_audioPipe->writePointer-this->m_audioPipe->readPointer);
      bbDBLocal("buffered",&l_buffered);
      bbDBStmt(1425411);
      if((l_buffered>=g_default_WriteAhead)){
        bbDBBlock db_blk;
        bbDBStmt(1425435);
        break;
      }
      bbDBStmt(1429507);
      {
        bbDBLoop db_loop;
        bbInt l_i=bbInt(0);
        bbDBLocal("i",&l_i);
        bbDBStmt(1429507);
        for(;(l_i<(g_default_FragmentSize*2));l_i+=1){
          bbDBBlock db_blk;
          bbDBStmt(1433604);
          this->m_buffer->at(l_i)=0.0;
        }
      }
      bbDBStmt(1445897);
      bbInt l_samples=g_default_FragmentSize;
      bbDBLocal("samples",&l_samples);
      bbDBStmt(1449987);
      g_default_vsynth->m_root->m_FillAudioBuffer(this->m_buffer,l_samples,this->m_detune);
      bbDBStmt(1454083);
      g_default_Duration+=l_samples;
      bbDBStmt(1462281);
      bbDouble* l_pointer=&this->m_buffer->at(bbInt(0));
      bbDBLocal("pointer",&l_pointer);
      bbDBStmt(1466371);
      this->m_audioPipe->WriteSamples(l_pointer,(g_default_FragmentSize*2));
    }
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
  bbDBStmt(1486856);
  bbDBLocal("spec",&f0.l_spec);
  bbDBStmt(1490946);
  f0.l_spec.freq=g_default_AudioFrequency;
  bbDBStmt(1495042);
  f0.l_spec.format=bbShort(AUDIO_S16);
  bbDBStmt(1499138);
  f0.l_spec.channels=2;
  bbDBStmt(1503234);
  f0.l_spec.samples=bbShort(g_default_FragmentSize);
  bbDBStmt(1507330);
  f0.l_spec.callback=AudioPipe::Callback;
  bbDBStmt(1511426);
  f0.l_spec.userdata=this->m_audioPipe->Handle();
  bbDBStmt(1519618);
  Mix_CloseAudio();
  bbDBStmt(1523720);
  bbInt l_error=SDL_OpenAudio(&f0.l_spec,&this->m_audioSpec);
  bbDBLocal("error",&l_error);
  bbDBStmt(1527810);
  if(bbBool(l_error)){
    bbDBBlock db_blk;
    bbDBStmt(1531907);
    puts((((BB_T("error=")+bbString(l_error))+BB_T(" "))+bbString::fromCString(((void*)(SDL_GetError())))).c_str());fflush( stdout );
  }else{
    bbDBStmt(1536002);
    bbDBBlock db_blk;
    bbDBStmt(1540099);
    puts((BB_T("Audio Open freq=")+bbString(this->m_audioSpec.freq)).c_str());fflush( stdout );
    bbDBStmt(1544195);
    g_default_AudioFrequency=this->m_audioSpec.freq;
  }
  bbDBStmt(1556482);
  SDL_PauseAudio(bbInt(0));
}

void t_default_VSynth::m_NoteOn(bbInt l_note,bbInt l_oscillator,bbInt l_envelope){
  bbDBFrame db_f{"NoteOn:Void(note:Int,oscillator:Int,envelope:Int)","/Users/simon/nitrologic/m2/vsynth/vsynth.monkey2"};
  t_default_VSynth*self=this;
  bbDBLocal("Self",&self);
  bbDBLocal("note",&l_note);
  bbDBLocal("oscillator",&l_oscillator);
  bbDBLocal("envelope",&l_envelope);
  bbDBStmt(1327106);
  this->m_root->m_NoteOn(l_note,l_oscillator,l_envelope);
}

void t_default_VSynth::m_NoteOff(bbInt l_note){
  bbDBFrame db_f{"NoteOff:Void(note:Int)","/Users/simon/nitrologic/m2/vsynth/vsynth.monkey2"};
  t_default_VSynth*self=this;
  bbDBLocal("Self",&self);
  bbDBLocal("note",&l_note);
  bbDBStmt(1343490);
  this->m_root->m_NoteOff(l_note);
}

void t_default_VSynth::m_Detune(bbDouble l_bend){
  bbDBFrame db_f{"Detune:Void(bend:V:Double)","/Users/simon/nitrologic/m2/vsynth/vsynth.monkey2"};
  t_default_VSynth*self=this;
  bbDBLocal("Self",&self);
  bbDBLocal("bend",&l_bend);
  bbDBStmt(1376258);
  this->m_detune=l_bend;
}

void t_default_VSynth::m_ClearKeys(){
  bbDBFrame db_f{"ClearKeys:Void()","/Users/simon/nitrologic/m2/vsynth/vsynth.monkey2"};
  t_default_VSynth*self=this;
  bbDBLocal("Self",&self);
  bbDBStmt(1392642);
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
  bbDBStmt(184322);
  return 1.0;
}

bbDouble t_default_Envelope::m_Off(){
  bbDBFrame db_f{"Off:V:Double()","/Users/simon/nitrologic/m2/vsynth/vsynth.monkey2"};
  t_default_Envelope*self=this;
  bbDBLocal("Self",&self);
  bbDBStmt(196610);
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
  bbDBStmt(241666);
  this->m_attack=l_a;
  bbDBStmt(245762);
  this->m_decay=l_d;
  bbDBStmt(249858);
  this->m_sustain=l_s;
  bbDBStmt(253954);
  this->m_release=l_r;
}

bbDouble t_default_ADSR::m_On(){
  bbDBFrame db_f{"On:V:Double()","/Users/simon/nitrologic/m2/vsynth/vsynth.monkey2"};
  t_default_ADSR*self=this;
  bbDBLocal("Self",&self);
  bbDBStmt(282626);
  if(!this->m_noteOn){
    bbDBBlock db_blk;
    bbDBStmt(286723);
    this->m_t=0.0;
    bbDBStmt(290819);
    this->m_noteOn=true;
  }
  bbDBStmt(299010);
  this->m_t+=bbDouble((1.0f/bbFloat(g_default_AudioFrequency)));
  bbDBStmt(303106);
  if((this->m_t<this->m_attack)){
    bbDBBlock db_blk;
    bbDBStmt(303118);
    return (this->m_t/this->m_attack);
  }
  bbDBStmt(307202);
  if(((this->m_t-this->m_attack)<this->m_decay)){
    bbDBBlock db_blk;
    bbDBStmt(307220);
    return (1.0-(((1.0-this->m_sustain)*(this->m_t-this->m_attack))/this->m_decay));
  }
  bbDBStmt(311298);
  return this->m_sustain;
}

bbDouble t_default_ADSR::m_Off(){
  bbDBFrame db_f{"Off:V:Double()","/Users/simon/nitrologic/m2/vsynth/vsynth.monkey2"};
  t_default_ADSR*self=this;
  bbDBLocal("Self",&self);
  bbDBStmt(327682);
  this->m_noteOn=false;
  bbDBStmt(331778);
  this->m_t+=bbDouble((1.0f/bbFloat(g_default_AudioFrequency)));
  bbDBStmt(335874);
  if((this->m_t<this->m_release)){
    bbDBBlock db_blk;
    bbDBStmt(339971);
    return (1.0-(this->m_t/this->m_release));
  }
  bbDBStmt(348162);
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
  bbDBStmt(380930);
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
  bbDBStmt(405512);
  bbDouble l_t=(l_hz/bbDouble(g_default_AudioFrequency));
  bbDBLocal("t",&l_t);
  bbDBStmt(409602);
  this->m_delta+=l_t;
  bbDBStmt(413698);
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
  bbDBStmt(438280);
  bbDouble l_t=(l_hz/bbDouble(g_default_AudioFrequency));
  bbDBLocal("t",&l_t);
  bbDBStmt(442370);
  this->m_delta+=l_t;
  bbDBStmt(446466);
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
  bbDBStmt(471048);
  bbDouble l_t=((2.0*l_hz)/bbDouble(g_default_AudioFrequency));
  bbDBLocal("t",&l_t);
  bbDBStmt(475138);
  this->m_delta+=l_t;
  bbDBStmt(479234);
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
  bbDBStmt(503816);
  bbDouble l_t=(l_hz/bbDouble(g_default_AudioFrequency));
  bbDBLocal("t",&l_t);
  bbDBStmt(507906);
  this->m_delta+=l_t;
  bbDBStmt(512002);
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
  bbDBStmt(540680);
  bbDouble l_t=(l_hz/bbDouble(g_default_AudioFrequency));
  bbDBLocal("t",&l_t);
  bbDBStmt(544776);
  bbDouble l_delta0=this->m_delta;
  bbDBLocal("delta0",&l_delta0);
  bbDBStmt(548866);
  this->m_delta+=l_t;
  bbDBStmt(552968);
  bbDouble l_f=std::fmod(this->m_delta,1.0);
  bbDBLocal("f",&l_f);
  bbDBStmt(557058);
  if((bbInt(l_delta0)!=bbInt(this->m_delta))){
    bbDBBlock db_blk;
    bbDBStmt(561155);
    this->m_a=g_std_random_Rnd();
  }
  bbDBStmt(569346);
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
  bbDBStmt(802818);
  this->m_NoteOff();
  bbDBStmt(806914);
  this->m_envelope->m_Off();
}

void t_default_Voice::m_SetPan(bbDouble l_value){
  bbDBFrame db_f{"SetPan:Void(value:V:Double)","/Users/simon/nitrologic/m2/vsynth/vsynth.monkey2"};
  t_default_Voice*self=this;
  bbDBLocal("Self",&self);
  bbDBLocal("value",&l_value);
  bbDBStmt(770050);
  this->m_pan=l_value;
}

void t_default_Voice::m_SetOscillator(bbInt l_osc){
  bbDBFrame db_f{"SetOscillator:Void(osc:Int)","/Users/simon/nitrologic/m2/vsynth/vsynth.monkey2"};
  t_default_Voice*self=this;
  bbDBLocal("Self",&self);
  bbDBLocal("osc",&l_osc);
  bbDBStmt(667650);
  if(l_osc==bbInt(0)){
    bbDBBlock db_blk;
    bbDBStmt(671754);
    this->m_oscillator=((t_default_Oscillator*)(bbGCNew<t_default_Square>()));
  }else if(l_osc==1){
    bbDBBlock db_blk;
    bbDBStmt(675850);
    this->m_oscillator=((t_default_Oscillator*)(bbGCNew<t_default_Sine>()));
  }else if(l_osc==2){
    bbDBBlock db_blk;
    bbDBStmt(679946);
    this->m_oscillator=((t_default_Oscillator*)(bbGCNew<t_default_Sawtooth>()));
  }else if(l_osc==3){
    bbDBBlock db_blk;
    bbDBStmt(684042);
    this->m_oscillator=((t_default_Oscillator*)(bbGCNew<t_default_Triangle>()));
  }else if(l_osc==4){
    bbDBBlock db_blk;
    bbDBStmt(688138);
    this->m_oscillator=((t_default_Oscillator*)(bbGCNew<t_default_Noise>()));
  }
}

void t_default_Voice::m_SetGain(bbDouble l_value){
  bbDBFrame db_f{"SetGain:Void(value:V:Double)","/Users/simon/nitrologic/m2/vsynth/vsynth.monkey2"};
  t_default_Voice*self=this;
  bbDBLocal("Self",&self);
  bbDBLocal("value",&l_value);
  bbDBStmt(786434);
  this->m_gain=l_value;
}

void t_default_Voice::m_SetEnvelope(bbInt l_env){
  bbDBFrame db_f{"SetEnvelope:Void(env:Int)","/Users/simon/nitrologic/m2/vsynth/vsynth.monkey2"};
  t_default_Voice*self=this;
  bbDBLocal("Self",&self);
  bbDBLocal("env",&l_env);
  bbDBStmt(708610);
  if(l_env==bbInt(0)){
    bbDBBlock db_blk;
    bbDBStmt(716804);
    this->m_envelope=bbGCNew<t_default_Envelope>();
  }else if(l_env==1){
    bbDBBlock db_blk;
    bbDBStmt(724996);
    this->m_envelope=((t_default_Envelope*)(bbGCNew<t_default_ADSR>(0.050000000000000003,1.5,0.20000000000000001,0.29999999999999999)));
  }else if(l_env==2){
    bbDBBlock db_blk;
    bbDBStmt(733188);
    this->m_envelope=((t_default_Envelope*)(bbGCNew<t_default_ADSR>(0.059999999999999998,0.01,0.92000000000000004,0.20000000000000001)));
  }else if(l_env==3){
    bbDBBlock db_blk;
    bbDBStmt(741380);
    this->m_envelope=((t_default_Envelope*)(bbGCNew<t_default_ADSR>(0.059999999999999998,2.0,0.20000000000000001,1.2)));
  }else if(l_env==4){
    bbDBBlock db_blk;
    bbDBStmt(749572);
    this->m_envelope=((t_default_Envelope*)(bbGCNew<t_default_ADSR>(0.20000000000000001,0.20000000000000001,0.92000000000000004,0.40000000000000002)));
  }
}

void t_default_Voice::m_NoteOn(bbInt l_note){
  bbDBFrame db_f{"NoteOn:Void(note:Int)","/Users/simon/nitrologic/m2/vsynth/vsynth.monkey2"};
  t_default_Voice*self=this;
  bbDBLocal("Self",&self);
  bbDBLocal("note",&l_note);
  bbDBStmt(823298);
  this->m_hz=(440.0*std::pow(2.0,bbDouble(((bbFloat(l_note)-67.0f)/12.0f))));
  bbDBStmt(827394);
  this->m_noteOn=true;
}

void t_default_Voice::m_NoteOff(){
  bbDBFrame db_f{"NoteOff:Void()","/Users/simon/nitrologic/m2/vsynth/vsynth.monkey2"};
  t_default_Voice*self=this;
  bbDBLocal("Self",&self);
  bbDBStmt(843778);
  this->m_noteOn=false;
}

void t_default_Voice::m_Mix(bbArray<bbDouble>* l_buffer,bbInt l_samples,bbDouble l_detune){
  bbDBFrame db_f{"Mix:Void(buffer:Double[],samples:Int,detune:V:Double)","/Users/simon/nitrologic/m2/vsynth/vsynth.monkey2"};
  t_default_Voice*self=this;
  bbDBLocal("Self",&self);
  bbDBLocal("buffer",&l_buffer);
  bbDBLocal("samples",&l_samples);
  bbDBLocal("detune",&l_detune);
  bbDBStmt(860168);
  bbFloat l_left=1.0f;
  bbDBLocal("left",&l_left);
  bbDBStmt(864264);
  bbFloat l_right=1.0f;
  bbDBLocal("right",&l_right);
  bbDBStmt(868354);
  if((this->m_pan<0.0)){
    bbDBBlock db_blk;
    bbDBStmt(868363);
    l_right+=bbFloat(this->m_pan);
  }
  bbDBStmt(872450);
  if((this->m_pan>0.0)){
    bbDBBlock db_blk;
    bbDBStmt(872459);
    l_left-=bbFloat(this->m_pan);
  }
  bbDBStmt(876546);
  {
    bbDBLoop db_loop;
    bbInt l_i=bbInt(0);
    bbDBLocal("i",&l_i);
    bbDBStmt(876546);
    for(;(l_i<l_samples);l_i+=1){
      bbDBBlock db_blk;
      bbDBStmt(880649);
      bbDouble l_v=this->m_oscillator->m_Sample((this->m_hz*l_detune));
      bbDBLocal("v",&l_v);
      bbDBStmt(884745);
      bbDouble l_e{};
      bbDBLocal("e",&l_e);
      bbDBStmt(888835);
      if(this->m_noteOn){
        bbDBBlock db_blk;
        bbDBStmt(888845);
        l_e=this->m_envelope->m_On();
      }else{
        bbDBStmt(888861);
        bbDBBlock db_blk;
        bbDBStmt(888866);
        l_e=this->m_envelope->m_Off();
      }
      bbDBStmt(892931);
      l_e*=this->m_gain;
      bbDBStmt(897027);
      l_buffer->at(((l_i*2)+bbInt(0)))+=((l_e*bbDouble(l_left))*l_v);
      bbDBStmt(901123);
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
  bbDBStmt(974850);
  {
    bbDBLoop db_loop;
    bbInt l_i=bbInt(0);
    bbDBLocal("i",&l_i);
    bbDBStmt(974850);
    for(;(l_i<g_default_MaxPolyphony);l_i+=1){
      struct f2_t : public bbGCFrame{
        t_default_Voice* l_tone{};
        void gcMark(){
          bbGCMarkPtr(l_tone);
        }
      }f2{};
      bbDBBlock db_blk;
      bbDBStmt(978953);
      f2.l_tone=bbGCNew<t_default_Voice>();
      bbDBLocal("tone",&f2.l_tone);
      bbDBStmt(983043);
      f2.l_tone->m_SetOscillator(bbInt(0));
      bbDBStmt(987139);
      f2.l_tone->m_SetEnvelope(bbInt(0));
      bbDBStmt(991235);
      this->m_polyList->m_AddLast(f2.l_tone);
    }
  }
}

void t_default_PolySynth::m_Panic(){
  bbDBFrame db_f{"Panic:Void()","/Users/simon/nitrologic/m2/vsynth/vsynth.monkey2"};
  t_default_PolySynth*self=this;
  bbDBLocal("Self",&self);
  bbDBStmt(1011714);
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
  bbDBStmt(1028098);
  this->m_NoteOff(l_note);
  bbDBStmt(1032194);
  if(this->m_polyList->m_Empty()){
    bbDBBlock db_blk;
    bbDBStmt(1032212);
    return;
  }
  bbDBStmt(1036296);
  f0.l_voice=this->m_polyList->m_RemoveFirst();
  bbDBLocal("voice",&f0.l_voice);
  bbDBStmt(1040386);
  f0.l_voice->m_SetEnvelope(l_envelope);
  bbDBStmt(1044482);
  f0.l_voice->m_SetOscillator(l_oscillator);
  bbDBStmt(1048578);
  f0.l_voice->m_NoteOn(l_note);
  bbDBStmt(1052674);
  this->m_polyMap->m__idxeq(l_note,f0.l_voice);
  bbDBStmt(1056770);
  this->m_polyList->m_Remove(f0.l_voice);
  bbDBStmt(1060866);
  if(!this->m_voices->m_Contains(f0.l_voice)){
    bbDBBlock db_blk;
    bbDBStmt(1064963);
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
  bbDBStmt(1085448);
  f0.l_voice=this->m_polyMap->m__idx(l_note);
  bbDBLocal("voice",&f0.l_voice);
  bbDBStmt(1089538);
  if(bbBool(f0.l_voice)){
    bbDBBlock db_blk;
    bbDBStmt(1093635);
    f0.l_voice->m_Stop();
    bbDBStmt(1097731);
    this->m_polyMap->m_Remove(l_note);
    bbDBStmt(1101827);
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
  bbDBStmt(1122306);
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
      bbDBStmt(1126403);
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

void t_default_MonoSynth::gcMark(){
  bbGCMark(m_tone);
}

void t_default_MonoSynth::dbEmit(){
  bbDBEmit("tone",&m_tone);
  bbDBEmit("monoNote",&m_monoNote);
}

t_default_MonoSynth::t_default_MonoSynth(){
  bbDBFrame db_f{"new:Void()","/Users/simon/nitrologic/m2/vsynth/vsynth.monkey2"};
  bbDBStmt(1171458);
  this->m_tone=bbGCNew<t_default_Voice>();
  bbDBStmt(1175554);
  this->m_tone->m_SetOscillator(bbInt(0));
  bbDBStmt(1179650);
  this->m_tone->m_SetEnvelope(bbInt(0));
}

void t_default_MonoSynth::m_Panic(){
  bbDBFrame db_f{"Panic:Void()","/Users/simon/nitrologic/m2/vsynth/vsynth.monkey2"};
  t_default_MonoSynth*self=this;
  bbDBLocal("Self",&self);
  bbDBStmt(1196034);
  this->m_tone->m_NoteOff();
}

void t_default_MonoSynth::m_NoteOn(bbInt l_note,bbInt l_oscillator,bbInt l_envelope){
  bbDBFrame db_f{"NoteOn:Void(note:Int,oscillator:Int,envelope:Int)","/Users/simon/nitrologic/m2/vsynth/vsynth.monkey2"};
  t_default_MonoSynth*self=this;
  bbDBLocal("Self",&self);
  bbDBLocal("note",&l_note);
  bbDBLocal("oscillator",&l_oscillator);
  bbDBLocal("envelope",&l_envelope);
  bbDBStmt(1212418);
  this->m_monoNote=l_note;
  bbDBStmt(1216514);
  this->m_tone->m_SetOscillator(l_oscillator);
  bbDBStmt(1220610);
  this->m_tone->m_SetEnvelope(l_envelope);
  bbDBStmt(1224706);
  this->m_tone->m_NoteOn(l_note);
}

void t_default_MonoSynth::m_NoteOff(bbInt l_note){
  bbDBFrame db_f{"NoteOff:Void(note:Int)","/Users/simon/nitrologic/m2/vsynth/vsynth.monkey2"};
  t_default_MonoSynth*self=this;
  bbDBLocal("Self",&self);
  bbDBLocal("note",&l_note);
  bbDBStmt(1241090);
  if((l_note==this->m_monoNote)){
    bbDBBlock db_blk;
    bbDBStmt(1245187);
    this->m_tone->m_NoteOff();
  }
}

void t_default_MonoSynth::m_FillAudioBuffer(bbArray<bbDouble>* l_buffer,bbInt l_samples,bbDouble l_detune){
  bbDBFrame db_f{"FillAudioBuffer:Void(buffer:Double[],samples:Int,detune:V:Double)","/Users/simon/nitrologic/m2/vsynth/vsynth.monkey2"};
  t_default_MonoSynth*self=this;
  bbDBLocal("Self",&self);
  bbDBLocal("buffer",&l_buffer);
  bbDBLocal("samples",&l_samples);
  bbDBLocal("detune",&l_detune);
  bbDBStmt(1265666);
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
}

void t_default_VSynthWindow::gcMark(){
  t_mojo_app_Window::gcMark();
  bbGCMark(m_keyNoteMap);
}

void t_default_VSynthWindow::dbEmit(){
  t_mojo_app_Window::dbEmit();
  bbDBEmit("frame",&m_frame);
  bbDBEmit("tick",&m_tick);
  bbDBEmit("mousex",&m_mousex);
  bbDBEmit("mousey",&m_mousey);
  bbDBEmit("oscillator",&m_oscillator);
  bbDBEmit("envelope",&m_envelope);
  bbDBEmit("octave",&m_octave);
  bbDBEmit("pitchbend",&m_pitchbend);
  bbDBEmit("arp",&m_arp);
  bbDBEmit("tempo",&m_tempo);
  bbDBEmit("keyNoteMap",&m_keyNoteMap);
}

t_default_VSynthWindow::t_default_VSynthWindow(bbString l_title):t_mojo_app_Window(l_title,720,560,8){
  init();
  bbDBFrame db_f{"new:Void(title:String)","/Users/simon/nitrologic/m2/vsynth/vsynth.monkey2"};
  bbDBLocal("title",&l_title);
  bbDBStmt(1671170);
  {
    bbDBLoop db_loop;
    bbInt l_i=bbInt(0);
    bbDBLocal("i",&l_i);
    bbDBStmt(1671170);
    for(;(l_i<g_default_VSynthWindow_MusicKeys->length());l_i+=1){
      bbDBBlock db_blk;
      bbDBStmt(1675267);
      this->m_keyNoteMap->m_Set(g_default_VSynthWindow_MusicKeys->at(l_i),(l_i-1));
    }
  }
  bbDBStmt(1683458);
  g_default_vsynth=bbGCNew<t_default_VSynth>();
}

void t_default_VSynthWindow::m_UpdateSequence(){
  bbDBFrame db_f{"UpdateSequence:Void()","/Users/simon/nitrologic/m2/vsynth/vsynth.monkey2"};
  t_default_VSynthWindow*self=this;
  bbDBLocal("Self",&self);
  bbDBStmt(1855490);
  this->m_frame+=1;
  bbDBStmt(1859592);
  bbInt l_t=(this->m_frame/20);
  bbDBLocal("t",&l_t);
  bbDBStmt(1863682);
  if((l_t!=this->m_tick)){
    bbDBBlock db_blk;
    bbDBStmt(1867785);
    bbInt l_note=((((l_t>>1)&15)*3)+40);
    bbDBLocal("note",&l_note);
    bbDBStmt(1871875);
    if(bbBool((l_t&1))){
      bbDBBlock db_blk;
      bbDBStmt(1875972);
      g_default_vsynth->m_NoteOn(l_note,this->m_oscillator,this->m_envelope);
    }else{
      bbDBStmt(1880067);
      bbDBBlock db_blk;
      bbDBStmt(1884164);
      g_default_vsynth->m_NoteOff(l_note);
    }
    bbDBStmt(1892355);
    this->m_tick=l_t;
  }
}

void t_default_VSynthWindow::m_OnRender(t_mojo_graphics_Canvas* l_display){
  bbDBFrame db_f{"OnRender:Void(display:mojo.graphics.Canvas)","/Users/simon/nitrologic/m2/vsynth/vsynth.monkey2"};
  t_default_VSynthWindow*self=this;
  bbDBLocal("Self",&self);
  bbDBLocal("display",&l_display);
  bbDBStmt(1699842);
  g_mojo_app_App->m_RequestRender();
  bbDBStmt(1708034);
  g_default_vsynth->m_Detune(std::pow(2.0,this->m_pitchbend));
  bbDBStmt(1712130);
  g_default_vsynth->m_UpdateAudio();
  bbDBStmt(1720328);
  bbString l_text=(((((g_default_About+BB_T(",,"))+g_default_Octave1)+BB_T(","))+g_default_Octave0)+BB_T(","));
  bbDBLocal("text",&l_text);
  bbDBStmt(1724418);
  l_text+=(BB_T("Octave=< >=")+bbString(this->m_octave));
  bbDBStmt(1728514);
  l_text+=(BB_T(",Oscillator=1-5=")+g_default_OscillatorNames->at(this->m_oscillator));
  bbDBStmt(1732610);
  l_text+=(BB_T(",Envelope=[]=")+g_default_EnvelopeNames->at(this->m_envelope));
  bbDBStmt(1736706);
  l_text+=(BB_T(",PitchBend=Mouse Wheel=")+g_default_FloatString(bbFloat(this->m_pitchbend),2));
  bbDBStmt(1740802);
  l_text+=(BB_T(",,Arpeggiator=F5-F8=")+g_default_ArpNames->at(this->m_arp));
  bbDBStmt(1744898);
  l_text+=(BB_T(",,Tempo=- +=")+bbString(this->m_tempo));
  bbDBStmt(1748994);
  l_text+=(((BB_T(",,")+g_default_Controls)+BB_T(",,"))+g_default_Contact);
  bbDBStmt(1761288);
  bbInt l_cy=40;
  bbDBLocal("cy",&l_cy);
  bbDBStmt(1765378);
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
      bbDBStmt(1769481);
      bbInt l_cx=50;
      bbDBLocal("cx",&l_cx);
      bbDBStmt(1773571);
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
          bbDBStmt(1777668);
          l_display->m_DrawText(l_tab,bbFloat(l_cx),bbFloat(l_cy),0.0f,0.0f);
          bbDBStmt(1781764);
          l_cx+=100;
        }
      }
      bbDBStmt(1789955);
      l_cy+=20;
    }
  }
}

void t_default_VSynthWindow::m_OnMouseEvent(t_mojo_app_MouseEvent* l_event){
  bbDBFrame db_f{"OnMouseEvent:Void(event:mojo.app.MouseEvent)","/Users/simon/nitrologic/m2/vsynth/vsynth.monkey2"};
  t_default_VSynthWindow*self=this;
  bbDBLocal("Self",&self);
  bbDBLocal("event",&l_event);
  bbDBStmt(2154498);
  this->m_mousex=l_event->m_Location().m_X();
  bbDBStmt(2158594);
  this->m_mousey=l_event->m_Location().m_Y();
  bbDBStmt(2162690);
  this->m_pitchbend+=bbDouble((bbFloat(l_event->m_Wheel().m_Y())/48.0f));
}

void t_default_VSynthWindow::m_OnKeyEvent(t_mojo_app_KeyEvent* l_event){
  bbDBFrame db_f{"OnKeyEvent:Void(event:mojo.app.KeyEvent)","/Users/simon/nitrologic/m2/vsynth/vsynth.monkey2"};
  t_default_VSynthWindow*self=this;
  bbDBLocal("Self",&self);
  bbDBLocal("event",&l_event);
  bbInt l_0=l_event->m_Type();
  bbDBLocal("0",&l_0);
  bbDBStmt(1941506);
  if(l_0==0){
    bbDBBlock db_blk;
    bbInt l_1=l_event->m_Key();
    bbDBLocal("1",&l_1);
    bbDBStmt(1949699);
    if(l_1==45){
      bbDBBlock db_blk;
      bbDBStmt(1957892);
      this->m_tempo-=1;
    }else if(l_1==48){
      bbDBBlock db_blk;
      bbDBStmt(1966084);
      this->m_tempo+=1;
    }else if(l_1==133){
      bbDBBlock db_blk;
      bbDBStmt(1974276);
      this->m_arp=bbInt(0);
    }else if(l_1==134){
      bbDBBlock db_blk;
      bbDBStmt(1982468);
      this->m_arp=1;
    }else if(l_1==135){
      bbDBBlock db_blk;
      bbDBStmt(1990660);
      this->m_arp=2;
    }else if(l_1==136){
      bbDBBlock db_blk;
      bbDBStmt(1998852);
      this->m_arp=3;
    }else if(l_1==137){
      bbDBBlock db_blk;
      bbDBStmt(2007044);
      this->m_arp=4;
    }else if(l_1==49){
      bbDBBlock db_blk;
      bbDBStmt(2015236);
      this->m_oscillator=bbInt(0);
    }else if(l_1==50){
      bbDBBlock db_blk;
      bbDBStmt(2023428);
      this->m_oscillator=1;
    }else if(l_1==51){
      bbDBBlock db_blk;
      bbDBStmt(2031620);
      this->m_oscillator=2;
    }else if(l_1==52){
      bbDBBlock db_blk;
      bbDBStmt(2039812);
      this->m_oscillator=3;
    }else if(l_1==53){
      bbDBBlock db_blk;
      bbDBStmt(2048004);
      this->m_oscillator=4;
    }else if(l_1==27){
      bbDBBlock db_blk;
      bbDBStmt(2056196);
      g_default_instance->m_Terminate();
    }else if(l_1==91){
      bbDBBlock db_blk;
      bbDBStmt(2064388);
      this->m_envelope=g_default_Wrap((this->m_envelope-1),bbInt(0),g_default_EnvelopeNames->length());
    }else if(l_1==93){
      bbDBBlock db_blk;
      bbDBStmt(2072580);
      this->m_envelope=g_default_Wrap((this->m_envelope+1),bbInt(0),g_default_EnvelopeNames->length());
    }else if(l_1==44){
      bbDBBlock db_blk;
      bbDBStmt(2080772);
      this->m_octave=g_monkey_math_Clamp_1i((this->m_octave-1),bbInt(0),12);
    }else if(l_1==46){
      bbDBBlock db_blk;
      bbDBStmt(2088964);
      this->m_octave=g_monkey_math_Clamp_1i((this->m_octave+1),bbInt(0),12);
    }else if(l_1==32){
      bbDBBlock db_blk;
      bbDBStmt(2097156);
      g_default_vsynth->m_ClearKeys();
    }else{
      bbDBBlock db_blk;
      bbDBStmt(2105348);
      this->m_KeyDown(l_event->m_Key());
    }
  }else if(l_0==2){
    bbDBBlock db_blk;
    bbInt l_2=l_event->m_Key();
    bbDBLocal("2",&l_2);
    bbDBStmt(2117635);
    if(l_2==27){
      bbDBBlock db_blk;
    }else{
      bbDBBlock db_blk;
      bbDBStmt(2129924);
      this->m_KeyUp(l_event->m_Key());
    }
  }
}

void t_default_VSynthWindow::m_KeyUp(bbInt l_key){
  bbDBFrame db_f{"KeyUp:Void(key:mojo.input.Key)","/Users/simon/nitrologic/m2/vsynth/vsynth.monkey2"};
  t_default_VSynthWindow*self=this;
  bbDBLocal("Self",&self);
  bbDBLocal("key",&l_key);
  bbDBStmt(1835016);
  bbInt l_note=(this->m_keyNoteMap->m__idx(l_key)+(this->m_octave*12));
  bbDBLocal("note",&l_note);
  bbDBStmt(1839106);
  g_default_vsynth->m_NoteOff(l_note);
}

void t_default_VSynthWindow::m_KeyDown(bbInt l_key){
  bbDBFrame db_f{"KeyDown:Void(key:mojo.input.Key)","/Users/simon/nitrologic/m2/vsynth/vsynth.monkey2"};
  t_default_VSynthWindow*self=this;
  bbDBLocal("Self",&self);
  bbDBLocal("key",&l_key);
  bbDBStmt(1814536);
  bbInt l_note=(this->m_keyNoteMap->m__idx(l_key)+(this->m_octave*12));
  bbDBLocal("note",&l_note);
  bbDBStmt(1818626);
  g_default_vsynth->m_NoteOn(l_note,this->m_oscillator,this->m_envelope);
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
  g_default_Duration=bbInt(0);
  g_default_FragmentSize=1024;
  g_default_WriteAhead=8192;
  g_default_AudioFrequency=44100;
  g_default_MaxPolyphony=32;
  g_default_VSynthWindow_MusicKeys=bbArray<bbInt>::create({113,97,119,115,101,100,102,116,103,121,104,117,106,107,111,108,112,59},18);
}

bbInit mx2_vsynth_vsynth_init_v("vsynth_vsynth",&mx2_vsynth_vsynth_init);
