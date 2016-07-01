
#ifndef MX2_MX2CC_STD_COLLECTIONS_2LIST_H
#define MX2_MX2CC_STD_COLLECTIONS_2LIST_H

#include <bbmonkey.h>
#include "../../../../../modules/std/std.buildv1.0.0/desktop_release_linux/std_collections_2list.h"

// ***** External *****

#include "../../../../../modules/monkey/monkey.buildv1.0.0/desktop_release_linux/monkey_types.h"
#include "mx2cc_std_collections_2container.h"

struct t_std_collections_Stack_1Tt_mx2_Translator_GCTmp_2;
struct t_std_collections_Stack_1Tt_mx2_Stmt_2;
struct t_std_collections_Stack_1Tt_mx2_Toker_2;
struct t_std_collections_Stack_1Tt_mx2_ParseEx_2;
struct t_std_collections_Stack_1Tt_mx2_TypeExpr_2;
struct t_std_collections_Stack_1Tt_mx2_CatchExpr_2;
struct t_std_collections_Stack_1Tt_mx2_StmtExpr_2;
struct t_std_collections_Stack_1Tt_mx2_Expr_2;
struct t_std_collections_Stack_1Tt_mx2_CaseExpr_2;
struct t_std_collections_Stack_1Tt_mx2_VarDecl_2;
struct t_std_collections_Stack_1Tt_mx2_Decl_2;
struct t_std_collections_Stack_1Tt_mx2_CatchStmt_2;
struct t_std_collections_Stack_1Tt_mx2_CaseStmt_2;
struct t_std_collections_Stack_1Tt_mx2_FuncListType_2;
struct t_std_collections_Stack_1Tt_mx2_AliasType_2;
struct t_std_collections_Stack_1Tt_mx2_PNode_2;
struct t_std_collections_Stack_1Tt_mx2_NamespaceScope_2;
struct t_std_collections_Stack_1Tt_mx2_FileScope_2;
struct t_std_collections_Stack_1Tt_mx2_FileDecl_2;
struct t_std_collections_Stack_1Tt_std_collections_Stack_1s_2;
struct t_std_collections_Stack_1Tt_mx2_VarValue_2;
struct t_std_collections_Stack_1Tt_mx2_FuncList_2;
struct t_std_collections_Stack_1Tt_mx2_SNode_2;
struct t_std_collections_Stack_1Tt_mx2_Scope_2;
struct t_std_collections_Stack_1Tt_mx2_ClassType_2;
struct t_std_collections_Stack_1Tt_mx2_ErrorEx_2;
struct t_std_collections_Stack_1Tt_mx2_Module_2;
struct t_std_collections_Stack_1Tt_mx2_FuncValue_2;
struct t_mx2_FuncValue;
struct t_mx2_Module;
struct t_mx2_ErrorEx;
struct t_mx2_ClassType;
struct t_mx2_Scope;
struct t_mx2_SNode;
struct t_mx2_VarValue;
struct t_std_collections_Stack_1s;
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

struct t_std_collections_List_1Tt_mx2_FuncValue_2_Node;
struct t_std_collections_List_1Tt_mx2_FuncValue_2_Iterator;
struct t_std_collections_List_1Tt_mx2_FuncValue_2_BackwardsIterator;
struct t_std_collections_List_1Tt_mx2_FuncValue_2;
struct t_std_collections_List_1Tt_mx2_Module_2_Node;
struct t_std_collections_List_1Tt_mx2_Module_2_Iterator;
struct t_std_collections_List_1Tt_mx2_Module_2_BackwardsIterator;
struct t_std_collections_List_1Tt_mx2_Module_2;
struct t_std_collections_List_1Tt_mx2_ErrorEx_2_Node;
struct t_std_collections_List_1Tt_mx2_ErrorEx_2_Iterator;
struct t_std_collections_List_1Tt_mx2_ErrorEx_2_BackwardsIterator;
struct t_std_collections_List_1Tt_mx2_ErrorEx_2;
struct t_std_collections_List_1Tt_mx2_ClassType_2_Node;
struct t_std_collections_List_1Tt_mx2_ClassType_2_Iterator;
struct t_std_collections_List_1Tt_mx2_ClassType_2_BackwardsIterator;
struct t_std_collections_List_1Tt_mx2_ClassType_2;
struct t_std_collections_List_1Tt_mx2_Scope_2_Node;
struct t_std_collections_List_1Tt_mx2_Scope_2_Iterator;
struct t_std_collections_List_1Tt_mx2_Scope_2_BackwardsIterator;
struct t_std_collections_List_1Tt_mx2_Scope_2;
struct t_std_collections_List_1Tt_mx2_SNode_2_Node;
struct t_std_collections_List_1Tt_mx2_SNode_2_Iterator;
struct t_std_collections_List_1Tt_mx2_SNode_2_BackwardsIterator;
struct t_std_collections_List_1Tt_mx2_SNode_2;
struct t_std_collections_List_1Tt_mx2_VarValue_2_Node;
struct t_std_collections_List_1Tt_mx2_VarValue_2_Iterator;
struct t_std_collections_List_1Tt_mx2_VarValue_2_BackwardsIterator;
struct t_std_collections_List_1Tt_mx2_VarValue_2;
struct t_std_collections_List_1Tt_std_collections_Stack_1s_2_Node;
struct t_std_collections_List_1Tt_std_collections_Stack_1s_2_Iterator;
struct t_std_collections_List_1Tt_std_collections_Stack_1s_2_BackwardsIterator;
struct t_std_collections_List_1Tt_std_collections_Stack_1s_2;
struct t_std_collections_List_1Tt_mx2_FileDecl_2_Node;
struct t_std_collections_List_1Tt_mx2_FileDecl_2_Iterator;
struct t_std_collections_List_1Tt_mx2_FileDecl_2_BackwardsIterator;
struct t_std_collections_List_1Tt_mx2_FileDecl_2;
struct t_std_collections_List_1Tt_mx2_FileScope_2_Node;
struct t_std_collections_List_1Tt_mx2_FileScope_2_Iterator;
struct t_std_collections_List_1Tt_mx2_FileScope_2_BackwardsIterator;
struct t_std_collections_List_1Tt_mx2_FileScope_2;
struct t_std_collections_List_1Tt_mx2_NamespaceScope_2_Node;
struct t_std_collections_List_1Tt_mx2_NamespaceScope_2_Iterator;
struct t_std_collections_List_1Tt_mx2_NamespaceScope_2_BackwardsIterator;
struct t_std_collections_List_1Tt_mx2_NamespaceScope_2;
struct t_std_collections_List_1Tt_mx2_PNode_2_Node;
struct t_std_collections_List_1Tt_mx2_PNode_2_Iterator;
struct t_std_collections_List_1Tt_mx2_PNode_2_BackwardsIterator;
struct t_std_collections_List_1Tt_mx2_PNode_2;
struct t_std_collections_List_1Tt_mx2_AliasType_2_Node;
struct t_std_collections_List_1Tt_mx2_AliasType_2_Iterator;
struct t_std_collections_List_1Tt_mx2_AliasType_2_BackwardsIterator;
struct t_std_collections_List_1Tt_mx2_AliasType_2;
struct t_std_collections_List_1Tt_mx2_FuncListType_2_Node;
struct t_std_collections_List_1Tt_mx2_FuncListType_2_Iterator;
struct t_std_collections_List_1Tt_mx2_FuncListType_2_BackwardsIterator;
struct t_std_collections_List_1Tt_mx2_FuncListType_2;
struct t_std_collections_List_1Tt_mx2_Decl_2_Node;
struct t_std_collections_List_1Tt_mx2_Decl_2_Iterator;
struct t_std_collections_List_1Tt_mx2_Decl_2_BackwardsIterator;
struct t_std_collections_List_1Tt_mx2_Decl_2;
struct t_std_collections_List_1Tt_mx2_ParseEx_2_Node;
struct t_std_collections_List_1Tt_mx2_ParseEx_2_Iterator;
struct t_std_collections_List_1Tt_mx2_ParseEx_2_BackwardsIterator;
struct t_std_collections_List_1Tt_mx2_ParseEx_2;
struct t_std_collections_List_1Tt_mx2_Toker_2_Node;
struct t_std_collections_List_1Tt_mx2_Toker_2_Iterator;
struct t_std_collections_List_1Tt_mx2_Toker_2_BackwardsIterator;
struct t_std_collections_List_1Tt_mx2_Toker_2;
struct t_std_collections_List_1Tt_mx2_Stmt_2_Node;
struct t_std_collections_List_1Tt_mx2_Stmt_2_Iterator;
struct t_std_collections_List_1Tt_mx2_Stmt_2_BackwardsIterator;
struct t_std_collections_List_1Tt_mx2_Stmt_2;
struct t_std_collections_List_1Tt_mx2_Translator_GCTmp_2_Node;
struct t_std_collections_List_1Tt_mx2_Translator_GCTmp_2_Iterator;
struct t_std_collections_List_1Tt_mx2_Translator_GCTmp_2_BackwardsIterator;
struct t_std_collections_List_1Tt_mx2_Translator_GCTmp_2;
struct t_std_collections_List_1Tt_mx2_TypeExpr_2_Node;
struct t_std_collections_List_1Tt_mx2_TypeExpr_2_Iterator;
struct t_std_collections_List_1Tt_mx2_TypeExpr_2_BackwardsIterator;
struct t_std_collections_List_1Tt_mx2_TypeExpr_2;
struct t_std_collections_List_1Tt_mx2_CatchExpr_2_Node;
struct t_std_collections_List_1Tt_mx2_CatchExpr_2_Iterator;
struct t_std_collections_List_1Tt_mx2_CatchExpr_2_BackwardsIterator;
struct t_std_collections_List_1Tt_mx2_CatchExpr_2;
struct t_std_collections_List_1Tt_mx2_StmtExpr_2_Node;
struct t_std_collections_List_1Tt_mx2_StmtExpr_2_Iterator;
struct t_std_collections_List_1Tt_mx2_StmtExpr_2_BackwardsIterator;
struct t_std_collections_List_1Tt_mx2_StmtExpr_2;
struct t_std_collections_List_1Tt_mx2_CaseExpr_2_Node;
struct t_std_collections_List_1Tt_mx2_CaseExpr_2_Iterator;
struct t_std_collections_List_1Tt_mx2_CaseExpr_2_BackwardsIterator;
struct t_std_collections_List_1Tt_mx2_CaseExpr_2;
struct t_std_collections_List_1Tt_mx2_Expr_2_Node;
struct t_std_collections_List_1Tt_mx2_Expr_2_Iterator;
struct t_std_collections_List_1Tt_mx2_Expr_2_BackwardsIterator;
struct t_std_collections_List_1Tt_mx2_Expr_2;
struct t_std_collections_List_1Tt_mx2_VarDecl_2_Node;
struct t_std_collections_List_1Tt_mx2_VarDecl_2_Iterator;
struct t_std_collections_List_1Tt_mx2_VarDecl_2_BackwardsIterator;
struct t_std_collections_List_1Tt_mx2_VarDecl_2;
struct t_std_collections_List_1Tt_mx2_CatchStmt_2_Node;
struct t_std_collections_List_1Tt_mx2_CatchStmt_2_Iterator;
struct t_std_collections_List_1Tt_mx2_CatchStmt_2_BackwardsIterator;
struct t_std_collections_List_1Tt_mx2_CatchStmt_2;
struct t_std_collections_List_1Tt_mx2_CaseStmt_2_Node;
struct t_std_collections_List_1Tt_mx2_CaseStmt_2_Iterator;
struct t_std_collections_List_1Tt_mx2_CaseStmt_2_BackwardsIterator;
struct t_std_collections_List_1Tt_mx2_CaseStmt_2;
struct t_std_collections_List_1Tt_mx2_FuncList_2_Node;
struct t_std_collections_List_1Tt_mx2_FuncList_2_Iterator;
struct t_std_collections_List_1Tt_mx2_FuncList_2_BackwardsIterator;
struct t_std_collections_List_1Tt_mx2_FuncList_2;

extern void g_std_collections_List_1Tt_mx2_Translator_GCTmp_2_AddAll_1Tt_std_collections_List_1Tt_mx2_Translator_GCTmp_2_2(t_std_collections_List_1Tt_mx2_Translator_GCTmp_2* l_self,t_std_collections_List_1Tt_mx2_Translator_GCTmp_2* l_values);
extern void g_std_collections_List_1Tt_mx2_Translator_GCTmp_2_AddAll_1Tt_std_collections_Stack_1Tt_mx2_Translator_GCTmp_2_2(t_std_collections_List_1Tt_mx2_Translator_GCTmp_2* l_self,t_std_collections_Stack_1Tt_mx2_Translator_GCTmp_2* l_values);
extern void g_std_collections_List_1Tt_mx2_Stmt_2_AddAll_1Tt_std_collections_List_1Tt_mx2_Stmt_2_2(t_std_collections_List_1Tt_mx2_Stmt_2* l_self,t_std_collections_List_1Tt_mx2_Stmt_2* l_values);
extern void g_std_collections_List_1Tt_mx2_Stmt_2_AddAll_1Tt_std_collections_Stack_1Tt_mx2_Stmt_2_2(t_std_collections_List_1Tt_mx2_Stmt_2* l_self,t_std_collections_Stack_1Tt_mx2_Stmt_2* l_values);
extern void g_std_collections_List_1Tt_mx2_Toker_2_AddAll_1Tt_std_collections_List_1Tt_mx2_Toker_2_2(t_std_collections_List_1Tt_mx2_Toker_2* l_self,t_std_collections_List_1Tt_mx2_Toker_2* l_values);
extern void g_std_collections_List_1Tt_mx2_Toker_2_AddAll_1Tt_std_collections_Stack_1Tt_mx2_Toker_2_2(t_std_collections_List_1Tt_mx2_Toker_2* l_self,t_std_collections_Stack_1Tt_mx2_Toker_2* l_values);
extern void g_std_collections_List_1Tt_mx2_ParseEx_2_AddAll_1Tt_std_collections_List_1Tt_mx2_ParseEx_2_2(t_std_collections_List_1Tt_mx2_ParseEx_2* l_self,t_std_collections_List_1Tt_mx2_ParseEx_2* l_values);
extern void g_std_collections_List_1Tt_mx2_ParseEx_2_AddAll_1Tt_std_collections_Stack_1Tt_mx2_ParseEx_2_2(t_std_collections_List_1Tt_mx2_ParseEx_2* l_self,t_std_collections_Stack_1Tt_mx2_ParseEx_2* l_values);
extern void g_std_collections_List_1Tt_mx2_TypeExpr_2_AddAll_1Tt_std_collections_List_1Tt_mx2_TypeExpr_2_2(t_std_collections_List_1Tt_mx2_TypeExpr_2* l_self,t_std_collections_List_1Tt_mx2_TypeExpr_2* l_values);
extern void g_std_collections_List_1Tt_mx2_TypeExpr_2_AddAll_1Tt_std_collections_Stack_1Tt_mx2_TypeExpr_2_2(t_std_collections_List_1Tt_mx2_TypeExpr_2* l_self,t_std_collections_Stack_1Tt_mx2_TypeExpr_2* l_values);
extern void g_std_collections_List_1Tt_mx2_CatchExpr_2_AddAll_1Tt_std_collections_List_1Tt_mx2_CatchExpr_2_2(t_std_collections_List_1Tt_mx2_CatchExpr_2* l_self,t_std_collections_List_1Tt_mx2_CatchExpr_2* l_values);
extern void g_std_collections_List_1Tt_mx2_CatchExpr_2_AddAll_1Tt_std_collections_Stack_1Tt_mx2_CatchExpr_2_2(t_std_collections_List_1Tt_mx2_CatchExpr_2* l_self,t_std_collections_Stack_1Tt_mx2_CatchExpr_2* l_values);
extern void g_std_collections_List_1Tt_mx2_StmtExpr_2_AddAll_1Tt_std_collections_List_1Tt_mx2_StmtExpr_2_2(t_std_collections_List_1Tt_mx2_StmtExpr_2* l_self,t_std_collections_List_1Tt_mx2_StmtExpr_2* l_values);
extern void g_std_collections_List_1Tt_mx2_StmtExpr_2_AddAll_1Tt_std_collections_Stack_1Tt_mx2_StmtExpr_2_2(t_std_collections_List_1Tt_mx2_StmtExpr_2* l_self,t_std_collections_Stack_1Tt_mx2_StmtExpr_2* l_values);
extern void g_std_collections_List_1Tt_mx2_Expr_2_AddAll_1Tt_std_collections_List_1Tt_mx2_Expr_2_2(t_std_collections_List_1Tt_mx2_Expr_2* l_self,t_std_collections_List_1Tt_mx2_Expr_2* l_values);
extern void g_std_collections_List_1Tt_mx2_Expr_2_AddAll_1Tt_std_collections_Stack_1Tt_mx2_Expr_2_2(t_std_collections_List_1Tt_mx2_Expr_2* l_self,t_std_collections_Stack_1Tt_mx2_Expr_2* l_values);
extern void g_std_collections_List_1Tt_mx2_CaseExpr_2_AddAll_1Tt_std_collections_List_1Tt_mx2_CaseExpr_2_2(t_std_collections_List_1Tt_mx2_CaseExpr_2* l_self,t_std_collections_List_1Tt_mx2_CaseExpr_2* l_values);
extern void g_std_collections_List_1Tt_mx2_CaseExpr_2_AddAll_1Tt_std_collections_Stack_1Tt_mx2_CaseExpr_2_2(t_std_collections_List_1Tt_mx2_CaseExpr_2* l_self,t_std_collections_Stack_1Tt_mx2_CaseExpr_2* l_values);
extern void g_std_collections_List_1Tt_mx2_VarDecl_2_AddAll_1Tt_std_collections_List_1Tt_mx2_VarDecl_2_2(t_std_collections_List_1Tt_mx2_VarDecl_2* l_self,t_std_collections_List_1Tt_mx2_VarDecl_2* l_values);
extern void g_std_collections_List_1Tt_mx2_VarDecl_2_AddAll_1Tt_std_collections_Stack_1Tt_mx2_VarDecl_2_2(t_std_collections_List_1Tt_mx2_VarDecl_2* l_self,t_std_collections_Stack_1Tt_mx2_VarDecl_2* l_values);
extern void g_std_collections_List_1Tt_mx2_Decl_2_AddAll_1Tt_std_collections_List_1Tt_mx2_Decl_2_2(t_std_collections_List_1Tt_mx2_Decl_2* l_self,t_std_collections_List_1Tt_mx2_Decl_2* l_values);
extern void g_std_collections_List_1Tt_mx2_Decl_2_AddAll_1Tt_std_collections_Stack_1Tt_mx2_Decl_2_2(t_std_collections_List_1Tt_mx2_Decl_2* l_self,t_std_collections_Stack_1Tt_mx2_Decl_2* l_values);
extern void g_std_collections_List_1Tt_mx2_CatchStmt_2_AddAll_1Tt_std_collections_List_1Tt_mx2_CatchStmt_2_2(t_std_collections_List_1Tt_mx2_CatchStmt_2* l_self,t_std_collections_List_1Tt_mx2_CatchStmt_2* l_values);
extern void g_std_collections_List_1Tt_mx2_CatchStmt_2_AddAll_1Tt_std_collections_Stack_1Tt_mx2_CatchStmt_2_2(t_std_collections_List_1Tt_mx2_CatchStmt_2* l_self,t_std_collections_Stack_1Tt_mx2_CatchStmt_2* l_values);
extern void g_std_collections_List_1Tt_mx2_CaseStmt_2_AddAll_1Tt_std_collections_List_1Tt_mx2_CaseStmt_2_2(t_std_collections_List_1Tt_mx2_CaseStmt_2* l_self,t_std_collections_List_1Tt_mx2_CaseStmt_2* l_values);
extern void g_std_collections_List_1Tt_mx2_CaseStmt_2_AddAll_1Tt_std_collections_Stack_1Tt_mx2_CaseStmt_2_2(t_std_collections_List_1Tt_mx2_CaseStmt_2* l_self,t_std_collections_Stack_1Tt_mx2_CaseStmt_2* l_values);
extern void g_std_collections_List_1Tt_mx2_FuncListType_2_AddAll_1Tt_std_collections_List_1Tt_mx2_FuncListType_2_2(t_std_collections_List_1Tt_mx2_FuncListType_2* l_self,t_std_collections_List_1Tt_mx2_FuncListType_2* l_values);
extern void g_std_collections_List_1Tt_mx2_FuncListType_2_AddAll_1Tt_std_collections_Stack_1Tt_mx2_FuncListType_2_2(t_std_collections_List_1Tt_mx2_FuncListType_2* l_self,t_std_collections_Stack_1Tt_mx2_FuncListType_2* l_values);
extern void g_std_collections_List_1Tt_mx2_AliasType_2_AddAll_1Tt_std_collections_List_1Tt_mx2_AliasType_2_2(t_std_collections_List_1Tt_mx2_AliasType_2* l_self,t_std_collections_List_1Tt_mx2_AliasType_2* l_values);
extern void g_std_collections_List_1Tt_mx2_AliasType_2_AddAll_1Tt_std_collections_Stack_1Tt_mx2_AliasType_2_2(t_std_collections_List_1Tt_mx2_AliasType_2* l_self,t_std_collections_Stack_1Tt_mx2_AliasType_2* l_values);
extern void g_std_collections_List_1Tt_mx2_PNode_2_AddAll_1Tt_std_collections_List_1Tt_mx2_PNode_2_2(t_std_collections_List_1Tt_mx2_PNode_2* l_self,t_std_collections_List_1Tt_mx2_PNode_2* l_values);
extern void g_std_collections_List_1Tt_mx2_PNode_2_AddAll_1Tt_std_collections_Stack_1Tt_mx2_PNode_2_2(t_std_collections_List_1Tt_mx2_PNode_2* l_self,t_std_collections_Stack_1Tt_mx2_PNode_2* l_values);
extern void g_std_collections_List_1Tt_mx2_NamespaceScope_2_AddAll_1Tt_std_collections_List_1Tt_mx2_NamespaceScope_2_2(t_std_collections_List_1Tt_mx2_NamespaceScope_2* l_self,t_std_collections_List_1Tt_mx2_NamespaceScope_2* l_values);
extern void g_std_collections_List_1Tt_mx2_NamespaceScope_2_AddAll_1Tt_std_collections_Stack_1Tt_mx2_NamespaceScope_2_2(t_std_collections_List_1Tt_mx2_NamespaceScope_2* l_self,t_std_collections_Stack_1Tt_mx2_NamespaceScope_2* l_values);
extern void g_std_collections_List_1Tt_mx2_FileScope_2_AddAll_1Tt_std_collections_List_1Tt_mx2_FileScope_2_2(t_std_collections_List_1Tt_mx2_FileScope_2* l_self,t_std_collections_List_1Tt_mx2_FileScope_2* l_values);
extern void g_std_collections_List_1Tt_mx2_FileScope_2_AddAll_1Tt_std_collections_Stack_1Tt_mx2_FileScope_2_2(t_std_collections_List_1Tt_mx2_FileScope_2* l_self,t_std_collections_Stack_1Tt_mx2_FileScope_2* l_values);
extern void g_std_collections_List_1Tt_mx2_FileDecl_2_AddAll_1Tt_std_collections_List_1Tt_mx2_FileDecl_2_2(t_std_collections_List_1Tt_mx2_FileDecl_2* l_self,t_std_collections_List_1Tt_mx2_FileDecl_2* l_values);
extern void g_std_collections_List_1Tt_mx2_FileDecl_2_AddAll_1Tt_std_collections_Stack_1Tt_mx2_FileDecl_2_2(t_std_collections_List_1Tt_mx2_FileDecl_2* l_self,t_std_collections_Stack_1Tt_mx2_FileDecl_2* l_values);
extern void g_std_collections_List_1Tt_std_collections_Stack_1s_2_AddAll_1Tt_std_collections_List_1Tt_std_collections_Stack_1s_2_2(t_std_collections_List_1Tt_std_collections_Stack_1s_2* l_self,t_std_collections_List_1Tt_std_collections_Stack_1s_2* l_values);
extern void g_std_collections_List_1Tt_std_collections_Stack_1s_2_AddAll_1Tt_std_collections_Stack_1Tt_std_collections_Stack_1s_2_2(t_std_collections_List_1Tt_std_collections_Stack_1s_2* l_self,t_std_collections_Stack_1Tt_std_collections_Stack_1s_2* l_values);
extern void g_std_collections_List_1Tt_mx2_VarValue_2_AddAll_1Tt_std_collections_List_1Tt_mx2_VarValue_2_2(t_std_collections_List_1Tt_mx2_VarValue_2* l_self,t_std_collections_List_1Tt_mx2_VarValue_2* l_values);
extern void g_std_collections_List_1Tt_mx2_VarValue_2_AddAll_1Tt_std_collections_Stack_1Tt_mx2_VarValue_2_2(t_std_collections_List_1Tt_mx2_VarValue_2* l_self,t_std_collections_Stack_1Tt_mx2_VarValue_2* l_values);
extern void g_std_collections_List_1Tt_mx2_FuncList_2_AddAll_1Tt_std_collections_List_1Tt_mx2_FuncList_2_2(t_std_collections_List_1Tt_mx2_FuncList_2* l_self,t_std_collections_List_1Tt_mx2_FuncList_2* l_values);
extern void g_std_collections_List_1Tt_mx2_FuncList_2_AddAll_1Tt_std_collections_Stack_1Tt_mx2_FuncList_2_2(t_std_collections_List_1Tt_mx2_FuncList_2* l_self,t_std_collections_Stack_1Tt_mx2_FuncList_2* l_values);
extern void g_std_collections_List_1Tt_mx2_SNode_2_AddAll_1Tt_std_collections_List_1Tt_mx2_SNode_2_2(t_std_collections_List_1Tt_mx2_SNode_2* l_self,t_std_collections_List_1Tt_mx2_SNode_2* l_values);
extern void g_std_collections_List_1Tt_mx2_SNode_2_AddAll_1Tt_std_collections_Stack_1Tt_mx2_SNode_2_2(t_std_collections_List_1Tt_mx2_SNode_2* l_self,t_std_collections_Stack_1Tt_mx2_SNode_2* l_values);
extern void g_std_collections_List_1Tt_mx2_Scope_2_AddAll_1Tt_std_collections_List_1Tt_mx2_Scope_2_2(t_std_collections_List_1Tt_mx2_Scope_2* l_self,t_std_collections_List_1Tt_mx2_Scope_2* l_values);
extern void g_std_collections_List_1Tt_mx2_Scope_2_AddAll_1Tt_std_collections_Stack_1Tt_mx2_Scope_2_2(t_std_collections_List_1Tt_mx2_Scope_2* l_self,t_std_collections_Stack_1Tt_mx2_Scope_2* l_values);
extern void g_std_collections_List_1Tt_mx2_ClassType_2_AddAll_1Tt_std_collections_List_1Tt_mx2_ClassType_2_2(t_std_collections_List_1Tt_mx2_ClassType_2* l_self,t_std_collections_List_1Tt_mx2_ClassType_2* l_values);
extern void g_std_collections_List_1Tt_mx2_ClassType_2_AddAll_1Tt_std_collections_Stack_1Tt_mx2_ClassType_2_2(t_std_collections_List_1Tt_mx2_ClassType_2* l_self,t_std_collections_Stack_1Tt_mx2_ClassType_2* l_values);
extern void g_std_collections_List_1Tt_mx2_ErrorEx_2_AddAll_1Tt_std_collections_List_1Tt_mx2_ErrorEx_2_2(t_std_collections_List_1Tt_mx2_ErrorEx_2* l_self,t_std_collections_List_1Tt_mx2_ErrorEx_2* l_values);
extern void g_std_collections_List_1Tt_mx2_ErrorEx_2_AddAll_1Tt_std_collections_Stack_1Tt_mx2_ErrorEx_2_2(t_std_collections_List_1Tt_mx2_ErrorEx_2* l_self,t_std_collections_Stack_1Tt_mx2_ErrorEx_2* l_values);
extern void g_std_collections_List_1Tt_mx2_Module_2_AddAll_1Tt_std_collections_List_1Tt_mx2_Module_2_2(t_std_collections_List_1Tt_mx2_Module_2* l_self,t_std_collections_List_1Tt_mx2_Module_2* l_values);
extern void g_std_collections_List_1Tt_mx2_Module_2_AddAll_1Tt_std_collections_Stack_1Tt_mx2_Module_2_2(t_std_collections_List_1Tt_mx2_Module_2* l_self,t_std_collections_Stack_1Tt_mx2_Module_2* l_values);
extern void g_std_collections_List_1Tt_mx2_FuncValue_2_AddAll_1Tt_std_collections_List_1Tt_mx2_FuncValue_2_2(t_std_collections_List_1Tt_mx2_FuncValue_2* l_self,t_std_collections_List_1Tt_mx2_FuncValue_2* l_values);
extern void g_std_collections_List_1Tt_mx2_FuncValue_2_AddAll_1Tt_std_collections_Stack_1Tt_mx2_FuncValue_2_2(t_std_collections_List_1Tt_mx2_FuncValue_2* l_self,t_std_collections_Stack_1Tt_mx2_FuncValue_2* l_values);

