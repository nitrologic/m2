
#include "mx2cc_std_collections_2map.h"

// ***** External *****

#include "mx2cc_class.h"
#include "mx2cc_decl.h"
#include "mx2cc_module.h"
#include "mx2cc_namespace.h"
#include "mx2cc_node.h"
#include "mx2cc_var.h"
#include "../../../../../modules/std/std.buildv1.0.0/desktop_release_linux/std_collections_2stack.h"

// ***** Internal *****

void t_std_collections_Map_1sTt_std_collections_Stack_1s_2_Node::gcMark(){
  bbGCMark(m__0value);
  bbGCMark(m__0left);
  bbGCMark(m__0right);
  bbGCMark(m__0parent);
}

t_std_collections_Map_1sTt_std_collections_Stack_1s_2_Node::t_std_collections_Map_1sTt_std_collections_Stack_1s_2_Node(bbString l_key,t_std_collections_Stack_1s* l_value,bbInt l_color,t_std_collections_Map_1sTt_std_collections_Stack_1s_2_Node* l_parent){
  this->m__0key=l_key;
  this->m__0value=l_value;
  this->m__0color=l_color;
  this->m__0parent=l_parent;
}

t_std_collections_Stack_1s* t_std_collections_Map_1sTt_std_collections_Stack_1s_2_Node::m_Value(){
  return this->m__0value;
}

t_std_collections_Map_1sTt_std_collections_Stack_1s_2_Node* t_std_collections_Map_1sTt_std_collections_Stack_1s_2_Node::m_PrevNode(){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1sTt_std_collections_Stack_1s_2_Node* l_node{};
    t_std_collections_Map_1sTt_std_collections_Stack_1s_2_Node* l_parent{};
    void gcMark(){
      bbGCMarkPtr(l_node);
      bbGCMarkPtr(l_parent);
    }
  }f0{};
  if(bbBool(this->m__0left)){
    struct f1_t : public bbGCFrame{
      t_std_collections_Map_1sTt_std_collections_Stack_1s_2_Node* l_node{};
      void gcMark(){
        bbGCMarkPtr(l_node);
      }
    }f1{};
    f1.l_node=this->m__0left;
    while(bbBool(f1.l_node->m__0right)){
      f1.l_node=f1.l_node->m__0right;
    }
    return f1.l_node;
  }
  f0.l_node=this;
  f0.l_parent=this->m__0parent;
  while((bbBool(f0.l_parent)&&(f0.l_node==f0.l_parent->m__0left))){
    f0.l_node=f0.l_parent;
    f0.l_parent=f0.l_parent->m__0parent;
  }
  return f0.l_parent;
}

t_std_collections_Map_1sTt_std_collections_Stack_1s_2_Node* t_std_collections_Map_1sTt_std_collections_Stack_1s_2_Node::m_NextNode(){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1sTt_std_collections_Stack_1s_2_Node* l_node{};
    t_std_collections_Map_1sTt_std_collections_Stack_1s_2_Node* l_parent{};
    void gcMark(){
      bbGCMarkPtr(l_node);
      bbGCMarkPtr(l_parent);
    }
  }f0{};
  if(bbBool(this->m__0right)){
    struct f1_t : public bbGCFrame{
      t_std_collections_Map_1sTt_std_collections_Stack_1s_2_Node* l_node{};
      void gcMark(){
        bbGCMarkPtr(l_node);
      }
    }f1{};
    f1.l_node=this->m__0right;
    while(bbBool(f1.l_node->m__0left)){
      f1.l_node=f1.l_node->m__0left;
    }
    return f1.l_node;
  }
  f0.l_node=this;
  f0.l_parent=this->m__0parent;
  while((bbBool(f0.l_parent)&&(f0.l_node==f0.l_parent->m__0right))){
    f0.l_node=f0.l_parent;
    f0.l_parent=f0.l_parent->m__0parent;
  }
  return f0.l_parent;
}

bbString t_std_collections_Map_1sTt_std_collections_Stack_1s_2_Node::m_Key(){
  return this->m__0key;
}

bbInt t_std_collections_Map_1sTt_std_collections_Stack_1s_2_Node::m_Count(bbInt l_n){
  if(bbBool(this->m__0left)){
    l_n=this->m__0left->m_Count(l_n);
  }
  if(bbBool(this->m__0right)){
    l_n=this->m__0right->m_Count(l_n);
  }
  return (l_n+1);
}

t_std_collections_Map_1sTt_std_collections_Stack_1s_2_Node* t_std_collections_Map_1sTt_std_collections_Stack_1s_2_Node::m_Copy(t_std_collections_Map_1sTt_std_collections_Stack_1s_2_Node* l_parent){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1sTt_std_collections_Stack_1s_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=bbGCNew<t_std_collections_Map_1sTt_std_collections_Stack_1s_2_Node>(this->m__0key,this->m__0value,this->m__0color,l_parent);
  if(bbBool(this->m__0left)){
    f0.l_node->m__0left=this->m__0left->m_Copy(f0.l_node);
  }
  if(bbBool(this->m__0right)){
    f0.l_node->m__0right=this->m__0right->m_Copy(f0.l_node);
  }
  return f0.l_node;
}

t_std_collections_Map_1sTt_std_collections_Stack_1s_2_Iterator::t_std_collections_Map_1sTt_std_collections_Stack_1s_2_Iterator(t_std_collections_Map_1sTt_std_collections_Stack_1s_2_Node* l_node){
  (*this).m__0node=l_node;
}

bbBool t_std_collections_Map_1sTt_std_collections_Stack_1s_2_Iterator::m_Valid(){
  return bbBool((*this).m__0node);
}

t_std_collections_Map_1sTt_std_collections_Stack_1s_2_Node* t_std_collections_Map_1sTt_std_collections_Stack_1s_2_Iterator::m_Current(){
  return (*this).m__0node;
}

void t_std_collections_Map_1sTt_std_collections_Stack_1s_2_Iterator::m_Bump(){
  (*this).m__0node=(*this).m__0node->m_NextNode();
}

int bbCompare(const t_std_collections_Map_1sTt_std_collections_Stack_1s_2_Iterator&x,const t_std_collections_Map_1sTt_std_collections_Stack_1s_2_Iterator&y){
  if(int t=bbCompare(x.m__0node,y.m__0node)) return t;
  return 0;
}

void bbGCMark(const t_std_collections_Map_1sTt_std_collections_Stack_1s_2_Iterator&t){
  bbGCMark(t.m__0node);
}

t_std_collections_Map_1sTt_std_collections_Stack_1s_2_KeyIterator::t_std_collections_Map_1sTt_std_collections_Stack_1s_2_KeyIterator(t_std_collections_Map_1sTt_std_collections_Stack_1s_2_Node* l_node){
  (*this).m__0node=l_node;
}

bbBool t_std_collections_Map_1sTt_std_collections_Stack_1s_2_KeyIterator::m_Valid(){
  return bbBool((*this).m__0node);
}

bbString t_std_collections_Map_1sTt_std_collections_Stack_1s_2_KeyIterator::m_Current(){
  return (*this).m__0node->m__0key;
}

void t_std_collections_Map_1sTt_std_collections_Stack_1s_2_KeyIterator::m_Bump(){
  (*this).m__0node=(*this).m__0node->m_NextNode();
}

int bbCompare(const t_std_collections_Map_1sTt_std_collections_Stack_1s_2_KeyIterator&x,const t_std_collections_Map_1sTt_std_collections_Stack_1s_2_KeyIterator&y){
  if(int t=bbCompare(x.m__0node,y.m__0node)) return t;
  return 0;
}

void bbGCMark(const t_std_collections_Map_1sTt_std_collections_Stack_1s_2_KeyIterator&t){
  bbGCMark(t.m__0node);
}

t_std_collections_Map_1sTt_std_collections_Stack_1s_2_MapKeys::t_std_collections_Map_1sTt_std_collections_Stack_1s_2_MapKeys(t_std_collections_Map_1sTt_std_collections_Stack_1s_2* l_map){
  (*this).m__0map=l_map;
}

t_std_collections_Map_1sTt_std_collections_Stack_1s_2_KeyIterator t_std_collections_Map_1sTt_std_collections_Stack_1s_2_MapKeys::m_All(){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1sTt_std_collections_Stack_1s_2_Node* t0{};
    void gcMark(){
      bbGCMarkPtr(t0);
    }
  }f0{};
  return t_std_collections_Map_1sTt_std_collections_Stack_1s_2_KeyIterator(f0.t0=(*this).m__0map->m_FirstNode());
}

int bbCompare(const t_std_collections_Map_1sTt_std_collections_Stack_1s_2_MapKeys&x,const t_std_collections_Map_1sTt_std_collections_Stack_1s_2_MapKeys&y){
  if(int t=bbCompare(x.m__0map,y.m__0map)) return t;
  return 0;
}

void bbGCMark(const t_std_collections_Map_1sTt_std_collections_Stack_1s_2_MapKeys&t){
  bbGCMark(t.m__0map);
}

t_std_collections_Map_1sTt_std_collections_Stack_1s_2_ValueIterator::t_std_collections_Map_1sTt_std_collections_Stack_1s_2_ValueIterator(t_std_collections_Map_1sTt_std_collections_Stack_1s_2_Node* l_node){
  (*this).m__0node=l_node;
}

bbBool t_std_collections_Map_1sTt_std_collections_Stack_1s_2_ValueIterator::m_Valid(){
  return bbBool((*this).m__0node);
}

t_std_collections_Stack_1s* t_std_collections_Map_1sTt_std_collections_Stack_1s_2_ValueIterator::m_Current(){
  return (*this).m__0node->m__0value;
}

void t_std_collections_Map_1sTt_std_collections_Stack_1s_2_ValueIterator::m_Bump(){
  (*this).m__0node=(*this).m__0node->m_NextNode();
}

int bbCompare(const t_std_collections_Map_1sTt_std_collections_Stack_1s_2_ValueIterator&x,const t_std_collections_Map_1sTt_std_collections_Stack_1s_2_ValueIterator&y){
  if(int t=bbCompare(x.m__0node,y.m__0node)) return t;
  return 0;
}

void bbGCMark(const t_std_collections_Map_1sTt_std_collections_Stack_1s_2_ValueIterator&t){
  bbGCMark(t.m__0node);
}

t_std_collections_Map_1sTt_std_collections_Stack_1s_2_MapValues::t_std_collections_Map_1sTt_std_collections_Stack_1s_2_MapValues(t_std_collections_Map_1sTt_std_collections_Stack_1s_2* l_map){
  (*this).m__0map=l_map;
}

t_std_collections_Map_1sTt_std_collections_Stack_1s_2_ValueIterator t_std_collections_Map_1sTt_std_collections_Stack_1s_2_MapValues::m_All(){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1sTt_std_collections_Stack_1s_2_Node* t0{};
    void gcMark(){
      bbGCMarkPtr(t0);
    }
  }f0{};
  return t_std_collections_Map_1sTt_std_collections_Stack_1s_2_ValueIterator(f0.t0=(*this).m__0map->m_FirstNode());
}

int bbCompare(const t_std_collections_Map_1sTt_std_collections_Stack_1s_2_MapValues&x,const t_std_collections_Map_1sTt_std_collections_Stack_1s_2_MapValues&y){
  if(int t=bbCompare(x.m__0map,y.m__0map)) return t;
  return 0;
}

void bbGCMark(const t_std_collections_Map_1sTt_std_collections_Stack_1s_2_MapValues&t){
  bbGCMark(t.m__0map);
}

void t_std_collections_Map_1sTt_std_collections_Stack_1s_2::gcMark(){
  bbGCMark(m__0root);
}

t_std_collections_Map_1sTt_std_collections_Stack_1s_2::t_std_collections_Map_1sTt_std_collections_Stack_1s_2(t_std_collections_Map_1sTt_std_collections_Stack_1s_2_Node* l_root){
  this->m__0root=l_root;
}

t_std_collections_Map_1sTt_std_collections_Stack_1s_2::t_std_collections_Map_1sTt_std_collections_Stack_1s_2(){
}

void t_std_collections_Map_1sTt_std_collections_Stack_1s_2::m__idxeq(bbString l_key,t_std_collections_Stack_1s* l_value){
  this->m_Set(l_key,l_value);
}

t_std_collections_Stack_1s* t_std_collections_Map_1sTt_std_collections_Stack_1s_2::m__idx(bbString l_key){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1sTt_std_collections_Stack_1s_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m_FindNode(l_key);
  if(!bbBool(f0.l_node)){
    return ((t_std_collections_Stack_1s*)0);
  }
  return f0.l_node->m__0value;
}

t_std_collections_Map_1sTt_std_collections_Stack_1s_2_MapValues t_std_collections_Map_1sTt_std_collections_Stack_1s_2::m_Values(){
  return t_std_collections_Map_1sTt_std_collections_Stack_1s_2_MapValues(this);
}

bbBool t_std_collections_Map_1sTt_std_collections_Stack_1s_2::m_Update(bbString l_key,t_std_collections_Stack_1s* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1sTt_std_collections_Stack_1s_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m_FindNode(l_key);
  if(!bbBool(f0.l_node)){
    return false;
  }
  f0.l_node->m__0value=l_value;
  return true;
}

bbBool t_std_collections_Map_1sTt_std_collections_Stack_1s_2::m_Set(bbString l_key,t_std_collections_Stack_1s* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1sTt_std_collections_Stack_1s_2_Node* l_node{};
    t_std_collections_Map_1sTt_std_collections_Stack_1s_2_Node* l_parent{};
    void gcMark(){
      bbGCMarkPtr(l_node);
      bbGCMarkPtr(l_parent);
    }
  }f0{};
  if(!bbBool(this->m__0root)){
    this->m__0root=bbGCNew<t_std_collections_Map_1sTt_std_collections_Stack_1s_2_Node>(l_key,l_value,0,((t_std_collections_Map_1sTt_std_collections_Stack_1s_2_Node*)0));
    return true;
  }
  f0.l_node=this->m__0root;
  bbInt l_cmp{};
  while(bbBool(f0.l_node)){
    f0.l_parent=f0.l_node;
    l_cmp=bbCompare(l_key,f0.l_node->m__0key);
    if((l_cmp>bbInt(0))){
      f0.l_node=f0.l_node->m__0right;
    }else if((l_cmp<bbInt(0))){
      f0.l_node=f0.l_node->m__0left;
    }else{
      f0.l_node->m__0value=l_value;
      return false;
    }
  }
  f0.l_node=bbGCNew<t_std_collections_Map_1sTt_std_collections_Stack_1s_2_Node>(l_key,l_value,0,f0.l_parent);
  if((l_cmp>bbInt(0))){
    f0.l_parent->m__0right=f0.l_node;
  }else{
    f0.l_parent->m__0left=f0.l_node;
  }
  this->m_InsertFixup(f0.l_node);
  return true;
}

void t_std_collections_Map_1sTt_std_collections_Stack_1s_2::m_RotateRight(t_std_collections_Map_1sTt_std_collections_Stack_1s_2_Node* l_node){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1sTt_std_collections_Stack_1s_2_Node* l_child{};
    void gcMark(){
      bbGCMarkPtr(l_child);
    }
  }f0{};
  f0.l_child=l_node->m__0left;
  l_node->m__0left=f0.l_child->m__0right;
  if(bbBool(f0.l_child->m__0right)){
    f0.l_child->m__0right->m__0parent=l_node;
  }
  f0.l_child->m__0parent=l_node->m__0parent;
  if(bbBool(l_node->m__0parent)){
    if((l_node==l_node->m__0parent->m__0right)){
      l_node->m__0parent->m__0right=f0.l_child;
    }else{
      l_node->m__0parent->m__0left=f0.l_child;
    }
  }else{
    this->m__0root=f0.l_child;
  }
  f0.l_child->m__0right=l_node;
  l_node->m__0parent=f0.l_child;
}

void t_std_collections_Map_1sTt_std_collections_Stack_1s_2::m_RotateLeft(t_std_collections_Map_1sTt_std_collections_Stack_1s_2_Node* l_node){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1sTt_std_collections_Stack_1s_2_Node* l_child{};
    void gcMark(){
      bbGCMarkPtr(l_child);
    }
  }f0{};
  f0.l_child=l_node->m__0right;
  l_node->m__0right=f0.l_child->m__0left;
  if(bbBool(f0.l_child->m__0left)){
    f0.l_child->m__0left->m__0parent=l_node;
  }
  f0.l_child->m__0parent=l_node->m__0parent;
  if(bbBool(l_node->m__0parent)){
    if((l_node==l_node->m__0parent->m__0left)){
      l_node->m__0parent->m__0left=f0.l_child;
    }else{
      l_node->m__0parent->m__0right=f0.l_child;
    }
  }else{
    this->m__0root=f0.l_child;
  }
  f0.l_child->m__0left=l_node;
  l_node->m__0parent=f0.l_child;
}

void t_std_collections_Map_1sTt_std_collections_Stack_1s_2::m_RemoveNode(t_std_collections_Map_1sTt_std_collections_Stack_1s_2_Node* l_node){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1sTt_std_collections_Stack_1s_2_Node* l_child{};
    t_std_collections_Map_1sTt_std_collections_Stack_1s_2_Node* l_parent{};
    t_std_collections_Map_1sTt_std_collections_Stack_1s_2_Node* l_splice{};
    void gcMark(){
      bbGCMarkPtr(l_child);
      bbGCMarkPtr(l_parent);
      bbGCMarkPtr(l_splice);
    }
  }f0{};
  if(!bbBool(l_node->m__0left)){
    f0.l_splice=l_node;
    f0.l_child=l_node->m__0right;
  }else if(!bbBool(l_node->m__0right)){
    f0.l_splice=l_node;
    f0.l_child=l_node->m__0left;
  }else{
    f0.l_splice=l_node->m__0left;
    while(bbBool(f0.l_splice->m__0right)){
      f0.l_splice=f0.l_splice->m__0right;
    }
    f0.l_child=f0.l_splice->m__0left;
    l_node->m__0key=f0.l_splice->m__0key;
    l_node->m__0value=f0.l_splice->m__0value;
  }
  f0.l_parent=f0.l_splice->m__0parent;
  if(bbBool(f0.l_child)){
    f0.l_child->m__0parent=f0.l_parent;
  }
  if(!bbBool(f0.l_parent)){
    this->m__0root=f0.l_child;
    return;
  }
  if((f0.l_splice==f0.l_parent->m__0left)){
    f0.l_parent->m__0left=f0.l_child;
  }else{
    f0.l_parent->m__0right=f0.l_child;
  }
  if((f0.l_splice->m__0color==1)){
    this->m_DeleteFixup(f0.l_child,f0.l_parent);
  }
}

bbBool t_std_collections_Map_1sTt_std_collections_Stack_1s_2::m_Remove(bbString l_key){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1sTt_std_collections_Stack_1s_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m_FindNode(l_key);
  if(!bbBool(f0.l_node)){
    return false;
  }
  this->m_RemoveNode(f0.l_node);
  return true;
}

t_std_collections_Map_1sTt_std_collections_Stack_1s_2_Node* t_std_collections_Map_1sTt_std_collections_Stack_1s_2::m_LastNode(){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1sTt_std_collections_Stack_1s_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  if(!bbBool(this->m__0root)){
    return ((t_std_collections_Map_1sTt_std_collections_Stack_1s_2_Node*)0);
  }
  f0.l_node=this->m__0root;
  while(bbBool(f0.l_node->m__0right)){
    f0.l_node=f0.l_node->m__0right;
  }
  return f0.l_node;
}

t_std_collections_Map_1sTt_std_collections_Stack_1s_2_MapKeys t_std_collections_Map_1sTt_std_collections_Stack_1s_2::m_Keys(){
  return t_std_collections_Map_1sTt_std_collections_Stack_1s_2_MapKeys(this);
}

void t_std_collections_Map_1sTt_std_collections_Stack_1s_2::m_InsertFixup(t_std_collections_Map_1sTt_std_collections_Stack_1s_2_Node* l_node){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1sTt_std_collections_Stack_1s_2_Node* l_node{};
    f0_t(t_std_collections_Map_1sTt_std_collections_Stack_1s_2_Node* l_node):l_node(l_node){
    }
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{l_node};
  while(((bbBool(f0.l_node->m__0parent)&&(f0.l_node->m__0parent->m__0color==0))&&bbBool(f0.l_node->m__0parent->m__0parent))){
    if((f0.l_node->m__0parent==f0.l_node->m__0parent->m__0parent->m__0left)){
      struct f2_t : public bbGCFrame{
        t_std_collections_Map_1sTt_std_collections_Stack_1s_2_Node* l_uncle{};
        void gcMark(){
          bbGCMarkPtr(l_uncle);
        }
      }f2{};
      f2.l_uncle=f0.l_node->m__0parent->m__0parent->m__0right;
      if((bbBool(f2.l_uncle)&&(f2.l_uncle->m__0color==0))){
        f0.l_node->m__0parent->m__0color=1;
        f2.l_uncle->m__0color=1;
        f2.l_uncle->m__0parent->m__0color=0;
        f0.l_node=f2.l_uncle->m__0parent;
      }else{
        if((f0.l_node==f0.l_node->m__0parent->m__0right)){
          f0.l_node=f0.l_node->m__0parent;
          this->m_RotateLeft(f0.l_node);
        }
        f0.l_node->m__0parent->m__0color=1;
        f0.l_node->m__0parent->m__0parent->m__0color=0;
        this->m_RotateRight(f0.l_node->m__0parent->m__0parent);
      }
    }else{
      struct f2_t : public bbGCFrame{
        t_std_collections_Map_1sTt_std_collections_Stack_1s_2_Node* l_uncle{};
        void gcMark(){
          bbGCMarkPtr(l_uncle);
        }
      }f2{};
      f2.l_uncle=f0.l_node->m__0parent->m__0parent->m__0left;
      if((bbBool(f2.l_uncle)&&(f2.l_uncle->m__0color==0))){
        f0.l_node->m__0parent->m__0color=1;
        f2.l_uncle->m__0color=1;
        f2.l_uncle->m__0parent->m__0color=0;
        f0.l_node=f2.l_uncle->m__0parent;
      }else{
        if((f0.l_node==f0.l_node->m__0parent->m__0left)){
          f0.l_node=f0.l_node->m__0parent;
          this->m_RotateRight(f0.l_node);
        }
        f0.l_node->m__0parent->m__0color=1;
        f0.l_node->m__0parent->m__0parent->m__0color=0;
        this->m_RotateLeft(f0.l_node->m__0parent->m__0parent);
      }
    }
  }
  this->m__0root->m__0color=1;
}

t_std_collections_Stack_1s* t_std_collections_Map_1sTt_std_collections_Stack_1s_2::m_Get(bbString l_key){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1sTt_std_collections_Stack_1s_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m_FindNode(l_key);
  if(bbBool(f0.l_node)){
    return f0.l_node->m__0value;
  }
  return ((t_std_collections_Stack_1s*)0);
}

t_std_collections_Map_1sTt_std_collections_Stack_1s_2_Node* t_std_collections_Map_1sTt_std_collections_Stack_1s_2::m_FirstNode(){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1sTt_std_collections_Stack_1s_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  if(!bbBool(this->m__0root)){
    return ((t_std_collections_Map_1sTt_std_collections_Stack_1s_2_Node*)0);
  }
  f0.l_node=this->m__0root;
  while(bbBool(f0.l_node->m__0left)){
    f0.l_node=f0.l_node->m__0left;
  }
  return f0.l_node;
}

t_std_collections_Map_1sTt_std_collections_Stack_1s_2_Node* t_std_collections_Map_1sTt_std_collections_Stack_1s_2::m_FindNode(bbString l_key){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1sTt_std_collections_Stack_1s_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m__0root;
  while(bbBool(f0.l_node)){
    bbInt l_cmp=bbCompare(l_key,f0.l_node->m__0key);
    if((l_cmp>bbInt(0))){
      f0.l_node=f0.l_node->m__0right;
    }else if((l_cmp<bbInt(0))){
      f0.l_node=f0.l_node->m__0left;
    }else{
      return f0.l_node;
    }
  }
  return ((t_std_collections_Map_1sTt_std_collections_Stack_1s_2_Node*)0);
}

bbBool t_std_collections_Map_1sTt_std_collections_Stack_1s_2::m_Empty(){
  return (this->m__0root==((t_std_collections_Map_1sTt_std_collections_Stack_1s_2_Node*)0));
}

void t_std_collections_Map_1sTt_std_collections_Stack_1s_2::m_DeleteFixup(t_std_collections_Map_1sTt_std_collections_Stack_1s_2_Node* l_node,t_std_collections_Map_1sTt_std_collections_Stack_1s_2_Node* l_parent){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1sTt_std_collections_Stack_1s_2_Node* l_node{};
    t_std_collections_Map_1sTt_std_collections_Stack_1s_2_Node* l_parent{};
    f0_t(t_std_collections_Map_1sTt_std_collections_Stack_1s_2_Node* l_node,t_std_collections_Map_1sTt_std_collections_Stack_1s_2_Node* l_parent):l_node(l_node),l_parent(l_parent){
    }
    void gcMark(){
      bbGCMarkPtr(l_node);
      bbGCMarkPtr(l_parent);
    }
  }f0{l_node,l_parent};
  while(((f0.l_node!=this->m__0root)&&(!bbBool(f0.l_node)||(f0.l_node->m__0color==1)))){
    if((f0.l_node==f0.l_parent->m__0left)){
      struct f2_t : public bbGCFrame{
        t_std_collections_Map_1sTt_std_collections_Stack_1s_2_Node* l_sib{};
        void gcMark(){
          bbGCMarkPtr(l_sib);
        }
      }f2{};
      f2.l_sib=f0.l_parent->m__0right;
      if((f2.l_sib->m__0color==0)){
        f2.l_sib->m__0color=1;
        f0.l_parent->m__0color=0;
        this->m_RotateLeft(f0.l_parent);
        f2.l_sib=f0.l_parent->m__0right;
      }
      if(((!bbBool(f2.l_sib->m__0left)||(f2.l_sib->m__0left->m__0color==1))&&(!bbBool(f2.l_sib->m__0right)||(f2.l_sib->m__0right->m__0color==1)))){
        f2.l_sib->m__0color=0;
        f0.l_node=f0.l_parent;
        f0.l_parent=f0.l_parent->m__0parent;
      }else{
        if((!bbBool(f2.l_sib->m__0right)||(f2.l_sib->m__0right->m__0color==1))){
          f2.l_sib->m__0left->m__0color=1;
          f2.l_sib->m__0color=0;
          this->m_RotateRight(f2.l_sib);
          f2.l_sib=f0.l_parent->m__0right;
        }
        f2.l_sib->m__0color=f0.l_parent->m__0color;
        f0.l_parent->m__0color=1;
        f2.l_sib->m__0right->m__0color=1;
        this->m_RotateLeft(f0.l_parent);
        f0.l_node=this->m__0root;
      }
    }else{
      struct f2_t : public bbGCFrame{
        t_std_collections_Map_1sTt_std_collections_Stack_1s_2_Node* l_sib{};
        void gcMark(){
          bbGCMarkPtr(l_sib);
        }
      }f2{};
      f2.l_sib=f0.l_parent->m__0left;
      if((f2.l_sib->m__0color==0)){
        f2.l_sib->m__0color=1;
        f0.l_parent->m__0color=0;
        this->m_RotateRight(f0.l_parent);
        f2.l_sib=f0.l_parent->m__0left;
      }
      if(((!bbBool(f2.l_sib->m__0right)||(f2.l_sib->m__0right->m__0color==1))&&(!bbBool(f2.l_sib->m__0left)||(f2.l_sib->m__0left->m__0color==1)))){
        f2.l_sib->m__0color=0;
        f0.l_node=f0.l_parent;
        f0.l_parent=f0.l_parent->m__0parent;
      }else{
        if((!bbBool(f2.l_sib->m__0left)||(f2.l_sib->m__0left->m__0color==1))){
          f2.l_sib->m__0right->m__0color=1;
          f2.l_sib->m__0color=0;
          this->m_RotateLeft(f2.l_sib);
          f2.l_sib=f0.l_parent->m__0left;
        }
        f2.l_sib->m__0color=f0.l_parent->m__0color;
        f0.l_parent->m__0color=1;
        f2.l_sib->m__0left->m__0color=1;
        this->m_RotateRight(f0.l_parent);
        f0.l_node=this->m__0root;
      }
    }
  }
  if(bbBool(f0.l_node)){
    f0.l_node->m__0color=1;
  }
}

bbInt t_std_collections_Map_1sTt_std_collections_Stack_1s_2::m_Count(){
  if(!bbBool(this->m__0root)){
    return bbInt(0);
  }
  return this->m__0root->m_Count(bbInt(0));
}

t_std_collections_Map_1sTt_std_collections_Stack_1s_2* t_std_collections_Map_1sTt_std_collections_Stack_1s_2::m_Copy(){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1sTt_std_collections_Stack_1s_2_Node* l_root{};
    void gcMark(){
      bbGCMarkPtr(l_root);
    }
  }f0{};
  if(bbBool(this->m__0root)){
    f0.l_root=this->m__0root->m_Copy(((t_std_collections_Map_1sTt_std_collections_Stack_1s_2_Node*)0));
  }
  return bbGCNew<t_std_collections_Map_1sTt_std_collections_Stack_1s_2>(f0.l_root);
}

bbBool t_std_collections_Map_1sTt_std_collections_Stack_1s_2::m_Contains(bbString l_key){
  return (this->m_FindNode(l_key)!=((t_std_collections_Map_1sTt_std_collections_Stack_1s_2_Node*)0));
}

void t_std_collections_Map_1sTt_std_collections_Stack_1s_2::m_Clear(){
  this->m__0root=((t_std_collections_Map_1sTt_std_collections_Stack_1s_2_Node*)0);
}

t_std_collections_Map_1sTt_std_collections_Stack_1s_2_Iterator t_std_collections_Map_1sTt_std_collections_Stack_1s_2::m_All(){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1sTt_std_collections_Stack_1s_2_Node* t0{};
    void gcMark(){
      bbGCMarkPtr(t0);
    }
  }f0{};
  return t_std_collections_Map_1sTt_std_collections_Stack_1s_2_Iterator(f0.t0=this->m_FirstNode());
}

bbBool t_std_collections_Map_1sTt_std_collections_Stack_1s_2::m_Add(bbString l_key,t_std_collections_Stack_1s* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1sTt_std_collections_Stack_1s_2_Node* l_node{};
    t_std_collections_Map_1sTt_std_collections_Stack_1s_2_Node* l_parent{};
    void gcMark(){
      bbGCMarkPtr(l_node);
      bbGCMarkPtr(l_parent);
    }
  }f0{};
  if(!bbBool(this->m__0root)){
    this->m__0root=bbGCNew<t_std_collections_Map_1sTt_std_collections_Stack_1s_2_Node>(l_key,l_value,0,((t_std_collections_Map_1sTt_std_collections_Stack_1s_2_Node*)0));
    return true;
  }
  f0.l_node=this->m__0root;
  bbInt l_cmp{};
  while(bbBool(f0.l_node)){
    f0.l_parent=f0.l_node;
    l_cmp=bbCompare(l_key,f0.l_node->m__0key);
    if((l_cmp>bbInt(0))){
      f0.l_node=f0.l_node->m__0right;
    }else if((l_cmp<bbInt(0))){
      f0.l_node=f0.l_node->m__0left;
    }else{
      return false;
    }
  }
  f0.l_node=bbGCNew<t_std_collections_Map_1sTt_std_collections_Stack_1s_2_Node>(l_key,l_value,0,f0.l_parent);
  if((l_cmp>bbInt(0))){
    f0.l_parent->m__0right=f0.l_node;
  }else{
    f0.l_parent->m__0left=f0.l_node;
  }
  this->m_InsertFixup(f0.l_node);
  return true;
}

void t_std_collections_Map_1ss_Node::gcMark(){
  bbGCMark(m__0left);
  bbGCMark(m__0right);
  bbGCMark(m__0parent);
}

t_std_collections_Map_1ss_Node::t_std_collections_Map_1ss_Node(bbString l_key,bbString l_value,bbInt l_color,t_std_collections_Map_1ss_Node* l_parent){
  this->m__0key=l_key;
  this->m__0value=l_value;
  this->m__0color=l_color;
  this->m__0parent=l_parent;
}

bbString t_std_collections_Map_1ss_Node::m_Value(){
  return this->m__0value;
}

t_std_collections_Map_1ss_Node* t_std_collections_Map_1ss_Node::m_PrevNode(){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1ss_Node* l_node{};
    t_std_collections_Map_1ss_Node* l_parent{};
    void gcMark(){
      bbGCMarkPtr(l_node);
      bbGCMarkPtr(l_parent);
    }
  }f0{};
  if(bbBool(this->m__0left)){
    struct f1_t : public bbGCFrame{
      t_std_collections_Map_1ss_Node* l_node{};
      void gcMark(){
        bbGCMarkPtr(l_node);
      }
    }f1{};
    f1.l_node=this->m__0left;
    while(bbBool(f1.l_node->m__0right)){
      f1.l_node=f1.l_node->m__0right;
    }
    return f1.l_node;
  }
  f0.l_node=this;
  f0.l_parent=this->m__0parent;
  while((bbBool(f0.l_parent)&&(f0.l_node==f0.l_parent->m__0left))){
    f0.l_node=f0.l_parent;
    f0.l_parent=f0.l_parent->m__0parent;
  }
  return f0.l_parent;
}

t_std_collections_Map_1ss_Node* t_std_collections_Map_1ss_Node::m_NextNode(){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1ss_Node* l_node{};
    t_std_collections_Map_1ss_Node* l_parent{};
    void gcMark(){
      bbGCMarkPtr(l_node);
      bbGCMarkPtr(l_parent);
    }
  }f0{};
  if(bbBool(this->m__0right)){
    struct f1_t : public bbGCFrame{
      t_std_collections_Map_1ss_Node* l_node{};
      void gcMark(){
        bbGCMarkPtr(l_node);
      }
    }f1{};
    f1.l_node=this->m__0right;
    while(bbBool(f1.l_node->m__0left)){
      f1.l_node=f1.l_node->m__0left;
    }
    return f1.l_node;
  }
  f0.l_node=this;
  f0.l_parent=this->m__0parent;
  while((bbBool(f0.l_parent)&&(f0.l_node==f0.l_parent->m__0right))){
    f0.l_node=f0.l_parent;
    f0.l_parent=f0.l_parent->m__0parent;
  }
  return f0.l_parent;
}

bbString t_std_collections_Map_1ss_Node::m_Key(){
  return this->m__0key;
}

bbInt t_std_collections_Map_1ss_Node::m_Count(bbInt l_n){
  if(bbBool(this->m__0left)){
    l_n=this->m__0left->m_Count(l_n);
  }
  if(bbBool(this->m__0right)){
    l_n=this->m__0right->m_Count(l_n);
  }
  return (l_n+1);
}

t_std_collections_Map_1ss_Node* t_std_collections_Map_1ss_Node::m_Copy(t_std_collections_Map_1ss_Node* l_parent){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1ss_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=bbGCNew<t_std_collections_Map_1ss_Node>(this->m__0key,this->m__0value,this->m__0color,l_parent);
  if(bbBool(this->m__0left)){
    f0.l_node->m__0left=this->m__0left->m_Copy(f0.l_node);
  }
  if(bbBool(this->m__0right)){
    f0.l_node->m__0right=this->m__0right->m_Copy(f0.l_node);
  }
  return f0.l_node;
}

t_std_collections_Map_1ss_Iterator::t_std_collections_Map_1ss_Iterator(t_std_collections_Map_1ss_Node* l_node){
  (*this).m__0node=l_node;
}

bbBool t_std_collections_Map_1ss_Iterator::m_Valid(){
  return bbBool((*this).m__0node);
}

t_std_collections_Map_1ss_Node* t_std_collections_Map_1ss_Iterator::m_Current(){
  return (*this).m__0node;
}

void t_std_collections_Map_1ss_Iterator::m_Bump(){
  (*this).m__0node=(*this).m__0node->m_NextNode();
}

int bbCompare(const t_std_collections_Map_1ss_Iterator&x,const t_std_collections_Map_1ss_Iterator&y){
  if(int t=bbCompare(x.m__0node,y.m__0node)) return t;
  return 0;
}

void bbGCMark(const t_std_collections_Map_1ss_Iterator&t){
  bbGCMark(t.m__0node);
}

t_std_collections_Map_1ss_KeyIterator::t_std_collections_Map_1ss_KeyIterator(t_std_collections_Map_1ss_Node* l_node){
  (*this).m__0node=l_node;
}

bbBool t_std_collections_Map_1ss_KeyIterator::m_Valid(){
  return bbBool((*this).m__0node);
}

