
#include "mx2cc_property.h"

// ***** External *****

#include "../../../../../modules/monkey/monkey.buildv1.0.0/desktop_release_linux/monkey_types.h"
#include "mx2cc_class.h"
#include "mx2cc_errors.h"
#include "mx2cc_node.h"
#include "mx2cc_scope.h"
#include "mx2cc_stmt.h"
#include "mx2cc_type.h"

extern t_mx2_Type* g_mx2_BalanceAssignTypes(bbString l_op,t_mx2_Type* l_lhs,t_mx2_Type* l_rhs);

// ***** Internal *****

void t_mx2_PropertyDecl::gcMark(){
  t_mx2_Decl::gcMark();
  bbGCMark(m_getFunc);
  bbGCMark(m_setFunc);
}

t_mx2_SNode* t_mx2_PropertyDecl::m_ToNode(t_mx2_Scope* l_scope){
  return ((t_mx2_SNode*)(bbGCNew<t_mx2_PropertyList>(this,l_scope)));
}

void t_mx2_PropertyList::gcMark(){
  t_mx2_FuncList::gcMark();
  bbGCMark(m_pdecl);
  bbGCMark(m_scope);
  bbGCMark(m_cscope);
  bbGCMark(m_getFunc);
  bbGCMark(m_setFunc);
  bbGCMark(m_type);
}

t_mx2_PropertyList::t_mx2_PropertyList(t_mx2_PropertyDecl* l_pdecl,t_mx2_Scope* l_scope):t_mx2_FuncList(l_pdecl->m_ident,l_scope){
  this->m_pnode=((t_mx2_PNode*)(l_pdecl));
  this->m_pdecl=l_pdecl;
  this->m_scope=l_scope;
  this->m_cscope=bb_object_cast<t_mx2_ClassScope*>(l_scope);
}

t_mx2_Value* t_mx2_PropertyList::m_ToValue(t_mx2_Value* l_instance){
  if(!bbBool(l_instance)){
    throw bbGCNew<t_mx2_SemantEx>(((BB_T("Property '")+this->m_pdecl->m_ident)+BB_T("' cannot be accessed without an instance")));
  }
  if(!l_instance->m_type->m_ExtendsType(((t_mx2_Type*)(this->m_cscope->m_ctype)))){
    throw bbGCNew<t_mx2_SemantEx>(((BB_T("Property '")+this->m_pdecl->m_ident)+BB_T("' cannot be accessed from an instance of a different class")));
  }
  return ((t_mx2_Value*)(bbGCNew<t_mx2_PropertyValue>(this,l_instance)));
}

bbString t_mx2_PropertyList::m_ToString(){
  return this->m_pdecl->m_ident;
}

t_mx2_SNode* t_mx2_PropertyList::m_OnSemant(){
  this->m_type=((t_mx2_Type*)(g_mx2_Type_VoidType));
  if(bbBool(this->m_pdecl->m_getFunc)){
    try{
      this->m_getFunc=bbGCNew<t_mx2_FuncValue>(this->m_pdecl->m_getFunc,this->m_scope,((bbArray<bbGCVar<t_mx2_Type>>*)0),((t_mx2_FuncValue*)0));
      this->m_getFunc->m_Semant();
      this->m_type=this->m_getFunc->m_ftype->m_retType;
      this->m_PushFunc(this->m_getFunc);
    }catch(t_mx2_SemantEx* ex){
      struct f2_t : public bbGCFrame{
        t_mx2_SemantEx* l_ex{};
        void gcMark(){
          bbGCMarkPtr(l_ex);
        }
      }f2{};
      f2.l_ex=ex;
    }
  }
  if(bbBool(this->m_pdecl->m_setFunc)){
    try{
      this->m_setFunc=bbGCNew<t_mx2_FuncValue>(this->m_pdecl->m_setFunc,this->m_scope,((bbArray<bbGCVar<t_mx2_Type>>*)0),((t_mx2_FuncValue*)0));
      this->m_setFunc->m_Semant();
      this->m_PushFunc(this->m_setFunc);
    }catch(t_mx2_SemantEx* ex){
      struct f2_t : public bbGCFrame{
        t_mx2_SemantEx* l_ex{};
        void gcMark(){
          bbGCMarkPtr(l_ex);
        }
      }f2{};
      f2.l_ex=ex;
    }
  }
  return ((t_mx2_SNode*)(this));
}

void t_mx2_PropertyValue::gcMark(){
  t_mx2_Value::gcMark();
  bbGCMark(m_plist);
  bbGCMark(m_instance);
}

t_mx2_PropertyValue::t_mx2_PropertyValue(t_mx2_PropertyList* l_plist,t_mx2_Value* l_instance){
  this->m_type=l_plist->m_type;
  this->m_plist=l_plist;
  this->m_instance=l_instance;
  if(bbBool(l_plist->m_setFunc)){
    this->m_flags|=g_mx2_VALUE_0ASSIGNABLE;
  }
}

bbString t_mx2_PropertyValue::m_ToString(){
  return (BB_T("PropertyValue ")+this->m_plist->m_pdecl->m_ident);
}