struct t_std_collections_List_1Tt_mx2_FuncValue_2_Node : public bbObject{

  const char *typeName()const{return "t_std_collections_List_1Tt_mx2_FuncValue_2_Node";}

  bbGCVar<t_std_collections_List_1Tt_mx2_FuncValue_2_Node> m__0succ{};
  bbGCVar<t_std_collections_List_1Tt_mx2_FuncValue_2_Node> m__0pred{};
  bbGCVar<t_mx2_FuncValue> m__0value{};

  void gcMark();

  t_std_collections_List_1Tt_mx2_FuncValue_2_Node(t_mx2_FuncValue* l_value,t_std_collections_List_1Tt_mx2_FuncValue_2_Node* l_succ);
  t_std_collections_List_1Tt_mx2_FuncValue_2_Node(t_mx2_FuncValue* l_value);

  void m_Value(t_mx2_FuncValue* l_value);
  t_mx2_FuncValue* m_Value();
  t_std_collections_List_1Tt_mx2_FuncValue_2_Node* m_Succ();
  void m_Remove();
  t_std_collections_List_1Tt_mx2_FuncValue_2_Node* m_Pred();
  void m_InsertBefore(t_std_collections_List_1Tt_mx2_FuncValue_2_Node* l_node);
  void m_InsertAfter(t_std_collections_List_1Tt_mx2_FuncValue_2_Node* l_node);

  t_std_collections_List_1Tt_mx2_FuncValue_2_Node(){
  }
};

struct t_std_collections_List_1Tt_mx2_FuncValue_2_Iterator{
  const char *typeName()const{return "t_std_collections_List_1Tt_mx2_FuncValue_2_Iterator";}

  bbGCVar<t_std_collections_List_1Tt_mx2_FuncValue_2> m__0list{};
  bbGCVar<t_std_collections_List_1Tt_mx2_FuncValue_2_Node> m__0node{};
  bbInt m__0seq{};

  t_std_collections_List_1Tt_mx2_FuncValue_2_Iterator(t_std_collections_List_1Tt_mx2_FuncValue_2* l_list,t_std_collections_List_1Tt_mx2_FuncValue_2_Node* l_node);

  void m_Insert(t_mx2_FuncValue* l_value);
  void m_Erase();
  void m_Current(t_mx2_FuncValue* l_current);
  t_mx2_FuncValue* m_Current();
  void m_Bump();
  bbBool m_AtEnd();
  void m_AssertSeq();
  void m_AssertCurrent();

  t_std_collections_List_1Tt_mx2_FuncValue_2_Iterator(){
  }

  t_std_collections_List_1Tt_mx2_FuncValue_2_Iterator(bbNullCtor_t){
  }
};

int bbCompare(const t_std_collections_List_1Tt_mx2_FuncValue_2_Iterator&x,const t_std_collections_List_1Tt_mx2_FuncValue_2_Iterator&y);

void bbGCMark(const t_std_collections_List_1Tt_mx2_FuncValue_2_Iterator&);

struct t_std_collections_List_1Tt_mx2_FuncValue_2_BackwardsIterator{
  const char *typeName()const{return "t_std_collections_List_1Tt_mx2_FuncValue_2_BackwardsIterator";}

  bbGCVar<t_std_collections_List_1Tt_mx2_FuncValue_2> m__0list{};
  bbGCVar<t_std_collections_List_1Tt_mx2_FuncValue_2_Node> m__0node{};
  bbInt m__0seq{};

  t_std_collections_List_1Tt_mx2_FuncValue_2_BackwardsIterator(t_std_collections_List_1Tt_mx2_FuncValue_2* l_list,t_std_collections_List_1Tt_mx2_FuncValue_2_Node* l_node);

  void m_Insert(t_mx2_FuncValue* l_value);
  void m_Erase();
  void m_Current(t_mx2_FuncValue* l_current);
  t_mx2_FuncValue* m_Current();
  void m_Bump();
  bbBool m_AtEnd();
  void m_AssertSeq();
  void m_AssertCurrent();

  t_std_collections_List_1Tt_mx2_FuncValue_2_BackwardsIterator(){
  }

  t_std_collections_List_1Tt_mx2_FuncValue_2_BackwardsIterator(bbNullCtor_t){
  }
};

int bbCompare(const t_std_collections_List_1Tt_mx2_FuncValue_2_BackwardsIterator&x,const t_std_collections_List_1Tt_mx2_FuncValue_2_BackwardsIterator&y);

void bbGCMark(const t_std_collections_List_1Tt_mx2_FuncValue_2_BackwardsIterator&);

struct t_std_collections_List_1Tt_mx2_FuncValue_2 : public bbObject,public virtual t_std_collections_IContainer_1Tt_mx2_FuncValue_2{

  const char *typeName()const{return "t_std_collections_List_1Tt_mx2_FuncValue_2";}

  bbGCVar<t_std_collections_List_1Tt_mx2_FuncValue_2_Node> m__0head{};
  bbInt m__0seq{};

  void gcMark();

  t_std_collections_List_1Tt_mx2_FuncValue_2(t_std_collections_List_1Tt_mx2_FuncValue_2* l_values);
  t_std_collections_List_1Tt_mx2_FuncValue_2(t_std_collections_Stack_1Tt_mx2_FuncValue_2* l_values);
  t_std_collections_List_1Tt_mx2_FuncValue_2(bbArray<bbGCVar<t_mx2_FuncValue>>* l_values);
  t_std_collections_List_1Tt_mx2_FuncValue_2();

  bbArray<bbGCVar<t_mx2_FuncValue>>* m_ToArray();
  void m_Sort(bbFunction<bbInt(t_mx2_FuncValue*,t_mx2_FuncValue*)> l_compareFunc);
  void m_Sort(bbBool l_ascending);
  t_mx2_FuncValue* m_RemoveLast();
  bbBool m_RemoveLast(t_mx2_FuncValue* l_value);
  t_mx2_FuncValue* m_RemoveFirst();
  bbInt m_RemoveEach(t_mx2_FuncValue* l_value);
  bbBool m_Remove(t_mx2_FuncValue* l_value);
  t_std_collections_List_1Tt_mx2_FuncValue_2_Node* m_LastNode();
  t_mx2_FuncValue* m_Last();
  t_std_collections_List_1Tt_mx2_FuncValue_2_Node* m_HeadNode();
  t_std_collections_List_1Tt_mx2_FuncValue_2_Node* m_FirstNode();
  t_mx2_FuncValue* m_First();
  t_std_collections_List_1Tt_mx2_FuncValue_2_Node* m_FindNode(t_mx2_FuncValue* l_value);
  t_std_collections_List_1Tt_mx2_FuncValue_2_Node* m_FindLastNode(t_mx2_FuncValue* l_value);
  bbBool m_Empty();
  bbInt m_Count();
  void m_Clear();
  t_std_collections_List_1Tt_mx2_FuncValue_2_BackwardsIterator m_Backwards();
  t_std_collections_List_1Tt_mx2_FuncValue_2_Iterator m_All();
  t_std_collections_List_1Tt_mx2_FuncValue_2_Node* m_AddLast(t_mx2_FuncValue* l_value);
  t_std_collections_List_1Tt_mx2_FuncValue_2_Node* m_AddFirst(t_mx2_FuncValue* l_value);
  void m_AddAll(bbArray<bbGCVar<t_mx2_FuncValue>>* l_values);
  void m_Add(t_mx2_FuncValue* l_value);
};

struct t_std_collections_List_1Tt_mx2_Module_2_Node : public bbObject{

  const char *typeName()const{return "t_std_collections_List_1Tt_mx2_Module_2_Node";}

  bbGCVar<t_std_collections_List_1Tt_mx2_Module_2_Node> m__0succ{};
  bbGCVar<t_std_collections_List_1Tt_mx2_Module_2_Node> m__0pred{};
  bbGCVar<t_mx2_Module> m__0value{};

  void gcMark();

  t_std_collections_List_1Tt_mx2_Module_2_Node(t_mx2_Module* l_value,t_std_collections_List_1Tt_mx2_Module_2_Node* l_succ);
  t_std_collections_List_1Tt_mx2_Module_2_Node(t_mx2_Module* l_value);

  void m_Value(t_mx2_Module* l_value);
  t_mx2_Module* m_Value();
  t_std_collections_List_1Tt_mx2_Module_2_Node* m_Succ();
  void m_Remove();
  t_std_collections_List_1Tt_mx2_Module_2_Node* m_Pred();
  void m_InsertBefore(t_std_collections_List_1Tt_mx2_Module_2_Node* l_node);
  void m_InsertAfter(t_std_collections_List_1Tt_mx2_Module_2_Node* l_node);

  t_std_collections_List_1Tt_mx2_Module_2_Node(){
  }
};

struct t_std_collections_List_1Tt_mx2_Module_2_Iterator{
  const char *typeName()const{return "t_std_collections_List_1Tt_mx2_Module_2_Iterator";}

  bbGCVar<t_std_collections_List_1Tt_mx2_Module_2> m__0list{};
  bbGCVar<t_std_collections_List_1Tt_mx2_Module_2_Node> m__0node{};
  bbInt m__0seq{};

  t_std_collections_List_1Tt_mx2_Module_2_Iterator(t_std_collections_List_1Tt_mx2_Module_2* l_list,t_std_collections_List_1Tt_mx2_Module_2_Node* l_node);

  void m_Insert(t_mx2_Module* l_value);
  void m_Erase();
  void m_Current(t_mx2_Module* l_current);
  t_mx2_Module* m_Current();
  void m_Bump();
  bbBool m_AtEnd();
  void m_AssertSeq();
  void m_AssertCurrent();

  t_std_collections_List_1Tt_mx2_Module_2_Iterator(){
  }

  t_std_collections_List_1Tt_mx2_Module_2_Iterator(bbNullCtor_t){
  }
};

int bbCompare(const t_std_collections_List_1Tt_mx2_Module_2_Iterator&x,const t_std_collections_List_1Tt_mx2_Module_2_Iterator&y);

void bbGCMark(const t_std_collections_List_1Tt_mx2_Module_2_Iterator&);

struct t_std_collections_List_1Tt_mx2_Module_2_BackwardsIterator{
  const char *typeName()const{return "t_std_collections_List_1Tt_mx2_Module_2_BackwardsIterator";}

  bbGCVar<t_std_collections_List_1Tt_mx2_Module_2> m__0list{};
  bbGCVar<t_std_collections_List_1Tt_mx2_Module_2_Node> m__0node{};
  bbInt m__0seq{};

  t_std_collections_List_1Tt_mx2_Module_2_BackwardsIterator(t_std_collections_List_1Tt_mx2_Module_2* l_list,t_std_collections_List_1Tt_mx2_Module_2_Node* l_node);

  void m_Insert(t_mx2_Module* l_value);
  void m_Erase();
  void m_Current(t_mx2_Module* l_current);
  t_mx2_Module* m_Current();
  void m_Bump();
  bbBool m_AtEnd();
  void m_AssertSeq();
  void m_AssertCurrent();

  t_std_collections_List_1Tt_mx2_Module_2_BackwardsIterator(){
  }

  t_std_collections_List_1Tt_mx2_Module_2_BackwardsIterator(bbNullCtor_t){
  }
};

int bbCompare(const t_std_collections_List_1Tt_mx2_Module_2_BackwardsIterator&x,const t_std_collections_List_1Tt_mx2_Module_2_BackwardsIterator&y);

void bbGCMark(const t_std_collections_List_1Tt_mx2_Module_2_BackwardsIterator&);

struct t_std_collections_List_1Tt_mx2_Module_2 : public bbObject,public virtual t_std_collections_IContainer_1Tt_mx2_Module_2{

  const char *typeName()const{return "t_std_collections_List_1Tt_mx2_Module_2";}

  bbGCVar<t_std_collections_List_1Tt_mx2_Module_2_Node> m__0head{};
  bbInt m__0seq{};

  void gcMark();

  t_std_collections_List_1Tt_mx2_Module_2(t_std_collections_List_1Tt_mx2_Module_2* l_values);
  t_std_collections_List_1Tt_mx2_Module_2(t_std_collections_Stack_1Tt_mx2_Module_2* l_values);
  t_std_collections_List_1Tt_mx2_Module_2(bbArray<bbGCVar<t_mx2_Module>>* l_values);
  t_std_collections_List_1Tt_mx2_Module_2();

  bbArray<bbGCVar<t_mx2_Module>>* m_ToArray();
  void m_Sort(bbFunction<bbInt(t_mx2_Module*,t_mx2_Module*)> l_compareFunc);
  void m_Sort(bbBool l_ascending);
  t_mx2_Module* m_RemoveLast();
  bbBool m_RemoveLast(t_mx2_Module* l_value);
  t_mx2_Module* m_RemoveFirst();
  bbInt m_RemoveEach(t_mx2_Module* l_value);
  bbBool m_Remove(t_mx2_Module* l_value);
  t_std_collections_List_1Tt_mx2_Module_2_Node* m_LastNode();
  t_mx2_Module* m_Last();
  t_std_collections_List_1Tt_mx2_Module_2_Node* m_HeadNode();
  t_std_collections_List_1Tt_mx2_Module_2_Node* m_FirstNode();
  t_mx2_Module* m_First();
  t_std_collections_List_1Tt_mx2_Module_2_Node* m_FindNode(t_mx2_Module* l_value);
  t_std_collections_List_1Tt_mx2_Module_2_Node* m_FindLastNode(t_mx2_Module* l_value);
  bbBool m_Empty();
  bbInt m_Count();
  void m_Clear();
  t_std_collections_List_1Tt_mx2_Module_2_BackwardsIterator m_Backwards();
  t_std_collections_List_1Tt_mx2_Module_2_Iterator m_All();
  t_std_collections_List_1Tt_mx2_Module_2_Node* m_AddLast(t_mx2_Module* l_value);
  t_std_collections_List_1Tt_mx2_Module_2_Node* m_AddFirst(t_mx2_Module* l_value);
  void m_AddAll(bbArray<bbGCVar<t_mx2_Module>>* l_values);
  void m_Add(t_mx2_Module* l_value);
};

struct t_std_collections_List_1Tt_mx2_ErrorEx_2_Node : public bbObject{

  const char *typeName()const{return "t_std_collections_List_1Tt_mx2_ErrorEx_2_Node";}

  bbGCVar<t_std_collections_List_1Tt_mx2_ErrorEx_2_Node> m__0succ{};
  bbGCVar<t_std_collections_List_1Tt_mx2_ErrorEx_2_Node> m__0pred{};
  bbGCVar<t_mx2_ErrorEx> m__0value{};

  void gcMark();

  t_std_collections_List_1Tt_mx2_ErrorEx_2_Node(t_mx2_ErrorEx* l_value,t_std_collections_List_1Tt_mx2_ErrorEx_2_Node* l_succ);
  t_std_collections_List_1Tt_mx2_ErrorEx_2_Node(t_mx2_ErrorEx* l_value);

  void m_Value(t_mx2_ErrorEx* l_value);
  t_mx2_ErrorEx* m_Value();
  t_std_collections_List_1Tt_mx2_ErrorEx_2_Node* m_Succ();
  void m_Remove();
  t_std_collections_List_1Tt_mx2_ErrorEx_2_Node* m_Pred();
  void m_InsertBefore(t_std_collections_List_1Tt_mx2_ErrorEx_2_Node* l_node);
  void m_InsertAfter(t_std_collections_List_1Tt_mx2_ErrorEx_2_Node* l_node);

  t_std_collections_List_1Tt_mx2_ErrorEx_2_Node(){
  }
};

struct t_std_collections_List_1Tt_mx2_ErrorEx_2_Iterator{
  const char *typeName()const{return "t_std_collections_List_1Tt_mx2_ErrorEx_2_Iterator";}

  bbGCVar<t_std_collections_List_1Tt_mx2_ErrorEx_2> m__0list{};
  bbGCVar<t_std_collections_List_1Tt_mx2_ErrorEx_2_Node> m__0node{};
  bbInt m__0seq{};

  t_std_collections_List_1Tt_mx2_ErrorEx_2_Iterator(t_std_collections_List_1Tt_mx2_ErrorEx_2* l_list,t_std_collections_List_1Tt_mx2_ErrorEx_2_Node* l_node);

  void m_Insert(t_mx2_ErrorEx* l_value);
  void m_Erase();
  void m_Current(t_mx2_ErrorEx* l_current);
  t_mx2_ErrorEx* m_Current();
  void m_Bump();
  bbBool m_AtEnd();
  void m_AssertSeq();
  void m_AssertCurrent();

  t_std_collections_List_1Tt_mx2_ErrorEx_2_Iterator(){
  }

  t_std_collections_List_1Tt_mx2_ErrorEx_2_Iterator(bbNullCtor_t){
  }
};

int bbCompare(const t_std_collections_List_1Tt_mx2_ErrorEx_2_Iterator&x,const t_std_collections_List_1Tt_mx2_ErrorEx_2_Iterator&y);

void bbGCMark(const t_std_collections_List_1Tt_mx2_ErrorEx_2_Iterator&);

struct t_std_collections_List_1Tt_mx2_ErrorEx_2_BackwardsIterator{
  const char *typeName()const{return "t_std_collections_List_1Tt_mx2_ErrorEx_2_BackwardsIterator";}

  bbGCVar<t_std_collections_List_1Tt_mx2_ErrorEx_2> m__0list{};
  bbGCVar<t_std_collections_List_1Tt_mx2_ErrorEx_2_Node> m__0node{};
  bbInt m__0seq{};

  t_std_collections_List_1Tt_mx2_ErrorEx_2_BackwardsIterator(t_std_collections_List_1Tt_mx2_ErrorEx_2* l_list,t_std_collections_List_1Tt_mx2_ErrorEx_2_Node* l_node);

  void m_Insert(t_mx2_ErrorEx* l_value);
  void m_Erase();
  void m_Current(t_mx2_ErrorEx* l_current);
  t_mx2_ErrorEx* m_Current();
  void m_Bump();
  bbBool m_AtEnd();
  void m_AssertSeq();
  void m_AssertCurrent();

  t_std_collections_List_1Tt_mx2_ErrorEx_2_BackwardsIterator(){
  }

  t_std_collections_List_1Tt_mx2_ErrorEx_2_BackwardsIterator(bbNullCtor_t){
  }
};

int bbCompare(const t_std_collections_List_1Tt_mx2_ErrorEx_2_BackwardsIterator&x,const t_std_collections_List_1Tt_mx2_ErrorEx_2_BackwardsIterator&y);

void bbGCMark(const t_std_collections_List_1Tt_mx2_ErrorEx_2_BackwardsIterator&);

struct t_std_collections_List_1Tt_mx2_ErrorEx_2 : public bbObject,public virtual t_std_collections_IContainer_1Tt_mx2_ErrorEx_2{

  const char *typeName()const{return "t_std_collections_List_1Tt_mx2_ErrorEx_2";}

  bbGCVar<t_std_collections_List_1Tt_mx2_ErrorEx_2_Node> m__0head{};
  bbInt m__0seq{};

  void gcMark();

  t_std_collections_List_1Tt_mx2_ErrorEx_2(t_std_collections_List_1Tt_mx2_ErrorEx_2* l_values);
  t_std_collections_List_1Tt_mx2_ErrorEx_2(t_std_collections_Stack_1Tt_mx2_ErrorEx_2* l_values);
  t_std_collections_List_1Tt_mx2_ErrorEx_2(bbArray<bbGCVar<t_mx2_ErrorEx>>* l_values);
  t_std_collections_List_1Tt_mx2_ErrorEx_2();

  bbArray<bbGCVar<t_mx2_ErrorEx>>* m_ToArray();
  void m_Sort(bbFunction<bbInt(t_mx2_ErrorEx*,t_mx2_ErrorEx*)> l_compareFunc);
  void m_Sort(bbBool l_ascending);
  t_mx2_ErrorEx* m_RemoveLast();
  bbBool m_RemoveLast(t_mx2_ErrorEx* l_value);
  t_mx2_ErrorEx* m_RemoveFirst();
  bbInt m_RemoveEach(t_mx2_ErrorEx* l_value);
  bbBool m_Remove(t_mx2_ErrorEx* l_value);
  t_std_collections_List_1Tt_mx2_ErrorEx_2_Node* m_LastNode();
  t_mx2_ErrorEx* m_Last();
  t_std_collections_List_1Tt_mx2_ErrorEx_2_Node* m_HeadNode();
  t_std_collections_List_1Tt_mx2_ErrorEx_2_Node* m_FirstNode();
  t_mx2_ErrorEx* m_First();
  t_std_collections_List_1Tt_mx2_ErrorEx_2_Node* m_FindNode(t_mx2_ErrorEx* l_value);
  t_std_collections_List_1Tt_mx2_ErrorEx_2_Node* m_FindLastNode(t_mx2_ErrorEx* l_value);
  bbBool m_Empty();
  bbInt m_Count();
  void m_Clear();
  t_std_collections_List_1Tt_mx2_ErrorEx_2_BackwardsIterator m_Backwards();
  t_std_collections_List_1Tt_mx2_ErrorEx_2_Iterator m_All();
  t_std_collections_List_1Tt_mx2_ErrorEx_2_Node* m_AddLast(t_mx2_ErrorEx* l_value);
  t_std_collections_List_1Tt_mx2_ErrorEx_2_Node* m_AddFirst(t_mx2_ErrorEx* l_value);
  void m_AddAll(bbArray<bbGCVar<t_mx2_ErrorEx>>* l_values);
  void m_Add(t_mx2_ErrorEx* l_value);
};

struct t_std_collections_List_1Tt_mx2_ClassType_2_Node : public bbObject{

  const char *typeName()const{return "t_std_collections_List_1Tt_mx2_ClassType_2_Node";}

  bbGCVar<t_std_collections_List_1Tt_mx2_ClassType_2_Node> m__0succ{};
  bbGCVar<t_std_collections_List_1Tt_mx2_ClassType_2_Node> m__0pred{};
  bbGCVar<t_mx2_ClassType> m__0value{};

  void gcMark();

  t_std_collections_List_1Tt_mx2_ClassType_2_Node(t_mx2_ClassType* l_value,t_std_collections_List_1Tt_mx2_ClassType_2_Node* l_succ);
  t_std_collections_List_1Tt_mx2_ClassType_2_Node(t_mx2_ClassType* l_value);

  void m_Value(t_mx2_ClassType* l_value);
  t_mx2_ClassType* m_Value();
  t_std_collections_List_1Tt_mx2_ClassType_2_Node* m_Succ();
  void m_Remove();
  t_std_collections_List_1Tt_mx2_ClassType_2_Node* m_Pred();
  void m_InsertBefore(t_std_collections_List_1Tt_mx2_ClassType_2_Node* l_node);
  void m_InsertAfter(t_std_collections_List_1Tt_mx2_ClassType_2_Node* l_node);

  t_std_collections_List_1Tt_mx2_ClassType_2_Node(){
  }
};

struct t_std_collections_List_1Tt_mx2_ClassType_2_Iterator{
  const char *typeName()const{return "t_std_collections_List_1Tt_mx2_ClassType_2_Iterator";}

  bbGCVar<t_std_collections_List_1Tt_mx2_ClassType_2> m__0list{};
  bbGCVar<t_std_collections_List_1Tt_mx2_ClassType_2_Node> m__0node{};
  bbInt m__0seq{};

  t_std_collections_List_1Tt_mx2_ClassType_2_Iterator(t_std_collections_List_1Tt_mx2_ClassType_2* l_list,t_std_collections_List_1Tt_mx2_ClassType_2_Node* l_node);

  void m_Insert(t_mx2_ClassType* l_value);
  void m_Erase();
  void m_Current(t_mx2_ClassType* l_current);
  t_mx2_ClassType* m_Current();
  void m_Bump();
  bbBool m_AtEnd();
  void m_AssertSeq();
  void m_AssertCurrent();

  t_std_collections_List_1Tt_mx2_ClassType_2_Iterator(){
  }

  t_std_collections_List_1Tt_mx2_ClassType_2_Iterator(bbNullCtor_t){
  }
};

int bbCompare(const t_std_collections_List_1Tt_mx2_ClassType_2_Iterator&x,const t_std_collections_List_1Tt_mx2_ClassType_2_Iterator&y);

void bbGCMark(const t_std_collections_List_1Tt_mx2_ClassType_2_Iterator&);

struct t_std_collections_List_1Tt_mx2_ClassType_2_BackwardsIterator{
  const char *typeName()const{return "t_std_collections_List_1Tt_mx2_ClassType_2_BackwardsIterator";}

  bbGCVar<t_std_collections_List_1Tt_mx2_ClassType_2> m__0list{};
  bbGCVar<t_std_collections_List_1Tt_mx2_ClassType_2_Node> m__0node{};
  bbInt m__0seq{};

  t_std_collections_List_1Tt_mx2_ClassType_2_BackwardsIterator(t_std_collections_List_1Tt_mx2_ClassType_2* l_list,t_std_collections_List_1Tt_mx2_ClassType_2_Node* l_node);

  void m_Insert(t_mx2_ClassType* l_value);
  void m_Erase();
  void m_Current(t_mx2_ClassType* l_current);
  t_mx2_ClassType* m_Current();
  void m_Bump();
  bbBool m_AtEnd();
  void m_AssertSeq();
  void m_AssertCurrent();

  t_std_collections_List_1Tt_mx2_ClassType_2_BackwardsIterator(){
  }

  t_std_collections_List_1Tt_mx2_ClassType_2_BackwardsIterator(bbNullCtor_t){
  }
};

int bbCompare(const t_std_collections_List_1Tt_mx2_ClassType_2_BackwardsIterator&x,const t_std_collections_List_1Tt_mx2_ClassType_2_BackwardsIterator&y);

void bbGCMark(const t_std_collections_List_1Tt_mx2_ClassType_2_BackwardsIterator&);

struct t_std_collections_List_1Tt_mx2_ClassType_2 : public bbObject,public virtual t_std_collections_IContainer_1Tt_mx2_ClassType_2{

  const char *typeName()const{return "t_std_collections_List_1Tt_mx2_ClassType_2";}

  bbGCVar<t_std_collections_List_1Tt_mx2_ClassType_2_Node> m__0head{};
  bbInt m__0seq{};

  void gcMark();

  t_std_collections_List_1Tt_mx2_ClassType_2(t_std_collections_List_1Tt_mx2_ClassType_2* l_values);
  t_std_collections_List_1Tt_mx2_ClassType_2(t_std_collections_Stack_1Tt_mx2_ClassType_2* l_values);
  t_std_collections_List_1Tt_mx2_ClassType_2(bbArray<bbGCVar<t_mx2_ClassType>>* l_values);
  t_std_collections_List_1Tt_mx2_ClassType_2();

  bbArray<bbGCVar<t_mx2_ClassType>>* m_ToArray();
  void m_Sort(bbFunction<bbInt(t_mx2_ClassType*,t_mx2_ClassType*)> l_compareFunc);
  void m_Sort(bbBool l_ascending);
  t_mx2_ClassType* m_RemoveLast();
  bbBool m_RemoveLast(t_mx2_ClassType* l_value);
  t_mx2_ClassType* m_RemoveFirst();
  bbInt m_RemoveEach(t_mx2_ClassType* l_value);
  bbBool m_Remove(t_mx2_ClassType* l_value);
  t_std_collections_List_1Tt_mx2_ClassType_2_Node* m_LastNode();
  t_mx2_ClassType* m_Last();
  t_std_collections_List_1Tt_mx2_ClassType_2_Node* m_HeadNode();
  t_std_collections_List_1Tt_mx2_ClassType_2_Node* m_FirstNode();
  t_mx2_ClassType* m_First();
  t_std_collections_List_1Tt_mx2_ClassType_2_Node* m_FindNode(t_mx2_ClassType* l_value);
  t_std_collections_List_1Tt_mx2_ClassType_2_Node* m_FindLastNode(t_mx2_ClassType* l_value);
  bbBool m_Empty();
  bbInt m_Count();
  void m_Clear();
  t_std_collections_List_1Tt_mx2_ClassType_2_BackwardsIterator m_Backwards();
  t_std_collections_List_1Tt_mx2_ClassType_2_Iterator m_All();
  t_std_collections_List_1Tt_mx2_ClassType_2_Node* m_AddLast(t_mx2_ClassType* l_value);
  t_std_collections_List_1Tt_mx2_ClassType_2_Node* m_AddFirst(t_mx2_ClassType* l_value);
  void m_AddAll(bbArray<bbGCVar<t_mx2_ClassType>>* l_values);
  void m_Add(t_mx2_ClassType* l_value);
};

struct t_std_collections_List_1Tt_mx2_Scope_2_Node : public bbObject{

  const char *typeName()const{return "t_std_collections_List_1Tt_mx2_Scope_2_Node";}

