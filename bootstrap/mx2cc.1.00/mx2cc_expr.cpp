
#include "mx2cc_expr.h"

// ***** External *****

#include "../../../../../modules/monkey/monkey.buildv1.0.0/desktop_release_linux/monkey_debug.h"
#include "../../../../../modules/monkey/monkey.buildv1.0.0/desktop_release_linux/monkey_types.h"
#include "mx2cc_class.h"
#include "mx2cc_decl.h"
#include "mx2cc_enum.h"
#include "mx2cc_errors.h"
#include "mx2cc_func.h"
#include "mx2cc_scope.h"
#include "mx2cc_std_collections_2stack.h"
#include "mx2cc_type.h"
#include "mx2cc_typeexpr.h"
#include "mx2cc_value.h"

extern bbInt g_mx2_TOKE_0INTLIT;
extern bbInt g_mx2_TOKE_0FLOATLIT;
extern bbInt g_mx2_TOKE_0STRINGLIT;
extern bbInt g_mx2_TOKE_0KEYWORD;
extern bbInt g_mx2_CHAR_0DOLLAR;

extern bbString g_mx2_Join_1Tt_mx2_Expr_2(bbArray<bbGCVar<t_mx2_Expr>>* l_bits,bbString l_sep);
extern bbArray<bbGCVar<t_mx2_Value>>* g_mx2_SemantArgs(bbArray<bbGCVar<t_mx2_Expr>>* l_exprs,t_mx2_Scope* l_scope);
extern bbString g_mx2_Join_1Tt_mx2_TypeExpr_2(bbArray<bbGCVar<t_mx2_TypeExpr>>* l_bits,bbString l_sep);
extern bbString g_mx2_Join_1Tt_mx2_Value_2(bbArray<bbGCVar<t_mx2_Value>>* l_bits,bbString l_sep);
extern bbArray<bbGCVar<t_mx2_Value>>* g_mx2_UpCast(bbArray<bbGCVar<t_mx2_Value>>* l_args,t_mx2_Type* l_type);
extern bbArray<bbGCVar<t_mx2_Value>>* g_mx2_SemantRValues(bbArray<bbGCVar<t_mx2_Expr>>* l_exprs,t_mx2_Scope* l_scope);
extern t_mx2_Value* g_mx2_EvalUnaryop(t_mx2_Type* l_type,bbString l_op,t_mx2_Value* l_arg);
extern t_mx2_Value* g_mx2_EvalBinaryop(t_mx2_Type* l_type,bbString l_op,t_mx2_Value* l_lhs,t_mx2_Value* l_rhs);
extern bbString g_mx2_DequoteMx2String(bbString l_str);

// ***** Internal *****

t_mx2_Type* g_mx2_BinaryopExpr_BalanceTypes(t_mx2_Type* l_lhs,t_mx2_Type* l_rhs){
  struct f0_t : public bbGCFrame{
    t_mx2_PrimType* l_plhs{};
    t_mx2_PrimType* l_prhs{};
    void gcMark(){
      bbGCMarkPtr(l_plhs);
      bbGCMarkPtr(l_prhs);
    }
  }f0{};
  f0.l_plhs=g_mx2_TCast_1Tt_mx2_PrimType_2(l_lhs);
  f0.l_prhs=g_mx2_TCast_1Tt_mx2_PrimType_2(l_rhs);
  if((bbBool(f0.l_plhs)&&bbBool(f0.l_prhs))){
    return g_mx2_BinaryopExpr_BalancePrimTypes(f0.l_plhs,f0.l_prhs);
  }
  if((l_lhs->m_DistanceToType(l_rhs)>=bbInt(0))){
    return l_rhs;
  }
  if((l_rhs->m_DistanceToType(l_lhs)>=bbInt(0))){
    return l_lhs;
  }
  throw bbGCNew<t_mx2_SemantEx>(((((BB_T("Types '")+l_lhs->m_Name())+BB_T("' and '"))+l_rhs->m_Name())+BB_T("' are incompatible")));
}

t_mx2_Type* g_mx2_BinaryopExpr_BalancePrimTypes(t_mx2_PrimType* l_lhs,t_mx2_PrimType* l_rhs){
  if((!bbBool(l_lhs)||!bbBool(l_rhs))){
    throw bbGCNew<t_mx2_SemantEx>(BB_T("Types must be primitive"));
  }
  if((l_lhs->m__eq(((t_mx2_Type*)(g_mx2_Type_StringType)))||l_rhs->m__eq(((t_mx2_Type*)(g_mx2_Type_StringType))))){
    return ((t_mx2_Type*)(g_mx2_Type_StringType));
  }
  return g_mx2_BinaryopExpr_BalanceNumericTypes(l_lhs,l_rhs);
}

t_mx2_Type* g_mx2_BinaryopExpr_BalanceNumericTypes(t_mx2_PrimType* l_lhs,t_mx2_PrimType* l_rhs){
  if((((!bbBool(l_lhs)||!bbBool(l_rhs))||!l_lhs->m_IsNumeric())||!l_rhs->m_IsNumeric())){
    throw bbGCNew<t_mx2_SemantEx>(BB_T("Types must be numeric"));
  }
  if((l_lhs->m__eq(((t_mx2_Type*)(g_mx2_Type_DoubleType)))||l_rhs->m__eq(((t_mx2_Type*)(g_mx2_Type_DoubleType))))){
    return ((t_mx2_Type*)(g_mx2_Type_DoubleType));
  }
  if((l_lhs->m__eq(((t_mx2_Type*)(g_mx2_Type_FloatType)))||l_rhs->m__eq(((t_mx2_Type*)(g_mx2_Type_FloatType))))){
    return ((t_mx2_Type*)(g_mx2_Type_FloatType));
  }
  return g_mx2_BinaryopExpr_BalanceIntegralTypes(l_lhs,l_rhs);
}

t_mx2_Type* g_mx2_BinaryopExpr_BalanceIntegralTypes(t_mx2_PrimType* l_lhs,t_mx2_PrimType* l_rhs){
  if((((!bbBool(l_lhs)||!bbBool(l_rhs))||!l_lhs->m_IsIntegral())||!l_rhs->m_IsIntegral())){
    throw bbGCNew<t_mx2_SemantEx>(BB_T("Types must be integral"));
  }
  if((l_lhs->m__eq(((t_mx2_Type*)(g_mx2_Type_ULongType)))||l_rhs->m__eq(((t_mx2_Type*)(g_mx2_Type_ULongType))))){
    return ((t_mx2_Type*)(g_mx2_Type_ULongType));
  }
  if((l_lhs->m__eq(((t_mx2_Type*)(g_mx2_Type_LongType)))||l_rhs->m__eq(((t_mx2_Type*)(g_mx2_Type_LongType))))){
    return ((t_mx2_Type*)(g_mx2_Type_LongType));
  }
  if((l_lhs->m_IsUnsignedIntegral()||l_rhs->m_IsUnsignedIntegral())){
    return ((t_mx2_Type*)(g_mx2_Type_UIntType));
  }
  return ((t_mx2_Type*)(g_mx2_Type_IntType));
}

t_mx2_Expr::t_mx2_Expr(bbInt l_srcpos,bbInt l_endpos):t_mx2_PNode(l_srcpos,l_endpos){
}

t_mx2_Value* t_mx2_Expr::m_TrySemantRValue(t_mx2_Scope* l_scope,t_mx2_Type* l_type){
  try{
    return this->m_SemantRValue(l_scope,l_type);
  }catch(t_mx2_SemantEx* ex){
    struct f1_t : public bbGCFrame{
      t_mx2_SemantEx* l_ex{};
      void gcMark(){
        bbGCMarkPtr(l_ex);
      }
    }f1{};
    f1.l_ex=ex;
  }
  return ((t_mx2_Value*)0);
}

bbBool t_mx2_Expr::m_SemantWhere(t_mx2_Scope* l_scope){
  try{
    g_mx2_PNode_semanting->m_Push(((t_mx2_PNode*)(this)));
    bbBool l_twhere=this->m_OnSemantWhere(l_scope);
    g_mx2_PNode_semanting->m_Pop();
    return l_twhere;
  }catch(t_mx2_SemantEx* ex){
    struct f1_t : public bbGCFrame{
      t_mx2_SemantEx* l_ex{};
      void gcMark(){
        bbGCMarkPtr(l_ex);
      }
    }f1{};
    f1.l_ex=ex;
    g_mx2_PNode_semanting->m_Pop();
    throw f1.l_ex;
  }
  return false;
}

