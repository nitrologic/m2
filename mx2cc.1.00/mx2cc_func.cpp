
#include "mx2cc_func.h"

// ***** External *****

#include "../../../../../modules/monkey/monkey.buildv1.0.0/desktop_release_linux/monkey_types.h"
#include "mx2cc_builder.h"
#include "mx2cc_class.h"
#include "mx2cc_errors.h"
#include "mx2cc_expr.h"
#include "mx2cc_module.h"
#include "mx2cc_scope.h"
#include "mx2cc_std_collections_2stack.h"
#include "mx2cc_stmtexpr.h"
#include "mx2cc_typeexpr.h"
#include "mx2cc_var.h"
#include "../../../../../modules/std/std.buildv1.0.0/desktop_release_linux/std_collections_2stack.h"

extern bbBool g_mx2_TypesEqual(bbArray<bbGCVar<t_mx2_Type>>* l_lhs,bbArray<bbGCVar<t_mx2_Type>>* l_rhs);
extern bbString g_mx2_Join_1Tt_mx2_Type_2(bbArray<bbGCVar<t_mx2_Type>>* l_bits,bbString l_sep);
extern bbBool g_mx2_AnyTypeGeneric(bbArray<bbGCVar<t_mx2_Type>>* l_types);
extern bbArray<bbGCVar<t_mx2_Type>>* g_mx2_Types(bbArray<bbGCVar<t_mx2_Value>>* l_args);
extern t_mx2_FuncValue* g_mx2_overload_FindOverload(t_std_collections_Stack_1Tt_mx2_FuncValue_2* l_funcs,t_mx2_Type* l_ret,bbArray<bbGCVar<t_mx2_Type>>* l_args);

// ***** Internal *****

void t_mx2_FuncValue::gcMark(){
  t_mx2_Value::gcMark();
  bbGCMark(m_fdecl);
  bbGCMark(m_scope);
  bbGCMark(m_types);
  bbGCMark(m_instanceOf);
  bbGCMark(m_pdecls);
  bbGCMark(m_transFile);
  bbGCMark(m_cscope);
  bbGCMark(m_block);
  bbGCMark(m_ftype);
  bbGCMark(m_overrides);
  bbGCMark(m_params);
  bbGCMark(m_selfValue);
  bbGCMark(m_instances);
  bbGCMark(m_captures);
  bbGCMark(m_invokeNew);
}

t_mx2_FuncValue::t_mx2_FuncValue(t_mx2_FuncDecl* l_fdecl,t_mx2_Scope* l_scope,bbArray<bbGCVar<t_mx2_Type>>* l_types,t_mx2_FuncValue* l_instanceOf){
  this->m_pnode=((t_mx2_PNode*)(l_fdecl));
  this->m_fdecl=l_fdecl;
  this->m_scope=l_scope;
  this->m_types=l_types;
  this->m_instanceOf=l_instanceOf;
  this->m_pdecls=l_fdecl->m_type->m_params;
  this->m_transFile=l_scope->m_FindFile()->m_fdecl;
  this->m_cscope=bb_object_cast<t_mx2_ClassScope*>(l_scope);
  if(this->m_IsLambda()){
    this->m_captures=bbGCNew<t_std_collections_Stack_1Tt_mx2_VarValue_2>();
  }
}

void t_mx2_FuncValue::m_Used(){
  if(this->m_used){
    return;
  }
  this->m_used=true;
  g_mx2_Builder_instance->m_semantStmts->m_Push(this);
}

t_mx2_FuncValue* t_mx2_FuncValue::m_TryGenInstance(bbArray<bbGCVar<t_mx2_Type>>* l_types){
  struct f0_t : public bbGCFrame{
    t_mx2_FuncValue* l_inst{};
    void gcMark(){
      bbGCMarkPtr(l_inst);
    }
  }f0{};
  if((l_types->length()!=this->m_types->length())){
    return ((t_mx2_FuncValue*)0);
  }
  if(!bbBool(this->m_instances)){
    this->m_instances=bbGCNew<t_std_collections_Stack_1Tt_mx2_FuncValue_2>();
  }
  {
    struct f1_t : public bbGCFrame{
      t_std_collections_Stack_1Tt_mx2_FuncValue_2_Iterator l_0{};
      void gcMark(){
        bbGCMark(l_0);
      }
    }f1{};
    f1.l_0=this->m_instances->m_All();
    for(;!f1.l_0.m_AtEnd();f1.l_0.m_Bump()){
      struct f2_t : public bbGCFrame{
        t_mx2_FuncValue* l_inst{};
        void gcMark(){
          bbGCMarkPtr(l_inst);
        }
      }f2{};
      f2.l_inst=f1.l_0.m_Current();
      if(g_mx2_TypesEqual(f2.l_inst->m_types,l_types)){
        return bb_object_cast<t_mx2_FuncValue*>(f2.l_inst->m_Semant());
      }
    }
  }
  f0.l_inst=bbGCNew<t_mx2_FuncValue>(this->m_fdecl,this->m_scope,l_types,this);
  this->m_instances->m_Push(f0.l_inst);
  return bb_object_cast<t_mx2_FuncValue*>(f0.l_inst->m_Semant());
}

