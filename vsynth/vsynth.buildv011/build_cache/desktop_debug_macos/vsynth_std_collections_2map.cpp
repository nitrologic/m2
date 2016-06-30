
#include "vsynth_std_collections_2map.h"

// ***** External *****

#include "vsynth_vsynth.h"

// ***** Internal *****

void t_std_collections_Map_1iTt_default_Voice_2_Node::gcMark(){
  bbGCMark(m__0value);
  bbGCMark(m__0left);
  bbGCMark(m__0right);
  bbGCMark(m__0parent);
}

void t_std_collections_Map_1iTt_default_Voice_2_Node::dbEmit(){
  bbDBEmit("_key",&m__0key);
  bbDBEmit("_value",&m__0value);
  bbDBEmit("_color",&m__0color);
  bbDBEmit("_left",&m__0left);
  bbDBEmit("_right",&m__0right);
  bbDBEmit("_parent",&m__0parent);
}

t_std_collections_Map_1iTt_default_Voice_2_Node::t_std_collections_Map_1iTt_default_Voice_2_Node(bbInt l_key,t_default_Voice* l_value,bbInt l_color,t_std_collections_Map_1iTt_default_Voice_2_Node* l_parent){
  bbDBFrame db_f{"new:Void(key:Int,value:default.Voice,color:std.collections.Map<Int,default.Voice>.Node.Color,parent:std.collections.Map<Int,default.Voice>.Node)","/Users/simon/monkey2/modules/std/collections/map.monkey2"};
  bbDBLocal("key",&l_key);
  bbDBLocal("value",&l_value);
  bbDBLocal("color",&l_color);
  bbDBLocal("parent",&l_parent);
  bbDBStmt(270339);
  this->m__0key=l_key;
  bbDBStmt(274435);
  this->m__0value=l_value;
  bbDBStmt(278531);
  this->m__0color=l_color;
  bbDBStmt(282627);
  this->m__0parent=l_parent;
}

t_default_Voice* t_std_collections_Map_1iTt_default_Voice_2_Node::m_Value(){
  bbDBFrame db_f{"Value:default.Voice()","/Users/simon/monkey2/modules/std/collections/map.monkey2"};
  t_std_collections_Map_1iTt_default_Voice_2_Node*self=this;
  bbDBLocal("Self",&self);
  bbDBStmt(196611);
  return this->m__0value;
}

t_std_collections_Map_1iTt_default_Voice_2_Node* t_std_collections_Map_1iTt_default_Voice_2_Node::m_PrevNode(){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1iTt_default_Voice_2_Node* l_node{};
    t_std_collections_Map_1iTt_default_Voice_2_Node* l_parent{};
    void gcMark(){
      bbGCMarkPtr(l_node);
      bbGCMarkPtr(l_parent);
    }
  }f0{};
  bbDBFrame db_f{"PrevNode:std.collections.Map<Int,default.Voice>.Node()","/Users/simon/monkey2/modules/std/collections/map.monkey2"};
  t_std_collections_Map_1iTt_default_Voice_2_Node*self=this;
  bbDBLocal("Self",&self);
  bbDBStmt(389123);
  if(bbBool(this->m__0left)){
    struct f1_t : public bbGCFrame{
      t_std_collections_Map_1iTt_default_Voice_2_Node* l_node{};
      void gcMark(){
        bbGCMarkPtr(l_node);
      }
    }f1{};
    bbDBBlock db_blk;
    bbDBStmt(393226);
    f1.l_node=this->m__0left;
    bbDBLocal("node",&f1.l_node);
    bbDBStmt(397316);
    {
      bbDBLoop db_loop;
      while(bbBool(f1.l_node->m__0right)){
        bbDBBlock db_blk;
        bbDBStmt(401413);
        f1.l_node=f1.l_node->m__0right;
      }
    }
    bbDBStmt(409604);
    return f1.l_node;
  }
  bbDBStmt(417801);
  f0.l_node=this;
  bbDBLocal("node",&f0.l_node);
  bbDBStmt(417812);
  f0.l_parent=this->m__0parent;
  bbDBLocal("parent",&f0.l_parent);
  bbDBStmt(421891);
  {
    bbDBLoop db_loop;
    while((bbBool(f0.l_parent)&&(f0.l_node==f0.l_parent->m__0left))){
      bbDBBlock db_blk;
      bbDBStmt(425988);
      f0.l_node=f0.l_parent;
      bbDBStmt(430084);
      f0.l_parent=f0.l_parent->m__0parent;
    }
  }
  bbDBStmt(438275);
  return f0.l_parent;
}

t_std_collections_Map_1iTt_default_Voice_2_Node* t_std_collections_Map_1iTt_default_Voice_2_Node::m_NextNode(){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1iTt_default_Voice_2_Node* l_node{};
    t_std_collections_Map_1iTt_default_Voice_2_Node* l_parent{};
    void gcMark(){
      bbGCMarkPtr(l_node);
      bbGCMarkPtr(l_parent);
    }
  }f0{};
  bbDBFrame db_f{"NextNode:std.collections.Map<Int,default.Voice>.Node()","/Users/simon/monkey2/modules/std/collections/map.monkey2"};
  t_std_collections_Map_1iTt_default_Voice_2_Node*self=this;
  bbDBLocal("Self",&self);
  bbDBStmt(323587);
  if(bbBool(this->m__0right)){
    struct f1_t : public bbGCFrame{
      t_std_collections_Map_1iTt_default_Voice_2_Node* l_node{};
      void gcMark(){
        bbGCMarkPtr(l_node);
      }
    }f1{};
    bbDBBlock db_blk;
    bbDBStmt(327690);
    f1.l_node=this->m__0right;
    bbDBLocal("node",&f1.l_node);
    bbDBStmt(331780);
    {
      bbDBLoop db_loop;
      while(bbBool(f1.l_node->m__0left)){
        bbDBBlock db_blk;
        bbDBStmt(335877);
        f1.l_node=f1.l_node->m__0left;
      }
    }
    bbDBStmt(344068);
    return f1.l_node;
  }
  bbDBStmt(352265);
  f0.l_node=this;
  bbDBLocal("node",&f0.l_node);
  bbDBStmt(352276);
  f0.l_parent=this->m__0parent;
  bbDBLocal("parent",&f0.l_parent);
  bbDBStmt(356355);
  {
    bbDBLoop db_loop;
    while((bbBool(f0.l_parent)&&(f0.l_node==f0.l_parent->m__0right))){
      bbDBBlock db_blk;
      bbDBStmt(360452);
      f0.l_node=f0.l_parent;
      bbDBStmt(364548);
      f0.l_parent=f0.l_parent->m__0parent;
    }
  }
  bbDBStmt(372739);
  return f0.l_parent;
}

bbInt t_std_collections_Map_1iTt_default_Voice_2_Node::m_Key(){
  bbDBFrame db_f{"Key:Int()","/Users/simon/monkey2/modules/std/collections/map.monkey2"};
  t_std_collections_Map_1iTt_default_Voice_2_Node*self=this;
  bbDBLocal("Self",&self);
  bbDBStmt(159747);
  return this->m__0key;
}

bbInt t_std_collections_Map_1iTt_default_Voice_2_Node::m_Count(bbInt l_n){
  bbDBFrame db_f{"Count:Int(n:Int)","/Users/simon/monkey2/modules/std/collections/map.monkey2"};
  t_std_collections_Map_1iTt_default_Voice_2_Node*self=this;
  bbDBLocal("Self",&self);
  bbDBLocal("n",&l_n);
  bbDBStmt(299011);
  if(bbBool(this->m__0left)){
    bbDBBlock db_blk;
    bbDBStmt(299020);
    l_n=this->m__0left->m_Count(l_n);
  }
  bbDBStmt(303107);
  if(bbBool(this->m__0right)){
    bbDBBlock db_blk;
    bbDBStmt(303117);
    l_n=this->m__0right->m_Count(l_n);
  }
  bbDBStmt(307203);
  return (l_n+1);
}

t_std_collections_Map_1iTt_default_Voice_2_Node* t_std_collections_Map_1iTt_default_Voice_2_Node::m_Copy(t_std_collections_Map_1iTt_default_Voice_2_Node* l_parent){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1iTt_default_Voice_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  bbDBFrame db_f{"Copy:std.collections.Map<Int,default.Voice>.Node(parent:std.collections.Map<Int,default.Voice>.Node)","/Users/simon/monkey2/modules/std/collections/map.monkey2"};
  t_std_collections_Map_1iTt_default_Voice_2_Node*self=this;
  bbDBLocal("Self",&self);
  bbDBLocal("parent",&l_parent);
  bbDBStmt(454665);
  f0.l_node=bbGCNew<t_std_collections_Map_1iTt_default_Voice_2_Node>(this->m__0key,this->m__0value,this->m__0color,l_parent);
  bbDBLocal("node",&f0.l_node);
  bbDBStmt(458755);
  if(bbBool(this->m__0left)){
    bbDBBlock db_blk;
    bbDBStmt(458764);
    f0.l_node->m__0left=this->m__0left->m_Copy(f0.l_node);
  }
  bbDBStmt(462851);
  if(bbBool(this->m__0right)){
    bbDBBlock db_blk;
    bbDBStmt(462861);
    f0.l_node->m__0right=this->m__0right->m_Copy(f0.l_node);
  }
  bbDBStmt(466947);
  return f0.l_node;
}
bbString bbDBType(t_std_collections_Map_1iTt_default_Voice_2_Node**){
  return "std.collections.Map<Int,default.Voice>.Node";
}
bbString bbDBValue(t_std_collections_Map_1iTt_default_Voice_2_Node**p){
  return bbDBObjectValue(*p);
}

void t_std_collections_Map_1iTt_default_Voice_2_Iterator::dbEmit(t_std_collections_Map_1iTt_default_Voice_2_Iterator*p){
  bbDBEmit("_node",&p->m__0node);
}

t_std_collections_Map_1iTt_default_Voice_2_Iterator::t_std_collections_Map_1iTt_default_Voice_2_Iterator(t_std_collections_Map_1iTt_default_Voice_2_Node* l_node){
  bbDBFrame db_f{"new:Void(node:std.collections.Map<Int,default.Voice>.Node)","/Users/simon/monkey2/modules/std/collections/map.monkey2"};
  bbDBLocal("node",&l_node);
  bbDBStmt(565251);
  (*this).m__0node=l_node;
}

bbBool t_std_collections_Map_1iTt_default_Voice_2_Iterator::m_Valid(){
  bbDBFrame db_f{"Valid:Bool()","/Users/simon/monkey2/modules/std/collections/map.monkey2"};
  t_std_collections_Map_1iTt_default_Voice_2_Iterator*self=&(*this);
  bbDBLocal("Self",self);
  bbDBStmt(499715);
  return bbBool((*this).m__0node);
}

t_std_collections_Map_1iTt_default_Voice_2_Node* t_std_collections_Map_1iTt_default_Voice_2_Iterator::m_Current(){
  bbDBFrame db_f{"Current:std.collections.Map<Int,default.Voice>.Node()","/Users/simon/monkey2/modules/std/collections/map.monkey2"};
  t_std_collections_Map_1iTt_default_Voice_2_Iterator*self=&(*this);
  bbDBLocal("Self",self);
  bbDBStmt(516099);
  return (*this).m__0node;
}

void t_std_collections_Map_1iTt_default_Voice_2_Iterator::m_Bump(){
  bbDBFrame db_f{"Bump:Void()","/Users/simon/monkey2/modules/std/collections/map.monkey2"};
  t_std_collections_Map_1iTt_default_Voice_2_Iterator*self=&(*this);
  bbDBLocal("Self",self);
  bbDBStmt(532483);
  (*this).m__0node=(*this).m__0node->m_NextNode();
}
bbString bbDBType(t_std_collections_Map_1iTt_default_Voice_2_Iterator*){
  return "std.collections.Map<Int,default.Voice>.Iterator";
}
bbString bbDBValue(t_std_collections_Map_1iTt_default_Voice_2_Iterator*p){
  return bbDBStructValue(p);
}

int bbCompare(const t_std_collections_Map_1iTt_default_Voice_2_Iterator&x,const t_std_collections_Map_1iTt_default_Voice_2_Iterator&y){
  if(int t=bbCompare(x.m__0node,y.m__0node)) return t;
  return 0;
}

void bbGCMark(const t_std_collections_Map_1iTt_default_Voice_2_Iterator&t){
  bbGCMark(t.m__0node);
}

void t_std_collections_Map_1iTt_default_Voice_2_KeyIterator::dbEmit(t_std_collections_Map_1iTt_default_Voice_2_KeyIterator*p){
  bbDBEmit("_node",&p->m__0node);
}

t_std_collections_Map_1iTt_default_Voice_2_KeyIterator::t_std_collections_Map_1iTt_default_Voice_2_KeyIterator(t_std_collections_Map_1iTt_default_Voice_2_Node* l_node){
  bbDBFrame db_f{"new:Void(node:std.collections.Map<Int,default.Voice>.Node)","/Users/simon/monkey2/modules/std/collections/map.monkey2"};
  bbDBLocal("node",&l_node);
  bbDBStmt(663555);
  (*this).m__0node=l_node;
}

bbBool t_std_collections_Map_1iTt_default_Voice_2_KeyIterator::m_Valid(){
  bbDBFrame db_f{"Valid:Bool()","/Users/simon/monkey2/modules/std/collections/map.monkey2"};
  t_std_collections_Map_1iTt_default_Voice_2_KeyIterator*self=&(*this);
  bbDBLocal("Self",self);
  bbDBStmt(598019);
  return bbBool((*this).m__0node);
}

bbInt t_std_collections_Map_1iTt_default_Voice_2_KeyIterator::m_Current(){
  bbDBFrame db_f{"Current:Int()","/Users/simon/monkey2/modules/std/collections/map.monkey2"};
  t_std_collections_Map_1iTt_default_Voice_2_KeyIterator*self=&(*this);
  bbDBLocal("Self",self);
  bbDBStmt(614403);
  return (*this).m__0node->m__0key;
}

void t_std_collections_Map_1iTt_default_Voice_2_KeyIterator::m_Bump(){
  bbDBFrame db_f{"Bump:Void()","/Users/simon/monkey2/modules/std/collections/map.monkey2"};
  t_std_collections_Map_1iTt_default_Voice_2_KeyIterator*self=&(*this);
  bbDBLocal("Self",self);
  bbDBStmt(630787);
  (*this).m__0node=(*this).m__0node->m_NextNode();
}
bbString bbDBType(t_std_collections_Map_1iTt_default_Voice_2_KeyIterator*){
  return "std.collections.Map<Int,default.Voice>.KeyIterator";
}
bbString bbDBValue(t_std_collections_Map_1iTt_default_Voice_2_KeyIterator*p){
  return bbDBStructValue(p);
}

