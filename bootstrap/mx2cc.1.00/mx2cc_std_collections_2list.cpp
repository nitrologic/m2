
#include "mx2cc_std_collections_2list.h"

// ***** External *****

#include "../../../../../modules/monkey/monkey.buildv1.0.0/desktop_release_linux/monkey_debug.h"
#include "mx2cc_alias.h"
#include "mx2cc_class.h"
#include "mx2cc_decl.h"
#include "mx2cc_errors.h"
#include "mx2cc_expr.h"
#include "mx2cc_func.h"
#include "mx2cc_module.h"
#include "mx2cc_namespace.h"
#include "mx2cc_node.h"
#include "mx2cc_scope.h"
#include "mx2cc_std_collections_2stack.h"
#include "mx2cc_stmt.h"
#include "mx2cc_stmtexpr.h"
#include "mx2cc_toker.h"
#include "mx2cc_translator.h"
#include "mx2cc_type.h"
#include "mx2cc_typeexpr.h"
#include "mx2cc_var.h"
#include "../../../../../modules/std/std.buildv1.0.0/desktop_release_linux/std_collections_2stack.h"

// ***** Internal *****

void g_std_collections_List_1Tt_mx2_Translator_GCTmp_2_AddAll_1Tt_std_collections_List_1Tt_mx2_Translator_GCTmp_2_2(t_std_collections_List_1Tt_mx2_Translator_GCTmp_2* l_self,t_std_collections_List_1Tt_mx2_Translator_GCTmp_2* l_values){
  {
    struct f1_t : public bbGCFrame{
      t_std_collections_List_1Tt_mx2_Translator_GCTmp_2_Iterator l_0{};
      void gcMark(){
        bbGCMark(l_0);
      }
    }f1{};
    f1.l_0=l_values->m_All();
    for(;!f1.l_0.m_AtEnd();f1.l_0.m_Bump()){
      struct f2_t : public bbGCFrame{
        t_mx2_Translator_GCTmp* l_value{};
        void gcMark(){
          bbGCMarkPtr(l_value);
        }
      }f2{};
      f2.l_value=f1.l_0.m_Current();
      l_self->m_AddLast(f2.l_value);
    }
  }
}

void g_std_collections_List_1Tt_mx2_Translator_GCTmp_2_AddAll_1Tt_std_collections_Stack_1Tt_mx2_Translator_GCTmp_2_2(t_std_collections_List_1Tt_mx2_Translator_GCTmp_2* l_self,t_std_collections_Stack_1Tt_mx2_Translator_GCTmp_2* l_values){
  {
    struct f1_t : public bbGCFrame{
      t_std_collections_Stack_1Tt_mx2_Translator_GCTmp_2_Iterator l_0{};
      void gcMark(){
        bbGCMark(l_0);
      }
    }f1{};
    f1.l_0=l_values->m_All();
    for(;!f1.l_0.m_AtEnd();f1.l_0.m_Bump()){
      struct f2_t : public bbGCFrame{
        t_mx2_Translator_GCTmp* l_value{};
        void gcMark(){
          bbGCMarkPtr(l_value);
        }
      }f2{};
      f2.l_value=f1.l_0.m_Current();
      l_self->m_AddLast(f2.l_value);
    }
  }
}

void g_std_collections_List_1Tt_mx2_Stmt_2_AddAll_1Tt_std_collections_List_1Tt_mx2_Stmt_2_2(t_std_collections_List_1Tt_mx2_Stmt_2* l_self,t_std_collections_List_1Tt_mx2_Stmt_2* l_values){
  {
    struct f1_t : public bbGCFrame{
      t_std_collections_List_1Tt_mx2_Stmt_2_Iterator l_0{};
      void gcMark(){
        bbGCMark(l_0);
      }
    }f1{};
    f1.l_0=l_values->m_All();
    for(;!f1.l_0.m_AtEnd();f1.l_0.m_Bump()){
      struct f2_t : public bbGCFrame{
        t_mx2_Stmt* l_value{};
        void gcMark(){
          bbGCMarkPtr(l_value);
        }
      }f2{};
      f2.l_value=f1.l_0.m_Current();
      l_self->m_AddLast(f2.l_value);
    }
  }
}

void g_std_collections_List_1Tt_mx2_Stmt_2_AddAll_1Tt_std_collections_Stack_1Tt_mx2_Stmt_2_2(t_std_collections_List_1Tt_mx2_Stmt_2* l_self,t_std_collections_Stack_1Tt_mx2_Stmt_2* l_values){
  {
    struct f1_t : public bbGCFrame{
      t_std_collections_Stack_1Tt_mx2_Stmt_2_Iterator l_0{};
      void gcMark(){
        bbGCMark(l_0);
      }
    }f1{};
    f1.l_0=l_values->m_All();
    for(;!f1.l_0.m_AtEnd();f1.l_0.m_Bump()){
      struct f2_t : public bbGCFrame{
        t_mx2_Stmt* l_value{};
        void gcMark(){
          bbGCMarkPtr(l_value);
        }
      }f2{};
      f2.l_value=f1.l_0.m_Current();
      l_self->m_AddLast(f2.l_value);
    }
  }
}

void g_std_collections_List_1Tt_mx2_Toker_2_AddAll_1Tt_std_collections_List_1Tt_mx2_Toker_2_2(t_std_collections_List_1Tt_mx2_Toker_2* l_self,t_std_collections_List_1Tt_mx2_Toker_2* l_values){
  {
    struct f1_t : public bbGCFrame{
      t_std_collections_List_1Tt_mx2_Toker_2_Iterator l_0{};
      void gcMark(){
        bbGCMark(l_0);
      }
    }f1{};
    f1.l_0=l_values->m_All();
    for(;!f1.l_0.m_AtEnd();f1.l_0.m_Bump()){
      struct f2_t : public bbGCFrame{
        t_mx2_Toker* l_value{};
        void gcMark(){
          bbGCMarkPtr(l_value);
        }
      }f2{};
      f2.l_value=f1.l_0.m_Current();
      l_self->m_AddLast(f2.l_value);
    }
  }
}

void g_std_collections_List_1Tt_mx2_Toker_2_AddAll_1Tt_std_collections_Stack_1Tt_mx2_Toker_2_2(t_std_collections_List_1Tt_mx2_Toker_2* l_self,t_std_collections_Stack_1Tt_mx2_Toker_2* l_values){
  {
    struct f1_t : public bbGCFrame{
      t_std_collections_Stack_1Tt_mx2_Toker_2_Iterator l_0{};
      void gcMark(){
        bbGCMark(l_0);
      }
    }f1{};
    f1.l_0=l_values->m_All();
    for(;!f1.l_0.m_AtEnd();f1.l_0.m_Bump()){
      struct f2_t : public bbGCFrame{
        t_mx2_Toker* l_value{};
        void gcMark(){
          bbGCMarkPtr(l_value);
        }
      }f2{};
      f2.l_value=f1.l_0.m_Current();
      l_self->m_AddLast(f2.l_value);
    }
  }
}

void g_std_collections_List_1Tt_mx2_ParseEx_2_AddAll_1Tt_std_collections_List_1Tt_mx2_ParseEx_2_2(t_std_collections_List_1Tt_mx2_ParseEx_2* l_self,t_std_collections_List_1Tt_mx2_ParseEx_2* l_values){
  {
    struct f1_t : public bbGCFrame{
      t_std_collections_List_1Tt_mx2_ParseEx_2_Iterator l_0{};
      void gcMark(){
        bbGCMark(l_0);
      }
    }f1{};
    f1.l_0=l_values->m_All();
    for(;!f1.l_0.m_AtEnd();f1.l_0.m_Bump()){
      struct f2_t : public bbGCFrame{
        t_mx2_ParseEx* l_value{};
        void gcMark(){
          bbGCMarkPtr(l_value);
        }
      }f2{};
      f2.l_value=f1.l_0.m_Current();
      l_self->m_AddLast(f2.l_value);
    }
  }
}

void g_std_collections_List_1Tt_mx2_ParseEx_2_AddAll_1Tt_std_collections_Stack_1Tt_mx2_ParseEx_2_2(t_std_collections_List_1Tt_mx2_ParseEx_2* l_self,t_std_collections_Stack_1Tt_mx2_ParseEx_2* l_values){
  {
    struct f1_t : public bbGCFrame{
      t_std_collections_Stack_1Tt_mx2_ParseEx_2_Iterator l_0{};
      void gcMark(){
        bbGCMark(l_0);
      }
    }f1{};
    f1.l_0=l_values->m_All();
    for(;!f1.l_0.m_AtEnd();f1.l_0.m_Bump()){
      struct f2_t : public bbGCFrame{
        t_mx2_ParseEx* l_value{};
        void gcMark(){
          bbGCMarkPtr(l_value);
        }
      }f2{};
      f2.l_value=f1.l_0.m_Current();
      l_self->m_AddLast(f2.l_value);
    }
  }
}

void g_std_collections_List_1Tt_mx2_TypeExpr_2_AddAll_1Tt_std_collections_List_1Tt_mx2_TypeExpr_2_2(t_std_collections_List_1Tt_mx2_TypeExpr_2* l_self,t_std_collections_List_1Tt_mx2_TypeExpr_2* l_values){
  {
    struct f1_t : public bbGCFrame{
      t_std_collections_List_1Tt_mx2_TypeExpr_2_Iterator l_0{};
      void gcMark(){
        bbGCMark(l_0);
      }
    }f1{};
    f1.l_0=l_values->m_All();
    for(;!f1.l_0.m_AtEnd();f1.l_0.m_Bump()){
      struct f2_t : public bbGCFrame{
        t_mx2_TypeExpr* l_value{};
        void gcMark(){
          bbGCMarkPtr(l_value);
        }
      }f2{};
      f2.l_value=f1.l_0.m_Current();
      l_self->m_AddLast(f2.l_value);
    }
  }
}

void g_std_collections_List_1Tt_mx2_TypeExpr_2_AddAll_1Tt_std_collections_Stack_1Tt_mx2_TypeExpr_2_2(t_std_collections_List_1Tt_mx2_TypeExpr_2* l_self,t_std_collections_Stack_1Tt_mx2_TypeExpr_2* l_values){
  {
    struct f1_t : public bbGCFrame{
      t_std_collections_Stack_1Tt_mx2_TypeExpr_2_Iterator l_0{};
      void gcMark(){
        bbGCMark(l_0);
      }
    }f1{};
    f1.l_0=l_values->m_All();
    for(;!f1.l_0.m_AtEnd();f1.l_0.m_Bump()){
      struct f2_t : public bbGCFrame{
        t_mx2_TypeExpr* l_value{};
        void gcMark(){
          bbGCMarkPtr(l_value);
        }
      }f2{};
      f2.l_value=f1.l_0.m_Current();
      l_self->m_AddLast(f2.l_value);
    }
  }
}

void g_std_collections_List_1Tt_mx2_CatchExpr_2_AddAll_1Tt_std_collections_List_1Tt_mx2_CatchExpr_2_2(t_std_collections_List_1Tt_mx2_CatchExpr_2* l_self,t_std_collections_List_1Tt_mx2_CatchExpr_2* l_values){
  {
    struct f1_t : public bbGCFrame{
      t_std_collections_List_1Tt_mx2_CatchExpr_2_Iterator l_0{};
      void gcMark(){
        bbGCMark(l_0);
      }
    }f1{};
    f1.l_0=l_values->m_All();
    for(;!f1.l_0.m_AtEnd();f1.l_0.m_Bump()){
      struct f2_t : public bbGCFrame{
        t_mx2_CatchExpr* l_value{};
        void gcMark(){
          bbGCMarkPtr(l_value);
        }
      }f2{};
      f2.l_value=f1.l_0.m_Current();
      l_self->m_AddLast(f2.l_value);
    }
  }
}

void g_std_collections_List_1Tt_mx2_CatchExpr_2_AddAll_1Tt_std_collections_Stack_1Tt_mx2_CatchExpr_2_2(t_std_collections_List_1Tt_mx2_CatchExpr_2* l_self,t_std_collections_Stack_1Tt_mx2_CatchExpr_2* l_values){
  {
    struct f1_t : public bbGCFrame{
      t_std_collections_Stack_1Tt_mx2_CatchExpr_2_Iterator l_0{};
      void gcMark(){
        bbGCMark(l_0);
      }
    }f1{};
    f1.l_0=l_values->m_All();
    for(;!f1.l_0.m_AtEnd();f1.l_0.m_Bump()){
      struct f2_t : public bbGCFrame{
        t_mx2_CatchExpr* l_value{};
        void gcMark(){
          bbGCMarkPtr(l_value);
        }
      }f2{};
      f2.l_value=f1.l_0.m_Current();
      l_self->m_AddLast(f2.l_value);
    }
  }
}

void g_std_collections_List_1Tt_mx2_StmtExpr_2_AddAll_1Tt_std_collections_List_1Tt_mx2_StmtExpr_2_2(t_std_collections_List_1Tt_mx2_StmtExpr_2* l_self,t_std_collections_List_1Tt_mx2_StmtExpr_2* l_values){
  {
    struct f1_t : public bbGCFrame{
      t_std_collections_List_1Tt_mx2_StmtExpr_2_Iterator l_0{};
      void gcMark(){
        bbGCMark(l_0);
      }
    }f1{};
    f1.l_0=l_values->m_All();
    for(;!f1.l_0.m_AtEnd();f1.l_0.m_Bump()){
      struct f2_t : public bbGCFrame{
        t_mx2_StmtExpr* l_value{};
        void gcMark(){
          bbGCMarkPtr(l_value);
        }
      }f2{};
      f2.l_value=f1.l_0.m_Current();
      l_self->m_AddLast(f2.l_value);
    }
  }
}

void g_std_collections_List_1Tt_mx2_StmtExpr_2_AddAll_1Tt_std_collections_Stack_1Tt_mx2_StmtExpr_2_2(t_std_collections_List_1Tt_mx2_StmtExpr_2* l_self,t_std_collections_Stack_1Tt_mx2_StmtExpr_2* l_values){
  {
    struct f1_t : public bbGCFrame{
      t_std_collections_Stack_1Tt_mx2_StmtExpr_2_Iterator l_0{};
      void gcMark(){
        bbGCMark(l_0);
      }
    }f1{};
    f1.l_0=l_values->m_All();
    for(;!f1.l_0.m_AtEnd();f1.l_0.m_Bump()){
      struct f2_t : public bbGCFrame{
        t_mx2_StmtExpr* l_value{};
        void gcMark(){
          bbGCMarkPtr(l_value);
        }
      }f2{};
      f2.l_value=f1.l_0.m_Current();
      l_self->m_AddLast(f2.l_value);
    }
  }
}

void g_std_collections_List_1Tt_mx2_Expr_2_AddAll_1Tt_std_collections_List_1Tt_mx2_Expr_2_2(t_std_collections_List_1Tt_mx2_Expr_2* l_self,t_std_collections_List_1Tt_mx2_Expr_2* l_values){
  {
    struct f1_t : public bbGCFrame{
      t_std_collections_List_1Tt_mx2_Expr_2_Iterator l_0{};
      void gcMark(){
        bbGCMark(l_0);
      }
    }f1{};
    f1.l_0=l_values->m_All();
    for(;!f1.l_0.m_AtEnd();f1.l_0.m_Bump()){
      struct f2_t : public bbGCFrame{
        t_mx2_Expr* l_value{};
        void gcMark(){
          bbGCMarkPtr(l_value);
        }
      }f2{};
      f2.l_value=f1.l_0.m_Current();
      l_self->m_AddLast(f2.l_value);
    }
  }
}

void g_std_collections_List_1Tt_mx2_Expr_2_AddAll_1Tt_std_collections_Stack_1Tt_mx2_Expr_2_2(t_std_collections_List_1Tt_mx2_Expr_2* l_self,t_std_collections_Stack_1Tt_mx2_Expr_2* l_values){
  {
    struct f1_t : public bbGCFrame{
      t_std_collections_Stack_1Tt_mx2_Expr_2_Iterator l_0{};
      void gcMark(){
        bbGCMark(l_0);
      }
    }f1{};
    f1.l_0=l_values->m_All();
    for(;!f1.l_0.m_AtEnd();f1.l_0.m_Bump()){
      struct f2_t : public bbGCFrame{
        t_mx2_Expr* l_value{};
        void gcMark(){
          bbGCMarkPtr(l_value);
        }
      }f2{};
      f2.l_value=f1.l_0.m_Current();
      l_self->m_AddLast(f2.l_value);
    }
  }
}

void g_std_collections_List_1Tt_mx2_CaseExpr_2_AddAll_1Tt_std_collections_List_1Tt_mx2_CaseExpr_2_2(t_std_collections_List_1Tt_mx2_CaseExpr_2* l_self,t_std_collections_List_1Tt_mx2_CaseExpr_2* l_values){
  {
    struct f1_t : public bbGCFrame{
      t_std_collections_List_1Tt_mx2_CaseExpr_2_Iterator l_0{};
      void gcMark(){
        bbGCMark(l_0);
      }
    }f1{};
    f1.l_0=l_values->m_All();
    for(;!f1.l_0.m_AtEnd();f1.l_0.m_Bump()){
      struct f2_t : public bbGCFrame{
        t_mx2_CaseExpr* l_value{};
        void gcMark(){
          bbGCMarkPtr(l_value);
        }
      }f2{};
      f2.l_value=f1.l_0.m_Current();
      l_self->m_AddLast(f2.l_value);
    }
  }
}

void g_std_collections_List_1Tt_mx2_CaseExpr_2_AddAll_1Tt_std_collections_Stack_1Tt_mx2_CaseExpr_2_2(t_std_collections_List_1Tt_mx2_CaseExpr_2* l_self,t_std_collections_Stack_1Tt_mx2_CaseExpr_2* l_values){
  {
    struct f1_t : public bbGCFrame{
      t_std_collections_Stack_1Tt_mx2_CaseExpr_2_Iterator l_0{};
      void gcMark(){
        bbGCMark(l_0);
      }
    }f1{};
    f1.l_0=l_values->m_All();
    for(;!f1.l_0.m_AtEnd();f1.l_0.m_Bump()){
      struct f2_t : public bbGCFrame{
        t_mx2_CaseExpr* l_value{};
        void gcMark(){
          bbGCMarkPtr(l_value);
        }
      }f2{};
      f2.l_value=f1.l_0.m_Current();
      l_self->m_AddLast(f2.l_value);
    }
  }
}

void g_std_collections_List_1Tt_mx2_VarDecl_2_AddAll_1Tt_std_collections_List_1Tt_mx2_VarDecl_2_2(t_std_collections_List_1Tt_mx2_VarDecl_2* l_self,t_std_collections_List_1Tt_mx2_VarDecl_2* l_values){
  {
    struct f1_t : public bbGCFrame{
      t_std_collections_List_1Tt_mx2_VarDecl_2_Iterator l_0{};
      void gcMark(){
        bbGCMark(l_0);
      }
    }f1{};
    f1.l_0=l_values->m_All();
    for(;!f1.l_0.m_AtEnd();f1.l_0.m_Bump()){
      struct f2_t : public bbGCFrame{
        t_mx2_VarDecl* l_value{};
        void gcMark(){
          bbGCMarkPtr(l_value);
        }
      }f2{};
      f2.l_value=f1.l_0.m_Current();
      l_self->m_AddLast(f2.l_value);
    }
  }
}

void g_std_collections_List_1Tt_mx2_VarDecl_2_AddAll_1Tt_std_collections_Stack_1Tt_mx2_VarDecl_2_2(t_std_collections_List_1Tt_mx2_VarDecl_2* l_self,t_std_collections_Stack_1Tt_mx2_VarDecl_2* l_values){
  {
    struct f1_t : public bbGCFrame{
      t_std_collections_Stack_1Tt_mx2_VarDecl_2_Iterator l_0{};
      void gcMark(){
        bbGCMark(l_0);
      }
    }f1{};
    f1.l_0=l_values->m_All();
    for(;!f1.l_0.m_AtEnd();f1.l_0.m_Bump()){
      struct f2_t : public bbGCFrame{
        t_mx2_VarDecl* l_value{};
        void gcMark(){
          bbGCMarkPtr(l_value);
        }
      }f2{};
      f2.l_value=f1.l_0.m_Current();
      l_self->m_AddLast(f2.l_value);
    }
  }
}

void g_std_collections_List_1Tt_mx2_Decl_2_AddAll_1Tt_std_collections_List_1Tt_mx2_Decl_2_2(t_std_collections_List_1Tt_mx2_Decl_2* l_self,t_std_collections_List_1Tt_mx2_Decl_2* l_values){
  {
    struct f1_t : public bbGCFrame{
      t_std_collections_List_1Tt_mx2_Decl_2_Iterator l_0{};
      void gcMark(){
        bbGCMark(l_0);
      }
    }f1{};
    f1.l_0=l_values->m_All();
    for(;!f1.l_0.m_AtEnd();f1.l_0.m_Bump()){
      struct f2_t : public bbGCFrame{
        t_mx2_Decl* l_value{};
        void gcMark(){
          bbGCMarkPtr(l_value);
        }
      }f2{};
      f2.l_value=f1.l_0.m_Current();
      l_self->m_AddLast(f2.l_value);
    }
  }
}

void g_std_collections_List_1Tt_mx2_Decl_2_AddAll_1Tt_std_collections_Stack_1Tt_mx2_Decl_2_2(t_std_collections_List_1Tt_mx2_Decl_2* l_self,t_std_collections_Stack_1Tt_mx2_Decl_2* l_values){
  {
    struct f1_t : public bbGCFrame{
      t_std_collections_Stack_1Tt_mx2_Decl_2_Iterator l_0{};
      void gcMark(){
        bbGCMark(l_0);
      }
    }f1{};
    f1.l_0=l_values->m_All();
    for(;!f1.l_0.m_AtEnd();f1.l_0.m_Bump()){
      struct f2_t : public bbGCFrame{
        t_mx2_Decl* l_value{};
        void gcMark(){
          bbGCMarkPtr(l_value);
        }
      }f2{};
      f2.l_value=f1.l_0.m_Current();
      l_self->m_AddLast(f2.l_value);
    }
  }
}

void g_std_collections_List_1Tt_mx2_CatchStmt_2_AddAll_1Tt_std_collections_List_1Tt_mx2_CatchStmt_2_2(t_std_collections_List_1Tt_mx2_CatchStmt_2* l_self,t_std_collections_List_1Tt_mx2_CatchStmt_2* l_values){
  {
    struct f1_t : public bbGCFrame{
      t_std_collections_List_1Tt_mx2_CatchStmt_2_Iterator l_0{};
      void gcMark(){
        bbGCMark(l_0);
      }
    }f1{};
    f1.l_0=l_values->m_All();
    for(;!f1.l_0.m_AtEnd();f1.l_0.m_Bump()){
      struct f2_t : public bbGCFrame{
        t_mx2_CatchStmt* l_value{};
        void gcMark(){
          bbGCMarkPtr(l_value);
        }
      }f2{};
      f2.l_value=f1.l_0.m_Current();
      l_self->m_AddLast(f2.l_value);
    }
  }
}

void g_std_collections_List_1Tt_mx2_CatchStmt_2_AddAll_1Tt_std_collections_Stack_1Tt_mx2_CatchStmt_2_2(t_std_collections_List_1Tt_mx2_CatchStmt_2* l_self,t_std_collections_Stack_1Tt_mx2_CatchStmt_2* l_values){
  {
    struct f1_t : public bbGCFrame{
      t_std_collections_Stack_1Tt_mx2_CatchStmt_2_Iterator l_0{};
      void gcMark(){
        bbGCMark(l_0);
      }
    }f1{};
    f1.l_0=l_values->m_All();
    for(;!f1.l_0.m_AtEnd();f1.l_0.m_Bump()){
      struct f2_t : public bbGCFrame{
        t_mx2_CatchStmt* l_value{};
        void gcMark(){
          bbGCMarkPtr(l_value);
        }
      }f2{};
      f2.l_value=f1.l_0.m_Current();
      l_self->m_AddLast(f2.l_value);
    }
  }
}

void g_std_collections_List_1Tt_mx2_CaseStmt_2_AddAll_1Tt_std_collections_List_1Tt_mx2_CaseStmt_2_2(t_std_collections_List_1Tt_mx2_CaseStmt_2* l_self,t_std_collections_List_1Tt_mx2_CaseStmt_2* l_values){
  {
    struct f1_t : public bbGCFrame{
      t_std_collections_List_1Tt_mx2_CaseStmt_2_Iterator l_0{};
      void gcMark(){
        bbGCMark(l_0);
      }
    }f1{};
    f1.l_0=l_values->m_All();
    for(;!f1.l_0.m_AtEnd();f1.l_0.m_Bump()){
      struct f2_t : public bbGCFrame{
        t_mx2_CaseStmt* l_value{};
        void gcMark(){
          bbGCMarkPtr(l_value);
        }
      }f2{};
      f2.l_value=f1.l_0.m_Current();
      l_self->m_AddLast(f2.l_value);
    }
  }
}

void g_std_collections_List_1Tt_mx2_CaseStmt_2_AddAll_1Tt_std_collections_Stack_1Tt_mx2_CaseStmt_2_2(t_std_collections_List_1Tt_mx2_CaseStmt_2* l_self,t_std_collections_Stack_1Tt_mx2_CaseStmt_2* l_values){
  {
    struct f1_t : public bbGCFrame{
      t_std_collections_Stack_1Tt_mx2_CaseStmt_2_Iterator l_0{};
      void gcMark(){
        bbGCMark(l_0);
      }
    }f1{};
    f1.l_0=l_values->m_All();
    for(;!f1.l_0.m_AtEnd();f1.l_0.m_Bump()){
      struct f2_t : public bbGCFrame{
        t_mx2_CaseStmt* l_value{};
        void gcMark(){
          bbGCMarkPtr(l_value);
        }
      }f2{};
      f2.l_value=f1.l_0.m_Current();
      l_self->m_AddLast(f2.l_value);
    }
  }
}

void g_std_collections_List_1Tt_mx2_FuncListType_2_AddAll_1Tt_std_collections_List_1Tt_mx2_FuncListType_2_2(t_std_collections_List_1Tt_mx2_FuncListType_2* l_self,t_std_collections_List_1Tt_mx2_FuncListType_2* l_values){
  {
    struct f1_t : public bbGCFrame{
      t_std_collections_List_1Tt_mx2_FuncListType_2_Iterator l_0{};
      void gcMark(){
        bbGCMark(l_0);
      }
    }f1{};
    f1.l_0=l_values->m_All();
    for(;!f1.l_0.m_AtEnd();f1.l_0.m_Bump()){
      struct f2_t : public bbGCFrame{
        t_mx2_FuncListType* l_value{};
        void gcMark(){
          bbGCMarkPtr(l_value);
        }
      }f2{};
      f2.l_value=f1.l_0.m_Current();
      l_self->m_AddLast(f2.l_value);
    }
  }
}

void g_std_collections_List_1Tt_mx2_FuncListType_2_AddAll_1Tt_std_collections_Stack_1Tt_mx2_FuncListType_2_2(t_std_collections_List_1Tt_mx2_FuncListType_2* l_self,t_std_collections_Stack_1Tt_mx2_FuncListType_2* l_values){
  {
    struct f1_t : public bbGCFrame{
      t_std_collections_Stack_1Tt_mx2_FuncListType_2_Iterator l_0{};
      void gcMark(){
        bbGCMark(l_0);
      }
    }f1{};
    f1.l_0=l_values->m_All();
    for(;!f1.l_0.m_AtEnd();f1.l_0.m_Bump()){
      struct f2_t : public bbGCFrame{
        t_mx2_FuncListType* l_value{};
        void gcMark(){
          bbGCMarkPtr(l_value);
        }
      }f2{};
      f2.l_value=f1.l_0.m_Current();
      l_self->m_AddLast(f2.l_value);
    }
  }
}

void g_std_collections_List_1Tt_mx2_AliasType_2_AddAll_1Tt_std_collections_List_1Tt_mx2_AliasType_2_2(t_std_collections_List_1Tt_mx2_AliasType_2* l_self,t_std_collections_List_1Tt_mx2_AliasType_2* l_values){
  {
    struct f1_t : public bbGCFrame{
      t_std_collections_List_1Tt_mx2_AliasType_2_Iterator l_0{};
      void gcMark(){
        bbGCMark(l_0);
      }
    }f1{};
    f1.l_0=l_values->m_All();
    for(;!f1.l_0.m_AtEnd();f1.l_0.m_Bump()){
      struct f2_t : public bbGCFrame{
        t_mx2_AliasType* l_value{};
        void gcMark(){
          bbGCMarkPtr(l_value);
        }
      }f2{};
      f2.l_value=f1.l_0.m_Current();
      l_self->m_AddLast(f2.l_value);
    }
  }
}

void g_std_collections_List_1Tt_mx2_AliasType_2_AddAll_1Tt_std_collections_Stack_1Tt_mx2_AliasType_2_2(t_std_collections_List_1Tt_mx2_AliasType_2* l_self,t_std_collections_Stack_1Tt_mx2_AliasType_2* l_values){
  {
    struct f1_t : public bbGCFrame{
      t_std_collections_Stack_1Tt_mx2_AliasType_2_Iterator l_0{};
      void gcMark(){
        bbGCMark(l_0);
      }
    }f1{};
    f1.l_0=l_values->m_All();
    for(;!f1.l_0.m_AtEnd();f1.l_0.m_Bump()){
      struct f2_t : public bbGCFrame{
        t_mx2_AliasType* l_value{};
        void gcMark(){
          bbGCMarkPtr(l_value);
        }
      }f2{};
      f2.l_value=f1.l_0.m_Current();
      l_self->m_AddLast(f2.l_value);
    }
  }
}

void g_std_collections_List_1Tt_mx2_PNode_2_AddAll_1Tt_std_collections_List_1Tt_mx2_PNode_2_2(t_std_collections_List_1Tt_mx2_PNode_2* l_self,t_std_collections_List_1Tt_mx2_PNode_2* l_values){
  {
    struct f1_t : public bbGCFrame{
      t_std_collections_List_1Tt_mx2_PNode_2_Iterator l_0{};
      void gcMark(){
        bbGCMark(l_0);
      }
    }f1{};
    f1.l_0=l_values->m_All();
    for(;!f1.l_0.m_AtEnd();f1.l_0.m_Bump()){
      struct f2_t : public bbGCFrame{
        t_mx2_PNode* l_value{};
        void gcMark(){
          bbGCMarkPtr(l_value);
        }
      }f2{};
      f2.l_value=f1.l_0.m_Current();
      l_self->m_AddLast(f2.l_value);
    }
  }
}

void g_std_collections_List_1Tt_mx2_PNode_2_AddAll_1Tt_std_collections_Stack_1Tt_mx2_PNode_2_2(t_std_collections_List_1Tt_mx2_PNode_2* l_self,t_std_collections_Stack_1Tt_mx2_PNode_2* l_values){
  {
    struct f1_t : public bbGCFrame{
      t_std_collections_Stack_1Tt_mx2_PNode_2_Iterator l_0{};
      void gcMark(){
        bbGCMark(l_0);
      }
    }f1{};
    f1.l_0=l_values->m_All();
    for(;!f1.l_0.m_AtEnd();f1.l_0.m_Bump()){
      struct f2_t : public bbGCFrame{
        t_mx2_PNode* l_value{};
        void gcMark(){
          bbGCMarkPtr(l_value);
        }
      }f2{};
      f2.l_value=f1.l_0.m_Current();
      l_self->m_AddLast(f2.l_value);
    }
  }
}

void g_std_collections_List_1Tt_mx2_NamespaceScope_2_AddAll_1Tt_std_collections_List_1Tt_mx2_NamespaceScope_2_2(t_std_collections_List_1Tt_mx2_NamespaceScope_2* l_self,t_std_collections_List_1Tt_mx2_NamespaceScope_2* l_values){
  {
    struct f1_t : public bbGCFrame{
      t_std_collections_List_1Tt_mx2_NamespaceScope_2_Iterator l_0{};
      void gcMark(){
        bbGCMark(l_0);
      }
    }f1{};
    f1.l_0=l_values->m_All();
    for(;!f1.l_0.m_AtEnd();f1.l_0.m_Bump()){
      struct f2_t : public bbGCFrame{
        t_mx2_NamespaceScope* l_value{};
        void gcMark(){
          bbGCMarkPtr(l_value);
        }
      }f2{};
      f2.l_value=f1.l_0.m_Current();
      l_self->m_AddLast(f2.l_value);
    }
  }
}

void g_std_collections_List_1Tt_mx2_NamespaceScope_2_AddAll_1Tt_std_collections_Stack_1Tt_mx2_NamespaceScope_2_2(t_std_collections_List_1Tt_mx2_NamespaceScope_2* l_self,t_std_collections_Stack_1Tt_mx2_NamespaceScope_2* l_values){
  {
    struct f1_t : public bbGCFrame{
      t_std_collections_Stack_1Tt_mx2_NamespaceScope_2_Iterator l_0{};
      void gcMark(){
        bbGCMark(l_0);
      }
    }f1{};
    f1.l_0=l_values->m_All();
    for(;!f1.l_0.m_AtEnd();f1.l_0.m_Bump()){
      struct f2_t : public bbGCFrame{
        t_mx2_NamespaceScope* l_value{};
        void gcMark(){
          bbGCMarkPtr(l_value);
        }
      }f2{};
      f2.l_value=f1.l_0.m_Current();
      l_self->m_AddLast(f2.l_value);
    }
  }
}

void g_std_collections_List_1Tt_mx2_FileScope_2_AddAll_1Tt_std_collections_List_1Tt_mx2_FileScope_2_2(t_std_collections_List_1Tt_mx2_FileScope_2* l_self,t_std_collections_List_1Tt_mx2_FileScope_2* l_values){
  {
    struct f1_t : public bbGCFrame{
      t_std_collections_List_1Tt_mx2_FileScope_2_Iterator l_0{};
      void gcMark(){
        bbGCMark(l_0);
      }
    }f1{};
    f1.l_0=l_values->m_All();
    for(;!f1.l_0.m_AtEnd();f1.l_0.m_Bump()){
      struct f2_t : public bbGCFrame{
        t_mx2_FileScope* l_value{};
        void gcMark(){
          bbGCMarkPtr(l_value);
        }
      }f2{};
      f2.l_value=f1.l_0.m_Current();
      l_self->m_AddLast(f2.l_value);
    }
  }
}

void g_std_collections_List_1Tt_mx2_FileScope_2_AddAll_1Tt_std_collections_Stack_1Tt_mx2_FileScope_2_2(t_std_collections_List_1Tt_mx2_FileScope_2* l_self,t_std_collections_Stack_1Tt_mx2_FileScope_2* l_values){
  {
    struct f1_t : public bbGCFrame{
      t_std_collections_Stack_1Tt_mx2_FileScope_2_Iterator l_0{};
      void gcMark(){
        bbGCMark(l_0);
      }
    }f1{};
    f1.l_0=l_values->m_All();
    for(;!f1.l_0.m_AtEnd();f1.l_0.m_Bump()){
      struct f2_t : public bbGCFrame{
        t_mx2_FileScope* l_value{};
        void gcMark(){
          bbGCMarkPtr(l_value);
        }
      }f2{};
      f2.l_value=f1.l_0.m_Current();
      l_self->m_AddLast(f2.l_value);
    }
  }
}

void g_std_collections_List_1Tt_mx2_FileDecl_2_AddAll_1Tt_std_collections_List_1Tt_mx2_FileDecl_2_2(t_std_collections_List_1Tt_mx2_FileDecl_2* l_self,t_std_collections_List_1Tt_mx2_FileDecl_2* l_values){
  {
    struct f1_t : public bbGCFrame{
      t_std_collections_List_1Tt_mx2_FileDecl_2_Iterator l_0{};
      void gcMark(){
        bbGCMark(l_0);
      }
    }f1{};
    f1.l_0=l_values->m_All();
    for(;!f1.l_0.m_AtEnd();f1.l_0.m_Bump()){
      struct f2_t : public bbGCFrame{
        t_mx2_FileDecl* l_value{};
        void gcMark(){
          bbGCMarkPtr(l_value);
        }
      }f2{};
      f2.l_value=f1.l_0.m_Current();
      l_self->m_AddLast(f2.l_value);
    }
  }
}

void g_std_collections_List_1Tt_mx2_FileDecl_2_AddAll_1Tt_std_collections_Stack_1Tt_mx2_FileDecl_2_2(t_std_collections_List_1Tt_mx2_FileDecl_2* l_self,t_std_collections_Stack_1Tt_mx2_FileDecl_2* l_values){
  {
    struct f1_t : public bbGCFrame{
      t_std_collections_Stack_1Tt_mx2_FileDecl_2_Iterator l_0{};
      void gcMark(){
        bbGCMark(l_0);
      }
    }f1{};
    f1.l_0=l_values->m_All();
    for(;!f1.l_0.m_AtEnd();f1.l_0.m_Bump()){
      struct f2_t : public bbGCFrame{
        t_mx2_FileDecl* l_value{};
        void gcMark(){
          bbGCMarkPtr(l_value);
        }
      }f2{};
      f2.l_value=f1.l_0.m_Current();
      l_self->m_AddLast(f2.l_value);
    }
  }
}

void g_std_collections_List_1Tt_std_collections_Stack_1s_2_AddAll_1Tt_std_collections_List_1Tt_std_collections_Stack_1s_2_2(t_std_collections_List_1Tt_std_collections_Stack_1s_2* l_self,t_std_collections_List_1Tt_std_collections_Stack_1s_2* l_values){
  {
    struct f1_t : public bbGCFrame{
      t_std_collections_List_1Tt_std_collections_Stack_1s_2_Iterator l_0{};
      void gcMark(){
        bbGCMark(l_0);
      }
    }f1{};
    f1.l_0=l_values->m_All();
    for(;!f1.l_0.m_AtEnd();f1.l_0.m_Bump()){
      struct f2_t : public bbGCFrame{
        t_std_collections_Stack_1s* l_value{};
        void gcMark(){
          bbGCMarkPtr(l_value);
        }
      }f2{};
      f2.l_value=f1.l_0.m_Current();
      l_self->m_AddLast(f2.l_value);
    }
  }
}

void g_std_collections_List_1Tt_std_collections_Stack_1s_2_AddAll_1Tt_std_collections_Stack_1Tt_std_collections_Stack_1s_2_2(t_std_collections_List_1Tt_std_collections_Stack_1s_2* l_self,t_std_collections_Stack_1Tt_std_collections_Stack_1s_2* l_values){
  {
    struct f1_t : public bbGCFrame{
      t_std_collections_Stack_1Tt_std_collections_Stack_1s_2_Iterator l_0{};
      void gcMark(){
        bbGCMark(l_0);
      }
    }f1{};
    f1.l_0=l_values->m_All();
    for(;!f1.l_0.m_AtEnd();f1.l_0.m_Bump()){
      struct f2_t : public bbGCFrame{
        t_std_collections_Stack_1s* l_value{};
        void gcMark(){
          bbGCMarkPtr(l_value);
        }
      }f2{};
      f2.l_value=f1.l_0.m_Current();
      l_self->m_AddLast(f2.l_value);
    }
  }
}

void g_std_collections_List_1Tt_mx2_VarValue_2_AddAll_1Tt_std_collections_List_1Tt_mx2_VarValue_2_2(t_std_collections_List_1Tt_mx2_VarValue_2* l_self,t_std_collections_List_1Tt_mx2_VarValue_2* l_values){
  {
    struct f1_t : public bbGCFrame{
      t_std_collections_List_1Tt_mx2_VarValue_2_Iterator l_0{};
      void gcMark(){
        bbGCMark(l_0);
      }
    }f1{};
    f1.l_0=l_values->m_All();
    for(;!f1.l_0.m_AtEnd();f1.l_0.m_Bump()){
      struct f2_t : public bbGCFrame{
        t_mx2_VarValue* l_value{};
        void gcMark(){
          bbGCMarkPtr(l_value);
        }
      }f2{};
      f2.l_value=f1.l_0.m_Current();
      l_self->m_AddLast(f2.l_value);
    }
  }
}

void g_std_collections_List_1Tt_mx2_VarValue_2_AddAll_1Tt_std_collections_Stack_1Tt_mx2_VarValue_2_2(t_std_collections_List_1Tt_mx2_VarValue_2* l_self,t_std_collections_Stack_1Tt_mx2_VarValue_2* l_values){
  {
    struct f1_t : public bbGCFrame{
      t_std_collections_Stack_1Tt_mx2_VarValue_2_Iterator l_0{};
      void gcMark(){
        bbGCMark(l_0);
      }
    }f1{};
    f1.l_0=l_values->m_All();
    for(;!f1.l_0.m_AtEnd();f1.l_0.m_Bump()){
      struct f2_t : public bbGCFrame{
        t_mx2_VarValue* l_value{};
        void gcMark(){
          bbGCMarkPtr(l_value);
        }
      }f2{};
      f2.l_value=f1.l_0.m_Current();
      l_self->m_AddLast(f2.l_value);
    }
  }
}

void g_std_collections_List_1Tt_mx2_FuncList_2_AddAll_1Tt_std_collections_List_1Tt_mx2_FuncList_2_2(t_std_collections_List_1Tt_mx2_FuncList_2* l_self,t_std_collections_List_1Tt_mx2_FuncList_2* l_values){
  {
    struct f1_t : public bbGCFrame{
      t_std_collections_List_1Tt_mx2_FuncList_2_Iterator l_0{};
      void gcMark(){
        bbGCMark(l_0);
      }
    }f1{};
    f1.l_0=l_values->m_All();
    for(;!f1.l_0.m_AtEnd();f1.l_0.m_Bump()){
      struct f2_t : public bbGCFrame{
        t_mx2_FuncList* l_value{};
        void gcMark(){
          bbGCMarkPtr(l_value);
        }
      }f2{};
      f2.l_value=f1.l_0.m_Current();
      l_self->m_AddLast(f2.l_value);
    }
  }
}

void g_std_collections_List_1Tt_mx2_FuncList_2_AddAll_1Tt_std_collections_Stack_1Tt_mx2_FuncList_2_2(t_std_collections_List_1Tt_mx2_FuncList_2* l_self,t_std_collections_Stack_1Tt_mx2_FuncList_2* l_values){
  {
    struct f1_t : public bbGCFrame{
      t_std_collections_Stack_1Tt_mx2_FuncList_2_Iterator l_0{};
      void gcMark(){
        bbGCMark(l_0);
      }
    }f1{};
    f1.l_0=l_values->m_All();
    for(;!f1.l_0.m_AtEnd();f1.l_0.m_Bump()){
      struct f2_t : public bbGCFrame{
        t_mx2_FuncList* l_value{};
        void gcMark(){
          bbGCMarkPtr(l_value);
        }
      }f2{};
      f2.l_value=f1.l_0.m_Current();
      l_self->m_AddLast(f2.l_value);
    }
  }
}

void g_std_collections_List_1Tt_mx2_SNode_2_AddAll_1Tt_std_collections_List_1Tt_mx2_SNode_2_2(t_std_collections_List_1Tt_mx2_SNode_2* l_self,t_std_collections_List_1Tt_mx2_SNode_2* l_values){
  {
    struct f1_t : public bbGCFrame{
      t_std_collections_List_1Tt_mx2_SNode_2_Iterator l_0{};
      void gcMark(){
        bbGCMark(l_0);
      }
    }f1{};
    f1.l_0=l_values->m_All();
    for(;!f1.l_0.m_AtEnd();f1.l_0.m_Bump()){
      struct f2_t : public bbGCFrame{
        t_mx2_SNode* l_value{};
        void gcMark(){
          bbGCMarkPtr(l_value);
        }
      }f2{};
      f2.l_value=f1.l_0.m_Current();
      l_self->m_AddLast(f2.l_value);
    }
  }
}

void g_std_collections_List_1Tt_mx2_SNode_2_AddAll_1Tt_std_collections_Stack_1Tt_mx2_SNode_2_2(t_std_collections_List_1Tt_mx2_SNode_2* l_self,t_std_collections_Stack_1Tt_mx2_SNode_2* l_values){
  {
    struct f1_t : public bbGCFrame{
      t_std_collections_Stack_1Tt_mx2_SNode_2_Iterator l_0{};
      void gcMark(){
        bbGCMark(l_0);
      }
    }f1{};
    f1.l_0=l_values->m_All();
    for(;!f1.l_0.m_AtEnd();f1.l_0.m_Bump()){
      struct f2_t : public bbGCFrame{
        t_mx2_SNode* l_value{};
        void gcMark(){
          bbGCMarkPtr(l_value);
        }
      }f2{};
      f2.l_value=f1.l_0.m_Current();
      l_self->m_AddLast(f2.l_value);
    }
  }
}

void g_std_collections_List_1Tt_mx2_Scope_2_AddAll_1Tt_std_collections_List_1Tt_mx2_Scope_2_2(t_std_collections_List_1Tt_mx2_Scope_2* l_self,t_std_collections_List_1Tt_mx2_Scope_2* l_values){
  {
    struct f1_t : public bbGCFrame{
      t_std_collections_List_1Tt_mx2_Scope_2_Iterator l_0{};
      void gcMark(){
        bbGCMark(l_0);
      }
    }f1{};
    f1.l_0=l_values->m_All();
    for(;!f1.l_0.m_AtEnd();f1.l_0.m_Bump()){
      struct f2_t : public bbGCFrame{
        t_mx2_Scope* l_value{};
        void gcMark(){
          bbGCMarkPtr(l_value);
        }
      }f2{};
      f2.l_value=f1.l_0.m_Current();
      l_self->m_AddLast(f2.l_value);
    }
  }
}

void g_std_collections_List_1Tt_mx2_Scope_2_AddAll_1Tt_std_collections_Stack_1Tt_mx2_Scope_2_2(t_std_collections_List_1Tt_mx2_Scope_2* l_self,t_std_collections_Stack_1Tt_mx2_Scope_2* l_values){
  {
    struct f1_t : public bbGCFrame{
      t_std_collections_Stack_1Tt_mx2_Scope_2_Iterator l_0{};
      void gcMark(){
        bbGCMark(l_0);
      }
    }f1{};
    f1.l_0=l_values->m_All();
    for(;!f1.l_0.m_AtEnd();f1.l_0.m_Bump()){
      struct f2_t : public bbGCFrame{
        t_mx2_Scope* l_value{};
        void gcMark(){
          bbGCMarkPtr(l_value);
        }
      }f2{};
      f2.l_value=f1.l_0.m_Current();
      l_self->m_AddLast(f2.l_value);
    }
  }
}

void g_std_collections_List_1Tt_mx2_ClassType_2_AddAll_1Tt_std_collections_List_1Tt_mx2_ClassType_2_2(t_std_collections_List_1Tt_mx2_ClassType_2* l_self,t_std_collections_List_1Tt_mx2_ClassType_2* l_values){
  {
    struct f1_t : public bbGCFrame{
      t_std_collections_List_1Tt_mx2_ClassType_2_Iterator l_0{};
      void gcMark(){
        bbGCMark(l_0);
      }
    }f1{};
    f1.l_0=l_values->m_All();
    for(;!f1.l_0.m_AtEnd();f1.l_0.m_Bump()){
      struct f2_t : public bbGCFrame{
        t_mx2_ClassType* l_value{};
        void gcMark(){
          bbGCMarkPtr(l_value);
        }
      }f2{};
      f2.l_value=f1.l_0.m_Current();
      l_self->m_AddLast(f2.l_value);
    }
  }
}

void g_std_collections_List_1Tt_mx2_ClassType_2_AddAll_1Tt_std_collections_Stack_1Tt_mx2_ClassType_2_2(t_std_collections_List_1Tt_mx2_ClassType_2* l_self,t_std_collections_Stack_1Tt_mx2_ClassType_2* l_values){
  {
    struct f1_t : public bbGCFrame{
      t_std_collections_Stack_1Tt_mx2_ClassType_2_Iterator l_0{};
      void gcMark(){
        bbGCMark(l_0);
      }
    }f1{};
    f1.l_0=l_values->m_All();
    for(;!f1.l_0.m_AtEnd();f1.l_0.m_Bump()){
      struct f2_t : public bbGCFrame{
        t_mx2_ClassType* l_value{};
        void gcMark(){
          bbGCMarkPtr(l_value);
        }
      }f2{};
      f2.l_value=f1.l_0.m_Current();
      l_self->m_AddLast(f2.l_value);
    }
  }
}

void g_std_collections_List_1Tt_mx2_ErrorEx_2_AddAll_1Tt_std_collections_List_1Tt_mx2_ErrorEx_2_2(t_std_collections_List_1Tt_mx2_ErrorEx_2* l_self,t_std_collections_List_1Tt_mx2_ErrorEx_2* l_values){
  {
    struct f1_t : public bbGCFrame{
      t_std_collections_List_1Tt_mx2_ErrorEx_2_Iterator l_0{};
      void gcMark(){
        bbGCMark(l_0);
      }
    }f1{};
    f1.l_0=l_values->m_All();
    for(;!f1.l_0.m_AtEnd();f1.l_0.m_Bump()){
      struct f2_t : public bbGCFrame{
        t_mx2_ErrorEx* l_value{};
        void gcMark(){
          bbGCMarkPtr(l_value);
        }
      }f2{};
      f2.l_value=f1.l_0.m_Current();
      l_self->m_AddLast(f2.l_value);
    }
  }
}

void g_std_collections_List_1Tt_mx2_ErrorEx_2_AddAll_1Tt_std_collections_Stack_1Tt_mx2_ErrorEx_2_2(t_std_collections_List_1Tt_mx2_ErrorEx_2* l_self,t_std_collections_Stack_1Tt_mx2_ErrorEx_2* l_values){
  {
    struct f1_t : public bbGCFrame{
      t_std_collections_Stack_1Tt_mx2_ErrorEx_2_Iterator l_0{};
      void gcMark(){
        bbGCMark(l_0);
      }
    }f1{};
    f1.l_0=l_values->m_All();
    for(;!f1.l_0.m_AtEnd();f1.l_0.m_Bump()){
      struct f2_t : public bbGCFrame{
        t_mx2_ErrorEx* l_value{};
        void gcMark(){
          bbGCMarkPtr(l_value);
        }
      }f2{};
      f2.l_value=f1.l_0.m_Current();
      l_self->m_AddLast(f2.l_value);
    }
  }
}

void g_std_collections_List_1Tt_mx2_Module_2_AddAll_1Tt_std_collections_List_1Tt_mx2_Module_2_2(t_std_collections_List_1Tt_mx2_Module_2* l_self,t_std_collections_List_1Tt_mx2_Module_2* l_values){
  {
    struct f1_t : public bbGCFrame{
      t_std_collections_List_1Tt_mx2_Module_2_Iterator l_0{};
      void gcMark(){
        bbGCMark(l_0);
      }
    }f1{};
    f1.l_0=l_values->m_All();
    for(;!f1.l_0.m_AtEnd();f1.l_0.m_Bump()){
      struct f2_t : public bbGCFrame{
        t_mx2_Module* l_value{};
        void gcMark(){
          bbGCMarkPtr(l_value);
        }
      }f2{};
      f2.l_value=f1.l_0.m_Current();
      l_self->m_AddLast(f2.l_value);
    }
  }
}

void g_std_collections_List_1Tt_mx2_Module_2_AddAll_1Tt_std_collections_Stack_1Tt_mx2_Module_2_2(t_std_collections_List_1Tt_mx2_Module_2* l_self,t_std_collections_Stack_1Tt_mx2_Module_2* l_values){
  {
    struct f1_t : public bbGCFrame{
      t_std_collections_Stack_1Tt_mx2_Module_2_Iterator l_0{};
      void gcMark(){
        bbGCMark(l_0);
      }
    }f1{};
    f1.l_0=l_values->m_All();
    for(;!f1.l_0.m_AtEnd();f1.l_0.m_Bump()){
      struct f2_t : public bbGCFrame{
        t_mx2_Module* l_value{};
        void gcMark(){
          bbGCMarkPtr(l_value);
        }
      }f2{};
      f2.l_value=f1.l_0.m_Current();
      l_self->m_AddLast(f2.l_value);
    }
  }
}

void g_std_collections_List_1Tt_mx2_FuncValue_2_AddAll_1Tt_std_collections_List_1Tt_mx2_FuncValue_2_2(t_std_collections_List_1Tt_mx2_FuncValue_2* l_self,t_std_collections_List_1Tt_mx2_FuncValue_2* l_values){
  {
    struct f1_t : public bbGCFrame{
      t_std_collections_List_1Tt_mx2_FuncValue_2_Iterator l_0{};
      void gcMark(){
        bbGCMark(l_0);
      }
    }f1{};
    f1.l_0=l_values->m_All();
    for(;!f1.l_0.m_AtEnd();f1.l_0.m_Bump()){
      struct f2_t : public bbGCFrame{
        t_mx2_FuncValue* l_value{};
        void gcMark(){
          bbGCMarkPtr(l_value);
        }
      }f2{};
      f2.l_value=f1.l_0.m_Current();
      l_self->m_AddLast(f2.l_value);
    }
  }
}

void g_std_collections_List_1Tt_mx2_FuncValue_2_AddAll_1Tt_std_collections_Stack_1Tt_mx2_FuncValue_2_2(t_std_collections_List_1Tt_mx2_FuncValue_2* l_self,t_std_collections_Stack_1Tt_mx2_FuncValue_2* l_values){
  {
    struct f1_t : public bbGCFrame{
      t_std_collections_Stack_1Tt_mx2_FuncValue_2_Iterator l_0{};
      void gcMark(){
        bbGCMark(l_0);
      }
    }f1{};
    f1.l_0=l_values->m_All();
    for(;!f1.l_0.m_AtEnd();f1.l_0.m_Bump()){
      struct f2_t : public bbGCFrame{
        t_mx2_FuncValue* l_value{};
        void gcMark(){
          bbGCMarkPtr(l_value);
        }
      }f2{};
      f2.l_value=f1.l_0.m_Current();
      l_self->m_AddLast(f2.l_value);
    }
  }
}

void t_std_collections_List_1Tt_mx2_FuncValue_2_Node::gcMark(){
  bbGCMark(m__0succ);
  bbGCMark(m__0pred);
  bbGCMark(m__0value);
}

t_std_collections_List_1Tt_mx2_FuncValue_2_Node::t_std_collections_List_1Tt_mx2_FuncValue_2_Node(t_mx2_FuncValue* l_value,t_std_collections_List_1Tt_mx2_FuncValue_2_Node* l_succ){
  this->m__0value=l_value;
  this->m__0succ=l_succ;
  this->m__0pred=l_succ->m__0pred;
  this->m__0pred->m__0succ=this;
  l_succ->m__0pred=this;
}

t_std_collections_List_1Tt_mx2_FuncValue_2_Node::t_std_collections_List_1Tt_mx2_FuncValue_2_Node(t_mx2_FuncValue* l_value){
  this->m__0value=l_value;
  this->m__0succ=this;
  this->m__0pred=this;
}

void t_std_collections_List_1Tt_mx2_FuncValue_2_Node::m_Value(t_mx2_FuncValue* l_value){
  this->m__0value=l_value;
}

t_mx2_FuncValue* t_std_collections_List_1Tt_mx2_FuncValue_2_Node::m_Value(){
  return this->m__0value;
}

t_std_collections_List_1Tt_mx2_FuncValue_2_Node* t_std_collections_List_1Tt_mx2_FuncValue_2_Node::m_Succ(){
  return this->m__0succ;
}

void t_std_collections_List_1Tt_mx2_FuncValue_2_Node::m_Remove(){
  this->m__0succ->m__0pred=this->m__0pred;
  this->m__0pred->m__0succ=this->m__0succ;
}

t_std_collections_List_1Tt_mx2_FuncValue_2_Node* t_std_collections_List_1Tt_mx2_FuncValue_2_Node::m_Pred(){
  return this->m__0pred;
}

void t_std_collections_List_1Tt_mx2_FuncValue_2_Node::m_InsertBefore(t_std_collections_List_1Tt_mx2_FuncValue_2_Node* l_node){
  this->m__0succ=l_node;
  this->m__0pred=l_node->m__0pred;
  this->m__0pred->m__0succ=this;
  l_node->m__0pred=this;
}

void t_std_collections_List_1Tt_mx2_FuncValue_2_Node::m_InsertAfter(t_std_collections_List_1Tt_mx2_FuncValue_2_Node* l_node){
  this->m__0pred=l_node;
  this->m__0succ=l_node->m__0succ;
  this->m__0succ->m__0pred=this;
  l_node->m__0succ=this;
}

t_std_collections_List_1Tt_mx2_FuncValue_2_Iterator::t_std_collections_List_1Tt_mx2_FuncValue_2_Iterator(t_std_collections_List_1Tt_mx2_FuncValue_2* l_list,t_std_collections_List_1Tt_mx2_FuncValue_2_Node* l_node){
  (*this).m__0list=l_list;
  (*this).m__0node=l_node;
  (*this).m__0seq=l_list->m__0seq;
}

void t_std_collections_List_1Tt_mx2_FuncValue_2_Iterator::m_Insert(t_mx2_FuncValue* l_value){
  (*this).m_AssertSeq();
  (*this).m__0node=bbGCNew<t_std_collections_List_1Tt_mx2_FuncValue_2_Node>(l_value,(*this).m__0node);
  (*this).m__0list->m__0seq+=1;
  (*this).m__0seq=(*this).m__0list->m__0seq;
}

void t_std_collections_List_1Tt_mx2_FuncValue_2_Iterator::m_Erase(){
  (*this).m_AssertCurrent();
  (*this).m__0node=(*this).m__0node->m__0succ;
  (*this).m__0node->m__0pred->m_Remove();
  (*this).m__0list->m__0seq+=1;
  (*this).m__0seq=(*this).m__0list->m__0seq;
}

void t_std_collections_List_1Tt_mx2_FuncValue_2_Iterator::m_Current(t_mx2_FuncValue* l_current){
  (*this).m_AssertCurrent();
  (*this).m__0node->m__0value=l_current;
}

t_mx2_FuncValue* t_std_collections_List_1Tt_mx2_FuncValue_2_Iterator::m_Current(){
  (*this).m_AssertCurrent();
  return (*this).m__0node->m__0value;
}

void t_std_collections_List_1Tt_mx2_FuncValue_2_Iterator::m_Bump(){
  (*this).m_AssertCurrent();
  (*this).m__0node=(*this).m__0node->m__0succ;
}

bbBool t_std_collections_List_1Tt_mx2_FuncValue_2_Iterator::m_AtEnd(){
  (*this).m_AssertSeq();
  return ((*this).m__0node==(*this).m__0list->m__0head);
}

void t_std_collections_List_1Tt_mx2_FuncValue_2_Iterator::m_AssertSeq(){
  bbDebugAssert(((*this).m__0seq==(*this).m__0list->m__0seq),BB_T("Concurrent list modification"));
}

void t_std_collections_List_1Tt_mx2_FuncValue_2_Iterator::m_AssertCurrent(){
  bbDebugAssert(!(*this).m_AtEnd(),BB_T("Invalid list iterator"));
}

int bbCompare(const t_std_collections_List_1Tt_mx2_FuncValue_2_Iterator&x,const t_std_collections_List_1Tt_mx2_FuncValue_2_Iterator&y){
  if(int t=bbCompare(x.m__0list,y.m__0list)) return t;
  if(int t=bbCompare(x.m__0node,y.m__0node)) return t;
  if(int t=bbCompare(x.m__0seq,y.m__0seq)) return t;
  return 0;
}

void bbGCMark(const t_std_collections_List_1Tt_mx2_FuncValue_2_Iterator&t){
  bbGCMark(t.m__0list);
  bbGCMark(t.m__0node);
}

t_std_collections_List_1Tt_mx2_FuncValue_2_BackwardsIterator::t_std_collections_List_1Tt_mx2_FuncValue_2_BackwardsIterator(t_std_collections_List_1Tt_mx2_FuncValue_2* l_list,t_std_collections_List_1Tt_mx2_FuncValue_2_Node* l_node){
  (*this).m__0list=l_list;
  (*this).m__0node=l_node;
  (*this).m__0seq=l_list->m__0seq;
}

void t_std_collections_List_1Tt_mx2_FuncValue_2_BackwardsIterator::m_Insert(t_mx2_FuncValue* l_value){
  (*this).m_AssertSeq();
  (*this).m__0node=bbGCNew<t_std_collections_List_1Tt_mx2_FuncValue_2_Node>(l_value,(*this).m__0node->m__0succ);
  (*this).m__0list->m__0seq+=1;
  (*this).m__0seq=(*this).m__0list->m__0seq;
}

void t_std_collections_List_1Tt_mx2_FuncValue_2_BackwardsIterator::m_Erase(){
  (*this).m_AssertCurrent();
  (*this).m__0node=(*this).m__0node->m__0pred;
  (*this).m__0node->m__0succ->m_Remove();
  (*this).m__0list->m__0seq+=1;
  (*this).m__0seq=(*this).m__0list->m__0seq;
}

void t_std_collections_List_1Tt_mx2_FuncValue_2_BackwardsIterator::m_Current(t_mx2_FuncValue* l_current){
  (*this).m_AssertCurrent();
  (*this).m__0node->m__0value=l_current;
}

t_mx2_FuncValue* t_std_collections_List_1Tt_mx2_FuncValue_2_BackwardsIterator::m_Current(){
  (*this).m_AssertCurrent();
  return (*this).m__0node->m__0value;
}

void t_std_collections_List_1Tt_mx2_FuncValue_2_BackwardsIterator::m_Bump(){
  (*this).m_AssertCurrent();
  (*this).m__0node=(*this).m__0node->m__0pred;
}

bbBool t_std_collections_List_1Tt_mx2_FuncValue_2_BackwardsIterator::m_AtEnd(){
  (*this).m_AssertSeq();
  return ((*this).m__0node==(*this).m__0list->m__0head);
}

void t_std_collections_List_1Tt_mx2_FuncValue_2_BackwardsIterator::m_AssertSeq(){
  bbDebugAssert(((*this).m__0seq==(*this).m__0list->m__0seq),BB_T("Concurrent list modification"));
}

void t_std_collections_List_1Tt_mx2_FuncValue_2_BackwardsIterator::m_AssertCurrent(){
  bbDebugAssert(!(*this).m_AtEnd(),BB_T("Invalid list iterator"));
}

int bbCompare(const t_std_collections_List_1Tt_mx2_FuncValue_2_BackwardsIterator&x,const t_std_collections_List_1Tt_mx2_FuncValue_2_BackwardsIterator&y){
  if(int t=bbCompare(x.m__0list,y.m__0list)) return t;
  if(int t=bbCompare(x.m__0node,y.m__0node)) return t;
  if(int t=bbCompare(x.m__0seq,y.m__0seq)) return t;
  return 0;
}

void bbGCMark(const t_std_collections_List_1Tt_mx2_FuncValue_2_BackwardsIterator&t){
  bbGCMark(t.m__0list);
  bbGCMark(t.m__0node);
}

void t_std_collections_List_1Tt_mx2_FuncValue_2::gcMark(){
  bbGCMark(m__0head);
}

t_std_collections_List_1Tt_mx2_FuncValue_2::t_std_collections_List_1Tt_mx2_FuncValue_2(t_std_collections_List_1Tt_mx2_FuncValue_2* l_values):t_std_collections_List_1Tt_mx2_FuncValue_2(){
  g_std_collections_List_1Tt_mx2_FuncValue_2_AddAll_1Tt_std_collections_List_1Tt_mx2_FuncValue_2_2(this,l_values);
}

t_std_collections_List_1Tt_mx2_FuncValue_2::t_std_collections_List_1Tt_mx2_FuncValue_2(t_std_collections_Stack_1Tt_mx2_FuncValue_2* l_values):t_std_collections_List_1Tt_mx2_FuncValue_2(){
  g_std_collections_List_1Tt_mx2_FuncValue_2_AddAll_1Tt_std_collections_Stack_1Tt_mx2_FuncValue_2_2(this,l_values);
}

t_std_collections_List_1Tt_mx2_FuncValue_2::t_std_collections_List_1Tt_mx2_FuncValue_2(bbArray<bbGCVar<t_mx2_FuncValue>>* l_values):t_std_collections_List_1Tt_mx2_FuncValue_2(){
  this->m_AddAll(l_values);
}

t_std_collections_List_1Tt_mx2_FuncValue_2::t_std_collections_List_1Tt_mx2_FuncValue_2(){
  this->m__0head=bbGCNew<t_std_collections_List_1Tt_mx2_FuncValue_2_Node>(((t_mx2_FuncValue*)0));
}

bbArray<bbGCVar<t_mx2_FuncValue>>* t_std_collections_List_1Tt_mx2_FuncValue_2::m_ToArray(){
  struct f0_t : public bbGCFrame{
    bbArray<bbGCVar<t_mx2_FuncValue>>* l_data{};
    t_std_collections_List_1Tt_mx2_FuncValue_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_data);
      bbGCMarkPtr(l_node);
    }
  }f0{};
  bbInt l_n=this->m_Count();
  f0.l_data=bbArray<bbGCVar<t_mx2_FuncValue>>::create(l_n);
  f0.l_node=this->m__0head->m__0succ;
  {
    bbInt l_i=bbInt(0);
    for(;(l_i<l_n);l_i+=1){
      f0.l_data->at(l_i)=f0.l_node->m__0value;
      f0.l_node=f0.l_node->m__0succ;
    }
  }
  return f0.l_data;
}

void t_std_collections_List_1Tt_mx2_FuncValue_2::m_Sort(bbFunction<bbInt(t_mx2_FuncValue*,t_mx2_FuncValue*)> l_compareFunc){
  bbInt l_insize=1;
  for(;;){
    struct f1_t : public bbGCFrame{
      t_std_collections_List_1Tt_mx2_FuncValue_2_Node* l_p{};
      t_std_collections_List_1Tt_mx2_FuncValue_2_Node* l_tail{};
      void gcMark(){
        bbGCMarkPtr(l_p);
        bbGCMarkPtr(l_tail);
      }
    }f1{};
    bbInt l_merges=bbInt(0);
    f1.l_tail=this->m__0head;
    f1.l_p=this->m__0head->m__0succ;
    while((f1.l_p!=this->m__0head)){
      struct f2_t : public bbGCFrame{
        t_std_collections_List_1Tt_mx2_FuncValue_2_Node* l_q{};
        void gcMark(){
          bbGCMarkPtr(l_q);
        }
      }f2{};
      l_merges+=1;
      f2.l_q=f1.l_p->m__0succ;
      bbInt l_qsize=l_insize;
      bbInt l_psize=1;
      while(((l_psize<l_insize)&&(f2.l_q!=this->m__0head))){
        l_psize+=1;
        f2.l_q=f2.l_q->m__0succ;
      }
      for(;;){
        struct f3_t : public bbGCFrame{
          t_std_collections_List_1Tt_mx2_FuncValue_2_Node* l_t{};
          void gcMark(){
            bbGCMarkPtr(l_t);
          }
        }f3{};
        if(((bbBool(l_psize)&&bbBool(l_qsize))&&(f2.l_q!=this->m__0head))){
          bbInt l_cc=l_compareFunc(f1.l_p->m__0value,f2.l_q->m__0value);
          if((l_cc<=bbInt(0))){
            f3.l_t=f1.l_p;
            f1.l_p=f1.l_p->m__0succ;
            l_psize-=1;
          }else{
            f3.l_t=f2.l_q;
            f2.l_q=f2.l_q->m__0succ;
            l_qsize-=1;
          }
        }else if(bbBool(l_psize)){
          f3.l_t=f1.l_p;
          f1.l_p=f1.l_p->m__0succ;
          l_psize-=1;
        }else if((bbBool(l_qsize)&&(f2.l_q!=this->m__0head))){
          f3.l_t=f2.l_q;
          f2.l_q=f2.l_q->m__0succ;
          l_qsize-=1;
        }else{
          break;
        }
        f3.l_t->m__0pred=f1.l_tail;
        f1.l_tail->m__0succ=f3.l_t;
        f1.l_tail=f3.l_t;
      }
      f1.l_p=f2.l_q;
    }
    f1.l_tail->m__0succ=this->m__0head;
    this->m__0head->m__0pred=f1.l_tail;
    if((l_merges<=1)){
      return;
    }
    l_insize*=2;
  }
}

void t_std_collections_List_1Tt_mx2_FuncValue_2::m_Sort(bbBool l_ascending){
  if(l_ascending){
    struct lambda0 : public bbFunction<bbInt(t_mx2_FuncValue*,t_mx2_FuncValue*)>::Rep{
      t_std_collections_List_1Tt_mx2_FuncValue_2* l_self;
      lambda0(t_std_collections_List_1Tt_mx2_FuncValue_2* l_self):l_self(l_self){
      }
      bbInt invoke(t_mx2_FuncValue* l_x,t_mx2_FuncValue* l_y){
        return bbCompare(l_x,l_y);
      }
      void gcMark(){
        bbGCMarkPtr(l_self);
      }
    };
    this->m_Sort(bbFunction<bbInt(t_mx2_FuncValue*,t_mx2_FuncValue*)>(new lambda0(this)));
  }else{
    struct lambda1 : public bbFunction<bbInt(t_mx2_FuncValue*,t_mx2_FuncValue*)>::Rep{
      t_std_collections_List_1Tt_mx2_FuncValue_2* l_self;
      lambda1(t_std_collections_List_1Tt_mx2_FuncValue_2* l_self):l_self(l_self){
      }
      bbInt invoke(t_mx2_FuncValue* l_x,t_mx2_FuncValue* l_y){
        return -bbCompare(l_x,l_y);
      }
      void gcMark(){
        bbGCMarkPtr(l_self);
      }
    };
    this->m_Sort(bbFunction<bbInt(t_mx2_FuncValue*,t_mx2_FuncValue*)>(new lambda1(this)));
  }
}

t_mx2_FuncValue* t_std_collections_List_1Tt_mx2_FuncValue_2::m_RemoveLast(){
  struct f0_t : public bbGCFrame{
    t_mx2_FuncValue* l_value{};
    void gcMark(){
      bbGCMarkPtr(l_value);
    }
  }f0{};
  bbDebugAssert(!this->m_Empty(),BB_T("Debug assert failed"));
  f0.l_value=this->m__0head->m__0pred->m__0value;
  this->m__0head->m__0pred->m_Remove();
  this->m__0seq+=1;
  return f0.l_value;
}

bbBool t_std_collections_List_1Tt_mx2_FuncValue_2::m_RemoveLast(t_mx2_FuncValue* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_mx2_FuncValue_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m_FindLastNode(l_value);
  if(!bbBool(f0.l_node)){
    return false;
  }
  f0.l_node->m_Remove();
  this->m__0seq+=1;
  return true;
}

t_mx2_FuncValue* t_std_collections_List_1Tt_mx2_FuncValue_2::m_RemoveFirst(){
  struct f0_t : public bbGCFrame{
    t_mx2_FuncValue* l_value{};
    void gcMark(){
      bbGCMarkPtr(l_value);
    }
  }f0{};
  bbDebugAssert(!this->m_Empty(),BB_T("Debug assert failed"));
  f0.l_value=this->m__0head->m__0succ->m__0value;
  this->m__0head->m__0succ->m_Remove();
  this->m__0seq+=1;
  return f0.l_value;
}

bbInt t_std_collections_List_1Tt_mx2_FuncValue_2::m_RemoveEach(t_mx2_FuncValue* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_mx2_FuncValue_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m__0head->m__0succ;
  bbInt l_n=bbInt(0);
  while((f0.l_node!=this->m__0head)){
    if((f0.l_node->m__0value==l_value)){
      f0.l_node=f0.l_node->m__0succ;
      f0.l_node->m__0pred->m_Remove();
      l_n+=1;
    }else{
      f0.l_node=f0.l_node->m__0succ;
    }
  }
  if(bbBool(l_n)){
    this->m__0seq+=1;
  }
  return l_n;
}

bbBool t_std_collections_List_1Tt_mx2_FuncValue_2::m_Remove(t_mx2_FuncValue* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_mx2_FuncValue_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m_FindNode(l_value);
  if(!bbBool(f0.l_node)){
    return false;
  }
  f0.l_node->m_Remove();
  this->m__0seq+=1;
  return true;
}

t_std_collections_List_1Tt_mx2_FuncValue_2_Node* t_std_collections_List_1Tt_mx2_FuncValue_2::m_LastNode(){
  if(!this->m_Empty()){
    return this->m__0head->m__0pred;
  }
  return ((t_std_collections_List_1Tt_mx2_FuncValue_2_Node*)0);
}

t_mx2_FuncValue* t_std_collections_List_1Tt_mx2_FuncValue_2::m_Last(){
  bbDebugAssert(!this->m_Empty(),BB_T("Debug assert failed"));
  return this->m__0head->m__0pred->m__0value;
}

t_std_collections_List_1Tt_mx2_FuncValue_2_Node* t_std_collections_List_1Tt_mx2_FuncValue_2::m_HeadNode(){
  return this->m__0head;
}

t_std_collections_List_1Tt_mx2_FuncValue_2_Node* t_std_collections_List_1Tt_mx2_FuncValue_2::m_FirstNode(){
  if(!this->m_Empty()){
    return this->m__0head->m__0succ;
  }
  return ((t_std_collections_List_1Tt_mx2_FuncValue_2_Node*)0);
}

t_mx2_FuncValue* t_std_collections_List_1Tt_mx2_FuncValue_2::m_First(){
  bbDebugAssert(!this->m_Empty(),BB_T("Debug assert failed"));
  return this->m__0head->m__0succ->m__0value;
}

t_std_collections_List_1Tt_mx2_FuncValue_2_Node* t_std_collections_List_1Tt_mx2_FuncValue_2::m_FindNode(t_mx2_FuncValue* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_mx2_FuncValue_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m__0head->m__0succ;
  while((f0.l_node!=this->m__0head)){
    if((f0.l_node->m__0value==l_value)){
      return f0.l_node;
    }
    f0.l_node=f0.l_node->m__0succ;
  }
  return ((t_std_collections_List_1Tt_mx2_FuncValue_2_Node*)0);
}

t_std_collections_List_1Tt_mx2_FuncValue_2_Node* t_std_collections_List_1Tt_mx2_FuncValue_2::m_FindLastNode(t_mx2_FuncValue* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_mx2_FuncValue_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m__0head->m__0pred;
  while((f0.l_node!=this->m__0head)){
    if((f0.l_node->m__0value==l_value)){
      return f0.l_node;
    }
    f0.l_node=f0.l_node->m__0pred;
  }
  return ((t_std_collections_List_1Tt_mx2_FuncValue_2_Node*)0);
}

bbBool t_std_collections_List_1Tt_mx2_FuncValue_2::m_Empty(){
  return (this->m__0head->m__0succ==this->m__0head);
}

bbInt t_std_collections_List_1Tt_mx2_FuncValue_2::m_Count(){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_mx2_FuncValue_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m__0head->m__0succ;
  bbInt l_n=bbInt(0);
  while((f0.l_node!=this->m__0head)){
    f0.l_node=f0.l_node->m__0succ;
    l_n+=1;
  }
  return l_n;
}

void t_std_collections_List_1Tt_mx2_FuncValue_2::m_Clear(){
  this->m__0head->m__0succ=this->m__0head;
  this->m__0head->m__0pred=this->m__0head;
  this->m__0seq+=1;
}

t_std_collections_List_1Tt_mx2_FuncValue_2_BackwardsIterator t_std_collections_List_1Tt_mx2_FuncValue_2::m_Backwards(){
  return t_std_collections_List_1Tt_mx2_FuncValue_2_BackwardsIterator(this,this->m__0head->m__0pred);
}

t_std_collections_List_1Tt_mx2_FuncValue_2_Iterator t_std_collections_List_1Tt_mx2_FuncValue_2::m_All(){
  return t_std_collections_List_1Tt_mx2_FuncValue_2_Iterator(this,this->m__0head->m__0succ);
}

t_std_collections_List_1Tt_mx2_FuncValue_2_Node* t_std_collections_List_1Tt_mx2_FuncValue_2::m_AddLast(t_mx2_FuncValue* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_mx2_FuncValue_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=bbGCNew<t_std_collections_List_1Tt_mx2_FuncValue_2_Node>(l_value,this->m__0head);
  this->m__0seq+=1;
  return f0.l_node;
}

t_std_collections_List_1Tt_mx2_FuncValue_2_Node* t_std_collections_List_1Tt_mx2_FuncValue_2::m_AddFirst(t_mx2_FuncValue* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_mx2_FuncValue_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=bbGCNew<t_std_collections_List_1Tt_mx2_FuncValue_2_Node>(l_value,this->m__0head->m__0succ);
  this->m__0seq+=1;
  return f0.l_node;
}

void t_std_collections_List_1Tt_mx2_FuncValue_2::m_AddAll(bbArray<bbGCVar<t_mx2_FuncValue>>* l_values){
  {
    bbInt l_0=bbInt(0);
    bbInt l_1=l_values->length();
    for(;(l_0<l_1);l_0+=1){
      struct f2_t : public bbGCFrame{
        t_mx2_FuncValue* l_value{};
        void gcMark(){
          bbGCMarkPtr(l_value);
        }
      }f2{};
      f2.l_value=l_values->at(l_0);
      this->m_AddLast(f2.l_value);
    }
  }
}

void t_std_collections_List_1Tt_mx2_FuncValue_2::m_Add(t_mx2_FuncValue* l_value){
  this->m_AddLast(l_value);
}

void t_std_collections_List_1Tt_mx2_Module_2_Node::gcMark(){
  bbGCMark(m__0succ);
  bbGCMark(m__0pred);
  bbGCMark(m__0value);
}

t_std_collections_List_1Tt_mx2_Module_2_Node::t_std_collections_List_1Tt_mx2_Module_2_Node(t_mx2_Module* l_value,t_std_collections_List_1Tt_mx2_Module_2_Node* l_succ){
  this->m__0value=l_value;
  this->m__0succ=l_succ;
  this->m__0pred=l_succ->m__0pred;
  this->m__0pred->m__0succ=this;
  l_succ->m__0pred=this;
}

t_std_collections_List_1Tt_mx2_Module_2_Node::t_std_collections_List_1Tt_mx2_Module_2_Node(t_mx2_Module* l_value){
  this->m__0value=l_value;
  this->m__0succ=this;
  this->m__0pred=this;
}

void t_std_collections_List_1Tt_mx2_Module_2_Node::m_Value(t_mx2_Module* l_value){
  this->m__0value=l_value;
}

t_mx2_Module* t_std_collections_List_1Tt_mx2_Module_2_Node::m_Value(){
  return this->m__0value;
}

t_std_collections_List_1Tt_mx2_Module_2_Node* t_std_collections_List_1Tt_mx2_Module_2_Node::m_Succ(){
  return this->m__0succ;
}

void t_std_collections_List_1Tt_mx2_Module_2_Node::m_Remove(){
  this->m__0succ->m__0pred=this->m__0pred;
  this->m__0pred->m__0succ=this->m__0succ;
}

t_std_collections_List_1Tt_mx2_Module_2_Node* t_std_collections_List_1Tt_mx2_Module_2_Node::m_Pred(){
  return this->m__0pred;
}

void t_std_collections_List_1Tt_mx2_Module_2_Node::m_InsertBefore(t_std_collections_List_1Tt_mx2_Module_2_Node* l_node){
  this->m__0succ=l_node;
  this->m__0pred=l_node->m__0pred;
  this->m__0pred->m__0succ=this;
  l_node->m__0pred=this;
}

void t_std_collections_List_1Tt_mx2_Module_2_Node::m_InsertAfter(t_std_collections_List_1Tt_mx2_Module_2_Node* l_node){
  this->m__0pred=l_node;
  this->m__0succ=l_node->m__0succ;
  this->m__0succ->m__0pred=this;
  l_node->m__0succ=this;
}

t_std_collections_List_1Tt_mx2_Module_2_Iterator::t_std_collections_List_1Tt_mx2_Module_2_Iterator(t_std_collections_List_1Tt_mx2_Module_2* l_list,t_std_collections_List_1Tt_mx2_Module_2_Node* l_node){
  (*this).m__0list=l_list;
  (*this).m__0node=l_node;
  (*this).m__0seq=l_list->m__0seq;
}

void t_std_collections_List_1Tt_mx2_Module_2_Iterator::m_Insert(t_mx2_Module* l_value){
  (*this).m_AssertSeq();
  (*this).m__0node=bbGCNew<t_std_collections_List_1Tt_mx2_Module_2_Node>(l_value,(*this).m__0node);
  (*this).m__0list->m__0seq+=1;
  (*this).m__0seq=(*this).m__0list->m__0seq;
}

void t_std_collections_List_1Tt_mx2_Module_2_Iterator::m_Erase(){
  (*this).m_AssertCurrent();
  (*this).m__0node=(*this).m__0node->m__0succ;
  (*this).m__0node->m__0pred->m_Remove();
  (*this).m__0list->m__0seq+=1;
  (*this).m__0seq=(*this).m__0list->m__0seq;
}

void t_std_collections_List_1Tt_mx2_Module_2_Iterator::m_Current(t_mx2_Module* l_current){
  (*this).m_AssertCurrent();
  (*this).m__0node->m__0value=l_current;
}

t_mx2_Module* t_std_collections_List_1Tt_mx2_Module_2_Iterator::m_Current(){
  (*this).m_AssertCurrent();
  return (*this).m__0node->m__0value;
}

void t_std_collections_List_1Tt_mx2_Module_2_Iterator::m_Bump(){
  (*this).m_AssertCurrent();
  (*this).m__0node=(*this).m__0node->m__0succ;
}

bbBool t_std_collections_List_1Tt_mx2_Module_2_Iterator::m_AtEnd(){
  (*this).m_AssertSeq();
  return ((*this).m__0node==(*this).m__0list->m__0head);
}

void t_std_collections_List_1Tt_mx2_Module_2_Iterator::m_AssertSeq(){
  bbDebugAssert(((*this).m__0seq==(*this).m__0list->m__0seq),BB_T("Concurrent list modification"));
}

void t_std_collections_List_1Tt_mx2_Module_2_Iterator::m_AssertCurrent(){
  bbDebugAssert(!(*this).m_AtEnd(),BB_T("Invalid list iterator"));
}

int bbCompare(const t_std_collections_List_1Tt_mx2_Module_2_Iterator&x,const t_std_collections_List_1Tt_mx2_Module_2_Iterator&y){
  if(int t=bbCompare(x.m__0list,y.m__0list)) return t;
  if(int t=bbCompare(x.m__0node,y.m__0node)) return t;
  if(int t=bbCompare(x.m__0seq,y.m__0seq)) return t;
  return 0;
}

void bbGCMark(const t_std_collections_List_1Tt_mx2_Module_2_Iterator&t){
  bbGCMark(t.m__0list);
  bbGCMark(t.m__0node);
}

t_std_collections_List_1Tt_mx2_Module_2_BackwardsIterator::t_std_collections_List_1Tt_mx2_Module_2_BackwardsIterator(t_std_collections_List_1Tt_mx2_Module_2* l_list,t_std_collections_List_1Tt_mx2_Module_2_Node* l_node){
  (*this).m__0list=l_list;
  (*this).m__0node=l_node;
  (*this).m__0seq=l_list->m__0seq;
}

void t_std_collections_List_1Tt_mx2_Module_2_BackwardsIterator::m_Insert(t_mx2_Module* l_value){
  (*this).m_AssertSeq();
  (*this).m__0node=bbGCNew<t_std_collections_List_1Tt_mx2_Module_2_Node>(l_value,(*this).m__0node->m__0succ);
  (*this).m__0list->m__0seq+=1;
  (*this).m__0seq=(*this).m__0list->m__0seq;
}

void t_std_collections_List_1Tt_mx2_Module_2_BackwardsIterator::m_Erase(){
  (*this).m_AssertCurrent();
  (*this).m__0node=(*this).m__0node->m__0pred;
  (*this).m__0node->m__0succ->m_Remove();
  (*this).m__0list->m__0seq+=1;
  (*this).m__0seq=(*this).m__0list->m__0seq;
}

void t_std_collections_List_1Tt_mx2_Module_2_BackwardsIterator::m_Current(t_mx2_Module* l_current){
  (*this).m_AssertCurrent();
  (*this).m__0node->m__0value=l_current;
}

t_mx2_Module* t_std_collections_List_1Tt_mx2_Module_2_BackwardsIterator::m_Current(){
  (*this).m_AssertCurrent();
  return (*this).m__0node->m__0value;
}

void t_std_collections_List_1Tt_mx2_Module_2_BackwardsIterator::m_Bump(){
  (*this).m_AssertCurrent();
  (*this).m__0node=(*this).m__0node->m__0pred;
}

bbBool t_std_collections_List_1Tt_mx2_Module_2_BackwardsIterator::m_AtEnd(){
  (*this).m_AssertSeq();
  return ((*this).m__0node==(*this).m__0list->m__0head);
}

void t_std_collections_List_1Tt_mx2_Module_2_BackwardsIterator::m_AssertSeq(){
  bbDebugAssert(((*this).m__0seq==(*this).m__0list->m__0seq),BB_T("Concurrent list modification"));
}

void t_std_collections_List_1Tt_mx2_Module_2_BackwardsIterator::m_AssertCurrent(){
  bbDebugAssert(!(*this).m_AtEnd(),BB_T("Invalid list iterator"));
}

int bbCompare(const t_std_collections_List_1Tt_mx2_Module_2_BackwardsIterator&x,const t_std_collections_List_1Tt_mx2_Module_2_BackwardsIterator&y){
  if(int t=bbCompare(x.m__0list,y.m__0list)) return t;
  if(int t=bbCompare(x.m__0node,y.m__0node)) return t;
  if(int t=bbCompare(x.m__0seq,y.m__0seq)) return t;
  return 0;
}

void bbGCMark(const t_std_collections_List_1Tt_mx2_Module_2_BackwardsIterator&t){
  bbGCMark(t.m__0list);
  bbGCMark(t.m__0node);
}

void t_std_collections_List_1Tt_mx2_Module_2::gcMark(){
  bbGCMark(m__0head);
}

t_std_collections_List_1Tt_mx2_Module_2::t_std_collections_List_1Tt_mx2_Module_2(t_std_collections_List_1Tt_mx2_Module_2* l_values):t_std_collections_List_1Tt_mx2_Module_2(){
  g_std_collections_List_1Tt_mx2_Module_2_AddAll_1Tt_std_collections_List_1Tt_mx2_Module_2_2(this,l_values);
}

t_std_collections_List_1Tt_mx2_Module_2::t_std_collections_List_1Tt_mx2_Module_2(t_std_collections_Stack_1Tt_mx2_Module_2* l_values):t_std_collections_List_1Tt_mx2_Module_2(){
  g_std_collections_List_1Tt_mx2_Module_2_AddAll_1Tt_std_collections_Stack_1Tt_mx2_Module_2_2(this,l_values);
}

t_std_collections_List_1Tt_mx2_Module_2::t_std_collections_List_1Tt_mx2_Module_2(bbArray<bbGCVar<t_mx2_Module>>* l_values):t_std_collections_List_1Tt_mx2_Module_2(){
  this->m_AddAll(l_values);
}

t_std_collections_List_1Tt_mx2_Module_2::t_std_collections_List_1Tt_mx2_Module_2(){
  this->m__0head=bbGCNew<t_std_collections_List_1Tt_mx2_Module_2_Node>(((t_mx2_Module*)0));
}

bbArray<bbGCVar<t_mx2_Module>>* t_std_collections_List_1Tt_mx2_Module_2::m_ToArray(){
  struct f0_t : public bbGCFrame{
    bbArray<bbGCVar<t_mx2_Module>>* l_data{};
    t_std_collections_List_1Tt_mx2_Module_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_data);
      bbGCMarkPtr(l_node);
    }
  }f0{};
  bbInt l_n=this->m_Count();
  f0.l_data=bbArray<bbGCVar<t_mx2_Module>>::create(l_n);
  f0.l_node=this->m__0head->m__0succ;
  {
    bbInt l_i=bbInt(0);
    for(;(l_i<l_n);l_i+=1){
      f0.l_data->at(l_i)=f0.l_node->m__0value;
      f0.l_node=f0.l_node->m__0succ;
    }
  }
  return f0.l_data;
}

void t_std_collections_List_1Tt_mx2_Module_2::m_Sort(bbFunction<bbInt(t_mx2_Module*,t_mx2_Module*)> l_compareFunc){
  bbInt l_insize=1;
  for(;;){
    struct f1_t : public bbGCFrame{
      t_std_collections_List_1Tt_mx2_Module_2_Node* l_p{};
      t_std_collections_List_1Tt_mx2_Module_2_Node* l_tail{};
      void gcMark(){
        bbGCMarkPtr(l_p);
        bbGCMarkPtr(l_tail);
      }
    }f1{};
    bbInt l_merges=bbInt(0);
    f1.l_tail=this->m__0head;
    f1.l_p=this->m__0head->m__0succ;
    while((f1.l_p!=this->m__0head)){
      struct f2_t : public bbGCFrame{
        t_std_collections_List_1Tt_mx2_Module_2_Node* l_q{};
        void gcMark(){
          bbGCMarkPtr(l_q);
        }
      }f2{};
      l_merges+=1;
      f2.l_q=f1.l_p->m__0succ;
      bbInt l_qsize=l_insize;
      bbInt l_psize=1;
      while(((l_psize<l_insize)&&(f2.l_q!=this->m__0head))){
        l_psize+=1;
        f2.l_q=f2.l_q->m__0succ;
      }
      for(;;){
        struct f3_t : public bbGCFrame{
          t_std_collections_List_1Tt_mx2_Module_2_Node* l_t{};
          void gcMark(){
            bbGCMarkPtr(l_t);
          }
        }f3{};
        if(((bbBool(l_psize)&&bbBool(l_qsize))&&(f2.l_q!=this->m__0head))){
          bbInt l_cc=l_compareFunc(f1.l_p->m__0value,f2.l_q->m__0value);
          if((l_cc<=bbInt(0))){
            f3.l_t=f1.l_p;
            f1.l_p=f1.l_p->m__0succ;
            l_psize-=1;
          }else{
            f3.l_t=f2.l_q;
            f2.l_q=f2.l_q->m__0succ;
            l_qsize-=1;
          }
        }else if(bbBool(l_psize)){
          f3.l_t=f1.l_p;
          f1.l_p=f1.l_p->m__0succ;
          l_psize-=1;
        }else if((bbBool(l_qsize)&&(f2.l_q!=this->m__0head))){
          f3.l_t=f2.l_q;
          f2.l_q=f2.l_q->m__0succ;
          l_qsize-=1;
        }else{
          break;
        }
        f3.l_t->m__0pred=f1.l_tail;
        f1.l_tail->m__0succ=f3.l_t;
        f1.l_tail=f3.l_t;
      }
      f1.l_p=f2.l_q;
    }
    f1.l_tail->m__0succ=this->m__0head;
    this->m__0head->m__0pred=f1.l_tail;
    if((l_merges<=1)){
      return;
    }
    l_insize*=2;
  }
}

void t_std_collections_List_1Tt_mx2_Module_2::m_Sort(bbBool l_ascending){
  if(l_ascending){
    struct lambda2 : public bbFunction<bbInt(t_mx2_Module*,t_mx2_Module*)>::Rep{
      t_std_collections_List_1Tt_mx2_Module_2* l_self;
      lambda2(t_std_collections_List_1Tt_mx2_Module_2* l_self):l_self(l_self){
      }
      bbInt invoke(t_mx2_Module* l_x,t_mx2_Module* l_y){
        return bbCompare(l_x,l_y);
      }
      void gcMark(){
        bbGCMarkPtr(l_self);
      }
    };
    this->m_Sort(bbFunction<bbInt(t_mx2_Module*,t_mx2_Module*)>(new lambda2(this)));
  }else{
    struct lambda3 : public bbFunction<bbInt(t_mx2_Module*,t_mx2_Module*)>::Rep{
      t_std_collections_List_1Tt_mx2_Module_2* l_self;
      lambda3(t_std_collections_List_1Tt_mx2_Module_2* l_self):l_self(l_self){
      }
      bbInt invoke(t_mx2_Module* l_x,t_mx2_Module* l_y){
        return -bbCompare(l_x,l_y);
      }
      void gcMark(){
        bbGCMarkPtr(l_self);
      }
    };
    this->m_Sort(bbFunction<bbInt(t_mx2_Module*,t_mx2_Module*)>(new lambda3(this)));
  }
}

t_mx2_Module* t_std_collections_List_1Tt_mx2_Module_2::m_RemoveLast(){
  struct f0_t : public bbGCFrame{
    t_mx2_Module* l_value{};
    void gcMark(){
      bbGCMarkPtr(l_value);
    }
  }f0{};
  bbDebugAssert(!this->m_Empty(),BB_T("Debug assert failed"));
  f0.l_value=this->m__0head->m__0pred->m__0value;
  this->m__0head->m__0pred->m_Remove();
  this->m__0seq+=1;
  return f0.l_value;
}

bbBool t_std_collections_List_1Tt_mx2_Module_2::m_RemoveLast(t_mx2_Module* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_mx2_Module_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m_FindLastNode(l_value);
  if(!bbBool(f0.l_node)){
    return false;
  }
  f0.l_node->m_Remove();
  this->m__0seq+=1;
  return true;
}

t_mx2_Module* t_std_collections_List_1Tt_mx2_Module_2::m_RemoveFirst(){
  struct f0_t : public bbGCFrame{
    t_mx2_Module* l_value{};
    void gcMark(){
      bbGCMarkPtr(l_value);
    }
  }f0{};
  bbDebugAssert(!this->m_Empty(),BB_T("Debug assert failed"));
  f0.l_value=this->m__0head->m__0succ->m__0value;
  this->m__0head->m__0succ->m_Remove();
  this->m__0seq+=1;
  return f0.l_value;
}

bbInt t_std_collections_List_1Tt_mx2_Module_2::m_RemoveEach(t_mx2_Module* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_mx2_Module_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m__0head->m__0succ;
  bbInt l_n=bbInt(0);
  while((f0.l_node!=this->m__0head)){
    if((f0.l_node->m__0value==l_value)){
      f0.l_node=f0.l_node->m__0succ;
      f0.l_node->m__0pred->m_Remove();
      l_n+=1;
    }else{
      f0.l_node=f0.l_node->m__0succ;
    }
  }
  if(bbBool(l_n)){
    this->m__0seq+=1;
  }
  return l_n;
}

bbBool t_std_collections_List_1Tt_mx2_Module_2::m_Remove(t_mx2_Module* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_mx2_Module_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m_FindNode(l_value);
  if(!bbBool(f0.l_node)){
    return false;
  }
  f0.l_node->m_Remove();
  this->m__0seq+=1;
  return true;
}

t_std_collections_List_1Tt_mx2_Module_2_Node* t_std_collections_List_1Tt_mx2_Module_2::m_LastNode(){
  if(!this->m_Empty()){
    return this->m__0head->m__0pred;
  }
  return ((t_std_collections_List_1Tt_mx2_Module_2_Node*)0);
}

t_mx2_Module* t_std_collections_List_1Tt_mx2_Module_2::m_Last(){
  bbDebugAssert(!this->m_Empty(),BB_T("Debug assert failed"));
  return this->m__0head->m__0pred->m__0value;
}

t_std_collections_List_1Tt_mx2_Module_2_Node* t_std_collections_List_1Tt_mx2_Module_2::m_HeadNode(){
  return this->m__0head;
}

t_std_collections_List_1Tt_mx2_Module_2_Node* t_std_collections_List_1Tt_mx2_Module_2::m_FirstNode(){
  if(!this->m_Empty()){
    return this->m__0head->m__0succ;
  }
  return ((t_std_collections_List_1Tt_mx2_Module_2_Node*)0);
}

t_mx2_Module* t_std_collections_List_1Tt_mx2_Module_2::m_First(){
  bbDebugAssert(!this->m_Empty(),BB_T("Debug assert failed"));
  return this->m__0head->m__0succ->m__0value;
}

t_std_collections_List_1Tt_mx2_Module_2_Node* t_std_collections_List_1Tt_mx2_Module_2::m_FindNode(t_mx2_Module* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_mx2_Module_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m__0head->m__0succ;
  while((f0.l_node!=this->m__0head)){
    if((f0.l_node->m__0value==l_value)){
      return f0.l_node;
    }
    f0.l_node=f0.l_node->m__0succ;
  }
  return ((t_std_collections_List_1Tt_mx2_Module_2_Node*)0);
}

t_std_collections_List_1Tt_mx2_Module_2_Node* t_std_collections_List_1Tt_mx2_Module_2::m_FindLastNode(t_mx2_Module* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_mx2_Module_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m__0head->m__0pred;
  while((f0.l_node!=this->m__0head)){
    if((f0.l_node->m__0value==l_value)){
      return f0.l_node;
    }
    f0.l_node=f0.l_node->m__0pred;
  }
  return ((t_std_collections_List_1Tt_mx2_Module_2_Node*)0);
}

bbBool t_std_collections_List_1Tt_mx2_Module_2::m_Empty(){
  return (this->m__0head->m__0succ==this->m__0head);
}

bbInt t_std_collections_List_1Tt_mx2_Module_2::m_Count(){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_mx2_Module_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m__0head->m__0succ;
  bbInt l_n=bbInt(0);
  while((f0.l_node!=this->m__0head)){
    f0.l_node=f0.l_node->m__0succ;
    l_n+=1;
  }
  return l_n;
}

void t_std_collections_List_1Tt_mx2_Module_2::m_Clear(){
  this->m__0head->m__0succ=this->m__0head;
  this->m__0head->m__0pred=this->m__0head;
  this->m__0seq+=1;
}

t_std_collections_List_1Tt_mx2_Module_2_BackwardsIterator t_std_collections_List_1Tt_mx2_Module_2::m_Backwards(){
  return t_std_collections_List_1Tt_mx2_Module_2_BackwardsIterator(this,this->m__0head->m__0pred);
}

t_std_collections_List_1Tt_mx2_Module_2_Iterator t_std_collections_List_1Tt_mx2_Module_2::m_All(){
  return t_std_collections_List_1Tt_mx2_Module_2_Iterator(this,this->m__0head->m__0succ);
}

t_std_collections_List_1Tt_mx2_Module_2_Node* t_std_collections_List_1Tt_mx2_Module_2::m_AddLast(t_mx2_Module* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_mx2_Module_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=bbGCNew<t_std_collections_List_1Tt_mx2_Module_2_Node>(l_value,this->m__0head);
  this->m__0seq+=1;
  return f0.l_node;
}

t_std_collections_List_1Tt_mx2_Module_2_Node* t_std_collections_List_1Tt_mx2_Module_2::m_AddFirst(t_mx2_Module* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_mx2_Module_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=bbGCNew<t_std_collections_List_1Tt_mx2_Module_2_Node>(l_value,this->m__0head->m__0succ);
  this->m__0seq+=1;
  return f0.l_node;
}

void t_std_collections_List_1Tt_mx2_Module_2::m_AddAll(bbArray<bbGCVar<t_mx2_Module>>* l_values){
  {
    bbInt l_0=bbInt(0);
    bbInt l_1=l_values->length();
    for(;(l_0<l_1);l_0+=1){
      struct f2_t : public bbGCFrame{
        t_mx2_Module* l_value{};
        void gcMark(){
          bbGCMarkPtr(l_value);
        }
      }f2{};
      f2.l_value=l_values->at(l_0);
      this->m_AddLast(f2.l_value);
    }
  }
}

void t_std_collections_List_1Tt_mx2_Module_2::m_Add(t_mx2_Module* l_value){
  this->m_AddLast(l_value);
}

void t_std_collections_List_1Tt_mx2_ErrorEx_2_Node::gcMark(){
  bbGCMark(m__0succ);
  bbGCMark(m__0pred);
  bbGCMark(m__0value);
}

t_std_collections_List_1Tt_mx2_ErrorEx_2_Node::t_std_collections_List_1Tt_mx2_ErrorEx_2_Node(t_mx2_ErrorEx* l_value,t_std_collections_List_1Tt_mx2_ErrorEx_2_Node* l_succ){
  this->m__0value=l_value;
  this->m__0succ=l_succ;
  this->m__0pred=l_succ->m__0pred;
  this->m__0pred->m__0succ=this;
  l_succ->m__0pred=this;
}

t_std_collections_List_1Tt_mx2_ErrorEx_2_Node::t_std_collections_List_1Tt_mx2_ErrorEx_2_Node(t_mx2_ErrorEx* l_value){
  this->m__0value=l_value;
  this->m__0succ=this;
  this->m__0pred=this;
}

void t_std_collections_List_1Tt_mx2_ErrorEx_2_Node::m_Value(t_mx2_ErrorEx* l_value){
  this->m__0value=l_value;
}

t_mx2_ErrorEx* t_std_collections_List_1Tt_mx2_ErrorEx_2_Node::m_Value(){
  return this->m__0value;
}

t_std_collections_List_1Tt_mx2_ErrorEx_2_Node* t_std_collections_List_1Tt_mx2_ErrorEx_2_Node::m_Succ(){
  return this->m__0succ;
}

void t_std_collections_List_1Tt_mx2_ErrorEx_2_Node::m_Remove(){
  this->m__0succ->m__0pred=this->m__0pred;
  this->m__0pred->m__0succ=this->m__0succ;
}

t_std_collections_List_1Tt_mx2_ErrorEx_2_Node* t_std_collections_List_1Tt_mx2_ErrorEx_2_Node::m_Pred(){
  return this->m__0pred;
}

void t_std_collections_List_1Tt_mx2_ErrorEx_2_Node::m_InsertBefore(t_std_collections_List_1Tt_mx2_ErrorEx_2_Node* l_node){
  this->m__0succ=l_node;
  this->m__0pred=l_node->m__0pred;
  this->m__0pred->m__0succ=this;
  l_node->m__0pred=this;
}

void t_std_collections_List_1Tt_mx2_ErrorEx_2_Node::m_InsertAfter(t_std_collections_List_1Tt_mx2_ErrorEx_2_Node* l_node){
  this->m__0pred=l_node;
  this->m__0succ=l_node->m__0succ;
  this->m__0succ->m__0pred=this;
  l_node->m__0succ=this;
}

t_std_collections_List_1Tt_mx2_ErrorEx_2_Iterator::t_std_collections_List_1Tt_mx2_ErrorEx_2_Iterator(t_std_collections_List_1Tt_mx2_ErrorEx_2* l_list,t_std_collections_List_1Tt_mx2_ErrorEx_2_Node* l_node){
  (*this).m__0list=l_list;
  (*this).m__0node=l_node;
  (*this).m__0seq=l_list->m__0seq;
}

void t_std_collections_List_1Tt_mx2_ErrorEx_2_Iterator::m_Insert(t_mx2_ErrorEx* l_value){
  (*this).m_AssertSeq();
  (*this).m__0node=bbGCNew<t_std_collections_List_1Tt_mx2_ErrorEx_2_Node>(l_value,(*this).m__0node);
  (*this).m__0list->m__0seq+=1;
  (*this).m__0seq=(*this).m__0list->m__0seq;
}

void t_std_collections_List_1Tt_mx2_ErrorEx_2_Iterator::m_Erase(){
  (*this).m_AssertCurrent();
  (*this).m__0node=(*this).m__0node->m__0succ;
  (*this).m__0node->m__0pred->m_Remove();
  (*this).m__0list->m__0seq+=1;
  (*this).m__0seq=(*this).m__0list->m__0seq;
}

void t_std_collections_List_1Tt_mx2_ErrorEx_2_Iterator::m_Current(t_mx2_ErrorEx* l_current){
  (*this).m_AssertCurrent();
  (*this).m__0node->m__0value=l_current;
}

t_mx2_ErrorEx* t_std_collections_List_1Tt_mx2_ErrorEx_2_Iterator::m_Current(){
  (*this).m_AssertCurrent();
  return (*this).m__0node->m__0value;
}

void t_std_collections_List_1Tt_mx2_ErrorEx_2_Iterator::m_Bump(){
  (*this).m_AssertCurrent();
  (*this).m__0node=(*this).m__0node->m__0succ;
}

bbBool t_std_collections_List_1Tt_mx2_ErrorEx_2_Iterator::m_AtEnd(){
  (*this).m_AssertSeq();
  return ((*this).m__0node==(*this).m__0list->m__0head);
}

void t_std_collections_List_1Tt_mx2_ErrorEx_2_Iterator::m_AssertSeq(){
  bbDebugAssert(((*this).m__0seq==(*this).m__0list->m__0seq),BB_T("Concurrent list modification"));
}

void t_std_collections_List_1Tt_mx2_ErrorEx_2_Iterator::m_AssertCurrent(){
  bbDebugAssert(!(*this).m_AtEnd(),BB_T("Invalid list iterator"));
}

int bbCompare(const t_std_collections_List_1Tt_mx2_ErrorEx_2_Iterator&x,const t_std_collections_List_1Tt_mx2_ErrorEx_2_Iterator&y){
  if(int t=bbCompare(x.m__0list,y.m__0list)) return t;
  if(int t=bbCompare(x.m__0node,y.m__0node)) return t;
  if(int t=bbCompare(x.m__0seq,y.m__0seq)) return t;
  return 0;
}

void bbGCMark(const t_std_collections_List_1Tt_mx2_ErrorEx_2_Iterator&t){
  bbGCMark(t.m__0list);
  bbGCMark(t.m__0node);
}

t_std_collections_List_1Tt_mx2_ErrorEx_2_BackwardsIterator::t_std_collections_List_1Tt_mx2_ErrorEx_2_BackwardsIterator(t_std_collections_List_1Tt_mx2_ErrorEx_2* l_list,t_std_collections_List_1Tt_mx2_ErrorEx_2_Node* l_node){
  (*this).m__0list=l_list;
  (*this).m__0node=l_node;
  (*this).m__0seq=l_list->m__0seq;
}

void t_std_collections_List_1Tt_mx2_ErrorEx_2_BackwardsIterator::m_Insert(t_mx2_ErrorEx* l_value){
  (*this).m_AssertSeq();
  (*this).m__0node=bbGCNew<t_std_collections_List_1Tt_mx2_ErrorEx_2_Node>(l_value,(*this).m__0node->m__0succ);
  (*this).m__0list->m__0seq+=1;
  (*this).m__0seq=(*this).m__0list->m__0seq;
}

void t_std_collections_List_1Tt_mx2_ErrorEx_2_BackwardsIterator::m_Erase(){
  (*this).m_AssertCurrent();
  (*this).m__0node=(*this).m__0node->m__0pred;
  (*this).m__0node->m__0succ->m_Remove();
  (*this).m__0list->m__0seq+=1;
  (*this).m__0seq=(*this).m__0list->m__0seq;
}

void t_std_collections_List_1Tt_mx2_ErrorEx_2_BackwardsIterator::m_Current(t_mx2_ErrorEx* l_current){
  (*this).m_AssertCurrent();
  (*this).m__0node->m__0value=l_current;
}

t_mx2_ErrorEx* t_std_collections_List_1Tt_mx2_ErrorEx_2_BackwardsIterator::m_Current(){
  (*this).m_AssertCurrent();
  return (*this).m__0node->m__0value;
}

void t_std_collections_List_1Tt_mx2_ErrorEx_2_BackwardsIterator::m_Bump(){
  (*this).m_AssertCurrent();
  (*this).m__0node=(*this).m__0node->m__0pred;
}

bbBool t_std_collections_List_1Tt_mx2_ErrorEx_2_BackwardsIterator::m_AtEnd(){
  (*this).m_AssertSeq();
  return ((*this).m__0node==(*this).m__0list->m__0head);
}

void t_std_collections_List_1Tt_mx2_ErrorEx_2_BackwardsIterator::m_AssertSeq(){
  bbDebugAssert(((*this).m__0seq==(*this).m__0list->m__0seq),BB_T("Concurrent list modification"));
}

void t_std_collections_List_1Tt_mx2_ErrorEx_2_BackwardsIterator::m_AssertCurrent(){
  bbDebugAssert(!(*this).m_AtEnd(),BB_T("Invalid list iterator"));
}

int bbCompare(const t_std_collections_List_1Tt_mx2_ErrorEx_2_BackwardsIterator&x,const t_std_collections_List_1Tt_mx2_ErrorEx_2_BackwardsIterator&y){
  if(int t=bbCompare(x.m__0list,y.m__0list)) return t;
  if(int t=bbCompare(x.m__0node,y.m__0node)) return t;
  if(int t=bbCompare(x.m__0seq,y.m__0seq)) return t;
  return 0;
}

void bbGCMark(const t_std_collections_List_1Tt_mx2_ErrorEx_2_BackwardsIterator&t){
  bbGCMark(t.m__0list);
  bbGCMark(t.m__0node);
}

void t_std_collections_List_1Tt_mx2_ErrorEx_2::gcMark(){
  bbGCMark(m__0head);
}

t_std_collections_List_1Tt_mx2_ErrorEx_2::t_std_collections_List_1Tt_mx2_ErrorEx_2(t_std_collections_List_1Tt_mx2_ErrorEx_2* l_values):t_std_collections_List_1Tt_mx2_ErrorEx_2(){
  g_std_collections_List_1Tt_mx2_ErrorEx_2_AddAll_1Tt_std_collections_List_1Tt_mx2_ErrorEx_2_2(this,l_values);
}

t_std_collections_List_1Tt_mx2_ErrorEx_2::t_std_collections_List_1Tt_mx2_ErrorEx_2(t_std_collections_Stack_1Tt_mx2_ErrorEx_2* l_values):t_std_collections_List_1Tt_mx2_ErrorEx_2(){
  g_std_collections_List_1Tt_mx2_ErrorEx_2_AddAll_1Tt_std_collections_Stack_1Tt_mx2_ErrorEx_2_2(this,l_values);
}

t_std_collections_List_1Tt_mx2_ErrorEx_2::t_std_collections_List_1Tt_mx2_ErrorEx_2(bbArray<bbGCVar<t_mx2_ErrorEx>>* l_values):t_std_collections_List_1Tt_mx2_ErrorEx_2(){
  this->m_AddAll(l_values);
}

t_std_collections_List_1Tt_mx2_ErrorEx_2::t_std_collections_List_1Tt_mx2_ErrorEx_2(){
  this->m__0head=bbGCNew<t_std_collections_List_1Tt_mx2_ErrorEx_2_Node>(((t_mx2_ErrorEx*)0));
}

bbArray<bbGCVar<t_mx2_ErrorEx>>* t_std_collections_List_1Tt_mx2_ErrorEx_2::m_ToArray(){
  struct f0_t : public bbGCFrame{
    bbArray<bbGCVar<t_mx2_ErrorEx>>* l_data{};
    t_std_collections_List_1Tt_mx2_ErrorEx_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_data);
      bbGCMarkPtr(l_node);
    }
  }f0{};
  bbInt l_n=this->m_Count();
  f0.l_data=bbArray<bbGCVar<t_mx2_ErrorEx>>::create(l_n);
  f0.l_node=this->m__0head->m__0succ;
  {
    bbInt l_i=bbInt(0);
    for(;(l_i<l_n);l_i+=1){
      f0.l_data->at(l_i)=f0.l_node->m__0value;
      f0.l_node=f0.l_node->m__0succ;
    }
  }
  return f0.l_data;
}

void t_std_collections_List_1Tt_mx2_ErrorEx_2::m_Sort(bbFunction<bbInt(t_mx2_ErrorEx*,t_mx2_ErrorEx*)> l_compareFunc){
  bbInt l_insize=1;
  for(;;){
    struct f1_t : public bbGCFrame{
      t_std_collections_List_1Tt_mx2_ErrorEx_2_Node* l_p{};
      t_std_collections_List_1Tt_mx2_ErrorEx_2_Node* l_tail{};
      void gcMark(){
        bbGCMarkPtr(l_p);
        bbGCMarkPtr(l_tail);
      }
    }f1{};
    bbInt l_merges=bbInt(0);
    f1.l_tail=this->m__0head;
    f1.l_p=this->m__0head->m__0succ;
    while((f1.l_p!=this->m__0head)){
      struct f2_t : public bbGCFrame{
        t_std_collections_List_1Tt_mx2_ErrorEx_2_Node* l_q{};
        void gcMark(){
          bbGCMarkPtr(l_q);
        }
      }f2{};
      l_merges+=1;
      f2.l_q=f1.l_p->m__0succ;
      bbInt l_qsize=l_insize;
      bbInt l_psize=1;
      while(((l_psize<l_insize)&&(f2.l_q!=this->m__0head))){
        l_psize+=1;
        f2.l_q=f2.l_q->m__0succ;
      }
      for(;;){
        struct f3_t : public bbGCFrame{
          t_std_collections_List_1Tt_mx2_ErrorEx_2_Node* l_t{};
          void gcMark(){
            bbGCMarkPtr(l_t);
          }
        }f3{};
        if(((bbBool(l_psize)&&bbBool(l_qsize))&&(f2.l_q!=this->m__0head))){
          bbInt l_cc=l_compareFunc(f1.l_p->m__0value,f2.l_q->m__0value);
          if((l_cc<=bbInt(0))){
            f3.l_t=f1.l_p;
            f1.l_p=f1.l_p->m__0succ;
            l_psize-=1;
          }else{
            f3.l_t=f2.l_q;
            f2.l_q=f2.l_q->m__0succ;
            l_qsize-=1;
          }
        }else if(bbBool(l_psize)){
          f3.l_t=f1.l_p;
          f1.l_p=f1.l_p->m__0succ;
          l_psize-=1;
        }else if((bbBool(l_qsize)&&(f2.l_q!=this->m__0head))){
          f3.l_t=f2.l_q;
          f2.l_q=f2.l_q->m__0succ;
          l_qsize-=1;
        }else{
          break;
        }
        f3.l_t->m__0pred=f1.l_tail;
        f1.l_tail->m__0succ=f3.l_t;
        f1.l_tail=f3.l_t;
      }
      f1.l_p=f2.l_q;
    }
    f1.l_tail->m__0succ=this->m__0head;
    this->m__0head->m__0pred=f1.l_tail;
    if((l_merges<=1)){
      return;
    }
    l_insize*=2;
  }
}

void t_std_collections_List_1Tt_mx2_ErrorEx_2::m_Sort(bbBool l_ascending){
  if(l_ascending){
    struct lambda4 : public bbFunction<bbInt(t_mx2_ErrorEx*,t_mx2_ErrorEx*)>::Rep{
      t_std_collections_List_1Tt_mx2_ErrorEx_2* l_self;
      lambda4(t_std_collections_List_1Tt_mx2_ErrorEx_2* l_self):l_self(l_self){
      }
      bbInt invoke(t_mx2_ErrorEx* l_x,t_mx2_ErrorEx* l_y){
        return bbCompare(l_x,l_y);
      }
      void gcMark(){
        bbGCMarkPtr(l_self);
      }
    };
    this->m_Sort(bbFunction<bbInt(t_mx2_ErrorEx*,t_mx2_ErrorEx*)>(new lambda4(this)));
  }else{
    struct lambda5 : public bbFunction<bbInt(t_mx2_ErrorEx*,t_mx2_ErrorEx*)>::Rep{
      t_std_collections_List_1Tt_mx2_ErrorEx_2* l_self;
      lambda5(t_std_collections_List_1Tt_mx2_ErrorEx_2* l_self):l_self(l_self){
      }
      bbInt invoke(t_mx2_ErrorEx* l_x,t_mx2_ErrorEx* l_y){
        return -bbCompare(l_x,l_y);
      }
      void gcMark(){
        bbGCMarkPtr(l_self);
      }
    };
    this->m_Sort(bbFunction<bbInt(t_mx2_ErrorEx*,t_mx2_ErrorEx*)>(new lambda5(this)));
  }
}

t_mx2_ErrorEx* t_std_collections_List_1Tt_mx2_ErrorEx_2::m_RemoveLast(){
  struct f0_t : public bbGCFrame{
    t_mx2_ErrorEx* l_value{};
    void gcMark(){
      bbGCMarkPtr(l_value);
    }
  }f0{};
  bbDebugAssert(!this->m_Empty(),BB_T("Debug assert failed"));
  f0.l_value=this->m__0head->m__0pred->m__0value;
  this->m__0head->m__0pred->m_Remove();
  this->m__0seq+=1;
  return f0.l_value;
}

bbBool t_std_collections_List_1Tt_mx2_ErrorEx_2::m_RemoveLast(t_mx2_ErrorEx* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_mx2_ErrorEx_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m_FindLastNode(l_value);
  if(!bbBool(f0.l_node)){
    return false;
  }
  f0.l_node->m_Remove();
  this->m__0seq+=1;
  return true;
}

t_mx2_ErrorEx* t_std_collections_List_1Tt_mx2_ErrorEx_2::m_RemoveFirst(){
  struct f0_t : public bbGCFrame{
    t_mx2_ErrorEx* l_value{};
    void gcMark(){
      bbGCMarkPtr(l_value);
    }
  }f0{};
  bbDebugAssert(!this->m_Empty(),BB_T("Debug assert failed"));
  f0.l_value=this->m__0head->m__0succ->m__0value;
  this->m__0head->m__0succ->m_Remove();
  this->m__0seq+=1;
  return f0.l_value;
}

bbInt t_std_collections_List_1Tt_mx2_ErrorEx_2::m_RemoveEach(t_mx2_ErrorEx* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_mx2_ErrorEx_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m__0head->m__0succ;
  bbInt l_n=bbInt(0);
  while((f0.l_node!=this->m__0head)){
    if((f0.l_node->m__0value==l_value)){
      f0.l_node=f0.l_node->m__0succ;
      f0.l_node->m__0pred->m_Remove();
      l_n+=1;
    }else{
      f0.l_node=f0.l_node->m__0succ;
    }
  }
  if(bbBool(l_n)){
    this->m__0seq+=1;
  }
  return l_n;
}

bbBool t_std_collections_List_1Tt_mx2_ErrorEx_2::m_Remove(t_mx2_ErrorEx* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_mx2_ErrorEx_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m_FindNode(l_value);
  if(!bbBool(f0.l_node)){
    return false;
  }
  f0.l_node->m_Remove();
  this->m__0seq+=1;
  return true;
}

t_std_collections_List_1Tt_mx2_ErrorEx_2_Node* t_std_collections_List_1Tt_mx2_ErrorEx_2::m_LastNode(){
  if(!this->m_Empty()){
    return this->m__0head->m__0pred;
  }
  return ((t_std_collections_List_1Tt_mx2_ErrorEx_2_Node*)0);
}

t_mx2_ErrorEx* t_std_collections_List_1Tt_mx2_ErrorEx_2::m_Last(){
  bbDebugAssert(!this->m_Empty(),BB_T("Debug assert failed"));
  return this->m__0head->m__0pred->m__0value;
}

t_std_collections_List_1Tt_mx2_ErrorEx_2_Node* t_std_collections_List_1Tt_mx2_ErrorEx_2::m_HeadNode(){
  return this->m__0head;
}

t_std_collections_List_1Tt_mx2_ErrorEx_2_Node* t_std_collections_List_1Tt_mx2_ErrorEx_2::m_FirstNode(){
  if(!this->m_Empty()){
    return this->m__0head->m__0succ;
  }
  return ((t_std_collections_List_1Tt_mx2_ErrorEx_2_Node*)0);
}

t_mx2_ErrorEx* t_std_collections_List_1Tt_mx2_ErrorEx_2::m_First(){
  bbDebugAssert(!this->m_Empty(),BB_T("Debug assert failed"));
  return this->m__0head->m__0succ->m__0value;
}

t_std_collections_List_1Tt_mx2_ErrorEx_2_Node* t_std_collections_List_1Tt_mx2_ErrorEx_2::m_FindNode(t_mx2_ErrorEx* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_mx2_ErrorEx_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m__0head->m__0succ;
  while((f0.l_node!=this->m__0head)){
    if((f0.l_node->m__0value==l_value)){
      return f0.l_node;
    }
    f0.l_node=f0.l_node->m__0succ;
  }
  return ((t_std_collections_List_1Tt_mx2_ErrorEx_2_Node*)0);
}

t_std_collections_List_1Tt_mx2_ErrorEx_2_Node* t_std_collections_List_1Tt_mx2_ErrorEx_2::m_FindLastNode(t_mx2_ErrorEx* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_mx2_ErrorEx_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m__0head->m__0pred;
  while((f0.l_node!=this->m__0head)){
    if((f0.l_node->m__0value==l_value)){
      return f0.l_node;
    }
    f0.l_node=f0.l_node->m__0pred;
  }
  return ((t_std_collections_List_1Tt_mx2_ErrorEx_2_Node*)0);
}

bbBool t_std_collections_List_1Tt_mx2_ErrorEx_2::m_Empty(){
  return (this->m__0head->m__0succ==this->m__0head);
}

bbInt t_std_collections_List_1Tt_mx2_ErrorEx_2::m_Count(){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_mx2_ErrorEx_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m__0head->m__0succ;
  bbInt l_n=bbInt(0);
  while((f0.l_node!=this->m__0head)){
    f0.l_node=f0.l_node->m__0succ;
    l_n+=1;
  }
  return l_n;
}

void t_std_collections_List_1Tt_mx2_ErrorEx_2::m_Clear(){
  this->m__0head->m__0succ=this->m__0head;
  this->m__0head->m__0pred=this->m__0head;
  this->m__0seq+=1;
}

t_std_collections_List_1Tt_mx2_ErrorEx_2_BackwardsIterator t_std_collections_List_1Tt_mx2_ErrorEx_2::m_Backwards(){
  return t_std_collections_List_1Tt_mx2_ErrorEx_2_BackwardsIterator(this,this->m__0head->m__0pred);
}

t_std_collections_List_1Tt_mx2_ErrorEx_2_Iterator t_std_collections_List_1Tt_mx2_ErrorEx_2::m_All(){
  return t_std_collections_List_1Tt_mx2_ErrorEx_2_Iterator(this,this->m__0head->m__0succ);
}

t_std_collections_List_1Tt_mx2_ErrorEx_2_Node* t_std_collections_List_1Tt_mx2_ErrorEx_2::m_AddLast(t_mx2_ErrorEx* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_mx2_ErrorEx_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=bbGCNew<t_std_collections_List_1Tt_mx2_ErrorEx_2_Node>(l_value,this->m__0head);
  this->m__0seq+=1;
  return f0.l_node;
}

t_std_collections_List_1Tt_mx2_ErrorEx_2_Node* t_std_collections_List_1Tt_mx2_ErrorEx_2::m_AddFirst(t_mx2_ErrorEx* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_mx2_ErrorEx_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=bbGCNew<t_std_collections_List_1Tt_mx2_ErrorEx_2_Node>(l_value,this->m__0head->m__0succ);
  this->m__0seq+=1;
  return f0.l_node;
}

void t_std_collections_List_1Tt_mx2_ErrorEx_2::m_AddAll(bbArray<bbGCVar<t_mx2_ErrorEx>>* l_values){
  {
    bbInt l_0=bbInt(0);
    bbInt l_1=l_values->length();
    for(;(l_0<l_1);l_0+=1){
      struct f2_t : public bbGCFrame{
        t_mx2_ErrorEx* l_value{};
        void gcMark(){
          bbGCMarkPtr(l_value);
        }
      }f2{};
      f2.l_value=l_values->at(l_0);
      this->m_AddLast(f2.l_value);
    }
  }
}

void t_std_collections_List_1Tt_mx2_ErrorEx_2::m_Add(t_mx2_ErrorEx* l_value){
  this->m_AddLast(l_value);
}

void t_std_collections_List_1Tt_mx2_ClassType_2_Node::gcMark(){
  bbGCMark(m__0succ);
  bbGCMark(m__0pred);
  bbGCMark(m__0value);
}

t_std_collections_List_1Tt_mx2_ClassType_2_Node::t_std_collections_List_1Tt_mx2_ClassType_2_Node(t_mx2_ClassType* l_value,t_std_collections_List_1Tt_mx2_ClassType_2_Node* l_succ){
  this->m__0value=l_value;
  this->m__0succ=l_succ;
  this->m__0pred=l_succ->m__0pred;
  this->m__0pred->m__0succ=this;
  l_succ->m__0pred=this;
}

t_std_collections_List_1Tt_mx2_ClassType_2_Node::t_std_collections_List_1Tt_mx2_ClassType_2_Node(t_mx2_ClassType* l_value){
  this->m__0value=l_value;
  this->m__0succ=this;
  this->m__0pred=this;
}

void t_std_collections_List_1Tt_mx2_ClassType_2_Node::m_Value(t_mx2_ClassType* l_value){
  this->m__0value=l_value;
}

t_mx2_ClassType* t_std_collections_List_1Tt_mx2_ClassType_2_Node::m_Value(){
  return this->m__0value;
}

t_std_collections_List_1Tt_mx2_ClassType_2_Node* t_std_collections_List_1Tt_mx2_ClassType_2_Node::m_Succ(){
  return this->m__0succ;
}

void t_std_collections_List_1Tt_mx2_ClassType_2_Node::m_Remove(){
  this->m__0succ->m__0pred=this->m__0pred;
  this->m__0pred->m__0succ=this->m__0succ;
}

t_std_collections_List_1Tt_mx2_ClassType_2_Node* t_std_collections_List_1Tt_mx2_ClassType_2_Node::m_Pred(){
  return this->m__0pred;
}

void t_std_collections_List_1Tt_mx2_ClassType_2_Node::m_InsertBefore(t_std_collections_List_1Tt_mx2_ClassType_2_Node* l_node){
  this->m__0succ=l_node;
  this->m__0pred=l_node->m__0pred;
  this->m__0pred->m__0succ=this;
  l_node->m__0pred=this;
}

void t_std_collections_List_1Tt_mx2_ClassType_2_Node::m_InsertAfter(t_std_collections_List_1Tt_mx2_ClassType_2_Node* l_node){
  this->m__0pred=l_node;
  this->m__0succ=l_node->m__0succ;
  this->m__0succ->m__0pred=this;
  l_node->m__0succ=this;
}

t_std_collections_List_1Tt_mx2_ClassType_2_Iterator::t_std_collections_List_1Tt_mx2_ClassType_2_Iterator(t_std_collections_List_1Tt_mx2_ClassType_2* l_list,t_std_collections_List_1Tt_mx2_ClassType_2_Node* l_node){
  (*this).m__0list=l_list;
  (*this).m__0node=l_node;
  (*this).m__0seq=l_list->m__0seq;
}

void t_std_collections_List_1Tt_mx2_ClassType_2_Iterator::m_Insert(t_mx2_ClassType* l_value){
  (*this).m_AssertSeq();
  (*this).m__0node=bbGCNew<t_std_collections_List_1Tt_mx2_ClassType_2_Node>(l_value,(*this).m__0node);
  (*this).m__0list->m__0seq+=1;
  (*this).m__0seq=(*this).m__0list->m__0seq;
}

void t_std_collections_List_1Tt_mx2_ClassType_2_Iterator::m_Erase(){
  (*this).m_AssertCurrent();
  (*this).m__0node=(*this).m__0node->m__0succ;
  (*this).m__0node->m__0pred->m_Remove();
  (*this).m__0list->m__0seq+=1;
  (*this).m__0seq=(*this).m__0list->m__0seq;
}

void t_std_collections_List_1Tt_mx2_ClassType_2_Iterator::m_Current(t_mx2_ClassType* l_current){
  (*this).m_AssertCurrent();
  (*this).m__0node->m__0value=l_current;
}

t_mx2_ClassType* t_std_collections_List_1Tt_mx2_ClassType_2_Iterator::m_Current(){
  (*this).m_AssertCurrent();
  return (*this).m__0node->m__0value;
}

void t_std_collections_List_1Tt_mx2_ClassType_2_Iterator::m_Bump(){
  (*this).m_AssertCurrent();
  (*this).m__0node=(*this).m__0node->m__0succ;
}

bbBool t_std_collections_List_1Tt_mx2_ClassType_2_Iterator::m_AtEnd(){
  (*this).m_AssertSeq();
  return ((*this).m__0node==(*this).m__0list->m__0head);
}

void t_std_collections_List_1Tt_mx2_ClassType_2_Iterator::m_AssertSeq(){
  bbDebugAssert(((*this).m__0seq==(*this).m__0list->m__0seq),BB_T("Concurrent list modification"));
}

void t_std_collections_List_1Tt_mx2_ClassType_2_Iterator::m_AssertCurrent(){
  bbDebugAssert(!(*this).m_AtEnd(),BB_T("Invalid list iterator"));
}

int bbCompare(const t_std_collections_List_1Tt_mx2_ClassType_2_Iterator&x,const t_std_collections_List_1Tt_mx2_ClassType_2_Iterator&y){
  if(int t=bbCompare(x.m__0list,y.m__0list)) return t;
  if(int t=bbCompare(x.m__0node,y.m__0node)) return t;
  if(int t=bbCompare(x.m__0seq,y.m__0seq)) return t;
  return 0;
}

void bbGCMark(const t_std_collections_List_1Tt_mx2_ClassType_2_Iterator&t){
  bbGCMark(t.m__0list);
  bbGCMark(t.m__0node);
}

t_std_collections_List_1Tt_mx2_ClassType_2_BackwardsIterator::t_std_collections_List_1Tt_mx2_ClassType_2_BackwardsIterator(t_std_collections_List_1Tt_mx2_ClassType_2* l_list,t_std_collections_List_1Tt_mx2_ClassType_2_Node* l_node){
  (*this).m__0list=l_list;
  (*this).m__0node=l_node;
  (*this).m__0seq=l_list->m__0seq;
}

void t_std_collections_List_1Tt_mx2_ClassType_2_BackwardsIterator::m_Insert(t_mx2_ClassType* l_value){
  (*this).m_AssertSeq();
  (*this).m__0node=bbGCNew<t_std_collections_List_1Tt_mx2_ClassType_2_Node>(l_value,(*this).m__0node->m__0succ);
  (*this).m__0list->m__0seq+=1;
  (*this).m__0seq=(*this).m__0list->m__0seq;
}

void t_std_collections_List_1Tt_mx2_ClassType_2_BackwardsIterator::m_Erase(){
  (*this).m_AssertCurrent();
  (*this).m__0node=(*this).m__0node->m__0pred;
  (*this).m__0node->m__0succ->m_Remove();
  (*this).m__0list->m__0seq+=1;
  (*this).m__0seq=(*this).m__0list->m__0seq;
}

void t_std_collections_List_1Tt_mx2_ClassType_2_BackwardsIterator::m_Current(t_mx2_ClassType* l_current){
  (*this).m_AssertCurrent();
  (*this).m__0node->m__0value=l_current;
}

t_mx2_ClassType* t_std_collections_List_1Tt_mx2_ClassType_2_BackwardsIterator::m_Current(){
  (*this).m_AssertCurrent();
  return (*this).m__0node->m__0value;
}

void t_std_collections_List_1Tt_mx2_ClassType_2_BackwardsIterator::m_Bump(){
  (*this).m_AssertCurrent();
  (*this).m__0node=(*this).m__0node->m__0pred;
}

bbBool t_std_collections_List_1Tt_mx2_ClassType_2_BackwardsIterator::m_AtEnd(){
  (*this).m_AssertSeq();
  return ((*this).m__0node==(*this).m__0list->m__0head);
}

void t_std_collections_List_1Tt_mx2_ClassType_2_BackwardsIterator::m_AssertSeq(){
  bbDebugAssert(((*this).m__0seq==(*this).m__0list->m__0seq),BB_T("Concurrent list modification"));
}

void t_std_collections_List_1Tt_mx2_ClassType_2_BackwardsIterator::m_AssertCurrent(){
  bbDebugAssert(!(*this).m_AtEnd(),BB_T("Invalid list iterator"));
}

int bbCompare(const t_std_collections_List_1Tt_mx2_ClassType_2_BackwardsIterator&x,const t_std_collections_List_1Tt_mx2_ClassType_2_BackwardsIterator&y){
  if(int t=bbCompare(x.m__0list,y.m__0list)) return t;
  if(int t=bbCompare(x.m__0node,y.m__0node)) return t;
  if(int t=bbCompare(x.m__0seq,y.m__0seq)) return t;
  return 0;
}

void bbGCMark(const t_std_collections_List_1Tt_mx2_ClassType_2_BackwardsIterator&t){
  bbGCMark(t.m__0list);
  bbGCMark(t.m__0node);
}

void t_std_collections_List_1Tt_mx2_ClassType_2::gcMark(){
  bbGCMark(m__0head);
}

t_std_collections_List_1Tt_mx2_ClassType_2::t_std_collections_List_1Tt_mx2_ClassType_2(t_std_collections_List_1Tt_mx2_ClassType_2* l_values):t_std_collections_List_1Tt_mx2_ClassType_2(){
  g_std_collections_List_1Tt_mx2_ClassType_2_AddAll_1Tt_std_collections_List_1Tt_mx2_ClassType_2_2(this,l_values);
}

t_std_collections_List_1Tt_mx2_ClassType_2::t_std_collections_List_1Tt_mx2_ClassType_2(t_std_collections_Stack_1Tt_mx2_ClassType_2* l_values):t_std_collections_List_1Tt_mx2_ClassType_2(){
  g_std_collections_List_1Tt_mx2_ClassType_2_AddAll_1Tt_std_collections_Stack_1Tt_mx2_ClassType_2_2(this,l_values);
}

t_std_collections_List_1Tt_mx2_ClassType_2::t_std_collections_List_1Tt_mx2_ClassType_2(bbArray<bbGCVar<t_mx2_ClassType>>* l_values):t_std_collections_List_1Tt_mx2_ClassType_2(){
  this->m_AddAll(l_values);
}

t_std_collections_List_1Tt_mx2_ClassType_2::t_std_collections_List_1Tt_mx2_ClassType_2(){
  this->m__0head=bbGCNew<t_std_collections_List_1Tt_mx2_ClassType_2_Node>(((t_mx2_ClassType*)0));
}

bbArray<bbGCVar<t_mx2_ClassType>>* t_std_collections_List_1Tt_mx2_ClassType_2::m_ToArray(){
  struct f0_t : public bbGCFrame{
    bbArray<bbGCVar<t_mx2_ClassType>>* l_data{};
    t_std_collections_List_1Tt_mx2_ClassType_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_data);
      bbGCMarkPtr(l_node);
    }
  }f0{};
  bbInt l_n=this->m_Count();
  f0.l_data=bbArray<bbGCVar<t_mx2_ClassType>>::create(l_n);
  f0.l_node=this->m__0head->m__0succ;
  {
    bbInt l_i=bbInt(0);
    for(;(l_i<l_n);l_i+=1){
      f0.l_data->at(l_i)=f0.l_node->m__0value;
      f0.l_node=f0.l_node->m__0succ;
    }
  }
  return f0.l_data;
}

void t_std_collections_List_1Tt_mx2_ClassType_2::m_Sort(bbFunction<bbInt(t_mx2_ClassType*,t_mx2_ClassType*)> l_compareFunc){
  bbInt l_insize=1;
  for(;;){
    struct f1_t : public bbGCFrame{
      t_std_collections_List_1Tt_mx2_ClassType_2_Node* l_p{};
      t_std_collections_List_1Tt_mx2_ClassType_2_Node* l_tail{};
      void gcMark(){
        bbGCMarkPtr(l_p);
        bbGCMarkPtr(l_tail);
      }
    }f1{};
    bbInt l_merges=bbInt(0);
    f1.l_tail=this->m__0head;
    f1.l_p=this->m__0head->m__0succ;
    while((f1.l_p!=this->m__0head)){
      struct f2_t : public bbGCFrame{
        t_std_collections_List_1Tt_mx2_ClassType_2_Node* l_q{};
        void gcMark(){
          bbGCMarkPtr(l_q);
        }
      }f2{};
      l_merges+=1;
      f2.l_q=f1.l_p->m__0succ;
      bbInt l_qsize=l_insize;
      bbInt l_psize=1;
      while(((l_psize<l_insize)&&(f2.l_q!=this->m__0head))){
        l_psize+=1;
        f2.l_q=f2.l_q->m__0succ;
      }
      for(;;){
        struct f3_t : public bbGCFrame{
          t_std_collections_List_1Tt_mx2_ClassType_2_Node* l_t{};
          void gcMark(){
            bbGCMarkPtr(l_t);
          }
        }f3{};
        if(((bbBool(l_psize)&&bbBool(l_qsize))&&(f2.l_q!=this->m__0head))){
          bbInt l_cc=l_compareFunc(f1.l_p->m__0value,f2.l_q->m__0value);
          if((l_cc<=bbInt(0))){
            f3.l_t=f1.l_p;
            f1.l_p=f1.l_p->m__0succ;
            l_psize-=1;
          }else{
            f3.l_t=f2.l_q;
            f2.l_q=f2.l_q->m__0succ;
            l_qsize-=1;
          }
        }else if(bbBool(l_psize)){
          f3.l_t=f1.l_p;
          f1.l_p=f1.l_p->m__0succ;
          l_psize-=1;
        }else if((bbBool(l_qsize)&&(f2.l_q!=this->m__0head))){
          f3.l_t=f2.l_q;
          f2.l_q=f2.l_q->m__0succ;
          l_qsize-=1;
        }else{
          break;
        }
        f3.l_t->m__0pred=f1.l_tail;
        f1.l_tail->m__0succ=f3.l_t;
        f1.l_tail=f3.l_t;
      }
      f1.l_p=f2.l_q;
    }
    f1.l_tail->m__0succ=this->m__0head;
    this->m__0head->m__0pred=f1.l_tail;
    if((l_merges<=1)){
      return;
    }
    l_insize*=2;
  }
}

void t_std_collections_List_1Tt_mx2_ClassType_2::m_Sort(bbBool l_ascending){
  if(l_ascending){
    struct lambda6 : public bbFunction<bbInt(t_mx2_ClassType*,t_mx2_ClassType*)>::Rep{
      t_std_collections_List_1Tt_mx2_ClassType_2* l_self;
      lambda6(t_std_collections_List_1Tt_mx2_ClassType_2* l_self):l_self(l_self){
      }
      bbInt invoke(t_mx2_ClassType* l_x,t_mx2_ClassType* l_y){
        return l_x->m__cmp(((t_mx2_Type*)(l_y)));
      }
      void gcMark(){
        bbGCMarkPtr(l_self);
      }
    };
    this->m_Sort(bbFunction<bbInt(t_mx2_ClassType*,t_mx2_ClassType*)>(new lambda6(this)));
  }else{
    struct lambda7 : public bbFunction<bbInt(t_mx2_ClassType*,t_mx2_ClassType*)>::Rep{
      t_std_collections_List_1Tt_mx2_ClassType_2* l_self;
      lambda7(t_std_collections_List_1Tt_mx2_ClassType_2* l_self):l_self(l_self){
      }
      bbInt invoke(t_mx2_ClassType* l_x,t_mx2_ClassType* l_y){
        return -l_x->m__cmp(((t_mx2_Type*)(l_y)));
      }
      void gcMark(){
        bbGCMarkPtr(l_self);
      }
    };
    this->m_Sort(bbFunction<bbInt(t_mx2_ClassType*,t_mx2_ClassType*)>(new lambda7(this)));
  }
}

t_mx2_ClassType* t_std_collections_List_1Tt_mx2_ClassType_2::m_RemoveLast(){
  struct f0_t : public bbGCFrame{
    t_mx2_ClassType* l_value{};
    void gcMark(){
      bbGCMarkPtr(l_value);
    }
  }f0{};
  bbDebugAssert(!this->m_Empty(),BB_T("Debug assert failed"));
  f0.l_value=this->m__0head->m__0pred->m__0value;
  this->m__0head->m__0pred->m_Remove();
  this->m__0seq+=1;
  return f0.l_value;
}

bbBool t_std_collections_List_1Tt_mx2_ClassType_2::m_RemoveLast(t_mx2_ClassType* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_mx2_ClassType_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m_FindLastNode(l_value);
  if(!bbBool(f0.l_node)){
    return false;
  }
  f0.l_node->m_Remove();
  this->m__0seq+=1;
  return true;
}

t_mx2_ClassType* t_std_collections_List_1Tt_mx2_ClassType_2::m_RemoveFirst(){
  struct f0_t : public bbGCFrame{
    t_mx2_ClassType* l_value{};
    void gcMark(){
      bbGCMarkPtr(l_value);
    }
  }f0{};
  bbDebugAssert(!this->m_Empty(),BB_T("Debug assert failed"));
  f0.l_value=this->m__0head->m__0succ->m__0value;
  this->m__0head->m__0succ->m_Remove();
  this->m__0seq+=1;
  return f0.l_value;
}

bbInt t_std_collections_List_1Tt_mx2_ClassType_2::m_RemoveEach(t_mx2_ClassType* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_mx2_ClassType_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m__0head->m__0succ;
  bbInt l_n=bbInt(0);
  while((f0.l_node!=this->m__0head)){
    if(f0.l_node->m__0value->m__eq(((t_mx2_Type*)(l_value)))){
      f0.l_node=f0.l_node->m__0succ;
      f0.l_node->m__0pred->m_Remove();
      l_n+=1;
    }else{
      f0.l_node=f0.l_node->m__0succ;
    }
  }
  if(bbBool(l_n)){
    this->m__0seq+=1;
  }
  return l_n;
}

bbBool t_std_collections_List_1Tt_mx2_ClassType_2::m_Remove(t_mx2_ClassType* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_mx2_ClassType_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m_FindNode(l_value);
  if(!bbBool(f0.l_node)){
    return false;
  }
  f0.l_node->m_Remove();
  this->m__0seq+=1;
  return true;
}

t_std_collections_List_1Tt_mx2_ClassType_2_Node* t_std_collections_List_1Tt_mx2_ClassType_2::m_LastNode(){
  if(!this->m_Empty()){
    return this->m__0head->m__0pred;
  }
  return ((t_std_collections_List_1Tt_mx2_ClassType_2_Node*)0);
}

t_mx2_ClassType* t_std_collections_List_1Tt_mx2_ClassType_2::m_Last(){
  bbDebugAssert(!this->m_Empty(),BB_T("Debug assert failed"));
  return this->m__0head->m__0pred->m__0value;
}

t_std_collections_List_1Tt_mx2_ClassType_2_Node* t_std_collections_List_1Tt_mx2_ClassType_2::m_HeadNode(){
  return this->m__0head;
}

t_std_collections_List_1Tt_mx2_ClassType_2_Node* t_std_collections_List_1Tt_mx2_ClassType_2::m_FirstNode(){
  if(!this->m_Empty()){
    return this->m__0head->m__0succ;
  }
  return ((t_std_collections_List_1Tt_mx2_ClassType_2_Node*)0);
}

t_mx2_ClassType* t_std_collections_List_1Tt_mx2_ClassType_2::m_First(){
  bbDebugAssert(!this->m_Empty(),BB_T("Debug assert failed"));
  return this->m__0head->m__0succ->m__0value;
}

t_std_collections_List_1Tt_mx2_ClassType_2_Node* t_std_collections_List_1Tt_mx2_ClassType_2::m_FindNode(t_mx2_ClassType* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_mx2_ClassType_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m__0head->m__0succ;
  while((f0.l_node!=this->m__0head)){
    if(f0.l_node->m__0value->m__eq(((t_mx2_Type*)(l_value)))){
      return f0.l_node;
    }
    f0.l_node=f0.l_node->m__0succ;
  }
  return ((t_std_collections_List_1Tt_mx2_ClassType_2_Node*)0);
}

t_std_collections_List_1Tt_mx2_ClassType_2_Node* t_std_collections_List_1Tt_mx2_ClassType_2::m_FindLastNode(t_mx2_ClassType* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_mx2_ClassType_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m__0head->m__0pred;
  while((f0.l_node!=this->m__0head)){
    if(f0.l_node->m__0value->m__eq(((t_mx2_Type*)(l_value)))){
      return f0.l_node;
    }
    f0.l_node=f0.l_node->m__0pred;
  }
  return ((t_std_collections_List_1Tt_mx2_ClassType_2_Node*)0);
}

bbBool t_std_collections_List_1Tt_mx2_ClassType_2::m_Empty(){
  return (this->m__0head->m__0succ==this->m__0head);
}

bbInt t_std_collections_List_1Tt_mx2_ClassType_2::m_Count(){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_mx2_ClassType_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m__0head->m__0succ;
  bbInt l_n=bbInt(0);
  while((f0.l_node!=this->m__0head)){
    f0.l_node=f0.l_node->m__0succ;
    l_n+=1;
  }
  return l_n;
}

void t_std_collections_List_1Tt_mx2_ClassType_2::m_Clear(){
  this->m__0head->m__0succ=this->m__0head;
  this->m__0head->m__0pred=this->m__0head;
  this->m__0seq+=1;
}

t_std_collections_List_1Tt_mx2_ClassType_2_BackwardsIterator t_std_collections_List_1Tt_mx2_ClassType_2::m_Backwards(){
  return t_std_collections_List_1Tt_mx2_ClassType_2_BackwardsIterator(this,this->m__0head->m__0pred);
}

t_std_collections_List_1Tt_mx2_ClassType_2_Iterator t_std_collections_List_1Tt_mx2_ClassType_2::m_All(){
  return t_std_collections_List_1Tt_mx2_ClassType_2_Iterator(this,this->m__0head->m__0succ);
}

t_std_collections_List_1Tt_mx2_ClassType_2_Node* t_std_collections_List_1Tt_mx2_ClassType_2::m_AddLast(t_mx2_ClassType* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_mx2_ClassType_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=bbGCNew<t_std_collections_List_1Tt_mx2_ClassType_2_Node>(l_value,this->m__0head);
  this->m__0seq+=1;
  return f0.l_node;
}

t_std_collections_List_1Tt_mx2_ClassType_2_Node* t_std_collections_List_1Tt_mx2_ClassType_2::m_AddFirst(t_mx2_ClassType* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_mx2_ClassType_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=bbGCNew<t_std_collections_List_1Tt_mx2_ClassType_2_Node>(l_value,this->m__0head->m__0succ);
  this->m__0seq+=1;
  return f0.l_node;
}

void t_std_collections_List_1Tt_mx2_ClassType_2::m_AddAll(bbArray<bbGCVar<t_mx2_ClassType>>* l_values){
  {
    bbInt l_0=bbInt(0);
    bbInt l_1=l_values->length();
    for(;(l_0<l_1);l_0+=1){
      struct f2_t : public bbGCFrame{
        t_mx2_ClassType* l_value{};
        void gcMark(){
          bbGCMarkPtr(l_value);
        }
      }f2{};
      f2.l_value=l_values->at(l_0);
      this->m_AddLast(f2.l_value);
    }
  }
}

void t_std_collections_List_1Tt_mx2_ClassType_2::m_Add(t_mx2_ClassType* l_value){
  this->m_AddLast(l_value);
}

void t_std_collections_List_1Tt_mx2_Scope_2_Node::gcMark(){
  bbGCMark(m__0succ);
  bbGCMark(m__0pred);
  bbGCMark(m__0value);
}

t_std_collections_List_1Tt_mx2_Scope_2_Node::t_std_collections_List_1Tt_mx2_Scope_2_Node(t_mx2_Scope* l_value,t_std_collections_List_1Tt_mx2_Scope_2_Node* l_succ){
  this->m__0value=l_value;
  this->m__0succ=l_succ;
  this->m__0pred=l_succ->m__0pred;
  this->m__0pred->m__0succ=this;
  l_succ->m__0pred=this;
}

t_std_collections_List_1Tt_mx2_Scope_2_Node::t_std_collections_List_1Tt_mx2_Scope_2_Node(t_mx2_Scope* l_value){
  this->m__0value=l_value;
  this->m__0succ=this;
  this->m__0pred=this;
}

void t_std_collections_List_1Tt_mx2_Scope_2_Node::m_Value(t_mx2_Scope* l_value){
  this->m__0value=l_value;
}

t_mx2_Scope* t_std_collections_List_1Tt_mx2_Scope_2_Node::m_Value(){
  return this->m__0value;
}

t_std_collections_List_1Tt_mx2_Scope_2_Node* t_std_collections_List_1Tt_mx2_Scope_2_Node::m_Succ(){
  return this->m__0succ;
}

void t_std_collections_List_1Tt_mx2_Scope_2_Node::m_Remove(){
  this->m__0succ->m__0pred=this->m__0pred;
  this->m__0pred->m__0succ=this->m__0succ;
}

t_std_collections_List_1Tt_mx2_Scope_2_Node* t_std_collections_List_1Tt_mx2_Scope_2_Node::m_Pred(){
  return this->m__0pred;
}

void t_std_collections_List_1Tt_mx2_Scope_2_Node::m_InsertBefore(t_std_collections_List_1Tt_mx2_Scope_2_Node* l_node){
  this->m__0succ=l_node;
  this->m__0pred=l_node->m__0pred;
  this->m__0pred->m__0succ=this;
  l_node->m__0pred=this;
}

void t_std_collections_List_1Tt_mx2_Scope_2_Node::m_InsertAfter(t_std_collections_List_1Tt_mx2_Scope_2_Node* l_node){
  this->m__0pred=l_node;
  this->m__0succ=l_node->m__0succ;
  this->m__0succ->m__0pred=this;
  l_node->m__0succ=this;
}

t_std_collections_List_1Tt_mx2_Scope_2_Iterator::t_std_collections_List_1Tt_mx2_Scope_2_Iterator(t_std_collections_List_1Tt_mx2_Scope_2* l_list,t_std_collections_List_1Tt_mx2_Scope_2_Node* l_node){
  (*this).m__0list=l_list;
  (*this).m__0node=l_node;
  (*this).m__0seq=l_list->m__0seq;
}

void t_std_collections_List_1Tt_mx2_Scope_2_Iterator::m_Insert(t_mx2_Scope* l_value){
  (*this).m_AssertSeq();
  (*this).m__0node=bbGCNew<t_std_collections_List_1Tt_mx2_Scope_2_Node>(l_value,(*this).m__0node);
  (*this).m__0list->m__0seq+=1;
  (*this).m__0seq=(*this).m__0list->m__0seq;
}

void t_std_collections_List_1Tt_mx2_Scope_2_Iterator::m_Erase(){
  (*this).m_AssertCurrent();
  (*this).m__0node=(*this).m__0node->m__0succ;
  (*this).m__0node->m__0pred->m_Remove();
  (*this).m__0list->m__0seq+=1;
  (*this).m__0seq=(*this).m__0list->m__0seq;
}

void t_std_collections_List_1Tt_mx2_Scope_2_Iterator::m_Current(t_mx2_Scope* l_current){
  (*this).m_AssertCurrent();
  (*this).m__0node->m__0value=l_current;
}

t_mx2_Scope* t_std_collections_List_1Tt_mx2_Scope_2_Iterator::m_Current(){
  (*this).m_AssertCurrent();
  return (*this).m__0node->m__0value;
}

void t_std_collections_List_1Tt_mx2_Scope_2_Iterator::m_Bump(){
  (*this).m_AssertCurrent();
  (*this).m__0node=(*this).m__0node->m__0succ;
}

bbBool t_std_collections_List_1Tt_mx2_Scope_2_Iterator::m_AtEnd(){
  (*this).m_AssertSeq();
  return ((*this).m__0node==(*this).m__0list->m__0head);
}

void t_std_collections_List_1Tt_mx2_Scope_2_Iterator::m_AssertSeq(){
  bbDebugAssert(((*this).m__0seq==(*this).m__0list->m__0seq),BB_T("Concurrent list modification"));
}

void t_std_collections_List_1Tt_mx2_Scope_2_Iterator::m_AssertCurrent(){
  bbDebugAssert(!(*this).m_AtEnd(),BB_T("Invalid list iterator"));
}

int bbCompare(const t_std_collections_List_1Tt_mx2_Scope_2_Iterator&x,const t_std_collections_List_1Tt_mx2_Scope_2_Iterator&y){
  if(int t=bbCompare(x.m__0list,y.m__0list)) return t;
  if(int t=bbCompare(x.m__0node,y.m__0node)) return t;
  if(int t=bbCompare(x.m__0seq,y.m__0seq)) return t;
  return 0;
}

void bbGCMark(const t_std_collections_List_1Tt_mx2_Scope_2_Iterator&t){
  bbGCMark(t.m__0list);
  bbGCMark(t.m__0node);
}

t_std_collections_List_1Tt_mx2_Scope_2_BackwardsIterator::t_std_collections_List_1Tt_mx2_Scope_2_BackwardsIterator(t_std_collections_List_1Tt_mx2_Scope_2* l_list,t_std_collections_List_1Tt_mx2_Scope_2_Node* l_node){
  (*this).m__0list=l_list;
  (*this).m__0node=l_node;
  (*this).m__0seq=l_list->m__0seq;
}

void t_std_collections_List_1Tt_mx2_Scope_2_BackwardsIterator::m_Insert(t_mx2_Scope* l_value){
  (*this).m_AssertSeq();
  (*this).m__0node=bbGCNew<t_std_collections_List_1Tt_mx2_Scope_2_Node>(l_value,(*this).m__0node->m__0succ);
  (*this).m__0list->m__0seq+=1;
  (*this).m__0seq=(*this).m__0list->m__0seq;
}

void t_std_collections_List_1Tt_mx2_Scope_2_BackwardsIterator::m_Erase(){
  (*this).m_AssertCurrent();
  (*this).m__0node=(*this).m__0node->m__0pred;
  (*this).m__0node->m__0succ->m_Remove();
  (*this).m__0list->m__0seq+=1;
  (*this).m__0seq=(*this).m__0list->m__0seq;
}

void t_std_collections_List_1Tt_mx2_Scope_2_BackwardsIterator::m_Current(t_mx2_Scope* l_current){
  (*this).m_AssertCurrent();
  (*this).m__0node->m__0value=l_current;
}

t_mx2_Scope* t_std_collections_List_1Tt_mx2_Scope_2_BackwardsIterator::m_Current(){
  (*this).m_AssertCurrent();
  return (*this).m__0node->m__0value;
}

void t_std_collections_List_1Tt_mx2_Scope_2_BackwardsIterator::m_Bump(){
  (*this).m_AssertCurrent();
  (*this).m__0node=(*this).m__0node->m__0pred;
}

bbBool t_std_collections_List_1Tt_mx2_Scope_2_BackwardsIterator::m_AtEnd(){
  (*this).m_AssertSeq();
  return ((*this).m__0node==(*this).m__0list->m__0head);
}

void t_std_collections_List_1Tt_mx2_Scope_2_BackwardsIterator::m_AssertSeq(){
  bbDebugAssert(((*this).m__0seq==(*this).m__0list->m__0seq),BB_T("Concurrent list modification"));
}

void t_std_collections_List_1Tt_mx2_Scope_2_BackwardsIterator::m_AssertCurrent(){
  bbDebugAssert(!(*this).m_AtEnd(),BB_T("Invalid list iterator"));
}

int bbCompare(const t_std_collections_List_1Tt_mx2_Scope_2_BackwardsIterator&x,const t_std_collections_List_1Tt_mx2_Scope_2_BackwardsIterator&y){
  if(int t=bbCompare(x.m__0list,y.m__0list)) return t;
  if(int t=bbCompare(x.m__0node,y.m__0node)) return t;
  if(int t=bbCompare(x.m__0seq,y.m__0seq)) return t;
  return 0;
}

void bbGCMark(const t_std_collections_List_1Tt_mx2_Scope_2_BackwardsIterator&t){
  bbGCMark(t.m__0list);
  bbGCMark(t.m__0node);
}

void t_std_collections_List_1Tt_mx2_Scope_2::gcMark(){
  bbGCMark(m__0head);
}

t_std_collections_List_1Tt_mx2_Scope_2::t_std_collections_List_1Tt_mx2_Scope_2(t_std_collections_List_1Tt_mx2_Scope_2* l_values):t_std_collections_List_1Tt_mx2_Scope_2(){
  g_std_collections_List_1Tt_mx2_Scope_2_AddAll_1Tt_std_collections_List_1Tt_mx2_Scope_2_2(this,l_values);
}

t_std_collections_List_1Tt_mx2_Scope_2::t_std_collections_List_1Tt_mx2_Scope_2(t_std_collections_Stack_1Tt_mx2_Scope_2* l_values):t_std_collections_List_1Tt_mx2_Scope_2(){
  g_std_collections_List_1Tt_mx2_Scope_2_AddAll_1Tt_std_collections_Stack_1Tt_mx2_Scope_2_2(this,l_values);
}

t_std_collections_List_1Tt_mx2_Scope_2::t_std_collections_List_1Tt_mx2_Scope_2(bbArray<bbGCVar<t_mx2_Scope>>* l_values):t_std_collections_List_1Tt_mx2_Scope_2(){
  this->m_AddAll(l_values);
}

t_std_collections_List_1Tt_mx2_Scope_2::t_std_collections_List_1Tt_mx2_Scope_2(){
  this->m__0head=bbGCNew<t_std_collections_List_1Tt_mx2_Scope_2_Node>(((t_mx2_Scope*)0));
}

bbArray<bbGCVar<t_mx2_Scope>>* t_std_collections_List_1Tt_mx2_Scope_2::m_ToArray(){
  struct f0_t : public bbGCFrame{
    bbArray<bbGCVar<t_mx2_Scope>>* l_data{};
    t_std_collections_List_1Tt_mx2_Scope_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_data);
      bbGCMarkPtr(l_node);
    }
  }f0{};
  bbInt l_n=this->m_Count();
  f0.l_data=bbArray<bbGCVar<t_mx2_Scope>>::create(l_n);
  f0.l_node=this->m__0head->m__0succ;
  {
    bbInt l_i=bbInt(0);
    for(;(l_i<l_n);l_i+=1){
      f0.l_data->at(l_i)=f0.l_node->m__0value;
      f0.l_node=f0.l_node->m__0succ;
    }
  }
  return f0.l_data;
}

void t_std_collections_List_1Tt_mx2_Scope_2::m_Sort(bbFunction<bbInt(t_mx2_Scope*,t_mx2_Scope*)> l_compareFunc){
  bbInt l_insize=1;
  for(;;){
    struct f1_t : public bbGCFrame{
      t_std_collections_List_1Tt_mx2_Scope_2_Node* l_p{};
      t_std_collections_List_1Tt_mx2_Scope_2_Node* l_tail{};
      void gcMark(){
        bbGCMarkPtr(l_p);
        bbGCMarkPtr(l_tail);
      }
    }f1{};
    bbInt l_merges=bbInt(0);
    f1.l_tail=this->m__0head;
    f1.l_p=this->m__0head->m__0succ;
    while((f1.l_p!=this->m__0head)){
      struct f2_t : public bbGCFrame{
        t_std_collections_List_1Tt_mx2_Scope_2_Node* l_q{};
        void gcMark(){
          bbGCMarkPtr(l_q);
        }
      }f2{};
      l_merges+=1;
      f2.l_q=f1.l_p->m__0succ;
      bbInt l_qsize=l_insize;
      bbInt l_psize=1;
      while(((l_psize<l_insize)&&(f2.l_q!=this->m__0head))){
        l_psize+=1;
        f2.l_q=f2.l_q->m__0succ;
      }
      for(;;){
        struct f3_t : public bbGCFrame{
          t_std_collections_List_1Tt_mx2_Scope_2_Node* l_t{};
          void gcMark(){
            bbGCMarkPtr(l_t);
          }
        }f3{};
        if(((bbBool(l_psize)&&bbBool(l_qsize))&&(f2.l_q!=this->m__0head))){
          bbInt l_cc=l_compareFunc(f1.l_p->m__0value,f2.l_q->m__0value);
          if((l_cc<=bbInt(0))){
            f3.l_t=f1.l_p;
            f1.l_p=f1.l_p->m__0succ;
            l_psize-=1;
          }else{
            f3.l_t=f2.l_q;
            f2.l_q=f2.l_q->m__0succ;
            l_qsize-=1;
          }
        }else if(bbBool(l_psize)){
          f3.l_t=f1.l_p;
          f1.l_p=f1.l_p->m__0succ;
          l_psize-=1;
        }else if((bbBool(l_qsize)&&(f2.l_q!=this->m__0head))){
          f3.l_t=f2.l_q;
          f2.l_q=f2.l_q->m__0succ;
          l_qsize-=1;
        }else{
          break;
        }
        f3.l_t->m__0pred=f1.l_tail;
        f1.l_tail->m__0succ=f3.l_t;
        f1.l_tail=f3.l_t;
      }
      f1.l_p=f2.l_q;
    }
    f1.l_tail->m__0succ=this->m__0head;
    this->m__0head->m__0pred=f1.l_tail;
    if((l_merges<=1)){
      return;
    }
    l_insize*=2;
  }
}

void t_std_collections_List_1Tt_mx2_Scope_2::m_Sort(bbBool l_ascending){
  if(l_ascending){
    struct lambda8 : public bbFunction<bbInt(t_mx2_Scope*,t_mx2_Scope*)>::Rep{
      t_std_collections_List_1Tt_mx2_Scope_2* l_self;
      lambda8(t_std_collections_List_1Tt_mx2_Scope_2* l_self):l_self(l_self){
      }
      bbInt invoke(t_mx2_Scope* l_x,t_mx2_Scope* l_y){
        return bbCompare(l_x,l_y);
      }
      void gcMark(){
        bbGCMarkPtr(l_self);
      }
    };
    this->m_Sort(bbFunction<bbInt(t_mx2_Scope*,t_mx2_Scope*)>(new lambda8(this)));
  }else{
    struct lambda9 : public bbFunction<bbInt(t_mx2_Scope*,t_mx2_Scope*)>::Rep{
      t_std_collections_List_1Tt_mx2_Scope_2* l_self;
      lambda9(t_std_collections_List_1Tt_mx2_Scope_2* l_self):l_self(l_self){
      }
      bbInt invoke(t_mx2_Scope* l_x,t_mx2_Scope* l_y){
        return -bbCompare(l_x,l_y);
      }
      void gcMark(){
        bbGCMarkPtr(l_self);
      }
    };
    this->m_Sort(bbFunction<bbInt(t_mx2_Scope*,t_mx2_Scope*)>(new lambda9(this)));
  }
}

t_mx2_Scope* t_std_collections_List_1Tt_mx2_Scope_2::m_RemoveLast(){
  struct f0_t : public bbGCFrame{
    t_mx2_Scope* l_value{};
    void gcMark(){
      bbGCMarkPtr(l_value);
    }
  }f0{};
  bbDebugAssert(!this->m_Empty(),BB_T("Debug assert failed"));
  f0.l_value=this->m__0head->m__0pred->m__0value;
  this->m__0head->m__0pred->m_Remove();
  this->m__0seq+=1;
  return f0.l_value;
}

bbBool t_std_collections_List_1Tt_mx2_Scope_2::m_RemoveLast(t_mx2_Scope* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_mx2_Scope_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m_FindLastNode(l_value);
  if(!bbBool(f0.l_node)){
    return false;
  }
  f0.l_node->m_Remove();
  this->m__0seq+=1;
  return true;
}

t_mx2_Scope* t_std_collections_List_1Tt_mx2_Scope_2::m_RemoveFirst(){
  struct f0_t : public bbGCFrame{
    t_mx2_Scope* l_value{};
    void gcMark(){
      bbGCMarkPtr(l_value);
    }
  }f0{};
  bbDebugAssert(!this->m_Empty(),BB_T("Debug assert failed"));
  f0.l_value=this->m__0head->m__0succ->m__0value;
  this->m__0head->m__0succ->m_Remove();
  this->m__0seq+=1;
  return f0.l_value;
}

bbInt t_std_collections_List_1Tt_mx2_Scope_2::m_RemoveEach(t_mx2_Scope* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_mx2_Scope_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m__0head->m__0succ;
  bbInt l_n=bbInt(0);
  while((f0.l_node!=this->m__0head)){
    if((f0.l_node->m__0value==l_value)){
      f0.l_node=f0.l_node->m__0succ;
      f0.l_node->m__0pred->m_Remove();
      l_n+=1;
    }else{
      f0.l_node=f0.l_node->m__0succ;
    }
  }
  if(bbBool(l_n)){
    this->m__0seq+=1;
  }
  return l_n;
}

bbBool t_std_collections_List_1Tt_mx2_Scope_2::m_Remove(t_mx2_Scope* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_mx2_Scope_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m_FindNode(l_value);
  if(!bbBool(f0.l_node)){
    return false;
  }
  f0.l_node->m_Remove();
  this->m__0seq+=1;
  return true;
}

t_std_collections_List_1Tt_mx2_Scope_2_Node* t_std_collections_List_1Tt_mx2_Scope_2::m_LastNode(){
  if(!this->m_Empty()){
    return this->m__0head->m__0pred;
  }
  return ((t_std_collections_List_1Tt_mx2_Scope_2_Node*)0);
}

t_mx2_Scope* t_std_collections_List_1Tt_mx2_Scope_2::m_Last(){
  bbDebugAssert(!this->m_Empty(),BB_T("Debug assert failed"));
  return this->m__0head->m__0pred->m__0value;
}

t_std_collections_List_1Tt_mx2_Scope_2_Node* t_std_collections_List_1Tt_mx2_Scope_2::m_HeadNode(){
  return this->m__0head;
}

t_std_collections_List_1Tt_mx2_Scope_2_Node* t_std_collections_List_1Tt_mx2_Scope_2::m_FirstNode(){
  if(!this->m_Empty()){
    return this->m__0head->m__0succ;
  }
  return ((t_std_collections_List_1Tt_mx2_Scope_2_Node*)0);
}

t_mx2_Scope* t_std_collections_List_1Tt_mx2_Scope_2::m_First(){
  bbDebugAssert(!this->m_Empty(),BB_T("Debug assert failed"));
  return this->m__0head->m__0succ->m__0value;
}

t_std_collections_List_1Tt_mx2_Scope_2_Node* t_std_collections_List_1Tt_mx2_Scope_2::m_FindNode(t_mx2_Scope* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_mx2_Scope_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m__0head->m__0succ;
  while((f0.l_node!=this->m__0head)){
    if((f0.l_node->m__0value==l_value)){
      return f0.l_node;
    }
    f0.l_node=f0.l_node->m__0succ;
  }
  return ((t_std_collections_List_1Tt_mx2_Scope_2_Node*)0);
}

t_std_collections_List_1Tt_mx2_Scope_2_Node* t_std_collections_List_1Tt_mx2_Scope_2::m_FindLastNode(t_mx2_Scope* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_mx2_Scope_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m__0head->m__0pred;
  while((f0.l_node!=this->m__0head)){
    if((f0.l_node->m__0value==l_value)){
      return f0.l_node;
    }
    f0.l_node=f0.l_node->m__0pred;
  }
  return ((t_std_collections_List_1Tt_mx2_Scope_2_Node*)0);
}

bbBool t_std_collections_List_1Tt_mx2_Scope_2::m_Empty(){
  return (this->m__0head->m__0succ==this->m__0head);
}

bbInt t_std_collections_List_1Tt_mx2_Scope_2::m_Count(){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_mx2_Scope_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m__0head->m__0succ;
  bbInt l_n=bbInt(0);
  while((f0.l_node!=this->m__0head)){
    f0.l_node=f0.l_node->m__0succ;
    l_n+=1;
  }
  return l_n;
}

void t_std_collections_List_1Tt_mx2_Scope_2::m_Clear(){
  this->m__0head->m__0succ=this->m__0head;
  this->m__0head->m__0pred=this->m__0head;
  this->m__0seq+=1;
}

t_std_collections_List_1Tt_mx2_Scope_2_BackwardsIterator t_std_collections_List_1Tt_mx2_Scope_2::m_Backwards(){
  return t_std_collections_List_1Tt_mx2_Scope_2_BackwardsIterator(this,this->m__0head->m__0pred);
}

t_std_collections_List_1Tt_mx2_Scope_2_Iterator t_std_collections_List_1Tt_mx2_Scope_2::m_All(){
  return t_std_collections_List_1Tt_mx2_Scope_2_Iterator(this,this->m__0head->m__0succ);
}

t_std_collections_List_1Tt_mx2_Scope_2_Node* t_std_collections_List_1Tt_mx2_Scope_2::m_AddLast(t_mx2_Scope* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_mx2_Scope_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=bbGCNew<t_std_collections_List_1Tt_mx2_Scope_2_Node>(l_value,this->m__0head);
  this->m__0seq+=1;
  return f0.l_node;
}

t_std_collections_List_1Tt_mx2_Scope_2_Node* t_std_collections_List_1Tt_mx2_Scope_2::m_AddFirst(t_mx2_Scope* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_mx2_Scope_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=bbGCNew<t_std_collections_List_1Tt_mx2_Scope_2_Node>(l_value,this->m__0head->m__0succ);
  this->m__0seq+=1;
  return f0.l_node;
}

void t_std_collections_List_1Tt_mx2_Scope_2::m_AddAll(bbArray<bbGCVar<t_mx2_Scope>>* l_values){
  {
    bbInt l_0=bbInt(0);
    bbInt l_1=l_values->length();
    for(;(l_0<l_1);l_0+=1){
      struct f2_t : public bbGCFrame{
        t_mx2_Scope* l_value{};
        void gcMark(){
          bbGCMarkPtr(l_value);
        }
      }f2{};
      f2.l_value=l_values->at(l_0);
      this->m_AddLast(f2.l_value);
    }
  }
}

void t_std_collections_List_1Tt_mx2_Scope_2::m_Add(t_mx2_Scope* l_value){
  this->m_AddLast(l_value);
}

void t_std_collections_List_1Tt_mx2_SNode_2_Node::gcMark(){
  bbGCMark(m__0succ);
  bbGCMark(m__0pred);
  bbGCMark(m__0value);
}

t_std_collections_List_1Tt_mx2_SNode_2_Node::t_std_collections_List_1Tt_mx2_SNode_2_Node(t_mx2_SNode* l_value,t_std_collections_List_1Tt_mx2_SNode_2_Node* l_succ){
  this->m__0value=l_value;
  this->m__0succ=l_succ;
  this->m__0pred=l_succ->m__0pred;
  this->m__0pred->m__0succ=this;
  l_succ->m__0pred=this;
}

t_std_collections_List_1Tt_mx2_SNode_2_Node::t_std_collections_List_1Tt_mx2_SNode_2_Node(t_mx2_SNode* l_value){
  this->m__0value=l_value;
  this->m__0succ=this;
  this->m__0pred=this;
}

void t_std_collections_List_1Tt_mx2_SNode_2_Node::m_Value(t_mx2_SNode* l_value){
  this->m__0value=l_value;
}

t_mx2_SNode* t_std_collections_List_1Tt_mx2_SNode_2_Node::m_Value(){
  return this->m__0value;
}

t_std_collections_List_1Tt_mx2_SNode_2_Node* t_std_collections_List_1Tt_mx2_SNode_2_Node::m_Succ(){
  return this->m__0succ;
}

void t_std_collections_List_1Tt_mx2_SNode_2_Node::m_Remove(){
  this->m__0succ->m__0pred=this->m__0pred;
  this->m__0pred->m__0succ=this->m__0succ;
}

t_std_collections_List_1Tt_mx2_SNode_2_Node* t_std_collections_List_1Tt_mx2_SNode_2_Node::m_Pred(){
  return this->m__0pred;
}

void t_std_collections_List_1Tt_mx2_SNode_2_Node::m_InsertBefore(t_std_collections_List_1Tt_mx2_SNode_2_Node* l_node){
  this->m__0succ=l_node;
  this->m__0pred=l_node->m__0pred;
  this->m__0pred->m__0succ=this;
  l_node->m__0pred=this;
}

void t_std_collections_List_1Tt_mx2_SNode_2_Node::m_InsertAfter(t_std_collections_List_1Tt_mx2_SNode_2_Node* l_node){
  this->m__0pred=l_node;
  this->m__0succ=l_node->m__0succ;
  this->m__0succ->m__0pred=this;
  l_node->m__0succ=this;
}

t_std_collections_List_1Tt_mx2_SNode_2_Iterator::t_std_collections_List_1Tt_mx2_SNode_2_Iterator(t_std_collections_List_1Tt_mx2_SNode_2* l_list,t_std_collections_List_1Tt_mx2_SNode_2_Node* l_node){
  (*this).m__0list=l_list;
  (*this).m__0node=l_node;
  (*this).m__0seq=l_list->m__0seq;
}

void t_std_collections_List_1Tt_mx2_SNode_2_Iterator::m_Insert(t_mx2_SNode* l_value){
  (*this).m_AssertSeq();
  (*this).m__0node=bbGCNew<t_std_collections_List_1Tt_mx2_SNode_2_Node>(l_value,(*this).m__0node);
  (*this).m__0list->m__0seq+=1;
  (*this).m__0seq=(*this).m__0list->m__0seq;
}

void t_std_collections_List_1Tt_mx2_SNode_2_Iterator::m_Erase(){
  (*this).m_AssertCurrent();
  (*this).m__0node=(*this).m__0node->m__0succ;
  (*this).m__0node->m__0pred->m_Remove();
  (*this).m__0list->m__0seq+=1;
  (*this).m__0seq=(*this).m__0list->m__0seq;
}

void t_std_collections_List_1Tt_mx2_SNode_2_Iterator::m_Current(t_mx2_SNode* l_current){
  (*this).m_AssertCurrent();
  (*this).m__0node->m__0value=l_current;
}

t_mx2_SNode* t_std_collections_List_1Tt_mx2_SNode_2_Iterator::m_Current(){
  (*this).m_AssertCurrent();
  return (*this).m__0node->m__0value;
}

void t_std_collections_List_1Tt_mx2_SNode_2_Iterator::m_Bump(){
  (*this).m_AssertCurrent();
  (*this).m__0node=(*this).m__0node->m__0succ;
}

bbBool t_std_collections_List_1Tt_mx2_SNode_2_Iterator::m_AtEnd(){
  (*this).m_AssertSeq();
  return ((*this).m__0node==(*this).m__0list->m__0head);
}

void t_std_collections_List_1Tt_mx2_SNode_2_Iterator::m_AssertSeq(){
  bbDebugAssert(((*this).m__0seq==(*this).m__0list->m__0seq),BB_T("Concurrent list modification"));
}

void t_std_collections_List_1Tt_mx2_SNode_2_Iterator::m_AssertCurrent(){
  bbDebugAssert(!(*this).m_AtEnd(),BB_T("Invalid list iterator"));
}

int bbCompare(const t_std_collections_List_1Tt_mx2_SNode_2_Iterator&x,const t_std_collections_List_1Tt_mx2_SNode_2_Iterator&y){
  if(int t=bbCompare(x.m__0list,y.m__0list)) return t;
  if(int t=bbCompare(x.m__0node,y.m__0node)) return t;
  if(int t=bbCompare(x.m__0seq,y.m__0seq)) return t;
  return 0;
}

void bbGCMark(const t_std_collections_List_1Tt_mx2_SNode_2_Iterator&t){
  bbGCMark(t.m__0list);
  bbGCMark(t.m__0node);
}

t_std_collections_List_1Tt_mx2_SNode_2_BackwardsIterator::t_std_collections_List_1Tt_mx2_SNode_2_BackwardsIterator(t_std_collections_List_1Tt_mx2_SNode_2* l_list,t_std_collections_List_1Tt_mx2_SNode_2_Node* l_node){
  (*this).m__0list=l_list;
  (*this).m__0node=l_node;
  (*this).m__0seq=l_list->m__0seq;
}

void t_std_collections_List_1Tt_mx2_SNode_2_BackwardsIterator::m_Insert(t_mx2_SNode* l_value){
  (*this).m_AssertSeq();
  (*this).m__0node=bbGCNew<t_std_collections_List_1Tt_mx2_SNode_2_Node>(l_value,(*this).m__0node->m__0succ);
  (*this).m__0list->m__0seq+=1;
  (*this).m__0seq=(*this).m__0list->m__0seq;
}

void t_std_collections_List_1Tt_mx2_SNode_2_BackwardsIterator::m_Erase(){
  (*this).m_AssertCurrent();
  (*this).m__0node=(*this).m__0node->m__0pred;
  (*this).m__0node->m__0succ->m_Remove();
  (*this).m__0list->m__0seq+=1;
  (*this).m__0seq=(*this).m__0list->m__0seq;
}

void t_std_collections_List_1Tt_mx2_SNode_2_BackwardsIterator::m_Current(t_mx2_SNode* l_current){
  (*this).m_AssertCurrent();
  (*this).m__0node->m__0value=l_current;
}

t_mx2_SNode* t_std_collections_List_1Tt_mx2_SNode_2_BackwardsIterator::m_Current(){
  (*this).m_AssertCurrent();
  return (*this).m__0node->m__0value;
}

void t_std_collections_List_1Tt_mx2_SNode_2_BackwardsIterator::m_Bump(){
  (*this).m_AssertCurrent();
  (*this).m__0node=(*this).m__0node->m__0pred;
}

bbBool t_std_collections_List_1Tt_mx2_SNode_2_BackwardsIterator::m_AtEnd(){
  (*this).m_AssertSeq();
  return ((*this).m__0node==(*this).m__0list->m__0head);
}

void t_std_collections_List_1Tt_mx2_SNode_2_BackwardsIterator::m_AssertSeq(){
  bbDebugAssert(((*this).m__0seq==(*this).m__0list->m__0seq),BB_T("Concurrent list modification"));
}

void t_std_collections_List_1Tt_mx2_SNode_2_BackwardsIterator::m_AssertCurrent(){
  bbDebugAssert(!(*this).m_AtEnd(),BB_T("Invalid list iterator"));
}

int bbCompare(const t_std_collections_List_1Tt_mx2_SNode_2_BackwardsIterator&x,const t_std_collections_List_1Tt_mx2_SNode_2_BackwardsIterator&y){
  if(int t=bbCompare(x.m__0list,y.m__0list)) return t;
  if(int t=bbCompare(x.m__0node,y.m__0node)) return t;
  if(int t=bbCompare(x.m__0seq,y.m__0seq)) return t;
  return 0;
}

void bbGCMark(const t_std_collections_List_1Tt_mx2_SNode_2_BackwardsIterator&t){
  bbGCMark(t.m__0list);
  bbGCMark(t.m__0node);
}

void t_std_collections_List_1Tt_mx2_SNode_2::gcMark(){
  bbGCMark(m__0head);
}

t_std_collections_List_1Tt_mx2_SNode_2::t_std_collections_List_1Tt_mx2_SNode_2(t_std_collections_List_1Tt_mx2_SNode_2* l_values):t_std_collections_List_1Tt_mx2_SNode_2(){
  g_std_collections_List_1Tt_mx2_SNode_2_AddAll_1Tt_std_collections_List_1Tt_mx2_SNode_2_2(this,l_values);
}

t_std_collections_List_1Tt_mx2_SNode_2::t_std_collections_List_1Tt_mx2_SNode_2(t_std_collections_Stack_1Tt_mx2_SNode_2* l_values):t_std_collections_List_1Tt_mx2_SNode_2(){
  g_std_collections_List_1Tt_mx2_SNode_2_AddAll_1Tt_std_collections_Stack_1Tt_mx2_SNode_2_2(this,l_values);
}

t_std_collections_List_1Tt_mx2_SNode_2::t_std_collections_List_1Tt_mx2_SNode_2(bbArray<bbGCVar<t_mx2_SNode>>* l_values):t_std_collections_List_1Tt_mx2_SNode_2(){
  this->m_AddAll(l_values);
}

t_std_collections_List_1Tt_mx2_SNode_2::t_std_collections_List_1Tt_mx2_SNode_2(){
  this->m__0head=bbGCNew<t_std_collections_List_1Tt_mx2_SNode_2_Node>(((t_mx2_SNode*)0));
}

bbArray<bbGCVar<t_mx2_SNode>>* t_std_collections_List_1Tt_mx2_SNode_2::m_ToArray(){
  struct f0_t : public bbGCFrame{
    bbArray<bbGCVar<t_mx2_SNode>>* l_data{};
    t_std_collections_List_1Tt_mx2_SNode_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_data);
      bbGCMarkPtr(l_node);
    }
  }f0{};
  bbInt l_n=this->m_Count();
  f0.l_data=bbArray<bbGCVar<t_mx2_SNode>>::create(l_n);
  f0.l_node=this->m__0head->m__0succ;
  {
    bbInt l_i=bbInt(0);
    for(;(l_i<l_n);l_i+=1){
      f0.l_data->at(l_i)=f0.l_node->m__0value;
      f0.l_node=f0.l_node->m__0succ;
    }
  }
  return f0.l_data;
}

void t_std_collections_List_1Tt_mx2_SNode_2::m_Sort(bbFunction<bbInt(t_mx2_SNode*,t_mx2_SNode*)> l_compareFunc){
  bbInt l_insize=1;
  for(;;){
    struct f1_t : public bbGCFrame{
      t_std_collections_List_1Tt_mx2_SNode_2_Node* l_p{};
      t_std_collections_List_1Tt_mx2_SNode_2_Node* l_tail{};
      void gcMark(){
        bbGCMarkPtr(l_p);
        bbGCMarkPtr(l_tail);
      }
    }f1{};
    bbInt l_merges=bbInt(0);
    f1.l_tail=this->m__0head;
    f1.l_p=this->m__0head->m__0succ;
    while((f1.l_p!=this->m__0head)){
      struct f2_t : public bbGCFrame{
        t_std_collections_List_1Tt_mx2_SNode_2_Node* l_q{};
        void gcMark(){
          bbGCMarkPtr(l_q);
        }
      }f2{};
      l_merges+=1;
      f2.l_q=f1.l_p->m__0succ;
      bbInt l_qsize=l_insize;
      bbInt l_psize=1;
      while(((l_psize<l_insize)&&(f2.l_q!=this->m__0head))){
        l_psize+=1;
        f2.l_q=f2.l_q->m__0succ;
      }
      for(;;){
        struct f3_t : public bbGCFrame{
          t_std_collections_List_1Tt_mx2_SNode_2_Node* l_t{};
          void gcMark(){
            bbGCMarkPtr(l_t);
          }
        }f3{};
        if(((bbBool(l_psize)&&bbBool(l_qsize))&&(f2.l_q!=this->m__0head))){
          bbInt l_cc=l_compareFunc(f1.l_p->m__0value,f2.l_q->m__0value);
          if((l_cc<=bbInt(0))){
            f3.l_t=f1.l_p;
            f1.l_p=f1.l_p->m__0succ;
            l_psize-=1;
          }else{
            f3.l_t=f2.l_q;
            f2.l_q=f2.l_q->m__0succ;
            l_qsize-=1;
          }
        }else if(bbBool(l_psize)){
          f3.l_t=f1.l_p;
          f1.l_p=f1.l_p->m__0succ;
          l_psize-=1;
        }else if((bbBool(l_qsize)&&(f2.l_q!=this->m__0head))){
          f3.l_t=f2.l_q;
          f2.l_q=f2.l_q->m__0succ;
          l_qsize-=1;
        }else{
          break;
        }
        f3.l_t->m__0pred=f1.l_tail;
        f1.l_tail->m__0succ=f3.l_t;
        f1.l_tail=f3.l_t;
      }
      f1.l_p=f2.l_q;
    }
    f1.l_tail->m__0succ=this->m__0head;
    this->m__0head->m__0pred=f1.l_tail;
    if((l_merges<=1)){
      return;
    }
    l_insize*=2;
  }
}

void t_std_collections_List_1Tt_mx2_SNode_2::m_Sort(bbBool l_ascending){
  if(l_ascending){
    struct lambda10 : public bbFunction<bbInt(t_mx2_SNode*,t_mx2_SNode*)>::Rep{
      t_std_collections_List_1Tt_mx2_SNode_2* l_self;
      lambda10(t_std_collections_List_1Tt_mx2_SNode_2* l_self):l_self(l_self){
      }
      bbInt invoke(t_mx2_SNode* l_x,t_mx2_SNode* l_y){
        return bbCompare(l_x,l_y);
      }
      void gcMark(){
        bbGCMarkPtr(l_self);
      }
    };
    this->m_Sort(bbFunction<bbInt(t_mx2_SNode*,t_mx2_SNode*)>(new lambda10(this)));
  }else{
    struct lambda11 : public bbFunction<bbInt(t_mx2_SNode*,t_mx2_SNode*)>::Rep{
      t_std_collections_List_1Tt_mx2_SNode_2* l_self;
      lambda11(t_std_collections_List_1Tt_mx2_SNode_2* l_self):l_self(l_self){
      }
      bbInt invoke(t_mx2_SNode* l_x,t_mx2_SNode* l_y){
        return -bbCompare(l_x,l_y);
      }
      void gcMark(){
        bbGCMarkPtr(l_self);
      }
    };
    this->m_Sort(bbFunction<bbInt(t_mx2_SNode*,t_mx2_SNode*)>(new lambda11(this)));
  }
}

t_mx2_SNode* t_std_collections_List_1Tt_mx2_SNode_2::m_RemoveLast(){
  struct f0_t : public bbGCFrame{
    t_mx2_SNode* l_value{};
    void gcMark(){
      bbGCMarkPtr(l_value);
    }
  }f0{};
  bbDebugAssert(!this->m_Empty(),BB_T("Debug assert failed"));
  f0.l_value=this->m__0head->m__0pred->m__0value;
  this->m__0head->m__0pred->m_Remove();
  this->m__0seq+=1;
  return f0.l_value;
}

bbBool t_std_collections_List_1Tt_mx2_SNode_2::m_RemoveLast(t_mx2_SNode* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_mx2_SNode_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m_FindLastNode(l_value);
  if(!bbBool(f0.l_node)){
    return false;
  }
  f0.l_node->m_Remove();
  this->m__0seq+=1;
  return true;
}

t_mx2_SNode* t_std_collections_List_1Tt_mx2_SNode_2::m_RemoveFirst(){
  struct f0_t : public bbGCFrame{
    t_mx2_SNode* l_value{};
    void gcMark(){
      bbGCMarkPtr(l_value);
    }
  }f0{};
  bbDebugAssert(!this->m_Empty(),BB_T("Debug assert failed"));
  f0.l_value=this->m__0head->m__0succ->m__0value;
  this->m__0head->m__0succ->m_Remove();
  this->m__0seq+=1;
  return f0.l_value;
}

bbInt t_std_collections_List_1Tt_mx2_SNode_2::m_RemoveEach(t_mx2_SNode* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_mx2_SNode_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m__0head->m__0succ;
  bbInt l_n=bbInt(0);
  while((f0.l_node!=this->m__0head)){
    if((f0.l_node->m__0value==l_value)){
      f0.l_node=f0.l_node->m__0succ;
      f0.l_node->m__0pred->m_Remove();
      l_n+=1;
    }else{
      f0.l_node=f0.l_node->m__0succ;
    }
  }
  if(bbBool(l_n)){
    this->m__0seq+=1;
  }
  return l_n;
}

bbBool t_std_collections_List_1Tt_mx2_SNode_2::m_Remove(t_mx2_SNode* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_mx2_SNode_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m_FindNode(l_value);
  if(!bbBool(f0.l_node)){
    return false;
  }
  f0.l_node->m_Remove();
  this->m__0seq+=1;
  return true;
}

t_std_collections_List_1Tt_mx2_SNode_2_Node* t_std_collections_List_1Tt_mx2_SNode_2::m_LastNode(){
  if(!this->m_Empty()){
    return this->m__0head->m__0pred;
  }
  return ((t_std_collections_List_1Tt_mx2_SNode_2_Node*)0);
}

t_mx2_SNode* t_std_collections_List_1Tt_mx2_SNode_2::m_Last(){
  bbDebugAssert(!this->m_Empty(),BB_T("Debug assert failed"));
  return this->m__0head->m__0pred->m__0value;
}

t_std_collections_List_1Tt_mx2_SNode_2_Node* t_std_collections_List_1Tt_mx2_SNode_2::m_HeadNode(){
  return this->m__0head;
}

t_std_collections_List_1Tt_mx2_SNode_2_Node* t_std_collections_List_1Tt_mx2_SNode_2::m_FirstNode(){
  if(!this->m_Empty()){
    return this->m__0head->m__0succ;
  }
  return ((t_std_collections_List_1Tt_mx2_SNode_2_Node*)0);
}

t_mx2_SNode* t_std_collections_List_1Tt_mx2_SNode_2::m_First(){
  bbDebugAssert(!this->m_Empty(),BB_T("Debug assert failed"));
  return this->m__0head->m__0succ->m__0value;
}

t_std_collections_List_1Tt_mx2_SNode_2_Node* t_std_collections_List_1Tt_mx2_SNode_2::m_FindNode(t_mx2_SNode* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_mx2_SNode_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m__0head->m__0succ;
  while((f0.l_node!=this->m__0head)){
    if((f0.l_node->m__0value==l_value)){
      return f0.l_node;
    }
    f0.l_node=f0.l_node->m__0succ;
  }
  return ((t_std_collections_List_1Tt_mx2_SNode_2_Node*)0);
}

t_std_collections_List_1Tt_mx2_SNode_2_Node* t_std_collections_List_1Tt_mx2_SNode_2::m_FindLastNode(t_mx2_SNode* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_mx2_SNode_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m__0head->m__0pred;
  while((f0.l_node!=this->m__0head)){
    if((f0.l_node->m__0value==l_value)){
      return f0.l_node;
    }
    f0.l_node=f0.l_node->m__0pred;
  }
  return ((t_std_collections_List_1Tt_mx2_SNode_2_Node*)0);
}

bbBool t_std_collections_List_1Tt_mx2_SNode_2::m_Empty(){
  return (this->m__0head->m__0succ==this->m__0head);
}

bbInt t_std_collections_List_1Tt_mx2_SNode_2::m_Count(){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_mx2_SNode_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m__0head->m__0succ;
  bbInt l_n=bbInt(0);
  while((f0.l_node!=this->m__0head)){
    f0.l_node=f0.l_node->m__0succ;
    l_n+=1;
  }
  return l_n;
}

void t_std_collections_List_1Tt_mx2_SNode_2::m_Clear(){
  this->m__0head->m__0succ=this->m__0head;
  this->m__0head->m__0pred=this->m__0head;
  this->m__0seq+=1;
}

t_std_collections_List_1Tt_mx2_SNode_2_BackwardsIterator t_std_collections_List_1Tt_mx2_SNode_2::m_Backwards(){
  return t_std_collections_List_1Tt_mx2_SNode_2_BackwardsIterator(this,this->m__0head->m__0pred);
}

t_std_collections_List_1Tt_mx2_SNode_2_Iterator t_std_collections_List_1Tt_mx2_SNode_2::m_All(){
  return t_std_collections_List_1Tt_mx2_SNode_2_Iterator(this,this->m__0head->m__0succ);
}

t_std_collections_List_1Tt_mx2_SNode_2_Node* t_std_collections_List_1Tt_mx2_SNode_2::m_AddLast(t_mx2_SNode* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_mx2_SNode_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=bbGCNew<t_std_collections_List_1Tt_mx2_SNode_2_Node>(l_value,this->m__0head);
  this->m__0seq+=1;
  return f0.l_node;
}

t_std_collections_List_1Tt_mx2_SNode_2_Node* t_std_collections_List_1Tt_mx2_SNode_2::m_AddFirst(t_mx2_SNode* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_mx2_SNode_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=bbGCNew<t_std_collections_List_1Tt_mx2_SNode_2_Node>(l_value,this->m__0head->m__0succ);
  this->m__0seq+=1;
  return f0.l_node;
}

void t_std_collections_List_1Tt_mx2_SNode_2::m_AddAll(bbArray<bbGCVar<t_mx2_SNode>>* l_values){
  {
    bbInt l_0=bbInt(0);
    bbInt l_1=l_values->length();
    for(;(l_0<l_1);l_0+=1){
      struct f2_t : public bbGCFrame{
        t_mx2_SNode* l_value{};
        void gcMark(){
          bbGCMarkPtr(l_value);
        }
      }f2{};
      f2.l_value=l_values->at(l_0);
      this->m_AddLast(f2.l_value);
    }
  }
}

void t_std_collections_List_1Tt_mx2_SNode_2::m_Add(t_mx2_SNode* l_value){
  this->m_AddLast(l_value);
}

void t_std_collections_List_1Tt_mx2_VarValue_2_Node::gcMark(){
  bbGCMark(m__0succ);
  bbGCMark(m__0pred);
  bbGCMark(m__0value);
}

t_std_collections_List_1Tt_mx2_VarValue_2_Node::t_std_collections_List_1Tt_mx2_VarValue_2_Node(t_mx2_VarValue* l_value,t_std_collections_List_1Tt_mx2_VarValue_2_Node* l_succ){
  this->m__0value=l_value;
  this->m__0succ=l_succ;
  this->m__0pred=l_succ->m__0pred;
  this->m__0pred->m__0succ=this;
  l_succ->m__0pred=this;
}

t_std_collections_List_1Tt_mx2_VarValue_2_Node::t_std_collections_List_1Tt_mx2_VarValue_2_Node(t_mx2_VarValue* l_value){
  this->m__0value=l_value;
  this->m__0succ=this;
  this->m__0pred=this;
}

void t_std_collections_List_1Tt_mx2_VarValue_2_Node::m_Value(t_mx2_VarValue* l_value){
  this->m__0value=l_value;
}

t_mx2_VarValue* t_std_collections_List_1Tt_mx2_VarValue_2_Node::m_Value(){
  return this->m__0value;
}

t_std_collections_List_1Tt_mx2_VarValue_2_Node* t_std_collections_List_1Tt_mx2_VarValue_2_Node::m_Succ(){
  return this->m__0succ;
}

void t_std_collections_List_1Tt_mx2_VarValue_2_Node::m_Remove(){
  this->m__0succ->m__0pred=this->m__0pred;
  this->m__0pred->m__0succ=this->m__0succ;
}

t_std_collections_List_1Tt_mx2_VarValue_2_Node* t_std_collections_List_1Tt_mx2_VarValue_2_Node::m_Pred(){
  return this->m__0pred;
}

void t_std_collections_List_1Tt_mx2_VarValue_2_Node::m_InsertBefore(t_std_collections_List_1Tt_mx2_VarValue_2_Node* l_node){
  this->m__0succ=l_node;
  this->m__0pred=l_node->m__0pred;
  this->m__0pred->m__0succ=this;
  l_node->m__0pred=this;
}

void t_std_collections_List_1Tt_mx2_VarValue_2_Node::m_InsertAfter(t_std_collections_List_1Tt_mx2_VarValue_2_Node* l_node){
  this->m__0pred=l_node;
  this->m__0succ=l_node->m__0succ;
  this->m__0succ->m__0pred=this;
  l_node->m__0succ=this;
}

t_std_collections_List_1Tt_mx2_VarValue_2_Iterator::t_std_collections_List_1Tt_mx2_VarValue_2_Iterator(t_std_collections_List_1Tt_mx2_VarValue_2* l_list,t_std_collections_List_1Tt_mx2_VarValue_2_Node* l_node){
  (*this).m__0list=l_list;
  (*this).m__0node=l_node;
  (*this).m__0seq=l_list->m__0seq;
}

void t_std_collections_List_1Tt_mx2_VarValue_2_Iterator::m_Insert(t_mx2_VarValue* l_value){
  (*this).m_AssertSeq();
  (*this).m__0node=bbGCNew<t_std_collections_List_1Tt_mx2_VarValue_2_Node>(l_value,(*this).m__0node);
  (*this).m__0list->m__0seq+=1;
  (*this).m__0seq=(*this).m__0list->m__0seq;
}

void t_std_collections_List_1Tt_mx2_VarValue_2_Iterator::m_Erase(){
  (*this).m_AssertCurrent();
  (*this).m__0node=(*this).m__0node->m__0succ;
  (*this).m__0node->m__0pred->m_Remove();
  (*this).m__0list->m__0seq+=1;
  (*this).m__0seq=(*this).m__0list->m__0seq;
}

void t_std_collections_List_1Tt_mx2_VarValue_2_Iterator::m_Current(t_mx2_VarValue* l_current){
  (*this).m_AssertCurrent();
  (*this).m__0node->m__0value=l_current;
}

t_mx2_VarValue* t_std_collections_List_1Tt_mx2_VarValue_2_Iterator::m_Current(){
  (*this).m_AssertCurrent();
  return (*this).m__0node->m__0value;
}

void t_std_collections_List_1Tt_mx2_VarValue_2_Iterator::m_Bump(){
  (*this).m_AssertCurrent();
  (*this).m__0node=(*this).m__0node->m__0succ;
}

bbBool t_std_collections_List_1Tt_mx2_VarValue_2_Iterator::m_AtEnd(){
  (*this).m_AssertSeq();
  return ((*this).m__0node==(*this).m__0list->m__0head);
}

void t_std_collections_List_1Tt_mx2_VarValue_2_Iterator::m_AssertSeq(){
  bbDebugAssert(((*this).m__0seq==(*this).m__0list->m__0seq),BB_T("Concurrent list modification"));
}

void t_std_collections_List_1Tt_mx2_VarValue_2_Iterator::m_AssertCurrent(){
  bbDebugAssert(!(*this).m_AtEnd(),BB_T("Invalid list iterator"));
}

int bbCompare(const t_std_collections_List_1Tt_mx2_VarValue_2_Iterator&x,const t_std_collections_List_1Tt_mx2_VarValue_2_Iterator&y){
  if(int t=bbCompare(x.m__0list,y.m__0list)) return t;
  if(int t=bbCompare(x.m__0node,y.m__0node)) return t;
  if(int t=bbCompare(x.m__0seq,y.m__0seq)) return t;
  return 0;
}

void bbGCMark(const t_std_collections_List_1Tt_mx2_VarValue_2_Iterator&t){
  bbGCMark(t.m__0list);
  bbGCMark(t.m__0node);
}

t_std_collections_List_1Tt_mx2_VarValue_2_BackwardsIterator::t_std_collections_List_1Tt_mx2_VarValue_2_BackwardsIterator(t_std_collections_List_1Tt_mx2_VarValue_2* l_list,t_std_collections_List_1Tt_mx2_VarValue_2_Node* l_node){
  (*this).m__0list=l_list;
  (*this).m__0node=l_node;
  (*this).m__0seq=l_list->m__0seq;
}

void t_std_collections_List_1Tt_mx2_VarValue_2_BackwardsIterator::m_Insert(t_mx2_VarValue* l_value){
  (*this).m_AssertSeq();
  (*this).m__0node=bbGCNew<t_std_collections_List_1Tt_mx2_VarValue_2_Node>(l_value,(*this).m__0node->m__0succ);
  (*this).m__0list->m__0seq+=1;
  (*this).m__0seq=(*this).m__0list->m__0seq;
}

void t_std_collections_List_1Tt_mx2_VarValue_2_BackwardsIterator::m_Erase(){
  (*this).m_AssertCurrent();
  (*this).m__0node=(*this).m__0node->m__0pred;
  (*this).m__0node->m__0succ->m_Remove();
  (*this).m__0list->m__0seq+=1;
  (*this).m__0seq=(*this).m__0list->m__0seq;
}

void t_std_collections_List_1Tt_mx2_VarValue_2_BackwardsIterator::m_Current(t_mx2_VarValue* l_current){
  (*this).m_AssertCurrent();
  (*this).m__0node->m__0value=l_current;
}

t_mx2_VarValue* t_std_collections_List_1Tt_mx2_VarValue_2_BackwardsIterator::m_Current(){
  (*this).m_AssertCurrent();
  return (*this).m__0node->m__0value;
}

void t_std_collections_List_1Tt_mx2_VarValue_2_BackwardsIterator::m_Bump(){
  (*this).m_AssertCurrent();
  (*this).m__0node=(*this).m__0node->m__0pred;
}

bbBool t_std_collections_List_1Tt_mx2_VarValue_2_BackwardsIterator::m_AtEnd(){
  (*this).m_AssertSeq();
  return ((*this).m__0node==(*this).m__0list->m__0head);
}

void t_std_collections_List_1Tt_mx2_VarValue_2_BackwardsIterator::m_AssertSeq(){
  bbDebugAssert(((*this).m__0seq==(*this).m__0list->m__0seq),BB_T("Concurrent list modification"));
}

void t_std_collections_List_1Tt_mx2_VarValue_2_BackwardsIterator::m_AssertCurrent(){
  bbDebugAssert(!(*this).m_AtEnd(),BB_T("Invalid list iterator"));
}

int bbCompare(const t_std_collections_List_1Tt_mx2_VarValue_2_BackwardsIterator&x,const t_std_collections_List_1Tt_mx2_VarValue_2_BackwardsIterator&y){
  if(int t=bbCompare(x.m__0list,y.m__0list)) return t;
  if(int t=bbCompare(x.m__0node,y.m__0node)) return t;
  if(int t=bbCompare(x.m__0seq,y.m__0seq)) return t;
  return 0;
}

void bbGCMark(const t_std_collections_List_1Tt_mx2_VarValue_2_BackwardsIterator&t){
  bbGCMark(t.m__0list);
  bbGCMark(t.m__0node);
}

void t_std_collections_List_1Tt_mx2_VarValue_2::gcMark(){
  bbGCMark(m__0head);
}

t_std_collections_List_1Tt_mx2_VarValue_2::t_std_collections_List_1Tt_mx2_VarValue_2(t_std_collections_List_1Tt_mx2_VarValue_2* l_values):t_std_collections_List_1Tt_mx2_VarValue_2(){
  g_std_collections_List_1Tt_mx2_VarValue_2_AddAll_1Tt_std_collections_List_1Tt_mx2_VarValue_2_2(this,l_values);
}

t_std_collections_List_1Tt_mx2_VarValue_2::t_std_collections_List_1Tt_mx2_VarValue_2(t_std_collections_Stack_1Tt_mx2_VarValue_2* l_values):t_std_collections_List_1Tt_mx2_VarValue_2(){
  g_std_collections_List_1Tt_mx2_VarValue_2_AddAll_1Tt_std_collections_Stack_1Tt_mx2_VarValue_2_2(this,l_values);
}

t_std_collections_List_1Tt_mx2_VarValue_2::t_std_collections_List_1Tt_mx2_VarValue_2(bbArray<bbGCVar<t_mx2_VarValue>>* l_values):t_std_collections_List_1Tt_mx2_VarValue_2(){
  this->m_AddAll(l_values);
}

t_std_collections_List_1Tt_mx2_VarValue_2::t_std_collections_List_1Tt_mx2_VarValue_2(){
  this->m__0head=bbGCNew<t_std_collections_List_1Tt_mx2_VarValue_2_Node>(((t_mx2_VarValue*)0));
}

bbArray<bbGCVar<t_mx2_VarValue>>* t_std_collections_List_1Tt_mx2_VarValue_2::m_ToArray(){
  struct f0_t : public bbGCFrame{
    bbArray<bbGCVar<t_mx2_VarValue>>* l_data{};
    t_std_collections_List_1Tt_mx2_VarValue_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_data);
      bbGCMarkPtr(l_node);
    }
  }f0{};
  bbInt l_n=this->m_Count();
  f0.l_data=bbArray<bbGCVar<t_mx2_VarValue>>::create(l_n);
  f0.l_node=this->m__0head->m__0succ;
  {
    bbInt l_i=bbInt(0);
    for(;(l_i<l_n);l_i+=1){
      f0.l_data->at(l_i)=f0.l_node->m__0value;
      f0.l_node=f0.l_node->m__0succ;
    }
  }
  return f0.l_data;
}

void t_std_collections_List_1Tt_mx2_VarValue_2::m_Sort(bbFunction<bbInt(t_mx2_VarValue*,t_mx2_VarValue*)> l_compareFunc){
  bbInt l_insize=1;
  for(;;){
    struct f1_t : public bbGCFrame{
      t_std_collections_List_1Tt_mx2_VarValue_2_Node* l_p{};
      t_std_collections_List_1Tt_mx2_VarValue_2_Node* l_tail{};
      void gcMark(){
        bbGCMarkPtr(l_p);
        bbGCMarkPtr(l_tail);
      }
    }f1{};
    bbInt l_merges=bbInt(0);
    f1.l_tail=this->m__0head;
    f1.l_p=this->m__0head->m__0succ;
    while((f1.l_p!=this->m__0head)){
      struct f2_t : public bbGCFrame{
        t_std_collections_List_1Tt_mx2_VarValue_2_Node* l_q{};
        void gcMark(){
          bbGCMarkPtr(l_q);
        }
      }f2{};
      l_merges+=1;
      f2.l_q=f1.l_p->m__0succ;
      bbInt l_qsize=l_insize;
      bbInt l_psize=1;
      while(((l_psize<l_insize)&&(f2.l_q!=this->m__0head))){
        l_psize+=1;
        f2.l_q=f2.l_q->m__0succ;
      }
      for(;;){
        struct f3_t : public bbGCFrame{
          t_std_collections_List_1Tt_mx2_VarValue_2_Node* l_t{};
          void gcMark(){
            bbGCMarkPtr(l_t);
          }
        }f3{};
        if(((bbBool(l_psize)&&bbBool(l_qsize))&&(f2.l_q!=this->m__0head))){
          bbInt l_cc=l_compareFunc(f1.l_p->m__0value,f2.l_q->m__0value);
          if((l_cc<=bbInt(0))){
            f3.l_t=f1.l_p;
            f1.l_p=f1.l_p->m__0succ;
            l_psize-=1;
          }else{
            f3.l_t=f2.l_q;
            f2.l_q=f2.l_q->m__0succ;
            l_qsize-=1;
          }
        }else if(bbBool(l_psize)){
          f3.l_t=f1.l_p;
          f1.l_p=f1.l_p->m__0succ;
          l_psize-=1;
        }else if((bbBool(l_qsize)&&(f2.l_q!=this->m__0head))){
          f3.l_t=f2.l_q;
          f2.l_q=f2.l_q->m__0succ;
          l_qsize-=1;
        }else{
          break;
        }
        f3.l_t->m__0pred=f1.l_tail;
        f1.l_tail->m__0succ=f3.l_t;
        f1.l_tail=f3.l_t;
      }
      f1.l_p=f2.l_q;
    }
    f1.l_tail->m__0succ=this->m__0head;
    this->m__0head->m__0pred=f1.l_tail;
    if((l_merges<=1)){
      return;
    }
    l_insize*=2;
  }
}

void t_std_collections_List_1Tt_mx2_VarValue_2::m_Sort(bbBool l_ascending){
  if(l_ascending){
    struct lambda12 : public bbFunction<bbInt(t_mx2_VarValue*,t_mx2_VarValue*)>::Rep{
      t_std_collections_List_1Tt_mx2_VarValue_2* l_self;
      lambda12(t_std_collections_List_1Tt_mx2_VarValue_2* l_self):l_self(l_self){
      }
      bbInt invoke(t_mx2_VarValue* l_x,t_mx2_VarValue* l_y){
        return bbCompare(l_x,l_y);
      }
      void gcMark(){
        bbGCMarkPtr(l_self);
      }
    };
    this->m_Sort(bbFunction<bbInt(t_mx2_VarValue*,t_mx2_VarValue*)>(new lambda12(this)));
  }else{
    struct lambda13 : public bbFunction<bbInt(t_mx2_VarValue*,t_mx2_VarValue*)>::Rep{
      t_std_collections_List_1Tt_mx2_VarValue_2* l_self;
      lambda13(t_std_collections_List_1Tt_mx2_VarValue_2* l_self):l_self(l_self){
      }
      bbInt invoke(t_mx2_VarValue* l_x,t_mx2_VarValue* l_y){
        return -bbCompare(l_x,l_y);
      }
      void gcMark(){
        bbGCMarkPtr(l_self);
      }
    };
    this->m_Sort(bbFunction<bbInt(t_mx2_VarValue*,t_mx2_VarValue*)>(new lambda13(this)));
  }
}

t_mx2_VarValue* t_std_collections_List_1Tt_mx2_VarValue_2::m_RemoveLast(){
  struct f0_t : public bbGCFrame{
    t_mx2_VarValue* l_value{};
    void gcMark(){
      bbGCMarkPtr(l_value);
    }
  }f0{};
  bbDebugAssert(!this->m_Empty(),BB_T("Debug assert failed"));
  f0.l_value=this->m__0head->m__0pred->m__0value;
  this->m__0head->m__0pred->m_Remove();
  this->m__0seq+=1;
  return f0.l_value;
}

bbBool t_std_collections_List_1Tt_mx2_VarValue_2::m_RemoveLast(t_mx2_VarValue* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_mx2_VarValue_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m_FindLastNode(l_value);
  if(!bbBool(f0.l_node)){
    return false;
  }
  f0.l_node->m_Remove();
  this->m__0seq+=1;
  return true;
}

t_mx2_VarValue* t_std_collections_List_1Tt_mx2_VarValue_2::m_RemoveFirst(){
  struct f0_t : public bbGCFrame{
    t_mx2_VarValue* l_value{};
    void gcMark(){
      bbGCMarkPtr(l_value);
    }
  }f0{};
  bbDebugAssert(!this->m_Empty(),BB_T("Debug assert failed"));
  f0.l_value=this->m__0head->m__0succ->m__0value;
  this->m__0head->m__0succ->m_Remove();
  this->m__0seq+=1;
  return f0.l_value;
}

bbInt t_std_collections_List_1Tt_mx2_VarValue_2::m_RemoveEach(t_mx2_VarValue* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_mx2_VarValue_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m__0head->m__0succ;
  bbInt l_n=bbInt(0);
  while((f0.l_node!=this->m__0head)){
    if((f0.l_node->m__0value==l_value)){
      f0.l_node=f0.l_node->m__0succ;
      f0.l_node->m__0pred->m_Remove();
      l_n+=1;
    }else{
      f0.l_node=f0.l_node->m__0succ;
    }
  }
  if(bbBool(l_n)){
    this->m__0seq+=1;
  }
  return l_n;
}

bbBool t_std_collections_List_1Tt_mx2_VarValue_2::m_Remove(t_mx2_VarValue* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_mx2_VarValue_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m_FindNode(l_value);
  if(!bbBool(f0.l_node)){
    return false;
  }
  f0.l_node->m_Remove();
  this->m__0seq+=1;
  return true;
}

t_std_collections_List_1Tt_mx2_VarValue_2_Node* t_std_collections_List_1Tt_mx2_VarValue_2::m_LastNode(){
  if(!this->m_Empty()){
    return this->m__0head->m__0pred;
  }
  return ((t_std_collections_List_1Tt_mx2_VarValue_2_Node*)0);
}

t_mx2_VarValue* t_std_collections_List_1Tt_mx2_VarValue_2::m_Last(){
  bbDebugAssert(!this->m_Empty(),BB_T("Debug assert failed"));
  return this->m__0head->m__0pred->m__0value;
}

t_std_collections_List_1Tt_mx2_VarValue_2_Node* t_std_collections_List_1Tt_mx2_VarValue_2::m_HeadNode(){
  return this->m__0head;
}

t_std_collections_List_1Tt_mx2_VarValue_2_Node* t_std_collections_List_1Tt_mx2_VarValue_2::m_FirstNode(){
  if(!this->m_Empty()){
    return this->m__0head->m__0succ;
  }
  return ((t_std_collections_List_1Tt_mx2_VarValue_2_Node*)0);
}

t_mx2_VarValue* t_std_collections_List_1Tt_mx2_VarValue_2::m_First(){
  bbDebugAssert(!this->m_Empty(),BB_T("Debug assert failed"));
  return this->m__0head->m__0succ->m__0value;
}

t_std_collections_List_1Tt_mx2_VarValue_2_Node* t_std_collections_List_1Tt_mx2_VarValue_2::m_FindNode(t_mx2_VarValue* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_mx2_VarValue_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m__0head->m__0succ;
  while((f0.l_node!=this->m__0head)){
    if((f0.l_node->m__0value==l_value)){
      return f0.l_node;
    }
    f0.l_node=f0.l_node->m__0succ;
  }
  return ((t_std_collections_List_1Tt_mx2_VarValue_2_Node*)0);
}

t_std_collections_List_1Tt_mx2_VarValue_2_Node* t_std_collections_List_1Tt_mx2_VarValue_2::m_FindLastNode(t_mx2_VarValue* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_mx2_VarValue_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m__0head->m__0pred;
  while((f0.l_node!=this->m__0head)){
    if((f0.l_node->m__0value==l_value)){
      return f0.l_node;
    }
    f0.l_node=f0.l_node->m__0pred;
  }
  return ((t_std_collections_List_1Tt_mx2_VarValue_2_Node*)0);
}

bbBool t_std_collections_List_1Tt_mx2_VarValue_2::m_Empty(){
  return (this->m__0head->m__0succ==this->m__0head);
}

bbInt t_std_collections_List_1Tt_mx2_VarValue_2::m_Count(){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_mx2_VarValue_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m__0head->m__0succ;
  bbInt l_n=bbInt(0);
  while((f0.l_node!=this->m__0head)){
    f0.l_node=f0.l_node->m__0succ;
    l_n+=1;
  }
  return l_n;
}

void t_std_collections_List_1Tt_mx2_VarValue_2::m_Clear(){
  this->m__0head->m__0succ=this->m__0head;
  this->m__0head->m__0pred=this->m__0head;
  this->m__0seq+=1;
}

t_std_collections_List_1Tt_mx2_VarValue_2_BackwardsIterator t_std_collections_List_1Tt_mx2_VarValue_2::m_Backwards(){
  return t_std_collections_List_1Tt_mx2_VarValue_2_BackwardsIterator(this,this->m__0head->m__0pred);
}

t_std_collections_List_1Tt_mx2_VarValue_2_Iterator t_std_collections_List_1Tt_mx2_VarValue_2::m_All(){
  return t_std_collections_List_1Tt_mx2_VarValue_2_Iterator(this,this->m__0head->m__0succ);
}

t_std_collections_List_1Tt_mx2_VarValue_2_Node* t_std_collections_List_1Tt_mx2_VarValue_2::m_AddLast(t_mx2_VarValue* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_mx2_VarValue_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=bbGCNew<t_std_collections_List_1Tt_mx2_VarValue_2_Node>(l_value,this->m__0head);
  this->m__0seq+=1;
  return f0.l_node;
}

t_std_collections_List_1Tt_mx2_VarValue_2_Node* t_std_collections_List_1Tt_mx2_VarValue_2::m_AddFirst(t_mx2_VarValue* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_mx2_VarValue_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=bbGCNew<t_std_collections_List_1Tt_mx2_VarValue_2_Node>(l_value,this->m__0head->m__0succ);
  this->m__0seq+=1;
  return f0.l_node;
}

void t_std_collections_List_1Tt_mx2_VarValue_2::m_AddAll(bbArray<bbGCVar<t_mx2_VarValue>>* l_values){
  {
    bbInt l_0=bbInt(0);
    bbInt l_1=l_values->length();
    for(;(l_0<l_1);l_0+=1){
      struct f2_t : public bbGCFrame{
        t_mx2_VarValue* l_value{};
        void gcMark(){
          bbGCMarkPtr(l_value);
        }
      }f2{};
      f2.l_value=l_values->at(l_0);
      this->m_AddLast(f2.l_value);
    }
  }
}

void t_std_collections_List_1Tt_mx2_VarValue_2::m_Add(t_mx2_VarValue* l_value){
  this->m_AddLast(l_value);
}

void t_std_collections_List_1Tt_std_collections_Stack_1s_2_Node::gcMark(){
  bbGCMark(m__0succ);
  bbGCMark(m__0pred);
  bbGCMark(m__0value);
}

t_std_collections_List_1Tt_std_collections_Stack_1s_2_Node::t_std_collections_List_1Tt_std_collections_Stack_1s_2_Node(t_std_collections_Stack_1s* l_value,t_std_collections_List_1Tt_std_collections_Stack_1s_2_Node* l_succ){
  this->m__0value=l_value;
  this->m__0succ=l_succ;
  this->m__0pred=l_succ->m__0pred;
  this->m__0pred->m__0succ=this;
  l_succ->m__0pred=this;
}

t_std_collections_List_1Tt_std_collections_Stack_1s_2_Node::t_std_collections_List_1Tt_std_collections_Stack_1s_2_Node(t_std_collections_Stack_1s* l_value){
  this->m__0value=l_value;
  this->m__0succ=this;
  this->m__0pred=this;
}

void t_std_collections_List_1Tt_std_collections_Stack_1s_2_Node::m_Value(t_std_collections_Stack_1s* l_value){
  this->m__0value=l_value;
}

t_std_collections_Stack_1s* t_std_collections_List_1Tt_std_collections_Stack_1s_2_Node::m_Value(){
  return this->m__0value;
}

t_std_collections_List_1Tt_std_collections_Stack_1s_2_Node* t_std_collections_List_1Tt_std_collections_Stack_1s_2_Node::m_Succ(){
  return this->m__0succ;
}

void t_std_collections_List_1Tt_std_collections_Stack_1s_2_Node::m_Remove(){
  this->m__0succ->m__0pred=this->m__0pred;
  this->m__0pred->m__0succ=this->m__0succ;
}

t_std_collections_List_1Tt_std_collections_Stack_1s_2_Node* t_std_collections_List_1Tt_std_collections_Stack_1s_2_Node::m_Pred(){
  return this->m__0pred;
}

void t_std_collections_List_1Tt_std_collections_Stack_1s_2_Node::m_InsertBefore(t_std_collections_List_1Tt_std_collections_Stack_1s_2_Node* l_node){
  this->m__0succ=l_node;
  this->m__0pred=l_node->m__0pred;
  this->m__0pred->m__0succ=this;
  l_node->m__0pred=this;
}

void t_std_collections_List_1Tt_std_collections_Stack_1s_2_Node::m_InsertAfter(t_std_collections_List_1Tt_std_collections_Stack_1s_2_Node* l_node){
  this->m__0pred=l_node;
  this->m__0succ=l_node->m__0succ;
  this->m__0succ->m__0pred=this;
  l_node->m__0succ=this;
}

t_std_collections_List_1Tt_std_collections_Stack_1s_2_Iterator::t_std_collections_List_1Tt_std_collections_Stack_1s_2_Iterator(t_std_collections_List_1Tt_std_collections_Stack_1s_2* l_list,t_std_collections_List_1Tt_std_collections_Stack_1s_2_Node* l_node){
  (*this).m__0list=l_list;
  (*this).m__0node=l_node;
  (*this).m__0seq=l_list->m__0seq;
}

void t_std_collections_List_1Tt_std_collections_Stack_1s_2_Iterator::m_Insert(t_std_collections_Stack_1s* l_value){
  (*this).m_AssertSeq();
  (*this).m__0node=bbGCNew<t_std_collections_List_1Tt_std_collections_Stack_1s_2_Node>(l_value,(*this).m__0node);
  (*this).m__0list->m__0seq+=1;
  (*this).m__0seq=(*this).m__0list->m__0seq;
}

void t_std_collections_List_1Tt_std_collections_Stack_1s_2_Iterator::m_Erase(){
  (*this).m_AssertCurrent();
  (*this).m__0node=(*this).m__0node->m__0succ;
  (*this).m__0node->m__0pred->m_Remove();
  (*this).m__0list->m__0seq+=1;
  (*this).m__0seq=(*this).m__0list->m__0seq;
}

void t_std_collections_List_1Tt_std_collections_Stack_1s_2_Iterator::m_Current(t_std_collections_Stack_1s* l_current){
  (*this).m_AssertCurrent();
  (*this).m__0node->m__0value=l_current;
}

t_std_collections_Stack_1s* t_std_collections_List_1Tt_std_collections_Stack_1s_2_Iterator::m_Current(){
  (*this).m_AssertCurrent();
  return (*this).m__0node->m__0value;
}

void t_std_collections_List_1Tt_std_collections_Stack_1s_2_Iterator::m_Bump(){
  (*this).m_AssertCurrent();
  (*this).m__0node=(*this).m__0node->m__0succ;
}

bbBool t_std_collections_List_1Tt_std_collections_Stack_1s_2_Iterator::m_AtEnd(){
  (*this).m_AssertSeq();
  return ((*this).m__0node==(*this).m__0list->m__0head);
}

void t_std_collections_List_1Tt_std_collections_Stack_1s_2_Iterator::m_AssertSeq(){
  bbDebugAssert(((*this).m__0seq==(*this).m__0list->m__0seq),BB_T("Concurrent list modification"));
}

void t_std_collections_List_1Tt_std_collections_Stack_1s_2_Iterator::m_AssertCurrent(){
  bbDebugAssert(!(*this).m_AtEnd(),BB_T("Invalid list iterator"));
}

int bbCompare(const t_std_collections_List_1Tt_std_collections_Stack_1s_2_Iterator&x,const t_std_collections_List_1Tt_std_collections_Stack_1s_2_Iterator&y){
  if(int t=bbCompare(x.m__0list,y.m__0list)) return t;
  if(int t=bbCompare(x.m__0node,y.m__0node)) return t;
  if(int t=bbCompare(x.m__0seq,y.m__0seq)) return t;
  return 0;
}

void bbGCMark(const t_std_collections_List_1Tt_std_collections_Stack_1s_2_Iterator&t){
  bbGCMark(t.m__0list);
  bbGCMark(t.m__0node);
}

t_std_collections_List_1Tt_std_collections_Stack_1s_2_BackwardsIterator::t_std_collections_List_1Tt_std_collections_Stack_1s_2_BackwardsIterator(t_std_collections_List_1Tt_std_collections_Stack_1s_2* l_list,t_std_collections_List_1Tt_std_collections_Stack_1s_2_Node* l_node){
  (*this).m__0list=l_list;
  (*this).m__0node=l_node;
  (*this).m__0seq=l_list->m__0seq;
}

void t_std_collections_List_1Tt_std_collections_Stack_1s_2_BackwardsIterator::m_Insert(t_std_collections_Stack_1s* l_value){
  (*this).m_AssertSeq();
  (*this).m__0node=bbGCNew<t_std_collections_List_1Tt_std_collections_Stack_1s_2_Node>(l_value,(*this).m__0node->m__0succ);
  (*this).m__0list->m__0seq+=1;
  (*this).m__0seq=(*this).m__0list->m__0seq;
}

void t_std_collections_List_1Tt_std_collections_Stack_1s_2_BackwardsIterator::m_Erase(){
  (*this).m_AssertCurrent();
  (*this).m__0node=(*this).m__0node->m__0pred;
  (*this).m__0node->m__0succ->m_Remove();
  (*this).m__0list->m__0seq+=1;
  (*this).m__0seq=(*this).m__0list->m__0seq;
}

void t_std_collections_List_1Tt_std_collections_Stack_1s_2_BackwardsIterator::m_Current(t_std_collections_Stack_1s* l_current){
  (*this).m_AssertCurrent();
  (*this).m__0node->m__0value=l_current;
}

t_std_collections_Stack_1s* t_std_collections_List_1Tt_std_collections_Stack_1s_2_BackwardsIterator::m_Current(){
  (*this).m_AssertCurrent();
  return (*this).m__0node->m__0value;
}

void t_std_collections_List_1Tt_std_collections_Stack_1s_2_BackwardsIterator::m_Bump(){
  (*this).m_AssertCurrent();
  (*this).m__0node=(*this).m__0node->m__0pred;
}

bbBool t_std_collections_List_1Tt_std_collections_Stack_1s_2_BackwardsIterator::m_AtEnd(){
  (*this).m_AssertSeq();
  return ((*this).m__0node==(*this).m__0list->m__0head);
}

void t_std_collections_List_1Tt_std_collections_Stack_1s_2_BackwardsIterator::m_AssertSeq(){
  bbDebugAssert(((*this).m__0seq==(*this).m__0list->m__0seq),BB_T("Concurrent list modification"));
}

void t_std_collections_List_1Tt_std_collections_Stack_1s_2_BackwardsIterator::m_AssertCurrent(){
  bbDebugAssert(!(*this).m_AtEnd(),BB_T("Invalid list iterator"));
}

int bbCompare(const t_std_collections_List_1Tt_std_collections_Stack_1s_2_BackwardsIterator&x,const t_std_collections_List_1Tt_std_collections_Stack_1s_2_BackwardsIterator&y){
  if(int t=bbCompare(x.m__0list,y.m__0list)) return t;
  if(int t=bbCompare(x.m__0node,y.m__0node)) return t;
  if(int t=bbCompare(x.m__0seq,y.m__0seq)) return t;
  return 0;
}

void bbGCMark(const t_std_collections_List_1Tt_std_collections_Stack_1s_2_BackwardsIterator&t){
  bbGCMark(t.m__0list);
  bbGCMark(t.m__0node);
}

void t_std_collections_List_1Tt_std_collections_Stack_1s_2::gcMark(){
  bbGCMark(m__0head);
}

t_std_collections_List_1Tt_std_collections_Stack_1s_2::t_std_collections_List_1Tt_std_collections_Stack_1s_2(t_std_collections_List_1Tt_std_collections_Stack_1s_2* l_values):t_std_collections_List_1Tt_std_collections_Stack_1s_2(){
  g_std_collections_List_1Tt_std_collections_Stack_1s_2_AddAll_1Tt_std_collections_List_1Tt_std_collections_Stack_1s_2_2(this,l_values);
}

t_std_collections_List_1Tt_std_collections_Stack_1s_2::t_std_collections_List_1Tt_std_collections_Stack_1s_2(t_std_collections_Stack_1Tt_std_collections_Stack_1s_2* l_values):t_std_collections_List_1Tt_std_collections_Stack_1s_2(){
  g_std_collections_List_1Tt_std_collections_Stack_1s_2_AddAll_1Tt_std_collections_Stack_1Tt_std_collections_Stack_1s_2_2(this,l_values);
}

t_std_collections_List_1Tt_std_collections_Stack_1s_2::t_std_collections_List_1Tt_std_collections_Stack_1s_2(bbArray<bbGCVar<t_std_collections_Stack_1s>>* l_values):t_std_collections_List_1Tt_std_collections_Stack_1s_2(){
  this->m_AddAll(l_values);
}

t_std_collections_List_1Tt_std_collections_Stack_1s_2::t_std_collections_List_1Tt_std_collections_Stack_1s_2(){
  this->m__0head=bbGCNew<t_std_collections_List_1Tt_std_collections_Stack_1s_2_Node>(((t_std_collections_Stack_1s*)0));
}

bbArray<bbGCVar<t_std_collections_Stack_1s>>* t_std_collections_List_1Tt_std_collections_Stack_1s_2::m_ToArray(){
  struct f0_t : public bbGCFrame{
    bbArray<bbGCVar<t_std_collections_Stack_1s>>* l_data{};
    t_std_collections_List_1Tt_std_collections_Stack_1s_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_data);
      bbGCMarkPtr(l_node);
    }
  }f0{};
  bbInt l_n=this->m_Count();
  f0.l_data=bbArray<bbGCVar<t_std_collections_Stack_1s>>::create(l_n);
  f0.l_node=this->m__0head->m__0succ;
  {
    bbInt l_i=bbInt(0);
    for(;(l_i<l_n);l_i+=1){
      f0.l_data->at(l_i)=f0.l_node->m__0value;
      f0.l_node=f0.l_node->m__0succ;
    }
  }
  return f0.l_data;
}

void t_std_collections_List_1Tt_std_collections_Stack_1s_2::m_Sort(bbFunction<bbInt(t_std_collections_Stack_1s*,t_std_collections_Stack_1s*)> l_compareFunc){
  bbInt l_insize=1;
  for(;;){
    struct f1_t : public bbGCFrame{
      t_std_collections_List_1Tt_std_collections_Stack_1s_2_Node* l_p{};
      t_std_collections_List_1Tt_std_collections_Stack_1s_2_Node* l_tail{};
      void gcMark(){
        bbGCMarkPtr(l_p);
        bbGCMarkPtr(l_tail);
      }
    }f1{};
    bbInt l_merges=bbInt(0);
    f1.l_tail=this->m__0head;
    f1.l_p=this->m__0head->m__0succ;
    while((f1.l_p!=this->m__0head)){
      struct f2_t : public bbGCFrame{
        t_std_collections_List_1Tt_std_collections_Stack_1s_2_Node* l_q{};
        void gcMark(){
          bbGCMarkPtr(l_q);
        }
      }f2{};
      l_merges+=1;
      f2.l_q=f1.l_p->m__0succ;
      bbInt l_qsize=l_insize;
      bbInt l_psize=1;
      while(((l_psize<l_insize)&&(f2.l_q!=this->m__0head))){
        l_psize+=1;
        f2.l_q=f2.l_q->m__0succ;
      }
      for(;;){
        struct f3_t : public bbGCFrame{
          t_std_collections_List_1Tt_std_collections_Stack_1s_2_Node* l_t{};
          void gcMark(){
            bbGCMarkPtr(l_t);
          }
        }f3{};
        if(((bbBool(l_psize)&&bbBool(l_qsize))&&(f2.l_q!=this->m__0head))){
          bbInt l_cc=l_compareFunc(f1.l_p->m__0value,f2.l_q->m__0value);
          if((l_cc<=bbInt(0))){
            f3.l_t=f1.l_p;
            f1.l_p=f1.l_p->m__0succ;
            l_psize-=1;
          }else{
            f3.l_t=f2.l_q;
            f2.l_q=f2.l_q->m__0succ;
            l_qsize-=1;
          }
        }else if(bbBool(l_psize)){
          f3.l_t=f1.l_p;
          f1.l_p=f1.l_p->m__0succ;
          l_psize-=1;
        }else if((bbBool(l_qsize)&&(f2.l_q!=this->m__0head))){
          f3.l_t=f2.l_q;
          f2.l_q=f2.l_q->m__0succ;
          l_qsize-=1;
        }else{
          break;
        }
        f3.l_t->m__0pred=f1.l_tail;
        f1.l_tail->m__0succ=f3.l_t;
        f1.l_tail=f3.l_t;
      }
      f1.l_p=f2.l_q;
    }
    f1.l_tail->m__0succ=this->m__0head;
    this->m__0head->m__0pred=f1.l_tail;
    if((l_merges<=1)){
      return;
    }
    l_insize*=2;
  }
}

void t_std_collections_List_1Tt_std_collections_Stack_1s_2::m_Sort(bbBool l_ascending){
  if(l_ascending){
    struct lambda14 : public bbFunction<bbInt(t_std_collections_Stack_1s*,t_std_collections_Stack_1s*)>::Rep{
      t_std_collections_List_1Tt_std_collections_Stack_1s_2* l_self;
      lambda14(t_std_collections_List_1Tt_std_collections_Stack_1s_2* l_self):l_self(l_self){
      }
      bbInt invoke(t_std_collections_Stack_1s* l_x,t_std_collections_Stack_1s* l_y){
        return bbCompare(l_x,l_y);
      }
      void gcMark(){
        bbGCMarkPtr(l_self);
      }
    };
    this->m_Sort(bbFunction<bbInt(t_std_collections_Stack_1s*,t_std_collections_Stack_1s*)>(new lambda14(this)));
  }else{
    struct lambda15 : public bbFunction<bbInt(t_std_collections_Stack_1s*,t_std_collections_Stack_1s*)>::Rep{
      t_std_collections_List_1Tt_std_collections_Stack_1s_2* l_self;
      lambda15(t_std_collections_List_1Tt_std_collections_Stack_1s_2* l_self):l_self(l_self){
      }
      bbInt invoke(t_std_collections_Stack_1s* l_x,t_std_collections_Stack_1s* l_y){
        return -bbCompare(l_x,l_y);
      }
      void gcMark(){
        bbGCMarkPtr(l_self);
      }
    };
    this->m_Sort(bbFunction<bbInt(t_std_collections_Stack_1s*,t_std_collections_Stack_1s*)>(new lambda15(this)));
  }
}

t_std_collections_Stack_1s* t_std_collections_List_1Tt_std_collections_Stack_1s_2::m_RemoveLast(){
  struct f0_t : public bbGCFrame{
    t_std_collections_Stack_1s* l_value{};
    void gcMark(){
      bbGCMarkPtr(l_value);
    }
  }f0{};
  bbDebugAssert(!this->m_Empty(),BB_T("Debug assert failed"));
  f0.l_value=this->m__0head->m__0pred->m__0value;
  this->m__0head->m__0pred->m_Remove();
  this->m__0seq+=1;
  return f0.l_value;
}

bbBool t_std_collections_List_1Tt_std_collections_Stack_1s_2::m_RemoveLast(t_std_collections_Stack_1s* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_std_collections_Stack_1s_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m_FindLastNode(l_value);
  if(!bbBool(f0.l_node)){
    return false;
  }
  f0.l_node->m_Remove();
  this->m__0seq+=1;
  return true;
}

t_std_collections_Stack_1s* t_std_collections_List_1Tt_std_collections_Stack_1s_2::m_RemoveFirst(){
  struct f0_t : public bbGCFrame{
    t_std_collections_Stack_1s* l_value{};
    void gcMark(){
      bbGCMarkPtr(l_value);
    }
  }f0{};
  bbDebugAssert(!this->m_Empty(),BB_T("Debug assert failed"));
  f0.l_value=this->m__0head->m__0succ->m__0value;
  this->m__0head->m__0succ->m_Remove();
  this->m__0seq+=1;
  return f0.l_value;
}

bbInt t_std_collections_List_1Tt_std_collections_Stack_1s_2::m_RemoveEach(t_std_collections_Stack_1s* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_std_collections_Stack_1s_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m__0head->m__0succ;
  bbInt l_n=bbInt(0);
  while((f0.l_node!=this->m__0head)){
    if((f0.l_node->m__0value==l_value)){
      f0.l_node=f0.l_node->m__0succ;
      f0.l_node->m__0pred->m_Remove();
      l_n+=1;
    }else{
      f0.l_node=f0.l_node->m__0succ;
    }
  }
  if(bbBool(l_n)){
    this->m__0seq+=1;
  }
  return l_n;
}

bbBool t_std_collections_List_1Tt_std_collections_Stack_1s_2::m_Remove(t_std_collections_Stack_1s* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_std_collections_Stack_1s_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m_FindNode(l_value);
  if(!bbBool(f0.l_node)){
    return false;
  }
  f0.l_node->m_Remove();
  this->m__0seq+=1;
  return true;
}

t_std_collections_List_1Tt_std_collections_Stack_1s_2_Node* t_std_collections_List_1Tt_std_collections_Stack_1s_2::m_LastNode(){
  if(!this->m_Empty()){
    return this->m__0head->m__0pred;
  }
  return ((t_std_collections_List_1Tt_std_collections_Stack_1s_2_Node*)0);
}

t_std_collections_Stack_1s* t_std_collections_List_1Tt_std_collections_Stack_1s_2::m_Last(){
  bbDebugAssert(!this->m_Empty(),BB_T("Debug assert failed"));
  return this->m__0head->m__0pred->m__0value;
}

t_std_collections_List_1Tt_std_collections_Stack_1s_2_Node* t_std_collections_List_1Tt_std_collections_Stack_1s_2::m_HeadNode(){
  return this->m__0head;
}

t_std_collections_List_1Tt_std_collections_Stack_1s_2_Node* t_std_collections_List_1Tt_std_collections_Stack_1s_2::m_FirstNode(){
  if(!this->m_Empty()){
    return this->m__0head->m__0succ;
  }
  return ((t_std_collections_List_1Tt_std_collections_Stack_1s_2_Node*)0);
}

t_std_collections_Stack_1s* t_std_collections_List_1Tt_std_collections_Stack_1s_2::m_First(){
  bbDebugAssert(!this->m_Empty(),BB_T("Debug assert failed"));
  return this->m__0head->m__0succ->m__0value;
}

t_std_collections_List_1Tt_std_collections_Stack_1s_2_Node* t_std_collections_List_1Tt_std_collections_Stack_1s_2::m_FindNode(t_std_collections_Stack_1s* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_std_collections_Stack_1s_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m__0head->m__0succ;
  while((f0.l_node!=this->m__0head)){
    if((f0.l_node->m__0value==l_value)){
      return f0.l_node;
    }
    f0.l_node=f0.l_node->m__0succ;
  }
  return ((t_std_collections_List_1Tt_std_collections_Stack_1s_2_Node*)0);
}

t_std_collections_List_1Tt_std_collections_Stack_1s_2_Node* t_std_collections_List_1Tt_std_collections_Stack_1s_2::m_FindLastNode(t_std_collections_Stack_1s* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_std_collections_Stack_1s_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m__0head->m__0pred;
  while((f0.l_node!=this->m__0head)){
    if((f0.l_node->m__0value==l_value)){
      return f0.l_node;
    }
    f0.l_node=f0.l_node->m__0pred;
  }
  return ((t_std_collections_List_1Tt_std_collections_Stack_1s_2_Node*)0);
}

bbBool t_std_collections_List_1Tt_std_collections_Stack_1s_2::m_Empty(){
  return (this->m__0head->m__0succ==this->m__0head);
}

bbInt t_std_collections_List_1Tt_std_collections_Stack_1s_2::m_Count(){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_std_collections_Stack_1s_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m__0head->m__0succ;
  bbInt l_n=bbInt(0);
  while((f0.l_node!=this->m__0head)){
    f0.l_node=f0.l_node->m__0succ;
    l_n+=1;
  }
  return l_n;
}

void t_std_collections_List_1Tt_std_collections_Stack_1s_2::m_Clear(){
  this->m__0head->m__0succ=this->m__0head;
  this->m__0head->m__0pred=this->m__0head;
  this->m__0seq+=1;
}

t_std_collections_List_1Tt_std_collections_Stack_1s_2_BackwardsIterator t_std_collections_List_1Tt_std_collections_Stack_1s_2::m_Backwards(){
  return t_std_collections_List_1Tt_std_collections_Stack_1s_2_BackwardsIterator(this,this->m__0head->m__0pred);
}

t_std_collections_List_1Tt_std_collections_Stack_1s_2_Iterator t_std_collections_List_1Tt_std_collections_Stack_1s_2::m_All(){
  return t_std_collections_List_1Tt_std_collections_Stack_1s_2_Iterator(this,this->m__0head->m__0succ);
}

t_std_collections_List_1Tt_std_collections_Stack_1s_2_Node* t_std_collections_List_1Tt_std_collections_Stack_1s_2::m_AddLast(t_std_collections_Stack_1s* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_std_collections_Stack_1s_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=bbGCNew<t_std_collections_List_1Tt_std_collections_Stack_1s_2_Node>(l_value,this->m__0head);
  this->m__0seq+=1;
  return f0.l_node;
}

t_std_collections_List_1Tt_std_collections_Stack_1s_2_Node* t_std_collections_List_1Tt_std_collections_Stack_1s_2::m_AddFirst(t_std_collections_Stack_1s* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_std_collections_Stack_1s_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=bbGCNew<t_std_collections_List_1Tt_std_collections_Stack_1s_2_Node>(l_value,this->m__0head->m__0succ);
  this->m__0seq+=1;
  return f0.l_node;
}

void t_std_collections_List_1Tt_std_collections_Stack_1s_2::m_AddAll(bbArray<bbGCVar<t_std_collections_Stack_1s>>* l_values){
  {
    bbInt l_0=bbInt(0);
    bbInt l_1=l_values->length();
    for(;(l_0<l_1);l_0+=1){
      struct f2_t : public bbGCFrame{
        t_std_collections_Stack_1s* l_value{};
        void gcMark(){
          bbGCMarkPtr(l_value);
        }
      }f2{};
      f2.l_value=l_values->at(l_0);
      this->m_AddLast(f2.l_value);
    }
  }
}

void t_std_collections_List_1Tt_std_collections_Stack_1s_2::m_Add(t_std_collections_Stack_1s* l_value){
  this->m_AddLast(l_value);
}

void t_std_collections_List_1Tt_mx2_FileDecl_2_Node::gcMark(){
  bbGCMark(m__0succ);
  bbGCMark(m__0pred);
  bbGCMark(m__0value);
}

t_std_collections_List_1Tt_mx2_FileDecl_2_Node::t_std_collections_List_1Tt_mx2_FileDecl_2_Node(t_mx2_FileDecl* l_value,t_std_collections_List_1Tt_mx2_FileDecl_2_Node* l_succ){
  this->m__0value=l_value;
  this->m__0succ=l_succ;
  this->m__0pred=l_succ->m__0pred;
  this->m__0pred->m__0succ=this;
  l_succ->m__0pred=this;
}

t_std_collections_List_1Tt_mx2_FileDecl_2_Node::t_std_collections_List_1Tt_mx2_FileDecl_2_Node(t_mx2_FileDecl* l_value){
  this->m__0value=l_value;
  this->m__0succ=this;
  this->m__0pred=this;
}

void t_std_collections_List_1Tt_mx2_FileDecl_2_Node::m_Value(t_mx2_FileDecl* l_value){
  this->m__0value=l_value;
}

t_mx2_FileDecl* t_std_collections_List_1Tt_mx2_FileDecl_2_Node::m_Value(){
  return this->m__0value;
}

t_std_collections_List_1Tt_mx2_FileDecl_2_Node* t_std_collections_List_1Tt_mx2_FileDecl_2_Node::m_Succ(){
  return this->m__0succ;
}

void t_std_collections_List_1Tt_mx2_FileDecl_2_Node::m_Remove(){
  this->m__0succ->m__0pred=this->m__0pred;
  this->m__0pred->m__0succ=this->m__0succ;
}

t_std_collections_List_1Tt_mx2_FileDecl_2_Node* t_std_collections_List_1Tt_mx2_FileDecl_2_Node::m_Pred(){
  return this->m__0pred;
}

void t_std_collections_List_1Tt_mx2_FileDecl_2_Node::m_InsertBefore(t_std_collections_List_1Tt_mx2_FileDecl_2_Node* l_node){
  this->m__0succ=l_node;
  this->m__0pred=l_node->m__0pred;
  this->m__0pred->m__0succ=this;
  l_node->m__0pred=this;
}

void t_std_collections_List_1Tt_mx2_FileDecl_2_Node::m_InsertAfter(t_std_collections_List_1Tt_mx2_FileDecl_2_Node* l_node){
  this->m__0pred=l_node;
  this->m__0succ=l_node->m__0succ;
  this->m__0succ->m__0pred=this;
  l_node->m__0succ=this;
}

t_std_collections_List_1Tt_mx2_FileDecl_2_Iterator::t_std_collections_List_1Tt_mx2_FileDecl_2_Iterator(t_std_collections_List_1Tt_mx2_FileDecl_2* l_list,t_std_collections_List_1Tt_mx2_FileDecl_2_Node* l_node){
  (*this).m__0list=l_list;
  (*this).m__0node=l_node;
  (*this).m__0seq=l_list->m__0seq;
}

void t_std_collections_List_1Tt_mx2_FileDecl_2_Iterator::m_Insert(t_mx2_FileDecl* l_value){
  (*this).m_AssertSeq();
  (*this).m__0node=bbGCNew<t_std_collections_List_1Tt_mx2_FileDecl_2_Node>(l_value,(*this).m__0node);
  (*this).m__0list->m__0seq+=1;
  (*this).m__0seq=(*this).m__0list->m__0seq;
}

void t_std_collections_List_1Tt_mx2_FileDecl_2_Iterator::m_Erase(){
  (*this).m_AssertCurrent();
  (*this).m__0node=(*this).m__0node->m__0succ;
  (*this).m__0node->m__0pred->m_Remove();
  (*this).m__0list->m__0seq+=1;
  (*this).m__0seq=(*this).m__0list->m__0seq;
}

void t_std_collections_List_1Tt_mx2_FileDecl_2_Iterator::m_Current(t_mx2_FileDecl* l_current){
  (*this).m_AssertCurrent();
  (*this).m__0node->m__0value=l_current;
}

t_mx2_FileDecl* t_std_collections_List_1Tt_mx2_FileDecl_2_Iterator::m_Current(){
  (*this).m_AssertCurrent();
  return (*this).m__0node->m__0value;
}

void t_std_collections_List_1Tt_mx2_FileDecl_2_Iterator::m_Bump(){
  (*this).m_AssertCurrent();
  (*this).m__0node=(*this).m__0node->m__0succ;
}

bbBool t_std_collections_List_1Tt_mx2_FileDecl_2_Iterator::m_AtEnd(){
  (*this).m_AssertSeq();
  return ((*this).m__0node==(*this).m__0list->m__0head);
}

void t_std_collections_List_1Tt_mx2_FileDecl_2_Iterator::m_AssertSeq(){
  bbDebugAssert(((*this).m__0seq==(*this).m__0list->m__0seq),BB_T("Concurrent list modification"));
}

void t_std_collections_List_1Tt_mx2_FileDecl_2_Iterator::m_AssertCurrent(){
  bbDebugAssert(!(*this).m_AtEnd(),BB_T("Invalid list iterator"));
}

int bbCompare(const t_std_collections_List_1Tt_mx2_FileDecl_2_Iterator&x,const t_std_collections_List_1Tt_mx2_FileDecl_2_Iterator&y){
  if(int t=bbCompare(x.m__0list,y.m__0list)) return t;
  if(int t=bbCompare(x.m__0node,y.m__0node)) return t;
  if(int t=bbCompare(x.m__0seq,y.m__0seq)) return t;
  return 0;
}

void bbGCMark(const t_std_collections_List_1Tt_mx2_FileDecl_2_Iterator&t){
  bbGCMark(t.m__0list);
  bbGCMark(t.m__0node);
}

t_std_collections_List_1Tt_mx2_FileDecl_2_BackwardsIterator::t_std_collections_List_1Tt_mx2_FileDecl_2_BackwardsIterator(t_std_collections_List_1Tt_mx2_FileDecl_2* l_list,t_std_collections_List_1Tt_mx2_FileDecl_2_Node* l_node){
  (*this).m__0list=l_list;
  (*this).m__0node=l_node;
  (*this).m__0seq=l_list->m__0seq;
}

void t_std_collections_List_1Tt_mx2_FileDecl_2_BackwardsIterator::m_Insert(t_mx2_FileDecl* l_value){
  (*this).m_AssertSeq();
  (*this).m__0node=bbGCNew<t_std_collections_List_1Tt_mx2_FileDecl_2_Node>(l_value,(*this).m__0node->m__0succ);
  (*this).m__0list->m__0seq+=1;
  (*this).m__0seq=(*this).m__0list->m__0seq;
}

void t_std_collections_List_1Tt_mx2_FileDecl_2_BackwardsIterator::m_Erase(){
  (*this).m_AssertCurrent();
  (*this).m__0node=(*this).m__0node->m__0pred;
  (*this).m__0node->m__0succ->m_Remove();
  (*this).m__0list->m__0seq+=1;
  (*this).m__0seq=(*this).m__0list->m__0seq;
}

void t_std_collections_List_1Tt_mx2_FileDecl_2_BackwardsIterator::m_Current(t_mx2_FileDecl* l_current){
  (*this).m_AssertCurrent();
  (*this).m__0node->m__0value=l_current;
}

t_mx2_FileDecl* t_std_collections_List_1Tt_mx2_FileDecl_2_BackwardsIterator::m_Current(){
  (*this).m_AssertCurrent();
  return (*this).m__0node->m__0value;
}

void t_std_collections_List_1Tt_mx2_FileDecl_2_BackwardsIterator::m_Bump(){
  (*this).m_AssertCurrent();
  (*this).m__0node=(*this).m__0node->m__0pred;
}

bbBool t_std_collections_List_1Tt_mx2_FileDecl_2_BackwardsIterator::m_AtEnd(){
  (*this).m_AssertSeq();
  return ((*this).m__0node==(*this).m__0list->m__0head);
}

void t_std_collections_List_1Tt_mx2_FileDecl_2_BackwardsIterator::m_AssertSeq(){
  bbDebugAssert(((*this).m__0seq==(*this).m__0list->m__0seq),BB_T("Concurrent list modification"));
}

void t_std_collections_List_1Tt_mx2_FileDecl_2_BackwardsIterator::m_AssertCurrent(){
  bbDebugAssert(!(*this).m_AtEnd(),BB_T("Invalid list iterator"));
}

int bbCompare(const t_std_collections_List_1Tt_mx2_FileDecl_2_BackwardsIterator&x,const t_std_collections_List_1Tt_mx2_FileDecl_2_BackwardsIterator&y){
  if(int t=bbCompare(x.m__0list,y.m__0list)) return t;
  if(int t=bbCompare(x.m__0node,y.m__0node)) return t;
  if(int t=bbCompare(x.m__0seq,y.m__0seq)) return t;
  return 0;
}

void bbGCMark(const t_std_collections_List_1Tt_mx2_FileDecl_2_BackwardsIterator&t){
  bbGCMark(t.m__0list);
  bbGCMark(t.m__0node);
}

void t_std_collections_List_1Tt_mx2_FileDecl_2::gcMark(){
  bbGCMark(m__0head);
}

t_std_collections_List_1Tt_mx2_FileDecl_2::t_std_collections_List_1Tt_mx2_FileDecl_2(t_std_collections_List_1Tt_mx2_FileDecl_2* l_values):t_std_collections_List_1Tt_mx2_FileDecl_2(){
  g_std_collections_List_1Tt_mx2_FileDecl_2_AddAll_1Tt_std_collections_List_1Tt_mx2_FileDecl_2_2(this,l_values);
}

t_std_collections_List_1Tt_mx2_FileDecl_2::t_std_collections_List_1Tt_mx2_FileDecl_2(t_std_collections_Stack_1Tt_mx2_FileDecl_2* l_values):t_std_collections_List_1Tt_mx2_FileDecl_2(){
  g_std_collections_List_1Tt_mx2_FileDecl_2_AddAll_1Tt_std_collections_Stack_1Tt_mx2_FileDecl_2_2(this,l_values);
}

t_std_collections_List_1Tt_mx2_FileDecl_2::t_std_collections_List_1Tt_mx2_FileDecl_2(bbArray<bbGCVar<t_mx2_FileDecl>>* l_values):t_std_collections_List_1Tt_mx2_FileDecl_2(){
  this->m_AddAll(l_values);
}

t_std_collections_List_1Tt_mx2_FileDecl_2::t_std_collections_List_1Tt_mx2_FileDecl_2(){
  this->m__0head=bbGCNew<t_std_collections_List_1Tt_mx2_FileDecl_2_Node>(((t_mx2_FileDecl*)0));
}

bbArray<bbGCVar<t_mx2_FileDecl>>* t_std_collections_List_1Tt_mx2_FileDecl_2::m_ToArray(){
  struct f0_t : public bbGCFrame{
    bbArray<bbGCVar<t_mx2_FileDecl>>* l_data{};
    t_std_collections_List_1Tt_mx2_FileDecl_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_data);
      bbGCMarkPtr(l_node);
    }
  }f0{};
  bbInt l_n=this->m_Count();
  f0.l_data=bbArray<bbGCVar<t_mx2_FileDecl>>::create(l_n);
  f0.l_node=this->m__0head->m__0succ;
  {
    bbInt l_i=bbInt(0);
    for(;(l_i<l_n);l_i+=1){
      f0.l_data->at(l_i)=f0.l_node->m__0value;
      f0.l_node=f0.l_node->m__0succ;
    }
  }
  return f0.l_data;
}

void t_std_collections_List_1Tt_mx2_FileDecl_2::m_Sort(bbFunction<bbInt(t_mx2_FileDecl*,t_mx2_FileDecl*)> l_compareFunc){
  bbInt l_insize=1;
  for(;;){
    struct f1_t : public bbGCFrame{
      t_std_collections_List_1Tt_mx2_FileDecl_2_Node* l_p{};
      t_std_collections_List_1Tt_mx2_FileDecl_2_Node* l_tail{};
      void gcMark(){
        bbGCMarkPtr(l_p);
        bbGCMarkPtr(l_tail);
      }
    }f1{};
    bbInt l_merges=bbInt(0);
    f1.l_tail=this->m__0head;
    f1.l_p=this->m__0head->m__0succ;
    while((f1.l_p!=this->m__0head)){
      struct f2_t : public bbGCFrame{
        t_std_collections_List_1Tt_mx2_FileDecl_2_Node* l_q{};
        void gcMark(){
          bbGCMarkPtr(l_q);
        }
      }f2{};
      l_merges+=1;
      f2.l_q=f1.l_p->m__0succ;
      bbInt l_qsize=l_insize;
      bbInt l_psize=1;
      while(((l_psize<l_insize)&&(f2.l_q!=this->m__0head))){
        l_psize+=1;
        f2.l_q=f2.l_q->m__0succ;
      }
      for(;;){
        struct f3_t : public bbGCFrame{
          t_std_collections_List_1Tt_mx2_FileDecl_2_Node* l_t{};
          void gcMark(){
            bbGCMarkPtr(l_t);
          }
        }f3{};
        if(((bbBool(l_psize)&&bbBool(l_qsize))&&(f2.l_q!=this->m__0head))){
          bbInt l_cc=l_compareFunc(f1.l_p->m__0value,f2.l_q->m__0value);
          if((l_cc<=bbInt(0))){
            f3.l_t=f1.l_p;
            f1.l_p=f1.l_p->m__0succ;
            l_psize-=1;
          }else{
            f3.l_t=f2.l_q;
            f2.l_q=f2.l_q->m__0succ;
            l_qsize-=1;
          }
        }else if(bbBool(l_psize)){
          f3.l_t=f1.l_p;
          f1.l_p=f1.l_p->m__0succ;
          l_psize-=1;
        }else if((bbBool(l_qsize)&&(f2.l_q!=this->m__0head))){
          f3.l_t=f2.l_q;
          f2.l_q=f2.l_q->m__0succ;
          l_qsize-=1;
        }else{
          break;
        }
        f3.l_t->m__0pred=f1.l_tail;
        f1.l_tail->m__0succ=f3.l_t;
        f1.l_tail=f3.l_t;
      }
      f1.l_p=f2.l_q;
    }
    f1.l_tail->m__0succ=this->m__0head;
    this->m__0head->m__0pred=f1.l_tail;
    if((l_merges<=1)){
      return;
    }
    l_insize*=2;
  }
}

void t_std_collections_List_1Tt_mx2_FileDecl_2::m_Sort(bbBool l_ascending){
  if(l_ascending){
    struct lambda16 : public bbFunction<bbInt(t_mx2_FileDecl*,t_mx2_FileDecl*)>::Rep{
      t_std_collections_List_1Tt_mx2_FileDecl_2* l_self;
      lambda16(t_std_collections_List_1Tt_mx2_FileDecl_2* l_self):l_self(l_self){
      }
      bbInt invoke(t_mx2_FileDecl* l_x,t_mx2_FileDecl* l_y){
        return bbCompare(l_x,l_y);
      }
      void gcMark(){
        bbGCMarkPtr(l_self);
      }
    };
    this->m_Sort(bbFunction<bbInt(t_mx2_FileDecl*,t_mx2_FileDecl*)>(new lambda16(this)));
  }else{
    struct lambda17 : public bbFunction<bbInt(t_mx2_FileDecl*,t_mx2_FileDecl*)>::Rep{
      t_std_collections_List_1Tt_mx2_FileDecl_2* l_self;
      lambda17(t_std_collections_List_1Tt_mx2_FileDecl_2* l_self):l_self(l_self){
      }
      bbInt invoke(t_mx2_FileDecl* l_x,t_mx2_FileDecl* l_y){
        return -bbCompare(l_x,l_y);
      }
      void gcMark(){
        bbGCMarkPtr(l_self);
      }
    };
    this->m_Sort(bbFunction<bbInt(t_mx2_FileDecl*,t_mx2_FileDecl*)>(new lambda17(this)));
  }
}

t_mx2_FileDecl* t_std_collections_List_1Tt_mx2_FileDecl_2::m_RemoveLast(){
  struct f0_t : public bbGCFrame{
    t_mx2_FileDecl* l_value{};
    void gcMark(){
      bbGCMarkPtr(l_value);
    }
  }f0{};
  bbDebugAssert(!this->m_Empty(),BB_T("Debug assert failed"));
  f0.l_value=this->m__0head->m__0pred->m__0value;
  this->m__0head->m__0pred->m_Remove();
  this->m__0seq+=1;
  return f0.l_value;
}

bbBool t_std_collections_List_1Tt_mx2_FileDecl_2::m_RemoveLast(t_mx2_FileDecl* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_mx2_FileDecl_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m_FindLastNode(l_value);
  if(!bbBool(f0.l_node)){
    return false;
  }
  f0.l_node->m_Remove();
  this->m__0seq+=1;
  return true;
}

t_mx2_FileDecl* t_std_collections_List_1Tt_mx2_FileDecl_2::m_RemoveFirst(){
  struct f0_t : public bbGCFrame{
    t_mx2_FileDecl* l_value{};
    void gcMark(){
      bbGCMarkPtr(l_value);
    }
  }f0{};
  bbDebugAssert(!this->m_Empty(),BB_T("Debug assert failed"));
  f0.l_value=this->m__0head->m__0succ->m__0value;
  this->m__0head->m__0succ->m_Remove();
  this->m__0seq+=1;
  return f0.l_value;
}

bbInt t_std_collections_List_1Tt_mx2_FileDecl_2::m_RemoveEach(t_mx2_FileDecl* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_mx2_FileDecl_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m__0head->m__0succ;
  bbInt l_n=bbInt(0);
  while((f0.l_node!=this->m__0head)){
    if((f0.l_node->m__0value==l_value)){
      f0.l_node=f0.l_node->m__0succ;
      f0.l_node->m__0pred->m_Remove();
      l_n+=1;
    }else{
      f0.l_node=f0.l_node->m__0succ;
    }
  }
  if(bbBool(l_n)){
    this->m__0seq+=1;
  }
  return l_n;
}

bbBool t_std_collections_List_1Tt_mx2_FileDecl_2::m_Remove(t_mx2_FileDecl* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_mx2_FileDecl_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m_FindNode(l_value);
  if(!bbBool(f0.l_node)){
    return false;
  }
  f0.l_node->m_Remove();
  this->m__0seq+=1;
  return true;
}

t_std_collections_List_1Tt_mx2_FileDecl_2_Node* t_std_collections_List_1Tt_mx2_FileDecl_2::m_LastNode(){
  if(!this->m_Empty()){
    return this->m__0head->m__0pred;
  }
  return ((t_std_collections_List_1Tt_mx2_FileDecl_2_Node*)0);
}

t_mx2_FileDecl* t_std_collections_List_1Tt_mx2_FileDecl_2::m_Last(){
  bbDebugAssert(!this->m_Empty(),BB_T("Debug assert failed"));
  return this->m__0head->m__0pred->m__0value;
}

t_std_collections_List_1Tt_mx2_FileDecl_2_Node* t_std_collections_List_1Tt_mx2_FileDecl_2::m_HeadNode(){
  return this->m__0head;
}

t_std_collections_List_1Tt_mx2_FileDecl_2_Node* t_std_collections_List_1Tt_mx2_FileDecl_2::m_FirstNode(){
  if(!this->m_Empty()){
    return this->m__0head->m__0succ;
  }
  return ((t_std_collections_List_1Tt_mx2_FileDecl_2_Node*)0);
}

t_mx2_FileDecl* t_std_collections_List_1Tt_mx2_FileDecl_2::m_First(){
  bbDebugAssert(!this->m_Empty(),BB_T("Debug assert failed"));
  return this->m__0head->m__0succ->m__0value;
}

t_std_collections_List_1Tt_mx2_FileDecl_2_Node* t_std_collections_List_1Tt_mx2_FileDecl_2::m_FindNode(t_mx2_FileDecl* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_mx2_FileDecl_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m__0head->m__0succ;
  while((f0.l_node!=this->m__0head)){
    if((f0.l_node->m__0value==l_value)){
      return f0.l_node;
    }
    f0.l_node=f0.l_node->m__0succ;
  }
  return ((t_std_collections_List_1Tt_mx2_FileDecl_2_Node*)0);
}

t_std_collections_List_1Tt_mx2_FileDecl_2_Node* t_std_collections_List_1Tt_mx2_FileDecl_2::m_FindLastNode(t_mx2_FileDecl* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_mx2_FileDecl_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m__0head->m__0pred;
  while((f0.l_node!=this->m__0head)){
    if((f0.l_node->m__0value==l_value)){
      return f0.l_node;
    }
    f0.l_node=f0.l_node->m__0pred;
  }
  return ((t_std_collections_List_1Tt_mx2_FileDecl_2_Node*)0);
}

bbBool t_std_collections_List_1Tt_mx2_FileDecl_2::m_Empty(){
  return (this->m__0head->m__0succ==this->m__0head);
}

bbInt t_std_collections_List_1Tt_mx2_FileDecl_2::m_Count(){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_mx2_FileDecl_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m__0head->m__0succ;
  bbInt l_n=bbInt(0);
  while((f0.l_node!=this->m__0head)){
    f0.l_node=f0.l_node->m__0succ;
    l_n+=1;
  }
  return l_n;
}

void t_std_collections_List_1Tt_mx2_FileDecl_2::m_Clear(){
  this->m__0head->m__0succ=this->m__0head;
  this->m__0head->m__0pred=this->m__0head;
  this->m__0seq+=1;
}

t_std_collections_List_1Tt_mx2_FileDecl_2_BackwardsIterator t_std_collections_List_1Tt_mx2_FileDecl_2::m_Backwards(){
  return t_std_collections_List_1Tt_mx2_FileDecl_2_BackwardsIterator(this,this->m__0head->m__0pred);
}

t_std_collections_List_1Tt_mx2_FileDecl_2_Iterator t_std_collections_List_1Tt_mx2_FileDecl_2::m_All(){
  return t_std_collections_List_1Tt_mx2_FileDecl_2_Iterator(this,this->m__0head->m__0succ);
}

t_std_collections_List_1Tt_mx2_FileDecl_2_Node* t_std_collections_List_1Tt_mx2_FileDecl_2::m_AddLast(t_mx2_FileDecl* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_mx2_FileDecl_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=bbGCNew<t_std_collections_List_1Tt_mx2_FileDecl_2_Node>(l_value,this->m__0head);
  this->m__0seq+=1;
  return f0.l_node;
}

t_std_collections_List_1Tt_mx2_FileDecl_2_Node* t_std_collections_List_1Tt_mx2_FileDecl_2::m_AddFirst(t_mx2_FileDecl* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_mx2_FileDecl_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=bbGCNew<t_std_collections_List_1Tt_mx2_FileDecl_2_Node>(l_value,this->m__0head->m__0succ);
  this->m__0seq+=1;
  return f0.l_node;
}

void t_std_collections_List_1Tt_mx2_FileDecl_2::m_AddAll(bbArray<bbGCVar<t_mx2_FileDecl>>* l_values){
  {
    bbInt l_0=bbInt(0);
    bbInt l_1=l_values->length();
    for(;(l_0<l_1);l_0+=1){
      struct f2_t : public bbGCFrame{
        t_mx2_FileDecl* l_value{};
        void gcMark(){
          bbGCMarkPtr(l_value);
        }
      }f2{};
      f2.l_value=l_values->at(l_0);
      this->m_AddLast(f2.l_value);
    }
  }
}

void t_std_collections_List_1Tt_mx2_FileDecl_2::m_Add(t_mx2_FileDecl* l_value){
  this->m_AddLast(l_value);
}

void t_std_collections_List_1Tt_mx2_FileScope_2_Node::gcMark(){
  bbGCMark(m__0succ);
  bbGCMark(m__0pred);
  bbGCMark(m__0value);
}

t_std_collections_List_1Tt_mx2_FileScope_2_Node::t_std_collections_List_1Tt_mx2_FileScope_2_Node(t_mx2_FileScope* l_value,t_std_collections_List_1Tt_mx2_FileScope_2_Node* l_succ){
  this->m__0value=l_value;
  this->m__0succ=l_succ;
  this->m__0pred=l_succ->m__0pred;
  this->m__0pred->m__0succ=this;
  l_succ->m__0pred=this;
}

t_std_collections_List_1Tt_mx2_FileScope_2_Node::t_std_collections_List_1Tt_mx2_FileScope_2_Node(t_mx2_FileScope* l_value){
  this->m__0value=l_value;
  this->m__0succ=this;
  this->m__0pred=this;
}

void t_std_collections_List_1Tt_mx2_FileScope_2_Node::m_Value(t_mx2_FileScope* l_value){
  this->m__0value=l_value;
}

t_mx2_FileScope* t_std_collections_List_1Tt_mx2_FileScope_2_Node::m_Value(){
  return this->m__0value;
}

t_std_collections_List_1Tt_mx2_FileScope_2_Node* t_std_collections_List_1Tt_mx2_FileScope_2_Node::m_Succ(){
  return this->m__0succ;
}

void t_std_collections_List_1Tt_mx2_FileScope_2_Node::m_Remove(){
  this->m__0succ->m__0pred=this->m__0pred;
  this->m__0pred->m__0succ=this->m__0succ;
}

t_std_collections_List_1Tt_mx2_FileScope_2_Node* t_std_collections_List_1Tt_mx2_FileScope_2_Node::m_Pred(){
  return this->m__0pred;
}

void t_std_collections_List_1Tt_mx2_FileScope_2_Node::m_InsertBefore(t_std_collections_List_1Tt_mx2_FileScope_2_Node* l_node){
  this->m__0succ=l_node;
  this->m__0pred=l_node->m__0pred;
  this->m__0pred->m__0succ=this;
  l_node->m__0pred=this;
}

void t_std_collections_List_1Tt_mx2_FileScope_2_Node::m_InsertAfter(t_std_collections_List_1Tt_mx2_FileScope_2_Node* l_node){
  this->m__0pred=l_node;
  this->m__0succ=l_node->m__0succ;
  this->m__0succ->m__0pred=this;
  l_node->m__0succ=this;
}

t_std_collections_List_1Tt_mx2_FileScope_2_Iterator::t_std_collections_List_1Tt_mx2_FileScope_2_Iterator(t_std_collections_List_1Tt_mx2_FileScope_2* l_list,t_std_collections_List_1Tt_mx2_FileScope_2_Node* l_node){
  (*this).m__0list=l_list;
  (*this).m__0node=l_node;
  (*this).m__0seq=l_list->m__0seq;
}

void t_std_collections_List_1Tt_mx2_FileScope_2_Iterator::m_Insert(t_mx2_FileScope* l_value){
  (*this).m_AssertSeq();
  (*this).m__0node=bbGCNew<t_std_collections_List_1Tt_mx2_FileScope_2_Node>(l_value,(*this).m__0node);
  (*this).m__0list->m__0seq+=1;
  (*this).m__0seq=(*this).m__0list->m__0seq;
}

void t_std_collections_List_1Tt_mx2_FileScope_2_Iterator::m_Erase(){
  (*this).m_AssertCurrent();
  (*this).m__0node=(*this).m__0node->m__0succ;
  (*this).m__0node->m__0pred->m_Remove();
  (*this).m__0list->m__0seq+=1;
  (*this).m__0seq=(*this).m__0list->m__0seq;
}

void t_std_collections_List_1Tt_mx2_FileScope_2_Iterator::m_Current(t_mx2_FileScope* l_current){
  (*this).m_AssertCurrent();
  (*this).m__0node->m__0value=l_current;
}

t_mx2_FileScope* t_std_collections_List_1Tt_mx2_FileScope_2_Iterator::m_Current(){
  (*this).m_AssertCurrent();
  return (*this).m__0node->m__0value;
}

void t_std_collections_List_1Tt_mx2_FileScope_2_Iterator::m_Bump(){
  (*this).m_AssertCurrent();
  (*this).m__0node=(*this).m__0node->m__0succ;
}

bbBool t_std_collections_List_1Tt_mx2_FileScope_2_Iterator::m_AtEnd(){
  (*this).m_AssertSeq();
  return ((*this).m__0node==(*this).m__0list->m__0head);
}

void t_std_collections_List_1Tt_mx2_FileScope_2_Iterator::m_AssertSeq(){
  bbDebugAssert(((*this).m__0seq==(*this).m__0list->m__0seq),BB_T("Concurrent list modification"));
}

void t_std_collections_List_1Tt_mx2_FileScope_2_Iterator::m_AssertCurrent(){
  bbDebugAssert(!(*this).m_AtEnd(),BB_T("Invalid list iterator"));
}

int bbCompare(const t_std_collections_List_1Tt_mx2_FileScope_2_Iterator&x,const t_std_collections_List_1Tt_mx2_FileScope_2_Iterator&y){
  if(int t=bbCompare(x.m__0list,y.m__0list)) return t;
  if(int t=bbCompare(x.m__0node,y.m__0node)) return t;
  if(int t=bbCompare(x.m__0seq,y.m__0seq)) return t;
  return 0;
}

void bbGCMark(const t_std_collections_List_1Tt_mx2_FileScope_2_Iterator&t){
  bbGCMark(t.m__0list);
  bbGCMark(t.m__0node);
}

t_std_collections_List_1Tt_mx2_FileScope_2_BackwardsIterator::t_std_collections_List_1Tt_mx2_FileScope_2_BackwardsIterator(t_std_collections_List_1Tt_mx2_FileScope_2* l_list,t_std_collections_List_1Tt_mx2_FileScope_2_Node* l_node){
  (*this).m__0list=l_list;
  (*this).m__0node=l_node;
  (*this).m__0seq=l_list->m__0seq;
}

void t_std_collections_List_1Tt_mx2_FileScope_2_BackwardsIterator::m_Insert(t_mx2_FileScope* l_value){
  (*this).m_AssertSeq();
  (*this).m__0node=bbGCNew<t_std_collections_List_1Tt_mx2_FileScope_2_Node>(l_value,(*this).m__0node->m__0succ);
  (*this).m__0list->m__0seq+=1;
  (*this).m__0seq=(*this).m__0list->m__0seq;
}

void t_std_collections_List_1Tt_mx2_FileScope_2_BackwardsIterator::m_Erase(){
  (*this).m_AssertCurrent();
  (*this).m__0node=(*this).m__0node->m__0pred;
  (*this).m__0node->m__0succ->m_Remove();
  (*this).m__0list->m__0seq+=1;
  (*this).m__0seq=(*this).m__0list->m__0seq;
}

void t_std_collections_List_1Tt_mx2_FileScope_2_BackwardsIterator::m_Current(t_mx2_FileScope* l_current){
  (*this).m_AssertCurrent();
  (*this).m__0node->m__0value=l_current;
}

t_mx2_FileScope* t_std_collections_List_1Tt_mx2_FileScope_2_BackwardsIterator::m_Current(){
  (*this).m_AssertCurrent();
  return (*this).m__0node->m__0value;
}

void t_std_collections_List_1Tt_mx2_FileScope_2_BackwardsIterator::m_Bump(){
  (*this).m_AssertCurrent();
  (*this).m__0node=(*this).m__0node->m__0pred;
}

bbBool t_std_collections_List_1Tt_mx2_FileScope_2_BackwardsIterator::m_AtEnd(){
  (*this).m_AssertSeq();
  return ((*this).m__0node==(*this).m__0list->m__0head);
}

void t_std_collections_List_1Tt_mx2_FileScope_2_BackwardsIterator::m_AssertSeq(){
  bbDebugAssert(((*this).m__0seq==(*this).m__0list->m__0seq),BB_T("Concurrent list modification"));
}

void t_std_collections_List_1Tt_mx2_FileScope_2_BackwardsIterator::m_AssertCurrent(){
  bbDebugAssert(!(*this).m_AtEnd(),BB_T("Invalid list iterator"));
}

int bbCompare(const t_std_collections_List_1Tt_mx2_FileScope_2_BackwardsIterator&x,const t_std_collections_List_1Tt_mx2_FileScope_2_BackwardsIterator&y){
  if(int t=bbCompare(x.m__0list,y.m__0list)) return t;
  if(int t=bbCompare(x.m__0node,y.m__0node)) return t;
  if(int t=bbCompare(x.m__0seq,y.m__0seq)) return t;
  return 0;
}

void bbGCMark(const t_std_collections_List_1Tt_mx2_FileScope_2_BackwardsIterator&t){
  bbGCMark(t.m__0list);
  bbGCMark(t.m__0node);
}

void t_std_collections_List_1Tt_mx2_FileScope_2::gcMark(){
  bbGCMark(m__0head);
}

t_std_collections_List_1Tt_mx2_FileScope_2::t_std_collections_List_1Tt_mx2_FileScope_2(t_std_collections_List_1Tt_mx2_FileScope_2* l_values):t_std_collections_List_1Tt_mx2_FileScope_2(){
  g_std_collections_List_1Tt_mx2_FileScope_2_AddAll_1Tt_std_collections_List_1Tt_mx2_FileScope_2_2(this,l_values);
}

t_std_collections_List_1Tt_mx2_FileScope_2::t_std_collections_List_1Tt_mx2_FileScope_2(t_std_collections_Stack_1Tt_mx2_FileScope_2* l_values):t_std_collections_List_1Tt_mx2_FileScope_2(){
  g_std_collections_List_1Tt_mx2_FileScope_2_AddAll_1Tt_std_collections_Stack_1Tt_mx2_FileScope_2_2(this,l_values);
}

t_std_collections_List_1Tt_mx2_FileScope_2::t_std_collections_List_1Tt_mx2_FileScope_2(bbArray<bbGCVar<t_mx2_FileScope>>* l_values):t_std_collections_List_1Tt_mx2_FileScope_2(){
  this->m_AddAll(l_values);
}

t_std_collections_List_1Tt_mx2_FileScope_2::t_std_collections_List_1Tt_mx2_FileScope_2(){
  this->m__0head=bbGCNew<t_std_collections_List_1Tt_mx2_FileScope_2_Node>(((t_mx2_FileScope*)0));
}

bbArray<bbGCVar<t_mx2_FileScope>>* t_std_collections_List_1Tt_mx2_FileScope_2::m_ToArray(){
  struct f0_t : public bbGCFrame{
    bbArray<bbGCVar<t_mx2_FileScope>>* l_data{};
    t_std_collections_List_1Tt_mx2_FileScope_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_data);
      bbGCMarkPtr(l_node);
    }
  }f0{};
  bbInt l_n=this->m_Count();
  f0.l_data=bbArray<bbGCVar<t_mx2_FileScope>>::create(l_n);
  f0.l_node=this->m__0head->m__0succ;
  {
    bbInt l_i=bbInt(0);
    for(;(l_i<l_n);l_i+=1){
      f0.l_data->at(l_i)=f0.l_node->m__0value;
      f0.l_node=f0.l_node->m__0succ;
    }
  }
  return f0.l_data;
}

void t_std_collections_List_1Tt_mx2_FileScope_2::m_Sort(bbFunction<bbInt(t_mx2_FileScope*,t_mx2_FileScope*)> l_compareFunc){
  bbInt l_insize=1;
  for(;;){
    struct f1_t : public bbGCFrame{
      t_std_collections_List_1Tt_mx2_FileScope_2_Node* l_p{};
      t_std_collections_List_1Tt_mx2_FileScope_2_Node* l_tail{};
      void gcMark(){
        bbGCMarkPtr(l_p);
        bbGCMarkPtr(l_tail);
      }
    }f1{};
    bbInt l_merges=bbInt(0);
    f1.l_tail=this->m__0head;
    f1.l_p=this->m__0head->m__0succ;
    while((f1.l_p!=this->m__0head)){
      struct f2_t : public bbGCFrame{
        t_std_collections_List_1Tt_mx2_FileScope_2_Node* l_q{};
        void gcMark(){
          bbGCMarkPtr(l_q);
        }
      }f2{};
      l_merges+=1;
      f2.l_q=f1.l_p->m__0succ;
      bbInt l_qsize=l_insize;
      bbInt l_psize=1;
      while(((l_psize<l_insize)&&(f2.l_q!=this->m__0head))){
        l_psize+=1;
        f2.l_q=f2.l_q->m__0succ;
      }
      for(;;){
        struct f3_t : public bbGCFrame{
          t_std_collections_List_1Tt_mx2_FileScope_2_Node* l_t{};
          void gcMark(){
            bbGCMarkPtr(l_t);
          }
        }f3{};
        if(((bbBool(l_psize)&&bbBool(l_qsize))&&(f2.l_q!=this->m__0head))){
          bbInt l_cc=l_compareFunc(f1.l_p->m__0value,f2.l_q->m__0value);
          if((l_cc<=bbInt(0))){
            f3.l_t=f1.l_p;
            f1.l_p=f1.l_p->m__0succ;
            l_psize-=1;
          }else{
            f3.l_t=f2.l_q;
            f2.l_q=f2.l_q->m__0succ;
            l_qsize-=1;
          }
        }else if(bbBool(l_psize)){
          f3.l_t=f1.l_p;
          f1.l_p=f1.l_p->m__0succ;
          l_psize-=1;
        }else if((bbBool(l_qsize)&&(f2.l_q!=this->m__0head))){
          f3.l_t=f2.l_q;
          f2.l_q=f2.l_q->m__0succ;
          l_qsize-=1;
        }else{
          break;
        }
        f3.l_t->m__0pred=f1.l_tail;
        f1.l_tail->m__0succ=f3.l_t;
        f1.l_tail=f3.l_t;
      }
      f1.l_p=f2.l_q;
    }
    f1.l_tail->m__0succ=this->m__0head;
    this->m__0head->m__0pred=f1.l_tail;
    if((l_merges<=1)){
      return;
    }
    l_insize*=2;
  }
}

void t_std_collections_List_1Tt_mx2_FileScope_2::m_Sort(bbBool l_ascending){
  if(l_ascending){
    struct lambda18 : public bbFunction<bbInt(t_mx2_FileScope*,t_mx2_FileScope*)>::Rep{
      t_std_collections_List_1Tt_mx2_FileScope_2* l_self;
      lambda18(t_std_collections_List_1Tt_mx2_FileScope_2* l_self):l_self(l_self){
      }
      bbInt invoke(t_mx2_FileScope* l_x,t_mx2_FileScope* l_y){
        return bbCompare(l_x,l_y);
      }
      void gcMark(){
        bbGCMarkPtr(l_self);
      }
    };
    this->m_Sort(bbFunction<bbInt(t_mx2_FileScope*,t_mx2_FileScope*)>(new lambda18(this)));
  }else{
    struct lambda19 : public bbFunction<bbInt(t_mx2_FileScope*,t_mx2_FileScope*)>::Rep{
      t_std_collections_List_1Tt_mx2_FileScope_2* l_self;
      lambda19(t_std_collections_List_1Tt_mx2_FileScope_2* l_self):l_self(l_self){
      }
      bbInt invoke(t_mx2_FileScope* l_x,t_mx2_FileScope* l_y){
        return -bbCompare(l_x,l_y);
      }
      void gcMark(){
        bbGCMarkPtr(l_self);
      }
    };
    this->m_Sort(bbFunction<bbInt(t_mx2_FileScope*,t_mx2_FileScope*)>(new lambda19(this)));
  }
}

t_mx2_FileScope* t_std_collections_List_1Tt_mx2_FileScope_2::m_RemoveLast(){
  struct f0_t : public bbGCFrame{
    t_mx2_FileScope* l_value{};
    void gcMark(){
      bbGCMarkPtr(l_value);
    }
  }f0{};
  bbDebugAssert(!this->m_Empty(),BB_T("Debug assert failed"));
  f0.l_value=this->m__0head->m__0pred->m__0value;
  this->m__0head->m__0pred->m_Remove();
  this->m__0seq+=1;
  return f0.l_value;
}

bbBool t_std_collections_List_1Tt_mx2_FileScope_2::m_RemoveLast(t_mx2_FileScope* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_mx2_FileScope_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m_FindLastNode(l_value);
  if(!bbBool(f0.l_node)){
    return false;
  }
  f0.l_node->m_Remove();
  this->m__0seq+=1;
  return true;
}

t_mx2_FileScope* t_std_collections_List_1Tt_mx2_FileScope_2::m_RemoveFirst(){
  struct f0_t : public bbGCFrame{
    t_mx2_FileScope* l_value{};
    void gcMark(){
      bbGCMarkPtr(l_value);
    }
  }f0{};
  bbDebugAssert(!this->m_Empty(),BB_T("Debug assert failed"));
  f0.l_value=this->m__0head->m__0succ->m__0value;
  this->m__0head->m__0succ->m_Remove();
  this->m__0seq+=1;
  return f0.l_value;
}

bbInt t_std_collections_List_1Tt_mx2_FileScope_2::m_RemoveEach(t_mx2_FileScope* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_mx2_FileScope_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m__0head->m__0succ;
  bbInt l_n=bbInt(0);
  while((f0.l_node!=this->m__0head)){
    if((f0.l_node->m__0value==l_value)){
      f0.l_node=f0.l_node->m__0succ;
      f0.l_node->m__0pred->m_Remove();
      l_n+=1;
    }else{
      f0.l_node=f0.l_node->m__0succ;
    }
  }
  if(bbBool(l_n)){
    this->m__0seq+=1;
  }
  return l_n;
}

bbBool t_std_collections_List_1Tt_mx2_FileScope_2::m_Remove(t_mx2_FileScope* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_mx2_FileScope_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m_FindNode(l_value);
  if(!bbBool(f0.l_node)){
    return false;
  }
  f0.l_node->m_Remove();
  this->m__0seq+=1;
  return true;
}

t_std_collections_List_1Tt_mx2_FileScope_2_Node* t_std_collections_List_1Tt_mx2_FileScope_2::m_LastNode(){
  if(!this->m_Empty()){
    return this->m__0head->m__0pred;
  }
  return ((t_std_collections_List_1Tt_mx2_FileScope_2_Node*)0);
}

t_mx2_FileScope* t_std_collections_List_1Tt_mx2_FileScope_2::m_Last(){
  bbDebugAssert(!this->m_Empty(),BB_T("Debug assert failed"));
  return this->m__0head->m__0pred->m__0value;
}

t_std_collections_List_1Tt_mx2_FileScope_2_Node* t_std_collections_List_1Tt_mx2_FileScope_2::m_HeadNode(){
  return this->m__0head;
}

t_std_collections_List_1Tt_mx2_FileScope_2_Node* t_std_collections_List_1Tt_mx2_FileScope_2::m_FirstNode(){
  if(!this->m_Empty()){
    return this->m__0head->m__0succ;
  }
  return ((t_std_collections_List_1Tt_mx2_FileScope_2_Node*)0);
}

t_mx2_FileScope* t_std_collections_List_1Tt_mx2_FileScope_2::m_First(){
  bbDebugAssert(!this->m_Empty(),BB_T("Debug assert failed"));
  return this->m__0head->m__0succ->m__0value;
}

t_std_collections_List_1Tt_mx2_FileScope_2_Node* t_std_collections_List_1Tt_mx2_FileScope_2::m_FindNode(t_mx2_FileScope* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_mx2_FileScope_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m__0head->m__0succ;
  while((f0.l_node!=this->m__0head)){
    if((f0.l_node->m__0value==l_value)){
      return f0.l_node;
    }
    f0.l_node=f0.l_node->m__0succ;
  }
  return ((t_std_collections_List_1Tt_mx2_FileScope_2_Node*)0);
}

t_std_collections_List_1Tt_mx2_FileScope_2_Node* t_std_collections_List_1Tt_mx2_FileScope_2::m_FindLastNode(t_mx2_FileScope* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_mx2_FileScope_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m__0head->m__0pred;
  while((f0.l_node!=this->m__0head)){
    if((f0.l_node->m__0value==l_value)){
      return f0.l_node;
    }
    f0.l_node=f0.l_node->m__0pred;
  }
  return ((t_std_collections_List_1Tt_mx2_FileScope_2_Node*)0);
}

bbBool t_std_collections_List_1Tt_mx2_FileScope_2::m_Empty(){
  return (this->m__0head->m__0succ==this->m__0head);
}

bbInt t_std_collections_List_1Tt_mx2_FileScope_2::m_Count(){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_mx2_FileScope_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m__0head->m__0succ;
  bbInt l_n=bbInt(0);
  while((f0.l_node!=this->m__0head)){
    f0.l_node=f0.l_node->m__0succ;
    l_n+=1;
  }
  return l_n;
}

void t_std_collections_List_1Tt_mx2_FileScope_2::m_Clear(){
  this->m__0head->m__0succ=this->m__0head;
  this->m__0head->m__0pred=this->m__0head;
  this->m__0seq+=1;
}

t_std_collections_List_1Tt_mx2_FileScope_2_BackwardsIterator t_std_collections_List_1Tt_mx2_FileScope_2::m_Backwards(){
  return t_std_collections_List_1Tt_mx2_FileScope_2_BackwardsIterator(this,this->m__0head->m__0pred);
}

t_std_collections_List_1Tt_mx2_FileScope_2_Iterator t_std_collections_List_1Tt_mx2_FileScope_2::m_All(){
  return t_std_collections_List_1Tt_mx2_FileScope_2_Iterator(this,this->m__0head->m__0succ);
}

t_std_collections_List_1Tt_mx2_FileScope_2_Node* t_std_collections_List_1Tt_mx2_FileScope_2::m_AddLast(t_mx2_FileScope* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_mx2_FileScope_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=bbGCNew<t_std_collections_List_1Tt_mx2_FileScope_2_Node>(l_value,this->m__0head);
  this->m__0seq+=1;
  return f0.l_node;
}

t_std_collections_List_1Tt_mx2_FileScope_2_Node* t_std_collections_List_1Tt_mx2_FileScope_2::m_AddFirst(t_mx2_FileScope* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_mx2_FileScope_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=bbGCNew<t_std_collections_List_1Tt_mx2_FileScope_2_Node>(l_value,this->m__0head->m__0succ);
  this->m__0seq+=1;
  return f0.l_node;
}

void t_std_collections_List_1Tt_mx2_FileScope_2::m_AddAll(bbArray<bbGCVar<t_mx2_FileScope>>* l_values){
  {
    bbInt l_0=bbInt(0);
    bbInt l_1=l_values->length();
    for(;(l_0<l_1);l_0+=1){
      struct f2_t : public bbGCFrame{
        t_mx2_FileScope* l_value{};
        void gcMark(){
          bbGCMarkPtr(l_value);
        }
      }f2{};
      f2.l_value=l_values->at(l_0);
      this->m_AddLast(f2.l_value);
    }
  }
}

void t_std_collections_List_1Tt_mx2_FileScope_2::m_Add(t_mx2_FileScope* l_value){
  this->m_AddLast(l_value);
}

void t_std_collections_List_1Tt_mx2_NamespaceScope_2_Node::gcMark(){
  bbGCMark(m__0succ);
  bbGCMark(m__0pred);
  bbGCMark(m__0value);
}

t_std_collections_List_1Tt_mx2_NamespaceScope_2_Node::t_std_collections_List_1Tt_mx2_NamespaceScope_2_Node(t_mx2_NamespaceScope* l_value,t_std_collections_List_1Tt_mx2_NamespaceScope_2_Node* l_succ){
  this->m__0value=l_value;
  this->m__0succ=l_succ;
  this->m__0pred=l_succ->m__0pred;
  this->m__0pred->m__0succ=this;
  l_succ->m__0pred=this;
}

t_std_collections_List_1Tt_mx2_NamespaceScope_2_Node::t_std_collections_List_1Tt_mx2_NamespaceScope_2_Node(t_mx2_NamespaceScope* l_value){
  this->m__0value=l_value;
  this->m__0succ=this;
  this->m__0pred=this;
}

void t_std_collections_List_1Tt_mx2_NamespaceScope_2_Node::m_Value(t_mx2_NamespaceScope* l_value){
  this->m__0value=l_value;
}

t_mx2_NamespaceScope* t_std_collections_List_1Tt_mx2_NamespaceScope_2_Node::m_Value(){
  return this->m__0value;
}

t_std_collections_List_1Tt_mx2_NamespaceScope_2_Node* t_std_collections_List_1Tt_mx2_NamespaceScope_2_Node::m_Succ(){
  return this->m__0succ;
}

void t_std_collections_List_1Tt_mx2_NamespaceScope_2_Node::m_Remove(){
  this->m__0succ->m__0pred=this->m__0pred;
  this->m__0pred->m__0succ=this->m__0succ;
}

t_std_collections_List_1Tt_mx2_NamespaceScope_2_Node* t_std_collections_List_1Tt_mx2_NamespaceScope_2_Node::m_Pred(){
  return this->m__0pred;
}

void t_std_collections_List_1Tt_mx2_NamespaceScope_2_Node::m_InsertBefore(t_std_collections_List_1Tt_mx2_NamespaceScope_2_Node* l_node){
  this->m__0succ=l_node;
  this->m__0pred=l_node->m__0pred;
  this->m__0pred->m__0succ=this;
  l_node->m__0pred=this;
}

void t_std_collections_List_1Tt_mx2_NamespaceScope_2_Node::m_InsertAfter(t_std_collections_List_1Tt_mx2_NamespaceScope_2_Node* l_node){
  this->m__0pred=l_node;
  this->m__0succ=l_node->m__0succ;
  this->m__0succ->m__0pred=this;
  l_node->m__0succ=this;
}

t_std_collections_List_1Tt_mx2_NamespaceScope_2_Iterator::t_std_collections_List_1Tt_mx2_NamespaceScope_2_Iterator(t_std_collections_List_1Tt_mx2_NamespaceScope_2* l_list,t_std_collections_List_1Tt_mx2_NamespaceScope_2_Node* l_node){
  (*this).m__0list=l_list;
  (*this).m__0node=l_node;
  (*this).m__0seq=l_list->m__0seq;
}

void t_std_collections_List_1Tt_mx2_NamespaceScope_2_Iterator::m_Insert(t_mx2_NamespaceScope* l_value){
  (*this).m_AssertSeq();
  (*this).m__0node=bbGCNew<t_std_collections_List_1Tt_mx2_NamespaceScope_2_Node>(l_value,(*this).m__0node);
  (*this).m__0list->m__0seq+=1;
  (*this).m__0seq=(*this).m__0list->m__0seq;
}

void t_std_collections_List_1Tt_mx2_NamespaceScope_2_Iterator::m_Erase(){
  (*this).m_AssertCurrent();
  (*this).m__0node=(*this).m__0node->m__0succ;
  (*this).m__0node->m__0pred->m_Remove();
  (*this).m__0list->m__0seq+=1;
  (*this).m__0seq=(*this).m__0list->m__0seq;
}

void t_std_collections_List_1Tt_mx2_NamespaceScope_2_Iterator::m_Current(t_mx2_NamespaceScope* l_current){
  (*this).m_AssertCurrent();
  (*this).m__0node->m__0value=l_current;
}

t_mx2_NamespaceScope* t_std_collections_List_1Tt_mx2_NamespaceScope_2_Iterator::m_Current(){
  (*this).m_AssertCurrent();
  return (*this).m__0node->m__0value;
}

void t_std_collections_List_1Tt_mx2_NamespaceScope_2_Iterator::m_Bump(){
  (*this).m_AssertCurrent();
  (*this).m__0node=(*this).m__0node->m__0succ;
}

bbBool t_std_collections_List_1Tt_mx2_NamespaceScope_2_Iterator::m_AtEnd(){
  (*this).m_AssertSeq();
  return ((*this).m__0node==(*this).m__0list->m__0head);
}

void t_std_collections_List_1Tt_mx2_NamespaceScope_2_Iterator::m_AssertSeq(){
  bbDebugAssert(((*this).m__0seq==(*this).m__0list->m__0seq),BB_T("Concurrent list modification"));
}

void t_std_collections_List_1Tt_mx2_NamespaceScope_2_Iterator::m_AssertCurrent(){
  bbDebugAssert(!(*this).m_AtEnd(),BB_T("Invalid list iterator"));
}

int bbCompare(const t_std_collections_List_1Tt_mx2_NamespaceScope_2_Iterator&x,const t_std_collections_List_1Tt_mx2_NamespaceScope_2_Iterator&y){
  if(int t=bbCompare(x.m__0list,y.m__0list)) return t;
  if(int t=bbCompare(x.m__0node,y.m__0node)) return t;
  if(int t=bbCompare(x.m__0seq,y.m__0seq)) return t;
  return 0;
}

void bbGCMark(const t_std_collections_List_1Tt_mx2_NamespaceScope_2_Iterator&t){
  bbGCMark(t.m__0list);
  bbGCMark(t.m__0node);
}

t_std_collections_List_1Tt_mx2_NamespaceScope_2_BackwardsIterator::t_std_collections_List_1Tt_mx2_NamespaceScope_2_BackwardsIterator(t_std_collections_List_1Tt_mx2_NamespaceScope_2* l_list,t_std_collections_List_1Tt_mx2_NamespaceScope_2_Node* l_node){
  (*this).m__0list=l_list;
  (*this).m__0node=l_node;
  (*this).m__0seq=l_list->m__0seq;
}

void t_std_collections_List_1Tt_mx2_NamespaceScope_2_BackwardsIterator::m_Insert(t_mx2_NamespaceScope* l_value){
  (*this).m_AssertSeq();
  (*this).m__0node=bbGCNew<t_std_collections_List_1Tt_mx2_NamespaceScope_2_Node>(l_value,(*this).m__0node->m__0succ);
  (*this).m__0list->m__0seq+=1;
  (*this).m__0seq=(*this).m__0list->m__0seq;
}

void t_std_collections_List_1Tt_mx2_NamespaceScope_2_BackwardsIterator::m_Erase(){
  (*this).m_AssertCurrent();
  (*this).m__0node=(*this).m__0node->m__0pred;
  (*this).m__0node->m__0succ->m_Remove();
  (*this).m__0list->m__0seq+=1;
  (*this).m__0seq=(*this).m__0list->m__0seq;
}

void t_std_collections_List_1Tt_mx2_NamespaceScope_2_BackwardsIterator::m_Current(t_mx2_NamespaceScope* l_current){
  (*this).m_AssertCurrent();
  (*this).m__0node->m__0value=l_current;
}

t_mx2_NamespaceScope* t_std_collections_List_1Tt_mx2_NamespaceScope_2_BackwardsIterator::m_Current(){
  (*this).m_AssertCurrent();
  return (*this).m__0node->m__0value;
}

void t_std_collections_List_1Tt_mx2_NamespaceScope_2_BackwardsIterator::m_Bump(){
  (*this).m_AssertCurrent();
  (*this).m__0node=(*this).m__0node->m__0pred;
}

bbBool t_std_collections_List_1Tt_mx2_NamespaceScope_2_BackwardsIterator::m_AtEnd(){
  (*this).m_AssertSeq();
  return ((*this).m__0node==(*this).m__0list->m__0head);
}

void t_std_collections_List_1Tt_mx2_NamespaceScope_2_BackwardsIterator::m_AssertSeq(){
  bbDebugAssert(((*this).m__0seq==(*this).m__0list->m__0seq),BB_T("Concurrent list modification"));
}

void t_std_collections_List_1Tt_mx2_NamespaceScope_2_BackwardsIterator::m_AssertCurrent(){
  bbDebugAssert(!(*this).m_AtEnd(),BB_T("Invalid list iterator"));
}

int bbCompare(const t_std_collections_List_1Tt_mx2_NamespaceScope_2_BackwardsIterator&x,const t_std_collections_List_1Tt_mx2_NamespaceScope_2_BackwardsIterator&y){
  if(int t=bbCompare(x.m__0list,y.m__0list)) return t;
  if(int t=bbCompare(x.m__0node,y.m__0node)) return t;
  if(int t=bbCompare(x.m__0seq,y.m__0seq)) return t;
  return 0;
}

void bbGCMark(const t_std_collections_List_1Tt_mx2_NamespaceScope_2_BackwardsIterator&t){
  bbGCMark(t.m__0list);
  bbGCMark(t.m__0node);
}

void t_std_collections_List_1Tt_mx2_NamespaceScope_2::gcMark(){
  bbGCMark(m__0head);
}

t_std_collections_List_1Tt_mx2_NamespaceScope_2::t_std_collections_List_1Tt_mx2_NamespaceScope_2(t_std_collections_List_1Tt_mx2_NamespaceScope_2* l_values):t_std_collections_List_1Tt_mx2_NamespaceScope_2(){
  g_std_collections_List_1Tt_mx2_NamespaceScope_2_AddAll_1Tt_std_collections_List_1Tt_mx2_NamespaceScope_2_2(this,l_values);
}

t_std_collections_List_1Tt_mx2_NamespaceScope_2::t_std_collections_List_1Tt_mx2_NamespaceScope_2(t_std_collections_Stack_1Tt_mx2_NamespaceScope_2* l_values):t_std_collections_List_1Tt_mx2_NamespaceScope_2(){
  g_std_collections_List_1Tt_mx2_NamespaceScope_2_AddAll_1Tt_std_collections_Stack_1Tt_mx2_NamespaceScope_2_2(this,l_values);
}

t_std_collections_List_1Tt_mx2_NamespaceScope_2::t_std_collections_List_1Tt_mx2_NamespaceScope_2(bbArray<bbGCVar<t_mx2_NamespaceScope>>* l_values):t_std_collections_List_1Tt_mx2_NamespaceScope_2(){
  this->m_AddAll(l_values);
}

t_std_collections_List_1Tt_mx2_NamespaceScope_2::t_std_collections_List_1Tt_mx2_NamespaceScope_2(){
  this->m__0head=bbGCNew<t_std_collections_List_1Tt_mx2_NamespaceScope_2_Node>(((t_mx2_NamespaceScope*)0));
}

bbArray<bbGCVar<t_mx2_NamespaceScope>>* t_std_collections_List_1Tt_mx2_NamespaceScope_2::m_ToArray(){
  struct f0_t : public bbGCFrame{
    bbArray<bbGCVar<t_mx2_NamespaceScope>>* l_data{};
    t_std_collections_List_1Tt_mx2_NamespaceScope_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_data);
      bbGCMarkPtr(l_node);
    }
  }f0{};
  bbInt l_n=this->m_Count();
  f0.l_data=bbArray<bbGCVar<t_mx2_NamespaceScope>>::create(l_n);
  f0.l_node=this->m__0head->m__0succ;
  {
    bbInt l_i=bbInt(0);
    for(;(l_i<l_n);l_i+=1){
      f0.l_data->at(l_i)=f0.l_node->m__0value;
      f0.l_node=f0.l_node->m__0succ;
    }
  }
  return f0.l_data;
}

void t_std_collections_List_1Tt_mx2_NamespaceScope_2::m_Sort(bbFunction<bbInt(t_mx2_NamespaceScope*,t_mx2_NamespaceScope*)> l_compareFunc){
  bbInt l_insize=1;
  for(;;){
    struct f1_t : public bbGCFrame{
      t_std_collections_List_1Tt_mx2_NamespaceScope_2_Node* l_p{};
      t_std_collections_List_1Tt_mx2_NamespaceScope_2_Node* l_tail{};
      void gcMark(){
        bbGCMarkPtr(l_p);
        bbGCMarkPtr(l_tail);
      }
    }f1{};
    bbInt l_merges=bbInt(0);
    f1.l_tail=this->m__0head;
    f1.l_p=this->m__0head->m__0succ;
    while((f1.l_p!=this->m__0head)){
      struct f2_t : public bbGCFrame{
        t_std_collections_List_1Tt_mx2_NamespaceScope_2_Node* l_q{};
        void gcMark(){
          bbGCMarkPtr(l_q);
        }
      }f2{};
      l_merges+=1;
      f2.l_q=f1.l_p->m__0succ;
      bbInt l_qsize=l_insize;
      bbInt l_psize=1;
      while(((l_psize<l_insize)&&(f2.l_q!=this->m__0head))){
        l_psize+=1;
        f2.l_q=f2.l_q->m__0succ;
      }
      for(;;){
        struct f3_t : public bbGCFrame{
          t_std_collections_List_1Tt_mx2_NamespaceScope_2_Node* l_t{};
          void gcMark(){
            bbGCMarkPtr(l_t);
          }
        }f3{};
        if(((bbBool(l_psize)&&bbBool(l_qsize))&&(f2.l_q!=this->m__0head))){
          bbInt l_cc=l_compareFunc(f1.l_p->m__0value,f2.l_q->m__0value);
          if((l_cc<=bbInt(0))){
            f3.l_t=f1.l_p;
            f1.l_p=f1.l_p->m__0succ;
            l_psize-=1;
          }else{
            f3.l_t=f2.l_q;
            f2.l_q=f2.l_q->m__0succ;
            l_qsize-=1;
          }
        }else if(bbBool(l_psize)){
          f3.l_t=f1.l_p;
          f1.l_p=f1.l_p->m__0succ;
          l_psize-=1;
        }else if((bbBool(l_qsize)&&(f2.l_q!=this->m__0head))){
          f3.l_t=f2.l_q;
          f2.l_q=f2.l_q->m__0succ;
          l_qsize-=1;
        }else{
          break;
        }
        f3.l_t->m__0pred=f1.l_tail;
        f1.l_tail->m__0succ=f3.l_t;
        f1.l_tail=f3.l_t;
      }
      f1.l_p=f2.l_q;
    }
    f1.l_tail->m__0succ=this->m__0head;
    this->m__0head->m__0pred=f1.l_tail;
    if((l_merges<=1)){
      return;
    }
    l_insize*=2;
  }
}

void t_std_collections_List_1Tt_mx2_NamespaceScope_2::m_Sort(bbBool l_ascending){
  if(l_ascending){
    struct lambda20 : public bbFunction<bbInt(t_mx2_NamespaceScope*,t_mx2_NamespaceScope*)>::Rep{
      t_std_collections_List_1Tt_mx2_NamespaceScope_2* l_self;
      lambda20(t_std_collections_List_1Tt_mx2_NamespaceScope_2* l_self):l_self(l_self){
      }
      bbInt invoke(t_mx2_NamespaceScope* l_x,t_mx2_NamespaceScope* l_y){
        return bbCompare(l_x,l_y);
      }
      void gcMark(){
        bbGCMarkPtr(l_self);
      }
    };
    this->m_Sort(bbFunction<bbInt(t_mx2_NamespaceScope*,t_mx2_NamespaceScope*)>(new lambda20(this)));
  }else{
    struct lambda21 : public bbFunction<bbInt(t_mx2_NamespaceScope*,t_mx2_NamespaceScope*)>::Rep{
      t_std_collections_List_1Tt_mx2_NamespaceScope_2* l_self;
      lambda21(t_std_collections_List_1Tt_mx2_NamespaceScope_2* l_self):l_self(l_self){
      }
      bbInt invoke(t_mx2_NamespaceScope* l_x,t_mx2_NamespaceScope* l_y){
        return -bbCompare(l_x,l_y);
      }
      void gcMark(){
        bbGCMarkPtr(l_self);
      }
    };
    this->m_Sort(bbFunction<bbInt(t_mx2_NamespaceScope*,t_mx2_NamespaceScope*)>(new lambda21(this)));
  }
}

t_mx2_NamespaceScope* t_std_collections_List_1Tt_mx2_NamespaceScope_2::m_RemoveLast(){
  struct f0_t : public bbGCFrame{
    t_mx2_NamespaceScope* l_value{};
    void gcMark(){
      bbGCMarkPtr(l_value);
    }
  }f0{};
  bbDebugAssert(!this->m_Empty(),BB_T("Debug assert failed"));
  f0.l_value=this->m__0head->m__0pred->m__0value;
  this->m__0head->m__0pred->m_Remove();
  this->m__0seq+=1;
  return f0.l_value;
}

bbBool t_std_collections_List_1Tt_mx2_NamespaceScope_2::m_RemoveLast(t_mx2_NamespaceScope* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_mx2_NamespaceScope_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m_FindLastNode(l_value);
  if(!bbBool(f0.l_node)){
    return false;
  }
  f0.l_node->m_Remove();
  this->m__0seq+=1;
  return true;
}

t_mx2_NamespaceScope* t_std_collections_List_1Tt_mx2_NamespaceScope_2::m_RemoveFirst(){
  struct f0_t : public bbGCFrame{
    t_mx2_NamespaceScope* l_value{};
    void gcMark(){
      bbGCMarkPtr(l_value);
    }
  }f0{};
  bbDebugAssert(!this->m_Empty(),BB_T("Debug assert failed"));
  f0.l_value=this->m__0head->m__0succ->m__0value;
  this->m__0head->m__0succ->m_Remove();
  this->m__0seq+=1;
  return f0.l_value;
}

bbInt t_std_collections_List_1Tt_mx2_NamespaceScope_2::m_RemoveEach(t_mx2_NamespaceScope* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_mx2_NamespaceScope_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m__0head->m__0succ;
  bbInt l_n=bbInt(0);
  while((f0.l_node!=this->m__0head)){
    if((f0.l_node->m__0value==l_value)){
      f0.l_node=f0.l_node->m__0succ;
      f0.l_node->m__0pred->m_Remove();
      l_n+=1;
    }else{
      f0.l_node=f0.l_node->m__0succ;
    }
  }
  if(bbBool(l_n)){
    this->m__0seq+=1;
  }
  return l_n;
}

bbBool t_std_collections_List_1Tt_mx2_NamespaceScope_2::m_Remove(t_mx2_NamespaceScope* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_mx2_NamespaceScope_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m_FindNode(l_value);
  if(!bbBool(f0.l_node)){
    return false;
  }
  f0.l_node->m_Remove();
  this->m__0seq+=1;
  return true;
}

t_std_collections_List_1Tt_mx2_NamespaceScope_2_Node* t_std_collections_List_1Tt_mx2_NamespaceScope_2::m_LastNode(){
  if(!this->m_Empty()){
    return this->m__0head->m__0pred;
  }
  return ((t_std_collections_List_1Tt_mx2_NamespaceScope_2_Node*)0);
}

t_mx2_NamespaceScope* t_std_collections_List_1Tt_mx2_NamespaceScope_2::m_Last(){
  bbDebugAssert(!this->m_Empty(),BB_T("Debug assert failed"));
  return this->m__0head->m__0pred->m__0value;
}

t_std_collections_List_1Tt_mx2_NamespaceScope_2_Node* t_std_collections_List_1Tt_mx2_NamespaceScope_2::m_HeadNode(){
  return this->m__0head;
}

t_std_collections_List_1Tt_mx2_NamespaceScope_2_Node* t_std_collections_List_1Tt_mx2_NamespaceScope_2::m_FirstNode(){
  if(!this->m_Empty()){
    return this->m__0head->m__0succ;
  }
  return ((t_std_collections_List_1Tt_mx2_NamespaceScope_2_Node*)0);
}

t_mx2_NamespaceScope* t_std_collections_List_1Tt_mx2_NamespaceScope_2::m_First(){
  bbDebugAssert(!this->m_Empty(),BB_T("Debug assert failed"));
  return this->m__0head->m__0succ->m__0value;
}

t_std_collections_List_1Tt_mx2_NamespaceScope_2_Node* t_std_collections_List_1Tt_mx2_NamespaceScope_2::m_FindNode(t_mx2_NamespaceScope* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_mx2_NamespaceScope_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m__0head->m__0succ;
  while((f0.l_node!=this->m__0head)){
    if((f0.l_node->m__0value==l_value)){
      return f0.l_node;
    }
    f0.l_node=f0.l_node->m__0succ;
  }
  return ((t_std_collections_List_1Tt_mx2_NamespaceScope_2_Node*)0);
}

t_std_collections_List_1Tt_mx2_NamespaceScope_2_Node* t_std_collections_List_1Tt_mx2_NamespaceScope_2::m_FindLastNode(t_mx2_NamespaceScope* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_mx2_NamespaceScope_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m__0head->m__0pred;
  while((f0.l_node!=this->m__0head)){
    if((f0.l_node->m__0value==l_value)){
      return f0.l_node;
    }
    f0.l_node=f0.l_node->m__0pred;
  }
  return ((t_std_collections_List_1Tt_mx2_NamespaceScope_2_Node*)0);
}

bbBool t_std_collections_List_1Tt_mx2_NamespaceScope_2::m_Empty(){
  return (this->m__0head->m__0succ==this->m__0head);
}

bbInt t_std_collections_List_1Tt_mx2_NamespaceScope_2::m_Count(){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_mx2_NamespaceScope_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m__0head->m__0succ;
  bbInt l_n=bbInt(0);
  while((f0.l_node!=this->m__0head)){
    f0.l_node=f0.l_node->m__0succ;
    l_n+=1;
  }
  return l_n;
}

void t_std_collections_List_1Tt_mx2_NamespaceScope_2::m_Clear(){
  this->m__0head->m__0succ=this->m__0head;
  this->m__0head->m__0pred=this->m__0head;
  this->m__0seq+=1;
}

t_std_collections_List_1Tt_mx2_NamespaceScope_2_BackwardsIterator t_std_collections_List_1Tt_mx2_NamespaceScope_2::m_Backwards(){
  return t_std_collections_List_1Tt_mx2_NamespaceScope_2_BackwardsIterator(this,this->m__0head->m__0pred);
}

t_std_collections_List_1Tt_mx2_NamespaceScope_2_Iterator t_std_collections_List_1Tt_mx2_NamespaceScope_2::m_All(){
  return t_std_collections_List_1Tt_mx2_NamespaceScope_2_Iterator(this,this->m__0head->m__0succ);
}

t_std_collections_List_1Tt_mx2_NamespaceScope_2_Node* t_std_collections_List_1Tt_mx2_NamespaceScope_2::m_AddLast(t_mx2_NamespaceScope* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_mx2_NamespaceScope_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=bbGCNew<t_std_collections_List_1Tt_mx2_NamespaceScope_2_Node>(l_value,this->m__0head);
  this->m__0seq+=1;
  return f0.l_node;
}

t_std_collections_List_1Tt_mx2_NamespaceScope_2_Node* t_std_collections_List_1Tt_mx2_NamespaceScope_2::m_AddFirst(t_mx2_NamespaceScope* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_mx2_NamespaceScope_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=bbGCNew<t_std_collections_List_1Tt_mx2_NamespaceScope_2_Node>(l_value,this->m__0head->m__0succ);
  this->m__0seq+=1;
  return f0.l_node;
}

void t_std_collections_List_1Tt_mx2_NamespaceScope_2::m_AddAll(bbArray<bbGCVar<t_mx2_NamespaceScope>>* l_values){
  {
    bbInt l_0=bbInt(0);
    bbInt l_1=l_values->length();
    for(;(l_0<l_1);l_0+=1){
      struct f2_t : public bbGCFrame{
        t_mx2_NamespaceScope* l_value{};
        void gcMark(){
          bbGCMarkPtr(l_value);
        }
      }f2{};
      f2.l_value=l_values->at(l_0);
      this->m_AddLast(f2.l_value);
    }
  }
}

void t_std_collections_List_1Tt_mx2_NamespaceScope_2::m_Add(t_mx2_NamespaceScope* l_value){
  this->m_AddLast(l_value);
}

void t_std_collections_List_1Tt_mx2_PNode_2_Node::gcMark(){
  bbGCMark(m__0succ);
  bbGCMark(m__0pred);
  bbGCMark(m__0value);
}

t_std_collections_List_1Tt_mx2_PNode_2_Node::t_std_collections_List_1Tt_mx2_PNode_2_Node(t_mx2_PNode* l_value,t_std_collections_List_1Tt_mx2_PNode_2_Node* l_succ){
  this->m__0value=l_value;
  this->m__0succ=l_succ;
  this->m__0pred=l_succ->m__0pred;
  this->m__0pred->m__0succ=this;
  l_succ->m__0pred=this;
}

t_std_collections_List_1Tt_mx2_PNode_2_Node::t_std_collections_List_1Tt_mx2_PNode_2_Node(t_mx2_PNode* l_value){
  this->m__0value=l_value;
  this->m__0succ=this;
  this->m__0pred=this;
}

void t_std_collections_List_1Tt_mx2_PNode_2_Node::m_Value(t_mx2_PNode* l_value){
  this->m__0value=l_value;
}

t_mx2_PNode* t_std_collections_List_1Tt_mx2_PNode_2_Node::m_Value(){
  return this->m__0value;
}

t_std_collections_List_1Tt_mx2_PNode_2_Node* t_std_collections_List_1Tt_mx2_PNode_2_Node::m_Succ(){
  return this->m__0succ;
}

void t_std_collections_List_1Tt_mx2_PNode_2_Node::m_Remove(){
  this->m__0succ->m__0pred=this->m__0pred;
  this->m__0pred->m__0succ=this->m__0succ;
}

t_std_collections_List_1Tt_mx2_PNode_2_Node* t_std_collections_List_1Tt_mx2_PNode_2_Node::m_Pred(){
  return this->m__0pred;
}

void t_std_collections_List_1Tt_mx2_PNode_2_Node::m_InsertBefore(t_std_collections_List_1Tt_mx2_PNode_2_Node* l_node){
  this->m__0succ=l_node;
  this->m__0pred=l_node->m__0pred;
  this->m__0pred->m__0succ=this;
  l_node->m__0pred=this;
}

void t_std_collections_List_1Tt_mx2_PNode_2_Node::m_InsertAfter(t_std_collections_List_1Tt_mx2_PNode_2_Node* l_node){
  this->m__0pred=l_node;
  this->m__0succ=l_node->m__0succ;
  this->m__0succ->m__0pred=this;
  l_node->m__0succ=this;
}

t_std_collections_List_1Tt_mx2_PNode_2_Iterator::t_std_collections_List_1Tt_mx2_PNode_2_Iterator(t_std_collections_List_1Tt_mx2_PNode_2* l_list,t_std_collections_List_1Tt_mx2_PNode_2_Node* l_node){
  (*this).m__0list=l_list;
  (*this).m__0node=l_node;
  (*this).m__0seq=l_list->m__0seq;
}

void t_std_collections_List_1Tt_mx2_PNode_2_Iterator::m_Insert(t_mx2_PNode* l_value){
  (*this).m_AssertSeq();
  (*this).m__0node=bbGCNew<t_std_collections_List_1Tt_mx2_PNode_2_Node>(l_value,(*this).m__0node);
  (*this).m__0list->m__0seq+=1;
  (*this).m__0seq=(*this).m__0list->m__0seq;
}

void t_std_collections_List_1Tt_mx2_PNode_2_Iterator::m_Erase(){
  (*this).m_AssertCurrent();
  (*this).m__0node=(*this).m__0node->m__0succ;
  (*this).m__0node->m__0pred->m_Remove();
  (*this).m__0list->m__0seq+=1;
  (*this).m__0seq=(*this).m__0list->m__0seq;
}

void t_std_collections_List_1Tt_mx2_PNode_2_Iterator::m_Current(t_mx2_PNode* l_current){
  (*this).m_AssertCurrent();
  (*this).m__0node->m__0value=l_current;
}

t_mx2_PNode* t_std_collections_List_1Tt_mx2_PNode_2_Iterator::m_Current(){
  (*this).m_AssertCurrent();
  return (*this).m__0node->m__0value;
}

void t_std_collections_List_1Tt_mx2_PNode_2_Iterator::m_Bump(){
  (*this).m_AssertCurrent();
  (*this).m__0node=(*this).m__0node->m__0succ;
}

bbBool t_std_collections_List_1Tt_mx2_PNode_2_Iterator::m_AtEnd(){
  (*this).m_AssertSeq();
  return ((*this).m__0node==(*this).m__0list->m__0head);
}

void t_std_collections_List_1Tt_mx2_PNode_2_Iterator::m_AssertSeq(){
  bbDebugAssert(((*this).m__0seq==(*this).m__0list->m__0seq),BB_T("Concurrent list modification"));
}

void t_std_collections_List_1Tt_mx2_PNode_2_Iterator::m_AssertCurrent(){
  bbDebugAssert(!(*this).m_AtEnd(),BB_T("Invalid list iterator"));
}

int bbCompare(const t_std_collections_List_1Tt_mx2_PNode_2_Iterator&x,const t_std_collections_List_1Tt_mx2_PNode_2_Iterator&y){
  if(int t=bbCompare(x.m__0list,y.m__0list)) return t;
  if(int t=bbCompare(x.m__0node,y.m__0node)) return t;
  if(int t=bbCompare(x.m__0seq,y.m__0seq)) return t;
  return 0;
}

void bbGCMark(const t_std_collections_List_1Tt_mx2_PNode_2_Iterator&t){
  bbGCMark(t.m__0list);
  bbGCMark(t.m__0node);
}

t_std_collections_List_1Tt_mx2_PNode_2_BackwardsIterator::t_std_collections_List_1Tt_mx2_PNode_2_BackwardsIterator(t_std_collections_List_1Tt_mx2_PNode_2* l_list,t_std_collections_List_1Tt_mx2_PNode_2_Node* l_node){
  (*this).m__0list=l_list;
  (*this).m__0node=l_node;
  (*this).m__0seq=l_list->m__0seq;
}

void t_std_collections_List_1Tt_mx2_PNode_2_BackwardsIterator::m_Insert(t_mx2_PNode* l_value){
  (*this).m_AssertSeq();
  (*this).m__0node=bbGCNew<t_std_collections_List_1Tt_mx2_PNode_2_Node>(l_value,(*this).m__0node->m__0succ);
  (*this).m__0list->m__0seq+=1;
  (*this).m__0seq=(*this).m__0list->m__0seq;
}

void t_std_collections_List_1Tt_mx2_PNode_2_BackwardsIterator::m_Erase(){
  (*this).m_AssertCurrent();
  (*this).m__0node=(*this).m__0node->m__0pred;
  (*this).m__0node->m__0succ->m_Remove();
  (*this).m__0list->m__0seq+=1;
  (*this).m__0seq=(*this).m__0list->m__0seq;
}

void t_std_collections_List_1Tt_mx2_PNode_2_BackwardsIterator::m_Current(t_mx2_PNode* l_current){
  (*this).m_AssertCurrent();
  (*this).m__0node->m__0value=l_current;
}

t_mx2_PNode* t_std_collections_List_1Tt_mx2_PNode_2_BackwardsIterator::m_Current(){
  (*this).m_AssertCurrent();
  return (*this).m__0node->m__0value;
}

void t_std_collections_List_1Tt_mx2_PNode_2_BackwardsIterator::m_Bump(){
  (*this).m_AssertCurrent();
  (*this).m__0node=(*this).m__0node->m__0pred;
}

bbBool t_std_collections_List_1Tt_mx2_PNode_2_BackwardsIterator::m_AtEnd(){
  (*this).m_AssertSeq();
  return ((*this).m__0node==(*this).m__0list->m__0head);
}

void t_std_collections_List_1Tt_mx2_PNode_2_BackwardsIterator::m_AssertSeq(){
  bbDebugAssert(((*this).m__0seq==(*this).m__0list->m__0seq),BB_T("Concurrent list modification"));
}

void t_std_collections_List_1Tt_mx2_PNode_2_BackwardsIterator::m_AssertCurrent(){
  bbDebugAssert(!(*this).m_AtEnd(),BB_T("Invalid list iterator"));
}

int bbCompare(const t_std_collections_List_1Tt_mx2_PNode_2_BackwardsIterator&x,const t_std_collections_List_1Tt_mx2_PNode_2_BackwardsIterator&y){
  if(int t=bbCompare(x.m__0list,y.m__0list)) return t;
  if(int t=bbCompare(x.m__0node,y.m__0node)) return t;
  if(int t=bbCompare(x.m__0seq,y.m__0seq)) return t;
  return 0;
}

void bbGCMark(const t_std_collections_List_1Tt_mx2_PNode_2_BackwardsIterator&t){
  bbGCMark(t.m__0list);
  bbGCMark(t.m__0node);
}

void t_std_collections_List_1Tt_mx2_PNode_2::gcMark(){
  bbGCMark(m__0head);
}

t_std_collections_List_1Tt_mx2_PNode_2::t_std_collections_List_1Tt_mx2_PNode_2(t_std_collections_List_1Tt_mx2_PNode_2* l_values):t_std_collections_List_1Tt_mx2_PNode_2(){
  g_std_collections_List_1Tt_mx2_PNode_2_AddAll_1Tt_std_collections_List_1Tt_mx2_PNode_2_2(this,l_values);
}

t_std_collections_List_1Tt_mx2_PNode_2::t_std_collections_List_1Tt_mx2_PNode_2(t_std_collections_Stack_1Tt_mx2_PNode_2* l_values):t_std_collections_List_1Tt_mx2_PNode_2(){
  g_std_collections_List_1Tt_mx2_PNode_2_AddAll_1Tt_std_collections_Stack_1Tt_mx2_PNode_2_2(this,l_values);
}

t_std_collections_List_1Tt_mx2_PNode_2::t_std_collections_List_1Tt_mx2_PNode_2(bbArray<bbGCVar<t_mx2_PNode>>* l_values):t_std_collections_List_1Tt_mx2_PNode_2(){
  this->m_AddAll(l_values);
}

t_std_collections_List_1Tt_mx2_PNode_2::t_std_collections_List_1Tt_mx2_PNode_2(){
  this->m__0head=bbGCNew<t_std_collections_List_1Tt_mx2_PNode_2_Node>(((t_mx2_PNode*)0));
}

bbArray<bbGCVar<t_mx2_PNode>>* t_std_collections_List_1Tt_mx2_PNode_2::m_ToArray(){
  struct f0_t : public bbGCFrame{
    bbArray<bbGCVar<t_mx2_PNode>>* l_data{};
    t_std_collections_List_1Tt_mx2_PNode_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_data);
      bbGCMarkPtr(l_node);
    }
  }f0{};
  bbInt l_n=this->m_Count();
  f0.l_data=bbArray<bbGCVar<t_mx2_PNode>>::create(l_n);
  f0.l_node=this->m__0head->m__0succ;
  {
    bbInt l_i=bbInt(0);
    for(;(l_i<l_n);l_i+=1){
      f0.l_data->at(l_i)=f0.l_node->m__0value;
      f0.l_node=f0.l_node->m__0succ;
    }
  }
  return f0.l_data;
}

void t_std_collections_List_1Tt_mx2_PNode_2::m_Sort(bbFunction<bbInt(t_mx2_PNode*,t_mx2_PNode*)> l_compareFunc){
  bbInt l_insize=1;
  for(;;){
    struct f1_t : public bbGCFrame{
      t_std_collections_List_1Tt_mx2_PNode_2_Node* l_p{};
      t_std_collections_List_1Tt_mx2_PNode_2_Node* l_tail{};
      void gcMark(){
        bbGCMarkPtr(l_p);
        bbGCMarkPtr(l_tail);
      }
    }f1{};
    bbInt l_merges=bbInt(0);
    f1.l_tail=this->m__0head;
    f1.l_p=this->m__0head->m__0succ;
    while((f1.l_p!=this->m__0head)){
      struct f2_t : public bbGCFrame{
        t_std_collections_List_1Tt_mx2_PNode_2_Node* l_q{};
        void gcMark(){
          bbGCMarkPtr(l_q);
        }
      }f2{};
      l_merges+=1;
      f2.l_q=f1.l_p->m__0succ;
      bbInt l_qsize=l_insize;
      bbInt l_psize=1;
      while(((l_psize<l_insize)&&(f2.l_q!=this->m__0head))){
        l_psize+=1;
        f2.l_q=f2.l_q->m__0succ;
      }
      for(;;){
        struct f3_t : public bbGCFrame{
          t_std_collections_List_1Tt_mx2_PNode_2_Node* l_t{};
          void gcMark(){
            bbGCMarkPtr(l_t);
          }
        }f3{};
        if(((bbBool(l_psize)&&bbBool(l_qsize))&&(f2.l_q!=this->m__0head))){
          bbInt l_cc=l_compareFunc(f1.l_p->m__0value,f2.l_q->m__0value);
          if((l_cc<=bbInt(0))){
            f3.l_t=f1.l_p;
            f1.l_p=f1.l_p->m__0succ;
            l_psize-=1;
          }else{
            f3.l_t=f2.l_q;
            f2.l_q=f2.l_q->m__0succ;
            l_qsize-=1;
          }
        }else if(bbBool(l_psize)){
          f3.l_t=f1.l_p;
          f1.l_p=f1.l_p->m__0succ;
          l_psize-=1;
        }else if((bbBool(l_qsize)&&(f2.l_q!=this->m__0head))){
          f3.l_t=f2.l_q;
          f2.l_q=f2.l_q->m__0succ;
          l_qsize-=1;
        }else{
          break;
        }
        f3.l_t->m__0pred=f1.l_tail;
        f1.l_tail->m__0succ=f3.l_t;
        f1.l_tail=f3.l_t;
      }
      f1.l_p=f2.l_q;
    }
    f1.l_tail->m__0succ=this->m__0head;
    this->m__0head->m__0pred=f1.l_tail;
    if((l_merges<=1)){
      return;
    }
    l_insize*=2;
  }
}

void t_std_collections_List_1Tt_mx2_PNode_2::m_Sort(bbBool l_ascending){
  if(l_ascending){
    struct lambda22 : public bbFunction<bbInt(t_mx2_PNode*,t_mx2_PNode*)>::Rep{
      t_std_collections_List_1Tt_mx2_PNode_2* l_self;
      lambda22(t_std_collections_List_1Tt_mx2_PNode_2* l_self):l_self(l_self){
      }
      bbInt invoke(t_mx2_PNode* l_x,t_mx2_PNode* l_y){
        return bbCompare(l_x,l_y);
      }
      void gcMark(){
        bbGCMarkPtr(l_self);
      }
    };
    this->m_Sort(bbFunction<bbInt(t_mx2_PNode*,t_mx2_PNode*)>(new lambda22(this)));
  }else{
    struct lambda23 : public bbFunction<bbInt(t_mx2_PNode*,t_mx2_PNode*)>::Rep{
      t_std_collections_List_1Tt_mx2_PNode_2* l_self;
      lambda23(t_std_collections_List_1Tt_mx2_PNode_2* l_self):l_self(l_self){
      }
      bbInt invoke(t_mx2_PNode* l_x,t_mx2_PNode* l_y){
        return -bbCompare(l_x,l_y);
      }
      void gcMark(){
        bbGCMarkPtr(l_self);
      }
    };
    this->m_Sort(bbFunction<bbInt(t_mx2_PNode*,t_mx2_PNode*)>(new lambda23(this)));
  }
}

t_mx2_PNode* t_std_collections_List_1Tt_mx2_PNode_2::m_RemoveLast(){
  struct f0_t : public bbGCFrame{
    t_mx2_PNode* l_value{};
    void gcMark(){
      bbGCMarkPtr(l_value);
    }
  }f0{};
  bbDebugAssert(!this->m_Empty(),BB_T("Debug assert failed"));
  f0.l_value=this->m__0head->m__0pred->m__0value;
  this->m__0head->m__0pred->m_Remove();
  this->m__0seq+=1;
  return f0.l_value;
}

bbBool t_std_collections_List_1Tt_mx2_PNode_2::m_RemoveLast(t_mx2_PNode* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_mx2_PNode_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m_FindLastNode(l_value);
  if(!bbBool(f0.l_node)){
    return false;
  }
  f0.l_node->m_Remove();
  this->m__0seq+=1;
  return true;
}

t_mx2_PNode* t_std_collections_List_1Tt_mx2_PNode_2::m_RemoveFirst(){
  struct f0_t : public bbGCFrame{
    t_mx2_PNode* l_value{};
    void gcMark(){
      bbGCMarkPtr(l_value);
    }
  }f0{};
  bbDebugAssert(!this->m_Empty(),BB_T("Debug assert failed"));
  f0.l_value=this->m__0head->m__0succ->m__0value;
  this->m__0head->m__0succ->m_Remove();
  this->m__0seq+=1;
  return f0.l_value;
}

bbInt t_std_collections_List_1Tt_mx2_PNode_2::m_RemoveEach(t_mx2_PNode* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_mx2_PNode_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m__0head->m__0succ;
  bbInt l_n=bbInt(0);
  while((f0.l_node!=this->m__0head)){
    if((f0.l_node->m__0value==l_value)){
      f0.l_node=f0.l_node->m__0succ;
      f0.l_node->m__0pred->m_Remove();
      l_n+=1;
    }else{
      f0.l_node=f0.l_node->m__0succ;
    }
  }
  if(bbBool(l_n)){
    this->m__0seq+=1;
  }
  return l_n;
}

bbBool t_std_collections_List_1Tt_mx2_PNode_2::m_Remove(t_mx2_PNode* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_mx2_PNode_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m_FindNode(l_value);
  if(!bbBool(f0.l_node)){
    return false;
  }
  f0.l_node->m_Remove();
  this->m__0seq+=1;
  return true;
}

t_std_collections_List_1Tt_mx2_PNode_2_Node* t_std_collections_List_1Tt_mx2_PNode_2::m_LastNode(){
  if(!this->m_Empty()){
    return this->m__0head->m__0pred;
  }
  return ((t_std_collections_List_1Tt_mx2_PNode_2_Node*)0);
}

t_mx2_PNode* t_std_collections_List_1Tt_mx2_PNode_2::m_Last(){
  bbDebugAssert(!this->m_Empty(),BB_T("Debug assert failed"));
  return this->m__0head->m__0pred->m__0value;
}

t_std_collections_List_1Tt_mx2_PNode_2_Node* t_std_collections_List_1Tt_mx2_PNode_2::m_HeadNode(){
  return this->m__0head;
}

t_std_collections_List_1Tt_mx2_PNode_2_Node* t_std_collections_List_1Tt_mx2_PNode_2::m_FirstNode(){
  if(!this->m_Empty()){
    return this->m__0head->m__0succ;
  }
  return ((t_std_collections_List_1Tt_mx2_PNode_2_Node*)0);
}

t_mx2_PNode* t_std_collections_List_1Tt_mx2_PNode_2::m_First(){
  bbDebugAssert(!this->m_Empty(),BB_T("Debug assert failed"));
  return this->m__0head->m__0succ->m__0value;
}

t_std_collections_List_1Tt_mx2_PNode_2_Node* t_std_collections_List_1Tt_mx2_PNode_2::m_FindNode(t_mx2_PNode* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_mx2_PNode_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m__0head->m__0succ;
  while((f0.l_node!=this->m__0head)){
    if((f0.l_node->m__0value==l_value)){
      return f0.l_node;
    }
    f0.l_node=f0.l_node->m__0succ;
  }
  return ((t_std_collections_List_1Tt_mx2_PNode_2_Node*)0);
}

t_std_collections_List_1Tt_mx2_PNode_2_Node* t_std_collections_List_1Tt_mx2_PNode_2::m_FindLastNode(t_mx2_PNode* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_mx2_PNode_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m__0head->m__0pred;
  while((f0.l_node!=this->m__0head)){
    if((f0.l_node->m__0value==l_value)){
      return f0.l_node;
    }
    f0.l_node=f0.l_node->m__0pred;
  }
  return ((t_std_collections_List_1Tt_mx2_PNode_2_Node*)0);
}

bbBool t_std_collections_List_1Tt_mx2_PNode_2::m_Empty(){
  return (this->m__0head->m__0succ==this->m__0head);
}

bbInt t_std_collections_List_1Tt_mx2_PNode_2::m_Count(){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_mx2_PNode_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m__0head->m__0succ;
  bbInt l_n=bbInt(0);
  while((f0.l_node!=this->m__0head)){
    f0.l_node=f0.l_node->m__0succ;
    l_n+=1;
  }
  return l_n;
}

void t_std_collections_List_1Tt_mx2_PNode_2::m_Clear(){
  this->m__0head->m__0succ=this->m__0head;
  this->m__0head->m__0pred=this->m__0head;
  this->m__0seq+=1;
}

t_std_collections_List_1Tt_mx2_PNode_2_BackwardsIterator t_std_collections_List_1Tt_mx2_PNode_2::m_Backwards(){
  return t_std_collections_List_1Tt_mx2_PNode_2_BackwardsIterator(this,this->m__0head->m__0pred);
}

t_std_collections_List_1Tt_mx2_PNode_2_Iterator t_std_collections_List_1Tt_mx2_PNode_2::m_All(){
  return t_std_collections_List_1Tt_mx2_PNode_2_Iterator(this,this->m__0head->m__0succ);
}

t_std_collections_List_1Tt_mx2_PNode_2_Node* t_std_collections_List_1Tt_mx2_PNode_2::m_AddLast(t_mx2_PNode* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_mx2_PNode_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=bbGCNew<t_std_collections_List_1Tt_mx2_PNode_2_Node>(l_value,this->m__0head);
  this->m__0seq+=1;
  return f0.l_node;
}

t_std_collections_List_1Tt_mx2_PNode_2_Node* t_std_collections_List_1Tt_mx2_PNode_2::m_AddFirst(t_mx2_PNode* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_mx2_PNode_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=bbGCNew<t_std_collections_List_1Tt_mx2_PNode_2_Node>(l_value,this->m__0head->m__0succ);
  this->m__0seq+=1;
  return f0.l_node;
}

void t_std_collections_List_1Tt_mx2_PNode_2::m_AddAll(bbArray<bbGCVar<t_mx2_PNode>>* l_values){
  {
    bbInt l_0=bbInt(0);
    bbInt l_1=l_values->length();
    for(;(l_0<l_1);l_0+=1){
      struct f2_t : public bbGCFrame{
        t_mx2_PNode* l_value{};
        void gcMark(){
          bbGCMarkPtr(l_value);
        }
      }f2{};
      f2.l_value=l_values->at(l_0);
      this->m_AddLast(f2.l_value);
    }
  }
}

void t_std_collections_List_1Tt_mx2_PNode_2::m_Add(t_mx2_PNode* l_value){
  this->m_AddLast(l_value);
}

void t_std_collections_List_1Tt_mx2_AliasType_2_Node::gcMark(){
  bbGCMark(m__0succ);
  bbGCMark(m__0pred);
  bbGCMark(m__0value);
}

t_std_collections_List_1Tt_mx2_AliasType_2_Node::t_std_collections_List_1Tt_mx2_AliasType_2_Node(t_mx2_AliasType* l_value,t_std_collections_List_1Tt_mx2_AliasType_2_Node* l_succ){
  this->m__0value=l_value;
  this->m__0succ=l_succ;
  this->m__0pred=l_succ->m__0pred;
  this->m__0pred->m__0succ=this;
  l_succ->m__0pred=this;
}

t_std_collections_List_1Tt_mx2_AliasType_2_Node::t_std_collections_List_1Tt_mx2_AliasType_2_Node(t_mx2_AliasType* l_value){
  this->m__0value=l_value;
  this->m__0succ=this;
  this->m__0pred=this;
}

void t_std_collections_List_1Tt_mx2_AliasType_2_Node::m_Value(t_mx2_AliasType* l_value){
  this->m__0value=l_value;
}

t_mx2_AliasType* t_std_collections_List_1Tt_mx2_AliasType_2_Node::m_Value(){
  return this->m__0value;
}

t_std_collections_List_1Tt_mx2_AliasType_2_Node* t_std_collections_List_1Tt_mx2_AliasType_2_Node::m_Succ(){
  return this->m__0succ;
}

void t_std_collections_List_1Tt_mx2_AliasType_2_Node::m_Remove(){
  this->m__0succ->m__0pred=this->m__0pred;
  this->m__0pred->m__0succ=this->m__0succ;
}

t_std_collections_List_1Tt_mx2_AliasType_2_Node* t_std_collections_List_1Tt_mx2_AliasType_2_Node::m_Pred(){
  return this->m__0pred;
}

void t_std_collections_List_1Tt_mx2_AliasType_2_Node::m_InsertBefore(t_std_collections_List_1Tt_mx2_AliasType_2_Node* l_node){
  this->m__0succ=l_node;
  this->m__0pred=l_node->m__0pred;
  this->m__0pred->m__0succ=this;
  l_node->m__0pred=this;
}

void t_std_collections_List_1Tt_mx2_AliasType_2_Node::m_InsertAfter(t_std_collections_List_1Tt_mx2_AliasType_2_Node* l_node){
  this->m__0pred=l_node;
  this->m__0succ=l_node->m__0succ;
  this->m__0succ->m__0pred=this;
  l_node->m__0succ=this;
}

t_std_collections_List_1Tt_mx2_AliasType_2_Iterator::t_std_collections_List_1Tt_mx2_AliasType_2_Iterator(t_std_collections_List_1Tt_mx2_AliasType_2* l_list,t_std_collections_List_1Tt_mx2_AliasType_2_Node* l_node){
  (*this).m__0list=l_list;
  (*this).m__0node=l_node;
  (*this).m__0seq=l_list->m__0seq;
}

void t_std_collections_List_1Tt_mx2_AliasType_2_Iterator::m_Insert(t_mx2_AliasType* l_value){
  (*this).m_AssertSeq();
  (*this).m__0node=bbGCNew<t_std_collections_List_1Tt_mx2_AliasType_2_Node>(l_value,(*this).m__0node);
  (*this).m__0list->m__0seq+=1;
  (*this).m__0seq=(*this).m__0list->m__0seq;
}

void t_std_collections_List_1Tt_mx2_AliasType_2_Iterator::m_Erase(){
  (*this).m_AssertCurrent();
  (*this).m__0node=(*this).m__0node->m__0succ;
  (*this).m__0node->m__0pred->m_Remove();
  (*this).m__0list->m__0seq+=1;
  (*this).m__0seq=(*this).m__0list->m__0seq;
}

void t_std_collections_List_1Tt_mx2_AliasType_2_Iterator::m_Current(t_mx2_AliasType* l_current){
  (*this).m_AssertCurrent();
  (*this).m__0node->m__0value=l_current;
}

t_mx2_AliasType* t_std_collections_List_1Tt_mx2_AliasType_2_Iterator::m_Current(){
  (*this).m_AssertCurrent();
  return (*this).m__0node->m__0value;
}

void t_std_collections_List_1Tt_mx2_AliasType_2_Iterator::m_Bump(){
  (*this).m_AssertCurrent();
  (*this).m__0node=(*this).m__0node->m__0succ;
}

bbBool t_std_collections_List_1Tt_mx2_AliasType_2_Iterator::m_AtEnd(){
  (*this).m_AssertSeq();
  return ((*this).m__0node==(*this).m__0list->m__0head);
}

void t_std_collections_List_1Tt_mx2_AliasType_2_Iterator::m_AssertSeq(){
  bbDebugAssert(((*this).m__0seq==(*this).m__0list->m__0seq),BB_T("Concurrent list modification"));
}

void t_std_collections_List_1Tt_mx2_AliasType_2_Iterator::m_AssertCurrent(){
  bbDebugAssert(!(*this).m_AtEnd(),BB_T("Invalid list iterator"));
}

int bbCompare(const t_std_collections_List_1Tt_mx2_AliasType_2_Iterator&x,const t_std_collections_List_1Tt_mx2_AliasType_2_Iterator&y){
  if(int t=bbCompare(x.m__0list,y.m__0list)) return t;
  if(int t=bbCompare(x.m__0node,y.m__0node)) return t;
  if(int t=bbCompare(x.m__0seq,y.m__0seq)) return t;
  return 0;
}

void bbGCMark(const t_std_collections_List_1Tt_mx2_AliasType_2_Iterator&t){
  bbGCMark(t.m__0list);
  bbGCMark(t.m__0node);
}

t_std_collections_List_1Tt_mx2_AliasType_2_BackwardsIterator::t_std_collections_List_1Tt_mx2_AliasType_2_BackwardsIterator(t_std_collections_List_1Tt_mx2_AliasType_2* l_list,t_std_collections_List_1Tt_mx2_AliasType_2_Node* l_node){
  (*this).m__0list=l_list;
  (*this).m__0node=l_node;
  (*this).m__0seq=l_list->m__0seq;
}

void t_std_collections_List_1Tt_mx2_AliasType_2_BackwardsIterator::m_Insert(t_mx2_AliasType* l_value){
  (*this).m_AssertSeq();
  (*this).m__0node=bbGCNew<t_std_collections_List_1Tt_mx2_AliasType_2_Node>(l_value,(*this).m__0node->m__0succ);
  (*this).m__0list->m__0seq+=1;
  (*this).m__0seq=(*this).m__0list->m__0seq;
}

void t_std_collections_List_1Tt_mx2_AliasType_2_BackwardsIterator::m_Erase(){
  (*this).m_AssertCurrent();
  (*this).m__0node=(*this).m__0node->m__0pred;
  (*this).m__0node->m__0succ->m_Remove();
  (*this).m__0list->m__0seq+=1;
  (*this).m__0seq=(*this).m__0list->m__0seq;
}

void t_std_collections_List_1Tt_mx2_AliasType_2_BackwardsIterator::m_Current(t_mx2_AliasType* l_current){
  (*this).m_AssertCurrent();
  (*this).m__0node->m__0value=l_current;
}

t_mx2_AliasType* t_std_collections_List_1Tt_mx2_AliasType_2_BackwardsIterator::m_Current(){
  (*this).m_AssertCurrent();
  return (*this).m__0node->m__0value;
}

void t_std_collections_List_1Tt_mx2_AliasType_2_BackwardsIterator::m_Bump(){
  (*this).m_AssertCurrent();
  (*this).m__0node=(*this).m__0node->m__0pred;
}

bbBool t_std_collections_List_1Tt_mx2_AliasType_2_BackwardsIterator::m_AtEnd(){
  (*this).m_AssertSeq();
  return ((*this).m__0node==(*this).m__0list->m__0head);
}

void t_std_collections_List_1Tt_mx2_AliasType_2_BackwardsIterator::m_AssertSeq(){
  bbDebugAssert(((*this).m__0seq==(*this).m__0list->m__0seq),BB_T("Concurrent list modification"));
}

void t_std_collections_List_1Tt_mx2_AliasType_2_BackwardsIterator::m_AssertCurrent(){
  bbDebugAssert(!(*this).m_AtEnd(),BB_T("Invalid list iterator"));
}

int bbCompare(const t_std_collections_List_1Tt_mx2_AliasType_2_BackwardsIterator&x,const t_std_collections_List_1Tt_mx2_AliasType_2_BackwardsIterator&y){
  if(int t=bbCompare(x.m__0list,y.m__0list)) return t;
  if(int t=bbCompare(x.m__0node,y.m__0node)) return t;
  if(int t=bbCompare(x.m__0seq,y.m__0seq)) return t;
  return 0;
}

void bbGCMark(const t_std_collections_List_1Tt_mx2_AliasType_2_BackwardsIterator&t){
  bbGCMark(t.m__0list);
  bbGCMark(t.m__0node);
}

void t_std_collections_List_1Tt_mx2_AliasType_2::gcMark(){
  bbGCMark(m__0head);
}

t_std_collections_List_1Tt_mx2_AliasType_2::t_std_collections_List_1Tt_mx2_AliasType_2(t_std_collections_List_1Tt_mx2_AliasType_2* l_values):t_std_collections_List_1Tt_mx2_AliasType_2(){
  g_std_collections_List_1Tt_mx2_AliasType_2_AddAll_1Tt_std_collections_List_1Tt_mx2_AliasType_2_2(this,l_values);
}

t_std_collections_List_1Tt_mx2_AliasType_2::t_std_collections_List_1Tt_mx2_AliasType_2(t_std_collections_Stack_1Tt_mx2_AliasType_2* l_values):t_std_collections_List_1Tt_mx2_AliasType_2(){
  g_std_collections_List_1Tt_mx2_AliasType_2_AddAll_1Tt_std_collections_Stack_1Tt_mx2_AliasType_2_2(this,l_values);
}

t_std_collections_List_1Tt_mx2_AliasType_2::t_std_collections_List_1Tt_mx2_AliasType_2(bbArray<bbGCVar<t_mx2_AliasType>>* l_values):t_std_collections_List_1Tt_mx2_AliasType_2(){
  this->m_AddAll(l_values);
}

t_std_collections_List_1Tt_mx2_AliasType_2::t_std_collections_List_1Tt_mx2_AliasType_2(){
  this->m__0head=bbGCNew<t_std_collections_List_1Tt_mx2_AliasType_2_Node>(((t_mx2_AliasType*)0));
}

bbArray<bbGCVar<t_mx2_AliasType>>* t_std_collections_List_1Tt_mx2_AliasType_2::m_ToArray(){
  struct f0_t : public bbGCFrame{
    bbArray<bbGCVar<t_mx2_AliasType>>* l_data{};
    t_std_collections_List_1Tt_mx2_AliasType_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_data);
      bbGCMarkPtr(l_node);
    }
  }f0{};
  bbInt l_n=this->m_Count();
  f0.l_data=bbArray<bbGCVar<t_mx2_AliasType>>::create(l_n);
  f0.l_node=this->m__0head->m__0succ;
  {
    bbInt l_i=bbInt(0);
    for(;(l_i<l_n);l_i+=1){
      f0.l_data->at(l_i)=f0.l_node->m__0value;
      f0.l_node=f0.l_node->m__0succ;
    }
  }
  return f0.l_data;
}

void t_std_collections_List_1Tt_mx2_AliasType_2::m_Sort(bbFunction<bbInt(t_mx2_AliasType*,t_mx2_AliasType*)> l_compareFunc){
  bbInt l_insize=1;
  for(;;){
    struct f1_t : public bbGCFrame{
      t_std_collections_List_1Tt_mx2_AliasType_2_Node* l_p{};
      t_std_collections_List_1Tt_mx2_AliasType_2_Node* l_tail{};
      void gcMark(){
        bbGCMarkPtr(l_p);
        bbGCMarkPtr(l_tail);
      }
    }f1{};
    bbInt l_merges=bbInt(0);
    f1.l_tail=this->m__0head;
    f1.l_p=this->m__0head->m__0succ;
    while((f1.l_p!=this->m__0head)){
      struct f2_t : public bbGCFrame{
        t_std_collections_List_1Tt_mx2_AliasType_2_Node* l_q{};
        void gcMark(){
          bbGCMarkPtr(l_q);
        }
      }f2{};
      l_merges+=1;
      f2.l_q=f1.l_p->m__0succ;
      bbInt l_qsize=l_insize;
      bbInt l_psize=1;
      while(((l_psize<l_insize)&&(f2.l_q!=this->m__0head))){
        l_psize+=1;
        f2.l_q=f2.l_q->m__0succ;
      }
      for(;;){
        struct f3_t : public bbGCFrame{
          t_std_collections_List_1Tt_mx2_AliasType_2_Node* l_t{};
          void gcMark(){
            bbGCMarkPtr(l_t);
          }
        }f3{};
        if(((bbBool(l_psize)&&bbBool(l_qsize))&&(f2.l_q!=this->m__0head))){
          bbInt l_cc=l_compareFunc(f1.l_p->m__0value,f2.l_q->m__0value);
          if((l_cc<=bbInt(0))){
            f3.l_t=f1.l_p;
            f1.l_p=f1.l_p->m__0succ;
            l_psize-=1;
          }else{
            f3.l_t=f2.l_q;
            f2.l_q=f2.l_q->m__0succ;
            l_qsize-=1;
          }
        }else if(bbBool(l_psize)){
          f3.l_t=f1.l_p;
          f1.l_p=f1.l_p->m__0succ;
          l_psize-=1;
        }else if((bbBool(l_qsize)&&(f2.l_q!=this->m__0head))){
          f3.l_t=f2.l_q;
          f2.l_q=f2.l_q->m__0succ;
          l_qsize-=1;
        }else{
          break;
        }
        f3.l_t->m__0pred=f1.l_tail;
        f1.l_tail->m__0succ=f3.l_t;
        f1.l_tail=f3.l_t;
      }
      f1.l_p=f2.l_q;
    }
    f1.l_tail->m__0succ=this->m__0head;
    this->m__0head->m__0pred=f1.l_tail;
    if((l_merges<=1)){
      return;
    }
    l_insize*=2;
  }
}

void t_std_collections_List_1Tt_mx2_AliasType_2::m_Sort(bbBool l_ascending){
  if(l_ascending){
    struct lambda24 : public bbFunction<bbInt(t_mx2_AliasType*,t_mx2_AliasType*)>::Rep{
      t_std_collections_List_1Tt_mx2_AliasType_2* l_self;
      lambda24(t_std_collections_List_1Tt_mx2_AliasType_2* l_self):l_self(l_self){
      }
      bbInt invoke(t_mx2_AliasType* l_x,t_mx2_AliasType* l_y){
        return l_x->m__cmp(((t_mx2_Type*)(l_y)));
      }
      void gcMark(){
        bbGCMarkPtr(l_self);
      }
    };
    this->m_Sort(bbFunction<bbInt(t_mx2_AliasType*,t_mx2_AliasType*)>(new lambda24(this)));
  }else{
    struct lambda25 : public bbFunction<bbInt(t_mx2_AliasType*,t_mx2_AliasType*)>::Rep{
      t_std_collections_List_1Tt_mx2_AliasType_2* l_self;
      lambda25(t_std_collections_List_1Tt_mx2_AliasType_2* l_self):l_self(l_self){
      }
      bbInt invoke(t_mx2_AliasType* l_x,t_mx2_AliasType* l_y){
        return -l_x->m__cmp(((t_mx2_Type*)(l_y)));
      }
      void gcMark(){
        bbGCMarkPtr(l_self);
      }
    };
    this->m_Sort(bbFunction<bbInt(t_mx2_AliasType*,t_mx2_AliasType*)>(new lambda25(this)));
  }
}

t_mx2_AliasType* t_std_collections_List_1Tt_mx2_AliasType_2::m_RemoveLast(){
  struct f0_t : public bbGCFrame{
    t_mx2_AliasType* l_value{};
    void gcMark(){
      bbGCMarkPtr(l_value);
    }
  }f0{};
  bbDebugAssert(!this->m_Empty(),BB_T("Debug assert failed"));
  f0.l_value=this->m__0head->m__0pred->m__0value;
  this->m__0head->m__0pred->m_Remove();
  this->m__0seq+=1;
  return f0.l_value;
}

bbBool t_std_collections_List_1Tt_mx2_AliasType_2::m_RemoveLast(t_mx2_AliasType* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_mx2_AliasType_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m_FindLastNode(l_value);
  if(!bbBool(f0.l_node)){
    return false;
  }
  f0.l_node->m_Remove();
  this->m__0seq+=1;
  return true;
}

t_mx2_AliasType* t_std_collections_List_1Tt_mx2_AliasType_2::m_RemoveFirst(){
  struct f0_t : public bbGCFrame{
    t_mx2_AliasType* l_value{};
    void gcMark(){
      bbGCMarkPtr(l_value);
    }
  }f0{};
  bbDebugAssert(!this->m_Empty(),BB_T("Debug assert failed"));
  f0.l_value=this->m__0head->m__0succ->m__0value;
  this->m__0head->m__0succ->m_Remove();
  this->m__0seq+=1;
  return f0.l_value;
}

bbInt t_std_collections_List_1Tt_mx2_AliasType_2::m_RemoveEach(t_mx2_AliasType* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_mx2_AliasType_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m__0head->m__0succ;
  bbInt l_n=bbInt(0);
  while((f0.l_node!=this->m__0head)){
    if(f0.l_node->m__0value->m__eq(((t_mx2_Type*)(l_value)))){
      f0.l_node=f0.l_node->m__0succ;
      f0.l_node->m__0pred->m_Remove();
      l_n+=1;
    }else{
      f0.l_node=f0.l_node->m__0succ;
    }
  }
  if(bbBool(l_n)){
    this->m__0seq+=1;
  }
  return l_n;
}

bbBool t_std_collections_List_1Tt_mx2_AliasType_2::m_Remove(t_mx2_AliasType* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_mx2_AliasType_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m_FindNode(l_value);
  if(!bbBool(f0.l_node)){
    return false;
  }
  f0.l_node->m_Remove();
  this->m__0seq+=1;
  return true;
}

t_std_collections_List_1Tt_mx2_AliasType_2_Node* t_std_collections_List_1Tt_mx2_AliasType_2::m_LastNode(){
  if(!this->m_Empty()){
    return this->m__0head->m__0pred;
  }
  return ((t_std_collections_List_1Tt_mx2_AliasType_2_Node*)0);
}

t_mx2_AliasType* t_std_collections_List_1Tt_mx2_AliasType_2::m_Last(){
  bbDebugAssert(!this->m_Empty(),BB_T("Debug assert failed"));
  return this->m__0head->m__0pred->m__0value;
}

t_std_collections_List_1Tt_mx2_AliasType_2_Node* t_std_collections_List_1Tt_mx2_AliasType_2::m_HeadNode(){
  return this->m__0head;
}

t_std_collections_List_1Tt_mx2_AliasType_2_Node* t_std_collections_List_1Tt_mx2_AliasType_2::m_FirstNode(){
  if(!this->m_Empty()){
    return this->m__0head->m__0succ;
  }
  return ((t_std_collections_List_1Tt_mx2_AliasType_2_Node*)0);
}

t_mx2_AliasType* t_std_collections_List_1Tt_mx2_AliasType_2::m_First(){
  bbDebugAssert(!this->m_Empty(),BB_T("Debug assert failed"));
  return this->m__0head->m__0succ->m__0value;
}

t_std_collections_List_1Tt_mx2_AliasType_2_Node* t_std_collections_List_1Tt_mx2_AliasType_2::m_FindNode(t_mx2_AliasType* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_mx2_AliasType_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m__0head->m__0succ;
  while((f0.l_node!=this->m__0head)){
    if(f0.l_node->m__0value->m__eq(((t_mx2_Type*)(l_value)))){
      return f0.l_node;
    }
    f0.l_node=f0.l_node->m__0succ;
  }
  return ((t_std_collections_List_1Tt_mx2_AliasType_2_Node*)0);
}

t_std_collections_List_1Tt_mx2_AliasType_2_Node* t_std_collections_List_1Tt_mx2_AliasType_2::m_FindLastNode(t_mx2_AliasType* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_mx2_AliasType_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m__0head->m__0pred;
  while((f0.l_node!=this->m__0head)){
    if(f0.l_node->m__0value->m__eq(((t_mx2_Type*)(l_value)))){
      return f0.l_node;
    }
    f0.l_node=f0.l_node->m__0pred;
  }
  return ((t_std_collections_List_1Tt_mx2_AliasType_2_Node*)0);
}

bbBool t_std_collections_List_1Tt_mx2_AliasType_2::m_Empty(){
  return (this->m__0head->m__0succ==this->m__0head);
}

bbInt t_std_collections_List_1Tt_mx2_AliasType_2::m_Count(){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_mx2_AliasType_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m__0head->m__0succ;
  bbInt l_n=bbInt(0);
  while((f0.l_node!=this->m__0head)){
    f0.l_node=f0.l_node->m__0succ;
    l_n+=1;
  }
  return l_n;
}

void t_std_collections_List_1Tt_mx2_AliasType_2::m_Clear(){
  this->m__0head->m__0succ=this->m__0head;
  this->m__0head->m__0pred=this->m__0head;
  this->m__0seq+=1;
}

t_std_collections_List_1Tt_mx2_AliasType_2_BackwardsIterator t_std_collections_List_1Tt_mx2_AliasType_2::m_Backwards(){
  return t_std_collections_List_1Tt_mx2_AliasType_2_BackwardsIterator(this,this->m__0head->m__0pred);
}

t_std_collections_List_1Tt_mx2_AliasType_2_Iterator t_std_collections_List_1Tt_mx2_AliasType_2::m_All(){
  return t_std_collections_List_1Tt_mx2_AliasType_2_Iterator(this,this->m__0head->m__0succ);
}

t_std_collections_List_1Tt_mx2_AliasType_2_Node* t_std_collections_List_1Tt_mx2_AliasType_2::m_AddLast(t_mx2_AliasType* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_mx2_AliasType_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=bbGCNew<t_std_collections_List_1Tt_mx2_AliasType_2_Node>(l_value,this->m__0head);
  this->m__0seq+=1;
  return f0.l_node;
}

t_std_collections_List_1Tt_mx2_AliasType_2_Node* t_std_collections_List_1Tt_mx2_AliasType_2::m_AddFirst(t_mx2_AliasType* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_mx2_AliasType_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=bbGCNew<t_std_collections_List_1Tt_mx2_AliasType_2_Node>(l_value,this->m__0head->m__0succ);
  this->m__0seq+=1;
  return f0.l_node;
}

void t_std_collections_List_1Tt_mx2_AliasType_2::m_AddAll(bbArray<bbGCVar<t_mx2_AliasType>>* l_values){
  {
    bbInt l_0=bbInt(0);
    bbInt l_1=l_values->length();
    for(;(l_0<l_1);l_0+=1){
      struct f2_t : public bbGCFrame{
        t_mx2_AliasType* l_value{};
        void gcMark(){
          bbGCMarkPtr(l_value);
        }
      }f2{};
      f2.l_value=l_values->at(l_0);
      this->m_AddLast(f2.l_value);
    }
  }
}

void t_std_collections_List_1Tt_mx2_AliasType_2::m_Add(t_mx2_AliasType* l_value){
  this->m_AddLast(l_value);
}

void t_std_collections_List_1Tt_mx2_FuncListType_2_Node::gcMark(){
  bbGCMark(m__0succ);
  bbGCMark(m__0pred);
  bbGCMark(m__0value);
}

t_std_collections_List_1Tt_mx2_FuncListType_2_Node::t_std_collections_List_1Tt_mx2_FuncListType_2_Node(t_mx2_FuncListType* l_value,t_std_collections_List_1Tt_mx2_FuncListType_2_Node* l_succ){
  this->m__0value=l_value;
  this->m__0succ=l_succ;
  this->m__0pred=l_succ->m__0pred;
  this->m__0pred->m__0succ=this;
  l_succ->m__0pred=this;
}

t_std_collections_List_1Tt_mx2_FuncListType_2_Node::t_std_collections_List_1Tt_mx2_FuncListType_2_Node(t_mx2_FuncListType* l_value){
  this->m__0value=l_value;
  this->m__0succ=this;
  this->m__0pred=this;
}

void t_std_collections_List_1Tt_mx2_FuncListType_2_Node::m_Value(t_mx2_FuncListType* l_value){
  this->m__0value=l_value;
}

t_mx2_FuncListType* t_std_collections_List_1Tt_mx2_FuncListType_2_Node::m_Value(){
  return this->m__0value;
}

t_std_collections_List_1Tt_mx2_FuncListType_2_Node* t_std_collections_List_1Tt_mx2_FuncListType_2_Node::m_Succ(){
  return this->m__0succ;
}

void t_std_collections_List_1Tt_mx2_FuncListType_2_Node::m_Remove(){
  this->m__0succ->m__0pred=this->m__0pred;
  this->m__0pred->m__0succ=this->m__0succ;
}

t_std_collections_List_1Tt_mx2_FuncListType_2_Node* t_std_collections_List_1Tt_mx2_FuncListType_2_Node::m_Pred(){
  return this->m__0pred;
}

void t_std_collections_List_1Tt_mx2_FuncListType_2_Node::m_InsertBefore(t_std_collections_List_1Tt_mx2_FuncListType_2_Node* l_node){
  this->m__0succ=l_node;
  this->m__0pred=l_node->m__0pred;
  this->m__0pred->m__0succ=this;
  l_node->m__0pred=this;
}

void t_std_collections_List_1Tt_mx2_FuncListType_2_Node::m_InsertAfter(t_std_collections_List_1Tt_mx2_FuncListType_2_Node* l_node){
  this->m__0pred=l_node;
  this->m__0succ=l_node->m__0succ;
  this->m__0succ->m__0pred=this;
  l_node->m__0succ=this;
}

t_std_collections_List_1Tt_mx2_FuncListType_2_Iterator::t_std_collections_List_1Tt_mx2_FuncListType_2_Iterator(t_std_collections_List_1Tt_mx2_FuncListType_2* l_list,t_std_collections_List_1Tt_mx2_FuncListType_2_Node* l_node){
  (*this).m__0list=l_list;
  (*this).m__0node=l_node;
  (*this).m__0seq=l_list->m__0seq;
}

void t_std_collections_List_1Tt_mx2_FuncListType_2_Iterator::m_Insert(t_mx2_FuncListType* l_value){
  (*this).m_AssertSeq();
  (*this).m__0node=bbGCNew<t_std_collections_List_1Tt_mx2_FuncListType_2_Node>(l_value,(*this).m__0node);
  (*this).m__0list->m__0seq+=1;
  (*this).m__0seq=(*this).m__0list->m__0seq;
}

void t_std_collections_List_1Tt_mx2_FuncListType_2_Iterator::m_Erase(){
  (*this).m_AssertCurrent();
  (*this).m__0node=(*this).m__0node->m__0succ;
  (*this).m__0node->m__0pred->m_Remove();
  (*this).m__0list->m__0seq+=1;
  (*this).m__0seq=(*this).m__0list->m__0seq;
}

void t_std_collections_List_1Tt_mx2_FuncListType_2_Iterator::m_Current(t_mx2_FuncListType* l_current){
  (*this).m_AssertCurrent();
  (*this).m__0node->m__0value=l_current;
}

t_mx2_FuncListType* t_std_collections_List_1Tt_mx2_FuncListType_2_Iterator::m_Current(){
  (*this).m_AssertCurrent();
  return (*this).m__0node->m__0value;
}

void t_std_collections_List_1Tt_mx2_FuncListType_2_Iterator::m_Bump(){
  (*this).m_AssertCurrent();
  (*this).m__0node=(*this).m__0node->m__0succ;
}

bbBool t_std_collections_List_1Tt_mx2_FuncListType_2_Iterator::m_AtEnd(){
  (*this).m_AssertSeq();
  return ((*this).m__0node==(*this).m__0list->m__0head);
}

void t_std_collections_List_1Tt_mx2_FuncListType_2_Iterator::m_AssertSeq(){
  bbDebugAssert(((*this).m__0seq==(*this).m__0list->m__0seq),BB_T("Concurrent list modification"));
}

void t_std_collections_List_1Tt_mx2_FuncListType_2_Iterator::m_AssertCurrent(){
  bbDebugAssert(!(*this).m_AtEnd(),BB_T("Invalid list iterator"));
}

int bbCompare(const t_std_collections_List_1Tt_mx2_FuncListType_2_Iterator&x,const t_std_collections_List_1Tt_mx2_FuncListType_2_Iterator&y){
  if(int t=bbCompare(x.m__0list,y.m__0list)) return t;
  if(int t=bbCompare(x.m__0node,y.m__0node)) return t;
  if(int t=bbCompare(x.m__0seq,y.m__0seq)) return t;
  return 0;
}

void bbGCMark(const t_std_collections_List_1Tt_mx2_FuncListType_2_Iterator&t){
  bbGCMark(t.m__0list);
  bbGCMark(t.m__0node);
}

t_std_collections_List_1Tt_mx2_FuncListType_2_BackwardsIterator::t_std_collections_List_1Tt_mx2_FuncListType_2_BackwardsIterator(t_std_collections_List_1Tt_mx2_FuncListType_2* l_list,t_std_collections_List_1Tt_mx2_FuncListType_2_Node* l_node){
  (*this).m__0list=l_list;
  (*this).m__0node=l_node;
  (*this).m__0seq=l_list->m__0seq;
}

void t_std_collections_List_1Tt_mx2_FuncListType_2_BackwardsIterator::m_Insert(t_mx2_FuncListType* l_value){
  (*this).m_AssertSeq();
  (*this).m__0node=bbGCNew<t_std_collections_List_1Tt_mx2_FuncListType_2_Node>(l_value,(*this).m__0node->m__0succ);
  (*this).m__0list->m__0seq+=1;
  (*this).m__0seq=(*this).m__0list->m__0seq;
}

void t_std_collections_List_1Tt_mx2_FuncListType_2_BackwardsIterator::m_Erase(){
  (*this).m_AssertCurrent();
  (*this).m__0node=(*this).m__0node->m__0pred;
  (*this).m__0node->m__0succ->m_Remove();
  (*this).m__0list->m__0seq+=1;
  (*this).m__0seq=(*this).m__0list->m__0seq;
}

void t_std_collections_List_1Tt_mx2_FuncListType_2_BackwardsIterator::m_Current(t_mx2_FuncListType* l_current){
  (*this).m_AssertCurrent();
  (*this).m__0node->m__0value=l_current;
}

t_mx2_FuncListType* t_std_collections_List_1Tt_mx2_FuncListType_2_BackwardsIterator::m_Current(){
  (*this).m_AssertCurrent();
  return (*this).m__0node->m__0value;
}

void t_std_collections_List_1Tt_mx2_FuncListType_2_BackwardsIterator::m_Bump(){
  (*this).m_AssertCurrent();
  (*this).m__0node=(*this).m__0node->m__0pred;
}

bbBool t_std_collections_List_1Tt_mx2_FuncListType_2_BackwardsIterator::m_AtEnd(){
  (*this).m_AssertSeq();
  return ((*this).m__0node==(*this).m__0list->m__0head);
}

void t_std_collections_List_1Tt_mx2_FuncListType_2_BackwardsIterator::m_AssertSeq(){
  bbDebugAssert(((*this).m__0seq==(*this).m__0list->m__0seq),BB_T("Concurrent list modification"));
}

void t_std_collections_List_1Tt_mx2_FuncListType_2_BackwardsIterator::m_AssertCurrent(){
  bbDebugAssert(!(*this).m_AtEnd(),BB_T("Invalid list iterator"));
}

int bbCompare(const t_std_collections_List_1Tt_mx2_FuncListType_2_BackwardsIterator&x,const t_std_collections_List_1Tt_mx2_FuncListType_2_BackwardsIterator&y){
  if(int t=bbCompare(x.m__0list,y.m__0list)) return t;
  if(int t=bbCompare(x.m__0node,y.m__0node)) return t;
  if(int t=bbCompare(x.m__0seq,y.m__0seq)) return t;
  return 0;
}

void bbGCMark(const t_std_collections_List_1Tt_mx2_FuncListType_2_BackwardsIterator&t){
  bbGCMark(t.m__0list);
  bbGCMark(t.m__0node);
}

void t_std_collections_List_1Tt_mx2_FuncListType_2::gcMark(){
  bbGCMark(m__0head);
}

t_std_collections_List_1Tt_mx2_FuncListType_2::t_std_collections_List_1Tt_mx2_FuncListType_2(t_std_collections_List_1Tt_mx2_FuncListType_2* l_values):t_std_collections_List_1Tt_mx2_FuncListType_2(){
  g_std_collections_List_1Tt_mx2_FuncListType_2_AddAll_1Tt_std_collections_List_1Tt_mx2_FuncListType_2_2(this,l_values);
}

t_std_collections_List_1Tt_mx2_FuncListType_2::t_std_collections_List_1Tt_mx2_FuncListType_2(t_std_collections_Stack_1Tt_mx2_FuncListType_2* l_values):t_std_collections_List_1Tt_mx2_FuncListType_2(){
  g_std_collections_List_1Tt_mx2_FuncListType_2_AddAll_1Tt_std_collections_Stack_1Tt_mx2_FuncListType_2_2(this,l_values);
}

t_std_collections_List_1Tt_mx2_FuncListType_2::t_std_collections_List_1Tt_mx2_FuncListType_2(bbArray<bbGCVar<t_mx2_FuncListType>>* l_values):t_std_collections_List_1Tt_mx2_FuncListType_2(){
  this->m_AddAll(l_values);
}

t_std_collections_List_1Tt_mx2_FuncListType_2::t_std_collections_List_1Tt_mx2_FuncListType_2(){
  this->m__0head=bbGCNew<t_std_collections_List_1Tt_mx2_FuncListType_2_Node>(((t_mx2_FuncListType*)0));
}

bbArray<bbGCVar<t_mx2_FuncListType>>* t_std_collections_List_1Tt_mx2_FuncListType_2::m_ToArray(){
  struct f0_t : public bbGCFrame{
    bbArray<bbGCVar<t_mx2_FuncListType>>* l_data{};
    t_std_collections_List_1Tt_mx2_FuncListType_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_data);
      bbGCMarkPtr(l_node);
    }
  }f0{};
  bbInt l_n=this->m_Count();
  f0.l_data=bbArray<bbGCVar<t_mx2_FuncListType>>::create(l_n);
  f0.l_node=this->m__0head->m__0succ;
  {
    bbInt l_i=bbInt(0);
    for(;(l_i<l_n);l_i+=1){
      f0.l_data->at(l_i)=f0.l_node->m__0value;
      f0.l_node=f0.l_node->m__0succ;
    }
  }
  return f0.l_data;
}

void t_std_collections_List_1Tt_mx2_FuncListType_2::m_Sort(bbFunction<bbInt(t_mx2_FuncListType*,t_mx2_FuncListType*)> l_compareFunc){
  bbInt l_insize=1;
  for(;;){
    struct f1_t : public bbGCFrame{
      t_std_collections_List_1Tt_mx2_FuncListType_2_Node* l_p{};
      t_std_collections_List_1Tt_mx2_FuncListType_2_Node* l_tail{};
      void gcMark(){
        bbGCMarkPtr(l_p);
        bbGCMarkPtr(l_tail);
      }
    }f1{};
    bbInt l_merges=bbInt(0);
    f1.l_tail=this->m__0head;
    f1.l_p=this->m__0head->m__0succ;
    while((f1.l_p!=this->m__0head)){
      struct f2_t : public bbGCFrame{
        t_std_collections_List_1Tt_mx2_FuncListType_2_Node* l_q{};
        void gcMark(){
          bbGCMarkPtr(l_q);
        }
      }f2{};
      l_merges+=1;
      f2.l_q=f1.l_p->m__0succ;
      bbInt l_qsize=l_insize;
      bbInt l_psize=1;
      while(((l_psize<l_insize)&&(f2.l_q!=this->m__0head))){
        l_psize+=1;
        f2.l_q=f2.l_q->m__0succ;
      }
      for(;;){
        struct f3_t : public bbGCFrame{
          t_std_collections_List_1Tt_mx2_FuncListType_2_Node* l_t{};
          void gcMark(){
            bbGCMarkPtr(l_t);
          }
        }f3{};
        if(((bbBool(l_psize)&&bbBool(l_qsize))&&(f2.l_q!=this->m__0head))){
          bbInt l_cc=l_compareFunc(f1.l_p->m__0value,f2.l_q->m__0value);
          if((l_cc<=bbInt(0))){
            f3.l_t=f1.l_p;
            f1.l_p=f1.l_p->m__0succ;
            l_psize-=1;
          }else{
            f3.l_t=f2.l_q;
            f2.l_q=f2.l_q->m__0succ;
            l_qsize-=1;
          }
        }else if(bbBool(l_psize)){
          f3.l_t=f1.l_p;
          f1.l_p=f1.l_p->m__0succ;
          l_psize-=1;
        }else if((bbBool(l_qsize)&&(f2.l_q!=this->m__0head))){
          f3.l_t=f2.l_q;
          f2.l_q=f2.l_q->m__0succ;
          l_qsize-=1;
        }else{
          break;
        }
        f3.l_t->m__0pred=f1.l_tail;
        f1.l_tail->m__0succ=f3.l_t;
        f1.l_tail=f3.l_t;
      }
      f1.l_p=f2.l_q;
    }
    f1.l_tail->m__0succ=this->m__0head;
    this->m__0head->m__0pred=f1.l_tail;
    if((l_merges<=1)){
      return;
    }
    l_insize*=2;
  }
}

void t_std_collections_List_1Tt_mx2_FuncListType_2::m_Sort(bbBool l_ascending){
  if(l_ascending){
    struct lambda26 : public bbFunction<bbInt(t_mx2_FuncListType*,t_mx2_FuncListType*)>::Rep{
      t_std_collections_List_1Tt_mx2_FuncListType_2* l_self;
      lambda26(t_std_collections_List_1Tt_mx2_FuncListType_2* l_self):l_self(l_self){
      }
      bbInt invoke(t_mx2_FuncListType* l_x,t_mx2_FuncListType* l_y){
        return l_x->m__cmp(((t_mx2_Type*)(l_y)));
      }
      void gcMark(){
        bbGCMarkPtr(l_self);
      }
    };
    this->m_Sort(bbFunction<bbInt(t_mx2_FuncListType*,t_mx2_FuncListType*)>(new lambda26(this)));
  }else{
    struct lambda27 : public bbFunction<bbInt(t_mx2_FuncListType*,t_mx2_FuncListType*)>::Rep{
      t_std_collections_List_1Tt_mx2_FuncListType_2* l_self;
      lambda27(t_std_collections_List_1Tt_mx2_FuncListType_2* l_self):l_self(l_self){
      }
      bbInt invoke(t_mx2_FuncListType* l_x,t_mx2_FuncListType* l_y){
        return -l_x->m__cmp(((t_mx2_Type*)(l_y)));
      }
      void gcMark(){
        bbGCMarkPtr(l_self);
      }
    };
    this->m_Sort(bbFunction<bbInt(t_mx2_FuncListType*,t_mx2_FuncListType*)>(new lambda27(this)));
  }
}

t_mx2_FuncListType* t_std_collections_List_1Tt_mx2_FuncListType_2::m_RemoveLast(){
  struct f0_t : public bbGCFrame{
    t_mx2_FuncListType* l_value{};
    void gcMark(){
      bbGCMarkPtr(l_value);
    }
  }f0{};
  bbDebugAssert(!this->m_Empty(),BB_T("Debug assert failed"));
  f0.l_value=this->m__0head->m__0pred->m__0value;
  this->m__0head->m__0pred->m_Remove();
  this->m__0seq+=1;
  return f0.l_value;
}

bbBool t_std_collections_List_1Tt_mx2_FuncListType_2::m_RemoveLast(t_mx2_FuncListType* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_mx2_FuncListType_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m_FindLastNode(l_value);
  if(!bbBool(f0.l_node)){
    return false;
  }
  f0.l_node->m_Remove();
  this->m__0seq+=1;
  return true;
}

t_mx2_FuncListType* t_std_collections_List_1Tt_mx2_FuncListType_2::m_RemoveFirst(){
  struct f0_t : public bbGCFrame{
    t_mx2_FuncListType* l_value{};
    void gcMark(){
      bbGCMarkPtr(l_value);
    }
  }f0{};
  bbDebugAssert(!this->m_Empty(),BB_T("Debug assert failed"));
  f0.l_value=this->m__0head->m__0succ->m__0value;
  this->m__0head->m__0succ->m_Remove();
  this->m__0seq+=1;
  return f0.l_value;
}

bbInt t_std_collections_List_1Tt_mx2_FuncListType_2::m_RemoveEach(t_mx2_FuncListType* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_mx2_FuncListType_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m__0head->m__0succ;
  bbInt l_n=bbInt(0);
  while((f0.l_node!=this->m__0head)){
    if(f0.l_node->m__0value->m__eq(((t_mx2_Type*)(l_value)))){
      f0.l_node=f0.l_node->m__0succ;
      f0.l_node->m__0pred->m_Remove();
      l_n+=1;
    }else{
      f0.l_node=f0.l_node->m__0succ;
    }
  }
  if(bbBool(l_n)){
    this->m__0seq+=1;
  }
  return l_n;
}

bbBool t_std_collections_List_1Tt_mx2_FuncListType_2::m_Remove(t_mx2_FuncListType* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_mx2_FuncListType_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m_FindNode(l_value);
  if(!bbBool(f0.l_node)){
    return false;
  }
  f0.l_node->m_Remove();
  this->m__0seq+=1;
  return true;
}

t_std_collections_List_1Tt_mx2_FuncListType_2_Node* t_std_collections_List_1Tt_mx2_FuncListType_2::m_LastNode(){
  if(!this->m_Empty()){
    return this->m__0head->m__0pred;
  }
  return ((t_std_collections_List_1Tt_mx2_FuncListType_2_Node*)0);
}

t_mx2_FuncListType* t_std_collections_List_1Tt_mx2_FuncListType_2::m_Last(){
  bbDebugAssert(!this->m_Empty(),BB_T("Debug assert failed"));
  return this->m__0head->m__0pred->m__0value;
}

t_std_collections_List_1Tt_mx2_FuncListType_2_Node* t_std_collections_List_1Tt_mx2_FuncListType_2::m_HeadNode(){
  return this->m__0head;
}

t_std_collections_List_1Tt_mx2_FuncListType_2_Node* t_std_collections_List_1Tt_mx2_FuncListType_2::m_FirstNode(){
  if(!this->m_Empty()){
    return this->m__0head->m__0succ;
  }
  return ((t_std_collections_List_1Tt_mx2_FuncListType_2_Node*)0);
}

t_mx2_FuncListType* t_std_collections_List_1Tt_mx2_FuncListType_2::m_First(){
  bbDebugAssert(!this->m_Empty(),BB_T("Debug assert failed"));
  return this->m__0head->m__0succ->m__0value;
}

t_std_collections_List_1Tt_mx2_FuncListType_2_Node* t_std_collections_List_1Tt_mx2_FuncListType_2::m_FindNode(t_mx2_FuncListType* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_mx2_FuncListType_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m__0head->m__0succ;
  while((f0.l_node!=this->m__0head)){
    if(f0.l_node->m__0value->m__eq(((t_mx2_Type*)(l_value)))){
      return f0.l_node;
    }
    f0.l_node=f0.l_node->m__0succ;
  }
  return ((t_std_collections_List_1Tt_mx2_FuncListType_2_Node*)0);
}

t_std_collections_List_1Tt_mx2_FuncListType_2_Node* t_std_collections_List_1Tt_mx2_FuncListType_2::m_FindLastNode(t_mx2_FuncListType* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_mx2_FuncListType_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m__0head->m__0pred;
  while((f0.l_node!=this->m__0head)){
    if(f0.l_node->m__0value->m__eq(((t_mx2_Type*)(l_value)))){
      return f0.l_node;
    }
    f0.l_node=f0.l_node->m__0pred;
  }
  return ((t_std_collections_List_1Tt_mx2_FuncListType_2_Node*)0);
}

bbBool t_std_collections_List_1Tt_mx2_FuncListType_2::m_Empty(){
  return (this->m__0head->m__0succ==this->m__0head);
}

bbInt t_std_collections_List_1Tt_mx2_FuncListType_2::m_Count(){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_mx2_FuncListType_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m__0head->m__0succ;
  bbInt l_n=bbInt(0);
  while((f0.l_node!=this->m__0head)){
    f0.l_node=f0.l_node->m__0succ;
    l_n+=1;
  }
  return l_n;
}

void t_std_collections_List_1Tt_mx2_FuncListType_2::m_Clear(){
  this->m__0head->m__0succ=this->m__0head;
  this->m__0head->m__0pred=this->m__0head;
  this->m__0seq+=1;
}

t_std_collections_List_1Tt_mx2_FuncListType_2_BackwardsIterator t_std_collections_List_1Tt_mx2_FuncListType_2::m_Backwards(){
  return t_std_collections_List_1Tt_mx2_FuncListType_2_BackwardsIterator(this,this->m__0head->m__0pred);
}

t_std_collections_List_1Tt_mx2_FuncListType_2_Iterator t_std_collections_List_1Tt_mx2_FuncListType_2::m_All(){
  return t_std_collections_List_1Tt_mx2_FuncListType_2_Iterator(this,this->m__0head->m__0succ);
}

t_std_collections_List_1Tt_mx2_FuncListType_2_Node* t_std_collections_List_1Tt_mx2_FuncListType_2::m_AddLast(t_mx2_FuncListType* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_mx2_FuncListType_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=bbGCNew<t_std_collections_List_1Tt_mx2_FuncListType_2_Node>(l_value,this->m__0head);
  this->m__0seq+=1;
  return f0.l_node;
}

t_std_collections_List_1Tt_mx2_FuncListType_2_Node* t_std_collections_List_1Tt_mx2_FuncListType_2::m_AddFirst(t_mx2_FuncListType* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_mx2_FuncListType_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=bbGCNew<t_std_collections_List_1Tt_mx2_FuncListType_2_Node>(l_value,this->m__0head->m__0succ);
  this->m__0seq+=1;
  return f0.l_node;
}

void t_std_collections_List_1Tt_mx2_FuncListType_2::m_AddAll(bbArray<bbGCVar<t_mx2_FuncListType>>* l_values){
  {
    bbInt l_0=bbInt(0);
    bbInt l_1=l_values->length();
    for(;(l_0<l_1);l_0+=1){
      struct f2_t : public bbGCFrame{
        t_mx2_FuncListType* l_value{};
        void gcMark(){
          bbGCMarkPtr(l_value);
        }
      }f2{};
      f2.l_value=l_values->at(l_0);
      this->m_AddLast(f2.l_value);
    }
  }
}

void t_std_collections_List_1Tt_mx2_FuncListType_2::m_Add(t_mx2_FuncListType* l_value){
  this->m_AddLast(l_value);
}

void t_std_collections_List_1Tt_mx2_Decl_2_Node::gcMark(){
  bbGCMark(m__0succ);
  bbGCMark(m__0pred);
  bbGCMark(m__0value);
}

t_std_collections_List_1Tt_mx2_Decl_2_Node::t_std_collections_List_1Tt_mx2_Decl_2_Node(t_mx2_Decl* l_value,t_std_collections_List_1Tt_mx2_Decl_2_Node* l_succ){
  this->m__0value=l_value;
  this->m__0succ=l_succ;
  this->m__0pred=l_succ->m__0pred;
  this->m__0pred->m__0succ=this;
  l_succ->m__0pred=this;
}

t_std_collections_List_1Tt_mx2_Decl_2_Node::t_std_collections_List_1Tt_mx2_Decl_2_Node(t_mx2_Decl* l_value){
  this->m__0value=l_value;
  this->m__0succ=this;
  this->m__0pred=this;
}

void t_std_collections_List_1Tt_mx2_Decl_2_Node::m_Value(t_mx2_Decl* l_value){
  this->m__0value=l_value;
}

t_mx2_Decl* t_std_collections_List_1Tt_mx2_Decl_2_Node::m_Value(){
  return this->m__0value;
}

t_std_collections_List_1Tt_mx2_Decl_2_Node* t_std_collections_List_1Tt_mx2_Decl_2_Node::m_Succ(){
  return this->m__0succ;
}

void t_std_collections_List_1Tt_mx2_Decl_2_Node::m_Remove(){
  this->m__0succ->m__0pred=this->m__0pred;
  this->m__0pred->m__0succ=this->m__0succ;
}

t_std_collections_List_1Tt_mx2_Decl_2_Node* t_std_collections_List_1Tt_mx2_Decl_2_Node::m_Pred(){
  return this->m__0pred;
}

void t_std_collections_List_1Tt_mx2_Decl_2_Node::m_InsertBefore(t_std_collections_List_1Tt_mx2_Decl_2_Node* l_node){
  this->m__0succ=l_node;
  this->m__0pred=l_node->m__0pred;
  this->m__0pred->m__0succ=this;
  l_node->m__0pred=this;
}

void t_std_collections_List_1Tt_mx2_Decl_2_Node::m_InsertAfter(t_std_collections_List_1Tt_mx2_Decl_2_Node* l_node){
  this->m__0pred=l_node;
  this->m__0succ=l_node->m__0succ;
  this->m__0succ->m__0pred=this;
  l_node->m__0succ=this;
}

t_std_collections_List_1Tt_mx2_Decl_2_Iterator::t_std_collections_List_1Tt_mx2_Decl_2_Iterator(t_std_collections_List_1Tt_mx2_Decl_2* l_list,t_std_collections_List_1Tt_mx2_Decl_2_Node* l_node){
  (*this).m__0list=l_list;
  (*this).m__0node=l_node;
  (*this).m__0seq=l_list->m__0seq;
}

void t_std_collections_List_1Tt_mx2_Decl_2_Iterator::m_Insert(t_mx2_Decl* l_value){
  (*this).m_AssertSeq();
  (*this).m__0node=bbGCNew<t_std_collections_List_1Tt_mx2_Decl_2_Node>(l_value,(*this).m__0node);
  (*this).m__0list->m__0seq+=1;
  (*this).m__0seq=(*this).m__0list->m__0seq;
}

void t_std_collections_List_1Tt_mx2_Decl_2_Iterator::m_Erase(){
  (*this).m_AssertCurrent();
  (*this).m__0node=(*this).m__0node->m__0succ;
  (*this).m__0node->m__0pred->m_Remove();
  (*this).m__0list->m__0seq+=1;
  (*this).m__0seq=(*this).m__0list->m__0seq;
}

void t_std_collections_List_1Tt_mx2_Decl_2_Iterator::m_Current(t_mx2_Decl* l_current){
  (*this).m_AssertCurrent();
  (*this).m__0node->m__0value=l_current;
}

t_mx2_Decl* t_std_collections_List_1Tt_mx2_Decl_2_Iterator::m_Current(){
  (*this).m_AssertCurrent();
  return (*this).m__0node->m__0value;
}

void t_std_collections_List_1Tt_mx2_Decl_2_Iterator::m_Bump(){
  (*this).m_AssertCurrent();
  (*this).m__0node=(*this).m__0node->m__0succ;
}

bbBool t_std_collections_List_1Tt_mx2_Decl_2_Iterator::m_AtEnd(){
  (*this).m_AssertSeq();
  return ((*this).m__0node==(*this).m__0list->m__0head);
}

void t_std_collections_List_1Tt_mx2_Decl_2_Iterator::m_AssertSeq(){
  bbDebugAssert(((*this).m__0seq==(*this).m__0list->m__0seq),BB_T("Concurrent list modification"));
}

void t_std_collections_List_1Tt_mx2_Decl_2_Iterator::m_AssertCurrent(){
  bbDebugAssert(!(*this).m_AtEnd(),BB_T("Invalid list iterator"));
}

int bbCompare(const t_std_collections_List_1Tt_mx2_Decl_2_Iterator&x,const t_std_collections_List_1Tt_mx2_Decl_2_Iterator&y){
  if(int t=bbCompare(x.m__0list,y.m__0list)) return t;
  if(int t=bbCompare(x.m__0node,y.m__0node)) return t;
  if(int t=bbCompare(x.m__0seq,y.m__0seq)) return t;
  return 0;
}

void bbGCMark(const t_std_collections_List_1Tt_mx2_Decl_2_Iterator&t){
  bbGCMark(t.m__0list);
  bbGCMark(t.m__0node);
}

t_std_collections_List_1Tt_mx2_Decl_2_BackwardsIterator::t_std_collections_List_1Tt_mx2_Decl_2_BackwardsIterator(t_std_collections_List_1Tt_mx2_Decl_2* l_list,t_std_collections_List_1Tt_mx2_Decl_2_Node* l_node){
  (*this).m__0list=l_list;
  (*this).m__0node=l_node;
  (*this).m__0seq=l_list->m__0seq;
}

void t_std_collections_List_1Tt_mx2_Decl_2_BackwardsIterator::m_Insert(t_mx2_Decl* l_value){
  (*this).m_AssertSeq();
  (*this).m__0node=bbGCNew<t_std_collections_List_1Tt_mx2_Decl_2_Node>(l_value,(*this).m__0node->m__0succ);
  (*this).m__0list->m__0seq+=1;
  (*this).m__0seq=(*this).m__0list->m__0seq;
}

void t_std_collections_List_1Tt_mx2_Decl_2_BackwardsIterator::m_Erase(){
  (*this).m_AssertCurrent();
  (*this).m__0node=(*this).m__0node->m__0pred;
  (*this).m__0node->m__0succ->m_Remove();
  (*this).m__0list->m__0seq+=1;
  (*this).m__0seq=(*this).m__0list->m__0seq;
}

void t_std_collections_List_1Tt_mx2_Decl_2_BackwardsIterator::m_Current(t_mx2_Decl* l_current){
  (*this).m_AssertCurrent();
  (*this).m__0node->m__0value=l_current;
}

t_mx2_Decl* t_std_collections_List_1Tt_mx2_Decl_2_BackwardsIterator::m_Current(){
  (*this).m_AssertCurrent();
  return (*this).m__0node->m__0value;
}

void t_std_collections_List_1Tt_mx2_Decl_2_BackwardsIterator::m_Bump(){
  (*this).m_AssertCurrent();
  (*this).m__0node=(*this).m__0node->m__0pred;
}

bbBool t_std_collections_List_1Tt_mx2_Decl_2_BackwardsIterator::m_AtEnd(){
  (*this).m_AssertSeq();
  return ((*this).m__0node==(*this).m__0list->m__0head);
}

void t_std_collections_List_1Tt_mx2_Decl_2_BackwardsIterator::m_AssertSeq(){
  bbDebugAssert(((*this).m__0seq==(*this).m__0list->m__0seq),BB_T("Concurrent list modification"));
}

void t_std_collections_List_1Tt_mx2_Decl_2_BackwardsIterator::m_AssertCurrent(){
  bbDebugAssert(!(*this).m_AtEnd(),BB_T("Invalid list iterator"));
}

int bbCompare(const t_std_collections_List_1Tt_mx2_Decl_2_BackwardsIterator&x,const t_std_collections_List_1Tt_mx2_Decl_2_BackwardsIterator&y){
  if(int t=bbCompare(x.m__0list,y.m__0list)) return t;
  if(int t=bbCompare(x.m__0node,y.m__0node)) return t;
  if(int t=bbCompare(x.m__0seq,y.m__0seq)) return t;
  return 0;
}

void bbGCMark(const t_std_collections_List_1Tt_mx2_Decl_2_BackwardsIterator&t){
  bbGCMark(t.m__0list);
  bbGCMark(t.m__0node);
}

void t_std_collections_List_1Tt_mx2_Decl_2::gcMark(){
  bbGCMark(m__0head);
}

t_std_collections_List_1Tt_mx2_Decl_2::t_std_collections_List_1Tt_mx2_Decl_2(t_std_collections_List_1Tt_mx2_Decl_2* l_values):t_std_collections_List_1Tt_mx2_Decl_2(){
  g_std_collections_List_1Tt_mx2_Decl_2_AddAll_1Tt_std_collections_List_1Tt_mx2_Decl_2_2(this,l_values);
}

t_std_collections_List_1Tt_mx2_Decl_2::t_std_collections_List_1Tt_mx2_Decl_2(t_std_collections_Stack_1Tt_mx2_Decl_2* l_values):t_std_collections_List_1Tt_mx2_Decl_2(){
  g_std_collections_List_1Tt_mx2_Decl_2_AddAll_1Tt_std_collections_Stack_1Tt_mx2_Decl_2_2(this,l_values);
}

t_std_collections_List_1Tt_mx2_Decl_2::t_std_collections_List_1Tt_mx2_Decl_2(bbArray<bbGCVar<t_mx2_Decl>>* l_values):t_std_collections_List_1Tt_mx2_Decl_2(){
  this->m_AddAll(l_values);
}

t_std_collections_List_1Tt_mx2_Decl_2::t_std_collections_List_1Tt_mx2_Decl_2(){
  this->m__0head=bbGCNew<t_std_collections_List_1Tt_mx2_Decl_2_Node>(((t_mx2_Decl*)0));
}

bbArray<bbGCVar<t_mx2_Decl>>* t_std_collections_List_1Tt_mx2_Decl_2::m_ToArray(){
  struct f0_t : public bbGCFrame{
    bbArray<bbGCVar<t_mx2_Decl>>* l_data{};
    t_std_collections_List_1Tt_mx2_Decl_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_data);
      bbGCMarkPtr(l_node);
    }
  }f0{};
  bbInt l_n=this->m_Count();
  f0.l_data=bbArray<bbGCVar<t_mx2_Decl>>::create(l_n);
  f0.l_node=this->m__0head->m__0succ;
  {
    bbInt l_i=bbInt(0);
    for(;(l_i<l_n);l_i+=1){
      f0.l_data->at(l_i)=f0.l_node->m__0value;
      f0.l_node=f0.l_node->m__0succ;
    }
  }
  return f0.l_data;
}

void t_std_collections_List_1Tt_mx2_Decl_2::m_Sort(bbFunction<bbInt(t_mx2_Decl*,t_mx2_Decl*)> l_compareFunc){
  bbInt l_insize=1;
  for(;;){
    struct f1_t : public bbGCFrame{
      t_std_collections_List_1Tt_mx2_Decl_2_Node* l_p{};
      t_std_collections_List_1Tt_mx2_Decl_2_Node* l_tail{};
      void gcMark(){
        bbGCMarkPtr(l_p);
        bbGCMarkPtr(l_tail);
      }
    }f1{};
    bbInt l_merges=bbInt(0);
    f1.l_tail=this->m__0head;
    f1.l_p=this->m__0head->m__0succ;
    while((f1.l_p!=this->m__0head)){
      struct f2_t : public bbGCFrame{
        t_std_collections_List_1Tt_mx2_Decl_2_Node* l_q{};
        void gcMark(){
          bbGCMarkPtr(l_q);
        }
      }f2{};
      l_merges+=1;
      f2.l_q=f1.l_p->m__0succ;
      bbInt l_qsize=l_insize;
      bbInt l_psize=1;
      while(((l_psize<l_insize)&&(f2.l_q!=this->m__0head))){
        l_psize+=1;
        f2.l_q=f2.l_q->m__0succ;
      }
      for(;;){
        struct f3_t : public bbGCFrame{
          t_std_collections_List_1Tt_mx2_Decl_2_Node* l_t{};
          void gcMark(){
            bbGCMarkPtr(l_t);
          }
        }f3{};
        if(((bbBool(l_psize)&&bbBool(l_qsize))&&(f2.l_q!=this->m__0head))){
          bbInt l_cc=l_compareFunc(f1.l_p->m__0value,f2.l_q->m__0value);
          if((l_cc<=bbInt(0))){
            f3.l_t=f1.l_p;
            f1.l_p=f1.l_p->m__0succ;
            l_psize-=1;
          }else{
            f3.l_t=f2.l_q;
            f2.l_q=f2.l_q->m__0succ;
            l_qsize-=1;
          }
        }else if(bbBool(l_psize)){
          f3.l_t=f1.l_p;
          f1.l_p=f1.l_p->m__0succ;
          l_psize-=1;
        }else if((bbBool(l_qsize)&&(f2.l_q!=this->m__0head))){
          f3.l_t=f2.l_q;
          f2.l_q=f2.l_q->m__0succ;
          l_qsize-=1;
        }else{
          break;
        }
        f3.l_t->m__0pred=f1.l_tail;
        f1.l_tail->m__0succ=f3.l_t;
        f1.l_tail=f3.l_t;
      }
      f1.l_p=f2.l_q;
    }
    f1.l_tail->m__0succ=this->m__0head;
    this->m__0head->m__0pred=f1.l_tail;
    if((l_merges<=1)){
      return;
    }
    l_insize*=2;
  }
}

void t_std_collections_List_1Tt_mx2_Decl_2::m_Sort(bbBool l_ascending){
  if(l_ascending){
    struct lambda28 : public bbFunction<bbInt(t_mx2_Decl*,t_mx2_Decl*)>::Rep{
      t_std_collections_List_1Tt_mx2_Decl_2* l_self;
      lambda28(t_std_collections_List_1Tt_mx2_Decl_2* l_self):l_self(l_self){
      }
      bbInt invoke(t_mx2_Decl* l_x,t_mx2_Decl* l_y){
        return bbCompare(l_x,l_y);
      }
      void gcMark(){
        bbGCMarkPtr(l_self);
      }
    };
    this->m_Sort(bbFunction<bbInt(t_mx2_Decl*,t_mx2_Decl*)>(new lambda28(this)));
  }else{
    struct lambda29 : public bbFunction<bbInt(t_mx2_Decl*,t_mx2_Decl*)>::Rep{
      t_std_collections_List_1Tt_mx2_Decl_2* l_self;
      lambda29(t_std_collections_List_1Tt_mx2_Decl_2* l_self):l_self(l_self){
      }
      bbInt invoke(t_mx2_Decl* l_x,t_mx2_Decl* l_y){
        return -bbCompare(l_x,l_y);
      }
      void gcMark(){
        bbGCMarkPtr(l_self);
      }
    };
    this->m_Sort(bbFunction<bbInt(t_mx2_Decl*,t_mx2_Decl*)>(new lambda29(this)));
  }
}

t_mx2_Decl* t_std_collections_List_1Tt_mx2_Decl_2::m_RemoveLast(){
  struct f0_t : public bbGCFrame{
    t_mx2_Decl* l_value{};
    void gcMark(){
      bbGCMarkPtr(l_value);
    }
  }f0{};
  bbDebugAssert(!this->m_Empty(),BB_T("Debug assert failed"));
  f0.l_value=this->m__0head->m__0pred->m__0value;
  this->m__0head->m__0pred->m_Remove();
  this->m__0seq+=1;
  return f0.l_value;
}

bbBool t_std_collections_List_1Tt_mx2_Decl_2::m_RemoveLast(t_mx2_Decl* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_mx2_Decl_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m_FindLastNode(l_value);
  if(!bbBool(f0.l_node)){
    return false;
  }
  f0.l_node->m_Remove();
  this->m__0seq+=1;
  return true;
}

t_mx2_Decl* t_std_collections_List_1Tt_mx2_Decl_2::m_RemoveFirst(){
  struct f0_t : public bbGCFrame{
    t_mx2_Decl* l_value{};
    void gcMark(){
      bbGCMarkPtr(l_value);
    }
  }f0{};
  bbDebugAssert(!this->m_Empty(),BB_T("Debug assert failed"));
  f0.l_value=this->m__0head->m__0succ->m__0value;
  this->m__0head->m__0succ->m_Remove();
  this->m__0seq+=1;
  return f0.l_value;
}

bbInt t_std_collections_List_1Tt_mx2_Decl_2::m_RemoveEach(t_mx2_Decl* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_mx2_Decl_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m__0head->m__0succ;
  bbInt l_n=bbInt(0);
  while((f0.l_node!=this->m__0head)){
    if((f0.l_node->m__0value==l_value)){
      f0.l_node=f0.l_node->m__0succ;
      f0.l_node->m__0pred->m_Remove();
      l_n+=1;
    }else{
      f0.l_node=f0.l_node->m__0succ;
    }
  }
  if(bbBool(l_n)){
    this->m__0seq+=1;
  }
  return l_n;
}

bbBool t_std_collections_List_1Tt_mx2_Decl_2::m_Remove(t_mx2_Decl* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_mx2_Decl_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m_FindNode(l_value);
  if(!bbBool(f0.l_node)){
    return false;
  }
  f0.l_node->m_Remove();
  this->m__0seq+=1;
  return true;
}

t_std_collections_List_1Tt_mx2_Decl_2_Node* t_std_collections_List_1Tt_mx2_Decl_2::m_LastNode(){
  if(!this->m_Empty()){
    return this->m__0head->m__0pred;
  }
  return ((t_std_collections_List_1Tt_mx2_Decl_2_Node*)0);
}

t_mx2_Decl* t_std_collections_List_1Tt_mx2_Decl_2::m_Last(){
  bbDebugAssert(!this->m_Empty(),BB_T("Debug assert failed"));
  return this->m__0head->m__0pred->m__0value;
}

t_std_collections_List_1Tt_mx2_Decl_2_Node* t_std_collections_List_1Tt_mx2_Decl_2::m_HeadNode(){
  return this->m__0head;
}

t_std_collections_List_1Tt_mx2_Decl_2_Node* t_std_collections_List_1Tt_mx2_Decl_2::m_FirstNode(){
  if(!this->m_Empty()){
    return this->m__0head->m__0succ;
  }
  return ((t_std_collections_List_1Tt_mx2_Decl_2_Node*)0);
}

t_mx2_Decl* t_std_collections_List_1Tt_mx2_Decl_2::m_First(){
  bbDebugAssert(!this->m_Empty(),BB_T("Debug assert failed"));
  return this->m__0head->m__0succ->m__0value;
}

t_std_collections_List_1Tt_mx2_Decl_2_Node* t_std_collections_List_1Tt_mx2_Decl_2::m_FindNode(t_mx2_Decl* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_mx2_Decl_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m__0head->m__0succ;
  while((f0.l_node!=this->m__0head)){
    if((f0.l_node->m__0value==l_value)){
      return f0.l_node;
    }
    f0.l_node=f0.l_node->m__0succ;
  }
  return ((t_std_collections_List_1Tt_mx2_Decl_2_Node*)0);
}

t_std_collections_List_1Tt_mx2_Decl_2_Node* t_std_collections_List_1Tt_mx2_Decl_2::m_FindLastNode(t_mx2_Decl* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_mx2_Decl_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m__0head->m__0pred;
  while((f0.l_node!=this->m__0head)){
    if((f0.l_node->m__0value==l_value)){
      return f0.l_node;
    }
    f0.l_node=f0.l_node->m__0pred;
  }
  return ((t_std_collections_List_1Tt_mx2_Decl_2_Node*)0);
}

bbBool t_std_collections_List_1Tt_mx2_Decl_2::m_Empty(){
  return (this->m__0head->m__0succ==this->m__0head);
}

bbInt t_std_collections_List_1Tt_mx2_Decl_2::m_Count(){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_mx2_Decl_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m__0head->m__0succ;
  bbInt l_n=bbInt(0);
  while((f0.l_node!=this->m__0head)){
    f0.l_node=f0.l_node->m__0succ;
    l_n+=1;
  }
  return l_n;
}

void t_std_collections_List_1Tt_mx2_Decl_2::m_Clear(){
  this->m__0head->m__0succ=this->m__0head;
  this->m__0head->m__0pred=this->m__0head;
  this->m__0seq+=1;
}

t_std_collections_List_1Tt_mx2_Decl_2_BackwardsIterator t_std_collections_List_1Tt_mx2_Decl_2::m_Backwards(){
  return t_std_collections_List_1Tt_mx2_Decl_2_BackwardsIterator(this,this->m__0head->m__0pred);
}

t_std_collections_List_1Tt_mx2_Decl_2_Iterator t_std_collections_List_1Tt_mx2_Decl_2::m_All(){
  return t_std_collections_List_1Tt_mx2_Decl_2_Iterator(this,this->m__0head->m__0succ);
}

t_std_collections_List_1Tt_mx2_Decl_2_Node* t_std_collections_List_1Tt_mx2_Decl_2::m_AddLast(t_mx2_Decl* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_mx2_Decl_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=bbGCNew<t_std_collections_List_1Tt_mx2_Decl_2_Node>(l_value,this->m__0head);
  this->m__0seq+=1;
  return f0.l_node;
}

t_std_collections_List_1Tt_mx2_Decl_2_Node* t_std_collections_List_1Tt_mx2_Decl_2::m_AddFirst(t_mx2_Decl* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_mx2_Decl_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=bbGCNew<t_std_collections_List_1Tt_mx2_Decl_2_Node>(l_value,this->m__0head->m__0succ);
  this->m__0seq+=1;
  return f0.l_node;
}

void t_std_collections_List_1Tt_mx2_Decl_2::m_AddAll(bbArray<bbGCVar<t_mx2_Decl>>* l_values){
  {
    bbInt l_0=bbInt(0);
    bbInt l_1=l_values->length();
    for(;(l_0<l_1);l_0+=1){
      struct f2_t : public bbGCFrame{
        t_mx2_Decl* l_value{};
        void gcMark(){
          bbGCMarkPtr(l_value);
        }
      }f2{};
      f2.l_value=l_values->at(l_0);
      this->m_AddLast(f2.l_value);
    }
  }
}

void t_std_collections_List_1Tt_mx2_Decl_2::m_Add(t_mx2_Decl* l_value){
  this->m_AddLast(l_value);
}

void t_std_collections_List_1Tt_mx2_ParseEx_2_Node::gcMark(){
  bbGCMark(m__0succ);
  bbGCMark(m__0pred);
  bbGCMark(m__0value);
}

t_std_collections_List_1Tt_mx2_ParseEx_2_Node::t_std_collections_List_1Tt_mx2_ParseEx_2_Node(t_mx2_ParseEx* l_value,t_std_collections_List_1Tt_mx2_ParseEx_2_Node* l_succ){
  this->m__0value=l_value;
  this->m__0succ=l_succ;
  this->m__0pred=l_succ->m__0pred;
  this->m__0pred->m__0succ=this;
  l_succ->m__0pred=this;
}

t_std_collections_List_1Tt_mx2_ParseEx_2_Node::t_std_collections_List_1Tt_mx2_ParseEx_2_Node(t_mx2_ParseEx* l_value){
  this->m__0value=l_value;
  this->m__0succ=this;
  this->m__0pred=this;
}

void t_std_collections_List_1Tt_mx2_ParseEx_2_Node::m_Value(t_mx2_ParseEx* l_value){
  this->m__0value=l_value;
}

t_mx2_ParseEx* t_std_collections_List_1Tt_mx2_ParseEx_2_Node::m_Value(){
  return this->m__0value;
}

t_std_collections_List_1Tt_mx2_ParseEx_2_Node* t_std_collections_List_1Tt_mx2_ParseEx_2_Node::m_Succ(){
  return this->m__0succ;
}

void t_std_collections_List_1Tt_mx2_ParseEx_2_Node::m_Remove(){
  this->m__0succ->m__0pred=this->m__0pred;
  this->m__0pred->m__0succ=this->m__0succ;
}

t_std_collections_List_1Tt_mx2_ParseEx_2_Node* t_std_collections_List_1Tt_mx2_ParseEx_2_Node::m_Pred(){
  return this->m__0pred;
}

void t_std_collections_List_1Tt_mx2_ParseEx_2_Node::m_InsertBefore(t_std_collections_List_1Tt_mx2_ParseEx_2_Node* l_node){
  this->m__0succ=l_node;
  this->m__0pred=l_node->m__0pred;
  this->m__0pred->m__0succ=this;
  l_node->m__0pred=this;
}

void t_std_collections_List_1Tt_mx2_ParseEx_2_Node::m_InsertAfter(t_std_collections_List_1Tt_mx2_ParseEx_2_Node* l_node){
  this->m__0pred=l_node;
  this->m__0succ=l_node->m__0succ;
  this->m__0succ->m__0pred=this;
  l_node->m__0succ=this;
}

t_std_collections_List_1Tt_mx2_ParseEx_2_Iterator::t_std_collections_List_1Tt_mx2_ParseEx_2_Iterator(t_std_collections_List_1Tt_mx2_ParseEx_2* l_list,t_std_collections_List_1Tt_mx2_ParseEx_2_Node* l_node){
  (*this).m__0list=l_list;
  (*this).m__0node=l_node;
  (*this).m__0seq=l_list->m__0seq;
}

void t_std_collections_List_1Tt_mx2_ParseEx_2_Iterator::m_Insert(t_mx2_ParseEx* l_value){
  (*this).m_AssertSeq();
  (*this).m__0node=bbGCNew<t_std_collections_List_1Tt_mx2_ParseEx_2_Node>(l_value,(*this).m__0node);
  (*this).m__0list->m__0seq+=1;
  (*this).m__0seq=(*this).m__0list->m__0seq;
}

void t_std_collections_List_1Tt_mx2_ParseEx_2_Iterator::m_Erase(){
  (*this).m_AssertCurrent();
  (*this).m__0node=(*this).m__0node->m__0succ;
  (*this).m__0node->m__0pred->m_Remove();
  (*this).m__0list->m__0seq+=1;
  (*this).m__0seq=(*this).m__0list->m__0seq;
}

void t_std_collections_List_1Tt_mx2_ParseEx_2_Iterator::m_Current(t_mx2_ParseEx* l_current){
  (*this).m_AssertCurrent();
  (*this).m__0node->m__0value=l_current;
}

t_mx2_ParseEx* t_std_collections_List_1Tt_mx2_ParseEx_2_Iterator::m_Current(){
  (*this).m_AssertCurrent();
  return (*this).m__0node->m__0value;
}

void t_std_collections_List_1Tt_mx2_ParseEx_2_Iterator::m_Bump(){
  (*this).m_AssertCurrent();
  (*this).m__0node=(*this).m__0node->m__0succ;
}

bbBool t_std_collections_List_1Tt_mx2_ParseEx_2_Iterator::m_AtEnd(){
  (*this).m_AssertSeq();
  return ((*this).m__0node==(*this).m__0list->m__0head);
}

void t_std_collections_List_1Tt_mx2_ParseEx_2_Iterator::m_AssertSeq(){
  bbDebugAssert(((*this).m__0seq==(*this).m__0list->m__0seq),BB_T("Concurrent list modification"));
}

void t_std_collections_List_1Tt_mx2_ParseEx_2_Iterator::m_AssertCurrent(){
  bbDebugAssert(!(*this).m_AtEnd(),BB_T("Invalid list iterator"));
}

int bbCompare(const t_std_collections_List_1Tt_mx2_ParseEx_2_Iterator&x,const t_std_collections_List_1Tt_mx2_ParseEx_2_Iterator&y){
  if(int t=bbCompare(x.m__0list,y.m__0list)) return t;
  if(int t=bbCompare(x.m__0node,y.m__0node)) return t;
  if(int t=bbCompare(x.m__0seq,y.m__0seq)) return t;
  return 0;
}

void bbGCMark(const t_std_collections_List_1Tt_mx2_ParseEx_2_Iterator&t){
  bbGCMark(t.m__0list);
  bbGCMark(t.m__0node);
}

t_std_collections_List_1Tt_mx2_ParseEx_2_BackwardsIterator::t_std_collections_List_1Tt_mx2_ParseEx_2_BackwardsIterator(t_std_collections_List_1Tt_mx2_ParseEx_2* l_list,t_std_collections_List_1Tt_mx2_ParseEx_2_Node* l_node){
  (*this).m__0list=l_list;
  (*this).m__0node=l_node;
  (*this).m__0seq=l_list->m__0seq;
}

void t_std_collections_List_1Tt_mx2_ParseEx_2_BackwardsIterator::m_Insert(t_mx2_ParseEx* l_value){
  (*this).m_AssertSeq();
  (*this).m__0node=bbGCNew<t_std_collections_List_1Tt_mx2_ParseEx_2_Node>(l_value,(*this).m__0node->m__0succ);
  (*this).m__0list->m__0seq+=1;
  (*this).m__0seq=(*this).m__0list->m__0seq;
}

void t_std_collections_List_1Tt_mx2_ParseEx_2_BackwardsIterator::m_Erase(){
  (*this).m_AssertCurrent();
  (*this).m__0node=(*this).m__0node->m__0pred;
  (*this).m__0node->m__0succ->m_Remove();
  (*this).m__0list->m__0seq+=1;
  (*this).m__0seq=(*this).m__0list->m__0seq;
}

void t_std_collections_List_1Tt_mx2_ParseEx_2_BackwardsIterator::m_Current(t_mx2_ParseEx* l_current){
  (*this).m_AssertCurrent();
  (*this).m__0node->m__0value=l_current;
}

t_mx2_ParseEx* t_std_collections_List_1Tt_mx2_ParseEx_2_BackwardsIterator::m_Current(){
  (*this).m_AssertCurrent();
  return (*this).m__0node->m__0value;
}

void t_std_collections_List_1Tt_mx2_ParseEx_2_BackwardsIterator::m_Bump(){
  (*this).m_AssertCurrent();
  (*this).m__0node=(*this).m__0node->m__0pred;
}

bbBool t_std_collections_List_1Tt_mx2_ParseEx_2_BackwardsIterator::m_AtEnd(){
  (*this).m_AssertSeq();
  return ((*this).m__0node==(*this).m__0list->m__0head);
}

void t_std_collections_List_1Tt_mx2_ParseEx_2_BackwardsIterator::m_AssertSeq(){
  bbDebugAssert(((*this).m__0seq==(*this).m__0list->m__0seq),BB_T("Concurrent list modification"));
}

void t_std_collections_List_1Tt_mx2_ParseEx_2_BackwardsIterator::m_AssertCurrent(){
  bbDebugAssert(!(*this).m_AtEnd(),BB_T("Invalid list iterator"));
}

int bbCompare(const t_std_collections_List_1Tt_mx2_ParseEx_2_BackwardsIterator&x,const t_std_collections_List_1Tt_mx2_ParseEx_2_BackwardsIterator&y){
  if(int t=bbCompare(x.m__0list,y.m__0list)) return t;
  if(int t=bbCompare(x.m__0node,y.m__0node)) return t;
  if(int t=bbCompare(x.m__0seq,y.m__0seq)) return t;
  return 0;
}

void bbGCMark(const t_std_collections_List_1Tt_mx2_ParseEx_2_BackwardsIterator&t){
  bbGCMark(t.m__0list);
  bbGCMark(t.m__0node);
}

void t_std_collections_List_1Tt_mx2_ParseEx_2::gcMark(){
  bbGCMark(m__0head);
}

t_std_collections_List_1Tt_mx2_ParseEx_2::t_std_collections_List_1Tt_mx2_ParseEx_2(t_std_collections_List_1Tt_mx2_ParseEx_2* l_values):t_std_collections_List_1Tt_mx2_ParseEx_2(){
  g_std_collections_List_1Tt_mx2_ParseEx_2_AddAll_1Tt_std_collections_List_1Tt_mx2_ParseEx_2_2(this,l_values);
}

t_std_collections_List_1Tt_mx2_ParseEx_2::t_std_collections_List_1Tt_mx2_ParseEx_2(t_std_collections_Stack_1Tt_mx2_ParseEx_2* l_values):t_std_collections_List_1Tt_mx2_ParseEx_2(){
  g_std_collections_List_1Tt_mx2_ParseEx_2_AddAll_1Tt_std_collections_Stack_1Tt_mx2_ParseEx_2_2(this,l_values);
}

t_std_collections_List_1Tt_mx2_ParseEx_2::t_std_collections_List_1Tt_mx2_ParseEx_2(bbArray<bbGCVar<t_mx2_ParseEx>>* l_values):t_std_collections_List_1Tt_mx2_ParseEx_2(){
  this->m_AddAll(l_values);
}

t_std_collections_List_1Tt_mx2_ParseEx_2::t_std_collections_List_1Tt_mx2_ParseEx_2(){
  this->m__0head=bbGCNew<t_std_collections_List_1Tt_mx2_ParseEx_2_Node>(((t_mx2_ParseEx*)0));
}

bbArray<bbGCVar<t_mx2_ParseEx>>* t_std_collections_List_1Tt_mx2_ParseEx_2::m_ToArray(){
  struct f0_t : public bbGCFrame{
    bbArray<bbGCVar<t_mx2_ParseEx>>* l_data{};
    t_std_collections_List_1Tt_mx2_ParseEx_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_data);
      bbGCMarkPtr(l_node);
    }
  }f0{};
  bbInt l_n=this->m_Count();
  f0.l_data=bbArray<bbGCVar<t_mx2_ParseEx>>::create(l_n);
  f0.l_node=this->m__0head->m__0succ;
  {
    bbInt l_i=bbInt(0);
    for(;(l_i<l_n);l_i+=1){
      f0.l_data->at(l_i)=f0.l_node->m__0value;
      f0.l_node=f0.l_node->m__0succ;
    }
  }
  return f0.l_data;
}

void t_std_collections_List_1Tt_mx2_ParseEx_2::m_Sort(bbFunction<bbInt(t_mx2_ParseEx*,t_mx2_ParseEx*)> l_compareFunc){
  bbInt l_insize=1;
  for(;;){
    struct f1_t : public bbGCFrame{
      t_std_collections_List_1Tt_mx2_ParseEx_2_Node* l_p{};
      t_std_collections_List_1Tt_mx2_ParseEx_2_Node* l_tail{};
      void gcMark(){
        bbGCMarkPtr(l_p);
        bbGCMarkPtr(l_tail);
      }
    }f1{};
    bbInt l_merges=bbInt(0);
    f1.l_tail=this->m__0head;
    f1.l_p=this->m__0head->m__0succ;
    while((f1.l_p!=this->m__0head)){
      struct f2_t : public bbGCFrame{
        t_std_collections_List_1Tt_mx2_ParseEx_2_Node* l_q{};
        void gcMark(){
          bbGCMarkPtr(l_q);
        }
      }f2{};
      l_merges+=1;
      f2.l_q=f1.l_p->m__0succ;
      bbInt l_qsize=l_insize;
      bbInt l_psize=1;
      while(((l_psize<l_insize)&&(f2.l_q!=this->m__0head))){
        l_psize+=1;
        f2.l_q=f2.l_q->m__0succ;
      }
      for(;;){
        struct f3_t : public bbGCFrame{
          t_std_collections_List_1Tt_mx2_ParseEx_2_Node* l_t{};
          void gcMark(){
            bbGCMarkPtr(l_t);
          }
        }f3{};
        if(((bbBool(l_psize)&&bbBool(l_qsize))&&(f2.l_q!=this->m__0head))){
          bbInt l_cc=l_compareFunc(f1.l_p->m__0value,f2.l_q->m__0value);
          if((l_cc<=bbInt(0))){
            f3.l_t=f1.l_p;
            f1.l_p=f1.l_p->m__0succ;
            l_psize-=1;
          }else{
            f3.l_t=f2.l_q;
            f2.l_q=f2.l_q->m__0succ;
            l_qsize-=1;
          }
        }else if(bbBool(l_psize)){
          f3.l_t=f1.l_p;
          f1.l_p=f1.l_p->m__0succ;
          l_psize-=1;
        }else if((bbBool(l_qsize)&&(f2.l_q!=this->m__0head))){
          f3.l_t=f2.l_q;
          f2.l_q=f2.l_q->m__0succ;
          l_qsize-=1;
        }else{
          break;
        }
        f3.l_t->m__0pred=f1.l_tail;
        f1.l_tail->m__0succ=f3.l_t;
        f1.l_tail=f3.l_t;
      }
      f1.l_p=f2.l_q;
    }
    f1.l_tail->m__0succ=this->m__0head;
    this->m__0head->m__0pred=f1.l_tail;
    if((l_merges<=1)){
      return;
    }
    l_insize*=2;
  }
}

void t_std_collections_List_1Tt_mx2_ParseEx_2::m_Sort(bbBool l_ascending){
  if(l_ascending){
    struct lambda30 : public bbFunction<bbInt(t_mx2_ParseEx*,t_mx2_ParseEx*)>::Rep{
      t_std_collections_List_1Tt_mx2_ParseEx_2* l_self;
      lambda30(t_std_collections_List_1Tt_mx2_ParseEx_2* l_self):l_self(l_self){
      }
      bbInt invoke(t_mx2_ParseEx* l_x,t_mx2_ParseEx* l_y){
        return bbCompare(l_x,l_y);
      }
      void gcMark(){
        bbGCMarkPtr(l_self);
      }
    };
    this->m_Sort(bbFunction<bbInt(t_mx2_ParseEx*,t_mx2_ParseEx*)>(new lambda30(this)));
  }else{
    struct lambda31 : public bbFunction<bbInt(t_mx2_ParseEx*,t_mx2_ParseEx*)>::Rep{
      t_std_collections_List_1Tt_mx2_ParseEx_2* l_self;
      lambda31(t_std_collections_List_1Tt_mx2_ParseEx_2* l_self):l_self(l_self){
      }
      bbInt invoke(t_mx2_ParseEx* l_x,t_mx2_ParseEx* l_y){
        return -bbCompare(l_x,l_y);
      }
      void gcMark(){
        bbGCMarkPtr(l_self);
      }
    };
    this->m_Sort(bbFunction<bbInt(t_mx2_ParseEx*,t_mx2_ParseEx*)>(new lambda31(this)));
  }
}

t_mx2_ParseEx* t_std_collections_List_1Tt_mx2_ParseEx_2::m_RemoveLast(){
  struct f0_t : public bbGCFrame{
    t_mx2_ParseEx* l_value{};
    void gcMark(){
      bbGCMarkPtr(l_value);
    }
  }f0{};
  bbDebugAssert(!this->m_Empty(),BB_T("Debug assert failed"));
  f0.l_value=this->m__0head->m__0pred->m__0value;
  this->m__0head->m__0pred->m_Remove();
  this->m__0seq+=1;
  return f0.l_value;
}

bbBool t_std_collections_List_1Tt_mx2_ParseEx_2::m_RemoveLast(t_mx2_ParseEx* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_mx2_ParseEx_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m_FindLastNode(l_value);
  if(!bbBool(f0.l_node)){
    return false;
  }
  f0.l_node->m_Remove();
  this->m__0seq+=1;
  return true;
}

t_mx2_ParseEx* t_std_collections_List_1Tt_mx2_ParseEx_2::m_RemoveFirst(){
  struct f0_t : public bbGCFrame{
    t_mx2_ParseEx* l_value{};
    void gcMark(){
      bbGCMarkPtr(l_value);
    }
  }f0{};
  bbDebugAssert(!this->m_Empty(),BB_T("Debug assert failed"));
  f0.l_value=this->m__0head->m__0succ->m__0value;
  this->m__0head->m__0succ->m_Remove();
  this->m__0seq+=1;
  return f0.l_value;
}

bbInt t_std_collections_List_1Tt_mx2_ParseEx_2::m_RemoveEach(t_mx2_ParseEx* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_mx2_ParseEx_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m__0head->m__0succ;
  bbInt l_n=bbInt(0);
  while((f0.l_node!=this->m__0head)){
    if((f0.l_node->m__0value==l_value)){
      f0.l_node=f0.l_node->m__0succ;
      f0.l_node->m__0pred->m_Remove();
      l_n+=1;
    }else{
      f0.l_node=f0.l_node->m__0succ;
    }
  }
  if(bbBool(l_n)){
    this->m__0seq+=1;
  }
  return l_n;
}

bbBool t_std_collections_List_1Tt_mx2_ParseEx_2::m_Remove(t_mx2_ParseEx* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_mx2_ParseEx_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m_FindNode(l_value);
  if(!bbBool(f0.l_node)){
    return false;
  }
  f0.l_node->m_Remove();
  this->m__0seq+=1;
  return true;
}

t_std_collections_List_1Tt_mx2_ParseEx_2_Node* t_std_collections_List_1Tt_mx2_ParseEx_2::m_LastNode(){
  if(!this->m_Empty()){
    return this->m__0head->m__0pred;
  }
  return ((t_std_collections_List_1Tt_mx2_ParseEx_2_Node*)0);
}

t_mx2_ParseEx* t_std_collections_List_1Tt_mx2_ParseEx_2::m_Last(){
  bbDebugAssert(!this->m_Empty(),BB_T("Debug assert failed"));
  return this->m__0head->m__0pred->m__0value;
}

t_std_collections_List_1Tt_mx2_ParseEx_2_Node* t_std_collections_List_1Tt_mx2_ParseEx_2::m_HeadNode(){
  return this->m__0head;
}

t_std_collections_List_1Tt_mx2_ParseEx_2_Node* t_std_collections_List_1Tt_mx2_ParseEx_2::m_FirstNode(){
  if(!this->m_Empty()){
    return this->m__0head->m__0succ;
  }
  return ((t_std_collections_List_1Tt_mx2_ParseEx_2_Node*)0);
}

t_mx2_ParseEx* t_std_collections_List_1Tt_mx2_ParseEx_2::m_First(){
  bbDebugAssert(!this->m_Empty(),BB_T("Debug assert failed"));
  return this->m__0head->m__0succ->m__0value;
}

t_std_collections_List_1Tt_mx2_ParseEx_2_Node* t_std_collections_List_1Tt_mx2_ParseEx_2::m_FindNode(t_mx2_ParseEx* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_mx2_ParseEx_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m__0head->m__0succ;
  while((f0.l_node!=this->m__0head)){
    if((f0.l_node->m__0value==l_value)){
      return f0.l_node;
    }
    f0.l_node=f0.l_node->m__0succ;
  }
  return ((t_std_collections_List_1Tt_mx2_ParseEx_2_Node*)0);
}

t_std_collections_List_1Tt_mx2_ParseEx_2_Node* t_std_collections_List_1Tt_mx2_ParseEx_2::m_FindLastNode(t_mx2_ParseEx* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_mx2_ParseEx_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m__0head->m__0pred;
  while((f0.l_node!=this->m__0head)){
    if((f0.l_node->m__0value==l_value)){
      return f0.l_node;
    }
    f0.l_node=f0.l_node->m__0pred;
  }
  return ((t_std_collections_List_1Tt_mx2_ParseEx_2_Node*)0);
}

bbBool t_std_collections_List_1Tt_mx2_ParseEx_2::m_Empty(){
  return (this->m__0head->m__0succ==this->m__0head);
}

bbInt t_std_collections_List_1Tt_mx2_ParseEx_2::m_Count(){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_mx2_ParseEx_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m__0head->m__0succ;
  bbInt l_n=bbInt(0);
  while((f0.l_node!=this->m__0head)){
    f0.l_node=f0.l_node->m__0succ;
    l_n+=1;
  }
  return l_n;
}

void t_std_collections_List_1Tt_mx2_ParseEx_2::m_Clear(){
  this->m__0head->m__0succ=this->m__0head;
  this->m__0head->m__0pred=this->m__0head;
  this->m__0seq+=1;
}

t_std_collections_List_1Tt_mx2_ParseEx_2_BackwardsIterator t_std_collections_List_1Tt_mx2_ParseEx_2::m_Backwards(){
  return t_std_collections_List_1Tt_mx2_ParseEx_2_BackwardsIterator(this,this->m__0head->m__0pred);
}

t_std_collections_List_1Tt_mx2_ParseEx_2_Iterator t_std_collections_List_1Tt_mx2_ParseEx_2::m_All(){
  return t_std_collections_List_1Tt_mx2_ParseEx_2_Iterator(this,this->m__0head->m__0succ);
}

t_std_collections_List_1Tt_mx2_ParseEx_2_Node* t_std_collections_List_1Tt_mx2_ParseEx_2::m_AddLast(t_mx2_ParseEx* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_mx2_ParseEx_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=bbGCNew<t_std_collections_List_1Tt_mx2_ParseEx_2_Node>(l_value,this->m__0head);
  this->m__0seq+=1;
  return f0.l_node;
}

t_std_collections_List_1Tt_mx2_ParseEx_2_Node* t_std_collections_List_1Tt_mx2_ParseEx_2::m_AddFirst(t_mx2_ParseEx* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_mx2_ParseEx_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=bbGCNew<t_std_collections_List_1Tt_mx2_ParseEx_2_Node>(l_value,this->m__0head->m__0succ);
  this->m__0seq+=1;
  return f0.l_node;
}

void t_std_collections_List_1Tt_mx2_ParseEx_2::m_AddAll(bbArray<bbGCVar<t_mx2_ParseEx>>* l_values){
  {
    bbInt l_0=bbInt(0);
    bbInt l_1=l_values->length();
    for(;(l_0<l_1);l_0+=1){
      struct f2_t : public bbGCFrame{
        t_mx2_ParseEx* l_value{};
        void gcMark(){
          bbGCMarkPtr(l_value);
        }
      }f2{};
      f2.l_value=l_values->at(l_0);
      this->m_AddLast(f2.l_value);
    }
  }
}

void t_std_collections_List_1Tt_mx2_ParseEx_2::m_Add(t_mx2_ParseEx* l_value){
  this->m_AddLast(l_value);
}

void t_std_collections_List_1Tt_mx2_Toker_2_Node::gcMark(){
  bbGCMark(m__0succ);
  bbGCMark(m__0pred);
  bbGCMark(m__0value);
}

t_std_collections_List_1Tt_mx2_Toker_2_Node::t_std_collections_List_1Tt_mx2_Toker_2_Node(t_mx2_Toker* l_value,t_std_collections_List_1Tt_mx2_Toker_2_Node* l_succ){
  this->m__0value=l_value;
  this->m__0succ=l_succ;
  this->m__0pred=l_succ->m__0pred;
  this->m__0pred->m__0succ=this;
  l_succ->m__0pred=this;
}

t_std_collections_List_1Tt_mx2_Toker_2_Node::t_std_collections_List_1Tt_mx2_Toker_2_Node(t_mx2_Toker* l_value){
  this->m__0value=l_value;
  this->m__0succ=this;
  this->m__0pred=this;
}

void t_std_collections_List_1Tt_mx2_Toker_2_Node::m_Value(t_mx2_Toker* l_value){
  this->m__0value=l_value;
}

t_mx2_Toker* t_std_collections_List_1Tt_mx2_Toker_2_Node::m_Value(){
  return this->m__0value;
}

t_std_collections_List_1Tt_mx2_Toker_2_Node* t_std_collections_List_1Tt_mx2_Toker_2_Node::m_Succ(){
  return this->m__0succ;
}

void t_std_collections_List_1Tt_mx2_Toker_2_Node::m_Remove(){
  this->m__0succ->m__0pred=this->m__0pred;
  this->m__0pred->m__0succ=this->m__0succ;
}

t_std_collections_List_1Tt_mx2_Toker_2_Node* t_std_collections_List_1Tt_mx2_Toker_2_Node::m_Pred(){
  return this->m__0pred;
}

void t_std_collections_List_1Tt_mx2_Toker_2_Node::m_InsertBefore(t_std_collections_List_1Tt_mx2_Toker_2_Node* l_node){
  this->m__0succ=l_node;
  this->m__0pred=l_node->m__0pred;
  this->m__0pred->m__0succ=this;
  l_node->m__0pred=this;
}

void t_std_collections_List_1Tt_mx2_Toker_2_Node::m_InsertAfter(t_std_collections_List_1Tt_mx2_Toker_2_Node* l_node){
  this->m__0pred=l_node;
  this->m__0succ=l_node->m__0succ;
  this->m__0succ->m__0pred=this;
  l_node->m__0succ=this;
}

t_std_collections_List_1Tt_mx2_Toker_2_Iterator::t_std_collections_List_1Tt_mx2_Toker_2_Iterator(t_std_collections_List_1Tt_mx2_Toker_2* l_list,t_std_collections_List_1Tt_mx2_Toker_2_Node* l_node){
  (*this).m__0list=l_list;
  (*this).m__0node=l_node;
  (*this).m__0seq=l_list->m__0seq;
}

void t_std_collections_List_1Tt_mx2_Toker_2_Iterator::m_Insert(t_mx2_Toker* l_value){
  (*this).m_AssertSeq();
  (*this).m__0node=bbGCNew<t_std_collections_List_1Tt_mx2_Toker_2_Node>(l_value,(*this).m__0node);
  (*this).m__0list->m__0seq+=1;
  (*this).m__0seq=(*this).m__0list->m__0seq;
}

void t_std_collections_List_1Tt_mx2_Toker_2_Iterator::m_Erase(){
  (*this).m_AssertCurrent();
  (*this).m__0node=(*this).m__0node->m__0succ;
  (*this).m__0node->m__0pred->m_Remove();
  (*this).m__0list->m__0seq+=1;
  (*this).m__0seq=(*this).m__0list->m__0seq;
}

void t_std_collections_List_1Tt_mx2_Toker_2_Iterator::m_Current(t_mx2_Toker* l_current){
  (*this).m_AssertCurrent();
  (*this).m__0node->m__0value=l_current;
}

t_mx2_Toker* t_std_collections_List_1Tt_mx2_Toker_2_Iterator::m_Current(){
  (*this).m_AssertCurrent();
  return (*this).m__0node->m__0value;
}

void t_std_collections_List_1Tt_mx2_Toker_2_Iterator::m_Bump(){
  (*this).m_AssertCurrent();
  (*this).m__0node=(*this).m__0node->m__0succ;
}

bbBool t_std_collections_List_1Tt_mx2_Toker_2_Iterator::m_AtEnd(){
  (*this).m_AssertSeq();
  return ((*this).m__0node==(*this).m__0list->m__0head);
}

void t_std_collections_List_1Tt_mx2_Toker_2_Iterator::m_AssertSeq(){
  bbDebugAssert(((*this).m__0seq==(*this).m__0list->m__0seq),BB_T("Concurrent list modification"));
}

void t_std_collections_List_1Tt_mx2_Toker_2_Iterator::m_AssertCurrent(){
  bbDebugAssert(!(*this).m_AtEnd(),BB_T("Invalid list iterator"));
}

int bbCompare(const t_std_collections_List_1Tt_mx2_Toker_2_Iterator&x,const t_std_collections_List_1Tt_mx2_Toker_2_Iterator&y){
  if(int t=bbCompare(x.m__0list,y.m__0list)) return t;
  if(int t=bbCompare(x.m__0node,y.m__0node)) return t;
  if(int t=bbCompare(x.m__0seq,y.m__0seq)) return t;
  return 0;
}

void bbGCMark(const t_std_collections_List_1Tt_mx2_Toker_2_Iterator&t){
  bbGCMark(t.m__0list);
  bbGCMark(t.m__0node);
}

t_std_collections_List_1Tt_mx2_Toker_2_BackwardsIterator::t_std_collections_List_1Tt_mx2_Toker_2_BackwardsIterator(t_std_collections_List_1Tt_mx2_Toker_2* l_list,t_std_collections_List_1Tt_mx2_Toker_2_Node* l_node){
  (*this).m__0list=l_list;
  (*this).m__0node=l_node;
  (*this).m__0seq=l_list->m__0seq;
}

void t_std_collections_List_1Tt_mx2_Toker_2_BackwardsIterator::m_Insert(t_mx2_Toker* l_value){
  (*this).m_AssertSeq();
  (*this).m__0node=bbGCNew<t_std_collections_List_1Tt_mx2_Toker_2_Node>(l_value,(*this).m__0node->m__0succ);
  (*this).m__0list->m__0seq+=1;
  (*this).m__0seq=(*this).m__0list->m__0seq;
}

void t_std_collections_List_1Tt_mx2_Toker_2_BackwardsIterator::m_Erase(){
  (*this).m_AssertCurrent();
  (*this).m__0node=(*this).m__0node->m__0pred;
  (*this).m__0node->m__0succ->m_Remove();
  (*this).m__0list->m__0seq+=1;
  (*this).m__0seq=(*this).m__0list->m__0seq;
}

void t_std_collections_List_1Tt_mx2_Toker_2_BackwardsIterator::m_Current(t_mx2_Toker* l_current){
  (*this).m_AssertCurrent();
  (*this).m__0node->m__0value=l_current;
}

t_mx2_Toker* t_std_collections_List_1Tt_mx2_Toker_2_BackwardsIterator::m_Current(){
  (*this).m_AssertCurrent();
  return (*this).m__0node->m__0value;
}

void t_std_collections_List_1Tt_mx2_Toker_2_BackwardsIterator::m_Bump(){
  (*this).m_AssertCurrent();
  (*this).m__0node=(*this).m__0node->m__0pred;
}

bbBool t_std_collections_List_1Tt_mx2_Toker_2_BackwardsIterator::m_AtEnd(){
  (*this).m_AssertSeq();
  return ((*this).m__0node==(*this).m__0list->m__0head);
}

void t_std_collections_List_1Tt_mx2_Toker_2_BackwardsIterator::m_AssertSeq(){
  bbDebugAssert(((*this).m__0seq==(*this).m__0list->m__0seq),BB_T("Concurrent list modification"));
}

void t_std_collections_List_1Tt_mx2_Toker_2_BackwardsIterator::m_AssertCurrent(){
  bbDebugAssert(!(*this).m_AtEnd(),BB_T("Invalid list iterator"));
}

int bbCompare(const t_std_collections_List_1Tt_mx2_Toker_2_BackwardsIterator&x,const t_std_collections_List_1Tt_mx2_Toker_2_BackwardsIterator&y){
  if(int t=bbCompare(x.m__0list,y.m__0list)) return t;
  if(int t=bbCompare(x.m__0node,y.m__0node)) return t;
  if(int t=bbCompare(x.m__0seq,y.m__0seq)) return t;
  return 0;
}

void bbGCMark(const t_std_collections_List_1Tt_mx2_Toker_2_BackwardsIterator&t){
  bbGCMark(t.m__0list);
  bbGCMark(t.m__0node);
}

void t_std_collections_List_1Tt_mx2_Toker_2::gcMark(){
  bbGCMark(m__0head);
}

t_std_collections_List_1Tt_mx2_Toker_2::t_std_collections_List_1Tt_mx2_Toker_2(t_std_collections_List_1Tt_mx2_Toker_2* l_values):t_std_collections_List_1Tt_mx2_Toker_2(){
  g_std_collections_List_1Tt_mx2_Toker_2_AddAll_1Tt_std_collections_List_1Tt_mx2_Toker_2_2(this,l_values);
}

t_std_collections_List_1Tt_mx2_Toker_2::t_std_collections_List_1Tt_mx2_Toker_2(t_std_collections_Stack_1Tt_mx2_Toker_2* l_values):t_std_collections_List_1Tt_mx2_Toker_2(){
  g_std_collections_List_1Tt_mx2_Toker_2_AddAll_1Tt_std_collections_Stack_1Tt_mx2_Toker_2_2(this,l_values);
}

t_std_collections_List_1Tt_mx2_Toker_2::t_std_collections_List_1Tt_mx2_Toker_2(bbArray<bbGCVar<t_mx2_Toker>>* l_values):t_std_collections_List_1Tt_mx2_Toker_2(){
  this->m_AddAll(l_values);
}

t_std_collections_List_1Tt_mx2_Toker_2::t_std_collections_List_1Tt_mx2_Toker_2(){
  this->m__0head=bbGCNew<t_std_collections_List_1Tt_mx2_Toker_2_Node>(((t_mx2_Toker*)0));
}

bbArray<bbGCVar<t_mx2_Toker>>* t_std_collections_List_1Tt_mx2_Toker_2::m_ToArray(){
  struct f0_t : public bbGCFrame{
    bbArray<bbGCVar<t_mx2_Toker>>* l_data{};
    t_std_collections_List_1Tt_mx2_Toker_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_data);
      bbGCMarkPtr(l_node);
    }
  }f0{};
  bbInt l_n=this->m_Count();
  f0.l_data=bbArray<bbGCVar<t_mx2_Toker>>::create(l_n);
  f0.l_node=this->m__0head->m__0succ;
  {
    bbInt l_i=bbInt(0);
    for(;(l_i<l_n);l_i+=1){
      f0.l_data->at(l_i)=f0.l_node->m__0value;
      f0.l_node=f0.l_node->m__0succ;
    }
  }
  return f0.l_data;
}

void t_std_collections_List_1Tt_mx2_Toker_2::m_Sort(bbFunction<bbInt(t_mx2_Toker*,t_mx2_Toker*)> l_compareFunc){
  bbInt l_insize=1;
  for(;;){
    struct f1_t : public bbGCFrame{
      t_std_collections_List_1Tt_mx2_Toker_2_Node* l_p{};
      t_std_collections_List_1Tt_mx2_Toker_2_Node* l_tail{};
      void gcMark(){
        bbGCMarkPtr(l_p);
        bbGCMarkPtr(l_tail);
      }
    }f1{};
    bbInt l_merges=bbInt(0);
    f1.l_tail=this->m__0head;
    f1.l_p=this->m__0head->m__0succ;
    while((f1.l_p!=this->m__0head)){
      struct f2_t : public bbGCFrame{
        t_std_collections_List_1Tt_mx2_Toker_2_Node* l_q{};
        void gcMark(){
          bbGCMarkPtr(l_q);
        }
      }f2{};
      l_merges+=1;
      f2.l_q=f1.l_p->m__0succ;
      bbInt l_qsize=l_insize;
      bbInt l_psize=1;
      while(((l_psize<l_insize)&&(f2.l_q!=this->m__0head))){
        l_psize+=1;
        f2.l_q=f2.l_q->m__0succ;
      }
      for(;;){
        struct f3_t : public bbGCFrame{
          t_std_collections_List_1Tt_mx2_Toker_2_Node* l_t{};
          void gcMark(){
            bbGCMarkPtr(l_t);
          }
        }f3{};
        if(((bbBool(l_psize)&&bbBool(l_qsize))&&(f2.l_q!=this->m__0head))){
          bbInt l_cc=l_compareFunc(f1.l_p->m__0value,f2.l_q->m__0value);
          if((l_cc<=bbInt(0))){
            f3.l_t=f1.l_p;
            f1.l_p=f1.l_p->m__0succ;
            l_psize-=1;
          }else{
            f3.l_t=f2.l_q;
            f2.l_q=f2.l_q->m__0succ;
            l_qsize-=1;
          }
        }else if(bbBool(l_psize)){
          f3.l_t=f1.l_p;
          f1.l_p=f1.l_p->m__0succ;
          l_psize-=1;
        }else if((bbBool(l_qsize)&&(f2.l_q!=this->m__0head))){
          f3.l_t=f2.l_q;
          f2.l_q=f2.l_q->m__0succ;
          l_qsize-=1;
        }else{
          break;
        }
        f3.l_t->m__0pred=f1.l_tail;
        f1.l_tail->m__0succ=f3.l_t;
        f1.l_tail=f3.l_t;
      }
      f1.l_p=f2.l_q;
    }
    f1.l_tail->m__0succ=this->m__0head;
    this->m__0head->m__0pred=f1.l_tail;
    if((l_merges<=1)){
      return;
    }
    l_insize*=2;
  }
}

void t_std_collections_List_1Tt_mx2_Toker_2::m_Sort(bbBool l_ascending){
  if(l_ascending){
    struct lambda32 : public bbFunction<bbInt(t_mx2_Toker*,t_mx2_Toker*)>::Rep{
      t_std_collections_List_1Tt_mx2_Toker_2* l_self;
      lambda32(t_std_collections_List_1Tt_mx2_Toker_2* l_self):l_self(l_self){
      }
      bbInt invoke(t_mx2_Toker* l_x,t_mx2_Toker* l_y){
        return bbCompare(l_x,l_y);
      }
      void gcMark(){
        bbGCMarkPtr(l_self);
      }
    };
    this->m_Sort(bbFunction<bbInt(t_mx2_Toker*,t_mx2_Toker*)>(new lambda32(this)));
  }else{
    struct lambda33 : public bbFunction<bbInt(t_mx2_Toker*,t_mx2_Toker*)>::Rep{
      t_std_collections_List_1Tt_mx2_Toker_2* l_self;
      lambda33(t_std_collections_List_1Tt_mx2_Toker_2* l_self):l_self(l_self){
      }
      bbInt invoke(t_mx2_Toker* l_x,t_mx2_Toker* l_y){
        return -bbCompare(l_x,l_y);
      }
      void gcMark(){
        bbGCMarkPtr(l_self);
      }
    };
    this->m_Sort(bbFunction<bbInt(t_mx2_Toker*,t_mx2_Toker*)>(new lambda33(this)));
  }
}

t_mx2_Toker* t_std_collections_List_1Tt_mx2_Toker_2::m_RemoveLast(){
  struct f0_t : public bbGCFrame{
    t_mx2_Toker* l_value{};
    void gcMark(){
      bbGCMarkPtr(l_value);
    }
  }f0{};
  bbDebugAssert(!this->m_Empty(),BB_T("Debug assert failed"));
  f0.l_value=this->m__0head->m__0pred->m__0value;
  this->m__0head->m__0pred->m_Remove();
  this->m__0seq+=1;
  return f0.l_value;
}

bbBool t_std_collections_List_1Tt_mx2_Toker_2::m_RemoveLast(t_mx2_Toker* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_mx2_Toker_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m_FindLastNode(l_value);
  if(!bbBool(f0.l_node)){
    return false;
  }
  f0.l_node->m_Remove();
  this->m__0seq+=1;
  return true;
}

t_mx2_Toker* t_std_collections_List_1Tt_mx2_Toker_2::m_RemoveFirst(){
  struct f0_t : public bbGCFrame{
    t_mx2_Toker* l_value{};
    void gcMark(){
      bbGCMarkPtr(l_value);
    }
  }f0{};
  bbDebugAssert(!this->m_Empty(),BB_T("Debug assert failed"));
  f0.l_value=this->m__0head->m__0succ->m__0value;
  this->m__0head->m__0succ->m_Remove();
  this->m__0seq+=1;
  return f0.l_value;
}

bbInt t_std_collections_List_1Tt_mx2_Toker_2::m_RemoveEach(t_mx2_Toker* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_mx2_Toker_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m__0head->m__0succ;
  bbInt l_n=bbInt(0);
  while((f0.l_node!=this->m__0head)){
    if((f0.l_node->m__0value==l_value)){
      f0.l_node=f0.l_node->m__0succ;
      f0.l_node->m__0pred->m_Remove();
      l_n+=1;
    }else{
      f0.l_node=f0.l_node->m__0succ;
    }
  }
  if(bbBool(l_n)){
    this->m__0seq+=1;
  }
  return l_n;
}

bbBool t_std_collections_List_1Tt_mx2_Toker_2::m_Remove(t_mx2_Toker* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_mx2_Toker_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m_FindNode(l_value);
  if(!bbBool(f0.l_node)){
    return false;
  }
  f0.l_node->m_Remove();
  this->m__0seq+=1;
  return true;
}

t_std_collections_List_1Tt_mx2_Toker_2_Node* t_std_collections_List_1Tt_mx2_Toker_2::m_LastNode(){
  if(!this->m_Empty()){
    return this->m__0head->m__0pred;
  }
  return ((t_std_collections_List_1Tt_mx2_Toker_2_Node*)0);
}

t_mx2_Toker* t_std_collections_List_1Tt_mx2_Toker_2::m_Last(){
  bbDebugAssert(!this->m_Empty(),BB_T("Debug assert failed"));
  return this->m__0head->m__0pred->m__0value;
}

t_std_collections_List_1Tt_mx2_Toker_2_Node* t_std_collections_List_1Tt_mx2_Toker_2::m_HeadNode(){
  return this->m__0head;
}

t_std_collections_List_1Tt_mx2_Toker_2_Node* t_std_collections_List_1Tt_mx2_Toker_2::m_FirstNode(){
  if(!this->m_Empty()){
    return this->m__0head->m__0succ;
  }
  return ((t_std_collections_List_1Tt_mx2_Toker_2_Node*)0);
}

t_mx2_Toker* t_std_collections_List_1Tt_mx2_Toker_2::m_First(){
  bbDebugAssert(!this->m_Empty(),BB_T("Debug assert failed"));
  return this->m__0head->m__0succ->m__0value;
}

t_std_collections_List_1Tt_mx2_Toker_2_Node* t_std_collections_List_1Tt_mx2_Toker_2::m_FindNode(t_mx2_Toker* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_mx2_Toker_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m__0head->m__0succ;
  while((f0.l_node!=this->m__0head)){
    if((f0.l_node->m__0value==l_value)){
      return f0.l_node;
    }
    f0.l_node=f0.l_node->m__0succ;
  }
  return ((t_std_collections_List_1Tt_mx2_Toker_2_Node*)0);
}

t_std_collections_List_1Tt_mx2_Toker_2_Node* t_std_collections_List_1Tt_mx2_Toker_2::m_FindLastNode(t_mx2_Toker* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_mx2_Toker_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m__0head->m__0pred;
  while((f0.l_node!=this->m__0head)){
    if((f0.l_node->m__0value==l_value)){
      return f0.l_node;
    }
    f0.l_node=f0.l_node->m__0pred;
  }
  return ((t_std_collections_List_1Tt_mx2_Toker_2_Node*)0);
}

bbBool t_std_collections_List_1Tt_mx2_Toker_2::m_Empty(){
  return (this->m__0head->m__0succ==this->m__0head);
}

bbInt t_std_collections_List_1Tt_mx2_Toker_2::m_Count(){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_mx2_Toker_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m__0head->m__0succ;
  bbInt l_n=bbInt(0);
  while((f0.l_node!=this->m__0head)){
    f0.l_node=f0.l_node->m__0succ;
    l_n+=1;
  }
  return l_n;
}

void t_std_collections_List_1Tt_mx2_Toker_2::m_Clear(){
  this->m__0head->m__0succ=this->m__0head;
  this->m__0head->m__0pred=this->m__0head;
  this->m__0seq+=1;
}

t_std_collections_List_1Tt_mx2_Toker_2_BackwardsIterator t_std_collections_List_1Tt_mx2_Toker_2::m_Backwards(){
  return t_std_collections_List_1Tt_mx2_Toker_2_BackwardsIterator(this,this->m__0head->m__0pred);
}

t_std_collections_List_1Tt_mx2_Toker_2_Iterator t_std_collections_List_1Tt_mx2_Toker_2::m_All(){
  return t_std_collections_List_1Tt_mx2_Toker_2_Iterator(this,this->m__0head->m__0succ);
}

t_std_collections_List_1Tt_mx2_Toker_2_Node* t_std_collections_List_1Tt_mx2_Toker_2::m_AddLast(t_mx2_Toker* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_mx2_Toker_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=bbGCNew<t_std_collections_List_1Tt_mx2_Toker_2_Node>(l_value,this->m__0head);
  this->m__0seq+=1;
  return f0.l_node;
}

t_std_collections_List_1Tt_mx2_Toker_2_Node* t_std_collections_List_1Tt_mx2_Toker_2::m_AddFirst(t_mx2_Toker* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_mx2_Toker_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=bbGCNew<t_std_collections_List_1Tt_mx2_Toker_2_Node>(l_value,this->m__0head->m__0succ);
  this->m__0seq+=1;
  return f0.l_node;
}

void t_std_collections_List_1Tt_mx2_Toker_2::m_AddAll(bbArray<bbGCVar<t_mx2_Toker>>* l_values){
  {
    bbInt l_0=bbInt(0);
    bbInt l_1=l_values->length();
    for(;(l_0<l_1);l_0+=1){
      struct f2_t : public bbGCFrame{
        t_mx2_Toker* l_value{};
        void gcMark(){
          bbGCMarkPtr(l_value);
        }
      }f2{};
      f2.l_value=l_values->at(l_0);
      this->m_AddLast(f2.l_value);
    }
  }
}

void t_std_collections_List_1Tt_mx2_Toker_2::m_Add(t_mx2_Toker* l_value){
  this->m_AddLast(l_value);
}

void t_std_collections_List_1Tt_mx2_Stmt_2_Node::gcMark(){
  bbGCMark(m__0succ);
  bbGCMark(m__0pred);
  bbGCMark(m__0value);
}

t_std_collections_List_1Tt_mx2_Stmt_2_Node::t_std_collections_List_1Tt_mx2_Stmt_2_Node(t_mx2_Stmt* l_value,t_std_collections_List_1Tt_mx2_Stmt_2_Node* l_succ){
  this->m__0value=l_value;
  this->m__0succ=l_succ;
  this->m__0pred=l_succ->m__0pred;
  this->m__0pred->m__0succ=this;
  l_succ->m__0pred=this;
}

t_std_collections_List_1Tt_mx2_Stmt_2_Node::t_std_collections_List_1Tt_mx2_Stmt_2_Node(t_mx2_Stmt* l_value){
  this->m__0value=l_value;
  this->m__0succ=this;
  this->m__0pred=this;
}

void t_std_collections_List_1Tt_mx2_Stmt_2_Node::m_Value(t_mx2_Stmt* l_value){
  this->m__0value=l_value;
}

t_mx2_Stmt* t_std_collections_List_1Tt_mx2_Stmt_2_Node::m_Value(){
  return this->m__0value;
}

t_std_collections_List_1Tt_mx2_Stmt_2_Node* t_std_collections_List_1Tt_mx2_Stmt_2_Node::m_Succ(){
  return this->m__0succ;
}

void t_std_collections_List_1Tt_mx2_Stmt_2_Node::m_Remove(){
  this->m__0succ->m__0pred=this->m__0pred;
  this->m__0pred->m__0succ=this->m__0succ;
}

t_std_collections_List_1Tt_mx2_Stmt_2_Node* t_std_collections_List_1Tt_mx2_Stmt_2_Node::m_Pred(){
  return this->m__0pred;
}

void t_std_collections_List_1Tt_mx2_Stmt_2_Node::m_InsertBefore(t_std_collections_List_1Tt_mx2_Stmt_2_Node* l_node){
  this->m__0succ=l_node;
  this->m__0pred=l_node->m__0pred;
  this->m__0pred->m__0succ=this;
  l_node->m__0pred=this;
}

void t_std_collections_List_1Tt_mx2_Stmt_2_Node::m_InsertAfter(t_std_collections_List_1Tt_mx2_Stmt_2_Node* l_node){
  this->m__0pred=l_node;
  this->m__0succ=l_node->m__0succ;
  this->m__0succ->m__0pred=this;
  l_node->m__0succ=this;
}

t_std_collections_List_1Tt_mx2_Stmt_2_Iterator::t_std_collections_List_1Tt_mx2_Stmt_2_Iterator(t_std_collections_List_1Tt_mx2_Stmt_2* l_list,t_std_collections_List_1Tt_mx2_Stmt_2_Node* l_node){
  (*this).m__0list=l_list;
  (*this).m__0node=l_node;
  (*this).m__0seq=l_list->m__0seq;
}

void t_std_collections_List_1Tt_mx2_Stmt_2_Iterator::m_Insert(t_mx2_Stmt* l_value){
  (*this).m_AssertSeq();
  (*this).m__0node=bbGCNew<t_std_collections_List_1Tt_mx2_Stmt_2_Node>(l_value,(*this).m__0node);
  (*this).m__0list->m__0seq+=1;
  (*this).m__0seq=(*this).m__0list->m__0seq;
}

void t_std_collections_List_1Tt_mx2_Stmt_2_Iterator::m_Erase(){
  (*this).m_AssertCurrent();
  (*this).m__0node=(*this).m__0node->m__0succ;
  (*this).m__0node->m__0pred->m_Remove();
  (*this).m__0list->m__0seq+=1;
  (*this).m__0seq=(*this).m__0list->m__0seq;
}

void t_std_collections_List_1Tt_mx2_Stmt_2_Iterator::m_Current(t_mx2_Stmt* l_current){
  (*this).m_AssertCurrent();
  (*this).m__0node->m__0value=l_current;
}

t_mx2_Stmt* t_std_collections_List_1Tt_mx2_Stmt_2_Iterator::m_Current(){
  (*this).m_AssertCurrent();
  return (*this).m__0node->m__0value;
}

void t_std_collections_List_1Tt_mx2_Stmt_2_Iterator::m_Bump(){
  (*this).m_AssertCurrent();
  (*this).m__0node=(*this).m__0node->m__0succ;
}

bbBool t_std_collections_List_1Tt_mx2_Stmt_2_Iterator::m_AtEnd(){
  (*this).m_AssertSeq();
  return ((*this).m__0node==(*this).m__0list->m__0head);
}

void t_std_collections_List_1Tt_mx2_Stmt_2_Iterator::m_AssertSeq(){
  bbDebugAssert(((*this).m__0seq==(*this).m__0list->m__0seq),BB_T("Concurrent list modification"));
}

void t_std_collections_List_1Tt_mx2_Stmt_2_Iterator::m_AssertCurrent(){
  bbDebugAssert(!(*this).m_AtEnd(),BB_T("Invalid list iterator"));
}

int bbCompare(const t_std_collections_List_1Tt_mx2_Stmt_2_Iterator&x,const t_std_collections_List_1Tt_mx2_Stmt_2_Iterator&y){
  if(int t=bbCompare(x.m__0list,y.m__0list)) return t;
  if(int t=bbCompare(x.m__0node,y.m__0node)) return t;
  if(int t=bbCompare(x.m__0seq,y.m__0seq)) return t;
  return 0;
}

void bbGCMark(const t_std_collections_List_1Tt_mx2_Stmt_2_Iterator&t){
  bbGCMark(t.m__0list);
  bbGCMark(t.m__0node);
}

t_std_collections_List_1Tt_mx2_Stmt_2_BackwardsIterator::t_std_collections_List_1Tt_mx2_Stmt_2_BackwardsIterator(t_std_collections_List_1Tt_mx2_Stmt_2* l_list,t_std_collections_List_1Tt_mx2_Stmt_2_Node* l_node){
  (*this).m__0list=l_list;
  (*this).m__0node=l_node;
  (*this).m__0seq=l_list->m__0seq;
}

void t_std_collections_List_1Tt_mx2_Stmt_2_BackwardsIterator::m_Insert(t_mx2_Stmt* l_value){
  (*this).m_AssertSeq();
  (*this).m__0node=bbGCNew<t_std_collections_List_1Tt_mx2_Stmt_2_Node>(l_value,(*this).m__0node->m__0succ);
  (*this).m__0list->m__0seq+=1;
  (*this).m__0seq=(*this).m__0list->m__0seq;
}

void t_std_collections_List_1Tt_mx2_Stmt_2_BackwardsIterator::m_Erase(){
  (*this).m_AssertCurrent();
  (*this).m__0node=(*this).m__0node->m__0pred;
  (*this).m__0node->m__0succ->m_Remove();
  (*this).m__0list->m__0seq+=1;
  (*this).m__0seq=(*this).m__0list->m__0seq;
}

void t_std_collections_List_1Tt_mx2_Stmt_2_BackwardsIterator::m_Current(t_mx2_Stmt* l_current){
  (*this).m_AssertCurrent();
  (*this).m__0node->m__0value=l_current;
}

t_mx2_Stmt* t_std_collections_List_1Tt_mx2_Stmt_2_BackwardsIterator::m_Current(){
  (*this).m_AssertCurrent();
  return (*this).m__0node->m__0value;
}

void t_std_collections_List_1Tt_mx2_Stmt_2_BackwardsIterator::m_Bump(){
  (*this).m_AssertCurrent();
  (*this).m__0node=(*this).m__0node->m__0pred;
}

bbBool t_std_collections_List_1Tt_mx2_Stmt_2_BackwardsIterator::m_AtEnd(){
  (*this).m_AssertSeq();
  return ((*this).m__0node==(*this).m__0list->m__0head);
}

void t_std_collections_List_1Tt_mx2_Stmt_2_BackwardsIterator::m_AssertSeq(){
  bbDebugAssert(((*this).m__0seq==(*this).m__0list->m__0seq),BB_T("Concurrent list modification"));
}

void t_std_collections_List_1Tt_mx2_Stmt_2_BackwardsIterator::m_AssertCurrent(){
  bbDebugAssert(!(*this).m_AtEnd(),BB_T("Invalid list iterator"));
}

int bbCompare(const t_std_collections_List_1Tt_mx2_Stmt_2_BackwardsIterator&x,const t_std_collections_List_1Tt_mx2_Stmt_2_BackwardsIterator&y){
  if(int t=bbCompare(x.m__0list,y.m__0list)) return t;
  if(int t=bbCompare(x.m__0node,y.m__0node)) return t;
  if(int t=bbCompare(x.m__0seq,y.m__0seq)) return t;
  return 0;
}

void bbGCMark(const t_std_collections_List_1Tt_mx2_Stmt_2_BackwardsIterator&t){
  bbGCMark(t.m__0list);
  bbGCMark(t.m__0node);
}

void t_std_collections_List_1Tt_mx2_Stmt_2::gcMark(){
  bbGCMark(m__0head);
}

t_std_collections_List_1Tt_mx2_Stmt_2::t_std_collections_List_1Tt_mx2_Stmt_2(t_std_collections_List_1Tt_mx2_Stmt_2* l_values):t_std_collections_List_1Tt_mx2_Stmt_2(){
  g_std_collections_List_1Tt_mx2_Stmt_2_AddAll_1Tt_std_collections_List_1Tt_mx2_Stmt_2_2(this,l_values);
}

t_std_collections_List_1Tt_mx2_Stmt_2::t_std_collections_List_1Tt_mx2_Stmt_2(t_std_collections_Stack_1Tt_mx2_Stmt_2* l_values):t_std_collections_List_1Tt_mx2_Stmt_2(){
  g_std_collections_List_1Tt_mx2_Stmt_2_AddAll_1Tt_std_collections_Stack_1Tt_mx2_Stmt_2_2(this,l_values);
}

t_std_collections_List_1Tt_mx2_Stmt_2::t_std_collections_List_1Tt_mx2_Stmt_2(bbArray<bbGCVar<t_mx2_Stmt>>* l_values):t_std_collections_List_1Tt_mx2_Stmt_2(){
  this->m_AddAll(l_values);
}

t_std_collections_List_1Tt_mx2_Stmt_2::t_std_collections_List_1Tt_mx2_Stmt_2(){
  this->m__0head=bbGCNew<t_std_collections_List_1Tt_mx2_Stmt_2_Node>(((t_mx2_Stmt*)0));
}

bbArray<bbGCVar<t_mx2_Stmt>>* t_std_collections_List_1Tt_mx2_Stmt_2::m_ToArray(){
  struct f0_t : public bbGCFrame{
    bbArray<bbGCVar<t_mx2_Stmt>>* l_data{};
    t_std_collections_List_1Tt_mx2_Stmt_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_data);
      bbGCMarkPtr(l_node);
    }
  }f0{};
  bbInt l_n=this->m_Count();
  f0.l_data=bbArray<bbGCVar<t_mx2_Stmt>>::create(l_n);
  f0.l_node=this->m__0head->m__0succ;
  {
    bbInt l_i=bbInt(0);
    for(;(l_i<l_n);l_i+=1){
      f0.l_data->at(l_i)=f0.l_node->m__0value;
      f0.l_node=f0.l_node->m__0succ;
    }
  }
  return f0.l_data;
}

void t_std_collections_List_1Tt_mx2_Stmt_2::m_Sort(bbFunction<bbInt(t_mx2_Stmt*,t_mx2_Stmt*)> l_compareFunc){
  bbInt l_insize=1;
  for(;;){
    struct f1_t : public bbGCFrame{
      t_std_collections_List_1Tt_mx2_Stmt_2_Node* l_p{};
      t_std_collections_List_1Tt_mx2_Stmt_2_Node* l_tail{};
      void gcMark(){
        bbGCMarkPtr(l_p);
        bbGCMarkPtr(l_tail);
      }
    }f1{};
    bbInt l_merges=bbInt(0);
    f1.l_tail=this->m__0head;
    f1.l_p=this->m__0head->m__0succ;
    while((f1.l_p!=this->m__0head)){
      struct f2_t : public bbGCFrame{
        t_std_collections_List_1Tt_mx2_Stmt_2_Node* l_q{};
        void gcMark(){
          bbGCMarkPtr(l_q);
        }
      }f2{};
      l_merges+=1;
      f2.l_q=f1.l_p->m__0succ;
      bbInt l_qsize=l_insize;
      bbInt l_psize=1;
      while(((l_psize<l_insize)&&(f2.l_q!=this->m__0head))){
        l_psize+=1;
        f2.l_q=f2.l_q->m__0succ;
      }
      for(;;){
        struct f3_t : public bbGCFrame{
          t_std_collections_List_1Tt_mx2_Stmt_2_Node* l_t{};
          void gcMark(){
            bbGCMarkPtr(l_t);
          }
        }f3{};
        if(((bbBool(l_psize)&&bbBool(l_qsize))&&(f2.l_q!=this->m__0head))){
          bbInt l_cc=l_compareFunc(f1.l_p->m__0value,f2.l_q->m__0value);
          if((l_cc<=bbInt(0))){
            f3.l_t=f1.l_p;
            f1.l_p=f1.l_p->m__0succ;
            l_psize-=1;
          }else{
            f3.l_t=f2.l_q;
            f2.l_q=f2.l_q->m__0succ;
            l_qsize-=1;
          }
        }else if(bbBool(l_psize)){
          f3.l_t=f1.l_p;
          f1.l_p=f1.l_p->m__0succ;
          l_psize-=1;
        }else if((bbBool(l_qsize)&&(f2.l_q!=this->m__0head))){
          f3.l_t=f2.l_q;
          f2.l_q=f2.l_q->m__0succ;
          l_qsize-=1;
        }else{
          break;
        }
        f3.l_t->m__0pred=f1.l_tail;
        f1.l_tail->m__0succ=f3.l_t;
        f1.l_tail=f3.l_t;
      }
      f1.l_p=f2.l_q;
    }
    f1.l_tail->m__0succ=this->m__0head;
    this->m__0head->m__0pred=f1.l_tail;
    if((l_merges<=1)){
      return;
    }
    l_insize*=2;
  }
}

void t_std_collections_List_1Tt_mx2_Stmt_2::m_Sort(bbBool l_ascending){
  if(l_ascending){
    struct lambda34 : public bbFunction<bbInt(t_mx2_Stmt*,t_mx2_Stmt*)>::Rep{
      t_std_collections_List_1Tt_mx2_Stmt_2* l_self;
      lambda34(t_std_collections_List_1Tt_mx2_Stmt_2* l_self):l_self(l_self){
      }
      bbInt invoke(t_mx2_Stmt* l_x,t_mx2_Stmt* l_y){
        return bbCompare(l_x,l_y);
      }
      void gcMark(){
        bbGCMarkPtr(l_self);
      }
    };
    this->m_Sort(bbFunction<bbInt(t_mx2_Stmt*,t_mx2_Stmt*)>(new lambda34(this)));
  }else{
    struct lambda35 : public bbFunction<bbInt(t_mx2_Stmt*,t_mx2_Stmt*)>::Rep{
      t_std_collections_List_1Tt_mx2_Stmt_2* l_self;
      lambda35(t_std_collections_List_1Tt_mx2_Stmt_2* l_self):l_self(l_self){
      }
      bbInt invoke(t_mx2_Stmt* l_x,t_mx2_Stmt* l_y){
        return -bbCompare(l_x,l_y);
      }
      void gcMark(){
        bbGCMarkPtr(l_self);
      }
    };
    this->m_Sort(bbFunction<bbInt(t_mx2_Stmt*,t_mx2_Stmt*)>(new lambda35(this)));
  }
}

t_mx2_Stmt* t_std_collections_List_1Tt_mx2_Stmt_2::m_RemoveLast(){
  struct f0_t : public bbGCFrame{
    t_mx2_Stmt* l_value{};
    void gcMark(){
      bbGCMarkPtr(l_value);
    }
  }f0{};
  bbDebugAssert(!this->m_Empty(),BB_T("Debug assert failed"));
  f0.l_value=this->m__0head->m__0pred->m__0value;
  this->m__0head->m__0pred->m_Remove();
  this->m__0seq+=1;
  return f0.l_value;
}

bbBool t_std_collections_List_1Tt_mx2_Stmt_2::m_RemoveLast(t_mx2_Stmt* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_mx2_Stmt_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m_FindLastNode(l_value);
  if(!bbBool(f0.l_node)){
    return false;
  }
  f0.l_node->m_Remove();
  this->m__0seq+=1;
  return true;
}

t_mx2_Stmt* t_std_collections_List_1Tt_mx2_Stmt_2::m_RemoveFirst(){
  struct f0_t : public bbGCFrame{
    t_mx2_Stmt* l_value{};
    void gcMark(){
      bbGCMarkPtr(l_value);
    }
  }f0{};
  bbDebugAssert(!this->m_Empty(),BB_T("Debug assert failed"));
  f0.l_value=this->m__0head->m__0succ->m__0value;
  this->m__0head->m__0succ->m_Remove();
  this->m__0seq+=1;
  return f0.l_value;
}

bbInt t_std_collections_List_1Tt_mx2_Stmt_2::m_RemoveEach(t_mx2_Stmt* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_mx2_Stmt_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m__0head->m__0succ;
  bbInt l_n=bbInt(0);
  while((f0.l_node!=this->m__0head)){
    if((f0.l_node->m__0value==l_value)){
      f0.l_node=f0.l_node->m__0succ;
      f0.l_node->m__0pred->m_Remove();
      l_n+=1;
    }else{
      f0.l_node=f0.l_node->m__0succ;
    }
  }
  if(bbBool(l_n)){
    this->m__0seq+=1;
  }
  return l_n;
}

bbBool t_std_collections_List_1Tt_mx2_Stmt_2::m_Remove(t_mx2_Stmt* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_mx2_Stmt_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m_FindNode(l_value);
  if(!bbBool(f0.l_node)){
    return false;
  }
  f0.l_node->m_Remove();
  this->m__0seq+=1;
  return true;
}

t_std_collections_List_1Tt_mx2_Stmt_2_Node* t_std_collections_List_1Tt_mx2_Stmt_2::m_LastNode(){
  if(!this->m_Empty()){
    return this->m__0head->m__0pred;
  }
  return ((t_std_collections_List_1Tt_mx2_Stmt_2_Node*)0);
}

t_mx2_Stmt* t_std_collections_List_1Tt_mx2_Stmt_2::m_Last(){
  bbDebugAssert(!this->m_Empty(),BB_T("Debug assert failed"));
  return this->m__0head->m__0pred->m__0value;
}

t_std_collections_List_1Tt_mx2_Stmt_2_Node* t_std_collections_List_1Tt_mx2_Stmt_2::m_HeadNode(){
  return this->m__0head;
}

t_std_collections_List_1Tt_mx2_Stmt_2_Node* t_std_collections_List_1Tt_mx2_Stmt_2::m_FirstNode(){
  if(!this->m_Empty()){
    return this->m__0head->m__0succ;
  }
  return ((t_std_collections_List_1Tt_mx2_Stmt_2_Node*)0);
}

t_mx2_Stmt* t_std_collections_List_1Tt_mx2_Stmt_2::m_First(){
  bbDebugAssert(!this->m_Empty(),BB_T("Debug assert failed"));
  return this->m__0head->m__0succ->m__0value;
}

t_std_collections_List_1Tt_mx2_Stmt_2_Node* t_std_collections_List_1Tt_mx2_Stmt_2::m_FindNode(t_mx2_Stmt* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_mx2_Stmt_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m__0head->m__0succ;
  while((f0.l_node!=this->m__0head)){
    if((f0.l_node->m__0value==l_value)){
      return f0.l_node;
    }
    f0.l_node=f0.l_node->m__0succ;
  }
  return ((t_std_collections_List_1Tt_mx2_Stmt_2_Node*)0);
}

t_std_collections_List_1Tt_mx2_Stmt_2_Node* t_std_collections_List_1Tt_mx2_Stmt_2::m_FindLastNode(t_mx2_Stmt* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_mx2_Stmt_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m__0head->m__0pred;
  while((f0.l_node!=this->m__0head)){
    if((f0.l_node->m__0value==l_value)){
      return f0.l_node;
    }
    f0.l_node=f0.l_node->m__0pred;
  }
  return ((t_std_collections_List_1Tt_mx2_Stmt_2_Node*)0);
}

bbBool t_std_collections_List_1Tt_mx2_Stmt_2::m_Empty(){
  return (this->m__0head->m__0succ==this->m__0head);
}

bbInt t_std_collections_List_1Tt_mx2_Stmt_2::m_Count(){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_mx2_Stmt_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m__0head->m__0succ;
  bbInt l_n=bbInt(0);
  while((f0.l_node!=this->m__0head)){
    f0.l_node=f0.l_node->m__0succ;
    l_n+=1;
  }
  return l_n;
}

void t_std_collections_List_1Tt_mx2_Stmt_2::m_Clear(){
  this->m__0head->m__0succ=this->m__0head;
  this->m__0head->m__0pred=this->m__0head;
  this->m__0seq+=1;
}

t_std_collections_List_1Tt_mx2_Stmt_2_BackwardsIterator t_std_collections_List_1Tt_mx2_Stmt_2::m_Backwards(){
  return t_std_collections_List_1Tt_mx2_Stmt_2_BackwardsIterator(this,this->m__0head->m__0pred);
}

t_std_collections_List_1Tt_mx2_Stmt_2_Iterator t_std_collections_List_1Tt_mx2_Stmt_2::m_All(){
  return t_std_collections_List_1Tt_mx2_Stmt_2_Iterator(this,this->m__0head->m__0succ);
}

t_std_collections_List_1Tt_mx2_Stmt_2_Node* t_std_collections_List_1Tt_mx2_Stmt_2::m_AddLast(t_mx2_Stmt* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_mx2_Stmt_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=bbGCNew<t_std_collections_List_1Tt_mx2_Stmt_2_Node>(l_value,this->m__0head);
  this->m__0seq+=1;
  return f0.l_node;
}

t_std_collections_List_1Tt_mx2_Stmt_2_Node* t_std_collections_List_1Tt_mx2_Stmt_2::m_AddFirst(t_mx2_Stmt* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_mx2_Stmt_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=bbGCNew<t_std_collections_List_1Tt_mx2_Stmt_2_Node>(l_value,this->m__0head->m__0succ);
  this->m__0seq+=1;
  return f0.l_node;
}

void t_std_collections_List_1Tt_mx2_Stmt_2::m_AddAll(bbArray<bbGCVar<t_mx2_Stmt>>* l_values){
  {
    bbInt l_0=bbInt(0);
    bbInt l_1=l_values->length();
    for(;(l_0<l_1);l_0+=1){
      struct f2_t : public bbGCFrame{
        t_mx2_Stmt* l_value{};
        void gcMark(){
          bbGCMarkPtr(l_value);
        }
      }f2{};
      f2.l_value=l_values->at(l_0);
      this->m_AddLast(f2.l_value);
    }
  }
}

void t_std_collections_List_1Tt_mx2_Stmt_2::m_Add(t_mx2_Stmt* l_value){
  this->m_AddLast(l_value);
}

void t_std_collections_List_1Tt_mx2_Translator_GCTmp_2_Node::gcMark(){
  bbGCMark(m__0succ);
  bbGCMark(m__0pred);
  bbGCMark(m__0value);
}

t_std_collections_List_1Tt_mx2_Translator_GCTmp_2_Node::t_std_collections_List_1Tt_mx2_Translator_GCTmp_2_Node(t_mx2_Translator_GCTmp* l_value,t_std_collections_List_1Tt_mx2_Translator_GCTmp_2_Node* l_succ){
  this->m__0value=l_value;
  this->m__0succ=l_succ;
  this->m__0pred=l_succ->m__0pred;
  this->m__0pred->m__0succ=this;
  l_succ->m__0pred=this;
}

t_std_collections_List_1Tt_mx2_Translator_GCTmp_2_Node::t_std_collections_List_1Tt_mx2_Translator_GCTmp_2_Node(t_mx2_Translator_GCTmp* l_value){
  this->m__0value=l_value;
  this->m__0succ=this;
  this->m__0pred=this;
}

void t_std_collections_List_1Tt_mx2_Translator_GCTmp_2_Node::m_Value(t_mx2_Translator_GCTmp* l_value){
  this->m__0value=l_value;
}

t_mx2_Translator_GCTmp* t_std_collections_List_1Tt_mx2_Translator_GCTmp_2_Node::m_Value(){
  return this->m__0value;
}

t_std_collections_List_1Tt_mx2_Translator_GCTmp_2_Node* t_std_collections_List_1Tt_mx2_Translator_GCTmp_2_Node::m_Succ(){
  return this->m__0succ;
}

void t_std_collections_List_1Tt_mx2_Translator_GCTmp_2_Node::m_Remove(){
  this->m__0succ->m__0pred=this->m__0pred;
  this->m__0pred->m__0succ=this->m__0succ;
}

t_std_collections_List_1Tt_mx2_Translator_GCTmp_2_Node* t_std_collections_List_1Tt_mx2_Translator_GCTmp_2_Node::m_Pred(){
  return this->m__0pred;
}

void t_std_collections_List_1Tt_mx2_Translator_GCTmp_2_Node::m_InsertBefore(t_std_collections_List_1Tt_mx2_Translator_GCTmp_2_Node* l_node){
  this->m__0succ=l_node;
  this->m__0pred=l_node->m__0pred;
  this->m__0pred->m__0succ=this;
  l_node->m__0pred=this;
}

void t_std_collections_List_1Tt_mx2_Translator_GCTmp_2_Node::m_InsertAfter(t_std_collections_List_1Tt_mx2_Translator_GCTmp_2_Node* l_node){
  this->m__0pred=l_node;
  this->m__0succ=l_node->m__0succ;
  this->m__0succ->m__0pred=this;
  l_node->m__0succ=this;
}

t_std_collections_List_1Tt_mx2_Translator_GCTmp_2_Iterator::t_std_collections_List_1Tt_mx2_Translator_GCTmp_2_Iterator(t_std_collections_List_1Tt_mx2_Translator_GCTmp_2* l_list,t_std_collections_List_1Tt_mx2_Translator_GCTmp_2_Node* l_node){
  (*this).m__0list=l_list;
  (*this).m__0node=l_node;
  (*this).m__0seq=l_list->m__0seq;
}

void t_std_collections_List_1Tt_mx2_Translator_GCTmp_2_Iterator::m_Insert(t_mx2_Translator_GCTmp* l_value){
  (*this).m_AssertSeq();
  (*this).m__0node=bbGCNew<t_std_collections_List_1Tt_mx2_Translator_GCTmp_2_Node>(l_value,(*this).m__0node);
  (*this).m__0list->m__0seq+=1;
  (*this).m__0seq=(*this).m__0list->m__0seq;
}

void t_std_collections_List_1Tt_mx2_Translator_GCTmp_2_Iterator::m_Erase(){
  (*this).m_AssertCurrent();
  (*this).m__0node=(*this).m__0node->m__0succ;
  (*this).m__0node->m__0pred->m_Remove();
  (*this).m__0list->m__0seq+=1;
  (*this).m__0seq=(*this).m__0list->m__0seq;
}

void t_std_collections_List_1Tt_mx2_Translator_GCTmp_2_Iterator::m_Current(t_mx2_Translator_GCTmp* l_current){
  (*this).m_AssertCurrent();
  (*this).m__0node->m__0value=l_current;
}

t_mx2_Translator_GCTmp* t_std_collections_List_1Tt_mx2_Translator_GCTmp_2_Iterator::m_Current(){
  (*this).m_AssertCurrent();
  return (*this).m__0node->m__0value;
}

void t_std_collections_List_1Tt_mx2_Translator_GCTmp_2_Iterator::m_Bump(){
  (*this).m_AssertCurrent();
  (*this).m__0node=(*this).m__0node->m__0succ;
}

bbBool t_std_collections_List_1Tt_mx2_Translator_GCTmp_2_Iterator::m_AtEnd(){
  (*this).m_AssertSeq();
  return ((*this).m__0node==(*this).m__0list->m__0head);
}

void t_std_collections_List_1Tt_mx2_Translator_GCTmp_2_Iterator::m_AssertSeq(){
  bbDebugAssert(((*this).m__0seq==(*this).m__0list->m__0seq),BB_T("Concurrent list modification"));
}

void t_std_collections_List_1Tt_mx2_Translator_GCTmp_2_Iterator::m_AssertCurrent(){
  bbDebugAssert(!(*this).m_AtEnd(),BB_T("Invalid list iterator"));
}

int bbCompare(const t_std_collections_List_1Tt_mx2_Translator_GCTmp_2_Iterator&x,const t_std_collections_List_1Tt_mx2_Translator_GCTmp_2_Iterator&y){
  if(int t=bbCompare(x.m__0list,y.m__0list)) return t;
  if(int t=bbCompare(x.m__0node,y.m__0node)) return t;
  if(int t=bbCompare(x.m__0seq,y.m__0seq)) return t;
  return 0;
}

void bbGCMark(const t_std_collections_List_1Tt_mx2_Translator_GCTmp_2_Iterator&t){
  bbGCMark(t.m__0list);
  bbGCMark(t.m__0node);
}

t_std_collections_List_1Tt_mx2_Translator_GCTmp_2_BackwardsIterator::t_std_collections_List_1Tt_mx2_Translator_GCTmp_2_BackwardsIterator(t_std_collections_List_1Tt_mx2_Translator_GCTmp_2* l_list,t_std_collections_List_1Tt_mx2_Translator_GCTmp_2_Node* l_node){
  (*this).m__0list=l_list;
  (*this).m__0node=l_node;
  (*this).m__0seq=l_list->m__0seq;
}

void t_std_collections_List_1Tt_mx2_Translator_GCTmp_2_BackwardsIterator::m_Insert(t_mx2_Translator_GCTmp* l_value){
  (*this).m_AssertSeq();
  (*this).m__0node=bbGCNew<t_std_collections_List_1Tt_mx2_Translator_GCTmp_2_Node>(l_value,(*this).m__0node->m__0succ);
  (*this).m__0list->m__0seq+=1;
  (*this).m__0seq=(*this).m__0list->m__0seq;
}

void t_std_collections_List_1Tt_mx2_Translator_GCTmp_2_BackwardsIterator::m_Erase(){
  (*this).m_AssertCurrent();
  (*this).m__0node=(*this).m__0node->m__0pred;
  (*this).m__0node->m__0succ->m_Remove();
  (*this).m__0list->m__0seq+=1;
  (*this).m__0seq=(*this).m__0list->m__0seq;
}

void t_std_collections_List_1Tt_mx2_Translator_GCTmp_2_BackwardsIterator::m_Current(t_mx2_Translator_GCTmp* l_current){
  (*this).m_AssertCurrent();
  (*this).m__0node->m__0value=l_current;
}

t_mx2_Translator_GCTmp* t_std_collections_List_1Tt_mx2_Translator_GCTmp_2_BackwardsIterator::m_Current(){
  (*this).m_AssertCurrent();
  return (*this).m__0node->m__0value;
}

void t_std_collections_List_1Tt_mx2_Translator_GCTmp_2_BackwardsIterator::m_Bump(){
  (*this).m_AssertCurrent();
  (*this).m__0node=(*this).m__0node->m__0pred;
}

bbBool t_std_collections_List_1Tt_mx2_Translator_GCTmp_2_BackwardsIterator::m_AtEnd(){
  (*this).m_AssertSeq();
  return ((*this).m__0node==(*this).m__0list->m__0head);
}

void t_std_collections_List_1Tt_mx2_Translator_GCTmp_2_BackwardsIterator::m_AssertSeq(){
  bbDebugAssert(((*this).m__0seq==(*this).m__0list->m__0seq),BB_T("Concurrent list modification"));
}

void t_std_collections_List_1Tt_mx2_Translator_GCTmp_2_BackwardsIterator::m_AssertCurrent(){
  bbDebugAssert(!(*this).m_AtEnd(),BB_T("Invalid list iterator"));
}

int bbCompare(const t_std_collections_List_1Tt_mx2_Translator_GCTmp_2_BackwardsIterator&x,const t_std_collections_List_1Tt_mx2_Translator_GCTmp_2_BackwardsIterator&y){
  if(int t=bbCompare(x.m__0list,y.m__0list)) return t;
  if(int t=bbCompare(x.m__0node,y.m__0node)) return t;
  if(int t=bbCompare(x.m__0seq,y.m__0seq)) return t;
  return 0;
}

void bbGCMark(const t_std_collections_List_1Tt_mx2_Translator_GCTmp_2_BackwardsIterator&t){
  bbGCMark(t.m__0list);
  bbGCMark(t.m__0node);
}

void t_std_collections_List_1Tt_mx2_Translator_GCTmp_2::gcMark(){
  bbGCMark(m__0head);
}

t_std_collections_List_1Tt_mx2_Translator_GCTmp_2::t_std_collections_List_1Tt_mx2_Translator_GCTmp_2(t_std_collections_List_1Tt_mx2_Translator_GCTmp_2* l_values):t_std_collections_List_1Tt_mx2_Translator_GCTmp_2(){
  g_std_collections_List_1Tt_mx2_Translator_GCTmp_2_AddAll_1Tt_std_collections_List_1Tt_mx2_Translator_GCTmp_2_2(this,l_values);
}

t_std_collections_List_1Tt_mx2_Translator_GCTmp_2::t_std_collections_List_1Tt_mx2_Translator_GCTmp_2(t_std_collections_Stack_1Tt_mx2_Translator_GCTmp_2* l_values):t_std_collections_List_1Tt_mx2_Translator_GCTmp_2(){
  g_std_collections_List_1Tt_mx2_Translator_GCTmp_2_AddAll_1Tt_std_collections_Stack_1Tt_mx2_Translator_GCTmp_2_2(this,l_values);
}

t_std_collections_List_1Tt_mx2_Translator_GCTmp_2::t_std_collections_List_1Tt_mx2_Translator_GCTmp_2(bbArray<bbGCVar<t_mx2_Translator_GCTmp>>* l_values):t_std_collections_List_1Tt_mx2_Translator_GCTmp_2(){
  this->m_AddAll(l_values);
}

t_std_collections_List_1Tt_mx2_Translator_GCTmp_2::t_std_collections_List_1Tt_mx2_Translator_GCTmp_2(){
  this->m__0head=bbGCNew<t_std_collections_List_1Tt_mx2_Translator_GCTmp_2_Node>(((t_mx2_Translator_GCTmp*)0));
}

bbArray<bbGCVar<t_mx2_Translator_GCTmp>>* t_std_collections_List_1Tt_mx2_Translator_GCTmp_2::m_ToArray(){
  struct f0_t : public bbGCFrame{
    bbArray<bbGCVar<t_mx2_Translator_GCTmp>>* l_data{};
    t_std_collections_List_1Tt_mx2_Translator_GCTmp_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_data);
      bbGCMarkPtr(l_node);
    }
  }f0{};
  bbInt l_n=this->m_Count();
  f0.l_data=bbArray<bbGCVar<t_mx2_Translator_GCTmp>>::create(l_n);
  f0.l_node=this->m__0head->m__0succ;
  {
    bbInt l_i=bbInt(0);
    for(;(l_i<l_n);l_i+=1){
      f0.l_data->at(l_i)=f0.l_node->m__0value;
      f0.l_node=f0.l_node->m__0succ;
    }
  }
  return f0.l_data;
}

void t_std_collections_List_1Tt_mx2_Translator_GCTmp_2::m_Sort(bbFunction<bbInt(t_mx2_Translator_GCTmp*,t_mx2_Translator_GCTmp*)> l_compareFunc){
  bbInt l_insize=1;
  for(;;){
    struct f1_t : public bbGCFrame{
      t_std_collections_List_1Tt_mx2_Translator_GCTmp_2_Node* l_p{};
      t_std_collections_List_1Tt_mx2_Translator_GCTmp_2_Node* l_tail{};
      void gcMark(){
        bbGCMarkPtr(l_p);
        bbGCMarkPtr(l_tail);
      }
    }f1{};
    bbInt l_merges=bbInt(0);
    f1.l_tail=this->m__0head;
    f1.l_p=this->m__0head->m__0succ;
    while((f1.l_p!=this->m__0head)){
      struct f2_t : public bbGCFrame{
        t_std_collections_List_1Tt_mx2_Translator_GCTmp_2_Node* l_q{};
        void gcMark(){
          bbGCMarkPtr(l_q);
        }
      }f2{};
      l_merges+=1;
      f2.l_q=f1.l_p->m__0succ;
      bbInt l_qsize=l_insize;
      bbInt l_psize=1;
      while(((l_psize<l_insize)&&(f2.l_q!=this->m__0head))){
        l_psize+=1;
        f2.l_q=f2.l_q->m__0succ;
      }
      for(;;){
        struct f3_t : public bbGCFrame{
          t_std_collections_List_1Tt_mx2_Translator_GCTmp_2_Node* l_t{};
          void gcMark(){
            bbGCMarkPtr(l_t);
          }
        }f3{};
        if(((bbBool(l_psize)&&bbBool(l_qsize))&&(f2.l_q!=this->m__0head))){
          bbInt l_cc=l_compareFunc(f1.l_p->m__0value,f2.l_q->m__0value);
          if((l_cc<=bbInt(0))){
            f3.l_t=f1.l_p;
            f1.l_p=f1.l_p->m__0succ;
            l_psize-=1;
          }else{
            f3.l_t=f2.l_q;
            f2.l_q=f2.l_q->m__0succ;
            l_qsize-=1;
          }
        }else if(bbBool(l_psize)){
          f3.l_t=f1.l_p;
          f1.l_p=f1.l_p->m__0succ;
          l_psize-=1;
        }else if((bbBool(l_qsize)&&(f2.l_q!=this->m__0head))){
          f3.l_t=f2.l_q;
          f2.l_q=f2.l_q->m__0succ;
          l_qsize-=1;
        }else{
          break;
        }
        f3.l_t->m__0pred=f1.l_tail;
        f1.l_tail->m__0succ=f3.l_t;
        f1.l_tail=f3.l_t;
      }
      f1.l_p=f2.l_q;
    }
    f1.l_tail->m__0succ=this->m__0head;
    this->m__0head->m__0pred=f1.l_tail;
    if((l_merges<=1)){
      return;
    }
    l_insize*=2;
  }
}

void t_std_collections_List_1Tt_mx2_Translator_GCTmp_2::m_Sort(bbBool l_ascending){
  if(l_ascending){
    struct lambda36 : public bbFunction<bbInt(t_mx2_Translator_GCTmp*,t_mx2_Translator_GCTmp*)>::Rep{
      t_std_collections_List_1Tt_mx2_Translator_GCTmp_2* l_self;
      lambda36(t_std_collections_List_1Tt_mx2_Translator_GCTmp_2* l_self):l_self(l_self){
      }
      bbInt invoke(t_mx2_Translator_GCTmp* l_x,t_mx2_Translator_GCTmp* l_y){
        return bbCompare(l_x,l_y);
      }
      void gcMark(){
        bbGCMarkPtr(l_self);
      }
    };
    this->m_Sort(bbFunction<bbInt(t_mx2_Translator_GCTmp*,t_mx2_Translator_GCTmp*)>(new lambda36(this)));
  }else{
    struct lambda37 : public bbFunction<bbInt(t_mx2_Translator_GCTmp*,t_mx2_Translator_GCTmp*)>::Rep{
      t_std_collections_List_1Tt_mx2_Translator_GCTmp_2* l_self;
      lambda37(t_std_collections_List_1Tt_mx2_Translator_GCTmp_2* l_self):l_self(l_self){
      }
      bbInt invoke(t_mx2_Translator_GCTmp* l_x,t_mx2_Translator_GCTmp* l_y){
        return -bbCompare(l_x,l_y);
      }
      void gcMark(){
        bbGCMarkPtr(l_self);
      }
    };
    this->m_Sort(bbFunction<bbInt(t_mx2_Translator_GCTmp*,t_mx2_Translator_GCTmp*)>(new lambda37(this)));
  }
}

t_mx2_Translator_GCTmp* t_std_collections_List_1Tt_mx2_Translator_GCTmp_2::m_RemoveLast(){
  struct f0_t : public bbGCFrame{
    t_mx2_Translator_GCTmp* l_value{};
    void gcMark(){
      bbGCMarkPtr(l_value);
    }
  }f0{};
  bbDebugAssert(!this->m_Empty(),BB_T("Debug assert failed"));
  f0.l_value=this->m__0head->m__0pred->m__0value;
  this->m__0head->m__0pred->m_Remove();
  this->m__0seq+=1;
  return f0.l_value;
}

bbBool t_std_collections_List_1Tt_mx2_Translator_GCTmp_2::m_RemoveLast(t_mx2_Translator_GCTmp* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_mx2_Translator_GCTmp_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m_FindLastNode(l_value);
  if(!bbBool(f0.l_node)){
    return false;
  }
  f0.l_node->m_Remove();
  this->m__0seq+=1;
  return true;
}

t_mx2_Translator_GCTmp* t_std_collections_List_1Tt_mx2_Translator_GCTmp_2::m_RemoveFirst(){
  struct f0_t : public bbGCFrame{
    t_mx2_Translator_GCTmp* l_value{};
    void gcMark(){
      bbGCMarkPtr(l_value);
    }
  }f0{};
  bbDebugAssert(!this->m_Empty(),BB_T("Debug assert failed"));
  f0.l_value=this->m__0head->m__0succ->m__0value;
  this->m__0head->m__0succ->m_Remove();
  this->m__0seq+=1;
  return f0.l_value;
}

bbInt t_std_collections_List_1Tt_mx2_Translator_GCTmp_2::m_RemoveEach(t_mx2_Translator_GCTmp* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_mx2_Translator_GCTmp_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m__0head->m__0succ;
  bbInt l_n=bbInt(0);
  while((f0.l_node!=this->m__0head)){
    if((f0.l_node->m__0value==l_value)){
      f0.l_node=f0.l_node->m__0succ;
      f0.l_node->m__0pred->m_Remove();
      l_n+=1;
    }else{
      f0.l_node=f0.l_node->m__0succ;
    }
  }
  if(bbBool(l_n)){
    this->m__0seq+=1;
  }
  return l_n;
}

bbBool t_std_collections_List_1Tt_mx2_Translator_GCTmp_2::m_Remove(t_mx2_Translator_GCTmp* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_mx2_Translator_GCTmp_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m_FindNode(l_value);
  if(!bbBool(f0.l_node)){
    return false;
  }
  f0.l_node->m_Remove();
  this->m__0seq+=1;
  return true;
}

t_std_collections_List_1Tt_mx2_Translator_GCTmp_2_Node* t_std_collections_List_1Tt_mx2_Translator_GCTmp_2::m_LastNode(){
  if(!this->m_Empty()){
    return this->m__0head->m__0pred;
  }
  return ((t_std_collections_List_1Tt_mx2_Translator_GCTmp_2_Node*)0);
}

t_mx2_Translator_GCTmp* t_std_collections_List_1Tt_mx2_Translator_GCTmp_2::m_Last(){
  bbDebugAssert(!this->m_Empty(),BB_T("Debug assert failed"));
  return this->m__0head->m__0pred->m__0value;
}

t_std_collections_List_1Tt_mx2_Translator_GCTmp_2_Node* t_std_collections_List_1Tt_mx2_Translator_GCTmp_2::m_HeadNode(){
  return this->m__0head;
}

t_std_collections_List_1Tt_mx2_Translator_GCTmp_2_Node* t_std_collections_List_1Tt_mx2_Translator_GCTmp_2::m_FirstNode(){
  if(!this->m_Empty()){
    return this->m__0head->m__0succ;
  }
  return ((t_std_collections_List_1Tt_mx2_Translator_GCTmp_2_Node*)0);
}

t_mx2_Translator_GCTmp* t_std_collections_List_1Tt_mx2_Translator_GCTmp_2::m_First(){
  bbDebugAssert(!this->m_Empty(),BB_T("Debug assert failed"));
  return this->m__0head->m__0succ->m__0value;
}

t_std_collections_List_1Tt_mx2_Translator_GCTmp_2_Node* t_std_collections_List_1Tt_mx2_Translator_GCTmp_2::m_FindNode(t_mx2_Translator_GCTmp* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_mx2_Translator_GCTmp_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m__0head->m__0succ;
  while((f0.l_node!=this->m__0head)){
    if((f0.l_node->m__0value==l_value)){
      return f0.l_node;
    }
    f0.l_node=f0.l_node->m__0succ;
  }
  return ((t_std_collections_List_1Tt_mx2_Translator_GCTmp_2_Node*)0);
}

t_std_collections_List_1Tt_mx2_Translator_GCTmp_2_Node* t_std_collections_List_1Tt_mx2_Translator_GCTmp_2::m_FindLastNode(t_mx2_Translator_GCTmp* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_mx2_Translator_GCTmp_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m__0head->m__0pred;
  while((f0.l_node!=this->m__0head)){
    if((f0.l_node->m__0value==l_value)){
      return f0.l_node;
    }
    f0.l_node=f0.l_node->m__0pred;
  }
  return ((t_std_collections_List_1Tt_mx2_Translator_GCTmp_2_Node*)0);
}

bbBool t_std_collections_List_1Tt_mx2_Translator_GCTmp_2::m_Empty(){
  return (this->m__0head->m__0succ==this->m__0head);
}

bbInt t_std_collections_List_1Tt_mx2_Translator_GCTmp_2::m_Count(){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_mx2_Translator_GCTmp_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m__0head->m__0succ;
  bbInt l_n=bbInt(0);
  while((f0.l_node!=this->m__0head)){
    f0.l_node=f0.l_node->m__0succ;
    l_n+=1;
  }
  return l_n;
}

void t_std_collections_List_1Tt_mx2_Translator_GCTmp_2::m_Clear(){
  this->m__0head->m__0succ=this->m__0head;
  this->m__0head->m__0pred=this->m__0head;
  this->m__0seq+=1;
}

t_std_collections_List_1Tt_mx2_Translator_GCTmp_2_BackwardsIterator t_std_collections_List_1Tt_mx2_Translator_GCTmp_2::m_Backwards(){
  return t_std_collections_List_1Tt_mx2_Translator_GCTmp_2_BackwardsIterator(this,this->m__0head->m__0pred);
}

t_std_collections_List_1Tt_mx2_Translator_GCTmp_2_Iterator t_std_collections_List_1Tt_mx2_Translator_GCTmp_2::m_All(){
  return t_std_collections_List_1Tt_mx2_Translator_GCTmp_2_Iterator(this,this->m__0head->m__0succ);
}

t_std_collections_List_1Tt_mx2_Translator_GCTmp_2_Node* t_std_collections_List_1Tt_mx2_Translator_GCTmp_2::m_AddLast(t_mx2_Translator_GCTmp* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_mx2_Translator_GCTmp_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=bbGCNew<t_std_collections_List_1Tt_mx2_Translator_GCTmp_2_Node>(l_value,this->m__0head);
  this->m__0seq+=1;
  return f0.l_node;
}

t_std_collections_List_1Tt_mx2_Translator_GCTmp_2_Node* t_std_collections_List_1Tt_mx2_Translator_GCTmp_2::m_AddFirst(t_mx2_Translator_GCTmp* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_mx2_Translator_GCTmp_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=bbGCNew<t_std_collections_List_1Tt_mx2_Translator_GCTmp_2_Node>(l_value,this->m__0head->m__0succ);
  this->m__0seq+=1;
  return f0.l_node;
}

void t_std_collections_List_1Tt_mx2_Translator_GCTmp_2::m_AddAll(bbArray<bbGCVar<t_mx2_Translator_GCTmp>>* l_values){
  {
    bbInt l_0=bbInt(0);
    bbInt l_1=l_values->length();
    for(;(l_0<l_1);l_0+=1){
      struct f2_t : public bbGCFrame{
        t_mx2_Translator_GCTmp* l_value{};
        void gcMark(){
          bbGCMarkPtr(l_value);
        }
      }f2{};
      f2.l_value=l_values->at(l_0);
      this->m_AddLast(f2.l_value);
    }
  }
}

void t_std_collections_List_1Tt_mx2_Translator_GCTmp_2::m_Add(t_mx2_Translator_GCTmp* l_value){
  this->m_AddLast(l_value);
}

void t_std_collections_List_1Tt_mx2_TypeExpr_2_Node::gcMark(){
  bbGCMark(m__0succ);
  bbGCMark(m__0pred);
  bbGCMark(m__0value);
}

t_std_collections_List_1Tt_mx2_TypeExpr_2_Node::t_std_collections_List_1Tt_mx2_TypeExpr_2_Node(t_mx2_TypeExpr* l_value,t_std_collections_List_1Tt_mx2_TypeExpr_2_Node* l_succ){
  this->m__0value=l_value;
  this->m__0succ=l_succ;
  this->m__0pred=l_succ->m__0pred;
  this->m__0pred->m__0succ=this;
  l_succ->m__0pred=this;
}

t_std_collections_List_1Tt_mx2_TypeExpr_2_Node::t_std_collections_List_1Tt_mx2_TypeExpr_2_Node(t_mx2_TypeExpr* l_value){
  this->m__0value=l_value;
  this->m__0succ=this;
  this->m__0pred=this;
}

void t_std_collections_List_1Tt_mx2_TypeExpr_2_Node::m_Value(t_mx2_TypeExpr* l_value){
  this->m__0value=l_value;
}

t_mx2_TypeExpr* t_std_collections_List_1Tt_mx2_TypeExpr_2_Node::m_Value(){
  return this->m__0value;
}

t_std_collections_List_1Tt_mx2_TypeExpr_2_Node* t_std_collections_List_1Tt_mx2_TypeExpr_2_Node::m_Succ(){
  return this->m__0succ;
}

void t_std_collections_List_1Tt_mx2_TypeExpr_2_Node::m_Remove(){
  this->m__0succ->m__0pred=this->m__0pred;
  this->m__0pred->m__0succ=this->m__0succ;
}

t_std_collections_List_1Tt_mx2_TypeExpr_2_Node* t_std_collections_List_1Tt_mx2_TypeExpr_2_Node::m_Pred(){
  return this->m__0pred;
}

void t_std_collections_List_1Tt_mx2_TypeExpr_2_Node::m_InsertBefore(t_std_collections_List_1Tt_mx2_TypeExpr_2_Node* l_node){
  this->m__0succ=l_node;
  this->m__0pred=l_node->m__0pred;
  this->m__0pred->m__0succ=this;
  l_node->m__0pred=this;
}

void t_std_collections_List_1Tt_mx2_TypeExpr_2_Node::m_InsertAfter(t_std_collections_List_1Tt_mx2_TypeExpr_2_Node* l_node){
  this->m__0pred=l_node;
  this->m__0succ=l_node->m__0succ;
  this->m__0succ->m__0pred=this;
  l_node->m__0succ=this;
}

t_std_collections_List_1Tt_mx2_TypeExpr_2_Iterator::t_std_collections_List_1Tt_mx2_TypeExpr_2_Iterator(t_std_collections_List_1Tt_mx2_TypeExpr_2* l_list,t_std_collections_List_1Tt_mx2_TypeExpr_2_Node* l_node){
  (*this).m__0list=l_list;
  (*this).m__0node=l_node;
  (*this).m__0seq=l_list->m__0seq;
}

void t_std_collections_List_1Tt_mx2_TypeExpr_2_Iterator::m_Insert(t_mx2_TypeExpr* l_value){
  (*this).m_AssertSeq();
  (*this).m__0node=bbGCNew<t_std_collections_List_1Tt_mx2_TypeExpr_2_Node>(l_value,(*this).m__0node);
  (*this).m__0list->m__0seq+=1;
  (*this).m__0seq=(*this).m__0list->m__0seq;
}

void t_std_collections_List_1Tt_mx2_TypeExpr_2_Iterator::m_Erase(){
  (*this).m_AssertCurrent();
  (*this).m__0node=(*this).m__0node->m__0succ;
  (*this).m__0node->m__0pred->m_Remove();
  (*this).m__0list->m__0seq+=1;
  (*this).m__0seq=(*this).m__0list->m__0seq;
}

void t_std_collections_List_1Tt_mx2_TypeExpr_2_Iterator::m_Current(t_mx2_TypeExpr* l_current){
  (*this).m_AssertCurrent();
  (*this).m__0node->m__0value=l_current;
}

t_mx2_TypeExpr* t_std_collections_List_1Tt_mx2_TypeExpr_2_Iterator::m_Current(){
  (*this).m_AssertCurrent();
  return (*this).m__0node->m__0value;
}

void t_std_collections_List_1Tt_mx2_TypeExpr_2_Iterator::m_Bump(){
  (*this).m_AssertCurrent();
  (*this).m__0node=(*this).m__0node->m__0succ;
}

bbBool t_std_collections_List_1Tt_mx2_TypeExpr_2_Iterator::m_AtEnd(){
  (*this).m_AssertSeq();
  return ((*this).m__0node==(*this).m__0list->m__0head);
}

void t_std_collections_List_1Tt_mx2_TypeExpr_2_Iterator::m_AssertSeq(){
  bbDebugAssert(((*this).m__0seq==(*this).m__0list->m__0seq),BB_T("Concurrent list modification"));
}

void t_std_collections_List_1Tt_mx2_TypeExpr_2_Iterator::m_AssertCurrent(){
  bbDebugAssert(!(*this).m_AtEnd(),BB_T("Invalid list iterator"));
}

int bbCompare(const t_std_collections_List_1Tt_mx2_TypeExpr_2_Iterator&x,const t_std_collections_List_1Tt_mx2_TypeExpr_2_Iterator&y){
  if(int t=bbCompare(x.m__0list,y.m__0list)) return t;
  if(int t=bbCompare(x.m__0node,y.m__0node)) return t;
  if(int t=bbCompare(x.m__0seq,y.m__0seq)) return t;
  return 0;
}

void bbGCMark(const t_std_collections_List_1Tt_mx2_TypeExpr_2_Iterator&t){
  bbGCMark(t.m__0list);
  bbGCMark(t.m__0node);
}

t_std_collections_List_1Tt_mx2_TypeExpr_2_BackwardsIterator::t_std_collections_List_1Tt_mx2_TypeExpr_2_BackwardsIterator(t_std_collections_List_1Tt_mx2_TypeExpr_2* l_list,t_std_collections_List_1Tt_mx2_TypeExpr_2_Node* l_node){
  (*this).m__0list=l_list;
  (*this).m__0node=l_node;
  (*this).m__0seq=l_list->m__0seq;
}

void t_std_collections_List_1Tt_mx2_TypeExpr_2_BackwardsIterator::m_Insert(t_mx2_TypeExpr* l_value){
  (*this).m_AssertSeq();
  (*this).m__0node=bbGCNew<t_std_collections_List_1Tt_mx2_TypeExpr_2_Node>(l_value,(*this).m__0node->m__0succ);
  (*this).m__0list->m__0seq+=1;
  (*this).m__0seq=(*this).m__0list->m__0seq;
}

void t_std_collections_List_1Tt_mx2_TypeExpr_2_BackwardsIterator::m_Erase(){
  (*this).m_AssertCurrent();
  (*this).m__0node=(*this).m__0node->m__0pred;
  (*this).m__0node->m__0succ->m_Remove();
  (*this).m__0list->m__0seq+=1;
  (*this).m__0seq=(*this).m__0list->m__0seq;
}

void t_std_collections_List_1Tt_mx2_TypeExpr_2_BackwardsIterator::m_Current(t_mx2_TypeExpr* l_current){
  (*this).m_AssertCurrent();
  (*this).m__0node->m__0value=l_current;
}

t_mx2_TypeExpr* t_std_collections_List_1Tt_mx2_TypeExpr_2_BackwardsIterator::m_Current(){
  (*this).m_AssertCurrent();
  return (*this).m__0node->m__0value;
}

void t_std_collections_List_1Tt_mx2_TypeExpr_2_BackwardsIterator::m_Bump(){
  (*this).m_AssertCurrent();
  (*this).m__0node=(*this).m__0node->m__0pred;
}

bbBool t_std_collections_List_1Tt_mx2_TypeExpr_2_BackwardsIterator::m_AtEnd(){
  (*this).m_AssertSeq();
  return ((*this).m__0node==(*this).m__0list->m__0head);
}

void t_std_collections_List_1Tt_mx2_TypeExpr_2_BackwardsIterator::m_AssertSeq(){
  bbDebugAssert(((*this).m__0seq==(*this).m__0list->m__0seq),BB_T("Concurrent list modification"));
}

void t_std_collections_List_1Tt_mx2_TypeExpr_2_BackwardsIterator::m_AssertCurrent(){
  bbDebugAssert(!(*this).m_AtEnd(),BB_T("Invalid list iterator"));
}

int bbCompare(const t_std_collections_List_1Tt_mx2_TypeExpr_2_BackwardsIterator&x,const t_std_collections_List_1Tt_mx2_TypeExpr_2_BackwardsIterator&y){
  if(int t=bbCompare(x.m__0list,y.m__0list)) return t;
  if(int t=bbCompare(x.m__0node,y.m__0node)) return t;
  if(int t=bbCompare(x.m__0seq,y.m__0seq)) return t;
  return 0;
}

void bbGCMark(const t_std_collections_List_1Tt_mx2_TypeExpr_2_BackwardsIterator&t){
  bbGCMark(t.m__0list);
  bbGCMark(t.m__0node);
}

void t_std_collections_List_1Tt_mx2_TypeExpr_2::gcMark(){
  bbGCMark(m__0head);
}

t_std_collections_List_1Tt_mx2_TypeExpr_2::t_std_collections_List_1Tt_mx2_TypeExpr_2(t_std_collections_List_1Tt_mx2_TypeExpr_2* l_values):t_std_collections_List_1Tt_mx2_TypeExpr_2(){
  g_std_collections_List_1Tt_mx2_TypeExpr_2_AddAll_1Tt_std_collections_List_1Tt_mx2_TypeExpr_2_2(this,l_values);
}

t_std_collections_List_1Tt_mx2_TypeExpr_2::t_std_collections_List_1Tt_mx2_TypeExpr_2(t_std_collections_Stack_1Tt_mx2_TypeExpr_2* l_values):t_std_collections_List_1Tt_mx2_TypeExpr_2(){
  g_std_collections_List_1Tt_mx2_TypeExpr_2_AddAll_1Tt_std_collections_Stack_1Tt_mx2_TypeExpr_2_2(this,l_values);
}

t_std_collections_List_1Tt_mx2_TypeExpr_2::t_std_collections_List_1Tt_mx2_TypeExpr_2(bbArray<bbGCVar<t_mx2_TypeExpr>>* l_values):t_std_collections_List_1Tt_mx2_TypeExpr_2(){
  this->m_AddAll(l_values);
}

t_std_collections_List_1Tt_mx2_TypeExpr_2::t_std_collections_List_1Tt_mx2_TypeExpr_2(){
  this->m__0head=bbGCNew<t_std_collections_List_1Tt_mx2_TypeExpr_2_Node>(((t_mx2_TypeExpr*)0));
}

bbArray<bbGCVar<t_mx2_TypeExpr>>* t_std_collections_List_1Tt_mx2_TypeExpr_2::m_ToArray(){
  struct f0_t : public bbGCFrame{
    bbArray<bbGCVar<t_mx2_TypeExpr>>* l_data{};
    t_std_collections_List_1Tt_mx2_TypeExpr_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_data);
      bbGCMarkPtr(l_node);
    }
  }f0{};
  bbInt l_n=this->m_Count();
  f0.l_data=bbArray<bbGCVar<t_mx2_TypeExpr>>::create(l_n);
  f0.l_node=this->m__0head->m__0succ;
  {
    bbInt l_i=bbInt(0);
    for(;(l_i<l_n);l_i+=1){
      f0.l_data->at(l_i)=f0.l_node->m__0value;
      f0.l_node=f0.l_node->m__0succ;
    }
  }
  return f0.l_data;
}

void t_std_collections_List_1Tt_mx2_TypeExpr_2::m_Sort(bbFunction<bbInt(t_mx2_TypeExpr*,t_mx2_TypeExpr*)> l_compareFunc){
  bbInt l_insize=1;
  for(;;){
    struct f1_t : public bbGCFrame{
      t_std_collections_List_1Tt_mx2_TypeExpr_2_Node* l_p{};
      t_std_collections_List_1Tt_mx2_TypeExpr_2_Node* l_tail{};
      void gcMark(){
        bbGCMarkPtr(l_p);
        bbGCMarkPtr(l_tail);
      }
    }f1{};
    bbInt l_merges=bbInt(0);
    f1.l_tail=this->m__0head;
    f1.l_p=this->m__0head->m__0succ;
    while((f1.l_p!=this->m__0head)){
      struct f2_t : public bbGCFrame{
        t_std_collections_List_1Tt_mx2_TypeExpr_2_Node* l_q{};
        void gcMark(){
          bbGCMarkPtr(l_q);
        }
      }f2{};
      l_merges+=1;
      f2.l_q=f1.l_p->m__0succ;
      bbInt l_qsize=l_insize;
      bbInt l_psize=1;
      while(((l_psize<l_insize)&&(f2.l_q!=this->m__0head))){
        l_psize+=1;
        f2.l_q=f2.l_q->m__0succ;
      }
      for(;;){
        struct f3_t : public bbGCFrame{
          t_std_collections_List_1Tt_mx2_TypeExpr_2_Node* l_t{};
          void gcMark(){
            bbGCMarkPtr(l_t);
          }
        }f3{};
        if(((bbBool(l_psize)&&bbBool(l_qsize))&&(f2.l_q!=this->m__0head))){
          bbInt l_cc=l_compareFunc(f1.l_p->m__0value,f2.l_q->m__0value);
          if((l_cc<=bbInt(0))){
            f3.l_t=f1.l_p;
            f1.l_p=f1.l_p->m__0succ;
            l_psize-=1;
          }else{
            f3.l_t=f2.l_q;
            f2.l_q=f2.l_q->m__0succ;
            l_qsize-=1;
          }
        }else if(bbBool(l_psize)){
          f3.l_t=f1.l_p;
          f1.l_p=f1.l_p->m__0succ;
          l_psize-=1;
        }else if((bbBool(l_qsize)&&(f2.l_q!=this->m__0head))){
          f3.l_t=f2.l_q;
          f2.l_q=f2.l_q->m__0succ;
          l_qsize-=1;
        }else{
          break;
        }
        f3.l_t->m__0pred=f1.l_tail;
        f1.l_tail->m__0succ=f3.l_t;
        f1.l_tail=f3.l_t;
      }
      f1.l_p=f2.l_q;
    }
    f1.l_tail->m__0succ=this->m__0head;
    this->m__0head->m__0pred=f1.l_tail;
    if((l_merges<=1)){
      return;
    }
    l_insize*=2;
  }
}

void t_std_collections_List_1Tt_mx2_TypeExpr_2::m_Sort(bbBool l_ascending){
  if(l_ascending){
    struct lambda38 : public bbFunction<bbInt(t_mx2_TypeExpr*,t_mx2_TypeExpr*)>::Rep{
      t_std_collections_List_1Tt_mx2_TypeExpr_2* l_self;
      lambda38(t_std_collections_List_1Tt_mx2_TypeExpr_2* l_self):l_self(l_self){
      }
      bbInt invoke(t_mx2_TypeExpr* l_x,t_mx2_TypeExpr* l_y){
        return bbCompare(l_x,l_y);
      }
      void gcMark(){
        bbGCMarkPtr(l_self);
      }
    };
    this->m_Sort(bbFunction<bbInt(t_mx2_TypeExpr*,t_mx2_TypeExpr*)>(new lambda38(this)));
  }else{
    struct lambda39 : public bbFunction<bbInt(t_mx2_TypeExpr*,t_mx2_TypeExpr*)>::Rep{
      t_std_collections_List_1Tt_mx2_TypeExpr_2* l_self;
      lambda39(t_std_collections_List_1Tt_mx2_TypeExpr_2* l_self):l_self(l_self){
      }
      bbInt invoke(t_mx2_TypeExpr* l_x,t_mx2_TypeExpr* l_y){
        return -bbCompare(l_x,l_y);
      }
      void gcMark(){
        bbGCMarkPtr(l_self);
      }
    };
    this->m_Sort(bbFunction<bbInt(t_mx2_TypeExpr*,t_mx2_TypeExpr*)>(new lambda39(this)));
  }
}

t_mx2_TypeExpr* t_std_collections_List_1Tt_mx2_TypeExpr_2::m_RemoveLast(){
  struct f0_t : public bbGCFrame{
    t_mx2_TypeExpr* l_value{};
    void gcMark(){
      bbGCMarkPtr(l_value);
    }
  }f0{};
  bbDebugAssert(!this->m_Empty(),BB_T("Debug assert failed"));
  f0.l_value=this->m__0head->m__0pred->m__0value;
  this->m__0head->m__0pred->m_Remove();
  this->m__0seq+=1;
  return f0.l_value;
}

bbBool t_std_collections_List_1Tt_mx2_TypeExpr_2::m_RemoveLast(t_mx2_TypeExpr* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_mx2_TypeExpr_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m_FindLastNode(l_value);
  if(!bbBool(f0.l_node)){
    return false;
  }
  f0.l_node->m_Remove();
  this->m__0seq+=1;
  return true;
}

t_mx2_TypeExpr* t_std_collections_List_1Tt_mx2_TypeExpr_2::m_RemoveFirst(){
  struct f0_t : public bbGCFrame{
    t_mx2_TypeExpr* l_value{};
    void gcMark(){
      bbGCMarkPtr(l_value);
    }
  }f0{};
  bbDebugAssert(!this->m_Empty(),BB_T("Debug assert failed"));
  f0.l_value=this->m__0head->m__0succ->m__0value;
  this->m__0head->m__0succ->m_Remove();
  this->m__0seq+=1;
  return f0.l_value;
}

bbInt t_std_collections_List_1Tt_mx2_TypeExpr_2::m_RemoveEach(t_mx2_TypeExpr* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_mx2_TypeExpr_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m__0head->m__0succ;
  bbInt l_n=bbInt(0);
  while((f0.l_node!=this->m__0head)){
    if((f0.l_node->m__0value==l_value)){
      f0.l_node=f0.l_node->m__0succ;
      f0.l_node->m__0pred->m_Remove();
      l_n+=1;
    }else{
      f0.l_node=f0.l_node->m__0succ;
    }
  }
  if(bbBool(l_n)){
    this->m__0seq+=1;
  }
  return l_n;
}

bbBool t_std_collections_List_1Tt_mx2_TypeExpr_2::m_Remove(t_mx2_TypeExpr* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_mx2_TypeExpr_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m_FindNode(l_value);
  if(!bbBool(f0.l_node)){
    return false;
  }
  f0.l_node->m_Remove();
  this->m__0seq+=1;
  return true;
}

t_std_collections_List_1Tt_mx2_TypeExpr_2_Node* t_std_collections_List_1Tt_mx2_TypeExpr_2::m_LastNode(){
  if(!this->m_Empty()){
    return this->m__0head->m__0pred;
  }
  return ((t_std_collections_List_1Tt_mx2_TypeExpr_2_Node*)0);
}

t_mx2_TypeExpr* t_std_collections_List_1Tt_mx2_TypeExpr_2::m_Last(){
  bbDebugAssert(!this->m_Empty(),BB_T("Debug assert failed"));
  return this->m__0head->m__0pred->m__0value;
}

t_std_collections_List_1Tt_mx2_TypeExpr_2_Node* t_std_collections_List_1Tt_mx2_TypeExpr_2::m_HeadNode(){
  return this->m__0head;
}

t_std_collections_List_1Tt_mx2_TypeExpr_2_Node* t_std_collections_List_1Tt_mx2_TypeExpr_2::m_FirstNode(){
  if(!this->m_Empty()){
    return this->m__0head->m__0succ;
  }
  return ((t_std_collections_List_1Tt_mx2_TypeExpr_2_Node*)0);
}

t_mx2_TypeExpr* t_std_collections_List_1Tt_mx2_TypeExpr_2::m_First(){
  bbDebugAssert(!this->m_Empty(),BB_T("Debug assert failed"));
  return this->m__0head->m__0succ->m__0value;
}

t_std_collections_List_1Tt_mx2_TypeExpr_2_Node* t_std_collections_List_1Tt_mx2_TypeExpr_2::m_FindNode(t_mx2_TypeExpr* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_mx2_TypeExpr_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m__0head->m__0succ;
  while((f0.l_node!=this->m__0head)){
    if((f0.l_node->m__0value==l_value)){
      return f0.l_node;
    }
    f0.l_node=f0.l_node->m__0succ;
  }
  return ((t_std_collections_List_1Tt_mx2_TypeExpr_2_Node*)0);
}

t_std_collections_List_1Tt_mx2_TypeExpr_2_Node* t_std_collections_List_1Tt_mx2_TypeExpr_2::m_FindLastNode(t_mx2_TypeExpr* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_mx2_TypeExpr_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m__0head->m__0pred;
  while((f0.l_node!=this->m__0head)){
    if((f0.l_node->m__0value==l_value)){
      return f0.l_node;
    }
    f0.l_node=f0.l_node->m__0pred;
  }
  return ((t_std_collections_List_1Tt_mx2_TypeExpr_2_Node*)0);
}

bbBool t_std_collections_List_1Tt_mx2_TypeExpr_2::m_Empty(){
  return (this->m__0head->m__0succ==this->m__0head);
}

bbInt t_std_collections_List_1Tt_mx2_TypeExpr_2::m_Count(){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_mx2_TypeExpr_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m__0head->m__0succ;
  bbInt l_n=bbInt(0);
  while((f0.l_node!=this->m__0head)){
    f0.l_node=f0.l_node->m__0succ;
    l_n+=1;
  }
  return l_n;
}

void t_std_collections_List_1Tt_mx2_TypeExpr_2::m_Clear(){
  this->m__0head->m__0succ=this->m__0head;
  this->m__0head->m__0pred=this->m__0head;
  this->m__0seq+=1;
}

t_std_collections_List_1Tt_mx2_TypeExpr_2_BackwardsIterator t_std_collections_List_1Tt_mx2_TypeExpr_2::m_Backwards(){
  return t_std_collections_List_1Tt_mx2_TypeExpr_2_BackwardsIterator(this,this->m__0head->m__0pred);
}

t_std_collections_List_1Tt_mx2_TypeExpr_2_Iterator t_std_collections_List_1Tt_mx2_TypeExpr_2::m_All(){
  return t_std_collections_List_1Tt_mx2_TypeExpr_2_Iterator(this,this->m__0head->m__0succ);
}

t_std_collections_List_1Tt_mx2_TypeExpr_2_Node* t_std_collections_List_1Tt_mx2_TypeExpr_2::m_AddLast(t_mx2_TypeExpr* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_mx2_TypeExpr_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=bbGCNew<t_std_collections_List_1Tt_mx2_TypeExpr_2_Node>(l_value,this->m__0head);
  this->m__0seq+=1;
  return f0.l_node;
}

t_std_collections_List_1Tt_mx2_TypeExpr_2_Node* t_std_collections_List_1Tt_mx2_TypeExpr_2::m_AddFirst(t_mx2_TypeExpr* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_mx2_TypeExpr_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=bbGCNew<t_std_collections_List_1Tt_mx2_TypeExpr_2_Node>(l_value,this->m__0head->m__0succ);
  this->m__0seq+=1;
  return f0.l_node;
}

void t_std_collections_List_1Tt_mx2_TypeExpr_2::m_AddAll(bbArray<bbGCVar<t_mx2_TypeExpr>>* l_values){
  {
    bbInt l_0=bbInt(0);
    bbInt l_1=l_values->length();
    for(;(l_0<l_1);l_0+=1){
      struct f2_t : public bbGCFrame{
        t_mx2_TypeExpr* l_value{};
        void gcMark(){
          bbGCMarkPtr(l_value);
        }
      }f2{};
      f2.l_value=l_values->at(l_0);
      this->m_AddLast(f2.l_value);
    }
  }
}

void t_std_collections_List_1Tt_mx2_TypeExpr_2::m_Add(t_mx2_TypeExpr* l_value){
  this->m_AddLast(l_value);
}

void t_std_collections_List_1Tt_mx2_CatchExpr_2_Node::gcMark(){
  bbGCMark(m__0succ);
  bbGCMark(m__0pred);
  bbGCMark(m__0value);
}

t_std_collections_List_1Tt_mx2_CatchExpr_2_Node::t_std_collections_List_1Tt_mx2_CatchExpr_2_Node(t_mx2_CatchExpr* l_value,t_std_collections_List_1Tt_mx2_CatchExpr_2_Node* l_succ){
  this->m__0value=l_value;
  this->m__0succ=l_succ;
  this->m__0pred=l_succ->m__0pred;
  this->m__0pred->m__0succ=this;
  l_succ->m__0pred=this;
}

t_std_collections_List_1Tt_mx2_CatchExpr_2_Node::t_std_collections_List_1Tt_mx2_CatchExpr_2_Node(t_mx2_CatchExpr* l_value){
  this->m__0value=l_value;
  this->m__0succ=this;
  this->m__0pred=this;
}

void t_std_collections_List_1Tt_mx2_CatchExpr_2_Node::m_Value(t_mx2_CatchExpr* l_value){
  this->m__0value=l_value;
}

t_mx2_CatchExpr* t_std_collections_List_1Tt_mx2_CatchExpr_2_Node::m_Value(){
  return this->m__0value;
}

t_std_collections_List_1Tt_mx2_CatchExpr_2_Node* t_std_collections_List_1Tt_mx2_CatchExpr_2_Node::m_Succ(){
  return this->m__0succ;
}

void t_std_collections_List_1Tt_mx2_CatchExpr_2_Node::m_Remove(){
  this->m__0succ->m__0pred=this->m__0pred;
  this->m__0pred->m__0succ=this->m__0succ;
}

t_std_collections_List_1Tt_mx2_CatchExpr_2_Node* t_std_collections_List_1Tt_mx2_CatchExpr_2_Node::m_Pred(){
  return this->m__0pred;
}

void t_std_collections_List_1Tt_mx2_CatchExpr_2_Node::m_InsertBefore(t_std_collections_List_1Tt_mx2_CatchExpr_2_Node* l_node){
  this->m__0succ=l_node;
  this->m__0pred=l_node->m__0pred;
  this->m__0pred->m__0succ=this;
  l_node->m__0pred=this;
}

void t_std_collections_List_1Tt_mx2_CatchExpr_2_Node::m_InsertAfter(t_std_collections_List_1Tt_mx2_CatchExpr_2_Node* l_node){
  this->m__0pred=l_node;
  this->m__0succ=l_node->m__0succ;
  this->m__0succ->m__0pred=this;
  l_node->m__0succ=this;
}

t_std_collections_List_1Tt_mx2_CatchExpr_2_Iterator::t_std_collections_List_1Tt_mx2_CatchExpr_2_Iterator(t_std_collections_List_1Tt_mx2_CatchExpr_2* l_list,t_std_collections_List_1Tt_mx2_CatchExpr_2_Node* l_node){
  (*this).m__0list=l_list;
  (*this).m__0node=l_node;
  (*this).m__0seq=l_list->m__0seq;
}

void t_std_collections_List_1Tt_mx2_CatchExpr_2_Iterator::m_Insert(t_mx2_CatchExpr* l_value){
  (*this).m_AssertSeq();
  (*this).m__0node=bbGCNew<t_std_collections_List_1Tt_mx2_CatchExpr_2_Node>(l_value,(*this).m__0node);
  (*this).m__0list->m__0seq+=1;
  (*this).m__0seq=(*this).m__0list->m__0seq;
}

void t_std_collections_List_1Tt_mx2_CatchExpr_2_Iterator::m_Erase(){
  (*this).m_AssertCurrent();
  (*this).m__0node=(*this).m__0node->m__0succ;
  (*this).m__0node->m__0pred->m_Remove();
  (*this).m__0list->m__0seq+=1;
  (*this).m__0seq=(*this).m__0list->m__0seq;
}

void t_std_collections_List_1Tt_mx2_CatchExpr_2_Iterator::m_Current(t_mx2_CatchExpr* l_current){
  (*this).m_AssertCurrent();
  (*this).m__0node->m__0value=l_current;
}

t_mx2_CatchExpr* t_std_collections_List_1Tt_mx2_CatchExpr_2_Iterator::m_Current(){
  (*this).m_AssertCurrent();
  return (*this).m__0node->m__0value;
}

void t_std_collections_List_1Tt_mx2_CatchExpr_2_Iterator::m_Bump(){
  (*this).m_AssertCurrent();
  (*this).m__0node=(*this).m__0node->m__0succ;
}

bbBool t_std_collections_List_1Tt_mx2_CatchExpr_2_Iterator::m_AtEnd(){
  (*this).m_AssertSeq();
  return ((*this).m__0node==(*this).m__0list->m__0head);
}

void t_std_collections_List_1Tt_mx2_CatchExpr_2_Iterator::m_AssertSeq(){
  bbDebugAssert(((*this).m__0seq==(*this).m__0list->m__0seq),BB_T("Concurrent list modification"));
}

void t_std_collections_List_1Tt_mx2_CatchExpr_2_Iterator::m_AssertCurrent(){
  bbDebugAssert(!(*this).m_AtEnd(),BB_T("Invalid list iterator"));
}

int bbCompare(const t_std_collections_List_1Tt_mx2_CatchExpr_2_Iterator&x,const t_std_collections_List_1Tt_mx2_CatchExpr_2_Iterator&y){
  if(int t=bbCompare(x.m__0list,y.m__0list)) return t;
  if(int t=bbCompare(x.m__0node,y.m__0node)) return t;
  if(int t=bbCompare(x.m__0seq,y.m__0seq)) return t;
  return 0;
}

void bbGCMark(const t_std_collections_List_1Tt_mx2_CatchExpr_2_Iterator&t){
  bbGCMark(t.m__0list);
  bbGCMark(t.m__0node);
}

t_std_collections_List_1Tt_mx2_CatchExpr_2_BackwardsIterator::t_std_collections_List_1Tt_mx2_CatchExpr_2_BackwardsIterator(t_std_collections_List_1Tt_mx2_CatchExpr_2* l_list,t_std_collections_List_1Tt_mx2_CatchExpr_2_Node* l_node){
  (*this).m__0list=l_list;
  (*this).m__0node=l_node;
  (*this).m__0seq=l_list->m__0seq;
}

void t_std_collections_List_1Tt_mx2_CatchExpr_2_BackwardsIterator::m_Insert(t_mx2_CatchExpr* l_value){
  (*this).m_AssertSeq();
  (*this).m__0node=bbGCNew<t_std_collections_List_1Tt_mx2_CatchExpr_2_Node>(l_value,(*this).m__0node->m__0succ);
  (*this).m__0list->m__0seq+=1;
  (*this).m__0seq=(*this).m__0list->m__0seq;
}

void t_std_collections_List_1Tt_mx2_CatchExpr_2_BackwardsIterator::m_Erase(){
  (*this).m_AssertCurrent();
  (*this).m__0node=(*this).m__0node->m__0pred;
  (*this).m__0node->m__0succ->m_Remove();
  (*this).m__0list->m__0seq+=1;
  (*this).m__0seq=(*this).m__0list->m__0seq;
}

void t_std_collections_List_1Tt_mx2_CatchExpr_2_BackwardsIterator::m_Current(t_mx2_CatchExpr* l_current){
  (*this).m_AssertCurrent();
  (*this).m__0node->m__0value=l_current;
}

t_mx2_CatchExpr* t_std_collections_List_1Tt_mx2_CatchExpr_2_BackwardsIterator::m_Current(){
  (*this).m_AssertCurrent();
  return (*this).m__0node->m__0value;
}

void t_std_collections_List_1Tt_mx2_CatchExpr_2_BackwardsIterator::m_Bump(){
  (*this).m_AssertCurrent();
  (*this).m__0node=(*this).m__0node->m__0pred;
}

bbBool t_std_collections_List_1Tt_mx2_CatchExpr_2_BackwardsIterator::m_AtEnd(){
  (*this).m_AssertSeq();
  return ((*this).m__0node==(*this).m__0list->m__0head);
}

void t_std_collections_List_1Tt_mx2_CatchExpr_2_BackwardsIterator::m_AssertSeq(){
  bbDebugAssert(((*this).m__0seq==(*this).m__0list->m__0seq),BB_T("Concurrent list modification"));
}

void t_std_collections_List_1Tt_mx2_CatchExpr_2_BackwardsIterator::m_AssertCurrent(){
  bbDebugAssert(!(*this).m_AtEnd(),BB_T("Invalid list iterator"));
}

int bbCompare(const t_std_collections_List_1Tt_mx2_CatchExpr_2_BackwardsIterator&x,const t_std_collections_List_1Tt_mx2_CatchExpr_2_BackwardsIterator&y){
  if(int t=bbCompare(x.m__0list,y.m__0list)) return t;
  if(int t=bbCompare(x.m__0node,y.m__0node)) return t;
  if(int t=bbCompare(x.m__0seq,y.m__0seq)) return t;
  return 0;
}

void bbGCMark(const t_std_collections_List_1Tt_mx2_CatchExpr_2_BackwardsIterator&t){
  bbGCMark(t.m__0list);
  bbGCMark(t.m__0node);
}

void t_std_collections_List_1Tt_mx2_CatchExpr_2::gcMark(){
  bbGCMark(m__0head);
}

t_std_collections_List_1Tt_mx2_CatchExpr_2::t_std_collections_List_1Tt_mx2_CatchExpr_2(t_std_collections_List_1Tt_mx2_CatchExpr_2* l_values):t_std_collections_List_1Tt_mx2_CatchExpr_2(){
  g_std_collections_List_1Tt_mx2_CatchExpr_2_AddAll_1Tt_std_collections_List_1Tt_mx2_CatchExpr_2_2(this,l_values);
}

t_std_collections_List_1Tt_mx2_CatchExpr_2::t_std_collections_List_1Tt_mx2_CatchExpr_2(t_std_collections_Stack_1Tt_mx2_CatchExpr_2* l_values):t_std_collections_List_1Tt_mx2_CatchExpr_2(){
  g_std_collections_List_1Tt_mx2_CatchExpr_2_AddAll_1Tt_std_collections_Stack_1Tt_mx2_CatchExpr_2_2(this,l_values);
}

t_std_collections_List_1Tt_mx2_CatchExpr_2::t_std_collections_List_1Tt_mx2_CatchExpr_2(bbArray<bbGCVar<t_mx2_CatchExpr>>* l_values):t_std_collections_List_1Tt_mx2_CatchExpr_2(){
  this->m_AddAll(l_values);
}

t_std_collections_List_1Tt_mx2_CatchExpr_2::t_std_collections_List_1Tt_mx2_CatchExpr_2(){
  this->m__0head=bbGCNew<t_std_collections_List_1Tt_mx2_CatchExpr_2_Node>(((t_mx2_CatchExpr*)0));
}

bbArray<bbGCVar<t_mx2_CatchExpr>>* t_std_collections_List_1Tt_mx2_CatchExpr_2::m_ToArray(){
  struct f0_t : public bbGCFrame{
    bbArray<bbGCVar<t_mx2_CatchExpr>>* l_data{};
    t_std_collections_List_1Tt_mx2_CatchExpr_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_data);
      bbGCMarkPtr(l_node);
    }
  }f0{};
  bbInt l_n=this->m_Count();
  f0.l_data=bbArray<bbGCVar<t_mx2_CatchExpr>>::create(l_n);
  f0.l_node=this->m__0head->m__0succ;
  {
    bbInt l_i=bbInt(0);
    for(;(l_i<l_n);l_i+=1){
      f0.l_data->at(l_i)=f0.l_node->m__0value;
      f0.l_node=f0.l_node->m__0succ;
    }
  }
  return f0.l_data;
}

void t_std_collections_List_1Tt_mx2_CatchExpr_2::m_Sort(bbFunction<bbInt(t_mx2_CatchExpr*,t_mx2_CatchExpr*)> l_compareFunc){
  bbInt l_insize=1;
  for(;;){
    struct f1_t : public bbGCFrame{
      t_std_collections_List_1Tt_mx2_CatchExpr_2_Node* l_p{};
      t_std_collections_List_1Tt_mx2_CatchExpr_2_Node* l_tail{};
      void gcMark(){
        bbGCMarkPtr(l_p);
        bbGCMarkPtr(l_tail);
      }
    }f1{};
    bbInt l_merges=bbInt(0);
    f1.l_tail=this->m__0head;
    f1.l_p=this->m__0head->m__0succ;
    while((f1.l_p!=this->m__0head)){
      struct f2_t : public bbGCFrame{
        t_std_collections_List_1Tt_mx2_CatchExpr_2_Node* l_q{};
        void gcMark(){
          bbGCMarkPtr(l_q);
        }
      }f2{};
      l_merges+=1;
      f2.l_q=f1.l_p->m__0succ;
      bbInt l_qsize=l_insize;
      bbInt l_psize=1;
      while(((l_psize<l_insize)&&(f2.l_q!=this->m__0head))){
        l_psize+=1;
        f2.l_q=f2.l_q->m__0succ;
      }
      for(;;){
        struct f3_t : public bbGCFrame{
          t_std_collections_List_1Tt_mx2_CatchExpr_2_Node* l_t{};
          void gcMark(){
            bbGCMarkPtr(l_t);
          }
        }f3{};
        if(((bbBool(l_psize)&&bbBool(l_qsize))&&(f2.l_q!=this->m__0head))){
          bbInt l_cc=l_compareFunc(f1.l_p->m__0value,f2.l_q->m__0value);
          if((l_cc<=bbInt(0))){
            f3.l_t=f1.l_p;
            f1.l_p=f1.l_p->m__0succ;
            l_psize-=1;
          }else{
            f3.l_t=f2.l_q;
            f2.l_q=f2.l_q->m__0succ;
            l_qsize-=1;
          }
        }else if(bbBool(l_psize)){
          f3.l_t=f1.l_p;
          f1.l_p=f1.l_p->m__0succ;
          l_psize-=1;
        }else if((bbBool(l_qsize)&&(f2.l_q!=this->m__0head))){
          f3.l_t=f2.l_q;
          f2.l_q=f2.l_q->m__0succ;
          l_qsize-=1;
        }else{
          break;
        }
        f3.l_t->m__0pred=f1.l_tail;
        f1.l_tail->m__0succ=f3.l_t;
        f1.l_tail=f3.l_t;
      }
      f1.l_p=f2.l_q;
    }
    f1.l_tail->m__0succ=this->m__0head;
    this->m__0head->m__0pred=f1.l_tail;
    if((l_merges<=1)){
      return;
    }
    l_insize*=2;
  }
}

void t_std_collections_List_1Tt_mx2_CatchExpr_2::m_Sort(bbBool l_ascending){
  if(l_ascending){
    struct lambda40 : public bbFunction<bbInt(t_mx2_CatchExpr*,t_mx2_CatchExpr*)>::Rep{
      t_std_collections_List_1Tt_mx2_CatchExpr_2* l_self;
      lambda40(t_std_collections_List_1Tt_mx2_CatchExpr_2* l_self):l_self(l_self){
      }
      bbInt invoke(t_mx2_CatchExpr* l_x,t_mx2_CatchExpr* l_y){
        return bbCompare(l_x,l_y);
      }
      void gcMark(){
        bbGCMarkPtr(l_self);
      }
    };
    this->m_Sort(bbFunction<bbInt(t_mx2_CatchExpr*,t_mx2_CatchExpr*)>(new lambda40(this)));
  }else{
    struct lambda41 : public bbFunction<bbInt(t_mx2_CatchExpr*,t_mx2_CatchExpr*)>::Rep{
      t_std_collections_List_1Tt_mx2_CatchExpr_2* l_self;
      lambda41(t_std_collections_List_1Tt_mx2_CatchExpr_2* l_self):l_self(l_self){
      }
      bbInt invoke(t_mx2_CatchExpr* l_x,t_mx2_CatchExpr* l_y){
        return -bbCompare(l_x,l_y);
      }
      void gcMark(){
        bbGCMarkPtr(l_self);
      }
    };
    this->m_Sort(bbFunction<bbInt(t_mx2_CatchExpr*,t_mx2_CatchExpr*)>(new lambda41(this)));
  }
}

t_mx2_CatchExpr* t_std_collections_List_1Tt_mx2_CatchExpr_2::m_RemoveLast(){
  struct f0_t : public bbGCFrame{
    t_mx2_CatchExpr* l_value{};
    void gcMark(){
      bbGCMarkPtr(l_value);
    }
  }f0{};
  bbDebugAssert(!this->m_Empty(),BB_T("Debug assert failed"));
  f0.l_value=this->m__0head->m__0pred->m__0value;
  this->m__0head->m__0pred->m_Remove();
  this->m__0seq+=1;
  return f0.l_value;
}

bbBool t_std_collections_List_1Tt_mx2_CatchExpr_2::m_RemoveLast(t_mx2_CatchExpr* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_mx2_CatchExpr_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m_FindLastNode(l_value);
  if(!bbBool(f0.l_node)){
    return false;
  }
  f0.l_node->m_Remove();
  this->m__0seq+=1;
  return true;
}

t_mx2_CatchExpr* t_std_collections_List_1Tt_mx2_CatchExpr_2::m_RemoveFirst(){
  struct f0_t : public bbGCFrame{
    t_mx2_CatchExpr* l_value{};
    void gcMark(){
      bbGCMarkPtr(l_value);
    }
  }f0{};
  bbDebugAssert(!this->m_Empty(),BB_T("Debug assert failed"));
  f0.l_value=this->m__0head->m__0succ->m__0value;
  this->m__0head->m__0succ->m_Remove();
  this->m__0seq+=1;
  return f0.l_value;
}

bbInt t_std_collections_List_1Tt_mx2_CatchExpr_2::m_RemoveEach(t_mx2_CatchExpr* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_mx2_CatchExpr_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m__0head->m__0succ;
  bbInt l_n=bbInt(0);
  while((f0.l_node!=this->m__0head)){
    if((f0.l_node->m__0value==l_value)){
      f0.l_node=f0.l_node->m__0succ;
      f0.l_node->m__0pred->m_Remove();
      l_n+=1;
    }else{
      f0.l_node=f0.l_node->m__0succ;
    }
  }
  if(bbBool(l_n)){
    this->m__0seq+=1;
  }
  return l_n;
}

bbBool t_std_collections_List_1Tt_mx2_CatchExpr_2::m_Remove(t_mx2_CatchExpr* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_mx2_CatchExpr_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m_FindNode(l_value);
  if(!bbBool(f0.l_node)){
    return false;
  }
  f0.l_node->m_Remove();
  this->m__0seq+=1;
  return true;
}

t_std_collections_List_1Tt_mx2_CatchExpr_2_Node* t_std_collections_List_1Tt_mx2_CatchExpr_2::m_LastNode(){
  if(!this->m_Empty()){
    return this->m__0head->m__0pred;
  }
  return ((t_std_collections_List_1Tt_mx2_CatchExpr_2_Node*)0);
}

t_mx2_CatchExpr* t_std_collections_List_1Tt_mx2_CatchExpr_2::m_Last(){
  bbDebugAssert(!this->m_Empty(),BB_T("Debug assert failed"));
  return this->m__0head->m__0pred->m__0value;
}

t_std_collections_List_1Tt_mx2_CatchExpr_2_Node* t_std_collections_List_1Tt_mx2_CatchExpr_2::m_HeadNode(){
  return this->m__0head;
}

t_std_collections_List_1Tt_mx2_CatchExpr_2_Node* t_std_collections_List_1Tt_mx2_CatchExpr_2::m_FirstNode(){
  if(!this->m_Empty()){
    return this->m__0head->m__0succ;
  }
  return ((t_std_collections_List_1Tt_mx2_CatchExpr_2_Node*)0);
}

t_mx2_CatchExpr* t_std_collections_List_1Tt_mx2_CatchExpr_2::m_First(){
  bbDebugAssert(!this->m_Empty(),BB_T("Debug assert failed"));
  return this->m__0head->m__0succ->m__0value;
}

t_std_collections_List_1Tt_mx2_CatchExpr_2_Node* t_std_collections_List_1Tt_mx2_CatchExpr_2::m_FindNode(t_mx2_CatchExpr* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_mx2_CatchExpr_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m__0head->m__0succ;
  while((f0.l_node!=this->m__0head)){
    if((f0.l_node->m__0value==l_value)){
      return f0.l_node;
    }
    f0.l_node=f0.l_node->m__0succ;
  }
  return ((t_std_collections_List_1Tt_mx2_CatchExpr_2_Node*)0);
}

t_std_collections_List_1Tt_mx2_CatchExpr_2_Node* t_std_collections_List_1Tt_mx2_CatchExpr_2::m_FindLastNode(t_mx2_CatchExpr* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_mx2_CatchExpr_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m__0head->m__0pred;
  while((f0.l_node!=this->m__0head)){
    if((f0.l_node->m__0value==l_value)){
      return f0.l_node;
    }
    f0.l_node=f0.l_node->m__0pred;
  }
  return ((t_std_collections_List_1Tt_mx2_CatchExpr_2_Node*)0);
}

bbBool t_std_collections_List_1Tt_mx2_CatchExpr_2::m_Empty(){
  return (this->m__0head->m__0succ==this->m__0head);
}

bbInt t_std_collections_List_1Tt_mx2_CatchExpr_2::m_Count(){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_mx2_CatchExpr_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m__0head->m__0succ;
  bbInt l_n=bbInt(0);
  while((f0.l_node!=this->m__0head)){
    f0.l_node=f0.l_node->m__0succ;
    l_n+=1;
  }
  return l_n;
}

void t_std_collections_List_1Tt_mx2_CatchExpr_2::m_Clear(){
  this->m__0head->m__0succ=this->m__0head;
  this->m__0head->m__0pred=this->m__0head;
  this->m__0seq+=1;
}

t_std_collections_List_1Tt_mx2_CatchExpr_2_BackwardsIterator t_std_collections_List_1Tt_mx2_CatchExpr_2::m_Backwards(){
  return t_std_collections_List_1Tt_mx2_CatchExpr_2_BackwardsIterator(this,this->m__0head->m__0pred);
}

t_std_collections_List_1Tt_mx2_CatchExpr_2_Iterator t_std_collections_List_1Tt_mx2_CatchExpr_2::m_All(){
  return t_std_collections_List_1Tt_mx2_CatchExpr_2_Iterator(this,this->m__0head->m__0succ);
}

t_std_collections_List_1Tt_mx2_CatchExpr_2_Node* t_std_collections_List_1Tt_mx2_CatchExpr_2::m_AddLast(t_mx2_CatchExpr* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_mx2_CatchExpr_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=bbGCNew<t_std_collections_List_1Tt_mx2_CatchExpr_2_Node>(l_value,this->m__0head);
  this->m__0seq+=1;
  return f0.l_node;
}

t_std_collections_List_1Tt_mx2_CatchExpr_2_Node* t_std_collections_List_1Tt_mx2_CatchExpr_2::m_AddFirst(t_mx2_CatchExpr* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_mx2_CatchExpr_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=bbGCNew<t_std_collections_List_1Tt_mx2_CatchExpr_2_Node>(l_value,this->m__0head->m__0succ);
  this->m__0seq+=1;
  return f0.l_node;
}

void t_std_collections_List_1Tt_mx2_CatchExpr_2::m_AddAll(bbArray<bbGCVar<t_mx2_CatchExpr>>* l_values){
  {
    bbInt l_0=bbInt(0);
    bbInt l_1=l_values->length();
    for(;(l_0<l_1);l_0+=1){
      struct f2_t : public bbGCFrame{
        t_mx2_CatchExpr* l_value{};
        void gcMark(){
          bbGCMarkPtr(l_value);
        }
      }f2{};
      f2.l_value=l_values->at(l_0);
      this->m_AddLast(f2.l_value);
    }
  }
}

void t_std_collections_List_1Tt_mx2_CatchExpr_2::m_Add(t_mx2_CatchExpr* l_value){
  this->m_AddLast(l_value);
}

void t_std_collections_List_1Tt_mx2_StmtExpr_2_Node::gcMark(){
  bbGCMark(m__0succ);
  bbGCMark(m__0pred);
  bbGCMark(m__0value);
}

t_std_collections_List_1Tt_mx2_StmtExpr_2_Node::t_std_collections_List_1Tt_mx2_StmtExpr_2_Node(t_mx2_StmtExpr* l_value,t_std_collections_List_1Tt_mx2_StmtExpr_2_Node* l_succ){
  this->m__0value=l_value;
  this->m__0succ=l_succ;
  this->m__0pred=l_succ->m__0pred;
  this->m__0pred->m__0succ=this;
  l_succ->m__0pred=this;
}

t_std_collections_List_1Tt_mx2_StmtExpr_2_Node::t_std_collections_List_1Tt_mx2_StmtExpr_2_Node(t_mx2_StmtExpr* l_value){
  this->m__0value=l_value;
  this->m__0succ=this;
  this->m__0pred=this;
}

void t_std_collections_List_1Tt_mx2_StmtExpr_2_Node::m_Value(t_mx2_StmtExpr* l_value){
  this->m__0value=l_value;
}

t_mx2_StmtExpr* t_std_collections_List_1Tt_mx2_StmtExpr_2_Node::m_Value(){
  return this->m__0value;
}

t_std_collections_List_1Tt_mx2_StmtExpr_2_Node* t_std_collections_List_1Tt_mx2_StmtExpr_2_Node::m_Succ(){
  return this->m__0succ;
}

void t_std_collections_List_1Tt_mx2_StmtExpr_2_Node::m_Remove(){
  this->m__0succ->m__0pred=this->m__0pred;
  this->m__0pred->m__0succ=this->m__0succ;
}

t_std_collections_List_1Tt_mx2_StmtExpr_2_Node* t_std_collections_List_1Tt_mx2_StmtExpr_2_Node::m_Pred(){
  return this->m__0pred;
}

void t_std_collections_List_1Tt_mx2_StmtExpr_2_Node::m_InsertBefore(t_std_collections_List_1Tt_mx2_StmtExpr_2_Node* l_node){
  this->m__0succ=l_node;
  this->m__0pred=l_node->m__0pred;
  this->m__0pred->m__0succ=this;
  l_node->m__0pred=this;
}

void t_std_collections_List_1Tt_mx2_StmtExpr_2_Node::m_InsertAfter(t_std_collections_List_1Tt_mx2_StmtExpr_2_Node* l_node){
  this->m__0pred=l_node;
  this->m__0succ=l_node->m__0succ;
  this->m__0succ->m__0pred=this;
  l_node->m__0succ=this;
}

t_std_collections_List_1Tt_mx2_StmtExpr_2_Iterator::t_std_collections_List_1Tt_mx2_StmtExpr_2_Iterator(t_std_collections_List_1Tt_mx2_StmtExpr_2* l_list,t_std_collections_List_1Tt_mx2_StmtExpr_2_Node* l_node){
  (*this).m__0list=l_list;
  (*this).m__0node=l_node;
  (*this).m__0seq=l_list->m__0seq;
}

void t_std_collections_List_1Tt_mx2_StmtExpr_2_Iterator::m_Insert(t_mx2_StmtExpr* l_value){
  (*this).m_AssertSeq();
  (*this).m__0node=bbGCNew<t_std_collections_List_1Tt_mx2_StmtExpr_2_Node>(l_value,(*this).m__0node);
  (*this).m__0list->m__0seq+=1;
  (*this).m__0seq=(*this).m__0list->m__0seq;
}

void t_std_collections_List_1Tt_mx2_StmtExpr_2_Iterator::m_Erase(){
  (*this).m_AssertCurrent();
  (*this).m__0node=(*this).m__0node->m__0succ;
  (*this).m__0node->m__0pred->m_Remove();
  (*this).m__0list->m__0seq+=1;
  (*this).m__0seq=(*this).m__0list->m__0seq;
}

void t_std_collections_List_1Tt_mx2_StmtExpr_2_Iterator::m_Current(t_mx2_StmtExpr* l_current){
  (*this).m_AssertCurrent();
  (*this).m__0node->m__0value=l_current;
}

t_mx2_StmtExpr* t_std_collections_List_1Tt_mx2_StmtExpr_2_Iterator::m_Current(){
  (*this).m_AssertCurrent();
  return (*this).m__0node->m__0value;
}

void t_std_collections_List_1Tt_mx2_StmtExpr_2_Iterator::m_Bump(){
  (*this).m_AssertCurrent();
  (*this).m__0node=(*this).m__0node->m__0succ;
}

bbBool t_std_collections_List_1Tt_mx2_StmtExpr_2_Iterator::m_AtEnd(){
  (*this).m_AssertSeq();
  return ((*this).m__0node==(*this).m__0list->m__0head);
}

void t_std_collections_List_1Tt_mx2_StmtExpr_2_Iterator::m_AssertSeq(){
  bbDebugAssert(((*this).m__0seq==(*this).m__0list->m__0seq),BB_T("Concurrent list modification"));
}

void t_std_collections_List_1Tt_mx2_StmtExpr_2_Iterator::m_AssertCurrent(){
  bbDebugAssert(!(*this).m_AtEnd(),BB_T("Invalid list iterator"));
}

int bbCompare(const t_std_collections_List_1Tt_mx2_StmtExpr_2_Iterator&x,const t_std_collections_List_1Tt_mx2_StmtExpr_2_Iterator&y){
  if(int t=bbCompare(x.m__0list,y.m__0list)) return t;
  if(int t=bbCompare(x.m__0node,y.m__0node)) return t;
  if(int t=bbCompare(x.m__0seq,y.m__0seq)) return t;
  return 0;
}

void bbGCMark(const t_std_collections_List_1Tt_mx2_StmtExpr_2_Iterator&t){
  bbGCMark(t.m__0list);
  bbGCMark(t.m__0node);
}

t_std_collections_List_1Tt_mx2_StmtExpr_2_BackwardsIterator::t_std_collections_List_1Tt_mx2_StmtExpr_2_BackwardsIterator(t_std_collections_List_1Tt_mx2_StmtExpr_2* l_list,t_std_collections_List_1Tt_mx2_StmtExpr_2_Node* l_node){
  (*this).m__0list=l_list;
  (*this).m__0node=l_node;
  (*this).m__0seq=l_list->m__0seq;
}

void t_std_collections_List_1Tt_mx2_StmtExpr_2_BackwardsIterator::m_Insert(t_mx2_StmtExpr* l_value){
  (*this).m_AssertSeq();
  (*this).m__0node=bbGCNew<t_std_collections_List_1Tt_mx2_StmtExpr_2_Node>(l_value,(*this).m__0node->m__0succ);
  (*this).m__0list->m__0seq+=1;
  (*this).m__0seq=(*this).m__0list->m__0seq;
}

void t_std_collections_List_1Tt_mx2_StmtExpr_2_BackwardsIterator::m_Erase(){
  (*this).m_AssertCurrent();
  (*this).m__0node=(*this).m__0node->m__0pred;
  (*this).m__0node->m__0succ->m_Remove();
  (*this).m__0list->m__0seq+=1;
  (*this).m__0seq=(*this).m__0list->m__0seq;
}

void t_std_collections_List_1Tt_mx2_StmtExpr_2_BackwardsIterator::m_Current(t_mx2_StmtExpr* l_current){
  (*this).m_AssertCurrent();
  (*this).m__0node->m__0value=l_current;
}

t_mx2_StmtExpr* t_std_collections_List_1Tt_mx2_StmtExpr_2_BackwardsIterator::m_Current(){
  (*this).m_AssertCurrent();
  return (*this).m__0node->m__0value;
}

void t_std_collections_List_1Tt_mx2_StmtExpr_2_BackwardsIterator::m_Bump(){
  (*this).m_AssertCurrent();
  (*this).m__0node=(*this).m__0node->m__0pred;
}

bbBool t_std_collections_List_1Tt_mx2_StmtExpr_2_BackwardsIterator::m_AtEnd(){
  (*this).m_AssertSeq();
  return ((*this).m__0node==(*this).m__0list->m__0head);
}

void t_std_collections_List_1Tt_mx2_StmtExpr_2_BackwardsIterator::m_AssertSeq(){
  bbDebugAssert(((*this).m__0seq==(*this).m__0list->m__0seq),BB_T("Concurrent list modification"));
}

void t_std_collections_List_1Tt_mx2_StmtExpr_2_BackwardsIterator::m_AssertCurrent(){
  bbDebugAssert(!(*this).m_AtEnd(),BB_T("Invalid list iterator"));
}

int bbCompare(const t_std_collections_List_1Tt_mx2_StmtExpr_2_BackwardsIterator&x,const t_std_collections_List_1Tt_mx2_StmtExpr_2_BackwardsIterator&y){
  if(int t=bbCompare(x.m__0list,y.m__0list)) return t;
  if(int t=bbCompare(x.m__0node,y.m__0node)) return t;
  if(int t=bbCompare(x.m__0seq,y.m__0seq)) return t;
  return 0;
}

void bbGCMark(const t_std_collections_List_1Tt_mx2_StmtExpr_2_BackwardsIterator&t){
  bbGCMark(t.m__0list);
  bbGCMark(t.m__0node);
}

void t_std_collections_List_1Tt_mx2_StmtExpr_2::gcMark(){
  bbGCMark(m__0head);
}

t_std_collections_List_1Tt_mx2_StmtExpr_2::t_std_collections_List_1Tt_mx2_StmtExpr_2(t_std_collections_List_1Tt_mx2_StmtExpr_2* l_values):t_std_collections_List_1Tt_mx2_StmtExpr_2(){
  g_std_collections_List_1Tt_mx2_StmtExpr_2_AddAll_1Tt_std_collections_List_1Tt_mx2_StmtExpr_2_2(this,l_values);
}

t_std_collections_List_1Tt_mx2_StmtExpr_2::t_std_collections_List_1Tt_mx2_StmtExpr_2(t_std_collections_Stack_1Tt_mx2_StmtExpr_2* l_values):t_std_collections_List_1Tt_mx2_StmtExpr_2(){
  g_std_collections_List_1Tt_mx2_StmtExpr_2_AddAll_1Tt_std_collections_Stack_1Tt_mx2_StmtExpr_2_2(this,l_values);
}

t_std_collections_List_1Tt_mx2_StmtExpr_2::t_std_collections_List_1Tt_mx2_StmtExpr_2(bbArray<bbGCVar<t_mx2_StmtExpr>>* l_values):t_std_collections_List_1Tt_mx2_StmtExpr_2(){
  this->m_AddAll(l_values);
}

t_std_collections_List_1Tt_mx2_StmtExpr_2::t_std_collections_List_1Tt_mx2_StmtExpr_2(){
  this->m__0head=bbGCNew<t_std_collections_List_1Tt_mx2_StmtExpr_2_Node>(((t_mx2_StmtExpr*)0));
}

bbArray<bbGCVar<t_mx2_StmtExpr>>* t_std_collections_List_1Tt_mx2_StmtExpr_2::m_ToArray(){
  struct f0_t : public bbGCFrame{
    bbArray<bbGCVar<t_mx2_StmtExpr>>* l_data{};
    t_std_collections_List_1Tt_mx2_StmtExpr_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_data);
      bbGCMarkPtr(l_node);
    }
  }f0{};
  bbInt l_n=this->m_Count();
  f0.l_data=bbArray<bbGCVar<t_mx2_StmtExpr>>::create(l_n);
  f0.l_node=this->m__0head->m__0succ;
  {
    bbInt l_i=bbInt(0);
    for(;(l_i<l_n);l_i+=1){
      f0.l_data->at(l_i)=f0.l_node->m__0value;
      f0.l_node=f0.l_node->m__0succ;
    }
  }
  return f0.l_data;
}

void t_std_collections_List_1Tt_mx2_StmtExpr_2::m_Sort(bbFunction<bbInt(t_mx2_StmtExpr*,t_mx2_StmtExpr*)> l_compareFunc){
  bbInt l_insize=1;
  for(;;){
    struct f1_t : public bbGCFrame{
      t_std_collections_List_1Tt_mx2_StmtExpr_2_Node* l_p{};
      t_std_collections_List_1Tt_mx2_StmtExpr_2_Node* l_tail{};
      void gcMark(){
        bbGCMarkPtr(l_p);
        bbGCMarkPtr(l_tail);
      }
    }f1{};
    bbInt l_merges=bbInt(0);
    f1.l_tail=this->m__0head;
    f1.l_p=this->m__0head->m__0succ;
    while((f1.l_p!=this->m__0head)){
      struct f2_t : public bbGCFrame{
        t_std_collections_List_1Tt_mx2_StmtExpr_2_Node* l_q{};
        void gcMark(){
          bbGCMarkPtr(l_q);
        }
      }f2{};
      l_merges+=1;
      f2.l_q=f1.l_p->m__0succ;
      bbInt l_qsize=l_insize;
      bbInt l_psize=1;
      while(((l_psize<l_insize)&&(f2.l_q!=this->m__0head))){
        l_psize+=1;
        f2.l_q=f2.l_q->m__0succ;
      }
      for(;;){
        struct f3_t : public bbGCFrame{
          t_std_collections_List_1Tt_mx2_StmtExpr_2_Node* l_t{};
          void gcMark(){
            bbGCMarkPtr(l_t);
          }
        }f3{};
        if(((bbBool(l_psize)&&bbBool(l_qsize))&&(f2.l_q!=this->m__0head))){
          bbInt l_cc=l_compareFunc(f1.l_p->m__0value,f2.l_q->m__0value);
          if((l_cc<=bbInt(0))){
            f3.l_t=f1.l_p;
            f1.l_p=f1.l_p->m__0succ;
            l_psize-=1;
          }else{
            f3.l_t=f2.l_q;
            f2.l_q=f2.l_q->m__0succ;
            l_qsize-=1;
          }
        }else if(bbBool(l_psize)){
          f3.l_t=f1.l_p;
          f1.l_p=f1.l_p->m__0succ;
          l_psize-=1;
        }else if((bbBool(l_qsize)&&(f2.l_q!=this->m__0head))){
          f3.l_t=f2.l_q;
          f2.l_q=f2.l_q->m__0succ;
          l_qsize-=1;
        }else{
          break;
        }
        f3.l_t->m__0pred=f1.l_tail;
        f1.l_tail->m__0succ=f3.l_t;
        f1.l_tail=f3.l_t;
      }
      f1.l_p=f2.l_q;
    }
    f1.l_tail->m__0succ=this->m__0head;
    this->m__0head->m__0pred=f1.l_tail;
    if((l_merges<=1)){
      return;
    }
    l_insize*=2;
  }
}

void t_std_collections_List_1Tt_mx2_StmtExpr_2::m_Sort(bbBool l_ascending){
  if(l_ascending){
    struct lambda42 : public bbFunction<bbInt(t_mx2_StmtExpr*,t_mx2_StmtExpr*)>::Rep{
      t_std_collections_List_1Tt_mx2_StmtExpr_2* l_self;
      lambda42(t_std_collections_List_1Tt_mx2_StmtExpr_2* l_self):l_self(l_self){
      }
      bbInt invoke(t_mx2_StmtExpr* l_x,t_mx2_StmtExpr* l_y){
        return bbCompare(l_x,l_y);
      }
      void gcMark(){
        bbGCMarkPtr(l_self);
      }
    };
    this->m_Sort(bbFunction<bbInt(t_mx2_StmtExpr*,t_mx2_StmtExpr*)>(new lambda42(this)));
  }else{
    struct lambda43 : public bbFunction<bbInt(t_mx2_StmtExpr*,t_mx2_StmtExpr*)>::Rep{
      t_std_collections_List_1Tt_mx2_StmtExpr_2* l_self;
      lambda43(t_std_collections_List_1Tt_mx2_StmtExpr_2* l_self):l_self(l_self){
      }
      bbInt invoke(t_mx2_StmtExpr* l_x,t_mx2_StmtExpr* l_y){
        return -bbCompare(l_x,l_y);
      }
      void gcMark(){
        bbGCMarkPtr(l_self);
      }
    };
    this->m_Sort(bbFunction<bbInt(t_mx2_StmtExpr*,t_mx2_StmtExpr*)>(new lambda43(this)));
  }
}

t_mx2_StmtExpr* t_std_collections_List_1Tt_mx2_StmtExpr_2::m_RemoveLast(){
  struct f0_t : public bbGCFrame{
    t_mx2_StmtExpr* l_value{};
    void gcMark(){
      bbGCMarkPtr(l_value);
    }
  }f0{};
  bbDebugAssert(!this->m_Empty(),BB_T("Debug assert failed"));
  f0.l_value=this->m__0head->m__0pred->m__0value;
  this->m__0head->m__0pred->m_Remove();
  this->m__0seq+=1;
  return f0.l_value;
}

bbBool t_std_collections_List_1Tt_mx2_StmtExpr_2::m_RemoveLast(t_mx2_StmtExpr* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_mx2_StmtExpr_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m_FindLastNode(l_value);
  if(!bbBool(f0.l_node)){
    return false;
  }
  f0.l_node->m_Remove();
  this->m__0seq+=1;
  return true;
}

t_mx2_StmtExpr* t_std_collections_List_1Tt_mx2_StmtExpr_2::m_RemoveFirst(){
  struct f0_t : public bbGCFrame{
    t_mx2_StmtExpr* l_value{};
    void gcMark(){
      bbGCMarkPtr(l_value);
    }
  }f0{};
  bbDebugAssert(!this->m_Empty(),BB_T("Debug assert failed"));
  f0.l_value=this->m__0head->m__0succ->m__0value;
  this->m__0head->m__0succ->m_Remove();
  this->m__0seq+=1;
  return f0.l_value;
}

bbInt t_std_collections_List_1Tt_mx2_StmtExpr_2::m_RemoveEach(t_mx2_StmtExpr* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_mx2_StmtExpr_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m__0head->m__0succ;
  bbInt l_n=bbInt(0);
  while((f0.l_node!=this->m__0head)){
    if((f0.l_node->m__0value==l_value)){
      f0.l_node=f0.l_node->m__0succ;
      f0.l_node->m__0pred->m_Remove();
      l_n+=1;
    }else{
      f0.l_node=f0.l_node->m__0succ;
    }
  }
  if(bbBool(l_n)){
    this->m__0seq+=1;
  }
  return l_n;
}

bbBool t_std_collections_List_1Tt_mx2_StmtExpr_2::m_Remove(t_mx2_StmtExpr* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_mx2_StmtExpr_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m_FindNode(l_value);
  if(!bbBool(f0.l_node)){
    return false;
  }
  f0.l_node->m_Remove();
  this->m__0seq+=1;
  return true;
}

t_std_collections_List_1Tt_mx2_StmtExpr_2_Node* t_std_collections_List_1Tt_mx2_StmtExpr_2::m_LastNode(){
  if(!this->m_Empty()){
    return this->m__0head->m__0pred;
  }
  return ((t_std_collections_List_1Tt_mx2_StmtExpr_2_Node*)0);
}

t_mx2_StmtExpr* t_std_collections_List_1Tt_mx2_StmtExpr_2::m_Last(){
  bbDebugAssert(!this->m_Empty(),BB_T("Debug assert failed"));
  return this->m__0head->m__0pred->m__0value;
}

t_std_collections_List_1Tt_mx2_StmtExpr_2_Node* t_std_collections_List_1Tt_mx2_StmtExpr_2::m_HeadNode(){
  return this->m__0head;
}

t_std_collections_List_1Tt_mx2_StmtExpr_2_Node* t_std_collections_List_1Tt_mx2_StmtExpr_2::m_FirstNode(){
  if(!this->m_Empty()){
    return this->m__0head->m__0succ;
  }
  return ((t_std_collections_List_1Tt_mx2_StmtExpr_2_Node*)0);
}

t_mx2_StmtExpr* t_std_collections_List_1Tt_mx2_StmtExpr_2::m_First(){
  bbDebugAssert(!this->m_Empty(),BB_T("Debug assert failed"));
  return this->m__0head->m__0succ->m__0value;
}

t_std_collections_List_1Tt_mx2_StmtExpr_2_Node* t_std_collections_List_1Tt_mx2_StmtExpr_2::m_FindNode(t_mx2_StmtExpr* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_mx2_StmtExpr_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m__0head->m__0succ;
  while((f0.l_node!=this->m__0head)){
    if((f0.l_node->m__0value==l_value)){
      return f0.l_node;
    }
    f0.l_node=f0.l_node->m__0succ;
  }
  return ((t_std_collections_List_1Tt_mx2_StmtExpr_2_Node*)0);
}

t_std_collections_List_1Tt_mx2_StmtExpr_2_Node* t_std_collections_List_1Tt_mx2_StmtExpr_2::m_FindLastNode(t_mx2_StmtExpr* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_mx2_StmtExpr_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m__0head->m__0pred;
  while((f0.l_node!=this->m__0head)){
    if((f0.l_node->m__0value==l_value)){
      return f0.l_node;
    }
    f0.l_node=f0.l_node->m__0pred;
  }
  return ((t_std_collections_List_1Tt_mx2_StmtExpr_2_Node*)0);
}

bbBool t_std_collections_List_1Tt_mx2_StmtExpr_2::m_Empty(){
  return (this->m__0head->m__0succ==this->m__0head);
}

bbInt t_std_collections_List_1Tt_mx2_StmtExpr_2::m_Count(){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_mx2_StmtExpr_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m__0head->m__0succ;
  bbInt l_n=bbInt(0);
  while((f0.l_node!=this->m__0head)){
    f0.l_node=f0.l_node->m__0succ;
    l_n+=1;
  }
  return l_n;
}

void t_std_collections_List_1Tt_mx2_StmtExpr_2::m_Clear(){
  this->m__0head->m__0succ=this->m__0head;
  this->m__0head->m__0pred=this->m__0head;
  this->m__0seq+=1;
}

t_std_collections_List_1Tt_mx2_StmtExpr_2_BackwardsIterator t_std_collections_List_1Tt_mx2_StmtExpr_2::m_Backwards(){
  return t_std_collections_List_1Tt_mx2_StmtExpr_2_BackwardsIterator(this,this->m__0head->m__0pred);
}

t_std_collections_List_1Tt_mx2_StmtExpr_2_Iterator t_std_collections_List_1Tt_mx2_StmtExpr_2::m_All(){
  return t_std_collections_List_1Tt_mx2_StmtExpr_2_Iterator(this,this->m__0head->m__0succ);
}

t_std_collections_List_1Tt_mx2_StmtExpr_2_Node* t_std_collections_List_1Tt_mx2_StmtExpr_2::m_AddLast(t_mx2_StmtExpr* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_mx2_StmtExpr_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=bbGCNew<t_std_collections_List_1Tt_mx2_StmtExpr_2_Node>(l_value,this->m__0head);
  this->m__0seq+=1;
  return f0.l_node;
}

t_std_collections_List_1Tt_mx2_StmtExpr_2_Node* t_std_collections_List_1Tt_mx2_StmtExpr_2::m_AddFirst(t_mx2_StmtExpr* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_mx2_StmtExpr_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=bbGCNew<t_std_collections_List_1Tt_mx2_StmtExpr_2_Node>(l_value,this->m__0head->m__0succ);
  this->m__0seq+=1;
  return f0.l_node;
}

void t_std_collections_List_1Tt_mx2_StmtExpr_2::m_AddAll(bbArray<bbGCVar<t_mx2_StmtExpr>>* l_values){
  {
    bbInt l_0=bbInt(0);
    bbInt l_1=l_values->length();
    for(;(l_0<l_1);l_0+=1){
      struct f2_t : public bbGCFrame{
        t_mx2_StmtExpr* l_value{};
        void gcMark(){
          bbGCMarkPtr(l_value);
        }
      }f2{};
      f2.l_value=l_values->at(l_0);
      this->m_AddLast(f2.l_value);
    }
  }
}

void t_std_collections_List_1Tt_mx2_StmtExpr_2::m_Add(t_mx2_StmtExpr* l_value){
  this->m_AddLast(l_value);
}

void t_std_collections_List_1Tt_mx2_CaseExpr_2_Node::gcMark(){
  bbGCMark(m__0succ);
  bbGCMark(m__0pred);
  bbGCMark(m__0value);
}

t_std_collections_List_1Tt_mx2_CaseExpr_2_Node::t_std_collections_List_1Tt_mx2_CaseExpr_2_Node(t_mx2_CaseExpr* l_value,t_std_collections_List_1Tt_mx2_CaseExpr_2_Node* l_succ){
  this->m__0value=l_value;
  this->m__0succ=l_succ;
  this->m__0pred=l_succ->m__0pred;
  this->m__0pred->m__0succ=this;
  l_succ->m__0pred=this;
}

t_std_collections_List_1Tt_mx2_CaseExpr_2_Node::t_std_collections_List_1Tt_mx2_CaseExpr_2_Node(t_mx2_CaseExpr* l_value){
  this->m__0value=l_value;
  this->m__0succ=this;
  this->m__0pred=this;
}

void t_std_collections_List_1Tt_mx2_CaseExpr_2_Node::m_Value(t_mx2_CaseExpr* l_value){
  this->m__0value=l_value;
}

t_mx2_CaseExpr* t_std_collections_List_1Tt_mx2_CaseExpr_2_Node::m_Value(){
  return this->m__0value;
}

t_std_collections_List_1Tt_mx2_CaseExpr_2_Node* t_std_collections_List_1Tt_mx2_CaseExpr_2_Node::m_Succ(){
  return this->m__0succ;
}

void t_std_collections_List_1Tt_mx2_CaseExpr_2_Node::m_Remove(){
  this->m__0succ->m__0pred=this->m__0pred;
  this->m__0pred->m__0succ=this->m__0succ;
}

t_std_collections_List_1Tt_mx2_CaseExpr_2_Node* t_std_collections_List_1Tt_mx2_CaseExpr_2_Node::m_Pred(){
  return this->m__0pred;
}

void t_std_collections_List_1Tt_mx2_CaseExpr_2_Node::m_InsertBefore(t_std_collections_List_1Tt_mx2_CaseExpr_2_Node* l_node){
  this->m__0succ=l_node;
  this->m__0pred=l_node->m__0pred;
  this->m__0pred->m__0succ=this;
  l_node->m__0pred=this;
}

void t_std_collections_List_1Tt_mx2_CaseExpr_2_Node::m_InsertAfter(t_std_collections_List_1Tt_mx2_CaseExpr_2_Node* l_node){
  this->m__0pred=l_node;
  this->m__0succ=l_node->m__0succ;
  this->m__0succ->m__0pred=this;
  l_node->m__0succ=this;
}

t_std_collections_List_1Tt_mx2_CaseExpr_2_Iterator::t_std_collections_List_1Tt_mx2_CaseExpr_2_Iterator(t_std_collections_List_1Tt_mx2_CaseExpr_2* l_list,t_std_collections_List_1Tt_mx2_CaseExpr_2_Node* l_node){
  (*this).m__0list=l_list;
  (*this).m__0node=l_node;
  (*this).m__0seq=l_list->m__0seq;
}

void t_std_collections_List_1Tt_mx2_CaseExpr_2_Iterator::m_Insert(t_mx2_CaseExpr* l_value){
  (*this).m_AssertSeq();
  (*this).m__0node=bbGCNew<t_std_collections_List_1Tt_mx2_CaseExpr_2_Node>(l_value,(*this).m__0node);
  (*this).m__0list->m__0seq+=1;
  (*this).m__0seq=(*this).m__0list->m__0seq;
}

void t_std_collections_List_1Tt_mx2_CaseExpr_2_Iterator::m_Erase(){
  (*this).m_AssertCurrent();
  (*this).m__0node=(*this).m__0node->m__0succ;
  (*this).m__0node->m__0pred->m_Remove();
  (*this).m__0list->m__0seq+=1;
  (*this).m__0seq=(*this).m__0list->m__0seq;
}

void t_std_collections_List_1Tt_mx2_CaseExpr_2_Iterator::m_Current(t_mx2_CaseExpr* l_current){
  (*this).m_AssertCurrent();
  (*this).m__0node->m__0value=l_current;
}

t_mx2_CaseExpr* t_std_collections_List_1Tt_mx2_CaseExpr_2_Iterator::m_Current(){
  (*this).m_AssertCurrent();
  return (*this).m__0node->m__0value;
}

void t_std_collections_List_1Tt_mx2_CaseExpr_2_Iterator::m_Bump(){
  (*this).m_AssertCurrent();
  (*this).m__0node=(*this).m__0node->m__0succ;
}

bbBool t_std_collections_List_1Tt_mx2_CaseExpr_2_Iterator::m_AtEnd(){
  (*this).m_AssertSeq();
  return ((*this).m__0node==(*this).m__0list->m__0head);
}

void t_std_collections_List_1Tt_mx2_CaseExpr_2_Iterator::m_AssertSeq(){
  bbDebugAssert(((*this).m__0seq==(*this).m__0list->m__0seq),BB_T("Concurrent list modification"));
}

void t_std_collections_List_1Tt_mx2_CaseExpr_2_Iterator::m_AssertCurrent(){
  bbDebugAssert(!(*this).m_AtEnd(),BB_T("Invalid list iterator"));
}

int bbCompare(const t_std_collections_List_1Tt_mx2_CaseExpr_2_Iterator&x,const t_std_collections_List_1Tt_mx2_CaseExpr_2_Iterator&y){
  if(int t=bbCompare(x.m__0list,y.m__0list)) return t;
  if(int t=bbCompare(x.m__0node,y.m__0node)) return t;
  if(int t=bbCompare(x.m__0seq,y.m__0seq)) return t;
  return 0;
}

void bbGCMark(const t_std_collections_List_1Tt_mx2_CaseExpr_2_Iterator&t){
  bbGCMark(t.m__0list);
  bbGCMark(t.m__0node);
}

t_std_collections_List_1Tt_mx2_CaseExpr_2_BackwardsIterator::t_std_collections_List_1Tt_mx2_CaseExpr_2_BackwardsIterator(t_std_collections_List_1Tt_mx2_CaseExpr_2* l_list,t_std_collections_List_1Tt_mx2_CaseExpr_2_Node* l_node){
  (*this).m__0list=l_list;
  (*this).m__0node=l_node;
  (*this).m__0seq=l_list->m__0seq;
}

void t_std_collections_List_1Tt_mx2_CaseExpr_2_BackwardsIterator::m_Insert(t_mx2_CaseExpr* l_value){
  (*this).m_AssertSeq();
  (*this).m__0node=bbGCNew<t_std_collections_List_1Tt_mx2_CaseExpr_2_Node>(l_value,(*this).m__0node->m__0succ);
  (*this).m__0list->m__0seq+=1;
  (*this).m__0seq=(*this).m__0list->m__0seq;
}

void t_std_collections_List_1Tt_mx2_CaseExpr_2_BackwardsIterator::m_Erase(){
  (*this).m_AssertCurrent();
  (*this).m__0node=(*this).m__0node->m__0pred;
  (*this).m__0node->m__0succ->m_Remove();
  (*this).m__0list->m__0seq+=1;
  (*this).m__0seq=(*this).m__0list->m__0seq;
}

void t_std_collections_List_1Tt_mx2_CaseExpr_2_BackwardsIterator::m_Current(t_mx2_CaseExpr* l_current){
  (*this).m_AssertCurrent();
  (*this).m__0node->m__0value=l_current;
}

t_mx2_CaseExpr* t_std_collections_List_1Tt_mx2_CaseExpr_2_BackwardsIterator::m_Current(){
  (*this).m_AssertCurrent();
  return (*this).m__0node->m__0value;
}

void t_std_collections_List_1Tt_mx2_CaseExpr_2_BackwardsIterator::m_Bump(){
  (*this).m_AssertCurrent();
  (*this).m__0node=(*this).m__0node->m__0pred;
}

bbBool t_std_collections_List_1Tt_mx2_CaseExpr_2_BackwardsIterator::m_AtEnd(){
  (*this).m_AssertSeq();
  return ((*this).m__0node==(*this).m__0list->m__0head);
}

void t_std_collections_List_1Tt_mx2_CaseExpr_2_BackwardsIterator::m_AssertSeq(){
  bbDebugAssert(((*this).m__0seq==(*this).m__0list->m__0seq),BB_T("Concurrent list modification"));
}

void t_std_collections_List_1Tt_mx2_CaseExpr_2_BackwardsIterator::m_AssertCurrent(){
  bbDebugAssert(!(*this).m_AtEnd(),BB_T("Invalid list iterator"));
}

int bbCompare(const t_std_collections_List_1Tt_mx2_CaseExpr_2_BackwardsIterator&x,const t_std_collections_List_1Tt_mx2_CaseExpr_2_BackwardsIterator&y){
  if(int t=bbCompare(x.m__0list,y.m__0list)) return t;
  if(int t=bbCompare(x.m__0node,y.m__0node)) return t;
  if(int t=bbCompare(x.m__0seq,y.m__0seq)) return t;
  return 0;
}

void bbGCMark(const t_std_collections_List_1Tt_mx2_CaseExpr_2_BackwardsIterator&t){
  bbGCMark(t.m__0list);
  bbGCMark(t.m__0node);
}

void t_std_collections_List_1Tt_mx2_CaseExpr_2::gcMark(){
  bbGCMark(m__0head);
}

t_std_collections_List_1Tt_mx2_CaseExpr_2::t_std_collections_List_1Tt_mx2_CaseExpr_2(t_std_collections_List_1Tt_mx2_CaseExpr_2* l_values):t_std_collections_List_1Tt_mx2_CaseExpr_2(){
  g_std_collections_List_1Tt_mx2_CaseExpr_2_AddAll_1Tt_std_collections_List_1Tt_mx2_CaseExpr_2_2(this,l_values);
}

t_std_collections_List_1Tt_mx2_CaseExpr_2::t_std_collections_List_1Tt_mx2_CaseExpr_2(t_std_collections_Stack_1Tt_mx2_CaseExpr_2* l_values):t_std_collections_List_1Tt_mx2_CaseExpr_2(){
  g_std_collections_List_1Tt_mx2_CaseExpr_2_AddAll_1Tt_std_collections_Stack_1Tt_mx2_CaseExpr_2_2(this,l_values);
}

t_std_collections_List_1Tt_mx2_CaseExpr_2::t_std_collections_List_1Tt_mx2_CaseExpr_2(bbArray<bbGCVar<t_mx2_CaseExpr>>* l_values):t_std_collections_List_1Tt_mx2_CaseExpr_2(){
  this->m_AddAll(l_values);
}

t_std_collections_List_1Tt_mx2_CaseExpr_2::t_std_collections_List_1Tt_mx2_CaseExpr_2(){
  this->m__0head=bbGCNew<t_std_collections_List_1Tt_mx2_CaseExpr_2_Node>(((t_mx2_CaseExpr*)0));
}

bbArray<bbGCVar<t_mx2_CaseExpr>>* t_std_collections_List_1Tt_mx2_CaseExpr_2::m_ToArray(){
  struct f0_t : public bbGCFrame{
    bbArray<bbGCVar<t_mx2_CaseExpr>>* l_data{};
    t_std_collections_List_1Tt_mx2_CaseExpr_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_data);
      bbGCMarkPtr(l_node);
    }
  }f0{};
  bbInt l_n=this->m_Count();
  f0.l_data=bbArray<bbGCVar<t_mx2_CaseExpr>>::create(l_n);
  f0.l_node=this->m__0head->m__0succ;
  {
    bbInt l_i=bbInt(0);
    for(;(l_i<l_n);l_i+=1){
      f0.l_data->at(l_i)=f0.l_node->m__0value;
      f0.l_node=f0.l_node->m__0succ;
    }
  }
  return f0.l_data;
}

void t_std_collections_List_1Tt_mx2_CaseExpr_2::m_Sort(bbFunction<bbInt(t_mx2_CaseExpr*,t_mx2_CaseExpr*)> l_compareFunc){
  bbInt l_insize=1;
  for(;;){
    struct f1_t : public bbGCFrame{
      t_std_collections_List_1Tt_mx2_CaseExpr_2_Node* l_p{};
      t_std_collections_List_1Tt_mx2_CaseExpr_2_Node* l_tail{};
      void gcMark(){
        bbGCMarkPtr(l_p);
        bbGCMarkPtr(l_tail);
      }
    }f1{};
    bbInt l_merges=bbInt(0);
    f1.l_tail=this->m__0head;
    f1.l_p=this->m__0head->m__0succ;
    while((f1.l_p!=this->m__0head)){
      struct f2_t : public bbGCFrame{
        t_std_collections_List_1Tt_mx2_CaseExpr_2_Node* l_q{};
        void gcMark(){
          bbGCMarkPtr(l_q);
        }
      }f2{};
      l_merges+=1;
      f2.l_q=f1.l_p->m__0succ;
      bbInt l_qsize=l_insize;
      bbInt l_psize=1;
      while(((l_psize<l_insize)&&(f2.l_q!=this->m__0head))){
        l_psize+=1;
        f2.l_q=f2.l_q->m__0succ;
      }
      for(;;){
        struct f3_t : public bbGCFrame{
          t_std_collections_List_1Tt_mx2_CaseExpr_2_Node* l_t{};
          void gcMark(){
            bbGCMarkPtr(l_t);
          }
        }f3{};
        if(((bbBool(l_psize)&&bbBool(l_qsize))&&(f2.l_q!=this->m__0head))){
          bbInt l_cc=l_compareFunc(f1.l_p->m__0value,f2.l_q->m__0value);
          if((l_cc<=bbInt(0))){
            f3.l_t=f1.l_p;
            f1.l_p=f1.l_p->m__0succ;
            l_psize-=1;
          }else{
            f3.l_t=f2.l_q;
            f2.l_q=f2.l_q->m__0succ;
            l_qsize-=1;
          }
        }else if(bbBool(l_psize)){
          f3.l_t=f1.l_p;
          f1.l_p=f1.l_p->m__0succ;
          l_psize-=1;
        }else if((bbBool(l_qsize)&&(f2.l_q!=this->m__0head))){
          f3.l_t=f2.l_q;
          f2.l_q=f2.l_q->m__0succ;
          l_qsize-=1;
        }else{
          break;
        }
        f3.l_t->m__0pred=f1.l_tail;
        f1.l_tail->m__0succ=f3.l_t;
        f1.l_tail=f3.l_t;
      }
      f1.l_p=f2.l_q;
    }
    f1.l_tail->m__0succ=this->m__0head;
    this->m__0head->m__0pred=f1.l_tail;
    if((l_merges<=1)){
      return;
    }
    l_insize*=2;
  }
}

void t_std_collections_List_1Tt_mx2_CaseExpr_2::m_Sort(bbBool l_ascending){
  if(l_ascending){
    struct lambda44 : public bbFunction<bbInt(t_mx2_CaseExpr*,t_mx2_CaseExpr*)>::Rep{
      t_std_collections_List_1Tt_mx2_CaseExpr_2* l_self;
      lambda44(t_std_collections_List_1Tt_mx2_CaseExpr_2* l_self):l_self(l_self){
      }
      bbInt invoke(t_mx2_CaseExpr* l_x,t_mx2_CaseExpr* l_y){
        return bbCompare(l_x,l_y);
      }
      void gcMark(){
        bbGCMarkPtr(l_self);
      }
    };
    this->m_Sort(bbFunction<bbInt(t_mx2_CaseExpr*,t_mx2_CaseExpr*)>(new lambda44(this)));
  }else{
    struct lambda45 : public bbFunction<bbInt(t_mx2_CaseExpr*,t_mx2_CaseExpr*)>::Rep{
      t_std_collections_List_1Tt_mx2_CaseExpr_2* l_self;
      lambda45(t_std_collections_List_1Tt_mx2_CaseExpr_2* l_self):l_self(l_self){
      }
      bbInt invoke(t_mx2_CaseExpr* l_x,t_mx2_CaseExpr* l_y){
        return -bbCompare(l_x,l_y);
      }
      void gcMark(){
        bbGCMarkPtr(l_self);
      }
    };
    this->m_Sort(bbFunction<bbInt(t_mx2_CaseExpr*,t_mx2_CaseExpr*)>(new lambda45(this)));
  }
}

t_mx2_CaseExpr* t_std_collections_List_1Tt_mx2_CaseExpr_2::m_RemoveLast(){
  struct f0_t : public bbGCFrame{
    t_mx2_CaseExpr* l_value{};
    void gcMark(){
      bbGCMarkPtr(l_value);
    }
  }f0{};
  bbDebugAssert(!this->m_Empty(),BB_T("Debug assert failed"));
  f0.l_value=this->m__0head->m__0pred->m__0value;
  this->m__0head->m__0pred->m_Remove();
  this->m__0seq+=1;
  return f0.l_value;
}

bbBool t_std_collections_List_1Tt_mx2_CaseExpr_2::m_RemoveLast(t_mx2_CaseExpr* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_mx2_CaseExpr_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m_FindLastNode(l_value);
  if(!bbBool(f0.l_node)){
    return false;
  }
  f0.l_node->m_Remove();
  this->m__0seq+=1;
  return true;
}

t_mx2_CaseExpr* t_std_collections_List_1Tt_mx2_CaseExpr_2::m_RemoveFirst(){
  struct f0_t : public bbGCFrame{
    t_mx2_CaseExpr* l_value{};
    void gcMark(){
      bbGCMarkPtr(l_value);
    }
  }f0{};
  bbDebugAssert(!this->m_Empty(),BB_T("Debug assert failed"));
  f0.l_value=this->m__0head->m__0succ->m__0value;
  this->m__0head->m__0succ->m_Remove();
  this->m__0seq+=1;
  return f0.l_value;
}

bbInt t_std_collections_List_1Tt_mx2_CaseExpr_2::m_RemoveEach(t_mx2_CaseExpr* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_mx2_CaseExpr_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m__0head->m__0succ;
  bbInt l_n=bbInt(0);
  while((f0.l_node!=this->m__0head)){
    if((f0.l_node->m__0value==l_value)){
      f0.l_node=f0.l_node->m__0succ;
      f0.l_node->m__0pred->m_Remove();
      l_n+=1;
    }else{
      f0.l_node=f0.l_node->m__0succ;
    }
  }
  if(bbBool(l_n)){
    this->m__0seq+=1;
  }
  return l_n;
}

bbBool t_std_collections_List_1Tt_mx2_CaseExpr_2::m_Remove(t_mx2_CaseExpr* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_mx2_CaseExpr_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m_FindNode(l_value);
  if(!bbBool(f0.l_node)){
    return false;
  }
  f0.l_node->m_Remove();
  this->m__0seq+=1;
  return true;
}

t_std_collections_List_1Tt_mx2_CaseExpr_2_Node* t_std_collections_List_1Tt_mx2_CaseExpr_2::m_LastNode(){
  if(!this->m_Empty()){
    return this->m__0head->m__0pred;
  }
  return ((t_std_collections_List_1Tt_mx2_CaseExpr_2_Node*)0);
}

t_mx2_CaseExpr* t_std_collections_List_1Tt_mx2_CaseExpr_2::m_Last(){
  bbDebugAssert(!this->m_Empty(),BB_T("Debug assert failed"));
  return this->m__0head->m__0pred->m__0value;
}

t_std_collections_List_1Tt_mx2_CaseExpr_2_Node* t_std_collections_List_1Tt_mx2_CaseExpr_2::m_HeadNode(){
  return this->m__0head;
}

t_std_collections_List_1Tt_mx2_CaseExpr_2_Node* t_std_collections_List_1Tt_mx2_CaseExpr_2::m_FirstNode(){
  if(!this->m_Empty()){
    return this->m__0head->m__0succ;
  }
  return ((t_std_collections_List_1Tt_mx2_CaseExpr_2_Node*)0);
}

t_mx2_CaseExpr* t_std_collections_List_1Tt_mx2_CaseExpr_2::m_First(){
  bbDebugAssert(!this->m_Empty(),BB_T("Debug assert failed"));
  return this->m__0head->m__0succ->m__0value;
}

t_std_collections_List_1Tt_mx2_CaseExpr_2_Node* t_std_collections_List_1Tt_mx2_CaseExpr_2::m_FindNode(t_mx2_CaseExpr* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_mx2_CaseExpr_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m__0head->m__0succ;
  while((f0.l_node!=this->m__0head)){
    if((f0.l_node->m__0value==l_value)){
      return f0.l_node;
    }
    f0.l_node=f0.l_node->m__0succ;
  }
  return ((t_std_collections_List_1Tt_mx2_CaseExpr_2_Node*)0);
}

t_std_collections_List_1Tt_mx2_CaseExpr_2_Node* t_std_collections_List_1Tt_mx2_CaseExpr_2::m_FindLastNode(t_mx2_CaseExpr* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_mx2_CaseExpr_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m__0head->m__0pred;
  while((f0.l_node!=this->m__0head)){
    if((f0.l_node->m__0value==l_value)){
      return f0.l_node;
    }
    f0.l_node=f0.l_node->m__0pred;
  }
  return ((t_std_collections_List_1Tt_mx2_CaseExpr_2_Node*)0);
}

bbBool t_std_collections_List_1Tt_mx2_CaseExpr_2::m_Empty(){
  return (this->m__0head->m__0succ==this->m__0head);
}

bbInt t_std_collections_List_1Tt_mx2_CaseExpr_2::m_Count(){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_mx2_CaseExpr_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m__0head->m__0succ;
  bbInt l_n=bbInt(0);
  while((f0.l_node!=this->m__0head)){
    f0.l_node=f0.l_node->m__0succ;
    l_n+=1;
  }
  return l_n;
}

void t_std_collections_List_1Tt_mx2_CaseExpr_2::m_Clear(){
  this->m__0head->m__0succ=this->m__0head;
  this->m__0head->m__0pred=this->m__0head;
  this->m__0seq+=1;
}

t_std_collections_List_1Tt_mx2_CaseExpr_2_BackwardsIterator t_std_collections_List_1Tt_mx2_CaseExpr_2::m_Backwards(){
  return t_std_collections_List_1Tt_mx2_CaseExpr_2_BackwardsIterator(this,this->m__0head->m__0pred);
}

t_std_collections_List_1Tt_mx2_CaseExpr_2_Iterator t_std_collections_List_1Tt_mx2_CaseExpr_2::m_All(){
  return t_std_collections_List_1Tt_mx2_CaseExpr_2_Iterator(this,this->m__0head->m__0succ);
}

t_std_collections_List_1Tt_mx2_CaseExpr_2_Node* t_std_collections_List_1Tt_mx2_CaseExpr_2::m_AddLast(t_mx2_CaseExpr* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_mx2_CaseExpr_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=bbGCNew<t_std_collections_List_1Tt_mx2_CaseExpr_2_Node>(l_value,this->m__0head);
  this->m__0seq+=1;
  return f0.l_node;
}

t_std_collections_List_1Tt_mx2_CaseExpr_2_Node* t_std_collections_List_1Tt_mx2_CaseExpr_2::m_AddFirst(t_mx2_CaseExpr* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_mx2_CaseExpr_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=bbGCNew<t_std_collections_List_1Tt_mx2_CaseExpr_2_Node>(l_value,this->m__0head->m__0succ);
  this->m__0seq+=1;
  return f0.l_node;
}

void t_std_collections_List_1Tt_mx2_CaseExpr_2::m_AddAll(bbArray<bbGCVar<t_mx2_CaseExpr>>* l_values){
  {
    bbInt l_0=bbInt(0);
    bbInt l_1=l_values->length();
    for(;(l_0<l_1);l_0+=1){
      struct f2_t : public bbGCFrame{
        t_mx2_CaseExpr* l_value{};
        void gcMark(){
          bbGCMarkPtr(l_value);
        }
      }f2{};
      f2.l_value=l_values->at(l_0);
      this->m_AddLast(f2.l_value);
    }
  }
}

void t_std_collections_List_1Tt_mx2_CaseExpr_2::m_Add(t_mx2_CaseExpr* l_value){
  this->m_AddLast(l_value);
}

void t_std_collections_List_1Tt_mx2_Expr_2_Node::gcMark(){
  bbGCMark(m__0succ);
  bbGCMark(m__0pred);
  bbGCMark(m__0value);
}

t_std_collections_List_1Tt_mx2_Expr_2_Node::t_std_collections_List_1Tt_mx2_Expr_2_Node(t_mx2_Expr* l_value,t_std_collections_List_1Tt_mx2_Expr_2_Node* l_succ){
  this->m__0value=l_value;
  this->m__0succ=l_succ;
  this->m__0pred=l_succ->m__0pred;
  this->m__0pred->m__0succ=this;
  l_succ->m__0pred=this;
}

t_std_collections_List_1Tt_mx2_Expr_2_Node::t_std_collections_List_1Tt_mx2_Expr_2_Node(t_mx2_Expr* l_value){
  this->m__0value=l_value;
  this->m__0succ=this;
  this->m__0pred=this;
}

void t_std_collections_List_1Tt_mx2_Expr_2_Node::m_Value(t_mx2_Expr* l_value){
  this->m__0value=l_value;
}

t_mx2_Expr* t_std_collections_List_1Tt_mx2_Expr_2_Node::m_Value(){
  return this->m__0value;
}

t_std_collections_List_1Tt_mx2_Expr_2_Node* t_std_collections_List_1Tt_mx2_Expr_2_Node::m_Succ(){
  return this->m__0succ;
}

void t_std_collections_List_1Tt_mx2_Expr_2_Node::m_Remove(){
  this->m__0succ->m__0pred=this->m__0pred;
  this->m__0pred->m__0succ=this->m__0succ;
}

t_std_collections_List_1Tt_mx2_Expr_2_Node* t_std_collections_List_1Tt_mx2_Expr_2_Node::m_Pred(){
  return this->m__0pred;
}

void t_std_collections_List_1Tt_mx2_Expr_2_Node::m_InsertBefore(t_std_collections_List_1Tt_mx2_Expr_2_Node* l_node){
  this->m__0succ=l_node;
  this->m__0pred=l_node->m__0pred;
  this->m__0pred->m__0succ=this;
  l_node->m__0pred=this;
}

void t_std_collections_List_1Tt_mx2_Expr_2_Node::m_InsertAfter(t_std_collections_List_1Tt_mx2_Expr_2_Node* l_node){
  this->m__0pred=l_node;
  this->m__0succ=l_node->m__0succ;
  this->m__0succ->m__0pred=this;
  l_node->m__0succ=this;
}

t_std_collections_List_1Tt_mx2_Expr_2_Iterator::t_std_collections_List_1Tt_mx2_Expr_2_Iterator(t_std_collections_List_1Tt_mx2_Expr_2* l_list,t_std_collections_List_1Tt_mx2_Expr_2_Node* l_node){
  (*this).m__0list=l_list;
  (*this).m__0node=l_node;
  (*this).m__0seq=l_list->m__0seq;
}

void t_std_collections_List_1Tt_mx2_Expr_2_Iterator::m_Insert(t_mx2_Expr* l_value){
  (*this).m_AssertSeq();
  (*this).m__0node=bbGCNew<t_std_collections_List_1Tt_mx2_Expr_2_Node>(l_value,(*this).m__0node);
  (*this).m__0list->m__0seq+=1;
  (*this).m__0seq=(*this).m__0list->m__0seq;
}

void t_std_collections_List_1Tt_mx2_Expr_2_Iterator::m_Erase(){
  (*this).m_AssertCurrent();
  (*this).m__0node=(*this).m__0node->m__0succ;
  (*this).m__0node->m__0pred->m_Remove();
  (*this).m__0list->m__0seq+=1;
  (*this).m__0seq=(*this).m__0list->m__0seq;
}

void t_std_collections_List_1Tt_mx2_Expr_2_Iterator::m_Current(t_mx2_Expr* l_current){
  (*this).m_AssertCurrent();
  (*this).m__0node->m__0value=l_current;
}

t_mx2_Expr* t_std_collections_List_1Tt_mx2_Expr_2_Iterator::m_Current(){
  (*this).m_AssertCurrent();
  return (*this).m__0node->m__0value;
}

void t_std_collections_List_1Tt_mx2_Expr_2_Iterator::m_Bump(){
  (*this).m_AssertCurrent();
  (*this).m__0node=(*this).m__0node->m__0succ;
}

bbBool t_std_collections_List_1Tt_mx2_Expr_2_Iterator::m_AtEnd(){
  (*this).m_AssertSeq();
  return ((*this).m__0node==(*this).m__0list->m__0head);
}

void t_std_collections_List_1Tt_mx2_Expr_2_Iterator::m_AssertSeq(){
  bbDebugAssert(((*this).m__0seq==(*this).m__0list->m__0seq),BB_T("Concurrent list modification"));
}

void t_std_collections_List_1Tt_mx2_Expr_2_Iterator::m_AssertCurrent(){
  bbDebugAssert(!(*this).m_AtEnd(),BB_T("Invalid list iterator"));
}

int bbCompare(const t_std_collections_List_1Tt_mx2_Expr_2_Iterator&x,const t_std_collections_List_1Tt_mx2_Expr_2_Iterator&y){
  if(int t=bbCompare(x.m__0list,y.m__0list)) return t;
  if(int t=bbCompare(x.m__0node,y.m__0node)) return t;
  if(int t=bbCompare(x.m__0seq,y.m__0seq)) return t;
  return 0;
}

void bbGCMark(const t_std_collections_List_1Tt_mx2_Expr_2_Iterator&t){
  bbGCMark(t.m__0list);
  bbGCMark(t.m__0node);
}

t_std_collections_List_1Tt_mx2_Expr_2_BackwardsIterator::t_std_collections_List_1Tt_mx2_Expr_2_BackwardsIterator(t_std_collections_List_1Tt_mx2_Expr_2* l_list,t_std_collections_List_1Tt_mx2_Expr_2_Node* l_node){
  (*this).m__0list=l_list;
  (*this).m__0node=l_node;
  (*this).m__0seq=l_list->m__0seq;
}

void t_std_collections_List_1Tt_mx2_Expr_2_BackwardsIterator::m_Insert(t_mx2_Expr* l_value){
  (*this).m_AssertSeq();
  (*this).m__0node=bbGCNew<t_std_collections_List_1Tt_mx2_Expr_2_Node>(l_value,(*this).m__0node->m__0succ);
  (*this).m__0list->m__0seq+=1;
  (*this).m__0seq=(*this).m__0list->m__0seq;
}

void t_std_collections_List_1Tt_mx2_Expr_2_BackwardsIterator::m_Erase(){
  (*this).m_AssertCurrent();
  (*this).m__0node=(*this).m__0node->m__0pred;
  (*this).m__0node->m__0succ->m_Remove();
  (*this).m__0list->m__0seq+=1;
  (*this).m__0seq=(*this).m__0list->m__0seq;
}

void t_std_collections_List_1Tt_mx2_Expr_2_BackwardsIterator::m_Current(t_mx2_Expr* l_current){
  (*this).m_AssertCurrent();
  (*this).m__0node->m__0value=l_current;
}

t_mx2_Expr* t_std_collections_List_1Tt_mx2_Expr_2_BackwardsIterator::m_Current(){
  (*this).m_AssertCurrent();
  return (*this).m__0node->m__0value;
}

void t_std_collections_List_1Tt_mx2_Expr_2_BackwardsIterator::m_Bump(){
  (*this).m_AssertCurrent();
  (*this).m__0node=(*this).m__0node->m__0pred;
}

bbBool t_std_collections_List_1Tt_mx2_Expr_2_BackwardsIterator::m_AtEnd(){
  (*this).m_AssertSeq();
  return ((*this).m__0node==(*this).m__0list->m__0head);
}

void t_std_collections_List_1Tt_mx2_Expr_2_BackwardsIterator::m_AssertSeq(){
  bbDebugAssert(((*this).m__0seq==(*this).m__0list->m__0seq),BB_T("Concurrent list modification"));
}

void t_std_collections_List_1Tt_mx2_Expr_2_BackwardsIterator::m_AssertCurrent(){
  bbDebugAssert(!(*this).m_AtEnd(),BB_T("Invalid list iterator"));
}

int bbCompare(const t_std_collections_List_1Tt_mx2_Expr_2_BackwardsIterator&x,const t_std_collections_List_1Tt_mx2_Expr_2_BackwardsIterator&y){
  if(int t=bbCompare(x.m__0list,y.m__0list)) return t;
  if(int t=bbCompare(x.m__0node,y.m__0node)) return t;
  if(int t=bbCompare(x.m__0seq,y.m__0seq)) return t;
  return 0;
}

void bbGCMark(const t_std_collections_List_1Tt_mx2_Expr_2_BackwardsIterator&t){
  bbGCMark(t.m__0list);
  bbGCMark(t.m__0node);
}

void t_std_collections_List_1Tt_mx2_Expr_2::gcMark(){
  bbGCMark(m__0head);
}

t_std_collections_List_1Tt_mx2_Expr_2::t_std_collections_List_1Tt_mx2_Expr_2(t_std_collections_List_1Tt_mx2_Expr_2* l_values):t_std_collections_List_1Tt_mx2_Expr_2(){
  g_std_collections_List_1Tt_mx2_Expr_2_AddAll_1Tt_std_collections_List_1Tt_mx2_Expr_2_2(this,l_values);
}

t_std_collections_List_1Tt_mx2_Expr_2::t_std_collections_List_1Tt_mx2_Expr_2(t_std_collections_Stack_1Tt_mx2_Expr_2* l_values):t_std_collections_List_1Tt_mx2_Expr_2(){
  g_std_collections_List_1Tt_mx2_Expr_2_AddAll_1Tt_std_collections_Stack_1Tt_mx2_Expr_2_2(this,l_values);
}

t_std_collections_List_1Tt_mx2_Expr_2::t_std_collections_List_1Tt_mx2_Expr_2(bbArray<bbGCVar<t_mx2_Expr>>* l_values):t_std_collections_List_1Tt_mx2_Expr_2(){
  this->m_AddAll(l_values);
}

t_std_collections_List_1Tt_mx2_Expr_2::t_std_collections_List_1Tt_mx2_Expr_2(){
  this->m__0head=bbGCNew<t_std_collections_List_1Tt_mx2_Expr_2_Node>(((t_mx2_Expr*)0));
}

bbArray<bbGCVar<t_mx2_Expr>>* t_std_collections_List_1Tt_mx2_Expr_2::m_ToArray(){
  struct f0_t : public bbGCFrame{
    bbArray<bbGCVar<t_mx2_Expr>>* l_data{};
    t_std_collections_List_1Tt_mx2_Expr_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_data);
      bbGCMarkPtr(l_node);
    }
  }f0{};
  bbInt l_n=this->m_Count();
  f0.l_data=bbArray<bbGCVar<t_mx2_Expr>>::create(l_n);
  f0.l_node=this->m__0head->m__0succ;
  {
    bbInt l_i=bbInt(0);
    for(;(l_i<l_n);l_i+=1){
      f0.l_data->at(l_i)=f0.l_node->m__0value;
      f0.l_node=f0.l_node->m__0succ;
    }
  }
  return f0.l_data;
}

void t_std_collections_List_1Tt_mx2_Expr_2::m_Sort(bbFunction<bbInt(t_mx2_Expr*,t_mx2_Expr*)> l_compareFunc){
  bbInt l_insize=1;
  for(;;){
    struct f1_t : public bbGCFrame{
      t_std_collections_List_1Tt_mx2_Expr_2_Node* l_p{};
      t_std_collections_List_1Tt_mx2_Expr_2_Node* l_tail{};
      void gcMark(){
        bbGCMarkPtr(l_p);
        bbGCMarkPtr(l_tail);
      }
    }f1{};
    bbInt l_merges=bbInt(0);
    f1.l_tail=this->m__0head;
    f1.l_p=this->m__0head->m__0succ;
    while((f1.l_p!=this->m__0head)){
      struct f2_t : public bbGCFrame{
        t_std_collections_List_1Tt_mx2_Expr_2_Node* l_q{};
        void gcMark(){
          bbGCMarkPtr(l_q);
        }
      }f2{};
      l_merges+=1;
      f2.l_q=f1.l_p->m__0succ;
      bbInt l_qsize=l_insize;
      bbInt l_psize=1;
      while(((l_psize<l_insize)&&(f2.l_q!=this->m__0head))){
        l_psize+=1;
        f2.l_q=f2.l_q->m__0succ;
      }
      for(;;){
        struct f3_t : public bbGCFrame{
          t_std_collections_List_1Tt_mx2_Expr_2_Node* l_t{};
          void gcMark(){
            bbGCMarkPtr(l_t);
          }
        }f3{};
        if(((bbBool(l_psize)&&bbBool(l_qsize))&&(f2.l_q!=this->m__0head))){
          bbInt l_cc=l_compareFunc(f1.l_p->m__0value,f2.l_q->m__0value);
          if((l_cc<=bbInt(0))){
            f3.l_t=f1.l_p;
            f1.l_p=f1.l_p->m__0succ;
            l_psize-=1;
          }else{
            f3.l_t=f2.l_q;
            f2.l_q=f2.l_q->m__0succ;
            l_qsize-=1;
          }
        }else if(bbBool(l_psize)){
          f3.l_t=f1.l_p;
          f1.l_p=f1.l_p->m__0succ;
          l_psize-=1;
        }else if((bbBool(l_qsize)&&(f2.l_q!=this->m__0head))){
          f3.l_t=f2.l_q;
          f2.l_q=f2.l_q->m__0succ;
          l_qsize-=1;
        }else{
          break;
        }
        f3.l_t->m__0pred=f1.l_tail;
        f1.l_tail->m__0succ=f3.l_t;
        f1.l_tail=f3.l_t;
      }
      f1.l_p=f2.l_q;
    }
    f1.l_tail->m__0succ=this->m__0head;
    this->m__0head->m__0pred=f1.l_tail;
    if((l_merges<=1)){
      return;
    }
    l_insize*=2;
  }
}

void t_std_collections_List_1Tt_mx2_Expr_2::m_Sort(bbBool l_ascending){
  if(l_ascending){
    struct lambda46 : public bbFunction<bbInt(t_mx2_Expr*,t_mx2_Expr*)>::Rep{
      t_std_collections_List_1Tt_mx2_Expr_2* l_self;
      lambda46(t_std_collections_List_1Tt_mx2_Expr_2* l_self):l_self(l_self){
      }
      bbInt invoke(t_mx2_Expr* l_x,t_mx2_Expr* l_y){
        return bbCompare(l_x,l_y);
      }
      void gcMark(){
        bbGCMarkPtr(l_self);
      }
    };
    this->m_Sort(bbFunction<bbInt(t_mx2_Expr*,t_mx2_Expr*)>(new lambda46(this)));
  }else{
    struct lambda47 : public bbFunction<bbInt(t_mx2_Expr*,t_mx2_Expr*)>::Rep{
      t_std_collections_List_1Tt_mx2_Expr_2* l_self;
      lambda47(t_std_collections_List_1Tt_mx2_Expr_2* l_self):l_self(l_self){
      }
      bbInt invoke(t_mx2_Expr* l_x,t_mx2_Expr* l_y){
        return -bbCompare(l_x,l_y);
      }
      void gcMark(){
        bbGCMarkPtr(l_self);
      }
    };
    this->m_Sort(bbFunction<bbInt(t_mx2_Expr*,t_mx2_Expr*)>(new lambda47(this)));
  }
}

t_mx2_Expr* t_std_collections_List_1Tt_mx2_Expr_2::m_RemoveLast(){
  struct f0_t : public bbGCFrame{
    t_mx2_Expr* l_value{};
    void gcMark(){
      bbGCMarkPtr(l_value);
    }
  }f0{};
  bbDebugAssert(!this->m_Empty(),BB_T("Debug assert failed"));
  f0.l_value=this->m__0head->m__0pred->m__0value;
  this->m__0head->m__0pred->m_Remove();
  this->m__0seq+=1;
  return f0.l_value;
}

bbBool t_std_collections_List_1Tt_mx2_Expr_2::m_RemoveLast(t_mx2_Expr* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_mx2_Expr_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m_FindLastNode(l_value);
  if(!bbBool(f0.l_node)){
    return false;
  }
  f0.l_node->m_Remove();
  this->m__0seq+=1;
  return true;
}

t_mx2_Expr* t_std_collections_List_1Tt_mx2_Expr_2::m_RemoveFirst(){
  struct f0_t : public bbGCFrame{
    t_mx2_Expr* l_value{};
    void gcMark(){
      bbGCMarkPtr(l_value);
    }
  }f0{};
  bbDebugAssert(!this->m_Empty(),BB_T("Debug assert failed"));
  f0.l_value=this->m__0head->m__0succ->m__0value;
  this->m__0head->m__0succ->m_Remove();
  this->m__0seq+=1;
  return f0.l_value;
}

bbInt t_std_collections_List_1Tt_mx2_Expr_2::m_RemoveEach(t_mx2_Expr* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_mx2_Expr_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m__0head->m__0succ;
  bbInt l_n=bbInt(0);
  while((f0.l_node!=this->m__0head)){
    if((f0.l_node->m__0value==l_value)){
      f0.l_node=f0.l_node->m__0succ;
      f0.l_node->m__0pred->m_Remove();
      l_n+=1;
    }else{
      f0.l_node=f0.l_node->m__0succ;
    }
  }
  if(bbBool(l_n)){
    this->m__0seq+=1;
  }
  return l_n;
}

bbBool t_std_collections_List_1Tt_mx2_Expr_2::m_Remove(t_mx2_Expr* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_mx2_Expr_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m_FindNode(l_value);
  if(!bbBool(f0.l_node)){
    return false;
  }
  f0.l_node->m_Remove();
  this->m__0seq+=1;
  return true;
}

t_std_collections_List_1Tt_mx2_Expr_2_Node* t_std_collections_List_1Tt_mx2_Expr_2::m_LastNode(){
  if(!this->m_Empty()){
    return this->m__0head->m__0pred;
  }
  return ((t_std_collections_List_1Tt_mx2_Expr_2_Node*)0);
}

t_mx2_Expr* t_std_collections_List_1Tt_mx2_Expr_2::m_Last(){
  bbDebugAssert(!this->m_Empty(),BB_T("Debug assert failed"));
  return this->m__0head->m__0pred->m__0value;
}

t_std_collections_List_1Tt_mx2_Expr_2_Node* t_std_collections_List_1Tt_mx2_Expr_2::m_HeadNode(){
  return this->m__0head;
}

t_std_collections_List_1Tt_mx2_Expr_2_Node* t_std_collections_List_1Tt_mx2_Expr_2::m_FirstNode(){
  if(!this->m_Empty()){
    return this->m__0head->m__0succ;
  }
  return ((t_std_collections_List_1Tt_mx2_Expr_2_Node*)0);
}

t_mx2_Expr* t_std_collections_List_1Tt_mx2_Expr_2::m_First(){
  bbDebugAssert(!this->m_Empty(),BB_T("Debug assert failed"));
  return this->m__0head->m__0succ->m__0value;
}

t_std_collections_List_1Tt_mx2_Expr_2_Node* t_std_collections_List_1Tt_mx2_Expr_2::m_FindNode(t_mx2_Expr* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_mx2_Expr_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m__0head->m__0succ;
  while((f0.l_node!=this->m__0head)){
    if((f0.l_node->m__0value==l_value)){
      return f0.l_node;
    }
    f0.l_node=f0.l_node->m__0succ;
  }
  return ((t_std_collections_List_1Tt_mx2_Expr_2_Node*)0);
}

t_std_collections_List_1Tt_mx2_Expr_2_Node* t_std_collections_List_1Tt_mx2_Expr_2::m_FindLastNode(t_mx2_Expr* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_mx2_Expr_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m__0head->m__0pred;
  while((f0.l_node!=this->m__0head)){
    if((f0.l_node->m__0value==l_value)){
      return f0.l_node;
    }
    f0.l_node=f0.l_node->m__0pred;
  }
  return ((t_std_collections_List_1Tt_mx2_Expr_2_Node*)0);
}

bbBool t_std_collections_List_1Tt_mx2_Expr_2::m_Empty(){
  return (this->m__0head->m__0succ==this->m__0head);
}

bbInt t_std_collections_List_1Tt_mx2_Expr_2::m_Count(){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_mx2_Expr_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m__0head->m__0succ;
  bbInt l_n=bbInt(0);
  while((f0.l_node!=this->m__0head)){
    f0.l_node=f0.l_node->m__0succ;
    l_n+=1;
  }
  return l_n;
}

void t_std_collections_List_1Tt_mx2_Expr_2::m_Clear(){
  this->m__0head->m__0succ=this->m__0head;
  this->m__0head->m__0pred=this->m__0head;
  this->m__0seq+=1;
}

t_std_collections_List_1Tt_mx2_Expr_2_BackwardsIterator t_std_collections_List_1Tt_mx2_Expr_2::m_Backwards(){
  return t_std_collections_List_1Tt_mx2_Expr_2_BackwardsIterator(this,this->m__0head->m__0pred);
}

t_std_collections_List_1Tt_mx2_Expr_2_Iterator t_std_collections_List_1Tt_mx2_Expr_2::m_All(){
  return t_std_collections_List_1Tt_mx2_Expr_2_Iterator(this,this->m__0head->m__0succ);
}

t_std_collections_List_1Tt_mx2_Expr_2_Node* t_std_collections_List_1Tt_mx2_Expr_2::m_AddLast(t_mx2_Expr* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_mx2_Expr_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=bbGCNew<t_std_collections_List_1Tt_mx2_Expr_2_Node>(l_value,this->m__0head);
  this->m__0seq+=1;
  return f0.l_node;
}

t_std_collections_List_1Tt_mx2_Expr_2_Node* t_std_collections_List_1Tt_mx2_Expr_2::m_AddFirst(t_mx2_Expr* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_mx2_Expr_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=bbGCNew<t_std_collections_List_1Tt_mx2_Expr_2_Node>(l_value,this->m__0head->m__0succ);
  this->m__0seq+=1;
  return f0.l_node;
}

void t_std_collections_List_1Tt_mx2_Expr_2::m_AddAll(bbArray<bbGCVar<t_mx2_Expr>>* l_values){
  {
    bbInt l_0=bbInt(0);
    bbInt l_1=l_values->length();
    for(;(l_0<l_1);l_0+=1){
      struct f2_t : public bbGCFrame{
        t_mx2_Expr* l_value{};
        void gcMark(){
          bbGCMarkPtr(l_value);
        }
      }f2{};
      f2.l_value=l_values->at(l_0);
      this->m_AddLast(f2.l_value);
    }
  }
}

void t_std_collections_List_1Tt_mx2_Expr_2::m_Add(t_mx2_Expr* l_value){
  this->m_AddLast(l_value);
}

void t_std_collections_List_1Tt_mx2_VarDecl_2_Node::gcMark(){
  bbGCMark(m__0succ);
  bbGCMark(m__0pred);
  bbGCMark(m__0value);
}

t_std_collections_List_1Tt_mx2_VarDecl_2_Node::t_std_collections_List_1Tt_mx2_VarDecl_2_Node(t_mx2_VarDecl* l_value,t_std_collections_List_1Tt_mx2_VarDecl_2_Node* l_succ){
  this->m__0value=l_value;
  this->m__0succ=l_succ;
  this->m__0pred=l_succ->m__0pred;
  this->m__0pred->m__0succ=this;
  l_succ->m__0pred=this;
}

t_std_collections_List_1Tt_mx2_VarDecl_2_Node::t_std_collections_List_1Tt_mx2_VarDecl_2_Node(t_mx2_VarDecl* l_value){
  this->m__0value=l_value;
  this->m__0succ=this;
  this->m__0pred=this;
}

void t_std_collections_List_1Tt_mx2_VarDecl_2_Node::m_Value(t_mx2_VarDecl* l_value){
  this->m__0value=l_value;
}

t_mx2_VarDecl* t_std_collections_List_1Tt_mx2_VarDecl_2_Node::m_Value(){
  return this->m__0value;
}

t_std_collections_List_1Tt_mx2_VarDecl_2_Node* t_std_collections_List_1Tt_mx2_VarDecl_2_Node::m_Succ(){
  return this->m__0succ;
}

void t_std_collections_List_1Tt_mx2_VarDecl_2_Node::m_Remove(){
  this->m__0succ->m__0pred=this->m__0pred;
  this->m__0pred->m__0succ=this->m__0succ;
}

t_std_collections_List_1Tt_mx2_VarDecl_2_Node* t_std_collections_List_1Tt_mx2_VarDecl_2_Node::m_Pred(){
  return this->m__0pred;
}

void t_std_collections_List_1Tt_mx2_VarDecl_2_Node::m_InsertBefore(t_std_collections_List_1Tt_mx2_VarDecl_2_Node* l_node){
  this->m__0succ=l_node;
  this->m__0pred=l_node->m__0pred;
  this->m__0pred->m__0succ=this;
  l_node->m__0pred=this;
}

void t_std_collections_List_1Tt_mx2_VarDecl_2_Node::m_InsertAfter(t_std_collections_List_1Tt_mx2_VarDecl_2_Node* l_node){
  this->m__0pred=l_node;
  this->m__0succ=l_node->m__0succ;
  this->m__0succ->m__0pred=this;
  l_node->m__0succ=this;
}

t_std_collections_List_1Tt_mx2_VarDecl_2_Iterator::t_std_collections_List_1Tt_mx2_VarDecl_2_Iterator(t_std_collections_List_1Tt_mx2_VarDecl_2* l_list,t_std_collections_List_1Tt_mx2_VarDecl_2_Node* l_node){
  (*this).m__0list=l_list;
  (*this).m__0node=l_node;
  (*this).m__0seq=l_list->m__0seq;
}

void t_std_collections_List_1Tt_mx2_VarDecl_2_Iterator::m_Insert(t_mx2_VarDecl* l_value){
  (*this).m_AssertSeq();
  (*this).m__0node=bbGCNew<t_std_collections_List_1Tt_mx2_VarDecl_2_Node>(l_value,(*this).m__0node);
  (*this).m__0list->m__0seq+=1;
  (*this).m__0seq=(*this).m__0list->m__0seq;
}

void t_std_collections_List_1Tt_mx2_VarDecl_2_Iterator::m_Erase(){
  (*this).m_AssertCurrent();
  (*this).m__0node=(*this).m__0node->m__0succ;
  (*this).m__0node->m__0pred->m_Remove();
  (*this).m__0list->m__0seq+=1;
  (*this).m__0seq=(*this).m__0list->m__0seq;
}

void t_std_collections_List_1Tt_mx2_VarDecl_2_Iterator::m_Current(t_mx2_VarDecl* l_current){
  (*this).m_AssertCurrent();
  (*this).m__0node->m__0value=l_current;
}

t_mx2_VarDecl* t_std_collections_List_1Tt_mx2_VarDecl_2_Iterator::m_Current(){
  (*this).m_AssertCurrent();
  return (*this).m__0node->m__0value;
}

void t_std_collections_List_1Tt_mx2_VarDecl_2_Iterator::m_Bump(){
  (*this).m_AssertCurrent();
  (*this).m__0node=(*this).m__0node->m__0succ;
}

bbBool t_std_collections_List_1Tt_mx2_VarDecl_2_Iterator::m_AtEnd(){
  (*this).m_AssertSeq();
  return ((*this).m__0node==(*this).m__0list->m__0head);
}

void t_std_collections_List_1Tt_mx2_VarDecl_2_Iterator::m_AssertSeq(){
  bbDebugAssert(((*this).m__0seq==(*this).m__0list->m__0seq),BB_T("Concurrent list modification"));
}

void t_std_collections_List_1Tt_mx2_VarDecl_2_Iterator::m_AssertCurrent(){
  bbDebugAssert(!(*this).m_AtEnd(),BB_T("Invalid list iterator"));
}

int bbCompare(const t_std_collections_List_1Tt_mx2_VarDecl_2_Iterator&x,const t_std_collections_List_1Tt_mx2_VarDecl_2_Iterator&y){
  if(int t=bbCompare(x.m__0list,y.m__0list)) return t;
  if(int t=bbCompare(x.m__0node,y.m__0node)) return t;
  if(int t=bbCompare(x.m__0seq,y.m__0seq)) return t;
  return 0;
}

void bbGCMark(const t_std_collections_List_1Tt_mx2_VarDecl_2_Iterator&t){
  bbGCMark(t.m__0list);
  bbGCMark(t.m__0node);
}

t_std_collections_List_1Tt_mx2_VarDecl_2_BackwardsIterator::t_std_collections_List_1Tt_mx2_VarDecl_2_BackwardsIterator(t_std_collections_List_1Tt_mx2_VarDecl_2* l_list,t_std_collections_List_1Tt_mx2_VarDecl_2_Node* l_node){
  (*this).m__0list=l_list;
  (*this).m__0node=l_node;
  (*this).m__0seq=l_list->m__0seq;
}

void t_std_collections_List_1Tt_mx2_VarDecl_2_BackwardsIterator::m_Insert(t_mx2_VarDecl* l_value){
  (*this).m_AssertSeq();
  (*this).m__0node=bbGCNew<t_std_collections_List_1Tt_mx2_VarDecl_2_Node>(l_value,(*this).m__0node->m__0succ);
  (*this).m__0list->m__0seq+=1;
  (*this).m__0seq=(*this).m__0list->m__0seq;
}

void t_std_collections_List_1Tt_mx2_VarDecl_2_BackwardsIterator::m_Erase(){
  (*this).m_AssertCurrent();
  (*this).m__0node=(*this).m__0node->m__0pred;
  (*this).m__0node->m__0succ->m_Remove();
  (*this).m__0list->m__0seq+=1;
  (*this).m__0seq=(*this).m__0list->m__0seq;
}

void t_std_collections_List_1Tt_mx2_VarDecl_2_BackwardsIterator::m_Current(t_mx2_VarDecl* l_current){
  (*this).m_AssertCurrent();
  (*this).m__0node->m__0value=l_current;
}

t_mx2_VarDecl* t_std_collections_List_1Tt_mx2_VarDecl_2_BackwardsIterator::m_Current(){
  (*this).m_AssertCurrent();
  return (*this).m__0node->m__0value;
}

void t_std_collections_List_1Tt_mx2_VarDecl_2_BackwardsIterator::m_Bump(){
  (*this).m_AssertCurrent();
  (*this).m__0node=(*this).m__0node->m__0pred;
}

bbBool t_std_collections_List_1Tt_mx2_VarDecl_2_BackwardsIterator::m_AtEnd(){
  (*this).m_AssertSeq();
  return ((*this).m__0node==(*this).m__0list->m__0head);
}

void t_std_collections_List_1Tt_mx2_VarDecl_2_BackwardsIterator::m_AssertSeq(){
  bbDebugAssert(((*this).m__0seq==(*this).m__0list->m__0seq),BB_T("Concurrent list modification"));
}

void t_std_collections_List_1Tt_mx2_VarDecl_2_BackwardsIterator::m_AssertCurrent(){
  bbDebugAssert(!(*this).m_AtEnd(),BB_T("Invalid list iterator"));
}

int bbCompare(const t_std_collections_List_1Tt_mx2_VarDecl_2_BackwardsIterator&x,const t_std_collections_List_1Tt_mx2_VarDecl_2_BackwardsIterator&y){
  if(int t=bbCompare(x.m__0list,y.m__0list)) return t;
  if(int t=bbCompare(x.m__0node,y.m__0node)) return t;
  if(int t=bbCompare(x.m__0seq,y.m__0seq)) return t;
  return 0;
}

void bbGCMark(const t_std_collections_List_1Tt_mx2_VarDecl_2_BackwardsIterator&t){
  bbGCMark(t.m__0list);
  bbGCMark(t.m__0node);
}

void t_std_collections_List_1Tt_mx2_VarDecl_2::gcMark(){
  bbGCMark(m__0head);
}

t_std_collections_List_1Tt_mx2_VarDecl_2::t_std_collections_List_1Tt_mx2_VarDecl_2(t_std_collections_List_1Tt_mx2_VarDecl_2* l_values):t_std_collections_List_1Tt_mx2_VarDecl_2(){
  g_std_collections_List_1Tt_mx2_VarDecl_2_AddAll_1Tt_std_collections_List_1Tt_mx2_VarDecl_2_2(this,l_values);
}

t_std_collections_List_1Tt_mx2_VarDecl_2::t_std_collections_List_1Tt_mx2_VarDecl_2(t_std_collections_Stack_1Tt_mx2_VarDecl_2* l_values):t_std_collections_List_1Tt_mx2_VarDecl_2(){
  g_std_collections_List_1Tt_mx2_VarDecl_2_AddAll_1Tt_std_collections_Stack_1Tt_mx2_VarDecl_2_2(this,l_values);
}

t_std_collections_List_1Tt_mx2_VarDecl_2::t_std_collections_List_1Tt_mx2_VarDecl_2(bbArray<bbGCVar<t_mx2_VarDecl>>* l_values):t_std_collections_List_1Tt_mx2_VarDecl_2(){
  this->m_AddAll(l_values);
}

t_std_collections_List_1Tt_mx2_VarDecl_2::t_std_collections_List_1Tt_mx2_VarDecl_2(){
  this->m__0head=bbGCNew<t_std_collections_List_1Tt_mx2_VarDecl_2_Node>(((t_mx2_VarDecl*)0));
}

bbArray<bbGCVar<t_mx2_VarDecl>>* t_std_collections_List_1Tt_mx2_VarDecl_2::m_ToArray(){
  struct f0_t : public bbGCFrame{
    bbArray<bbGCVar<t_mx2_VarDecl>>* l_data{};
    t_std_collections_List_1Tt_mx2_VarDecl_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_data);
      bbGCMarkPtr(l_node);
    }
  }f0{};
  bbInt l_n=this->m_Count();
  f0.l_data=bbArray<bbGCVar<t_mx2_VarDecl>>::create(l_n);
  f0.l_node=this->m__0head->m__0succ;
  {
    bbInt l_i=bbInt(0);
    for(;(l_i<l_n);l_i+=1){
      f0.l_data->at(l_i)=f0.l_node->m__0value;
      f0.l_node=f0.l_node->m__0succ;
    }
  }
  return f0.l_data;
}

void t_std_collections_List_1Tt_mx2_VarDecl_2::m_Sort(bbFunction<bbInt(t_mx2_VarDecl*,t_mx2_VarDecl*)> l_compareFunc){
  bbInt l_insize=1;
  for(;;){
    struct f1_t : public bbGCFrame{
      t_std_collections_List_1Tt_mx2_VarDecl_2_Node* l_p{};
      t_std_collections_List_1Tt_mx2_VarDecl_2_Node* l_tail{};
      void gcMark(){
        bbGCMarkPtr(l_p);
        bbGCMarkPtr(l_tail);
      }
    }f1{};
    bbInt l_merges=bbInt(0);
    f1.l_tail=this->m__0head;
    f1.l_p=this->m__0head->m__0succ;
    while((f1.l_p!=this->m__0head)){
      struct f2_t : public bbGCFrame{
        t_std_collections_List_1Tt_mx2_VarDecl_2_Node* l_q{};
        void gcMark(){
          bbGCMarkPtr(l_q);
        }
      }f2{};
      l_merges+=1;
      f2.l_q=f1.l_p->m__0succ;
      bbInt l_qsize=l_insize;
      bbInt l_psize=1;
      while(((l_psize<l_insize)&&(f2.l_q!=this->m__0head))){
        l_psize+=1;
        f2.l_q=f2.l_q->m__0succ;
      }
      for(;;){
        struct f3_t : public bbGCFrame{
          t_std_collections_List_1Tt_mx2_VarDecl_2_Node* l_t{};
          void gcMark(){
            bbGCMarkPtr(l_t);
          }
        }f3{};
        if(((bbBool(l_psize)&&bbBool(l_qsize))&&(f2.l_q!=this->m__0head))){
          bbInt l_cc=l_compareFunc(f1.l_p->m__0value,f2.l_q->m__0value);
          if((l_cc<=bbInt(0))){
            f3.l_t=f1.l_p;
            f1.l_p=f1.l_p->m__0succ;
            l_psize-=1;
          }else{
            f3.l_t=f2.l_q;
            f2.l_q=f2.l_q->m__0succ;
            l_qsize-=1;
          }
        }else if(bbBool(l_psize)){
          f3.l_t=f1.l_p;
          f1.l_p=f1.l_p->m__0succ;
          l_psize-=1;
        }else if((bbBool(l_qsize)&&(f2.l_q!=this->m__0head))){
          f3.l_t=f2.l_q;
          f2.l_q=f2.l_q->m__0succ;
          l_qsize-=1;
        }else{
          break;
        }
        f3.l_t->m__0pred=f1.l_tail;
        f1.l_tail->m__0succ=f3.l_t;
        f1.l_tail=f3.l_t;
      }
      f1.l_p=f2.l_q;
    }
    f1.l_tail->m__0succ=this->m__0head;
    this->m__0head->m__0pred=f1.l_tail;
    if((l_merges<=1)){
      return;
    }
    l_insize*=2;
  }
}

void t_std_collections_List_1Tt_mx2_VarDecl_2::m_Sort(bbBool l_ascending){
  if(l_ascending){
    struct lambda48 : public bbFunction<bbInt(t_mx2_VarDecl*,t_mx2_VarDecl*)>::Rep{
      t_std_collections_List_1Tt_mx2_VarDecl_2* l_self;
      lambda48(t_std_collections_List_1Tt_mx2_VarDecl_2* l_self):l_self(l_self){
      }
      bbInt invoke(t_mx2_VarDecl* l_x,t_mx2_VarDecl* l_y){
        return bbCompare(l_x,l_y);
      }
      void gcMark(){
        bbGCMarkPtr(l_self);
      }
    };
    this->m_Sort(bbFunction<bbInt(t_mx2_VarDecl*,t_mx2_VarDecl*)>(new lambda48(this)));
  }else{
    struct lambda49 : public bbFunction<bbInt(t_mx2_VarDecl*,t_mx2_VarDecl*)>::Rep{
      t_std_collections_List_1Tt_mx2_VarDecl_2* l_self;
      lambda49(t_std_collections_List_1Tt_mx2_VarDecl_2* l_self):l_self(l_self){
      }
      bbInt invoke(t_mx2_VarDecl* l_x,t_mx2_VarDecl* l_y){
        return -bbCompare(l_x,l_y);
      }
      void gcMark(){
        bbGCMarkPtr(l_self);
      }
    };
    this->m_Sort(bbFunction<bbInt(t_mx2_VarDecl*,t_mx2_VarDecl*)>(new lambda49(this)));
  }
}

t_mx2_VarDecl* t_std_collections_List_1Tt_mx2_VarDecl_2::m_RemoveLast(){
  struct f0_t : public bbGCFrame{
    t_mx2_VarDecl* l_value{};
    void gcMark(){
      bbGCMarkPtr(l_value);
    }
  }f0{};
  bbDebugAssert(!this->m_Empty(),BB_T("Debug assert failed"));
  f0.l_value=this->m__0head->m__0pred->m__0value;
  this->m__0head->m__0pred->m_Remove();
  this->m__0seq+=1;
  return f0.l_value;
}

bbBool t_std_collections_List_1Tt_mx2_VarDecl_2::m_RemoveLast(t_mx2_VarDecl* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_mx2_VarDecl_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m_FindLastNode(l_value);
  if(!bbBool(f0.l_node)){
    return false;
  }
  f0.l_node->m_Remove();
  this->m__0seq+=1;
  return true;
}

t_mx2_VarDecl* t_std_collections_List_1Tt_mx2_VarDecl_2::m_RemoveFirst(){
  struct f0_t : public bbGCFrame{
    t_mx2_VarDecl* l_value{};
    void gcMark(){
      bbGCMarkPtr(l_value);
    }
  }f0{};
  bbDebugAssert(!this->m_Empty(),BB_T("Debug assert failed"));
  f0.l_value=this->m__0head->m__0succ->m__0value;
  this->m__0head->m__0succ->m_Remove();
  this->m__0seq+=1;
  return f0.l_value;
}

bbInt t_std_collections_List_1Tt_mx2_VarDecl_2::m_RemoveEach(t_mx2_VarDecl* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_mx2_VarDecl_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m__0head->m__0succ;
  bbInt l_n=bbInt(0);
  while((f0.l_node!=this->m__0head)){
    if((f0.l_node->m__0value==l_value)){
      f0.l_node=f0.l_node->m__0succ;
      f0.l_node->m__0pred->m_Remove();
      l_n+=1;
    }else{
      f0.l_node=f0.l_node->m__0succ;
    }
  }
  if(bbBool(l_n)){
    this->m__0seq+=1;
  }
  return l_n;
}

bbBool t_std_collections_List_1Tt_mx2_VarDecl_2::m_Remove(t_mx2_VarDecl* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_mx2_VarDecl_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m_FindNode(l_value);
  if(!bbBool(f0.l_node)){
    return false;
  }
  f0.l_node->m_Remove();
  this->m__0seq+=1;
  return true;
}

t_std_collections_List_1Tt_mx2_VarDecl_2_Node* t_std_collections_List_1Tt_mx2_VarDecl_2::m_LastNode(){
  if(!this->m_Empty()){
    return this->m__0head->m__0pred;
  }
  return ((t_std_collections_List_1Tt_mx2_VarDecl_2_Node*)0);
}

t_mx2_VarDecl* t_std_collections_List_1Tt_mx2_VarDecl_2::m_Last(){
  bbDebugAssert(!this->m_Empty(),BB_T("Debug assert failed"));
  return this->m__0head->m__0pred->m__0value;
}

t_std_collections_List_1Tt_mx2_VarDecl_2_Node* t_std_collections_List_1Tt_mx2_VarDecl_2::m_HeadNode(){
  return this->m__0head;
}

t_std_collections_List_1Tt_mx2_VarDecl_2_Node* t_std_collections_List_1Tt_mx2_VarDecl_2::m_FirstNode(){
  if(!this->m_Empty()){
    return this->m__0head->m__0succ;
  }
  return ((t_std_collections_List_1Tt_mx2_VarDecl_2_Node*)0);
}

t_mx2_VarDecl* t_std_collections_List_1Tt_mx2_VarDecl_2::m_First(){
  bbDebugAssert(!this->m_Empty(),BB_T("Debug assert failed"));
  return this->m__0head->m__0succ->m__0value;
}

t_std_collections_List_1Tt_mx2_VarDecl_2_Node* t_std_collections_List_1Tt_mx2_VarDecl_2::m_FindNode(t_mx2_VarDecl* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_mx2_VarDecl_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m__0head->m__0succ;
  while((f0.l_node!=this->m__0head)){
    if((f0.l_node->m__0value==l_value)){
      return f0.l_node;
    }
    f0.l_node=f0.l_node->m__0succ;
  }
  return ((t_std_collections_List_1Tt_mx2_VarDecl_2_Node*)0);
}

t_std_collections_List_1Tt_mx2_VarDecl_2_Node* t_std_collections_List_1Tt_mx2_VarDecl_2::m_FindLastNode(t_mx2_VarDecl* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_mx2_VarDecl_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m__0head->m__0pred;
  while((f0.l_node!=this->m__0head)){
    if((f0.l_node->m__0value==l_value)){
      return f0.l_node;
    }
    f0.l_node=f0.l_node->m__0pred;
  }
  return ((t_std_collections_List_1Tt_mx2_VarDecl_2_Node*)0);
}

bbBool t_std_collections_List_1Tt_mx2_VarDecl_2::m_Empty(){
  return (this->m__0head->m__0succ==this->m__0head);
}

bbInt t_std_collections_List_1Tt_mx2_VarDecl_2::m_Count(){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_mx2_VarDecl_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m__0head->m__0succ;
  bbInt l_n=bbInt(0);
  while((f0.l_node!=this->m__0head)){
    f0.l_node=f0.l_node->m__0succ;
    l_n+=1;
  }
  return l_n;
}

void t_std_collections_List_1Tt_mx2_VarDecl_2::m_Clear(){
  this->m__0head->m__0succ=this->m__0head;
  this->m__0head->m__0pred=this->m__0head;
  this->m__0seq+=1;
}

t_std_collections_List_1Tt_mx2_VarDecl_2_BackwardsIterator t_std_collections_List_1Tt_mx2_VarDecl_2::m_Backwards(){
  return t_std_collections_List_1Tt_mx2_VarDecl_2_BackwardsIterator(this,this->m__0head->m__0pred);
}

t_std_collections_List_1Tt_mx2_VarDecl_2_Iterator t_std_collections_List_1Tt_mx2_VarDecl_2::m_All(){
  return t_std_collections_List_1Tt_mx2_VarDecl_2_Iterator(this,this->m__0head->m__0succ);
}

t_std_collections_List_1Tt_mx2_VarDecl_2_Node* t_std_collections_List_1Tt_mx2_VarDecl_2::m_AddLast(t_mx2_VarDecl* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_mx2_VarDecl_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=bbGCNew<t_std_collections_List_1Tt_mx2_VarDecl_2_Node>(l_value,this->m__0head);
  this->m__0seq+=1;
  return f0.l_node;
}

t_std_collections_List_1Tt_mx2_VarDecl_2_Node* t_std_collections_List_1Tt_mx2_VarDecl_2::m_AddFirst(t_mx2_VarDecl* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_mx2_VarDecl_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=bbGCNew<t_std_collections_List_1Tt_mx2_VarDecl_2_Node>(l_value,this->m__0head->m__0succ);
  this->m__0seq+=1;
  return f0.l_node;
}

void t_std_collections_List_1Tt_mx2_VarDecl_2::m_AddAll(bbArray<bbGCVar<t_mx2_VarDecl>>* l_values){
  {
    bbInt l_0=bbInt(0);
    bbInt l_1=l_values->length();
    for(;(l_0<l_1);l_0+=1){
      struct f2_t : public bbGCFrame{
        t_mx2_VarDecl* l_value{};
        void gcMark(){
          bbGCMarkPtr(l_value);
        }
      }f2{};
      f2.l_value=l_values->at(l_0);
      this->m_AddLast(f2.l_value);
    }
  }
}

void t_std_collections_List_1Tt_mx2_VarDecl_2::m_Add(t_mx2_VarDecl* l_value){
  this->m_AddLast(l_value);
}

void t_std_collections_List_1Tt_mx2_CatchStmt_2_Node::gcMark(){
  bbGCMark(m__0succ);
  bbGCMark(m__0pred);
  bbGCMark(m__0value);
}

t_std_collections_List_1Tt_mx2_CatchStmt_2_Node::t_std_collections_List_1Tt_mx2_CatchStmt_2_Node(t_mx2_CatchStmt* l_value,t_std_collections_List_1Tt_mx2_CatchStmt_2_Node* l_succ){
  this->m__0value=l_value;
  this->m__0succ=l_succ;
  this->m__0pred=l_succ->m__0pred;
  this->m__0pred->m__0succ=this;
  l_succ->m__0pred=this;
}

t_std_collections_List_1Tt_mx2_CatchStmt_2_Node::t_std_collections_List_1Tt_mx2_CatchStmt_2_Node(t_mx2_CatchStmt* l_value){
  this->m__0value=l_value;
  this->m__0succ=this;
  this->m__0pred=this;
}

void t_std_collections_List_1Tt_mx2_CatchStmt_2_Node::m_Value(t_mx2_CatchStmt* l_value){
  this->m__0value=l_value;
}

t_mx2_CatchStmt* t_std_collections_List_1Tt_mx2_CatchStmt_2_Node::m_Value(){
  return this->m__0value;
}

t_std_collections_List_1Tt_mx2_CatchStmt_2_Node* t_std_collections_List_1Tt_mx2_CatchStmt_2_Node::m_Succ(){
  return this->m__0succ;
}

void t_std_collections_List_1Tt_mx2_CatchStmt_2_Node::m_Remove(){
  this->m__0succ->m__0pred=this->m__0pred;
  this->m__0pred->m__0succ=this->m__0succ;
}

t_std_collections_List_1Tt_mx2_CatchStmt_2_Node* t_std_collections_List_1Tt_mx2_CatchStmt_2_Node::m_Pred(){
  return this->m__0pred;
}

void t_std_collections_List_1Tt_mx2_CatchStmt_2_Node::m_InsertBefore(t_std_collections_List_1Tt_mx2_CatchStmt_2_Node* l_node){
  this->m__0succ=l_node;
  this->m__0pred=l_node->m__0pred;
  this->m__0pred->m__0succ=this;
  l_node->m__0pred=this;
}

void t_std_collections_List_1Tt_mx2_CatchStmt_2_Node::m_InsertAfter(t_std_collections_List_1Tt_mx2_CatchStmt_2_Node* l_node){
  this->m__0pred=l_node;
  this->m__0succ=l_node->m__0succ;
  this->m__0succ->m__0pred=this;
  l_node->m__0succ=this;
}

t_std_collections_List_1Tt_mx2_CatchStmt_2_Iterator::t_std_collections_List_1Tt_mx2_CatchStmt_2_Iterator(t_std_collections_List_1Tt_mx2_CatchStmt_2* l_list,t_std_collections_List_1Tt_mx2_CatchStmt_2_Node* l_node){
  (*this).m__0list=l_list;
  (*this).m__0node=l_node;
  (*this).m__0seq=l_list->m__0seq;
}

void t_std_collections_List_1Tt_mx2_CatchStmt_2_Iterator::m_Insert(t_mx2_CatchStmt* l_value){
  (*this).m_AssertSeq();
  (*this).m__0node=bbGCNew<t_std_collections_List_1Tt_mx2_CatchStmt_2_Node>(l_value,(*this).m__0node);
  (*this).m__0list->m__0seq+=1;
  (*this).m__0seq=(*this).m__0list->m__0seq;
}

void t_std_collections_List_1Tt_mx2_CatchStmt_2_Iterator::m_Erase(){
  (*this).m_AssertCurrent();
  (*this).m__0node=(*this).m__0node->m__0succ;
  (*this).m__0node->m__0pred->m_Remove();
  (*this).m__0list->m__0seq+=1;
  (*this).m__0seq=(*this).m__0list->m__0seq;
}

void t_std_collections_List_1Tt_mx2_CatchStmt_2_Iterator::m_Current(t_mx2_CatchStmt* l_current){
  (*this).m_AssertCurrent();
  (*this).m__0node->m__0value=l_current;
}

t_mx2_CatchStmt* t_std_collections_List_1Tt_mx2_CatchStmt_2_Iterator::m_Current(){
  (*this).m_AssertCurrent();
  return (*this).m__0node->m__0value;
}

void t_std_collections_List_1Tt_mx2_CatchStmt_2_Iterator::m_Bump(){
  (*this).m_AssertCurrent();
  (*this).m__0node=(*this).m__0node->m__0succ;
}

bbBool t_std_collections_List_1Tt_mx2_CatchStmt_2_Iterator::m_AtEnd(){
  (*this).m_AssertSeq();
  return ((*this).m__0node==(*this).m__0list->m__0head);
}

void t_std_collections_List_1Tt_mx2_CatchStmt_2_Iterator::m_AssertSeq(){
  bbDebugAssert(((*this).m__0seq==(*this).m__0list->m__0seq),BB_T("Concurrent list modification"));
}

void t_std_collections_List_1Tt_mx2_CatchStmt_2_Iterator::m_AssertCurrent(){
  bbDebugAssert(!(*this).m_AtEnd(),BB_T("Invalid list iterator"));
}

int bbCompare(const t_std_collections_List_1Tt_mx2_CatchStmt_2_Iterator&x,const t_std_collections_List_1Tt_mx2_CatchStmt_2_Iterator&y){
  if(int t=bbCompare(x.m__0list,y.m__0list)) return t;
  if(int t=bbCompare(x.m__0node,y.m__0node)) return t;
  if(int t=bbCompare(x.m__0seq,y.m__0seq)) return t;
  return 0;
}

void bbGCMark(const t_std_collections_List_1Tt_mx2_CatchStmt_2_Iterator&t){
  bbGCMark(t.m__0list);
  bbGCMark(t.m__0node);
}

t_std_collections_List_1Tt_mx2_CatchStmt_2_BackwardsIterator::t_std_collections_List_1Tt_mx2_CatchStmt_2_BackwardsIterator(t_std_collections_List_1Tt_mx2_CatchStmt_2* l_list,t_std_collections_List_1Tt_mx2_CatchStmt_2_Node* l_node){
  (*this).m__0list=l_list;
  (*this).m__0node=l_node;
  (*this).m__0seq=l_list->m__0seq;
}

void t_std_collections_List_1Tt_mx2_CatchStmt_2_BackwardsIterator::m_Insert(t_mx2_CatchStmt* l_value){
  (*this).m_AssertSeq();
  (*this).m__0node=bbGCNew<t_std_collections_List_1Tt_mx2_CatchStmt_2_Node>(l_value,(*this).m__0node->m__0succ);
  (*this).m__0list->m__0seq+=1;
  (*this).m__0seq=(*this).m__0list->m__0seq;
}

void t_std_collections_List_1Tt_mx2_CatchStmt_2_BackwardsIterator::m_Erase(){
  (*this).m_AssertCurrent();
  (*this).m__0node=(*this).m__0node->m__0pred;
  (*this).m__0node->m__0succ->m_Remove();
  (*this).m__0list->m__0seq+=1;
  (*this).m__0seq=(*this).m__0list->m__0seq;
}

void t_std_collections_List_1Tt_mx2_CatchStmt_2_BackwardsIterator::m_Current(t_mx2_CatchStmt* l_current){
  (*this).m_AssertCurrent();
  (*this).m__0node->m__0value=l_current;
}

t_mx2_CatchStmt* t_std_collections_List_1Tt_mx2_CatchStmt_2_BackwardsIterator::m_Current(){
  (*this).m_AssertCurrent();
  return (*this).m__0node->m__0value;
}

void t_std_collections_List_1Tt_mx2_CatchStmt_2_BackwardsIterator::m_Bump(){
  (*this).m_AssertCurrent();
  (*this).m__0node=(*this).m__0node->m__0pred;
}

bbBool t_std_collections_List_1Tt_mx2_CatchStmt_2_BackwardsIterator::m_AtEnd(){
  (*this).m_AssertSeq();
  return ((*this).m__0node==(*this).m__0list->m__0head);
}

void t_std_collections_List_1Tt_mx2_CatchStmt_2_BackwardsIterator::m_AssertSeq(){
  bbDebugAssert(((*this).m__0seq==(*this).m__0list->m__0seq),BB_T("Concurrent list modification"));
}

void t_std_collections_List_1Tt_mx2_CatchStmt_2_BackwardsIterator::m_AssertCurrent(){
  bbDebugAssert(!(*this).m_AtEnd(),BB_T("Invalid list iterator"));
}

int bbCompare(const t_std_collections_List_1Tt_mx2_CatchStmt_2_BackwardsIterator&x,const t_std_collections_List_1Tt_mx2_CatchStmt_2_BackwardsIterator&y){
  if(int t=bbCompare(x.m__0list,y.m__0list)) return t;
  if(int t=bbCompare(x.m__0node,y.m__0node)) return t;
  if(int t=bbCompare(x.m__0seq,y.m__0seq)) return t;
  return 0;
}

void bbGCMark(const t_std_collections_List_1Tt_mx2_CatchStmt_2_BackwardsIterator&t){
  bbGCMark(t.m__0list);
  bbGCMark(t.m__0node);
}

void t_std_collections_List_1Tt_mx2_CatchStmt_2::gcMark(){
  bbGCMark(m__0head);
}

t_std_collections_List_1Tt_mx2_CatchStmt_2::t_std_collections_List_1Tt_mx2_CatchStmt_2(t_std_collections_List_1Tt_mx2_CatchStmt_2* l_values):t_std_collections_List_1Tt_mx2_CatchStmt_2(){
  g_std_collections_List_1Tt_mx2_CatchStmt_2_AddAll_1Tt_std_collections_List_1Tt_mx2_CatchStmt_2_2(this,l_values);
}

t_std_collections_List_1Tt_mx2_CatchStmt_2::t_std_collections_List_1Tt_mx2_CatchStmt_2(t_std_collections_Stack_1Tt_mx2_CatchStmt_2* l_values):t_std_collections_List_1Tt_mx2_CatchStmt_2(){
  g_std_collections_List_1Tt_mx2_CatchStmt_2_AddAll_1Tt_std_collections_Stack_1Tt_mx2_CatchStmt_2_2(this,l_values);
}

t_std_collections_List_1Tt_mx2_CatchStmt_2::t_std_collections_List_1Tt_mx2_CatchStmt_2(bbArray<bbGCVar<t_mx2_CatchStmt>>* l_values):t_std_collections_List_1Tt_mx2_CatchStmt_2(){
  this->m_AddAll(l_values);
}

t_std_collections_List_1Tt_mx2_CatchStmt_2::t_std_collections_List_1Tt_mx2_CatchStmt_2(){
  this->m__0head=bbGCNew<t_std_collections_List_1Tt_mx2_CatchStmt_2_Node>(((t_mx2_CatchStmt*)0));
}

bbArray<bbGCVar<t_mx2_CatchStmt>>* t_std_collections_List_1Tt_mx2_CatchStmt_2::m_ToArray(){
  struct f0_t : public bbGCFrame{
    bbArray<bbGCVar<t_mx2_CatchStmt>>* l_data{};
    t_std_collections_List_1Tt_mx2_CatchStmt_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_data);
      bbGCMarkPtr(l_node);
    }
  }f0{};
  bbInt l_n=this->m_Count();
  f0.l_data=bbArray<bbGCVar<t_mx2_CatchStmt>>::create(l_n);
  f0.l_node=this->m__0head->m__0succ;
  {
    bbInt l_i=bbInt(0);
    for(;(l_i<l_n);l_i+=1){
      f0.l_data->at(l_i)=f0.l_node->m__0value;
      f0.l_node=f0.l_node->m__0succ;
    }
  }
  return f0.l_data;
}

void t_std_collections_List_1Tt_mx2_CatchStmt_2::m_Sort(bbFunction<bbInt(t_mx2_CatchStmt*,t_mx2_CatchStmt*)> l_compareFunc){
  bbInt l_insize=1;
  for(;;){
    struct f1_t : public bbGCFrame{
      t_std_collections_List_1Tt_mx2_CatchStmt_2_Node* l_p{};
      t_std_collections_List_1Tt_mx2_CatchStmt_2_Node* l_tail{};
      void gcMark(){
        bbGCMarkPtr(l_p);
        bbGCMarkPtr(l_tail);
      }
    }f1{};
    bbInt l_merges=bbInt(0);
    f1.l_tail=this->m__0head;
    f1.l_p=this->m__0head->m__0succ;
    while((f1.l_p!=this->m__0head)){
      struct f2_t : public bbGCFrame{
        t_std_collections_List_1Tt_mx2_CatchStmt_2_Node* l_q{};
        void gcMark(){
          bbGCMarkPtr(l_q);
        }
      }f2{};
      l_merges+=1;
      f2.l_q=f1.l_p->m__0succ;
      bbInt l_qsize=l_insize;
      bbInt l_psize=1;
      while(((l_psize<l_insize)&&(f2.l_q!=this->m__0head))){
        l_psize+=1;
        f2.l_q=f2.l_q->m__0succ;
      }
      for(;;){
        struct f3_t : public bbGCFrame{
          t_std_collections_List_1Tt_mx2_CatchStmt_2_Node* l_t{};
          void gcMark(){
            bbGCMarkPtr(l_t);
          }
        }f3{};
        if(((bbBool(l_psize)&&bbBool(l_qsize))&&(f2.l_q!=this->m__0head))){
          bbInt l_cc=l_compareFunc(f1.l_p->m__0value,f2.l_q->m__0value);
          if((l_cc<=bbInt(0))){
            f3.l_t=f1.l_p;
            f1.l_p=f1.l_p->m__0succ;
            l_psize-=1;
          }else{
            f3.l_t=f2.l_q;
            f2.l_q=f2.l_q->m__0succ;
            l_qsize-=1;
          }
        }else if(bbBool(l_psize)){
          f3.l_t=f1.l_p;
          f1.l_p=f1.l_p->m__0succ;
          l_psize-=1;
        }else if((bbBool(l_qsize)&&(f2.l_q!=this->m__0head))){
          f3.l_t=f2.l_q;
          f2.l_q=f2.l_q->m__0succ;
          l_qsize-=1;
        }else{
          break;
        }
        f3.l_t->m__0pred=f1.l_tail;
        f1.l_tail->m__0succ=f3.l_t;
        f1.l_tail=f3.l_t;
      }
      f1.l_p=f2.l_q;
    }
    f1.l_tail->m__0succ=this->m__0head;
    this->m__0head->m__0pred=f1.l_tail;
    if((l_merges<=1)){
      return;
    }
    l_insize*=2;
  }
}

void t_std_collections_List_1Tt_mx2_CatchStmt_2::m_Sort(bbBool l_ascending){
  if(l_ascending){
    struct lambda50 : public bbFunction<bbInt(t_mx2_CatchStmt*,t_mx2_CatchStmt*)>::Rep{
      t_std_collections_List_1Tt_mx2_CatchStmt_2* l_self;
      lambda50(t_std_collections_List_1Tt_mx2_CatchStmt_2* l_self):l_self(l_self){
      }
      bbInt invoke(t_mx2_CatchStmt* l_x,t_mx2_CatchStmt* l_y){
        return bbCompare(l_x,l_y);
      }
      void gcMark(){
        bbGCMarkPtr(l_self);
      }
    };
    this->m_Sort(bbFunction<bbInt(t_mx2_CatchStmt*,t_mx2_CatchStmt*)>(new lambda50(this)));
  }else{
    struct lambda51 : public bbFunction<bbInt(t_mx2_CatchStmt*,t_mx2_CatchStmt*)>::Rep{
      t_std_collections_List_1Tt_mx2_CatchStmt_2* l_self;
      lambda51(t_std_collections_List_1Tt_mx2_CatchStmt_2* l_self):l_self(l_self){
      }
      bbInt invoke(t_mx2_CatchStmt* l_x,t_mx2_CatchStmt* l_y){
        return -bbCompare(l_x,l_y);
      }
      void gcMark(){
        bbGCMarkPtr(l_self);
      }
    };
    this->m_Sort(bbFunction<bbInt(t_mx2_CatchStmt*,t_mx2_CatchStmt*)>(new lambda51(this)));
  }
}

t_mx2_CatchStmt* t_std_collections_List_1Tt_mx2_CatchStmt_2::m_RemoveLast(){
  struct f0_t : public bbGCFrame{
    t_mx2_CatchStmt* l_value{};
    void gcMark(){
      bbGCMarkPtr(l_value);
    }
  }f0{};
  bbDebugAssert(!this->m_Empty(),BB_T("Debug assert failed"));
  f0.l_value=this->m__0head->m__0pred->m__0value;
  this->m__0head->m__0pred->m_Remove();
  this->m__0seq+=1;
  return f0.l_value;
}

bbBool t_std_collections_List_1Tt_mx2_CatchStmt_2::m_RemoveLast(t_mx2_CatchStmt* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_mx2_CatchStmt_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m_FindLastNode(l_value);
  if(!bbBool(f0.l_node)){
    return false;
  }
  f0.l_node->m_Remove();
  this->m__0seq+=1;
  return true;
}

t_mx2_CatchStmt* t_std_collections_List_1Tt_mx2_CatchStmt_2::m_RemoveFirst(){
  struct f0_t : public bbGCFrame{
    t_mx2_CatchStmt* l_value{};
    void gcMark(){
      bbGCMarkPtr(l_value);
    }
  }f0{};
  bbDebugAssert(!this->m_Empty(),BB_T("Debug assert failed"));
  f0.l_value=this->m__0head->m__0succ->m__0value;
  this->m__0head->m__0succ->m_Remove();
  this->m__0seq+=1;
  return f0.l_value;
}

bbInt t_std_collections_List_1Tt_mx2_CatchStmt_2::m_RemoveEach(t_mx2_CatchStmt* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_mx2_CatchStmt_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m__0head->m__0succ;
  bbInt l_n=bbInt(0);
  while((f0.l_node!=this->m__0head)){
    if((f0.l_node->m__0value==l_value)){
      f0.l_node=f0.l_node->m__0succ;
      f0.l_node->m__0pred->m_Remove();
      l_n+=1;
    }else{
      f0.l_node=f0.l_node->m__0succ;
    }
  }
  if(bbBool(l_n)){
    this->m__0seq+=1;
  }
  return l_n;
}

bbBool t_std_collections_List_1Tt_mx2_CatchStmt_2::m_Remove(t_mx2_CatchStmt* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_mx2_CatchStmt_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m_FindNode(l_value);
  if(!bbBool(f0.l_node)){
    return false;
  }
  f0.l_node->m_Remove();
  this->m__0seq+=1;
  return true;
}

t_std_collections_List_1Tt_mx2_CatchStmt_2_Node* t_std_collections_List_1Tt_mx2_CatchStmt_2::m_LastNode(){
  if(!this->m_Empty()){
    return this->m__0head->m__0pred;
  }
  return ((t_std_collections_List_1Tt_mx2_CatchStmt_2_Node*)0);
}

t_mx2_CatchStmt* t_std_collections_List_1Tt_mx2_CatchStmt_2::m_Last(){
  bbDebugAssert(!this->m_Empty(),BB_T("Debug assert failed"));
  return this->m__0head->m__0pred->m__0value;
}

t_std_collections_List_1Tt_mx2_CatchStmt_2_Node* t_std_collections_List_1Tt_mx2_CatchStmt_2::m_HeadNode(){
  return this->m__0head;
}

t_std_collections_List_1Tt_mx2_CatchStmt_2_Node* t_std_collections_List_1Tt_mx2_CatchStmt_2::m_FirstNode(){
  if(!this->m_Empty()){
    return this->m__0head->m__0succ;
  }
  return ((t_std_collections_List_1Tt_mx2_CatchStmt_2_Node*)0);
}

t_mx2_CatchStmt* t_std_collections_List_1Tt_mx2_CatchStmt_2::m_First(){
  bbDebugAssert(!this->m_Empty(),BB_T("Debug assert failed"));
  return this->m__0head->m__0succ->m__0value;
}

t_std_collections_List_1Tt_mx2_CatchStmt_2_Node* t_std_collections_List_1Tt_mx2_CatchStmt_2::m_FindNode(t_mx2_CatchStmt* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_mx2_CatchStmt_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m__0head->m__0succ;
  while((f0.l_node!=this->m__0head)){
    if((f0.l_node->m__0value==l_value)){
      return f0.l_node;
    }
    f0.l_node=f0.l_node->m__0succ;
  }
  return ((t_std_collections_List_1Tt_mx2_CatchStmt_2_Node*)0);
}

t_std_collections_List_1Tt_mx2_CatchStmt_2_Node* t_std_collections_List_1Tt_mx2_CatchStmt_2::m_FindLastNode(t_mx2_CatchStmt* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_mx2_CatchStmt_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m__0head->m__0pred;
  while((f0.l_node!=this->m__0head)){
    if((f0.l_node->m__0value==l_value)){
      return f0.l_node;
    }
    f0.l_node=f0.l_node->m__0pred;
  }
  return ((t_std_collections_List_1Tt_mx2_CatchStmt_2_Node*)0);
}

bbBool t_std_collections_List_1Tt_mx2_CatchStmt_2::m_Empty(){
  return (this->m__0head->m__0succ==this->m__0head);
}

bbInt t_std_collections_List_1Tt_mx2_CatchStmt_2::m_Count(){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_mx2_CatchStmt_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m__0head->m__0succ;
  bbInt l_n=bbInt(0);
  while((f0.l_node!=this->m__0head)){
    f0.l_node=f0.l_node->m__0succ;
    l_n+=1;
  }
  return l_n;
}

void t_std_collections_List_1Tt_mx2_CatchStmt_2::m_Clear(){
  this->m__0head->m__0succ=this->m__0head;
  this->m__0head->m__0pred=this->m__0head;
  this->m__0seq+=1;
}

t_std_collections_List_1Tt_mx2_CatchStmt_2_BackwardsIterator t_std_collections_List_1Tt_mx2_CatchStmt_2::m_Backwards(){
  return t_std_collections_List_1Tt_mx2_CatchStmt_2_BackwardsIterator(this,this->m__0head->m__0pred);
}

t_std_collections_List_1Tt_mx2_CatchStmt_2_Iterator t_std_collections_List_1Tt_mx2_CatchStmt_2::m_All(){
  return t_std_collections_List_1Tt_mx2_CatchStmt_2_Iterator(this,this->m__0head->m__0succ);
}

t_std_collections_List_1Tt_mx2_CatchStmt_2_Node* t_std_collections_List_1Tt_mx2_CatchStmt_2::m_AddLast(t_mx2_CatchStmt* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_mx2_CatchStmt_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=bbGCNew<t_std_collections_List_1Tt_mx2_CatchStmt_2_Node>(l_value,this->m__0head);
  this->m__0seq+=1;
  return f0.l_node;
}

t_std_collections_List_1Tt_mx2_CatchStmt_2_Node* t_std_collections_List_1Tt_mx2_CatchStmt_2::m_AddFirst(t_mx2_CatchStmt* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_mx2_CatchStmt_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=bbGCNew<t_std_collections_List_1Tt_mx2_CatchStmt_2_Node>(l_value,this->m__0head->m__0succ);
  this->m__0seq+=1;
  return f0.l_node;
}

void t_std_collections_List_1Tt_mx2_CatchStmt_2::m_AddAll(bbArray<bbGCVar<t_mx2_CatchStmt>>* l_values){
  {
    bbInt l_0=bbInt(0);
    bbInt l_1=l_values->length();
    for(;(l_0<l_1);l_0+=1){
      struct f2_t : public bbGCFrame{
        t_mx2_CatchStmt* l_value{};
        void gcMark(){
          bbGCMarkPtr(l_value);
        }
      }f2{};
      f2.l_value=l_values->at(l_0);
      this->m_AddLast(f2.l_value);
    }
  }
}

void t_std_collections_List_1Tt_mx2_CatchStmt_2::m_Add(t_mx2_CatchStmt* l_value){
  this->m_AddLast(l_value);
}

void t_std_collections_List_1Tt_mx2_CaseStmt_2_Node::gcMark(){
  bbGCMark(m__0succ);
  bbGCMark(m__0pred);
  bbGCMark(m__0value);
}

t_std_collections_List_1Tt_mx2_CaseStmt_2_Node::t_std_collections_List_1Tt_mx2_CaseStmt_2_Node(t_mx2_CaseStmt* l_value,t_std_collections_List_1Tt_mx2_CaseStmt_2_Node* l_succ){
  this->m__0value=l_value;
  this->m__0succ=l_succ;
  this->m__0pred=l_succ->m__0pred;
  this->m__0pred->m__0succ=this;
  l_succ->m__0pred=this;
}

t_std_collections_List_1Tt_mx2_CaseStmt_2_Node::t_std_collections_List_1Tt_mx2_CaseStmt_2_Node(t_mx2_CaseStmt* l_value){
  this->m__0value=l_value;
  this->m__0succ=this;
  this->m__0pred=this;
}

void t_std_collections_List_1Tt_mx2_CaseStmt_2_Node::m_Value(t_mx2_CaseStmt* l_value){
  this->m__0value=l_value;
}

t_mx2_CaseStmt* t_std_collections_List_1Tt_mx2_CaseStmt_2_Node::m_Value(){
  return this->m__0value;
}

t_std_collections_List_1Tt_mx2_CaseStmt_2_Node* t_std_collections_List_1Tt_mx2_CaseStmt_2_Node::m_Succ(){
  return this->m__0succ;
}

void t_std_collections_List_1Tt_mx2_CaseStmt_2_Node::m_Remove(){
  this->m__0succ->m__0pred=this->m__0pred;
  this->m__0pred->m__0succ=this->m__0succ;
}

t_std_collections_List_1Tt_mx2_CaseStmt_2_Node* t_std_collections_List_1Tt_mx2_CaseStmt_2_Node::m_Pred(){
  return this->m__0pred;
}

void t_std_collections_List_1Tt_mx2_CaseStmt_2_Node::m_InsertBefore(t_std_collections_List_1Tt_mx2_CaseStmt_2_Node* l_node){
  this->m__0succ=l_node;
  this->m__0pred=l_node->m__0pred;
  this->m__0pred->m__0succ=this;
  l_node->m__0pred=this;
}

void t_std_collections_List_1Tt_mx2_CaseStmt_2_Node::m_InsertAfter(t_std_collections_List_1Tt_mx2_CaseStmt_2_Node* l_node){
  this->m__0pred=l_node;
  this->m__0succ=l_node->m__0succ;
  this->m__0succ->m__0pred=this;
  l_node->m__0succ=this;
}

t_std_collections_List_1Tt_mx2_CaseStmt_2_Iterator::t_std_collections_List_1Tt_mx2_CaseStmt_2_Iterator(t_std_collections_List_1Tt_mx2_CaseStmt_2* l_list,t_std_collections_List_1Tt_mx2_CaseStmt_2_Node* l_node){
  (*this).m__0list=l_list;
  (*this).m__0node=l_node;
  (*this).m__0seq=l_list->m__0seq;
}

void t_std_collections_List_1Tt_mx2_CaseStmt_2_Iterator::m_Insert(t_mx2_CaseStmt* l_value){
  (*this).m_AssertSeq();
  (*this).m__0node=bbGCNew<t_std_collections_List_1Tt_mx2_CaseStmt_2_Node>(l_value,(*this).m__0node);
  (*this).m__0list->m__0seq+=1;
  (*this).m__0seq=(*this).m__0list->m__0seq;
}

void t_std_collections_List_1Tt_mx2_CaseStmt_2_Iterator::m_Erase(){
  (*this).m_AssertCurrent();
  (*this).m__0node=(*this).m__0node->m__0succ;
  (*this).m__0node->m__0pred->m_Remove();
  (*this).m__0list->m__0seq+=1;
  (*this).m__0seq=(*this).m__0list->m__0seq;
}

void t_std_collections_List_1Tt_mx2_CaseStmt_2_Iterator::m_Current(t_mx2_CaseStmt* l_current){
  (*this).m_AssertCurrent();
  (*this).m__0node->m__0value=l_current;
}

t_mx2_CaseStmt* t_std_collections_List_1Tt_mx2_CaseStmt_2_Iterator::m_Current(){
  (*this).m_AssertCurrent();
  return (*this).m__0node->m__0value;
}

void t_std_collections_List_1Tt_mx2_CaseStmt_2_Iterator::m_Bump(){
  (*this).m_AssertCurrent();
  (*this).m__0node=(*this).m__0node->m__0succ;
}

bbBool t_std_collections_List_1Tt_mx2_CaseStmt_2_Iterator::m_AtEnd(){
  (*this).m_AssertSeq();
  return ((*this).m__0node==(*this).m__0list->m__0head);
}

void t_std_collections_List_1Tt_mx2_CaseStmt_2_Iterator::m_AssertSeq(){
  bbDebugAssert(((*this).m__0seq==(*this).m__0list->m__0seq),BB_T("Concurrent list modification"));
}

void t_std_collections_List_1Tt_mx2_CaseStmt_2_Iterator::m_AssertCurrent(){
  bbDebugAssert(!(*this).m_AtEnd(),BB_T("Invalid list iterator"));
}

int bbCompare(const t_std_collections_List_1Tt_mx2_CaseStmt_2_Iterator&x,const t_std_collections_List_1Tt_mx2_CaseStmt_2_Iterator&y){
  if(int t=bbCompare(x.m__0list,y.m__0list)) return t;
  if(int t=bbCompare(x.m__0node,y.m__0node)) return t;
  if(int t=bbCompare(x.m__0seq,y.m__0seq)) return t;
  return 0;
}

void bbGCMark(const t_std_collections_List_1Tt_mx2_CaseStmt_2_Iterator&t){
  bbGCMark(t.m__0list);
  bbGCMark(t.m__0node);
}

t_std_collections_List_1Tt_mx2_CaseStmt_2_BackwardsIterator::t_std_collections_List_1Tt_mx2_CaseStmt_2_BackwardsIterator(t_std_collections_List_1Tt_mx2_CaseStmt_2* l_list,t_std_collections_List_1Tt_mx2_CaseStmt_2_Node* l_node){
  (*this).m__0list=l_list;
  (*this).m__0node=l_node;
  (*this).m__0seq=l_list->m__0seq;
}

void t_std_collections_List_1Tt_mx2_CaseStmt_2_BackwardsIterator::m_Insert(t_mx2_CaseStmt* l_value){
  (*this).m_AssertSeq();
  (*this).m__0node=bbGCNew<t_std_collections_List_1Tt_mx2_CaseStmt_2_Node>(l_value,(*this).m__0node->m__0succ);
  (*this).m__0list->m__0seq+=1;
  (*this).m__0seq=(*this).m__0list->m__0seq;
}

void t_std_collections_List_1Tt_mx2_CaseStmt_2_BackwardsIterator::m_Erase(){
  (*this).m_AssertCurrent();
  (*this).m__0node=(*this).m__0node->m__0pred;
  (*this).m__0node->m__0succ->m_Remove();
  (*this).m__0list->m__0seq+=1;
  (*this).m__0seq=(*this).m__0list->m__0seq;
}

void t_std_collections_List_1Tt_mx2_CaseStmt_2_BackwardsIterator::m_Current(t_mx2_CaseStmt* l_current){
  (*this).m_AssertCurrent();
  (*this).m__0node->m__0value=l_current;
}

t_mx2_CaseStmt* t_std_collections_List_1Tt_mx2_CaseStmt_2_BackwardsIterator::m_Current(){
  (*this).m_AssertCurrent();
  return (*this).m__0node->m__0value;
}

void t_std_collections_List_1Tt_mx2_CaseStmt_2_BackwardsIterator::m_Bump(){
  (*this).m_AssertCurrent();
  (*this).m__0node=(*this).m__0node->m__0pred;
}

bbBool t_std_collections_List_1Tt_mx2_CaseStmt_2_BackwardsIterator::m_AtEnd(){
  (*this).m_AssertSeq();
  return ((*this).m__0node==(*this).m__0list->m__0head);
}

void t_std_collections_List_1Tt_mx2_CaseStmt_2_BackwardsIterator::m_AssertSeq(){
  bbDebugAssert(((*this).m__0seq==(*this).m__0list->m__0seq),BB_T("Concurrent list modification"));
}

void t_std_collections_List_1Tt_mx2_CaseStmt_2_BackwardsIterator::m_AssertCurrent(){
  bbDebugAssert(!(*this).m_AtEnd(),BB_T("Invalid list iterator"));
}

int bbCompare(const t_std_collections_List_1Tt_mx2_CaseStmt_2_BackwardsIterator&x,const t_std_collections_List_1Tt_mx2_CaseStmt_2_BackwardsIterator&y){
  if(int t=bbCompare(x.m__0list,y.m__0list)) return t;
  if(int t=bbCompare(x.m__0node,y.m__0node)) return t;
  if(int t=bbCompare(x.m__0seq,y.m__0seq)) return t;
  return 0;
}

void bbGCMark(const t_std_collections_List_1Tt_mx2_CaseStmt_2_BackwardsIterator&t){
  bbGCMark(t.m__0list);
  bbGCMark(t.m__0node);
}

void t_std_collections_List_1Tt_mx2_CaseStmt_2::gcMark(){
  bbGCMark(m__0head);
}

t_std_collections_List_1Tt_mx2_CaseStmt_2::t_std_collections_List_1Tt_mx2_CaseStmt_2(t_std_collections_List_1Tt_mx2_CaseStmt_2* l_values):t_std_collections_List_1Tt_mx2_CaseStmt_2(){
  g_std_collections_List_1Tt_mx2_CaseStmt_2_AddAll_1Tt_std_collections_List_1Tt_mx2_CaseStmt_2_2(this,l_values);
}

t_std_collections_List_1Tt_mx2_CaseStmt_2::t_std_collections_List_1Tt_mx2_CaseStmt_2(t_std_collections_Stack_1Tt_mx2_CaseStmt_2* l_values):t_std_collections_List_1Tt_mx2_CaseStmt_2(){
  g_std_collections_List_1Tt_mx2_CaseStmt_2_AddAll_1Tt_std_collections_Stack_1Tt_mx2_CaseStmt_2_2(this,l_values);
}

t_std_collections_List_1Tt_mx2_CaseStmt_2::t_std_collections_List_1Tt_mx2_CaseStmt_2(bbArray<bbGCVar<t_mx2_CaseStmt>>* l_values):t_std_collections_List_1Tt_mx2_CaseStmt_2(){
  this->m_AddAll(l_values);
}

t_std_collections_List_1Tt_mx2_CaseStmt_2::t_std_collections_List_1Tt_mx2_CaseStmt_2(){
  this->m__0head=bbGCNew<t_std_collections_List_1Tt_mx2_CaseStmt_2_Node>(((t_mx2_CaseStmt*)0));
}

bbArray<bbGCVar<t_mx2_CaseStmt>>* t_std_collections_List_1Tt_mx2_CaseStmt_2::m_ToArray(){
  struct f0_t : public bbGCFrame{
    bbArray<bbGCVar<t_mx2_CaseStmt>>* l_data{};
    t_std_collections_List_1Tt_mx2_CaseStmt_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_data);
      bbGCMarkPtr(l_node);
    }
  }f0{};
  bbInt l_n=this->m_Count();
  f0.l_data=bbArray<bbGCVar<t_mx2_CaseStmt>>::create(l_n);
  f0.l_node=this->m__0head->m__0succ;
  {
    bbInt l_i=bbInt(0);
    for(;(l_i<l_n);l_i+=1){
      f0.l_data->at(l_i)=f0.l_node->m__0value;
      f0.l_node=f0.l_node->m__0succ;
    }
  }
  return f0.l_data;
}

void t_std_collections_List_1Tt_mx2_CaseStmt_2::m_Sort(bbFunction<bbInt(t_mx2_CaseStmt*,t_mx2_CaseStmt*)> l_compareFunc){
  bbInt l_insize=1;
  for(;;){
    struct f1_t : public bbGCFrame{
      t_std_collections_List_1Tt_mx2_CaseStmt_2_Node* l_p{};
      t_std_collections_List_1Tt_mx2_CaseStmt_2_Node* l_tail{};
      void gcMark(){
        bbGCMarkPtr(l_p);
        bbGCMarkPtr(l_tail);
      }
    }f1{};
    bbInt l_merges=bbInt(0);
    f1.l_tail=this->m__0head;
    f1.l_p=this->m__0head->m__0succ;
    while((f1.l_p!=this->m__0head)){
      struct f2_t : public bbGCFrame{
        t_std_collections_List_1Tt_mx2_CaseStmt_2_Node* l_q{};
        void gcMark(){
          bbGCMarkPtr(l_q);
        }
      }f2{};
      l_merges+=1;
      f2.l_q=f1.l_p->m__0succ;
      bbInt l_qsize=l_insize;
      bbInt l_psize=1;
      while(((l_psize<l_insize)&&(f2.l_q!=this->m__0head))){
        l_psize+=1;
        f2.l_q=f2.l_q->m__0succ;
      }
      for(;;){
        struct f3_t : public bbGCFrame{
          t_std_collections_List_1Tt_mx2_CaseStmt_2_Node* l_t{};
          void gcMark(){
            bbGCMarkPtr(l_t);
          }
        }f3{};
        if(((bbBool(l_psize)&&bbBool(l_qsize))&&(f2.l_q!=this->m__0head))){
          bbInt l_cc=l_compareFunc(f1.l_p->m__0value,f2.l_q->m__0value);
          if((l_cc<=bbInt(0))){
            f3.l_t=f1.l_p;
            f1.l_p=f1.l_p->m__0succ;
            l_psize-=1;
          }else{
            f3.l_t=f2.l_q;
            f2.l_q=f2.l_q->m__0succ;
            l_qsize-=1;
          }
        }else if(bbBool(l_psize)){
          f3.l_t=f1.l_p;
          f1.l_p=f1.l_p->m__0succ;
          l_psize-=1;
        }else if((bbBool(l_qsize)&&(f2.l_q!=this->m__0head))){
          f3.l_t=f2.l_q;
          f2.l_q=f2.l_q->m__0succ;
          l_qsize-=1;
        }else{
          break;
        }
        f3.l_t->m__0pred=f1.l_tail;
        f1.l_tail->m__0succ=f3.l_t;
        f1.l_tail=f3.l_t;
      }
      f1.l_p=f2.l_q;
    }
    f1.l_tail->m__0succ=this->m__0head;
    this->m__0head->m__0pred=f1.l_tail;
    if((l_merges<=1)){
      return;
    }
    l_insize*=2;
  }
}

void t_std_collections_List_1Tt_mx2_CaseStmt_2::m_Sort(bbBool l_ascending){
  if(l_ascending){
    struct lambda52 : public bbFunction<bbInt(t_mx2_CaseStmt*,t_mx2_CaseStmt*)>::Rep{
      t_std_collections_List_1Tt_mx2_CaseStmt_2* l_self;
      lambda52(t_std_collections_List_1Tt_mx2_CaseStmt_2* l_self):l_self(l_self){
      }
      bbInt invoke(t_mx2_CaseStmt* l_x,t_mx2_CaseStmt* l_y){
        return bbCompare(l_x,l_y);
      }
      void gcMark(){
        bbGCMarkPtr(l_self);
      }
    };
    this->m_Sort(bbFunction<bbInt(t_mx2_CaseStmt*,t_mx2_CaseStmt*)>(new lambda52(this)));
  }else{
    struct lambda53 : public bbFunction<bbInt(t_mx2_CaseStmt*,t_mx2_CaseStmt*)>::Rep{
      t_std_collections_List_1Tt_mx2_CaseStmt_2* l_self;
      lambda53(t_std_collections_List_1Tt_mx2_CaseStmt_2* l_self):l_self(l_self){
      }
      bbInt invoke(t_mx2_CaseStmt* l_x,t_mx2_CaseStmt* l_y){
        return -bbCompare(l_x,l_y);
      }
      void gcMark(){
        bbGCMarkPtr(l_self);
      }
    };
    this->m_Sort(bbFunction<bbInt(t_mx2_CaseStmt*,t_mx2_CaseStmt*)>(new lambda53(this)));
  }
}

t_mx2_CaseStmt* t_std_collections_List_1Tt_mx2_CaseStmt_2::m_RemoveLast(){
  struct f0_t : public bbGCFrame{
    t_mx2_CaseStmt* l_value{};
    void gcMark(){
      bbGCMarkPtr(l_value);
    }
  }f0{};
  bbDebugAssert(!this->m_Empty(),BB_T("Debug assert failed"));
  f0.l_value=this->m__0head->m__0pred->m__0value;
  this->m__0head->m__0pred->m_Remove();
  this->m__0seq+=1;
  return f0.l_value;
}

bbBool t_std_collections_List_1Tt_mx2_CaseStmt_2::m_RemoveLast(t_mx2_CaseStmt* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_mx2_CaseStmt_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m_FindLastNode(l_value);
  if(!bbBool(f0.l_node)){
    return false;
  }
  f0.l_node->m_Remove();
  this->m__0seq+=1;
  return true;
}

t_mx2_CaseStmt* t_std_collections_List_1Tt_mx2_CaseStmt_2::m_RemoveFirst(){
  struct f0_t : public bbGCFrame{
    t_mx2_CaseStmt* l_value{};
    void gcMark(){
      bbGCMarkPtr(l_value);
    }
  }f0{};
  bbDebugAssert(!this->m_Empty(),BB_T("Debug assert failed"));
  f0.l_value=this->m__0head->m__0succ->m__0value;
  this->m__0head->m__0succ->m_Remove();
  this->m__0seq+=1;
  return f0.l_value;
}

bbInt t_std_collections_List_1Tt_mx2_CaseStmt_2::m_RemoveEach(t_mx2_CaseStmt* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_mx2_CaseStmt_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m__0head->m__0succ;
  bbInt l_n=bbInt(0);
  while((f0.l_node!=this->m__0head)){
    if((f0.l_node->m__0value==l_value)){
      f0.l_node=f0.l_node->m__0succ;
      f0.l_node->m__0pred->m_Remove();
      l_n+=1;
    }else{
      f0.l_node=f0.l_node->m__0succ;
    }
  }
  if(bbBool(l_n)){
    this->m__0seq+=1;
  }
  return l_n;
}

bbBool t_std_collections_List_1Tt_mx2_CaseStmt_2::m_Remove(t_mx2_CaseStmt* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_mx2_CaseStmt_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m_FindNode(l_value);
  if(!bbBool(f0.l_node)){
    return false;
  }
  f0.l_node->m_Remove();
  this->m__0seq+=1;
  return true;
}

t_std_collections_List_1Tt_mx2_CaseStmt_2_Node* t_std_collections_List_1Tt_mx2_CaseStmt_2::m_LastNode(){
  if(!this->m_Empty()){
    return this->m__0head->m__0pred;
  }
  return ((t_std_collections_List_1Tt_mx2_CaseStmt_2_Node*)0);
}

t_mx2_CaseStmt* t_std_collections_List_1Tt_mx2_CaseStmt_2::m_Last(){
  bbDebugAssert(!this->m_Empty(),BB_T("Debug assert failed"));
  return this->m__0head->m__0pred->m__0value;
}

t_std_collections_List_1Tt_mx2_CaseStmt_2_Node* t_std_collections_List_1Tt_mx2_CaseStmt_2::m_HeadNode(){
  return this->m__0head;
}

t_std_collections_List_1Tt_mx2_CaseStmt_2_Node* t_std_collections_List_1Tt_mx2_CaseStmt_2::m_FirstNode(){
  if(!this->m_Empty()){
    return this->m__0head->m__0succ;
  }
  return ((t_std_collections_List_1Tt_mx2_CaseStmt_2_Node*)0);
}

t_mx2_CaseStmt* t_std_collections_List_1Tt_mx2_CaseStmt_2::m_First(){
  bbDebugAssert(!this->m_Empty(),BB_T("Debug assert failed"));
  return this->m__0head->m__0succ->m__0value;
}

t_std_collections_List_1Tt_mx2_CaseStmt_2_Node* t_std_collections_List_1Tt_mx2_CaseStmt_2::m_FindNode(t_mx2_CaseStmt* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_mx2_CaseStmt_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m__0head->m__0succ;
  while((f0.l_node!=this->m__0head)){
    if((f0.l_node->m__0value==l_value)){
      return f0.l_node;
    }
    f0.l_node=f0.l_node->m__0succ;
  }
  return ((t_std_collections_List_1Tt_mx2_CaseStmt_2_Node*)0);
}

t_std_collections_List_1Tt_mx2_CaseStmt_2_Node* t_std_collections_List_1Tt_mx2_CaseStmt_2::m_FindLastNode(t_mx2_CaseStmt* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_mx2_CaseStmt_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m__0head->m__0pred;
  while((f0.l_node!=this->m__0head)){
    if((f0.l_node->m__0value==l_value)){
      return f0.l_node;
    }
    f0.l_node=f0.l_node->m__0pred;
  }
  return ((t_std_collections_List_1Tt_mx2_CaseStmt_2_Node*)0);
}

bbBool t_std_collections_List_1Tt_mx2_CaseStmt_2::m_Empty(){
  return (this->m__0head->m__0succ==this->m__0head);
}

bbInt t_std_collections_List_1Tt_mx2_CaseStmt_2::m_Count(){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_mx2_CaseStmt_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m__0head->m__0succ;
  bbInt l_n=bbInt(0);
  while((f0.l_node!=this->m__0head)){
    f0.l_node=f0.l_node->m__0succ;
    l_n+=1;
  }
  return l_n;
}

void t_std_collections_List_1Tt_mx2_CaseStmt_2::m_Clear(){
  this->m__0head->m__0succ=this->m__0head;
  this->m__0head->m__0pred=this->m__0head;
  this->m__0seq+=1;
}

t_std_collections_List_1Tt_mx2_CaseStmt_2_BackwardsIterator t_std_collections_List_1Tt_mx2_CaseStmt_2::m_Backwards(){
  return t_std_collections_List_1Tt_mx2_CaseStmt_2_BackwardsIterator(this,this->m__0head->m__0pred);
}

t_std_collections_List_1Tt_mx2_CaseStmt_2_Iterator t_std_collections_List_1Tt_mx2_CaseStmt_2::m_All(){
  return t_std_collections_List_1Tt_mx2_CaseStmt_2_Iterator(this,this->m__0head->m__0succ);
}

t_std_collections_List_1Tt_mx2_CaseStmt_2_Node* t_std_collections_List_1Tt_mx2_CaseStmt_2::m_AddLast(t_mx2_CaseStmt* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_mx2_CaseStmt_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=bbGCNew<t_std_collections_List_1Tt_mx2_CaseStmt_2_Node>(l_value,this->m__0head);
  this->m__0seq+=1;
  return f0.l_node;
}

t_std_collections_List_1Tt_mx2_CaseStmt_2_Node* t_std_collections_List_1Tt_mx2_CaseStmt_2::m_AddFirst(t_mx2_CaseStmt* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_mx2_CaseStmt_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=bbGCNew<t_std_collections_List_1Tt_mx2_CaseStmt_2_Node>(l_value,this->m__0head->m__0succ);
  this->m__0seq+=1;
  return f0.l_node;
}

void t_std_collections_List_1Tt_mx2_CaseStmt_2::m_AddAll(bbArray<bbGCVar<t_mx2_CaseStmt>>* l_values){
  {
    bbInt l_0=bbInt(0);
    bbInt l_1=l_values->length();
    for(;(l_0<l_1);l_0+=1){
      struct f2_t : public bbGCFrame{
        t_mx2_CaseStmt* l_value{};
        void gcMark(){
          bbGCMarkPtr(l_value);
        }
      }f2{};
      f2.l_value=l_values->at(l_0);
      this->m_AddLast(f2.l_value);
    }
  }
}

void t_std_collections_List_1Tt_mx2_CaseStmt_2::m_Add(t_mx2_CaseStmt* l_value){
  this->m_AddLast(l_value);
}

void t_std_collections_List_1Tt_mx2_FuncList_2_Node::gcMark(){
  bbGCMark(m__0succ);
  bbGCMark(m__0pred);
  bbGCMark(m__0value);
}

t_std_collections_List_1Tt_mx2_FuncList_2_Node::t_std_collections_List_1Tt_mx2_FuncList_2_Node(t_mx2_FuncList* l_value,t_std_collections_List_1Tt_mx2_FuncList_2_Node* l_succ){
  this->m__0value=l_value;
  this->m__0succ=l_succ;
  this->m__0pred=l_succ->m__0pred;
  this->m__0pred->m__0succ=this;
  l_succ->m__0pred=this;
}

t_std_collections_List_1Tt_mx2_FuncList_2_Node::t_std_collections_List_1Tt_mx2_FuncList_2_Node(t_mx2_FuncList* l_value){
  this->m__0value=l_value;
  this->m__0succ=this;
  this->m__0pred=this;
}

void t_std_collections_List_1Tt_mx2_FuncList_2_Node::m_Value(t_mx2_FuncList* l_value){
  this->m__0value=l_value;
}

t_mx2_FuncList* t_std_collections_List_1Tt_mx2_FuncList_2_Node::m_Value(){
  return this->m__0value;
}

t_std_collections_List_1Tt_mx2_FuncList_2_Node* t_std_collections_List_1Tt_mx2_FuncList_2_Node::m_Succ(){
  return this->m__0succ;
}

void t_std_collections_List_1Tt_mx2_FuncList_2_Node::m_Remove(){
  this->m__0succ->m__0pred=this->m__0pred;
  this->m__0pred->m__0succ=this->m__0succ;
}

t_std_collections_List_1Tt_mx2_FuncList_2_Node* t_std_collections_List_1Tt_mx2_FuncList_2_Node::m_Pred(){
  return this->m__0pred;
}

void t_std_collections_List_1Tt_mx2_FuncList_2_Node::m_InsertBefore(t_std_collections_List_1Tt_mx2_FuncList_2_Node* l_node){
  this->m__0succ=l_node;
  this->m__0pred=l_node->m__0pred;
  this->m__0pred->m__0succ=this;
  l_node->m__0pred=this;
}

void t_std_collections_List_1Tt_mx2_FuncList_2_Node::m_InsertAfter(t_std_collections_List_1Tt_mx2_FuncList_2_Node* l_node){
  this->m__0pred=l_node;
  this->m__0succ=l_node->m__0succ;
  this->m__0succ->m__0pred=this;
  l_node->m__0succ=this;
}

t_std_collections_List_1Tt_mx2_FuncList_2_Iterator::t_std_collections_List_1Tt_mx2_FuncList_2_Iterator(t_std_collections_List_1Tt_mx2_FuncList_2* l_list,t_std_collections_List_1Tt_mx2_FuncList_2_Node* l_node){
  (*this).m__0list=l_list;
  (*this).m__0node=l_node;
  (*this).m__0seq=l_list->m__0seq;
}

void t_std_collections_List_1Tt_mx2_FuncList_2_Iterator::m_Insert(t_mx2_FuncList* l_value){
  (*this).m_AssertSeq();
  (*this).m__0node=bbGCNew<t_std_collections_List_1Tt_mx2_FuncList_2_Node>(l_value,(*this).m__0node);
  (*this).m__0list->m__0seq+=1;
  (*this).m__0seq=(*this).m__0list->m__0seq;
}

void t_std_collections_List_1Tt_mx2_FuncList_2_Iterator::m_Erase(){
  (*this).m_AssertCurrent();
  (*this).m__0node=(*this).m__0node->m__0succ;
  (*this).m__0node->m__0pred->m_Remove();
  (*this).m__0list->m__0seq+=1;
  (*this).m__0seq=(*this).m__0list->m__0seq;
}

void t_std_collections_List_1Tt_mx2_FuncList_2_Iterator::m_Current(t_mx2_FuncList* l_current){
  (*this).m_AssertCurrent();
  (*this).m__0node->m__0value=l_current;
}

t_mx2_FuncList* t_std_collections_List_1Tt_mx2_FuncList_2_Iterator::m_Current(){
  (*this).m_AssertCurrent();
  return (*this).m__0node->m__0value;
}

void t_std_collections_List_1Tt_mx2_FuncList_2_Iterator::m_Bump(){
  (*this).m_AssertCurrent();
  (*this).m__0node=(*this).m__0node->m__0succ;
}

bbBool t_std_collections_List_1Tt_mx2_FuncList_2_Iterator::m_AtEnd(){
  (*this).m_AssertSeq();
  return ((*this).m__0node==(*this).m__0list->m__0head);
}

void t_std_collections_List_1Tt_mx2_FuncList_2_Iterator::m_AssertSeq(){
  bbDebugAssert(((*this).m__0seq==(*this).m__0list->m__0seq),BB_T("Concurrent list modification"));
}

void t_std_collections_List_1Tt_mx2_FuncList_2_Iterator::m_AssertCurrent(){
  bbDebugAssert(!(*this).m_AtEnd(),BB_T("Invalid list iterator"));
}

int bbCompare(const t_std_collections_List_1Tt_mx2_FuncList_2_Iterator&x,const t_std_collections_List_1Tt_mx2_FuncList_2_Iterator&y){
  if(int t=bbCompare(x.m__0list,y.m__0list)) return t;
  if(int t=bbCompare(x.m__0node,y.m__0node)) return t;
  if(int t=bbCompare(x.m__0seq,y.m__0seq)) return t;
  return 0;
}

void bbGCMark(const t_std_collections_List_1Tt_mx2_FuncList_2_Iterator&t){
  bbGCMark(t.m__0list);
  bbGCMark(t.m__0node);
}

t_std_collections_List_1Tt_mx2_FuncList_2_BackwardsIterator::t_std_collections_List_1Tt_mx2_FuncList_2_BackwardsIterator(t_std_collections_List_1Tt_mx2_FuncList_2* l_list,t_std_collections_List_1Tt_mx2_FuncList_2_Node* l_node){
  (*this).m__0list=l_list;
  (*this).m__0node=l_node;
  (*this).m__0seq=l_list->m__0seq;
}

void t_std_collections_List_1Tt_mx2_FuncList_2_BackwardsIterator::m_Insert(t_mx2_FuncList* l_value){
  (*this).m_AssertSeq();
  (*this).m__0node=bbGCNew<t_std_collections_List_1Tt_mx2_FuncList_2_Node>(l_value,(*this).m__0node->m__0succ);
  (*this).m__0list->m__0seq+=1;
  (*this).m__0seq=(*this).m__0list->m__0seq;
}

void t_std_collections_List_1Tt_mx2_FuncList_2_BackwardsIterator::m_Erase(){
  (*this).m_AssertCurrent();
  (*this).m__0node=(*this).m__0node->m__0pred;
  (*this).m__0node->m__0succ->m_Remove();
  (*this).m__0list->m__0seq+=1;
  (*this).m__0seq=(*this).m__0list->m__0seq;
}

void t_std_collections_List_1Tt_mx2_FuncList_2_BackwardsIterator::m_Current(t_mx2_FuncList* l_current){
  (*this).m_AssertCurrent();
  (*this).m__0node->m__0value=l_current;
}

t_mx2_FuncList* t_std_collections_List_1Tt_mx2_FuncList_2_BackwardsIterator::m_Current(){
  (*this).m_AssertCurrent();
  return (*this).m__0node->m__0value;
}

void t_std_collections_List_1Tt_mx2_FuncList_2_BackwardsIterator::m_Bump(){
  (*this).m_AssertCurrent();
  (*this).m__0node=(*this).m__0node->m__0pred;
}

bbBool t_std_collections_List_1Tt_mx2_FuncList_2_BackwardsIterator::m_AtEnd(){
  (*this).m_AssertSeq();
  return ((*this).m__0node==(*this).m__0list->m__0head);
}

void t_std_collections_List_1Tt_mx2_FuncList_2_BackwardsIterator::m_AssertSeq(){
  bbDebugAssert(((*this).m__0seq==(*this).m__0list->m__0seq),BB_T("Concurrent list modification"));
}

void t_std_collections_List_1Tt_mx2_FuncList_2_BackwardsIterator::m_AssertCurrent(){
  bbDebugAssert(!(*this).m_AtEnd(),BB_T("Invalid list iterator"));
}

int bbCompare(const t_std_collections_List_1Tt_mx2_FuncList_2_BackwardsIterator&x,const t_std_collections_List_1Tt_mx2_FuncList_2_BackwardsIterator&y){
  if(int t=bbCompare(x.m__0list,y.m__0list)) return t;
  if(int t=bbCompare(x.m__0node,y.m__0node)) return t;
  if(int t=bbCompare(x.m__0seq,y.m__0seq)) return t;
  return 0;
}

void bbGCMark(const t_std_collections_List_1Tt_mx2_FuncList_2_BackwardsIterator&t){
  bbGCMark(t.m__0list);
  bbGCMark(t.m__0node);
}

void t_std_collections_List_1Tt_mx2_FuncList_2::gcMark(){
  bbGCMark(m__0head);
}

t_std_collections_List_1Tt_mx2_FuncList_2::t_std_collections_List_1Tt_mx2_FuncList_2(t_std_collections_List_1Tt_mx2_FuncList_2* l_values):t_std_collections_List_1Tt_mx2_FuncList_2(){
  g_std_collections_List_1Tt_mx2_FuncList_2_AddAll_1Tt_std_collections_List_1Tt_mx2_FuncList_2_2(this,l_values);
}

t_std_collections_List_1Tt_mx2_FuncList_2::t_std_collections_List_1Tt_mx2_FuncList_2(t_std_collections_Stack_1Tt_mx2_FuncList_2* l_values):t_std_collections_List_1Tt_mx2_FuncList_2(){
  g_std_collections_List_1Tt_mx2_FuncList_2_AddAll_1Tt_std_collections_Stack_1Tt_mx2_FuncList_2_2(this,l_values);
}

t_std_collections_List_1Tt_mx2_FuncList_2::t_std_collections_List_1Tt_mx2_FuncList_2(bbArray<bbGCVar<t_mx2_FuncList>>* l_values):t_std_collections_List_1Tt_mx2_FuncList_2(){
  this->m_AddAll(l_values);
}

t_std_collections_List_1Tt_mx2_FuncList_2::t_std_collections_List_1Tt_mx2_FuncList_2(){
  this->m__0head=bbGCNew<t_std_collections_List_1Tt_mx2_FuncList_2_Node>(((t_mx2_FuncList*)0));
}

bbArray<bbGCVar<t_mx2_FuncList>>* t_std_collections_List_1Tt_mx2_FuncList_2::m_ToArray(){
  struct f0_t : public bbGCFrame{
    bbArray<bbGCVar<t_mx2_FuncList>>* l_data{};
    t_std_collections_List_1Tt_mx2_FuncList_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_data);
      bbGCMarkPtr(l_node);
    }
  }f0{};
  bbInt l_n=this->m_Count();
  f0.l_data=bbArray<bbGCVar<t_mx2_FuncList>>::create(l_n);
  f0.l_node=this->m__0head->m__0succ;
  {
    bbInt l_i=bbInt(0);
    for(;(l_i<l_n);l_i+=1){
      f0.l_data->at(l_i)=f0.l_node->m__0value;
      f0.l_node=f0.l_node->m__0succ;
    }
  }
  return f0.l_data;
}

void t_std_collections_List_1Tt_mx2_FuncList_2::m_Sort(bbFunction<bbInt(t_mx2_FuncList*,t_mx2_FuncList*)> l_compareFunc){
  bbInt l_insize=1;
  for(;;){
    struct f1_t : public bbGCFrame{
      t_std_collections_List_1Tt_mx2_FuncList_2_Node* l_p{};
      t_std_collections_List_1Tt_mx2_FuncList_2_Node* l_tail{};
      void gcMark(){
        bbGCMarkPtr(l_p);
        bbGCMarkPtr(l_tail);
      }
    }f1{};
    bbInt l_merges=bbInt(0);
    f1.l_tail=this->m__0head;
    f1.l_p=this->m__0head->m__0succ;
    while((f1.l_p!=this->m__0head)){
      struct f2_t : public bbGCFrame{
        t_std_collections_List_1Tt_mx2_FuncList_2_Node* l_q{};
        void gcMark(){
          bbGCMarkPtr(l_q);
        }
      }f2{};
      l_merges+=1;
      f2.l_q=f1.l_p->m__0succ;
      bbInt l_qsize=l_insize;
      bbInt l_psize=1;
      while(((l_psize<l_insize)&&(f2.l_q!=this->m__0head))){
        l_psize+=1;
        f2.l_q=f2.l_q->m__0succ;
      }
      for(;;){
        struct f3_t : public bbGCFrame{
          t_std_collections_List_1Tt_mx2_FuncList_2_Node* l_t{};
          void gcMark(){
            bbGCMarkPtr(l_t);
          }
        }f3{};
        if(((bbBool(l_psize)&&bbBool(l_qsize))&&(f2.l_q!=this->m__0head))){
          bbInt l_cc=l_compareFunc(f1.l_p->m__0value,f2.l_q->m__0value);
          if((l_cc<=bbInt(0))){
            f3.l_t=f1.l_p;
            f1.l_p=f1.l_p->m__0succ;
            l_psize-=1;
          }else{
            f3.l_t=f2.l_q;
            f2.l_q=f2.l_q->m__0succ;
            l_qsize-=1;
          }
        }else if(bbBool(l_psize)){
          f3.l_t=f1.l_p;
          f1.l_p=f1.l_p->m__0succ;
          l_psize-=1;
        }else if((bbBool(l_qsize)&&(f2.l_q!=this->m__0head))){
          f3.l_t=f2.l_q;
          f2.l_q=f2.l_q->m__0succ;
          l_qsize-=1;
        }else{
          break;
        }
        f3.l_t->m__0pred=f1.l_tail;
        f1.l_tail->m__0succ=f3.l_t;
        f1.l_tail=f3.l_t;
      }
      f1.l_p=f2.l_q;
    }
    f1.l_tail->m__0succ=this->m__0head;
    this->m__0head->m__0pred=f1.l_tail;
    if((l_merges<=1)){
      return;
    }
    l_insize*=2;
  }
}

void t_std_collections_List_1Tt_mx2_FuncList_2::m_Sort(bbBool l_ascending){
  if(l_ascending){
    struct lambda54 : public bbFunction<bbInt(t_mx2_FuncList*,t_mx2_FuncList*)>::Rep{
      t_std_collections_List_1Tt_mx2_FuncList_2* l_self;
      lambda54(t_std_collections_List_1Tt_mx2_FuncList_2* l_self):l_self(l_self){
      }
      bbInt invoke(t_mx2_FuncList* l_x,t_mx2_FuncList* l_y){
        return bbCompare(l_x,l_y);
      }
      void gcMark(){
        bbGCMarkPtr(l_self);
      }
    };
    this->m_Sort(bbFunction<bbInt(t_mx2_FuncList*,t_mx2_FuncList*)>(new lambda54(this)));
  }else{
    struct lambda55 : public bbFunction<bbInt(t_mx2_FuncList*,t_mx2_FuncList*)>::Rep{
      t_std_collections_List_1Tt_mx2_FuncList_2* l_self;
      lambda55(t_std_collections_List_1Tt_mx2_FuncList_2* l_self):l_self(l_self){
      }
      bbInt invoke(t_mx2_FuncList* l_x,t_mx2_FuncList* l_y){
        return -bbCompare(l_x,l_y);
      }
      void gcMark(){
        bbGCMarkPtr(l_self);
      }
    };
    this->m_Sort(bbFunction<bbInt(t_mx2_FuncList*,t_mx2_FuncList*)>(new lambda55(this)));
  }
}

t_mx2_FuncList* t_std_collections_List_1Tt_mx2_FuncList_2::m_RemoveLast(){
  struct f0_t : public bbGCFrame{
    t_mx2_FuncList* l_value{};
    void gcMark(){
      bbGCMarkPtr(l_value);
    }
  }f0{};
  bbDebugAssert(!this->m_Empty(),BB_T("Debug assert failed"));
  f0.l_value=this->m__0head->m__0pred->m__0value;
  this->m__0head->m__0pred->m_Remove();
  this->m__0seq+=1;
  return f0.l_value;
}

bbBool t_std_collections_List_1Tt_mx2_FuncList_2::m_RemoveLast(t_mx2_FuncList* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_mx2_FuncList_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m_FindLastNode(l_value);
  if(!bbBool(f0.l_node)){
    return false;
  }
  f0.l_node->m_Remove();
  this->m__0seq+=1;
  return true;
}

t_mx2_FuncList* t_std_collections_List_1Tt_mx2_FuncList_2::m_RemoveFirst(){
  struct f0_t : public bbGCFrame{
    t_mx2_FuncList* l_value{};
    void gcMark(){
      bbGCMarkPtr(l_value);
    }
  }f0{};
  bbDebugAssert(!this->m_Empty(),BB_T("Debug assert failed"));
  f0.l_value=this->m__0head->m__0succ->m__0value;
  this->m__0head->m__0succ->m_Remove();
  this->m__0seq+=1;
  return f0.l_value;
}

bbInt t_std_collections_List_1Tt_mx2_FuncList_2::m_RemoveEach(t_mx2_FuncList* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_mx2_FuncList_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m__0head->m__0succ;
  bbInt l_n=bbInt(0);
  while((f0.l_node!=this->m__0head)){
    if((f0.l_node->m__0value==l_value)){
      f0.l_node=f0.l_node->m__0succ;
      f0.l_node->m__0pred->m_Remove();
      l_n+=1;
    }else{
      f0.l_node=f0.l_node->m__0succ;
    }
  }
  if(bbBool(l_n)){
    this->m__0seq+=1;
  }
  return l_n;
}

bbBool t_std_collections_List_1Tt_mx2_FuncList_2::m_Remove(t_mx2_FuncList* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_mx2_FuncList_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m_FindNode(l_value);
  if(!bbBool(f0.l_node)){
    return false;
  }
  f0.l_node->m_Remove();
  this->m__0seq+=1;
  return true;
}

t_std_collections_List_1Tt_mx2_FuncList_2_Node* t_std_collections_List_1Tt_mx2_FuncList_2::m_LastNode(){
  if(!this->m_Empty()){
    return this->m__0head->m__0pred;
  }
  return ((t_std_collections_List_1Tt_mx2_FuncList_2_Node*)0);
}

t_mx2_FuncList* t_std_collections_List_1Tt_mx2_FuncList_2::m_Last(){
  bbDebugAssert(!this->m_Empty(),BB_T("Debug assert failed"));
  return this->m__0head->m__0pred->m__0value;
}

t_std_collections_List_1Tt_mx2_FuncList_2_Node* t_std_collections_List_1Tt_mx2_FuncList_2::m_HeadNode(){
  return this->m__0head;
}

t_std_collections_List_1Tt_mx2_FuncList_2_Node* t_std_collections_List_1Tt_mx2_FuncList_2::m_FirstNode(){
  if(!this->m_Empty()){
    return this->m__0head->m__0succ;
  }
  return ((t_std_collections_List_1Tt_mx2_FuncList_2_Node*)0);
}

t_mx2_FuncList* t_std_collections_List_1Tt_mx2_FuncList_2::m_First(){
  bbDebugAssert(!this->m_Empty(),BB_T("Debug assert failed"));
  return this->m__0head->m__0succ->m__0value;
}

t_std_collections_List_1Tt_mx2_FuncList_2_Node* t_std_collections_List_1Tt_mx2_FuncList_2::m_FindNode(t_mx2_FuncList* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_mx2_FuncList_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m__0head->m__0succ;
  while((f0.l_node!=this->m__0head)){
    if((f0.l_node->m__0value==l_value)){
      return f0.l_node;
    }
    f0.l_node=f0.l_node->m__0succ;
  }
  return ((t_std_collections_List_1Tt_mx2_FuncList_2_Node*)0);
}

t_std_collections_List_1Tt_mx2_FuncList_2_Node* t_std_collections_List_1Tt_mx2_FuncList_2::m_FindLastNode(t_mx2_FuncList* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_mx2_FuncList_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m__0head->m__0pred;
  while((f0.l_node!=this->m__0head)){
    if((f0.l_node->m__0value==l_value)){
      return f0.l_node;
    }
    f0.l_node=f0.l_node->m__0pred;
  }
  return ((t_std_collections_List_1Tt_mx2_FuncList_2_Node*)0);
}

bbBool t_std_collections_List_1Tt_mx2_FuncList_2::m_Empty(){
  return (this->m__0head->m__0succ==this->m__0head);
}

bbInt t_std_collections_List_1Tt_mx2_FuncList_2::m_Count(){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_mx2_FuncList_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m__0head->m__0succ;
  bbInt l_n=bbInt(0);
  while((f0.l_node!=this->m__0head)){
    f0.l_node=f0.l_node->m__0succ;
    l_n+=1;
  }
  return l_n;
}

void t_std_collections_List_1Tt_mx2_FuncList_2::m_Clear(){
  this->m__0head->m__0succ=this->m__0head;
  this->m__0head->m__0pred=this->m__0head;
  this->m__0seq+=1;
}

t_std_collections_List_1Tt_mx2_FuncList_2_BackwardsIterator t_std_collections_List_1Tt_mx2_FuncList_2::m_Backwards(){
  return t_std_collections_List_1Tt_mx2_FuncList_2_BackwardsIterator(this,this->m__0head->m__0pred);
}

t_std_collections_List_1Tt_mx2_FuncList_2_Iterator t_std_collections_List_1Tt_mx2_FuncList_2::m_All(){
  return t_std_collections_List_1Tt_mx2_FuncList_2_Iterator(this,this->m__0head->m__0succ);
}

t_std_collections_List_1Tt_mx2_FuncList_2_Node* t_std_collections_List_1Tt_mx2_FuncList_2::m_AddLast(t_mx2_FuncList* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_mx2_FuncList_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=bbGCNew<t_std_collections_List_1Tt_mx2_FuncList_2_Node>(l_value,this->m__0head);
  this->m__0seq+=1;
  return f0.l_node;
}

t_std_collections_List_1Tt_mx2_FuncList_2_Node* t_std_collections_List_1Tt_mx2_FuncList_2::m_AddFirst(t_mx2_FuncList* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_mx2_FuncList_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=bbGCNew<t_std_collections_List_1Tt_mx2_FuncList_2_Node>(l_value,this->m__0head->m__0succ);
  this->m__0seq+=1;
  return f0.l_node;
}

void t_std_collections_List_1Tt_mx2_FuncList_2::m_AddAll(bbArray<bbGCVar<t_mx2_FuncList>>* l_values){
  {
    bbInt l_0=bbInt(0);
    bbInt l_1=l_values->length();
    for(;(l_0<l_1);l_0+=1){
      struct f2_t : public bbGCFrame{
        t_mx2_FuncList* l_value{};
        void gcMark(){
          bbGCMarkPtr(l_value);
        }
      }f2{};
      f2.l_value=l_values->at(l_0);
      this->m_AddLast(f2.l_value);
    }
  }
}

void t_std_collections_List_1Tt_mx2_FuncList_2::m_Add(t_mx2_FuncList* l_value){
  this->m_AddLast(l_value);
}

void mx2_mx2cc_std_collections_2list_init(){
  static bool done;
  if(done) return;
  done=true;
}

bbInit mx2_mx2cc_std_collections_2list_init_v("mx2cc_std_collections_2list",&mx2_mx2cc_std_collections_2list_init);
