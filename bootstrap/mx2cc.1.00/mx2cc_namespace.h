
#ifndef MX2_MX2CC_NAMESPACE_H
#define MX2_MX2CC_NAMESPACE_H

#include <bbmonkey.h>

// ***** External *****

#include "mx2cc_scope.h"
#include "mx2cc_type.h"

struct t_mx2_SNode;

// ***** Internal *****

struct t_mx2_NamespaceType;
struct t_mx2_NamespaceScope;

struct t_mx2_NamespaceType : public t_mx2_Type{

  const char *typeName()const{return "t_mx2_NamespaceType";}

  bbString m_ident{};
  bbGCVar<t_mx2_NamespaceScope> m_scope{};

  void gcMark();

  t_mx2_NamespaceType(bbString l_ident,t_mx2_NamespaceScope* l_outer);

  bbString m_TypeId();
  bbString m_ToString();
  bbString m_Name();
  t_mx2_Type* m_FindType(bbString l_ident);
  t_mx2_SNode* m_FindNode(bbString l_ident);

  t_mx2_NamespaceType(){
  }
};

struct t_mx2_NamespaceScope : public t_mx2_Scope{

  const char *typeName()const{return "t_mx2_NamespaceScope";}

  bbGCVar<t_mx2_NamespaceType> m_ntype{};

  void gcMark();

  t_mx2_NamespaceScope(t_mx2_NamespaceType* l_ntype,t_mx2_NamespaceScope* l_outer);

  bbString m_TypeId();
  bbString m_ToString();
  bbString m_Name();
  t_mx2_NamespaceScope* m_FindRoot();

  t_mx2_NamespaceScope(){
  }
};

#endif
