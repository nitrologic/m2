
#ifndef MX2_MX2CC_STD_COLLECTIONS_2MAP_H
#define MX2_MX2CC_STD_COLLECTIONS_2MAP_H

#include <bbmonkey.h>
#include "../../../../../modules/std/std.buildv1.0.0/desktop_release_linux/std_collections_2map.h"

// ***** External *****

#include "../../../../../modules/monkey/monkey.buildv1.0.0/desktop_release_linux/monkey_types.h"

struct t_std_collections_Stack_1s;
struct t_mx2_Module;
struct t_mx2_SNode;
struct t_mx2_FileDecl;
struct t_mx2_ClassType;
struct t_mx2_VarValue;
struct t_mx2_NamespaceScope;

// ***** Internal *****

struct t_std_collections_Map_1sTt_std_collections_Stack_1s_2_Node;
struct t_std_collections_Map_1sTt_std_collections_Stack_1s_2_Iterator;
struct t_std_collections_Map_1sTt_std_collections_Stack_1s_2_KeyIterator;
struct t_std_collections_Map_1sTt_std_collections_Stack_1s_2_MapKeys;
struct t_std_collections_Map_1sTt_std_collections_Stack_1s_2_ValueIterator;
struct t_std_collections_Map_1sTt_std_collections_Stack_1s_2_MapValues;
struct t_std_collections_Map_1sTt_std_collections_Stack_1s_2;
struct t_std_collections_Map_1ss_Node;
struct t_std_collections_Map_1ss_Iterator;
struct t_std_collections_Map_1ss_KeyIterator;
struct t_std_collections_Map_1ss_MapKeys;
struct t_std_collections_Map_1ss_ValueIterator;
struct t_std_collections_Map_1ss_MapValues;
struct t_std_collections_Map_1ss;
struct t_std_collections_Map_1sz_Node;
struct t_std_collections_Map_1sz_Iterator;
struct t_std_collections_Map_1sz_KeyIterator;
struct t_std_collections_Map_1sz_MapKeys;
struct t_std_collections_Map_1sz_ValueIterator;
struct t_std_collections_Map_1sz_MapValues;
struct t_std_collections_Map_1sz;
struct t_std_collections_Map_1sTt_mx2_Module_2_Node;
struct t_std_collections_Map_1sTt_mx2_Module_2_Iterator;
struct t_std_collections_Map_1sTt_mx2_Module_2_KeyIterator;
struct t_std_collections_Map_1sTt_mx2_Module_2_MapKeys;
struct t_std_collections_Map_1sTt_mx2_Module_2_ValueIterator;
struct t_std_collections_Map_1sTt_mx2_Module_2_MapValues;
struct t_std_collections_Map_1sTt_mx2_Module_2;
struct t_std_collections_Map_1sTt_mx2_SNode_2_Node;
struct t_std_collections_Map_1sTt_mx2_SNode_2_Iterator;
struct t_std_collections_Map_1sTt_mx2_SNode_2_KeyIterator;
struct t_std_collections_Map_1sTt_mx2_SNode_2_MapKeys;
struct t_std_collections_Map_1sTt_mx2_SNode_2_ValueIterator;
struct t_std_collections_Map_1sTt_mx2_SNode_2_MapValues;
struct t_std_collections_Map_1sTt_mx2_SNode_2;
struct t_std_collections_Map_1sTt_mx2_FileDecl_2_Node;
struct t_std_collections_Map_1sTt_mx2_FileDecl_2_Iterator;
struct t_std_collections_Map_1sTt_mx2_FileDecl_2_KeyIterator;
struct t_std_collections_Map_1sTt_mx2_FileDecl_2_MapKeys;
struct t_std_collections_Map_1sTt_mx2_FileDecl_2_ValueIterator;
struct t_std_collections_Map_1sTt_mx2_FileDecl_2_MapValues;
struct t_std_collections_Map_1sTt_mx2_FileDecl_2;
struct t_std_collections_Map_1Tt_mx2_SNode_2z_Node;
struct t_std_collections_Map_1Tt_mx2_SNode_2z_Iterator;
struct t_std_collections_Map_1Tt_mx2_SNode_2z_KeyIterator;
struct t_std_collections_Map_1Tt_mx2_SNode_2z_MapKeys;
struct t_std_collections_Map_1Tt_mx2_SNode_2z_ValueIterator;
struct t_std_collections_Map_1Tt_mx2_SNode_2z_MapValues;
struct t_std_collections_Map_1Tt_mx2_SNode_2z;
struct t_std_collections_Map_1sTt_mx2_ClassType_2_Node;
struct t_std_collections_Map_1sTt_mx2_ClassType_2_Iterator;
struct t_std_collections_Map_1sTt_mx2_ClassType_2_KeyIterator;
struct t_std_collections_Map_1sTt_mx2_ClassType_2_MapKeys;
struct t_std_collections_Map_1sTt_mx2_ClassType_2_ValueIterator;
struct t_std_collections_Map_1sTt_mx2_ClassType_2_MapValues;
struct t_std_collections_Map_1sTt_mx2_ClassType_2;
struct t_std_collections_Map_1sTt_mx2_VarValue_2_Node;
struct t_std_collections_Map_1sTt_mx2_VarValue_2_Iterator;
struct t_std_collections_Map_1sTt_mx2_VarValue_2_KeyIterator;
struct t_std_collections_Map_1sTt_mx2_VarValue_2_MapKeys;
struct t_std_collections_Map_1sTt_mx2_VarValue_2_ValueIterator;
struct t_std_collections_Map_1sTt_mx2_VarValue_2_MapValues;
struct t_std_collections_Map_1sTt_mx2_VarValue_2;
struct t_std_collections_Map_1sTt_mx2_NamespaceScope_2_Node;
struct t_std_collections_Map_1sTt_mx2_NamespaceScope_2_Iterator;
struct t_std_collections_Map_1sTt_mx2_NamespaceScope_2_KeyIterator;
struct t_std_collections_Map_1sTt_mx2_NamespaceScope_2_MapKeys;
struct t_std_collections_Map_1sTt_mx2_NamespaceScope_2_ValueIterator;
struct t_std_collections_Map_1sTt_mx2_NamespaceScope_2_MapValues;
struct t_std_collections_Map_1sTt_mx2_NamespaceScope_2;

struct t_std_collections_Map_1sTt_std_collections_Stack_1s_2_Node : public bbObject{

  const char *typeName()const{return "t_std_collections_Map_1sTt_std_collections_Stack_1s_2_Node";}

  bbString m__0key{};
  bbGCVar<t_std_collections_Stack_1s> m__0value{};
  bbInt m__0color{};
  bbGCVar<t_std_collections_Map_1sTt_std_collections_Stack_1s_2_Node> m__0left{};
  bbGCVar<t_std_collections_Map_1sTt_std_collections_Stack_1s_2_Node> m__0right{};
  bbGCVar<t_std_collections_Map_1sTt_std_collections_Stack_1s_2_Node> m__0parent{};

  void gcMark();

  t_std_collections_Map_1sTt_std_collections_Stack_1s_2_Node(bbString l_key,t_std_collections_Stack_1s* l_value,bbInt l_color,t_std_collections_Map_1sTt_std_collections_Stack_1s_2_Node* l_parent);

  t_std_collections_Stack_1s* m_Value();
  t_std_collections_Map_1sTt_std_collections_Stack_1s_2_Node* m_PrevNode();
  t_std_collections_Map_1sTt_std_collections_Stack_1s_2_Node* m_NextNode();
  bbString m_Key();
  bbInt m_Count(bbInt l_n);
  t_std_collections_Map_1sTt_std_collections_Stack_1s_2_Node* m_Copy(t_std_collections_Map_1sTt_std_collections_Stack_1s_2_Node* l_parent);

  t_std_collections_Map_1sTt_std_collections_Stack_1s_2_Node(){
  }
};

struct t_std_collections_Map_1sTt_std_collections_Stack_1s_2_Iterator{
  const char *typeName()const{return "t_std_collections_Map_1sTt_std_collections_Stack_1s_2_Iterator";}

  bbGCVar<t_std_collections_Map_1sTt_std_collections_Stack_1s_2_Node> m__0node{};

  t_std_collections_Map_1sTt_std_collections_Stack_1s_2_Iterator(t_std_collections_Map_1sTt_std_collections_Stack_1s_2_Node* l_node);

  bbBool m_Valid();
  t_std_collections_Map_1sTt_std_collections_Stack_1s_2_Node* m_Current();
  void m_Bump();

  t_std_collections_Map_1sTt_std_collections_Stack_1s_2_Iterator(){
  }

  t_std_collections_Map_1sTt_std_collections_Stack_1s_2_Iterator(bbNullCtor_t){
  }
};

int bbCompare(const t_std_collections_Map_1sTt_std_collections_Stack_1s_2_Iterator&x,const t_std_collections_Map_1sTt_std_collections_Stack_1s_2_Iterator&y);

void bbGCMark(const t_std_collections_Map_1sTt_std_collections_Stack_1s_2_Iterator&);

struct t_std_collections_Map_1sTt_std_collections_Stack_1s_2_KeyIterator{
  const char *typeName()const{return "t_std_collections_Map_1sTt_std_collections_Stack_1s_2_KeyIterator";}

  bbGCVar<t_std_collections_Map_1sTt_std_collections_Stack_1s_2_Node> m__0node{};

  t_std_collections_Map_1sTt_std_collections_Stack_1s_2_KeyIterator(t_std_collections_Map_1sTt_std_collections_Stack_1s_2_Node* l_node);

  bbBool m_Valid();
  bbString m_Current();
  void m_Bump();

  t_std_collections_Map_1sTt_std_collections_Stack_1s_2_KeyIterator(){
  }

  t_std_collections_Map_1sTt_std_collections_Stack_1s_2_KeyIterator(bbNullCtor_t){
  }
};

int bbCompare(const t_std_collections_Map_1sTt_std_collections_Stack_1s_2_KeyIterator&x,const t_std_collections_Map_1sTt_std_collections_Stack_1s_2_KeyIterator&y);

void bbGCMark(const t_std_collections_Map_1sTt_std_collections_Stack_1s_2_KeyIterator&);

struct t_std_collections_Map_1sTt_std_collections_Stack_1s_2_MapKeys{
  const char *typeName()const{return "t_std_collections_Map_1sTt_std_collections_Stack_1s_2_MapKeys";}

  bbGCVar<t_std_collections_Map_1sTt_std_collections_Stack_1s_2> m__0map{};

  t_std_collections_Map_1sTt_std_collections_Stack_1s_2_MapKeys(t_std_collections_Map_1sTt_std_collections_Stack_1s_2* l_map);

  t_std_collections_Map_1sTt_std_collections_Stack_1s_2_KeyIterator m_All();

  t_std_collections_Map_1sTt_std_collections_Stack_1s_2_MapKeys(){
  }

  t_std_collections_Map_1sTt_std_collections_Stack_1s_2_MapKeys(bbNullCtor_t){
  }
};

int bbCompare(const t_std_collections_Map_1sTt_std_collections_Stack_1s_2_MapKeys&x,const t_std_collections_Map_1sTt_std_collections_Stack_1s_2_MapKeys&y);

void bbGCMark(const t_std_collections_Map_1sTt_std_collections_Stack_1s_2_MapKeys&);

struct t_std_collections_Map_1sTt_std_collections_Stack_1s_2_ValueIterator{
  const char *typeName()const{return "t_std_collections_Map_1sTt_std_collections_Stack_1s_2_ValueIterator";}

  bbGCVar<t_std_collections_Map_1sTt_std_collections_Stack_1s_2_Node> m__0node{};

  t_std_collections_Map_1sTt_std_collections_Stack_1s_2_ValueIterator(t_std_collections_Map_1sTt_std_collections_Stack_1s_2_Node* l_node);

  bbBool m_Valid();
  t_std_collections_Stack_1s* m_Current();
  void m_Bump();

