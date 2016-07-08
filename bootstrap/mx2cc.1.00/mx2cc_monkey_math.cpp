
#include "mx2cc_monkey_math.h"

// ***** External *****

// ***** Internal *****

bbLong g_monkey_math_Max_1l(bbLong l_x,bbLong l_y){
  if((l_x>=l_y)){
    return l_x;
  }
  return l_y;
}

void mx2_mx2cc_monkey_math_init(){
  static bool done;
  if(done) return;
  done=true;
}

bbInit mx2_mx2cc_monkey_math_init_v("mx2cc_monkey_math",&mx2_mx2cc_monkey_math_init);
