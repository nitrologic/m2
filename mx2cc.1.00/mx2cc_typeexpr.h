
#ifndef MX2_MX2CC_TYPEEXPR_H
#define MX2_MX2CC_TYPEEXPR_H

#include <bbmonkey.h>

// ***** External *****

#include "mx2cc_node.h"

struct t_mx2_Type;
struct t_mx2_Scope;
struct t_mx2_VarDecl;

// ***** Internal *****

struct t_mx2_TypeExpr;
struct t_mx2_IdentTypeExpr;
struct t_mx2_FuncTypeExpr;
struct t_mx2_MemberTypeExpr;
struct t_mx2_ArrayTypeExpr;
struct t_mx2_GenericTypeExpr;
struct t_mx2_PointerTypeExpr;

extern bbArray<bbGCVar<t_mx2_Type>>* g_mx2_SemantTypes(bbArray<bbGCVar<t_mx2_TypeExpr>>* l_exprs,t_mx2_Scope* l_scope);

struct t_mx2_TypeExpr : public t_mx2_PNode{

  const char *typeName()const{return "t_mx2_TypeExpr";}

  t_mx2_TypeExpr(bbInt l_srcpos,bbInt l_endpos);

  t_mx2_Type* m_Semant(t_mx2_Scope* l_scope,bbBool l_generic);
  virtual t_mx2_Type* m_OnSemant(t_mx2_Scope* l_scope);

  t_mx2_TypeExpr(){
  }
};

struct t_mx2_IdentTypeExpr : public t_mx2_TypeExpr{

  const char *typeName()const{return "t_mx2_IdentTypeExpr";}

  bbString m_ident{};

  t_mx2_IdentTypeExpr(bbString l_ident,bbInt l_srcpos,bbInt l_endpos);

  bbString m_ToString();
  t_mx2_Type* m_OnSemant(t_mx2_Scope* l_scope);

  t_mx2_IdentTypeExpr(){
  }
};

struct t_mx2_FuncTypeExpr : public t_mx2_TypeExpr{

  const char *typeName()const{return "t_mx2_FuncTypeExpr";}

  bbGCVar<t_mx2_TypeExpr> m_retType{};
  bbGCVar<bbArray<bbGCVar<t_mx2_VarDecl>>> m_params{};

  void gcMark();

  t_mx2_FuncTypeExpr(t_mx2_TypeExpr* l_retType,bbArray<bbGCVar<t_mx2_VarDecl>>* l_params,bbInt l_srcpos,bbInt l_endpos);

  bbString m_ToString();
  t_mx2_Type* m_OnSemant(t_mx2_Scope* l_scope);

  t_mx2_FuncTypeExpr(){
  }
};

struct t_mx2_MemberTypeExpr : public t_mx2_TypeExpr{

  const char *typeName()const{return "t_mx2_MemberTypeExpr";}

  bbGCVar<t_mx2_TypeExpr> m_type{};
  bbString m_ident{};

  void gcMark();

  t_mx2_MemberTypeExpr(t_mx2_TypeExpr* l_type,bbString l_ident,bbInt l_srcpos,bbInt l_endpos);

  bbString m_ToString();
  t_mx2_Type* m_OnSemant(t_mx2_Scope* l_scope);

  t_mx2_MemberTypeExpr(){
  }
};

struct t_mx2_ArrayTypeExpr : public t_mx2_TypeExpr{

  const char *typeName()const{return "t_mx2_ArrayTypeExpr";}

  bbGCVar<t_mx2_TypeExpr> m_type{};
  bbInt m_rank{};

  void gcMark();

  t_mx2_ArrayTypeExpr(t_mx2_TypeExpr* l_type,bbInt l_rank,bbInt l_srcpos,bbInt l_endpos);

  bbString m_ToString();
  t_mx2_Type* m_OnSemant(t_mx2_Scope* l_scope);

  t_mx2_ArrayTypeExpr(){
  }
};

struct t_mx2_GenericTypeExpr : public t_mx2_TypeExpr{

  const char *typeName()const{return "t_mx2_GenericTypeExpr";}

  bbGCVar<t_mx2_TypeExpr> m_type{};
  bbGCVar<bbArray<bbGCVar<t_mx2_TypeExpr>>> m_args{};

  void gcMark();

  t_mx2_GenericTypeExpr(t_mx2_TypeExpr* l_type,bbArray<bbGCVar<t_mx2_TypeExpr>>* l_args,bbInt l_srcpos,bbInt l_endpos);

  bbString m_ToString();
  t_mx2_Type* m_OnSemant(t_mx2_Scope* l_scope);

  t_mx2_GenericTypeExpr(){
  }
};

struct t_mx2_PointerTypeExpr : public t_mx2_TypeExpr{

  const char *typeName()const{return "t_mx2_PointerTypeExpr";}

  bbGCVar<t_mx2_TypeExpr> m_type{};

  void gcMark();

  t_mx2_PointerTypeExpr(t_mx2_TypeExpr* l_type,bbInt l_srcpos,bbInt l_endpos);

  bbString m_ToString();
  t_mx2_Type* m_OnSemant(t_mx2_Scope* l_scope);

  t_mx2_PointerTypeExpr(){
  }
};

#endif
