
#ifndef MX2_MX2CC_ENUM_H
#define MX2_MX2CC_ENUM_H

#include <bbmonkey.h>

// ***** External *****

#include "mx2cc_decl.h"
#include "mx2cc_scope.h"
#include "mx2cc_type.h"

struct t_mx2_SNode;
struct t_mx2_TypeExpr;

// ***** Internal *****

struct t_mx2_EnumType;
struct t_mx2_EnumDecl;
struct t_mx2_EnumScope;

struct t_mx2_EnumType : public t_mx2_Type{

  const char *typeName()const{return "t_mx2_EnumType";}

  bbGCVar<t_mx2_EnumDecl> m_edecl{};
  bbGCVar<t_mx2_EnumScope> m_scope{};
  bbGCVar<t_mx2_EnumType> m_superType{};
  bbInt m_nextInit{};

  void gcMark();

  t_mx2_EnumType(t_mx2_EnumDecl* l_edecl,t_mx2_Scope* l_outer);

  bbString m_TypeId();
  bbString m_ToString();
  t_mx2_SNode* m_OnSemant();
  bbString m_Name();
  t_mx2_SNode* m_FindNode(bbString l_ident);
  bbInt m_DistanceToType(t_mx2_Type* l_type);

  t_mx2_EnumType(){
  }
};

struct t_mx2_EnumDecl : public t_mx2_Decl{

  const char *typeName()const{return "t_mx2_EnumDecl";}

  bbGCVar<t_mx2_TypeExpr> m_superType{};

  void gcMark();

  t_mx2_SNode* m_ToNode(t_mx2_Scope* l_scope);

  t_mx2_EnumDecl(){
  }
};

struct t_mx2_EnumScope : public t_mx2_Scope{

  const char *typeName()const{return "t_mx2_EnumScope";}

  bbGCVar<t_mx2_EnumType> m_etype{};

  void gcMark();

  t_mx2_EnumScope(t_mx2_EnumType* l_etype,t_mx2_Scope* l_outer);

  t_mx2_EnumScope(){
  }
};

#endif