  bbGCVar<t_std_collections_List_1Tt_mx2_Scope_2_Node> m__0succ{};
  bbGCVar<t_std_collections_List_1Tt_mx2_Scope_2_Node> m__0pred{};
  bbGCVar<t_mx2_Scope> m__0value{};

  void gcMark();

  t_std_collections_List_1Tt_mx2_Scope_2_Node(t_mx2_Scope* l_value,t_std_collections_List_1Tt_mx2_Scope_2_Node* l_succ);
  t_std_collections_List_1Tt_mx2_Scope_2_Node(t_mx2_Scope* l_value);

  void m_Value(t_mx2_Scope* l_value);
  t_mx2_Scope* m_Value();
  t_std_collections_List_1Tt_mx2_Scope_2_Node* m_Succ();
  void m_Remove();
  t_std_collections_List_1Tt_mx2_Scope_2_Node* m_Pred();
  void m_InsertBefore(t_std_collections_List_1Tt_mx2_Scope_2_Node* l_node);
  void m_InsertAfter(t_std_collections_List_1Tt_mx2_Scope_2_Node* l_node);

  t_std_collections_List_1Tt_mx2_Scope_2_Node(){
  }
};

struct t_std_collections_List_1Tt_mx2_Scope_2_Iterator{
  const char *typeName()const{return "t_std_collections_List_1Tt_mx2_Scope_2_Iterator";}

  bbGCVar<t_std_collections_List_1Tt_mx2_Scope_2> m__0list{};
  bbGCVar<t_std_collections_List_1Tt_mx2_Scope_2_Node> m__0node{};
  bbInt m__0seq{};

  t_std_collections_List_1Tt_mx2_Scope_2_Iterator(t_std_collections_List_1Tt_mx2_Scope_2* l_list,t_std_collections_List_1Tt_mx2_Scope_2_Node* l_node);

  void m_Insert(t_mx2_Scope* l_value);
  void m_Erase();
  void m_Current(t_mx2_Scope* l_current);
  t_mx2_Scope* m_Current();
  void m_Bump();
  bbBool m_AtEnd();
  void m_AssertSeq();
  void m_AssertCurrent();

  t_std_collections_List_1Tt_mx2_Scope_2_Iterator(){
  }

  t_std_collections_List_1Tt_mx2_Scope_2_Iterator(bbNullCtor_t){
  }
};

int bbCompare(const t_std_collections_List_1Tt_mx2_Scope_2_Iterator&x,const t_std_collections_List_1Tt_mx2_Scope_2_Iterator&y);

void bbGCMark(const t_std_collections_List_1Tt_mx2_Scope_2_Iterator&);

struct t_std_collections_List_1Tt_mx2_Scope_2_BackwardsIterator{
  const char *typeName()const{return "t_std_collections_List_1Tt_mx2_Scope_2_BackwardsIterator";}

  bbGCVar<t_std_collections_List_1Tt_mx2_Scope_2> m__0list{};
  bbGCVar<t_std_collections_List_1Tt_mx2_Scope_2_Node> m__0node{};
  bbInt m__0seq{};

  t_std_collections_List_1Tt_mx2_Scope_2_BackwardsIterator(t_std_collections_List_1Tt_mx2_Scope_2* l_list,t_std_collections_List_1Tt_mx2_Scope_2_Node* l_node);

  void m_Insert(t_mx2_Scope* l_value);
  void m_Erase();
  void m_Current(t_mx2_Scope* l_current);
  t_mx2_Scope* m_Current();
  void m_Bump();
  bbBool m_AtEnd();
  void m_AssertSeq();
  void m_AssertCurrent();

  t_std_collections_List_1Tt_mx2_Scope_2_BackwardsIterator(){
  }

  t_std_collections_List_1Tt_mx2_Scope_2_BackwardsIterator(bbNullCtor_t){
  }
};

int bbCompare(const t_std_collections_List_1Tt_mx2_Scope_2_BackwardsIterator&x,const t_std_collections_List_1Tt_mx2_Scope_2_BackwardsIterator&y);

void bbGCMark(const t_std_collections_List_1Tt_mx2_Scope_2_BackwardsIterator&);

struct t_std_collections_List_1Tt_mx2_Scope_2 : public bbObject,public virtual t_std_collections_IContainer_1Tt_mx2_Scope_2{

  const char *typeName()const{return "t_std_collections_List_1Tt_mx2_Scope_2";}

  bbGCVar<t_std_collections_List_1Tt_mx2_Scope_2_Node> m__0head{};
  bbInt m__0seq{};

  void gcMark();

  t_std_collections_List_1Tt_mx2_Scope_2(t_std_collections_List_1Tt_mx2_Scope_2* l_values);
  t_std_collections_List_1Tt_mx2_Scope_2(t_std_collections_Stack_1Tt_mx2_Scope_2* l_values);
  t_std_collections_List_1Tt_mx2_Scope_2(bbArray<bbGCVar<t_mx2_Scope>>* l_values);
  t_std_collections_List_1Tt_mx2_Scope_2();

  bbArray<bbGCVar<t_mx2_Scope>>* m_ToArray();
  void m_Sort(bbFunction<bbInt(t_mx2_Scope*,t_mx2_Scope*)> l_compareFunc);
  void m_Sort(bbBool l_ascending);
  t_mx2_Scope* m_RemoveLast();
  bbBool m_RemoveLast(t_mx2_Scope* l_value);
  t_mx2_Scope* m_RemoveFirst();
  bbInt m_RemoveEach(t_mx2_Scope* l_value);
  bbBool m_Remove(t_mx2_Scope* l_value);
  t_std_collections_List_1Tt_mx2_Scope_2_Node* m_LastNode();
  t_mx2_Scope* m_Last();
  t_std_collections_List_1Tt_mx2_Scope_2_Node* m_HeadNode();
  t_std_collections_List_1Tt_mx2_Scope_2_Node* m_FirstNode();
  t_mx2_Scope* m_First();
  t_std_collections_List_1Tt_mx2_Scope_2_Node* m_FindNode(t_mx2_Scope* l_value);
  t_std_collections_List_1Tt_mx2_Scope_2_Node* m_FindLastNode(t_mx2_Scope* l_value);
  bbBool m_Empty();
  bbInt m_Count();
  void m_Clear();
  t_std_collections_List_1Tt_mx2_Scope_2_BackwardsIterator m_Backwards();
  t_std_collections_List_1Tt_mx2_Scope_2_Iterator m_All();
  t_std_collections_List_1Tt_mx2_Scope_2_Node* m_AddLast(t_mx2_Scope* l_value);
  t_std_collections_List_1Tt_mx2_Scope_2_Node* m_AddFirst(t_mx2_Scope* l_value);
  void m_AddAll(bbArray<bbGCVar<t_mx2_Scope>>* l_values);
  void m_Add(t_mx2_Scope* l_value);
};

struct t_std_collections_List_1Tt_mx2_SNode_2_Node : public bbObject{

  const char *typeName()const{return "t_std_collections_List_1Tt_mx2_SNode_2_Node";}

  bbGCVar<t_std_collections_List_1Tt_mx2_SNode_2_Node> m__0succ{};
  bbGCVar<t_std_collections_List_1Tt_mx2_SNode_2_Node> m__0pred{};
  bbGCVar<t_mx2_SNode> m__0value{};

  void gcMark();

  t_std_collections_List_1Tt_mx2_SNode_2_Node(t_mx2_SNode* l_value,t_std_collections_List_1Tt_mx2_SNode_2_Node* l_succ);
  t_std_collections_List_1Tt_mx2_SNode_2_Node(t_mx2_SNode* l_value);

  void m_Value(t_mx2_SNode* l_value);
  t_mx2_SNode* m_Value();
  t_std_collections_List_1Tt_mx2_SNode_2_Node* m_Succ();
  void m_Remove();
  t_std_collections_List_1Tt_mx2_SNode_2_Node* m_Pred();
  void m_InsertBefore(t_std_collections_List_1Tt_mx2_SNode_2_Node* l_node);
  void m_InsertAfter(t_std_collections_List_1Tt_mx2_SNode_2_Node* l_node);

  t_std_collections_List_1Tt_mx2_SNode_2_Node(){
  }
};

struct t_std_collections_List_1Tt_mx2_SNode_2_Iterator{
  const char *typeName()const{return "t_std_collections_List_1Tt_mx2_SNode_2_Iterator";}

  bbGCVar<t_std_collections_List_1Tt_mx2_SNode_2> m__0list{};
  bbGCVar<t_std_collections_List_1Tt_mx2_SNode_2_Node> m__0node{};
  bbInt m__0seq{};

  t_std_collections_List_1Tt_mx2_SNode_2_Iterator(t_std_collections_List_1Tt_mx2_SNode_2* l_list,t_std_collections_List_1Tt_mx2_SNode_2_Node* l_node);

  void m_Insert(t_mx2_SNode* l_value);
  void m_Erase();
  void m_Current(t_mx2_SNode* l_current);
  t_mx2_SNode* m_Current();
  void m_Bump();
  bbBool m_AtEnd();
  void m_AssertSeq();
  void m_AssertCurrent();

  t_std_collections_List_1Tt_mx2_SNode_2_Iterator(){
  }

  t_std_collections_List_1Tt_mx2_SNode_2_Iterator(bbNullCtor_t){
  }
};

int bbCompare(const t_std_collections_List_1Tt_mx2_SNode_2_Iterator&x,const t_std_collections_List_1Tt_mx2_SNode_2_Iterator&y);

void bbGCMark(const t_std_collections_List_1Tt_mx2_SNode_2_Iterator&);

struct t_std_collections_List_1Tt_mx2_SNode_2_BackwardsIterator{
  const char *typeName()const{return "t_std_collections_List_1Tt_mx2_SNode_2_BackwardsIterator";}

  bbGCVar<t_std_collections_List_1Tt_mx2_SNode_2> m__0list{};
  bbGCVar<t_std_collections_List_1Tt_mx2_SNode_2_Node> m__0node{};
  bbInt m__0seq{};

  t_std_collections_List_1Tt_mx2_SNode_2_BackwardsIterator(t_std_collections_List_1Tt_mx2_SNode_2* l_list,t_std_collections_List_1Tt_mx2_SNode_2_Node* l_node);

  void m_Insert(t_mx2_SNode* l_value);
  void m_Erase();
  void m_Current(t_mx2_SNode* l_current);
  t_mx2_SNode* m_Current();
  void m_Bump();
  bbBool m_AtEnd();
  void m_AssertSeq();
  void m_AssertCurrent();

  t_std_collections_List_1Tt_mx2_SNode_2_BackwardsIterator(){
  }

  t_std_collections_List_1Tt_mx2_SNode_2_BackwardsIterator(bbNullCtor_t){
  }
};

int bbCompare(const t_std_collections_List_1Tt_mx2_SNode_2_BackwardsIterator&x,const t_std_collections_List_1Tt_mx2_SNode_2_BackwardsIterator&y);

void bbGCMark(const t_std_collections_List_1Tt_mx2_SNode_2_BackwardsIterator&);

struct t_std_collections_List_1Tt_mx2_SNode_2 : public bbObject,public virtual t_std_collections_IContainer_1Tt_mx2_SNode_2{

  const char *typeName()const{return "t_std_collections_List_1Tt_mx2_SNode_2";}

  bbGCVar<t_std_collections_List_1Tt_mx2_SNode_2_Node> m__0head{};
  bbInt m__0seq{};

  void gcMark();

  t_std_collections_List_1Tt_mx2_SNode_2(t_std_collections_List_1Tt_mx2_SNode_2* l_values);
  t_std_collections_List_1Tt_mx2_SNode_2(t_std_collections_Stack_1Tt_mx2_SNode_2* l_values);
  t_std_collections_List_1Tt_mx2_SNode_2(bbArray<bbGCVar<t_mx2_SNode>>* l_values);
  t_std_collections_List_1Tt_mx2_SNode_2();

  bbArray<bbGCVar<t_mx2_SNode>>* m_ToArray();
  void m_Sort(bbFunction<bbInt(t_mx2_SNode*,t_mx2_SNode*)> l_compareFunc);
  void m_Sort(bbBool l_ascending);
  t_mx2_SNode* m_RemoveLast();
  bbBool m_RemoveLast(t_mx2_SNode* l_value);
  t_mx2_SNode* m_RemoveFirst();
  bbInt m_RemoveEach(t_mx2_SNode* l_value);
  bbBool m_Remove(t_mx2_SNode* l_value);
  t_std_collections_List_1Tt_mx2_SNode_2_Node* m_LastNode();
  t_mx2_SNode* m_Last();
  t_std_collections_List_1Tt_mx2_SNode_2_Node* m_HeadNode();
  t_std_collections_List_1Tt_mx2_SNode_2_Node* m_FirstNode();
  t_mx2_SNode* m_First();
  t_std_collections_List_1Tt_mx2_SNode_2_Node* m_FindNode(t_mx2_SNode* l_value);
  t_std_collections_List_1Tt_mx2_SNode_2_Node* m_FindLastNode(t_mx2_SNode* l_value);
  bbBool m_Empty();
  bbInt m_Count();
  void m_Clear();
  t_std_collections_List_1Tt_mx2_SNode_2_BackwardsIterator m_Backwards();
  t_std_collections_List_1Tt_mx2_SNode_2_Iterator m_All();
  t_std_collections_List_1Tt_mx2_SNode_2_Node* m_AddLast(t_mx2_SNode* l_value);
  t_std_collections_List_1Tt_mx2_SNode_2_Node* m_AddFirst(t_mx2_SNode* l_value);
  void m_AddAll(bbArray<bbGCVar<t_mx2_SNode>>* l_values);
  void m_Add(t_mx2_SNode* l_value);
};

struct t_std_collections_List_1Tt_mx2_VarValue_2_Node : public bbObject{

  const char *typeName()const{return "t_std_collections_List_1Tt_mx2_VarValue_2_Node";}

  bbGCVar<t_std_collections_List_1Tt_mx2_VarValue_2_Node> m__0succ{};
  bbGCVar<t_std_collections_List_1Tt_mx2_VarValue_2_Node> m__0pred{};
  bbGCVar<t_mx2_VarValue> m__0value{};

  void gcMark();

  t_std_collections_List_1Tt_mx2_VarValue_2_Node(t_mx2_VarValue* l_value,t_std_collections_List_1Tt_mx2_VarValue_2_Node* l_succ);
  t_std_collections_List_1Tt_mx2_VarValue_2_Node(t_mx2_VarValue* l_value);

  void m_Value(t_mx2_VarValue* l_value);
  t_mx2_VarValue* m_Value();
  t_std_collections_List_1Tt_mx2_VarValue_2_Node* m_Succ();
  void m_Remove();
  t_std_collections_List_1Tt_mx2_VarValue_2_Node* m_Pred();
  void m_InsertBefore(t_std_collections_List_1Tt_mx2_VarValue_2_Node* l_node);
  void m_InsertAfter(t_std_collections_List_1Tt_mx2_VarValue_2_Node* l_node);

  t_std_collections_List_1Tt_mx2_VarValue_2_Node(){
  }
};

struct t_std_collections_List_1Tt_mx2_VarValue_2_Iterator{
  const char *typeName()const{return "t_std_collections_List_1Tt_mx2_VarValue_2_Iterator";}

  bbGCVar<t_std_collections_List_1Tt_mx2_VarValue_2> m__0list{};
  bbGCVar<t_std_collections_List_1Tt_mx2_VarValue_2_Node> m__0node{};
  bbInt m__0seq{};

  t_std_collections_List_1Tt_mx2_VarValue_2_Iterator(t_std_collections_List_1Tt_mx2_VarValue_2* l_list,t_std_collections_List_1Tt_mx2_VarValue_2_Node* l_node);

  void m_Insert(t_mx2_VarValue* l_value);
  void m_Erase();
  void m_Current(t_mx2_VarValue* l_current);
  t_mx2_VarValue* m_Current();
  void m_Bump();
  bbBool m_AtEnd();
  void m_AssertSeq();
  void m_AssertCurrent();

  t_std_collections_List_1Tt_mx2_VarValue_2_Iterator(){
  }

  t_std_collections_List_1Tt_mx2_VarValue_2_Iterator(bbNullCtor_t){
  }
};

int bbCompare(const t_std_collections_List_1Tt_mx2_VarValue_2_Iterator&x,const t_std_collections_List_1Tt_mx2_VarValue_2_Iterator&y);

void bbGCMark(const t_std_collections_List_1Tt_mx2_VarValue_2_Iterator&);

struct t_std_collections_List_1Tt_mx2_VarValue_2_BackwardsIterator{
  const char *typeName()const{return "t_std_collections_List_1Tt_mx2_VarValue_2_BackwardsIterator";}

  bbGCVar<t_std_collections_List_1Tt_mx2_VarValue_2> m__0list{};
  bbGCVar<t_std_collections_List_1Tt_mx2_VarValue_2_Node> m__0node{};
  bbInt m__0seq{};

  t_std_collections_List_1Tt_mx2_VarValue_2_BackwardsIterator(t_std_collections_List_1Tt_mx2_VarValue_2* l_list,t_std_collections_List_1Tt_mx2_VarValue_2_Node* l_node);

  void m_Insert(t_mx2_VarValue* l_value);
  void m_Erase();
  void m_Current(t_mx2_VarValue* l_current);
  t_mx2_VarValue* m_Current();
  void m_Bump();
  bbBool m_AtEnd();
  void m_AssertSeq();
  void m_AssertCurrent();

  t_std_collections_List_1Tt_mx2_VarValue_2_BackwardsIterator(){
  }

  t_std_collections_List_1Tt_mx2_VarValue_2_BackwardsIterator(bbNullCtor_t){
  }
};

int bbCompare(const t_std_collections_List_1Tt_mx2_VarValue_2_BackwardsIterator&x,const t_std_collections_List_1Tt_mx2_VarValue_2_BackwardsIterator&y);

void bbGCMark(const t_std_collections_List_1Tt_mx2_VarValue_2_BackwardsIterator&);

struct t_std_collections_List_1Tt_mx2_VarValue_2 : public bbObject,public virtual t_std_collections_IContainer_1Tt_mx2_VarValue_2{

  const char *typeName()const{return "t_std_collections_List_1Tt_mx2_VarValue_2";}

  bbGCVar<t_std_collections_List_1Tt_mx2_VarValue_2_Node> m__0head{};
  bbInt m__0seq{};

  void gcMark();

  t_std_collections_List_1Tt_mx2_VarValue_2(t_std_collections_List_1Tt_mx2_VarValue_2* l_values);
  t_std_collections_List_1Tt_mx2_VarValue_2(t_std_collections_Stack_1Tt_mx2_VarValue_2* l_values);
  t_std_collections_List_1Tt_mx2_VarValue_2(bbArray<bbGCVar<t_mx2_VarValue>>* l_values);
  t_std_collections_List_1Tt_mx2_VarValue_2();

  bbArray<bbGCVar<t_mx2_VarValue>>* m_ToArray();
  void m_Sort(bbFunction<bbInt(t_mx2_VarValue*,t_mx2_VarValue*)> l_compareFunc);
  void m_Sort(bbBool l_ascending);
  t_mx2_VarValue* m_RemoveLast();
  bbBool m_RemoveLast(t_mx2_VarValue* l_value);
  t_mx2_VarValue* m_RemoveFirst();
  bbInt m_RemoveEach(t_mx2_VarValue* l_value);
  bbBool m_Remove(t_mx2_VarValue* l_value);
  t_std_collections_List_1Tt_mx2_VarValue_2_Node* m_LastNode();
  t_mx2_VarValue* m_Last();
  t_std_collections_List_1Tt_mx2_VarValue_2_Node* m_HeadNode();
  t_std_collections_List_1Tt_mx2_VarValue_2_Node* m_FirstNode();
  t_mx2_VarValue* m_First();
  t_std_collections_List_1Tt_mx2_VarValue_2_Node* m_FindNode(t_mx2_VarValue* l_value);
  t_std_collections_List_1Tt_mx2_VarValue_2_Node* m_FindLastNode(t_mx2_VarValue* l_value);
  bbBool m_Empty();
  bbInt m_Count();
  void m_Clear();
  t_std_collections_List_1Tt_mx2_VarValue_2_BackwardsIterator m_Backwards();
  t_std_collections_List_1Tt_mx2_VarValue_2_Iterator m_All();
  t_std_collections_List_1Tt_mx2_VarValue_2_Node* m_AddLast(t_mx2_VarValue* l_value);
  t_std_collections_List_1Tt_mx2_VarValue_2_Node* m_AddFirst(t_mx2_VarValue* l_value);
  void m_AddAll(bbArray<bbGCVar<t_mx2_VarValue>>* l_values);
  void m_Add(t_mx2_VarValue* l_value);
};

struct t_std_collections_List_1Tt_std_collections_Stack_1s_2_Node : public bbObject{

  const char *typeName()const{return "t_std_collections_List_1Tt_std_collections_Stack_1s_2_Node";}

  bbGCVar<t_std_collections_List_1Tt_std_collections_Stack_1s_2_Node> m__0succ{};
  bbGCVar<t_std_collections_List_1Tt_std_collections_Stack_1s_2_Node> m__0pred{};
  bbGCVar<t_std_collections_Stack_1s> m__0value{};

  void gcMark();

  t_std_collections_List_1Tt_std_collections_Stack_1s_2_Node(t_std_collections_Stack_1s* l_value,t_std_collections_List_1Tt_std_collections_Stack_1s_2_Node* l_succ);
  t_std_collections_List_1Tt_std_collections_Stack_1s_2_Node(t_std_collections_Stack_1s* l_value);

  void m_Value(t_std_collections_Stack_1s* l_value);
  t_std_collections_Stack_1s* m_Value();
  t_std_collections_List_1Tt_std_collections_Stack_1s_2_Node* m_Succ();
  void m_Remove();
  t_std_collections_List_1Tt_std_collections_Stack_1s_2_Node* m_Pred();
  void m_InsertBefore(t_std_collections_List_1Tt_std_collections_Stack_1s_2_Node* l_node);
  void m_InsertAfter(t_std_collections_List_1Tt_std_collections_Stack_1s_2_Node* l_node);

  t_std_collections_List_1Tt_std_collections_Stack_1s_2_Node(){
  }
};

struct t_std_collections_List_1Tt_std_collections_Stack_1s_2_Iterator{
  const char *typeName()const{return "t_std_collections_List_1Tt_std_collections_Stack_1s_2_Iterator";}

  bbGCVar<t_std_collections_List_1Tt_std_collections_Stack_1s_2> m__0list{};
  bbGCVar<t_std_collections_List_1Tt_std_collections_Stack_1s_2_Node> m__0node{};
  bbInt m__0seq{};

  t_std_collections_List_1Tt_std_collections_Stack_1s_2_Iterator(t_std_collections_List_1Tt_std_collections_Stack_1s_2* l_list,t_std_collections_List_1Tt_std_collections_Stack_1s_2_Node* l_node);

  void m_Insert(t_std_collections_Stack_1s* l_value);
  void m_Erase();
  void m_Current(t_std_collections_Stack_1s* l_current);
  t_std_collections_Stack_1s* m_Current();
  void m_Bump();
  bbBool m_AtEnd();
  void m_AssertSeq();
  void m_AssertCurrent();

  t_std_collections_List_1Tt_std_collections_Stack_1s_2_Iterator(){
  }

  t_std_collections_List_1Tt_std_collections_Stack_1s_2_Iterator(bbNullCtor_t){
  }
};

int bbCompare(const t_std_collections_List_1Tt_std_collections_Stack_1s_2_Iterator&x,const t_std_collections_List_1Tt_std_collections_Stack_1s_2_Iterator&y);

void bbGCMark(const t_std_collections_List_1Tt_std_collections_Stack_1s_2_Iterator&);

struct t_std_collections_List_1Tt_std_collections_Stack_1s_2_BackwardsIterator{
  const char *typeName()const{return "t_std_collections_List_1Tt_std_collections_Stack_1s_2_BackwardsIterator";}

  bbGCVar<t_std_collections_List_1Tt_std_collections_Stack_1s_2> m__0list{};
  bbGCVar<t_std_collections_List_1Tt_std_collections_Stack_1s_2_Node> m__0node{};
  bbInt m__0seq{};

  t_std_collections_List_1Tt_std_collections_Stack_1s_2_BackwardsIterator(t_std_collections_List_1Tt_std_collections_Stack_1s_2* l_list,t_std_collections_List_1Tt_std_collections_Stack_1s_2_Node* l_node);

  void m_Insert(t_std_collections_Stack_1s* l_value);
  void m_Erase();
  void m_Current(t_std_collections_Stack_1s* l_current);
  t_std_collections_Stack_1s* m_Current();
  void m_Bump();
  bbBool m_AtEnd();
  void m_AssertSeq();
  void m_AssertCurrent();

  t_std_collections_List_1Tt_std_collections_Stack_1s_2_BackwardsIterator(){
  }

  t_std_collections_List_1Tt_std_collections_Stack_1s_2_BackwardsIterator(bbNullCtor_t){
  }
};

int bbCompare(const t_std_collections_List_1Tt_std_collections_Stack_1s_2_BackwardsIterator&x,const t_std_collections_List_1Tt_std_collections_Stack_1s_2_BackwardsIterator&y);

void bbGCMark(const t_std_collections_List_1Tt_std_collections_Stack_1s_2_BackwardsIterator&);

struct t_std_collections_List_1Tt_std_collections_Stack_1s_2 : public bbObject,public virtual t_std_collections_IContainer_1Tt_std_collections_Stack_1s_2{

  const char *typeName()const{return "t_std_collections_List_1Tt_std_collections_Stack_1s_2";}

  bbGCVar<t_std_collections_List_1Tt_std_collections_Stack_1s_2_Node> m__0head{};
  bbInt m__0seq{};

  void gcMark();

  t_std_collections_List_1Tt_std_collections_Stack_1s_2(t_std_collections_List_1Tt_std_collections_Stack_1s_2* l_values);
  t_std_collections_List_1Tt_std_collections_Stack_1s_2(t_std_collections_Stack_1Tt_std_collections_Stack_1s_2* l_values);
  t_std_collections_List_1Tt_std_collections_Stack_1s_2(bbArray<bbGCVar<t_std_collections_Stack_1s>>* l_values);
  t_std_collections_List_1Tt_std_collections_Stack_1s_2();

  bbArray<bbGCVar<t_std_collections_Stack_1s>>* m_ToArray();
  void m_Sort(bbFunction<bbInt(t_std_collections_Stack_1s*,t_std_collections_Stack_1s*)> l_compareFunc);
  void m_Sort(bbBool l_ascending);
  t_std_collections_Stack_1s* m_RemoveLast();
  bbBool m_RemoveLast(t_std_collections_Stack_1s* l_value);
  t_std_collections_Stack_1s* m_RemoveFirst();
  bbInt m_RemoveEach(t_std_collections_Stack_1s* l_value);
  bbBool m_Remove(t_std_collections_Stack_1s* l_value);
  t_std_collections_List_1Tt_std_collections_Stack_1s_2_Node* m_LastNode();
  t_std_collections_Stack_1s* m_Last();
  t_std_collections_List_1Tt_std_collections_Stack_1s_2_Node* m_HeadNode();
  t_std_collections_List_1Tt_std_collections_Stack_1s_2_Node* m_FirstNode();
  t_std_collections_Stack_1s* m_First();
  t_std_collections_List_1Tt_std_collections_Stack_1s_2_Node* m_FindNode(t_std_collections_Stack_1s* l_value);
  t_std_collections_List_1Tt_std_collections_Stack_1s_2_Node* m_FindLastNode(t_std_collections_Stack_1s* l_value);
  bbBool m_Empty();
  bbInt m_Count();
  void m_Clear();
  t_std_collections_List_1Tt_std_collections_Stack_1s_2_BackwardsIterator m_Backwards();
  t_std_collections_List_1Tt_std_collections_Stack_1s_2_Iterator m_All();
  t_std_collections_List_1Tt_std_collections_Stack_1s_2_Node* m_AddLast(t_std_collections_Stack_1s* l_value);
  t_std_collections_List_1Tt_std_collections_Stack_1s_2_Node* m_AddFirst(t_std_collections_Stack_1s* l_value);
  void m_AddAll(bbArray<bbGCVar<t_std_collections_Stack_1s>>* l_values);
  void m_Add(t_std_collections_Stack_1s* l_value);
};

struct t_std_collections_List_1Tt_mx2_FileDecl_2_Node : public bbObject{

  const char *typeName()const{return "t_std_collections_List_1Tt_mx2_FileDecl_2_Node";}

  bbGCVar<t_std_collections_List_1Tt_mx2_FileDecl_2_Node> m__0succ{};
  bbGCVar<t_std_collections_List_1Tt_mx2_FileDecl_2_Node> m__0pred{};
  bbGCVar<t_mx2_FileDecl> m__0value{};

  void gcMark();

  t_std_collections_List_1Tt_mx2_FileDecl_2_Node(t_mx2_FileDecl* l_value,t_std_collections_List_1Tt_mx2_FileDecl_2_Node* l_succ);
  t_std_collections_List_1Tt_mx2_FileDecl_2_Node(t_mx2_FileDecl* l_value);