  t_std_collections_Map_1sTt_std_collections_Stack_1s_2_ValueIterator(){
  }

  t_std_collections_Map_1sTt_std_collections_Stack_1s_2_ValueIterator(bbNullCtor_t){
  }
};

int bbCompare(const t_std_collections_Map_1sTt_std_collections_Stack_1s_2_ValueIterator&x,const t_std_collections_Map_1sTt_std_collections_Stack_1s_2_ValueIterator&y);

void bbGCMark(const t_std_collections_Map_1sTt_std_collections_Stack_1s_2_ValueIterator&);

struct t_std_collections_Map_1sTt_std_collections_Stack_1s_2_MapValues{
  const char *typeName()const{return "t_std_collections_Map_1sTt_std_collections_Stack_1s_2_MapValues";}

  bbGCVar<t_std_collections_Map_1sTt_std_collections_Stack_1s_2> m__0map{};

  t_std_collections_Map_1sTt_std_collections_Stack_1s_2_MapValues(t_std_collections_Map_1sTt_std_collections_Stack_1s_2* l_map);

  t_std_collections_Map_1sTt_std_collections_Stack_1s_2_ValueIterator m_All();

  t_std_collections_Map_1sTt_std_collections_Stack_1s_2_MapValues(){
  }

  t_std_collections_Map_1sTt_std_collections_Stack_1s_2_MapValues(bbNullCtor_t){
  }
};

int bbCompare(const t_std_collections_Map_1sTt_std_collections_Stack_1s_2_MapValues&x,const t_std_collections_Map_1sTt_std_collections_Stack_1s_2_MapValues&y);

void bbGCMark(const t_std_collections_Map_1sTt_std_collections_Stack_1s_2_MapValues&);

struct t_std_collections_Map_1sTt_std_collections_Stack_1s_2 : public bbObject{

  const char *typeName()const{return "t_std_collections_Map_1sTt_std_collections_Stack_1s_2";}

  bbGCVar<t_std_collections_Map_1sTt_std_collections_Stack_1s_2_Node> m__0root{};

  void gcMark();

  t_std_collections_Map_1sTt_std_collections_Stack_1s_2(t_std_collections_Map_1sTt_std_collections_Stack_1s_2_Node* l_root);
  t_std_collections_Map_1sTt_std_collections_Stack_1s_2();

  void m__idxeq(bbString l_key,t_std_collections_Stack_1s* l_value);
  t_std_collections_Stack_1s* m__idx(bbString l_key);
  t_std_collections_Map_1sTt_std_collections_Stack_1s_2_MapValues m_Values();
  bbBool m_Update(bbString l_key,t_std_collections_Stack_1s* l_value);
  bbBool m_Set(bbString l_key,t_std_collections_Stack_1s* l_value);
  void m_RotateRight(t_std_collections_Map_1sTt_std_collections_Stack_1s_2_Node* l_node);
  void m_RotateLeft(t_std_collections_Map_1sTt_std_collections_Stack_1s_2_Node* l_node);
  void m_RemoveNode(t_std_collections_Map_1sTt_std_collections_Stack_1s_2_Node* l_node);
  bbBool m_Remove(bbString l_key);
  t_std_collections_Map_1sTt_std_collections_Stack_1s_2_Node* m_LastNode();
  t_std_collections_Map_1sTt_std_collections_Stack_1s_2_MapKeys m_Keys();
  void m_InsertFixup(t_std_collections_Map_1sTt_std_collections_Stack_1s_2_Node* l_node);
  t_std_collections_Stack_1s* m_Get(bbString l_key);
  t_std_collections_Map_1sTt_std_collections_Stack_1s_2_Node* m_FirstNode();
  t_std_collections_Map_1sTt_std_collections_Stack_1s_2_Node* m_FindNode(bbString l_key);
  bbBool m_Empty();
  void m_DeleteFixup(t_std_collections_Map_1sTt_std_collections_Stack_1s_2_Node* l_node,t_std_collections_Map_1sTt_std_collections_Stack_1s_2_Node* l_parent);
  bbInt m_Count();
  t_std_collections_Map_1sTt_std_collections_Stack_1s_2* m_Copy();
  bbBool m_Contains(bbString l_key);
  void m_Clear();
  t_std_collections_Map_1sTt_std_collections_Stack_1s_2_Iterator m_All();
  bbBool m_Add(bbString l_key,t_std_collections_Stack_1s* l_value);
};

struct t_std_collections_Map_1ss_Node : public bbObject{

  const char *typeName()const{return "t_std_collections_Map_1ss_Node";}

  bbString m__0key{};
  bbString m__0value{};
  bbInt m__0color{};
  bbGCVar<t_std_collections_Map_1ss_Node> m__0left{};
  bbGCVar<t_std_collections_Map_1ss_Node> m__0right{};
  bbGCVar<t_std_collections_Map_1ss_Node> m__0parent{};

  void gcMark();

  t_std_collections_Map_1ss_Node(bbString l_key,bbString l_value,bbInt l_color,t_std_collections_Map_1ss_Node* l_parent);

  bbString m_Value();
  t_std_collections_Map_1ss_Node* m_PrevNode();
  t_std_collections_Map_1ss_Node* m_NextNode();
  bbString m_Key();
  bbInt m_Count(bbInt l_n);
  t_std_collections_Map_1ss_Node* m_Copy(t_std_collections_Map_1ss_Node* l_parent);

  t_std_collections_Map_1ss_Node(){
  }
};

struct t_std_collections_Map_1ss_Iterator{
  const char *typeName()const{return "t_std_collections_Map_1ss_Iterator";}

  bbGCVar<t_std_collections_Map_1ss_Node> m__0node{};

  t_std_collections_Map_1ss_Iterator(t_std_collections_Map_1ss_Node* l_node);

  bbBool m_Valid();
  t_std_collections_Map_1ss_Node* m_Current();
  void m_Bump();

  t_std_collections_Map_1ss_Iterator(){
  }

  t_std_collections_Map_1ss_Iterator(bbNullCtor_t){
  }
};

int bbCompare(const t_std_collections_Map_1ss_Iterator&x,const t_std_collections_Map_1ss_Iterator&y);

void bbGCMark(const t_std_collections_Map_1ss_Iterator&);

struct t_std_collections_Map_1ss_KeyIterator{
  const char *typeName()const{return "t_std_collections_Map_1ss_KeyIterator";}

  bbGCVar<t_std_collections_Map_1ss_Node> m__0node{};

  t_std_collections_Map_1ss_KeyIterator(t_std_collections_Map_1ss_Node* l_node);

  bbBool m_Valid();
  bbString m_Current();
  void m_Bump();

  t_std_collections_Map_1ss_KeyIterator(){
  }

  t_std_collections_Map_1ss_KeyIterator(bbNullCtor_t){
  }
};

int bbCompare(const t_std_collections_Map_1ss_KeyIterator&x,const t_std_collections_Map_1ss_KeyIterator&y);

void bbGCMark(const t_std_collections_Map_1ss_KeyIterator&);

struct t_std_collections_Map_1ss_MapKeys{
  const char *typeName()const{return "t_std_collections_Map_1ss_MapKeys";}

  bbGCVar<t_std_collections_Map_1ss> m__0map{};

  t_std_collections_Map_1ss_MapKeys(t_std_collections_Map_1ss* l_map);

  t_std_collections_Map_1ss_KeyIterator m_All();

  t_std_collections_Map_1ss_MapKeys(){
  }

  t_std_collections_Map_1ss_MapKeys(bbNullCtor_t){
  }
};

int bbCompare(const t_std_collections_Map_1ss_MapKeys&x,const t_std_collections_Map_1ss_MapKeys&y);

void bbGCMark(const t_std_collections_Map_1ss_MapKeys&);

struct t_std_collections_Map_1ss_ValueIterator{
  const char *typeName()const{return "t_std_collections_Map_1ss_ValueIterator";}

  bbGCVar<t_std_collections_Map_1ss_Node> m__0node{};

  t_std_collections_Map_1ss_ValueIterator(t_std_collections_Map_1ss_Node* l_node);

  bbBool m_Valid();
  bbString m_Current();
  void m_Bump();

  t_std_collections_Map_1ss_ValueIterator(){
  }

  t_std_collections_Map_1ss_ValueIterator(bbNullCtor_t){
  }
};

int bbCompare(const t_std_collections_Map_1ss_ValueIterator&x,const t_std_collections_Map_1ss_ValueIterator&y);

void bbGCMark(const t_std_collections_Map_1ss_ValueIterator&);

struct t_std_collections_Map_1ss_MapValues{
  const char *typeName()const{return "t_std_collections_Map_1ss_MapValues";}

  bbGCVar<t_std_collections_Map_1ss> m__0map{};

  t_std_collections_Map_1ss_MapValues(t_std_collections_Map_1ss* l_map);

  t_std_collections_Map_1ss_ValueIterator m_All();

  t_std_collections_Map_1ss_MapValues(){
  }

  t_std_collections_Map_1ss_MapValues(bbNullCtor_t){
  }
};

int bbCompare(const t_std_collections_Map_1ss_MapValues&x,const t_std_collections_Map_1ss_MapValues&y);

void bbGCMark(const t_std_collections_Map_1ss_MapValues&);

struct t_std_collections_Map_1ss : public bbObject{

  const char *typeName()const{return "t_std_collections_Map_1ss";}

  bbGCVar<t_std_collections_Map_1ss_Node> m__0root{};

  void gcMark();

  t_std_collections_Map_1ss(t_std_collections_Map_1ss_Node* l_root);
  t_std_collections_Map_1ss();

  void m__idxeq(bbString l_key,bbString l_value);
  bbString m__idx(bbString l_key);
  t_std_collections_Map_1ss_MapValues m_Values();
  bbBool m_Update(bbString l_key,bbString l_value);
  bbBool m_Set(bbString l_key,bbString l_value);
  void m_RotateRight(t_std_collections_Map_1ss_Node* l_node);
  void m_RotateLeft(t_std_collections_Map_1ss_Node* l_node);
  void m_RemoveNode(t_std_collections_Map_1ss_Node* l_node);
  bbBool m_Remove(bbString l_key);
  t_std_collections_Map_1ss_Node* m_LastNode();
  t_std_collections_Map_1ss_MapKeys m_Keys();
  void m_InsertFixup(t_std_collections_Map_1ss_Node* l_node);
  bbString m_Get(bbString l_key);
  t_std_collections_Map_1ss_Node* m_FirstNode();
  t_std_collections_Map_1ss_Node* m_FindNode(bbString l_key);
  bbBool m_Empty();
  void m_DeleteFixup(t_std_collections_Map_1ss_Node* l_node,t_std_collections_Map_1ss_Node* l_parent);
  bbInt m_Count();
  t_std_collections_Map_1ss* m_Copy();
  bbBool m_Contains(bbString l_key);
  void m_Clear();
  t_std_collections_Map_1ss_Iterator m_All();
  bbBool m_Add(bbString l_key,bbString l_value);
};

struct t_std_collections_Map_1sz_Node : public bbObject{

  const char *typeName()const{return "t_std_collections_Map_1sz_Node";}

  bbString m__0key{};
  bbBool m__0value{};
  bbInt m__0color{};
  bbGCVar<t_std_collections_Map_1sz_Node> m__0left{};
  bbGCVar<t_std_collections_Map_1sz_Node> m__0right{};
  bbGCVar<t_std_collections_Map_1sz_Node> m__0parent{};

  void gcMark();

  t_std_collections_Map_1sz_Node(bbString l_key,bbBool l_value,bbInt l_color,t_std_collections_Map_1sz_Node* l_parent);

  bbBool m_Value();
  t_std_collections_Map_1sz_Node* m_PrevNode();
  t_std_collections_Map_1sz_Node* m_NextNode();
  bbString m_Key();
  bbInt m_Count(bbInt l_n);
  t_std_collections_Map_1sz_Node* m_Copy(t_std_collections_Map_1sz_Node* l_parent);

