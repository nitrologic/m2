
#ifndef MX2_MX2CC_EXPR_H
#define MX2_MX2CC_EXPR_H

#include <bbmonkey.h>

// ***** External *****

#include "mx2cc_node.h"

struct t_mx2_Type;
struct t_mx2_PrimType;
struct t_mx2_Value;
struct t_mx2_Scope;
struct t_mx2_TypeExpr;
struct t_mx2_ArrayTypeExpr;
struct t_mx2_FuncDecl;

// ***** Internal *****

struct t_mx2_Expr;
struct t_mx2_ValueExpr;
struct t_mx2_IdentExpr;
struct t_mx2_MemberExpr;
struct t_mx2_InvokeExpr;
struct t_mx2_GenericExpr;
struct t_mx2_NewObjectExpr;
struct t_mx2_NewArrayExpr;
struct t_mx2_IndexExpr;
struct t_mx2_ExtendsExpr;
struct t_mx2_CastExpr;
struct t_mx2_SelfExpr;
struct t_mx2_SuperExpr;
struct t_mx2_NullExpr;
struct t_mx2_UnaryopExpr;
struct t_mx2_BinaryopExpr;
struct t_mx2_IfThenElseExpr;
struct t_mx2_VarptrExpr;
struct t_mx2_LiteralExpr;
struct t_mx2_ArrayLiteralExpr;
struct t_mx2_LambdaExpr;

extern t_mx2_Type* g_mx2_BinaryopExpr_BalanceTypes(t_mx2_Type* l_lhs,t_mx2_Type* l_rhs);
extern t_mx2_Type* g_mx2_BinaryopExpr_BalancePrimTypes(t_mx2_PrimType* l_lhs,t_mx2_PrimType* l_rhs);
extern t_mx2_Type* g_mx2_BinaryopExpr_BalanceNumericTypes(t_mx2_PrimType* l_lhs,t_mx2_PrimType* l_rhs);
extern t_mx2_Type* g_mx2_BinaryopExpr_BalanceIntegralTypes(t_mx2_PrimType* l_lhs,t_mx2_PrimType* l_rhs);

struct t_mx2_Expr : public t_mx2_PNode{

  const char *typeName()const{return "t_mx2_Expr";}

  t_mx2_Expr(bbInt l_srcpos,bbInt l_endpos);

  t_mx2_Value* m_TrySemantRValue(t_mx2_Scope* l_scope,t_mx2_Type* l_type);
  bbBool m_SemantWhere(t_mx2_Scope* l_scope);
  t_mx2_Type* m_SemantType(t_mx2_Scope* l_scope,bbBool l_generic);
  t_mx2_Value* m_SemantRValue(t_mx2_Scope* l_scope,t_mx2_Type* l_type);
  t_mx2_Value* m_Semant(t_mx2_Scope* l_scope);
  virtual bbBool m_OnSemantWhere(t_mx2_Scope* l_scope);
  virtual t_mx2_Type* m_OnSemantType(t_mx2_Scope* l_scope);
  virtual t_mx2_Value* m_OnSemant(t_mx2_Scope* l_scope);

  t_mx2_Expr(){
  }
};

struct t_mx2_ValueExpr : public t_mx2_Expr{

  const char *typeName()const{return "t_mx2_ValueExpr";}

  bbGCVar<t_mx2_Value> m_value{};

  void gcMark();

  t_mx2_ValueExpr(t_mx2_Value* l_value,bbInt l_srcpos,bbInt l_endpos);

  t_mx2_Value* m_OnSemant(t_mx2_Scope* l_scope);

  t_mx2_ValueExpr(){
  }
};

struct t_mx2_IdentExpr : public t_mx2_Expr{

  const char *typeName()const{return "t_mx2_IdentExpr";}

  bbString m_ident{};

  t_mx2_IdentExpr(bbString l_ident,bbInt l_srcpos,bbInt l_endpos);

