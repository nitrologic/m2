
#include "mx2cc_value.h"

// ***** External *****

#include "../../../../../modules/monkey/monkey.buildv1.0.0/desktop_release_linux/monkey_types.h"
#include "mx2cc_class.h"
#include "mx2cc_decl.h"
#include "mx2cc_errors.h"
#include "mx2cc_func.h"
#include "mx2cc_scope.h"
#include "mx2cc_stmt.h"
#include "mx2cc_type.h"
#include "mx2cc_var.h"

struct t_mx2_Module;

extern t_mx2_Type* g_mx2_BalanceAssignTypes(bbString l_op,t_mx2_Type* l_lhs,t_mx2_Type* l_rhs);
extern bbString g_mx2_Join_1Tt_mx2_Value_2(bbArray<bbGCVar<t_mx2_Value>>* l_bits,bbString l_sep);

// ***** Internal *****

bbInt g_mx2_VALUE_0LVALUE;
bbInt g_mx2_VALUE_0ASSIGNABLE;

t_mx2_LiteralValue* g_mx2_LiteralValue_IntValue(bbInt l_value){
  return bbGCNew<t_mx2_LiteralValue>(((t_mx2_Type*)(g_mx2_Type_IntType)),bbString(l_value));
}

t_mx2_LiteralValue* g_mx2_LiteralValue_BoolValue(bbBool l_value){
  if(l_value){
    return bbGCNew<t_mx2_LiteralValue>(((t_mx2_Type*)(g_mx2_Type_BoolType)),BB_T("true"));
  }
  return bbGCNew<t_mx2_LiteralValue>(((t_mx2_Type*)(g_mx2_Type_BoolType)),BB_T("false"));
}

void g_mx2_Value_CheckAccess(t_mx2_Decl* l_decl,t_mx2_Scope* l_scope,t_mx2_Scope* l_tscope){
  struct f0_t : public bbGCFrame{
    t_mx2_ClassScope* l_cscope{};
    void gcMark(){
      bbGCMarkPtr(l_cscope);
    }
  }f0{};
  if(l_decl->m_IsPublic()){
    return;
  }
  f0.l_cscope=bb_object_cast<t_mx2_ClassScope*>(l_scope);
  if(bbBool(f0.l_cscope)){
    struct f1_t : public bbGCFrame{
      t_mx2_ClassType* l_ctype{};
      t_mx2_ClassType* l_ctype2{};
      void gcMark(){
        bbGCMarkPtr(l_ctype);
        bbGCMarkPtr(l_ctype2);
      }
    }f1{};
    if((l_scope->m_FindFile()==l_tscope->m_FindFile())){
      return;
    }
    if(l_decl->m_IsInternal()){
      if((l_scope->m_FindFile()->m_fdecl->m_module==l_tscope->m_FindFile()->m_fdecl->m_module)){
        return;
      }
      throw bbGCNew<t_mx2_SemantEx>(((BB_T("Internal member '")+l_decl->m_ident)+BB_T("' cannot be accessed from different module")));
    }
    f1.l_ctype=f0.l_cscope->m_ctype;
    f1.l_ctype2=l_tscope->m_FindClass();
    if(l_decl->m_IsPrivate()){
      if(f1.l_ctype->m__eq(((t_mx2_Type*)(f1.l_ctype2)))){
        return;
      }
      throw bbGCNew<t_mx2_SemantEx>(((BB_T("Private member '")+l_decl->m_ident)+BB_T("' cannot be accessed from here")));
    }else if(l_decl->m_IsProtected()){
      while(bbBool(f1.l_ctype2)){
        if(f1.l_ctype->m__eq(((t_mx2_Type*)(f1.l_ctype2)))){
          return;
        }
        f1.l_ctype2=f1.l_ctype2->m_superType;
      }
      throw bbGCNew<t_mx2_SemantEx>(((BB_T("Protected member '")+l_decl->m_ident)+BB_T("' cannot be accessed from here")));
    }
  }
}

void t_mx2_Value::gcMark(){
  t_mx2_SNode::gcMark();
  bbGCMark(m_type);
}