  void m_Value(t_mx2_FileDecl* l_value);
  t_mx2_FileDecl* m_Value();
  t_std_collections_List_1Tt_mx2_FileDecl_2_Node* m_Succ();
  void m_Remove();
  t_std_collections_List_1Tt_mx2_FileDecl_2_Node* m_Pred();
  void m_InsertBefore(t_std_collections_List_1Tt_mx2_FileDecl_2_Node* l_node);
  void m_InsertAfter(t_std_collections_List_1Tt_mx2_FileDecl_2_Node* l_node);

  t_std_collections_List_1Tt_mx2_FileDecl_2_Node(){
  }
};

struct t_std_collections_List_1Tt_mx2_FileDecl_2_Iterator{
  const char *typeName()const{return "t_std_collections_List_1Tt_mx2_FileDecl_2_Iterator";}

  bbGCVar<t_std_collections_List_1Tt_mx2_FileDecl_2> m__0list{};
  bbGCVar<t_std_collections_List_1Tt_mx2_FileDecl_2_Node> m__0node{};
  bbInt m__0seq{};

  t_std_collections_List_1Tt_mx2_FileDecl_2_Iterator(t_std_collections_List_1Tt_mx2_FileDecl_2* l_list,t_std_collections_List_1Tt_mx2_FileDecl_2_Node* l_node);

  void m_Insert(t_mx2_FileDecl* l_value);
  void m_Erase();
  void m_Current(t_mx2_FileDecl* l_current);
  t_mx2_FileDecl* m_Current();
  void m_Bump();
  bbBool m_AtEnd();
  void m_AssertSeq();
  void m_AssertCurrent();

  t_std_collections_List_1Tt_mx2_FileDecl_2_Iterator(){
  }

  t_std_collections_List_1Tt_mx2_FileDecl_2_Iterator(bbNullCtor_t){
  }
};

int bbCompare(const t_std_collections_List_1Tt_mx2_FileDecl_2_Iterator&x,const t_std_collections_List_1Tt_mx2_FileDecl_2_Iterator&y);

void bbGCMark(const t_std_collections_List_1Tt_mx2_FileDecl_2_Iterator&);

struct t_std_collections_List_1Tt_mx2_FileDecl_2_BackwardsIterator{
  const char *typeName()const{return "t_std_collections_List_1Tt_mx2_FileDecl_2_BackwardsIterator";}

  bbGCVar<t_std_collections_List_1Tt_mx2_FileDecl_2> m__0list{};
  bbGCVar<t_std_collections_List_1Tt_mx2_FileDecl_2_Node> m__0node{};
  bbInt m__0seq{};

  t_std_collections_List_1Tt_mx2_FileDecl_2_BackwardsIterator(t_std_collections_List_1Tt_mx2_FileDecl_2* l_list,t_std_collections_List_1Tt_mx2_FileDecl_2_Node* l_node);

  void m_Insert(t_mx2_FileDecl* l_value);
  void m_Erase();
  void m_Current(t_mx2_FileDecl* l_current);
  t_mx2_FileDecl* m_Current();
  void m_Bump();
  bbBool m_AtEnd();
  void m_AssertSeq();
  void m_AssertCurrent();

  t_std_collections_List_1Tt_mx2_FileDecl_2_BackwardsIterator(){
  }

  t_std_collections_List_1Tt_mx2_FileDecl_2_BackwardsIterator(bbNullCtor_t){
  }
};

int bbCompare(const t_std_collections_List_1Tt_mx2_FileDecl_2_BackwardsIterator&x,const t_std_collections_List_1Tt_mx2_FileDecl_2_BackwardsIterator&y);

void bbGCMark(const t_std_collections_List_1Tt_mx2_FileDecl_2_BackwardsIterator&);

struct t_std_collections_List_1Tt_mx2_FileDecl_2 : public bbObject,public virtual t_std_collections_IContainer_1Tt_mx2_FileDecl_2{

  const char *typeName()const{return "t_std_collections_List_1Tt_mx2_FileDecl_2";}

  bbGCVar<t_std_collections_List_1Tt_mx2_FileDecl_2_Node> m__0head{};
  bbInt m__0seq{};

  void gcMark();

  t_std_collections_List_1Tt_mx2_FileDecl_2(t_std_collections_List_1Tt_mx2_FileDecl_2* l_values);
  t_std_collections_List_1Tt_mx2_FileDecl_2(t_std_collections_Stack_1Tt_mx2_FileDecl_2* l_values);
  t_std_collections_List_1Tt_mx2_FileDecl_2(bbArray<bbGCVar<t_mx2_FileDecl>>* l_values);
  t_std_collections_List_1Tt_mx2_FileDecl_2();

  bbArray<bbGCVar<t_mx2_FileDecl>>* m_ToArray();
  void m_Sort(bbFunction<bbInt(t_mx2_FileDecl*,t_mx2_FileDecl*)> l_compareFunc);
  void m_Sort(bbBool l_ascending);
  t_mx2_FileDecl* m_RemoveLast();
  bbBool m_RemoveLast(t_mx2_FileDecl* l_value);
  t_mx2_FileDecl* m_RemoveFirst();
  bbInt m_RemoveEach(t_mx2_FileDecl* l_value);
  bbBool m_Remove(t_mx2_FileDecl* l_value);
  t_std_collections_List_1Tt_mx2_FileDecl_2_Node* m_LastNode();
  t_mx2_FileDecl* m_Last();
  t_std_collections_List_1Tt_mx2_FileDecl_2_Node* m_HeadNode();
  t_std_collections_List_1Tt_mx2_FileDecl_2_Node* m_FirstNode();
  t_mx2_FileDecl* m_First();
  t_std_collections_List_1Tt_mx2_FileDecl_2_Node* m_FindNode(t_mx2_FileDecl* l_value);
  t_std_collections_List_1Tt_mx2_FileDecl_2_Node* m_FindLastNode(t_mx2_FileDecl* l_value);
  bbBool m_Empty();
  bbInt m_Count();
  void m_Clear();
  t_std_collections_List_1Tt_mx2_FileDecl_2_BackwardsIterator m_Backwards();
  t_std_collections_List_1Tt_mx2_FileDecl_2_Iterator m_All();
  t_std_collections_List_1Tt_mx2_FileDecl_2_Node* m_AddLast(t_mx2_FileDecl* l_value);
  t_std_collections_List_1Tt_mx2_FileDecl_2_Node* m_AddFirst(t_mx2_FileDecl* l_value);
  void m_AddAll(bbArray<bbGCVar<t_mx2_FileDecl>>* l_values);
  void m_Add(t_mx2_FileDecl* l_value);
};

struct t_std_collections_List_1Tt_mx2_FileScope_2_Node : public bbObject{

  const char *typeName()const{return "t_std_collections_List_1Tt_mx2_FileScope_2_Node";}

  bbGCVar<t_std_collections_List_1Tt_mx2_FileScope_2_Node> m__0succ{};
  bbGCVar<t_std_collections_List_1Tt_mx2_FileScope_2_Node> m__0pred{};
  bbGCVar<t_mx2_FileScope> m__0value{};

  void gcMark();

  t_std_collections_List_1Tt_mx2_FileScope_2_Node(t_mx2_FileScope* l_value,t_std_collections_List_1Tt_mx2_FileScope_2_Node* l_succ);
  t_std_collections_List_1Tt_mx2_FileScope_2_Node(t_mx2_FileScope* l_value);

  void m_Value(t_mx2_FileScope* l_value);
  t_mx2_FileScope* m_Value();
  t_std_collections_List_1Tt_mx2_FileScope_2_Node* m_Succ();
  void m_Remove();
  t_std_collections_List_1Tt_mx2_FileScope_2_Node* m_Pred();
  void m_InsertBefore(t_std_collections_List_1Tt_mx2_FileScope_2_Node* l_node);
  void m_InsertAfter(t_std_collections_List_1Tt_mx2_FileScope_2_Node* l_node);

  t_std_collections_List_1Tt_mx2_FileScope_2_Node(){
  }
};

struct t_std_collections_List_1Tt_mx2_FileScope_2_Iterator{
  const char *typeName()const{return "t_std_collections_List_1Tt_mx2_FileScope_2_Iterator";}

  bbGCVar<t_std_collections_List_1Tt_mx2_FileScope_2> m__0list{};
  bbGCVar<t_std_collections_List_1Tt_mx2_FileScope_2_Node> m__0node{};
  bbInt m__0seq{};

  t_std_collections_List_1Tt_mx2_FileScope_2_Iterator(t_std_collections_List_1Tt_mx2_FileScope_2* l_list,t_std_collections_List_1Tt_mx2_FileScope_2_Node* l_node);

  void m_Insert(t_mx2_FileScope* l_value);
  void m_Erase();
  void m_Current(t_mx2_FileScope* l_current);
  t_mx2_FileScope* m_Current();
  void m_Bump();
  bbBool m_AtEnd();
  void m_AssertSeq();
  void m_AssertCurrent();

  t_std_collections_List_1Tt_mx2_FileScope_2_Iterator(){
  }

  t_std_collections_List_1Tt_mx2_FileScope_2_Iterator(bbNullCtor_t){
  }
};

int bbCompare(const t_std_collections_List_1Tt_mx2_FileScope_2_Iterator&x,const t_std_collections_List_1Tt_mx2_FileScope_2_Iterator&y);

void bbGCMark(const t_std_collections_List_1Tt_mx2_FileScope_2_Iterator&);

struct t_std_collections_List_1Tt_mx2_FileScope_2_BackwardsIterator{
  const char *typeName()const{return "t_std_collections_List_1Tt_mx2_FileScope_2_BackwardsIterator";}

  bbGCVar<t_std_collections_List_1Tt_mx2_FileScope_2> m__0list{};
  bbGCVar<t_std_collections_List_1Tt_mx2_FileScope_2_Node> m__0node{};
  bbInt m__0seq{};

  t_std_collections_List_1Tt_mx2_FileScope_2_BackwardsIterator(t_std_collections_List_1Tt_mx2_FileScope_2* l_list,t_std_collections_List_1Tt_mx2_FileScope_2_Node* l_node);

  void m_Insert(t_mx2_FileScope* l_value);
  void m_Erase();
  void m_Current(t_mx2_FileScope* l_current);
  t_mx2_FileScope* m_Current();
  void m_Bump();
  bbBool m_AtEnd();
  void m_AssertSeq();
  void m_AssertCurrent();

  t_std_collections_List_1Tt_mx2_FileScope_2_BackwardsIterator(){
  }

  t_std_collections_List_1Tt_mx2_FileScope_2_BackwardsIterator(bbNullCtor_t){
  }
};

int bbCompare(const t_std_collections_List_1Tt_mx2_FileScope_2_BackwardsIterator&x,const t_std_collections_List_1Tt_mx2_FileScope_2_BackwardsIterator&y);

void bbGCMark(const t_std_collections_List_1Tt_mx2_FileScope_2_BackwardsIterator&);

struct t_std_collections_List_1Tt_mx2_FileScope_2 : public bbObject,public virtual t_std_collections_IContainer_1Tt_mx2_FileScope_2{

  const char *typeName()const{return "t_std_collections_List_1Tt_mx2_FileScope_2";}

  bbGCVar<t_std_collections_List_1Tt_mx2_FileScope_2_Node> m__0head{};
  bbInt m__0seq{};

  void gcMark();

  t_std_collections_List_1Tt_mx2_FileScope_2(t_std_collections_List_1Tt_mx2_FileScope_2* l_values);
  t_std_collections_List_1Tt_mx2_FileScope_2(t_std_collections_Stack_1Tt_mx2_FileScope_2* l_values);
  t_std_collections_List_1Tt_mx2_FileScope_2(bbArray<bbGCVar<t_mx2_FileScope>>* l_values);
  t_std_collections_List_1Tt_mx2_FileScope_2();

  bbArray<bbGCVar<t_mx2_FileScope>>* m_ToArray();
  void m_Sort(bbFunction<bbInt(t_mx2_FileScope*,t_mx2_FileScope*)> l_compareFunc);
  void m_Sort(bbBool l_ascending);
  t_mx2_FileScope* m_RemoveLast();
  bbBool m_RemoveLast(t_mx2_FileScope* l_value);
  t_mx2_FileScope* m_RemoveFirst();
  bbInt m_RemoveEach(t_mx2_FileScope* l_value);
  bbBool m_Remove(t_mx2_FileScope* l_value);
  t_std_collections_List_1Tt_mx2_FileScope_2_Node* m_LastNode();
  t_mx2_FileScope* m_Last();
  t_std_collections_List_1Tt_mx2_FileScope_2_Node* m_HeadNode();
  t_std_collections_List_1Tt_mx2_FileScope_2_Node* m_FirstNode();
  t_mx2_FileScope* m_First();
  t_std_collections_List_1Tt_mx2_FileScope_2_Node* m_FindNode(t_mx2_FileScope* l_value);
  t_std_collections_List_1Tt_mx2_FileScope_2_Node* m_FindLastNode(t_mx2_FileScope* l_value);
  bbBool m_Empty();
  bbInt m_Count();
  void m_Clear();
  t_std_collections_List_1Tt_mx2_FileScope_2_BackwardsIterator m_Backwards();
  t_std_collections_List_1Tt_mx2_FileScope_2_Iterator m_All();
  t_std_collections_List_1Tt_mx2_FileScope_2_Node* m_AddLast(t_mx2_FileScope* l_value);
  t_std_collections_List_1Tt_mx2_FileScope_2_Node* m_AddFirst(t_mx2_FileScope* l_value);
  void m_AddAll(bbArray<bbGCVar<t_mx2_FileScope>>* l_values);
  void m_Add(t_mx2_FileScope* l_value);
};

struct t_std_collections_List_1Tt_mx2_NamespaceScope_2_Node : public bbObject{

  const char *typeName()const{return "t_std_collections_List_1Tt_mx2_NamespaceScope_2_Node";}

  bbGCVar<t_std_collections_List_1Tt_mx2_NamespaceScope_2_Node> m__0succ{};
  bbGCVar<t_std_collections_List_1Tt_mx2_NamespaceScope_2_Node> m__0pred{};
  bbGCVar<t_mx2_NamespaceScope> m__0value{};

  void gcMark();

  t_std_collections_List_1Tt_mx2_NamespaceScope_2_Node(t_mx2_NamespaceScope* l_value,t_std_collections_List_1Tt_mx2_NamespaceScope_2_Node* l_succ);
  t_std_collections_List_1Tt_mx2_NamespaceScope_2_Node(t_mx2_NamespaceScope* l_value);

  void m_Value(t_mx2_NamespaceScope* l_value);
  t_mx2_NamespaceScope* m_Value();
  t_std_collections_List_1Tt_mx2_NamespaceScope_2_Node* m_Succ();
  void m_Remove();
  t_std_collections_List_1Tt_mx2_NamespaceScope_2_Node* m_Pred();
  void m_InsertBefore(t_std_collections_List_1Tt_mx2_NamespaceScope_2_Node* l_node);
  void m_InsertAfter(t_std_collections_List_1Tt_mx2_NamespaceScope_2_Node* l_node);

  t_std_collections_List_1Tt_mx2_NamespaceScope_2_Node(){
  }
};

struct t_std_collections_List_1Tt_mx2_NamespaceScope_2_Iterator{
  const char *typeName()const{return "t_std_collections_List_1Tt_mx2_NamespaceScope_2_Iterator";}

  bbGCVar<t_std_collections_List_1Tt_mx2_NamespaceScope_2> m__0list{};
  bbGCVar<t_std_collections_List_1Tt_mx2_NamespaceScope_2_Node> m__0node{};
  bbInt m__0seq{};

  t_std_collections_List_1Tt_mx2_NamespaceScope_2_Iterator(t_std_collections_List_1Tt_mx2_NamespaceScope_2* l_list,t_std_collections_List_1Tt_mx2_NamespaceScope_2_Node* l_node);

  void m_Insert(t_mx2_NamespaceScope* l_value);
  void m_Erase();
  void m_Current(t_mx2_NamespaceScope* l_current);
  t_mx2_NamespaceScope* m_Current();
  void m_Bump();
  bbBool m_AtEnd();
  void m_AssertSeq();
  void m_AssertCurrent();

  t_std_collections_List_1Tt_mx2_NamespaceScope_2_Iterator(){
  }

  t_std_collections_List_1Tt_mx2_NamespaceScope_2_Iterator(bbNullCtor_t){
  }
};

int bbCompare(const t_std_collections_List_1Tt_mx2_NamespaceScope_2_Iterator&x,const t_std_collections_List_1Tt_mx2_NamespaceScope_2_Iterator&y);

void bbGCMark(const t_std_collections_List_1Tt_mx2_NamespaceScope_2_Iterator&);

struct t_std_collections_List_1Tt_mx2_NamespaceScope_2_BackwardsIterator{
  const char *typeName()const{return "t_std_collections_List_1Tt_mx2_NamespaceScope_2_BackwardsIterator";}

  bbGCVar<t_std_collections_List_1Tt_mx2_NamespaceScope_2> m__0list{};
  bbGCVar<t_std_collections_List_1Tt_mx2_NamespaceScope_2_Node> m__0node{};
  bbInt m__0seq{};

  t_std_collections_List_1Tt_mx2_NamespaceScope_2_BackwardsIterator(t_std_collections_List_1Tt_mx2_NamespaceScope_2* l_list,t_std_collections_List_1Tt_mx2_NamespaceScope_2_Node* l_node);

  void m_Insert(t_mx2_NamespaceScope* l_value);
  void m_Erase();
  void m_Current(t_mx2_NamespaceScope* l_current);
  t_mx2_NamespaceScope* m_Current();
  void m_Bump();
  bbBool m_AtEnd();
  void m_AssertSeq();
  void m_AssertCurrent();

  t_std_collections_List_1Tt_mx2_NamespaceScope_2_BackwardsIterator(){
  }

  t_std_collections_List_1Tt_mx2_NamespaceScope_2_BackwardsIterator(bbNullCtor_t){
  }
};

int bbCompare(const t_std_collections_List_1Tt_mx2_NamespaceScope_2_BackwardsIterator&x,const t_std_collections_List_1Tt_mx2_NamespaceScope_2_BackwardsIterator&y);

void bbGCMark(const t_std_collections_List_1Tt_mx2_NamespaceScope_2_BackwardsIterator&);

struct t_std_collections_List_1Tt_mx2_NamespaceScope_2 : public bbObject,public virtual t_std_collections_IContainer_1Tt_mx2_NamespaceScope_2{

  const char *typeName()const{return "t_std_collections_List_1Tt_mx2_NamespaceScope_2";}

  bbGCVar<t_std_collections_List_1Tt_mx2_NamespaceScope_2_Node> m__0head{};
  bbInt m__0seq{};

  void gcMark();

  t_std_collections_List_1Tt_mx2_NamespaceScope_2(t_std_collections_List_1Tt_mx2_NamespaceScope_2* l_values);
  t_std_collections_List_1Tt_mx2_NamespaceScope_2(t_std_collections_Stack_1Tt_mx2_NamespaceScope_2* l_values);
  t_std_collections_List_1Tt_mx2_NamespaceScope_2(bbArray<bbGCVar<t_mx2_NamespaceScope>>* l_values);
  t_std_collections_List_1Tt_mx2_NamespaceScope_2();

  bbArray<bbGCVar<t_mx2_NamespaceScope>>* m_ToArray();
  void m_Sort(bbFunction<bbInt(t_mx2_NamespaceScope*,t_mx2_NamespaceScope*)> l_compareFunc);
  void m_Sort(bbBool l_ascending);
  t_mx2_NamespaceScope* m_RemoveLast();
  bbBool m_RemoveLast(t_mx2_NamespaceScope* l_value);
  t_mx2_NamespaceScope* m_RemoveFirst();
  bbInt m_RemoveEach(t_mx2_NamespaceScope* l_value);
  bbBool m_Remove(t_mx2_NamespaceScope* l_value);
  t_std_collections_List_1Tt_mx2_NamespaceScope_2_Node* m_LastNode();
  t_mx2_NamespaceScope* m_Last();
  t_std_collections_List_1Tt_mx2_NamespaceScope_2_Node* m_HeadNode();
  t_std_collections_List_1Tt_mx2_NamespaceScope_2_Node* m_FirstNode();
  t_mx2_NamespaceScope* m_First();
  t_std_collections_List_1Tt_mx2_NamespaceScope_2_Node* m_FindNode(t_mx2_NamespaceScope* l_value);
  t_std_collections_List_1Tt_mx2_NamespaceScope_2_Node* m_FindLastNode(t_mx2_NamespaceScope* l_value);
  bbBool m_Empty();
  bbInt m_Count();
  void m_Clear();
  t_std_collections_List_1Tt_mx2_NamespaceScope_2_BackwardsIterator m_Backwards();
  t_std_collections_List_1Tt_mx2_NamespaceScope_2_Iterator m_All();
  t_std_collections_List_1Tt_mx2_NamespaceScope_2_Node* m_AddLast(t_mx2_NamespaceScope* l_value);
  t_std_collections_List_1Tt_mx2_NamespaceScope_2_Node* m_AddFirst(t_mx2_NamespaceScope* l_value);
  void m_AddAll(bbArray<bbGCVar<t_mx2_NamespaceScope>>* l_values);
  void m_Add(t_mx2_NamespaceScope* l_value);
};

struct t_std_collections_List_1Tt_mx2_PNode_2_Node : public bbObject{

  const char *typeName()const{return "t_std_collections_List_1Tt_mx2_PNode_2_Node";}

  bbGCVar<t_std_collections_List_1Tt_mx2_PNode_2_Node> m__0succ{};
  bbGCVar<t_std_collections_List_1Tt_mx2_PNode_2_Node> m__0pred{};
  bbGCVar<t_mx2_PNode> m__0value{};

  void gcMark();

  t_std_collections_List_1Tt_mx2_PNode_2_Node(t_mx2_PNode* l_value,t_std_collections_List_1Tt_mx2_PNode_2_Node* l_succ);
  t_std_collections_List_1Tt_mx2_PNode_2_Node(t_mx2_PNode* l_value);

  void m_Value(t_mx2_PNode* l_value);
  t_mx2_PNode* m_Value();
  t_std_collections_List_1Tt_mx2_PNode_2_Node* m_Succ();
  void m_Remove();
  t_std_collections_List_1Tt_mx2_PNode_2_Node* m_Pred();
  void m_InsertBefore(t_std_collections_List_1Tt_mx2_PNode_2_Node* l_node);
  void m_InsertAfter(t_std_collections_List_1Tt_mx2_PNode_2_Node* l_node);

  t_std_collections_List_1Tt_mx2_PNode_2_Node(){
  }
};

struct t_std_collections_List_1Tt_mx2_PNode_2_Iterator{
  const char *typeName()const{return "t_std_collections_List_1Tt_mx2_PNode_2_Iterator";}

  bbGCVar<t_std_collections_List_1Tt_mx2_PNode_2> m__0list{};
  bbGCVar<t_std_collections_List_1Tt_mx2_PNode_2_Node> m__0node{};
  bbInt m__0seq{};

  t_std_collections_List_1Tt_mx2_PNode_2_Iterator(t_std_collections_List_1Tt_mx2_PNode_2* l_list,t_std_collections_List_1Tt_mx2_PNode_2_Node* l_node);

  void m_Insert(t_mx2_PNode* l_value);
  void m_Erase();
  void m_Current(t_mx2_PNode* l_current);
  t_mx2_PNode* m_Current();
  void m_Bump();
  bbBool m_AtEnd();
  void m_AssertSeq();
  void m_AssertCurrent();

  t_std_collections_List_1Tt_mx2_PNode_2_Iterator(){
  }

  t_std_collections_List_1Tt_mx2_PNode_2_Iterator(bbNullCtor_t){
  }
};

int bbCompare(const t_std_collections_List_1Tt_mx2_PNode_2_Iterator&x,const t_std_collections_List_1Tt_mx2_PNode_2_Iterator&y);

void bbGCMark(const t_std_collections_List_1Tt_mx2_PNode_2_Iterator&);

struct t_std_collections_List_1Tt_mx2_PNode_2_BackwardsIterator{
  const char *typeName()const{return "t_std_collections_List_1Tt_mx2_PNode_2_BackwardsIterator";}

  bbGCVar<t_std_collections_List_1Tt_mx2_PNode_2> m__0list{};
  bbGCVar<t_std_collections_List_1Tt_mx2_PNode_2_Node> m__0node{};
  bbInt m__0seq{};

  t_std_collections_List_1Tt_mx2_PNode_2_BackwardsIterator(t_std_collections_List_1Tt_mx2_PNode_2* l_list,t_std_collections_List_1Tt_mx2_PNode_2_Node* l_node);

  void m_Insert(t_mx2_PNode* l_value);
  void m_Erase();
  void m_Current(t_mx2_PNode* l_current);
  t_mx2_PNode* m_Current();
  void m_Bump();
  bbBool m_AtEnd();
  void m_AssertSeq();
  void m_AssertCurrent();

  t_std_collections_List_1Tt_mx2_PNode_2_BackwardsIterator(){
  }

  t_std_collections_List_1Tt_mx2_PNode_2_BackwardsIterator(bbNullCtor_t){
  }
};

int bbCompare(const t_std_collections_List_1Tt_mx2_PNode_2_BackwardsIterator&x,const t_std_collections_List_1Tt_mx2_PNode_2_BackwardsIterator&y);

void bbGCMark(const t_std_collections_List_1Tt_mx2_PNode_2_BackwardsIterator&);

struct t_std_collections_List_1Tt_mx2_PNode_2 : public bbObject,public virtual t_std_collections_IContainer_1Tt_mx2_PNode_2{

  const char *typeName()const{return "t_std_collections_List_1Tt_mx2_PNode_2";}

  bbGCVar<t_std_collections_List_1Tt_mx2_PNode_2_Node> m__0head{};
  bbInt m__0seq{};

  void gcMark();

  t_std_collections_List_1Tt_mx2_PNode_2(t_std_collections_List_1Tt_mx2_PNode_2* l_values);
  t_std_collections_List_1Tt_mx2_PNode_2(t_std_collections_Stack_1Tt_mx2_PNode_2* l_values);
  t_std_collections_List_1Tt_mx2_PNode_2(bbArray<bbGCVar<t_mx2_PNode>>* l_values);
  t_std_collections_List_1Tt_mx2_PNode_2();

  bbArray<bbGCVar<t_mx2_PNode>>* m_ToArray();
  void m_Sort(bbFunction<bbInt(t_mx2_PNode*,t_mx2_PNode*)> l_compareFunc);
  void m_Sort(bbBool l_ascending);
  t_mx2_PNode* m_RemoveLast();
  bbBool m_RemoveLast(t_mx2_PNode* l_value);
  t_mx2_PNode* m_RemoveFirst();
  bbInt m_RemoveEach(t_mx2_PNode* l_value);
  bbBool m_Remove(t_mx2_PNode* l_value);
  t_std_collections_List_1Tt_mx2_PNode_2_Node* m_LastNode();
  t_mx2_PNode* m_Last();
  t_std_collections_List_1Tt_mx2_PNode_2_Node* m_HeadNode();
  t_std_collections_List_1Tt_mx2_PNode_2_Node* m_FirstNode();
  t_mx2_PNode* m_First();
  t_std_collections_List_1Tt_mx2_PNode_2_Node* m_FindNode(t_mx2_PNode* l_value);
  t_std_collections_List_1Tt_mx2_PNode_2_Node* m_FindLastNode(t_mx2_PNode* l_value);
  bbBool m_Empty();
  bbInt m_Count();
  void m_Clear();
  t_std_collections_List_1Tt_mx2_PNode_2_BackwardsIterator m_Backwards();
  t_std_collections_List_1Tt_mx2_PNode_2_Iterator m_All();
  t_std_collections_List_1Tt_mx2_PNode_2_Node* m_AddLast(t_mx2_PNode* l_value);
  t_std_collections_List_1Tt_mx2_PNode_2_Node* m_AddFirst(t_mx2_PNode* l_value);
  void m_AddAll(bbArray<bbGCVar<t_mx2_PNode>>* l_values);
  void m_Add(t_mx2_PNode* l_value);
};

struct t_std_collections_List_1Tt_mx2_AliasType_2_Node : public bbObject{

  const char *typeName()const{return "t_std_collections_List_1Tt_mx2_AliasType_2_Node";}

  bbGCVar<t_std_collections_List_1Tt_mx2_AliasType_2_Node> m__0succ{};
  bbGCVar<t_std_collections_List_1Tt_mx2_AliasType_2_Node> m__0pred{};
  bbGCVar<t_mx2_AliasType> m__0value{};

  void gcMark();

  t_std_collections_List_1Tt_mx2_AliasType_2_Node(t_mx2_AliasType* l_value,t_std_collections_List_1Tt_mx2_AliasType_2_Node* l_succ);
  t_std_collections_List_1Tt_mx2_AliasType_2_Node(t_mx2_AliasType* l_value);

