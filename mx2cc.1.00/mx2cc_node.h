
#ifndef MX2_MX2CC_NODE_H
#define MX2_MX2CC_NODE_H

#include <bbmonkey.h>

// ***** External *****

#include "../../../../../modules/monkey/monkey.buildv1.0.0/desktop_release_linux/monkey_types.h"

struct t_mx2_FileDecl;
struct t_std_collections_Stack_1Tt_mx2_PNode_2;
struct t_mx2_Value;
struct t_mx2_Type;

// ***** Internal *****

struct t_mx2_SNode;
struct t_mx2_PNode;

extern bbBool g_mx2_DEBUG_0SEMANTS;
extern bbInt g_mx2_SNODE_0INIT;
extern bbInt g_mx2_SNODE_0SEMANTING;
extern bbInt g_mx2_SNODE_0SEMANTED;
extern bbString g_mx2_SNode_semtab;
extern bbGCRootVar<t_mx2_FileDecl> g_mx2_PNode_parsing;
extern bbGCRootVar<t_std_collections_Stack_1Tt_mx2_PNode_2> g_mx2_PNode_semanting;

struct t_mx2_SNode : public bbObject{

  const char *typeName()const{return "t_mx2_SNode";}

  bbGCVar<t_mx2_PNode> m_pnode{};
  bbGCVar<t_mx2_SNode> m_semanted{};
  bbInt m_state{};

  void gcMark();

  virtual t_mx2_Value* m_ToValue(t_mx2_Value* l_instance);
  virtual t_mx2_Type* m_ToType();
  virtual bbString m_ToString();
  t_mx2_SNode* m_Semant();
  virtual t_mx2_SNode* m_OnSemant();

  t_mx2_SNode(){
  }
};

struct t_mx2_PNode : public bbObject{

  const char *typeName()const{return "t_mx2_PNode";}

  bbGCVar<t_mx2_FileDecl> m_srcfile{};
  bbInt m_srcpos{};
  bbInt m_endpos{};

  void gcMark();

  t_mx2_PNode(bbInt l_srcpos,bbInt l_endpos);
  t_mx2_PNode();

  virtual bbString m_ToString();
  virtual bbString m_ToDebugString();
};

#endif