bbString t_std_collections_Map_1ss_KeyIterator::m_Current(){
  return (*this).m__0node->m__0key;
}

void t_std_collections_Map_1ss_KeyIterator::m_Bump(){
  (*this).m__0node=(*this).m__0node->m_NextNode();
}

int bbCompare(const t_std_collections_Map_1ss_KeyIterator&x,const t_std_collections_Map_1ss_KeyIterator&y){
  if(int t=bbCompare(x.m__0node,y.m__0node)) return t;
  return 0;
}

void bbGCMark(const t_std_collections_Map_1ss_KeyIterator&t){
  bbGCMark(t.m__0node);
}

t_std_collections_Map_1ss_MapKeys::t_std_collections_Map_1ss_MapKeys(t_std_collections_Map_1ss* l_map){
  (*this).m__0map=l_map;
}

t_std_collections_Map_1ss_KeyIterator t_std_collections_Map_1ss_MapKeys::m_All(){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1ss_Node* t0{};
    void gcMark(){
      bbGCMarkPtr(t0);
    }
  }f0{};
  return t_std_collections_Map_1ss_KeyIterator(f0.t0=(*this).m__0map->m_FirstNode());
}

int bbCompare(const t_std_collections_Map_1ss_MapKeys&x,const t_std_collections_Map_1ss_MapKeys&y){
  if(int t=bbCompare(x.m__0map,y.m__0map)) return t;
  return 0;
}

void bbGCMark(const t_std_collections_Map_1ss_MapKeys&t){
  bbGCMark(t.m__0map);
}

t_std_collections_Map_1ss_ValueIterator::t_std_collections_Map_1ss_ValueIterator(t_std_collections_Map_1ss_Node* l_node){
  (*this).m__0node=l_node;
}

bbBool t_std_collections_Map_1ss_ValueIterator::m_Valid(){
  return bbBool((*this).m__0node);
}

bbString t_std_collections_Map_1ss_ValueIterator::m_Current(){
  return (*this).m__0node->m__0value;
}

void t_std_collections_Map_1ss_ValueIterator::m_Bump(){
  (*this).m__0node=(*this).m__0node->m_NextNode();
}

int bbCompare(const t_std_collections_Map_1ss_ValueIterator&x,const t_std_collections_Map_1ss_ValueIterator&y){
  if(int t=bbCompare(x.m__0node,y.m__0node)) return t;
  return 0;
}

void bbGCMark(const t_std_collections_Map_1ss_ValueIterator&t){
  bbGCMark(t.m__0node);
}

t_std_collections_Map_1ss_MapValues::t_std_collections_Map_1ss_MapValues(t_std_collections_Map_1ss* l_map){
  (*this).m__0map=l_map;
}

t_std_collections_Map_1ss_ValueIterator t_std_collections_Map_1ss_MapValues::m_All(){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1ss_Node* t0{};
    void gcMark(){
      bbGCMarkPtr(t0);
    }
  }f0{};
  return t_std_collections_Map_1ss_ValueIterator(f0.t0=(*this).m__0map->m_FirstNode());
}

int bbCompare(const t_std_collections_Map_1ss_MapValues&x,const t_std_collections_Map_1ss_MapValues&y){
  if(int t=bbCompare(x.m__0map,y.m__0map)) return t;
  return 0;
}

void bbGCMark(const t_std_collections_Map_1ss_MapValues&t){
  bbGCMark(t.m__0map);
}

void t_std_collections_Map_1ss::gcMark(){
  bbGCMark(m__0root);
}

t_std_collections_Map_1ss::t_std_collections_Map_1ss(t_std_collections_Map_1ss_Node* l_root){
  this->m__0root=l_root;
}

t_std_collections_Map_1ss::t_std_collections_Map_1ss(){
}

void t_std_collections_Map_1ss::m__idxeq(bbString l_key,bbString l_value){
  this->m_Set(l_key,l_value);
}

bbString t_std_collections_Map_1ss::m__idx(bbString l_key){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1ss_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m_FindNode(l_key);
  if(!bbBool(f0.l_node)){
    return bbString{};
  }
  return f0.l_node->m__0value;
}

t_std_collections_Map_1ss_MapValues t_std_collections_Map_1ss::m_Values(){
  return t_std_collections_Map_1ss_MapValues(this);
}

bbBool t_std_collections_Map_1ss::m_Update(bbString l_key,bbString l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1ss_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m_FindNode(l_key);
  if(!bbBool(f0.l_node)){
    return false;
  }
  f0.l_node->m__0value=l_value;
  return true;
}

bbBool t_std_collections_Map_1ss::m_Set(bbString l_key,bbString l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1ss_Node* l_node{};
    t_std_collections_Map_1ss_Node* l_parent{};
    void gcMark(){
      bbGCMarkPtr(l_node);
      bbGCMarkPtr(l_parent);
    }
  }f0{};
  if(!bbBool(this->m__0root)){
    this->m__0root=bbGCNew<t_std_collections_Map_1ss_Node>(l_key,l_value,0,((t_std_collections_Map_1ss_Node*)0));
    return true;
  }
  f0.l_node=this->m__0root;
  bbInt l_cmp{};
  while(bbBool(f0.l_node)){
    f0.l_parent=f0.l_node;
    l_cmp=bbCompare(l_key,f0.l_node->m__0key);
    if((l_cmp>bbInt(0))){
      f0.l_node=f0.l_node->m__0right;
    }else if((l_cmp<bbInt(0))){
      f0.l_node=f0.l_node->m__0left;
    }else{
      f0.l_node->m__0value=l_value;
      return false;
    }
  }
  f0.l_node=bbGCNew<t_std_collections_Map_1ss_Node>(l_key,l_value,0,f0.l_parent);
  if((l_cmp>bbInt(0))){
    f0.l_parent->m__0right=f0.l_node;
  }else{
    f0.l_parent->m__0left=f0.l_node;
  }
  this->m_InsertFixup(f0.l_node);
  return true;
}

void t_std_collections_Map_1ss::m_RotateRight(t_std_collections_Map_1ss_Node* l_node){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1ss_Node* l_child{};
    void gcMark(){
      bbGCMarkPtr(l_child);
    }
  }f0{};
  f0.l_child=l_node->m__0left;
  l_node->m__0left=f0.l_child->m__0right;
  if(bbBool(f0.l_child->m__0right)){
    f0.l_child->m__0right->m__0parent=l_node;
  }
  f0.l_child->m__0parent=l_node->m__0parent;
  if(bbBool(l_node->m__0parent)){
    if((l_node==l_node->m__0parent->m__0right)){
      l_node->m__0parent->m__0right=f0.l_child;
    }else{
      l_node->m__0parent->m__0left=f0.l_child;
    }
  }else{
    this->m__0root=f0.l_child;
  }
  f0.l_child->m__0right=l_node;
  l_node->m__0parent=f0.l_child;
}

void t_std_collections_Map_1ss::m_RotateLeft(t_std_collections_Map_1ss_Node* l_node){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1ss_Node* l_child{};
    void gcMark(){
      bbGCMarkPtr(l_child);
    }
  }f0{};
  f0.l_child=l_node->m__0right;
  l_node->m__0right=f0.l_child->m__0left;
  if(bbBool(f0.l_child->m__0left)){
    f0.l_child->m__0left->m__0parent=l_node;
  }
  f0.l_child->m__0parent=l_node->m__0parent;
  if(bbBool(l_node->m__0parent)){
    if((l_node==l_node->m__0parent->m__0left)){
      l_node->m__0parent->m__0left=f0.l_child;
    }else{
      l_node->m__0parent->m__0right=f0.l_child;
    }
  }else{
    this->m__0root=f0.l_child;
  }
  f0.l_child->m__0left=l_node;
  l_node->m__0parent=f0.l_child;
}

void t_std_collections_Map_1ss::m_RemoveNode(t_std_collections_Map_1ss_Node* l_node){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1ss_Node* l_child{};
    t_std_collections_Map_1ss_Node* l_parent{};
    t_std_collections_Map_1ss_Node* l_splice{};
    void gcMark(){
      bbGCMarkPtr(l_child);
      bbGCMarkPtr(l_parent);
      bbGCMarkPtr(l_splice);
    }
  }f0{};
  if(!bbBool(l_node->m__0left)){
    f0.l_splice=l_node;
    f0.l_child=l_node->m__0right;
  }else if(!bbBool(l_node->m__0right)){
    f0.l_splice=l_node;
    f0.l_child=l_node->m__0left;
  }else{
    f0.l_splice=l_node->m__0left;
    while(bbBool(f0.l_splice->m__0right)){
      f0.l_splice=f0.l_splice->m__0right;
    }
    f0.l_child=f0.l_splice->m__0left;
    l_node->m__0key=f0.l_splice->m__0key;
    l_node->m__0value=f0.l_splice->m__0value;
  }
  f0.l_parent=f0.l_splice->m__0parent;
  if(bbBool(f0.l_child)){
    f0.l_child->m__0parent=f0.l_parent;
  }
  if(!bbBool(f0.l_parent)){
    this->m__0root=f0.l_child;
    return;
  }
  if((f0.l_splice==f0.l_parent->m__0left)){
    f0.l_parent->m__0left=f0.l_child;
  }else{
    f0.l_parent->m__0right=f0.l_child;
  }
  if((f0.l_splice->m__0color==1)){
    this->m_DeleteFixup(f0.l_child,f0.l_parent);
  }
}

bbBool t_std_collections_Map_1ss::m_Remove(bbString l_key){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1ss_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m_FindNode(l_key);
  if(!bbBool(f0.l_node)){
    return false;
  }
  this->m_RemoveNode(f0.l_node);
  return true;
}

t_std_collections_Map_1ss_Node* t_std_collections_Map_1ss::m_LastNode(){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1ss_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  if(!bbBool(this->m__0root)){
    return ((t_std_collections_Map_1ss_Node*)0);
  }
  f0.l_node=this->m__0root;
  while(bbBool(f0.l_node->m__0right)){
    f0.l_node=f0.l_node->m__0right;
  }
  return f0.l_node;
}

t_std_collections_Map_1ss_MapKeys t_std_collections_Map_1ss::m_Keys(){
  return t_std_collections_Map_1ss_MapKeys(this);
}

void t_std_collections_Map_1ss::m_InsertFixup(t_std_collections_Map_1ss_Node* l_node){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1ss_Node* l_node{};
    f0_t(t_std_collections_Map_1ss_Node* l_node):l_node(l_node){
    }
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{l_node};
  while(((bbBool(f0.l_node->m__0parent)&&(f0.l_node->m__0parent->m__0color==0))&&bbBool(f0.l_node->m__0parent->m__0parent))){
    if((f0.l_node->m__0parent==f0.l_node->m__0parent->m__0parent->m__0left)){
      struct f2_t : public bbGCFrame{
        t_std_collections_Map_1ss_Node* l_uncle{};
        void gcMark(){
          bbGCMarkPtr(l_uncle);
        }
      }f2{};
      f2.l_uncle=f0.l_node->m__0parent->m__0parent->m__0right;
      if((bbBool(f2.l_uncle)&&(f2.l_uncle->m__0color==0))){
        f0.l_node->m__0parent->m__0color=1;
        f2.l_uncle->m__0color=1;
        f2.l_uncle->m__0parent->m__0color=0;
        f0.l_node=f2.l_uncle->m__0parent;
      }else{
        if((f0.l_node==f0.l_node->m__0parent->m__0right)){
          f0.l_node=f0.l_node->m__0parent;
          this->m_RotateLeft(f0.l_node);
        }
        f0.l_node->m__0parent->m__0color=1;
        f0.l_node->m__0parent->m__0parent->m__0color=0;
        this->m_RotateRight(f0.l_node->m__0parent->m__0parent);
      }
    }else{
      struct f2_t : public bbGCFrame{
        t_std_collections_Map_1ss_Node* l_uncle{};
        void gcMark(){
          bbGCMarkPtr(l_uncle);
        }
      }f2{};
      f2.l_uncle=f0.l_node->m__0parent->m__0parent->m__0left;
      if((bbBool(f2.l_uncle)&&(f2.l_uncle->m__0color==0))){
        f0.l_node->m__0parent->m__0color=1;
        f2.l_uncle->m__0color=1;
        f2.l_uncle->m__0parent->m__0color=0;
        f0.l_node=f2.l_uncle->m__0parent;
      }else{
        if((f0.l_node==f0.l_node->m__0parent->m__0left)){
          f0.l_node=f0.l_node->m__0parent;
          this->m_RotateRight(f0.l_node);
        }
        f0.l_node->m__0parent->m__0color=1;
        f0.l_node->m__0parent->m__0parent->m__0color=0;
        this->m_RotateLeft(f0.l_node->m__0parent->m__0parent);
      }
    }
  }
  this->m__0root->m__0color=1;
}

bbString t_std_collections_Map_1ss::m_Get(bbString l_key){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1ss_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m_FindNode(l_key);
  if(bbBool(f0.l_node)){
    return f0.l_node->m__0value;
  }
  return bbString{};
}

t_std_collections_Map_1ss_Node* t_std_collections_Map_1ss::m_FirstNode(){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1ss_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  if(!bbBool(this->m__0root)){
    return ((t_std_collections_Map_1ss_Node*)0);
  }
  f0.l_node=this->m__0root;
  while(bbBool(f0.l_node->m__0left)){
    f0.l_node=f0.l_node->m__0left;
  }
  return f0.l_node;
}

t_std_collections_Map_1ss_Node* t_std_collections_Map_1ss::m_FindNode(bbString l_key){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1ss_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m__0root;
  while(bbBool(f0.l_node)){
    bbInt l_cmp=bbCompare(l_key,f0.l_node->m__0key);
    if((l_cmp>bbInt(0))){
      f0.l_node=f0.l_node->m__0right;
    }else if((l_cmp<bbInt(0))){
      f0.l_node=f0.l_node->m__0left;
    }else{
      return f0.l_node;
    }
  }
  return ((t_std_collections_Map_1ss_Node*)0);
}

bbBool t_std_collections_Map_1ss::m_Empty(){
  return (this->m__0root==((t_std_collections_Map_1ss_Node*)0));
}

void t_std_collections_Map_1ss::m_DeleteFixup(t_std_collections_Map_1ss_Node* l_node,t_std_collections_Map_1ss_Node* l_parent){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1ss_Node* l_node{};
    t_std_collections_Map_1ss_Node* l_parent{};
    f0_t(t_std_collections_Map_1ss_Node* l_node,t_std_collections_Map_1ss_Node* l_parent):l_node(l_node),l_parent(l_parent){
    }
    void gcMark(){
      bbGCMarkPtr(l_node);
      bbGCMarkPtr(l_parent);
    }
  }f0{l_node,l_parent};
  while(((f0.l_node!=this->m__0root)&&(!bbBool(f0.l_node)||(f0.l_node->m__0color==1)))){
    if((f0.l_node==f0.l_parent->m__0left)){
      struct f2_t : public bbGCFrame{
        t_std_collections_Map_1ss_Node* l_sib{};
        void gcMark(){
          bbGCMarkPtr(l_sib);
        }
      }f2{};
      f2.l_sib=f0.l_parent->m__0right;
      if((f2.l_sib->m__0color==0)){
        f2.l_sib->m__0color=1;
        f0.l_parent->m__0color=0;
        this->m_RotateLeft(f0.l_parent);
        f2.l_sib=f0.l_parent->m__0right;
      }
      if(((!bbBool(f2.l_sib->m__0left)||(f2.l_sib->m__0left->m__0color==1))&&(!bbBool(f2.l_sib->m__0right)||(f2.l_sib->m__0right->m__0color==1)))){
        f2.l_sib->m__0color=0;
        f0.l_node=f0.l_parent;
        f0.l_parent=f0.l_parent->m__0parent;
      }else{
        if((!bbBool(f2.l_sib->m__0right)||(f2.l_sib->m__0right->m__0color==1))){
          f2.l_sib->m__0left->m__0color=1;
          f2.l_sib->m__0color=0;
          this->m_RotateRight(f2.l_sib);
          f2.l_sib=f0.l_parent->m__0right;
        }
        f2.l_sib->m__0color=f0.l_parent->m__0color;
        f0.l_parent->m__0color=1;
        f2.l_sib->m__0right->m__0color=1;
        this->m_RotateLeft(f0.l_parent);
        f0.l_node=this->m__0root;
      }
    }else{
      struct f2_t : public bbGCFrame{
        t_std_collections_Map_1ss_Node* l_sib{};
        void gcMark(){
          bbGCMarkPtr(l_sib);
        }
      }f2{};
      f2.l_sib=f0.l_parent->m__0left;
      if((f2.l_sib->m__0color==0)){
        f2.l_sib->m__0color=1;
        f0.l_parent->m__0color=0;
        this->m_RotateRight(f0.l_parent);
        f2.l_sib=f0.l_parent->m__0left;
      }
      if(((!bbBool(f2.l_sib->m__0right)||(f2.l_sib->m__0right->m__0color==1))&&(!bbBool(f2.l_sib->m__0left)||(f2.l_sib->m__0left->m__0color==1)))){
        f2.l_sib->m__0color=0;
        f0.l_node=f0.l_parent;
        f0.l_parent=f0.l_parent->m__0parent;
      }else{
        if((!bbBool(f2.l_sib->m__0left)||(f2.l_sib->m__0left->m__0color==1))){
          f2.l_sib->m__0right->m__0color=1;
          f2.l_sib->m__0color=0;
          this->m_RotateLeft(f2.l_sib);
          f2.l_sib=f0.l_parent->m__0left;
        }
        f2.l_sib->m__0color=f0.l_parent->m__0color;
        f0.l_parent->m__0color=1;
        f2.l_sib->m__0left->m__0color=1;
        this->m_RotateRight(f0.l_parent);
        f0.l_node=this->m__0root;
      }
    }
  }
  if(bbBool(f0.l_node)){
    f0.l_node->m__0color=1;
  }
}

bbInt t_std_collections_Map_1ss::m_Count(){
  if(!bbBool(this->m__0root)){
    return bbInt(0);
  }
  return this->m__0root->m_Count(bbInt(0));
}

t_std_collections_Map_1ss* t_std_collections_Map_1ss::m_Copy(){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1ss_Node* l_root{};
    void gcMark(){
      bbGCMarkPtr(l_root);
    }
  }f0{};
  if(bbBool(this->m__0root)){
    f0.l_root=this->m__0root->m_Copy(((t_std_collections_Map_1ss_Node*)0));
  }
  return bbGCNew<t_std_collections_Map_1ss>(f0.l_root);
}

bbBool t_std_collections_Map_1ss::m_Contains(bbString l_key){
  return (this->m_FindNode(l_key)!=((t_std_collections_Map_1ss_Node*)0));
}

void t_std_collections_Map_1ss::m_Clear(){
  this->m__0root=((t_std_collections_Map_1ss_Node*)0);
}

t_std_collections_Map_1ss_Iterator t_std_collections_Map_1ss::m_All(){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1ss_Node* t0{};
    void gcMark(){
      bbGCMarkPtr(t0);
    }
  }f0{};
  return t_std_collections_Map_1ss_Iterator(f0.t0=this->m_FirstNode());
}

bbBool t_std_collections_Map_1ss::m_Add(bbString l_key,bbString l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1ss_Node* l_node{};
    t_std_collections_Map_1ss_Node* l_parent{};
    void gcMark(){
      bbGCMarkPtr(l_node);
      bbGCMarkPtr(l_parent);
    }
  }f0{};
  if(!bbBool(this->m__0root)){
    this->m__0root=bbGCNew<t_std_collections_Map_1ss_Node>(l_key,l_value,0,((t_std_collections_Map_1ss_Node*)0));
    return true;
  }
  f0.l_node=this->m__0root;
  bbInt l_cmp{};
  while(bbBool(f0.l_node)){
    f0.l_parent=f0.l_node;
    l_cmp=bbCompare(l_key,f0.l_node->m__0key);
    if((l_cmp>bbInt(0))){
      f0.l_node=f0.l_node->m__0right;
    }else if((l_cmp<bbInt(0))){
      f0.l_node=f0.l_node->m__0left;
    }else{
      return false;
    }
  }
  f0.l_node=bbGCNew<t_std_collections_Map_1ss_Node>(l_key,l_value,0,f0.l_parent);
  if((l_cmp>bbInt(0))){
    f0.l_parent->m__0right=f0.l_node;
  }else{
    f0.l_parent->m__0left=f0.l_node;
  }
  this->m_InsertFixup(f0.l_node);
  return true;
}

void t_std_collections_Map_1sz_Node::gcMark(){
  bbGCMark(m__0left);
  bbGCMark(m__0right);
  bbGCMark(m__0parent);
}

t_std_collections_Map_1sz_Node::t_std_collections_Map_1sz_Node(bbString l_key,bbBool l_value,bbInt l_color,t_std_collections_Map_1sz_Node* l_parent){
  this->m__0key=l_key;
  this->m__0value=l_value;
  this->m__0color=l_color;
  this->m__0parent=l_parent;
}

bbBool t_std_collections_Map_1sz_Node::m_Value(){
  return this->m__0value;
}

t_std_collections_Map_1sz_Node* t_std_collections_Map_1sz_Node::m_PrevNode(){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1sz_Node* l_node{};
    t_std_collections_Map_1sz_Node* l_parent{};
    void gcMark(){
      bbGCMarkPtr(l_node);
      bbGCMarkPtr(l_parent);
    }
  }f0{};
  if(bbBool(this->m__0left)){
    struct f1_t : public bbGCFrame{
      t_std_collections_Map_1sz_Node* l_node{};
      void gcMark(){
        bbGCMarkPtr(l_node);
      }
    }f1{};
    f1.l_node=this->m__0left;
    while(bbBool(f1.l_node->m__0right)){
      f1.l_node=f1.l_node->m__0right;
    }
    return f1.l_node;
  }
  f0.l_node=this;
  f0.l_parent=this->m__0parent;
  while((bbBool(f0.l_parent)&&(f0.l_node==f0.l_parent->m__0left))){
    f0.l_node=f0.l_parent;
    f0.l_parent=f0.l_parent->m__0parent;
  }
  return f0.l_parent;
}

t_std_collections_Map_1sz_Node* t_std_collections_Map_1sz_Node::m_NextNode(){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1sz_Node* l_node{};
    t_std_collections_Map_1sz_Node* l_parent{};
    void gcMark(){
      bbGCMarkPtr(l_node);
      bbGCMarkPtr(l_parent);
    }
  }f0{};
  if(bbBool(this->m__0right)){
    struct f1_t : public bbGCFrame{
      t_std_collections_Map_1sz_Node* l_node{};
      void gcMark(){
        bbGCMarkPtr(l_node);
      }
    }f1{};
    f1.l_node=this->m__0right;
    while(bbBool(f1.l_node->m__0left)){
      f1.l_node=f1.l_node->m__0left;
    }
    return f1.l_node;
  }
  f0.l_node=this;
  f0.l_parent=this->m__0parent;
  while((bbBool(f0.l_parent)&&(f0.l_node==f0.l_parent->m__0right))){
    f0.l_node=f0.l_parent;
    f0.l_parent=f0.l_parent->m__0parent;
  }
  return f0.l_parent;
}

bbString t_std_collections_Map_1sz_Node::m_Key(){
  return this->m__0key;
}

bbInt t_std_collections_Map_1sz_Node::m_Count(bbInt l_n){
  if(bbBool(this->m__0left)){
    l_n=this->m__0left->m_Count(l_n);
  }
  if(bbBool(this->m__0right)){
    l_n=this->m__0right->m_Count(l_n);
  }
  return (l_n+1);
}

t_std_collections_Map_1sz_Node* t_std_collections_Map_1sz_Node::m_Copy(t_std_collections_Map_1sz_Node* l_parent){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1sz_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=bbGCNew<t_std_collections_Map_1sz_Node>(this->m__0key,this->m__0value,this->m__0color,l_parent);
  if(bbBool(this->m__0left)){
    f0.l_node->m__0left=this->m__0left->m_Copy(f0.l_node);
  }
  if(bbBool(this->m__0right)){
    f0.l_node->m__0right=this->m__0right->m_Copy(f0.l_node);
  }
  return f0.l_node;
}

t_std_collections_Map_1sz_Iterator::t_std_collections_Map_1sz_Iterator(t_std_collections_Map_1sz_Node* l_node){
  (*this).m__0node=l_node;
}

bbBool t_std_collections_Map_1sz_Iterator::m_Valid(){
  return bbBool((*this).m__0node);
}

t_std_collections_Map_1sz_Node* t_std_collections_Map_1sz_Iterator::m_Current(){
  return (*this).m__0node;
}

void t_std_collections_Map_1sz_Iterator::m_Bump(){
  (*this).m__0node=(*this).m__0node->m_NextNode();
}

int bbCompare(const t_std_collections_Map_1sz_Iterator&x,const t_std_collections_Map_1sz_Iterator&y){
  if(int t=bbCompare(x.m__0node,y.m__0node)) return t;
  return 0;
}

void bbGCMark(const t_std_collections_Map_1sz_Iterator&t){
  bbGCMark(t.m__0node);
}

t_std_collections_Map_1sz_KeyIterator::t_std_collections_Map_1sz_KeyIterator(t_std_collections_Map_1sz_Node* l_node){
  (*this).m__0node=l_node;
}

bbBool t_std_collections_Map_1sz_KeyIterator::m_Valid(){
  return bbBool((*this).m__0node);
}

bbString t_std_collections_Map_1sz_KeyIterator::m_Current(){
  return (*this).m__0node->m__0key;
}

void t_std_collections_Map_1sz_KeyIterator::m_Bump(){
  (*this).m__0node=(*this).m__0node->m_NextNode();
}

int bbCompare(const t_std_collections_Map_1sz_KeyIterator&x,const t_std_collections_Map_1sz_KeyIterator&y){
  if(int t=bbCompare(x.m__0node,y.m__0node)) return t;
  return 0;
}

void bbGCMark(const t_std_collections_Map_1sz_KeyIterator&t){
  bbGCMark(t.m__0node);
}

t_std_collections_Map_1sz_MapKeys::t_std_collections_Map_1sz_MapKeys(t_std_collections_Map_1sz* l_map){
  (*this).m__0map=l_map;
}

t_std_collections_Map_1sz_KeyIterator t_std_collections_Map_1sz_MapKeys::m_All(){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1sz_Node* t0{};
    void gcMark(){
      bbGCMarkPtr(t0);
    }
  }f0{};
  return t_std_collections_Map_1sz_KeyIterator(f0.t0=(*this).m__0map->m_FirstNode());
}

int bbCompare(const t_std_collections_Map_1sz_MapKeys&x,const t_std_collections_Map_1sz_MapKeys&y){
  if(int t=bbCompare(x.m__0map,y.m__0map)) return t;
  return 0;
}

void bbGCMark(const t_std_collections_Map_1sz_MapKeys&t){
  bbGCMark(t.m__0map);
}

t_std_collections_Map_1sz_ValueIterator::t_std_collections_Map_1sz_ValueIterator(t_std_collections_Map_1sz_Node* l_node){
  (*this).m__0node=l_node;
}

bbBool t_std_collections_Map_1sz_ValueIterator::m_Valid(){
  return bbBool((*this).m__0node);
}

bbBool t_std_collections_Map_1sz_ValueIterator::m_Current(){
  return (*this).m__0node->m__0value;
}

void t_std_collections_Map_1sz_ValueIterator::m_Bump(){
  (*this).m__0node=(*this).m__0node->m_NextNode();
}

int bbCompare(const t_std_collections_Map_1sz_ValueIterator&x,const t_std_collections_Map_1sz_ValueIterator&y){
  if(int t=bbCompare(x.m__0node,y.m__0node)) return t;
  return 0;
}

void bbGCMark(const t_std_collections_Map_1sz_ValueIterator&t){
  bbGCMark(t.m__0node);
}

t_std_collections_Map_1sz_MapValues::t_std_collections_Map_1sz_MapValues(t_std_collections_Map_1sz* l_map){
  (*this).m__0map=l_map;
}

t_std_collections_Map_1sz_ValueIterator t_std_collections_Map_1sz_MapValues::m_All(){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1sz_Node* t0{};
    void gcMark(){
      bbGCMarkPtr(t0);
    }
  }f0{};
  return t_std_collections_Map_1sz_ValueIterator(f0.t0=(*this).m__0map->m_FirstNode());
}

int bbCompare(const t_std_collections_Map_1sz_MapValues&x,const t_std_collections_Map_1sz_MapValues&y){
  if(int t=bbCompare(x.m__0map,y.m__0map)) return t;
  return 0;
}

void bbGCMark(const t_std_collections_Map_1sz_MapValues&t){
  bbGCMark(t.m__0map);
}

void t_std_collections_Map_1sz::gcMark(){
  bbGCMark(m__0root);
}

t_std_collections_Map_1sz::t_std_collections_Map_1sz(t_std_collections_Map_1sz_Node* l_root){
  this->m__0root=l_root;
}

t_std_collections_Map_1sz::t_std_collections_Map_1sz(){
}

void t_std_collections_Map_1sz::m__idxeq(bbString l_key,bbBool l_value){
  this->m_Set(l_key,l_value);
}

bbBool t_std_collections_Map_1sz::m__idx(bbString l_key){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1sz_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m_FindNode(l_key);
  if(!bbBool(f0.l_node)){
    return false;
  }
  return f0.l_node->m__0value;
}

t_std_collections_Map_1sz_MapValues t_std_collections_Map_1sz::m_Values(){
  return t_std_collections_Map_1sz_MapValues(this);
}

bbBool t_std_collections_Map_1sz::m_Update(bbString l_key,bbBool l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1sz_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m_FindNode(l_key);
  if(!bbBool(f0.l_node)){
    return false;
  }
  f0.l_node->m__0value=l_value;
  return true;
}

bbBool t_std_collections_Map_1sz::m_Set(bbString l_key,bbBool l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1sz_Node* l_node{};
    t_std_collections_Map_1sz_Node* l_parent{};
    void gcMark(){
      bbGCMarkPtr(l_node);
      bbGCMarkPtr(l_parent);
    }
  }f0{};
  if(!bbBool(this->m__0root)){
    this->m__0root=bbGCNew<t_std_collections_Map_1sz_Node>(l_key,l_value,0,((t_std_collections_Map_1sz_Node*)0));
    return true;
  }
  f0.l_node=this->m__0root;
  bbInt l_cmp{};
  while(bbBool(f0.l_node)){
    f0.l_parent=f0.l_node;
    l_cmp=bbCompare(l_key,f0.l_node->m__0key);
    if((l_cmp>bbInt(0))){
      f0.l_node=f0.l_node->m__0right;
    }else if((l_cmp<bbInt(0))){
      f0.l_node=f0.l_node->m__0left;
    }else{
      f0.l_node->m__0value=l_value;
      return false;
    }
  }
  f0.l_node=bbGCNew<t_std_collections_Map_1sz_Node>(l_key,l_value,0,f0.l_parent);
  if((l_cmp>bbInt(0))){
    f0.l_parent->m__0right=f0.l_node;
  }else{
    f0.l_parent->m__0left=f0.l_node;
  }
  this->m_InsertFixup(f0.l_node);
  return true;
}

void t_std_collections_Map_1sz::m_RotateRight(t_std_collections_Map_1sz_Node* l_node){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1sz_Node* l_child{};
    void gcMark(){
      bbGCMarkPtr(l_child);
    }
  }f0{};
  f0.l_child=l_node->m__0left;
  l_node->m__0left=f0.l_child->m__0right;
  if(bbBool(f0.l_child->m__0right)){
    f0.l_child->m__0right->m__0parent=l_node;
  }
  f0.l_child->m__0parent=l_node->m__0parent;
  if(bbBool(l_node->m__0parent)){
    if((l_node==l_node->m__0parent->m__0right)){
      l_node->m__0parent->m__0right=f0.l_child;
    }else{
      l_node->m__0parent->m__0left=f0.l_child;
    }
  }else{
    this->m__0root=f0.l_child;
  }
  f0.l_child->m__0right=l_node;
  l_node->m__0parent=f0.l_child;
}

void t_std_collections_Map_1sz::m_RotateLeft(t_std_collections_Map_1sz_Node* l_node){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1sz_Node* l_child{};
    void gcMark(){
      bbGCMarkPtr(l_child);
    }
  }f0{};
  f0.l_child=l_node->m__0right;
  l_node->m__0right=f0.l_child->m__0left;
  if(bbBool(f0.l_child->m__0left)){
    f0.l_child->m__0left->m__0parent=l_node;
  }
  f0.l_child->m__0parent=l_node->m__0parent;
  if(bbBool(l_node->m__0parent)){
    if((l_node==l_node->m__0parent->m__0left)){
      l_node->m__0parent->m__0left=f0.l_child;
    }else{
      l_node->m__0parent->m__0right=f0.l_child;
    }
  }else{
    this->m__0root=f0.l_child;
  }
  f0.l_child->m__0left=l_node;
  l_node->m__0parent=f0.l_child;
}

void t_std_collections_Map_1sz::m_RemoveNode(t_std_collections_Map_1sz_Node* l_node){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1sz_Node* l_child{};
    t_std_collections_Map_1sz_Node* l_parent{};
    t_std_collections_Map_1sz_Node* l_splice{};
    void gcMark(){
      bbGCMarkPtr(l_child);
      bbGCMarkPtr(l_parent);
      bbGCMarkPtr(l_splice);
    }
  }f0{};
  if(!bbBool(l_node->m__0left)){
    f0.l_splice=l_node;
    f0.l_child=l_node->m__0right;
  }else if(!bbBool(l_node->m__0right)){
    f0.l_splice=l_node;
    f0.l_child=l_node->m__0left;
  }else{
    f0.l_splice=l_node->m__0left;
    while(bbBool(f0.l_splice->m__0right)){
      f0.l_splice=f0.l_splice->m__0right;
    }
    f0.l_child=f0.l_splice->m__0left;
    l_node->m__0key=f0.l_splice->m__0key;
    l_node->m__0value=f0.l_splice->m__0value;
  }
  f0.l_parent=f0.l_splice->m__0parent;
  if(bbBool(f0.l_child)){
    f0.l_child->m__0parent=f0.l_parent;
  }
  if(!bbBool(f0.l_parent)){
    this->m__0root=f0.l_child;
    return;
  }
  if((f0.l_splice==f0.l_parent->m__0left)){
    f0.l_parent->m__0left=f0.l_child;
  }else{
    f0.l_parent->m__0right=f0.l_child;
  }
  if((f0.l_splice->m__0color==1)){
    this->m_DeleteFixup(f0.l_child,f0.l_parent);
  }
}

bbBool t_std_collections_Map_1sz::m_Remove(bbString l_key){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1sz_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m_FindNode(l_key);
  if(!bbBool(f0.l_node)){
    return false;
  }
  this->m_RemoveNode(f0.l_node);
  return true;
}

t_std_collections_Map_1sz_Node* t_std_collections_Map_1sz::m_LastNode(){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1sz_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  if(!bbBool(this->m__0root)){
    return ((t_std_collections_Map_1sz_Node*)0);
  }
  f0.l_node=this->m__0root;
  while(bbBool(f0.l_node->m__0right)){
    f0.l_node=f0.l_node->m__0right;
  }
  return f0.l_node;
}

t_std_collections_Map_1sz_MapKeys t_std_collections_Map_1sz::m_Keys(){
  return t_std_collections_Map_1sz_MapKeys(this);
}

void t_std_collections_Map_1sz::m_InsertFixup(t_std_collections_Map_1sz_Node* l_node){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1sz_Node* l_node{};
    f0_t(t_std_collections_Map_1sz_Node* l_node):l_node(l_node){
    }
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{l_node};
  while(((bbBool(f0.l_node->m__0parent)&&(f0.l_node->m__0parent->m__0color==0))&&bbBool(f0.l_node->m__0parent->m__0parent))){
    if((f0.l_node->m__0parent==f0.l_node->m__0parent->m__0parent->m__0left)){
      struct f2_t : public bbGCFrame{
        t_std_collections_Map_1sz_Node* l_uncle{};
        void gcMark(){
          bbGCMarkPtr(l_uncle);
        }
      }f2{};
      f2.l_uncle=f0.l_node->m__0parent->m__0parent->m__0right;
      if((bbBool(f2.l_uncle)&&(f2.l_uncle->m__0color==0))){
        f0.l_node->m__0parent->m__0color=1;
        f2.l_uncle->m__0color=1;
        f2.l_uncle->m__0parent->m__0color=0;
        f0.l_node=f2.l_uncle->m__0parent;
      }else{
        if((f0.l_node==f0.l_node->m__0parent->m__0right)){
          f0.l_node=f0.l_node->m__0parent;
          this->m_RotateLeft(f0.l_node);
        }
        f0.l_node->m__0parent->m__0color=1;
        f0.l_node->m__0parent->m__0parent->m__0color=0;
        this->m_RotateRight(f0.l_node->m__0parent->m__0parent);
      }
    }else{
      struct f2_t : public bbGCFrame{
        t_std_collections_Map_1sz_Node* l_uncle{};
        void gcMark(){
          bbGCMarkPtr(l_uncle);
        }
      }f2{};
      f2.l_uncle=f0.l_node->m__0parent->m__0parent->m__0left;
      if((bbBool(f2.l_uncle)&&(f2.l_uncle->m__0color==0))){
        f0.l_node->m__0parent->m__0color=1;
        f2.l_uncle->m__0color=1;
        f2.l_uncle->m__0parent->m__0color=0;
        f0.l_node=f2.l_uncle->m__0parent;
      }else{
        if((f0.l_node==f0.l_node->m__0parent->m__0left)){
          f0.l_node=f0.l_node->m__0parent;
          this->m_RotateRight(f0.l_node);
        }
        f0.l_node->m__0parent->m__0color=1;
        f0.l_node->m__0parent->m__0parent->m__0color=0;
        this->m_RotateLeft(f0.l_node->m__0parent->m__0parent);
      }
    }
  }
  this->m__0root->m__0color=1;
}

