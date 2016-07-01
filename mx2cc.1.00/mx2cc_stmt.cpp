
#include "mx2cc_stmt.h"

// ***** External *****

#include "mx2cc_node.h"
#include "mx2cc_scope.h"
#include "mx2cc_std_collections_2stack.h"
#include "mx2cc_value.h"
#include "mx2cc_var.h"

// ***** Internal *****

void t_mx2_StmtVisitor::m_Visit(t_mx2_TryStmt* l_stmt){
  {
    bbInt l_0=bbInt(0);
    bbInt l_1=l_stmt->m_catches->length();
    for(;(l_0<l_1);l_0+=1){
      struct f2_t : public bbGCFrame{
        t_mx2_CatchStmt* l_cstmt{};
        void gcMark(){
          bbGCMarkPtr(l_cstmt);
        }
      }f2{};
      f2.l_cstmt=l_stmt->m_catches->at(l_0);
      this->m_Visit(f2.l_cstmt->m_block);
    }
  }
}

void t_mx2_StmtVisitor::m_Visit(t_mx2_ForStmt* l_stmt){
  this->m_Visit(l_stmt->m_iblock);
  this->m_Visit(l_stmt->m_block);
}

void t_mx2_StmtVisitor::m_Visit(t_mx2_SelectStmt* l_stmt){
  {
    bbInt l_0=bbInt(0);
    bbInt l_1=l_stmt->m_cases->length();
    for(;(l_0<l_1);l_0+=1){
      struct f2_t : public bbGCFrame{
        t_mx2_CaseStmt* l_cstmt{};
        void gcMark(){
          bbGCMarkPtr(l_cstmt);
        }
      }f2{};
      f2.l_cstmt=l_stmt->m_cases->at(l_0);
      this->m_Visit(f2.l_cstmt->m_block);
    }
  }
}

void t_mx2_StmtVisitor::m_Visit(t_mx2_RepeatStmt* l_stmt){
  this->m_Visit(l_stmt->m_block);
}

void t_mx2_StmtVisitor::m_Visit(t_mx2_WhileStmt* l_stmt){
  this->m_Visit(l_stmt->m_block);
}

void t_mx2_StmtVisitor::m_Visit(t_mx2_IfStmt* l_stmt){
  struct f0_t : public bbGCFrame{
    t_mx2_IfStmt* l_stmt{};
    f0_t(t_mx2_IfStmt* l_stmt):l_stmt(l_stmt){
    }
    void gcMark(){
      bbGCMarkPtr(l_stmt);
    }
  }f0{l_stmt};
  while(bbBool(f0.l_stmt)){
    this->m_Visit(f0.l_stmt->m_block);
    f0.l_stmt=f0.l_stmt->m_succ;
  }
}

void t_mx2_StmtVisitor::m_Visit(t_mx2_ContinueStmt* l_stmt){
}

void t_mx2_StmtVisitor::m_Visit(t_mx2_ExitStmt* l_stmt){
}

void t_mx2_StmtVisitor::m_Visit(t_mx2_ThrowStmt* l_stmt){
}

void t_mx2_StmtVisitor::m_Visit(t_mx2_EvalStmt* l_stmt){
}

void t_mx2_StmtVisitor::m_Visit(t_mx2_AssignStmt* l_stmt){
}

void t_mx2_StmtVisitor::m_Visit(t_mx2_VarDeclStmt* l_stmt){
}

void t_mx2_StmtVisitor::m_Visit(t_mx2_ReturnStmt* l_stmt){
}

void t_mx2_StmtVisitor::m_Visit(t_mx2_PrintStmt* l_stmt){
}

