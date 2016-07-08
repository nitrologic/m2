
#include "mx2cc_typeexpr.h"

// ***** External *****

#include "../../../../../modules/monkey/monkey.buildv1.0.0/desktop_release_linux/monkey_types.h"
#include "mx2cc_class.h"
#include "mx2cc_errors.h"
#include "mx2cc_scope.h"
#include "mx2cc_std_collections_2stack.h"
#include "mx2cc_type.h"
#include "mx2cc_var.h"

extern bbString g_mx2_Join_1Tt_mx2_VarDecl_2(bbArray<bbGCVar<t_mx2_VarDecl>>* l_bits,bbString l_sep);
extern bbString g_mx2_Join_1Tt_mx2_TypeExpr_2(bbArray<bbGCVar<t_mx2_TypeExpr>>* l_bits,bbString l_sep);

// ***** Internal *****

bbArray<bbGCVar<t_mx2_Type>>* g_mx2_SemantTypes(bbArray<bbGCVar<t_mx2_TypeExpr>>* l_exprs,t_mx2_Scope* l_scope){
  struct f0_t : public bbGCFrame{
    bbArray<bbGCVar<t_mx2_Type>>* l_types{};
    void gcMark(){
      bbGCMarkPtr(l_types);
    }
  }f0{};
  f0.l_types=bbArray<bbGCVar<t_mx2_Type>>::create(l_exprs->length());
  {
    bbInt l_i=bbInt(0);
    for(;(l_i<f0.l_types->length());l_i+=1){
      f0.l_types->at(l_i)=l_exprs->at(l_i)->m_Semant(l_scope,false);
    }
  }
  return f0.l_types;
}

t_mx2_TypeExpr::t_mx2_TypeExpr(bbInt l_srcpos,bbInt l_endpos){
  this->m_srcpos=l_srcpos;
  this->m_endpos=l_endpos;
}

t_mx2_Type* t_mx2_TypeExpr::m_Semant(t_mx2_Scope* l_scope,bbBool l_generic){
  try{
    struct f1_t : public bbGCFrame{
      t_mx2_ClassType* l_ctype{};
      t_mx2_Type* l_type{};
      void gcMark(){
        bbGCMarkPtr(l_ctype);
        bbGCMarkPtr(l_type);
      }
    }f1{};
    g_mx2_PNode_semanting->m_Push(((t_mx2_PNode*)(this)));
    f1.l_type=this->m_OnSemant(l_scope);
    f1.l_ctype=g_mx2_TCast_1Tt_mx2_ClassType_2(f1.l_type);
    if(bbBool(f1.l_ctype)){
      if(l_generic){
      }else{
        if((bbBool(f1.l_ctype->m_types)&&!bbBool(f1.l_ctype->m_instanceOf))){
          throw bbGCNew<t_mx2_SemantEx>(((BB_T("Type '")+f1.l_ctype->m_ToString())+BB_T(" is generic")));
        }
      }
    }
    g_mx2_PNode_semanting->m_Pop();
    return f1.l_type;
  }catch(t_mx2_SemantEx* ex){
    struct f1_t : public bbGCFrame{
      t_mx2_SemantEx* l_ex{};
      void gcMark(){
        bbGCMarkPtr(l_ex);
      }
    }f1{};
    f1.l_ex=ex;
    g_mx2_PNode_semanting->m_Pop();
    throw f1.l_ex;
  }
  return ((t_mx2_Type*)0);
}

t_mx2_Type* t_mx2_TypeExpr::m_OnSemant(t_mx2_Scope* l_scope){
  g_mx2_SemantError(BB_T("TypeExpr.Semant()"));
  return ((t_mx2_Type*)0);
}

t_mx2_IdentTypeExpr::t_mx2_IdentTypeExpr(bbString l_ident,bbInt l_srcpos,bbInt l_endpos):t_mx2_TypeExpr(l_srcpos,l_endpos){
  this->m_ident=l_ident;
}

