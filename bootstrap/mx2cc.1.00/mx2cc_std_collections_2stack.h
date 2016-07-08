
#ifndef MX2_MX2CC_STD_COLLECTIONS_2STACK_H
#define MX2_MX2CC_STD_COLLECTIONS_2STACK_H

#include <bbmonkey.h>
#include "../../../../../modules/std/std.buildv1.0.0/desktop_release_linux/std_collections_2stack.h"

// ***** External *****

#include "../../../../../modules/monkey/monkey.buildv1.0.0/desktop_release_linux/monkey_types.h"
#include "mx2cc_std_collections_2container.h"

struct t_std_collections_List_1Tt_mx2_Translator_GCTmp_2;
struct t_std_collections_List_1Tt_mx2_Stmt_2;
struct t_std_collections_List_1Tt_mx2_Toker_2;
struct t_std_collections_List_1Tt_mx2_ParseEx_2;
struct t_std_collections_List_1Tt_mx2_TypeExpr_2;
struct t_std_collections_List_1Tt_mx2_CatchExpr_2;
struct t_std_collections_List_1Tt_mx2_StmtExpr_2;
struct t_std_collections_List_1Tt_mx2_Expr_2;
struct t_std_collections_List_1Tt_mx2_CaseExpr_2;
struct t_std_collections_List_1Tt_mx2_VarDecl_2;
struct t_std_collections_List_1Tt_mx2_Decl_2;
struct t_std_collections_List_1Tt_mx2_CatchStmt_2;
struct t_std_collections_List_1Tt_mx2_CaseStmt_2;
struct t_std_collections_List_1Tt_mx2_FuncListType_2;
struct t_std_collections_List_1Tt_mx2_AliasType_2;
struct t_std_collections_List_1Tt_mx2_PNode_2;
struct t_std_collections_List_1Tt_mx2_NamespaceScope_2;
struct t_std_collections_List_1Tt_mx2_FileScope_2;
struct t_std_collections_List_1Tt_mx2_FileDecl_2;
struct t_std_collections_List_1Tt_std_collections_Stack_1s_2;
struct t_std_collections_Stack_1s;
struct t_std_collections_List_1Tt_mx2_VarValue_2;
struct t_std_collections_List_1Tt_mx2_FuncList_2;
struct t_std_collections_List_1Tt_mx2_SNode_2;
struct t_std_collections_List_1Tt_mx2_Scope_2;
struct t_std_collections_List_1Tt_mx2_ClassType_2;
struct t_std_collections_List_1Tt_mx2_ErrorEx_2;
struct t_std_collections_List_1Tt_mx2_Module_2;
struct t_std_collections_List_1Tt_mx2_FuncValue_2;
struct t_mx2_FuncValue;
struct t_mx2_Module;
struct t_mx2_ErrorEx;
struct t_mx2_ClassType;
struct t_mx2_Scope;
struct t_mx2_SNode;
struct t_mx2_VarValue;
struct t_mx2_FileDecl;
struct t_mx2_FileScope;
struct t_mx2_NamespaceScope;
struct t_mx2_PNode;
struct t_mx2_AliasType;
struct t_mx2_FuncListType;
struct t_mx2_Decl;
struct t_mx2_ParseEx;
struct t_mx2_Toker;
struct t_mx2_Stmt;
struct t_mx2_Translator_GCTmp;
struct t_mx2_TypeExpr;
struct t_mx2_CatchExpr;
struct t_mx2_StmtExpr;
struct t_mx2_CaseExpr;
struct t_mx2_Expr;
struct t_mx2_VarDecl;
struct t_mx2_CatchStmt;
struct t_mx2_CaseStmt;
struct t_mx2_FuncList;

// ***** Internal *****

struct t_std_collections_Stack_1Tt_mx2_FuncValue_2_Iterator;
struct t_std_collections_Stack_1Tt_mx2_FuncValue_2_BackwardsIterator;
struct t_std_collections_Stack_1Tt_mx2_FuncValue_2;
struct t_std_collections_Stack_1Tt_mx2_Module_2_Iterator;
struct t_std_collections_Stack_1Tt_mx2_Module_2_BackwardsIterator;
struct t_std_collections_Stack_1Tt_mx2_Module_2;
struct t_std_collections_Stack_1Tt_mx2_ErrorEx_2_Iterator;
struct t_std_collections_Stack_1Tt_mx2_ErrorEx_2_BackwardsIterator;
struct t_std_collections_Stack_1Tt_mx2_ErrorEx_2;
struct t_std_collections_Stack_1Tt_mx2_ClassType_2_Iterator;
struct t_std_collections_Stack_1Tt_mx2_ClassType_2_BackwardsIterator;
struct t_std_collections_Stack_1Tt_mx2_ClassType_2;
struct t_std_collections_Stack_1Tt_mx2_Scope_2_Iterator;
struct t_std_collections_Stack_1Tt_mx2_Scope_2_BackwardsIterator;
struct t_std_collections_Stack_1Tt_mx2_Scope_2;
struct t_std_collections_Stack_1Tt_mx2_SNode_2_Iterator;
struct t_std_collections_Stack_1Tt_mx2_SNode_2_BackwardsIterator;
struct t_std_collections_Stack_1Tt_mx2_SNode_2;
struct t_std_collections_Stack_1Tt_mx2_VarValue_2_Iterator;
struct t_std_collections_Stack_1Tt_mx2_VarValue_2_BackwardsIterator;
struct t_std_collections_Stack_1Tt_mx2_VarValue_2;
struct t_std_collections_Stack_1Tt_std_collections_Stack_1s_2_Iterator;
struct t_std_collections_Stack_1Tt_std_collections_Stack_1s_2_BackwardsIterator;
struct t_std_collections_Stack_1Tt_std_collections_Stack_1s_2;
struct t_std_collections_Stack_1Tt_mx2_FileDecl_2_Iterator;
struct t_std_collections_Stack_1Tt_mx2_FileDecl_2_BackwardsIterator;
struct t_std_collections_Stack_1Tt_mx2_FileDecl_2;
struct t_std_collections_Stack_1Tt_mx2_FileScope_2_Iterator;
struct t_std_collections_Stack_1Tt_mx2_FileScope_2_BackwardsIterator;
struct t_std_collections_Stack_1Tt_mx2_FileScope_2;
struct t_std_collections_Stack_1Tt_mx2_NamespaceScope_2_Iterator;
struct t_std_collections_Stack_1Tt_mx2_NamespaceScope_2_BackwardsIterator;
struct t_std_collections_Stack_1Tt_mx2_NamespaceScope_2;
struct t_std_collections_Stack_1Tt_mx2_PNode_2_Iterator;
struct t_std_collections_Stack_1Tt_mx2_PNode_2_BackwardsIterator;
struct t_std_collections_Stack_1Tt_mx2_PNode_2;
struct t_std_collections_Stack_1Tt_mx2_AliasType_2_Iterator;
struct t_std_collections_Stack_1Tt_mx2_AliasType_2_BackwardsIterator;
struct t_std_collections_Stack_1Tt_mx2_AliasType_2;
struct t_std_collections_Stack_1Tt_mx2_FuncListType_2_Iterator;
struct t_std_collections_Stack_1Tt_mx2_FuncListType_2_BackwardsIterator;
struct t_std_collections_Stack_1Tt_mx2_FuncListType_2;
struct t_std_collections_Stack_1Tt_mx2_Decl_2_Iterator;
struct t_std_collections_Stack_1Tt_mx2_Decl_2_BackwardsIterator;
struct t_std_collections_Stack_1Tt_mx2_Decl_2;
struct t_std_collections_Stack_1Tt_mx2_ParseEx_2_Iterator;
struct t_std_collections_Stack_1Tt_mx2_ParseEx_2_BackwardsIterator;
struct t_std_collections_Stack_1Tt_mx2_ParseEx_2;
struct t_std_collections_Stack_1Tt_mx2_Toker_2_Iterator;
struct t_std_collections_Stack_1Tt_mx2_Toker_2_BackwardsIterator;
struct t_std_collections_Stack_1Tt_mx2_Toker_2;
struct t_std_collections_Stack_1Tt_mx2_Stmt_2_Iterator;
struct t_std_collections_Stack_1Tt_mx2_Stmt_2_BackwardsIterator;
struct t_std_collections_Stack_1Tt_mx2_Stmt_2;
struct t_std_collections_Stack_1Tt_mx2_Translator_GCTmp_2_Iterator;
struct t_std_collections_Stack_1Tt_mx2_Translator_GCTmp_2_BackwardsIterator;
struct t_std_collections_Stack_1Tt_mx2_Translator_GCTmp_2;
struct t_std_collections_Stack_1Tt_mx2_TypeExpr_2_Iterator;
struct t_std_collections_Stack_1Tt_mx2_TypeExpr_2_BackwardsIterator;
struct t_std_collections_Stack_1Tt_mx2_TypeExpr_2;
struct t_std_collections_Stack_1Tt_mx2_CatchExpr_2_Iterator;
struct t_std_collections_Stack_1Tt_mx2_CatchExpr_2_BackwardsIterator;
struct t_std_collections_Stack_1Tt_mx2_CatchExpr_2;
struct t_std_collections_Stack_1Tt_mx2_StmtExpr_2_Iterator;
struct t_std_collections_Stack_1Tt_mx2_StmtExpr_2_BackwardsIterator;
struct t_std_collections_Stack_1Tt_mx2_StmtExpr_2;
struct t_std_collections_Stack_1Tt_mx2_CaseExpr_2_Iterator;
struct t_std_collections_Stack_1Tt_mx2_CaseExpr_2_BackwardsIterator;
struct t_std_collections_Stack_1Tt_mx2_CaseExpr_2;
struct t_std_collections_Stack_1Tt_mx2_Expr_2_Iterator;
struct t_std_collections_Stack_1Tt_mx2_Expr_2_BackwardsIterator;
struct t_std_collections_Stack_1Tt_mx2_Expr_2;
struct t_std_collections_Stack_1Tt_mx2_VarDecl_2_Iterator;
struct t_std_collections_Stack_1Tt_mx2_VarDecl_2_BackwardsIterator;
struct t_std_collections_Stack_1Tt_mx2_VarDecl_2;
struct t_std_collections_Stack_1Tt_mx2_CatchStmt_2_Iterator;
struct t_std_collections_Stack_1Tt_mx2_CatchStmt_2_BackwardsIterator;
struct t_std_collections_Stack_1Tt_mx2_CatchStmt_2;
struct t_std_collections_Stack_1Tt_mx2_CaseStmt_2_Iterator;
struct t_std_collections_Stack_1Tt_mx2_CaseStmt_2_BackwardsIterator;
struct t_std_collections_Stack_1Tt_mx2_CaseStmt_2;
struct t_std_collections_Stack_1Tt_mx2_FuncList_2_Iterator;
struct t_std_collections_Stack_1Tt_mx2_FuncList_2_BackwardsIterator;
struct t_std_collections_Stack_1Tt_mx2_FuncList_2;

extern void g_std_collections_Stack_1Tt_mx2_Translator_GCTmp_2_AddAll_1Tt_std_collections_List_1Tt_mx2_Translator_GCTmp_2_2(t_std_collections_Stack_1Tt_mx2_Translator_GCTmp_2* l_self,t_std_collections_List_1Tt_mx2_Translator_GCTmp_2* l_values);
extern void g_std_collections_Stack_1Tt_mx2_Stmt_2_AddAll_1Tt_std_collections_List_1Tt_mx2_Stmt_2_2(t_std_collections_Stack_1Tt_mx2_Stmt_2* l_self,t_std_collections_List_1Tt_mx2_Stmt_2* l_values);
extern void g_std_collections_Stack_1Tt_mx2_Toker_2_AddAll_1Tt_std_collections_List_1Tt_mx2_Toker_2_2(t_std_collections_Stack_1Tt_mx2_Toker_2* l_self,t_std_collections_List_1Tt_mx2_Toker_2* l_values);
extern void g_std_collections_Stack_1Tt_mx2_ParseEx_2_AddAll_1Tt_std_collections_List_1Tt_mx2_ParseEx_2_2(t_std_collections_Stack_1Tt_mx2_ParseEx_2* l_self,t_std_collections_List_1Tt_mx2_ParseEx_2* l_values);
extern void g_std_collections_Stack_1Tt_mx2_TypeExpr_2_AddAll_1Tt_std_collections_List_1Tt_mx2_TypeExpr_2_2(t_std_collections_Stack_1Tt_mx2_TypeExpr_2* l_self,t_std_collections_List_1Tt_mx2_TypeExpr_2* l_values);
extern void g_std_collections_Stack_1Tt_mx2_CatchExpr_2_AddAll_1Tt_std_collections_List_1Tt_mx2_CatchExpr_2_2(t_std_collections_Stack_1Tt_mx2_CatchExpr_2* l_self,t_std_collections_List_1Tt_mx2_CatchExpr_2* l_values);
extern void g_std_collections_Stack_1Tt_mx2_StmtExpr_2_AddAll_1Tt_std_collections_List_1Tt_mx2_StmtExpr_2_2(t_std_collections_Stack_1Tt_mx2_StmtExpr_2* l_self,t_std_collections_List_1Tt_mx2_StmtExpr_2* l_values);
extern void g_std_collections_Stack_1Tt_mx2_Expr_2_AddAll_1Tt_std_collections_List_1Tt_mx2_Expr_2_2(t_std_collections_Stack_1Tt_mx2_Expr_2* l_self,t_std_collections_List_1Tt_mx2_Expr_2* l_values);
extern void g_std_collections_Stack_1Tt_mx2_CaseExpr_2_AddAll_1Tt_std_collections_List_1Tt_mx2_CaseExpr_2_2(t_std_collections_Stack_1Tt_mx2_CaseExpr_2* l_self,t_std_collections_List_1Tt_mx2_CaseExpr_2* l_values);
extern void g_std_collections_Stack_1Tt_mx2_VarDecl_2_AddAll_1Tt_std_collections_List_1Tt_mx2_VarDecl_2_2(t_std_collections_Stack_1Tt_mx2_VarDecl_2* l_self,t_std_collections_List_1Tt_mx2_VarDecl_2* l_values);
extern void g_std_collections_Stack_1Tt_mx2_Decl_2_AddAll_1Tt_std_collections_List_1Tt_mx2_Decl_2_2(t_std_collections_Stack_1Tt_mx2_Decl_2* l_self,t_std_collections_List_1Tt_mx2_Decl_2* l_values);
extern void g_std_collections_Stack_1Tt_mx2_CatchStmt_2_AddAll_1Tt_std_collections_List_1Tt_mx2_CatchStmt_2_2(t_std_collections_Stack_1Tt_mx2_CatchStmt_2* l_self,t_std_collections_List_1Tt_mx2_CatchStmt_2* l_values);
extern void g_std_collections_Stack_1Tt_mx2_CaseStmt_2_AddAll_1Tt_std_collections_List_1Tt_mx2_CaseStmt_2_2(t_std_collections_Stack_1Tt_mx2_CaseStmt_2* l_self,t_std_collections_List_1Tt_mx2_CaseStmt_2* l_values);
extern void g_std_collections_Stack_1Tt_mx2_FuncListType_2_AddAll_1Tt_std_collections_List_1Tt_mx2_FuncListType_2_2(t_std_collections_Stack_1Tt_mx2_FuncListType_2* l_self,t_std_collections_List_1Tt_mx2_FuncListType_2* l_values);
extern void g_std_collections_Stack_1Tt_mx2_AliasType_2_AddAll_1Tt_std_collections_List_1Tt_mx2_AliasType_2_2(t_std_collections_Stack_1Tt_mx2_AliasType_2* l_self,t_std_collections_List_1Tt_mx2_AliasType_2* l_values);
extern void g_std_collections_Stack_1Tt_mx2_PNode_2_AddAll_1Tt_std_collections_List_1Tt_mx2_PNode_2_2(t_std_collections_Stack_1Tt_mx2_PNode_2* l_self,t_std_collections_List_1Tt_mx2_PNode_2* l_values);
extern void g_std_collections_Stack_1Tt_mx2_NamespaceScope_2_AddAll_1Tt_std_collections_List_1Tt_mx2_NamespaceScope_2_2(t_std_collections_Stack_1Tt_mx2_NamespaceScope_2* l_self,t_std_collections_List_1Tt_mx2_NamespaceScope_2* l_values);
extern void g_std_collections_Stack_1Tt_mx2_FileScope_2_AddAll_1Tt_std_collections_List_1Tt_mx2_FileScope_2_2(t_std_collections_Stack_1Tt_mx2_FileScope_2* l_self,t_std_collections_List_1Tt_mx2_FileScope_2* l_values);
extern void g_std_collections_Stack_1Tt_mx2_FileDecl_2_AddAll_1Tt_std_collections_List_1Tt_mx2_FileDecl_2_2(t_std_collections_Stack_1Tt_mx2_FileDecl_2* l_self,t_std_collections_List_1Tt_mx2_FileDecl_2* l_values);
extern void g_std_collections_Stack_1Tt_std_collections_Stack_1s_2_AddAll_1Tt_std_collections_List_1Tt_std_collections_Stack_1s_2_2(t_std_collections_Stack_1Tt_std_collections_Stack_1s_2* l_self,t_std_collections_List_1Tt_std_collections_Stack_1s_2* l_values);
extern void g_std_collections_Stack_1s_Append_1Tt_std_collections_Stack_1s_2(t_std_collections_Stack_1s* l_self,t_std_collections_Stack_1s* l_values);
extern void g_std_collections_Stack_1Tt_mx2_VarValue_2_AddAll_1Tt_std_collections_List_1Tt_mx2_VarValue_2_2(t_std_collections_Stack_1Tt_mx2_VarValue_2* l_self,t_std_collections_List_1Tt_mx2_VarValue_2* l_values);
extern void g_std_collections_Stack_1Tt_mx2_FuncList_2_AddAll_1Tt_std_collections_List_1Tt_mx2_FuncList_2_2(t_std_collections_Stack_1Tt_mx2_FuncList_2* l_self,t_std_collections_List_1Tt_mx2_FuncList_2* l_values);
extern void g_std_collections_Stack_1Tt_mx2_SNode_2_AddAll_1Tt_std_collections_List_1Tt_mx2_SNode_2_2(t_std_collections_Stack_1Tt_mx2_SNode_2* l_self,t_std_collections_List_1Tt_mx2_SNode_2* l_values);
extern void g_std_collections_Stack_1Tt_mx2_Scope_2_AddAll_1Tt_std_collections_List_1Tt_mx2_Scope_2_2(t_std_collections_Stack_1Tt_mx2_Scope_2* l_self,t_std_collections_List_1Tt_mx2_Scope_2* l_values);
extern void g_std_collections_Stack_1Tt_mx2_ClassType_2_AddAll_1Tt_std_collections_List_1Tt_mx2_ClassType_2_2(t_std_collections_Stack_1Tt_mx2_ClassType_2* l_self,t_std_collections_List_1Tt_mx2_ClassType_2* l_values);
extern void g_std_collections_Stack_1Tt_mx2_ErrorEx_2_AddAll_1Tt_std_collections_List_1Tt_mx2_ErrorEx_2_2(t_std_collections_Stack_1Tt_mx2_ErrorEx_2* l_self,t_std_collections_List_1Tt_mx2_ErrorEx_2* l_values);
extern void g_std_collections_Stack_1Tt_mx2_Module_2_AddAll_1Tt_std_collections_List_1Tt_mx2_Module_2_2(t_std_collections_Stack_1Tt_mx2_Module_2* l_self,t_std_collections_List_1Tt_mx2_Module_2* l_values);
extern void g_std_collections_Stack_1Tt_mx2_FuncValue_2_AddAll_1Tt_std_collections_List_1Tt_mx2_FuncValue_2_2(t_std_collections_Stack_1Tt_mx2_FuncValue_2* l_self,t_std_collections_List_1Tt_mx2_FuncValue_2* l_values);

struct t_std_collections_Stack_1Tt_mx2_FuncValue_2_Iterator{
  const char *typeName()const{return "t_std_collections_Stack_1Tt_mx2_FuncValue_2_Iterator";}

  bbGCVar<t_std_collections_Stack_1Tt_mx2_FuncValue_2> m__0stack{};
  bbInt m__0index{};
  bbInt m__0seq{};

  t_std_collections_Stack_1Tt_mx2_FuncValue_2_Iterator(t_std_collections_Stack_1Tt_mx2_FuncValue_2* l_stack,bbInt l_index);

  void m_Insert(t_mx2_FuncValue* l_value);
  void m_Erase();
  void m_Current(t_mx2_FuncValue* l_current);
  t_mx2_FuncValue* m_Current();
  void m_Bump();
  bbBool m_AtEnd();
  void m_AssertSeq();
  void m_AssertCurrent();

  t_std_collections_Stack_1Tt_mx2_FuncValue_2_Iterator(){
  }

  t_std_collections_Stack_1Tt_mx2_FuncValue_2_Iterator(bbNullCtor_t){
  }
};

int bbCompare(const t_std_collections_Stack_1Tt_mx2_FuncValue_2_Iterator&x,const t_std_collections_Stack_1Tt_mx2_FuncValue_2_Iterator&y);

void bbGCMark(const t_std_collections_Stack_1Tt_mx2_FuncValue_2_Iterator&);

struct t_std_collections_Stack_1Tt_mx2_FuncValue_2_BackwardsIterator{
  const char *typeName()const{return "t_std_collections_Stack_1Tt_mx2_FuncValue_2_BackwardsIterator";}

  bbGCVar<t_std_collections_Stack_1Tt_mx2_FuncValue_2> m__0stack{};
  bbInt m__0index{};
  bbInt m__0seq{};

  t_std_collections_Stack_1Tt_mx2_FuncValue_2_BackwardsIterator(t_std_collections_Stack_1Tt_mx2_FuncValue_2* l_stack,bbInt l_index);

  void m_Insert(t_mx2_FuncValue* l_value);
  void m_Erase();
  void m_Current(t_mx2_FuncValue* l_current);
  t_mx2_FuncValue* m_Current();
  void m_Bump();
  bbBool m_AtEnd();
  void m_AssertSeq();
  void m_AssertCurrent();

  t_std_collections_Stack_1Tt_mx2_FuncValue_2_BackwardsIterator(){
  }

  t_std_collections_Stack_1Tt_mx2_FuncValue_2_BackwardsIterator(bbNullCtor_t){
  }
};

int bbCompare(const t_std_collections_Stack_1Tt_mx2_FuncValue_2_BackwardsIterator&x,const t_std_collections_Stack_1Tt_mx2_FuncValue_2_BackwardsIterator&y);

void bbGCMark(const t_std_collections_Stack_1Tt_mx2_FuncValue_2_BackwardsIterator&);

struct t_std_collections_Stack_1Tt_mx2_FuncValue_2 : public bbObject,public virtual t_std_collections_IContainer_1Tt_mx2_FuncValue_2{

  const char *typeName()const{return "t_std_collections_Stack_1Tt_mx2_FuncValue_2";}

  bbGCVar<bbArray<bbGCVar<t_mx2_FuncValue>>> m__0data{};
  bbInt m__0length{};
  bbInt m__0seq{};

  void gcMark();

  t_std_collections_Stack_1Tt_mx2_FuncValue_2(t_std_collections_List_1Tt_mx2_FuncValue_2* l_values);
  t_std_collections_Stack_1Tt_mx2_FuncValue_2(t_std_collections_Stack_1Tt_mx2_FuncValue_2* l_values);
  t_std_collections_Stack_1Tt_mx2_FuncValue_2(bbArray<bbGCVar<t_mx2_FuncValue>>* l_values);
  t_std_collections_Stack_1Tt_mx2_FuncValue_2(bbInt l_length);
  t_std_collections_Stack_1Tt_mx2_FuncValue_2();

