
#include "vsynth_std_collections_2stack.h"

// ***** External *****

#include "../../../../../../monkey2/modules/monkey/monkey.buildv1.0.0/desktop_debug_macos/monkey_debug.h"
#include "vsynth_std_collections_2list.h"
#include "vsynth_vsynth.h"

extern bbInt g_monkey_math_Max_1i(bbInt l_x,bbInt l_y);

// ***** Internal *****

void g_std_collections_Stack_1Tt_default_Voice_2_AddAll_1Tt_std_collections_List_1Tt_default_Voice_2_2(t_std_collections_Stack_1Tt_default_Voice_2* l_self,t_std_collections_List_1Tt_default_Voice_2* l_values){
  bbDBFrame db_f{"AddAll<std.collections.List<default.Voice>>:Void(values:std.collections.List<default.Voice>)","/Users/simon/monkey2/modules/std/collections/stack.monkey2"};
  t_std_collections_Stack_1Tt_default_Voice_2*self=l_self;
  bbDBLocal("Self",&self);
  bbDBLocal("values",&l_values);
  bbDBStmt(2060290);
  {
    struct f1_t : public bbGCFrame{
      t_std_collections_List_1Tt_default_Voice_2_Iterator l_0{};
      void gcMark(){
        bbGCMark(l_0);
      }
    }f1{};
    bbDBLoop db_loop;
    f1.l_0=l_values->m_All();
    bbDBLocal("0",&f1.l_0);
    for(;!f1.l_0.m_AtEnd();f1.l_0.m_Bump()){
      struct f2_t : public bbGCFrame{
        t_default_Voice* l_value{};
        void gcMark(){
          bbGCMarkPtr(l_value);
        }
      }f2{};
      bbDBBlock db_blk;
      f2.l_value=f1.l_0.m_Current();
      bbDBLocal("value",&f2.l_value);
      bbDBStmt(2064387);
      l_self->m_Add(f2.l_value);
    }
  }
}

void t_std_collections_Stack_1Tt_default_Voice_2_Iterator::dbEmit(t_std_collections_Stack_1Tt_default_Voice_2_Iterator*p){
  bbDBEmit("_stack",&p->m__0stack);
  bbDBEmit("_index",&p->m__0index);
  bbDBEmit("_seq",&p->m__0seq);
}

t_std_collections_Stack_1Tt_default_Voice_2_Iterator::t_std_collections_Stack_1Tt_default_Voice_2_Iterator(t_std_collections_Stack_1Tt_default_Voice_2* l_stack,bbInt l_index){
  bbDBFrame db_f{"new:Void(stack:std.collections.Stack<default.Voice>,index:Int)","/Users/simon/monkey2/modules/std/collections/stack.monkey2"};
  bbDBLocal("stack",&l_stack);
  bbDBLocal("index",&l_index);
  bbDBStmt(204803);
  (*this).m__0stack=l_stack;
  bbDBStmt(208899);
  (*this).m__0index=l_index;
  bbDBStmt(212995);
  (*this).m__0seq=l_stack->m__0seq;
}

void t_std_collections_Stack_1Tt_default_Voice_2_Iterator::m_Insert(t_default_Voice* l_value){
  bbDBFrame db_f{"Insert:Void(value:default.Voice)","/Users/simon/monkey2/modules/std/collections/stack.monkey2"};
  t_std_collections_Stack_1Tt_default_Voice_2_Iterator*self=&(*this);
  bbDBLocal("Self",self);
  bbDBLocal("value",&l_value);
  bbDBStmt(413699);
  (*this).m_AssertSeq();
  bbDBStmt(417795);
  (*this).m__0stack->m_Insert((*this).m__0index,l_value);
  bbDBStmt(421891);
  (*this).m__0seq=(*this).m__0stack->m__0seq;
}

void t_std_collections_Stack_1Tt_default_Voice_2_Iterator::m_Erase(){
  bbDBFrame db_f{"Erase:Void()","/Users/simon/monkey2/modules/std/collections/stack.monkey2"};
  t_std_collections_Stack_1Tt_default_Voice_2_Iterator*self=&(*this);
  bbDBLocal("Self",self);
  bbDBStmt(368643);
  (*this).m_AssertSeq();
  bbDBStmt(372739);
  (*this).m__0stack->m_Erase((*this).m__0index);
  bbDBStmt(376835);
  (*this).m__0seq=(*this).m__0stack->m__0seq;
}

void t_std_collections_Stack_1Tt_default_Voice_2_Iterator::m_Current(t_default_Voice* l_current){
  bbDBFrame db_f{"Current:Void(current:default.Voice)","/Users/simon/monkey2/modules/std/collections/stack.monkey2"};
  t_std_collections_Stack_1Tt_default_Voice_2_Iterator*self=&(*this);
  bbDBLocal("Self",self);
  bbDBLocal("current",&l_current);
  bbDBStmt(286723);
  (*this).m_AssertCurrent();
  bbDBStmt(290819);
  (*this).m__0stack->m__0data->at((*this).m__0index)=l_current;
}

t_default_Voice* t_std_collections_Stack_1Tt_default_Voice_2_Iterator::m_Current(){
  bbDBFrame db_f{"Current:default.Voice()","/Users/simon/monkey2/modules/std/collections/stack.monkey2"};
  t_std_collections_Stack_1Tt_default_Voice_2_Iterator*self=&(*this);
  bbDBLocal("Self",self);
  bbDBStmt(274435);
  (*this).m_AssertCurrent();
  bbDBStmt(278531);
  return (*this).m__0stack->m__0data->at((*this).m__0index);
}

void t_std_collections_Stack_1Tt_default_Voice_2_Iterator::m_Bump(){
  bbDBFrame db_f{"Bump:Void()","/Users/simon/monkey2/modules/std/collections/stack.monkey2"};
  t_std_collections_Stack_1Tt_default_Voice_2_Iterator*self=&(*this);
  bbDBLocal("Self",self);
  bbDBStmt(315395);
  (*this).m_AssertCurrent();
  bbDBStmt(319491);
  (*this).m__0index+=1;
}

bbBool t_std_collections_Stack_1Tt_default_Voice_2_Iterator::m_AtEnd(){
  bbDBFrame db_f{"AtEnd:Bool()","/Users/simon/monkey2/modules/std/collections/stack.monkey2"};
  t_std_collections_Stack_1Tt_default_Voice_2_Iterator*self=&(*this);
  bbDBLocal("Self",self);
  bbDBStmt(245763);
  (*this).m_AssertSeq();
  bbDBStmt(249859);
  return ((*this).m__0index==(*this).m__0stack->m__0length);
}