bbBool t_std_collections_Map_1sz::m_Get(bbString l_key){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1sz_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m_FindNode(l_key);
  if(bbBool(f0.l_node)){
    return f0.l_node->m__0value;
  }
  return false;
}

t_std_collections_Map_1sz_Node* t_std_collections_Map_1sz::m_FirstNode(){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1sz_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  if(!bbBool(this->m__0root)){
    return ((t_std_collections_Map_1sz_Node*)0);
  }
  f0.l_node=this->m__0root;
  while(bbBool(f0.l_node->m__0left)){
    f0.l_node=f0.l_node->m__0left;
  }
  return f0.l_node;
}

t_std_collections_Map_1sz_Node* t_std_collections_Map_1sz::m_FindNode(bbString l_key){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1sz_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m__0root;
  while(bbBool(f0.l_node)){
    bbInt l_cmp=bbCompare(l_key,f0.l_node->m__0key);
    if((l_cmp>bbInt(0))){
      f0.l_node=f0.l_node->m__0right;
    }else if((l_cmp<bbInt(0))){
      f0.l_node=f0.l_node->m__0left;
    }else{
      return f0.l_node;
    }
  }
  return ((t_std_collections_Map_1sz_Node*)0);
}

bbBool t_std_collections_Map_1sz::m_Empty(){
  return (this->m__0root==((t_std_collections_Map_1sz_Node*)0));
}

void t_std_collections_Map_1sz::m_DeleteFixup(t_std_collections_Map_1sz_Node* l_node,t_std_collections_Map_1sz_Node* l_parent){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1sz_Node* l_node{};
    t_std_collections_Map_1sz_Node* l_parent{};
    f0_t(t_std_collections_Map_1sz_Node* l_node,t_std_collections_Map_1sz_Node* l_parent):l_node(l_node),l_parent(l_parent){
    }
    void gcMark(){
      bbGCMarkPtr(l_node);
      bbGCMarkPtr(l_parent);
    }
  }f0{l_node,l_parent};
  while(((f0.l_node!=this->m__0root)&&(!bbBool(f0.l_node)||(f0.l_node->m__0color==1)))){
    if((f0.l_node==f0.l_parent->m__0left)){
      struct f2_t : public bbGCFrame{
        t_std_collections_Map_1sz_Node* l_sib{};
        void gcMark(){
          bbGCMarkPtr(l_sib);
        }
      }f2{};
      f2.l_sib=f0.l_parent->m__0right;
      if((f2.l_sib->m__0color==0)){
        f2.l_sib->m__0color=1;
        f0.l_parent->m__0color=0;
        this->m_RotateLeft(f0.l_parent);
        f2.l_sib=f0.l_parent->m__0right;
      }
      if(((!bbBool(f2.l_sib->m__0left)||(f2.l_sib->m__0left->m__0color==1))&&(!bbBool(f2.l_sib->m__0right)||(f2.l_sib->m__0right->m__0color==1)))){
        f2.l_sib->m__0color=0;
        f0.l_node=f0.l_parent;
        f0.l_parent=f0.l_parent->m__0parent;
      }else{
        if((!bbBool(f2.l_sib->m__0right)||(f2.l_sib->m__0right->m__0color==1))){
          f2.l_sib->m__0left->m__0color=1;
          f2.l_sib->m__0color=0;
          this->m_RotateRight(f2.l_sib);
          f2.l_sib=f0.l_parent->m__0right;
        }
        f2.l_sib->m__0color=f0.l_parent->m__0color;
        f0.l_parent->m__0color=1;
        f2.l_sib->m__0right->m__0color=1;
        this->m_RotateLeft(f0.l_parent);
        f0.l_node=this->m__0root;
      }
    }else{
      struct f2_t : public bbGCFrame{
        t_std_collections_Map_1sz_Node* l_sib{};
        void gcMark(){
          bbGCMarkPtr(l_sib);
        }
      }f2{};
      f2.l_sib=f0.l_parent->m__0left;
      if((f2.l_sib->m__0color==0)){
        f2.l_sib->m__0color=1;
        f0.l_parent->m__0color=0;
        this->m_RotateRight(f0.l_parent);
        f2.l_sib=f0.l_parent->m__0left;
      }
      if(((!bbBool(f2.l_sib->m__0right)||(f2.l_sib->m__0right->m__0color==1))&&(!bbBool(f2.l_sib->m__0left)||(f2.l_sib->m__0left->m__0color==1)))){
        f2.l_sib->m__0color=0;
        f0.l_node=f0.l_parent;
        f0.l_parent=f0.l_parent->m__0parent;
      }else{
        if((!bbBool(f2.l_sib->m__0left)||(f2.l_sib->m__0left->m__0color==1))){
          f2.l_sib->m__0right->m__0color=1;
          f2.l_sib->m__0color=0;
          this->m_RotateLeft(f2.l_sib);
          f2.l_sib=f0.l_parent->m__0left;
        }
        f2.l_sib->m__0color=f0.l_parent->m__0color;
        f0.l_parent->m__0color=1;
        f2.l_sib->m__0left->m__0color=1;
        this->m_RotateRight(f0.l_parent);
        f0.l_node=this->m__0root;
      }
    }
  }
  if(bbBool(f0.l_node)){
    f0.l_node->m__0color=1;
  }
}

bbInt t_std_collections_Map_1sz::m_Count(){
  if(!bbBool(this->m__0root)){
    return bbInt(0);
  }
  return this->m__0root->m_Count(bbInt(0));
}

t_std_collections_Map_1sz* t_std_collections_Map_1sz::m_Copy(){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1sz_Node* l_root{};
    void gcMark(){
      bbGCMarkPtr(l_root);
    }
  }f0{};
  if(bbBool(this->m__0root)){
    f0.l_root=this->m__0root->m_Copy(((t_std_collections_Map_1sz_Node*)0));
  }
  return bbGCNew<t_std_collections_Map_1sz>(f0.l_root);
}

bbBool t_std_collections_Map_1sz::m_Contains(bbString l_key){
  return (this->m_FindNode(l_key)!=((t_std_collections_Map_1sz_Node*)0));
}

void t_std_collections_Map_1sz::m_Clear(){
  this->m__0root=((t_std_collections_Map_1sz_Node*)0);
}

t_std_collections_Map_1sz_Iterator t_std_collections_Map_1sz::m_All(){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1sz_Node* t0{};
    void gcMark(){
      bbGCMarkPtr(t0);
    }
  }f0{};
  return t_std_collections_Map_1sz_Iterator(f0.t0=this->m_FirstNode());
}

bbBool t_std_collections_Map_1sz::m_Add(bbString l_key,bbBool l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1sz_Node* l_node{};
    t_std_collections_Map_1sz_Node* l_parent{};
    void gcMark(){
      bbGCMarkPtr(l_node);
      bbGCMarkPtr(l_parent);
    }
  }f0{};
  if(!bbBool(this->m__0root)){
    this->m__0root=bbGCNew<t_std_collections_Map_1sz_Node>(l_key,l_value,0,((t_std_collections_Map_1sz_Node*)0));
    return true;
  }
  f0.l_node=this->m__0root;
  bbInt l_cmp{};
  while(bbBool(f0.l_node)){
    f0.l_parent=f0.l_node;
    l_cmp=bbCompare(l_key,f0.l_node->m__0key);
    if((l_cmp>bbInt(0))){
      f0.l_node=f0.l_node->m__0right;
    }else if((l_cmp<bbInt(0))){
      f0.l_node=f0.l_node->m__0left;
    }else{
      return false;
    }
  }
  f0.l_node=bbGCNew<t_std_collections_Map_1sz_Node>(l_key,l_value,0,f0.l_parent);
  if((l_cmp>bbInt(0))){
    f0.l_parent->m__0right=f0.l_node;
  }else{
    f0.l_parent->m__0left=f0.l_node;
  }
  this->m_InsertFixup(f0.l_node);
  return true;
}

void t_std_collections_Map_1sTt_mx2_Module_2_Node::gcMark(){
  bbGCMark(m__0value);
  bbGCMark(m__0left);
  bbGCMark(m__0right);
  bbGCMark(m__0parent);
}

t_std_collections_Map_1sTt_mx2_Module_2_Node::t_std_collections_Map_1sTt_mx2_Module_2_Node(bbString l_key,t_mx2_Module* l_value,bbInt l_color,t_std_collections_Map_1sTt_mx2_Module_2_Node* l_parent){
  this->m__0key=l_key;
  this->m__0value=l_value;
  this->m__0color=l_color;
  this->m__0parent=l_parent;
}

t_mx2_Module* t_std_collections_Map_1sTt_mx2_Module_2_Node::m_Value(){
  return this->m__0value;
}

t_std_collections_Map_1sTt_mx2_Module_2_Node* t_std_collections_Map_1sTt_mx2_Module_2_Node::m_PrevNode(){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1sTt_mx2_Module_2_Node* l_node{};
    t_std_collections_Map_1sTt_mx2_Module_2_Node* l_parent{};
    void gcMark(){
      bbGCMarkPtr(l_node);
      bbGCMarkPtr(l_parent);
    }
  }f0{};
  if(bbBool(this->m__0left)){
    struct f1_t : public bbGCFrame{
      t_std_collections_Map_1sTt_mx2_Module_2_Node* l_node{};
      void gcMark(){
        bbGCMarkPtr(l_node);
      }
    }f1{};
    f1.l_node=this->m__0left;
    while(bbBool(f1.l_node->m__0right)){
      f1.l_node=f1.l_node->m__0right;
    }
    return f1.l_node;
  }
  f0.l_node=this;
  f0.l_parent=this->m__0parent;
  while((bbBool(f0.l_parent)&&(f0.l_node==f0.l_parent->m__0left))){
    f0.l_node=f0.l_parent;
    f0.l_parent=f0.l_parent->m__0parent;
  }
  return f0.l_parent;
}

t_std_collections_Map_1sTt_mx2_Module_2_Node* t_std_collections_Map_1sTt_mx2_Module_2_Node::m_NextNode(){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1sTt_mx2_Module_2_Node* l_node{};
    t_std_collections_Map_1sTt_mx2_Module_2_Node* l_parent{};
    void gcMark(){
      bbGCMarkPtr(l_node);
      bbGCMarkPtr(l_parent);
    }
  }f0{};
  if(bbBool(this->m__0right)){
    struct f1_t : public bbGCFrame{
      t_std_collections_Map_1sTt_mx2_Module_2_Node* l_node{};
      void gcMark(){
        bbGCMarkPtr(l_node);
      }
    }f1{};
    f1.l_node=this->m__0right;
    while(bbBool(f1.l_node->m__0left)){
      f1.l_node=f1.l_node->m__0left;
    }
    return f1.l_node;
  }
  f0.l_node=this;
  f0.l_parent=this->m__0parent;
  while((bbBool(f0.l_parent)&&(f0.l_node==f0.l_parent->m__0right))){
    f0.l_node=f0.l_parent;
    f0.l_parent=f0.l_parent->m__0parent;
  }
  return f0.l_parent;
}

bbString t_std_collections_Map_1sTt_mx2_Module_2_Node::m_Key(){
  return this->m__0key;
}

bbInt t_std_collections_Map_1sTt_mx2_Module_2_Node::m_Count(bbInt l_n){
  if(bbBool(this->m__0left)){
    l_n=this->m__0left->m_Count(l_n);
  }
  if(bbBool(this->m__0right)){
    l_n=this->m__0right->m_Count(l_n);
  }
  return (l_n+1);
}

t_std_collections_Map_1sTt_mx2_Module_2_Node* t_std_collections_Map_1sTt_mx2_Module_2_Node::m_Copy(t_std_collections_Map_1sTt_mx2_Module_2_Node* l_parent){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1sTt_mx2_Module_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=bbGCNew<t_std_collections_Map_1sTt_mx2_Module_2_Node>(this->m__0key,this->m__0value,this->m__0color,l_parent);
  if(bbBool(this->m__0left)){
    f0.l_node->m__0left=this->m__0left->m_Copy(f0.l_node);
  }
  if(bbBool(this->m__0right)){
    f0.l_node->m__0right=this->m__0right->m_Copy(f0.l_node);
  }
  return f0.l_node;
}

t_std_collections_Map_1sTt_mx2_Module_2_Iterator::t_std_collections_Map_1sTt_mx2_Module_2_Iterator(t_std_collections_Map_1sTt_mx2_Module_2_Node* l_node){
  (*this).m__0node=l_node;
}

bbBool t_std_collections_Map_1sTt_mx2_Module_2_Iterator::m_Valid(){
  return bbBool((*this).m__0node);
}

t_std_collections_Map_1sTt_mx2_Module_2_Node* t_std_collections_Map_1sTt_mx2_Module_2_Iterator::m_Current(){
  return (*this).m__0node;
}

void t_std_collections_Map_1sTt_mx2_Module_2_Iterator::m_Bump(){
  (*this).m__0node=(*this).m__0node->m_NextNode();
}

int bbCompare(const t_std_collections_Map_1sTt_mx2_Module_2_Iterator&x,const t_std_collections_Map_1sTt_mx2_Module_2_Iterator&y){
  if(int t=bbCompare(x.m__0node,y.m__0node)) return t;
  return 0;
}

void bbGCMark(const t_std_collections_Map_1sTt_mx2_Module_2_Iterator&t){
  bbGCMark(t.m__0node);
}

t_std_collections_Map_1sTt_mx2_Module_2_KeyIterator::t_std_collections_Map_1sTt_mx2_Module_2_KeyIterator(t_std_collections_Map_1sTt_mx2_Module_2_Node* l_node){
  (*this).m__0node=l_node;
}

bbBool t_std_collections_Map_1sTt_mx2_Module_2_KeyIterator::m_Valid(){
  return bbBool((*this).m__0node);
}

bbString t_std_collections_Map_1sTt_mx2_Module_2_KeyIterator::m_Current(){
  return (*this).m__0node->m__0key;
}

void t_std_collections_Map_1sTt_mx2_Module_2_KeyIterator::m_Bump(){
  (*this).m__0node=(*this).m__0node->m_NextNode();
}

int bbCompare(const t_std_collections_Map_1sTt_mx2_Module_2_KeyIterator&x,const t_std_collections_Map_1sTt_mx2_Module_2_KeyIterator&y){
  if(int t=bbCompare(x.m__0node,y.m__0node)) return t;
  return 0;
}

void bbGCMark(const t_std_collections_Map_1sTt_mx2_Module_2_KeyIterator&t){
  bbGCMark(t.m__0node);
}

t_std_collections_Map_1sTt_mx2_Module_2_MapKeys::t_std_collections_Map_1sTt_mx2_Module_2_MapKeys(t_std_collections_Map_1sTt_mx2_Module_2* l_map){
  (*this).m__0map=l_map;
}

t_std_collections_Map_1sTt_mx2_Module_2_KeyIterator t_std_collections_Map_1sTt_mx2_Module_2_MapKeys::m_All(){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1sTt_mx2_Module_2_Node* t0{};
    void gcMark(){
      bbGCMarkPtr(t0);
    }
  }f0{};
  return t_std_collections_Map_1sTt_mx2_Module_2_KeyIterator(f0.t0=(*this).m__0map->m_FirstNode());
}

int bbCompare(const t_std_collections_Map_1sTt_mx2_Module_2_MapKeys&x,const t_std_collections_Map_1sTt_mx2_Module_2_MapKeys&y){
  if(int t=bbCompare(x.m__0map,y.m__0map)) return t;
  return 0;
}

void bbGCMark(const t_std_collections_Map_1sTt_mx2_Module_2_MapKeys&t){
  bbGCMark(t.m__0map);
}

t_std_collections_Map_1sTt_mx2_Module_2_ValueIterator::t_std_collections_Map_1sTt_mx2_Module_2_ValueIterator(t_std_collections_Map_1sTt_mx2_Module_2_Node* l_node){
  (*this).m__0node=l_node;
}

bbBool t_std_collections_Map_1sTt_mx2_Module_2_ValueIterator::m_Valid(){
  return bbBool((*this).m__0node);
}

t_mx2_Module* t_std_collections_Map_1sTt_mx2_Module_2_ValueIterator::m_Current(){
  return (*this).m__0node->m__0value;
}

void t_std_collections_Map_1sTt_mx2_Module_2_ValueIterator::m_Bump(){
  (*this).m__0node=(*this).m__0node->m_NextNode();
}

int bbCompare(const t_std_collections_Map_1sTt_mx2_Module_2_ValueIterator&x,const t_std_collections_Map_1sTt_mx2_Module_2_ValueIterator&y){
  if(int t=bbCompare(x.m__0node,y.m__0node)) return t;
  return 0;
}

void bbGCMark(const t_std_collections_Map_1sTt_mx2_Module_2_ValueIterator&t){
  bbGCMark(t.m__0node);
}

t_std_collections_Map_1sTt_mx2_Module_2_MapValues::t_std_collections_Map_1sTt_mx2_Module_2_MapValues(t_std_collections_Map_1sTt_mx2_Module_2* l_map){
  (*this).m__0map=l_map;
}

t_std_collections_Map_1sTt_mx2_Module_2_ValueIterator t_std_collections_Map_1sTt_mx2_Module_2_MapValues::m_All(){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1sTt_mx2_Module_2_Node* t0{};
    void gcMark(){
      bbGCMarkPtr(t0);
    }
  }f0{};
  return t_std_collections_Map_1sTt_mx2_Module_2_ValueIterator(f0.t0=(*this).m__0map->m_FirstNode());
}

int bbCompare(const t_std_collections_Map_1sTt_mx2_Module_2_MapValues&x,const t_std_collections_Map_1sTt_mx2_Module_2_MapValues&y){
  if(int t=bbCompare(x.m__0map,y.m__0map)) return t;
  return 0;
}

void bbGCMark(const t_std_collections_Map_1sTt_mx2_Module_2_MapValues&t){
  bbGCMark(t.m__0map);
}

void t_std_collections_Map_1sTt_mx2_Module_2::gcMark(){
  bbGCMark(m__0root);
}

t_std_collections_Map_1sTt_mx2_Module_2::t_std_collections_Map_1sTt_mx2_Module_2(t_std_collections_Map_1sTt_mx2_Module_2_Node* l_root){
  this->m__0root=l_root;
}

t_std_collections_Map_1sTt_mx2_Module_2::t_std_collections_Map_1sTt_mx2_Module_2(){
}

void t_std_collections_Map_1sTt_mx2_Module_2::m__idxeq(bbString l_key,t_mx2_Module* l_value){
  this->m_Set(l_key,l_value);
}

t_mx2_Module* t_std_collections_Map_1sTt_mx2_Module_2::m__idx(bbString l_key){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1sTt_mx2_Module_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m_FindNode(l_key);
  if(!bbBool(f0.l_node)){
    return ((t_mx2_Module*)0);
  }
  return f0.l_node->m__0value;
}

t_std_collections_Map_1sTt_mx2_Module_2_MapValues t_std_collections_Map_1sTt_mx2_Module_2::m_Values(){
  return t_std_collections_Map_1sTt_mx2_Module_2_MapValues(this);
}

bbBool t_std_collections_Map_1sTt_mx2_Module_2::m_Update(bbString l_key,t_mx2_Module* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1sTt_mx2_Module_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m_FindNode(l_key);
  if(!bbBool(f0.l_node)){
    return false;
  }
  f0.l_node->m__0value=l_value;
  return true;
}

bbBool t_std_collections_Map_1sTt_mx2_Module_2::m_Set(bbString l_key,t_mx2_Module* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1sTt_mx2_Module_2_Node* l_node{};
    t_std_collections_Map_1sTt_mx2_Module_2_Node* l_parent{};
    void gcMark(){
      bbGCMarkPtr(l_node);
      bbGCMarkPtr(l_parent);
    }
  }f0{};
  if(!bbBool(this->m__0root)){
    this->m__0root=bbGCNew<t_std_collections_Map_1sTt_mx2_Module_2_Node>(l_key,l_value,0,((t_std_collections_Map_1sTt_mx2_Module_2_Node*)0));
    return true;
  }
  f0.l_node=this->m__0root;
  bbInt l_cmp{};
  while(bbBool(f0.l_node)){
    f0.l_parent=f0.l_node;
    l_cmp=bbCompare(l_key,f0.l_node->m__0key);
    if((l_cmp>bbInt(0))){
      f0.l_node=f0.l_node->m__0right;
    }else if((l_cmp<bbInt(0))){
      f0.l_node=f0.l_node->m__0left;
    }else{
      f0.l_node->m__0value=l_value;
      return false;
    }
  }
  f0.l_node=bbGCNew<t_std_collections_Map_1sTt_mx2_Module_2_Node>(l_key,l_value,0,f0.l_parent);
  if((l_cmp>bbInt(0))){
    f0.l_parent->m__0right=f0.l_node;
  }else{
    f0.l_parent->m__0left=f0.l_node;
  }
  this->m_InsertFixup(f0.l_node);
  return true;
}

void t_std_collections_Map_1sTt_mx2_Module_2::m_RotateRight(t_std_collections_Map_1sTt_mx2_Module_2_Node* l_node){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1sTt_mx2_Module_2_Node* l_child{};
    void gcMark(){
      bbGCMarkPtr(l_child);
    }
  }f0{};
  f0.l_child=l_node->m__0left;
  l_node->m__0left=f0.l_child->m__0right;
  if(bbBool(f0.l_child->m__0right)){
    f0.l_child->m__0right->m__0parent=l_node;
  }
  f0.l_child->m__0parent=l_node->m__0parent;
  if(bbBool(l_node->m__0parent)){
    if((l_node==l_node->m__0parent->m__0right)){
      l_node->m__0parent->m__0right=f0.l_child;
    }else{
      l_node->m__0parent->m__0left=f0.l_child;
    }
  }else{
    this->m__0root=f0.l_child;
  }
  f0.l_child->m__0right=l_node;
  l_node->m__0parent=f0.l_child;
}

void t_std_collections_Map_1sTt_mx2_Module_2::m_RotateLeft(t_std_collections_Map_1sTt_mx2_Module_2_Node* l_node){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1sTt_mx2_Module_2_Node* l_child{};
    void gcMark(){
      bbGCMarkPtr(l_child);
    }
  }f0{};
  f0.l_child=l_node->m__0right;
  l_node->m__0right=f0.l_child->m__0left;
  if(bbBool(f0.l_child->m__0left)){
    f0.l_child->m__0left->m__0parent=l_node;
  }
  f0.l_child->m__0parent=l_node->m__0parent;
  if(bbBool(l_node->m__0parent)){
    if((l_node==l_node->m__0parent->m__0left)){
      l_node->m__0parent->m__0left=f0.l_child;
    }else{
      l_node->m__0parent->m__0right=f0.l_child;
    }
  }else{
    this->m__0root=f0.l_child;
  }
  f0.l_child->m__0left=l_node;
  l_node->m__0parent=f0.l_child;
}

void t_std_collections_Map_1sTt_mx2_Module_2::m_RemoveNode(t_std_collections_Map_1sTt_mx2_Module_2_Node* l_node){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1sTt_mx2_Module_2_Node* l_child{};
    t_std_collections_Map_1sTt_mx2_Module_2_Node* l_parent{};
    t_std_collections_Map_1sTt_mx2_Module_2_Node* l_splice{};
    void gcMark(){
      bbGCMarkPtr(l_child);
      bbGCMarkPtr(l_parent);
      bbGCMarkPtr(l_splice);
    }
  }f0{};
  if(!bbBool(l_node->m__0left)){
    f0.l_splice=l_node;
    f0.l_child=l_node->m__0right;
  }else if(!bbBool(l_node->m__0right)){
    f0.l_splice=l_node;
    f0.l_child=l_node->m__0left;
  }else{
    f0.l_splice=l_node->m__0left;
    while(bbBool(f0.l_splice->m__0right)){
      f0.l_splice=f0.l_splice->m__0right;
    }
    f0.l_child=f0.l_splice->m__0left;
    l_node->m__0key=f0.l_splice->m__0key;
    l_node->m__0value=f0.l_splice->m__0value;
  }
  f0.l_parent=f0.l_splice->m__0parent;
  if(bbBool(f0.l_child)){
    f0.l_child->m__0parent=f0.l_parent;
  }
  if(!bbBool(f0.l_parent)){
    this->m__0root=f0.l_child;
    return;
  }
  if((f0.l_splice==f0.l_parent->m__0left)){
    f0.l_parent->m__0left=f0.l_child;
  }else{
    f0.l_parent->m__0right=f0.l_child;
  }
  if((f0.l_splice->m__0color==1)){
    this->m_DeleteFixup(f0.l_child,f0.l_parent);
  }
}

bbBool t_std_collections_Map_1sTt_mx2_Module_2::m_Remove(bbString l_key){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1sTt_mx2_Module_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m_FindNode(l_key);
  if(!bbBool(f0.l_node)){
    return false;
  }
  this->m_RemoveNode(f0.l_node);
  return true;
}

t_std_collections_Map_1sTt_mx2_Module_2_Node* t_std_collections_Map_1sTt_mx2_Module_2::m_LastNode(){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1sTt_mx2_Module_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  if(!bbBool(this->m__0root)){
    return ((t_std_collections_Map_1sTt_mx2_Module_2_Node*)0);
  }
  f0.l_node=this->m__0root;
  while(bbBool(f0.l_node->m__0right)){
    f0.l_node=f0.l_node->m__0right;
  }
  return f0.l_node;
}

t_std_collections_Map_1sTt_mx2_Module_2_MapKeys t_std_collections_Map_1sTt_mx2_Module_2::m_Keys(){
  return t_std_collections_Map_1sTt_mx2_Module_2_MapKeys(this);
}

void t_std_collections_Map_1sTt_mx2_Module_2::m_InsertFixup(t_std_collections_Map_1sTt_mx2_Module_2_Node* l_node){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1sTt_mx2_Module_2_Node* l_node{};
    f0_t(t_std_collections_Map_1sTt_mx2_Module_2_Node* l_node):l_node(l_node){
    }
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{l_node};
  while(((bbBool(f0.l_node->m__0parent)&&(f0.l_node->m__0parent->m__0color==0))&&bbBool(f0.l_node->m__0parent->m__0parent))){
    if((f0.l_node->m__0parent==f0.l_node->m__0parent->m__0parent->m__0left)){
      struct f2_t : public bbGCFrame{
        t_std_collections_Map_1sTt_mx2_Module_2_Node* l_uncle{};
        void gcMark(){
          bbGCMarkPtr(l_uncle);
        }
      }f2{};
      f2.l_uncle=f0.l_node->m__0parent->m__0parent->m__0right;
      if((bbBool(f2.l_uncle)&&(f2.l_uncle->m__0color==0))){
        f0.l_node->m__0parent->m__0color=1;
        f2.l_uncle->m__0color=1;
        f2.l_uncle->m__0parent->m__0color=0;
        f0.l_node=f2.l_uncle->m__0parent;
      }else{
        if((f0.l_node==f0.l_node->m__0parent->m__0right)){
          f0.l_node=f0.l_node->m__0parent;
          this->m_RotateLeft(f0.l_node);
        }
        f0.l_node->m__0parent->m__0color=1;
        f0.l_node->m__0parent->m__0parent->m__0color=0;
        this->m_RotateRight(f0.l_node->m__0parent->m__0parent);
      }
    }else{
      struct f2_t : public bbGCFrame{
        t_std_collections_Map_1sTt_mx2_Module_2_Node* l_uncle{};
        void gcMark(){
          bbGCMarkPtr(l_uncle);
        }
      }f2{};
      f2.l_uncle=f0.l_node->m__0parent->m__0parent->m__0left;
      if((bbBool(f2.l_uncle)&&(f2.l_uncle->m__0color==0))){
        f0.l_node->m__0parent->m__0color=1;
        f2.l_uncle->m__0color=1;
        f2.l_uncle->m__0parent->m__0color=0;
        f0.l_node=f2.l_uncle->m__0parent;
      }else{
        if((f0.l_node==f0.l_node->m__0parent->m__0left)){
          f0.l_node=f0.l_node->m__0parent;
          this->m_RotateRight(f0.l_node);
        }
        f0.l_node->m__0parent->m__0color=1;
        f0.l_node->m__0parent->m__0parent->m__0color=0;
        this->m_RotateLeft(f0.l_node->m__0parent->m__0parent);
      }
    }
  }
  this->m__0root->m__0color=1;
}

t_mx2_Module* t_std_collections_Map_1sTt_mx2_Module_2::m_Get(bbString l_key){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1sTt_mx2_Module_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m_FindNode(l_key);
  if(bbBool(f0.l_node)){
    return f0.l_node->m__0value;
  }
  return ((t_mx2_Module*)0);
}

t_std_collections_Map_1sTt_mx2_Module_2_Node* t_std_collections_Map_1sTt_mx2_Module_2::m_FirstNode(){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1sTt_mx2_Module_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  if(!bbBool(this->m__0root)){
    return ((t_std_collections_Map_1sTt_mx2_Module_2_Node*)0);
  }
  f0.l_node=this->m__0root;
  while(bbBool(f0.l_node->m__0left)){
    f0.l_node=f0.l_node->m__0left;
  }
  return f0.l_node;
}

t_std_collections_Map_1sTt_mx2_Module_2_Node* t_std_collections_Map_1sTt_mx2_Module_2::m_FindNode(bbString l_key){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1sTt_mx2_Module_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m__0root;
  while(bbBool(f0.l_node)){
    bbInt l_cmp=bbCompare(l_key,f0.l_node->m__0key);
    if((l_cmp>bbInt(0))){
      f0.l_node=f0.l_node->m__0right;
    }else if((l_cmp<bbInt(0))){
      f0.l_node=f0.l_node->m__0left;
    }else{
      return f0.l_node;
    }
  }
  return ((t_std_collections_Map_1sTt_mx2_Module_2_Node*)0);
}

bbBool t_std_collections_Map_1sTt_mx2_Module_2::m_Empty(){
  return (this->m__0root==((t_std_collections_Map_1sTt_mx2_Module_2_Node*)0));
}

void t_std_collections_Map_1sTt_mx2_Module_2::m_DeleteFixup(t_std_collections_Map_1sTt_mx2_Module_2_Node* l_node,t_std_collections_Map_1sTt_mx2_Module_2_Node* l_parent){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1sTt_mx2_Module_2_Node* l_node{};
    t_std_collections_Map_1sTt_mx2_Module_2_Node* l_parent{};
    f0_t(t_std_collections_Map_1sTt_mx2_Module_2_Node* l_node,t_std_collections_Map_1sTt_mx2_Module_2_Node* l_parent):l_node(l_node),l_parent(l_parent){
    }
    void gcMark(){
      bbGCMarkPtr(l_node);
      bbGCMarkPtr(l_parent);
    }
  }f0{l_node,l_parent};
  while(((f0.l_node!=this->m__0root)&&(!bbBool(f0.l_node)||(f0.l_node->m__0color==1)))){
    if((f0.l_node==f0.l_parent->m__0left)){
      struct f2_t : public bbGCFrame{
        t_std_collections_Map_1sTt_mx2_Module_2_Node* l_sib{};
        void gcMark(){
          bbGCMarkPtr(l_sib);
        }
      }f2{};
      f2.l_sib=f0.l_parent->m__0right;
      if((f2.l_sib->m__0color==0)){
        f2.l_sib->m__0color=1;
        f0.l_parent->m__0color=0;
        this->m_RotateLeft(f0.l_parent);
        f2.l_sib=f0.l_parent->m__0right;
      }
      if(((!bbBool(f2.l_sib->m__0left)||(f2.l_sib->m__0left->m__0color==1))&&(!bbBool(f2.l_sib->m__0right)||(f2.l_sib->m__0right->m__0color==1)))){
        f2.l_sib->m__0color=0;
        f0.l_node=f0.l_parent;
        f0.l_parent=f0.l_parent->m__0parent;
      }else{
        if((!bbBool(f2.l_sib->m__0right)||(f2.l_sib->m__0right->m__0color==1))){
          f2.l_sib->m__0left->m__0color=1;
          f2.l_sib->m__0color=0;
          this->m_RotateRight(f2.l_sib);
          f2.l_sib=f0.l_parent->m__0right;
        }
        f2.l_sib->m__0color=f0.l_parent->m__0color;
        f0.l_parent->m__0color=1;
        f2.l_sib->m__0right->m__0color=1;
        this->m_RotateLeft(f0.l_parent);
        f0.l_node=this->m__0root;
      }
    }else{
      struct f2_t : public bbGCFrame{
        t_std_collections_Map_1sTt_mx2_Module_2_Node* l_sib{};
        void gcMark(){
          bbGCMarkPtr(l_sib);
        }
      }f2{};
      f2.l_sib=f0.l_parent->m__0left;
      if((f2.l_sib->m__0color==0)){
        f2.l_sib->m__0color=1;
        f0.l_parent->m__0color=0;
        this->m_RotateRight(f0.l_parent);
        f2.l_sib=f0.l_parent->m__0left;
      }
      if(((!bbBool(f2.l_sib->m__0right)||(f2.l_sib->m__0right->m__0color==1))&&(!bbBool(f2.l_sib->m__0left)||(f2.l_sib->m__0left->m__0color==1)))){
        f2.l_sib->m__0color=0;
        f0.l_node=f0.l_parent;
        f0.l_parent=f0.l_parent->m__0parent;
      }else{
        if((!bbBool(f2.l_sib->m__0left)||(f2.l_sib->m__0left->m__0color==1))){
          f2.l_sib->m__0right->m__0color=1;
          f2.l_sib->m__0color=0;
          this->m_RotateLeft(f2.l_sib);
          f2.l_sib=f0.l_parent->m__0left;
        }
        f2.l_sib->m__0color=f0.l_parent->m__0color;
        f0.l_parent->m__0color=1;
        f2.l_sib->m__0left->m__0color=1;
        this->m_RotateRight(f0.l_parent);
        f0.l_node=this->m__0root;
      }
    }
  }
  if(bbBool(f0.l_node)){
    f0.l_node->m__0color=1;
  }
}

bbInt t_std_collections_Map_1sTt_mx2_Module_2::m_Count(){
  if(!bbBool(this->m__0root)){
    return bbInt(0);
  }
  return this->m__0root->m_Count(bbInt(0));
}

t_std_collections_Map_1sTt_mx2_Module_2* t_std_collections_Map_1sTt_mx2_Module_2::m_Copy(){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1sTt_mx2_Module_2_Node* l_root{};
    void gcMark(){
      bbGCMarkPtr(l_root);
    }
  }f0{};
  if(bbBool(this->m__0root)){
    f0.l_root=this->m__0root->m_Copy(((t_std_collections_Map_1sTt_mx2_Module_2_Node*)0));
  }
  return bbGCNew<t_std_collections_Map_1sTt_mx2_Module_2>(f0.l_root);
}

bbBool t_std_collections_Map_1sTt_mx2_Module_2::m_Contains(bbString l_key){
  return (this->m_FindNode(l_key)!=((t_std_collections_Map_1sTt_mx2_Module_2_Node*)0));
}

void t_std_collections_Map_1sTt_mx2_Module_2::m_Clear(){
  this->m__0root=((t_std_collections_Map_1sTt_mx2_Module_2_Node*)0);
}

t_std_collections_Map_1sTt_mx2_Module_2_Iterator t_std_collections_Map_1sTt_mx2_Module_2::m_All(){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1sTt_mx2_Module_2_Node* t0{};
    void gcMark(){
      bbGCMarkPtr(t0);
    }
  }f0{};
  return t_std_collections_Map_1sTt_mx2_Module_2_Iterator(f0.t0=this->m_FirstNode());
}

