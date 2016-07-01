
#ifndef MX2_MX2CC_DOCS_2JSONBUFFER_H
#define MX2_MX2CC_DOCS_2JSONBUFFER_H

#include <bbmonkey.h>

// ***** External *****

#include "../../../../../modules/monkey/monkey.buildv1.0.0/desktop_release_linux/monkey_types.h"

struct t_std_collections_Stack_1s;
struct t_std_collections_Stack_1i;

// ***** Internal *****

struct t_mx2_docs_JsonBuffer;

struct t_mx2_docs_JsonBuffer : public bbObject{

  const char *typeName()const{return "t_mx2_docs_JsonBuffer";}

  bbGCVar<t_std_collections_Stack_1s> m__0buf{};
  bbGCVar<t_std_collections_Stack_1i> m__0blks{};
  bbString m__0indent{};
  bbBool m__0sep{};

  void init();

  void gcMark();

  bbString m_Flush();
  void m_Emit(bbString l_json);

  t_mx2_docs_JsonBuffer(){
    init();
  }
};

#endif