t_mx2_Value* t_mx2_Value::m_UpCast(t_mx2_Type* l_type){
  struct f0_t : public bbGCFrame{
    t_mx2_Value* l_rvalue{};
    void gcMark(){
      bbGCMarkPtr(l_rvalue);
    }
  }f0{};
  f0.l_rvalue=this->m_ToRValue();
  bbInt l_d=f0.l_rvalue->m_type->m_DistanceToType(l_type);
  if((l_d<bbInt(0))){
    throw bbGCNew<t_mx2_UpCastEx>(f0.l_rvalue,l_type);
  }
  if((l_d>bbInt(0))){
    return ((t_mx2_Value*)(bbGCNew<t_mx2_UpCastValue>(l_type,f0.l_rvalue)));
  }
  return f0.l_rvalue;
}

t_mx2_Value* t_mx2_Value::m_ToValue(t_mx2_Value* l_instance){
  return this;
}

bbString t_mx2_Value::m_ToString(){
  return (BB_T("????? VALUE ????? ")+bbString::fromCString(this->typeName()));
}

t_mx2_Value* t_mx2_Value::m_ToRValue(){
  return this;
}

t_mx2_Value* t_mx2_Value::m_RemoveSideEffects(t_mx2_Block* l_block){
  return this;
}

bbBool t_mx2_Value::m_IsLValue(){
  return ((this->m_flags&g_mx2_VALUE_0LVALUE)!=bbInt(0));
}

bbBool t_mx2_Value::m_IsAssignable(){
  return ((this->m_flags&g_mx2_VALUE_0ASSIGNABLE)!=bbInt(0));
}

t_mx2_Value* t_mx2_Value::m_Invoke(bbArray<bbGCVar<t_mx2_Value>>* l_args){
  struct f0_t : public bbGCFrame{
    t_mx2_Value* l_rvalue{};
    void gcMark(){
      bbGCMarkPtr(l_rvalue);
    }
  }f0{};
  f0.l_rvalue=this->m_ToRValue();
  return f0.l_rvalue->m_type->m_Invoke(l_args,f0.l_rvalue);
}

t_mx2_Value* t_mx2_Value::m_Index(bbArray<bbGCVar<t_mx2_Value>>* l_args){
  struct f0_t : public bbGCFrame{
    t_mx2_Value* l_rvalue{};
    void gcMark(){
      bbGCMarkPtr(l_rvalue);
    }
  }f0{};
  f0.l_rvalue=this->m_ToRValue();
  return f0.l_rvalue->m_type->m_Index(l_args,f0.l_rvalue);
}

bbBool t_mx2_Value::m_HasSideEffects(){
  return false;
}

t_mx2_Value* t_mx2_Value::m_GenInstance(bbArray<bbGCVar<t_mx2_Type>>* l_types){
  throw bbGCNew<t_mx2_SemantEx>(((BB_T("Value '")+this->m_ToString())+BB_T("' is Not generic")));
}

t_mx2_Value* t_mx2_Value::m_FindValue(bbString l_ident){
  struct f0_t : public bbGCFrame{
    t_mx2_SNode* l_node{};
    t_mx2_Value* l_rvalue{};
    void gcMark(){
      bbGCMarkPtr(l_node);
      bbGCMarkPtr(l_rvalue);
    }
  }f0{};
  f0.l_rvalue=this->m_ToRValue();
  f0.l_node=f0.l_rvalue->m_type->m_FindNode(l_ident);
  if(bbBool(f0.l_node)){
    return f0.l_node->m_ToValue(f0.l_rvalue);
  }
  return ((t_mx2_Value*)0);
}

void t_mx2_Value::m_CheckAccess(t_mx2_Scope* l_tscope){
}

