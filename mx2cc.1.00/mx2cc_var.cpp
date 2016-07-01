
#include "mx2cc_var.h"

// ***** External *****

#include "mx2cc_class.h"
#include "mx2cc_errors.h"
#include "mx2cc_expr.h"
#include "mx2cc_node.h"
#include "mx2cc_scope.h"
#include "mx2cc_std_collections_2stack.h"
#include "mx2cc_type.h"
#include "mx2cc_typeexpr.h"

// ***** Internal *****

void t_mx2_VarValue::gcMark(){
  t_mx2_Value::gcMark();
  bbGCMark(m_vdecl);
  bbGCMark(m_scope);
  bbGCMark(m_transFile);
  bbGCMark(m_cscope);
  bbGCMark(m_init);
}

t_mx2_VarValue::t_mx2_VarValue(bbString l_kind,bbString l_ident,t_mx2_Value* l_init,t_mx2_Scope* l_scope){
  this->m_vdecl=bbGCNew<t_mx2_VarDecl>();
  this->m_vdecl->m_kind=l_kind;
  this->m_vdecl->m_ident=l_ident;
  this->m_pnode=((t_mx2_PNode*)(this->m_vdecl));
  this->m_type=l_init->m_type;
  this->m_scope=l_scope;
  this->m_cscope=bb_object_cast<t_mx2_ClassScope*>(l_scope);
  this->m_init=l_init;
  if((((this->m_vdecl->m_kind==BB_T("global"))||(this->m_vdecl->m_kind==BB_T("local")))||(this->m_vdecl->m_kind==BB_T("param")))){
    this->m_flags|=(g_mx2_VALUE_0LVALUE|g_mx2_VALUE_0ASSIGNABLE);
  }
  this->m_semanted=((t_mx2_SNode*)(this));
}

t_mx2_VarValue::t_mx2_VarValue(t_mx2_VarDecl* l_vdecl,t_mx2_Scope* l_scope){
  this->m_pnode=((t_mx2_PNode*)(l_vdecl));
  this->m_vdecl=l_vdecl;
  this->m_scope=l_scope;
  this->m_transFile=l_scope->m_FindFile()->m_fdecl;
  this->m_cscope=bb_object_cast<t_mx2_ClassScope*>(l_scope);
  if((((l_vdecl->m_kind==BB_T("global"))||(l_vdecl->m_kind==BB_T("local")))||(l_vdecl->m_kind==BB_T("param")))){
    this->m_flags|=(g_mx2_VALUE_0LVALUE|g_mx2_VALUE_0ASSIGNABLE);
  }
}

t_mx2_Value* t_mx2_VarValue::m_ToValue(t_mx2_Value* l_instance){
  if((this->m_vdecl->m_kind==BB_T("field"))){
    if(!bbBool(l_instance)){
      throw bbGCNew<t_mx2_SemantEx>(((BB_T("Field '")+this->m_vdecl->m_ident)+BB_T("' cannot be accessed without an instance")));
    }
    if(!l_instance->m_type->m_ExtendsType(((t_mx2_Type*)(this->m_cscope->m_ctype)))){
      throw bbGCNew<t_mx2_SemantEx>(((BB_T("Field '")+this->m_vdecl->m_ident)+BB_T("' cannot be accessed from an instance of a different class")));
    }
    return ((t_mx2_Value*)(bbGCNew<t_mx2_MemberVarValue>(l_instance,this)));
  }
  return ((t_mx2_Value*)(this));
}

bbString t_mx2_VarValue::m_ToString(){
  return this->m_vdecl->m_ident;
}

