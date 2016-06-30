
#ifndef MX2_VMIXER_VMIXER_H
#define MX2_VMIXER_VMIXER_H

#include <bbmonkey.h>

// ***** External *****

#include "../../../../../../monkey2/modules/mojo/mojo.buildv010/desktop_release_macos/mojo_app_2window.h"
#include "../../../../../../monkey2/modules/sdl2/sdl2.buildv010/desktop_release_macos/sdl2_sdl2.h"

struct t_mojo_app_AppInstance;
struct t_mojo_app_MouseEvent;
struct t_mojo_app_KeyEvent;

// ***** Internal *****

struct t_default_VSynth;

extern bbGCRootVar<t_mojo_app_AppInstance> g_default_instance;
extern bbGCRootVar<t_default_VSynth> g_default_vsynth;
extern bbInt g_default_Pos;
extern bbInt g_default_FragmentSize;

extern void g_default_VSynth_audio_0callback(void* l_a,bbUByte* l_b,bbInt l_byteCount);
extern void bbMain();

struct t_default_VSynth : public t_mojo_app_Window{

  const char *typeName()const{return "t_default_VSynth";}

  SDL_AudioSpec* m_audioSpec{};
  bbGCVar<bbArray<bbFloat>> m_buffer{};
  bbInt m_mousex{};
  bbInt m_mousey{};

  void gcMark();

  t_default_VSynth(bbString l_title);

  void m_OpenAudio();
  void m_OnMouseEvent(t_mojo_app_MouseEvent* l_event);
  void m_OnKeyEvent(t_mojo_app_KeyEvent* l_event);
  bbArray<bbFloat>* m_FillAudioBuffer(bbInt l_samples);

  t_default_VSynth(){
  }
};

#endif
