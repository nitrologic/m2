
#include "readmidi_readmidi.h"

// ***** External *****

// ***** Internal *****

bbInt g_default_RIFF;
bbInt g_default_RMID;
bbInt g_default_MThd;
bbInt g_default_MTrk;

void bbMain(){
  static bool done;
  if(done) return;
  done=true;
  void mx2_std_main();mx2_std_main();
  puts(BB_T("readmidi v0.0").c_str());fflush( stdout );
}

bbInt g_default_readTime(bbUByte* l_p){
  bbInt l_t{};
  while(true){
    l_t=bbInt((bbUInt((l_t<<7))+bbUInt(l_p[bbInt(0)])));
    l_p+=1;
  }
  return l_t;
}

void mx2_readmidi_readmidi_init(){
  static bool done;
  if(done) return;
  done=true;
  g_default_RIFF=1179011410;
  g_default_RMID=1145654610;
  g_default_MThd=1684558925;
  g_default_MTrk=1802654797;
}

bbInit mx2_readmidi_readmidi_init_v("readmidi_readmidi",&mx2_readmidi_readmidi_init);