t_mx2_Value* t_mx2_FuncValue::m_ToValue(t_mx2_Value* l_instance){
  struct f0_t : public bbGCFrame{
    t_mx2_Value* l_value{};
    void gcMark(){
      bbGCMarkPtr(l_value);
    }
  }f0{};
  f0.l_value=((t_mx2_Value*)(this));
  if(this->m_IsCtor()){
    if(bbBool(l_instance)){
      throw bbGCNew<t_mx2_SemantEx>(BB_T("'New' cannot be directly invoked"));
    }
  }else if(this->m_IsMethod()){
    if(!bbBool(l_instance)){
      throw bbGCNew<t_mx2_SemantEx>(((BB_T("Method '")+this->m_ToString())+BB_T("' cannot be accessed without an instance")));
    }
    if(!l_instance->m_type->m_ExtendsType(((t_mx2_Type*)(this->m_cscope->m_ctype)))){
      throw bbGCNew<t_mx2_SemantEx>(((BB_T("Method '")+this->m_ToString())+BB_T("' cannot be accessed from an instance of a different class")));
    }
    f0.l_value=((t_mx2_Value*)(bbGCNew<t_mx2_MemberFuncValue>(l_instance,this)));
  }
  this->m_Used();
  return f0.l_value;
}

bbString t_mx2_FuncValue::m_ToString(){
  bbString l_args=g_mx2_Join_1Tt_mx2_Type_2(this->m_types,BB_T(","));
  if(bbBool(l_args)){
    l_args=((BB_T("<")+l_args)+BB_T(">"));
  }
  return ((((((this->m_fdecl->m_ident+l_args)+BB_T(":"))+this->m_ftype->m_retType->m_ToString())+BB_T("("))+g_mx2_Join_1Tt_mx2_Type_2(this->m_ftype->m_argTypes,BB_T(",")))+BB_T(")"));
}

void t_mx2_FuncValue::m_SemantStmts(){
  if(this->m_block->m_IsGeneric()){
    g_mx2_SemantError(BB_T("FuncValue.SemantStmts(1)"));
  }
  try{
    this->m_SemantParams();
  }catch(t_mx2_SemantEx* ex){
    struct f1_t : public bbGCFrame{
      t_mx2_SemantEx* l_ex{};
      void gcMark(){
        bbGCMarkPtr(l_ex);
      }
    }f1{};
    f1.l_ex=ex;
  }
  if(!this->m_fdecl->m_IsAbstract()){
    this->m_block->m_Semant(this->m_fdecl->m_stmts);
    if((this->m_block->m_reachable&&this->m_ftype->m_retType->m__ne(((t_mx2_Type*)(g_mx2_Type_VoidType))))){
      throw bbGCNew<t_mx2_SemantEx>(BB_T("Missing return statement"));
    }
    this->m_SemantInvokeNew();
  }
  if(((this->m_fdecl->m_kind==BB_T("function"))||this->m_IsExtension())){
    this->m_transFile->m_functions->m_Push(this);
    if((((this->m_fdecl->m_ident==BB_T("Main"))&&bbBool(g_mx2_TCast_1Tt_mx2_VoidType_2(this->m_ftype->m_retType)))&&!bbBool(this->m_ftype->m_argTypes))){
      struct f2_t : public bbGCFrame{
        t_mx2_Module* l_module{};
        void gcMark(){
          bbGCMarkPtr(l_module);
        }
      }f2{};
      f2.l_module=this->m_scope->m_FindFile()->m_fdecl->m_module;
      if(bbBool(f2.l_module->m_main)){
        throw bbGCNew<t_mx2_SemantEx>(BB_T("Duplicate declaration of 'Main'"));
      }
      f2.l_module->m_main=this;
    }
    if(bbBool(this->m_instanceOf)){
      struct f2_t : public bbGCFrame{
        t_mx2_Builder* l_builder{};
        t_mx2_Module* l_module{};
        void gcMark(){
          bbGCMarkPtr(l_builder);
          bbGCMarkPtr(l_module);
        }
      }f2{};
      f2.l_builder=g_mx2_Builder_instance;
      f2.l_module=f2.l_builder->m_semantingModule;
      f2.l_module->m_genInstances->m_Push(((t_mx2_SNode*)(this)));
    }
  }else{
    if((this->m_IsCtor()||this->m_IsMethod())){
      this->m_cscope->m_ctype->m_methods->m_Push(this);
    }
    this->m_scope->m_transMembers->m_Push(((t_mx2_SNode*)(this)));
  }
}

void t_mx2_FuncValue::m_SemantParams(){
  this->m_params=bbArray<bbGCVar<t_mx2_VarValue>>::create(this->m_pdecls->length());
  {
    bbInt l_i=bbInt(0);
    for(;(l_i<this->m_pdecls->length());l_i+=1){
      struct f2_t : public bbGCFrame{
        t_mx2_VarValue* l_param{};
        void gcMark(){
          bbGCMarkPtr(l_param);
        }
      }f2{};
      f2.l_param=bbGCNew<t_mx2_VarValue>(this->m_pdecls->at(l_i),((t_mx2_Scope*)(this->m_block)));
      try{
        f2.l_param->m_Semant();
        this->m_block->m_Insert(this->m_pdecls->at(l_i)->m_ident,((t_mx2_SNode*)(f2.l_param)));
        this->m_params->at(l_i)=f2.l_param;
      }catch(t_mx2_SemantEx* ex){
        struct f3_t : public bbGCFrame{
          t_mx2_SemantEx* l_ex{};
          void gcMark(){
            bbGCMarkPtr(l_ex);
          }
        }f3{};
        f3.l_ex=ex;
      }
    }
  }
  if((this->m_IsCtor()||this->m_IsMethod())){
    if(this->m_IsExtension()){
      struct f2_t : public bbGCFrame{
        t_mx2_Value* t0{};
        void gcMark(){
          bbGCMarkPtr(t0);
        }
      }f2{};
      this->m_selfValue=((t_mx2_Value*)(bbGCNew<t_mx2_VarValue>(BB_T("capture"),BB_T("self"),f2.t0=((t_mx2_Value*)(bbGCNew<t_mx2_LiteralValue>(((t_mx2_Type*)(this->m_cscope->m_ctype)),bbString{}))),this->m_scope)));
    }else{
      this->m_selfValue=((t_mx2_Value*)(bbGCNew<t_mx2_SelfValue>(this->m_cscope->m_ctype)));
    }
  }else if(this->m_IsLambda()){
    this->m_selfValue=bb_object_cast<t_mx2_Block*>(this->m_scope)->m_func->m_selfValue;
    if(bbBool(this->m_selfValue)){
      this->m_selfValue=((t_mx2_Value*)(bbGCNew<t_mx2_VarValue>(BB_T("capture"),BB_T("self"),this->m_selfValue,((t_mx2_Scope*)(this->m_block)))));
      this->m_captures->m_Push(bb_object_cast<t_mx2_VarValue*>(this->m_selfValue));
    }
  }
}