t_mx2_Stmt* t_mx2_Value::m_Assign(t_mx2_PNode* l_pnode,bbString l_op,t_mx2_Value* l_value,t_mx2_Block* l_block){
  struct f0_t : public bbGCFrame{
    t_mx2_Type* l_rtype{};
    t_mx2_Value* t0{};
    void gcMark(){
      bbGCMarkPtr(l_rtype);
      bbGCMarkPtr(t0);
    }
  }f0{};
  if(!this->m_IsAssignable()){
    g_mx2_SemantError(BB_T("Value.Assign()"));
  }
  f0.l_rtype=g_mx2_BalanceAssignTypes(l_op,this->m_type,l_value->m_type);
  return ((t_mx2_Stmt*)(bbGCNew<t_mx2_AssignStmt>(l_pnode,l_op,this,f0.t0=l_value->m_UpCast(f0.l_rtype))));
}

t_mx2_LiteralValue::t_mx2_LiteralValue(t_mx2_Type* l_type,bbString l_value){
  this->m_type=l_type;
  this->m_value=l_value;
}

t_mx2_Value* t_mx2_LiteralValue::m_UpCast(t_mx2_Type* l_type){
  struct f0_t : public bbGCFrame{
    t_mx2_PrimType* l_ptype{};
    t_mx2_PrimType* l_ptype2{};
    void gcMark(){
      bbGCMarkPtr(l_ptype);
      bbGCMarkPtr(l_ptype2);
    }
  }f0{};
  bbInt l_d=this->m_type->m_DistanceToType(l_type);
  if((l_d<bbInt(0))){
    throw bbGCNew<t_mx2_UpCastEx>(((t_mx2_Value*)(this)),l_type);
  }
  if((l_d==bbInt(0))){
    return ((t_mx2_Value*)(this));
  }
  f0.l_ptype=g_mx2_TCast_1Tt_mx2_PrimType_2(l_type);
  if(!bbBool(f0.l_ptype)){
    return ((t_mx2_Value*)(bbGCNew<t_mx2_UpCastValue>(l_type,((t_mx2_Value*)(this)))));
  }
  f0.l_ptype2=g_mx2_TCast_1Tt_mx2_PrimType_2(this->m_type);
  if(!bbBool(f0.l_ptype2)){
    return ((t_mx2_Value*)(bbGCNew<t_mx2_UpCastValue>(l_type,((t_mx2_Value*)(this)))));
  }
  bbString l_result=bbString{};
  if(f0.l_ptype->m__eq(((t_mx2_Type*)(g_mx2_Type_BoolType)))){
    l_result=BB_T("false");
    if(f0.l_ptype2->m_IsIntegral()){
      if(bbBool(bbULong(this->m_value))){
        l_result=BB_T("true");
      }
    }else if(f0.l_ptype2->m_IsReal()){
      if(bbBool(bbDouble(this->m_value))){
        l_result=BB_T("true");
      }
    }else if(f0.l_ptype2->m__eq(((t_mx2_Type*)(g_mx2_Type_StringType)))){
      if(bbBool(this->m_value)){
        l_result=BB_T("true");
      }
    }else{
      g_mx2_SemantError(BB_T("LiteralValue.UpCast()"));
    }
  }else if(f0.l_ptype->m_IsIntegral()){
    l_result=BB_T("0");
    if(f0.l_ptype2->m__eq(((t_mx2_Type*)(g_mx2_Type_BoolType)))){
      if((this->m_value==BB_T("true"))){
        l_result=BB_T("1");
      }
    }else if((f0.l_ptype2->m_IsNumeric()||f0.l_ptype2->m__eq(((t_mx2_Type*)(g_mx2_Type_StringType))))){
      l_result=bbString(bbULong(this->m_value));
    }else{
      g_mx2_SemantError(BB_T("LiteralValue.UpCast()"));
    }
  }else if(f0.l_ptype->m_IsReal()){
    l_result=BB_T("0.0");
    if(f0.l_ptype2->m__eq(((t_mx2_Type*)(g_mx2_Type_BoolType)))){
      if((this->m_value==BB_T("true"))){
        l_result=BB_T("1.0");
      }
    }else if((f0.l_ptype2->m_IsNumeric()||f0.l_ptype2->m__eq(((t_mx2_Type*)(g_mx2_Type_StringType))))){
      l_result=bbString(bbDouble(this->m_value));
    }else{
      g_mx2_SemantError(BB_T("LiteralValue.UpCast()"));
    }
  }else if(f0.l_ptype->m__eq(((t_mx2_Type*)(g_mx2_Type_StringType)))){
    l_result=this->m_value;
  }else{
    g_mx2_SemantError(BB_T("LiteralValue.UpCast()"));
  }
  return ((t_mx2_Value*)(bbGCNew<t_mx2_LiteralValue>(l_type,l_result)));
}

