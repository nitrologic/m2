
#ifndef MX2_MX2CC_STMTEXPR_H
#define MX2_MX2CC_STMTEXPR_H

#include <bbmonkey.h>

// ***** External *****

#include "../../../../../modules/monkey/monkey.buildv1.0.0/desktop_release_linux/monkey_types.h"
#include "mx2cc_node.h"

struct t_std_collections_Stack_1s;
struct t_mx2_Stmt;
struct t_mx2_Block;
struct t_mx2_Expr;
struct t_mx2_VarDecl;
struct t_mx2_TypeExpr;

// ***** Internal *****

struct t_mx2_StmtExpr;
struct t_mx2_AssignStmtExpr;
struct t_mx2_VarDeclStmtExpr;
struct t_mx2_EvalStmtExpr;
struct t_mx2_InvokeNewStmtExpr;
struct t_mx2_PrintStmtExpr;
struct t_mx2_ReturnStmtExpr;
struct t_mx2_ContinueStmtExpr;
struct t_mx2_ExitStmtExpr;
struct t_mx2_IfStmtExpr;
struct t_mx2_WhileStmtExpr;
struct t_mx2_RepeatStmtExpr;
struct t_mx2_CaseExpr;
struct t_mx2_SelectStmtExpr;
struct t_mx2_ForStmtExpr;
struct t_mx2_CatchExpr;
struct t_mx2_TryStmtExpr;
struct t_mx2_ThrowStmtExpr;

extern bbString g_mx2_StmtsToString(bbArray<bbGCVar<t_mx2_StmtExpr>>* l_stmts);
extern void g_mx2_EmitStmts(bbArray<bbGCVar<t_mx2_StmtExpr>>* l_stmts,t_std_collections_Stack_1s* l_buf,bbString l_spc);

struct t_mx2_StmtExpr : public t_mx2_PNode{

  const char *typeName()const{return "t_mx2_StmtExpr";}

  t_mx2_StmtExpr(bbInt l_srcpos,bbInt l_endpos);

  t_mx2_Stmt* m_Semant(t_mx2_Block* l_block);
  virtual t_mx2_Stmt* m_OnSemant(t_mx2_Block* l_block);
  virtual void m_Emit(t_std_collections_Stack_1s* l_buf,bbString l_spc);

  t_mx2_StmtExpr(){
  }
};

struct t_mx2_AssignStmtExpr : public t_mx2_StmtExpr{

  const char *typeName()const{return "t_mx2_AssignStmtExpr";}

  bbString m_op{};
  bbGCVar<t_mx2_Expr> m_lhs{};
  bbGCVar<t_mx2_Expr> m_rhs{};

  void gcMark();

  t_mx2_AssignStmtExpr(bbString l_op,t_mx2_Expr* l_lhs,t_mx2_Expr* l_rhs,bbInt l_srcpos,bbInt l_endpos);

  bbString m_ToString();
  t_mx2_Stmt* m_OnSemant(t_mx2_Block* l_block);

  t_mx2_AssignStmtExpr(){
  }
};

struct t_mx2_VarDeclStmtExpr : public t_mx2_StmtExpr{

  const char *typeName()const{return "t_mx2_VarDeclStmtExpr";}

  bbGCVar<t_mx2_VarDecl> m_decl{};

  void gcMark();

  t_mx2_VarDeclStmtExpr(t_mx2_VarDecl* l_decl,bbInt l_srcpos,bbInt l_endpos);

  bbString m_ToString();
  t_mx2_Stmt* m_OnSemant(t_mx2_Block* l_block);

  t_mx2_VarDeclStmtExpr(){
  }
};

struct t_mx2_EvalStmtExpr : public t_mx2_StmtExpr{

  const char *typeName()const{return "t_mx2_EvalStmtExpr";}

  bbGCVar<t_mx2_Expr> m_expr{};

  void gcMark();

  t_mx2_EvalStmtExpr(t_mx2_Expr* l_expr,bbInt l_srcpos,bbInt l_endpos);

  bbString m_ToString();
  t_mx2_Stmt* m_OnSemant(t_mx2_Block* l_block);

  t_mx2_EvalStmtExpr(){
  }
};

struct t_mx2_InvokeNewStmtExpr : public t_mx2_StmtExpr{

  const char *typeName()const{return "t_mx2_InvokeNewStmtExpr";}

  bbGCVar<t_mx2_Expr> m_expr{};
  bbGCVar<bbArray<bbGCVar<t_mx2_Expr>>> m_args{};

  void gcMark();

  t_mx2_InvokeNewStmtExpr(t_mx2_Expr* l_expr,bbArray<bbGCVar<t_mx2_Expr>>* l_args,bbInt l_srcpos,bbInt l_endpos);

