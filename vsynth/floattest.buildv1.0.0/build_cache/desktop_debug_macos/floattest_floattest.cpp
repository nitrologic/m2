
#include "floattest_floattest.h"

// ***** External *****

#include "../../../../../../monkey2/modules/monkey/monkey.buildv1.0.0/desktop_debug_macos/monkey_math.h"

// ***** Internal *****

void bbMain(){
  static bool done;
  if(done) return;
  done=true;
  bbDBFrame db_f{"Main:Void()","/Users/simon/nitrologic/m2/vsynth/floattest.monkey2"};
  bbDBStmt(8199);
  bbFloat l_value=0.4f;
  bbDBLocal("value",&l_value);
  bbDBStmt(12295);
  bbInt l_dp=2;
  bbDBLocal("dp",&l_dp);
  bbDBStmt(16391);
  bbInt l_integral=bbInt((bbDouble(l_value)*std::pow(10.0,bbDouble(l_dp))));
  bbDBLocal("integral",&l_integral);
  bbDBStmt(20481);
  puts(bbString(l_integral).c_str());fflush( stdout );
  bbDBStmt(28679);
  bbInt l_word=1024;
  bbDBLocal("word",&l_word);
  bbDBStmt(32775);
  bbDouble l_pitchbend=bbDouble((1.0f+(bbFloat((l_word-8192))/8192.0f)));
  bbDBLocal("pitchbend",&l_pitchbend);
  bbDBStmt(40961);
  puts((BB_T("pitchbend=")+bbString(l_pitchbend)).c_str());fflush( stdout );
}

void mx2_floattest_floattest_init(){
  static bool done;
  if(done) return;
  done=true;
}

bbInit mx2_floattest_floattest_init_v("floattest_floattest",&mx2_floattest_floattest_init);
