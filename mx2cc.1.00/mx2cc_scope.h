
#ifndef MX2_MX2CC_SCOPE_H
#define MX2_MX2CC_SCOPE_H

#include <bbmonkey.h>

// ***** External *****

#include "../../../../../modules/monkey/monkey.buildv1.0.0/desktop_release_linux/monkey_types.h"

struct t_std_collections_Stack_1Tt_mx2_Scope_2;
struct t_std_collections_Map_1sTt_mx2_SNode_2;
struct t_std_collections_Stack_1Tt_mx2_SNode_2;
struct t_mx2_SNode;
struct t_mx2_Type;
struct t_mx2_Value;
struct t_mx2_ClassType;
struct t_mx2_FileDecl;
struct t_mx2_NamespaceScope;
struct t_std_collections_Stack_1Tt_mx2_NamespaceScope_2;
struct t_mx2_FuncValue;
struct t_std_collections_Stack_1Tt_mx2_Stmt_2;
struct t_mx2_StmtExpr;
struct t_mx2_Stmt;
struct t_mx2_VarValue;

// ***** Internal *****

struct t_mx2_Scope;
struct t_mx2_FileScope;
struct t_mx2_Block;
struct t_mx2_FuncBlock;

struct t_mx2_Scope : public bbObject{

  const char *typeName()const{return "t_mx2_Scope";}

  bbGCVar<t_mx2_Scope> m_outer{};
  bbGCVar<t_std_collections_Stack_1Tt_mx2_Scope_2> m_inner{};
  bbGCVar<t_std_collections_Map_1sTt_mx2_SNode_2> m_nodes{};
  bbGCVar<t_std_collections_Stack_1Tt_mx2_SNode_2> m_transMembers{};

  void init();

  void gcMark();

  t_mx2_Scope(t_mx2_Scope* l_outer);

  virtual bbString m_TypeId();
  virtual bbString m_ToString();
  virtual bbString m_Name();
  virtual bbBool m_IsGeneric();
  bbBool m_Insert(bbString l_ident,t_mx2_SNode* l_node);
  t_mx2_Type* m_GetType(bbString l_ident);
  t_mx2_SNode* m_GetNode(bbString l_ident);
  virtual t_mx2_Value* m_FindValue(bbString l_ident);
  virtual t_mx2_Type* m_FindType(bbString l_ident);
  virtual t_mx2_SNode* m_FindNode(bbString l_ident);
  virtual t_mx2_FileScope* m_FindFile();
  virtual t_mx2_ClassType* m_FindClass();

  t_mx2_Scope(){
    init();
  }
};

struct t_mx2_FileScope : public t_mx2_Scope{

  const char *typeName()const{return "t_mx2_FileScope";}

  bbGCVar<t_mx2_FileDecl> m_fdecl{};
  bbGCVar<t_mx2_NamespaceScope> m_nmspace{};
  bbGCVar<t_std_collections_Stack_1Tt_mx2_NamespaceScope_2> m_usings{};
  bbGCVar<t_std_collections_Stack_1Tt_mx2_SNode_2> m_toSemant{};

  void init();

  void gcMark();

  t_mx2_FileScope(t_mx2_FileDecl* l_fdecl);

  bbBool m_UsingNamespace(t_mx2_NamespaceScope* l_nmspace);
  void m_UsingInner(t_mx2_NamespaceScope* l_nmspace);
  void m_UsingAll(t_mx2_NamespaceScope* l_nmspace);
  void m_Semant();
  t_mx2_Type* m_FindType(bbString l_ident);
  t_mx2_SNode* m_FindNode(bbString l_ident);
  t_mx2_FileScope* m_FindFile();

  t_mx2_FileScope(){
    init();
  }
};

struct t_mx2_Block : public t_mx2_Scope{

  const char *typeName()const{return "t_mx2_Block";}

  bbGCVar<t_mx2_FuncValue> m_func{};
  bbGCVar<t_std_collections_Stack_1Tt_mx2_Stmt_2> m_stmts{};
  bbBool m_reachable=true;
  bbBool m_loop{};
  bbBool m_inex{};

  void init();

  void gcMark();

  t_mx2_Block(t_mx2_Block* l_outer);
  t_mx2_Block(t_mx2_FuncValue* l_func);

  void m_Semant(bbArray<bbGCVar<t_mx2_StmtExpr>>* l_stmts);
  t_mx2_Value* m_FindValue(bbString l_ident);
  void m_Emit(t_mx2_Stmt* l_stmt);
  t_mx2_VarValue* m_AllocLocal(bbString l_ident,t_mx2_Value* l_init);
  t_mx2_VarValue* m_AllocLocal(t_mx2_Value* l_init);

  t_mx2_Block(){
    init();
  }
};

struct t_mx2_FuncBlock : public t_mx2_Block{

  const char *typeName()const{return "t_mx2_FuncBlock";}

  t_mx2_FuncBlock(t_mx2_FuncValue* l_func);

  bbBool m_IsGeneric();
  t_mx2_Type* m_FindType(bbString l_ident);

  t_mx2_FuncBlock(){
  }
};

#endif
