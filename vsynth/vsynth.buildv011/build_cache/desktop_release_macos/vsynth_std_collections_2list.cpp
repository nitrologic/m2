
#include "vsynth_std_collections_2list.h"

// ***** External *****

#include "../../../../../../monkey2/modules/monkey/monkey.buildv011/desktop_release_macos/monkey_debug.h"
#include "vsynth_std_collections_2stack.h"
#include "vsynth_vsynth.h"

// ***** Internal *****

void g_std_collections_List_1Tt_default_Voice_2_AddAll_1Tt_std_collections_List_1Tt_default_Voice_2_2(t_std_collections_List_1Tt_default_Voice_2* l_self,t_std_collections_List_1Tt_default_Voice_2* l_values){
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
      l_self->m_AddLast(f2.l_value);
    }
  }
}

void g_std_collections_List_1Tt_default_Voice_2_AddAll_1Tt_std_collections_Stack_1Tt_default_Voice_2_2(t_std_collections_List_1Tt_default_Voice_2* l_self,t_std_collections_Stack_1Tt_default_Voice_2* l_values){
  {
    struct f1_t : public bbGCFrame{
      t_std_collections_Stack_1Tt_default_Voice_2_Iterator l_0{};
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
      l_self->m_AddLast(f2.l_value);
    }
  }
}

void t_std_collections_List_1Tt_default_Voice_2_Node::gcMark(){
  bbGCMark(m__0succ);
  bbGCMark(m__0pred);
  bbGCMark(m__0value);
}

t_std_collections_List_1Tt_default_Voice_2_Node::t_std_collections_List_1Tt_default_Voice_2_Node(t_default_Voice* l_value,t_std_collections_List_1Tt_default_Voice_2_Node* l_succ){
  this->m__0value=l_value;
  this->m__0succ=l_succ;
  this->m__0pred=l_succ->m__0pred;
  this->m__0pred->m__0succ=this;
  l_succ->m__0pred=this;
}

t_std_collections_List_1Tt_default_Voice_2_Node::t_std_collections_List_1Tt_default_Voice_2_Node(t_default_Voice* l_value){
  this->m__0value=l_value;
  this->m__0succ=this;
  this->m__0pred=this;
}

void t_std_collections_List_1Tt_default_Voice_2_Node::m_Value(t_default_Voice* l_value){
  this->m__0value=l_value;
}

t_default_Voice* t_std_collections_List_1Tt_default_Voice_2_Node::m_Value(){
  return this->m__0value;
}

t_std_collections_List_1Tt_default_Voice_2_Node* t_std_collections_List_1Tt_default_Voice_2_Node::m_Succ(){
  return this->m__0succ;
}

void t_std_collections_List_1Tt_default_Voice_2_Node::m_Remove(){
  this->m__0succ->m__0pred=this->m__0pred;
  this->m__0pred->m__0succ=this->m__0succ;
}

t_std_collections_List_1Tt_default_Voice_2_Node* t_std_collections_List_1Tt_default_Voice_2_Node::m_Pred(){
  return this->m__0pred;
}

void t_std_collections_List_1Tt_default_Voice_2_Node::m_InsertBefore(t_std_collections_List_1Tt_default_Voice_2_Node* l_node){
  this->m__0succ=l_node;
  this->m__0pred=l_node->m__0pred;
  this->m__0pred->m__0succ=this;
  l_node->m__0pred=this;
}

void t_std_collections_List_1Tt_default_Voice_2_Node::m_InsertAfter(t_std_collections_List_1Tt_default_Voice_2_Node* l_node){
  this->m__0pred=l_node;
  this->m__0succ=l_node->m__0succ;
  this->m__0succ->m__0pred=this;
  l_node->m__0succ=this;
}

t_std_collections_List_1Tt_default_Voice_2_Iterator::t_std_collections_List_1Tt_default_Voice_2_Iterator(t_std_collections_List_1Tt_default_Voice_2* l_list,t_std_collections_List_1Tt_default_Voice_2_Node* l_node){
  (*this).m__0list=l_list;
  (*this).m__0node=l_node;
  (*this).m__0seq=l_list->m__0seq;
}