  t_std_collections_Map_1sz_Node(){
  }
};

struct t_std_collections_Map_1sz_Iterator{
  const char *typeName()const{return "t_std_collections_Map_1sz_Iterator";}

  bbGCVar<t_std_collections_Map_1sz_Node> m__0node{};

  t_std_collections_Map_1sz_Iterator(t_std_collections_Map_1sz_Node* l_node);

  bbBool m_Valid();
  t_std_collections_Map_1sz_Node* m_Current();
  void m_Bump();

  t_std_collections_Map_1sz_Iterator(){
  }

  t_std_collections_Map_1sz_Iterator(bbNullCtor_t){
  }
};

int bbCompare(const t_std_collections_Map_1sz_Iterator&x,const t_std_collections_Map_1sz_Iterator&y);

void bbGCMark(const t_std_collections_Map_1sz_Iterator&);

struct t_std_collections_Map_1sz_KeyIterator{
  const char *typeName()const{return "t_std_collections_Map_1sz_KeyIterator";}

  bbGCVar<t_std_collections_Map_1sz_Node> m__0node{};

  t_std_collections_Map_1sz_KeyIterator(t_std_collections_Map_1sz_Node* l_node);

  bbBool m_Valid();
  bbString m_Current();
  void m_Bump();

  t_std_collections_Map_1sz_KeyIterator(){
  }

  t_std_collections_Map_1sz_KeyIterator(bbNullCtor_t){
  }
};

int bbCompare(const t_std_collections_Map_1sz_KeyIterator&x,const t_std_collections_Map_1sz_KeyIterator&y);

void bbGCMark(const t_std_collections_Map_1sz_KeyIterator&);

struct t_std_collections_Map_1sz_MapKeys{
  const char *typeName()const{return "t_std_collections_Map_1sz_MapKeys";}

  bbGCVar<t_std_collections_Map_1sz> m__0map{};

  t_std_collections_Map_1sz_MapKeys(t_std_collections_Map_1sz* l_map);

  t_std_collections_Map_1sz_KeyIterator m_All();

  t_std_collections_Map_1sz_MapKeys(){
  }

  t_std_collections_Map_1sz_MapKeys(bbNullCtor_t){
  }
};

int bbCompare(const t_std_collections_Map_1sz_MapKeys&x,const t_std_collections_Map_1sz_MapKeys&y);

void bbGCMark(const t_std_collections_Map_1sz_MapKeys&);

struct t_std_collections_Map_1sz_ValueIterator{
  const char *typeName()const{return "t_std_collections_Map_1sz_ValueIterator";}

  bbGCVar<t_std_collections_Map_1sz_Node> m__0node{};

  t_std_collections_Map_1sz_ValueIterator(t_std_collections_Map_1sz_Node* l_node);

  bbBool m_Valid();
  bbBool m_Current();
  void m_Bump();

  t_std_collections_Map_1sz_ValueIterator(){
  }

  t_std_collections_Map_1sz_ValueIterator(bbNullCtor_t){
  }
};

int bbCompare(const t_std_collections_Map_1sz_ValueIterator&x,const t_std_collections_Map_1sz_ValueIterator&y);

void bbGCMark(const t_std_collections_Map_1sz_ValueIterator&);

struct t_std_collections_Map_1sz_MapValues{
  const char *typeName()const{return "t_std_collections_Map_1sz_MapValues";}

  bbGCVar<t_std_collections_Map_1sz> m__0map{};

  t_std_collections_Map_1sz_MapValues(t_std_collections_Map_1sz* l_map);

  t_std_collections_Map_1sz_ValueIterator m_All();

  t_std_collections_Map_1sz_MapValues(){
  }

  t_std_collections_Map_1sz_MapValues(bbNullCtor_t){
  }
};

int bbCompare(const t_std_collections_Map_1sz_MapValues&x,const t_std_collections_Map_1sz_MapValues&y);

void bbGCMark(const t_std_collections_Map_1sz_MapValues&);

struct t_std_collections_Map_1sz : public bbObject{

  const char *typeName()const{return "t_std_collections_Map_1sz";}

  bbGCVar<t_std_collections_Map_1sz_Node> m__0root{};

  void gcMark();

  t_std_collections_Map_1sz(t_std_collections_Map_1sz_Node* l_root);
  t_std_collections_Map_1sz();

  void m__idxeq(bbString l_key,bbBool l_value);
  bbBool m__idx(bbString l_key);
  t_std_collections_Map_1sz_MapValues m_Values();
  bbBool m_Update(bbString l_key,bbBool l_value);
  bbBool m_Set(bbString l_key,bbBool l_value);
  void m_RotateRight(t_std_collections_Map_1sz_Node* l_node);
  void m_RotateLeft(t_std_collections_Map_1sz_Node* l_node);
  void m_RemoveNode(t_std_collections_Map_1sz_Node* l_node);
  bbBool m_Remove(bbString l_key);
  t_std_collections_Map_1sz_Node* m_LastNode();
  t_std_collections_Map_1sz_MapKeys m_Keys();
  void m_InsertFixup(t_std_collections_Map_1sz_Node* l_node);
  bbBool m_Get(bbString l_key);
  t_std_collections_Map_1sz_Node* m_FirstNode();
  t_std_collections_Map_1sz_Node* m_FindNode(bbString l_key);
  bbBool m_Empty();
  void m_DeleteFixup(t_std_collections_Map_1sz_Node* l_node,t_std_collections_Map_1sz_Node* l_parent);
  bbInt m_Count();
  t_std_collections_Map_1sz* m_Copy();
  bbBool m_Contains(bbString l_key);
  void m_Clear();
  t_std_collections_Map_1sz_Iterator m_All();
  bbBool m_Add(bbString l_key,bbBool l_value);
};

struct t_std_collections_Map_1sTt_mx2_Module_2_Node : public bbObject{

  const char *typeName()const{return "t_std_collections_Map_1sTt_mx2_Module_2_Node";}

  bbString m__0key{};
  bbGCVar<t_mx2_Module> m__0value{};
  bbInt m__0color{};
  bbGCVar<t_std_collections_Map_1sTt_mx2_Module_2_Node> m__0left{};
  bbGCVar<t_std_collections_Map_1sTt_mx2_Module_2_Node> m__0right{};
  bbGCVar<t_std_collections_Map_1sTt_mx2_Module_2_Node> m__0parent{};

  void gcMark();

  t_std_collections_Map_1sTt_mx2_Module_2_Node(bbString l_key,t_mx2_Module* l_value,bbInt l_color,t_std_collections_Map_1sTt_mx2_Module_2_Node* l_parent);

  t_mx2_Module* m_Value();
  t_std_collections_Map_1sTt_mx2_Module_2_Node* m_PrevNode();
  t_std_collections_Map_1sTt_mx2_Module_2_Node* m_NextNode();
  bbString m_Key();
  bbInt m_Count(bbInt l_n);
  t_std_collections_Map_1sTt_mx2_Module_2_Node* m_Copy(t_std_collections_Map_1sTt_mx2_Module_2_Node* l_parent);

  t_std_collections_Map_1sTt_mx2_Module_2_Node(){
  }
};

struct t_std_collections_Map_1sTt_mx2_Module_2_Iterator{
  const char *typeName()const{return "t_std_collections_Map_1sTt_mx2_Module_2_Iterator";}

  bbGCVar<t_std_collections_Map_1sTt_mx2_Module_2_Node> m__0node{};

  t_std_collections_Map_1sTt_mx2_Module_2_Iterator(t_std_collections_Map_1sTt_mx2_Module_2_Node* l_node);

  bbBool m_Valid();
  t_std_collections_Map_1sTt_mx2_Module_2_Node* m_Current();
  void m_Bump();

  t_std_collections_Map_1sTt_mx2_Module_2_Iterator(){
  }

  t_std_collections_Map_1sTt_mx2_Module_2_Iterator(bbNullCtor_t){
  }
};

int bbCompare(const t_std_collections_Map_1sTt_mx2_Module_2_Iterator&x,const t_std_collections_Map_1sTt_mx2_Module_2_Iterator&y);

void bbGCMark(const t_std_collections_Map_1sTt_mx2_Module_2_Iterator&);

struct t_std_collections_Map_1sTt_mx2_Module_2_KeyIterator{
  const char *typeName()const{return "t_std_collections_Map_1sTt_mx2_Module_2_KeyIterator";}

  bbGCVar<t_std_collections_Map_1sTt_mx2_Module_2_Node> m__0node{};

  t_std_collections_Map_1sTt_mx2_Module_2_KeyIterator(t_std_collections_Map_1sTt_mx2_Module_2_Node* l_node);

  bbBool m_Valid();
  bbString m_Current();
  void m_Bump();

  t_std_collections_Map_1sTt_mx2_Module_2_KeyIterator(){
  }

  t_std_collections_Map_1sTt_mx2_Module_2_KeyIterator(bbNullCtor_t){
  }
};

int bbCompare(const t_std_collections_Map_1sTt_mx2_Module_2_KeyIterator&x,const t_std_collections_Map_1sTt_mx2_Module_2_KeyIterator&y);

void bbGCMark(const t_std_collections_Map_1sTt_mx2_Module_2_KeyIterator&);

struct t_std_collections_Map_1sTt_mx2_Module_2_MapKeys{
  const char *typeName()const{return "t_std_collections_Map_1sTt_mx2_Module_2_MapKeys";}

  bbGCVar<t_std_collections_Map_1sTt_mx2_Module_2> m__0map{};

  t_std_collections_Map_1sTt_mx2_Module_2_MapKeys(t_std_collections_Map_1sTt_mx2_Module_2* l_map);

  t_std_collections_Map_1sTt_mx2_Module_2_KeyIterator m_All();

  t_std_collections_Map_1sTt_mx2_Module_2_MapKeys(){
  }

  t_std_collections_Map_1sTt_mx2_Module_2_MapKeys(bbNullCtor_t){
  }
};

int bbCompare(const t_std_collections_Map_1sTt_mx2_Module_2_MapKeys&x,const t_std_collections_Map_1sTt_mx2_Module_2_MapKeys&y);

void bbGCMark(const t_std_collections_Map_1sTt_mx2_Module_2_MapKeys&);

struct t_std_collections_Map_1sTt_mx2_Module_2_ValueIterator{
  const char *typeName()const{return "t_std_collections_Map_1sTt_mx2_Module_2_ValueIterator";}

  bbGCVar<t_std_collections_Map_1sTt_mx2_Module_2_Node> m__0node{};

  t_std_collections_Map_1sTt_mx2_Module_2_ValueIterator(t_std_collections_Map_1sTt_mx2_Module_2_Node* l_node);

  bbBool m_Valid();
  t_mx2_Module* m_Current();
  void m_Bump();

  t_std_collections_Map_1sTt_mx2_Module_2_ValueIterator(){
  }

  t_std_collections_Map_1sTt_mx2_Module_2_ValueIterator(bbNullCtor_t){
  }
};

int bbCompare(const t_std_collections_Map_1sTt_mx2_Module_2_ValueIterator&x,const t_std_collections_Map_1sTt_mx2_Module_2_ValueIterator&y);

void bbGCMark(const t_std_collections_Map_1sTt_mx2_Module_2_ValueIterator&);

struct t_std_collections_Map_1sTt_mx2_Module_2_MapValues{
  const char *typeName()const{return "t_std_collections_Map_1sTt_mx2_Module_2_MapValues";}

  bbGCVar<t_std_collections_Map_1sTt_mx2_Module_2> m__0map{};

  t_std_collections_Map_1sTt_mx2_Module_2_MapValues(t_std_collections_Map_1sTt_mx2_Module_2* l_map);

  t_std_collections_Map_1sTt_mx2_Module_2_ValueIterator m_All();

  t_std_collections_Map_1sTt_mx2_Module_2_MapValues(){
  }

