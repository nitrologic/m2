
#include "mx2cc_eval.h"

// ***** External *****

#include "mx2cc_decl.h"
#include "mx2cc_enum.h"
#include "mx2cc_type.h"
#include "mx2cc_value.h"

// ***** Internal *****

t_mx2_Value* g_mx2_EvalBinaryop(t_mx2_Type* l_type,bbString l_op,t_mx2_Value* l_lhs,t_mx2_Value* l_rhs){
  struct f0_t : public bbGCFrame{
    t_mx2_LiteralValue* l_x{};
    void gcMark(){
      bbGCMarkPtr(l_x);
    }
  }f0{};
  f0.l_x=bb_object_cast<t_mx2_LiteralValue*>(l_lhs);
  if(bbBool(f0.l_x)){
    struct f1_t : public bbGCFrame{
      t_mx2_LiteralValue* l_y{};
      void gcMark(){
        bbGCMarkPtr(l_y);
      }
    }f1{};
    f1.l_y=bb_object_cast<t_mx2_LiteralValue*>(l_rhs);
    if(bbBool(f1.l_y)){
      struct f2_t : public bbGCFrame{
        t_mx2_LiteralValue* l_value{};
        void gcMark(){
          bbGCMarkPtr(l_value);
        }
      }f2{};
      f2.l_value=g_mx2_EvalBinaryop(l_type,l_op,f0.l_x,f1.l_y);
      if(bbBool(f2.l_value)){
        return ((t_mx2_Value*)(f2.l_value));
      }
    }
  }
  return ((t_mx2_Value*)(bbGCNew<t_mx2_BinaryopValue>(l_type,l_op,l_lhs,l_rhs)));
}

t_mx2_LiteralValue* g_mx2_EvalBinaryop(t_mx2_Type* l_type,bbString l_op,t_mx2_LiteralValue* l_lhs,t_mx2_LiteralValue* l_rhs){
  struct f0_t : public bbGCFrame{
    t_mx2_EnumType* l_etype{};
    void gcMark(){
      bbGCMarkPtr(l_etype);
    }
  }f0{};
  if(l_type==((t_mx2_Type*)(g_mx2_Type_IntType))){
    bbInt l_r{};
    bbInt l_x=bbInt(l_lhs->m_value);
    bbInt l_y=bbInt(l_rhs->m_value);
    if(l_op==BB_T("*")){
      l_r=(l_x*l_y);
    }else if(l_op==BB_T("/")){
      l_r=(l_x/l_y);
    }else if(l_op==BB_T("+")){
      l_r=(l_x+l_y);
    }else if(l_op==BB_T("-")){
      l_r=(l_x-l_y);
    }else if(l_op==BB_T("&")){
      l_r=(l_x&l_y);
    }else if(l_op==BB_T("|")){
      l_r=(l_x|l_y);
    }else if(l_op==BB_T("~")){
      l_r=(l_x^l_y);
    }else if(l_op==BB_T("mod")){
      l_r=(l_x%l_y);
    }else if(l_op==BB_T("shl")){
      l_r=(l_x<<l_y);
    }else if(l_op==BB_T("shr")){
      l_r=(l_x>>l_y);
    }else{
      return ((t_mx2_LiteralValue*)0);
    }
    return bbGCNew<t_mx2_LiteralValue>(((t_mx2_Type*)(g_mx2_Type_IntType)),bbString(l_r));
  }
  f0.l_etype=g_mx2_TCast_1Tt_mx2_EnumType_2(l_type);
  if((bbBool(f0.l_etype)&&!f0.l_etype->m_edecl->m_IsExtern())){
    bbInt l_r{};
    bbInt l_x=bbInt(l_lhs->m_value);
    bbInt l_y=bbInt(l_rhs->m_value);
    if(l_op==BB_T("&")){
      l_r=(l_x&l_y);
    }else if(l_op==BB_T("|")){
      l_r=(l_x|l_y);
    }else if(l_op==BB_T("~")){
      l_r=(l_x^l_y);
    }else{
      return ((t_mx2_LiteralValue*)0);
    }
    return bbGCNew<t_mx2_LiteralValue>(l_type,bbString(l_r));
  }
  return ((t_mx2_LiteralValue*)0);
}

t_mx2_Value* g_mx2_EvalUnaryop(t_mx2_Type* l_type,bbString l_op,t_mx2_Value* l_arg){
  struct f0_t : public bbGCFrame{
    t_mx2_LiteralValue* l_t{};
    void gcMark(){
      bbGCMarkPtr(l_t);
    }
  }f0{};
  f0.l_t=bb_object_cast<t_mx2_LiteralValue*>(l_arg);
  if(bbBool(f0.l_t)){
    struct f1_t : public bbGCFrame{
      t_mx2_LiteralValue* l_value{};
      void gcMark(){
        bbGCMarkPtr(l_value);
      }
    }f1{};
    f1.l_value=g_mx2_EvalUnaryop(l_type,l_op,f0.l_t);
    if(bbBool(f1.l_value)){
      return ((t_mx2_Value*)(f1.l_value));
    }
  }
  return ((t_mx2_Value*)(bbGCNew<t_mx2_UnaryopValue>(l_type,l_op,l_arg)));
}

t_mx2_LiteralValue* g_mx2_EvalUnaryop(t_mx2_Type* l_type,bbString l_op,t_mx2_LiteralValue* l_arg){
  return ((t_mx2_LiteralValue*)0);
}

void mx2_mx2cc_eval_init(){
  static bool done;
  if(done) return;
  done=true;
}

bbInit mx2_mx2cc_eval_init_v("mx2cc_eval",&mx2_mx2cc_eval_init);