  void m__idxeq(bbInt l_index,t_mx2_FuncValue* l_value);
  t_mx2_FuncValue* m__idx(bbInt l_index);
  t_mx2_FuncValue* m_Top();
  bbArray<bbGCVar<t_mx2_FuncValue>>* m_ToArray();
  void m_Swap(bbInt l_index1,bbInt l_index2);
  void m_Sort(bbFunction<bbInt(t_mx2_FuncValue*,t_mx2_FuncValue*)> l_compareFunc,bbInt l_lo,bbInt l_hi);
  void m_Sort(bbFunction<bbInt(t_mx2_FuncValue*,t_mx2_FuncValue*)> l_compareFunc);
  void m_Sort(bbBool l_ascending);
  t_std_collections_Stack_1Tt_mx2_FuncValue_2* m_Slice(bbInt l_index1,bbInt l_index2);
  t_std_collections_Stack_1Tt_mx2_FuncValue_2* m_Slice(bbInt l_index);
  void m_Set(bbInt l_index,t_mx2_FuncValue* l_value);
  void m_Resize(bbInt l_length);
  void m_Reserve(bbInt l_capacity);
  bbBool m_RemoveLast(t_mx2_FuncValue* l_value,bbInt l_start);
  bbInt m_RemoveEach(t_mx2_FuncValue* l_value);
  bbBool m_Remove(t_mx2_FuncValue* l_value,bbInt l_start);
  void m_Push(t_mx2_FuncValue* l_value);
  t_mx2_FuncValue* m_Pop();
  bbInt m_Length();
  void m_Insert(bbInt l_index,t_mx2_FuncValue* l_value);
  t_mx2_FuncValue* m_Get(bbInt l_index);
  bbInt m_FindLastIndex(t_mx2_FuncValue* l_value,bbInt l_start);
  bbInt m_FindIndex(t_mx2_FuncValue* l_value,bbInt l_start);
  void m_Erase(bbInt l_index1,bbInt l_index2);
  void m_Erase(bbInt l_index);
  bbBool m_Empty();
  bbArray<bbGCVar<t_mx2_FuncValue>>* m_Data();
  bbBool m_Contains(t_mx2_FuncValue* l_value);
  void m_Clear();
  bbInt m_Capacity();
  t_std_collections_Stack_1Tt_mx2_FuncValue_2_BackwardsIterator m_Backwards();
  t_std_collections_Stack_1Tt_mx2_FuncValue_2_Iterator m_All();
  void m_AddAll(bbArray<bbGCVar<t_mx2_FuncValue>>* l_values);
  void m_Add(t_mx2_FuncValue* l_value);
};

struct t_std_collections_Stack_1Tt_mx2_Module_2_Iterator{
  const char *typeName()const{return "t_std_collections_Stack_1Tt_mx2_Module_2_Iterator";}

  bbGCVar<t_std_collections_Stack_1Tt_mx2_Module_2> m__0stack{};
  bbInt m__0index{};
  bbInt m__0seq{};

  t_std_collections_Stack_1Tt_mx2_Module_2_Iterator(t_std_collections_Stack_1Tt_mx2_Module_2* l_stack,bbInt l_index);

  void m_Insert(t_mx2_Module* l_value);
  void m_Erase();
  void m_Current(t_mx2_Module* l_current);
  t_mx2_Module* m_Current();
  void m_Bump();
  bbBool m_AtEnd();
  void m_AssertSeq();
  void m_AssertCurrent();

  t_std_collections_Stack_1Tt_mx2_Module_2_Iterator(){
  }

  t_std_collections_Stack_1Tt_mx2_Module_2_Iterator(bbNullCtor_t){
  }
};

int bbCompare(const t_std_collections_Stack_1Tt_mx2_Module_2_Iterator&x,const t_std_collections_Stack_1Tt_mx2_Module_2_Iterator&y);

void bbGCMark(const t_std_collections_Stack_1Tt_mx2_Module_2_Iterator&);

struct t_std_collections_Stack_1Tt_mx2_Module_2_BackwardsIterator{
  const char *typeName()const{return "t_std_collections_Stack_1Tt_mx2_Module_2_BackwardsIterator";}

  bbGCVar<t_std_collections_Stack_1Tt_mx2_Module_2> m__0stack{};
  bbInt m__0index{};
  bbInt m__0seq{};

  t_std_collections_Stack_1Tt_mx2_Module_2_BackwardsIterator(t_std_collections_Stack_1Tt_mx2_Module_2* l_stack,bbInt l_index);

  void m_Insert(t_mx2_Module* l_value);
  void m_Erase();
  void m_Current(t_mx2_Module* l_current);
  t_mx2_Module* m_Current();
  void m_Bump();
  bbBool m_AtEnd();
  void m_AssertSeq();
  void m_AssertCurrent();

  t_std_collections_Stack_1Tt_mx2_Module_2_BackwardsIterator(){
  }

  t_std_collections_Stack_1Tt_mx2_Module_2_BackwardsIterator(bbNullCtor_t){
  }
};

int bbCompare(const t_std_collections_Stack_1Tt_mx2_Module_2_BackwardsIterator&x,const t_std_collections_Stack_1Tt_mx2_Module_2_BackwardsIterator&y);

void bbGCMark(const t_std_collections_Stack_1Tt_mx2_Module_2_BackwardsIterator&);

struct t_std_collections_Stack_1Tt_mx2_Module_2 : public bbObject,public virtual t_std_collections_IContainer_1Tt_mx2_Module_2{

  const char *typeName()const{return "t_std_collections_Stack_1Tt_mx2_Module_2";}

  bbGCVar<bbArray<bbGCVar<t_mx2_Module>>> m__0data{};
  bbInt m__0length{};
  bbInt m__0seq{};

  void gcMark();

  t_std_collections_Stack_1Tt_mx2_Module_2(t_std_collections_List_1Tt_mx2_Module_2* l_values);
  t_std_collections_Stack_1Tt_mx2_Module_2(t_std_collections_Stack_1Tt_mx2_Module_2* l_values);
  t_std_collections_Stack_1Tt_mx2_Module_2(bbArray<bbGCVar<t_mx2_Module>>* l_values);
  t_std_collections_Stack_1Tt_mx2_Module_2(bbInt l_length);
  t_std_collections_Stack_1Tt_mx2_Module_2();

  void m__idxeq(bbInt l_index,t_mx2_Module* l_value);
  t_mx2_Module* m__idx(bbInt l_index);
  t_mx2_Module* m_Top();
  bbArray<bbGCVar<t_mx2_Module>>* m_ToArray();
  void m_Swap(bbInt l_index1,bbInt l_index2);
  void m_Sort(bbFunction<bbInt(t_mx2_Module*,t_mx2_Module*)> l_compareFunc,bbInt l_lo,bbInt l_hi);
  void m_Sort(bbFunction<bbInt(t_mx2_Module*,t_mx2_Module*)> l_compareFunc);
  void m_Sort(bbBool l_ascending);
  t_std_collections_Stack_1Tt_mx2_Module_2* m_Slice(bbInt l_index1,bbInt l_index2);
  t_std_collections_Stack_1Tt_mx2_Module_2* m_Slice(bbInt l_index);
  void m_Set(bbInt l_index,t_mx2_Module* l_value);
  void m_Resize(bbInt l_length);
  void m_Reserve(bbInt l_capacity);
  bbBool m_RemoveLast(t_mx2_Module* l_value,bbInt l_start);
  bbInt m_RemoveEach(t_mx2_Module* l_value);
  bbBool m_Remove(t_mx2_Module* l_value,bbInt l_start);
  void m_Push(t_mx2_Module* l_value);
  t_mx2_Module* m_Pop();
  bbInt m_Length();
  void m_Insert(bbInt l_index,t_mx2_Module* l_value);
  t_mx2_Module* m_Get(bbInt l_index);
  bbInt m_FindLastIndex(t_mx2_Module* l_value,bbInt l_start);
  bbInt m_FindIndex(t_mx2_Module* l_value,bbInt l_start);
  void m_Erase(bbInt l_index1,bbInt l_index2);
  void m_Erase(bbInt l_index);
  bbBool m_Empty();
  bbArray<bbGCVar<t_mx2_Module>>* m_Data();
  bbBool m_Contains(t_mx2_Module* l_value);
  void m_Clear();
  bbInt m_Capacity();
  t_std_collections_Stack_1Tt_mx2_Module_2_BackwardsIterator m_Backwards();
  t_std_collections_Stack_1Tt_mx2_Module_2_Iterator m_All();
  void m_AddAll(bbArray<bbGCVar<t_mx2_Module>>* l_values);
  void m_Add(t_mx2_Module* l_value);
};

struct t_std_collections_Stack_1Tt_mx2_ErrorEx_2_Iterator{
  const char *typeName()const{return "t_std_collections_Stack_1Tt_mx2_ErrorEx_2_Iterator";}

  bbGCVar<t_std_collections_Stack_1Tt_mx2_ErrorEx_2> m__0stack{};
  bbInt m__0index{};
  bbInt m__0seq{};

  t_std_collections_Stack_1Tt_mx2_ErrorEx_2_Iterator(t_std_collections_Stack_1Tt_mx2_ErrorEx_2* l_stack,bbInt l_index);

  void m_Insert(t_mx2_ErrorEx* l_value);
  void m_Erase();
  void m_Current(t_mx2_ErrorEx* l_current);
  t_mx2_ErrorEx* m_Current();
  void m_Bump();
  bbBool m_AtEnd();
  void m_AssertSeq();
  void m_AssertCurrent();

  t_std_collections_Stack_1Tt_mx2_ErrorEx_2_Iterator(){
  }

  t_std_collections_Stack_1Tt_mx2_ErrorEx_2_Iterator(bbNullCtor_t){
  }
};

int bbCompare(const t_std_collections_Stack_1Tt_mx2_ErrorEx_2_Iterator&x,const t_std_collections_Stack_1Tt_mx2_ErrorEx_2_Iterator&y);

void bbGCMark(const t_std_collections_Stack_1Tt_mx2_ErrorEx_2_Iterator&);

struct t_std_collections_Stack_1Tt_mx2_ErrorEx_2_BackwardsIterator{
  const char *typeName()const{return "t_std_collections_Stack_1Tt_mx2_ErrorEx_2_BackwardsIterator";}

  bbGCVar<t_std_collections_Stack_1Tt_mx2_ErrorEx_2> m__0stack{};
  bbInt m__0index{};
  bbInt m__0seq{};

  t_std_collections_Stack_1Tt_mx2_ErrorEx_2_BackwardsIterator(t_std_collections_Stack_1Tt_mx2_ErrorEx_2* l_stack,bbInt l_index);

  void m_Insert(t_mx2_ErrorEx* l_value);
  void m_Erase();
  void m_Current(t_mx2_ErrorEx* l_current);
  t_mx2_ErrorEx* m_Current();
  void m_Bump();
  bbBool m_AtEnd();
  void m_AssertSeq();
  void m_AssertCurrent();

  t_std_collections_Stack_1Tt_mx2_ErrorEx_2_BackwardsIterator(){
  }

  t_std_collections_Stack_1Tt_mx2_ErrorEx_2_BackwardsIterator(bbNullCtor_t){
  }
};

int bbCompare(const t_std_collections_Stack_1Tt_mx2_ErrorEx_2_BackwardsIterator&x,const t_std_collections_Stack_1Tt_mx2_ErrorEx_2_BackwardsIterator&y);

void bbGCMark(const t_std_collections_Stack_1Tt_mx2_ErrorEx_2_BackwardsIterator&);

struct t_std_collections_Stack_1Tt_mx2_ErrorEx_2 : public bbObject,public virtual t_std_collections_IContainer_1Tt_mx2_ErrorEx_2{

  const char *typeName()const{return "t_std_collections_Stack_1Tt_mx2_ErrorEx_2";}

  bbGCVar<bbArray<bbGCVar<t_mx2_ErrorEx>>> m__0data{};
  bbInt m__0length{};
  bbInt m__0seq{};

  void gcMark();

  t_std_collections_Stack_1Tt_mx2_ErrorEx_2(t_std_collections_List_1Tt_mx2_ErrorEx_2* l_values);
  t_std_collections_Stack_1Tt_mx2_ErrorEx_2(t_std_collections_Stack_1Tt_mx2_ErrorEx_2* l_values);
  t_std_collections_Stack_1Tt_mx2_ErrorEx_2(bbArray<bbGCVar<t_mx2_ErrorEx>>* l_values);
  t_std_collections_Stack_1Tt_mx2_ErrorEx_2(bbInt l_length);
  t_std_collections_Stack_1Tt_mx2_ErrorEx_2();

  void m__idxeq(bbInt l_index,t_mx2_ErrorEx* l_value);
  t_mx2_ErrorEx* m__idx(bbInt l_index);
  t_mx2_ErrorEx* m_Top();
  bbArray<bbGCVar<t_mx2_ErrorEx>>* m_ToArray();
  void m_Swap(bbInt l_index1,bbInt l_index2);
  void m_Sort(bbFunction<bbInt(t_mx2_ErrorEx*,t_mx2_ErrorEx*)> l_compareFunc,bbInt l_lo,bbInt l_hi);
  void m_Sort(bbFunction<bbInt(t_mx2_ErrorEx*,t_mx2_ErrorEx*)> l_compareFunc);
  void m_Sort(bbBool l_ascending);
  t_std_collections_Stack_1Tt_mx2_ErrorEx_2* m_Slice(bbInt l_index1,bbInt l_index2);
  t_std_collections_Stack_1Tt_mx2_ErrorEx_2* m_Slice(bbInt l_index);
  void m_Set(bbInt l_index,t_mx2_ErrorEx* l_value);
  void m_Resize(bbInt l_length);
  void m_Reserve(bbInt l_capacity);
  bbBool m_RemoveLast(t_mx2_ErrorEx* l_value,bbInt l_start);
  bbInt m_RemoveEach(t_mx2_ErrorEx* l_value);
  bbBool m_Remove(t_mx2_ErrorEx* l_value,bbInt l_start);
  void m_Push(t_mx2_ErrorEx* l_value);
  t_mx2_ErrorEx* m_Pop();
  bbInt m_Length();
  void m_Insert(bbInt l_index,t_mx2_ErrorEx* l_value);
  t_mx2_ErrorEx* m_Get(bbInt l_index);
  bbInt m_FindLastIndex(t_mx2_ErrorEx* l_value,bbInt l_start);
  bbInt m_FindIndex(t_mx2_ErrorEx* l_value,bbInt l_start);
  void m_Erase(bbInt l_index1,bbInt l_index2);
  void m_Erase(bbInt l_index);
  bbBool m_Empty();
  bbArray<bbGCVar<t_mx2_ErrorEx>>* m_Data();
  bbBool m_Contains(t_mx2_ErrorEx* l_value);
  void m_Clear();
  bbInt m_Capacity();
  t_std_collections_Stack_1Tt_mx2_ErrorEx_2_BackwardsIterator m_Backwards();
  t_std_collections_Stack_1Tt_mx2_ErrorEx_2_Iterator m_All();
  void m_AddAll(bbArray<bbGCVar<t_mx2_ErrorEx>>* l_values);
  void m_Add(t_mx2_ErrorEx* l_value);
};

struct t_std_collections_Stack_1Tt_mx2_ClassType_2_Iterator{
  const char *typeName()const{return "t_std_collections_Stack_1Tt_mx2_ClassType_2_Iterator";}

  bbGCVar<t_std_collections_Stack_1Tt_mx2_ClassType_2> m__0stack{};
  bbInt m__0index{};
  bbInt m__0seq{};

  t_std_collections_Stack_1Tt_mx2_ClassType_2_Iterator(t_std_collections_Stack_1Tt_mx2_ClassType_2* l_stack,bbInt l_index);

  void m_Insert(t_mx2_ClassType* l_value);
  void m_Erase();
  void m_Current(t_mx2_ClassType* l_current);
  t_mx2_ClassType* m_Current();
  void m_Bump();
  bbBool m_AtEnd();
  void m_AssertSeq();
  void m_AssertCurrent();

  t_std_collections_Stack_1Tt_mx2_ClassType_2_Iterator(){
  }

  t_std_collections_Stack_1Tt_mx2_ClassType_2_Iterator(bbNullCtor_t){
  }
};

int bbCompare(const t_std_collections_Stack_1Tt_mx2_ClassType_2_Iterator&x,const t_std_collections_Stack_1Tt_mx2_ClassType_2_Iterator&y);

void bbGCMark(const t_std_collections_Stack_1Tt_mx2_ClassType_2_Iterator&);

struct t_std_collections_Stack_1Tt_mx2_ClassType_2_BackwardsIterator{
  const char *typeName()const{return "t_std_collections_Stack_1Tt_mx2_ClassType_2_BackwardsIterator";}

  bbGCVar<t_std_collections_Stack_1Tt_mx2_ClassType_2> m__0stack{};
  bbInt m__0index{};
  bbInt m__0seq{};

  t_std_collections_Stack_1Tt_mx2_ClassType_2_BackwardsIterator(t_std_collections_Stack_1Tt_mx2_ClassType_2* l_stack,bbInt l_index);

  void m_Insert(t_mx2_ClassType* l_value);
  void m_Erase();
  void m_Current(t_mx2_ClassType* l_current);
  t_mx2_ClassType* m_Current();
  void m_Bump();
  bbBool m_AtEnd();
  void m_AssertSeq();
  void m_AssertCurrent();

  t_std_collections_Stack_1Tt_mx2_ClassType_2_BackwardsIterator(){
  }

  t_std_collections_Stack_1Tt_mx2_ClassType_2_BackwardsIterator(bbNullCtor_t){
  }
};

int bbCompare(const t_std_collections_Stack_1Tt_mx2_ClassType_2_BackwardsIterator&x,const t_std_collections_Stack_1Tt_mx2_ClassType_2_BackwardsIterator&y);

void bbGCMark(const t_std_collections_Stack_1Tt_mx2_ClassType_2_BackwardsIterator&);

struct t_std_collections_Stack_1Tt_mx2_ClassType_2 : public bbObject,public virtual t_std_collections_IContainer_1Tt_mx2_ClassType_2{

  const char *typeName()const{return "t_std_collections_Stack_1Tt_mx2_ClassType_2";}

  bbGCVar<bbArray<bbGCVar<t_mx2_ClassType>>> m__0data{};
  bbInt m__0length{};
  bbInt m__0seq{};

  void gcMark();

  t_std_collections_Stack_1Tt_mx2_ClassType_2(t_std_collections_List_1Tt_mx2_ClassType_2* l_values);
  t_std_collections_Stack_1Tt_mx2_ClassType_2(t_std_collections_Stack_1Tt_mx2_ClassType_2* l_values);
  t_std_collections_Stack_1Tt_mx2_ClassType_2(bbArray<bbGCVar<t_mx2_ClassType>>* l_values);
  t_std_collections_Stack_1Tt_mx2_ClassType_2(bbInt l_length);
  t_std_collections_Stack_1Tt_mx2_ClassType_2();

  void m__idxeq(bbInt l_index,t_mx2_ClassType* l_value);
  t_mx2_ClassType* m__idx(bbInt l_index);
  t_mx2_ClassType* m_Top();
  bbArray<bbGCVar<t_mx2_ClassType>>* m_ToArray();
  void m_Swap(bbInt l_index1,bbInt l_index2);
  void m_Sort(bbFunction<bbInt(t_mx2_ClassType*,t_mx2_ClassType*)> l_compareFunc,bbInt l_lo,bbInt l_hi);
  void m_Sort(bbFunction<bbInt(t_mx2_ClassType*,t_mx2_ClassType*)> l_compareFunc);
  void m_Sort(bbBool l_ascending);
  t_std_collections_Stack_1Tt_mx2_ClassType_2* m_Slice(bbInt l_index1,bbInt l_index2);
  t_std_collections_Stack_1Tt_mx2_ClassType_2* m_Slice(bbInt l_index);
  void m_Set(bbInt l_index,t_mx2_ClassType* l_value);
  void m_Resize(bbInt l_length);
  void m_Reserve(bbInt l_capacity);
  bbBool m_RemoveLast(t_mx2_ClassType* l_value,bbInt l_start);
  bbInt m_RemoveEach(t_mx2_ClassType* l_value);
  bbBool m_Remove(t_mx2_ClassType* l_value,bbInt l_start);
  void m_Push(t_mx2_ClassType* l_value);
  t_mx2_ClassType* m_Pop();
  bbInt m_Length();
  void m_Insert(bbInt l_index,t_mx2_ClassType* l_value);
  t_mx2_ClassType* m_Get(bbInt l_index);
  bbInt m_FindLastIndex(t_mx2_ClassType* l_value,bbInt l_start);
  bbInt m_FindIndex(t_mx2_ClassType* l_value,bbInt l_start);
  void m_Erase(bbInt l_index1,bbInt l_index2);
  void m_Erase(bbInt l_index);
  bbBool m_Empty();
  bbArray<bbGCVar<t_mx2_ClassType>>* m_Data();
  bbBool m_Contains(t_mx2_ClassType* l_value);
  void m_Clear();
  bbInt m_Capacity();
  t_std_collections_Stack_1Tt_mx2_ClassType_2_BackwardsIterator m_Backwards();
  t_std_collections_Stack_1Tt_mx2_ClassType_2_Iterator m_All();
  void m_AddAll(bbArray<bbGCVar<t_mx2_ClassType>>* l_values);
  void m_Add(t_mx2_ClassType* l_value);
};

struct t_std_collections_Stack_1Tt_mx2_Scope_2_Iterator{
  const char *typeName()const{return "t_std_collections_Stack_1Tt_mx2_Scope_2_Iterator";}

  bbGCVar<t_std_collections_Stack_1Tt_mx2_Scope_2> m__0stack{};
  bbInt m__0index{};
  bbInt m__0seq{};

  t_std_collections_Stack_1Tt_mx2_Scope_2_Iterator(t_std_collections_Stack_1Tt_mx2_Scope_2* l_stack,bbInt l_index);

  void m_Insert(t_mx2_Scope* l_value);
  void m_Erase();
  void m_Current(t_mx2_Scope* l_current);
  t_mx2_Scope* m_Current();
  void m_Bump();
  bbBool m_AtEnd();
  void m_AssertSeq();
  void m_AssertCurrent();

  t_std_collections_Stack_1Tt_mx2_Scope_2_Iterator(){
  }

  t_std_collections_Stack_1Tt_mx2_Scope_2_Iterator(bbNullCtor_t){
  }
};

int bbCompare(const t_std_collections_Stack_1Tt_mx2_Scope_2_Iterator&x,const t_std_collections_Stack_1Tt_mx2_Scope_2_Iterator&y);

void bbGCMark(const t_std_collections_Stack_1Tt_mx2_Scope_2_Iterator&);

struct t_std_collections_Stack_1Tt_mx2_Scope_2_BackwardsIterator{
  const char *typeName()const{return "t_std_collections_Stack_1Tt_mx2_Scope_2_BackwardsIterator";}

  bbGCVar<t_std_collections_Stack_1Tt_mx2_Scope_2> m__0stack{};
  bbInt m__0index{};
  bbInt m__0seq{};

  t_std_collections_Stack_1Tt_mx2_Scope_2_BackwardsIterator(t_std_collections_Stack_1Tt_mx2_Scope_2* l_stack,bbInt l_index);

  void m_Insert(t_mx2_Scope* l_value);
  void m_Erase();
  void m_Current(t_mx2_Scope* l_current);
  t_mx2_Scope* m_Current();
  void m_Bump();
  bbBool m_AtEnd();
  void m_AssertSeq();
  void m_AssertCurrent();

  t_std_collections_Stack_1Tt_mx2_Scope_2_BackwardsIterator(){
  }

  t_std_collections_Stack_1Tt_mx2_Scope_2_BackwardsIterator(bbNullCtor_t){
  }
};

int bbCompare(const t_std_collections_Stack_1Tt_mx2_Scope_2_BackwardsIterator&x,const t_std_collections_Stack_1Tt_mx2_Scope_2_BackwardsIterator&y);

void bbGCMark(const t_std_collections_Stack_1Tt_mx2_Scope_2_BackwardsIterator&);

struct t_std_collections_Stack_1Tt_mx2_Scope_2 : public bbObject,public virtual t_std_collections_IContainer_1Tt_mx2_Scope_2{

  const char *typeName()const{return "t_std_collections_Stack_1Tt_mx2_Scope_2";}

  bbGCVar<bbArray<bbGCVar<t_mx2_Scope>>> m__0data{};
  bbInt m__0length{};
  bbInt m__0seq{};

  void gcMark();

  t_std_collections_Stack_1Tt_mx2_Scope_2(t_std_collections_List_1Tt_mx2_Scope_2* l_values);
  t_std_collections_Stack_1Tt_mx2_Scope_2(t_std_collections_Stack_1Tt_mx2_Scope_2* l_values);
  t_std_collections_Stack_1Tt_mx2_Scope_2(bbArray<bbGCVar<t_mx2_Scope>>* l_values);
  t_std_collections_Stack_1Tt_mx2_Scope_2(bbInt l_length);
  t_std_collections_Stack_1Tt_mx2_Scope_2();