  t_std_collections_Map_1sTt_mx2_Module_2_MapValues(bbNullCtor_t){
  }
};

int bbCompare(const t_std_collections_Map_1sTt_mx2_Module_2_MapValues&x,const t_std_collections_Map_1sTt_mx2_Module_2_MapValues&y);

void bbGCMark(const t_std_collections_Map_1sTt_mx2_Module_2_MapValues&);

struct t_std_collections_Map_1sTt_mx2_Module_2 : public bbObject{

  const char *typeName()const{return "t_std_collections_Map_1sTt_mx2_Module_2";}

  bbGCVar<t_std_collections_Map_1sTt_mx2_Module_2_Node> m__0root{};

  void gcMark();

  t_std_collections_Map_1sTt_mx2_Module_2(t_std_collections_Map_1sTt_mx2_Module_2_Node* l_root);
  t_std_collections_Map_1sTt_mx2_Module_2();

  void m__idxeq(bbString l_key,t_mx2_Module* l_value);
  t_mx2_Module* m__idx(bbString l_key);
  t_std_collections_Map_1sTt_mx2_Module_2_MapValues m_Values();
  bbBool m_Update(bbString l_key,t_mx2_Module* l_value);
  bbBool m_Set(bbString l_key,t_mx2_Module* l_value);
  void m_RotateRight(t_std_collections_Map_1sTt_mx2_Module_2_Node* l_node);
  void m_RotateLeft(t_std_collections_Map_1sTt_mx2_Module_2_Node* l_node);
  void m_RemoveNode(t_std_collections_Map_1sTt_mx2_Module_2_Node* l_node);
  bbBool m_Remove(bbString l_key);
  t_std_collections_Map_1sTt_mx2_Module_2_Node* m_LastNode();
  t_std_collections_Map_1sTt_mx2_Module_2_MapKeys m_Keys();
  void m_InsertFixup(t_std_collections_Map_1sTt_mx2_Module_2_Node* l_node);
  t_mx2_Module* m_Get(bbString l_key);
  t_std_collections_Map_1sTt_mx2_Module_2_Node* m_FirstNode();
  t_std_collections_Map_1sTt_mx2_Module_2_Node* m_FindNode(bbString l_key);
  bbBool m_Empty();
  void m_DeleteFixup(t_std_collections_Map_1sTt_mx2_Module_2_Node* l_node,t_std_collections_Map_1sTt_mx2_Module_2_Node* l_parent);
  bbInt m_Count();
  t_std_collections_Map_1sTt_mx2_Module_2* m_Copy();
  bbBool m_Contains(bbString l_key);
  void m_Clear();
  t_std_collections_Map_1sTt_mx2_Module_2_Iterator m_All();
  bbBool m_Add(bbString l_key,t_mx2_Module* l_value);
};

struct t_std_collections_Map_1sTt_mx2_SNode_2_Node : public bbObject{

  const char *typeName()const{return "t_std_collections_Map_1sTt_mx2_SNode_2_Node";}

  bbString m__0key{};
  bbGCVar<t_mx2_SNode> m__0value{};
  bbInt m__0color{};
  bbGCVar<t_std_collections_Map_1sTt_mx2_SNode_2_Node> m__0left{};
  bbGCVar<t_std_collections_Map_1sTt_mx2_SNode_2_Node> m__0right{};
  bbGCVar<t_std_collections_Map_1sTt_mx2_SNode_2_Node> m__0parent{};

  void gcMark();

  t_std_collections_Map_1sTt_mx2_SNode_2_Node(bbString l_key,t_mx2_SNode* l_value,bbInt l_color,t_std_collections_Map_1sTt_mx2_SNode_2_Node* l_parent);

  t_mx2_SNode* m_Value();
  t_std_collections_Map_1sTt_mx2_SNode_2_Node* m_PrevNode();
  t_std_collections_Map_1sTt_mx2_SNode_2_Node* m_NextNode();
  bbString m_Key();
  bbInt m_Count(bbInt l_n);
  t_std_collections_Map_1sTt_mx2_SNode_2_Node* m_Copy(t_std_collections_Map_1sTt_mx2_SNode_2_Node* l_parent);

  t_std_collections_Map_1sTt_mx2_SNode_2_Node(){
  }
};

struct t_std_collections_Map_1sTt_mx2_SNode_2_Iterator{
  const char *typeName()const{return "t_std_collections_Map_1sTt_mx2_SNode_2_Iterator";}

  bbGCVar<t_std_collections_Map_1sTt_mx2_SNode_2_Node> m__0node{};

  t_std_collections_Map_1sTt_mx2_SNode_2_Iterator(t_std_collections_Map_1sTt_mx2_SNode_2_Node* l_node);

  bbBool m_Valid();
  t_std_collections_Map_1sTt_mx2_SNode_2_Node* m_Current();
  void m_Bump();

  t_std_collections_Map_1sTt_mx2_SNode_2_Iterator(){
  }

  t_std_collections_Map_1sTt_mx2_SNode_2_Iterator(bbNullCtor_t){
  }
};

int bbCompare(const t_std_collections_Map_1sTt_mx2_SNode_2_Iterator&x,const t_std_collections_Map_1sTt_mx2_SNode_2_Iterator&y);

void bbGCMark(const t_std_collections_Map_1sTt_mx2_SNode_2_Iterator&);

struct t_std_collections_Map_1sTt_mx2_SNode_2_KeyIterator{
  const char *typeName()const{return "t_std_collections_Map_1sTt_mx2_SNode_2_KeyIterator";}

  bbGCVar<t_std_collections_Map_1sTt_mx2_SNode_2_Node> m__0node{};

  t_std_collections_Map_1sTt_mx2_SNode_2_KeyIterator(t_std_collections_Map_1sTt_mx2_SNode_2_Node* l_node);

  bbBool m_Valid();
  bbString m_Current();
  void m_Bump();

  t_std_collections_Map_1sTt_mx2_SNode_2_KeyIterator(){
  }

  t_std_collections_Map_1sTt_mx2_SNode_2_KeyIterator(bbNullCtor_t){
  }
};

int bbCompare(const t_std_collections_Map_1sTt_mx2_SNode_2_KeyIterator&x,const t_std_collections_Map_1sTt_mx2_SNode_2_KeyIterator&y);

void bbGCMark(const t_std_collections_Map_1sTt_mx2_SNode_2_KeyIterator&);

struct t_std_collections_Map_1sTt_mx2_SNode_2_MapKeys{
  const char *typeName()const{return "t_std_collections_Map_1sTt_mx2_SNode_2_MapKeys";}

  bbGCVar<t_std_collections_Map_1sTt_mx2_SNode_2> m__0map{};

  t_std_collections_Map_1sTt_mx2_SNode_2_MapKeys(t_std_collections_Map_1sTt_mx2_SNode_2* l_map);

  t_std_collections_Map_1sTt_mx2_SNode_2_KeyIterator m_All();

  t_std_collections_Map_1sTt_mx2_SNode_2_MapKeys(){
  }

  t_std_collections_Map_1sTt_mx2_SNode_2_MapKeys(bbNullCtor_t){
  }
};

int bbCompare(const t_std_collections_Map_1sTt_mx2_SNode_2_MapKeys&x,const t_std_collections_Map_1sTt_mx2_SNode_2_MapKeys&y);

void bbGCMark(const t_std_collections_Map_1sTt_mx2_SNode_2_MapKeys&);

struct t_std_collections_Map_1sTt_mx2_SNode_2_ValueIterator{
  const char *typeName()const{return "t_std_collections_Map_1sTt_mx2_SNode_2_ValueIterator";}

  bbGCVar<t_std_collections_Map_1sTt_mx2_SNode_2_Node> m__0node{};

  t_std_collections_Map_1sTt_mx2_SNode_2_ValueIterator(t_std_collections_Map_1sTt_mx2_SNode_2_Node* l_node);

  bbBool m_Valid();
  t_mx2_SNode* m_Current();
  void m_Bump();

  t_std_collections_Map_1sTt_mx2_SNode_2_ValueIterator(){
  }

  t_std_collections_Map_1sTt_mx2_SNode_2_ValueIterator(bbNullCtor_t){
  }
};

int bbCompare(const t_std_collections_Map_1sTt_mx2_SNode_2_ValueIterator&x,const t_std_collections_Map_1sTt_mx2_SNode_2_ValueIterator&y);

void bbGCMark(const t_std_collections_Map_1sTt_mx2_SNode_2_ValueIterator&);

struct t_std_collections_Map_1sTt_mx2_SNode_2_MapValues{
  const char *typeName()const{return "t_std_collections_Map_1sTt_mx2_SNode_2_MapValues";}

  bbGCVar<t_std_collections_Map_1sTt_mx2_SNode_2> m__0map{};

  t_std_collections_Map_1sTt_mx2_SNode_2_MapValues(t_std_collections_Map_1sTt_mx2_SNode_2* l_map);

  t_std_collections_Map_1sTt_mx2_SNode_2_ValueIterator m_All();

  t_std_collections_Map_1sTt_mx2_SNode_2_MapValues(){
  }

  t_std_collections_Map_1sTt_mx2_SNode_2_MapValues(bbNullCtor_t){
  }
};

int bbCompare(const t_std_collections_Map_1sTt_mx2_SNode_2_MapValues&x,const t_std_collections_Map_1sTt_mx2_SNode_2_MapValues&y);

void bbGCMark(const t_std_collections_Map_1sTt_mx2_SNode_2_MapValues&);

struct t_std_collections_Map_1sTt_mx2_SNode_2 : public bbObject{

  const char *typeName()const{return "t_std_collections_Map_1sTt_mx2_SNode_2";}

  bbGCVar<t_std_collections_Map_1sTt_mx2_SNode_2_Node> m__0root{};

  void gcMark();

  t_std_collections_Map_1sTt_mx2_SNode_2(t_std_collections_Map_1sTt_mx2_SNode_2_Node* l_root);
  t_std_collections_Map_1sTt_mx2_SNode_2();

  void m__idxeq(bbString l_key,t_mx2_SNode* l_value);
  t_mx2_SNode* m__idx(bbString l_key);
  t_std_collections_Map_1sTt_mx2_SNode_2_MapValues m_Values();
  bbBool m_Update(bbString l_key,t_mx2_SNode* l_value);
  bbBool m_Set(bbString l_key,t_mx2_SNode* l_value);
  void m_RotateRight(t_std_collections_Map_1sTt_mx2_SNode_2_Node* l_node);
  void m_RotateLeft(t_std_collections_Map_1sTt_mx2_SNode_2_Node* l_node);
  void m_RemoveNode(t_std_collections_Map_1sTt_mx2_SNode_2_Node* l_node);
  bbBool m_Remove(bbString l_key);
  t_std_collections_Map_1sTt_mx2_SNode_2_Node* m_LastNode();
  t_std_collections_Map_1sTt_mx2_SNode_2_MapKeys m_Keys();
  void m_InsertFixup(t_std_collections_Map_1sTt_mx2_SNode_2_Node* l_node);
  t_mx2_SNode* m_Get(bbString l_key);
  t_std_collections_Map_1sTt_mx2_SNode_2_Node* m_FirstNode();
  t_std_collections_Map_1sTt_mx2_SNode_2_Node* m_FindNode(bbString l_key);
  bbBool m_Empty();
  void m_DeleteFixup(t_std_collections_Map_1sTt_mx2_SNode_2_Node* l_node,t_std_collections_Map_1sTt_mx2_SNode_2_Node* l_parent);
  bbInt m_Count();
  t_std_collections_Map_1sTt_mx2_SNode_2* m_Copy();
  bbBool m_Contains(bbString l_key);
  void m_Clear();
  t_std_collections_Map_1sTt_mx2_SNode_2_Iterator m_All();
  bbBool m_Add(bbString l_key,t_mx2_SNode* l_value);
};

struct t_std_collections_Map_1sTt_mx2_FileDecl_2_Node : public bbObject{