  bbString m_ToString();
  t_mx2_Type* m_OnSemantType(t_mx2_Scope* l_scope);
  t_mx2_Value* m_OnSemant(t_mx2_Scope* l_scope);

  t_mx2_IdentExpr(){
  }
};

struct t_mx2_MemberExpr : public t_mx2_Expr{

  const char *typeName()const{return "t_mx2_MemberExpr";}

  bbGCVar<t_mx2_Expr> m_expr{};
  bbString m_ident{};

  void gcMark();

  t_mx2_MemberExpr(t_mx2_Expr* l_expr,bbString l_ident,bbInt l_srcpos,bbInt l_endpos);

  bbString m_ToString();
  t_mx2_Type* m_OnSemantType(t_mx2_Scope* l_scope);
  t_mx2_Value* m_OnSemant(t_mx2_Scope* l_scope);

  t_mx2_MemberExpr(){
  }
};

struct t_mx2_InvokeExpr : public t_mx2_Expr{

  const char *typeName()const{return "t_mx2_InvokeExpr";}

  bbGCVar<t_mx2_Expr> m_expr{};
  bbGCVar<bbArray<bbGCVar<t_mx2_Expr>>> m_args{};

  void gcMark();

  t_mx2_InvokeExpr(t_mx2_Expr* l_expr,bbArray<bbGCVar<t_mx2_Expr>>* l_args,bbInt l_srcpos,bbInt l_endpos);

  bbString m_ToString();
  t_mx2_Value* m_OnSemant(t_mx2_Scope* l_scope);

  t_mx2_InvokeExpr(){
  }
};

struct t_mx2_GenericExpr : public t_mx2_Expr{

  const char *typeName()const{return "t_mx2_GenericExpr";}

  bbGCVar<t_mx2_Expr> m_expr{};
  bbGCVar<bbArray<bbGCVar<t_mx2_TypeExpr>>> m_types{};

  void gcMark();

  t_mx2_GenericExpr(t_mx2_Expr* l_expr,bbArray<bbGCVar<t_mx2_TypeExpr>>* l_types,bbInt l_srcpos,bbInt l_endpos);

  bbString m_ToString();
  t_mx2_Type* m_OnSemantType(t_mx2_Scope* l_scope);
  t_mx2_Value* m_OnSemant(t_mx2_Scope* l_scope);

  t_mx2_GenericExpr(){
  }
};

struct t_mx2_NewObjectExpr : public t_mx2_Expr{

  const char *typeName()const{return "t_mx2_NewObjectExpr";}

  bbGCVar<t_mx2_TypeExpr> m_type{};
  bbGCVar<bbArray<bbGCVar<t_mx2_Expr>>> m_args{};

  void gcMark();

  t_mx2_NewObjectExpr(t_mx2_TypeExpr* l_type,bbArray<bbGCVar<t_mx2_Expr>>* l_args,bbInt l_srcpos,bbInt l_endpos);

  bbString m_ToString();
  t_mx2_Value* m_OnSemant(t_mx2_Scope* l_scope);

  t_mx2_NewObjectExpr(){
  }
};

struct t_mx2_NewArrayExpr : public t_mx2_Expr{

  const char *typeName()const{return "t_mx2_NewArrayExpr";}

  bbGCVar<t_mx2_ArrayTypeExpr> m_type{};
  bbGCVar<bbArray<bbGCVar<t_mx2_Expr>>> m_sizes{};
  bbGCVar<bbArray<bbGCVar<t_mx2_Expr>>> m_inits{};

  void gcMark();

  t_mx2_NewArrayExpr(t_mx2_ArrayTypeExpr* l_type,bbArray<bbGCVar<t_mx2_Expr>>* l_sizes,bbArray<bbGCVar<t_mx2_Expr>>* l_inits,bbInt l_srcpos,bbInt l_endpos);

