
#ifndef MX2_VSYNTH_STD_COLLECTIONS_2STACK_H
#define MX2_VSYNTH_STD_COLLECTIONS_2STACK_H

#include <bbmonkey.h>
#include "../../../../../../monkey2/modules/std/std.buildv011/desktop_debug_macos/std_collections_2stack.h"

// ***** External *****

#include "../../../../../../monkey2/modules/monkey/monkey.buildv011/desktop_debug_macos/monkey_types.h"
#include "vsynth_std_collections_2container.h"

struct t_std_collections_List_1Tt_default_Voice_2;
bbString bbDBType(t_std_collections_List_1Tt_default_Voice_2**);
bbString bbDBValue(t_std_collections_List_1Tt_default_Voice_2**);
struct t_default_Voice;
bbString bbDBType(t_default_Voice**);
bbString bbDBValue(t_default_Voice**);

// ***** Internal *****

struct t_std_collections_Stack_1Tt_default_Voice_2_Iterator;
struct t_std_collections_Stack_1Tt_default_Voice_2_BackwardsIterator;
struct t_std_collections_Stack_1Tt_default_Voice_2;

extern void g_std_collections_Stack_1Tt_default_Voice_2_AddAll_1Tt_std_collections_List_1Tt_default_Voice_2_2(t_std_collections_Stack_1Tt_default_Voice_2* l_self,t_std_collections_List_1Tt_default_Voice_2* l_values);

struct t_std_collections_Stack_1Tt_default_Voice_2_Iterator{
  const char *typeName()const{return "t_std_collections_Stack_1Tt_default_Voice_2_Iterator";}

  bbGCVar<t_std_collections_Stack_1Tt_default_Voice_2> m__0stack{};
  bbInt m__0index{};
  bbInt m__0seq{};
  static void dbEmit(t_std_collections_Stack_1Tt_default_Voice_2_Iterator*);

  t_std_collections_Stack_1Tt_default_Voice_2_Iterator(t_std_collections_Stack_1Tt_default_Voice_2* l_stack,bbInt l_index);

  void m_Insert(t_default_Voice* l_value);
  void m_Erase();
  void m_Current(t_default_Voice* l_current);
  t_default_Voice* m_Current();
  void m_Bump();
  bbBool m_AtEnd();
  void m_AssertSeq();
  void m_AssertCurrent();

  t_std_collections_Stack_1Tt_default_Voice_2_Iterator(){
  }

  t_std_collections_Stack_1Tt_default_Voice_2_Iterator(bbNullCtor_t){
  }
};
bbString bbDBType(t_std_collections_Stack_1Tt_default_Voice_2_Iterator*);
bbString bbDBValue(t_std_collections_Stack_1Tt_default_Voice_2_Iterator*);

int bbCompare(const t_std_collections_Stack_1Tt_default_Voice_2_Iterator&x,const t_std_collections_Stack_1Tt_default_Voice_2_Iterator&y);

void bbGCMark(const t_std_collections_Stack_1Tt_default_Voice_2_Iterator&);

struct t_std_collections_Stack_1Tt_default_Voice_2_BackwardsIterator{
  const char *typeName()const{return "t_std_collections_Stack_1Tt_default_Voice_2_BackwardsIterator";}

  bbGCVar<t_std_collections_Stack_1Tt_default_Voice_2> m__0stack{};
  bbInt m__0index{};
  bbInt m__0seq{};
  static void dbEmit(t_std_collections_Stack_1Tt_default_Voice_2_BackwardsIterator*);

  t_std_collections_Stack_1Tt_default_Voice_2_BackwardsIterator(t_std_collections_Stack_1Tt_default_Voice_2* l_stack,bbInt l_index);

  void m_Insert(t_default_Voice* l_value);
  void m_Erase();
  void m_Current(t_default_Voice* l_current);
  t_default_Voice* m_Current();
  void m_Bump();
  bbBool m_AtEnd();
  void m_AssertSeq();
  void m_AssertCurrent();

  t_std_collections_Stack_1Tt_default_Voice_2_BackwardsIterator(){
  }