  const char *typeName()const{return "t_std_collections_Map_1sTt_mx2_FileDecl_2_Node";}

  bbString m__0key{};
  bbGCVar<t_mx2_FileDecl> m__0value{};
  bbInt m__0color{};
  bbGCVar<t_std_collections_Map_1sTt_mx2_FileDecl_2_Node> m__0left{};
  bbGCVar<t_std_collections_Map_1sTt_mx2_FileDecl_2_Node> m__0right{};
  bbGCVar<t_std_collections_Map_1sTt_mx2_FileDecl_2_Node> m__0parent{};

  void gcMark();

  t_std_collections_Map_1sTt_mx2_FileDecl_2_Node(bbString l_key,t_mx2_FileDecl* l_value,bbInt l_color,t_std_collections_Map_1sTt_mx2_FileDecl_2_Node* l_parent);

  t_mx2_FileDecl* m_Value();
  t_std_collections_Map_1sTt_mx2_FileDecl_2_Node* m_PrevNode();
  t_std_collections_Map_1sTt_mx2_FileDecl_2_Node* m_NextNode();
  bbString m_Key();
  bbInt m_Count(bbInt l_n);
  t_std_collections_Map_1sTt_mx2_FileDecl_2_Node* m_Copy(t_std_collections_Map_1sTt_mx2_FileDecl_2_Node* l_parent);

  t_std_collections_Map_1sTt_mx2_FileDecl_2_Node(){
  }
};

struct t_std_collections_Map_1sTt_mx2_FileDecl_2_Iterator{
  const char *typeName()const{return "t_std_collections_Map_1sTt_mx2_FileDecl_2_Iterator";}

  bbGCVar<t_std_collections_Map_1sTt_mx2_FileDecl_2_Node> m__0node{};

  t_std_collections_Map_1sTt_mx2_FileDecl_2_Iterator(t_std_collections_Map_1sTt_mx2_FileDecl_2_Node* l_node);

  bbBool m_Valid();
  t_std_collections_Map_1sTt_mx2_FileDecl_2_Node* m_Current();
  void m_Bump();

  t_std_collections_Map_1sTt_mx2_FileDecl_2_Iterator(){
  }

  t_std_collections_Map_1sTt_mx2_FileDecl_2_Iterator(bbNullCtor_t){
  }
};

int bbCompare(const t_std_collections_Map_1sTt_mx2_FileDecl_2_Iterator&x,const t_std_collections_Map_1sTt_mx2_FileDecl_2_Iterator&y);

void bbGCMark(const t_std_collections_Map_1sTt_mx2_FileDecl_2_Iterator&);

struct t_std_collections_Map_1sTt_mx2_FileDecl_2_KeyIterator{
  const char *typeName()const{return "t_std_collections_Map_1sTt_mx2_FileDecl_2_KeyIterator";}

  bbGCVar<t_std_collections_Map_1sTt_mx2_FileDecl_2_Node> m__0node{};

  t_std_collections_Map_1sTt_mx2_FileDecl_2_KeyIterator(t_std_collections_Map_1sTt_mx2_FileDecl_2_Node* l_node);

  bbBool m_Valid();
  bbString m_Current();
  void m_Bump();

  t_std_collections_Map_1sTt_mx2_FileDecl_2_KeyIterator(){
  }

  t_std_collections_Map_1sTt_mx2_FileDecl_2_KeyIterator(bbNullCtor_t){
  }
};

int bbCompare(const t_std_collections_Map_1sTt_mx2_FileDecl_2_KeyIterator&x,const t_std_collections_Map_1sTt_mx2_FileDecl_2_KeyIterator&y);

void bbGCMark(const t_std_collections_Map_1sTt_mx2_FileDecl_2_KeyIterator&);

struct t_std_collections_Map_1sTt_mx2_FileDecl_2_MapKeys{
  const char *typeName()const{return "t_std_collections_Map_1sTt_mx2_FileDecl_2_MapKeys";}

  bbGCVar<t_std_collections_Map_1sTt_mx2_FileDecl_2> m__0map{};

  t_std_collections_Map_1sTt_mx2_FileDecl_2_MapKeys(t_std_collections_Map_1sTt_mx2_FileDecl_2* l_map);

  t_std_collections_Map_1sTt_mx2_FileDecl_2_KeyIterator m_All();

  t_std_collections_Map_1sTt_mx2_FileDecl_2_MapKeys(){
  }

  t_std_collections_Map_1sTt_mx2_FileDecl_2_MapKeys(bbNullCtor_t){
  }
};

int bbCompare(const t_std_collections_Map_1sTt_mx2_FileDecl_2_MapKeys&x,const t_std_collections_Map_1sTt_mx2_FileDecl_2_MapKeys&y);

void bbGCMark(const t_std_collections_Map_1sTt_mx2_FileDecl_2_MapKeys&);

struct t_std_collections_Map_1sTt_mx2_FileDecl_2_ValueIterator{
  const char *typeName()const{return "t_std_collections_Map_1sTt_mx2_FileDecl_2_ValueIterator";}

  bbGCVar<t_std_collections_Map_1sTt_mx2_FileDecl_2_Node> m__0node{};

  t_std_collections_Map_1sTt_mx2_FileDecl_2_ValueIterator(t_std_collections_Map_1sTt_mx2_FileDecl_2_Node* l_node);

  bbBool m_Valid();
  t_mx2_FileDecl* m_Current();
  void m_Bump();

  t_std_collections_Map_1sTt_mx2_FileDecl_2_ValueIterator(){
  }

  t_std_collections_Map_1sTt_mx2_FileDecl_2_ValueIterator(bbNullCtor_t){
  }
};

int bbCompare(const t_std_collections_Map_1sTt_mx2_FileDecl_2_ValueIterator&x,const t_std_collections_Map_1sTt_mx2_FileDecl_2_ValueIterator&y);

void bbGCMark(const t_std_collections_Map_1sTt_mx2_FileDecl_2_ValueIterator&);

struct t_std_collections_Map_1sTt_mx2_FileDecl_2_MapValues{
  const char *typeName()const{return "t_std_collections_Map_1sTt_mx2_FileDecl_2_MapValues";}

  bbGCVar<t_std_collections_Map_1sTt_mx2_FileDecl_2> m__0map{};

  t_std_collections_Map_1sTt_mx2_FileDecl_2_MapValues(t_std_collections_Map_1sTt_mx2_FileDecl_2* l_map);

  t_std_collections_Map_1sTt_mx2_FileDecl_2_ValueIterator m_All();

  t_std_collections_Map_1sTt_mx2_FileDecl_2_MapValues(){
  }

  t_std_collections_Map_1sTt_mx2_FileDecl_2_MapValues(bbNullCtor_t){
  }
};

int bbCompare(const t_std_collections_Map_1sTt_mx2_FileDecl_2_MapValues&x,const t_std_collections_Map_1sTt_mx2_FileDecl_2_MapValues&y);

void bbGCMark(const t_std_collections_Map_1sTt_mx2_FileDecl_2_MapValues&);

struct t_std_collections_Map_1sTt_mx2_FileDecl_2 : public bbObject{

  const char *typeName()const{return "t_std_collections_Map_1sTt_mx2_FileDecl_2";}

  bbGCVar<t_std_collections_Map_1sTt_mx2_FileDecl_2_Node> m__0root{};

  void gcMark();

  t_std_collections_Map_1sTt_mx2_FileDecl_2(t_std_collections_Map_1sTt_mx2_FileDecl_2_Node* l_root);
  t_std_collections_Map_1sTt_mx2_FileDecl_2();

  void m__idxeq(bbString l_key,t_mx2_FileDecl* l_value);
  t_mx2_FileDecl* m__idx(bbString l_key);
  t_std_collections_Map_1sTt_mx2_FileDecl_2_MapValues m_Values();
  bbBool m_Update(bbString l_key,t_mx2_FileDecl* l_value);
  bbBool m_Set(bbString l_key,t_mx2_FileDecl* l_value);
  void m_RotateRight(t_std_collections_Map_1sTt_mx2_FileDecl_2_Node* l_node);
  void m_RotateLeft(t_std_collections_Map_1sTt_mx2_FileDecl_2_Node* l_node);
  void m_RemoveNode(t_std_collections_Map_1sTt_mx2_FileDecl_2_Node* l_node);
  bbBool m_Remove(bbString l_key);
  t_std_collections_Map_1sTt_mx2_FileDecl_2_Node* m_LastNode();
  t_std_collections_Map_1sTt_mx2_FileDecl_2_MapKeys m_Keys();
  void m_InsertFixup(t_std_collections_Map_1sTt_mx2_FileDecl_2_Node* l_node);
  t_mx2_FileDecl* m_Get(bbString l_key);
  t_std_collections_Map_1sTt_mx2_FileDecl_2_Node* m_FirstNode();
  t_std_collections_Map_1sTt_mx2_FileDecl_2_Node* m_FindNode(bbString l_key);
  bbBool m_Empty();
  void m_DeleteFixup(t_std_collections_Map_1sTt_mx2_FileDecl_2_Node* l_node,t_std_collections_Map_1sTt_mx2_FileDecl_2_Node* l_parent);
  bbInt m_Count();
  t_std_collections_Map_1sTt_mx2_FileDecl_2* m_Copy();
  bbBool m_Contains(bbString l_key);
  void m_Clear();
  t_std_collections_Map_1sTt_mx2_FileDecl_2_Iterator m_All();
  bbBool m_Add(bbString l_key,t_mx2_FileDecl* l_value);
};

struct t_std_collections_Map_1Tt_mx2_SNode_2z_Node : public bbObject{

  const char *typeName()const{return "t_std_collections_Map_1Tt_mx2_SNode_2z_Node";}

  bbGCVar<t_mx2_SNode> m__0key{};
  bbBool m__0value{};
  bbInt m__0color{};
  bbGCVar<t_std_collections_Map_1Tt_mx2_SNode_2z_Node> m__0left{};
  bbGCVar<t_std_collections_Map_1Tt_mx2_SNode_2z_Node> m__0right{};
  bbGCVar<t_std_collections_Map_1Tt_mx2_SNode_2z_Node> m__0parent{};

  void gcMark();

  t_std_collections_Map_1Tt_mx2_SNode_2z_Node(t_mx2_SNode* l_key,bbBool l_value,bbInt l_color,t_std_collections_Map_1Tt_mx2_SNode_2z_Node* l_parent);

  bbBool m_Value();
  t_std_collections_Map_1Tt_mx2_SNode_2z_Node* m_PrevNode();
  t_std_collections_Map_1Tt_mx2_SNode_2z_Node* m_NextNode();
  t_mx2_SNode* m_Key();
  bbInt m_Count(bbInt l_n);
  t_std_collections_Map_1Tt_mx2_SNode_2z_Node* m_Copy(t_std_collections_Map_1Tt_mx2_SNode_2z_Node* l_parent);

  t_std_collections_Map_1Tt_mx2_SNode_2z_Node(){
  }
};

struct t_std_collections_Map_1Tt_mx2_SNode_2z_Iterator{
  const char *typeName()const{return "t_std_collections_Map_1Tt_mx2_SNode_2z_Iterator";}

  bbGCVar<t_std_collections_Map_1Tt_mx2_SNode_2z_Node> m__0node{};

  t_std_collections_Map_1Tt_mx2_SNode_2z_Iterator(t_std_collections_Map_1Tt_mx2_SNode_2z_Node* l_node);

  bbBool m_Valid();
  t_std_collections_Map_1Tt_mx2_SNode_2z_Node* m_Current();
  void m_Bump();

  t_std_collections_Map_1Tt_mx2_SNode_2z_Iterator(){
  }

  t_std_collections_Map_1Tt_mx2_SNode_2z_Iterator(bbNullCtor_t){
  }
};

int bbCompare(const t_std_collections_Map_1Tt_mx2_SNode_2z_Iterator&x,const t_std_collections_Map_1Tt_mx2_SNode_2z_Iterator&y);

