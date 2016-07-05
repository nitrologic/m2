
#include "vpaint_monkey_math.h"

// ***** External *****

// ***** Internal *****

bbDouble g_monkey_math_Abs_1d(bbDouble l_x){
  bbDBFrame db_f{"Abs<Double>:Double(x:Double)","/Users/simon/monkey2/modules/monkey/math.monkey2"};
  bbDBLocal("x",&l_x);
  bbDBStmt(884737);
  if((l_x>=0.0)){
    bbDBBlock db_blk;
    bbDBStmt(884745);
    return l_x;
  }
  bbDBStmt(888833);
  return -l_x;
}

void mx2_vpaint_monkey_math_init(){
  static bool done;
  if(done) return;
  done=true;
}

bbInit mx2_vpaint_monkey_math_init_v("vpaint_monkey_math",&mx2_vpaint_monkey_math_init);