void t_mx2_FuncValue::m_SemantInvokeNew(){
  struct f0_t : public bbGCFrame{
    t_mx2_FuncList* l_flist{};
    t_mx2_FuncValue* l_func{};
    t_mx2_ClassType* l_superType{};
    void gcMark(){
      bbGCMarkPtr(l_flist);
      bbGCMarkPtr(l_func);
      bbGCMarkPtr(l_superType);
    }
  }f0{};
  if(((this->m_fdecl->m_ident!=BB_T("new"))||bbBool(this->m_invokeNew))){
    return;
  }
  f0.l_superType=this->m_scope->m_FindClass()->m_superType;
  if(!bbBool(f0.l_superType)){
    return;
  }
  f0.l_flist=bb_object_cast<t_mx2_FuncList*>(f0.l_superType->m_FindNode(BB_T("new")));
  if(!bbBool(f0.l_flist)){
    return;
  }
  f0.l_func=f0.l_flist->m_FindFunc(((bbArray<bbGCVar<t_mx2_Type>>*)0));
  if(bbBool(f0.l_func)){
    return;
  }
  throw bbGCNew<t_mx2_SemantEx>(((BB_T("Class '")+f0.l_superType->m_ToString())+BB_T("' has no default constructor")),this->m_pnode);
}

bbString t_mx2_FuncValue::m_ParamNames(){
  bbString l_ps=bbString{};
  {
    bbInt l_0=bbInt(0);
    bbInt l_1=this->m_params->length();
    for(;(l_0<l_1);l_0+=1){
      struct f2_t : public bbGCFrame{
        t_mx2_VarValue* l_p{};
        void gcMark(){
          bbGCMarkPtr(l_p);
        }
      }f2{};
      f2.l_p=this->m_params->at(l_0);
      l_ps+=(BB_T(",")+f2.l_p->m_Name());
    }
  }
  return l_ps.slice(1);
}

