
#ifndef MX2_VSYNTH_VSYNTH_H
#define MX2_VSYNTH_VSYNTH_H

#include <bbmonkey.h>

// ***** External *****

#include "../../../../../../monkey2/modules/mojo/mojo.buildv1.0.0/desktop_debug_macos/mojo_app_2window.h"
#include "../../../../../../monkey2/modules/monkey/monkey.buildv1.0.0/desktop_debug_macos/monkey_types.h"
#include "../../../../../../monkey2/modules/sdl2/sdl2.buildv1.0.0/desktop_debug_macos/sdl2_sdl2.h"

struct t_mojo_app_AppInstance;
bbString bbDBType(t_mojo_app_AppInstance**);
bbString bbDBValue(t_mojo_app_AppInstance**);
struct AudioPipe;
struct t_std_collections_Stack_1i;
bbString bbDBType(t_std_collections_Stack_1i**);
bbString bbDBValue(t_std_collections_Stack_1i**);
struct t_std_collections_List_1Tt_default_Voice_2;
bbString bbDBType(t_std_collections_List_1Tt_default_Voice_2**);
bbString bbDBValue(t_std_collections_List_1Tt_default_Voice_2**);
struct t_std_collections_Map_1iTt_default_Voice_2;
bbString bbDBType(t_std_collections_Map_1iTt_default_Voice_2**);
bbString bbDBValue(t_std_collections_Map_1iTt_default_Voice_2**);
struct t_std_collections_Stack_1Tt_default_Voice_2;
bbString bbDBType(t_std_collections_Stack_1Tt_default_Voice_2**);
bbString bbDBValue(t_std_collections_Stack_1Tt_default_Voice_2**);
struct t_std_collections_Map_1TbbInt_2i;
bbString bbDBType(t_std_collections_Map_1TbbInt_2i**);
bbString bbDBValue(t_std_collections_Map_1TbbInt_2i**);
struct t_portmidi_PortMidi;
bbString bbDBType(t_portmidi_PortMidi**);
bbString bbDBValue(t_portmidi_PortMidi**);
struct t_std_collections_Map_1iz;
bbString bbDBType(t_std_collections_Map_1iz**);
bbString bbDBValue(t_std_collections_Map_1iz**);
struct t_mojo_graphics_Canvas;
bbString bbDBType(t_mojo_graphics_Canvas**);
bbString bbDBValue(t_mojo_graphics_Canvas**);
struct t_mojo_app_MouseEvent;
bbString bbDBType(t_mojo_app_MouseEvent**);
bbString bbDBValue(t_mojo_app_MouseEvent**);
struct t_mojo_app_KeyEvent;
bbString bbDBType(t_mojo_app_KeyEvent**);
bbString bbDBValue(t_mojo_app_KeyEvent**);

// ***** Internal *****

struct t_default_VSynth;
struct t_default_Envelope;
struct t_default_ADSR;
struct t_default_Oscillator;
struct t_default_Sine;
struct t_default_Sawtooth;
struct t_default_Triangle;
struct t_default_Square;
struct t_default_Noise;
struct t_default_NotePlayer;
struct t_default_Voice;
struct t_default_Synth;
struct t_default_BeatGenerator;
struct t_default_Arpeggiator;
struct t_default_PolySynth;
struct t_default_MonoSynth;
struct t_default_VSynthWindow;

extern bbString g_default_AppTitle;
extern bbString g_default_Contact;
extern bbString g_default_About;
extern bbString g_default_Octave1;
extern bbString g_default_Octave0;
extern bbString g_default_Controls;
extern bbGCRootVar<bbArray<bbString>> g_default_OscillatorNames;
extern bbGCRootVar<bbArray<bbString>> g_default_EnvelopeNames;
extern bbGCRootVar<bbArray<bbString>> g_default_ArpNames;
extern bbGCRootVar<bbArray<bbString>> g_default_SynthNames;
extern bbGCRootVar<bbArray<bbString>> g_default_DivisorNames;
extern bbGCRootVar<t_mojo_app_AppInstance> g_default_instance;
extern bbGCRootVar<t_default_VSynth> g_default_vsynth;
extern bbInt g_default_Duration;
extern bbInt g_default_FragmentSize;
extern bbInt g_default_WriteAhead;
extern bbInt g_default_AudioFrequency;
extern bbInt g_default_MaxPolyphony;
extern bbInt g_default_MaxOctave;
extern bbGCRootVar<bbArray<bbInt>> g_default_VSynthWindow_MusicKeys;