int bbCompare(const t_std_collections_Map_1iTt_default_Voice_2_KeyIterator&x,const t_std_collections_Map_1iTt_default_Voice_2_KeyIterator&y){
  if(int t=bbCompare(x.m__0node,y.m__0node)) return t;
  return 0;
}

void bbGCMark(const t_std_collections_Map_1iTt_default_Voice_2_KeyIterator&t){
  bbGCMark(t.m__0node);
}

void t_std_collections_Map_1iTt_default_Voice_2_MapKeys::dbEmit(t_std_collections_Map_1iTt_default_Voice_2_MapKeys*p){
  bbDBEmit("_map",&p->m__0map);
}

t_std_collections_Map_1iTt_default_Voice_2_MapKeys::t_std_collections_Map_1iTt_default_Voice_2_MapKeys(t_std_collections_Map_1iTt_default_Voice_2* l_map){
  bbDBFrame db_f{"new:Void(map:std.collections.Map<Int,default.Voice>)","/Users/simon/monkey2/modules/std/collections/map.monkey2"};
  bbDBLocal("map",&l_map);
  bbDBStmt(827395);
  (*this).m__0map=l_map;
}

t_std_collections_Map_1iTt_default_Voice_2_KeyIterator t_std_collections_Map_1iTt_default_Voice_2_MapKeys::m_All(){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1iTt_default_Voice_2_Node* t0{};
    void gcMark(){
      bbGCMarkPtr(t0);
    }
  }f0{};
  bbDBFrame db_f{"All:std.collections.Map<Int,default.Voice>.KeyIterator()","/Users/simon/monkey2/modules/std/collections/map.monkey2"};
  t_std_collections_Map_1iTt_default_Voice_2_MapKeys*self=&(*this);
  bbDBLocal("Self",self);
  bbDBStmt(794627);
  return t_std_collections_Map_1iTt_default_Voice_2_KeyIterator(f0.t0=(*this).m__0map->m_FirstNode());
}
bbString bbDBType(t_std_collections_Map_1iTt_default_Voice_2_MapKeys*){
  return "std.collections.Map<Int,default.Voice>.MapKeys";
}
bbString bbDBValue(t_std_collections_Map_1iTt_default_Voice_2_MapKeys*p){
  return bbDBStructValue(p);
}

int bbCompare(const t_std_collections_Map_1iTt_default_Voice_2_MapKeys&x,const t_std_collections_Map_1iTt_default_Voice_2_MapKeys&y){
  if(int t=bbCompare(x.m__0map,y.m__0map)) return t;
  return 0;
}

void bbGCMark(const t_std_collections_Map_1iTt_default_Voice_2_MapKeys&t){
  bbGCMark(t.m__0map);
}

void t_std_collections_Map_1iTt_default_Voice_2_ValueIterator::dbEmit(t_std_collections_Map_1iTt_default_Voice_2_ValueIterator*p){
  bbDBEmit("_node",&p->m__0node);
}

t_std_collections_Map_1iTt_default_Voice_2_ValueIterator::t_std_collections_Map_1iTt_default_Voice_2_ValueIterator(t_std_collections_Map_1iTt_default_Voice_2_Node* l_node){
  bbDBFrame db_f{"new:Void(node:std.collections.Map<Int,default.Voice>.Node)","/Users/simon/monkey2/modules/std/collections/map.monkey2"};
  bbDBLocal("node",&l_node);
  bbDBStmt(761859);
  (*this).m__0node=l_node;
}

bbBool t_std_collections_Map_1iTt_default_Voice_2_ValueIterator::m_Valid(){
  bbDBFrame db_f{"Valid:Bool()","/Users/simon/monkey2/modules/std/collections/map.monkey2"};
  t_std_collections_Map_1iTt_default_Voice_2_ValueIterator*self=&(*this);
  bbDBLocal("Self",self);
  bbDBStmt(696323);
  return bbBool((*this).m__0node);
}

t_default_Voice* t_std_collections_Map_1iTt_default_Voice_2_ValueIterator::m_Current(){
  bbDBFrame db_f{"Current:default.Voice()","/Users/simon/monkey2/modules/std/collections/map.monkey2"};
  t_std_collections_Map_1iTt_default_Voice_2_ValueIterator*self=&(*this);
  bbDBLocal("Self",self);
  bbDBStmt(712707);
  return (*this).m__0node->m__0value;
}

void t_std_collections_Map_1iTt_default_Voice_2_ValueIterator::m_Bump(){
  bbDBFrame db_f{"Bump:Void()","/Users/simon/monkey2/modules/std/collections/map.monkey2"};
  t_std_collections_Map_1iTt_default_Voice_2_ValueIterator*self=&(*this);
  bbDBLocal("Self",self);
  bbDBStmt(729091);
  (*this).m__0node=(*this).m__0node->m_NextNode();
}
bbString bbDBType(t_std_collections_Map_1iTt_default_Voice_2_ValueIterator*){
  return "std.collections.Map<Int,default.Voice>.ValueIterator";
}
bbString bbDBValue(t_std_collections_Map_1iTt_default_Voice_2_ValueIterator*p){
  return bbDBStructValue(p);
}

int bbCompare(const t_std_collections_Map_1iTt_default_Voice_2_ValueIterator&x,const t_std_collections_Map_1iTt_default_Voice_2_ValueIterator&y){
  if(int t=bbCompare(x.m__0node,y.m__0node)) return t;
  return 0;
}

void bbGCMark(const t_std_collections_Map_1iTt_default_Voice_2_ValueIterator&t){
  bbGCMark(t.m__0node);
}

void t_std_collections_Map_1iTt_default_Voice_2_MapValues::dbEmit(t_std_collections_Map_1iTt_default_Voice_2_MapValues*p){
  bbDBEmit("_map",&p->m__0map);
}

t_std_collections_Map_1iTt_default_Voice_2_MapValues::t_std_collections_Map_1iTt_default_Voice_2_MapValues(t_std_collections_Map_1iTt_default_Voice_2* l_map){
  bbDBFrame db_f{"new:Void(map:std.collections.Map<Int,default.Voice>)","/Users/simon/monkey2/modules/std/collections/map.monkey2"};
  bbDBLocal("map",&l_map);
  bbDBStmt(892931);
  (*this).m__0map=l_map;
}

t_std_collections_Map_1iTt_default_Voice_2_ValueIterator t_std_collections_Map_1iTt_default_Voice_2_MapValues::m_All(){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1iTt_default_Voice_2_Node* t0{};
    void gcMark(){
      bbGCMarkPtr(t0);
    }
  }f0{};
  bbDBFrame db_f{"All:std.collections.Map<Int,default.Voice>.ValueIterator()","/Users/simon/monkey2/modules/std/collections/map.monkey2"};
  t_std_collections_Map_1iTt_default_Voice_2_MapValues*self=&(*this);
  bbDBLocal("Self",self);
  bbDBStmt(860163);
  return t_std_collections_Map_1iTt_default_Voice_2_ValueIterator(f0.t0=(*this).m__0map->m_FirstNode());
}
bbString bbDBType(t_std_collections_Map_1iTt_default_Voice_2_MapValues*){
  return "std.collections.Map<Int,default.Voice>.MapValues";
}
bbString bbDBValue(t_std_collections_Map_1iTt_default_Voice_2_MapValues*p){
  return bbDBStructValue(p);
}

int bbCompare(const t_std_collections_Map_1iTt_default_Voice_2_MapValues&x,const t_std_collections_Map_1iTt_default_Voice_2_MapValues&y){
  if(int t=bbCompare(x.m__0map,y.m__0map)) return t;
  return 0;
}

void bbGCMark(const t_std_collections_Map_1iTt_default_Voice_2_MapValues&t){
  bbGCMark(t.m__0map);
}

void t_std_collections_Map_1iTt_default_Voice_2::gcMark(){
  bbGCMark(m__0root);
}

void t_std_collections_Map_1iTt_default_Voice_2::dbEmit(){
  bbDBEmit("_root",&m__0root);
}

t_std_collections_Map_1iTt_default_Voice_2::t_std_collections_Map_1iTt_default_Voice_2(t_std_collections_Map_1iTt_default_Voice_2_Node* l_root){
  bbDBFrame db_f{"new:Void(root:std.collections.Map<Int,default.Voice>.Node)","/Users/simon/monkey2/modules/std/collections/map.monkey2"};
  bbDBLocal("root",&l_root);
  bbDBStmt(1941506);
  this->m__0root=l_root;
}

t_std_collections_Map_1iTt_default_Voice_2::t_std_collections_Map_1iTt_default_Voice_2(){
  bbDBFrame db_f{"new:Void()","/Users/simon/monkey2/modules/std/collections/map.monkey2"};
}

void t_std_collections_Map_1iTt_default_Voice_2::m__idxeq(bbInt l_key,t_default_Voice* l_value){
  bbDBFrame db_f{"[]=:Void(key:Int,value:default.Voice)","/Users/simon/monkey2/modules/std/collections/map.monkey2"};
  t_std_collections_Map_1iTt_default_Voice_2*self=this;
  bbDBLocal("Self",&self);
  bbDBLocal("key",&l_key);
  bbDBLocal("value",&l_value);
  bbDBStmt(1314818);
  this->m_Set(l_key,l_value);
}

t_default_Voice* t_std_collections_Map_1iTt_default_Voice_2::m__idx(bbInt l_key){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1iTt_default_Voice_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  bbDBFrame db_f{"[]:default.Voice(key:Int)","/Users/simon/monkey2/modules/std/collections/map.monkey2"};
  t_std_collections_Map_1iTt_default_Voice_2*self=this;
  bbDBLocal("Self",&self);
  bbDBLocal("key",&l_key);
  bbDBStmt(1359880);
  f0.l_node=this->m_FindNode(l_key);
  bbDBLocal("node",&f0.l_node);
  bbDBStmt(1363970);
  if(!bbBool(f0.l_node)){
    bbDBBlock db_blk;
    bbDBStmt(1363982);
    return ((t_default_Voice*)0);
  }
  bbDBStmt(1368066);
  return f0.l_node->m__0value;
}

t_std_collections_Map_1iTt_default_Voice_2_MapValues t_std_collections_Map_1iTt_default_Voice_2::m_Values(){
  bbDBFrame db_f{"Values:std.collections.Map<Int,default.Voice>.MapValues()","/Users/simon/monkey2/modules/std/collections/map.monkey2"};
  t_std_collections_Map_1iTt_default_Voice_2*self=this;
  bbDBLocal("Self",&self);
  bbDBStmt(1044482);
  return t_std_collections_Map_1iTt_default_Voice_2_MapValues(this);
}

bbBool t_std_collections_Map_1iTt_default_Voice_2::m_Update(bbInt l_key,t_default_Voice* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1iTt_default_Voice_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  bbDBFrame db_f{"Update:Bool(key:Int,value:default.Voice)","/Users/simon/monkey2/modules/std/collections/map.monkey2"};
  t_std_collections_Map_1iTt_default_Voice_2*self=this;
  bbDBLocal("Self",&self);
  bbDBLocal("key",&l_key);
  bbDBLocal("value",&l_value);
  bbDBStmt(1785864);
  f0.l_node=this->m_FindNode(l_key);
  bbDBLocal("node",&f0.l_node);
  bbDBStmt(1789954);
  if(!bbBool(f0.l_node)){
    bbDBBlock db_blk;
    bbDBStmt(1789966);
    return false;
  }
  bbDBStmt(1794050);
  f0.l_node->m__0value=l_value;
  bbDBStmt(1798146);
  return true;
}

bbBool t_std_collections_Map_1iTt_default_Voice_2::m_Set(bbInt l_key,t_default_Voice* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1iTt_default_Voice_2_Node* l_node{};
    t_std_collections_Map_1iTt_default_Voice_2_Node* l_parent{};
    void gcMark(){
      bbGCMarkPtr(l_node);
      bbGCMarkPtr(l_parent);
    }
  }f0{};
  bbDBFrame db_f{"Set:Bool(key:Int,value:default.Voice)","/Users/simon/monkey2/modules/std/collections/map.monkey2"};
  t_std_collections_Map_1iTt_default_Voice_2*self=this;
  bbDBLocal("Self",&self);
  bbDBLocal("key",&l_key);
  bbDBLocal("value",&l_value);
  bbDBStmt(1437698);
  if(!bbBool(this->m__0root)){
    bbDBBlock db_blk;
    bbDBStmt(1441795);
    this->m__0root=bbGCNew<t_std_collections_Map_1iTt_default_Voice_2_Node>(l_key,l_value,0,((t_std_collections_Map_1iTt_default_Voice_2_Node*)0));
    bbDBStmt(1445891);
    return true;
  }
  bbDBStmt(1458184);
  f0.l_node=this->m__0root;
  bbDBLocal("node",&f0.l_node);
  bbDBStmt(1458196);
  bbDBLocal("parent",&f0.l_parent);
  bbDBStmt(1458208);
  bbInt l_cmp{};
  bbDBLocal("cmp",&l_cmp);
  bbDBStmt(1466370);
  {
    bbDBLoop db_loop;
    while(bbBool(f0.l_node)){
      bbDBBlock db_blk;
      bbDBStmt(1470467);
      f0.l_parent=f0.l_node;
      bbDBStmt(1474563);
      l_cmp=bbCompare(l_key,f0.l_node->m__0key);
      bbDBStmt(1478659);
      if((l_cmp>bbInt(0))){
        bbDBBlock db_blk;
        bbDBStmt(1482756);
        f0.l_node=f0.l_node->m__0right;
      }else if(bbDBStmt(1486851),(l_cmp<bbInt(0))){
        bbDBBlock db_blk;
        bbDBStmt(1490948);
        f0.l_node=f0.l_node->m__0left;
      }else{
        bbDBStmt(1495043);
        bbDBBlock db_blk;
        bbDBStmt(1499140);
        f0.l_node->m__0value=l_value;
        bbDBStmt(1503236);
        return false;
      }
    }
  }
  bbDBStmt(1519618);
  f0.l_node=bbGCNew<t_std_collections_Map_1iTt_default_Voice_2_Node>(l_key,l_value,0,f0.l_parent);
  bbDBStmt(1527810);
  if((l_cmp>bbInt(0))){
    bbDBBlock db_blk;
    bbDBStmt(1527819);
    f0.l_parent->m__0right=f0.l_node;
  }else{
    bbDBStmt(1527838);
    bbDBBlock db_blk;
    bbDBStmt(1527843);
    f0.l_parent->m__0left=f0.l_node;
  }
  bbDBStmt(1536002);
  this->m_InsertFixup(f0.l_node);
  bbDBStmt(1544194);
  return true;
}