t_mx2_SNode* t_mx2_VarValue::m_OnSemant(){
  if(bbBool(this->m_vdecl->m_type)){
    this->m_type=this->m_vdecl->m_type->m_Semant(this->m_scope,false);
    if(bbBool(this->m_vdecl->m_init)){
      this->m_init=this->m_vdecl->m_init->m_SemantRValue(this->m_scope,this->m_type);
    }
  }else if(bbBool(this->m_vdecl->m_init)){
    this->m_init=this->m_vdecl->m_init->m_SemantRValue(this->m_scope,((t_mx2_Type*)0));
    if(bbBool(g_mx2_TCast_1Tt_mx2_VoidType_2(this->m_init->m_type))){
      throw bbGCNew<t_mx2_SemantEx>(BB_T("Variables cannot have 'Void' type"));
    }
    this->m_type=this->m_init->m_type;
  }else{
    g_mx2_SemantError(BB_T("VarValue.OnSemant()"));
  }
  if(((!this->m_type->m_IsGeneric()&&!this->m_vdecl->m_IsExtern())&&!bbBool(bb_object_cast<t_mx2_Block*>(this->m_scope)))){
    if(((this->m_vdecl->m_kind==BB_T("global"))||(this->m_vdecl->m_kind==BB_T("const")))){
      this->m_transFile->m_globals->m_Push(this);
    }else{
      this->m_scope->m_transMembers->m_Push(((t_mx2_SNode*)(this)));
    }
  }
  return ((t_mx2_SNode*)(this));
}

bbString t_mx2_VarValue::m_Name(){
  return ((this->m_vdecl->m_ident+BB_T(":"))+this->m_type->m_Name());
}

bbBool t_mx2_VarValue::m_IsField(){
  return (this->m_vdecl->m_kind==BB_T("field"));
}

void t_mx2_VarValue::m_CheckAccess(t_mx2_Scope* l_tscope){
  g_mx2_Value_CheckAccess(((t_mx2_Decl*)(this->m_vdecl)),this->m_scope,l_tscope);
}

void t_mx2_VarDecl::gcMark(){
  t_mx2_Decl::gcMark();
  bbGCMark(m_type);
  bbGCMark(m_init);
}

bbString t_mx2_VarDecl::m_ToString(){
  bbString l_str=bbString{};
  if((this->m_kind==BB_T("param"))){
    l_str=this->m_ident;
  }else{
    l_str=t_mx2_Decl::m_ToString();
  }
  if(bbBool(this->m_type)){
    if(bbBool(l_str)){
      l_str+=BB_T(":");
    }
    l_str+=this->m_type->m_ToString();
    if(bbBool(this->m_init)){
      l_str+=(BB_T("=")+this->m_init->m_ToString());
    }
  }else if(bbBool(this->m_init)){
    l_str+=(BB_T(":=")+this->m_init->m_ToString());
  }
  return l_str;
}

t_mx2_SNode* t_mx2_VarDecl::m_ToNode(t_mx2_Scope* l_scope){
  return ((t_mx2_SNode*)(bbGCNew<t_mx2_VarValue>(this,l_scope)));
}

void t_mx2_MemberVarValue::gcMark(){
  t_mx2_Value::gcMark();
  bbGCMark(m_instance);
  bbGCMark(m_member);
}

t_mx2_MemberVarValue::t_mx2_MemberVarValue(t_mx2_Value* l_instance,t_mx2_VarValue* l_member){
  this->m_type=l_member->m_type;
  this->m_instance=l_instance;
  this->m_member=l_member;
  if((l_member->m_vdecl->m_kind==BB_T("field"))){
    if(l_member->m_cscope->m_ctype->m_IsStruct()){
      if(l_instance->m_IsLValue()){
        this->m_flags|=g_mx2_VALUE_0LVALUE;
      }
      if(l_instance->m_IsAssignable()){
        this->m_flags|=g_mx2_VALUE_0ASSIGNABLE;
      }
    }else{
      this->m_flags|=(g_mx2_VALUE_0LVALUE|g_mx2_VALUE_0ASSIGNABLE);
    }
  }
}

bbString t_mx2_MemberVarValue::m_ToString(){
  return ((this->m_instance->m_ToString()+BB_T("."))+this->m_type->m_ToString());
}

bbBool t_mx2_MemberVarValue::m_HasSideEffects(){
  return this->m_instance->m_HasSideEffects();
}

void t_mx2_MemberVarValue::m_CheckAccess(t_mx2_Scope* l_tscope){
  this->m_member->m_CheckAccess(l_tscope);
}

void mx2_mx2cc_var_init(){
  static bool done;
  if(done) return;
  done=true;
}

bbInit mx2_mx2cc_var_init_v("mx2cc_var",&mx2_mx2cc_var_init);