t_mx2_Type* t_mx2_Expr::m_SemantType(t_mx2_Scope* l_scope,bbBool l_generic){
  try{
    struct f1_t : public bbGCFrame{
      t_mx2_ClassType* l_ctype{};
      t_mx2_Type* l_type{};
      void gcMark(){
        bbGCMarkPtr(l_ctype);
        bbGCMarkPtr(l_type);
      }
    }f1{};
    g_mx2_PNode_semanting->m_Push(((t_mx2_PNode*)(this)));
    f1.l_type=this->m_OnSemantType(l_scope);
    f1.l_ctype=g_mx2_TCast_1Tt_mx2_ClassType_2(f1.l_type);
    if(bbBool(f1.l_ctype)){
      if(l_generic){
      }else{
        if((bbBool(f1.l_ctype->m_types)&&!bbBool(f1.l_ctype->m_instanceOf))){
          throw bbGCNew<t_mx2_SemantEx>(((BB_T("Type '")+f1.l_ctype->m_ToString())+BB_T("' is generic")));
        }
      }
    }
    g_mx2_PNode_semanting->m_Pop();
    return f1.l_type;
  }catch(t_mx2_SemantEx* ex){
    struct f1_t : public bbGCFrame{
      t_mx2_SemantEx* l_ex{};
      void gcMark(){
        bbGCMarkPtr(l_ex);
      }
    }f1{};
    f1.l_ex=ex;
    g_mx2_PNode_semanting->m_Pop();
    throw f1.l_ex;
  }
  return ((t_mx2_Type*)0);
}

t_mx2_Value* t_mx2_Expr::m_SemantRValue(t_mx2_Scope* l_scope,t_mx2_Type* l_type){
  try{
    struct f1_t : public bbGCFrame{
      t_mx2_Value* l_rvalue{};
      t_mx2_Value* l_value{};
      void gcMark(){
        bbGCMarkPtr(l_rvalue);
        bbGCMarkPtr(l_value);
      }
    }f1{};
    g_mx2_PNode_semanting->m_Push(((t_mx2_PNode*)(this)));
    f1.l_value=this->m_OnSemant(l_scope);
    if(bbBool(l_type)){
      f1.l_rvalue=f1.l_value->m_UpCast(l_type);
    }else{
      f1.l_rvalue=f1.l_value->m_ToRValue();
    }
    f1.l_rvalue->m_CheckAccess(l_scope);
    g_mx2_PNode_semanting->m_Pop();
    return f1.l_rvalue;
  }catch(t_mx2_SemantEx* ex){
    struct f1_t : public bbGCFrame{
      t_mx2_SemantEx* l_ex{};
      void gcMark(){
        bbGCMarkPtr(l_ex);
      }
    }f1{};
    f1.l_ex=ex;
    g_mx2_PNode_semanting->m_Pop();
    throw f1.l_ex;
  }
  return ((t_mx2_Value*)0);
}

t_mx2_Value* t_mx2_Expr::m_Semant(t_mx2_Scope* l_scope){
  try{
    struct f1_t : public bbGCFrame{
      t_mx2_Value* l_value{};
      void gcMark(){
        bbGCMarkPtr(l_value);
      }
    }f1{};
    g_mx2_PNode_semanting->m_Push(((t_mx2_PNode*)(this)));
    f1.l_value=this->m_OnSemant(l_scope);
    f1.l_value->m_CheckAccess(l_scope);
    g_mx2_PNode_semanting->m_Pop();
    return f1.l_value;
  }catch(t_mx2_SemantEx* ex){
    struct f1_t : public bbGCFrame{
      t_mx2_SemantEx* l_ex{};
      void gcMark(){
        bbGCMarkPtr(l_ex);
      }
    }f1{};
    f1.l_ex=ex;
    g_mx2_PNode_semanting->m_Pop();
    throw f1.l_ex;
  }
  return ((t_mx2_Value*)0);
}

bbBool t_mx2_Expr::m_OnSemantWhere(t_mx2_Scope* l_scope){
  throw bbGCNew<t_mx2_SemantEx>(BB_T("Invalid 'Where' expression"));
}

t_mx2_Type* t_mx2_Expr::m_OnSemantType(t_mx2_Scope* l_scope){
  throw bbGCNew<t_mx2_SemantEx>(BB_T("Invalid type expression"));
}

t_mx2_Value* t_mx2_Expr::m_OnSemant(t_mx2_Scope* l_scope){
  throw bbGCNew<t_mx2_SemantEx>(BB_T("OnSemant TODO!"));
}

void t_mx2_ValueExpr::gcMark(){
  t_mx2_Expr::gcMark();
  bbGCMark(m_value);
}

t_mx2_ValueExpr::t_mx2_ValueExpr(t_mx2_Value* l_value,bbInt l_srcpos,bbInt l_endpos):t_mx2_Expr(l_srcpos,l_endpos){
  this->m_value=l_value;
}

t_mx2_Value* t_mx2_ValueExpr::m_OnSemant(t_mx2_Scope* l_scope){
  return this->m_value;
}

t_mx2_IdentExpr::t_mx2_IdentExpr(bbString l_ident,bbInt l_srcpos,bbInt l_endpos):t_mx2_Expr(l_srcpos,l_endpos){
  this->m_ident=l_ident;
}

bbString t_mx2_IdentExpr::m_ToString(){
  return this->m_ident;
}

t_mx2_Type* t_mx2_IdentExpr::m_OnSemantType(t_mx2_Scope* l_scope){
  struct f0_t : public bbGCFrame{
    t_mx2_Type* l_type{};
    void gcMark(){
      bbGCMarkPtr(l_type);
    }
  }f0{};
  f0.l_type=l_scope->m_FindType(this->m_ident);
  if(!bbBool(f0.l_type)){
    throw bbGCNew<t_mx2_SemantEx>(((BB_T("Type '")+this->m_ident)+BB_T("' not found")));
  }
  return f0.l_type;
}

t_mx2_Value* t_mx2_IdentExpr::m_OnSemant(t_mx2_Scope* l_scope){
  struct f0_t : public bbGCFrame{
    t_mx2_Value* l_value{};
    void gcMark(){
      bbGCMarkPtr(l_value);
    }
  }f0{};
  f0.l_value=l_scope->m_FindValue(this->m_ident);
  if(bbBool(f0.l_value)){
    return f0.l_value;
  }
  throw bbGCNew<t_mx2_SemantEx>(((BB_T("Identifier '")+this->m_ident)+BB_T("' not found")));
}

void t_mx2_MemberExpr::gcMark(){
  t_mx2_Expr::gcMark();
  bbGCMark(m_expr);
}

t_mx2_MemberExpr::t_mx2_MemberExpr(t_mx2_Expr* l_expr,bbString l_ident,bbInt l_srcpos,bbInt l_endpos):t_mx2_Expr(l_srcpos,l_endpos){
  this->m_expr=l_expr;
  this->m_ident=l_ident;
}

bbString t_mx2_MemberExpr::m_ToString(){
  return ((this->m_expr->m_ToString()+BB_T("."))+this->m_ident);
}

t_mx2_Type* t_mx2_MemberExpr::m_OnSemantType(t_mx2_Scope* l_scope){
  struct f0_t : public bbGCFrame{
    t_mx2_Type* l_type{};
    t_mx2_Type* l_type2{};
    void gcMark(){
      bbGCMarkPtr(l_type);
      bbGCMarkPtr(l_type2);
    }
  }f0{};
  f0.l_type=this->m_expr->m_SemantType(l_scope,false);
  f0.l_type2=f0.l_type->m_FindType(this->m_ident);
  if(!bbBool(f0.l_type2)){
    throw bbGCNew<t_mx2_SemantEx>(((((BB_T("Type '")+f0.l_type->m_Name())+BB_T("' has no member type named '"))+this->m_ident)+BB_T("'")));
  }
  return f0.l_type2;
}

