
#include "vsynth_vsynth.h"

// ***** External *****

#include "../../../../../../monkey2/modules/mojo/mojo.buildv010/desktop_debug_macos/mojo_app_2app.h"
#include "../../../../../../monkey2/modules/mojo/mojo.buildv010/desktop_debug_macos/mojo_app_2event.h"
#include "../../../../../../monkey2/modules/monkey/monkey.buildv010/desktop_debug_macos/monkey_math.h"
#include "../../../../../../monkey2/modules/monkey/monkey.buildv010/desktop_debug_macos/monkey_types.h"
#include "../../../../../../monkey2/modules/sdl2-mixer/sdl2-mixer.buildv010/desktop_debug_macos/sdl2_5mixer_sdl2_5mixer.h"
#include "../../../../../../monkey2/modules/std/std.buildv010/desktop_debug_macos/std_geom_2vec2.h"

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
  bbDBFrame db_f{"audio_callback:Void(a:Void Ptr,b:Ubyte Ptr,byteCount:Int)","/Users/simon/nitrologic/m2/vsynth/vsynth.monkey2"};
  bbDBLocal("a",&l_a);
  bbDBLocal("b",&l_b);
  bbDBLocal("byteCount",&l_byteCount);
  bbDBStmt(241672);
  bbInt l_samples=(l_byteCount/4);
  bbDBLocal("samples",&l_samples);
  bbDBStmt(245762);
  if((l_samples>g_default_FragmentSize)){
    bbDBBlock db_blk;
    bbDBStmt(249859);
    puts(BB_T("Audio Overrun").c_str());fflush( stdout );
    bbDBStmt(253955);
    l_samples=g_default_FragmentSize;
  }
  bbDBStmt(262152);
  f0.l_buffer=g_default_vsynth->m_FillAudioBuffer(l_samples);
  bbDBLocal("buffer",&f0.l_buffer);
  bbDBStmt(266242);
  {
    bbDBLoop db_loop;
    bbInt l_i=bbInt(0);
    bbDBLocal("i",&l_i);
    bbDBStmt(266242);
    for(;(l_i<l_samples);l_i+=1){
      bbDBBlock db_blk;
      bbDBStmt(270345);
      bbInt l_s0=bbInt((f0.l_buffer->at(((l_i*2)+bbInt(0)))*2000.0f));
      bbDBLocal("s0",&l_s0);
      bbDBStmt(274435);
      if((l_s0>32767)){
        bbDBBlock db_blk;
        bbDBStmt(274447);
        l_s0=32767;
      }
      bbDBStmt(278531);
      if((l_s0<-32767)){
        bbDBBlock db_blk;
        bbDBStmt(278544);
        l_s0=-32767;
      }
      bbDBStmt(282627);
      l_b[((l_i*4)+bbInt(0))]=bbUByte((l_s0&255));
      bbDBStmt(286723);
      l_b[((l_i*4)+1)]=bbUByte((l_s0>>8));
      bbDBStmt(290825);
      bbInt l_s1=bbInt((f0.l_buffer->at(((l_i*2)+1))*2000.0f));
      bbDBLocal("s1",&l_s1);
      bbDBStmt(294915);
      if((l_s1>32767)){
        bbDBBlock db_blk;
        bbDBStmt(294927);
        l_s1=32767;
      }
      bbDBStmt(299011);
      if((l_s1<-32767)){
        bbDBBlock db_blk;
        bbDBStmt(299024);
        l_s1=-32767;
      }
      bbDBStmt(303107);
      l_b[((l_i*4)+2)]=bbUByte((l_s1&255));
      bbDBStmt(307203);
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
  bbDBFrame db_f{"Main:Void()","/Users/simon/nitrologic/m2/vsynth/vsynth.monkey2"};
  bbDBStmt(397313);
  g_default_instance=bbGCNew<t_mojo_app_AppInstance>();
  bbDBStmt(401409);
  bbGCNew<t_default_VSynth>(BB_T("VSynth0.01"));
  bbDBStmt(405505);
  g_mojo_app_App->m_Run();
}

void t_default_VSynth::gcMark(){
  t_mojo_app_Window::gcMark();
  bbGCMark(m_buffer);
}

void t_default_VSynth::dbEmit(){
  t_mojo_app_Window::dbEmit();
  bbDBEmit("audioSpec",&m_audioSpec);
  bbDBEmit("buffer",&m_buffer);
  bbDBEmit("mousex",&m_mousex);
  bbDBEmit("mousey",&m_mousey);
}

t_default_VSynth::t_default_VSynth(bbString l_title):t_mojo_app_Window(l_title,720,560,8){
  bbDBFrame db_f{"new:Void(title:String)","/Users/simon/nitrologic/m2/vsynth/vsynth.monkey2"};
  bbDBLocal("title",&l_title);
  bbDBStmt(77826);
  g_default_vsynth=this;
  bbDBStmt(81922);
  this->m_OpenAudio();
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
  bbDBStmt(118786);
  this->m_buffer=bbArray<bbFloat>::create((g_default_FragmentSize*2));
  bbDBStmt(122888);
  bbDBLocal("spec",&f0.l_spec);
  bbDBStmt(126978);
  f0.l_spec.freq=44100;
  bbDBStmt(131074);
  f0.l_spec.format=bbShort(AUDIO_S16);
  bbDBStmt(135170);
  f0.l_spec.channels=2;
  bbDBStmt(139266);
  f0.l_spec.samples=bbShort(g_default_FragmentSize);
  bbDBStmt(143362);
  f0.l_spec.callback=g_default_VSynth_audio_0callback;
  bbDBStmt(151554);
  Mix_CloseAudio();
  bbDBStmt(155656);
  bbInt l_error=SDL_OpenAudio(&f0.l_spec,this->m_audioSpec);
  bbDBLocal("error",&l_error);
  bbDBStmt(159746);
  if(bbBool(l_error)){
    bbDBBlock db_blk;
    bbDBStmt(163843);
    puts((((BB_T("error=")+bbString(l_error))+BB_T(" "))+bbString::fromCString(((void*)(SDL_GetError())))).c_str());fflush( stdout );
  }
  bbDBStmt(172034);
  SDL_PauseAudio(bbInt(0));
}

void t_default_VSynth::m_OnMouseEvent(t_mojo_app_MouseEvent* l_event){
  bbDBFrame db_f{"OnMouseEvent:Void(event:mojo.app.MouseEvent)","/Users/simon/nitrologic/m2/vsynth/vsynth.monkey2"};
  t_default_VSynth*self=this;
  bbDBLocal("Self",&self);
  bbDBLocal("event",&l_event);
  bbDBStmt(368642);
  this->m_mousex=l_event->m_Location().m_X();
  bbDBStmt(372738);
  this->m_mousey=l_event->m_Location().m_Y();
}

void t_default_VSynth::m_OnKeyEvent(t_mojo_app_KeyEvent* l_event){
  bbDBFrame db_f{"OnKeyEvent:Void(event:mojo.app.KeyEvent)","/Users/simon/nitrologic/m2/vsynth/vsynth.monkey2"};
  t_default_VSynth*self=this;
  bbDBLocal("Self",&self);
  bbDBLocal("event",&l_event);
  bbInt l_0=l_event->m_Type();
  bbDBLocal("0",&l_0);
  bbDBStmt(327682);
  if(l_0==0){
    bbDBBlock db_blk;
    bbInt l_1=l_event->m_Key();
    bbDBLocal("1",&l_1);
    bbDBStmt(335875);
    if(l_1==27){
      bbDBBlock db_blk;
      bbDBStmt(344068);
      g_default_instance->m_Terminate();
    }
  }
}

bbArray<bbFloat>* t_default_VSynth::m_FillAudioBuffer(bbInt l_samples){
  bbDBFrame db_f{"FillAudioBuffer:Float[](samples:Int)","/Users/simon/nitrologic/m2/vsynth/vsynth.monkey2"};
  t_default_VSynth*self=this;
  bbDBLocal("Self",&self);
  bbDBLocal("samples",&l_samples);
  bbDBStmt(188424);
  bbFloat l_p0=(bbFloat(this->m_mousey)/5000.0f);
  bbDBLocal("p0",&l_p0);
  bbDBStmt(192520);
  bbFloat l_p1=(bbFloat(this->m_mousex)/5000.0f);
  bbDBLocal("p1",&l_p1);
  bbDBStmt(196610);
  {
    bbDBLoop db_loop;
    bbInt l_i=bbInt(0);
    bbDBLocal("i",&l_i);
    bbDBStmt(196610);
    for(;(l_i<l_samples);l_i+=1){
      bbDBBlock db_blk;
      bbDBStmt(200713);
      bbDouble l_left=std::sin(bbDouble((l_p0*bbFloat((g_default_Pos+l_i)))));
      bbDBLocal("left",&l_left);
      bbDBStmt(204809);
      bbDouble l_right=std::sin(bbDouble((l_p1*bbFloat((g_default_Pos+l_i)))));
      bbDBLocal("right",&l_right);
      bbDBStmt(208899);
      this->m_buffer->at(((l_i*2)+bbInt(0)))=bbFloat(l_left);
      bbDBStmt(212995);
      this->m_buffer->at(((l_i*2)+1))=bbFloat(l_right);
    }
  }
  bbDBStmt(221186);
  g_default_Pos+=l_samples;
  bbDBStmt(225282);
  return this->m_buffer;
}
bbString bbDBType(t_default_VSynth**){
  return "default.VSynth";
}
bbString bbDBValue(t_default_VSynth**p){
  return bbDBObjectValue(*p);
}

void mx2_vsynth_vsynth_init(){
  static bool done;
  if(done) return;
  done=true;
  g_default_FragmentSize=4096;
}

bbInit mx2_vsynth_vsynth_init_v("vsynth_vsynth",&mx2_vsynth_vsynth_init);
