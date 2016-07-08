
#ifndef MX2_MX2CC_FUNC_H
#define MX2_MX2CC_FUNC_H

#include <bbmonkey.h>

// ***** External *****

#include "mx2cc_decl.h"
#include "mx2cc_node.h"
#include "mx2cc_type.h"
#include "mx2cc_value.h"

struct t_mx2_Scope;
struct t_mx2_VarDecl;
struct t_mx2_ClassScope;
struct t_mx2_Block;
struct t_mx2_VarValue;
struct t_std_collections_Stack_1Tt_mx2_FuncValue_2;
struct t_std_collections_Stack_1Tt_mx2_VarValue_2;
struct t_std_collections_Stack_1Tt_mx2_FuncListType_2;
struct t_mx2_FuncTypeExpr;
struct t_mx2_Expr;
struct t_mx2_StmtExpr;
struct t_std_collections_Stack_1s;

// ***** Internal *****

struct t_mx2_FuncValue;
struct t_mx2_FuncList;
struct t_mx2_FuncDecl;
struct t_mx2_MemberFuncValue;
struct t_mx2_FuncListValue;
struct t_mx2_FuncListType;

struct t_mx2_FuncValue : public t_mx2_Value{

  const char *typeName()const{return "t_mx2_FuncValue";}

  bbGCVar<t_mx2_FuncDecl> m_fdecl{};
  bbGCVar<t_mx2_Scope> m_scope{};
  bbGCVar<bbArray<bbGCVar<t_mx2_Type>>> m_types{};
  bbGCVar<t_mx2_FuncValue> m_instanceOf{};
  bbGCVar<bbArray<bbGCVar<t_mx2_VarDecl>>> m_pdecls{};
  bbGCVar<t_mx2_FileDecl> m_transFile{};
  bbGCVar<t_mx2_ClassScope> m_cscope{};
  bbGCVar<t_mx2_Block> m_block{};
  bbGCVar<t_mx2_FuncType> m_ftype{};
  bbGCVar<t_mx2_FuncValue> m_overrides{};
  bbGCVar<bbArray<bbGCVar<t_mx2_VarValue>>> m_params{};
  bbGCVar<t_mx2_Value> m_selfValue{};
  bbGCVar<t_std_collections_Stack_1Tt_mx2_FuncValue_2> m_instances{};
  bbGCVar<t_std_collections_Stack_1Tt_mx2_VarValue_2> m_captures{};
  bbInt m_nextLocalId{};
  bbGCVar<t_mx2_InvokeNewValue> m_invokeNew{};
  bbBool m_used{};

  void gcMark();

  t_mx2_FuncValue(t_mx2_FuncDecl* l_fdecl,t_mx2_Scope* l_scope,bbArray<bbGCVar<t_mx2_Type>>* l_types,t_mx2_FuncValue* l_instanceOf);

  void m_Used();
  t_mx2_FuncValue* m_TryGenInstance(bbArray<bbGCVar<t_mx2_Type>>* l_types);
  t_mx2_Value* m_ToValue(t_mx2_Value* l_instance);
  bbString m_ToString();
  void m_SemantStmts();
  void m_SemantParams();
  void m_SemantInvokeNew();
  bbString m_ParamNames();
  t_mx2_SNode* m_OnSemant();
  bbString m_Name();
  bbBool m_IsVirtual();
  bbBool m_IsMethod();
  bbBool m_IsLambda();
  bbBool m_IsGeneric();
  bbBool m_IsFunction();
  bbBool m_IsExtension();
  bbBool m_IsCtor();
  t_mx2_Value* m_Invoke(bbArray<bbGCVar<t_mx2_Value>>* l_args);
  t_mx2_Value* m_GenInstance(bbArray<bbGCVar<t_mx2_Type>>* l_types);
  bbString m_GenArgsName();
  bbArray<bbGCVar<t_mx2_Value>>* m_FixArgs(bbArray<bbGCVar<t_mx2_Value>>* l_args);
  void m_CheckAccess(t_mx2_Scope* l_tscope);

  t_mx2_FuncValue(){
  }
};

struct t_mx2_FuncList : public t_mx2_SNode{

  const char *typeName()const{return "t_mx2_FuncList";}

