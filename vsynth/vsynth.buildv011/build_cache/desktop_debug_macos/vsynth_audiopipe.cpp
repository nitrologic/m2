
#include "vsynth_audiopipe.h"

// ***** External *****

// ***** Internal *****

void mx2_vsynth_audiopipe_init(){
  static bool done;
  if(done) return;
  done=true;
}

bbInit mx2_vsynth_audiopipe_init_v("vsynth_audiopipe",&mx2_vsynth_audiopipe_init);