  void m__idxeq(bbInt l_index,t_mx2_Scope* l_value);
  t_mx2_Scope* m__idx(bbInt l_index);
  t_mx2_Scope* m_Top();
  bbArray<bbGCVar<t_mx2_Scope>>* m_ToArray();
  void m_Swap(bbInt l_index1,bbInt l_index2);
  void m_Sort(bbFunction<bbInt(t_mx2_Scope*,t_mx2_Scope*)> l_compareFunc,bbInt l_lo,bbInt l_hi);
  void m_Sort(bbFunction<bbInt(t_mx2_Scope*,t_mx2_Scope*)> l_compareFunc);
  void m_Sort(bbBool l_ascending);
  t_std_collections_Stack_1Tt_mx2_Scope_2* m_Slice(bbInt l_index1,bbInt l_index2);
  t_std_collections_Stack_1Tt_mx2_Scope_2* m_Slice(bbInt l_index);
  void m_Set(bbInt l_index,t_mx2_Scope* l_value);
  void m_Resize(bbInt l_length);
  void m_Reserve(bbInt l_capacity);
  bbBool m_RemoveLast(t_mx2_Scope* l_value,bbInt l_start);
  bbInt m_RemoveEach(t_mx2_Scope* l_value);
  bbBool m_Remove(t_mx2_Scope* l_value,bbInt l_start);
  void m_Push(t_mx2_Scope* l_value);
  t_mx2_Scope* m_Pop();
  bbInt m_Length();
  void m_Insert(bbInt l_index,t_mx2_Scope* l_value);
  t_mx2_Scope* m_Get(bbInt l_index);
  bbInt m_FindLastIndex(t_mx2_Scope* l_value,bbInt l_start);
  bbInt m_FindIndex(t_mx2_Scope* l_value,bbInt l_start);
  void m_Erase(bbInt l_index1,bbInt l_index2);
  void m_Erase(bbInt l_index);
  bbBool m_Empty();
  bbArray<bbGCVar<t_mx2_Scope>>* m_Data();
  bbBool m_Contains(t_mx2_Scope* l_value);
  void m_Clear();
  bbInt m_Capacity();
  t_std_collections_Stack_1Tt_mx2_Scope_2_BackwardsIterator m_Backwards();
  t_std_collections_Stack_1Tt_mx2_Scope_2_Iterator m_All();
  void m_AddAll(bbArray<bbGCVar<t_mx2_Scope>>* l_values);
  void m_Add(t_mx2_Scope* l_value);
};

struct t_std_collections_Stack_1Tt_mx2_SNode_2_Iterator{
  const char *typeName()const{return "t_std_collections_Stack_1Tt_mx2_SNode_2_Iterator";}

  bbGCVar<t_std_collections_Stack_1Tt_mx2_SNode_2> m__0stack{};
  bbInt m__0index{};
  bbInt m__0seq{};

  t_std_collections_Stack_1Tt_mx2_SNode_2_Iterator(t_std_collections_Stack_1Tt_mx2_SNode_2* l_stack,bbInt l_index);

  void m_Insert(t_mx2_SNode* l_value);
  void m_Erase();
  void m_Current(t_mx2_SNode* l_current);
  t_mx2_SNode* m_Current();
  void m_Bump();
  bbBool m_AtEnd();
  void m_AssertSeq();
  void m_AssertCurrent();

  t_std_collections_Stack_1Tt_mx2_SNode_2_Iterator(){
  }

  t_std_collections_Stack_1Tt_mx2_SNode_2_Iterator(bbNullCtor_t){
  }
};

int bbCompare(const t_std_collections_Stack_1Tt_mx2_SNode_2_Iterator&x,const t_std_collections_Stack_1Tt_mx2_SNode_2_Iterator&y);

void bbGCMark(const t_std_collections_Stack_1Tt_mx2_SNode_2_Iterator&);

struct t_std_collections_Stack_1Tt_mx2_SNode_2_BackwardsIterator{
  const char *typeName()const{return "t_std_collections_Stack_1Tt_mx2_SNode_2_BackwardsIterator";}

  bbGCVar<t_std_collections_Stack_1Tt_mx2_SNode_2> m__0stack{};
  bbInt m__0index{};
  bbInt m__0seq{};

  t_std_collections_Stack_1Tt_mx2_SNode_2_BackwardsIterator(t_std_collections_Stack_1Tt_mx2_SNode_2* l_stack,bbInt l_index);

  void m_Insert(t_mx2_SNode* l_value);
  void m_Erase();
  void m_Current(t_mx2_SNode* l_current);
  t_mx2_SNode* m_Current();
  void m_Bump();
  bbBool m_AtEnd();
  void m_AssertSeq();
  void m_AssertCurrent();

  t_std_collections_Stack_1Tt_mx2_SNode_2_BackwardsIterator(){
  }

  t_std_collections_Stack_1Tt_mx2_SNode_2_BackwardsIterator(bbNullCtor_t){
  }
};

int bbCompare(const t_std_collections_Stack_1Tt_mx2_SNode_2_BackwardsIterator&x,const t_std_collections_Stack_1Tt_mx2_SNode_2_BackwardsIterator&y);

void bbGCMark(const t_std_collections_Stack_1Tt_mx2_SNode_2_BackwardsIterator&);

struct t_std_collections_Stack_1Tt_mx2_SNode_2 : public bbObject,public virtual t_std_collections_IContainer_1Tt_mx2_SNode_2{

  const char *typeName()const{return "t_std_collections_Stack_1Tt_mx2_SNode_2";}

  bbGCVar<bbArray<bbGCVar<t_mx2_SNode>>> m__0data{};
  bbInt m__0length{};
  bbInt m__0seq{};

  void gcMark();

  t_std_collections_Stack_1Tt_mx2_SNode_2(t_std_collections_List_1Tt_mx2_SNode_2* l_values);
  t_std_collections_Stack_1Tt_mx2_SNode_2(t_std_collections_Stack_1Tt_mx2_SNode_2* l_values);
  t_std_collections_Stack_1Tt_mx2_SNode_2(bbArray<bbGCVar<t_mx2_SNode>>* l_values);
  t_std_collections_Stack_1Tt_mx2_SNode_2(bbInt l_length);
  t_std_collections_Stack_1Tt_mx2_SNode_2();

  void m__idxeq(bbInt l_index,t_mx2_SNode* l_value);
  t_mx2_SNode* m__idx(bbInt l_index);
  t_mx2_SNode* m_Top();
  bbArray<bbGCVar<t_mx2_SNode>>* m_ToArray();
  void m_Swap(bbInt l_index1,bbInt l_index2);
  void m_Sort(bbFunction<bbInt(t_mx2_SNode*,t_mx2_SNode*)> l_compareFunc,bbInt l_lo,bbInt l_hi);
  void m_Sort(bbFunction<bbInt(t_mx2_SNode*,t_mx2_SNode*)> l_compareFunc);
  void m_Sort(bbBool l_ascending);
  t_std_collections_Stack_1Tt_mx2_SNode_2* m_Slice(bbInt l_index1,bbInt l_index2);
  t_std_collections_Stack_1Tt_mx2_SNode_2* m_Slice(bbInt l_index);
  void m_Set(bbInt l_index,t_mx2_SNode* l_value);
  void m_Resize(bbInt l_length);
  void m_Reserve(bbInt l_capacity);
  bbBool m_RemoveLast(t_mx2_SNode* l_value,bbInt l_start);
  bbInt m_RemoveEach(t_mx2_SNode* l_value);
  bbBool m_Remove(t_mx2_SNode* l_value,bbInt l_start);
  void m_Push(t_mx2_SNode* l_value);
  t_mx2_SNode* m_Pop();
  bbInt m_Length();
  void m_Insert(bbInt l_index,t_mx2_SNode* l_value);
  t_mx2_SNode* m_Get(bbInt l_index);
  bbInt m_FindLastIndex(t_mx2_SNode* l_value,bbInt l_start);
  bbInt m_FindIndex(t_mx2_SNode* l_value,bbInt l_start);
  void m_Erase(bbInt l_index1,bbInt l_index2);
  void m_Erase(bbInt l_index);
  bbBool m_Empty();
  bbArray<bbGCVar<t_mx2_SNode>>* m_Data();
  bbBool m_Contains(t_mx2_SNode* l_value);
  void m_Clear();
  bbInt m_Capacity();
  t_std_collections_Stack_1Tt_mx2_SNode_2_BackwardsIterator m_Backwards();
  t_std_collections_Stack_1Tt_mx2_SNode_2_Iterator m_All();
  void m_AddAll(bbArray<bbGCVar<t_mx2_SNode>>* l_values);
  void m_Add(t_mx2_SNode* l_value);
};

struct t_std_collections_Stack_1Tt_mx2_VarValue_2_Iterator{
  const char *typeName()const{return "t_std_collections_Stack_1Tt_mx2_VarValue_2_Iterator";}

  bbGCVar<t_std_collections_Stack_1Tt_mx2_VarValue_2> m__0stack{};
  bbInt m__0index{};
  bbInt m__0seq{};

  t_std_collections_Stack_1Tt_mx2_VarValue_2_Iterator(t_std_collections_Stack_1Tt_mx2_VarValue_2* l_stack,bbInt l_index);

  void m_Insert(t_mx2_VarValue* l_value);
  void m_Erase();
  void m_Current(t_mx2_VarValue* l_current);
  t_mx2_VarValue* m_Current();
  void m_Bump();
  bbBool m_AtEnd();
  void m_AssertSeq();
  void m_AssertCurrent();

  t_std_collections_Stack_1Tt_mx2_VarValue_2_Iterator(){
  }

  t_std_collections_Stack_1Tt_mx2_VarValue_2_Iterator(bbNullCtor_t){
  }
};

int bbCompare(const t_std_collections_Stack_1Tt_mx2_VarValue_2_Iterator&x,const t_std_collections_Stack_1Tt_mx2_VarValue_2_Iterator&y);

void bbGCMark(const t_std_collections_Stack_1Tt_mx2_VarValue_2_Iterator&);

struct t_std_collections_Stack_1Tt_mx2_VarValue_2_BackwardsIterator{
  const char *typeName()const{return "t_std_collections_Stack_1Tt_mx2_VarValue_2_BackwardsIterator";}

  bbGCVar<t_std_collections_Stack_1Tt_mx2_VarValue_2> m__0stack{};
  bbInt m__0index{};
  bbInt m__0seq{};

  t_std_collections_Stack_1Tt_mx2_VarValue_2_BackwardsIterator(t_std_collections_Stack_1Tt_mx2_VarValue_2* l_stack,bbInt l_index);

  void m_Insert(t_mx2_VarValue* l_value);
  void m_Erase();
  void m_Current(t_mx2_VarValue* l_current);
  t_mx2_VarValue* m_Current();
  void m_Bump();
  bbBool m_AtEnd();
  void m_AssertSeq();
  void m_AssertCurrent();

  t_std_collections_Stack_1Tt_mx2_VarValue_2_BackwardsIterator(){
  }

  t_std_collections_Stack_1Tt_mx2_VarValue_2_BackwardsIterator(bbNullCtor_t){
  }
};

int bbCompare(const t_std_collections_Stack_1Tt_mx2_VarValue_2_BackwardsIterator&x,const t_std_collections_Stack_1Tt_mx2_VarValue_2_BackwardsIterator&y);

void bbGCMark(const t_std_collections_Stack_1Tt_mx2_VarValue_2_BackwardsIterator&);

struct t_std_collections_Stack_1Tt_mx2_VarValue_2 : public bbObject,public virtual t_std_collections_IContainer_1Tt_mx2_VarValue_2{

  const char *typeName()const{return "t_std_collections_Stack_1Tt_mx2_VarValue_2";}

  bbGCVar<bbArray<bbGCVar<t_mx2_VarValue>>> m__0data{};
  bbInt m__0length{};
  bbInt m__0seq{};

  void gcMark();

  t_std_collections_Stack_1Tt_mx2_VarValue_2(t_std_collections_List_1Tt_mx2_VarValue_2* l_values);
  t_std_collections_Stack_1Tt_mx2_VarValue_2(t_std_collections_Stack_1Tt_mx2_VarValue_2* l_values);
  t_std_collections_Stack_1Tt_mx2_VarValue_2(bbArray<bbGCVar<t_mx2_VarValue>>* l_values);
  t_std_collections_Stack_1Tt_mx2_VarValue_2(bbInt l_length);
  t_std_collections_Stack_1Tt_mx2_VarValue_2();

  void m__idxeq(bbInt l_index,t_mx2_VarValue* l_value);
  t_mx2_VarValue* m__idx(bbInt l_index);
  t_mx2_VarValue* m_Top();
  bbArray<bbGCVar<t_mx2_VarValue>>* m_ToArray();
  void m_Swap(bbInt l_index1,bbInt l_index2);
  void m_Sort(bbFunction<bbInt(t_mx2_VarValue*,t_mx2_VarValue*)> l_compareFunc,bbInt l_lo,bbInt l_hi);
  void m_Sort(bbFunction<bbInt(t_mx2_VarValue*,t_mx2_VarValue*)> l_compareFunc);
  void m_Sort(bbBool l_ascending);
  t_std_collections_Stack_1Tt_mx2_VarValue_2* m_Slice(bbInt l_index1,bbInt l_index2);
  t_std_collections_Stack_1Tt_mx2_VarValue_2* m_Slice(bbInt l_index);
  void m_Set(bbInt l_index,t_mx2_VarValue* l_value);
  void m_Resize(bbInt l_length);
  void m_Reserve(bbInt l_capacity);
  bbBool m_RemoveLast(t_mx2_VarValue* l_value,bbInt l_start);
  bbInt m_RemoveEach(t_mx2_VarValue* l_value);
  bbBool m_Remove(t_mx2_VarValue* l_value,bbInt l_start);
  void m_Push(t_mx2_VarValue* l_value);
  t_mx2_VarValue* m_Pop();
  bbInt m_Length();
  void m_Insert(bbInt l_index,t_mx2_VarValue* l_value);
  t_mx2_VarValue* m_Get(bbInt l_index);
  bbInt m_FindLastIndex(t_mx2_VarValue* l_value,bbInt l_start);
  bbInt m_FindIndex(t_mx2_VarValue* l_value,bbInt l_start);
  void m_Erase(bbInt l_index1,bbInt l_index2);
  void m_Erase(bbInt l_index);
  bbBool m_Empty();
  bbArray<bbGCVar<t_mx2_VarValue>>* m_Data();
  bbBool m_Contains(t_mx2_VarValue* l_value);
  void m_Clear();
  bbInt m_Capacity();
  t_std_collections_Stack_1Tt_mx2_VarValue_2_BackwardsIterator m_Backwards();
  t_std_collections_Stack_1Tt_mx2_VarValue_2_Iterator m_All();
  void m_AddAll(bbArray<bbGCVar<t_mx2_VarValue>>* l_values);
  void m_Add(t_mx2_VarValue* l_value);
};

struct t_std_collections_Stack_1Tt_std_collections_Stack_1s_2_Iterator{
  const char *typeName()const{return "t_std_collections_Stack_1Tt_std_collections_Stack_1s_2_Iterator";}

  bbGCVar<t_std_collections_Stack_1Tt_std_collections_Stack_1s_2> m__0stack{};
  bbInt m__0index{};
  bbInt m__0seq{};

  t_std_collections_Stack_1Tt_std_collections_Stack_1s_2_Iterator(t_std_collections_Stack_1Tt_std_collections_Stack_1s_2* l_stack,bbInt l_index);

  void m_Insert(t_std_collections_Stack_1s* l_value);
  void m_Erase();
  void m_Current(t_std_collections_Stack_1s* l_current);
  t_std_collections_Stack_1s* m_Current();
  void m_Bump();
  bbBool m_AtEnd();
  void m_AssertSeq();
  void m_AssertCurrent();

  t_std_collections_Stack_1Tt_std_collections_Stack_1s_2_Iterator(){
  }

  t_std_collections_Stack_1Tt_std_collections_Stack_1s_2_Iterator(bbNullCtor_t){
  }
};

int bbCompare(const t_std_collections_Stack_1Tt_std_collections_Stack_1s_2_Iterator&x,const t_std_collections_Stack_1Tt_std_collections_Stack_1s_2_Iterator&y);

void bbGCMark(const t_std_collections_Stack_1Tt_std_collections_Stack_1s_2_Iterator&);

struct t_std_collections_Stack_1Tt_std_collections_Stack_1s_2_BackwardsIterator{
  const char *typeName()const{return "t_std_collections_Stack_1Tt_std_collections_Stack_1s_2_BackwardsIterator";}

  bbGCVar<t_std_collections_Stack_1Tt_std_collections_Stack_1s_2> m__0stack{};
  bbInt m__0index{};
  bbInt m__0seq{};

  t_std_collections_Stack_1Tt_std_collections_Stack_1s_2_BackwardsIterator(t_std_collections_Stack_1Tt_std_collections_Stack_1s_2* l_stack,bbInt l_index);

  void m_Insert(t_std_collections_Stack_1s* l_value);
  void m_Erase();
  void m_Current(t_std_collections_Stack_1s* l_current);
  t_std_collections_Stack_1s* m_Current();
  void m_Bump();
  bbBool m_AtEnd();
  void m_AssertSeq();
  void m_AssertCurrent();

  t_std_collections_Stack_1Tt_std_collections_Stack_1s_2_BackwardsIterator(){
  }

  t_std_collections_Stack_1Tt_std_collections_Stack_1s_2_BackwardsIterator(bbNullCtor_t){
  }
};

int bbCompare(const t_std_collections_Stack_1Tt_std_collections_Stack_1s_2_BackwardsIterator&x,const t_std_collections_Stack_1Tt_std_collections_Stack_1s_2_BackwardsIterator&y);

void bbGCMark(const t_std_collections_Stack_1Tt_std_collections_Stack_1s_2_BackwardsIterator&);

struct t_std_collections_Stack_1Tt_std_collections_Stack_1s_2 : public bbObject,public virtual t_std_collections_IContainer_1Tt_std_collections_Stack_1s_2{

  const char *typeName()const{return "t_std_collections_Stack_1Tt_std_collections_Stack_1s_2";}

  bbGCVar<bbArray<bbGCVar<t_std_collections_Stack_1s>>> m__0data{};
  bbInt m__0length{};
  bbInt m__0seq{};

  void gcMark();

  t_std_collections_Stack_1Tt_std_collections_Stack_1s_2(t_std_collections_List_1Tt_std_collections_Stack_1s_2* l_values);
  t_std_collections_Stack_1Tt_std_collections_Stack_1s_2(t_std_collections_Stack_1Tt_std_collections_Stack_1s_2* l_values);
  t_std_collections_Stack_1Tt_std_collections_Stack_1s_2(bbArray<bbGCVar<t_std_collections_Stack_1s>>* l_values);
  t_std_collections_Stack_1Tt_std_collections_Stack_1s_2(bbInt l_length);
  t_std_collections_Stack_1Tt_std_collections_Stack_1s_2();

  void m__idxeq(bbInt l_index,t_std_collections_Stack_1s* l_value);
  t_std_collections_Stack_1s* m__idx(bbInt l_index);
  t_std_collections_Stack_1s* m_Top();
  bbArray<bbGCVar<t_std_collections_Stack_1s>>* m_ToArray();
  void m_Swap(bbInt l_index1,bbInt l_index2);
  void m_Sort(bbFunction<bbInt(t_std_collections_Stack_1s*,t_std_collections_Stack_1s*)> l_compareFunc,bbInt l_lo,bbInt l_hi);
  void m_Sort(bbFunction<bbInt(t_std_collections_Stack_1s*,t_std_collections_Stack_1s*)> l_compareFunc);
  void m_Sort(bbBool l_ascending);
  t_std_collections_Stack_1Tt_std_collections_Stack_1s_2* m_Slice(bbInt l_index1,bbInt l_index2);
  t_std_collections_Stack_1Tt_std_collections_Stack_1s_2* m_Slice(bbInt l_index);
  void m_Set(bbInt l_index,t_std_collections_Stack_1s* l_value);
  void m_Resize(bbInt l_length);
  void m_Reserve(bbInt l_capacity);
  bbBool m_RemoveLast(t_std_collections_Stack_1s* l_value,bbInt l_start);
  bbInt m_RemoveEach(t_std_collections_Stack_1s* l_value);
  bbBool m_Remove(t_std_collections_Stack_1s* l_value,bbInt l_start);
  void m_Push(t_std_collections_Stack_1s* l_value);
  t_std_collections_Stack_1s* m_Pop();
  bbInt m_Length();
  void m_Insert(bbInt l_index,t_std_collections_Stack_1s* l_value);
  t_std_collections_Stack_1s* m_Get(bbInt l_index);
  bbInt m_FindLastIndex(t_std_collections_Stack_1s* l_value,bbInt l_start);
  bbInt m_FindIndex(t_std_collections_Stack_1s* l_value,bbInt l_start);
  void m_Erase(bbInt l_index1,bbInt l_index2);
  void m_Erase(bbInt l_index);
  bbBool m_Empty();
  bbArray<bbGCVar<t_std_collections_Stack_1s>>* m_Data();
  bbBool m_Contains(t_std_collections_Stack_1s* l_value);
  void m_Clear();
  bbInt m_Capacity();
  t_std_collections_Stack_1Tt_std_collections_Stack_1s_2_BackwardsIterator m_Backwards();
  t_std_collections_Stack_1Tt_std_collections_Stack_1s_2_Iterator m_All();
  void m_AddAll(bbArray<bbGCVar<t_std_collections_Stack_1s>>* l_values);
  void m_Add(t_std_collections_Stack_1s* l_value);
};

struct t_std_collections_Stack_1Tt_mx2_FileDecl_2_Iterator{
  const char *typeName()const{return "t_std_collections_Stack_1Tt_mx2_FileDecl_2_Iterator";}

  bbGCVar<t_std_collections_Stack_1Tt_mx2_FileDecl_2> m__0stack{};
  bbInt m__0index{};
  bbInt m__0seq{};

  t_std_collections_Stack_1Tt_mx2_FileDecl_2_Iterator(t_std_collections_Stack_1Tt_mx2_FileDecl_2* l_stack,bbInt l_index);

  void m_Insert(t_mx2_FileDecl* l_value);
  void m_Erase();
  void m_Current(t_mx2_FileDecl* l_current);
  t_mx2_FileDecl* m_Current();
  void m_Bump();
  bbBool m_AtEnd();
  void m_AssertSeq();
  void m_AssertCurrent();

  t_std_collections_Stack_1Tt_mx2_FileDecl_2_Iterator(){
  }

  t_std_collections_Stack_1Tt_mx2_FileDecl_2_Iterator(bbNullCtor_t){
  }
};

int bbCompare(const t_std_collections_Stack_1Tt_mx2_FileDecl_2_Iterator&x,const t_std_collections_Stack_1Tt_mx2_FileDecl_2_Iterator&y);

void bbGCMark(const t_std_collections_Stack_1Tt_mx2_FileDecl_2_Iterator&);

struct t_std_collections_Stack_1Tt_mx2_FileDecl_2_BackwardsIterator{
  const char *typeName()const{return "t_std_collections_Stack_1Tt_mx2_FileDecl_2_BackwardsIterator";}

  bbGCVar<t_std_collections_Stack_1Tt_mx2_FileDecl_2> m__0stack{};
  bbInt m__0index{};
  bbInt m__0seq{};

  t_std_collections_Stack_1Tt_mx2_FileDecl_2_BackwardsIterator(t_std_collections_Stack_1Tt_mx2_FileDecl_2* l_stack,bbInt l_index);

  void m_Insert(t_mx2_FileDecl* l_value);
  void m_Erase();
  void m_Current(t_mx2_FileDecl* l_current);
  t_mx2_FileDecl* m_Current();
  void m_Bump();
  bbBool m_AtEnd();
  void m_AssertSeq();
  void m_AssertCurrent();

  t_std_collections_Stack_1Tt_mx2_FileDecl_2_BackwardsIterator(){
  }

  t_std_collections_Stack_1Tt_mx2_FileDecl_2_BackwardsIterator(bbNullCtor_t){
  }
};

int bbCompare(const t_std_collections_Stack_1Tt_mx2_FileDecl_2_BackwardsIterator&x,const t_std_collections_Stack_1Tt_mx2_FileDecl_2_BackwardsIterator&y);

void bbGCMark(const t_std_collections_Stack_1Tt_mx2_FileDecl_2_BackwardsIterator&);

struct t_std_collections_Stack_1Tt_mx2_FileDecl_2 : public bbObject,public virtual t_std_collections_IContainer_1Tt_mx2_FileDecl_2{

  const char *typeName()const{return "t_std_collections_Stack_1Tt_mx2_FileDecl_2";}

  bbGCVar<bbArray<bbGCVar<t_mx2_FileDecl>>> m__0data{};
  bbInt m__0length{};
  bbInt m__0seq{};

  void gcMark();

  t_std_collections_Stack_1Tt_mx2_FileDecl_2(t_std_collections_List_1Tt_mx2_FileDecl_2* l_values);
  t_std_collections_Stack_1Tt_mx2_FileDecl_2(t_std_collections_Stack_1Tt_mx2_FileDecl_2* l_values);
  t_std_collections_Stack_1Tt_mx2_FileDecl_2(bbArray<bbGCVar<t_mx2_FileDecl>>* l_values);
  t_std_collections_Stack_1Tt_mx2_FileDecl_2(bbInt l_length);
  t_std_collections_Stack_1Tt_mx2_FileDecl_2();