void t_std_collections_Map_1iTt_default_Voice_2::m_RotateRight(t_std_collections_Map_1iTt_default_Voice_2_Node* l_node){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1iTt_default_Voice_2_Node* l_child{};
    void gcMark(){
      bbGCMarkPtr(l_child);
    }
  }f0{};
  bbDBFrame db_f{"RotateRight:Void(node:std.collections.Map<Int,default.Voice>.Node)","/Users/simon/monkey2/modules/std/collections/map.monkey2"};
  t_std_collections_Map_1iTt_default_Voice_2*self=this;
  bbDBLocal("Self",&self);
  bbDBLocal("node",&l_node);
  bbDBStmt(2351112);
  f0.l_child=l_node->m__0left;
  bbDBLocal("child",&f0.l_child);
  bbDBStmt(2355202);
  l_node->m__0left=f0.l_child->m__0right;
  bbDBStmt(2359298);
  if(bbBool(f0.l_child->m__0right)){
    bbDBBlock db_blk;
    bbDBStmt(2363395);
    f0.l_child->m__0right->m__0parent=l_node;
  }
  bbDBStmt(2371586);
  f0.l_child->m__0parent=l_node->m__0parent;
  bbDBStmt(2375682);
  if(bbBool(l_node->m__0parent)){
    bbDBBlock db_blk;
    bbDBStmt(2379779);
    if((l_node==l_node->m__0parent->m__0right)){
      bbDBBlock db_blk;
      bbDBStmt(2383876);
      l_node->m__0parent->m__0right=f0.l_child;
    }else{
      bbDBStmt(2387971);
      bbDBBlock db_blk;
      bbDBStmt(2392068);
      l_node->m__0parent->m__0left=f0.l_child;
    }
  }else{
    bbDBStmt(2400258);
    bbDBBlock db_blk;
    bbDBStmt(2404355);
    this->m__0root=f0.l_child;
  }
  bbDBStmt(2412546);
  f0.l_child->m__0right=l_node;
  bbDBStmt(2416642);
  l_node->m__0parent=f0.l_child;
}

void t_std_collections_Map_1iTt_default_Voice_2::m_RotateLeft(t_std_collections_Map_1iTt_default_Voice_2_Node* l_node){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1iTt_default_Voice_2_Node* l_child{};
    void gcMark(){
      bbGCMarkPtr(l_child);
    }
  }f0{};
  bbDBFrame db_f{"RotateLeft:Void(node:std.collections.Map<Int,default.Voice>.Node)","/Users/simon/monkey2/modules/std/collections/map.monkey2"};
  t_std_collections_Map_1iTt_default_Voice_2*self=this;
  bbDBLocal("Self",&self);
  bbDBLocal("node",&l_node);
  bbDBStmt(2269192);
  f0.l_child=l_node->m__0right;
  bbDBLocal("child",&f0.l_child);
  bbDBStmt(2273282);
  l_node->m__0right=f0.l_child->m__0left;
  bbDBStmt(2277378);
  if(bbBool(f0.l_child->m__0left)){
    bbDBBlock db_blk;
    bbDBStmt(2281475);
    f0.l_child->m__0left->m__0parent=l_node;
  }
  bbDBStmt(2289666);
  f0.l_child->m__0parent=l_node->m__0parent;
  bbDBStmt(2293762);
  if(bbBool(l_node->m__0parent)){
    bbDBBlock db_blk;
    bbDBStmt(2297859);
    if((l_node==l_node->m__0parent->m__0left)){
      bbDBBlock db_blk;
      bbDBStmt(2301956);
      l_node->m__0parent->m__0left=f0.l_child;
    }else{
      bbDBStmt(2306051);
      bbDBBlock db_blk;
      bbDBStmt(2310148);
      l_node->m__0parent->m__0right=f0.l_child;
    }
  }else{
    bbDBStmt(2318338);
    bbDBBlock db_blk;
    bbDBStmt(2322435);
    this->m__0root=f0.l_child;
  }
  bbDBStmt(2330626);
  f0.l_child->m__0left=l_node;
  bbDBStmt(2334722);
  l_node->m__0parent=f0.l_child;
}

void t_std_collections_Map_1iTt_default_Voice_2::m_RemoveNode(t_std_collections_Map_1iTt_default_Voice_2_Node* l_node){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1iTt_default_Voice_2_Node* l_child{};
    t_std_collections_Map_1iTt_default_Voice_2_Node* l_parent{};
    t_std_collections_Map_1iTt_default_Voice_2_Node* l_splice{};
    void gcMark(){
      bbGCMarkPtr(l_child);
      bbGCMarkPtr(l_parent);
      bbGCMarkPtr(l_splice);
    }
  }f0{};
  bbDBFrame db_f{"RemoveNode:Void(node:std.collections.Map<Int,default.Voice>.Node)","/Users/simon/monkey2/modules/std/collections/map.monkey2"};
  t_std_collections_Map_1iTt_default_Voice_2*self=this;
  bbDBLocal("Self",&self);
  bbDBLocal("node",&l_node);
  bbDBStmt(2101256);
  bbDBLocal("splice",&f0.l_splice);
  bbDBStmt(2101268);
  bbDBLocal("child",&f0.l_child);
  bbDBStmt(2109442);
  if(!bbBool(l_node->m__0left)){
    bbDBBlock db_blk;
    bbDBStmt(2113539);
    f0.l_splice=l_node;
    bbDBStmt(2117635);
    f0.l_child=l_node->m__0right;
  }else if(bbDBStmt(2121730),!bbBool(l_node->m__0right)){
    bbDBBlock db_blk;
    bbDBStmt(2125827);
    f0.l_splice=l_node;
    bbDBStmt(2129923);
    f0.l_child=l_node->m__0left;
  }else{
    bbDBStmt(2134018);
    bbDBBlock db_blk;
    bbDBStmt(2138115);
    f0.l_splice=l_node->m__0left;
    bbDBStmt(2142211);
    {
      bbDBLoop db_loop;
      while(bbBool(f0.l_splice->m__0right)){
        bbDBBlock db_blk;
        bbDBStmt(2146308);
        f0.l_splice=f0.l_splice->m__0right;
      }
    }
    bbDBStmt(2154499);
    f0.l_child=f0.l_splice->m__0left;
    bbDBStmt(2158595);
    l_node->m__0key=f0.l_splice->m__0key;
    bbDBStmt(2162691);
    l_node->m__0value=f0.l_splice->m__0value;
  }
  bbDBStmt(2174984);
  f0.l_parent=f0.l_splice->m__0parent;
  bbDBLocal("parent",&f0.l_parent);
  bbDBStmt(2183170);
  if(bbBool(f0.l_child)){
    bbDBBlock db_blk;
    bbDBStmt(2187267);
    f0.l_child->m__0parent=f0.l_parent;
  }
  bbDBStmt(2199554);
  if(!bbBool(f0.l_parent)){
    bbDBBlock db_blk;
    bbDBStmt(2203651);
    this->m__0root=f0.l_child;
    bbDBStmt(2207747);
    return;
  }
  bbDBStmt(2220034);
  if((f0.l_splice==f0.l_parent->m__0left)){
    bbDBBlock db_blk;
    bbDBStmt(2224131);
    f0.l_parent->m__0left=f0.l_child;
  }else{
    bbDBStmt(2228226);
    bbDBBlock db_blk;
    bbDBStmt(2232323);
    f0.l_parent->m__0right=f0.l_child;
  }
  bbDBStmt(2244610);
  if((f0.l_splice->m__0color==1)){
    bbDBBlock db_blk;
    bbDBStmt(2248707);
    this->m_DeleteFixup(f0.l_child,f0.l_parent);
  }
}

bbBool t_std_collections_Map_1iTt_default_Voice_2::m_Remove(bbInt l_key){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1iTt_default_Voice_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  bbDBFrame db_f{"Remove:Bool(key:Int)","/Users/simon/monkey2/modules/std/collections/map.monkey2"};
  t_std_collections_Map_1iTt_default_Voice_2*self=this;
  bbDBLocal("Self",&self);
  bbDBLocal("key",&l_key);
  bbDBStmt(1896456);
  f0.l_node=this->m_FindNode(l_key);
  bbDBLocal("node",&f0.l_node);
  bbDBStmt(1900546);
  if(!bbBool(f0.l_node)){
    bbDBBlock db_blk;
    bbDBStmt(1900558);
    return false;
  }
  bbDBStmt(1904642);
  this->m_RemoveNode(f0.l_node);
  bbDBStmt(1908738);
  return true;
}

t_std_collections_Map_1iTt_default_Voice_2_Node* t_std_collections_Map_1iTt_default_Voice_2::m_LastNode(){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1iTt_default_Voice_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  bbDBFrame db_f{"LastNode:std.collections.Map<Int,default.Voice>.Node()","/Users/simon/monkey2/modules/std/collections/map.monkey2"};
  t_std_collections_Map_1iTt_default_Voice_2*self=this;
  bbDBLocal("Self",&self);
  bbDBStmt(1998850);
  if(!bbBool(this->m__0root)){
    bbDBBlock db_blk;
    bbDBStmt(1998863);
    return ((t_std_collections_Map_1iTt_default_Voice_2_Node*)0);
  }
  bbDBStmt(2007048);
  f0.l_node=this->m__0root;
  bbDBLocal("node",&f0.l_node);
  bbDBStmt(2011138);
  {
    bbDBLoop db_loop;
    while(bbBool(f0.l_node->m__0right)){
      bbDBBlock db_blk;
      bbDBStmt(2015235);
      f0.l_node=f0.l_node->m__0right;
    }
  }
  bbDBStmt(2023426);
  return f0.l_node;
}

t_std_collections_Map_1iTt_default_Voice_2_MapKeys t_std_collections_Map_1iTt_default_Voice_2::m_Keys(){
  bbDBFrame db_f{"Keys:std.collections.Map<Int,default.Voice>.MapKeys()","/Users/simon/monkey2/modules/std/collections/map.monkey2"};
  t_std_collections_Map_1iTt_default_Voice_2*self=this;
  bbDBLocal("Self",&self);
  bbDBStmt(999426);
  return t_std_collections_Map_1iTt_default_Voice_2_MapKeys(this);
}

void t_std_collections_Map_1iTt_default_Voice_2::m_InsertFixup(t_std_collections_Map_1iTt_default_Voice_2_Node* l_node){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1iTt_default_Voice_2_Node* l_node{};
    f0_t(t_std_collections_Map_1iTt_default_Voice_2_Node* l_node):l_node(l_node){
    }
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{l_node};
  bbDBFrame db_f{"InsertFixup:Void(node:std.collections.Map<Int,default.Voice>.Node)","/Users/simon/monkey2/modules/std/collections/map.monkey2"};
  t_std_collections_Map_1iTt_default_Voice_2*self=this;
  bbDBLocal("Self",&self);
  bbDBLocal("node",&f0.l_node);
  bbDBStmt(2433026);
  {
    bbDBLoop db_loop;
    while(((bbBool(f0.l_node->m__0parent)&&(f0.l_node->m__0parent->m__0color==0))&&bbBool(f0.l_node->m__0parent->m__0parent))){
      bbDBBlock db_blk;
      bbDBStmt(2437123);
      if((f0.l_node->m__0parent==f0.l_node->m__0parent->m__0parent->m__0left)){
        struct f2_t : public bbGCFrame{
          t_std_collections_Map_1iTt_default_Voice_2_Node* l_uncle{};
          void gcMark(){
            bbGCMarkPtr(l_uncle);
          }
        }f2{};
        bbDBBlock db_blk;
        bbDBStmt(2441226);
        f2.l_uncle=f0.l_node->m__0parent->m__0parent->m__0right;
        bbDBLocal("uncle",&f2.l_uncle);
        bbDBStmt(2445316);
        if((bbBool(f2.l_uncle)&&(f2.l_uncle->m__0color==0))){
          bbDBBlock db_blk;
          bbDBStmt(2449413);
          f0.l_node->m__0parent->m__0color=1;
          bbDBStmt(2453509);
          f2.l_uncle->m__0color=1;
          bbDBStmt(2457605);
          f2.l_uncle->m__0parent->m__0color=0;
          bbDBStmt(2461701);
          f0.l_node=f2.l_uncle->m__0parent;
        }else{
          bbDBStmt(2465796);
          bbDBBlock db_blk;
          bbDBStmt(2469893);
          if((f0.l_node==f0.l_node->m__0parent->m__0right)){
            bbDBBlock db_blk;
            bbDBStmt(2473990);
            f0.l_node=f0.l_node->m__0parent;
            bbDBStmt(2478086);
            this->m_RotateLeft(f0.l_node);
          }
          bbDBStmt(2486277);
          f0.l_node->m__0parent->m__0color=1;
          bbDBStmt(2490373);
          f0.l_node->m__0parent->m__0parent->m__0color=0;
          bbDBStmt(2494469);
          this->m_RotateRight(f0.l_node->m__0parent->m__0parent);
        }
      }else{
        bbDBStmt(2502659);
        struct f2_t : public bbGCFrame{
          t_std_collections_Map_1iTt_default_Voice_2_Node* l_uncle{};
          void gcMark(){
            bbGCMarkPtr(l_uncle);
          }
        }f2{};
        bbDBBlock db_blk;
        bbDBStmt(2506762);
        f2.l_uncle=f0.l_node->m__0parent->m__0parent->m__0left;
        bbDBLocal("uncle",&f2.l_uncle);
        bbDBStmt(2510852);
        if((bbBool(f2.l_uncle)&&(f2.l_uncle->m__0color==0))){
          bbDBBlock db_blk;
          bbDBStmt(2514949);
          f0.l_node->m__0parent->m__0color=1;
          bbDBStmt(2519045);
          f2.l_uncle->m__0color=1;
          bbDBStmt(2523141);
          f2.l_uncle->m__0parent->m__0color=0;
          bbDBStmt(2527237);
          f0.l_node=f2.l_uncle->m__0parent;
        }else{
          bbDBStmt(2531332);
          bbDBBlock db_blk;
          bbDBStmt(2535429);
          if((f0.l_node==f0.l_node->m__0parent->m__0left)){
            bbDBBlock db_blk;
            bbDBStmt(2539526);
            f0.l_node=f0.l_node->m__0parent;
            bbDBStmt(2543622);
            this->m_RotateRight(f0.l_node);
          }
          bbDBStmt(2551813);
          f0.l_node->m__0parent->m__0color=1;
          bbDBStmt(2555909);
          f0.l_node->m__0parent->m__0parent->m__0color=0;
          bbDBStmt(2560005);
          this->m_RotateLeft(f0.l_node->m__0parent->m__0parent);
        }
      }
    }
  }
  bbDBStmt(2576386);
  this->m__0root->m__0color=1;
}