void bbGCMark(const t_std_collections_Map_1Tt_mx2_SNode_2z_Iterator&);

struct t_std_collections_Map_1Tt_mx2_SNode_2z_KeyIterator{
  const char *typeName()const{return "t_std_collections_Map_1Tt_mx2_SNode_2z_KeyIterator";}

  bbGCVar<t_std_collections_Map_1Tt_mx2_SNode_2z_Node> m__0node{};

  t_std_collections_Map_1Tt_mx2_SNode_2z_KeyIterator(t_std_collections_Map_1Tt_mx2_SNode_2z_Node* l_node);

  bbBool m_Valid();
  t_mx2_SNode* m_Current();
  void m_Bump();

  t_std_collections_Map_1Tt_mx2_SNode_2z_KeyIterator(){
  }

  t_std_collections_Map_1Tt_mx2_SNode_2z_KeyIterator(bbNullCtor_t){
  }
};

int bbCompare(const t_std_collections_Map_1Tt_mx2_SNode_2z_KeyIterator&x,const t_std_collections_Map_1Tt_mx2_SNode_2z_KeyIterator&y);

void bbGCMark(const t_std_collections_Map_1Tt_mx2_SNode_2z_KeyIterator&);

struct t_std_collections_Map_1Tt_mx2_SNode_2z_MapKeys{
  const char *typeName()const{return "t_std_collections_Map_1Tt_mx2_SNode_2z_MapKeys";}

  bbGCVar<t_std_collections_Map_1Tt_mx2_SNode_2z> m__0map{};

  t_std_collections_Map_1Tt_mx2_SNode_2z_MapKeys(t_std_collections_Map_1Tt_mx2_SNode_2z* l_map);

  t_std_collections_Map_1Tt_mx2_SNode_2z_KeyIterator m_All();

  t_std_collections_Map_1Tt_mx2_SNode_2z_MapKeys(){
  }

  t_std_collections_Map_1Tt_mx2_SNode_2z_MapKeys(bbNullCtor_t){
  }
};

int bbCompare(const t_std_collections_Map_1Tt_mx2_SNode_2z_MapKeys&x,const t_std_collections_Map_1Tt_mx2_SNode_2z_MapKeys&y);

void bbGCMark(const t_std_collections_Map_1Tt_mx2_SNode_2z_MapKeys&);

struct t_std_collections_Map_1Tt_mx2_SNode_2z_ValueIterator{
  const char *typeName()const{return "t_std_collections_Map_1Tt_mx2_SNode_2z_ValueIterator";}

  bbGCVar<t_std_collections_Map_1Tt_mx2_SNode_2z_Node> m__0node{};

  t_std_collections_Map_1Tt_mx2_SNode_2z_ValueIterator(t_std_collections_Map_1Tt_mx2_SNode_2z_Node* l_node);

  bbBool m_Valid();
  bbBool m_Current();
  void m_Bump();

  t_std_collections_Map_1Tt_mx2_SNode_2z_ValueIterator(){
  }

  t_std_collections_Map_1Tt_mx2_SNode_2z_ValueIterator(bbNullCtor_t){
  }
};

int bbCompare(const t_std_collections_Map_1Tt_mx2_SNode_2z_ValueIterator&x,const t_std_collections_Map_1Tt_mx2_SNode_2z_ValueIterator&y);

void bbGCMark(const t_std_collections_Map_1Tt_mx2_SNode_2z_ValueIterator&);

struct t_std_collections_Map_1Tt_mx2_SNode_2z_MapValues{
  const char *typeName()const{return "t_std_collections_Map_1Tt_mx2_SNode_2z_MapValues";}

  bbGCVar<t_std_collections_Map_1Tt_mx2_SNode_2z> m__0map{};

  t_std_collections_Map_1Tt_mx2_SNode_2z_MapValues(t_std_collections_Map_1Tt_mx2_SNode_2z* l_map);

  t_std_collections_Map_1Tt_mx2_SNode_2z_ValueIterator m_All();

  t_std_collections_Map_1Tt_mx2_SNode_2z_MapValues(){
  }

  t_std_collections_Map_1Tt_mx2_SNode_2z_MapValues(bbNullCtor_t){
  }
};

int bbCompare(const t_std_collections_Map_1Tt_mx2_SNode_2z_MapValues&x,const t_std_collections_Map_1Tt_mx2_SNode_2z_MapValues&y);

void bbGCMark(const t_std_collections_Map_1Tt_mx2_SNode_2z_MapValues&);

struct t_std_collections_Map_1Tt_mx2_SNode_2z : public bbObject{

  const char *typeName()const{return "t_std_collections_Map_1Tt_mx2_SNode_2z";}

  bbGCVar<t_std_collections_Map_1Tt_mx2_SNode_2z_Node> m__0root{};

  void gcMark();

  t_std_collections_Map_1Tt_mx2_SNode_2z(t_std_collections_Map_1Tt_mx2_SNode_2z_Node* l_root);
  t_std_collections_Map_1Tt_mx2_SNode_2z();

  void m__idxeq(t_mx2_SNode* l_key,bbBool l_value);
  bbBool m__idx(t_mx2_SNode* l_key);
  t_std_collections_Map_1Tt_mx2_SNode_2z_MapValues m_Values();
  bbBool m_Update(t_mx2_SNode* l_key,bbBool l_value);
  bbBool m_Set(t_mx2_SNode* l_key,bbBool l_value);
  void m_RotateRight(t_std_collections_Map_1Tt_mx2_SNode_2z_Node* l_node);
  void m_RotateLeft(t_std_collections_Map_1Tt_mx2_SNode_2z_Node* l_node);
  void m_RemoveNode(t_std_collections_Map_1Tt_mx2_SNode_2z_Node* l_node);
  bbBool m_Remove(t_mx2_SNode* l_key);
  t_std_collections_Map_1Tt_mx2_SNode_2z_Node* m_LastNode();
  t_std_collections_Map_1Tt_mx2_SNode_2z_MapKeys m_Keys();
  void m_InsertFixup(t_std_collections_Map_1Tt_mx2_SNode_2z_Node* l_node);
  bbBool m_Get(t_mx2_SNode* l_key);
  t_std_collections_Map_1Tt_mx2_SNode_2z_Node* m_FirstNode();
  t_std_collections_Map_1Tt_mx2_SNode_2z_Node* m_FindNode(t_mx2_SNode* l_key);
  bbBool m_Empty();
  void m_DeleteFixup(t_std_collections_Map_1Tt_mx2_SNode_2z_Node* l_node,t_std_collections_Map_1Tt_mx2_SNode_2z_Node* l_parent);
  bbInt m_Count();
  t_std_collections_Map_1Tt_mx2_SNode_2z* m_Copy();
  bbBool m_Contains(t_mx2_SNode* l_key);
  void m_Clear();
  t_std_collections_Map_1Tt_mx2_SNode_2z_Iterator m_All();
  bbBool m_Add(t_mx2_SNode* l_key,bbBool l_value);
};

struct t_std_collections_Map_1sTt_mx2_ClassType_2_Node : public bbObject{

  const char *typeName()const{return "t_std_collections_Map_1sTt_mx2_ClassType_2_Node";}

  bbString m__0key{};
  bbGCVar<t_mx2_ClassType> m__0value{};
  bbInt m__0color{};
  bbGCVar<t_std_collections_Map_1sTt_mx2_ClassType_2_Node> m__0left{};
  bbGCVar<t_std_collections_Map_1sTt_mx2_ClassType_2_Node> m__0right{};
  bbGCVar<t_std_collections_Map_1sTt_mx2_ClassType_2_Node> m__0parent{};

  void gcMark();

  t_std_collections_Map_1sTt_mx2_ClassType_2_Node(bbString l_key,t_mx2_ClassType* l_value,bbInt l_color,t_std_collections_Map_1sTt_mx2_ClassType_2_Node* l_parent);

  t_mx2_ClassType* m_Value();
  t_std_collections_Map_1sTt_mx2_ClassType_2_Node* m_PrevNode();
  t_std_collections_Map_1sTt_mx2_ClassType_2_Node* m_NextNode();
  bbString m_Key();
  bbInt m_Count(bbInt l_n);
  t_std_collections_Map_1sTt_mx2_ClassType_2_Node* m_Copy(t_std_collections_Map_1sTt_mx2_ClassType_2_Node* l_parent);

  t_std_collections_Map_1sTt_mx2_ClassType_2_Node(){
  }
};

struct t_std_collections_Map_1sTt_mx2_ClassType_2_Iterator{
  const char *typeName()const{return "t_std_collections_Map_1sTt_mx2_ClassType_2_Iterator";}

  bbGCVar<t_std_collections_Map_1sTt_mx2_ClassType_2_Node> m__0node{};

  t_std_collections_Map_1sTt_mx2_ClassType_2_Iterator(t_std_collections_Map_1sTt_mx2_ClassType_2_Node* l_node);

  bbBool m_Valid();
  t_std_collections_Map_1sTt_mx2_ClassType_2_Node* m_Current();
  void m_Bump();

  t_std_collections_Map_1sTt_mx2_ClassType_2_Iterator(){
  }

  t_std_collections_Map_1sTt_mx2_ClassType_2_Iterator(bbNullCtor_t){
  }
};

int bbCompare(const t_std_collections_Map_1sTt_mx2_ClassType_2_Iterator&x,const t_std_collections_Map_1sTt_mx2_ClassType_2_Iterator&y);

void bbGCMark(const t_std_collections_Map_1sTt_mx2_ClassType_2_Iterator&);

struct t_std_collections_Map_1sTt_mx2_ClassType_2_KeyIterator{
  const char *typeName()const{return "t_std_collections_Map_1sTt_mx2_ClassType_2_KeyIterator";}

  bbGCVar<t_std_collections_Map_1sTt_mx2_ClassType_2_Node> m__0node{};

  t_std_collections_Map_1sTt_mx2_ClassType_2_KeyIterator(t_std_collections_Map_1sTt_mx2_ClassType_2_Node* l_node);

  bbBool m_Valid();
  bbString m_Current();
  void m_Bump();

  t_std_collections_Map_1sTt_mx2_ClassType_2_KeyIterator(){
  }

  t_std_collections_Map_1sTt_mx2_ClassType_2_KeyIterator(bbNullCtor_t){
  }
};

int bbCompare(const t_std_collections_Map_1sTt_mx2_ClassType_2_KeyIterator&x,const t_std_collections_Map_1sTt_mx2_ClassType_2_KeyIterator&y);

void bbGCMark(const t_std_collections_Map_1sTt_mx2_ClassType_2_KeyIterator&);

struct t_std_collections_Map_1sTt_mx2_ClassType_2_MapKeys{
  const char *typeName()const{return "t_std_collections_Map_1sTt_mx2_ClassType_2_MapKeys";}

  bbGCVar<t_std_collections_Map_1sTt_mx2_ClassType_2> m__0map{};

  t_std_collections_Map_1sTt_mx2_ClassType_2_MapKeys(t_std_collections_Map_1sTt_mx2_ClassType_2* l_map);

  t_std_collections_Map_1sTt_mx2_ClassType_2_KeyIterator m_All();

  t_std_collections_Map_1sTt_mx2_ClassType_2_MapKeys(){
  }

  t_std_collections_Map_1sTt_mx2_ClassType_2_MapKeys(bbNullCtor_t){
  }
};

int bbCompare(const t_std_collections_Map_1sTt_mx2_ClassType_2_MapKeys&x,const t_std_collections_Map_1sTt_mx2_ClassType_2_MapKeys&y);

void bbGCMark(const t_std_collections_Map_1sTt_mx2_ClassType_2_MapKeys&);

struct t_std_collections_Map_1sTt_mx2_ClassType_2_ValueIterator{
  const char *typeName()const{return "t_std_collections_Map_1sTt_mx2_ClassType_2_ValueIterator";}