  void m__idxeq(bbInt l_index,t_mx2_FileDecl* l_value);
  t_mx2_FileDecl* m__idx(bbInt l_index);
  t_mx2_FileDecl* m_Top();
  bbArray<bbGCVar<t_mx2_FileDecl>>* m_ToArray();
  void m_Swap(bbInt l_index1,bbInt l_index2);
  void m_Sort(bbFunction<bbInt(t_mx2_FileDecl*,t_mx2_FileDecl*)> l_compareFunc,bbInt l_lo,bbInt l_hi);
  void m_Sort(bbFunction<bbInt(t_mx2_FileDecl*,t_mx2_FileDecl*)> l_compareFunc);
  void m_Sort(bbBool l_ascending);
  t_std_collections_Stack_1Tt_mx2_FileDecl_2* m_Slice(bbInt l_index1,bbInt l_index2);
  t_std_collections_Stack_1Tt_mx2_FileDecl_2* m_Slice(bbInt l_index);
  void m_Set(bbInt l_index,t_mx2_FileDecl* l_value);
  void m_Resize(bbInt l_length);
  void m_Reserve(bbInt l_capacity);
  bbBool m_RemoveLast(t_mx2_FileDecl* l_value,bbInt l_start);
  bbInt m_RemoveEach(t_mx2_FileDecl* l_value);
  bbBool m_Remove(t_mx2_FileDecl* l_value,bbInt l_start);
  void m_Push(t_mx2_FileDecl* l_value);
  t_mx2_FileDecl* m_Pop();
  bbInt m_Length();
  void m_Insert(bbInt l_index,t_mx2_FileDecl* l_value);
  t_mx2_FileDecl* m_Get(bbInt l_index);
  bbInt m_FindLastIndex(t_mx2_FileDecl* l_value,bbInt l_start);
  bbInt m_FindIndex(t_mx2_FileDecl* l_value,bbInt l_start);
  void m_Erase(bbInt l_index1,bbInt l_index2);
  void m_Erase(bbInt l_index);
  bbBool m_Empty();
  bbArray<bbGCVar<t_mx2_FileDecl>>* m_Data();
  bbBool m_Contains(t_mx2_FileDecl* l_value);
  void m_Clear();
  bbInt m_Capacity();
  t_std_collections_Stack_1Tt_mx2_FileDecl_2_BackwardsIterator m_Backwards();
  t_std_collections_Stack_1Tt_mx2_FileDecl_2_Iterator m_All();
  void m_AddAll(bbArray<bbGCVar<t_mx2_FileDecl>>* l_values);
  void m_Add(t_mx2_FileDecl* l_value);
};

struct t_std_collections_Stack_1Tt_mx2_FileScope_2_Iterator{
  const char *typeName()const{return "t_std_collections_Stack_1Tt_mx2_FileScope_2_Iterator";}

  bbGCVar<t_std_collections_Stack_1Tt_mx2_FileScope_2> m__0stack{};
  bbInt m__0index{};
  bbInt m__0seq{};

  t_std_collections_Stack_1Tt_mx2_FileScope_2_Iterator(t_std_collections_Stack_1Tt_mx2_FileScope_2* l_stack,bbInt l_index);

  void m_Insert(t_mx2_FileScope* l_value);
  void m_Erase();
  void m_Current(t_mx2_FileScope* l_current);
  t_mx2_FileScope* m_Current();
  void m_Bump();
  bbBool m_AtEnd();
  void m_AssertSeq();
  void m_AssertCurrent();

  t_std_collections_Stack_1Tt_mx2_FileScope_2_Iterator(){
  }

  t_std_collections_Stack_1Tt_mx2_FileScope_2_Iterator(bbNullCtor_t){
  }
};

int bbCompare(const t_std_collections_Stack_1Tt_mx2_FileScope_2_Iterator&x,const t_std_collections_Stack_1Tt_mx2_FileScope_2_Iterator&y);

void bbGCMark(const t_std_collections_Stack_1Tt_mx2_FileScope_2_Iterator&);

struct t_std_collections_Stack_1Tt_mx2_FileScope_2_BackwardsIterator{
  const char *typeName()const{return "t_std_collections_Stack_1Tt_mx2_FileScope_2_BackwardsIterator";}

  bbGCVar<t_std_collections_Stack_1Tt_mx2_FileScope_2> m__0stack{};
  bbInt m__0index{};
  bbInt m__0seq{};

  t_std_collections_Stack_1Tt_mx2_FileScope_2_BackwardsIterator(t_std_collections_Stack_1Tt_mx2_FileScope_2* l_stack,bbInt l_index);

  void m_Insert(t_mx2_FileScope* l_value);
  void m_Erase();
  void m_Current(t_mx2_FileScope* l_current);
  t_mx2_FileScope* m_Current();
  void m_Bump();
  bbBool m_AtEnd();
  void m_AssertSeq();
  void m_AssertCurrent();

  t_std_collections_Stack_1Tt_mx2_FileScope_2_BackwardsIterator(){
  }

  t_std_collections_Stack_1Tt_mx2_FileScope_2_BackwardsIterator(bbNullCtor_t){
  }
};

int bbCompare(const t_std_collections_Stack_1Tt_mx2_FileScope_2_BackwardsIterator&x,const t_std_collections_Stack_1Tt_mx2_FileScope_2_BackwardsIterator&y);

void bbGCMark(const t_std_collections_Stack_1Tt_mx2_FileScope_2_BackwardsIterator&);

struct t_std_collections_Stack_1Tt_mx2_FileScope_2 : public bbObject,public virtual t_std_collections_IContainer_1Tt_mx2_FileScope_2{

  const char *typeName()const{return "t_std_collections_Stack_1Tt_mx2_FileScope_2";}

  bbGCVar<bbArray<bbGCVar<t_mx2_FileScope>>> m__0data{};
  bbInt m__0length{};
  bbInt m__0seq{};

  void gcMark();

  t_std_collections_Stack_1Tt_mx2_FileScope_2(t_std_collections_List_1Tt_mx2_FileScope_2* l_values);
  t_std_collections_Stack_1Tt_mx2_FileScope_2(t_std_collections_Stack_1Tt_mx2_FileScope_2* l_values);
  t_std_collections_Stack_1Tt_mx2_FileScope_2(bbArray<bbGCVar<t_mx2_FileScope>>* l_values);
  t_std_collections_Stack_1Tt_mx2_FileScope_2(bbInt l_length);
  t_std_collections_Stack_1Tt_mx2_FileScope_2();

  void m__idxeq(bbInt l_index,t_mx2_FileScope* l_value);
  t_mx2_FileScope* m__idx(bbInt l_index);
  t_mx2_FileScope* m_Top();
  bbArray<bbGCVar<t_mx2_FileScope>>* m_ToArray();
  void m_Swap(bbInt l_index1,bbInt l_index2);
  void m_Sort(bbFunction<bbInt(t_mx2_FileScope*,t_mx2_FileScope*)> l_compareFunc,bbInt l_lo,bbInt l_hi);
  void m_Sort(bbFunction<bbInt(t_mx2_FileScope*,t_mx2_FileScope*)> l_compareFunc);
  void m_Sort(bbBool l_ascending);
  t_std_collections_Stack_1Tt_mx2_FileScope_2* m_Slice(bbInt l_index1,bbInt l_index2);
  t_std_collections_Stack_1Tt_mx2_FileScope_2* m_Slice(bbInt l_index);
  void m_Set(bbInt l_index,t_mx2_FileScope* l_value);
  void m_Resize(bbInt l_length);
  void m_Reserve(bbInt l_capacity);
  bbBool m_RemoveLast(t_mx2_FileScope* l_value,bbInt l_start);
  bbInt m_RemoveEach(t_mx2_FileScope* l_value);
  bbBool m_Remove(t_mx2_FileScope* l_value,bbInt l_start);
  void m_Push(t_mx2_FileScope* l_value);
  t_mx2_FileScope* m_Pop();
  bbInt m_Length();
  void m_Insert(bbInt l_index,t_mx2_FileScope* l_value);
  t_mx2_FileScope* m_Get(bbInt l_index);
  bbInt m_FindLastIndex(t_mx2_FileScope* l_value,bbInt l_start);
  bbInt m_FindIndex(t_mx2_FileScope* l_value,bbInt l_start);
  void m_Erase(bbInt l_index1,bbInt l_index2);
  void m_Erase(bbInt l_index);
  bbBool m_Empty();
  bbArray<bbGCVar<t_mx2_FileScope>>* m_Data();
  bbBool m_Contains(t_mx2_FileScope* l_value);
  void m_Clear();
  bbInt m_Capacity();
  t_std_collections_Stack_1Tt_mx2_FileScope_2_BackwardsIterator m_Backwards();
  t_std_collections_Stack_1Tt_mx2_FileScope_2_Iterator m_All();
  void m_AddAll(bbArray<bbGCVar<t_mx2_FileScope>>* l_values);
  void m_Add(t_mx2_FileScope* l_value);
};

struct t_std_collections_Stack_1Tt_mx2_NamespaceScope_2_Iterator{
  const char *typeName()const{return "t_std_collections_Stack_1Tt_mx2_NamespaceScope_2_Iterator";}

  bbGCVar<t_std_collections_Stack_1Tt_mx2_NamespaceScope_2> m__0stack{};
  bbInt m__0index{};
  bbInt m__0seq{};

  t_std_collections_Stack_1Tt_mx2_NamespaceScope_2_Iterator(t_std_collections_Stack_1Tt_mx2_NamespaceScope_2* l_stack,bbInt l_index);

  void m_Insert(t_mx2_NamespaceScope* l_value);
  void m_Erase();
  void m_Current(t_mx2_NamespaceScope* l_current);
  t_mx2_NamespaceScope* m_Current();
  void m_Bump();
  bbBool m_AtEnd();
  void m_AssertSeq();
  void m_AssertCurrent();

  t_std_collections_Stack_1Tt_mx2_NamespaceScope_2_Iterator(){
  }

  t_std_collections_Stack_1Tt_mx2_NamespaceScope_2_Iterator(bbNullCtor_t){
  }
};

int bbCompare(const t_std_collections_Stack_1Tt_mx2_NamespaceScope_2_Iterator&x,const t_std_collections_Stack_1Tt_mx2_NamespaceScope_2_Iterator&y);

void bbGCMark(const t_std_collections_Stack_1Tt_mx2_NamespaceScope_2_Iterator&);

struct t_std_collections_Stack_1Tt_mx2_NamespaceScope_2_BackwardsIterator{
  const char *typeName()const{return "t_std_collections_Stack_1Tt_mx2_NamespaceScope_2_BackwardsIterator";}

  bbGCVar<t_std_collections_Stack_1Tt_mx2_NamespaceScope_2> m__0stack{};
  bbInt m__0index{};
  bbInt m__0seq{};

  t_std_collections_Stack_1Tt_mx2_NamespaceScope_2_BackwardsIterator(t_std_collections_Stack_1Tt_mx2_NamespaceScope_2* l_stack,bbInt l_index);

  void m_Insert(t_mx2_NamespaceScope* l_value);
  void m_Erase();
  void m_Current(t_mx2_NamespaceScope* l_current);
  t_mx2_NamespaceScope* m_Current();
  void m_Bump();
  bbBool m_AtEnd();
  void m_AssertSeq();
  void m_AssertCurrent();

  t_std_collections_Stack_1Tt_mx2_NamespaceScope_2_BackwardsIterator(){
  }

  t_std_collections_Stack_1Tt_mx2_NamespaceScope_2_BackwardsIterator(bbNullCtor_t){
  }
};

int bbCompare(const t_std_collections_Stack_1Tt_mx2_NamespaceScope_2_BackwardsIterator&x,const t_std_collections_Stack_1Tt_mx2_NamespaceScope_2_BackwardsIterator&y);

void bbGCMark(const t_std_collections_Stack_1Tt_mx2_NamespaceScope_2_BackwardsIterator&);

struct t_std_collections_Stack_1Tt_mx2_NamespaceScope_2 : public bbObject,public virtual t_std_collections_IContainer_1Tt_mx2_NamespaceScope_2{

  const char *typeName()const{return "t_std_collections_Stack_1Tt_mx2_NamespaceScope_2";}

  bbGCVar<bbArray<bbGCVar<t_mx2_NamespaceScope>>> m__0data{};
  bbInt m__0length{};
  bbInt m__0seq{};

  void gcMark();

  t_std_collections_Stack_1Tt_mx2_NamespaceScope_2(t_std_collections_List_1Tt_mx2_NamespaceScope_2* l_values);
  t_std_collections_Stack_1Tt_mx2_NamespaceScope_2(t_std_collections_Stack_1Tt_mx2_NamespaceScope_2* l_values);
  t_std_collections_Stack_1Tt_mx2_NamespaceScope_2(bbArray<bbGCVar<t_mx2_NamespaceScope>>* l_values);
  t_std_collections_Stack_1Tt_mx2_NamespaceScope_2(bbInt l_length);
  t_std_collections_Stack_1Tt_mx2_NamespaceScope_2();

  void m__idxeq(bbInt l_index,t_mx2_NamespaceScope* l_value);
  t_mx2_NamespaceScope* m__idx(bbInt l_index);
  t_mx2_NamespaceScope* m_Top();
  bbArray<bbGCVar<t_mx2_NamespaceScope>>* m_ToArray();
  void m_Swap(bbInt l_index1,bbInt l_index2);
  void m_Sort(bbFunction<bbInt(t_mx2_NamespaceScope*,t_mx2_NamespaceScope*)> l_compareFunc,bbInt l_lo,bbInt l_hi);
  void m_Sort(bbFunction<bbInt(t_mx2_NamespaceScope*,t_mx2_NamespaceScope*)> l_compareFunc);
  void m_Sort(bbBool l_ascending);
  t_std_collections_Stack_1Tt_mx2_NamespaceScope_2* m_Slice(bbInt l_index1,bbInt l_index2);
  t_std_collections_Stack_1Tt_mx2_NamespaceScope_2* m_Slice(bbInt l_index);
  void m_Set(bbInt l_index,t_mx2_NamespaceScope* l_value);
  void m_Resize(bbInt l_length);
  void m_Reserve(bbInt l_capacity);
  bbBool m_RemoveLast(t_mx2_NamespaceScope* l_value,bbInt l_start);
  bbInt m_RemoveEach(t_mx2_NamespaceScope* l_value);
  bbBool m_Remove(t_mx2_NamespaceScope* l_value,bbInt l_start);
  void m_Push(t_mx2_NamespaceScope* l_value);
  t_mx2_NamespaceScope* m_Pop();
  bbInt m_Length();
  void m_Insert(bbInt l_index,t_mx2_NamespaceScope* l_value);
  t_mx2_NamespaceScope* m_Get(bbInt l_index);
  bbInt m_FindLastIndex(t_mx2_NamespaceScope* l_value,bbInt l_start);
  bbInt m_FindIndex(t_mx2_NamespaceScope* l_value,bbInt l_start);
  void m_Erase(bbInt l_index1,bbInt l_index2);
  void m_Erase(bbInt l_index);
  bbBool m_Empty();
  bbArray<bbGCVar<t_mx2_NamespaceScope>>* m_Data();
  bbBool m_Contains(t_mx2_NamespaceScope* l_value);
  void m_Clear();
  bbInt m_Capacity();
  t_std_collections_Stack_1Tt_mx2_NamespaceScope_2_BackwardsIterator m_Backwards();
  t_std_collections_Stack_1Tt_mx2_NamespaceScope_2_Iterator m_All();
  void m_AddAll(bbArray<bbGCVar<t_mx2_NamespaceScope>>* l_values);
  void m_Add(t_mx2_NamespaceScope* l_value);
};

struct t_std_collections_Stack_1Tt_mx2_PNode_2_Iterator{
  const char *typeName()const{return "t_std_collections_Stack_1Tt_mx2_PNode_2_Iterator";}

  bbGCVar<t_std_collections_Stack_1Tt_mx2_PNode_2> m__0stack{};
  bbInt m__0index{};
  bbInt m__0seq{};

  t_std_collections_Stack_1Tt_mx2_PNode_2_Iterator(t_std_collections_Stack_1Tt_mx2_PNode_2* l_stack,bbInt l_index);

  void m_Insert(t_mx2_PNode* l_value);
  void m_Erase();
  void m_Current(t_mx2_PNode* l_current);
  t_mx2_PNode* m_Current();
  void m_Bump();
  bbBool m_AtEnd();
  void m_AssertSeq();
  void m_AssertCurrent();

  t_std_collections_Stack_1Tt_mx2_PNode_2_Iterator(){
  }

  t_std_collections_Stack_1Tt_mx2_PNode_2_Iterator(bbNullCtor_t){
  }
};

int bbCompare(const t_std_collections_Stack_1Tt_mx2_PNode_2_Iterator&x,const t_std_collections_Stack_1Tt_mx2_PNode_2_Iterator&y);

void bbGCMark(const t_std_collections_Stack_1Tt_mx2_PNode_2_Iterator&);

struct t_std_collections_Stack_1Tt_mx2_PNode_2_BackwardsIterator{
  const char *typeName()const{return "t_std_collections_Stack_1Tt_mx2_PNode_2_BackwardsIterator";}

  bbGCVar<t_std_collections_Stack_1Tt_mx2_PNode_2> m__0stack{};
  bbInt m__0index{};
  bbInt m__0seq{};

  t_std_collections_Stack_1Tt_mx2_PNode_2_BackwardsIterator(t_std_collections_Stack_1Tt_mx2_PNode_2* l_stack,bbInt l_index);

  void m_Insert(t_mx2_PNode* l_value);
  void m_Erase();
  void m_Current(t_mx2_PNode* l_current);
  t_mx2_PNode* m_Current();
  void m_Bump();
  bbBool m_AtEnd();
  void m_AssertSeq();
  void m_AssertCurrent();

  t_std_collections_Stack_1Tt_mx2_PNode_2_BackwardsIterator(){
  }

  t_std_collections_Stack_1Tt_mx2_PNode_2_BackwardsIterator(bbNullCtor_t){
  }
};

int bbCompare(const t_std_collections_Stack_1Tt_mx2_PNode_2_BackwardsIterator&x,const t_std_collections_Stack_1Tt_mx2_PNode_2_BackwardsIterator&y);

void bbGCMark(const t_std_collections_Stack_1Tt_mx2_PNode_2_BackwardsIterator&);

struct t_std_collections_Stack_1Tt_mx2_PNode_2 : public bbObject,public virtual t_std_collections_IContainer_1Tt_mx2_PNode_2{

  const char *typeName()const{return "t_std_collections_Stack_1Tt_mx2_PNode_2";}

  bbGCVar<bbArray<bbGCVar<t_mx2_PNode>>> m__0data{};
  bbInt m__0length{};
  bbInt m__0seq{};

  void gcMark();

  t_std_collections_Stack_1Tt_mx2_PNode_2(t_std_collections_List_1Tt_mx2_PNode_2* l_values);
  t_std_collections_Stack_1Tt_mx2_PNode_2(t_std_collections_Stack_1Tt_mx2_PNode_2* l_values);
  t_std_collections_Stack_1Tt_mx2_PNode_2(bbArray<bbGCVar<t_mx2_PNode>>* l_values);
  t_std_collections_Stack_1Tt_mx2_PNode_2(bbInt l_length);
  t_std_collections_Stack_1Tt_mx2_PNode_2();

  void m__idxeq(bbInt l_index,t_mx2_PNode* l_value);
  t_mx2_PNode* m__idx(bbInt l_index);
  t_mx2_PNode* m_Top();
  bbArray<bbGCVar<t_mx2_PNode>>* m_ToArray();
  void m_Swap(bbInt l_index1,bbInt l_index2);
  void m_Sort(bbFunction<bbInt(t_mx2_PNode*,t_mx2_PNode*)> l_compareFunc,bbInt l_lo,bbInt l_hi);
  void m_Sort(bbFunction<bbInt(t_mx2_PNode*,t_mx2_PNode*)> l_compareFunc);
  void m_Sort(bbBool l_ascending);
  t_std_collections_Stack_1Tt_mx2_PNode_2* m_Slice(bbInt l_index1,bbInt l_index2);
  t_std_collections_Stack_1Tt_mx2_PNode_2* m_Slice(bbInt l_index);
  void m_Set(bbInt l_index,t_mx2_PNode* l_value);
  void m_Resize(bbInt l_length);
  void m_Reserve(bbInt l_capacity);
  bbBool m_RemoveLast(t_mx2_PNode* l_value,bbInt l_start);
  bbInt m_RemoveEach(t_mx2_PNode* l_value);
  bbBool m_Remove(t_mx2_PNode* l_value,bbInt l_start);
  void m_Push(t_mx2_PNode* l_value);
  t_mx2_PNode* m_Pop();
  bbInt m_Length();
  void m_Insert(bbInt l_index,t_mx2_PNode* l_value);
  t_mx2_PNode* m_Get(bbInt l_index);
  bbInt m_FindLastIndex(t_mx2_PNode* l_value,bbInt l_start);
  bbInt m_FindIndex(t_mx2_PNode* l_value,bbInt l_start);
  void m_Erase(bbInt l_index1,bbInt l_index2);
  void m_Erase(bbInt l_index);
  bbBool m_Empty();
  bbArray<bbGCVar<t_mx2_PNode>>* m_Data();
  bbBool m_Contains(t_mx2_PNode* l_value);
  void m_Clear();
  bbInt m_Capacity();
  t_std_collections_Stack_1Tt_mx2_PNode_2_BackwardsIterator m_Backwards();
  t_std_collections_Stack_1Tt_mx2_PNode_2_Iterator m_All();
  void m_AddAll(bbArray<bbGCVar<t_mx2_PNode>>* l_values);
  void m_Add(t_mx2_PNode* l_value);
};

struct t_std_collections_Stack_1Tt_mx2_AliasType_2_Iterator{
  const char *typeName()const{return "t_std_collections_Stack_1Tt_mx2_AliasType_2_Iterator";}

  bbGCVar<t_std_collections_Stack_1Tt_mx2_AliasType_2> m__0stack{};
  bbInt m__0index{};
  bbInt m__0seq{};

  t_std_collections_Stack_1Tt_mx2_AliasType_2_Iterator(t_std_collections_Stack_1Tt_mx2_AliasType_2* l_stack,bbInt l_index);

  void m_Insert(t_mx2_AliasType* l_value);
  void m_Erase();
  void m_Current(t_mx2_AliasType* l_current);
  t_mx2_AliasType* m_Current();
  void m_Bump();
  bbBool m_AtEnd();
  void m_AssertSeq();
  void m_AssertCurrent();

  t_std_collections_Stack_1Tt_mx2_AliasType_2_Iterator(){
  }

  t_std_collections_Stack_1Tt_mx2_AliasType_2_Iterator(bbNullCtor_t){
  }
};

int bbCompare(const t_std_collections_Stack_1Tt_mx2_AliasType_2_Iterator&x,const t_std_collections_Stack_1Tt_mx2_AliasType_2_Iterator&y);

void bbGCMark(const t_std_collections_Stack_1Tt_mx2_AliasType_2_Iterator&);

struct t_std_collections_Stack_1Tt_mx2_AliasType_2_BackwardsIterator{
  const char *typeName()const{return "t_std_collections_Stack_1Tt_mx2_AliasType_2_BackwardsIterator";}

  bbGCVar<t_std_collections_Stack_1Tt_mx2_AliasType_2> m__0stack{};
  bbInt m__0index{};
  bbInt m__0seq{};

  t_std_collections_Stack_1Tt_mx2_AliasType_2_BackwardsIterator(t_std_collections_Stack_1Tt_mx2_AliasType_2* l_stack,bbInt l_index);

  void m_Insert(t_mx2_AliasType* l_value);
  void m_Erase();
  void m_Current(t_mx2_AliasType* l_current);
  t_mx2_AliasType* m_Current();
  void m_Bump();
  bbBool m_AtEnd();
  void m_AssertSeq();
  void m_AssertCurrent();

  t_std_collections_Stack_1Tt_mx2_AliasType_2_BackwardsIterator(){
  }

  t_std_collections_Stack_1Tt_mx2_AliasType_2_BackwardsIterator(bbNullCtor_t){
  }
};

int bbCompare(const t_std_collections_Stack_1Tt_mx2_AliasType_2_BackwardsIterator&x,const t_std_collections_Stack_1Tt_mx2_AliasType_2_BackwardsIterator&y);

void bbGCMark(const t_std_collections_Stack_1Tt_mx2_AliasType_2_BackwardsIterator&);

struct t_std_collections_Stack_1Tt_mx2_AliasType_2 : public bbObject,public virtual t_std_collections_IContainer_1Tt_mx2_AliasType_2{

  const char *typeName()const{return "t_std_collections_Stack_1Tt_mx2_AliasType_2";}

  bbGCVar<bbArray<bbGCVar<t_mx2_AliasType>>> m__0data{};
  bbInt m__0length{};
  bbInt m__0seq{};

  void gcMark();

  t_std_collections_Stack_1Tt_mx2_AliasType_2(t_std_collections_List_1Tt_mx2_AliasType_2* l_values);
  t_std_collections_Stack_1Tt_mx2_AliasType_2(t_std_collections_Stack_1Tt_mx2_AliasType_2* l_values);
  t_std_collections_Stack_1Tt_mx2_AliasType_2(bbArray<bbGCVar<t_mx2_AliasType>>* l_values);
  t_std_collections_Stack_1Tt_mx2_AliasType_2(bbInt l_length);
  t_std_collections_Stack_1Tt_mx2_AliasType_2();

