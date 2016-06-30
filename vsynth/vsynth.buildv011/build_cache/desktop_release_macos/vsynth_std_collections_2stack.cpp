
#include "vsynth_std_collections_2stack.h"

// ***** External *****

#include "../../../../../../monkey2/modules/monkey/monkey.buildv011/desktop_release_macos/monkey_debug.h"
#include "vsynth_std_collections_2list.h"
#include "vsynth_vsynth.h"

extern bbInt g_monkey_math_Max_1i(bbInt l_x,bbInt l_y);

// ***** Internal *****

void g_std_collections_Stack_1Tt_default_Voice_2_AddAll_1Tt_std_collections_List_1Tt_default_Voice_2_2(t_std_collections_Stack_1Tt_default_Voice_2* l_self,t_std_collections_List_1Tt_default_Voice_2* l_values){
  {
    struct f1_t : public bbGCFrame{
      t_std_collections_List_1Tt_default_Voice_2_Iterator l_0{};
      void gcMark(){
        bbGCMark(l_0);
      }
    }f1{};
    f1.l_0=l_values->m_All();
    for(;!f1.l_0.m_AtEnd();f1.l_0.m_Bump()){
      struct f2_t : public bbGCFrame{
        t_default_Voice* l_value{};
        void gcMark(){
          bbGCMarkPtr(l_value);
        }
      }f2{};
      f2.l_value=f1.l_0.m_Current();
      l_self->m_Add(f2.l_value);
    }
  }
}

t_std_collections_Stack_1Tt_default_Voice_2_Iterator::t_std_collections_Stack_1Tt_default_Voice_2_Iterator(t_std_collections_Stack_1Tt_default_Voice_2* l_stack,bbInt l_index){
  (*this).m__0stack=l_stack;
  (*this).m__0index=l_index;
  (*this).m__0seq=l_stack->m__0seq;
}

void t_std_collections_Stack_1Tt_default_Voice_2_Iterator::m_Insert(t_default_Voice* l_value){
  (*this).m_AssertSeq();
  (*this).m__0stack->m_Insert((*this).m__0index,l_value);
  (*this).m__0seq=(*this).m__0stack->m__0seq;
}

void t_std_collections_Stack_1Tt_default_Voice_2_Iterator::m_Erase(){
  (*this).m_AssertSeq();
  (*this).m__0stack->m_Erase((*this).m__0index);
  (*this).m__0seq=(*this).m__0stack->m__0seq;
}

void t_std_collections_Stack_1Tt_default_Voice_2_Iterator::m_Current(t_default_Voice* l_current){
  (*this).m_AssertCurrent();
  (*this).m__0stack->m__0data->at((*this).m__0index)=l_current;
}

t_default_Voice* t_std_collections_Stack_1Tt_default_Voice_2_Iterator::m_Current(){
  (*this).m_AssertCurrent();
  return (*this).m__0stack->m__0data->at((*this).m__0index);
}

void t_std_collections_Stack_1Tt_default_Voice_2_Iterator::m_Bump(){
  (*this).m_AssertCurrent();
  (*this).m__0index+=1;
}

bbBool t_std_collections_Stack_1Tt_default_Voice_2_Iterator::m_AtEnd(){
  (*this).m_AssertSeq();
  return ((*this).m__0index==(*this).m__0stack->m__0length);
}

void t_std_collections_Stack_1Tt_default_Voice_2_Iterator::m_AssertSeq(){
  bbDebugAssert(((*this).m__0seq==(*this).m__0stack->m__0seq),BB_T("Concurrent list modification"));
}

void t_std_collections_Stack_1Tt_default_Voice_2_Iterator::m_AssertCurrent(){
  bbDebugAssert(!(*this).m_AtEnd(),BB_T("Invalid list iterator"));
}

int bbCompare(const t_std_collections_Stack_1Tt_default_Voice_2_Iterator&x,const t_std_collections_Stack_1Tt_default_Voice_2_Iterator&y){
  if(int t=bbCompare(x.m__0stack,y.m__0stack)) return t;
  if(int t=bbCompare(x.m__0index,y.m__0index)) return t;
  if(int t=bbCompare(x.m__0seq,y.m__0seq)) return t;
  return 0;
}