bbString t_mx2_LiteralValue::m_ToString(){
  if(bbBool(this->m_value)){
    return this->m_value;
  }
  return BB_T("Null");
}

t_mx2_Value* t_mx2_LiteralValue::m_RemoveSideEffects(t_mx2_Block* l_block){
  if(this->m_HasSideEffects()){
    return ((t_mx2_Value*)(l_block->m_AllocLocal(((t_mx2_Value*)(this)))));
  }
  return ((t_mx2_Value*)(this));
}

bbBool t_mx2_LiteralValue::m_HasSideEffects(){
  struct f0_t : public bbGCFrame{
    t_mx2_Type* t0{};
    void gcMark(){
      bbGCMarkPtr(t0);
    }
  }f0{};
  return (f0.t0=this->m_type->m_Dealias())->m__eq(((t_mx2_Type*)(g_mx2_Type_StringType)));
}

void t_mx2_TypeValue::gcMark(){
  t_mx2_Value::gcMark();
  bbGCMark(m_ttype);
}

t_mx2_TypeValue::t_mx2_TypeValue(t_mx2_Type* l_ttype){
  this->m_type=((t_mx2_Type*)(g_mx2_Type_VoidType));
  this->m_ttype=l_ttype;
}

bbString t_mx2_TypeValue::m_ToString(){
  return ((BB_T("<")+this->m_ttype->m_ToString())+BB_T(">"));
}