t_mx2_Value* t_mx2_MemberExpr::m_OnSemant(t_mx2_Scope* l_scope){
  struct f0_t : public bbGCFrame{
    t_mx2_TypeValue* l_tv{};
    t_mx2_Value* l_tvalue{};
    t_mx2_Value* l_value{};
    void gcMark(){
      bbGCMarkPtr(l_tv);
      bbGCMarkPtr(l_tvalue);
      bbGCMarkPtr(l_value);
    }
  }f0{};
  f0.l_value=this->m_expr->m_SemantRValue(l_scope,((t_mx2_Type*)0));
  f0.l_tvalue=f0.l_value->m_FindValue(this->m_ident);
  if(bbBool(f0.l_tvalue)){
    return f0.l_tvalue;
  }
  f0.l_tv=bb_object_cast<t_mx2_TypeValue*>(f0.l_value);
  if(bbBool(f0.l_tv)){
    throw bbGCNew<t_mx2_SemantEx>(((((BB_T("Type '")+f0.l_tv->m_ttype->m_Name())+BB_T("' has no member named '"))+this->m_ident)+BB_T("'")));
  }
  throw bbGCNew<t_mx2_SemantEx>(((((BB_T("Value of type '")+f0.l_value->m_type->m_Name())+BB_T("' has no member named '"))+this->m_ident)+BB_T("'")));
}

void t_mx2_InvokeExpr::gcMark(){
  t_mx2_Expr::gcMark();
  bbGCMark(m_expr);
  bbGCMark(m_args);
}

t_mx2_InvokeExpr::t_mx2_InvokeExpr(t_mx2_Expr* l_expr,bbArray<bbGCVar<t_mx2_Expr>>* l_args,bbInt l_srcpos,bbInt l_endpos):t_mx2_Expr(l_srcpos,l_endpos){
  this->m_expr=l_expr;
  this->m_args=l_args;
}

bbString t_mx2_InvokeExpr::m_ToString(){
  return (((this->m_expr->m_ToString()+BB_T("("))+g_mx2_Join_1Tt_mx2_Expr_2(this->m_args,BB_T(",")))+BB_T(")"));
}

t_mx2_Value* t_mx2_InvokeExpr::m_OnSemant(t_mx2_Scope* l_scope){
  struct f0_t : public bbGCFrame{
    bbArray<bbGCVar<t_mx2_Value>>* l_args{};
    t_mx2_Value* l_ivalue{};
    t_mx2_Value* l_value{};
    void gcMark(){
      bbGCMarkPtr(l_args);
      bbGCMarkPtr(l_ivalue);
      bbGCMarkPtr(l_value);
    }
  }f0{};
  f0.l_args=g_mx2_SemantArgs(this->m_args,l_scope);
  f0.l_value=this->m_expr->m_Semant(l_scope);
  f0.l_ivalue=f0.l_value->m_Invoke(f0.l_args);
  return f0.l_ivalue;
}

void t_mx2_GenericExpr::gcMark(){
  t_mx2_Expr::gcMark();
  bbGCMark(m_expr);
  bbGCMark(m_types);
}

t_mx2_GenericExpr::t_mx2_GenericExpr(t_mx2_Expr* l_expr,bbArray<bbGCVar<t_mx2_TypeExpr>>* l_types,bbInt l_srcpos,bbInt l_endpos):t_mx2_Expr(l_srcpos,l_endpos){
  this->m_expr=l_expr;
  this->m_types=l_types;
}

bbString t_mx2_GenericExpr::m_ToString(){
  return (((this->m_expr->m_ToString()+BB_T("<"))+g_mx2_Join_1Tt_mx2_TypeExpr_2(this->m_types,BB_T(",")))+BB_T(">"));
}

t_mx2_Type* t_mx2_GenericExpr::m_OnSemantType(t_mx2_Scope* l_scope){
  struct f0_t : public bbGCFrame{
    t_mx2_Type* l_type{};
    bbArray<bbGCVar<t_mx2_Type>>* l_types{};
    void gcMark(){
      bbGCMarkPtr(l_type);
      bbGCMarkPtr(l_types);
    }
  }f0{};
  f0.l_types=g_mx2_SemantTypes(this->m_types,l_scope);
  f0.l_type=this->m_expr->m_SemantType(l_scope,true);
  return f0.l_type->m_GenInstance(f0.l_types);
}

t_mx2_Value* t_mx2_GenericExpr::m_OnSemant(t_mx2_Scope* l_scope){
  struct f0_t : public bbGCFrame{
    t_mx2_TypeValue* l_tvalue{};
    bbArray<bbGCVar<t_mx2_Type>>* l_types{};
    t_mx2_Value* l_value{};
    void gcMark(){
      bbGCMarkPtr(l_tvalue);
      bbGCMarkPtr(l_types);
      bbGCMarkPtr(l_value);
    }
  }f0{};
  f0.l_types=g_mx2_SemantTypes(this->m_types,l_scope);
  f0.l_value=this->m_expr->m_Semant(l_scope);
  f0.l_tvalue=bb_object_cast<t_mx2_TypeValue*>(f0.l_value);
  if(bbBool(f0.l_tvalue)){
    struct f1_t : public bbGCFrame{
      t_mx2_Type* t0{};
      void gcMark(){
        bbGCMarkPtr(t0);
      }
    }f1{};
    return ((t_mx2_Value*)(bbGCNew<t_mx2_TypeValue>(f1.t0=f0.l_tvalue->m_ttype->m_GenInstance(f0.l_types))));
  }
  return f0.l_value->m_GenInstance(f0.l_types);
}

void t_mx2_NewObjectExpr::gcMark(){
  t_mx2_Expr::gcMark();
  bbGCMark(m_type);
  bbGCMark(m_args);
}

t_mx2_NewObjectExpr::t_mx2_NewObjectExpr(t_mx2_TypeExpr* l_type,bbArray<bbGCVar<t_mx2_Expr>>* l_args,bbInt l_srcpos,bbInt l_endpos):t_mx2_Expr(l_srcpos,l_endpos){
  this->m_type=l_type;
  this->m_args=l_args;
}

bbString t_mx2_NewObjectExpr::m_ToString(){
  bbString l_str=(BB_T("New ")+this->m_type->m_ToString());
  if(bbBool(this->m_args)){
    l_str+=((BB_T("(")+g_mx2_Join_1Tt_mx2_Expr_2(this->m_args,BB_T(",")))+BB_T(")"));
  }
  return l_str;
}

t_mx2_Value* t_mx2_NewObjectExpr::m_OnSemant(t_mx2_Scope* l_scope){
  struct f0_t : public bbGCFrame{
    bbArray<bbGCVar<t_mx2_Value>>* l_args{};
    t_mx2_SNode* l_ctor{};
    t_mx2_FuncValue* l_ctorFunc{};
    t_mx2_ClassType* l_ctype{};
    t_mx2_Type* l_type{};
    void gcMark(){
      bbGCMarkPtr(l_args);
      bbGCMarkPtr(l_ctor);
      bbGCMarkPtr(l_ctorFunc);
      bbGCMarkPtr(l_ctype);
      bbGCMarkPtr(l_type);
    }
  }f0{};
  f0.l_type=this->m_type->m_Semant(l_scope,false);
  f0.l_ctype=g_mx2_TCast_1Tt_mx2_ClassType_2(f0.l_type);
  if(!bbBool(f0.l_ctype)){
    throw bbGCNew<t_mx2_SemantEx>(((BB_T("Type '")+f0.l_type->m_Name())+BB_T("' is not a class")));
  }
  if(f0.l_ctype->m_IsGeneric()){
    throw bbGCNew<t_mx2_SemantEx>(((BB_T("Class '")+f0.l_ctype->m_Name())+BB_T("' is generic")));
  }
  if(f0.l_ctype->m_IsAbstract()){
    bbString l_t=bbString{};
    {
      bbInt l_0=bbInt(0);
      bbInt l_1=f0.l_ctype->m_abstractMethods->length();
      for(;(l_0<l_1);l_0+=1){
        struct f3_t : public bbGCFrame{
          t_mx2_FuncValue* l_func{};
          void gcMark(){
            bbGCMarkPtr(l_func);
          }
        }f3{};
        f3.l_func=f0.l_ctype->m_abstractMethods->at(l_0);
        if(bbBool(l_t)){
          l_t+=BB_T(",");
        }
        l_t+=f3.l_func->m_ToString();
      }
    }
    if(bbBool(l_t)){
      throw bbGCNew<t_mx2_SemantEx>((((BB_T("Class '")+f0.l_ctype->m_Name())+BB_T("' is abstract due to unimplemented method(s) "))+l_t));
    }
    throw bbGCNew<t_mx2_SemantEx>(((BB_T("Class '")+f0.l_ctype->m_Name())+BB_T("' is abstract")));
  }
  f0.l_args=g_mx2_SemantArgs(this->m_args,l_scope);
  f0.l_ctor=f0.l_ctype->m_FindNode(BB_T("new"));
  if(bbBool(f0.l_ctor)){
    struct f1_t : public bbGCFrame{
      t_mx2_Value* l_ctorValue{};
      t_mx2_InvokeValue* l_invoke{};
      void gcMark(){
        bbGCMarkPtr(l_ctorValue);
        bbGCMarkPtr(l_invoke);
      }
    }f1{};
    f1.l_ctorValue=f0.l_ctor->m_ToValue(((t_mx2_Value*)0));
    f1.l_invoke=bb_object_cast<t_mx2_InvokeValue*>(f1.l_ctorValue->m_Invoke(f0.l_args));
    if(!bbBool(f1.l_invoke)){
      throw bbGCNew<t_mx2_SemantEx>(((((BB_T("Can't invoke class '")+f0.l_ctype->m_Name())+BB_T("' constuctor with arguments '"))+g_mx2_Join_1Tt_mx2_Value_2(f0.l_args,BB_T(",")))+BB_T("'")));
    }
    f0.l_ctorFunc=bb_object_cast<t_mx2_FuncValue*>(f1.l_invoke->m_value);
    if(!bbBool(f0.l_ctorFunc)){
      g_mx2_SemantError(BB_T("NewObjectExpr.OnSemant()"));
    }
    f0.l_ctorFunc->m_CheckAccess(l_scope);
    f0.l_args=f1.l_invoke->m_args;
  }else if(bbBool(f0.l_args)){
    throw bbGCNew<t_mx2_SemantEx>(((BB_T("Class '")+f0.l_type->m_Name())+BB_T("' has no constructors")));
  }
  return ((t_mx2_Value*)(bbGCNew<t_mx2_NewObjectValue>(f0.l_ctype,f0.l_ctorFunc,f0.l_args)));
}