  void m_Value(t_mx2_AliasType* l_value);
  t_mx2_AliasType* m_Value();
  t_std_collections_List_1Tt_mx2_AliasType_2_Node* m_Succ();
  void m_Remove();
  t_std_collections_List_1Tt_mx2_AliasType_2_Node* m_Pred();
  void m_InsertBefore(t_std_collections_List_1Tt_mx2_AliasType_2_Node* l_node);
  void m_InsertAfter(t_std_collections_List_1Tt_mx2_AliasType_2_Node* l_node);

  t_std_collections_List_1Tt_mx2_AliasType_2_Node(){
  }
};

struct t_std_collections_List_1Tt_mx2_AliasType_2_Iterator{
  const char *typeName()const{return "t_std_collections_List_1Tt_mx2_AliasType_2_Iterator";}

  bbGCVar<t_std_collections_List_1Tt_mx2_AliasType_2> m__0list{};
  bbGCVar<t_std_collections_List_1Tt_mx2_AliasType_2_Node> m__0node{};
  bbInt m__0seq{};

  t_std_collections_List_1Tt_mx2_AliasType_2_Iterator(t_std_collections_List_1Tt_mx2_AliasType_2* l_list,t_std_collections_List_1Tt_mx2_AliasType_2_Node* l_node);

  void m_Insert(t_mx2_AliasType* l_value);
  void m_Erase();
  void m_Current(t_mx2_AliasType* l_current);
  t_mx2_AliasType* m_Current();
  void m_Bump();
  bbBool m_AtEnd();
  void m_AssertSeq();
  void m_AssertCurrent();

  t_std_collections_List_1Tt_mx2_AliasType_2_Iterator(){
  }

  t_std_collections_List_1Tt_mx2_AliasType_2_Iterator(bbNullCtor_t){
  }
};

int bbCompare(const t_std_collections_List_1Tt_mx2_AliasType_2_Iterator&x,const t_std_collections_List_1Tt_mx2_AliasType_2_Iterator&y);

void bbGCMark(const t_std_collections_List_1Tt_mx2_AliasType_2_Iterator&);

struct t_std_collections_List_1Tt_mx2_AliasType_2_BackwardsIterator{
  const char *typeName()const{return "t_std_collections_List_1Tt_mx2_AliasType_2_BackwardsIterator";}

  bbGCVar<t_std_collections_List_1Tt_mx2_AliasType_2> m__0list{};
  bbGCVar<t_std_collections_List_1Tt_mx2_AliasType_2_Node> m__0node{};
  bbInt m__0seq{};

  t_std_collections_List_1Tt_mx2_AliasType_2_BackwardsIterator(t_std_collections_List_1Tt_mx2_AliasType_2* l_list,t_std_collections_List_1Tt_mx2_AliasType_2_Node* l_node);

  void m_Insert(t_mx2_AliasType* l_value);
  void m_Erase();
  void m_Current(t_mx2_AliasType* l_current);
  t_mx2_AliasType* m_Current();
  void m_Bump();
  bbBool m_AtEnd();
  void m_AssertSeq();
  void m_AssertCurrent();

  t_std_collections_List_1Tt_mx2_AliasType_2_BackwardsIterator(){
  }

  t_std_collections_List_1Tt_mx2_AliasType_2_BackwardsIterator(bbNullCtor_t){
  }
};

int bbCompare(const t_std_collections_List_1Tt_mx2_AliasType_2_BackwardsIterator&x,const t_std_collections_List_1Tt_mx2_AliasType_2_BackwardsIterator&y);

void bbGCMark(const t_std_collections_List_1Tt_mx2_AliasType_2_BackwardsIterator&);

struct t_std_collections_List_1Tt_mx2_AliasType_2 : public bbObject,public virtual t_std_collections_IContainer_1Tt_mx2_AliasType_2{

  const char *typeName()const{return "t_std_collections_List_1Tt_mx2_AliasType_2";}

  bbGCVar<t_std_collections_List_1Tt_mx2_AliasType_2_Node> m__0head{};
  bbInt m__0seq{};

  void gcMark();

  t_std_collections_List_1Tt_mx2_AliasType_2(t_std_collections_List_1Tt_mx2_AliasType_2* l_values);
  t_std_collections_List_1Tt_mx2_AliasType_2(t_std_collections_Stack_1Tt_mx2_AliasType_2* l_values);
  t_std_collections_List_1Tt_mx2_AliasType_2(bbArray<bbGCVar<t_mx2_AliasType>>* l_values);
  t_std_collections_List_1Tt_mx2_AliasType_2();

  bbArray<bbGCVar<t_mx2_AliasType>>* m_ToArray();
  void m_Sort(bbFunction<bbInt(t_mx2_AliasType*,t_mx2_AliasType*)> l_compareFunc);
  void m_Sort(bbBool l_ascending);
  t_mx2_AliasType* m_RemoveLast();
  bbBool m_RemoveLast(t_mx2_AliasType* l_value);
  t_mx2_AliasType* m_RemoveFirst();
  bbInt m_RemoveEach(t_mx2_AliasType* l_value);
  bbBool m_Remove(t_mx2_AliasType* l_value);
  t_std_collections_List_1Tt_mx2_AliasType_2_Node* m_LastNode();
  t_mx2_AliasType* m_Last();
  t_std_collections_List_1Tt_mx2_AliasType_2_Node* m_HeadNode();
  t_std_collections_List_1Tt_mx2_AliasType_2_Node* m_FirstNode();
  t_mx2_AliasType* m_First();
  t_std_collections_List_1Tt_mx2_AliasType_2_Node* m_FindNode(t_mx2_AliasType* l_value);
  t_std_collections_List_1Tt_mx2_AliasType_2_Node* m_FindLastNode(t_mx2_AliasType* l_value);
  bbBool m_Empty();
  bbInt m_Count();
  void m_Clear();
  t_std_collections_List_1Tt_mx2_AliasType_2_BackwardsIterator m_Backwards();
  t_std_collections_List_1Tt_mx2_AliasType_2_Iterator m_All();
  t_std_collections_List_1Tt_mx2_AliasType_2_Node* m_AddLast(t_mx2_AliasType* l_value);
  t_std_collections_List_1Tt_mx2_AliasType_2_Node* m_AddFirst(t_mx2_AliasType* l_value);
  void m_AddAll(bbArray<bbGCVar<t_mx2_AliasType>>* l_values);
  void m_Add(t_mx2_AliasType* l_value);
};

struct t_std_collections_List_1Tt_mx2_FuncListType_2_Node : public bbObject{

  const char *typeName()const{return "t_std_collections_List_1Tt_mx2_FuncListType_2_Node";}

  bbGCVar<t_std_collections_List_1Tt_mx2_FuncListType_2_Node> m__0succ{};
  bbGCVar<t_std_collections_List_1Tt_mx2_FuncListType_2_Node> m__0pred{};
  bbGCVar<t_mx2_FuncListType> m__0value{};

  void gcMark();

  t_std_collections_List_1Tt_mx2_FuncListType_2_Node(t_mx2_FuncListType* l_value,t_std_collections_List_1Tt_mx2_FuncListType_2_Node* l_succ);
  t_std_collections_List_1Tt_mx2_FuncListType_2_Node(t_mx2_FuncListType* l_value);

  void m_Value(t_mx2_FuncListType* l_value);
  t_mx2_FuncListType* m_Value();
  t_std_collections_List_1Tt_mx2_FuncListType_2_Node* m_Succ();
  void m_Remove();
  t_std_collections_List_1Tt_mx2_FuncListType_2_Node* m_Pred();
  void m_InsertBefore(t_std_collections_List_1Tt_mx2_FuncListType_2_Node* l_node);
  void m_InsertAfter(t_std_collections_List_1Tt_mx2_FuncListType_2_Node* l_node);

  t_std_collections_List_1Tt_mx2_FuncListType_2_Node(){
  }
};

struct t_std_collections_List_1Tt_mx2_FuncListType_2_Iterator{
  const char *typeName()const{return "t_std_collections_List_1Tt_mx2_FuncListType_2_Iterator";}

  bbGCVar<t_std_collections_List_1Tt_mx2_FuncListType_2> m__0list{};
  bbGCVar<t_std_collections_List_1Tt_mx2_FuncListType_2_Node> m__0node{};
  bbInt m__0seq{};

  t_std_collections_List_1Tt_mx2_FuncListType_2_Iterator(t_std_collections_List_1Tt_mx2_FuncListType_2* l_list,t_std_collections_List_1Tt_mx2_FuncListType_2_Node* l_node);

  void m_Insert(t_mx2_FuncListType* l_value);
  void m_Erase();
  void m_Current(t_mx2_FuncListType* l_current);
  t_mx2_FuncListType* m_Current();
  void m_Bump();
  bbBool m_AtEnd();
  void m_AssertSeq();
  void m_AssertCurrent();

  t_std_collections_List_1Tt_mx2_FuncListType_2_Iterator(){
  }

  t_std_collections_List_1Tt_mx2_FuncListType_2_Iterator(bbNullCtor_t){
  }
};

int bbCompare(const t_std_collections_List_1Tt_mx2_FuncListType_2_Iterator&x,const t_std_collections_List_1Tt_mx2_FuncListType_2_Iterator&y);

void bbGCMark(const t_std_collections_List_1Tt_mx2_FuncListType_2_Iterator&);

struct t_std_collections_List_1Tt_mx2_FuncListType_2_BackwardsIterator{
  const char *typeName()const{return "t_std_collections_List_1Tt_mx2_FuncListType_2_BackwardsIterator";}

  bbGCVar<t_std_collections_List_1Tt_mx2_FuncListType_2> m__0list{};
  bbGCVar<t_std_collections_List_1Tt_mx2_FuncListType_2_Node> m__0node{};
  bbInt m__0seq{};

  t_std_collections_List_1Tt_mx2_FuncListType_2_BackwardsIterator(t_std_collections_List_1Tt_mx2_FuncListType_2* l_list,t_std_collections_List_1Tt_mx2_FuncListType_2_Node* l_node);

  void m_Insert(t_mx2_FuncListType* l_value);
  void m_Erase();
  void m_Current(t_mx2_FuncListType* l_current);
  t_mx2_FuncListType* m_Current();
  void m_Bump();
  bbBool m_AtEnd();
  void m_AssertSeq();
  void m_AssertCurrent();

  t_std_collections_List_1Tt_mx2_FuncListType_2_BackwardsIterator(){
  }

  t_std_collections_List_1Tt_mx2_FuncListType_2_BackwardsIterator(bbNullCtor_t){
  }
};

int bbCompare(const t_std_collections_List_1Tt_mx2_FuncListType_2_BackwardsIterator&x,const t_std_collections_List_1Tt_mx2_FuncListType_2_BackwardsIterator&y);

void bbGCMark(const t_std_collections_List_1Tt_mx2_FuncListType_2_BackwardsIterator&);

struct t_std_collections_List_1Tt_mx2_FuncListType_2 : public bbObject,public virtual t_std_collections_IContainer_1Tt_mx2_FuncListType_2{

  const char *typeName()const{return "t_std_collections_List_1Tt_mx2_FuncListType_2";}

  bbGCVar<t_std_collections_List_1Tt_mx2_FuncListType_2_Node> m__0head{};
  bbInt m__0seq{};

  void gcMark();

  t_std_collections_List_1Tt_mx2_FuncListType_2(t_std_collections_List_1Tt_mx2_FuncListType_2* l_values);
  t_std_collections_List_1Tt_mx2_FuncListType_2(t_std_collections_Stack_1Tt_mx2_FuncListType_2* l_values);
  t_std_collections_List_1Tt_mx2_FuncListType_2(bbArray<bbGCVar<t_mx2_FuncListType>>* l_values);
  t_std_collections_List_1Tt_mx2_FuncListType_2();

  bbArray<bbGCVar<t_mx2_FuncListType>>* m_ToArray();
  void m_Sort(bbFunction<bbInt(t_mx2_FuncListType*,t_mx2_FuncListType*)> l_compareFunc);
  void m_Sort(bbBool l_ascending);
  t_mx2_FuncListType* m_RemoveLast();
  bbBool m_RemoveLast(t_mx2_FuncListType* l_value);
  t_mx2_FuncListType* m_RemoveFirst();
  bbInt m_RemoveEach(t_mx2_FuncListType* l_value);
  bbBool m_Remove(t_mx2_FuncListType* l_value);
  t_std_collections_List_1Tt_mx2_FuncListType_2_Node* m_LastNode();
  t_mx2_FuncListType* m_Last();
  t_std_collections_List_1Tt_mx2_FuncListType_2_Node* m_HeadNode();
  t_std_collections_List_1Tt_mx2_FuncListType_2_Node* m_FirstNode();
  t_mx2_FuncListType* m_First();
  t_std_collections_List_1Tt_mx2_FuncListType_2_Node* m_FindNode(t_mx2_FuncListType* l_value);
  t_std_collections_List_1Tt_mx2_FuncListType_2_Node* m_FindLastNode(t_mx2_FuncListType* l_value);
  bbBool m_Empty();
  bbInt m_Count();
  void m_Clear();
  t_std_collections_List_1Tt_mx2_FuncListType_2_BackwardsIterator m_Backwards();
  t_std_collections_List_1Tt_mx2_FuncListType_2_Iterator m_All();
  t_std_collections_List_1Tt_mx2_FuncListType_2_Node* m_AddLast(t_mx2_FuncListType* l_value);
  t_std_collections_List_1Tt_mx2_FuncListType_2_Node* m_AddFirst(t_mx2_FuncListType* l_value);
  void m_AddAll(bbArray<bbGCVar<t_mx2_FuncListType>>* l_values);
  void m_Add(t_mx2_FuncListType* l_value);
};

struct t_std_collections_List_1Tt_mx2_Decl_2_Node : public bbObject{

  const char *typeName()const{return "t_std_collections_List_1Tt_mx2_Decl_2_Node";}

  bbGCVar<t_std_collections_List_1Tt_mx2_Decl_2_Node> m__0succ{};
  bbGCVar<t_std_collections_List_1Tt_mx2_Decl_2_Node> m__0pred{};
  bbGCVar<t_mx2_Decl> m__0value{};

  void gcMark();

  t_std_collections_List_1Tt_mx2_Decl_2_Node(t_mx2_Decl* l_value,t_std_collections_List_1Tt_mx2_Decl_2_Node* l_succ);
  t_std_collections_List_1Tt_mx2_Decl_2_Node(t_mx2_Decl* l_value);

  void m_Value(t_mx2_Decl* l_value);
  t_mx2_Decl* m_Value();
  t_std_collections_List_1Tt_mx2_Decl_2_Node* m_Succ();
  void m_Remove();
  t_std_collections_List_1Tt_mx2_Decl_2_Node* m_Pred();
  void m_InsertBefore(t_std_collections_List_1Tt_mx2_Decl_2_Node* l_node);
  void m_InsertAfter(t_std_collections_List_1Tt_mx2_Decl_2_Node* l_node);

  t_std_collections_List_1Tt_mx2_Decl_2_Node(){
  }
};

struct t_std_collections_List_1Tt_mx2_Decl_2_Iterator{
  const char *typeName()const{return "t_std_collections_List_1Tt_mx2_Decl_2_Iterator";}

  bbGCVar<t_std_collections_List_1Tt_mx2_Decl_2> m__0list{};
  bbGCVar<t_std_collections_List_1Tt_mx2_Decl_2_Node> m__0node{};
  bbInt m__0seq{};

  t_std_collections_List_1Tt_mx2_Decl_2_Iterator(t_std_collections_List_1Tt_mx2_Decl_2* l_list,t_std_collections_List_1Tt_mx2_Decl_2_Node* l_node);

  void m_Insert(t_mx2_Decl* l_value);
  void m_Erase();
  void m_Current(t_mx2_Decl* l_current);
  t_mx2_Decl* m_Current();
  void m_Bump();
  bbBool m_AtEnd();
  void m_AssertSeq();
  void m_AssertCurrent();

  t_std_collections_List_1Tt_mx2_Decl_2_Iterator(){
  }

  t_std_collections_List_1Tt_mx2_Decl_2_Iterator(bbNullCtor_t){
  }
};

int bbCompare(const t_std_collections_List_1Tt_mx2_Decl_2_Iterator&x,const t_std_collections_List_1Tt_mx2_Decl_2_Iterator&y);

void bbGCMark(const t_std_collections_List_1Tt_mx2_Decl_2_Iterator&);

struct t_std_collections_List_1Tt_mx2_Decl_2_BackwardsIterator{
  const char *typeName()const{return "t_std_collections_List_1Tt_mx2_Decl_2_BackwardsIterator";}

  bbGCVar<t_std_collections_List_1Tt_mx2_Decl_2> m__0list{};
  bbGCVar<t_std_collections_List_1Tt_mx2_Decl_2_Node> m__0node{};
  bbInt m__0seq{};

  t_std_collections_List_1Tt_mx2_Decl_2_BackwardsIterator(t_std_collections_List_1Tt_mx2_Decl_2* l_list,t_std_collections_List_1Tt_mx2_Decl_2_Node* l_node);

  void m_Insert(t_mx2_Decl* l_value);
  void m_Erase();
  void m_Current(t_mx2_Decl* l_current);
  t_mx2_Decl* m_Current();
  void m_Bump();
  bbBool m_AtEnd();
  void m_AssertSeq();
  void m_AssertCurrent();

  t_std_collections_List_1Tt_mx2_Decl_2_BackwardsIterator(){
  }

  t_std_collections_List_1Tt_mx2_Decl_2_BackwardsIterator(bbNullCtor_t){
  }
};

int bbCompare(const t_std_collections_List_1Tt_mx2_Decl_2_BackwardsIterator&x,const t_std_collections_List_1Tt_mx2_Decl_2_BackwardsIterator&y);

void bbGCMark(const t_std_collections_List_1Tt_mx2_Decl_2_BackwardsIterator&);

struct t_std_collections_List_1Tt_mx2_Decl_2 : public bbObject,public virtual t_std_collections_IContainer_1Tt_mx2_Decl_2{

  const char *typeName()const{return "t_std_collections_List_1Tt_mx2_Decl_2";}

  bbGCVar<t_std_collections_List_1Tt_mx2_Decl_2_Node> m__0head{};
  bbInt m__0seq{};

  void gcMark();

  t_std_collections_List_1Tt_mx2_Decl_2(t_std_collections_List_1Tt_mx2_Decl_2* l_values);
  t_std_collections_List_1Tt_mx2_Decl_2(t_std_collections_Stack_1Tt_mx2_Decl_2* l_values);
  t_std_collections_List_1Tt_mx2_Decl_2(bbArray<bbGCVar<t_mx2_Decl>>* l_values);
  t_std_collections_List_1Tt_mx2_Decl_2();

  bbArray<bbGCVar<t_mx2_Decl>>* m_ToArray();
  void m_Sort(bbFunction<bbInt(t_mx2_Decl*,t_mx2_Decl*)> l_compareFunc);
  void m_Sort(bbBool l_ascending);
  t_mx2_Decl* m_RemoveLast();
  bbBool m_RemoveLast(t_mx2_Decl* l_value);
  t_mx2_Decl* m_RemoveFirst();
  bbInt m_RemoveEach(t_mx2_Decl* l_value);
  bbBool m_Remove(t_mx2_Decl* l_value);
  t_std_collections_List_1Tt_mx2_Decl_2_Node* m_LastNode();
  t_mx2_Decl* m_Last();
  t_std_collections_List_1Tt_mx2_Decl_2_Node* m_HeadNode();
  t_std_collections_List_1Tt_mx2_Decl_2_Node* m_FirstNode();
  t_mx2_Decl* m_First();
  t_std_collections_List_1Tt_mx2_Decl_2_Node* m_FindNode(t_mx2_Decl* l_value);
  t_std_collections_List_1Tt_mx2_Decl_2_Node* m_FindLastNode(t_mx2_Decl* l_value);
  bbBool m_Empty();
  bbInt m_Count();
  void m_Clear();
  t_std_collections_List_1Tt_mx2_Decl_2_BackwardsIterator m_Backwards();
  t_std_collections_List_1Tt_mx2_Decl_2_Iterator m_All();
  t_std_collections_List_1Tt_mx2_Decl_2_Node* m_AddLast(t_mx2_Decl* l_value);
  t_std_collections_List_1Tt_mx2_Decl_2_Node* m_AddFirst(t_mx2_Decl* l_value);
  void m_AddAll(bbArray<bbGCVar<t_mx2_Decl>>* l_values);
  void m_Add(t_mx2_Decl* l_value);
};

struct t_std_collections_List_1Tt_mx2_ParseEx_2_Node : public bbObject{

  const char *typeName()const{return "t_std_collections_List_1Tt_mx2_ParseEx_2_Node";}

  bbGCVar<t_std_collections_List_1Tt_mx2_ParseEx_2_Node> m__0succ{};
  bbGCVar<t_std_collections_List_1Tt_mx2_ParseEx_2_Node> m__0pred{};
  bbGCVar<t_mx2_ParseEx> m__0value{};

  void gcMark();

  t_std_collections_List_1Tt_mx2_ParseEx_2_Node(t_mx2_ParseEx* l_value,t_std_collections_List_1Tt_mx2_ParseEx_2_Node* l_succ);
  t_std_collections_List_1Tt_mx2_ParseEx_2_Node(t_mx2_ParseEx* l_value);

  void m_Value(t_mx2_ParseEx* l_value);
  t_mx2_ParseEx* m_Value();
  t_std_collections_List_1Tt_mx2_ParseEx_2_Node* m_Succ();
  void m_Remove();
  t_std_collections_List_1Tt_mx2_ParseEx_2_Node* m_Pred();
  void m_InsertBefore(t_std_collections_List_1Tt_mx2_ParseEx_2_Node* l_node);
  void m_InsertAfter(t_std_collections_List_1Tt_mx2_ParseEx_2_Node* l_node);

  t_std_collections_List_1Tt_mx2_ParseEx_2_Node(){
  }
};

struct t_std_collections_List_1Tt_mx2_ParseEx_2_Iterator{
  const char *typeName()const{return "t_std_collections_List_1Tt_mx2_ParseEx_2_Iterator";}

  bbGCVar<t_std_collections_List_1Tt_mx2_ParseEx_2> m__0list{};
  bbGCVar<t_std_collections_List_1Tt_mx2_ParseEx_2_Node> m__0node{};
  bbInt m__0seq{};

  t_std_collections_List_1Tt_mx2_ParseEx_2_Iterator(t_std_collections_List_1Tt_mx2_ParseEx_2* l_list,t_std_collections_List_1Tt_mx2_ParseEx_2_Node* l_node);

  void m_Insert(t_mx2_ParseEx* l_value);
  void m_Erase();
  void m_Current(t_mx2_ParseEx* l_current);
  t_mx2_ParseEx* m_Current();
  void m_Bump();
  bbBool m_AtEnd();
  void m_AssertSeq();
  void m_AssertCurrent();

  t_std_collections_List_1Tt_mx2_ParseEx_2_Iterator(){
  }

  t_std_collections_List_1Tt_mx2_ParseEx_2_Iterator(bbNullCtor_t){
  }
};

int bbCompare(const t_std_collections_List_1Tt_mx2_ParseEx_2_Iterator&x,const t_std_collections_List_1Tt_mx2_ParseEx_2_Iterator&y);

void bbGCMark(const t_std_collections_List_1Tt_mx2_ParseEx_2_Iterator&);

struct t_std_collections_List_1Tt_mx2_ParseEx_2_BackwardsIterator{
  const char *typeName()const{return "t_std_collections_List_1Tt_mx2_ParseEx_2_BackwardsIterator";}

  bbGCVar<t_std_collections_List_1Tt_mx2_ParseEx_2> m__0list{};
  bbGCVar<t_std_collections_List_1Tt_mx2_ParseEx_2_Node> m__0node{};
  bbInt m__0seq{};

  t_std_collections_List_1Tt_mx2_ParseEx_2_BackwardsIterator(t_std_collections_List_1Tt_mx2_ParseEx_2* l_list,t_std_collections_List_1Tt_mx2_ParseEx_2_Node* l_node);

  void m_Insert(t_mx2_ParseEx* l_value);
  void m_Erase();
  void m_Current(t_mx2_ParseEx* l_current);
  t_mx2_ParseEx* m_Current();
  void m_Bump();
  bbBool m_AtEnd();
  void m_AssertSeq();
  void m_AssertCurrent();

  t_std_collections_List_1Tt_mx2_ParseEx_2_BackwardsIterator(){
  }

  t_std_collections_List_1Tt_mx2_ParseEx_2_BackwardsIterator(bbNullCtor_t){
  }
};

int bbCompare(const t_std_collections_List_1Tt_mx2_ParseEx_2_BackwardsIterator&x,const t_std_collections_List_1Tt_mx2_ParseEx_2_BackwardsIterator&y);

void bbGCMark(const t_std_collections_List_1Tt_mx2_ParseEx_2_BackwardsIterator&);

struct t_std_collections_List_1Tt_mx2_ParseEx_2 : public bbObject,public virtual t_std_collections_IContainer_1Tt_mx2_ParseEx_2{

  const char *typeName()const{return "t_std_collections_List_1Tt_mx2_ParseEx_2";}

  bbGCVar<t_std_collections_List_1Tt_mx2_ParseEx_2_Node> m__0head{};
  bbInt m__0seq{};

  void gcMark();

  t_std_collections_List_1Tt_mx2_ParseEx_2(t_std_collections_List_1Tt_mx2_ParseEx_2* l_values);
  t_std_collections_List_1Tt_mx2_ParseEx_2(t_std_collections_Stack_1Tt_mx2_ParseEx_2* l_values);
  t_std_collections_List_1Tt_mx2_ParseEx_2(bbArray<bbGCVar<t_mx2_ParseEx>>* l_values);
  t_std_collections_List_1Tt_mx2_ParseEx_2();

  bbArray<bbGCVar<t_mx2_ParseEx>>* m_ToArray();
  void m_Sort(bbFunction<bbInt(t_mx2_ParseEx*,t_mx2_ParseEx*)> l_compareFunc);
  void m_Sort(bbBool l_ascending);
  t_mx2_ParseEx* m_RemoveLast();
  bbBool m_RemoveLast(t_mx2_ParseEx* l_value);
  t_mx2_ParseEx* m_RemoveFirst();
  bbInt m_RemoveEach(t_mx2_ParseEx* l_value);
  bbBool m_Remove(t_mx2_ParseEx* l_value);
  t_std_collections_List_1Tt_mx2_ParseEx_2_Node* m_LastNode();
  t_mx2_ParseEx* m_Last();
  t_std_collections_List_1Tt_mx2_ParseEx_2_Node* m_HeadNode();
  t_std_collections_List_1Tt_mx2_ParseEx_2_Node* m_FirstNode();
  t_mx2_ParseEx* m_First();
  t_std_collections_List_1Tt_mx2_ParseEx_2_Node* m_FindNode(t_mx2_ParseEx* l_value);
  t_std_collections_List_1Tt_mx2_ParseEx_2_Node* m_FindLastNode(t_mx2_ParseEx* l_value);
  bbBool m_Empty();
  bbInt m_Count();
  void m_Clear();
  t_std_collections_List_1Tt_mx2_ParseEx_2_BackwardsIterator m_Backwards();
  t_std_collections_List_1Tt_mx2_ParseEx_2_Iterator m_All();
  t_std_collections_List_1Tt_mx2_ParseEx_2_Node* m_AddLast(t_mx2_ParseEx* l_value);
  t_std_collections_List_1Tt_mx2_ParseEx_2_Node* m_AddFirst(t_mx2_ParseEx* l_value);
  void m_AddAll(bbArray<bbGCVar<t_mx2_ParseEx>>* l_values);
  void m_Add(t_mx2_ParseEx* l_value);
};

struct t_std_collections_List_1Tt_mx2_Toker_2_Node : public bbObject{

  const char *typeName()const{return "t_std_collections_List_1Tt_mx2_Toker_2_Node";}

  bbGCVar<t_std_collections_List_1Tt_mx2_Toker_2_Node> m__0succ{};
  bbGCVar<t_std_collections_List_1Tt_mx2_Toker_2_Node> m__0pred{};
  bbGCVar<t_mx2_Toker> m__0value{};

  void gcMark();

  t_std_collections_List_1Tt_mx2_Toker_2_Node(t_mx2_Toker* l_value,t_std_collections_List_1Tt_mx2_Toker_2_Node* l_succ);
  t_std_collections_List_1Tt_mx2_Toker_2_Node(t_mx2_Toker* l_value);

  void m_Value(t_mx2_Toker* l_value);
  t_mx2_Toker* m_Value();
  t_std_collections_List_1Tt_mx2_Toker_2_Node* m_Succ();
  void m_Remove();
  t_std_collections_List_1Tt_mx2_Toker_2_Node* m_Pred();
  void m_InsertBefore(t_std_collections_List_1Tt_mx2_Toker_2_Node* l_node);
  void m_InsertAfter(t_std_collections_List_1Tt_mx2_Toker_2_Node* l_node);