void t_std_collections_List_1Tt_default_Voice_2_Iterator::m_Insert(t_default_Voice* l_value){
  (*this).m_AssertSeq();
  (*this).m__0node=bbGCNew<t_std_collections_List_1Tt_default_Voice_2_Node>(l_value,(*this).m__0node);
  (*this).m__0list->m__0seq+=1;
  (*this).m__0seq=(*this).m__0list->m__0seq;
}

void t_std_collections_List_1Tt_default_Voice_2_Iterator::m_Erase(){
  (*this).m_AssertCurrent();
  (*this).m__0node=(*this).m__0node->m__0succ;
  (*this).m__0node->m__0pred->m_Remove();
  (*this).m__0list->m__0seq+=1;
  (*this).m__0seq=(*this).m__0list->m__0seq;
}

void t_std_collections_List_1Tt_default_Voice_2_Iterator::m_Current(t_default_Voice* l_current){
  (*this).m_AssertCurrent();
  (*this).m__0node->m__0value=l_current;
}

t_default_Voice* t_std_collections_List_1Tt_default_Voice_2_Iterator::m_Current(){
  (*this).m_AssertCurrent();
  return (*this).m__0node->m__0value;
}

void t_std_collections_List_1Tt_default_Voice_2_Iterator::m_Bump(){
  (*this).m_AssertCurrent();
  (*this).m__0node=(*this).m__0node->m__0succ;
}

bbBool t_std_collections_List_1Tt_default_Voice_2_Iterator::m_AtEnd(){
  (*this).m_AssertSeq();
  return ((*this).m__0node==(*this).m__0list->m__0head);
}

void t_std_collections_List_1Tt_default_Voice_2_Iterator::m_AssertSeq(){
  bbDebugAssert(((*this).m__0seq==(*this).m__0list->m__0seq),BB_T("Concurrent list modification"));
}

void t_std_collections_List_1Tt_default_Voice_2_Iterator::m_AssertCurrent(){
  bbDebugAssert(!(*this).m_AtEnd(),BB_T("Invalid list iterator"));
}

int bbCompare(const t_std_collections_List_1Tt_default_Voice_2_Iterator&x,const t_std_collections_List_1Tt_default_Voice_2_Iterator&y){
  if(int t=bbCompare(x.m__0list,y.m__0list)) return t;
  if(int t=bbCompare(x.m__0node,y.m__0node)) return t;
  if(int t=bbCompare(x.m__0seq,y.m__0seq)) return t;
  return 0;
}

void bbGCMark(const t_std_collections_List_1Tt_default_Voice_2_Iterator&t){
  bbGCMark(t.m__0list);
  bbGCMark(t.m__0node);
}

t_std_collections_List_1Tt_default_Voice_2_BackwardsIterator::t_std_collections_List_1Tt_default_Voice_2_BackwardsIterator(t_std_collections_List_1Tt_default_Voice_2* l_list,t_std_collections_List_1Tt_default_Voice_2_Node* l_node){
  (*this).m__0list=l_list;
  (*this).m__0node=l_node;
  (*this).m__0seq=l_list->m__0seq;
}

void t_std_collections_List_1Tt_default_Voice_2_BackwardsIterator::m_Insert(t_default_Voice* l_value){
  (*this).m_AssertSeq();
  (*this).m__0node=bbGCNew<t_std_collections_List_1Tt_default_Voice_2_Node>(l_value,(*this).m__0node->m__0succ);
  (*this).m__0list->m__0seq+=1;
  (*this).m__0seq=(*this).m__0list->m__0seq;
}

void t_std_collections_List_1Tt_default_Voice_2_BackwardsIterator::m_Erase(){
  (*this).m_AssertCurrent();
  (*this).m__0node=(*this).m__0node->m__0pred;
  (*this).m__0node->m__0succ->m_Remove();
  (*this).m__0list->m__0seq+=1;
  (*this).m__0seq=(*this).m__0list->m__0seq;
}