t_mx2_SNode* t_mx2_FuncValue::m_OnSemant(){
  this->m_block=((t_mx2_Block*)(bbGCNew<t_mx2_FuncBlock>(this)));
  if(bbBool(this->m_types)){
    if(((this->m_fdecl->m_IsAbstract()||this->m_fdecl->m_IsVirtual())||this->m_fdecl->m_IsOverride())){
      throw bbGCNew<t_mx2_SemantEx>(BB_T("Generic methods cannot be virtual"));
    }
    if(this->m_IsCtor()){
      throw bbGCNew<t_mx2_SemantEx>(BB_T("Constructors cannot be generic"));
    }
  }
  this->m_type=this->m_fdecl->m_type->m_Semant(((t_mx2_Scope*)(this->m_block)),false);
  this->m_ftype=g_mx2_TCast_1Tt_mx2_FuncType_2(this->m_type);
  if(this->m_block->m_IsGeneric()){
    return ((t_mx2_SNode*)(this));
  }
  if(this->m_IsCtor()){
    if((this->m_cscope->m_ctype->m_cdecl->m_kind==BB_T("struct"))){
      if((bbBool(this->m_ftype->m_argTypes->length())&&this->m_ftype->m_argTypes->at(bbInt(0))->m_Equals(((t_mx2_Type*)(this->m_cscope->m_ctype))))){
        bbBool l_ok=false;
        {
          bbInt l_i=1;
          for(;(l_i<this->m_ftype->m_argTypes->length());l_i+=1){
            if(bbBool(this->m_pdecls->at(l_i)->m_init)){
              continue;
            }
            l_ok=true;
            break;
          }
        }
        if(!l_ok){
          throw bbGCNew<t_mx2_SemantEx>(BB_T("Illegal struct constructor - 'copy constructors' are automatically generated and cannot be redefined"));
        }
      }
    }
  }else if(this->m_IsMethod()){
    struct f1_t : public bbGCFrame{
      t_mx2_ClassType* l_ctype{};
      t_mx2_FuncValue* l_func2{};
      void gcMark(){
        bbGCMarkPtr(l_ctype);
        bbGCMarkPtr(l_func2);
      }
    }f1{};
    f1.l_ctype=this->m_cscope->m_ctype;
    if(this->m_fdecl->m_IsOperator()){
      bbString l_op=this->m_fdecl->m_ident;
      if(l_op==BB_T("=")||l_op==BB_T("<>")||l_op==BB_T("<")||l_op==BB_T(">")||l_op==BB_T("<=")||l_op==BB_T(">=")){
        if(this->m_ftype->m_retType->m__ne(((t_mx2_Type*)(g_mx2_Type_BoolType)))){
          throw bbGCNew<t_mx2_SemantEx>(((BB_T("Comparison operator '")+l_op)+BB_T("' must return Bool")));
        }
        if((this->m_ftype->m_argTypes->length()!=1)){
          throw bbGCNew<t_mx2_SemantEx>(((BB_T("Comparison operator '")+l_op)+BB_T("' must have 1 parameter")));
        }
      }else if(l_op==BB_T("<=>")){
        struct f3_t : public bbGCFrame{
          t_mx2_PrimType* l_ptype{};
          void gcMark(){
            bbGCMarkPtr(l_ptype);
          }
        }f3{};
        f3.l_ptype=g_mx2_TCast_1Tt_mx2_PrimType_2(this->m_ftype->m_retType);
        if((!bbBool(f3.l_ptype)||!f3.l_ptype->m_IsNumeric())){
          throw bbGCNew<t_mx2_SemantEx>(BB_T("Comparison operator '<=>' must return a numeric type"));
        }
        if((this->m_ftype->m_argTypes->length()!=1)){
          throw bbGCNew<t_mx2_SemantEx>(((BB_T("Comparison operator '")+l_op)+BB_T("' must have 1 parameter")));
        }
      }
    }
    if((f1.l_ctype->m_IsVirtual()&&(this->m_fdecl->m_IsVirtual()||this->m_fdecl->m_IsOverride()))){
      throw bbGCNew<t_mx2_SemantEx>(BB_T("Virtual class methods cannot be declared 'Virtual' or 'Override'"));
    }
    f1.l_func2=f1.l_ctype->m_FindSuperFunc(this->m_fdecl->m_ident,this->m_ftype->m_argTypes);
    if(bbBool(f1.l_func2)){
      if((!f1.l_ctype->m_IsVirtual()&&!this->m_fdecl->m_IsOverride())){
        throw bbGCNew<t_mx2_SemantEx>(((BB_T("Method '")+this->m_ToString())+BB_T("' overrides a superclass method but is not declared 'Override'")));
      }
      if(f1.l_func2->m_fdecl->m_IsFinal()){
        throw bbGCNew<t_mx2_SemantEx>(((BB_T("Method '")+this->m_ToString())+BB_T("' overrides a final method")));
      }
      if((((!f1.l_ctype->m_IsVirtual()&&!f1.l_func2->m_fdecl->m_IsVirtual())&&!f1.l_func2->m_fdecl->m_IsOverride())&&!f1.l_func2->m_fdecl->m_IsAbstract())){
        throw bbGCNew<t_mx2_SemantEx>(((BB_T("Method '")+this->m_ToString())+BB_T("' overrides a non-virtual superclass method")));
      }
      if(!this->m_ftype->m_retType->m_ExtendsType(f1.l_func2->m_ftype->m_retType)){
        throw bbGCNew<t_mx2_SemantEx>(((BB_T("Method '")+this->m_ToString())+BB_T("' overrides a method with incompatible return type")));
      }
      this->m_overrides=f1.l_func2;
    }else{
      if(this->m_fdecl->m_IsOverride()){
        throw bbGCNew<t_mx2_SemantEx>(((BB_T("Method '")+this->m_ToString())+BB_T("' is declared 'Override' but does not override any method")));
      }
    }
  }
  if(bbBool(this->m_fdecl->m_whereExpr)){
    bbBool l_t=this->m_fdecl->m_whereExpr->m_SemantWhere(((t_mx2_Scope*)(this->m_block)));
    if(!l_t){
      return ((t_mx2_SNode*)0);
    }
  }
  if(this->m_IsLambda()){
    this->m_used=true;
    this->m_semanted=((t_mx2_SNode*)(this));
    this->m_SemantStmts();
  }else if(this->m_fdecl->m_IsExtern()){
    this->m_used=true;
  }else if(!bbBool(this->m_types)){
    this->m_Used();
  }
  return ((t_mx2_SNode*)(this));
}

bbString t_mx2_FuncValue::m_Name(){
  bbString l_tys=bbString{};
  {
    bbInt l_0=bbInt(0);
    bbInt l_1=this->m_types->length();
    for(;(l_0<l_1);l_0+=1){
      struct f2_t : public bbGCFrame{
        t_mx2_Type* l_ty{};
        void gcMark(){
          bbGCMarkPtr(l_ty);
        }
      }f2{};
      f2.l_ty=this->m_types->at(l_0);
      l_tys+=(BB_T(",")+f2.l_ty->m_Name());
    }
  }
  if(bbBool(l_tys)){
    l_tys=((BB_T("<")+l_tys.slice(1))+BB_T(">"));
  }
  bbString l_name=this->m_fdecl->m_ident;
  bbString l_ps=bbString{};
  {
    bbInt l_2=bbInt(0);
    bbInt l_3=this->m_params->length();
    for(;(l_2<l_3);l_2+=1){
      struct f2_t : public bbGCFrame{
        t_mx2_VarValue* l_p{};
        void gcMark(){
          bbGCMarkPtr(l_p);
        }
      }f2{};
      f2.l_p=this->m_params->at(l_2);
      l_ps+=(BB_T(",")+f2.l_p->m_Name());
    }
  }
  return (l_name+l_tys);
}

bbBool t_mx2_FuncValue::m_IsVirtual(){
  return (this->m_IsMethod()&&((this->m_cscope->m_ctype->m_IsVirtual()||this->m_fdecl->m_IsVirtual())||this->m_fdecl->m_IsOverride()));
}