void bbGCMark(const t_std_collections_Stack_1Tt_default_Voice_2_Iterator&t){
  bbGCMark(t.m__0stack);
}

t_std_collections_Stack_1Tt_default_Voice_2_BackwardsIterator::t_std_collections_Stack_1Tt_default_Voice_2_BackwardsIterator(t_std_collections_Stack_1Tt_default_Voice_2* l_stack,bbInt l_index){
  (*this).m__0stack=l_stack;
  (*this).m__0index=l_index;
  (*this).m__0seq=l_stack->m__0seq;
}

void t_std_collections_Stack_1Tt_default_Voice_2_BackwardsIterator::m_Insert(t_default_Voice* l_value){
  (*this).m_AssertSeq();
  (*this).m__0index+=1;
  (*this).m__0stack->m_Insert((*this).m__0index,l_value);
  (*this).m__0seq=(*this).m__0stack->m__0seq;
}

void t_std_collections_Stack_1Tt_default_Voice_2_BackwardsIterator::m_Erase(){
  (*this).m_AssertCurrent();
  (*this).m__0index-=1;
  (*this).m__0stack->m_Erase(((*this).m__0index+1));
  (*this).m__0seq=(*this).m__0stack->m__0seq;
}

void t_std_collections_Stack_1Tt_default_Voice_2_BackwardsIterator::m_Current(t_default_Voice* l_current){
  (*this).m_AssertCurrent();
  (*this).m__0stack->m__0data->at((*this).m__0index)=l_current;
}

t_default_Voice* t_std_collections_Stack_1Tt_default_Voice_2_BackwardsIterator::m_Current(){
  (*this).m_AssertCurrent();
  return (*this).m__0stack->m__0data->at((*this).m__0index);
}

void t_std_collections_Stack_1Tt_default_Voice_2_BackwardsIterator::m_Bump(){
  (*this).m_AssertCurrent();
  (*this).m__0index-=1;
}

bbBool t_std_collections_Stack_1Tt_default_Voice_2_BackwardsIterator::m_AtEnd(){
  (*this).m_AssertSeq();
  return ((*this).m__0index==-1);
}

void t_std_collections_Stack_1Tt_default_Voice_2_BackwardsIterator::m_AssertSeq(){
  bbDebugAssert(((*this).m__0seq==(*this).m__0stack->m__0seq),BB_T("Concurrent list modification"));
}

void t_std_collections_Stack_1Tt_default_Voice_2_BackwardsIterator::m_AssertCurrent(){
  bbDebugAssert(!(*this).m_AtEnd(),BB_T("Invalid list iterator"));
}

int bbCompare(const t_std_collections_Stack_1Tt_default_Voice_2_BackwardsIterator&x,const t_std_collections_Stack_1Tt_default_Voice_2_BackwardsIterator&y){
  if(int t=bbCompare(x.m__0stack,y.m__0stack)) return t;
  if(int t=bbCompare(x.m__0index,y.m__0index)) return t;
  if(int t=bbCompare(x.m__0seq,y.m__0seq)) return t;
  return 0;
}

void bbGCMark(const t_std_collections_Stack_1Tt_default_Voice_2_BackwardsIterator&t){
  bbGCMark(t.m__0stack);
}

void t_std_collections_Stack_1Tt_default_Voice_2::gcMark(){
  bbGCMark(m__0data);
}

t_std_collections_Stack_1Tt_default_Voice_2::t_std_collections_Stack_1Tt_default_Voice_2(t_std_collections_List_1Tt_default_Voice_2* l_values){
  g_std_collections_Stack_1Tt_default_Voice_2_AddAll_1Tt_std_collections_List_1Tt_default_Voice_2_2(this,l_values);
}

t_std_collections_Stack_1Tt_default_Voice_2::t_std_collections_Stack_1Tt_default_Voice_2(t_std_collections_Stack_1Tt_default_Voice_2* l_values){
  struct f0_t : public bbGCFrame{
    bbArray<bbGCVar<t_default_Voice>>* t0{};
    void gcMark(){
      bbGCMarkPtr(t0);
    }
  }f0{};
  this->m__0length=l_values->m_Length();
  this->m__0data=bbArray<bbGCVar<t_default_Voice>>::create(this->m__0length);
  (f0.t0=l_values->m_Data())->copyTo(this->m__0data,bbInt(0),bbInt(0),this->m__0length);
}

