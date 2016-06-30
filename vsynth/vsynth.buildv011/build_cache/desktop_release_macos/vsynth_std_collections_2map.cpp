
#include "vsynth_std_collections_2map.h"

// ***** External *****

// ***** Internal *****

void t_std_collections_Map_1TbbInt_2i_Node::gcMark(){
  bbGCMark(m__0left);
  bbGCMark(m__0right);
  bbGCMark(m__0parent);
}

t_std_collections_Map_1TbbInt_2i_Node::t_std_collections_Map_1TbbInt_2i_Node(bbInt l_key,bbInt l_value,bbInt l_color,t_std_collections_Map_1TbbInt_2i_Node* l_parent){
  this->m__0key=l_key;
  this->m__0value=l_value;
  this->m__0color=l_color;
  this->m__0parent=l_parent;
}

bbInt t_std_collections_Map_1TbbInt_2i_Node::m_Value(){
  return this->m__0value;
}

t_std_collections_Map_1TbbInt_2i_Node* t_std_collections_Map_1TbbInt_2i_Node::m_PrevNode(){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1TbbInt_2i_Node* l_node{};
    t_std_collections_Map_1TbbInt_2i_Node* l_parent{};
    void gcMark(){
      bbGCMarkPtr(l_node);
      bbGCMarkPtr(l_parent);
    }
  }f0{};
  if(bbBool(this->m__0left)){
    struct f1_t : public bbGCFrame{
      t_std_collections_Map_1TbbInt_2i_Node* l_node{};
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

t_std_collections_Map_1TbbInt_2i_Node* t_std_collections_Map_1TbbInt_2i_Node::m_NextNode(){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1TbbInt_2i_Node* l_node{};
    t_std_collections_Map_1TbbInt_2i_Node* l_parent{};
    void gcMark(){
      bbGCMarkPtr(l_node);
      bbGCMarkPtr(l_parent);
    }
  }f0{};
  if(bbBool(this->m__0right)){
    struct f1_t : public bbGCFrame{
      t_std_collections_Map_1TbbInt_2i_Node* l_node{};
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

bbInt t_std_collections_Map_1TbbInt_2i_Node::m_Key(){
  return this->m__0key;
}

bbInt t_std_collections_Map_1TbbInt_2i_Node::m_Count(bbInt l_n){
  if(bbBool(this->m__0left)){
    l_n=this->m__0left->m_Count(l_n);
  }
  if(bbBool(this->m__0right)){
    l_n=this->m__0right->m_Count(l_n);
  }
  return (l_n+1);
}

t_std_collections_Map_1TbbInt_2i_Node* t_std_collections_Map_1TbbInt_2i_Node::m_Copy(t_std_collections_Map_1TbbInt_2i_Node* l_parent){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1TbbInt_2i_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=bbGCNew<t_std_collections_Map_1TbbInt_2i_Node>(this->m__0key,this->m__0value,this->m__0color,l_parent);
  if(bbBool(this->m__0left)){
    f0.l_node->m__0left=this->m__0left->m_Copy(f0.l_node);
  }
  if(bbBool(this->m__0right)){
    f0.l_node->m__0right=this->m__0right->m_Copy(f0.l_node);
  }
  return f0.l_node;
}

t_std_collections_Map_1TbbInt_2i_Iterator::t_std_collections_Map_1TbbInt_2i_Iterator(t_std_collections_Map_1TbbInt_2i_Node* l_node){
  (*this).m__0node=l_node;
}

bbBool t_std_collections_Map_1TbbInt_2i_Iterator::m_Valid(){
  return bbBool((*this).m__0node);
}

t_std_collections_Map_1TbbInt_2i_Node* t_std_collections_Map_1TbbInt_2i_Iterator::m_Current(){
  return (*this).m__0node;
}

void t_std_collections_Map_1TbbInt_2i_Iterator::m_Bump(){
  (*this).m__0node=(*this).m__0node->m_NextNode();
}

int bbCompare(const t_std_collections_Map_1TbbInt_2i_Iterator&x,const t_std_collections_Map_1TbbInt_2i_Iterator&y){
  if(int t=bbCompare(x.m__0node,y.m__0node)) return t;
  return 0;
}

void bbGCMark(const t_std_collections_Map_1TbbInt_2i_Iterator&t){
  bbGCMark(t.m__0node);
}

t_std_collections_Map_1TbbInt_2i_KeyIterator::t_std_collections_Map_1TbbInt_2i_KeyIterator(t_std_collections_Map_1TbbInt_2i_Node* l_node){
  (*this).m__0node=l_node;
}

bbBool t_std_collections_Map_1TbbInt_2i_KeyIterator::m_Valid(){
  return bbBool((*this).m__0node);
}

bbInt t_std_collections_Map_1TbbInt_2i_KeyIterator::m_Current(){
  return (*this).m__0node->m__0key;
}

void t_std_collections_Map_1TbbInt_2i_KeyIterator::m_Bump(){
  (*this).m__0node=(*this).m__0node->m_NextNode();
}

int bbCompare(const t_std_collections_Map_1TbbInt_2i_KeyIterator&x,const t_std_collections_Map_1TbbInt_2i_KeyIterator&y){
  if(int t=bbCompare(x.m__0node,y.m__0node)) return t;
  return 0;
}

void bbGCMark(const t_std_collections_Map_1TbbInt_2i_KeyIterator&t){
  bbGCMark(t.m__0node);
}

t_std_collections_Map_1TbbInt_2i_MapKeys::t_std_collections_Map_1TbbInt_2i_MapKeys(t_std_collections_Map_1TbbInt_2i* l_map){
  (*this).m__0map=l_map;
}

t_std_collections_Map_1TbbInt_2i_KeyIterator t_std_collections_Map_1TbbInt_2i_MapKeys::m_All(){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1TbbInt_2i_Node* t0{};
    void gcMark(){
      bbGCMarkPtr(t0);
    }
  }f0{};
  return t_std_collections_Map_1TbbInt_2i_KeyIterator(f0.t0=(*this).m__0map->m_FirstNode());
}

int bbCompare(const t_std_collections_Map_1TbbInt_2i_MapKeys&x,const t_std_collections_Map_1TbbInt_2i_MapKeys&y){
  if(int t=bbCompare(x.m__0map,y.m__0map)) return t;
  return 0;
}

void bbGCMark(const t_std_collections_Map_1TbbInt_2i_MapKeys&t){
  bbGCMark(t.m__0map);
}

t_std_collections_Map_1TbbInt_2i_ValueIterator::t_std_collections_Map_1TbbInt_2i_ValueIterator(t_std_collections_Map_1TbbInt_2i_Node* l_node){
  (*this).m__0node=l_node;
}

bbBool t_std_collections_Map_1TbbInt_2i_ValueIterator::m_Valid(){
  return bbBool((*this).m__0node);
}

bbInt t_std_collections_Map_1TbbInt_2i_ValueIterator::m_Current(){
  return (*this).m__0node->m__0value;
}

void t_std_collections_Map_1TbbInt_2i_ValueIterator::m_Bump(){
  (*this).m__0node=(*this).m__0node->m_NextNode();
}

int bbCompare(const t_std_collections_Map_1TbbInt_2i_ValueIterator&x,const t_std_collections_Map_1TbbInt_2i_ValueIterator&y){
  if(int t=bbCompare(x.m__0node,y.m__0node)) return t;
  return 0;
}

void bbGCMark(const t_std_collections_Map_1TbbInt_2i_ValueIterator&t){
  bbGCMark(t.m__0node);
}

t_std_collections_Map_1TbbInt_2i_MapValues::t_std_collections_Map_1TbbInt_2i_MapValues(t_std_collections_Map_1TbbInt_2i* l_map){
  (*this).m__0map=l_map;
}

t_std_collections_Map_1TbbInt_2i_ValueIterator t_std_collections_Map_1TbbInt_2i_MapValues::m_All(){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1TbbInt_2i_Node* t0{};
    void gcMark(){
      bbGCMarkPtr(t0);
    }
  }f0{};
  return t_std_collections_Map_1TbbInt_2i_ValueIterator(f0.t0=(*this).m__0map->m_FirstNode());
}

int bbCompare(const t_std_collections_Map_1TbbInt_2i_MapValues&x,const t_std_collections_Map_1TbbInt_2i_MapValues&y){
  if(int t=bbCompare(x.m__0map,y.m__0map)) return t;
  return 0;
}

void bbGCMark(const t_std_collections_Map_1TbbInt_2i_MapValues&t){
  bbGCMark(t.m__0map);
}

void t_std_collections_Map_1TbbInt_2i::gcMark(){
  bbGCMark(m__0root);
}

t_std_collections_Map_1TbbInt_2i::t_std_collections_Map_1TbbInt_2i(t_std_collections_Map_1TbbInt_2i_Node* l_root){
  this->m__0root=l_root;
}

t_std_collections_Map_1TbbInt_2i::t_std_collections_Map_1TbbInt_2i(){
}

void t_std_collections_Map_1TbbInt_2i::m__idxeq(bbInt l_key,bbInt l_value){
  this->m_Set(l_key,l_value);
}

bbInt t_std_collections_Map_1TbbInt_2i::m__idx(bbInt l_key){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1TbbInt_2i_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m_FindNode(l_key);
  if(!bbBool(f0.l_node)){
    return 0;
  }
  return f0.l_node->m__0value;
}

t_std_collections_Map_1TbbInt_2i_MapValues t_std_collections_Map_1TbbInt_2i::m_Values(){
  return t_std_collections_Map_1TbbInt_2i_MapValues(this);
}

bbBool t_std_collections_Map_1TbbInt_2i::m_Update(bbInt l_key,bbInt l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1TbbInt_2i_Node* l_node{};
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

bbBool t_std_collections_Map_1TbbInt_2i::m_Set(bbInt l_key,bbInt l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1TbbInt_2i_Node* l_node{};
    t_std_collections_Map_1TbbInt_2i_Node* l_parent{};
    void gcMark(){
      bbGCMarkPtr(l_node);
      bbGCMarkPtr(l_parent);
    }
  }f0{};
  if(!bbBool(this->m__0root)){
    this->m__0root=bbGCNew<t_std_collections_Map_1TbbInt_2i_Node>(l_key,l_value,0,((t_std_collections_Map_1TbbInt_2i_Node*)0));
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
  f0.l_node=bbGCNew<t_std_collections_Map_1TbbInt_2i_Node>(l_key,l_value,0,f0.l_parent);
  if((l_cmp>bbInt(0))){
    f0.l_parent->m__0right=f0.l_node;
  }else{
    f0.l_parent->m__0left=f0.l_node;
  }
  this->m_InsertFixup(f0.l_node);
  return true;
}

void t_std_collections_Map_1TbbInt_2i::m_RotateRight(t_std_collections_Map_1TbbInt_2i_Node* l_node){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1TbbInt_2i_Node* l_child{};
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

void t_std_collections_Map_1TbbInt_2i::m_RotateLeft(t_std_collections_Map_1TbbInt_2i_Node* l_node){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1TbbInt_2i_Node* l_child{};
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

void t_std_collections_Map_1TbbInt_2i::m_RemoveNode(t_std_collections_Map_1TbbInt_2i_Node* l_node){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1TbbInt_2i_Node* l_child{};
    t_std_collections_Map_1TbbInt_2i_Node* l_parent{};
    t_std_collections_Map_1TbbInt_2i_Node* l_splice{};
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

bbBool t_std_collections_Map_1TbbInt_2i::m_Remove(bbInt l_key){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1TbbInt_2i_Node* l_node{};
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

t_std_collections_Map_1TbbInt_2i_Node* t_std_collections_Map_1TbbInt_2i::m_LastNode(){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1TbbInt_2i_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  if(!bbBool(this->m__0root)){
    return ((t_std_collections_Map_1TbbInt_2i_Node*)0);
  }
  f0.l_node=this->m__0root;
  while(bbBool(f0.l_node->m__0right)){
    f0.l_node=f0.l_node->m__0right;
  }
  return f0.l_node;
}

t_std_collections_Map_1TbbInt_2i_MapKeys t_std_collections_Map_1TbbInt_2i::m_Keys(){
  return t_std_collections_Map_1TbbInt_2i_MapKeys(this);
}

void t_std_collections_Map_1TbbInt_2i::m_InsertFixup(t_std_collections_Map_1TbbInt_2i_Node* l_node){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1TbbInt_2i_Node* l_node{};
    f0_t(t_std_collections_Map_1TbbInt_2i_Node* l_node):l_node(l_node){
    }
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{l_node};
  while(((bbBool(f0.l_node->m__0parent)&&(f0.l_node->m__0parent->m__0color==0))&&bbBool(f0.l_node->m__0parent->m__0parent))){
    if((f0.l_node->m__0parent==f0.l_node->m__0parent->m__0parent->m__0left)){
      struct f2_t : public bbGCFrame{
        t_std_collections_Map_1TbbInt_2i_Node* l_uncle{};
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
        t_std_collections_Map_1TbbInt_2i_Node* l_uncle{};
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

bbInt t_std_collections_Map_1TbbInt_2i::m_Get(bbInt l_key){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1TbbInt_2i_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m_FindNode(l_key);
  if(bbBool(f0.l_node)){
    return f0.l_node->m__0value;
  }
  return 0;
}

t_std_collections_Map_1TbbInt_2i_Node* t_std_collections_Map_1TbbInt_2i::m_FirstNode(){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1TbbInt_2i_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  if(!bbBool(this->m__0root)){
    return ((t_std_collections_Map_1TbbInt_2i_Node*)0);
  }
  f0.l_node=this->m__0root;
  while(bbBool(f0.l_node->m__0left)){
    f0.l_node=f0.l_node->m__0left;
  }
  return f0.l_node;
}

t_std_collections_Map_1TbbInt_2i_Node* t_std_collections_Map_1TbbInt_2i::m_FindNode(bbInt l_key){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1TbbInt_2i_Node* l_node{};
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
  return ((t_std_collections_Map_1TbbInt_2i_Node*)0);
}

bbBool t_std_collections_Map_1TbbInt_2i::m_Empty(){
  return (this->m__0root==((t_std_collections_Map_1TbbInt_2i_Node*)0));
}

void t_std_collections_Map_1TbbInt_2i::m_DeleteFixup(t_std_collections_Map_1TbbInt_2i_Node* l_node,t_std_collections_Map_1TbbInt_2i_Node* l_parent){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1TbbInt_2i_Node* l_node{};
    t_std_collections_Map_1TbbInt_2i_Node* l_parent{};
    f0_t(t_std_collections_Map_1TbbInt_2i_Node* l_node,t_std_collections_Map_1TbbInt_2i_Node* l_parent):l_node(l_node),l_parent(l_parent){
    }
    void gcMark(){
      bbGCMarkPtr(l_node);
      bbGCMarkPtr(l_parent);
    }
  }f0{l_node,l_parent};
  while(((f0.l_node!=this->m__0root)&&(!bbBool(f0.l_node)||(f0.l_node->m__0color==1)))){
    if((f0.l_node==f0.l_parent->m__0left)){
      struct f2_t : public bbGCFrame{
        t_std_collections_Map_1TbbInt_2i_Node* l_sib{};
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
        t_std_collections_Map_1TbbInt_2i_Node* l_sib{};
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

bbInt t_std_collections_Map_1TbbInt_2i::m_Count(){
  if(!bbBool(this->m__0root)){
    return bbInt(0);
  }
  return this->m__0root->m_Count(bbInt(0));
}

t_std_collections_Map_1TbbInt_2i* t_std_collections_Map_1TbbInt_2i::m_Copy(){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1TbbInt_2i_Node* l_root{};
    void gcMark(){
      bbGCMarkPtr(l_root);
    }
  }f0{};
  if(bbBool(this->m__0root)){
    f0.l_root=this->m__0root->m_Copy(((t_std_collections_Map_1TbbInt_2i_Node*)0));
  }
  return bbGCNew<t_std_collections_Map_1TbbInt_2i>(f0.l_root);
}

bbBool t_std_collections_Map_1TbbInt_2i::m_Contains(bbInt l_key){
  return (this->m_FindNode(l_key)!=((t_std_collections_Map_1TbbInt_2i_Node*)0));
}

void t_std_collections_Map_1TbbInt_2i::m_Clear(){
  this->m__0root=((t_std_collections_Map_1TbbInt_2i_Node*)0);
}

t_std_collections_Map_1TbbInt_2i_Iterator t_std_collections_Map_1TbbInt_2i::m_All(){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1TbbInt_2i_Node* t0{};
    void gcMark(){
      bbGCMarkPtr(t0);
    }
  }f0{};
  return t_std_collections_Map_1TbbInt_2i_Iterator(f0.t0=this->m_FirstNode());
}

bbBool t_std_collections_Map_1TbbInt_2i::m_Add(bbInt l_key,bbInt l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1TbbInt_2i_Node* l_node{};
    t_std_collections_Map_1TbbInt_2i_Node* l_parent{};
    void gcMark(){
      bbGCMarkPtr(l_node);
      bbGCMarkPtr(l_parent);
    }
  }f0{};
  if(!bbBool(this->m__0root)){
    this->m__0root=bbGCNew<t_std_collections_Map_1TbbInt_2i_Node>(l_key,l_value,0,((t_std_collections_Map_1TbbInt_2i_Node*)0));
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
  f0.l_node=bbGCNew<t_std_collections_Map_1TbbInt_2i_Node>(l_key,l_value,0,f0.l_parent);
  if((l_cmp>bbInt(0))){
    f0.l_parent->m__0right=f0.l_node;
  }else{
    f0.l_parent->m__0left=f0.l_node;
  }
  this->m_InsertFixup(f0.l_node);
  return true;
}

void mx2_vsynth_std_collections_2map_init(){
  static bool done;
  if(done) return;
  done=true;
}

bbInit mx2_vsynth_std_collections_2map_init_v("vsynth_std_collections_2map",&mx2_vsynth_std_collections_2map_init);