bbBool t_mx2_FuncValue::m_IsMethod(){
  return ((this->m_fdecl->m_kind==BB_T("method"))&&(this->m_fdecl->m_ident!=BB_T("new")));
}

bbBool t_mx2_FuncValue::m_IsLambda(){
  return (this->m_fdecl->m_kind==BB_T("lambda"));
}

bbBool t_mx2_FuncValue::m_IsGeneric(){
  if(!bbBool(this->m_ftype)){
    g_mx2_SemantError(BB_T("FuncValue.IsGeneric()"));
  }
  return (this->m_ftype->m_IsGeneric()||(bbBool(this->m_types)&&!bbBool(this->m_instanceOf)));
}

bbBool t_mx2_FuncValue::m_IsFunction(){
  return (this->m_fdecl->m_kind==BB_T("function"));
}

bbBool t_mx2_FuncValue::m_IsExtension(){
  return (((this->m_fdecl->m_kind==BB_T("method"))&&bbBool(this->m_types))||this->m_fdecl->m_IsExtension());
}

bbBool t_mx2_FuncValue::m_IsCtor(){
  return (this->m_fdecl->m_ident==BB_T("new"));
}

t_mx2_Value* t_mx2_FuncValue::m_Invoke(bbArray<bbGCVar<t_mx2_Value>>* l_args){
  struct f0_t : public bbGCFrame{
    bbArray<bbGCVar<t_mx2_Value>>* t0{};
    void gcMark(){
      bbGCMarkPtr(t0);
    }
  }f0{};
  return t_mx2_Value::m_Invoke(f0.t0=this->m_FixArgs(l_args));
}

t_mx2_Value* t_mx2_FuncValue::m_GenInstance(bbArray<bbGCVar<t_mx2_Type>>* l_types){
  struct f0_t : public bbGCFrame{
    t_mx2_FuncValue* l_value{};
    void gcMark(){
      bbGCMarkPtr(l_value);
    }
  }f0{};
  if(g_mx2_AnyTypeGeneric(l_types)){
    g_mx2_SemantError(BB_T("FuncValue.GenInstance()"));
  }
  if(!this->m_IsGeneric()){
    return t_mx2_Value::m_GenInstance(l_types);
  }
  f0.l_value=this->m_TryGenInstance(l_types);
  if(!bbBool(f0.l_value)){
    throw bbGCNew<t_mx2_SemantEx>(((((BB_T("Failed to create generic instance of '")+this->m_ToString())+BB_T("' with types '<"))+g_mx2_Join_1Tt_mx2_Type_2(l_types,BB_T(",")))+BB_T(">'")));
  }
  return ((t_mx2_Value*)(f0.l_value));
}

bbString t_mx2_FuncValue::m_GenArgsName(){
  if(!bbBool(this->m_types)){
    return bbString{};
  }
  bbString l_tys=bbString{};
  {
    bbInt l_0=bbInt(0);
    bbInt l_1=this->m_types->length();
    for(;(l_0<l_1);l_0+=1){
      struct f2_t : public bbGCFrame{
        t_mx2_Type* l_ty{};
        void gcMark(){
          bbGCMarkPtr(l_ty);
        }
      }f2{};
      f2.l_ty=this->m_types->at(l_0);
      l_tys+=(BB_T(",")+f2.l_ty->m_Name());
    }
  }
  return ((BB_T("<")+l_tys.slice(1))+BB_T(">"));
}

bbArray<bbGCVar<t_mx2_Value>>* t_mx2_FuncValue::m_FixArgs(bbArray<bbGCVar<t_mx2_Value>>* l_args){
  struct f0_t : public bbGCFrame{
    bbArray<bbGCVar<t_mx2_Value>>* l_args2{};
    void gcMark(){
      bbGCMarkPtr(l_args2);
    }
  }f0{};
  f0.l_args2=bbArray<bbGCVar<t_mx2_Value>>::create(this->m_pdecls->length());
  {
    bbInt l_i=bbInt(0);
    for(;(l_i<f0.l_args2->length());l_i+=1){
      if(((l_i<l_args->length())&&bbBool(l_args->at(l_i)))){
        f0.l_args2->at(l_i)=l_args->at(l_i);
      }else{
        if(bbBool(this->m_pdecls->at(l_i))){
          f0.l_args2->at(l_i)=this->m_pdecls->at(l_i)->m_init->m_Semant(this->m_scope);
        }
      }
    }
  }
  return f0.l_args2;
}

void t_mx2_FuncValue::m_CheckAccess(t_mx2_Scope* l_tscope){
  g_mx2_Value_CheckAccess(((t_mx2_Decl*)(this->m_fdecl)),this->m_scope,l_tscope);
}

void t_mx2_FuncList::init(){
  m_funcs=bbGCNew<t_std_collections_Stack_1Tt_mx2_FuncValue_2>();
  m_instances=bbGCNew<t_std_collections_Stack_1Tt_mx2_FuncListType_2>();
}

void t_mx2_FuncList::gcMark(){
  t_mx2_SNode::gcMark();
  bbGCMark(m_scope);
  bbGCMark(m_funcs);
  bbGCMark(m_instances);
  bbGCMark(m_instance0);
}

t_mx2_FuncList::t_mx2_FuncList(bbString l_ident,t_mx2_Scope* l_scope){
  init();
  this->m_ident=l_ident;
  this->m_scope=l_scope;
}

t_mx2_Value* t_mx2_FuncList::m_ToValue(t_mx2_Value* l_instance){
  if(!bbBool(this->m_instance0)){
    this->m_instance0=bbGCNew<t_mx2_FuncListType>(this);
  }
  return ((t_mx2_Value*)(bbGCNew<t_mx2_FuncListValue>(this->m_instance0,l_instance)));
}

