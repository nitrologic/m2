
#ifndef MX2_VSYNTH_VSYNTH_H
#define MX2_VSYNTH_VSYNTH_H

#include <bbmonkey.h>
#include "../../../audiopipe.h"

// ***** External *****

#include "../../../../../../monkey2/modules/mojo/mojo.buildv011/desktop_release_macos/mojo_app_2window.h"
#include "../../../../../../monkey2/modules/monkey/monkey.buildv011/desktop_release_macos/monkey_types.h"
#include "../../../../../../monkey2/modules/sdl2/sdl2.buildv011/desktop_release_macos/sdl2_sdl2.h"

struct t_mojo_app_AppInstance;
struct t_std_collections_Map_1TbbInt_2i;
struct t_std_collections_List_1Tt_default_Voice_2;
struct t_mojo_graphics_Canvas;
struct t_mojo_app_MouseEvent;
struct t_mojo_app_KeyEvent;

// ***** Internal *****

struct t_default_VSynth;
struct t_default_Envelope;
struct t_default_ADSR;
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
extern bbGCRootVar<bbArray<bbInt>> g_default_VSynth_MusicKeys;

extern void g_default_VSynth_audio_0callback(void* l_a,bbUByte* l_b,bbInt l_byteCount);
extern bbInt g_default_VSynth_Limit(bbInt l_value,bbInt l_lo,bbInt l_hi);
extern void bbMain();

struct t_default_VSynth : public t_mojo_app_Window{

  const char *typeName()const{return "t_default_VSynth";}

  AudioPipe* m_audioPipe{};
  bbInt m_frame{};
  bbInt m_tick{};
  bbGCVar<t_std_collections_Map_1TbbInt_2i> m_keyNoteMap{};
  SDL_AudioSpec m_audioSpec{};
  bbGCVar<bbArray<bbFloat>> m_buffer{};
  bbInt m_mousex{};
  bbInt m_mousey{};
  bbGCVar<t_std_collections_List_1Tt_default_Voice_2> m_voices{};
  bbGCVar<t_default_Voice> m_tone{};
  bbInt m_monoKey{};

  void init();

  void gcMark();

  t_default_VSynth(bbString l_title);

  void m_UpdateSequence();
  void m_OpenAudio();
  void m_OnRender(t_mojo_graphics_Canvas* l_display);
  void m_OnMouseEvent(t_mojo_app_MouseEvent* l_event);
  void m_OnKeyEvent(t_mojo_app_KeyEvent* l_event);
  void m_KeyUp(bbInt l_key);
  void m_KeyDown(bbInt l_key);
  bbArray<bbFloat>* m_FillAudioBuffer(bbInt l_samples);

  t_default_VSynth(){
    init();
  }
};

struct t_default_Envelope : public bbObject{

  const char *typeName()const{return "t_default_Envelope";}

  bbDouble m_p{};

  virtual bbDouble m_On();
  virtual bbDouble m_Off();

  t_default_Envelope(){
  }
};

struct t_default_ADSR : public t_default_Envelope{

  const char *typeName()const{return "t_default_ADSR";}

  bbDouble m_attack{};
  bbDouble m_decay{};
  bbDouble m_sustain{};
  bbDouble m_release{};
  bbDouble m_t{};
  bbBool m_noteOn{};

  t_default_ADSR(bbDouble l_a,bbDouble l_d,bbDouble l_s,bbDouble l_r);

  bbDouble m_On();
  bbDouble m_Off();

  t_default_ADSR(){
  }
};

struct t_default_Oscillator : public bbObject{

  const char *typeName()const{return "t_default_Oscillator";}

  bbDouble m_delta{};

  virtual bbDouble m_Sample(bbDouble l_hz);

  t_default_Oscillator(){
  }
};

struct t_default_Sine : public t_default_Oscillator{

  const char *typeName()const{return "t_default_Sine";}

  bbDouble m_Sample(bbDouble l_hz);

  t_default_Sine(){
  }
};

struct t_default_Sawtooth : public t_default_Oscillator{

  const char *typeName()const{return "t_default_Sawtooth";}

  bbDouble m_Sample(bbDouble l_hz);

  t_default_Sawtooth(){
  }
};

struct t_default_Triangle : public t_default_Oscillator{

  const char *typeName()const{return "t_default_Triangle";}

  bbDouble m_Sample(bbDouble l_hz);

  t_default_Triangle(){
  }
};

struct t_default_Square : public t_default_Oscillator{

  const char *typeName()const{return "t_default_Square";}

  bbDouble m_Sample(bbDouble l_hz);

  t_default_Square(){
  }
};

struct t_default_Voice : public bbObject{

  const char *typeName()const{return "t_default_Voice";}

  bbGCVar<t_default_Oscillator> m_oscillator{};
  bbGCVar<t_default_Envelope> m_envelope{};
  bbBool m_noteOn{};
  bbDouble m_hz{};
  bbDouble m_pan{};

  void gcMark();

  void m_SetPan(bbDouble l_value);
  void m_SetOscillator(t_default_Oscillator* l_osc);
  void m_SetEnvelope(t_default_Envelope* l_env);
  void m_NoteOn(bbInt l_note);
  void m_NoteOff();
  void m_Mix(bbArray<bbFloat>* l_buffer,bbInt l_samples);

  t_default_Voice(){
  }
};

#endif
