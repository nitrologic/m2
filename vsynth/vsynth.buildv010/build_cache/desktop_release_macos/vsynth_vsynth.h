
#ifndef MX2_VSYNTH_VSYNTH_H
#define MX2_VSYNTH_VSYNTH_H

#include <bbmonkey.h>

// ***** External *****

#include "../../../../../../monkey2/modules/mojo/mojo.buildv010/desktop_release_macos/mojo_app_2window.h"
#include "../../../../../../monkey2/modules/monkey/monkey.buildv010/desktop_release_macos/monkey_types.h"
#include "../../../../../../monkey2/modules/sdl2/sdl2.buildv010/desktop_release_macos/sdl2_sdl2.h"

struct t_mojo_app_AppInstance;
struct t_mojo_app_MouseEvent;
struct t_mojo_app_KeyEvent;

// ***** Internal *****

struct t_default_VSynth;
struct t_default_Oscillator;
struct t_default_Sine;
struct t_default_Sawtooth;
struct t_default_Triangle;
struct t_default_Square;
struct t_default_Voice;

extern bbGCRootVar<t_mojo_app_AppInstance> g_default_instance;
extern bbGCRootVar<t_default_VSynth> g_default_vsynth;
extern bbFloat g_default_Pos;
extern bbInt g_default_FragmentSize;
extern bbInt g_default_AudioFrequency;

extern void g_default_VSynth_audio_0callback(void* l_a,bbUByte* l_b,bbInt l_byteCount);
extern bbInt g_default_VSynth_Limit(bbInt l_value,bbInt l_lo,bbInt l_hi);
extern void bbMain();

struct t_default_VSynth : public t_mojo_app_Window{

  const char *typeName()const{return "t_default_VSynth";}

  SDL_AudioSpec m_audioSpec{};
  bbGCVar<bbArray<bbFloat>> m_buffer{};
  bbInt m_mousex{};
  bbInt m_mousey{};
  bbGCVar<t_default_Sine> m_left{};
  bbGCVar<t_default_Sine> m_right{};

  void init();

  void gcMark();

  t_default_VSynth(bbString l_title);

  void m_OpenAudio();
  void m_OnMouseEvent(t_mojo_app_MouseEvent* l_event);
  void m_OnKeyEvent(t_mojo_app_KeyEvent* l_event);
  bbArray<bbFloat>* m_FillAudioBuffer(bbInt l_samples);

  t_default_VSynth(){
    init();
  }
};

struct t_default_Oscillator : public bbObject{

  const char *typeName()const{return "t_default_Oscillator";}

  bbDouble m_r{};

  virtual bbFloat m_Sample(bbDouble l_hz);

  t_default_Oscillator(){
  }
};

struct t_default_Sine : public t_default_Oscillator{

  const char *typeName()const{return "t_default_Sine";}

  bbFloat m_Sample(bbDouble l_hz);

  t_default_Sine(){
  }
};

struct t_default_Sawtooth : public t_default_Oscillator{

  const char *typeName()const{return "t_default_Sawtooth";}

  bbFloat m_Sample(bbDouble l_hz);

  t_default_Sawtooth(){
  }
};

struct t_default_Triangle : public t_default_Oscillator{

  const char *typeName()const{return "t_default_Triangle";}

  bbFloat m_Sample(bbDouble l_hz);

  t_default_Triangle(){
  }
};

struct t_default_Square : public t_default_Oscillator{

  const char *typeName()const{return "t_default_Square";}

  bbFloat m_Sample(bbDouble l_hz);

  t_default_Square(){
  }
};

struct t_default_Voice : public bbObject{

  const char *typeName()const{return "t_default_Voice";}

  bbGCVar<t_default_Oscillator> m_oscillator{};
  bbFloat m_pan{};
  bbBool m_noteOn{};
  bbFloat m_hz{};

  void gcMark();

  void m_SetPan(bbFloat l_value);
  void m_SetOscillator(t_default_Oscillator* l_osc);
  void m_NoteOn(bbInt l_note);
  void m_NoteOff();

  t_default_Voice(){
  }
};

#endif