void t_mx2_NewArrayExpr::gcMark(){
  t_mx2_Expr::gcMark();
  bbGCMark(m_type);
  bbGCMark(m_sizes);
  bbGCMark(m_inits);
}

t_mx2_NewArrayExpr::t_mx2_NewArrayExpr(t_mx2_ArrayTypeExpr* l_type,bbArray<bbGCVar<t_mx2_Expr>>* l_sizes,bbArray<bbGCVar<t_mx2_Expr>>* l_inits,bbInt l_srcpos,bbInt l_endpos):t_mx2_Expr(l_srcpos,l_endpos){
  this->m_type=l_type;
  this->m_sizes=l_sizes;
  this->m_inits=l_inits;
}

bbString t_mx2_NewArrayExpr::m_ToString(){
  if(bbBool(this->m_sizes)){
    return ((((BB_T("New ")+this->m_type->m_type->m_ToString())+BB_T("["))+g_mx2_Join_1Tt_mx2_Expr_2(this->m_sizes,BB_T(",")))+BB_T("]"));
  }
  return ((((BB_T("New ")+this->m_type->m_ToString())+BB_T("("))+g_mx2_Join_1Tt_mx2_Expr_2(this->m_inits,BB_T(",")))+BB_T(")"));
}

t_mx2_Value* t_mx2_NewArrayExpr::m_OnSemant(t_mx2_Scope* l_scope){
  struct f0_t : public bbGCFrame{
    t_mx2_ArrayType* l_atype{};
    bbArray<bbGCVar<t_mx2_Value>>* l_inits{};
    bbArray<bbGCVar<t_mx2_Value>>* l_sizes{};
    t_mx2_Type* t0{};
    void gcMark(){
      bbGCMarkPtr(l_atype);
      bbGCMarkPtr(l_inits);
      bbGCMarkPtr(l_sizes);
      bbGCMarkPtr(t0);
    }
  }f0{};
  f0.l_atype=g_mx2_TCast_1Tt_mx2_ArrayType_2(f0.t0=this->m_type->m_Semant(l_scope,false));
  if(!bbBool(f0.l_atype)){
    g_mx2_SemantError(BB_T("NewArrayExpr.OnSemant()"));
  }
  if(f0.l_atype->m_elemType->m_IsGeneric()){
    throw bbGCNew<t_mx2_SemantEx>(((BB_T("Array element type '")+f0.l_atype->m_elemType->m_Name())+BB_T("' is generic")));
  }
  if(bbBool(this->m_inits)){
    if((f0.l_atype->m_rank!=1)){
      throw bbGCNew<t_mx2_SemantEx>(BB_T("Array must be 1 dimensional"));
    }
    f0.l_inits=g_mx2_SemantArgs(this->m_inits,l_scope);
    f0.l_inits=g_mx2_UpCast(f0.l_inits,f0.l_atype->m_elemType);
  }else{
    f0.l_sizes=g_mx2_SemantArgs(this->m_sizes,l_scope);
    f0.l_sizes=g_mx2_UpCast(f0.l_sizes,((t_mx2_Type*)(g_mx2_Type_IntType)));
  }
  return ((t_mx2_Value*)(bbGCNew<t_mx2_NewArrayValue>(f0.l_atype,f0.l_sizes,f0.l_inits)));
}

void t_mx2_IndexExpr::gcMark(){
  t_mx2_Expr::gcMark();
  bbGCMark(m_expr);
  bbGCMark(m_args);
}

t_mx2_IndexExpr::t_mx2_IndexExpr(t_mx2_Expr* l_expr,bbArray<bbGCVar<t_mx2_Expr>>* l_args,bbInt l_srcpos,bbInt l_endpos):t_mx2_Expr(l_srcpos,l_endpos){
  this->m_expr=l_expr;
  this->m_args=l_args;
}

bbString t_mx2_IndexExpr::m_ToString(){
  return (((this->m_expr->m_ToString()+BB_T("["))+g_mx2_Join_1Tt_mx2_Expr_2(this->m_args,BB_T(",")))+BB_T("]"));
}

t_mx2_Value* t_mx2_IndexExpr::m_OnSemant(t_mx2_Scope* l_scope){
  struct f0_t : public bbGCFrame{
    bbArray<bbGCVar<t_mx2_Value>>* l_args{};
    t_mx2_Value* l_value{};
    void gcMark(){
      bbGCMarkPtr(l_args);
      bbGCMarkPtr(l_value);
    }
  }f0{};
  f0.l_value=this->m_expr->m_Semant(l_scope);
  f0.l_args=g_mx2_SemantRValues(this->m_args,l_scope);
  return f0.l_value->m_Index(f0.l_args);
}

void t_mx2_ExtendsExpr::gcMark(){
  t_mx2_Expr::gcMark();
  bbGCMark(m_expr);
  bbGCMark(m_type);
}

t_mx2_ExtendsExpr::t_mx2_ExtendsExpr(bbString l_op,t_mx2_Expr* l_expr,t_mx2_TypeExpr* l_type,bbInt l_srcpos,bbInt l_endpos):t_mx2_Expr(l_srcpos,l_endpos){
  this->m_op=l_op;
  this->m_expr=l_expr;
  this->m_type=l_type;
}

bbBool t_mx2_ExtendsExpr::m_OnSemantWhere(t_mx2_Scope* l_scope){
  struct f0_t : public bbGCFrame{
    t_mx2_ClassType* l_ctype{};
    t_mx2_Type* l_type{};
    t_mx2_Type* t0{};
    void gcMark(){
      bbGCMarkPtr(l_ctype);
      bbGCMarkPtr(l_type);
      bbGCMarkPtr(t0);
    }
  }f0{};
  f0.l_ctype=g_mx2_TCast_1Tt_mx2_ClassType_2(f0.t0=this->m_type->m_Semant(l_scope,false));
  if((!bbBool(f0.l_ctype)||(((f0.l_ctype->m_cdecl->m_kind!=BB_T("class"))&&(f0.l_ctype->m_cdecl->m_kind!=BB_T("interface")))&&(f0.l_ctype->m_cdecl->m_kind!=BB_T("protocol"))))){
    throw bbGCNew<t_mx2_SemantEx>(((BB_T("Type '")+this->m_type->m_ToString())+BB_T("' is not a class or interface type")));
  }
  f0.l_type=this->m_expr->m_SemantType(l_scope,false);
  return f0.l_type->m_ExtendsType(((t_mx2_Type*)(f0.l_ctype)));
}