extern bbInt g_default_VSynthWindow_Limit(bbInt l_value,bbInt l_lo,bbInt l_hi);
extern void bbMain();
extern bbInt g_default_Wrap(bbInt l_value,bbInt l_lower,bbInt l_upper);
extern bbString g_default_FloatString(bbFloat l_value,bbInt l_dp);

struct t_default_VSynth : public bbObject{

  const char *typeName()const{return "t_default_VSynth";}

  SDL_AudioSpec m_audioSpec{};
  AudioPipe* m_audioPipe{};
  bbDouble m_detune{};
  bbGCVar<t_default_Synth> m_poly{};
  bbGCVar<t_default_Synth> m_mono{};
  bbGCVar<t_default_Synth> m_root{};
  bbGCVar<t_default_Arpeggiator> m_arp{};
  bbGCVar<bbArray<bbDouble>> m_buffer{};

  void init();

  void gcMark();
  void dbEmit();

  t_default_VSynth();

  void m_UpdateAudio();
  void m_SetTempo(bbInt l_tempo,bbInt l_divisor);
  void m_SetSynth(bbInt l_synth);
  void m_OpenAudio();
  void m_NoteOn(bbInt l_note,bbInt l_oscillator,bbInt l_envelope);
  void m_NoteOff(bbInt l_note);
  void m_Detune(bbDouble l_bend);
  void m_ClearKeys();
};
bbString bbDBType(t_default_VSynth**);
bbString bbDBValue(t_default_VSynth**);

struct t_default_Envelope : public bbObject{

  const char *typeName()const{return "t_default_Envelope";}

  bbDouble m_p{};
  void dbEmit();

  virtual bbDouble m_On();
  virtual bbDouble m_Off();

  t_default_Envelope(){
  }
};
bbString bbDBType(t_default_Envelope**);
bbString bbDBValue(t_default_Envelope**);

struct t_default_ADSR : public t_default_Envelope{

  const char *typeName()const{return "t_default_ADSR";}

  bbDouble m_attack{};
  bbDouble m_decay{};
  bbDouble m_sustain{};
  bbDouble m_release{};
  bbDouble m_t{};
  bbBool m_noteOn{};
  void dbEmit();

  t_default_ADSR(bbDouble l_a,bbDouble l_d,bbDouble l_s,bbDouble l_r);

  bbDouble m_On();
  bbDouble m_Off();

  t_default_ADSR(){
  }
};
bbString bbDBType(t_default_ADSR**);
bbString bbDBValue(t_default_ADSR**);

struct t_default_Oscillator : public bbObject{

  const char *typeName()const{return "t_default_Oscillator";}

  bbDouble m_delta{};
  void dbEmit();

  virtual bbDouble m_Sample(bbDouble l_hz);

  t_default_Oscillator(){
  }
};
bbString bbDBType(t_default_Oscillator**);
bbString bbDBValue(t_default_Oscillator**);

struct t_default_Sine : public t_default_Oscillator{

  const char *typeName()const{return "t_default_Sine";}

  void dbEmit();

  bbDouble m_Sample(bbDouble l_hz);

  t_default_Sine(){
  }
};
bbString bbDBType(t_default_Sine**);
bbString bbDBValue(t_default_Sine**);

struct t_default_Sawtooth : public t_default_Oscillator{

  const char *typeName()const{return "t_default_Sawtooth";}

  void dbEmit();

  bbDouble m_Sample(bbDouble l_hz);

  t_default_Sawtooth(){
  }
};
bbString bbDBType(t_default_Sawtooth**);
bbString bbDBValue(t_default_Sawtooth**);

struct t_default_Triangle : public t_default_Oscillator{

  const char *typeName()const{return "t_default_Triangle";}

  void dbEmit();

  bbDouble m_Sample(bbDouble l_hz);

