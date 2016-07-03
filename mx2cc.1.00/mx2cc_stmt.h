
#ifndef MX2_MX2CC_STMT_H
#define MX2_MX2CC_STMT_H

#include <bbmonkey.h>

// ***** External *****

#include "../../../../../modules/monkey/monkey.buildv1.0.0/desktop_release_linux/monkey_types.h"

struct t_mx2_Block;
struct t_mx2_PNode;
struct t_mx2_Value;
struct t_mx2_VarValue;

// ***** Internal *****

struct t_mx2_StmtVisitor;
struct t_mx2_Stmt;
struct t_mx2_PrintStmt;
struct t_mx2_ReturnStmt;
struct t_mx2_VarDeclStmt;
struct t_mx2_AssignStmt;
struct t_mx2_EvalStmt;
struct t_mx2_IfStmt;
struct t_mx2_WhileStmt;
struct t_mx2_RepeatStmt;
struct t_mx2_CaseStmt;
struct t_mx2_SelectStmt;
struct t_mx2_ForStmt;
struct t_mx2_CatchStmt;
struct t_mx2_TryStmt;
struct t_mx2_ThrowStmt;
struct t_mx2_ContinueStmt;
struct t_mx2_ExitStmt;

struct t_mx2_StmtVisitor : public bbObject{

  const char *typeName()const{return "t_mx2_StmtVisitor";}

  virtual void m_Visit(t_mx2_TryStmt* l_stmt);
  virtual void m_Visit(t_mx2_ForStmt* l_stmt);
  virtual void m_Visit(t_mx2_SelectStmt* l_stmt);
  virtual void m_Visit(t_mx2_RepeatStmt* l_stmt);
  virtual void m_Visit(t_mx2_WhileStmt* l_stmt);
  virtual void m_Visit(t_mx2_IfStmt* l_stmt);
  virtual void m_Visit(t_mx2_ContinueStmt* l_stmt);
  virtual void m_Visit(t_mx2_ExitStmt* l_stmt);
  virtual void m_Visit(t_mx2_ThrowStmt* l_stmt);
  virtual void m_Visit(t_mx2_EvalStmt* l_stmt);
  virtual void m_Visit(t_mx2_AssignStmt* l_stmt);
  virtual void m_Visit(t_mx2_VarDeclStmt* l_stmt);
  virtual void m_Visit(t_mx2_ReturnStmt* l_stmt);
  virtual void m_Visit(t_mx2_PrintStmt* l_stmt);
  virtual void m_Visit(t_mx2_Stmt* l_stmt);
  void m_Visit(t_mx2_Block* l_block);

  t_mx2_StmtVisitor(){
  }
};

struct t_mx2_Stmt : public bbObject{

  const char *typeName()const{return "t_mx2_Stmt";}

  bbGCVar<t_mx2_PNode> m_pnode{};

  void gcMark();

  t_mx2_Stmt(t_mx2_PNode* l_pnode);
  t_mx2_Stmt();

};

struct t_mx2_PrintStmt : public t_mx2_Stmt{

  const char *typeName()const{return "t_mx2_PrintStmt";}

  bbGCVar<t_mx2_Value> m_value{};

  void gcMark();

  t_mx2_PrintStmt(t_mx2_PNode* l_pnode,t_mx2_Value* l_value);

  t_mx2_PrintStmt(){
  }
};

struct t_mx2_ReturnStmt : public t_mx2_Stmt{

  const char *typeName()const{return "t_mx2_ReturnStmt";}

  bbGCVar<t_mx2_Value> m_value{};

  void gcMark();

  t_mx2_ReturnStmt(t_mx2_PNode* l_pnode,t_mx2_Value* l_value);

  t_mx2_ReturnStmt(){
  }
};

struct t_mx2_VarDeclStmt : public t_mx2_Stmt{

  const char *typeName()const{return "t_mx2_VarDeclStmt";}

  bbGCVar<t_mx2_VarValue> m_varValue{};

  void gcMark();

  t_mx2_VarDeclStmt(t_mx2_PNode* l_pnode,t_mx2_VarValue* l_varValue);

  t_mx2_VarDeclStmt(){
  }
};

struct t_mx2_AssignStmt : public t_mx2_Stmt{

  const char *typeName()const{return "t_mx2_AssignStmt";}

  bbString m_op{};
  bbGCVar<t_mx2_Value> m_lhs{};
  bbGCVar<t_mx2_Value> m_rhs{};

  void gcMark();

  t_mx2_AssignStmt(t_mx2_PNode* l_pnode,bbString l_op,t_mx2_Value* l_lhs,t_mx2_Value* l_rhs);

  t_mx2_AssignStmt(){
  }
};

struct t_mx2_EvalStmt : public t_mx2_Stmt{

  const char *typeName()const{return "t_mx2_EvalStmt";}

  bbGCVar<t_mx2_Value> m_value{};

  void gcMark();

  t_mx2_EvalStmt(t_mx2_PNode* l_pnode,t_mx2_Value* l_value);

  t_mx2_EvalStmt(){
  }
};

struct t_mx2_IfStmt : public t_mx2_Stmt{