t_mx2_Value* t_mx2_ExtendsExpr::m_OnSemant(t_mx2_Scope* l_scope){
  struct f0_t : public bbGCFrame{
    t_mx2_ClassType* l_ctype{};
    t_mx2_ExplicitCastValue* l_cvalue{};
    t_mx2_TypeValue* l_tvalue{};
    t_mx2_Value* l_value{};
    t_mx2_Type* t0{};
    void gcMark(){
      bbGCMarkPtr(l_ctype);
      bbGCMarkPtr(l_cvalue);
      bbGCMarkPtr(l_tvalue);
      bbGCMarkPtr(l_value);
      bbGCMarkPtr(t0);
    }
  }f0{};
  f0.l_ctype=g_mx2_TCast_1Tt_mx2_ClassType_2(f0.t0=this->m_type->m_Semant(l_scope,false));
  if((!bbBool(f0.l_ctype)||(((f0.l_ctype->m_cdecl->m_kind!=BB_T("class"))&&(f0.l_ctype->m_cdecl->m_kind!=BB_T("interface")))&&(f0.l_ctype->m_cdecl->m_kind!=BB_T("protocol"))))){
    throw bbGCNew<t_mx2_SemantEx>(((BB_T("Type '")+this->m_type->m_ToString())+BB_T("' is not a class or interface type")));
  }
  f0.l_value=this->m_expr->m_SemantRValue(l_scope,((t_mx2_Type*)0));
  f0.l_tvalue=bb_object_cast<t_mx2_TypeValue*>(f0.l_value);
  if(bbBool(f0.l_tvalue)){
    struct f1_t : public bbGCFrame{
      t_mx2_PrimType* l_ptype{};
      void gcMark(){
        bbGCMarkPtr(l_ptype);
      }
    }f1{};
    if((f0.l_tvalue->m_ttype->m_DistanceToType(((t_mx2_Type*)(f0.l_ctype)))>=bbInt(0))){
      return ((t_mx2_Value*)(g_mx2_LiteralValue_BoolValue(true)));
    }
    f1.l_ptype=g_mx2_TCast_1Tt_mx2_PrimType_2(f0.l_tvalue->m_ttype);
    if((bbBool(f1.l_ptype)&&(f1.l_ptype->m_ctype->m_DistanceToType(((t_mx2_Type*)(f0.l_ctype)))>=bbInt(0)))){
      return ((t_mx2_Value*)(g_mx2_LiteralValue_BoolValue(true)));
    }
    return ((t_mx2_Value*)(g_mx2_LiteralValue_BoolValue(false)));
  }
  if((f0.l_value->m_type->m_DistanceToType(((t_mx2_Type*)(f0.l_ctype)))>=bbInt(0))){
    return ((t_mx2_Value*)(g_mx2_LiteralValue_BoolValue(true)));
  }
  if(!f0.l_value->m_type->m_CanCastToType(((t_mx2_Type*)(f0.l_ctype)))){
    return ((t_mx2_Value*)(g_mx2_LiteralValue_BoolValue(false)));
  }
  f0.l_cvalue=bbGCNew<t_mx2_ExplicitCastValue>(((t_mx2_Type*)(f0.l_ctype)),f0.l_value);
  return f0.l_cvalue->m_UpCast(((t_mx2_Type*)(g_mx2_Type_BoolType)));
}

void t_mx2_CastExpr::gcMark(){
  t_mx2_Expr::gcMark();
  bbGCMark(m_type);
  bbGCMark(m_expr);
}

t_mx2_CastExpr::t_mx2_CastExpr(t_mx2_TypeExpr* l_type,t_mx2_Expr* l_expr,bbInt l_srcpos,bbInt l_endpos):t_mx2_Expr(l_srcpos,l_endpos){
  this->m_type=l_type;
  this->m_expr=l_expr;
}

bbString t_mx2_CastExpr::m_ToString(){
  return ((((BB_T("cast<")+this->m_type->m_ToString())+BB_T(">("))+this->m_expr->m_ToString())+BB_T(")"));
}

t_mx2_Value* t_mx2_CastExpr::m_OnSemant(t_mx2_Scope* l_scope){
  struct f0_t : public bbGCFrame{
    t_mx2_Value* l_castOp{};
    t_mx2_Type* l_type{};
    t_mx2_Value* l_value{};
    void gcMark(){
      bbGCMarkPtr(l_castOp);
      bbGCMarkPtr(l_type);
      bbGCMarkPtr(l_value);
    }
  }f0{};
  f0.l_type=this->m_type->m_Semant(l_scope,false);
  f0.l_value=this->m_expr->m_Semant(l_scope);
  f0.l_castOp=f0.l_value->m_FindValue(BB_T("cast"));
  if(bbBool(f0.l_castOp)){
    f0.l_value=f0.l_castOp->m_Invoke(((bbArray<bbGCVar<t_mx2_Value>>*)0));
  }
  if((f0.l_value->m_type->m_DistanceToType(f0.l_type)>=bbInt(0))){
    return f0.l_value->m_UpCast(f0.l_type);
  }
  f0.l_value=f0.l_value->m_ToRValue();
  if(!f0.l_value->m_type->m_CanCastToType(f0.l_type)){
    throw bbGCNew<t_mx2_SemantEx>(((((BB_T("Value of type '")+f0.l_value->m_type->m_Name())+BB_T("' cannot be cast to type '"))+f0.l_type->m_Name())+BB_T("'")));
  }
  return ((t_mx2_Value*)(bbGCNew<t_mx2_ExplicitCastValue>(f0.l_type,f0.l_value)));
}

t_mx2_SelfExpr::t_mx2_SelfExpr(bbInt l_srcpos,bbInt l_endpos):t_mx2_Expr(l_srcpos,l_endpos){
}

bbString t_mx2_SelfExpr::m_ToString(){
  return BB_T("self");
}

t_mx2_Value* t_mx2_SelfExpr::m_OnSemant(t_mx2_Scope* l_scope){
  struct f0_t : public bbGCFrame{
    t_mx2_Block* l_block{};
    void gcMark(){
      bbGCMarkPtr(l_block);
    }
  }f0{};
  f0.l_block=bb_object_cast<t_mx2_Block*>(l_scope);
  if((bbBool(f0.l_block)&&bbBool(f0.l_block->m_func->m_selfValue))){
    return f0.l_block->m_func->m_selfValue;
  }
  throw bbGCNew<t_mx2_SemantEx>(BB_T("'Self' can only be used in properties and methods"));
}

t_mx2_SuperExpr::t_mx2_SuperExpr(bbInt l_srcpos,bbInt l_endpos):t_mx2_Expr(l_srcpos,l_endpos){
}

bbString t_mx2_SuperExpr::m_ToString(){
  return BB_T("super");
}

t_mx2_Value* t_mx2_SuperExpr::m_OnSemant(t_mx2_Scope* l_scope){
  struct f0_t : public bbGCFrame{
    t_mx2_Block* l_block{};
    void gcMark(){
      bbGCMarkPtr(l_block);
    }
  }f0{};
  f0.l_block=bb_object_cast<t_mx2_Block*>(l_scope);
  if((bbBool(f0.l_block)&&bbBool(f0.l_block->m_func->m_selfValue))){
    struct f1_t : public bbGCFrame{
      t_mx2_ClassType* l_ctype{};
      void gcMark(){
        bbGCMarkPtr(l_ctype);
      }
    }f1{};
    f1.l_ctype=g_mx2_TCast_1Tt_mx2_ClassType_2(f0.l_block->m_func->m_selfValue->m_type);
    if(bbBool(f1.l_ctype)){
      struct f2_t : public bbGCFrame{
        t_mx2_ClassType* l_superType{};
        void gcMark(){
          bbGCMarkPtr(l_superType);
        }
      }f2{};
      f2.l_superType=f1.l_ctype->m_superType;
      if(bbBool(f2.l_superType)){
        return ((t_mx2_Value*)(bbGCNew<t_mx2_SuperValue>(f2.l_superType)));
      }
      throw bbGCNew<t_mx2_SemantEx>(((BB_T("Class '")+f1.l_ctype->m_Name())+BB_T("' has no super class")));
    }
  }
  throw bbGCNew<t_mx2_SemantEx>(BB_T("'Super' can only be used in properties and methods"));
}

t_mx2_NullExpr::t_mx2_NullExpr(bbInt l_srcpos,bbInt l_endpos):t_mx2_Expr(l_srcpos,l_endpos){
}

bbString t_mx2_NullExpr::m_ToString(){
  return BB_T("null");
}

t_mx2_Value* t_mx2_NullExpr::m_OnSemant(t_mx2_Scope* l_scope){
  return ((t_mx2_Value*)(bbGCNew<t_mx2_NullValue>()));
}

void t_mx2_UnaryopExpr::gcMark(){
  t_mx2_Expr::gcMark();
  bbGCMark(m_expr);
}

