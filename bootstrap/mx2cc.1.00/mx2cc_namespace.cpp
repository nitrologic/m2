
#include "mx2cc_namespace.h"

// ***** External *****

#include "mx2cc_node.h"

// ***** Internal *****

void t_mx2_NamespaceType::gcMark(){
  t_mx2_Type::gcMark();
  bbGCMark(m_scope);
}

t_mx2_NamespaceType::t_mx2_NamespaceType(bbString l_ident,t_mx2_NamespaceScope* l_outer){
  this->m_ident=l_ident;
  this->m_scope=bbGCNew<t_mx2_NamespaceScope>(this,l_outer);
}

bbString t_mx2_NamespaceType::m_TypeId(){
  return this->m_scope->m_TypeId();
}

bbString t_mx2_NamespaceType::m_ToString(){
  return this->m_ident;
}

bbString t_mx2_NamespaceType::m_Name(){
  return this->m_scope->m_Name();
}

t_mx2_Type* t_mx2_NamespaceType::m_FindType(bbString l_ident){
  struct f0_t : public bbGCFrame{
    t_mx2_Type* l_type{};
    void gcMark(){
      bbGCMarkPtr(l_type);
    }
  }f0{};
  f0.l_type=this->m_scope->m_GetType(l_ident);
  if(bbBool(f0.l_type)){
    return f0.l_type;
  }
  return ((t_mx2_Type*)0);
}

t_mx2_SNode* t_mx2_NamespaceType::m_FindNode(bbString l_ident){
  struct f0_t : public bbGCFrame{
    t_mx2_SNode* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m_scope->m_GetNode(l_ident);
  if(bbBool(f0.l_node)){
    return f0.l_node;
  }
  return ((t_mx2_SNode*)0);
}

void t_mx2_NamespaceScope::gcMark(){
  t_mx2_Scope::gcMark();
  bbGCMark(m_ntype);
}

t_mx2_NamespaceScope::t_mx2_NamespaceScope(t_mx2_NamespaceType* l_ntype,t_mx2_NamespaceScope* l_outer):t_mx2_Scope(((t_mx2_Scope*)(l_outer))){
  this->m_ntype=l_ntype;
}

bbString t_mx2_NamespaceScope::m_TypeId(){
  if(!bbBool(this->m_ntype)){
    return bbString{};
  }
  if(bbBool(this->m_outer)){
    bbString l_id=this->m_outer->m_TypeId();
    if(bbBool(l_id)){
      return ((l_id+BB_T("_"))+this->m_ntype->m_ident);
    }
  }
  return this->m_ntype->m_ident;
}

bbString t_mx2_NamespaceScope::m_ToString(){
  if(!bbBool(this->m_ntype)){
    return bbString{};
  }
  if(bbBool(this->m_outer)){
    bbString l_str=this->m_outer->m_ToString();
    if(bbBool(l_str)){
      return ((l_str+BB_T("."))+this->m_ntype->m_ident);
    }
  }
  return this->m_ntype->m_ident;
}

bbString t_mx2_NamespaceScope::m_Name(){
  if(!bbBool(this->m_ntype)){
    return bbString{};
  }
  if(bbBool(this->m_outer)){
    bbString l_name=this->m_outer->m_Name();
    if(bbBool(l_name)){
      return ((l_name+BB_T("."))+this->m_ntype->m_ident);
    }
  }
  return this->m_ntype->m_ident;
}

t_mx2_NamespaceScope* t_mx2_NamespaceScope::m_FindRoot(){
  struct f0_t : public bbGCFrame{
    t_mx2_NamespaceScope* l_nmspace{};
    void gcMark(){
      bbGCMarkPtr(l_nmspace);
    }
  }f0{};
  f0.l_nmspace=bb_object_cast<t_mx2_NamespaceScope*>(this->m_outer);
  if((bbBool(f0.l_nmspace)&&bbBool(f0.l_nmspace->m_ntype))){
    return f0.l_nmspace->m_FindRoot();
  }
  return this;
}

void mx2_mx2cc_namespace_init(){
  static bool done;
  if(done) return;
  done=true;
}

bbInit mx2_mx2cc_namespace_init_v("mx2cc_namespace",&mx2_mx2cc_namespace_init);