t_default_Voice* t_std_collections_Map_1iTt_default_Voice_2::m_Get(bbInt l_key){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1iTt_default_Voice_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  bbDBFrame db_f{"Get:default.Voice(key:Int)","/Users/simon/monkey2/modules/std/collections/map.monkey2"};
  t_std_collections_Map_1iTt_default_Voice_2*self=this;
  bbDBLocal("Self",&self);
  bbDBLocal("key",&l_key);
  bbDBStmt(1843208);
  f0.l_node=this->m_FindNode(l_key);
  bbDBLocal("node",&f0.l_node);
  bbDBStmt(1847298);
  if(bbBool(f0.l_node)){
    bbDBBlock db_blk;
    bbDBStmt(1847306);
    return f0.l_node->m__0value;
  }
  bbDBStmt(1851394);
  return ((t_default_Voice*)0);
}

t_std_collections_Map_1iTt_default_Voice_2_Node* t_std_collections_Map_1iTt_default_Voice_2::m_FirstNode(){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1iTt_default_Voice_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  bbDBFrame db_f{"FirstNode:std.collections.Map<Int,default.Voice>.Node()","/Users/simon/monkey2/modules/std/collections/map.monkey2"};
  t_std_collections_Map_1iTt_default_Voice_2*self=this;
  bbDBLocal("Self",&self);
  bbDBStmt(1957890);
  if(!bbBool(this->m__0root)){
    bbDBBlock db_blk;
    bbDBStmt(1957903);
    return ((t_std_collections_Map_1iTt_default_Voice_2_Node*)0);
  }
  bbDBStmt(1966088);
  f0.l_node=this->m__0root;
  bbDBLocal("node",&f0.l_node);
  bbDBStmt(1970178);
  {
    bbDBLoop db_loop;
    while(bbBool(f0.l_node->m__0left)){
      bbDBBlock db_blk;
      bbDBStmt(1974275);
      f0.l_node=f0.l_node->m__0left;
    }
  }
  bbDBStmt(1982466);
  return f0.l_node;
}

t_std_collections_Map_1iTt_default_Voice_2_Node* t_std_collections_Map_1iTt_default_Voice_2::m_FindNode(bbInt l_key){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1iTt_default_Voice_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  bbDBFrame db_f{"FindNode:std.collections.Map<Int,default.Voice>.Node(key:Int)","/Users/simon/monkey2/modules/std/collections/map.monkey2"};
  t_std_collections_Map_1iTt_default_Voice_2*self=this;
  bbDBLocal("Self",&self);
  bbDBLocal("key",&l_key);
  bbDBStmt(2039816);
  f0.l_node=this->m__0root;
  bbDBLocal("node",&f0.l_node);
  bbDBStmt(2043906);
  {
    bbDBLoop db_loop;
    while(bbBool(f0.l_node)){
      bbDBBlock db_blk;
      bbDBStmt(2048009);
      bbInt l_cmp=bbCompare(l_key,f0.l_node->m__0key);
      bbDBLocal("cmp",&l_cmp);
      bbDBStmt(2052099);
      if((l_cmp>bbInt(0))){
        bbDBBlock db_blk;
        bbDBStmt(2056196);
        f0.l_node=f0.l_node->m__0right;
      }else if(bbDBStmt(2060291),(l_cmp<bbInt(0))){
        bbDBBlock db_blk;
        bbDBStmt(2064388);
        f0.l_node=f0.l_node->m__0left;
      }else{
        bbDBStmt(2068483);
        bbDBBlock db_blk;
        bbDBStmt(2072580);
        return f0.l_node;
      }
    }
  }
  bbDBStmt(2084866);
  return ((t_std_collections_Map_1iTt_default_Voice_2_Node*)0);
}

bbBool t_std_collections_Map_1iTt_default_Voice_2::m_Empty(){
  bbDBFrame db_f{"Empty:Bool()","/Users/simon/monkey2/modules/std/collections/map.monkey2"};
  t_std_collections_Map_1iTt_default_Voice_2*self=this;
  bbDBLocal("Self",&self);
  bbDBStmt(1191938);
  return (this->m__0root==((t_std_collections_Map_1iTt_default_Voice_2_Node*)0));
}

void t_std_collections_Map_1iTt_default_Voice_2::m_DeleteFixup(t_std_collections_Map_1iTt_default_Voice_2_Node* l_node,t_std_collections_Map_1iTt_default_Voice_2_Node* l_parent){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1iTt_default_Voice_2_Node* l_node{};
    t_std_collections_Map_1iTt_default_Voice_2_Node* l_parent{};
    f0_t(t_std_collections_Map_1iTt_default_Voice_2_Node* l_node,t_std_collections_Map_1iTt_default_Voice_2_Node* l_parent):l_node(l_node),l_parent(l_parent){
    }
    void gcMark(){
      bbGCMarkPtr(l_node);
      bbGCMarkPtr(l_parent);
    }
  }f0{l_node,l_parent};
  bbDBFrame db_f{"DeleteFixup:Void(node:std.collections.Map<Int,default.Voice>.Node,parent:std.collections.Map<Int,default.Voice>.Node)","/Users/simon/monkey2/modules/std/collections/map.monkey2"};
  t_std_collections_Map_1iTt_default_Voice_2*self=this;
  bbDBLocal("Self",&self);
  bbDBLocal("node",&f0.l_node);
  bbDBLocal("parent",&f0.l_parent);
  bbDBStmt(2596866);
  {
    bbDBLoop db_loop;
    while(((f0.l_node!=this->m__0root)&&(!bbBool(f0.l_node)||(f0.l_node->m__0color==1)))){
      bbDBBlock db_blk;
      bbDBStmt(2605059);
      if((f0.l_node==f0.l_parent->m__0left)){
        struct f2_t : public bbGCFrame{
          t_std_collections_Map_1iTt_default_Voice_2_Node* l_sib{};
          void gcMark(){
            bbGCMarkPtr(l_sib);
          }
        }f2{};
        bbDBBlock db_blk;
        bbDBStmt(2613258);
        f2.l_sib=f0.l_parent->m__0right;
        bbDBLocal("sib",&f2.l_sib);
        bbDBStmt(2621444);
        if((f2.l_sib->m__0color==0)){
          bbDBBlock db_blk;
          bbDBStmt(2625541);
          f2.l_sib->m__0color=1;
          bbDBStmt(2629637);
          f0.l_parent->m__0color=0;
          bbDBStmt(2633733);
          this->m_RotateLeft(f0.l_parent);
          bbDBStmt(2637829);
          f2.l_sib=f0.l_parent->m__0right;
        }
        bbDBStmt(2650116);
        if(((!bbBool(f2.l_sib->m__0left)||(f2.l_sib->m__0left->m__0color==1))&&(!bbBool(f2.l_sib->m__0right)||(f2.l_sib->m__0right->m__0color==1)))){
          bbDBBlock db_blk;
          bbDBStmt(2654213);
          f2.l_sib->m__0color=0;
          bbDBStmt(2658309);
          f0.l_node=f0.l_parent;
          bbDBStmt(2662405);
          f0.l_parent=f0.l_parent->m__0parent;
        }else{
          bbDBStmt(2666500);
          bbDBBlock db_blk;
          bbDBStmt(2670597);
          if((!bbBool(f2.l_sib->m__0right)||(f2.l_sib->m__0right->m__0color==1))){
            bbDBBlock db_blk;
            bbDBStmt(2674694);
            f2.l_sib->m__0left->m__0color=1;
            bbDBStmt(2678790);
            f2.l_sib->m__0color=0;
            bbDBStmt(2682886);
            this->m_RotateRight(f2.l_sib);
            bbDBStmt(2686982);
            f2.l_sib=f0.l_parent->m__0right;
          }
          bbDBStmt(2695173);
          f2.l_sib->m__0color=f0.l_parent->m__0color;
          bbDBStmt(2699269);
          f0.l_parent->m__0color=1;
          bbDBStmt(2703365);
          f2.l_sib->m__0right->m__0color=1;
          bbDBStmt(2707461);
          this->m_RotateLeft(f0.l_parent);
          bbDBStmt(2711557);
          f0.l_node=this->m__0root;
        }
      }else{
        bbDBStmt(2719747);
        struct f2_t : public bbGCFrame{
          t_std_collections_Map_1iTt_default_Voice_2_Node* l_sib{};
          void gcMark(){
            bbGCMarkPtr(l_sib);
          }
        }f2{};
        bbDBBlock db_blk;
        bbDBStmt(2723850);
        f2.l_sib=f0.l_parent->m__0left;
        bbDBLocal("sib",&f2.l_sib);
        bbDBStmt(2732036);
        if((f2.l_sib->m__0color==0)){
          bbDBBlock db_blk;
          bbDBStmt(2736133);
          f2.l_sib->m__0color=1;
          bbDBStmt(2740229);
          f0.l_parent->m__0color=0;
          bbDBStmt(2744325);
          this->m_RotateRight(f0.l_parent);
          bbDBStmt(2748421);
          f2.l_sib=f0.l_parent->m__0left;
        }
        bbDBStmt(2760708);
        if(((!bbBool(f2.l_sib->m__0right)||(f2.l_sib->m__0right->m__0color==1))&&(!bbBool(f2.l_sib->m__0left)||(f2.l_sib->m__0left->m__0color==1)))){
          bbDBBlock db_blk;
          bbDBStmt(2764805);
          f2.l_sib->m__0color=0;
          bbDBStmt(2768901);
          f0.l_node=f0.l_parent;
          bbDBStmt(2772997);
          f0.l_parent=f0.l_parent->m__0parent;
        }else{
          bbDBStmt(2777092);
          bbDBBlock db_blk;
          bbDBStmt(2781189);
          if((!bbBool(f2.l_sib->m__0left)||(f2.l_sib->m__0left->m__0color==1))){
            bbDBBlock db_blk;
            bbDBStmt(2785286);
            f2.l_sib->m__0right->m__0color=1;
            bbDBStmt(2789382);
            f2.l_sib->m__0color=0;
            bbDBStmt(2793478);
            this->m_RotateLeft(f2.l_sib);
            bbDBStmt(2797574);
            f2.l_sib=f0.l_parent->m__0left;
          }
          bbDBStmt(2805765);
          f2.l_sib->m__0color=f0.l_parent->m__0color;
          bbDBStmt(2809861);
          f0.l_parent->m__0color=1;
          bbDBStmt(2813957);
          f2.l_sib->m__0left->m__0color=1;
          bbDBStmt(2818053);
          this->m_RotateRight(f0.l_parent);
          bbDBStmt(2822149);
          f0.l_node=this->m__0root;
        }
      }
    }
  }
  bbDBStmt(2838530);
  if(bbBool(f0.l_node)){
    bbDBBlock db_blk;
    bbDBStmt(2838538);
    f0.l_node->m__0color=1;
  }
}

bbInt t_std_collections_Map_1iTt_default_Voice_2::m_Count(){
  bbDBFrame db_f{"Count:Int()","/Users/simon/monkey2/modules/std/collections/map.monkey2"};
  t_std_collections_Map_1iTt_default_Voice_2*self=this;
  bbDBLocal("Self",&self);
  bbDBStmt(1150978);
  if(!bbBool(this->m__0root)){
    bbDBBlock db_blk;
    bbDBStmt(1150991);
    return bbInt(0);
  }
  bbDBStmt(1155074);
  return this->m__0root->m_Count(bbInt(0));
}

t_std_collections_Map_1iTt_default_Voice_2* t_std_collections_Map_1iTt_default_Voice_2::m_Copy(){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1iTt_default_Voice_2_Node* l_root{};
    void gcMark(){
      bbGCMarkPtr(l_root);
    }
  }f0{};
  bbDBFrame db_f{"Copy:std.collections.Map<Int,default.Voice>()","/Users/simon/monkey2/modules/std/collections/map.monkey2"};
  t_std_collections_Map_1iTt_default_Voice_2*self=this;
  bbDBLocal("Self",&self);
  bbDBStmt(1081352);
  bbDBLocal("root",&f0.l_root);
  bbDBStmt(1085442);
  if(bbBool(this->m__0root)){
    bbDBBlock db_blk;
    bbDBStmt(1085451);
    f0.l_root=this->m__0root->m_Copy(((t_std_collections_Map_1iTt_default_Voice_2_Node*)0));
  }
  bbDBStmt(1089538);
  return bbGCNew<t_std_collections_Map_1iTt_default_Voice_2>(f0.l_root);
}

bbBool t_std_collections_Map_1iTt_default_Voice_2::m_Contains(bbInt l_key){
  bbDBFrame db_f{"Contains:Bool(key:Int)","/Users/simon/monkey2/modules/std/collections/map.monkey2"};
  t_std_collections_Map_1iTt_default_Voice_2*self=this;
  bbDBLocal("Self",&self);
  bbDBLocal("key",&l_key);
  bbDBStmt(1236994);
  return (this->m_FindNode(l_key)!=((t_std_collections_Map_1iTt_default_Voice_2_Node*)0));
}

void t_std_collections_Map_1iTt_default_Voice_2::m_Clear(){
  bbDBFrame db_f{"Clear:Void()","/Users/simon/monkey2/modules/std/collections/map.monkey2"};
  t_std_collections_Map_1iTt_default_Voice_2*self=this;
  bbDBLocal("Self",&self);
  bbDBStmt(1114114);
  this->m__0root=((t_std_collections_Map_1iTt_default_Voice_2_Node*)0);
}

t_std_collections_Map_1iTt_default_Voice_2_Iterator t_std_collections_Map_1iTt_default_Voice_2::m_All(){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1iTt_default_Voice_2_Node* t0{};
    void gcMark(){
      bbGCMarkPtr(t0);
    }
  }f0{};
  bbDBFrame db_f{"All:std.collections.Map<Int,default.Voice>.Iterator()","/Users/simon/monkey2/modules/std/collections/map.monkey2"};
  t_std_collections_Map_1iTt_default_Voice_2*self=this;
  bbDBLocal("Self",&self);
  bbDBStmt(954370);
  return t_std_collections_Map_1iTt_default_Voice_2_Iterator(f0.t0=this->m_FirstNode());
}