t_mx2_UnaryopExpr::t_mx2_UnaryopExpr(bbString l_op,t_mx2_Expr* l_expr,bbInt l_srcpos,bbInt l_endpos):t_mx2_Expr(l_srcpos,l_endpos){
  this->m_op=l_op;
  this->m_expr=l_expr;
}

bbString t_mx2_UnaryopExpr::m_ToString(){
  return (this->m_op+this->m_expr->m_ToString());
}

t_mx2_Value* t_mx2_UnaryopExpr::m_OnSemant(t_mx2_Scope* l_scope){
  struct f0_t : public bbGCFrame{
    t_mx2_Value* l_node{};
    t_mx2_PrimType* l_ptype{};
    t_mx2_Type* l_type{};
    t_mx2_Value* l_value{};
    t_mx2_Value* t0{};
    void gcMark(){
      bbGCMarkPtr(l_node);
      bbGCMarkPtr(l_ptype);
      bbGCMarkPtr(l_type);
      bbGCMarkPtr(l_value);
      bbGCMarkPtr(t0);
    }
  }f0{};
  f0.l_value=this->m_expr->m_SemantRValue(l_scope,((t_mx2_Type*)0));
  f0.l_type=f0.l_value->m_type;
  f0.l_node=f0.l_value->m_FindValue(this->m_op);
  if(bbBool(f0.l_node)){
    return f0.l_node->m_Invoke(((bbArray<bbGCVar<t_mx2_Value>>*)0));
  }
  f0.l_ptype=g_mx2_TCast_1Tt_mx2_PrimType_2(f0.l_type);
  if(this->m_op==BB_T("+")||this->m_op==BB_T("-")){
    if((!bbBool(f0.l_ptype)||!f0.l_ptype->m_IsNumeric())){
      throw bbGCNew<t_mx2_SemantEx>(BB_T("Type must be numeric"));
    }
    if(f0.l_ptype->m_IsUnsignedIntegral()){
      throw bbGCNew<t_mx2_SemantEx>(BB_T("Type cannot be unsigned"));
    }
  }else if(this->m_op==BB_T("~")){
    struct f1_t : public bbGCFrame{
      t_mx2_EnumType* l_etype{};
      void gcMark(){
        bbGCMarkPtr(l_etype);
      }
    }f1{};
    f1.l_etype=g_mx2_TCast_1Tt_mx2_EnumType_2(f0.l_type);
    if(bbBool(f1.l_etype)){
      f0.l_type=((t_mx2_Type*)(f1.l_etype));
    }else if((!bbBool(f0.l_ptype)||!f0.l_ptype->m_IsIntegral())){
      throw bbGCNew<t_mx2_SemantEx>(BB_T("Type must be integral"));
    }
  }else if(this->m_op==BB_T("not")){
    f0.l_type=((t_mx2_Type*)(g_mx2_Type_BoolType));
  }else{
    throw bbGCNew<t_mx2_SemantEx>(((BB_T("Illegal type for unary operator '")+this->m_op)+BB_T("'")));
  }
  return g_mx2_EvalUnaryop(f0.l_type,this->m_op,f0.t0=f0.l_value->m_UpCast(f0.l_type));
}

void t_mx2_BinaryopExpr::gcMark(){
  t_mx2_Expr::gcMark();
  bbGCMark(m_lhs);
  bbGCMark(m_rhs);
}

t_mx2_BinaryopExpr::t_mx2_BinaryopExpr(bbString l_op,t_mx2_Expr* l_lhs,t_mx2_Expr* l_rhs,bbInt l_srcpos,bbInt l_endpos):t_mx2_Expr(l_srcpos,l_endpos){
  this->m_op=l_op;
  this->m_lhs=l_lhs;
  this->m_rhs=l_rhs;
}

bbString t_mx2_BinaryopExpr::m_ToString(){
  return ((((BB_T("(")+this->m_lhs->m_ToString())+this->m_op)+this->m_rhs->m_ToString())+BB_T(")"));
}

bbBool t_mx2_BinaryopExpr::m_OnSemantWhere(t_mx2_Scope* l_scope){
  struct f0_t : public bbGCFrame{
    t_mx2_Type* l_lhs{};
    t_mx2_Type* l_rhs{};
    void gcMark(){
      bbGCMarkPtr(l_lhs);
      bbGCMarkPtr(l_rhs);
    }
  }f0{};
  if(((this->m_op!=BB_T("="))&&(this->m_op!=BB_T("<>")))){
    throw bbGCNew<t_mx2_SemantEx>(BB_T("Types can only be compared for equality"));
  }
  f0.l_lhs=this->m_lhs->m_SemantType(l_scope,false);
  f0.l_rhs=this->m_rhs->m_SemantType(l_scope,false);
  if((this->m_op==BB_T("="))){
    return f0.l_lhs->m_Equals(f0.l_rhs);
  }
  return !f0.l_lhs->m_Equals(f0.l_rhs);
}

