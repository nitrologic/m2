
#include "vsynth_std_collections_2list.h"

// ***** External *****

#include "../../../../../../monkey2/modules/monkey/monkey.buildv1.0.0/desktop_debug_macos/monkey_debug.h"
#include "vsynth_std_collections_2stack.h"
#include "vsynth_vsynth.h"

// ***** Internal *****

void g_std_collections_List_1Tt_default_Voice_2_AddAll_1Tt_std_collections_List_1Tt_default_Voice_2_2(t_std_collections_List_1Tt_default_Voice_2* l_self,t_std_collections_List_1Tt_default_Voice_2* l_values){
  bbDBFrame db_f{"AddAll<std.collections.List<default.Voice>>:Void(values:std.collections.List<default.Voice>)","/Users/simon/monkey2/modules/std/collections/list.monkey2"};
  t_std_collections_List_1Tt_default_Voice_2*self=l_self;
  bbDBLocal("Self",&self);
  bbDBLocal("values",&l_values);
  bbDBStmt(2318338);
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
      bbDBStmt(2322435);
      l_self->m_AddLast(f2.l_value);
    }
  }
}

void g_std_collections_List_1Tt_default_Voice_2_AddAll_1Tt_std_collections_Stack_1Tt_default_Voice_2_2(t_std_collections_List_1Tt_default_Voice_2* l_self,t_std_collections_Stack_1Tt_default_Voice_2* l_values){
  bbDBFrame db_f{"AddAll<std.collections.Stack<default.Voice>>:Void(values:std.collections.Stack<default.Voice>)","/Users/simon/monkey2/modules/std/collections/list.monkey2"};
  t_std_collections_List_1Tt_default_Voice_2*self=l_self;
  bbDBLocal("Self",&self);
  bbDBLocal("values",&l_values);
  bbDBStmt(2318338);
  {
    struct f1_t : public bbGCFrame{
      t_std_collections_Stack_1Tt_default_Voice_2_Iterator l_0{};
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
      bbDBStmt(2322435);
      l_self->m_AddLast(f2.l_value);
    }
  }
}

void t_std_collections_List_1Tt_default_Voice_2_Node::gcMark(){
  bbGCMark(m__0succ);
  bbGCMark(m__0pred);
  bbGCMark(m__0value);
}

void t_std_collections_List_1Tt_default_Voice_2_Node::dbEmit(){
  bbDBEmit("_succ",&m__0succ);
  bbDBEmit("_pred",&m__0pred);
  bbDBEmit("_value",&m__0value);
}

t_std_collections_List_1Tt_default_Voice_2_Node::t_std_collections_List_1Tt_default_Voice_2_Node(t_default_Voice* l_value,t_std_collections_List_1Tt_default_Voice_2_Node* l_succ){
  bbDBFrame db_f{"new:Void(value:default.Voice,succ:std.collections.List<default.Voice>.Node)","/Users/simon/monkey2/modules/std/collections/list.monkey2"};
  bbDBLocal("value",&l_value);
  bbDBLocal("succ",&l_succ);
  bbDBStmt(245763);
  this->m__0value=l_value;
  bbDBStmt(249859);
  this->m__0succ=l_succ;
  bbDBStmt(253955);
  this->m__0pred=l_succ->m__0pred;
  bbDBStmt(258051);
  this->m__0pred->m__0succ=this;
  bbDBStmt(262147);
  l_succ->m__0pred=this;
}

t_std_collections_List_1Tt_default_Voice_2_Node::t_std_collections_List_1Tt_default_Voice_2_Node(t_default_Voice* l_value){
  bbDBFrame db_f{"new:Void(value:default.Voice)","/Users/simon/monkey2/modules/std/collections/list.monkey2"};
  bbDBLocal("value",&l_value);
  bbDBStmt(192515);
  this->m__0value=l_value;
  bbDBStmt(196611);
  this->m__0succ=this;
  bbDBStmt(200707);
  this->m__0pred=this;
}

void t_std_collections_List_1Tt_default_Voice_2_Node::m_Value(t_default_Voice* l_value){
  bbDBFrame db_f{"Value:Void(value:default.Voice)","/Users/simon/monkey2/modules/std/collections/list.monkey2"};
  t_std_collections_List_1Tt_default_Voice_2_Node*self=this;
  bbDBLocal("Self",&self);
  bbDBLocal("value",&l_value);
  bbDBStmt(344067);
  this->m__0value=l_value;
}

t_default_Voice* t_std_collections_List_1Tt_default_Voice_2_Node::m_Value(){
  bbDBFrame db_f{"Value:default.Voice()","/Users/simon/monkey2/modules/std/collections/list.monkey2"};
  t_std_collections_List_1Tt_default_Voice_2_Node*self=this;
  bbDBLocal("Self",&self);
  bbDBStmt(335875);
  return this->m__0value;
}

t_std_collections_List_1Tt_default_Voice_2_Node* t_std_collections_List_1Tt_default_Voice_2_Node::m_Succ(){
  bbDBFrame db_f{"Succ:std.collections.List<default.Voice>.Node()","/Users/simon/monkey2/modules/std/collections/list.monkey2"};
  t_std_collections_List_1Tt_default_Voice_2_Node*self=this;
  bbDBLocal("Self",&self);
  bbDBStmt(286723);
  return this->m__0succ;
}

void t_std_collections_List_1Tt_default_Voice_2_Node::m_Remove(){
  bbDBFrame db_f{"Remove:Void()","/Users/simon/monkey2/modules/std/collections/list.monkey2"};
  t_std_collections_List_1Tt_default_Voice_2_Node*self=this;
  bbDBLocal("Self",&self);
  bbDBStmt(503811);
  this->m__0succ->m__0pred=this->m__0pred;
  bbDBStmt(507907);
  this->m__0pred->m__0succ=this->m__0succ;
}

t_std_collections_List_1Tt_default_Voice_2_Node* t_std_collections_List_1Tt_default_Voice_2_Node::m_Pred(){
  bbDBFrame db_f{"Pred:std.collections.List<default.Voice>.Node()","/Users/simon/monkey2/modules/std/collections/list.monkey2"};
  t_std_collections_List_1Tt_default_Voice_2_Node*self=this;
  bbDBLocal("Self",&self);
  bbDBStmt(311299);
  return this->m__0pred;
}