bbBool t_std_collections_Map_1iTt_default_Voice_2::m_Add(bbInt l_key,t_default_Voice* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1iTt_default_Voice_2_Node* l_node{};
    t_std_collections_Map_1iTt_default_Voice_2_Node* l_parent{};
    void gcMark(){
      bbGCMarkPtr(l_node);
      bbGCMarkPtr(l_parent);
    }
  }f0{};
  bbDBFrame db_f{"Add:Bool(key:Int,value:default.Voice)","/Users/simon/monkey2/modules/std/collections/map.monkey2"};
  t_std_collections_Map_1iTt_default_Voice_2*self=this;
  bbDBLocal("Self",&self);
  bbDBLocal("key",&l_key);
  bbDBLocal("value",&l_value);
  bbDBStmt(1613826);
  if(!bbBool(this->m__0root)){
    bbDBBlock db_blk;
    bbDBStmt(1617923);
    this->m__0root=bbGCNew<t_std_collections_Map_1iTt_default_Voice_2_Node>(l_key,l_value,0,((t_std_collections_Map_1iTt_default_Voice_2_Node*)0));
    bbDBStmt(1622019);
    return true;
  }
  bbDBStmt(1634312);
  f0.l_node=this->m__0root;
  bbDBLocal("node",&f0.l_node);
  bbDBStmt(1634324);
  bbDBLocal("parent",&f0.l_parent);
  bbDBStmt(1634336);
  bbInt l_cmp{};
  bbDBLocal("cmp",&l_cmp);
  bbDBStmt(1642498);
  {
    bbDBLoop db_loop;
    while(bbBool(f0.l_node)){
      bbDBBlock db_blk;
      bbDBStmt(1646595);
      f0.l_parent=f0.l_node;
      bbDBStmt(1650691);
      l_cmp=bbCompare(l_key,f0.l_node->m__0key);
      bbDBStmt(1654787);
      if((l_cmp>bbInt(0))){
        bbDBBlock db_blk;
        bbDBStmt(1658884);
        f0.l_node=f0.l_node->m__0right;
      }else if(bbDBStmt(1662979),(l_cmp<bbInt(0))){
        bbDBBlock db_blk;
        bbDBStmt(1667076);
        f0.l_node=f0.l_node->m__0left;
      }else{
        bbDBStmt(1671171);
        bbDBBlock db_blk;
        bbDBStmt(1675268);
        return false;
      }
    }
  }
  bbDBStmt(1691650);
  f0.l_node=bbGCNew<t_std_collections_Map_1iTt_default_Voice_2_Node>(l_key,l_value,0,f0.l_parent);
  bbDBStmt(1699842);
  if((l_cmp>bbInt(0))){
    bbDBBlock db_blk;
    bbDBStmt(1699851);
    f0.l_parent->m__0right=f0.l_node;
  }else{
    bbDBStmt(1699870);
    bbDBBlock db_blk;
    bbDBStmt(1699875);
    f0.l_parent->m__0left=f0.l_node;
  }
  bbDBStmt(1708034);
  this->m_InsertFixup(f0.l_node);
  bbDBStmt(1716226);
  return true;
}
bbString bbDBType(t_std_collections_Map_1iTt_default_Voice_2**){
  return "std.collections.Map<Int,default.Voice>";
}
bbString bbDBValue(t_std_collections_Map_1iTt_default_Voice_2**p){
  return bbDBObjectValue(*p);
}

void t_std_collections_Map_1TbbInt_2i_Node::gcMark(){
  bbGCMark(m__0left);
  bbGCMark(m__0right);
  bbGCMark(m__0parent);
}

void t_std_collections_Map_1TbbInt_2i_Node::dbEmit(){
  bbDBEmit("_key",&m__0key);
  bbDBEmit("_value",&m__0value);
  bbDBEmit("_color",&m__0color);
  bbDBEmit("_left",&m__0left);
  bbDBEmit("_right",&m__0right);
  bbDBEmit("_parent",&m__0parent);
}

t_std_collections_Map_1TbbInt_2i_Node::t_std_collections_Map_1TbbInt_2i_Node(bbInt l_key,bbInt l_value,bbInt l_color,t_std_collections_Map_1TbbInt_2i_Node* l_parent){
  bbDBFrame db_f{"new:Void(key:mojo.input.Key,value:Int,color:std.collections.Map<mojo.input.Key,Int>.Node.Color,parent:std.collections.Map<mojo.input.Key,Int>.Node)","/Users/simon/monkey2/modules/std/collections/map.monkey2"};
  bbDBLocal("key",&l_key);
  bbDBLocal("value",&l_value);
  bbDBLocal("color",&l_color);
  bbDBLocal("parent",&l_parent);
  bbDBStmt(270339);
  this->m__0key=l_key;
  bbDBStmt(274435);
  this->m__0value=l_value;
  bbDBStmt(278531);
  this->m__0color=l_color;
  bbDBStmt(282627);
  this->m__0parent=l_parent;
}

bbInt t_std_collections_Map_1TbbInt_2i_Node::m_Value(){
  bbDBFrame db_f{"Value:Int()","/Users/simon/monkey2/modules/std/collections/map.monkey2"};
  t_std_collections_Map_1TbbInt_2i_Node*self=this;
  bbDBLocal("Self",&self);
  bbDBStmt(196611);
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
  bbDBFrame db_f{"PrevNode:std.collections.Map<mojo.input.Key,Int>.Node()","/Users/simon/monkey2/modules/std/collections/map.monkey2"};
  t_std_collections_Map_1TbbInt_2i_Node*self=this;
  bbDBLocal("Self",&self);
  bbDBStmt(389123);
  if(bbBool(this->m__0left)){
    struct f1_t : public bbGCFrame{
      t_std_collections_Map_1TbbInt_2i_Node* l_node{};
      void gcMark(){
        bbGCMarkPtr(l_node);
      }
    }f1{};
    bbDBBlock db_blk;
    bbDBStmt(393226);
    f1.l_node=this->m__0left;
    bbDBLocal("node",&f1.l_node);
    bbDBStmt(397316);
    {
      bbDBLoop db_loop;
      while(bbBool(f1.l_node->m__0right)){
        bbDBBlock db_blk;
        bbDBStmt(401413);
        f1.l_node=f1.l_node->m__0right;
      }
    }
    bbDBStmt(409604);
    return f1.l_node;
  }
  bbDBStmt(417801);
  f0.l_node=this;
  bbDBLocal("node",&f0.l_node);
  bbDBStmt(417812);
  f0.l_parent=this->m__0parent;
  bbDBLocal("parent",&f0.l_parent);
  bbDBStmt(421891);
  {
    bbDBLoop db_loop;
    while((bbBool(f0.l_parent)&&(f0.l_node==f0.l_parent->m__0left))){
      bbDBBlock db_blk;
      bbDBStmt(425988);
      f0.l_node=f0.l_parent;
      bbDBStmt(430084);
      f0.l_parent=f0.l_parent->m__0parent;
    }
  }
  bbDBStmt(438275);
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
  bbDBFrame db_f{"NextNode:std.collections.Map<mojo.input.Key,Int>.Node()","/Users/simon/monkey2/modules/std/collections/map.monkey2"};
  t_std_collections_Map_1TbbInt_2i_Node*self=this;
  bbDBLocal("Self",&self);
  bbDBStmt(323587);
  if(bbBool(this->m__0right)){
    struct f1_t : public bbGCFrame{
      t_std_collections_Map_1TbbInt_2i_Node* l_node{};
      void gcMark(){
        bbGCMarkPtr(l_node);
      }
    }f1{};
    bbDBBlock db_blk;
    bbDBStmt(327690);
    f1.l_node=this->m__0right;
    bbDBLocal("node",&f1.l_node);
    bbDBStmt(331780);
    {
      bbDBLoop db_loop;
      while(bbBool(f1.l_node->m__0left)){
        bbDBBlock db_blk;
        bbDBStmt(335877);
        f1.l_node=f1.l_node->m__0left;
      }
    }
    bbDBStmt(344068);
    return f1.l_node;
  }
  bbDBStmt(352265);
  f0.l_node=this;
  bbDBLocal("node",&f0.l_node);
  bbDBStmt(352276);
  f0.l_parent=this->m__0parent;
  bbDBLocal("parent",&f0.l_parent);
  bbDBStmt(356355);
  {
    bbDBLoop db_loop;
    while((bbBool(f0.l_parent)&&(f0.l_node==f0.l_parent->m__0right))){
      bbDBBlock db_blk;
      bbDBStmt(360452);
      f0.l_node=f0.l_parent;
      bbDBStmt(364548);
      f0.l_parent=f0.l_parent->m__0parent;
    }
  }
  bbDBStmt(372739);
  return f0.l_parent;
}

bbInt t_std_collections_Map_1TbbInt_2i_Node::m_Key(){
  bbDBFrame db_f{"Key:mojo.input.Key()","/Users/simon/monkey2/modules/std/collections/map.monkey2"};
  t_std_collections_Map_1TbbInt_2i_Node*self=this;
  bbDBLocal("Self",&self);
  bbDBStmt(159747);
  return this->m__0key;
}

bbInt t_std_collections_Map_1TbbInt_2i_Node::m_Count(bbInt l_n){
  bbDBFrame db_f{"Count:Int(n:Int)","/Users/simon/monkey2/modules/std/collections/map.monkey2"};
  t_std_collections_Map_1TbbInt_2i_Node*self=this;
  bbDBLocal("Self",&self);
  bbDBLocal("n",&l_n);
  bbDBStmt(299011);
  if(bbBool(this->m__0left)){
    bbDBBlock db_blk;
    bbDBStmt(299020);
    l_n=this->m__0left->m_Count(l_n);
  }
  bbDBStmt(303107);
  if(bbBool(this->m__0right)){
    bbDBBlock db_blk;
    bbDBStmt(303117);
    l_n=this->m__0right->m_Count(l_n);
  }
  bbDBStmt(307203);
  return (l_n+1);
}

t_std_collections_Map_1TbbInt_2i_Node* t_std_collections_Map_1TbbInt_2i_Node::m_Copy(t_std_collections_Map_1TbbInt_2i_Node* l_parent){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1TbbInt_2i_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  bbDBFrame db_f{"Copy:std.collections.Map<mojo.input.Key,Int>.Node(parent:std.collections.Map<mojo.input.Key,Int>.Node)","/Users/simon/monkey2/modules/std/collections/map.monkey2"};
  t_std_collections_Map_1TbbInt_2i_Node*self=this;
  bbDBLocal("Self",&self);
  bbDBLocal("parent",&l_parent);
  bbDBStmt(454665);
  f0.l_node=bbGCNew<t_std_collections_Map_1TbbInt_2i_Node>(this->m__0key,this->m__0value,this->m__0color,l_parent);
  bbDBLocal("node",&f0.l_node);
  bbDBStmt(458755);
  if(bbBool(this->m__0left)){
    bbDBBlock db_blk;
    bbDBStmt(458764);
    f0.l_node->m__0left=this->m__0left->m_Copy(f0.l_node);
  }
  bbDBStmt(462851);
  if(bbBool(this->m__0right)){
    bbDBBlock db_blk;
    bbDBStmt(462861);
    f0.l_node->m__0right=this->m__0right->m_Copy(f0.l_node);
  }
  bbDBStmt(466947);
  return f0.l_node;
}
bbString bbDBType(t_std_collections_Map_1TbbInt_2i_Node**){
  return "std.collections.Map<mojo.input.Key,Int>.Node";
}
bbString bbDBValue(t_std_collections_Map_1TbbInt_2i_Node**p){
  return bbDBObjectValue(*p);
}

void t_std_collections_Map_1TbbInt_2i_Iterator::dbEmit(t_std_collections_Map_1TbbInt_2i_Iterator*p){
  bbDBEmit("_node",&p->m__0node);
}

t_std_collections_Map_1TbbInt_2i_Iterator::t_std_collections_Map_1TbbInt_2i_Iterator(t_std_collections_Map_1TbbInt_2i_Node* l_node){
  bbDBFrame db_f{"new:Void(node:std.collections.Map<mojo.input.Key,Int>.Node)","/Users/simon/monkey2/modules/std/collections/map.monkey2"};
  bbDBLocal("node",&l_node);
  bbDBStmt(565251);
  (*this).m__0node=l_node;
}

bbBool t_std_collections_Map_1TbbInt_2i_Iterator::m_Valid(){
  bbDBFrame db_f{"Valid:Bool()","/Users/simon/monkey2/modules/std/collections/map.monkey2"};
  t_std_collections_Map_1TbbInt_2i_Iterator*self=&(*this);
  bbDBLocal("Self",self);
  bbDBStmt(499715);
  return bbBool((*this).m__0node);
}

t_std_collections_Map_1TbbInt_2i_Node* t_std_collections_Map_1TbbInt_2i_Iterator::m_Current(){
  bbDBFrame db_f{"Current:std.collections.Map<mojo.input.Key,Int>.Node()","/Users/simon/monkey2/modules/std/collections/map.monkey2"};
  t_std_collections_Map_1TbbInt_2i_Iterator*self=&(*this);
  bbDBLocal("Self",self);
  bbDBStmt(516099);
  return (*this).m__0node;
}

void t_std_collections_Map_1TbbInt_2i_Iterator::m_Bump(){
  bbDBFrame db_f{"Bump:Void()","/Users/simon/monkey2/modules/std/collections/map.monkey2"};
  t_std_collections_Map_1TbbInt_2i_Iterator*self=&(*this);
  bbDBLocal("Self",self);
  bbDBStmt(532483);
  (*this).m__0node=(*this).m__0node->m_NextNode();
}
bbString bbDBType(t_std_collections_Map_1TbbInt_2i_Iterator*){
  return "std.collections.Map<mojo.input.Key,Int>.Iterator";
}
bbString bbDBValue(t_std_collections_Map_1TbbInt_2i_Iterator*p){
  return bbDBStructValue(p);
}

int bbCompare(const t_std_collections_Map_1TbbInt_2i_Iterator&x,const t_std_collections_Map_1TbbInt_2i_Iterator&y){
  if(int t=bbCompare(x.m__0node,y.m__0node)) return t;
  return 0;
}

void bbGCMark(const t_std_collections_Map_1TbbInt_2i_Iterator&t){
  bbGCMark(t.m__0node);
}

void t_std_collections_Map_1TbbInt_2i_KeyIterator::dbEmit(t_std_collections_Map_1TbbInt_2i_KeyIterator*p){
  bbDBEmit("_node",&p->m__0node);
}

t_std_collections_Map_1TbbInt_2i_KeyIterator::t_std_collections_Map_1TbbInt_2i_KeyIterator(t_std_collections_Map_1TbbInt_2i_Node* l_node){
  bbDBFrame db_f{"new:Void(node:std.collections.Map<mojo.input.Key,Int>.Node)","/Users/simon/monkey2/modules/std/collections/map.monkey2"};
  bbDBLocal("node",&l_node);
  bbDBStmt(663555);
  (*this).m__0node=l_node;
}

bbBool t_std_collections_Map_1TbbInt_2i_KeyIterator::m_Valid(){
  bbDBFrame db_f{"Valid:Bool()","/Users/simon/monkey2/modules/std/collections/map.monkey2"};
  t_std_collections_Map_1TbbInt_2i_KeyIterator*self=&(*this);
  bbDBLocal("Self",self);
  bbDBStmt(598019);
  return bbBool((*this).m__0node);
}