void t_mx2_StmtVisitor::m_Visit(t_mx2_Stmt* l_stmt){
  struct f0_t : public bbGCFrame{
    t_mx2_AssignStmt* l_assignStmt{};
    t_mx2_ContinueStmt* l_continueStmt{};
    t_mx2_EvalStmt* l_evalStmt{};
    t_mx2_ExitStmt* l_exitStmt{};
    t_mx2_ForStmt* l_forStmt{};
    t_mx2_IfStmt* l_ifStmt{};
    t_mx2_PrintStmt* l_printStmt{};
    t_mx2_RepeatStmt* l_repeatStmt{};
    t_mx2_ReturnStmt* l_returnStmt{};
    t_mx2_SelectStmt* l_selectStmt{};
    t_mx2_ThrowStmt* l_throwStmt{};
    t_mx2_TryStmt* l_tryStmt{};
    t_mx2_VarDeclStmt* l_varDeclStmt{};
    t_mx2_WhileStmt* l_whileStmt{};
    void gcMark(){
      bbGCMarkPtr(l_assignStmt);
      bbGCMarkPtr(l_continueStmt);
      bbGCMarkPtr(l_evalStmt);
      bbGCMarkPtr(l_exitStmt);
      bbGCMarkPtr(l_forStmt);
      bbGCMarkPtr(l_ifStmt);
      bbGCMarkPtr(l_printStmt);
      bbGCMarkPtr(l_repeatStmt);
      bbGCMarkPtr(l_returnStmt);
      bbGCMarkPtr(l_selectStmt);
      bbGCMarkPtr(l_throwStmt);
      bbGCMarkPtr(l_tryStmt);
      bbGCMarkPtr(l_varDeclStmt);
      bbGCMarkPtr(l_whileStmt);
    }
  }f0{};
  f0.l_printStmt=bb_object_cast<t_mx2_PrintStmt*>(l_stmt);
  if(bbBool(f0.l_printStmt)){
    this->m_Visit(f0.l_printStmt);
    return;
  }
  f0.l_returnStmt=bb_object_cast<t_mx2_ReturnStmt*>(l_stmt);
  if(bbBool(f0.l_returnStmt)){
    this->m_Visit(f0.l_returnStmt);
    return;
  }
  f0.l_varDeclStmt=bb_object_cast<t_mx2_VarDeclStmt*>(l_stmt);
  if(bbBool(f0.l_varDeclStmt)){
    this->m_Visit(f0.l_varDeclStmt);
    return;
  }
  f0.l_assignStmt=bb_object_cast<t_mx2_AssignStmt*>(l_stmt);
  if(bbBool(f0.l_assignStmt)){
    this->m_Visit(f0.l_assignStmt);
    return;
  }
  f0.l_evalStmt=bb_object_cast<t_mx2_EvalStmt*>(l_stmt);
  if(bbBool(f0.l_evalStmt)){
    this->m_Visit(f0.l_evalStmt);
    return;
  }
  f0.l_exitStmt=bb_object_cast<t_mx2_ExitStmt*>(l_stmt);
  if(bbBool(f0.l_exitStmt)){
    this->m_Visit(f0.l_exitStmt);
    return;
  }
  f0.l_continueStmt=bb_object_cast<t_mx2_ContinueStmt*>(l_stmt);
  if(bbBool(f0.l_continueStmt)){
    this->m_Visit(f0.l_continueStmt);
    return;
  }
  f0.l_throwStmt=bb_object_cast<t_mx2_ThrowStmt*>(l_stmt);
  if(bbBool(f0.l_throwStmt)){
    this->m_Visit(f0.l_throwStmt);
    return;
  }
  f0.l_ifStmt=bb_object_cast<t_mx2_IfStmt*>(l_stmt);
  if(bbBool(f0.l_ifStmt)){
    this->m_Visit(f0.l_ifStmt);
    return;
  }
  f0.l_whileStmt=bb_object_cast<t_mx2_WhileStmt*>(l_stmt);
  if(bbBool(f0.l_whileStmt)){
    this->m_Visit(f0.l_whileStmt);
    return;
  }
  f0.l_repeatStmt=bb_object_cast<t_mx2_RepeatStmt*>(l_stmt);
  if(bbBool(f0.l_repeatStmt)){
    this->m_Visit(f0.l_repeatStmt);
    return;
  }
  f0.l_selectStmt=bb_object_cast<t_mx2_SelectStmt*>(l_stmt);
  if(bbBool(f0.l_selectStmt)){
    this->m_Visit(f0.l_selectStmt);
    return;
  }
  f0.l_forStmt=bb_object_cast<t_mx2_ForStmt*>(l_stmt);
  if(bbBool(f0.l_forStmt)){
    this->m_Visit(f0.l_forStmt);
    return;
  }
  f0.l_tryStmt=bb_object_cast<t_mx2_TryStmt*>(l_stmt);
  if(bbBool(f0.l_tryStmt)){
    this->m_Visit(f0.l_tryStmt);
    return;
  }
  puts(BB_T("????? StmtVisitor.VisitStmt() ?????").c_str());fflush( stdout );
}