void t_std_collections_List_1Tt_default_Voice_2_Node::m_InsertBefore(t_std_collections_List_1Tt_default_Voice_2_Node* l_node){
  bbDBFrame db_f{"InsertBefore:Void(node:std.collections.List<default.Voice>.Node)","/Users/simon/monkey2/modules/std/collections/list.monkey2"};
  t_std_collections_List_1Tt_default_Voice_2_Node*self=this;
  bbDBLocal("Self",&self);
  bbDBLocal("node",&l_node);
  bbDBStmt(389123);
  this->m__0succ=l_node;
  bbDBStmt(393219);
  this->m__0pred=l_node->m__0pred;
  bbDBStmt(397315);
  this->m__0pred->m__0succ=this;
  bbDBStmt(401411);
  l_node->m__0pred=this;
}

void t_std_collections_List_1Tt_default_Voice_2_Node::m_InsertAfter(t_std_collections_List_1Tt_default_Voice_2_Node* l_node){
  bbDBFrame db_f{"InsertAfter:Void(node:std.collections.List<default.Voice>.Node)","/Users/simon/monkey2/modules/std/collections/list.monkey2"};
  t_std_collections_List_1Tt_default_Voice_2_Node*self=this;
  bbDBLocal("Self",&self);
  bbDBLocal("node",&l_node);
  bbDBStmt(446467);
  this->m__0pred=l_node;
  bbDBStmt(450563);
  this->m__0succ=l_node->m__0succ;
  bbDBStmt(454659);
  this->m__0succ->m__0pred=this;
  bbDBStmt(458755);
  l_node->m__0succ=this;
}
bbString bbDBType(t_std_collections_List_1Tt_default_Voice_2_Node**){
  return "std.collections.List<default.Voice>.Node";
}
bbString bbDBValue(t_std_collections_List_1Tt_default_Voice_2_Node**p){
  return bbDBObjectValue(*p);
}

void t_std_collections_List_1Tt_default_Voice_2_Iterator::dbEmit(t_std_collections_List_1Tt_default_Voice_2_Iterator*p){
  bbDBEmit("_list",&p->m__0list);
  bbDBEmit("_node",&p->m__0node);
  bbDBEmit("_seq",&p->m__0seq);
}

t_std_collections_List_1Tt_default_Voice_2_Iterator::t_std_collections_List_1Tt_default_Voice_2_Iterator(t_std_collections_List_1Tt_default_Voice_2* l_list,t_std_collections_List_1Tt_default_Voice_2_Node* l_node){
  bbDBFrame db_f{"new:Void(list:std.collections.List<default.Voice>,node:std.collections.List<default.Voice>.Node)","/Users/simon/monkey2/modules/std/collections/list.monkey2"};
  bbDBLocal("list",&l_list);
  bbDBLocal("node",&l_node);
  bbDBStmt(622595);
  (*this).m__0list=l_list;
  bbDBStmt(626691);
  (*this).m__0node=l_node;
  bbDBStmt(630787);
  (*this).m__0seq=l_list->m__0seq;
}

void t_std_collections_List_1Tt_default_Voice_2_Iterator::m_Insert(t_default_Voice* l_value){
  bbDBFrame db_f{"Insert:Void(value:default.Voice)","/Users/simon/monkey2/modules/std/collections/list.monkey2"};
  t_std_collections_List_1Tt_default_Voice_2_Iterator*self=&(*this);
  bbDBLocal("Self",self);
  bbDBLocal("value",&l_value);
  bbDBStmt(835587);
  (*this).m_AssertSeq();
  bbDBStmt(839683);
  (*this).m__0node=bbGCNew<t_std_collections_List_1Tt_default_Voice_2_Node>(l_value,(*this).m__0node);
  bbDBStmt(843779);
  (*this).m__0list->m__0seq+=1;
  bbDBStmt(847875);
  (*this).m__0seq=(*this).m__0list->m__0seq;
}

void t_std_collections_List_1Tt_default_Voice_2_Iterator::m_Erase(){
  bbDBFrame db_f{"Erase:Void()","/Users/simon/monkey2/modules/std/collections/list.monkey2"};
  t_std_collections_List_1Tt_default_Voice_2_Iterator*self=&(*this);
  bbDBLocal("Self",self);
  bbDBStmt(782339);
  (*this).m_AssertCurrent();
  bbDBStmt(786435);
  (*this).m__0node=(*this).m__0node->m__0succ;
  bbDBStmt(790531);
  (*this).m__0node->m__0pred->m_Remove();
  bbDBStmt(794627);
  (*this).m__0list->m__0seq+=1;
  bbDBStmt(798723);
  (*this).m__0seq=(*this).m__0list->m__0seq;
}

void t_std_collections_List_1Tt_default_Voice_2_Iterator::m_Current(t_default_Voice* l_current){
  bbDBFrame db_f{"Current:Void(current:default.Voice)","/Users/simon/monkey2/modules/std/collections/list.monkey2"};
  t_std_collections_List_1Tt_default_Voice_2_Iterator*self=&(*this);
  bbDBLocal("Self",self);
  bbDBLocal("current",&l_current);
  bbDBStmt(700419);
  (*this).m_AssertCurrent();
  bbDBStmt(704515);
  (*this).m__0node->m__0value=l_current;
}

t_default_Voice* t_std_collections_List_1Tt_default_Voice_2_Iterator::m_Current(){
  bbDBFrame db_f{"Current:default.Voice()","/Users/simon/monkey2/modules/std/collections/list.monkey2"};
  t_std_collections_List_1Tt_default_Voice_2_Iterator*self=&(*this);
  bbDBLocal("Self",self);
  bbDBStmt(684035);
  (*this).m_AssertCurrent();
  bbDBStmt(688131);
  return (*this).m__0node->m__0value;
}

void t_std_collections_List_1Tt_default_Voice_2_Iterator::m_Bump(){
  bbDBFrame db_f{"Bump:Void()","/Users/simon/monkey2/modules/std/collections/list.monkey2"};
  t_std_collections_List_1Tt_default_Voice_2_Iterator*self=&(*this);
  bbDBLocal("Self",self);
  bbDBStmt(729091);
  (*this).m_AssertCurrent();
  bbDBStmt(733187);
  (*this).m__0node=(*this).m__0node->m__0succ;
}

