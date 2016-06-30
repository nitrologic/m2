
#include "vsynth_vsynth.h"

// ***** External *****

#include "../../../../../../monkey2/modules/mojo/mojo.buildv010/desktop_release_macos/mojo_app_2app.h"
#include "../../../../../../monkey2/modules/mojo/mojo.buildv010/desktop_release_macos/mojo_app_2event.h"
#include "../../../../../../monkey2/modules/monkey/monkey.buildv010/desktop_release_macos/monkey_math.h"
#include "../../../../../../monkey2/modules/sdl2-mixer/sdl2-mixer.buildv010/desktop_release_macos/sdl2_5mixer_sdl2_5mixer.h"
#include "../../../../../../monkey2/modules/std/std.buildv010/desktop_release_macos/std_geom_2vec2.h"

extern bbDouble g_monkey_math_Abs_1d(bbDouble l_x);

// ***** Internal *****

bbGCRootVar<t_mojo_app_AppInstance> g_default_instance;
bbGCRootVar<t_default_VSynth> g_default_vsynth;
bbFloat g_default_Pos;
bbInt g_default_FragmentSize;
bbInt g_default_AudioFrequency;

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
  m_left=bbGCNew<t_default_Sine>();
  m_right=bbGCNew<t_default_Sine>();
}

void t_default_VSynth::gcMark(){
  t_mojo_app_Window::gcMark();
  bbGCMark(m_audioSpec);
  bbGCMark(m_buffer);
  bbGCMark(m_left);
  bbGCMark(m_right);
}

t_default_VSynth::t_default_VSynth(bbString l_title):t_mojo_app_Window(l_title,720,560,8){
  init();
  g_default_vsynth=this;
  this->m_OpenAudio();
}

void t_default_VSynth::m_OpenAudio(){
  struct f0_t : public bbGCFrame{
    SDL_AudioSpec l_spec{};
    void gcMark(){
      bbGCMark(l_spec);
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
  SDL_PauseAudio(bbInt(0));
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
    }
  }
}

bbArray<bbFloat>* t_default_VSynth::m_FillAudioBuffer(bbInt l_samples){
  bbFloat l_p0=bbFloat(this->m_mousey);
  bbFloat l_p1=bbFloat(this->m_mousex);
  {
    bbInt l_i=bbInt(0);
    for(;(l_i<l_samples);l_i+=1){
      bbFloat l_sleft=this->m_left->m_Sample(bbDouble(l_p0));
      bbFloat l_sright=this->m_right->m_Sample(bbDouble(l_p1));
      this->m_buffer->at(((l_i*2)+bbInt(0)))=l_sleft;
      this->m_buffer->at(((l_i*2)+1))=l_sright;
    }
  }
  g_default_Pos+=bbFloat(l_samples);
  return this->m_buffer;
}

bbFloat t_default_Oscillator::m_Sample(bbDouble l_hz){
  return 0.0f;
}

bbFloat t_default_Sine::m_Sample(bbDouble l_hz){
  bbDouble l_t=((l_hz*g_monkey_math_Pi)/bbDouble(g_default_AudioFrequency));
  this->m_r+=l_t;
  return bbFloat(std::sin(this->m_r));
}

bbFloat t_default_Sawtooth::m_Sample(bbDouble l_hz){
  bbDouble l_t=(l_hz/bbDouble(g_default_AudioFrequency));
  this->m_r+=l_t;
  return bbFloat((std::fmod((this->m_r+1.0),2.0)-1.0));
}

bbFloat t_default_Triangle::m_Sample(bbDouble l_hz){
  bbDouble l_t=(l_hz/bbDouble(g_default_AudioFrequency));
  this->m_r+=l_t;
  return bbFloat(((g_monkey_math_Abs_1d(std::fmod(this->m_r,4.0))-2.0)-1.0));
}

bbFloat t_default_Square::m_Sample(bbDouble l_hz){
  bbDouble l_t=(l_hz/bbDouble(g_default_AudioFrequency));
  this->m_r+=l_t;
  bbInt l_i=bbInt(this->m_r);
  return bbFloat((-1+(2*(l_i&1))));
}

void t_default_Voice::gcMark(){
  bbGCMark(m_oscillator);
}

void t_default_Voice::m_SetPan(bbFloat l_value){
  this->m_pan=l_value;
}

void t_default_Voice::m_SetOscillator(t_default_Oscillator* l_osc){
  this->m_oscillator=l_osc;
}

void t_default_Voice::m_NoteOn(bbInt l_note){
  this->m_hz=bbFloat((440.0*std::pow(2.0,bbDouble(((bbFloat(l_note)-67.0f)/12.0f)))));
}

void t_default_Voice::m_NoteOff(){
}

void mx2_vsynth_vsynth_init(){
  static bool done;
  if(done) return;
  done=true;
  g_default_FragmentSize=4096;
  g_default_AudioFrequency=44100;
}

bbInit mx2_vsynth_vsynth_init_v("vsynth_vsynth",&mx2_vsynth_vsynth_init);
