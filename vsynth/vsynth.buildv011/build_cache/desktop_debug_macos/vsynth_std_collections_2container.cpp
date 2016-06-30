
#include "vsynth_std_collections_2container.h"

// ***** External *****

// ***** Internal *****

bbString bbDBType(t_std_collections_IContainer_1Tt_default_Voice_2**){
  return "std.collections.IContainer<default.Voice>";
}
bbString bbDBValue(t_std_collections_IContainer_1Tt_default_Voice_2**p){
  return bbDBInterfaceValue(*p);
}

void mx2_vsynth_std_collections_2container_init(){
  static bool done;
  if(done) return;
  done=true;
}

bbInit mx2_vsynth_std_collections_2container_init_v("vsynth_std_collections_2container",&mx2_vsynth_std_collections_2container_init);