  t_std_collections_List_1Tt_mx2_Toker_2_Node(){
  }
};

struct t_std_collections_List_1Tt_mx2_Toker_2_Iterator{
  const char *typeName()const{return "t_std_collections_List_1Tt_mx2_Toker_2_Iterator";}

  bbGCVar<t_std_collections_List_1Tt_mx2_Toker_2> m__0list{};
  bbGCVar<t_std_collections_List_1Tt_mx2_Toker_2_Node> m__0node{};
  bbInt m__0seq{};

  t_std_collections_List_1Tt_mx2_Toker_2_Iterator(t_std_collections_List_1Tt_mx2_Toker_2* l_list,t_std_collections_List_1Tt_mx2_Toker_2_Node* l_node);

  void m_Insert(t_mx2_Toker* l_value);
  void m_Erase();
  void m_Current(t_mx2_Toker* l_current);
  t_mx2_Toker* m_Current();
  void m_Bump();
  bbBool m_AtEnd();
  void m_AssertSeq();
  void m_AssertCurrent();

  t_std_collections_List_1Tt_mx2_Toker_2_Iterator(){
  }

  t_std_collections_List_1Tt_mx2_Toker_2_Iterator(bbNullCtor_t){
  }
};

int bbCompare(const t_std_collections_List_1Tt_mx2_Toker_2_Iterator&x,const t_std_collections_List_1Tt_mx2_Toker_2_Iterator&y);

void bbGCMark(const t_std_collections_List_1Tt_mx2_Toker_2_Iterator&);

struct t_std_collections_List_1Tt_mx2_Toker_2_BackwardsIterator{
  const char *typeName()const{return "t_std_collections_List_1Tt_mx2_Toker_2_BackwardsIterator";}

  bbGCVar<t_std_collections_List_1Tt_mx2_Toker_2> m__0list{};
  bbGCVar<t_std_collections_List_1Tt_mx2_Toker_2_Node> m__0node{};
  bbInt m__0seq{};

  t_std_collections_List_1Tt_mx2_Toker_2_BackwardsIterator(t_std_collections_List_1Tt_mx2_Toker_2* l_list,t_std_collections_List_1Tt_mx2_Toker_2_Node* l_node);

  void m_Insert(t_mx2_Toker* l_value);
  void m_Erase();
  void m_Current(t_mx2_Toker* l_current);
  t_mx2_Toker* m_Current();
  void m_Bump();
  bbBool m_AtEnd();
  void m_AssertSeq();
  void m_AssertCurrent();

  t_std_collections_List_1Tt_mx2_Toker_2_BackwardsIterator(){
  }

  t_std_collections_List_1Tt_mx2_Toker_2_BackwardsIterator(bbNullCtor_t){
  }
};

int bbCompare(const t_std_collections_List_1Tt_mx2_Toker_2_BackwardsIterator&x,const t_std_collections_List_1Tt_mx2_Toker_2_BackwardsIterator&y);

void bbGCMark(const t_std_collections_List_1Tt_mx2_Toker_2_BackwardsIterator&);

struct t_std_collections_List_1Tt_mx2_Toker_2 : public bbObject,public virtual t_std_collections_IContainer_1Tt_mx2_Toker_2{

  const char *typeName()const{return "t_std_collections_List_1Tt_mx2_Toker_2";}

  bbGCVar<t_std_collections_List_1Tt_mx2_Toker_2_Node> m__0head{};
  bbInt m__0seq{};

  void gcMark();

  t_std_collections_List_1Tt_mx2_Toker_2(t_std_collections_List_1Tt_mx2_Toker_2* l_values);
  t_std_collections_List_1Tt_mx2_Toker_2(t_std_collections_Stack_1Tt_mx2_Toker_2* l_values);
  t_std_collections_List_1Tt_mx2_Toker_2(bbArray<bbGCVar<t_mx2_Toker>>* l_values);
  t_std_collections_List_1Tt_mx2_Toker_2();

  bbArray<bbGCVar<t_mx2_Toker>>* m_ToArray();
  void m_Sort(bbFunction<bbInt(t_mx2_Toker*,t_mx2_Toker*)> l_compareFunc);
  void m_Sort(bbBool l_ascending);
  t_mx2_Toker* m_RemoveLast();
  bbBool m_RemoveLast(t_mx2_Toker* l_value);
  t_mx2_Toker* m_RemoveFirst();
  bbInt m_RemoveEach(t_mx2_Toker* l_value);
  bbBool m_Remove(t_mx2_Toker* l_value);
  t_std_collections_List_1Tt_mx2_Toker_2_Node* m_LastNode();
  t_mx2_Toker* m_Last();
  t_std_collections_List_1Tt_mx2_Toker_2_Node* m_HeadNode();
  t_std_collections_List_1Tt_mx2_Toker_2_Node* m_FirstNode();
  t_mx2_Toker* m_First();
  t_std_collections_List_1Tt_mx2_Toker_2_Node* m_FindNode(t_mx2_Toker* l_value);
  t_std_collections_List_1Tt_mx2_Toker_2_Node* m_FindLastNode(t_mx2_Toker* l_value);
  bbBool m_Empty();
  bbInt m_Count();
  void m_Clear();
  t_std_collections_List_1Tt_mx2_Toker_2_BackwardsIterator m_Backwards();
  t_std_collections_List_1Tt_mx2_Toker_2_Iterator m_All();
  t_std_collections_List_1Tt_mx2_Toker_2_Node* m_AddLast(t_mx2_Toker* l_value);
  t_std_collections_List_1Tt_mx2_Toker_2_Node* m_AddFirst(t_mx2_Toker* l_value);
  void m_AddAll(bbArray<bbGCVar<t_mx2_Toker>>* l_values);
  void m_Add(t_mx2_Toker* l_value);
};

struct t_std_collections_List_1Tt_mx2_Stmt_2_Node : public bbObject{

  const char *typeName()const{return "t_std_collections_List_1Tt_mx2_Stmt_2_Node";}

  bbGCVar<t_std_collections_List_1Tt_mx2_Stmt_2_Node> m__0succ{};
  bbGCVar<t_std_collections_List_1Tt_mx2_Stmt_2_Node> m__0pred{};
  bbGCVar<t_mx2_Stmt> m__0value{};

  void gcMark();

  t_std_collections_List_1Tt_mx2_Stmt_2_Node(t_mx2_Stmt* l_value,t_std_collections_List_1Tt_mx2_Stmt_2_Node* l_succ);
  t_std_collections_List_1Tt_mx2_Stmt_2_Node(t_mx2_Stmt* l_value);

  void m_Value(t_mx2_Stmt* l_value);
  t_mx2_Stmt* m_Value();
  t_std_collections_List_1Tt_mx2_Stmt_2_Node* m_Succ();
  void m_Remove();
  t_std_collections_List_1Tt_mx2_Stmt_2_Node* m_Pred();
  void m_InsertBefore(t_std_collections_List_1Tt_mx2_Stmt_2_Node* l_node);
  void m_InsertAfter(t_std_collections_List_1Tt_mx2_Stmt_2_Node* l_node);

  t_std_collections_List_1Tt_mx2_Stmt_2_Node(){
  }
};

struct t_std_collections_List_1Tt_mx2_Stmt_2_Iterator{
  const char *typeName()const{return "t_std_collections_List_1Tt_mx2_Stmt_2_Iterator";}

  bbGCVar<t_std_collections_List_1Tt_mx2_Stmt_2> m__0list{};
  bbGCVar<t_std_collections_List_1Tt_mx2_Stmt_2_Node> m__0node{};
  bbInt m__0seq{};

  t_std_collections_List_1Tt_mx2_Stmt_2_Iterator(t_std_collections_List_1Tt_mx2_Stmt_2* l_list,t_std_collections_List_1Tt_mx2_Stmt_2_Node* l_node);

  void m_Insert(t_mx2_Stmt* l_value);
  void m_Erase();
  void m_Current(t_mx2_Stmt* l_current);
  t_mx2_Stmt* m_Current();
  void m_Bump();
  bbBool m_AtEnd();
  void m_AssertSeq();
  void m_AssertCurrent();

  t_std_collections_List_1Tt_mx2_Stmt_2_Iterator(){
  }

  t_std_collections_List_1Tt_mx2_Stmt_2_Iterator(bbNullCtor_t){
  }
};

int bbCompare(const t_std_collections_List_1Tt_mx2_Stmt_2_Iterator&x,const t_std_collections_List_1Tt_mx2_Stmt_2_Iterator&y);

void bbGCMark(const t_std_collections_List_1Tt_mx2_Stmt_2_Iterator&);

struct t_std_collections_List_1Tt_mx2_Stmt_2_BackwardsIterator{
  const char *typeName()const{return "t_std_collections_List_1Tt_mx2_Stmt_2_BackwardsIterator";}

  bbGCVar<t_std_collections_List_1Tt_mx2_Stmt_2> m__0list{};
  bbGCVar<t_std_collections_List_1Tt_mx2_Stmt_2_Node> m__0node{};
  bbInt m__0seq{};

  t_std_collections_List_1Tt_mx2_Stmt_2_BackwardsIterator(t_std_collections_List_1Tt_mx2_Stmt_2* l_list,t_std_collections_List_1Tt_mx2_Stmt_2_Node* l_node);

  void m_Insert(t_mx2_Stmt* l_value);
  void m_Erase();
  void m_Current(t_mx2_Stmt* l_current);
  t_mx2_Stmt* m_Current();
  void m_Bump();
  bbBool m_AtEnd();
  void m_AssertSeq();
  void m_AssertCurrent();

  t_std_collections_List_1Tt_mx2_Stmt_2_BackwardsIterator(){
  }

  t_std_collections_List_1Tt_mx2_Stmt_2_BackwardsIterator(bbNullCtor_t){
  }
};

int bbCompare(const t_std_collections_List_1Tt_mx2_Stmt_2_BackwardsIterator&x,const t_std_collections_List_1Tt_mx2_Stmt_2_BackwardsIterator&y);

void bbGCMark(const t_std_collections_List_1Tt_mx2_Stmt_2_BackwardsIterator&);

struct t_std_collections_List_1Tt_mx2_Stmt_2 : public bbObject,public virtual t_std_collections_IContainer_1Tt_mx2_Stmt_2{

  const char *typeName()const{return "t_std_collections_List_1Tt_mx2_Stmt_2";}

  bbGCVar<t_std_collections_List_1Tt_mx2_Stmt_2_Node> m__0head{};
  bbInt m__0seq{};

  void gcMark();

  t_std_collections_List_1Tt_mx2_Stmt_2(t_std_collections_List_1Tt_mx2_Stmt_2* l_values);
  t_std_collections_List_1Tt_mx2_Stmt_2(t_std_collections_Stack_1Tt_mx2_Stmt_2* l_values);
  t_std_collections_List_1Tt_mx2_Stmt_2(bbArray<bbGCVar<t_mx2_Stmt>>* l_values);
  t_std_collections_List_1Tt_mx2_Stmt_2();

  bbArray<bbGCVar<t_mx2_Stmt>>* m_ToArray();
  void m_Sort(bbFunction<bbInt(t_mx2_Stmt*,t_mx2_Stmt*)> l_compareFunc);
  void m_Sort(bbBool l_ascending);
  t_mx2_Stmt* m_RemoveLast();
  bbBool m_RemoveLast(t_mx2_Stmt* l_value);
  t_mx2_Stmt* m_RemoveFirst();
  bbInt m_RemoveEach(t_mx2_Stmt* l_value);
  bbBool m_Remove(t_mx2_Stmt* l_value);
  t_std_collections_List_1Tt_mx2_Stmt_2_Node* m_LastNode();
  t_mx2_Stmt* m_Last();
  t_std_collections_List_1Tt_mx2_Stmt_2_Node* m_HeadNode();
  t_std_collections_List_1Tt_mx2_Stmt_2_Node* m_FirstNode();
  t_mx2_Stmt* m_First();
  t_std_collections_List_1Tt_mx2_Stmt_2_Node* m_FindNode(t_mx2_Stmt* l_value);
  t_std_collections_List_1Tt_mx2_Stmt_2_Node* m_FindLastNode(t_mx2_Stmt* l_value);
  bbBool m_Empty();
  bbInt m_Count();
  void m_Clear();
  t_std_collections_List_1Tt_mx2_Stmt_2_BackwardsIterator m_Backwards();
  t_std_collections_List_1Tt_mx2_Stmt_2_Iterator m_All();
  t_std_collections_List_1Tt_mx2_Stmt_2_Node* m_AddLast(t_mx2_Stmt* l_value);
  t_std_collections_List_1Tt_mx2_Stmt_2_Node* m_AddFirst(t_mx2_Stmt* l_value);
  void m_AddAll(bbArray<bbGCVar<t_mx2_Stmt>>* l_values);
  void m_Add(t_mx2_Stmt* l_value);
};

struct t_std_collections_List_1Tt_mx2_Translator_GCTmp_2_Node : public bbObject{

  const char *typeName()const{return "t_std_collections_List_1Tt_mx2_Translator_GCTmp_2_Node";}

  bbGCVar<t_std_collections_List_1Tt_mx2_Translator_GCTmp_2_Node> m__0succ{};
  bbGCVar<t_std_collections_List_1Tt_mx2_Translator_GCTmp_2_Node> m__0pred{};
  bbGCVar<t_mx2_Translator_GCTmp> m__0value{};

  void gcMark();

  t_std_collections_List_1Tt_mx2_Translator_GCTmp_2_Node(t_mx2_Translator_GCTmp* l_value,t_std_collections_List_1Tt_mx2_Translator_GCTmp_2_Node* l_succ);
  t_std_collections_List_1Tt_mx2_Translator_GCTmp_2_Node(t_mx2_Translator_GCTmp* l_value);

  void m_Value(t_mx2_Translator_GCTmp* l_value);
  t_mx2_Translator_GCTmp* m_Value();
  t_std_collections_List_1Tt_mx2_Translator_GCTmp_2_Node* m_Succ();
  void m_Remove();
  t_std_collections_List_1Tt_mx2_Translator_GCTmp_2_Node* m_Pred();
  void m_InsertBefore(t_std_collections_List_1Tt_mx2_Translator_GCTmp_2_Node* l_node);
  void m_InsertAfter(t_std_collections_List_1Tt_mx2_Translator_GCTmp_2_Node* l_node);

  t_std_collections_List_1Tt_mx2_Translator_GCTmp_2_Node(){
  }
};

struct t_std_collections_List_1Tt_mx2_Translator_GCTmp_2_Iterator{
  const char *typeName()const{return "t_std_collections_List_1Tt_mx2_Translator_GCTmp_2_Iterator";}

  bbGCVar<t_std_collections_List_1Tt_mx2_Translator_GCTmp_2> m__0list{};
  bbGCVar<t_std_collections_List_1Tt_mx2_Translator_GCTmp_2_Node> m__0node{};
  bbInt m__0seq{};

  t_std_collections_List_1Tt_mx2_Translator_GCTmp_2_Iterator(t_std_collections_List_1Tt_mx2_Translator_GCTmp_2* l_list,t_std_collections_List_1Tt_mx2_Translator_GCTmp_2_Node* l_node);

  void m_Insert(t_mx2_Translator_GCTmp* l_value);
  void m_Erase();
  void m_Current(t_mx2_Translator_GCTmp* l_current);
  t_mx2_Translator_GCTmp* m_Current();
  void m_Bump();
  bbBool m_AtEnd();
  void m_AssertSeq();
  void m_AssertCurrent();

  t_std_collections_List_1Tt_mx2_Translator_GCTmp_2_Iterator(){
  }

  t_std_collections_List_1Tt_mx2_Translator_GCTmp_2_Iterator(bbNullCtor_t){
  }
};

int bbCompare(const t_std_collections_List_1Tt_mx2_Translator_GCTmp_2_Iterator&x,const t_std_collections_List_1Tt_mx2_Translator_GCTmp_2_Iterator&y);

void bbGCMark(const t_std_collections_List_1Tt_mx2_Translator_GCTmp_2_Iterator&);

struct t_std_collections_List_1Tt_mx2_Translator_GCTmp_2_BackwardsIterator{
  const char *typeName()const{return "t_std_collections_List_1Tt_mx2_Translator_GCTmp_2_BackwardsIterator";}

  bbGCVar<t_std_collections_List_1Tt_mx2_Translator_GCTmp_2> m__0list{};
  bbGCVar<t_std_collections_List_1Tt_mx2_Translator_GCTmp_2_Node> m__0node{};
  bbInt m__0seq{};

  t_std_collections_List_1Tt_mx2_Translator_GCTmp_2_BackwardsIterator(t_std_collections_List_1Tt_mx2_Translator_GCTmp_2* l_list,t_std_collections_List_1Tt_mx2_Translator_GCTmp_2_Node* l_node);

  void m_Insert(t_mx2_Translator_GCTmp* l_value);
  void m_Erase();
  void m_Current(t_mx2_Translator_GCTmp* l_current);
  t_mx2_Translator_GCTmp* m_Current();
  void m_Bump();
  bbBool m_AtEnd();
  void m_AssertSeq();
  void m_AssertCurrent();

  t_std_collections_List_1Tt_mx2_Translator_GCTmp_2_BackwardsIterator(){
  }

  t_std_collections_List_1Tt_mx2_Translator_GCTmp_2_BackwardsIterator(bbNullCtor_t){
  }
};

int bbCompare(const t_std_collections_List_1Tt_mx2_Translator_GCTmp_2_BackwardsIterator&x,const t_std_collections_List_1Tt_mx2_Translator_GCTmp_2_BackwardsIterator&y);

void bbGCMark(const t_std_collections_List_1Tt_mx2_Translator_GCTmp_2_BackwardsIterator&);

struct t_std_collections_List_1Tt_mx2_Translator_GCTmp_2 : public bbObject,public virtual t_std_collections_IContainer_1Tt_mx2_Translator_GCTmp_2{

  const char *typeName()const{return "t_std_collections_List_1Tt_mx2_Translator_GCTmp_2";}

  bbGCVar<t_std_collections_List_1Tt_mx2_Translator_GCTmp_2_Node> m__0head{};
  bbInt m__0seq{};

  void gcMark();

  t_std_collections_List_1Tt_mx2_Translator_GCTmp_2(t_std_collections_List_1Tt_mx2_Translator_GCTmp_2* l_values);
  t_std_collections_List_1Tt_mx2_Translator_GCTmp_2(t_std_collections_Stack_1Tt_mx2_Translator_GCTmp_2* l_values);
  t_std_collections_List_1Tt_mx2_Translator_GCTmp_2(bbArray<bbGCVar<t_mx2_Translator_GCTmp>>* l_values);
  t_std_collections_List_1Tt_mx2_Translator_GCTmp_2();

  bbArray<bbGCVar<t_mx2_Translator_GCTmp>>* m_ToArray();
  void m_Sort(bbFunction<bbInt(t_mx2_Translator_GCTmp*,t_mx2_Translator_GCTmp*)> l_compareFunc);
  void m_Sort(bbBool l_ascending);
  t_mx2_Translator_GCTmp* m_RemoveLast();
  bbBool m_RemoveLast(t_mx2_Translator_GCTmp* l_value);
  t_mx2_Translator_GCTmp* m_RemoveFirst();
  bbInt m_RemoveEach(t_mx2_Translator_GCTmp* l_value);
  bbBool m_Remove(t_mx2_Translator_GCTmp* l_value);
  t_std_collections_List_1Tt_mx2_Translator_GCTmp_2_Node* m_LastNode();
  t_mx2_Translator_GCTmp* m_Last();
  t_std_collections_List_1Tt_mx2_Translator_GCTmp_2_Node* m_HeadNode();
  t_std_collections_List_1Tt_mx2_Translator_GCTmp_2_Node* m_FirstNode();
  t_mx2_Translator_GCTmp* m_First();
  t_std_collections_List_1Tt_mx2_Translator_GCTmp_2_Node* m_FindNode(t_mx2_Translator_GCTmp* l_value);
  t_std_collections_List_1Tt_mx2_Translator_GCTmp_2_Node* m_FindLastNode(t_mx2_Translator_GCTmp* l_value);
  bbBool m_Empty();
  bbInt m_Count();
  void m_Clear();
  t_std_collections_List_1Tt_mx2_Translator_GCTmp_2_BackwardsIterator m_Backwards();
  t_std_collections_List_1Tt_mx2_Translator_GCTmp_2_Iterator m_All();
  t_std_collections_List_1Tt_mx2_Translator_GCTmp_2_Node* m_AddLast(t_mx2_Translator_GCTmp* l_value);
  t_std_collections_List_1Tt_mx2_Translator_GCTmp_2_Node* m_AddFirst(t_mx2_Translator_GCTmp* l_value);
  void m_AddAll(bbArray<bbGCVar<t_mx2_Translator_GCTmp>>* l_values);
  void m_Add(t_mx2_Translator_GCTmp* l_value);
};

struct t_std_collections_List_1Tt_mx2_TypeExpr_2_Node : public bbObject{

  const char *typeName()const{return "t_std_collections_List_1Tt_mx2_TypeExpr_2_Node";}

  bbGCVar<t_std_collections_List_1Tt_mx2_TypeExpr_2_Node> m__0succ{};
  bbGCVar<t_std_collections_List_1Tt_mx2_TypeExpr_2_Node> m__0pred{};
  bbGCVar<t_mx2_TypeExpr> m__0value{};

  void gcMark();

  t_std_collections_List_1Tt_mx2_TypeExpr_2_Node(t_mx2_TypeExpr* l_value,t_std_collections_List_1Tt_mx2_TypeExpr_2_Node* l_succ);
  t_std_collections_List_1Tt_mx2_TypeExpr_2_Node(t_mx2_TypeExpr* l_value);

  void m_Value(t_mx2_TypeExpr* l_value);
  t_mx2_TypeExpr* m_Value();
  t_std_collections_List_1Tt_mx2_TypeExpr_2_Node* m_Succ();
  void m_Remove();
  t_std_collections_List_1Tt_mx2_TypeExpr_2_Node* m_Pred();
  void m_InsertBefore(t_std_collections_List_1Tt_mx2_TypeExpr_2_Node* l_node);
  void m_InsertAfter(t_std_collections_List_1Tt_mx2_TypeExpr_2_Node* l_node);

  t_std_collections_List_1Tt_mx2_TypeExpr_2_Node(){
  }
};

struct t_std_collections_List_1Tt_mx2_TypeExpr_2_Iterator{
  const char *typeName()const{return "t_std_collections_List_1Tt_mx2_TypeExpr_2_Iterator";}

  bbGCVar<t_std_collections_List_1Tt_mx2_TypeExpr_2> m__0list{};
  bbGCVar<t_std_collections_List_1Tt_mx2_TypeExpr_2_Node> m__0node{};
  bbInt m__0seq{};

  t_std_collections_List_1Tt_mx2_TypeExpr_2_Iterator(t_std_collections_List_1Tt_mx2_TypeExpr_2* l_list,t_std_collections_List_1Tt_mx2_TypeExpr_2_Node* l_node);

  void m_Insert(t_mx2_TypeExpr* l_value);
  void m_Erase();
  void m_Current(t_mx2_TypeExpr* l_current);
  t_mx2_TypeExpr* m_Current();
  void m_Bump();
  bbBool m_AtEnd();
  void m_AssertSeq();
  void m_AssertCurrent();

  t_std_collections_List_1Tt_mx2_TypeExpr_2_Iterator(){
  }

  t_std_collections_List_1Tt_mx2_TypeExpr_2_Iterator(bbNullCtor_t){
  }
};

int bbCompare(const t_std_collections_List_1Tt_mx2_TypeExpr_2_Iterator&x,const t_std_collections_List_1Tt_mx2_TypeExpr_2_Iterator&y);

void bbGCMark(const t_std_collections_List_1Tt_mx2_TypeExpr_2_Iterator&);

struct t_std_collections_List_1Tt_mx2_TypeExpr_2_BackwardsIterator{
  const char *typeName()const{return "t_std_collections_List_1Tt_mx2_TypeExpr_2_BackwardsIterator";}

  bbGCVar<t_std_collections_List_1Tt_mx2_TypeExpr_2> m__0list{};
  bbGCVar<t_std_collections_List_1Tt_mx2_TypeExpr_2_Node> m__0node{};
  bbInt m__0seq{};

  t_std_collections_List_1Tt_mx2_TypeExpr_2_BackwardsIterator(t_std_collections_List_1Tt_mx2_TypeExpr_2* l_list,t_std_collections_List_1Tt_mx2_TypeExpr_2_Node* l_node);

  void m_Insert(t_mx2_TypeExpr* l_value);
  void m_Erase();
  void m_Current(t_mx2_TypeExpr* l_current);
  t_mx2_TypeExpr* m_Current();
  void m_Bump();
  bbBool m_AtEnd();
  void m_AssertSeq();
  void m_AssertCurrent();

  t_std_collections_List_1Tt_mx2_TypeExpr_2_BackwardsIterator(){
  }

  t_std_collections_List_1Tt_mx2_TypeExpr_2_BackwardsIterator(bbNullCtor_t){
  }
};

int bbCompare(const t_std_collections_List_1Tt_mx2_TypeExpr_2_BackwardsIterator&x,const t_std_collections_List_1Tt_mx2_TypeExpr_2_BackwardsIterator&y);

void bbGCMark(const t_std_collections_List_1Tt_mx2_TypeExpr_2_BackwardsIterator&);

struct t_std_collections_List_1Tt_mx2_TypeExpr_2 : public bbObject,public virtual t_std_collections_IContainer_1Tt_mx2_TypeExpr_2{

  const char *typeName()const{return "t_std_collections_List_1Tt_mx2_TypeExpr_2";}

  bbGCVar<t_std_collections_List_1Tt_mx2_TypeExpr_2_Node> m__0head{};
  bbInt m__0seq{};

  void gcMark();

  t_std_collections_List_1Tt_mx2_TypeExpr_2(t_std_collections_List_1Tt_mx2_TypeExpr_2* l_values);
  t_std_collections_List_1Tt_mx2_TypeExpr_2(t_std_collections_Stack_1Tt_mx2_TypeExpr_2* l_values);
  t_std_collections_List_1Tt_mx2_TypeExpr_2(bbArray<bbGCVar<t_mx2_TypeExpr>>* l_values);
  t_std_collections_List_1Tt_mx2_TypeExpr_2();

  bbArray<bbGCVar<t_mx2_TypeExpr>>* m_ToArray();
  void m_Sort(bbFunction<bbInt(t_mx2_TypeExpr*,t_mx2_TypeExpr*)> l_compareFunc);
  void m_Sort(bbBool l_ascending);
  t_mx2_TypeExpr* m_RemoveLast();
  bbBool m_RemoveLast(t_mx2_TypeExpr* l_value);
  t_mx2_TypeExpr* m_RemoveFirst();
  bbInt m_RemoveEach(t_mx2_TypeExpr* l_value);
  bbBool m_Remove(t_mx2_TypeExpr* l_value);
  t_std_collections_List_1Tt_mx2_TypeExpr_2_Node* m_LastNode();
  t_mx2_TypeExpr* m_Last();
  t_std_collections_List_1Tt_mx2_TypeExpr_2_Node* m_HeadNode();
  t_std_collections_List_1Tt_mx2_TypeExpr_2_Node* m_FirstNode();
  t_mx2_TypeExpr* m_First();
  t_std_collections_List_1Tt_mx2_TypeExpr_2_Node* m_FindNode(t_mx2_TypeExpr* l_value);
  t_std_collections_List_1Tt_mx2_TypeExpr_2_Node* m_FindLastNode(t_mx2_TypeExpr* l_value);
  bbBool m_Empty();
  bbInt m_Count();
  void m_Clear();
  t_std_collections_List_1Tt_mx2_TypeExpr_2_BackwardsIterator m_Backwards();
  t_std_collections_List_1Tt_mx2_TypeExpr_2_Iterator m_All();
  t_std_collections_List_1Tt_mx2_TypeExpr_2_Node* m_AddLast(t_mx2_TypeExpr* l_value);
  t_std_collections_List_1Tt_mx2_TypeExpr_2_Node* m_AddFirst(t_mx2_TypeExpr* l_value);
  void m_AddAll(bbArray<bbGCVar<t_mx2_TypeExpr>>* l_values);
  void m_Add(t_mx2_TypeExpr* l_value);
};

struct t_std_collections_List_1Tt_mx2_CatchExpr_2_Node : public bbObject{

  const char *typeName()const{return "t_std_collections_List_1Tt_mx2_CatchExpr_2_Node";}

  bbGCVar<t_std_collections_List_1Tt_mx2_CatchExpr_2_Node> m__0succ{};
  bbGCVar<t_std_collections_List_1Tt_mx2_CatchExpr_2_Node> m__0pred{};
  bbGCVar<t_mx2_CatchExpr> m__0value{};

  void gcMark();

  t_std_collections_List_1Tt_mx2_CatchExpr_2_Node(t_mx2_CatchExpr* l_value,t_std_collections_List_1Tt_mx2_CatchExpr_2_Node* l_succ);
  t_std_collections_List_1Tt_mx2_CatchExpr_2_Node(t_mx2_CatchExpr* l_value);

