
#include "vmixer_vmixer.h"

// ***** External *****

#include "../../../../../../monkey2/modules/mojo/mojo.buildv010/desktop_release_macos/mojo_app_2app.h"
#include "../../../../../../monkey2/modules/mojo/mojo.buildv010/desktop_release_macos/mojo_app_2event.h"
#include "../../../../../../monkey2/modules/monkey/monkey.buildv010/desktop_release_macos/monkey_math.h"
#include "../../../../../../monkey2/modules/monkey/monkey.buildv010/desktop_release_macos/monkey_types.h"
#include "../../../../../../monkey2/modules/sdl2-mixer/sdl2-mixer.buildv010/desktop_release_macos/sdl2_5mixer_sdl2_5mixer.h"
#include "../../../../../../monkey2/modules/std/std.buildv010/desktop_release_macos/std_geom_2vec2.h"

// ***** Internal *****

bbGCRootVar<t_mojo_app_AppInstance> g_default_instance;
bbGCRootVar<t_default_VSynth> g_default_vsynth;
bbInt g_default_Pos;
bbInt g_default_FragmentSize;

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
      if((l_s0>32767)){
        l_s0=32767;
      }
      if((l_s0<-32767)){
        l_s0=-32767;
      }
      l_b[((l_i*4)+bbInt(0))]=bbUByte((l_s0&255));
      l_b[((l_i*4)+1)]=bbUByte((l_s0>>8));
      bbInt l_s1=bbInt((f0.l_buffer->at(((l_i*2)+1))*2000.0f));
      if((l_s1>32767)){
        l_s1=32767;
      }
      if((l_s1<-32767)){
        l_s1=-32767;
      }
      l_b[((l_i*4)+2)]=bbUByte((l_s1&255));
      l_b[((l_i*4)+3)]=bbUByte((l_s1>>8));
    }
  }
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

void t_default_VSynth::gcMark(){
  t_mojo_app_Window::gcMark();
  bbGCMark(m_buffer);
}

t_default_VSynth::t_default_VSynth(bbString l_title):t_mojo_app_Window(l_title,720,560,8){
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
  f0.l_spec.freq=44100;
  f0.l_spec.format=bbShort(AUDIO_S16);
  f0.l_spec.channels=2;
  f0.l_spec.samples=bbShort(g_default_FragmentSize);
  f0.l_spec.callback=g_default_VSynth_audio_0callback;
  Mix_CloseAudio();
  bbInt l_error=SDL_OpenAudio(&f0.l_spec,this->m_audioSpec);
  if(bbBool(l_error)){
    puts((((BB_T("error=")+bbString(l_error))+BB_T(" "))+bbString::fromCString(((void*)(SDL_GetError())))).c_str());fflush( stdout );
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
  bbFloat l_p0=(bbFloat(this->m_mousey)/5000.0f);
  bbFloat l_p1=(bbFloat(this->m_mousex)/5000.0f);
  {
    bbInt l_i=bbInt(0);
    for(;(l_i<l_samples);l_i+=1){
      bbDouble l_left=std::sin(bbDouble((l_p0*bbFloat((g_default_Pos+l_i)))));
      bbDouble l_right=std::sin(bbDouble((l_p1*bbFloat((g_default_Pos+l_i)))));
      this->m_buffer->at(((l_i*2)+bbInt(0)))=bbFloat(l_left);
      this->m_buffer->at(((l_i*2)+1))=bbFloat(l_right);
    }
  }
  g_default_Pos+=l_samples;
  return this->m_buffer;
}

void mx2_vmixer_vmixer_init(){
  static bool done;
  if(done) return;
  done=true;
  g_default_FragmentSize=4096;
}

bbInit mx2_vmixer_vmixer_init_v("vmixer_vmixer",&mx2_vmixer_vmixer_init);
