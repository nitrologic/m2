
#ifndef MX2_MX2CC_ALIAS_H
#define MX2_MX2CC_ALIAS_H

#include <bbmonkey.h>

// ***** External *****

#include "mx2cc_decl.h"
#include "mx2cc_type.h"

struct t_mx2_TypeExpr;
struct t_mx2_SNode;
struct t_mx2_Scope;
struct t_std_collections_Stack_1Tt_mx2_AliasType_2;

// ***** Internal *****

struct t_mx2_AliasDecl;
struct t_mx2_AliasType;

struct t_mx2_AliasDecl : public t_mx2_Decl{

  const char *typeName()const{return "t_mx2_AliasDecl";}

  bbGCVar<bbArray<bbString>> m_genArgs{};
  bbGCVar<t_mx2_TypeExpr> m_type{};

  void gcMark();

  t_mx2_SNode* m_ToNode(t_mx2_Scope* l_scope);

  t_mx2_AliasDecl(){
  }
};

struct t_mx2_AliasType : public t_mx2_ProxyType{

  const char *typeName()const{return "t_mx2_AliasType";}

  bbGCVar<t_mx2_AliasDecl> m_adecl{};
  bbGCVar<t_mx2_Scope> m_scope{};
  bbGCVar<bbArray<bbGCVar<t_mx2_Type>>> m_types{};
  bbGCVar<t_mx2_AliasType> m_instanceOf{};
  bbGCVar<t_std_collections_Stack_1Tt_mx2_AliasType_2> m_instances{};

  void gcMark();

  t_mx2_AliasType(t_mx2_AliasDecl* l_adecl,t_mx2_Scope* l_scope,bbArray<bbGCVar<t_mx2_Type>>* l_types,t_mx2_AliasType* l_instanceOf);

  t_mx2_SNode* m_OnSemant();
  bbString m_Name();
  t_mx2_Type* m_GenInstance(bbArray<bbGCVar<t_mx2_Type>>* l_types);

  t_mx2_AliasType(){
  }
};

#endif