t_mx2_Value* t_mx2_BinaryopExpr::m_OnSemant(t_mx2_Scope* l_scope){
  struct f0_t : public bbGCFrame{
    t_mx2_Value* l_lhs{};
    t_mx2_Type* l_lhsType{};
    t_mx2_PointerType* l_lptype{};
    t_mx2_Value* l_node{};
    t_mx2_PrimType* l_plhs{};
    t_mx2_PrimType* l_prhs{};
    t_mx2_Value* l_rhs{};
    t_mx2_Type* l_rhsType{};
    t_mx2_PointerType* l_rptype{};
    t_mx2_Type* l_type{};
    t_mx2_Value* t0{};
    t_mx2_Value* t1{};
    void gcMark(){
      bbGCMarkPtr(l_lhs);
      bbGCMarkPtr(l_lhsType);
      bbGCMarkPtr(l_lptype);
      bbGCMarkPtr(l_node);
      bbGCMarkPtr(l_plhs);
      bbGCMarkPtr(l_prhs);
      bbGCMarkPtr(l_rhs);
      bbGCMarkPtr(l_rhsType);
      bbGCMarkPtr(l_rptype);
      bbGCMarkPtr(l_type);
      bbGCMarkPtr(t0);
      bbGCMarkPtr(t1);
    }
  }f0{};
  f0.l_lhs=this->m_lhs->m_Semant(l_scope);
  f0.l_rhs=this->m_rhs->m_Semant(l_scope);
  if(f0.l_lhs->m_type->m__eq(((t_mx2_Type*)(g_mx2_Type_NullType)))){
    f0.l_rhs=f0.l_rhs->m_ToRValue();
    f0.l_lhs=f0.l_lhs->m_UpCast(f0.l_rhs->m_type);
  }else if(f0.l_rhs->m_type->m__eq(((t_mx2_Type*)(g_mx2_Type_NullType)))){
    f0.l_lhs=f0.l_lhs->m_ToRValue();
    f0.l_rhs=f0.l_rhs->m_UpCast(f0.l_lhs->m_type);
  }else{
    f0.l_lhs=f0.l_lhs->m_ToRValue();
    f0.l_rhs=f0.l_rhs->m_ToRValue();
  }
  f0.l_node=f0.l_lhs->m_FindValue(this->m_op);
  if(bbBool(f0.l_node)){
    struct f1_t : public bbGCFrame{
      bbArray<bbGCVar<t_mx2_Value>>* l_args{};
      void gcMark(){
        bbGCMarkPtr(l_args);
      }
    }f1{};
    f1.l_args=bbArray<bbGCVar<t_mx2_Value>>::create(1);
    f1.l_args->at(bbInt(0))=f0.l_rhs;
    return f0.l_node->m_Invoke(f1.l_args);
  }
  f0.l_lptype=g_mx2_TCast_1Tt_mx2_PointerType_2(f0.l_lhs->m_type);
  f0.l_rptype=g_mx2_TCast_1Tt_mx2_PointerType_2(f0.l_rhs->m_type);
  if((bbBool(f0.l_lptype)||bbBool(f0.l_rptype))){
    if((bbBool(f0.l_lptype)&&((this->m_op==BB_T("+"))||(this->m_op==BB_T("-"))))){
      struct f2_t : public bbGCFrame{
        t_mx2_Value* t0{};
        void gcMark(){
          bbGCMarkPtr(t0);
        }
      }f2{};
      return ((t_mx2_Value*)(bbGCNew<t_mx2_BinaryopValue>(((t_mx2_Type*)(f0.l_lptype)),this->m_op,f0.l_lhs,f2.t0=f0.l_rhs->m_UpCast(((t_mx2_Type*)(g_mx2_Type_IntType))))));
    }else if((bbBool(f0.l_rptype)&&(this->m_op==BB_T("+")))){
      struct f2_t : public bbGCFrame{
        t_mx2_Value* t0{};
        void gcMark(){
          bbGCMarkPtr(t0);
        }
      }f2{};
      return ((t_mx2_Value*)(bbGCNew<t_mx2_BinaryopValue>(((t_mx2_Type*)(f0.l_rptype)),this->m_op,f0.l_rhs,f2.t0=f0.l_lhs->m_UpCast(((t_mx2_Type*)(g_mx2_Type_IntType))))));
    }
    throw bbGCNew<t_mx2_SemantEx>(BB_T("Pointer arithmetic error"));
  }
  f0.l_plhs=g_mx2_TCast_1Tt_mx2_PrimType_2(f0.l_lhs->m_type);
  f0.l_prhs=g_mx2_TCast_1Tt_mx2_PrimType_2(f0.l_rhs->m_type);
  if(this->m_op==BB_T("+")){
    f0.l_type=g_mx2_BinaryopExpr_BalancePrimTypes(f0.l_plhs,f0.l_prhs);
  }else if(this->m_op==BB_T("*")||this->m_op==BB_T("/")||this->m_op==BB_T("mod")||this->m_op==BB_T("-")){
    f0.l_type=g_mx2_BinaryopExpr_BalanceNumericTypes(f0.l_plhs,f0.l_prhs);
  }else if(this->m_op==BB_T("&")||this->m_op==BB_T("|")||this->m_op==BB_T("~")){
    struct f1_t : public bbGCFrame{
      t_mx2_EnumType* l_elhs{};
      t_mx2_EnumType* l_erhs{};
      void gcMark(){
        bbGCMarkPtr(l_elhs);
        bbGCMarkPtr(l_erhs);
      }
    }f1{};
    f1.l_elhs=g_mx2_TCast_1Tt_mx2_EnumType_2(f0.l_lhs->m_type);
    f1.l_erhs=g_mx2_TCast_1Tt_mx2_EnumType_2(f0.l_rhs->m_type);
    if((bbBool(f1.l_elhs)||bbBool(f1.l_erhs))){
      if(f1.l_elhs->m_Equals(((t_mx2_Type*)(f1.l_erhs)))){
        f0.l_type=((t_mx2_Type*)(f1.l_elhs));
      }
    }else{
      f0.l_type=g_mx2_BinaryopExpr_BalanceIntegralTypes(f0.l_plhs,f0.l_prhs);
    }
  }else if(this->m_op==BB_T("shl")||this->m_op==BB_T("shr")){
    f0.l_type=g_mx2_BinaryopExpr_BalanceIntegralTypes(f0.l_plhs,f0.l_plhs);
    f0.l_rhsType=((t_mx2_Type*)(g_mx2_Type_IntType));
  }else if(this->m_op==BB_T("=")||this->m_op==BB_T("<>")||this->m_op==BB_T("<")||this->m_op==BB_T(">")||this->m_op==BB_T("<=")||this->m_op==BB_T(">=")){
    struct f1_t : public bbGCFrame{
      t_mx2_Value* l_node{};
      void gcMark(){
        bbGCMarkPtr(l_node);
      }
    }f1{};
    f1.l_node=f0.l_lhs->m_FindValue(BB_T("<=>"));
    if(bbBool(f1.l_node)){
      struct f2_t : public bbGCFrame{
        bbArray<bbGCVar<t_mx2_Value>>* l_args{};
        t_mx2_PrimType* l_ptype{};
        void gcMark(){
          bbGCMarkPtr(l_args);
          bbGCMarkPtr(l_ptype);
        }
      }f2{};
      f2.l_args=bbArray<bbGCVar<t_mx2_Value>>::create(1);
      f2.l_args->at(bbInt(0))=f0.l_rhs;
      f0.l_lhs=f1.l_node->m_Invoke(f2.l_args);
      f0.l_lhsType=f0.l_lhs->m_type;
      f0.l_rhsType=f0.l_lhsType;
      f2.l_ptype=g_mx2_TCast_1Tt_mx2_PrimType_2(f0.l_lhsType);
      bbAssert((bbBool(f2.l_ptype)&&f2.l_ptype->m_IsNumeric()),BB_T("Assert failed"));
      f0.l_rhs=((t_mx2_Value*)(bbGCNew<t_mx2_LiteralValue>(f0.l_rhsType,bbString{})));
      f0.l_type=((t_mx2_Type*)(g_mx2_Type_BoolType));
    }else if((f0.l_plhs->m__eq(((t_mx2_Type*)(g_mx2_Type_BoolType)))||f0.l_prhs->m__eq(((t_mx2_Type*)(g_mx2_Type_BoolType))))){
      if(((this->m_op!=BB_T("="))&&(this->m_op!=BB_T("<>")))){
        throw bbGCNew<t_mx2_SemantEx>(BB_T("Bool values can only be compared for equality"));
      }
      f0.l_type=((t_mx2_Type*)(g_mx2_Type_BoolType));
    }else{
      f0.l_type=g_mx2_BinaryopExpr_BalanceTypes(f0.l_lhs->m_type,f0.l_rhs->m_type);
      if(bbBool(f0.l_type)){
        f0.l_lhsType=f0.l_type;
        f0.l_rhsType=f0.l_type;
        f0.l_type=((t_mx2_Type*)(g_mx2_Type_BoolType));
      }
    }
  }else if(this->m_op==BB_T("<=>")){
    f0.l_type=g_mx2_BinaryopExpr_BalanceTypes(f0.l_lhs->m_type,f0.l_rhs->m_type);
    if(bbBool(f0.l_type)){
      f0.l_lhsType=f0.l_type;
      f0.l_rhsType=f0.l_type;
      f0.l_type=((t_mx2_Type*)(g_mx2_Type_IntType));
    }
  }else if(this->m_op==BB_T("and")||this->m_op==BB_T("or")){
    f0.l_type=((t_mx2_Type*)(g_mx2_Type_BoolType));
  }
  if(!bbBool(f0.l_type)){
    throw bbGCNew<t_mx2_SemantEx>(((BB_T("Parameter types for binary operator '")+this->m_op)+BB_T("' cannot be determined")));
  }
  if(!bbBool(f0.l_lhsType)){
    f0.l_lhsType=f0.l_type;
  }
  if(!bbBool(f0.l_rhsType)){
    f0.l_rhsType=f0.l_type;
  }
  return g_mx2_EvalBinaryop(f0.l_type,this->m_op,f0.t0=f0.l_lhs->m_UpCast(f0.l_lhsType),f0.t1=f0.l_rhs->m_UpCast(f0.l_rhsType));
}

void t_mx2_IfThenElseExpr::gcMark(){
  t_mx2_Expr::gcMark();
  bbGCMark(m_expr);
  bbGCMark(m_thenExpr);
  bbGCMark(m_elseExpr);
}

t_mx2_IfThenElseExpr::t_mx2_IfThenElseExpr(t_mx2_Expr* l_expr,t_mx2_Expr* l_thenExpr,t_mx2_Expr* l_elseExpr,bbInt l_srcpos,bbInt l_endpos):t_mx2_Expr(l_srcpos,l_endpos){
  this->m_expr=l_expr;
  this->m_thenExpr=l_thenExpr;
  this->m_elseExpr=l_elseExpr;
}

t_mx2_Value* t_mx2_IfThenElseExpr::m_OnSemant(t_mx2_Scope* l_scope){
  struct f0_t : public bbGCFrame{
    t_mx2_Value* l_elseValue{};
    t_mx2_Value* l_thenValue{};
    t_mx2_Type* l_type{};
    t_mx2_Value* l_value{};
    void gcMark(){
      bbGCMarkPtr(l_elseValue);
      bbGCMarkPtr(l_thenValue);
      bbGCMarkPtr(l_type);
      bbGCMarkPtr(l_value);
    }
  }f0{};
  f0.l_value=this->m_expr->m_SemantRValue(l_scope,((t_mx2_Type*)(g_mx2_Type_BoolType)));
  f0.l_thenValue=this->m_thenExpr->m_SemantRValue(l_scope,((t_mx2_Type*)0));
  f0.l_elseValue=this->m_elseExpr->m_SemantRValue(l_scope,((t_mx2_Type*)0));
  f0.l_type=g_mx2_BinaryopExpr_BalanceTypes(f0.l_thenValue->m_type,f0.l_elseValue->m_type);
  f0.l_thenValue=f0.l_thenValue->m_UpCast(f0.l_type);
  f0.l_elseValue=f0.l_elseValue->m_UpCast(f0.l_type);
  return ((t_mx2_Value*)(bbGCNew<t_mx2_IfThenElseValue>(f0.l_type,f0.l_value,f0.l_thenValue,f0.l_elseValue)));
}