  void m__idxeq(bbInt l_index,t_mx2_AliasType* l_value);
  t_mx2_AliasType* m__idx(bbInt l_index);
  t_mx2_AliasType* m_Top();
  bbArray<bbGCVar<t_mx2_AliasType>>* m_ToArray();
  void m_Swap(bbInt l_index1,bbInt l_index2);
  void m_Sort(bbFunction<bbInt(t_mx2_AliasType*,t_mx2_AliasType*)> l_compareFunc,bbInt l_lo,bbInt l_hi);
  void m_Sort(bbFunction<bbInt(t_mx2_AliasType*,t_mx2_AliasType*)> l_compareFunc);
  void m_Sort(bbBool l_ascending);
  t_std_collections_Stack_1Tt_mx2_AliasType_2* m_Slice(bbInt l_index1,bbInt l_index2);
  t_std_collections_Stack_1Tt_mx2_AliasType_2* m_Slice(bbInt l_index);
  void m_Set(bbInt l_index,t_mx2_AliasType* l_value);
  void m_Resize(bbInt l_length);
  void m_Reserve(bbInt l_capacity);
  bbBool m_RemoveLast(t_mx2_AliasType* l_value,bbInt l_start);
  bbInt m_RemoveEach(t_mx2_AliasType* l_value);
  bbBool m_Remove(t_mx2_AliasType* l_value,bbInt l_start);
  void m_Push(t_mx2_AliasType* l_value);
  t_mx2_AliasType* m_Pop();
  bbInt m_Length();
  void m_Insert(bbInt l_index,t_mx2_AliasType* l_value);
  t_mx2_AliasType* m_Get(bbInt l_index);
  bbInt m_FindLastIndex(t_mx2_AliasType* l_value,bbInt l_start);
  bbInt m_FindIndex(t_mx2_AliasType* l_value,bbInt l_start);
  void m_Erase(bbInt l_index1,bbInt l_index2);
  void m_Erase(bbInt l_index);
  bbBool m_Empty();
  bbArray<bbGCVar<t_mx2_AliasType>>* m_Data();
  bbBool m_Contains(t_mx2_AliasType* l_value);
  void m_Clear();
  bbInt m_Capacity();
  t_std_collections_Stack_1Tt_mx2_AliasType_2_BackwardsIterator m_Backwards();
  t_std_collections_Stack_1Tt_mx2_AliasType_2_Iterator m_All();
  void m_AddAll(bbArray<bbGCVar<t_mx2_AliasType>>* l_values);
  void m_Add(t_mx2_AliasType* l_value);
};

struct t_std_collections_Stack_1Tt_mx2_FuncListType_2_Iterator{
  const char *typeName()const{return "t_std_collections_Stack_1Tt_mx2_FuncListType_2_Iterator";}

  bbGCVar<t_std_collections_Stack_1Tt_mx2_FuncListType_2> m__0stack{};
  bbInt m__0index{};
  bbInt m__0seq{};

  t_std_collections_Stack_1Tt_mx2_FuncListType_2_Iterator(t_std_collections_Stack_1Tt_mx2_FuncListType_2* l_stack,bbInt l_index);

  void m_Insert(t_mx2_FuncListType* l_value);
  void m_Erase();
  void m_Current(t_mx2_FuncListType* l_current);
  t_mx2_FuncListType* m_Current();
  void m_Bump();
  bbBool m_AtEnd();
  void m_AssertSeq();
  void m_AssertCurrent();

  t_std_collections_Stack_1Tt_mx2_FuncListType_2_Iterator(){
  }

  t_std_collections_Stack_1Tt_mx2_FuncListType_2_Iterator(bbNullCtor_t){
  }
};

int bbCompare(const t_std_collections_Stack_1Tt_mx2_FuncListType_2_Iterator&x,const t_std_collections_Stack_1Tt_mx2_FuncListType_2_Iterator&y);

void bbGCMark(const t_std_collections_Stack_1Tt_mx2_FuncListType_2_Iterator&);

struct t_std_collections_Stack_1Tt_mx2_FuncListType_2_BackwardsIterator{
  const char *typeName()const{return "t_std_collections_Stack_1Tt_mx2_FuncListType_2_BackwardsIterator";}

  bbGCVar<t_std_collections_Stack_1Tt_mx2_FuncListType_2> m__0stack{};
  bbInt m__0index{};
  bbInt m__0seq{};

  t_std_collections_Stack_1Tt_mx2_FuncListType_2_BackwardsIterator(t_std_collections_Stack_1Tt_mx2_FuncListType_2* l_stack,bbInt l_index);

  void m_Insert(t_mx2_FuncListType* l_value);
  void m_Erase();
  void m_Current(t_mx2_FuncListType* l_current);
  t_mx2_FuncListType* m_Current();
  void m_Bump();
  bbBool m_AtEnd();
  void m_AssertSeq();
  void m_AssertCurrent();

  t_std_collections_Stack_1Tt_mx2_FuncListType_2_BackwardsIterator(){
  }

  t_std_collections_Stack_1Tt_mx2_FuncListType_2_BackwardsIterator(bbNullCtor_t){
  }
};

int bbCompare(const t_std_collections_Stack_1Tt_mx2_FuncListType_2_BackwardsIterator&x,const t_std_collections_Stack_1Tt_mx2_FuncListType_2_BackwardsIterator&y);

void bbGCMark(const t_std_collections_Stack_1Tt_mx2_FuncListType_2_BackwardsIterator&);

struct t_std_collections_Stack_1Tt_mx2_FuncListType_2 : public bbObject,public virtual t_std_collections_IContainer_1Tt_mx2_FuncListType_2{

  const char *typeName()const{return "t_std_collections_Stack_1Tt_mx2_FuncListType_2";}

  bbGCVar<bbArray<bbGCVar<t_mx2_FuncListType>>> m__0data{};
  bbInt m__0length{};
  bbInt m__0seq{};

  void gcMark();

  t_std_collections_Stack_1Tt_mx2_FuncListType_2(t_std_collections_List_1Tt_mx2_FuncListType_2* l_values);
  t_std_collections_Stack_1Tt_mx2_FuncListType_2(t_std_collections_Stack_1Tt_mx2_FuncListType_2* l_values);
  t_std_collections_Stack_1Tt_mx2_FuncListType_2(bbArray<bbGCVar<t_mx2_FuncListType>>* l_values);
  t_std_collections_Stack_1Tt_mx2_FuncListType_2(bbInt l_length);
  t_std_collections_Stack_1Tt_mx2_FuncListType_2();

  void m__idxeq(bbInt l_index,t_mx2_FuncListType* l_value);
  t_mx2_FuncListType* m__idx(bbInt l_index);
  t_mx2_FuncListType* m_Top();
  bbArray<bbGCVar<t_mx2_FuncListType>>* m_ToArray();
  void m_Swap(bbInt l_index1,bbInt l_index2);
  void m_Sort(bbFunction<bbInt(t_mx2_FuncListType*,t_mx2_FuncListType*)> l_compareFunc,bbInt l_lo,bbInt l_hi);
  void m_Sort(bbFunction<bbInt(t_mx2_FuncListType*,t_mx2_FuncListType*)> l_compareFunc);
  void m_Sort(bbBool l_ascending);
  t_std_collections_Stack_1Tt_mx2_FuncListType_2* m_Slice(bbInt l_index1,bbInt l_index2);
  t_std_collections_Stack_1Tt_mx2_FuncListType_2* m_Slice(bbInt l_index);
  void m_Set(bbInt l_index,t_mx2_FuncListType* l_value);
  void m_Resize(bbInt l_length);
  void m_Reserve(bbInt l_capacity);
  bbBool m_RemoveLast(t_mx2_FuncListType* l_value,bbInt l_start);
  bbInt m_RemoveEach(t_mx2_FuncListType* l_value);
  bbBool m_Remove(t_mx2_FuncListType* l_value,bbInt l_start);
  void m_Push(t_mx2_FuncListType* l_value);
  t_mx2_FuncListType* m_Pop();
  bbInt m_Length();
  void m_Insert(bbInt l_index,t_mx2_FuncListType* l_value);
  t_mx2_FuncListType* m_Get(bbInt l_index);
  bbInt m_FindLastIndex(t_mx2_FuncListType* l_value,bbInt l_start);
  bbInt m_FindIndex(t_mx2_FuncListType* l_value,bbInt l_start);
  void m_Erase(bbInt l_index1,bbInt l_index2);
  void m_Erase(bbInt l_index);
  bbBool m_Empty();
  bbArray<bbGCVar<t_mx2_FuncListType>>* m_Data();
  bbBool m_Contains(t_mx2_FuncListType* l_value);
  void m_Clear();
  bbInt m_Capacity();
  t_std_collections_Stack_1Tt_mx2_FuncListType_2_BackwardsIterator m_Backwards();
  t_std_collections_Stack_1Tt_mx2_FuncListType_2_Iterator m_All();
  void m_AddAll(bbArray<bbGCVar<t_mx2_FuncListType>>* l_values);
  void m_Add(t_mx2_FuncListType* l_value);
};

struct t_std_collections_Stack_1Tt_mx2_Decl_2_Iterator{
  const char *typeName()const{return "t_std_collections_Stack_1Tt_mx2_Decl_2_Iterator";}

  bbGCVar<t_std_collections_Stack_1Tt_mx2_Decl_2> m__0stack{};
  bbInt m__0index{};
  bbInt m__0seq{};

  t_std_collections_Stack_1Tt_mx2_Decl_2_Iterator(t_std_collections_Stack_1Tt_mx2_Decl_2* l_stack,bbInt l_index);

  void m_Insert(t_mx2_Decl* l_value);
  void m_Erase();
  void m_Current(t_mx2_Decl* l_current);
  t_mx2_Decl* m_Current();
  void m_Bump();
  bbBool m_AtEnd();
  void m_AssertSeq();
  void m_AssertCurrent();

  t_std_collections_Stack_1Tt_mx2_Decl_2_Iterator(){
  }

  t_std_collections_Stack_1Tt_mx2_Decl_2_Iterator(bbNullCtor_t){
  }
};

int bbCompare(const t_std_collections_Stack_1Tt_mx2_Decl_2_Iterator&x,const t_std_collections_Stack_1Tt_mx2_Decl_2_Iterator&y);

void bbGCMark(const t_std_collections_Stack_1Tt_mx2_Decl_2_Iterator&);

struct t_std_collections_Stack_1Tt_mx2_Decl_2_BackwardsIterator{
  const char *typeName()const{return "t_std_collections_Stack_1Tt_mx2_Decl_2_BackwardsIterator";}

  bbGCVar<t_std_collections_Stack_1Tt_mx2_Decl_2> m__0stack{};
  bbInt m__0index{};
  bbInt m__0seq{};

  t_std_collections_Stack_1Tt_mx2_Decl_2_BackwardsIterator(t_std_collections_Stack_1Tt_mx2_Decl_2* l_stack,bbInt l_index);

  void m_Insert(t_mx2_Decl* l_value);
  void m_Erase();
  void m_Current(t_mx2_Decl* l_current);
  t_mx2_Decl* m_Current();
  void m_Bump();
  bbBool m_AtEnd();
  void m_AssertSeq();
  void m_AssertCurrent();

  t_std_collections_Stack_1Tt_mx2_Decl_2_BackwardsIterator(){
  }

  t_std_collections_Stack_1Tt_mx2_Decl_2_BackwardsIterator(bbNullCtor_t){
  }
};

int bbCompare(const t_std_collections_Stack_1Tt_mx2_Decl_2_BackwardsIterator&x,const t_std_collections_Stack_1Tt_mx2_Decl_2_BackwardsIterator&y);

void bbGCMark(const t_std_collections_Stack_1Tt_mx2_Decl_2_BackwardsIterator&);

struct t_std_collections_Stack_1Tt_mx2_Decl_2 : public bbObject,public virtual t_std_collections_IContainer_1Tt_mx2_Decl_2{

  const char *typeName()const{return "t_std_collections_Stack_1Tt_mx2_Decl_2";}

  bbGCVar<bbArray<bbGCVar<t_mx2_Decl>>> m__0data{};
  bbInt m__0length{};
  bbInt m__0seq{};

  void gcMark();

  t_std_collections_Stack_1Tt_mx2_Decl_2(t_std_collections_List_1Tt_mx2_Decl_2* l_values);
  t_std_collections_Stack_1Tt_mx2_Decl_2(t_std_collections_Stack_1Tt_mx2_Decl_2* l_values);
  t_std_collections_Stack_1Tt_mx2_Decl_2(bbArray<bbGCVar<t_mx2_Decl>>* l_values);
  t_std_collections_Stack_1Tt_mx2_Decl_2(bbInt l_length);
  t_std_collections_Stack_1Tt_mx2_Decl_2();

  void m__idxeq(bbInt l_index,t_mx2_Decl* l_value);
  t_mx2_Decl* m__idx(bbInt l_index);
  t_mx2_Decl* m_Top();
  bbArray<bbGCVar<t_mx2_Decl>>* m_ToArray();
  void m_Swap(bbInt l_index1,bbInt l_index2);
  void m_Sort(bbFunction<bbInt(t_mx2_Decl*,t_mx2_Decl*)> l_compareFunc,bbInt l_lo,bbInt l_hi);
  void m_Sort(bbFunction<bbInt(t_mx2_Decl*,t_mx2_Decl*)> l_compareFunc);
  void m_Sort(bbBool l_ascending);
  t_std_collections_Stack_1Tt_mx2_Decl_2* m_Slice(bbInt l_index1,bbInt l_index2);
  t_std_collections_Stack_1Tt_mx2_Decl_2* m_Slice(bbInt l_index);
  void m_Set(bbInt l_index,t_mx2_Decl* l_value);
  void m_Resize(bbInt l_length);
  void m_Reserve(bbInt l_capacity);
  bbBool m_RemoveLast(t_mx2_Decl* l_value,bbInt l_start);
  bbInt m_RemoveEach(t_mx2_Decl* l_value);
  bbBool m_Remove(t_mx2_Decl* l_value,bbInt l_start);
  void m_Push(t_mx2_Decl* l_value);
  t_mx2_Decl* m_Pop();
  bbInt m_Length();
  void m_Insert(bbInt l_index,t_mx2_Decl* l_value);
  t_mx2_Decl* m_Get(bbInt l_index);
  bbInt m_FindLastIndex(t_mx2_Decl* l_value,bbInt l_start);
  bbInt m_FindIndex(t_mx2_Decl* l_value,bbInt l_start);
  void m_Erase(bbInt l_index1,bbInt l_index2);
  void m_Erase(bbInt l_index);
  bbBool m_Empty();
  bbArray<bbGCVar<t_mx2_Decl>>* m_Data();
  bbBool m_Contains(t_mx2_Decl* l_value);
  void m_Clear();
  bbInt m_Capacity();
  t_std_collections_Stack_1Tt_mx2_Decl_2_BackwardsIterator m_Backwards();
  t_std_collections_Stack_1Tt_mx2_Decl_2_Iterator m_All();
  void m_AddAll(bbArray<bbGCVar<t_mx2_Decl>>* l_values);
  void m_Add(t_mx2_Decl* l_value);
};

struct t_std_collections_Stack_1Tt_mx2_ParseEx_2_Iterator{
  const char *typeName()const{return "t_std_collections_Stack_1Tt_mx2_ParseEx_2_Iterator";}

  bbGCVar<t_std_collections_Stack_1Tt_mx2_ParseEx_2> m__0stack{};
  bbInt m__0index{};
  bbInt m__0seq{};

  t_std_collections_Stack_1Tt_mx2_ParseEx_2_Iterator(t_std_collections_Stack_1Tt_mx2_ParseEx_2* l_stack,bbInt l_index);

  void m_Insert(t_mx2_ParseEx* l_value);
  void m_Erase();
  void m_Current(t_mx2_ParseEx* l_current);
  t_mx2_ParseEx* m_Current();
  void m_Bump();
  bbBool m_AtEnd();
  void m_AssertSeq();
  void m_AssertCurrent();

  t_std_collections_Stack_1Tt_mx2_ParseEx_2_Iterator(){
  }

  t_std_collections_Stack_1Tt_mx2_ParseEx_2_Iterator(bbNullCtor_t){
  }
};

int bbCompare(const t_std_collections_Stack_1Tt_mx2_ParseEx_2_Iterator&x,const t_std_collections_Stack_1Tt_mx2_ParseEx_2_Iterator&y);

void bbGCMark(const t_std_collections_Stack_1Tt_mx2_ParseEx_2_Iterator&);

struct t_std_collections_Stack_1Tt_mx2_ParseEx_2_BackwardsIterator{
  const char *typeName()const{return "t_std_collections_Stack_1Tt_mx2_ParseEx_2_BackwardsIterator";}

  bbGCVar<t_std_collections_Stack_1Tt_mx2_ParseEx_2> m__0stack{};
  bbInt m__0index{};
  bbInt m__0seq{};

  t_std_collections_Stack_1Tt_mx2_ParseEx_2_BackwardsIterator(t_std_collections_Stack_1Tt_mx2_ParseEx_2* l_stack,bbInt l_index);

  void m_Insert(t_mx2_ParseEx* l_value);
  void m_Erase();
  void m_Current(t_mx2_ParseEx* l_current);
  t_mx2_ParseEx* m_Current();
  void m_Bump();
  bbBool m_AtEnd();
  void m_AssertSeq();
  void m_AssertCurrent();

  t_std_collections_Stack_1Tt_mx2_ParseEx_2_BackwardsIterator(){
  }

  t_std_collections_Stack_1Tt_mx2_ParseEx_2_BackwardsIterator(bbNullCtor_t){
  }
};

int bbCompare(const t_std_collections_Stack_1Tt_mx2_ParseEx_2_BackwardsIterator&x,const t_std_collections_Stack_1Tt_mx2_ParseEx_2_BackwardsIterator&y);

void bbGCMark(const t_std_collections_Stack_1Tt_mx2_ParseEx_2_BackwardsIterator&);

struct t_std_collections_Stack_1Tt_mx2_ParseEx_2 : public bbObject,public virtual t_std_collections_IContainer_1Tt_mx2_ParseEx_2{

  const char *typeName()const{return "t_std_collections_Stack_1Tt_mx2_ParseEx_2";}

  bbGCVar<bbArray<bbGCVar<t_mx2_ParseEx>>> m__0data{};
  bbInt m__0length{};
  bbInt m__0seq{};

  void gcMark();

  t_std_collections_Stack_1Tt_mx2_ParseEx_2(t_std_collections_List_1Tt_mx2_ParseEx_2* l_values);
  t_std_collections_Stack_1Tt_mx2_ParseEx_2(t_std_collections_Stack_1Tt_mx2_ParseEx_2* l_values);
  t_std_collections_Stack_1Tt_mx2_ParseEx_2(bbArray<bbGCVar<t_mx2_ParseEx>>* l_values);
  t_std_collections_Stack_1Tt_mx2_ParseEx_2(bbInt l_length);
  t_std_collections_Stack_1Tt_mx2_ParseEx_2();

  void m__idxeq(bbInt l_index,t_mx2_ParseEx* l_value);
  t_mx2_ParseEx* m__idx(bbInt l_index);
  t_mx2_ParseEx* m_Top();
  bbArray<bbGCVar<t_mx2_ParseEx>>* m_ToArray();
  void m_Swap(bbInt l_index1,bbInt l_index2);
  void m_Sort(bbFunction<bbInt(t_mx2_ParseEx*,t_mx2_ParseEx*)> l_compareFunc,bbInt l_lo,bbInt l_hi);
  void m_Sort(bbFunction<bbInt(t_mx2_ParseEx*,t_mx2_ParseEx*)> l_compareFunc);
  void m_Sort(bbBool l_ascending);
  t_std_collections_Stack_1Tt_mx2_ParseEx_2* m_Slice(bbInt l_index1,bbInt l_index2);
  t_std_collections_Stack_1Tt_mx2_ParseEx_2* m_Slice(bbInt l_index);
  void m_Set(bbInt l_index,t_mx2_ParseEx* l_value);
  void m_Resize(bbInt l_length);
  void m_Reserve(bbInt l_capacity);
  bbBool m_RemoveLast(t_mx2_ParseEx* l_value,bbInt l_start);
  bbInt m_RemoveEach(t_mx2_ParseEx* l_value);
  bbBool m_Remove(t_mx2_ParseEx* l_value,bbInt l_start);
  void m_Push(t_mx2_ParseEx* l_value);
  t_mx2_ParseEx* m_Pop();
  bbInt m_Length();
  void m_Insert(bbInt l_index,t_mx2_ParseEx* l_value);
  t_mx2_ParseEx* m_Get(bbInt l_index);
  bbInt m_FindLastIndex(t_mx2_ParseEx* l_value,bbInt l_start);
  bbInt m_FindIndex(t_mx2_ParseEx* l_value,bbInt l_start);
  void m_Erase(bbInt l_index1,bbInt l_index2);
  void m_Erase(bbInt l_index);
  bbBool m_Empty();
  bbArray<bbGCVar<t_mx2_ParseEx>>* m_Data();
  bbBool m_Contains(t_mx2_ParseEx* l_value);
  void m_Clear();
  bbInt m_Capacity();
  t_std_collections_Stack_1Tt_mx2_ParseEx_2_BackwardsIterator m_Backwards();
  t_std_collections_Stack_1Tt_mx2_ParseEx_2_Iterator m_All();
  void m_AddAll(bbArray<bbGCVar<t_mx2_ParseEx>>* l_values);
  void m_Add(t_mx2_ParseEx* l_value);
};

struct t_std_collections_Stack_1Tt_mx2_Toker_2_Iterator{
  const char *typeName()const{return "t_std_collections_Stack_1Tt_mx2_Toker_2_Iterator";}

  bbGCVar<t_std_collections_Stack_1Tt_mx2_Toker_2> m__0stack{};
  bbInt m__0index{};
  bbInt m__0seq{};

  t_std_collections_Stack_1Tt_mx2_Toker_2_Iterator(t_std_collections_Stack_1Tt_mx2_Toker_2* l_stack,bbInt l_index);

  void m_Insert(t_mx2_Toker* l_value);
  void m_Erase();
  void m_Current(t_mx2_Toker* l_current);
  t_mx2_Toker* m_Current();
  void m_Bump();
  bbBool m_AtEnd();
  void m_AssertSeq();
  void m_AssertCurrent();

  t_std_collections_Stack_1Tt_mx2_Toker_2_Iterator(){
  }

  t_std_collections_Stack_1Tt_mx2_Toker_2_Iterator(bbNullCtor_t){
  }
};

int bbCompare(const t_std_collections_Stack_1Tt_mx2_Toker_2_Iterator&x,const t_std_collections_Stack_1Tt_mx2_Toker_2_Iterator&y);

void bbGCMark(const t_std_collections_Stack_1Tt_mx2_Toker_2_Iterator&);

struct t_std_collections_Stack_1Tt_mx2_Toker_2_BackwardsIterator{
  const char *typeName()const{return "t_std_collections_Stack_1Tt_mx2_Toker_2_BackwardsIterator";}

  bbGCVar<t_std_collections_Stack_1Tt_mx2_Toker_2> m__0stack{};
  bbInt m__0index{};
  bbInt m__0seq{};

  t_std_collections_Stack_1Tt_mx2_Toker_2_BackwardsIterator(t_std_collections_Stack_1Tt_mx2_Toker_2* l_stack,bbInt l_index);

  void m_Insert(t_mx2_Toker* l_value);
  void m_Erase();
  void m_Current(t_mx2_Toker* l_current);
  t_mx2_Toker* m_Current();
  void m_Bump();
  bbBool m_AtEnd();
  void m_AssertSeq();
  void m_AssertCurrent();

  t_std_collections_Stack_1Tt_mx2_Toker_2_BackwardsIterator(){
  }

  t_std_collections_Stack_1Tt_mx2_Toker_2_BackwardsIterator(bbNullCtor_t){
  }
};

int bbCompare(const t_std_collections_Stack_1Tt_mx2_Toker_2_BackwardsIterator&x,const t_std_collections_Stack_1Tt_mx2_Toker_2_BackwardsIterator&y);

void bbGCMark(const t_std_collections_Stack_1Tt_mx2_Toker_2_BackwardsIterator&);

struct t_std_collections_Stack_1Tt_mx2_Toker_2 : public bbObject,public virtual t_std_collections_IContainer_1Tt_mx2_Toker_2{

  const char *typeName()const{return "t_std_collections_Stack_1Tt_mx2_Toker_2";}

  bbGCVar<bbArray<bbGCVar<t_mx2_Toker>>> m__0data{};
  bbInt m__0length{};
  bbInt m__0seq{};

  void gcMark();