  t_std_collections_Stack_1Tt_default_Voice_2_BackwardsIterator(bbNullCtor_t){
  }
};
bbString bbDBType(t_std_collections_Stack_1Tt_default_Voice_2_BackwardsIterator*);
bbString bbDBValue(t_std_collections_Stack_1Tt_default_Voice_2_BackwardsIterator*);

int bbCompare(const t_std_collections_Stack_1Tt_default_Voice_2_BackwardsIterator&x,const t_std_collections_Stack_1Tt_default_Voice_2_BackwardsIterator&y);

void bbGCMark(const t_std_collections_Stack_1Tt_default_Voice_2_BackwardsIterator&);

struct t_std_collections_Stack_1Tt_default_Voice_2 : public bbObject,public virtual t_std_collections_IContainer_1Tt_default_Voice_2{

  const char *typeName()const{return "t_std_collections_Stack_1Tt_default_Voice_2";}

  bbGCVar<bbArray<bbGCVar<t_default_Voice>>> m__0data{};
  bbInt m__0length{};
  bbInt m__0seq{};

  void gcMark();
  void dbEmit();

  t_std_collections_Stack_1Tt_default_Voice_2(t_std_collections_List_1Tt_default_Voice_2* l_values);
  t_std_collections_Stack_1Tt_default_Voice_2(t_std_collections_Stack_1Tt_default_Voice_2* l_values);
  t_std_collections_Stack_1Tt_default_Voice_2(bbArray<bbGCVar<t_default_Voice>>* l_values);
  t_std_collections_Stack_1Tt_default_Voice_2(bbInt l_length);
  t_std_collections_Stack_1Tt_default_Voice_2();

  void m__idxeq(bbInt l_index,t_default_Voice* l_value);
  t_default_Voice* m__idx(bbInt l_index);
  t_default_Voice* m_Top();
  bbArray<bbGCVar<t_default_Voice>>* m_ToArray();
  void m_Swap(bbInt l_index1,bbInt l_index2);
  void m_Sort(bbFunction<bbInt(t_default_Voice*,t_default_Voice*)> l_compareFunc,bbInt l_lo,bbInt l_hi);
  void m_Sort(bbFunction<bbInt(t_default_Voice*,t_default_Voice*)> l_compareFunc);
  void m_Sort(bbBool l_ascending);
  t_std_collections_Stack_1Tt_default_Voice_2* m_Slice(bbInt l_index1,bbInt l_index2);
  t_std_collections_Stack_1Tt_default_Voice_2* m_Slice(bbInt l_index);
  void m_Set(bbInt l_index,t_default_Voice* l_value);
  void m_Resize(bbInt l_length);
  void m_Reserve(bbInt l_capacity);
  bbBool m_RemoveLast(t_default_Voice* l_value,bbInt l_start);
  bbInt m_RemoveEach(t_default_Voice* l_value);
  bbBool m_Remove(t_default_Voice* l_value,bbInt l_start);
  void m_Push(t_default_Voice* l_value);
  t_default_Voice* m_Pop();
  bbInt m_Length();
  void m_Insert(bbInt l_index,t_default_Voice* l_value);
  t_default_Voice* m_Get(bbInt l_index);
  bbInt m_FindLastIndex(t_default_Voice* l_value,bbInt l_start);
  bbInt m_FindIndex(t_default_Voice* l_value,bbInt l_start);
  void m_Erase(bbInt l_index1,bbInt l_index2);
  void m_Erase(bbInt l_index);
  bbBool m_Empty();
  bbArray<bbGCVar<t_default_Voice>>* m_Data();
  bbBool m_Contains(t_default_Voice* l_value);
  void m_Clear();
  bbInt m_Capacity();
  t_std_collections_Stack_1Tt_default_Voice_2_BackwardsIterator m_Backwards();
  t_std_collections_Stack_1Tt_default_Voice_2_Iterator m_All();
  void m_AddAll(bbArray<bbGCVar<t_default_Voice>>* l_values);
  void m_Add(t_default_Voice* l_value);
};
bbString bbDBType(t_std_collections_Stack_1Tt_default_Voice_2**);
bbString bbDBValue(t_std_collections_Stack_1Tt_default_Voice_2**);

#endif