bbBool t_std_collections_Map_1sTt_mx2_Module_2::m_Add(bbString l_key,t_mx2_Module* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1sTt_mx2_Module_2_Node* l_node{};
    t_std_collections_Map_1sTt_mx2_Module_2_Node* l_parent{};
    void gcMark(){
      bbGCMarkPtr(l_node);
      bbGCMarkPtr(l_parent);
    }
  }f0{};
  if(!bbBool(this->m__0root)){
    this->m__0root=bbGCNew<t_std_collections_Map_1sTt_mx2_Module_2_Node>(l_key,l_value,0,((t_std_collections_Map_1sTt_mx2_Module_2_Node*)0));
    return true;
  }
  f0.l_node=this->m__0root;
  bbInt l_cmp{};
  while(bbBool(f0.l_node)){
    f0.l_parent=f0.l_node;
    l_cmp=bbCompare(l_key,f0.l_node->m__0key);
    if((l_cmp>bbInt(0))){
      f0.l_node=f0.l_node->m__0right;
    }else if((l_cmp<bbInt(0))){
      f0.l_node=f0.l_node->m__0left;
    }else{
      return false;
    }
  }
  f0.l_node=bbGCNew<t_std_collections_Map_1sTt_mx2_Module_2_Node>(l_key,l_value,0,f0.l_parent);
  if((l_cmp>bbInt(0))){
    f0.l_parent->m__0right=f0.l_node;
  }else{
    f0.l_parent->m__0left=f0.l_node;
  }
  this->m_InsertFixup(f0.l_node);
  return true;
}

void t_std_collections_Map_1sTt_mx2_SNode_2_Node::gcMark(){
  bbGCMark(m__0value);
  bbGCMark(m__0left);
  bbGCMark(m__0right);
  bbGCMark(m__0parent);
}

t_std_collections_Map_1sTt_mx2_SNode_2_Node::t_std_collections_Map_1sTt_mx2_SNode_2_Node(bbString l_key,t_mx2_SNode* l_value,bbInt l_color,t_std_collections_Map_1sTt_mx2_SNode_2_Node* l_parent){
  this->m__0key=l_key;
  this->m__0value=l_value;
  this->m__0color=l_color;
  this->m__0parent=l_parent;
}

t_mx2_SNode* t_std_collections_Map_1sTt_mx2_SNode_2_Node::m_Value(){
  return this->m__0value;
}

t_std_collections_Map_1sTt_mx2_SNode_2_Node* t_std_collections_Map_1sTt_mx2_SNode_2_Node::m_PrevNode(){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1sTt_mx2_SNode_2_Node* l_node{};
    t_std_collections_Map_1sTt_mx2_SNode_2_Node* l_parent{};
    void gcMark(){
      bbGCMarkPtr(l_node);
      bbGCMarkPtr(l_parent);
    }
  }f0{};
  if(bbBool(this->m__0left)){
    struct f1_t : public bbGCFrame{
      t_std_collections_Map_1sTt_mx2_SNode_2_Node* l_node{};
      void gcMark(){
        bbGCMarkPtr(l_node);
      }
    }f1{};
    f1.l_node=this->m__0left;
    while(bbBool(f1.l_node->m__0right)){
      f1.l_node=f1.l_node->m__0right;
    }
    return f1.l_node;
  }
  f0.l_node=this;
  f0.l_parent=this->m__0parent;
  while((bbBool(f0.l_parent)&&(f0.l_node==f0.l_parent->m__0left))){
    f0.l_node=f0.l_parent;
    f0.l_parent=f0.l_parent->m__0parent;
  }
  return f0.l_parent;
}

t_std_collections_Map_1sTt_mx2_SNode_2_Node* t_std_collections_Map_1sTt_mx2_SNode_2_Node::m_NextNode(){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1sTt_mx2_SNode_2_Node* l_node{};
    t_std_collections_Map_1sTt_mx2_SNode_2_Node* l_parent{};
    void gcMark(){
      bbGCMarkPtr(l_node);
      bbGCMarkPtr(l_parent);
    }
  }f0{};
  if(bbBool(this->m__0right)){
    struct f1_t : public bbGCFrame{
      t_std_collections_Map_1sTt_mx2_SNode_2_Node* l_node{};
      void gcMark(){
        bbGCMarkPtr(l_node);
      }
    }f1{};
    f1.l_node=this->m__0right;
    while(bbBool(f1.l_node->m__0left)){
      f1.l_node=f1.l_node->m__0left;
    }
    return f1.l_node;
  }
  f0.l_node=this;
  f0.l_parent=this->m__0parent;
  while((bbBool(f0.l_parent)&&(f0.l_node==f0.l_parent->m__0right))){
    f0.l_node=f0.l_parent;
    f0.l_parent=f0.l_parent->m__0parent;
  }
  return f0.l_parent;
}

bbString t_std_collections_Map_1sTt_mx2_SNode_2_Node::m_Key(){
  return this->m__0key;
}

bbInt t_std_collections_Map_1sTt_mx2_SNode_2_Node::m_Count(bbInt l_n){
  if(bbBool(this->m__0left)){
    l_n=this->m__0left->m_Count(l_n);
  }
  if(bbBool(this->m__0right)){
    l_n=this->m__0right->m_Count(l_n);
  }
  return (l_n+1);
}

t_std_collections_Map_1sTt_mx2_SNode_2_Node* t_std_collections_Map_1sTt_mx2_SNode_2_Node::m_Copy(t_std_collections_Map_1sTt_mx2_SNode_2_Node* l_parent){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1sTt_mx2_SNode_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=bbGCNew<t_std_collections_Map_1sTt_mx2_SNode_2_Node>(this->m__0key,this->m__0value,this->m__0color,l_parent);
  if(bbBool(this->m__0left)){
    f0.l_node->m__0left=this->m__0left->m_Copy(f0.l_node);
  }
  if(bbBool(this->m__0right)){
    f0.l_node->m__0right=this->m__0right->m_Copy(f0.l_node);
  }
  return f0.l_node;
}

t_std_collections_Map_1sTt_mx2_SNode_2_Iterator::t_std_collections_Map_1sTt_mx2_SNode_2_Iterator(t_std_collections_Map_1sTt_mx2_SNode_2_Node* l_node){
  (*this).m__0node=l_node;
}

bbBool t_std_collections_Map_1sTt_mx2_SNode_2_Iterator::m_Valid(){
  return bbBool((*this).m__0node);
}

t_std_collections_Map_1sTt_mx2_SNode_2_Node* t_std_collections_Map_1sTt_mx2_SNode_2_Iterator::m_Current(){
  return (*this).m__0node;
}

void t_std_collections_Map_1sTt_mx2_SNode_2_Iterator::m_Bump(){
  (*this).m__0node=(*this).m__0node->m_NextNode();
}

int bbCompare(const t_std_collections_Map_1sTt_mx2_SNode_2_Iterator&x,const t_std_collections_Map_1sTt_mx2_SNode_2_Iterator&y){
  if(int t=bbCompare(x.m__0node,y.m__0node)) return t;
  return 0;
}

void bbGCMark(const t_std_collections_Map_1sTt_mx2_SNode_2_Iterator&t){
  bbGCMark(t.m__0node);
}

t_std_collections_Map_1sTt_mx2_SNode_2_KeyIterator::t_std_collections_Map_1sTt_mx2_SNode_2_KeyIterator(t_std_collections_Map_1sTt_mx2_SNode_2_Node* l_node){
  (*this).m__0node=l_node;
}

bbBool t_std_collections_Map_1sTt_mx2_SNode_2_KeyIterator::m_Valid(){
  return bbBool((*this).m__0node);
}

bbString t_std_collections_Map_1sTt_mx2_SNode_2_KeyIterator::m_Current(){
  return (*this).m__0node->m__0key;
}

void t_std_collections_Map_1sTt_mx2_SNode_2_KeyIterator::m_Bump(){
  (*this).m__0node=(*this).m__0node->m_NextNode();
}

int bbCompare(const t_std_collections_Map_1sTt_mx2_SNode_2_KeyIterator&x,const t_std_collections_Map_1sTt_mx2_SNode_2_KeyIterator&y){
  if(int t=bbCompare(x.m__0node,y.m__0node)) return t;
  return 0;
}

void bbGCMark(const t_std_collections_Map_1sTt_mx2_SNode_2_KeyIterator&t){
  bbGCMark(t.m__0node);
}

t_std_collections_Map_1sTt_mx2_SNode_2_MapKeys::t_std_collections_Map_1sTt_mx2_SNode_2_MapKeys(t_std_collections_Map_1sTt_mx2_SNode_2* l_map){
  (*this).m__0map=l_map;
}

t_std_collections_Map_1sTt_mx2_SNode_2_KeyIterator t_std_collections_Map_1sTt_mx2_SNode_2_MapKeys::m_All(){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1sTt_mx2_SNode_2_Node* t0{};
    void gcMark(){
      bbGCMarkPtr(t0);
    }
  }f0{};
  return t_std_collections_Map_1sTt_mx2_SNode_2_KeyIterator(f0.t0=(*this).m__0map->m_FirstNode());
}

int bbCompare(const t_std_collections_Map_1sTt_mx2_SNode_2_MapKeys&x,const t_std_collections_Map_1sTt_mx2_SNode_2_MapKeys&y){
  if(int t=bbCompare(x.m__0map,y.m__0map)) return t;
  return 0;
}

void bbGCMark(const t_std_collections_Map_1sTt_mx2_SNode_2_MapKeys&t){
  bbGCMark(t.m__0map);
}

t_std_collections_Map_1sTt_mx2_SNode_2_ValueIterator::t_std_collections_Map_1sTt_mx2_SNode_2_ValueIterator(t_std_collections_Map_1sTt_mx2_SNode_2_Node* l_node){
  (*this).m__0node=l_node;
}

bbBool t_std_collections_Map_1sTt_mx2_SNode_2_ValueIterator::m_Valid(){
  return bbBool((*this).m__0node);
}

t_mx2_SNode* t_std_collections_Map_1sTt_mx2_SNode_2_ValueIterator::m_Current(){
  return (*this).m__0node->m__0value;
}

void t_std_collections_Map_1sTt_mx2_SNode_2_ValueIterator::m_Bump(){
  (*this).m__0node=(*this).m__0node->m_NextNode();
}

int bbCompare(const t_std_collections_Map_1sTt_mx2_SNode_2_ValueIterator&x,const t_std_collections_Map_1sTt_mx2_SNode_2_ValueIterator&y){
  if(int t=bbCompare(x.m__0node,y.m__0node)) return t;
  return 0;
}

void bbGCMark(const t_std_collections_Map_1sTt_mx2_SNode_2_ValueIterator&t){
  bbGCMark(t.m__0node);
}

t_std_collections_Map_1sTt_mx2_SNode_2_MapValues::t_std_collections_Map_1sTt_mx2_SNode_2_MapValues(t_std_collections_Map_1sTt_mx2_SNode_2* l_map){
  (*this).m__0map=l_map;
}

t_std_collections_Map_1sTt_mx2_SNode_2_ValueIterator t_std_collections_Map_1sTt_mx2_SNode_2_MapValues::m_All(){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1sTt_mx2_SNode_2_Node* t0{};
    void gcMark(){
      bbGCMarkPtr(t0);
    }
  }f0{};
  return t_std_collections_Map_1sTt_mx2_SNode_2_ValueIterator(f0.t0=(*this).m__0map->m_FirstNode());
}

int bbCompare(const t_std_collections_Map_1sTt_mx2_SNode_2_MapValues&x,const t_std_collections_Map_1sTt_mx2_SNode_2_MapValues&y){
  if(int t=bbCompare(x.m__0map,y.m__0map)) return t;
  return 0;
}

void bbGCMark(const t_std_collections_Map_1sTt_mx2_SNode_2_MapValues&t){
  bbGCMark(t.m__0map);
}

void t_std_collections_Map_1sTt_mx2_SNode_2::gcMark(){
  bbGCMark(m__0root);
}

t_std_collections_Map_1sTt_mx2_SNode_2::t_std_collections_Map_1sTt_mx2_SNode_2(t_std_collections_Map_1sTt_mx2_SNode_2_Node* l_root){
  this->m__0root=l_root;
}

t_std_collections_Map_1sTt_mx2_SNode_2::t_std_collections_Map_1sTt_mx2_SNode_2(){
}

void t_std_collections_Map_1sTt_mx2_SNode_2::m__idxeq(bbString l_key,t_mx2_SNode* l_value){
  this->m_Set(l_key,l_value);
}

t_mx2_SNode* t_std_collections_Map_1sTt_mx2_SNode_2::m__idx(bbString l_key){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1sTt_mx2_SNode_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m_FindNode(l_key);
  if(!bbBool(f0.l_node)){
    return ((t_mx2_SNode*)0);
  }
  return f0.l_node->m__0value;
}

t_std_collections_Map_1sTt_mx2_SNode_2_MapValues t_std_collections_Map_1sTt_mx2_SNode_2::m_Values(){
  return t_std_collections_Map_1sTt_mx2_SNode_2_MapValues(this);
}

bbBool t_std_collections_Map_1sTt_mx2_SNode_2::m_Update(bbString l_key,t_mx2_SNode* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1sTt_mx2_SNode_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m_FindNode(l_key);
  if(!bbBool(f0.l_node)){
    return false;
  }
  f0.l_node->m__0value=l_value;
  return true;
}

bbBool t_std_collections_Map_1sTt_mx2_SNode_2::m_Set(bbString l_key,t_mx2_SNode* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1sTt_mx2_SNode_2_Node* l_node{};
    t_std_collections_Map_1sTt_mx2_SNode_2_Node* l_parent{};
    void gcMark(){
      bbGCMarkPtr(l_node);
      bbGCMarkPtr(l_parent);
    }
  }f0{};
  if(!bbBool(this->m__0root)){
    this->m__0root=bbGCNew<t_std_collections_Map_1sTt_mx2_SNode_2_Node>(l_key,l_value,0,((t_std_collections_Map_1sTt_mx2_SNode_2_Node*)0));
    return true;
  }
  f0.l_node=this->m__0root;
  bbInt l_cmp{};
  while(bbBool(f0.l_node)){
    f0.l_parent=f0.l_node;
    l_cmp=bbCompare(l_key,f0.l_node->m__0key);
    if((l_cmp>bbInt(0))){
      f0.l_node=f0.l_node->m__0right;
    }else if((l_cmp<bbInt(0))){
      f0.l_node=f0.l_node->m__0left;
    }else{
      f0.l_node->m__0value=l_value;
      return false;
    }
  }
  f0.l_node=bbGCNew<t_std_collections_Map_1sTt_mx2_SNode_2_Node>(l_key,l_value,0,f0.l_parent);
  if((l_cmp>bbInt(0))){
    f0.l_parent->m__0right=f0.l_node;
  }else{
    f0.l_parent->m__0left=f0.l_node;
  }
  this->m_InsertFixup(f0.l_node);
  return true;
}

void t_std_collections_Map_1sTt_mx2_SNode_2::m_RotateRight(t_std_collections_Map_1sTt_mx2_SNode_2_Node* l_node){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1sTt_mx2_SNode_2_Node* l_child{};
    void gcMark(){
      bbGCMarkPtr(l_child);
    }
  }f0{};
  f0.l_child=l_node->m__0left;
  l_node->m__0left=f0.l_child->m__0right;
  if(bbBool(f0.l_child->m__0right)){
    f0.l_child->m__0right->m__0parent=l_node;
  }
  f0.l_child->m__0parent=l_node->m__0parent;
  if(bbBool(l_node->m__0parent)){
    if((l_node==l_node->m__0parent->m__0right)){
      l_node->m__0parent->m__0right=f0.l_child;
    }else{
      l_node->m__0parent->m__0left=f0.l_child;
    }
  }else{
    this->m__0root=f0.l_child;
  }
  f0.l_child->m__0right=l_node;
  l_node->m__0parent=f0.l_child;
}

void t_std_collections_Map_1sTt_mx2_SNode_2::m_RotateLeft(t_std_collections_Map_1sTt_mx2_SNode_2_Node* l_node){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1sTt_mx2_SNode_2_Node* l_child{};
    void gcMark(){
      bbGCMarkPtr(l_child);
    }
  }f0{};
  f0.l_child=l_node->m__0right;
  l_node->m__0right=f0.l_child->m__0left;
  if(bbBool(f0.l_child->m__0left)){
    f0.l_child->m__0left->m__0parent=l_node;
  }
  f0.l_child->m__0parent=l_node->m__0parent;
  if(bbBool(l_node->m__0parent)){
    if((l_node==l_node->m__0parent->m__0left)){
      l_node->m__0parent->m__0left=f0.l_child;
    }else{
      l_node->m__0parent->m__0right=f0.l_child;
    }
  }else{
    this->m__0root=f0.l_child;
  }
  f0.l_child->m__0left=l_node;
  l_node->m__0parent=f0.l_child;
}

void t_std_collections_Map_1sTt_mx2_SNode_2::m_RemoveNode(t_std_collections_Map_1sTt_mx2_SNode_2_Node* l_node){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1sTt_mx2_SNode_2_Node* l_child{};
    t_std_collections_Map_1sTt_mx2_SNode_2_Node* l_parent{};
    t_std_collections_Map_1sTt_mx2_SNode_2_Node* l_splice{};
    void gcMark(){
      bbGCMarkPtr(l_child);
      bbGCMarkPtr(l_parent);
      bbGCMarkPtr(l_splice);
    }
  }f0{};
  if(!bbBool(l_node->m__0left)){
    f0.l_splice=l_node;
    f0.l_child=l_node->m__0right;
  }else if(!bbBool(l_node->m__0right)){
    f0.l_splice=l_node;
    f0.l_child=l_node->m__0left;
  }else{
    f0.l_splice=l_node->m__0left;
    while(bbBool(f0.l_splice->m__0right)){
      f0.l_splice=f0.l_splice->m__0right;
    }
    f0.l_child=f0.l_splice->m__0left;
    l_node->m__0key=f0.l_splice->m__0key;
    l_node->m__0value=f0.l_splice->m__0value;
  }
  f0.l_parent=f0.l_splice->m__0parent;
  if(bbBool(f0.l_child)){
    f0.l_child->m__0parent=f0.l_parent;
  }
  if(!bbBool(f0.l_parent)){
    this->m__0root=f0.l_child;
    return;
  }
  if((f0.l_splice==f0.l_parent->m__0left)){
    f0.l_parent->m__0left=f0.l_child;
  }else{
    f0.l_parent->m__0right=f0.l_child;
  }
  if((f0.l_splice->m__0color==1)){
    this->m_DeleteFixup(f0.l_child,f0.l_parent);
  }
}

bbBool t_std_collections_Map_1sTt_mx2_SNode_2::m_Remove(bbString l_key){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1sTt_mx2_SNode_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m_FindNode(l_key);
  if(!bbBool(f0.l_node)){
    return false;
  }
  this->m_RemoveNode(f0.l_node);
  return true;
}

t_std_collections_Map_1sTt_mx2_SNode_2_Node* t_std_collections_Map_1sTt_mx2_SNode_2::m_LastNode(){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1sTt_mx2_SNode_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  if(!bbBool(this->m__0root)){
    return ((t_std_collections_Map_1sTt_mx2_SNode_2_Node*)0);
  }
  f0.l_node=this->m__0root;
  while(bbBool(f0.l_node->m__0right)){
    f0.l_node=f0.l_node->m__0right;
  }
  return f0.l_node;
}

t_std_collections_Map_1sTt_mx2_SNode_2_MapKeys t_std_collections_Map_1sTt_mx2_SNode_2::m_Keys(){
  return t_std_collections_Map_1sTt_mx2_SNode_2_MapKeys(this);
}

void t_std_collections_Map_1sTt_mx2_SNode_2::m_InsertFixup(t_std_collections_Map_1sTt_mx2_SNode_2_Node* l_node){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1sTt_mx2_SNode_2_Node* l_node{};
    f0_t(t_std_collections_Map_1sTt_mx2_SNode_2_Node* l_node):l_node(l_node){
    }
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{l_node};
  while(((bbBool(f0.l_node->m__0parent)&&(f0.l_node->m__0parent->m__0color==0))&&bbBool(f0.l_node->m__0parent->m__0parent))){
    if((f0.l_node->m__0parent==f0.l_node->m__0parent->m__0parent->m__0left)){
      struct f2_t : public bbGCFrame{
        t_std_collections_Map_1sTt_mx2_SNode_2_Node* l_uncle{};
        void gcMark(){
          bbGCMarkPtr(l_uncle);
        }
      }f2{};
      f2.l_uncle=f0.l_node->m__0parent->m__0parent->m__0right;
      if((bbBool(f2.l_uncle)&&(f2.l_uncle->m__0color==0))){
        f0.l_node->m__0parent->m__0color=1;
        f2.l_uncle->m__0color=1;
        f2.l_uncle->m__0parent->m__0color=0;
        f0.l_node=f2.l_uncle->m__0parent;
      }else{
        if((f0.l_node==f0.l_node->m__0parent->m__0right)){
          f0.l_node=f0.l_node->m__0parent;
          this->m_RotateLeft(f0.l_node);
        }
        f0.l_node->m__0parent->m__0color=1;
        f0.l_node->m__0parent->m__0parent->m__0color=0;
        this->m_RotateRight(f0.l_node->m__0parent->m__0parent);
      }
    }else{
      struct f2_t : public bbGCFrame{
        t_std_collections_Map_1sTt_mx2_SNode_2_Node* l_uncle{};
        void gcMark(){
          bbGCMarkPtr(l_uncle);
        }
      }f2{};
      f2.l_uncle=f0.l_node->m__0parent->m__0parent->m__0left;
      if((bbBool(f2.l_uncle)&&(f2.l_uncle->m__0color==0))){
        f0.l_node->m__0parent->m__0color=1;
        f2.l_uncle->m__0color=1;
        f2.l_uncle->m__0parent->m__0color=0;
        f0.l_node=f2.l_uncle->m__0parent;
      }else{
        if((f0.l_node==f0.l_node->m__0parent->m__0left)){
          f0.l_node=f0.l_node->m__0parent;
          this->m_RotateRight(f0.l_node);
        }
        f0.l_node->m__0parent->m__0color=1;
        f0.l_node->m__0parent->m__0parent->m__0color=0;
        this->m_RotateLeft(f0.l_node->m__0parent->m__0parent);
      }
    }
  }
  this->m__0root->m__0color=1;
}

t_mx2_SNode* t_std_collections_Map_1sTt_mx2_SNode_2::m_Get(bbString l_key){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1sTt_mx2_SNode_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m_FindNode(l_key);
  if(bbBool(f0.l_node)){
    return f0.l_node->m__0value;
  }
  return ((t_mx2_SNode*)0);
}

t_std_collections_Map_1sTt_mx2_SNode_2_Node* t_std_collections_Map_1sTt_mx2_SNode_2::m_FirstNode(){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1sTt_mx2_SNode_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  if(!bbBool(this->m__0root)){
    return ((t_std_collections_Map_1sTt_mx2_SNode_2_Node*)0);
  }
  f0.l_node=this->m__0root;
  while(bbBool(f0.l_node->m__0left)){
    f0.l_node=f0.l_node->m__0left;
  }
  return f0.l_node;
}

t_std_collections_Map_1sTt_mx2_SNode_2_Node* t_std_collections_Map_1sTt_mx2_SNode_2::m_FindNode(bbString l_key){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1sTt_mx2_SNode_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m__0root;
  while(bbBool(f0.l_node)){
    bbInt l_cmp=bbCompare(l_key,f0.l_node->m__0key);
    if((l_cmp>bbInt(0))){
      f0.l_node=f0.l_node->m__0right;
    }else if((l_cmp<bbInt(0))){
      f0.l_node=f0.l_node->m__0left;
    }else{
      return f0.l_node;
    }
  }
  return ((t_std_collections_Map_1sTt_mx2_SNode_2_Node*)0);
}

bbBool t_std_collections_Map_1sTt_mx2_SNode_2::m_Empty(){
  return (this->m__0root==((t_std_collections_Map_1sTt_mx2_SNode_2_Node*)0));
}

void t_std_collections_Map_1sTt_mx2_SNode_2::m_DeleteFixup(t_std_collections_Map_1sTt_mx2_SNode_2_Node* l_node,t_std_collections_Map_1sTt_mx2_SNode_2_Node* l_parent){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1sTt_mx2_SNode_2_Node* l_node{};
    t_std_collections_Map_1sTt_mx2_SNode_2_Node* l_parent{};
    f0_t(t_std_collections_Map_1sTt_mx2_SNode_2_Node* l_node,t_std_collections_Map_1sTt_mx2_SNode_2_Node* l_parent):l_node(l_node),l_parent(l_parent){
    }
    void gcMark(){
      bbGCMarkPtr(l_node);
      bbGCMarkPtr(l_parent);
    }
  }f0{l_node,l_parent};
  while(((f0.l_node!=this->m__0root)&&(!bbBool(f0.l_node)||(f0.l_node->m__0color==1)))){
    if((f0.l_node==f0.l_parent->m__0left)){
      struct f2_t : public bbGCFrame{
        t_std_collections_Map_1sTt_mx2_SNode_2_Node* l_sib{};
        void gcMark(){
          bbGCMarkPtr(l_sib);
        }
      }f2{};
      f2.l_sib=f0.l_parent->m__0right;
      if((f2.l_sib->m__0color==0)){
        f2.l_sib->m__0color=1;
        f0.l_parent->m__0color=0;
        this->m_RotateLeft(f0.l_parent);
        f2.l_sib=f0.l_parent->m__0right;
      }
      if(((!bbBool(f2.l_sib->m__0left)||(f2.l_sib->m__0left->m__0color==1))&&(!bbBool(f2.l_sib->m__0right)||(f2.l_sib->m__0right->m__0color==1)))){
        f2.l_sib->m__0color=0;
        f0.l_node=f0.l_parent;
        f0.l_parent=f0.l_parent->m__0parent;
      }else{
        if((!bbBool(f2.l_sib->m__0right)||(f2.l_sib->m__0right->m__0color==1))){
          f2.l_sib->m__0left->m__0color=1;
          f2.l_sib->m__0color=0;
          this->m_RotateRight(f2.l_sib);
          f2.l_sib=f0.l_parent->m__0right;
        }
        f2.l_sib->m__0color=f0.l_parent->m__0color;
        f0.l_parent->m__0color=1;
        f2.l_sib->m__0right->m__0color=1;
        this->m_RotateLeft(f0.l_parent);
        f0.l_node=this->m__0root;
      }
    }else{
      struct f2_t : public bbGCFrame{
        t_std_collections_Map_1sTt_mx2_SNode_2_Node* l_sib{};
        void gcMark(){
          bbGCMarkPtr(l_sib);
        }
      }f2{};
      f2.l_sib=f0.l_parent->m__0left;
      if((f2.l_sib->m__0color==0)){
        f2.l_sib->m__0color=1;
        f0.l_parent->m__0color=0;
        this->m_RotateRight(f0.l_parent);
        f2.l_sib=f0.l_parent->m__0left;
      }
      if(((!bbBool(f2.l_sib->m__0right)||(f2.l_sib->m__0right->m__0color==1))&&(!bbBool(f2.l_sib->m__0left)||(f2.l_sib->m__0left->m__0color==1)))){
        f2.l_sib->m__0color=0;
        f0.l_node=f0.l_parent;
        f0.l_parent=f0.l_parent->m__0parent;
      }else{
        if((!bbBool(f2.l_sib->m__0left)||(f2.l_sib->m__0left->m__0color==1))){
          f2.l_sib->m__0right->m__0color=1;
          f2.l_sib->m__0color=0;
          this->m_RotateLeft(f2.l_sib);
          f2.l_sib=f0.l_parent->m__0left;
        }
        f2.l_sib->m__0color=f0.l_parent->m__0color;
        f0.l_parent->m__0color=1;
        f2.l_sib->m__0left->m__0color=1;
        this->m_RotateRight(f0.l_parent);
        f0.l_node=this->m__0root;
      }
    }
  }
  if(bbBool(f0.l_node)){
    f0.l_node->m__0color=1;
  }
}

bbInt t_std_collections_Map_1sTt_mx2_SNode_2::m_Count(){
  if(!bbBool(this->m__0root)){
    return bbInt(0);
  }
  return this->m__0root->m_Count(bbInt(0));
}

t_std_collections_Map_1sTt_mx2_SNode_2* t_std_collections_Map_1sTt_mx2_SNode_2::m_Copy(){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1sTt_mx2_SNode_2_Node* l_root{};
    void gcMark(){
      bbGCMarkPtr(l_root);
    }
  }f0{};
  if(bbBool(this->m__0root)){
    f0.l_root=this->m__0root->m_Copy(((t_std_collections_Map_1sTt_mx2_SNode_2_Node*)0));
  }
  return bbGCNew<t_std_collections_Map_1sTt_mx2_SNode_2>(f0.l_root);
}

bbBool t_std_collections_Map_1sTt_mx2_SNode_2::m_Contains(bbString l_key){
  return (this->m_FindNode(l_key)!=((t_std_collections_Map_1sTt_mx2_SNode_2_Node*)0));
}

void t_std_collections_Map_1sTt_mx2_SNode_2::m_Clear(){
  this->m__0root=((t_std_collections_Map_1sTt_mx2_SNode_2_Node*)0);
}

t_std_collections_Map_1sTt_mx2_SNode_2_Iterator t_std_collections_Map_1sTt_mx2_SNode_2::m_All(){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1sTt_mx2_SNode_2_Node* t0{};
    void gcMark(){
      bbGCMarkPtr(t0);
    }
  }f0{};
  return t_std_collections_Map_1sTt_mx2_SNode_2_Iterator(f0.t0=this->m_FirstNode());
}

bbBool t_std_collections_Map_1sTt_mx2_SNode_2::m_Add(bbString l_key,t_mx2_SNode* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1sTt_mx2_SNode_2_Node* l_node{};
    t_std_collections_Map_1sTt_mx2_SNode_2_Node* l_parent{};
    void gcMark(){
      bbGCMarkPtr(l_node);
      bbGCMarkPtr(l_parent);
    }
  }f0{};
  if(!bbBool(this->m__0root)){
    this->m__0root=bbGCNew<t_std_collections_Map_1sTt_mx2_SNode_2_Node>(l_key,l_value,0,((t_std_collections_Map_1sTt_mx2_SNode_2_Node*)0));
    return true;
  }
  f0.l_node=this->m__0root;
  bbInt l_cmp{};
  while(bbBool(f0.l_node)){
    f0.l_parent=f0.l_node;
    l_cmp=bbCompare(l_key,f0.l_node->m__0key);
    if((l_cmp>bbInt(0))){
      f0.l_node=f0.l_node->m__0right;
    }else if((l_cmp<bbInt(0))){
      f0.l_node=f0.l_node->m__0left;
    }else{
      return false;
    }
  }
  f0.l_node=bbGCNew<t_std_collections_Map_1sTt_mx2_SNode_2_Node>(l_key,l_value,0,f0.l_parent);
  if((l_cmp>bbInt(0))){
    f0.l_parent->m__0right=f0.l_node;
  }else{
    f0.l_parent->m__0left=f0.l_node;
  }
  this->m_InsertFixup(f0.l_node);
  return true;
}

void t_std_collections_Map_1sTt_mx2_FileDecl_2_Node::gcMark(){
  bbGCMark(m__0value);
  bbGCMark(m__0left);
  bbGCMark(m__0right);
  bbGCMark(m__0parent);
}

t_std_collections_Map_1sTt_mx2_FileDecl_2_Node::t_std_collections_Map_1sTt_mx2_FileDecl_2_Node(bbString l_key,t_mx2_FileDecl* l_value,bbInt l_color,t_std_collections_Map_1sTt_mx2_FileDecl_2_Node* l_parent){
  this->m__0key=l_key;
  this->m__0value=l_value;
  this->m__0color=l_color;
  this->m__0parent=l_parent;
}

t_mx2_FileDecl* t_std_collections_Map_1sTt_mx2_FileDecl_2_Node::m_Value(){
  return this->m__0value;
}

t_std_collections_Map_1sTt_mx2_FileDecl_2_Node* t_std_collections_Map_1sTt_mx2_FileDecl_2_Node::m_PrevNode(){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1sTt_mx2_FileDecl_2_Node* l_node{};
    t_std_collections_Map_1sTt_mx2_FileDecl_2_Node* l_parent{};
    void gcMark(){
      bbGCMarkPtr(l_node);
      bbGCMarkPtr(l_parent);
    }
  }f0{};
  if(bbBool(this->m__0left)){
    struct f1_t : public bbGCFrame{
      t_std_collections_Map_1sTt_mx2_FileDecl_2_Node* l_node{};
      void gcMark(){
        bbGCMarkPtr(l_node);
      }
    }f1{};
    f1.l_node=this->m__0left;
    while(bbBool(f1.l_node->m__0right)){
      f1.l_node=f1.l_node->m__0right;
    }
    return f1.l_node;
  }
  f0.l_node=this;
  f0.l_parent=this->m__0parent;
  while((bbBool(f0.l_parent)&&(f0.l_node==f0.l_parent->m__0left))){
    f0.l_node=f0.l_parent;
    f0.l_parent=f0.l_parent->m__0parent;
  }
  return f0.l_parent;
}

t_std_collections_Map_1sTt_mx2_FileDecl_2_Node* t_std_collections_Map_1sTt_mx2_FileDecl_2_Node::m_NextNode(){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1sTt_mx2_FileDecl_2_Node* l_node{};
    t_std_collections_Map_1sTt_mx2_FileDecl_2_Node* l_parent{};
    void gcMark(){
      bbGCMarkPtr(l_node);
      bbGCMarkPtr(l_parent);
    }
  }f0{};
  if(bbBool(this->m__0right)){
    struct f1_t : public bbGCFrame{
      t_std_collections_Map_1sTt_mx2_FileDecl_2_Node* l_node{};
      void gcMark(){
        bbGCMarkPtr(l_node);
      }
    }f1{};
    f1.l_node=this->m__0right;
    while(bbBool(f1.l_node->m__0left)){
      f1.l_node=f1.l_node->m__0left;
    }
    return f1.l_node;
  }
  f0.l_node=this;
  f0.l_parent=this->m__0parent;
  while((bbBool(f0.l_parent)&&(f0.l_node==f0.l_parent->m__0right))){
    f0.l_node=f0.l_parent;
    f0.l_parent=f0.l_parent->m__0parent;
  }
  return f0.l_parent;
}

bbString t_std_collections_Map_1sTt_mx2_FileDecl_2_Node::m_Key(){
  return this->m__0key;
}

bbInt t_std_collections_Map_1sTt_mx2_FileDecl_2_Node::m_Count(bbInt l_n){
  if(bbBool(this->m__0left)){
    l_n=this->m__0left->m_Count(l_n);
  }
  if(bbBool(this->m__0right)){
    l_n=this->m__0right->m_Count(l_n);
  }
  return (l_n+1);
}

t_std_collections_Map_1sTt_mx2_FileDecl_2_Node* t_std_collections_Map_1sTt_mx2_FileDecl_2_Node::m_Copy(t_std_collections_Map_1sTt_mx2_FileDecl_2_Node* l_parent){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1sTt_mx2_FileDecl_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=bbGCNew<t_std_collections_Map_1sTt_mx2_FileDecl_2_Node>(this->m__0key,this->m__0value,this->m__0color,l_parent);
  if(bbBool(this->m__0left)){
    f0.l_node->m__0left=this->m__0left->m_Copy(f0.l_node);
  }
  if(bbBool(this->m__0right)){
    f0.l_node->m__0right=this->m__0right->m_Copy(f0.l_node);
  }
  return f0.l_node;
}

t_std_collections_Map_1sTt_mx2_FileDecl_2_Iterator::t_std_collections_Map_1sTt_mx2_FileDecl_2_Iterator(t_std_collections_Map_1sTt_mx2_FileDecl_2_Node* l_node){
  (*this).m__0node=l_node;
}

bbBool t_std_collections_Map_1sTt_mx2_FileDecl_2_Iterator::m_Valid(){
  return bbBool((*this).m__0node);
}

t_std_collections_Map_1sTt_mx2_FileDecl_2_Node* t_std_collections_Map_1sTt_mx2_FileDecl_2_Iterator::m_Current(){
  return (*this).m__0node;
}

void t_std_collections_Map_1sTt_mx2_FileDecl_2_Iterator::m_Bump(){
  (*this).m__0node=(*this).m__0node->m_NextNode();
}

int bbCompare(const t_std_collections_Map_1sTt_mx2_FileDecl_2_Iterator&x,const t_std_collections_Map_1sTt_mx2_FileDecl_2_Iterator&y){
  if(int t=bbCompare(x.m__0node,y.m__0node)) return t;
  return 0;
}

