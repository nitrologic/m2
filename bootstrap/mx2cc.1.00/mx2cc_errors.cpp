
#include "mx2cc_errors.h"

// ***** External *****

#include "../../../../../modules/monkey/monkey.buildv1.0.0/desktop_release_linux/monkey_debug.h"
#include "mx2cc_builder.h"
#include "mx2cc_decl.h"
#include "mx2cc_node.h"
#include "mx2cc_std_collections_2stack.h"
#include "mx2cc_type.h"
#include "mx2cc_value.h"

extern bbString g_mx2_Join_1Tt_mx2_Type_2(bbArray<bbGCVar<t_mx2_Type>>* l_bits,bbString l_sep);
extern bbString g_mx2_Join_1Tt_mx2_Value_2(bbArray<bbGCVar<t_mx2_Value>>* l_bits,bbString l_sep);

// ***** Internal *****

void g_mx2_TransError(bbString l_func){
  struct f0_t : public bbGCFrame{
    bbArray<bbString>* t0{};
    void gcMark(){
      bbGCMarkPtr(t0);
    }
  }f0{};
  puts(BB_T("\n").join(f0.t0=bbDB::stack()).c_str());fflush( stdout );
  throw bbGCNew<t_mx2_SemantEx>((l_func+BB_T(" Internal Error")));
}

void g_mx2_SemantError(bbString l_func){
  struct f0_t : public bbGCFrame{
    bbArray<bbString>* t0{};
    void gcMark(){
      bbGCMarkPtr(t0);
    }
  }f0{};
  puts(BB_T("\n").join(f0.t0=bbDB::stack()).c_str());fflush( stdout );
  throw bbGCNew<t_mx2_SemantEx>((l_func+BB_T(" Internal Error")));
}

t_mx2_ErrorEx::t_mx2_ErrorEx(bbString l_msg){
  struct f0_t : public bbGCFrame{
    t_mx2_Builder* l_builder{};
    void gcMark(){
      bbGCMarkPtr(l_builder);
    }
  }f0{};
  this->m_msg=l_msg;
  f0.l_builder=g_mx2_Builder_instance;
  f0.l_builder->m_errors->m_Push(this);
}

bbString t_mx2_ErrorEx::m_ToString(){
  return (BB_T("?[?] : Error :")+this->m_msg);
}

t_mx2_ParseEx::t_mx2_ParseEx(bbString l_msg,bbString l_srcfile,bbInt l_srcpos):t_mx2_ErrorEx(l_msg){
  this->m_srcfile=l_srcfile;
  this->m_srcpos=l_srcpos;
  puts(this->m_ToString().c_str());fflush( stdout );
}

bbString t_mx2_ParseEx::m_ToString(){
  return ((((this->m_srcfile+BB_T(" ["))+bbString((this->m_srcpos>>12)))+BB_T("] : Error : "))+this->m_msg);
}

void t_mx2_SemantEx::gcMark(){
  t_mx2_ErrorEx::gcMark();
  bbGCMark(m_pnode);
}

t_mx2_SemantEx::t_mx2_SemantEx(bbString l_msg,t_mx2_PNode* l_pnode):t_mx2_ErrorEx(l_msg){
  this->m_pnode=l_pnode;
  puts(this->m_ToString().c_str());fflush( stdout );
}

t_mx2_SemantEx::t_mx2_SemantEx(bbString l_msg):t_mx2_ErrorEx(l_msg){
  if(bbBool(g_mx2_PNode_semanting->m_Length())){
    this->m_pnode=g_mx2_PNode_semanting->m_Top();
  }
  puts(this->m_ToString().c_str());fflush( stdout );
}

bbString t_mx2_SemantEx::m_ToString(){
  struct f0_t : public bbGCFrame{
    t_mx2_FileDecl* l_fdecl{};
    void gcMark(){
      bbGCMarkPtr(l_fdecl);
    }
  }f0{};
  if(!bbBool(this->m_pnode)){
    return (BB_T("? [?] : Error : ")+this->m_msg);
  }
  f0.l_fdecl=this->m_pnode->m_srcfile;
  return ((((f0.l_fdecl->m_path+BB_T(" ["))+bbString((this->m_pnode->m_srcpos>>12)))+BB_T("] : Error : "))+this->m_msg);
}

t_mx2_BuildEx::t_mx2_BuildEx(bbString l_msg):t_mx2_ErrorEx(l_msg){
  puts(this->m_ToString().c_str());fflush( stdout );
}

bbString t_mx2_BuildEx::m_ToString(){
  return (BB_T("Build error: ")+this->m_msg);
}

t_mx2_TransEx::t_mx2_TransEx(bbString l_msg):t_mx2_BuildEx(l_msg){
  puts(this->m_ToString().c_str());fflush( stdout );
}

bbString t_mx2_TransEx::m_ToString(){
  return (BB_T("Translate error: ")+this->m_msg);
}

t_mx2_IdentEx::t_mx2_IdentEx(bbString l_ident):t_mx2_SemantEx(((BB_T("Identifier '")+l_ident)+BB_T("' not found"))){
}

t_mx2_TypeIdentEx::t_mx2_TypeIdentEx(bbString l_ident):t_mx2_SemantEx(((BB_T("Type '")+l_ident)+BB_T("' not found"))){
}

t_mx2_UpCastEx::t_mx2_UpCastEx(t_mx2_Value* l_value,t_mx2_Type* l_type):t_mx2_SemantEx(((((BB_T("Value cannot be implicitly cast from type '")+l_value->m_type->m_ToString())+BB_T("' to type '"))+l_type->m_ToString())+BB_T("'"))){
}

t_mx2_OverloadEx::t_mx2_OverloadEx(t_mx2_Value* l_value,bbArray<bbGCVar<t_mx2_Type>>* l_args):t_mx2_SemantEx(((((BB_T("Can't find overload for '")+l_value->m_ToString())+BB_T("' with argument types ("))+g_mx2_Join_1Tt_mx2_Type_2(l_args,BB_T(",")))+BB_T(")"))){
}

t_mx2_OverloadEx::t_mx2_OverloadEx(t_mx2_Value* l_value,bbArray<bbGCVar<t_mx2_Value>>* l_args):t_mx2_SemantEx(((((BB_T("Can't find overload for '")+l_value->m_ToString())+BB_T("' with arguments ("))+g_mx2_Join_1Tt_mx2_Value_2(l_args,BB_T(",")))+BB_T(")"))){
}

void mx2_mx2cc_errors_init(){
  static bool done;
  if(done) return;
  done=true;
}

bbInit mx2_mx2cc_errors_init_v("mx2cc_errors",&mx2_mx2cc_errors_init);