bbString t_mx2_IdentTypeExpr::m_ToString(){
  if(this->m_ident==BB_T("void")||this->m_ident==BB_T("bool")||this->m_ident==BB_T("byte")||this->m_ident==BB_T("short")||this->m_ident==BB_T("int")||this->m_ident==BB_T("long")||this->m_ident==BB_T("ubyte")||this->m_ident==BB_T("ushort")||this->m_ident==BB_T("uint")||this->m_ident==BB_T("ulong")||this->m_ident==BB_T("float")||this->m_ident==BB_T("double")||this->m_ident==BB_T("string")||this->m_ident==BB_T("object")){
    return this->m_ident.capitalize();
  }
  return this->m_ident;
}

t_mx2_Type* t_mx2_IdentTypeExpr::m_OnSemant(t_mx2_Scope* l_scope){
  struct f0_t : public bbGCFrame{
    t_mx2_Type* l_type{};
    void gcMark(){
      bbGCMarkPtr(l_type);
    }
  }f0{};
  f0.l_type=l_scope->m_FindType(this->m_ident);
  if(!bbBool(f0.l_type)){
    throw bbGCNew<t_mx2_TypeIdentEx>(this->m_ident);
  }
  return f0.l_type;
}

void t_mx2_FuncTypeExpr::gcMark(){
  t_mx2_TypeExpr::gcMark();
  bbGCMark(m_retType);
  bbGCMark(m_params);
}

t_mx2_FuncTypeExpr::t_mx2_FuncTypeExpr(t_mx2_TypeExpr* l_retType,bbArray<bbGCVar<t_mx2_VarDecl>>* l_params,bbInt l_srcpos,bbInt l_endpos):t_mx2_TypeExpr(l_srcpos,l_endpos){
  this->m_retType=l_retType;
  this->m_params=l_params;
}

bbString t_mx2_FuncTypeExpr::m_ToString(){
  bbString l_str=bbString{};
  if(bbBool(this->m_retType)){
    l_str=this->m_retType->m_ToString();
  }
  return (((l_str+BB_T("("))+g_mx2_Join_1Tt_mx2_VarDecl_2(this->m_params,BB_T(",")))+BB_T(")"));
}

t_mx2_Type* t_mx2_FuncTypeExpr::m_OnSemant(t_mx2_Scope* l_scope){
  struct f0_t : public bbGCFrame{
    bbArray<bbGCVar<t_mx2_Type>>* l_argTypes{};
    t_mx2_Type* l_retType{};
    void gcMark(){
      bbGCMarkPtr(l_argTypes);
      bbGCMarkPtr(l_retType);
    }
  }f0{};
  f0.l_retType=this->m_retType->m_Semant(l_scope,false);
  f0.l_argTypes=bbArray<bbGCVar<t_mx2_Type>>::create(this->m_params->length());
  {
    bbInt l_i=bbInt(0);
    for(;(l_i<f0.l_argTypes->length());l_i+=1){
      f0.l_argTypes->at(l_i)=this->m_params->at(l_i)->m_type->m_Semant(l_scope,false);
    }
  }
  return ((t_mx2_Type*)(bbGCNew<t_mx2_FuncType>(f0.l_retType,f0.l_argTypes)));
}

void t_mx2_MemberTypeExpr::gcMark(){
  t_mx2_TypeExpr::gcMark();
  bbGCMark(m_type);
}

t_mx2_MemberTypeExpr::t_mx2_MemberTypeExpr(t_mx2_TypeExpr* l_type,bbString l_ident,bbInt l_srcpos,bbInt l_endpos):t_mx2_TypeExpr(l_srcpos,l_endpos){
  this->m_type=l_type;
  this->m_ident=l_ident;
}

bbString t_mx2_MemberTypeExpr::m_ToString(){
  return ((this->m_type->m_ToString()+BB_T("."))+this->m_ident);
}

t_mx2_Type* t_mx2_MemberTypeExpr::m_OnSemant(t_mx2_Scope* l_scope){
  struct f0_t : public bbGCFrame{
    t_mx2_Type* l_type{};
    void gcMark(){
      bbGCMarkPtr(l_type);
    }
  }f0{};
  f0.l_type=this->m_type->m_Semant(l_scope,false);
  f0.l_type=f0.l_type->m_FindType(this->m_ident);
  if(!bbBool(f0.l_type)){
    throw bbGCNew<t_mx2_TypeIdentEx>(this->m_ident);
  }
  return f0.l_type;
}