  const char *typeName()const{return "t_mx2_IfStmt";}

  bbGCVar<t_mx2_Value> m_cond{};
  bbGCVar<t_mx2_Block> m_block{};
  bbGCVar<t_mx2_IfStmt> m_succ{};

  void gcMark();

  t_mx2_IfStmt(t_mx2_PNode* l_pnode,t_mx2_Value* l_cond,t_mx2_Block* l_block);

  t_mx2_IfStmt(){
  }
};

struct t_mx2_WhileStmt : public t_mx2_Stmt{

  const char *typeName()const{return "t_mx2_WhileStmt";}

  bbGCVar<t_mx2_Value> m_cond{};
  bbGCVar<t_mx2_Block> m_block{};

  void gcMark();

  t_mx2_WhileStmt(t_mx2_PNode* l_pnode,t_mx2_Value* l_cond,t_mx2_Block* l_block);

  t_mx2_WhileStmt(){
  }
};

struct t_mx2_RepeatStmt : public t_mx2_Stmt{

  const char *typeName()const{return "t_mx2_RepeatStmt";}

  bbGCVar<t_mx2_Value> m_cond{};
  bbGCVar<t_mx2_Block> m_block{};

  void gcMark();

  t_mx2_RepeatStmt(t_mx2_PNode* l_pnode,t_mx2_Value* l_cond,t_mx2_Block* l_block);

  t_mx2_RepeatStmt(){
  }
};

struct t_mx2_CaseStmt : public t_mx2_Stmt{

  const char *typeName()const{return "t_mx2_CaseStmt";}

  bbGCVar<bbArray<bbGCVar<t_mx2_Value>>> m_values{};
  bbGCVar<t_mx2_Block> m_block{};

  void gcMark();

  t_mx2_CaseStmt(bbArray<bbGCVar<t_mx2_Value>>* l_values,t_mx2_Block* l_block);

  t_mx2_CaseStmt(){
  }
};

struct t_mx2_SelectStmt : public t_mx2_Stmt{

  const char *typeName()const{return "t_mx2_SelectStmt";}

  bbGCVar<t_mx2_Value> m_value{};
  bbGCVar<bbArray<bbGCVar<t_mx2_CaseStmt>>> m_cases{};

  void gcMark();

  t_mx2_SelectStmt(t_mx2_PNode* l_pnode,t_mx2_Value* l_value,bbArray<bbGCVar<t_mx2_CaseStmt>>* l_cases);

  t_mx2_SelectStmt(){
  }
};

struct t_mx2_ForStmt : public t_mx2_Stmt{

  const char *typeName()const{return "t_mx2_ForStmt";}

  bbGCVar<t_mx2_Block> m_iblock{};
  bbGCVar<t_mx2_Value> m_cond{};
  bbGCVar<t_mx2_Stmt> m_incr{};
  bbGCVar<t_mx2_Block> m_block{};

  void gcMark();

  t_mx2_ForStmt(t_mx2_PNode* l_pnode,t_mx2_Block* l_iblock,t_mx2_Value* l_cond,t_mx2_Stmt* l_incr,t_mx2_Block* l_block);

  t_mx2_ForStmt(){
  }
};

struct t_mx2_CatchStmt : public bbObject{

  const char *typeName()const{return "t_mx2_CatchStmt";}

  bbGCVar<t_mx2_VarValue> m_vvar{};
  bbGCVar<t_mx2_Block> m_block{};

  void gcMark();

  t_mx2_CatchStmt(t_mx2_VarValue* l_vvar,t_mx2_Block* l_block);

  t_mx2_CatchStmt(){
  }
};

struct t_mx2_TryStmt : public t_mx2_Stmt{

  const char *typeName()const{return "t_mx2_TryStmt";}

  bbGCVar<t_mx2_Block> m_block{};
  bbGCVar<bbArray<bbGCVar<t_mx2_CatchStmt>>> m_catches{};

  void gcMark();

  t_mx2_TryStmt(t_mx2_PNode* l_pnode,t_mx2_Block* l_block,bbArray<bbGCVar<t_mx2_CatchStmt>>* l_catches);

  t_mx2_TryStmt(){
  }
};

struct t_mx2_ThrowStmt : public t_mx2_Stmt{

  const char *typeName()const{return "t_mx2_ThrowStmt";}

  bbGCVar<t_mx2_Value> m_value{};

  void gcMark();

  t_mx2_ThrowStmt(t_mx2_PNode* l_pnode,t_mx2_Value* l_value);

  t_mx2_ThrowStmt(){
  }
};

struct t_mx2_ContinueStmt : public t_mx2_Stmt{

  const char *typeName()const{return "t_mx2_ContinueStmt";}

  t_mx2_ContinueStmt(t_mx2_PNode* l_pnode);

  t_mx2_ContinueStmt(){
  }
};

struct t_mx2_ExitStmt : public t_mx2_Stmt{

  const char *typeName()const{return "t_mx2_ExitStmt";}

  t_mx2_ExitStmt(t_mx2_PNode* l_pnode);

  t_mx2_ExitStmt(){
  }
};

#endif