  bbString m_ident{};
  bbGCVar<t_mx2_Scope> m_scope{};
  bbGCVar<t_std_collections_Stack_1Tt_mx2_FuncValue_2> m_funcs{};
  bbGCVar<t_std_collections_Stack_1Tt_mx2_FuncListType_2> m_instances{};
  bbGCVar<t_mx2_FuncListType> m_instance0{};

  void init();

  void gcMark();

  t_mx2_FuncList(bbString l_ident,t_mx2_Scope* l_scope);

  t_mx2_Value* m_ToValue(t_mx2_Value* l_instance);
  bbString m_ToString();
  void m_PushFunc(t_mx2_FuncValue* l_func);
  t_mx2_SNode* m_OnSemant();
  t_mx2_FuncListType* m_GenFuncListType(bbArray<bbGCVar<t_mx2_Type>>* l_types);
  t_mx2_FuncValue* m_FindFunc(bbArray<bbGCVar<t_mx2_Type>>* l_argTypes);

  t_mx2_FuncList(){
    init();
  }
};

struct t_mx2_FuncDecl : public t_mx2_Decl{

  const char *typeName()const{return "t_mx2_FuncDecl";}

  bbGCVar<bbArray<bbString>> m_genArgs{};
  bbGCVar<t_mx2_FuncTypeExpr> m_type{};
  bbGCVar<t_mx2_Expr> m_whereExpr{};
  bbGCVar<bbArray<bbGCVar<t_mx2_StmtExpr>>> m_stmts{};

  void gcMark();

  bbString m_ToString();
  t_mx2_SNode* m_ToNode(t_mx2_Scope* l_scope);
  void m_Emit(t_std_collections_Stack_1s* l_buf,bbString l_spc);

  t_mx2_FuncDecl(){
  }
};

struct t_mx2_MemberFuncValue : public t_mx2_Value{

  const char *typeName()const{return "t_mx2_MemberFuncValue";}

  bbGCVar<t_mx2_Value> m_instance{};
  bbGCVar<t_mx2_FuncValue> m_member{};

  void gcMark();

  t_mx2_MemberFuncValue(t_mx2_Value* l_instance,t_mx2_FuncValue* l_member);

  bbString m_ToString();
  bbBool m_HasSideEffects();
  void m_CheckAccess(t_mx2_Scope* l_tscope);

  t_mx2_MemberFuncValue(){
  }
};

struct t_mx2_FuncListValue : public t_mx2_Value{

  const char *typeName()const{return "t_mx2_FuncListValue";}

  bbGCVar<t_mx2_FuncListType> m_flistType{};
  bbGCVar<t_mx2_Value> m_instance{};

  void gcMark();

  t_mx2_FuncListValue(t_mx2_FuncListType* l_flistType,t_mx2_Value* l_instance);

  t_mx2_Value* m_UpCast(t_mx2_Type* l_type);
  bbString m_ToString();
  t_mx2_Value* m_ToRValue();
  t_mx2_Value* m_Invoke(bbArray<bbGCVar<t_mx2_Value>>* l_args);
  t_mx2_Value* m_GenInstance(bbArray<bbGCVar<t_mx2_Type>>* l_types);

  t_mx2_FuncListValue(){
  }
};

struct t_mx2_FuncListType : public t_mx2_Type{

  const char *typeName()const{return "t_mx2_FuncListType";}

  bbGCVar<t_mx2_FuncList> m_flist{};
  bbGCVar<t_std_collections_Stack_1Tt_mx2_FuncValue_2> m_funcs{};
  bbGCVar<bbArray<bbGCVar<t_mx2_Type>>> m_types{};

  void gcMark();

  t_mx2_FuncListType(t_mx2_FuncList* l_flist,bbArray<bbGCVar<t_mx2_Type>>* l_types);
  t_mx2_FuncListType(t_mx2_FuncList* l_flist);

  bbString m_TypeId();
  t_mx2_Value* m_ToValue(t_mx2_Value* l_instance);
  bbString m_ToString();
  bbString m_Name();
  t_mx2_FuncValue* m_FindOverload(t_mx2_Type* l_ret,bbArray<bbGCVar<t_mx2_Type>>* l_args);
  bbInt m_DistanceToType(t_mx2_Type* l_type);

  t_mx2_FuncListType(){
  }
};

#endif