  bbString m_ToString();
  t_mx2_Value* m_OnSemant(t_mx2_Scope* l_scope);

  t_mx2_NewArrayExpr(){
  }
};

struct t_mx2_IndexExpr : public t_mx2_Expr{

  const char *typeName()const{return "t_mx2_IndexExpr";}

  bbGCVar<t_mx2_Expr> m_expr{};
  bbGCVar<bbArray<bbGCVar<t_mx2_Expr>>> m_args{};

  void gcMark();

  t_mx2_IndexExpr(t_mx2_Expr* l_expr,bbArray<bbGCVar<t_mx2_Expr>>* l_args,bbInt l_srcpos,bbInt l_endpos);

  bbString m_ToString();
  t_mx2_Value* m_OnSemant(t_mx2_Scope* l_scope);

  t_mx2_IndexExpr(){
  }
};

struct t_mx2_ExtendsExpr : public t_mx2_Expr{

  const char *typeName()const{return "t_mx2_ExtendsExpr";}

  bbString m_op{};
  bbGCVar<t_mx2_Expr> m_expr{};
  bbGCVar<t_mx2_TypeExpr> m_type{};

  void gcMark();

  t_mx2_ExtendsExpr(bbString l_op,t_mx2_Expr* l_expr,t_mx2_TypeExpr* l_type,bbInt l_srcpos,bbInt l_endpos);

  bbBool m_OnSemantWhere(t_mx2_Scope* l_scope);
  t_mx2_Value* m_OnSemant(t_mx2_Scope* l_scope);

  t_mx2_ExtendsExpr(){
  }
};

struct t_mx2_CastExpr : public t_mx2_Expr{

  const char *typeName()const{return "t_mx2_CastExpr";}

  bbGCVar<t_mx2_TypeExpr> m_type{};
  bbGCVar<t_mx2_Expr> m_expr{};

  void gcMark();

  t_mx2_CastExpr(t_mx2_TypeExpr* l_type,t_mx2_Expr* l_expr,bbInt l_srcpos,bbInt l_endpos);

  bbString m_ToString();
  t_mx2_Value* m_OnSemant(t_mx2_Scope* l_scope);

  t_mx2_CastExpr(){
  }
};

struct t_mx2_SelfExpr : public t_mx2_Expr{

  const char *typeName()const{return "t_mx2_SelfExpr";}

  t_mx2_SelfExpr(bbInt l_srcpos,bbInt l_endpos);

  bbString m_ToString();
  t_mx2_Value* m_OnSemant(t_mx2_Scope* l_scope);

  t_mx2_SelfExpr(){
  }
};

struct t_mx2_SuperExpr : public t_mx2_Expr{

  const char *typeName()const{return "t_mx2_SuperExpr";}

  t_mx2_SuperExpr(bbInt l_srcpos,bbInt l_endpos);

  bbString m_ToString();
  t_mx2_Value* m_OnSemant(t_mx2_Scope* l_scope);

  t_mx2_SuperExpr(){
  }
};

struct t_mx2_NullExpr : public t_mx2_Expr{

  const char *typeName()const{return "t_mx2_NullExpr";}

  t_mx2_NullExpr(bbInt l_srcpos,bbInt l_endpos);

  bbString m_ToString();
  t_mx2_Value* m_OnSemant(t_mx2_Scope* l_scope);

  t_mx2_NullExpr(){
  }
};

struct t_mx2_UnaryopExpr : public t_mx2_Expr{

  const char *typeName()const{return "t_mx2_UnaryopExpr";}

  bbString m_op{};
  bbGCVar<t_mx2_Expr> m_expr{};

  void gcMark();

  t_mx2_UnaryopExpr(bbString l_op,t_mx2_Expr* l_expr,bbInt l_srcpos,bbInt l_endpos);

  bbString m_ToString();
  t_mx2_Value* m_OnSemant(t_mx2_Scope* l_scope);