void bbGCMark(const t_std_collections_Map_1sTt_mx2_FileDecl_2_Iterator&t){
  bbGCMark(t.m__0node);
}

t_std_collections_Map_1sTt_mx2_FileDecl_2_KeyIterator::t_std_collections_Map_1sTt_mx2_FileDecl_2_KeyIterator(t_std_collections_Map_1sTt_mx2_FileDecl_2_Node* l_node){
  (*this).m__0node=l_node;
}

bbBool t_std_collections_Map_1sTt_mx2_FileDecl_2_KeyIterator::m_Valid(){
  return bbBool((*this).m__0node);
}

bbString t_std_collections_Map_1sTt_mx2_FileDecl_2_KeyIterator::m_Current(){
  return (*this).m__0node->m__0key;
}

void t_std_collections_Map_1sTt_mx2_FileDecl_2_KeyIterator::m_Bump(){
  (*this).m__0node=(*this).m__0node->m_NextNode();
}

int bbCompare(const t_std_collections_Map_1sTt_mx2_FileDecl_2_KeyIterator&x,const t_std_collections_Map_1sTt_mx2_FileDecl_2_KeyIterator&y){
  if(int t=bbCompare(x.m__0node,y.m__0node)) return t;
  return 0;
}

void bbGCMark(const t_std_collections_Map_1sTt_mx2_FileDecl_2_KeyIterator&t){
  bbGCMark(t.m__0node);
}

t_std_collections_Map_1sTt_mx2_FileDecl_2_MapKeys::t_std_collections_Map_1sTt_mx2_FileDecl_2_MapKeys(t_std_collections_Map_1sTt_mx2_FileDecl_2* l_map){
  (*this).m__0map=l_map;
}

t_std_collections_Map_1sTt_mx2_FileDecl_2_KeyIterator t_std_collections_Map_1sTt_mx2_FileDecl_2_MapKeys::m_All(){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1sTt_mx2_FileDecl_2_Node* t0{};
    void gcMark(){
      bbGCMarkPtr(t0);
    }
  }f0{};
  return t_std_collections_Map_1sTt_mx2_FileDecl_2_KeyIterator(f0.t0=(*this).m__0map->m_FirstNode());
}

int bbCompare(const t_std_collections_Map_1sTt_mx2_FileDecl_2_MapKeys&x,const t_std_collections_Map_1sTt_mx2_FileDecl_2_MapKeys&y){
  if(int t=bbCompare(x.m__0map,y.m__0map)) return t;
  return 0;
}

void bbGCMark(const t_std_collections_Map_1sTt_mx2_FileDecl_2_MapKeys&t){
  bbGCMark(t.m__0map);
}

t_std_collections_Map_1sTt_mx2_FileDecl_2_ValueIterator::t_std_collections_Map_1sTt_mx2_FileDecl_2_ValueIterator(t_std_collections_Map_1sTt_mx2_FileDecl_2_Node* l_node){
  (*this).m__0node=l_node;
}

bbBool t_std_collections_Map_1sTt_mx2_FileDecl_2_ValueIterator::m_Valid(){
  return bbBool((*this).m__0node);
}

t_mx2_FileDecl* t_std_collections_Map_1sTt_mx2_FileDecl_2_ValueIterator::m_Current(){
  return (*this).m__0node->m__0value;
}

void t_std_collections_Map_1sTt_mx2_FileDecl_2_ValueIterator::m_Bump(){
  (*this).m__0node=(*this).m__0node->m_NextNode();
}

int bbCompare(const t_std_collections_Map_1sTt_mx2_FileDecl_2_ValueIterator&x,const t_std_collections_Map_1sTt_mx2_FileDecl_2_ValueIterator&y){
  if(int t=bbCompare(x.m__0node,y.m__0node)) return t;
  return 0;
}

void bbGCMark(const t_std_collections_Map_1sTt_mx2_FileDecl_2_ValueIterator&t){
  bbGCMark(t.m__0node);
}

t_std_collections_Map_1sTt_mx2_FileDecl_2_MapValues::t_std_collections_Map_1sTt_mx2_FileDecl_2_MapValues(t_std_collections_Map_1sTt_mx2_FileDecl_2* l_map){
  (*this).m__0map=l_map;
}

t_std_collections_Map_1sTt_mx2_FileDecl_2_ValueIterator t_std_collections_Map_1sTt_mx2_FileDecl_2_MapValues::m_All(){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1sTt_mx2_FileDecl_2_Node* t0{};
    void gcMark(){
      bbGCMarkPtr(t0);
    }
  }f0{};
  return t_std_collections_Map_1sTt_mx2_FileDecl_2_ValueIterator(f0.t0=(*this).m__0map->m_FirstNode());
}

int bbCompare(const t_std_collections_Map_1sTt_mx2_FileDecl_2_MapValues&x,const t_std_collections_Map_1sTt_mx2_FileDecl_2_MapValues&y){
  if(int t=bbCompare(x.m__0map,y.m__0map)) return t;
  return 0;
}

void bbGCMark(const t_std_collections_Map_1sTt_mx2_FileDecl_2_MapValues&t){
  bbGCMark(t.m__0map);
}

void t_std_collections_Map_1sTt_mx2_FileDecl_2::gcMark(){
  bbGCMark(m__0root);
}

t_std_collections_Map_1sTt_mx2_FileDecl_2::t_std_collections_Map_1sTt_mx2_FileDecl_2(t_std_collections_Map_1sTt_mx2_FileDecl_2_Node* l_root){
  this->m__0root=l_root;
}

t_std_collections_Map_1sTt_mx2_FileDecl_2::t_std_collections_Map_1sTt_mx2_FileDecl_2(){
}

void t_std_collections_Map_1sTt_mx2_FileDecl_2::m__idxeq(bbString l_key,t_mx2_FileDecl* l_value){
  this->m_Set(l_key,l_value);
}

t_mx2_FileDecl* t_std_collections_Map_1sTt_mx2_FileDecl_2::m__idx(bbString l_key){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1sTt_mx2_FileDecl_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m_FindNode(l_key);
  if(!bbBool(f0.l_node)){
    return ((t_mx2_FileDecl*)0);
  }
  return f0.l_node->m__0value;
}

t_std_collections_Map_1sTt_mx2_FileDecl_2_MapValues t_std_collections_Map_1sTt_mx2_FileDecl_2::m_Values(){
  return t_std_collections_Map_1sTt_mx2_FileDecl_2_MapValues(this);
}

bbBool t_std_collections_Map_1sTt_mx2_FileDecl_2::m_Update(bbString l_key,t_mx2_FileDecl* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1sTt_mx2_FileDecl_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m_FindNode(l_key);
  if(!bbBool(f0.l_node)){
    return false;
  }
  f0.l_node->m__0value=l_value;
  return true;
}

bbBool t_std_collections_Map_1sTt_mx2_FileDecl_2::m_Set(bbString l_key,t_mx2_FileDecl* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1sTt_mx2_FileDecl_2_Node* l_node{};
    t_std_collections_Map_1sTt_mx2_FileDecl_2_Node* l_parent{};
    void gcMark(){
      bbGCMarkPtr(l_node);
      bbGCMarkPtr(l_parent);
    }
  }f0{};
  if(!bbBool(this->m__0root)){
    this->m__0root=bbGCNew<t_std_collections_Map_1sTt_mx2_FileDecl_2_Node>(l_key,l_value,0,((t_std_collections_Map_1sTt_mx2_FileDecl_2_Node*)0));
    return true;
  }
  f0.l_node=this->m__0root;
  bbInt l_cmp{};
  while(bbBool(f0.l_node)){
    f0.l_parent=f0.l_node;
    l_cmp=bbCompare(l_key,f0.l_node->m__0key);
    if((l_cmp>bbInt(0))){
      f0.l_node=f0.l_node->m__0right;
    }else if((l_cmp<bbInt(0))){
      f0.l_node=f0.l_node->m__0left;
    }else{
      f0.l_node->m__0value=l_value;
      return false;
    }
  }
  f0.l_node=bbGCNew<t_std_collections_Map_1sTt_mx2_FileDecl_2_Node>(l_key,l_value,0,f0.l_parent);
  if((l_cmp>bbInt(0))){
    f0.l_parent->m__0right=f0.l_node;
  }else{
    f0.l_parent->m__0left=f0.l_node;
  }
  this->m_InsertFixup(f0.l_node);
  return true;
}

void t_std_collections_Map_1sTt_mx2_FileDecl_2::m_RotateRight(t_std_collections_Map_1sTt_mx2_FileDecl_2_Node* l_node){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1sTt_mx2_FileDecl_2_Node* l_child{};
    void gcMark(){
      bbGCMarkPtr(l_child);
    }
  }f0{};
  f0.l_child=l_node->m__0left;
  l_node->m__0left=f0.l_child->m__0right;
  if(bbBool(f0.l_child->m__0right)){
    f0.l_child->m__0right->m__0parent=l_node;
  }
  f0.l_child->m__0parent=l_node->m__0parent;
  if(bbBool(l_node->m__0parent)){
    if((l_node==l_node->m__0parent->m__0right)){
      l_node->m__0parent->m__0right=f0.l_child;
    }else{
      l_node->m__0parent->m__0left=f0.l_child;
    }
  }else{
    this->m__0root=f0.l_child;
  }
  f0.l_child->m__0right=l_node;
  l_node->m__0parent=f0.l_child;
}

void t_std_collections_Map_1sTt_mx2_FileDecl_2::m_RotateLeft(t_std_collections_Map_1sTt_mx2_FileDecl_2_Node* l_node){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1sTt_mx2_FileDecl_2_Node* l_child{};
    void gcMark(){
      bbGCMarkPtr(l_child);
    }
  }f0{};
  f0.l_child=l_node->m__0right;
  l_node->m__0right=f0.l_child->m__0left;
  if(bbBool(f0.l_child->m__0left)){
    f0.l_child->m__0left->m__0parent=l_node;
  }
  f0.l_child->m__0parent=l_node->m__0parent;
  if(bbBool(l_node->m__0parent)){
    if((l_node==l_node->m__0parent->m__0left)){
      l_node->m__0parent->m__0left=f0.l_child;
    }else{
      l_node->m__0parent->m__0right=f0.l_child;
    }
  }else{
    this->m__0root=f0.l_child;
  }
  f0.l_child->m__0left=l_node;
  l_node->m__0parent=f0.l_child;
}

void t_std_collections_Map_1sTt_mx2_FileDecl_2::m_RemoveNode(t_std_collections_Map_1sTt_mx2_FileDecl_2_Node* l_node){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1sTt_mx2_FileDecl_2_Node* l_child{};
    t_std_collections_Map_1sTt_mx2_FileDecl_2_Node* l_parent{};
    t_std_collections_Map_1sTt_mx2_FileDecl_2_Node* l_splice{};
    void gcMark(){
      bbGCMarkPtr(l_child);
      bbGCMarkPtr(l_parent);
      bbGCMarkPtr(l_splice);
    }
  }f0{};
  if(!bbBool(l_node->m__0left)){
    f0.l_splice=l_node;
    f0.l_child=l_node->m__0right;
  }else if(!bbBool(l_node->m__0right)){
    f0.l_splice=l_node;
    f0.l_child=l_node->m__0left;
  }else{
    f0.l_splice=l_node->m__0left;
    while(bbBool(f0.l_splice->m__0right)){
      f0.l_splice=f0.l_splice->m__0right;
    }
    f0.l_child=f0.l_splice->m__0left;
    l_node->m__0key=f0.l_splice->m__0key;
    l_node->m__0value=f0.l_splice->m__0value;
  }
  f0.l_parent=f0.l_splice->m__0parent;
  if(bbBool(f0.l_child)){
    f0.l_child->m__0parent=f0.l_parent;
  }
  if(!bbBool(f0.l_parent)){
    this->m__0root=f0.l_child;
    return;
  }
  if((f0.l_splice==f0.l_parent->m__0left)){
    f0.l_parent->m__0left=f0.l_child;
  }else{
    f0.l_parent->m__0right=f0.l_child;
  }
  if((f0.l_splice->m__0color==1)){
    this->m_DeleteFixup(f0.l_child,f0.l_parent);
  }
}

bbBool t_std_collections_Map_1sTt_mx2_FileDecl_2::m_Remove(bbString l_key){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1sTt_mx2_FileDecl_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m_FindNode(l_key);
  if(!bbBool(f0.l_node)){
    return false;
  }
  this->m_RemoveNode(f0.l_node);
  return true;
}

t_std_collections_Map_1sTt_mx2_FileDecl_2_Node* t_std_collections_Map_1sTt_mx2_FileDecl_2::m_LastNode(){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1sTt_mx2_FileDecl_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  if(!bbBool(this->m__0root)){
    return ((t_std_collections_Map_1sTt_mx2_FileDecl_2_Node*)0);
  }
  f0.l_node=this->m__0root;
  while(bbBool(f0.l_node->m__0right)){
    f0.l_node=f0.l_node->m__0right;
  }
  return f0.l_node;
}

t_std_collections_Map_1sTt_mx2_FileDecl_2_MapKeys t_std_collections_Map_1sTt_mx2_FileDecl_2::m_Keys(){
  return t_std_collections_Map_1sTt_mx2_FileDecl_2_MapKeys(this);
}

void t_std_collections_Map_1sTt_mx2_FileDecl_2::m_InsertFixup(t_std_collections_Map_1sTt_mx2_FileDecl_2_Node* l_node){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1sTt_mx2_FileDecl_2_Node* l_node{};
    f0_t(t_std_collections_Map_1sTt_mx2_FileDecl_2_Node* l_node):l_node(l_node){
    }
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{l_node};
  while(((bbBool(f0.l_node->m__0parent)&&(f0.l_node->m__0parent->m__0color==0))&&bbBool(f0.l_node->m__0parent->m__0parent))){
    if((f0.l_node->m__0parent==f0.l_node->m__0parent->m__0parent->m__0left)){
      struct f2_t : public bbGCFrame{
        t_std_collections_Map_1sTt_mx2_FileDecl_2_Node* l_uncle{};
        void gcMark(){
          bbGCMarkPtr(l_uncle);
        }
      }f2{};
      f2.l_uncle=f0.l_node->m__0parent->m__0parent->m__0right;
      if((bbBool(f2.l_uncle)&&(f2.l_uncle->m__0color==0))){
        f0.l_node->m__0parent->m__0color=1;
        f2.l_uncle->m__0color=1;
        f2.l_uncle->m__0parent->m__0color=0;
        f0.l_node=f2.l_uncle->m__0parent;
      }else{
        if((f0.l_node==f0.l_node->m__0parent->m__0right)){
          f0.l_node=f0.l_node->m__0parent;
          this->m_RotateLeft(f0.l_node);
        }
        f0.l_node->m__0parent->m__0color=1;
        f0.l_node->m__0parent->m__0parent->m__0color=0;
        this->m_RotateRight(f0.l_node->m__0parent->m__0parent);
      }
    }else{
      struct f2_t : public bbGCFrame{
        t_std_collections_Map_1sTt_mx2_FileDecl_2_Node* l_uncle{};
        void gcMark(){
          bbGCMarkPtr(l_uncle);
        }
      }f2{};
      f2.l_uncle=f0.l_node->m__0parent->m__0parent->m__0left;
      if((bbBool(f2.l_uncle)&&(f2.l_uncle->m__0color==0))){
        f0.l_node->m__0parent->m__0color=1;
        f2.l_uncle->m__0color=1;
        f2.l_uncle->m__0parent->m__0color=0;
        f0.l_node=f2.l_uncle->m__0parent;
      }else{
        if((f0.l_node==f0.l_node->m__0parent->m__0left)){
          f0.l_node=f0.l_node->m__0parent;
          this->m_RotateRight(f0.l_node);
        }
        f0.l_node->m__0parent->m__0color=1;
        f0.l_node->m__0parent->m__0parent->m__0color=0;
        this->m_RotateLeft(f0.l_node->m__0parent->m__0parent);
      }
    }
  }
  this->m__0root->m__0color=1;
}

t_mx2_FileDecl* t_std_collections_Map_1sTt_mx2_FileDecl_2::m_Get(bbString l_key){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1sTt_mx2_FileDecl_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m_FindNode(l_key);
  if(bbBool(f0.l_node)){
    return f0.l_node->m__0value;
  }
  return ((t_mx2_FileDecl*)0);
}

t_std_collections_Map_1sTt_mx2_FileDecl_2_Node* t_std_collections_Map_1sTt_mx2_FileDecl_2::m_FirstNode(){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1sTt_mx2_FileDecl_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  if(!bbBool(this->m__0root)){
    return ((t_std_collections_Map_1sTt_mx2_FileDecl_2_Node*)0);
  }
  f0.l_node=this->m__0root;
  while(bbBool(f0.l_node->m__0left)){
    f0.l_node=f0.l_node->m__0left;
  }
  return f0.l_node;
}

t_std_collections_Map_1sTt_mx2_FileDecl_2_Node* t_std_collections_Map_1sTt_mx2_FileDecl_2::m_FindNode(bbString l_key){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1sTt_mx2_FileDecl_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m__0root;
  while(bbBool(f0.l_node)){
    bbInt l_cmp=bbCompare(l_key,f0.l_node->m__0key);
    if((l_cmp>bbInt(0))){
      f0.l_node=f0.l_node->m__0right;
    }else if((l_cmp<bbInt(0))){
      f0.l_node=f0.l_node->m__0left;
    }else{
      return f0.l_node;
    }
  }
  return ((t_std_collections_Map_1sTt_mx2_FileDecl_2_Node*)0);
}

bbBool t_std_collections_Map_1sTt_mx2_FileDecl_2::m_Empty(){
  return (this->m__0root==((t_std_collections_Map_1sTt_mx2_FileDecl_2_Node*)0));
}

void t_std_collections_Map_1sTt_mx2_FileDecl_2::m_DeleteFixup(t_std_collections_Map_1sTt_mx2_FileDecl_2_Node* l_node,t_std_collections_Map_1sTt_mx2_FileDecl_2_Node* l_parent){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1sTt_mx2_FileDecl_2_Node* l_node{};
    t_std_collections_Map_1sTt_mx2_FileDecl_2_Node* l_parent{};
    f0_t(t_std_collections_Map_1sTt_mx2_FileDecl_2_Node* l_node,t_std_collections_Map_1sTt_mx2_FileDecl_2_Node* l_parent):l_node(l_node),l_parent(l_parent){
    }
    void gcMark(){
      bbGCMarkPtr(l_node);
      bbGCMarkPtr(l_parent);
    }
  }f0{l_node,l_parent};
  while(((f0.l_node!=this->m__0root)&&(!bbBool(f0.l_node)||(f0.l_node->m__0color==1)))){
    if((f0.l_node==f0.l_parent->m__0left)){
      struct f2_t : public bbGCFrame{
        t_std_collections_Map_1sTt_mx2_FileDecl_2_Node* l_sib{};
        void gcMark(){
          bbGCMarkPtr(l_sib);
        }
      }f2{};
      f2.l_sib=f0.l_parent->m__0right;
      if((f2.l_sib->m__0color==0)){
        f2.l_sib->m__0color=1;
        f0.l_parent->m__0color=0;
        this->m_RotateLeft(f0.l_parent);
        f2.l_sib=f0.l_parent->m__0right;
      }
      if(((!bbBool(f2.l_sib->m__0left)||(f2.l_sib->m__0left->m__0color==1))&&(!bbBool(f2.l_sib->m__0right)||(f2.l_sib->m__0right->m__0color==1)))){
        f2.l_sib->m__0color=0;
        f0.l_node=f0.l_parent;
        f0.l_parent=f0.l_parent->m__0parent;
      }else{
        if((!bbBool(f2.l_sib->m__0right)||(f2.l_sib->m__0right->m__0color==1))){
          f2.l_sib->m__0left->m__0color=1;
          f2.l_sib->m__0color=0;
          this->m_RotateRight(f2.l_sib);
          f2.l_sib=f0.l_parent->m__0right;
        }
        f2.l_sib->m__0color=f0.l_parent->m__0color;
        f0.l_parent->m__0color=1;
        f2.l_sib->m__0right->m__0color=1;
        this->m_RotateLeft(f0.l_parent);
        f0.l_node=this->m__0root;
      }
    }else{
      struct f2_t : public bbGCFrame{
        t_std_collections_Map_1sTt_mx2_FileDecl_2_Node* l_sib{};
        void gcMark(){
          bbGCMarkPtr(l_sib);
        }
      }f2{};
      f2.l_sib=f0.l_parent->m__0left;
      if((f2.l_sib->m__0color==0)){
        f2.l_sib->m__0color=1;
        f0.l_parent->m__0color=0;
        this->m_RotateRight(f0.l_parent);
        f2.l_sib=f0.l_parent->m__0left;
      }
      if(((!bbBool(f2.l_sib->m__0right)||(f2.l_sib->m__0right->m__0color==1))&&(!bbBool(f2.l_sib->m__0left)||(f2.l_sib->m__0left->m__0color==1)))){
        f2.l_sib->m__0color=0;
        f0.l_node=f0.l_parent;
        f0.l_parent=f0.l_parent->m__0parent;
      }else{
        if((!bbBool(f2.l_sib->m__0left)||(f2.l_sib->m__0left->m__0color==1))){
          f2.l_sib->m__0right->m__0color=1;
          f2.l_sib->m__0color=0;
          this->m_RotateLeft(f2.l_sib);
          f2.l_sib=f0.l_parent->m__0left;
        }
        f2.l_sib->m__0color=f0.l_parent->m__0color;
        f0.l_parent->m__0color=1;
        f2.l_sib->m__0left->m__0color=1;
        this->m_RotateRight(f0.l_parent);
        f0.l_node=this->m__0root;
      }
    }
  }
  if(bbBool(f0.l_node)){
    f0.l_node->m__0color=1;
  }
}

bbInt t_std_collections_Map_1sTt_mx2_FileDecl_2::m_Count(){
  if(!bbBool(this->m__0root)){
    return bbInt(0);
  }
  return this->m__0root->m_Count(bbInt(0));
}

t_std_collections_Map_1sTt_mx2_FileDecl_2* t_std_collections_Map_1sTt_mx2_FileDecl_2::m_Copy(){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1sTt_mx2_FileDecl_2_Node* l_root{};
    void gcMark(){
      bbGCMarkPtr(l_root);
    }
  }f0{};
  if(bbBool(this->m__0root)){
    f0.l_root=this->m__0root->m_Copy(((t_std_collections_Map_1sTt_mx2_FileDecl_2_Node*)0));
  }
  return bbGCNew<t_std_collections_Map_1sTt_mx2_FileDecl_2>(f0.l_root);
}

bbBool t_std_collections_Map_1sTt_mx2_FileDecl_2::m_Contains(bbString l_key){
  return (this->m_FindNode(l_key)!=((t_std_collections_Map_1sTt_mx2_FileDecl_2_Node*)0));
}

void t_std_collections_Map_1sTt_mx2_FileDecl_2::m_Clear(){
  this->m__0root=((t_std_collections_Map_1sTt_mx2_FileDecl_2_Node*)0);
}

t_std_collections_Map_1sTt_mx2_FileDecl_2_Iterator t_std_collections_Map_1sTt_mx2_FileDecl_2::m_All(){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1sTt_mx2_FileDecl_2_Node* t0{};
    void gcMark(){
      bbGCMarkPtr(t0);
    }
  }f0{};
  return t_std_collections_Map_1sTt_mx2_FileDecl_2_Iterator(f0.t0=this->m_FirstNode());
}

bbBool t_std_collections_Map_1sTt_mx2_FileDecl_2::m_Add(bbString l_key,t_mx2_FileDecl* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1sTt_mx2_FileDecl_2_Node* l_node{};
    t_std_collections_Map_1sTt_mx2_FileDecl_2_Node* l_parent{};
    void gcMark(){
      bbGCMarkPtr(l_node);
      bbGCMarkPtr(l_parent);
    }
  }f0{};
  if(!bbBool(this->m__0root)){
    this->m__0root=bbGCNew<t_std_collections_Map_1sTt_mx2_FileDecl_2_Node>(l_key,l_value,0,((t_std_collections_Map_1sTt_mx2_FileDecl_2_Node*)0));
    return true;
  }
  f0.l_node=this->m__0root;
  bbInt l_cmp{};
  while(bbBool(f0.l_node)){
    f0.l_parent=f0.l_node;
    l_cmp=bbCompare(l_key,f0.l_node->m__0key);
    if((l_cmp>bbInt(0))){
      f0.l_node=f0.l_node->m__0right;
    }else if((l_cmp<bbInt(0))){
      f0.l_node=f0.l_node->m__0left;
    }else{
      return false;
    }
  }
  f0.l_node=bbGCNew<t_std_collections_Map_1sTt_mx2_FileDecl_2_Node>(l_key,l_value,0,f0.l_parent);
  if((l_cmp>bbInt(0))){
    f0.l_parent->m__0right=f0.l_node;
  }else{
    f0.l_parent->m__0left=f0.l_node;
  }
  this->m_InsertFixup(f0.l_node);
  return true;
}

void t_std_collections_Map_1Tt_mx2_SNode_2z_Node::gcMark(){
  bbGCMark(m__0key);
  bbGCMark(m__0left);
  bbGCMark(m__0right);
  bbGCMark(m__0parent);
}

t_std_collections_Map_1Tt_mx2_SNode_2z_Node::t_std_collections_Map_1Tt_mx2_SNode_2z_Node(t_mx2_SNode* l_key,bbBool l_value,bbInt l_color,t_std_collections_Map_1Tt_mx2_SNode_2z_Node* l_parent){
  this->m__0key=l_key;
  this->m__0value=l_value;
  this->m__0color=l_color;
  this->m__0parent=l_parent;
}

bbBool t_std_collections_Map_1Tt_mx2_SNode_2z_Node::m_Value(){
  return this->m__0value;
}

t_std_collections_Map_1Tt_mx2_SNode_2z_Node* t_std_collections_Map_1Tt_mx2_SNode_2z_Node::m_PrevNode(){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1Tt_mx2_SNode_2z_Node* l_node{};
    t_std_collections_Map_1Tt_mx2_SNode_2z_Node* l_parent{};
    void gcMark(){
      bbGCMarkPtr(l_node);
      bbGCMarkPtr(l_parent);
    }
  }f0{};
  if(bbBool(this->m__0left)){
    struct f1_t : public bbGCFrame{
      t_std_collections_Map_1Tt_mx2_SNode_2z_Node* l_node{};
      void gcMark(){
        bbGCMarkPtr(l_node);
      }
    }f1{};
    f1.l_node=this->m__0left;
    while(bbBool(f1.l_node->m__0right)){
      f1.l_node=f1.l_node->m__0right;
    }
    return f1.l_node;
  }
  f0.l_node=this;
  f0.l_parent=this->m__0parent;
  while((bbBool(f0.l_parent)&&(f0.l_node==f0.l_parent->m__0left))){
    f0.l_node=f0.l_parent;
    f0.l_parent=f0.l_parent->m__0parent;
  }
  return f0.l_parent;
}

t_std_collections_Map_1Tt_mx2_SNode_2z_Node* t_std_collections_Map_1Tt_mx2_SNode_2z_Node::m_NextNode(){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1Tt_mx2_SNode_2z_Node* l_node{};
    t_std_collections_Map_1Tt_mx2_SNode_2z_Node* l_parent{};
    void gcMark(){
      bbGCMarkPtr(l_node);
      bbGCMarkPtr(l_parent);
    }
  }f0{};
  if(bbBool(this->m__0right)){
    struct f1_t : public bbGCFrame{
      t_std_collections_Map_1Tt_mx2_SNode_2z_Node* l_node{};
      void gcMark(){
        bbGCMarkPtr(l_node);
      }
    }f1{};
    f1.l_node=this->m__0right;
    while(bbBool(f1.l_node->m__0left)){
      f1.l_node=f1.l_node->m__0left;
    }
    return f1.l_node;
  }
  f0.l_node=this;
  f0.l_parent=this->m__0parent;
  while((bbBool(f0.l_parent)&&(f0.l_node==f0.l_parent->m__0right))){
    f0.l_node=f0.l_parent;
    f0.l_parent=f0.l_parent->m__0parent;
  }
  return f0.l_parent;
}

t_mx2_SNode* t_std_collections_Map_1Tt_mx2_SNode_2z_Node::m_Key(){
  return this->m__0key;
}

bbInt t_std_collections_Map_1Tt_mx2_SNode_2z_Node::m_Count(bbInt l_n){
  if(bbBool(this->m__0left)){
    l_n=this->m__0left->m_Count(l_n);
  }
  if(bbBool(this->m__0right)){
    l_n=this->m__0right->m_Count(l_n);
  }
  return (l_n+1);
}

t_std_collections_Map_1Tt_mx2_SNode_2z_Node* t_std_collections_Map_1Tt_mx2_SNode_2z_Node::m_Copy(t_std_collections_Map_1Tt_mx2_SNode_2z_Node* l_parent){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1Tt_mx2_SNode_2z_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=bbGCNew<t_std_collections_Map_1Tt_mx2_SNode_2z_Node>(this->m__0key,this->m__0value,this->m__0color,l_parent);
  if(bbBool(this->m__0left)){
    f0.l_node->m__0left=this->m__0left->m_Copy(f0.l_node);
  }
  if(bbBool(this->m__0right)){
    f0.l_node->m__0right=this->m__0right->m_Copy(f0.l_node);
  }
  return f0.l_node;
}

t_std_collections_Map_1Tt_mx2_SNode_2z_Iterator::t_std_collections_Map_1Tt_mx2_SNode_2z_Iterator(t_std_collections_Map_1Tt_mx2_SNode_2z_Node* l_node){
  (*this).m__0node=l_node;
}

bbBool t_std_collections_Map_1Tt_mx2_SNode_2z_Iterator::m_Valid(){
  return bbBool((*this).m__0node);
}

t_std_collections_Map_1Tt_mx2_SNode_2z_Node* t_std_collections_Map_1Tt_mx2_SNode_2z_Iterator::m_Current(){
  return (*this).m__0node;
}

void t_std_collections_Map_1Tt_mx2_SNode_2z_Iterator::m_Bump(){
  (*this).m__0node=(*this).m__0node->m_NextNode();
}

int bbCompare(const t_std_collections_Map_1Tt_mx2_SNode_2z_Iterator&x,const t_std_collections_Map_1Tt_mx2_SNode_2z_Iterator&y){
  if(int t=bbCompare(x.m__0node,y.m__0node)) return t;
  return 0;
}

void bbGCMark(const t_std_collections_Map_1Tt_mx2_SNode_2z_Iterator&t){
  bbGCMark(t.m__0node);
}

t_std_collections_Map_1Tt_mx2_SNode_2z_KeyIterator::t_std_collections_Map_1Tt_mx2_SNode_2z_KeyIterator(t_std_collections_Map_1Tt_mx2_SNode_2z_Node* l_node){
  (*this).m__0node=l_node;
}

bbBool t_std_collections_Map_1Tt_mx2_SNode_2z_KeyIterator::m_Valid(){
  return bbBool((*this).m__0node);
}

t_mx2_SNode* t_std_collections_Map_1Tt_mx2_SNode_2z_KeyIterator::m_Current(){
  return (*this).m__0node->m__0key;
}

void t_std_collections_Map_1Tt_mx2_SNode_2z_KeyIterator::m_Bump(){
  (*this).m__0node=(*this).m__0node->m_NextNode();
}

int bbCompare(const t_std_collections_Map_1Tt_mx2_SNode_2z_KeyIterator&x,const t_std_collections_Map_1Tt_mx2_SNode_2z_KeyIterator&y){
  if(int t=bbCompare(x.m__0node,y.m__0node)) return t;
  return 0;
}

void bbGCMark(const t_std_collections_Map_1Tt_mx2_SNode_2z_KeyIterator&t){
  bbGCMark(t.m__0node);
}

t_std_collections_Map_1Tt_mx2_SNode_2z_MapKeys::t_std_collections_Map_1Tt_mx2_SNode_2z_MapKeys(t_std_collections_Map_1Tt_mx2_SNode_2z* l_map){
  (*this).m__0map=l_map;
}

t_std_collections_Map_1Tt_mx2_SNode_2z_KeyIterator t_std_collections_Map_1Tt_mx2_SNode_2z_MapKeys::m_All(){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1Tt_mx2_SNode_2z_Node* t0{};
    void gcMark(){
      bbGCMarkPtr(t0);
    }
  }f0{};
  return t_std_collections_Map_1Tt_mx2_SNode_2z_KeyIterator(f0.t0=(*this).m__0map->m_FirstNode());
}

int bbCompare(const t_std_collections_Map_1Tt_mx2_SNode_2z_MapKeys&x,const t_std_collections_Map_1Tt_mx2_SNode_2z_MapKeys&y){
  if(int t=bbCompare(x.m__0map,y.m__0map)) return t;
  return 0;
}

void bbGCMark(const t_std_collections_Map_1Tt_mx2_SNode_2z_MapKeys&t){
  bbGCMark(t.m__0map);
}

t_std_collections_Map_1Tt_mx2_SNode_2z_ValueIterator::t_std_collections_Map_1Tt_mx2_SNode_2z_ValueIterator(t_std_collections_Map_1Tt_mx2_SNode_2z_Node* l_node){
  (*this).m__0node=l_node;
}

bbBool t_std_collections_Map_1Tt_mx2_SNode_2z_ValueIterator::m_Valid(){
  return bbBool((*this).m__0node);
}

bbBool t_std_collections_Map_1Tt_mx2_SNode_2z_ValueIterator::m_Current(){
  return (*this).m__0node->m__0value;
}

void t_std_collections_Map_1Tt_mx2_SNode_2z_ValueIterator::m_Bump(){
  (*this).m__0node=(*this).m__0node->m_NextNode();
}

int bbCompare(const t_std_collections_Map_1Tt_mx2_SNode_2z_ValueIterator&x,const t_std_collections_Map_1Tt_mx2_SNode_2z_ValueIterator&y){
  if(int t=bbCompare(x.m__0node,y.m__0node)) return t;
  return 0;
}

void bbGCMark(const t_std_collections_Map_1Tt_mx2_SNode_2z_ValueIterator&t){
  bbGCMark(t.m__0node);
}

t_std_collections_Map_1Tt_mx2_SNode_2z_MapValues::t_std_collections_Map_1Tt_mx2_SNode_2z_MapValues(t_std_collections_Map_1Tt_mx2_SNode_2z* l_map){
  (*this).m__0map=l_map;
}

t_std_collections_Map_1Tt_mx2_SNode_2z_ValueIterator t_std_collections_Map_1Tt_mx2_SNode_2z_MapValues::m_All(){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1Tt_mx2_SNode_2z_Node* t0{};
    void gcMark(){
      bbGCMarkPtr(t0);
    }
  }f0{};
  return t_std_collections_Map_1Tt_mx2_SNode_2z_ValueIterator(f0.t0=(*this).m__0map->m_FirstNode());
}

int bbCompare(const t_std_collections_Map_1Tt_mx2_SNode_2z_MapValues&x,const t_std_collections_Map_1Tt_mx2_SNode_2z_MapValues&y){
  if(int t=bbCompare(x.m__0map,y.m__0map)) return t;
  return 0;
}

void bbGCMark(const t_std_collections_Map_1Tt_mx2_SNode_2z_MapValues&t){
  bbGCMark(t.m__0map);
}

void t_std_collections_Map_1Tt_mx2_SNode_2z::gcMark(){
  bbGCMark(m__0root);
}

t_std_collections_Map_1Tt_mx2_SNode_2z::t_std_collections_Map_1Tt_mx2_SNode_2z(t_std_collections_Map_1Tt_mx2_SNode_2z_Node* l_root){
  this->m__0root=l_root;
}

t_std_collections_Map_1Tt_mx2_SNode_2z::t_std_collections_Map_1Tt_mx2_SNode_2z(){
}

void t_std_collections_Map_1Tt_mx2_SNode_2z::m__idxeq(t_mx2_SNode* l_key,bbBool l_value){
  this->m_Set(l_key,l_value);
}

bbBool t_std_collections_Map_1Tt_mx2_SNode_2z::m__idx(t_mx2_SNode* l_key){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1Tt_mx2_SNode_2z_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m_FindNode(l_key);
  if(!bbBool(f0.l_node)){
    return false;
  }
  return f0.l_node->m__0value;
}

t_std_collections_Map_1Tt_mx2_SNode_2z_MapValues t_std_collections_Map_1Tt_mx2_SNode_2z::m_Values(){
  return t_std_collections_Map_1Tt_mx2_SNode_2z_MapValues(this);
}