  t_std_collections_Stack_1Tt_mx2_Toker_2(t_std_collections_List_1Tt_mx2_Toker_2* l_values);
  t_std_collections_Stack_1Tt_mx2_Toker_2(t_std_collections_Stack_1Tt_mx2_Toker_2* l_values);
  t_std_collections_Stack_1Tt_mx2_Toker_2(bbArray<bbGCVar<t_mx2_Toker>>* l_values);
  t_std_collections_Stack_1Tt_mx2_Toker_2(bbInt l_length);
  t_std_collections_Stack_1Tt_mx2_Toker_2();

  void m__idxeq(bbInt l_index,t_mx2_Toker* l_value);
  t_mx2_Toker* m__idx(bbInt l_index);
  t_mx2_Toker* m_Top();
  bbArray<bbGCVar<t_mx2_Toker>>* m_ToArray();
  void m_Swap(bbInt l_index1,bbInt l_index2);
  void m_Sort(bbFunction<bbInt(t_mx2_Toker*,t_mx2_Toker*)> l_compareFunc,bbInt l_lo,bbInt l_hi);
  void m_Sort(bbFunction<bbInt(t_mx2_Toker*,t_mx2_Toker*)> l_compareFunc);
  void m_Sort(bbBool l_ascending);
  t_std_collections_Stack_1Tt_mx2_Toker_2* m_Slice(bbInt l_index1,bbInt l_index2);
  t_std_collections_Stack_1Tt_mx2_Toker_2* m_Slice(bbInt l_index);
  void m_Set(bbInt l_index,t_mx2_Toker* l_value);
  void m_Resize(bbInt l_length);
  void m_Reserve(bbInt l_capacity);
  bbBool m_RemoveLast(t_mx2_Toker* l_value,bbInt l_start);
  bbInt m_RemoveEach(t_mx2_Toker* l_value);
  bbBool m_Remove(t_mx2_Toker* l_value,bbInt l_start);
  void m_Push(t_mx2_Toker* l_value);
  t_mx2_Toker* m_Pop();
  bbInt m_Length();
  void m_Insert(bbInt l_index,t_mx2_Toker* l_value);
  t_mx2_Toker* m_Get(bbInt l_index);
  bbInt m_FindLastIndex(t_mx2_Toker* l_value,bbInt l_start);
  bbInt m_FindIndex(t_mx2_Toker* l_value,bbInt l_start);
  void m_Erase(bbInt l_index1,bbInt l_index2);
  void m_Erase(bbInt l_index);
  bbBool m_Empty();
  bbArray<bbGCVar<t_mx2_Toker>>* m_Data();
  bbBool m_Contains(t_mx2_Toker* l_value);
  void m_Clear();
  bbInt m_Capacity();
  t_std_collections_Stack_1Tt_mx2_Toker_2_BackwardsIterator m_Backwards();
  t_std_collections_Stack_1Tt_mx2_Toker_2_Iterator m_All();
  void m_AddAll(bbArray<bbGCVar<t_mx2_Toker>>* l_values);
  void m_Add(t_mx2_Toker* l_value);
};

struct t_std_collections_Stack_1Tt_mx2_Stmt_2_Iterator{
  const char *typeName()const{return "t_std_collections_Stack_1Tt_mx2_Stmt_2_Iterator";}

  bbGCVar<t_std_collections_Stack_1Tt_mx2_Stmt_2> m__0stack{};
  bbInt m__0index{};
  bbInt m__0seq{};

  t_std_collections_Stack_1Tt_mx2_Stmt_2_Iterator(t_std_collections_Stack_1Tt_mx2_Stmt_2* l_stack,bbInt l_index);

  void m_Insert(t_mx2_Stmt* l_value);
  void m_Erase();
  void m_Current(t_mx2_Stmt* l_current);
  t_mx2_Stmt* m_Current();
  void m_Bump();
  bbBool m_AtEnd();
  void m_AssertSeq();
  void m_AssertCurrent();

  t_std_collections_Stack_1Tt_mx2_Stmt_2_Iterator(){
  }

  t_std_collections_Stack_1Tt_mx2_Stmt_2_Iterator(bbNullCtor_t){
  }
};

int bbCompare(const t_std_collections_Stack_1Tt_mx2_Stmt_2_Iterator&x,const t_std_collections_Stack_1Tt_mx2_Stmt_2_Iterator&y);

void bbGCMark(const t_std_collections_Stack_1Tt_mx2_Stmt_2_Iterator&);

struct t_std_collections_Stack_1Tt_mx2_Stmt_2_BackwardsIterator{
  const char *typeName()const{return "t_std_collections_Stack_1Tt_mx2_Stmt_2_BackwardsIterator";}

  bbGCVar<t_std_collections_Stack_1Tt_mx2_Stmt_2> m__0stack{};
  bbInt m__0index{};
  bbInt m__0seq{};

  t_std_collections_Stack_1Tt_mx2_Stmt_2_BackwardsIterator(t_std_collections_Stack_1Tt_mx2_Stmt_2* l_stack,bbInt l_index);

  void m_Insert(t_mx2_Stmt* l_value);
  void m_Erase();
  void m_Current(t_mx2_Stmt* l_current);
  t_mx2_Stmt* m_Current();
  void m_Bump();
  bbBool m_AtEnd();
  void m_AssertSeq();
  void m_AssertCurrent();

  t_std_collections_Stack_1Tt_mx2_Stmt_2_BackwardsIterator(){
  }

  t_std_collections_Stack_1Tt_mx2_Stmt_2_BackwardsIterator(bbNullCtor_t){
  }
};

int bbCompare(const t_std_collections_Stack_1Tt_mx2_Stmt_2_BackwardsIterator&x,const t_std_collections_Stack_1Tt_mx2_Stmt_2_BackwardsIterator&y);

void bbGCMark(const t_std_collections_Stack_1Tt_mx2_Stmt_2_BackwardsIterator&);

struct t_std_collections_Stack_1Tt_mx2_Stmt_2 : public bbObject,public virtual t_std_collections_IContainer_1Tt_mx2_Stmt_2{

  const char *typeName()const{return "t_std_collections_Stack_1Tt_mx2_Stmt_2";}

  bbGCVar<bbArray<bbGCVar<t_mx2_Stmt>>> m__0data{};
  bbInt m__0length{};
  bbInt m__0seq{};

  void gcMark();

  t_std_collections_Stack_1Tt_mx2_Stmt_2(t_std_collections_List_1Tt_mx2_Stmt_2* l_values);
  t_std_collections_Stack_1Tt_mx2_Stmt_2(t_std_collections_Stack_1Tt_mx2_Stmt_2* l_values);
  t_std_collections_Stack_1Tt_mx2_Stmt_2(bbArray<bbGCVar<t_mx2_Stmt>>* l_values);
  t_std_collections_Stack_1Tt_mx2_Stmt_2(bbInt l_length);
  t_std_collections_Stack_1Tt_mx2_Stmt_2();

  void m__idxeq(bbInt l_index,t_mx2_Stmt* l_value);
  t_mx2_Stmt* m__idx(bbInt l_index);
  t_mx2_Stmt* m_Top();
  bbArray<bbGCVar<t_mx2_Stmt>>* m_ToArray();
  void m_Swap(bbInt l_index1,bbInt l_index2);
  void m_Sort(bbFunction<bbInt(t_mx2_Stmt*,t_mx2_Stmt*)> l_compareFunc,bbInt l_lo,bbInt l_hi);
  void m_Sort(bbFunction<bbInt(t_mx2_Stmt*,t_mx2_Stmt*)> l_compareFunc);
  void m_Sort(bbBool l_ascending);
  t_std_collections_Stack_1Tt_mx2_Stmt_2* m_Slice(bbInt l_index1,bbInt l_index2);
  t_std_collections_Stack_1Tt_mx2_Stmt_2* m_Slice(bbInt l_index);
  void m_Set(bbInt l_index,t_mx2_Stmt* l_value);
  void m_Resize(bbInt l_length);
  void m_Reserve(bbInt l_capacity);
  bbBool m_RemoveLast(t_mx2_Stmt* l_value,bbInt l_start);
  bbInt m_RemoveEach(t_mx2_Stmt* l_value);
  bbBool m_Remove(t_mx2_Stmt* l_value,bbInt l_start);
  void m_Push(t_mx2_Stmt* l_value);
  t_mx2_Stmt* m_Pop();
  bbInt m_Length();
  void m_Insert(bbInt l_index,t_mx2_Stmt* l_value);
  t_mx2_Stmt* m_Get(bbInt l_index);
  bbInt m_FindLastIndex(t_mx2_Stmt* l_value,bbInt l_start);
  bbInt m_FindIndex(t_mx2_Stmt* l_value,bbInt l_start);
  void m_Erase(bbInt l_index1,bbInt l_index2);
  void m_Erase(bbInt l_index);
  bbBool m_Empty();
  bbArray<bbGCVar<t_mx2_Stmt>>* m_Data();
  bbBool m_Contains(t_mx2_Stmt* l_value);
  void m_Clear();
  bbInt m_Capacity();
  t_std_collections_Stack_1Tt_mx2_Stmt_2_BackwardsIterator m_Backwards();
  t_std_collections_Stack_1Tt_mx2_Stmt_2_Iterator m_All();
  void m_AddAll(bbArray<bbGCVar<t_mx2_Stmt>>* l_values);
  void m_Add(t_mx2_Stmt* l_value);
};

struct t_std_collections_Stack_1Tt_mx2_Translator_GCTmp_2_Iterator{
  const char *typeName()const{return "t_std_collections_Stack_1Tt_mx2_Translator_GCTmp_2_Iterator";}

  bbGCVar<t_std_collections_Stack_1Tt_mx2_Translator_GCTmp_2> m__0stack{};
  bbInt m__0index{};
  bbInt m__0seq{};

  t_std_collections_Stack_1Tt_mx2_Translator_GCTmp_2_Iterator(t_std_collections_Stack_1Tt_mx2_Translator_GCTmp_2* l_stack,bbInt l_index);

  void m_Insert(t_mx2_Translator_GCTmp* l_value);
  void m_Erase();
  void m_Current(t_mx2_Translator_GCTmp* l_current);
  t_mx2_Translator_GCTmp* m_Current();
  void m_Bump();
  bbBool m_AtEnd();
  void m_AssertSeq();
  void m_AssertCurrent();

  t_std_collections_Stack_1Tt_mx2_Translator_GCTmp_2_Iterator(){
  }

  t_std_collections_Stack_1Tt_mx2_Translator_GCTmp_2_Iterator(bbNullCtor_t){
  }
};

int bbCompare(const t_std_collections_Stack_1Tt_mx2_Translator_GCTmp_2_Iterator&x,const t_std_collections_Stack_1Tt_mx2_Translator_GCTmp_2_Iterator&y);

void bbGCMark(const t_std_collections_Stack_1Tt_mx2_Translator_GCTmp_2_Iterator&);

struct t_std_collections_Stack_1Tt_mx2_Translator_GCTmp_2_BackwardsIterator{
  const char *typeName()const{return "t_std_collections_Stack_1Tt_mx2_Translator_GCTmp_2_BackwardsIterator";}

  bbGCVar<t_std_collections_Stack_1Tt_mx2_Translator_GCTmp_2> m__0stack{};
  bbInt m__0index{};
  bbInt m__0seq{};

  t_std_collections_Stack_1Tt_mx2_Translator_GCTmp_2_BackwardsIterator(t_std_collections_Stack_1Tt_mx2_Translator_GCTmp_2* l_stack,bbInt l_index);

  void m_Insert(t_mx2_Translator_GCTmp* l_value);
  void m_Erase();
  void m_Current(t_mx2_Translator_GCTmp* l_current);
  t_mx2_Translator_GCTmp* m_Current();
  void m_Bump();
  bbBool m_AtEnd();
  void m_AssertSeq();
  void m_AssertCurrent();

  t_std_collections_Stack_1Tt_mx2_Translator_GCTmp_2_BackwardsIterator(){
  }

  t_std_collections_Stack_1Tt_mx2_Translator_GCTmp_2_BackwardsIterator(bbNullCtor_t){
  }
};

int bbCompare(const t_std_collections_Stack_1Tt_mx2_Translator_GCTmp_2_BackwardsIterator&x,const t_std_collections_Stack_1Tt_mx2_Translator_GCTmp_2_BackwardsIterator&y);

void bbGCMark(const t_std_collections_Stack_1Tt_mx2_Translator_GCTmp_2_BackwardsIterator&);

struct t_std_collections_Stack_1Tt_mx2_Translator_GCTmp_2 : public bbObject,public virtual t_std_collections_IContainer_1Tt_mx2_Translator_GCTmp_2{

  const char *typeName()const{return "t_std_collections_Stack_1Tt_mx2_Translator_GCTmp_2";}

  bbGCVar<bbArray<bbGCVar<t_mx2_Translator_GCTmp>>> m__0data{};
  bbInt m__0length{};
  bbInt m__0seq{};

  void gcMark();

  t_std_collections_Stack_1Tt_mx2_Translator_GCTmp_2(t_std_collections_List_1Tt_mx2_Translator_GCTmp_2* l_values);
  t_std_collections_Stack_1Tt_mx2_Translator_GCTmp_2(t_std_collections_Stack_1Tt_mx2_Translator_GCTmp_2* l_values);
  t_std_collections_Stack_1Tt_mx2_Translator_GCTmp_2(bbArray<bbGCVar<t_mx2_Translator_GCTmp>>* l_values);
  t_std_collections_Stack_1Tt_mx2_Translator_GCTmp_2(bbInt l_length);
  t_std_collections_Stack_1Tt_mx2_Translator_GCTmp_2();

  void m__idxeq(bbInt l_index,t_mx2_Translator_GCTmp* l_value);
  t_mx2_Translator_GCTmp* m__idx(bbInt l_index);
  t_mx2_Translator_GCTmp* m_Top();
  bbArray<bbGCVar<t_mx2_Translator_GCTmp>>* m_ToArray();
  void m_Swap(bbInt l_index1,bbInt l_index2);
  void m_Sort(bbFunction<bbInt(t_mx2_Translator_GCTmp*,t_mx2_Translator_GCTmp*)> l_compareFunc,bbInt l_lo,bbInt l_hi);
  void m_Sort(bbFunction<bbInt(t_mx2_Translator_GCTmp*,t_mx2_Translator_GCTmp*)> l_compareFunc);
  void m_Sort(bbBool l_ascending);
  t_std_collections_Stack_1Tt_mx2_Translator_GCTmp_2* m_Slice(bbInt l_index1,bbInt l_index2);
  t_std_collections_Stack_1Tt_mx2_Translator_GCTmp_2* m_Slice(bbInt l_index);
  void m_Set(bbInt l_index,t_mx2_Translator_GCTmp* l_value);
  void m_Resize(bbInt l_length);
  void m_Reserve(bbInt l_capacity);
  bbBool m_RemoveLast(t_mx2_Translator_GCTmp* l_value,bbInt l_start);
  bbInt m_RemoveEach(t_mx2_Translator_GCTmp* l_value);
  bbBool m_Remove(t_mx2_Translator_GCTmp* l_value,bbInt l_start);
  void m_Push(t_mx2_Translator_GCTmp* l_value);
  t_mx2_Translator_GCTmp* m_Pop();
  bbInt m_Length();
  void m_Insert(bbInt l_index,t_mx2_Translator_GCTmp* l_value);
  t_mx2_Translator_GCTmp* m_Get(bbInt l_index);
  bbInt m_FindLastIndex(t_mx2_Translator_GCTmp* l_value,bbInt l_start);
  bbInt m_FindIndex(t_mx2_Translator_GCTmp* l_value,bbInt l_start);
  void m_Erase(bbInt l_index1,bbInt l_index2);
  void m_Erase(bbInt l_index);
  bbBool m_Empty();
  bbArray<bbGCVar<t_mx2_Translator_GCTmp>>* m_Data();
  bbBool m_Contains(t_mx2_Translator_GCTmp* l_value);
  void m_Clear();
  bbInt m_Capacity();
  t_std_collections_Stack_1Tt_mx2_Translator_GCTmp_2_BackwardsIterator m_Backwards();
  t_std_collections_Stack_1Tt_mx2_Translator_GCTmp_2_Iterator m_All();
  void m_AddAll(bbArray<bbGCVar<t_mx2_Translator_GCTmp>>* l_values);
  void m_Add(t_mx2_Translator_GCTmp* l_value);
};

struct t_std_collections_Stack_1Tt_mx2_TypeExpr_2_Iterator{
  const char *typeName()const{return "t_std_collections_Stack_1Tt_mx2_TypeExpr_2_Iterator";}

  bbGCVar<t_std_collections_Stack_1Tt_mx2_TypeExpr_2> m__0stack{};
  bbInt m__0index{};
  bbInt m__0seq{};

  t_std_collections_Stack_1Tt_mx2_TypeExpr_2_Iterator(t_std_collections_Stack_1Tt_mx2_TypeExpr_2* l_stack,bbInt l_index);

  void m_Insert(t_mx2_TypeExpr* l_value);
  void m_Erase();
  void m_Current(t_mx2_TypeExpr* l_current);
  t_mx2_TypeExpr* m_Current();
  void m_Bump();
  bbBool m_AtEnd();
  void m_AssertSeq();
  void m_AssertCurrent();

  t_std_collections_Stack_1Tt_mx2_TypeExpr_2_Iterator(){
  }

  t_std_collections_Stack_1Tt_mx2_TypeExpr_2_Iterator(bbNullCtor_t){
  }
};

int bbCompare(const t_std_collections_Stack_1Tt_mx2_TypeExpr_2_Iterator&x,const t_std_collections_Stack_1Tt_mx2_TypeExpr_2_Iterator&y);

void bbGCMark(const t_std_collections_Stack_1Tt_mx2_TypeExpr_2_Iterator&);

struct t_std_collections_Stack_1Tt_mx2_TypeExpr_2_BackwardsIterator{
  const char *typeName()const{return "t_std_collections_Stack_1Tt_mx2_TypeExpr_2_BackwardsIterator";}

  bbGCVar<t_std_collections_Stack_1Tt_mx2_TypeExpr_2> m__0stack{};
  bbInt m__0index{};
  bbInt m__0seq{};

  t_std_collections_Stack_1Tt_mx2_TypeExpr_2_BackwardsIterator(t_std_collections_Stack_1Tt_mx2_TypeExpr_2* l_stack,bbInt l_index);

  void m_Insert(t_mx2_TypeExpr* l_value);
  void m_Erase();
  void m_Current(t_mx2_TypeExpr* l_current);
  t_mx2_TypeExpr* m_Current();
  void m_Bump();
  bbBool m_AtEnd();
  void m_AssertSeq();
  void m_AssertCurrent();

  t_std_collections_Stack_1Tt_mx2_TypeExpr_2_BackwardsIterator(){
  }

  t_std_collections_Stack_1Tt_mx2_TypeExpr_2_BackwardsIterator(bbNullCtor_t){
  }
};

int bbCompare(const t_std_collections_Stack_1Tt_mx2_TypeExpr_2_BackwardsIterator&x,const t_std_collections_Stack_1Tt_mx2_TypeExpr_2_BackwardsIterator&y);

void bbGCMark(const t_std_collections_Stack_1Tt_mx2_TypeExpr_2_BackwardsIterator&);

struct t_std_collections_Stack_1Tt_mx2_TypeExpr_2 : public bbObject,public virtual t_std_collections_IContainer_1Tt_mx2_TypeExpr_2{

  const char *typeName()const{return "t_std_collections_Stack_1Tt_mx2_TypeExpr_2";}

  bbGCVar<bbArray<bbGCVar<t_mx2_TypeExpr>>> m__0data{};
  bbInt m__0length{};
  bbInt m__0seq{};

  void gcMark();

  t_std_collections_Stack_1Tt_mx2_TypeExpr_2(t_std_collections_List_1Tt_mx2_TypeExpr_2* l_values);
  t_std_collections_Stack_1Tt_mx2_TypeExpr_2(t_std_collections_Stack_1Tt_mx2_TypeExpr_2* l_values);
  t_std_collections_Stack_1Tt_mx2_TypeExpr_2(bbArray<bbGCVar<t_mx2_TypeExpr>>* l_values);
  t_std_collections_Stack_1Tt_mx2_TypeExpr_2(bbInt l_length);
  t_std_collections_Stack_1Tt_mx2_TypeExpr_2();

  void m__idxeq(bbInt l_index,t_mx2_TypeExpr* l_value);
  t_mx2_TypeExpr* m__idx(bbInt l_index);
  t_mx2_TypeExpr* m_Top();
  bbArray<bbGCVar<t_mx2_TypeExpr>>* m_ToArray();
  void m_Swap(bbInt l_index1,bbInt l_index2);
  void m_Sort(bbFunction<bbInt(t_mx2_TypeExpr*,t_mx2_TypeExpr*)> l_compareFunc,bbInt l_lo,bbInt l_hi);
  void m_Sort(bbFunction<bbInt(t_mx2_TypeExpr*,t_mx2_TypeExpr*)> l_compareFunc);
  void m_Sort(bbBool l_ascending);
  t_std_collections_Stack_1Tt_mx2_TypeExpr_2* m_Slice(bbInt l_index1,bbInt l_index2);
  t_std_collections_Stack_1Tt_mx2_TypeExpr_2* m_Slice(bbInt l_index);
  void m_Set(bbInt l_index,t_mx2_TypeExpr* l_value);
  void m_Resize(bbInt l_length);
  void m_Reserve(bbInt l_capacity);
  bbBool m_RemoveLast(t_mx2_TypeExpr* l_value,bbInt l_start);
  bbInt m_RemoveEach(t_mx2_TypeExpr* l_value);
  bbBool m_Remove(t_mx2_TypeExpr* l_value,bbInt l_start);
  void m_Push(t_mx2_TypeExpr* l_value);
  t_mx2_TypeExpr* m_Pop();
  bbInt m_Length();
  void m_Insert(bbInt l_index,t_mx2_TypeExpr* l_value);
  t_mx2_TypeExpr* m_Get(bbInt l_index);
  bbInt m_FindLastIndex(t_mx2_TypeExpr* l_value,bbInt l_start);
  bbInt m_FindIndex(t_mx2_TypeExpr* l_value,bbInt l_start);
  void m_Erase(bbInt l_index1,bbInt l_index2);
  void m_Erase(bbInt l_index);
  bbBool m_Empty();
  bbArray<bbGCVar<t_mx2_TypeExpr>>* m_Data();
  bbBool m_Contains(t_mx2_TypeExpr* l_value);
  void m_Clear();
  bbInt m_Capacity();
  t_std_collections_Stack_1Tt_mx2_TypeExpr_2_BackwardsIterator m_Backwards();
  t_std_collections_Stack_1Tt_mx2_TypeExpr_2_Iterator m_All();
  void m_AddAll(bbArray<bbGCVar<t_mx2_TypeExpr>>* l_values);
  void m_Add(t_mx2_TypeExpr* l_value);
};

struct t_std_collections_Stack_1Tt_mx2_CatchExpr_2_Iterator{
  const char *typeName()const{return "t_std_collections_Stack_1Tt_mx2_CatchExpr_2_Iterator";}

  bbGCVar<t_std_collections_Stack_1Tt_mx2_CatchExpr_2> m__0stack{};
  bbInt m__0index{};
  bbInt m__0seq{};

  t_std_collections_Stack_1Tt_mx2_CatchExpr_2_Iterator(t_std_collections_Stack_1Tt_mx2_CatchExpr_2* l_stack,bbInt l_index);

  void m_Insert(t_mx2_CatchExpr* l_value);
  void m_Erase();
  void m_Current(t_mx2_CatchExpr* l_current);
  t_mx2_CatchExpr* m_Current();
  void m_Bump();
  bbBool m_AtEnd();
  void m_AssertSeq();
  void m_AssertCurrent();

  t_std_collections_Stack_1Tt_mx2_CatchExpr_2_Iterator(){
  }

  t_std_collections_Stack_1Tt_mx2_CatchExpr_2_Iterator(bbNullCtor_t){
  }
};

int bbCompare(const t_std_collections_Stack_1Tt_mx2_CatchExpr_2_Iterator&x,const t_std_collections_Stack_1Tt_mx2_CatchExpr_2_Iterator&y);

void bbGCMark(const t_std_collections_Stack_1Tt_mx2_CatchExpr_2_Iterator&);

struct t_std_collections_Stack_1Tt_mx2_CatchExpr_2_BackwardsIterator{
  const char *typeName()const{return "t_std_collections_Stack_1Tt_mx2_CatchExpr_2_BackwardsIterator";}

  bbGCVar<t_std_collections_Stack_1Tt_mx2_CatchExpr_2> m__0stack{};
  bbInt m__0index{};
  bbInt m__0seq{};

  t_std_collections_Stack_1Tt_mx2_CatchExpr_2_BackwardsIterator(t_std_collections_Stack_1Tt_mx2_CatchExpr_2* l_stack,bbInt l_index);