void t_mx2_VarptrExpr::gcMark(){
  t_mx2_Expr::gcMark();
  bbGCMark(m_expr);
}

t_mx2_VarptrExpr::t_mx2_VarptrExpr(t_mx2_Expr* l_expr,bbInt l_srcpos,bbInt l_endpos):t_mx2_Expr(l_srcpos,l_endpos){
  this->m_expr=l_expr;
}

bbString t_mx2_VarptrExpr::m_ToString(){
  return (BB_T("Varptr ")+this->m_expr->m_ToString());
}

t_mx2_Value* t_mx2_VarptrExpr::m_OnSemant(t_mx2_Scope* l_scope){
  struct f0_t : public bbGCFrame{
    t_mx2_Value* l_value{};
    void gcMark(){
      bbGCMarkPtr(l_value);
    }
  }f0{};
  f0.l_value=this->m_expr->m_Semant(l_scope);
  if(!f0.l_value->m_IsLValue()){
    throw bbGCNew<t_mx2_SemantEx>(((BB_T("Value '")+f0.l_value->m_ToString())+BB_T("' is not a valid variable reference")));
  }
  return ((t_mx2_Value*)(bbGCNew<t_mx2_PointerValue>(f0.l_value)));
}

void t_mx2_LiteralExpr::gcMark(){
  t_mx2_Expr::gcMark();
  bbGCMark(m_typeExpr);
}

t_mx2_LiteralExpr::t_mx2_LiteralExpr(bbString l_toke,bbInt l_tokeType,t_mx2_TypeExpr* l_typeExpr,bbInt l_srcpos,bbInt l_endpos):t_mx2_Expr(l_srcpos,l_endpos){
  this->m_toke=l_toke;
  this->m_tokeType=l_tokeType;
  this->m_typeExpr=l_typeExpr;
}

bbString t_mx2_LiteralExpr::m_ToString(){
  return this->m_toke;
}

t_mx2_Value* t_mx2_LiteralExpr::m_OnSemant(t_mx2_Scope* l_scope){
  struct f0_t : public bbGCFrame{
    t_mx2_PrimType* l_ptype{};
    t_mx2_Type* l_type{};
    void gcMark(){
      bbGCMarkPtr(l_ptype);
      bbGCMarkPtr(l_type);
    }
  }f0{};
  if(bbBool(this->m_typeExpr)){
    struct f1_t : public bbGCFrame{
      t_mx2_PrimType* l_ptype{};
      void gcMark(){
        bbGCMarkPtr(l_ptype);
      }
    }f1{};
    f0.l_type=this->m_typeExpr->m_Semant(l_scope,false);
    f1.l_ptype=g_mx2_TCast_1Tt_mx2_PrimType_2(f0.l_type);
    if(!bbBool(f1.l_ptype)){
      throw bbGCNew<t_mx2_SemantEx>(BB_T("Literal type must be a primitive type"));
    }
    if(this->m_tokeType==g_mx2_TOKE_0INTLIT){
      if(!f1.l_ptype->m_IsIntegral()){
        throw bbGCNew<t_mx2_SemantEx>(BB_T("Literal type must be an integral type"));
      }
    }else if(this->m_tokeType==g_mx2_TOKE_0FLOATLIT){
      if(!f1.l_ptype->m_IsReal()){
        throw bbGCNew<t_mx2_SemantEx>(BB_T("Literal type must be 'Float' or 'Double'"));
      }
    }else if(this->m_tokeType==g_mx2_TOKE_0STRINGLIT){
      if(f1.l_ptype->m__ne(((t_mx2_Type*)(g_mx2_Type_StringType)))){
        throw bbGCNew<t_mx2_SemantEx>(BB_T("Literal type must be 'String'"));
      }
    }else if(this->m_tokeType==g_mx2_TOKE_0KEYWORD){
      if(f1.l_ptype->m__ne(((t_mx2_Type*)(g_mx2_Type_BoolType)))){
        throw bbGCNew<t_mx2_SemantEx>(BB_T("Literal type must be 'Bool'"));
      }
    }
  }else{
    if(this->m_tokeType==g_mx2_TOKE_0INTLIT){
      f0.l_type=((t_mx2_Type*)(g_mx2_Type_IntType));
    }else if(this->m_tokeType==g_mx2_TOKE_0FLOATLIT){
      f0.l_type=((t_mx2_Type*)(g_mx2_Type_FloatType));
    }else if(this->m_tokeType==g_mx2_TOKE_0STRINGLIT){
      f0.l_type=((t_mx2_Type*)(g_mx2_Type_StringType));
    }else if(this->m_tokeType==g_mx2_TOKE_0KEYWORD){
      f0.l_type=((t_mx2_Type*)(g_mx2_Type_BoolType));
    }
  }
  if(!bbBool(f0.l_type)){
    g_mx2_SemantError(BB_T("LiteralExpr.OnSemant()"));
  }
  bbString l_t=this->m_toke;
  f0.l_ptype=g_mx2_TCast_1Tt_mx2_PrimType_2(f0.l_type);
  if((((bbBool(f0.l_ptype)&&f0.l_ptype->m_IsIntegral())&&bbBool(l_t))&&(l_t[bbInt(0)]==g_mx2_CHAR_0DOLLAR))){
    bbULong l_n{};
    {
      bbInt l_i=1;
      for(;(l_i<this->m_toke.length());l_i+=1){
        bbInt l_c=this->m_toke[l_i];
        if((l_c>=97)){
          l_c-=87;
        }else if((l_c>=65)){
          l_c-=55;
        }else{
          l_c-=48;
        }
        l_n=((l_n<<4)|bbULong(l_c));
      }
    }
    l_t=bbString(l_n);
  }else if(f0.l_ptype->m__eq(((t_mx2_Type*)(g_mx2_Type_StringType)))){
    l_t=g_mx2_DequoteMx2String(l_t);
  }
  return ((t_mx2_Value*)(bbGCNew<t_mx2_LiteralValue>(f0.l_type,l_t)));
}

void t_mx2_ArrayLiteralExpr::gcMark(){
  t_mx2_Expr::gcMark();
  bbGCMark(m_exprs);
}

t_mx2_ArrayLiteralExpr::t_mx2_ArrayLiteralExpr(bbArray<bbGCVar<t_mx2_Expr>>* l_exprs,bbInt l_srcpos,bbInt l_endpos):t_mx2_Expr(l_srcpos,l_endpos){
  this->m_exprs=l_exprs;
}

bbString t_mx2_ArrayLiteralExpr::m_ToString(){
  return ((BB_T("[")+g_mx2_Join_1Tt_mx2_Expr_2(this->m_exprs,BB_T(",")))+BB_T("]"));
}

void t_mx2_LambdaExpr::gcMark(){
  t_mx2_Expr::gcMark();
  bbGCMark(m_decl);
}

t_mx2_LambdaExpr::t_mx2_LambdaExpr(t_mx2_FuncDecl* l_decl,bbInt l_srcpos,bbInt l_endpos):t_mx2_Expr(l_srcpos,l_endpos){
  this->m_decl=l_decl;
}

bbString t_mx2_LambdaExpr::m_ToString(){
  return this->m_decl->m_ToString();
}

t_mx2_Value* t_mx2_LambdaExpr::m_OnSemant(t_mx2_Scope* l_scope){
  struct f0_t : public bbGCFrame{
    t_mx2_FuncValue* l_func{};
    void gcMark(){
      bbGCMarkPtr(l_func);
    }
  }f0{};
  f0.l_func=bbGCNew<t_mx2_FuncValue>(this->m_decl,l_scope,((bbArray<bbGCVar<t_mx2_Type>>*)0),((t_mx2_FuncValue*)0));
  f0.l_func->m_Semant();
  return ((t_mx2_Value*)(f0.l_func));
}

void mx2_mx2cc_expr_init(){
  static bool done;
  if(done) return;
  done=true;
}

bbInit mx2_mx2cc_expr_init_v("mx2cc_expr",&mx2_mx2cc_expr_init);
