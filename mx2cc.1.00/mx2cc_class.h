
#ifndef MX2_MX2CC_CLASS_H
#define MX2_MX2CC_CLASS_H

#include <bbmonkey.h>

// ***** External *****

#include "mx2cc_decl.h"
#include "mx2cc_scope.h"
#include "mx2cc_type.h"
#include "mx2cc_value.h"

struct t_std_collections_Stack_1Tt_mx2_ClassType_2;
struct t_mx2_FuncValue;
struct t_std_collections_Stack_1Tt_mx2_FuncValue_2;
struct t_std_collections_Stack_1Tt_mx2_VarValue_2;
struct t_mx2_SNode;
struct t_mx2_TypeExpr;
struct t_mx2_FuncList;
struct t_mx2_Stmt;
struct t_mx2_PNode;

// ***** Internal *****

struct t_mx2_ClassType;
struct t_mx2_ClassDecl;
struct t_mx2_OpIndexValue;
struct t_mx2_ClassScope;

struct t_mx2_ClassType : public t_mx2_Type{

  const char *typeName()const{return "t_mx2_ClassType";}

  bbGCVar<t_mx2_ClassDecl> m_cdecl{};
  bbGCVar<bbArray<bbGCVar<t_mx2_Type>>> m_types{};
  bbGCVar<t_mx2_ClassType> m_instanceOf{};
  bbGCVar<t_mx2_FileDecl> m_transFile{};
  bbGCVar<t_mx2_ClassScope> m_scope{};
  bbGCVar<t_mx2_ClassType> m_superType{};
  bbGCVar<bbArray<bbGCVar<t_mx2_ClassType>>> m_ifaceTypes{};
  bbGCVar<bbArray<bbGCVar<t_mx2_ClassType>>> m_allIfaces{};
  bbBool m_isvoid{};
  bbGCVar<t_std_collections_Stack_1Tt_mx2_ClassType_2> m_instances{};
  bbBool m_membersSemanted{};
  bbBool m_membersSemanting{};
  bbGCVar<bbArray<bbGCVar<t_mx2_FuncValue>>> m_abstractMethods{};
  bbGCVar<t_std_collections_Stack_1Tt_mx2_FuncValue_2> m_ctors{};
  bbGCVar<t_std_collections_Stack_1Tt_mx2_FuncValue_2> m_methods{};
  bbGCVar<t_std_collections_Stack_1Tt_mx2_VarValue_2> m_fields{};

  void init();

  void gcMark();

  t_mx2_ClassType(t_mx2_ClassDecl* l_cdecl,t_mx2_Scope* l_outer,bbArray<bbGCVar<t_mx2_Type>>* l_types,t_mx2_ClassType* l_instanceOf);

  bbString m_TypeId();
  bbString m_ToString();
  void m_SemantMembers();
  t_mx2_SNode* m_OnSemant();
  bbString m_Name();
  bbBool m_IsVoid();
  bbBool m_IsVirtual();
  bbBool m_IsStruct();
  bbBool m_IsInterface();
  bbBool m_IsGenInstance();
  bbBool m_IsClass();
  bbBool m_IsAbstract();
  t_mx2_Type* m_InferType(t_mx2_Type* l_type,bbArray<bbGCVar<t_mx2_Type>>* l_infered);
  t_mx2_Value* m_Index(bbArray<bbGCVar<t_mx2_Value>>* l_args,t_mx2_Value* l_value);
  t_mx2_Type* m_GenInstance(bbArray<bbGCVar<t_mx2_Type>>* l_types);
  t_mx2_Type* m_FindType(bbString l_ident);
  t_mx2_SNode* m_FindSuperNode(bbString l_ident);
  t_mx2_FuncValue* m_FindSuperFunc(bbString l_ident,bbArray<bbGCVar<t_mx2_Type>>* l_argTypes);
  t_mx2_SNode* m_FindNode(bbString l_ident);
  bbBool m_ExtendsType(t_mx2_Type* l_type);
  bbInt m_DistanceToType(t_mx2_Type* l_type);
  bbBool m_CanCastToType(t_mx2_Type* l_type);

  t_mx2_ClassType(){
    init();
  }
};

struct t_mx2_ClassDecl : public t_mx2_Decl{

  const char *typeName()const{return "t_mx2_ClassDecl";}

  bbGCVar<bbArray<bbString>> m_genArgs{};
  bbGCVar<t_mx2_TypeExpr> m_superType{};
  bbGCVar<bbArray<bbGCVar<t_mx2_TypeExpr>>> m_ifaceTypes{};

  void gcMark();

  bbString m_ToString();
  t_mx2_SNode* m_ToNode(t_mx2_Scope* l_scope);

  t_mx2_ClassDecl(){
  }
};

struct t_mx2_OpIndexValue : public t_mx2_Value{

  const char *typeName()const{return "t_mx2_OpIndexValue";}

  bbGCVar<t_mx2_ClassType> m_ctype{};
  bbGCVar<bbArray<bbGCVar<t_mx2_Value>>> m_args{};
  bbGCVar<t_mx2_Value> m_instance{};
  bbGCVar<t_mx2_FuncList> m_getters{};
  bbGCVar<t_mx2_FuncList> m_setters{};
  bbGCVar<t_mx2_Value> m_invokeGet{};

  void gcMark();

  t_mx2_OpIndexValue(t_mx2_ClassType* l_ctype,bbArray<bbGCVar<t_mx2_Value>>* l_args,t_mx2_Value* l_instance);

  bbString m_ToString();
  t_mx2_Value* m_ToRValue();
  bbBool m_HasSideEffects();
  t_mx2_Stmt* m_Assign(t_mx2_PNode* l_pnode,bbString l_op,t_mx2_Value* l_rvalue,t_mx2_Block* l_block);

  t_mx2_OpIndexValue(){
  }
};

struct t_mx2_ClassScope : public t_mx2_Scope{

  const char *typeName()const{return "t_mx2_ClassScope";}

  bbGCVar<t_mx2_ClassType> m_ctype{};
  bbGCVar<t_mx2_Type> m_itype{};

  void gcMark();

  t_mx2_ClassScope(t_mx2_ClassType* l_ctype,t_mx2_Scope* l_outer);

  bbString m_TypeId();
  bbString m_Name();
  bbBool m_IsGeneric();
  t_mx2_Type* m_FindType(bbString l_ident);
  t_mx2_SNode* m_FindNode(bbString l_ident);
  t_mx2_ClassType* m_FindClass();

  t_mx2_ClassScope(){
  }
};

#endif