void t_mx2_StmtVisitor::m_Visit(t_mx2_Block* l_block){
  {
    struct f1_t : public bbGCFrame{
      t_std_collections_Stack_1Tt_mx2_Stmt_2_Iterator l_0{};
      void gcMark(){
        bbGCMark(l_0);
      }
    }f1{};
    f1.l_0=l_block->m_stmts->m_All();
    for(;!f1.l_0.m_AtEnd();f1.l_0.m_Bump()){
      struct f2_t : public bbGCFrame{
        t_mx2_Stmt* l_stmt{};
        void gcMark(){
          bbGCMarkPtr(l_stmt);
        }
      }f2{};
      f2.l_stmt=f1.l_0.m_Current();
      this->m_Visit(f2.l_stmt);
    }
  }
}

void t_mx2_Stmt::gcMark(){
  bbGCMark(m_pnode);
}

t_mx2_Stmt::t_mx2_Stmt(t_mx2_PNode* l_pnode){
  this->m_pnode=l_pnode;
}

t_mx2_Stmt::t_mx2_Stmt(){
}

void t_mx2_PrintStmt::gcMark(){
  t_mx2_Stmt::gcMark();
  bbGCMark(m_value);
}

t_mx2_PrintStmt::t_mx2_PrintStmt(t_mx2_PNode* l_pnode,t_mx2_Value* l_value):t_mx2_Stmt(l_pnode){
  this->m_value=l_value;
}

void t_mx2_ReturnStmt::gcMark(){
  t_mx2_Stmt::gcMark();
  bbGCMark(m_value);
}

t_mx2_ReturnStmt::t_mx2_ReturnStmt(t_mx2_PNode* l_pnode,t_mx2_Value* l_value):t_mx2_Stmt(l_pnode){
  this->m_value=l_value;
}

void t_mx2_VarDeclStmt::gcMark(){
  t_mx2_Stmt::gcMark();
  bbGCMark(m_varValue);
}

t_mx2_VarDeclStmt::t_mx2_VarDeclStmt(t_mx2_PNode* l_pnode,t_mx2_VarValue* l_varValue):t_mx2_Stmt(l_pnode){
  this->m_varValue=l_varValue;
}

void t_mx2_AssignStmt::gcMark(){
  t_mx2_Stmt::gcMark();
  bbGCMark(m_lhs);
  bbGCMark(m_rhs);
}

t_mx2_AssignStmt::t_mx2_AssignStmt(t_mx2_PNode* l_pnode,bbString l_op,t_mx2_Value* l_lhs,t_mx2_Value* l_rhs):t_mx2_Stmt(l_pnode){
  this->m_op=l_op;
  this->m_lhs=l_lhs;
  this->m_rhs=l_rhs;
}

void t_mx2_EvalStmt::gcMark(){
  t_mx2_Stmt::gcMark();
  bbGCMark(m_value);
}

t_mx2_EvalStmt::t_mx2_EvalStmt(t_mx2_PNode* l_pnode,t_mx2_Value* l_value):t_mx2_Stmt(l_pnode){
  this->m_value=l_value;
}

void t_mx2_IfStmt::gcMark(){
  t_mx2_Stmt::gcMark();
  bbGCMark(m_cond);
  bbGCMark(m_block);
  bbGCMark(m_succ);
}

t_mx2_IfStmt::t_mx2_IfStmt(t_mx2_PNode* l_pnode,t_mx2_Value* l_cond,t_mx2_Block* l_block):t_mx2_Stmt(l_pnode){
  this->m_cond=l_cond;
  this->m_block=l_block;
}

void t_mx2_WhileStmt::gcMark(){
  t_mx2_Stmt::gcMark();
  bbGCMark(m_cond);
  bbGCMark(m_block);
}