  t_mx2_Stmt* m_OnSemant(t_mx2_Block* l_block);

  t_mx2_InvokeNewStmtExpr(){
  }
};

struct t_mx2_PrintStmtExpr : public t_mx2_StmtExpr{

  const char *typeName()const{return "t_mx2_PrintStmtExpr";}

  bbGCVar<t_mx2_Expr> m_expr{};

  void gcMark();

  t_mx2_PrintStmtExpr(t_mx2_Expr* l_expr,bbInt l_srcpos,bbInt l_endpos);

  bbString m_ToString();
  t_mx2_Stmt* m_OnSemant(t_mx2_Block* l_block);

  t_mx2_PrintStmtExpr(){
  }
};

struct t_mx2_ReturnStmtExpr : public t_mx2_StmtExpr{

  const char *typeName()const{return "t_mx2_ReturnStmtExpr";}

  bbGCVar<t_mx2_Expr> m_expr{};

  void gcMark();

  t_mx2_ReturnStmtExpr(t_mx2_Expr* l_expr,bbInt l_srcpos,bbInt l_endpos);

  bbString m_ToString();
  t_mx2_Stmt* m_OnSemant(t_mx2_Block* l_block);

  t_mx2_ReturnStmtExpr(){
  }
};

struct t_mx2_ContinueStmtExpr : public t_mx2_StmtExpr{

  const char *typeName()const{return "t_mx2_ContinueStmtExpr";}

  t_mx2_ContinueStmtExpr(bbInt l_srcpos,bbInt l_endpos);

  bbString m_ToString();
  t_mx2_Stmt* m_OnSemant(t_mx2_Block* l_block);

  t_mx2_ContinueStmtExpr(){
  }
};

struct t_mx2_ExitStmtExpr : public t_mx2_StmtExpr{

  const char *typeName()const{return "t_mx2_ExitStmtExpr";}

  t_mx2_ExitStmtExpr(bbInt l_srcpos,bbInt l_endpos);

  bbString m_ToString();
  t_mx2_Stmt* m_OnSemant(t_mx2_Block* l_block);

  t_mx2_ExitStmtExpr(){
  }
};

struct t_mx2_IfStmtExpr : public t_mx2_StmtExpr{

  const char *typeName()const{return "t_mx2_IfStmtExpr";}

  bbGCVar<t_mx2_Expr> m_cond{};
  bbGCVar<bbArray<bbGCVar<t_mx2_StmtExpr>>> m_stmts{};
  bbGCVar<t_mx2_IfStmtExpr> m_succ{};

  void gcMark();

  t_mx2_IfStmtExpr(t_mx2_Expr* l_cond,bbArray<bbGCVar<t_mx2_StmtExpr>>* l_stmts,t_mx2_IfStmtExpr* l_succ,bbInt l_srcpos,bbInt l_endpos);

  bbString m_ToString();
  t_mx2_Stmt* m_OnSemant(t_mx2_Block* l_block);
  void m_Emit(t_std_collections_Stack_1s* l_buf,bbString l_spc);

  t_mx2_IfStmtExpr(){
  }
};

struct t_mx2_WhileStmtExpr : public t_mx2_StmtExpr{

  const char *typeName()const{return "t_mx2_WhileStmtExpr";}

  bbGCVar<t_mx2_Expr> m_expr{};
  bbGCVar<bbArray<bbGCVar<t_mx2_StmtExpr>>> m_stmts{};

  void gcMark();

  t_mx2_WhileStmtExpr(t_mx2_Expr* l_expr,bbArray<bbGCVar<t_mx2_StmtExpr>>* l_stmts,bbInt l_srcpos,bbInt l_endpos);

  bbString m_ToString();
  t_mx2_Stmt* m_OnSemant(t_mx2_Block* l_block);
  void m_Emit(t_std_collections_Stack_1s* l_buf,bbString l_spc);

  t_mx2_WhileStmtExpr(){
  }
};

struct t_mx2_RepeatStmtExpr : public t_mx2_StmtExpr{

  const char *typeName()const{return "t_mx2_RepeatStmtExpr";}

  bbGCVar<bbArray<bbGCVar<t_mx2_StmtExpr>>> m_stmts{};
  bbGCVar<t_mx2_Expr> m_expr{};

  void gcMark();

  t_mx2_RepeatStmtExpr(bbArray<bbGCVar<t_mx2_StmtExpr>>* l_stmts,t_mx2_Expr* l_expr,bbInt l_srcpos,bbInt l_endpos);

  bbString m_ToString();
  t_mx2_Stmt* m_OnSemant(t_mx2_Block* l_block);
  void m_Emit(t_std_collections_Stack_1s* l_buf,bbString l_spc);

  t_mx2_RepeatStmtExpr(){
  }
};

struct t_mx2_CaseExpr : public bbObject{