bbString t_mx2_FuncList::m_ToString(){
  return ((BB_T("{")+this->m_ident)+BB_T("}"));
}

void t_mx2_FuncList::m_PushFunc(t_mx2_FuncValue* l_func){
  if(bbBool(this->m_instances->m_Length())){
    g_mx2_SemantError(BB_T("FuncList.PushFunc()"));
  }
  this->m_funcs->m_Push(l_func);
}

t_mx2_SNode* t_mx2_FuncList::m_OnSemant(){
  struct f0_t : public bbGCFrame{
    t_std_collections_Stack_1Tt_mx2_FuncValue_2* l_tfuncs{};
    void gcMark(){
      bbGCMarkPtr(l_tfuncs);
    }
  }f0{};
  if(!bbBool(this->m_funcs->m_Length())){
    return ((t_mx2_SNode*)(this));
  }
  f0.l_tfuncs=this->m_funcs;
  this->m_funcs=bbGCNew<t_std_collections_Stack_1Tt_mx2_FuncValue_2>();
  {
    struct f1_t : public bbGCFrame{
      t_std_collections_Stack_1Tt_mx2_FuncValue_2_Iterator l_0{};
      void gcMark(){
        bbGCMark(l_0);
      }
    }f1{};
    f1.l_0=f0.l_tfuncs->m_All();
    for(;!f1.l_0.m_AtEnd();f1.l_0.m_Bump()){
      struct f2_t : public bbGCFrame{
        t_mx2_FuncValue* l_tfunc{};
        void gcMark(){
          bbGCMarkPtr(l_tfunc);
        }
      }f2{};
      f2.l_tfunc=f1.l_0.m_Current();
      try{
        struct f3_t : public bbGCFrame{
          t_mx2_FuncValue* l_func{};
          void gcMark(){
            bbGCMarkPtr(l_func);
          }
        }f3{};
        f3.l_func=bb_object_cast<t_mx2_FuncValue*>(f2.l_tfunc->m_Semant());
        if(!bbBool(f3.l_func)){
          continue;
        }
        if(!f3.l_func->m_block->m_IsGeneric()){
          struct f4_t : public bbGCFrame{
            t_mx2_FuncValue* l_func2{};
            void gcMark(){
              bbGCMarkPtr(l_func2);
            }
          }f4{};
          f4.l_func2=this->m_FindFunc(f3.l_func->m_ftype->m_argTypes);
          if(bbBool(f4.l_func2)){
            throw bbGCNew<t_mx2_SemantEx>(((BB_T("Duplicate declaration '")+f3.l_func->m_ToString())+BB_T("'")),f2.l_tfunc->m_pnode);
          }
        }
        this->m_funcs->m_Push(f3.l_func);
      }catch(t_mx2_SemantEx* ex){
        struct f3_t : public bbGCFrame{
          t_mx2_SemantEx* l_ex{};
          void gcMark(){
            bbGCMarkPtr(l_ex);
          }
        }f3{};
        f3.l_ex=ex;
      }
    }
  }
  return ((t_mx2_SNode*)(this));
}

t_mx2_FuncListType* t_mx2_FuncList::m_GenFuncListType(bbArray<bbGCVar<t_mx2_Type>>* l_types){
  struct f0_t : public bbGCFrame{
    t_mx2_FuncListType* l_inst{};
    void gcMark(){
      bbGCMarkPtr(l_inst);
    }
  }f0{};
  {
    struct f1_t : public bbGCFrame{
      t_std_collections_Stack_1Tt_mx2_FuncListType_2_Iterator l_0{};
      void gcMark(){
        bbGCMark(l_0);
      }
    }f1{};
    f1.l_0=this->m_instances->m_All();
    for(;!f1.l_0.m_AtEnd();f1.l_0.m_Bump()){
      struct f2_t : public bbGCFrame{
        t_mx2_FuncListType* l_inst{};
        void gcMark(){
          bbGCMarkPtr(l_inst);
        }
      }f2{};
      f2.l_inst=f1.l_0.m_Current();
      if(g_mx2_TypesEqual(f2.l_inst->m_types,l_types)){
        return f2.l_inst;
      }
    }
  }
  f0.l_inst=bbGCNew<t_mx2_FuncListType>(this,l_types);
  this->m_instances->m_Push(f0.l_inst);
  f0.l_inst->m_Semant();
  return f0.l_inst;
}

t_mx2_FuncValue* t_mx2_FuncList::m_FindFunc(bbArray<bbGCVar<t_mx2_Type>>* l_argTypes){
  if(g_mx2_AnyTypeGeneric(l_argTypes)){
    g_mx2_SemantError(BB_T("FuncList.FindFunc()"));
  }
  {
    struct f1_t : public bbGCFrame{
      t_std_collections_Stack_1Tt_mx2_FuncValue_2_Iterator l_0{};
      void gcMark(){
        bbGCMark(l_0);
      }
    }f1{};
    f1.l_0=this->m_funcs->m_All();
    for(;!f1.l_0.m_AtEnd();f1.l_0.m_Bump()){
      struct f2_t : public bbGCFrame{
        t_mx2_FuncValue* l_func{};
        void gcMark(){
          bbGCMarkPtr(l_func);
        }
      }f2{};
      f2.l_func=f1.l_0.m_Current();
      if(f2.l_func->m_block->m_IsGeneric()){
        continue;
      }
      if(g_mx2_TypesEqual(f2.l_func->m_ftype->m_argTypes,l_argTypes)){
        return f2.l_func;
      }
    }
  }
  return ((t_mx2_FuncValue*)0);
}

