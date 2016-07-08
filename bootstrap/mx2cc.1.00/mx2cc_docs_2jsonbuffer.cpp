
#include "mx2cc_docs_2jsonbuffer.h"

// ***** External *****

#include "../../../../../modules/std/std.buildv1.0.0/desktop_release_linux/std_collections_2stack.h"

// ***** Internal *****

void t_mx2_docs_JsonBuffer::init(){
  m__0buf=bbGCNew<t_std_collections_Stack_1s>();
  m__0blks=bbGCNew<t_std_collections_Stack_1i>();
}

void t_mx2_docs_JsonBuffer::gcMark(){
  bbGCMark(m__0buf);
  bbGCMark(m__0blks);
}

bbString t_mx2_docs_JsonBuffer::m_Flush(){
  bbString l_json=this->m__0buf->m_Join(BB_T("\n"));
  this->m__0buf->m_Clear();
  this->m__0blks->m_Clear();
  this->m__0indent=bbString{};
  this->m__0sep=false;
  return l_json;
}

void t_mx2_docs_JsonBuffer::m_Emit(bbString l_json){
  if((l_json.startsWith(BB_T("}"))||l_json.startsWith(BB_T("]")))){
    this->m__0indent=this->m__0indent.slice(bbInt(0),-2);
    this->m__0sep=false;
    if((this->m__0blks->m_Pop()==this->m__0buf->m_Length())){
      this->m__0buf->m_Resize((this->m__0buf->m_Length()-1));
      if(bbBool(this->m__0buf->m_Length())){
        bbString l_t=this->m__0buf->m_Top();
        if(!(l_t.endsWith(BB_T("{"))||l_t.endsWith(BB_T("[")))){
          this->m__0sep=true;
        }
      }
      return;
    }
  }
  if(this->m__0sep){
    l_json=(BB_T(",")+l_json);
  }
  this->m__0buf->m_Push((this->m__0indent+l_json));
  if((l_json.endsWith(BB_T("{"))||l_json.endsWith(BB_T("[")))){
    this->m__0blks->m_Push(this->m__0buf->m_Length());
    this->m__0indent+=BB_T("  ");
    this->m__0sep=false;
    return;
  }
  this->m__0sep=true;
}

void mx2_mx2cc_docs_2jsonbuffer_init(){
  static bool done;
  if(done) return;
  done=true;
}

bbInit mx2_mx2cc_docs_2jsonbuffer_init_v("mx2cc_docs_2jsonbuffer",&mx2_mx2cc_docs_2jsonbuffer_init);