void t_std_collections_List_1Tt_default_Voice_2_BackwardsIterator::m_Current(t_default_Voice* l_current){
  (*this).m_AssertCurrent();
  (*this).m__0node->m__0value=l_current;
}

t_default_Voice* t_std_collections_List_1Tt_default_Voice_2_BackwardsIterator::m_Current(){
  (*this).m_AssertCurrent();
  return (*this).m__0node->m__0value;
}

void t_std_collections_List_1Tt_default_Voice_2_BackwardsIterator::m_Bump(){
  (*this).m_AssertCurrent();
  (*this).m__0node=(*this).m__0node->m__0pred;
}

bbBool t_std_collections_List_1Tt_default_Voice_2_BackwardsIterator::m_AtEnd(){
  (*this).m_AssertSeq();
  return ((*this).m__0node==(*this).m__0list->m__0head);
}

void t_std_collections_List_1Tt_default_Voice_2_BackwardsIterator::m_AssertSeq(){
  bbDebugAssert(((*this).m__0seq==(*this).m__0list->m__0seq),BB_T("Concurrent list modification"));
}

void t_std_collections_List_1Tt_default_Voice_2_BackwardsIterator::m_AssertCurrent(){
  bbDebugAssert(!(*this).m_AtEnd(),BB_T("Invalid list iterator"));
}

int bbCompare(const t_std_collections_List_1Tt_default_Voice_2_BackwardsIterator&x,const t_std_collections_List_1Tt_default_Voice_2_BackwardsIterator&y){
  if(int t=bbCompare(x.m__0list,y.m__0list)) return t;
  if(int t=bbCompare(x.m__0node,y.m__0node)) return t;
  if(int t=bbCompare(x.m__0seq,y.m__0seq)) return t;
  return 0;
}

void bbGCMark(const t_std_collections_List_1Tt_default_Voice_2_BackwardsIterator&t){
  bbGCMark(t.m__0list);
  bbGCMark(t.m__0node);
}

void t_std_collections_List_1Tt_default_Voice_2::gcMark(){
  bbGCMark(m__0head);
}

t_std_collections_List_1Tt_default_Voice_2::t_std_collections_List_1Tt_default_Voice_2(t_std_collections_List_1Tt_default_Voice_2* l_values):t_std_collections_List_1Tt_default_Voice_2(){
  g_std_collections_List_1Tt_default_Voice_2_AddAll_1Tt_std_collections_List_1Tt_default_Voice_2_2(this,l_values);
}

t_std_collections_List_1Tt_default_Voice_2::t_std_collections_List_1Tt_default_Voice_2(t_std_collections_Stack_1Tt_default_Voice_2* l_values):t_std_collections_List_1Tt_default_Voice_2(){
  g_std_collections_List_1Tt_default_Voice_2_AddAll_1Tt_std_collections_Stack_1Tt_default_Voice_2_2(this,l_values);
}

t_std_collections_List_1Tt_default_Voice_2::t_std_collections_List_1Tt_default_Voice_2(bbArray<bbGCVar<t_default_Voice>>* l_values):t_std_collections_List_1Tt_default_Voice_2(){
  this->m_AddAll(l_values);
}

t_std_collections_List_1Tt_default_Voice_2::t_std_collections_List_1Tt_default_Voice_2(){
  this->m__0head=bbGCNew<t_std_collections_List_1Tt_default_Voice_2_Node>(((t_default_Voice*)0));
}

