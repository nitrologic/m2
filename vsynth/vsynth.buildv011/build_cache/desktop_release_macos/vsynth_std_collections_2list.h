
#ifndef MX2_VSYNTH_STD_COLLECTIONS_2LIST_H
#define MX2_VSYNTH_STD_COLLECTIONS_2LIST_H

#include <bbmonkey.h>
#include "../../../../../../monkey2/modules/std/std.buildv011/desktop_release_macos/std_collections_2list.h"

// ***** External *****

#include "../../../../../../monkey2/modules/monkey/monkey.buildv011/desktop_release_macos/monkey_types.h"
#include "vsynth_std_collections_2container.h"

struct t_std_collections_Stack_1Tt_default_Voice_2;
struct t_default_Voice;

// ***** Internal *****

struct t_std_collections_List_1Tt_default_Voice_2_Node;
struct t_std_collections_List_1Tt_default_Voice_2_Iterator;
struct t_std_collections_List_1Tt_default_Voice_2_BackwardsIterator;
struct t_std_collections_List_1Tt_default_Voice_2;

extern void g_std_collections_List_1Tt_default_Voice_2_AddAll_1Tt_std_collections_List_1Tt_default_Voice_2_2(t_std_collections_List_1Tt_default_Voice_2* l_self,t_std_collections_List_1Tt_default_Voice_2* l_values);
extern void g_std_collections_List_1Tt_default_Voice_2_AddAll_1Tt_std_collections_Stack_1Tt_default_Voice_2_2(t_std_collections_List_1Tt_default_Voice_2* l_self,t_std_collections_Stack_1Tt_default_Voice_2* l_values);

struct t_std_collections_List_1Tt_default_Voice_2_Node : public bbObject{

  const char *typeName()const{return "t_std_collections_List_1Tt_default_Voice_2_Node";}

  bbGCVar<t_std_collections_List_1Tt_default_Voice_2_Node> m__0succ{};
  bbGCVar<t_std_collections_List_1Tt_default_Voice_2_Node> m__0pred{};
  bbGCVar<t_default_Voice> m__0value{};

  void gcMark();

  t_std_collections_List_1Tt_default_Voice_2_Node(t_default_Voice* l_value,t_std_collections_List_1Tt_default_Voice_2_Node* l_succ);
  t_std_collections_List_1Tt_default_Voice_2_Node(t_default_Voice* l_value);

  void m_Value(t_default_Voice* l_value);
  t_default_Voice* m_Value();
  t_std_collections_List_1Tt_default_Voice_2_Node* m_Succ();
  void m_Remove();
  t_std_collections_List_1Tt_default_Voice_2_Node* m_Pred();
  void m_InsertBefore(t_std_collections_List_1Tt_default_Voice_2_Node* l_node);
  void m_InsertAfter(t_std_collections_List_1Tt_default_Voice_2_Node* l_node);

  t_std_collections_List_1Tt_default_Voice_2_Node(){
  }
};

struct t_std_collections_List_1Tt_default_Voice_2_Iterator{
  const char *typeName()const{return "t_std_collections_List_1Tt_default_Voice_2_Iterator";}

  bbGCVar<t_std_collections_List_1Tt_default_Voice_2> m__0list{};
  bbGCVar<t_std_collections_List_1Tt_default_Voice_2_Node> m__0node{};
  bbInt m__0seq{};

  t_std_collections_List_1Tt_default_Voice_2_Iterator(t_std_collections_List_1Tt_default_Voice_2* l_list,t_std_collections_List_1Tt_default_Voice_2_Node* l_node);

  void m_Insert(t_default_Voice* l_value);
  void m_Erase();
  void m_Current(t_default_Voice* l_current);
  t_default_Voice* m_Current();
  void m_Bump();
  bbBool m_AtEnd();
  void m_AssertSeq();
  void m_AssertCurrent();

  t_std_collections_List_1Tt_default_Voice_2_Iterator(){
  }

  t_std_collections_List_1Tt_default_Voice_2_Iterator(bbNullCtor_t){
  }
};

int bbCompare(const t_std_collections_List_1Tt_default_Voice_2_Iterator&x,const t_std_collections_List_1Tt_default_Voice_2_Iterator&y);