t_std_collections_Stack_1Tt_default_Voice_2::t_std_collections_Stack_1Tt_default_Voice_2(bbArray<bbGCVar<t_default_Voice>>* l_values){
  this->m_AddAll(l_values);
}

t_std_collections_Stack_1Tt_default_Voice_2::t_std_collections_Stack_1Tt_default_Voice_2(bbInt l_length){
  this->m__0length=l_length;
  this->m__0data=bbArray<bbGCVar<t_default_Voice>>::create(this->m__0length);
}

t_std_collections_Stack_1Tt_default_Voice_2::t_std_collections_Stack_1Tt_default_Voice_2(){
  this->m__0data=bbArray<bbGCVar<t_default_Voice>>::create(10);
}

void t_std_collections_Stack_1Tt_default_Voice_2::m__idxeq(bbInt l_index,t_default_Voice* l_value){
  bbDebugAssert(((l_index>=bbInt(0))&&(l_index<this->m__0length)),BB_T("Stack index out of range"));
  this->m__0data->at(l_index)=l_value;
}

t_default_Voice* t_std_collections_Stack_1Tt_default_Voice_2::m__idx(bbInt l_index){
  bbDebugAssert(((l_index>=bbInt(0))&&(l_index<this->m__0length)),BB_T("Stack index out of range"));
  return this->m__0data->at(l_index);
}

t_default_Voice* t_std_collections_Stack_1Tt_default_Voice_2::m_Top(){
  bbDebugAssert(bbBool(this->m__0length),BB_T("Stack is empty"));
  return this->m__0data->at((this->m__0length-1));
}

bbArray<bbGCVar<t_default_Voice>>* t_std_collections_Stack_1Tt_default_Voice_2::m_ToArray(){
  return this->m__0data->slice(bbInt(0),this->m__0length);
}

void t_std_collections_Stack_1Tt_default_Voice_2::m_Swap(bbInt l_index1,bbInt l_index2){
  struct f0_t : public bbGCFrame{
    t_default_Voice* l_t{};
    void gcMark(){
      bbGCMarkPtr(l_t);
    }
  }f0{};
  bbDebugAssert(((((l_index1>=bbInt(0))&&(l_index1<this->m__0length))&&(l_index2>=bbInt(0)))&&(l_index2<this->m__0length)),BB_T("Stack index out of range"));
  f0.l_t=this->m__0data->at(l_index1);
  this->m__0data->at(l_index1)=this->m__0data->at(l_index2);
  this->m__0data->at(l_index2)=f0.l_t;
}

void t_std_collections_Stack_1Tt_default_Voice_2::m_Sort(bbFunction<bbInt(t_default_Voice*,t_default_Voice*)> l_compareFunc,bbInt l_lo,bbInt l_hi){
  if((l_hi<=l_lo)){
    return;
  }
  if(((l_lo+1)==l_hi)){
    if((l_compareFunc(this->m__0data->at(l_hi),this->m__0data->at(l_lo))<bbInt(0))){
      this->m_Swap(l_hi,l_lo);
    }
    return;
  }
  bbInt l_i=((l_lo+l_hi)/2);
  if((l_compareFunc(this->m__0data->at(l_i),this->m__0data->at(l_lo))<bbInt(0))){
    this->m_Swap(l_i,l_lo);
  }
  if((l_compareFunc(this->m__0data->at(l_hi),this->m__0data->at(l_i))<bbInt(0))){
    this->m_Swap(l_hi,l_i);
    if((l_compareFunc(this->m__0data->at(l_i),this->m__0data->at(l_lo))<bbInt(0))){
      this->m_Swap(l_i,l_lo);
    }
  }
  bbInt l_x=(l_lo+1);
  bbInt l_y=(l_hi-1);
  do{
    struct f1_t : public bbGCFrame{
      t_default_Voice* l_p{};
      void gcMark(){
        bbGCMarkPtr(l_p);
      }
    }f1{};
    f1.l_p=this->m__0data->at(l_i);
    while((l_compareFunc(this->m__0data->at(l_x),f1.l_p)<bbInt(0))){
      l_x+=1;
    }
    while((l_compareFunc(f1.l_p,this->m__0data->at(l_y))<bbInt(0))){
      l_y-=1;
    }
    if((l_x>l_y)){
      break;
    }
    if((l_x<l_y)){
      this->m_Swap(l_x,l_y);
      if((l_i==l_x)){
        l_i=l_y;
      }else if((l_i==l_y)){
        l_i=l_x;
      }
    }
    l_x+=1;
    l_y-=1;
  }while(!((l_x>l_y)));
  this->m_Sort(l_compareFunc,l_lo,l_y);
  this->m_Sort(l_compareFunc,l_x,l_hi);
}