bbBool t_std_collections_Map_1Tt_mx2_SNode_2z::m_Update(t_mx2_SNode* l_key,bbBool l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1Tt_mx2_SNode_2z_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m_FindNode(l_key);
  if(!bbBool(f0.l_node)){
    return false;
  }
  f0.l_node->m__0value=l_value;
  return true;
}

bbBool t_std_collections_Map_1Tt_mx2_SNode_2z::m_Set(t_mx2_SNode* l_key,bbBool l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1Tt_mx2_SNode_2z_Node* l_node{};
    t_std_collections_Map_1Tt_mx2_SNode_2z_Node* l_parent{};
    void gcMark(){
      bbGCMarkPtr(l_node);
      bbGCMarkPtr(l_parent);
    }
  }f0{};
  if(!bbBool(this->m__0root)){
    this->m__0root=bbGCNew<t_std_collections_Map_1Tt_mx2_SNode_2z_Node>(l_key,l_value,0,((t_std_collections_Map_1Tt_mx2_SNode_2z_Node*)0));
    return true;
  }
  f0.l_node=this->m__0root;
  bbInt l_cmp{};
  while(bbBool(f0.l_node)){
    f0.l_parent=f0.l_node;
    l_cmp=bbCompare(l_key,f0.l_node->m__0key);
    if((l_cmp>bbInt(0))){
      f0.l_node=f0.l_node->m__0right;
    }else if((l_cmp<bbInt(0))){
      f0.l_node=f0.l_node->m__0left;
    }else{
      f0.l_node->m__0value=l_value;
      return false;
    }
  }
  f0.l_node=bbGCNew<t_std_collections_Map_1Tt_mx2_SNode_2z_Node>(l_key,l_value,0,f0.l_parent);
  if((l_cmp>bbInt(0))){
    f0.l_parent->m__0right=f0.l_node;
  }else{
    f0.l_parent->m__0left=f0.l_node;
  }
  this->m_InsertFixup(f0.l_node);
  return true;
}

void t_std_collections_Map_1Tt_mx2_SNode_2z::m_RotateRight(t_std_collections_Map_1Tt_mx2_SNode_2z_Node* l_node){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1Tt_mx2_SNode_2z_Node* l_child{};
    void gcMark(){
      bbGCMarkPtr(l_child);
    }
  }f0{};
  f0.l_child=l_node->m__0left;
  l_node->m__0left=f0.l_child->m__0right;
  if(bbBool(f0.l_child->m__0right)){
    f0.l_child->m__0right->m__0parent=l_node;
  }
  f0.l_child->m__0parent=l_node->m__0parent;
  if(bbBool(l_node->m__0parent)){
    if((l_node==l_node->m__0parent->m__0right)){
      l_node->m__0parent->m__0right=f0.l_child;
    }else{
      l_node->m__0parent->m__0left=f0.l_child;
    }
  }else{
    this->m__0root=f0.l_child;
  }
  f0.l_child->m__0right=l_node;
  l_node->m__0parent=f0.l_child;
}

void t_std_collections_Map_1Tt_mx2_SNode_2z::m_RotateLeft(t_std_collections_Map_1Tt_mx2_SNode_2z_Node* l_node){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1Tt_mx2_SNode_2z_Node* l_child{};
    void gcMark(){
      bbGCMarkPtr(l_child);
    }
  }f0{};
  f0.l_child=l_node->m__0right;
  l_node->m__0right=f0.l_child->m__0left;
  if(bbBool(f0.l_child->m__0left)){
    f0.l_child->m__0left->m__0parent=l_node;
  }
  f0.l_child->m__0parent=l_node->m__0parent;
  if(bbBool(l_node->m__0parent)){
    if((l_node==l_node->m__0parent->m__0left)){
      l_node->m__0parent->m__0left=f0.l_child;
    }else{
      l_node->m__0parent->m__0right=f0.l_child;
    }
  }else{
    this->m__0root=f0.l_child;
  }
  f0.l_child->m__0left=l_node;
  l_node->m__0parent=f0.l_child;
}

void t_std_collections_Map_1Tt_mx2_SNode_2z::m_RemoveNode(t_std_collections_Map_1Tt_mx2_SNode_2z_Node* l_node){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1Tt_mx2_SNode_2z_Node* l_child{};
    t_std_collections_Map_1Tt_mx2_SNode_2z_Node* l_parent{};
    t_std_collections_Map_1Tt_mx2_SNode_2z_Node* l_splice{};
    void gcMark(){
      bbGCMarkPtr(l_child);
      bbGCMarkPtr(l_parent);
      bbGCMarkPtr(l_splice);
    }
  }f0{};
  if(!bbBool(l_node->m__0left)){
    f0.l_splice=l_node;
    f0.l_child=l_node->m__0right;
  }else if(!bbBool(l_node->m__0right)){
    f0.l_splice=l_node;
    f0.l_child=l_node->m__0left;
  }else{
    f0.l_splice=l_node->m__0left;
    while(bbBool(f0.l_splice->m__0right)){
      f0.l_splice=f0.l_splice->m__0right;
    }
    f0.l_child=f0.l_splice->m__0left;
    l_node->m__0key=f0.l_splice->m__0key;
    l_node->m__0value=f0.l_splice->m__0value;
  }
  f0.l_parent=f0.l_splice->m__0parent;
  if(bbBool(f0.l_child)){
    f0.l_child->m__0parent=f0.l_parent;
  }
  if(!bbBool(f0.l_parent)){
    this->m__0root=f0.l_child;
    return;
  }
  if((f0.l_splice==f0.l_parent->m__0left)){
    f0.l_parent->m__0left=f0.l_child;
  }else{
    f0.l_parent->m__0right=f0.l_child;
  }
  if((f0.l_splice->m__0color==1)){
    this->m_DeleteFixup(f0.l_child,f0.l_parent);
  }
}

bbBool t_std_collections_Map_1Tt_mx2_SNode_2z::m_Remove(t_mx2_SNode* l_key){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1Tt_mx2_SNode_2z_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m_FindNode(l_key);
  if(!bbBool(f0.l_node)){
    return false;
  }
  this->m_RemoveNode(f0.l_node);
  return true;
}

t_std_collections_Map_1Tt_mx2_SNode_2z_Node* t_std_collections_Map_1Tt_mx2_SNode_2z::m_LastNode(){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1Tt_mx2_SNode_2z_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  if(!bbBool(this->m__0root)){
    return ((t_std_collections_Map_1Tt_mx2_SNode_2z_Node*)0);
  }
  f0.l_node=this->m__0root;
  while(bbBool(f0.l_node->m__0right)){
    f0.l_node=f0.l_node->m__0right;
  }
  return f0.l_node;
}

t_std_collections_Map_1Tt_mx2_SNode_2z_MapKeys t_std_collections_Map_1Tt_mx2_SNode_2z::m_Keys(){
  return t_std_collections_Map_1Tt_mx2_SNode_2z_MapKeys(this);
}

void t_std_collections_Map_1Tt_mx2_SNode_2z::m_InsertFixup(t_std_collections_Map_1Tt_mx2_SNode_2z_Node* l_node){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1Tt_mx2_SNode_2z_Node* l_node{};
    f0_t(t_std_collections_Map_1Tt_mx2_SNode_2z_Node* l_node):l_node(l_node){
    }
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{l_node};
  while(((bbBool(f0.l_node->m__0parent)&&(f0.l_node->m__0parent->m__0color==0))&&bbBool(f0.l_node->m__0parent->m__0parent))){
    if((f0.l_node->m__0parent==f0.l_node->m__0parent->m__0parent->m__0left)){
      struct f2_t : public bbGCFrame{
        t_std_collections_Map_1Tt_mx2_SNode_2z_Node* l_uncle{};
        void gcMark(){
          bbGCMarkPtr(l_uncle);
        }
      }f2{};
      f2.l_uncle=f0.l_node->m__0parent->m__0parent->m__0right;
      if((bbBool(f2.l_uncle)&&(f2.l_uncle->m__0color==0))){
        f0.l_node->m__0parent->m__0color=1;
        f2.l_uncle->m__0color=1;
        f2.l_uncle->m__0parent->m__0color=0;
        f0.l_node=f2.l_uncle->m__0parent;
      }else{
        if((f0.l_node==f0.l_node->m__0parent->m__0right)){
          f0.l_node=f0.l_node->m__0parent;
          this->m_RotateLeft(f0.l_node);
        }
        f0.l_node->m__0parent->m__0color=1;
        f0.l_node->m__0parent->m__0parent->m__0color=0;
        this->m_RotateRight(f0.l_node->m__0parent->m__0parent);
      }
    }else{
      struct f2_t : public bbGCFrame{
        t_std_collections_Map_1Tt_mx2_SNode_2z_Node* l_uncle{};
        void gcMark(){
          bbGCMarkPtr(l_uncle);
        }
      }f2{};
      f2.l_uncle=f0.l_node->m__0parent->m__0parent->m__0left;
      if((bbBool(f2.l_uncle)&&(f2.l_uncle->m__0color==0))){
        f0.l_node->m__0parent->m__0color=1;
        f2.l_uncle->m__0color=1;
        f2.l_uncle->m__0parent->m__0color=0;
        f0.l_node=f2.l_uncle->m__0parent;
      }else{
        if((f0.l_node==f0.l_node->m__0parent->m__0left)){
          f0.l_node=f0.l_node->m__0parent;
          this->m_RotateRight(f0.l_node);
        }
        f0.l_node->m__0parent->m__0color=1;
        f0.l_node->m__0parent->m__0parent->m__0color=0;
        this->m_RotateLeft(f0.l_node->m__0parent->m__0parent);
      }
    }
  }
  this->m__0root->m__0color=1;
}

bbBool t_std_collections_Map_1Tt_mx2_SNode_2z::m_Get(t_mx2_SNode* l_key){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1Tt_mx2_SNode_2z_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m_FindNode(l_key);
  if(bbBool(f0.l_node)){
    return f0.l_node->m__0value;
  }
  return false;
}

t_std_collections_Map_1Tt_mx2_SNode_2z_Node* t_std_collections_Map_1Tt_mx2_SNode_2z::m_FirstNode(){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1Tt_mx2_SNode_2z_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  if(!bbBool(this->m__0root)){
    return ((t_std_collections_Map_1Tt_mx2_SNode_2z_Node*)0);
  }
  f0.l_node=this->m__0root;
  while(bbBool(f0.l_node->m__0left)){
    f0.l_node=f0.l_node->m__0left;
  }
  return f0.l_node;
}

t_std_collections_Map_1Tt_mx2_SNode_2z_Node* t_std_collections_Map_1Tt_mx2_SNode_2z::m_FindNode(t_mx2_SNode* l_key){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1Tt_mx2_SNode_2z_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m__0root;
  while(bbBool(f0.l_node)){
    bbInt l_cmp=bbCompare(l_key,f0.l_node->m__0key);
    if((l_cmp>bbInt(0))){
      f0.l_node=f0.l_node->m__0right;
    }else if((l_cmp<bbInt(0))){
      f0.l_node=f0.l_node->m__0left;
    }else{
      return f0.l_node;
    }
  }
  return ((t_std_collections_Map_1Tt_mx2_SNode_2z_Node*)0);
}

bbBool t_std_collections_Map_1Tt_mx2_SNode_2z::m_Empty(){
  return (this->m__0root==((t_std_collections_Map_1Tt_mx2_SNode_2z_Node*)0));
}

void t_std_collections_Map_1Tt_mx2_SNode_2z::m_DeleteFixup(t_std_collections_Map_1Tt_mx2_SNode_2z_Node* l_node,t_std_collections_Map_1Tt_mx2_SNode_2z_Node* l_parent){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1Tt_mx2_SNode_2z_Node* l_node{};
    t_std_collections_Map_1Tt_mx2_SNode_2z_Node* l_parent{};
    f0_t(t_std_collections_Map_1Tt_mx2_SNode_2z_Node* l_node,t_std_collections_Map_1Tt_mx2_SNode_2z_Node* l_parent):l_node(l_node),l_parent(l_parent){
    }
    void gcMark(){
      bbGCMarkPtr(l_node);
      bbGCMarkPtr(l_parent);
    }
  }f0{l_node,l_parent};
  while(((f0.l_node!=this->m__0root)&&(!bbBool(f0.l_node)||(f0.l_node->m__0color==1)))){
    if((f0.l_node==f0.l_parent->m__0left)){
      struct f2_t : public bbGCFrame{
        t_std_collections_Map_1Tt_mx2_SNode_2z_Node* l_sib{};
        void gcMark(){
          bbGCMarkPtr(l_sib);
        }
      }f2{};
      f2.l_sib=f0.l_parent->m__0right;
      if((f2.l_sib->m__0color==0)){
        f2.l_sib->m__0color=1;
        f0.l_parent->m__0color=0;
        this->m_RotateLeft(f0.l_parent);
        f2.l_sib=f0.l_parent->m__0right;
      }
      if(((!bbBool(f2.l_sib->m__0left)||(f2.l_sib->m__0left->m__0color==1))&&(!bbBool(f2.l_sib->m__0right)||(f2.l_sib->m__0right->m__0color==1)))){
        f2.l_sib->m__0color=0;
        f0.l_node=f0.l_parent;
        f0.l_parent=f0.l_parent->m__0parent;
      }else{
        if((!bbBool(f2.l_sib->m__0right)||(f2.l_sib->m__0right->m__0color==1))){
          f2.l_sib->m__0left->m__0color=1;
          f2.l_sib->m__0color=0;
          this->m_RotateRight(f2.l_sib);
          f2.l_sib=f0.l_parent->m__0right;
        }
        f2.l_sib->m__0color=f0.l_parent->m__0color;
        f0.l_parent->m__0color=1;
        f2.l_sib->m__0right->m__0color=1;
        this->m_RotateLeft(f0.l_parent);
        f0.l_node=this->m__0root;
      }
    }else{
      struct f2_t : public bbGCFrame{
        t_std_collections_Map_1Tt_mx2_SNode_2z_Node* l_sib{};
        void gcMark(){
          bbGCMarkPtr(l_sib);
        }
      }f2{};
      f2.l_sib=f0.l_parent->m__0left;
      if((f2.l_sib->m__0color==0)){
        f2.l_sib->m__0color=1;
        f0.l_parent->m__0color=0;
        this->m_RotateRight(f0.l_parent);
        f2.l_sib=f0.l_parent->m__0left;
      }
      if(((!bbBool(f2.l_sib->m__0right)||(f2.l_sib->m__0right->m__0color==1))&&(!bbBool(f2.l_sib->m__0left)||(f2.l_sib->m__0left->m__0color==1)))){
        f2.l_sib->m__0color=0;
        f0.l_node=f0.l_parent;
        f0.l_parent=f0.l_parent->m__0parent;
      }else{
        if((!bbBool(f2.l_sib->m__0left)||(f2.l_sib->m__0left->m__0color==1))){
          f2.l_sib->m__0right->m__0color=1;
          f2.l_sib->m__0color=0;
          this->m_RotateLeft(f2.l_sib);
          f2.l_sib=f0.l_parent->m__0left;
        }
        f2.l_sib->m__0color=f0.l_parent->m__0color;
        f0.l_parent->m__0color=1;
        f2.l_sib->m__0left->m__0color=1;
        this->m_RotateRight(f0.l_parent);
        f0.l_node=this->m__0root;
      }
    }
  }
  if(bbBool(f0.l_node)){
    f0.l_node->m__0color=1;
  }
}

bbInt t_std_collections_Map_1Tt_mx2_SNode_2z::m_Count(){
  if(!bbBool(this->m__0root)){
    return bbInt(0);
  }
  return this->m__0root->m_Count(bbInt(0));
}

t_std_collections_Map_1Tt_mx2_SNode_2z* t_std_collections_Map_1Tt_mx2_SNode_2z::m_Copy(){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1Tt_mx2_SNode_2z_Node* l_root{};
    void gcMark(){
      bbGCMarkPtr(l_root);
    }
  }f0{};
  if(bbBool(this->m__0root)){
    f0.l_root=this->m__0root->m_Copy(((t_std_collections_Map_1Tt_mx2_SNode_2z_Node*)0));
  }
  return bbGCNew<t_std_collections_Map_1Tt_mx2_SNode_2z>(f0.l_root);
}

bbBool t_std_collections_Map_1Tt_mx2_SNode_2z::m_Contains(t_mx2_SNode* l_key){
  return (this->m_FindNode(l_key)!=((t_std_collections_Map_1Tt_mx2_SNode_2z_Node*)0));
}

void t_std_collections_Map_1Tt_mx2_SNode_2z::m_Clear(){
  this->m__0root=((t_std_collections_Map_1Tt_mx2_SNode_2z_Node*)0);
}

t_std_collections_Map_1Tt_mx2_SNode_2z_Iterator t_std_collections_Map_1Tt_mx2_SNode_2z::m_All(){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1Tt_mx2_SNode_2z_Node* t0{};
    void gcMark(){
      bbGCMarkPtr(t0);
    }
  }f0{};
  return t_std_collections_Map_1Tt_mx2_SNode_2z_Iterator(f0.t0=this->m_FirstNode());
}

bbBool t_std_collections_Map_1Tt_mx2_SNode_2z::m_Add(t_mx2_SNode* l_key,bbBool l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1Tt_mx2_SNode_2z_Node* l_node{};
    t_std_collections_Map_1Tt_mx2_SNode_2z_Node* l_parent{};
    void gcMark(){
      bbGCMarkPtr(l_node);
      bbGCMarkPtr(l_parent);
    }
  }f0{};
  if(!bbBool(this->m__0root)){
    this->m__0root=bbGCNew<t_std_collections_Map_1Tt_mx2_SNode_2z_Node>(l_key,l_value,0,((t_std_collections_Map_1Tt_mx2_SNode_2z_Node*)0));
    return true;
  }
  f0.l_node=this->m__0root;
  bbInt l_cmp{};
  while(bbBool(f0.l_node)){
    f0.l_parent=f0.l_node;
    l_cmp=bbCompare(l_key,f0.l_node->m__0key);
    if((l_cmp>bbInt(0))){
      f0.l_node=f0.l_node->m__0right;
    }else if((l_cmp<bbInt(0))){
      f0.l_node=f0.l_node->m__0left;
    }else{
      return false;
    }
  }
  f0.l_node=bbGCNew<t_std_collections_Map_1Tt_mx2_SNode_2z_Node>(l_key,l_value,0,f0.l_parent);
  if((l_cmp>bbInt(0))){
    f0.l_parent->m__0right=f0.l_node;
  }else{
    f0.l_parent->m__0left=f0.l_node;
  }
  this->m_InsertFixup(f0.l_node);
  return true;
}

void t_std_collections_Map_1sTt_mx2_ClassType_2_Node::gcMark(){
  bbGCMark(m__0value);
  bbGCMark(m__0left);
  bbGCMark(m__0right);
  bbGCMark(m__0parent);
}

t_std_collections_Map_1sTt_mx2_ClassType_2_Node::t_std_collections_Map_1sTt_mx2_ClassType_2_Node(bbString l_key,t_mx2_ClassType* l_value,bbInt l_color,t_std_collections_Map_1sTt_mx2_ClassType_2_Node* l_parent){
  this->m__0key=l_key;
  this->m__0value=l_value;
  this->m__0color=l_color;
  this->m__0parent=l_parent;
}

t_mx2_ClassType* t_std_collections_Map_1sTt_mx2_ClassType_2_Node::m_Value(){
  return this->m__0value;
}

t_std_collections_Map_1sTt_mx2_ClassType_2_Node* t_std_collections_Map_1sTt_mx2_ClassType_2_Node::m_PrevNode(){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1sTt_mx2_ClassType_2_Node* l_node{};
    t_std_collections_Map_1sTt_mx2_ClassType_2_Node* l_parent{};
    void gcMark(){
      bbGCMarkPtr(l_node);
      bbGCMarkPtr(l_parent);
    }
  }f0{};
  if(bbBool(this->m__0left)){
    struct f1_t : public bbGCFrame{
      t_std_collections_Map_1sTt_mx2_ClassType_2_Node* l_node{};
      void gcMark(){
        bbGCMarkPtr(l_node);
      }
    }f1{};
    f1.l_node=this->m__0left;
    while(bbBool(f1.l_node->m__0right)){
      f1.l_node=f1.l_node->m__0right;
    }
    return f1.l_node;
  }
  f0.l_node=this;
  f0.l_parent=this->m__0parent;
  while((bbBool(f0.l_parent)&&(f0.l_node==f0.l_parent->m__0left))){
    f0.l_node=f0.l_parent;
    f0.l_parent=f0.l_parent->m__0parent;
  }
  return f0.l_parent;
}

t_std_collections_Map_1sTt_mx2_ClassType_2_Node* t_std_collections_Map_1sTt_mx2_ClassType_2_Node::m_NextNode(){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1sTt_mx2_ClassType_2_Node* l_node{};
    t_std_collections_Map_1sTt_mx2_ClassType_2_Node* l_parent{};
    void gcMark(){
      bbGCMarkPtr(l_node);
      bbGCMarkPtr(l_parent);
    }
  }f0{};
  if(bbBool(this->m__0right)){
    struct f1_t : public bbGCFrame{
      t_std_collections_Map_1sTt_mx2_ClassType_2_Node* l_node{};
      void gcMark(){
        bbGCMarkPtr(l_node);
      }
    }f1{};
    f1.l_node=this->m__0right;
    while(bbBool(f1.l_node->m__0left)){
      f1.l_node=f1.l_node->m__0left;
    }
    return f1.l_node;
  }
  f0.l_node=this;
  f0.l_parent=this->m__0parent;
  while((bbBool(f0.l_parent)&&(f0.l_node==f0.l_parent->m__0right))){
    f0.l_node=f0.l_parent;
    f0.l_parent=f0.l_parent->m__0parent;
  }
  return f0.l_parent;
}

bbString t_std_collections_Map_1sTt_mx2_ClassType_2_Node::m_Key(){
  return this->m__0key;
}

bbInt t_std_collections_Map_1sTt_mx2_ClassType_2_Node::m_Count(bbInt l_n){
  if(bbBool(this->m__0left)){
    l_n=this->m__0left->m_Count(l_n);
  }
  if(bbBool(this->m__0right)){
    l_n=this->m__0right->m_Count(l_n);
  }
  return (l_n+1);
}

t_std_collections_Map_1sTt_mx2_ClassType_2_Node* t_std_collections_Map_1sTt_mx2_ClassType_2_Node::m_Copy(t_std_collections_Map_1sTt_mx2_ClassType_2_Node* l_parent){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1sTt_mx2_ClassType_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=bbGCNew<t_std_collections_Map_1sTt_mx2_ClassType_2_Node>(this->m__0key,this->m__0value,this->m__0color,l_parent);
  if(bbBool(this->m__0left)){
    f0.l_node->m__0left=this->m__0left->m_Copy(f0.l_node);
  }
  if(bbBool(this->m__0right)){
    f0.l_node->m__0right=this->m__0right->m_Copy(f0.l_node);
  }
  return f0.l_node;
}

t_std_collections_Map_1sTt_mx2_ClassType_2_Iterator::t_std_collections_Map_1sTt_mx2_ClassType_2_Iterator(t_std_collections_Map_1sTt_mx2_ClassType_2_Node* l_node){
  (*this).m__0node=l_node;
}

bbBool t_std_collections_Map_1sTt_mx2_ClassType_2_Iterator::m_Valid(){
  return bbBool((*this).m__0node);
}

t_std_collections_Map_1sTt_mx2_ClassType_2_Node* t_std_collections_Map_1sTt_mx2_ClassType_2_Iterator::m_Current(){
  return (*this).m__0node;
}

void t_std_collections_Map_1sTt_mx2_ClassType_2_Iterator::m_Bump(){
  (*this).m__0node=(*this).m__0node->m_NextNode();
}

int bbCompare(const t_std_collections_Map_1sTt_mx2_ClassType_2_Iterator&x,const t_std_collections_Map_1sTt_mx2_ClassType_2_Iterator&y){
  if(int t=bbCompare(x.m__0node,y.m__0node)) return t;
  return 0;
}

void bbGCMark(const t_std_collections_Map_1sTt_mx2_ClassType_2_Iterator&t){
  bbGCMark(t.m__0node);
}

t_std_collections_Map_1sTt_mx2_ClassType_2_KeyIterator::t_std_collections_Map_1sTt_mx2_ClassType_2_KeyIterator(t_std_collections_Map_1sTt_mx2_ClassType_2_Node* l_node){
  (*this).m__0node=l_node;
}

bbBool t_std_collections_Map_1sTt_mx2_ClassType_2_KeyIterator::m_Valid(){
  return bbBool((*this).m__0node);
}

bbString t_std_collections_Map_1sTt_mx2_ClassType_2_KeyIterator::m_Current(){
  return (*this).m__0node->m__0key;
}

void t_std_collections_Map_1sTt_mx2_ClassType_2_KeyIterator::m_Bump(){
  (*this).m__0node=(*this).m__0node->m_NextNode();
}

int bbCompare(const t_std_collections_Map_1sTt_mx2_ClassType_2_KeyIterator&x,const t_std_collections_Map_1sTt_mx2_ClassType_2_KeyIterator&y){
  if(int t=bbCompare(x.m__0node,y.m__0node)) return t;
  return 0;
}

void bbGCMark(const t_std_collections_Map_1sTt_mx2_ClassType_2_KeyIterator&t){
  bbGCMark(t.m__0node);
}

t_std_collections_Map_1sTt_mx2_ClassType_2_MapKeys::t_std_collections_Map_1sTt_mx2_ClassType_2_MapKeys(t_std_collections_Map_1sTt_mx2_ClassType_2* l_map){
  (*this).m__0map=l_map;
}

t_std_collections_Map_1sTt_mx2_ClassType_2_KeyIterator t_std_collections_Map_1sTt_mx2_ClassType_2_MapKeys::m_All(){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1sTt_mx2_ClassType_2_Node* t0{};
    void gcMark(){
      bbGCMarkPtr(t0);
    }
  }f0{};
  return t_std_collections_Map_1sTt_mx2_ClassType_2_KeyIterator(f0.t0=(*this).m__0map->m_FirstNode());
}

int bbCompare(const t_std_collections_Map_1sTt_mx2_ClassType_2_MapKeys&x,const t_std_collections_Map_1sTt_mx2_ClassType_2_MapKeys&y){
  if(int t=bbCompare(x.m__0map,y.m__0map)) return t;
  return 0;
}

void bbGCMark(const t_std_collections_Map_1sTt_mx2_ClassType_2_MapKeys&t){
  bbGCMark(t.m__0map);
}

t_std_collections_Map_1sTt_mx2_ClassType_2_ValueIterator::t_std_collections_Map_1sTt_mx2_ClassType_2_ValueIterator(t_std_collections_Map_1sTt_mx2_ClassType_2_Node* l_node){
  (*this).m__0node=l_node;
}

bbBool t_std_collections_Map_1sTt_mx2_ClassType_2_ValueIterator::m_Valid(){
  return bbBool((*this).m__0node);
}

t_mx2_ClassType* t_std_collections_Map_1sTt_mx2_ClassType_2_ValueIterator::m_Current(){
  return (*this).m__0node->m__0value;
}

void t_std_collections_Map_1sTt_mx2_ClassType_2_ValueIterator::m_Bump(){
  (*this).m__0node=(*this).m__0node->m_NextNode();
}

int bbCompare(const t_std_collections_Map_1sTt_mx2_ClassType_2_ValueIterator&x,const t_std_collections_Map_1sTt_mx2_ClassType_2_ValueIterator&y){
  if(int t=bbCompare(x.m__0node,y.m__0node)) return t;
  return 0;
}

void bbGCMark(const t_std_collections_Map_1sTt_mx2_ClassType_2_ValueIterator&t){
  bbGCMark(t.m__0node);
}

t_std_collections_Map_1sTt_mx2_ClassType_2_MapValues::t_std_collections_Map_1sTt_mx2_ClassType_2_MapValues(t_std_collections_Map_1sTt_mx2_ClassType_2* l_map){
  (*this).m__0map=l_map;
}

t_std_collections_Map_1sTt_mx2_ClassType_2_ValueIterator t_std_collections_Map_1sTt_mx2_ClassType_2_MapValues::m_All(){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1sTt_mx2_ClassType_2_Node* t0{};
    void gcMark(){
      bbGCMarkPtr(t0);
    }
  }f0{};
  return t_std_collections_Map_1sTt_mx2_ClassType_2_ValueIterator(f0.t0=(*this).m__0map->m_FirstNode());
}

int bbCompare(const t_std_collections_Map_1sTt_mx2_ClassType_2_MapValues&x,const t_std_collections_Map_1sTt_mx2_ClassType_2_MapValues&y){
  if(int t=bbCompare(x.m__0map,y.m__0map)) return t;
  return 0;
}

void bbGCMark(const t_std_collections_Map_1sTt_mx2_ClassType_2_MapValues&t){
  bbGCMark(t.m__0map);
}

void t_std_collections_Map_1sTt_mx2_ClassType_2::gcMark(){
  bbGCMark(m__0root);
}

t_std_collections_Map_1sTt_mx2_ClassType_2::t_std_collections_Map_1sTt_mx2_ClassType_2(t_std_collections_Map_1sTt_mx2_ClassType_2_Node* l_root){
  this->m__0root=l_root;
}

t_std_collections_Map_1sTt_mx2_ClassType_2::t_std_collections_Map_1sTt_mx2_ClassType_2(){
}

void t_std_collections_Map_1sTt_mx2_ClassType_2::m__idxeq(bbString l_key,t_mx2_ClassType* l_value){
  this->m_Set(l_key,l_value);
}

t_mx2_ClassType* t_std_collections_Map_1sTt_mx2_ClassType_2::m__idx(bbString l_key){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1sTt_mx2_ClassType_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m_FindNode(l_key);
  if(!bbBool(f0.l_node)){
    return ((t_mx2_ClassType*)0);
  }
  return f0.l_node->m__0value;
}

t_std_collections_Map_1sTt_mx2_ClassType_2_MapValues t_std_collections_Map_1sTt_mx2_ClassType_2::m_Values(){
  return t_std_collections_Map_1sTt_mx2_ClassType_2_MapValues(this);
}

bbBool t_std_collections_Map_1sTt_mx2_ClassType_2::m_Update(bbString l_key,t_mx2_ClassType* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1sTt_mx2_ClassType_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m_FindNode(l_key);
  if(!bbBool(f0.l_node)){
    return false;
  }
  f0.l_node->m__0value=l_value;
  return true;
}

bbBool t_std_collections_Map_1sTt_mx2_ClassType_2::m_Set(bbString l_key,t_mx2_ClassType* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1sTt_mx2_ClassType_2_Node* l_node{};
    t_std_collections_Map_1sTt_mx2_ClassType_2_Node* l_parent{};
    void gcMark(){
      bbGCMarkPtr(l_node);
      bbGCMarkPtr(l_parent);
    }
  }f0{};
  if(!bbBool(this->m__0root)){
    this->m__0root=bbGCNew<t_std_collections_Map_1sTt_mx2_ClassType_2_Node>(l_key,l_value,0,((t_std_collections_Map_1sTt_mx2_ClassType_2_Node*)0));
    return true;
  }
  f0.l_node=this->m__0root;
  bbInt l_cmp{};
  while(bbBool(f0.l_node)){
    f0.l_parent=f0.l_node;
    l_cmp=bbCompare(l_key,f0.l_node->m__0key);
    if((l_cmp>bbInt(0))){
      f0.l_node=f0.l_node->m__0right;
    }else if((l_cmp<bbInt(0))){
      f0.l_node=f0.l_node->m__0left;
    }else{
      f0.l_node->m__0value=l_value;
      return false;
    }
  }
  f0.l_node=bbGCNew<t_std_collections_Map_1sTt_mx2_ClassType_2_Node>(l_key,l_value,0,f0.l_parent);
  if((l_cmp>bbInt(0))){
    f0.l_parent->m__0right=f0.l_node;
  }else{
    f0.l_parent->m__0left=f0.l_node;
  }
  this->m_InsertFixup(f0.l_node);
  return true;
}

void t_std_collections_Map_1sTt_mx2_ClassType_2::m_RotateRight(t_std_collections_Map_1sTt_mx2_ClassType_2_Node* l_node){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1sTt_mx2_ClassType_2_Node* l_child{};
    void gcMark(){
      bbGCMarkPtr(l_child);
    }
  }f0{};
  f0.l_child=l_node->m__0left;
  l_node->m__0left=f0.l_child->m__0right;
  if(bbBool(f0.l_child->m__0right)){
    f0.l_child->m__0right->m__0parent=l_node;
  }
  f0.l_child->m__0parent=l_node->m__0parent;
  if(bbBool(l_node->m__0parent)){
    if((l_node==l_node->m__0parent->m__0right)){
      l_node->m__0parent->m__0right=f0.l_child;
    }else{
      l_node->m__0parent->m__0left=f0.l_child;
    }
  }else{
    this->m__0root=f0.l_child;
  }
  f0.l_child->m__0right=l_node;
  l_node->m__0parent=f0.l_child;
}

void t_std_collections_Map_1sTt_mx2_ClassType_2::m_RotateLeft(t_std_collections_Map_1sTt_mx2_ClassType_2_Node* l_node){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1sTt_mx2_ClassType_2_Node* l_child{};
    void gcMark(){
      bbGCMarkPtr(l_child);
    }
  }f0{};
  f0.l_child=l_node->m__0right;
  l_node->m__0right=f0.l_child->m__0left;
  if(bbBool(f0.l_child->m__0left)){
    f0.l_child->m__0left->m__0parent=l_node;
  }
  f0.l_child->m__0parent=l_node->m__0parent;
  if(bbBool(l_node->m__0parent)){
    if((l_node==l_node->m__0parent->m__0left)){
      l_node->m__0parent->m__0left=f0.l_child;
    }else{
      l_node->m__0parent->m__0right=f0.l_child;
    }
  }else{
    this->m__0root=f0.l_child;
  }
  f0.l_child->m__0left=l_node;
  l_node->m__0parent=f0.l_child;
}

void t_std_collections_Map_1sTt_mx2_ClassType_2::m_RemoveNode(t_std_collections_Map_1sTt_mx2_ClassType_2_Node* l_node){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1sTt_mx2_ClassType_2_Node* l_child{};
    t_std_collections_Map_1sTt_mx2_ClassType_2_Node* l_parent{};
    t_std_collections_Map_1sTt_mx2_ClassType_2_Node* l_splice{};
    void gcMark(){
      bbGCMarkPtr(l_child);
      bbGCMarkPtr(l_parent);
      bbGCMarkPtr(l_splice);
    }
  }f0{};
  if(!bbBool(l_node->m__0left)){
    f0.l_splice=l_node;
    f0.l_child=l_node->m__0right;
  }else if(!bbBool(l_node->m__0right)){
    f0.l_splice=l_node;
    f0.l_child=l_node->m__0left;
  }else{
    f0.l_splice=l_node->m__0left;
    while(bbBool(f0.l_splice->m__0right)){
      f0.l_splice=f0.l_splice->m__0right;
    }
    f0.l_child=f0.l_splice->m__0left;
    l_node->m__0key=f0.l_splice->m__0key;
    l_node->m__0value=f0.l_splice->m__0value;
  }
  f0.l_parent=f0.l_splice->m__0parent;
  if(bbBool(f0.l_child)){
    f0.l_child->m__0parent=f0.l_parent;
  }
  if(!bbBool(f0.l_parent)){
    this->m__0root=f0.l_child;
    return;
  }
  if((f0.l_splice==f0.l_parent->m__0left)){
    f0.l_parent->m__0left=f0.l_child;
  }else{
    f0.l_parent->m__0right=f0.l_child;
  }
  if((f0.l_splice->m__0color==1)){
    this->m_DeleteFixup(f0.l_child,f0.l_parent);
  }
}

bbBool t_std_collections_Map_1sTt_mx2_ClassType_2::m_Remove(bbString l_key){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1sTt_mx2_ClassType_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m_FindNode(l_key);
  if(!bbBool(f0.l_node)){
    return false;
  }
  this->m_RemoveNode(f0.l_node);
  return true;
}

t_std_collections_Map_1sTt_mx2_ClassType_2_Node* t_std_collections_Map_1sTt_mx2_ClassType_2::m_LastNode(){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1sTt_mx2_ClassType_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  if(!bbBool(this->m__0root)){
    return ((t_std_collections_Map_1sTt_mx2_ClassType_2_Node*)0);
  }
  f0.l_node=this->m__0root;
  while(bbBool(f0.l_node->m__0right)){
    f0.l_node=f0.l_node->m__0right;
  }
  return f0.l_node;
}

t_std_collections_Map_1sTt_mx2_ClassType_2_MapKeys t_std_collections_Map_1sTt_mx2_ClassType_2::m_Keys(){
  return t_std_collections_Map_1sTt_mx2_ClassType_2_MapKeys(this);
}