bbBool t_std_collections_List_1Tt_default_Voice_2_Iterator::m_AtEnd(){
  bbDBFrame db_f{"AtEnd:Bool()","/Users/simon/monkey2/modules/std/collections/list.monkey2"};
  t_std_collections_List_1Tt_default_Voice_2_Iterator*self=&(*this);
  bbDBLocal("Self",self);
  bbDBStmt(655363);
  (*this).m_AssertSeq();
  bbDBStmt(659459);
  return ((*this).m__0node==(*this).m__0list->m__0head);
}

void t_std_collections_List_1Tt_default_Voice_2_Iterator::m_AssertSeq(){
  bbDBFrame db_f{"AssertSeq:Void()","/Users/simon/monkey2/modules/std/collections/list.monkey2"};
  t_std_collections_List_1Tt_default_Voice_2_Iterator*self=&(*this);
  bbDBLocal("Self",self);
  bbDBStmt(573443);
  bbDebugAssert(((*this).m__0seq==(*this).m__0list->m__0seq),BB_T("Concurrent list modification"));
}

void t_std_collections_List_1Tt_default_Voice_2_Iterator::m_AssertCurrent(){
  bbDBFrame db_f{"AssertCurrent:Void()","/Users/simon/monkey2/modules/std/collections/list.monkey2"};
  t_std_collections_List_1Tt_default_Voice_2_Iterator*self=&(*this);
  bbDBLocal("Self",self);
  bbDBStmt(589827);
  bbDebugAssert(!(*this).m_AtEnd(),BB_T("Invalid list iterator"));
}
bbString bbDBType(t_std_collections_List_1Tt_default_Voice_2_Iterator*){
  return "std.collections.List<default.Voice>.Iterator";
}
bbString bbDBValue(t_std_collections_List_1Tt_default_Voice_2_Iterator*p){
  return bbDBStructValue(p);
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

void t_std_collections_List_1Tt_default_Voice_2_BackwardsIterator::dbEmit(t_std_collections_List_1Tt_default_Voice_2_BackwardsIterator*p){
  bbDBEmit("_list",&p->m__0list);
  bbDBEmit("_node",&p->m__0node);
  bbDBEmit("_seq",&p->m__0seq);
}

t_std_collections_List_1Tt_default_Voice_2_BackwardsIterator::t_std_collections_List_1Tt_default_Voice_2_BackwardsIterator(t_std_collections_List_1Tt_default_Voice_2* l_list,t_std_collections_List_1Tt_default_Voice_2_Node* l_node){
  bbDBFrame db_f{"new:Void(list:std.collections.List<default.Voice>,node:std.collections.List<default.Voice>.Node)","/Users/simon/monkey2/modules/std/collections/list.monkey2"};
  bbDBLocal("list",&l_list);
  bbDBLocal("node",&l_node);
  bbDBStmt(958467);
  (*this).m__0list=l_list;
  bbDBStmt(962563);
  (*this).m__0node=l_node;
  bbDBStmt(966659);
  (*this).m__0seq=l_list->m__0seq;
}

void t_std_collections_List_1Tt_default_Voice_2_BackwardsIterator::m_Insert(t_default_Voice* l_value){
  bbDBFrame db_f{"Insert:Void(value:default.Voice)","/Users/simon/monkey2/modules/std/collections/list.monkey2"};
  t_std_collections_List_1Tt_default_Voice_2_BackwardsIterator*self=&(*this);
  bbDBLocal("Self",self);
  bbDBLocal("value",&l_value);
  bbDBStmt(1171459);
  (*this).m_AssertSeq();
  bbDBStmt(1175555);
  (*this).m__0node=bbGCNew<t_std_collections_List_1Tt_default_Voice_2_Node>(l_value,(*this).m__0node->m__0succ);
  bbDBStmt(1179651);
  (*this).m__0list->m__0seq+=1;
  bbDBStmt(1183747);
  (*this).m__0seq=(*this).m__0list->m__0seq;
}

void t_std_collections_List_1Tt_default_Voice_2_BackwardsIterator::m_Erase(){
  bbDBFrame db_f{"Erase:Void()","/Users/simon/monkey2/modules/std/collections/list.monkey2"};
  t_std_collections_List_1Tt_default_Voice_2_BackwardsIterator*self=&(*this);
  bbDBLocal("Self",self);
  bbDBStmt(1118211);
  (*this).m_AssertCurrent();
  bbDBStmt(1122307);
  (*this).m__0node=(*this).m__0node->m__0pred;
  bbDBStmt(1126403);
  (*this).m__0node->m__0succ->m_Remove();
  bbDBStmt(1130499);
  (*this).m__0list->m__0seq+=1;
  bbDBStmt(1134595);
  (*this).m__0seq=(*this).m__0list->m__0seq;
}

void t_std_collections_List_1Tt_default_Voice_2_BackwardsIterator::m_Current(t_default_Voice* l_current){
  bbDBFrame db_f{"Current:Void(current:default.Voice)","/Users/simon/monkey2/modules/std/collections/list.monkey2"};
  t_std_collections_List_1Tt_default_Voice_2_BackwardsIterator*self=&(*this);
  bbDBLocal("Self",self);
  bbDBLocal("current",&l_current);
  bbDBStmt(1036291);
  (*this).m_AssertCurrent();
  bbDBStmt(1040387);
  (*this).m__0node->m__0value=l_current;
}

t_default_Voice* t_std_collections_List_1Tt_default_Voice_2_BackwardsIterator::m_Current(){
  bbDBFrame db_f{"Current:default.Voice()","/Users/simon/monkey2/modules/std/collections/list.monkey2"};
  t_std_collections_List_1Tt_default_Voice_2_BackwardsIterator*self=&(*this);
  bbDBLocal("Self",self);
  bbDBStmt(1019907);
  (*this).m_AssertCurrent();
  bbDBStmt(1024003);
  return (*this).m__0node->m__0value;
}

void t_std_collections_List_1Tt_default_Voice_2_BackwardsIterator::m_Bump(){
  bbDBFrame db_f{"Bump:Void()","/Users/simon/monkey2/modules/std/collections/list.monkey2"};
  t_std_collections_List_1Tt_default_Voice_2_BackwardsIterator*self=&(*this);
  bbDBLocal("Self",self);
  bbDBStmt(1064963);
  (*this).m_AssertCurrent();
  bbDBStmt(1069059);
  (*this).m__0node=(*this).m__0node->m__0pred;
}

bbBool t_std_collections_List_1Tt_default_Voice_2_BackwardsIterator::m_AtEnd(){
  bbDBFrame db_f{"AtEnd:Bool()","/Users/simon/monkey2/modules/std/collections/list.monkey2"};
  t_std_collections_List_1Tt_default_Voice_2_BackwardsIterator*self=&(*this);
  bbDBLocal("Self",self);
  bbDBStmt(991235);
  (*this).m_AssertSeq();
  bbDBStmt(995331);
  return ((*this).m__0node==(*this).m__0list->m__0head);
}

void t_std_collections_List_1Tt_default_Voice_2_BackwardsIterator::m_AssertSeq(){
  bbDBFrame db_f{"AssertSeq:Void()","/Users/simon/monkey2/modules/std/collections/list.monkey2"};
  t_std_collections_List_1Tt_default_Voice_2_BackwardsIterator*self=&(*this);
  bbDBLocal("Self",self);
  bbDBStmt(909315);
  bbDebugAssert(((*this).m__0seq==(*this).m__0list->m__0seq),BB_T("Concurrent list modification"));
}

void t_std_collections_List_1Tt_default_Voice_2_BackwardsIterator::m_AssertCurrent(){
  bbDBFrame db_f{"AssertCurrent:Void()","/Users/simon/monkey2/modules/std/collections/list.monkey2"};
  t_std_collections_List_1Tt_default_Voice_2_BackwardsIterator*self=&(*this);
  bbDBLocal("Self",self);
  bbDBStmt(925699);
  bbDebugAssert(!(*this).m_AtEnd(),BB_T("Invalid list iterator"));
}
bbString bbDBType(t_std_collections_List_1Tt_default_Voice_2_BackwardsIterator*){
  return "std.collections.List<default.Voice>.BackwardsIterator";
}
bbString bbDBValue(t_std_collections_List_1Tt_default_Voice_2_BackwardsIterator*p){
  return bbDBStructValue(p);
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

void t_std_collections_List_1Tt_default_Voice_2::dbEmit(){
  bbDBEmit("_head",&m__0head);
  bbDBEmit("_seq",&m__0seq);
}

t_std_collections_List_1Tt_default_Voice_2::t_std_collections_List_1Tt_default_Voice_2(t_std_collections_List_1Tt_default_Voice_2* l_values):t_std_collections_List_1Tt_default_Voice_2(){
  bbDBFrame db_f{"new:Void(values:std.collections.List<default.Voice>)","/Users/simon/monkey2/modules/std/collections/list.monkey2"};
  bbDBLocal("values",&l_values);
  bbDBStmt(1351682);
  g_std_collections_List_1Tt_default_Voice_2_AddAll_1Tt_std_collections_List_1Tt_default_Voice_2_2(this,l_values);
}

t_std_collections_List_1Tt_default_Voice_2::t_std_collections_List_1Tt_default_Voice_2(t_std_collections_Stack_1Tt_default_Voice_2* l_values):t_std_collections_List_1Tt_default_Voice_2(){
  bbDBFrame db_f{"new:Void(values:std.collections.Stack<default.Voice>)","/Users/simon/monkey2/modules/std/collections/list.monkey2"};
  bbDBLocal("values",&l_values);
  bbDBStmt(1331202);
  g_std_collections_List_1Tt_default_Voice_2_AddAll_1Tt_std_collections_Stack_1Tt_default_Voice_2_2(this,l_values);
}

t_std_collections_List_1Tt_default_Voice_2::t_std_collections_List_1Tt_default_Voice_2(bbArray<bbGCVar<t_default_Voice>>* l_values):t_std_collections_List_1Tt_default_Voice_2(){
  bbDBFrame db_f{"new:Void(values:default.Voice[])","/Users/simon/monkey2/modules/std/collections/list.monkey2"};
  bbDBLocal("values",&l_values);
  bbDBStmt(1310722);
  this->m_AddAll(l_values);
}

t_std_collections_List_1Tt_default_Voice_2::t_std_collections_List_1Tt_default_Voice_2(){
  bbDBFrame db_f{"new:Void()","/Users/simon/monkey2/modules/std/collections/list.monkey2"};
  bbDBStmt(1290242);
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
  bbDBFrame db_f{"ToArray:default.Voice[]()","/Users/simon/monkey2/modules/std/collections/list.monkey2"};
  t_std_collections_List_1Tt_default_Voice_2*self=this;
  bbDBLocal("Self",&self);
  bbDBStmt(1585160);
  bbInt l_n=this->m_Count();
  bbDBLocal("n",&l_n);
  bbDBStmt(1589256);
  f0.l_data=bbArray<bbGCVar<t_default_Voice>>::create(l_n);
  bbDBLocal("data",&f0.l_data);
  bbDBStmt(1589271);
  f0.l_node=this->m__0head->m__0succ;
  bbDBLocal("node",&f0.l_node);
  bbDBStmt(1593346);
  {
    bbDBLoop db_loop;
    bbInt l_i=bbInt(0);
    bbDBLocal("i",&l_i);
    bbDBStmt(1593346);
    for(;(l_i<l_n);l_i+=1){
      bbDBBlock db_blk;
      bbDBStmt(1597443);
      f0.l_data->at(l_i)=f0.l_node->m__0value;
      bbDBStmt(1601539);
      f0.l_node=f0.l_node->m__0succ;
    }
  }
  bbDBStmt(1609730);
  return f0.l_data;
}

void t_std_collections_List_1Tt_default_Voice_2::m_Sort(bbFunction<bbInt(t_default_Voice*,t_default_Voice*)> l_compareFunc){
  bbDBFrame db_f{"Sort:Void(compareFunc:Int(default.Voice,default.Voice))","/Users/simon/monkey2/modules/std/collections/list.monkey2"};
  t_std_collections_List_1Tt_default_Voice_2*self=this;
  bbDBLocal("Self",&self);
  bbDBLocal("compareFunc",&l_compareFunc);
  bbDBStmt(2424840);
  bbInt l_insize=1;
  bbDBLocal("insize",&l_insize);
  bbDBStmt(2433026);
  {
    bbDBLoop db_loop;
    for(;;){
      struct f1_t : public bbGCFrame{
        t_std_collections_List_1Tt_default_Voice_2_Node* l_p{};
        t_std_collections_List_1Tt_default_Voice_2_Node* l_tail{};
        void gcMark(){
          bbGCMarkPtr(l_p);
          bbGCMarkPtr(l_tail);
        }
      }f1{};
      bbDBBlock db_blk;
      bbDBStmt(2441225);
      bbInt l_merges=bbInt(0);
      bbDBLocal("merges",&l_merges);
      bbDBStmt(2445321);
      f1.l_tail=this->m__0head;
      bbDBLocal("tail",&f1.l_tail);
      bbDBStmt(2449417);
      f1.l_p=this->m__0head->m__0succ;
      bbDBLocal("p",&f1.l_p);
      bbDBStmt(2457603);
      {
        bbDBLoop db_loop;
        while((f1.l_p!=this->m__0head)){
          struct f2_t : public bbGCFrame{
            t_std_collections_List_1Tt_default_Voice_2_Node* l_q{};
            void gcMark(){
              bbGCMarkPtr(l_q);
            }
          }f2{};
          bbDBBlock db_blk;
          bbDBStmt(2461700);
          l_merges+=1;
          bbDBStmt(2465802);
          f2.l_q=f1.l_p->m__0succ;
          bbDBLocal("q",&f2.l_q);
          bbDBStmt(2465813);
          bbInt l_qsize=l_insize;
          bbDBLocal("qsize",&l_qsize);
          bbDBStmt(2465827);
          bbInt l_psize=1;
          bbDBLocal("psize",&l_psize);
          bbDBStmt(2473988);
          {
            bbDBLoop db_loop;
            while(((l_psize<l_insize)&&(f2.l_q!=this->m__0head))){
              bbDBBlock db_blk;
              bbDBStmt(2478085);
              l_psize+=1;
              bbDBStmt(2482181);
              f2.l_q=f2.l_q->m__0succ;
            }
          }
          bbDBStmt(2494468);
          {
            bbDBLoop db_loop;
            for(;;){
              struct f3_t : public bbGCFrame{
                t_std_collections_List_1Tt_default_Voice_2_Node* l_t{};
                void gcMark(){
                  bbGCMarkPtr(l_t);
                }
              }f3{};
              bbDBBlock db_blk;
              bbDBStmt(2498571);
              bbDBLocal("t",&f3.l_t);
              bbDBStmt(2502661);
              if(((bbBool(l_psize)&&bbBool(l_qsize))&&(f2.l_q!=this->m__0head))){
                bbDBBlock db_blk;
                bbDBStmt(2506764);
                bbInt l_cc=l_compareFunc(f1.l_p->m__0value,f2.l_q->m__0value);
                bbDBLocal("cc",&l_cc);
                bbDBStmt(2510854);
                if((l_cc<=bbInt(0))){
                  bbDBBlock db_blk;
                  bbDBStmt(2514951);
                  f3.l_t=f1.l_p;
                  bbDBStmt(2519047);
                  f1.l_p=f1.l_p->m__0succ;
                  bbDBStmt(2523143);
                  l_psize-=1;
                }else{
                  bbDBStmt(2527238);
                  bbDBBlock db_blk;
                  bbDBStmt(2531335);
                  f3.l_t=f2.l_q;
                  bbDBStmt(2535431);
                  f2.l_q=f2.l_q->m__0succ;
                  bbDBStmt(2539527);
                  l_qsize-=1;
                }
              }else if(bbDBStmt(2547717),bbBool(l_psize)){
                bbDBBlock db_blk;
                bbDBStmt(2551814);
                f3.l_t=f1.l_p;
                bbDBStmt(2555910);
                f1.l_p=f1.l_p->m__0succ;
                bbDBStmt(2560006);
                l_psize-=1;
              }else if(bbDBStmt(2564101),(bbBool(l_qsize)&&(f2.l_q!=this->m__0head))){
                bbDBBlock db_blk;
                bbDBStmt(2568198);
                f3.l_t=f2.l_q;
                bbDBStmt(2572294);
                f2.l_q=f2.l_q->m__0succ;
                bbDBStmt(2576390);
                l_qsize-=1;
              }else{
                bbDBStmt(2580485);
                bbDBBlock db_blk;
                bbDBStmt(2584582);
                break;
              }
              bbDBStmt(2592773);
              f3.l_t->m__0pred=f1.l_tail;
              bbDBStmt(2596869);
              f1.l_tail->m__0succ=f3.l_t;
              bbDBStmt(2600965);
              f1.l_tail=f3.l_t;
            }
          }
          bbDBStmt(2609156);
          f1.l_p=f2.l_q;
        }
      }
      bbDBStmt(2617347);
      f1.l_tail->m__0succ=this->m__0head;
      bbDBStmt(2621443);
      this->m__0head->m__0pred=f1.l_tail;
      bbDBStmt(2629635);
      if((l_merges<=1)){
        bbDBBlock db_blk;
        bbDBStmt(2629648);
        return;
      }
      bbDBStmt(2637827);
      l_insize*=2;
    }
  }
}

void t_std_collections_List_1Tt_default_Voice_2::m_Sort(bbBool l_ascending){
  bbDBFrame db_f{"Sort:Void(ascending:Bool)","/Users/simon/monkey2/modules/std/collections/list.monkey2"};
  t_std_collections_List_1Tt_default_Voice_2*self=this;
  bbDBLocal("Self",&self);
  bbDBLocal("ascending",&l_ascending);
  bbDBStmt(2371586);
  if(l_ascending){
    bbDBBlock db_blk;
    bbDBStmt(2375683);
    struct lambda0 : public bbFunction<bbInt(t_default_Voice*,t_default_Voice*)>::Rep{
      t_std_collections_List_1Tt_default_Voice_2* l_self;
      lambda0(t_std_collections_List_1Tt_default_Voice_2* l_self):l_self(l_self){
      }
      bbInt invoke(t_default_Voice* l_x,t_default_Voice* l_y){
        bbDBFrame db_f{"?????:Int(x:default.Voice,y:default.Voice)","/Users/simon/monkey2/modules/std/collections/list.monkey2"};
        bbDBLocal("x",&l_x);
        bbDBLocal("y",&l_y);
        bbDBStmt(2379780);
        return bbCompare(l_x,l_y);
      }
      void gcMark(){
        bbGCMarkPtr(l_self);
      }
    };
    this->m_Sort(bbFunction<bbInt(t_default_Voice*,t_default_Voice*)>(new lambda0(this)));
  }else{
    bbDBStmt(2387970);
    bbDBBlock db_blk;
    bbDBStmt(2392067);
    struct lambda1 : public bbFunction<bbInt(t_default_Voice*,t_default_Voice*)>::Rep{
      t_std_collections_List_1Tt_default_Voice_2* l_self;
      lambda1(t_std_collections_List_1Tt_default_Voice_2* l_self):l_self(l_self){
      }
      bbInt invoke(t_default_Voice* l_x,t_default_Voice* l_y){
        bbDBFrame db_f{"?????:Int(x:default.Voice,y:default.Voice)","/Users/simon/monkey2/modules/std/collections/list.monkey2"};
        bbDBLocal("x",&l_x);
        bbDBLocal("y",&l_y);
        bbDBStmt(2396164);
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
  bbDBFrame db_f{"RemoveLast:default.Voice()","/Users/simon/monkey2/modules/std/collections/list.monkey2"};
  t_std_collections_List_1Tt_default_Voice_2*self=this;
  bbDBLocal("Self",&self);
  bbDBStmt(2183170);
  bbDebugAssert(!this->m_Empty(),BB_T("Debug assert failed"));
  bbDBStmt(2191368);
  f0.l_value=this->m__0head->m__0pred->m__0value;
  bbDBLocal("value",&f0.l_value);
  bbDBStmt(2195458);
  this->m__0head->m__0pred->m_Remove();
  bbDBStmt(2199554);
  this->m__0seq+=1;
  bbDBStmt(2203650);
  return f0.l_value;
}

bbBool t_std_collections_List_1Tt_default_Voice_2::m_RemoveLast(t_default_Voice* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_default_Voice_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  bbDBFrame db_f{"RemoveLast:Bool(value:default.Voice)","/Users/simon/monkey2/modules/std/collections/list.monkey2"};
  t_std_collections_List_1Tt_default_Voice_2*self=this;
  bbDBLocal("Self",&self);
  bbDBLocal("value",&l_value);
  bbDBStmt(1966088);
  f0.l_node=this->m_FindLastNode(l_value);
  bbDBLocal("node",&f0.l_node);
  bbDBStmt(1970178);
  if(!bbBool(f0.l_node)){
    bbDBBlock db_blk;
    bbDBStmt(1970190);
    return false;
  }
  bbDBStmt(1974274);
  f0.l_node->m_Remove();
  bbDBStmt(1978370);
  this->m__0seq+=1;
  bbDBStmt(1982466);
  return true;
}

t_default_Voice* t_std_collections_List_1Tt_default_Voice_2::m_RemoveFirst(){
  struct f0_t : public bbGCFrame{
    t_default_Voice* l_value{};
    void gcMark(){
      bbGCMarkPtr(l_value);
    }
  }f0{};
  bbDBFrame db_f{"RemoveFirst:default.Voice()","/Users/simon/monkey2/modules/std/collections/list.monkey2"};
  t_std_collections_List_1Tt_default_Voice_2*self=this;
  bbDBLocal("Self",&self);
  bbDBStmt(2117634);
  bbDebugAssert(!this->m_Empty(),BB_T("Debug assert failed"));
  bbDBStmt(2125832);
  f0.l_value=this->m__0head->m__0succ->m__0value;
  bbDBLocal("value",&f0.l_value);
  bbDBStmt(2129922);
  this->m__0head->m__0succ->m_Remove();
  bbDBStmt(2134018);
  this->m__0seq+=1;
  bbDBStmt(2138114);
  return f0.l_value;
}

bbInt t_std_collections_List_1Tt_default_Voice_2::m_RemoveEach(t_default_Voice* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_default_Voice_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  bbDBFrame db_f{"RemoveEach:Int(value:default.Voice)","/Users/simon/monkey2/modules/std/collections/list.monkey2"};
  t_std_collections_List_1Tt_default_Voice_2*self=this;
  bbDBLocal("Self",&self);
  bbDBLocal("value",&l_value);
  bbDBStmt(2027528);
  f0.l_node=this->m__0head->m__0succ;
  bbDBLocal("node",&f0.l_node);
  bbDBStmt(2027546);
  bbInt l_n=bbInt(0);
  bbDBLocal("n",&l_n);
  bbDBStmt(2031618);
  {
    bbDBLoop db_loop;
    while((f0.l_node!=this->m__0head)){
      bbDBBlock db_blk;
      bbDBStmt(2035715);
      if((f0.l_node->m__0value==l_value)){
        bbDBBlock db_blk;
        bbDBStmt(2039812);
        f0.l_node=f0.l_node->m__0succ;
        bbDBStmt(2043908);
        f0.l_node->m__0pred->m_Remove();
        bbDBStmt(2048004);
        l_n+=1;
      }else{
        bbDBStmt(2052099);
        bbDBBlock db_blk;
        bbDBStmt(2056196);
        f0.l_node=f0.l_node->m__0succ;
      }
    }
  }
  bbDBStmt(2068482);
  if(bbBool(l_n)){
    bbDBBlock db_blk;
    bbDBStmt(2068487);
    this->m__0seq+=1;
  }
  bbDBStmt(2072578);
  return l_n;
}

bbBool t_std_collections_List_1Tt_default_Voice_2::m_Remove(t_default_Voice* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_default_Voice_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  bbDBFrame db_f{"Remove:Bool(value:default.Voice)","/Users/simon/monkey2/modules/std/collections/list.monkey2"};
  t_std_collections_List_1Tt_default_Voice_2*self=this;
  bbDBLocal("Self",&self);
  bbDBLocal("value",&l_value);
  bbDBStmt(1904648);
  f0.l_node=this->m_FindNode(l_value);
  bbDBLocal("node",&f0.l_node);
  bbDBStmt(1908738);
  if(!bbBool(f0.l_node)){
    bbDBBlock db_blk;
    bbDBStmt(1908750);
    return false;
  }
  bbDBStmt(1912834);
  f0.l_node->m_Remove();
  bbDBStmt(1916930);
  this->m__0seq+=1;
  bbDBStmt(1921026);
  return true;
}

t_std_collections_List_1Tt_default_Voice_2_Node* t_std_collections_List_1Tt_default_Voice_2::m_LastNode(){
  bbDBFrame db_f{"LastNode:std.collections.List<default.Voice>.Node()","/Users/simon/monkey2/modules/std/collections/list.monkey2"};
  t_std_collections_List_1Tt_default_Voice_2*self=this;
  bbDBLocal("Self",&self);
  bbDBStmt(2793474);
  if(!this->m_Empty()){
    bbDBBlock db_blk;
    bbDBStmt(2793487);
    return this->m__0head->m__0pred;
  }
  bbDBStmt(2797570);
  return ((t_std_collections_List_1Tt_default_Voice_2_Node*)0);
}

t_default_Voice* t_std_collections_List_1Tt_default_Voice_2::m_Last(){
  bbDBFrame db_f{"Last:default.Voice()","/Users/simon/monkey2/modules/std/collections/list.monkey2"};
  t_std_collections_List_1Tt_default_Voice_2*self=this;
  bbDBLocal("Self",&self);
  bbDBStmt(1708034);
  bbDebugAssert(!this->m_Empty(),BB_T("Debug assert failed"));
  bbDBStmt(1716226);
  return this->m__0head->m__0pred->m__0value;
}

t_std_collections_List_1Tt_default_Voice_2_Node* t_std_collections_List_1Tt_default_Voice_2::m_HeadNode(){
  bbDBFrame db_f{"HeadNode:std.collections.List<default.Voice>.Node()","/Users/simon/monkey2/modules/std/collections/list.monkey2"};
  t_std_collections_List_1Tt_default_Voice_2*self=this;
  bbDBLocal("Self",&self);
  bbDBStmt(2715650);
  return this->m__0head;
}

t_std_collections_List_1Tt_default_Voice_2_Node* t_std_collections_List_1Tt_default_Voice_2::m_FirstNode(){
  bbDBFrame db_f{"FirstNode:std.collections.List<default.Voice>.Node()","/Users/simon/monkey2/modules/std/collections/list.monkey2"};
  t_std_collections_List_1Tt_default_Voice_2*self=this;
  bbDBLocal("Self",&self);
  bbDBStmt(2752514);
  if(!this->m_Empty()){
    bbDBBlock db_blk;
    bbDBStmt(2752527);
    return this->m__0head->m__0succ;
  }
  bbDBStmt(2756610);
  return ((t_std_collections_List_1Tt_default_Voice_2_Node*)0);
}

t_default_Voice* t_std_collections_List_1Tt_default_Voice_2::m_First(){
  bbDBFrame db_f{"First:default.Voice()","/Users/simon/monkey2/modules/std/collections/list.monkey2"};
  t_std_collections_List_1Tt_default_Voice_2*self=this;
  bbDBLocal("Self",&self);
  bbDBStmt(1654786);
  bbDebugAssert(!this->m_Empty(),BB_T("Debug assert failed"));
  bbDBStmt(1662978);
  return this->m__0head->m__0succ->m__0value;
}

t_std_collections_List_1Tt_default_Voice_2_Node* t_std_collections_List_1Tt_default_Voice_2::m_FindNode(t_default_Voice* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_default_Voice_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  bbDBFrame db_f{"FindNode:std.collections.List<default.Voice>.Node(value:default.Voice)","/Users/simon/monkey2/modules/std/collections/list.monkey2"};
  t_std_collections_List_1Tt_default_Voice_2*self=this;
  bbDBLocal("Self",&self);
  bbDBLocal("value",&l_value);
  bbDBStmt(2842632);
  f0.l_node=this->m__0head->m__0succ;
  bbDBLocal("node",&f0.l_node);
  bbDBStmt(2846722);
  {
    bbDBLoop db_loop;
    while((f0.l_node!=this->m__0head)){
      bbDBBlock db_blk;
      bbDBStmt(2850819);
      if((f0.l_node->m__0value==l_value)){
        bbDBBlock db_blk;
        bbDBStmt(2850840);
        return f0.l_node;
      }
      bbDBStmt(2854915);
      f0.l_node=f0.l_node->m__0succ;
    }
  }
  bbDBStmt(2863106);
  return ((t_std_collections_List_1Tt_default_Voice_2_Node*)0);
}

t_std_collections_List_1Tt_default_Voice_2_Node* t_std_collections_List_1Tt_default_Voice_2::m_FindLastNode(t_default_Voice* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_default_Voice_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  bbDBFrame db_f{"FindLastNode:std.collections.List<default.Voice>.Node(value:default.Voice)","/Users/simon/monkey2/modules/std/collections/list.monkey2"};
  t_std_collections_List_1Tt_default_Voice_2*self=this;
  bbDBLocal("Self",&self);
  bbDBLocal("value",&l_value);
  bbDBStmt(2908168);
  f0.l_node=this->m__0head->m__0pred;
  bbDBLocal("node",&f0.l_node);
  bbDBStmt(2912258);
  {
    bbDBLoop db_loop;
    while((f0.l_node!=this->m__0head)){
      bbDBBlock db_blk;
      bbDBStmt(2916355);
      if((f0.l_node->m__0value==l_value)){
        bbDBBlock db_blk;
        bbDBStmt(2916376);
        return f0.l_node;
      }
      bbDBStmt(2920451);
      f0.l_node=f0.l_node->m__0pred;
    }
  }
  bbDBStmt(2928642);
  return ((t_std_collections_List_1Tt_default_Voice_2_Node*)0);
}

bbBool t_std_collections_List_1Tt_default_Voice_2::m_Empty(){
  bbDBFrame db_f{"Empty:Bool()","/Users/simon/monkey2/modules/std/collections/list.monkey2"};
  t_std_collections_List_1Tt_default_Voice_2*self=this;
  bbDBLocal("Self",&self);
  bbDBStmt(1478658);
  return (this->m__0head->m__0succ==this->m__0head);
}

bbInt t_std_collections_List_1Tt_default_Voice_2::m_Count(){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_default_Voice_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  bbDBFrame db_f{"Count:Int()","/Users/simon/monkey2/modules/std/collections/list.monkey2"};
  t_std_collections_List_1Tt_default_Voice_2*self=this;
  bbDBLocal("Self",&self);
  bbDBStmt(1527816);
  f0.l_node=this->m__0head->m__0succ;
  bbDBLocal("node",&f0.l_node);
  bbDBStmt(1527834);
  bbInt l_n=bbInt(0);
  bbDBLocal("n",&l_n);
  bbDBStmt(1531906);
  {
    bbDBLoop db_loop;
    while((f0.l_node!=this->m__0head)){
      bbDBBlock db_blk;
      bbDBStmt(1536003);
      f0.l_node=f0.l_node->m__0succ;
      bbDBStmt(1540099);
      l_n+=1;
    }
  }
  bbDBStmt(1548290);
  return l_n;
}

void t_std_collections_List_1Tt_default_Voice_2::m_Clear(){
  bbDBFrame db_f{"Clear:Void()","/Users/simon/monkey2/modules/std/collections/list.monkey2"};
  t_std_collections_List_1Tt_default_Voice_2*self=this;
  bbDBLocal("Self",&self);
  bbDBStmt(1744898);
  this->m__0head->m__0succ=this->m__0head;
  bbDBStmt(1748994);
  this->m__0head->m__0pred=this->m__0head;
  bbDBStmt(1753090);
  this->m__0seq+=1;
}

t_std_collections_List_1Tt_default_Voice_2_BackwardsIterator t_std_collections_List_1Tt_default_Voice_2::m_Backwards(){
  bbDBFrame db_f{"Backwards:std.collections.List<default.Voice>.BackwardsIterator()","/Users/simon/monkey2/modules/std/collections/list.monkey2"};
  t_std_collections_List_1Tt_default_Voice_2*self=this;
  bbDBLocal("Self",&self);
  bbDBStmt(1441794);
  return t_std_collections_List_1Tt_default_Voice_2_BackwardsIterator(this,this->m__0head->m__0pred);
}

t_std_collections_List_1Tt_default_Voice_2_Iterator t_std_collections_List_1Tt_default_Voice_2::m_All(){
  bbDBFrame db_f{"All:std.collections.List<default.Voice>.Iterator()","/Users/simon/monkey2/modules/std/collections/list.monkey2"};
  t_std_collections_List_1Tt_default_Voice_2*self=this;
  bbDBLocal("Self",&self);
  bbDBStmt(1396738);
  return t_std_collections_List_1Tt_default_Voice_2_Iterator(this,this->m__0head->m__0succ);
}

t_std_collections_List_1Tt_default_Voice_2_Node* t_std_collections_List_1Tt_default_Voice_2::m_AddLast(t_default_Voice* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_default_Voice_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  bbDBFrame db_f{"AddLast:std.collections.List<default.Voice>.Node(value:default.Voice)","/Users/simon/monkey2/modules/std/collections/list.monkey2"};
  t_std_collections_List_1Tt_default_Voice_2*self=this;
  bbDBLocal("Self",&self);
  bbDBLocal("value",&l_value);
  bbDBStmt(1851400);
  f0.l_node=bbGCNew<t_std_collections_List_1Tt_default_Voice_2_Node>(l_value,this->m__0head);
  bbDBLocal("node",&f0.l_node);
  bbDBStmt(1855490);
  this->m__0seq+=1;
  bbDBStmt(1859586);
  return f0.l_node;
}

t_std_collections_List_1Tt_default_Voice_2_Node* t_std_collections_List_1Tt_default_Voice_2::m_AddFirst(t_default_Voice* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_default_Voice_2_Node* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  bbDBFrame db_f{"AddFirst:std.collections.List<default.Voice>.Node(value:default.Voice)","/Users/simon/monkey2/modules/std/collections/list.monkey2"};
  t_std_collections_List_1Tt_default_Voice_2*self=this;
  bbDBLocal("Self",&self);
  bbDBLocal("value",&l_value);
  bbDBStmt(1798152);
  f0.l_node=bbGCNew<t_std_collections_List_1Tt_default_Voice_2_Node>(l_value,this->m__0head->m__0succ);
  bbDBLocal("node",&f0.l_node);
  bbDBStmt(1802242);
  this->m__0seq+=1;
  bbDBStmt(1806338);
  return f0.l_node;
}

void t_std_collections_List_1Tt_default_Voice_2::m_AddAll(bbArray<bbGCVar<t_default_Voice>>* l_values){
  bbDBFrame db_f{"AddAll:Void(values:default.Voice[])","/Users/simon/monkey2/modules/std/collections/list.monkey2"};
  t_std_collections_List_1Tt_default_Voice_2*self=this;
  bbDBLocal("Self",&self);
  bbDBLocal("values",&l_values);
  bbDBStmt(2293762);
  {
    bbDBLoop db_loop;
    bbInt l_0=bbInt(0);
    bbDBLocal("0",&l_0);
    bbInt l_1=l_values->length();
    bbDBLocal("1",&l_1);
    for(;(l_0<l_1);l_0+=1){
      struct f2_t : public bbGCFrame{
        t_default_Voice* l_value{};
        void gcMark(){
          bbGCMarkPtr(l_value);
        }
      }f2{};
      bbDBBlock db_blk;
      f2.l_value=l_values->at(l_0);
      bbDBLocal("value",&f2.l_value);
      bbDBStmt(2297859);
      this->m_AddLast(f2.l_value);
    }
  }
}

void t_std_collections_List_1Tt_default_Voice_2::m_Add(t_default_Voice* l_value){
  bbDBFrame db_f{"Add:Void(value:default.Voice)","/Users/simon/monkey2/modules/std/collections/list.monkey2"};
  t_std_collections_List_1Tt_default_Voice_2*self=this;
  bbDBLocal("Self",&self);
  bbDBLocal("value",&l_value);
  bbDBStmt(2248706);
  this->m_AddLast(l_value);
}
bbString bbDBType(t_std_collections_List_1Tt_default_Voice_2**){
  return "std.collections.List<default.Voice>";
}
bbString bbDBValue(t_std_collections_List_1Tt_default_Voice_2**p){
  return bbDBObjectValue(*p);
}

void mx2_vsynth_std_collections_2list_init(){
  static bool done;
  if(done) return;
  done=true;
}

bbInit mx2_vsynth_std_collections_2list_init_v("vsynth_std_collections_2list",&mx2_vsynth_std_collections_2list_init);