void t_mx2_FuncDecl::gcMark(){
  t_mx2_Decl::gcMark();
  bbGCMark(m_genArgs);
  bbGCMark(m_type);
  bbGCMark(m_whereExpr);
  bbGCMark(m_stmts);
}

bbString t_mx2_FuncDecl::m_ToString(){
  bbString l_str=t_mx2_Decl::m_ToString();
  if(bbBool(this->m_genArgs)){
    l_str+=((BB_T("<")+BB_T(",").join(this->m_genArgs))+BB_T(">"));
  }
  return ((l_str+BB_T(":"))+this->m_type->m_ToString());
}

t_mx2_SNode* t_mx2_FuncDecl::m_ToNode(t_mx2_Scope* l_scope){
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
  return ((t_mx2_SNode*)(bbGCNew<t_mx2_FuncValue>(this,l_scope,f0.l_types,((t_mx2_FuncValue*)0))));
}

void t_mx2_FuncDecl::m_Emit(t_std_collections_Stack_1s* l_buf,bbString l_spc){
  l_buf->m_Push((l_spc+this->m_ToString()));
  g_mx2_EmitStmts(this->m_stmts,l_buf,l_spc);
  l_buf->m_Push((l_spc+BB_T("End")));
}

void t_mx2_MemberFuncValue::gcMark(){
  t_mx2_Value::gcMark();
  bbGCMark(m_instance);
  bbGCMark(m_member);
}

t_mx2_MemberFuncValue::t_mx2_MemberFuncValue(t_mx2_Value* l_instance,t_mx2_FuncValue* l_member){
  this->m_type=l_member->m_type;
  this->m_instance=l_instance;
  this->m_member=l_member;
}

bbString t_mx2_MemberFuncValue::m_ToString(){
  return ((this->m_instance->m_ToString()+BB_T("."))+this->m_member->m_ToString());
}

bbBool t_mx2_MemberFuncValue::m_HasSideEffects(){
  return this->m_instance->m_HasSideEffects();
}

void t_mx2_MemberFuncValue::m_CheckAccess(t_mx2_Scope* l_tscope){
  this->m_member->m_CheckAccess(l_tscope);
}

void t_mx2_FuncListValue::gcMark(){
  t_mx2_Value::gcMark();
  bbGCMark(m_flistType);
  bbGCMark(m_instance);
}

t_mx2_FuncListValue::t_mx2_FuncListValue(t_mx2_FuncListType* l_flistType,t_mx2_Value* l_instance){
  this->m_type=((t_mx2_Type*)(l_flistType));
  this->m_flistType=l_flistType;
  this->m_instance=l_instance;
}

t_mx2_Value* t_mx2_FuncListValue::m_UpCast(t_mx2_Type* l_type){
  struct f0_t : public bbGCFrame{
    t_mx2_FuncType* l_ftype{};
    t_mx2_FuncValue* l_func{};
    void gcMark(){
      bbGCMarkPtr(l_ftype);
      bbGCMarkPtr(l_func);
    }
  }f0{};
  f0.l_ftype=g_mx2_TCast_1Tt_mx2_FuncType_2(l_type);
  if(!bbBool(f0.l_ftype)){
    throw bbGCNew<t_mx2_UpCastEx>(((t_mx2_Value*)(this)),l_type);
  }
  f0.l_func=this->m_flistType->m_FindOverload(f0.l_ftype->m_retType,f0.l_ftype->m_argTypes);
  if(!bbBool(f0.l_func)){
    throw bbGCNew<t_mx2_OverloadEx>(((t_mx2_Value*)(this)),f0.l_ftype->m_argTypes);
  }
  if(!f0.l_func->m_ftype->m_Equals(((t_mx2_Type*)(f0.l_ftype)))){
    throw bbGCNew<t_mx2_UpCastEx>(((t_mx2_Value*)(this)),l_type);
  }
  return f0.l_func->m_ToValue(this->m_instance);
}

bbString t_mx2_FuncListValue::m_ToString(){
  bbString l_args=g_mx2_Join_1Tt_mx2_Type_2(this->m_flistType->m_types,BB_T(","));
  if(bbBool(l_args)){
    l_args=((BB_T("<")+l_args)+BB_T(">"));
  }
  return ((this->m_flistType->m_flist->m_ident+l_args)+BB_T("(...)"));
}

t_mx2_Value* t_mx2_FuncListValue::m_ToRValue(){
  struct f0_t : public bbGCFrame{
    t_mx2_FuncValue* l_func{};
    void gcMark(){
      bbGCMarkPtr(l_func);
    }
  }f0{};
  if((this->m_flistType->m_funcs->m_Length()>1)){
    throw bbGCNew<t_mx2_SemantEx>(((BB_T("Value '")+this->m_ToString())+BB_T("' is overloaded")));
  }
  f0.l_func=this->m_flistType->m_funcs->m__idx(bbInt(0));
  if(f0.l_func->m_IsGeneric()){
    throw bbGCNew<t_mx2_SemantEx>(((BB_T("Value '")+this->m_ToString())+BB_T("' is generic")));
  }
  return f0.l_func->m_ToValue(this->m_instance);
}