void t_std_collections_Stack_1Tt_default_Voice_2_Iterator::m_AssertSeq(){
  bbDBFrame db_f{"AssertSeq:Void()","/Users/simon/monkey2/modules/std/collections/stack.monkey2"};
  t_std_collections_Stack_1Tt_default_Voice_2_Iterator*self=&(*this);
  bbDBLocal("Self",self);
  bbDBStmt(172035);
  bbDebugAssert(((*this).m__0seq==(*this).m__0stack->m__0seq),BB_T("Concurrent list modification"));
}

void t_std_collections_Stack_1Tt_default_Voice_2_Iterator::m_AssertCurrent(){
  bbDBFrame db_f{"AssertCurrent:Void()","/Users/simon/monkey2/modules/std/collections/stack.monkey2"};
  t_std_collections_Stack_1Tt_default_Voice_2_Iterator*self=&(*this);
  bbDBLocal("Self",self);
  bbDBStmt(188419);
  bbDebugAssert(!(*this).m_AtEnd(),BB_T("Invalid list iterator"));
}
bbString bbDBType(t_std_collections_Stack_1Tt_default_Voice_2_Iterator*){
  return "std.collections.Stack<default.Voice>.Iterator";
}
bbString bbDBValue(t_std_collections_Stack_1Tt_default_Voice_2_Iterator*p){
  return bbDBStructValue(p);
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

void t_std_collections_Stack_1Tt_default_Voice_2_BackwardsIterator::dbEmit(t_std_collections_Stack_1Tt_default_Voice_2_BackwardsIterator*p){
  bbDBEmit("_stack",&p->m__0stack);
  bbDBEmit("_index",&p->m__0index);
  bbDBEmit("_seq",&p->m__0seq);
}

t_std_collections_Stack_1Tt_default_Voice_2_BackwardsIterator::t_std_collections_Stack_1Tt_default_Voice_2_BackwardsIterator(t_std_collections_Stack_1Tt_default_Voice_2* l_stack,bbInt l_index){
  bbDBFrame db_f{"new:Void(stack:std.collections.Stack<default.Voice>,index:Int)","/Users/simon/monkey2/modules/std/collections/stack.monkey2"};
  bbDBLocal("stack",&l_stack);
  bbDBLocal("index",&l_index);
  bbDBStmt(516099);
  (*this).m__0stack=l_stack;
  bbDBStmt(520195);
  (*this).m__0index=l_index;
  bbDBStmt(524291);
  (*this).m__0seq=l_stack->m__0seq;
}

void t_std_collections_Stack_1Tt_default_Voice_2_BackwardsIterator::m_Insert(t_default_Voice* l_value){
  bbDBFrame db_f{"Insert:Void(value:default.Voice)","/Users/simon/monkey2/modules/std/collections/stack.monkey2"};
  t_std_collections_Stack_1Tt_default_Voice_2_BackwardsIterator*self=&(*this);
  bbDBLocal("Self",self);
  bbDBLocal("value",&l_value);
  bbDBStmt(729091);
  (*this).m_AssertSeq();
  bbDBStmt(733187);
  (*this).m__0index+=1;
  bbDBStmt(737283);
  (*this).m__0stack->m_Insert((*this).m__0index,l_value);
  bbDBStmt(741379);
  (*this).m__0seq=(*this).m__0stack->m__0seq;
}

void t_std_collections_Stack_1Tt_default_Voice_2_BackwardsIterator::m_Erase(){
  bbDBFrame db_f{"Erase:Void()","/Users/simon/monkey2/modules/std/collections/stack.monkey2"};
  t_std_collections_Stack_1Tt_default_Voice_2_BackwardsIterator*self=&(*this);
  bbDBLocal("Self",self);
  bbDBStmt(679939);
  (*this).m_AssertCurrent();
  bbDBStmt(684035);
  (*this).m__0index-=1;
  bbDBStmt(688131);
  (*this).m__0stack->m_Erase(((*this).m__0index+1));
  bbDBStmt(692227);
  (*this).m__0seq=(*this).m__0stack->m__0seq;
}

void t_std_collections_Stack_1Tt_default_Voice_2_BackwardsIterator::m_Current(t_default_Voice* l_current){
  bbDBFrame db_f{"Current:Void(current:default.Voice)","/Users/simon/monkey2/modules/std/collections/stack.monkey2"};
  t_std_collections_Stack_1Tt_default_Voice_2_BackwardsIterator*self=&(*this);
  bbDBLocal("Self",self);
  bbDBLocal("current",&l_current);
  bbDBStmt(598019);
  (*this).m_AssertCurrent();
  bbDBStmt(602115);
  (*this).m__0stack->m__0data->at((*this).m__0index)=l_current;
}

t_default_Voice* t_std_collections_Stack_1Tt_default_Voice_2_BackwardsIterator::m_Current(){
  bbDBFrame db_f{"Current:default.Voice()","/Users/simon/monkey2/modules/std/collections/stack.monkey2"};
  t_std_collections_Stack_1Tt_default_Voice_2_BackwardsIterator*self=&(*this);
  bbDBLocal("Self",self);
  bbDBStmt(585731);
  (*this).m_AssertCurrent();
  bbDBStmt(589827);
  return (*this).m__0stack->m__0data->at((*this).m__0index);
}

void t_std_collections_Stack_1Tt_default_Voice_2_BackwardsIterator::m_Bump(){
  bbDBFrame db_f{"Bump:Void()","/Users/simon/monkey2/modules/std/collections/stack.monkey2"};
  t_std_collections_Stack_1Tt_default_Voice_2_BackwardsIterator*self=&(*this);
  bbDBLocal("Self",self);
  bbDBStmt(626691);
  (*this).m_AssertCurrent();
  bbDBStmt(630787);
  (*this).m__0index-=1;
}

bbBool t_std_collections_Stack_1Tt_default_Voice_2_BackwardsIterator::m_AtEnd(){
  bbDBFrame db_f{"AtEnd:Bool()","/Users/simon/monkey2/modules/std/collections/stack.monkey2"};
  t_std_collections_Stack_1Tt_default_Voice_2_BackwardsIterator*self=&(*this);
  bbDBLocal("Self",self);
  bbDBStmt(557059);
  (*this).m_AssertSeq();
  bbDBStmt(561155);
  return ((*this).m__0index==-1);
}

void t_std_collections_Stack_1Tt_default_Voice_2_BackwardsIterator::m_AssertSeq(){
  bbDBFrame db_f{"AssertSeq:Void()","/Users/simon/monkey2/modules/std/collections/stack.monkey2"};
  t_std_collections_Stack_1Tt_default_Voice_2_BackwardsIterator*self=&(*this);
  bbDBLocal("Self",self);
  bbDBStmt(483331);
  bbDebugAssert(((*this).m__0seq==(*this).m__0stack->m__0seq),BB_T("Concurrent list modification"));
}

void t_std_collections_Stack_1Tt_default_Voice_2_BackwardsIterator::m_AssertCurrent(){
  bbDBFrame db_f{"AssertCurrent:Void()","/Users/simon/monkey2/modules/std/collections/stack.monkey2"};
  t_std_collections_Stack_1Tt_default_Voice_2_BackwardsIterator*self=&(*this);
  bbDBLocal("Self",self);
  bbDBStmt(499715);
  bbDebugAssert(!(*this).m_AtEnd(),BB_T("Invalid list iterator"));
}
bbString bbDBType(t_std_collections_Stack_1Tt_default_Voice_2_BackwardsIterator*){
  return "std.collections.Stack<default.Voice>.BackwardsIterator";
}
bbString bbDBValue(t_std_collections_Stack_1Tt_default_Voice_2_BackwardsIterator*p){
  return bbDBStructValue(p);
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

void t_std_collections_Stack_1Tt_default_Voice_2::dbEmit(){
  bbDBEmit("_data",&m__0data);
  bbDBEmit("_length",&m__0length);
  bbDBEmit("_seq",&m__0seq);
}

t_std_collections_Stack_1Tt_default_Voice_2::t_std_collections_Stack_1Tt_default_Voice_2(t_std_collections_List_1Tt_default_Voice_2* l_values){
  bbDBFrame db_f{"new:Void(values:std.collections.List<default.Voice>)","/Users/simon/monkey2/modules/std/collections/stack.monkey2"};
  bbDBLocal("values",&l_values);
  bbDBStmt(942082);
  g_std_collections_Stack_1Tt_default_Voice_2_AddAll_1Tt_std_collections_List_1Tt_default_Voice_2_2(this,l_values);
}

t_std_collections_Stack_1Tt_default_Voice_2::t_std_collections_Stack_1Tt_default_Voice_2(t_std_collections_Stack_1Tt_default_Voice_2* l_values){
  struct f0_t : public bbGCFrame{
    bbArray<bbGCVar<t_default_Voice>>* t0{};
    void gcMark(){
      bbGCMarkPtr(t0);
    }
  }f0{};
  bbDBFrame db_f{"new:Void(values:std.collections.Stack<default.Voice>)","/Users/simon/monkey2/modules/std/collections/stack.monkey2"};
  bbDBLocal("values",&l_values);
  bbDBStmt(917506);
  this->m__0length=l_values->m_Length();
  bbDBStmt(921602);
  this->m__0data=bbArray<bbGCVar<t_default_Voice>>::create(this->m__0length);
  bbDBStmt(925698);
  (f0.t0=l_values->m_Data())->copyTo(this->m__0data,bbInt(0),bbInt(0),this->m__0length);
}

t_std_collections_Stack_1Tt_default_Voice_2::t_std_collections_Stack_1Tt_default_Voice_2(bbArray<bbGCVar<t_default_Voice>>* l_values){
  bbDBFrame db_f{"new:Void(values:default.Voice[])","/Users/simon/monkey2/modules/std/collections/stack.monkey2"};
  bbDBLocal("values",&l_values);
  bbDBStmt(901122);
  this->m_AddAll(l_values);
}

t_std_collections_Stack_1Tt_default_Voice_2::t_std_collections_Stack_1Tt_default_Voice_2(bbInt l_length){
  bbDBFrame db_f{"new:Void(length:Int)","/Users/simon/monkey2/modules/std/collections/stack.monkey2"};
  bbDBLocal("length",&l_length);
  bbDBStmt(880642);
  this->m__0length=l_length;
  bbDBStmt(884738);
  this->m__0data=bbArray<bbGCVar<t_default_Voice>>::create(this->m__0length);
}

t_std_collections_Stack_1Tt_default_Voice_2::t_std_collections_Stack_1Tt_default_Voice_2(){
  bbDBFrame db_f{"new:Void()","/Users/simon/monkey2/modules/std/collections/stack.monkey2"};
  bbDBStmt(864258);
  this->m__0data=bbArray<bbGCVar<t_default_Voice>>::create(10);
}

void t_std_collections_Stack_1Tt_default_Voice_2::m__idxeq(bbInt l_index,t_default_Voice* l_value){
  bbDBFrame db_f{"[]=:Void(index:Int,value:default.Voice)","/Users/simon/monkey2/modules/std/collections/stack.monkey2"};
  t_std_collections_Stack_1Tt_default_Voice_2*self=this;
  bbDBLocal("Self",&self);
  bbDBLocal("index",&l_index);
  bbDBLocal("value",&l_value);
  bbDBStmt(1912834);
  bbDebugAssert(((l_index>=bbInt(0))&&(l_index<this->m__0length)),BB_T("Stack index out of range"));
  bbDBStmt(1921026);
  this->m__0data->at(l_index)=l_value;
}

t_default_Voice* t_std_collections_Stack_1Tt_default_Voice_2::m__idx(bbInt l_index){
  bbDBFrame db_f{"[]:default.Voice(index:Int)","/Users/simon/monkey2/modules/std/collections/stack.monkey2"};
  t_std_collections_Stack_1Tt_default_Voice_2*self=this;
  bbDBLocal("Self",&self);
  bbDBLocal("index",&l_index);
  bbDBStmt(1851394);
  bbDebugAssert(((l_index>=bbInt(0))&&(l_index<this->m__0length)),BB_T("Stack index out of range"));
  bbDBStmt(1859586);
  return this->m__0data->at(l_index);
}

t_default_Voice* t_std_collections_Stack_1Tt_default_Voice_2::m_Top(){
  bbDBFrame db_f{"Top:default.Voice()","/Users/simon/monkey2/modules/std/collections/stack.monkey2"};
  t_std_collections_Stack_1Tt_default_Voice_2*self=this;
  bbDBLocal("Self",&self);
  bbDBStmt(3141634);
  bbDebugAssert(bbBool(this->m__0length),BB_T("Stack is empty"));
  bbDBStmt(3149826);
  return this->m__0data->at((this->m__0length-1));
}

bbArray<bbGCVar<t_default_Voice>>* t_std_collections_Stack_1Tt_default_Voice_2::m_ToArray(){
  bbDBFrame db_f{"ToArray:default.Voice[]()","/Users/simon/monkey2/modules/std/collections/stack.monkey2"};
  t_std_collections_Stack_1Tt_default_Voice_2*self=this;
  bbDBLocal("Self",&self);
  bbDBStmt(1105922);
  return this->m__0data->slice(bbInt(0),this->m__0length);
}

void t_std_collections_Stack_1Tt_default_Voice_2::m_Swap(bbInt l_index1,bbInt l_index2){
  struct f0_t : public bbGCFrame{
    t_default_Voice* l_t{};
    void gcMark(){
      bbGCMarkPtr(l_t);
    }
  }f0{};
  bbDBFrame db_f{"Swap:Void(index1:Int,index2:Int)","/Users/simon/monkey2/modules/std/collections/stack.monkey2"};
  t_std_collections_Stack_1Tt_default_Voice_2*self=this;
  bbDBLocal("Self",&self);
  bbDBLocal("index1",&l_index1);
  bbDBLocal("index2",&l_index2);
  bbDBStmt(2801666);
  bbDebugAssert(((((l_index1>=bbInt(0))&&(l_index1<this->m__0length))&&(l_index2>=bbInt(0)))&&(l_index2<this->m__0length)),BB_T("Stack index out of range"));
  bbDBStmt(2809864);
  f0.l_t=this->m__0data->at(l_index1);
  bbDBLocal("t",&f0.l_t);
  bbDBStmt(2813954);
  this->m__0data->at(l_index1)=this->m__0data->at(l_index2);
  bbDBStmt(2818050);
  this->m__0data->at(l_index2)=f0.l_t;
}

void t_std_collections_Stack_1Tt_default_Voice_2::m_Sort(bbFunction<bbInt(t_default_Voice*,t_default_Voice*)> l_compareFunc,bbInt l_lo,bbInt l_hi){
  bbDBFrame db_f{"Sort:Void(compareFunc:Int(default.Voice,default.Voice),lo:Int,hi:Int)","/Users/simon/monkey2/modules/std/collections/stack.monkey2"};
  t_std_collections_Stack_1Tt_default_Voice_2*self=this;
  bbDBLocal("Self",&self);
  bbDBLocal("compareFunc",&l_compareFunc);
  bbDBLocal("lo",&l_lo);
  bbDBLocal("hi",&l_hi);
  bbDBStmt(2949122);
  if((l_hi<=l_lo)){
    bbDBBlock db_blk;
    bbDBStmt(2949132);
    return;
  }
  bbDBStmt(2957314);
  if(((l_lo+1)==l_hi)){
    bbDBBlock db_blk;
    bbDBStmt(2961411);
    if((l_compareFunc(this->m__0data->at(l_hi),this->m__0data->at(l_lo))<bbInt(0))){
      bbDBBlock db_blk;
      bbDBStmt(2961451);
      this->m_Swap(l_hi,l_lo);
    }
    bbDBStmt(2965507);
    return;
  }
  bbDBStmt(2977800);
  bbInt l_i=((l_lo+l_hi)/2);
  bbDBLocal("i",&l_i);
  bbDBStmt(2985986);
  if((l_compareFunc(this->m__0data->at(l_i),this->m__0data->at(l_lo))<bbInt(0))){
    bbDBBlock db_blk;
    bbDBStmt(2986025);
    this->m_Swap(l_i,l_lo);
  }
  bbDBStmt(2994178);
  if((l_compareFunc(this->m__0data->at(l_hi),this->m__0data->at(l_i))<bbInt(0))){
    bbDBBlock db_blk;
    bbDBStmt(2998275);
    this->m_Swap(l_hi,l_i);
    bbDBStmt(3002371);
    if((l_compareFunc(this->m__0data->at(l_i),this->m__0data->at(l_lo))<bbInt(0))){
      bbDBBlock db_blk;
      bbDBStmt(3002410);
      this->m_Swap(l_i,l_lo);
    }
  }
  bbDBStmt(3014664);
  bbInt l_x=(l_lo+1);
  bbDBLocal("x",&l_x);
  bbDBStmt(3018760);
  bbInt l_y=(l_hi-1);
  bbDBLocal("y",&l_y);
  bbDBStmt(3022850);
  {
    bbDBLoop db_loop;
    do{
      struct f1_t : public bbGCFrame{
        t_default_Voice* l_p{};
        void gcMark(){
          bbGCMarkPtr(l_p);
        }
      }f1{};
      bbDBBlock db_blk;
      bbDBStmt(3026953);
      f1.l_p=this->m__0data->at(l_i);
      bbDBLocal("p",&f1.l_p);
      bbDBStmt(3031043);
      {
        bbDBLoop db_loop;
        while((l_compareFunc(this->m__0data->at(l_x),f1.l_p)<bbInt(0))){
          bbDBBlock db_blk;
          bbDBStmt(3035140);
          l_x+=1;
        }
      }
      bbDBStmt(3043331);
      {
        bbDBLoop db_loop;
        while((l_compareFunc(f1.l_p,this->m__0data->at(l_y))<bbInt(0))){
          bbDBBlock db_blk;
          bbDBStmt(3047428);
          l_y-=1;
        }
      }
      bbDBStmt(3055619);
      if((l_x>l_y)){
        bbDBBlock db_blk;
        bbDBStmt(3055626);
        break;
      }
      bbDBStmt(3059715);
      if((l_x<l_y)){
        bbDBBlock db_blk;
        bbDBStmt(3063812);
        this->m_Swap(l_x,l_y);
        bbDBStmt(3067908);
        if((l_i==l_x)){
          bbDBBlock db_blk;
          bbDBStmt(3067915);
          l_i=l_y;
        }else if(bbDBStmt(3067919),(l_i==l_y)){
          bbDBBlock db_blk;
          bbDBStmt(3067931);
          l_i=l_x;
        }
      }
      bbDBStmt(3076099);
      l_x+=1;
      bbDBStmt(3080195);
      l_y-=1;
    }while(!((l_x>l_y)));
  }
  bbDBStmt(3092482);
  this->m_Sort(l_compareFunc,l_lo,l_y);
  bbDBStmt(3096578);
  this->m_Sort(l_compareFunc,l_x,l_hi);
}

void t_std_collections_Stack_1Tt_default_Voice_2::m_Sort(bbFunction<bbInt(t_default_Voice*,t_default_Voice*)> l_compareFunc){
  bbDBFrame db_f{"Sort:Void(compareFunc:Int(default.Voice,default.Voice))","/Users/simon/monkey2/modules/std/collections/stack.monkey2"};
  t_std_collections_Stack_1Tt_default_Voice_2*self=this;
  bbDBLocal("Self",&self);
  bbDBLocal("compareFunc",&l_compareFunc);
  bbDBStmt(2928642);
  this->m_Sort(l_compareFunc,bbInt(0),(this->m__0length-1));
}

void t_std_collections_Stack_1Tt_default_Voice_2::m_Sort(bbBool l_ascending){
  bbDBFrame db_f{"Sort:Void(ascending:Bool)","/Users/simon/monkey2/modules/std/collections/stack.monkey2"};
  t_std_collections_Stack_1Tt_default_Voice_2*self=this;
  bbDBLocal("Self",&self);
  bbDBLocal("ascending",&l_ascending);
  bbDBStmt(2879490);
  if(l_ascending){
    bbDBBlock db_blk;
    bbDBStmt(2883587);
    struct lambda0 : public bbFunction<bbInt(t_default_Voice*,t_default_Voice*)>::Rep{
      t_std_collections_Stack_1Tt_default_Voice_2* l_self;
      lambda0(t_std_collections_Stack_1Tt_default_Voice_2* l_self):l_self(l_self){
      }
      bbInt invoke(t_default_Voice* l_x,t_default_Voice* l_y){
        bbDBFrame db_f{"?????:Int(x:default.Voice,y:default.Voice)","/Users/simon/monkey2/modules/std/collections/stack.monkey2"};
        bbDBLocal("x",&l_x);
        bbDBLocal("y",&l_y);
        bbDBStmt(2887684);
        return bbCompare(l_x,l_y);
      }
      void gcMark(){
        bbGCMarkPtr(l_self);
      }
    };
    this->m_Sort(bbFunction<bbInt(t_default_Voice*,t_default_Voice*)>(new lambda0(this)));
  }else{
    bbDBStmt(2895874);
    bbDBBlock db_blk;
    bbDBStmt(2899971);
    struct lambda1 : public bbFunction<bbInt(t_default_Voice*,t_default_Voice*)>::Rep{
      t_std_collections_Stack_1Tt_default_Voice_2* l_self;
      lambda1(t_std_collections_Stack_1Tt_default_Voice_2* l_self):l_self(l_self){
      }
      bbInt invoke(t_default_Voice* l_x,t_default_Voice* l_y){
        bbDBFrame db_f{"?????:Int(x:default.Voice,y:default.Voice)","/Users/simon/monkey2/modules/std/collections/stack.monkey2"};
        bbDBLocal("x",&l_x);
        bbDBLocal("y",&l_y);
        bbDBStmt(2904068);
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
  bbDBFrame db_f{"Slice:std.collections.Stack<default.Voice>(index1:Int,index2:Int)","/Users/simon/monkey2/modules/std/collections/stack.monkey2"};
  t_std_collections_Stack_1Tt_default_Voice_2*self=this;
  bbDBLocal("Self",&self);
  bbDBLocal("index1",&l_index1);
  bbDBLocal("index2",&l_index2);
  bbDBStmt(2691074);
  if((l_index1<bbInt(0))){
    bbDBBlock db_blk;
    bbDBStmt(2695171);
    l_index1=g_monkey_math_Max_1i((l_index1+this->m__0length),bbInt(0));
  }else if(bbDBStmt(2699266),(l_index1>this->m__0length)){
    bbDBBlock db_blk;
    bbDBStmt(2703363);
    l_index1=this->m__0length;
  }
  bbDBStmt(2715650);
  if((l_index2<bbInt(0))){
    bbDBBlock db_blk;
    bbDBStmt(2719747);
    l_index2=g_monkey_math_Max_1i((l_index2+this->m__0length),l_index1);
  }else if(bbDBStmt(2723842),(l_index2>this->m__0length)){
    bbDBBlock db_blk;
    bbDBStmt(2727939);
    l_index2=this->m__0length;
  }else if(bbDBStmt(2732034),(l_index2<l_index1)){
    bbDBBlock db_blk;
    bbDBStmt(2736131);
    l_index2=l_index1;
  }
  bbDBStmt(2748418);
  return bbGCNew<t_std_collections_Stack_1Tt_default_Voice_2>(f0.t0=this->m__0data->slice(l_index1,l_index2));
}

t_std_collections_Stack_1Tt_default_Voice_2* t_std_collections_Stack_1Tt_default_Voice_2::m_Slice(bbInt l_index){
  bbDBFrame db_f{"Slice:std.collections.Stack<default.Voice>(index:Int)","/Users/simon/monkey2/modules/std/collections/stack.monkey2"};
  t_std_collections_Stack_1Tt_default_Voice_2*self=this;
  bbDBLocal("Self",&self);
  bbDBLocal("index",&l_index);
  bbDBStmt(2609154);
  return this->m_Slice(l_index,this->m__0length);
}

void t_std_collections_Stack_1Tt_default_Voice_2::m_Set(bbInt l_index,t_default_Voice* l_value){
  bbDBFrame db_f{"Set:Void(index:Int,value:default.Voice)","/Users/simon/monkey2/modules/std/collections/stack.monkey2"};
  t_std_collections_Stack_1Tt_default_Voice_2*self=this;
  bbDBLocal("Self",&self);
  bbDBLocal("index",&l_index);
  bbDBLocal("value",&l_value);
  bbDBStmt(1798146);
  bbDebugAssert(((l_index>=bbInt(0))&&(l_index<this->m__0length)),BB_T("Stack index out of range"));
  bbDBStmt(1806338);
  this->m__0data->at(l_index)=l_value;
}

void t_std_collections_Stack_1Tt_default_Voice_2::m_Resize(bbInt l_length){
  bbDBFrame db_f{"Resize:Void(length:Int)","/Users/simon/monkey2/modules/std/collections/stack.monkey2"};
  t_std_collections_Stack_1Tt_default_Voice_2*self=this;
  bbDBLocal("Self",&self);
  bbDBLocal("length",&l_length);
  bbDBStmt(1306626);
  bbDebugAssert((l_length>=bbInt(0)),BB_T("Debug assert failed"));
  bbDBStmt(1314818);
  {
    bbDBLoop db_loop;
    bbInt l_i=l_length;
    bbDBLocal("i",&l_i);
    bbDBStmt(1314818);
    for(;(l_i<this->m__0length);l_i+=1){
      bbDBBlock db_blk;
      bbDBStmt(1318915);
      this->m__0data->at(l_i)=((t_default_Voice*)0);
    }
  }
  bbDBStmt(1331202);
  this->m_Reserve(l_length);
  bbDBStmt(1335298);
  this->m__0length=l_length;
  bbDBStmt(1339394);
  this->m__0seq+=1;
}

void t_std_collections_Stack_1Tt_default_Voice_2::m_Reserve(bbInt l_capacity){
  struct f0_t : public bbGCFrame{
    bbArray<bbGCVar<t_default_Voice>>* l_data{};
    void gcMark(){
      bbGCMarkPtr(l_data);
    }
  }f0{};
  bbDBFrame db_f{"Reserve:Void(capacity:Int)","/Users/simon/monkey2/modules/std/collections/stack.monkey2"};
  t_std_collections_Stack_1Tt_default_Voice_2*self=this;
  bbDBLocal("Self",&self);
  bbDBLocal("capacity",&l_capacity);
  bbDBStmt(1404930);
  bbDebugAssert((l_capacity>=bbInt(0)),BB_T("Debug assert failed"));
  bbDBStmt(1413122);
  if((this->m__0data->length()>=l_capacity)){
    bbDBBlock db_blk;
    bbDBStmt(1413148);
    return;
  }
  bbDBStmt(1421314);
  l_capacity=g_monkey_math_Max_1i(((this->m__0length*2)+this->m__0length),l_capacity);
  bbDBStmt(1425416);
  f0.l_data=bbArray<bbGCVar<t_default_Voice>>::create(l_capacity);
  bbDBLocal("data",&f0.l_data);
  bbDBStmt(1429506);
  this->m__0data->copyTo(f0.l_data,bbInt(0),bbInt(0),this->m__0length);
  bbDBStmt(1433602);
  this->m__0data=f0.l_data;
}

bbBool t_std_collections_Stack_1Tt_default_Voice_2::m_RemoveLast(t_default_Voice* l_value,bbInt l_start){
  bbDBFrame db_f{"RemoveLast:Bool(value:default.Voice,start:Int)","/Users/simon/monkey2/modules/std/collections/stack.monkey2"};
  t_std_collections_Stack_1Tt_default_Voice_2*self=this;
  bbDBLocal("Self",&self);
  bbDBLocal("value",&l_value);
  bbDBLocal("start",&l_start);
  bbDBStmt(2441224);
  bbInt l_i=this->m_FindLastIndex(l_value,l_start);
  bbDBLocal("i",&l_i);
  bbDBStmt(2445314);
  if((l_i==-1)){
    bbDBBlock db_blk;
    bbDBStmt(2445322);
    return false;
  }
  bbDBStmt(2449410);
  this->m_Erase(l_i);
  bbDBStmt(2453506);
  return true;
}

bbInt t_std_collections_Stack_1Tt_default_Voice_2::m_RemoveEach(t_default_Voice* l_value){
  bbDBFrame db_f{"RemoveEach:Int(value:default.Voice)","/Users/simon/monkey2/modules/std/collections/stack.monkey2"};
  t_std_collections_Stack_1Tt_default_Voice_2*self=this;
  bbDBLocal("Self",&self);
  bbDBLocal("value",&l_value);
  bbDBStmt(2498568);
  bbInt l_put=bbInt(0);
  bbDBLocal("put",&l_put);
  bbDBStmt(2498575);
  bbInt l_n=bbInt(0);
  bbDBLocal("n",&l_n);
  bbDBStmt(2502658);
  {
    bbDBLoop db_loop;
    bbInt l_get=bbInt(0);
    bbDBLocal("get",&l_get);
    bbDBStmt(2502658);
    for(;(l_get<this->m__0length);l_get+=1){
      bbDBBlock db_blk;
      bbDBStmt(2506755);
      if((this->m__0data->at(l_get)==l_value)){
        bbDBBlock db_blk;
        bbDBStmt(2510852);
        l_n+=1;
        bbDBStmt(2514948);
        continue;
      }
      bbDBStmt(2523139);
      this->m__0data->at(l_put)=this->m__0data->at(l_get);
      bbDBStmt(2527235);
      l_put+=1;
    }
  }
  bbDBStmt(2535426);
  this->m_Resize(l_put);
  bbDBStmt(2539522);
  return l_n;
}

bbBool t_std_collections_Stack_1Tt_default_Voice_2::m_Remove(t_default_Voice* l_value,bbInt l_start){
  bbDBFrame db_f{"Remove:Bool(value:default.Voice,start:Int)","/Users/simon/monkey2/modules/std/collections/stack.monkey2"};
  t_std_collections_Stack_1Tt_default_Voice_2*self=this;
  bbDBLocal("Self",&self);
  bbDBLocal("value",&l_value);
  bbDBLocal("start",&l_start);
  bbDBStmt(2375688);
  bbInt l_i=this->m_FindIndex(l_value,l_start);
  bbDBLocal("i",&l_i);
  bbDBStmt(2379778);
  if((l_i==-1)){
    bbDBBlock db_blk;
    bbDBStmt(2379786);
    return false;
  }
  bbDBStmt(2383874);
  this->m_Erase(l_i);
  bbDBStmt(2387970);
  return true;
}

void t_std_collections_Stack_1Tt_default_Voice_2::m_Push(t_default_Voice* l_value){
  bbDBFrame db_f{"Push:Void(value:default.Voice)","/Users/simon/monkey2/modules/std/collections/stack.monkey2"};
  t_std_collections_Stack_1Tt_default_Voice_2*self=this;
  bbDBLocal("Self",&self);
  bbDBLocal("value",&l_value);
  bbDBStmt(3260418);
  this->m_Add(l_value);
}

t_default_Voice* t_std_collections_Stack_1Tt_default_Voice_2::m_Pop(){
  struct f0_t : public bbGCFrame{
    t_default_Voice* l_value{};
    void gcMark(){
      bbGCMarkPtr(l_value);
    }
  }f0{};
  bbDBFrame db_f{"Pop:default.Voice()","/Users/simon/monkey2/modules/std/collections/stack.monkey2"};
  t_std_collections_Stack_1Tt_default_Voice_2*self=this;
  bbDBLocal("Self",&self);
  bbDBStmt(3190786);
  bbDebugAssert(bbBool(this->m__0length),BB_T("Stack is empty"));
  bbDBStmt(3198978);
  this->m__0length-=1;
  bbDBStmt(3203074);
  this->m__0seq+=1;
  bbDBStmt(3207176);
  f0.l_value=this->m__0data->at(this->m__0length);
  bbDBLocal("value",&f0.l_value);
  bbDBStmt(3211266);
  this->m__0data->at(this->m__0length)=((t_default_Voice*)0);
  bbDBStmt(3215362);
  return f0.l_value;
}

bbInt t_std_collections_Stack_1Tt_default_Voice_2::m_Length(){
  bbDBFrame db_f{"Length:Int()","/Users/simon/monkey2/modules/std/collections/stack.monkey2"};
  t_std_collections_Stack_1Tt_default_Voice_2*self=this;
  bbDBLocal("Self",&self);
  bbDBStmt(1187842);
  return this->m__0length;
}

void t_std_collections_Stack_1Tt_default_Voice_2::m_Insert(bbInt l_index,t_default_Voice* l_value){
  bbDBFrame db_f{"Insert:Void(index:Int,value:default.Voice)","/Users/simon/monkey2/modules/std/collections/stack.monkey2"};
  t_std_collections_Stack_1Tt_default_Voice_2*self=this;
  bbDBLocal("Self",&self);
  bbDBLocal("index",&l_index);
  bbDBLocal("value",&l_value);
  bbDBStmt(1667074);
  bbDebugAssert(((l_index>=bbInt(0))&&(l_index<=this->m__0length)),BB_T("Debug assert failed"));
  bbDBStmt(1675266);
  this->m_Reserve((this->m__0length+1));
  bbDBStmt(1679362);
  this->m__0data->copyTo(this->m__0data,l_index,(l_index+1),(this->m__0length-l_index));
  bbDBStmt(1683458);
  this->m__0data->at(l_index)=l_value;
  bbDBStmt(1687554);
  this->m__0length+=1;
  bbDBStmt(1691650);
  this->m__0seq+=1;
}

t_default_Voice* t_std_collections_Stack_1Tt_default_Voice_2::m_Get(bbInt l_index){
  bbDBFrame db_f{"Get:default.Voice(index:Int)","/Users/simon/monkey2/modules/std/collections/stack.monkey2"};
  t_std_collections_Stack_1Tt_default_Voice_2*self=this;
  bbDBLocal("Self",&self);
  bbDBLocal("index",&l_index);
  bbDBStmt(1736706);
  bbDebugAssert(((l_index>=bbInt(0))&&(l_index<this->m__0length)),BB_T("Stack index out of range"));
  bbDBStmt(1744898);
  return this->m__0data->at(l_index);
}

bbInt t_std_collections_Stack_1Tt_default_Voice_2::m_FindLastIndex(t_default_Voice* l_value,bbInt l_start){
  bbDBFrame db_f{"FindLastIndex:Int(value:default.Voice,start:Int)","/Users/simon/monkey2/modules/std/collections/stack.monkey2"};
  t_std_collections_Stack_1Tt_default_Voice_2*self=this;
  bbDBLocal("Self",&self);
  bbDBLocal("value",&l_value);
  bbDBLocal("start",&l_start);
  bbDBStmt(2248706);
  bbDebugAssert(((l_start>=bbInt(0))&&(l_start<=this->m__0length)),BB_T("Debug assert failed"));
  bbDBStmt(2256904);
  bbInt l_i=this->m__0length;
  bbDBLocal("i",&l_i);
  bbDBStmt(2260994);
  {
    bbDBLoop db_loop;
    while((l_i>l_start)){
      bbDBBlock db_blk;
      bbDBStmt(2265091);
      l_i-=1;
      bbDBStmt(2269187);
      if((this->m__0data->at(l_i)==l_value)){
        bbDBBlock db_blk;
        bbDBStmt(2269205);
        return l_i;
      }
    }
  }
  bbDBStmt(2277378);
  return -1;
}

bbInt t_std_collections_Stack_1Tt_default_Voice_2::m_FindIndex(t_default_Voice* l_value,bbInt l_start){
  bbDBFrame db_f{"FindIndex:Int(value:default.Voice,start:Int)","/Users/simon/monkey2/modules/std/collections/stack.monkey2"};
  t_std_collections_Stack_1Tt_default_Voice_2*self=this;
  bbDBLocal("Self",&self);
  bbDBLocal("value",&l_value);
  bbDBLocal("start",&l_start);
  bbDBStmt(2158594);
  bbDebugAssert(((l_start>=bbInt(0))&&(l_start<=this->m__0length)),BB_T("Debug assert failed"));
  bbDBStmt(2166792);
  bbInt l_i=l_start;
  bbDBLocal("i",&l_i);
  bbDBStmt(2170882);
  {
    bbDBLoop db_loop;
    while((l_i<this->m__0length)){
      bbDBBlock db_blk;
      bbDBStmt(2174979);
      if((this->m__0data->at(l_i)==l_value)){
        bbDBBlock db_blk;
        bbDBStmt(2174997);
        return l_i;
      }
      bbDBStmt(2179075);
      l_i+=1;
    }
  }
  bbDBStmt(2187266);
  return -1;
}

void t_std_collections_Stack_1Tt_default_Voice_2::m_Erase(bbInt l_index1,bbInt l_index2){
  bbDBFrame db_f{"Erase:Void(index1:Int,index2:Int)","/Users/simon/monkey2/modules/std/collections/stack.monkey2"};
  t_std_collections_Stack_1Tt_default_Voice_2*self=this;
  bbDBLocal("Self",&self);
  bbDBLocal("index1",&l_index1);
  bbDBLocal("index2",&l_index2);
  bbDBStmt(1589250);
  bbDebugAssert((((((l_index1>=bbInt(0))&&(l_index1<=this->m__0length))&&(l_index2>=bbInt(0)))&&(l_index2<=this->m__0length))&&(l_index1<=l_index2)),BB_T("Debug assert failed"));
  bbDBStmt(1597442);
  if((l_index1==this->m__0length)){
    bbDBBlock db_blk;
    bbDBStmt(1597460);
    return;
  }
  bbDBStmt(1601538);
  this->m__0data->copyTo(this->m__0data,l_index2,l_index1,(this->m__0length-l_index2));
  bbDBStmt(1605634);
  this->m_Resize(((this->m__0length-l_index2)+l_index1));
}

void t_std_collections_Stack_1Tt_default_Voice_2::m_Erase(bbInt l_index){
  bbDBFrame db_f{"Erase:Void(index:Int)","/Users/simon/monkey2/modules/std/collections/stack.monkey2"};
  t_std_collections_Stack_1Tt_default_Voice_2*self=this;
  bbDBLocal("Self",&self);
  bbDBLocal("index",&l_index);
  bbDBStmt(1511426);
  bbDebugAssert(((l_index>=bbInt(0))&&(l_index<=this->m__0length)),BB_T("Debug assert failed"));
  bbDBStmt(1515522);
  if((l_index==this->m__0length)){
    bbDBBlock db_blk;
    bbDBStmt(1515539);
    return;
  }
  bbDBStmt(1523714);
  this->m__0data->copyTo(this->m__0data,(l_index+1),l_index,((this->m__0length-l_index)-1));
  bbDBStmt(1527810);
  this->m_Resize((this->m__0length-1));
}

bbBool t_std_collections_Stack_1Tt_default_Voice_2::m_Empty(){
  bbDBFrame db_f{"Empty:Bool()","/Users/simon/monkey2/modules/std/collections/stack.monkey2"};
  t_std_collections_Stack_1Tt_default_Voice_2*self=this;
  bbDBLocal("Self",&self);
  bbDBStmt(978946);
  return (this->m__0length==bbInt(0));
}

bbArray<bbGCVar<t_default_Voice>>* t_std_collections_Stack_1Tt_default_Voice_2::m_Data(){
  bbDBFrame db_f{"Data:default.Voice[]()","/Users/simon/monkey2/modules/std/collections/stack.monkey2"};
  t_std_collections_Stack_1Tt_default_Voice_2*self=this;
  bbDBLocal("Self",&self);
  bbDBStmt(1150978);
  return this->m__0data;
}

bbBool t_std_collections_Stack_1Tt_default_Voice_2::m_Contains(t_default_Voice* l_value){
  bbDBFrame db_f{"Contains:Bool(value:default.Voice)","/Users/simon/monkey2/modules/std/collections/stack.monkey2"};
  t_std_collections_Stack_1Tt_default_Voice_2*self=this;
  bbDBLocal("Self",&self);
  bbDBLocal("value",&l_value);
  bbDBStmt(2322434);
  return (this->m_FindIndex(l_value,bbInt(0))!=-1);
}

void t_std_collections_Stack_1Tt_default_Voice_2::m_Clear(){
  bbDBFrame db_f{"Clear:Void()","/Users/simon/monkey2/modules/std/collections/stack.monkey2"};
  t_std_collections_Stack_1Tt_default_Voice_2*self=this;
  bbDBLocal("Self",&self);
  bbDBStmt(1458178);
  this->m_Resize(bbInt(0));
}

bbInt t_std_collections_Stack_1Tt_default_Voice_2::m_Capacity(){
  bbDBFrame db_f{"Capacity:Int()","/Users/simon/monkey2/modules/std/collections/stack.monkey2"};
  t_std_collections_Stack_1Tt_default_Voice_2*self=this;
  bbDBLocal("Self",&self);
  bbDBStmt(1253378);
  return this->m__0data->length();
}

t_std_collections_Stack_1Tt_default_Voice_2_BackwardsIterator t_std_collections_Stack_1Tt_default_Voice_2::m_Backwards(){
  bbDBFrame db_f{"Backwards:std.collections.Stack<default.Voice>.BackwardsIterator()","/Users/simon/monkey2/modules/std/collections/stack.monkey2"};
  t_std_collections_Stack_1Tt_default_Voice_2*self=this;
  bbDBLocal("Self",&self);
  bbDBStmt(1069058);
  return t_std_collections_Stack_1Tt_default_Voice_2_BackwardsIterator(this,(this->m__0length-1));
}

t_std_collections_Stack_1Tt_default_Voice_2_Iterator t_std_collections_Stack_1Tt_default_Voice_2::m_All(){
  bbDBFrame db_f{"All:std.collections.Stack<default.Voice>.Iterator()","/Users/simon/monkey2/modules/std/collections/stack.monkey2"};
  t_std_collections_Stack_1Tt_default_Voice_2*self=this;
  bbDBLocal("Self",&self);
  bbDBStmt(1024002);
  return t_std_collections_Stack_1Tt_default_Voice_2_Iterator(this,bbInt(0));
}

void t_std_collections_Stack_1Tt_default_Voice_2::m_AddAll(bbArray<bbGCVar<t_default_Voice>>* l_values){
  bbDBFrame db_f{"AddAll:Void(values:default.Voice[])","/Users/simon/monkey2/modules/std/collections/stack.monkey2"};
  t_std_collections_Stack_1Tt_default_Voice_2*self=this;
  bbDBLocal("Self",&self);
  bbDBLocal("values",&l_values);
  bbDBStmt(2015234);
  this->m_Reserve((this->m__0length+l_values->length()));
  bbDBStmt(2019330);
  l_values->copyTo(this->m__0data,bbInt(0),this->m__0length,l_values->length());
  bbDBStmt(2023426);
  this->m_Resize((this->m__0length+l_values->length()));
}

void t_std_collections_Stack_1Tt_default_Voice_2::m_Add(t_default_Voice* l_value){
  bbDBFrame db_f{"Add:Void(value:default.Voice)","/Users/simon/monkey2/modules/std/collections/stack.monkey2"};
  t_std_collections_Stack_1Tt_default_Voice_2*self=this;
  bbDBLocal("Self",&self);
  bbDBLocal("value",&l_value);
  bbDBStmt(1966082);
  this->m_Reserve((this->m__0length+1));
  bbDBStmt(1970178);
  this->m__0data->at(this->m__0length)=l_value;
  bbDBStmt(1974274);
  this->m__0length+=1;
  bbDBStmt(1978370);
  this->m__0seq+=1;
}
bbString bbDBType(t_std_collections_Stack_1Tt_default_Voice_2**){
  return "std.collections.Stack<default.Voice>";
}
bbString bbDBValue(t_std_collections_Stack_1Tt_default_Voice_2**p){
  return bbDBObjectValue(*p);
}

void mx2_vsynth_std_collections_2stack_init(){
  static bool done;
  if(done) return;
  done=true;
}

bbInit mx2_vsynth_std_collections_2stack_init_v("vsynth_std_collections_2stack",&mx2_vsynth_std_collections_2stack_init);
