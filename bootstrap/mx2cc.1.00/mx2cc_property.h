
#ifndef MX2_MX2CC_PROPERTY_H
#define MX2_MX2CC_PROPERTY_H

#include <bbmonkey.h>

// ***** External *****

#include "mx2cc_decl.h"
#include "mx2cc_func.h"
#include "mx2cc_value.h"

struct t_mx2_SNode;
struct t_mx2_Scope;
struct t_mx2_ClassScope;
struct t_mx2_Type;
struct t_mx2_Block;
struct t_mx2_Stmt;
struct t_mx2_PNode;

// ***** Internal *****

struct t_mx2_PropertyDecl;
struct t_mx2_PropertyList;
struct t_mx2_PropertyValue;

struct t_mx2_PropertyDecl : public t_mx2_Decl{

  const char *typeName()const{return "t_mx2_PropertyDecl";}

  bbGCVar<t_mx2_FuncDecl> m_getFunc{};
  bbGCVar<t_mx2_FuncDecl> m_setFunc{};

  void gcMark();

  t_mx2_SNode* m_ToNode(t_mx2_Scope* l_scope);

  t_mx2_PropertyDecl(){
  }
};

struct t_mx2_PropertyList : public t_mx2_FuncList{

  const char *typeName()const{return "t_mx2_PropertyList";}

  bbGCVar<t_mx2_PropertyDecl> m_pdecl{};
  bbGCVar<t_mx2_Scope> m_scope{};
  bbGCVar<t_mx2_ClassScope> m_cscope{};
  bbGCVar<t_mx2_FuncValue> m_getFunc{};
  bbGCVar<t_mx2_FuncValue> m_setFunc{};
  bbGCVar<t_mx2_Type> m_type{};

  void gcMark();

  t_mx2_PropertyList(t_mx2_PropertyDecl* l_pdecl,t_mx2_Scope* l_scope);

  t_mx2_Value* m_ToValue(t_mx2_Value* l_instance);
  bbString m_ToString();
  t_mx2_SNode* m_OnSemant();

  t_mx2_PropertyList(){
  }
};

struct t_mx2_PropertyValue : public t_mx2_Value{

  const char *typeName()const{return "t_mx2_PropertyValue";}

  bbGCVar<t_mx2_PropertyList> m_plist{};
  bbGCVar<t_mx2_Value> m_instance{};

  void gcMark();

  t_mx2_PropertyValue(t_mx2_PropertyList* l_plist,t_mx2_Value* l_instance);

  bbString m_ToString();
  t_mx2_Value* m_ToRValue();
  t_mx2_Value* m_RemoveSideEffects(t_mx2_Block* l_block);
  bbBool m_HasSideEffects();
  t_mx2_Stmt* m_Assign(t_mx2_PNode* l_pnode,bbString l_op,t_mx2_Value* l_rvalue,t_mx2_Block* l_block);

  t_mx2_PropertyValue(){
  }
};

#endif
