
#include "mx2cc_alias.h"

// ***** External *****

#include "../../../../../modules/monkey/monkey.buildv1.0.0/desktop_release_linux/monkey_types.h"
#include "mx2cc_errors.h"
#include "mx2cc_node.h"
#include "mx2cc_scope.h"
#include "mx2cc_std_collections_2stack.h"
#include "mx2cc_typeexpr.h"

extern bbBool g_mx2_AnyTypeGeneric(bbArray<bbGCVar<t_mx2_Type>>* l_types);
extern bbBool g_mx2_TypesEqual(bbArray<bbGCVar<t_mx2_Type>>* l_lhs,bbArray<bbGCVar<t_mx2_Type>>* l_rhs);

// ***** Internal *****

void t_mx2_AliasDecl::gcMark(){
  t_mx2_Decl::gcMark();
  bbGCMark(m_genArgs);
  bbGCMark(m_type);
}

t_mx2_SNode* t_mx2_AliasDecl::m_ToNode(t_mx2_Scope* l_scope){
  struct f0_t : public bbGCFrame{
    bbArray<bbGCVar<t_mx2_Type>>* l_types{};
    void gcMark(){
      bbGCMarkPtr(l_types);
    }
  }f0{};
  f0.l_types=bbArray<bbGCVar<t_mx2_Type>>::create(this->m_genArgs->length());
  {
    bbInt l_i=bbInt(0);
    for(;(l_i<f0.l_types->length());l_i+=1){
      f0.l_types->at(l_i)=((t_mx2_Type*)(bbGCNew<t_mx2_GenArgType>(l_i,this->m_genArgs->at(l_i),((bbArray<bbGCVar<t_mx2_Type>>*)0),((t_mx2_GenArgType*)0))));
    }
  }
  return ((t_mx2_SNode*)(bbGCNew<t_mx2_AliasType>(this,l_scope,f0.l_types,((t_mx2_AliasType*)0))));
}

void t_mx2_AliasType::gcMark(){
  t_mx2_ProxyType::gcMark();
  bbGCMark(m_adecl);
  bbGCMark(m_scope);
  bbGCMark(m_types);
  bbGCMark(m_instanceOf);
  bbGCMark(m_instances);
}

t_mx2_AliasType::t_mx2_AliasType(t_mx2_AliasDecl* l_adecl,t_mx2_Scope* l_scope,bbArray<bbGCVar<t_mx2_Type>>* l_types,t_mx2_AliasType* l_instanceOf){
  this->m_adecl=l_adecl;
  this->m_scope=l_scope;
  this->m_types=l_types;
  this->m_instanceOf=l_instanceOf;
  if(g_mx2_AnyTypeGeneric(l_types)){
    this->m_flags|=g_mx2_Type_TYPE_0GENERIC;
  }
}

t_mx2_SNode* t_mx2_AliasType::m_OnSemant(){
  struct f0_t : public bbGCFrame{
    t_mx2_Scope* l_tscope{};
    void gcMark(){
      bbGCMarkPtr(l_tscope);
    }
  }f0{};
  f0.l_tscope=this->m_scope;
  if(bbBool(this->m_types)){
    f0.l_tscope=bbGCNew<t_mx2_Scope>(f0.l_tscope);
    {
      bbInt l_i=bbInt(0);
      for(;(l_i<this->m_types->length());l_i+=1){
        f0.l_tscope->m_Insert(this->m_adecl->m_genArgs->at(l_i),((t_mx2_SNode*)(this->m_types->at(l_i))));
      }
    }
  }
  this->m__0alias=this->m_adecl->m_type->m_Semant(f0.l_tscope,false);
  this->m_flags=this->m__0alias->m_flags;
  return ((t_mx2_SNode*)(this));
}

bbString t_mx2_AliasType::m_Name(){
  return ((this->m_adecl->m_ident+BB_T(":"))+this->m__0alias->m_Name());
}

t_mx2_Type* t_mx2_AliasType::m_GenInstance(bbArray<bbGCVar<t_mx2_Type>>* l_types){
  struct f0_t : public bbGCFrame{
    t_mx2_AliasType* l_inst{};
    void gcMark(){
      bbGCMarkPtr(l_inst);
    }
  }f0{};
  if(!this->m_IsGeneric()){
    return t_mx2_ProxyType::m_GenInstance(l_types);
  }
  if((l_types->length()!=this->m_types->length())){
    throw bbGCNew<t_mx2_SemantEx>(BB_T("Wrong number of generic type parameters"));
  }
  if(!bbBool(this->m_instances)){
    this->m_instances=bbGCNew<t_std_collections_Stack_1Tt_mx2_AliasType_2>();
  }
  {
    struct f1_t : public bbGCFrame{
      t_std_collections_Stack_1Tt_mx2_AliasType_2_Iterator l_0{};
      void gcMark(){
        bbGCMark(l_0);
      }
    }f1{};
    f1.l_0=this->m_instances->m_All();
    for(;!f1.l_0.m_AtEnd();f1.l_0.m_Bump()){
      struct f2_t : public bbGCFrame{
        t_mx2_AliasType* l_inst{};
        void gcMark(){
          bbGCMarkPtr(l_inst);
        }
      }f2{};
      f2.l_inst=f1.l_0.m_Current();
      if(g_mx2_TypesEqual(f2.l_inst->m_types,l_types)){
        return ((t_mx2_Type*)(f2.l_inst));
      }
    }
  }
  f0.l_inst=bbGCNew<t_mx2_AliasType>(this->m_adecl,this->m_scope,l_types,this);
  this->m_instances->m_Push(f0.l_inst);
  f0.l_inst->m_Semant();
  return ((t_mx2_Type*)(f0.l_inst));
}

void mx2_mx2cc_alias_init(){
  static bool done;
  if(done) return;
  done=true;
}

bbInit mx2_mx2cc_alias_init_v("mx2cc_alias",&mx2_mx2cc_alias_init);