t_mx2_Value* t_mx2_TypeValue::m_FindValue(bbString l_ident){
  struct f0_t : public bbGCFrame{
    t_mx2_SNode* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m_ttype->m_FindNode(l_ident);
  if(bbBool(f0.l_node)){
    return f0.l_node->m_ToValue(((t_mx2_Value*)0));
  }
  return ((t_mx2_Value*)0);
}

void t_mx2_UpCastValue::gcMark(){
  t_mx2_Value::gcMark();
  bbGCMark(m_value);
}

t_mx2_UpCastValue::t_mx2_UpCastValue(t_mx2_Type* l_type,t_mx2_Value* l_value){
  this->m_type=l_type;
  this->m_value=l_value;
}

bbString t_mx2_UpCastValue::m_ToString(){
  return this->m_value->m_ToString();
}

t_mx2_Value* t_mx2_UpCastValue::m_RemoveSideEffects(t_mx2_Block* l_block){
  struct f0_t : public bbGCFrame{
    t_mx2_Value* t0{};
    void gcMark(){
      bbGCMarkPtr(t0);
    }
  }f0{};
  if(!this->m_HasSideEffects()){
    return ((t_mx2_Value*)(this));
  }
  return ((t_mx2_Value*)(bbGCNew<t_mx2_UpCastValue>(this->m_type,f0.t0=this->m_value->m_RemoveSideEffects(l_block))));
}

bbBool t_mx2_UpCastValue::m_HasSideEffects(){
  return this->m_value->m_HasSideEffects();
}

void t_mx2_UpCastValue::m_CheckAccess(t_mx2_Scope* l_tscope){
  this->m_value->m_CheckAccess(l_tscope);
}

void t_mx2_ExplicitCastValue::gcMark(){
  t_mx2_Value::gcMark();
  bbGCMark(m_value);
}

t_mx2_ExplicitCastValue::t_mx2_ExplicitCastValue(t_mx2_Type* l_type,t_mx2_Value* l_value){
  this->m_type=l_type;
  this->m_value=l_value;
}

bbString t_mx2_ExplicitCastValue::m_ToString(){
  return ((((BB_T("Cast<")+this->m_type->m_ToString())+BB_T(">("))+this->m_value->m_ToString())+BB_T(")"));
}

t_mx2_Value* t_mx2_ExplicitCastValue::m_RemoveSideEffects(t_mx2_Block* l_block){
  struct f0_t : public bbGCFrame{
    t_mx2_Value* t0{};
    void gcMark(){
      bbGCMarkPtr(t0);
    }
  }f0{};
  if(!this->m_HasSideEffects()){
    return ((t_mx2_Value*)(this));
  }
  return ((t_mx2_Value*)(bbGCNew<t_mx2_ExplicitCastValue>(this->m_type,f0.t0=this->m_value->m_RemoveSideEffects(l_block))));
}

bbBool t_mx2_ExplicitCastValue::m_HasSideEffects(){
  return this->m_value->m_HasSideEffects();
}

void t_mx2_SelfValue::gcMark(){
  t_mx2_Value::gcMark();
  bbGCMark(m_ctype);
}

t_mx2_SelfValue::t_mx2_SelfValue(t_mx2_ClassType* l_ctype){
  this->m_type=((t_mx2_Type*)(l_ctype));
  this->m_ctype=l_ctype;
  if(l_ctype->m_IsStruct()){
    this->m_flags|=(g_mx2_VALUE_0LVALUE|g_mx2_VALUE_0ASSIGNABLE);
  }
}

bbString t_mx2_SelfValue::m_ToString(){
  return BB_T("Self");
}

void t_mx2_SuperValue::gcMark(){
  t_mx2_Value::gcMark();
  bbGCMark(m_ctype);
}

t_mx2_SuperValue::t_mx2_SuperValue(t_mx2_ClassType* l_ctype){
  this->m_type=((t_mx2_Type*)(l_ctype));
  this->m_ctype=l_ctype;
}

bbString t_mx2_SuperValue::m_ToString(){
  return BB_T("Super");
}

t_mx2_NullValue::t_mx2_NullValue(){
  this->m_type=((t_mx2_Type*)(g_mx2_Type_NullType));
}

t_mx2_Value* t_mx2_NullValue::m_UpCast(t_mx2_Type* l_type){
  return ((t_mx2_Value*)(bbGCNew<t_mx2_LiteralValue>(l_type,bbString{})));
}

bbString t_mx2_NullValue::m_ToString(){
  return BB_T("Null");
}

t_mx2_Value* t_mx2_NullValue::m_ToRValue(){
  throw bbGCNew<t_mx2_SemantEx>(BB_T("'Null' has no type!"));
}

void t_mx2_InvokeValue::gcMark(){
  t_mx2_Value::gcMark();
  bbGCMark(m_ftype);
  bbGCMark(m_value);
  bbGCMark(m_args);
}

t_mx2_InvokeValue::t_mx2_InvokeValue(t_mx2_Value* l_value,bbArray<bbGCVar<t_mx2_Value>>* l_args){
  this->m_ftype=g_mx2_TCast_1Tt_mx2_FuncType_2(l_value->m_type);
  this->m_type=this->m_ftype->m_retType;
  this->m_value=l_value;
  this->m_args=l_args;
}

bbString t_mx2_InvokeValue::m_ToString(){
  return (((this->m_value->m_ToString()+BB_T("("))+g_mx2_Join_1Tt_mx2_Value_2(this->m_args,BB_T(",")))+BB_T(")!"));
}

t_mx2_Value* t_mx2_InvokeValue::m_RemoveSideEffects(t_mx2_Block* l_block){
  return ((t_mx2_Value*)(l_block->m_AllocLocal(((t_mx2_Value*)(this)))));
}

bbBool t_mx2_InvokeValue::m_HasSideEffects(){
  return true;
}

void t_mx2_InvokeValue::m_CheckAccess(t_mx2_Scope* l_scope){
  this->m_value->m_CheckAccess(l_scope);
  {
    bbInt l_0=bbInt(0);
    bbInt l_1=this->m_args->length();
    for(;(l_0<l_1);l_0+=1){
      struct f2_t : public bbGCFrame{
        t_mx2_Value* l_arg{};
        void gcMark(){
          bbGCMarkPtr(l_arg);
        }
      }f2{};
      f2.l_arg=this->m_args->at(l_0);
      f2.l_arg->m_CheckAccess(l_scope);
    }
  }
}

void t_mx2_InvokeNewValue::gcMark(){
  t_mx2_Value::gcMark();
  bbGCMark(m_ctype);
  bbGCMark(m_args);
}

t_mx2_InvokeNewValue::t_mx2_InvokeNewValue(t_mx2_ClassType* l_ctype,bbArray<bbGCVar<t_mx2_Value>>* l_args){
  this->m_type=((t_mx2_Type*)(g_mx2_Type_VoidType));
  this->m_ctype=l_ctype;
  this->m_args=l_args;
}

bbString t_mx2_InvokeNewValue::m_ToString(){
  return ((BB_T("New(")+g_mx2_Join_1Tt_mx2_Value_2(this->m_args,BB_T(",")))+BB_T(")"));
}

void t_mx2_NewObjectValue::gcMark(){
  t_mx2_Value::gcMark();
  bbGCMark(m_ctype);
  bbGCMark(m_ctor);
  bbGCMark(m_args);
}

t_mx2_NewObjectValue::t_mx2_NewObjectValue(t_mx2_ClassType* l_ctype,t_mx2_FuncValue* l_ctor,bbArray<bbGCVar<t_mx2_Value>>* l_args){
  this->m_type=((t_mx2_Type*)(l_ctype));
  this->m_ctype=l_ctype;
  this->m_ctor=l_ctor;
  this->m_args=l_args;
}

bbString t_mx2_NewObjectValue::m_ToString(){
  return ((((BB_T("New ")+this->m_ctype->m_ToString())+BB_T("("))+g_mx2_Join_1Tt_mx2_Value_2(this->m_args,BB_T(",")))+BB_T(")"));
}

t_mx2_Value* t_mx2_NewObjectValue::m_RemoveSideEffects(t_mx2_Block* l_block){
  return ((t_mx2_Value*)(l_block->m_AllocLocal(((t_mx2_Value*)(this)))));
}

bbBool t_mx2_NewObjectValue::m_HasSideEffects(){
  return true;
}

void t_mx2_NewArrayValue::gcMark(){
  t_mx2_Value::gcMark();
  bbGCMark(m_atype);
  bbGCMark(m_sizes);
  bbGCMark(m_inits);
}

t_mx2_NewArrayValue::t_mx2_NewArrayValue(t_mx2_ArrayType* l_atype,bbArray<bbGCVar<t_mx2_Value>>* l_sizes,bbArray<bbGCVar<t_mx2_Value>>* l_inits){
  this->m_type=((t_mx2_Type*)(l_atype));
  this->m_atype=l_atype;
  this->m_sizes=l_sizes;
  this->m_inits=l_inits;
}

bbString t_mx2_NewArrayValue::m_ToString(){
  if(bbBool(this->m_inits)){
    return (((this->m_atype->m_ToString()+BB_T("("))+g_mx2_Join_1Tt_mx2_Value_2(this->m_inits,BB_T(",")))+BB_T(")"));
  }
  return ((((BB_T("New ")+this->m_atype->m_elemType->m_ToString())+BB_T("["))+g_mx2_Join_1Tt_mx2_Value_2(this->m_sizes,BB_T(",")))+BB_T("]"));
}

t_mx2_Value* t_mx2_NewArrayValue::m_RemoveSideEffects(t_mx2_Block* l_block){
  return ((t_mx2_Value*)(l_block->m_AllocLocal(((t_mx2_Value*)(this)))));
}

bbBool t_mx2_NewArrayValue::m_HasSideEffects(){
  return true;
}

void t_mx2_ArrayIndexValue::gcMark(){
  t_mx2_Value::gcMark();
  bbGCMark(m_atype);
  bbGCMark(m_value);
  bbGCMark(m_args);
}

t_mx2_ArrayIndexValue::t_mx2_ArrayIndexValue(t_mx2_ArrayType* l_atype,t_mx2_Value* l_value,bbArray<bbGCVar<t_mx2_Value>>* l_args){
  this->m_type=l_atype->m_elemType;
  this->m_atype=l_atype;
  this->m_value=l_value;
  this->m_args=l_args;
  this->m_flags|=(g_mx2_VALUE_0LVALUE|g_mx2_VALUE_0ASSIGNABLE);
}

bbString t_mx2_ArrayIndexValue::m_ToString(){
  return (((this->m_value->m_ToString()+BB_T("["))+g_mx2_Join_1Tt_mx2_Value_2(this->m_args,BB_T(",")))+BB_T("]"));
}

t_mx2_Value* t_mx2_ArrayIndexValue::m_RemoveSideEffects(t_mx2_Block* l_block){
  struct f0_t : public bbGCFrame{
    bbArray<bbGCVar<t_mx2_Value>>* l_args{};
    t_mx2_Value* l_value{};
    void gcMark(){
      bbGCMarkPtr(l_args);
      bbGCMarkPtr(l_value);
    }
  }f0{};
  if(!this->m_HasSideEffects()){
    return ((t_mx2_Value*)(this));
  }
  f0.l_value=this->m_value->m_RemoveSideEffects(l_block);
  f0.l_args=this->m_args->slice(bbInt(0));
  {
    bbInt l_i=bbInt(0);
    for(;(l_i<f0.l_args->length());l_i+=1){
      f0.l_args->at(l_i)=f0.l_args->at(l_i)->m_RemoveSideEffects(l_block);
    }
  }
  return ((t_mx2_Value*)(bbGCNew<t_mx2_ArrayIndexValue>(this->m_atype,f0.l_value,f0.l_args)));
}

bbBool t_mx2_ArrayIndexValue::m_HasSideEffects(){
  if(this->m_value->m_HasSideEffects()){
    return true;
  }
  {
    bbInt l_0=bbInt(0);
    bbInt l_1=this->m_args->length();
    for(;(l_0<l_1);l_0+=1){
      struct f2_t : public bbGCFrame{
        t_mx2_Value* l_arg{};
        void gcMark(){
          bbGCMarkPtr(l_arg);
        }
      }f2{};
      f2.l_arg=this->m_args->at(l_0);
      if(f2.l_arg->m_HasSideEffects()){
        return true;
      }
    }
  }
  return false;
}

void t_mx2_StringIndexValue::gcMark(){
  t_mx2_Value::gcMark();
  bbGCMark(m_value);
  bbGCMark(m_index);
}

t_mx2_StringIndexValue::t_mx2_StringIndexValue(t_mx2_Value* l_value,t_mx2_Value* l_index){
  this->m_type=((t_mx2_Type*)(g_mx2_Type_IntType));
  this->m_value=l_value;
  this->m_index=l_index;
}

bbString t_mx2_StringIndexValue::m_ToString(){
  return (((this->m_value->m_ToString()+BB_T("["))+this->m_index->m_ToString())+BB_T("]"));
}

t_mx2_Value* t_mx2_StringIndexValue::m_RemoveSideEffects(t_mx2_Block* l_block){
  struct f0_t : public bbGCFrame{
    t_mx2_Value* l_index{};
    t_mx2_Value* l_value{};
    void gcMark(){
      bbGCMarkPtr(l_index);
      bbGCMarkPtr(l_value);
    }
  }f0{};
  if(!this->m_HasSideEffects()){
    return ((t_mx2_Value*)(this));
  }
  f0.l_value=this->m_value->m_RemoveSideEffects(l_block);
  f0.l_index=this->m_index->m_RemoveSideEffects(l_block);
  return ((t_mx2_Value*)(bbGCNew<t_mx2_StringIndexValue>(f0.l_value,f0.l_index)));
}

bbBool t_mx2_StringIndexValue::m_HasSideEffects(){
  return (this->m_value->m_HasSideEffects()||this->m_index->m_HasSideEffects());
}

void t_mx2_PointerIndexValue::gcMark(){
  t_mx2_Value::gcMark();
  bbGCMark(m_value);
  bbGCMark(m_index);
}

t_mx2_PointerIndexValue::t_mx2_PointerIndexValue(t_mx2_Type* l_elemType,t_mx2_Value* l_value,t_mx2_Value* l_index){
  this->m_type=l_elemType;
  this->m_value=l_value;
  this->m_index=l_index;
  this->m_flags|=(g_mx2_VALUE_0LVALUE|g_mx2_VALUE_0ASSIGNABLE);
}

bbString t_mx2_PointerIndexValue::m_ToString(){
  return (((this->m_value->m_ToString()+BB_T("["))+this->m_index->m_ToString())+BB_T("]"));
}

t_mx2_Value* t_mx2_PointerIndexValue::m_RemoveSideEffects(t_mx2_Block* l_block){
  struct f0_t : public bbGCFrame{
    t_mx2_Value* l_index{};
    t_mx2_Value* l_value{};
    void gcMark(){
      bbGCMarkPtr(l_index);
      bbGCMarkPtr(l_value);
    }
  }f0{};
  if(!this->m_HasSideEffects()){
    return ((t_mx2_Value*)(this));
  }
  f0.l_value=this->m_value->m_RemoveSideEffects(l_block);
  f0.l_index=this->m_index->m_RemoveSideEffects(l_block);
  return ((t_mx2_Value*)(bbGCNew<t_mx2_StringIndexValue>(f0.l_value,f0.l_index)));
}

bbBool t_mx2_PointerIndexValue::m_HasSideEffects(){
  return (this->m_value->m_HasSideEffects()||this->m_index->m_HasSideEffects());
}

void t_mx2_UnaryopValue::gcMark(){
  t_mx2_Value::gcMark();
  bbGCMark(m_value);
}

t_mx2_UnaryopValue::t_mx2_UnaryopValue(t_mx2_Type* l_type,bbString l_op,t_mx2_Value* l_value){
  this->m_type=l_type;
  this->m_op=l_op;
  this->m_value=l_value;
}

bbString t_mx2_UnaryopValue::m_ToString(){
  return (this->m_op+this->m_value->m_ToString());
}

void t_mx2_BinaryopValue::gcMark(){
  t_mx2_Value::gcMark();
  bbGCMark(m_lhs);
  bbGCMark(m_rhs);
}

t_mx2_BinaryopValue::t_mx2_BinaryopValue(t_mx2_Type* l_type,bbString l_op,t_mx2_Value* l_lhs,t_mx2_Value* l_rhs){
  this->m_type=l_type;
  this->m_op=l_op;
  this->m_lhs=l_lhs;
  this->m_rhs=l_rhs;
}

bbString t_mx2_BinaryopValue::m_ToString(){
  return ((((BB_T("(")+this->m_lhs->m_ToString())+this->m_op)+this->m_rhs->m_ToString())+BB_T(")"));
}

void t_mx2_IfThenElseValue::gcMark(){
  t_mx2_Value::gcMark();
  bbGCMark(m_value);
  bbGCMark(m_thenValue);
  bbGCMark(m_elseValue);
}

t_mx2_IfThenElseValue::t_mx2_IfThenElseValue(t_mx2_Type* l_type,t_mx2_Value* l_value,t_mx2_Value* l_thenValue,t_mx2_Value* l_elseValue){
  this->m_type=l_type;
  this->m_value=l_value;
  this->m_thenValue=l_thenValue;
  this->m_elseValue=l_elseValue;
}

void t_mx2_PointerValue::gcMark(){
  t_mx2_Value::gcMark();
  bbGCMark(m_value);
}

t_mx2_PointerValue::t_mx2_PointerValue(t_mx2_Value* l_value){
  this->m_type=((t_mx2_Type*)(bbGCNew<t_mx2_PointerType>(l_value->m_type)));
  this->m_value=l_value;
}

bbString t_mx2_PointerValue::m_ToString(){
  return (this->m_value->m_ToString()+BB_T(" Ptr"));
}

void mx2_mx2cc_value_init(){
  static bool done;
  if(done) return;
  done=true;
  g_mx2_VALUE_0LVALUE=1;
  g_mx2_VALUE_0ASSIGNABLE=2;
}

bbInit mx2_mx2cc_value_init_v("mx2cc_value",&mx2_mx2cc_value_init);