  void m_Insert(t_mx2_CatchExpr* l_value);
  void m_Erase();
  void m_Current(t_mx2_CatchExpr* l_current);
  t_mx2_CatchExpr* m_Current();
  void m_Bump();
  bbBool m_AtEnd();
  void m_AssertSeq();
  void m_AssertCurrent();

  t_std_collections_Stack_1Tt_mx2_CatchExpr_2_BackwardsIterator(){
  }

  t_std_collections_Stack_1Tt_mx2_CatchExpr_2_BackwardsIterator(bbNullCtor_t){
  }
};

int bbCompare(const t_std_collections_Stack_1Tt_mx2_CatchExpr_2_BackwardsIterator&x,const t_std_collections_Stack_1Tt_mx2_CatchExpr_2_BackwardsIterator&y);

void bbGCMark(const t_std_collections_Stack_1Tt_mx2_CatchExpr_2_BackwardsIterator&);

struct t_std_collections_Stack_1Tt_mx2_CatchExpr_2 : public bbObject,public virtual t_std_collections_IContainer_1Tt_mx2_CatchExpr_2{

  const char *typeName()const{return "t_std_collections_Stack_1Tt_mx2_CatchExpr_2";}

  bbGCVar<bbArray<bbGCVar<t_mx2_CatchExpr>>> m__0data{};
  bbInt m__0length{};
  bbInt m__0seq{};

  void gcMark();

  t_std_collections_Stack_1Tt_mx2_CatchExpr_2(t_std_collections_List_1Tt_mx2_CatchExpr_2* l_values);
  t_std_collections_Stack_1Tt_mx2_CatchExpr_2(t_std_collections_Stack_1Tt_mx2_CatchExpr_2* l_values);
  t_std_collections_Stack_1Tt_mx2_CatchExpr_2(bbArray<bbGCVar<t_mx2_CatchExpr>>* l_values);
  t_std_collections_Stack_1Tt_mx2_CatchExpr_2(bbInt l_length);
  t_std_collections_Stack_1Tt_mx2_CatchExpr_2();

  void m__idxeq(bbInt l_index,t_mx2_CatchExpr* l_value);
  t_mx2_CatchExpr* m__idx(bbInt l_index);
  t_mx2_CatchExpr* m_Top();
  bbArray<bbGCVar<t_mx2_CatchExpr>>* m_ToArray();
  void m_Swap(bbInt l_index1,bbInt l_index2);
  void m_Sort(bbFunction<bbInt(t_mx2_CatchExpr*,t_mx2_CatchExpr*)> l_compareFunc,bbInt l_lo,bbInt l_hi);
  void m_Sort(bbFunction<bbInt(t_mx2_CatchExpr*,t_mx2_CatchExpr*)> l_compareFunc);
  void m_Sort(bbBool l_ascending);
  t_std_collections_Stack_1Tt_mx2_CatchExpr_2* m_Slice(bbInt l_index1,bbInt l_index2);
  t_std_collections_Stack_1Tt_mx2_CatchExpr_2* m_Slice(bbInt l_index);
  void m_Set(bbInt l_index,t_mx2_CatchExpr* l_value);
  void m_Resize(bbInt l_length);
  void m_Reserve(bbInt l_capacity);
  bbBool m_RemoveLast(t_mx2_CatchExpr* l_value,bbInt l_start);
  bbInt m_RemoveEach(t_mx2_CatchExpr* l_value);
  bbBool m_Remove(t_mx2_CatchExpr* l_value,bbInt l_start);
  void m_Push(t_mx2_CatchExpr* l_value);
  t_mx2_CatchExpr* m_Pop();
  bbInt m_Length();
  void m_Insert(bbInt l_index,t_mx2_CatchExpr* l_value);
  t_mx2_CatchExpr* m_Get(bbInt l_index);
  bbInt m_FindLastIndex(t_mx2_CatchExpr* l_value,bbInt l_start);
  bbInt m_FindIndex(t_mx2_CatchExpr* l_value,bbInt l_start);
  void m_Erase(bbInt l_index1,bbInt l_index2);
  void m_Erase(bbInt l_index);
  bbBool m_Empty();
  bbArray<bbGCVar<t_mx2_CatchExpr>>* m_Data();
  bbBool m_Contains(t_mx2_CatchExpr* l_value);
  void m_Clear();
  bbInt m_Capacity();
  t_std_collections_Stack_1Tt_mx2_CatchExpr_2_BackwardsIterator m_Backwards();
  t_std_collections_Stack_1Tt_mx2_CatchExpr_2_Iterator m_All();
  void m_AddAll(bbArray<bbGCVar<t_mx2_CatchExpr>>* l_values);
  void m_Add(t_mx2_CatchExpr* l_value);
};

struct t_std_collections_Stack_1Tt_mx2_StmtExpr_2_Iterator{
  const char *typeName()const{return "t_std_collections_Stack_1Tt_mx2_StmtExpr_2_Iterator";}

  bbGCVar<t_std_collections_Stack_1Tt_mx2_StmtExpr_2> m__0stack{};
  bbInt m__0index{};
  bbInt m__0seq{};

  t_std_collections_Stack_1Tt_mx2_StmtExpr_2_Iterator(t_std_collections_Stack_1Tt_mx2_StmtExpr_2* l_stack,bbInt l_index);

  void m_Insert(t_mx2_StmtExpr* l_value);
  void m_Erase();
  void m_Current(t_mx2_StmtExpr* l_current);
  t_mx2_StmtExpr* m_Current();
  void m_Bump();
  bbBool m_AtEnd();
  void m_AssertSeq();
  void m_AssertCurrent();

  t_std_collections_Stack_1Tt_mx2_StmtExpr_2_Iterator(){
  }

  t_std_collections_Stack_1Tt_mx2_StmtExpr_2_Iterator(bbNullCtor_t){
  }
};

int bbCompare(const t_std_collections_Stack_1Tt_mx2_StmtExpr_2_Iterator&x,const t_std_collections_Stack_1Tt_mx2_StmtExpr_2_Iterator&y);

void bbGCMark(const t_std_collections_Stack_1Tt_mx2_StmtExpr_2_Iterator&);

struct t_std_collections_Stack_1Tt_mx2_StmtExpr_2_BackwardsIterator{
  const char *typeName()const{return "t_std_collections_Stack_1Tt_mx2_StmtExpr_2_BackwardsIterator";}

  bbGCVar<t_std_collections_Stack_1Tt_mx2_StmtExpr_2> m__0stack{};
  bbInt m__0index{};
  bbInt m__0seq{};

  t_std_collections_Stack_1Tt_mx2_StmtExpr_2_BackwardsIterator(t_std_collections_Stack_1Tt_mx2_StmtExpr_2* l_stack,bbInt l_index);

  void m_Insert(t_mx2_StmtExpr* l_value);
  void m_Erase();
  void m_Current(t_mx2_StmtExpr* l_current);
  t_mx2_StmtExpr* m_Current();
  void m_Bump();
  bbBool m_AtEnd();
  void m_AssertSeq();
  void m_AssertCurrent();

  t_std_collections_Stack_1Tt_mx2_StmtExpr_2_BackwardsIterator(){
  }

  t_std_collections_Stack_1Tt_mx2_StmtExpr_2_BackwardsIterator(bbNullCtor_t){
  }
};

int bbCompare(const t_std_collections_Stack_1Tt_mx2_StmtExpr_2_BackwardsIterator&x,const t_std_collections_Stack_1Tt_mx2_StmtExpr_2_BackwardsIterator&y);

void bbGCMark(const t_std_collections_Stack_1Tt_mx2_StmtExpr_2_BackwardsIterator&);

struct t_std_collections_Stack_1Tt_mx2_StmtExpr_2 : public bbObject,public virtual t_std_collections_IContainer_1Tt_mx2_StmtExpr_2{

  const char *typeName()const{return "t_std_collections_Stack_1Tt_mx2_StmtExpr_2";}

  bbGCVar<bbArray<bbGCVar<t_mx2_StmtExpr>>> m__0data{};
  bbInt m__0length{};
  bbInt m__0seq{};

  void gcMark();

  t_std_collections_Stack_1Tt_mx2_StmtExpr_2(t_std_collections_List_1Tt_mx2_StmtExpr_2* l_values);
  t_std_collections_Stack_1Tt_mx2_StmtExpr_2(t_std_collections_Stack_1Tt_mx2_StmtExpr_2* l_values);
  t_std_collections_Stack_1Tt_mx2_StmtExpr_2(bbArray<bbGCVar<t_mx2_StmtExpr>>* l_values);
  t_std_collections_Stack_1Tt_mx2_StmtExpr_2(bbInt l_length);
  t_std_collections_Stack_1Tt_mx2_StmtExpr_2();

  void m__idxeq(bbInt l_index,t_mx2_StmtExpr* l_value);
  t_mx2_StmtExpr* m__idx(bbInt l_index);
  t_mx2_StmtExpr* m_Top();
  bbArray<bbGCVar<t_mx2_StmtExpr>>* m_ToArray();
  void m_Swap(bbInt l_index1,bbInt l_index2);
  void m_Sort(bbFunction<bbInt(t_mx2_StmtExpr*,t_mx2_StmtExpr*)> l_compareFunc,bbInt l_lo,bbInt l_hi);
  void m_Sort(bbFunction<bbInt(t_mx2_StmtExpr*,t_mx2_StmtExpr*)> l_compareFunc);
  void m_Sort(bbBool l_ascending);
  t_std_collections_Stack_1Tt_mx2_StmtExpr_2* m_Slice(bbInt l_index1,bbInt l_index2);
  t_std_collections_Stack_1Tt_mx2_StmtExpr_2* m_Slice(bbInt l_index);
  void m_Set(bbInt l_index,t_mx2_StmtExpr* l_value);
  void m_Resize(bbInt l_length);
  void m_Reserve(bbInt l_capacity);
  bbBool m_RemoveLast(t_mx2_StmtExpr* l_value,bbInt l_start);
  bbInt m_RemoveEach(t_mx2_StmtExpr* l_value);
  bbBool m_Remove(t_mx2_StmtExpr* l_value,bbInt l_start);
  void m_Push(t_mx2_StmtExpr* l_value);
  t_mx2_StmtExpr* m_Pop();
  bbInt m_Length();
  void m_Insert(bbInt l_index,t_mx2_StmtExpr* l_value);
  t_mx2_StmtExpr* m_Get(bbInt l_index);
  bbInt m_FindLastIndex(t_mx2_StmtExpr* l_value,bbInt l_start);
  bbInt m_FindIndex(t_mx2_StmtExpr* l_value,bbInt l_start);
  void m_Erase(bbInt l_index1,bbInt l_index2);
  void m_Erase(bbInt l_index);
  bbBool m_Empty();
  bbArray<bbGCVar<t_mx2_StmtExpr>>* m_Data();
  bbBool m_Contains(t_mx2_StmtExpr* l_value);
  void m_Clear();
  bbInt m_Capacity();
  t_std_collections_Stack_1Tt_mx2_StmtExpr_2_BackwardsIterator m_Backwards();
  t_std_collections_Stack_1Tt_mx2_StmtExpr_2_Iterator m_All();
  void m_AddAll(bbArray<bbGCVar<t_mx2_StmtExpr>>* l_values);
  void m_Add(t_mx2_StmtExpr* l_value);
};

struct t_std_collections_Stack_1Tt_mx2_CaseExpr_2_Iterator{
  const char *typeName()const{return "t_std_collections_Stack_1Tt_mx2_CaseExpr_2_Iterator";}

  bbGCVar<t_std_collections_Stack_1Tt_mx2_CaseExpr_2> m__0stack{};
  bbInt m__0index{};
  bbInt m__0seq{};

  t_std_collections_Stack_1Tt_mx2_CaseExpr_2_Iterator(t_std_collections_Stack_1Tt_mx2_CaseExpr_2* l_stack,bbInt l_index);

  void m_Insert(t_mx2_CaseExpr* l_value);
  void m_Erase();
  void m_Current(t_mx2_CaseExpr* l_current);
  t_mx2_CaseExpr* m_Current();
  void m_Bump();
  bbBool m_AtEnd();
  void m_AssertSeq();
  void m_AssertCurrent();

  t_std_collections_Stack_1Tt_mx2_CaseExpr_2_Iterator(){
  }

  t_std_collections_Stack_1Tt_mx2_CaseExpr_2_Iterator(bbNullCtor_t){
  }
};

int bbCompare(const t_std_collections_Stack_1Tt_mx2_CaseExpr_2_Iterator&x,const t_std_collections_Stack_1Tt_mx2_CaseExpr_2_Iterator&y);

void bbGCMark(const t_std_collections_Stack_1Tt_mx2_CaseExpr_2_Iterator&);

struct t_std_collections_Stack_1Tt_mx2_CaseExpr_2_BackwardsIterator{
  const char *typeName()const{return "t_std_collections_Stack_1Tt_mx2_CaseExpr_2_BackwardsIterator";}

  bbGCVar<t_std_collections_Stack_1Tt_mx2_CaseExpr_2> m__0stack{};
  bbInt m__0index{};
  bbInt m__0seq{};

  t_std_collections_Stack_1Tt_mx2_CaseExpr_2_BackwardsIterator(t_std_collections_Stack_1Tt_mx2_CaseExpr_2* l_stack,bbInt l_index);

  void m_Insert(t_mx2_CaseExpr* l_value);
  void m_Erase();
  void m_Current(t_mx2_CaseExpr* l_current);
  t_mx2_CaseExpr* m_Current();
  void m_Bump();
  bbBool m_AtEnd();
  void m_AssertSeq();
  void m_AssertCurrent();

  t_std_collections_Stack_1Tt_mx2_CaseExpr_2_BackwardsIterator(){
  }

  t_std_collections_Stack_1Tt_mx2_CaseExpr_2_BackwardsIterator(bbNullCtor_t){
  }
};

int bbCompare(const t_std_collections_Stack_1Tt_mx2_CaseExpr_2_BackwardsIterator&x,const t_std_collections_Stack_1Tt_mx2_CaseExpr_2_BackwardsIterator&y);

void bbGCMark(const t_std_collections_Stack_1Tt_mx2_CaseExpr_2_BackwardsIterator&);

struct t_std_collections_Stack_1Tt_mx2_CaseExpr_2 : public bbObject,public virtual t_std_collections_IContainer_1Tt_mx2_CaseExpr_2{

  const char *typeName()const{return "t_std_collections_Stack_1Tt_mx2_CaseExpr_2";}

  bbGCVar<bbArray<bbGCVar<t_mx2_CaseExpr>>> m__0data{};
  bbInt m__0length{};
  bbInt m__0seq{};

  void gcMark();

  t_std_collections_Stack_1Tt_mx2_CaseExpr_2(t_std_collections_List_1Tt_mx2_CaseExpr_2* l_values);
  t_std_collections_Stack_1Tt_mx2_CaseExpr_2(t_std_collections_Stack_1Tt_mx2_CaseExpr_2* l_values);
  t_std_collections_Stack_1Tt_mx2_CaseExpr_2(bbArray<bbGCVar<t_mx2_CaseExpr>>* l_values);
  t_std_collections_Stack_1Tt_mx2_CaseExpr_2(bbInt l_length);
  t_std_collections_Stack_1Tt_mx2_CaseExpr_2();

  void m__idxeq(bbInt l_index,t_mx2_CaseExpr* l_value);
  t_mx2_CaseExpr* m__idx(bbInt l_index);
  t_mx2_CaseExpr* m_Top();
  bbArray<bbGCVar<t_mx2_CaseExpr>>* m_ToArray();
  void m_Swap(bbInt l_index1,bbInt l_index2);
  void m_Sort(bbFunction<bbInt(t_mx2_CaseExpr*,t_mx2_CaseExpr*)> l_compareFunc,bbInt l_lo,bbInt l_hi);
  void m_Sort(bbFunction<bbInt(t_mx2_CaseExpr*,t_mx2_CaseExpr*)> l_compareFunc);
  void m_Sort(bbBool l_ascending);
  t_std_collections_Stack_1Tt_mx2_CaseExpr_2* m_Slice(bbInt l_index1,bbInt l_index2);
  t_std_collections_Stack_1Tt_mx2_CaseExpr_2* m_Slice(bbInt l_index);
  void m_Set(bbInt l_index,t_mx2_CaseExpr* l_value);
  void m_Resize(bbInt l_length);
  void m_Reserve(bbInt l_capacity);
  bbBool m_RemoveLast(t_mx2_CaseExpr* l_value,bbInt l_start);
  bbInt m_RemoveEach(t_mx2_CaseExpr* l_value);
  bbBool m_Remove(t_mx2_CaseExpr* l_value,bbInt l_start);
  void m_Push(t_mx2_CaseExpr* l_value);
  t_mx2_CaseExpr* m_Pop();
  bbInt m_Length();
  void m_Insert(bbInt l_index,t_mx2_CaseExpr* l_value);
  t_mx2_CaseExpr* m_Get(bbInt l_index);
  bbInt m_FindLastIndex(t_mx2_CaseExpr* l_value,bbInt l_start);
  bbInt m_FindIndex(t_mx2_CaseExpr* l_value,bbInt l_start);
  void m_Erase(bbInt l_index1,bbInt l_index2);
  void m_Erase(bbInt l_index);
  bbBool m_Empty();
  bbArray<bbGCVar<t_mx2_CaseExpr>>* m_Data();
  bbBool m_Contains(t_mx2_CaseExpr* l_value);
  void m_Clear();
  bbInt m_Capacity();
  t_std_collections_Stack_1Tt_mx2_CaseExpr_2_BackwardsIterator m_Backwards();
  t_std_collections_Stack_1Tt_mx2_CaseExpr_2_Iterator m_All();
  void m_AddAll(bbArray<bbGCVar<t_mx2_CaseExpr>>* l_values);
  void m_Add(t_mx2_CaseExpr* l_value);
};

struct t_std_collections_Stack_1Tt_mx2_Expr_2_Iterator{
  const char *typeName()const{return "t_std_collections_Stack_1Tt_mx2_Expr_2_Iterator";}

  bbGCVar<t_std_collections_Stack_1Tt_mx2_Expr_2> m__0stack{};
  bbInt m__0index{};
  bbInt m__0seq{};

  t_std_collections_Stack_1Tt_mx2_Expr_2_Iterator(t_std_collections_Stack_1Tt_mx2_Expr_2* l_stack,bbInt l_index);

  void m_Insert(t_mx2_Expr* l_value);
  void m_Erase();
  void m_Current(t_mx2_Expr* l_current);
  t_mx2_Expr* m_Current();
  void m_Bump();
  bbBool m_AtEnd();
  void m_AssertSeq();
  void m_AssertCurrent();

  t_std_collections_Stack_1Tt_mx2_Expr_2_Iterator(){
  }

  t_std_collections_Stack_1Tt_mx2_Expr_2_Iterator(bbNullCtor_t){
  }
};

int bbCompare(const t_std_collections_Stack_1Tt_mx2_Expr_2_Iterator&x,const t_std_collections_Stack_1Tt_mx2_Expr_2_Iterator&y);

void bbGCMark(const t_std_collections_Stack_1Tt_mx2_Expr_2_Iterator&);

struct t_std_collections_Stack_1Tt_mx2_Expr_2_BackwardsIterator{
  const char *typeName()const{return "t_std_collections_Stack_1Tt_mx2_Expr_2_BackwardsIterator";}

  bbGCVar<t_std_collections_Stack_1Tt_mx2_Expr_2> m__0stack{};
  bbInt m__0index{};
  bbInt m__0seq{};

  t_std_collections_Stack_1Tt_mx2_Expr_2_BackwardsIterator(t_std_collections_Stack_1Tt_mx2_Expr_2* l_stack,bbInt l_index);

  void m_Insert(t_mx2_Expr* l_value);
  void m_Erase();
  void m_Current(t_mx2_Expr* l_current);
  t_mx2_Expr* m_Current();
  void m_Bump();
  bbBool m_AtEnd();
  void m_AssertSeq();
  void m_AssertCurrent();

  t_std_collections_Stack_1Tt_mx2_Expr_2_BackwardsIterator(){
  }

  t_std_collections_Stack_1Tt_mx2_Expr_2_BackwardsIterator(bbNullCtor_t){
  }
};

int bbCompare(const t_std_collections_Stack_1Tt_mx2_Expr_2_BackwardsIterator&x,const t_std_collections_Stack_1Tt_mx2_Expr_2_BackwardsIterator&y);

void bbGCMark(const t_std_collections_Stack_1Tt_mx2_Expr_2_BackwardsIterator&);

struct t_std_collections_Stack_1Tt_mx2_Expr_2 : public bbObject,public virtual t_std_collections_IContainer_1Tt_mx2_Expr_2{

  const char *typeName()const{return "t_std_collections_Stack_1Tt_mx2_Expr_2";}

  bbGCVar<bbArray<bbGCVar<t_mx2_Expr>>> m__0data{};
  bbInt m__0length{};
  bbInt m__0seq{};

  void gcMark();

  t_std_collections_Stack_1Tt_mx2_Expr_2(t_std_collections_List_1Tt_mx2_Expr_2* l_values);
  t_std_collections_Stack_1Tt_mx2_Expr_2(t_std_collections_Stack_1Tt_mx2_Expr_2* l_values);
  t_std_collections_Stack_1Tt_mx2_Expr_2(bbArray<bbGCVar<t_mx2_Expr>>* l_values);
  t_std_collections_Stack_1Tt_mx2_Expr_2(bbInt l_length);
  t_std_collections_Stack_1Tt_mx2_Expr_2();

  void m__idxeq(bbInt l_index,t_mx2_Expr* l_value);
  t_mx2_Expr* m__idx(bbInt l_index);
  t_mx2_Expr* m_Top();
  bbArray<bbGCVar<t_mx2_Expr>>* m_ToArray();
  void m_Swap(bbInt l_index1,bbInt l_index2);
  void m_Sort(bbFunction<bbInt(t_mx2_Expr*,t_mx2_Expr*)> l_compareFunc,bbInt l_lo,bbInt l_hi);
  void m_Sort(bbFunction<bbInt(t_mx2_Expr*,t_mx2_Expr*)> l_compareFunc);
  void m_Sort(bbBool l_ascending);
  t_std_collections_Stack_1Tt_mx2_Expr_2* m_Slice(bbInt l_index1,bbInt l_index2);
  t_std_collections_Stack_1Tt_mx2_Expr_2* m_Slice(bbInt l_index);
  void m_Set(bbInt l_index,t_mx2_Expr* l_value);
  void m_Resize(bbInt l_length);
  void m_Reserve(bbInt l_capacity);
  bbBool m_RemoveLast(t_mx2_Expr* l_value,bbInt l_start);
  bbInt m_RemoveEach(t_mx2_Expr* l_value);
  bbBool m_Remove(t_mx2_Expr* l_value,bbInt l_start);
  void m_Push(t_mx2_Expr* l_value);
  t_mx2_Expr* m_Pop();
  bbInt m_Length();
  void m_Insert(bbInt l_index,t_mx2_Expr* l_value);
  t_mx2_Expr* m_Get(bbInt l_index);
  bbInt m_FindLastIndex(t_mx2_Expr* l_value,bbInt l_start);
  bbInt m_FindIndex(t_mx2_Expr* l_value,bbInt l_start);
  void m_Erase(bbInt l_index1,bbInt l_index2);
  void m_Erase(bbInt l_index);
  bbBool m_Empty();
  bbArray<bbGCVar<t_mx2_Expr>>* m_Data();
  bbBool m_Contains(t_mx2_Expr* l_value);
  void m_Clear();
  bbInt m_Capacity();
  t_std_collections_Stack_1Tt_mx2_Expr_2_BackwardsIterator m_Backwards();
  t_std_collections_Stack_1Tt_mx2_Expr_2_Iterator m_All();
  void m_AddAll(bbArray<bbGCVar<t_mx2_Expr>>* l_values);
  void m_Add(t_mx2_Expr* l_value);
};

struct t_std_collections_Stack_1Tt_mx2_VarDecl_2_Iterator{
  const char *typeName()const{return "t_std_collections_Stack_1Tt_mx2_VarDecl_2_Iterator";}

  bbGCVar<t_std_collections_Stack_1Tt_mx2_VarDecl_2> m__0stack{};
  bbInt m__0index{};
  bbInt m__0seq{};

  t_std_collections_Stack_1Tt_mx2_VarDecl_2_Iterator(t_std_collections_Stack_1Tt_mx2_VarDecl_2* l_stack,bbInt l_index);

  void m_Insert(t_mx2_VarDecl* l_value);
  void m_Erase();
  void m_Current(t_mx2_VarDecl* l_current);
  t_mx2_VarDecl* m_Current();
  void m_Bump();
  bbBool m_AtEnd();
  void m_AssertSeq();
  void m_AssertCurrent();

  t_std_collections_Stack_1Tt_mx2_VarDecl_2_Iterator(){
  }

  t_std_collections_Stack_1Tt_mx2_VarDecl_2_Iterator(bbNullCtor_t){
  }
};