t_mx2_Value* t_mx2_PropertyValue::m_ToRValue(){
  struct f0_t : public bbGCFrame{
    t_mx2_Value* t0{};
    void gcMark(){
      bbGCMarkPtr(t0);
    }
  }f0{};
  if(!bbBool(this->m_plist->m_getFunc)){
    throw bbGCNew<t_mx2_SemantEx>(((BB_T("Property '")+this->m_ToString())+BB_T("' is write only")));
  }
  return (f0.t0=this->m_plist->m_getFunc->m_ToValue(this->m_instance))->m_Invoke(((bbArray<bbGCVar<t_mx2_Value>>*)0));
}

t_mx2_Value* t_mx2_PropertyValue::m_RemoveSideEffects(t_mx2_Block* l_block){
  struct f0_t : public bbGCFrame{
    t_mx2_Value* l_value{};
    void gcMark(){
      bbGCMarkPtr(l_value);
    }
  }f0{};
  f0.l_value=this->m_instance->m_RemoveSideEffects(l_block);
  if((f0.l_value==this->m_instance)){
    return ((t_mx2_Value*)(this));
  }
  return ((t_mx2_Value*)(bbGCNew<t_mx2_PropertyValue>(this->m_plist,f0.l_value)));
}

bbBool t_mx2_PropertyValue::m_HasSideEffects(){
  return this->m_instance->m_HasSideEffects();
}

t_mx2_Stmt* t_mx2_PropertyValue::m_Assign(t_mx2_PNode* l_pnode,bbString l_op,t_mx2_Value* l_rvalue,t_mx2_Block* l_block){
  struct f0_t : public bbGCFrame{
    bbArray<bbGCVar<t_mx2_Value>>* l_args{};
    t_mx2_Value* l_inst{};
    t_mx2_Value* l_invoke{};
    t_mx2_Value* l_rvalue{};
    t_mx2_Value* t0{};
    f0_t(t_mx2_Value* l_rvalue):l_rvalue(l_rvalue){
    }
    void gcMark(){
      bbGCMarkPtr(l_args);
      bbGCMarkPtr(l_inst);
      bbGCMarkPtr(l_invoke);
      bbGCMarkPtr(l_rvalue);
      bbGCMarkPtr(t0);
    }
  }f0{l_rvalue};
  f0.l_inst=this->m_instance;
  if((l_op!=BB_T("="))){
    struct f1_t : public bbGCFrame{
      t_mx2_Value* l_node{};
      t_mx2_Value* l_value{};
      t_mx2_Value* t0{};
      void gcMark(){
        bbGCMarkPtr(l_node);
        bbGCMarkPtr(l_value);
        bbGCMarkPtr(t0);
      }
    }f1{};
    if(!bbBool(this->m_plist->m_getFunc)){
      throw bbGCNew<t_mx2_SemantEx>(((BB_T("Property '")+this->m_ToString())+BB_T("' is write only")));
    }
    f0.l_inst=f0.l_inst->m_RemoveSideEffects(l_block);
    f1.l_value=(f1.t0=this->m_plist->m_getFunc->m_ToValue(f0.l_inst))->m_Invoke(((bbArray<bbGCVar<t_mx2_Value>>*)0));
    bbString l_op2=l_op.slice(bbInt(0),-1);
    f1.l_node=f1.l_value->m_FindValue(l_op2);
    if(bbBool(f1.l_node)){
      struct f2_t : public bbGCFrame{
        bbArray<bbGCVar<t_mx2_Value>>* l_args{};
        void gcMark(){
          bbGCMarkPtr(l_args);
        }
      }f2{};
      l_op=l_op2;
      f2.l_args=bbArray<bbGCVar<t_mx2_Value>>::create(1);
      f2.l_args->at(bbInt(0))=f0.l_rvalue;
      f0.l_rvalue=f1.l_node->m_Invoke(f2.l_args);
    }else{
      struct f2_t : public bbGCFrame{
        t_mx2_Type* l_rtype{};
        t_mx2_Value* t0{};
        void gcMark(){
          bbGCMarkPtr(l_rtype);
          bbGCMarkPtr(t0);
        }
      }f2{};
      f2.l_rtype=g_mx2_BalanceAssignTypes(l_op,f1.l_value->m_type,f0.l_rvalue->m_type);
      f0.l_rvalue=((t_mx2_Value*)(bbGCNew<t_mx2_BinaryopValue>(f1.l_value->m_type,l_op2,f1.l_value,f2.t0=f0.l_rvalue->m_UpCast(f2.l_rtype))));
    }
  }
  f0.l_args=bbArray<bbGCVar<t_mx2_Value>>::create(1);
  f0.l_args->at(bbInt(0))=f0.l_rvalue;
  f0.l_invoke=(f0.t0=this->m_plist->m_setFunc->m_ToValue(f0.l_inst))->m_Invoke(f0.l_args);
  return ((t_mx2_Stmt*)(bbGCNew<t_mx2_EvalStmt>(l_pnode,f0.l_invoke)));
}

void mx2_mx2cc_property_init(){
  static bool done;
  if(done) return;
  done=true;
}

bbInit mx2_mx2cc_property_init_v("mx2cc_property",&mx2_mx2cc_property_init);
