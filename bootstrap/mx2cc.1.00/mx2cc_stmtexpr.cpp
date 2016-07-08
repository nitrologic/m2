
#include "mx2cc_stmtexpr.h"

// ***** External *****

#include "mx2cc_class.h"
#include "mx2cc_decl.h"
#include "mx2cc_errors.h"
#include "mx2cc_expr.h"
#include "mx2cc_func.h"
#include "mx2cc_scope.h"
#include "mx2cc_std_collections_2stack.h"
#include "mx2cc_stmt.h"
#include "mx2cc_type.h"
#include "mx2cc_typeexpr.h"
#include "mx2cc_value.h"
#include "mx2cc_var.h"
#include "../../../../../modules/std/std.buildv1.0.0/desktop_release_linux/std_collections_2stack.h"

extern bbInt g_mx2_TOKE_0INTLIT;

extern bbArray<bbGCVar<t_mx2_Value>>* g_mx2_SemantArgs(bbArray<bbGCVar<t_mx2_Expr>>* l_exprs,t_mx2_Scope* l_scope);
extern bbString g_mx2_Join_1Tt_mx2_Value_2(bbArray<bbGCVar<t_mx2_Value>>* l_bits,bbString l_sep);
extern bbString g_mx2_Join_1Tt_mx2_Expr_2(bbArray<bbGCVar<t_mx2_Expr>>* l_bits,bbString l_sep);

// ***** Internal *****

bbString g_mx2_StmtsToString(bbArray<bbGCVar<t_mx2_StmtExpr>>* l_stmts){
  struct f0_t : public bbGCFrame{
    t_std_collections_Stack_1s* l_buf{};
    void gcMark(){
      bbGCMarkPtr(l_buf);
    }
  }f0{};
  f0.l_buf=bbGCNew<t_std_collections_Stack_1s>();
  {
    bbInt l_0=bbInt(0);
    bbInt l_1=l_stmts->length();
    for(;(l_0<l_1);l_0+=1){
      struct f2_t : public bbGCFrame{
        t_mx2_StmtExpr* l_stmt{};
        void gcMark(){
          bbGCMarkPtr(l_stmt);
        }
      }f2{};
      f2.l_stmt=l_stmts->at(l_0);
      f0.l_buf->m_Push(f2.l_stmt->m_ToString());
    }
  }
  return f0.l_buf->m_Join(BB_T("\n"));
}

void g_mx2_EmitStmts(bbArray<bbGCVar<t_mx2_StmtExpr>>* l_stmts,t_std_collections_Stack_1s* l_buf,bbString l_spc){
  l_spc+=BB_T("  ");
  {
    bbInt l_0=bbInt(0);
    bbInt l_1=l_stmts->length();
    for(;(l_0<l_1);l_0+=1){
      struct f2_t : public bbGCFrame{
        t_mx2_StmtExpr* l_stmt{};
        void gcMark(){
          bbGCMarkPtr(l_stmt);
        }
      }f2{};
      f2.l_stmt=l_stmts->at(l_0);
      f2.l_stmt->m_Emit(l_buf,l_spc);
    }
  }
}

t_mx2_StmtExpr::t_mx2_StmtExpr(bbInt l_srcpos,bbInt l_endpos):t_mx2_PNode(l_srcpos,l_endpos){
}