  t_default_Triangle(){
  }
};
bbString bbDBType(t_default_Triangle**);
bbString bbDBValue(t_default_Triangle**);

struct t_default_Square : public t_default_Oscillator{

  const char *typeName()const{return "t_default_Square";}

  void dbEmit();

  bbDouble m_Sample(bbDouble l_hz);

  t_default_Square(){
  }
};
bbString bbDBType(t_default_Square**);
bbString bbDBValue(t_default_Square**);

struct t_default_Noise : public t_default_Oscillator{

  const char *typeName()const{return "t_default_Noise";}

  bbDouble m_a{};
  void dbEmit();

  bbDouble m_Sample(bbDouble l_hz);

  t_default_Noise(){
  }
};
bbString bbDBType(t_default_Noise**);
bbString bbDBValue(t_default_Noise**);

struct t_default_NotePlayer : public bbInterface{
  const char *typeName()const{return "t_default_NotePlayer";}

  virtual void m_Stop()=0;
  virtual void m_SetPan(bbDouble l_value)=0;
  virtual void m_SetOscillator(bbInt l_osc)=0;
  virtual void m_SetGain(bbDouble l_value)=0;
  virtual void m_SetEnvelope(bbInt l_env)=0;
  virtual void m_NoteOn(bbInt l_note)=0;
  virtual void m_NoteOff()=0;
};
bbString bbDBType(t_default_NotePlayer**);
bbString bbDBValue(t_default_NotePlayer**);

struct t_default_Voice : public bbObject,public virtual t_default_NotePlayer{

  const char *typeName()const{return "t_default_Voice";}

  bbGCVar<t_default_Oscillator> m_oscillator{};
  bbGCVar<t_default_Envelope> m_envelope{};
  bbBool m_noteOn{};
  bbDouble m_hz{};
  bbDouble m_pan{};
  bbDouble m_gain=0.12;

  void gcMark();
  void dbEmit();

  void m_Stop();
  void m_SetPan(bbDouble l_value);
  void m_SetOscillator(bbInt l_osc);
  void m_SetGain(bbDouble l_value);
  void m_SetEnvelope(bbInt l_env);
  void m_NoteOn(bbInt l_note);
  void m_NoteOff();
  void m_Mix(bbArray<bbDouble>* l_buffer,bbInt l_samples,bbDouble l_detune);

  t_default_Voice(){
  }
};
bbString bbDBType(t_default_Voice**);
bbString bbDBValue(t_default_Voice**);

struct t_default_Synth : public bbInterface{
  const char *typeName()const{return "t_default_Synth";}

  virtual void m_SetTempo(bbInt l_tempo,bbInt l_divisor)=0;
  virtual void m_Panic()=0;
  virtual void m_NoteOn(bbInt l_note,bbInt l_oscillator,bbInt l_envelope)=0;
  virtual void m_NoteOff(bbInt l_note)=0;
  virtual void m_FillAudioBuffer(bbArray<bbDouble>* l_buffer,bbInt l_samples,bbDouble l_detune)=0;
};
bbString bbDBType(t_default_Synth**);
bbString bbDBValue(t_default_Synth**);

struct t_default_BeatGenerator : public bbObject,public virtual t_default_Synth{

  const char *typeName()const{return "t_default_BeatGenerator";}

  bbInt m_bpm=120;
  bbInt m_divisor=3;
  bbGCVar<t_default_Synth> m_output{};
  bbDouble m_time{};
  bbDouble m_clock{};
  bbInt m_oscillator{};
  bbInt m_envelope{};
  bbInt m_recent{};

  void gcMark();
  void dbEmit();

  void m_Update(bbDouble l_duration);
  void m_SetTempo(bbInt l_tempo,bbInt l_div);
  void m_SetSynth(t_default_Synth* l_synth);
  void m_Panic();
  virtual void m_NoteOn(bbInt l_note,bbInt l_osc,bbInt l_env);
  virtual void m_NoteOff(bbInt l_note);
  void m_FillAudioBuffer(bbArray<bbDouble>* l_buffer,bbInt l_samples,bbDouble l_detune);
  virtual void m_Beat();

  t_default_BeatGenerator(){
  }
};
bbString bbDBType(t_default_BeatGenerator**);
bbString bbDBValue(t_default_BeatGenerator**);