  bbGCVar<t_std_collections_Map_1sTt_mx2_ClassType_2_Node> m__0node{};

  t_std_collections_Map_1sTt_mx2_ClassType_2_ValueIterator(t_std_collections_Map_1sTt_mx2_ClassType_2_Node* l_node);

  bbBool m_Valid();
  t_mx2_ClassType* m_Current();
  void m_Bump();

  t_std_collections_Map_1sTt_mx2_ClassType_2_ValueIterator(){
  }

  t_std_collections_Map_1sTt_mx2_ClassType_2_ValueIterator(bbNullCtor_t){
  }
};

int bbCompare(const t_std_collections_Map_1sTt_mx2_ClassType_2_ValueIterator&x,const t_std_collections_Map_1sTt_mx2_ClassType_2_ValueIterator&y);

void bbGCMark(const t_std_collections_Map_1sTt_mx2_ClassType_2_ValueIterator&);

struct t_std_collections_Map_1sTt_mx2_ClassType_2_MapValues{
  const char *typeName()const{return "t_std_collections_Map_1sTt_mx2_ClassType_2_MapValues";}

  bbGCVar<t_std_collections_Map_1sTt_mx2_ClassType_2> m__0map{};

  t_std_collections_Map_1sTt_mx2_ClassType_2_MapValues(t_std_collections_Map_1sTt_mx2_ClassType_2* l_map);

  t_std_collections_Map_1sTt_mx2_ClassType_2_ValueIterator m_All();

  t_std_collections_Map_1sTt_mx2_ClassType_2_MapValues(){
  }

  t_std_collections_Map_1sTt_mx2_ClassType_2_MapValues(bbNullCtor_t){
  }
};

int bbCompare(const t_std_collections_Map_1sTt_mx2_ClassType_2_MapValues&x,const t_std_collections_Map_1sTt_mx2_ClassType_2_MapValues&y);

void bbGCMark(const t_std_collections_Map_1sTt_mx2_ClassType_2_MapValues&);

struct t_std_collections_Map_1sTt_mx2_ClassType_2 : public bbObject{

  const char *typeName()const{return "t_std_collections_Map_1sTt_mx2_ClassType_2";}

  bbGCVar<t_std_collections_Map_1sTt_mx2_ClassType_2_Node> m__0root{};

  void gcMark();

  t_std_collections_Map_1sTt_mx2_ClassType_2(t_std_collections_Map_1sTt_mx2_ClassType_2_Node* l_root);
  t_std_collections_Map_1sTt_mx2_ClassType_2();

  void m__idxeq(bbString l_key,t_mx2_ClassType* l_value);
  t_mx2_ClassType* m__idx(bbString l_key);
  t_std_collections_Map_1sTt_mx2_ClassType_2_MapValues m_Values();
  bbBool m_Update(bbString l_key,t_mx2_ClassType* l_value);
  bbBool m_Set(bbString l_key,t_mx2_ClassType* l_value);
  void m_RotateRight(t_std_collections_Map_1sTt_mx2_ClassType_2_Node* l_node);
  void m_RotateLeft(t_std_collections_Map_1sTt_mx2_ClassType_2_Node* l_node);
  void m_RemoveNode(t_std_collections_Map_1sTt_mx2_ClassType_2_Node* l_node);
  bbBool m_Remove(bbString l_key);
  t_std_collections_Map_1sTt_mx2_ClassType_2_Node* m_LastNode();
  t_std_collections_Map_1sTt_mx2_ClassType_2_MapKeys m_Keys();
  void m_InsertFixup(t_std_collections_Map_1sTt_mx2_ClassType_2_Node* l_node);
  t_mx2_ClassType* m_Get(bbString l_key);
  t_std_collections_Map_1sTt_mx2_ClassType_2_Node* m_FirstNode();
  t_std_collections_Map_1sTt_mx2_ClassType_2_Node* m_FindNode(bbString l_key);
  bbBool m_Empty();
  void m_DeleteFixup(t_std_collections_Map_1sTt_mx2_ClassType_2_Node* l_node,t_std_collections_Map_1sTt_mx2_ClassType_2_Node* l_parent);
  bbInt m_Count();
  t_std_collections_Map_1sTt_mx2_ClassType_2* m_Copy();
  bbBool m_Contains(bbString l_key);
  void m_Clear();
  t_std_collections_Map_1sTt_mx2_ClassType_2_Iterator m_All();
  bbBool m_Add(bbString l_key,t_mx2_ClassType* l_value);
};

struct t_std_collections_Map_1sTt_mx2_VarValue_2_Node : public bbObject{

  const char *typeName()const{return "t_std_collections_Map_1sTt_mx2_VarValue_2_Node";}

  bbString m__0key{};
  bbGCVar<t_mx2_VarValue> m__0value{};
  bbInt m__0color{};
  bbGCVar<t_std_collections_Map_1sTt_mx2_VarValue_2_Node> m__0left{};
  bbGCVar<t_std_collections_Map_1sTt_mx2_VarValue_2_Node> m__0right{};
  bbGCVar<t_std_collections_Map_1sTt_mx2_VarValue_2_Node> m__0parent{};

  void gcMark();

  t_std_collections_Map_1sTt_mx2_VarValue_2_Node(bbString l_key,t_mx2_VarValue* l_value,bbInt l_color,t_std_collections_Map_1sTt_mx2_VarValue_2_Node* l_parent);

  t_mx2_VarValue* m_Value();
  t_std_collections_Map_1sTt_mx2_VarValue_2_Node* m_PrevNode();
  t_std_collections_Map_1sTt_mx2_VarValue_2_Node* m_NextNode();
  bbString m_Key();
  bbInt m_Count(bbInt l_n);
  t_std_collections_Map_1sTt_mx2_VarValue_2_Node* m_Copy(t_std_collections_Map_1sTt_mx2_VarValue_2_Node* l_parent);

  t_std_collections_Map_1sTt_mx2_VarValue_2_Node(){
  }
};

struct t_std_collections_Map_1sTt_mx2_VarValue_2_Iterator{
  const char *typeName()const{return "t_std_collections_Map_1sTt_mx2_VarValue_2_Iterator";}

  bbGCVar<t_std_collections_Map_1sTt_mx2_VarValue_2_Node> m__0node{};

  t_std_collections_Map_1sTt_mx2_VarValue_2_Iterator(t_std_collections_Map_1sTt_mx2_VarValue_2_Node* l_node);

  bbBool m_Valid();
  t_std_collections_Map_1sTt_mx2_VarValue_2_Node* m_Current();
  void m_Bump();

  t_std_collections_Map_1sTt_mx2_VarValue_2_Iterator(){
  }

  t_std_collections_Map_1sTt_mx2_VarValue_2_Iterator(bbNullCtor_t){
  }
};

int bbCompare(const t_std_collections_Map_1sTt_mx2_VarValue_2_Iterator&x,const t_std_collections_Map_1sTt_mx2_VarValue_2_Iterator&y);

void bbGCMark(const t_std_collections_Map_1sTt_mx2_VarValue_2_Iterator&);

struct t_std_collections_Map_1sTt_mx2_VarValue_2_KeyIterator{
  const char *typeName()const{return "t_std_collections_Map_1sTt_mx2_VarValue_2_KeyIterator";}

  bbGCVar<t_std_collections_Map_1sTt_mx2_VarValue_2_Node> m__0node{};

  t_std_collections_Map_1sTt_mx2_VarValue_2_KeyIterator(t_std_collections_Map_1sTt_mx2_VarValue_2_Node* l_node);

  bbBool m_Valid();
  bbString m_Current();
  void m_Bump();

  t_std_collections_Map_1sTt_mx2_VarValue_2_KeyIterator(){
  }

  t_std_collections_Map_1sTt_mx2_VarValue_2_KeyIterator(bbNullCtor_t){
  }
};

int bbCompare(const t_std_collections_Map_1sTt_mx2_VarValue_2_KeyIterator&x,const t_std_collections_Map_1sTt_mx2_VarValue_2_KeyIterator&y);

void bbGCMark(const t_std_collections_Map_1sTt_mx2_VarValue_2_KeyIterator&);

struct t_std_collections_Map_1sTt_mx2_VarValue_2_MapKeys{
  const char *typeName()const{return "t_std_collections_Map_1sTt_mx2_VarValue_2_MapKeys";}

  bbGCVar<t_std_collections_Map_1sTt_mx2_VarValue_2> m__0map{};

  t_std_collections_Map_1sTt_mx2_VarValue_2_MapKeys(t_std_collections_Map_1sTt_mx2_VarValue_2* l_map);

  t_std_collections_Map_1sTt_mx2_VarValue_2_KeyIterator m_All();

  t_std_collections_Map_1sTt_mx2_VarValue_2_MapKeys(){
  }

  t_std_collections_Map_1sTt_mx2_VarValue_2_MapKeys(bbNullCtor_t){
  }
};

int bbCompare(const t_std_collections_Map_1sTt_mx2_VarValue_2_MapKeys&x,const t_std_collections_Map_1sTt_mx2_VarValue_2_MapKeys&y);

void bbGCMark(const t_std_collections_Map_1sTt_mx2_VarValue_2_MapKeys&);

struct t_std_collections_Map_1sTt_mx2_VarValue_2_ValueIterator{
  const char *typeName()const{return "t_std_collections_Map_1sTt_mx2_VarValue_2_ValueIterator";}

  bbGCVar<t_std_collections_Map_1sTt_mx2_VarValue_2_Node> m__0node{};

  t_std_collections_Map_1sTt_mx2_VarValue_2_ValueIterator(t_std_collections_Map_1sTt_mx2_VarValue_2_Node* l_node);

  bbBool m_Valid();
  t_mx2_VarValue* m_Current();
  void m_Bump();

  t_std_collections_Map_1sTt_mx2_VarValue_2_ValueIterator(){
  }

  t_std_collections_Map_1sTt_mx2_VarValue_2_ValueIterator(bbNullCtor_t){
  }
};

int bbCompare(const t_std_collections_Map_1sTt_mx2_VarValue_2_ValueIterator&x,const t_std_collections_Map_1sTt_mx2_VarValue_2_ValueIterator&y);

void bbGCMark(const t_std_collections_Map_1sTt_mx2_VarValue_2_ValueIterator&);

struct t_std_collections_Map_1sTt_mx2_VarValue_2_MapValues{
  const char *typeName()const{return "t_std_collections_Map_1sTt_mx2_VarValue_2_MapValues";}

  bbGCVar<t_std_collections_Map_1sTt_mx2_VarValue_2> m__0map{};

  t_std_collections_Map_1sTt_mx2_VarValue_2_MapValues(t_std_collections_Map_1sTt_mx2_VarValue_2* l_map);

  t_std_collections_Map_1sTt_mx2_VarValue_2_ValueIterator m_All();

  t_std_collections_Map_1sTt_mx2_VarValue_2_MapValues(){
  }

  t_std_collections_Map_1sTt_mx2_VarValue_2_MapValues(bbNullCtor_t){
  }
};

int bbCompare(const t_std_collections_Map_1sTt_mx2_VarValue_2_MapValues&x,const t_std_collections_Map_1sTt_mx2_VarValue_2_MapValues&y);

void bbGCMark(const t_std_collections_Map_1sTt_mx2_VarValue_2_MapValues&);

struct t_std_collections_Map_1sTt_mx2_VarValue_2 : public bbObject{

  const char *typeName()const{return "t_std_collections_Map_1sTt_mx2_VarValue_2";}

  bbGCVar<t_std_collections_Map_1sTt_mx2_VarValue_2_Node> m__0root{};

  void gcMark();

  t_std_collections_Map_1sTt_mx2_VarValue_2(t_std_collections_Map_1sTt_mx2_VarValue_2_Node* l_root);
  t_std_collections_Map_1sTt_mx2_VarValue_2();