  const char *typeName()const{return "t_mx2_CaseExpr";}

  bbGCVar<bbArray<bbGCVar<t_mx2_Expr>>> m_exprs{};
  bbGCVar<bbArray<bbGCVar<t_mx2_StmtExpr>>> m_stmts{};

  void gcMark();

  t_mx2_CaseExpr(bbArray<bbGCVar<t_mx2_Expr>>* l_exprs,bbArray<bbGCVar<t_mx2_StmtExpr>>* l_stmts);

  t_mx2_CaseExpr(){
  }
};

struct t_mx2_SelectStmtExpr : public t_mx2_StmtExpr{

  const char *typeName()const{return "t_mx2_SelectStmtExpr";}

  bbGCVar<t_mx2_Expr> m_expr{};
  bbGCVar<bbArray<bbGCVar<t_mx2_CaseExpr>>> m_cases{};

  void gcMark();

  t_mx2_SelectStmtExpr(t_mx2_Expr* l_expr,bbArray<bbGCVar<t_mx2_CaseExpr>>* l_cases,bbInt l_srcpos,bbInt l_endpos);

  bbString m_ToString();
  t_mx2_Stmt* m_OnSemant(t_mx2_Block* l_block);
  void m_Emit(t_std_collections_Stack_1s* l_buf,bbString l_spc);

  t_mx2_SelectStmtExpr(){
  }
};

struct t_mx2_ForStmtExpr : public t_mx2_StmtExpr{

  const char *typeName()const{return "t_mx2_ForStmtExpr";}

  bbString m_varIdent{};
  bbGCVar<t_mx2_TypeExpr> m_varType{};
  bbGCVar<t_mx2_Expr> m_varExpr{};
  bbString m_kind{};
  bbGCVar<t_mx2_Expr> m_init{};
  bbGCVar<t_mx2_Expr> m_cond{};
  bbGCVar<t_mx2_Expr> m_incr{};
  bbGCVar<bbArray<bbGCVar<t_mx2_StmtExpr>>> m_stmts{};

  void gcMark();

  t_mx2_ForStmtExpr(bbString l_varIdent,t_mx2_TypeExpr* l_varType,t_mx2_Expr* l_varExpr,bbString l_kind,t_mx2_Expr* l_init,t_mx2_Expr* l_cond,t_mx2_Expr* l_incr,bbArray<bbGCVar<t_mx2_StmtExpr>>* l_stmts,bbInt l_srcpos,bbInt l_endpos);

  bbString m_ToString();
  t_mx2_Stmt* m_SemantEachin(t_mx2_Block* l_block);
  t_mx2_Stmt* m_OnSemant(t_mx2_Block* l_block);
  void m_Emit(t_std_collections_Stack_1s* l_buf,bbString l_spc);

  t_mx2_ForStmtExpr(){
  }
};

struct t_mx2_CatchExpr : public bbObject{

  const char *typeName()const{return "t_mx2_CatchExpr";}

  bbString m_varIdent{};
  bbGCVar<t_mx2_TypeExpr> m_varType{};
  bbGCVar<bbArray<bbGCVar<t_mx2_StmtExpr>>> m_stmts{};

  void gcMark();

  t_mx2_CatchExpr(bbString l_varIdent,t_mx2_TypeExpr* l_varType,bbArray<bbGCVar<t_mx2_StmtExpr>>* l_stmts);

  t_mx2_CatchExpr(){
  }
};

struct t_mx2_TryStmtExpr : public t_mx2_StmtExpr{

  const char *typeName()const{return "t_mx2_TryStmtExpr";}

  bbGCVar<bbArray<bbGCVar<t_mx2_StmtExpr>>> m_stmts{};
  bbGCVar<bbArray<bbGCVar<t_mx2_CatchExpr>>> m_catches{};

  void gcMark();

  t_mx2_TryStmtExpr(bbArray<bbGCVar<t_mx2_StmtExpr>>* l_stmts,bbArray<bbGCVar<t_mx2_CatchExpr>>* l_catches,bbInt l_srcpos,bbInt l_endpos);

  t_mx2_Stmt* m_OnSemant(t_mx2_Block* l_block);

  t_mx2_TryStmtExpr(){
  }
};

struct t_mx2_ThrowStmtExpr : public t_mx2_StmtExpr{

  const char *typeName()const{return "t_mx2_ThrowStmtExpr";}

  bbGCVar<t_mx2_Expr> m_expr{};

  void gcMark();

  t_mx2_ThrowStmtExpr(t_mx2_Expr* l_expr,bbInt l_srcpos,bbInt l_endpos);

  t_mx2_Stmt* m_OnSemant(t_mx2_Block* l_block);

  t_mx2_ThrowStmtExpr(){
  }
};

#endif