t_mx2_Value* t_mx2_FuncListValue::m_Invoke(bbArray<bbGCVar<t_mx2_Value>>* l_args){
  struct f0_t : public bbGCFrame{
    t_mx2_FuncValue* l_func{};
    t_mx2_Value* l_value{};
    bbArray<bbGCVar<t_mx2_Type>>* t0{};
    bbArray<bbGCVar<t_mx2_Value>>* t1{};
    void gcMark(){
      bbGCMarkPtr(l_func);
      bbGCMarkPtr(l_value);
      bbGCMarkPtr(t0);
      bbGCMarkPtr(t1);
    }
  }f0{};
  f0.l_func=this->m_flistType->m_FindOverload(((t_mx2_Type*)0),f0.t0=g_mx2_Types(l_args));
  if(!bbBool(f0.l_func)){
    struct f1_t : public bbGCFrame{
      bbArray<bbGCVar<t_mx2_Type>>* t0{};
      void gcMark(){
        bbGCMarkPtr(t0);
      }
    }f1{};
    throw bbGCNew<t_mx2_OverloadEx>(((t_mx2_Value*)(this)),f1.t0=g_mx2_Types(l_args));
  }
  f0.l_value=f0.l_func->m_ToValue(this->m_instance);
  f0.l_value=f0.l_value->m_Invoke(f0.t1=f0.l_func->m_FixArgs(l_args));
  return f0.l_value;
}

t_mx2_Value* t_mx2_FuncListValue::m_GenInstance(bbArray<bbGCVar<t_mx2_Type>>* l_types){
  struct f0_t : public bbGCFrame{
    t_mx2_FuncListType* l_flistType{};
    void gcMark(){
      bbGCMarkPtr(l_flistType);
    }
  }f0{};
  f0.l_flistType=this->m_flistType->m_flist->m_GenFuncListType(l_types);
  return ((t_mx2_Value*)(bbGCNew<t_mx2_FuncListValue>(f0.l_flistType,this->m_instance)));
}

void t_mx2_FuncListType::gcMark(){
  t_mx2_Type::gcMark();
  bbGCMark(m_flist);
  bbGCMark(m_funcs);
  bbGCMark(m_types);
}

t_mx2_FuncListType::t_mx2_FuncListType(t_mx2_FuncList* l_flist,bbArray<bbGCVar<t_mx2_Type>>* l_types){
  this->m_flist=l_flist;
  this->m_funcs=bbGCNew<t_std_collections_Stack_1Tt_mx2_FuncValue_2>();
  this->m_types=l_types;
  {
    struct f1_t : public bbGCFrame{
      t_std_collections_Stack_1Tt_mx2_FuncValue_2_Iterator l_0{};
      void gcMark(){
        bbGCMark(l_0);
      }
    }f1{};
    f1.l_0=l_flist->m_funcs->m_All();
    for(;!f1.l_0.m_AtEnd();f1.l_0.m_Bump()){
      struct f2_t : public bbGCFrame{
        t_mx2_FuncValue* l_func{};
        t_mx2_FuncValue* l_func2{};
        void gcMark(){
          bbGCMarkPtr(l_func);
          bbGCMarkPtr(l_func2);
        }
      }f2{};
      f2.l_func=f1.l_0.m_Current();
      f2.l_func2=f2.l_func->m_TryGenInstance(l_types);
      if(bbBool(f2.l_func2)){
        this->m_funcs->m_Push(f2.l_func2);
      }
    }
  }
}

t_mx2_FuncListType::t_mx2_FuncListType(t_mx2_FuncList* l_flist){
  this->m_flist=l_flist;
  this->m_funcs=l_flist->m_funcs;
}

bbString t_mx2_FuncListType::m_TypeId(){
  g_mx2_SemantError(BB_T("FuncListType.TypeId()"));
  return bbString{};
}

t_mx2_Value* t_mx2_FuncListType::m_ToValue(t_mx2_Value* l_instance){
  g_mx2_SemantError(BB_T("FuncListType.ToValue()"));
  return ((t_mx2_Value*)0);
}

bbString t_mx2_FuncListType::m_ToString(){
  bbString l_str=bbString{};
  if(bbBool(this->m_types)){
    l_str=((BB_T("<")+g_mx2_Join_1Tt_mx2_Type_2(this->m_types,BB_T(",")))+BB_T(">"));
  }
  return ((this->m_flist->m_ident+l_str)+BB_T("(...)"));
}

bbString t_mx2_FuncListType::m_Name(){
  return BB_T("{FuncListType}");
}

t_mx2_FuncValue* t_mx2_FuncListType::m_FindOverload(t_mx2_Type* l_ret,bbArray<bbGCVar<t_mx2_Type>>* l_args){
  return g_mx2_overload_FindOverload(this->m_funcs,l_ret,l_args);
}

bbInt t_mx2_FuncListType::m_DistanceToType(t_mx2_Type* l_type){
  struct f0_t : public bbGCFrame{
    t_mx2_FuncType* l_ftype{};
    t_mx2_FuncValue* l_func{};
    void gcMark(){
      bbGCMarkPtr(l_ftype);
      bbGCMarkPtr(l_func);
    }
  }f0{};
  f0.l_ftype=g_mx2_TCast_1Tt_mx2_FuncType_2(l_type);
  if(!bbBool(f0.l_ftype)){
    return -1;
  }
  f0.l_func=this->m_FindOverload(f0.l_ftype->m_retType,f0.l_ftype->m_argTypes);
  if(bbBool(f0.l_func)){
    return f0.l_func->m_ftype->m_DistanceToType(((t_mx2_Type*)(f0.l_ftype)));
  }
  return -1;
}

void mx2_mx2cc_func_init(){
  static bool done;
  if(done) return;
  done=true;
}

bbInit mx2_mx2cc_func_init_v("mx2cc_func",&mx2_mx2cc_func_init);
