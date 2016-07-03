
#ifndef MX2_MX2CC_VAR_H
#define MX2_MX2CC_VAR_H

#include <bbmonkey.h>

// ***** External *****

#include "mx2cc_decl.h"
#include "mx2cc_value.h"

struct t_mx2_Scope;
struct t_mx2_ClassScope;
struct t_mx2_SNode;
struct t_mx2_TypeExpr;
struct t_mx2_Expr;

// ***** Internal *****

struct t_mx2_VarValue;
struct t_mx2_VarDecl;
struct t_mx2_MemberVarValue;

struct t_mx2_VarValue : public t_mx2_Value{

  const char *typeName()const{return "t_mx2_VarValue";}

  bbGCVar<t_mx2_VarDecl> m_vdecl{};
  bbGCVar<t_mx2_Scope> m_scope{};
  bbGCVar<t_mx2_FileDecl> m_transFile{};
  bbGCVar<t_mx2_ClassScope> m_cscope{};
  bbGCVar<t_mx2_Value> m_init{};

  void gcMark();

  t_mx2_VarValue(bbString l_kind,bbString l_ident,t_mx2_Value* l_init,t_mx2_Scope* l_scope);
  t_mx2_VarValue(t_mx2_VarDecl* l_vdecl,t_mx2_Scope* l_scope);

  t_mx2_Value* m_ToValue(t_mx2_Value* l_instance);
  bbString m_ToString();
  t_mx2_SNode* m_OnSemant();
  bbString m_Name();
  bbBool m_IsField();
  void m_CheckAccess(t_mx2_Scope* l_tscope);

  t_mx2_VarValue(){
  }
};

struct t_mx2_VarDecl : public t_mx2_Decl{

  const char *typeName()const{return "t_mx2_VarDecl";}

  bbGCVar<t_mx2_TypeExpr> m_type{};
  bbGCVar<t_mx2_Expr> m_init{};

  void gcMark();

  bbString m_ToString();
  t_mx2_SNode* m_ToNode(t_mx2_Scope* l_scope);

  t_mx2_VarDecl(){
  }
};

struct t_mx2_MemberVarValue : public t_mx2_Value{

  const char *typeName()const{return "t_mx2_MemberVarValue";}

  bbGCVar<t_mx2_Value> m_instance{};
  bbGCVar<t_mx2_VarValue> m_member{};

  void gcMark();

  t_mx2_MemberVarValue(t_mx2_Value* l_instance,t_mx2_VarValue* l_member);

  bbString m_ToString();
  bbBool m_HasSideEffects();
  void m_CheckAccess(t_mx2_Scope* l_tscope);

  t_mx2_MemberVarValue(){
  }
};

#endif