void t_std_collections_Map_1sTt_mx2_ClassType_2::m_InsertFixup(t_std_collections_Map_1sTt_mx2_ClassType_2_Node* l_node){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1sTt_mx2_ClassType_2_Node* l_node{};
    f0_t(t_std_collections_Map_1sTt_mx2_ClassType_2_Node* l_node):l_node(l_node){
    }
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{l_node};
  while(((bbBool(f0.l_node->m__0parent)&&(f0.l_node->m__0parent->m__0color==0))&&bbBool(f0.l_node->m__0parent->m__0parent))){
    if((f0.l_node->m__0parent==f0.l_node->m__0parent->m__0parent->m__0left)){
      struct f2_t : public bbGCFrame{
        t_std_collections_Map_1sTt_mx2_ClassType_2_Node* l_uncle{};
        void gcMark(){
          bbGCMarkPtr(l_uncle);
        }
      }f2{};
      f2.l_uncle=f0.l_node->m__0parent->m__0parent->m__0right;
      if((bbBool(f2.l_uncle)&&(f2.l_uncle->m__0color==0))){
        f0.l_node->m__0parent->m__0color=1;
        f2.l_uncle->m__0color=1;
        f2.l_uncle->m__0parent->m__0color=0;
        f0.l_node=f2.l_uncle->m__0parent;
      }else{
        if((f0.l_node==f0.l_node->m__0parent->m__0right)){
          f0.l_node=f0.l_node->m__0parent;
          this->m_RotateLeft(f0.l_node);
        }
        f0.l_node->m__0parent->m__0color=1;
        f0.l_node->m__0parent->m__0parent->m__0color=0;
        this->m_RotateRight(f0.l_node->m__0parent->m__0parent);
      }
    }else{
      struct f2_t : public bbGCFrame{
        t_std_collections_Map_1sTt_mx2_ClassType_2_Node* l_uncle{};
        void gcMark(){
          bbGCMarkPtr(l_uncle);
        }
      }f2{};
      f2.l_uncle=f0.l_node->m__0parent->m__0parent->m__0left;
      if((bbBool(f2.l_uncle)&&(f2.l_uncle->m__0color==0))){
        f0.l_node->m__0parent->m__0color=1;
        f2.l_uncle->m__0color=1;
        f2.l_uncle->m__0parent->m__0color=0;
        f0.l_node=f2.l_uncle->m__0parent;
      }else{
        if((f0.l_node==f0.l_node->m__0parent->m__0left)){
          f0.l_node=f0.l_node->m__0parent;
          this->m_RotateRight(f0.l_node);
        }
        f0.l_node->m__0parent->m__0color=1;
        f0.l_node->m__0parent->m__0parent->m__0color=0;
        this->m_RotateLeft(f0.l_node->m__0parent->m__0parent);
      }
    }
  }
  this->m__0root->m__0color=1;
}

t_mx2_ClassType* t_std_collections_Map_1sTt_mx2_ClassType_2::m_Get(bbString l_key){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1sTt_mx2_ClassType_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m_FindNode(l_key);
  if(bbBool(f0.l_node)){
    return f0.l_node->m__0value;
  }
  return ((t_mx2_ClassType*)0);
}

t_std_collections_Map_1sTt_mx2_ClassType_2_Node* t_std_collections_Map_1sTt_mx2_ClassType_2::m_FirstNode(){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1sTt_mx2_ClassType_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  if(!bbBool(this->m__0root)){
    return ((t_std_collections_Map_1sTt_mx2_ClassType_2_Node*)0);
  }
  f0.l_node=this->m__0root;
  while(bbBool(f0.l_node->m__0left)){
    f0.l_node=f0.l_node->m__0left;
  }
  return f0.l_node;
}

t_std_collections_Map_1sTt_mx2_ClassType_2_Node* t_std_collections_Map_1sTt_mx2_ClassType_2::m_FindNode(bbString l_key){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1sTt_mx2_ClassType_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m__0root;
  while(bbBool(f0.l_node)){
    bbInt l_cmp=bbCompare(l_key,f0.l_node->m__0key);
    if((l_cmp>bbInt(0))){
      f0.l_node=f0.l_node->m__0right;
    }else if((l_cmp<bbInt(0))){
      f0.l_node=f0.l_node->m__0left;
    }else{
      return f0.l_node;
    }
  }
  return ((t_std_collections_Map_1sTt_mx2_ClassType_2_Node*)0);
}

bbBool t_std_collections_Map_1sTt_mx2_ClassType_2::m_Empty(){
  return (this->m__0root==((t_std_collections_Map_1sTt_mx2_ClassType_2_Node*)0));
}

void t_std_collections_Map_1sTt_mx2_ClassType_2::m_DeleteFixup(t_std_collections_Map_1sTt_mx2_ClassType_2_Node* l_node,t_std_collections_Map_1sTt_mx2_ClassType_2_Node* l_parent){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1sTt_mx2_ClassType_2_Node* l_node{};
    t_std_collections_Map_1sTt_mx2_ClassType_2_Node* l_parent{};
    f0_t(t_std_collections_Map_1sTt_mx2_ClassType_2_Node* l_node,t_std_collections_Map_1sTt_mx2_ClassType_2_Node* l_parent):l_node(l_node),l_parent(l_parent){
    }
    void gcMark(){
      bbGCMarkPtr(l_node);
      bbGCMarkPtr(l_parent);
    }
  }f0{l_node,l_parent};
  while(((f0.l_node!=this->m__0root)&&(!bbBool(f0.l_node)||(f0.l_node->m__0color==1)))){
    if((f0.l_node==f0.l_parent->m__0left)){
      struct f2_t : public bbGCFrame{
        t_std_collections_Map_1sTt_mx2_ClassType_2_Node* l_sib{};
        void gcMark(){
          bbGCMarkPtr(l_sib);
        }
      }f2{};
      f2.l_sib=f0.l_parent->m__0right;
      if((f2.l_sib->m__0color==0)){
        f2.l_sib->m__0color=1;
        f0.l_parent->m__0color=0;
        this->m_RotateLeft(f0.l_parent);
        f2.l_sib=f0.l_parent->m__0right;
      }
      if(((!bbBool(f2.l_sib->m__0left)||(f2.l_sib->m__0left->m__0color==1))&&(!bbBool(f2.l_sib->m__0right)||(f2.l_sib->m__0right->m__0color==1)))){
        f2.l_sib->m__0color=0;
        f0.l_node=f0.l_parent;
        f0.l_parent=f0.l_parent->m__0parent;
      }else{
        if((!bbBool(f2.l_sib->m__0right)||(f2.l_sib->m__0right->m__0color==1))){
          f2.l_sib->m__0left->m__0color=1;
          f2.l_sib->m__0color=0;
          this->m_RotateRight(f2.l_sib);
          f2.l_sib=f0.l_parent->m__0right;
        }
        f2.l_sib->m__0color=f0.l_parent->m__0color;
        f0.l_parent->m__0color=1;
        f2.l_sib->m__0right->m__0color=1;
        this->m_RotateLeft(f0.l_parent);
        f0.l_node=this->m__0root;
      }
    }else{
      struct f2_t : public bbGCFrame{
        t_std_collections_Map_1sTt_mx2_ClassType_2_Node* l_sib{};
        void gcMark(){
          bbGCMarkPtr(l_sib);
        }
      }f2{};
      f2.l_sib=f0.l_parent->m__0left;
      if((f2.l_sib->m__0color==0)){
        f2.l_sib->m__0color=1;
        f0.l_parent->m__0color=0;
        this->m_RotateRight(f0.l_parent);
        f2.l_sib=f0.l_parent->m__0left;
      }
      if(((!bbBool(f2.l_sib->m__0right)||(f2.l_sib->m__0right->m__0color==1))&&(!bbBool(f2.l_sib->m__0left)||(f2.l_sib->m__0left->m__0color==1)))){
        f2.l_sib->m__0color=0;
        f0.l_node=f0.l_parent;
        f0.l_parent=f0.l_parent->m__0parent;
      }else{
        if((!bbBool(f2.l_sib->m__0left)||(f2.l_sib->m__0left->m__0color==1))){
          f2.l_sib->m__0right->m__0color=1;
          f2.l_sib->m__0color=0;
          this->m_RotateLeft(f2.l_sib);
          f2.l_sib=f0.l_parent->m__0left;
        }
        f2.l_sib->m__0color=f0.l_parent->m__0color;
        f0.l_parent->m__0color=1;
        f2.l_sib->m__0left->m__0color=1;
        this->m_RotateRight(f0.l_parent);
        f0.l_node=this->m__0root;
      }
    }
  }
  if(bbBool(f0.l_node)){
    f0.l_node->m__0color=1;
  }
}

bbInt t_std_collections_Map_1sTt_mx2_ClassType_2::m_Count(){
  if(!bbBool(this->m__0root)){
    return bbInt(0);
  }
  return this->m__0root->m_Count(bbInt(0));
}

t_std_collections_Map_1sTt_mx2_ClassType_2* t_std_collections_Map_1sTt_mx2_ClassType_2::m_Copy(){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1sTt_mx2_ClassType_2_Node* l_root{};
    void gcMark(){
      bbGCMarkPtr(l_root);
    }
  }f0{};
  if(bbBool(this->m__0root)){
    f0.l_root=this->m__0root->m_Copy(((t_std_collections_Map_1sTt_mx2_ClassType_2_Node*)0));
  }
  return bbGCNew<t_std_collections_Map_1sTt_mx2_ClassType_2>(f0.l_root);
}

bbBool t_std_collections_Map_1sTt_mx2_ClassType_2::m_Contains(bbString l_key){
  return (this->m_FindNode(l_key)!=((t_std_collections_Map_1sTt_mx2_ClassType_2_Node*)0));
}

void t_std_collections_Map_1sTt_mx2_ClassType_2::m_Clear(){
  this->m__0root=((t_std_collections_Map_1sTt_mx2_ClassType_2_Node*)0);
}

t_std_collections_Map_1sTt_mx2_ClassType_2_Iterator t_std_collections_Map_1sTt_mx2_ClassType_2::m_All(){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1sTt_mx2_ClassType_2_Node* t0{};
    void gcMark(){
      bbGCMarkPtr(t0);
    }
  }f0{};
  return t_std_collections_Map_1sTt_mx2_ClassType_2_Iterator(f0.t0=this->m_FirstNode());
}

bbBool t_std_collections_Map_1sTt_mx2_ClassType_2::m_Add(bbString l_key,t_mx2_ClassType* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1sTt_mx2_ClassType_2_Node* l_node{};
    t_std_collections_Map_1sTt_mx2_ClassType_2_Node* l_parent{};
    void gcMark(){
      bbGCMarkPtr(l_node);
      bbGCMarkPtr(l_parent);
    }
  }f0{};
  if(!bbBool(this->m__0root)){
    this->m__0root=bbGCNew<t_std_collections_Map_1sTt_mx2_ClassType_2_Node>(l_key,l_value,0,((t_std_collections_Map_1sTt_mx2_ClassType_2_Node*)0));
    return true;
  }
  f0.l_node=this->m__0root;
  bbInt l_cmp{};
  while(bbBool(f0.l_node)){
    f0.l_parent=f0.l_node;
    l_cmp=bbCompare(l_key,f0.l_node->m__0key);
    if((l_cmp>bbInt(0))){
      f0.l_node=f0.l_node->m__0right;
    }else if((l_cmp<bbInt(0))){
      f0.l_node=f0.l_node->m__0left;
    }else{
      return false;
    }
  }
  f0.l_node=bbGCNew<t_std_collections_Map_1sTt_mx2_ClassType_2_Node>(l_key,l_value,0,f0.l_parent);
  if((l_cmp>bbInt(0))){
    f0.l_parent->m__0right=f0.l_node;
  }else{
    f0.l_parent->m__0left=f0.l_node;
  }
  this->m_InsertFixup(f0.l_node);
  return true;
}

void t_std_collections_Map_1sTt_mx2_VarValue_2_Node::gcMark(){
  bbGCMark(m__0value);
  bbGCMark(m__0left);
  bbGCMark(m__0right);
  bbGCMark(m__0parent);
}

t_std_collections_Map_1sTt_mx2_VarValue_2_Node::t_std_collections_Map_1sTt_mx2_VarValue_2_Node(bbString l_key,t_mx2_VarValue* l_value,bbInt l_color,t_std_collections_Map_1sTt_mx2_VarValue_2_Node* l_parent){
  this->m__0key=l_key;
  this->m__0value=l_value;
  this->m__0color=l_color;
  this->m__0parent=l_parent;
}

t_mx2_VarValue* t_std_collections_Map_1sTt_mx2_VarValue_2_Node::m_Value(){
  return this->m__0value;
}

t_std_collections_Map_1sTt_mx2_VarValue_2_Node* t_std_collections_Map_1sTt_mx2_VarValue_2_Node::m_PrevNode(){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1sTt_mx2_VarValue_2_Node* l_node{};
    t_std_collections_Map_1sTt_mx2_VarValue_2_Node* l_parent{};
    void gcMark(){
      bbGCMarkPtr(l_node);
      bbGCMarkPtr(l_parent);
    }
  }f0{};
  if(bbBool(this->m__0left)){
    struct f1_t : public bbGCFrame{
      t_std_collections_Map_1sTt_mx2_VarValue_2_Node* l_node{};
      void gcMark(){
        bbGCMarkPtr(l_node);
      }
    }f1{};
    f1.l_node=this->m__0left;
    while(bbBool(f1.l_node->m__0right)){
      f1.l_node=f1.l_node->m__0right;
    }
    return f1.l_node;
  }
  f0.l_node=this;
  f0.l_parent=this->m__0parent;
  while((bbBool(f0.l_parent)&&(f0.l_node==f0.l_parent->m__0left))){
    f0.l_node=f0.l_parent;
    f0.l_parent=f0.l_parent->m__0parent;
  }
  return f0.l_parent;
}

t_std_collections_Map_1sTt_mx2_VarValue_2_Node* t_std_collections_Map_1sTt_mx2_VarValue_2_Node::m_NextNode(){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1sTt_mx2_VarValue_2_Node* l_node{};
    t_std_collections_Map_1sTt_mx2_VarValue_2_Node* l_parent{};
    void gcMark(){
      bbGCMarkPtr(l_node);
      bbGCMarkPtr(l_parent);
    }
  }f0{};
  if(bbBool(this->m__0right)){
    struct f1_t : public bbGCFrame{
      t_std_collections_Map_1sTt_mx2_VarValue_2_Node* l_node{};
      void gcMark(){
        bbGCMarkPtr(l_node);
      }
    }f1{};
    f1.l_node=this->m__0right;
    while(bbBool(f1.l_node->m__0left)){
      f1.l_node=f1.l_node->m__0left;
    }
    return f1.l_node;
  }
  f0.l_node=this;
  f0.l_parent=this->m__0parent;
  while((bbBool(f0.l_parent)&&(f0.l_node==f0.l_parent->m__0right))){
    f0.l_node=f0.l_parent;
    f0.l_parent=f0.l_parent->m__0parent;
  }
  return f0.l_parent;
}

bbString t_std_collections_Map_1sTt_mx2_VarValue_2_Node::m_Key(){
  return this->m__0key;
}

bbInt t_std_collections_Map_1sTt_mx2_VarValue_2_Node::m_Count(bbInt l_n){
  if(bbBool(this->m__0left)){
    l_n=this->m__0left->m_Count(l_n);
  }
  if(bbBool(this->m__0right)){
    l_n=this->m__0right->m_Count(l_n);
  }
  return (l_n+1);
}

t_std_collections_Map_1sTt_mx2_VarValue_2_Node* t_std_collections_Map_1sTt_mx2_VarValue_2_Node::m_Copy(t_std_collections_Map_1sTt_mx2_VarValue_2_Node* l_parent){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1sTt_mx2_VarValue_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=bbGCNew<t_std_collections_Map_1sTt_mx2_VarValue_2_Node>(this->m__0key,this->m__0value,this->m__0color,l_parent);
  if(bbBool(this->m__0left)){
    f0.l_node->m__0left=this->m__0left->m_Copy(f0.l_node);
  }
  if(bbBool(this->m__0right)){
    f0.l_node->m__0right=this->m__0right->m_Copy(f0.l_node);
  }
  return f0.l_node;
}

t_std_collections_Map_1sTt_mx2_VarValue_2_Iterator::t_std_collections_Map_1sTt_mx2_VarValue_2_Iterator(t_std_collections_Map_1sTt_mx2_VarValue_2_Node* l_node){
  (*this).m__0node=l_node;
}

bbBool t_std_collections_Map_1sTt_mx2_VarValue_2_Iterator::m_Valid(){
  return bbBool((*this).m__0node);
}

t_std_collections_Map_1sTt_mx2_VarValue_2_Node* t_std_collections_Map_1sTt_mx2_VarValue_2_Iterator::m_Current(){
  return (*this).m__0node;
}

void t_std_collections_Map_1sTt_mx2_VarValue_2_Iterator::m_Bump(){
  (*this).m__0node=(*this).m__0node->m_NextNode();
}

int bbCompare(const t_std_collections_Map_1sTt_mx2_VarValue_2_Iterator&x,const t_std_collections_Map_1sTt_mx2_VarValue_2_Iterator&y){
  if(int t=bbCompare(x.m__0node,y.m__0node)) return t;
  return 0;
}

void bbGCMark(const t_std_collections_Map_1sTt_mx2_VarValue_2_Iterator&t){
  bbGCMark(t.m__0node);
}

t_std_collections_Map_1sTt_mx2_VarValue_2_KeyIterator::t_std_collections_Map_1sTt_mx2_VarValue_2_KeyIterator(t_std_collections_Map_1sTt_mx2_VarValue_2_Node* l_node){
  (*this).m__0node=l_node;
}

bbBool t_std_collections_Map_1sTt_mx2_VarValue_2_KeyIterator::m_Valid(){
  return bbBool((*this).m__0node);
}

bbString t_std_collections_Map_1sTt_mx2_VarValue_2_KeyIterator::m_Current(){
  return (*this).m__0node->m__0key;
}

void t_std_collections_Map_1sTt_mx2_VarValue_2_KeyIterator::m_Bump(){
  (*this).m__0node=(*this).m__0node->m_NextNode();
}

int bbCompare(const t_std_collections_Map_1sTt_mx2_VarValue_2_KeyIterator&x,const t_std_collections_Map_1sTt_mx2_VarValue_2_KeyIterator&y){
  if(int t=bbCompare(x.m__0node,y.m__0node)) return t;
  return 0;
}

void bbGCMark(const t_std_collections_Map_1sTt_mx2_VarValue_2_KeyIterator&t){
  bbGCMark(t.m__0node);
}

t_std_collections_Map_1sTt_mx2_VarValue_2_MapKeys::t_std_collections_Map_1sTt_mx2_VarValue_2_MapKeys(t_std_collections_Map_1sTt_mx2_VarValue_2* l_map){
  (*this).m__0map=l_map;
}

t_std_collections_Map_1sTt_mx2_VarValue_2_KeyIterator t_std_collections_Map_1sTt_mx2_VarValue_2_MapKeys::m_All(){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1sTt_mx2_VarValue_2_Node* t0{};
    void gcMark(){
      bbGCMarkPtr(t0);
    }
  }f0{};
  return t_std_collections_Map_1sTt_mx2_VarValue_2_KeyIterator(f0.t0=(*this).m__0map->m_FirstNode());
}

int bbCompare(const t_std_collections_Map_1sTt_mx2_VarValue_2_MapKeys&x,const t_std_collections_Map_1sTt_mx2_VarValue_2_MapKeys&y){
  if(int t=bbCompare(x.m__0map,y.m__0map)) return t;
  return 0;
}

void bbGCMark(const t_std_collections_Map_1sTt_mx2_VarValue_2_MapKeys&t){
  bbGCMark(t.m__0map);
}

t_std_collections_Map_1sTt_mx2_VarValue_2_ValueIterator::t_std_collections_Map_1sTt_mx2_VarValue_2_ValueIterator(t_std_collections_Map_1sTt_mx2_VarValue_2_Node* l_node){
  (*this).m__0node=l_node;
}

bbBool t_std_collections_Map_1sTt_mx2_VarValue_2_ValueIterator::m_Valid(){
  return bbBool((*this).m__0node);
}

t_mx2_VarValue* t_std_collections_Map_1sTt_mx2_VarValue_2_ValueIterator::m_Current(){
  return (*this).m__0node->m__0value;
}

void t_std_collections_Map_1sTt_mx2_VarValue_2_ValueIterator::m_Bump(){
  (*this).m__0node=(*this).m__0node->m_NextNode();
}

int bbCompare(const t_std_collections_Map_1sTt_mx2_VarValue_2_ValueIterator&x,const t_std_collections_Map_1sTt_mx2_VarValue_2_ValueIterator&y){
  if(int t=bbCompare(x.m__0node,y.m__0node)) return t;
  return 0;
}

void bbGCMark(const t_std_collections_Map_1sTt_mx2_VarValue_2_ValueIterator&t){
  bbGCMark(t.m__0node);
}

t_std_collections_Map_1sTt_mx2_VarValue_2_MapValues::t_std_collections_Map_1sTt_mx2_VarValue_2_MapValues(t_std_collections_Map_1sTt_mx2_VarValue_2* l_map){
  (*this).m__0map=l_map;
}

t_std_collections_Map_1sTt_mx2_VarValue_2_ValueIterator t_std_collections_Map_1sTt_mx2_VarValue_2_MapValues::m_All(){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1sTt_mx2_VarValue_2_Node* t0{};
    void gcMark(){
      bbGCMarkPtr(t0);
    }
  }f0{};
  return t_std_collections_Map_1sTt_mx2_VarValue_2_ValueIterator(f0.t0=(*this).m__0map->m_FirstNode());
}

int bbCompare(const t_std_collections_Map_1sTt_mx2_VarValue_2_MapValues&x,const t_std_collections_Map_1sTt_mx2_VarValue_2_MapValues&y){
  if(int t=bbCompare(x.m__0map,y.m__0map)) return t;
  return 0;
}

void bbGCMark(const t_std_collections_Map_1sTt_mx2_VarValue_2_MapValues&t){
  bbGCMark(t.m__0map);
}

void t_std_collections_Map_1sTt_mx2_VarValue_2::gcMark(){
  bbGCMark(m__0root);
}

t_std_collections_Map_1sTt_mx2_VarValue_2::t_std_collections_Map_1sTt_mx2_VarValue_2(t_std_collections_Map_1sTt_mx2_VarValue_2_Node* l_root){
  this->m__0root=l_root;
}

t_std_collections_Map_1sTt_mx2_VarValue_2::t_std_collections_Map_1sTt_mx2_VarValue_2(){
}

void t_std_collections_Map_1sTt_mx2_VarValue_2::m__idxeq(bbString l_key,t_mx2_VarValue* l_value){
  this->m_Set(l_key,l_value);
}

t_mx2_VarValue* t_std_collections_Map_1sTt_mx2_VarValue_2::m__idx(bbString l_key){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1sTt_mx2_VarValue_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m_FindNode(l_key);
  if(!bbBool(f0.l_node)){
    return ((t_mx2_VarValue*)0);
  }
  return f0.l_node->m__0value;
}

t_std_collections_Map_1sTt_mx2_VarValue_2_MapValues t_std_collections_Map_1sTt_mx2_VarValue_2::m_Values(){
  return t_std_collections_Map_1sTt_mx2_VarValue_2_MapValues(this);
}

bbBool t_std_collections_Map_1sTt_mx2_VarValue_2::m_Update(bbString l_key,t_mx2_VarValue* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1sTt_mx2_VarValue_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m_FindNode(l_key);
  if(!bbBool(f0.l_node)){
    return false;
  }
  f0.l_node->m__0value=l_value;
  return true;
}

bbBool t_std_collections_Map_1sTt_mx2_VarValue_2::m_Set(bbString l_key,t_mx2_VarValue* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1sTt_mx2_VarValue_2_Node* l_node{};
    t_std_collections_Map_1sTt_mx2_VarValue_2_Node* l_parent{};
    void gcMark(){
      bbGCMarkPtr(l_node);
      bbGCMarkPtr(l_parent);
    }
  }f0{};
  if(!bbBool(this->m__0root)){
    this->m__0root=bbGCNew<t_std_collections_Map_1sTt_mx2_VarValue_2_Node>(l_key,l_value,0,((t_std_collections_Map_1sTt_mx2_VarValue_2_Node*)0));
    return true;
  }
  f0.l_node=this->m__0root;
  bbInt l_cmp{};
  while(bbBool(f0.l_node)){
    f0.l_parent=f0.l_node;
    l_cmp=bbCompare(l_key,f0.l_node->m__0key);
    if((l_cmp>bbInt(0))){
      f0.l_node=f0.l_node->m__0right;
    }else if((l_cmp<bbInt(0))){
      f0.l_node=f0.l_node->m__0left;
    }else{
      f0.l_node->m__0value=l_value;
      return false;
    }
  }
  f0.l_node=bbGCNew<t_std_collections_Map_1sTt_mx2_VarValue_2_Node>(l_key,l_value,0,f0.l_parent);
  if((l_cmp>bbInt(0))){
    f0.l_parent->m__0right=f0.l_node;
  }else{
    f0.l_parent->m__0left=f0.l_node;
  }
  this->m_InsertFixup(f0.l_node);
  return true;
}

void t_std_collections_Map_1sTt_mx2_VarValue_2::m_RotateRight(t_std_collections_Map_1sTt_mx2_VarValue_2_Node* l_node){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1sTt_mx2_VarValue_2_Node* l_child{};
    void gcMark(){
      bbGCMarkPtr(l_child);
    }
  }f0{};
  f0.l_child=l_node->m__0left;
  l_node->m__0left=f0.l_child->m__0right;
  if(bbBool(f0.l_child->m__0right)){
    f0.l_child->m__0right->m__0parent=l_node;
  }
  f0.l_child->m__0parent=l_node->m__0parent;
  if(bbBool(l_node->m__0parent)){
    if((l_node==l_node->m__0parent->m__0right)){
      l_node->m__0parent->m__0right=f0.l_child;
    }else{
      l_node->m__0parent->m__0left=f0.l_child;
    }
  }else{
    this->m__0root=f0.l_child;
  }
  f0.l_child->m__0right=l_node;
  l_node->m__0parent=f0.l_child;
}

void t_std_collections_Map_1sTt_mx2_VarValue_2::m_RotateLeft(t_std_collections_Map_1sTt_mx2_VarValue_2_Node* l_node){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1sTt_mx2_VarValue_2_Node* l_child{};
    void gcMark(){
      bbGCMarkPtr(l_child);
    }
  }f0{};
  f0.l_child=l_node->m__0right;
  l_node->m__0right=f0.l_child->m__0left;
  if(bbBool(f0.l_child->m__0left)){
    f0.l_child->m__0left->m__0parent=l_node;
  }
  f0.l_child->m__0parent=l_node->m__0parent;
  if(bbBool(l_node->m__0parent)){
    if((l_node==l_node->m__0parent->m__0left)){
      l_node->m__0parent->m__0left=f0.l_child;
    }else{
      l_node->m__0parent->m__0right=f0.l_child;
    }
  }else{
    this->m__0root=f0.l_child;
  }
  f0.l_child->m__0left=l_node;
  l_node->m__0parent=f0.l_child;
}

void t_std_collections_Map_1sTt_mx2_VarValue_2::m_RemoveNode(t_std_collections_Map_1sTt_mx2_VarValue_2_Node* l_node){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1sTt_mx2_VarValue_2_Node* l_child{};
    t_std_collections_Map_1sTt_mx2_VarValue_2_Node* l_parent{};
    t_std_collections_Map_1sTt_mx2_VarValue_2_Node* l_splice{};
    void gcMark(){
      bbGCMarkPtr(l_child);
      bbGCMarkPtr(l_parent);
      bbGCMarkPtr(l_splice);
    }
  }f0{};
  if(!bbBool(l_node->m__0left)){
    f0.l_splice=l_node;
    f0.l_child=l_node->m__0right;
  }else if(!bbBool(l_node->m__0right)){
    f0.l_splice=l_node;
    f0.l_child=l_node->m__0left;
  }else{
    f0.l_splice=l_node->m__0left;
    while(bbBool(f0.l_splice->m__0right)){
      f0.l_splice=f0.l_splice->m__0right;
    }
    f0.l_child=f0.l_splice->m__0left;
    l_node->m__0key=f0.l_splice->m__0key;
    l_node->m__0value=f0.l_splice->m__0value;
  }
  f0.l_parent=f0.l_splice->m__0parent;
  if(bbBool(f0.l_child)){
    f0.l_child->m__0parent=f0.l_parent;
  }
  if(!bbBool(f0.l_parent)){
    this->m__0root=f0.l_child;
    return;
  }
  if((f0.l_splice==f0.l_parent->m__0left)){
    f0.l_parent->m__0left=f0.l_child;
  }else{
    f0.l_parent->m__0right=f0.l_child;
  }
  if((f0.l_splice->m__0color==1)){
    this->m_DeleteFixup(f0.l_child,f0.l_parent);
  }
}

bbBool t_std_collections_Map_1sTt_mx2_VarValue_2::m_Remove(bbString l_key){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1sTt_mx2_VarValue_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m_FindNode(l_key);
  if(!bbBool(f0.l_node)){
    return false;
  }
  this->m_RemoveNode(f0.l_node);
  return true;
}

t_std_collections_Map_1sTt_mx2_VarValue_2_Node* t_std_collections_Map_1sTt_mx2_VarValue_2::m_LastNode(){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1sTt_mx2_VarValue_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  if(!bbBool(this->m__0root)){
    return ((t_std_collections_Map_1sTt_mx2_VarValue_2_Node*)0);
  }
  f0.l_node=this->m__0root;
  while(bbBool(f0.l_node->m__0right)){
    f0.l_node=f0.l_node->m__0right;
  }
  return f0.l_node;
}

t_std_collections_Map_1sTt_mx2_VarValue_2_MapKeys t_std_collections_Map_1sTt_mx2_VarValue_2::m_Keys(){
  return t_std_collections_Map_1sTt_mx2_VarValue_2_MapKeys(this);
}

void t_std_collections_Map_1sTt_mx2_VarValue_2::m_InsertFixup(t_std_collections_Map_1sTt_mx2_VarValue_2_Node* l_node){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1sTt_mx2_VarValue_2_Node* l_node{};
    f0_t(t_std_collections_Map_1sTt_mx2_VarValue_2_Node* l_node):l_node(l_node){
    }
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{l_node};
  while(((bbBool(f0.l_node->m__0parent)&&(f0.l_node->m__0parent->m__0color==0))&&bbBool(f0.l_node->m__0parent->m__0parent))){
    if((f0.l_node->m__0parent==f0.l_node->m__0parent->m__0parent->m__0left)){
      struct f2_t : public bbGCFrame{
        t_std_collections_Map_1sTt_mx2_VarValue_2_Node* l_uncle{};
        void gcMark(){
          bbGCMarkPtr(l_uncle);
        }
      }f2{};
      f2.l_uncle=f0.l_node->m__0parent->m__0parent->m__0right;
      if((bbBool(f2.l_uncle)&&(f2.l_uncle->m__0color==0))){
        f0.l_node->m__0parent->m__0color=1;
        f2.l_uncle->m__0color=1;
        f2.l_uncle->m__0parent->m__0color=0;
        f0.l_node=f2.l_uncle->m__0parent;
      }else{
        if((f0.l_node==f0.l_node->m__0parent->m__0right)){
          f0.l_node=f0.l_node->m__0parent;
          this->m_RotateLeft(f0.l_node);
        }
        f0.l_node->m__0parent->m__0color=1;
        f0.l_node->m__0parent->m__0parent->m__0color=0;
        this->m_RotateRight(f0.l_node->m__0parent->m__0parent);
      }
    }else{
      struct f2_t : public bbGCFrame{
        t_std_collections_Map_1sTt_mx2_VarValue_2_Node* l_uncle{};
        void gcMark(){
          bbGCMarkPtr(l_uncle);
        }
      }f2{};
      f2.l_uncle=f0.l_node->m__0parent->m__0parent->m__0left;
      if((bbBool(f2.l_uncle)&&(f2.l_uncle->m__0color==0))){
        f0.l_node->m__0parent->m__0color=1;
        f2.l_uncle->m__0color=1;
        f2.l_uncle->m__0parent->m__0color=0;
        f0.l_node=f2.l_uncle->m__0parent;
      }else{
        if((f0.l_node==f0.l_node->m__0parent->m__0left)){
          f0.l_node=f0.l_node->m__0parent;
          this->m_RotateRight(f0.l_node);
        }
        f0.l_node->m__0parent->m__0color=1;
        f0.l_node->m__0parent->m__0parent->m__0color=0;
        this->m_RotateLeft(f0.l_node->m__0parent->m__0parent);
      }
    }
  }
  this->m__0root->m__0color=1;
}

t_mx2_VarValue* t_std_collections_Map_1sTt_mx2_VarValue_2::m_Get(bbString l_key){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1sTt_mx2_VarValue_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m_FindNode(l_key);
  if(bbBool(f0.l_node)){
    return f0.l_node->m__0value;
  }
  return ((t_mx2_VarValue*)0);
}

t_std_collections_Map_1sTt_mx2_VarValue_2_Node* t_std_collections_Map_1sTt_mx2_VarValue_2::m_FirstNode(){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1sTt_mx2_VarValue_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  if(!bbBool(this->m__0root)){
    return ((t_std_collections_Map_1sTt_mx2_VarValue_2_Node*)0);
  }
  f0.l_node=this->m__0root;
  while(bbBool(f0.l_node->m__0left)){
    f0.l_node=f0.l_node->m__0left;
  }
  return f0.l_node;
}

t_std_collections_Map_1sTt_mx2_VarValue_2_Node* t_std_collections_Map_1sTt_mx2_VarValue_2::m_FindNode(bbString l_key){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1sTt_mx2_VarValue_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m__0root;
  while(bbBool(f0.l_node)){
    bbInt l_cmp=bbCompare(l_key,f0.l_node->m__0key);
    if((l_cmp>bbInt(0))){
      f0.l_node=f0.l_node->m__0right;
    }else if((l_cmp<bbInt(0))){
      f0.l_node=f0.l_node->m__0left;
    }else{
      return f0.l_node;
    }
  }
  return ((t_std_collections_Map_1sTt_mx2_VarValue_2_Node*)0);
}

bbBool t_std_collections_Map_1sTt_mx2_VarValue_2::m_Empty(){
  return (this->m__0root==((t_std_collections_Map_1sTt_mx2_VarValue_2_Node*)0));
}

void t_std_collections_Map_1sTt_mx2_VarValue_2::m_DeleteFixup(t_std_collections_Map_1sTt_mx2_VarValue_2_Node* l_node,t_std_collections_Map_1sTt_mx2_VarValue_2_Node* l_parent){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1sTt_mx2_VarValue_2_Node* l_node{};
    t_std_collections_Map_1sTt_mx2_VarValue_2_Node* l_parent{};
    f0_t(t_std_collections_Map_1sTt_mx2_VarValue_2_Node* l_node,t_std_collections_Map_1sTt_mx2_VarValue_2_Node* l_parent):l_node(l_node),l_parent(l_parent){
    }
    void gcMark(){
      bbGCMarkPtr(l_node);
      bbGCMarkPtr(l_parent);
    }
  }f0{l_node,l_parent};
  while(((f0.l_node!=this->m__0root)&&(!bbBool(f0.l_node)||(f0.l_node->m__0color==1)))){
    if((f0.l_node==f0.l_parent->m__0left)){
      struct f2_t : public bbGCFrame{
        t_std_collections_Map_1sTt_mx2_VarValue_2_Node* l_sib{};
        void gcMark(){
          bbGCMarkPtr(l_sib);
        }
      }f2{};
      f2.l_sib=f0.l_parent->m__0right;
      if((f2.l_sib->m__0color==0)){
        f2.l_sib->m__0color=1;
        f0.l_parent->m__0color=0;
        this->m_RotateLeft(f0.l_parent);
        f2.l_sib=f0.l_parent->m__0right;
      }
      if(((!bbBool(f2.l_sib->m__0left)||(f2.l_sib->m__0left->m__0color==1))&&(!bbBool(f2.l_sib->m__0right)||(f2.l_sib->m__0right->m__0color==1)))){
        f2.l_sib->m__0color=0;
        f0.l_node=f0.l_parent;
        f0.l_parent=f0.l_parent->m__0parent;
      }else{
        if((!bbBool(f2.l_sib->m__0right)||(f2.l_sib->m__0right->m__0color==1))){
          f2.l_sib->m__0left->m__0color=1;
          f2.l_sib->m__0color=0;
          this->m_RotateRight(f2.l_sib);
          f2.l_sib=f0.l_parent->m__0right;
        }
        f2.l_sib->m__0color=f0.l_parent->m__0color;
        f0.l_parent->m__0color=1;
        f2.l_sib->m__0right->m__0color=1;
        this->m_RotateLeft(f0.l_parent);
        f0.l_node=this->m__0root;
      }
    }else{
      struct f2_t : public bbGCFrame{
        t_std_collections_Map_1sTt_mx2_VarValue_2_Node* l_sib{};
        void gcMark(){
          bbGCMarkPtr(l_sib);
        }
      }f2{};
      f2.l_sib=f0.l_parent->m__0left;
      if((f2.l_sib->m__0color==0)){
        f2.l_sib->m__0color=1;
        f0.l_parent->m__0color=0;
        this->m_RotateRight(f0.l_parent);
        f2.l_sib=f0.l_parent->m__0left;
      }
      if(((!bbBool(f2.l_sib->m__0right)||(f2.l_sib->m__0right->m__0color==1))&&(!bbBool(f2.l_sib->m__0left)||(f2.l_sib->m__0left->m__0color==1)))){
        f2.l_sib->m__0color=0;
        f0.l_node=f0.l_parent;
        f0.l_parent=f0.l_parent->m__0parent;
      }else{
        if((!bbBool(f2.l_sib->m__0left)||(f2.l_sib->m__0left->m__0color==1))){
          f2.l_sib->m__0right->m__0color=1;
          f2.l_sib->m__0color=0;
          this->m_RotateLeft(f2.l_sib);
          f2.l_sib=f0.l_parent->m__0left;
        }
        f2.l_sib->m__0color=f0.l_parent->m__0color;
        f0.l_parent->m__0color=1;
        f2.l_sib->m__0left->m__0color=1;
        this->m_RotateRight(f0.l_parent);
        f0.l_node=this->m__0root;
      }
    }
  }
  if(bbBool(f0.l_node)){
    f0.l_node->m__0color=1;
  }
}