void t_std_collections_Stack_1Tt_default_Voice_2::m_Sort(bbFunction<bbInt(t_default_Voice*,t_default_Voice*)> l_compareFunc){
  this->m_Sort(l_compareFunc,bbInt(0),(this->m__0length-1));
}

void t_std_collections_Stack_1Tt_default_Voice_2::m_Sort(bbBool l_ascending){
  if(l_ascending){
    struct lambda0 : public bbFunction<bbInt(t_default_Voice*,t_default_Voice*)>::Rep{
      t_std_collections_Stack_1Tt_default_Voice_2* l_self;
      lambda0(t_std_collections_Stack_1Tt_default_Voice_2* l_self):l_self(l_self){
      }
      bbInt invoke(t_default_Voice* l_x,t_default_Voice* l_y){
        return bbCompare(l_x,l_y);
      }
      void gcMark(){
        bbGCMarkPtr(l_self);
      }
    };
    this->m_Sort(bbFunction<bbInt(t_default_Voice*,t_default_Voice*)>(new lambda0(this)));
  }else{
    struct lambda1 : public bbFunction<bbInt(t_default_Voice*,t_default_Voice*)>::Rep{
      t_std_collections_Stack_1Tt_default_Voice_2* l_self;
      lambda1(t_std_collections_Stack_1Tt_default_Voice_2* l_self):l_self(l_self){
      }
      bbInt invoke(t_default_Voice* l_x,t_default_Voice* l_y){
        return bbCompare(l_y,l_x);
      }
      void gcMark(){
        bbGCMarkPtr(l_self);
      }
    };
    this->m_Sort(bbFunction<bbInt(t_default_Voice*,t_default_Voice*)>(new lambda1(this)));
  }
}

t_std_collections_Stack_1Tt_default_Voice_2* t_std_collections_Stack_1Tt_default_Voice_2::m_Slice(bbInt l_index1,bbInt l_index2){
  struct f0_t : public bbGCFrame{
    bbArray<bbGCVar<t_default_Voice>>* t0{};
    void gcMark(){
      bbGCMarkPtr(t0);
    }
  }f0{};
  if((l_index1<bbInt(0))){
    l_index1=g_monkey_math_Max_1i((l_index1+this->m__0length),bbInt(0));
  }else if((l_index1>this->m__0length)){
    l_index1=this->m__0length;
  }
  if((l_index2<bbInt(0))){
    l_index2=g_monkey_math_Max_1i((l_index2+this->m__0length),l_index1);
  }else if((l_index2>this->m__0length)){
    l_index2=this->m__0length;
  }else if((l_index2<l_index1)){
    l_index2=l_index1;
  }
  return bbGCNew<t_std_collections_Stack_1Tt_default_Voice_2>(f0.t0=this->m__0data->slice(l_index1,l_index2));
}

t_std_collections_Stack_1Tt_default_Voice_2* t_std_collections_Stack_1Tt_default_Voice_2::m_Slice(bbInt l_index){
  return this->m_Slice(l_index,this->m__0length);
}

void t_std_collections_Stack_1Tt_default_Voice_2::m_Set(bbInt l_index,t_default_Voice* l_value){
  bbDebugAssert(((l_index>=bbInt(0))&&(l_index<this->m__0length)),BB_T("Stack index out of range"));
  this->m__0data->at(l_index)=l_value;
}

