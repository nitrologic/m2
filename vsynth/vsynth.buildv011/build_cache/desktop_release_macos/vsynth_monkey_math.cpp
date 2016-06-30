
#include "vsynth_monkey_math.h"

// ***** External *****

// ***** Internal *****

bbDouble g_monkey_math_Abs_1d(bbDouble l_x){
  if((l_x>=0.0)){
    return l_x;
  }
  return -l_x;
}

void mx2_vsynth_monkey_math_init(){
  static bool done;
  if(done) return;
  done=true;
}

bbInit mx2_vsynth_monkey_math_init_v("vsynth_monkey_math",&mx2_vsynth_monkey_math_init);