struct t_default_Arpeggiator : public t_default_BeatGenerator{

  const char *typeName()const{return "t_default_Arpeggiator";}

  bbGCVar<t_std_collections_Stack_1i> m_notes{};
  bbInt m_index{};

  void init();

  void gcMark();
  void dbEmit();

  void m_NoteOn(bbInt l_note,bbInt l_osc,bbInt l_env);
  void m_NoteOff(bbInt l_note);
  void m_Beat();

  t_default_Arpeggiator(){
    init();
  }
};
bbString bbDBType(t_default_Arpeggiator**);
bbString bbDBValue(t_default_Arpeggiator**);

struct t_default_PolySynth : public bbObject,public virtual t_default_Synth{

  const char *typeName()const{return "t_default_PolySynth";}

  bbGCVar<t_std_collections_List_1Tt_default_Voice_2> m_polyList{};
  bbGCVar<t_std_collections_Map_1iTt_default_Voice_2> m_polyMap{};
  bbGCVar<t_std_collections_Stack_1Tt_default_Voice_2> m_voices{};

  void init();

  void gcMark();
  void dbEmit();

  t_default_PolySynth();

  void m_SetTempo(bbInt l_tempo,bbInt l_divisor);
  void m_Panic();
  void m_NoteOn(bbInt l_note,bbInt l_oscillator,bbInt l_envelope);
  void m_NoteOff(bbInt l_note);
  void m_FillAudioBuffer(bbArray<bbDouble>* l_buffer,bbInt l_samples,bbDouble l_detune);
};
bbString bbDBType(t_default_PolySynth**);
bbString bbDBValue(t_default_PolySynth**);

struct t_default_MonoSynth : public bbObject,public virtual t_default_Synth{

  const char *typeName()const{return "t_default_MonoSynth";}

  bbGCVar<t_default_Voice> m_tone{};
  bbInt m_monoNote{};
  bbGCVar<t_std_collections_Stack_1i> m_notes{};
  bbInt m_oscillator{};

  void init();

  void gcMark();
  void dbEmit();

  t_default_MonoSynth();

  void m_SetTempo(bbInt l_tempo,bbInt l_divisor);
  void m_Panic();
  void m_NoteOn(bbInt l_note,bbInt l_osc,bbInt l_envelope);
  void m_NoteOff(bbInt l_note);
  void m_FillAudioBuffer(bbArray<bbDouble>* l_buffer,bbInt l_samples,bbDouble l_detune);
};
bbString bbDBType(t_default_MonoSynth**);
bbString bbDBValue(t_default_MonoSynth**);

struct t_default_VSynthWindow : public t_mojo_app_Window{

  const char *typeName()const{return "t_default_VSynthWindow";}

  bbInt m_frame{};
  bbInt m_tick{};
  bbInt m_mousex{};
  bbInt m_mousey{};
  bbInt m_synth{};
  bbInt m_oscillator{};
  bbInt m_envelope{};
  bbInt m_octave=5;
  bbDouble m_mousebend{};
  bbDouble m_pitchbend{};
  bbInt m_arp{};
  bbInt m_div{};
  bbInt m_tempo=120;
  bbGCVar<t_std_collections_Map_1TbbInt_2i> m_keyNoteMap{};
  bbGCVar<t_portmidi_PortMidi> m_portMidi{};
  bbGCVar<t_std_collections_Map_1iz> m_noteMap{};

  void init();

  void gcMark();
  void dbEmit();

  t_default_VSynthWindow(bbString l_title);

  void m_UpdateSequence();
  void m_PollMidi();
  void m_OnRender(t_mojo_graphics_Canvas* l_display);
  void m_OnMouseEvent(t_mojo_app_MouseEvent* l_event);
  void m_OnKeyEvent(t_mojo_app_KeyEvent* l_event);
  void m_KeyUp(bbInt l_key);
  void m_KeyDown(bbInt l_key);
  void m_InitMidi();

  t_default_VSynthWindow(){
    init();
  }
};
bbString bbDBType(t_default_VSynthWindow**);
bbString bbDBValue(t_default_VSynthWindow**);

#endif