bbInt t_std_collections_Map_1TbbInt_2i_KeyIterator::m_Current(){
  bbDBFrame db_f{"Current:mojo.input.Key()","/Users/simon/monkey2/modules/std/collections/map.monkey2"};
  t_std_collections_Map_1TbbInt_2i_KeyIterator*self=&(*this);
  bbDBLocal("Self",self);
  bbDBStmt(614403);
  return (*this).m__0node->m__0key;
}

void t_std_collections_Map_1TbbInt_2i_KeyIterator::m_Bump(){
  bbDBFrame db_f{"Bump:Void()","/Users/simon/monkey2/modules/std/collections/map.monkey2"};
  t_std_collections_Map_1TbbInt_2i_KeyIterator*self=&(*this);
  bbDBLocal("Self",self);
  bbDBStmt(630787);
  (*this).m__0node=(*this).m__0node->m_NextNode();
}
bbString bbDBType(t_std_collections_Map_1TbbInt_2i_KeyIterator*){
  return "std.collections.Map<mojo.input.Key,Int>.KeyIterator";
}
bbString bbDBValue(t_std_collections_Map_1TbbInt_2i_KeyIterator*p){
  return bbDBStructValue(p);
}

int bbCompare(const t_std_collections_Map_1TbbInt_2i_KeyIterator&x,const t_std_collections_Map_1TbbInt_2i_KeyIterator&y){
  if(int t=bbCompare(x.m__0node,y.m__0node)) return t;
  return 0;
}

void bbGCMark(const t_std_collections_Map_1TbbInt_2i_KeyIterator&t){
  bbGCMark(t.m__0node);
}

void t_std_collections_Map_1TbbInt_2i_MapKeys::dbEmit(t_std_collections_Map_1TbbInt_2i_MapKeys*p){
  bbDBEmit("_map",&p->m__0map);
}

t_std_collections_Map_1TbbInt_2i_MapKeys::t_std_collections_Map_1TbbInt_2i_MapKeys(t_std_collections_Map_1TbbInt_2i* l_map){
  bbDBFrame db_f{"new:Void(map:std.collections.Map<mojo.input.Key,Int>)","/Users/simon/monkey2/modules/std/collections/map.monkey2"};
  bbDBLocal("map",&l_map);
  bbDBStmt(827395);
  (*this).m__0map=l_map;
}

t_std_collections_Map_1TbbInt_2i_KeyIterator t_std_collections_Map_1TbbInt_2i_MapKeys::m_All(){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1TbbInt_2i_Node* t0{};
    void gcMark(){
      bbGCMarkPtr(t0);
    }
  }f0{};
  bbDBFrame db_f{"All:std.collections.Map<mojo.input.Key,Int>.KeyIterator()","/Users/simon/monkey2/modules/std/collections/map.monkey2"};
  t_std_collections_Map_1TbbInt_2i_MapKeys*self=&(*this);
  bbDBLocal("Self",self);
  bbDBStmt(794627);
  return t_std_collections_Map_1TbbInt_2i_KeyIterator(f0.t0=(*this).m__0map->m_FirstNode());
}
bbString bbDBType(t_std_collections_Map_1TbbInt_2i_MapKeys*){
  return "std.collections.Map<mojo.input.Key,Int>.MapKeys";
}
bbString bbDBValue(t_std_collections_Map_1TbbInt_2i_MapKeys*p){
  return bbDBStructValue(p);
}

int bbCompare(const t_std_collections_Map_1TbbInt_2i_MapKeys&x,const t_std_collections_Map_1TbbInt_2i_MapKeys&y){
  if(int t=bbCompare(x.m__0map,y.m__0map)) return t;
  return 0;
}

void bbGCMark(const t_std_collections_Map_1TbbInt_2i_MapKeys&t){
  bbGCMark(t.m__0map);
}

void t_std_collections_Map_1TbbInt_2i_ValueIterator::dbEmit(t_std_collections_Map_1TbbInt_2i_ValueIterator*p){
  bbDBEmit("_node",&p->m__0node);
}

t_std_collections_Map_1TbbInt_2i_ValueIterator::t_std_collections_Map_1TbbInt_2i_ValueIterator(t_std_collections_Map_1TbbInt_2i_Node* l_node){
  bbDBFrame db_f{"new:Void(node:std.collections.Map<mojo.input.Key,Int>.Node)","/Users/simon/monkey2/modules/std/collections/map.monkey2"};
  bbDBLocal("node",&l_node);
  bbDBStmt(761859);
  (*this).m__0node=l_node;
}

bbBool t_std_collections_Map_1TbbInt_2i_ValueIterator::m_Valid(){
  bbDBFrame db_f{"Valid:Bool()","/Users/simon/monkey2/modules/std/collections/map.monkey2"};
  t_std_collections_Map_1TbbInt_2i_ValueIterator*self=&(*this);
  bbDBLocal("Self",self);
  bbDBStmt(696323);
  return bbBool((*this).m__0node);
}

bbInt t_std_collections_Map_1TbbInt_2i_ValueIterator::m_Current(){
  bbDBFrame db_f{"Current:Int()","/Users/simon/monkey2/modules/std/collections/map.monkey2"};
  t_std_collections_Map_1TbbInt_2i_ValueIterator*self=&(*this);
  bbDBLocal("Self",self);
  bbDBStmt(712707);
  return (*this).m__0node->m__0value;
}

void t_std_collections_Map_1TbbInt_2i_ValueIterator::m_Bump(){
  bbDBFrame db_f{"Bump:Void()","/Users/simon/monkey2/modules/std/collections/map.monkey2"};
  t_std_collections_Map_1TbbInt_2i_ValueIterator*self=&(*this);
  bbDBLocal("Self",self);
  bbDBStmt(729091);
  (*this).m__0node=(*this).m__0node->m_NextNode();
}
bbString bbDBType(t_std_collections_Map_1TbbInt_2i_ValueIterator*){
  return "std.collections.Map<mojo.input.Key,Int>.ValueIterator";
}
bbString bbDBValue(t_std_collections_Map_1TbbInt_2i_ValueIterator*p){
  return bbDBStructValue(p);
}

int bbCompare(const t_std_collections_Map_1TbbInt_2i_ValueIterator&x,const t_std_collections_Map_1TbbInt_2i_ValueIterator&y){
  if(int t=bbCompare(x.m__0node,y.m__0node)) return t;
  return 0;
}

void bbGCMark(const t_std_collections_Map_1TbbInt_2i_ValueIterator&t){
  bbGCMark(t.m__0node);
}

void t_std_collections_Map_1TbbInt_2i_MapValues::dbEmit(t_std_collections_Map_1TbbInt_2i_MapValues*p){
  bbDBEmit("_map",&p->m__0map);
}

t_std_collections_Map_1TbbInt_2i_MapValues::t_std_collections_Map_1TbbInt_2i_MapValues(t_std_collections_Map_1TbbInt_2i* l_map){
  bbDBFrame db_f{"new:Void(map:std.collections.Map<mojo.input.Key,Int>)","/Users/simon/monkey2/modules/std/collections/map.monkey2"};
  bbDBLocal("map",&l_map);
  bbDBStmt(892931);
  (*this).m__0map=l_map;
}

t_std_collections_Map_1TbbInt_2i_ValueIterator t_std_collections_Map_1TbbInt_2i_MapValues::m_All(){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1TbbInt_2i_Node* t0{};
    void gcMark(){
      bbGCMarkPtr(t0);
    }
  }f0{};
  bbDBFrame db_f{"All:std.collections.Map<mojo.input.Key,Int>.ValueIterator()","/Users/simon/monkey2/modules/std/collections/map.monkey2"};
  t_std_collections_Map_1TbbInt_2i_MapValues*self=&(*this);
  bbDBLocal("Self",self);
  bbDBStmt(860163);
  return t_std_collections_Map_1TbbInt_2i_ValueIterator(f0.t0=(*this).m__0map->m_FirstNode());
}
bbString bbDBType(t_std_collections_Map_1TbbInt_2i_MapValues*){
  return "std.collections.Map<mojo.input.Key,Int>.MapValues";
}
bbString bbDBValue(t_std_collections_Map_1TbbInt_2i_MapValues*p){
  return bbDBStructValue(p);
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

void t_std_collections_Map_1TbbInt_2i::dbEmit(){
  bbDBEmit("_root",&m__0root);
}

t_std_collections_Map_1TbbInt_2i::t_std_collections_Map_1TbbInt_2i(t_std_collections_Map_1TbbInt_2i_Node* l_root){
  bbDBFrame db_f{"new:Void(root:std.collections.Map<mojo.input.Key,Int>.Node)","/Users/simon/monkey2/modules/std/collections/map.monkey2"};
  bbDBLocal("root",&l_root);
  bbDBStmt(1941506);
  this->m__0root=l_root;
}

t_std_collections_Map_1TbbInt_2i::t_std_collections_Map_1TbbInt_2i(){
  bbDBFrame db_f{"new:Void()","/Users/simon/monkey2/modules/std/collections/map.monkey2"};
}

void t_std_collections_Map_1TbbInt_2i::m__idxeq(bbInt l_key,bbInt l_value){
  bbDBFrame db_f{"[]=:Void(key:mojo.input.Key,value:Int)","/Users/simon/monkey2/modules/std/collections/map.monkey2"};
  t_std_collections_Map_1TbbInt_2i*self=this;
  bbDBLocal("Self",&self);
  bbDBLocal("key",&l_key);
  bbDBLocal("value",&l_value);
  bbDBStmt(1314818);
  this->m_Set(l_key,l_value);
}

bbInt t_std_collections_Map_1TbbInt_2i::m__idx(bbInt l_key){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1TbbInt_2i_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  bbDBFrame db_f{"[]:Int(key:mojo.input.Key)","/Users/simon/monkey2/modules/std/collections/map.monkey2"};
  t_std_collections_Map_1TbbInt_2i*self=this;
  bbDBLocal("Self",&self);
  bbDBLocal("key",&l_key);
  bbDBStmt(1359880);
  f0.l_node=this->m_FindNode(l_key);
  bbDBLocal("node",&f0.l_node);
  bbDBStmt(1363970);
  if(!bbBool(f0.l_node)){
    bbDBBlock db_blk;
    bbDBStmt(1363982);
    return 0;
  }
  bbDBStmt(1368066);
  return f0.l_node->m__0value;
}

t_std_collections_Map_1TbbInt_2i_MapValues t_std_collections_Map_1TbbInt_2i::m_Values(){
  bbDBFrame db_f{"Values:std.collections.Map<mojo.input.Key,Int>.MapValues()","/Users/simon/monkey2/modules/std/collections/map.monkey2"};
  t_std_collections_Map_1TbbInt_2i*self=this;
  bbDBLocal("Self",&self);
  bbDBStmt(1044482);
  return t_std_collections_Map_1TbbInt_2i_MapValues(this);
}

bbBool t_std_collections_Map_1TbbInt_2i::m_Update(bbInt l_key,bbInt l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1TbbInt_2i_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  bbDBFrame db_f{"Update:Bool(key:mojo.input.Key,value:Int)","/Users/simon/monkey2/modules/std/collections/map.monkey2"};
  t_std_collections_Map_1TbbInt_2i*self=this;
  bbDBLocal("Self",&self);
  bbDBLocal("key",&l_key);
  bbDBLocal("value",&l_value);
  bbDBStmt(1785864);
  f0.l_node=this->m_FindNode(l_key);
  bbDBLocal("node",&f0.l_node);
  bbDBStmt(1789954);
  if(!bbBool(f0.l_node)){
    bbDBBlock db_blk;
    bbDBStmt(1789966);
    return false;
  }
  bbDBStmt(1794050);
  f0.l_node->m__0value=l_value;
  bbDBStmt(1798146);
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
  bbDBFrame db_f{"Set:Bool(key:mojo.input.Key,value:Int)","/Users/simon/monkey2/modules/std/collections/map.monkey2"};
  t_std_collections_Map_1TbbInt_2i*self=this;
  bbDBLocal("Self",&self);
  bbDBLocal("key",&l_key);
  bbDBLocal("value",&l_value);
  bbDBStmt(1437698);
  if(!bbBool(this->m__0root)){
    bbDBBlock db_blk;
    bbDBStmt(1441795);
    this->m__0root=bbGCNew<t_std_collections_Map_1TbbInt_2i_Node>(l_key,l_value,0,((t_std_collections_Map_1TbbInt_2i_Node*)0));
    bbDBStmt(1445891);
    return true;
  }
  bbDBStmt(1458184);
  f0.l_node=this->m__0root;
  bbDBLocal("node",&f0.l_node);
  bbDBStmt(1458196);
  bbDBLocal("parent",&f0.l_parent);
  bbDBStmt(1458208);
  bbInt l_cmp{};
  bbDBLocal("cmp",&l_cmp);
  bbDBStmt(1466370);
  {
    bbDBLoop db_loop;
    while(bbBool(f0.l_node)){
      bbDBBlock db_blk;
      bbDBStmt(1470467);
      f0.l_parent=f0.l_node;
      bbDBStmt(1474563);
      l_cmp=bbCompare(l_key,f0.l_node->m__0key);
      bbDBStmt(1478659);
      if((l_cmp>bbInt(0))){
        bbDBBlock db_blk;
        bbDBStmt(1482756);
        f0.l_node=f0.l_node->m__0right;
      }else if(bbDBStmt(1486851),(l_cmp<bbInt(0))){
        bbDBBlock db_blk;
        bbDBStmt(1490948);
        f0.l_node=f0.l_node->m__0left;
      }else{
        bbDBStmt(1495043);
        bbDBBlock db_blk;
        bbDBStmt(1499140);
        f0.l_node->m__0value=l_value;
        bbDBStmt(1503236);
        return false;
      }
    }
  }
  bbDBStmt(1519618);
  f0.l_node=bbGCNew<t_std_collections_Map_1TbbInt_2i_Node>(l_key,l_value,0,f0.l_parent);
  bbDBStmt(1527810);
  if((l_cmp>bbInt(0))){
    bbDBBlock db_blk;
    bbDBStmt(1527819);
    f0.l_parent->m__0right=f0.l_node;
  }else{
    bbDBStmt(1527838);
    bbDBBlock db_blk;
    bbDBStmt(1527843);
    f0.l_parent->m__0left=f0.l_node;
  }
  bbDBStmt(1536002);
  this->m_InsertFixup(f0.l_node);
  bbDBStmt(1544194);
  return true;
}

void t_std_collections_Map_1TbbInt_2i::m_RotateRight(t_std_collections_Map_1TbbInt_2i_Node* l_node){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1TbbInt_2i_Node* l_child{};
    void gcMark(){
      bbGCMarkPtr(l_child);
    }
  }f0{};
  bbDBFrame db_f{"RotateRight:Void(node:std.collections.Map<mojo.input.Key,Int>.Node)","/Users/simon/monkey2/modules/std/collections/map.monkey2"};
  t_std_collections_Map_1TbbInt_2i*self=this;
  bbDBLocal("Self",&self);
  bbDBLocal("node",&l_node);
  bbDBStmt(2351112);
  f0.l_child=l_node->m__0left;
  bbDBLocal("child",&f0.l_child);
  bbDBStmt(2355202);
  l_node->m__0left=f0.l_child->m__0right;
  bbDBStmt(2359298);
  if(bbBool(f0.l_child->m__0right)){
    bbDBBlock db_blk;
    bbDBStmt(2363395);
    f0.l_child->m__0right->m__0parent=l_node;
  }
  bbDBStmt(2371586);
  f0.l_child->m__0parent=l_node->m__0parent;
  bbDBStmt(2375682);
  if(bbBool(l_node->m__0parent)){
    bbDBBlock db_blk;
    bbDBStmt(2379779);
    if((l_node==l_node->m__0parent->m__0right)){
      bbDBBlock db_blk;
      bbDBStmt(2383876);
      l_node->m__0parent->m__0right=f0.l_child;
    }else{
      bbDBStmt(2387971);
      bbDBBlock db_blk;
      bbDBStmt(2392068);
      l_node->m__0parent->m__0left=f0.l_child;
    }
  }else{
    bbDBStmt(2400258);
    bbDBBlock db_blk;
    bbDBStmt(2404355);
    this->m__0root=f0.l_child;
  }
  bbDBStmt(2412546);
  f0.l_child->m__0right=l_node;
  bbDBStmt(2416642);
  l_node->m__0parent=f0.l_child;
}