  void m_Value(t_mx2_CatchExpr* l_value);
  t_mx2_CatchExpr* m_Value();
  t_std_collections_List_1Tt_mx2_CatchExpr_2_Node* m_Succ();
  void m_Remove();
  t_std_collections_List_1Tt_mx2_CatchExpr_2_Node* m_Pred();
  void m_InsertBefore(t_std_collections_List_1Tt_mx2_CatchExpr_2_Node* l_node);
  void m_InsertAfter(t_std_collections_List_1Tt_mx2_CatchExpr_2_Node* l_node);

  t_std_collections_List_1Tt_mx2_CatchExpr_2_Node(){
  }
};

struct t_std_collections_List_1Tt_mx2_CatchExpr_2_Iterator{
  const char *typeName()const{return "t_std_collections_List_1Tt_mx2_CatchExpr_2_Iterator";}

  bbGCVar<t_std_collections_List_1Tt_mx2_CatchExpr_2> m__0list{};
  bbGCVar<t_std_collections_List_1Tt_mx2_CatchExpr_2_Node> m__0node{};
  bbInt m__0seq{};

  t_std_collections_List_1Tt_mx2_CatchExpr_2_Iterator(t_std_collections_List_1Tt_mx2_CatchExpr_2* l_list,t_std_collections_List_1Tt_mx2_CatchExpr_2_Node* l_node);

  void m_Insert(t_mx2_CatchExpr* l_value);
  void m_Erase();
  void m_Current(t_mx2_CatchExpr* l_current);
  t_mx2_CatchExpr* m_Current();
  void m_Bump();
  bbBool m_AtEnd();
  void m_AssertSeq();
  void m_AssertCurrent();

  t_std_collections_List_1Tt_mx2_CatchExpr_2_Iterator(){
  }

  t_std_collections_List_1Tt_mx2_CatchExpr_2_Iterator(bbNullCtor_t){
  }
};

int bbCompare(const t_std_collections_List_1Tt_mx2_CatchExpr_2_Iterator&x,const t_std_collections_List_1Tt_mx2_CatchExpr_2_Iterator&y);

void bbGCMark(const t_std_collections_List_1Tt_mx2_CatchExpr_2_Iterator&);

struct t_std_collections_List_1Tt_mx2_CatchExpr_2_BackwardsIterator{
  const char *typeName()const{return "t_std_collections_List_1Tt_mx2_CatchExpr_2_BackwardsIterator";}

  bbGCVar<t_std_collections_List_1Tt_mx2_CatchExpr_2> m__0list{};
  bbGCVar<t_std_collections_List_1Tt_mx2_CatchExpr_2_Node> m__0node{};
  bbInt m__0seq{};

  t_std_collections_List_1Tt_mx2_CatchExpr_2_BackwardsIterator(t_std_collections_List_1Tt_mx2_CatchExpr_2* l_list,t_std_collections_List_1Tt_mx2_CatchExpr_2_Node* l_node);

  void m_Insert(t_mx2_CatchExpr* l_value);
  void m_Erase();
  void m_Current(t_mx2_CatchExpr* l_current);
  t_mx2_CatchExpr* m_Current();
  void m_Bump();
  bbBool m_AtEnd();
  void m_AssertSeq();
  void m_AssertCurrent();

  t_std_collections_List_1Tt_mx2_CatchExpr_2_BackwardsIterator(){
  }

  t_std_collections_List_1Tt_mx2_CatchExpr_2_BackwardsIterator(bbNullCtor_t){
  }
};

int bbCompare(const t_std_collections_List_1Tt_mx2_CatchExpr_2_BackwardsIterator&x,const t_std_collections_List_1Tt_mx2_CatchExpr_2_BackwardsIterator&y);

void bbGCMark(const t_std_collections_List_1Tt_mx2_CatchExpr_2_BackwardsIterator&);

struct t_std_collections_List_1Tt_mx2_CatchExpr_2 : public bbObject,public virtual t_std_collections_IContainer_1Tt_mx2_CatchExpr_2{

  const char *typeName()const{return "t_std_collections_List_1Tt_mx2_CatchExpr_2";}

  bbGCVar<t_std_collections_List_1Tt_mx2_CatchExpr_2_Node> m__0head{};
  bbInt m__0seq{};

  void gcMark();

  t_std_collections_List_1Tt_mx2_CatchExpr_2(t_std_collections_List_1Tt_mx2_CatchExpr_2* l_values);
  t_std_collections_List_1Tt_mx2_CatchExpr_2(t_std_collections_Stack_1Tt_mx2_CatchExpr_2* l_values);
  t_std_collections_List_1Tt_mx2_CatchExpr_2(bbArray<bbGCVar<t_mx2_CatchExpr>>* l_values);
  t_std_collections_List_1Tt_mx2_CatchExpr_2();

  bbArray<bbGCVar<t_mx2_CatchExpr>>* m_ToArray();
  void m_Sort(bbFunction<bbInt(t_mx2_CatchExpr*,t_mx2_CatchExpr*)> l_compareFunc);
  void m_Sort(bbBool l_ascending);
  t_mx2_CatchExpr* m_RemoveLast();
  bbBool m_RemoveLast(t_mx2_CatchExpr* l_value);
  t_mx2_CatchExpr* m_RemoveFirst();
  bbInt m_RemoveEach(t_mx2_CatchExpr* l_value);
  bbBool m_Remove(t_mx2_CatchExpr* l_value);
  t_std_collections_List_1Tt_mx2_CatchExpr_2_Node* m_LastNode();
  t_mx2_CatchExpr* m_Last();
  t_std_collections_List_1Tt_mx2_CatchExpr_2_Node* m_HeadNode();
  t_std_collections_List_1Tt_mx2_CatchExpr_2_Node* m_FirstNode();
  t_mx2_CatchExpr* m_First();
  t_std_collections_List_1Tt_mx2_CatchExpr_2_Node* m_FindNode(t_mx2_CatchExpr* l_value);
  t_std_collections_List_1Tt_mx2_CatchExpr_2_Node* m_FindLastNode(t_mx2_CatchExpr* l_value);
  bbBool m_Empty();
  bbInt m_Count();
  void m_Clear();
  t_std_collections_List_1Tt_mx2_CatchExpr_2_BackwardsIterator m_Backwards();
  t_std_collections_List_1Tt_mx2_CatchExpr_2_Iterator m_All();
  t_std_collections_List_1Tt_mx2_CatchExpr_2_Node* m_AddLast(t_mx2_CatchExpr* l_value);
  t_std_collections_List_1Tt_mx2_CatchExpr_2_Node* m_AddFirst(t_mx2_CatchExpr* l_value);
  void m_AddAll(bbArray<bbGCVar<t_mx2_CatchExpr>>* l_values);
  void m_Add(t_mx2_CatchExpr* l_value);
};

struct t_std_collections_List_1Tt_mx2_StmtExpr_2_Node : public bbObject{

  const char *typeName()const{return "t_std_collections_List_1Tt_mx2_StmtExpr_2_Node";}

  bbGCVar<t_std_collections_List_1Tt_mx2_StmtExpr_2_Node> m__0succ{};
  bbGCVar<t_std_collections_List_1Tt_mx2_StmtExpr_2_Node> m__0pred{};
  bbGCVar<t_mx2_StmtExpr> m__0value{};

  void gcMark();

  t_std_collections_List_1Tt_mx2_StmtExpr_2_Node(t_mx2_StmtExpr* l_value,t_std_collections_List_1Tt_mx2_StmtExpr_2_Node* l_succ);
  t_std_collections_List_1Tt_mx2_StmtExpr_2_Node(t_mx2_StmtExpr* l_value);

  void m_Value(t_mx2_StmtExpr* l_value);
  t_mx2_StmtExpr* m_Value();
  t_std_collections_List_1Tt_mx2_StmtExpr_2_Node* m_Succ();
  void m_Remove();
  t_std_collections_List_1Tt_mx2_StmtExpr_2_Node* m_Pred();
  void m_InsertBefore(t_std_collections_List_1Tt_mx2_StmtExpr_2_Node* l_node);
  void m_InsertAfter(t_std_collections_List_1Tt_mx2_StmtExpr_2_Node* l_node);

  t_std_collections_List_1Tt_mx2_StmtExpr_2_Node(){
  }
};

struct t_std_collections_List_1Tt_mx2_StmtExpr_2_Iterator{
  const char *typeName()const{return "t_std_collections_List_1Tt_mx2_StmtExpr_2_Iterator";}

  bbGCVar<t_std_collections_List_1Tt_mx2_StmtExpr_2> m__0list{};
  bbGCVar<t_std_collections_List_1Tt_mx2_StmtExpr_2_Node> m__0node{};
  bbInt m__0seq{};

  t_std_collections_List_1Tt_mx2_StmtExpr_2_Iterator(t_std_collections_List_1Tt_mx2_StmtExpr_2* l_list,t_std_collections_List_1Tt_mx2_StmtExpr_2_Node* l_node);

  void m_Insert(t_mx2_StmtExpr* l_value);
  void m_Erase();
  void m_Current(t_mx2_StmtExpr* l_current);
  t_mx2_StmtExpr* m_Current();
  void m_Bump();
  bbBool m_AtEnd();
  void m_AssertSeq();
  void m_AssertCurrent();

  t_std_collections_List_1Tt_mx2_StmtExpr_2_Iterator(){
  }

  t_std_collections_List_1Tt_mx2_StmtExpr_2_Iterator(bbNullCtor_t){
  }
};

int bbCompare(const t_std_collections_List_1Tt_mx2_StmtExpr_2_Iterator&x,const t_std_collections_List_1Tt_mx2_StmtExpr_2_Iterator&y);

void bbGCMark(const t_std_collections_List_1Tt_mx2_StmtExpr_2_Iterator&);

struct t_std_collections_List_1Tt_mx2_StmtExpr_2_BackwardsIterator{
  const char *typeName()const{return "t_std_collections_List_1Tt_mx2_StmtExpr_2_BackwardsIterator";}

  bbGCVar<t_std_collections_List_1Tt_mx2_StmtExpr_2> m__0list{};
  bbGCVar<t_std_collections_List_1Tt_mx2_StmtExpr_2_Node> m__0node{};
  bbInt m__0seq{};

  t_std_collections_List_1Tt_mx2_StmtExpr_2_BackwardsIterator(t_std_collections_List_1Tt_mx2_StmtExpr_2* l_list,t_std_collections_List_1Tt_mx2_StmtExpr_2_Node* l_node);

  void m_Insert(t_mx2_StmtExpr* l_value);
  void m_Erase();
  void m_Current(t_mx2_StmtExpr* l_current);
  t_mx2_StmtExpr* m_Current();
  void m_Bump();
  bbBool m_AtEnd();
  void m_AssertSeq();
  void m_AssertCurrent();

  t_std_collections_List_1Tt_mx2_StmtExpr_2_BackwardsIterator(){
  }

  t_std_collections_List_1Tt_mx2_StmtExpr_2_BackwardsIterator(bbNullCtor_t){
  }
};

int bbCompare(const t_std_collections_List_1Tt_mx2_StmtExpr_2_BackwardsIterator&x,const t_std_collections_List_1Tt_mx2_StmtExpr_2_BackwardsIterator&y);

void bbGCMark(const t_std_collections_List_1Tt_mx2_StmtExpr_2_BackwardsIterator&);

struct t_std_collections_List_1Tt_mx2_StmtExpr_2 : public bbObject,public virtual t_std_collections_IContainer_1Tt_mx2_StmtExpr_2{

  const char *typeName()const{return "t_std_collections_List_1Tt_mx2_StmtExpr_2";}

  bbGCVar<t_std_collections_List_1Tt_mx2_StmtExpr_2_Node> m__0head{};
  bbInt m__0seq{};

  void gcMark();

  t_std_collections_List_1Tt_mx2_StmtExpr_2(t_std_collections_List_1Tt_mx2_StmtExpr_2* l_values);
  t_std_collections_List_1Tt_mx2_StmtExpr_2(t_std_collections_Stack_1Tt_mx2_StmtExpr_2* l_values);
  t_std_collections_List_1Tt_mx2_StmtExpr_2(bbArray<bbGCVar<t_mx2_StmtExpr>>* l_values);
  t_std_collections_List_1Tt_mx2_StmtExpr_2();

  bbArray<bbGCVar<t_mx2_StmtExpr>>* m_ToArray();
  void m_Sort(bbFunction<bbInt(t_mx2_StmtExpr*,t_mx2_StmtExpr*)> l_compareFunc);
  void m_Sort(bbBool l_ascending);
  t_mx2_StmtExpr* m_RemoveLast();
  bbBool m_RemoveLast(t_mx2_StmtExpr* l_value);
  t_mx2_StmtExpr* m_RemoveFirst();
  bbInt m_RemoveEach(t_mx2_StmtExpr* l_value);
  bbBool m_Remove(t_mx2_StmtExpr* l_value);
  t_std_collections_List_1Tt_mx2_StmtExpr_2_Node* m_LastNode();
  t_mx2_StmtExpr* m_Last();
  t_std_collections_List_1Tt_mx2_StmtExpr_2_Node* m_HeadNode();
  t_std_collections_List_1Tt_mx2_StmtExpr_2_Node* m_FirstNode();
  t_mx2_StmtExpr* m_First();
  t_std_collections_List_1Tt_mx2_StmtExpr_2_Node* m_FindNode(t_mx2_StmtExpr* l_value);
  t_std_collections_List_1Tt_mx2_StmtExpr_2_Node* m_FindLastNode(t_mx2_StmtExpr* l_value);
  bbBool m_Empty();
  bbInt m_Count();
  void m_Clear();
  t_std_collections_List_1Tt_mx2_StmtExpr_2_BackwardsIterator m_Backwards();
  t_std_collections_List_1Tt_mx2_StmtExpr_2_Iterator m_All();
  t_std_collections_List_1Tt_mx2_StmtExpr_2_Node* m_AddLast(t_mx2_StmtExpr* l_value);
  t_std_collections_List_1Tt_mx2_StmtExpr_2_Node* m_AddFirst(t_mx2_StmtExpr* l_value);
  void m_AddAll(bbArray<bbGCVar<t_mx2_StmtExpr>>* l_values);
  void m_Add(t_mx2_StmtExpr* l_value);
};

struct t_std_collections_List_1Tt_mx2_CaseExpr_2_Node : public bbObject{

  const char *typeName()const{return "t_std_collections_List_1Tt_mx2_CaseExpr_2_Node";}

  bbGCVar<t_std_collections_List_1Tt_mx2_CaseExpr_2_Node> m__0succ{};
  bbGCVar<t_std_collections_List_1Tt_mx2_CaseExpr_2_Node> m__0pred{};
  bbGCVar<t_mx2_CaseExpr> m__0value{};

  void gcMark();

  t_std_collections_List_1Tt_mx2_CaseExpr_2_Node(t_mx2_CaseExpr* l_value,t_std_collections_List_1Tt_mx2_CaseExpr_2_Node* l_succ);
  t_std_collections_List_1Tt_mx2_CaseExpr_2_Node(t_mx2_CaseExpr* l_value);

  void m_Value(t_mx2_CaseExpr* l_value);
  t_mx2_CaseExpr* m_Value();
  t_std_collections_List_1Tt_mx2_CaseExpr_2_Node* m_Succ();
  void m_Remove();
  t_std_collections_List_1Tt_mx2_CaseExpr_2_Node* m_Pred();
  void m_InsertBefore(t_std_collections_List_1Tt_mx2_CaseExpr_2_Node* l_node);
  void m_InsertAfter(t_std_collections_List_1Tt_mx2_CaseExpr_2_Node* l_node);

  t_std_collections_List_1Tt_mx2_CaseExpr_2_Node(){
  }
};

struct t_std_collections_List_1Tt_mx2_CaseExpr_2_Iterator{
  const char *typeName()const{return "t_std_collections_List_1Tt_mx2_CaseExpr_2_Iterator";}

  bbGCVar<t_std_collections_List_1Tt_mx2_CaseExpr_2> m__0list{};
  bbGCVar<t_std_collections_List_1Tt_mx2_CaseExpr_2_Node> m__0node{};
  bbInt m__0seq{};

  t_std_collections_List_1Tt_mx2_CaseExpr_2_Iterator(t_std_collections_List_1Tt_mx2_CaseExpr_2* l_list,t_std_collections_List_1Tt_mx2_CaseExpr_2_Node* l_node);

  void m_Insert(t_mx2_CaseExpr* l_value);
  void m_Erase();
  void m_Current(t_mx2_CaseExpr* l_current);
  t_mx2_CaseExpr* m_Current();
  void m_Bump();
  bbBool m_AtEnd();
  void m_AssertSeq();
  void m_AssertCurrent();

  t_std_collections_List_1Tt_mx2_CaseExpr_2_Iterator(){
  }

  t_std_collections_List_1Tt_mx2_CaseExpr_2_Iterator(bbNullCtor_t){
  }
};

int bbCompare(const t_std_collections_List_1Tt_mx2_CaseExpr_2_Iterator&x,const t_std_collections_List_1Tt_mx2_CaseExpr_2_Iterator&y);

void bbGCMark(const t_std_collections_List_1Tt_mx2_CaseExpr_2_Iterator&);

struct t_std_collections_List_1Tt_mx2_CaseExpr_2_BackwardsIterator{
  const char *typeName()const{return "t_std_collections_List_1Tt_mx2_CaseExpr_2_BackwardsIterator";}

  bbGCVar<t_std_collections_List_1Tt_mx2_CaseExpr_2> m__0list{};
  bbGCVar<t_std_collections_List_1Tt_mx2_CaseExpr_2_Node> m__0node{};
  bbInt m__0seq{};

  t_std_collections_List_1Tt_mx2_CaseExpr_2_BackwardsIterator(t_std_collections_List_1Tt_mx2_CaseExpr_2* l_list,t_std_collections_List_1Tt_mx2_CaseExpr_2_Node* l_node);

  void m_Insert(t_mx2_CaseExpr* l_value);
  void m_Erase();
  void m_Current(t_mx2_CaseExpr* l_current);
  t_mx2_CaseExpr* m_Current();
  void m_Bump();
  bbBool m_AtEnd();
  void m_AssertSeq();
  void m_AssertCurrent();

  t_std_collections_List_1Tt_mx2_CaseExpr_2_BackwardsIterator(){
  }

  t_std_collections_List_1Tt_mx2_CaseExpr_2_BackwardsIterator(bbNullCtor_t){
  }
};

int bbCompare(const t_std_collections_List_1Tt_mx2_CaseExpr_2_BackwardsIterator&x,const t_std_collections_List_1Tt_mx2_CaseExpr_2_BackwardsIterator&y);

void bbGCMark(const t_std_collections_List_1Tt_mx2_CaseExpr_2_BackwardsIterator&);

struct t_std_collections_List_1Tt_mx2_CaseExpr_2 : public bbObject,public virtual t_std_collections_IContainer_1Tt_mx2_CaseExpr_2{

  const char *typeName()const{return "t_std_collections_List_1Tt_mx2_CaseExpr_2";}

  bbGCVar<t_std_collections_List_1Tt_mx2_CaseExpr_2_Node> m__0head{};
  bbInt m__0seq{};

  void gcMark();

  t_std_collections_List_1Tt_mx2_CaseExpr_2(t_std_collections_List_1Tt_mx2_CaseExpr_2* l_values);
  t_std_collections_List_1Tt_mx2_CaseExpr_2(t_std_collections_Stack_1Tt_mx2_CaseExpr_2* l_values);
  t_std_collections_List_1Tt_mx2_CaseExpr_2(bbArray<bbGCVar<t_mx2_CaseExpr>>* l_values);
  t_std_collections_List_1Tt_mx2_CaseExpr_2();

  bbArray<bbGCVar<t_mx2_CaseExpr>>* m_ToArray();
  void m_Sort(bbFunction<bbInt(t_mx2_CaseExpr*,t_mx2_CaseExpr*)> l_compareFunc);
  void m_Sort(bbBool l_ascending);
  t_mx2_CaseExpr* m_RemoveLast();
  bbBool m_RemoveLast(t_mx2_CaseExpr* l_value);
  t_mx2_CaseExpr* m_RemoveFirst();
  bbInt m_RemoveEach(t_mx2_CaseExpr* l_value);
  bbBool m_Remove(t_mx2_CaseExpr* l_value);
  t_std_collections_List_1Tt_mx2_CaseExpr_2_Node* m_LastNode();
  t_mx2_CaseExpr* m_Last();
  t_std_collections_List_1Tt_mx2_CaseExpr_2_Node* m_HeadNode();
  t_std_collections_List_1Tt_mx2_CaseExpr_2_Node* m_FirstNode();
  t_mx2_CaseExpr* m_First();
  t_std_collections_List_1Tt_mx2_CaseExpr_2_Node* m_FindNode(t_mx2_CaseExpr* l_value);
  t_std_collections_List_1Tt_mx2_CaseExpr_2_Node* m_FindLastNode(t_mx2_CaseExpr* l_value);
  bbBool m_Empty();
  bbInt m_Count();
  void m_Clear();
  t_std_collections_List_1Tt_mx2_CaseExpr_2_BackwardsIterator m_Backwards();
  t_std_collections_List_1Tt_mx2_CaseExpr_2_Iterator m_All();
  t_std_collections_List_1Tt_mx2_CaseExpr_2_Node* m_AddLast(t_mx2_CaseExpr* l_value);
  t_std_collections_List_1Tt_mx2_CaseExpr_2_Node* m_AddFirst(t_mx2_CaseExpr* l_value);
  void m_AddAll(bbArray<bbGCVar<t_mx2_CaseExpr>>* l_values);
  void m_Add(t_mx2_CaseExpr* l_value);
};

struct t_std_collections_List_1Tt_mx2_Expr_2_Node : public bbObject{

  const char *typeName()const{return "t_std_collections_List_1Tt_mx2_Expr_2_Node";}

  bbGCVar<t_std_collections_List_1Tt_mx2_Expr_2_Node> m__0succ{};
  bbGCVar<t_std_collections_List_1Tt_mx2_Expr_2_Node> m__0pred{};
  bbGCVar<t_mx2_Expr> m__0value{};

  void gcMark();

  t_std_collections_List_1Tt_mx2_Expr_2_Node(t_mx2_Expr* l_value,t_std_collections_List_1Tt_mx2_Expr_2_Node* l_succ);
  t_std_collections_List_1Tt_mx2_Expr_2_Node(t_mx2_Expr* l_value);

  void m_Value(t_mx2_Expr* l_value);
  t_mx2_Expr* m_Value();
  t_std_collections_List_1Tt_mx2_Expr_2_Node* m_Succ();
  void m_Remove();
  t_std_collections_List_1Tt_mx2_Expr_2_Node* m_Pred();
  void m_InsertBefore(t_std_collections_List_1Tt_mx2_Expr_2_Node* l_node);
  void m_InsertAfter(t_std_collections_List_1Tt_mx2_Expr_2_Node* l_node);

  t_std_collections_List_1Tt_mx2_Expr_2_Node(){
  }
};

struct t_std_collections_List_1Tt_mx2_Expr_2_Iterator{
  const char *typeName()const{return "t_std_collections_List_1Tt_mx2_Expr_2_Iterator";}

  bbGCVar<t_std_collections_List_1Tt_mx2_Expr_2> m__0list{};
  bbGCVar<t_std_collections_List_1Tt_mx2_Expr_2_Node> m__0node{};
  bbInt m__0seq{};

  t_std_collections_List_1Tt_mx2_Expr_2_Iterator(t_std_collections_List_1Tt_mx2_Expr_2* l_list,t_std_collections_List_1Tt_mx2_Expr_2_Node* l_node);

  void m_Insert(t_mx2_Expr* l_value);
  void m_Erase();
  void m_Current(t_mx2_Expr* l_current);
  t_mx2_Expr* m_Current();
  void m_Bump();
  bbBool m_AtEnd();
  void m_AssertSeq();
  void m_AssertCurrent();

  t_std_collections_List_1Tt_mx2_Expr_2_Iterator(){
  }

  t_std_collections_List_1Tt_mx2_Expr_2_Iterator(bbNullCtor_t){
  }
};

int bbCompare(const t_std_collections_List_1Tt_mx2_Expr_2_Iterator&x,const t_std_collections_List_1Tt_mx2_Expr_2_Iterator&y);

void bbGCMark(const t_std_collections_List_1Tt_mx2_Expr_2_Iterator&);

struct t_std_collections_List_1Tt_mx2_Expr_2_BackwardsIterator{
  const char *typeName()const{return "t_std_collections_List_1Tt_mx2_Expr_2_BackwardsIterator";}

  bbGCVar<t_std_collections_List_1Tt_mx2_Expr_2> m__0list{};
  bbGCVar<t_std_collections_List_1Tt_mx2_Expr_2_Node> m__0node{};
  bbInt m__0seq{};

  t_std_collections_List_1Tt_mx2_Expr_2_BackwardsIterator(t_std_collections_List_1Tt_mx2_Expr_2* l_list,t_std_collections_List_1Tt_mx2_Expr_2_Node* l_node);

  void m_Insert(t_mx2_Expr* l_value);
  void m_Erase();
  void m_Current(t_mx2_Expr* l_current);
  t_mx2_Expr* m_Current();
  void m_Bump();
  bbBool m_AtEnd();
  void m_AssertSeq();
  void m_AssertCurrent();

  t_std_collections_List_1Tt_mx2_Expr_2_BackwardsIterator(){
  }

  t_std_collections_List_1Tt_mx2_Expr_2_BackwardsIterator(bbNullCtor_t){
  }
};

int bbCompare(const t_std_collections_List_1Tt_mx2_Expr_2_BackwardsIterator&x,const t_std_collections_List_1Tt_mx2_Expr_2_BackwardsIterator&y);

void bbGCMark(const t_std_collections_List_1Tt_mx2_Expr_2_BackwardsIterator&);

struct t_std_collections_List_1Tt_mx2_Expr_2 : public bbObject,public virtual t_std_collections_IContainer_1Tt_mx2_Expr_2{

  const char *typeName()const{return "t_std_collections_List_1Tt_mx2_Expr_2";}

  bbGCVar<t_std_collections_List_1Tt_mx2_Expr_2_Node> m__0head{};
  bbInt m__0seq{};

  void gcMark();

  t_std_collections_List_1Tt_mx2_Expr_2(t_std_collections_List_1Tt_mx2_Expr_2* l_values);
  t_std_collections_List_1Tt_mx2_Expr_2(t_std_collections_Stack_1Tt_mx2_Expr_2* l_values);
  t_std_collections_List_1Tt_mx2_Expr_2(bbArray<bbGCVar<t_mx2_Expr>>* l_values);
  t_std_collections_List_1Tt_mx2_Expr_2();

  bbArray<bbGCVar<t_mx2_Expr>>* m_ToArray();
  void m_Sort(bbFunction<bbInt(t_mx2_Expr*,t_mx2_Expr*)> l_compareFunc);
  void m_Sort(bbBool l_ascending);
  t_mx2_Expr* m_RemoveLast();
  bbBool m_RemoveLast(t_mx2_Expr* l_value);
  t_mx2_Expr* m_RemoveFirst();
  bbInt m_RemoveEach(t_mx2_Expr* l_value);
  bbBool m_Remove(t_mx2_Expr* l_value);
  t_std_collections_List_1Tt_mx2_Expr_2_Node* m_LastNode();
  t_mx2_Expr* m_Last();
  t_std_collections_List_1Tt_mx2_Expr_2_Node* m_HeadNode();
  t_std_collections_List_1Tt_mx2_Expr_2_Node* m_FirstNode();
  t_mx2_Expr* m_First();
  t_std_collections_List_1Tt_mx2_Expr_2_Node* m_FindNode(t_mx2_Expr* l_value);
  t_std_collections_List_1Tt_mx2_Expr_2_Node* m_FindLastNode(t_mx2_Expr* l_value);
  bbBool m_Empty();
  bbInt m_Count();
  void m_Clear();
  t_std_collections_List_1Tt_mx2_Expr_2_BackwardsIterator m_Backwards();
  t_std_collections_List_1Tt_mx2_Expr_2_Iterator m_All();
  t_std_collections_List_1Tt_mx2_Expr_2_Node* m_AddLast(t_mx2_Expr* l_value);
  t_std_collections_List_1Tt_mx2_Expr_2_Node* m_AddFirst(t_mx2_Expr* l_value);
  void m_AddAll(bbArray<bbGCVar<t_mx2_Expr>>* l_values);
  void m_Add(t_mx2_Expr* l_value);
};

struct t_std_collections_List_1Tt_mx2_VarDecl_2_Node : public bbObject{

  const char *typeName()const{return "t_std_collections_List_1Tt_mx2_VarDecl_2_Node";}

  bbGCVar<t_std_collections_List_1Tt_mx2_VarDecl_2_Node> m__0succ{};
  bbGCVar<t_std_collections_List_1Tt_mx2_VarDecl_2_Node> m__0pred{};
  bbGCVar<t_mx2_VarDecl> m__0value{};

