
#include "mx2cc_std_collections_2container.h"

// ***** External *****

// ***** Internal *****

void mx2_mx2cc_std_collections_2container_init(){
  static bool done;
  if(done) return;
  done=true;
}

bbInit mx2_mx2cc_std_collections_2container_init_v("mx2cc_std_collections_2container",&mx2_mx2cc_std_collections_2container_init);