void t_std_collections_Stack_1Tt_default_Voice_2::m_Resize(bbInt l_length){
  bbDebugAssert((l_length>=bbInt(0)),BB_T("Debug assert failed"));
  {
    bbInt l_i=l_length;
    for(;(l_i<this->m__0length);l_i+=1){
      this->m__0data->at(l_i)=((t_default_Voice*)0);
    }
  }
  this->m_Reserve(l_length);
  this->m__0length=l_length;
  this->m__0seq+=1;
}

void t_std_collections_Stack_1Tt_default_Voice_2::m_Reserve(bbInt l_capacity){
  struct f0_t : public bbGCFrame{
    bbArray<bbGCVar<t_default_Voice>>* l_data{};
    void gcMark(){
      bbGCMarkPtr(l_data);
    }
  }f0{};
  bbDebugAssert((l_capacity>=bbInt(0)),BB_T("Debug assert failed"));
  if((this->m__0data->length()>=l_capacity)){
    return;
  }
  l_capacity=g_monkey_math_Max_1i(((this->m__0length*2)+this->m__0length),l_capacity);
  f0.l_data=bbArray<bbGCVar<t_default_Voice>>::create(l_capacity);
  this->m__0data->copyTo(f0.l_data,bbInt(0),bbInt(0),this->m__0length);
  this->m__0data=f0.l_data;
}

bbBool t_std_collections_Stack_1Tt_default_Voice_2::m_RemoveLast(t_default_Voice* l_value,bbInt l_start){
  bbInt l_i=this->m_FindLastIndex(l_value,l_start);
  if((l_i==-1)){
    return false;
  }
  this->m_Erase(l_i);
  return true;
}

bbInt t_std_collections_Stack_1Tt_default_Voice_2::m_RemoveEach(t_default_Voice* l_value){
  bbInt l_put=bbInt(0);
  bbInt l_n=bbInt(0);
  {
    bbInt l_get=bbInt(0);
    for(;(l_get<this->m__0length);l_get+=1){
      if((this->m__0data->at(l_get)==l_value)){
        l_n+=1;
        continue;
      }
      this->m__0data->at(l_put)=this->m__0data->at(l_get);
      l_put+=1;
    }
  }
  this->m_Resize(l_put);
  return l_n;
}

bbBool t_std_collections_Stack_1Tt_default_Voice_2::m_Remove(t_default_Voice* l_value,bbInt l_start){
  bbInt l_i=this->m_FindIndex(l_value,l_start);
  if((l_i==-1)){
    return false;
  }
  this->m_Erase(l_i);
  return true;
}

void t_std_collections_Stack_1Tt_default_Voice_2::m_Push(t_default_Voice* l_value){
  this->m_Add(l_value);
}

t_default_Voice* t_std_collections_Stack_1Tt_default_Voice_2::m_Pop(){
  struct f0_t : public bbGCFrame{
    t_default_Voice* l_value{};
    void gcMark(){
      bbGCMarkPtr(l_value);
    }
  }f0{};
  bbDebugAssert(bbBool(this->m__0length),BB_T("Stack is empty"));
  this->m__0length-=1;
  this->m__0seq+=1;
  f0.l_value=this->m__0data->at(this->m__0length);
  this->m__0data->at(this->m__0length)=((t_default_Voice*)0);
  return f0.l_value;
}

bbInt t_std_collections_Stack_1Tt_default_Voice_2::m_Length(){
  return this->m__0length;
}

void t_std_collections_Stack_1Tt_default_Voice_2::m_Insert(bbInt l_index,t_default_Voice* l_value){
  bbDebugAssert(((l_index>=bbInt(0))&&(l_index<=this->m__0length)),BB_T("Debug assert failed"));
  this->m_Reserve((this->m__0length+1));
  this->m__0data->copyTo(this->m__0data,l_index,(l_index+1),(this->m__0length-l_index));
  this->m__0data->at(l_index)=l_value;
  this->m__0length+=1;
  this->m__0seq+=1;
}

t_default_Voice* t_std_collections_Stack_1Tt_default_Voice_2::m_Get(bbInt l_index){
  bbDebugAssert(((l_index>=bbInt(0))&&(l_index<this->m__0length)),BB_T("Stack index out of range"));
  return this->m__0data->at(l_index);
}