  t_mx2_UnaryopExpr(){
  }
};

struct t_mx2_BinaryopExpr : public t_mx2_Expr{

  const char *typeName()const{return "t_mx2_BinaryopExpr";}

  bbString m_op{};
  bbGCVar<t_mx2_Expr> m_lhs{};
  bbGCVar<t_mx2_Expr> m_rhs{};

  void gcMark();

  t_mx2_BinaryopExpr(bbString l_op,t_mx2_Expr* l_lhs,t_mx2_Expr* l_rhs,bbInt l_srcpos,bbInt l_endpos);

  bbString m_ToString();
  bbBool m_OnSemantWhere(t_mx2_Scope* l_scope);
  t_mx2_Value* m_OnSemant(t_mx2_Scope* l_scope);

  t_mx2_BinaryopExpr(){
  }
};

struct t_mx2_IfThenElseExpr : public t_mx2_Expr{

  const char *typeName()const{return "t_mx2_IfThenElseExpr";}

  bbGCVar<t_mx2_Expr> m_expr{};
  bbGCVar<t_mx2_Expr> m_thenExpr{};
  bbGCVar<t_mx2_Expr> m_elseExpr{};

  void gcMark();

  t_mx2_IfThenElseExpr(t_mx2_Expr* l_expr,t_mx2_Expr* l_thenExpr,t_mx2_Expr* l_elseExpr,bbInt l_srcpos,bbInt l_endpos);

  t_mx2_Value* m_OnSemant(t_mx2_Scope* l_scope);

  t_mx2_IfThenElseExpr(){
  }
};

struct t_mx2_VarptrExpr : public t_mx2_Expr{

  const char *typeName()const{return "t_mx2_VarptrExpr";}

  bbGCVar<t_mx2_Expr> m_expr{};

  void gcMark();

  t_mx2_VarptrExpr(t_mx2_Expr* l_expr,bbInt l_srcpos,bbInt l_endpos);

  bbString m_ToString();
  t_mx2_Value* m_OnSemant(t_mx2_Scope* l_scope);

  t_mx2_VarptrExpr(){
  }
};

struct t_mx2_LiteralExpr : public t_mx2_Expr{

  const char *typeName()const{return "t_mx2_LiteralExpr";}

  bbString m_toke{};
  bbInt m_tokeType{};
  bbGCVar<t_mx2_TypeExpr> m_typeExpr{};

  void gcMark();

  t_mx2_LiteralExpr(bbString l_toke,bbInt l_tokeType,t_mx2_TypeExpr* l_typeExpr,bbInt l_srcpos,bbInt l_endpos);

  bbString m_ToString();
  t_mx2_Value* m_OnSemant(t_mx2_Scope* l_scope);

  t_mx2_LiteralExpr(){
  }
};

struct t_mx2_ArrayLiteralExpr : public t_mx2_Expr{

  const char *typeName()const{return "t_mx2_ArrayLiteralExpr";}

  bbGCVar<bbArray<bbGCVar<t_mx2_Expr>>> m_exprs{};

  void gcMark();

  t_mx2_ArrayLiteralExpr(bbArray<bbGCVar<t_mx2_Expr>>* l_exprs,bbInt l_srcpos,bbInt l_endpos);

  bbString m_ToString();

  t_mx2_ArrayLiteralExpr(){
  }
};

struct t_mx2_LambdaExpr : public t_mx2_Expr{

  const char *typeName()const{return "t_mx2_LambdaExpr";}

  bbGCVar<t_mx2_FuncDecl> m_decl{};

  void gcMark();

  t_mx2_LambdaExpr(t_mx2_FuncDecl* l_decl,bbInt l_srcpos,bbInt l_endpos);

  bbString m_ToString();
  t_mx2_Value* m_OnSemant(t_mx2_Scope* l_scope);

  t_mx2_LambdaExpr(){
  }
};

#endif