t_mx2_WhileStmt::t_mx2_WhileStmt(t_mx2_PNode* l_pnode,t_mx2_Value* l_cond,t_mx2_Block* l_block):t_mx2_Stmt(l_pnode){
  this->m_cond=l_cond;
  this->m_block=l_block;
}

void t_mx2_RepeatStmt::gcMark(){
  t_mx2_Stmt::gcMark();
  bbGCMark(m_cond);
  bbGCMark(m_block);
}

t_mx2_RepeatStmt::t_mx2_RepeatStmt(t_mx2_PNode* l_pnode,t_mx2_Value* l_cond,t_mx2_Block* l_block):t_mx2_Stmt(l_pnode){
  this->m_cond=l_cond;
  this->m_block=l_block;
}

void t_mx2_CaseStmt::gcMark(){
  t_mx2_Stmt::gcMark();
  bbGCMark(m_values);
  bbGCMark(m_block);
}

t_mx2_CaseStmt::t_mx2_CaseStmt(bbArray<bbGCVar<t_mx2_Value>>* l_values,t_mx2_Block* l_block){
  this->m_values=l_values;
  this->m_block=l_block;
}

void t_mx2_SelectStmt::gcMark(){
  t_mx2_Stmt::gcMark();
  bbGCMark(m_value);
  bbGCMark(m_cases);
}

t_mx2_SelectStmt::t_mx2_SelectStmt(t_mx2_PNode* l_pnode,t_mx2_Value* l_value,bbArray<bbGCVar<t_mx2_CaseStmt>>* l_cases):t_mx2_Stmt(l_pnode){
  this->m_value=l_value;
  this->m_cases=l_cases;
}

void t_mx2_ForStmt::gcMark(){
  t_mx2_Stmt::gcMark();
  bbGCMark(m_iblock);
  bbGCMark(m_cond);
  bbGCMark(m_incr);
  bbGCMark(m_block);
}

t_mx2_ForStmt::t_mx2_ForStmt(t_mx2_PNode* l_pnode,t_mx2_Block* l_iblock,t_mx2_Value* l_cond,t_mx2_Stmt* l_incr,t_mx2_Block* l_block):t_mx2_Stmt(l_pnode){
  this->m_iblock=l_iblock;
  this->m_cond=l_cond;
  this->m_incr=l_incr;
  this->m_block=l_block;
}

void t_mx2_CatchStmt::gcMark(){
  bbGCMark(m_vvar);
  bbGCMark(m_block);
}

t_mx2_CatchStmt::t_mx2_CatchStmt(t_mx2_VarValue* l_vvar,t_mx2_Block* l_block){
  this->m_vvar=l_vvar;
  this->m_block=l_block;
}

void t_mx2_TryStmt::gcMark(){
  t_mx2_Stmt::gcMark();
  bbGCMark(m_block);
  bbGCMark(m_catches);
}

t_mx2_TryStmt::t_mx2_TryStmt(t_mx2_PNode* l_pnode,t_mx2_Block* l_block,bbArray<bbGCVar<t_mx2_CatchStmt>>* l_catches):t_mx2_Stmt(l_pnode){
  this->m_block=l_block;
  this->m_catches=l_catches;
}

void t_mx2_ThrowStmt::gcMark(){
  t_mx2_Stmt::gcMark();
  bbGCMark(m_value);
}

t_mx2_ThrowStmt::t_mx2_ThrowStmt(t_mx2_PNode* l_pnode,t_mx2_Value* l_value):t_mx2_Stmt(l_pnode){
  this->m_value=l_value;
}

t_mx2_ContinueStmt::t_mx2_ContinueStmt(t_mx2_PNode* l_pnode):t_mx2_Stmt(l_pnode){
}

t_mx2_ExitStmt::t_mx2_ExitStmt(t_mx2_PNode* l_pnode):t_mx2_Stmt(l_pnode){
}

void mx2_mx2cc_stmt_init(){
  static bool done;
  if(done) return;
  done=true;
}

bbInit mx2_mx2cc_stmt_init_v("mx2cc_stmt",&mx2_mx2cc_stmt_init);