bbArray<bbGCVar<t_default_Voice>>* t_std_collections_List_1Tt_default_Voice_2::m_ToArray(){
  struct f0_t : public bbGCFrame{
    bbArray<bbGCVar<t_default_Voice>>* l_data{};
    t_std_collections_List_1Tt_default_Voice_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_data);
      bbGCMarkPtr(l_node);
    }
  }f0{};
  bbInt l_n=this->m_Count();
  f0.l_data=bbArray<bbGCVar<t_default_Voice>>::create(l_n);
  f0.l_node=this->m__0head->m__0succ;
  {
    bbInt l_i=bbInt(0);
    for(;(l_i<l_n);l_i+=1){
      f0.l_data->at(l_i)=f0.l_node->m__0value;
      f0.l_node=f0.l_node->m__0succ;
    }
  }
  return f0.l_data;
}

void t_std_collections_List_1Tt_default_Voice_2::m_Sort(bbFunction<bbInt(t_default_Voice*,t_default_Voice*)> l_compareFunc){
  bbInt l_insize=1;
  for(;;){
    struct f1_t : public bbGCFrame{
      t_std_collections_List_1Tt_default_Voice_2_Node* l_p{};
      t_std_collections_List_1Tt_default_Voice_2_Node* l_tail{};
      void gcMark(){
        bbGCMarkPtr(l_p);
        bbGCMarkPtr(l_tail);
      }
    }f1{};
    bbInt l_merges=bbInt(0);
    f1.l_tail=this->m__0head;
    f1.l_p=this->m__0head->m__0succ;
    while((f1.l_p!=this->m__0head)){
      struct f2_t : public bbGCFrame{
        t_std_collections_List_1Tt_default_Voice_2_Node* l_q{};
        void gcMark(){
          bbGCMarkPtr(l_q);
        }
      }f2{};
      l_merges+=1;
      f2.l_q=f1.l_p->m__0succ;
      bbInt l_qsize=l_insize;
      bbInt l_psize=1;
      while(((l_psize<l_insize)&&(f2.l_q!=this->m__0head))){
        l_psize+=1;
        f2.l_q=f2.l_q->m__0succ;
      }
      for(;;){
        struct f3_t : public bbGCFrame{
          t_std_collections_List_1Tt_default_Voice_2_Node* l_t{};
          void gcMark(){
            bbGCMarkPtr(l_t);
          }
        }f3{};
        if(((bbBool(l_psize)&&bbBool(l_qsize))&&(f2.l_q!=this->m__0head))){
          bbInt l_cc=l_compareFunc(f1.l_p->m__0value,f2.l_q->m__0value);
          if((l_cc<=bbInt(0))){
            f3.l_t=f1.l_p;
            f1.l_p=f1.l_p->m__0succ;
            l_psize-=1;
          }else{
            f3.l_t=f2.l_q;
            f2.l_q=f2.l_q->m__0succ;
            l_qsize-=1;
          }
        }else if(bbBool(l_psize)){
          f3.l_t=f1.l_p;
          f1.l_p=f1.l_p->m__0succ;
          l_psize-=1;
        }else if((bbBool(l_qsize)&&(f2.l_q!=this->m__0head))){
          f3.l_t=f2.l_q;
          f2.l_q=f2.l_q->m__0succ;
          l_qsize-=1;
        }else{
          break;
        }
        f3.l_t->m__0pred=f1.l_tail;
        f1.l_tail->m__0succ=f3.l_t;
        f1.l_tail=f3.l_t;
      }
      f1.l_p=f2.l_q;
    }
    f1.l_tail->m__0succ=this->m__0head;
    this->m__0head->m__0pred=f1.l_tail;
    if((l_merges<=1)){
      return;
    }
    l_insize*=2;
  }
}