  void m__idxeq(bbString l_key,t_mx2_VarValue* l_value);
  t_mx2_VarValue* m__idx(bbString l_key);
  t_std_collections_Map_1sTt_mx2_VarValue_2_MapValues m_Values();
  bbBool m_Update(bbString l_key,t_mx2_VarValue* l_value);
  bbBool m_Set(bbString l_key,t_mx2_VarValue* l_value);
  void m_RotateRight(t_std_collections_Map_1sTt_mx2_VarValue_2_Node* l_node);
  void m_RotateLeft(t_std_collections_Map_1sTt_mx2_VarValue_2_Node* l_node);
  void m_RemoveNode(t_std_collections_Map_1sTt_mx2_VarValue_2_Node* l_node);
  bbBool m_Remove(bbString l_key);
  t_std_collections_Map_1sTt_mx2_VarValue_2_Node* m_LastNode();
  t_std_collections_Map_1sTt_mx2_VarValue_2_MapKeys m_Keys();
  void m_InsertFixup(t_std_collections_Map_1sTt_mx2_VarValue_2_Node* l_node);
  t_mx2_VarValue* m_Get(bbString l_key);
  t_std_collections_Map_1sTt_mx2_VarValue_2_Node* m_FirstNode();
  t_std_collections_Map_1sTt_mx2_VarValue_2_Node* m_FindNode(bbString l_key);
  bbBool m_Empty();
  void m_DeleteFixup(t_std_collections_Map_1sTt_mx2_VarValue_2_Node* l_node,t_std_collections_Map_1sTt_mx2_VarValue_2_Node* l_parent);
  bbInt m_Count();
  t_std_collections_Map_1sTt_mx2_VarValue_2* m_Copy();
  bbBool m_Contains(bbString l_key);
  void m_Clear();
  t_std_collections_Map_1sTt_mx2_VarValue_2_Iterator m_All();
  bbBool m_Add(bbString l_key,t_mx2_VarValue* l_value);
};

struct t_std_collections_Map_1sTt_mx2_NamespaceScope_2_Node : public bbObject{

  const char *typeName()const{return "t_std_collections_Map_1sTt_mx2_NamespaceScope_2_Node";}

  bbString m__0key{};
  bbGCVar<t_mx2_NamespaceScope> m__0value{};
  bbInt m__0color{};
  bbGCVar<t_std_collections_Map_1sTt_mx2_NamespaceScope_2_Node> m__0left{};
  bbGCVar<t_std_collections_Map_1sTt_mx2_NamespaceScope_2_Node> m__0right{};
  bbGCVar<t_std_collections_Map_1sTt_mx2_NamespaceScope_2_Node> m__0parent{};

  void gcMark();

  t_std_collections_Map_1sTt_mx2_NamespaceScope_2_Node(bbString l_key,t_mx2_NamespaceScope* l_value,bbInt l_color,t_std_collections_Map_1sTt_mx2_NamespaceScope_2_Node* l_parent);

  t_mx2_NamespaceScope* m_Value();
  t_std_collections_Map_1sTt_mx2_NamespaceScope_2_Node* m_PrevNode();
  t_std_collections_Map_1sTt_mx2_NamespaceScope_2_Node* m_NextNode();
  bbString m_Key();
  bbInt m_Count(bbInt l_n);
  t_std_collections_Map_1sTt_mx2_NamespaceScope_2_Node* m_Copy(t_std_collections_Map_1sTt_mx2_NamespaceScope_2_Node* l_parent);

  t_std_collections_Map_1sTt_mx2_NamespaceScope_2_Node(){
  }
};

struct t_std_collections_Map_1sTt_mx2_NamespaceScope_2_Iterator{
  const char *typeName()const{return "t_std_collections_Map_1sTt_mx2_NamespaceScope_2_Iterator";}

  bbGCVar<t_std_collections_Map_1sTt_mx2_NamespaceScope_2_Node> m__0node{};

  t_std_collections_Map_1sTt_mx2_NamespaceScope_2_Iterator(t_std_collections_Map_1sTt_mx2_NamespaceScope_2_Node* l_node);

  bbBool m_Valid();
  t_std_collections_Map_1sTt_mx2_NamespaceScope_2_Node* m_Current();
  void m_Bump();

  t_std_collections_Map_1sTt_mx2_NamespaceScope_2_Iterator(){
  }

  t_std_collections_Map_1sTt_mx2_NamespaceScope_2_Iterator(bbNullCtor_t){
  }
};

int bbCompare(const t_std_collections_Map_1sTt_mx2_NamespaceScope_2_Iterator&x,const t_std_collections_Map_1sTt_mx2_NamespaceScope_2_Iterator&y);

void bbGCMark(const t_std_collections_Map_1sTt_mx2_NamespaceScope_2_Iterator&);

struct t_std_collections_Map_1sTt_mx2_NamespaceScope_2_KeyIterator{
  const char *typeName()const{return "t_std_collections_Map_1sTt_mx2_NamespaceScope_2_KeyIterator";}

  bbGCVar<t_std_collections_Map_1sTt_mx2_NamespaceScope_2_Node> m__0node{};

  t_std_collections_Map_1sTt_mx2_NamespaceScope_2_KeyIterator(t_std_collections_Map_1sTt_mx2_NamespaceScope_2_Node* l_node);

  bbBool m_Valid();
  bbString m_Current();
  void m_Bump();

  t_std_collections_Map_1sTt_mx2_NamespaceScope_2_KeyIterator(){
  }

  t_std_collections_Map_1sTt_mx2_NamespaceScope_2_KeyIterator(bbNullCtor_t){
  }
};

int bbCompare(const t_std_collections_Map_1sTt_mx2_NamespaceScope_2_KeyIterator&x,const t_std_collections_Map_1sTt_mx2_NamespaceScope_2_KeyIterator&y);

void bbGCMark(const t_std_collections_Map_1sTt_mx2_NamespaceScope_2_KeyIterator&);

struct t_std_collections_Map_1sTt_mx2_NamespaceScope_2_MapKeys{
  const char *typeName()const{return "t_std_collections_Map_1sTt_mx2_NamespaceScope_2_MapKeys";}

  bbGCVar<t_std_collections_Map_1sTt_mx2_NamespaceScope_2> m__0map{};

  t_std_collections_Map_1sTt_mx2_NamespaceScope_2_MapKeys(t_std_collections_Map_1sTt_mx2_NamespaceScope_2* l_map);

  t_std_collections_Map_1sTt_mx2_NamespaceScope_2_KeyIterator m_All();

  t_std_collections_Map_1sTt_mx2_NamespaceScope_2_MapKeys(){
  }

  t_std_collections_Map_1sTt_mx2_NamespaceScope_2_MapKeys(bbNullCtor_t){
  }
};

int bbCompare(const t_std_collections_Map_1sTt_mx2_NamespaceScope_2_MapKeys&x,const t_std_collections_Map_1sTt_mx2_NamespaceScope_2_MapKeys&y);

void bbGCMark(const t_std_collections_Map_1sTt_mx2_NamespaceScope_2_MapKeys&);

struct t_std_collections_Map_1sTt_mx2_NamespaceScope_2_ValueIterator{
  const char *typeName()const{return "t_std_collections_Map_1sTt_mx2_NamespaceScope_2_ValueIterator";}

  bbGCVar<t_std_collections_Map_1sTt_mx2_NamespaceScope_2_Node> m__0node{};

  t_std_collections_Map_1sTt_mx2_NamespaceScope_2_ValueIterator(t_std_collections_Map_1sTt_mx2_NamespaceScope_2_Node* l_node);

  bbBool m_Valid();
  t_mx2_NamespaceScope* m_Current();
  void m_Bump();

  t_std_collections_Map_1sTt_mx2_NamespaceScope_2_ValueIterator(){
  }

  t_std_collections_Map_1sTt_mx2_NamespaceScope_2_ValueIterator(bbNullCtor_t){
  }
};

int bbCompare(const t_std_collections_Map_1sTt_mx2_NamespaceScope_2_ValueIterator&x,const t_std_collections_Map_1sTt_mx2_NamespaceScope_2_ValueIterator&y);

void bbGCMark(const t_std_collections_Map_1sTt_mx2_NamespaceScope_2_ValueIterator&);

struct t_std_collections_Map_1sTt_mx2_NamespaceScope_2_MapValues{
  const char *typeName()const{return "t_std_collections_Map_1sTt_mx2_NamespaceScope_2_MapValues";}

  bbGCVar<t_std_collections_Map_1sTt_mx2_NamespaceScope_2> m__0map{};

  t_std_collections_Map_1sTt_mx2_NamespaceScope_2_MapValues(t_std_collections_Map_1sTt_mx2_NamespaceScope_2* l_map);

  t_std_collections_Map_1sTt_mx2_NamespaceScope_2_ValueIterator m_All();

  t_std_collections_Map_1sTt_mx2_NamespaceScope_2_MapValues(){
  }

  t_std_collections_Map_1sTt_mx2_NamespaceScope_2_MapValues(bbNullCtor_t){
  }
};

int bbCompare(const t_std_collections_Map_1sTt_mx2_NamespaceScope_2_MapValues&x,const t_std_collections_Map_1sTt_mx2_NamespaceScope_2_MapValues&y);

void bbGCMark(const t_std_collections_Map_1sTt_mx2_NamespaceScope_2_MapValues&);

struct t_std_collections_Map_1sTt_mx2_NamespaceScope_2 : public bbObject{

  const char *typeName()const{return "t_std_collections_Map_1sTt_mx2_NamespaceScope_2";}

  bbGCVar<t_std_collections_Map_1sTt_mx2_NamespaceScope_2_Node> m__0root{};

  void gcMark();

  t_std_collections_Map_1sTt_mx2_NamespaceScope_2(t_std_collections_Map_1sTt_mx2_NamespaceScope_2_Node* l_root);
  t_std_collections_Map_1sTt_mx2_NamespaceScope_2();

  void m__idxeq(bbString l_key,t_mx2_NamespaceScope* l_value);
  t_mx2_NamespaceScope* m__idx(bbString l_key);
  t_std_collections_Map_1sTt_mx2_NamespaceScope_2_MapValues m_Values();
  bbBool m_Update(bbString l_key,t_mx2_NamespaceScope* l_value);
  bbBool m_Set(bbString l_key,t_mx2_NamespaceScope* l_value);
  void m_RotateRight(t_std_collections_Map_1sTt_mx2_NamespaceScope_2_Node* l_node);
  void m_RotateLeft(t_std_collections_Map_1sTt_mx2_NamespaceScope_2_Node* l_node);
  void m_RemoveNode(t_std_collections_Map_1sTt_mx2_NamespaceScope_2_Node* l_node);
  bbBool m_Remove(bbString l_key);
  t_std_collections_Map_1sTt_mx2_NamespaceScope_2_Node* m_LastNode();
  t_std_collections_Map_1sTt_mx2_NamespaceScope_2_MapKeys m_Keys();
  void m_InsertFixup(t_std_collections_Map_1sTt_mx2_NamespaceScope_2_Node* l_node);
  t_mx2_NamespaceScope* m_Get(bbString l_key);
  t_std_collections_Map_1sTt_mx2_NamespaceScope_2_Node* m_FirstNode();
  t_std_collections_Map_1sTt_mx2_NamespaceScope_2_Node* m_FindNode(bbString l_key);
  bbBool m_Empty();
  void m_DeleteFixup(t_std_collections_Map_1sTt_mx2_NamespaceScope_2_Node* l_node,t_std_collections_Map_1sTt_mx2_NamespaceScope_2_Node* l_parent);
  bbInt m_Count();
  t_std_collections_Map_1sTt_mx2_NamespaceScope_2* m_Copy();
  bbBool m_Contains(bbString l_key);
  void m_Clear();
  t_std_collections_Map_1sTt_mx2_NamespaceScope_2_Iterator m_All();
  bbBool m_Add(bbString l_key,t_mx2_NamespaceScope* l_value);
};

#endif
