
#include "mx2cc_mx2.h"

// ***** External *****

// ***** Internal *****

bbString g_mx2_MX2CC_0VERSION;

void mx2_mx2cc_mx2_init(){
  static bool done;
  if(done) return;
  done=true;
  g_mx2_MX2CC_0VERSION=BB_T("1.0.0");
}

bbInit mx2_mx2cc_mx2_init_v("mx2cc_mx2",&mx2_mx2cc_mx2_init);