t_mx2_Stmt* t_mx2_StmtExpr::m_Semant(t_mx2_Block* l_block){
  try{
    struct f1_t : public bbGCFrame{
      t_mx2_Stmt* l_stmt{};
      void gcMark(){
        bbGCMarkPtr(l_stmt);
      }
    }f1{};
    g_mx2_PNode_semanting->m_Push(((t_mx2_PNode*)(this)));
    f1.l_stmt=this->m_OnSemant(l_block);
    g_mx2_PNode_semanting->m_Pop();
    return f1.l_stmt;
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
  return ((t_mx2_Stmt*)0);
}

t_mx2_Stmt* t_mx2_StmtExpr::m_OnSemant(t_mx2_Block* l_block){
  puts(BB_T("????? StmtExpr.OnSemant ?????").c_str());fflush( stdout );
  return ((t_mx2_Stmt*)0);
}

void t_mx2_StmtExpr::m_Emit(t_std_collections_Stack_1s* l_buf,bbString l_spc){
  l_buf->m_Push((l_spc+this->m_ToString()));
}

void t_mx2_AssignStmtExpr::gcMark(){
  t_mx2_StmtExpr::gcMark();
  bbGCMark(m_lhs);
  bbGCMark(m_rhs);
}

t_mx2_AssignStmtExpr::t_mx2_AssignStmtExpr(bbString l_op,t_mx2_Expr* l_lhs,t_mx2_Expr* l_rhs,bbInt l_srcpos,bbInt l_endpos):t_mx2_StmtExpr(l_srcpos,l_endpos){
  this->m_op=l_op;
  this->m_lhs=l_lhs;
  this->m_rhs=l_rhs;
}

bbString t_mx2_AssignStmtExpr::m_ToString(){
  return ((this->m_lhs->m_ToString()+this->m_op)+this->m_rhs->m_ToString());
}

t_mx2_Stmt* t_mx2_AssignStmtExpr::m_OnSemant(t_mx2_Block* l_block){
  struct f0_t : public bbGCFrame{
    t_mx2_Value* l_lhs{};
    t_mx2_Value* l_rhs{};
    void gcMark(){
      bbGCMarkPtr(l_lhs);
      bbGCMarkPtr(l_rhs);
    }
  }f0{};
  bbString l_op=this->m_op;
  f0.l_lhs=this->m_lhs->m_Semant(((t_mx2_Scope*)(l_block)));
  f0.l_rhs=this->m_rhs->m_Semant(((t_mx2_Scope*)(l_block)));
  if(((l_op!=BB_T("="))&&f0.l_lhs->m_IsLValue())){
    struct f1_t : public bbGCFrame{
      t_mx2_Value* l_node{};
      void gcMark(){
        bbGCMarkPtr(l_node);
      }
    }f1{};
    f1.l_node=f0.l_lhs->m_FindValue(l_op);
    if(bbBool(f1.l_node)){
      struct f2_t : public bbGCFrame{
        bbArray<bbGCVar<t_mx2_Value>>* l_args{};
        t_mx2_Value* l_value{};
        void gcMark(){
          bbGCMarkPtr(l_args);
          bbGCMarkPtr(l_value);
        }
      }f2{};
      f2.l_args=bbArray<bbGCVar<t_mx2_Value>>::create(1);
      f2.l_args->at(bbInt(0))=f0.l_rhs;
      f2.l_value=f1.l_node->m_Invoke(f2.l_args);
      return ((t_mx2_Stmt*)(bbGCNew<t_mx2_EvalStmt>(((t_mx2_PNode*)(this)),f2.l_value)));
    }
    f1.l_node=f0.l_lhs->m_FindValue(l_op.slice(bbInt(0),-1));
    if(bbBool(f1.l_node)){
      struct f2_t : public bbGCFrame{
        bbArray<bbGCVar<t_mx2_Value>>* l_args{};
        void gcMark(){
          bbGCMarkPtr(l_args);
        }
      }f2{};
      f2.l_args=bbArray<bbGCVar<t_mx2_Value>>::create(1);
      f2.l_args->at(bbInt(0))=f0.l_rhs;
      f0.l_rhs=f1.l_node->m_Invoke(f2.l_args);
      l_op=BB_T("=");
    }
  }
  if(!f0.l_lhs->m_IsAssignable()){
    throw bbGCNew<t_mx2_SemantEx>(((BB_T("Value '")+f0.l_lhs->m_ToString())+BB_T("' is not assignable")));
  }
  return f0.l_lhs->m_Assign(((t_mx2_PNode*)(this)),l_op,f0.l_rhs,l_block);
}

void t_mx2_VarDeclStmtExpr::gcMark(){
  t_mx2_StmtExpr::gcMark();
  bbGCMark(m_decl);
}

t_mx2_VarDeclStmtExpr::t_mx2_VarDeclStmtExpr(t_mx2_VarDecl* l_decl,bbInt l_srcpos,bbInt l_endpos):t_mx2_StmtExpr(l_srcpos,l_endpos){
  this->m_decl=l_decl;
}

bbString t_mx2_VarDeclStmtExpr::m_ToString(){
  return this->m_decl->m_ToString();
}

t_mx2_Stmt* t_mx2_VarDeclStmtExpr::m_OnSemant(t_mx2_Block* l_block){
  struct f0_t : public bbGCFrame{
    t_mx2_VarValue* l_value{};
    void gcMark(){
      bbGCMarkPtr(l_value);
    }
  }f0{};
  f0.l_value=bbGCNew<t_mx2_VarValue>(this->m_decl,((t_mx2_Scope*)(l_block)));
  f0.l_value->m_Semant();
  l_block->m_Insert(this->m_decl->m_ident,((t_mx2_SNode*)(f0.l_value)));
  return ((t_mx2_Stmt*)(bbGCNew<t_mx2_VarDeclStmt>(((t_mx2_PNode*)(this)),f0.l_value)));
}

void t_mx2_EvalStmtExpr::gcMark(){
  t_mx2_StmtExpr::gcMark();
  bbGCMark(m_expr);
}

t_mx2_EvalStmtExpr::t_mx2_EvalStmtExpr(t_mx2_Expr* l_expr,bbInt l_srcpos,bbInt l_endpos):t_mx2_StmtExpr(l_srcpos,l_endpos){
  this->m_expr=l_expr;
}

bbString t_mx2_EvalStmtExpr::m_ToString(){
  return this->m_expr->m_ToString();
}

t_mx2_Stmt* t_mx2_EvalStmtExpr::m_OnSemant(t_mx2_Block* l_block){
  struct f0_t : public bbGCFrame{
    t_mx2_Value* l_value{};
    void gcMark(){
      bbGCMarkPtr(l_value);
    }
  }f0{};
  f0.l_value=this->m_expr->m_SemantRValue(((t_mx2_Scope*)(l_block)),((t_mx2_Type*)0));
  if(!f0.l_value->m_HasSideEffects()){
    throw bbGCNew<t_mx2_SemantEx>(BB_T("Statement has no effect"));
  }
  return ((t_mx2_Stmt*)(bbGCNew<t_mx2_EvalStmt>(((t_mx2_PNode*)(this)),f0.l_value)));
}

void t_mx2_InvokeNewStmtExpr::gcMark(){
  t_mx2_StmtExpr::gcMark();
  bbGCMark(m_expr);
  bbGCMark(m_args);
}

t_mx2_InvokeNewStmtExpr::t_mx2_InvokeNewStmtExpr(t_mx2_Expr* l_expr,bbArray<bbGCVar<t_mx2_Expr>>* l_args,bbInt l_srcpos,bbInt l_endpos):t_mx2_StmtExpr(l_srcpos,l_endpos){
  this->m_expr=l_expr;
  this->m_args=l_args;
}

t_mx2_Stmt* t_mx2_InvokeNewStmtExpr::m_OnSemant(t_mx2_Block* l_block){
  struct f0_t : public bbGCFrame{
    t_mx2_ClassType* l_ctype{};
    t_mx2_FuncValue* l_func{};
    t_mx2_Value* l_value{};
    void gcMark(){
      bbGCMarkPtr(l_ctype);
      bbGCMarkPtr(l_func);
      bbGCMarkPtr(l_value);
    }
  }f0{};
  f0.l_value=this->m_expr->m_SemantRValue(((t_mx2_Scope*)(l_block)),((t_mx2_Type*)0));
  if((!bbBool(bb_object_cast<t_mx2_SelfValue*>(f0.l_value))&&!bbBool(bb_object_cast<t_mx2_SuperValue*>(f0.l_value)))){
    throw bbGCNew<t_mx2_SemantEx>(BB_T("'New' cannot be directly invoked"));
  }
  f0.l_ctype=g_mx2_TCast_1Tt_mx2_ClassType_2(f0.l_value->m_type);
  f0.l_func=l_block->m_func;
  try{
    struct f1_t : public bbGCFrame{
      bbArray<bbGCVar<t_mx2_Value>>* l_args{};
      t_mx2_SNode* l_ctor{};
      t_mx2_InvokeValue* l_invoke{};
      t_mx2_InvokeNewValue* l_ivalue{};
      t_mx2_Value* t0{};
      void gcMark(){
        bbGCMarkPtr(l_args);
        bbGCMarkPtr(l_ctor);
        bbGCMarkPtr(l_invoke);
        bbGCMarkPtr(l_ivalue);
        bbGCMarkPtr(t0);
      }
    }f1{};
    if(((((l_block!=f0.l_func->m_block)||bbBool(l_block->m_stmts->m_Length()))||(f0.l_func->m_fdecl->m_ident!=BB_T("new")))||bbBool(f0.l_func->m_invokeNew))){
      throw bbGCNew<t_mx2_SemantEx>(BB_T("Call to 'Self.New' or 'Super.New' must be the first statement of a constructor"));
    }
    f1.l_args=g_mx2_SemantArgs(this->m_args,((t_mx2_Scope*)(l_block)));
    f1.l_ctor=f0.l_ctype->m_FindNode(BB_T("new"));
    if(!bbBool(f1.l_ctor)){
      throw bbGCNew<t_mx2_SemantEx>(((BB_T("Class '")+f0.l_ctype->m_ToString())+BB_T("' has no constructors")));
    }
    f1.l_invoke=bb_object_cast<t_mx2_InvokeValue*>((f1.t0=f1.l_ctor->m_ToValue(((t_mx2_Value*)0)))->m_Invoke(f1.l_args));
    if(!bbBool(f1.l_invoke)){
      throw bbGCNew<t_mx2_SemantEx>(((((BB_T("Can't invoke '")+f0.l_ctype->m_ToString())+BB_T("' constuctor with arguments '"))+g_mx2_Join_1Tt_mx2_Value_2(f1.l_args,BB_T(",")))+BB_T("'")));
    }
    f1.l_ivalue=bbGCNew<t_mx2_InvokeNewValue>(f0.l_ctype,f1.l_invoke->m_args);
    f0.l_func->m_invokeNew=f1.l_ivalue;
  }catch(t_mx2_SemantEx* ex){
    struct f1_t : public bbGCFrame{
      t_mx2_SemantEx* l_ex{};
      bbArray<bbGCVar<t_mx2_Value>>* l_noargs{};
      void gcMark(){
        bbGCMarkPtr(l_ex);
        bbGCMarkPtr(l_noargs);
      }
    }f1{};
    f1.l_ex=ex;
    if(!bbBool(f0.l_func->m_invokeNew)){
      f0.l_func->m_invokeNew=bbGCNew<t_mx2_InvokeNewValue>(f0.l_ctype,f1.l_noargs);
    }
    throw f1.l_ex;
  }
  return ((t_mx2_Stmt*)0);
}

void t_mx2_PrintStmtExpr::gcMark(){
  t_mx2_StmtExpr::gcMark();
  bbGCMark(m_expr);
}

t_mx2_PrintStmtExpr::t_mx2_PrintStmtExpr(t_mx2_Expr* l_expr,bbInt l_srcpos,bbInt l_endpos):t_mx2_StmtExpr(l_srcpos,l_endpos){
  this->m_expr=l_expr;
}

bbString t_mx2_PrintStmtExpr::m_ToString(){
  return (BB_T("Print ")+this->m_expr->m_ToString());
}

t_mx2_Stmt* t_mx2_PrintStmtExpr::m_OnSemant(t_mx2_Block* l_block){
  struct f0_t : public bbGCFrame{
    t_mx2_Value* l_value{};
    void gcMark(){
      bbGCMarkPtr(l_value);
    }
  }f0{};
  f0.l_value=this->m_expr->m_SemantRValue(((t_mx2_Scope*)(l_block)),((t_mx2_Type*)(g_mx2_Type_StringType)));
  return ((t_mx2_Stmt*)(bbGCNew<t_mx2_PrintStmt>(((t_mx2_PNode*)(this)),f0.l_value)));
}

void t_mx2_ReturnStmtExpr::gcMark(){
  t_mx2_StmtExpr::gcMark();
  bbGCMark(m_expr);
}

t_mx2_ReturnStmtExpr::t_mx2_ReturnStmtExpr(t_mx2_Expr* l_expr,bbInt l_srcpos,bbInt l_endpos):t_mx2_StmtExpr(l_srcpos,l_endpos){
  this->m_expr=l_expr;
}

bbString t_mx2_ReturnStmtExpr::m_ToString(){
  return (BB_T("Return ")+this->m_expr->m_ToString());
}

t_mx2_Stmt* t_mx2_ReturnStmtExpr::m_OnSemant(t_mx2_Block* l_block){
  try{
    struct f1_t : public bbGCFrame{
      t_mx2_Type* l_rtype{};
      t_mx2_Value* l_value{};
      t_mx2_Stmt* t0{};
      void gcMark(){
        bbGCMarkPtr(l_rtype);
        bbGCMarkPtr(l_value);
        bbGCMarkPtr(t0);
      }
    }f1{};
    f1.l_rtype=l_block->m_func->m_ftype->m_retType;
    if(f1.l_rtype->m__eq(((t_mx2_Type*)(g_mx2_Type_VoidType)))){
      if(bbBool(this->m_expr)){
        throw bbGCNew<t_mx2_SemantEx>(BB_T("Return statement cannot return a value"));
      }
    }else{
      if(!bbBool(this->m_expr)){
        throw bbGCNew<t_mx2_SemantEx>(BB_T("Return statement must return a value"));
      }
      f1.l_value=this->m_expr->m_SemantRValue(((t_mx2_Scope*)(l_block)),f1.l_rtype);
    }
    l_block->m_Emit(f1.t0=((t_mx2_Stmt*)(bbGCNew<t_mx2_ReturnStmt>(((t_mx2_PNode*)(this)),f1.l_value))));
    l_block->m_reachable=false;
  }catch(t_mx2_SemantEx* ex){
    struct f1_t : public bbGCFrame{
      t_mx2_SemantEx* l_ex{};
      void gcMark(){
        bbGCMarkPtr(l_ex);
      }
    }f1{};
    f1.l_ex=ex;
  }
  return ((t_mx2_Stmt*)0);
}

t_mx2_ContinueStmtExpr::t_mx2_ContinueStmtExpr(bbInt l_srcpos,bbInt l_endpos):t_mx2_StmtExpr(l_srcpos,l_endpos){
}

bbString t_mx2_ContinueStmtExpr::m_ToString(){
  return BB_T("Continue");
}

t_mx2_Stmt* t_mx2_ContinueStmtExpr::m_OnSemant(t_mx2_Block* l_block){
  if(!l_block->m_loop){
    throw bbGCNew<t_mx2_SemantEx>(BB_T("'Exit' must appear inside a loop"));
  }
  return ((t_mx2_Stmt*)(bbGCNew<t_mx2_ContinueStmt>(((t_mx2_PNode*)(this)))));
}

t_mx2_ExitStmtExpr::t_mx2_ExitStmtExpr(bbInt l_srcpos,bbInt l_endpos):t_mx2_StmtExpr(l_srcpos,l_endpos){
}

bbString t_mx2_ExitStmtExpr::m_ToString(){
  return BB_T("Exit");
}

t_mx2_Stmt* t_mx2_ExitStmtExpr::m_OnSemant(t_mx2_Block* l_block){
  if(!l_block->m_loop){
    throw bbGCNew<t_mx2_SemantEx>(BB_T("'Exit' must appear inside a loop"));
  }
  return ((t_mx2_Stmt*)(bbGCNew<t_mx2_ExitStmt>(((t_mx2_PNode*)(this)))));
}

void t_mx2_IfStmtExpr::gcMark(){
  t_mx2_StmtExpr::gcMark();
  bbGCMark(m_cond);
  bbGCMark(m_stmts);
  bbGCMark(m_succ);
}

t_mx2_IfStmtExpr::t_mx2_IfStmtExpr(t_mx2_Expr* l_cond,bbArray<bbGCVar<t_mx2_StmtExpr>>* l_stmts,t_mx2_IfStmtExpr* l_succ,bbInt l_srcpos,bbInt l_endpos):t_mx2_StmtExpr(l_srcpos,l_endpos){
  this->m_cond=l_cond;
  this->m_stmts=l_stmts;
  this->m_succ=l_succ;
}

bbString t_mx2_IfStmtExpr::m_ToString(){
  return BB_T("if");
}

t_mx2_Stmt* t_mx2_IfStmtExpr::m_OnSemant(t_mx2_Block* l_block){
  struct f0_t : public bbGCFrame{
    t_mx2_IfStmtExpr* l_expr{};
    t_mx2_IfStmt* l_head{};
    t_mx2_IfStmt* l_prev{};
    void gcMark(){
      bbGCMarkPtr(l_expr);
      bbGCMarkPtr(l_head);
      bbGCMarkPtr(l_prev);
    }
  }f0{};
  f0.l_expr=this;
  while(bbBool(f0.l_expr)){
    struct f1_t : public bbGCFrame{
      t_mx2_Value* l_cond{};
      t_mx2_IfStmt* l_curr{};
      t_mx2_Block* l_tblock{};
      void gcMark(){
        bbGCMarkPtr(l_cond);
        bbGCMarkPtr(l_curr);
        bbGCMarkPtr(l_tblock);
      }
    }f1{};
    if(bbBool(f0.l_expr->m_cond)){
      f1.l_cond=f0.l_expr->m_cond->m_TrySemantRValue(((t_mx2_Scope*)(l_block)),((t_mx2_Type*)(g_mx2_Type_BoolType)));
    }
    f1.l_tblock=bbGCNew<t_mx2_Block>(l_block);
    f1.l_tblock->m_Semant(f0.l_expr->m_stmts);
    f1.l_curr=bbGCNew<t_mx2_IfStmt>(((t_mx2_PNode*)(f0.l_expr)),f1.l_cond,f1.l_tblock);
    if(bbBool(f0.l_prev)){
      f0.l_prev->m_succ=f1.l_curr;
    }else{
      f0.l_head=f1.l_curr;
    }
    f0.l_prev=f1.l_curr;
    f0.l_expr=f0.l_expr->m_succ;
  }
  return ((t_mx2_Stmt*)(f0.l_head));
}

void t_mx2_IfStmtExpr::m_Emit(t_std_collections_Stack_1s* l_buf,bbString l_spc){
  struct f0_t : public bbGCFrame{
    t_mx2_IfStmtExpr* l_stmt{};
    void gcMark(){
      bbGCMarkPtr(l_stmt);
    }
  }f0{};
  l_buf->m_Push(((l_spc+BB_T("If "))+this->m_cond->m_ToString()));
  g_mx2_EmitStmts(this->m_stmts,l_buf,l_spc);
  f0.l_stmt=this->m_succ;
  while(bbBool(f0.l_stmt)){
    if(bbBool(f0.l_stmt->m_cond)){
      l_buf->m_Push(((l_spc+BB_T("else If "))+f0.l_stmt->m_cond->m_ToString()));
    }else{
      l_buf->m_Push((l_spc+BB_T("else")));
    }
    g_mx2_EmitStmts(f0.l_stmt->m_stmts,l_buf,l_spc);
    f0.l_stmt=f0.l_stmt->m_succ;
  }
  l_buf->m_Push((l_spc+BB_T("end")));
}

void t_mx2_WhileStmtExpr::gcMark(){
  t_mx2_StmtExpr::gcMark();
  bbGCMark(m_expr);
  bbGCMark(m_stmts);
}

t_mx2_WhileStmtExpr::t_mx2_WhileStmtExpr(t_mx2_Expr* l_expr,bbArray<bbGCVar<t_mx2_StmtExpr>>* l_stmts,bbInt l_srcpos,bbInt l_endpos):t_mx2_StmtExpr(l_srcpos,l_endpos){
  this->m_expr=l_expr;
  this->m_stmts=l_stmts;
}

bbString t_mx2_WhileStmtExpr::m_ToString(){
  return BB_T("while");
}

t_mx2_Stmt* t_mx2_WhileStmtExpr::m_OnSemant(t_mx2_Block* l_block){
  struct f0_t : public bbGCFrame{
    t_mx2_Value* l_cond{};
    t_mx2_Block* l_iblock{};
    void gcMark(){
      bbGCMarkPtr(l_cond);
      bbGCMarkPtr(l_iblock);
    }
  }f0{};
  if(bbBool(this->m_expr)){
    f0.l_cond=this->m_expr->m_TrySemantRValue(((t_mx2_Scope*)(l_block)),((t_mx2_Type*)(g_mx2_Type_BoolType)));
  }
  f0.l_iblock=bbGCNew<t_mx2_Block>(l_block);
  f0.l_iblock->m_loop=true;
  f0.l_iblock->m_Semant(this->m_stmts);
  return ((t_mx2_Stmt*)(bbGCNew<t_mx2_WhileStmt>(((t_mx2_PNode*)(this)),f0.l_cond,f0.l_iblock)));
}

void t_mx2_WhileStmtExpr::m_Emit(t_std_collections_Stack_1s* l_buf,bbString l_spc){
  l_buf->m_Push(((l_spc+BB_T("while "))+this->m_expr->m_ToString()));
  g_mx2_EmitStmts(this->m_stmts,l_buf,l_spc);
  l_buf->m_Push((l_spc+BB_T("wend")));
}

void t_mx2_RepeatStmtExpr::gcMark(){
  t_mx2_StmtExpr::gcMark();
  bbGCMark(m_stmts);
  bbGCMark(m_expr);
}

t_mx2_RepeatStmtExpr::t_mx2_RepeatStmtExpr(bbArray<bbGCVar<t_mx2_StmtExpr>>* l_stmts,t_mx2_Expr* l_expr,bbInt l_srcpos,bbInt l_endpos):t_mx2_StmtExpr(l_srcpos,l_endpos){
  this->m_stmts=l_stmts;
  this->m_expr=l_expr;
}

bbString t_mx2_RepeatStmtExpr::m_ToString(){
  return BB_T("Repeat");
}

t_mx2_Stmt* t_mx2_RepeatStmtExpr::m_OnSemant(t_mx2_Block* l_block){
  struct f0_t : public bbGCFrame{
    t_mx2_Value* l_cond{};
    t_mx2_Block* l_iblock{};
    void gcMark(){
      bbGCMarkPtr(l_cond);
      bbGCMarkPtr(l_iblock);
    }
  }f0{};
  if(bbBool(this->m_expr)){
    f0.l_cond=this->m_expr->m_TrySemantRValue(((t_mx2_Scope*)(l_block)),((t_mx2_Type*)(g_mx2_Type_BoolType)));
  }
  f0.l_iblock=bbGCNew<t_mx2_Block>(l_block);
  f0.l_iblock->m_loop=true;
  f0.l_iblock->m_Semant(this->m_stmts);
  return ((t_mx2_Stmt*)(bbGCNew<t_mx2_RepeatStmt>(((t_mx2_PNode*)(this)),f0.l_cond,f0.l_iblock)));
}

void t_mx2_RepeatStmtExpr::m_Emit(t_std_collections_Stack_1s* l_buf,bbString l_spc){
  l_buf->m_Push((l_spc+BB_T("repeat")));
  g_mx2_EmitStmts(this->m_stmts,l_buf,l_spc);
  if(bbBool(this->m_expr)){
    l_buf->m_Push(((l_spc+BB_T("until "))+this->m_expr->m_ToString()));
  }else{
    l_buf->m_Push((l_spc+BB_T("forever")));
  }
}

void t_mx2_CaseExpr::gcMark(){
  bbGCMark(m_exprs);
  bbGCMark(m_stmts);
}

t_mx2_CaseExpr::t_mx2_CaseExpr(bbArray<bbGCVar<t_mx2_Expr>>* l_exprs,bbArray<bbGCVar<t_mx2_StmtExpr>>* l_stmts){
  this->m_exprs=l_exprs;
  this->m_stmts=l_stmts;
}

void t_mx2_SelectStmtExpr::gcMark(){
  t_mx2_StmtExpr::gcMark();
  bbGCMark(m_expr);
  bbGCMark(m_cases);
}

t_mx2_SelectStmtExpr::t_mx2_SelectStmtExpr(t_mx2_Expr* l_expr,bbArray<bbGCVar<t_mx2_CaseExpr>>* l_cases,bbInt l_srcpos,bbInt l_endpos):t_mx2_StmtExpr(l_srcpos,l_endpos){
  this->m_expr=l_expr;
  this->m_cases=l_cases;
}

bbString t_mx2_SelectStmtExpr::m_ToString(){
  return BB_T("select");
}

t_mx2_Stmt* t_mx2_SelectStmtExpr::m_OnSemant(t_mx2_Block* l_block){
  struct f0_t : public bbGCFrame{
    t_std_collections_Stack_1Tt_mx2_CaseStmt_2* l_cases{};
    t_mx2_Value* l_value{};
    bbArray<bbGCVar<t_mx2_CaseStmt>>* t0{};
    void gcMark(){
      bbGCMarkPtr(l_cases);
      bbGCMarkPtr(l_value);
      bbGCMarkPtr(t0);
    }
  }f0{};
  f0.l_value=this->m_expr->m_SemantRValue(((t_mx2_Scope*)(l_block)),((t_mx2_Type*)0));
  f0.l_value=f0.l_value->m_RemoveSideEffects(l_block);
  f0.l_cases=bbGCNew<t_std_collections_Stack_1Tt_mx2_CaseStmt_2>();
  {
    bbInt l_0=bbInt(0);
    bbInt l_1=this->m_cases->length();
    for(;(l_0<l_1);l_0+=1){
      struct f2_t : public bbGCFrame{
        t_mx2_CaseExpr* l_cexpr{};
        t_mx2_Block* l_iblock{};
        bbArray<bbGCVar<t_mx2_Value>>* l_values{};
        t_mx2_CaseStmt* t0{};
        void gcMark(){
          bbGCMarkPtr(l_cexpr);
          bbGCMarkPtr(l_iblock);
          bbGCMarkPtr(l_values);
          bbGCMarkPtr(t0);
        }
      }f2{};
      f2.l_cexpr=this->m_cases->at(l_0);
      f2.l_values=bbArray<bbGCVar<t_mx2_Value>>::create(f2.l_cexpr->m_exprs->length());
      {
        bbInt l_i=bbInt(0);
        for(;(l_i<f2.l_values->length());l_i+=1){
          f2.l_values->at(l_i)=f2.l_cexpr->m_exprs->at(l_i)->m_SemantRValue(((t_mx2_Scope*)(l_block)),f0.l_value->m_type);
        }
      }
      f2.l_iblock=bbGCNew<t_mx2_Block>(l_block);
      f2.l_iblock->m_Semant(f2.l_cexpr->m_stmts);
      f0.l_cases->m_Push(f2.t0=bbGCNew<t_mx2_CaseStmt>(f2.l_values,f2.l_iblock));
    }
  }
  return ((t_mx2_Stmt*)(bbGCNew<t_mx2_SelectStmt>(((t_mx2_PNode*)(this)),f0.l_value,f0.t0=f0.l_cases->m_ToArray())));
}

void t_mx2_SelectStmtExpr::m_Emit(t_std_collections_Stack_1s* l_buf,bbString l_spc){
  l_buf->m_Push(((l_spc+BB_T("select "))+this->m_expr->m_ToString()));
  {
    bbInt l_0=bbInt(0);
    bbInt l_1=this->m_cases->length();
    for(;(l_0<l_1);l_0+=1){
      struct f2_t : public bbGCFrame{
        t_mx2_CaseExpr* l_c{};
        void gcMark(){
          bbGCMarkPtr(l_c);
        }
      }f2{};
      f2.l_c=this->m_cases->at(l_0);
      l_buf->m_Push((BB_T("case ")+g_mx2_Join_1Tt_mx2_Expr_2(f2.l_c->m_exprs,BB_T(","))));
      g_mx2_EmitStmts(f2.l_c->m_stmts,l_buf,l_spc);
    }
  }
  l_buf->m_Push((l_spc+BB_T("end")));
}

void t_mx2_ForStmtExpr::gcMark(){
  t_mx2_StmtExpr::gcMark();
  bbGCMark(m_varType);
  bbGCMark(m_varExpr);
  bbGCMark(m_init);
  bbGCMark(m_cond);
  bbGCMark(m_incr);
  bbGCMark(m_stmts);
}

t_mx2_ForStmtExpr::t_mx2_ForStmtExpr(bbString l_varIdent,t_mx2_TypeExpr* l_varType,t_mx2_Expr* l_varExpr,bbString l_kind,t_mx2_Expr* l_init,t_mx2_Expr* l_cond,t_mx2_Expr* l_incr,bbArray<bbGCVar<t_mx2_StmtExpr>>* l_stmts,bbInt l_srcpos,bbInt l_endpos):t_mx2_StmtExpr(l_srcpos,l_endpos){
  this->m_varIdent=l_varIdent;
  this->m_varType=l_varType;
  this->m_varExpr=l_varExpr;
  this->m_kind=l_kind;
  this->m_init=l_init;
  this->m_cond=l_cond;
  this->m_incr=l_incr;
  this->m_stmts=l_stmts;
}

bbString t_mx2_ForStmtExpr::m_ToString(){
  return BB_T("for");
}

t_mx2_Stmt* t_mx2_ForStmtExpr::m_SemantEachin(t_mx2_Block* l_block){
  struct f0_t : public bbGCFrame{
    t_mx2_ArrayType* l_atype{};
    t_mx2_Block* l_block{};
    t_mx2_Value* l_cond{};
    t_mx2_Value* l_curr{};
    t_mx2_Block* l_iblock{};
    t_mx2_Stmt* l_incr{};
    t_mx2_Value* l_init{};
    f0_t(t_mx2_Block* l_block):l_block(l_block){
    }
    void gcMark(){
      bbGCMarkPtr(l_atype);
      bbGCMarkPtr(l_block);
      bbGCMarkPtr(l_cond);
      bbGCMarkPtr(l_curr);
      bbGCMarkPtr(l_iblock);
      bbGCMarkPtr(l_incr);
      bbGCMarkPtr(l_init);
    }
  }f0{l_block};
  f0.l_iblock=bbGCNew<t_mx2_Block>(f0.l_block);
  f0.l_block=bbGCNew<t_mx2_Block>(f0.l_iblock);
  f0.l_block->m_loop=true;
  f0.l_init=this->m_init->m_SemantRValue(((t_mx2_Scope*)(f0.l_iblock)),((t_mx2_Type*)0));
  f0.l_atype=g_mx2_TCast_1Tt_mx2_ArrayType_2(f0.l_init->m_type);
  if((bbBool(f0.l_atype)&&(f0.l_atype->m_rank!=1))){
    throw bbGCNew<t_mx2_SemantEx>(BB_T("'Eachin' can only be used with 1 dimensional arrays"));
  }
  if((bbBool(f0.l_atype)||f0.l_init->m_type->m__eq(((t_mx2_Type*)(g_mx2_Type_StringType))))){
    struct f1_t : public bbGCFrame{
      t_mx2_VarValue* l_iter{};
      t_mx2_Value* l_len{};
      t_mx2_Value* t0{};
      void gcMark(){
        bbGCMarkPtr(l_iter);
        bbGCMarkPtr(l_len);
        bbGCMarkPtr(t0);
      }
    }f1{};
    f0.l_init=f0.l_init->m_RemoveSideEffects(f0.l_iblock);
    f1.l_iter=f0.l_iblock->m_AllocLocal(f1.t0=((t_mx2_Value*)(g_mx2_LiteralValue_IntValue(bbInt(0)))));
    f1.l_len=f0.l_init->m_FindValue(BB_T("Length"));
    f1.l_len=(f1.t0=f1.l_len->m_ToRValue())->m_RemoveSideEffects(f0.l_iblock);
    f0.l_cond=((t_mx2_Value*)(bbGCNew<t_mx2_BinaryopValue>(((t_mx2_Type*)(g_mx2_Type_BoolType)),BB_T("<"),((t_mx2_Value*)(f1.l_iter)),f1.l_len)));
    f0.l_incr=f1.l_iter->m_Assign(((t_mx2_PNode*)0),BB_T("+="),f1.t0=((t_mx2_Value*)(g_mx2_LiteralValue_IntValue(1))),f0.l_iblock);
    if(bbBool(f0.l_atype)){
      struct f2_t : public bbGCFrame{
        bbArray<bbGCVar<t_mx2_Value>>* l_indices{};
        void gcMark(){
          bbGCMarkPtr(l_indices);
        }
      }f2{};
      f2.l_indices=bbArray<bbGCVar<t_mx2_Value>>::create(1);
      f2.l_indices->at(bbInt(0))=((t_mx2_Value*)(f1.l_iter));
      f0.l_curr=((t_mx2_Value*)(bbGCNew<t_mx2_ArrayIndexValue>(f0.l_atype,f0.l_init,f2.l_indices)));
    }else{
      f0.l_curr=((t_mx2_Value*)(bbGCNew<t_mx2_StringIndexValue>(f0.l_init,((t_mx2_Value*)(f1.l_iter)))));
    }
  }else{
    struct f1_t : public bbGCFrame{
      t_mx2_Value* l_atEnd{};
      t_mx2_Value* l_bump{};
      t_mx2_Value* l_iter{};
      void gcMark(){
        bbGCMarkPtr(l_atEnd);
        bbGCMarkPtr(l_bump);
        bbGCMarkPtr(l_iter);
      }
    }f1{};
    f1.l_iter=f0.l_init->m_FindValue(BB_T("All"));
    if(!bbBool(f1.l_iter)){
      f1.l_iter=f0.l_init->m_FindValue(BB_T("GetIterator"));
      if(!bbBool(f1.l_iter)){
        f1.l_iter=f0.l_init->m_RemoveSideEffects(f0.l_iblock);
      }
    }else{
      struct f2_t : public bbGCFrame{
        t_mx2_Value* t0{};
        void gcMark(){
          bbGCMarkPtr(t0);
        }
      }f2{};
      f1.l_iter=(f2.t0=f1.l_iter->m_Invoke(((bbArray<bbGCVar<t_mx2_Value>>*)0)))->m_RemoveSideEffects(f0.l_iblock);
    }
    f1.l_atEnd=f1.l_iter->m_FindValue(BB_T("AtEnd"));
    if(!bbBool(f1.l_atEnd)){
      struct f2_t : public bbGCFrame{
        t_mx2_Value* l_isValid{};
        void gcMark(){
          bbGCMarkPtr(l_isValid);
        }
      }f2{};
      f2.l_isValid=f1.l_iter->m_FindValue(BB_T("Valid"));
      if(!bbBool(f2.l_isValid)){
        throw bbGCNew<t_mx2_SemantEx>(BB_T("Iterator has no 'AtEnd' property"));
      }
      f2.l_isValid=f2.l_isValid->m_UpCast(((t_mx2_Type*)(g_mx2_Type_BoolType)));
      f0.l_cond=f2.l_isValid;
    }else{
      f1.l_atEnd=f1.l_atEnd->m_UpCast(((t_mx2_Type*)(g_mx2_Type_BoolType)));
      f1.l_atEnd=((t_mx2_Value*)(bbGCNew<t_mx2_UnaryopValue>(((t_mx2_Type*)(g_mx2_Type_BoolType)),BB_T("not"),f1.l_atEnd)));
      f0.l_cond=f1.l_atEnd;
    }
    f0.l_curr=f1.l_iter->m_FindValue(BB_T("Current"));
    if(!bbBool(f0.l_curr)){
      throw bbGCNew<t_mx2_SemantEx>(BB_T("Iterator has no 'Current' property"));
    }
    f0.l_curr=f0.l_curr->m_ToRValue();
    f1.l_bump=f1.l_iter->m_FindValue(BB_T("Bump"));
    if(!bbBool(f1.l_bump)){
      throw bbGCNew<t_mx2_SemantEx>(BB_T("Iterator has no 'Bump' method"));
    }
    f1.l_bump=f1.l_bump->m_Invoke(((bbArray<bbGCVar<t_mx2_Value>>*)0));
    f0.l_incr=((t_mx2_Stmt*)(bbGCNew<t_mx2_EvalStmt>(((t_mx2_PNode*)0),f1.l_bump)));
  }
  if(bbBool(this->m_varIdent)){
    if(bbBool(this->m_varType)){
      struct f2_t : public bbGCFrame{
        t_mx2_Type* t0{};
        void gcMark(){
          bbGCMarkPtr(t0);
        }
      }f2{};
      f0.l_curr=f0.l_curr->m_UpCast(f2.t0=this->m_varType->m_Semant(((t_mx2_Scope*)(f0.l_block)),false));
    }
    f0.l_block->m_AllocLocal(this->m_varIdent,f0.l_curr);
  }else{
    struct f1_t : public bbGCFrame{
      t_mx2_Value* l_iter{};
      t_mx2_Value* t0{};
      t_mx2_Stmt* t1{};
      void gcMark(){
        bbGCMarkPtr(l_iter);
        bbGCMarkPtr(t0);
        bbGCMarkPtr(t1);
      }
    }f1{};
    f1.l_iter=(f1.t0=this->m_varExpr->m_Semant(((t_mx2_Scope*)(f0.l_block))))->m_RemoveSideEffects(f0.l_block);
    if(!f1.l_iter->m_IsAssignable()){
      throw bbGCNew<t_mx2_SemantEx>(((BB_T("For loop index '")+f1.l_iter->m_ToString())+BB_T("' is not assignable")));
    }
    f0.l_block->m_Emit(f1.t1=f1.l_iter->m_Assign(((t_mx2_PNode*)0),BB_T("="),f0.l_curr,f0.l_block));
  }
  f0.l_block->m_Semant(this->m_stmts);
  return ((t_mx2_Stmt*)(bbGCNew<t_mx2_ForStmt>(((t_mx2_PNode*)(this)),f0.l_iblock,f0.l_cond,f0.l_incr,f0.l_block)));
}

t_mx2_Stmt* t_mx2_ForStmtExpr::m_OnSemant(t_mx2_Block* l_block){
  struct f0_t : public bbGCFrame{
    t_mx2_Block* l_block{};
    t_mx2_Value* l_cond{};
    t_mx2_Block* l_iblock{};
    t_mx2_Value* l_incr{};
    t_mx2_Stmt* l_incrStmt{};
    t_mx2_Value* l_init{};
    t_mx2_Value* l_iter{};
    t_mx2_ValueExpr* l_iterExpr{};
    t_mx2_Value* l_term{};
    t_mx2_ValueExpr* l_termExpr{};
    f0_t(t_mx2_Block* l_block):l_block(l_block){
    }
    void gcMark(){
      bbGCMarkPtr(l_block);
      bbGCMarkPtr(l_cond);
      bbGCMarkPtr(l_iblock);
      bbGCMarkPtr(l_incr);
      bbGCMarkPtr(l_incrStmt);
      bbGCMarkPtr(l_init);
      bbGCMarkPtr(l_iter);
      bbGCMarkPtr(l_iterExpr);
      bbGCMarkPtr(l_term);
      bbGCMarkPtr(l_termExpr);
    }
  }f0{l_block};
  if((this->m_kind==BB_T("eachin"))){
    return this->m_SemantEachin(f0.l_block);
  }
  f0.l_iblock=bbGCNew<t_mx2_Block>(f0.l_block);
  f0.l_block=bbGCNew<t_mx2_Block>(f0.l_iblock);
  f0.l_block->m_loop=true;
  f0.l_init=this->m_init->m_SemantRValue(((t_mx2_Scope*)(f0.l_iblock)),((t_mx2_Type*)0));
  if(bbBool(this->m_varIdent)){
    if(bbBool(this->m_varType)){
      struct f2_t : public bbGCFrame{
        t_mx2_Type* t0{};
        void gcMark(){
          bbGCMarkPtr(t0);
        }
      }f2{};
      f0.l_init=f0.l_init->m_UpCast(f2.t0=this->m_varType->m_Semant(((t_mx2_Scope*)(f0.l_iblock)),false));
    }
    f0.l_iter=((t_mx2_Value*)(f0.l_iblock->m_AllocLocal(this->m_varIdent,f0.l_init)));
  }else{
    struct f1_t : public bbGCFrame{
      t_mx2_Value* t0{};
      t_mx2_Stmt* t1{};
      void gcMark(){
        bbGCMarkPtr(t0);
        bbGCMarkPtr(t1);
      }
    }f1{};
    f0.l_iter=(f1.t0=this->m_varExpr->m_Semant(((t_mx2_Scope*)(f0.l_iblock))))->m_RemoveSideEffects(f0.l_iblock);
    if(!f0.l_iter->m_IsAssignable()){
      throw bbGCNew<t_mx2_SemantEx>(((BB_T("For loop index '")+f0.l_iter->m_ToString())+BB_T("' is not assignable")));
    }
    f0.l_iblock->m_Emit(f1.t1=f0.l_iter->m_Assign(((t_mx2_PNode*)0),BB_T("="),f0.l_init,f0.l_iblock));
  }
  f0.l_term=this->m_cond->m_SemantRValue(((t_mx2_Scope*)(f0.l_iblock)),((t_mx2_Type*)0));
  f0.l_termExpr=bbGCNew<t_mx2_ValueExpr>(f0.l_term,this->m_srcpos,this->m_endpos);
  f0.l_iterExpr=bbGCNew<t_mx2_ValueExpr>(f0.l_iter,this->m_srcpos,this->m_endpos);
  bbString l_opx=BB_T("<");
  bbString l_opy=BB_T(">");
  if((this->m_kind==BB_T("to"))){
    l_opx=BB_T("<=");
    l_opy=BB_T(">=");
  }
  if(bbBool(this->m_incr)){
    struct f1_t : public bbGCFrame{
      t_mx2_Value* l_cmp1{};
      t_mx2_Value* l_cmp2{};
      t_mx2_Value* l_cmp3{};
      t_mx2_Value* l_cmp4{};
      t_mx2_BinaryopValue* l_cmp5{};
      t_mx2_BinaryopValue* l_cmp6{};
      t_mx2_ValueExpr* l_incrExpr{};
      t_mx2_LiteralExpr* l_zero{};
      t_mx2_Value* t0{};
      t_mx2_BinaryopExpr* t1{};
      void gcMark(){
        bbGCMarkPtr(l_cmp1);
        bbGCMarkPtr(l_cmp2);
        bbGCMarkPtr(l_cmp3);
        bbGCMarkPtr(l_cmp4);
        bbGCMarkPtr(l_cmp5);
        bbGCMarkPtr(l_cmp6);
        bbGCMarkPtr(l_incrExpr);
        bbGCMarkPtr(l_zero);
        bbGCMarkPtr(t0);
        bbGCMarkPtr(t1);
      }
    }f1{};
    f0.l_incr=(f1.t0=this->m_incr->m_SemantRValue(((t_mx2_Scope*)(f0.l_iblock)),((t_mx2_Type*)0)))->m_RemoveSideEffects(f0.l_iblock);
    f1.l_incrExpr=bbGCNew<t_mx2_ValueExpr>(f0.l_incr,this->m_srcpos,this->m_endpos);
    f1.l_zero=bbGCNew<t_mx2_LiteralExpr>(BB_T("0"),g_mx2_TOKE_0INTLIT,((t_mx2_TypeExpr*)0),this->m_srcpos,this->m_endpos);
    f1.l_cmp1=(f1.t1=bbGCNew<t_mx2_BinaryopExpr>(BB_T(">"),((t_mx2_Expr*)(f1.l_incrExpr)),((t_mx2_Expr*)(f1.l_zero)),this->m_srcpos,this->m_endpos))->m_SemantRValue(((t_mx2_Scope*)(f0.l_iblock)),((t_mx2_Type*)0));
    f1.l_cmp2=(f1.t1=bbGCNew<t_mx2_BinaryopExpr>(l_opx,((t_mx2_Expr*)(f0.l_iterExpr)),((t_mx2_Expr*)(f0.l_termExpr)),this->m_srcpos,this->m_endpos))->m_SemantRValue(((t_mx2_Scope*)(f0.l_iblock)),((t_mx2_Type*)0));
    f1.l_cmp3=(f1.t1=bbGCNew<t_mx2_BinaryopExpr>(BB_T("<"),((t_mx2_Expr*)(f1.l_incrExpr)),((t_mx2_Expr*)(f1.l_zero)),this->m_srcpos,this->m_endpos))->m_SemantRValue(((t_mx2_Scope*)(f0.l_iblock)),((t_mx2_Type*)0));
    f1.l_cmp4=(f1.t1=bbGCNew<t_mx2_BinaryopExpr>(l_opy,((t_mx2_Expr*)(f0.l_iterExpr)),((t_mx2_Expr*)(f0.l_termExpr)),this->m_srcpos,this->m_endpos))->m_SemantRValue(((t_mx2_Scope*)(f0.l_iblock)),((t_mx2_Type*)0));
    f1.l_cmp5=bbGCNew<t_mx2_BinaryopValue>(((t_mx2_Type*)(g_mx2_Type_BoolType)),BB_T("and"),f1.l_cmp1,f1.l_cmp2);
    f1.l_cmp6=bbGCNew<t_mx2_BinaryopValue>(((t_mx2_Type*)(g_mx2_Type_BoolType)),BB_T("and"),f1.l_cmp3,f1.l_cmp4);
    f0.l_cond=((t_mx2_Value*)(bbGCNew<t_mx2_BinaryopValue>(((t_mx2_Type*)(g_mx2_Type_BoolType)),BB_T("or"),((t_mx2_Value*)(f1.l_cmp5)),((t_mx2_Value*)(f1.l_cmp6)))));
  }else{
    struct f1_t : public bbGCFrame{
      t_mx2_BinaryopExpr* t0{};
      void gcMark(){
        bbGCMarkPtr(t0);
      }
    }f1{};
    f0.l_incr=((t_mx2_Value*)(bbGCNew<t_mx2_LiteralValue>(((t_mx2_Type*)(g_mx2_Type_IntType)),BB_T("1"))));
    f0.l_cond=(f1.t0=bbGCNew<t_mx2_BinaryopExpr>(l_opx,((t_mx2_Expr*)(f0.l_iterExpr)),((t_mx2_Expr*)(f0.l_termExpr)),this->m_srcpos,this->m_endpos))->m_SemantRValue(((t_mx2_Scope*)(f0.l_iblock)),((t_mx2_Type*)0));
  }
  f0.l_incrStmt=f0.l_iter->m_Assign(((t_mx2_PNode*)(this)),BB_T("+="),f0.l_incr,f0.l_iblock);
  f0.l_block->m_Semant(this->m_stmts);
  return ((t_mx2_Stmt*)(bbGCNew<t_mx2_ForStmt>(((t_mx2_PNode*)(this)),f0.l_iblock,f0.l_cond,f0.l_incrStmt,f0.l_block)));
}

void t_mx2_ForStmtExpr::m_Emit(t_std_collections_Stack_1s* l_buf,bbString l_spc){
  bbString l_str=BB_T("for ");
  if(bbBool(this->m_varIdent)){
    l_str+=this->m_varIdent;
    if(bbBool(this->m_varType)){
      l_str+=(BB_T(":")+this->m_varType->m_ToString());
    }else{
      l_str+=BB_T(":=");
    }
  }else{
    l_str+=(this->m_varExpr->m_ToString()+BB_T("="));
  }
  if((this->m_kind==BB_T("eachin"))){
    l_str+=(BB_T(" eachin ")+this->m_init->m_ToString());
  }else{
    l_str+=this->m_init->m_ToString();
    if((this->m_kind==BB_T("to"))){
      l_str+=BB_T(" to ");
    }else{
      l_str+=BB_T(" until ");
    }
    l_str+=this->m_cond->m_ToString();
    if(bbBool(this->m_incr)){
      l_str+=(BB_T(" step ")+this->m_incr->m_ToString());
    }
  }
  l_buf->m_Push((l_spc+l_str));
  g_mx2_EmitStmts(this->m_stmts,l_buf,l_spc);
  l_buf->m_Push((l_spc+BB_T("next")));
}

void t_mx2_CatchExpr::gcMark(){
  bbGCMark(m_varType);
  bbGCMark(m_stmts);
}

t_mx2_CatchExpr::t_mx2_CatchExpr(bbString l_varIdent,t_mx2_TypeExpr* l_varType,bbArray<bbGCVar<t_mx2_StmtExpr>>* l_stmts){
  this->m_varIdent=l_varIdent;
  this->m_varType=l_varType;
  this->m_stmts=l_stmts;
}

void t_mx2_TryStmtExpr::gcMark(){
  t_mx2_StmtExpr::gcMark();
  bbGCMark(m_stmts);
  bbGCMark(m_catches);
}

t_mx2_TryStmtExpr::t_mx2_TryStmtExpr(bbArray<bbGCVar<t_mx2_StmtExpr>>* l_stmts,bbArray<bbGCVar<t_mx2_CatchExpr>>* l_catches,bbInt l_srcpos,bbInt l_endpos):t_mx2_StmtExpr(l_srcpos,l_endpos){
  this->m_stmts=l_stmts;
  this->m_catches=l_catches;
}

t_mx2_Stmt* t_mx2_TryStmtExpr::m_OnSemant(t_mx2_Block* l_block){
  struct f0_t : public bbGCFrame{
    t_std_collections_Stack_1Tt_mx2_CatchStmt_2* l_catches{};
    t_mx2_Block* l_iblock{};
    bbArray<bbGCVar<t_mx2_CatchStmt>>* t0{};
    void gcMark(){
      bbGCMarkPtr(l_catches);
      bbGCMarkPtr(l_iblock);
      bbGCMarkPtr(t0);
    }
  }f0{};
  f0.l_iblock=bbGCNew<t_mx2_Block>(l_block);
  f0.l_iblock->m_Semant(this->m_stmts);
  f0.l_catches=bbGCNew<t_std_collections_Stack_1Tt_mx2_CatchStmt_2>();
  {
    bbInt l_0=bbInt(0);
    bbInt l_1=this->m_catches->length();
    for(;(l_0<l_1);l_0+=1){
      struct f2_t : public bbGCFrame{
        t_mx2_CatchExpr* l_cexpr{};
        t_mx2_Block* l_iblock{};
        t_mx2_VarValue* l_vvar{};
        t_mx2_CatchStmt* t0{};
        void gcMark(){
          bbGCMarkPtr(l_cexpr);
          bbGCMarkPtr(l_iblock);
          bbGCMarkPtr(l_vvar);
          bbGCMarkPtr(t0);
        }
      }f2{};
      f2.l_cexpr=this->m_catches->at(l_0);
      f2.l_iblock=bbGCNew<t_mx2_Block>(l_block);
      f2.l_iblock->m_inex=true;
      if(bbBool(f2.l_cexpr->m_varType)){
        struct f3_t : public bbGCFrame{
          t_mx2_Type* l_type{};
          t_mx2_Value* t0{};
          void gcMark(){
            bbGCMarkPtr(l_type);
            bbGCMarkPtr(t0);
          }
        }f3{};
        f3.l_type=f2.l_cexpr->m_varType->m_Semant(((t_mx2_Scope*)(f2.l_iblock)),false);
        f2.l_vvar=bbGCNew<t_mx2_VarValue>(BB_T("local"),f2.l_cexpr->m_varIdent,f3.t0=((t_mx2_Value*)(bbGCNew<t_mx2_LiteralValue>(f3.l_type,bbString{}))),((t_mx2_Scope*)(f2.l_iblock)));
        f2.l_iblock->m_Insert(f2.l_cexpr->m_varIdent,((t_mx2_SNode*)(f2.l_vvar)));
      }
      f2.l_iblock->m_Semant(f2.l_cexpr->m_stmts);
      f0.l_catches->m_Push(f2.t0=bbGCNew<t_mx2_CatchStmt>(f2.l_vvar,f2.l_iblock));
    }
  }
  return ((t_mx2_Stmt*)(bbGCNew<t_mx2_TryStmt>(((t_mx2_PNode*)(this)),f0.l_iblock,f0.t0=f0.l_catches->m_ToArray())));
}

void t_mx2_ThrowStmtExpr::gcMark(){
  t_mx2_StmtExpr::gcMark();
  bbGCMark(m_expr);
}

t_mx2_ThrowStmtExpr::t_mx2_ThrowStmtExpr(t_mx2_Expr* l_expr,bbInt l_srcpos,bbInt l_endpos):t_mx2_StmtExpr(l_srcpos,l_endpos){
  this->m_expr=l_expr;
}

t_mx2_Stmt* t_mx2_ThrowStmtExpr::m_OnSemant(t_mx2_Block* l_block){
  if(bbBool(this->m_expr)){
    struct f1_t : public bbGCFrame{
      t_mx2_ClassType* l_ctype{};
      t_mx2_Value* l_value{};
      t_mx2_Stmt* t0{};
      void gcMark(){
        bbGCMarkPtr(l_ctype);
        bbGCMarkPtr(l_value);
        bbGCMarkPtr(t0);
      }
    }f1{};
    f1.l_value=this->m_expr->m_SemantRValue(((t_mx2_Scope*)(l_block)),((t_mx2_Type*)0));
    f1.l_ctype=g_mx2_TCast_1Tt_mx2_ClassType_2(f1.l_value->m_type);
    if((!bbBool(f1.l_ctype)||!f1.l_ctype->m_ExtendsType(((t_mx2_Type*)(g_mx2_Type_ThrowableClass))))){
      throw bbGCNew<t_mx2_SemantEx>(BB_T("Thrown value type must extend 'Throwable'"));
    }
    l_block->m_Emit(f1.t0=((t_mx2_Stmt*)(bbGCNew<t_mx2_ThrowStmt>(((t_mx2_PNode*)(this)),f1.l_value))));
    l_block->m_reachable=false;
  }else if(l_block->m_inex){
    struct f1_t : public bbGCFrame{
      t_mx2_Stmt* t0{};
      void gcMark(){
        bbGCMarkPtr(t0);
      }
    }f1{};
    l_block->m_Emit(f1.t0=((t_mx2_Stmt*)(bbGCNew<t_mx2_ThrowStmt>(((t_mx2_PNode*)(this)),((t_mx2_Value*)0)))));
    l_block->m_reachable=false;
  }else{
    throw bbGCNew<t_mx2_SemantEx>(BB_T("Exceptions can only be rethrown inside 'Catch' blocks"));
  }
  return ((t_mx2_Stmt*)0);
}

void mx2_mx2cc_stmtexpr_init(){
  static bool done;
  if(done) return;
  done=true;
}

bbInit mx2_mx2cc_stmtexpr_init_v("mx2cc_stmtexpr",&mx2_mx2cc_stmtexpr_init);