void t_std_collections_Map_1TbbInt_2i::m_RotateLeft(t_std_collections_Map_1TbbInt_2i_Node* l_node){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1TbbInt_2i_Node* l_child{};
    void gcMark(){
      bbGCMarkPtr(l_child);
    }
  }f0{};
  bbDBFrame db_f{"RotateLeft:Void(node:std.collections.Map<mojo.input.Key,Int>.Node)","/Users/simon/monkey2/modules/std/collections/map.monkey2"};
  t_std_collections_Map_1TbbInt_2i*self=this;
  bbDBLocal("Self",&self);
  bbDBLocal("node",&l_node);
  bbDBStmt(2269192);
  f0.l_child=l_node->m__0right;
  bbDBLocal("child",&f0.l_child);
  bbDBStmt(2273282);
  l_node->m__0right=f0.l_child->m__0left;
  bbDBStmt(2277378);
  if(bbBool(f0.l_child->m__0left)){
    bbDBBlock db_blk;
    bbDBStmt(2281475);
    f0.l_child->m__0left->m__0parent=l_node;
  }
  bbDBStmt(2289666);
  f0.l_child->m__0parent=l_node->m__0parent;
  bbDBStmt(2293762);
  if(bbBool(l_node->m__0parent)){
    bbDBBlock db_blk;
    bbDBStmt(2297859);
    if((l_node==l_node->m__0parent->m__0left)){
      bbDBBlock db_blk;
      bbDBStmt(2301956);
      l_node->m__0parent->m__0left=f0.l_child;
    }else{
      bbDBStmt(2306051);
      bbDBBlock db_blk;
      bbDBStmt(2310148);
      l_node->m__0parent->m__0right=f0.l_child;
    }
  }else{
    bbDBStmt(2318338);
    bbDBBlock db_blk;
    bbDBStmt(2322435);
    this->m__0root=f0.l_child;
  }
  bbDBStmt(2330626);
  f0.l_child->m__0left=l_node;
  bbDBStmt(2334722);
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
  bbDBFrame db_f{"RemoveNode:Void(node:std.collections.Map<mojo.input.Key,Int>.Node)","/Users/simon/monkey2/modules/std/collections/map.monkey2"};
  t_std_collections_Map_1TbbInt_2i*self=this;
  bbDBLocal("Self",&self);
  bbDBLocal("node",&l_node);
  bbDBStmt(2101256);
  bbDBLocal("splice",&f0.l_splice);
  bbDBStmt(2101268);
  bbDBLocal("child",&f0.l_child);
  bbDBStmt(2109442);
  if(!bbBool(l_node->m__0left)){
    bbDBBlock db_blk;
    bbDBStmt(2113539);
    f0.l_splice=l_node;
    bbDBStmt(2117635);
    f0.l_child=l_node->m__0right;
  }else if(bbDBStmt(2121730),!bbBool(l_node->m__0right)){
    bbDBBlock db_blk;
    bbDBStmt(2125827);
    f0.l_splice=l_node;
    bbDBStmt(2129923);
    f0.l_child=l_node->m__0left;
  }else{
    bbDBStmt(2134018);
    bbDBBlock db_blk;
    bbDBStmt(2138115);
    f0.l_splice=l_node->m__0left;
    bbDBStmt(2142211);
    {
      bbDBLoop db_loop;
      while(bbBool(f0.l_splice->m__0right)){
        bbDBBlock db_blk;
        bbDBStmt(2146308);
        f0.l_splice=f0.l_splice->m__0right;
      }
    }
    bbDBStmt(2154499);
    f0.l_child=f0.l_splice->m__0left;
    bbDBStmt(2158595);
    l_node->m__0key=f0.l_splice->m__0key;
    bbDBStmt(2162691);
    l_node->m__0value=f0.l_splice->m__0value;
  }
  bbDBStmt(2174984);
  f0.l_parent=f0.l_splice->m__0parent;
  bbDBLocal("parent",&f0.l_parent);
  bbDBStmt(2183170);
  if(bbBool(f0.l_child)){
    bbDBBlock db_blk;
    bbDBStmt(2187267);
    f0.l_child->m__0parent=f0.l_parent;
  }
  bbDBStmt(2199554);
  if(!bbBool(f0.l_parent)){
    bbDBBlock db_blk;
    bbDBStmt(2203651);
    this->m__0root=f0.l_child;
    bbDBStmt(2207747);
    return;
  }
  bbDBStmt(2220034);
  if((f0.l_splice==f0.l_parent->m__0left)){
    bbDBBlock db_blk;
    bbDBStmt(2224131);
    f0.l_parent->m__0left=f0.l_child;
  }else{
    bbDBStmt(2228226);
    bbDBBlock db_blk;
    bbDBStmt(2232323);
    f0.l_parent->m__0right=f0.l_child;
  }
  bbDBStmt(2244610);
  if((f0.l_splice->m__0color==1)){
    bbDBBlock db_blk;
    bbDBStmt(2248707);
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
  bbDBFrame db_f{"Remove:Bool(key:mojo.input.Key)","/Users/simon/monkey2/modules/std/collections/map.monkey2"};
  t_std_collections_Map_1TbbInt_2i*self=this;
  bbDBLocal("Self",&self);
  bbDBLocal("key",&l_key);
  bbDBStmt(1896456);
  f0.l_node=this->m_FindNode(l_key);
  bbDBLocal("node",&f0.l_node);
  bbDBStmt(1900546);
  if(!bbBool(f0.l_node)){
    bbDBBlock db_blk;
    bbDBStmt(1900558);
    return false;
  }
  bbDBStmt(1904642);
  this->m_RemoveNode(f0.l_node);
  bbDBStmt(1908738);
  return true;
}

t_std_collections_Map_1TbbInt_2i_Node* t_std_collections_Map_1TbbInt_2i::m_LastNode(){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1TbbInt_2i_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  bbDBFrame db_f{"LastNode:std.collections.Map<mojo.input.Key,Int>.Node()","/Users/simon/monkey2/modules/std/collections/map.monkey2"};
  t_std_collections_Map_1TbbInt_2i*self=this;
  bbDBLocal("Self",&self);
  bbDBStmt(1998850);
  if(!bbBool(this->m__0root)){
    bbDBBlock db_blk;
    bbDBStmt(1998863);
    return ((t_std_collections_Map_1TbbInt_2i_Node*)0);
  }
  bbDBStmt(2007048);
  f0.l_node=this->m__0root;
  bbDBLocal("node",&f0.l_node);
  bbDBStmt(2011138);
  {
    bbDBLoop db_loop;
    while(bbBool(f0.l_node->m__0right)){
      bbDBBlock db_blk;
      bbDBStmt(2015235);
      f0.l_node=f0.l_node->m__0right;
    }
  }
  bbDBStmt(2023426);
  return f0.l_node;
}

t_std_collections_Map_1TbbInt_2i_MapKeys t_std_collections_Map_1TbbInt_2i::m_Keys(){
  bbDBFrame db_f{"Keys:std.collections.Map<mojo.input.Key,Int>.MapKeys()","/Users/simon/monkey2/modules/std/collections/map.monkey2"};
  t_std_collections_Map_1TbbInt_2i*self=this;
  bbDBLocal("Self",&self);
  bbDBStmt(999426);
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
  bbDBFrame db_f{"InsertFixup:Void(node:std.collections.Map<mojo.input.Key,Int>.Node)","/Users/simon/monkey2/modules/std/collections/map.monkey2"};
  t_std_collections_Map_1TbbInt_2i*self=this;
  bbDBLocal("Self",&self);
  bbDBLocal("node",&f0.l_node);
  bbDBStmt(2433026);
  {
    bbDBLoop db_loop;
    while(((bbBool(f0.l_node->m__0parent)&&(f0.l_node->m__0parent->m__0color==0))&&bbBool(f0.l_node->m__0parent->m__0parent))){
      bbDBBlock db_blk;
      bbDBStmt(2437123);
      if((f0.l_node->m__0parent==f0.l_node->m__0parent->m__0parent->m__0left)){
        struct f2_t : public bbGCFrame{
          t_std_collections_Map_1TbbInt_2i_Node* l_uncle{};
          void gcMark(){
            bbGCMarkPtr(l_uncle);
          }
        }f2{};
        bbDBBlock db_blk;
        bbDBStmt(2441226);
        f2.l_uncle=f0.l_node->m__0parent->m__0parent->m__0right;
        bbDBLocal("uncle",&f2.l_uncle);
        bbDBStmt(2445316);
        if((bbBool(f2.l_uncle)&&(f2.l_uncle->m__0color==0))){
          bbDBBlock db_blk;
          bbDBStmt(2449413);
          f0.l_node->m__0parent->m__0color=1;
          bbDBStmt(2453509);
          f2.l_uncle->m__0color=1;
          bbDBStmt(2457605);
          f2.l_uncle->m__0parent->m__0color=0;
          bbDBStmt(2461701);
          f0.l_node=f2.l_uncle->m__0parent;
        }else{
          bbDBStmt(2465796);
          bbDBBlock db_blk;
          bbDBStmt(2469893);
          if((f0.l_node==f0.l_node->m__0parent->m__0right)){
            bbDBBlock db_blk;
            bbDBStmt(2473990);
            f0.l_node=f0.l_node->m__0parent;
            bbDBStmt(2478086);
            this->m_RotateLeft(f0.l_node);
          }
          bbDBStmt(2486277);
          f0.l_node->m__0parent->m__0color=1;
          bbDBStmt(2490373);
          f0.l_node->m__0parent->m__0parent->m__0color=0;
          bbDBStmt(2494469);
          this->m_RotateRight(f0.l_node->m__0parent->m__0parent);
        }
      }else{
        bbDBStmt(2502659);
        struct f2_t : public bbGCFrame{
          t_std_collections_Map_1TbbInt_2i_Node* l_uncle{};
          void gcMark(){
            bbGCMarkPtr(l_uncle);
          }
        }f2{};
        bbDBBlock db_blk;
        bbDBStmt(2506762);
        f2.l_uncle=f0.l_node->m__0parent->m__0parent->m__0left;
        bbDBLocal("uncle",&f2.l_uncle);
        bbDBStmt(2510852);
        if((bbBool(f2.l_uncle)&&(f2.l_uncle->m__0color==0))){
          bbDBBlock db_blk;
          bbDBStmt(2514949);
          f0.l_node->m__0parent->m__0color=1;
          bbDBStmt(2519045);
          f2.l_uncle->m__0color=1;
          bbDBStmt(2523141);
          f2.l_uncle->m__0parent->m__0color=0;
          bbDBStmt(2527237);
          f0.l_node=f2.l_uncle->m__0parent;
        }else{
          bbDBStmt(2531332);
          bbDBBlock db_blk;
          bbDBStmt(2535429);
          if((f0.l_node==f0.l_node->m__0parent->m__0left)){
            bbDBBlock db_blk;
            bbDBStmt(2539526);
            f0.l_node=f0.l_node->m__0parent;
            bbDBStmt(2543622);
            this->m_RotateRight(f0.l_node);
          }
          bbDBStmt(2551813);
          f0.l_node->m__0parent->m__0color=1;
          bbDBStmt(2555909);
          f0.l_node->m__0parent->m__0parent->m__0color=0;
          bbDBStmt(2560005);
          this->m_RotateLeft(f0.l_node->m__0parent->m__0parent);
        }
      }
    }
  }
  bbDBStmt(2576386);
  this->m__0root->m__0color=1;
}

bbInt t_std_collections_Map_1TbbInt_2i::m_Get(bbInt l_key){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1TbbInt_2i_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  bbDBFrame db_f{"Get:Int(key:mojo.input.Key)","/Users/simon/monkey2/modules/std/collections/map.monkey2"};
  t_std_collections_Map_1TbbInt_2i*self=this;
  bbDBLocal("Self",&self);
  bbDBLocal("key",&l_key);
  bbDBStmt(1843208);
  f0.l_node=this->m_FindNode(l_key);
  bbDBLocal("node",&f0.l_node);
  bbDBStmt(1847298);
  if(bbBool(f0.l_node)){
    bbDBBlock db_blk;
    bbDBStmt(1847306);
    return f0.l_node->m__0value;
  }
  bbDBStmt(1851394);
  return 0;
}

t_std_collections_Map_1TbbInt_2i_Node* t_std_collections_Map_1TbbInt_2i::m_FirstNode(){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1TbbInt_2i_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  bbDBFrame db_f{"FirstNode:std.collections.Map<mojo.input.Key,Int>.Node()","/Users/simon/monkey2/modules/std/collections/map.monkey2"};
  t_std_collections_Map_1TbbInt_2i*self=this;
  bbDBLocal("Self",&self);
  bbDBStmt(1957890);
  if(!bbBool(this->m__0root)){
    bbDBBlock db_blk;
    bbDBStmt(1957903);
    return ((t_std_collections_Map_1TbbInt_2i_Node*)0);
  }
  bbDBStmt(1966088);
  f0.l_node=this->m__0root;
  bbDBLocal("node",&f0.l_node);
  bbDBStmt(1970178);
  {
    bbDBLoop db_loop;
    while(bbBool(f0.l_node->m__0left)){
      bbDBBlock db_blk;
      bbDBStmt(1974275);
      f0.l_node=f0.l_node->m__0left;
    }
  }
  bbDBStmt(1982466);
  return f0.l_node;
}