bbInt t_std_collections_Stack_1Tt_default_Voice_2::m_FindLastIndex(t_default_Voice* l_value,bbInt l_start){
  bbDebugAssert(((l_start>=bbInt(0))&&(l_start<=this->m__0length)),BB_T("Debug assert failed"));
  bbInt l_i=this->m__0length;
  while((l_i>l_start)){
    l_i-=1;
    if((this->m__0data->at(l_i)==l_value)){
      return l_i;
    }
  }
  return -1;
}

bbInt t_std_collections_Stack_1Tt_default_Voice_2::m_FindIndex(t_default_Voice* l_value,bbInt l_start){
  bbDebugAssert(((l_start>=bbInt(0))&&(l_start<=this->m__0length)),BB_T("Debug assert failed"));
  bbInt l_i=l_start;
  while((l_i<this->m__0length)){
    if((this->m__0data->at(l_i)==l_value)){
      return l_i;
    }
    l_i+=1;
  }
  return -1;
}

void t_std_collections_Stack_1Tt_default_Voice_2::m_Erase(bbInt l_index1,bbInt l_index2){
  bbDebugAssert((((((l_index1>=bbInt(0))&&(l_index1<=this->m__0length))&&(l_index2>=bbInt(0)))&&(l_index2<=this->m__0length))&&(l_index1<=l_index2)),BB_T("Debug assert failed"));
  if((l_index1==this->m__0length)){
    return;
  }
  this->m__0data->copyTo(this->m__0data,l_index2,l_index1,(this->m__0length-l_index2));
  this->m_Resize(((this->m__0length-l_index2)+l_index1));
}

void t_std_collections_Stack_1Tt_default_Voice_2::m_Erase(bbInt l_index){
  bbDebugAssert(((l_index>=bbInt(0))&&(l_index<=this->m__0length)),BB_T("Debug assert failed"));
  if((l_index==this->m__0length)){
    return;
  }
  this->m__0data->copyTo(this->m__0data,(l_index+1),l_index,((this->m__0length-l_index)-1));
  this->m_Resize((this->m__0length-1));
}

bbBool t_std_collections_Stack_1Tt_default_Voice_2::m_Empty(){
  return (this->m__0length==bbInt(0));
}

bbArray<bbGCVar<t_default_Voice>>* t_std_collections_Stack_1Tt_default_Voice_2::m_Data(){
  return this->m__0data;
}

bbBool t_std_collections_Stack_1Tt_default_Voice_2::m_Contains(t_default_Voice* l_value){
  return (this->m_FindIndex(l_value,bbInt(0))!=-1);
}

void t_std_collections_Stack_1Tt_default_Voice_2::m_Clear(){
  this->m_Resize(bbInt(0));
}

bbInt t_std_collections_Stack_1Tt_default_Voice_2::m_Capacity(){
  return this->m__0data->length();
}

t_std_collections_Stack_1Tt_default_Voice_2_BackwardsIterator t_std_collections_Stack_1Tt_default_Voice_2::m_Backwards(){
  return t_std_collections_Stack_1Tt_default_Voice_2_BackwardsIterator(this,(this->m__0length-1));
}

t_std_collections_Stack_1Tt_default_Voice_2_Iterator t_std_collections_Stack_1Tt_default_Voice_2::m_All(){
  return t_std_collections_Stack_1Tt_default_Voice_2_Iterator(this,bbInt(0));
}

void t_std_collections_Stack_1Tt_default_Voice_2::m_AddAll(bbArray<bbGCVar<t_default_Voice>>* l_values){
  this->m_Reserve((this->m__0length+l_values->length()));
  l_values->copyTo(this->m__0data,bbInt(0),this->m__0length,l_values->length());
  this->m_Resize((this->m__0length+l_values->length()));
}

void t_std_collections_Stack_1Tt_default_Voice_2::m_Add(t_default_Voice* l_value){
  this->m_Reserve((this->m__0length+1));
  this->m__0data->at(this->m__0length)=l_value;
  this->m__0length+=1;
  this->m__0seq+=1;
}

void mx2_vsynth_std_collections_2stack_init(){
  static bool done;
  if(done) return;
  done=true;
}

bbInit mx2_vsynth_std_collections_2stack_init_v("vsynth_std_collections_2stack",&mx2_vsynth_std_collections_2stack_init);