void t_mx2_ArrayTypeExpr::gcMark(){
  t_mx2_TypeExpr::gcMark();
  bbGCMark(m_type);
}

t_mx2_ArrayTypeExpr::t_mx2_ArrayTypeExpr(t_mx2_TypeExpr* l_type,bbInt l_rank,bbInt l_srcpos,bbInt l_endpos):t_mx2_TypeExpr(l_srcpos,l_endpos){
  this->m_type=l_type;
  this->m_rank=l_rank;
}

bbString t_mx2_ArrayTypeExpr::m_ToString(){
  return ((this->m_type->m_ToString()+BB_T("[,,,,,,,,,,,").slice(bbInt(0),this->m_rank))+BB_T("]"));
}

t_mx2_Type* t_mx2_ArrayTypeExpr::m_OnSemant(t_mx2_Scope* l_scope){
  struct f0_t : public bbGCFrame{
    t_mx2_Type* l_type{};
    void gcMark(){
      bbGCMarkPtr(l_type);
    }
  }f0{};
  f0.l_type=this->m_type->m_Semant(l_scope,false);
  return ((t_mx2_Type*)(bbGCNew<t_mx2_ArrayType>(f0.l_type,this->m_rank)));
}

void t_mx2_GenericTypeExpr::gcMark(){
  t_mx2_TypeExpr::gcMark();
  bbGCMark(m_type);
  bbGCMark(m_args);
}

t_mx2_GenericTypeExpr::t_mx2_GenericTypeExpr(t_mx2_TypeExpr* l_type,bbArray<bbGCVar<t_mx2_TypeExpr>>* l_args,bbInt l_srcpos,bbInt l_endpos):t_mx2_TypeExpr(l_srcpos,l_endpos){
  this->m_type=l_type;
  this->m_args=l_args;
}

bbString t_mx2_GenericTypeExpr::m_ToString(){
  return (((this->m_type->m_ToString()+BB_T("<"))+g_mx2_Join_1Tt_mx2_TypeExpr_2(this->m_args,BB_T(",")))+BB_T(">"));
}

t_mx2_Type* t_mx2_GenericTypeExpr::m_OnSemant(t_mx2_Scope* l_scope){
  struct f0_t : public bbGCFrame{
    bbArray<bbGCVar<t_mx2_Type>>* l_args{};
    t_mx2_Type* l_type{};
    void gcMark(){
      bbGCMarkPtr(l_args);
      bbGCMarkPtr(l_type);
    }
  }f0{};
  f0.l_type=this->m_type->m_Semant(l_scope,true);
  f0.l_args=bbArray<bbGCVar<t_mx2_Type>>::create(this->m_args->length());
  {
    bbInt l_i=bbInt(0);
    for(;(l_i<f0.l_args->length());l_i+=1){
      f0.l_args->at(l_i)=this->m_args->at(l_i)->m_Semant(l_scope,false);
    }
  }
  return f0.l_type->m_GenInstance(f0.l_args);
}

void t_mx2_PointerTypeExpr::gcMark(){
  t_mx2_TypeExpr::gcMark();
  bbGCMark(m_type);
}

t_mx2_PointerTypeExpr::t_mx2_PointerTypeExpr(t_mx2_TypeExpr* l_type,bbInt l_srcpos,bbInt l_endpos):t_mx2_TypeExpr(l_srcpos,l_endpos){
  this->m_type=l_type;
}

bbString t_mx2_PointerTypeExpr::m_ToString(){
  return (this->m_type->m_ToString()+BB_T(" Ptr"));
}

t_mx2_Type* t_mx2_PointerTypeExpr::m_OnSemant(t_mx2_Scope* l_scope){
  struct f0_t : public bbGCFrame{
    t_mx2_Type* l_type{};
    void gcMark(){
      bbGCMarkPtr(l_type);
    }
  }f0{};
  f0.l_type=this->m_type->m_Semant(l_scope,false);
  return ((t_mx2_Type*)(bbGCNew<t_mx2_PointerType>(f0.l_type)));
}

void mx2_mx2cc_typeexpr_init(){
  static bool done;
  if(done) return;
  done=true;
}

bbInit mx2_mx2cc_typeexpr_init_v("mx2cc_typeexpr",&mx2_mx2cc_typeexpr_init);