void bbGCMark(const t_std_collections_List_1Tt_default_Voice_2_Iterator&);

struct t_std_collections_List_1Tt_default_Voice_2_BackwardsIterator{
  const char *typeName()const{return "t_std_collections_List_1Tt_default_Voice_2_BackwardsIterator";}

  bbGCVar<t_std_collections_List_1Tt_default_Voice_2> m__0list{};
  bbGCVar<t_std_collections_List_1Tt_default_Voice_2_Node> m__0node{};
  bbInt m__0seq{};

  t_std_collections_List_1Tt_default_Voice_2_BackwardsIterator(t_std_collections_List_1Tt_default_Voice_2* l_list,t_std_collections_List_1Tt_default_Voice_2_Node* l_node);

  void m_Insert(t_default_Voice* l_value);
  void m_Erase();
  void m_Current(t_default_Voice* l_current);
  t_default_Voice* m_Current();
  void m_Bump();
  bbBool m_AtEnd();
  void m_AssertSeq();
  void m_AssertCurrent();

  t_std_collections_List_1Tt_default_Voice_2_BackwardsIterator(){
  }

  t_std_collections_List_1Tt_default_Voice_2_BackwardsIterator(bbNullCtor_t){
  }
};

int bbCompare(const t_std_collections_List_1Tt_default_Voice_2_BackwardsIterator&x,const t_std_collections_List_1Tt_default_Voice_2_BackwardsIterator&y);

void bbGCMark(const t_std_collections_List_1Tt_default_Voice_2_BackwardsIterator&);

struct t_std_collections_List_1Tt_default_Voice_2 : public bbObject,public virtual t_std_collections_IContainer_1Tt_default_Voice_2{

  const char *typeName()const{return "t_std_collections_List_1Tt_default_Voice_2";}

  bbGCVar<t_std_collections_List_1Tt_default_Voice_2_Node> m__0head{};
  bbInt m__0seq{};

  void gcMark();

  t_std_collections_List_1Tt_default_Voice_2(t_std_collections_List_1Tt_default_Voice_2* l_values);
  t_std_collections_List_1Tt_default_Voice_2(t_std_collections_Stack_1Tt_default_Voice_2* l_values);
  t_std_collections_List_1Tt_default_Voice_2(bbArray<bbGCVar<t_default_Voice>>* l_values);
  t_std_collections_List_1Tt_default_Voice_2();

  bbArray<bbGCVar<t_default_Voice>>* m_ToArray();
  void m_Sort(bbFunction<bbInt(t_default_Voice*,t_default_Voice*)> l_compareFunc);
  void m_Sort(bbBool l_ascending);
  t_default_Voice* m_RemoveLast();
  bbBool m_RemoveLast(t_default_Voice* l_value);
  t_default_Voice* m_RemoveFirst();
  bbInt m_RemoveEach(t_default_Voice* l_value);
  bbBool m_Remove(t_default_Voice* l_value);
  t_std_collections_List_1Tt_default_Voice_2_Node* m_LastNode();
  t_default_Voice* m_Last();
  t_std_collections_List_1Tt_default_Voice_2_Node* m_HeadNode();
  t_std_collections_List_1Tt_default_Voice_2_Node* m_FirstNode();
  t_default_Voice* m_First();
  t_std_collections_List_1Tt_default_Voice_2_Node* m_FindNode(t_default_Voice* l_value);
  t_std_collections_List_1Tt_default_Voice_2_Node* m_FindLastNode(t_default_Voice* l_value);
  bbBool m_Empty();
  bbInt m_Count();
  void m_Clear();
  t_std_collections_List_1Tt_default_Voice_2_BackwardsIterator m_Backwards();
  t_std_collections_List_1Tt_default_Voice_2_Iterator m_All();
  t_std_collections_List_1Tt_default_Voice_2_Node* m_AddLast(t_default_Voice* l_value);
  t_std_collections_List_1Tt_default_Voice_2_Node* m_AddFirst(t_default_Voice* l_value);
  void m_AddAll(bbArray<bbGCVar<t_default_Voice>>* l_values);
  void m_Add(t_default_Voice* l_value);
};

#endif