  void gcMark();

  t_std_collections_List_1Tt_mx2_VarDecl_2_Node(t_mx2_VarDecl* l_value,t_std_collections_List_1Tt_mx2_VarDecl_2_Node* l_succ);
  t_std_collections_List_1Tt_mx2_VarDecl_2_Node(t_mx2_VarDecl* l_value);

  void m_Value(t_mx2_VarDecl* l_value);
  t_mx2_VarDecl* m_Value();
  t_std_collections_List_1Tt_mx2_VarDecl_2_Node* m_Succ();
  void m_Remove();
  t_std_collections_List_1Tt_mx2_VarDecl_2_Node* m_Pred();
  void m_InsertBefore(t_std_collections_List_1Tt_mx2_VarDecl_2_Node* l_node);
  void m_InsertAfter(t_std_collections_List_1Tt_mx2_VarDecl_2_Node* l_node);

  t_std_collections_List_1Tt_mx2_VarDecl_2_Node(){
  }
};

struct t_std_collections_List_1Tt_mx2_VarDecl_2_Iterator{
  const char *typeName()const{return "t_std_collections_List_1Tt_mx2_VarDecl_2_Iterator";}

  bbGCVar<t_std_collections_List_1Tt_mx2_VarDecl_2> m__0list{};
  bbGCVar<t_std_collections_List_1Tt_mx2_VarDecl_2_Node> m__0node{};
  bbInt m__0seq{};

  t_std_collections_List_1Tt_mx2_VarDecl_2_Iterator(t_std_collections_List_1Tt_mx2_VarDecl_2* l_list,t_std_collections_List_1Tt_mx2_VarDecl_2_Node* l_node);

  void m_Insert(t_mx2_VarDecl* l_value);
  void m_Erase();
  void m_Current(t_mx2_VarDecl* l_current);
  t_mx2_VarDecl* m_Current();
  void m_Bump();
  bbBool m_AtEnd();
  void m_AssertSeq();
  void m_AssertCurrent();

  t_std_collections_List_1Tt_mx2_VarDecl_2_Iterator(){
  }

  t_std_collections_List_1Tt_mx2_VarDecl_2_Iterator(bbNullCtor_t){
  }
};

int bbCompare(const t_std_collections_List_1Tt_mx2_VarDecl_2_Iterator&x,const t_std_collections_List_1Tt_mx2_VarDecl_2_Iterator&y);

void bbGCMark(const t_std_collections_List_1Tt_mx2_VarDecl_2_Iterator&);

struct t_std_collections_List_1Tt_mx2_VarDecl_2_BackwardsIterator{
  const char *typeName()const{return "t_std_collections_List_1Tt_mx2_VarDecl_2_BackwardsIterator";}

  bbGCVar<t_std_collections_List_1Tt_mx2_VarDecl_2> m__0list{};
  bbGCVar<t_std_collections_List_1Tt_mx2_VarDecl_2_Node> m__0node{};
  bbInt m__0seq{};

  t_std_collections_List_1Tt_mx2_VarDecl_2_BackwardsIterator(t_std_collections_List_1Tt_mx2_VarDecl_2* l_list,t_std_collections_List_1Tt_mx2_VarDecl_2_Node* l_node);

  void m_Insert(t_mx2_VarDecl* l_value);
  void m_Erase();
  void m_Current(t_mx2_VarDecl* l_current);
  t_mx2_VarDecl* m_Current();
  void m_Bump();
  bbBool m_AtEnd();
  void m_AssertSeq();
  void m_AssertCurrent();

  t_std_collections_List_1Tt_mx2_VarDecl_2_BackwardsIterator(){
  }

  t_std_collections_List_1Tt_mx2_VarDecl_2_BackwardsIterator(bbNullCtor_t){
  }
};

int bbCompare(const t_std_collections_List_1Tt_mx2_VarDecl_2_BackwardsIterator&x,const t_std_collections_List_1Tt_mx2_VarDecl_2_BackwardsIterator&y);

void bbGCMark(const t_std_collections_List_1Tt_mx2_VarDecl_2_BackwardsIterator&);

struct t_std_collections_List_1Tt_mx2_VarDecl_2 : public bbObject,public virtual t_std_collections_IContainer_1Tt_mx2_VarDecl_2{

  const char *typeName()const{return "t_std_collections_List_1Tt_mx2_VarDecl_2";}

  bbGCVar<t_std_collections_List_1Tt_mx2_VarDecl_2_Node> m__0head{};
  bbInt m__0seq{};

  void gcMark();

  t_std_collections_List_1Tt_mx2_VarDecl_2(t_std_collections_List_1Tt_mx2_VarDecl_2* l_values);
  t_std_collections_List_1Tt_mx2_VarDecl_2(t_std_collections_Stack_1Tt_mx2_VarDecl_2* l_values);
  t_std_collections_List_1Tt_mx2_VarDecl_2(bbArray<bbGCVar<t_mx2_VarDecl>>* l_values);
  t_std_collections_List_1Tt_mx2_VarDecl_2();

  bbArray<bbGCVar<t_mx2_VarDecl>>* m_ToArray();
  void m_Sort(bbFunction<bbInt(t_mx2_VarDecl*,t_mx2_VarDecl*)> l_compareFunc);
  void m_Sort(bbBool l_ascending);
  t_mx2_VarDecl* m_RemoveLast();
  bbBool m_RemoveLast(t_mx2_VarDecl* l_value);
  t_mx2_VarDecl* m_RemoveFirst();
  bbInt m_RemoveEach(t_mx2_VarDecl* l_value);
  bbBool m_Remove(t_mx2_VarDecl* l_value);
  t_std_collections_List_1Tt_mx2_VarDecl_2_Node* m_LastNode();
  t_mx2_VarDecl* m_Last();
  t_std_collections_List_1Tt_mx2_VarDecl_2_Node* m_HeadNode();
  t_std_collections_List_1Tt_mx2_VarDecl_2_Node* m_FirstNode();
  t_mx2_VarDecl* m_First();
  t_std_collections_List_1Tt_mx2_VarDecl_2_Node* m_FindNode(t_mx2_VarDecl* l_value);
  t_std_collections_List_1Tt_mx2_VarDecl_2_Node* m_FindLastNode(t_mx2_VarDecl* l_value);
  bbBool m_Empty();
  bbInt m_Count();
  void m_Clear();
  t_std_collections_List_1Tt_mx2_VarDecl_2_BackwardsIterator m_Backwards();
  t_std_collections_List_1Tt_mx2_VarDecl_2_Iterator m_All();
  t_std_collections_List_1Tt_mx2_VarDecl_2_Node* m_AddLast(t_mx2_VarDecl* l_value);
  t_std_collections_List_1Tt_mx2_VarDecl_2_Node* m_AddFirst(t_mx2_VarDecl* l_value);
  void m_AddAll(bbArray<bbGCVar<t_mx2_VarDecl>>* l_values);
  void m_Add(t_mx2_VarDecl* l_value);
};

struct t_std_collections_List_1Tt_mx2_CatchStmt_2_Node : public bbObject{

  const char *typeName()const{return "t_std_collections_List_1Tt_mx2_CatchStmt_2_Node";}

  bbGCVar<t_std_collections_List_1Tt_mx2_CatchStmt_2_Node> m__0succ{};
  bbGCVar<t_std_collections_List_1Tt_mx2_CatchStmt_2_Node> m__0pred{};
  bbGCVar<t_mx2_CatchStmt> m__0value{};

  void gcMark();

  t_std_collections_List_1Tt_mx2_CatchStmt_2_Node(t_mx2_CatchStmt* l_value,t_std_collections_List_1Tt_mx2_CatchStmt_2_Node* l_succ);
  t_std_collections_List_1Tt_mx2_CatchStmt_2_Node(t_mx2_CatchStmt* l_value);

  void m_Value(t_mx2_CatchStmt* l_value);
  t_mx2_CatchStmt* m_Value();
  t_std_collections_List_1Tt_mx2_CatchStmt_2_Node* m_Succ();
  void m_Remove();
  t_std_collections_List_1Tt_mx2_CatchStmt_2_Node* m_Pred();
  void m_InsertBefore(t_std_collections_List_1Tt_mx2_CatchStmt_2_Node* l_node);
  void m_InsertAfter(t_std_collections_List_1Tt_mx2_CatchStmt_2_Node* l_node);

  t_std_collections_List_1Tt_mx2_CatchStmt_2_Node(){
  }
};

struct t_std_collections_List_1Tt_mx2_CatchStmt_2_Iterator{
  const char *typeName()const{return "t_std_collections_List_1Tt_mx2_CatchStmt_2_Iterator";}

  bbGCVar<t_std_collections_List_1Tt_mx2_CatchStmt_2> m__0list{};
  bbGCVar<t_std_collections_List_1Tt_mx2_CatchStmt_2_Node> m__0node{};
  bbInt m__0seq{};

  t_std_collections_List_1Tt_mx2_CatchStmt_2_Iterator(t_std_collections_List_1Tt_mx2_CatchStmt_2* l_list,t_std_collections_List_1Tt_mx2_CatchStmt_2_Node* l_node);

  void m_Insert(t_mx2_CatchStmt* l_value);
  void m_Erase();
  void m_Current(t_mx2_CatchStmt* l_current);
  t_mx2_CatchStmt* m_Current();
  void m_Bump();
  bbBool m_AtEnd();
  void m_AssertSeq();
  void m_AssertCurrent();

  t_std_collections_List_1Tt_mx2_CatchStmt_2_Iterator(){
  }

  t_std_collections_List_1Tt_mx2_CatchStmt_2_Iterator(bbNullCtor_t){
  }
};

int bbCompare(const t_std_collections_List_1Tt_mx2_CatchStmt_2_Iterator&x,const t_std_collections_List_1Tt_mx2_CatchStmt_2_Iterator&y);

void bbGCMark(const t_std_collections_List_1Tt_mx2_CatchStmt_2_Iterator&);

struct t_std_collections_List_1Tt_mx2_CatchStmt_2_BackwardsIterator{
  const char *typeName()const{return "t_std_collections_List_1Tt_mx2_CatchStmt_2_BackwardsIterator";}

  bbGCVar<t_std_collections_List_1Tt_mx2_CatchStmt_2> m__0list{};
  bbGCVar<t_std_collections_List_1Tt_mx2_CatchStmt_2_Node> m__0node{};
  bbInt m__0seq{};

  t_std_collections_List_1Tt_mx2_CatchStmt_2_BackwardsIterator(t_std_collections_List_1Tt_mx2_CatchStmt_2* l_list,t_std_collections_List_1Tt_mx2_CatchStmt_2_Node* l_node);

  void m_Insert(t_mx2_CatchStmt* l_value);
  void m_Erase();
  void m_Current(t_mx2_CatchStmt* l_current);
  t_mx2_CatchStmt* m_Current();
  void m_Bump();
  bbBool m_AtEnd();
  void m_AssertSeq();
  void m_AssertCurrent();

  t_std_collections_List_1Tt_mx2_CatchStmt_2_BackwardsIterator(){
  }

  t_std_collections_List_1Tt_mx2_CatchStmt_2_BackwardsIterator(bbNullCtor_t){
  }
};

int bbCompare(const t_std_collections_List_1Tt_mx2_CatchStmt_2_BackwardsIterator&x,const t_std_collections_List_1Tt_mx2_CatchStmt_2_BackwardsIterator&y);

void bbGCMark(const t_std_collections_List_1Tt_mx2_CatchStmt_2_BackwardsIterator&);

struct t_std_collections_List_1Tt_mx2_CatchStmt_2 : public bbObject,public virtual t_std_collections_IContainer_1Tt_mx2_CatchStmt_2{

  const char *typeName()const{return "t_std_collections_List_1Tt_mx2_CatchStmt_2";}

  bbGCVar<t_std_collections_List_1Tt_mx2_CatchStmt_2_Node> m__0head{};
  bbInt m__0seq{};

  void gcMark();

  t_std_collections_List_1Tt_mx2_CatchStmt_2(t_std_collections_List_1Tt_mx2_CatchStmt_2* l_values);
  t_std_collections_List_1Tt_mx2_CatchStmt_2(t_std_collections_Stack_1Tt_mx2_CatchStmt_2* l_values);
  t_std_collections_List_1Tt_mx2_CatchStmt_2(bbArray<bbGCVar<t_mx2_CatchStmt>>* l_values);
  t_std_collections_List_1Tt_mx2_CatchStmt_2();

  bbArray<bbGCVar<t_mx2_CatchStmt>>* m_ToArray();
  void m_Sort(bbFunction<bbInt(t_mx2_CatchStmt*,t_mx2_CatchStmt*)> l_compareFunc);
  void m_Sort(bbBool l_ascending);
  t_mx2_CatchStmt* m_RemoveLast();
  bbBool m_RemoveLast(t_mx2_CatchStmt* l_value);
  t_mx2_CatchStmt* m_RemoveFirst();
  bbInt m_RemoveEach(t_mx2_CatchStmt* l_value);
  bbBool m_Remove(t_mx2_CatchStmt* l_value);
  t_std_collections_List_1Tt_mx2_CatchStmt_2_Node* m_LastNode();
  t_mx2_CatchStmt* m_Last();
  t_std_collections_List_1Tt_mx2_CatchStmt_2_Node* m_HeadNode();
  t_std_collections_List_1Tt_mx2_CatchStmt_2_Node* m_FirstNode();
  t_mx2_CatchStmt* m_First();
  t_std_collections_List_1Tt_mx2_CatchStmt_2_Node* m_FindNode(t_mx2_CatchStmt* l_value);
  t_std_collections_List_1Tt_mx2_CatchStmt_2_Node* m_FindLastNode(t_mx2_CatchStmt* l_value);
  bbBool m_Empty();
  bbInt m_Count();
  void m_Clear();
  t_std_collections_List_1Tt_mx2_CatchStmt_2_BackwardsIterator m_Backwards();
  t_std_collections_List_1Tt_mx2_CatchStmt_2_Iterator m_All();
  t_std_collections_List_1Tt_mx2_CatchStmt_2_Node* m_AddLast(t_mx2_CatchStmt* l_value);
  t_std_collections_List_1Tt_mx2_CatchStmt_2_Node* m_AddFirst(t_mx2_CatchStmt* l_value);
  void m_AddAll(bbArray<bbGCVar<t_mx2_CatchStmt>>* l_values);
  void m_Add(t_mx2_CatchStmt* l_value);
};

struct t_std_collections_List_1Tt_mx2_CaseStmt_2_Node : public bbObject{

  const char *typeName()const{return "t_std_collections_List_1Tt_mx2_CaseStmt_2_Node";}

  bbGCVar<t_std_collections_List_1Tt_mx2_CaseStmt_2_Node> m__0succ{};
  bbGCVar<t_std_collections_List_1Tt_mx2_CaseStmt_2_Node> m__0pred{};
  bbGCVar<t_mx2_CaseStmt> m__0value{};

  void gcMark();

  t_std_collections_List_1Tt_mx2_CaseStmt_2_Node(t_mx2_CaseStmt* l_value,t_std_collections_List_1Tt_mx2_CaseStmt_2_Node* l_succ);
  t_std_collections_List_1Tt_mx2_CaseStmt_2_Node(t_mx2_CaseStmt* l_value);

  void m_Value(t_mx2_CaseStmt* l_value);
  t_mx2_CaseStmt* m_Value();
  t_std_collections_List_1Tt_mx2_CaseStmt_2_Node* m_Succ();
  void m_Remove();
  t_std_collections_List_1Tt_mx2_CaseStmt_2_Node* m_Pred();
  void m_InsertBefore(t_std_collections_List_1Tt_mx2_CaseStmt_2_Node* l_node);
  void m_InsertAfter(t_std_collections_List_1Tt_mx2_CaseStmt_2_Node* l_node);

  t_std_collections_List_1Tt_mx2_CaseStmt_2_Node(){
  }
};

struct t_std_collections_List_1Tt_mx2_CaseStmt_2_Iterator{
  const char *typeName()const{return "t_std_collections_List_1Tt_mx2_CaseStmt_2_Iterator";}

  bbGCVar<t_std_collections_List_1Tt_mx2_CaseStmt_2> m__0list{};
  bbGCVar<t_std_collections_List_1Tt_mx2_CaseStmt_2_Node> m__0node{};
  bbInt m__0seq{};

  t_std_collections_List_1Tt_mx2_CaseStmt_2_Iterator(t_std_collections_List_1Tt_mx2_CaseStmt_2* l_list,t_std_collections_List_1Tt_mx2_CaseStmt_2_Node* l_node);

  void m_Insert(t_mx2_CaseStmt* l_value);
  void m_Erase();
  void m_Current(t_mx2_CaseStmt* l_current);
  t_mx2_CaseStmt* m_Current();
  void m_Bump();
  bbBool m_AtEnd();
  void m_AssertSeq();
  void m_AssertCurrent();

  t_std_collections_List_1Tt_mx2_CaseStmt_2_Iterator(){
  }

  t_std_collections_List_1Tt_mx2_CaseStmt_2_Iterator(bbNullCtor_t){
  }
};

int bbCompare(const t_std_collections_List_1Tt_mx2_CaseStmt_2_Iterator&x,const t_std_collections_List_1Tt_mx2_CaseStmt_2_Iterator&y);

void bbGCMark(const t_std_collections_List_1Tt_mx2_CaseStmt_2_Iterator&);

struct t_std_collections_List_1Tt_mx2_CaseStmt_2_BackwardsIterator{
  const char *typeName()const{return "t_std_collections_List_1Tt_mx2_CaseStmt_2_BackwardsIterator";}

  bbGCVar<t_std_collections_List_1Tt_mx2_CaseStmt_2> m__0list{};
  bbGCVar<t_std_collections_List_1Tt_mx2_CaseStmt_2_Node> m__0node{};
  bbInt m__0seq{};

  t_std_collections_List_1Tt_mx2_CaseStmt_2_BackwardsIterator(t_std_collections_List_1Tt_mx2_CaseStmt_2* l_list,t_std_collections_List_1Tt_mx2_CaseStmt_2_Node* l_node);

  void m_Insert(t_mx2_CaseStmt* l_value);
  void m_Erase();
  void m_Current(t_mx2_CaseStmt* l_current);
  t_mx2_CaseStmt* m_Current();
  void m_Bump();
  bbBool m_AtEnd();
  void m_AssertSeq();
  void m_AssertCurrent();

  t_std_collections_List_1Tt_mx2_CaseStmt_2_BackwardsIterator(){
  }

  t_std_collections_List_1Tt_mx2_CaseStmt_2_BackwardsIterator(bbNullCtor_t){
  }
};

int bbCompare(const t_std_collections_List_1Tt_mx2_CaseStmt_2_BackwardsIterator&x,const t_std_collections_List_1Tt_mx2_CaseStmt_2_BackwardsIterator&y);

void bbGCMark(const t_std_collections_List_1Tt_mx2_CaseStmt_2_BackwardsIterator&);

struct t_std_collections_List_1Tt_mx2_CaseStmt_2 : public bbObject,public virtual t_std_collections_IContainer_1Tt_mx2_CaseStmt_2{

  const char *typeName()const{return "t_std_collections_List_1Tt_mx2_CaseStmt_2";}

  bbGCVar<t_std_collections_List_1Tt_mx2_CaseStmt_2_Node> m__0head{};
  bbInt m__0seq{};

  void gcMark();

  t_std_collections_List_1Tt_mx2_CaseStmt_2(t_std_collections_List_1Tt_mx2_CaseStmt_2* l_values);
  t_std_collections_List_1Tt_mx2_CaseStmt_2(t_std_collections_Stack_1Tt_mx2_CaseStmt_2* l_values);
  t_std_collections_List_1Tt_mx2_CaseStmt_2(bbArray<bbGCVar<t_mx2_CaseStmt>>* l_values);
  t_std_collections_List_1Tt_mx2_CaseStmt_2();

  bbArray<bbGCVar<t_mx2_CaseStmt>>* m_ToArray();
  void m_Sort(bbFunction<bbInt(t_mx2_CaseStmt*,t_mx2_CaseStmt*)> l_compareFunc);
  void m_Sort(bbBool l_ascending);
  t_mx2_CaseStmt* m_RemoveLast();
  bbBool m_RemoveLast(t_mx2_CaseStmt* l_value);
  t_mx2_CaseStmt* m_RemoveFirst();
  bbInt m_RemoveEach(t_mx2_CaseStmt* l_value);
  bbBool m_Remove(t_mx2_CaseStmt* l_value);
  t_std_collections_List_1Tt_mx2_CaseStmt_2_Node* m_LastNode();
  t_mx2_CaseStmt* m_Last();
  t_std_collections_List_1Tt_mx2_CaseStmt_2_Node* m_HeadNode();
  t_std_collections_List_1Tt_mx2_CaseStmt_2_Node* m_FirstNode();
  t_mx2_CaseStmt* m_First();
  t_std_collections_List_1Tt_mx2_CaseStmt_2_Node* m_FindNode(t_mx2_CaseStmt* l_value);
  t_std_collections_List_1Tt_mx2_CaseStmt_2_Node* m_FindLastNode(t_mx2_CaseStmt* l_value);
  bbBool m_Empty();
  bbInt m_Count();
  void m_Clear();
  t_std_collections_List_1Tt_mx2_CaseStmt_2_BackwardsIterator m_Backwards();
  t_std_collections_List_1Tt_mx2_CaseStmt_2_Iterator m_All();
  t_std_collections_List_1Tt_mx2_CaseStmt_2_Node* m_AddLast(t_mx2_CaseStmt* l_value);
  t_std_collections_List_1Tt_mx2_CaseStmt_2_Node* m_AddFirst(t_mx2_CaseStmt* l_value);
  void m_AddAll(bbArray<bbGCVar<t_mx2_CaseStmt>>* l_values);
  void m_Add(t_mx2_CaseStmt* l_value);
};

struct t_std_collections_List_1Tt_mx2_FuncList_2_Node : public bbObject{

  const char *typeName()const{return "t_std_collections_List_1Tt_mx2_FuncList_2_Node";}

  bbGCVar<t_std_collections_List_1Tt_mx2_FuncList_2_Node> m__0succ{};
  bbGCVar<t_std_collections_List_1Tt_mx2_FuncList_2_Node> m__0pred{};
  bbGCVar<t_mx2_FuncList> m__0value{};

  void gcMark();

  t_std_collections_List_1Tt_mx2_FuncList_2_Node(t_mx2_FuncList* l_value,t_std_collections_List_1Tt_mx2_FuncList_2_Node* l_succ);
  t_std_collections_List_1Tt_mx2_FuncList_2_Node(t_mx2_FuncList* l_value);

  void m_Value(t_mx2_FuncList* l_value);
  t_mx2_FuncList* m_Value();
  t_std_collections_List_1Tt_mx2_FuncList_2_Node* m_Succ();
  void m_Remove();
  t_std_collections_List_1Tt_mx2_FuncList_2_Node* m_Pred();
  void m_InsertBefore(t_std_collections_List_1Tt_mx2_FuncList_2_Node* l_node);
  void m_InsertAfter(t_std_collections_List_1Tt_mx2_FuncList_2_Node* l_node);

  t_std_collections_List_1Tt_mx2_FuncList_2_Node(){
  }
};

struct t_std_collections_List_1Tt_mx2_FuncList_2_Iterator{
  const char *typeName()const{return "t_std_collections_List_1Tt_mx2_FuncList_2_Iterator";}

  bbGCVar<t_std_collections_List_1Tt_mx2_FuncList_2> m__0list{};
  bbGCVar<t_std_collections_List_1Tt_mx2_FuncList_2_Node> m__0node{};
  bbInt m__0seq{};

  t_std_collections_List_1Tt_mx2_FuncList_2_Iterator(t_std_collections_List_1Tt_mx2_FuncList_2* l_list,t_std_collections_List_1Tt_mx2_FuncList_2_Node* l_node);

  void m_Insert(t_mx2_FuncList* l_value);
  void m_Erase();
  void m_Current(t_mx2_FuncList* l_current);
  t_mx2_FuncList* m_Current();
  void m_Bump();
  bbBool m_AtEnd();
  void m_AssertSeq();
  void m_AssertCurrent();

  t_std_collections_List_1Tt_mx2_FuncList_2_Iterator(){
  }

  t_std_collections_List_1Tt_mx2_FuncList_2_Iterator(bbNullCtor_t){
  }
};

int bbCompare(const t_std_collections_List_1Tt_mx2_FuncList_2_Iterator&x,const t_std_collections_List_1Tt_mx2_FuncList_2_Iterator&y);

void bbGCMark(const t_std_collections_List_1Tt_mx2_FuncList_2_Iterator&);

struct t_std_collections_List_1Tt_mx2_FuncList_2_BackwardsIterator{
  const char *typeName()const{return "t_std_collections_List_1Tt_mx2_FuncList_2_BackwardsIterator";}

  bbGCVar<t_std_collections_List_1Tt_mx2_FuncList_2> m__0list{};
  bbGCVar<t_std_collections_List_1Tt_mx2_FuncList_2_Node> m__0node{};
  bbInt m__0seq{};

  t_std_collections_List_1Tt_mx2_FuncList_2_BackwardsIterator(t_std_collections_List_1Tt_mx2_FuncList_2* l_list,t_std_collections_List_1Tt_mx2_FuncList_2_Node* l_node);

  void m_Insert(t_mx2_FuncList* l_value);
  void m_Erase();
  void m_Current(t_mx2_FuncList* l_current);
  t_mx2_FuncList* m_Current();
  void m_Bump();
  bbBool m_AtEnd();
  void m_AssertSeq();
  void m_AssertCurrent();

  t_std_collections_List_1Tt_mx2_FuncList_2_BackwardsIterator(){
  }

  t_std_collections_List_1Tt_mx2_FuncList_2_BackwardsIterator(bbNullCtor_t){
  }
};

int bbCompare(const t_std_collections_List_1Tt_mx2_FuncList_2_BackwardsIterator&x,const t_std_collections_List_1Tt_mx2_FuncList_2_BackwardsIterator&y);

void bbGCMark(const t_std_collections_List_1Tt_mx2_FuncList_2_BackwardsIterator&);

struct t_std_collections_List_1Tt_mx2_FuncList_2 : public bbObject,public virtual t_std_collections_IContainer_1Tt_mx2_FuncList_2{

  const char *typeName()const{return "t_std_collections_List_1Tt_mx2_FuncList_2";}

  bbGCVar<t_std_collections_List_1Tt_mx2_FuncList_2_Node> m__0head{};
  bbInt m__0seq{};

  void gcMark();

  t_std_collections_List_1Tt_mx2_FuncList_2(t_std_collections_List_1Tt_mx2_FuncList_2* l_values);
  t_std_collections_List_1Tt_mx2_FuncList_2(t_std_collections_Stack_1Tt_mx2_FuncList_2* l_values);
  t_std_collections_List_1Tt_mx2_FuncList_2(bbArray<bbGCVar<t_mx2_FuncList>>* l_values);
  t_std_collections_List_1Tt_mx2_FuncList_2();

  bbArray<bbGCVar<t_mx2_FuncList>>* m_ToArray();
  void m_Sort(bbFunction<bbInt(t_mx2_FuncList*,t_mx2_FuncList*)> l_compareFunc);
  void m_Sort(bbBool l_ascending);
  t_mx2_FuncList* m_RemoveLast();
  bbBool m_RemoveLast(t_mx2_FuncList* l_value);
  t_mx2_FuncList* m_RemoveFirst();
  bbInt m_RemoveEach(t_mx2_FuncList* l_value);
  bbBool m_Remove(t_mx2_FuncList* l_value);
  t_std_collections_List_1Tt_mx2_FuncList_2_Node* m_LastNode();
  t_mx2_FuncList* m_Last();
  t_std_collections_List_1Tt_mx2_FuncList_2_Node* m_HeadNode();
  t_std_collections_List_1Tt_mx2_FuncList_2_Node* m_FirstNode();
  t_mx2_FuncList* m_First();
  t_std_collections_List_1Tt_mx2_FuncList_2_Node* m_FindNode(t_mx2_FuncList* l_value);
  t_std_collections_List_1Tt_mx2_FuncList_2_Node* m_FindLastNode(t_mx2_FuncList* l_value);
  bbBool m_Empty();
  bbInt m_Count();
  void m_Clear();
  t_std_collections_List_1Tt_mx2_FuncList_2_BackwardsIterator m_Backwards();
  t_std_collections_List_1Tt_mx2_FuncList_2_Iterator m_All();
  t_std_collections_List_1Tt_mx2_FuncList_2_Node* m_AddLast(t_mx2_FuncList* l_value);
  t_std_collections_List_1Tt_mx2_FuncList_2_Node* m_AddFirst(t_mx2_FuncList* l_value);
  void m_AddAll(bbArray<bbGCVar<t_mx2_FuncList>>* l_values);
  void m_Add(t_mx2_FuncList* l_value);
};

#endif