bbInt t_std_collections_Map_1sTt_mx2_VarValue_2::m_Count(){
  if(!bbBool(this->m__0root)){
    return bbInt(0);
  }
  return this->m__0root->m_Count(bbInt(0));
}

t_std_collections_Map_1sTt_mx2_VarValue_2* t_std_collections_Map_1sTt_mx2_VarValue_2::m_Copy(){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1sTt_mx2_VarValue_2_Node* l_root{};
    void gcMark(){
      bbGCMarkPtr(l_root);
    }
  }f0{};
  if(bbBool(this->m__0root)){
    f0.l_root=this->m__0root->m_Copy(((t_std_collections_Map_1sTt_mx2_VarValue_2_Node*)0));
  }
  return bbGCNew<t_std_collections_Map_1sTt_mx2_VarValue_2>(f0.l_root);
}

bbBool t_std_collections_Map_1sTt_mx2_VarValue_2::m_Contains(bbString l_key){
  return (this->m_FindNode(l_key)!=((t_std_collections_Map_1sTt_mx2_VarValue_2_Node*)0));
}

void t_std_collections_Map_1sTt_mx2_VarValue_2::m_Clear(){
  this->m__0root=((t_std_collections_Map_1sTt_mx2_VarValue_2_Node*)0);
}

t_std_collections_Map_1sTt_mx2_VarValue_2_Iterator t_std_collections_Map_1sTt_mx2_VarValue_2::m_All(){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1sTt_mx2_VarValue_2_Node* t0{};
    void gcMark(){
      bbGCMarkPtr(t0);
    }
  }f0{};
  return t_std_collections_Map_1sTt_mx2_VarValue_2_Iterator(f0.t0=this->m_FirstNode());
}

bbBool t_std_collections_Map_1sTt_mx2_VarValue_2::m_Add(bbString l_key,t_mx2_VarValue* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1sTt_mx2_VarValue_2_Node* l_node{};
    t_std_collections_Map_1sTt_mx2_VarValue_2_Node* l_parent{};
    void gcMark(){
      bbGCMarkPtr(l_node);
      bbGCMarkPtr(l_parent);
    }
  }f0{};
  if(!bbBool(this->m__0root)){
    this->m__0root=bbGCNew<t_std_collections_Map_1sTt_mx2_VarValue_2_Node>(l_key,l_value,0,((t_std_collections_Map_1sTt_mx2_VarValue_2_Node*)0));
    return true;
  }
  f0.l_node=this->m__0root;
  bbInt l_cmp{};
  while(bbBool(f0.l_node)){
    f0.l_parent=f0.l_node;
    l_cmp=bbCompare(l_key,f0.l_node->m__0key);
    if((l_cmp>bbInt(0))){
      f0.l_node=f0.l_node->m__0right;
    }else if((l_cmp<bbInt(0))){
      f0.l_node=f0.l_node->m__0left;
    }else{
      return false;
    }
  }
  f0.l_node=bbGCNew<t_std_collections_Map_1sTt_mx2_VarValue_2_Node>(l_key,l_value,0,f0.l_parent);
  if((l_cmp>bbInt(0))){
    f0.l_parent->m__0right=f0.l_node;
  }else{
    f0.l_parent->m__0left=f0.l_node;
  }
  this->m_InsertFixup(f0.l_node);
  return true;
}

void t_std_collections_Map_1sTt_mx2_NamespaceScope_2_Node::gcMark(){
  bbGCMark(m__0value);
  bbGCMark(m__0left);
  bbGCMark(m__0right);
  bbGCMark(m__0parent);
}

t_std_collections_Map_1sTt_mx2_NamespaceScope_2_Node::t_std_collections_Map_1sTt_mx2_NamespaceScope_2_Node(bbString l_key,t_mx2_NamespaceScope* l_value,bbInt l_color,t_std_collections_Map_1sTt_mx2_NamespaceScope_2_Node* l_parent){
  this->m__0key=l_key;
  this->m__0value=l_value;
  this->m__0color=l_color;
  this->m__0parent=l_parent;
}

t_mx2_NamespaceScope* t_std_collections_Map_1sTt_mx2_NamespaceScope_2_Node::m_Value(){
  return this->m__0value;
}

t_std_collections_Map_1sTt_mx2_NamespaceScope_2_Node* t_std_collections_Map_1sTt_mx2_NamespaceScope_2_Node::m_PrevNode(){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1sTt_mx2_NamespaceScope_2_Node* l_node{};
    t_std_collections_Map_1sTt_mx2_NamespaceScope_2_Node* l_parent{};
    void gcMark(){
      bbGCMarkPtr(l_node);
      bbGCMarkPtr(l_parent);
    }
  }f0{};
  if(bbBool(this->m__0left)){
    struct f1_t : public bbGCFrame{
      t_std_collections_Map_1sTt_mx2_NamespaceScope_2_Node* l_node{};
      void gcMark(){
        bbGCMarkPtr(l_node);
      }
    }f1{};
    f1.l_node=this->m__0left;
    while(bbBool(f1.l_node->m__0right)){
      f1.l_node=f1.l_node->m__0right;
    }
    return f1.l_node;
  }
  f0.l_node=this;
  f0.l_parent=this->m__0parent;
  while((bbBool(f0.l_parent)&&(f0.l_node==f0.l_parent->m__0left))){
    f0.l_node=f0.l_parent;
    f0.l_parent=f0.l_parent->m__0parent;
  }
  return f0.l_parent;
}

t_std_collections_Map_1sTt_mx2_NamespaceScope_2_Node* t_std_collections_Map_1sTt_mx2_NamespaceScope_2_Node::m_NextNode(){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1sTt_mx2_NamespaceScope_2_Node* l_node{};
    t_std_collections_Map_1sTt_mx2_NamespaceScope_2_Node* l_parent{};
    void gcMark(){
      bbGCMarkPtr(l_node);
      bbGCMarkPtr(l_parent);
    }
  }f0{};
  if(bbBool(this->m__0right)){
    struct f1_t : public bbGCFrame{
      t_std_collections_Map_1sTt_mx2_NamespaceScope_2_Node* l_node{};
      void gcMark(){
        bbGCMarkPtr(l_node);
      }
    }f1{};
    f1.l_node=this->m__0right;
    while(bbBool(f1.l_node->m__0left)){
      f1.l_node=f1.l_node->m__0left;
    }
    return f1.l_node;
  }
  f0.l_node=this;
  f0.l_parent=this->m__0parent;
  while((bbBool(f0.l_parent)&&(f0.l_node==f0.l_parent->m__0right))){
    f0.l_node=f0.l_parent;
    f0.l_parent=f0.l_parent->m__0parent;
  }
  return f0.l_parent;
}

bbString t_std_collections_Map_1sTt_mx2_NamespaceScope_2_Node::m_Key(){
  return this->m__0key;
}

bbInt t_std_collections_Map_1sTt_mx2_NamespaceScope_2_Node::m_Count(bbInt l_n){
  if(bbBool(this->m__0left)){
    l_n=this->m__0left->m_Count(l_n);
  }
  if(bbBool(this->m__0right)){
    l_n=this->m__0right->m_Count(l_n);
  }
  return (l_n+1);
}

t_std_collections_Map_1sTt_mx2_NamespaceScope_2_Node* t_std_collections_Map_1sTt_mx2_NamespaceScope_2_Node::m_Copy(t_std_collections_Map_1sTt_mx2_NamespaceScope_2_Node* l_parent){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1sTt_mx2_NamespaceScope_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=bbGCNew<t_std_collections_Map_1sTt_mx2_NamespaceScope_2_Node>(this->m__0key,this->m__0value,this->m__0color,l_parent);
  if(bbBool(this->m__0left)){
    f0.l_node->m__0left=this->m__0left->m_Copy(f0.l_node);
  }
  if(bbBool(this->m__0right)){
    f0.l_node->m__0right=this->m__0right->m_Copy(f0.l_node);
  }
  return f0.l_node;
}

t_std_collections_Map_1sTt_mx2_NamespaceScope_2_Iterator::t_std_collections_Map_1sTt_mx2_NamespaceScope_2_Iterator(t_std_collections_Map_1sTt_mx2_NamespaceScope_2_Node* l_node){
  (*this).m__0node=l_node;
}

bbBool t_std_collections_Map_1sTt_mx2_NamespaceScope_2_Iterator::m_Valid(){
  return bbBool((*this).m__0node);
}

t_std_collections_Map_1sTt_mx2_NamespaceScope_2_Node* t_std_collections_Map_1sTt_mx2_NamespaceScope_2_Iterator::m_Current(){
  return (*this).m__0node;
}

void t_std_collections_Map_1sTt_mx2_NamespaceScope_2_Iterator::m_Bump(){
  (*this).m__0node=(*this).m__0node->m_NextNode();
}

int bbCompare(const t_std_collections_Map_1sTt_mx2_NamespaceScope_2_Iterator&x,const t_std_collections_Map_1sTt_mx2_NamespaceScope_2_Iterator&y){
  if(int t=bbCompare(x.m__0node,y.m__0node)) return t;
  return 0;
}

void bbGCMark(const t_std_collections_Map_1sTt_mx2_NamespaceScope_2_Iterator&t){
  bbGCMark(t.m__0node);
}

t_std_collections_Map_1sTt_mx2_NamespaceScope_2_KeyIterator::t_std_collections_Map_1sTt_mx2_NamespaceScope_2_KeyIterator(t_std_collections_Map_1sTt_mx2_NamespaceScope_2_Node* l_node){
  (*this).m__0node=l_node;
}

bbBool t_std_collections_Map_1sTt_mx2_NamespaceScope_2_KeyIterator::m_Valid(){
  return bbBool((*this).m__0node);
}

bbString t_std_collections_Map_1sTt_mx2_NamespaceScope_2_KeyIterator::m_Current(){
  return (*this).m__0node->m__0key;
}

void t_std_collections_Map_1sTt_mx2_NamespaceScope_2_KeyIterator::m_Bump(){
  (*this).m__0node=(*this).m__0node->m_NextNode();
}

int bbCompare(const t_std_collections_Map_1sTt_mx2_NamespaceScope_2_KeyIterator&x,const t_std_collections_Map_1sTt_mx2_NamespaceScope_2_KeyIterator&y){
  if(int t=bbCompare(x.m__0node,y.m__0node)) return t;
  return 0;
}

void bbGCMark(const t_std_collections_Map_1sTt_mx2_NamespaceScope_2_KeyIterator&t){
  bbGCMark(t.m__0node);
}

t_std_collections_Map_1sTt_mx2_NamespaceScope_2_MapKeys::t_std_collections_Map_1sTt_mx2_NamespaceScope_2_MapKeys(t_std_collections_Map_1sTt_mx2_NamespaceScope_2* l_map){
  (*this).m__0map=l_map;
}

t_std_collections_Map_1sTt_mx2_NamespaceScope_2_KeyIterator t_std_collections_Map_1sTt_mx2_NamespaceScope_2_MapKeys::m_All(){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1sTt_mx2_NamespaceScope_2_Node* t0{};
    void gcMark(){
      bbGCMarkPtr(t0);
    }
  }f0{};
  return t_std_collections_Map_1sTt_mx2_NamespaceScope_2_KeyIterator(f0.t0=(*this).m__0map->m_FirstNode());
}

int bbCompare(const t_std_collections_Map_1sTt_mx2_NamespaceScope_2_MapKeys&x,const t_std_collections_Map_1sTt_mx2_NamespaceScope_2_MapKeys&y){
  if(int t=bbCompare(x.m__0map,y.m__0map)) return t;
  return 0;
}

void bbGCMark(const t_std_collections_Map_1sTt_mx2_NamespaceScope_2_MapKeys&t){
  bbGCMark(t.m__0map);
}

t_std_collections_Map_1sTt_mx2_NamespaceScope_2_ValueIterator::t_std_collections_Map_1sTt_mx2_NamespaceScope_2_ValueIterator(t_std_collections_Map_1sTt_mx2_NamespaceScope_2_Node* l_node){
  (*this).m__0node=l_node;
}

bbBool t_std_collections_Map_1sTt_mx2_NamespaceScope_2_ValueIterator::m_Valid(){
  return bbBool((*this).m__0node);
}

t_mx2_NamespaceScope* t_std_collections_Map_1sTt_mx2_NamespaceScope_2_ValueIterator::m_Current(){
  return (*this).m__0node->m__0value;
}

void t_std_collections_Map_1sTt_mx2_NamespaceScope_2_ValueIterator::m_Bump(){
  (*this).m__0node=(*this).m__0node->m_NextNode();
}

int bbCompare(const t_std_collections_Map_1sTt_mx2_NamespaceScope_2_ValueIterator&x,const t_std_collections_Map_1sTt_mx2_NamespaceScope_2_ValueIterator&y){
  if(int t=bbCompare(x.m__0node,y.m__0node)) return t;
  return 0;
}

void bbGCMark(const t_std_collections_Map_1sTt_mx2_NamespaceScope_2_ValueIterator&t){
  bbGCMark(t.m__0node);
}

t_std_collections_Map_1sTt_mx2_NamespaceScope_2_MapValues::t_std_collections_Map_1sTt_mx2_NamespaceScope_2_MapValues(t_std_collections_Map_1sTt_mx2_NamespaceScope_2* l_map){
  (*this).m__0map=l_map;
}

t_std_collections_Map_1sTt_mx2_NamespaceScope_2_ValueIterator t_std_collections_Map_1sTt_mx2_NamespaceScope_2_MapValues::m_All(){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1sTt_mx2_NamespaceScope_2_Node* t0{};
    void gcMark(){
      bbGCMarkPtr(t0);
    }
  }f0{};
  return t_std_collections_Map_1sTt_mx2_NamespaceScope_2_ValueIterator(f0.t0=(*this).m__0map->m_FirstNode());
}

int bbCompare(const t_std_collections_Map_1sTt_mx2_NamespaceScope_2_MapValues&x,const t_std_collections_Map_1sTt_mx2_NamespaceScope_2_MapValues&y){
  if(int t=bbCompare(x.m__0map,y.m__0map)) return t;
  return 0;
}

void bbGCMark(const t_std_collections_Map_1sTt_mx2_NamespaceScope_2_MapValues&t){
  bbGCMark(t.m__0map);
}

void t_std_collections_Map_1sTt_mx2_NamespaceScope_2::gcMark(){
  bbGCMark(m__0root);
}

t_std_collections_Map_1sTt_mx2_NamespaceScope_2::t_std_collections_Map_1sTt_mx2_NamespaceScope_2(t_std_collections_Map_1sTt_mx2_NamespaceScope_2_Node* l_root){
  this->m__0root=l_root;
}

t_std_collections_Map_1sTt_mx2_NamespaceScope_2::t_std_collections_Map_1sTt_mx2_NamespaceScope_2(){
}

void t_std_collections_Map_1sTt_mx2_NamespaceScope_2::m__idxeq(bbString l_key,t_mx2_NamespaceScope* l_value){
  this->m_Set(l_key,l_value);
}

t_mx2_NamespaceScope* t_std_collections_Map_1sTt_mx2_NamespaceScope_2::m__idx(bbString l_key){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1sTt_mx2_NamespaceScope_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m_FindNode(l_key);
  if(!bbBool(f0.l_node)){
    return ((t_mx2_NamespaceScope*)0);
  }
  return f0.l_node->m__0value;
}

t_std_collections_Map_1sTt_mx2_NamespaceScope_2_MapValues t_std_collections_Map_1sTt_mx2_NamespaceScope_2::m_Values(){
  return t_std_collections_Map_1sTt_mx2_NamespaceScope_2_MapValues(this);
}

bbBool t_std_collections_Map_1sTt_mx2_NamespaceScope_2::m_Update(bbString l_key,t_mx2_NamespaceScope* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1sTt_mx2_NamespaceScope_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m_FindNode(l_key);
  if(!bbBool(f0.l_node)){
    return false;
  }
  f0.l_node->m__0value=l_value;
  return true;
}

bbBool t_std_collections_Map_1sTt_mx2_NamespaceScope_2::m_Set(bbString l_key,t_mx2_NamespaceScope* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1sTt_mx2_NamespaceScope_2_Node* l_node{};
    t_std_collections_Map_1sTt_mx2_NamespaceScope_2_Node* l_parent{};
    void gcMark(){
      bbGCMarkPtr(l_node);
      bbGCMarkPtr(l_parent);
    }
  }f0{};
  if(!bbBool(this->m__0root)){
    this->m__0root=bbGCNew<t_std_collections_Map_1sTt_mx2_NamespaceScope_2_Node>(l_key,l_value,0,((t_std_collections_Map_1sTt_mx2_NamespaceScope_2_Node*)0));
    return true;
  }
  f0.l_node=this->m__0root;
  bbInt l_cmp{};
  while(bbBool(f0.l_node)){
    f0.l_parent=f0.l_node;
    l_cmp=bbCompare(l_key,f0.l_node->m__0key);
    if((l_cmp>bbInt(0))){
      f0.l_node=f0.l_node->m__0right;
    }else if((l_cmp<bbInt(0))){
      f0.l_node=f0.l_node->m__0left;
    }else{
      f0.l_node->m__0value=l_value;
      return false;
    }
  }
  f0.l_node=bbGCNew<t_std_collections_Map_1sTt_mx2_NamespaceScope_2_Node>(l_key,l_value,0,f0.l_parent);
  if((l_cmp>bbInt(0))){
    f0.l_parent->m__0right=f0.l_node;
  }else{
    f0.l_parent->m__0left=f0.l_node;
  }
  this->m_InsertFixup(f0.l_node);
  return true;
}

void t_std_collections_Map_1sTt_mx2_NamespaceScope_2::m_RotateRight(t_std_collections_Map_1sTt_mx2_NamespaceScope_2_Node* l_node){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1sTt_mx2_NamespaceScope_2_Node* l_child{};
    void gcMark(){
      bbGCMarkPtr(l_child);
    }
  }f0{};
  f0.l_child=l_node->m__0left;
  l_node->m__0left=f0.l_child->m__0right;
  if(bbBool(f0.l_child->m__0right)){
    f0.l_child->m__0right->m__0parent=l_node;
  }
  f0.l_child->m__0parent=l_node->m__0parent;
  if(bbBool(l_node->m__0parent)){
    if((l_node==l_node->m__0parent->m__0right)){
      l_node->m__0parent->m__0right=f0.l_child;
    }else{
      l_node->m__0parent->m__0left=f0.l_child;
    }
  }else{
    this->m__0root=f0.l_child;
  }
  f0.l_child->m__0right=l_node;
  l_node->m__0parent=f0.l_child;
}

void t_std_collections_Map_1sTt_mx2_NamespaceScope_2::m_RotateLeft(t_std_collections_Map_1sTt_mx2_NamespaceScope_2_Node* l_node){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1sTt_mx2_NamespaceScope_2_Node* l_child{};
    void gcMark(){
      bbGCMarkPtr(l_child);
    }
  }f0{};
  f0.l_child=l_node->m__0right;
  l_node->m__0right=f0.l_child->m__0left;
  if(bbBool(f0.l_child->m__0left)){
    f0.l_child->m__0left->m__0parent=l_node;
  }
  f0.l_child->m__0parent=l_node->m__0parent;
  if(bbBool(l_node->m__0parent)){
    if((l_node==l_node->m__0parent->m__0left)){
      l_node->m__0parent->m__0left=f0.l_child;
    }else{
      l_node->m__0parent->m__0right=f0.l_child;
    }
  }else{
    this->m__0root=f0.l_child;
  }
  f0.l_child->m__0left=l_node;
  l_node->m__0parent=f0.l_child;
}

void t_std_collections_Map_1sTt_mx2_NamespaceScope_2::m_RemoveNode(t_std_collections_Map_1sTt_mx2_NamespaceScope_2_Node* l_node){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1sTt_mx2_NamespaceScope_2_Node* l_child{};
    t_std_collections_Map_1sTt_mx2_NamespaceScope_2_Node* l_parent{};
    t_std_collections_Map_1sTt_mx2_NamespaceScope_2_Node* l_splice{};
    void gcMark(){
      bbGCMarkPtr(l_child);
      bbGCMarkPtr(l_parent);
      bbGCMarkPtr(l_splice);
    }
  }f0{};
  if(!bbBool(l_node->m__0left)){
    f0.l_splice=l_node;
    f0.l_child=l_node->m__0right;
  }else if(!bbBool(l_node->m__0right)){
    f0.l_splice=l_node;
    f0.l_child=l_node->m__0left;
  }else{
    f0.l_splice=l_node->m__0left;
    while(bbBool(f0.l_splice->m__0right)){
      f0.l_splice=f0.l_splice->m__0right;
    }
    f0.l_child=f0.l_splice->m__0left;
    l_node->m__0key=f0.l_splice->m__0key;
    l_node->m__0value=f0.l_splice->m__0value;
  }
  f0.l_parent=f0.l_splice->m__0parent;
  if(bbBool(f0.l_child)){
    f0.l_child->m__0parent=f0.l_parent;
  }
  if(!bbBool(f0.l_parent)){
    this->m__0root=f0.l_child;
    return;
  }
  if((f0.l_splice==f0.l_parent->m__0left)){
    f0.l_parent->m__0left=f0.l_child;
  }else{
    f0.l_parent->m__0right=f0.l_child;
  }
  if((f0.l_splice->m__0color==1)){
    this->m_DeleteFixup(f0.l_child,f0.l_parent);
  }
}

bbBool t_std_collections_Map_1sTt_mx2_NamespaceScope_2::m_Remove(bbString l_key){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1sTt_mx2_NamespaceScope_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m_FindNode(l_key);
  if(!bbBool(f0.l_node)){
    return false;
  }
  this->m_RemoveNode(f0.l_node);
  return true;
}

t_std_collections_Map_1sTt_mx2_NamespaceScope_2_Node* t_std_collections_Map_1sTt_mx2_NamespaceScope_2::m_LastNode(){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1sTt_mx2_NamespaceScope_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  if(!bbBool(this->m__0root)){
    return ((t_std_collections_Map_1sTt_mx2_NamespaceScope_2_Node*)0);
  }
  f0.l_node=this->m__0root;
  while(bbBool(f0.l_node->m__0right)){
    f0.l_node=f0.l_node->m__0right;
  }
  return f0.l_node;
}

t_std_collections_Map_1sTt_mx2_NamespaceScope_2_MapKeys t_std_collections_Map_1sTt_mx2_NamespaceScope_2::m_Keys(){
  return t_std_collections_Map_1sTt_mx2_NamespaceScope_2_MapKeys(this);
}

void t_std_collections_Map_1sTt_mx2_NamespaceScope_2::m_InsertFixup(t_std_collections_Map_1sTt_mx2_NamespaceScope_2_Node* l_node){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1sTt_mx2_NamespaceScope_2_Node* l_node{};
    f0_t(t_std_collections_Map_1sTt_mx2_NamespaceScope_2_Node* l_node):l_node(l_node){
    }
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{l_node};
  while(((bbBool(f0.l_node->m__0parent)&&(f0.l_node->m__0parent->m__0color==0))&&bbBool(f0.l_node->m__0parent->m__0parent))){
    if((f0.l_node->m__0parent==f0.l_node->m__0parent->m__0parent->m__0left)){
      struct f2_t : public bbGCFrame{
        t_std_collections_Map_1sTt_mx2_NamespaceScope_2_Node* l_uncle{};
        void gcMark(){
          bbGCMarkPtr(l_uncle);
        }
      }f2{};
      f2.l_uncle=f0.l_node->m__0parent->m__0parent->m__0right;
      if((bbBool(f2.l_uncle)&&(f2.l_uncle->m__0color==0))){
        f0.l_node->m__0parent->m__0color=1;
        f2.l_uncle->m__0color=1;
        f2.l_uncle->m__0parent->m__0color=0;
        f0.l_node=f2.l_uncle->m__0parent;
      }else{
        if((f0.l_node==f0.l_node->m__0parent->m__0right)){
          f0.l_node=f0.l_node->m__0parent;
          this->m_RotateLeft(f0.l_node);
        }
        f0.l_node->m__0parent->m__0color=1;
        f0.l_node->m__0parent->m__0parent->m__0color=0;
        this->m_RotateRight(f0.l_node->m__0parent->m__0parent);
      }
    }else{
      struct f2_t : public bbGCFrame{
        t_std_collections_Map_1sTt_mx2_NamespaceScope_2_Node* l_uncle{};
        void gcMark(){
          bbGCMarkPtr(l_uncle);
        }
      }f2{};
      f2.l_uncle=f0.l_node->m__0parent->m__0parent->m__0left;
      if((bbBool(f2.l_uncle)&&(f2.l_uncle->m__0color==0))){
        f0.l_node->m__0parent->m__0color=1;
        f2.l_uncle->m__0color=1;
        f2.l_uncle->m__0parent->m__0color=0;
        f0.l_node=f2.l_uncle->m__0parent;
      }else{
        if((f0.l_node==f0.l_node->m__0parent->m__0left)){
          f0.l_node=f0.l_node->m__0parent;
          this->m_RotateRight(f0.l_node);
        }
        f0.l_node->m__0parent->m__0color=1;
        f0.l_node->m__0parent->m__0parent->m__0color=0;
        this->m_RotateLeft(f0.l_node->m__0parent->m__0parent);
      }
    }
  }
  this->m__0root->m__0color=1;
}

t_mx2_NamespaceScope* t_std_collections_Map_1sTt_mx2_NamespaceScope_2::m_Get(bbString l_key){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1sTt_mx2_NamespaceScope_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m_FindNode(l_key);
  if(bbBool(f0.l_node)){
    return f0.l_node->m__0value;
  }
  return ((t_mx2_NamespaceScope*)0);
}

t_std_collections_Map_1sTt_mx2_NamespaceScope_2_Node* t_std_collections_Map_1sTt_mx2_NamespaceScope_2::m_FirstNode(){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1sTt_mx2_NamespaceScope_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  if(!bbBool(this->m__0root)){
    return ((t_std_collections_Map_1sTt_mx2_NamespaceScope_2_Node*)0);
  }
  f0.l_node=this->m__0root;
  while(bbBool(f0.l_node->m__0left)){
    f0.l_node=f0.l_node->m__0left;
  }
  return f0.l_node;
}

t_std_collections_Map_1sTt_mx2_NamespaceScope_2_Node* t_std_collections_Map_1sTt_mx2_NamespaceScope_2::m_FindNode(bbString l_key){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1sTt_mx2_NamespaceScope_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m__0root;
  while(bbBool(f0.l_node)){
    bbInt l_cmp=bbCompare(l_key,f0.l_node->m__0key);
    if((l_cmp>bbInt(0))){
      f0.l_node=f0.l_node->m__0right;
    }else if((l_cmp<bbInt(0))){
      f0.l_node=f0.l_node->m__0left;
    }else{
      return f0.l_node;
    }
  }
  return ((t_std_collections_Map_1sTt_mx2_NamespaceScope_2_Node*)0);
}

bbBool t_std_collections_Map_1sTt_mx2_NamespaceScope_2::m_Empty(){
  return (this->m__0root==((t_std_collections_Map_1sTt_mx2_NamespaceScope_2_Node*)0));
}

void t_std_collections_Map_1sTt_mx2_NamespaceScope_2::m_DeleteFixup(t_std_collections_Map_1sTt_mx2_NamespaceScope_2_Node* l_node,t_std_collections_Map_1sTt_mx2_NamespaceScope_2_Node* l_parent){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1sTt_mx2_NamespaceScope_2_Node* l_node{};
    t_std_collections_Map_1sTt_mx2_NamespaceScope_2_Node* l_parent{};
    f0_t(t_std_collections_Map_1sTt_mx2_NamespaceScope_2_Node* l_node,t_std_collections_Map_1sTt_mx2_NamespaceScope_2_Node* l_parent):l_node(l_node),l_parent(l_parent){
    }
    void gcMark(){
      bbGCMarkPtr(l_node);
      bbGCMarkPtr(l_parent);
    }
  }f0{l_node,l_parent};
  while(((f0.l_node!=this->m__0root)&&(!bbBool(f0.l_node)||(f0.l_node->m__0color==1)))){
    if((f0.l_node==f0.l_parent->m__0left)){
      struct f2_t : public bbGCFrame{
        t_std_collections_Map_1sTt_mx2_NamespaceScope_2_Node* l_sib{};
        void gcMark(){
          bbGCMarkPtr(l_sib);
        }
      }f2{};
      f2.l_sib=f0.l_parent->m__0right;
      if((f2.l_sib->m__0color==0)){
        f2.l_sib->m__0color=1;
        f0.l_parent->m__0color=0;
        this->m_RotateLeft(f0.l_parent);
        f2.l_sib=f0.l_parent->m__0right;
      }
      if(((!bbBool(f2.l_sib->m__0left)||(f2.l_sib->m__0left->m__0color==1))&&(!bbBool(f2.l_sib->m__0right)||(f2.l_sib->m__0right->m__0color==1)))){
        f2.l_sib->m__0color=0;
        f0.l_node=f0.l_parent;
        f0.l_parent=f0.l_parent->m__0parent;
      }else{
        if((!bbBool(f2.l_sib->m__0right)||(f2.l_sib->m__0right->m__0color==1))){
          f2.l_sib->m__0left->m__0color=1;
          f2.l_sib->m__0color=0;
          this->m_RotateRight(f2.l_sib);
          f2.l_sib=f0.l_parent->m__0right;
        }
        f2.l_sib->m__0color=f0.l_parent->m__0color;
        f0.l_parent->m__0color=1;
        f2.l_sib->m__0right->m__0color=1;
        this->m_RotateLeft(f0.l_parent);
        f0.l_node=this->m__0root;
      }
    }else{
      struct f2_t : public bbGCFrame{
        t_std_collections_Map_1sTt_mx2_NamespaceScope_2_Node* l_sib{};
        void gcMark(){
          bbGCMarkPtr(l_sib);
        }
      }f2{};
      f2.l_sib=f0.l_parent->m__0left;
      if((f2.l_sib->m__0color==0)){
        f2.l_sib->m__0color=1;
        f0.l_parent->m__0color=0;
        this->m_RotateRight(f0.l_parent);
        f2.l_sib=f0.l_parent->m__0left;
      }
      if(((!bbBool(f2.l_sib->m__0right)||(f2.l_sib->m__0right->m__0color==1))&&(!bbBool(f2.l_sib->m__0left)||(f2.l_sib->m__0left->m__0color==1)))){
        f2.l_sib->m__0color=0;
        f0.l_node=f0.l_parent;
        f0.l_parent=f0.l_parent->m__0parent;
      }else{
        if((!bbBool(f2.l_sib->m__0left)||(f2.l_sib->m__0left->m__0color==1))){
          f2.l_sib->m__0right->m__0color=1;
          f2.l_sib->m__0color=0;
          this->m_RotateLeft(f2.l_sib);
          f2.l_sib=f0.l_parent->m__0left;
        }
        f2.l_sib->m__0color=f0.l_parent->m__0color;
        f0.l_parent->m__0color=1;
        f2.l_sib->m__0left->m__0color=1;
        this->m_RotateRight(f0.l_parent);
        f0.l_node=this->m__0root;
      }
    }
  }
  if(bbBool(f0.l_node)){
    f0.l_node->m__0color=1;
  }
}

bbInt t_std_collections_Map_1sTt_mx2_NamespaceScope_2::m_Count(){
  if(!bbBool(this->m__0root)){
    return bbInt(0);
  }
  return this->m__0root->m_Count(bbInt(0));
}

t_std_collections_Map_1sTt_mx2_NamespaceScope_2* t_std_collections_Map_1sTt_mx2_NamespaceScope_2::m_Copy(){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1sTt_mx2_NamespaceScope_2_Node* l_root{};
    void gcMark(){
      bbGCMarkPtr(l_root);
    }
  }f0{};
  if(bbBool(this->m__0root)){
    f0.l_root=this->m__0root->m_Copy(((t_std_collections_Map_1sTt_mx2_NamespaceScope_2_Node*)0));
  }
  return bbGCNew<t_std_collections_Map_1sTt_mx2_NamespaceScope_2>(f0.l_root);
}

bbBool t_std_collections_Map_1sTt_mx2_NamespaceScope_2::m_Contains(bbString l_key){
  return (this->m_FindNode(l_key)!=((t_std_collections_Map_1sTt_mx2_NamespaceScope_2_Node*)0));
}

void t_std_collections_Map_1sTt_mx2_NamespaceScope_2::m_Clear(){
  this->m__0root=((t_std_collections_Map_1sTt_mx2_NamespaceScope_2_Node*)0);
}

t_std_collections_Map_1sTt_mx2_NamespaceScope_2_Iterator t_std_collections_Map_1sTt_mx2_NamespaceScope_2::m_All(){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1sTt_mx2_NamespaceScope_2_Node* t0{};
    void gcMark(){
      bbGCMarkPtr(t0);
    }
  }f0{};
  return t_std_collections_Map_1sTt_mx2_NamespaceScope_2_Iterator(f0.t0=this->m_FirstNode());
}

bbBool t_std_collections_Map_1sTt_mx2_NamespaceScope_2::m_Add(bbString l_key,t_mx2_NamespaceScope* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1sTt_mx2_NamespaceScope_2_Node* l_node{};
    t_std_collections_Map_1sTt_mx2_NamespaceScope_2_Node* l_parent{};
    void gcMark(){
      bbGCMarkPtr(l_node);
      bbGCMarkPtr(l_parent);
    }
  }f0{};
  if(!bbBool(this->m__0root)){
    this->m__0root=bbGCNew<t_std_collections_Map_1sTt_mx2_NamespaceScope_2_Node>(l_key,l_value,0,((t_std_collections_Map_1sTt_mx2_NamespaceScope_2_Node*)0));
    return true;
  }
  f0.l_node=this->m__0root;
  bbInt l_cmp{};
  while(bbBool(f0.l_node)){
    f0.l_parent=f0.l_node;
    l_cmp=bbCompare(l_key,f0.l_node->m__0key);
    if((l_cmp>bbInt(0))){
      f0.l_node=f0.l_node->m__0right;
    }else if((l_cmp<bbInt(0))){
      f0.l_node=f0.l_node->m__0left;
    }else{
      return false;
    }
  }
  f0.l_node=bbGCNew<t_std_collections_Map_1sTt_mx2_NamespaceScope_2_Node>(l_key,l_value,0,f0.l_parent);
  if((l_cmp>bbInt(0))){
    f0.l_parent->m__0right=f0.l_node;
  }else{
    f0.l_parent->m__0left=f0.l_node;
  }
  this->m_InsertFixup(f0.l_node);
  return true;
}

void mx2_mx2cc_std_collections_2map_init(){
  static bool done;
  if(done) return;
  done=true;
}

bbInit mx2_mx2cc_std_collections_2map_init_v("mx2cc_std_collections_2map",&mx2_mx2cc_std_collections_2map_init);