void t_std_collections_List_1Tt_default_Voice_2::m_Sort(bbBool l_ascending){
  if(l_ascending){
    struct lambda0 : public bbFunction<bbInt(t_default_Voice*,t_default_Voice*)>::Rep{
      t_std_collections_List_1Tt_default_Voice_2* l_self;
      lambda0(t_std_collections_List_1Tt_default_Voice_2* l_self):l_self(l_self){
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
      t_std_collections_List_1Tt_default_Voice_2* l_self;
      lambda1(t_std_collections_List_1Tt_default_Voice_2* l_self):l_self(l_self){
      }
      bbInt invoke(t_default_Voice* l_x,t_default_Voice* l_y){
        return -bbCompare(l_x,l_y);
      }
      void gcMark(){
        bbGCMarkPtr(l_self);
      }
    };
    this->m_Sort(bbFunction<bbInt(t_default_Voice*,t_default_Voice*)>(new lambda1(this)));
  }
}

t_default_Voice* t_std_collections_List_1Tt_default_Voice_2::m_RemoveLast(){
  struct f0_t : public bbGCFrame{
    t_default_Voice* l_value{};
    void gcMark(){
      bbGCMarkPtr(l_value);
    }
  }f0{};
  bbDebugAssert(!this->m_Empty(),BB_T("Debug assert failed"));
  f0.l_value=this->m__0head->m__0pred->m__0value;
  this->m__0head->m__0pred->m_Remove();
  this->m__0seq+=1;
  return f0.l_value;
}

bbBool t_std_collections_List_1Tt_default_Voice_2::m_RemoveLast(t_default_Voice* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_default_Voice_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m_FindLastNode(l_value);
  if(!bbBool(f0.l_node)){
    return false;
  }
  f0.l_node->m_Remove();
  this->m__0seq+=1;
  return true;
}

t_default_Voice* t_std_collections_List_1Tt_default_Voice_2::m_RemoveFirst(){
  struct f0_t : public bbGCFrame{
    t_default_Voice* l_value{};
    void gcMark(){
      bbGCMarkPtr(l_value);
    }
  }f0{};
  bbDebugAssert(!this->m_Empty(),BB_T("Debug assert failed"));
  f0.l_value=this->m__0head->m__0succ->m__0value;
  this->m__0head->m__0succ->m_Remove();
  this->m__0seq+=1;
  return f0.l_value;
}

bbInt t_std_collections_List_1Tt_default_Voice_2::m_RemoveEach(t_default_Voice* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_default_Voice_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m__0head->m__0succ;
  bbInt l_n=bbInt(0);
  while((f0.l_node!=this->m__0head)){
    if((f0.l_node->m__0value==l_value)){
      f0.l_node=f0.l_node->m__0succ;
      f0.l_node->m__0pred->m_Remove();
      l_n+=1;
    }else{
      f0.l_node=f0.l_node->m__0succ;
    }
  }
  if(bbBool(l_n)){
    this->m__0seq+=1;
  }
  return l_n;
}

bbBool t_std_collections_List_1Tt_default_Voice_2::m_Remove(t_default_Voice* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_default_Voice_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m_FindNode(l_value);
  if(!bbBool(f0.l_node)){
    return false;
  }
  f0.l_node->m_Remove();
  this->m__0seq+=1;
  return true;
}

t_std_collections_List_1Tt_default_Voice_2_Node* t_std_collections_List_1Tt_default_Voice_2::m_LastNode(){
  if(!this->m_Empty()){
    return this->m__0head->m__0pred;
  }
  return ((t_std_collections_List_1Tt_default_Voice_2_Node*)0);
}

t_default_Voice* t_std_collections_List_1Tt_default_Voice_2::m_Last(){
  bbDebugAssert(!this->m_Empty(),BB_T("Debug assert failed"));
  return this->m__0head->m__0pred->m__0value;
}

t_std_collections_List_1Tt_default_Voice_2_Node* t_std_collections_List_1Tt_default_Voice_2::m_HeadNode(){
  return this->m__0head;
}

t_std_collections_List_1Tt_default_Voice_2_Node* t_std_collections_List_1Tt_default_Voice_2::m_FirstNode(){
  if(!this->m_Empty()){
    return this->m__0head->m__0succ;
  }
  return ((t_std_collections_List_1Tt_default_Voice_2_Node*)0);
}

t_default_Voice* t_std_collections_List_1Tt_default_Voice_2::m_First(){
  bbDebugAssert(!this->m_Empty(),BB_T("Debug assert failed"));
  return this->m__0head->m__0succ->m__0value;
}

t_std_collections_List_1Tt_default_Voice_2_Node* t_std_collections_List_1Tt_default_Voice_2::m_FindNode(t_default_Voice* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_default_Voice_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m__0head->m__0succ;
  while((f0.l_node!=this->m__0head)){
    if((f0.l_node->m__0value==l_value)){
      return f0.l_node;
    }
    f0.l_node=f0.l_node->m__0succ;
  }
  return ((t_std_collections_List_1Tt_default_Voice_2_Node*)0);
}

t_std_collections_List_1Tt_default_Voice_2_Node* t_std_collections_List_1Tt_default_Voice_2::m_FindLastNode(t_default_Voice* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_default_Voice_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m__0head->m__0pred;
  while((f0.l_node!=this->m__0head)){
    if((f0.l_node->m__0value==l_value)){
      return f0.l_node;
    }
    f0.l_node=f0.l_node->m__0pred;
  }
  return ((t_std_collections_List_1Tt_default_Voice_2_Node*)0);
}

bbBool t_std_collections_List_1Tt_default_Voice_2::m_Empty(){
  return (this->m__0head->m__0succ==this->m__0head);
}

bbInt t_std_collections_List_1Tt_default_Voice_2::m_Count(){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_default_Voice_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m__0head->m__0succ;
  bbInt l_n=bbInt(0);
  while((f0.l_node!=this->m__0head)){
    f0.l_node=f0.l_node->m__0succ;
    l_n+=1;
  }
  return l_n;
}

void t_std_collections_List_1Tt_default_Voice_2::m_Clear(){
  this->m__0head->m__0succ=this->m__0head;
  this->m__0head->m__0pred=this->m__0head;
  this->m__0seq+=1;
}

t_std_collections_List_1Tt_default_Voice_2_BackwardsIterator t_std_collections_List_1Tt_default_Voice_2::m_Backwards(){
  return t_std_collections_List_1Tt_default_Voice_2_BackwardsIterator(this,this->m__0head->m__0pred);
}

t_std_collections_List_1Tt_default_Voice_2_Iterator t_std_collections_List_1Tt_default_Voice_2::m_All(){
  return t_std_collections_List_1Tt_default_Voice_2_Iterator(this,this->m__0head->m__0succ);
}

t_std_collections_List_1Tt_default_Voice_2_Node* t_std_collections_List_1Tt_default_Voice_2::m_AddLast(t_default_Voice* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_default_Voice_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=bbGCNew<t_std_collections_List_1Tt_default_Voice_2_Node>(l_value,this->m__0head);
  this->m__0seq+=1;
  return f0.l_node;
}

t_std_collections_List_1Tt_default_Voice_2_Node* t_std_collections_List_1Tt_default_Voice_2::m_AddFirst(t_default_Voice* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_default_Voice_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=bbGCNew<t_std_collections_List_1Tt_default_Voice_2_Node>(l_value,this->m__0head->m__0succ);
  this->m__0seq+=1;
  return f0.l_node;
}

void t_std_collections_List_1Tt_default_Voice_2::m_AddAll(bbArray<bbGCVar<t_default_Voice>>* l_values){
  {
    bbInt l_0=bbInt(0);
    bbInt l_1=l_values->length();
    for(;(l_0<l_1);l_0+=1){
      struct f2_t : public bbGCFrame{
        t_default_Voice* l_value{};
        void gcMark(){
          bbGCMarkPtr(l_value);
        }
      }f2{};
      f2.l_value=l_values->at(l_0);
      this->m_AddLast(f2.l_value);
    }
  }
}

void t_std_collections_List_1Tt_default_Voice_2::m_Add(t_default_Voice* l_value){
  this->m_AddLast(l_value);
}

void mx2_vsynth_std_collections_2list_init(){
  static bool done;
  if(done) return;
  done=true;
}

bbInit mx2_vsynth_std_collections_2list_init_v("vsynth_std_collections_2list",&mx2_vsynth_std_collections_2list_init);