t_std_collections_Map_1TbbInt_2i_Node* t_std_collections_Map_1TbbInt_2i::m_FindNode(bbInt l_key){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1TbbInt_2i_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  bbDBFrame db_f{"FindNode:std.collections.Map<mojo.input.Key,Int>.Node(key:mojo.input.Key)","/Users/simon/monkey2/modules/std/collections/map.monkey2"};
  t_std_collections_Map_1TbbInt_2i*self=this;
  bbDBLocal("Self",&self);
  bbDBLocal("key",&l_key);
  bbDBStmt(2039816);
  f0.l_node=this->m__0root;
  bbDBLocal("node",&f0.l_node);
  bbDBStmt(2043906);
  {
    bbDBLoop db_loop;
    while(bbBool(f0.l_node)){
      bbDBBlock db_blk;
      bbDBStmt(2048009);
      bbInt l_cmp=bbCompare(l_key,f0.l_node->m__0key);
      bbDBLocal("cmp",&l_cmp);
      bbDBStmt(2052099);
      if((l_cmp>bbInt(0))){
        bbDBBlock db_blk;
        bbDBStmt(2056196);
        f0.l_node=f0.l_node->m__0right;
      }else if(bbDBStmt(2060291),(l_cmp<bbInt(0))){
        bbDBBlock db_blk;
        bbDBStmt(2064388);
        f0.l_node=f0.l_node->m__0left;
      }else{
        bbDBStmt(2068483);
        bbDBBlock db_blk;
        bbDBStmt(2072580);
        return f0.l_node;
      }
    }
  }
  bbDBStmt(2084866);
  return ((t_std_collections_Map_1TbbInt_2i_Node*)0);
}

bbBool t_std_collections_Map_1TbbInt_2i::m_Empty(){
  bbDBFrame db_f{"Empty:Bool()","/Users/simon/monkey2/modules/std/collections/map.monkey2"};
  t_std_collections_Map_1TbbInt_2i*self=this;
  bbDBLocal("Self",&self);
  bbDBStmt(1191938);
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
  bbDBFrame db_f{"DeleteFixup:Void(node:std.collections.Map<mojo.input.Key,Int>.Node,parent:std.collections.Map<mojo.input.Key,Int>.Node)","/Users/simon/monkey2/modules/std/collections/map.monkey2"};
  t_std_collections_Map_1TbbInt_2i*self=this;
  bbDBLocal("Self",&self);
  bbDBLocal("node",&f0.l_node);
  bbDBLocal("parent",&f0.l_parent);
  bbDBStmt(2596866);
  {
    bbDBLoop db_loop;
    while(((f0.l_node!=this->m__0root)&&(!bbBool(f0.l_node)||(f0.l_node->m__0color==1)))){
      bbDBBlock db_blk;
      bbDBStmt(2605059);
      if((f0.l_node==f0.l_parent->m__0left)){
        struct f2_t : public bbGCFrame{
          t_std_collections_Map_1TbbInt_2i_Node* l_sib{};
          void gcMark(){
            bbGCMarkPtr(l_sib);
          }
        }f2{};
        bbDBBlock db_blk;
        bbDBStmt(2613258);
        f2.l_sib=f0.l_parent->m__0right;
        bbDBLocal("sib",&f2.l_sib);
        bbDBStmt(2621444);
        if((f2.l_sib->m__0color==0)){
          bbDBBlock db_blk;
          bbDBStmt(2625541);
          f2.l_sib->m__0color=1;
          bbDBStmt(2629637);
          f0.l_parent->m__0color=0;
          bbDBStmt(2633733);
          this->m_RotateLeft(f0.l_parent);
          bbDBStmt(2637829);
          f2.l_sib=f0.l_parent->m__0right;
        }
        bbDBStmt(2650116);
        if(((!bbBool(f2.l_sib->m__0left)||(f2.l_sib->m__0left->m__0color==1))&&(!bbBool(f2.l_sib->m__0right)||(f2.l_sib->m__0right->m__0color==1)))){
          bbDBBlock db_blk;
          bbDBStmt(2654213);
          f2.l_sib->m__0color=0;
          bbDBStmt(2658309);
          f0.l_node=f0.l_parent;
          bbDBStmt(2662405);
          f0.l_parent=f0.l_parent->m__0parent;
        }else{
          bbDBStmt(2666500);
          bbDBBlock db_blk;
          bbDBStmt(2670597);
          if((!bbBool(f2.l_sib->m__0right)||(f2.l_sib->m__0right->m__0color==1))){
            bbDBBlock db_blk;
            bbDBStmt(2674694);
            f2.l_sib->m__0left->m__0color=1;
            bbDBStmt(2678790);
            f2.l_sib->m__0color=0;
            bbDBStmt(2682886);
            this->m_RotateRight(f2.l_sib);
            bbDBStmt(2686982);
            f2.l_sib=f0.l_parent->m__0right;
          }
          bbDBStmt(2695173);
          f2.l_sib->m__0color=f0.l_parent->m__0color;
          bbDBStmt(2699269);
          f0.l_parent->m__0color=1;
          bbDBStmt(2703365);
          f2.l_sib->m__0right->m__0color=1;
          bbDBStmt(2707461);
          this->m_RotateLeft(f0.l_parent);
          bbDBStmt(2711557);
          f0.l_node=this->m__0root;
        }
      }else{
        bbDBStmt(2719747);
        struct f2_t : public bbGCFrame{
          t_std_collections_Map_1TbbInt_2i_Node* l_sib{};
          void gcMark(){
            bbGCMarkPtr(l_sib);
          }
        }f2{};
        bbDBBlock db_blk;
        bbDBStmt(2723850);
        f2.l_sib=f0.l_parent->m__0left;
        bbDBLocal("sib",&f2.l_sib);
        bbDBStmt(2732036);
        if((f2.l_sib->m__0color==0)){
          bbDBBlock db_blk;
          bbDBStmt(2736133);
          f2.l_sib->m__0color=1;
          bbDBStmt(2740229);
          f0.l_parent->m__0color=0;
          bbDBStmt(2744325);
          this->m_RotateRight(f0.l_parent);
          bbDBStmt(2748421);
          f2.l_sib=f0.l_parent->m__0left;
        }
        bbDBStmt(2760708);
        if(((!bbBool(f2.l_sib->m__0right)||(f2.l_sib->m__0right->m__0color==1))&&(!bbBool(f2.l_sib->m__0left)||(f2.l_sib->m__0left->m__0color==1)))){
          bbDBBlock db_blk;
          bbDBStmt(2764805);
          f2.l_sib->m__0color=0;
          bbDBStmt(2768901);
          f0.l_node=f0.l_parent;
          bbDBStmt(2772997);
          f0.l_parent=f0.l_parent->m__0parent;
        }else{
          bbDBStmt(2777092);
          bbDBBlock db_blk;
          bbDBStmt(2781189);
          if((!bbBool(f2.l_sib->m__0left)||(f2.l_sib->m__0left->m__0color==1))){
            bbDBBlock db_blk;
            bbDBStmt(2785286);
            f2.l_sib->m__0right->m__0color=1;
            bbDBStmt(2789382);
            f2.l_sib->m__0color=0;
            bbDBStmt(2793478);
            this->m_RotateLeft(f2.l_sib);
            bbDBStmt(2797574);
            f2.l_sib=f0.l_parent->m__0left;
          }
          bbDBStmt(2805765);
          f2.l_sib->m__0color=f0.l_parent->m__0color;
          bbDBStmt(2809861);
          f0.l_parent->m__0color=1;
          bbDBStmt(2813957);
          f2.l_sib->m__0left->m__0color=1;
          bbDBStmt(2818053);
          this->m_RotateRight(f0.l_parent);
          bbDBStmt(2822149);
          f0.l_node=this->m__0root;
        }
      }
    }
  }
  bbDBStmt(2838530);
  if(bbBool(f0.l_node)){
    bbDBBlock db_blk;
    bbDBStmt(2838538);
    f0.l_node->m__0color=1;
  }
}

bbInt t_std_collections_Map_1TbbInt_2i::m_Count(){
  bbDBFrame db_f{"Count:Int()","/Users/simon/monkey2/modules/std/collections/map.monkey2"};
  t_std_collections_Map_1TbbInt_2i*self=this;
  bbDBLocal("Self",&self);
  bbDBStmt(1150978);
  if(!bbBool(this->m__0root)){
    bbDBBlock db_blk;
    bbDBStmt(1150991);
    return bbInt(0);
  }
  bbDBStmt(1155074);
  return this->m__0root->m_Count(bbInt(0));
}

t_std_collections_Map_1TbbInt_2i* t_std_collections_Map_1TbbInt_2i::m_Copy(){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1TbbInt_2i_Node* l_root{};
    void gcMark(){
      bbGCMarkPtr(l_root);
    }
  }f0{};
  bbDBFrame db_f{"Copy:std.collections.Map<mojo.input.Key,Int>()","/Users/simon/monkey2/modules/std/collections/map.monkey2"};
  t_std_collections_Map_1TbbInt_2i*self=this;
  bbDBLocal("Self",&self);
  bbDBStmt(1081352);
  bbDBLocal("root",&f0.l_root);
  bbDBStmt(1085442);
  if(bbBool(this->m__0root)){
    bbDBBlock db_blk;
    bbDBStmt(1085451);
    f0.l_root=this->m__0root->m_Copy(((t_std_collections_Map_1TbbInt_2i_Node*)0));
  }
  bbDBStmt(1089538);
  return bbGCNew<t_std_collections_Map_1TbbInt_2i>(f0.l_root);
}

bbBool t_std_collections_Map_1TbbInt_2i::m_Contains(bbInt l_key){
  bbDBFrame db_f{"Contains:Bool(key:mojo.input.Key)","/Users/simon/monkey2/modules/std/collections/map.monkey2"};
  t_std_collections_Map_1TbbInt_2i*self=this;
  bbDBLocal("Self",&self);
  bbDBLocal("key",&l_key);
  bbDBStmt(1236994);
  return (this->m_FindNode(l_key)!=((t_std_collections_Map_1TbbInt_2i_Node*)0));
}

void t_std_collections_Map_1TbbInt_2i::m_Clear(){
  bbDBFrame db_f{"Clear:Void()","/Users/simon/monkey2/modules/std/collections/map.monkey2"};
  t_std_collections_Map_1TbbInt_2i*self=this;
  bbDBLocal("Self",&self);
  bbDBStmt(1114114);
  this->m__0root=((t_std_collections_Map_1TbbInt_2i_Node*)0);
}

t_std_collections_Map_1TbbInt_2i_Iterator t_std_collections_Map_1TbbInt_2i::m_All(){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1TbbInt_2i_Node* t0{};
    void gcMark(){
      bbGCMarkPtr(t0);
    }
  }f0{};
  bbDBFrame db_f{"All:std.collections.Map<mojo.input.Key,Int>.Iterator()","/Users/simon/monkey2/modules/std/collections/map.monkey2"};
  t_std_collections_Map_1TbbInt_2i*self=this;
  bbDBLocal("Self",&self);
  bbDBStmt(954370);
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
  bbDBFrame db_f{"Add:Bool(key:mojo.input.Key,value:Int)","/Users/simon/monkey2/modules/std/collections/map.monkey2"};
  t_std_collections_Map_1TbbInt_2i*self=this;
  bbDBLocal("Self",&self);
  bbDBLocal("key",&l_key);
  bbDBLocal("value",&l_value);
  bbDBStmt(1613826);
  if(!bbBool(this->m__0root)){
    bbDBBlock db_blk;
    bbDBStmt(1617923);
    this->m__0root=bbGCNew<t_std_collections_Map_1TbbInt_2i_Node>(l_key,l_value,0,((t_std_collections_Map_1TbbInt_2i_Node*)0));
    bbDBStmt(1622019);
    return true;
  }
  bbDBStmt(1634312);
  f0.l_node=this->m__0root;
  bbDBLocal("node",&f0.l_node);
  bbDBStmt(1634324);
  bbDBLocal("parent",&f0.l_parent);
  bbDBStmt(1634336);
  bbInt l_cmp{};
  bbDBLocal("cmp",&l_cmp);
  bbDBStmt(1642498);
  {
    bbDBLoop db_loop;
    while(bbBool(f0.l_node)){
      bbDBBlock db_blk;
      bbDBStmt(1646595);
      f0.l_parent=f0.l_node;
      bbDBStmt(1650691);
      l_cmp=bbCompare(l_key,f0.l_node->m__0key);
      bbDBStmt(1654787);
      if((l_cmp>bbInt(0))){
        bbDBBlock db_blk;
        bbDBStmt(1658884);
        f0.l_node=f0.l_node->m__0right;
      }else if(bbDBStmt(1662979),(l_cmp<bbInt(0))){
        bbDBBlock db_blk;
        bbDBStmt(1667076);
        f0.l_node=f0.l_node->m__0left;
      }else{
        bbDBStmt(1671171);
        bbDBBlock db_blk;
        bbDBStmt(1675268);
        return false;
      }
    }
  }
  bbDBStmt(1691650);
  f0.l_node=bbGCNew<t_std_collections_Map_1TbbInt_2i_Node>(l_key,l_value,0,f0.l_parent);
  bbDBStmt(1699842);
  if((l_cmp>bbInt(0))){
    bbDBBlock db_blk;
    bbDBStmt(1699851);
    f0.l_parent->m__0right=f0.l_node;
  }else{
    bbDBStmt(1699870);
    bbDBBlock db_blk;
    bbDBStmt(1699875);
    f0.l_parent->m__0left=f0.l_node;
  }
  bbDBStmt(1708034);
  this->m_InsertFixup(f0.l_node);
  bbDBStmt(1716226);
  return true;
}
bbString bbDBType(t_std_collections_Map_1TbbInt_2i**){
  return "std.collections.Map<mojo.input.Key,Int>";
}
bbString bbDBValue(t_std_collections_Map_1TbbInt_2i**p){
  return bbDBObjectValue(*p);
}

void mx2_vsynth_std_collections_2map_init(){
  static bool done;
  if(done) return;
  done=true;
}

bbInit mx2_vsynth_std_collections_2map_init_v("vsynth_std_collections_2map",&mx2_vsynth_std_collections_2map_init);
