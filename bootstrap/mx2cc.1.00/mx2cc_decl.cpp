
#include "mx2cc_decl.h"

// ***** External *****

#include "../../../../../modules/monkey/monkey.buildv1.0.0/desktop_release_linux/monkey_types.h"
#include "mx2cc_errors.h"
#include "mx2cc_module.h"
#include "mx2cc_std_collections_2stack.h"
#include "../../../../../modules/std/std.buildv1.0.0/desktop_release_linux/std_collections_2stack.h"

// ***** Internal *****

bbInt g_mx2_DECL_0PUBLIC;
bbInt g_mx2_DECL_0PRIVATE;
bbInt g_mx2_DECL_0PROTECTED;
bbInt g_mx2_DECL_0INTERNAL;
bbInt g_mx2_DECL_0VIRTUAL;
bbInt g_mx2_DECL_0OVERRIDE;
bbInt g_mx2_DECL_0ABSTRACT;
bbInt g_mx2_DECL_0FINAL;
bbInt g_mx2_DECL_0EXTERN;
bbInt g_mx2_DECL_0EXTENSION;
bbInt g_mx2_DECL_0DEFAULT;
bbInt g_mx2_DECL_0GETTER;
bbInt g_mx2_DECL_0SETTER;
bbInt g_mx2_DECL_0OPERATOR;
bbInt g_mx2_DECL_0IFACEMEMBER;
bbInt g_mx2_DECL_0ACCESSMASK;

void t_mx2_Decl::gcMark(){
  t_mx2_PNode::gcMark();
  bbGCMark(m_members);
}

bbString t_mx2_Decl::m_ToString(){
  return ((this->m_kind.capitalize()+BB_T(" "))+this->m_ident);
}

t_mx2_SNode* t_mx2_Decl::m_ToNode(t_mx2_Scope* l_scope){
  return ((t_mx2_SNode*)0);
}

bbBool t_mx2_Decl::m_IsVirtual(){
  return ((this->m_flags&g_mx2_DECL_0VIRTUAL)!=bbInt(0));
}

bbBool t_mx2_Decl::m_IsSetter(){
  return ((this->m_flags&g_mx2_DECL_0SETTER)!=bbInt(0));
}

bbBool t_mx2_Decl::m_IsPublic(){
  return ((this->m_flags&g_mx2_DECL_0PUBLIC)!=bbInt(0));
}

bbBool t_mx2_Decl::m_IsProtected(){
  return ((this->m_flags&g_mx2_DECL_0PROTECTED)!=bbInt(0));
}

bbBool t_mx2_Decl::m_IsPrivate(){
  return ((this->m_flags&g_mx2_DECL_0PRIVATE)!=bbInt(0));
}

bbBool t_mx2_Decl::m_IsOverride(){
  return ((this->m_flags&g_mx2_DECL_0OVERRIDE)!=bbInt(0));
}

bbBool t_mx2_Decl::m_IsOperator(){
  return ((this->m_flags&g_mx2_DECL_0OPERATOR)!=bbInt(0));
}

bbBool t_mx2_Decl::m_IsInternal(){
  return ((this->m_flags&g_mx2_DECL_0INTERNAL)!=bbInt(0));
}

bbBool t_mx2_Decl::m_IsIfaceMember(){
  return ((this->m_flags&g_mx2_DECL_0IFACEMEMBER)!=bbInt(0));
}

bbBool t_mx2_Decl::m_IsGetter(){
  return ((this->m_flags&g_mx2_DECL_0GETTER)!=bbInt(0));
}

bbBool t_mx2_Decl::m_IsFinal(){
  return ((this->m_flags&g_mx2_DECL_0FINAL)!=bbInt(0));
}

bbBool t_mx2_Decl::m_IsExtern(){
  return ((this->m_flags&g_mx2_DECL_0EXTERN)!=bbInt(0));
}

bbBool t_mx2_Decl::m_IsExtension(){
  return ((this->m_flags&g_mx2_DECL_0EXTENSION)!=bbInt(0));
}

bbBool t_mx2_Decl::m_IsDefault(){
  return ((this->m_flags&g_mx2_DECL_0DEFAULT)!=bbInt(0));
}

bbBool t_mx2_Decl::m_IsAbstract(){
  return ((this->m_flags&g_mx2_DECL_0ABSTRACT)!=bbInt(0));
}

void t_mx2_Decl::m_Emit(t_std_collections_Stack_1s* l_buf,bbString l_spc){
  l_buf->m_Push((l_spc+this->m_ToString()));
  l_spc+=BB_T("  ");
  {
    bbInt l_0=bbInt(0);
    bbInt l_1=this->m_members->length();
    for(;(l_0<l_1);l_0+=1){
      struct f2_t : public bbGCFrame{
        t_mx2_Decl* l_member{};
        void gcMark(){
          bbGCMarkPtr(l_member);
        }
      }f2{};
      f2.l_member=this->m_members->at(l_0);
      f2.l_member->m_Emit(l_buf,l_spc);
    }
  }
}

void t_mx2_FileDecl::init(){
  m_functions=bbGCNew<t_std_collections_Stack_1Tt_mx2_FuncValue_2>();
  m_classes=bbGCNew<t_std_collections_Stack_1Tt_mx2_ClassType_2>();
  m_globals=bbGCNew<t_std_collections_Stack_1Tt_mx2_VarValue_2>();
}

void t_mx2_FileDecl::gcMark(){
  t_mx2_Decl::gcMark();
  bbGCMark(m_usings);
  bbGCMark(m_imports);
  bbGCMark(m_errors);
  bbGCMark(m_module);
  bbGCMark(m_functions);
  bbGCMark(m_classes);
  bbGCMark(m_globals);
}

void mx2_mx2cc_decl_init(){
  static bool done;
  if(done) return;
  done=true;
  g_mx2_DECL_0PUBLIC=1;
  g_mx2_DECL_0PRIVATE=2;
  g_mx2_DECL_0PROTECTED=4;
  g_mx2_DECL_0INTERNAL=8;
  g_mx2_DECL_0VIRTUAL=256;
  g_mx2_DECL_0OVERRIDE=512;
  g_mx2_DECL_0ABSTRACT=1024;
  g_mx2_DECL_0FINAL=2048;
  g_mx2_DECL_0EXTERN=4096;
  g_mx2_DECL_0EXTENSION=8192;
  g_mx2_DECL_0DEFAULT=16384;
  g_mx2_DECL_0GETTER=65536;
  g_mx2_DECL_0SETTER=131072;
  g_mx2_DECL_0OPERATOR=262144;
  g_mx2_DECL_0IFACEMEMBER=524288;
  g_mx2_DECL_0ACCESSMASK=(((g_mx2_DECL_0PUBLIC|g_mx2_DECL_0PRIVATE)|g_mx2_DECL_0PROTECTED)|g_mx2_DECL_0INTERNAL);
}

bbInit mx2_mx2cc_decl_init_v("mx2cc_decl",&mx2_mx2cc_decl_init);
