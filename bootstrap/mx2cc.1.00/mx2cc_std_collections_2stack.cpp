
#include "mx2cc_std_collections_2stack.h"

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
#include "mx2cc_std_collections_2list.h"
#include "mx2cc_stmt.h"
#include "mx2cc_stmtexpr.h"
#include "mx2cc_toker.h"
#include "mx2cc_translator.h"
#include "mx2cc_type.h"
#include "mx2cc_typeexpr.h"
#include "mx2cc_var.h"
#include "../../../../../modules/std/std.buildv1.0.0/desktop_release_linux/std_collections_2stack.h"

extern bbInt g_monkey_math_Max_1i(bbInt l_x,bbInt l_y);

// ***** Internal *****

void g_std_collections_Stack_1Tt_mx2_Translator_GCTmp_2_AddAll_1Tt_std_collections_List_1Tt_mx2_Translator_GCTmp_2_2(t_std_collections_Stack_1Tt_mx2_Translator_GCTmp_2* l_self,t_std_collections_List_1Tt_mx2_Translator_GCTmp_2* l_values){
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
      l_self->m_Add(f2.l_value);
    }
  }
}

void g_std_collections_Stack_1Tt_mx2_Stmt_2_AddAll_1Tt_std_collections_List_1Tt_mx2_Stmt_2_2(t_std_collections_Stack_1Tt_mx2_Stmt_2* l_self,t_std_collections_List_1Tt_mx2_Stmt_2* l_values){
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
      l_self->m_Add(f2.l_value);
    }
  }
}

void g_std_collections_Stack_1Tt_mx2_Toker_2_AddAll_1Tt_std_collections_List_1Tt_mx2_Toker_2_2(t_std_collections_Stack_1Tt_mx2_Toker_2* l_self,t_std_collections_List_1Tt_mx2_Toker_2* l_values){
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
      l_self->m_Add(f2.l_value);
    }
  }
}

void g_std_collections_Stack_1Tt_mx2_ParseEx_2_AddAll_1Tt_std_collections_List_1Tt_mx2_ParseEx_2_2(t_std_collections_Stack_1Tt_mx2_ParseEx_2* l_self,t_std_collections_List_1Tt_mx2_ParseEx_2* l_values){
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
      l_self->m_Add(f2.l_value);
    }
  }
}

void g_std_collections_Stack_1Tt_mx2_TypeExpr_2_AddAll_1Tt_std_collections_List_1Tt_mx2_TypeExpr_2_2(t_std_collections_Stack_1Tt_mx2_TypeExpr_2* l_self,t_std_collections_List_1Tt_mx2_TypeExpr_2* l_values){
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
      l_self->m_Add(f2.l_value);
    }
  }
}

void g_std_collections_Stack_1Tt_mx2_CatchExpr_2_AddAll_1Tt_std_collections_List_1Tt_mx2_CatchExpr_2_2(t_std_collections_Stack_1Tt_mx2_CatchExpr_2* l_self,t_std_collections_List_1Tt_mx2_CatchExpr_2* l_values){
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
      l_self->m_Add(f2.l_value);
    }
  }
}

void g_std_collections_Stack_1Tt_mx2_StmtExpr_2_AddAll_1Tt_std_collections_List_1Tt_mx2_StmtExpr_2_2(t_std_collections_Stack_1Tt_mx2_StmtExpr_2* l_self,t_std_collections_List_1Tt_mx2_StmtExpr_2* l_values){
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
      l_self->m_Add(f2.l_value);
    }
  }
}

void g_std_collections_Stack_1Tt_mx2_Expr_2_AddAll_1Tt_std_collections_List_1Tt_mx2_Expr_2_2(t_std_collections_Stack_1Tt_mx2_Expr_2* l_self,t_std_collections_List_1Tt_mx2_Expr_2* l_values){
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
      l_self->m_Add(f2.l_value);
    }
  }
}

void g_std_collections_Stack_1Tt_mx2_CaseExpr_2_AddAll_1Tt_std_collections_List_1Tt_mx2_CaseExpr_2_2(t_std_collections_Stack_1Tt_mx2_CaseExpr_2* l_self,t_std_collections_List_1Tt_mx2_CaseExpr_2* l_values){
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
      l_self->m_Add(f2.l_value);
    }
  }
}

void g_std_collections_Stack_1Tt_mx2_VarDecl_2_AddAll_1Tt_std_collections_List_1Tt_mx2_VarDecl_2_2(t_std_collections_Stack_1Tt_mx2_VarDecl_2* l_self,t_std_collections_List_1Tt_mx2_VarDecl_2* l_values){
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
      l_self->m_Add(f2.l_value);
    }
  }
}

void g_std_collections_Stack_1Tt_mx2_Decl_2_AddAll_1Tt_std_collections_List_1Tt_mx2_Decl_2_2(t_std_collections_Stack_1Tt_mx2_Decl_2* l_self,t_std_collections_List_1Tt_mx2_Decl_2* l_values){
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
      l_self->m_Add(f2.l_value);
    }
  }
}

void g_std_collections_Stack_1Tt_mx2_CatchStmt_2_AddAll_1Tt_std_collections_List_1Tt_mx2_CatchStmt_2_2(t_std_collections_Stack_1Tt_mx2_CatchStmt_2* l_self,t_std_collections_List_1Tt_mx2_CatchStmt_2* l_values){
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
      l_self->m_Add(f2.l_value);
    }
  }
}

void g_std_collections_Stack_1Tt_mx2_CaseStmt_2_AddAll_1Tt_std_collections_List_1Tt_mx2_CaseStmt_2_2(t_std_collections_Stack_1Tt_mx2_CaseStmt_2* l_self,t_std_collections_List_1Tt_mx2_CaseStmt_2* l_values){
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
      l_self->m_Add(f2.l_value);
    }
  }
}

void g_std_collections_Stack_1Tt_mx2_FuncListType_2_AddAll_1Tt_std_collections_List_1Tt_mx2_FuncListType_2_2(t_std_collections_Stack_1Tt_mx2_FuncListType_2* l_self,t_std_collections_List_1Tt_mx2_FuncListType_2* l_values){
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
      l_self->m_Add(f2.l_value);
    }
  }
}

void g_std_collections_Stack_1Tt_mx2_AliasType_2_AddAll_1Tt_std_collections_List_1Tt_mx2_AliasType_2_2(t_std_collections_Stack_1Tt_mx2_AliasType_2* l_self,t_std_collections_List_1Tt_mx2_AliasType_2* l_values){
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
      l_self->m_Add(f2.l_value);
    }
  }
}

void g_std_collections_Stack_1Tt_mx2_PNode_2_AddAll_1Tt_std_collections_List_1Tt_mx2_PNode_2_2(t_std_collections_Stack_1Tt_mx2_PNode_2* l_self,t_std_collections_List_1Tt_mx2_PNode_2* l_values){
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
      l_self->m_Add(f2.l_value);
    }
  }
}

void g_std_collections_Stack_1Tt_mx2_NamespaceScope_2_AddAll_1Tt_std_collections_List_1Tt_mx2_NamespaceScope_2_2(t_std_collections_Stack_1Tt_mx2_NamespaceScope_2* l_self,t_std_collections_List_1Tt_mx2_NamespaceScope_2* l_values){
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
      l_self->m_Add(f2.l_value);
    }
  }
}

void g_std_collections_Stack_1Tt_mx2_FileScope_2_AddAll_1Tt_std_collections_List_1Tt_mx2_FileScope_2_2(t_std_collections_Stack_1Tt_mx2_FileScope_2* l_self,t_std_collections_List_1Tt_mx2_FileScope_2* l_values){
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
      l_self->m_Add(f2.l_value);
    }
  }
}

void g_std_collections_Stack_1Tt_mx2_FileDecl_2_AddAll_1Tt_std_collections_List_1Tt_mx2_FileDecl_2_2(t_std_collections_Stack_1Tt_mx2_FileDecl_2* l_self,t_std_collections_List_1Tt_mx2_FileDecl_2* l_values){
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
      l_self->m_Add(f2.l_value);
    }
  }
}

void g_std_collections_Stack_1Tt_std_collections_Stack_1s_2_AddAll_1Tt_std_collections_List_1Tt_std_collections_Stack_1s_2_2(t_std_collections_Stack_1Tt_std_collections_Stack_1s_2* l_self,t_std_collections_List_1Tt_std_collections_Stack_1s_2* l_values){
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
      l_self->m_Add(f2.l_value);
    }
  }
}

void g_std_collections_Stack_1s_Append_1Tt_std_collections_Stack_1s_2(t_std_collections_Stack_1s* l_self,t_std_collections_Stack_1s* l_values){
  {
    struct f1_t : public bbGCFrame{
      t_std_collections_Stack_1s_Iterator l_0{};
      void gcMark(){
        bbGCMark(l_0);
      }
    }f1{};
    f1.l_0=l_values->m_All();
    for(;!f1.l_0.m_AtEnd();f1.l_0.m_Bump()){
      bbString l_value=f1.l_0.m_Current();
      l_self->m_Add(l_value);
    }
  }
}

void g_std_collections_Stack_1Tt_mx2_VarValue_2_AddAll_1Tt_std_collections_List_1Tt_mx2_VarValue_2_2(t_std_collections_Stack_1Tt_mx2_VarValue_2* l_self,t_std_collections_List_1Tt_mx2_VarValue_2* l_values){
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
      l_self->m_Add(f2.l_value);
    }
  }
}

void g_std_collections_Stack_1Tt_mx2_FuncList_2_AddAll_1Tt_std_collections_List_1Tt_mx2_FuncList_2_2(t_std_collections_Stack_1Tt_mx2_FuncList_2* l_self,t_std_collections_List_1Tt_mx2_FuncList_2* l_values){
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
      l_self->m_Add(f2.l_value);
    }
  }
}

void g_std_collections_Stack_1Tt_mx2_SNode_2_AddAll_1Tt_std_collections_List_1Tt_mx2_SNode_2_2(t_std_collections_Stack_1Tt_mx2_SNode_2* l_self,t_std_collections_List_1Tt_mx2_SNode_2* l_values){
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
      l_self->m_Add(f2.l_value);
    }
  }
}

void g_std_collections_Stack_1Tt_mx2_Scope_2_AddAll_1Tt_std_collections_List_1Tt_mx2_Scope_2_2(t_std_collections_Stack_1Tt_mx2_Scope_2* l_self,t_std_collections_List_1Tt_mx2_Scope_2* l_values){
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
      l_self->m_Add(f2.l_value);
    }
  }
}

void g_std_collections_Stack_1Tt_mx2_ClassType_2_AddAll_1Tt_std_collections_List_1Tt_mx2_ClassType_2_2(t_std_collections_Stack_1Tt_mx2_ClassType_2* l_self,t_std_collections_List_1Tt_mx2_ClassType_2* l_values){
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
      l_self->m_Add(f2.l_value);
    }
  }
}

void g_std_collections_Stack_1Tt_mx2_ErrorEx_2_AddAll_1Tt_std_collections_List_1Tt_mx2_ErrorEx_2_2(t_std_collections_Stack_1Tt_mx2_ErrorEx_2* l_self,t_std_collections_List_1Tt_mx2_ErrorEx_2* l_values){
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
      l_self->m_Add(f2.l_value);
    }
  }
}

void g_std_collections_Stack_1Tt_mx2_Module_2_AddAll_1Tt_std_collections_List_1Tt_mx2_Module_2_2(t_std_collections_Stack_1Tt_mx2_Module_2* l_self,t_std_collections_List_1Tt_mx2_Module_2* l_values){
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
      l_self->m_Add(f2.l_value);
    }
  }
}

void g_std_collections_Stack_1Tt_mx2_FuncValue_2_AddAll_1Tt_std_collections_List_1Tt_mx2_FuncValue_2_2(t_std_collections_Stack_1Tt_mx2_FuncValue_2* l_self,t_std_collections_List_1Tt_mx2_FuncValue_2* l_values){
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
      l_self->m_Add(f2.l_value);
    }
  }
}

t_std_collections_Stack_1Tt_mx2_FuncValue_2_Iterator::t_std_collections_Stack_1Tt_mx2_FuncValue_2_Iterator(t_std_collections_Stack_1Tt_mx2_FuncValue_2* l_stack,bbInt l_index){
  (*this).m__0stack=l_stack;
  (*this).m__0index=l_index;
  (*this).m__0seq=l_stack->m__0seq;
}

void t_std_collections_Stack_1Tt_mx2_FuncValue_2_Iterator::m_Insert(t_mx2_FuncValue* l_value){
  (*this).m_AssertSeq();
  (*this).m__0stack->m_Insert((*this).m__0index,l_value);
  (*this).m__0seq=(*this).m__0stack->m__0seq;
}

void t_std_collections_Stack_1Tt_mx2_FuncValue_2_Iterator::m_Erase(){
  (*this).m_AssertSeq();
  (*this).m__0stack->m_Erase((*this).m__0index);
  (*this).m__0seq=(*this).m__0stack->m__0seq;
}

void t_std_collections_Stack_1Tt_mx2_FuncValue_2_Iterator::m_Current(t_mx2_FuncValue* l_current){
  (*this).m_AssertCurrent();
  (*this).m__0stack->m__0data->at((*this).m__0index)=l_current;
}

t_mx2_FuncValue* t_std_collections_Stack_1Tt_mx2_FuncValue_2_Iterator::m_Current(){
  (*this).m_AssertCurrent();
  return (*this).m__0stack->m__0data->at((*this).m__0index);
}

void t_std_collections_Stack_1Tt_mx2_FuncValue_2_Iterator::m_Bump(){
  (*this).m_AssertCurrent();
  (*this).m__0index+=1;
}

bbBool t_std_collections_Stack_1Tt_mx2_FuncValue_2_Iterator::m_AtEnd(){
  (*this).m_AssertSeq();
  return ((*this).m__0index==(*this).m__0stack->m__0length);
}

void t_std_collections_Stack_1Tt_mx2_FuncValue_2_Iterator::m_AssertSeq(){
  bbDebugAssert(((*this).m__0seq==(*this).m__0stack->m__0seq),BB_T("Concurrent list modification"));
}

void t_std_collections_Stack_1Tt_mx2_FuncValue_2_Iterator::m_AssertCurrent(){
  bbDebugAssert(!(*this).m_AtEnd(),BB_T("Invalid list iterator"));
}

int bbCompare(const t_std_collections_Stack_1Tt_mx2_FuncValue_2_Iterator&x,const t_std_collections_Stack_1Tt_mx2_FuncValue_2_Iterator&y){
  if(int t=bbCompare(x.m__0stack,y.m__0stack)) return t;
  if(int t=bbCompare(x.m__0index,y.m__0index)) return t;
  if(int t=bbCompare(x.m__0seq,y.m__0seq)) return t;
  return 0;
}

void bbGCMark(const t_std_collections_Stack_1Tt_mx2_FuncValue_2_Iterator&t){
  bbGCMark(t.m__0stack);
}

t_std_collections_Stack_1Tt_mx2_FuncValue_2_BackwardsIterator::t_std_collections_Stack_1Tt_mx2_FuncValue_2_BackwardsIterator(t_std_collections_Stack_1Tt_mx2_FuncValue_2* l_stack,bbInt l_index){
  (*this).m__0stack=l_stack;
  (*this).m__0index=l_index;
  (*this).m__0seq=l_stack->m__0seq;
}

void t_std_collections_Stack_1Tt_mx2_FuncValue_2_BackwardsIterator::m_Insert(t_mx2_FuncValue* l_value){
  (*this).m_AssertSeq();
  (*this).m__0index+=1;
  (*this).m__0stack->m_Insert((*this).m__0index,l_value);
  (*this).m__0seq=(*this).m__0stack->m__0seq;
}

void t_std_collections_Stack_1Tt_mx2_FuncValue_2_BackwardsIterator::m_Erase(){
  (*this).m_AssertCurrent();
  (*this).m__0index-=1;
  (*this).m__0stack->m_Erase(((*this).m__0index+1));
  (*this).m__0seq=(*this).m__0stack->m__0seq;
}

void t_std_collections_Stack_1Tt_mx2_FuncValue_2_BackwardsIterator::m_Current(t_mx2_FuncValue* l_current){
  (*this).m_AssertCurrent();
  (*this).m__0stack->m__0data->at((*this).m__0index)=l_current;
}

t_mx2_FuncValue* t_std_collections_Stack_1Tt_mx2_FuncValue_2_BackwardsIterator::m_Current(){
  (*this).m_AssertCurrent();
  return (*this).m__0stack->m__0data->at((*this).m__0index);
}

void t_std_collections_Stack_1Tt_mx2_FuncValue_2_BackwardsIterator::m_Bump(){
  (*this).m_AssertCurrent();
  (*this).m__0index-=1;
}

bbBool t_std_collections_Stack_1Tt_mx2_FuncValue_2_BackwardsIterator::m_AtEnd(){
  (*this).m_AssertSeq();
  return ((*this).m__0index==-1);
}

void t_std_collections_Stack_1Tt_mx2_FuncValue_2_BackwardsIterator::m_AssertSeq(){
  bbDebugAssert(((*this).m__0seq==(*this).m__0stack->m__0seq),BB_T("Concurrent list modification"));
}

void t_std_collections_Stack_1Tt_mx2_FuncValue_2_BackwardsIterator::m_AssertCurrent(){
  bbDebugAssert(!(*this).m_AtEnd(),BB_T("Invalid list iterator"));
}

int bbCompare(const t_std_collections_Stack_1Tt_mx2_FuncValue_2_BackwardsIterator&x,const t_std_collections_Stack_1Tt_mx2_FuncValue_2_BackwardsIterator&y){
  if(int t=bbCompare(x.m__0stack,y.m__0stack)) return t;
  if(int t=bbCompare(x.m__0index,y.m__0index)) return t;
  if(int t=bbCompare(x.m__0seq,y.m__0seq)) return t;
  return 0;
}

void bbGCMark(const t_std_collections_Stack_1Tt_mx2_FuncValue_2_BackwardsIterator&t){
  bbGCMark(t.m__0stack);
}

void t_std_collections_Stack_1Tt_mx2_FuncValue_2::gcMark(){
  bbGCMark(m__0data);
}

t_std_collections_Stack_1Tt_mx2_FuncValue_2::t_std_collections_Stack_1Tt_mx2_FuncValue_2(t_std_collections_List_1Tt_mx2_FuncValue_2* l_values){
  g_std_collections_Stack_1Tt_mx2_FuncValue_2_AddAll_1Tt_std_collections_List_1Tt_mx2_FuncValue_2_2(this,l_values);
}

t_std_collections_Stack_1Tt_mx2_FuncValue_2::t_std_collections_Stack_1Tt_mx2_FuncValue_2(t_std_collections_Stack_1Tt_mx2_FuncValue_2* l_values){
  struct f0_t : public bbGCFrame{
    bbArray<bbGCVar<t_mx2_FuncValue>>* t0{};
    void gcMark(){
      bbGCMarkPtr(t0);
    }
  }f0{};
  this->m__0length=l_values->m_Length();
  this->m__0data=bbArray<bbGCVar<t_mx2_FuncValue>>::create(this->m__0length);
  (f0.t0=l_values->m_Data())->copyTo(this->m__0data,bbInt(0),bbInt(0),this->m__0length);
}

t_std_collections_Stack_1Tt_mx2_FuncValue_2::t_std_collections_Stack_1Tt_mx2_FuncValue_2(bbArray<bbGCVar<t_mx2_FuncValue>>* l_values){
  this->m_AddAll(l_values);
}

t_std_collections_Stack_1Tt_mx2_FuncValue_2::t_std_collections_Stack_1Tt_mx2_FuncValue_2(bbInt l_length){
  this->m__0length=l_length;
  this->m__0data=bbArray<bbGCVar<t_mx2_FuncValue>>::create(this->m__0length);
}

t_std_collections_Stack_1Tt_mx2_FuncValue_2::t_std_collections_Stack_1Tt_mx2_FuncValue_2(){
  this->m__0data=bbArray<bbGCVar<t_mx2_FuncValue>>::create(10);
}

void t_std_collections_Stack_1Tt_mx2_FuncValue_2::m__idxeq(bbInt l_index,t_mx2_FuncValue* l_value){
  bbDebugAssert(((l_index>=bbInt(0))&&(l_index<this->m__0length)),BB_T("Stack index out of range"));
  this->m__0data->at(l_index)=l_value;
}

t_mx2_FuncValue* t_std_collections_Stack_1Tt_mx2_FuncValue_2::m__idx(bbInt l_index){
  bbDebugAssert(((l_index>=bbInt(0))&&(l_index<this->m__0length)),BB_T("Stack index out of range"));
  return this->m__0data->at(l_index);
}

t_mx2_FuncValue* t_std_collections_Stack_1Tt_mx2_FuncValue_2::m_Top(){
  bbDebugAssert(bbBool(this->m__0length),BB_T("Stack is empty"));
  return this->m__0data->at((this->m__0length-1));
}

bbArray<bbGCVar<t_mx2_FuncValue>>* t_std_collections_Stack_1Tt_mx2_FuncValue_2::m_ToArray(){
  return this->m__0data->slice(bbInt(0),this->m__0length);
}

void t_std_collections_Stack_1Tt_mx2_FuncValue_2::m_Swap(bbInt l_index1,bbInt l_index2){
  struct f0_t : public bbGCFrame{
    t_mx2_FuncValue* l_t{};
    void gcMark(){
      bbGCMarkPtr(l_t);
    }
  }f0{};
  bbDebugAssert(((((l_index1>=bbInt(0))&&(l_index1<this->m__0length))&&(l_index2>=bbInt(0)))&&(l_index2<this->m__0length)),BB_T("Stack index out of range"));
  f0.l_t=this->m__0data->at(l_index1);
  this->m__0data->at(l_index1)=this->m__0data->at(l_index2);
  this->m__0data->at(l_index2)=f0.l_t;
}

void t_std_collections_Stack_1Tt_mx2_FuncValue_2::m_Sort(bbFunction<bbInt(t_mx2_FuncValue*,t_mx2_FuncValue*)> l_compareFunc,bbInt l_lo,bbInt l_hi){
  if((l_hi<=l_lo)){
    return;
  }
  if(((l_lo+1)==l_hi)){
    if((l_compareFunc(this->m__0data->at(l_hi),this->m__0data->at(l_lo))<bbInt(0))){
      this->m_Swap(l_hi,l_lo);
    }
    return;
  }
  bbInt l_i=((l_lo+l_hi)/2);
  if((l_compareFunc(this->m__0data->at(l_i),this->m__0data->at(l_lo))<bbInt(0))){
    this->m_Swap(l_i,l_lo);
  }
  if((l_compareFunc(this->m__0data->at(l_hi),this->m__0data->at(l_i))<bbInt(0))){
    this->m_Swap(l_hi,l_i);
    if((l_compareFunc(this->m__0data->at(l_i),this->m__0data->at(l_lo))<bbInt(0))){
      this->m_Swap(l_i,l_lo);
    }
  }
  bbInt l_x=(l_lo+1);
  bbInt l_y=(l_hi-1);
  do{
    struct f1_t : public bbGCFrame{
      t_mx2_FuncValue* l_p{};
      void gcMark(){
        bbGCMarkPtr(l_p);
      }
    }f1{};
    f1.l_p=this->m__0data->at(l_i);
    while((l_compareFunc(this->m__0data->at(l_x),f1.l_p)<bbInt(0))){
      l_x+=1;
    }
    while((l_compareFunc(f1.l_p,this->m__0data->at(l_y))<bbInt(0))){
      l_y-=1;
    }
    if((l_x>l_y)){
      break;
    }
    if((l_x<l_y)){
      this->m_Swap(l_x,l_y);
      if((l_i==l_x)){
        l_i=l_y;
      }else if((l_i==l_y)){
        l_i=l_x;
      }
    }
    l_x+=1;
    l_y-=1;
  }while(!((l_x>l_y)));
  this->m_Sort(l_compareFunc,l_lo,l_y);
  this->m_Sort(l_compareFunc,l_x,l_hi);
}

void t_std_collections_Stack_1Tt_mx2_FuncValue_2::m_Sort(bbFunction<bbInt(t_mx2_FuncValue*,t_mx2_FuncValue*)> l_compareFunc){
  this->m_Sort(l_compareFunc,bbInt(0),(this->m__0length-1));
}

void t_std_collections_Stack_1Tt_mx2_FuncValue_2::m_Sort(bbBool l_ascending){
  if(l_ascending){
    struct lambda0 : public bbFunction<bbInt(t_mx2_FuncValue*,t_mx2_FuncValue*)>::Rep{
      t_std_collections_Stack_1Tt_mx2_FuncValue_2* l_self;
      lambda0(t_std_collections_Stack_1Tt_mx2_FuncValue_2* l_self):l_self(l_self){
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
      t_std_collections_Stack_1Tt_mx2_FuncValue_2* l_self;
      lambda1(t_std_collections_Stack_1Tt_mx2_FuncValue_2* l_self):l_self(l_self){
      }
      bbInt invoke(t_mx2_FuncValue* l_x,t_mx2_FuncValue* l_y){
        return bbCompare(l_y,l_x);
      }
      void gcMark(){
        bbGCMarkPtr(l_self);
      }
    };
    this->m_Sort(bbFunction<bbInt(t_mx2_FuncValue*,t_mx2_FuncValue*)>(new lambda1(this)));
  }
}

t_std_collections_Stack_1Tt_mx2_FuncValue_2* t_std_collections_Stack_1Tt_mx2_FuncValue_2::m_Slice(bbInt l_index1,bbInt l_index2){
  struct f0_t : public bbGCFrame{
    bbArray<bbGCVar<t_mx2_FuncValue>>* t0{};
    void gcMark(){
      bbGCMarkPtr(t0);
    }
  }f0{};
  if((l_index1<bbInt(0))){
    l_index1=g_monkey_math_Max_1i((l_index1+this->m__0length),bbInt(0));
  }else if((l_index1>this->m__0length)){
    l_index1=this->m__0length;
  }
  if((l_index2<bbInt(0))){
    l_index2=g_monkey_math_Max_1i((l_index2+this->m__0length),l_index1);
  }else if((l_index2>this->m__0length)){
    l_index2=this->m__0length;
  }else if((l_index2<l_index1)){
    l_index2=l_index1;
  }
  return bbGCNew<t_std_collections_Stack_1Tt_mx2_FuncValue_2>(f0.t0=this->m__0data->slice(l_index1,l_index2));
}

t_std_collections_Stack_1Tt_mx2_FuncValue_2* t_std_collections_Stack_1Tt_mx2_FuncValue_2::m_Slice(bbInt l_index){
  return this->m_Slice(l_index,this->m__0length);
}

void t_std_collections_Stack_1Tt_mx2_FuncValue_2::m_Set(bbInt l_index,t_mx2_FuncValue* l_value){
  bbDebugAssert(((l_index>=bbInt(0))&&(l_index<this->m__0length)),BB_T("Stack index out of range"));
  this->m__0data->at(l_index)=l_value;
}

void t_std_collections_Stack_1Tt_mx2_FuncValue_2::m_Resize(bbInt l_length){
  bbDebugAssert((l_length>=bbInt(0)),BB_T("Debug assert failed"));
  {
    bbInt l_i=l_length;
    for(;(l_i<this->m__0length);l_i+=1){
      this->m__0data->at(l_i)=((t_mx2_FuncValue*)0);
    }
  }
  this->m_Reserve(l_length);
  this->m__0length=l_length;
  this->m__0seq+=1;
}

void t_std_collections_Stack_1Tt_mx2_FuncValue_2::m_Reserve(bbInt l_capacity){
  struct f0_t : public bbGCFrame{
    bbArray<bbGCVar<t_mx2_FuncValue>>* l_data{};
    void gcMark(){
      bbGCMarkPtr(l_data);
    }
  }f0{};
  bbDebugAssert((l_capacity>=bbInt(0)),BB_T("Debug assert failed"));
  if((this->m__0data->length()>=l_capacity)){
    return;
  }
  l_capacity=g_monkey_math_Max_1i(((this->m__0length*2)+this->m__0length),l_capacity);
  f0.l_data=bbArray<bbGCVar<t_mx2_FuncValue>>::create(l_capacity);
  this->m__0data->copyTo(f0.l_data,bbInt(0),bbInt(0),this->m__0length);
  this->m__0data=f0.l_data;
}

bbBool t_std_collections_Stack_1Tt_mx2_FuncValue_2::m_RemoveLast(t_mx2_FuncValue* l_value,bbInt l_start){
  bbInt l_i=this->m_FindLastIndex(l_value,l_start);
  if((l_i==-1)){
    return false;
  }
  this->m_Erase(l_i);
  return true;
}

bbInt t_std_collections_Stack_1Tt_mx2_FuncValue_2::m_RemoveEach(t_mx2_FuncValue* l_value){
  bbInt l_put=bbInt(0);
  bbInt l_n=bbInt(0);
  {
    bbInt l_get=bbInt(0);
    for(;(l_get<this->m__0length);l_get+=1){
      if((this->m__0data->at(l_get)==l_value)){
        l_n+=1;
        continue;
      }
      this->m__0data->at(l_put)=this->m__0data->at(l_get);
      l_put+=1;
    }
  }
  this->m_Resize(l_put);
  return l_n;
}

bbBool t_std_collections_Stack_1Tt_mx2_FuncValue_2::m_Remove(t_mx2_FuncValue* l_value,bbInt l_start){
  bbInt l_i=this->m_FindIndex(l_value,l_start);
  if((l_i==-1)){
    return false;
  }
  this->m_Erase(l_i);
  return true;
}

void t_std_collections_Stack_1Tt_mx2_FuncValue_2::m_Push(t_mx2_FuncValue* l_value){
  this->m_Add(l_value);
}

t_mx2_FuncValue* t_std_collections_Stack_1Tt_mx2_FuncValue_2::m_Pop(){
  struct f0_t : public bbGCFrame{
    t_mx2_FuncValue* l_value{};
    void gcMark(){
      bbGCMarkPtr(l_value);
    }
  }f0{};
  bbDebugAssert(bbBool(this->m__0length),BB_T("Stack is empty"));
  this->m__0length-=1;
  this->m__0seq+=1;
  f0.l_value=this->m__0data->at(this->m__0length);
  this->m__0data->at(this->m__0length)=((t_mx2_FuncValue*)0);
  return f0.l_value;
}

bbInt t_std_collections_Stack_1Tt_mx2_FuncValue_2::m_Length(){
  return this->m__0length;
}

void t_std_collections_Stack_1Tt_mx2_FuncValue_2::m_Insert(bbInt l_index,t_mx2_FuncValue* l_value){
  bbDebugAssert(((l_index>=bbInt(0))&&(l_index<=this->m__0length)),BB_T("Debug assert failed"));
  this->m_Reserve((this->m__0length+1));
  this->m__0data->copyTo(this->m__0data,l_index,(l_index+1),(this->m__0length-l_index));
  this->m__0data->at(l_index)=l_value;
  this->m__0length+=1;
  this->m__0seq+=1;
}

t_mx2_FuncValue* t_std_collections_Stack_1Tt_mx2_FuncValue_2::m_Get(bbInt l_index){
  bbDebugAssert(((l_index>=bbInt(0))&&(l_index<this->m__0length)),BB_T("Stack index out of range"));
  return this->m__0data->at(l_index);
}

bbInt t_std_collections_Stack_1Tt_mx2_FuncValue_2::m_FindLastIndex(t_mx2_FuncValue* l_value,bbInt l_start){
  bbDebugAssert(((l_start>=bbInt(0))&&(l_start<=this->m__0length)),BB_T("Debug assert failed"));
  bbInt l_i=this->m__0length;
  while((l_i>l_start)){
    l_i-=1;
    if((this->m__0data->at(l_i)==l_value)){
      return l_i;
    }
  }
  return -1;
}

bbInt t_std_collections_Stack_1Tt_mx2_FuncValue_2::m_FindIndex(t_mx2_FuncValue* l_value,bbInt l_start){
  bbDebugAssert(((l_start>=bbInt(0))&&(l_start<=this->m__0length)),BB_T("Debug assert failed"));
  bbInt l_i=l_start;
  while((l_i<this->m__0length)){
    if((this->m__0data->at(l_i)==l_value)){
      return l_i;
    }
    l_i+=1;
  }
  return -1;
}

void t_std_collections_Stack_1Tt_mx2_FuncValue_2::m_Erase(bbInt l_index1,bbInt l_index2){
  bbDebugAssert((((((l_index1>=bbInt(0))&&(l_index1<=this->m__0length))&&(l_index2>=bbInt(0)))&&(l_index2<=this->m__0length))&&(l_index1<=l_index2)),BB_T("Debug assert failed"));
  if((l_index1==this->m__0length)){
    return;
  }
  this->m__0data->copyTo(this->m__0data,l_index2,l_index1,(this->m__0length-l_index2));
  this->m_Resize(((this->m__0length-l_index2)+l_index1));
}

void t_std_collections_Stack_1Tt_mx2_FuncValue_2::m_Erase(bbInt l_index){
  bbDebugAssert(((l_index>=bbInt(0))&&(l_index<=this->m__0length)),BB_T("Debug assert failed"));
  if((l_index==this->m__0length)){
    return;
  }
  this->m__0data->copyTo(this->m__0data,(l_index+1),l_index,((this->m__0length-l_index)-1));
  this->m_Resize((this->m__0length-1));
}

bbBool t_std_collections_Stack_1Tt_mx2_FuncValue_2::m_Empty(){
  return (this->m__0length==bbInt(0));
}

bbArray<bbGCVar<t_mx2_FuncValue>>* t_std_collections_Stack_1Tt_mx2_FuncValue_2::m_Data(){
  return this->m__0data;
}

bbBool t_std_collections_Stack_1Tt_mx2_FuncValue_2::m_Contains(t_mx2_FuncValue* l_value){
  return (this->m_FindIndex(l_value,bbInt(0))!=-1);
}

void t_std_collections_Stack_1Tt_mx2_FuncValue_2::m_Clear(){
  this->m_Resize(bbInt(0));
}

bbInt t_std_collections_Stack_1Tt_mx2_FuncValue_2::m_Capacity(){
  return this->m__0data->length();
}

t_std_collections_Stack_1Tt_mx2_FuncValue_2_BackwardsIterator t_std_collections_Stack_1Tt_mx2_FuncValue_2::m_Backwards(){
  return t_std_collections_Stack_1Tt_mx2_FuncValue_2_BackwardsIterator(this,(this->m__0length-1));
}

t_std_collections_Stack_1Tt_mx2_FuncValue_2_Iterator t_std_collections_Stack_1Tt_mx2_FuncValue_2::m_All(){
  return t_std_collections_Stack_1Tt_mx2_FuncValue_2_Iterator(this,bbInt(0));
}

void t_std_collections_Stack_1Tt_mx2_FuncValue_2::m_AddAll(bbArray<bbGCVar<t_mx2_FuncValue>>* l_values){
  this->m_Reserve((this->m__0length+l_values->length()));
  l_values->copyTo(this->m__0data,bbInt(0),this->m__0length,l_values->length());
  this->m_Resize((this->m__0length+l_values->length()));
}

void t_std_collections_Stack_1Tt_mx2_FuncValue_2::m_Add(t_mx2_FuncValue* l_value){
  this->m_Reserve((this->m__0length+1));
  this->m__0data->at(this->m__0length)=l_value;
  this->m__0length+=1;
  this->m__0seq+=1;
}

t_std_collections_Stack_1Tt_mx2_Module_2_Iterator::t_std_collections_Stack_1Tt_mx2_Module_2_Iterator(t_std_collections_Stack_1Tt_mx2_Module_2* l_stack,bbInt l_index){
  (*this).m__0stack=l_stack;
  (*this).m__0index=l_index;
  (*this).m__0seq=l_stack->m__0seq;
}

void t_std_collections_Stack_1Tt_mx2_Module_2_Iterator::m_Insert(t_mx2_Module* l_value){
  (*this).m_AssertSeq();
  (*this).m__0stack->m_Insert((*this).m__0index,l_value);
  (*this).m__0seq=(*this).m__0stack->m__0seq;
}

void t_std_collections_Stack_1Tt_mx2_Module_2_Iterator::m_Erase(){
  (*this).m_AssertSeq();
  (*this).m__0stack->m_Erase((*this).m__0index);
  (*this).m__0seq=(*this).m__0stack->m__0seq;
}

void t_std_collections_Stack_1Tt_mx2_Module_2_Iterator::m_Current(t_mx2_Module* l_current){
  (*this).m_AssertCurrent();
  (*this).m__0stack->m__0data->at((*this).m__0index)=l_current;
}

t_mx2_Module* t_std_collections_Stack_1Tt_mx2_Module_2_Iterator::m_Current(){
  (*this).m_AssertCurrent();
  return (*this).m__0stack->m__0data->at((*this).m__0index);
}

void t_std_collections_Stack_1Tt_mx2_Module_2_Iterator::m_Bump(){
  (*this).m_AssertCurrent();
  (*this).m__0index+=1;
}

bbBool t_std_collections_Stack_1Tt_mx2_Module_2_Iterator::m_AtEnd(){
  (*this).m_AssertSeq();
  return ((*this).m__0index==(*this).m__0stack->m__0length);
}

void t_std_collections_Stack_1Tt_mx2_Module_2_Iterator::m_AssertSeq(){
  bbDebugAssert(((*this).m__0seq==(*this).m__0stack->m__0seq),BB_T("Concurrent list modification"));
}

void t_std_collections_Stack_1Tt_mx2_Module_2_Iterator::m_AssertCurrent(){
  bbDebugAssert(!(*this).m_AtEnd(),BB_T("Invalid list iterator"));
}

int bbCompare(const t_std_collections_Stack_1Tt_mx2_Module_2_Iterator&x,const t_std_collections_Stack_1Tt_mx2_Module_2_Iterator&y){
  if(int t=bbCompare(x.m__0stack,y.m__0stack)) return t;
  if(int t=bbCompare(x.m__0index,y.m__0index)) return t;
  if(int t=bbCompare(x.m__0seq,y.m__0seq)) return t;
  return 0;
}

void bbGCMark(const t_std_collections_Stack_1Tt_mx2_Module_2_Iterator&t){
  bbGCMark(t.m__0stack);
}

t_std_collections_Stack_1Tt_mx2_Module_2_BackwardsIterator::t_std_collections_Stack_1Tt_mx2_Module_2_BackwardsIterator(t_std_collections_Stack_1Tt_mx2_Module_2* l_stack,bbInt l_index){
  (*this).m__0stack=l_stack;
  (*this).m__0index=l_index;
  (*this).m__0seq=l_stack->m__0seq;
}

void t_std_collections_Stack_1Tt_mx2_Module_2_BackwardsIterator::m_Insert(t_mx2_Module* l_value){
  (*this).m_AssertSeq();
  (*this).m__0index+=1;
  (*this).m__0stack->m_Insert((*this).m__0index,l_value);
  (*this).m__0seq=(*this).m__0stack->m__0seq;
}

void t_std_collections_Stack_1Tt_mx2_Module_2_BackwardsIterator::m_Erase(){
  (*this).m_AssertCurrent();
  (*this).m__0index-=1;
  (*this).m__0stack->m_Erase(((*this).m__0index+1));
  (*this).m__0seq=(*this).m__0stack->m__0seq;
}

void t_std_collections_Stack_1Tt_mx2_Module_2_BackwardsIterator::m_Current(t_mx2_Module* l_current){
  (*this).m_AssertCurrent();
  (*this).m__0stack->m__0data->at((*this).m__0index)=l_current;
}

t_mx2_Module* t_std_collections_Stack_1Tt_mx2_Module_2_BackwardsIterator::m_Current(){
  (*this).m_AssertCurrent();
  return (*this).m__0stack->m__0data->at((*this).m__0index);
}

void t_std_collections_Stack_1Tt_mx2_Module_2_BackwardsIterator::m_Bump(){
  (*this).m_AssertCurrent();
  (*this).m__0index-=1;
}

bbBool t_std_collections_Stack_1Tt_mx2_Module_2_BackwardsIterator::m_AtEnd(){
  (*this).m_AssertSeq();
  return ((*this).m__0index==-1);
}

void t_std_collections_Stack_1Tt_mx2_Module_2_BackwardsIterator::m_AssertSeq(){
  bbDebugAssert(((*this).m__0seq==(*this).m__0stack->m__0seq),BB_T("Concurrent list modification"));
}

void t_std_collections_Stack_1Tt_mx2_Module_2_BackwardsIterator::m_AssertCurrent(){
  bbDebugAssert(!(*this).m_AtEnd(),BB_T("Invalid list iterator"));
}

int bbCompare(const t_std_collections_Stack_1Tt_mx2_Module_2_BackwardsIterator&x,const t_std_collections_Stack_1Tt_mx2_Module_2_BackwardsIterator&y){
  if(int t=bbCompare(x.m__0stack,y.m__0stack)) return t;
  if(int t=bbCompare(x.m__0index,y.m__0index)) return t;
  if(int t=bbCompare(x.m__0seq,y.m__0seq)) return t;
  return 0;
}

void bbGCMark(const t_std_collections_Stack_1Tt_mx2_Module_2_BackwardsIterator&t){
  bbGCMark(t.m__0stack);
}

void t_std_collections_Stack_1Tt_mx2_Module_2::gcMark(){
  bbGCMark(m__0data);
}

t_std_collections_Stack_1Tt_mx2_Module_2::t_std_collections_Stack_1Tt_mx2_Module_2(t_std_collections_List_1Tt_mx2_Module_2* l_values){
  g_std_collections_Stack_1Tt_mx2_Module_2_AddAll_1Tt_std_collections_List_1Tt_mx2_Module_2_2(this,l_values);
}

t_std_collections_Stack_1Tt_mx2_Module_2::t_std_collections_Stack_1Tt_mx2_Module_2(t_std_collections_Stack_1Tt_mx2_Module_2* l_values){
  struct f0_t : public bbGCFrame{
    bbArray<bbGCVar<t_mx2_Module>>* t0{};
    void gcMark(){
      bbGCMarkPtr(t0);
    }
  }f0{};
  this->m__0length=l_values->m_Length();
  this->m__0data=bbArray<bbGCVar<t_mx2_Module>>::create(this->m__0length);
  (f0.t0=l_values->m_Data())->copyTo(this->m__0data,bbInt(0),bbInt(0),this->m__0length);
}

t_std_collections_Stack_1Tt_mx2_Module_2::t_std_collections_Stack_1Tt_mx2_Module_2(bbArray<bbGCVar<t_mx2_Module>>* l_values){
  this->m_AddAll(l_values);
}

t_std_collections_Stack_1Tt_mx2_Module_2::t_std_collections_Stack_1Tt_mx2_Module_2(bbInt l_length){
  this->m__0length=l_length;
  this->m__0data=bbArray<bbGCVar<t_mx2_Module>>::create(this->m__0length);
}

t_std_collections_Stack_1Tt_mx2_Module_2::t_std_collections_Stack_1Tt_mx2_Module_2(){
  this->m__0data=bbArray<bbGCVar<t_mx2_Module>>::create(10);
}

void t_std_collections_Stack_1Tt_mx2_Module_2::m__idxeq(bbInt l_index,t_mx2_Module* l_value){
  bbDebugAssert(((l_index>=bbInt(0))&&(l_index<this->m__0length)),BB_T("Stack index out of range"));
  this->m__0data->at(l_index)=l_value;
}

t_mx2_Module* t_std_collections_Stack_1Tt_mx2_Module_2::m__idx(bbInt l_index){
  bbDebugAssert(((l_index>=bbInt(0))&&(l_index<this->m__0length)),BB_T("Stack index out of range"));
  return this->m__0data->at(l_index);
}

t_mx2_Module* t_std_collections_Stack_1Tt_mx2_Module_2::m_Top(){
  bbDebugAssert(bbBool(this->m__0length),BB_T("Stack is empty"));
  return this->m__0data->at((this->m__0length-1));
}

bbArray<bbGCVar<t_mx2_Module>>* t_std_collections_Stack_1Tt_mx2_Module_2::m_ToArray(){
  return this->m__0data->slice(bbInt(0),this->m__0length);
}

void t_std_collections_Stack_1Tt_mx2_Module_2::m_Swap(bbInt l_index1,bbInt l_index2){
  struct f0_t : public bbGCFrame{
    t_mx2_Module* l_t{};
    void gcMark(){
      bbGCMarkPtr(l_t);
    }
  }f0{};
  bbDebugAssert(((((l_index1>=bbInt(0))&&(l_index1<this->m__0length))&&(l_index2>=bbInt(0)))&&(l_index2<this->m__0length)),BB_T("Stack index out of range"));
  f0.l_t=this->m__0data->at(l_index1);
  this->m__0data->at(l_index1)=this->m__0data->at(l_index2);
  this->m__0data->at(l_index2)=f0.l_t;
}

void t_std_collections_Stack_1Tt_mx2_Module_2::m_Sort(bbFunction<bbInt(t_mx2_Module*,t_mx2_Module*)> l_compareFunc,bbInt l_lo,bbInt l_hi){
  if((l_hi<=l_lo)){
    return;
  }
  if(((l_lo+1)==l_hi)){
    if((l_compareFunc(this->m__0data->at(l_hi),this->m__0data->at(l_lo))<bbInt(0))){
      this->m_Swap(l_hi,l_lo);
    }
    return;
  }
  bbInt l_i=((l_lo+l_hi)/2);
  if((l_compareFunc(this->m__0data->at(l_i),this->m__0data->at(l_lo))<bbInt(0))){
    this->m_Swap(l_i,l_lo);
  }
  if((l_compareFunc(this->m__0data->at(l_hi),this->m__0data->at(l_i))<bbInt(0))){
    this->m_Swap(l_hi,l_i);
    if((l_compareFunc(this->m__0data->at(l_i),this->m__0data->at(l_lo))<bbInt(0))){
      this->m_Swap(l_i,l_lo);
    }
  }
  bbInt l_x=(l_lo+1);
  bbInt l_y=(l_hi-1);
  do{
    struct f1_t : public bbGCFrame{
      t_mx2_Module* l_p{};
      void gcMark(){
        bbGCMarkPtr(l_p);
      }
    }f1{};
    f1.l_p=this->m__0data->at(l_i);
    while((l_compareFunc(this->m__0data->at(l_x),f1.l_p)<bbInt(0))){
      l_x+=1;
    }
    while((l_compareFunc(f1.l_p,this->m__0data->at(l_y))<bbInt(0))){
      l_y-=1;
    }
    if((l_x>l_y)){
      break;
    }
    if((l_x<l_y)){
      this->m_Swap(l_x,l_y);
      if((l_i==l_x)){
        l_i=l_y;
      }else if((l_i==l_y)){
        l_i=l_x;
      }
    }
    l_x+=1;
    l_y-=1;
  }while(!((l_x>l_y)));
  this->m_Sort(l_compareFunc,l_lo,l_y);
  this->m_Sort(l_compareFunc,l_x,l_hi);
}

void t_std_collections_Stack_1Tt_mx2_Module_2::m_Sort(bbFunction<bbInt(t_mx2_Module*,t_mx2_Module*)> l_compareFunc){
  this->m_Sort(l_compareFunc,bbInt(0),(this->m__0length-1));
}

void t_std_collections_Stack_1Tt_mx2_Module_2::m_Sort(bbBool l_ascending){
  if(l_ascending){
    struct lambda2 : public bbFunction<bbInt(t_mx2_Module*,t_mx2_Module*)>::Rep{
      t_std_collections_Stack_1Tt_mx2_Module_2* l_self;
      lambda2(t_std_collections_Stack_1Tt_mx2_Module_2* l_self):l_self(l_self){
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
      t_std_collections_Stack_1Tt_mx2_Module_2* l_self;
      lambda3(t_std_collections_Stack_1Tt_mx2_Module_2* l_self):l_self(l_self){
      }
      bbInt invoke(t_mx2_Module* l_x,t_mx2_Module* l_y){
        return bbCompare(l_y,l_x);
      }
      void gcMark(){
        bbGCMarkPtr(l_self);
      }
    };
    this->m_Sort(bbFunction<bbInt(t_mx2_Module*,t_mx2_Module*)>(new lambda3(this)));
  }
}

t_std_collections_Stack_1Tt_mx2_Module_2* t_std_collections_Stack_1Tt_mx2_Module_2::m_Slice(bbInt l_index1,bbInt l_index2){
  struct f0_t : public bbGCFrame{
    bbArray<bbGCVar<t_mx2_Module>>* t0{};
    void gcMark(){
      bbGCMarkPtr(t0);
    }
  }f0{};
  if((l_index1<bbInt(0))){
    l_index1=g_monkey_math_Max_1i((l_index1+this->m__0length),bbInt(0));
  }else if((l_index1>this->m__0length)){
    l_index1=this->m__0length;
  }
  if((l_index2<bbInt(0))){
    l_index2=g_monkey_math_Max_1i((l_index2+this->m__0length),l_index1);
  }else if((l_index2>this->m__0length)){
    l_index2=this->m__0length;
  }else if((l_index2<l_index1)){
    l_index2=l_index1;
  }
  return bbGCNew<t_std_collections_Stack_1Tt_mx2_Module_2>(f0.t0=this->m__0data->slice(l_index1,l_index2));
}

t_std_collections_Stack_1Tt_mx2_Module_2* t_std_collections_Stack_1Tt_mx2_Module_2::m_Slice(bbInt l_index){
  return this->m_Slice(l_index,this->m__0length);
}

void t_std_collections_Stack_1Tt_mx2_Module_2::m_Set(bbInt l_index,t_mx2_Module* l_value){
  bbDebugAssert(((l_index>=bbInt(0))&&(l_index<this->m__0length)),BB_T("Stack index out of range"));
  this->m__0data->at(l_index)=l_value;
}

void t_std_collections_Stack_1Tt_mx2_Module_2::m_Resize(bbInt l_length){
  bbDebugAssert((l_length>=bbInt(0)),BB_T("Debug assert failed"));
  {
    bbInt l_i=l_length;
    for(;(l_i<this->m__0length);l_i+=1){
      this->m__0data->at(l_i)=((t_mx2_Module*)0);
    }
  }
  this->m_Reserve(l_length);
  this->m__0length=l_length;
  this->m__0seq+=1;
}

void t_std_collections_Stack_1Tt_mx2_Module_2::m_Reserve(bbInt l_capacity){
  struct f0_t : public bbGCFrame{
    bbArray<bbGCVar<t_mx2_Module>>* l_data{};
    void gcMark(){
      bbGCMarkPtr(l_data);
    }
  }f0{};
  bbDebugAssert((l_capacity>=bbInt(0)),BB_T("Debug assert failed"));
  if((this->m__0data->length()>=l_capacity)){
    return;
  }
  l_capacity=g_monkey_math_Max_1i(((this->m__0length*2)+this->m__0length),l_capacity);
  f0.l_data=bbArray<bbGCVar<t_mx2_Module>>::create(l_capacity);
  this->m__0data->copyTo(f0.l_data,bbInt(0),bbInt(0),this->m__0length);
  this->m__0data=f0.l_data;
}

bbBool t_std_collections_Stack_1Tt_mx2_Module_2::m_RemoveLast(t_mx2_Module* l_value,bbInt l_start){
  bbInt l_i=this->m_FindLastIndex(l_value,l_start);
  if((l_i==-1)){
    return false;
  }
  this->m_Erase(l_i);
  return true;
}

bbInt t_std_collections_Stack_1Tt_mx2_Module_2::m_RemoveEach(t_mx2_Module* l_value){
  bbInt l_put=bbInt(0);
  bbInt l_n=bbInt(0);
  {
    bbInt l_get=bbInt(0);
    for(;(l_get<this->m__0length);l_get+=1){
      if((this->m__0data->at(l_get)==l_value)){
        l_n+=1;
        continue;
      }
      this->m__0data->at(l_put)=this->m__0data->at(l_get);
      l_put+=1;
    }
  }
  this->m_Resize(l_put);
  return l_n;
}

bbBool t_std_collections_Stack_1Tt_mx2_Module_2::m_Remove(t_mx2_Module* l_value,bbInt l_start){
  bbInt l_i=this->m_FindIndex(l_value,l_start);
  if((l_i==-1)){
    return false;
  }
  this->m_Erase(l_i);
  return true;
}

void t_std_collections_Stack_1Tt_mx2_Module_2::m_Push(t_mx2_Module* l_value){
  this->m_Add(l_value);
}

t_mx2_Module* t_std_collections_Stack_1Tt_mx2_Module_2::m_Pop(){
  struct f0_t : public bbGCFrame{
    t_mx2_Module* l_value{};
    void gcMark(){
      bbGCMarkPtr(l_value);
    }
  }f0{};
  bbDebugAssert(bbBool(this->m__0length),BB_T("Stack is empty"));
  this->m__0length-=1;
  this->m__0seq+=1;
  f0.l_value=this->m__0data->at(this->m__0length);
  this->m__0data->at(this->m__0length)=((t_mx2_Module*)0);
  return f0.l_value;
}

bbInt t_std_collections_Stack_1Tt_mx2_Module_2::m_Length(){
  return this->m__0length;
}

void t_std_collections_Stack_1Tt_mx2_Module_2::m_Insert(bbInt l_index,t_mx2_Module* l_value){
  bbDebugAssert(((l_index>=bbInt(0))&&(l_index<=this->m__0length)),BB_T("Debug assert failed"));
  this->m_Reserve((this->m__0length+1));
  this->m__0data->copyTo(this->m__0data,l_index,(l_index+1),(this->m__0length-l_index));
  this->m__0data->at(l_index)=l_value;
  this->m__0length+=1;
  this->m__0seq+=1;
}

t_mx2_Module* t_std_collections_Stack_1Tt_mx2_Module_2::m_Get(bbInt l_index){
  bbDebugAssert(((l_index>=bbInt(0))&&(l_index<this->m__0length)),BB_T("Stack index out of range"));
  return this->m__0data->at(l_index);
}

bbInt t_std_collections_Stack_1Tt_mx2_Module_2::m_FindLastIndex(t_mx2_Module* l_value,bbInt l_start){
  bbDebugAssert(((l_start>=bbInt(0))&&(l_start<=this->m__0length)),BB_T("Debug assert failed"));
  bbInt l_i=this->m__0length;
  while((l_i>l_start)){
    l_i-=1;
    if((this->m__0data->at(l_i)==l_value)){
      return l_i;
    }
  }
  return -1;
}

bbInt t_std_collections_Stack_1Tt_mx2_Module_2::m_FindIndex(t_mx2_Module* l_value,bbInt l_start){
  bbDebugAssert(((l_start>=bbInt(0))&&(l_start<=this->m__0length)),BB_T("Debug assert failed"));
  bbInt l_i=l_start;
  while((l_i<this->m__0length)){
    if((this->m__0data->at(l_i)==l_value)){
      return l_i;
    }
    l_i+=1;
  }
  return -1;
}

void t_std_collections_Stack_1Tt_mx2_Module_2::m_Erase(bbInt l_index1,bbInt l_index2){
  bbDebugAssert((((((l_index1>=bbInt(0))&&(l_index1<=this->m__0length))&&(l_index2>=bbInt(0)))&&(l_index2<=this->m__0length))&&(l_index1<=l_index2)),BB_T("Debug assert failed"));
  if((l_index1==this->m__0length)){
    return;
  }
  this->m__0data->copyTo(this->m__0data,l_index2,l_index1,(this->m__0length-l_index2));
  this->m_Resize(((this->m__0length-l_index2)+l_index1));
}

void t_std_collections_Stack_1Tt_mx2_Module_2::m_Erase(bbInt l_index){
  bbDebugAssert(((l_index>=bbInt(0))&&(l_index<=this->m__0length)),BB_T("Debug assert failed"));
  if((l_index==this->m__0length)){
    return;
  }
  this->m__0data->copyTo(this->m__0data,(l_index+1),l_index,((this->m__0length-l_index)-1));
  this->m_Resize((this->m__0length-1));
}

bbBool t_std_collections_Stack_1Tt_mx2_Module_2::m_Empty(){
  return (this->m__0length==bbInt(0));
}

bbArray<bbGCVar<t_mx2_Module>>* t_std_collections_Stack_1Tt_mx2_Module_2::m_Data(){
  return this->m__0data;
}

bbBool t_std_collections_Stack_1Tt_mx2_Module_2::m_Contains(t_mx2_Module* l_value){
  return (this->m_FindIndex(l_value,bbInt(0))!=-1);
}

void t_std_collections_Stack_1Tt_mx2_Module_2::m_Clear(){
  this->m_Resize(bbInt(0));
}

bbInt t_std_collections_Stack_1Tt_mx2_Module_2::m_Capacity(){
  return this->m__0data->length();
}

t_std_collections_Stack_1Tt_mx2_Module_2_BackwardsIterator t_std_collections_Stack_1Tt_mx2_Module_2::m_Backwards(){
  return t_std_collections_Stack_1Tt_mx2_Module_2_BackwardsIterator(this,(this->m__0length-1));
}

t_std_collections_Stack_1Tt_mx2_Module_2_Iterator t_std_collections_Stack_1Tt_mx2_Module_2::m_All(){
  return t_std_collections_Stack_1Tt_mx2_Module_2_Iterator(this,bbInt(0));
}

void t_std_collections_Stack_1Tt_mx2_Module_2::m_AddAll(bbArray<bbGCVar<t_mx2_Module>>* l_values){
  this->m_Reserve((this->m__0length+l_values->length()));
  l_values->copyTo(this->m__0data,bbInt(0),this->m__0length,l_values->length());
  this->m_Resize((this->m__0length+l_values->length()));
}

void t_std_collections_Stack_1Tt_mx2_Module_2::m_Add(t_mx2_Module* l_value){
  this->m_Reserve((this->m__0length+1));
  this->m__0data->at(this->m__0length)=l_value;
  this->m__0length+=1;
  this->m__0seq+=1;
}

t_std_collections_Stack_1Tt_mx2_ErrorEx_2_Iterator::t_std_collections_Stack_1Tt_mx2_ErrorEx_2_Iterator(t_std_collections_Stack_1Tt_mx2_ErrorEx_2* l_stack,bbInt l_index){
  (*this).m__0stack=l_stack;
  (*this).m__0index=l_index;
  (*this).m__0seq=l_stack->m__0seq;
}

void t_std_collections_Stack_1Tt_mx2_ErrorEx_2_Iterator::m_Insert(t_mx2_ErrorEx* l_value){
  (*this).m_AssertSeq();
  (*this).m__0stack->m_Insert((*this).m__0index,l_value);
  (*this).m__0seq=(*this).m__0stack->m__0seq;
}

void t_std_collections_Stack_1Tt_mx2_ErrorEx_2_Iterator::m_Erase(){
  (*this).m_AssertSeq();
  (*this).m__0stack->m_Erase((*this).m__0index);
  (*this).m__0seq=(*this).m__0stack->m__0seq;
}

void t_std_collections_Stack_1Tt_mx2_ErrorEx_2_Iterator::m_Current(t_mx2_ErrorEx* l_current){
  (*this).m_AssertCurrent();
  (*this).m__0stack->m__0data->at((*this).m__0index)=l_current;
}

t_mx2_ErrorEx* t_std_collections_Stack_1Tt_mx2_ErrorEx_2_Iterator::m_Current(){
  (*this).m_AssertCurrent();
  return (*this).m__0stack->m__0data->at((*this).m__0index);
}

void t_std_collections_Stack_1Tt_mx2_ErrorEx_2_Iterator::m_Bump(){
  (*this).m_AssertCurrent();
  (*this).m__0index+=1;
}

bbBool t_std_collections_Stack_1Tt_mx2_ErrorEx_2_Iterator::m_AtEnd(){
  (*this).m_AssertSeq();
  return ((*this).m__0index==(*this).m__0stack->m__0length);
}

void t_std_collections_Stack_1Tt_mx2_ErrorEx_2_Iterator::m_AssertSeq(){
  bbDebugAssert(((*this).m__0seq==(*this).m__0stack->m__0seq),BB_T("Concurrent list modification"));
}

void t_std_collections_Stack_1Tt_mx2_ErrorEx_2_Iterator::m_AssertCurrent(){
  bbDebugAssert(!(*this).m_AtEnd(),BB_T("Invalid list iterator"));
}

int bbCompare(const t_std_collections_Stack_1Tt_mx2_ErrorEx_2_Iterator&x,const t_std_collections_Stack_1Tt_mx2_ErrorEx_2_Iterator&y){
  if(int t=bbCompare(x.m__0stack,y.m__0stack)) return t;
  if(int t=bbCompare(x.m__0index,y.m__0index)) return t;
  if(int t=bbCompare(x.m__0seq,y.m__0seq)) return t;
  return 0;
}

void bbGCMark(const t_std_collections_Stack_1Tt_mx2_ErrorEx_2_Iterator&t){
  bbGCMark(t.m__0stack);
}

t_std_collections_Stack_1Tt_mx2_ErrorEx_2_BackwardsIterator::t_std_collections_Stack_1Tt_mx2_ErrorEx_2_BackwardsIterator(t_std_collections_Stack_1Tt_mx2_ErrorEx_2* l_stack,bbInt l_index){
  (*this).m__0stack=l_stack;
  (*this).m__0index=l_index;
  (*this).m__0seq=l_stack->m__0seq;
}

void t_std_collections_Stack_1Tt_mx2_ErrorEx_2_BackwardsIterator::m_Insert(t_mx2_ErrorEx* l_value){
  (*this).m_AssertSeq();
  (*this).m__0index+=1;
  (*this).m__0stack->m_Insert((*this).m__0index,l_value);
  (*this).m__0seq=(*this).m__0stack->m__0seq;
}

void t_std_collections_Stack_1Tt_mx2_ErrorEx_2_BackwardsIterator::m_Erase(){
  (*this).m_AssertCurrent();
  (*this).m__0index-=1;
  (*this).m__0stack->m_Erase(((*this).m__0index+1));
  (*this).m__0seq=(*this).m__0stack->m__0seq;
}

void t_std_collections_Stack_1Tt_mx2_ErrorEx_2_BackwardsIterator::m_Current(t_mx2_ErrorEx* l_current){
  (*this).m_AssertCurrent();
  (*this).m__0stack->m__0data->at((*this).m__0index)=l_current;
}

t_mx2_ErrorEx* t_std_collections_Stack_1Tt_mx2_ErrorEx_2_BackwardsIterator::m_Current(){
  (*this).m_AssertCurrent();
  return (*this).m__0stack->m__0data->at((*this).m__0index);
}

void t_std_collections_Stack_1Tt_mx2_ErrorEx_2_BackwardsIterator::m_Bump(){
  (*this).m_AssertCurrent();
  (*this).m__0index-=1;
}

bbBool t_std_collections_Stack_1Tt_mx2_ErrorEx_2_BackwardsIterator::m_AtEnd(){
  (*this).m_AssertSeq();
  return ((*this).m__0index==-1);
}

void t_std_collections_Stack_1Tt_mx2_ErrorEx_2_BackwardsIterator::m_AssertSeq(){
  bbDebugAssert(((*this).m__0seq==(*this).m__0stack->m__0seq),BB_T("Concurrent list modification"));
}

void t_std_collections_Stack_1Tt_mx2_ErrorEx_2_BackwardsIterator::m_AssertCurrent(){
  bbDebugAssert(!(*this).m_AtEnd(),BB_T("Invalid list iterator"));
}

int bbCompare(const t_std_collections_Stack_1Tt_mx2_ErrorEx_2_BackwardsIterator&x,const t_std_collections_Stack_1Tt_mx2_ErrorEx_2_BackwardsIterator&y){
  if(int t=bbCompare(x.m__0stack,y.m__0stack)) return t;
  if(int t=bbCompare(x.m__0index,y.m__0index)) return t;
  if(int t=bbCompare(x.m__0seq,y.m__0seq)) return t;
  return 0;
}

void bbGCMark(const t_std_collections_Stack_1Tt_mx2_ErrorEx_2_BackwardsIterator&t){
  bbGCMark(t.m__0stack);
}

void t_std_collections_Stack_1Tt_mx2_ErrorEx_2::gcMark(){
  bbGCMark(m__0data);
}

t_std_collections_Stack_1Tt_mx2_ErrorEx_2::t_std_collections_Stack_1Tt_mx2_ErrorEx_2(t_std_collections_List_1Tt_mx2_ErrorEx_2* l_values){
  g_std_collections_Stack_1Tt_mx2_ErrorEx_2_AddAll_1Tt_std_collections_List_1Tt_mx2_ErrorEx_2_2(this,l_values);
}

t_std_collections_Stack_1Tt_mx2_ErrorEx_2::t_std_collections_Stack_1Tt_mx2_ErrorEx_2(t_std_collections_Stack_1Tt_mx2_ErrorEx_2* l_values){
  struct f0_t : public bbGCFrame{
    bbArray<bbGCVar<t_mx2_ErrorEx>>* t0{};
    void gcMark(){
      bbGCMarkPtr(t0);
    }
  }f0{};
  this->m__0length=l_values->m_Length();
  this->m__0data=bbArray<bbGCVar<t_mx2_ErrorEx>>::create(this->m__0length);
  (f0.t0=l_values->m_Data())->copyTo(this->m__0data,bbInt(0),bbInt(0),this->m__0length);
}

t_std_collections_Stack_1Tt_mx2_ErrorEx_2::t_std_collections_Stack_1Tt_mx2_ErrorEx_2(bbArray<bbGCVar<t_mx2_ErrorEx>>* l_values){
  this->m_AddAll(l_values);
}

t_std_collections_Stack_1Tt_mx2_ErrorEx_2::t_std_collections_Stack_1Tt_mx2_ErrorEx_2(bbInt l_length){
  this->m__0length=l_length;
  this->m__0data=bbArray<bbGCVar<t_mx2_ErrorEx>>::create(this->m__0length);
}

t_std_collections_Stack_1Tt_mx2_ErrorEx_2::t_std_collections_Stack_1Tt_mx2_ErrorEx_2(){
  this->m__0data=bbArray<bbGCVar<t_mx2_ErrorEx>>::create(10);
}

void t_std_collections_Stack_1Tt_mx2_ErrorEx_2::m__idxeq(bbInt l_index,t_mx2_ErrorEx* l_value){
  bbDebugAssert(((l_index>=bbInt(0))&&(l_index<this->m__0length)),BB_T("Stack index out of range"));
  this->m__0data->at(l_index)=l_value;
}

t_mx2_ErrorEx* t_std_collections_Stack_1Tt_mx2_ErrorEx_2::m__idx(bbInt l_index){
  bbDebugAssert(((l_index>=bbInt(0))&&(l_index<this->m__0length)),BB_T("Stack index out of range"));
  return this->m__0data->at(l_index);
}

t_mx2_ErrorEx* t_std_collections_Stack_1Tt_mx2_ErrorEx_2::m_Top(){
  bbDebugAssert(bbBool(this->m__0length),BB_T("Stack is empty"));
  return this->m__0data->at((this->m__0length-1));
}

bbArray<bbGCVar<t_mx2_ErrorEx>>* t_std_collections_Stack_1Tt_mx2_ErrorEx_2::m_ToArray(){
  return this->m__0data->slice(bbInt(0),this->m__0length);
}

void t_std_collections_Stack_1Tt_mx2_ErrorEx_2::m_Swap(bbInt l_index1,bbInt l_index2){
  struct f0_t : public bbGCFrame{
    t_mx2_ErrorEx* l_t{};
    void gcMark(){
      bbGCMarkPtr(l_t);
    }
  }f0{};
  bbDebugAssert(((((l_index1>=bbInt(0))&&(l_index1<this->m__0length))&&(l_index2>=bbInt(0)))&&(l_index2<this->m__0length)),BB_T("Stack index out of range"));
  f0.l_t=this->m__0data->at(l_index1);
  this->m__0data->at(l_index1)=this->m__0data->at(l_index2);
  this->m__0data->at(l_index2)=f0.l_t;
}

void t_std_collections_Stack_1Tt_mx2_ErrorEx_2::m_Sort(bbFunction<bbInt(t_mx2_ErrorEx*,t_mx2_ErrorEx*)> l_compareFunc,bbInt l_lo,bbInt l_hi){
  if((l_hi<=l_lo)){
    return;
  }
  if(((l_lo+1)==l_hi)){
    if((l_compareFunc(this->m__0data->at(l_hi),this->m__0data->at(l_lo))<bbInt(0))){
      this->m_Swap(l_hi,l_lo);
    }
    return;
  }
  bbInt l_i=((l_lo+l_hi)/2);
  if((l_compareFunc(this->m__0data->at(l_i),this->m__0data->at(l_lo))<bbInt(0))){
    this->m_Swap(l_i,l_lo);
  }
  if((l_compareFunc(this->m__0data->at(l_hi),this->m__0data->at(l_i))<bbInt(0))){
    this->m_Swap(l_hi,l_i);
    if((l_compareFunc(this->m__0data->at(l_i),this->m__0data->at(l_lo))<bbInt(0))){
      this->m_Swap(l_i,l_lo);
    }
  }
  bbInt l_x=(l_lo+1);
  bbInt l_y=(l_hi-1);
  do{
    struct f1_t : public bbGCFrame{
      t_mx2_ErrorEx* l_p{};
      void gcMark(){
        bbGCMarkPtr(l_p);
      }
    }f1{};
    f1.l_p=this->m__0data->at(l_i);
    while((l_compareFunc(this->m__0data->at(l_x),f1.l_p)<bbInt(0))){
      l_x+=1;
    }
    while((l_compareFunc(f1.l_p,this->m__0data->at(l_y))<bbInt(0))){
      l_y-=1;
    }
    if((l_x>l_y)){
      break;
    }
    if((l_x<l_y)){
      this->m_Swap(l_x,l_y);
      if((l_i==l_x)){
        l_i=l_y;
      }else if((l_i==l_y)){
        l_i=l_x;
      }
    }
    l_x+=1;
    l_y-=1;
  }while(!((l_x>l_y)));
  this->m_Sort(l_compareFunc,l_lo,l_y);
  this->m_Sort(l_compareFunc,l_x,l_hi);
}

void t_std_collections_Stack_1Tt_mx2_ErrorEx_2::m_Sort(bbFunction<bbInt(t_mx2_ErrorEx*,t_mx2_ErrorEx*)> l_compareFunc){
  this->m_Sort(l_compareFunc,bbInt(0),(this->m__0length-1));
}

void t_std_collections_Stack_1Tt_mx2_ErrorEx_2::m_Sort(bbBool l_ascending){
  if(l_ascending){
    struct lambda4 : public bbFunction<bbInt(t_mx2_ErrorEx*,t_mx2_ErrorEx*)>::Rep{
      t_std_collections_Stack_1Tt_mx2_ErrorEx_2* l_self;
      lambda4(t_std_collections_Stack_1Tt_mx2_ErrorEx_2* l_self):l_self(l_self){
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
      t_std_collections_Stack_1Tt_mx2_ErrorEx_2* l_self;
      lambda5(t_std_collections_Stack_1Tt_mx2_ErrorEx_2* l_self):l_self(l_self){
      }
      bbInt invoke(t_mx2_ErrorEx* l_x,t_mx2_ErrorEx* l_y){
        return bbCompare(l_y,l_x);
      }
      void gcMark(){
        bbGCMarkPtr(l_self);
      }
    };
    this->m_Sort(bbFunction<bbInt(t_mx2_ErrorEx*,t_mx2_ErrorEx*)>(new lambda5(this)));
  }
}

t_std_collections_Stack_1Tt_mx2_ErrorEx_2* t_std_collections_Stack_1Tt_mx2_ErrorEx_2::m_Slice(bbInt l_index1,bbInt l_index2){
  struct f0_t : public bbGCFrame{
    bbArray<bbGCVar<t_mx2_ErrorEx>>* t0{};
    void gcMark(){
      bbGCMarkPtr(t0);
    }
  }f0{};
  if((l_index1<bbInt(0))){
    l_index1=g_monkey_math_Max_1i((l_index1+this->m__0length),bbInt(0));
  }else if((l_index1>this->m__0length)){
    l_index1=this->m__0length;
  }
  if((l_index2<bbInt(0))){
    l_index2=g_monkey_math_Max_1i((l_index2+this->m__0length),l_index1);
  }else if((l_index2>this->m__0length)){
    l_index2=this->m__0length;
  }else if((l_index2<l_index1)){
    l_index2=l_index1;
  }
  return bbGCNew<t_std_collections_Stack_1Tt_mx2_ErrorEx_2>(f0.t0=this->m__0data->slice(l_index1,l_index2));
}

t_std_collections_Stack_1Tt_mx2_ErrorEx_2* t_std_collections_Stack_1Tt_mx2_ErrorEx_2::m_Slice(bbInt l_index){
  return this->m_Slice(l_index,this->m__0length);
}

void t_std_collections_Stack_1Tt_mx2_ErrorEx_2::m_Set(bbInt l_index,t_mx2_ErrorEx* l_value){
  bbDebugAssert(((l_index>=bbInt(0))&&(l_index<this->m__0length)),BB_T("Stack index out of range"));
  this->m__0data->at(l_index)=l_value;
}

void t_std_collections_Stack_1Tt_mx2_ErrorEx_2::m_Resize(bbInt l_length){
  bbDebugAssert((l_length>=bbInt(0)),BB_T("Debug assert failed"));
  {
    bbInt l_i=l_length;
    for(;(l_i<this->m__0length);l_i+=1){
      this->m__0data->at(l_i)=((t_mx2_ErrorEx*)0);
    }
  }
  this->m_Reserve(l_length);
  this->m__0length=l_length;
  this->m__0seq+=1;
}

void t_std_collections_Stack_1Tt_mx2_ErrorEx_2::m_Reserve(bbInt l_capacity){
  struct f0_t : public bbGCFrame{
    bbArray<bbGCVar<t_mx2_ErrorEx>>* l_data{};
    void gcMark(){
      bbGCMarkPtr(l_data);
    }
  }f0{};
  bbDebugAssert((l_capacity>=bbInt(0)),BB_T("Debug assert failed"));
  if((this->m__0data->length()>=l_capacity)){
    return;
  }
  l_capacity=g_monkey_math_Max_1i(((this->m__0length*2)+this->m__0length),l_capacity);
  f0.l_data=bbArray<bbGCVar<t_mx2_ErrorEx>>::create(l_capacity);
  this->m__0data->copyTo(f0.l_data,bbInt(0),bbInt(0),this->m__0length);
  this->m__0data=f0.l_data;
}

bbBool t_std_collections_Stack_1Tt_mx2_ErrorEx_2::m_RemoveLast(t_mx2_ErrorEx* l_value,bbInt l_start){
  bbInt l_i=this->m_FindLastIndex(l_value,l_start);
  if((l_i==-1)){
    return false;
  }
  this->m_Erase(l_i);
  return true;
}

bbInt t_std_collections_Stack_1Tt_mx2_ErrorEx_2::m_RemoveEach(t_mx2_ErrorEx* l_value){
  bbInt l_put=bbInt(0);
  bbInt l_n=bbInt(0);
  {
    bbInt l_get=bbInt(0);
    for(;(l_get<this->m__0length);l_get+=1){
      if((this->m__0data->at(l_get)==l_value)){
        l_n+=1;
        continue;
      }
      this->m__0data->at(l_put)=this->m__0data->at(l_get);
      l_put+=1;
    }
  }
  this->m_Resize(l_put);
  return l_n;
}

bbBool t_std_collections_Stack_1Tt_mx2_ErrorEx_2::m_Remove(t_mx2_ErrorEx* l_value,bbInt l_start){
  bbInt l_i=this->m_FindIndex(l_value,l_start);
  if((l_i==-1)){
    return false;
  }
  this->m_Erase(l_i);
  return true;
}

void t_std_collections_Stack_1Tt_mx2_ErrorEx_2::m_Push(t_mx2_ErrorEx* l_value){
  this->m_Add(l_value);
}

t_mx2_ErrorEx* t_std_collections_Stack_1Tt_mx2_ErrorEx_2::m_Pop(){
  struct f0_t : public bbGCFrame{
    t_mx2_ErrorEx* l_value{};
    void gcMark(){
      bbGCMarkPtr(l_value);
    }
  }f0{};
  bbDebugAssert(bbBool(this->m__0length),BB_T("Stack is empty"));
  this->m__0length-=1;
  this->m__0seq+=1;
  f0.l_value=this->m__0data->at(this->m__0length);
  this->m__0data->at(this->m__0length)=((t_mx2_ErrorEx*)0);
  return f0.l_value;
}

bbInt t_std_collections_Stack_1Tt_mx2_ErrorEx_2::m_Length(){
  return this->m__0length;
}

void t_std_collections_Stack_1Tt_mx2_ErrorEx_2::m_Insert(bbInt l_index,t_mx2_ErrorEx* l_value){
  bbDebugAssert(((l_index>=bbInt(0))&&(l_index<=this->m__0length)),BB_T("Debug assert failed"));
  this->m_Reserve((this->m__0length+1));
  this->m__0data->copyTo(this->m__0data,l_index,(l_index+1),(this->m__0length-l_index));
  this->m__0data->at(l_index)=l_value;
  this->m__0length+=1;
  this->m__0seq+=1;
}

t_mx2_ErrorEx* t_std_collections_Stack_1Tt_mx2_ErrorEx_2::m_Get(bbInt l_index){
  bbDebugAssert(((l_index>=bbInt(0))&&(l_index<this->m__0length)),BB_T("Stack index out of range"));
  return this->m__0data->at(l_index);
}

bbInt t_std_collections_Stack_1Tt_mx2_ErrorEx_2::m_FindLastIndex(t_mx2_ErrorEx* l_value,bbInt l_start){
  bbDebugAssert(((l_start>=bbInt(0))&&(l_start<=this->m__0length)),BB_T("Debug assert failed"));
  bbInt l_i=this->m__0length;
  while((l_i>l_start)){
    l_i-=1;
    if((this->m__0data->at(l_i)==l_value)){
      return l_i;
    }
  }
  return -1;
}

bbInt t_std_collections_Stack_1Tt_mx2_ErrorEx_2::m_FindIndex(t_mx2_ErrorEx* l_value,bbInt l_start){
  bbDebugAssert(((l_start>=bbInt(0))&&(l_start<=this->m__0length)),BB_T("Debug assert failed"));
  bbInt l_i=l_start;
  while((l_i<this->m__0length)){
    if((this->m__0data->at(l_i)==l_value)){
      return l_i;
    }
    l_i+=1;
  }
  return -1;
}

void t_std_collections_Stack_1Tt_mx2_ErrorEx_2::m_Erase(bbInt l_index1,bbInt l_index2){
  bbDebugAssert((((((l_index1>=bbInt(0))&&(l_index1<=this->m__0length))&&(l_index2>=bbInt(0)))&&(l_index2<=this->m__0length))&&(l_index1<=l_index2)),BB_T("Debug assert failed"));
  if((l_index1==this->m__0length)){
    return;
  }
  this->m__0data->copyTo(this->m__0data,l_index2,l_index1,(this->m__0length-l_index2));
  this->m_Resize(((this->m__0length-l_index2)+l_index1));
}

void t_std_collections_Stack_1Tt_mx2_ErrorEx_2::m_Erase(bbInt l_index){
  bbDebugAssert(((l_index>=bbInt(0))&&(l_index<=this->m__0length)),BB_T("Debug assert failed"));
  if((l_index==this->m__0length)){
    return;
  }
  this->m__0data->copyTo(this->m__0data,(l_index+1),l_index,((this->m__0length-l_index)-1));
  this->m_Resize((this->m__0length-1));
}

bbBool t_std_collections_Stack_1Tt_mx2_ErrorEx_2::m_Empty(){
  return (this->m__0length==bbInt(0));
}

bbArray<bbGCVar<t_mx2_ErrorEx>>* t_std_collections_Stack_1Tt_mx2_ErrorEx_2::m_Data(){
  return this->m__0data;
}

bbBool t_std_collections_Stack_1Tt_mx2_ErrorEx_2::m_Contains(t_mx2_ErrorEx* l_value){
  return (this->m_FindIndex(l_value,bbInt(0))!=-1);
}

void t_std_collections_Stack_1Tt_mx2_ErrorEx_2::m_Clear(){
  this->m_Resize(bbInt(0));
}

bbInt t_std_collections_Stack_1Tt_mx2_ErrorEx_2::m_Capacity(){
  return this->m__0data->length();
}

t_std_collections_Stack_1Tt_mx2_ErrorEx_2_BackwardsIterator t_std_collections_Stack_1Tt_mx2_ErrorEx_2::m_Backwards(){
  return t_std_collections_Stack_1Tt_mx2_ErrorEx_2_BackwardsIterator(this,(this->m__0length-1));
}

t_std_collections_Stack_1Tt_mx2_ErrorEx_2_Iterator t_std_collections_Stack_1Tt_mx2_ErrorEx_2::m_All(){
  return t_std_collections_Stack_1Tt_mx2_ErrorEx_2_Iterator(this,bbInt(0));
}

void t_std_collections_Stack_1Tt_mx2_ErrorEx_2::m_AddAll(bbArray<bbGCVar<t_mx2_ErrorEx>>* l_values){
  this->m_Reserve((this->m__0length+l_values->length()));
  l_values->copyTo(this->m__0data,bbInt(0),this->m__0length,l_values->length());
  this->m_Resize((this->m__0length+l_values->length()));
}

void t_std_collections_Stack_1Tt_mx2_ErrorEx_2::m_Add(t_mx2_ErrorEx* l_value){
  this->m_Reserve((this->m__0length+1));
  this->m__0data->at(this->m__0length)=l_value;
  this->m__0length+=1;
  this->m__0seq+=1;
}

t_std_collections_Stack_1Tt_mx2_ClassType_2_Iterator::t_std_collections_Stack_1Tt_mx2_ClassType_2_Iterator(t_std_collections_Stack_1Tt_mx2_ClassType_2* l_stack,bbInt l_index){
  (*this).m__0stack=l_stack;
  (*this).m__0index=l_index;
  (*this).m__0seq=l_stack->m__0seq;
}

void t_std_collections_Stack_1Tt_mx2_ClassType_2_Iterator::m_Insert(t_mx2_ClassType* l_value){
  (*this).m_AssertSeq();
  (*this).m__0stack->m_Insert((*this).m__0index,l_value);
  (*this).m__0seq=(*this).m__0stack->m__0seq;
}

void t_std_collections_Stack_1Tt_mx2_ClassType_2_Iterator::m_Erase(){
  (*this).m_AssertSeq();
  (*this).m__0stack->m_Erase((*this).m__0index);
  (*this).m__0seq=(*this).m__0stack->m__0seq;
}

void t_std_collections_Stack_1Tt_mx2_ClassType_2_Iterator::m_Current(t_mx2_ClassType* l_current){
  (*this).m_AssertCurrent();
  (*this).m__0stack->m__0data->at((*this).m__0index)=l_current;
}

t_mx2_ClassType* t_std_collections_Stack_1Tt_mx2_ClassType_2_Iterator::m_Current(){
  (*this).m_AssertCurrent();
  return (*this).m__0stack->m__0data->at((*this).m__0index);
}

void t_std_collections_Stack_1Tt_mx2_ClassType_2_Iterator::m_Bump(){
  (*this).m_AssertCurrent();
  (*this).m__0index+=1;
}

bbBool t_std_collections_Stack_1Tt_mx2_ClassType_2_Iterator::m_AtEnd(){
  (*this).m_AssertSeq();
  return ((*this).m__0index==(*this).m__0stack->m__0length);
}

void t_std_collections_Stack_1Tt_mx2_ClassType_2_Iterator::m_AssertSeq(){
  bbDebugAssert(((*this).m__0seq==(*this).m__0stack->m__0seq),BB_T("Concurrent list modification"));
}

void t_std_collections_Stack_1Tt_mx2_ClassType_2_Iterator::m_AssertCurrent(){
  bbDebugAssert(!(*this).m_AtEnd(),BB_T("Invalid list iterator"));
}

int bbCompare(const t_std_collections_Stack_1Tt_mx2_ClassType_2_Iterator&x,const t_std_collections_Stack_1Tt_mx2_ClassType_2_Iterator&y){
  if(int t=bbCompare(x.m__0stack,y.m__0stack)) return t;
  if(int t=bbCompare(x.m__0index,y.m__0index)) return t;
  if(int t=bbCompare(x.m__0seq,y.m__0seq)) return t;
  return 0;
}

void bbGCMark(const t_std_collections_Stack_1Tt_mx2_ClassType_2_Iterator&t){
  bbGCMark(t.m__0stack);
}

t_std_collections_Stack_1Tt_mx2_ClassType_2_BackwardsIterator::t_std_collections_Stack_1Tt_mx2_ClassType_2_BackwardsIterator(t_std_collections_Stack_1Tt_mx2_ClassType_2* l_stack,bbInt l_index){
  (*this).m__0stack=l_stack;
  (*this).m__0index=l_index;
  (*this).m__0seq=l_stack->m__0seq;
}

void t_std_collections_Stack_1Tt_mx2_ClassType_2_BackwardsIterator::m_Insert(t_mx2_ClassType* l_value){
  (*this).m_AssertSeq();
  (*this).m__0index+=1;
  (*this).m__0stack->m_Insert((*this).m__0index,l_value);
  (*this).m__0seq=(*this).m__0stack->m__0seq;
}

void t_std_collections_Stack_1Tt_mx2_ClassType_2_BackwardsIterator::m_Erase(){
  (*this).m_AssertCurrent();
  (*this).m__0index-=1;
  (*this).m__0stack->m_Erase(((*this).m__0index+1));
  (*this).m__0seq=(*this).m__0stack->m__0seq;
}

void t_std_collections_Stack_1Tt_mx2_ClassType_2_BackwardsIterator::m_Current(t_mx2_ClassType* l_current){
  (*this).m_AssertCurrent();
  (*this).m__0stack->m__0data->at((*this).m__0index)=l_current;
}

t_mx2_ClassType* t_std_collections_Stack_1Tt_mx2_ClassType_2_BackwardsIterator::m_Current(){
  (*this).m_AssertCurrent();
  return (*this).m__0stack->m__0data->at((*this).m__0index);
}

void t_std_collections_Stack_1Tt_mx2_ClassType_2_BackwardsIterator::m_Bump(){
  (*this).m_AssertCurrent();
  (*this).m__0index-=1;
}

bbBool t_std_collections_Stack_1Tt_mx2_ClassType_2_BackwardsIterator::m_AtEnd(){
  (*this).m_AssertSeq();
  return ((*this).m__0index==-1);
}

void t_std_collections_Stack_1Tt_mx2_ClassType_2_BackwardsIterator::m_AssertSeq(){
  bbDebugAssert(((*this).m__0seq==(*this).m__0stack->m__0seq),BB_T("Concurrent list modification"));
}

void t_std_collections_Stack_1Tt_mx2_ClassType_2_BackwardsIterator::m_AssertCurrent(){
  bbDebugAssert(!(*this).m_AtEnd(),BB_T("Invalid list iterator"));
}

int bbCompare(const t_std_collections_Stack_1Tt_mx2_ClassType_2_BackwardsIterator&x,const t_std_collections_Stack_1Tt_mx2_ClassType_2_BackwardsIterator&y){
  if(int t=bbCompare(x.m__0stack,y.m__0stack)) return t;
  if(int t=bbCompare(x.m__0index,y.m__0index)) return t;
  if(int t=bbCompare(x.m__0seq,y.m__0seq)) return t;
  return 0;
}

void bbGCMark(const t_std_collections_Stack_1Tt_mx2_ClassType_2_BackwardsIterator&t){
  bbGCMark(t.m__0stack);
}

void t_std_collections_Stack_1Tt_mx2_ClassType_2::gcMark(){
  bbGCMark(m__0data);
}

t_std_collections_Stack_1Tt_mx2_ClassType_2::t_std_collections_Stack_1Tt_mx2_ClassType_2(t_std_collections_List_1Tt_mx2_ClassType_2* l_values){
  g_std_collections_Stack_1Tt_mx2_ClassType_2_AddAll_1Tt_std_collections_List_1Tt_mx2_ClassType_2_2(this,l_values);
}

t_std_collections_Stack_1Tt_mx2_ClassType_2::t_std_collections_Stack_1Tt_mx2_ClassType_2(t_std_collections_Stack_1Tt_mx2_ClassType_2* l_values){
  struct f0_t : public bbGCFrame{
    bbArray<bbGCVar<t_mx2_ClassType>>* t0{};
    void gcMark(){
      bbGCMarkPtr(t0);
    }
  }f0{};
  this->m__0length=l_values->m_Length();
  this->m__0data=bbArray<bbGCVar<t_mx2_ClassType>>::create(this->m__0length);
  (f0.t0=l_values->m_Data())->copyTo(this->m__0data,bbInt(0),bbInt(0),this->m__0length);
}

t_std_collections_Stack_1Tt_mx2_ClassType_2::t_std_collections_Stack_1Tt_mx2_ClassType_2(bbArray<bbGCVar<t_mx2_ClassType>>* l_values){
  this->m_AddAll(l_values);
}

t_std_collections_Stack_1Tt_mx2_ClassType_2::t_std_collections_Stack_1Tt_mx2_ClassType_2(bbInt l_length){
  this->m__0length=l_length;
  this->m__0data=bbArray<bbGCVar<t_mx2_ClassType>>::create(this->m__0length);
}

t_std_collections_Stack_1Tt_mx2_ClassType_2::t_std_collections_Stack_1Tt_mx2_ClassType_2(){
  this->m__0data=bbArray<bbGCVar<t_mx2_ClassType>>::create(10);
}

void t_std_collections_Stack_1Tt_mx2_ClassType_2::m__idxeq(bbInt l_index,t_mx2_ClassType* l_value){
  bbDebugAssert(((l_index>=bbInt(0))&&(l_index<this->m__0length)),BB_T("Stack index out of range"));
  this->m__0data->at(l_index)=l_value;
}

t_mx2_ClassType* t_std_collections_Stack_1Tt_mx2_ClassType_2::m__idx(bbInt l_index){
  bbDebugAssert(((l_index>=bbInt(0))&&(l_index<this->m__0length)),BB_T("Stack index out of range"));
  return this->m__0data->at(l_index);
}

t_mx2_ClassType* t_std_collections_Stack_1Tt_mx2_ClassType_2::m_Top(){
  bbDebugAssert(bbBool(this->m__0length),BB_T("Stack is empty"));
  return this->m__0data->at((this->m__0length-1));
}

bbArray<bbGCVar<t_mx2_ClassType>>* t_std_collections_Stack_1Tt_mx2_ClassType_2::m_ToArray(){
  return this->m__0data->slice(bbInt(0),this->m__0length);
}

void t_std_collections_Stack_1Tt_mx2_ClassType_2::m_Swap(bbInt l_index1,bbInt l_index2){
  struct f0_t : public bbGCFrame{
    t_mx2_ClassType* l_t{};
    void gcMark(){
      bbGCMarkPtr(l_t);
    }
  }f0{};
  bbDebugAssert(((((l_index1>=bbInt(0))&&(l_index1<this->m__0length))&&(l_index2>=bbInt(0)))&&(l_index2<this->m__0length)),BB_T("Stack index out of range"));
  f0.l_t=this->m__0data->at(l_index1);
  this->m__0data->at(l_index1)=this->m__0data->at(l_index2);
  this->m__0data->at(l_index2)=f0.l_t;
}

void t_std_collections_Stack_1Tt_mx2_ClassType_2::m_Sort(bbFunction<bbInt(t_mx2_ClassType*,t_mx2_ClassType*)> l_compareFunc,bbInt l_lo,bbInt l_hi){
  if((l_hi<=l_lo)){
    return;
  }
  if(((l_lo+1)==l_hi)){
    if((l_compareFunc(this->m__0data->at(l_hi),this->m__0data->at(l_lo))<bbInt(0))){
      this->m_Swap(l_hi,l_lo);
    }
    return;
  }
  bbInt l_i=((l_lo+l_hi)/2);
  if((l_compareFunc(this->m__0data->at(l_i),this->m__0data->at(l_lo))<bbInt(0))){
    this->m_Swap(l_i,l_lo);
  }
  if((l_compareFunc(this->m__0data->at(l_hi),this->m__0data->at(l_i))<bbInt(0))){
    this->m_Swap(l_hi,l_i);
    if((l_compareFunc(this->m__0data->at(l_i),this->m__0data->at(l_lo))<bbInt(0))){
      this->m_Swap(l_i,l_lo);
    }
  }
  bbInt l_x=(l_lo+1);
  bbInt l_y=(l_hi-1);
  do{
    struct f1_t : public bbGCFrame{
      t_mx2_ClassType* l_p{};
      void gcMark(){
        bbGCMarkPtr(l_p);
      }
    }f1{};
    f1.l_p=this->m__0data->at(l_i);
    while((l_compareFunc(this->m__0data->at(l_x),f1.l_p)<bbInt(0))){
      l_x+=1;
    }
    while((l_compareFunc(f1.l_p,this->m__0data->at(l_y))<bbInt(0))){
      l_y-=1;
    }
    if((l_x>l_y)){
      break;
    }
    if((l_x<l_y)){
      this->m_Swap(l_x,l_y);
      if((l_i==l_x)){
        l_i=l_y;
      }else if((l_i==l_y)){
        l_i=l_x;
      }
    }
    l_x+=1;
    l_y-=1;
  }while(!((l_x>l_y)));
  this->m_Sort(l_compareFunc,l_lo,l_y);
  this->m_Sort(l_compareFunc,l_x,l_hi);
}

void t_std_collections_Stack_1Tt_mx2_ClassType_2::m_Sort(bbFunction<bbInt(t_mx2_ClassType*,t_mx2_ClassType*)> l_compareFunc){
  this->m_Sort(l_compareFunc,bbInt(0),(this->m__0length-1));
}

void t_std_collections_Stack_1Tt_mx2_ClassType_2::m_Sort(bbBool l_ascending){
  if(l_ascending){
    struct lambda6 : public bbFunction<bbInt(t_mx2_ClassType*,t_mx2_ClassType*)>::Rep{
      t_std_collections_Stack_1Tt_mx2_ClassType_2* l_self;
      lambda6(t_std_collections_Stack_1Tt_mx2_ClassType_2* l_self):l_self(l_self){
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
      t_std_collections_Stack_1Tt_mx2_ClassType_2* l_self;
      lambda7(t_std_collections_Stack_1Tt_mx2_ClassType_2* l_self):l_self(l_self){
      }
      bbInt invoke(t_mx2_ClassType* l_x,t_mx2_ClassType* l_y){
        return l_y->m__cmp(((t_mx2_Type*)(l_x)));
      }
      void gcMark(){
        bbGCMarkPtr(l_self);
      }
    };
    this->m_Sort(bbFunction<bbInt(t_mx2_ClassType*,t_mx2_ClassType*)>(new lambda7(this)));
  }
}

t_std_collections_Stack_1Tt_mx2_ClassType_2* t_std_collections_Stack_1Tt_mx2_ClassType_2::m_Slice(bbInt l_index1,bbInt l_index2){
  struct f0_t : public bbGCFrame{
    bbArray<bbGCVar<t_mx2_ClassType>>* t0{};
    void gcMark(){
      bbGCMarkPtr(t0);
    }
  }f0{};
  if((l_index1<bbInt(0))){
    l_index1=g_monkey_math_Max_1i((l_index1+this->m__0length),bbInt(0));
  }else if((l_index1>this->m__0length)){
    l_index1=this->m__0length;
  }
  if((l_index2<bbInt(0))){
    l_index2=g_monkey_math_Max_1i((l_index2+this->m__0length),l_index1);
  }else if((l_index2>this->m__0length)){
    l_index2=this->m__0length;
  }else if((l_index2<l_index1)){
    l_index2=l_index1;
  }
  return bbGCNew<t_std_collections_Stack_1Tt_mx2_ClassType_2>(f0.t0=this->m__0data->slice(l_index1,l_index2));
}

t_std_collections_Stack_1Tt_mx2_ClassType_2* t_std_collections_Stack_1Tt_mx2_ClassType_2::m_Slice(bbInt l_index){
  return this->m_Slice(l_index,this->m__0length);
}

void t_std_collections_Stack_1Tt_mx2_ClassType_2::m_Set(bbInt l_index,t_mx2_ClassType* l_value){
  bbDebugAssert(((l_index>=bbInt(0))&&(l_index<this->m__0length)),BB_T("Stack index out of range"));
  this->m__0data->at(l_index)=l_value;
}

void t_std_collections_Stack_1Tt_mx2_ClassType_2::m_Resize(bbInt l_length){
  bbDebugAssert((l_length>=bbInt(0)),BB_T("Debug assert failed"));
  {
    bbInt l_i=l_length;
    for(;(l_i<this->m__0length);l_i+=1){
      this->m__0data->at(l_i)=((t_mx2_ClassType*)0);
    }
  }
  this->m_Reserve(l_length);
  this->m__0length=l_length;
  this->m__0seq+=1;
}

void t_std_collections_Stack_1Tt_mx2_ClassType_2::m_Reserve(bbInt l_capacity){
  struct f0_t : public bbGCFrame{
    bbArray<bbGCVar<t_mx2_ClassType>>* l_data{};
    void gcMark(){
      bbGCMarkPtr(l_data);
    }
  }f0{};
  bbDebugAssert((l_capacity>=bbInt(0)),BB_T("Debug assert failed"));
  if((this->m__0data->length()>=l_capacity)){
    return;
  }
  l_capacity=g_monkey_math_Max_1i(((this->m__0length*2)+this->m__0length),l_capacity);
  f0.l_data=bbArray<bbGCVar<t_mx2_ClassType>>::create(l_capacity);
  this->m__0data->copyTo(f0.l_data,bbInt(0),bbInt(0),this->m__0length);
  this->m__0data=f0.l_data;
}

bbBool t_std_collections_Stack_1Tt_mx2_ClassType_2::m_RemoveLast(t_mx2_ClassType* l_value,bbInt l_start){
  bbInt l_i=this->m_FindLastIndex(l_value,l_start);
  if((l_i==-1)){
    return false;
  }
  this->m_Erase(l_i);
  return true;
}

bbInt t_std_collections_Stack_1Tt_mx2_ClassType_2::m_RemoveEach(t_mx2_ClassType* l_value){
  bbInt l_put=bbInt(0);
  bbInt l_n=bbInt(0);
  {
    bbInt l_get=bbInt(0);
    for(;(l_get<this->m__0length);l_get+=1){
      if(this->m__0data->at(l_get)->m__eq(((t_mx2_Type*)(l_value)))){
        l_n+=1;
        continue;
      }
      this->m__0data->at(l_put)=this->m__0data->at(l_get);
      l_put+=1;
    }
  }
  this->m_Resize(l_put);
  return l_n;
}

bbBool t_std_collections_Stack_1Tt_mx2_ClassType_2::m_Remove(t_mx2_ClassType* l_value,bbInt l_start){
  bbInt l_i=this->m_FindIndex(l_value,l_start);
  if((l_i==-1)){
    return false;
  }
  this->m_Erase(l_i);
  return true;
}

void t_std_collections_Stack_1Tt_mx2_ClassType_2::m_Push(t_mx2_ClassType* l_value){
  this->m_Add(l_value);
}

t_mx2_ClassType* t_std_collections_Stack_1Tt_mx2_ClassType_2::m_Pop(){
  struct f0_t : public bbGCFrame{
    t_mx2_ClassType* l_value{};
    void gcMark(){
      bbGCMarkPtr(l_value);
    }
  }f0{};
  bbDebugAssert(bbBool(this->m__0length),BB_T("Stack is empty"));
  this->m__0length-=1;
  this->m__0seq+=1;
  f0.l_value=this->m__0data->at(this->m__0length);
  this->m__0data->at(this->m__0length)=((t_mx2_ClassType*)0);
  return f0.l_value;
}

bbInt t_std_collections_Stack_1Tt_mx2_ClassType_2::m_Length(){
  return this->m__0length;
}

void t_std_collections_Stack_1Tt_mx2_ClassType_2::m_Insert(bbInt l_index,t_mx2_ClassType* l_value){
  bbDebugAssert(((l_index>=bbInt(0))&&(l_index<=this->m__0length)),BB_T("Debug assert failed"));
  this->m_Reserve((this->m__0length+1));
  this->m__0data->copyTo(this->m__0data,l_index,(l_index+1),(this->m__0length-l_index));
  this->m__0data->at(l_index)=l_value;
  this->m__0length+=1;
  this->m__0seq+=1;
}

t_mx2_ClassType* t_std_collections_Stack_1Tt_mx2_ClassType_2::m_Get(bbInt l_index){
  bbDebugAssert(((l_index>=bbInt(0))&&(l_index<this->m__0length)),BB_T("Stack index out of range"));
  return this->m__0data->at(l_index);
}

bbInt t_std_collections_Stack_1Tt_mx2_ClassType_2::m_FindLastIndex(t_mx2_ClassType* l_value,bbInt l_start){
  bbDebugAssert(((l_start>=bbInt(0))&&(l_start<=this->m__0length)),BB_T("Debug assert failed"));
  bbInt l_i=this->m__0length;
  while((l_i>l_start)){
    l_i-=1;
    if(this->m__0data->at(l_i)->m__eq(((t_mx2_Type*)(l_value)))){
      return l_i;
    }
  }
  return -1;
}

bbInt t_std_collections_Stack_1Tt_mx2_ClassType_2::m_FindIndex(t_mx2_ClassType* l_value,bbInt l_start){
  bbDebugAssert(((l_start>=bbInt(0))&&(l_start<=this->m__0length)),BB_T("Debug assert failed"));
  bbInt l_i=l_start;
  while((l_i<this->m__0length)){
    if(this->m__0data->at(l_i)->m__eq(((t_mx2_Type*)(l_value)))){
      return l_i;
    }
    l_i+=1;
  }
  return -1;
}

void t_std_collections_Stack_1Tt_mx2_ClassType_2::m_Erase(bbInt l_index1,bbInt l_index2){
  bbDebugAssert((((((l_index1>=bbInt(0))&&(l_index1<=this->m__0length))&&(l_index2>=bbInt(0)))&&(l_index2<=this->m__0length))&&(l_index1<=l_index2)),BB_T("Debug assert failed"));
  if((l_index1==this->m__0length)){
    return;
  }
  this->m__0data->copyTo(this->m__0data,l_index2,l_index1,(this->m__0length-l_index2));
  this->m_Resize(((this->m__0length-l_index2)+l_index1));
}

void t_std_collections_Stack_1Tt_mx2_ClassType_2::m_Erase(bbInt l_index){
  bbDebugAssert(((l_index>=bbInt(0))&&(l_index<=this->m__0length)),BB_T("Debug assert failed"));
  if((l_index==this->m__0length)){
    return;
  }
  this->m__0data->copyTo(this->m__0data,(l_index+1),l_index,((this->m__0length-l_index)-1));
  this->m_Resize((this->m__0length-1));
}

bbBool t_std_collections_Stack_1Tt_mx2_ClassType_2::m_Empty(){
  return (this->m__0length==bbInt(0));
}

bbArray<bbGCVar<t_mx2_ClassType>>* t_std_collections_Stack_1Tt_mx2_ClassType_2::m_Data(){
  return this->m__0data;
}

bbBool t_std_collections_Stack_1Tt_mx2_ClassType_2::m_Contains(t_mx2_ClassType* l_value){
  return (this->m_FindIndex(l_value,bbInt(0))!=-1);
}

void t_std_collections_Stack_1Tt_mx2_ClassType_2::m_Clear(){
  this->m_Resize(bbInt(0));
}

bbInt t_std_collections_Stack_1Tt_mx2_ClassType_2::m_Capacity(){
  return this->m__0data->length();
}

t_std_collections_Stack_1Tt_mx2_ClassType_2_BackwardsIterator t_std_collections_Stack_1Tt_mx2_ClassType_2::m_Backwards(){
  return t_std_collections_Stack_1Tt_mx2_ClassType_2_BackwardsIterator(this,(this->m__0length-1));
}

t_std_collections_Stack_1Tt_mx2_ClassType_2_Iterator t_std_collections_Stack_1Tt_mx2_ClassType_2::m_All(){
  return t_std_collections_Stack_1Tt_mx2_ClassType_2_Iterator(this,bbInt(0));
}

void t_std_collections_Stack_1Tt_mx2_ClassType_2::m_AddAll(bbArray<bbGCVar<t_mx2_ClassType>>* l_values){
  this->m_Reserve((this->m__0length+l_values->length()));
  l_values->copyTo(this->m__0data,bbInt(0),this->m__0length,l_values->length());
  this->m_Resize((this->m__0length+l_values->length()));
}

void t_std_collections_Stack_1Tt_mx2_ClassType_2::m_Add(t_mx2_ClassType* l_value){
  this->m_Reserve((this->m__0length+1));
  this->m__0data->at(this->m__0length)=l_value;
  this->m__0length+=1;
  this->m__0seq+=1;
}

t_std_collections_Stack_1Tt_mx2_Scope_2_Iterator::t_std_collections_Stack_1Tt_mx2_Scope_2_Iterator(t_std_collections_Stack_1Tt_mx2_Scope_2* l_stack,bbInt l_index){
  (*this).m__0stack=l_stack;
  (*this).m__0index=l_index;
  (*this).m__0seq=l_stack->m__0seq;
}

void t_std_collections_Stack_1Tt_mx2_Scope_2_Iterator::m_Insert(t_mx2_Scope* l_value){
  (*this).m_AssertSeq();
  (*this).m__0stack->m_Insert((*this).m__0index,l_value);
  (*this).m__0seq=(*this).m__0stack->m__0seq;
}

void t_std_collections_Stack_1Tt_mx2_Scope_2_Iterator::m_Erase(){
  (*this).m_AssertSeq();
  (*this).m__0stack->m_Erase((*this).m__0index);
  (*this).m__0seq=(*this).m__0stack->m__0seq;
}

void t_std_collections_Stack_1Tt_mx2_Scope_2_Iterator::m_Current(t_mx2_Scope* l_current){
  (*this).m_AssertCurrent();
  (*this).m__0stack->m__0data->at((*this).m__0index)=l_current;
}

t_mx2_Scope* t_std_collections_Stack_1Tt_mx2_Scope_2_Iterator::m_Current(){
  (*this).m_AssertCurrent();
  return (*this).m__0stack->m__0data->at((*this).m__0index);
}

void t_std_collections_Stack_1Tt_mx2_Scope_2_Iterator::m_Bump(){
  (*this).m_AssertCurrent();
  (*this).m__0index+=1;
}

bbBool t_std_collections_Stack_1Tt_mx2_Scope_2_Iterator::m_AtEnd(){
  (*this).m_AssertSeq();
  return ((*this).m__0index==(*this).m__0stack->m__0length);
}

void t_std_collections_Stack_1Tt_mx2_Scope_2_Iterator::m_AssertSeq(){
  bbDebugAssert(((*this).m__0seq==(*this).m__0stack->m__0seq),BB_T("Concurrent list modification"));
}

void t_std_collections_Stack_1Tt_mx2_Scope_2_Iterator::m_AssertCurrent(){
  bbDebugAssert(!(*this).m_AtEnd(),BB_T("Invalid list iterator"));
}

int bbCompare(const t_std_collections_Stack_1Tt_mx2_Scope_2_Iterator&x,const t_std_collections_Stack_1Tt_mx2_Scope_2_Iterator&y){
  if(int t=bbCompare(x.m__0stack,y.m__0stack)) return t;
  if(int t=bbCompare(x.m__0index,y.m__0index)) return t;
  if(int t=bbCompare(x.m__0seq,y.m__0seq)) return t;
  return 0;
}

void bbGCMark(const t_std_collections_Stack_1Tt_mx2_Scope_2_Iterator&t){
  bbGCMark(t.m__0stack);
}

t_std_collections_Stack_1Tt_mx2_Scope_2_BackwardsIterator::t_std_collections_Stack_1Tt_mx2_Scope_2_BackwardsIterator(t_std_collections_Stack_1Tt_mx2_Scope_2* l_stack,bbInt l_index){
  (*this).m__0stack=l_stack;
  (*this).m__0index=l_index;
  (*this).m__0seq=l_stack->m__0seq;
}

void t_std_collections_Stack_1Tt_mx2_Scope_2_BackwardsIterator::m_Insert(t_mx2_Scope* l_value){
  (*this).m_AssertSeq();
  (*this).m__0index+=1;
  (*this).m__0stack->m_Insert((*this).m__0index,l_value);
  (*this).m__0seq=(*this).m__0stack->m__0seq;
}

void t_std_collections_Stack_1Tt_mx2_Scope_2_BackwardsIterator::m_Erase(){
  (*this).m_AssertCurrent();
  (*this).m__0index-=1;
  (*this).m__0stack->m_Erase(((*this).m__0index+1));
  (*this).m__0seq=(*this).m__0stack->m__0seq;
}

void t_std_collections_Stack_1Tt_mx2_Scope_2_BackwardsIterator::m_Current(t_mx2_Scope* l_current){
  (*this).m_AssertCurrent();
  (*this).m__0stack->m__0data->at((*this).m__0index)=l_current;
}

t_mx2_Scope* t_std_collections_Stack_1Tt_mx2_Scope_2_BackwardsIterator::m_Current(){
  (*this).m_AssertCurrent();
  return (*this).m__0stack->m__0data->at((*this).m__0index);
}

void t_std_collections_Stack_1Tt_mx2_Scope_2_BackwardsIterator::m_Bump(){
  (*this).m_AssertCurrent();
  (*this).m__0index-=1;
}

bbBool t_std_collections_Stack_1Tt_mx2_Scope_2_BackwardsIterator::m_AtEnd(){
  (*this).m_AssertSeq();
  return ((*this).m__0index==-1);
}

void t_std_collections_Stack_1Tt_mx2_Scope_2_BackwardsIterator::m_AssertSeq(){
  bbDebugAssert(((*this).m__0seq==(*this).m__0stack->m__0seq),BB_T("Concurrent list modification"));
}

void t_std_collections_Stack_1Tt_mx2_Scope_2_BackwardsIterator::m_AssertCurrent(){
  bbDebugAssert(!(*this).m_AtEnd(),BB_T("Invalid list iterator"));
}

int bbCompare(const t_std_collections_Stack_1Tt_mx2_Scope_2_BackwardsIterator&x,const t_std_collections_Stack_1Tt_mx2_Scope_2_BackwardsIterator&y){
  if(int t=bbCompare(x.m__0stack,y.m__0stack)) return t;
  if(int t=bbCompare(x.m__0index,y.m__0index)) return t;
  if(int t=bbCompare(x.m__0seq,y.m__0seq)) return t;
  return 0;
}

void bbGCMark(const t_std_collections_Stack_1Tt_mx2_Scope_2_BackwardsIterator&t){
  bbGCMark(t.m__0stack);
}

void t_std_collections_Stack_1Tt_mx2_Scope_2::gcMark(){
  bbGCMark(m__0data);
}

t_std_collections_Stack_1Tt_mx2_Scope_2::t_std_collections_Stack_1Tt_mx2_Scope_2(t_std_collections_List_1Tt_mx2_Scope_2* l_values){
  g_std_collections_Stack_1Tt_mx2_Scope_2_AddAll_1Tt_std_collections_List_1Tt_mx2_Scope_2_2(this,l_values);
}

t_std_collections_Stack_1Tt_mx2_Scope_2::t_std_collections_Stack_1Tt_mx2_Scope_2(t_std_collections_Stack_1Tt_mx2_Scope_2* l_values){
  struct f0_t : public bbGCFrame{
    bbArray<bbGCVar<t_mx2_Scope>>* t0{};
    void gcMark(){
      bbGCMarkPtr(t0);
    }
  }f0{};
  this->m__0length=l_values->m_Length();
  this->m__0data=bbArray<bbGCVar<t_mx2_Scope>>::create(this->m__0length);
  (f0.t0=l_values->m_Data())->copyTo(this->m__0data,bbInt(0),bbInt(0),this->m__0length);
}

t_std_collections_Stack_1Tt_mx2_Scope_2::t_std_collections_Stack_1Tt_mx2_Scope_2(bbArray<bbGCVar<t_mx2_Scope>>* l_values){
  this->m_AddAll(l_values);
}

t_std_collections_Stack_1Tt_mx2_Scope_2::t_std_collections_Stack_1Tt_mx2_Scope_2(bbInt l_length){
  this->m__0length=l_length;
  this->m__0data=bbArray<bbGCVar<t_mx2_Scope>>::create(this->m__0length);
}

t_std_collections_Stack_1Tt_mx2_Scope_2::t_std_collections_Stack_1Tt_mx2_Scope_2(){
  this->m__0data=bbArray<bbGCVar<t_mx2_Scope>>::create(10);
}

void t_std_collections_Stack_1Tt_mx2_Scope_2::m__idxeq(bbInt l_index,t_mx2_Scope* l_value){
  bbDebugAssert(((l_index>=bbInt(0))&&(l_index<this->m__0length)),BB_T("Stack index out of range"));
  this->m__0data->at(l_index)=l_value;
}

t_mx2_Scope* t_std_collections_Stack_1Tt_mx2_Scope_2::m__idx(bbInt l_index){
  bbDebugAssert(((l_index>=bbInt(0))&&(l_index<this->m__0length)),BB_T("Stack index out of range"));
  return this->m__0data->at(l_index);
}

t_mx2_Scope* t_std_collections_Stack_1Tt_mx2_Scope_2::m_Top(){
  bbDebugAssert(bbBool(this->m__0length),BB_T("Stack is empty"));
  return this->m__0data->at((this->m__0length-1));
}

bbArray<bbGCVar<t_mx2_Scope>>* t_std_collections_Stack_1Tt_mx2_Scope_2::m_ToArray(){
  return this->m__0data->slice(bbInt(0),this->m__0length);
}

void t_std_collections_Stack_1Tt_mx2_Scope_2::m_Swap(bbInt l_index1,bbInt l_index2){
  struct f0_t : public bbGCFrame{
    t_mx2_Scope* l_t{};
    void gcMark(){
      bbGCMarkPtr(l_t);
    }
  }f0{};
  bbDebugAssert(((((l_index1>=bbInt(0))&&(l_index1<this->m__0length))&&(l_index2>=bbInt(0)))&&(l_index2<this->m__0length)),BB_T("Stack index out of range"));
  f0.l_t=this->m__0data->at(l_index1);
  this->m__0data->at(l_index1)=this->m__0data->at(l_index2);
  this->m__0data->at(l_index2)=f0.l_t;
}

void t_std_collections_Stack_1Tt_mx2_Scope_2::m_Sort(bbFunction<bbInt(t_mx2_Scope*,t_mx2_Scope*)> l_compareFunc,bbInt l_lo,bbInt l_hi){
  if((l_hi<=l_lo)){
    return;
  }
  if(((l_lo+1)==l_hi)){
    if((l_compareFunc(this->m__0data->at(l_hi),this->m__0data->at(l_lo))<bbInt(0))){
      this->m_Swap(l_hi,l_lo);
    }
    return;
  }
  bbInt l_i=((l_lo+l_hi)/2);
  if((l_compareFunc(this->m__0data->at(l_i),this->m__0data->at(l_lo))<bbInt(0))){
    this->m_Swap(l_i,l_lo);
  }
  if((l_compareFunc(this->m__0data->at(l_hi),this->m__0data->at(l_i))<bbInt(0))){
    this->m_Swap(l_hi,l_i);
    if((l_compareFunc(this->m__0data->at(l_i),this->m__0data->at(l_lo))<bbInt(0))){
      this->m_Swap(l_i,l_lo);
    }
  }
  bbInt l_x=(l_lo+1);
  bbInt l_y=(l_hi-1);
  do{
    struct f1_t : public bbGCFrame{
      t_mx2_Scope* l_p{};
      void gcMark(){
        bbGCMarkPtr(l_p);
      }
    }f1{};
    f1.l_p=this->m__0data->at(l_i);
    while((l_compareFunc(this->m__0data->at(l_x),f1.l_p)<bbInt(0))){
      l_x+=1;
    }
    while((l_compareFunc(f1.l_p,this->m__0data->at(l_y))<bbInt(0))){
      l_y-=1;
    }
    if((l_x>l_y)){
      break;
    }
    if((l_x<l_y)){
      this->m_Swap(l_x,l_y);
      if((l_i==l_x)){
        l_i=l_y;
      }else if((l_i==l_y)){
        l_i=l_x;
      }
    }
    l_x+=1;
    l_y-=1;
  }while(!((l_x>l_y)));
  this->m_Sort(l_compareFunc,l_lo,l_y);
  this->m_Sort(l_compareFunc,l_x,l_hi);
}

void t_std_collections_Stack_1Tt_mx2_Scope_2::m_Sort(bbFunction<bbInt(t_mx2_Scope*,t_mx2_Scope*)> l_compareFunc){
  this->m_Sort(l_compareFunc,bbInt(0),(this->m__0length-1));
}

void t_std_collections_Stack_1Tt_mx2_Scope_2::m_Sort(bbBool l_ascending){
  if(l_ascending){
    struct lambda8 : public bbFunction<bbInt(t_mx2_Scope*,t_mx2_Scope*)>::Rep{
      t_std_collections_Stack_1Tt_mx2_Scope_2* l_self;
      lambda8(t_std_collections_Stack_1Tt_mx2_Scope_2* l_self):l_self(l_self){
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
      t_std_collections_Stack_1Tt_mx2_Scope_2* l_self;
      lambda9(t_std_collections_Stack_1Tt_mx2_Scope_2* l_self):l_self(l_self){
      }
      bbInt invoke(t_mx2_Scope* l_x,t_mx2_Scope* l_y){
        return bbCompare(l_y,l_x);
      }
      void gcMark(){
        bbGCMarkPtr(l_self);
      }
    };
    this->m_Sort(bbFunction<bbInt(t_mx2_Scope*,t_mx2_Scope*)>(new lambda9(this)));
  }
}

t_std_collections_Stack_1Tt_mx2_Scope_2* t_std_collections_Stack_1Tt_mx2_Scope_2::m_Slice(bbInt l_index1,bbInt l_index2){
  struct f0_t : public bbGCFrame{
    bbArray<bbGCVar<t_mx2_Scope>>* t0{};
    void gcMark(){
      bbGCMarkPtr(t0);
    }
  }f0{};
  if((l_index1<bbInt(0))){
    l_index1=g_monkey_math_Max_1i((l_index1+this->m__0length),bbInt(0));
  }else if((l_index1>this->m__0length)){
    l_index1=this->m__0length;
  }
  if((l_index2<bbInt(0))){
    l_index2=g_monkey_math_Max_1i((l_index2+this->m__0length),l_index1);
  }else if((l_index2>this->m__0length)){
    l_index2=this->m__0length;
  }else if((l_index2<l_index1)){
    l_index2=l_index1;
  }
  return bbGCNew<t_std_collections_Stack_1Tt_mx2_Scope_2>(f0.t0=this->m__0data->slice(l_index1,l_index2));
}

t_std_collections_Stack_1Tt_mx2_Scope_2* t_std_collections_Stack_1Tt_mx2_Scope_2::m_Slice(bbInt l_index){
  return this->m_Slice(l_index,this->m__0length);
}

void t_std_collections_Stack_1Tt_mx2_Scope_2::m_Set(bbInt l_index,t_mx2_Scope* l_value){
  bbDebugAssert(((l_index>=bbInt(0))&&(l_index<this->m__0length)),BB_T("Stack index out of range"));
  this->m__0data->at(l_index)=l_value;
}

void t_std_collections_Stack_1Tt_mx2_Scope_2::m_Resize(bbInt l_length){
  bbDebugAssert((l_length>=bbInt(0)),BB_T("Debug assert failed"));
  {
    bbInt l_i=l_length;
    for(;(l_i<this->m__0length);l_i+=1){
      this->m__0data->at(l_i)=((t_mx2_Scope*)0);
    }
  }
  this->m_Reserve(l_length);
  this->m__0length=l_length;
  this->m__0seq+=1;
}

void t_std_collections_Stack_1Tt_mx2_Scope_2::m_Reserve(bbInt l_capacity){
  struct f0_t : public bbGCFrame{
    bbArray<bbGCVar<t_mx2_Scope>>* l_data{};
    void gcMark(){
      bbGCMarkPtr(l_data);
    }
  }f0{};
  bbDebugAssert((l_capacity>=bbInt(0)),BB_T("Debug assert failed"));
  if((this->m__0data->length()>=l_capacity)){
    return;
  }
  l_capacity=g_monkey_math_Max_1i(((this->m__0length*2)+this->m__0length),l_capacity);
  f0.l_data=bbArray<bbGCVar<t_mx2_Scope>>::create(l_capacity);
  this->m__0data->copyTo(f0.l_data,bbInt(0),bbInt(0),this->m__0length);
  this->m__0data=f0.l_data;
}

bbBool t_std_collections_Stack_1Tt_mx2_Scope_2::m_RemoveLast(t_mx2_Scope* l_value,bbInt l_start){
  bbInt l_i=this->m_FindLastIndex(l_value,l_start);
  if((l_i==-1)){
    return false;
  }
  this->m_Erase(l_i);
  return true;
}

bbInt t_std_collections_Stack_1Tt_mx2_Scope_2::m_RemoveEach(t_mx2_Scope* l_value){
  bbInt l_put=bbInt(0);
  bbInt l_n=bbInt(0);
  {
    bbInt l_get=bbInt(0);
    for(;(l_get<this->m__0length);l_get+=1){
      if((this->m__0data->at(l_get)==l_value)){
        l_n+=1;
        continue;
      }
      this->m__0data->at(l_put)=this->m__0data->at(l_get);
      l_put+=1;
    }
  }
  this->m_Resize(l_put);
  return l_n;
}

bbBool t_std_collections_Stack_1Tt_mx2_Scope_2::m_Remove(t_mx2_Scope* l_value,bbInt l_start){
  bbInt l_i=this->m_FindIndex(l_value,l_start);
  if((l_i==-1)){
    return false;
  }
  this->m_Erase(l_i);
  return true;
}

void t_std_collections_Stack_1Tt_mx2_Scope_2::m_Push(t_mx2_Scope* l_value){
  this->m_Add(l_value);
}

t_mx2_Scope* t_std_collections_Stack_1Tt_mx2_Scope_2::m_Pop(){
  struct f0_t : public bbGCFrame{
    t_mx2_Scope* l_value{};
    void gcMark(){
      bbGCMarkPtr(l_value);
    }
  }f0{};
  bbDebugAssert(bbBool(this->m__0length),BB_T("Stack is empty"));
  this->m__0length-=1;
  this->m__0seq+=1;
  f0.l_value=this->m__0data->at(this->m__0length);
  this->m__0data->at(this->m__0length)=((t_mx2_Scope*)0);
  return f0.l_value;
}

bbInt t_std_collections_Stack_1Tt_mx2_Scope_2::m_Length(){
  return this->m__0length;
}

void t_std_collections_Stack_1Tt_mx2_Scope_2::m_Insert(bbInt l_index,t_mx2_Scope* l_value){
  bbDebugAssert(((l_index>=bbInt(0))&&(l_index<=this->m__0length)),BB_T("Debug assert failed"));
  this->m_Reserve((this->m__0length+1));
  this->m__0data->copyTo(this->m__0data,l_index,(l_index+1),(this->m__0length-l_index));
  this->m__0data->at(l_index)=l_value;
  this->m__0length+=1;
  this->m__0seq+=1;
}

t_mx2_Scope* t_std_collections_Stack_1Tt_mx2_Scope_2::m_Get(bbInt l_index){
  bbDebugAssert(((l_index>=bbInt(0))&&(l_index<this->m__0length)),BB_T("Stack index out of range"));
  return this->m__0data->at(l_index);
}

bbInt t_std_collections_Stack_1Tt_mx2_Scope_2::m_FindLastIndex(t_mx2_Scope* l_value,bbInt l_start){
  bbDebugAssert(((l_start>=bbInt(0))&&(l_start<=this->m__0length)),BB_T("Debug assert failed"));
  bbInt l_i=this->m__0length;
  while((l_i>l_start)){
    l_i-=1;
    if((this->m__0data->at(l_i)==l_value)){
      return l_i;
    }
  }
  return -1;
}

bbInt t_std_collections_Stack_1Tt_mx2_Scope_2::m_FindIndex(t_mx2_Scope* l_value,bbInt l_start){
  bbDebugAssert(((l_start>=bbInt(0))&&(l_start<=this->m__0length)),BB_T("Debug assert failed"));
  bbInt l_i=l_start;
  while((l_i<this->m__0length)){
    if((this->m__0data->at(l_i)==l_value)){
      return l_i;
    }
    l_i+=1;
  }
  return -1;
}

void t_std_collections_Stack_1Tt_mx2_Scope_2::m_Erase(bbInt l_index1,bbInt l_index2){
  bbDebugAssert((((((l_index1>=bbInt(0))&&(l_index1<=this->m__0length))&&(l_index2>=bbInt(0)))&&(l_index2<=this->m__0length))&&(l_index1<=l_index2)),BB_T("Debug assert failed"));
  if((l_index1==this->m__0length)){
    return;
  }
  this->m__0data->copyTo(this->m__0data,l_index2,l_index1,(this->m__0length-l_index2));
  this->m_Resize(((this->m__0length-l_index2)+l_index1));
}

void t_std_collections_Stack_1Tt_mx2_Scope_2::m_Erase(bbInt l_index){
  bbDebugAssert(((l_index>=bbInt(0))&&(l_index<=this->m__0length)),BB_T("Debug assert failed"));
  if((l_index==this->m__0length)){
    return;
  }
  this->m__0data->copyTo(this->m__0data,(l_index+1),l_index,((this->m__0length-l_index)-1));
  this->m_Resize((this->m__0length-1));
}

bbBool t_std_collections_Stack_1Tt_mx2_Scope_2::m_Empty(){
  return (this->m__0length==bbInt(0));
}

bbArray<bbGCVar<t_mx2_Scope>>* t_std_collections_Stack_1Tt_mx2_Scope_2::m_Data(){
  return this->m__0data;
}

bbBool t_std_collections_Stack_1Tt_mx2_Scope_2::m_Contains(t_mx2_Scope* l_value){
  return (this->m_FindIndex(l_value,bbInt(0))!=-1);
}

void t_std_collections_Stack_1Tt_mx2_Scope_2::m_Clear(){
  this->m_Resize(bbInt(0));
}

bbInt t_std_collections_Stack_1Tt_mx2_Scope_2::m_Capacity(){
  return this->m__0data->length();
}

t_std_collections_Stack_1Tt_mx2_Scope_2_BackwardsIterator t_std_collections_Stack_1Tt_mx2_Scope_2::m_Backwards(){
  return t_std_collections_Stack_1Tt_mx2_Scope_2_BackwardsIterator(this,(this->m__0length-1));
}

t_std_collections_Stack_1Tt_mx2_Scope_2_Iterator t_std_collections_Stack_1Tt_mx2_Scope_2::m_All(){
  return t_std_collections_Stack_1Tt_mx2_Scope_2_Iterator(this,bbInt(0));
}

void t_std_collections_Stack_1Tt_mx2_Scope_2::m_AddAll(bbArray<bbGCVar<t_mx2_Scope>>* l_values){
  this->m_Reserve((this->m__0length+l_values->length()));
  l_values->copyTo(this->m__0data,bbInt(0),this->m__0length,l_values->length());
  this->m_Resize((this->m__0length+l_values->length()));
}

void t_std_collections_Stack_1Tt_mx2_Scope_2::m_Add(t_mx2_Scope* l_value){
  this->m_Reserve((this->m__0length+1));
  this->m__0data->at(this->m__0length)=l_value;
  this->m__0length+=1;
  this->m__0seq+=1;
}

t_std_collections_Stack_1Tt_mx2_SNode_2_Iterator::t_std_collections_Stack_1Tt_mx2_SNode_2_Iterator(t_std_collections_Stack_1Tt_mx2_SNode_2* l_stack,bbInt l_index){
  (*this).m__0stack=l_stack;
  (*this).m__0index=l_index;
  (*this).m__0seq=l_stack->m__0seq;
}

void t_std_collections_Stack_1Tt_mx2_SNode_2_Iterator::m_Insert(t_mx2_SNode* l_value){
  (*this).m_AssertSeq();
  (*this).m__0stack->m_Insert((*this).m__0index,l_value);
  (*this).m__0seq=(*this).m__0stack->m__0seq;
}

void t_std_collections_Stack_1Tt_mx2_SNode_2_Iterator::m_Erase(){
  (*this).m_AssertSeq();
  (*this).m__0stack->m_Erase((*this).m__0index);
  (*this).m__0seq=(*this).m__0stack->m__0seq;
}

void t_std_collections_Stack_1Tt_mx2_SNode_2_Iterator::m_Current(t_mx2_SNode* l_current){
  (*this).m_AssertCurrent();
  (*this).m__0stack->m__0data->at((*this).m__0index)=l_current;
}

t_mx2_SNode* t_std_collections_Stack_1Tt_mx2_SNode_2_Iterator::m_Current(){
  (*this).m_AssertCurrent();
  return (*this).m__0stack->m__0data->at((*this).m__0index);
}

void t_std_collections_Stack_1Tt_mx2_SNode_2_Iterator::m_Bump(){
  (*this).m_AssertCurrent();
  (*this).m__0index+=1;
}

bbBool t_std_collections_Stack_1Tt_mx2_SNode_2_Iterator::m_AtEnd(){
  (*this).m_AssertSeq();
  return ((*this).m__0index==(*this).m__0stack->m__0length);
}

void t_std_collections_Stack_1Tt_mx2_SNode_2_Iterator::m_AssertSeq(){
  bbDebugAssert(((*this).m__0seq==(*this).m__0stack->m__0seq),BB_T("Concurrent list modification"));
}

void t_std_collections_Stack_1Tt_mx2_SNode_2_Iterator::m_AssertCurrent(){
  bbDebugAssert(!(*this).m_AtEnd(),BB_T("Invalid list iterator"));
}

int bbCompare(const t_std_collections_Stack_1Tt_mx2_SNode_2_Iterator&x,const t_std_collections_Stack_1Tt_mx2_SNode_2_Iterator&y){
  if(int t=bbCompare(x.m__0stack,y.m__0stack)) return t;
  if(int t=bbCompare(x.m__0index,y.m__0index)) return t;
  if(int t=bbCompare(x.m__0seq,y.m__0seq)) return t;
  return 0;
}

void bbGCMark(const t_std_collections_Stack_1Tt_mx2_SNode_2_Iterator&t){
  bbGCMark(t.m__0stack);
}

t_std_collections_Stack_1Tt_mx2_SNode_2_BackwardsIterator::t_std_collections_Stack_1Tt_mx2_SNode_2_BackwardsIterator(t_std_collections_Stack_1Tt_mx2_SNode_2* l_stack,bbInt l_index){
  (*this).m__0stack=l_stack;
  (*this).m__0index=l_index;
  (*this).m__0seq=l_stack->m__0seq;
}

void t_std_collections_Stack_1Tt_mx2_SNode_2_BackwardsIterator::m_Insert(t_mx2_SNode* l_value){
  (*this).m_AssertSeq();
  (*this).m__0index+=1;
  (*this).m__0stack->m_Insert((*this).m__0index,l_value);
  (*this).m__0seq=(*this).m__0stack->m__0seq;
}

void t_std_collections_Stack_1Tt_mx2_SNode_2_BackwardsIterator::m_Erase(){
  (*this).m_AssertCurrent();
  (*this).m__0index-=1;
  (*this).m__0stack->m_Erase(((*this).m__0index+1));
  (*this).m__0seq=(*this).m__0stack->m__0seq;
}

void t_std_collections_Stack_1Tt_mx2_SNode_2_BackwardsIterator::m_Current(t_mx2_SNode* l_current){
  (*this).m_AssertCurrent();
  (*this).m__0stack->m__0data->at((*this).m__0index)=l_current;
}

t_mx2_SNode* t_std_collections_Stack_1Tt_mx2_SNode_2_BackwardsIterator::m_Current(){
  (*this).m_AssertCurrent();
  return (*this).m__0stack->m__0data->at((*this).m__0index);
}

void t_std_collections_Stack_1Tt_mx2_SNode_2_BackwardsIterator::m_Bump(){
  (*this).m_AssertCurrent();
  (*this).m__0index-=1;
}

bbBool t_std_collections_Stack_1Tt_mx2_SNode_2_BackwardsIterator::m_AtEnd(){
  (*this).m_AssertSeq();
  return ((*this).m__0index==-1);
}

void t_std_collections_Stack_1Tt_mx2_SNode_2_BackwardsIterator::m_AssertSeq(){
  bbDebugAssert(((*this).m__0seq==(*this).m__0stack->m__0seq),BB_T("Concurrent list modification"));
}

void t_std_collections_Stack_1Tt_mx2_SNode_2_BackwardsIterator::m_AssertCurrent(){
  bbDebugAssert(!(*this).m_AtEnd(),BB_T("Invalid list iterator"));
}

int bbCompare(const t_std_collections_Stack_1Tt_mx2_SNode_2_BackwardsIterator&x,const t_std_collections_Stack_1Tt_mx2_SNode_2_BackwardsIterator&y){
  if(int t=bbCompare(x.m__0stack,y.m__0stack)) return t;
  if(int t=bbCompare(x.m__0index,y.m__0index)) return t;
  if(int t=bbCompare(x.m__0seq,y.m__0seq)) return t;
  return 0;
}

void bbGCMark(const t_std_collections_Stack_1Tt_mx2_SNode_2_BackwardsIterator&t){
  bbGCMark(t.m__0stack);
}

void t_std_collections_Stack_1Tt_mx2_SNode_2::gcMark(){
  bbGCMark(m__0data);
}

t_std_collections_Stack_1Tt_mx2_SNode_2::t_std_collections_Stack_1Tt_mx2_SNode_2(t_std_collections_List_1Tt_mx2_SNode_2* l_values){
  g_std_collections_Stack_1Tt_mx2_SNode_2_AddAll_1Tt_std_collections_List_1Tt_mx2_SNode_2_2(this,l_values);
}

t_std_collections_Stack_1Tt_mx2_SNode_2::t_std_collections_Stack_1Tt_mx2_SNode_2(t_std_collections_Stack_1Tt_mx2_SNode_2* l_values){
  struct f0_t : public bbGCFrame{
    bbArray<bbGCVar<t_mx2_SNode>>* t0{};
    void gcMark(){
      bbGCMarkPtr(t0);
    }
  }f0{};
  this->m__0length=l_values->m_Length();
  this->m__0data=bbArray<bbGCVar<t_mx2_SNode>>::create(this->m__0length);
  (f0.t0=l_values->m_Data())->copyTo(this->m__0data,bbInt(0),bbInt(0),this->m__0length);
}

t_std_collections_Stack_1Tt_mx2_SNode_2::t_std_collections_Stack_1Tt_mx2_SNode_2(bbArray<bbGCVar<t_mx2_SNode>>* l_values){
  this->m_AddAll(l_values);
}

t_std_collections_Stack_1Tt_mx2_SNode_2::t_std_collections_Stack_1Tt_mx2_SNode_2(bbInt l_length){
  this->m__0length=l_length;
  this->m__0data=bbArray<bbGCVar<t_mx2_SNode>>::create(this->m__0length);
}

t_std_collections_Stack_1Tt_mx2_SNode_2::t_std_collections_Stack_1Tt_mx2_SNode_2(){
  this->m__0data=bbArray<bbGCVar<t_mx2_SNode>>::create(10);
}

void t_std_collections_Stack_1Tt_mx2_SNode_2::m__idxeq(bbInt l_index,t_mx2_SNode* l_value){
  bbDebugAssert(((l_index>=bbInt(0))&&(l_index<this->m__0length)),BB_T("Stack index out of range"));
  this->m__0data->at(l_index)=l_value;
}

t_mx2_SNode* t_std_collections_Stack_1Tt_mx2_SNode_2::m__idx(bbInt l_index){
  bbDebugAssert(((l_index>=bbInt(0))&&(l_index<this->m__0length)),BB_T("Stack index out of range"));
  return this->m__0data->at(l_index);
}

t_mx2_SNode* t_std_collections_Stack_1Tt_mx2_SNode_2::m_Top(){
  bbDebugAssert(bbBool(this->m__0length),BB_T("Stack is empty"));
  return this->m__0data->at((this->m__0length-1));
}

bbArray<bbGCVar<t_mx2_SNode>>* t_std_collections_Stack_1Tt_mx2_SNode_2::m_ToArray(){
  return this->m__0data->slice(bbInt(0),this->m__0length);
}

void t_std_collections_Stack_1Tt_mx2_SNode_2::m_Swap(bbInt l_index1,bbInt l_index2){
  struct f0_t : public bbGCFrame{
    t_mx2_SNode* l_t{};
    void gcMark(){
      bbGCMarkPtr(l_t);
    }
  }f0{};
  bbDebugAssert(((((l_index1>=bbInt(0))&&(l_index1<this->m__0length))&&(l_index2>=bbInt(0)))&&(l_index2<this->m__0length)),BB_T("Stack index out of range"));
  f0.l_t=this->m__0data->at(l_index1);
  this->m__0data->at(l_index1)=this->m__0data->at(l_index2);
  this->m__0data->at(l_index2)=f0.l_t;
}

void t_std_collections_Stack_1Tt_mx2_SNode_2::m_Sort(bbFunction<bbInt(t_mx2_SNode*,t_mx2_SNode*)> l_compareFunc,bbInt l_lo,bbInt l_hi){
  if((l_hi<=l_lo)){
    return;
  }
  if(((l_lo+1)==l_hi)){
    if((l_compareFunc(this->m__0data->at(l_hi),this->m__0data->at(l_lo))<bbInt(0))){
      this->m_Swap(l_hi,l_lo);
    }
    return;
  }
  bbInt l_i=((l_lo+l_hi)/2);
  if((l_compareFunc(this->m__0data->at(l_i),this->m__0data->at(l_lo))<bbInt(0))){
    this->m_Swap(l_i,l_lo);
  }
  if((l_compareFunc(this->m__0data->at(l_hi),this->m__0data->at(l_i))<bbInt(0))){
    this->m_Swap(l_hi,l_i);
    if((l_compareFunc(this->m__0data->at(l_i),this->m__0data->at(l_lo))<bbInt(0))){
      this->m_Swap(l_i,l_lo);
    }
  }
  bbInt l_x=(l_lo+1);
  bbInt l_y=(l_hi-1);
  do{
    struct f1_t : public bbGCFrame{
      t_mx2_SNode* l_p{};
      void gcMark(){
        bbGCMarkPtr(l_p);
      }
    }f1{};
    f1.l_p=this->m__0data->at(l_i);
    while((l_compareFunc(this->m__0data->at(l_x),f1.l_p)<bbInt(0))){
      l_x+=1;
    }
    while((l_compareFunc(f1.l_p,this->m__0data->at(l_y))<bbInt(0))){
      l_y-=1;
    }
    if((l_x>l_y)){
      break;
    }
    if((l_x<l_y)){
      this->m_Swap(l_x,l_y);
      if((l_i==l_x)){
        l_i=l_y;
      }else if((l_i==l_y)){
        l_i=l_x;
      }
    }
    l_x+=1;
    l_y-=1;
  }while(!((l_x>l_y)));
  this->m_Sort(l_compareFunc,l_lo,l_y);
  this->m_Sort(l_compareFunc,l_x,l_hi);
}

void t_std_collections_Stack_1Tt_mx2_SNode_2::m_Sort(bbFunction<bbInt(t_mx2_SNode*,t_mx2_SNode*)> l_compareFunc){
  this->m_Sort(l_compareFunc,bbInt(0),(this->m__0length-1));
}

void t_std_collections_Stack_1Tt_mx2_SNode_2::m_Sort(bbBool l_ascending){
  if(l_ascending){
    struct lambda10 : public bbFunction<bbInt(t_mx2_SNode*,t_mx2_SNode*)>::Rep{
      t_std_collections_Stack_1Tt_mx2_SNode_2* l_self;
      lambda10(t_std_collections_Stack_1Tt_mx2_SNode_2* l_self):l_self(l_self){
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
      t_std_collections_Stack_1Tt_mx2_SNode_2* l_self;
      lambda11(t_std_collections_Stack_1Tt_mx2_SNode_2* l_self):l_self(l_self){
      }
      bbInt invoke(t_mx2_SNode* l_x,t_mx2_SNode* l_y){
        return bbCompare(l_y,l_x);
      }
      void gcMark(){
        bbGCMarkPtr(l_self);
      }
    };
    this->m_Sort(bbFunction<bbInt(t_mx2_SNode*,t_mx2_SNode*)>(new lambda11(this)));
  }
}

t_std_collections_Stack_1Tt_mx2_SNode_2* t_std_collections_Stack_1Tt_mx2_SNode_2::m_Slice(bbInt l_index1,bbInt l_index2){
  struct f0_t : public bbGCFrame{
    bbArray<bbGCVar<t_mx2_SNode>>* t0{};
    void gcMark(){
      bbGCMarkPtr(t0);
    }
  }f0{};
  if((l_index1<bbInt(0))){
    l_index1=g_monkey_math_Max_1i((l_index1+this->m__0length),bbInt(0));
  }else if((l_index1>this->m__0length)){
    l_index1=this->m__0length;
  }
  if((l_index2<bbInt(0))){
    l_index2=g_monkey_math_Max_1i((l_index2+this->m__0length),l_index1);
  }else if((l_index2>this->m__0length)){
    l_index2=this->m__0length;
  }else if((l_index2<l_index1)){
    l_index2=l_index1;
  }
  return bbGCNew<t_std_collections_Stack_1Tt_mx2_SNode_2>(f0.t0=this->m__0data->slice(l_index1,l_index2));
}

t_std_collections_Stack_1Tt_mx2_SNode_2* t_std_collections_Stack_1Tt_mx2_SNode_2::m_Slice(bbInt l_index){
  return this->m_Slice(l_index,this->m__0length);
}

void t_std_collections_Stack_1Tt_mx2_SNode_2::m_Set(bbInt l_index,t_mx2_SNode* l_value){
  bbDebugAssert(((l_index>=bbInt(0))&&(l_index<this->m__0length)),BB_T("Stack index out of range"));
  this->m__0data->at(l_index)=l_value;
}

void t_std_collections_Stack_1Tt_mx2_SNode_2::m_Resize(bbInt l_length){
  bbDebugAssert((l_length>=bbInt(0)),BB_T("Debug assert failed"));
  {
    bbInt l_i=l_length;
    for(;(l_i<this->m__0length);l_i+=1){
      this->m__0data->at(l_i)=((t_mx2_SNode*)0);
    }
  }
  this->m_Reserve(l_length);
  this->m__0length=l_length;
  this->m__0seq+=1;
}

void t_std_collections_Stack_1Tt_mx2_SNode_2::m_Reserve(bbInt l_capacity){
  struct f0_t : public bbGCFrame{
    bbArray<bbGCVar<t_mx2_SNode>>* l_data{};
    void gcMark(){
      bbGCMarkPtr(l_data);
    }
  }f0{};
  bbDebugAssert((l_capacity>=bbInt(0)),BB_T("Debug assert failed"));
  if((this->m__0data->length()>=l_capacity)){
    return;
  }
  l_capacity=g_monkey_math_Max_1i(((this->m__0length*2)+this->m__0length),l_capacity);
  f0.l_data=bbArray<bbGCVar<t_mx2_SNode>>::create(l_capacity);
  this->m__0data->copyTo(f0.l_data,bbInt(0),bbInt(0),this->m__0length);
  this->m__0data=f0.l_data;
}

bbBool t_std_collections_Stack_1Tt_mx2_SNode_2::m_RemoveLast(t_mx2_SNode* l_value,bbInt l_start){
  bbInt l_i=this->m_FindLastIndex(l_value,l_start);
  if((l_i==-1)){
    return false;
  }
  this->m_Erase(l_i);
  return true;
}

bbInt t_std_collections_Stack_1Tt_mx2_SNode_2::m_RemoveEach(t_mx2_SNode* l_value){
  bbInt l_put=bbInt(0);
  bbInt l_n=bbInt(0);
  {
    bbInt l_get=bbInt(0);
    for(;(l_get<this->m__0length);l_get+=1){
      if((this->m__0data->at(l_get)==l_value)){
        l_n+=1;
        continue;
      }
      this->m__0data->at(l_put)=this->m__0data->at(l_get);
      l_put+=1;
    }
  }
  this->m_Resize(l_put);
  return l_n;
}

bbBool t_std_collections_Stack_1Tt_mx2_SNode_2::m_Remove(t_mx2_SNode* l_value,bbInt l_start){
  bbInt l_i=this->m_FindIndex(l_value,l_start);
  if((l_i==-1)){
    return false;
  }
  this->m_Erase(l_i);
  return true;
}

void t_std_collections_Stack_1Tt_mx2_SNode_2::m_Push(t_mx2_SNode* l_value){
  this->m_Add(l_value);
}

t_mx2_SNode* t_std_collections_Stack_1Tt_mx2_SNode_2::m_Pop(){
  struct f0_t : public bbGCFrame{
    t_mx2_SNode* l_value{};
    void gcMark(){
      bbGCMarkPtr(l_value);
    }
  }f0{};
  bbDebugAssert(bbBool(this->m__0length),BB_T("Stack is empty"));
  this->m__0length-=1;
  this->m__0seq+=1;
  f0.l_value=this->m__0data->at(this->m__0length);
  this->m__0data->at(this->m__0length)=((t_mx2_SNode*)0);
  return f0.l_value;
}

bbInt t_std_collections_Stack_1Tt_mx2_SNode_2::m_Length(){
  return this->m__0length;
}

void t_std_collections_Stack_1Tt_mx2_SNode_2::m_Insert(bbInt l_index,t_mx2_SNode* l_value){
  bbDebugAssert(((l_index>=bbInt(0))&&(l_index<=this->m__0length)),BB_T("Debug assert failed"));
  this->m_Reserve((this->m__0length+1));
  this->m__0data->copyTo(this->m__0data,l_index,(l_index+1),(this->m__0length-l_index));
  this->m__0data->at(l_index)=l_value;
  this->m__0length+=1;
  this->m__0seq+=1;
}

t_mx2_SNode* t_std_collections_Stack_1Tt_mx2_SNode_2::m_Get(bbInt l_index){
  bbDebugAssert(((l_index>=bbInt(0))&&(l_index<this->m__0length)),BB_T("Stack index out of range"));
  return this->m__0data->at(l_index);
}

bbInt t_std_collections_Stack_1Tt_mx2_SNode_2::m_FindLastIndex(t_mx2_SNode* l_value,bbInt l_start){
  bbDebugAssert(((l_start>=bbInt(0))&&(l_start<=this->m__0length)),BB_T("Debug assert failed"));
  bbInt l_i=this->m__0length;
  while((l_i>l_start)){
    l_i-=1;
    if((this->m__0data->at(l_i)==l_value)){
      return l_i;
    }
  }
  return -1;
}

bbInt t_std_collections_Stack_1Tt_mx2_SNode_2::m_FindIndex(t_mx2_SNode* l_value,bbInt l_start){
  bbDebugAssert(((l_start>=bbInt(0))&&(l_start<=this->m__0length)),BB_T("Debug assert failed"));
  bbInt l_i=l_start;
  while((l_i<this->m__0length)){
    if((this->m__0data->at(l_i)==l_value)){
      return l_i;
    }
    l_i+=1;
  }
  return -1;
}

void t_std_collections_Stack_1Tt_mx2_SNode_2::m_Erase(bbInt l_index1,bbInt l_index2){
  bbDebugAssert((((((l_index1>=bbInt(0))&&(l_index1<=this->m__0length))&&(l_index2>=bbInt(0)))&&(l_index2<=this->m__0length))&&(l_index1<=l_index2)),BB_T("Debug assert failed"));
  if((l_index1==this->m__0length)){
    return;
  }
  this->m__0data->copyTo(this->m__0data,l_index2,l_index1,(this->m__0length-l_index2));
  this->m_Resize(((this->m__0length-l_index2)+l_index1));
}

void t_std_collections_Stack_1Tt_mx2_SNode_2::m_Erase(bbInt l_index){
  bbDebugAssert(((l_index>=bbInt(0))&&(l_index<=this->m__0length)),BB_T("Debug assert failed"));
  if((l_index==this->m__0length)){
    return;
  }
  this->m__0data->copyTo(this->m__0data,(l_index+1),l_index,((this->m__0length-l_index)-1));
  this->m_Resize((this->m__0length-1));
}

bbBool t_std_collections_Stack_1Tt_mx2_SNode_2::m_Empty(){
  return (this->m__0length==bbInt(0));
}

bbArray<bbGCVar<t_mx2_SNode>>* t_std_collections_Stack_1Tt_mx2_SNode_2::m_Data(){
  return this->m__0data;
}

bbBool t_std_collections_Stack_1Tt_mx2_SNode_2::m_Contains(t_mx2_SNode* l_value){
  return (this->m_FindIndex(l_value,bbInt(0))!=-1);
}

void t_std_collections_Stack_1Tt_mx2_SNode_2::m_Clear(){
  this->m_Resize(bbInt(0));
}

bbInt t_std_collections_Stack_1Tt_mx2_SNode_2::m_Capacity(){
  return this->m__0data->length();
}

t_std_collections_Stack_1Tt_mx2_SNode_2_BackwardsIterator t_std_collections_Stack_1Tt_mx2_SNode_2::m_Backwards(){
  return t_std_collections_Stack_1Tt_mx2_SNode_2_BackwardsIterator(this,(this->m__0length-1));
}

t_std_collections_Stack_1Tt_mx2_SNode_2_Iterator t_std_collections_Stack_1Tt_mx2_SNode_2::m_All(){
  return t_std_collections_Stack_1Tt_mx2_SNode_2_Iterator(this,bbInt(0));
}

void t_std_collections_Stack_1Tt_mx2_SNode_2::m_AddAll(bbArray<bbGCVar<t_mx2_SNode>>* l_values){
  this->m_Reserve((this->m__0length+l_values->length()));
  l_values->copyTo(this->m__0data,bbInt(0),this->m__0length,l_values->length());
  this->m_Resize((this->m__0length+l_values->length()));
}

void t_std_collections_Stack_1Tt_mx2_SNode_2::m_Add(t_mx2_SNode* l_value){
  this->m_Reserve((this->m__0length+1));
  this->m__0data->at(this->m__0length)=l_value;
  this->m__0length+=1;
  this->m__0seq+=1;
}

t_std_collections_Stack_1Tt_mx2_VarValue_2_Iterator::t_std_collections_Stack_1Tt_mx2_VarValue_2_Iterator(t_std_collections_Stack_1Tt_mx2_VarValue_2* l_stack,bbInt l_index){
  (*this).m__0stack=l_stack;
  (*this).m__0index=l_index;
  (*this).m__0seq=l_stack->m__0seq;
}

void t_std_collections_Stack_1Tt_mx2_VarValue_2_Iterator::m_Insert(t_mx2_VarValue* l_value){
  (*this).m_AssertSeq();
  (*this).m__0stack->m_Insert((*this).m__0index,l_value);
  (*this).m__0seq=(*this).m__0stack->m__0seq;
}

void t_std_collections_Stack_1Tt_mx2_VarValue_2_Iterator::m_Erase(){
  (*this).m_AssertSeq();
  (*this).m__0stack->m_Erase((*this).m__0index);
  (*this).m__0seq=(*this).m__0stack->m__0seq;
}

void t_std_collections_Stack_1Tt_mx2_VarValue_2_Iterator::m_Current(t_mx2_VarValue* l_current){
  (*this).m_AssertCurrent();
  (*this).m__0stack->m__0data->at((*this).m__0index)=l_current;
}

t_mx2_VarValue* t_std_collections_Stack_1Tt_mx2_VarValue_2_Iterator::m_Current(){
  (*this).m_AssertCurrent();
  return (*this).m__0stack->m__0data->at((*this).m__0index);
}

void t_std_collections_Stack_1Tt_mx2_VarValue_2_Iterator::m_Bump(){
  (*this).m_AssertCurrent();
  (*this).m__0index+=1;
}

bbBool t_std_collections_Stack_1Tt_mx2_VarValue_2_Iterator::m_AtEnd(){
  (*this).m_AssertSeq();
  return ((*this).m__0index==(*this).m__0stack->m__0length);
}

void t_std_collections_Stack_1Tt_mx2_VarValue_2_Iterator::m_AssertSeq(){
  bbDebugAssert(((*this).m__0seq==(*this).m__0stack->m__0seq),BB_T("Concurrent list modification"));
}

void t_std_collections_Stack_1Tt_mx2_VarValue_2_Iterator::m_AssertCurrent(){
  bbDebugAssert(!(*this).m_AtEnd(),BB_T("Invalid list iterator"));
}

int bbCompare(const t_std_collections_Stack_1Tt_mx2_VarValue_2_Iterator&x,const t_std_collections_Stack_1Tt_mx2_VarValue_2_Iterator&y){
  if(int t=bbCompare(x.m__0stack,y.m__0stack)) return t;
  if(int t=bbCompare(x.m__0index,y.m__0index)) return t;
  if(int t=bbCompare(x.m__0seq,y.m__0seq)) return t;
  return 0;
}

void bbGCMark(const t_std_collections_Stack_1Tt_mx2_VarValue_2_Iterator&t){
  bbGCMark(t.m__0stack);
}

t_std_collections_Stack_1Tt_mx2_VarValue_2_BackwardsIterator::t_std_collections_Stack_1Tt_mx2_VarValue_2_BackwardsIterator(t_std_collections_Stack_1Tt_mx2_VarValue_2* l_stack,bbInt l_index){
  (*this).m__0stack=l_stack;
  (*this).m__0index=l_index;
  (*this).m__0seq=l_stack->m__0seq;
}

void t_std_collections_Stack_1Tt_mx2_VarValue_2_BackwardsIterator::m_Insert(t_mx2_VarValue* l_value){
  (*this).m_AssertSeq();
  (*this).m__0index+=1;
  (*this).m__0stack->m_Insert((*this).m__0index,l_value);
  (*this).m__0seq=(*this).m__0stack->m__0seq;
}

void t_std_collections_Stack_1Tt_mx2_VarValue_2_BackwardsIterator::m_Erase(){
  (*this).m_AssertCurrent();
  (*this).m__0index-=1;
  (*this).m__0stack->m_Erase(((*this).m__0index+1));
  (*this).m__0seq=(*this).m__0stack->m__0seq;
}

void t_std_collections_Stack_1Tt_mx2_VarValue_2_BackwardsIterator::m_Current(t_mx2_VarValue* l_current){
  (*this).m_AssertCurrent();
  (*this).m__0stack->m__0data->at((*this).m__0index)=l_current;
}

t_mx2_VarValue* t_std_collections_Stack_1Tt_mx2_VarValue_2_BackwardsIterator::m_Current(){
  (*this).m_AssertCurrent();
  return (*this).m__0stack->m__0data->at((*this).m__0index);
}

void t_std_collections_Stack_1Tt_mx2_VarValue_2_BackwardsIterator::m_Bump(){
  (*this).m_AssertCurrent();
  (*this).m__0index-=1;
}

bbBool t_std_collections_Stack_1Tt_mx2_VarValue_2_BackwardsIterator::m_AtEnd(){
  (*this).m_AssertSeq();
  return ((*this).m__0index==-1);
}

void t_std_collections_Stack_1Tt_mx2_VarValue_2_BackwardsIterator::m_AssertSeq(){
  bbDebugAssert(((*this).m__0seq==(*this).m__0stack->m__0seq),BB_T("Concurrent list modification"));
}

void t_std_collections_Stack_1Tt_mx2_VarValue_2_BackwardsIterator::m_AssertCurrent(){
  bbDebugAssert(!(*this).m_AtEnd(),BB_T("Invalid list iterator"));
}

int bbCompare(const t_std_collections_Stack_1Tt_mx2_VarValue_2_BackwardsIterator&x,const t_std_collections_Stack_1Tt_mx2_VarValue_2_BackwardsIterator&y){
  if(int t=bbCompare(x.m__0stack,y.m__0stack)) return t;
  if(int t=bbCompare(x.m__0index,y.m__0index)) return t;
  if(int t=bbCompare(x.m__0seq,y.m__0seq)) return t;
  return 0;
}

void bbGCMark(const t_std_collections_Stack_1Tt_mx2_VarValue_2_BackwardsIterator&t){
  bbGCMark(t.m__0stack);
}

void t_std_collections_Stack_1Tt_mx2_VarValue_2::gcMark(){
  bbGCMark(m__0data);
}

t_std_collections_Stack_1Tt_mx2_VarValue_2::t_std_collections_Stack_1Tt_mx2_VarValue_2(t_std_collections_List_1Tt_mx2_VarValue_2* l_values){
  g_std_collections_Stack_1Tt_mx2_VarValue_2_AddAll_1Tt_std_collections_List_1Tt_mx2_VarValue_2_2(this,l_values);
}

t_std_collections_Stack_1Tt_mx2_VarValue_2::t_std_collections_Stack_1Tt_mx2_VarValue_2(t_std_collections_Stack_1Tt_mx2_VarValue_2* l_values){
  struct f0_t : public bbGCFrame{
    bbArray<bbGCVar<t_mx2_VarValue>>* t0{};
    void gcMark(){
      bbGCMarkPtr(t0);
    }
  }f0{};
  this->m__0length=l_values->m_Length();
  this->m__0data=bbArray<bbGCVar<t_mx2_VarValue>>::create(this->m__0length);
  (f0.t0=l_values->m_Data())->copyTo(this->m__0data,bbInt(0),bbInt(0),this->m__0length);
}

t_std_collections_Stack_1Tt_mx2_VarValue_2::t_std_collections_Stack_1Tt_mx2_VarValue_2(bbArray<bbGCVar<t_mx2_VarValue>>* l_values){
  this->m_AddAll(l_values);
}

t_std_collections_Stack_1Tt_mx2_VarValue_2::t_std_collections_Stack_1Tt_mx2_VarValue_2(bbInt l_length){
  this->m__0length=l_length;
  this->m__0data=bbArray<bbGCVar<t_mx2_VarValue>>::create(this->m__0length);
}

t_std_collections_Stack_1Tt_mx2_VarValue_2::t_std_collections_Stack_1Tt_mx2_VarValue_2(){
  this->m__0data=bbArray<bbGCVar<t_mx2_VarValue>>::create(10);
}

void t_std_collections_Stack_1Tt_mx2_VarValue_2::m__idxeq(bbInt l_index,t_mx2_VarValue* l_value){
  bbDebugAssert(((l_index>=bbInt(0))&&(l_index<this->m__0length)),BB_T("Stack index out of range"));
  this->m__0data->at(l_index)=l_value;
}

t_mx2_VarValue* t_std_collections_Stack_1Tt_mx2_VarValue_2::m__idx(bbInt l_index){
  bbDebugAssert(((l_index>=bbInt(0))&&(l_index<this->m__0length)),BB_T("Stack index out of range"));
  return this->m__0data->at(l_index);
}

t_mx2_VarValue* t_std_collections_Stack_1Tt_mx2_VarValue_2::m_Top(){
  bbDebugAssert(bbBool(this->m__0length),BB_T("Stack is empty"));
  return this->m__0data->at((this->m__0length-1));
}

bbArray<bbGCVar<t_mx2_VarValue>>* t_std_collections_Stack_1Tt_mx2_VarValue_2::m_ToArray(){
  return this->m__0data->slice(bbInt(0),this->m__0length);
}

void t_std_collections_Stack_1Tt_mx2_VarValue_2::m_Swap(bbInt l_index1,bbInt l_index2){
  struct f0_t : public bbGCFrame{
    t_mx2_VarValue* l_t{};
    void gcMark(){
      bbGCMarkPtr(l_t);
    }
  }f0{};
  bbDebugAssert(((((l_index1>=bbInt(0))&&(l_index1<this->m__0length))&&(l_index2>=bbInt(0)))&&(l_index2<this->m__0length)),BB_T("Stack index out of range"));
  f0.l_t=this->m__0data->at(l_index1);
  this->m__0data->at(l_index1)=this->m__0data->at(l_index2);
  this->m__0data->at(l_index2)=f0.l_t;
}

void t_std_collections_Stack_1Tt_mx2_VarValue_2::m_Sort(bbFunction<bbInt(t_mx2_VarValue*,t_mx2_VarValue*)> l_compareFunc,bbInt l_lo,bbInt l_hi){
  if((l_hi<=l_lo)){
    return;
  }
  if(((l_lo+1)==l_hi)){
    if((l_compareFunc(this->m__0data->at(l_hi),this->m__0data->at(l_lo))<bbInt(0))){
      this->m_Swap(l_hi,l_lo);
    }
    return;
  }
  bbInt l_i=((l_lo+l_hi)/2);
  if((l_compareFunc(this->m__0data->at(l_i),this->m__0data->at(l_lo))<bbInt(0))){
    this->m_Swap(l_i,l_lo);
  }
  if((l_compareFunc(this->m__0data->at(l_hi),this->m__0data->at(l_i))<bbInt(0))){
    this->m_Swap(l_hi,l_i);
    if((l_compareFunc(this->m__0data->at(l_i),this->m__0data->at(l_lo))<bbInt(0))){
      this->m_Swap(l_i,l_lo);
    }
  }
  bbInt l_x=(l_lo+1);
  bbInt l_y=(l_hi-1);
  do{
    struct f1_t : public bbGCFrame{
      t_mx2_VarValue* l_p{};
      void gcMark(){
        bbGCMarkPtr(l_p);
      }
    }f1{};
    f1.l_p=this->m__0data->at(l_i);
    while((l_compareFunc(this->m__0data->at(l_x),f1.l_p)<bbInt(0))){
      l_x+=1;
    }
    while((l_compareFunc(f1.l_p,this->m__0data->at(l_y))<bbInt(0))){
      l_y-=1;
    }
    if((l_x>l_y)){
      break;
    }
    if((l_x<l_y)){
      this->m_Swap(l_x,l_y);
      if((l_i==l_x)){
        l_i=l_y;
      }else if((l_i==l_y)){
        l_i=l_x;
      }
    }
    l_x+=1;
    l_y-=1;
  }while(!((l_x>l_y)));
  this->m_Sort(l_compareFunc,l_lo,l_y);
  this->m_Sort(l_compareFunc,l_x,l_hi);
}

void t_std_collections_Stack_1Tt_mx2_VarValue_2::m_Sort(bbFunction<bbInt(t_mx2_VarValue*,t_mx2_VarValue*)> l_compareFunc){
  this->m_Sort(l_compareFunc,bbInt(0),(this->m__0length-1));
}

void t_std_collections_Stack_1Tt_mx2_VarValue_2::m_Sort(bbBool l_ascending){
  if(l_ascending){
    struct lambda12 : public bbFunction<bbInt(t_mx2_VarValue*,t_mx2_VarValue*)>::Rep{
      t_std_collections_Stack_1Tt_mx2_VarValue_2* l_self;
      lambda12(t_std_collections_Stack_1Tt_mx2_VarValue_2* l_self):l_self(l_self){
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
      t_std_collections_Stack_1Tt_mx2_VarValue_2* l_self;
      lambda13(t_std_collections_Stack_1Tt_mx2_VarValue_2* l_self):l_self(l_self){
      }
      bbInt invoke(t_mx2_VarValue* l_x,t_mx2_VarValue* l_y){
        return bbCompare(l_y,l_x);
      }
      void gcMark(){
        bbGCMarkPtr(l_self);
      }
    };
    this->m_Sort(bbFunction<bbInt(t_mx2_VarValue*,t_mx2_VarValue*)>(new lambda13(this)));
  }
}

t_std_collections_Stack_1Tt_mx2_VarValue_2* t_std_collections_Stack_1Tt_mx2_VarValue_2::m_Slice(bbInt l_index1,bbInt l_index2){
  struct f0_t : public bbGCFrame{
    bbArray<bbGCVar<t_mx2_VarValue>>* t0{};
    void gcMark(){
      bbGCMarkPtr(t0);
    }
  }f0{};
  if((l_index1<bbInt(0))){
    l_index1=g_monkey_math_Max_1i((l_index1+this->m__0length),bbInt(0));
  }else if((l_index1>this->m__0length)){
    l_index1=this->m__0length;
  }
  if((l_index2<bbInt(0))){
    l_index2=g_monkey_math_Max_1i((l_index2+this->m__0length),l_index1);
  }else if((l_index2>this->m__0length)){
    l_index2=this->m__0length;
  }else if((l_index2<l_index1)){
    l_index2=l_index1;
  }
  return bbGCNew<t_std_collections_Stack_1Tt_mx2_VarValue_2>(f0.t0=this->m__0data->slice(l_index1,l_index2));
}

t_std_collections_Stack_1Tt_mx2_VarValue_2* t_std_collections_Stack_1Tt_mx2_VarValue_2::m_Slice(bbInt l_index){
  return this->m_Slice(l_index,this->m__0length);
}

void t_std_collections_Stack_1Tt_mx2_VarValue_2::m_Set(bbInt l_index,t_mx2_VarValue* l_value){
  bbDebugAssert(((l_index>=bbInt(0))&&(l_index<this->m__0length)),BB_T("Stack index out of range"));
  this->m__0data->at(l_index)=l_value;
}

void t_std_collections_Stack_1Tt_mx2_VarValue_2::m_Resize(bbInt l_length){
  bbDebugAssert((l_length>=bbInt(0)),BB_T("Debug assert failed"));
  {
    bbInt l_i=l_length;
    for(;(l_i<this->m__0length);l_i+=1){
      this->m__0data->at(l_i)=((t_mx2_VarValue*)0);
    }
  }
  this->m_Reserve(l_length);
  this->m__0length=l_length;
  this->m__0seq+=1;
}

void t_std_collections_Stack_1Tt_mx2_VarValue_2::m_Reserve(bbInt l_capacity){
  struct f0_t : public bbGCFrame{
    bbArray<bbGCVar<t_mx2_VarValue>>* l_data{};
    void gcMark(){
      bbGCMarkPtr(l_data);
    }
  }f0{};
  bbDebugAssert((l_capacity>=bbInt(0)),BB_T("Debug assert failed"));
  if((this->m__0data->length()>=l_capacity)){
    return;
  }
  l_capacity=g_monkey_math_Max_1i(((this->m__0length*2)+this->m__0length),l_capacity);
  f0.l_data=bbArray<bbGCVar<t_mx2_VarValue>>::create(l_capacity);
  this->m__0data->copyTo(f0.l_data,bbInt(0),bbInt(0),this->m__0length);
  this->m__0data=f0.l_data;
}

bbBool t_std_collections_Stack_1Tt_mx2_VarValue_2::m_RemoveLast(t_mx2_VarValue* l_value,bbInt l_start){
  bbInt l_i=this->m_FindLastIndex(l_value,l_start);
  if((l_i==-1)){
    return false;
  }
  this->m_Erase(l_i);
  return true;
}

bbInt t_std_collections_Stack_1Tt_mx2_VarValue_2::m_RemoveEach(t_mx2_VarValue* l_value){
  bbInt l_put=bbInt(0);
  bbInt l_n=bbInt(0);
  {
    bbInt l_get=bbInt(0);
    for(;(l_get<this->m__0length);l_get+=1){
      if((this->m__0data->at(l_get)==l_value)){
        l_n+=1;
        continue;
      }
      this->m__0data->at(l_put)=this->m__0data->at(l_get);
      l_put+=1;
    }
  }
  this->m_Resize(l_put);
  return l_n;
}

bbBool t_std_collections_Stack_1Tt_mx2_VarValue_2::m_Remove(t_mx2_VarValue* l_value,bbInt l_start){
  bbInt l_i=this->m_FindIndex(l_value,l_start);
  if((l_i==-1)){
    return false;
  }
  this->m_Erase(l_i);
  return true;
}

void t_std_collections_Stack_1Tt_mx2_VarValue_2::m_Push(t_mx2_VarValue* l_value){
  this->m_Add(l_value);
}

t_mx2_VarValue* t_std_collections_Stack_1Tt_mx2_VarValue_2::m_Pop(){
  struct f0_t : public bbGCFrame{
    t_mx2_VarValue* l_value{};
    void gcMark(){
      bbGCMarkPtr(l_value);
    }
  }f0{};
  bbDebugAssert(bbBool(this->m__0length),BB_T("Stack is empty"));
  this->m__0length-=1;
  this->m__0seq+=1;
  f0.l_value=this->m__0data->at(this->m__0length);
  this->m__0data->at(this->m__0length)=((t_mx2_VarValue*)0);
  return f0.l_value;
}

bbInt t_std_collections_Stack_1Tt_mx2_VarValue_2::m_Length(){
  return this->m__0length;
}

void t_std_collections_Stack_1Tt_mx2_VarValue_2::m_Insert(bbInt l_index,t_mx2_VarValue* l_value){
  bbDebugAssert(((l_index>=bbInt(0))&&(l_index<=this->m__0length)),BB_T("Debug assert failed"));
  this->m_Reserve((this->m__0length+1));
  this->m__0data->copyTo(this->m__0data,l_index,(l_index+1),(this->m__0length-l_index));
  this->m__0data->at(l_index)=l_value;
  this->m__0length+=1;
  this->m__0seq+=1;
}

t_mx2_VarValue* t_std_collections_Stack_1Tt_mx2_VarValue_2::m_Get(bbInt l_index){
  bbDebugAssert(((l_index>=bbInt(0))&&(l_index<this->m__0length)),BB_T("Stack index out of range"));
  return this->m__0data->at(l_index);
}

bbInt t_std_collections_Stack_1Tt_mx2_VarValue_2::m_FindLastIndex(t_mx2_VarValue* l_value,bbInt l_start){
  bbDebugAssert(((l_start>=bbInt(0))&&(l_start<=this->m__0length)),BB_T("Debug assert failed"));
  bbInt l_i=this->m__0length;
  while((l_i>l_start)){
    l_i-=1;
    if((this->m__0data->at(l_i)==l_value)){
      return l_i;
    }
  }
  return -1;
}

bbInt t_std_collections_Stack_1Tt_mx2_VarValue_2::m_FindIndex(t_mx2_VarValue* l_value,bbInt l_start){
  bbDebugAssert(((l_start>=bbInt(0))&&(l_start<=this->m__0length)),BB_T("Debug assert failed"));
  bbInt l_i=l_start;
  while((l_i<this->m__0length)){
    if((this->m__0data->at(l_i)==l_value)){
      return l_i;
    }
    l_i+=1;
  }
  return -1;
}

void t_std_collections_Stack_1Tt_mx2_VarValue_2::m_Erase(bbInt l_index1,bbInt l_index2){
  bbDebugAssert((((((l_index1>=bbInt(0))&&(l_index1<=this->m__0length))&&(l_index2>=bbInt(0)))&&(l_index2<=this->m__0length))&&(l_index1<=l_index2)),BB_T("Debug assert failed"));
  if((l_index1==this->m__0length)){
    return;
  }
  this->m__0data->copyTo(this->m__0data,l_index2,l_index1,(this->m__0length-l_index2));
  this->m_Resize(((this->m__0length-l_index2)+l_index1));
}

void t_std_collections_Stack_1Tt_mx2_VarValue_2::m_Erase(bbInt l_index){
  bbDebugAssert(((l_index>=bbInt(0))&&(l_index<=this->m__0length)),BB_T("Debug assert failed"));
  if((l_index==this->m__0length)){
    return;
  }
  this->m__0data->copyTo(this->m__0data,(l_index+1),l_index,((this->m__0length-l_index)-1));
  this->m_Resize((this->m__0length-1));
}

bbBool t_std_collections_Stack_1Tt_mx2_VarValue_2::m_Empty(){
  return (this->m__0length==bbInt(0));
}

bbArray<bbGCVar<t_mx2_VarValue>>* t_std_collections_Stack_1Tt_mx2_VarValue_2::m_Data(){
  return this->m__0data;
}

bbBool t_std_collections_Stack_1Tt_mx2_VarValue_2::m_Contains(t_mx2_VarValue* l_value){
  return (this->m_FindIndex(l_value,bbInt(0))!=-1);
}

void t_std_collections_Stack_1Tt_mx2_VarValue_2::m_Clear(){
  this->m_Resize(bbInt(0));
}

bbInt t_std_collections_Stack_1Tt_mx2_VarValue_2::m_Capacity(){
  return this->m__0data->length();
}

t_std_collections_Stack_1Tt_mx2_VarValue_2_BackwardsIterator t_std_collections_Stack_1Tt_mx2_VarValue_2::m_Backwards(){
  return t_std_collections_Stack_1Tt_mx2_VarValue_2_BackwardsIterator(this,(this->m__0length-1));
}

t_std_collections_Stack_1Tt_mx2_VarValue_2_Iterator t_std_collections_Stack_1Tt_mx2_VarValue_2::m_All(){
  return t_std_collections_Stack_1Tt_mx2_VarValue_2_Iterator(this,bbInt(0));
}

void t_std_collections_Stack_1Tt_mx2_VarValue_2::m_AddAll(bbArray<bbGCVar<t_mx2_VarValue>>* l_values){
  this->m_Reserve((this->m__0length+l_values->length()));
  l_values->copyTo(this->m__0data,bbInt(0),this->m__0length,l_values->length());
  this->m_Resize((this->m__0length+l_values->length()));
}

void t_std_collections_Stack_1Tt_mx2_VarValue_2::m_Add(t_mx2_VarValue* l_value){
  this->m_Reserve((this->m__0length+1));
  this->m__0data->at(this->m__0length)=l_value;
  this->m__0length+=1;
  this->m__0seq+=1;
}

t_std_collections_Stack_1Tt_std_collections_Stack_1s_2_Iterator::t_std_collections_Stack_1Tt_std_collections_Stack_1s_2_Iterator(t_std_collections_Stack_1Tt_std_collections_Stack_1s_2* l_stack,bbInt l_index){
  (*this).m__0stack=l_stack;
  (*this).m__0index=l_index;
  (*this).m__0seq=l_stack->m__0seq;
}

void t_std_collections_Stack_1Tt_std_collections_Stack_1s_2_Iterator::m_Insert(t_std_collections_Stack_1s* l_value){
  (*this).m_AssertSeq();
  (*this).m__0stack->m_Insert((*this).m__0index,l_value);
  (*this).m__0seq=(*this).m__0stack->m__0seq;
}

void t_std_collections_Stack_1Tt_std_collections_Stack_1s_2_Iterator::m_Erase(){
  (*this).m_AssertSeq();
  (*this).m__0stack->m_Erase((*this).m__0index);
  (*this).m__0seq=(*this).m__0stack->m__0seq;
}

void t_std_collections_Stack_1Tt_std_collections_Stack_1s_2_Iterator::m_Current(t_std_collections_Stack_1s* l_current){
  (*this).m_AssertCurrent();
  (*this).m__0stack->m__0data->at((*this).m__0index)=l_current;
}

t_std_collections_Stack_1s* t_std_collections_Stack_1Tt_std_collections_Stack_1s_2_Iterator::m_Current(){
  (*this).m_AssertCurrent();
  return (*this).m__0stack->m__0data->at((*this).m__0index);
}

void t_std_collections_Stack_1Tt_std_collections_Stack_1s_2_Iterator::m_Bump(){
  (*this).m_AssertCurrent();
  (*this).m__0index+=1;
}

bbBool t_std_collections_Stack_1Tt_std_collections_Stack_1s_2_Iterator::m_AtEnd(){
  (*this).m_AssertSeq();
  return ((*this).m__0index==(*this).m__0stack->m__0length);
}

void t_std_collections_Stack_1Tt_std_collections_Stack_1s_2_Iterator::m_AssertSeq(){
  bbDebugAssert(((*this).m__0seq==(*this).m__0stack->m__0seq),BB_T("Concurrent list modification"));
}

void t_std_collections_Stack_1Tt_std_collections_Stack_1s_2_Iterator::m_AssertCurrent(){
  bbDebugAssert(!(*this).m_AtEnd(),BB_T("Invalid list iterator"));
}

int bbCompare(const t_std_collections_Stack_1Tt_std_collections_Stack_1s_2_Iterator&x,const t_std_collections_Stack_1Tt_std_collections_Stack_1s_2_Iterator&y){
  if(int t=bbCompare(x.m__0stack,y.m__0stack)) return t;
  if(int t=bbCompare(x.m__0index,y.m__0index)) return t;
  if(int t=bbCompare(x.m__0seq,y.m__0seq)) return t;
  return 0;
}

void bbGCMark(const t_std_collections_Stack_1Tt_std_collections_Stack_1s_2_Iterator&t){
  bbGCMark(t.m__0stack);
}

t_std_collections_Stack_1Tt_std_collections_Stack_1s_2_BackwardsIterator::t_std_collections_Stack_1Tt_std_collections_Stack_1s_2_BackwardsIterator(t_std_collections_Stack_1Tt_std_collections_Stack_1s_2* l_stack,bbInt l_index){
  (*this).m__0stack=l_stack;
  (*this).m__0index=l_index;
  (*this).m__0seq=l_stack->m__0seq;
}

void t_std_collections_Stack_1Tt_std_collections_Stack_1s_2_BackwardsIterator::m_Insert(t_std_collections_Stack_1s* l_value){
  (*this).m_AssertSeq();
  (*this).m__0index+=1;
  (*this).m__0stack->m_Insert((*this).m__0index,l_value);
  (*this).m__0seq=(*this).m__0stack->m__0seq;
}

void t_std_collections_Stack_1Tt_std_collections_Stack_1s_2_BackwardsIterator::m_Erase(){
  (*this).m_AssertCurrent();
  (*this).m__0index-=1;
  (*this).m__0stack->m_Erase(((*this).m__0index+1));
  (*this).m__0seq=(*this).m__0stack->m__0seq;
}

void t_std_collections_Stack_1Tt_std_collections_Stack_1s_2_BackwardsIterator::m_Current(t_std_collections_Stack_1s* l_current){
  (*this).m_AssertCurrent();
  (*this).m__0stack->m__0data->at((*this).m__0index)=l_current;
}

t_std_collections_Stack_1s* t_std_collections_Stack_1Tt_std_collections_Stack_1s_2_BackwardsIterator::m_Current(){
  (*this).m_AssertCurrent();
  return (*this).m__0stack->m__0data->at((*this).m__0index);
}

void t_std_collections_Stack_1Tt_std_collections_Stack_1s_2_BackwardsIterator::m_Bump(){
  (*this).m_AssertCurrent();
  (*this).m__0index-=1;
}

bbBool t_std_collections_Stack_1Tt_std_collections_Stack_1s_2_BackwardsIterator::m_AtEnd(){
  (*this).m_AssertSeq();
  return ((*this).m__0index==-1);
}

void t_std_collections_Stack_1Tt_std_collections_Stack_1s_2_BackwardsIterator::m_AssertSeq(){
  bbDebugAssert(((*this).m__0seq==(*this).m__0stack->m__0seq),BB_T("Concurrent list modification"));
}

void t_std_collections_Stack_1Tt_std_collections_Stack_1s_2_BackwardsIterator::m_AssertCurrent(){
  bbDebugAssert(!(*this).m_AtEnd(),BB_T("Invalid list iterator"));
}

int bbCompare(const t_std_collections_Stack_1Tt_std_collections_Stack_1s_2_BackwardsIterator&x,const t_std_collections_Stack_1Tt_std_collections_Stack_1s_2_BackwardsIterator&y){
  if(int t=bbCompare(x.m__0stack,y.m__0stack)) return t;
  if(int t=bbCompare(x.m__0index,y.m__0index)) return t;
  if(int t=bbCompare(x.m__0seq,y.m__0seq)) return t;
  return 0;
}

void bbGCMark(const t_std_collections_Stack_1Tt_std_collections_Stack_1s_2_BackwardsIterator&t){
  bbGCMark(t.m__0stack);
}

void t_std_collections_Stack_1Tt_std_collections_Stack_1s_2::gcMark(){
  bbGCMark(m__0data);
}

t_std_collections_Stack_1Tt_std_collections_Stack_1s_2::t_std_collections_Stack_1Tt_std_collections_Stack_1s_2(t_std_collections_List_1Tt_std_collections_Stack_1s_2* l_values){
  g_std_collections_Stack_1Tt_std_collections_Stack_1s_2_AddAll_1Tt_std_collections_List_1Tt_std_collections_Stack_1s_2_2(this,l_values);
}

t_std_collections_Stack_1Tt_std_collections_Stack_1s_2::t_std_collections_Stack_1Tt_std_collections_Stack_1s_2(t_std_collections_Stack_1Tt_std_collections_Stack_1s_2* l_values){
  struct f0_t : public bbGCFrame{
    bbArray<bbGCVar<t_std_collections_Stack_1s>>* t0{};
    void gcMark(){
      bbGCMarkPtr(t0);
    }
  }f0{};
  this->m__0length=l_values->m_Length();
  this->m__0data=bbArray<bbGCVar<t_std_collections_Stack_1s>>::create(this->m__0length);
  (f0.t0=l_values->m_Data())->copyTo(this->m__0data,bbInt(0),bbInt(0),this->m__0length);
}

t_std_collections_Stack_1Tt_std_collections_Stack_1s_2::t_std_collections_Stack_1Tt_std_collections_Stack_1s_2(bbArray<bbGCVar<t_std_collections_Stack_1s>>* l_values){
  this->m_AddAll(l_values);
}

t_std_collections_Stack_1Tt_std_collections_Stack_1s_2::t_std_collections_Stack_1Tt_std_collections_Stack_1s_2(bbInt l_length){
  this->m__0length=l_length;
  this->m__0data=bbArray<bbGCVar<t_std_collections_Stack_1s>>::create(this->m__0length);
}

t_std_collections_Stack_1Tt_std_collections_Stack_1s_2::t_std_collections_Stack_1Tt_std_collections_Stack_1s_2(){
  this->m__0data=bbArray<bbGCVar<t_std_collections_Stack_1s>>::create(10);
}

void t_std_collections_Stack_1Tt_std_collections_Stack_1s_2::m__idxeq(bbInt l_index,t_std_collections_Stack_1s* l_value){
  bbDebugAssert(((l_index>=bbInt(0))&&(l_index<this->m__0length)),BB_T("Stack index out of range"));
  this->m__0data->at(l_index)=l_value;
}

t_std_collections_Stack_1s* t_std_collections_Stack_1Tt_std_collections_Stack_1s_2::m__idx(bbInt l_index){
  bbDebugAssert(((l_index>=bbInt(0))&&(l_index<this->m__0length)),BB_T("Stack index out of range"));
  return this->m__0data->at(l_index);
}

t_std_collections_Stack_1s* t_std_collections_Stack_1Tt_std_collections_Stack_1s_2::m_Top(){
  bbDebugAssert(bbBool(this->m__0length),BB_T("Stack is empty"));
  return this->m__0data->at((this->m__0length-1));
}

bbArray<bbGCVar<t_std_collections_Stack_1s>>* t_std_collections_Stack_1Tt_std_collections_Stack_1s_2::m_ToArray(){
  return this->m__0data->slice(bbInt(0),this->m__0length);
}

void t_std_collections_Stack_1Tt_std_collections_Stack_1s_2::m_Swap(bbInt l_index1,bbInt l_index2){
  struct f0_t : public bbGCFrame{
    t_std_collections_Stack_1s* l_t{};
    void gcMark(){
      bbGCMarkPtr(l_t);
    }
  }f0{};
  bbDebugAssert(((((l_index1>=bbInt(0))&&(l_index1<this->m__0length))&&(l_index2>=bbInt(0)))&&(l_index2<this->m__0length)),BB_T("Stack index out of range"));
  f0.l_t=this->m__0data->at(l_index1);
  this->m__0data->at(l_index1)=this->m__0data->at(l_index2);
  this->m__0data->at(l_index2)=f0.l_t;
}

void t_std_collections_Stack_1Tt_std_collections_Stack_1s_2::m_Sort(bbFunction<bbInt(t_std_collections_Stack_1s*,t_std_collections_Stack_1s*)> l_compareFunc,bbInt l_lo,bbInt l_hi){
  if((l_hi<=l_lo)){
    return;
  }
  if(((l_lo+1)==l_hi)){
    if((l_compareFunc(this->m__0data->at(l_hi),this->m__0data->at(l_lo))<bbInt(0))){
      this->m_Swap(l_hi,l_lo);
    }
    return;
  }
  bbInt l_i=((l_lo+l_hi)/2);
  if((l_compareFunc(this->m__0data->at(l_i),this->m__0data->at(l_lo))<bbInt(0))){
    this->m_Swap(l_i,l_lo);
  }
  if((l_compareFunc(this->m__0data->at(l_hi),this->m__0data->at(l_i))<bbInt(0))){
    this->m_Swap(l_hi,l_i);
    if((l_compareFunc(this->m__0data->at(l_i),this->m__0data->at(l_lo))<bbInt(0))){
      this->m_Swap(l_i,l_lo);
    }
  }
  bbInt l_x=(l_lo+1);
  bbInt l_y=(l_hi-1);
  do{
    struct f1_t : public bbGCFrame{
      t_std_collections_Stack_1s* l_p{};
      void gcMark(){
        bbGCMarkPtr(l_p);
      }
    }f1{};
    f1.l_p=this->m__0data->at(l_i);
    while((l_compareFunc(this->m__0data->at(l_x),f1.l_p)<bbInt(0))){
      l_x+=1;
    }
    while((l_compareFunc(f1.l_p,this->m__0data->at(l_y))<bbInt(0))){
      l_y-=1;
    }
    if((l_x>l_y)){
      break;
    }
    if((l_x<l_y)){
      this->m_Swap(l_x,l_y);
      if((l_i==l_x)){
        l_i=l_y;
      }else if((l_i==l_y)){
        l_i=l_x;
      }
    }
    l_x+=1;
    l_y-=1;
  }while(!((l_x>l_y)));
  this->m_Sort(l_compareFunc,l_lo,l_y);
  this->m_Sort(l_compareFunc,l_x,l_hi);
}

void t_std_collections_Stack_1Tt_std_collections_Stack_1s_2::m_Sort(bbFunction<bbInt(t_std_collections_Stack_1s*,t_std_collections_Stack_1s*)> l_compareFunc){
  this->m_Sort(l_compareFunc,bbInt(0),(this->m__0length-1));
}

void t_std_collections_Stack_1Tt_std_collections_Stack_1s_2::m_Sort(bbBool l_ascending){
  if(l_ascending){
    struct lambda14 : public bbFunction<bbInt(t_std_collections_Stack_1s*,t_std_collections_Stack_1s*)>::Rep{
      t_std_collections_Stack_1Tt_std_collections_Stack_1s_2* l_self;
      lambda14(t_std_collections_Stack_1Tt_std_collections_Stack_1s_2* l_self):l_self(l_self){
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
      t_std_collections_Stack_1Tt_std_collections_Stack_1s_2* l_self;
      lambda15(t_std_collections_Stack_1Tt_std_collections_Stack_1s_2* l_self):l_self(l_self){
      }
      bbInt invoke(t_std_collections_Stack_1s* l_x,t_std_collections_Stack_1s* l_y){
        return bbCompare(l_y,l_x);
      }
      void gcMark(){
        bbGCMarkPtr(l_self);
      }
    };
    this->m_Sort(bbFunction<bbInt(t_std_collections_Stack_1s*,t_std_collections_Stack_1s*)>(new lambda15(this)));
  }
}

t_std_collections_Stack_1Tt_std_collections_Stack_1s_2* t_std_collections_Stack_1Tt_std_collections_Stack_1s_2::m_Slice(bbInt l_index1,bbInt l_index2){
  struct f0_t : public bbGCFrame{
    bbArray<bbGCVar<t_std_collections_Stack_1s>>* t0{};
    void gcMark(){
      bbGCMarkPtr(t0);
    }
  }f0{};
  if((l_index1<bbInt(0))){
    l_index1=g_monkey_math_Max_1i((l_index1+this->m__0length),bbInt(0));
  }else if((l_index1>this->m__0length)){
    l_index1=this->m__0length;
  }
  if((l_index2<bbInt(0))){
    l_index2=g_monkey_math_Max_1i((l_index2+this->m__0length),l_index1);
  }else if((l_index2>this->m__0length)){
    l_index2=this->m__0length;
  }else if((l_index2<l_index1)){
    l_index2=l_index1;
  }
  return bbGCNew<t_std_collections_Stack_1Tt_std_collections_Stack_1s_2>(f0.t0=this->m__0data->slice(l_index1,l_index2));
}

t_std_collections_Stack_1Tt_std_collections_Stack_1s_2* t_std_collections_Stack_1Tt_std_collections_Stack_1s_2::m_Slice(bbInt l_index){
  return this->m_Slice(l_index,this->m__0length);
}

void t_std_collections_Stack_1Tt_std_collections_Stack_1s_2::m_Set(bbInt l_index,t_std_collections_Stack_1s* l_value){
  bbDebugAssert(((l_index>=bbInt(0))&&(l_index<this->m__0length)),BB_T("Stack index out of range"));
  this->m__0data->at(l_index)=l_value;
}

void t_std_collections_Stack_1Tt_std_collections_Stack_1s_2::m_Resize(bbInt l_length){
  bbDebugAssert((l_length>=bbInt(0)),BB_T("Debug assert failed"));
  {
    bbInt l_i=l_length;
    for(;(l_i<this->m__0length);l_i+=1){
      this->m__0data->at(l_i)=((t_std_collections_Stack_1s*)0);
    }
  }
  this->m_Reserve(l_length);
  this->m__0length=l_length;
  this->m__0seq+=1;
}

void t_std_collections_Stack_1Tt_std_collections_Stack_1s_2::m_Reserve(bbInt l_capacity){
  struct f0_t : public bbGCFrame{
    bbArray<bbGCVar<t_std_collections_Stack_1s>>* l_data{};
    void gcMark(){
      bbGCMarkPtr(l_data);
    }
  }f0{};
  bbDebugAssert((l_capacity>=bbInt(0)),BB_T("Debug assert failed"));
  if((this->m__0data->length()>=l_capacity)){
    return;
  }
  l_capacity=g_monkey_math_Max_1i(((this->m__0length*2)+this->m__0length),l_capacity);
  f0.l_data=bbArray<bbGCVar<t_std_collections_Stack_1s>>::create(l_capacity);
  this->m__0data->copyTo(f0.l_data,bbInt(0),bbInt(0),this->m__0length);
  this->m__0data=f0.l_data;
}

bbBool t_std_collections_Stack_1Tt_std_collections_Stack_1s_2::m_RemoveLast(t_std_collections_Stack_1s* l_value,bbInt l_start){
  bbInt l_i=this->m_FindLastIndex(l_value,l_start);
  if((l_i==-1)){
    return false;
  }
  this->m_Erase(l_i);
  return true;
}

bbInt t_std_collections_Stack_1Tt_std_collections_Stack_1s_2::m_RemoveEach(t_std_collections_Stack_1s* l_value){
  bbInt l_put=bbInt(0);
  bbInt l_n=bbInt(0);
  {
    bbInt l_get=bbInt(0);
    for(;(l_get<this->m__0length);l_get+=1){
      if((this->m__0data->at(l_get)==l_value)){
        l_n+=1;
        continue;
      }
      this->m__0data->at(l_put)=this->m__0data->at(l_get);
      l_put+=1;
    }
  }
  this->m_Resize(l_put);
  return l_n;
}

bbBool t_std_collections_Stack_1Tt_std_collections_Stack_1s_2::m_Remove(t_std_collections_Stack_1s* l_value,bbInt l_start){
  bbInt l_i=this->m_FindIndex(l_value,l_start);
  if((l_i==-1)){
    return false;
  }
  this->m_Erase(l_i);
  return true;
}

void t_std_collections_Stack_1Tt_std_collections_Stack_1s_2::m_Push(t_std_collections_Stack_1s* l_value){
  this->m_Add(l_value);
}

t_std_collections_Stack_1s* t_std_collections_Stack_1Tt_std_collections_Stack_1s_2::m_Pop(){
  struct f0_t : public bbGCFrame{
    t_std_collections_Stack_1s* l_value{};
    void gcMark(){
      bbGCMarkPtr(l_value);
    }
  }f0{};
  bbDebugAssert(bbBool(this->m__0length),BB_T("Stack is empty"));
  this->m__0length-=1;
  this->m__0seq+=1;
  f0.l_value=this->m__0data->at(this->m__0length);
  this->m__0data->at(this->m__0length)=((t_std_collections_Stack_1s*)0);
  return f0.l_value;
}

bbInt t_std_collections_Stack_1Tt_std_collections_Stack_1s_2::m_Length(){
  return this->m__0length;
}

void t_std_collections_Stack_1Tt_std_collections_Stack_1s_2::m_Insert(bbInt l_index,t_std_collections_Stack_1s* l_value){
  bbDebugAssert(((l_index>=bbInt(0))&&(l_index<=this->m__0length)),BB_T("Debug assert failed"));
  this->m_Reserve((this->m__0length+1));
  this->m__0data->copyTo(this->m__0data,l_index,(l_index+1),(this->m__0length-l_index));
  this->m__0data->at(l_index)=l_value;
  this->m__0length+=1;
  this->m__0seq+=1;
}

t_std_collections_Stack_1s* t_std_collections_Stack_1Tt_std_collections_Stack_1s_2::m_Get(bbInt l_index){
  bbDebugAssert(((l_index>=bbInt(0))&&(l_index<this->m__0length)),BB_T("Stack index out of range"));
  return this->m__0data->at(l_index);
}

bbInt t_std_collections_Stack_1Tt_std_collections_Stack_1s_2::m_FindLastIndex(t_std_collections_Stack_1s* l_value,bbInt l_start){
  bbDebugAssert(((l_start>=bbInt(0))&&(l_start<=this->m__0length)),BB_T("Debug assert failed"));
  bbInt l_i=this->m__0length;
  while((l_i>l_start)){
    l_i-=1;
    if((this->m__0data->at(l_i)==l_value)){
      return l_i;
    }
  }
  return -1;
}

bbInt t_std_collections_Stack_1Tt_std_collections_Stack_1s_2::m_FindIndex(t_std_collections_Stack_1s* l_value,bbInt l_start){
  bbDebugAssert(((l_start>=bbInt(0))&&(l_start<=this->m__0length)),BB_T("Debug assert failed"));
  bbInt l_i=l_start;
  while((l_i<this->m__0length)){
    if((this->m__0data->at(l_i)==l_value)){
      return l_i;
    }
    l_i+=1;
  }
  return -1;
}

void t_std_collections_Stack_1Tt_std_collections_Stack_1s_2::m_Erase(bbInt l_index1,bbInt l_index2){
  bbDebugAssert((((((l_index1>=bbInt(0))&&(l_index1<=this->m__0length))&&(l_index2>=bbInt(0)))&&(l_index2<=this->m__0length))&&(l_index1<=l_index2)),BB_T("Debug assert failed"));
  if((l_index1==this->m__0length)){
    return;
  }
  this->m__0data->copyTo(this->m__0data,l_index2,l_index1,(this->m__0length-l_index2));
  this->m_Resize(((this->m__0length-l_index2)+l_index1));
}

void t_std_collections_Stack_1Tt_std_collections_Stack_1s_2::m_Erase(bbInt l_index){
  bbDebugAssert(((l_index>=bbInt(0))&&(l_index<=this->m__0length)),BB_T("Debug assert failed"));
  if((l_index==this->m__0length)){
    return;
  }
  this->m__0data->copyTo(this->m__0data,(l_index+1),l_index,((this->m__0length-l_index)-1));
  this->m_Resize((this->m__0length-1));
}

bbBool t_std_collections_Stack_1Tt_std_collections_Stack_1s_2::m_Empty(){
  return (this->m__0length==bbInt(0));
}

bbArray<bbGCVar<t_std_collections_Stack_1s>>* t_std_collections_Stack_1Tt_std_collections_Stack_1s_2::m_Data(){
  return this->m__0data;
}

bbBool t_std_collections_Stack_1Tt_std_collections_Stack_1s_2::m_Contains(t_std_collections_Stack_1s* l_value){
  return (this->m_FindIndex(l_value,bbInt(0))!=-1);
}

void t_std_collections_Stack_1Tt_std_collections_Stack_1s_2::m_Clear(){
  this->m_Resize(bbInt(0));
}

bbInt t_std_collections_Stack_1Tt_std_collections_Stack_1s_2::m_Capacity(){
  return this->m__0data->length();
}

t_std_collections_Stack_1Tt_std_collections_Stack_1s_2_BackwardsIterator t_std_collections_Stack_1Tt_std_collections_Stack_1s_2::m_Backwards(){
  return t_std_collections_Stack_1Tt_std_collections_Stack_1s_2_BackwardsIterator(this,(this->m__0length-1));
}

t_std_collections_Stack_1Tt_std_collections_Stack_1s_2_Iterator t_std_collections_Stack_1Tt_std_collections_Stack_1s_2::m_All(){
  return t_std_collections_Stack_1Tt_std_collections_Stack_1s_2_Iterator(this,bbInt(0));
}

void t_std_collections_Stack_1Tt_std_collections_Stack_1s_2::m_AddAll(bbArray<bbGCVar<t_std_collections_Stack_1s>>* l_values){
  this->m_Reserve((this->m__0length+l_values->length()));
  l_values->copyTo(this->m__0data,bbInt(0),this->m__0length,l_values->length());
  this->m_Resize((this->m__0length+l_values->length()));
}

void t_std_collections_Stack_1Tt_std_collections_Stack_1s_2::m_Add(t_std_collections_Stack_1s* l_value){
  this->m_Reserve((this->m__0length+1));
  this->m__0data->at(this->m__0length)=l_value;
  this->m__0length+=1;
  this->m__0seq+=1;
}

t_std_collections_Stack_1Tt_mx2_FileDecl_2_Iterator::t_std_collections_Stack_1Tt_mx2_FileDecl_2_Iterator(t_std_collections_Stack_1Tt_mx2_FileDecl_2* l_stack,bbInt l_index){
  (*this).m__0stack=l_stack;
  (*this).m__0index=l_index;
  (*this).m__0seq=l_stack->m__0seq;
}

void t_std_collections_Stack_1Tt_mx2_FileDecl_2_Iterator::m_Insert(t_mx2_FileDecl* l_value){
  (*this).m_AssertSeq();
  (*this).m__0stack->m_Insert((*this).m__0index,l_value);
  (*this).m__0seq=(*this).m__0stack->m__0seq;
}

void t_std_collections_Stack_1Tt_mx2_FileDecl_2_Iterator::m_Erase(){
  (*this).m_AssertSeq();
  (*this).m__0stack->m_Erase((*this).m__0index);
  (*this).m__0seq=(*this).m__0stack->m__0seq;
}

void t_std_collections_Stack_1Tt_mx2_FileDecl_2_Iterator::m_Current(t_mx2_FileDecl* l_current){
  (*this).m_AssertCurrent();
  (*this).m__0stack->m__0data->at((*this).m__0index)=l_current;
}

t_mx2_FileDecl* t_std_collections_Stack_1Tt_mx2_FileDecl_2_Iterator::m_Current(){
  (*this).m_AssertCurrent();
  return (*this).m__0stack->m__0data->at((*this).m__0index);
}

void t_std_collections_Stack_1Tt_mx2_FileDecl_2_Iterator::m_Bump(){
  (*this).m_AssertCurrent();
  (*this).m__0index+=1;
}

bbBool t_std_collections_Stack_1Tt_mx2_FileDecl_2_Iterator::m_AtEnd(){
  (*this).m_AssertSeq();
  return ((*this).m__0index==(*this).m__0stack->m__0length);
}

void t_std_collections_Stack_1Tt_mx2_FileDecl_2_Iterator::m_AssertSeq(){
  bbDebugAssert(((*this).m__0seq==(*this).m__0stack->m__0seq),BB_T("Concurrent list modification"));
}

void t_std_collections_Stack_1Tt_mx2_FileDecl_2_Iterator::m_AssertCurrent(){
  bbDebugAssert(!(*this).m_AtEnd(),BB_T("Invalid list iterator"));
}

int bbCompare(const t_std_collections_Stack_1Tt_mx2_FileDecl_2_Iterator&x,const t_std_collections_Stack_1Tt_mx2_FileDecl_2_Iterator&y){
  if(int t=bbCompare(x.m__0stack,y.m__0stack)) return t;
  if(int t=bbCompare(x.m__0index,y.m__0index)) return t;
  if(int t=bbCompare(x.m__0seq,y.m__0seq)) return t;
  return 0;
}

void bbGCMark(const t_std_collections_Stack_1Tt_mx2_FileDecl_2_Iterator&t){
  bbGCMark(t.m__0stack);
}

t_std_collections_Stack_1Tt_mx2_FileDecl_2_BackwardsIterator::t_std_collections_Stack_1Tt_mx2_FileDecl_2_BackwardsIterator(t_std_collections_Stack_1Tt_mx2_FileDecl_2* l_stack,bbInt l_index){
  (*this).m__0stack=l_stack;
  (*this).m__0index=l_index;
  (*this).m__0seq=l_stack->m__0seq;
}

void t_std_collections_Stack_1Tt_mx2_FileDecl_2_BackwardsIterator::m_Insert(t_mx2_FileDecl* l_value){
  (*this).m_AssertSeq();
  (*this).m__0index+=1;
  (*this).m__0stack->m_Insert((*this).m__0index,l_value);
  (*this).m__0seq=(*this).m__0stack->m__0seq;
}

void t_std_collections_Stack_1Tt_mx2_FileDecl_2_BackwardsIterator::m_Erase(){
  (*this).m_AssertCurrent();
  (*this).m__0index-=1;
  (*this).m__0stack->m_Erase(((*this).m__0index+1));
  (*this).m__0seq=(*this).m__0stack->m__0seq;
}

void t_std_collections_Stack_1Tt_mx2_FileDecl_2_BackwardsIterator::m_Current(t_mx2_FileDecl* l_current){
  (*this).m_AssertCurrent();
  (*this).m__0stack->m__0data->at((*this).m__0index)=l_current;
}

t_mx2_FileDecl* t_std_collections_Stack_1Tt_mx2_FileDecl_2_BackwardsIterator::m_Current(){
  (*this).m_AssertCurrent();
  return (*this).m__0stack->m__0data->at((*this).m__0index);
}

void t_std_collections_Stack_1Tt_mx2_FileDecl_2_BackwardsIterator::m_Bump(){
  (*this).m_AssertCurrent();
  (*this).m__0index-=1;
}

bbBool t_std_collections_Stack_1Tt_mx2_FileDecl_2_BackwardsIterator::m_AtEnd(){
  (*this).m_AssertSeq();
  return ((*this).m__0index==-1);
}

void t_std_collections_Stack_1Tt_mx2_FileDecl_2_BackwardsIterator::m_AssertSeq(){
  bbDebugAssert(((*this).m__0seq==(*this).m__0stack->m__0seq),BB_T("Concurrent list modification"));
}

void t_std_collections_Stack_1Tt_mx2_FileDecl_2_BackwardsIterator::m_AssertCurrent(){
  bbDebugAssert(!(*this).m_AtEnd(),BB_T("Invalid list iterator"));
}

int bbCompare(const t_std_collections_Stack_1Tt_mx2_FileDecl_2_BackwardsIterator&x,const t_std_collections_Stack_1Tt_mx2_FileDecl_2_BackwardsIterator&y){
  if(int t=bbCompare(x.m__0stack,y.m__0stack)) return t;
  if(int t=bbCompare(x.m__0index,y.m__0index)) return t;
  if(int t=bbCompare(x.m__0seq,y.m__0seq)) return t;
  return 0;
}

void bbGCMark(const t_std_collections_Stack_1Tt_mx2_FileDecl_2_BackwardsIterator&t){
  bbGCMark(t.m__0stack);
}

void t_std_collections_Stack_1Tt_mx2_FileDecl_2::gcMark(){
  bbGCMark(m__0data);
}

t_std_collections_Stack_1Tt_mx2_FileDecl_2::t_std_collections_Stack_1Tt_mx2_FileDecl_2(t_std_collections_List_1Tt_mx2_FileDecl_2* l_values){
  g_std_collections_Stack_1Tt_mx2_FileDecl_2_AddAll_1Tt_std_collections_List_1Tt_mx2_FileDecl_2_2(this,l_values);
}

t_std_collections_Stack_1Tt_mx2_FileDecl_2::t_std_collections_Stack_1Tt_mx2_FileDecl_2(t_std_collections_Stack_1Tt_mx2_FileDecl_2* l_values){
  struct f0_t : public bbGCFrame{
    bbArray<bbGCVar<t_mx2_FileDecl>>* t0{};
    void gcMark(){
      bbGCMarkPtr(t0);
    }
  }f0{};
  this->m__0length=l_values->m_Length();
  this->m__0data=bbArray<bbGCVar<t_mx2_FileDecl>>::create(this->m__0length);
  (f0.t0=l_values->m_Data())->copyTo(this->m__0data,bbInt(0),bbInt(0),this->m__0length);
}

t_std_collections_Stack_1Tt_mx2_FileDecl_2::t_std_collections_Stack_1Tt_mx2_FileDecl_2(bbArray<bbGCVar<t_mx2_FileDecl>>* l_values){
  this->m_AddAll(l_values);
}

t_std_collections_Stack_1Tt_mx2_FileDecl_2::t_std_collections_Stack_1Tt_mx2_FileDecl_2(bbInt l_length){
  this->m__0length=l_length;
  this->m__0data=bbArray<bbGCVar<t_mx2_FileDecl>>::create(this->m__0length);
}

t_std_collections_Stack_1Tt_mx2_FileDecl_2::t_std_collections_Stack_1Tt_mx2_FileDecl_2(){
  this->m__0data=bbArray<bbGCVar<t_mx2_FileDecl>>::create(10);
}

void t_std_collections_Stack_1Tt_mx2_FileDecl_2::m__idxeq(bbInt l_index,t_mx2_FileDecl* l_value){
  bbDebugAssert(((l_index>=bbInt(0))&&(l_index<this->m__0length)),BB_T("Stack index out of range"));
  this->m__0data->at(l_index)=l_value;
}

t_mx2_FileDecl* t_std_collections_Stack_1Tt_mx2_FileDecl_2::m__idx(bbInt l_index){
  bbDebugAssert(((l_index>=bbInt(0))&&(l_index<this->m__0length)),BB_T("Stack index out of range"));
  return this->m__0data->at(l_index);
}

t_mx2_FileDecl* t_std_collections_Stack_1Tt_mx2_FileDecl_2::m_Top(){
  bbDebugAssert(bbBool(this->m__0length),BB_T("Stack is empty"));
  return this->m__0data->at((this->m__0length-1));
}

bbArray<bbGCVar<t_mx2_FileDecl>>* t_std_collections_Stack_1Tt_mx2_FileDecl_2::m_ToArray(){
  return this->m__0data->slice(bbInt(0),this->m__0length);
}

void t_std_collections_Stack_1Tt_mx2_FileDecl_2::m_Swap(bbInt l_index1,bbInt l_index2){
  struct f0_t : public bbGCFrame{
    t_mx2_FileDecl* l_t{};
    void gcMark(){
      bbGCMarkPtr(l_t);
    }
  }f0{};
  bbDebugAssert(((((l_index1>=bbInt(0))&&(l_index1<this->m__0length))&&(l_index2>=bbInt(0)))&&(l_index2<this->m__0length)),BB_T("Stack index out of range"));
  f0.l_t=this->m__0data->at(l_index1);
  this->m__0data->at(l_index1)=this->m__0data->at(l_index2);
  this->m__0data->at(l_index2)=f0.l_t;
}

void t_std_collections_Stack_1Tt_mx2_FileDecl_2::m_Sort(bbFunction<bbInt(t_mx2_FileDecl*,t_mx2_FileDecl*)> l_compareFunc,bbInt l_lo,bbInt l_hi){
  if((l_hi<=l_lo)){
    return;
  }
  if(((l_lo+1)==l_hi)){
    if((l_compareFunc(this->m__0data->at(l_hi),this->m__0data->at(l_lo))<bbInt(0))){
      this->m_Swap(l_hi,l_lo);
    }
    return;
  }
  bbInt l_i=((l_lo+l_hi)/2);
  if((l_compareFunc(this->m__0data->at(l_i),this->m__0data->at(l_lo))<bbInt(0))){
    this->m_Swap(l_i,l_lo);
  }
  if((l_compareFunc(this->m__0data->at(l_hi),this->m__0data->at(l_i))<bbInt(0))){
    this->m_Swap(l_hi,l_i);
    if((l_compareFunc(this->m__0data->at(l_i),this->m__0data->at(l_lo))<bbInt(0))){
      this->m_Swap(l_i,l_lo);
    }
  }
  bbInt l_x=(l_lo+1);
  bbInt l_y=(l_hi-1);
  do{
    struct f1_t : public bbGCFrame{
      t_mx2_FileDecl* l_p{};
      void gcMark(){
        bbGCMarkPtr(l_p);
      }
    }f1{};
    f1.l_p=this->m__0data->at(l_i);
    while((l_compareFunc(this->m__0data->at(l_x),f1.l_p)<bbInt(0))){
      l_x+=1;
    }
    while((l_compareFunc(f1.l_p,this->m__0data->at(l_y))<bbInt(0))){
      l_y-=1;
    }
    if((l_x>l_y)){
      break;
    }
    if((l_x<l_y)){
      this->m_Swap(l_x,l_y);
      if((l_i==l_x)){
        l_i=l_y;
      }else if((l_i==l_y)){
        l_i=l_x;
      }
    }
    l_x+=1;
    l_y-=1;
  }while(!((l_x>l_y)));
  this->m_Sort(l_compareFunc,l_lo,l_y);
  this->m_Sort(l_compareFunc,l_x,l_hi);
}

void t_std_collections_Stack_1Tt_mx2_FileDecl_2::m_Sort(bbFunction<bbInt(t_mx2_FileDecl*,t_mx2_FileDecl*)> l_compareFunc){
  this->m_Sort(l_compareFunc,bbInt(0),(this->m__0length-1));
}

void t_std_collections_Stack_1Tt_mx2_FileDecl_2::m_Sort(bbBool l_ascending){
  if(l_ascending){
    struct lambda16 : public bbFunction<bbInt(t_mx2_FileDecl*,t_mx2_FileDecl*)>::Rep{
      t_std_collections_Stack_1Tt_mx2_FileDecl_2* l_self;
      lambda16(t_std_collections_Stack_1Tt_mx2_FileDecl_2* l_self):l_self(l_self){
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
      t_std_collections_Stack_1Tt_mx2_FileDecl_2* l_self;
      lambda17(t_std_collections_Stack_1Tt_mx2_FileDecl_2* l_self):l_self(l_self){
      }
      bbInt invoke(t_mx2_FileDecl* l_x,t_mx2_FileDecl* l_y){
        return bbCompare(l_y,l_x);
      }
      void gcMark(){
        bbGCMarkPtr(l_self);
      }
    };
    this->m_Sort(bbFunction<bbInt(t_mx2_FileDecl*,t_mx2_FileDecl*)>(new lambda17(this)));
  }
}

t_std_collections_Stack_1Tt_mx2_FileDecl_2* t_std_collections_Stack_1Tt_mx2_FileDecl_2::m_Slice(bbInt l_index1,bbInt l_index2){
  struct f0_t : public bbGCFrame{
    bbArray<bbGCVar<t_mx2_FileDecl>>* t0{};
    void gcMark(){
      bbGCMarkPtr(t0);
    }
  }f0{};
  if((l_index1<bbInt(0))){
    l_index1=g_monkey_math_Max_1i((l_index1+this->m__0length),bbInt(0));
  }else if((l_index1>this->m__0length)){
    l_index1=this->m__0length;
  }
  if((l_index2<bbInt(0))){
    l_index2=g_monkey_math_Max_1i((l_index2+this->m__0length),l_index1);
  }else if((l_index2>this->m__0length)){
    l_index2=this->m__0length;
  }else if((l_index2<l_index1)){
    l_index2=l_index1;
  }
  return bbGCNew<t_std_collections_Stack_1Tt_mx2_FileDecl_2>(f0.t0=this->m__0data->slice(l_index1,l_index2));
}

t_std_collections_Stack_1Tt_mx2_FileDecl_2* t_std_collections_Stack_1Tt_mx2_FileDecl_2::m_Slice(bbInt l_index){
  return this->m_Slice(l_index,this->m__0length);
}

void t_std_collections_Stack_1Tt_mx2_FileDecl_2::m_Set(bbInt l_index,t_mx2_FileDecl* l_value){
  bbDebugAssert(((l_index>=bbInt(0))&&(l_index<this->m__0length)),BB_T("Stack index out of range"));
  this->m__0data->at(l_index)=l_value;
}

void t_std_collections_Stack_1Tt_mx2_FileDecl_2::m_Resize(bbInt l_length){
  bbDebugAssert((l_length>=bbInt(0)),BB_T("Debug assert failed"));
  {
    bbInt l_i=l_length;
    for(;(l_i<this->m__0length);l_i+=1){
      this->m__0data->at(l_i)=((t_mx2_FileDecl*)0);
    }
  }
  this->m_Reserve(l_length);
  this->m__0length=l_length;
  this->m__0seq+=1;
}

void t_std_collections_Stack_1Tt_mx2_FileDecl_2::m_Reserve(bbInt l_capacity){
  struct f0_t : public bbGCFrame{
    bbArray<bbGCVar<t_mx2_FileDecl>>* l_data{};
    void gcMark(){
      bbGCMarkPtr(l_data);
    }
  }f0{};
  bbDebugAssert((l_capacity>=bbInt(0)),BB_T("Debug assert failed"));
  if((this->m__0data->length()>=l_capacity)){
    return;
  }
  l_capacity=g_monkey_math_Max_1i(((this->m__0length*2)+this->m__0length),l_capacity);
  f0.l_data=bbArray<bbGCVar<t_mx2_FileDecl>>::create(l_capacity);
  this->m__0data->copyTo(f0.l_data,bbInt(0),bbInt(0),this->m__0length);
  this->m__0data=f0.l_data;
}

bbBool t_std_collections_Stack_1Tt_mx2_FileDecl_2::m_RemoveLast(t_mx2_FileDecl* l_value,bbInt l_start){
  bbInt l_i=this->m_FindLastIndex(l_value,l_start);
  if((l_i==-1)){
    return false;
  }
  this->m_Erase(l_i);
  return true;
}

bbInt t_std_collections_Stack_1Tt_mx2_FileDecl_2::m_RemoveEach(t_mx2_FileDecl* l_value){
  bbInt l_put=bbInt(0);
  bbInt l_n=bbInt(0);
  {
    bbInt l_get=bbInt(0);
    for(;(l_get<this->m__0length);l_get+=1){
      if((this->m__0data->at(l_get)==l_value)){
        l_n+=1;
        continue;
      }
      this->m__0data->at(l_put)=this->m__0data->at(l_get);
      l_put+=1;
    }
  }
  this->m_Resize(l_put);
  return l_n;
}

bbBool t_std_collections_Stack_1Tt_mx2_FileDecl_2::m_Remove(t_mx2_FileDecl* l_value,bbInt l_start){
  bbInt l_i=this->m_FindIndex(l_value,l_start);
  if((l_i==-1)){
    return false;
  }
  this->m_Erase(l_i);
  return true;
}

void t_std_collections_Stack_1Tt_mx2_FileDecl_2::m_Push(t_mx2_FileDecl* l_value){
  this->m_Add(l_value);
}

t_mx2_FileDecl* t_std_collections_Stack_1Tt_mx2_FileDecl_2::m_Pop(){
  struct f0_t : public bbGCFrame{
    t_mx2_FileDecl* l_value{};
    void gcMark(){
      bbGCMarkPtr(l_value);
    }
  }f0{};
  bbDebugAssert(bbBool(this->m__0length),BB_T("Stack is empty"));
  this->m__0length-=1;
  this->m__0seq+=1;
  f0.l_value=this->m__0data->at(this->m__0length);
  this->m__0data->at(this->m__0length)=((t_mx2_FileDecl*)0);
  return f0.l_value;
}

bbInt t_std_collections_Stack_1Tt_mx2_FileDecl_2::m_Length(){
  return this->m__0length;
}

void t_std_collections_Stack_1Tt_mx2_FileDecl_2::m_Insert(bbInt l_index,t_mx2_FileDecl* l_value){
  bbDebugAssert(((l_index>=bbInt(0))&&(l_index<=this->m__0length)),BB_T("Debug assert failed"));
  this->m_Reserve((this->m__0length+1));
  this->m__0data->copyTo(this->m__0data,l_index,(l_index+1),(this->m__0length-l_index));
  this->m__0data->at(l_index)=l_value;
  this->m__0length+=1;
  this->m__0seq+=1;
}

t_mx2_FileDecl* t_std_collections_Stack_1Tt_mx2_FileDecl_2::m_Get(bbInt l_index){
  bbDebugAssert(((l_index>=bbInt(0))&&(l_index<this->m__0length)),BB_T("Stack index out of range"));
  return this->m__0data->at(l_index);
}

bbInt t_std_collections_Stack_1Tt_mx2_FileDecl_2::m_FindLastIndex(t_mx2_FileDecl* l_value,bbInt l_start){
  bbDebugAssert(((l_start>=bbInt(0))&&(l_start<=this->m__0length)),BB_T("Debug assert failed"));
  bbInt l_i=this->m__0length;
  while((l_i>l_start)){
    l_i-=1;
    if((this->m__0data->at(l_i)==l_value)){
      return l_i;
    }
  }
  return -1;
}

bbInt t_std_collections_Stack_1Tt_mx2_FileDecl_2::m_FindIndex(t_mx2_FileDecl* l_value,bbInt l_start){
  bbDebugAssert(((l_start>=bbInt(0))&&(l_start<=this->m__0length)),BB_T("Debug assert failed"));
  bbInt l_i=l_start;
  while((l_i<this->m__0length)){
    if((this->m__0data->at(l_i)==l_value)){
      return l_i;
    }
    l_i+=1;
  }
  return -1;
}

void t_std_collections_Stack_1Tt_mx2_FileDecl_2::m_Erase(bbInt l_index1,bbInt l_index2){
  bbDebugAssert((((((l_index1>=bbInt(0))&&(l_index1<=this->m__0length))&&(l_index2>=bbInt(0)))&&(l_index2<=this->m__0length))&&(l_index1<=l_index2)),BB_T("Debug assert failed"));
  if((l_index1==this->m__0length)){
    return;
  }
  this->m__0data->copyTo(this->m__0data,l_index2,l_index1,(this->m__0length-l_index2));
  this->m_Resize(((this->m__0length-l_index2)+l_index1));
}

void t_std_collections_Stack_1Tt_mx2_FileDecl_2::m_Erase(bbInt l_index){
  bbDebugAssert(((l_index>=bbInt(0))&&(l_index<=this->m__0length)),BB_T("Debug assert failed"));
  if((l_index==this->m__0length)){
    return;
  }
  this->m__0data->copyTo(this->m__0data,(l_index+1),l_index,((this->m__0length-l_index)-1));
  this->m_Resize((this->m__0length-1));
}

bbBool t_std_collections_Stack_1Tt_mx2_FileDecl_2::m_Empty(){
  return (this->m__0length==bbInt(0));
}

bbArray<bbGCVar<t_mx2_FileDecl>>* t_std_collections_Stack_1Tt_mx2_FileDecl_2::m_Data(){
  return this->m__0data;
}

bbBool t_std_collections_Stack_1Tt_mx2_FileDecl_2::m_Contains(t_mx2_FileDecl* l_value){
  return (this->m_FindIndex(l_value,bbInt(0))!=-1);
}

void t_std_collections_Stack_1Tt_mx2_FileDecl_2::m_Clear(){
  this->m_Resize(bbInt(0));
}

bbInt t_std_collections_Stack_1Tt_mx2_FileDecl_2::m_Capacity(){
  return this->m__0data->length();
}

t_std_collections_Stack_1Tt_mx2_FileDecl_2_BackwardsIterator t_std_collections_Stack_1Tt_mx2_FileDecl_2::m_Backwards(){
  return t_std_collections_Stack_1Tt_mx2_FileDecl_2_BackwardsIterator(this,(this->m__0length-1));
}

t_std_collections_Stack_1Tt_mx2_FileDecl_2_Iterator t_std_collections_Stack_1Tt_mx2_FileDecl_2::m_All(){
  return t_std_collections_Stack_1Tt_mx2_FileDecl_2_Iterator(this,bbInt(0));
}

void t_std_collections_Stack_1Tt_mx2_FileDecl_2::m_AddAll(bbArray<bbGCVar<t_mx2_FileDecl>>* l_values){
  this->m_Reserve((this->m__0length+l_values->length()));
  l_values->copyTo(this->m__0data,bbInt(0),this->m__0length,l_values->length());
  this->m_Resize((this->m__0length+l_values->length()));
}

void t_std_collections_Stack_1Tt_mx2_FileDecl_2::m_Add(t_mx2_FileDecl* l_value){
  this->m_Reserve((this->m__0length+1));
  this->m__0data->at(this->m__0length)=l_value;
  this->m__0length+=1;
  this->m__0seq+=1;
}

t_std_collections_Stack_1Tt_mx2_FileScope_2_Iterator::t_std_collections_Stack_1Tt_mx2_FileScope_2_Iterator(t_std_collections_Stack_1Tt_mx2_FileScope_2* l_stack,bbInt l_index){
  (*this).m__0stack=l_stack;
  (*this).m__0index=l_index;
  (*this).m__0seq=l_stack->m__0seq;
}

void t_std_collections_Stack_1Tt_mx2_FileScope_2_Iterator::m_Insert(t_mx2_FileScope* l_value){
  (*this).m_AssertSeq();
  (*this).m__0stack->m_Insert((*this).m__0index,l_value);
  (*this).m__0seq=(*this).m__0stack->m__0seq;
}

void t_std_collections_Stack_1Tt_mx2_FileScope_2_Iterator::m_Erase(){
  (*this).m_AssertSeq();
  (*this).m__0stack->m_Erase((*this).m__0index);
  (*this).m__0seq=(*this).m__0stack->m__0seq;
}

void t_std_collections_Stack_1Tt_mx2_FileScope_2_Iterator::m_Current(t_mx2_FileScope* l_current){
  (*this).m_AssertCurrent();
  (*this).m__0stack->m__0data->at((*this).m__0index)=l_current;
}

t_mx2_FileScope* t_std_collections_Stack_1Tt_mx2_FileScope_2_Iterator::m_Current(){
  (*this).m_AssertCurrent();
  return (*this).m__0stack->m__0data->at((*this).m__0index);
}

void t_std_collections_Stack_1Tt_mx2_FileScope_2_Iterator::m_Bump(){
  (*this).m_AssertCurrent();
  (*this).m__0index+=1;
}

bbBool t_std_collections_Stack_1Tt_mx2_FileScope_2_Iterator::m_AtEnd(){
  (*this).m_AssertSeq();
  return ((*this).m__0index==(*this).m__0stack->m__0length);
}

void t_std_collections_Stack_1Tt_mx2_FileScope_2_Iterator::m_AssertSeq(){
  bbDebugAssert(((*this).m__0seq==(*this).m__0stack->m__0seq),BB_T("Concurrent list modification"));
}

void t_std_collections_Stack_1Tt_mx2_FileScope_2_Iterator::m_AssertCurrent(){
  bbDebugAssert(!(*this).m_AtEnd(),BB_T("Invalid list iterator"));
}

int bbCompare(const t_std_collections_Stack_1Tt_mx2_FileScope_2_Iterator&x,const t_std_collections_Stack_1Tt_mx2_FileScope_2_Iterator&y){
  if(int t=bbCompare(x.m__0stack,y.m__0stack)) return t;
  if(int t=bbCompare(x.m__0index,y.m__0index)) return t;
  if(int t=bbCompare(x.m__0seq,y.m__0seq)) return t;
  return 0;
}

void bbGCMark(const t_std_collections_Stack_1Tt_mx2_FileScope_2_Iterator&t){
  bbGCMark(t.m__0stack);
}

t_std_collections_Stack_1Tt_mx2_FileScope_2_BackwardsIterator::t_std_collections_Stack_1Tt_mx2_FileScope_2_BackwardsIterator(t_std_collections_Stack_1Tt_mx2_FileScope_2* l_stack,bbInt l_index){
  (*this).m__0stack=l_stack;
  (*this).m__0index=l_index;
  (*this).m__0seq=l_stack->m__0seq;
}

void t_std_collections_Stack_1Tt_mx2_FileScope_2_BackwardsIterator::m_Insert(t_mx2_FileScope* l_value){
  (*this).m_AssertSeq();
  (*this).m__0index+=1;
  (*this).m__0stack->m_Insert((*this).m__0index,l_value);
  (*this).m__0seq=(*this).m__0stack->m__0seq;
}

void t_std_collections_Stack_1Tt_mx2_FileScope_2_BackwardsIterator::m_Erase(){
  (*this).m_AssertCurrent();
  (*this).m__0index-=1;
  (*this).m__0stack->m_Erase(((*this).m__0index+1));
  (*this).m__0seq=(*this).m__0stack->m__0seq;
}

void t_std_collections_Stack_1Tt_mx2_FileScope_2_BackwardsIterator::m_Current(t_mx2_FileScope* l_current){
  (*this).m_AssertCurrent();
  (*this).m__0stack->m__0data->at((*this).m__0index)=l_current;
}

t_mx2_FileScope* t_std_collections_Stack_1Tt_mx2_FileScope_2_BackwardsIterator::m_Current(){
  (*this).m_AssertCurrent();
  return (*this).m__0stack->m__0data->at((*this).m__0index);
}

void t_std_collections_Stack_1Tt_mx2_FileScope_2_BackwardsIterator::m_Bump(){
  (*this).m_AssertCurrent();
  (*this).m__0index-=1;
}

bbBool t_std_collections_Stack_1Tt_mx2_FileScope_2_BackwardsIterator::m_AtEnd(){
  (*this).m_AssertSeq();
  return ((*this).m__0index==-1);
}

void t_std_collections_Stack_1Tt_mx2_FileScope_2_BackwardsIterator::m_AssertSeq(){
  bbDebugAssert(((*this).m__0seq==(*this).m__0stack->m__0seq),BB_T("Concurrent list modification"));
}

void t_std_collections_Stack_1Tt_mx2_FileScope_2_BackwardsIterator::m_AssertCurrent(){
  bbDebugAssert(!(*this).m_AtEnd(),BB_T("Invalid list iterator"));
}

int bbCompare(const t_std_collections_Stack_1Tt_mx2_FileScope_2_BackwardsIterator&x,const t_std_collections_Stack_1Tt_mx2_FileScope_2_BackwardsIterator&y){
  if(int t=bbCompare(x.m__0stack,y.m__0stack)) return t;
  if(int t=bbCompare(x.m__0index,y.m__0index)) return t;
  if(int t=bbCompare(x.m__0seq,y.m__0seq)) return t;
  return 0;
}

void bbGCMark(const t_std_collections_Stack_1Tt_mx2_FileScope_2_BackwardsIterator&t){
  bbGCMark(t.m__0stack);
}

void t_std_collections_Stack_1Tt_mx2_FileScope_2::gcMark(){
  bbGCMark(m__0data);
}

t_std_collections_Stack_1Tt_mx2_FileScope_2::t_std_collections_Stack_1Tt_mx2_FileScope_2(t_std_collections_List_1Tt_mx2_FileScope_2* l_values){
  g_std_collections_Stack_1Tt_mx2_FileScope_2_AddAll_1Tt_std_collections_List_1Tt_mx2_FileScope_2_2(this,l_values);
}

t_std_collections_Stack_1Tt_mx2_FileScope_2::t_std_collections_Stack_1Tt_mx2_FileScope_2(t_std_collections_Stack_1Tt_mx2_FileScope_2* l_values){
  struct f0_t : public bbGCFrame{
    bbArray<bbGCVar<t_mx2_FileScope>>* t0{};
    void gcMark(){
      bbGCMarkPtr(t0);
    }
  }f0{};
  this->m__0length=l_values->m_Length();
  this->m__0data=bbArray<bbGCVar<t_mx2_FileScope>>::create(this->m__0length);
  (f0.t0=l_values->m_Data())->copyTo(this->m__0data,bbInt(0),bbInt(0),this->m__0length);
}

t_std_collections_Stack_1Tt_mx2_FileScope_2::t_std_collections_Stack_1Tt_mx2_FileScope_2(bbArray<bbGCVar<t_mx2_FileScope>>* l_values){
  this->m_AddAll(l_values);
}

t_std_collections_Stack_1Tt_mx2_FileScope_2::t_std_collections_Stack_1Tt_mx2_FileScope_2(bbInt l_length){
  this->m__0length=l_length;
  this->m__0data=bbArray<bbGCVar<t_mx2_FileScope>>::create(this->m__0length);
}

t_std_collections_Stack_1Tt_mx2_FileScope_2::t_std_collections_Stack_1Tt_mx2_FileScope_2(){
  this->m__0data=bbArray<bbGCVar<t_mx2_FileScope>>::create(10);
}

void t_std_collections_Stack_1Tt_mx2_FileScope_2::m__idxeq(bbInt l_index,t_mx2_FileScope* l_value){
  bbDebugAssert(((l_index>=bbInt(0))&&(l_index<this->m__0length)),BB_T("Stack index out of range"));
  this->m__0data->at(l_index)=l_value;
}

t_mx2_FileScope* t_std_collections_Stack_1Tt_mx2_FileScope_2::m__idx(bbInt l_index){
  bbDebugAssert(((l_index>=bbInt(0))&&(l_index<this->m__0length)),BB_T("Stack index out of range"));
  return this->m__0data->at(l_index);
}

t_mx2_FileScope* t_std_collections_Stack_1Tt_mx2_FileScope_2::m_Top(){
  bbDebugAssert(bbBool(this->m__0length),BB_T("Stack is empty"));
  return this->m__0data->at((this->m__0length-1));
}

bbArray<bbGCVar<t_mx2_FileScope>>* t_std_collections_Stack_1Tt_mx2_FileScope_2::m_ToArray(){
  return this->m__0data->slice(bbInt(0),this->m__0length);
}

void t_std_collections_Stack_1Tt_mx2_FileScope_2::m_Swap(bbInt l_index1,bbInt l_index2){
  struct f0_t : public bbGCFrame{
    t_mx2_FileScope* l_t{};
    void gcMark(){
      bbGCMarkPtr(l_t);
    }
  }f0{};
  bbDebugAssert(((((l_index1>=bbInt(0))&&(l_index1<this->m__0length))&&(l_index2>=bbInt(0)))&&(l_index2<this->m__0length)),BB_T("Stack index out of range"));
  f0.l_t=this->m__0data->at(l_index1);
  this->m__0data->at(l_index1)=this->m__0data->at(l_index2);
  this->m__0data->at(l_index2)=f0.l_t;
}

void t_std_collections_Stack_1Tt_mx2_FileScope_2::m_Sort(bbFunction<bbInt(t_mx2_FileScope*,t_mx2_FileScope*)> l_compareFunc,bbInt l_lo,bbInt l_hi){
  if((l_hi<=l_lo)){
    return;
  }
  if(((l_lo+1)==l_hi)){
    if((l_compareFunc(this->m__0data->at(l_hi),this->m__0data->at(l_lo))<bbInt(0))){
      this->m_Swap(l_hi,l_lo);
    }
    return;
  }
  bbInt l_i=((l_lo+l_hi)/2);
  if((l_compareFunc(this->m__0data->at(l_i),this->m__0data->at(l_lo))<bbInt(0))){
    this->m_Swap(l_i,l_lo);
  }
  if((l_compareFunc(this->m__0data->at(l_hi),this->m__0data->at(l_i))<bbInt(0))){
    this->m_Swap(l_hi,l_i);
    if((l_compareFunc(this->m__0data->at(l_i),this->m__0data->at(l_lo))<bbInt(0))){
      this->m_Swap(l_i,l_lo);
    }
  }
  bbInt l_x=(l_lo+1);
  bbInt l_y=(l_hi-1);
  do{
    struct f1_t : public bbGCFrame{
      t_mx2_FileScope* l_p{};
      void gcMark(){
        bbGCMarkPtr(l_p);
      }
    }f1{};
    f1.l_p=this->m__0data->at(l_i);
    while((l_compareFunc(this->m__0data->at(l_x),f1.l_p)<bbInt(0))){
      l_x+=1;
    }
    while((l_compareFunc(f1.l_p,this->m__0data->at(l_y))<bbInt(0))){
      l_y-=1;
    }
    if((l_x>l_y)){
      break;
    }
    if((l_x<l_y)){
      this->m_Swap(l_x,l_y);
      if((l_i==l_x)){
        l_i=l_y;
      }else if((l_i==l_y)){
        l_i=l_x;
      }
    }
    l_x+=1;
    l_y-=1;
  }while(!((l_x>l_y)));
  this->m_Sort(l_compareFunc,l_lo,l_y);
  this->m_Sort(l_compareFunc,l_x,l_hi);
}

void t_std_collections_Stack_1Tt_mx2_FileScope_2::m_Sort(bbFunction<bbInt(t_mx2_FileScope*,t_mx2_FileScope*)> l_compareFunc){
  this->m_Sort(l_compareFunc,bbInt(0),(this->m__0length-1));
}

void t_std_collections_Stack_1Tt_mx2_FileScope_2::m_Sort(bbBool l_ascending){
  if(l_ascending){
    struct lambda18 : public bbFunction<bbInt(t_mx2_FileScope*,t_mx2_FileScope*)>::Rep{
      t_std_collections_Stack_1Tt_mx2_FileScope_2* l_self;
      lambda18(t_std_collections_Stack_1Tt_mx2_FileScope_2* l_self):l_self(l_self){
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
      t_std_collections_Stack_1Tt_mx2_FileScope_2* l_self;
      lambda19(t_std_collections_Stack_1Tt_mx2_FileScope_2* l_self):l_self(l_self){
      }
      bbInt invoke(t_mx2_FileScope* l_x,t_mx2_FileScope* l_y){
        return bbCompare(l_y,l_x);
      }
      void gcMark(){
        bbGCMarkPtr(l_self);
      }
    };
    this->m_Sort(bbFunction<bbInt(t_mx2_FileScope*,t_mx2_FileScope*)>(new lambda19(this)));
  }
}

t_std_collections_Stack_1Tt_mx2_FileScope_2* t_std_collections_Stack_1Tt_mx2_FileScope_2::m_Slice(bbInt l_index1,bbInt l_index2){
  struct f0_t : public bbGCFrame{
    bbArray<bbGCVar<t_mx2_FileScope>>* t0{};
    void gcMark(){
      bbGCMarkPtr(t0);
    }
  }f0{};
  if((l_index1<bbInt(0))){
    l_index1=g_monkey_math_Max_1i((l_index1+this->m__0length),bbInt(0));
  }else if((l_index1>this->m__0length)){
    l_index1=this->m__0length;
  }
  if((l_index2<bbInt(0))){
    l_index2=g_monkey_math_Max_1i((l_index2+this->m__0length),l_index1);
  }else if((l_index2>this->m__0length)){
    l_index2=this->m__0length;
  }else if((l_index2<l_index1)){
    l_index2=l_index1;
  }
  return bbGCNew<t_std_collections_Stack_1Tt_mx2_FileScope_2>(f0.t0=this->m__0data->slice(l_index1,l_index2));
}

t_std_collections_Stack_1Tt_mx2_FileScope_2* t_std_collections_Stack_1Tt_mx2_FileScope_2::m_Slice(bbInt l_index){
  return this->m_Slice(l_index,this->m__0length);
}

void t_std_collections_Stack_1Tt_mx2_FileScope_2::m_Set(bbInt l_index,t_mx2_FileScope* l_value){
  bbDebugAssert(((l_index>=bbInt(0))&&(l_index<this->m__0length)),BB_T("Stack index out of range"));
  this->m__0data->at(l_index)=l_value;
}

void t_std_collections_Stack_1Tt_mx2_FileScope_2::m_Resize(bbInt l_length){
  bbDebugAssert((l_length>=bbInt(0)),BB_T("Debug assert failed"));
  {
    bbInt l_i=l_length;
    for(;(l_i<this->m__0length);l_i+=1){
      this->m__0data->at(l_i)=((t_mx2_FileScope*)0);
    }
  }
  this->m_Reserve(l_length);
  this->m__0length=l_length;
  this->m__0seq+=1;
}

void t_std_collections_Stack_1Tt_mx2_FileScope_2::m_Reserve(bbInt l_capacity){
  struct f0_t : public bbGCFrame{
    bbArray<bbGCVar<t_mx2_FileScope>>* l_data{};
    void gcMark(){
      bbGCMarkPtr(l_data);
    }
  }f0{};
  bbDebugAssert((l_capacity>=bbInt(0)),BB_T("Debug assert failed"));
  if((this->m__0data->length()>=l_capacity)){
    return;
  }
  l_capacity=g_monkey_math_Max_1i(((this->m__0length*2)+this->m__0length),l_capacity);
  f0.l_data=bbArray<bbGCVar<t_mx2_FileScope>>::create(l_capacity);
  this->m__0data->copyTo(f0.l_data,bbInt(0),bbInt(0),this->m__0length);
  this->m__0data=f0.l_data;
}

bbBool t_std_collections_Stack_1Tt_mx2_FileScope_2::m_RemoveLast(t_mx2_FileScope* l_value,bbInt l_start){
  bbInt l_i=this->m_FindLastIndex(l_value,l_start);
  if((l_i==-1)){
    return false;
  }
  this->m_Erase(l_i);
  return true;
}

bbInt t_std_collections_Stack_1Tt_mx2_FileScope_2::m_RemoveEach(t_mx2_FileScope* l_value){
  bbInt l_put=bbInt(0);
  bbInt l_n=bbInt(0);
  {
    bbInt l_get=bbInt(0);
    for(;(l_get<this->m__0length);l_get+=1){
      if((this->m__0data->at(l_get)==l_value)){
        l_n+=1;
        continue;
      }
      this->m__0data->at(l_put)=this->m__0data->at(l_get);
      l_put+=1;
    }
  }
  this->m_Resize(l_put);
  return l_n;
}

bbBool t_std_collections_Stack_1Tt_mx2_FileScope_2::m_Remove(t_mx2_FileScope* l_value,bbInt l_start){
  bbInt l_i=this->m_FindIndex(l_value,l_start);
  if((l_i==-1)){
    return false;
  }
  this->m_Erase(l_i);
  return true;
}

void t_std_collections_Stack_1Tt_mx2_FileScope_2::m_Push(t_mx2_FileScope* l_value){
  this->m_Add(l_value);
}

t_mx2_FileScope* t_std_collections_Stack_1Tt_mx2_FileScope_2::m_Pop(){
  struct f0_t : public bbGCFrame{
    t_mx2_FileScope* l_value{};
    void gcMark(){
      bbGCMarkPtr(l_value);
    }
  }f0{};
  bbDebugAssert(bbBool(this->m__0length),BB_T("Stack is empty"));
  this->m__0length-=1;
  this->m__0seq+=1;
  f0.l_value=this->m__0data->at(this->m__0length);
  this->m__0data->at(this->m__0length)=((t_mx2_FileScope*)0);
  return f0.l_value;
}

bbInt t_std_collections_Stack_1Tt_mx2_FileScope_2::m_Length(){
  return this->m__0length;
}

void t_std_collections_Stack_1Tt_mx2_FileScope_2::m_Insert(bbInt l_index,t_mx2_FileScope* l_value){
  bbDebugAssert(((l_index>=bbInt(0))&&(l_index<=this->m__0length)),BB_T("Debug assert failed"));
  this->m_Reserve((this->m__0length+1));
  this->m__0data->copyTo(this->m__0data,l_index,(l_index+1),(this->m__0length-l_index));
  this->m__0data->at(l_index)=l_value;
  this->m__0length+=1;
  this->m__0seq+=1;
}

t_mx2_FileScope* t_std_collections_Stack_1Tt_mx2_FileScope_2::m_Get(bbInt l_index){
  bbDebugAssert(((l_index>=bbInt(0))&&(l_index<this->m__0length)),BB_T("Stack index out of range"));
  return this->m__0data->at(l_index);
}

bbInt t_std_collections_Stack_1Tt_mx2_FileScope_2::m_FindLastIndex(t_mx2_FileScope* l_value,bbInt l_start){
  bbDebugAssert(((l_start>=bbInt(0))&&(l_start<=this->m__0length)),BB_T("Debug assert failed"));
  bbInt l_i=this->m__0length;
  while((l_i>l_start)){
    l_i-=1;
    if((this->m__0data->at(l_i)==l_value)){
      return l_i;
    }
  }
  return -1;
}

bbInt t_std_collections_Stack_1Tt_mx2_FileScope_2::m_FindIndex(t_mx2_FileScope* l_value,bbInt l_start){
  bbDebugAssert(((l_start>=bbInt(0))&&(l_start<=this->m__0length)),BB_T("Debug assert failed"));
  bbInt l_i=l_start;
  while((l_i<this->m__0length)){
    if((this->m__0data->at(l_i)==l_value)){
      return l_i;
    }
    l_i+=1;
  }
  return -1;
}

void t_std_collections_Stack_1Tt_mx2_FileScope_2::m_Erase(bbInt l_index1,bbInt l_index2){
  bbDebugAssert((((((l_index1>=bbInt(0))&&(l_index1<=this->m__0length))&&(l_index2>=bbInt(0)))&&(l_index2<=this->m__0length))&&(l_index1<=l_index2)),BB_T("Debug assert failed"));
  if((l_index1==this->m__0length)){
    return;
  }
  this->m__0data->copyTo(this->m__0data,l_index2,l_index1,(this->m__0length-l_index2));
  this->m_Resize(((this->m__0length-l_index2)+l_index1));
}

void t_std_collections_Stack_1Tt_mx2_FileScope_2::m_Erase(bbInt l_index){
  bbDebugAssert(((l_index>=bbInt(0))&&(l_index<=this->m__0length)),BB_T("Debug assert failed"));
  if((l_index==this->m__0length)){
    return;
  }
  this->m__0data->copyTo(this->m__0data,(l_index+1),l_index,((this->m__0length-l_index)-1));
  this->m_Resize((this->m__0length-1));
}

bbBool t_std_collections_Stack_1Tt_mx2_FileScope_2::m_Empty(){
  return (this->m__0length==bbInt(0));
}

bbArray<bbGCVar<t_mx2_FileScope>>* t_std_collections_Stack_1Tt_mx2_FileScope_2::m_Data(){
  return this->m__0data;
}

bbBool t_std_collections_Stack_1Tt_mx2_FileScope_2::m_Contains(t_mx2_FileScope* l_value){
  return (this->m_FindIndex(l_value,bbInt(0))!=-1);
}

void t_std_collections_Stack_1Tt_mx2_FileScope_2::m_Clear(){
  this->m_Resize(bbInt(0));
}

bbInt t_std_collections_Stack_1Tt_mx2_FileScope_2::m_Capacity(){
  return this->m__0data->length();
}

t_std_collections_Stack_1Tt_mx2_FileScope_2_BackwardsIterator t_std_collections_Stack_1Tt_mx2_FileScope_2::m_Backwards(){
  return t_std_collections_Stack_1Tt_mx2_FileScope_2_BackwardsIterator(this,(this->m__0length-1));
}

t_std_collections_Stack_1Tt_mx2_FileScope_2_Iterator t_std_collections_Stack_1Tt_mx2_FileScope_2::m_All(){
  return t_std_collections_Stack_1Tt_mx2_FileScope_2_Iterator(this,bbInt(0));
}

void t_std_collections_Stack_1Tt_mx2_FileScope_2::m_AddAll(bbArray<bbGCVar<t_mx2_FileScope>>* l_values){
  this->m_Reserve((this->m__0length+l_values->length()));
  l_values->copyTo(this->m__0data,bbInt(0),this->m__0length,l_values->length());
  this->m_Resize((this->m__0length+l_values->length()));
}

void t_std_collections_Stack_1Tt_mx2_FileScope_2::m_Add(t_mx2_FileScope* l_value){
  this->m_Reserve((this->m__0length+1));
  this->m__0data->at(this->m__0length)=l_value;
  this->m__0length+=1;
  this->m__0seq+=1;
}

t_std_collections_Stack_1Tt_mx2_NamespaceScope_2_Iterator::t_std_collections_Stack_1Tt_mx2_NamespaceScope_2_Iterator(t_std_collections_Stack_1Tt_mx2_NamespaceScope_2* l_stack,bbInt l_index){
  (*this).m__0stack=l_stack;
  (*this).m__0index=l_index;
  (*this).m__0seq=l_stack->m__0seq;
}

void t_std_collections_Stack_1Tt_mx2_NamespaceScope_2_Iterator::m_Insert(t_mx2_NamespaceScope* l_value){
  (*this).m_AssertSeq();
  (*this).m__0stack->m_Insert((*this).m__0index,l_value);
  (*this).m__0seq=(*this).m__0stack->m__0seq;
}

void t_std_collections_Stack_1Tt_mx2_NamespaceScope_2_Iterator::m_Erase(){
  (*this).m_AssertSeq();
  (*this).m__0stack->m_Erase((*this).m__0index);
  (*this).m__0seq=(*this).m__0stack->m__0seq;
}

void t_std_collections_Stack_1Tt_mx2_NamespaceScope_2_Iterator::m_Current(t_mx2_NamespaceScope* l_current){
  (*this).m_AssertCurrent();
  (*this).m__0stack->m__0data->at((*this).m__0index)=l_current;
}

t_mx2_NamespaceScope* t_std_collections_Stack_1Tt_mx2_NamespaceScope_2_Iterator::m_Current(){
  (*this).m_AssertCurrent();
  return (*this).m__0stack->m__0data->at((*this).m__0index);
}

void t_std_collections_Stack_1Tt_mx2_NamespaceScope_2_Iterator::m_Bump(){
  (*this).m_AssertCurrent();
  (*this).m__0index+=1;
}

bbBool t_std_collections_Stack_1Tt_mx2_NamespaceScope_2_Iterator::m_AtEnd(){
  (*this).m_AssertSeq();
  return ((*this).m__0index==(*this).m__0stack->m__0length);
}

void t_std_collections_Stack_1Tt_mx2_NamespaceScope_2_Iterator::m_AssertSeq(){
  bbDebugAssert(((*this).m__0seq==(*this).m__0stack->m__0seq),BB_T("Concurrent list modification"));
}

void t_std_collections_Stack_1Tt_mx2_NamespaceScope_2_Iterator::m_AssertCurrent(){
  bbDebugAssert(!(*this).m_AtEnd(),BB_T("Invalid list iterator"));
}

int bbCompare(const t_std_collections_Stack_1Tt_mx2_NamespaceScope_2_Iterator&x,const t_std_collections_Stack_1Tt_mx2_NamespaceScope_2_Iterator&y){
  if(int t=bbCompare(x.m__0stack,y.m__0stack)) return t;
  if(int t=bbCompare(x.m__0index,y.m__0index)) return t;
  if(int t=bbCompare(x.m__0seq,y.m__0seq)) return t;
  return 0;
}

void bbGCMark(const t_std_collections_Stack_1Tt_mx2_NamespaceScope_2_Iterator&t){
  bbGCMark(t.m__0stack);
}

t_std_collections_Stack_1Tt_mx2_NamespaceScope_2_BackwardsIterator::t_std_collections_Stack_1Tt_mx2_NamespaceScope_2_BackwardsIterator(t_std_collections_Stack_1Tt_mx2_NamespaceScope_2* l_stack,bbInt l_index){
  (*this).m__0stack=l_stack;
  (*this).m__0index=l_index;
  (*this).m__0seq=l_stack->m__0seq;
}

void t_std_collections_Stack_1Tt_mx2_NamespaceScope_2_BackwardsIterator::m_Insert(t_mx2_NamespaceScope* l_value){
  (*this).m_AssertSeq();
  (*this).m__0index+=1;
  (*this).m__0stack->m_Insert((*this).m__0index,l_value);
  (*this).m__0seq=(*this).m__0stack->m__0seq;
}

void t_std_collections_Stack_1Tt_mx2_NamespaceScope_2_BackwardsIterator::m_Erase(){
  (*this).m_AssertCurrent();
  (*this).m__0index-=1;
  (*this).m__0stack->m_Erase(((*this).m__0index+1));
  (*this).m__0seq=(*this).m__0stack->m__0seq;
}

void t_std_collections_Stack_1Tt_mx2_NamespaceScope_2_BackwardsIterator::m_Current(t_mx2_NamespaceScope* l_current){
  (*this).m_AssertCurrent();
  (*this).m__0stack->m__0data->at((*this).m__0index)=l_current;
}

t_mx2_NamespaceScope* t_std_collections_Stack_1Tt_mx2_NamespaceScope_2_BackwardsIterator::m_Current(){
  (*this).m_AssertCurrent();
  return (*this).m__0stack->m__0data->at((*this).m__0index);
}

void t_std_collections_Stack_1Tt_mx2_NamespaceScope_2_BackwardsIterator::m_Bump(){
  (*this).m_AssertCurrent();
  (*this).m__0index-=1;
}

bbBool t_std_collections_Stack_1Tt_mx2_NamespaceScope_2_BackwardsIterator::m_AtEnd(){
  (*this).m_AssertSeq();
  return ((*this).m__0index==-1);
}

void t_std_collections_Stack_1Tt_mx2_NamespaceScope_2_BackwardsIterator::m_AssertSeq(){
  bbDebugAssert(((*this).m__0seq==(*this).m__0stack->m__0seq),BB_T("Concurrent list modification"));
}

void t_std_collections_Stack_1Tt_mx2_NamespaceScope_2_BackwardsIterator::m_AssertCurrent(){
  bbDebugAssert(!(*this).m_AtEnd(),BB_T("Invalid list iterator"));
}

int bbCompare(const t_std_collections_Stack_1Tt_mx2_NamespaceScope_2_BackwardsIterator&x,const t_std_collections_Stack_1Tt_mx2_NamespaceScope_2_BackwardsIterator&y){
  if(int t=bbCompare(x.m__0stack,y.m__0stack)) return t;
  if(int t=bbCompare(x.m__0index,y.m__0index)) return t;
  if(int t=bbCompare(x.m__0seq,y.m__0seq)) return t;
  return 0;
}

void bbGCMark(const t_std_collections_Stack_1Tt_mx2_NamespaceScope_2_BackwardsIterator&t){
  bbGCMark(t.m__0stack);
}

void t_std_collections_Stack_1Tt_mx2_NamespaceScope_2::gcMark(){
  bbGCMark(m__0data);
}

t_std_collections_Stack_1Tt_mx2_NamespaceScope_2::t_std_collections_Stack_1Tt_mx2_NamespaceScope_2(t_std_collections_List_1Tt_mx2_NamespaceScope_2* l_values){
  g_std_collections_Stack_1Tt_mx2_NamespaceScope_2_AddAll_1Tt_std_collections_List_1Tt_mx2_NamespaceScope_2_2(this,l_values);
}

t_std_collections_Stack_1Tt_mx2_NamespaceScope_2::t_std_collections_Stack_1Tt_mx2_NamespaceScope_2(t_std_collections_Stack_1Tt_mx2_NamespaceScope_2* l_values){
  struct f0_t : public bbGCFrame{
    bbArray<bbGCVar<t_mx2_NamespaceScope>>* t0{};
    void gcMark(){
      bbGCMarkPtr(t0);
    }
  }f0{};
  this->m__0length=l_values->m_Length();
  this->m__0data=bbArray<bbGCVar<t_mx2_NamespaceScope>>::create(this->m__0length);
  (f0.t0=l_values->m_Data())->copyTo(this->m__0data,bbInt(0),bbInt(0),this->m__0length);
}

t_std_collections_Stack_1Tt_mx2_NamespaceScope_2::t_std_collections_Stack_1Tt_mx2_NamespaceScope_2(bbArray<bbGCVar<t_mx2_NamespaceScope>>* l_values){
  this->m_AddAll(l_values);
}

t_std_collections_Stack_1Tt_mx2_NamespaceScope_2::t_std_collections_Stack_1Tt_mx2_NamespaceScope_2(bbInt l_length){
  this->m__0length=l_length;
  this->m__0data=bbArray<bbGCVar<t_mx2_NamespaceScope>>::create(this->m__0length);
}

t_std_collections_Stack_1Tt_mx2_NamespaceScope_2::t_std_collections_Stack_1Tt_mx2_NamespaceScope_2(){
  this->m__0data=bbArray<bbGCVar<t_mx2_NamespaceScope>>::create(10);
}

void t_std_collections_Stack_1Tt_mx2_NamespaceScope_2::m__idxeq(bbInt l_index,t_mx2_NamespaceScope* l_value){
  bbDebugAssert(((l_index>=bbInt(0))&&(l_index<this->m__0length)),BB_T("Stack index out of range"));
  this->m__0data->at(l_index)=l_value;
}

t_mx2_NamespaceScope* t_std_collections_Stack_1Tt_mx2_NamespaceScope_2::m__idx(bbInt l_index){
  bbDebugAssert(((l_index>=bbInt(0))&&(l_index<this->m__0length)),BB_T("Stack index out of range"));
  return this->m__0data->at(l_index);
}

t_mx2_NamespaceScope* t_std_collections_Stack_1Tt_mx2_NamespaceScope_2::m_Top(){
  bbDebugAssert(bbBool(this->m__0length),BB_T("Stack is empty"));
  return this->m__0data->at((this->m__0length-1));
}

bbArray<bbGCVar<t_mx2_NamespaceScope>>* t_std_collections_Stack_1Tt_mx2_NamespaceScope_2::m_ToArray(){
  return this->m__0data->slice(bbInt(0),this->m__0length);
}

void t_std_collections_Stack_1Tt_mx2_NamespaceScope_2::m_Swap(bbInt l_index1,bbInt l_index2){
  struct f0_t : public bbGCFrame{
    t_mx2_NamespaceScope* l_t{};
    void gcMark(){
      bbGCMarkPtr(l_t);
    }
  }f0{};
  bbDebugAssert(((((l_index1>=bbInt(0))&&(l_index1<this->m__0length))&&(l_index2>=bbInt(0)))&&(l_index2<this->m__0length)),BB_T("Stack index out of range"));
  f0.l_t=this->m__0data->at(l_index1);
  this->m__0data->at(l_index1)=this->m__0data->at(l_index2);
  this->m__0data->at(l_index2)=f0.l_t;
}

void t_std_collections_Stack_1Tt_mx2_NamespaceScope_2::m_Sort(bbFunction<bbInt(t_mx2_NamespaceScope*,t_mx2_NamespaceScope*)> l_compareFunc,bbInt l_lo,bbInt l_hi){
  if((l_hi<=l_lo)){
    return;
  }
  if(((l_lo+1)==l_hi)){
    if((l_compareFunc(this->m__0data->at(l_hi),this->m__0data->at(l_lo))<bbInt(0))){
      this->m_Swap(l_hi,l_lo);
    }
    return;
  }
  bbInt l_i=((l_lo+l_hi)/2);
  if((l_compareFunc(this->m__0data->at(l_i),this->m__0data->at(l_lo))<bbInt(0))){
    this->m_Swap(l_i,l_lo);
  }
  if((l_compareFunc(this->m__0data->at(l_hi),this->m__0data->at(l_i))<bbInt(0))){
    this->m_Swap(l_hi,l_i);
    if((l_compareFunc(this->m__0data->at(l_i),this->m__0data->at(l_lo))<bbInt(0))){
      this->m_Swap(l_i,l_lo);
    }
  }
  bbInt l_x=(l_lo+1);
  bbInt l_y=(l_hi-1);
  do{
    struct f1_t : public bbGCFrame{
      t_mx2_NamespaceScope* l_p{};
      void gcMark(){
        bbGCMarkPtr(l_p);
      }
    }f1{};
    f1.l_p=this->m__0data->at(l_i);
    while((l_compareFunc(this->m__0data->at(l_x),f1.l_p)<bbInt(0))){
      l_x+=1;
    }
    while((l_compareFunc(f1.l_p,this->m__0data->at(l_y))<bbInt(0))){
      l_y-=1;
    }
    if((l_x>l_y)){
      break;
    }
    if((l_x<l_y)){
      this->m_Swap(l_x,l_y);
      if((l_i==l_x)){
        l_i=l_y;
      }else if((l_i==l_y)){
        l_i=l_x;
      }
    }
    l_x+=1;
    l_y-=1;
  }while(!((l_x>l_y)));
  this->m_Sort(l_compareFunc,l_lo,l_y);
  this->m_Sort(l_compareFunc,l_x,l_hi);
}

void t_std_collections_Stack_1Tt_mx2_NamespaceScope_2::m_Sort(bbFunction<bbInt(t_mx2_NamespaceScope*,t_mx2_NamespaceScope*)> l_compareFunc){
  this->m_Sort(l_compareFunc,bbInt(0),(this->m__0length-1));
}

void t_std_collections_Stack_1Tt_mx2_NamespaceScope_2::m_Sort(bbBool l_ascending){
  if(l_ascending){
    struct lambda20 : public bbFunction<bbInt(t_mx2_NamespaceScope*,t_mx2_NamespaceScope*)>::Rep{
      t_std_collections_Stack_1Tt_mx2_NamespaceScope_2* l_self;
      lambda20(t_std_collections_Stack_1Tt_mx2_NamespaceScope_2* l_self):l_self(l_self){
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
      t_std_collections_Stack_1Tt_mx2_NamespaceScope_2* l_self;
      lambda21(t_std_collections_Stack_1Tt_mx2_NamespaceScope_2* l_self):l_self(l_self){
      }
      bbInt invoke(t_mx2_NamespaceScope* l_x,t_mx2_NamespaceScope* l_y){
        return bbCompare(l_y,l_x);
      }
      void gcMark(){
        bbGCMarkPtr(l_self);
      }
    };
    this->m_Sort(bbFunction<bbInt(t_mx2_NamespaceScope*,t_mx2_NamespaceScope*)>(new lambda21(this)));
  }
}

t_std_collections_Stack_1Tt_mx2_NamespaceScope_2* t_std_collections_Stack_1Tt_mx2_NamespaceScope_2::m_Slice(bbInt l_index1,bbInt l_index2){
  struct f0_t : public bbGCFrame{
    bbArray<bbGCVar<t_mx2_NamespaceScope>>* t0{};
    void gcMark(){
      bbGCMarkPtr(t0);
    }
  }f0{};
  if((l_index1<bbInt(0))){
    l_index1=g_monkey_math_Max_1i((l_index1+this->m__0length),bbInt(0));
  }else if((l_index1>this->m__0length)){
    l_index1=this->m__0length;
  }
  if((l_index2<bbInt(0))){
    l_index2=g_monkey_math_Max_1i((l_index2+this->m__0length),l_index1);
  }else if((l_index2>this->m__0length)){
    l_index2=this->m__0length;
  }else if((l_index2<l_index1)){
    l_index2=l_index1;
  }
  return bbGCNew<t_std_collections_Stack_1Tt_mx2_NamespaceScope_2>(f0.t0=this->m__0data->slice(l_index1,l_index2));
}

t_std_collections_Stack_1Tt_mx2_NamespaceScope_2* t_std_collections_Stack_1Tt_mx2_NamespaceScope_2::m_Slice(bbInt l_index){
  return this->m_Slice(l_index,this->m__0length);
}

void t_std_collections_Stack_1Tt_mx2_NamespaceScope_2::m_Set(bbInt l_index,t_mx2_NamespaceScope* l_value){
  bbDebugAssert(((l_index>=bbInt(0))&&(l_index<this->m__0length)),BB_T("Stack index out of range"));
  this->m__0data->at(l_index)=l_value;
}

void t_std_collections_Stack_1Tt_mx2_NamespaceScope_2::m_Resize(bbInt l_length){
  bbDebugAssert((l_length>=bbInt(0)),BB_T("Debug assert failed"));
  {
    bbInt l_i=l_length;
    for(;(l_i<this->m__0length);l_i+=1){
      this->m__0data->at(l_i)=((t_mx2_NamespaceScope*)0);
    }
  }
  this->m_Reserve(l_length);
  this->m__0length=l_length;
  this->m__0seq+=1;
}

void t_std_collections_Stack_1Tt_mx2_NamespaceScope_2::m_Reserve(bbInt l_capacity){
  struct f0_t : public bbGCFrame{
    bbArray<bbGCVar<t_mx2_NamespaceScope>>* l_data{};
    void gcMark(){
      bbGCMarkPtr(l_data);
    }
  }f0{};
  bbDebugAssert((l_capacity>=bbInt(0)),BB_T("Debug assert failed"));
  if((this->m__0data->length()>=l_capacity)){
    return;
  }
  l_capacity=g_monkey_math_Max_1i(((this->m__0length*2)+this->m__0length),l_capacity);
  f0.l_data=bbArray<bbGCVar<t_mx2_NamespaceScope>>::create(l_capacity);
  this->m__0data->copyTo(f0.l_data,bbInt(0),bbInt(0),this->m__0length);
  this->m__0data=f0.l_data;
}

bbBool t_std_collections_Stack_1Tt_mx2_NamespaceScope_2::m_RemoveLast(t_mx2_NamespaceScope* l_value,bbInt l_start){
  bbInt l_i=this->m_FindLastIndex(l_value,l_start);
  if((l_i==-1)){
    return false;
  }
  this->m_Erase(l_i);
  return true;
}

bbInt t_std_collections_Stack_1Tt_mx2_NamespaceScope_2::m_RemoveEach(t_mx2_NamespaceScope* l_value){
  bbInt l_put=bbInt(0);
  bbInt l_n=bbInt(0);
  {
    bbInt l_get=bbInt(0);
    for(;(l_get<this->m__0length);l_get+=1){
      if((this->m__0data->at(l_get)==l_value)){
        l_n+=1;
        continue;
      }
      this->m__0data->at(l_put)=this->m__0data->at(l_get);
      l_put+=1;
    }
  }
  this->m_Resize(l_put);
  return l_n;
}

bbBool t_std_collections_Stack_1Tt_mx2_NamespaceScope_2::m_Remove(t_mx2_NamespaceScope* l_value,bbInt l_start){
  bbInt l_i=this->m_FindIndex(l_value,l_start);
  if((l_i==-1)){
    return false;
  }
  this->m_Erase(l_i);
  return true;
}

void t_std_collections_Stack_1Tt_mx2_NamespaceScope_2::m_Push(t_mx2_NamespaceScope* l_value){
  this->m_Add(l_value);
}

t_mx2_NamespaceScope* t_std_collections_Stack_1Tt_mx2_NamespaceScope_2::m_Pop(){
  struct f0_t : public bbGCFrame{
    t_mx2_NamespaceScope* l_value{};
    void gcMark(){
      bbGCMarkPtr(l_value);
    }
  }f0{};
  bbDebugAssert(bbBool(this->m__0length),BB_T("Stack is empty"));
  this->m__0length-=1;
  this->m__0seq+=1;
  f0.l_value=this->m__0data->at(this->m__0length);
  this->m__0data->at(this->m__0length)=((t_mx2_NamespaceScope*)0);
  return f0.l_value;
}

bbInt t_std_collections_Stack_1Tt_mx2_NamespaceScope_2::m_Length(){
  return this->m__0length;
}

void t_std_collections_Stack_1Tt_mx2_NamespaceScope_2::m_Insert(bbInt l_index,t_mx2_NamespaceScope* l_value){
  bbDebugAssert(((l_index>=bbInt(0))&&(l_index<=this->m__0length)),BB_T("Debug assert failed"));
  this->m_Reserve((this->m__0length+1));
  this->m__0data->copyTo(this->m__0data,l_index,(l_index+1),(this->m__0length-l_index));
  this->m__0data->at(l_index)=l_value;
  this->m__0length+=1;
  this->m__0seq+=1;
}

t_mx2_NamespaceScope* t_std_collections_Stack_1Tt_mx2_NamespaceScope_2::m_Get(bbInt l_index){
  bbDebugAssert(((l_index>=bbInt(0))&&(l_index<this->m__0length)),BB_T("Stack index out of range"));
  return this->m__0data->at(l_index);
}

bbInt t_std_collections_Stack_1Tt_mx2_NamespaceScope_2::m_FindLastIndex(t_mx2_NamespaceScope* l_value,bbInt l_start){
  bbDebugAssert(((l_start>=bbInt(0))&&(l_start<=this->m__0length)),BB_T("Debug assert failed"));
  bbInt l_i=this->m__0length;
  while((l_i>l_start)){
    l_i-=1;
    if((this->m__0data->at(l_i)==l_value)){
      return l_i;
    }
  }
  return -1;
}

bbInt t_std_collections_Stack_1Tt_mx2_NamespaceScope_2::m_FindIndex(t_mx2_NamespaceScope* l_value,bbInt l_start){
  bbDebugAssert(((l_start>=bbInt(0))&&(l_start<=this->m__0length)),BB_T("Debug assert failed"));
  bbInt l_i=l_start;
  while((l_i<this->m__0length)){
    if((this->m__0data->at(l_i)==l_value)){
      return l_i;
    }
    l_i+=1;
  }
  return -1;
}

void t_std_collections_Stack_1Tt_mx2_NamespaceScope_2::m_Erase(bbInt l_index1,bbInt l_index2){
  bbDebugAssert((((((l_index1>=bbInt(0))&&(l_index1<=this->m__0length))&&(l_index2>=bbInt(0)))&&(l_index2<=this->m__0length))&&(l_index1<=l_index2)),BB_T("Debug assert failed"));
  if((l_index1==this->m__0length)){
    return;
  }
  this->m__0data->copyTo(this->m__0data,l_index2,l_index1,(this->m__0length-l_index2));
  this->m_Resize(((this->m__0length-l_index2)+l_index1));
}

void t_std_collections_Stack_1Tt_mx2_NamespaceScope_2::m_Erase(bbInt l_index){
  bbDebugAssert(((l_index>=bbInt(0))&&(l_index<=this->m__0length)),BB_T("Debug assert failed"));
  if((l_index==this->m__0length)){
    return;
  }
  this->m__0data->copyTo(this->m__0data,(l_index+1),l_index,((this->m__0length-l_index)-1));
  this->m_Resize((this->m__0length-1));
}

bbBool t_std_collections_Stack_1Tt_mx2_NamespaceScope_2::m_Empty(){
  return (this->m__0length==bbInt(0));
}

bbArray<bbGCVar<t_mx2_NamespaceScope>>* t_std_collections_Stack_1Tt_mx2_NamespaceScope_2::m_Data(){
  return this->m__0data;
}

bbBool t_std_collections_Stack_1Tt_mx2_NamespaceScope_2::m_Contains(t_mx2_NamespaceScope* l_value){
  return (this->m_FindIndex(l_value,bbInt(0))!=-1);
}

void t_std_collections_Stack_1Tt_mx2_NamespaceScope_2::m_Clear(){
  this->m_Resize(bbInt(0));
}

bbInt t_std_collections_Stack_1Tt_mx2_NamespaceScope_2::m_Capacity(){
  return this->m__0data->length();
}

t_std_collections_Stack_1Tt_mx2_NamespaceScope_2_BackwardsIterator t_std_collections_Stack_1Tt_mx2_NamespaceScope_2::m_Backwards(){
  return t_std_collections_Stack_1Tt_mx2_NamespaceScope_2_BackwardsIterator(this,(this->m__0length-1));
}

t_std_collections_Stack_1Tt_mx2_NamespaceScope_2_Iterator t_std_collections_Stack_1Tt_mx2_NamespaceScope_2::m_All(){
  return t_std_collections_Stack_1Tt_mx2_NamespaceScope_2_Iterator(this,bbInt(0));
}

void t_std_collections_Stack_1Tt_mx2_NamespaceScope_2::m_AddAll(bbArray<bbGCVar<t_mx2_NamespaceScope>>* l_values){
  this->m_Reserve((this->m__0length+l_values->length()));
  l_values->copyTo(this->m__0data,bbInt(0),this->m__0length,l_values->length());
  this->m_Resize((this->m__0length+l_values->length()));
}

void t_std_collections_Stack_1Tt_mx2_NamespaceScope_2::m_Add(t_mx2_NamespaceScope* l_value){
  this->m_Reserve((this->m__0length+1));
  this->m__0data->at(this->m__0length)=l_value;
  this->m__0length+=1;
  this->m__0seq+=1;
}

t_std_collections_Stack_1Tt_mx2_PNode_2_Iterator::t_std_collections_Stack_1Tt_mx2_PNode_2_Iterator(t_std_collections_Stack_1Tt_mx2_PNode_2* l_stack,bbInt l_index){
  (*this).m__0stack=l_stack;
  (*this).m__0index=l_index;
  (*this).m__0seq=l_stack->m__0seq;
}

void t_std_collections_Stack_1Tt_mx2_PNode_2_Iterator::m_Insert(t_mx2_PNode* l_value){
  (*this).m_AssertSeq();
  (*this).m__0stack->m_Insert((*this).m__0index,l_value);
  (*this).m__0seq=(*this).m__0stack->m__0seq;
}

void t_std_collections_Stack_1Tt_mx2_PNode_2_Iterator::m_Erase(){
  (*this).m_AssertSeq();
  (*this).m__0stack->m_Erase((*this).m__0index);
  (*this).m__0seq=(*this).m__0stack->m__0seq;
}

void t_std_collections_Stack_1Tt_mx2_PNode_2_Iterator::m_Current(t_mx2_PNode* l_current){
  (*this).m_AssertCurrent();
  (*this).m__0stack->m__0data->at((*this).m__0index)=l_current;
}

t_mx2_PNode* t_std_collections_Stack_1Tt_mx2_PNode_2_Iterator::m_Current(){
  (*this).m_AssertCurrent();
  return (*this).m__0stack->m__0data->at((*this).m__0index);
}

void t_std_collections_Stack_1Tt_mx2_PNode_2_Iterator::m_Bump(){
  (*this).m_AssertCurrent();
  (*this).m__0index+=1;
}

bbBool t_std_collections_Stack_1Tt_mx2_PNode_2_Iterator::m_AtEnd(){
  (*this).m_AssertSeq();
  return ((*this).m__0index==(*this).m__0stack->m__0length);
}

void t_std_collections_Stack_1Tt_mx2_PNode_2_Iterator::m_AssertSeq(){
  bbDebugAssert(((*this).m__0seq==(*this).m__0stack->m__0seq),BB_T("Concurrent list modification"));
}

void t_std_collections_Stack_1Tt_mx2_PNode_2_Iterator::m_AssertCurrent(){
  bbDebugAssert(!(*this).m_AtEnd(),BB_T("Invalid list iterator"));
}

int bbCompare(const t_std_collections_Stack_1Tt_mx2_PNode_2_Iterator&x,const t_std_collections_Stack_1Tt_mx2_PNode_2_Iterator&y){
  if(int t=bbCompare(x.m__0stack,y.m__0stack)) return t;
  if(int t=bbCompare(x.m__0index,y.m__0index)) return t;
  if(int t=bbCompare(x.m__0seq,y.m__0seq)) return t;
  return 0;
}

void bbGCMark(const t_std_collections_Stack_1Tt_mx2_PNode_2_Iterator&t){
  bbGCMark(t.m__0stack);
}

t_std_collections_Stack_1Tt_mx2_PNode_2_BackwardsIterator::t_std_collections_Stack_1Tt_mx2_PNode_2_BackwardsIterator(t_std_collections_Stack_1Tt_mx2_PNode_2* l_stack,bbInt l_index){
  (*this).m__0stack=l_stack;
  (*this).m__0index=l_index;
  (*this).m__0seq=l_stack->m__0seq;
}

void t_std_collections_Stack_1Tt_mx2_PNode_2_BackwardsIterator::m_Insert(t_mx2_PNode* l_value){
  (*this).m_AssertSeq();
  (*this).m__0index+=1;
  (*this).m__0stack->m_Insert((*this).m__0index,l_value);
  (*this).m__0seq=(*this).m__0stack->m__0seq;
}

void t_std_collections_Stack_1Tt_mx2_PNode_2_BackwardsIterator::m_Erase(){
  (*this).m_AssertCurrent();
  (*this).m__0index-=1;
  (*this).m__0stack->m_Erase(((*this).m__0index+1));
  (*this).m__0seq=(*this).m__0stack->m__0seq;
}

void t_std_collections_Stack_1Tt_mx2_PNode_2_BackwardsIterator::m_Current(t_mx2_PNode* l_current){
  (*this).m_AssertCurrent();
  (*this).m__0stack->m__0data->at((*this).m__0index)=l_current;
}

t_mx2_PNode* t_std_collections_Stack_1Tt_mx2_PNode_2_BackwardsIterator::m_Current(){
  (*this).m_AssertCurrent();
  return (*this).m__0stack->m__0data->at((*this).m__0index);
}

void t_std_collections_Stack_1Tt_mx2_PNode_2_BackwardsIterator::m_Bump(){
  (*this).m_AssertCurrent();
  (*this).m__0index-=1;
}

bbBool t_std_collections_Stack_1Tt_mx2_PNode_2_BackwardsIterator::m_AtEnd(){
  (*this).m_AssertSeq();
  return ((*this).m__0index==-1);
}

void t_std_collections_Stack_1Tt_mx2_PNode_2_BackwardsIterator::m_AssertSeq(){
  bbDebugAssert(((*this).m__0seq==(*this).m__0stack->m__0seq),BB_T("Concurrent list modification"));
}

void t_std_collections_Stack_1Tt_mx2_PNode_2_BackwardsIterator::m_AssertCurrent(){
  bbDebugAssert(!(*this).m_AtEnd(),BB_T("Invalid list iterator"));
}

int bbCompare(const t_std_collections_Stack_1Tt_mx2_PNode_2_BackwardsIterator&x,const t_std_collections_Stack_1Tt_mx2_PNode_2_BackwardsIterator&y){
  if(int t=bbCompare(x.m__0stack,y.m__0stack)) return t;
  if(int t=bbCompare(x.m__0index,y.m__0index)) return t;
  if(int t=bbCompare(x.m__0seq,y.m__0seq)) return t;
  return 0;
}

void bbGCMark(const t_std_collections_Stack_1Tt_mx2_PNode_2_BackwardsIterator&t){
  bbGCMark(t.m__0stack);
}

void t_std_collections_Stack_1Tt_mx2_PNode_2::gcMark(){
  bbGCMark(m__0data);
}

t_std_collections_Stack_1Tt_mx2_PNode_2::t_std_collections_Stack_1Tt_mx2_PNode_2(t_std_collections_List_1Tt_mx2_PNode_2* l_values){
  g_std_collections_Stack_1Tt_mx2_PNode_2_AddAll_1Tt_std_collections_List_1Tt_mx2_PNode_2_2(this,l_values);
}

t_std_collections_Stack_1Tt_mx2_PNode_2::t_std_collections_Stack_1Tt_mx2_PNode_2(t_std_collections_Stack_1Tt_mx2_PNode_2* l_values){
  struct f0_t : public bbGCFrame{
    bbArray<bbGCVar<t_mx2_PNode>>* t0{};
    void gcMark(){
      bbGCMarkPtr(t0);
    }
  }f0{};
  this->m__0length=l_values->m_Length();
  this->m__0data=bbArray<bbGCVar<t_mx2_PNode>>::create(this->m__0length);
  (f0.t0=l_values->m_Data())->copyTo(this->m__0data,bbInt(0),bbInt(0),this->m__0length);
}

t_std_collections_Stack_1Tt_mx2_PNode_2::t_std_collections_Stack_1Tt_mx2_PNode_2(bbArray<bbGCVar<t_mx2_PNode>>* l_values){
  this->m_AddAll(l_values);
}

t_std_collections_Stack_1Tt_mx2_PNode_2::t_std_collections_Stack_1Tt_mx2_PNode_2(bbInt l_length){
  this->m__0length=l_length;
  this->m__0data=bbArray<bbGCVar<t_mx2_PNode>>::create(this->m__0length);
}

t_std_collections_Stack_1Tt_mx2_PNode_2::t_std_collections_Stack_1Tt_mx2_PNode_2(){
  this->m__0data=bbArray<bbGCVar<t_mx2_PNode>>::create(10);
}

void t_std_collections_Stack_1Tt_mx2_PNode_2::m__idxeq(bbInt l_index,t_mx2_PNode* l_value){
  bbDebugAssert(((l_index>=bbInt(0))&&(l_index<this->m__0length)),BB_T("Stack index out of range"));
  this->m__0data->at(l_index)=l_value;
}

t_mx2_PNode* t_std_collections_Stack_1Tt_mx2_PNode_2::m__idx(bbInt l_index){
  bbDebugAssert(((l_index>=bbInt(0))&&(l_index<this->m__0length)),BB_T("Stack index out of range"));
  return this->m__0data->at(l_index);
}

t_mx2_PNode* t_std_collections_Stack_1Tt_mx2_PNode_2::m_Top(){
  bbDebugAssert(bbBool(this->m__0length),BB_T("Stack is empty"));
  return this->m__0data->at((this->m__0length-1));
}

bbArray<bbGCVar<t_mx2_PNode>>* t_std_collections_Stack_1Tt_mx2_PNode_2::m_ToArray(){
  return this->m__0data->slice(bbInt(0),this->m__0length);
}

void t_std_collections_Stack_1Tt_mx2_PNode_2::m_Swap(bbInt l_index1,bbInt l_index2){
  struct f0_t : public bbGCFrame{
    t_mx2_PNode* l_t{};
    void gcMark(){
      bbGCMarkPtr(l_t);
    }
  }f0{};
  bbDebugAssert(((((l_index1>=bbInt(0))&&(l_index1<this->m__0length))&&(l_index2>=bbInt(0)))&&(l_index2<this->m__0length)),BB_T("Stack index out of range"));
  f0.l_t=this->m__0data->at(l_index1);
  this->m__0data->at(l_index1)=this->m__0data->at(l_index2);
  this->m__0data->at(l_index2)=f0.l_t;
}

void t_std_collections_Stack_1Tt_mx2_PNode_2::m_Sort(bbFunction<bbInt(t_mx2_PNode*,t_mx2_PNode*)> l_compareFunc,bbInt l_lo,bbInt l_hi){
  if((l_hi<=l_lo)){
    return;
  }
  if(((l_lo+1)==l_hi)){
    if((l_compareFunc(this->m__0data->at(l_hi),this->m__0data->at(l_lo))<bbInt(0))){
      this->m_Swap(l_hi,l_lo);
    }
    return;
  }
  bbInt l_i=((l_lo+l_hi)/2);
  if((l_compareFunc(this->m__0data->at(l_i),this->m__0data->at(l_lo))<bbInt(0))){
    this->m_Swap(l_i,l_lo);
  }
  if((l_compareFunc(this->m__0data->at(l_hi),this->m__0data->at(l_i))<bbInt(0))){
    this->m_Swap(l_hi,l_i);
    if((l_compareFunc(this->m__0data->at(l_i),this->m__0data->at(l_lo))<bbInt(0))){
      this->m_Swap(l_i,l_lo);
    }
  }
  bbInt l_x=(l_lo+1);
  bbInt l_y=(l_hi-1);
  do{
    struct f1_t : public bbGCFrame{
      t_mx2_PNode* l_p{};
      void gcMark(){
        bbGCMarkPtr(l_p);
      }
    }f1{};
    f1.l_p=this->m__0data->at(l_i);
    while((l_compareFunc(this->m__0data->at(l_x),f1.l_p)<bbInt(0))){
      l_x+=1;
    }
    while((l_compareFunc(f1.l_p,this->m__0data->at(l_y))<bbInt(0))){
      l_y-=1;
    }
    if((l_x>l_y)){
      break;
    }
    if((l_x<l_y)){
      this->m_Swap(l_x,l_y);
      if((l_i==l_x)){
        l_i=l_y;
      }else if((l_i==l_y)){
        l_i=l_x;
      }
    }
    l_x+=1;
    l_y-=1;
  }while(!((l_x>l_y)));
  this->m_Sort(l_compareFunc,l_lo,l_y);
  this->m_Sort(l_compareFunc,l_x,l_hi);
}

void t_std_collections_Stack_1Tt_mx2_PNode_2::m_Sort(bbFunction<bbInt(t_mx2_PNode*,t_mx2_PNode*)> l_compareFunc){
  this->m_Sort(l_compareFunc,bbInt(0),(this->m__0length-1));
}

void t_std_collections_Stack_1Tt_mx2_PNode_2::m_Sort(bbBool l_ascending){
  if(l_ascending){
    struct lambda22 : public bbFunction<bbInt(t_mx2_PNode*,t_mx2_PNode*)>::Rep{
      t_std_collections_Stack_1Tt_mx2_PNode_2* l_self;
      lambda22(t_std_collections_Stack_1Tt_mx2_PNode_2* l_self):l_self(l_self){
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
      t_std_collections_Stack_1Tt_mx2_PNode_2* l_self;
      lambda23(t_std_collections_Stack_1Tt_mx2_PNode_2* l_self):l_self(l_self){
      }
      bbInt invoke(t_mx2_PNode* l_x,t_mx2_PNode* l_y){
        return bbCompare(l_y,l_x);
      }
      void gcMark(){
        bbGCMarkPtr(l_self);
      }
    };
    this->m_Sort(bbFunction<bbInt(t_mx2_PNode*,t_mx2_PNode*)>(new lambda23(this)));
  }
}

t_std_collections_Stack_1Tt_mx2_PNode_2* t_std_collections_Stack_1Tt_mx2_PNode_2::m_Slice(bbInt l_index1,bbInt l_index2){
  struct f0_t : public bbGCFrame{
    bbArray<bbGCVar<t_mx2_PNode>>* t0{};
    void gcMark(){
      bbGCMarkPtr(t0);
    }
  }f0{};
  if((l_index1<bbInt(0))){
    l_index1=g_monkey_math_Max_1i((l_index1+this->m__0length),bbInt(0));
  }else if((l_index1>this->m__0length)){
    l_index1=this->m__0length;
  }
  if((l_index2<bbInt(0))){
    l_index2=g_monkey_math_Max_1i((l_index2+this->m__0length),l_index1);
  }else if((l_index2>this->m__0length)){
    l_index2=this->m__0length;
  }else if((l_index2<l_index1)){
    l_index2=l_index1;
  }
  return bbGCNew<t_std_collections_Stack_1Tt_mx2_PNode_2>(f0.t0=this->m__0data->slice(l_index1,l_index2));
}

t_std_collections_Stack_1Tt_mx2_PNode_2* t_std_collections_Stack_1Tt_mx2_PNode_2::m_Slice(bbInt l_index){
  return this->m_Slice(l_index,this->m__0length);
}

void t_std_collections_Stack_1Tt_mx2_PNode_2::m_Set(bbInt l_index,t_mx2_PNode* l_value){
  bbDebugAssert(((l_index>=bbInt(0))&&(l_index<this->m__0length)),BB_T("Stack index out of range"));
  this->m__0data->at(l_index)=l_value;
}

void t_std_collections_Stack_1Tt_mx2_PNode_2::m_Resize(bbInt l_length){
  bbDebugAssert((l_length>=bbInt(0)),BB_T("Debug assert failed"));
  {
    bbInt l_i=l_length;
    for(;(l_i<this->m__0length);l_i+=1){
      this->m__0data->at(l_i)=((t_mx2_PNode*)0);
    }
  }
  this->m_Reserve(l_length);
  this->m__0length=l_length;
  this->m__0seq+=1;
}

void t_std_collections_Stack_1Tt_mx2_PNode_2::m_Reserve(bbInt l_capacity){
  struct f0_t : public bbGCFrame{
    bbArray<bbGCVar<t_mx2_PNode>>* l_data{};
    void gcMark(){
      bbGCMarkPtr(l_data);
    }
  }f0{};
  bbDebugAssert((l_capacity>=bbInt(0)),BB_T("Debug assert failed"));
  if((this->m__0data->length()>=l_capacity)){
    return;
  }
  l_capacity=g_monkey_math_Max_1i(((this->m__0length*2)+this->m__0length),l_capacity);
  f0.l_data=bbArray<bbGCVar<t_mx2_PNode>>::create(l_capacity);
  this->m__0data->copyTo(f0.l_data,bbInt(0),bbInt(0),this->m__0length);
  this->m__0data=f0.l_data;
}

bbBool t_std_collections_Stack_1Tt_mx2_PNode_2::m_RemoveLast(t_mx2_PNode* l_value,bbInt l_start){
  bbInt l_i=this->m_FindLastIndex(l_value,l_start);
  if((l_i==-1)){
    return false;
  }
  this->m_Erase(l_i);
  return true;
}

bbInt t_std_collections_Stack_1Tt_mx2_PNode_2::m_RemoveEach(t_mx2_PNode* l_value){
  bbInt l_put=bbInt(0);
  bbInt l_n=bbInt(0);
  {
    bbInt l_get=bbInt(0);
    for(;(l_get<this->m__0length);l_get+=1){
      if((this->m__0data->at(l_get)==l_value)){
        l_n+=1;
        continue;
      }
      this->m__0data->at(l_put)=this->m__0data->at(l_get);
      l_put+=1;
    }
  }
  this->m_Resize(l_put);
  return l_n;
}

bbBool t_std_collections_Stack_1Tt_mx2_PNode_2::m_Remove(t_mx2_PNode* l_value,bbInt l_start){
  bbInt l_i=this->m_FindIndex(l_value,l_start);
  if((l_i==-1)){
    return false;
  }
  this->m_Erase(l_i);
  return true;
}

void t_std_collections_Stack_1Tt_mx2_PNode_2::m_Push(t_mx2_PNode* l_value){
  this->m_Add(l_value);
}

t_mx2_PNode* t_std_collections_Stack_1Tt_mx2_PNode_2::m_Pop(){
  struct f0_t : public bbGCFrame{
    t_mx2_PNode* l_value{};
    void gcMark(){
      bbGCMarkPtr(l_value);
    }
  }f0{};
  bbDebugAssert(bbBool(this->m__0length),BB_T("Stack is empty"));
  this->m__0length-=1;
  this->m__0seq+=1;
  f0.l_value=this->m__0data->at(this->m__0length);
  this->m__0data->at(this->m__0length)=((t_mx2_PNode*)0);
  return f0.l_value;
}

bbInt t_std_collections_Stack_1Tt_mx2_PNode_2::m_Length(){
  return this->m__0length;
}

void t_std_collections_Stack_1Tt_mx2_PNode_2::m_Insert(bbInt l_index,t_mx2_PNode* l_value){
  bbDebugAssert(((l_index>=bbInt(0))&&(l_index<=this->m__0length)),BB_T("Debug assert failed"));
  this->m_Reserve((this->m__0length+1));
  this->m__0data->copyTo(this->m__0data,l_index,(l_index+1),(this->m__0length-l_index));
  this->m__0data->at(l_index)=l_value;
  this->m__0length+=1;
  this->m__0seq+=1;
}

t_mx2_PNode* t_std_collections_Stack_1Tt_mx2_PNode_2::m_Get(bbInt l_index){
  bbDebugAssert(((l_index>=bbInt(0))&&(l_index<this->m__0length)),BB_T("Stack index out of range"));
  return this->m__0data->at(l_index);
}

bbInt t_std_collections_Stack_1Tt_mx2_PNode_2::m_FindLastIndex(t_mx2_PNode* l_value,bbInt l_start){
  bbDebugAssert(((l_start>=bbInt(0))&&(l_start<=this->m__0length)),BB_T("Debug assert failed"));
  bbInt l_i=this->m__0length;
  while((l_i>l_start)){
    l_i-=1;
    if((this->m__0data->at(l_i)==l_value)){
      return l_i;
    }
  }
  return -1;
}

bbInt t_std_collections_Stack_1Tt_mx2_PNode_2::m_FindIndex(t_mx2_PNode* l_value,bbInt l_start){
  bbDebugAssert(((l_start>=bbInt(0))&&(l_start<=this->m__0length)),BB_T("Debug assert failed"));
  bbInt l_i=l_start;
  while((l_i<this->m__0length)){
    if((this->m__0data->at(l_i)==l_value)){
      return l_i;
    }
    l_i+=1;
  }
  return -1;
}

void t_std_collections_Stack_1Tt_mx2_PNode_2::m_Erase(bbInt l_index1,bbInt l_index2){
  bbDebugAssert((((((l_index1>=bbInt(0))&&(l_index1<=this->m__0length))&&(l_index2>=bbInt(0)))&&(l_index2<=this->m__0length))&&(l_index1<=l_index2)),BB_T("Debug assert failed"));
  if((l_index1==this->m__0length)){
    return;
  }
  this->m__0data->copyTo(this->m__0data,l_index2,l_index1,(this->m__0length-l_index2));
  this->m_Resize(((this->m__0length-l_index2)+l_index1));
}

void t_std_collections_Stack_1Tt_mx2_PNode_2::m_Erase(bbInt l_index){
  bbDebugAssert(((l_index>=bbInt(0))&&(l_index<=this->m__0length)),BB_T("Debug assert failed"));
  if((l_index==this->m__0length)){
    return;
  }
  this->m__0data->copyTo(this->m__0data,(l_index+1),l_index,((this->m__0length-l_index)-1));
  this->m_Resize((this->m__0length-1));
}

bbBool t_std_collections_Stack_1Tt_mx2_PNode_2::m_Empty(){
  return (this->m__0length==bbInt(0));
}

bbArray<bbGCVar<t_mx2_PNode>>* t_std_collections_Stack_1Tt_mx2_PNode_2::m_Data(){
  return this->m__0data;
}

bbBool t_std_collections_Stack_1Tt_mx2_PNode_2::m_Contains(t_mx2_PNode* l_value){
  return (this->m_FindIndex(l_value,bbInt(0))!=-1);
}

void t_std_collections_Stack_1Tt_mx2_PNode_2::m_Clear(){
  this->m_Resize(bbInt(0));
}

bbInt t_std_collections_Stack_1Tt_mx2_PNode_2::m_Capacity(){
  return this->m__0data->length();
}

t_std_collections_Stack_1Tt_mx2_PNode_2_BackwardsIterator t_std_collections_Stack_1Tt_mx2_PNode_2::m_Backwards(){
  return t_std_collections_Stack_1Tt_mx2_PNode_2_BackwardsIterator(this,(this->m__0length-1));
}

t_std_collections_Stack_1Tt_mx2_PNode_2_Iterator t_std_collections_Stack_1Tt_mx2_PNode_2::m_All(){
  return t_std_collections_Stack_1Tt_mx2_PNode_2_Iterator(this,bbInt(0));
}

void t_std_collections_Stack_1Tt_mx2_PNode_2::m_AddAll(bbArray<bbGCVar<t_mx2_PNode>>* l_values){
  this->m_Reserve((this->m__0length+l_values->length()));
  l_values->copyTo(this->m__0data,bbInt(0),this->m__0length,l_values->length());
  this->m_Resize((this->m__0length+l_values->length()));
}

void t_std_collections_Stack_1Tt_mx2_PNode_2::m_Add(t_mx2_PNode* l_value){
  this->m_Reserve((this->m__0length+1));
  this->m__0data->at(this->m__0length)=l_value;
  this->m__0length+=1;
  this->m__0seq+=1;
}

t_std_collections_Stack_1Tt_mx2_AliasType_2_Iterator::t_std_collections_Stack_1Tt_mx2_AliasType_2_Iterator(t_std_collections_Stack_1Tt_mx2_AliasType_2* l_stack,bbInt l_index){
  (*this).m__0stack=l_stack;
  (*this).m__0index=l_index;
  (*this).m__0seq=l_stack->m__0seq;
}

void t_std_collections_Stack_1Tt_mx2_AliasType_2_Iterator::m_Insert(t_mx2_AliasType* l_value){
  (*this).m_AssertSeq();
  (*this).m__0stack->m_Insert((*this).m__0index,l_value);
  (*this).m__0seq=(*this).m__0stack->m__0seq;
}

void t_std_collections_Stack_1Tt_mx2_AliasType_2_Iterator::m_Erase(){
  (*this).m_AssertSeq();
  (*this).m__0stack->m_Erase((*this).m__0index);
  (*this).m__0seq=(*this).m__0stack->m__0seq;
}

void t_std_collections_Stack_1Tt_mx2_AliasType_2_Iterator::m_Current(t_mx2_AliasType* l_current){
  (*this).m_AssertCurrent();
  (*this).m__0stack->m__0data->at((*this).m__0index)=l_current;
}

t_mx2_AliasType* t_std_collections_Stack_1Tt_mx2_AliasType_2_Iterator::m_Current(){
  (*this).m_AssertCurrent();
  return (*this).m__0stack->m__0data->at((*this).m__0index);
}

void t_std_collections_Stack_1Tt_mx2_AliasType_2_Iterator::m_Bump(){
  (*this).m_AssertCurrent();
  (*this).m__0index+=1;
}

bbBool t_std_collections_Stack_1Tt_mx2_AliasType_2_Iterator::m_AtEnd(){
  (*this).m_AssertSeq();
  return ((*this).m__0index==(*this).m__0stack->m__0length);
}

void t_std_collections_Stack_1Tt_mx2_AliasType_2_Iterator::m_AssertSeq(){
  bbDebugAssert(((*this).m__0seq==(*this).m__0stack->m__0seq),BB_T("Concurrent list modification"));
}

void t_std_collections_Stack_1Tt_mx2_AliasType_2_Iterator::m_AssertCurrent(){
  bbDebugAssert(!(*this).m_AtEnd(),BB_T("Invalid list iterator"));
}

int bbCompare(const t_std_collections_Stack_1Tt_mx2_AliasType_2_Iterator&x,const t_std_collections_Stack_1Tt_mx2_AliasType_2_Iterator&y){
  if(int t=bbCompare(x.m__0stack,y.m__0stack)) return t;
  if(int t=bbCompare(x.m__0index,y.m__0index)) return t;
  if(int t=bbCompare(x.m__0seq,y.m__0seq)) return t;
  return 0;
}

void bbGCMark(const t_std_collections_Stack_1Tt_mx2_AliasType_2_Iterator&t){
  bbGCMark(t.m__0stack);
}

t_std_collections_Stack_1Tt_mx2_AliasType_2_BackwardsIterator::t_std_collections_Stack_1Tt_mx2_AliasType_2_BackwardsIterator(t_std_collections_Stack_1Tt_mx2_AliasType_2* l_stack,bbInt l_index){
  (*this).m__0stack=l_stack;
  (*this).m__0index=l_index;
  (*this).m__0seq=l_stack->m__0seq;
}

void t_std_collections_Stack_1Tt_mx2_AliasType_2_BackwardsIterator::m_Insert(t_mx2_AliasType* l_value){
  (*this).m_AssertSeq();
  (*this).m__0index+=1;
  (*this).m__0stack->m_Insert((*this).m__0index,l_value);
  (*this).m__0seq=(*this).m__0stack->m__0seq;
}

void t_std_collections_Stack_1Tt_mx2_AliasType_2_BackwardsIterator::m_Erase(){
  (*this).m_AssertCurrent();
  (*this).m__0index-=1;
  (*this).m__0stack->m_Erase(((*this).m__0index+1));
  (*this).m__0seq=(*this).m__0stack->m__0seq;
}

void t_std_collections_Stack_1Tt_mx2_AliasType_2_BackwardsIterator::m_Current(t_mx2_AliasType* l_current){
  (*this).m_AssertCurrent();
  (*this).m__0stack->m__0data->at((*this).m__0index)=l_current;
}

t_mx2_AliasType* t_std_collections_Stack_1Tt_mx2_AliasType_2_BackwardsIterator::m_Current(){
  (*this).m_AssertCurrent();
  return (*this).m__0stack->m__0data->at((*this).m__0index);
}

void t_std_collections_Stack_1Tt_mx2_AliasType_2_BackwardsIterator::m_Bump(){
  (*this).m_AssertCurrent();
  (*this).m__0index-=1;
}

bbBool t_std_collections_Stack_1Tt_mx2_AliasType_2_BackwardsIterator::m_AtEnd(){
  (*this).m_AssertSeq();
  return ((*this).m__0index==-1);
}

void t_std_collections_Stack_1Tt_mx2_AliasType_2_BackwardsIterator::m_AssertSeq(){
  bbDebugAssert(((*this).m__0seq==(*this).m__0stack->m__0seq),BB_T("Concurrent list modification"));
}

void t_std_collections_Stack_1Tt_mx2_AliasType_2_BackwardsIterator::m_AssertCurrent(){
  bbDebugAssert(!(*this).m_AtEnd(),BB_T("Invalid list iterator"));
}

int bbCompare(const t_std_collections_Stack_1Tt_mx2_AliasType_2_BackwardsIterator&x,const t_std_collections_Stack_1Tt_mx2_AliasType_2_BackwardsIterator&y){
  if(int t=bbCompare(x.m__0stack,y.m__0stack)) return t;
  if(int t=bbCompare(x.m__0index,y.m__0index)) return t;
  if(int t=bbCompare(x.m__0seq,y.m__0seq)) return t;
  return 0;
}

void bbGCMark(const t_std_collections_Stack_1Tt_mx2_AliasType_2_BackwardsIterator&t){
  bbGCMark(t.m__0stack);
}

void t_std_collections_Stack_1Tt_mx2_AliasType_2::gcMark(){
  bbGCMark(m__0data);
}

t_std_collections_Stack_1Tt_mx2_AliasType_2::t_std_collections_Stack_1Tt_mx2_AliasType_2(t_std_collections_List_1Tt_mx2_AliasType_2* l_values){
  g_std_collections_Stack_1Tt_mx2_AliasType_2_AddAll_1Tt_std_collections_List_1Tt_mx2_AliasType_2_2(this,l_values);
}

t_std_collections_Stack_1Tt_mx2_AliasType_2::t_std_collections_Stack_1Tt_mx2_AliasType_2(t_std_collections_Stack_1Tt_mx2_AliasType_2* l_values){
  struct f0_t : public bbGCFrame{
    bbArray<bbGCVar<t_mx2_AliasType>>* t0{};
    void gcMark(){
      bbGCMarkPtr(t0);
    }
  }f0{};
  this->m__0length=l_values->m_Length();
  this->m__0data=bbArray<bbGCVar<t_mx2_AliasType>>::create(this->m__0length);
  (f0.t0=l_values->m_Data())->copyTo(this->m__0data,bbInt(0),bbInt(0),this->m__0length);
}

t_std_collections_Stack_1Tt_mx2_AliasType_2::t_std_collections_Stack_1Tt_mx2_AliasType_2(bbArray<bbGCVar<t_mx2_AliasType>>* l_values){
  this->m_AddAll(l_values);
}

t_std_collections_Stack_1Tt_mx2_AliasType_2::t_std_collections_Stack_1Tt_mx2_AliasType_2(bbInt l_length){
  this->m__0length=l_length;
  this->m__0data=bbArray<bbGCVar<t_mx2_AliasType>>::create(this->m__0length);
}

t_std_collections_Stack_1Tt_mx2_AliasType_2::t_std_collections_Stack_1Tt_mx2_AliasType_2(){
  this->m__0data=bbArray<bbGCVar<t_mx2_AliasType>>::create(10);
}

void t_std_collections_Stack_1Tt_mx2_AliasType_2::m__idxeq(bbInt l_index,t_mx2_AliasType* l_value){
  bbDebugAssert(((l_index>=bbInt(0))&&(l_index<this->m__0length)),BB_T("Stack index out of range"));
  this->m__0data->at(l_index)=l_value;
}

t_mx2_AliasType* t_std_collections_Stack_1Tt_mx2_AliasType_2::m__idx(bbInt l_index){
  bbDebugAssert(((l_index>=bbInt(0))&&(l_index<this->m__0length)),BB_T("Stack index out of range"));
  return this->m__0data->at(l_index);
}

t_mx2_AliasType* t_std_collections_Stack_1Tt_mx2_AliasType_2::m_Top(){
  bbDebugAssert(bbBool(this->m__0length),BB_T("Stack is empty"));
  return this->m__0data->at((this->m__0length-1));
}

bbArray<bbGCVar<t_mx2_AliasType>>* t_std_collections_Stack_1Tt_mx2_AliasType_2::m_ToArray(){
  return this->m__0data->slice(bbInt(0),this->m__0length);
}

void t_std_collections_Stack_1Tt_mx2_AliasType_2::m_Swap(bbInt l_index1,bbInt l_index2){
  struct f0_t : public bbGCFrame{
    t_mx2_AliasType* l_t{};
    void gcMark(){
      bbGCMarkPtr(l_t);
    }
  }f0{};
  bbDebugAssert(((((l_index1>=bbInt(0))&&(l_index1<this->m__0length))&&(l_index2>=bbInt(0)))&&(l_index2<this->m__0length)),BB_T("Stack index out of range"));
  f0.l_t=this->m__0data->at(l_index1);
  this->m__0data->at(l_index1)=this->m__0data->at(l_index2);
  this->m__0data->at(l_index2)=f0.l_t;
}

void t_std_collections_Stack_1Tt_mx2_AliasType_2::m_Sort(bbFunction<bbInt(t_mx2_AliasType*,t_mx2_AliasType*)> l_compareFunc,bbInt l_lo,bbInt l_hi){
  if((l_hi<=l_lo)){
    return;
  }
  if(((l_lo+1)==l_hi)){
    if((l_compareFunc(this->m__0data->at(l_hi),this->m__0data->at(l_lo))<bbInt(0))){
      this->m_Swap(l_hi,l_lo);
    }
    return;
  }
  bbInt l_i=((l_lo+l_hi)/2);
  if((l_compareFunc(this->m__0data->at(l_i),this->m__0data->at(l_lo))<bbInt(0))){
    this->m_Swap(l_i,l_lo);
  }
  if((l_compareFunc(this->m__0data->at(l_hi),this->m__0data->at(l_i))<bbInt(0))){
    this->m_Swap(l_hi,l_i);
    if((l_compareFunc(this->m__0data->at(l_i),this->m__0data->at(l_lo))<bbInt(0))){
      this->m_Swap(l_i,l_lo);
    }
  }
  bbInt l_x=(l_lo+1);
  bbInt l_y=(l_hi-1);
  do{
    struct f1_t : public bbGCFrame{
      t_mx2_AliasType* l_p{};
      void gcMark(){
        bbGCMarkPtr(l_p);
      }
    }f1{};
    f1.l_p=this->m__0data->at(l_i);
    while((l_compareFunc(this->m__0data->at(l_x),f1.l_p)<bbInt(0))){
      l_x+=1;
    }
    while((l_compareFunc(f1.l_p,this->m__0data->at(l_y))<bbInt(0))){
      l_y-=1;
    }
    if((l_x>l_y)){
      break;
    }
    if((l_x<l_y)){
      this->m_Swap(l_x,l_y);
      if((l_i==l_x)){
        l_i=l_y;
      }else if((l_i==l_y)){
        l_i=l_x;
      }
    }
    l_x+=1;
    l_y-=1;
  }while(!((l_x>l_y)));
  this->m_Sort(l_compareFunc,l_lo,l_y);
  this->m_Sort(l_compareFunc,l_x,l_hi);
}

void t_std_collections_Stack_1Tt_mx2_AliasType_2::m_Sort(bbFunction<bbInt(t_mx2_AliasType*,t_mx2_AliasType*)> l_compareFunc){
  this->m_Sort(l_compareFunc,bbInt(0),(this->m__0length-1));
}

void t_std_collections_Stack_1Tt_mx2_AliasType_2::m_Sort(bbBool l_ascending){
  if(l_ascending){
    struct lambda24 : public bbFunction<bbInt(t_mx2_AliasType*,t_mx2_AliasType*)>::Rep{
      t_std_collections_Stack_1Tt_mx2_AliasType_2* l_self;
      lambda24(t_std_collections_Stack_1Tt_mx2_AliasType_2* l_self):l_self(l_self){
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
      t_std_collections_Stack_1Tt_mx2_AliasType_2* l_self;
      lambda25(t_std_collections_Stack_1Tt_mx2_AliasType_2* l_self):l_self(l_self){
      }
      bbInt invoke(t_mx2_AliasType* l_x,t_mx2_AliasType* l_y){
        return l_y->m__cmp(((t_mx2_Type*)(l_x)));
      }
      void gcMark(){
        bbGCMarkPtr(l_self);
      }
    };
    this->m_Sort(bbFunction<bbInt(t_mx2_AliasType*,t_mx2_AliasType*)>(new lambda25(this)));
  }
}

t_std_collections_Stack_1Tt_mx2_AliasType_2* t_std_collections_Stack_1Tt_mx2_AliasType_2::m_Slice(bbInt l_index1,bbInt l_index2){
  struct f0_t : public bbGCFrame{
    bbArray<bbGCVar<t_mx2_AliasType>>* t0{};
    void gcMark(){
      bbGCMarkPtr(t0);
    }
  }f0{};
  if((l_index1<bbInt(0))){
    l_index1=g_monkey_math_Max_1i((l_index1+this->m__0length),bbInt(0));
  }else if((l_index1>this->m__0length)){
    l_index1=this->m__0length;
  }
  if((l_index2<bbInt(0))){
    l_index2=g_monkey_math_Max_1i((l_index2+this->m__0length),l_index1);
  }else if((l_index2>this->m__0length)){
    l_index2=this->m__0length;
  }else if((l_index2<l_index1)){
    l_index2=l_index1;
  }
  return bbGCNew<t_std_collections_Stack_1Tt_mx2_AliasType_2>(f0.t0=this->m__0data->slice(l_index1,l_index2));
}

t_std_collections_Stack_1Tt_mx2_AliasType_2* t_std_collections_Stack_1Tt_mx2_AliasType_2::m_Slice(bbInt l_index){
  return this->m_Slice(l_index,this->m__0length);
}

void t_std_collections_Stack_1Tt_mx2_AliasType_2::m_Set(bbInt l_index,t_mx2_AliasType* l_value){
  bbDebugAssert(((l_index>=bbInt(0))&&(l_index<this->m__0length)),BB_T("Stack index out of range"));
  this->m__0data->at(l_index)=l_value;
}

void t_std_collections_Stack_1Tt_mx2_AliasType_2::m_Resize(bbInt l_length){
  bbDebugAssert((l_length>=bbInt(0)),BB_T("Debug assert failed"));
  {
    bbInt l_i=l_length;
    for(;(l_i<this->m__0length);l_i+=1){
      this->m__0data->at(l_i)=((t_mx2_AliasType*)0);
    }
  }
  this->m_Reserve(l_length);
  this->m__0length=l_length;
  this->m__0seq+=1;
}

void t_std_collections_Stack_1Tt_mx2_AliasType_2::m_Reserve(bbInt l_capacity){
  struct f0_t : public bbGCFrame{
    bbArray<bbGCVar<t_mx2_AliasType>>* l_data{};
    void gcMark(){
      bbGCMarkPtr(l_data);
    }
  }f0{};
  bbDebugAssert((l_capacity>=bbInt(0)),BB_T("Debug assert failed"));
  if((this->m__0data->length()>=l_capacity)){
    return;
  }
  l_capacity=g_monkey_math_Max_1i(((this->m__0length*2)+this->m__0length),l_capacity);
  f0.l_data=bbArray<bbGCVar<t_mx2_AliasType>>::create(l_capacity);
  this->m__0data->copyTo(f0.l_data,bbInt(0),bbInt(0),this->m__0length);
  this->m__0data=f0.l_data;
}

bbBool t_std_collections_Stack_1Tt_mx2_AliasType_2::m_RemoveLast(t_mx2_AliasType* l_value,bbInt l_start){
  bbInt l_i=this->m_FindLastIndex(l_value,l_start);
  if((l_i==-1)){
    return false;
  }
  this->m_Erase(l_i);
  return true;
}

bbInt t_std_collections_Stack_1Tt_mx2_AliasType_2::m_RemoveEach(t_mx2_AliasType* l_value){
  bbInt l_put=bbInt(0);
  bbInt l_n=bbInt(0);
  {
    bbInt l_get=bbInt(0);
    for(;(l_get<this->m__0length);l_get+=1){
      if(this->m__0data->at(l_get)->m__eq(((t_mx2_Type*)(l_value)))){
        l_n+=1;
        continue;
      }
      this->m__0data->at(l_put)=this->m__0data->at(l_get);
      l_put+=1;
    }
  }
  this->m_Resize(l_put);
  return l_n;
}

bbBool t_std_collections_Stack_1Tt_mx2_AliasType_2::m_Remove(t_mx2_AliasType* l_value,bbInt l_start){
  bbInt l_i=this->m_FindIndex(l_value,l_start);
  if((l_i==-1)){
    return false;
  }
  this->m_Erase(l_i);
  return true;
}

void t_std_collections_Stack_1Tt_mx2_AliasType_2::m_Push(t_mx2_AliasType* l_value){
  this->m_Add(l_value);
}

t_mx2_AliasType* t_std_collections_Stack_1Tt_mx2_AliasType_2::m_Pop(){
  struct f0_t : public bbGCFrame{
    t_mx2_AliasType* l_value{};
    void gcMark(){
      bbGCMarkPtr(l_value);
    }
  }f0{};
  bbDebugAssert(bbBool(this->m__0length),BB_T("Stack is empty"));
  this->m__0length-=1;
  this->m__0seq+=1;
  f0.l_value=this->m__0data->at(this->m__0length);
  this->m__0data->at(this->m__0length)=((t_mx2_AliasType*)0);
  return f0.l_value;
}

bbInt t_std_collections_Stack_1Tt_mx2_AliasType_2::m_Length(){
  return this->m__0length;
}

void t_std_collections_Stack_1Tt_mx2_AliasType_2::m_Insert(bbInt l_index,t_mx2_AliasType* l_value){
  bbDebugAssert(((l_index>=bbInt(0))&&(l_index<=this->m__0length)),BB_T("Debug assert failed"));
  this->m_Reserve((this->m__0length+1));
  this->m__0data->copyTo(this->m__0data,l_index,(l_index+1),(this->m__0length-l_index));
  this->m__0data->at(l_index)=l_value;
  this->m__0length+=1;
  this->m__0seq+=1;
}

t_mx2_AliasType* t_std_collections_Stack_1Tt_mx2_AliasType_2::m_Get(bbInt l_index){
  bbDebugAssert(((l_index>=bbInt(0))&&(l_index<this->m__0length)),BB_T("Stack index out of range"));
  return this->m__0data->at(l_index);
}

bbInt t_std_collections_Stack_1Tt_mx2_AliasType_2::m_FindLastIndex(t_mx2_AliasType* l_value,bbInt l_start){
  bbDebugAssert(((l_start>=bbInt(0))&&(l_start<=this->m__0length)),BB_T("Debug assert failed"));
  bbInt l_i=this->m__0length;
  while((l_i>l_start)){
    l_i-=1;
    if(this->m__0data->at(l_i)->m__eq(((t_mx2_Type*)(l_value)))){
      return l_i;
    }
  }
  return -1;
}

bbInt t_std_collections_Stack_1Tt_mx2_AliasType_2::m_FindIndex(t_mx2_AliasType* l_value,bbInt l_start){
  bbDebugAssert(((l_start>=bbInt(0))&&(l_start<=this->m__0length)),BB_T("Debug assert failed"));
  bbInt l_i=l_start;
  while((l_i<this->m__0length)){
    if(this->m__0data->at(l_i)->m__eq(((t_mx2_Type*)(l_value)))){
      return l_i;
    }
    l_i+=1;
  }
  return -1;
}

void t_std_collections_Stack_1Tt_mx2_AliasType_2::m_Erase(bbInt l_index1,bbInt l_index2){
  bbDebugAssert((((((l_index1>=bbInt(0))&&(l_index1<=this->m__0length))&&(l_index2>=bbInt(0)))&&(l_index2<=this->m__0length))&&(l_index1<=l_index2)),BB_T("Debug assert failed"));
  if((l_index1==this->m__0length)){
    return;
  }
  this->m__0data->copyTo(this->m__0data,l_index2,l_index1,(this->m__0length-l_index2));
  this->m_Resize(((this->m__0length-l_index2)+l_index1));
}

void t_std_collections_Stack_1Tt_mx2_AliasType_2::m_Erase(bbInt l_index){
  bbDebugAssert(((l_index>=bbInt(0))&&(l_index<=this->m__0length)),BB_T("Debug assert failed"));
  if((l_index==this->m__0length)){
    return;
  }
  this->m__0data->copyTo(this->m__0data,(l_index+1),l_index,((this->m__0length-l_index)-1));
  this->m_Resize((this->m__0length-1));
}

bbBool t_std_collections_Stack_1Tt_mx2_AliasType_2::m_Empty(){
  return (this->m__0length==bbInt(0));
}

bbArray<bbGCVar<t_mx2_AliasType>>* t_std_collections_Stack_1Tt_mx2_AliasType_2::m_Data(){
  return this->m__0data;
}

bbBool t_std_collections_Stack_1Tt_mx2_AliasType_2::m_Contains(t_mx2_AliasType* l_value){
  return (this->m_FindIndex(l_value,bbInt(0))!=-1);
}

void t_std_collections_Stack_1Tt_mx2_AliasType_2::m_Clear(){
  this->m_Resize(bbInt(0));
}

bbInt t_std_collections_Stack_1Tt_mx2_AliasType_2::m_Capacity(){
  return this->m__0data->length();
}

t_std_collections_Stack_1Tt_mx2_AliasType_2_BackwardsIterator t_std_collections_Stack_1Tt_mx2_AliasType_2::m_Backwards(){
  return t_std_collections_Stack_1Tt_mx2_AliasType_2_BackwardsIterator(this,(this->m__0length-1));
}

t_std_collections_Stack_1Tt_mx2_AliasType_2_Iterator t_std_collections_Stack_1Tt_mx2_AliasType_2::m_All(){
  return t_std_collections_Stack_1Tt_mx2_AliasType_2_Iterator(this,bbInt(0));
}

void t_std_collections_Stack_1Tt_mx2_AliasType_2::m_AddAll(bbArray<bbGCVar<t_mx2_AliasType>>* l_values){
  this->m_Reserve((this->m__0length+l_values->length()));
  l_values->copyTo(this->m__0data,bbInt(0),this->m__0length,l_values->length());
  this->m_Resize((this->m__0length+l_values->length()));
}

void t_std_collections_Stack_1Tt_mx2_AliasType_2::m_Add(t_mx2_AliasType* l_value){
  this->m_Reserve((this->m__0length+1));
  this->m__0data->at(this->m__0length)=l_value;
  this->m__0length+=1;
  this->m__0seq+=1;
}

t_std_collections_Stack_1Tt_mx2_FuncListType_2_Iterator::t_std_collections_Stack_1Tt_mx2_FuncListType_2_Iterator(t_std_collections_Stack_1Tt_mx2_FuncListType_2* l_stack,bbInt l_index){
  (*this).m__0stack=l_stack;
  (*this).m__0index=l_index;
  (*this).m__0seq=l_stack->m__0seq;
}

void t_std_collections_Stack_1Tt_mx2_FuncListType_2_Iterator::m_Insert(t_mx2_FuncListType* l_value){
  (*this).m_AssertSeq();
  (*this).m__0stack->m_Insert((*this).m__0index,l_value);
  (*this).m__0seq=(*this).m__0stack->m__0seq;
}

void t_std_collections_Stack_1Tt_mx2_FuncListType_2_Iterator::m_Erase(){
  (*this).m_AssertSeq();
  (*this).m__0stack->m_Erase((*this).m__0index);
  (*this).m__0seq=(*this).m__0stack->m__0seq;
}

void t_std_collections_Stack_1Tt_mx2_FuncListType_2_Iterator::m_Current(t_mx2_FuncListType* l_current){
  (*this).m_AssertCurrent();
  (*this).m__0stack->m__0data->at((*this).m__0index)=l_current;
}

t_mx2_FuncListType* t_std_collections_Stack_1Tt_mx2_FuncListType_2_Iterator::m_Current(){
  (*this).m_AssertCurrent();
  return (*this).m__0stack->m__0data->at((*this).m__0index);
}

void t_std_collections_Stack_1Tt_mx2_FuncListType_2_Iterator::m_Bump(){
  (*this).m_AssertCurrent();
  (*this).m__0index+=1;
}

bbBool t_std_collections_Stack_1Tt_mx2_FuncListType_2_Iterator::m_AtEnd(){
  (*this).m_AssertSeq();
  return ((*this).m__0index==(*this).m__0stack->m__0length);
}

void t_std_collections_Stack_1Tt_mx2_FuncListType_2_Iterator::m_AssertSeq(){
  bbDebugAssert(((*this).m__0seq==(*this).m__0stack->m__0seq),BB_T("Concurrent list modification"));
}

void t_std_collections_Stack_1Tt_mx2_FuncListType_2_Iterator::m_AssertCurrent(){
  bbDebugAssert(!(*this).m_AtEnd(),BB_T("Invalid list iterator"));
}

int bbCompare(const t_std_collections_Stack_1Tt_mx2_FuncListType_2_Iterator&x,const t_std_collections_Stack_1Tt_mx2_FuncListType_2_Iterator&y){
  if(int t=bbCompare(x.m__0stack,y.m__0stack)) return t;
  if(int t=bbCompare(x.m__0index,y.m__0index)) return t;
  if(int t=bbCompare(x.m__0seq,y.m__0seq)) return t;
  return 0;
}

void bbGCMark(const t_std_collections_Stack_1Tt_mx2_FuncListType_2_Iterator&t){
  bbGCMark(t.m__0stack);
}

t_std_collections_Stack_1Tt_mx2_FuncListType_2_BackwardsIterator::t_std_collections_Stack_1Tt_mx2_FuncListType_2_BackwardsIterator(t_std_collections_Stack_1Tt_mx2_FuncListType_2* l_stack,bbInt l_index){
  (*this).m__0stack=l_stack;
  (*this).m__0index=l_index;
  (*this).m__0seq=l_stack->m__0seq;
}

void t_std_collections_Stack_1Tt_mx2_FuncListType_2_BackwardsIterator::m_Insert(t_mx2_FuncListType* l_value){
  (*this).m_AssertSeq();
  (*this).m__0index+=1;
  (*this).m__0stack->m_Insert((*this).m__0index,l_value);
  (*this).m__0seq=(*this).m__0stack->m__0seq;
}

void t_std_collections_Stack_1Tt_mx2_FuncListType_2_BackwardsIterator::m_Erase(){
  (*this).m_AssertCurrent();
  (*this).m__0index-=1;
  (*this).m__0stack->m_Erase(((*this).m__0index+1));
  (*this).m__0seq=(*this).m__0stack->m__0seq;
}

void t_std_collections_Stack_1Tt_mx2_FuncListType_2_BackwardsIterator::m_Current(t_mx2_FuncListType* l_current){
  (*this).m_AssertCurrent();
  (*this).m__0stack->m__0data->at((*this).m__0index)=l_current;
}

t_mx2_FuncListType* t_std_collections_Stack_1Tt_mx2_FuncListType_2_BackwardsIterator::m_Current(){
  (*this).m_AssertCurrent();
  return (*this).m__0stack->m__0data->at((*this).m__0index);
}

void t_std_collections_Stack_1Tt_mx2_FuncListType_2_BackwardsIterator::m_Bump(){
  (*this).m_AssertCurrent();
  (*this).m__0index-=1;
}

bbBool t_std_collections_Stack_1Tt_mx2_FuncListType_2_BackwardsIterator::m_AtEnd(){
  (*this).m_AssertSeq();
  return ((*this).m__0index==-1);
}

void t_std_collections_Stack_1Tt_mx2_FuncListType_2_BackwardsIterator::m_AssertSeq(){
  bbDebugAssert(((*this).m__0seq==(*this).m__0stack->m__0seq),BB_T("Concurrent list modification"));
}

void t_std_collections_Stack_1Tt_mx2_FuncListType_2_BackwardsIterator::m_AssertCurrent(){
  bbDebugAssert(!(*this).m_AtEnd(),BB_T("Invalid list iterator"));
}

int bbCompare(const t_std_collections_Stack_1Tt_mx2_FuncListType_2_BackwardsIterator&x,const t_std_collections_Stack_1Tt_mx2_FuncListType_2_BackwardsIterator&y){
  if(int t=bbCompare(x.m__0stack,y.m__0stack)) return t;
  if(int t=bbCompare(x.m__0index,y.m__0index)) return t;
  if(int t=bbCompare(x.m__0seq,y.m__0seq)) return t;
  return 0;
}

void bbGCMark(const t_std_collections_Stack_1Tt_mx2_FuncListType_2_BackwardsIterator&t){
  bbGCMark(t.m__0stack);
}

void t_std_collections_Stack_1Tt_mx2_FuncListType_2::gcMark(){
  bbGCMark(m__0data);
}

t_std_collections_Stack_1Tt_mx2_FuncListType_2::t_std_collections_Stack_1Tt_mx2_FuncListType_2(t_std_collections_List_1Tt_mx2_FuncListType_2* l_values){
  g_std_collections_Stack_1Tt_mx2_FuncListType_2_AddAll_1Tt_std_collections_List_1Tt_mx2_FuncListType_2_2(this,l_values);
}

t_std_collections_Stack_1Tt_mx2_FuncListType_2::t_std_collections_Stack_1Tt_mx2_FuncListType_2(t_std_collections_Stack_1Tt_mx2_FuncListType_2* l_values){
  struct f0_t : public bbGCFrame{
    bbArray<bbGCVar<t_mx2_FuncListType>>* t0{};
    void gcMark(){
      bbGCMarkPtr(t0);
    }
  }f0{};
  this->m__0length=l_values->m_Length();
  this->m__0data=bbArray<bbGCVar<t_mx2_FuncListType>>::create(this->m__0length);
  (f0.t0=l_values->m_Data())->copyTo(this->m__0data,bbInt(0),bbInt(0),this->m__0length);
}

t_std_collections_Stack_1Tt_mx2_FuncListType_2::t_std_collections_Stack_1Tt_mx2_FuncListType_2(bbArray<bbGCVar<t_mx2_FuncListType>>* l_values){
  this->m_AddAll(l_values);
}

t_std_collections_Stack_1Tt_mx2_FuncListType_2::t_std_collections_Stack_1Tt_mx2_FuncListType_2(bbInt l_length){
  this->m__0length=l_length;
  this->m__0data=bbArray<bbGCVar<t_mx2_FuncListType>>::create(this->m__0length);
}

t_std_collections_Stack_1Tt_mx2_FuncListType_2::t_std_collections_Stack_1Tt_mx2_FuncListType_2(){
  this->m__0data=bbArray<bbGCVar<t_mx2_FuncListType>>::create(10);
}

void t_std_collections_Stack_1Tt_mx2_FuncListType_2::m__idxeq(bbInt l_index,t_mx2_FuncListType* l_value){
  bbDebugAssert(((l_index>=bbInt(0))&&(l_index<this->m__0length)),BB_T("Stack index out of range"));
  this->m__0data->at(l_index)=l_value;
}

t_mx2_FuncListType* t_std_collections_Stack_1Tt_mx2_FuncListType_2::m__idx(bbInt l_index){
  bbDebugAssert(((l_index>=bbInt(0))&&(l_index<this->m__0length)),BB_T("Stack index out of range"));
  return this->m__0data->at(l_index);
}

t_mx2_FuncListType* t_std_collections_Stack_1Tt_mx2_FuncListType_2::m_Top(){
  bbDebugAssert(bbBool(this->m__0length),BB_T("Stack is empty"));
  return this->m__0data->at((this->m__0length-1));
}

bbArray<bbGCVar<t_mx2_FuncListType>>* t_std_collections_Stack_1Tt_mx2_FuncListType_2::m_ToArray(){
  return this->m__0data->slice(bbInt(0),this->m__0length);
}

void t_std_collections_Stack_1Tt_mx2_FuncListType_2::m_Swap(bbInt l_index1,bbInt l_index2){
  struct f0_t : public bbGCFrame{
    t_mx2_FuncListType* l_t{};
    void gcMark(){
      bbGCMarkPtr(l_t);
    }
  }f0{};
  bbDebugAssert(((((l_index1>=bbInt(0))&&(l_index1<this->m__0length))&&(l_index2>=bbInt(0)))&&(l_index2<this->m__0length)),BB_T("Stack index out of range"));
  f0.l_t=this->m__0data->at(l_index1);
  this->m__0data->at(l_index1)=this->m__0data->at(l_index2);
  this->m__0data->at(l_index2)=f0.l_t;
}

void t_std_collections_Stack_1Tt_mx2_FuncListType_2::m_Sort(bbFunction<bbInt(t_mx2_FuncListType*,t_mx2_FuncListType*)> l_compareFunc,bbInt l_lo,bbInt l_hi){
  if((l_hi<=l_lo)){
    return;
  }
  if(((l_lo+1)==l_hi)){
    if((l_compareFunc(this->m__0data->at(l_hi),this->m__0data->at(l_lo))<bbInt(0))){
      this->m_Swap(l_hi,l_lo);
    }
    return;
  }
  bbInt l_i=((l_lo+l_hi)/2);
  if((l_compareFunc(this->m__0data->at(l_i),this->m__0data->at(l_lo))<bbInt(0))){
    this->m_Swap(l_i,l_lo);
  }
  if((l_compareFunc(this->m__0data->at(l_hi),this->m__0data->at(l_i))<bbInt(0))){
    this->m_Swap(l_hi,l_i);
    if((l_compareFunc(this->m__0data->at(l_i),this->m__0data->at(l_lo))<bbInt(0))){
      this->m_Swap(l_i,l_lo);
    }
  }
  bbInt l_x=(l_lo+1);
  bbInt l_y=(l_hi-1);
  do{
    struct f1_t : public bbGCFrame{
      t_mx2_FuncListType* l_p{};
      void gcMark(){
        bbGCMarkPtr(l_p);
      }
    }f1{};
    f1.l_p=this->m__0data->at(l_i);
    while((l_compareFunc(this->m__0data->at(l_x),f1.l_p)<bbInt(0))){
      l_x+=1;
    }
    while((l_compareFunc(f1.l_p,this->m__0data->at(l_y))<bbInt(0))){
      l_y-=1;
    }
    if((l_x>l_y)){
      break;
    }
    if((l_x<l_y)){
      this->m_Swap(l_x,l_y);
      if((l_i==l_x)){
        l_i=l_y;
      }else if((l_i==l_y)){
        l_i=l_x;
      }
    }
    l_x+=1;
    l_y-=1;
  }while(!((l_x>l_y)));
  this->m_Sort(l_compareFunc,l_lo,l_y);
  this->m_Sort(l_compareFunc,l_x,l_hi);
}

void t_std_collections_Stack_1Tt_mx2_FuncListType_2::m_Sort(bbFunction<bbInt(t_mx2_FuncListType*,t_mx2_FuncListType*)> l_compareFunc){
  this->m_Sort(l_compareFunc,bbInt(0),(this->m__0length-1));
}

void t_std_collections_Stack_1Tt_mx2_FuncListType_2::m_Sort(bbBool l_ascending){
  if(l_ascending){
    struct lambda26 : public bbFunction<bbInt(t_mx2_FuncListType*,t_mx2_FuncListType*)>::Rep{
      t_std_collections_Stack_1Tt_mx2_FuncListType_2* l_self;
      lambda26(t_std_collections_Stack_1Tt_mx2_FuncListType_2* l_self):l_self(l_self){
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
      t_std_collections_Stack_1Tt_mx2_FuncListType_2* l_self;
      lambda27(t_std_collections_Stack_1Tt_mx2_FuncListType_2* l_self):l_self(l_self){
      }
      bbInt invoke(t_mx2_FuncListType* l_x,t_mx2_FuncListType* l_y){
        return l_y->m__cmp(((t_mx2_Type*)(l_x)));
      }
      void gcMark(){
        bbGCMarkPtr(l_self);
      }
    };
    this->m_Sort(bbFunction<bbInt(t_mx2_FuncListType*,t_mx2_FuncListType*)>(new lambda27(this)));
  }
}

t_std_collections_Stack_1Tt_mx2_FuncListType_2* t_std_collections_Stack_1Tt_mx2_FuncListType_2::m_Slice(bbInt l_index1,bbInt l_index2){
  struct f0_t : public bbGCFrame{
    bbArray<bbGCVar<t_mx2_FuncListType>>* t0{};
    void gcMark(){
      bbGCMarkPtr(t0);
    }
  }f0{};
  if((l_index1<bbInt(0))){
    l_index1=g_monkey_math_Max_1i((l_index1+this->m__0length),bbInt(0));
  }else if((l_index1>this->m__0length)){
    l_index1=this->m__0length;
  }
  if((l_index2<bbInt(0))){
    l_index2=g_monkey_math_Max_1i((l_index2+this->m__0length),l_index1);
  }else if((l_index2>this->m__0length)){
    l_index2=this->m__0length;
  }else if((l_index2<l_index1)){
    l_index2=l_index1;
  }
  return bbGCNew<t_std_collections_Stack_1Tt_mx2_FuncListType_2>(f0.t0=this->m__0data->slice(l_index1,l_index2));
}

t_std_collections_Stack_1Tt_mx2_FuncListType_2* t_std_collections_Stack_1Tt_mx2_FuncListType_2::m_Slice(bbInt l_index){
  return this->m_Slice(l_index,this->m__0length);
}

void t_std_collections_Stack_1Tt_mx2_FuncListType_2::m_Set(bbInt l_index,t_mx2_FuncListType* l_value){
  bbDebugAssert(((l_index>=bbInt(0))&&(l_index<this->m__0length)),BB_T("Stack index out of range"));
  this->m__0data->at(l_index)=l_value;
}

void t_std_collections_Stack_1Tt_mx2_FuncListType_2::m_Resize(bbInt l_length){
  bbDebugAssert((l_length>=bbInt(0)),BB_T("Debug assert failed"));
  {
    bbInt l_i=l_length;
    for(;(l_i<this->m__0length);l_i+=1){
      this->m__0data->at(l_i)=((t_mx2_FuncListType*)0);
    }
  }
  this->m_Reserve(l_length);
  this->m__0length=l_length;
  this->m__0seq+=1;
}

void t_std_collections_Stack_1Tt_mx2_FuncListType_2::m_Reserve(bbInt l_capacity){
  struct f0_t : public bbGCFrame{
    bbArray<bbGCVar<t_mx2_FuncListType>>* l_data{};
    void gcMark(){
      bbGCMarkPtr(l_data);
    }
  }f0{};
  bbDebugAssert((l_capacity>=bbInt(0)),BB_T("Debug assert failed"));
  if((this->m__0data->length()>=l_capacity)){
    return;
  }
  l_capacity=g_monkey_math_Max_1i(((this->m__0length*2)+this->m__0length),l_capacity);
  f0.l_data=bbArray<bbGCVar<t_mx2_FuncListType>>::create(l_capacity);
  this->m__0data->copyTo(f0.l_data,bbInt(0),bbInt(0),this->m__0length);
  this->m__0data=f0.l_data;
}

bbBool t_std_collections_Stack_1Tt_mx2_FuncListType_2::m_RemoveLast(t_mx2_FuncListType* l_value,bbInt l_start){
  bbInt l_i=this->m_FindLastIndex(l_value,l_start);
  if((l_i==-1)){
    return false;
  }
  this->m_Erase(l_i);
  return true;
}

bbInt t_std_collections_Stack_1Tt_mx2_FuncListType_2::m_RemoveEach(t_mx2_FuncListType* l_value){
  bbInt l_put=bbInt(0);
  bbInt l_n=bbInt(0);
  {
    bbInt l_get=bbInt(0);
    for(;(l_get<this->m__0length);l_get+=1){
      if(this->m__0data->at(l_get)->m__eq(((t_mx2_Type*)(l_value)))){
        l_n+=1;
        continue;
      }
      this->m__0data->at(l_put)=this->m__0data->at(l_get);
      l_put+=1;
    }
  }
  this->m_Resize(l_put);
  return l_n;
}

bbBool t_std_collections_Stack_1Tt_mx2_FuncListType_2::m_Remove(t_mx2_FuncListType* l_value,bbInt l_start){
  bbInt l_i=this->m_FindIndex(l_value,l_start);
  if((l_i==-1)){
    return false;
  }
  this->m_Erase(l_i);
  return true;
}

void t_std_collections_Stack_1Tt_mx2_FuncListType_2::m_Push(t_mx2_FuncListType* l_value){
  this->m_Add(l_value);
}

t_mx2_FuncListType* t_std_collections_Stack_1Tt_mx2_FuncListType_2::m_Pop(){
  struct f0_t : public bbGCFrame{
    t_mx2_FuncListType* l_value{};
    void gcMark(){
      bbGCMarkPtr(l_value);
    }
  }f0{};
  bbDebugAssert(bbBool(this->m__0length),BB_T("Stack is empty"));
  this->m__0length-=1;
  this->m__0seq+=1;
  f0.l_value=this->m__0data->at(this->m__0length);
  this->m__0data->at(this->m__0length)=((t_mx2_FuncListType*)0);
  return f0.l_value;
}

bbInt t_std_collections_Stack_1Tt_mx2_FuncListType_2::m_Length(){
  return this->m__0length;
}

void t_std_collections_Stack_1Tt_mx2_FuncListType_2::m_Insert(bbInt l_index,t_mx2_FuncListType* l_value){
  bbDebugAssert(((l_index>=bbInt(0))&&(l_index<=this->m__0length)),BB_T("Debug assert failed"));
  this->m_Reserve((this->m__0length+1));
  this->m__0data->copyTo(this->m__0data,l_index,(l_index+1),(this->m__0length-l_index));
  this->m__0data->at(l_index)=l_value;
  this->m__0length+=1;
  this->m__0seq+=1;
}

t_mx2_FuncListType* t_std_collections_Stack_1Tt_mx2_FuncListType_2::m_Get(bbInt l_index){
  bbDebugAssert(((l_index>=bbInt(0))&&(l_index<this->m__0length)),BB_T("Stack index out of range"));
  return this->m__0data->at(l_index);
}

bbInt t_std_collections_Stack_1Tt_mx2_FuncListType_2::m_FindLastIndex(t_mx2_FuncListType* l_value,bbInt l_start){
  bbDebugAssert(((l_start>=bbInt(0))&&(l_start<=this->m__0length)),BB_T("Debug assert failed"));
  bbInt l_i=this->m__0length;
  while((l_i>l_start)){
    l_i-=1;
    if(this->m__0data->at(l_i)->m__eq(((t_mx2_Type*)(l_value)))){
      return l_i;
    }
  }
  return -1;
}

bbInt t_std_collections_Stack_1Tt_mx2_FuncListType_2::m_FindIndex(t_mx2_FuncListType* l_value,bbInt l_start){
  bbDebugAssert(((l_start>=bbInt(0))&&(l_start<=this->m__0length)),BB_T("Debug assert failed"));
  bbInt l_i=l_start;
  while((l_i<this->m__0length)){
    if(this->m__0data->at(l_i)->m__eq(((t_mx2_Type*)(l_value)))){
      return l_i;
    }
    l_i+=1;
  }
  return -1;
}

void t_std_collections_Stack_1Tt_mx2_FuncListType_2::m_Erase(bbInt l_index1,bbInt l_index2){
  bbDebugAssert((((((l_index1>=bbInt(0))&&(l_index1<=this->m__0length))&&(l_index2>=bbInt(0)))&&(l_index2<=this->m__0length))&&(l_index1<=l_index2)),BB_T("Debug assert failed"));
  if((l_index1==this->m__0length)){
    return;
  }
  this->m__0data->copyTo(this->m__0data,l_index2,l_index1,(this->m__0length-l_index2));
  this->m_Resize(((this->m__0length-l_index2)+l_index1));
}

void t_std_collections_Stack_1Tt_mx2_FuncListType_2::m_Erase(bbInt l_index){
  bbDebugAssert(((l_index>=bbInt(0))&&(l_index<=this->m__0length)),BB_T("Debug assert failed"));
  if((l_index==this->m__0length)){
    return;
  }
  this->m__0data->copyTo(this->m__0data,(l_index+1),l_index,((this->m__0length-l_index)-1));
  this->m_Resize((this->m__0length-1));
}

bbBool t_std_collections_Stack_1Tt_mx2_FuncListType_2::m_Empty(){
  return (this->m__0length==bbInt(0));
}

bbArray<bbGCVar<t_mx2_FuncListType>>* t_std_collections_Stack_1Tt_mx2_FuncListType_2::m_Data(){
  return this->m__0data;
}

bbBool t_std_collections_Stack_1Tt_mx2_FuncListType_2::m_Contains(t_mx2_FuncListType* l_value){
  return (this->m_FindIndex(l_value,bbInt(0))!=-1);
}

void t_std_collections_Stack_1Tt_mx2_FuncListType_2::m_Clear(){
  this->m_Resize(bbInt(0));
}

bbInt t_std_collections_Stack_1Tt_mx2_FuncListType_2::m_Capacity(){
  return this->m__0data->length();
}

t_std_collections_Stack_1Tt_mx2_FuncListType_2_BackwardsIterator t_std_collections_Stack_1Tt_mx2_FuncListType_2::m_Backwards(){
  return t_std_collections_Stack_1Tt_mx2_FuncListType_2_BackwardsIterator(this,(this->m__0length-1));
}

t_std_collections_Stack_1Tt_mx2_FuncListType_2_Iterator t_std_collections_Stack_1Tt_mx2_FuncListType_2::m_All(){
  return t_std_collections_Stack_1Tt_mx2_FuncListType_2_Iterator(this,bbInt(0));
}

void t_std_collections_Stack_1Tt_mx2_FuncListType_2::m_AddAll(bbArray<bbGCVar<t_mx2_FuncListType>>* l_values){
  this->m_Reserve((this->m__0length+l_values->length()));
  l_values->copyTo(this->m__0data,bbInt(0),this->m__0length,l_values->length());
  this->m_Resize((this->m__0length+l_values->length()));
}

void t_std_collections_Stack_1Tt_mx2_FuncListType_2::m_Add(t_mx2_FuncListType* l_value){
  this->m_Reserve((this->m__0length+1));
  this->m__0data->at(this->m__0length)=l_value;
  this->m__0length+=1;
  this->m__0seq+=1;
}

t_std_collections_Stack_1Tt_mx2_Decl_2_Iterator::t_std_collections_Stack_1Tt_mx2_Decl_2_Iterator(t_std_collections_Stack_1Tt_mx2_Decl_2* l_stack,bbInt l_index){
  (*this).m__0stack=l_stack;
  (*this).m__0index=l_index;
  (*this).m__0seq=l_stack->m__0seq;
}

void t_std_collections_Stack_1Tt_mx2_Decl_2_Iterator::m_Insert(t_mx2_Decl* l_value){
  (*this).m_AssertSeq();
  (*this).m__0stack->m_Insert((*this).m__0index,l_value);
  (*this).m__0seq=(*this).m__0stack->m__0seq;
}

void t_std_collections_Stack_1Tt_mx2_Decl_2_Iterator::m_Erase(){
  (*this).m_AssertSeq();
  (*this).m__0stack->m_Erase((*this).m__0index);
  (*this).m__0seq=(*this).m__0stack->m__0seq;
}

void t_std_collections_Stack_1Tt_mx2_Decl_2_Iterator::m_Current(t_mx2_Decl* l_current){
  (*this).m_AssertCurrent();
  (*this).m__0stack->m__0data->at((*this).m__0index)=l_current;
}

t_mx2_Decl* t_std_collections_Stack_1Tt_mx2_Decl_2_Iterator::m_Current(){
  (*this).m_AssertCurrent();
  return (*this).m__0stack->m__0data->at((*this).m__0index);
}

void t_std_collections_Stack_1Tt_mx2_Decl_2_Iterator::m_Bump(){
  (*this).m_AssertCurrent();
  (*this).m__0index+=1;
}

bbBool t_std_collections_Stack_1Tt_mx2_Decl_2_Iterator::m_AtEnd(){
  (*this).m_AssertSeq();
  return ((*this).m__0index==(*this).m__0stack->m__0length);
}

void t_std_collections_Stack_1Tt_mx2_Decl_2_Iterator::m_AssertSeq(){
  bbDebugAssert(((*this).m__0seq==(*this).m__0stack->m__0seq),BB_T("Concurrent list modification"));
}

void t_std_collections_Stack_1Tt_mx2_Decl_2_Iterator::m_AssertCurrent(){
  bbDebugAssert(!(*this).m_AtEnd(),BB_T("Invalid list iterator"));
}

int bbCompare(const t_std_collections_Stack_1Tt_mx2_Decl_2_Iterator&x,const t_std_collections_Stack_1Tt_mx2_Decl_2_Iterator&y){
  if(int t=bbCompare(x.m__0stack,y.m__0stack)) return t;
  if(int t=bbCompare(x.m__0index,y.m__0index)) return t;
  if(int t=bbCompare(x.m__0seq,y.m__0seq)) return t;
  return 0;
}

void bbGCMark(const t_std_collections_Stack_1Tt_mx2_Decl_2_Iterator&t){
  bbGCMark(t.m__0stack);
}

t_std_collections_Stack_1Tt_mx2_Decl_2_BackwardsIterator::t_std_collections_Stack_1Tt_mx2_Decl_2_BackwardsIterator(t_std_collections_Stack_1Tt_mx2_Decl_2* l_stack,bbInt l_index){
  (*this).m__0stack=l_stack;
  (*this).m__0index=l_index;
  (*this).m__0seq=l_stack->m__0seq;
}

void t_std_collections_Stack_1Tt_mx2_Decl_2_BackwardsIterator::m_Insert(t_mx2_Decl* l_value){
  (*this).m_AssertSeq();
  (*this).m__0index+=1;
  (*this).m__0stack->m_Insert((*this).m__0index,l_value);
  (*this).m__0seq=(*this).m__0stack->m__0seq;
}

void t_std_collections_Stack_1Tt_mx2_Decl_2_BackwardsIterator::m_Erase(){
  (*this).m_AssertCurrent();
  (*this).m__0index-=1;
  (*this).m__0stack->m_Erase(((*this).m__0index+1));
  (*this).m__0seq=(*this).m__0stack->m__0seq;
}

void t_std_collections_Stack_1Tt_mx2_Decl_2_BackwardsIterator::m_Current(t_mx2_Decl* l_current){
  (*this).m_AssertCurrent();
  (*this).m__0stack->m__0data->at((*this).m__0index)=l_current;
}

t_mx2_Decl* t_std_collections_Stack_1Tt_mx2_Decl_2_BackwardsIterator::m_Current(){
  (*this).m_AssertCurrent();
  return (*this).m__0stack->m__0data->at((*this).m__0index);
}

void t_std_collections_Stack_1Tt_mx2_Decl_2_BackwardsIterator::m_Bump(){
  (*this).m_AssertCurrent();
  (*this).m__0index-=1;
}

bbBool t_std_collections_Stack_1Tt_mx2_Decl_2_BackwardsIterator::m_AtEnd(){
  (*this).m_AssertSeq();
  return ((*this).m__0index==-1);
}

void t_std_collections_Stack_1Tt_mx2_Decl_2_BackwardsIterator::m_AssertSeq(){
  bbDebugAssert(((*this).m__0seq==(*this).m__0stack->m__0seq),BB_T("Concurrent list modification"));
}

void t_std_collections_Stack_1Tt_mx2_Decl_2_BackwardsIterator::m_AssertCurrent(){
  bbDebugAssert(!(*this).m_AtEnd(),BB_T("Invalid list iterator"));
}

int bbCompare(const t_std_collections_Stack_1Tt_mx2_Decl_2_BackwardsIterator&x,const t_std_collections_Stack_1Tt_mx2_Decl_2_BackwardsIterator&y){
  if(int t=bbCompare(x.m__0stack,y.m__0stack)) return t;
  if(int t=bbCompare(x.m__0index,y.m__0index)) return t;
  if(int t=bbCompare(x.m__0seq,y.m__0seq)) return t;
  return 0;
}

void bbGCMark(const t_std_collections_Stack_1Tt_mx2_Decl_2_BackwardsIterator&t){
  bbGCMark(t.m__0stack);
}

void t_std_collections_Stack_1Tt_mx2_Decl_2::gcMark(){
  bbGCMark(m__0data);
}

t_std_collections_Stack_1Tt_mx2_Decl_2::t_std_collections_Stack_1Tt_mx2_Decl_2(t_std_collections_List_1Tt_mx2_Decl_2* l_values){
  g_std_collections_Stack_1Tt_mx2_Decl_2_AddAll_1Tt_std_collections_List_1Tt_mx2_Decl_2_2(this,l_values);
}

t_std_collections_Stack_1Tt_mx2_Decl_2::t_std_collections_Stack_1Tt_mx2_Decl_2(t_std_collections_Stack_1Tt_mx2_Decl_2* l_values){
  struct f0_t : public bbGCFrame{
    bbArray<bbGCVar<t_mx2_Decl>>* t0{};
    void gcMark(){
      bbGCMarkPtr(t0);
    }
  }f0{};
  this->m__0length=l_values->m_Length();
  this->m__0data=bbArray<bbGCVar<t_mx2_Decl>>::create(this->m__0length);
  (f0.t0=l_values->m_Data())->copyTo(this->m__0data,bbInt(0),bbInt(0),this->m__0length);
}

t_std_collections_Stack_1Tt_mx2_Decl_2::t_std_collections_Stack_1Tt_mx2_Decl_2(bbArray<bbGCVar<t_mx2_Decl>>* l_values){
  this->m_AddAll(l_values);
}

t_std_collections_Stack_1Tt_mx2_Decl_2::t_std_collections_Stack_1Tt_mx2_Decl_2(bbInt l_length){
  this->m__0length=l_length;
  this->m__0data=bbArray<bbGCVar<t_mx2_Decl>>::create(this->m__0length);
}

t_std_collections_Stack_1Tt_mx2_Decl_2::t_std_collections_Stack_1Tt_mx2_Decl_2(){
  this->m__0data=bbArray<bbGCVar<t_mx2_Decl>>::create(10);
}

void t_std_collections_Stack_1Tt_mx2_Decl_2::m__idxeq(bbInt l_index,t_mx2_Decl* l_value){
  bbDebugAssert(((l_index>=bbInt(0))&&(l_index<this->m__0length)),BB_T("Stack index out of range"));
  this->m__0data->at(l_index)=l_value;
}

t_mx2_Decl* t_std_collections_Stack_1Tt_mx2_Decl_2::m__idx(bbInt l_index){
  bbDebugAssert(((l_index>=bbInt(0))&&(l_index<this->m__0length)),BB_T("Stack index out of range"));
  return this->m__0data->at(l_index);
}

t_mx2_Decl* t_std_collections_Stack_1Tt_mx2_Decl_2::m_Top(){
  bbDebugAssert(bbBool(this->m__0length),BB_T("Stack is empty"));
  return this->m__0data->at((this->m__0length-1));
}

bbArray<bbGCVar<t_mx2_Decl>>* t_std_collections_Stack_1Tt_mx2_Decl_2::m_ToArray(){
  return this->m__0data->slice(bbInt(0),this->m__0length);
}

void t_std_collections_Stack_1Tt_mx2_Decl_2::m_Swap(bbInt l_index1,bbInt l_index2){
  struct f0_t : public bbGCFrame{
    t_mx2_Decl* l_t{};
    void gcMark(){
      bbGCMarkPtr(l_t);
    }
  }f0{};
  bbDebugAssert(((((l_index1>=bbInt(0))&&(l_index1<this->m__0length))&&(l_index2>=bbInt(0)))&&(l_index2<this->m__0length)),BB_T("Stack index out of range"));
  f0.l_t=this->m__0data->at(l_index1);
  this->m__0data->at(l_index1)=this->m__0data->at(l_index2);
  this->m__0data->at(l_index2)=f0.l_t;
}

void t_std_collections_Stack_1Tt_mx2_Decl_2::m_Sort(bbFunction<bbInt(t_mx2_Decl*,t_mx2_Decl*)> l_compareFunc,bbInt l_lo,bbInt l_hi){
  if((l_hi<=l_lo)){
    return;
  }
  if(((l_lo+1)==l_hi)){
    if((l_compareFunc(this->m__0data->at(l_hi),this->m__0data->at(l_lo))<bbInt(0))){
      this->m_Swap(l_hi,l_lo);
    }
    return;
  }
  bbInt l_i=((l_lo+l_hi)/2);
  if((l_compareFunc(this->m__0data->at(l_i),this->m__0data->at(l_lo))<bbInt(0))){
    this->m_Swap(l_i,l_lo);
  }
  if((l_compareFunc(this->m__0data->at(l_hi),this->m__0data->at(l_i))<bbInt(0))){
    this->m_Swap(l_hi,l_i);
    if((l_compareFunc(this->m__0data->at(l_i),this->m__0data->at(l_lo))<bbInt(0))){
      this->m_Swap(l_i,l_lo);
    }
  }
  bbInt l_x=(l_lo+1);
  bbInt l_y=(l_hi-1);
  do{
    struct f1_t : public bbGCFrame{
      t_mx2_Decl* l_p{};
      void gcMark(){
        bbGCMarkPtr(l_p);
      }
    }f1{};
    f1.l_p=this->m__0data->at(l_i);
    while((l_compareFunc(this->m__0data->at(l_x),f1.l_p)<bbInt(0))){
      l_x+=1;
    }
    while((l_compareFunc(f1.l_p,this->m__0data->at(l_y))<bbInt(0))){
      l_y-=1;
    }
    if((l_x>l_y)){
      break;
    }
    if((l_x<l_y)){
      this->m_Swap(l_x,l_y);
      if((l_i==l_x)){
        l_i=l_y;
      }else if((l_i==l_y)){
        l_i=l_x;
      }
    }
    l_x+=1;
    l_y-=1;
  }while(!((l_x>l_y)));
  this->m_Sort(l_compareFunc,l_lo,l_y);
  this->m_Sort(l_compareFunc,l_x,l_hi);
}

void t_std_collections_Stack_1Tt_mx2_Decl_2::m_Sort(bbFunction<bbInt(t_mx2_Decl*,t_mx2_Decl*)> l_compareFunc){
  this->m_Sort(l_compareFunc,bbInt(0),(this->m__0length-1));
}

void t_std_collections_Stack_1Tt_mx2_Decl_2::m_Sort(bbBool l_ascending){
  if(l_ascending){
    struct lambda28 : public bbFunction<bbInt(t_mx2_Decl*,t_mx2_Decl*)>::Rep{
      t_std_collections_Stack_1Tt_mx2_Decl_2* l_self;
      lambda28(t_std_collections_Stack_1Tt_mx2_Decl_2* l_self):l_self(l_self){
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
      t_std_collections_Stack_1Tt_mx2_Decl_2* l_self;
      lambda29(t_std_collections_Stack_1Tt_mx2_Decl_2* l_self):l_self(l_self){
      }
      bbInt invoke(t_mx2_Decl* l_x,t_mx2_Decl* l_y){
        return bbCompare(l_y,l_x);
      }
      void gcMark(){
        bbGCMarkPtr(l_self);
      }
    };
    this->m_Sort(bbFunction<bbInt(t_mx2_Decl*,t_mx2_Decl*)>(new lambda29(this)));
  }
}

t_std_collections_Stack_1Tt_mx2_Decl_2* t_std_collections_Stack_1Tt_mx2_Decl_2::m_Slice(bbInt l_index1,bbInt l_index2){
  struct f0_t : public bbGCFrame{
    bbArray<bbGCVar<t_mx2_Decl>>* t0{};
    void gcMark(){
      bbGCMarkPtr(t0);
    }
  }f0{};
  if((l_index1<bbInt(0))){
    l_index1=g_monkey_math_Max_1i((l_index1+this->m__0length),bbInt(0));
  }else if((l_index1>this->m__0length)){
    l_index1=this->m__0length;
  }
  if((l_index2<bbInt(0))){
    l_index2=g_monkey_math_Max_1i((l_index2+this->m__0length),l_index1);
  }else if((l_index2>this->m__0length)){
    l_index2=this->m__0length;
  }else if((l_index2<l_index1)){
    l_index2=l_index1;
  }
  return bbGCNew<t_std_collections_Stack_1Tt_mx2_Decl_2>(f0.t0=this->m__0data->slice(l_index1,l_index2));
}

t_std_collections_Stack_1Tt_mx2_Decl_2* t_std_collections_Stack_1Tt_mx2_Decl_2::m_Slice(bbInt l_index){
  return this->m_Slice(l_index,this->m__0length);
}

void t_std_collections_Stack_1Tt_mx2_Decl_2::m_Set(bbInt l_index,t_mx2_Decl* l_value){
  bbDebugAssert(((l_index>=bbInt(0))&&(l_index<this->m__0length)),BB_T("Stack index out of range"));
  this->m__0data->at(l_index)=l_value;
}

void t_std_collections_Stack_1Tt_mx2_Decl_2::m_Resize(bbInt l_length){
  bbDebugAssert((l_length>=bbInt(0)),BB_T("Debug assert failed"));
  {
    bbInt l_i=l_length;
    for(;(l_i<this->m__0length);l_i+=1){
      this->m__0data->at(l_i)=((t_mx2_Decl*)0);
    }
  }
  this->m_Reserve(l_length);
  this->m__0length=l_length;
  this->m__0seq+=1;
}

void t_std_collections_Stack_1Tt_mx2_Decl_2::m_Reserve(bbInt l_capacity){
  struct f0_t : public bbGCFrame{
    bbArray<bbGCVar<t_mx2_Decl>>* l_data{};
    void gcMark(){
      bbGCMarkPtr(l_data);
    }
  }f0{};
  bbDebugAssert((l_capacity>=bbInt(0)),BB_T("Debug assert failed"));
  if((this->m__0data->length()>=l_capacity)){
    return;
  }
  l_capacity=g_monkey_math_Max_1i(((this->m__0length*2)+this->m__0length),l_capacity);
  f0.l_data=bbArray<bbGCVar<t_mx2_Decl>>::create(l_capacity);
  this->m__0data->copyTo(f0.l_data,bbInt(0),bbInt(0),this->m__0length);
  this->m__0data=f0.l_data;
}

bbBool t_std_collections_Stack_1Tt_mx2_Decl_2::m_RemoveLast(t_mx2_Decl* l_value,bbInt l_start){
  bbInt l_i=this->m_FindLastIndex(l_value,l_start);
  if((l_i==-1)){
    return false;
  }
  this->m_Erase(l_i);
  return true;
}

bbInt t_std_collections_Stack_1Tt_mx2_Decl_2::m_RemoveEach(t_mx2_Decl* l_value){
  bbInt l_put=bbInt(0);
  bbInt l_n=bbInt(0);
  {
    bbInt l_get=bbInt(0);
    for(;(l_get<this->m__0length);l_get+=1){
      if((this->m__0data->at(l_get)==l_value)){
        l_n+=1;
        continue;
      }
      this->m__0data->at(l_put)=this->m__0data->at(l_get);
      l_put+=1;
    }
  }
  this->m_Resize(l_put);
  return l_n;
}

bbBool t_std_collections_Stack_1Tt_mx2_Decl_2::m_Remove(t_mx2_Decl* l_value,bbInt l_start){
  bbInt l_i=this->m_FindIndex(l_value,l_start);
  if((l_i==-1)){
    return false;
  }
  this->m_Erase(l_i);
  return true;
}

void t_std_collections_Stack_1Tt_mx2_Decl_2::m_Push(t_mx2_Decl* l_value){
  this->m_Add(l_value);
}

t_mx2_Decl* t_std_collections_Stack_1Tt_mx2_Decl_2::m_Pop(){
  struct f0_t : public bbGCFrame{
    t_mx2_Decl* l_value{};
    void gcMark(){
      bbGCMarkPtr(l_value);
    }
  }f0{};
  bbDebugAssert(bbBool(this->m__0length),BB_T("Stack is empty"));
  this->m__0length-=1;
  this->m__0seq+=1;
  f0.l_value=this->m__0data->at(this->m__0length);
  this->m__0data->at(this->m__0length)=((t_mx2_Decl*)0);
  return f0.l_value;
}

bbInt t_std_collections_Stack_1Tt_mx2_Decl_2::m_Length(){
  return this->m__0length;
}

void t_std_collections_Stack_1Tt_mx2_Decl_2::m_Insert(bbInt l_index,t_mx2_Decl* l_value){
  bbDebugAssert(((l_index>=bbInt(0))&&(l_index<=this->m__0length)),BB_T("Debug assert failed"));
  this->m_Reserve((this->m__0length+1));
  this->m__0data->copyTo(this->m__0data,l_index,(l_index+1),(this->m__0length-l_index));
  this->m__0data->at(l_index)=l_value;
  this->m__0length+=1;
  this->m__0seq+=1;
}

t_mx2_Decl* t_std_collections_Stack_1Tt_mx2_Decl_2::m_Get(bbInt l_index){
  bbDebugAssert(((l_index>=bbInt(0))&&(l_index<this->m__0length)),BB_T("Stack index out of range"));
  return this->m__0data->at(l_index);
}

bbInt t_std_collections_Stack_1Tt_mx2_Decl_2::m_FindLastIndex(t_mx2_Decl* l_value,bbInt l_start){
  bbDebugAssert(((l_start>=bbInt(0))&&(l_start<=this->m__0length)),BB_T("Debug assert failed"));
  bbInt l_i=this->m__0length;
  while((l_i>l_start)){
    l_i-=1;
    if((this->m__0data->at(l_i)==l_value)){
      return l_i;
    }
  }
  return -1;
}

bbInt t_std_collections_Stack_1Tt_mx2_Decl_2::m_FindIndex(t_mx2_Decl* l_value,bbInt l_start){
  bbDebugAssert(((l_start>=bbInt(0))&&(l_start<=this->m__0length)),BB_T("Debug assert failed"));
  bbInt l_i=l_start;
  while((l_i<this->m__0length)){
    if((this->m__0data->at(l_i)==l_value)){
      return l_i;
    }
    l_i+=1;
  }
  return -1;
}

void t_std_collections_Stack_1Tt_mx2_Decl_2::m_Erase(bbInt l_index1,bbInt l_index2){
  bbDebugAssert((((((l_index1>=bbInt(0))&&(l_index1<=this->m__0length))&&(l_index2>=bbInt(0)))&&(l_index2<=this->m__0length))&&(l_index1<=l_index2)),BB_T("Debug assert failed"));
  if((l_index1==this->m__0length)){
    return;
  }
  this->m__0data->copyTo(this->m__0data,l_index2,l_index1,(this->m__0length-l_index2));
  this->m_Resize(((this->m__0length-l_index2)+l_index1));
}

void t_std_collections_Stack_1Tt_mx2_Decl_2::m_Erase(bbInt l_index){
  bbDebugAssert(((l_index>=bbInt(0))&&(l_index<=this->m__0length)),BB_T("Debug assert failed"));
  if((l_index==this->m__0length)){
    return;
  }
  this->m__0data->copyTo(this->m__0data,(l_index+1),l_index,((this->m__0length-l_index)-1));
  this->m_Resize((this->m__0length-1));
}

bbBool t_std_collections_Stack_1Tt_mx2_Decl_2::m_Empty(){
  return (this->m__0length==bbInt(0));
}

bbArray<bbGCVar<t_mx2_Decl>>* t_std_collections_Stack_1Tt_mx2_Decl_2::m_Data(){
  return this->m__0data;
}

bbBool t_std_collections_Stack_1Tt_mx2_Decl_2::m_Contains(t_mx2_Decl* l_value){
  return (this->m_FindIndex(l_value,bbInt(0))!=-1);
}

void t_std_collections_Stack_1Tt_mx2_Decl_2::m_Clear(){
  this->m_Resize(bbInt(0));
}

bbInt t_std_collections_Stack_1Tt_mx2_Decl_2::m_Capacity(){
  return this->m__0data->length();
}

t_std_collections_Stack_1Tt_mx2_Decl_2_BackwardsIterator t_std_collections_Stack_1Tt_mx2_Decl_2::m_Backwards(){
  return t_std_collections_Stack_1Tt_mx2_Decl_2_BackwardsIterator(this,(this->m__0length-1));
}

t_std_collections_Stack_1Tt_mx2_Decl_2_Iterator t_std_collections_Stack_1Tt_mx2_Decl_2::m_All(){
  return t_std_collections_Stack_1Tt_mx2_Decl_2_Iterator(this,bbInt(0));
}

void t_std_collections_Stack_1Tt_mx2_Decl_2::m_AddAll(bbArray<bbGCVar<t_mx2_Decl>>* l_values){
  this->m_Reserve((this->m__0length+l_values->length()));
  l_values->copyTo(this->m__0data,bbInt(0),this->m__0length,l_values->length());
  this->m_Resize((this->m__0length+l_values->length()));
}

void t_std_collections_Stack_1Tt_mx2_Decl_2::m_Add(t_mx2_Decl* l_value){
  this->m_Reserve((this->m__0length+1));
  this->m__0data->at(this->m__0length)=l_value;
  this->m__0length+=1;
  this->m__0seq+=1;
}

t_std_collections_Stack_1Tt_mx2_ParseEx_2_Iterator::t_std_collections_Stack_1Tt_mx2_ParseEx_2_Iterator(t_std_collections_Stack_1Tt_mx2_ParseEx_2* l_stack,bbInt l_index){
  (*this).m__0stack=l_stack;
  (*this).m__0index=l_index;
  (*this).m__0seq=l_stack->m__0seq;
}

void t_std_collections_Stack_1Tt_mx2_ParseEx_2_Iterator::m_Insert(t_mx2_ParseEx* l_value){
  (*this).m_AssertSeq();
  (*this).m__0stack->m_Insert((*this).m__0index,l_value);
  (*this).m__0seq=(*this).m__0stack->m__0seq;
}

void t_std_collections_Stack_1Tt_mx2_ParseEx_2_Iterator::m_Erase(){
  (*this).m_AssertSeq();
  (*this).m__0stack->m_Erase((*this).m__0index);
  (*this).m__0seq=(*this).m__0stack->m__0seq;
}

void t_std_collections_Stack_1Tt_mx2_ParseEx_2_Iterator::m_Current(t_mx2_ParseEx* l_current){
  (*this).m_AssertCurrent();
  (*this).m__0stack->m__0data->at((*this).m__0index)=l_current;
}

t_mx2_ParseEx* t_std_collections_Stack_1Tt_mx2_ParseEx_2_Iterator::m_Current(){
  (*this).m_AssertCurrent();
  return (*this).m__0stack->m__0data->at((*this).m__0index);
}

void t_std_collections_Stack_1Tt_mx2_ParseEx_2_Iterator::m_Bump(){
  (*this).m_AssertCurrent();
  (*this).m__0index+=1;
}

bbBool t_std_collections_Stack_1Tt_mx2_ParseEx_2_Iterator::m_AtEnd(){
  (*this).m_AssertSeq();
  return ((*this).m__0index==(*this).m__0stack->m__0length);
}

void t_std_collections_Stack_1Tt_mx2_ParseEx_2_Iterator::m_AssertSeq(){
  bbDebugAssert(((*this).m__0seq==(*this).m__0stack->m__0seq),BB_T("Concurrent list modification"));
}

void t_std_collections_Stack_1Tt_mx2_ParseEx_2_Iterator::m_AssertCurrent(){
  bbDebugAssert(!(*this).m_AtEnd(),BB_T("Invalid list iterator"));
}

int bbCompare(const t_std_collections_Stack_1Tt_mx2_ParseEx_2_Iterator&x,const t_std_collections_Stack_1Tt_mx2_ParseEx_2_Iterator&y){
  if(int t=bbCompare(x.m__0stack,y.m__0stack)) return t;
  if(int t=bbCompare(x.m__0index,y.m__0index)) return t;
  if(int t=bbCompare(x.m__0seq,y.m__0seq)) return t;
  return 0;
}

void bbGCMark(const t_std_collections_Stack_1Tt_mx2_ParseEx_2_Iterator&t){
  bbGCMark(t.m__0stack);
}

t_std_collections_Stack_1Tt_mx2_ParseEx_2_BackwardsIterator::t_std_collections_Stack_1Tt_mx2_ParseEx_2_BackwardsIterator(t_std_collections_Stack_1Tt_mx2_ParseEx_2* l_stack,bbInt l_index){
  (*this).m__0stack=l_stack;
  (*this).m__0index=l_index;
  (*this).m__0seq=l_stack->m__0seq;
}

void t_std_collections_Stack_1Tt_mx2_ParseEx_2_BackwardsIterator::m_Insert(t_mx2_ParseEx* l_value){
  (*this).m_AssertSeq();
  (*this).m__0index+=1;
  (*this).m__0stack->m_Insert((*this).m__0index,l_value);
  (*this).m__0seq=(*this).m__0stack->m__0seq;
}

void t_std_collections_Stack_1Tt_mx2_ParseEx_2_BackwardsIterator::m_Erase(){
  (*this).m_AssertCurrent();
  (*this).m__0index-=1;
  (*this).m__0stack->m_Erase(((*this).m__0index+1));
  (*this).m__0seq=(*this).m__0stack->m__0seq;
}

void t_std_collections_Stack_1Tt_mx2_ParseEx_2_BackwardsIterator::m_Current(t_mx2_ParseEx* l_current){
  (*this).m_AssertCurrent();
  (*this).m__0stack->m__0data->at((*this).m__0index)=l_current;
}

t_mx2_ParseEx* t_std_collections_Stack_1Tt_mx2_ParseEx_2_BackwardsIterator::m_Current(){
  (*this).m_AssertCurrent();
  return (*this).m__0stack->m__0data->at((*this).m__0index);
}

void t_std_collections_Stack_1Tt_mx2_ParseEx_2_BackwardsIterator::m_Bump(){
  (*this).m_AssertCurrent();
  (*this).m__0index-=1;
}

bbBool t_std_collections_Stack_1Tt_mx2_ParseEx_2_BackwardsIterator::m_AtEnd(){
  (*this).m_AssertSeq();
  return ((*this).m__0index==-1);
}

void t_std_collections_Stack_1Tt_mx2_ParseEx_2_BackwardsIterator::m_AssertSeq(){
  bbDebugAssert(((*this).m__0seq==(*this).m__0stack->m__0seq),BB_T("Concurrent list modification"));
}

void t_std_collections_Stack_1Tt_mx2_ParseEx_2_BackwardsIterator::m_AssertCurrent(){
  bbDebugAssert(!(*this).m_AtEnd(),BB_T("Invalid list iterator"));
}

int bbCompare(const t_std_collections_Stack_1Tt_mx2_ParseEx_2_BackwardsIterator&x,const t_std_collections_Stack_1Tt_mx2_ParseEx_2_BackwardsIterator&y){
  if(int t=bbCompare(x.m__0stack,y.m__0stack)) return t;
  if(int t=bbCompare(x.m__0index,y.m__0index)) return t;
  if(int t=bbCompare(x.m__0seq,y.m__0seq)) return t;
  return 0;
}

void bbGCMark(const t_std_collections_Stack_1Tt_mx2_ParseEx_2_BackwardsIterator&t){
  bbGCMark(t.m__0stack);
}

void t_std_collections_Stack_1Tt_mx2_ParseEx_2::gcMark(){
  bbGCMark(m__0data);
}

t_std_collections_Stack_1Tt_mx2_ParseEx_2::t_std_collections_Stack_1Tt_mx2_ParseEx_2(t_std_collections_List_1Tt_mx2_ParseEx_2* l_values){
  g_std_collections_Stack_1Tt_mx2_ParseEx_2_AddAll_1Tt_std_collections_List_1Tt_mx2_ParseEx_2_2(this,l_values);
}

t_std_collections_Stack_1Tt_mx2_ParseEx_2::t_std_collections_Stack_1Tt_mx2_ParseEx_2(t_std_collections_Stack_1Tt_mx2_ParseEx_2* l_values){
  struct f0_t : public bbGCFrame{
    bbArray<bbGCVar<t_mx2_ParseEx>>* t0{};
    void gcMark(){
      bbGCMarkPtr(t0);
    }
  }f0{};
  this->m__0length=l_values->m_Length();
  this->m__0data=bbArray<bbGCVar<t_mx2_ParseEx>>::create(this->m__0length);
  (f0.t0=l_values->m_Data())->copyTo(this->m__0data,bbInt(0),bbInt(0),this->m__0length);
}

t_std_collections_Stack_1Tt_mx2_ParseEx_2::t_std_collections_Stack_1Tt_mx2_ParseEx_2(bbArray<bbGCVar<t_mx2_ParseEx>>* l_values){
  this->m_AddAll(l_values);
}

t_std_collections_Stack_1Tt_mx2_ParseEx_2::t_std_collections_Stack_1Tt_mx2_ParseEx_2(bbInt l_length){
  this->m__0length=l_length;
  this->m__0data=bbArray<bbGCVar<t_mx2_ParseEx>>::create(this->m__0length);
}

t_std_collections_Stack_1Tt_mx2_ParseEx_2::t_std_collections_Stack_1Tt_mx2_ParseEx_2(){
  this->m__0data=bbArray<bbGCVar<t_mx2_ParseEx>>::create(10);
}

void t_std_collections_Stack_1Tt_mx2_ParseEx_2::m__idxeq(bbInt l_index,t_mx2_ParseEx* l_value){
  bbDebugAssert(((l_index>=bbInt(0))&&(l_index<this->m__0length)),BB_T("Stack index out of range"));
  this->m__0data->at(l_index)=l_value;
}

t_mx2_ParseEx* t_std_collections_Stack_1Tt_mx2_ParseEx_2::m__idx(bbInt l_index){
  bbDebugAssert(((l_index>=bbInt(0))&&(l_index<this->m__0length)),BB_T("Stack index out of range"));
  return this->m__0data->at(l_index);
}

t_mx2_ParseEx* t_std_collections_Stack_1Tt_mx2_ParseEx_2::m_Top(){
  bbDebugAssert(bbBool(this->m__0length),BB_T("Stack is empty"));
  return this->m__0data->at((this->m__0length-1));
}

bbArray<bbGCVar<t_mx2_ParseEx>>* t_std_collections_Stack_1Tt_mx2_ParseEx_2::m_ToArray(){
  return this->m__0data->slice(bbInt(0),this->m__0length);
}

void t_std_collections_Stack_1Tt_mx2_ParseEx_2::m_Swap(bbInt l_index1,bbInt l_index2){
  struct f0_t : public bbGCFrame{
    t_mx2_ParseEx* l_t{};
    void gcMark(){
      bbGCMarkPtr(l_t);
    }
  }f0{};
  bbDebugAssert(((((l_index1>=bbInt(0))&&(l_index1<this->m__0length))&&(l_index2>=bbInt(0)))&&(l_index2<this->m__0length)),BB_T("Stack index out of range"));
  f0.l_t=this->m__0data->at(l_index1);
  this->m__0data->at(l_index1)=this->m__0data->at(l_index2);
  this->m__0data->at(l_index2)=f0.l_t;
}

void t_std_collections_Stack_1Tt_mx2_ParseEx_2::m_Sort(bbFunction<bbInt(t_mx2_ParseEx*,t_mx2_ParseEx*)> l_compareFunc,bbInt l_lo,bbInt l_hi){
  if((l_hi<=l_lo)){
    return;
  }
  if(((l_lo+1)==l_hi)){
    if((l_compareFunc(this->m__0data->at(l_hi),this->m__0data->at(l_lo))<bbInt(0))){
      this->m_Swap(l_hi,l_lo);
    }
    return;
  }
  bbInt l_i=((l_lo+l_hi)/2);
  if((l_compareFunc(this->m__0data->at(l_i),this->m__0data->at(l_lo))<bbInt(0))){
    this->m_Swap(l_i,l_lo);
  }
  if((l_compareFunc(this->m__0data->at(l_hi),this->m__0data->at(l_i))<bbInt(0))){
    this->m_Swap(l_hi,l_i);
    if((l_compareFunc(this->m__0data->at(l_i),this->m__0data->at(l_lo))<bbInt(0))){
      this->m_Swap(l_i,l_lo);
    }
  }
  bbInt l_x=(l_lo+1);
  bbInt l_y=(l_hi-1);
  do{
    struct f1_t : public bbGCFrame{
      t_mx2_ParseEx* l_p{};
      void gcMark(){
        bbGCMarkPtr(l_p);
      }
    }f1{};
    f1.l_p=this->m__0data->at(l_i);
    while((l_compareFunc(this->m__0data->at(l_x),f1.l_p)<bbInt(0))){
      l_x+=1;
    }
    while((l_compareFunc(f1.l_p,this->m__0data->at(l_y))<bbInt(0))){
      l_y-=1;
    }
    if((l_x>l_y)){
      break;
    }
    if((l_x<l_y)){
      this->m_Swap(l_x,l_y);
      if((l_i==l_x)){
        l_i=l_y;
      }else if((l_i==l_y)){
        l_i=l_x;
      }
    }
    l_x+=1;
    l_y-=1;
  }while(!((l_x>l_y)));
  this->m_Sort(l_compareFunc,l_lo,l_y);
  this->m_Sort(l_compareFunc,l_x,l_hi);
}

void t_std_collections_Stack_1Tt_mx2_ParseEx_2::m_Sort(bbFunction<bbInt(t_mx2_ParseEx*,t_mx2_ParseEx*)> l_compareFunc){
  this->m_Sort(l_compareFunc,bbInt(0),(this->m__0length-1));
}

void t_std_collections_Stack_1Tt_mx2_ParseEx_2::m_Sort(bbBool l_ascending){
  if(l_ascending){
    struct lambda30 : public bbFunction<bbInt(t_mx2_ParseEx*,t_mx2_ParseEx*)>::Rep{
      t_std_collections_Stack_1Tt_mx2_ParseEx_2* l_self;
      lambda30(t_std_collections_Stack_1Tt_mx2_ParseEx_2* l_self):l_self(l_self){
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
      t_std_collections_Stack_1Tt_mx2_ParseEx_2* l_self;
      lambda31(t_std_collections_Stack_1Tt_mx2_ParseEx_2* l_self):l_self(l_self){
      }
      bbInt invoke(t_mx2_ParseEx* l_x,t_mx2_ParseEx* l_y){
        return bbCompare(l_y,l_x);
      }
      void gcMark(){
        bbGCMarkPtr(l_self);
      }
    };
    this->m_Sort(bbFunction<bbInt(t_mx2_ParseEx*,t_mx2_ParseEx*)>(new lambda31(this)));
  }
}

t_std_collections_Stack_1Tt_mx2_ParseEx_2* t_std_collections_Stack_1Tt_mx2_ParseEx_2::m_Slice(bbInt l_index1,bbInt l_index2){
  struct f0_t : public bbGCFrame{
    bbArray<bbGCVar<t_mx2_ParseEx>>* t0{};
    void gcMark(){
      bbGCMarkPtr(t0);
    }
  }f0{};
  if((l_index1<bbInt(0))){
    l_index1=g_monkey_math_Max_1i((l_index1+this->m__0length),bbInt(0));
  }else if((l_index1>this->m__0length)){
    l_index1=this->m__0length;
  }
  if((l_index2<bbInt(0))){
    l_index2=g_monkey_math_Max_1i((l_index2+this->m__0length),l_index1);
  }else if((l_index2>this->m__0length)){
    l_index2=this->m__0length;
  }else if((l_index2<l_index1)){
    l_index2=l_index1;
  }
  return bbGCNew<t_std_collections_Stack_1Tt_mx2_ParseEx_2>(f0.t0=this->m__0data->slice(l_index1,l_index2));
}

t_std_collections_Stack_1Tt_mx2_ParseEx_2* t_std_collections_Stack_1Tt_mx2_ParseEx_2::m_Slice(bbInt l_index){
  return this->m_Slice(l_index,this->m__0length);
}

void t_std_collections_Stack_1Tt_mx2_ParseEx_2::m_Set(bbInt l_index,t_mx2_ParseEx* l_value){
  bbDebugAssert(((l_index>=bbInt(0))&&(l_index<this->m__0length)),BB_T("Stack index out of range"));
  this->m__0data->at(l_index)=l_value;
}

void t_std_collections_Stack_1Tt_mx2_ParseEx_2::m_Resize(bbInt l_length){
  bbDebugAssert((l_length>=bbInt(0)),BB_T("Debug assert failed"));
  {
    bbInt l_i=l_length;
    for(;(l_i<this->m__0length);l_i+=1){
      this->m__0data->at(l_i)=((t_mx2_ParseEx*)0);
    }
  }
  this->m_Reserve(l_length);
  this->m__0length=l_length;
  this->m__0seq+=1;
}

void t_std_collections_Stack_1Tt_mx2_ParseEx_2::m_Reserve(bbInt l_capacity){
  struct f0_t : public bbGCFrame{
    bbArray<bbGCVar<t_mx2_ParseEx>>* l_data{};
    void gcMark(){
      bbGCMarkPtr(l_data);
    }
  }f0{};
  bbDebugAssert((l_capacity>=bbInt(0)),BB_T("Debug assert failed"));
  if((this->m__0data->length()>=l_capacity)){
    return;
  }
  l_capacity=g_monkey_math_Max_1i(((this->m__0length*2)+this->m__0length),l_capacity);
  f0.l_data=bbArray<bbGCVar<t_mx2_ParseEx>>::create(l_capacity);
  this->m__0data->copyTo(f0.l_data,bbInt(0),bbInt(0),this->m__0length);
  this->m__0data=f0.l_data;
}

bbBool t_std_collections_Stack_1Tt_mx2_ParseEx_2::m_RemoveLast(t_mx2_ParseEx* l_value,bbInt l_start){
  bbInt l_i=this->m_FindLastIndex(l_value,l_start);
  if((l_i==-1)){
    return false;
  }
  this->m_Erase(l_i);
  return true;
}

bbInt t_std_collections_Stack_1Tt_mx2_ParseEx_2::m_RemoveEach(t_mx2_ParseEx* l_value){
  bbInt l_put=bbInt(0);
  bbInt l_n=bbInt(0);
  {
    bbInt l_get=bbInt(0);
    for(;(l_get<this->m__0length);l_get+=1){
      if((this->m__0data->at(l_get)==l_value)){
        l_n+=1;
        continue;
      }
      this->m__0data->at(l_put)=this->m__0data->at(l_get);
      l_put+=1;
    }
  }
  this->m_Resize(l_put);
  return l_n;
}

bbBool t_std_collections_Stack_1Tt_mx2_ParseEx_2::m_Remove(t_mx2_ParseEx* l_value,bbInt l_start){
  bbInt l_i=this->m_FindIndex(l_value,l_start);
  if((l_i==-1)){
    return false;
  }
  this->m_Erase(l_i);
  return true;
}

void t_std_collections_Stack_1Tt_mx2_ParseEx_2::m_Push(t_mx2_ParseEx* l_value){
  this->m_Add(l_value);
}

t_mx2_ParseEx* t_std_collections_Stack_1Tt_mx2_ParseEx_2::m_Pop(){
  struct f0_t : public bbGCFrame{
    t_mx2_ParseEx* l_value{};
    void gcMark(){
      bbGCMarkPtr(l_value);
    }
  }f0{};
  bbDebugAssert(bbBool(this->m__0length),BB_T("Stack is empty"));
  this->m__0length-=1;
  this->m__0seq+=1;
  f0.l_value=this->m__0data->at(this->m__0length);
  this->m__0data->at(this->m__0length)=((t_mx2_ParseEx*)0);
  return f0.l_value;
}

bbInt t_std_collections_Stack_1Tt_mx2_ParseEx_2::m_Length(){
  return this->m__0length;
}

void t_std_collections_Stack_1Tt_mx2_ParseEx_2::m_Insert(bbInt l_index,t_mx2_ParseEx* l_value){
  bbDebugAssert(((l_index>=bbInt(0))&&(l_index<=this->m__0length)),BB_T("Debug assert failed"));
  this->m_Reserve((this->m__0length+1));
  this->m__0data->copyTo(this->m__0data,l_index,(l_index+1),(this->m__0length-l_index));
  this->m__0data->at(l_index)=l_value;
  this->m__0length+=1;
  this->m__0seq+=1;
}

t_mx2_ParseEx* t_std_collections_Stack_1Tt_mx2_ParseEx_2::m_Get(bbInt l_index){
  bbDebugAssert(((l_index>=bbInt(0))&&(l_index<this->m__0length)),BB_T("Stack index out of range"));
  return this->m__0data->at(l_index);
}

bbInt t_std_collections_Stack_1Tt_mx2_ParseEx_2::m_FindLastIndex(t_mx2_ParseEx* l_value,bbInt l_start){
  bbDebugAssert(((l_start>=bbInt(0))&&(l_start<=this->m__0length)),BB_T("Debug assert failed"));
  bbInt l_i=this->m__0length;
  while((l_i>l_start)){
    l_i-=1;
    if((this->m__0data->at(l_i)==l_value)){
      return l_i;
    }
  }
  return -1;
}

bbInt t_std_collections_Stack_1Tt_mx2_ParseEx_2::m_FindIndex(t_mx2_ParseEx* l_value,bbInt l_start){
  bbDebugAssert(((l_start>=bbInt(0))&&(l_start<=this->m__0length)),BB_T("Debug assert failed"));
  bbInt l_i=l_start;
  while((l_i<this->m__0length)){
    if((this->m__0data->at(l_i)==l_value)){
      return l_i;
    }
    l_i+=1;
  }
  return -1;
}

void t_std_collections_Stack_1Tt_mx2_ParseEx_2::m_Erase(bbInt l_index1,bbInt l_index2){
  bbDebugAssert((((((l_index1>=bbInt(0))&&(l_index1<=this->m__0length))&&(l_index2>=bbInt(0)))&&(l_index2<=this->m__0length))&&(l_index1<=l_index2)),BB_T("Debug assert failed"));
  if((l_index1==this->m__0length)){
    return;
  }
  this->m__0data->copyTo(this->m__0data,l_index2,l_index1,(this->m__0length-l_index2));
  this->m_Resize(((this->m__0length-l_index2)+l_index1));
}

void t_std_collections_Stack_1Tt_mx2_ParseEx_2::m_Erase(bbInt l_index){
  bbDebugAssert(((l_index>=bbInt(0))&&(l_index<=this->m__0length)),BB_T("Debug assert failed"));
  if((l_index==this->m__0length)){
    return;
  }
  this->m__0data->copyTo(this->m__0data,(l_index+1),l_index,((this->m__0length-l_index)-1));
  this->m_Resize((this->m__0length-1));
}

bbBool t_std_collections_Stack_1Tt_mx2_ParseEx_2::m_Empty(){
  return (this->m__0length==bbInt(0));
}

bbArray<bbGCVar<t_mx2_ParseEx>>* t_std_collections_Stack_1Tt_mx2_ParseEx_2::m_Data(){
  return this->m__0data;
}

bbBool t_std_collections_Stack_1Tt_mx2_ParseEx_2::m_Contains(t_mx2_ParseEx* l_value){
  return (this->m_FindIndex(l_value,bbInt(0))!=-1);
}

void t_std_collections_Stack_1Tt_mx2_ParseEx_2::m_Clear(){
  this->m_Resize(bbInt(0));
}

bbInt t_std_collections_Stack_1Tt_mx2_ParseEx_2::m_Capacity(){
  return this->m__0data->length();
}

t_std_collections_Stack_1Tt_mx2_ParseEx_2_BackwardsIterator t_std_collections_Stack_1Tt_mx2_ParseEx_2::m_Backwards(){
  return t_std_collections_Stack_1Tt_mx2_ParseEx_2_BackwardsIterator(this,(this->m__0length-1));
}

t_std_collections_Stack_1Tt_mx2_ParseEx_2_Iterator t_std_collections_Stack_1Tt_mx2_ParseEx_2::m_All(){
  return t_std_collections_Stack_1Tt_mx2_ParseEx_2_Iterator(this,bbInt(0));
}

void t_std_collections_Stack_1Tt_mx2_ParseEx_2::m_AddAll(bbArray<bbGCVar<t_mx2_ParseEx>>* l_values){
  this->m_Reserve((this->m__0length+l_values->length()));
  l_values->copyTo(this->m__0data,bbInt(0),this->m__0length,l_values->length());
  this->m_Resize((this->m__0length+l_values->length()));
}

void t_std_collections_Stack_1Tt_mx2_ParseEx_2::m_Add(t_mx2_ParseEx* l_value){
  this->m_Reserve((this->m__0length+1));
  this->m__0data->at(this->m__0length)=l_value;
  this->m__0length+=1;
  this->m__0seq+=1;
}

t_std_collections_Stack_1Tt_mx2_Toker_2_Iterator::t_std_collections_Stack_1Tt_mx2_Toker_2_Iterator(t_std_collections_Stack_1Tt_mx2_Toker_2* l_stack,bbInt l_index){
  (*this).m__0stack=l_stack;
  (*this).m__0index=l_index;
  (*this).m__0seq=l_stack->m__0seq;
}

void t_std_collections_Stack_1Tt_mx2_Toker_2_Iterator::m_Insert(t_mx2_Toker* l_value){
  (*this).m_AssertSeq();
  (*this).m__0stack->m_Insert((*this).m__0index,l_value);
  (*this).m__0seq=(*this).m__0stack->m__0seq;
}

void t_std_collections_Stack_1Tt_mx2_Toker_2_Iterator::m_Erase(){
  (*this).m_AssertSeq();
  (*this).m__0stack->m_Erase((*this).m__0index);
  (*this).m__0seq=(*this).m__0stack->m__0seq;
}

void t_std_collections_Stack_1Tt_mx2_Toker_2_Iterator::m_Current(t_mx2_Toker* l_current){
  (*this).m_AssertCurrent();
  (*this).m__0stack->m__0data->at((*this).m__0index)=l_current;
}

t_mx2_Toker* t_std_collections_Stack_1Tt_mx2_Toker_2_Iterator::m_Current(){
  (*this).m_AssertCurrent();
  return (*this).m__0stack->m__0data->at((*this).m__0index);
}

void t_std_collections_Stack_1Tt_mx2_Toker_2_Iterator::m_Bump(){
  (*this).m_AssertCurrent();
  (*this).m__0index+=1;
}

bbBool t_std_collections_Stack_1Tt_mx2_Toker_2_Iterator::m_AtEnd(){
  (*this).m_AssertSeq();
  return ((*this).m__0index==(*this).m__0stack->m__0length);
}

void t_std_collections_Stack_1Tt_mx2_Toker_2_Iterator::m_AssertSeq(){
  bbDebugAssert(((*this).m__0seq==(*this).m__0stack->m__0seq),BB_T("Concurrent list modification"));
}

void t_std_collections_Stack_1Tt_mx2_Toker_2_Iterator::m_AssertCurrent(){
  bbDebugAssert(!(*this).m_AtEnd(),BB_T("Invalid list iterator"));
}

int bbCompare(const t_std_collections_Stack_1Tt_mx2_Toker_2_Iterator&x,const t_std_collections_Stack_1Tt_mx2_Toker_2_Iterator&y){
  if(int t=bbCompare(x.m__0stack,y.m__0stack)) return t;
  if(int t=bbCompare(x.m__0index,y.m__0index)) return t;
  if(int t=bbCompare(x.m__0seq,y.m__0seq)) return t;
  return 0;
}

void bbGCMark(const t_std_collections_Stack_1Tt_mx2_Toker_2_Iterator&t){
  bbGCMark(t.m__0stack);
}

t_std_collections_Stack_1Tt_mx2_Toker_2_BackwardsIterator::t_std_collections_Stack_1Tt_mx2_Toker_2_BackwardsIterator(t_std_collections_Stack_1Tt_mx2_Toker_2* l_stack,bbInt l_index){
  (*this).m__0stack=l_stack;
  (*this).m__0index=l_index;
  (*this).m__0seq=l_stack->m__0seq;
}

void t_std_collections_Stack_1Tt_mx2_Toker_2_BackwardsIterator::m_Insert(t_mx2_Toker* l_value){
  (*this).m_AssertSeq();
  (*this).m__0index+=1;
  (*this).m__0stack->m_Insert((*this).m__0index,l_value);
  (*this).m__0seq=(*this).m__0stack->m__0seq;
}

void t_std_collections_Stack_1Tt_mx2_Toker_2_BackwardsIterator::m_Erase(){
  (*this).m_AssertCurrent();
  (*this).m__0index-=1;
  (*this).m__0stack->m_Erase(((*this).m__0index+1));
  (*this).m__0seq=(*this).m__0stack->m__0seq;
}

void t_std_collections_Stack_1Tt_mx2_Toker_2_BackwardsIterator::m_Current(t_mx2_Toker* l_current){
  (*this).m_AssertCurrent();
  (*this).m__0stack->m__0data->at((*this).m__0index)=l_current;
}

t_mx2_Toker* t_std_collections_Stack_1Tt_mx2_Toker_2_BackwardsIterator::m_Current(){
  (*this).m_AssertCurrent();
  return (*this).m__0stack->m__0data->at((*this).m__0index);
}

void t_std_collections_Stack_1Tt_mx2_Toker_2_BackwardsIterator::m_Bump(){
  (*this).m_AssertCurrent();
  (*this).m__0index-=1;
}

bbBool t_std_collections_Stack_1Tt_mx2_Toker_2_BackwardsIterator::m_AtEnd(){
  (*this).m_AssertSeq();
  return ((*this).m__0index==-1);
}

void t_std_collections_Stack_1Tt_mx2_Toker_2_BackwardsIterator::m_AssertSeq(){
  bbDebugAssert(((*this).m__0seq==(*this).m__0stack->m__0seq),BB_T("Concurrent list modification"));
}

void t_std_collections_Stack_1Tt_mx2_Toker_2_BackwardsIterator::m_AssertCurrent(){
  bbDebugAssert(!(*this).m_AtEnd(),BB_T("Invalid list iterator"));
}

int bbCompare(const t_std_collections_Stack_1Tt_mx2_Toker_2_BackwardsIterator&x,const t_std_collections_Stack_1Tt_mx2_Toker_2_BackwardsIterator&y){
  if(int t=bbCompare(x.m__0stack,y.m__0stack)) return t;
  if(int t=bbCompare(x.m__0index,y.m__0index)) return t;
  if(int t=bbCompare(x.m__0seq,y.m__0seq)) return t;
  return 0;
}

void bbGCMark(const t_std_collections_Stack_1Tt_mx2_Toker_2_BackwardsIterator&t){
  bbGCMark(t.m__0stack);
}

void t_std_collections_Stack_1Tt_mx2_Toker_2::gcMark(){
  bbGCMark(m__0data);
}

t_std_collections_Stack_1Tt_mx2_Toker_2::t_std_collections_Stack_1Tt_mx2_Toker_2(t_std_collections_List_1Tt_mx2_Toker_2* l_values){
  g_std_collections_Stack_1Tt_mx2_Toker_2_AddAll_1Tt_std_collections_List_1Tt_mx2_Toker_2_2(this,l_values);
}

t_std_collections_Stack_1Tt_mx2_Toker_2::t_std_collections_Stack_1Tt_mx2_Toker_2(t_std_collections_Stack_1Tt_mx2_Toker_2* l_values){
  struct f0_t : public bbGCFrame{
    bbArray<bbGCVar<t_mx2_Toker>>* t0{};
    void gcMark(){
      bbGCMarkPtr(t0);
    }
  }f0{};
  this->m__0length=l_values->m_Length();
  this->m__0data=bbArray<bbGCVar<t_mx2_Toker>>::create(this->m__0length);
  (f0.t0=l_values->m_Data())->copyTo(this->m__0data,bbInt(0),bbInt(0),this->m__0length);
}

t_std_collections_Stack_1Tt_mx2_Toker_2::t_std_collections_Stack_1Tt_mx2_Toker_2(bbArray<bbGCVar<t_mx2_Toker>>* l_values){
  this->m_AddAll(l_values);
}

t_std_collections_Stack_1Tt_mx2_Toker_2::t_std_collections_Stack_1Tt_mx2_Toker_2(bbInt l_length){
  this->m__0length=l_length;
  this->m__0data=bbArray<bbGCVar<t_mx2_Toker>>::create(this->m__0length);
}

t_std_collections_Stack_1Tt_mx2_Toker_2::t_std_collections_Stack_1Tt_mx2_Toker_2(){
  this->m__0data=bbArray<bbGCVar<t_mx2_Toker>>::create(10);
}

void t_std_collections_Stack_1Tt_mx2_Toker_2::m__idxeq(bbInt l_index,t_mx2_Toker* l_value){
  bbDebugAssert(((l_index>=bbInt(0))&&(l_index<this->m__0length)),BB_T("Stack index out of range"));
  this->m__0data->at(l_index)=l_value;
}

t_mx2_Toker* t_std_collections_Stack_1Tt_mx2_Toker_2::m__idx(bbInt l_index){
  bbDebugAssert(((l_index>=bbInt(0))&&(l_index<this->m__0length)),BB_T("Stack index out of range"));
  return this->m__0data->at(l_index);
}

t_mx2_Toker* t_std_collections_Stack_1Tt_mx2_Toker_2::m_Top(){
  bbDebugAssert(bbBool(this->m__0length),BB_T("Stack is empty"));
  return this->m__0data->at((this->m__0length-1));
}

bbArray<bbGCVar<t_mx2_Toker>>* t_std_collections_Stack_1Tt_mx2_Toker_2::m_ToArray(){
  return this->m__0data->slice(bbInt(0),this->m__0length);
}

void t_std_collections_Stack_1Tt_mx2_Toker_2::m_Swap(bbInt l_index1,bbInt l_index2){
  struct f0_t : public bbGCFrame{
    t_mx2_Toker* l_t{};
    void gcMark(){
      bbGCMarkPtr(l_t);
    }
  }f0{};
  bbDebugAssert(((((l_index1>=bbInt(0))&&(l_index1<this->m__0length))&&(l_index2>=bbInt(0)))&&(l_index2<this->m__0length)),BB_T("Stack index out of range"));
  f0.l_t=this->m__0data->at(l_index1);
  this->m__0data->at(l_index1)=this->m__0data->at(l_index2);
  this->m__0data->at(l_index2)=f0.l_t;
}

void t_std_collections_Stack_1Tt_mx2_Toker_2::m_Sort(bbFunction<bbInt(t_mx2_Toker*,t_mx2_Toker*)> l_compareFunc,bbInt l_lo,bbInt l_hi){
  if((l_hi<=l_lo)){
    return;
  }
  if(((l_lo+1)==l_hi)){
    if((l_compareFunc(this->m__0data->at(l_hi),this->m__0data->at(l_lo))<bbInt(0))){
      this->m_Swap(l_hi,l_lo);
    }
    return;
  }
  bbInt l_i=((l_lo+l_hi)/2);
  if((l_compareFunc(this->m__0data->at(l_i),this->m__0data->at(l_lo))<bbInt(0))){
    this->m_Swap(l_i,l_lo);
  }
  if((l_compareFunc(this->m__0data->at(l_hi),this->m__0data->at(l_i))<bbInt(0))){
    this->m_Swap(l_hi,l_i);
    if((l_compareFunc(this->m__0data->at(l_i),this->m__0data->at(l_lo))<bbInt(0))){
      this->m_Swap(l_i,l_lo);
    }
  }
  bbInt l_x=(l_lo+1);
  bbInt l_y=(l_hi-1);
  do{
    struct f1_t : public bbGCFrame{
      t_mx2_Toker* l_p{};
      void gcMark(){
        bbGCMarkPtr(l_p);
      }
    }f1{};
    f1.l_p=this->m__0data->at(l_i);
    while((l_compareFunc(this->m__0data->at(l_x),f1.l_p)<bbInt(0))){
      l_x+=1;
    }
    while((l_compareFunc(f1.l_p,this->m__0data->at(l_y))<bbInt(0))){
      l_y-=1;
    }
    if((l_x>l_y)){
      break;
    }
    if((l_x<l_y)){
      this->m_Swap(l_x,l_y);
      if((l_i==l_x)){
        l_i=l_y;
      }else if((l_i==l_y)){
        l_i=l_x;
      }
    }
    l_x+=1;
    l_y-=1;
  }while(!((l_x>l_y)));
  this->m_Sort(l_compareFunc,l_lo,l_y);
  this->m_Sort(l_compareFunc,l_x,l_hi);
}

void t_std_collections_Stack_1Tt_mx2_Toker_2::m_Sort(bbFunction<bbInt(t_mx2_Toker*,t_mx2_Toker*)> l_compareFunc){
  this->m_Sort(l_compareFunc,bbInt(0),(this->m__0length-1));
}

void t_std_collections_Stack_1Tt_mx2_Toker_2::m_Sort(bbBool l_ascending){
  if(l_ascending){
    struct lambda32 : public bbFunction<bbInt(t_mx2_Toker*,t_mx2_Toker*)>::Rep{
      t_std_collections_Stack_1Tt_mx2_Toker_2* l_self;
      lambda32(t_std_collections_Stack_1Tt_mx2_Toker_2* l_self):l_self(l_self){
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
      t_std_collections_Stack_1Tt_mx2_Toker_2* l_self;
      lambda33(t_std_collections_Stack_1Tt_mx2_Toker_2* l_self):l_self(l_self){
      }
      bbInt invoke(t_mx2_Toker* l_x,t_mx2_Toker* l_y){
        return bbCompare(l_y,l_x);
      }
      void gcMark(){
        bbGCMarkPtr(l_self);
      }
    };
    this->m_Sort(bbFunction<bbInt(t_mx2_Toker*,t_mx2_Toker*)>(new lambda33(this)));
  }
}

t_std_collections_Stack_1Tt_mx2_Toker_2* t_std_collections_Stack_1Tt_mx2_Toker_2::m_Slice(bbInt l_index1,bbInt l_index2){
  struct f0_t : public bbGCFrame{
    bbArray<bbGCVar<t_mx2_Toker>>* t0{};
    void gcMark(){
      bbGCMarkPtr(t0);
    }
  }f0{};
  if((l_index1<bbInt(0))){
    l_index1=g_monkey_math_Max_1i((l_index1+this->m__0length),bbInt(0));
  }else if((l_index1>this->m__0length)){
    l_index1=this->m__0length;
  }
  if((l_index2<bbInt(0))){
    l_index2=g_monkey_math_Max_1i((l_index2+this->m__0length),l_index1);
  }else if((l_index2>this->m__0length)){
    l_index2=this->m__0length;
  }else if((l_index2<l_index1)){
    l_index2=l_index1;
  }
  return bbGCNew<t_std_collections_Stack_1Tt_mx2_Toker_2>(f0.t0=this->m__0data->slice(l_index1,l_index2));
}

t_std_collections_Stack_1Tt_mx2_Toker_2* t_std_collections_Stack_1Tt_mx2_Toker_2::m_Slice(bbInt l_index){
  return this->m_Slice(l_index,this->m__0length);
}

void t_std_collections_Stack_1Tt_mx2_Toker_2::m_Set(bbInt l_index,t_mx2_Toker* l_value){
  bbDebugAssert(((l_index>=bbInt(0))&&(l_index<this->m__0length)),BB_T("Stack index out of range"));
  this->m__0data->at(l_index)=l_value;
}

void t_std_collections_Stack_1Tt_mx2_Toker_2::m_Resize(bbInt l_length){
  bbDebugAssert((l_length>=bbInt(0)),BB_T("Debug assert failed"));
  {
    bbInt l_i=l_length;
    for(;(l_i<this->m__0length);l_i+=1){
      this->m__0data->at(l_i)=((t_mx2_Toker*)0);
    }
  }
  this->m_Reserve(l_length);
  this->m__0length=l_length;
  this->m__0seq+=1;
}

void t_std_collections_Stack_1Tt_mx2_Toker_2::m_Reserve(bbInt l_capacity){
  struct f0_t : public bbGCFrame{
    bbArray<bbGCVar<t_mx2_Toker>>* l_data{};
    void gcMark(){
      bbGCMarkPtr(l_data);
    }
  }f0{};
  bbDebugAssert((l_capacity>=bbInt(0)),BB_T("Debug assert failed"));
  if((this->m__0data->length()>=l_capacity)){
    return;
  }
  l_capacity=g_monkey_math_Max_1i(((this->m__0length*2)+this->m__0length),l_capacity);
  f0.l_data=bbArray<bbGCVar<t_mx2_Toker>>::create(l_capacity);
  this->m__0data->copyTo(f0.l_data,bbInt(0),bbInt(0),this->m__0length);
  this->m__0data=f0.l_data;
}

bbBool t_std_collections_Stack_1Tt_mx2_Toker_2::m_RemoveLast(t_mx2_Toker* l_value,bbInt l_start){
  bbInt l_i=this->m_FindLastIndex(l_value,l_start);
  if((l_i==-1)){
    return false;
  }
  this->m_Erase(l_i);
  return true;
}

bbInt t_std_collections_Stack_1Tt_mx2_Toker_2::m_RemoveEach(t_mx2_Toker* l_value){
  bbInt l_put=bbInt(0);
  bbInt l_n=bbInt(0);
  {
    bbInt l_get=bbInt(0);
    for(;(l_get<this->m__0length);l_get+=1){
      if((this->m__0data->at(l_get)==l_value)){
        l_n+=1;
        continue;
      }
      this->m__0data->at(l_put)=this->m__0data->at(l_get);
      l_put+=1;
    }
  }
  this->m_Resize(l_put);
  return l_n;
}

bbBool t_std_collections_Stack_1Tt_mx2_Toker_2::m_Remove(t_mx2_Toker* l_value,bbInt l_start){
  bbInt l_i=this->m_FindIndex(l_value,l_start);
  if((l_i==-1)){
    return false;
  }
  this->m_Erase(l_i);
  return true;
}

void t_std_collections_Stack_1Tt_mx2_Toker_2::m_Push(t_mx2_Toker* l_value){
  this->m_Add(l_value);
}

t_mx2_Toker* t_std_collections_Stack_1Tt_mx2_Toker_2::m_Pop(){
  struct f0_t : public bbGCFrame{
    t_mx2_Toker* l_value{};
    void gcMark(){
      bbGCMarkPtr(l_value);
    }
  }f0{};
  bbDebugAssert(bbBool(this->m__0length),BB_T("Stack is empty"));
  this->m__0length-=1;
  this->m__0seq+=1;
  f0.l_value=this->m__0data->at(this->m__0length);
  this->m__0data->at(this->m__0length)=((t_mx2_Toker*)0);
  return f0.l_value;
}

bbInt t_std_collections_Stack_1Tt_mx2_Toker_2::m_Length(){
  return this->m__0length;
}

void t_std_collections_Stack_1Tt_mx2_Toker_2::m_Insert(bbInt l_index,t_mx2_Toker* l_value){
  bbDebugAssert(((l_index>=bbInt(0))&&(l_index<=this->m__0length)),BB_T("Debug assert failed"));
  this->m_Reserve((this->m__0length+1));
  this->m__0data->copyTo(this->m__0data,l_index,(l_index+1),(this->m__0length-l_index));
  this->m__0data->at(l_index)=l_value;
  this->m__0length+=1;
  this->m__0seq+=1;
}

t_mx2_Toker* t_std_collections_Stack_1Tt_mx2_Toker_2::m_Get(bbInt l_index){
  bbDebugAssert(((l_index>=bbInt(0))&&(l_index<this->m__0length)),BB_T("Stack index out of range"));
  return this->m__0data->at(l_index);
}

bbInt t_std_collections_Stack_1Tt_mx2_Toker_2::m_FindLastIndex(t_mx2_Toker* l_value,bbInt l_start){
  bbDebugAssert(((l_start>=bbInt(0))&&(l_start<=this->m__0length)),BB_T("Debug assert failed"));
  bbInt l_i=this->m__0length;
  while((l_i>l_start)){
    l_i-=1;
    if((this->m__0data->at(l_i)==l_value)){
      return l_i;
    }
  }
  return -1;
}

bbInt t_std_collections_Stack_1Tt_mx2_Toker_2::m_FindIndex(t_mx2_Toker* l_value,bbInt l_start){
  bbDebugAssert(((l_start>=bbInt(0))&&(l_start<=this->m__0length)),BB_T("Debug assert failed"));
  bbInt l_i=l_start;
  while((l_i<this->m__0length)){
    if((this->m__0data->at(l_i)==l_value)){
      return l_i;
    }
    l_i+=1;
  }
  return -1;
}

void t_std_collections_Stack_1Tt_mx2_Toker_2::m_Erase(bbInt l_index1,bbInt l_index2){
  bbDebugAssert((((((l_index1>=bbInt(0))&&(l_index1<=this->m__0length))&&(l_index2>=bbInt(0)))&&(l_index2<=this->m__0length))&&(l_index1<=l_index2)),BB_T("Debug assert failed"));
  if((l_index1==this->m__0length)){
    return;
  }
  this->m__0data->copyTo(this->m__0data,l_index2,l_index1,(this->m__0length-l_index2));
  this->m_Resize(((this->m__0length-l_index2)+l_index1));
}

void t_std_collections_Stack_1Tt_mx2_Toker_2::m_Erase(bbInt l_index){
  bbDebugAssert(((l_index>=bbInt(0))&&(l_index<=this->m__0length)),BB_T("Debug assert failed"));
  if((l_index==this->m__0length)){
    return;
  }
  this->m__0data->copyTo(this->m__0data,(l_index+1),l_index,((this->m__0length-l_index)-1));
  this->m_Resize((this->m__0length-1));
}

bbBool t_std_collections_Stack_1Tt_mx2_Toker_2::m_Empty(){
  return (this->m__0length==bbInt(0));
}

bbArray<bbGCVar<t_mx2_Toker>>* t_std_collections_Stack_1Tt_mx2_Toker_2::m_Data(){
  return this->m__0data;
}

bbBool t_std_collections_Stack_1Tt_mx2_Toker_2::m_Contains(t_mx2_Toker* l_value){
  return (this->m_FindIndex(l_value,bbInt(0))!=-1);
}

void t_std_collections_Stack_1Tt_mx2_Toker_2::m_Clear(){
  this->m_Resize(bbInt(0));
}

bbInt t_std_collections_Stack_1Tt_mx2_Toker_2::m_Capacity(){
  return this->m__0data->length();
}

t_std_collections_Stack_1Tt_mx2_Toker_2_BackwardsIterator t_std_collections_Stack_1Tt_mx2_Toker_2::m_Backwards(){
  return t_std_collections_Stack_1Tt_mx2_Toker_2_BackwardsIterator(this,(this->m__0length-1));
}

t_std_collections_Stack_1Tt_mx2_Toker_2_Iterator t_std_collections_Stack_1Tt_mx2_Toker_2::m_All(){
  return t_std_collections_Stack_1Tt_mx2_Toker_2_Iterator(this,bbInt(0));
}

void t_std_collections_Stack_1Tt_mx2_Toker_2::m_AddAll(bbArray<bbGCVar<t_mx2_Toker>>* l_values){
  this->m_Reserve((this->m__0length+l_values->length()));
  l_values->copyTo(this->m__0data,bbInt(0),this->m__0length,l_values->length());
  this->m_Resize((this->m__0length+l_values->length()));
}

void t_std_collections_Stack_1Tt_mx2_Toker_2::m_Add(t_mx2_Toker* l_value){
  this->m_Reserve((this->m__0length+1));
  this->m__0data->at(this->m__0length)=l_value;
  this->m__0length+=1;
  this->m__0seq+=1;
}

t_std_collections_Stack_1Tt_mx2_Stmt_2_Iterator::t_std_collections_Stack_1Tt_mx2_Stmt_2_Iterator(t_std_collections_Stack_1Tt_mx2_Stmt_2* l_stack,bbInt l_index){
  (*this).m__0stack=l_stack;
  (*this).m__0index=l_index;
  (*this).m__0seq=l_stack->m__0seq;
}

void t_std_collections_Stack_1Tt_mx2_Stmt_2_Iterator::m_Insert(t_mx2_Stmt* l_value){
  (*this).m_AssertSeq();
  (*this).m__0stack->m_Insert((*this).m__0index,l_value);
  (*this).m__0seq=(*this).m__0stack->m__0seq;
}

void t_std_collections_Stack_1Tt_mx2_Stmt_2_Iterator::m_Erase(){
  (*this).m_AssertSeq();
  (*this).m__0stack->m_Erase((*this).m__0index);
  (*this).m__0seq=(*this).m__0stack->m__0seq;
}

void t_std_collections_Stack_1Tt_mx2_Stmt_2_Iterator::m_Current(t_mx2_Stmt* l_current){
  (*this).m_AssertCurrent();
  (*this).m__0stack->m__0data->at((*this).m__0index)=l_current;
}

t_mx2_Stmt* t_std_collections_Stack_1Tt_mx2_Stmt_2_Iterator::m_Current(){
  (*this).m_AssertCurrent();
  return (*this).m__0stack->m__0data->at((*this).m__0index);
}

void t_std_collections_Stack_1Tt_mx2_Stmt_2_Iterator::m_Bump(){
  (*this).m_AssertCurrent();
  (*this).m__0index+=1;
}

bbBool t_std_collections_Stack_1Tt_mx2_Stmt_2_Iterator::m_AtEnd(){
  (*this).m_AssertSeq();
  return ((*this).m__0index==(*this).m__0stack->m__0length);
}

void t_std_collections_Stack_1Tt_mx2_Stmt_2_Iterator::m_AssertSeq(){
  bbDebugAssert(((*this).m__0seq==(*this).m__0stack->m__0seq),BB_T("Concurrent list modification"));
}

void t_std_collections_Stack_1Tt_mx2_Stmt_2_Iterator::m_AssertCurrent(){
  bbDebugAssert(!(*this).m_AtEnd(),BB_T("Invalid list iterator"));
}

int bbCompare(const t_std_collections_Stack_1Tt_mx2_Stmt_2_Iterator&x,const t_std_collections_Stack_1Tt_mx2_Stmt_2_Iterator&y){
  if(int t=bbCompare(x.m__0stack,y.m__0stack)) return t;
  if(int t=bbCompare(x.m__0index,y.m__0index)) return t;
  if(int t=bbCompare(x.m__0seq,y.m__0seq)) return t;
  return 0;
}

void bbGCMark(const t_std_collections_Stack_1Tt_mx2_Stmt_2_Iterator&t){
  bbGCMark(t.m__0stack);
}

t_std_collections_Stack_1Tt_mx2_Stmt_2_BackwardsIterator::t_std_collections_Stack_1Tt_mx2_Stmt_2_BackwardsIterator(t_std_collections_Stack_1Tt_mx2_Stmt_2* l_stack,bbInt l_index){
  (*this).m__0stack=l_stack;
  (*this).m__0index=l_index;
  (*this).m__0seq=l_stack->m__0seq;
}

void t_std_collections_Stack_1Tt_mx2_Stmt_2_BackwardsIterator::m_Insert(t_mx2_Stmt* l_value){
  (*this).m_AssertSeq();
  (*this).m__0index+=1;
  (*this).m__0stack->m_Insert((*this).m__0index,l_value);
  (*this).m__0seq=(*this).m__0stack->m__0seq;
}

void t_std_collections_Stack_1Tt_mx2_Stmt_2_BackwardsIterator::m_Erase(){
  (*this).m_AssertCurrent();
  (*this).m__0index-=1;
  (*this).m__0stack->m_Erase(((*this).m__0index+1));
  (*this).m__0seq=(*this).m__0stack->m__0seq;
}

void t_std_collections_Stack_1Tt_mx2_Stmt_2_BackwardsIterator::m_Current(t_mx2_Stmt* l_current){
  (*this).m_AssertCurrent();
  (*this).m__0stack->m__0data->at((*this).m__0index)=l_current;
}

t_mx2_Stmt* t_std_collections_Stack_1Tt_mx2_Stmt_2_BackwardsIterator::m_Current(){
  (*this).m_AssertCurrent();
  return (*this).m__0stack->m__0data->at((*this).m__0index);
}

void t_std_collections_Stack_1Tt_mx2_Stmt_2_BackwardsIterator::m_Bump(){
  (*this).m_AssertCurrent();
  (*this).m__0index-=1;
}

bbBool t_std_collections_Stack_1Tt_mx2_Stmt_2_BackwardsIterator::m_AtEnd(){
  (*this).m_AssertSeq();
  return ((*this).m__0index==-1);
}

void t_std_collections_Stack_1Tt_mx2_Stmt_2_BackwardsIterator::m_AssertSeq(){
  bbDebugAssert(((*this).m__0seq==(*this).m__0stack->m__0seq),BB_T("Concurrent list modification"));
}

void t_std_collections_Stack_1Tt_mx2_Stmt_2_BackwardsIterator::m_AssertCurrent(){
  bbDebugAssert(!(*this).m_AtEnd(),BB_T("Invalid list iterator"));
}

int bbCompare(const t_std_collections_Stack_1Tt_mx2_Stmt_2_BackwardsIterator&x,const t_std_collections_Stack_1Tt_mx2_Stmt_2_BackwardsIterator&y){
  if(int t=bbCompare(x.m__0stack,y.m__0stack)) return t;
  if(int t=bbCompare(x.m__0index,y.m__0index)) return t;
  if(int t=bbCompare(x.m__0seq,y.m__0seq)) return t;
  return 0;
}

void bbGCMark(const t_std_collections_Stack_1Tt_mx2_Stmt_2_BackwardsIterator&t){
  bbGCMark(t.m__0stack);
}

void t_std_collections_Stack_1Tt_mx2_Stmt_2::gcMark(){
  bbGCMark(m__0data);
}

t_std_collections_Stack_1Tt_mx2_Stmt_2::t_std_collections_Stack_1Tt_mx2_Stmt_2(t_std_collections_List_1Tt_mx2_Stmt_2* l_values){
  g_std_collections_Stack_1Tt_mx2_Stmt_2_AddAll_1Tt_std_collections_List_1Tt_mx2_Stmt_2_2(this,l_values);
}

t_std_collections_Stack_1Tt_mx2_Stmt_2::t_std_collections_Stack_1Tt_mx2_Stmt_2(t_std_collections_Stack_1Tt_mx2_Stmt_2* l_values){
  struct f0_t : public bbGCFrame{
    bbArray<bbGCVar<t_mx2_Stmt>>* t0{};
    void gcMark(){
      bbGCMarkPtr(t0);
    }
  }f0{};
  this->m__0length=l_values->m_Length();
  this->m__0data=bbArray<bbGCVar<t_mx2_Stmt>>::create(this->m__0length);
  (f0.t0=l_values->m_Data())->copyTo(this->m__0data,bbInt(0),bbInt(0),this->m__0length);
}

t_std_collections_Stack_1Tt_mx2_Stmt_2::t_std_collections_Stack_1Tt_mx2_Stmt_2(bbArray<bbGCVar<t_mx2_Stmt>>* l_values){
  this->m_AddAll(l_values);
}

t_std_collections_Stack_1Tt_mx2_Stmt_2::t_std_collections_Stack_1Tt_mx2_Stmt_2(bbInt l_length){
  this->m__0length=l_length;
  this->m__0data=bbArray<bbGCVar<t_mx2_Stmt>>::create(this->m__0length);
}

t_std_collections_Stack_1Tt_mx2_Stmt_2::t_std_collections_Stack_1Tt_mx2_Stmt_2(){
  this->m__0data=bbArray<bbGCVar<t_mx2_Stmt>>::create(10);
}

void t_std_collections_Stack_1Tt_mx2_Stmt_2::m__idxeq(bbInt l_index,t_mx2_Stmt* l_value){
  bbDebugAssert(((l_index>=bbInt(0))&&(l_index<this->m__0length)),BB_T("Stack index out of range"));
  this->m__0data->at(l_index)=l_value;
}

t_mx2_Stmt* t_std_collections_Stack_1Tt_mx2_Stmt_2::m__idx(bbInt l_index){
  bbDebugAssert(((l_index>=bbInt(0))&&(l_index<this->m__0length)),BB_T("Stack index out of range"));
  return this->m__0data->at(l_index);
}

t_mx2_Stmt* t_std_collections_Stack_1Tt_mx2_Stmt_2::m_Top(){
  bbDebugAssert(bbBool(this->m__0length),BB_T("Stack is empty"));
  return this->m__0data->at((this->m__0length-1));
}

bbArray<bbGCVar<t_mx2_Stmt>>* t_std_collections_Stack_1Tt_mx2_Stmt_2::m_ToArray(){
  return this->m__0data->slice(bbInt(0),this->m__0length);
}

void t_std_collections_Stack_1Tt_mx2_Stmt_2::m_Swap(bbInt l_index1,bbInt l_index2){
  struct f0_t : public bbGCFrame{
    t_mx2_Stmt* l_t{};
    void gcMark(){
      bbGCMarkPtr(l_t);
    }
  }f0{};
  bbDebugAssert(((((l_index1>=bbInt(0))&&(l_index1<this->m__0length))&&(l_index2>=bbInt(0)))&&(l_index2<this->m__0length)),BB_T("Stack index out of range"));
  f0.l_t=this->m__0data->at(l_index1);
  this->m__0data->at(l_index1)=this->m__0data->at(l_index2);
  this->m__0data->at(l_index2)=f0.l_t;
}

void t_std_collections_Stack_1Tt_mx2_Stmt_2::m_Sort(bbFunction<bbInt(t_mx2_Stmt*,t_mx2_Stmt*)> l_compareFunc,bbInt l_lo,bbInt l_hi){
  if((l_hi<=l_lo)){
    return;
  }
  if(((l_lo+1)==l_hi)){
    if((l_compareFunc(this->m__0data->at(l_hi),this->m__0data->at(l_lo))<bbInt(0))){
      this->m_Swap(l_hi,l_lo);
    }
    return;
  }
  bbInt l_i=((l_lo+l_hi)/2);
  if((l_compareFunc(this->m__0data->at(l_i),this->m__0data->at(l_lo))<bbInt(0))){
    this->m_Swap(l_i,l_lo);
  }
  if((l_compareFunc(this->m__0data->at(l_hi),this->m__0data->at(l_i))<bbInt(0))){
    this->m_Swap(l_hi,l_i);
    if((l_compareFunc(this->m__0data->at(l_i),this->m__0data->at(l_lo))<bbInt(0))){
      this->m_Swap(l_i,l_lo);
    }
  }
  bbInt l_x=(l_lo+1);
  bbInt l_y=(l_hi-1);
  do{
    struct f1_t : public bbGCFrame{
      t_mx2_Stmt* l_p{};
      void gcMark(){
        bbGCMarkPtr(l_p);
      }
    }f1{};
    f1.l_p=this->m__0data->at(l_i);
    while((l_compareFunc(this->m__0data->at(l_x),f1.l_p)<bbInt(0))){
      l_x+=1;
    }
    while((l_compareFunc(f1.l_p,this->m__0data->at(l_y))<bbInt(0))){
      l_y-=1;
    }
    if((l_x>l_y)){
      break;
    }
    if((l_x<l_y)){
      this->m_Swap(l_x,l_y);
      if((l_i==l_x)){
        l_i=l_y;
      }else if((l_i==l_y)){
        l_i=l_x;
      }
    }
    l_x+=1;
    l_y-=1;
  }while(!((l_x>l_y)));
  this->m_Sort(l_compareFunc,l_lo,l_y);
  this->m_Sort(l_compareFunc,l_x,l_hi);
}

void t_std_collections_Stack_1Tt_mx2_Stmt_2::m_Sort(bbFunction<bbInt(t_mx2_Stmt*,t_mx2_Stmt*)> l_compareFunc){
  this->m_Sort(l_compareFunc,bbInt(0),(this->m__0length-1));
}

void t_std_collections_Stack_1Tt_mx2_Stmt_2::m_Sort(bbBool l_ascending){
  if(l_ascending){
    struct lambda34 : public bbFunction<bbInt(t_mx2_Stmt*,t_mx2_Stmt*)>::Rep{
      t_std_collections_Stack_1Tt_mx2_Stmt_2* l_self;
      lambda34(t_std_collections_Stack_1Tt_mx2_Stmt_2* l_self):l_self(l_self){
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
      t_std_collections_Stack_1Tt_mx2_Stmt_2* l_self;
      lambda35(t_std_collections_Stack_1Tt_mx2_Stmt_2* l_self):l_self(l_self){
      }
      bbInt invoke(t_mx2_Stmt* l_x,t_mx2_Stmt* l_y){
        return bbCompare(l_y,l_x);
      }
      void gcMark(){
        bbGCMarkPtr(l_self);
      }
    };
    this->m_Sort(bbFunction<bbInt(t_mx2_Stmt*,t_mx2_Stmt*)>(new lambda35(this)));
  }
}

t_std_collections_Stack_1Tt_mx2_Stmt_2* t_std_collections_Stack_1Tt_mx2_Stmt_2::m_Slice(bbInt l_index1,bbInt l_index2){
  struct f0_t : public bbGCFrame{
    bbArray<bbGCVar<t_mx2_Stmt>>* t0{};
    void gcMark(){
      bbGCMarkPtr(t0);
    }
  }f0{};
  if((l_index1<bbInt(0))){
    l_index1=g_monkey_math_Max_1i((l_index1+this->m__0length),bbInt(0));
  }else if((l_index1>this->m__0length)){
    l_index1=this->m__0length;
  }
  if((l_index2<bbInt(0))){
    l_index2=g_monkey_math_Max_1i((l_index2+this->m__0length),l_index1);
  }else if((l_index2>this->m__0length)){
    l_index2=this->m__0length;
  }else if((l_index2<l_index1)){
    l_index2=l_index1;
  }
  return bbGCNew<t_std_collections_Stack_1Tt_mx2_Stmt_2>(f0.t0=this->m__0data->slice(l_index1,l_index2));
}

t_std_collections_Stack_1Tt_mx2_Stmt_2* t_std_collections_Stack_1Tt_mx2_Stmt_2::m_Slice(bbInt l_index){
  return this->m_Slice(l_index,this->m__0length);
}

void t_std_collections_Stack_1Tt_mx2_Stmt_2::m_Set(bbInt l_index,t_mx2_Stmt* l_value){
  bbDebugAssert(((l_index>=bbInt(0))&&(l_index<this->m__0length)),BB_T("Stack index out of range"));
  this->m__0data->at(l_index)=l_value;
}

void t_std_collections_Stack_1Tt_mx2_Stmt_2::m_Resize(bbInt l_length){
  bbDebugAssert((l_length>=bbInt(0)),BB_T("Debug assert failed"));
  {
    bbInt l_i=l_length;
    for(;(l_i<this->m__0length);l_i+=1){
      this->m__0data->at(l_i)=((t_mx2_Stmt*)0);
    }
  }
  this->m_Reserve(l_length);
  this->m__0length=l_length;
  this->m__0seq+=1;
}

void t_std_collections_Stack_1Tt_mx2_Stmt_2::m_Reserve(bbInt l_capacity){
  struct f0_t : public bbGCFrame{
    bbArray<bbGCVar<t_mx2_Stmt>>* l_data{};
    void gcMark(){
      bbGCMarkPtr(l_data);
    }
  }f0{};
  bbDebugAssert((l_capacity>=bbInt(0)),BB_T("Debug assert failed"));
  if((this->m__0data->length()>=l_capacity)){
    return;
  }
  l_capacity=g_monkey_math_Max_1i(((this->m__0length*2)+this->m__0length),l_capacity);
  f0.l_data=bbArray<bbGCVar<t_mx2_Stmt>>::create(l_capacity);
  this->m__0data->copyTo(f0.l_data,bbInt(0),bbInt(0),this->m__0length);
  this->m__0data=f0.l_data;
}

bbBool t_std_collections_Stack_1Tt_mx2_Stmt_2::m_RemoveLast(t_mx2_Stmt* l_value,bbInt l_start){
  bbInt l_i=this->m_FindLastIndex(l_value,l_start);
  if((l_i==-1)){
    return false;
  }
  this->m_Erase(l_i);
  return true;
}

bbInt t_std_collections_Stack_1Tt_mx2_Stmt_2::m_RemoveEach(t_mx2_Stmt* l_value){
  bbInt l_put=bbInt(0);
  bbInt l_n=bbInt(0);
  {
    bbInt l_get=bbInt(0);
    for(;(l_get<this->m__0length);l_get+=1){
      if((this->m__0data->at(l_get)==l_value)){
        l_n+=1;
        continue;
      }
      this->m__0data->at(l_put)=this->m__0data->at(l_get);
      l_put+=1;
    }
  }
  this->m_Resize(l_put);
  return l_n;
}

bbBool t_std_collections_Stack_1Tt_mx2_Stmt_2::m_Remove(t_mx2_Stmt* l_value,bbInt l_start){
  bbInt l_i=this->m_FindIndex(l_value,l_start);
  if((l_i==-1)){
    return false;
  }
  this->m_Erase(l_i);
  return true;
}

void t_std_collections_Stack_1Tt_mx2_Stmt_2::m_Push(t_mx2_Stmt* l_value){
  this->m_Add(l_value);
}

t_mx2_Stmt* t_std_collections_Stack_1Tt_mx2_Stmt_2::m_Pop(){
  struct f0_t : public bbGCFrame{
    t_mx2_Stmt* l_value{};
    void gcMark(){
      bbGCMarkPtr(l_value);
    }
  }f0{};
  bbDebugAssert(bbBool(this->m__0length),BB_T("Stack is empty"));
  this->m__0length-=1;
  this->m__0seq+=1;
  f0.l_value=this->m__0data->at(this->m__0length);
  this->m__0data->at(this->m__0length)=((t_mx2_Stmt*)0);
  return f0.l_value;
}

bbInt t_std_collections_Stack_1Tt_mx2_Stmt_2::m_Length(){
  return this->m__0length;
}

void t_std_collections_Stack_1Tt_mx2_Stmt_2::m_Insert(bbInt l_index,t_mx2_Stmt* l_value){
  bbDebugAssert(((l_index>=bbInt(0))&&(l_index<=this->m__0length)),BB_T("Debug assert failed"));
  this->m_Reserve((this->m__0length+1));
  this->m__0data->copyTo(this->m__0data,l_index,(l_index+1),(this->m__0length-l_index));
  this->m__0data->at(l_index)=l_value;
  this->m__0length+=1;
  this->m__0seq+=1;
}

t_mx2_Stmt* t_std_collections_Stack_1Tt_mx2_Stmt_2::m_Get(bbInt l_index){
  bbDebugAssert(((l_index>=bbInt(0))&&(l_index<this->m__0length)),BB_T("Stack index out of range"));
  return this->m__0data->at(l_index);
}

bbInt t_std_collections_Stack_1Tt_mx2_Stmt_2::m_FindLastIndex(t_mx2_Stmt* l_value,bbInt l_start){
  bbDebugAssert(((l_start>=bbInt(0))&&(l_start<=this->m__0length)),BB_T("Debug assert failed"));
  bbInt l_i=this->m__0length;
  while((l_i>l_start)){
    l_i-=1;
    if((this->m__0data->at(l_i)==l_value)){
      return l_i;
    }
  }
  return -1;
}

bbInt t_std_collections_Stack_1Tt_mx2_Stmt_2::m_FindIndex(t_mx2_Stmt* l_value,bbInt l_start){
  bbDebugAssert(((l_start>=bbInt(0))&&(l_start<=this->m__0length)),BB_T("Debug assert failed"));
  bbInt l_i=l_start;
  while((l_i<this->m__0length)){
    if((this->m__0data->at(l_i)==l_value)){
      return l_i;
    }
    l_i+=1;
  }
  return -1;
}

void t_std_collections_Stack_1Tt_mx2_Stmt_2::m_Erase(bbInt l_index1,bbInt l_index2){
  bbDebugAssert((((((l_index1>=bbInt(0))&&(l_index1<=this->m__0length))&&(l_index2>=bbInt(0)))&&(l_index2<=this->m__0length))&&(l_index1<=l_index2)),BB_T("Debug assert failed"));
  if((l_index1==this->m__0length)){
    return;
  }
  this->m__0data->copyTo(this->m__0data,l_index2,l_index1,(this->m__0length-l_index2));
  this->m_Resize(((this->m__0length-l_index2)+l_index1));
}

void t_std_collections_Stack_1Tt_mx2_Stmt_2::m_Erase(bbInt l_index){
  bbDebugAssert(((l_index>=bbInt(0))&&(l_index<=this->m__0length)),BB_T("Debug assert failed"));
  if((l_index==this->m__0length)){
    return;
  }
  this->m__0data->copyTo(this->m__0data,(l_index+1),l_index,((this->m__0length-l_index)-1));
  this->m_Resize((this->m__0length-1));
}

bbBool t_std_collections_Stack_1Tt_mx2_Stmt_2::m_Empty(){
  return (this->m__0length==bbInt(0));
}

bbArray<bbGCVar<t_mx2_Stmt>>* t_std_collections_Stack_1Tt_mx2_Stmt_2::m_Data(){
  return this->m__0data;
}

bbBool t_std_collections_Stack_1Tt_mx2_Stmt_2::m_Contains(t_mx2_Stmt* l_value){
  return (this->m_FindIndex(l_value,bbInt(0))!=-1);
}

void t_std_collections_Stack_1Tt_mx2_Stmt_2::m_Clear(){
  this->m_Resize(bbInt(0));
}

bbInt t_std_collections_Stack_1Tt_mx2_Stmt_2::m_Capacity(){
  return this->m__0data->length();
}

t_std_collections_Stack_1Tt_mx2_Stmt_2_BackwardsIterator t_std_collections_Stack_1Tt_mx2_Stmt_2::m_Backwards(){
  return t_std_collections_Stack_1Tt_mx2_Stmt_2_BackwardsIterator(this,(this->m__0length-1));
}

t_std_collections_Stack_1Tt_mx2_Stmt_2_Iterator t_std_collections_Stack_1Tt_mx2_Stmt_2::m_All(){
  return t_std_collections_Stack_1Tt_mx2_Stmt_2_Iterator(this,bbInt(0));
}

void t_std_collections_Stack_1Tt_mx2_Stmt_2::m_AddAll(bbArray<bbGCVar<t_mx2_Stmt>>* l_values){
  this->m_Reserve((this->m__0length+l_values->length()));
  l_values->copyTo(this->m__0data,bbInt(0),this->m__0length,l_values->length());
  this->m_Resize((this->m__0length+l_values->length()));
}

void t_std_collections_Stack_1Tt_mx2_Stmt_2::m_Add(t_mx2_Stmt* l_value){
  this->m_Reserve((this->m__0length+1));
  this->m__0data->at(this->m__0length)=l_value;
  this->m__0length+=1;
  this->m__0seq+=1;
}

t_std_collections_Stack_1Tt_mx2_Translator_GCTmp_2_Iterator::t_std_collections_Stack_1Tt_mx2_Translator_GCTmp_2_Iterator(t_std_collections_Stack_1Tt_mx2_Translator_GCTmp_2* l_stack,bbInt l_index){
  (*this).m__0stack=l_stack;
  (*this).m__0index=l_index;
  (*this).m__0seq=l_stack->m__0seq;
}

void t_std_collections_Stack_1Tt_mx2_Translator_GCTmp_2_Iterator::m_Insert(t_mx2_Translator_GCTmp* l_value){
  (*this).m_AssertSeq();
  (*this).m__0stack->m_Insert((*this).m__0index,l_value);
  (*this).m__0seq=(*this).m__0stack->m__0seq;
}

void t_std_collections_Stack_1Tt_mx2_Translator_GCTmp_2_Iterator::m_Erase(){
  (*this).m_AssertSeq();
  (*this).m__0stack->m_Erase((*this).m__0index);
  (*this).m__0seq=(*this).m__0stack->m__0seq;
}

void t_std_collections_Stack_1Tt_mx2_Translator_GCTmp_2_Iterator::m_Current(t_mx2_Translator_GCTmp* l_current){
  (*this).m_AssertCurrent();
  (*this).m__0stack->m__0data->at((*this).m__0index)=l_current;
}

t_mx2_Translator_GCTmp* t_std_collections_Stack_1Tt_mx2_Translator_GCTmp_2_Iterator::m_Current(){
  (*this).m_AssertCurrent();
  return (*this).m__0stack->m__0data->at((*this).m__0index);
}

void t_std_collections_Stack_1Tt_mx2_Translator_GCTmp_2_Iterator::m_Bump(){
  (*this).m_AssertCurrent();
  (*this).m__0index+=1;
}

bbBool t_std_collections_Stack_1Tt_mx2_Translator_GCTmp_2_Iterator::m_AtEnd(){
  (*this).m_AssertSeq();
  return ((*this).m__0index==(*this).m__0stack->m__0length);
}

void t_std_collections_Stack_1Tt_mx2_Translator_GCTmp_2_Iterator::m_AssertSeq(){
  bbDebugAssert(((*this).m__0seq==(*this).m__0stack->m__0seq),BB_T("Concurrent list modification"));
}

void t_std_collections_Stack_1Tt_mx2_Translator_GCTmp_2_Iterator::m_AssertCurrent(){
  bbDebugAssert(!(*this).m_AtEnd(),BB_T("Invalid list iterator"));
}

int bbCompare(const t_std_collections_Stack_1Tt_mx2_Translator_GCTmp_2_Iterator&x,const t_std_collections_Stack_1Tt_mx2_Translator_GCTmp_2_Iterator&y){
  if(int t=bbCompare(x.m__0stack,y.m__0stack)) return t;
  if(int t=bbCompare(x.m__0index,y.m__0index)) return t;
  if(int t=bbCompare(x.m__0seq,y.m__0seq)) return t;
  return 0;
}

void bbGCMark(const t_std_collections_Stack_1Tt_mx2_Translator_GCTmp_2_Iterator&t){
  bbGCMark(t.m__0stack);
}

t_std_collections_Stack_1Tt_mx2_Translator_GCTmp_2_BackwardsIterator::t_std_collections_Stack_1Tt_mx2_Translator_GCTmp_2_BackwardsIterator(t_std_collections_Stack_1Tt_mx2_Translator_GCTmp_2* l_stack,bbInt l_index){
  (*this).m__0stack=l_stack;
  (*this).m__0index=l_index;
  (*this).m__0seq=l_stack->m__0seq;
}

void t_std_collections_Stack_1Tt_mx2_Translator_GCTmp_2_BackwardsIterator::m_Insert(t_mx2_Translator_GCTmp* l_value){
  (*this).m_AssertSeq();
  (*this).m__0index+=1;
  (*this).m__0stack->m_Insert((*this).m__0index,l_value);
  (*this).m__0seq=(*this).m__0stack->m__0seq;
}

void t_std_collections_Stack_1Tt_mx2_Translator_GCTmp_2_BackwardsIterator::m_Erase(){
  (*this).m_AssertCurrent();
  (*this).m__0index-=1;
  (*this).m__0stack->m_Erase(((*this).m__0index+1));
  (*this).m__0seq=(*this).m__0stack->m__0seq;
}

void t_std_collections_Stack_1Tt_mx2_Translator_GCTmp_2_BackwardsIterator::m_Current(t_mx2_Translator_GCTmp* l_current){
  (*this).m_AssertCurrent();
  (*this).m__0stack->m__0data->at((*this).m__0index)=l_current;
}

t_mx2_Translator_GCTmp* t_std_collections_Stack_1Tt_mx2_Translator_GCTmp_2_BackwardsIterator::m_Current(){
  (*this).m_AssertCurrent();
  return (*this).m__0stack->m__0data->at((*this).m__0index);
}

void t_std_collections_Stack_1Tt_mx2_Translator_GCTmp_2_BackwardsIterator::m_Bump(){
  (*this).m_AssertCurrent();
  (*this).m__0index-=1;
}

bbBool t_std_collections_Stack_1Tt_mx2_Translator_GCTmp_2_BackwardsIterator::m_AtEnd(){
  (*this).m_AssertSeq();
  return ((*this).m__0index==-1);
}

void t_std_collections_Stack_1Tt_mx2_Translator_GCTmp_2_BackwardsIterator::m_AssertSeq(){
  bbDebugAssert(((*this).m__0seq==(*this).m__0stack->m__0seq),BB_T("Concurrent list modification"));
}

void t_std_collections_Stack_1Tt_mx2_Translator_GCTmp_2_BackwardsIterator::m_AssertCurrent(){
  bbDebugAssert(!(*this).m_AtEnd(),BB_T("Invalid list iterator"));
}

int bbCompare(const t_std_collections_Stack_1Tt_mx2_Translator_GCTmp_2_BackwardsIterator&x,const t_std_collections_Stack_1Tt_mx2_Translator_GCTmp_2_BackwardsIterator&y){
  if(int t=bbCompare(x.m__0stack,y.m__0stack)) return t;
  if(int t=bbCompare(x.m__0index,y.m__0index)) return t;
  if(int t=bbCompare(x.m__0seq,y.m__0seq)) return t;
  return 0;
}

void bbGCMark(const t_std_collections_Stack_1Tt_mx2_Translator_GCTmp_2_BackwardsIterator&t){
  bbGCMark(t.m__0stack);
}

void t_std_collections_Stack_1Tt_mx2_Translator_GCTmp_2::gcMark(){
  bbGCMark(m__0data);
}

t_std_collections_Stack_1Tt_mx2_Translator_GCTmp_2::t_std_collections_Stack_1Tt_mx2_Translator_GCTmp_2(t_std_collections_List_1Tt_mx2_Translator_GCTmp_2* l_values){
  g_std_collections_Stack_1Tt_mx2_Translator_GCTmp_2_AddAll_1Tt_std_collections_List_1Tt_mx2_Translator_GCTmp_2_2(this,l_values);
}

t_std_collections_Stack_1Tt_mx2_Translator_GCTmp_2::t_std_collections_Stack_1Tt_mx2_Translator_GCTmp_2(t_std_collections_Stack_1Tt_mx2_Translator_GCTmp_2* l_values){
  struct f0_t : public bbGCFrame{
    bbArray<bbGCVar<t_mx2_Translator_GCTmp>>* t0{};
    void gcMark(){
      bbGCMarkPtr(t0);
    }
  }f0{};
  this->m__0length=l_values->m_Length();
  this->m__0data=bbArray<bbGCVar<t_mx2_Translator_GCTmp>>::create(this->m__0length);
  (f0.t0=l_values->m_Data())->copyTo(this->m__0data,bbInt(0),bbInt(0),this->m__0length);
}

t_std_collections_Stack_1Tt_mx2_Translator_GCTmp_2::t_std_collections_Stack_1Tt_mx2_Translator_GCTmp_2(bbArray<bbGCVar<t_mx2_Translator_GCTmp>>* l_values){
  this->m_AddAll(l_values);
}

t_std_collections_Stack_1Tt_mx2_Translator_GCTmp_2::t_std_collections_Stack_1Tt_mx2_Translator_GCTmp_2(bbInt l_length){
  this->m__0length=l_length;
  this->m__0data=bbArray<bbGCVar<t_mx2_Translator_GCTmp>>::create(this->m__0length);
}

t_std_collections_Stack_1Tt_mx2_Translator_GCTmp_2::t_std_collections_Stack_1Tt_mx2_Translator_GCTmp_2(){
  this->m__0data=bbArray<bbGCVar<t_mx2_Translator_GCTmp>>::create(10);
}

void t_std_collections_Stack_1Tt_mx2_Translator_GCTmp_2::m__idxeq(bbInt l_index,t_mx2_Translator_GCTmp* l_value){
  bbDebugAssert(((l_index>=bbInt(0))&&(l_index<this->m__0length)),BB_T("Stack index out of range"));
  this->m__0data->at(l_index)=l_value;
}

t_mx2_Translator_GCTmp* t_std_collections_Stack_1Tt_mx2_Translator_GCTmp_2::m__idx(bbInt l_index){
  bbDebugAssert(((l_index>=bbInt(0))&&(l_index<this->m__0length)),BB_T("Stack index out of range"));
  return this->m__0data->at(l_index);
}

t_mx2_Translator_GCTmp* t_std_collections_Stack_1Tt_mx2_Translator_GCTmp_2::m_Top(){
  bbDebugAssert(bbBool(this->m__0length),BB_T("Stack is empty"));
  return this->m__0data->at((this->m__0length-1));
}

bbArray<bbGCVar<t_mx2_Translator_GCTmp>>* t_std_collections_Stack_1Tt_mx2_Translator_GCTmp_2::m_ToArray(){
  return this->m__0data->slice(bbInt(0),this->m__0length);
}

void t_std_collections_Stack_1Tt_mx2_Translator_GCTmp_2::m_Swap(bbInt l_index1,bbInt l_index2){
  struct f0_t : public bbGCFrame{
    t_mx2_Translator_GCTmp* l_t{};
    void gcMark(){
      bbGCMarkPtr(l_t);
    }
  }f0{};
  bbDebugAssert(((((l_index1>=bbInt(0))&&(l_index1<this->m__0length))&&(l_index2>=bbInt(0)))&&(l_index2<this->m__0length)),BB_T("Stack index out of range"));
  f0.l_t=this->m__0data->at(l_index1);
  this->m__0data->at(l_index1)=this->m__0data->at(l_index2);
  this->m__0data->at(l_index2)=f0.l_t;
}

void t_std_collections_Stack_1Tt_mx2_Translator_GCTmp_2::m_Sort(bbFunction<bbInt(t_mx2_Translator_GCTmp*,t_mx2_Translator_GCTmp*)> l_compareFunc,bbInt l_lo,bbInt l_hi){
  if((l_hi<=l_lo)){
    return;
  }
  if(((l_lo+1)==l_hi)){
    if((l_compareFunc(this->m__0data->at(l_hi),this->m__0data->at(l_lo))<bbInt(0))){
      this->m_Swap(l_hi,l_lo);
    }
    return;
  }
  bbInt l_i=((l_lo+l_hi)/2);
  if((l_compareFunc(this->m__0data->at(l_i),this->m__0data->at(l_lo))<bbInt(0))){
    this->m_Swap(l_i,l_lo);
  }
  if((l_compareFunc(this->m__0data->at(l_hi),this->m__0data->at(l_i))<bbInt(0))){
    this->m_Swap(l_hi,l_i);
    if((l_compareFunc(this->m__0data->at(l_i),this->m__0data->at(l_lo))<bbInt(0))){
      this->m_Swap(l_i,l_lo);
    }
  }
  bbInt l_x=(l_lo+1);
  bbInt l_y=(l_hi-1);
  do{
    struct f1_t : public bbGCFrame{
      t_mx2_Translator_GCTmp* l_p{};
      void gcMark(){
        bbGCMarkPtr(l_p);
      }
    }f1{};
    f1.l_p=this->m__0data->at(l_i);
    while((l_compareFunc(this->m__0data->at(l_x),f1.l_p)<bbInt(0))){
      l_x+=1;
    }
    while((l_compareFunc(f1.l_p,this->m__0data->at(l_y))<bbInt(0))){
      l_y-=1;
    }
    if((l_x>l_y)){
      break;
    }
    if((l_x<l_y)){
      this->m_Swap(l_x,l_y);
      if((l_i==l_x)){
        l_i=l_y;
      }else if((l_i==l_y)){
        l_i=l_x;
      }
    }
    l_x+=1;
    l_y-=1;
  }while(!((l_x>l_y)));
  this->m_Sort(l_compareFunc,l_lo,l_y);
  this->m_Sort(l_compareFunc,l_x,l_hi);
}

void t_std_collections_Stack_1Tt_mx2_Translator_GCTmp_2::m_Sort(bbFunction<bbInt(t_mx2_Translator_GCTmp*,t_mx2_Translator_GCTmp*)> l_compareFunc){
  this->m_Sort(l_compareFunc,bbInt(0),(this->m__0length-1));
}

void t_std_collections_Stack_1Tt_mx2_Translator_GCTmp_2::m_Sort(bbBool l_ascending){
  if(l_ascending){
    struct lambda36 : public bbFunction<bbInt(t_mx2_Translator_GCTmp*,t_mx2_Translator_GCTmp*)>::Rep{
      t_std_collections_Stack_1Tt_mx2_Translator_GCTmp_2* l_self;
      lambda36(t_std_collections_Stack_1Tt_mx2_Translator_GCTmp_2* l_self):l_self(l_self){
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
      t_std_collections_Stack_1Tt_mx2_Translator_GCTmp_2* l_self;
      lambda37(t_std_collections_Stack_1Tt_mx2_Translator_GCTmp_2* l_self):l_self(l_self){
      }
      bbInt invoke(t_mx2_Translator_GCTmp* l_x,t_mx2_Translator_GCTmp* l_y){
        return bbCompare(l_y,l_x);
      }
      void gcMark(){
        bbGCMarkPtr(l_self);
      }
    };
    this->m_Sort(bbFunction<bbInt(t_mx2_Translator_GCTmp*,t_mx2_Translator_GCTmp*)>(new lambda37(this)));
  }
}

t_std_collections_Stack_1Tt_mx2_Translator_GCTmp_2* t_std_collections_Stack_1Tt_mx2_Translator_GCTmp_2::m_Slice(bbInt l_index1,bbInt l_index2){
  struct f0_t : public bbGCFrame{
    bbArray<bbGCVar<t_mx2_Translator_GCTmp>>* t0{};
    void gcMark(){
      bbGCMarkPtr(t0);
    }
  }f0{};
  if((l_index1<bbInt(0))){
    l_index1=g_monkey_math_Max_1i((l_index1+this->m__0length),bbInt(0));
  }else if((l_index1>this->m__0length)){
    l_index1=this->m__0length;
  }
  if((l_index2<bbInt(0))){
    l_index2=g_monkey_math_Max_1i((l_index2+this->m__0length),l_index1);
  }else if((l_index2>this->m__0length)){
    l_index2=this->m__0length;
  }else if((l_index2<l_index1)){
    l_index2=l_index1;
  }
  return bbGCNew<t_std_collections_Stack_1Tt_mx2_Translator_GCTmp_2>(f0.t0=this->m__0data->slice(l_index1,l_index2));
}

t_std_collections_Stack_1Tt_mx2_Translator_GCTmp_2* t_std_collections_Stack_1Tt_mx2_Translator_GCTmp_2::m_Slice(bbInt l_index){
  return this->m_Slice(l_index,this->m__0length);
}

void t_std_collections_Stack_1Tt_mx2_Translator_GCTmp_2::m_Set(bbInt l_index,t_mx2_Translator_GCTmp* l_value){
  bbDebugAssert(((l_index>=bbInt(0))&&(l_index<this->m__0length)),BB_T("Stack index out of range"));
  this->m__0data->at(l_index)=l_value;
}

void t_std_collections_Stack_1Tt_mx2_Translator_GCTmp_2::m_Resize(bbInt l_length){
  bbDebugAssert((l_length>=bbInt(0)),BB_T("Debug assert failed"));
  {
    bbInt l_i=l_length;
    for(;(l_i<this->m__0length);l_i+=1){
      this->m__0data->at(l_i)=((t_mx2_Translator_GCTmp*)0);
    }
  }
  this->m_Reserve(l_length);
  this->m__0length=l_length;
  this->m__0seq+=1;
}

void t_std_collections_Stack_1Tt_mx2_Translator_GCTmp_2::m_Reserve(bbInt l_capacity){
  struct f0_t : public bbGCFrame{
    bbArray<bbGCVar<t_mx2_Translator_GCTmp>>* l_data{};
    void gcMark(){
      bbGCMarkPtr(l_data);
    }
  }f0{};
  bbDebugAssert((l_capacity>=bbInt(0)),BB_T("Debug assert failed"));
  if((this->m__0data->length()>=l_capacity)){
    return;
  }
  l_capacity=g_monkey_math_Max_1i(((this->m__0length*2)+this->m__0length),l_capacity);
  f0.l_data=bbArray<bbGCVar<t_mx2_Translator_GCTmp>>::create(l_capacity);
  this->m__0data->copyTo(f0.l_data,bbInt(0),bbInt(0),this->m__0length);
  this->m__0data=f0.l_data;
}

bbBool t_std_collections_Stack_1Tt_mx2_Translator_GCTmp_2::m_RemoveLast(t_mx2_Translator_GCTmp* l_value,bbInt l_start){
  bbInt l_i=this->m_FindLastIndex(l_value,l_start);
  if((l_i==-1)){
    return false;
  }
  this->m_Erase(l_i);
  return true;
}

bbInt t_std_collections_Stack_1Tt_mx2_Translator_GCTmp_2::m_RemoveEach(t_mx2_Translator_GCTmp* l_value){
  bbInt l_put=bbInt(0);
  bbInt l_n=bbInt(0);
  {
    bbInt l_get=bbInt(0);
    for(;(l_get<this->m__0length);l_get+=1){
      if((this->m__0data->at(l_get)==l_value)){
        l_n+=1;
        continue;
      }
      this->m__0data->at(l_put)=this->m__0data->at(l_get);
      l_put+=1;
    }
  }
  this->m_Resize(l_put);
  return l_n;
}

bbBool t_std_collections_Stack_1Tt_mx2_Translator_GCTmp_2::m_Remove(t_mx2_Translator_GCTmp* l_value,bbInt l_start){
  bbInt l_i=this->m_FindIndex(l_value,l_start);
  if((l_i==-1)){
    return false;
  }
  this->m_Erase(l_i);
  return true;
}

void t_std_collections_Stack_1Tt_mx2_Translator_GCTmp_2::m_Push(t_mx2_Translator_GCTmp* l_value){
  this->m_Add(l_value);
}

t_mx2_Translator_GCTmp* t_std_collections_Stack_1Tt_mx2_Translator_GCTmp_2::m_Pop(){
  struct f0_t : public bbGCFrame{
    t_mx2_Translator_GCTmp* l_value{};
    void gcMark(){
      bbGCMarkPtr(l_value);
    }
  }f0{};
  bbDebugAssert(bbBool(this->m__0length),BB_T("Stack is empty"));
  this->m__0length-=1;
  this->m__0seq+=1;
  f0.l_value=this->m__0data->at(this->m__0length);
  this->m__0data->at(this->m__0length)=((t_mx2_Translator_GCTmp*)0);
  return f0.l_value;
}

bbInt t_std_collections_Stack_1Tt_mx2_Translator_GCTmp_2::m_Length(){
  return this->m__0length;
}

void t_std_collections_Stack_1Tt_mx2_Translator_GCTmp_2::m_Insert(bbInt l_index,t_mx2_Translator_GCTmp* l_value){
  bbDebugAssert(((l_index>=bbInt(0))&&(l_index<=this->m__0length)),BB_T("Debug assert failed"));
  this->m_Reserve((this->m__0length+1));
  this->m__0data->copyTo(this->m__0data,l_index,(l_index+1),(this->m__0length-l_index));
  this->m__0data->at(l_index)=l_value;
  this->m__0length+=1;
  this->m__0seq+=1;
}

t_mx2_Translator_GCTmp* t_std_collections_Stack_1Tt_mx2_Translator_GCTmp_2::m_Get(bbInt l_index){
  bbDebugAssert(((l_index>=bbInt(0))&&(l_index<this->m__0length)),BB_T("Stack index out of range"));
  return this->m__0data->at(l_index);
}

bbInt t_std_collections_Stack_1Tt_mx2_Translator_GCTmp_2::m_FindLastIndex(t_mx2_Translator_GCTmp* l_value,bbInt l_start){
  bbDebugAssert(((l_start>=bbInt(0))&&(l_start<=this->m__0length)),BB_T("Debug assert failed"));
  bbInt l_i=this->m__0length;
  while((l_i>l_start)){
    l_i-=1;
    if((this->m__0data->at(l_i)==l_value)){
      return l_i;
    }
  }
  return -1;
}

bbInt t_std_collections_Stack_1Tt_mx2_Translator_GCTmp_2::m_FindIndex(t_mx2_Translator_GCTmp* l_value,bbInt l_start){
  bbDebugAssert(((l_start>=bbInt(0))&&(l_start<=this->m__0length)),BB_T("Debug assert failed"));
  bbInt l_i=l_start;
  while((l_i<this->m__0length)){
    if((this->m__0data->at(l_i)==l_value)){
      return l_i;
    }
    l_i+=1;
  }
  return -1;
}

void t_std_collections_Stack_1Tt_mx2_Translator_GCTmp_2::m_Erase(bbInt l_index1,bbInt l_index2){
  bbDebugAssert((((((l_index1>=bbInt(0))&&(l_index1<=this->m__0length))&&(l_index2>=bbInt(0)))&&(l_index2<=this->m__0length))&&(l_index1<=l_index2)),BB_T("Debug assert failed"));
  if((l_index1==this->m__0length)){
    return;
  }
  this->m__0data->copyTo(this->m__0data,l_index2,l_index1,(this->m__0length-l_index2));
  this->m_Resize(((this->m__0length-l_index2)+l_index1));
}

void t_std_collections_Stack_1Tt_mx2_Translator_GCTmp_2::m_Erase(bbInt l_index){
  bbDebugAssert(((l_index>=bbInt(0))&&(l_index<=this->m__0length)),BB_T("Debug assert failed"));
  if((l_index==this->m__0length)){
    return;
  }
  this->m__0data->copyTo(this->m__0data,(l_index+1),l_index,((this->m__0length-l_index)-1));
  this->m_Resize((this->m__0length-1));
}

bbBool t_std_collections_Stack_1Tt_mx2_Translator_GCTmp_2::m_Empty(){
  return (this->m__0length==bbInt(0));
}

bbArray<bbGCVar<t_mx2_Translator_GCTmp>>* t_std_collections_Stack_1Tt_mx2_Translator_GCTmp_2::m_Data(){
  return this->m__0data;
}

bbBool t_std_collections_Stack_1Tt_mx2_Translator_GCTmp_2::m_Contains(t_mx2_Translator_GCTmp* l_value){
  return (this->m_FindIndex(l_value,bbInt(0))!=-1);
}

void t_std_collections_Stack_1Tt_mx2_Translator_GCTmp_2::m_Clear(){
  this->m_Resize(bbInt(0));
}

bbInt t_std_collections_Stack_1Tt_mx2_Translator_GCTmp_2::m_Capacity(){
  return this->m__0data->length();
}

t_std_collections_Stack_1Tt_mx2_Translator_GCTmp_2_BackwardsIterator t_std_collections_Stack_1Tt_mx2_Translator_GCTmp_2::m_Backwards(){
  return t_std_collections_Stack_1Tt_mx2_Translator_GCTmp_2_BackwardsIterator(this,(this->m__0length-1));
}

t_std_collections_Stack_1Tt_mx2_Translator_GCTmp_2_Iterator t_std_collections_Stack_1Tt_mx2_Translator_GCTmp_2::m_All(){
  return t_std_collections_Stack_1Tt_mx2_Translator_GCTmp_2_Iterator(this,bbInt(0));
}

void t_std_collections_Stack_1Tt_mx2_Translator_GCTmp_2::m_AddAll(bbArray<bbGCVar<t_mx2_Translator_GCTmp>>* l_values){
  this->m_Reserve((this->m__0length+l_values->length()));
  l_values->copyTo(this->m__0data,bbInt(0),this->m__0length,l_values->length());
  this->m_Resize((this->m__0length+l_values->length()));
}

void t_std_collections_Stack_1Tt_mx2_Translator_GCTmp_2::m_Add(t_mx2_Translator_GCTmp* l_value){
  this->m_Reserve((this->m__0length+1));
  this->m__0data->at(this->m__0length)=l_value;
  this->m__0length+=1;
  this->m__0seq+=1;
}

t_std_collections_Stack_1Tt_mx2_TypeExpr_2_Iterator::t_std_collections_Stack_1Tt_mx2_TypeExpr_2_Iterator(t_std_collections_Stack_1Tt_mx2_TypeExpr_2* l_stack,bbInt l_index){
  (*this).m__0stack=l_stack;
  (*this).m__0index=l_index;
  (*this).m__0seq=l_stack->m__0seq;
}

void t_std_collections_Stack_1Tt_mx2_TypeExpr_2_Iterator::m_Insert(t_mx2_TypeExpr* l_value){
  (*this).m_AssertSeq();
  (*this).m__0stack->m_Insert((*this).m__0index,l_value);
  (*this).m__0seq=(*this).m__0stack->m__0seq;
}

void t_std_collections_Stack_1Tt_mx2_TypeExpr_2_Iterator::m_Erase(){
  (*this).m_AssertSeq();
  (*this).m__0stack->m_Erase((*this).m__0index);
  (*this).m__0seq=(*this).m__0stack->m__0seq;
}

void t_std_collections_Stack_1Tt_mx2_TypeExpr_2_Iterator::m_Current(t_mx2_TypeExpr* l_current){
  (*this).m_AssertCurrent();
  (*this).m__0stack->m__0data->at((*this).m__0index)=l_current;
}

t_mx2_TypeExpr* t_std_collections_Stack_1Tt_mx2_TypeExpr_2_Iterator::m_Current(){
  (*this).m_AssertCurrent();
  return (*this).m__0stack->m__0data->at((*this).m__0index);
}

void t_std_collections_Stack_1Tt_mx2_TypeExpr_2_Iterator::m_Bump(){
  (*this).m_AssertCurrent();
  (*this).m__0index+=1;
}

bbBool t_std_collections_Stack_1Tt_mx2_TypeExpr_2_Iterator::m_AtEnd(){
  (*this).m_AssertSeq();
  return ((*this).m__0index==(*this).m__0stack->m__0length);
}

void t_std_collections_Stack_1Tt_mx2_TypeExpr_2_Iterator::m_AssertSeq(){
  bbDebugAssert(((*this).m__0seq==(*this).m__0stack->m__0seq),BB_T("Concurrent list modification"));
}

void t_std_collections_Stack_1Tt_mx2_TypeExpr_2_Iterator::m_AssertCurrent(){
  bbDebugAssert(!(*this).m_AtEnd(),BB_T("Invalid list iterator"));
}

int bbCompare(const t_std_collections_Stack_1Tt_mx2_TypeExpr_2_Iterator&x,const t_std_collections_Stack_1Tt_mx2_TypeExpr_2_Iterator&y){
  if(int t=bbCompare(x.m__0stack,y.m__0stack)) return t;
  if(int t=bbCompare(x.m__0index,y.m__0index)) return t;
  if(int t=bbCompare(x.m__0seq,y.m__0seq)) return t;
  return 0;
}

void bbGCMark(const t_std_collections_Stack_1Tt_mx2_TypeExpr_2_Iterator&t){
  bbGCMark(t.m__0stack);
}

t_std_collections_Stack_1Tt_mx2_TypeExpr_2_BackwardsIterator::t_std_collections_Stack_1Tt_mx2_TypeExpr_2_BackwardsIterator(t_std_collections_Stack_1Tt_mx2_TypeExpr_2* l_stack,bbInt l_index){
  (*this).m__0stack=l_stack;
  (*this).m__0index=l_index;
  (*this).m__0seq=l_stack->m__0seq;
}

void t_std_collections_Stack_1Tt_mx2_TypeExpr_2_BackwardsIterator::m_Insert(t_mx2_TypeExpr* l_value){
  (*this).m_AssertSeq();
  (*this).m__0index+=1;
  (*this).m__0stack->m_Insert((*this).m__0index,l_value);
  (*this).m__0seq=(*this).m__0stack->m__0seq;
}

void t_std_collections_Stack_1Tt_mx2_TypeExpr_2_BackwardsIterator::m_Erase(){
  (*this).m_AssertCurrent();
  (*this).m__0index-=1;
  (*this).m__0stack->m_Erase(((*this).m__0index+1));
  (*this).m__0seq=(*this).m__0stack->m__0seq;
}

void t_std_collections_Stack_1Tt_mx2_TypeExpr_2_BackwardsIterator::m_Current(t_mx2_TypeExpr* l_current){
  (*this).m_AssertCurrent();
  (*this).m__0stack->m__0data->at((*this).m__0index)=l_current;
}

t_mx2_TypeExpr* t_std_collections_Stack_1Tt_mx2_TypeExpr_2_BackwardsIterator::m_Current(){
  (*this).m_AssertCurrent();
  return (*this).m__0stack->m__0data->at((*this).m__0index);
}

void t_std_collections_Stack_1Tt_mx2_TypeExpr_2_BackwardsIterator::m_Bump(){
  (*this).m_AssertCurrent();
  (*this).m__0index-=1;
}

bbBool t_std_collections_Stack_1Tt_mx2_TypeExpr_2_BackwardsIterator::m_AtEnd(){
  (*this).m_AssertSeq();
  return ((*this).m__0index==-1);
}

void t_std_collections_Stack_1Tt_mx2_TypeExpr_2_BackwardsIterator::m_AssertSeq(){
  bbDebugAssert(((*this).m__0seq==(*this).m__0stack->m__0seq),BB_T("Concurrent list modification"));
}

void t_std_collections_Stack_1Tt_mx2_TypeExpr_2_BackwardsIterator::m_AssertCurrent(){
  bbDebugAssert(!(*this).m_AtEnd(),BB_T("Invalid list iterator"));
}

int bbCompare(const t_std_collections_Stack_1Tt_mx2_TypeExpr_2_BackwardsIterator&x,const t_std_collections_Stack_1Tt_mx2_TypeExpr_2_BackwardsIterator&y){
  if(int t=bbCompare(x.m__0stack,y.m__0stack)) return t;
  if(int t=bbCompare(x.m__0index,y.m__0index)) return t;
  if(int t=bbCompare(x.m__0seq,y.m__0seq)) return t;
  return 0;
}

void bbGCMark(const t_std_collections_Stack_1Tt_mx2_TypeExpr_2_BackwardsIterator&t){
  bbGCMark(t.m__0stack);
}

void t_std_collections_Stack_1Tt_mx2_TypeExpr_2::gcMark(){
  bbGCMark(m__0data);
}

t_std_collections_Stack_1Tt_mx2_TypeExpr_2::t_std_collections_Stack_1Tt_mx2_TypeExpr_2(t_std_collections_List_1Tt_mx2_TypeExpr_2* l_values){
  g_std_collections_Stack_1Tt_mx2_TypeExpr_2_AddAll_1Tt_std_collections_List_1Tt_mx2_TypeExpr_2_2(this,l_values);
}

t_std_collections_Stack_1Tt_mx2_TypeExpr_2::t_std_collections_Stack_1Tt_mx2_TypeExpr_2(t_std_collections_Stack_1Tt_mx2_TypeExpr_2* l_values){
  struct f0_t : public bbGCFrame{
    bbArray<bbGCVar<t_mx2_TypeExpr>>* t0{};
    void gcMark(){
      bbGCMarkPtr(t0);
    }
  }f0{};
  this->m__0length=l_values->m_Length();
  this->m__0data=bbArray<bbGCVar<t_mx2_TypeExpr>>::create(this->m__0length);
  (f0.t0=l_values->m_Data())->copyTo(this->m__0data,bbInt(0),bbInt(0),this->m__0length);
}

t_std_collections_Stack_1Tt_mx2_TypeExpr_2::t_std_collections_Stack_1Tt_mx2_TypeExpr_2(bbArray<bbGCVar<t_mx2_TypeExpr>>* l_values){
  this->m_AddAll(l_values);
}

t_std_collections_Stack_1Tt_mx2_TypeExpr_2::t_std_collections_Stack_1Tt_mx2_TypeExpr_2(bbInt l_length){
  this->m__0length=l_length;
  this->m__0data=bbArray<bbGCVar<t_mx2_TypeExpr>>::create(this->m__0length);
}

t_std_collections_Stack_1Tt_mx2_TypeExpr_2::t_std_collections_Stack_1Tt_mx2_TypeExpr_2(){
  this->m__0data=bbArray<bbGCVar<t_mx2_TypeExpr>>::create(10);
}

void t_std_collections_Stack_1Tt_mx2_TypeExpr_2::m__idxeq(bbInt l_index,t_mx2_TypeExpr* l_value){
  bbDebugAssert(((l_index>=bbInt(0))&&(l_index<this->m__0length)),BB_T("Stack index out of range"));
  this->m__0data->at(l_index)=l_value;
}

t_mx2_TypeExpr* t_std_collections_Stack_1Tt_mx2_TypeExpr_2::m__idx(bbInt l_index){
  bbDebugAssert(((l_index>=bbInt(0))&&(l_index<this->m__0length)),BB_T("Stack index out of range"));
  return this->m__0data->at(l_index);
}

t_mx2_TypeExpr* t_std_collections_Stack_1Tt_mx2_TypeExpr_2::m_Top(){
  bbDebugAssert(bbBool(this->m__0length),BB_T("Stack is empty"));
  return this->m__0data->at((this->m__0length-1));
}

bbArray<bbGCVar<t_mx2_TypeExpr>>* t_std_collections_Stack_1Tt_mx2_TypeExpr_2::m_ToArray(){
  return this->m__0data->slice(bbInt(0),this->m__0length);
}

void t_std_collections_Stack_1Tt_mx2_TypeExpr_2::m_Swap(bbInt l_index1,bbInt l_index2){
  struct f0_t : public bbGCFrame{
    t_mx2_TypeExpr* l_t{};
    void gcMark(){
      bbGCMarkPtr(l_t);
    }
  }f0{};
  bbDebugAssert(((((l_index1>=bbInt(0))&&(l_index1<this->m__0length))&&(l_index2>=bbInt(0)))&&(l_index2<this->m__0length)),BB_T("Stack index out of range"));
  f0.l_t=this->m__0data->at(l_index1);
  this->m__0data->at(l_index1)=this->m__0data->at(l_index2);
  this->m__0data->at(l_index2)=f0.l_t;
}

void t_std_collections_Stack_1Tt_mx2_TypeExpr_2::m_Sort(bbFunction<bbInt(t_mx2_TypeExpr*,t_mx2_TypeExpr*)> l_compareFunc,bbInt l_lo,bbInt l_hi){
  if((l_hi<=l_lo)){
    return;
  }
  if(((l_lo+1)==l_hi)){
    if((l_compareFunc(this->m__0data->at(l_hi),this->m__0data->at(l_lo))<bbInt(0))){
      this->m_Swap(l_hi,l_lo);
    }
    return;
  }
  bbInt l_i=((l_lo+l_hi)/2);
  if((l_compareFunc(this->m__0data->at(l_i),this->m__0data->at(l_lo))<bbInt(0))){
    this->m_Swap(l_i,l_lo);
  }
  if((l_compareFunc(this->m__0data->at(l_hi),this->m__0data->at(l_i))<bbInt(0))){
    this->m_Swap(l_hi,l_i);
    if((l_compareFunc(this->m__0data->at(l_i),this->m__0data->at(l_lo))<bbInt(0))){
      this->m_Swap(l_i,l_lo);
    }
  }
  bbInt l_x=(l_lo+1);
  bbInt l_y=(l_hi-1);
  do{
    struct f1_t : public bbGCFrame{
      t_mx2_TypeExpr* l_p{};
      void gcMark(){
        bbGCMarkPtr(l_p);
      }
    }f1{};
    f1.l_p=this->m__0data->at(l_i);
    while((l_compareFunc(this->m__0data->at(l_x),f1.l_p)<bbInt(0))){
      l_x+=1;
    }
    while((l_compareFunc(f1.l_p,this->m__0data->at(l_y))<bbInt(0))){
      l_y-=1;
    }
    if((l_x>l_y)){
      break;
    }
    if((l_x<l_y)){
      this->m_Swap(l_x,l_y);
      if((l_i==l_x)){
        l_i=l_y;
      }else if((l_i==l_y)){
        l_i=l_x;
      }
    }
    l_x+=1;
    l_y-=1;
  }while(!((l_x>l_y)));
  this->m_Sort(l_compareFunc,l_lo,l_y);
  this->m_Sort(l_compareFunc,l_x,l_hi);
}

void t_std_collections_Stack_1Tt_mx2_TypeExpr_2::m_Sort(bbFunction<bbInt(t_mx2_TypeExpr*,t_mx2_TypeExpr*)> l_compareFunc){
  this->m_Sort(l_compareFunc,bbInt(0),(this->m__0length-1));
}

void t_std_collections_Stack_1Tt_mx2_TypeExpr_2::m_Sort(bbBool l_ascending){
  if(l_ascending){
    struct lambda38 : public bbFunction<bbInt(t_mx2_TypeExpr*,t_mx2_TypeExpr*)>::Rep{
      t_std_collections_Stack_1Tt_mx2_TypeExpr_2* l_self;
      lambda38(t_std_collections_Stack_1Tt_mx2_TypeExpr_2* l_self):l_self(l_self){
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
      t_std_collections_Stack_1Tt_mx2_TypeExpr_2* l_self;
      lambda39(t_std_collections_Stack_1Tt_mx2_TypeExpr_2* l_self):l_self(l_self){
      }
      bbInt invoke(t_mx2_TypeExpr* l_x,t_mx2_TypeExpr* l_y){
        return bbCompare(l_y,l_x);
      }
      void gcMark(){
        bbGCMarkPtr(l_self);
      }
    };
    this->m_Sort(bbFunction<bbInt(t_mx2_TypeExpr*,t_mx2_TypeExpr*)>(new lambda39(this)));
  }
}

t_std_collections_Stack_1Tt_mx2_TypeExpr_2* t_std_collections_Stack_1Tt_mx2_TypeExpr_2::m_Slice(bbInt l_index1,bbInt l_index2){
  struct f0_t : public bbGCFrame{
    bbArray<bbGCVar<t_mx2_TypeExpr>>* t0{};
    void gcMark(){
      bbGCMarkPtr(t0);
    }
  }f0{};
  if((l_index1<bbInt(0))){
    l_index1=g_monkey_math_Max_1i((l_index1+this->m__0length),bbInt(0));
  }else if((l_index1>this->m__0length)){
    l_index1=this->m__0length;
  }
  if((l_index2<bbInt(0))){
    l_index2=g_monkey_math_Max_1i((l_index2+this->m__0length),l_index1);
  }else if((l_index2>this->m__0length)){
    l_index2=this->m__0length;
  }else if((l_index2<l_index1)){
    l_index2=l_index1;
  }
  return bbGCNew<t_std_collections_Stack_1Tt_mx2_TypeExpr_2>(f0.t0=this->m__0data->slice(l_index1,l_index2));
}

t_std_collections_Stack_1Tt_mx2_TypeExpr_2* t_std_collections_Stack_1Tt_mx2_TypeExpr_2::m_Slice(bbInt l_index){
  return this->m_Slice(l_index,this->m__0length);
}

void t_std_collections_Stack_1Tt_mx2_TypeExpr_2::m_Set(bbInt l_index,t_mx2_TypeExpr* l_value){
  bbDebugAssert(((l_index>=bbInt(0))&&(l_index<this->m__0length)),BB_T("Stack index out of range"));
  this->m__0data->at(l_index)=l_value;
}

void t_std_collections_Stack_1Tt_mx2_TypeExpr_2::m_Resize(bbInt l_length){
  bbDebugAssert((l_length>=bbInt(0)),BB_T("Debug assert failed"));
  {
    bbInt l_i=l_length;
    for(;(l_i<this->m__0length);l_i+=1){
      this->m__0data->at(l_i)=((t_mx2_TypeExpr*)0);
    }
  }
  this->m_Reserve(l_length);
  this->m__0length=l_length;
  this->m__0seq+=1;
}

void t_std_collections_Stack_1Tt_mx2_TypeExpr_2::m_Reserve(bbInt l_capacity){
  struct f0_t : public bbGCFrame{
    bbArray<bbGCVar<t_mx2_TypeExpr>>* l_data{};
    void gcMark(){
      bbGCMarkPtr(l_data);
    }
  }f0{};
  bbDebugAssert((l_capacity>=bbInt(0)),BB_T("Debug assert failed"));
  if((this->m__0data->length()>=l_capacity)){
    return;
  }
  l_capacity=g_monkey_math_Max_1i(((this->m__0length*2)+this->m__0length),l_capacity);
  f0.l_data=bbArray<bbGCVar<t_mx2_TypeExpr>>::create(l_capacity);
  this->m__0data->copyTo(f0.l_data,bbInt(0),bbInt(0),this->m__0length);
  this->m__0data=f0.l_data;
}

bbBool t_std_collections_Stack_1Tt_mx2_TypeExpr_2::m_RemoveLast(t_mx2_TypeExpr* l_value,bbInt l_start){
  bbInt l_i=this->m_FindLastIndex(l_value,l_start);
  if((l_i==-1)){
    return false;
  }
  this->m_Erase(l_i);
  return true;
}

bbInt t_std_collections_Stack_1Tt_mx2_TypeExpr_2::m_RemoveEach(t_mx2_TypeExpr* l_value){
  bbInt l_put=bbInt(0);
  bbInt l_n=bbInt(0);
  {
    bbInt l_get=bbInt(0);
    for(;(l_get<this->m__0length);l_get+=1){
      if((this->m__0data->at(l_get)==l_value)){
        l_n+=1;
        continue;
      }
      this->m__0data->at(l_put)=this->m__0data->at(l_get);
      l_put+=1;
    }
  }
  this->m_Resize(l_put);
  return l_n;
}

bbBool t_std_collections_Stack_1Tt_mx2_TypeExpr_2::m_Remove(t_mx2_TypeExpr* l_value,bbInt l_start){
  bbInt l_i=this->m_FindIndex(l_value,l_start);
  if((l_i==-1)){
    return false;
  }
  this->m_Erase(l_i);
  return true;
}

void t_std_collections_Stack_1Tt_mx2_TypeExpr_2::m_Push(t_mx2_TypeExpr* l_value){
  this->m_Add(l_value);
}

t_mx2_TypeExpr* t_std_collections_Stack_1Tt_mx2_TypeExpr_2::m_Pop(){
  struct f0_t : public bbGCFrame{
    t_mx2_TypeExpr* l_value{};
    void gcMark(){
      bbGCMarkPtr(l_value);
    }
  }f0{};
  bbDebugAssert(bbBool(this->m__0length),BB_T("Stack is empty"));
  this->m__0length-=1;
  this->m__0seq+=1;
  f0.l_value=this->m__0data->at(this->m__0length);
  this->m__0data->at(this->m__0length)=((t_mx2_TypeExpr*)0);
  return f0.l_value;
}

bbInt t_std_collections_Stack_1Tt_mx2_TypeExpr_2::m_Length(){
  return this->m__0length;
}

void t_std_collections_Stack_1Tt_mx2_TypeExpr_2::m_Insert(bbInt l_index,t_mx2_TypeExpr* l_value){
  bbDebugAssert(((l_index>=bbInt(0))&&(l_index<=this->m__0length)),BB_T("Debug assert failed"));
  this->m_Reserve((this->m__0length+1));
  this->m__0data->copyTo(this->m__0data,l_index,(l_index+1),(this->m__0length-l_index));
  this->m__0data->at(l_index)=l_value;
  this->m__0length+=1;
  this->m__0seq+=1;
}

t_mx2_TypeExpr* t_std_collections_Stack_1Tt_mx2_TypeExpr_2::m_Get(bbInt l_index){
  bbDebugAssert(((l_index>=bbInt(0))&&(l_index<this->m__0length)),BB_T("Stack index out of range"));
  return this->m__0data->at(l_index);
}

bbInt t_std_collections_Stack_1Tt_mx2_TypeExpr_2::m_FindLastIndex(t_mx2_TypeExpr* l_value,bbInt l_start){
  bbDebugAssert(((l_start>=bbInt(0))&&(l_start<=this->m__0length)),BB_T("Debug assert failed"));
  bbInt l_i=this->m__0length;
  while((l_i>l_start)){
    l_i-=1;
    if((this->m__0data->at(l_i)==l_value)){
      return l_i;
    }
  }
  return -1;
}

bbInt t_std_collections_Stack_1Tt_mx2_TypeExpr_2::m_FindIndex(t_mx2_TypeExpr* l_value,bbInt l_start){
  bbDebugAssert(((l_start>=bbInt(0))&&(l_start<=this->m__0length)),BB_T("Debug assert failed"));
  bbInt l_i=l_start;
  while((l_i<this->m__0length)){
    if((this->m__0data->at(l_i)==l_value)){
      return l_i;
    }
    l_i+=1;
  }
  return -1;
}

void t_std_collections_Stack_1Tt_mx2_TypeExpr_2::m_Erase(bbInt l_index1,bbInt l_index2){
  bbDebugAssert((((((l_index1>=bbInt(0))&&(l_index1<=this->m__0length))&&(l_index2>=bbInt(0)))&&(l_index2<=this->m__0length))&&(l_index1<=l_index2)),BB_T("Debug assert failed"));
  if((l_index1==this->m__0length)){
    return;
  }
  this->m__0data->copyTo(this->m__0data,l_index2,l_index1,(this->m__0length-l_index2));
  this->m_Resize(((this->m__0length-l_index2)+l_index1));
}

void t_std_collections_Stack_1Tt_mx2_TypeExpr_2::m_Erase(bbInt l_index){
  bbDebugAssert(((l_index>=bbInt(0))&&(l_index<=this->m__0length)),BB_T("Debug assert failed"));
  if((l_index==this->m__0length)){
    return;
  }
  this->m__0data->copyTo(this->m__0data,(l_index+1),l_index,((this->m__0length-l_index)-1));
  this->m_Resize((this->m__0length-1));
}

bbBool t_std_collections_Stack_1Tt_mx2_TypeExpr_2::m_Empty(){
  return (this->m__0length==bbInt(0));
}

bbArray<bbGCVar<t_mx2_TypeExpr>>* t_std_collections_Stack_1Tt_mx2_TypeExpr_2::m_Data(){
  return this->m__0data;
}

bbBool t_std_collections_Stack_1Tt_mx2_TypeExpr_2::m_Contains(t_mx2_TypeExpr* l_value){
  return (this->m_FindIndex(l_value,bbInt(0))!=-1);
}

void t_std_collections_Stack_1Tt_mx2_TypeExpr_2::m_Clear(){
  this->m_Resize(bbInt(0));
}

bbInt t_std_collections_Stack_1Tt_mx2_TypeExpr_2::m_Capacity(){
  return this->m__0data->length();
}

t_std_collections_Stack_1Tt_mx2_TypeExpr_2_BackwardsIterator t_std_collections_Stack_1Tt_mx2_TypeExpr_2::m_Backwards(){
  return t_std_collections_Stack_1Tt_mx2_TypeExpr_2_BackwardsIterator(this,(this->m__0length-1));
}

t_std_collections_Stack_1Tt_mx2_TypeExpr_2_Iterator t_std_collections_Stack_1Tt_mx2_TypeExpr_2::m_All(){
  return t_std_collections_Stack_1Tt_mx2_TypeExpr_2_Iterator(this,bbInt(0));
}

void t_std_collections_Stack_1Tt_mx2_TypeExpr_2::m_AddAll(bbArray<bbGCVar<t_mx2_TypeExpr>>* l_values){
  this->m_Reserve((this->m__0length+l_values->length()));
  l_values->copyTo(this->m__0data,bbInt(0),this->m__0length,l_values->length());
  this->m_Resize((this->m__0length+l_values->length()));
}

void t_std_collections_Stack_1Tt_mx2_TypeExpr_2::m_Add(t_mx2_TypeExpr* l_value){
  this->m_Reserve((this->m__0length+1));
  this->m__0data->at(this->m__0length)=l_value;
  this->m__0length+=1;
  this->m__0seq+=1;
}

t_std_collections_Stack_1Tt_mx2_CatchExpr_2_Iterator::t_std_collections_Stack_1Tt_mx2_CatchExpr_2_Iterator(t_std_collections_Stack_1Tt_mx2_CatchExpr_2* l_stack,bbInt l_index){
  (*this).m__0stack=l_stack;
  (*this).m__0index=l_index;
  (*this).m__0seq=l_stack->m__0seq;
}

void t_std_collections_Stack_1Tt_mx2_CatchExpr_2_Iterator::m_Insert(t_mx2_CatchExpr* l_value){
  (*this).m_AssertSeq();
  (*this).m__0stack->m_Insert((*this).m__0index,l_value);
  (*this).m__0seq=(*this).m__0stack->m__0seq;
}

void t_std_collections_Stack_1Tt_mx2_CatchExpr_2_Iterator::m_Erase(){
  (*this).m_AssertSeq();
  (*this).m__0stack->m_Erase((*this).m__0index);
  (*this).m__0seq=(*this).m__0stack->m__0seq;
}

void t_std_collections_Stack_1Tt_mx2_CatchExpr_2_Iterator::m_Current(t_mx2_CatchExpr* l_current){
  (*this).m_AssertCurrent();
  (*this).m__0stack->m__0data->at((*this).m__0index)=l_current;
}

t_mx2_CatchExpr* t_std_collections_Stack_1Tt_mx2_CatchExpr_2_Iterator::m_Current(){
  (*this).m_AssertCurrent();
  return (*this).m__0stack->m__0data->at((*this).m__0index);
}

void t_std_collections_Stack_1Tt_mx2_CatchExpr_2_Iterator::m_Bump(){
  (*this).m_AssertCurrent();
  (*this).m__0index+=1;
}

bbBool t_std_collections_Stack_1Tt_mx2_CatchExpr_2_Iterator::m_AtEnd(){
  (*this).m_AssertSeq();
  return ((*this).m__0index==(*this).m__0stack->m__0length);
}

void t_std_collections_Stack_1Tt_mx2_CatchExpr_2_Iterator::m_AssertSeq(){
  bbDebugAssert(((*this).m__0seq==(*this).m__0stack->m__0seq),BB_T("Concurrent list modification"));
}

void t_std_collections_Stack_1Tt_mx2_CatchExpr_2_Iterator::m_AssertCurrent(){
  bbDebugAssert(!(*this).m_AtEnd(),BB_T("Invalid list iterator"));
}

int bbCompare(const t_std_collections_Stack_1Tt_mx2_CatchExpr_2_Iterator&x,const t_std_collections_Stack_1Tt_mx2_CatchExpr_2_Iterator&y){
  if(int t=bbCompare(x.m__0stack,y.m__0stack)) return t;
  if(int t=bbCompare(x.m__0index,y.m__0index)) return t;
  if(int t=bbCompare(x.m__0seq,y.m__0seq)) return t;
  return 0;
}

void bbGCMark(const t_std_collections_Stack_1Tt_mx2_CatchExpr_2_Iterator&t){
  bbGCMark(t.m__0stack);
}

t_std_collections_Stack_1Tt_mx2_CatchExpr_2_BackwardsIterator::t_std_collections_Stack_1Tt_mx2_CatchExpr_2_BackwardsIterator(t_std_collections_Stack_1Tt_mx2_CatchExpr_2* l_stack,bbInt l_index){
  (*this).m__0stack=l_stack;
  (*this).m__0index=l_index;
  (*this).m__0seq=l_stack->m__0seq;
}

void t_std_collections_Stack_1Tt_mx2_CatchExpr_2_BackwardsIterator::m_Insert(t_mx2_CatchExpr* l_value){
  (*this).m_AssertSeq();
  (*this).m__0index+=1;
  (*this).m__0stack->m_Insert((*this).m__0index,l_value);
  (*this).m__0seq=(*this).m__0stack->m__0seq;
}

void t_std_collections_Stack_1Tt_mx2_CatchExpr_2_BackwardsIterator::m_Erase(){
  (*this).m_AssertCurrent();
  (*this).m__0index-=1;
  (*this).m__0stack->m_Erase(((*this).m__0index+1));
  (*this).m__0seq=(*this).m__0stack->m__0seq;
}

void t_std_collections_Stack_1Tt_mx2_CatchExpr_2_BackwardsIterator::m_Current(t_mx2_CatchExpr* l_current){
  (*this).m_AssertCurrent();
  (*this).m__0stack->m__0data->at((*this).m__0index)=l_current;
}

t_mx2_CatchExpr* t_std_collections_Stack_1Tt_mx2_CatchExpr_2_BackwardsIterator::m_Current(){
  (*this).m_AssertCurrent();
  return (*this).m__0stack->m__0data->at((*this).m__0index);
}

void t_std_collections_Stack_1Tt_mx2_CatchExpr_2_BackwardsIterator::m_Bump(){
  (*this).m_AssertCurrent();
  (*this).m__0index-=1;
}

bbBool t_std_collections_Stack_1Tt_mx2_CatchExpr_2_BackwardsIterator::m_AtEnd(){
  (*this).m_AssertSeq();
  return ((*this).m__0index==-1);
}

void t_std_collections_Stack_1Tt_mx2_CatchExpr_2_BackwardsIterator::m_AssertSeq(){
  bbDebugAssert(((*this).m__0seq==(*this).m__0stack->m__0seq),BB_T("Concurrent list modification"));
}

void t_std_collections_Stack_1Tt_mx2_CatchExpr_2_BackwardsIterator::m_AssertCurrent(){
  bbDebugAssert(!(*this).m_AtEnd(),BB_T("Invalid list iterator"));
}

int bbCompare(const t_std_collections_Stack_1Tt_mx2_CatchExpr_2_BackwardsIterator&x,const t_std_collections_Stack_1Tt_mx2_CatchExpr_2_BackwardsIterator&y){
  if(int t=bbCompare(x.m__0stack,y.m__0stack)) return t;
  if(int t=bbCompare(x.m__0index,y.m__0index)) return t;
  if(int t=bbCompare(x.m__0seq,y.m__0seq)) return t;
  return 0;
}

void bbGCMark(const t_std_collections_Stack_1Tt_mx2_CatchExpr_2_BackwardsIterator&t){
  bbGCMark(t.m__0stack);
}

void t_std_collections_Stack_1Tt_mx2_CatchExpr_2::gcMark(){
  bbGCMark(m__0data);
}

t_std_collections_Stack_1Tt_mx2_CatchExpr_2::t_std_collections_Stack_1Tt_mx2_CatchExpr_2(t_std_collections_List_1Tt_mx2_CatchExpr_2* l_values){
  g_std_collections_Stack_1Tt_mx2_CatchExpr_2_AddAll_1Tt_std_collections_List_1Tt_mx2_CatchExpr_2_2(this,l_values);
}

t_std_collections_Stack_1Tt_mx2_CatchExpr_2::t_std_collections_Stack_1Tt_mx2_CatchExpr_2(t_std_collections_Stack_1Tt_mx2_CatchExpr_2* l_values){
  struct f0_t : public bbGCFrame{
    bbArray<bbGCVar<t_mx2_CatchExpr>>* t0{};
    void gcMark(){
      bbGCMarkPtr(t0);
    }
  }f0{};
  this->m__0length=l_values->m_Length();
  this->m__0data=bbArray<bbGCVar<t_mx2_CatchExpr>>::create(this->m__0length);
  (f0.t0=l_values->m_Data())->copyTo(this->m__0data,bbInt(0),bbInt(0),this->m__0length);
}

t_std_collections_Stack_1Tt_mx2_CatchExpr_2::t_std_collections_Stack_1Tt_mx2_CatchExpr_2(bbArray<bbGCVar<t_mx2_CatchExpr>>* l_values){
  this->m_AddAll(l_values);
}

t_std_collections_Stack_1Tt_mx2_CatchExpr_2::t_std_collections_Stack_1Tt_mx2_CatchExpr_2(bbInt l_length){
  this->m__0length=l_length;
  this->m__0data=bbArray<bbGCVar<t_mx2_CatchExpr>>::create(this->m__0length);
}

t_std_collections_Stack_1Tt_mx2_CatchExpr_2::t_std_collections_Stack_1Tt_mx2_CatchExpr_2(){
  this->m__0data=bbArray<bbGCVar<t_mx2_CatchExpr>>::create(10);
}

void t_std_collections_Stack_1Tt_mx2_CatchExpr_2::m__idxeq(bbInt l_index,t_mx2_CatchExpr* l_value){
  bbDebugAssert(((l_index>=bbInt(0))&&(l_index<this->m__0length)),BB_T("Stack index out of range"));
  this->m__0data->at(l_index)=l_value;
}

t_mx2_CatchExpr* t_std_collections_Stack_1Tt_mx2_CatchExpr_2::m__idx(bbInt l_index){
  bbDebugAssert(((l_index>=bbInt(0))&&(l_index<this->m__0length)),BB_T("Stack index out of range"));
  return this->m__0data->at(l_index);
}

t_mx2_CatchExpr* t_std_collections_Stack_1Tt_mx2_CatchExpr_2::m_Top(){
  bbDebugAssert(bbBool(this->m__0length),BB_T("Stack is empty"));
  return this->m__0data->at((this->m__0length-1));
}

bbArray<bbGCVar<t_mx2_CatchExpr>>* t_std_collections_Stack_1Tt_mx2_CatchExpr_2::m_ToArray(){
  return this->m__0data->slice(bbInt(0),this->m__0length);
}

void t_std_collections_Stack_1Tt_mx2_CatchExpr_2::m_Swap(bbInt l_index1,bbInt l_index2){
  struct f0_t : public bbGCFrame{
    t_mx2_CatchExpr* l_t{};
    void gcMark(){
      bbGCMarkPtr(l_t);
    }
  }f0{};
  bbDebugAssert(((((l_index1>=bbInt(0))&&(l_index1<this->m__0length))&&(l_index2>=bbInt(0)))&&(l_index2<this->m__0length)),BB_T("Stack index out of range"));
  f0.l_t=this->m__0data->at(l_index1);
  this->m__0data->at(l_index1)=this->m__0data->at(l_index2);
  this->m__0data->at(l_index2)=f0.l_t;
}

void t_std_collections_Stack_1Tt_mx2_CatchExpr_2::m_Sort(bbFunction<bbInt(t_mx2_CatchExpr*,t_mx2_CatchExpr*)> l_compareFunc,bbInt l_lo,bbInt l_hi){
  if((l_hi<=l_lo)){
    return;
  }
  if(((l_lo+1)==l_hi)){
    if((l_compareFunc(this->m__0data->at(l_hi),this->m__0data->at(l_lo))<bbInt(0))){
      this->m_Swap(l_hi,l_lo);
    }
    return;
  }
  bbInt l_i=((l_lo+l_hi)/2);
  if((l_compareFunc(this->m__0data->at(l_i),this->m__0data->at(l_lo))<bbInt(0))){
    this->m_Swap(l_i,l_lo);
  }
  if((l_compareFunc(this->m__0data->at(l_hi),this->m__0data->at(l_i))<bbInt(0))){
    this->m_Swap(l_hi,l_i);
    if((l_compareFunc(this->m__0data->at(l_i),this->m__0data->at(l_lo))<bbInt(0))){
      this->m_Swap(l_i,l_lo);
    }
  }
  bbInt l_x=(l_lo+1);
  bbInt l_y=(l_hi-1);
  do{
    struct f1_t : public bbGCFrame{
      t_mx2_CatchExpr* l_p{};
      void gcMark(){
        bbGCMarkPtr(l_p);
      }
    }f1{};
    f1.l_p=this->m__0data->at(l_i);
    while((l_compareFunc(this->m__0data->at(l_x),f1.l_p)<bbInt(0))){
      l_x+=1;
    }
    while((l_compareFunc(f1.l_p,this->m__0data->at(l_y))<bbInt(0))){
      l_y-=1;
    }
    if((l_x>l_y)){
      break;
    }
    if((l_x<l_y)){
      this->m_Swap(l_x,l_y);
      if((l_i==l_x)){
        l_i=l_y;
      }else if((l_i==l_y)){
        l_i=l_x;
      }
    }
    l_x+=1;
    l_y-=1;
  }while(!((l_x>l_y)));
  this->m_Sort(l_compareFunc,l_lo,l_y);
  this->m_Sort(l_compareFunc,l_x,l_hi);
}

void t_std_collections_Stack_1Tt_mx2_CatchExpr_2::m_Sort(bbFunction<bbInt(t_mx2_CatchExpr*,t_mx2_CatchExpr*)> l_compareFunc){
  this->m_Sort(l_compareFunc,bbInt(0),(this->m__0length-1));
}

void t_std_collections_Stack_1Tt_mx2_CatchExpr_2::m_Sort(bbBool l_ascending){
  if(l_ascending){
    struct lambda40 : public bbFunction<bbInt(t_mx2_CatchExpr*,t_mx2_CatchExpr*)>::Rep{
      t_std_collections_Stack_1Tt_mx2_CatchExpr_2* l_self;
      lambda40(t_std_collections_Stack_1Tt_mx2_CatchExpr_2* l_self):l_self(l_self){
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
      t_std_collections_Stack_1Tt_mx2_CatchExpr_2* l_self;
      lambda41(t_std_collections_Stack_1Tt_mx2_CatchExpr_2* l_self):l_self(l_self){
      }
      bbInt invoke(t_mx2_CatchExpr* l_x,t_mx2_CatchExpr* l_y){
        return bbCompare(l_y,l_x);
      }
      void gcMark(){
        bbGCMarkPtr(l_self);
      }
    };
    this->m_Sort(bbFunction<bbInt(t_mx2_CatchExpr*,t_mx2_CatchExpr*)>(new lambda41(this)));
  }
}

t_std_collections_Stack_1Tt_mx2_CatchExpr_2* t_std_collections_Stack_1Tt_mx2_CatchExpr_2::m_Slice(bbInt l_index1,bbInt l_index2){
  struct f0_t : public bbGCFrame{
    bbArray<bbGCVar<t_mx2_CatchExpr>>* t0{};
    void gcMark(){
      bbGCMarkPtr(t0);
    }
  }f0{};
  if((l_index1<bbInt(0))){
    l_index1=g_monkey_math_Max_1i((l_index1+this->m__0length),bbInt(0));
  }else if((l_index1>this->m__0length)){
    l_index1=this->m__0length;
  }
  if((l_index2<bbInt(0))){
    l_index2=g_monkey_math_Max_1i((l_index2+this->m__0length),l_index1);
  }else if((l_index2>this->m__0length)){
    l_index2=this->m__0length;
  }else if((l_index2<l_index1)){
    l_index2=l_index1;
  }
  return bbGCNew<t_std_collections_Stack_1Tt_mx2_CatchExpr_2>(f0.t0=this->m__0data->slice(l_index1,l_index2));
}

t_std_collections_Stack_1Tt_mx2_CatchExpr_2* t_std_collections_Stack_1Tt_mx2_CatchExpr_2::m_Slice(bbInt l_index){
  return this->m_Slice(l_index,this->m__0length);
}

void t_std_collections_Stack_1Tt_mx2_CatchExpr_2::m_Set(bbInt l_index,t_mx2_CatchExpr* l_value){
  bbDebugAssert(((l_index>=bbInt(0))&&(l_index<this->m__0length)),BB_T("Stack index out of range"));
  this->m__0data->at(l_index)=l_value;
}

void t_std_collections_Stack_1Tt_mx2_CatchExpr_2::m_Resize(bbInt l_length){
  bbDebugAssert((l_length>=bbInt(0)),BB_T("Debug assert failed"));
  {
    bbInt l_i=l_length;
    for(;(l_i<this->m__0length);l_i+=1){
      this->m__0data->at(l_i)=((t_mx2_CatchExpr*)0);
    }
  }
  this->m_Reserve(l_length);
  this->m__0length=l_length;
  this->m__0seq+=1;
}

void t_std_collections_Stack_1Tt_mx2_CatchExpr_2::m_Reserve(bbInt l_capacity){
  struct f0_t : public bbGCFrame{
    bbArray<bbGCVar<t_mx2_CatchExpr>>* l_data{};
    void gcMark(){
      bbGCMarkPtr(l_data);
    }
  }f0{};
  bbDebugAssert((l_capacity>=bbInt(0)),BB_T("Debug assert failed"));
  if((this->m__0data->length()>=l_capacity)){
    return;
  }
  l_capacity=g_monkey_math_Max_1i(((this->m__0length*2)+this->m__0length),l_capacity);
  f0.l_data=bbArray<bbGCVar<t_mx2_CatchExpr>>::create(l_capacity);
  this->m__0data->copyTo(f0.l_data,bbInt(0),bbInt(0),this->m__0length);
  this->m__0data=f0.l_data;
}

bbBool t_std_collections_Stack_1Tt_mx2_CatchExpr_2::m_RemoveLast(t_mx2_CatchExpr* l_value,bbInt l_start){
  bbInt l_i=this->m_FindLastIndex(l_value,l_start);
  if((l_i==-1)){
    return false;
  }
  this->m_Erase(l_i);
  return true;
}

bbInt t_std_collections_Stack_1Tt_mx2_CatchExpr_2::m_RemoveEach(t_mx2_CatchExpr* l_value){
  bbInt l_put=bbInt(0);
  bbInt l_n=bbInt(0);
  {
    bbInt l_get=bbInt(0);
    for(;(l_get<this->m__0length);l_get+=1){
      if((this->m__0data->at(l_get)==l_value)){
        l_n+=1;
        continue;
      }
      this->m__0data->at(l_put)=this->m__0data->at(l_get);
      l_put+=1;
    }
  }
  this->m_Resize(l_put);
  return l_n;
}

bbBool t_std_collections_Stack_1Tt_mx2_CatchExpr_2::m_Remove(t_mx2_CatchExpr* l_value,bbInt l_start){
  bbInt l_i=this->m_FindIndex(l_value,l_start);
  if((l_i==-1)){
    return false;
  }
  this->m_Erase(l_i);
  return true;
}

void t_std_collections_Stack_1Tt_mx2_CatchExpr_2::m_Push(t_mx2_CatchExpr* l_value){
  this->m_Add(l_value);
}

t_mx2_CatchExpr* t_std_collections_Stack_1Tt_mx2_CatchExpr_2::m_Pop(){
  struct f0_t : public bbGCFrame{
    t_mx2_CatchExpr* l_value{};
    void gcMark(){
      bbGCMarkPtr(l_value);
    }
  }f0{};
  bbDebugAssert(bbBool(this->m__0length),BB_T("Stack is empty"));
  this->m__0length-=1;
  this->m__0seq+=1;
  f0.l_value=this->m__0data->at(this->m__0length);
  this->m__0data->at(this->m__0length)=((t_mx2_CatchExpr*)0);
  return f0.l_value;
}

bbInt t_std_collections_Stack_1Tt_mx2_CatchExpr_2::m_Length(){
  return this->m__0length;
}

void t_std_collections_Stack_1Tt_mx2_CatchExpr_2::m_Insert(bbInt l_index,t_mx2_CatchExpr* l_value){
  bbDebugAssert(((l_index>=bbInt(0))&&(l_index<=this->m__0length)),BB_T("Debug assert failed"));
  this->m_Reserve((this->m__0length+1));
  this->m__0data->copyTo(this->m__0data,l_index,(l_index+1),(this->m__0length-l_index));
  this->m__0data->at(l_index)=l_value;
  this->m__0length+=1;
  this->m__0seq+=1;
}

t_mx2_CatchExpr* t_std_collections_Stack_1Tt_mx2_CatchExpr_2::m_Get(bbInt l_index){
  bbDebugAssert(((l_index>=bbInt(0))&&(l_index<this->m__0length)),BB_T("Stack index out of range"));
  return this->m__0data->at(l_index);
}

bbInt t_std_collections_Stack_1Tt_mx2_CatchExpr_2::m_FindLastIndex(t_mx2_CatchExpr* l_value,bbInt l_start){
  bbDebugAssert(((l_start>=bbInt(0))&&(l_start<=this->m__0length)),BB_T("Debug assert failed"));
  bbInt l_i=this->m__0length;
  while((l_i>l_start)){
    l_i-=1;
    if((this->m__0data->at(l_i)==l_value)){
      return l_i;
    }
  }
  return -1;
}

bbInt t_std_collections_Stack_1Tt_mx2_CatchExpr_2::m_FindIndex(t_mx2_CatchExpr* l_value,bbInt l_start){
  bbDebugAssert(((l_start>=bbInt(0))&&(l_start<=this->m__0length)),BB_T("Debug assert failed"));
  bbInt l_i=l_start;
  while((l_i<this->m__0length)){
    if((this->m__0data->at(l_i)==l_value)){
      return l_i;
    }
    l_i+=1;
  }
  return -1;
}

void t_std_collections_Stack_1Tt_mx2_CatchExpr_2::m_Erase(bbInt l_index1,bbInt l_index2){
  bbDebugAssert((((((l_index1>=bbInt(0))&&(l_index1<=this->m__0length))&&(l_index2>=bbInt(0)))&&(l_index2<=this->m__0length))&&(l_index1<=l_index2)),BB_T("Debug assert failed"));
  if((l_index1==this->m__0length)){
    return;
  }
  this->m__0data->copyTo(this->m__0data,l_index2,l_index1,(this->m__0length-l_index2));
  this->m_Resize(((this->m__0length-l_index2)+l_index1));
}

void t_std_collections_Stack_1Tt_mx2_CatchExpr_2::m_Erase(bbInt l_index){
  bbDebugAssert(((l_index>=bbInt(0))&&(l_index<=this->m__0length)),BB_T("Debug assert failed"));
  if((l_index==this->m__0length)){
    return;
  }
  this->m__0data->copyTo(this->m__0data,(l_index+1),l_index,((this->m__0length-l_index)-1));
  this->m_Resize((this->m__0length-1));
}

bbBool t_std_collections_Stack_1Tt_mx2_CatchExpr_2::m_Empty(){
  return (this->m__0length==bbInt(0));
}

bbArray<bbGCVar<t_mx2_CatchExpr>>* t_std_collections_Stack_1Tt_mx2_CatchExpr_2::m_Data(){
  return this->m__0data;
}

bbBool t_std_collections_Stack_1Tt_mx2_CatchExpr_2::m_Contains(t_mx2_CatchExpr* l_value){
  return (this->m_FindIndex(l_value,bbInt(0))!=-1);
}

void t_std_collections_Stack_1Tt_mx2_CatchExpr_2::m_Clear(){
  this->m_Resize(bbInt(0));
}

bbInt t_std_collections_Stack_1Tt_mx2_CatchExpr_2::m_Capacity(){
  return this->m__0data->length();
}

t_std_collections_Stack_1Tt_mx2_CatchExpr_2_BackwardsIterator t_std_collections_Stack_1Tt_mx2_CatchExpr_2::m_Backwards(){
  return t_std_collections_Stack_1Tt_mx2_CatchExpr_2_BackwardsIterator(this,(this->m__0length-1));
}

t_std_collections_Stack_1Tt_mx2_CatchExpr_2_Iterator t_std_collections_Stack_1Tt_mx2_CatchExpr_2::m_All(){
  return t_std_collections_Stack_1Tt_mx2_CatchExpr_2_Iterator(this,bbInt(0));
}

void t_std_collections_Stack_1Tt_mx2_CatchExpr_2::m_AddAll(bbArray<bbGCVar<t_mx2_CatchExpr>>* l_values){
  this->m_Reserve((this->m__0length+l_values->length()));
  l_values->copyTo(this->m__0data,bbInt(0),this->m__0length,l_values->length());
  this->m_Resize((this->m__0length+l_values->length()));
}

void t_std_collections_Stack_1Tt_mx2_CatchExpr_2::m_Add(t_mx2_CatchExpr* l_value){
  this->m_Reserve((this->m__0length+1));
  this->m__0data->at(this->m__0length)=l_value;
  this->m__0length+=1;
  this->m__0seq+=1;
}

t_std_collections_Stack_1Tt_mx2_StmtExpr_2_Iterator::t_std_collections_Stack_1Tt_mx2_StmtExpr_2_Iterator(t_std_collections_Stack_1Tt_mx2_StmtExpr_2* l_stack,bbInt l_index){
  (*this).m__0stack=l_stack;
  (*this).m__0index=l_index;
  (*this).m__0seq=l_stack->m__0seq;
}

void t_std_collections_Stack_1Tt_mx2_StmtExpr_2_Iterator::m_Insert(t_mx2_StmtExpr* l_value){
  (*this).m_AssertSeq();
  (*this).m__0stack->m_Insert((*this).m__0index,l_value);
  (*this).m__0seq=(*this).m__0stack->m__0seq;
}

void t_std_collections_Stack_1Tt_mx2_StmtExpr_2_Iterator::m_Erase(){
  (*this).m_AssertSeq();
  (*this).m__0stack->m_Erase((*this).m__0index);
  (*this).m__0seq=(*this).m__0stack->m__0seq;
}

void t_std_collections_Stack_1Tt_mx2_StmtExpr_2_Iterator::m_Current(t_mx2_StmtExpr* l_current){
  (*this).m_AssertCurrent();
  (*this).m__0stack->m__0data->at((*this).m__0index)=l_current;
}

t_mx2_StmtExpr* t_std_collections_Stack_1Tt_mx2_StmtExpr_2_Iterator::m_Current(){
  (*this).m_AssertCurrent();
  return (*this).m__0stack->m__0data->at((*this).m__0index);
}

void t_std_collections_Stack_1Tt_mx2_StmtExpr_2_Iterator::m_Bump(){
  (*this).m_AssertCurrent();
  (*this).m__0index+=1;
}

bbBool t_std_collections_Stack_1Tt_mx2_StmtExpr_2_Iterator::m_AtEnd(){
  (*this).m_AssertSeq();
  return ((*this).m__0index==(*this).m__0stack->m__0length);
}

void t_std_collections_Stack_1Tt_mx2_StmtExpr_2_Iterator::m_AssertSeq(){
  bbDebugAssert(((*this).m__0seq==(*this).m__0stack->m__0seq),BB_T("Concurrent list modification"));
}

void t_std_collections_Stack_1Tt_mx2_StmtExpr_2_Iterator::m_AssertCurrent(){
  bbDebugAssert(!(*this).m_AtEnd(),BB_T("Invalid list iterator"));
}

int bbCompare(const t_std_collections_Stack_1Tt_mx2_StmtExpr_2_Iterator&x,const t_std_collections_Stack_1Tt_mx2_StmtExpr_2_Iterator&y){
  if(int t=bbCompare(x.m__0stack,y.m__0stack)) return t;
  if(int t=bbCompare(x.m__0index,y.m__0index)) return t;
  if(int t=bbCompare(x.m__0seq,y.m__0seq)) return t;
  return 0;
}

void bbGCMark(const t_std_collections_Stack_1Tt_mx2_StmtExpr_2_Iterator&t){
  bbGCMark(t.m__0stack);
}

t_std_collections_Stack_1Tt_mx2_StmtExpr_2_BackwardsIterator::t_std_collections_Stack_1Tt_mx2_StmtExpr_2_BackwardsIterator(t_std_collections_Stack_1Tt_mx2_StmtExpr_2* l_stack,bbInt l_index){
  (*this).m__0stack=l_stack;
  (*this).m__0index=l_index;
  (*this).m__0seq=l_stack->m__0seq;
}

void t_std_collections_Stack_1Tt_mx2_StmtExpr_2_BackwardsIterator::m_Insert(t_mx2_StmtExpr* l_value){
  (*this).m_AssertSeq();
  (*this).m__0index+=1;
  (*this).m__0stack->m_Insert((*this).m__0index,l_value);
  (*this).m__0seq=(*this).m__0stack->m__0seq;
}

void t_std_collections_Stack_1Tt_mx2_StmtExpr_2_BackwardsIterator::m_Erase(){
  (*this).m_AssertCurrent();
  (*this).m__0index-=1;
  (*this).m__0stack->m_Erase(((*this).m__0index+1));
  (*this).m__0seq=(*this).m__0stack->m__0seq;
}

void t_std_collections_Stack_1Tt_mx2_StmtExpr_2_BackwardsIterator::m_Current(t_mx2_StmtExpr* l_current){
  (*this).m_AssertCurrent();
  (*this).m__0stack->m__0data->at((*this).m__0index)=l_current;
}

t_mx2_StmtExpr* t_std_collections_Stack_1Tt_mx2_StmtExpr_2_BackwardsIterator::m_Current(){
  (*this).m_AssertCurrent();
  return (*this).m__0stack->m__0data->at((*this).m__0index);
}

void t_std_collections_Stack_1Tt_mx2_StmtExpr_2_BackwardsIterator::m_Bump(){
  (*this).m_AssertCurrent();
  (*this).m__0index-=1;
}

bbBool t_std_collections_Stack_1Tt_mx2_StmtExpr_2_BackwardsIterator::m_AtEnd(){
  (*this).m_AssertSeq();
  return ((*this).m__0index==-1);
}

void t_std_collections_Stack_1Tt_mx2_StmtExpr_2_BackwardsIterator::m_AssertSeq(){
  bbDebugAssert(((*this).m__0seq==(*this).m__0stack->m__0seq),BB_T("Concurrent list modification"));
}

void t_std_collections_Stack_1Tt_mx2_StmtExpr_2_BackwardsIterator::m_AssertCurrent(){
  bbDebugAssert(!(*this).m_AtEnd(),BB_T("Invalid list iterator"));
}

int bbCompare(const t_std_collections_Stack_1Tt_mx2_StmtExpr_2_BackwardsIterator&x,const t_std_collections_Stack_1Tt_mx2_StmtExpr_2_BackwardsIterator&y){
  if(int t=bbCompare(x.m__0stack,y.m__0stack)) return t;
  if(int t=bbCompare(x.m__0index,y.m__0index)) return t;
  if(int t=bbCompare(x.m__0seq,y.m__0seq)) return t;
  return 0;
}

void bbGCMark(const t_std_collections_Stack_1Tt_mx2_StmtExpr_2_BackwardsIterator&t){
  bbGCMark(t.m__0stack);
}

void t_std_collections_Stack_1Tt_mx2_StmtExpr_2::gcMark(){
  bbGCMark(m__0data);
}

t_std_collections_Stack_1Tt_mx2_StmtExpr_2::t_std_collections_Stack_1Tt_mx2_StmtExpr_2(t_std_collections_List_1Tt_mx2_StmtExpr_2* l_values){
  g_std_collections_Stack_1Tt_mx2_StmtExpr_2_AddAll_1Tt_std_collections_List_1Tt_mx2_StmtExpr_2_2(this,l_values);
}

t_std_collections_Stack_1Tt_mx2_StmtExpr_2::t_std_collections_Stack_1Tt_mx2_StmtExpr_2(t_std_collections_Stack_1Tt_mx2_StmtExpr_2* l_values){
  struct f0_t : public bbGCFrame{
    bbArray<bbGCVar<t_mx2_StmtExpr>>* t0{};
    void gcMark(){
      bbGCMarkPtr(t0);
    }
  }f0{};
  this->m__0length=l_values->m_Length();
  this->m__0data=bbArray<bbGCVar<t_mx2_StmtExpr>>::create(this->m__0length);
  (f0.t0=l_values->m_Data())->copyTo(this->m__0data,bbInt(0),bbInt(0),this->m__0length);
}

t_std_collections_Stack_1Tt_mx2_StmtExpr_2::t_std_collections_Stack_1Tt_mx2_StmtExpr_2(bbArray<bbGCVar<t_mx2_StmtExpr>>* l_values){
  this->m_AddAll(l_values);
}

t_std_collections_Stack_1Tt_mx2_StmtExpr_2::t_std_collections_Stack_1Tt_mx2_StmtExpr_2(bbInt l_length){
  this->m__0length=l_length;
  this->m__0data=bbArray<bbGCVar<t_mx2_StmtExpr>>::create(this->m__0length);
}

t_std_collections_Stack_1Tt_mx2_StmtExpr_2::t_std_collections_Stack_1Tt_mx2_StmtExpr_2(){
  this->m__0data=bbArray<bbGCVar<t_mx2_StmtExpr>>::create(10);
}

void t_std_collections_Stack_1Tt_mx2_StmtExpr_2::m__idxeq(bbInt l_index,t_mx2_StmtExpr* l_value){
  bbDebugAssert(((l_index>=bbInt(0))&&(l_index<this->m__0length)),BB_T("Stack index out of range"));
  this->m__0data->at(l_index)=l_value;
}

t_mx2_StmtExpr* t_std_collections_Stack_1Tt_mx2_StmtExpr_2::m__idx(bbInt l_index){
  bbDebugAssert(((l_index>=bbInt(0))&&(l_index<this->m__0length)),BB_T("Stack index out of range"));
  return this->m__0data->at(l_index);
}

t_mx2_StmtExpr* t_std_collections_Stack_1Tt_mx2_StmtExpr_2::m_Top(){
  bbDebugAssert(bbBool(this->m__0length),BB_T("Stack is empty"));
  return this->m__0data->at((this->m__0length-1));
}

bbArray<bbGCVar<t_mx2_StmtExpr>>* t_std_collections_Stack_1Tt_mx2_StmtExpr_2::m_ToArray(){
  return this->m__0data->slice(bbInt(0),this->m__0length);
}

void t_std_collections_Stack_1Tt_mx2_StmtExpr_2::m_Swap(bbInt l_index1,bbInt l_index2){
  struct f0_t : public bbGCFrame{
    t_mx2_StmtExpr* l_t{};
    void gcMark(){
      bbGCMarkPtr(l_t);
    }
  }f0{};
  bbDebugAssert(((((l_index1>=bbInt(0))&&(l_index1<this->m__0length))&&(l_index2>=bbInt(0)))&&(l_index2<this->m__0length)),BB_T("Stack index out of range"));
  f0.l_t=this->m__0data->at(l_index1);
  this->m__0data->at(l_index1)=this->m__0data->at(l_index2);
  this->m__0data->at(l_index2)=f0.l_t;
}

void t_std_collections_Stack_1Tt_mx2_StmtExpr_2::m_Sort(bbFunction<bbInt(t_mx2_StmtExpr*,t_mx2_StmtExpr*)> l_compareFunc,bbInt l_lo,bbInt l_hi){
  if((l_hi<=l_lo)){
    return;
  }
  if(((l_lo+1)==l_hi)){
    if((l_compareFunc(this->m__0data->at(l_hi),this->m__0data->at(l_lo))<bbInt(0))){
      this->m_Swap(l_hi,l_lo);
    }
    return;
  }
  bbInt l_i=((l_lo+l_hi)/2);
  if((l_compareFunc(this->m__0data->at(l_i),this->m__0data->at(l_lo))<bbInt(0))){
    this->m_Swap(l_i,l_lo);
  }
  if((l_compareFunc(this->m__0data->at(l_hi),this->m__0data->at(l_i))<bbInt(0))){
    this->m_Swap(l_hi,l_i);
    if((l_compareFunc(this->m__0data->at(l_i),this->m__0data->at(l_lo))<bbInt(0))){
      this->m_Swap(l_i,l_lo);
    }
  }
  bbInt l_x=(l_lo+1);
  bbInt l_y=(l_hi-1);
  do{
    struct f1_t : public bbGCFrame{
      t_mx2_StmtExpr* l_p{};
      void gcMark(){
        bbGCMarkPtr(l_p);
      }
    }f1{};
    f1.l_p=this->m__0data->at(l_i);
    while((l_compareFunc(this->m__0data->at(l_x),f1.l_p)<bbInt(0))){
      l_x+=1;
    }
    while((l_compareFunc(f1.l_p,this->m__0data->at(l_y))<bbInt(0))){
      l_y-=1;
    }
    if((l_x>l_y)){
      break;
    }
    if((l_x<l_y)){
      this->m_Swap(l_x,l_y);
      if((l_i==l_x)){
        l_i=l_y;
      }else if((l_i==l_y)){
        l_i=l_x;
      }
    }
    l_x+=1;
    l_y-=1;
  }while(!((l_x>l_y)));
  this->m_Sort(l_compareFunc,l_lo,l_y);
  this->m_Sort(l_compareFunc,l_x,l_hi);
}

void t_std_collections_Stack_1Tt_mx2_StmtExpr_2::m_Sort(bbFunction<bbInt(t_mx2_StmtExpr*,t_mx2_StmtExpr*)> l_compareFunc){
  this->m_Sort(l_compareFunc,bbInt(0),(this->m__0length-1));
}

void t_std_collections_Stack_1Tt_mx2_StmtExpr_2::m_Sort(bbBool l_ascending){
  if(l_ascending){
    struct lambda42 : public bbFunction<bbInt(t_mx2_StmtExpr*,t_mx2_StmtExpr*)>::Rep{
      t_std_collections_Stack_1Tt_mx2_StmtExpr_2* l_self;
      lambda42(t_std_collections_Stack_1Tt_mx2_StmtExpr_2* l_self):l_self(l_self){
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
      t_std_collections_Stack_1Tt_mx2_StmtExpr_2* l_self;
      lambda43(t_std_collections_Stack_1Tt_mx2_StmtExpr_2* l_self):l_self(l_self){
      }
      bbInt invoke(t_mx2_StmtExpr* l_x,t_mx2_StmtExpr* l_y){
        return bbCompare(l_y,l_x);
      }
      void gcMark(){
        bbGCMarkPtr(l_self);
      }
    };
    this->m_Sort(bbFunction<bbInt(t_mx2_StmtExpr*,t_mx2_StmtExpr*)>(new lambda43(this)));
  }
}

t_std_collections_Stack_1Tt_mx2_StmtExpr_2* t_std_collections_Stack_1Tt_mx2_StmtExpr_2::m_Slice(bbInt l_index1,bbInt l_index2){
  struct f0_t : public bbGCFrame{
    bbArray<bbGCVar<t_mx2_StmtExpr>>* t0{};
    void gcMark(){
      bbGCMarkPtr(t0);
    }
  }f0{};
  if((l_index1<bbInt(0))){
    l_index1=g_monkey_math_Max_1i((l_index1+this->m__0length),bbInt(0));
  }else if((l_index1>this->m__0length)){
    l_index1=this->m__0length;
  }
  if((l_index2<bbInt(0))){
    l_index2=g_monkey_math_Max_1i((l_index2+this->m__0length),l_index1);
  }else if((l_index2>this->m__0length)){
    l_index2=this->m__0length;
  }else if((l_index2<l_index1)){
    l_index2=l_index1;
  }
  return bbGCNew<t_std_collections_Stack_1Tt_mx2_StmtExpr_2>(f0.t0=this->m__0data->slice(l_index1,l_index2));
}

t_std_collections_Stack_1Tt_mx2_StmtExpr_2* t_std_collections_Stack_1Tt_mx2_StmtExpr_2::m_Slice(bbInt l_index){
  return this->m_Slice(l_index,this->m__0length);
}

void t_std_collections_Stack_1Tt_mx2_StmtExpr_2::m_Set(bbInt l_index,t_mx2_StmtExpr* l_value){
  bbDebugAssert(((l_index>=bbInt(0))&&(l_index<this->m__0length)),BB_T("Stack index out of range"));
  this->m__0data->at(l_index)=l_value;
}

void t_std_collections_Stack_1Tt_mx2_StmtExpr_2::m_Resize(bbInt l_length){
  bbDebugAssert((l_length>=bbInt(0)),BB_T("Debug assert failed"));
  {
    bbInt l_i=l_length;
    for(;(l_i<this->m__0length);l_i+=1){
      this->m__0data->at(l_i)=((t_mx2_StmtExpr*)0);
    }
  }
  this->m_Reserve(l_length);
  this->m__0length=l_length;
  this->m__0seq+=1;
}

void t_std_collections_Stack_1Tt_mx2_StmtExpr_2::m_Reserve(bbInt l_capacity){
  struct f0_t : public bbGCFrame{
    bbArray<bbGCVar<t_mx2_StmtExpr>>* l_data{};
    void gcMark(){
      bbGCMarkPtr(l_data);
    }
  }f0{};
  bbDebugAssert((l_capacity>=bbInt(0)),BB_T("Debug assert failed"));
  if((this->m__0data->length()>=l_capacity)){
    return;
  }
  l_capacity=g_monkey_math_Max_1i(((this->m__0length*2)+this->m__0length),l_capacity);
  f0.l_data=bbArray<bbGCVar<t_mx2_StmtExpr>>::create(l_capacity);
  this->m__0data->copyTo(f0.l_data,bbInt(0),bbInt(0),this->m__0length);
  this->m__0data=f0.l_data;
}

bbBool t_std_collections_Stack_1Tt_mx2_StmtExpr_2::m_RemoveLast(t_mx2_StmtExpr* l_value,bbInt l_start){
  bbInt l_i=this->m_FindLastIndex(l_value,l_start);
  if((l_i==-1)){
    return false;
  }
  this->m_Erase(l_i);
  return true;
}

bbInt t_std_collections_Stack_1Tt_mx2_StmtExpr_2::m_RemoveEach(t_mx2_StmtExpr* l_value){
  bbInt l_put=bbInt(0);
  bbInt l_n=bbInt(0);
  {
    bbInt l_get=bbInt(0);
    for(;(l_get<this->m__0length);l_get+=1){
      if((this->m__0data->at(l_get)==l_value)){
        l_n+=1;
        continue;
      }
      this->m__0data->at(l_put)=this->m__0data->at(l_get);
      l_put+=1;
    }
  }
  this->m_Resize(l_put);
  return l_n;
}

bbBool t_std_collections_Stack_1Tt_mx2_StmtExpr_2::m_Remove(t_mx2_StmtExpr* l_value,bbInt l_start){
  bbInt l_i=this->m_FindIndex(l_value,l_start);
  if((l_i==-1)){
    return false;
  }
  this->m_Erase(l_i);
  return true;
}

void t_std_collections_Stack_1Tt_mx2_StmtExpr_2::m_Push(t_mx2_StmtExpr* l_value){
  this->m_Add(l_value);
}

t_mx2_StmtExpr* t_std_collections_Stack_1Tt_mx2_StmtExpr_2::m_Pop(){
  struct f0_t : public bbGCFrame{
    t_mx2_StmtExpr* l_value{};
    void gcMark(){
      bbGCMarkPtr(l_value);
    }
  }f0{};
  bbDebugAssert(bbBool(this->m__0length),BB_T("Stack is empty"));
  this->m__0length-=1;
  this->m__0seq+=1;
  f0.l_value=this->m__0data->at(this->m__0length);
  this->m__0data->at(this->m__0length)=((t_mx2_StmtExpr*)0);
  return f0.l_value;
}

bbInt t_std_collections_Stack_1Tt_mx2_StmtExpr_2::m_Length(){
  return this->m__0length;
}

void t_std_collections_Stack_1Tt_mx2_StmtExpr_2::m_Insert(bbInt l_index,t_mx2_StmtExpr* l_value){
  bbDebugAssert(((l_index>=bbInt(0))&&(l_index<=this->m__0length)),BB_T("Debug assert failed"));
  this->m_Reserve((this->m__0length+1));
  this->m__0data->copyTo(this->m__0data,l_index,(l_index+1),(this->m__0length-l_index));
  this->m__0data->at(l_index)=l_value;
  this->m__0length+=1;
  this->m__0seq+=1;
}

t_mx2_StmtExpr* t_std_collections_Stack_1Tt_mx2_StmtExpr_2::m_Get(bbInt l_index){
  bbDebugAssert(((l_index>=bbInt(0))&&(l_index<this->m__0length)),BB_T("Stack index out of range"));
  return this->m__0data->at(l_index);
}

bbInt t_std_collections_Stack_1Tt_mx2_StmtExpr_2::m_FindLastIndex(t_mx2_StmtExpr* l_value,bbInt l_start){
  bbDebugAssert(((l_start>=bbInt(0))&&(l_start<=this->m__0length)),BB_T("Debug assert failed"));
  bbInt l_i=this->m__0length;
  while((l_i>l_start)){
    l_i-=1;
    if((this->m__0data->at(l_i)==l_value)){
      return l_i;
    }
  }
  return -1;
}

bbInt t_std_collections_Stack_1Tt_mx2_StmtExpr_2::m_FindIndex(t_mx2_StmtExpr* l_value,bbInt l_start){
  bbDebugAssert(((l_start>=bbInt(0))&&(l_start<=this->m__0length)),BB_T("Debug assert failed"));
  bbInt l_i=l_start;
  while((l_i<this->m__0length)){
    if((this->m__0data->at(l_i)==l_value)){
      return l_i;
    }
    l_i+=1;
  }
  return -1;
}

void t_std_collections_Stack_1Tt_mx2_StmtExpr_2::m_Erase(bbInt l_index1,bbInt l_index2){
  bbDebugAssert((((((l_index1>=bbInt(0))&&(l_index1<=this->m__0length))&&(l_index2>=bbInt(0)))&&(l_index2<=this->m__0length))&&(l_index1<=l_index2)),BB_T("Debug assert failed"));
  if((l_index1==this->m__0length)){
    return;
  }
  this->m__0data->copyTo(this->m__0data,l_index2,l_index1,(this->m__0length-l_index2));
  this->m_Resize(((this->m__0length-l_index2)+l_index1));
}

void t_std_collections_Stack_1Tt_mx2_StmtExpr_2::m_Erase(bbInt l_index){
  bbDebugAssert(((l_index>=bbInt(0))&&(l_index<=this->m__0length)),BB_T("Debug assert failed"));
  if((l_index==this->m__0length)){
    return;
  }
  this->m__0data->copyTo(this->m__0data,(l_index+1),l_index,((this->m__0length-l_index)-1));
  this->m_Resize((this->m__0length-1));
}

bbBool t_std_collections_Stack_1Tt_mx2_StmtExpr_2::m_Empty(){
  return (this->m__0length==bbInt(0));
}

bbArray<bbGCVar<t_mx2_StmtExpr>>* t_std_collections_Stack_1Tt_mx2_StmtExpr_2::m_Data(){
  return this->m__0data;
}

bbBool t_std_collections_Stack_1Tt_mx2_StmtExpr_2::m_Contains(t_mx2_StmtExpr* l_value){
  return (this->m_FindIndex(l_value,bbInt(0))!=-1);
}

void t_std_collections_Stack_1Tt_mx2_StmtExpr_2::m_Clear(){
  this->m_Resize(bbInt(0));
}

bbInt t_std_collections_Stack_1Tt_mx2_StmtExpr_2::m_Capacity(){
  return this->m__0data->length();
}

t_std_collections_Stack_1Tt_mx2_StmtExpr_2_BackwardsIterator t_std_collections_Stack_1Tt_mx2_StmtExpr_2::m_Backwards(){
  return t_std_collections_Stack_1Tt_mx2_StmtExpr_2_BackwardsIterator(this,(this->m__0length-1));
}

t_std_collections_Stack_1Tt_mx2_StmtExpr_2_Iterator t_std_collections_Stack_1Tt_mx2_StmtExpr_2::m_All(){
  return t_std_collections_Stack_1Tt_mx2_StmtExpr_2_Iterator(this,bbInt(0));
}

void t_std_collections_Stack_1Tt_mx2_StmtExpr_2::m_AddAll(bbArray<bbGCVar<t_mx2_StmtExpr>>* l_values){
  this->m_Reserve((this->m__0length+l_values->length()));
  l_values->copyTo(this->m__0data,bbInt(0),this->m__0length,l_values->length());
  this->m_Resize((this->m__0length+l_values->length()));
}

void t_std_collections_Stack_1Tt_mx2_StmtExpr_2::m_Add(t_mx2_StmtExpr* l_value){
  this->m_Reserve((this->m__0length+1));
  this->m__0data->at(this->m__0length)=l_value;
  this->m__0length+=1;
  this->m__0seq+=1;
}

t_std_collections_Stack_1Tt_mx2_CaseExpr_2_Iterator::t_std_collections_Stack_1Tt_mx2_CaseExpr_2_Iterator(t_std_collections_Stack_1Tt_mx2_CaseExpr_2* l_stack,bbInt l_index){
  (*this).m__0stack=l_stack;
  (*this).m__0index=l_index;
  (*this).m__0seq=l_stack->m__0seq;
}

void t_std_collections_Stack_1Tt_mx2_CaseExpr_2_Iterator::m_Insert(t_mx2_CaseExpr* l_value){
  (*this).m_AssertSeq();
  (*this).m__0stack->m_Insert((*this).m__0index,l_value);
  (*this).m__0seq=(*this).m__0stack->m__0seq;
}

void t_std_collections_Stack_1Tt_mx2_CaseExpr_2_Iterator::m_Erase(){
  (*this).m_AssertSeq();
  (*this).m__0stack->m_Erase((*this).m__0index);
  (*this).m__0seq=(*this).m__0stack->m__0seq;
}

void t_std_collections_Stack_1Tt_mx2_CaseExpr_2_Iterator::m_Current(t_mx2_CaseExpr* l_current){
  (*this).m_AssertCurrent();
  (*this).m__0stack->m__0data->at((*this).m__0index)=l_current;
}

t_mx2_CaseExpr* t_std_collections_Stack_1Tt_mx2_CaseExpr_2_Iterator::m_Current(){
  (*this).m_AssertCurrent();
  return (*this).m__0stack->m__0data->at((*this).m__0index);
}

void t_std_collections_Stack_1Tt_mx2_CaseExpr_2_Iterator::m_Bump(){
  (*this).m_AssertCurrent();
  (*this).m__0index+=1;
}

bbBool t_std_collections_Stack_1Tt_mx2_CaseExpr_2_Iterator::m_AtEnd(){
  (*this).m_AssertSeq();
  return ((*this).m__0index==(*this).m__0stack->m__0length);
}

void t_std_collections_Stack_1Tt_mx2_CaseExpr_2_Iterator::m_AssertSeq(){
  bbDebugAssert(((*this).m__0seq==(*this).m__0stack->m__0seq),BB_T("Concurrent list modification"));
}

void t_std_collections_Stack_1Tt_mx2_CaseExpr_2_Iterator::m_AssertCurrent(){
  bbDebugAssert(!(*this).m_AtEnd(),BB_T("Invalid list iterator"));
}

int bbCompare(const t_std_collections_Stack_1Tt_mx2_CaseExpr_2_Iterator&x,const t_std_collections_Stack_1Tt_mx2_CaseExpr_2_Iterator&y){
  if(int t=bbCompare(x.m__0stack,y.m__0stack)) return t;
  if(int t=bbCompare(x.m__0index,y.m__0index)) return t;
  if(int t=bbCompare(x.m__0seq,y.m__0seq)) return t;
  return 0;
}

void bbGCMark(const t_std_collections_Stack_1Tt_mx2_CaseExpr_2_Iterator&t){
  bbGCMark(t.m__0stack);
}

t_std_collections_Stack_1Tt_mx2_CaseExpr_2_BackwardsIterator::t_std_collections_Stack_1Tt_mx2_CaseExpr_2_BackwardsIterator(t_std_collections_Stack_1Tt_mx2_CaseExpr_2* l_stack,bbInt l_index){
  (*this).m__0stack=l_stack;
  (*this).m__0index=l_index;
  (*this).m__0seq=l_stack->m__0seq;
}

void t_std_collections_Stack_1Tt_mx2_CaseExpr_2_BackwardsIterator::m_Insert(t_mx2_CaseExpr* l_value){
  (*this).m_AssertSeq();
  (*this).m__0index+=1;
  (*this).m__0stack->m_Insert((*this).m__0index,l_value);
  (*this).m__0seq=(*this).m__0stack->m__0seq;
}

void t_std_collections_Stack_1Tt_mx2_CaseExpr_2_BackwardsIterator::m_Erase(){
  (*this).m_AssertCurrent();
  (*this).m__0index-=1;
  (*this).m__0stack->m_Erase(((*this).m__0index+1));
  (*this).m__0seq=(*this).m__0stack->m__0seq;
}

void t_std_collections_Stack_1Tt_mx2_CaseExpr_2_BackwardsIterator::m_Current(t_mx2_CaseExpr* l_current){
  (*this).m_AssertCurrent();
  (*this).m__0stack->m__0data->at((*this).m__0index)=l_current;
}

t_mx2_CaseExpr* t_std_collections_Stack_1Tt_mx2_CaseExpr_2_BackwardsIterator::m_Current(){
  (*this).m_AssertCurrent();
  return (*this).m__0stack->m__0data->at((*this).m__0index);
}

void t_std_collections_Stack_1Tt_mx2_CaseExpr_2_BackwardsIterator::m_Bump(){
  (*this).m_AssertCurrent();
  (*this).m__0index-=1;
}

bbBool t_std_collections_Stack_1Tt_mx2_CaseExpr_2_BackwardsIterator::m_AtEnd(){
  (*this).m_AssertSeq();
  return ((*this).m__0index==-1);
}

void t_std_collections_Stack_1Tt_mx2_CaseExpr_2_BackwardsIterator::m_AssertSeq(){
  bbDebugAssert(((*this).m__0seq==(*this).m__0stack->m__0seq),BB_T("Concurrent list modification"));
}

void t_std_collections_Stack_1Tt_mx2_CaseExpr_2_BackwardsIterator::m_AssertCurrent(){
  bbDebugAssert(!(*this).m_AtEnd(),BB_T("Invalid list iterator"));
}

int bbCompare(const t_std_collections_Stack_1Tt_mx2_CaseExpr_2_BackwardsIterator&x,const t_std_collections_Stack_1Tt_mx2_CaseExpr_2_BackwardsIterator&y){
  if(int t=bbCompare(x.m__0stack,y.m__0stack)) return t;
  if(int t=bbCompare(x.m__0index,y.m__0index)) return t;
  if(int t=bbCompare(x.m__0seq,y.m__0seq)) return t;
  return 0;
}

void bbGCMark(const t_std_collections_Stack_1Tt_mx2_CaseExpr_2_BackwardsIterator&t){
  bbGCMark(t.m__0stack);
}

void t_std_collections_Stack_1Tt_mx2_CaseExpr_2::gcMark(){
  bbGCMark(m__0data);
}

t_std_collections_Stack_1Tt_mx2_CaseExpr_2::t_std_collections_Stack_1Tt_mx2_CaseExpr_2(t_std_collections_List_1Tt_mx2_CaseExpr_2* l_values){
  g_std_collections_Stack_1Tt_mx2_CaseExpr_2_AddAll_1Tt_std_collections_List_1Tt_mx2_CaseExpr_2_2(this,l_values);
}

t_std_collections_Stack_1Tt_mx2_CaseExpr_2::t_std_collections_Stack_1Tt_mx2_CaseExpr_2(t_std_collections_Stack_1Tt_mx2_CaseExpr_2* l_values){
  struct f0_t : public bbGCFrame{
    bbArray<bbGCVar<t_mx2_CaseExpr>>* t0{};
    void gcMark(){
      bbGCMarkPtr(t0);
    }
  }f0{};
  this->m__0length=l_values->m_Length();
  this->m__0data=bbArray<bbGCVar<t_mx2_CaseExpr>>::create(this->m__0length);
  (f0.t0=l_values->m_Data())->copyTo(this->m__0data,bbInt(0),bbInt(0),this->m__0length);
}

t_std_collections_Stack_1Tt_mx2_CaseExpr_2::t_std_collections_Stack_1Tt_mx2_CaseExpr_2(bbArray<bbGCVar<t_mx2_CaseExpr>>* l_values){
  this->m_AddAll(l_values);
}

t_std_collections_Stack_1Tt_mx2_CaseExpr_2::t_std_collections_Stack_1Tt_mx2_CaseExpr_2(bbInt l_length){
  this->m__0length=l_length;
  this->m__0data=bbArray<bbGCVar<t_mx2_CaseExpr>>::create(this->m__0length);
}

t_std_collections_Stack_1Tt_mx2_CaseExpr_2::t_std_collections_Stack_1Tt_mx2_CaseExpr_2(){
  this->m__0data=bbArray<bbGCVar<t_mx2_CaseExpr>>::create(10);
}

void t_std_collections_Stack_1Tt_mx2_CaseExpr_2::m__idxeq(bbInt l_index,t_mx2_CaseExpr* l_value){
  bbDebugAssert(((l_index>=bbInt(0))&&(l_index<this->m__0length)),BB_T("Stack index out of range"));
  this->m__0data->at(l_index)=l_value;
}

t_mx2_CaseExpr* t_std_collections_Stack_1Tt_mx2_CaseExpr_2::m__idx(bbInt l_index){
  bbDebugAssert(((l_index>=bbInt(0))&&(l_index<this->m__0length)),BB_T("Stack index out of range"));
  return this->m__0data->at(l_index);
}

t_mx2_CaseExpr* t_std_collections_Stack_1Tt_mx2_CaseExpr_2::m_Top(){
  bbDebugAssert(bbBool(this->m__0length),BB_T("Stack is empty"));
  return this->m__0data->at((this->m__0length-1));
}

bbArray<bbGCVar<t_mx2_CaseExpr>>* t_std_collections_Stack_1Tt_mx2_CaseExpr_2::m_ToArray(){
  return this->m__0data->slice(bbInt(0),this->m__0length);
}

void t_std_collections_Stack_1Tt_mx2_CaseExpr_2::m_Swap(bbInt l_index1,bbInt l_index2){
  struct f0_t : public bbGCFrame{
    t_mx2_CaseExpr* l_t{};
    void gcMark(){
      bbGCMarkPtr(l_t);
    }
  }f0{};
  bbDebugAssert(((((l_index1>=bbInt(0))&&(l_index1<this->m__0length))&&(l_index2>=bbInt(0)))&&(l_index2<this->m__0length)),BB_T("Stack index out of range"));
  f0.l_t=this->m__0data->at(l_index1);
  this->m__0data->at(l_index1)=this->m__0data->at(l_index2);
  this->m__0data->at(l_index2)=f0.l_t;
}

void t_std_collections_Stack_1Tt_mx2_CaseExpr_2::m_Sort(bbFunction<bbInt(t_mx2_CaseExpr*,t_mx2_CaseExpr*)> l_compareFunc,bbInt l_lo,bbInt l_hi){
  if((l_hi<=l_lo)){
    return;
  }
  if(((l_lo+1)==l_hi)){
    if((l_compareFunc(this->m__0data->at(l_hi),this->m__0data->at(l_lo))<bbInt(0))){
      this->m_Swap(l_hi,l_lo);
    }
    return;
  }
  bbInt l_i=((l_lo+l_hi)/2);
  if((l_compareFunc(this->m__0data->at(l_i),this->m__0data->at(l_lo))<bbInt(0))){
    this->m_Swap(l_i,l_lo);
  }
  if((l_compareFunc(this->m__0data->at(l_hi),this->m__0data->at(l_i))<bbInt(0))){
    this->m_Swap(l_hi,l_i);
    if((l_compareFunc(this->m__0data->at(l_i),this->m__0data->at(l_lo))<bbInt(0))){
      this->m_Swap(l_i,l_lo);
    }
  }
  bbInt l_x=(l_lo+1);
  bbInt l_y=(l_hi-1);
  do{
    struct f1_t : public bbGCFrame{
      t_mx2_CaseExpr* l_p{};
      void gcMark(){
        bbGCMarkPtr(l_p);
      }
    }f1{};
    f1.l_p=this->m__0data->at(l_i);
    while((l_compareFunc(this->m__0data->at(l_x),f1.l_p)<bbInt(0))){
      l_x+=1;
    }
    while((l_compareFunc(f1.l_p,this->m__0data->at(l_y))<bbInt(0))){
      l_y-=1;
    }
    if((l_x>l_y)){
      break;
    }
    if((l_x<l_y)){
      this->m_Swap(l_x,l_y);
      if((l_i==l_x)){
        l_i=l_y;
      }else if((l_i==l_y)){
        l_i=l_x;
      }
    }
    l_x+=1;
    l_y-=1;
  }while(!((l_x>l_y)));
  this->m_Sort(l_compareFunc,l_lo,l_y);
  this->m_Sort(l_compareFunc,l_x,l_hi);
}

void t_std_collections_Stack_1Tt_mx2_CaseExpr_2::m_Sort(bbFunction<bbInt(t_mx2_CaseExpr*,t_mx2_CaseExpr*)> l_compareFunc){
  this->m_Sort(l_compareFunc,bbInt(0),(this->m__0length-1));
}

void t_std_collections_Stack_1Tt_mx2_CaseExpr_2::m_Sort(bbBool l_ascending){
  if(l_ascending){
    struct lambda44 : public bbFunction<bbInt(t_mx2_CaseExpr*,t_mx2_CaseExpr*)>::Rep{
      t_std_collections_Stack_1Tt_mx2_CaseExpr_2* l_self;
      lambda44(t_std_collections_Stack_1Tt_mx2_CaseExpr_2* l_self):l_self(l_self){
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
      t_std_collections_Stack_1Tt_mx2_CaseExpr_2* l_self;
      lambda45(t_std_collections_Stack_1Tt_mx2_CaseExpr_2* l_self):l_self(l_self){
      }
      bbInt invoke(t_mx2_CaseExpr* l_x,t_mx2_CaseExpr* l_y){
        return bbCompare(l_y,l_x);
      }
      void gcMark(){
        bbGCMarkPtr(l_self);
      }
    };
    this->m_Sort(bbFunction<bbInt(t_mx2_CaseExpr*,t_mx2_CaseExpr*)>(new lambda45(this)));
  }
}

t_std_collections_Stack_1Tt_mx2_CaseExpr_2* t_std_collections_Stack_1Tt_mx2_CaseExpr_2::m_Slice(bbInt l_index1,bbInt l_index2){
  struct f0_t : public bbGCFrame{
    bbArray<bbGCVar<t_mx2_CaseExpr>>* t0{};
    void gcMark(){
      bbGCMarkPtr(t0);
    }
  }f0{};
  if((l_index1<bbInt(0))){
    l_index1=g_monkey_math_Max_1i((l_index1+this->m__0length),bbInt(0));
  }else if((l_index1>this->m__0length)){
    l_index1=this->m__0length;
  }
  if((l_index2<bbInt(0))){
    l_index2=g_monkey_math_Max_1i((l_index2+this->m__0length),l_index1);
  }else if((l_index2>this->m__0length)){
    l_index2=this->m__0length;
  }else if((l_index2<l_index1)){
    l_index2=l_index1;
  }
  return bbGCNew<t_std_collections_Stack_1Tt_mx2_CaseExpr_2>(f0.t0=this->m__0data->slice(l_index1,l_index2));
}

t_std_collections_Stack_1Tt_mx2_CaseExpr_2* t_std_collections_Stack_1Tt_mx2_CaseExpr_2::m_Slice(bbInt l_index){
  return this->m_Slice(l_index,this->m__0length);
}

void t_std_collections_Stack_1Tt_mx2_CaseExpr_2::m_Set(bbInt l_index,t_mx2_CaseExpr* l_value){
  bbDebugAssert(((l_index>=bbInt(0))&&(l_index<this->m__0length)),BB_T("Stack index out of range"));
  this->m__0data->at(l_index)=l_value;
}

void t_std_collections_Stack_1Tt_mx2_CaseExpr_2::m_Resize(bbInt l_length){
  bbDebugAssert((l_length>=bbInt(0)),BB_T("Debug assert failed"));
  {
    bbInt l_i=l_length;
    for(;(l_i<this->m__0length);l_i+=1){
      this->m__0data->at(l_i)=((t_mx2_CaseExpr*)0);
    }
  }
  this->m_Reserve(l_length);
  this->m__0length=l_length;
  this->m__0seq+=1;
}

void t_std_collections_Stack_1Tt_mx2_CaseExpr_2::m_Reserve(bbInt l_capacity){
  struct f0_t : public bbGCFrame{
    bbArray<bbGCVar<t_mx2_CaseExpr>>* l_data{};
    void gcMark(){
      bbGCMarkPtr(l_data);
    }
  }f0{};
  bbDebugAssert((l_capacity>=bbInt(0)),BB_T("Debug assert failed"));
  if((this->m__0data->length()>=l_capacity)){
    return;
  }
  l_capacity=g_monkey_math_Max_1i(((this->m__0length*2)+this->m__0length),l_capacity);
  f0.l_data=bbArray<bbGCVar<t_mx2_CaseExpr>>::create(l_capacity);
  this->m__0data->copyTo(f0.l_data,bbInt(0),bbInt(0),this->m__0length);
  this->m__0data=f0.l_data;
}

bbBool t_std_collections_Stack_1Tt_mx2_CaseExpr_2::m_RemoveLast(t_mx2_CaseExpr* l_value,bbInt l_start){
  bbInt l_i=this->m_FindLastIndex(l_value,l_start);
  if((l_i==-1)){
    return false;
  }
  this->m_Erase(l_i);
  return true;
}

bbInt t_std_collections_Stack_1Tt_mx2_CaseExpr_2::m_RemoveEach(t_mx2_CaseExpr* l_value){
  bbInt l_put=bbInt(0);
  bbInt l_n=bbInt(0);
  {
    bbInt l_get=bbInt(0);
    for(;(l_get<this->m__0length);l_get+=1){
      if((this->m__0data->at(l_get)==l_value)){
        l_n+=1;
        continue;
      }
      this->m__0data->at(l_put)=this->m__0data->at(l_get);
      l_put+=1;
    }
  }
  this->m_Resize(l_put);
  return l_n;
}

bbBool t_std_collections_Stack_1Tt_mx2_CaseExpr_2::m_Remove(t_mx2_CaseExpr* l_value,bbInt l_start){
  bbInt l_i=this->m_FindIndex(l_value,l_start);
  if((l_i==-1)){
    return false;
  }
  this->m_Erase(l_i);
  return true;
}

void t_std_collections_Stack_1Tt_mx2_CaseExpr_2::m_Push(t_mx2_CaseExpr* l_value){
  this->m_Add(l_value);
}

t_mx2_CaseExpr* t_std_collections_Stack_1Tt_mx2_CaseExpr_2::m_Pop(){
  struct f0_t : public bbGCFrame{
    t_mx2_CaseExpr* l_value{};
    void gcMark(){
      bbGCMarkPtr(l_value);
    }
  }f0{};
  bbDebugAssert(bbBool(this->m__0length),BB_T("Stack is empty"));
  this->m__0length-=1;
  this->m__0seq+=1;
  f0.l_value=this->m__0data->at(this->m__0length);
  this->m__0data->at(this->m__0length)=((t_mx2_CaseExpr*)0);
  return f0.l_value;
}

bbInt t_std_collections_Stack_1Tt_mx2_CaseExpr_2::m_Length(){
  return this->m__0length;
}

void t_std_collections_Stack_1Tt_mx2_CaseExpr_2::m_Insert(bbInt l_index,t_mx2_CaseExpr* l_value){
  bbDebugAssert(((l_index>=bbInt(0))&&(l_index<=this->m__0length)),BB_T("Debug assert failed"));
  this->m_Reserve((this->m__0length+1));
  this->m__0data->copyTo(this->m__0data,l_index,(l_index+1),(this->m__0length-l_index));
  this->m__0data->at(l_index)=l_value;
  this->m__0length+=1;
  this->m__0seq+=1;
}

t_mx2_CaseExpr* t_std_collections_Stack_1Tt_mx2_CaseExpr_2::m_Get(bbInt l_index){
  bbDebugAssert(((l_index>=bbInt(0))&&(l_index<this->m__0length)),BB_T("Stack index out of range"));
  return this->m__0data->at(l_index);
}

bbInt t_std_collections_Stack_1Tt_mx2_CaseExpr_2::m_FindLastIndex(t_mx2_CaseExpr* l_value,bbInt l_start){
  bbDebugAssert(((l_start>=bbInt(0))&&(l_start<=this->m__0length)),BB_T("Debug assert failed"));
  bbInt l_i=this->m__0length;
  while((l_i>l_start)){
    l_i-=1;
    if((this->m__0data->at(l_i)==l_value)){
      return l_i;
    }
  }
  return -1;
}

bbInt t_std_collections_Stack_1Tt_mx2_CaseExpr_2::m_FindIndex(t_mx2_CaseExpr* l_value,bbInt l_start){
  bbDebugAssert(((l_start>=bbInt(0))&&(l_start<=this->m__0length)),BB_T("Debug assert failed"));
  bbInt l_i=l_start;
  while((l_i<this->m__0length)){
    if((this->m__0data->at(l_i)==l_value)){
      return l_i;
    }
    l_i+=1;
  }
  return -1;
}

void t_std_collections_Stack_1Tt_mx2_CaseExpr_2::m_Erase(bbInt l_index1,bbInt l_index2){
  bbDebugAssert((((((l_index1>=bbInt(0))&&(l_index1<=this->m__0length))&&(l_index2>=bbInt(0)))&&(l_index2<=this->m__0length))&&(l_index1<=l_index2)),BB_T("Debug assert failed"));
  if((l_index1==this->m__0length)){
    return;
  }
  this->m__0data->copyTo(this->m__0data,l_index2,l_index1,(this->m__0length-l_index2));
  this->m_Resize(((this->m__0length-l_index2)+l_index1));
}

void t_std_collections_Stack_1Tt_mx2_CaseExpr_2::m_Erase(bbInt l_index){
  bbDebugAssert(((l_index>=bbInt(0))&&(l_index<=this->m__0length)),BB_T("Debug assert failed"));
  if((l_index==this->m__0length)){
    return;
  }
  this->m__0data->copyTo(this->m__0data,(l_index+1),l_index,((this->m__0length-l_index)-1));
  this->m_Resize((this->m__0length-1));
}

bbBool t_std_collections_Stack_1Tt_mx2_CaseExpr_2::m_Empty(){
  return (this->m__0length==bbInt(0));
}

bbArray<bbGCVar<t_mx2_CaseExpr>>* t_std_collections_Stack_1Tt_mx2_CaseExpr_2::m_Data(){
  return this->m__0data;
}

bbBool t_std_collections_Stack_1Tt_mx2_CaseExpr_2::m_Contains(t_mx2_CaseExpr* l_value){
  return (this->m_FindIndex(l_value,bbInt(0))!=-1);
}

void t_std_collections_Stack_1Tt_mx2_CaseExpr_2::m_Clear(){
  this->m_Resize(bbInt(0));
}

bbInt t_std_collections_Stack_1Tt_mx2_CaseExpr_2::m_Capacity(){
  return this->m__0data->length();
}

t_std_collections_Stack_1Tt_mx2_CaseExpr_2_BackwardsIterator t_std_collections_Stack_1Tt_mx2_CaseExpr_2::m_Backwards(){
  return t_std_collections_Stack_1Tt_mx2_CaseExpr_2_BackwardsIterator(this,(this->m__0length-1));
}

t_std_collections_Stack_1Tt_mx2_CaseExpr_2_Iterator t_std_collections_Stack_1Tt_mx2_CaseExpr_2::m_All(){
  return t_std_collections_Stack_1Tt_mx2_CaseExpr_2_Iterator(this,bbInt(0));
}

void t_std_collections_Stack_1Tt_mx2_CaseExpr_2::m_AddAll(bbArray<bbGCVar<t_mx2_CaseExpr>>* l_values){
  this->m_Reserve((this->m__0length+l_values->length()));
  l_values->copyTo(this->m__0data,bbInt(0),this->m__0length,l_values->length());
  this->m_Resize((this->m__0length+l_values->length()));
}

void t_std_collections_Stack_1Tt_mx2_CaseExpr_2::m_Add(t_mx2_CaseExpr* l_value){
  this->m_Reserve((this->m__0length+1));
  this->m__0data->at(this->m__0length)=l_value;
  this->m__0length+=1;
  this->m__0seq+=1;
}

t_std_collections_Stack_1Tt_mx2_Expr_2_Iterator::t_std_collections_Stack_1Tt_mx2_Expr_2_Iterator(t_std_collections_Stack_1Tt_mx2_Expr_2* l_stack,bbInt l_index){
  (*this).m__0stack=l_stack;
  (*this).m__0index=l_index;
  (*this).m__0seq=l_stack->m__0seq;
}

void t_std_collections_Stack_1Tt_mx2_Expr_2_Iterator::m_Insert(t_mx2_Expr* l_value){
  (*this).m_AssertSeq();
  (*this).m__0stack->m_Insert((*this).m__0index,l_value);
  (*this).m__0seq=(*this).m__0stack->m__0seq;
}

void t_std_collections_Stack_1Tt_mx2_Expr_2_Iterator::m_Erase(){
  (*this).m_AssertSeq();
  (*this).m__0stack->m_Erase((*this).m__0index);
  (*this).m__0seq=(*this).m__0stack->m__0seq;
}

void t_std_collections_Stack_1Tt_mx2_Expr_2_Iterator::m_Current(t_mx2_Expr* l_current){
  (*this).m_AssertCurrent();
  (*this).m__0stack->m__0data->at((*this).m__0index)=l_current;
}

t_mx2_Expr* t_std_collections_Stack_1Tt_mx2_Expr_2_Iterator::m_Current(){
  (*this).m_AssertCurrent();
  return (*this).m__0stack->m__0data->at((*this).m__0index);
}

void t_std_collections_Stack_1Tt_mx2_Expr_2_Iterator::m_Bump(){
  (*this).m_AssertCurrent();
  (*this).m__0index+=1;
}

bbBool t_std_collections_Stack_1Tt_mx2_Expr_2_Iterator::m_AtEnd(){
  (*this).m_AssertSeq();
  return ((*this).m__0index==(*this).m__0stack->m__0length);
}

void t_std_collections_Stack_1Tt_mx2_Expr_2_Iterator::m_AssertSeq(){
  bbDebugAssert(((*this).m__0seq==(*this).m__0stack->m__0seq),BB_T("Concurrent list modification"));
}

void t_std_collections_Stack_1Tt_mx2_Expr_2_Iterator::m_AssertCurrent(){
  bbDebugAssert(!(*this).m_AtEnd(),BB_T("Invalid list iterator"));
}

int bbCompare(const t_std_collections_Stack_1Tt_mx2_Expr_2_Iterator&x,const t_std_collections_Stack_1Tt_mx2_Expr_2_Iterator&y){
  if(int t=bbCompare(x.m__0stack,y.m__0stack)) return t;
  if(int t=bbCompare(x.m__0index,y.m__0index)) return t;
  if(int t=bbCompare(x.m__0seq,y.m__0seq)) return t;
  return 0;
}

void bbGCMark(const t_std_collections_Stack_1Tt_mx2_Expr_2_Iterator&t){
  bbGCMark(t.m__0stack);
}

t_std_collections_Stack_1Tt_mx2_Expr_2_BackwardsIterator::t_std_collections_Stack_1Tt_mx2_Expr_2_BackwardsIterator(t_std_collections_Stack_1Tt_mx2_Expr_2* l_stack,bbInt l_index){
  (*this).m__0stack=l_stack;
  (*this).m__0index=l_index;
  (*this).m__0seq=l_stack->m__0seq;
}

void t_std_collections_Stack_1Tt_mx2_Expr_2_BackwardsIterator::m_Insert(t_mx2_Expr* l_value){
  (*this).m_AssertSeq();
  (*this).m__0index+=1;
  (*this).m__0stack->m_Insert((*this).m__0index,l_value);
  (*this).m__0seq=(*this).m__0stack->m__0seq;
}

void t_std_collections_Stack_1Tt_mx2_Expr_2_BackwardsIterator::m_Erase(){
  (*this).m_AssertCurrent();
  (*this).m__0index-=1;
  (*this).m__0stack->m_Erase(((*this).m__0index+1));
  (*this).m__0seq=(*this).m__0stack->m__0seq;
}

void t_std_collections_Stack_1Tt_mx2_Expr_2_BackwardsIterator::m_Current(t_mx2_Expr* l_current){
  (*this).m_AssertCurrent();
  (*this).m__0stack->m__0data->at((*this).m__0index)=l_current;
}

t_mx2_Expr* t_std_collections_Stack_1Tt_mx2_Expr_2_BackwardsIterator::m_Current(){
  (*this).m_AssertCurrent();
  return (*this).m__0stack->m__0data->at((*this).m__0index);
}

void t_std_collections_Stack_1Tt_mx2_Expr_2_BackwardsIterator::m_Bump(){
  (*this).m_AssertCurrent();
  (*this).m__0index-=1;
}

bbBool t_std_collections_Stack_1Tt_mx2_Expr_2_BackwardsIterator::m_AtEnd(){
  (*this).m_AssertSeq();
  return ((*this).m__0index==-1);
}

void t_std_collections_Stack_1Tt_mx2_Expr_2_BackwardsIterator::m_AssertSeq(){
  bbDebugAssert(((*this).m__0seq==(*this).m__0stack->m__0seq),BB_T("Concurrent list modification"));
}

void t_std_collections_Stack_1Tt_mx2_Expr_2_BackwardsIterator::m_AssertCurrent(){
  bbDebugAssert(!(*this).m_AtEnd(),BB_T("Invalid list iterator"));
}

int bbCompare(const t_std_collections_Stack_1Tt_mx2_Expr_2_BackwardsIterator&x,const t_std_collections_Stack_1Tt_mx2_Expr_2_BackwardsIterator&y){
  if(int t=bbCompare(x.m__0stack,y.m__0stack)) return t;
  if(int t=bbCompare(x.m__0index,y.m__0index)) return t;
  if(int t=bbCompare(x.m__0seq,y.m__0seq)) return t;
  return 0;
}

void bbGCMark(const t_std_collections_Stack_1Tt_mx2_Expr_2_BackwardsIterator&t){
  bbGCMark(t.m__0stack);
}

void t_std_collections_Stack_1Tt_mx2_Expr_2::gcMark(){
  bbGCMark(m__0data);
}

t_std_collections_Stack_1Tt_mx2_Expr_2::t_std_collections_Stack_1Tt_mx2_Expr_2(t_std_collections_List_1Tt_mx2_Expr_2* l_values){
  g_std_collections_Stack_1Tt_mx2_Expr_2_AddAll_1Tt_std_collections_List_1Tt_mx2_Expr_2_2(this,l_values);
}

t_std_collections_Stack_1Tt_mx2_Expr_2::t_std_collections_Stack_1Tt_mx2_Expr_2(t_std_collections_Stack_1Tt_mx2_Expr_2* l_values){
  struct f0_t : public bbGCFrame{
    bbArray<bbGCVar<t_mx2_Expr>>* t0{};
    void gcMark(){
      bbGCMarkPtr(t0);
    }
  }f0{};
  this->m__0length=l_values->m_Length();
  this->m__0data=bbArray<bbGCVar<t_mx2_Expr>>::create(this->m__0length);
  (f0.t0=l_values->m_Data())->copyTo(this->m__0data,bbInt(0),bbInt(0),this->m__0length);
}

t_std_collections_Stack_1Tt_mx2_Expr_2::t_std_collections_Stack_1Tt_mx2_Expr_2(bbArray<bbGCVar<t_mx2_Expr>>* l_values){
  this->m_AddAll(l_values);
}

t_std_collections_Stack_1Tt_mx2_Expr_2::t_std_collections_Stack_1Tt_mx2_Expr_2(bbInt l_length){
  this->m__0length=l_length;
  this->m__0data=bbArray<bbGCVar<t_mx2_Expr>>::create(this->m__0length);
}

t_std_collections_Stack_1Tt_mx2_Expr_2::t_std_collections_Stack_1Tt_mx2_Expr_2(){
  this->m__0data=bbArray<bbGCVar<t_mx2_Expr>>::create(10);
}

void t_std_collections_Stack_1Tt_mx2_Expr_2::m__idxeq(bbInt l_index,t_mx2_Expr* l_value){
  bbDebugAssert(((l_index>=bbInt(0))&&(l_index<this->m__0length)),BB_T("Stack index out of range"));
  this->m__0data->at(l_index)=l_value;
}

t_mx2_Expr* t_std_collections_Stack_1Tt_mx2_Expr_2::m__idx(bbInt l_index){
  bbDebugAssert(((l_index>=bbInt(0))&&(l_index<this->m__0length)),BB_T("Stack index out of range"));
  return this->m__0data->at(l_index);
}

t_mx2_Expr* t_std_collections_Stack_1Tt_mx2_Expr_2::m_Top(){
  bbDebugAssert(bbBool(this->m__0length),BB_T("Stack is empty"));
  return this->m__0data->at((this->m__0length-1));
}

bbArray<bbGCVar<t_mx2_Expr>>* t_std_collections_Stack_1Tt_mx2_Expr_2::m_ToArray(){
  return this->m__0data->slice(bbInt(0),this->m__0length);
}

void t_std_collections_Stack_1Tt_mx2_Expr_2::m_Swap(bbInt l_index1,bbInt l_index2){
  struct f0_t : public bbGCFrame{
    t_mx2_Expr* l_t{};
    void gcMark(){
      bbGCMarkPtr(l_t);
    }
  }f0{};
  bbDebugAssert(((((l_index1>=bbInt(0))&&(l_index1<this->m__0length))&&(l_index2>=bbInt(0)))&&(l_index2<this->m__0length)),BB_T("Stack index out of range"));
  f0.l_t=this->m__0data->at(l_index1);
  this->m__0data->at(l_index1)=this->m__0data->at(l_index2);
  this->m__0data->at(l_index2)=f0.l_t;
}

void t_std_collections_Stack_1Tt_mx2_Expr_2::m_Sort(bbFunction<bbInt(t_mx2_Expr*,t_mx2_Expr*)> l_compareFunc,bbInt l_lo,bbInt l_hi){
  if((l_hi<=l_lo)){
    return;
  }
  if(((l_lo+1)==l_hi)){
    if((l_compareFunc(this->m__0data->at(l_hi),this->m__0data->at(l_lo))<bbInt(0))){
      this->m_Swap(l_hi,l_lo);
    }
    return;
  }
  bbInt l_i=((l_lo+l_hi)/2);
  if((l_compareFunc(this->m__0data->at(l_i),this->m__0data->at(l_lo))<bbInt(0))){
    this->m_Swap(l_i,l_lo);
  }
  if((l_compareFunc(this->m__0data->at(l_hi),this->m__0data->at(l_i))<bbInt(0))){
    this->m_Swap(l_hi,l_i);
    if((l_compareFunc(this->m__0data->at(l_i),this->m__0data->at(l_lo))<bbInt(0))){
      this->m_Swap(l_i,l_lo);
    }
  }
  bbInt l_x=(l_lo+1);
  bbInt l_y=(l_hi-1);
  do{
    struct f1_t : public bbGCFrame{
      t_mx2_Expr* l_p{};
      void gcMark(){
        bbGCMarkPtr(l_p);
      }
    }f1{};
    f1.l_p=this->m__0data->at(l_i);
    while((l_compareFunc(this->m__0data->at(l_x),f1.l_p)<bbInt(0))){
      l_x+=1;
    }
    while((l_compareFunc(f1.l_p,this->m__0data->at(l_y))<bbInt(0))){
      l_y-=1;
    }
    if((l_x>l_y)){
      break;
    }
    if((l_x<l_y)){
      this->m_Swap(l_x,l_y);
      if((l_i==l_x)){
        l_i=l_y;
      }else if((l_i==l_y)){
        l_i=l_x;
      }
    }
    l_x+=1;
    l_y-=1;
  }while(!((l_x>l_y)));
  this->m_Sort(l_compareFunc,l_lo,l_y);
  this->m_Sort(l_compareFunc,l_x,l_hi);
}

void t_std_collections_Stack_1Tt_mx2_Expr_2::m_Sort(bbFunction<bbInt(t_mx2_Expr*,t_mx2_Expr*)> l_compareFunc){
  this->m_Sort(l_compareFunc,bbInt(0),(this->m__0length-1));
}

void t_std_collections_Stack_1Tt_mx2_Expr_2::m_Sort(bbBool l_ascending){
  if(l_ascending){
    struct lambda46 : public bbFunction<bbInt(t_mx2_Expr*,t_mx2_Expr*)>::Rep{
      t_std_collections_Stack_1Tt_mx2_Expr_2* l_self;
      lambda46(t_std_collections_Stack_1Tt_mx2_Expr_2* l_self):l_self(l_self){
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
      t_std_collections_Stack_1Tt_mx2_Expr_2* l_self;
      lambda47(t_std_collections_Stack_1Tt_mx2_Expr_2* l_self):l_self(l_self){
      }
      bbInt invoke(t_mx2_Expr* l_x,t_mx2_Expr* l_y){
        return bbCompare(l_y,l_x);
      }
      void gcMark(){
        bbGCMarkPtr(l_self);
      }
    };
    this->m_Sort(bbFunction<bbInt(t_mx2_Expr*,t_mx2_Expr*)>(new lambda47(this)));
  }
}

t_std_collections_Stack_1Tt_mx2_Expr_2* t_std_collections_Stack_1Tt_mx2_Expr_2::m_Slice(bbInt l_index1,bbInt l_index2){
  struct f0_t : public bbGCFrame{
    bbArray<bbGCVar<t_mx2_Expr>>* t0{};
    void gcMark(){
      bbGCMarkPtr(t0);
    }
  }f0{};
  if((l_index1<bbInt(0))){
    l_index1=g_monkey_math_Max_1i((l_index1+this->m__0length),bbInt(0));
  }else if((l_index1>this->m__0length)){
    l_index1=this->m__0length;
  }
  if((l_index2<bbInt(0))){
    l_index2=g_monkey_math_Max_1i((l_index2+this->m__0length),l_index1);
  }else if((l_index2>this->m__0length)){
    l_index2=this->m__0length;
  }else if((l_index2<l_index1)){
    l_index2=l_index1;
  }
  return bbGCNew<t_std_collections_Stack_1Tt_mx2_Expr_2>(f0.t0=this->m__0data->slice(l_index1,l_index2));
}

t_std_collections_Stack_1Tt_mx2_Expr_2* t_std_collections_Stack_1Tt_mx2_Expr_2::m_Slice(bbInt l_index){
  return this->m_Slice(l_index,this->m__0length);
}

void t_std_collections_Stack_1Tt_mx2_Expr_2::m_Set(bbInt l_index,t_mx2_Expr* l_value){
  bbDebugAssert(((l_index>=bbInt(0))&&(l_index<this->m__0length)),BB_T("Stack index out of range"));
  this->m__0data->at(l_index)=l_value;
}

void t_std_collections_Stack_1Tt_mx2_Expr_2::m_Resize(bbInt l_length){
  bbDebugAssert((l_length>=bbInt(0)),BB_T("Debug assert failed"));
  {
    bbInt l_i=l_length;
    for(;(l_i<this->m__0length);l_i+=1){
      this->m__0data->at(l_i)=((t_mx2_Expr*)0);
    }
  }
  this->m_Reserve(l_length);
  this->m__0length=l_length;
  this->m__0seq+=1;
}

void t_std_collections_Stack_1Tt_mx2_Expr_2::m_Reserve(bbInt l_capacity){
  struct f0_t : public bbGCFrame{
    bbArray<bbGCVar<t_mx2_Expr>>* l_data{};
    void gcMark(){
      bbGCMarkPtr(l_data);
    }
  }f0{};
  bbDebugAssert((l_capacity>=bbInt(0)),BB_T("Debug assert failed"));
  if((this->m__0data->length()>=l_capacity)){
    return;
  }
  l_capacity=g_monkey_math_Max_1i(((this->m__0length*2)+this->m__0length),l_capacity);
  f0.l_data=bbArray<bbGCVar<t_mx2_Expr>>::create(l_capacity);
  this->m__0data->copyTo(f0.l_data,bbInt(0),bbInt(0),this->m__0length);
  this->m__0data=f0.l_data;
}

bbBool t_std_collections_Stack_1Tt_mx2_Expr_2::m_RemoveLast(t_mx2_Expr* l_value,bbInt l_start){
  bbInt l_i=this->m_FindLastIndex(l_value,l_start);
  if((l_i==-1)){
    return false;
  }
  this->m_Erase(l_i);
  return true;
}

bbInt t_std_collections_Stack_1Tt_mx2_Expr_2::m_RemoveEach(t_mx2_Expr* l_value){
  bbInt l_put=bbInt(0);
  bbInt l_n=bbInt(0);
  {
    bbInt l_get=bbInt(0);
    for(;(l_get<this->m__0length);l_get+=1){
      if((this->m__0data->at(l_get)==l_value)){
        l_n+=1;
        continue;
      }
      this->m__0data->at(l_put)=this->m__0data->at(l_get);
      l_put+=1;
    }
  }
  this->m_Resize(l_put);
  return l_n;
}

bbBool t_std_collections_Stack_1Tt_mx2_Expr_2::m_Remove(t_mx2_Expr* l_value,bbInt l_start){
  bbInt l_i=this->m_FindIndex(l_value,l_start);
  if((l_i==-1)){
    return false;
  }
  this->m_Erase(l_i);
  return true;
}

void t_std_collections_Stack_1Tt_mx2_Expr_2::m_Push(t_mx2_Expr* l_value){
  this->m_Add(l_value);
}

t_mx2_Expr* t_std_collections_Stack_1Tt_mx2_Expr_2::m_Pop(){
  struct f0_t : public bbGCFrame{
    t_mx2_Expr* l_value{};
    void gcMark(){
      bbGCMarkPtr(l_value);
    }
  }f0{};
  bbDebugAssert(bbBool(this->m__0length),BB_T("Stack is empty"));
  this->m__0length-=1;
  this->m__0seq+=1;
  f0.l_value=this->m__0data->at(this->m__0length);
  this->m__0data->at(this->m__0length)=((t_mx2_Expr*)0);
  return f0.l_value;
}

bbInt t_std_collections_Stack_1Tt_mx2_Expr_2::m_Length(){
  return this->m__0length;
}

void t_std_collections_Stack_1Tt_mx2_Expr_2::m_Insert(bbInt l_index,t_mx2_Expr* l_value){
  bbDebugAssert(((l_index>=bbInt(0))&&(l_index<=this->m__0length)),BB_T("Debug assert failed"));
  this->m_Reserve((this->m__0length+1));
  this->m__0data->copyTo(this->m__0data,l_index,(l_index+1),(this->m__0length-l_index));
  this->m__0data->at(l_index)=l_value;
  this->m__0length+=1;
  this->m__0seq+=1;
}

t_mx2_Expr* t_std_collections_Stack_1Tt_mx2_Expr_2::m_Get(bbInt l_index){
  bbDebugAssert(((l_index>=bbInt(0))&&(l_index<this->m__0length)),BB_T("Stack index out of range"));
  return this->m__0data->at(l_index);
}

bbInt t_std_collections_Stack_1Tt_mx2_Expr_2::m_FindLastIndex(t_mx2_Expr* l_value,bbInt l_start){
  bbDebugAssert(((l_start>=bbInt(0))&&(l_start<=this->m__0length)),BB_T("Debug assert failed"));
  bbInt l_i=this->m__0length;
  while((l_i>l_start)){
    l_i-=1;
    if((this->m__0data->at(l_i)==l_value)){
      return l_i;
    }
  }
  return -1;
}

bbInt t_std_collections_Stack_1Tt_mx2_Expr_2::m_FindIndex(t_mx2_Expr* l_value,bbInt l_start){
  bbDebugAssert(((l_start>=bbInt(0))&&(l_start<=this->m__0length)),BB_T("Debug assert failed"));
  bbInt l_i=l_start;
  while((l_i<this->m__0length)){
    if((this->m__0data->at(l_i)==l_value)){
      return l_i;
    }
    l_i+=1;
  }
  return -1;
}

void t_std_collections_Stack_1Tt_mx2_Expr_2::m_Erase(bbInt l_index1,bbInt l_index2){
  bbDebugAssert((((((l_index1>=bbInt(0))&&(l_index1<=this->m__0length))&&(l_index2>=bbInt(0)))&&(l_index2<=this->m__0length))&&(l_index1<=l_index2)),BB_T("Debug assert failed"));
  if((l_index1==this->m__0length)){
    return;
  }
  this->m__0data->copyTo(this->m__0data,l_index2,l_index1,(this->m__0length-l_index2));
  this->m_Resize(((this->m__0length-l_index2)+l_index1));
}

void t_std_collections_Stack_1Tt_mx2_Expr_2::m_Erase(bbInt l_index){
  bbDebugAssert(((l_index>=bbInt(0))&&(l_index<=this->m__0length)),BB_T("Debug assert failed"));
  if((l_index==this->m__0length)){
    return;
  }
  this->m__0data->copyTo(this->m__0data,(l_index+1),l_index,((this->m__0length-l_index)-1));
  this->m_Resize((this->m__0length-1));
}

bbBool t_std_collections_Stack_1Tt_mx2_Expr_2::m_Empty(){
  return (this->m__0length==bbInt(0));
}

bbArray<bbGCVar<t_mx2_Expr>>* t_std_collections_Stack_1Tt_mx2_Expr_2::m_Data(){
  return this->m__0data;
}

bbBool t_std_collections_Stack_1Tt_mx2_Expr_2::m_Contains(t_mx2_Expr* l_value){
  return (this->m_FindIndex(l_value,bbInt(0))!=-1);
}

void t_std_collections_Stack_1Tt_mx2_Expr_2::m_Clear(){
  this->m_Resize(bbInt(0));
}

bbInt t_std_collections_Stack_1Tt_mx2_Expr_2::m_Capacity(){
  return this->m__0data->length();
}

t_std_collections_Stack_1Tt_mx2_Expr_2_BackwardsIterator t_std_collections_Stack_1Tt_mx2_Expr_2::m_Backwards(){
  return t_std_collections_Stack_1Tt_mx2_Expr_2_BackwardsIterator(this,(this->m__0length-1));
}

t_std_collections_Stack_1Tt_mx2_Expr_2_Iterator t_std_collections_Stack_1Tt_mx2_Expr_2::m_All(){
  return t_std_collections_Stack_1Tt_mx2_Expr_2_Iterator(this,bbInt(0));
}

void t_std_collections_Stack_1Tt_mx2_Expr_2::m_AddAll(bbArray<bbGCVar<t_mx2_Expr>>* l_values){
  this->m_Reserve((this->m__0length+l_values->length()));
  l_values->copyTo(this->m__0data,bbInt(0),this->m__0length,l_values->length());
  this->m_Resize((this->m__0length+l_values->length()));
}

void t_std_collections_Stack_1Tt_mx2_Expr_2::m_Add(t_mx2_Expr* l_value){
  this->m_Reserve((this->m__0length+1));
  this->m__0data->at(this->m__0length)=l_value;
  this->m__0length+=1;
  this->m__0seq+=1;
}

t_std_collections_Stack_1Tt_mx2_VarDecl_2_Iterator::t_std_collections_Stack_1Tt_mx2_VarDecl_2_Iterator(t_std_collections_Stack_1Tt_mx2_VarDecl_2* l_stack,bbInt l_index){
  (*this).m__0stack=l_stack;
  (*this).m__0index=l_index;
  (*this).m__0seq=l_stack->m__0seq;
}

void t_std_collections_Stack_1Tt_mx2_VarDecl_2_Iterator::m_Insert(t_mx2_VarDecl* l_value){
  (*this).m_AssertSeq();
  (*this).m__0stack->m_Insert((*this).m__0index,l_value);
  (*this).m__0seq=(*this).m__0stack->m__0seq;
}

void t_std_collections_Stack_1Tt_mx2_VarDecl_2_Iterator::m_Erase(){
  (*this).m_AssertSeq();
  (*this).m__0stack->m_Erase((*this).m__0index);
  (*this).m__0seq=(*this).m__0stack->m__0seq;
}

void t_std_collections_Stack_1Tt_mx2_VarDecl_2_Iterator::m_Current(t_mx2_VarDecl* l_current){
  (*this).m_AssertCurrent();
  (*this).m__0stack->m__0data->at((*this).m__0index)=l_current;
}

t_mx2_VarDecl* t_std_collections_Stack_1Tt_mx2_VarDecl_2_Iterator::m_Current(){
  (*this).m_AssertCurrent();
  return (*this).m__0stack->m__0data->at((*this).m__0index);
}

void t_std_collections_Stack_1Tt_mx2_VarDecl_2_Iterator::m_Bump(){
  (*this).m_AssertCurrent();
  (*this).m__0index+=1;
}

bbBool t_std_collections_Stack_1Tt_mx2_VarDecl_2_Iterator::m_AtEnd(){
  (*this).m_AssertSeq();
  return ((*this).m__0index==(*this).m__0stack->m__0length);
}

void t_std_collections_Stack_1Tt_mx2_VarDecl_2_Iterator::m_AssertSeq(){
  bbDebugAssert(((*this).m__0seq==(*this).m__0stack->m__0seq),BB_T("Concurrent list modification"));
}

void t_std_collections_Stack_1Tt_mx2_VarDecl_2_Iterator::m_AssertCurrent(){
  bbDebugAssert(!(*this).m_AtEnd(),BB_T("Invalid list iterator"));
}

int bbCompare(const t_std_collections_Stack_1Tt_mx2_VarDecl_2_Iterator&x,const t_std_collections_Stack_1Tt_mx2_VarDecl_2_Iterator&y){
  if(int t=bbCompare(x.m__0stack,y.m__0stack)) return t;
  if(int t=bbCompare(x.m__0index,y.m__0index)) return t;
  if(int t=bbCompare(x.m__0seq,y.m__0seq)) return t;
  return 0;
}

void bbGCMark(const t_std_collections_Stack_1Tt_mx2_VarDecl_2_Iterator&t){
  bbGCMark(t.m__0stack);
}

t_std_collections_Stack_1Tt_mx2_VarDecl_2_BackwardsIterator::t_std_collections_Stack_1Tt_mx2_VarDecl_2_BackwardsIterator(t_std_collections_Stack_1Tt_mx2_VarDecl_2* l_stack,bbInt l_index){
  (*this).m__0stack=l_stack;
  (*this).m__0index=l_index;
  (*this).m__0seq=l_stack->m__0seq;
}

void t_std_collections_Stack_1Tt_mx2_VarDecl_2_BackwardsIterator::m_Insert(t_mx2_VarDecl* l_value){
  (*this).m_AssertSeq();
  (*this).m__0index+=1;
  (*this).m__0stack->m_Insert((*this).m__0index,l_value);
  (*this).m__0seq=(*this).m__0stack->m__0seq;
}

void t_std_collections_Stack_1Tt_mx2_VarDecl_2_BackwardsIterator::m_Erase(){
  (*this).m_AssertCurrent();
  (*this).m__0index-=1;
  (*this).m__0stack->m_Erase(((*this).m__0index+1));
  (*this).m__0seq=(*this).m__0stack->m__0seq;
}

void t_std_collections_Stack_1Tt_mx2_VarDecl_2_BackwardsIterator::m_Current(t_mx2_VarDecl* l_current){
  (*this).m_AssertCurrent();
  (*this).m__0stack->m__0data->at((*this).m__0index)=l_current;
}

t_mx2_VarDecl* t_std_collections_Stack_1Tt_mx2_VarDecl_2_BackwardsIterator::m_Current(){
  (*this).m_AssertCurrent();
  return (*this).m__0stack->m__0data->at((*this).m__0index);
}

void t_std_collections_Stack_1Tt_mx2_VarDecl_2_BackwardsIterator::m_Bump(){
  (*this).m_AssertCurrent();
  (*this).m__0index-=1;
}

bbBool t_std_collections_Stack_1Tt_mx2_VarDecl_2_BackwardsIterator::m_AtEnd(){
  (*this).m_AssertSeq();
  return ((*this).m__0index==-1);
}

void t_std_collections_Stack_1Tt_mx2_VarDecl_2_BackwardsIterator::m_AssertSeq(){
  bbDebugAssert(((*this).m__0seq==(*this).m__0stack->m__0seq),BB_T("Concurrent list modification"));
}

void t_std_collections_Stack_1Tt_mx2_VarDecl_2_BackwardsIterator::m_AssertCurrent(){
  bbDebugAssert(!(*this).m_AtEnd(),BB_T("Invalid list iterator"));
}

int bbCompare(const t_std_collections_Stack_1Tt_mx2_VarDecl_2_BackwardsIterator&x,const t_std_collections_Stack_1Tt_mx2_VarDecl_2_BackwardsIterator&y){
  if(int t=bbCompare(x.m__0stack,y.m__0stack)) return t;
  if(int t=bbCompare(x.m__0index,y.m__0index)) return t;
  if(int t=bbCompare(x.m__0seq,y.m__0seq)) return t;
  return 0;
}

void bbGCMark(const t_std_collections_Stack_1Tt_mx2_VarDecl_2_BackwardsIterator&t){
  bbGCMark(t.m__0stack);
}

void t_std_collections_Stack_1Tt_mx2_VarDecl_2::gcMark(){
  bbGCMark(m__0data);
}

t_std_collections_Stack_1Tt_mx2_VarDecl_2::t_std_collections_Stack_1Tt_mx2_VarDecl_2(t_std_collections_List_1Tt_mx2_VarDecl_2* l_values){
  g_std_collections_Stack_1Tt_mx2_VarDecl_2_AddAll_1Tt_std_collections_List_1Tt_mx2_VarDecl_2_2(this,l_values);
}

t_std_collections_Stack_1Tt_mx2_VarDecl_2::t_std_collections_Stack_1Tt_mx2_VarDecl_2(t_std_collections_Stack_1Tt_mx2_VarDecl_2* l_values){
  struct f0_t : public bbGCFrame{
    bbArray<bbGCVar<t_mx2_VarDecl>>* t0{};
    void gcMark(){
      bbGCMarkPtr(t0);
    }
  }f0{};
  this->m__0length=l_values->m_Length();
  this->m__0data=bbArray<bbGCVar<t_mx2_VarDecl>>::create(this->m__0length);
  (f0.t0=l_values->m_Data())->copyTo(this->m__0data,bbInt(0),bbInt(0),this->m__0length);
}

t_std_collections_Stack_1Tt_mx2_VarDecl_2::t_std_collections_Stack_1Tt_mx2_VarDecl_2(bbArray<bbGCVar<t_mx2_VarDecl>>* l_values){
  this->m_AddAll(l_values);
}

t_std_collections_Stack_1Tt_mx2_VarDecl_2::t_std_collections_Stack_1Tt_mx2_VarDecl_2(bbInt l_length){
  this->m__0length=l_length;
  this->m__0data=bbArray<bbGCVar<t_mx2_VarDecl>>::create(this->m__0length);
}

t_std_collections_Stack_1Tt_mx2_VarDecl_2::t_std_collections_Stack_1Tt_mx2_VarDecl_2(){
  this->m__0data=bbArray<bbGCVar<t_mx2_VarDecl>>::create(10);
}

void t_std_collections_Stack_1Tt_mx2_VarDecl_2::m__idxeq(bbInt l_index,t_mx2_VarDecl* l_value){
  bbDebugAssert(((l_index>=bbInt(0))&&(l_index<this->m__0length)),BB_T("Stack index out of range"));
  this->m__0data->at(l_index)=l_value;
}

t_mx2_VarDecl* t_std_collections_Stack_1Tt_mx2_VarDecl_2::m__idx(bbInt l_index){
  bbDebugAssert(((l_index>=bbInt(0))&&(l_index<this->m__0length)),BB_T("Stack index out of range"));
  return this->m__0data->at(l_index);
}

t_mx2_VarDecl* t_std_collections_Stack_1Tt_mx2_VarDecl_2::m_Top(){
  bbDebugAssert(bbBool(this->m__0length),BB_T("Stack is empty"));
  return this->m__0data->at((this->m__0length-1));
}

bbArray<bbGCVar<t_mx2_VarDecl>>* t_std_collections_Stack_1Tt_mx2_VarDecl_2::m_ToArray(){
  return this->m__0data->slice(bbInt(0),this->m__0length);
}

void t_std_collections_Stack_1Tt_mx2_VarDecl_2::m_Swap(bbInt l_index1,bbInt l_index2){
  struct f0_t : public bbGCFrame{
    t_mx2_VarDecl* l_t{};
    void gcMark(){
      bbGCMarkPtr(l_t);
    }
  }f0{};
  bbDebugAssert(((((l_index1>=bbInt(0))&&(l_index1<this->m__0length))&&(l_index2>=bbInt(0)))&&(l_index2<this->m__0length)),BB_T("Stack index out of range"));
  f0.l_t=this->m__0data->at(l_index1);
  this->m__0data->at(l_index1)=this->m__0data->at(l_index2);
  this->m__0data->at(l_index2)=f0.l_t;
}

void t_std_collections_Stack_1Tt_mx2_VarDecl_2::m_Sort(bbFunction<bbInt(t_mx2_VarDecl*,t_mx2_VarDecl*)> l_compareFunc,bbInt l_lo,bbInt l_hi){
  if((l_hi<=l_lo)){
    return;
  }
  if(((l_lo+1)==l_hi)){
    if((l_compareFunc(this->m__0data->at(l_hi),this->m__0data->at(l_lo))<bbInt(0))){
      this->m_Swap(l_hi,l_lo);
    }
    return;
  }
  bbInt l_i=((l_lo+l_hi)/2);
  if((l_compareFunc(this->m__0data->at(l_i),this->m__0data->at(l_lo))<bbInt(0))){
    this->m_Swap(l_i,l_lo);
  }
  if((l_compareFunc(this->m__0data->at(l_hi),this->m__0data->at(l_i))<bbInt(0))){
    this->m_Swap(l_hi,l_i);
    if((l_compareFunc(this->m__0data->at(l_i),this->m__0data->at(l_lo))<bbInt(0))){
      this->m_Swap(l_i,l_lo);
    }
  }
  bbInt l_x=(l_lo+1);
  bbInt l_y=(l_hi-1);
  do{
    struct f1_t : public bbGCFrame{
      t_mx2_VarDecl* l_p{};
      void gcMark(){
        bbGCMarkPtr(l_p);
      }
    }f1{};
    f1.l_p=this->m__0data->at(l_i);
    while((l_compareFunc(this->m__0data->at(l_x),f1.l_p)<bbInt(0))){
      l_x+=1;
    }
    while((l_compareFunc(f1.l_p,this->m__0data->at(l_y))<bbInt(0))){
      l_y-=1;
    }
    if((l_x>l_y)){
      break;
    }
    if((l_x<l_y)){
      this->m_Swap(l_x,l_y);
      if((l_i==l_x)){
        l_i=l_y;
      }else if((l_i==l_y)){
        l_i=l_x;
      }
    }
    l_x+=1;
    l_y-=1;
  }while(!((l_x>l_y)));
  this->m_Sort(l_compareFunc,l_lo,l_y);
  this->m_Sort(l_compareFunc,l_x,l_hi);
}

void t_std_collections_Stack_1Tt_mx2_VarDecl_2::m_Sort(bbFunction<bbInt(t_mx2_VarDecl*,t_mx2_VarDecl*)> l_compareFunc){
  this->m_Sort(l_compareFunc,bbInt(0),(this->m__0length-1));
}

void t_std_collections_Stack_1Tt_mx2_VarDecl_2::m_Sort(bbBool l_ascending){
  if(l_ascending){
    struct lambda48 : public bbFunction<bbInt(t_mx2_VarDecl*,t_mx2_VarDecl*)>::Rep{
      t_std_collections_Stack_1Tt_mx2_VarDecl_2* l_self;
      lambda48(t_std_collections_Stack_1Tt_mx2_VarDecl_2* l_self):l_self(l_self){
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
      t_std_collections_Stack_1Tt_mx2_VarDecl_2* l_self;
      lambda49(t_std_collections_Stack_1Tt_mx2_VarDecl_2* l_self):l_self(l_self){
      }
      bbInt invoke(t_mx2_VarDecl* l_x,t_mx2_VarDecl* l_y){
        return bbCompare(l_y,l_x);
      }
      void gcMark(){
        bbGCMarkPtr(l_self);
      }
    };
    this->m_Sort(bbFunction<bbInt(t_mx2_VarDecl*,t_mx2_VarDecl*)>(new lambda49(this)));
  }
}

t_std_collections_Stack_1Tt_mx2_VarDecl_2* t_std_collections_Stack_1Tt_mx2_VarDecl_2::m_Slice(bbInt l_index1,bbInt l_index2){
  struct f0_t : public bbGCFrame{
    bbArray<bbGCVar<t_mx2_VarDecl>>* t0{};
    void gcMark(){
      bbGCMarkPtr(t0);
    }
  }f0{};
  if((l_index1<bbInt(0))){
    l_index1=g_monkey_math_Max_1i((l_index1+this->m__0length),bbInt(0));
  }else if((l_index1>this->m__0length)){
    l_index1=this->m__0length;
  }
  if((l_index2<bbInt(0))){
    l_index2=g_monkey_math_Max_1i((l_index2+this->m__0length),l_index1);
  }else if((l_index2>this->m__0length)){
    l_index2=this->m__0length;
  }else if((l_index2<l_index1)){
    l_index2=l_index1;
  }
  return bbGCNew<t_std_collections_Stack_1Tt_mx2_VarDecl_2>(f0.t0=this->m__0data->slice(l_index1,l_index2));
}

t_std_collections_Stack_1Tt_mx2_VarDecl_2* t_std_collections_Stack_1Tt_mx2_VarDecl_2::m_Slice(bbInt l_index){
  return this->m_Slice(l_index,this->m__0length);
}

void t_std_collections_Stack_1Tt_mx2_VarDecl_2::m_Set(bbInt l_index,t_mx2_VarDecl* l_value){
  bbDebugAssert(((l_index>=bbInt(0))&&(l_index<this->m__0length)),BB_T("Stack index out of range"));
  this->m__0data->at(l_index)=l_value;
}

void t_std_collections_Stack_1Tt_mx2_VarDecl_2::m_Resize(bbInt l_length){
  bbDebugAssert((l_length>=bbInt(0)),BB_T("Debug assert failed"));
  {
    bbInt l_i=l_length;
    for(;(l_i<this->m__0length);l_i+=1){
      this->m__0data->at(l_i)=((t_mx2_VarDecl*)0);
    }
  }
  this->m_Reserve(l_length);
  this->m__0length=l_length;
  this->m__0seq+=1;
}

void t_std_collections_Stack_1Tt_mx2_VarDecl_2::m_Reserve(bbInt l_capacity){
  struct f0_t : public bbGCFrame{
    bbArray<bbGCVar<t_mx2_VarDecl>>* l_data{};
    void gcMark(){
      bbGCMarkPtr(l_data);
    }
  }f0{};
  bbDebugAssert((l_capacity>=bbInt(0)),BB_T("Debug assert failed"));
  if((this->m__0data->length()>=l_capacity)){
    return;
  }
  l_capacity=g_monkey_math_Max_1i(((this->m__0length*2)+this->m__0length),l_capacity);
  f0.l_data=bbArray<bbGCVar<t_mx2_VarDecl>>::create(l_capacity);
  this->m__0data->copyTo(f0.l_data,bbInt(0),bbInt(0),this->m__0length);
  this->m__0data=f0.l_data;
}

bbBool t_std_collections_Stack_1Tt_mx2_VarDecl_2::m_RemoveLast(t_mx2_VarDecl* l_value,bbInt l_start){
  bbInt l_i=this->m_FindLastIndex(l_value,l_start);
  if((l_i==-1)){
    return false;
  }
  this->m_Erase(l_i);
  return true;
}

bbInt t_std_collections_Stack_1Tt_mx2_VarDecl_2::m_RemoveEach(t_mx2_VarDecl* l_value){
  bbInt l_put=bbInt(0);
  bbInt l_n=bbInt(0);
  {
    bbInt l_get=bbInt(0);
    for(;(l_get<this->m__0length);l_get+=1){
      if((this->m__0data->at(l_get)==l_value)){
        l_n+=1;
        continue;
      }
      this->m__0data->at(l_put)=this->m__0data->at(l_get);
      l_put+=1;
    }
  }
  this->m_Resize(l_put);
  return l_n;
}

bbBool t_std_collections_Stack_1Tt_mx2_VarDecl_2::m_Remove(t_mx2_VarDecl* l_value,bbInt l_start){
  bbInt l_i=this->m_FindIndex(l_value,l_start);
  if((l_i==-1)){
    return false;
  }
  this->m_Erase(l_i);
  return true;
}

void t_std_collections_Stack_1Tt_mx2_VarDecl_2::m_Push(t_mx2_VarDecl* l_value){
  this->m_Add(l_value);
}

t_mx2_VarDecl* t_std_collections_Stack_1Tt_mx2_VarDecl_2::m_Pop(){
  struct f0_t : public bbGCFrame{
    t_mx2_VarDecl* l_value{};
    void gcMark(){
      bbGCMarkPtr(l_value);
    }
  }f0{};
  bbDebugAssert(bbBool(this->m__0length),BB_T("Stack is empty"));
  this->m__0length-=1;
  this->m__0seq+=1;
  f0.l_value=this->m__0data->at(this->m__0length);
  this->m__0data->at(this->m__0length)=((t_mx2_VarDecl*)0);
  return f0.l_value;
}

bbInt t_std_collections_Stack_1Tt_mx2_VarDecl_2::m_Length(){
  return this->m__0length;
}

void t_std_collections_Stack_1Tt_mx2_VarDecl_2::m_Insert(bbInt l_index,t_mx2_VarDecl* l_value){
  bbDebugAssert(((l_index>=bbInt(0))&&(l_index<=this->m__0length)),BB_T("Debug assert failed"));
  this->m_Reserve((this->m__0length+1));
  this->m__0data->copyTo(this->m__0data,l_index,(l_index+1),(this->m__0length-l_index));
  this->m__0data->at(l_index)=l_value;
  this->m__0length+=1;
  this->m__0seq+=1;
}

t_mx2_VarDecl* t_std_collections_Stack_1Tt_mx2_VarDecl_2::m_Get(bbInt l_index){
  bbDebugAssert(((l_index>=bbInt(0))&&(l_index<this->m__0length)),BB_T("Stack index out of range"));
  return this->m__0data->at(l_index);
}

bbInt t_std_collections_Stack_1Tt_mx2_VarDecl_2::m_FindLastIndex(t_mx2_VarDecl* l_value,bbInt l_start){
  bbDebugAssert(((l_start>=bbInt(0))&&(l_start<=this->m__0length)),BB_T("Debug assert failed"));
  bbInt l_i=this->m__0length;
  while((l_i>l_start)){
    l_i-=1;
    if((this->m__0data->at(l_i)==l_value)){
      return l_i;
    }
  }
  return -1;
}

bbInt t_std_collections_Stack_1Tt_mx2_VarDecl_2::m_FindIndex(t_mx2_VarDecl* l_value,bbInt l_start){
  bbDebugAssert(((l_start>=bbInt(0))&&(l_start<=this->m__0length)),BB_T("Debug assert failed"));
  bbInt l_i=l_start;
  while((l_i<this->m__0length)){
    if((this->m__0data->at(l_i)==l_value)){
      return l_i;
    }
    l_i+=1;
  }
  return -1;
}

void t_std_collections_Stack_1Tt_mx2_VarDecl_2::m_Erase(bbInt l_index1,bbInt l_index2){
  bbDebugAssert((((((l_index1>=bbInt(0))&&(l_index1<=this->m__0length))&&(l_index2>=bbInt(0)))&&(l_index2<=this->m__0length))&&(l_index1<=l_index2)),BB_T("Debug assert failed"));
  if((l_index1==this->m__0length)){
    return;
  }
  this->m__0data->copyTo(this->m__0data,l_index2,l_index1,(this->m__0length-l_index2));
  this->m_Resize(((this->m__0length-l_index2)+l_index1));
}

void t_std_collections_Stack_1Tt_mx2_VarDecl_2::m_Erase(bbInt l_index){
  bbDebugAssert(((l_index>=bbInt(0))&&(l_index<=this->m__0length)),BB_T("Debug assert failed"));
  if((l_index==this->m__0length)){
    return;
  }
  this->m__0data->copyTo(this->m__0data,(l_index+1),l_index,((this->m__0length-l_index)-1));
  this->m_Resize((this->m__0length-1));
}

bbBool t_std_collections_Stack_1Tt_mx2_VarDecl_2::m_Empty(){
  return (this->m__0length==bbInt(0));
}

bbArray<bbGCVar<t_mx2_VarDecl>>* t_std_collections_Stack_1Tt_mx2_VarDecl_2::m_Data(){
  return this->m__0data;
}

bbBool t_std_collections_Stack_1Tt_mx2_VarDecl_2::m_Contains(t_mx2_VarDecl* l_value){
  return (this->m_FindIndex(l_value,bbInt(0))!=-1);
}

void t_std_collections_Stack_1Tt_mx2_VarDecl_2::m_Clear(){
  this->m_Resize(bbInt(0));
}

bbInt t_std_collections_Stack_1Tt_mx2_VarDecl_2::m_Capacity(){
  return this->m__0data->length();
}

t_std_collections_Stack_1Tt_mx2_VarDecl_2_BackwardsIterator t_std_collections_Stack_1Tt_mx2_VarDecl_2::m_Backwards(){
  return t_std_collections_Stack_1Tt_mx2_VarDecl_2_BackwardsIterator(this,(this->m__0length-1));
}

t_std_collections_Stack_1Tt_mx2_VarDecl_2_Iterator t_std_collections_Stack_1Tt_mx2_VarDecl_2::m_All(){
  return t_std_collections_Stack_1Tt_mx2_VarDecl_2_Iterator(this,bbInt(0));
}

void t_std_collections_Stack_1Tt_mx2_VarDecl_2::m_AddAll(bbArray<bbGCVar<t_mx2_VarDecl>>* l_values){
  this->m_Reserve((this->m__0length+l_values->length()));
  l_values->copyTo(this->m__0data,bbInt(0),this->m__0length,l_values->length());
  this->m_Resize((this->m__0length+l_values->length()));
}

void t_std_collections_Stack_1Tt_mx2_VarDecl_2::m_Add(t_mx2_VarDecl* l_value){
  this->m_Reserve((this->m__0length+1));
  this->m__0data->at(this->m__0length)=l_value;
  this->m__0length+=1;
  this->m__0seq+=1;
}

t_std_collections_Stack_1Tt_mx2_CatchStmt_2_Iterator::t_std_collections_Stack_1Tt_mx2_CatchStmt_2_Iterator(t_std_collections_Stack_1Tt_mx2_CatchStmt_2* l_stack,bbInt l_index){
  (*this).m__0stack=l_stack;
  (*this).m__0index=l_index;
  (*this).m__0seq=l_stack->m__0seq;
}

void t_std_collections_Stack_1Tt_mx2_CatchStmt_2_Iterator::m_Insert(t_mx2_CatchStmt* l_value){
  (*this).m_AssertSeq();
  (*this).m__0stack->m_Insert((*this).m__0index,l_value);
  (*this).m__0seq=(*this).m__0stack->m__0seq;
}

void t_std_collections_Stack_1Tt_mx2_CatchStmt_2_Iterator::m_Erase(){
  (*this).m_AssertSeq();
  (*this).m__0stack->m_Erase((*this).m__0index);
  (*this).m__0seq=(*this).m__0stack->m__0seq;
}

void t_std_collections_Stack_1Tt_mx2_CatchStmt_2_Iterator::m_Current(t_mx2_CatchStmt* l_current){
  (*this).m_AssertCurrent();
  (*this).m__0stack->m__0data->at((*this).m__0index)=l_current;
}

t_mx2_CatchStmt* t_std_collections_Stack_1Tt_mx2_CatchStmt_2_Iterator::m_Current(){
  (*this).m_AssertCurrent();
  return (*this).m__0stack->m__0data->at((*this).m__0index);
}

void t_std_collections_Stack_1Tt_mx2_CatchStmt_2_Iterator::m_Bump(){
  (*this).m_AssertCurrent();
  (*this).m__0index+=1;
}

bbBool t_std_collections_Stack_1Tt_mx2_CatchStmt_2_Iterator::m_AtEnd(){
  (*this).m_AssertSeq();
  return ((*this).m__0index==(*this).m__0stack->m__0length);
}

void t_std_collections_Stack_1Tt_mx2_CatchStmt_2_Iterator::m_AssertSeq(){
  bbDebugAssert(((*this).m__0seq==(*this).m__0stack->m__0seq),BB_T("Concurrent list modification"));
}

void t_std_collections_Stack_1Tt_mx2_CatchStmt_2_Iterator::m_AssertCurrent(){
  bbDebugAssert(!(*this).m_AtEnd(),BB_T("Invalid list iterator"));
}

int bbCompare(const t_std_collections_Stack_1Tt_mx2_CatchStmt_2_Iterator&x,const t_std_collections_Stack_1Tt_mx2_CatchStmt_2_Iterator&y){
  if(int t=bbCompare(x.m__0stack,y.m__0stack)) return t;
  if(int t=bbCompare(x.m__0index,y.m__0index)) return t;
  if(int t=bbCompare(x.m__0seq,y.m__0seq)) return t;
  return 0;
}

void bbGCMark(const t_std_collections_Stack_1Tt_mx2_CatchStmt_2_Iterator&t){
  bbGCMark(t.m__0stack);
}

t_std_collections_Stack_1Tt_mx2_CatchStmt_2_BackwardsIterator::t_std_collections_Stack_1Tt_mx2_CatchStmt_2_BackwardsIterator(t_std_collections_Stack_1Tt_mx2_CatchStmt_2* l_stack,bbInt l_index){
  (*this).m__0stack=l_stack;
  (*this).m__0index=l_index;
  (*this).m__0seq=l_stack->m__0seq;
}

void t_std_collections_Stack_1Tt_mx2_CatchStmt_2_BackwardsIterator::m_Insert(t_mx2_CatchStmt* l_value){
  (*this).m_AssertSeq();
  (*this).m__0index+=1;
  (*this).m__0stack->m_Insert((*this).m__0index,l_value);
  (*this).m__0seq=(*this).m__0stack->m__0seq;
}

void t_std_collections_Stack_1Tt_mx2_CatchStmt_2_BackwardsIterator::m_Erase(){
  (*this).m_AssertCurrent();
  (*this).m__0index-=1;
  (*this).m__0stack->m_Erase(((*this).m__0index+1));
  (*this).m__0seq=(*this).m__0stack->m__0seq;
}

void t_std_collections_Stack_1Tt_mx2_CatchStmt_2_BackwardsIterator::m_Current(t_mx2_CatchStmt* l_current){
  (*this).m_AssertCurrent();
  (*this).m__0stack->m__0data->at((*this).m__0index)=l_current;
}

t_mx2_CatchStmt* t_std_collections_Stack_1Tt_mx2_CatchStmt_2_BackwardsIterator::m_Current(){
  (*this).m_AssertCurrent();
  return (*this).m__0stack->m__0data->at((*this).m__0index);
}

void t_std_collections_Stack_1Tt_mx2_CatchStmt_2_BackwardsIterator::m_Bump(){
  (*this).m_AssertCurrent();
  (*this).m__0index-=1;
}

bbBool t_std_collections_Stack_1Tt_mx2_CatchStmt_2_BackwardsIterator::m_AtEnd(){
  (*this).m_AssertSeq();
  return ((*this).m__0index==-1);
}

void t_std_collections_Stack_1Tt_mx2_CatchStmt_2_BackwardsIterator::m_AssertSeq(){
  bbDebugAssert(((*this).m__0seq==(*this).m__0stack->m__0seq),BB_T("Concurrent list modification"));
}

void t_std_collections_Stack_1Tt_mx2_CatchStmt_2_BackwardsIterator::m_AssertCurrent(){
  bbDebugAssert(!(*this).m_AtEnd(),BB_T("Invalid list iterator"));
}

int bbCompare(const t_std_collections_Stack_1Tt_mx2_CatchStmt_2_BackwardsIterator&x,const t_std_collections_Stack_1Tt_mx2_CatchStmt_2_BackwardsIterator&y){
  if(int t=bbCompare(x.m__0stack,y.m__0stack)) return t;
  if(int t=bbCompare(x.m__0index,y.m__0index)) return t;
  if(int t=bbCompare(x.m__0seq,y.m__0seq)) return t;
  return 0;
}

void bbGCMark(const t_std_collections_Stack_1Tt_mx2_CatchStmt_2_BackwardsIterator&t){
  bbGCMark(t.m__0stack);
}

void t_std_collections_Stack_1Tt_mx2_CatchStmt_2::gcMark(){
  bbGCMark(m__0data);
}

t_std_collections_Stack_1Tt_mx2_CatchStmt_2::t_std_collections_Stack_1Tt_mx2_CatchStmt_2(t_std_collections_List_1Tt_mx2_CatchStmt_2* l_values){
  g_std_collections_Stack_1Tt_mx2_CatchStmt_2_AddAll_1Tt_std_collections_List_1Tt_mx2_CatchStmt_2_2(this,l_values);
}

t_std_collections_Stack_1Tt_mx2_CatchStmt_2::t_std_collections_Stack_1Tt_mx2_CatchStmt_2(t_std_collections_Stack_1Tt_mx2_CatchStmt_2* l_values){
  struct f0_t : public bbGCFrame{
    bbArray<bbGCVar<t_mx2_CatchStmt>>* t0{};
    void gcMark(){
      bbGCMarkPtr(t0);
    }
  }f0{};
  this->m__0length=l_values->m_Length();
  this->m__0data=bbArray<bbGCVar<t_mx2_CatchStmt>>::create(this->m__0length);
  (f0.t0=l_values->m_Data())->copyTo(this->m__0data,bbInt(0),bbInt(0),this->m__0length);
}

t_std_collections_Stack_1Tt_mx2_CatchStmt_2::t_std_collections_Stack_1Tt_mx2_CatchStmt_2(bbArray<bbGCVar<t_mx2_CatchStmt>>* l_values){
  this->m_AddAll(l_values);
}

t_std_collections_Stack_1Tt_mx2_CatchStmt_2::t_std_collections_Stack_1Tt_mx2_CatchStmt_2(bbInt l_length){
  this->m__0length=l_length;
  this->m__0data=bbArray<bbGCVar<t_mx2_CatchStmt>>::create(this->m__0length);
}

t_std_collections_Stack_1Tt_mx2_CatchStmt_2::t_std_collections_Stack_1Tt_mx2_CatchStmt_2(){
  this->m__0data=bbArray<bbGCVar<t_mx2_CatchStmt>>::create(10);
}

void t_std_collections_Stack_1Tt_mx2_CatchStmt_2::m__idxeq(bbInt l_index,t_mx2_CatchStmt* l_value){
  bbDebugAssert(((l_index>=bbInt(0))&&(l_index<this->m__0length)),BB_T("Stack index out of range"));
  this->m__0data->at(l_index)=l_value;
}

t_mx2_CatchStmt* t_std_collections_Stack_1Tt_mx2_CatchStmt_2::m__idx(bbInt l_index){
  bbDebugAssert(((l_index>=bbInt(0))&&(l_index<this->m__0length)),BB_T("Stack index out of range"));
  return this->m__0data->at(l_index);
}

t_mx2_CatchStmt* t_std_collections_Stack_1Tt_mx2_CatchStmt_2::m_Top(){
  bbDebugAssert(bbBool(this->m__0length),BB_T("Stack is empty"));
  return this->m__0data->at((this->m__0length-1));
}

bbArray<bbGCVar<t_mx2_CatchStmt>>* t_std_collections_Stack_1Tt_mx2_CatchStmt_2::m_ToArray(){
  return this->m__0data->slice(bbInt(0),this->m__0length);
}

void t_std_collections_Stack_1Tt_mx2_CatchStmt_2::m_Swap(bbInt l_index1,bbInt l_index2){
  struct f0_t : public bbGCFrame{
    t_mx2_CatchStmt* l_t{};
    void gcMark(){
      bbGCMarkPtr(l_t);
    }
  }f0{};
  bbDebugAssert(((((l_index1>=bbInt(0))&&(l_index1<this->m__0length))&&(l_index2>=bbInt(0)))&&(l_index2<this->m__0length)),BB_T("Stack index out of range"));
  f0.l_t=this->m__0data->at(l_index1);
  this->m__0data->at(l_index1)=this->m__0data->at(l_index2);
  this->m__0data->at(l_index2)=f0.l_t;
}

void t_std_collections_Stack_1Tt_mx2_CatchStmt_2::m_Sort(bbFunction<bbInt(t_mx2_CatchStmt*,t_mx2_CatchStmt*)> l_compareFunc,bbInt l_lo,bbInt l_hi){
  if((l_hi<=l_lo)){
    return;
  }
  if(((l_lo+1)==l_hi)){
    if((l_compareFunc(this->m__0data->at(l_hi),this->m__0data->at(l_lo))<bbInt(0))){
      this->m_Swap(l_hi,l_lo);
    }
    return;
  }
  bbInt l_i=((l_lo+l_hi)/2);
  if((l_compareFunc(this->m__0data->at(l_i),this->m__0data->at(l_lo))<bbInt(0))){
    this->m_Swap(l_i,l_lo);
  }
  if((l_compareFunc(this->m__0data->at(l_hi),this->m__0data->at(l_i))<bbInt(0))){
    this->m_Swap(l_hi,l_i);
    if((l_compareFunc(this->m__0data->at(l_i),this->m__0data->at(l_lo))<bbInt(0))){
      this->m_Swap(l_i,l_lo);
    }
  }
  bbInt l_x=(l_lo+1);
  bbInt l_y=(l_hi-1);
  do{
    struct f1_t : public bbGCFrame{
      t_mx2_CatchStmt* l_p{};
      void gcMark(){
        bbGCMarkPtr(l_p);
      }
    }f1{};
    f1.l_p=this->m__0data->at(l_i);
    while((l_compareFunc(this->m__0data->at(l_x),f1.l_p)<bbInt(0))){
      l_x+=1;
    }
    while((l_compareFunc(f1.l_p,this->m__0data->at(l_y))<bbInt(0))){
      l_y-=1;
    }
    if((l_x>l_y)){
      break;
    }
    if((l_x<l_y)){
      this->m_Swap(l_x,l_y);
      if((l_i==l_x)){
        l_i=l_y;
      }else if((l_i==l_y)){
        l_i=l_x;
      }
    }
    l_x+=1;
    l_y-=1;
  }while(!((l_x>l_y)));
  this->m_Sort(l_compareFunc,l_lo,l_y);
  this->m_Sort(l_compareFunc,l_x,l_hi);
}

void t_std_collections_Stack_1Tt_mx2_CatchStmt_2::m_Sort(bbFunction<bbInt(t_mx2_CatchStmt*,t_mx2_CatchStmt*)> l_compareFunc){
  this->m_Sort(l_compareFunc,bbInt(0),(this->m__0length-1));
}

void t_std_collections_Stack_1Tt_mx2_CatchStmt_2::m_Sort(bbBool l_ascending){
  if(l_ascending){
    struct lambda50 : public bbFunction<bbInt(t_mx2_CatchStmt*,t_mx2_CatchStmt*)>::Rep{
      t_std_collections_Stack_1Tt_mx2_CatchStmt_2* l_self;
      lambda50(t_std_collections_Stack_1Tt_mx2_CatchStmt_2* l_self):l_self(l_self){
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
      t_std_collections_Stack_1Tt_mx2_CatchStmt_2* l_self;
      lambda51(t_std_collections_Stack_1Tt_mx2_CatchStmt_2* l_self):l_self(l_self){
      }
      bbInt invoke(t_mx2_CatchStmt* l_x,t_mx2_CatchStmt* l_y){
        return bbCompare(l_y,l_x);
      }
      void gcMark(){
        bbGCMarkPtr(l_self);
      }
    };
    this->m_Sort(bbFunction<bbInt(t_mx2_CatchStmt*,t_mx2_CatchStmt*)>(new lambda51(this)));
  }
}

t_std_collections_Stack_1Tt_mx2_CatchStmt_2* t_std_collections_Stack_1Tt_mx2_CatchStmt_2::m_Slice(bbInt l_index1,bbInt l_index2){
  struct f0_t : public bbGCFrame{
    bbArray<bbGCVar<t_mx2_CatchStmt>>* t0{};
    void gcMark(){
      bbGCMarkPtr(t0);
    }
  }f0{};
  if((l_index1<bbInt(0))){
    l_index1=g_monkey_math_Max_1i((l_index1+this->m__0length),bbInt(0));
  }else if((l_index1>this->m__0length)){
    l_index1=this->m__0length;
  }
  if((l_index2<bbInt(0))){
    l_index2=g_monkey_math_Max_1i((l_index2+this->m__0length),l_index1);
  }else if((l_index2>this->m__0length)){
    l_index2=this->m__0length;
  }else if((l_index2<l_index1)){
    l_index2=l_index1;
  }
  return bbGCNew<t_std_collections_Stack_1Tt_mx2_CatchStmt_2>(f0.t0=this->m__0data->slice(l_index1,l_index2));
}

t_std_collections_Stack_1Tt_mx2_CatchStmt_2* t_std_collections_Stack_1Tt_mx2_CatchStmt_2::m_Slice(bbInt l_index){
  return this->m_Slice(l_index,this->m__0length);
}

void t_std_collections_Stack_1Tt_mx2_CatchStmt_2::m_Set(bbInt l_index,t_mx2_CatchStmt* l_value){
  bbDebugAssert(((l_index>=bbInt(0))&&(l_index<this->m__0length)),BB_T("Stack index out of range"));
  this->m__0data->at(l_index)=l_value;
}

void t_std_collections_Stack_1Tt_mx2_CatchStmt_2::m_Resize(bbInt l_length){
  bbDebugAssert((l_length>=bbInt(0)),BB_T("Debug assert failed"));
  {
    bbInt l_i=l_length;
    for(;(l_i<this->m__0length);l_i+=1){
      this->m__0data->at(l_i)=((t_mx2_CatchStmt*)0);
    }
  }
  this->m_Reserve(l_length);
  this->m__0length=l_length;
  this->m__0seq+=1;
}

void t_std_collections_Stack_1Tt_mx2_CatchStmt_2::m_Reserve(bbInt l_capacity){
  struct f0_t : public bbGCFrame{
    bbArray<bbGCVar<t_mx2_CatchStmt>>* l_data{};
    void gcMark(){
      bbGCMarkPtr(l_data);
    }
  }f0{};
  bbDebugAssert((l_capacity>=bbInt(0)),BB_T("Debug assert failed"));
  if((this->m__0data->length()>=l_capacity)){
    return;
  }
  l_capacity=g_monkey_math_Max_1i(((this->m__0length*2)+this->m__0length),l_capacity);
  f0.l_data=bbArray<bbGCVar<t_mx2_CatchStmt>>::create(l_capacity);
  this->m__0data->copyTo(f0.l_data,bbInt(0),bbInt(0),this->m__0length);
  this->m__0data=f0.l_data;
}

bbBool t_std_collections_Stack_1Tt_mx2_CatchStmt_2::m_RemoveLast(t_mx2_CatchStmt* l_value,bbInt l_start){
  bbInt l_i=this->m_FindLastIndex(l_value,l_start);
  if((l_i==-1)){
    return false;
  }
  this->m_Erase(l_i);
  return true;
}

bbInt t_std_collections_Stack_1Tt_mx2_CatchStmt_2::m_RemoveEach(t_mx2_CatchStmt* l_value){
  bbInt l_put=bbInt(0);
  bbInt l_n=bbInt(0);
  {
    bbInt l_get=bbInt(0);
    for(;(l_get<this->m__0length);l_get+=1){
      if((this->m__0data->at(l_get)==l_value)){
        l_n+=1;
        continue;
      }
      this->m__0data->at(l_put)=this->m__0data->at(l_get);
      l_put+=1;
    }
  }
  this->m_Resize(l_put);
  return l_n;
}

bbBool t_std_collections_Stack_1Tt_mx2_CatchStmt_2::m_Remove(t_mx2_CatchStmt* l_value,bbInt l_start){
  bbInt l_i=this->m_FindIndex(l_value,l_start);
  if((l_i==-1)){
    return false;
  }
  this->m_Erase(l_i);
  return true;
}

void t_std_collections_Stack_1Tt_mx2_CatchStmt_2::m_Push(t_mx2_CatchStmt* l_value){
  this->m_Add(l_value);
}

t_mx2_CatchStmt* t_std_collections_Stack_1Tt_mx2_CatchStmt_2::m_Pop(){
  struct f0_t : public bbGCFrame{
    t_mx2_CatchStmt* l_value{};
    void gcMark(){
      bbGCMarkPtr(l_value);
    }
  }f0{};
  bbDebugAssert(bbBool(this->m__0length),BB_T("Stack is empty"));
  this->m__0length-=1;
  this->m__0seq+=1;
  f0.l_value=this->m__0data->at(this->m__0length);
  this->m__0data->at(this->m__0length)=((t_mx2_CatchStmt*)0);
  return f0.l_value;
}

bbInt t_std_collections_Stack_1Tt_mx2_CatchStmt_2::m_Length(){
  return this->m__0length;
}

void t_std_collections_Stack_1Tt_mx2_CatchStmt_2::m_Insert(bbInt l_index,t_mx2_CatchStmt* l_value){
  bbDebugAssert(((l_index>=bbInt(0))&&(l_index<=this->m__0length)),BB_T("Debug assert failed"));
  this->m_Reserve((this->m__0length+1));
  this->m__0data->copyTo(this->m__0data,l_index,(l_index+1),(this->m__0length-l_index));
  this->m__0data->at(l_index)=l_value;
  this->m__0length+=1;
  this->m__0seq+=1;
}

t_mx2_CatchStmt* t_std_collections_Stack_1Tt_mx2_CatchStmt_2::m_Get(bbInt l_index){
  bbDebugAssert(((l_index>=bbInt(0))&&(l_index<this->m__0length)),BB_T("Stack index out of range"));
  return this->m__0data->at(l_index);
}

bbInt t_std_collections_Stack_1Tt_mx2_CatchStmt_2::m_FindLastIndex(t_mx2_CatchStmt* l_value,bbInt l_start){
  bbDebugAssert(((l_start>=bbInt(0))&&(l_start<=this->m__0length)),BB_T("Debug assert failed"));
  bbInt l_i=this->m__0length;
  while((l_i>l_start)){
    l_i-=1;
    if((this->m__0data->at(l_i)==l_value)){
      return l_i;
    }
  }
  return -1;
}

bbInt t_std_collections_Stack_1Tt_mx2_CatchStmt_2::m_FindIndex(t_mx2_CatchStmt* l_value,bbInt l_start){
  bbDebugAssert(((l_start>=bbInt(0))&&(l_start<=this->m__0length)),BB_T("Debug assert failed"));
  bbInt l_i=l_start;
  while((l_i<this->m__0length)){
    if((this->m__0data->at(l_i)==l_value)){
      return l_i;
    }
    l_i+=1;
  }
  return -1;
}

void t_std_collections_Stack_1Tt_mx2_CatchStmt_2::m_Erase(bbInt l_index1,bbInt l_index2){
  bbDebugAssert((((((l_index1>=bbInt(0))&&(l_index1<=this->m__0length))&&(l_index2>=bbInt(0)))&&(l_index2<=this->m__0length))&&(l_index1<=l_index2)),BB_T("Debug assert failed"));
  if((l_index1==this->m__0length)){
    return;
  }
  this->m__0data->copyTo(this->m__0data,l_index2,l_index1,(this->m__0length-l_index2));
  this->m_Resize(((this->m__0length-l_index2)+l_index1));
}

void t_std_collections_Stack_1Tt_mx2_CatchStmt_2::m_Erase(bbInt l_index){
  bbDebugAssert(((l_index>=bbInt(0))&&(l_index<=this->m__0length)),BB_T("Debug assert failed"));
  if((l_index==this->m__0length)){
    return;
  }
  this->m__0data->copyTo(this->m__0data,(l_index+1),l_index,((this->m__0length-l_index)-1));
  this->m_Resize((this->m__0length-1));
}

bbBool t_std_collections_Stack_1Tt_mx2_CatchStmt_2::m_Empty(){
  return (this->m__0length==bbInt(0));
}

bbArray<bbGCVar<t_mx2_CatchStmt>>* t_std_collections_Stack_1Tt_mx2_CatchStmt_2::m_Data(){
  return this->m__0data;
}

bbBool t_std_collections_Stack_1Tt_mx2_CatchStmt_2::m_Contains(t_mx2_CatchStmt* l_value){
  return (this->m_FindIndex(l_value,bbInt(0))!=-1);
}

void t_std_collections_Stack_1Tt_mx2_CatchStmt_2::m_Clear(){
  this->m_Resize(bbInt(0));
}

bbInt t_std_collections_Stack_1Tt_mx2_CatchStmt_2::m_Capacity(){
  return this->m__0data->length();
}

t_std_collections_Stack_1Tt_mx2_CatchStmt_2_BackwardsIterator t_std_collections_Stack_1Tt_mx2_CatchStmt_2::m_Backwards(){
  return t_std_collections_Stack_1Tt_mx2_CatchStmt_2_BackwardsIterator(this,(this->m__0length-1));
}

t_std_collections_Stack_1Tt_mx2_CatchStmt_2_Iterator t_std_collections_Stack_1Tt_mx2_CatchStmt_2::m_All(){
  return t_std_collections_Stack_1Tt_mx2_CatchStmt_2_Iterator(this,bbInt(0));
}

void t_std_collections_Stack_1Tt_mx2_CatchStmt_2::m_AddAll(bbArray<bbGCVar<t_mx2_CatchStmt>>* l_values){
  this->m_Reserve((this->m__0length+l_values->length()));
  l_values->copyTo(this->m__0data,bbInt(0),this->m__0length,l_values->length());
  this->m_Resize((this->m__0length+l_values->length()));
}

void t_std_collections_Stack_1Tt_mx2_CatchStmt_2::m_Add(t_mx2_CatchStmt* l_value){
  this->m_Reserve((this->m__0length+1));
  this->m__0data->at(this->m__0length)=l_value;
  this->m__0length+=1;
  this->m__0seq+=1;
}

t_std_collections_Stack_1Tt_mx2_CaseStmt_2_Iterator::t_std_collections_Stack_1Tt_mx2_CaseStmt_2_Iterator(t_std_collections_Stack_1Tt_mx2_CaseStmt_2* l_stack,bbInt l_index){
  (*this).m__0stack=l_stack;
  (*this).m__0index=l_index;
  (*this).m__0seq=l_stack->m__0seq;
}

void t_std_collections_Stack_1Tt_mx2_CaseStmt_2_Iterator::m_Insert(t_mx2_CaseStmt* l_value){
  (*this).m_AssertSeq();
  (*this).m__0stack->m_Insert((*this).m__0index,l_value);
  (*this).m__0seq=(*this).m__0stack->m__0seq;
}

void t_std_collections_Stack_1Tt_mx2_CaseStmt_2_Iterator::m_Erase(){
  (*this).m_AssertSeq();
  (*this).m__0stack->m_Erase((*this).m__0index);
  (*this).m__0seq=(*this).m__0stack->m__0seq;
}

void t_std_collections_Stack_1Tt_mx2_CaseStmt_2_Iterator::m_Current(t_mx2_CaseStmt* l_current){
  (*this).m_AssertCurrent();
  (*this).m__0stack->m__0data->at((*this).m__0index)=l_current;
}

t_mx2_CaseStmt* t_std_collections_Stack_1Tt_mx2_CaseStmt_2_Iterator::m_Current(){
  (*this).m_AssertCurrent();
  return (*this).m__0stack->m__0data->at((*this).m__0index);
}

void t_std_collections_Stack_1Tt_mx2_CaseStmt_2_Iterator::m_Bump(){
  (*this).m_AssertCurrent();
  (*this).m__0index+=1;
}

bbBool t_std_collections_Stack_1Tt_mx2_CaseStmt_2_Iterator::m_AtEnd(){
  (*this).m_AssertSeq();
  return ((*this).m__0index==(*this).m__0stack->m__0length);
}

void t_std_collections_Stack_1Tt_mx2_CaseStmt_2_Iterator::m_AssertSeq(){
  bbDebugAssert(((*this).m__0seq==(*this).m__0stack->m__0seq),BB_T("Concurrent list modification"));
}

void t_std_collections_Stack_1Tt_mx2_CaseStmt_2_Iterator::m_AssertCurrent(){
  bbDebugAssert(!(*this).m_AtEnd(),BB_T("Invalid list iterator"));
}

int bbCompare(const t_std_collections_Stack_1Tt_mx2_CaseStmt_2_Iterator&x,const t_std_collections_Stack_1Tt_mx2_CaseStmt_2_Iterator&y){
  if(int t=bbCompare(x.m__0stack,y.m__0stack)) return t;
  if(int t=bbCompare(x.m__0index,y.m__0index)) return t;
  if(int t=bbCompare(x.m__0seq,y.m__0seq)) return t;
  return 0;
}

void bbGCMark(const t_std_collections_Stack_1Tt_mx2_CaseStmt_2_Iterator&t){
  bbGCMark(t.m__0stack);
}

t_std_collections_Stack_1Tt_mx2_CaseStmt_2_BackwardsIterator::t_std_collections_Stack_1Tt_mx2_CaseStmt_2_BackwardsIterator(t_std_collections_Stack_1Tt_mx2_CaseStmt_2* l_stack,bbInt l_index){
  (*this).m__0stack=l_stack;
  (*this).m__0index=l_index;
  (*this).m__0seq=l_stack->m__0seq;
}

void t_std_collections_Stack_1Tt_mx2_CaseStmt_2_BackwardsIterator::m_Insert(t_mx2_CaseStmt* l_value){
  (*this).m_AssertSeq();
  (*this).m__0index+=1;
  (*this).m__0stack->m_Insert((*this).m__0index,l_value);
  (*this).m__0seq=(*this).m__0stack->m__0seq;
}

void t_std_collections_Stack_1Tt_mx2_CaseStmt_2_BackwardsIterator::m_Erase(){
  (*this).m_AssertCurrent();
  (*this).m__0index-=1;
  (*this).m__0stack->m_Erase(((*this).m__0index+1));
  (*this).m__0seq=(*this).m__0stack->m__0seq;
}

void t_std_collections_Stack_1Tt_mx2_CaseStmt_2_BackwardsIterator::m_Current(t_mx2_CaseStmt* l_current){
  (*this).m_AssertCurrent();
  (*this).m__0stack->m__0data->at((*this).m__0index)=l_current;
}

t_mx2_CaseStmt* t_std_collections_Stack_1Tt_mx2_CaseStmt_2_BackwardsIterator::m_Current(){
  (*this).m_AssertCurrent();
  return (*this).m__0stack->m__0data->at((*this).m__0index);
}

void t_std_collections_Stack_1Tt_mx2_CaseStmt_2_BackwardsIterator::m_Bump(){
  (*this).m_AssertCurrent();
  (*this).m__0index-=1;
}

bbBool t_std_collections_Stack_1Tt_mx2_CaseStmt_2_BackwardsIterator::m_AtEnd(){
  (*this).m_AssertSeq();
  return ((*this).m__0index==-1);
}

void t_std_collections_Stack_1Tt_mx2_CaseStmt_2_BackwardsIterator::m_AssertSeq(){
  bbDebugAssert(((*this).m__0seq==(*this).m__0stack->m__0seq),BB_T("Concurrent list modification"));
}

void t_std_collections_Stack_1Tt_mx2_CaseStmt_2_BackwardsIterator::m_AssertCurrent(){
  bbDebugAssert(!(*this).m_AtEnd(),BB_T("Invalid list iterator"));
}

int bbCompare(const t_std_collections_Stack_1Tt_mx2_CaseStmt_2_BackwardsIterator&x,const t_std_collections_Stack_1Tt_mx2_CaseStmt_2_BackwardsIterator&y){
  if(int t=bbCompare(x.m__0stack,y.m__0stack)) return t;
  if(int t=bbCompare(x.m__0index,y.m__0index)) return t;
  if(int t=bbCompare(x.m__0seq,y.m__0seq)) return t;
  return 0;
}

void bbGCMark(const t_std_collections_Stack_1Tt_mx2_CaseStmt_2_BackwardsIterator&t){
  bbGCMark(t.m__0stack);
}

void t_std_collections_Stack_1Tt_mx2_CaseStmt_2::gcMark(){
  bbGCMark(m__0data);
}

t_std_collections_Stack_1Tt_mx2_CaseStmt_2::t_std_collections_Stack_1Tt_mx2_CaseStmt_2(t_std_collections_List_1Tt_mx2_CaseStmt_2* l_values){
  g_std_collections_Stack_1Tt_mx2_CaseStmt_2_AddAll_1Tt_std_collections_List_1Tt_mx2_CaseStmt_2_2(this,l_values);
}

t_std_collections_Stack_1Tt_mx2_CaseStmt_2::t_std_collections_Stack_1Tt_mx2_CaseStmt_2(t_std_collections_Stack_1Tt_mx2_CaseStmt_2* l_values){
  struct f0_t : public bbGCFrame{
    bbArray<bbGCVar<t_mx2_CaseStmt>>* t0{};
    void gcMark(){
      bbGCMarkPtr(t0);
    }
  }f0{};
  this->m__0length=l_values->m_Length();
  this->m__0data=bbArray<bbGCVar<t_mx2_CaseStmt>>::create(this->m__0length);
  (f0.t0=l_values->m_Data())->copyTo(this->m__0data,bbInt(0),bbInt(0),this->m__0length);
}

t_std_collections_Stack_1Tt_mx2_CaseStmt_2::t_std_collections_Stack_1Tt_mx2_CaseStmt_2(bbArray<bbGCVar<t_mx2_CaseStmt>>* l_values){
  this->m_AddAll(l_values);
}

t_std_collections_Stack_1Tt_mx2_CaseStmt_2::t_std_collections_Stack_1Tt_mx2_CaseStmt_2(bbInt l_length){
  this->m__0length=l_length;
  this->m__0data=bbArray<bbGCVar<t_mx2_CaseStmt>>::create(this->m__0length);
}

t_std_collections_Stack_1Tt_mx2_CaseStmt_2::t_std_collections_Stack_1Tt_mx2_CaseStmt_2(){
  this->m__0data=bbArray<bbGCVar<t_mx2_CaseStmt>>::create(10);
}

void t_std_collections_Stack_1Tt_mx2_CaseStmt_2::m__idxeq(bbInt l_index,t_mx2_CaseStmt* l_value){
  bbDebugAssert(((l_index>=bbInt(0))&&(l_index<this->m__0length)),BB_T("Stack index out of range"));
  this->m__0data->at(l_index)=l_value;
}

t_mx2_CaseStmt* t_std_collections_Stack_1Tt_mx2_CaseStmt_2::m__idx(bbInt l_index){
  bbDebugAssert(((l_index>=bbInt(0))&&(l_index<this->m__0length)),BB_T("Stack index out of range"));
  return this->m__0data->at(l_index);
}

t_mx2_CaseStmt* t_std_collections_Stack_1Tt_mx2_CaseStmt_2::m_Top(){
  bbDebugAssert(bbBool(this->m__0length),BB_T("Stack is empty"));
  return this->m__0data->at((this->m__0length-1));
}

bbArray<bbGCVar<t_mx2_CaseStmt>>* t_std_collections_Stack_1Tt_mx2_CaseStmt_2::m_ToArray(){
  return this->m__0data->slice(bbInt(0),this->m__0length);
}

void t_std_collections_Stack_1Tt_mx2_CaseStmt_2::m_Swap(bbInt l_index1,bbInt l_index2){
  struct f0_t : public bbGCFrame{
    t_mx2_CaseStmt* l_t{};
    void gcMark(){
      bbGCMarkPtr(l_t);
    }
  }f0{};
  bbDebugAssert(((((l_index1>=bbInt(0))&&(l_index1<this->m__0length))&&(l_index2>=bbInt(0)))&&(l_index2<this->m__0length)),BB_T("Stack index out of range"));
  f0.l_t=this->m__0data->at(l_index1);
  this->m__0data->at(l_index1)=this->m__0data->at(l_index2);
  this->m__0data->at(l_index2)=f0.l_t;
}

void t_std_collections_Stack_1Tt_mx2_CaseStmt_2::m_Sort(bbFunction<bbInt(t_mx2_CaseStmt*,t_mx2_CaseStmt*)> l_compareFunc,bbInt l_lo,bbInt l_hi){
  if((l_hi<=l_lo)){
    return;
  }
  if(((l_lo+1)==l_hi)){
    if((l_compareFunc(this->m__0data->at(l_hi),this->m__0data->at(l_lo))<bbInt(0))){
      this->m_Swap(l_hi,l_lo);
    }
    return;
  }
  bbInt l_i=((l_lo+l_hi)/2);
  if((l_compareFunc(this->m__0data->at(l_i),this->m__0data->at(l_lo))<bbInt(0))){
    this->m_Swap(l_i,l_lo);
  }
  if((l_compareFunc(this->m__0data->at(l_hi),this->m__0data->at(l_i))<bbInt(0))){
    this->m_Swap(l_hi,l_i);
    if((l_compareFunc(this->m__0data->at(l_i),this->m__0data->at(l_lo))<bbInt(0))){
      this->m_Swap(l_i,l_lo);
    }
  }
  bbInt l_x=(l_lo+1);
  bbInt l_y=(l_hi-1);
  do{
    struct f1_t : public bbGCFrame{
      t_mx2_CaseStmt* l_p{};
      void gcMark(){
        bbGCMarkPtr(l_p);
      }
    }f1{};
    f1.l_p=this->m__0data->at(l_i);
    while((l_compareFunc(this->m__0data->at(l_x),f1.l_p)<bbInt(0))){
      l_x+=1;
    }
    while((l_compareFunc(f1.l_p,this->m__0data->at(l_y))<bbInt(0))){
      l_y-=1;
    }
    if((l_x>l_y)){
      break;
    }
    if((l_x<l_y)){
      this->m_Swap(l_x,l_y);
      if((l_i==l_x)){
        l_i=l_y;
      }else if((l_i==l_y)){
        l_i=l_x;
      }
    }
    l_x+=1;
    l_y-=1;
  }while(!((l_x>l_y)));
  this->m_Sort(l_compareFunc,l_lo,l_y);
  this->m_Sort(l_compareFunc,l_x,l_hi);
}

void t_std_collections_Stack_1Tt_mx2_CaseStmt_2::m_Sort(bbFunction<bbInt(t_mx2_CaseStmt*,t_mx2_CaseStmt*)> l_compareFunc){
  this->m_Sort(l_compareFunc,bbInt(0),(this->m__0length-1));
}

void t_std_collections_Stack_1Tt_mx2_CaseStmt_2::m_Sort(bbBool l_ascending){
  if(l_ascending){
    struct lambda52 : public bbFunction<bbInt(t_mx2_CaseStmt*,t_mx2_CaseStmt*)>::Rep{
      t_std_collections_Stack_1Tt_mx2_CaseStmt_2* l_self;
      lambda52(t_std_collections_Stack_1Tt_mx2_CaseStmt_2* l_self):l_self(l_self){
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
      t_std_collections_Stack_1Tt_mx2_CaseStmt_2* l_self;
      lambda53(t_std_collections_Stack_1Tt_mx2_CaseStmt_2* l_self):l_self(l_self){
      }
      bbInt invoke(t_mx2_CaseStmt* l_x,t_mx2_CaseStmt* l_y){
        return bbCompare(l_y,l_x);
      }
      void gcMark(){
        bbGCMarkPtr(l_self);
      }
    };
    this->m_Sort(bbFunction<bbInt(t_mx2_CaseStmt*,t_mx2_CaseStmt*)>(new lambda53(this)));
  }
}

t_std_collections_Stack_1Tt_mx2_CaseStmt_2* t_std_collections_Stack_1Tt_mx2_CaseStmt_2::m_Slice(bbInt l_index1,bbInt l_index2){
  struct f0_t : public bbGCFrame{
    bbArray<bbGCVar<t_mx2_CaseStmt>>* t0{};
    void gcMark(){
      bbGCMarkPtr(t0);
    }
  }f0{};
  if((l_index1<bbInt(0))){
    l_index1=g_monkey_math_Max_1i((l_index1+this->m__0length),bbInt(0));
  }else if((l_index1>this->m__0length)){
    l_index1=this->m__0length;
  }
  if((l_index2<bbInt(0))){
    l_index2=g_monkey_math_Max_1i((l_index2+this->m__0length),l_index1);
  }else if((l_index2>this->m__0length)){
    l_index2=this->m__0length;
  }else if((l_index2<l_index1)){
    l_index2=l_index1;
  }
  return bbGCNew<t_std_collections_Stack_1Tt_mx2_CaseStmt_2>(f0.t0=this->m__0data->slice(l_index1,l_index2));
}

t_std_collections_Stack_1Tt_mx2_CaseStmt_2* t_std_collections_Stack_1Tt_mx2_CaseStmt_2::m_Slice(bbInt l_index){
  return this->m_Slice(l_index,this->m__0length);
}

void t_std_collections_Stack_1Tt_mx2_CaseStmt_2::m_Set(bbInt l_index,t_mx2_CaseStmt* l_value){
  bbDebugAssert(((l_index>=bbInt(0))&&(l_index<this->m__0length)),BB_T("Stack index out of range"));
  this->m__0data->at(l_index)=l_value;
}

void t_std_collections_Stack_1Tt_mx2_CaseStmt_2::m_Resize(bbInt l_length){
  bbDebugAssert((l_length>=bbInt(0)),BB_T("Debug assert failed"));
  {
    bbInt l_i=l_length;
    for(;(l_i<this->m__0length);l_i+=1){
      this->m__0data->at(l_i)=((t_mx2_CaseStmt*)0);
    }
  }
  this->m_Reserve(l_length);
  this->m__0length=l_length;
  this->m__0seq+=1;
}

void t_std_collections_Stack_1Tt_mx2_CaseStmt_2::m_Reserve(bbInt l_capacity){
  struct f0_t : public bbGCFrame{
    bbArray<bbGCVar<t_mx2_CaseStmt>>* l_data{};
    void gcMark(){
      bbGCMarkPtr(l_data);
    }
  }f0{};
  bbDebugAssert((l_capacity>=bbInt(0)),BB_T("Debug assert failed"));
  if((this->m__0data->length()>=l_capacity)){
    return;
  }
  l_capacity=g_monkey_math_Max_1i(((this->m__0length*2)+this->m__0length),l_capacity);
  f0.l_data=bbArray<bbGCVar<t_mx2_CaseStmt>>::create(l_capacity);
  this->m__0data->copyTo(f0.l_data,bbInt(0),bbInt(0),this->m__0length);
  this->m__0data=f0.l_data;
}

bbBool t_std_collections_Stack_1Tt_mx2_CaseStmt_2::m_RemoveLast(t_mx2_CaseStmt* l_value,bbInt l_start){
  bbInt l_i=this->m_FindLastIndex(l_value,l_start);
  if((l_i==-1)){
    return false;
  }
  this->m_Erase(l_i);
  return true;
}

bbInt t_std_collections_Stack_1Tt_mx2_CaseStmt_2::m_RemoveEach(t_mx2_CaseStmt* l_value){
  bbInt l_put=bbInt(0);
  bbInt l_n=bbInt(0);
  {
    bbInt l_get=bbInt(0);
    for(;(l_get<this->m__0length);l_get+=1){
      if((this->m__0data->at(l_get)==l_value)){
        l_n+=1;
        continue;
      }
      this->m__0data->at(l_put)=this->m__0data->at(l_get);
      l_put+=1;
    }
  }
  this->m_Resize(l_put);
  return l_n;
}

bbBool t_std_collections_Stack_1Tt_mx2_CaseStmt_2::m_Remove(t_mx2_CaseStmt* l_value,bbInt l_start){
  bbInt l_i=this->m_FindIndex(l_value,l_start);
  if((l_i==-1)){
    return false;
  }
  this->m_Erase(l_i);
  return true;
}

void t_std_collections_Stack_1Tt_mx2_CaseStmt_2::m_Push(t_mx2_CaseStmt* l_value){
  this->m_Add(l_value);
}

t_mx2_CaseStmt* t_std_collections_Stack_1Tt_mx2_CaseStmt_2::m_Pop(){
  struct f0_t : public bbGCFrame{
    t_mx2_CaseStmt* l_value{};
    void gcMark(){
      bbGCMarkPtr(l_value);
    }
  }f0{};
  bbDebugAssert(bbBool(this->m__0length),BB_T("Stack is empty"));
  this->m__0length-=1;
  this->m__0seq+=1;
  f0.l_value=this->m__0data->at(this->m__0length);
  this->m__0data->at(this->m__0length)=((t_mx2_CaseStmt*)0);
  return f0.l_value;
}

bbInt t_std_collections_Stack_1Tt_mx2_CaseStmt_2::m_Length(){
  return this->m__0length;
}

void t_std_collections_Stack_1Tt_mx2_CaseStmt_2::m_Insert(bbInt l_index,t_mx2_CaseStmt* l_value){
  bbDebugAssert(((l_index>=bbInt(0))&&(l_index<=this->m__0length)),BB_T("Debug assert failed"));
  this->m_Reserve((this->m__0length+1));
  this->m__0data->copyTo(this->m__0data,l_index,(l_index+1),(this->m__0length-l_index));
  this->m__0data->at(l_index)=l_value;
  this->m__0length+=1;
  this->m__0seq+=1;
}

t_mx2_CaseStmt* t_std_collections_Stack_1Tt_mx2_CaseStmt_2::m_Get(bbInt l_index){
  bbDebugAssert(((l_index>=bbInt(0))&&(l_index<this->m__0length)),BB_T("Stack index out of range"));
  return this->m__0data->at(l_index);
}

bbInt t_std_collections_Stack_1Tt_mx2_CaseStmt_2::m_FindLastIndex(t_mx2_CaseStmt* l_value,bbInt l_start){
  bbDebugAssert(((l_start>=bbInt(0))&&(l_start<=this->m__0length)),BB_T("Debug assert failed"));
  bbInt l_i=this->m__0length;
  while((l_i>l_start)){
    l_i-=1;
    if((this->m__0data->at(l_i)==l_value)){
      return l_i;
    }
  }
  return -1;
}

bbInt t_std_collections_Stack_1Tt_mx2_CaseStmt_2::m_FindIndex(t_mx2_CaseStmt* l_value,bbInt l_start){
  bbDebugAssert(((l_start>=bbInt(0))&&(l_start<=this->m__0length)),BB_T("Debug assert failed"));
  bbInt l_i=l_start;
  while((l_i<this->m__0length)){
    if((this->m__0data->at(l_i)==l_value)){
      return l_i;
    }
    l_i+=1;
  }
  return -1;
}

void t_std_collections_Stack_1Tt_mx2_CaseStmt_2::m_Erase(bbInt l_index1,bbInt l_index2){
  bbDebugAssert((((((l_index1>=bbInt(0))&&(l_index1<=this->m__0length))&&(l_index2>=bbInt(0)))&&(l_index2<=this->m__0length))&&(l_index1<=l_index2)),BB_T("Debug assert failed"));
  if((l_index1==this->m__0length)){
    return;
  }
  this->m__0data->copyTo(this->m__0data,l_index2,l_index1,(this->m__0length-l_index2));
  this->m_Resize(((this->m__0length-l_index2)+l_index1));
}

void t_std_collections_Stack_1Tt_mx2_CaseStmt_2::m_Erase(bbInt l_index){
  bbDebugAssert(((l_index>=bbInt(0))&&(l_index<=this->m__0length)),BB_T("Debug assert failed"));
  if((l_index==this->m__0length)){
    return;
  }
  this->m__0data->copyTo(this->m__0data,(l_index+1),l_index,((this->m__0length-l_index)-1));
  this->m_Resize((this->m__0length-1));
}

bbBool t_std_collections_Stack_1Tt_mx2_CaseStmt_2::m_Empty(){
  return (this->m__0length==bbInt(0));
}

bbArray<bbGCVar<t_mx2_CaseStmt>>* t_std_collections_Stack_1Tt_mx2_CaseStmt_2::m_Data(){
  return this->m__0data;
}

bbBool t_std_collections_Stack_1Tt_mx2_CaseStmt_2::m_Contains(t_mx2_CaseStmt* l_value){
  return (this->m_FindIndex(l_value,bbInt(0))!=-1);
}

void t_std_collections_Stack_1Tt_mx2_CaseStmt_2::m_Clear(){
  this->m_Resize(bbInt(0));
}

bbInt t_std_collections_Stack_1Tt_mx2_CaseStmt_2::m_Capacity(){
  return this->m__0data->length();
}

t_std_collections_Stack_1Tt_mx2_CaseStmt_2_BackwardsIterator t_std_collections_Stack_1Tt_mx2_CaseStmt_2::m_Backwards(){
  return t_std_collections_Stack_1Tt_mx2_CaseStmt_2_BackwardsIterator(this,(this->m__0length-1));
}

t_std_collections_Stack_1Tt_mx2_CaseStmt_2_Iterator t_std_collections_Stack_1Tt_mx2_CaseStmt_2::m_All(){
  return t_std_collections_Stack_1Tt_mx2_CaseStmt_2_Iterator(this,bbInt(0));
}

void t_std_collections_Stack_1Tt_mx2_CaseStmt_2::m_AddAll(bbArray<bbGCVar<t_mx2_CaseStmt>>* l_values){
  this->m_Reserve((this->m__0length+l_values->length()));
  l_values->copyTo(this->m__0data,bbInt(0),this->m__0length,l_values->length());
  this->m_Resize((this->m__0length+l_values->length()));
}

void t_std_collections_Stack_1Tt_mx2_CaseStmt_2::m_Add(t_mx2_CaseStmt* l_value){
  this->m_Reserve((this->m__0length+1));
  this->m__0data->at(this->m__0length)=l_value;
  this->m__0length+=1;
  this->m__0seq+=1;
}

t_std_collections_Stack_1Tt_mx2_FuncList_2_Iterator::t_std_collections_Stack_1Tt_mx2_FuncList_2_Iterator(t_std_collections_Stack_1Tt_mx2_FuncList_2* l_stack,bbInt l_index){
  (*this).m__0stack=l_stack;
  (*this).m__0index=l_index;
  (*this).m__0seq=l_stack->m__0seq;
}

void t_std_collections_Stack_1Tt_mx2_FuncList_2_Iterator::m_Insert(t_mx2_FuncList* l_value){
  (*this).m_AssertSeq();
  (*this).m__0stack->m_Insert((*this).m__0index,l_value);
  (*this).m__0seq=(*this).m__0stack->m__0seq;
}

void t_std_collections_Stack_1Tt_mx2_FuncList_2_Iterator::m_Erase(){
  (*this).m_AssertSeq();
  (*this).m__0stack->m_Erase((*this).m__0index);
  (*this).m__0seq=(*this).m__0stack->m__0seq;
}

void t_std_collections_Stack_1Tt_mx2_FuncList_2_Iterator::m_Current(t_mx2_FuncList* l_current){
  (*this).m_AssertCurrent();
  (*this).m__0stack->m__0data->at((*this).m__0index)=l_current;
}

t_mx2_FuncList* t_std_collections_Stack_1Tt_mx2_FuncList_2_Iterator::m_Current(){
  (*this).m_AssertCurrent();
  return (*this).m__0stack->m__0data->at((*this).m__0index);
}

void t_std_collections_Stack_1Tt_mx2_FuncList_2_Iterator::m_Bump(){
  (*this).m_AssertCurrent();
  (*this).m__0index+=1;
}

bbBool t_std_collections_Stack_1Tt_mx2_FuncList_2_Iterator::m_AtEnd(){
  (*this).m_AssertSeq();
  return ((*this).m__0index==(*this).m__0stack->m__0length);
}

void t_std_collections_Stack_1Tt_mx2_FuncList_2_Iterator::m_AssertSeq(){
  bbDebugAssert(((*this).m__0seq==(*this).m__0stack->m__0seq),BB_T("Concurrent list modification"));
}

void t_std_collections_Stack_1Tt_mx2_FuncList_2_Iterator::m_AssertCurrent(){
  bbDebugAssert(!(*this).m_AtEnd(),BB_T("Invalid list iterator"));
}

int bbCompare(const t_std_collections_Stack_1Tt_mx2_FuncList_2_Iterator&x,const t_std_collections_Stack_1Tt_mx2_FuncList_2_Iterator&y){
  if(int t=bbCompare(x.m__0stack,y.m__0stack)) return t;
  if(int t=bbCompare(x.m__0index,y.m__0index)) return t;
  if(int t=bbCompare(x.m__0seq,y.m__0seq)) return t;
  return 0;
}

void bbGCMark(const t_std_collections_Stack_1Tt_mx2_FuncList_2_Iterator&t){
  bbGCMark(t.m__0stack);
}

t_std_collections_Stack_1Tt_mx2_FuncList_2_BackwardsIterator::t_std_collections_Stack_1Tt_mx2_FuncList_2_BackwardsIterator(t_std_collections_Stack_1Tt_mx2_FuncList_2* l_stack,bbInt l_index){
  (*this).m__0stack=l_stack;
  (*this).m__0index=l_index;
  (*this).m__0seq=l_stack->m__0seq;
}

void t_std_collections_Stack_1Tt_mx2_FuncList_2_BackwardsIterator::m_Insert(t_mx2_FuncList* l_value){
  (*this).m_AssertSeq();
  (*this).m__0index+=1;
  (*this).m__0stack->m_Insert((*this).m__0index,l_value);
  (*this).m__0seq=(*this).m__0stack->m__0seq;
}

void t_std_collections_Stack_1Tt_mx2_FuncList_2_BackwardsIterator::m_Erase(){
  (*this).m_AssertCurrent();
  (*this).m__0index-=1;
  (*this).m__0stack->m_Erase(((*this).m__0index+1));
  (*this).m__0seq=(*this).m__0stack->m__0seq;
}

void t_std_collections_Stack_1Tt_mx2_FuncList_2_BackwardsIterator::m_Current(t_mx2_FuncList* l_current){
  (*this).m_AssertCurrent();
  (*this).m__0stack->m__0data->at((*this).m__0index)=l_current;
}

t_mx2_FuncList* t_std_collections_Stack_1Tt_mx2_FuncList_2_BackwardsIterator::m_Current(){
  (*this).m_AssertCurrent();
  return (*this).m__0stack->m__0data->at((*this).m__0index);
}

void t_std_collections_Stack_1Tt_mx2_FuncList_2_BackwardsIterator::m_Bump(){
  (*this).m_AssertCurrent();
  (*this).m__0index-=1;
}

bbBool t_std_collections_Stack_1Tt_mx2_FuncList_2_BackwardsIterator::m_AtEnd(){
  (*this).m_AssertSeq();
  return ((*this).m__0index==-1);
}

void t_std_collections_Stack_1Tt_mx2_FuncList_2_BackwardsIterator::m_AssertSeq(){
  bbDebugAssert(((*this).m__0seq==(*this).m__0stack->m__0seq),BB_T("Concurrent list modification"));
}

void t_std_collections_Stack_1Tt_mx2_FuncList_2_BackwardsIterator::m_AssertCurrent(){
  bbDebugAssert(!(*this).m_AtEnd(),BB_T("Invalid list iterator"));
}

int bbCompare(const t_std_collections_Stack_1Tt_mx2_FuncList_2_BackwardsIterator&x,const t_std_collections_Stack_1Tt_mx2_FuncList_2_BackwardsIterator&y){
  if(int t=bbCompare(x.m__0stack,y.m__0stack)) return t;
  if(int t=bbCompare(x.m__0index,y.m__0index)) return t;
  if(int t=bbCompare(x.m__0seq,y.m__0seq)) return t;
  return 0;
}

void bbGCMark(const t_std_collections_Stack_1Tt_mx2_FuncList_2_BackwardsIterator&t){
  bbGCMark(t.m__0stack);
}

void t_std_collections_Stack_1Tt_mx2_FuncList_2::gcMark(){
  bbGCMark(m__0data);
}

t_std_collections_Stack_1Tt_mx2_FuncList_2::t_std_collections_Stack_1Tt_mx2_FuncList_2(t_std_collections_List_1Tt_mx2_FuncList_2* l_values){
  g_std_collections_Stack_1Tt_mx2_FuncList_2_AddAll_1Tt_std_collections_List_1Tt_mx2_FuncList_2_2(this,l_values);
}

t_std_collections_Stack_1Tt_mx2_FuncList_2::t_std_collections_Stack_1Tt_mx2_FuncList_2(t_std_collections_Stack_1Tt_mx2_FuncList_2* l_values){
  struct f0_t : public bbGCFrame{
    bbArray<bbGCVar<t_mx2_FuncList>>* t0{};
    void gcMark(){
      bbGCMarkPtr(t0);
    }
  }f0{};
  this->m__0length=l_values->m_Length();
  this->m__0data=bbArray<bbGCVar<t_mx2_FuncList>>::create(this->m__0length);
  (f0.t0=l_values->m_Data())->copyTo(this->m__0data,bbInt(0),bbInt(0),this->m__0length);
}

t_std_collections_Stack_1Tt_mx2_FuncList_2::t_std_collections_Stack_1Tt_mx2_FuncList_2(bbArray<bbGCVar<t_mx2_FuncList>>* l_values){
  this->m_AddAll(l_values);
}

t_std_collections_Stack_1Tt_mx2_FuncList_2::t_std_collections_Stack_1Tt_mx2_FuncList_2(bbInt l_length){
  this->m__0length=l_length;
  this->m__0data=bbArray<bbGCVar<t_mx2_FuncList>>::create(this->m__0length);
}

t_std_collections_Stack_1Tt_mx2_FuncList_2::t_std_collections_Stack_1Tt_mx2_FuncList_2(){
  this->m__0data=bbArray<bbGCVar<t_mx2_FuncList>>::create(10);
}

void t_std_collections_Stack_1Tt_mx2_FuncList_2::m__idxeq(bbInt l_index,t_mx2_FuncList* l_value){
  bbDebugAssert(((l_index>=bbInt(0))&&(l_index<this->m__0length)),BB_T("Stack index out of range"));
  this->m__0data->at(l_index)=l_value;
}

t_mx2_FuncList* t_std_collections_Stack_1Tt_mx2_FuncList_2::m__idx(bbInt l_index){
  bbDebugAssert(((l_index>=bbInt(0))&&(l_index<this->m__0length)),BB_T("Stack index out of range"));
  return this->m__0data->at(l_index);
}

t_mx2_FuncList* t_std_collections_Stack_1Tt_mx2_FuncList_2::m_Top(){
  bbDebugAssert(bbBool(this->m__0length),BB_T("Stack is empty"));
  return this->m__0data->at((this->m__0length-1));
}

bbArray<bbGCVar<t_mx2_FuncList>>* t_std_collections_Stack_1Tt_mx2_FuncList_2::m_ToArray(){
  return this->m__0data->slice(bbInt(0),this->m__0length);
}

void t_std_collections_Stack_1Tt_mx2_FuncList_2::m_Swap(bbInt l_index1,bbInt l_index2){
  struct f0_t : public bbGCFrame{
    t_mx2_FuncList* l_t{};
    void gcMark(){
      bbGCMarkPtr(l_t);
    }
  }f0{};
  bbDebugAssert(((((l_index1>=bbInt(0))&&(l_index1<this->m__0length))&&(l_index2>=bbInt(0)))&&(l_index2<this->m__0length)),BB_T("Stack index out of range"));
  f0.l_t=this->m__0data->at(l_index1);
  this->m__0data->at(l_index1)=this->m__0data->at(l_index2);
  this->m__0data->at(l_index2)=f0.l_t;
}

void t_std_collections_Stack_1Tt_mx2_FuncList_2::m_Sort(bbFunction<bbInt(t_mx2_FuncList*,t_mx2_FuncList*)> l_compareFunc,bbInt l_lo,bbInt l_hi){
  if((l_hi<=l_lo)){
    return;
  }
  if(((l_lo+1)==l_hi)){
    if((l_compareFunc(this->m__0data->at(l_hi),this->m__0data->at(l_lo))<bbInt(0))){
      this->m_Swap(l_hi,l_lo);
    }
    return;
  }
  bbInt l_i=((l_lo+l_hi)/2);
  if((l_compareFunc(this->m__0data->at(l_i),this->m__0data->at(l_lo))<bbInt(0))){
    this->m_Swap(l_i,l_lo);
  }
  if((l_compareFunc(this->m__0data->at(l_hi),this->m__0data->at(l_i))<bbInt(0))){
    this->m_Swap(l_hi,l_i);
    if((l_compareFunc(this->m__0data->at(l_i),this->m__0data->at(l_lo))<bbInt(0))){
      this->m_Swap(l_i,l_lo);
    }
  }
  bbInt l_x=(l_lo+1);
  bbInt l_y=(l_hi-1);
  do{
    struct f1_t : public bbGCFrame{
      t_mx2_FuncList* l_p{};
      void gcMark(){
        bbGCMarkPtr(l_p);
      }
    }f1{};
    f1.l_p=this->m__0data->at(l_i);
    while((l_compareFunc(this->m__0data->at(l_x),f1.l_p)<bbInt(0))){
      l_x+=1;
    }
    while((l_compareFunc(f1.l_p,this->m__0data->at(l_y))<bbInt(0))){
      l_y-=1;
    }
    if((l_x>l_y)){
      break;
    }
    if((l_x<l_y)){
      this->m_Swap(l_x,l_y);
      if((l_i==l_x)){
        l_i=l_y;
      }else if((l_i==l_y)){
        l_i=l_x;
      }
    }
    l_x+=1;
    l_y-=1;
  }while(!((l_x>l_y)));
  this->m_Sort(l_compareFunc,l_lo,l_y);
  this->m_Sort(l_compareFunc,l_x,l_hi);
}

void t_std_collections_Stack_1Tt_mx2_FuncList_2::m_Sort(bbFunction<bbInt(t_mx2_FuncList*,t_mx2_FuncList*)> l_compareFunc){
  this->m_Sort(l_compareFunc,bbInt(0),(this->m__0length-1));
}

void t_std_collections_Stack_1Tt_mx2_FuncList_2::m_Sort(bbBool l_ascending){
  if(l_ascending){
    struct lambda54 : public bbFunction<bbInt(t_mx2_FuncList*,t_mx2_FuncList*)>::Rep{
      t_std_collections_Stack_1Tt_mx2_FuncList_2* l_self;
      lambda54(t_std_collections_Stack_1Tt_mx2_FuncList_2* l_self):l_self(l_self){
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
      t_std_collections_Stack_1Tt_mx2_FuncList_2* l_self;
      lambda55(t_std_collections_Stack_1Tt_mx2_FuncList_2* l_self):l_self(l_self){
      }
      bbInt invoke(t_mx2_FuncList* l_x,t_mx2_FuncList* l_y){
        return bbCompare(l_y,l_x);
      }
      void gcMark(){
        bbGCMarkPtr(l_self);
      }
    };
    this->m_Sort(bbFunction<bbInt(t_mx2_FuncList*,t_mx2_FuncList*)>(new lambda55(this)));
  }
}

t_std_collections_Stack_1Tt_mx2_FuncList_2* t_std_collections_Stack_1Tt_mx2_FuncList_2::m_Slice(bbInt l_index1,bbInt l_index2){
  struct f0_t : public bbGCFrame{
    bbArray<bbGCVar<t_mx2_FuncList>>* t0{};
    void gcMark(){
      bbGCMarkPtr(t0);
    }
  }f0{};
  if((l_index1<bbInt(0))){
    l_index1=g_monkey_math_Max_1i((l_index1+this->m__0length),bbInt(0));
  }else if((l_index1>this->m__0length)){
    l_index1=this->m__0length;
  }
  if((l_index2<bbInt(0))){
    l_index2=g_monkey_math_Max_1i((l_index2+this->m__0length),l_index1);
  }else if((l_index2>this->m__0length)){
    l_index2=this->m__0length;
  }else if((l_index2<l_index1)){
    l_index2=l_index1;
  }
  return bbGCNew<t_std_collections_Stack_1Tt_mx2_FuncList_2>(f0.t0=this->m__0data->slice(l_index1,l_index2));
}

t_std_collections_Stack_1Tt_mx2_FuncList_2* t_std_collections_Stack_1Tt_mx2_FuncList_2::m_Slice(bbInt l_index){
  return this->m_Slice(l_index,this->m__0length);
}

void t_std_collections_Stack_1Tt_mx2_FuncList_2::m_Set(bbInt l_index,t_mx2_FuncList* l_value){
  bbDebugAssert(((l_index>=bbInt(0))&&(l_index<this->m__0length)),BB_T("Stack index out of range"));
  this->m__0data->at(l_index)=l_value;
}

void t_std_collections_Stack_1Tt_mx2_FuncList_2::m_Resize(bbInt l_length){
  bbDebugAssert((l_length>=bbInt(0)),BB_T("Debug assert failed"));
  {
    bbInt l_i=l_length;
    for(;(l_i<this->m__0length);l_i+=1){
      this->m__0data->at(l_i)=((t_mx2_FuncList*)0);
    }
  }
  this->m_Reserve(l_length);
  this->m__0length=l_length;
  this->m__0seq+=1;
}

void t_std_collections_Stack_1Tt_mx2_FuncList_2::m_Reserve(bbInt l_capacity){
  struct f0_t : public bbGCFrame{
    bbArray<bbGCVar<t_mx2_FuncList>>* l_data{};
    void gcMark(){
      bbGCMarkPtr(l_data);
    }
  }f0{};
  bbDebugAssert((l_capacity>=bbInt(0)),BB_T("Debug assert failed"));
  if((this->m__0data->length()>=l_capacity)){
    return;
  }
  l_capacity=g_monkey_math_Max_1i(((this->m__0length*2)+this->m__0length),l_capacity);
  f0.l_data=bbArray<bbGCVar<t_mx2_FuncList>>::create(l_capacity);
  this->m__0data->copyTo(f0.l_data,bbInt(0),bbInt(0),this->m__0length);
  this->m__0data=f0.l_data;
}

bbBool t_std_collections_Stack_1Tt_mx2_FuncList_2::m_RemoveLast(t_mx2_FuncList* l_value,bbInt l_start){
  bbInt l_i=this->m_FindLastIndex(l_value,l_start);
  if((l_i==-1)){
    return false;
  }
  this->m_Erase(l_i);
  return true;
}

bbInt t_std_collections_Stack_1Tt_mx2_FuncList_2::m_RemoveEach(t_mx2_FuncList* l_value){
  bbInt l_put=bbInt(0);
  bbInt l_n=bbInt(0);
  {
    bbInt l_get=bbInt(0);
    for(;(l_get<this->m__0length);l_get+=1){
      if((this->m__0data->at(l_get)==l_value)){
        l_n+=1;
        continue;
      }
      this->m__0data->at(l_put)=this->m__0data->at(l_get);
      l_put+=1;
    }
  }
  this->m_Resize(l_put);
  return l_n;
}

bbBool t_std_collections_Stack_1Tt_mx2_FuncList_2::m_Remove(t_mx2_FuncList* l_value,bbInt l_start){
  bbInt l_i=this->m_FindIndex(l_value,l_start);
  if((l_i==-1)){
    return false;
  }
  this->m_Erase(l_i);
  return true;
}

void t_std_collections_Stack_1Tt_mx2_FuncList_2::m_Push(t_mx2_FuncList* l_value){
  this->m_Add(l_value);
}

t_mx2_FuncList* t_std_collections_Stack_1Tt_mx2_FuncList_2::m_Pop(){
  struct f0_t : public bbGCFrame{
    t_mx2_FuncList* l_value{};
    void gcMark(){
      bbGCMarkPtr(l_value);
    }
  }f0{};
  bbDebugAssert(bbBool(this->m__0length),BB_T("Stack is empty"));
  this->m__0length-=1;
  this->m__0seq+=1;
  f0.l_value=this->m__0data->at(this->m__0length);
  this->m__0data->at(this->m__0length)=((t_mx2_FuncList*)0);
  return f0.l_value;
}

bbInt t_std_collections_Stack_1Tt_mx2_FuncList_2::m_Length(){
  return this->m__0length;
}

void t_std_collections_Stack_1Tt_mx2_FuncList_2::m_Insert(bbInt l_index,t_mx2_FuncList* l_value){
  bbDebugAssert(((l_index>=bbInt(0))&&(l_index<=this->m__0length)),BB_T("Debug assert failed"));
  this->m_Reserve((this->m__0length+1));
  this->m__0data->copyTo(this->m__0data,l_index,(l_index+1),(this->m__0length-l_index));
  this->m__0data->at(l_index)=l_value;
  this->m__0length+=1;
  this->m__0seq+=1;
}

t_mx2_FuncList* t_std_collections_Stack_1Tt_mx2_FuncList_2::m_Get(bbInt l_index){
  bbDebugAssert(((l_index>=bbInt(0))&&(l_index<this->m__0length)),BB_T("Stack index out of range"));
  return this->m__0data->at(l_index);
}

bbInt t_std_collections_Stack_1Tt_mx2_FuncList_2::m_FindLastIndex(t_mx2_FuncList* l_value,bbInt l_start){
  bbDebugAssert(((l_start>=bbInt(0))&&(l_start<=this->m__0length)),BB_T("Debug assert failed"));
  bbInt l_i=this->m__0length;
  while((l_i>l_start)){
    l_i-=1;
    if((this->m__0data->at(l_i)==l_value)){
      return l_i;
    }
  }
  return -1;
}

bbInt t_std_collections_Stack_1Tt_mx2_FuncList_2::m_FindIndex(t_mx2_FuncList* l_value,bbInt l_start){
  bbDebugAssert(((l_start>=bbInt(0))&&(l_start<=this->m__0length)),BB_T("Debug assert failed"));
  bbInt l_i=l_start;
  while((l_i<this->m__0length)){
    if((this->m__0data->at(l_i)==l_value)){
      return l_i;
    }
    l_i+=1;
  }
  return -1;
}

void t_std_collections_Stack_1Tt_mx2_FuncList_2::m_Erase(bbInt l_index1,bbInt l_index2){
  bbDebugAssert((((((l_index1>=bbInt(0))&&(l_index1<=this->m__0length))&&(l_index2>=bbInt(0)))&&(l_index2<=this->m__0length))&&(l_index1<=l_index2)),BB_T("Debug assert failed"));
  if((l_index1==this->m__0length)){
    return;
  }
  this->m__0data->copyTo(this->m__0data,l_index2,l_index1,(this->m__0length-l_index2));
  this->m_Resize(((this->m__0length-l_index2)+l_index1));
}

void t_std_collections_Stack_1Tt_mx2_FuncList_2::m_Erase(bbInt l_index){
  bbDebugAssert(((l_index>=bbInt(0))&&(l_index<=this->m__0length)),BB_T("Debug assert failed"));
  if((l_index==this->m__0length)){
    return;
  }
  this->m__0data->copyTo(this->m__0data,(l_index+1),l_index,((this->m__0length-l_index)-1));
  this->m_Resize((this->m__0length-1));
}

bbBool t_std_collections_Stack_1Tt_mx2_FuncList_2::m_Empty(){
  return (this->m__0length==bbInt(0));
}

bbArray<bbGCVar<t_mx2_FuncList>>* t_std_collections_Stack_1Tt_mx2_FuncList_2::m_Data(){
  return this->m__0data;
}

bbBool t_std_collections_Stack_1Tt_mx2_FuncList_2::m_Contains(t_mx2_FuncList* l_value){
  return (this->m_FindIndex(l_value,bbInt(0))!=-1);
}

void t_std_collections_Stack_1Tt_mx2_FuncList_2::m_Clear(){
  this->m_Resize(bbInt(0));
}

bbInt t_std_collections_Stack_1Tt_mx2_FuncList_2::m_Capacity(){
  return this->m__0data->length();
}

t_std_collections_Stack_1Tt_mx2_FuncList_2_BackwardsIterator t_std_collections_Stack_1Tt_mx2_FuncList_2::m_Backwards(){
  return t_std_collections_Stack_1Tt_mx2_FuncList_2_BackwardsIterator(this,(this->m__0length-1));
}

t_std_collections_Stack_1Tt_mx2_FuncList_2_Iterator t_std_collections_Stack_1Tt_mx2_FuncList_2::m_All(){
  return t_std_collections_Stack_1Tt_mx2_FuncList_2_Iterator(this,bbInt(0));
}

void t_std_collections_Stack_1Tt_mx2_FuncList_2::m_AddAll(bbArray<bbGCVar<t_mx2_FuncList>>* l_values){
  this->m_Reserve((this->m__0length+l_values->length()));
  l_values->copyTo(this->m__0data,bbInt(0),this->m__0length,l_values->length());
  this->m_Resize((this->m__0length+l_values->length()));
}

void t_std_collections_Stack_1Tt_mx2_FuncList_2::m_Add(t_mx2_FuncList* l_value){
  this->m_Reserve((this->m__0length+1));
  this->m__0data->at(this->m__0length)=l_value;
  this->m__0length+=1;
  this->m__0seq+=1;
}

void mx2_mx2cc_std_collections_2stack_init(){
  static bool done;
  if(done) return;
  done=true;
}

bbInit mx2_mx2cc_std_collections_2stack_init_v("mx2cc_std_collections_2stack",&mx2_mx2cc_std_collections_2stack_init);