int bbCompare(const t_std_collections_Stack_1Tt_mx2_VarDecl_2_Iterator&x,const t_std_collections_Stack_1Tt_mx2_VarDecl_2_Iterator&y);

void bbGCMark(const t_std_collections_Stack_1Tt_mx2_VarDecl_2_Iterator&);

struct t_std_collections_Stack_1Tt_mx2_VarDecl_2_BackwardsIterator{
  const char *typeName()const{return "t_std_collections_Stack_1Tt_mx2_VarDecl_2_BackwardsIterator";}

  bbGCVar<t_std_collections_Stack_1Tt_mx2_VarDecl_2> m__0stack{};
  bbInt m__0index{};
  bbInt m__0seq{};

  t_std_collections_Stack_1Tt_mx2_VarDecl_2_BackwardsIterator(t_std_collections_Stack_1Tt_mx2_VarDecl_2* l_stack,bbInt l_index);

  void m_Insert(t_mx2_VarDecl* l_value);
  void m_Erase();
  void m_Current(t_mx2_VarDecl* l_current);
  t_mx2_VarDecl* m_Current();
  void m_Bump();
  bbBool m_AtEnd();
  void m_AssertSeq();
  void m_AssertCurrent();

  t_std_collections_Stack_1Tt_mx2_VarDecl_2_BackwardsIterator(){
  }

  t_std_collections_Stack_1Tt_mx2_VarDecl_2_BackwardsIterator(bbNullCtor_t){
  }
};

int bbCompare(const t_std_collections_Stack_1Tt_mx2_VarDecl_2_BackwardsIterator&x,const t_std_collections_Stack_1Tt_mx2_VarDecl_2_BackwardsIterator&y);

void bbGCMark(const t_std_collections_Stack_1Tt_mx2_VarDecl_2_BackwardsIterator&);

struct t_std_collections_Stack_1Tt_mx2_VarDecl_2 : public bbObject,public virtual t_std_collections_IContainer_1Tt_mx2_VarDecl_2{

  const char *typeName()const{return "t_std_collections_Stack_1Tt_mx2_VarDecl_2";}

  bbGCVar<bbArray<bbGCVar<t_mx2_VarDecl>>> m__0data{};
  bbInt m__0length{};
  bbInt m__0seq{};

  void gcMark();

  t_std_collections_Stack_1Tt_mx2_VarDecl_2(t_std_collections_List_1Tt_mx2_VarDecl_2* l_values);
  t_std_collections_Stack_1Tt_mx2_VarDecl_2(t_std_collections_Stack_1Tt_mx2_VarDecl_2* l_values);
  t_std_collections_Stack_1Tt_mx2_VarDecl_2(bbArray<bbGCVar<t_mx2_VarDecl>>* l_values);
  t_std_collections_Stack_1Tt_mx2_VarDecl_2(bbInt l_length);
  t_std_collections_Stack_1Tt_mx2_VarDecl_2();

  void m__idxeq(bbInt l_index,t_mx2_VarDecl* l_value);
  t_mx2_VarDecl* m__idx(bbInt l_index);
  t_mx2_VarDecl* m_Top();
  bbArray<bbGCVar<t_mx2_VarDecl>>* m_ToArray();
  void m_Swap(bbInt l_index1,bbInt l_index2);
  void m_Sort(bbFunction<bbInt(t_mx2_VarDecl*,t_mx2_VarDecl*)> l_compareFunc,bbInt l_lo,bbInt l_hi);
  void m_Sort(bbFunction<bbInt(t_mx2_VarDecl*,t_mx2_VarDecl*)> l_compareFunc);
  void m_Sort(bbBool l_ascending);
  t_std_collections_Stack_1Tt_mx2_VarDecl_2* m_Slice(bbInt l_index1,bbInt l_index2);
  t_std_collections_Stack_1Tt_mx2_VarDecl_2* m_Slice(bbInt l_index);
  void m_Set(bbInt l_index,t_mx2_VarDecl* l_value);
  void m_Resize(bbInt l_length);
  void m_Reserve(bbInt l_capacity);
  bbBool m_RemoveLast(t_mx2_VarDecl* l_value,bbInt l_start);
  bbInt m_RemoveEach(t_mx2_VarDecl* l_value);
  bbBool m_Remove(t_mx2_VarDecl* l_value,bbInt l_start);
  void m_Push(t_mx2_VarDecl* l_value);
  t_mx2_VarDecl* m_Pop();
  bbInt m_Length();
  void m_Insert(bbInt l_index,t_mx2_VarDecl* l_value);
  t_mx2_VarDecl* m_Get(bbInt l_index);
  bbInt m_FindLastIndex(t_mx2_VarDecl* l_value,bbInt l_start);
  bbInt m_FindIndex(t_mx2_VarDecl* l_value,bbInt l_start);
  void m_Erase(bbInt l_index1,bbInt l_index2);
  void m_Erase(bbInt l_index);
  bbBool m_Empty();
  bbArray<bbGCVar<t_mx2_VarDecl>>* m_Data();
  bbBool m_Contains(t_mx2_VarDecl* l_value);
  void m_Clear();
  bbInt m_Capacity();
  t_std_collections_Stack_1Tt_mx2_VarDecl_2_BackwardsIterator m_Backwards();
  t_std_collections_Stack_1Tt_mx2_VarDecl_2_Iterator m_All();
  void m_AddAll(bbArray<bbGCVar<t_mx2_VarDecl>>* l_values);
  void m_Add(t_mx2_VarDecl* l_value);
};

struct t_std_collections_Stack_1Tt_mx2_CatchStmt_2_Iterator{
  const char *typeName()const{return "t_std_collections_Stack_1Tt_mx2_CatchStmt_2_Iterator";}

  bbGCVar<t_std_collections_Stack_1Tt_mx2_CatchStmt_2> m__0stack{};
  bbInt m__0index{};
  bbInt m__0seq{};

  t_std_collections_Stack_1Tt_mx2_CatchStmt_2_Iterator(t_std_collections_Stack_1Tt_mx2_CatchStmt_2* l_stack,bbInt l_index);

  void m_Insert(t_mx2_CatchStmt* l_value);
  void m_Erase();
  void m_Current(t_mx2_CatchStmt* l_current);
  t_mx2_CatchStmt* m_Current();
  void m_Bump();
  bbBool m_AtEnd();
  void m_AssertSeq();
  void m_AssertCurrent();

  t_std_collections_Stack_1Tt_mx2_CatchStmt_2_Iterator(){
  }

  t_std_collections_Stack_1Tt_mx2_CatchStmt_2_Iterator(bbNullCtor_t){
  }
};

int bbCompare(const t_std_collections_Stack_1Tt_mx2_CatchStmt_2_Iterator&x,const t_std_collections_Stack_1Tt_mx2_CatchStmt_2_Iterator&y);

void bbGCMark(const t_std_collections_Stack_1Tt_mx2_CatchStmt_2_Iterator&);

struct t_std_collections_Stack_1Tt_mx2_CatchStmt_2_BackwardsIterator{
  const char *typeName()const{return "t_std_collections_Stack_1Tt_mx2_CatchStmt_2_BackwardsIterator";}

  bbGCVar<t_std_collections_Stack_1Tt_mx2_CatchStmt_2> m__0stack{};
  bbInt m__0index{};
  bbInt m__0seq{};

  t_std_collections_Stack_1Tt_mx2_CatchStmt_2_BackwardsIterator(t_std_collections_Stack_1Tt_mx2_CatchStmt_2* l_stack,bbInt l_index);

  void m_Insert(t_mx2_CatchStmt* l_value);
  void m_Erase();
  void m_Current(t_mx2_CatchStmt* l_current);
  t_mx2_CatchStmt* m_Current();
  void m_Bump();
  bbBool m_AtEnd();
  void m_AssertSeq();
  void m_AssertCurrent();

  t_std_collections_Stack_1Tt_mx2_CatchStmt_2_BackwardsIterator(){
  }

  t_std_collections_Stack_1Tt_mx2_CatchStmt_2_BackwardsIterator(bbNullCtor_t){
  }
};

int bbCompare(const t_std_collections_Stack_1Tt_mx2_CatchStmt_2_BackwardsIterator&x,const t_std_collections_Stack_1Tt_mx2_CatchStmt_2_BackwardsIterator&y);

void bbGCMark(const t_std_collections_Stack_1Tt_mx2_CatchStmt_2_BackwardsIterator&);

struct t_std_collections_Stack_1Tt_mx2_CatchStmt_2 : public bbObject,public virtual t_std_collections_IContainer_1Tt_mx2_CatchStmt_2{

  const char *typeName()const{return "t_std_collections_Stack_1Tt_mx2_CatchStmt_2";}

  bbGCVar<bbArray<bbGCVar<t_mx2_CatchStmt>>> m__0data{};
  bbInt m__0length{};
  bbInt m__0seq{};

  void gcMark();

  t_std_collections_Stack_1Tt_mx2_CatchStmt_2(t_std_collections_List_1Tt_mx2_CatchStmt_2* l_values);
  t_std_collections_Stack_1Tt_mx2_CatchStmt_2(t_std_collections_Stack_1Tt_mx2_CatchStmt_2* l_values);
  t_std_collections_Stack_1Tt_mx2_CatchStmt_2(bbArray<bbGCVar<t_mx2_CatchStmt>>* l_values);
  t_std_collections_Stack_1Tt_mx2_CatchStmt_2(bbInt l_length);
  t_std_collections_Stack_1Tt_mx2_CatchStmt_2();

  void m__idxeq(bbInt l_index,t_mx2_CatchStmt* l_value);
  t_mx2_CatchStmt* m__idx(bbInt l_index);
  t_mx2_CatchStmt* m_Top();
  bbArray<bbGCVar<t_mx2_CatchStmt>>* m_ToArray();
  void m_Swap(bbInt l_index1,bbInt l_index2);
  void m_Sort(bbFunction<bbInt(t_mx2_CatchStmt*,t_mx2_CatchStmt*)> l_compareFunc,bbInt l_lo,bbInt l_hi);
  void m_Sort(bbFunction<bbInt(t_mx2_CatchStmt*,t_mx2_CatchStmt*)> l_compareFunc);
  void m_Sort(bbBool l_ascending);
  t_std_collections_Stack_1Tt_mx2_CatchStmt_2* m_Slice(bbInt l_index1,bbInt l_index2);
  t_std_collections_Stack_1Tt_mx2_CatchStmt_2* m_Slice(bbInt l_index);
  void m_Set(bbInt l_index,t_mx2_CatchStmt* l_value);
  void m_Resize(bbInt l_length);
  void m_Reserve(bbInt l_capacity);
  bbBool m_RemoveLast(t_mx2_CatchStmt* l_value,bbInt l_start);
  bbInt m_RemoveEach(t_mx2_CatchStmt* l_value);
  bbBool m_Remove(t_mx2_CatchStmt* l_value,bbInt l_start);
  void m_Push(t_mx2_CatchStmt* l_value);
  t_mx2_CatchStmt* m_Pop();
  bbInt m_Length();
  void m_Insert(bbInt l_index,t_mx2_CatchStmt* l_value);
  t_mx2_CatchStmt* m_Get(bbInt l_index);
  bbInt m_FindLastIndex(t_mx2_CatchStmt* l_value,bbInt l_start);
  bbInt m_FindIndex(t_mx2_CatchStmt* l_value,bbInt l_start);
  void m_Erase(bbInt l_index1,bbInt l_index2);
  void m_Erase(bbInt l_index);
  bbBool m_Empty();
  bbArray<bbGCVar<t_mx2_CatchStmt>>* m_Data();
  bbBool m_Contains(t_mx2_CatchStmt* l_value);
  void m_Clear();
  bbInt m_Capacity();
  t_std_collections_Stack_1Tt_mx2_CatchStmt_2_BackwardsIterator m_Backwards();
  t_std_collections_Stack_1Tt_mx2_CatchStmt_2_Iterator m_All();
  void m_AddAll(bbArray<bbGCVar<t_mx2_CatchStmt>>* l_values);
  void m_Add(t_mx2_CatchStmt* l_value);
};

struct t_std_collections_Stack_1Tt_mx2_CaseStmt_2_Iterator{
  const char *typeName()const{return "t_std_collections_Stack_1Tt_mx2_CaseStmt_2_Iterator";}

  bbGCVar<t_std_collections_Stack_1Tt_mx2_CaseStmt_2> m__0stack{};
  bbInt m__0index{};
  bbInt m__0seq{};

  t_std_collections_Stack_1Tt_mx2_CaseStmt_2_Iterator(t_std_collections_Stack_1Tt_mx2_CaseStmt_2* l_stack,bbInt l_index);

  void m_Insert(t_mx2_CaseStmt* l_value);
  void m_Erase();
  void m_Current(t_mx2_CaseStmt* l_current);
  t_mx2_CaseStmt* m_Current();
  void m_Bump();
  bbBool m_AtEnd();
  void m_AssertSeq();
  void m_AssertCurrent();

  t_std_collections_Stack_1Tt_mx2_CaseStmt_2_Iterator(){
  }

  t_std_collections_Stack_1Tt_mx2_CaseStmt_2_Iterator(bbNullCtor_t){
  }
};

int bbCompare(const t_std_collections_Stack_1Tt_mx2_CaseStmt_2_Iterator&x,const t_std_collections_Stack_1Tt_mx2_CaseStmt_2_Iterator&y);

void bbGCMark(const t_std_collections_Stack_1Tt_mx2_CaseStmt_2_Iterator&);

struct t_std_collections_Stack_1Tt_mx2_CaseStmt_2_BackwardsIterator{
  const char *typeName()const{return "t_std_collections_Stack_1Tt_mx2_CaseStmt_2_BackwardsIterator";}

  bbGCVar<t_std_collections_Stack_1Tt_mx2_CaseStmt_2> m__0stack{};
  bbInt m__0index{};
  bbInt m__0seq{};

  t_std_collections_Stack_1Tt_mx2_CaseStmt_2_BackwardsIterator(t_std_collections_Stack_1Tt_mx2_CaseStmt_2* l_stack,bbInt l_index);

  void m_Insert(t_mx2_CaseStmt* l_value);
  void m_Erase();
  void m_Current(t_mx2_CaseStmt* l_current);
  t_mx2_CaseStmt* m_Current();
  void m_Bump();
  bbBool m_AtEnd();
  void m_AssertSeq();
  void m_AssertCurrent();

  t_std_collections_Stack_1Tt_mx2_CaseStmt_2_BackwardsIterator(){
  }

  t_std_collections_Stack_1Tt_mx2_CaseStmt_2_BackwardsIterator(bbNullCtor_t){
  }
};

int bbCompare(const t_std_collections_Stack_1Tt_mx2_CaseStmt_2_BackwardsIterator&x,const t_std_collections_Stack_1Tt_mx2_CaseStmt_2_BackwardsIterator&y);

void bbGCMark(const t_std_collections_Stack_1Tt_mx2_CaseStmt_2_BackwardsIterator&);

struct t_std_collections_Stack_1Tt_mx2_CaseStmt_2 : public bbObject,public virtual t_std_collections_IContainer_1Tt_mx2_CaseStmt_2{

  const char *typeName()const{return "t_std_collections_Stack_1Tt_mx2_CaseStmt_2";}

  bbGCVar<bbArray<bbGCVar<t_mx2_CaseStmt>>> m__0data{};
  bbInt m__0length{};
  bbInt m__0seq{};

  void gcMark();

  t_std_collections_Stack_1Tt_mx2_CaseStmt_2(t_std_collections_List_1Tt_mx2_CaseStmt_2* l_values);
  t_std_collections_Stack_1Tt_mx2_CaseStmt_2(t_std_collections_Stack_1Tt_mx2_CaseStmt_2* l_values);
  t_std_collections_Stack_1Tt_mx2_CaseStmt_2(bbArray<bbGCVar<t_mx2_CaseStmt>>* l_values);
  t_std_collections_Stack_1Tt_mx2_CaseStmt_2(bbInt l_length);
  t_std_collections_Stack_1Tt_mx2_CaseStmt_2();

  void m__idxeq(bbInt l_index,t_mx2_CaseStmt* l_value);
  t_mx2_CaseStmt* m__idx(bbInt l_index);
  t_mx2_CaseStmt* m_Top();
  bbArray<bbGCVar<t_mx2_CaseStmt>>* m_ToArray();
  void m_Swap(bbInt l_index1,bbInt l_index2);
  void m_Sort(bbFunction<bbInt(t_mx2_CaseStmt*,t_mx2_CaseStmt*)> l_compareFunc,bbInt l_lo,bbInt l_hi);
  void m_Sort(bbFunction<bbInt(t_mx2_CaseStmt*,t_mx2_CaseStmt*)> l_compareFunc);
  void m_Sort(bbBool l_ascending);
  t_std_collections_Stack_1Tt_mx2_CaseStmt_2* m_Slice(bbInt l_index1,bbInt l_index2);
  t_std_collections_Stack_1Tt_mx2_CaseStmt_2* m_Slice(bbInt l_index);
  void m_Set(bbInt l_index,t_mx2_CaseStmt* l_value);
  void m_Resize(bbInt l_length);
  void m_Reserve(bbInt l_capacity);
  bbBool m_RemoveLast(t_mx2_CaseStmt* l_value,bbInt l_start);
  bbInt m_RemoveEach(t_mx2_CaseStmt* l_value);
  bbBool m_Remove(t_mx2_CaseStmt* l_value,bbInt l_start);
  void m_Push(t_mx2_CaseStmt* l_value);
  t_mx2_CaseStmt* m_Pop();
  bbInt m_Length();
  void m_Insert(bbInt l_index,t_mx2_CaseStmt* l_value);
  t_mx2_CaseStmt* m_Get(bbInt l_index);
  bbInt m_FindLastIndex(t_mx2_CaseStmt* l_value,bbInt l_start);
  bbInt m_FindIndex(t_mx2_CaseStmt* l_value,bbInt l_start);
  void m_Erase(bbInt l_index1,bbInt l_index2);
  void m_Erase(bbInt l_index);
  bbBool m_Empty();
  bbArray<bbGCVar<t_mx2_CaseStmt>>* m_Data();
  bbBool m_Contains(t_mx2_CaseStmt* l_value);
  void m_Clear();
  bbInt m_Capacity();
  t_std_collections_Stack_1Tt_mx2_CaseStmt_2_BackwardsIterator m_Backwards();
  t_std_collections_Stack_1Tt_mx2_CaseStmt_2_Iterator m_All();
  void m_AddAll(bbArray<bbGCVar<t_mx2_CaseStmt>>* l_values);
  void m_Add(t_mx2_CaseStmt* l_value);
};

struct t_std_collections_Stack_1Tt_mx2_FuncList_2_Iterator{
  const char *typeName()const{return "t_std_collections_Stack_1Tt_mx2_FuncList_2_Iterator";}

  bbGCVar<t_std_collections_Stack_1Tt_mx2_FuncList_2> m__0stack{};
  bbInt m__0index{};
  bbInt m__0seq{};

  t_std_collections_Stack_1Tt_mx2_FuncList_2_Iterator(t_std_collections_Stack_1Tt_mx2_FuncList_2* l_stack,bbInt l_index);

  void m_Insert(t_mx2_FuncList* l_value);
  void m_Erase();
  void m_Current(t_mx2_FuncList* l_current);
  t_mx2_FuncList* m_Current();
  void m_Bump();
  bbBool m_AtEnd();
  void m_AssertSeq();
  void m_AssertCurrent();

  t_std_collections_Stack_1Tt_mx2_FuncList_2_Iterator(){
  }

  t_std_collections_Stack_1Tt_mx2_FuncList_2_Iterator(bbNullCtor_t){
  }
};

int bbCompare(const t_std_collections_Stack_1Tt_mx2_FuncList_2_Iterator&x,const t_std_collections_Stack_1Tt_mx2_FuncList_2_Iterator&y);

void bbGCMark(const t_std_collections_Stack_1Tt_mx2_FuncList_2_Iterator&);

struct t_std_collections_Stack_1Tt_mx2_FuncList_2_BackwardsIterator{
  const char *typeName()const{return "t_std_collections_Stack_1Tt_mx2_FuncList_2_BackwardsIterator";}

  bbGCVar<t_std_collections_Stack_1Tt_mx2_FuncList_2> m__0stack{};
  bbInt m__0index{};
  bbInt m__0seq{};

  t_std_collections_Stack_1Tt_mx2_FuncList_2_BackwardsIterator(t_std_collections_Stack_1Tt_mx2_FuncList_2* l_stack,bbInt l_index);

  void m_Insert(t_mx2_FuncList* l_value);
  void m_Erase();
  void m_Current(t_mx2_FuncList* l_current);
  t_mx2_FuncList* m_Current();
  void m_Bump();
  bbBool m_AtEnd();
  void m_AssertSeq();
  void m_AssertCurrent();

  t_std_collections_Stack_1Tt_mx2_FuncList_2_BackwardsIterator(){
  }

  t_std_collections_Stack_1Tt_mx2_FuncList_2_BackwardsIterator(bbNullCtor_t){
  }
};

int bbCompare(const t_std_collections_Stack_1Tt_mx2_FuncList_2_BackwardsIterator&x,const t_std_collections_Stack_1Tt_mx2_FuncList_2_BackwardsIterator&y);

void bbGCMark(const t_std_collections_Stack_1Tt_mx2_FuncList_2_BackwardsIterator&);

struct t_std_collections_Stack_1Tt_mx2_FuncList_2 : public bbObject,public virtual t_std_collections_IContainer_1Tt_mx2_FuncList_2{

  const char *typeName()const{return "t_std_collections_Stack_1Tt_mx2_FuncList_2";}

  bbGCVar<bbArray<bbGCVar<t_mx2_FuncList>>> m__0data{};
  bbInt m__0length{};
  bbInt m__0seq{};

  void gcMark();

  t_std_collections_Stack_1Tt_mx2_FuncList_2(t_std_collections_List_1Tt_mx2_FuncList_2* l_values);
  t_std_collections_Stack_1Tt_mx2_FuncList_2(t_std_collections_Stack_1Tt_mx2_FuncList_2* l_values);
  t_std_collections_Stack_1Tt_mx2_FuncList_2(bbArray<bbGCVar<t_mx2_FuncList>>* l_values);
  t_std_collections_Stack_1Tt_mx2_FuncList_2(bbInt l_length);
  t_std_collections_Stack_1Tt_mx2_FuncList_2();

  void m__idxeq(bbInt l_index,t_mx2_FuncList* l_value);
  t_mx2_FuncList* m__idx(bbInt l_index);
  t_mx2_FuncList* m_Top();
  bbArray<bbGCVar<t_mx2_FuncList>>* m_ToArray();
  void m_Swap(bbInt l_index1,bbInt l_index2);
  void m_Sort(bbFunction<bbInt(t_mx2_FuncList*,t_mx2_FuncList*)> l_compareFunc,bbInt l_lo,bbInt l_hi);
  void m_Sort(bbFunction<bbInt(t_mx2_FuncList*,t_mx2_FuncList*)> l_compareFunc);
  void m_Sort(bbBool l_ascending);
  t_std_collections_Stack_1Tt_mx2_FuncList_2* m_Slice(bbInt l_index1,bbInt l_index2);
  t_std_collections_Stack_1Tt_mx2_FuncList_2* m_Slice(bbInt l_index);
  void m_Set(bbInt l_index,t_mx2_FuncList* l_value);
  void m_Resize(bbInt l_length);
  void m_Reserve(bbInt l_capacity);
  bbBool m_RemoveLast(t_mx2_FuncList* l_value,bbInt l_start);
  bbInt m_RemoveEach(t_mx2_FuncList* l_value);
  bbBool m_Remove(t_mx2_FuncList* l_value,bbInt l_start);
  void m_Push(t_mx2_FuncList* l_value);
  t_mx2_FuncList* m_Pop();
  bbInt m_Length();
  void m_Insert(bbInt l_index,t_mx2_FuncList* l_value);
  t_mx2_FuncList* m_Get(bbInt l_index);
  bbInt m_FindLastIndex(t_mx2_FuncList* l_value,bbInt l_start);
  bbInt m_FindIndex(t_mx2_FuncList* l_value,bbInt l_start);
  void m_Erase(bbInt l_index1,bbInt l_index2);
  void m_Erase(bbInt l_index);
  bbBool m_Empty();
  bbArray<bbGCVar<t_mx2_FuncList>>* m_Data();
  bbBool m_Contains(t_mx2_FuncList* l_value);
  void m_Clear();
  bbInt m_Capacity();
  t_std_collections_Stack_1Tt_mx2_FuncList_2_BackwardsIterator m_Backwards();
  t_std_collections_Stack_1Tt_mx2_FuncList_2_Iterator m_All();
  void m_AddAll(bbArray<bbGCVar<t_mx2_FuncList>>* l_values);
  void m_Add(t_mx2_FuncList* l_value);
};

#endif
