
#include "mx2cc_balance.h"

// ***** External *****

#include "mx2cc_enum.h"
#include "mx2cc_errors.h"
#include "mx2cc_type.h"

// ***** Internal *****

t_mx2_Type* g_mx2_BalanceAssignTypes(bbString l_op,t_mx2_Type* l_lhs,t_mx2_Type* l_rhs){
  struct f0_t : public bbGCFrame{
    t_mx2_PrimType* l_plhs{};
    void gcMark(){
      bbGCMarkPtr(l_plhs);
    }
  }f0{};
  if((l_op==BB_T("="))){
    return l_lhs;
  }
  f0.l_plhs=g_mx2_TCast_1Tt_mx2_PrimType_2(l_lhs);
  if(l_op==BB_T("+=")){
    if(bbBool(f0.l_plhs)){
      if((f0.l_plhs->m__eq(((t_mx2_Type*)(g_mx2_Type_StringType)))||f0.l_plhs->m_IsNumeric())){
        return l_lhs;
      }
    }else if(bbBool(g_mx2_TCast_1Tt_mx2_PointerType_2(l_lhs))){
      struct f2_t : public bbGCFrame{
        t_mx2_PrimType* l_prhs{};
        void gcMark(){
          bbGCMarkPtr(l_prhs);
        }
      }f2{};
      f2.l_prhs=g_mx2_TCast_1Tt_mx2_PrimType_2(l_rhs);
      if(bbBool(f2.l_prhs)){
        if((f2.l_prhs->m__eq(((t_mx2_Type*)(g_mx2_Type_LongType)))||f2.l_prhs->m__eq(((t_mx2_Type*)(g_mx2_Type_ULongType))))){
          return l_rhs;
        }
        if(f2.l_prhs->m_IsIntegral()){
          return ((t_mx2_Type*)(g_mx2_Type_IntType));
        }
      }
    }else if(bbBool(g_mx2_TCast_1Tt_mx2_FuncType_2(l_lhs))){
      return l_lhs;
    }
  }else if(l_op==BB_T("-=")){
    if(bbBool(f0.l_plhs)){
      if(f0.l_plhs->m_IsNumeric()){
        return l_lhs;
      }
    }else if(bbBool(g_mx2_TCast_1Tt_mx2_PointerType_2(l_lhs))){
      struct f2_t : public bbGCFrame{
        t_mx2_PrimType* l_prhs{};
        void gcMark(){
          bbGCMarkPtr(l_prhs);
        }
      }f2{};
      f2.l_prhs=g_mx2_TCast_1Tt_mx2_PrimType_2(l_rhs);
      if(bbBool(f2.l_prhs)){
        if((f2.l_prhs->m__eq(((t_mx2_Type*)(g_mx2_Type_LongType)))||f2.l_prhs->m__eq(((t_mx2_Type*)(g_mx2_Type_ULongType))))){
          return l_rhs;
        }
        if((bbBool(f2.l_prhs)&&f2.l_prhs->m_IsIntegral())){
          return ((t_mx2_Type*)(g_mx2_Type_IntType));
        }
      }
    }else if(bbBool(g_mx2_TCast_1Tt_mx2_FuncType_2(l_lhs))){
      return l_lhs;
    }
  }else if(l_op==BB_T("*=")||l_op==BB_T("/=")||l_op==BB_T("mod=")){
    if((bbBool(f0.l_plhs)&&f0.l_plhs->m_IsNumeric())){
      return l_lhs;
    }
  }else if(l_op==BB_T("&=")||l_op==BB_T("|=")||l_op==BB_T("~=")){
    if((bbBool(f0.l_plhs)&&f0.l_plhs->m_IsIntegral())){
      return l_lhs;
    }
    if((bbBool(g_mx2_TCast_1Tt_mx2_EnumType_2(l_lhs))&&l_lhs->m_Equals(l_rhs))){
      return l_lhs;
    }
  }else if(l_op==BB_T("shl=")||l_op==BB_T("shr=")){
    if((bbBool(f0.l_plhs)&&f0.l_plhs->m_IsIntegral())){
      return ((t_mx2_Type*)(g_mx2_Type_IntType));
    }
  }else if(l_op==BB_T("and=")||l_op==BB_T("or=")){
    if((bbBool(f0.l_plhs)&&f0.l_plhs->m__eq(((t_mx2_Type*)(g_mx2_Type_BoolType))))){
      return ((t_mx2_Type*)(g_mx2_Type_BoolType));
    }
  }
  throw bbGCNew<t_mx2_SemantEx>(BB_T("Invalid type for assignment"));
}

t_mx2_Type* g_mx2_BalanceBinaryopTypes(bbString l_op,t_mx2_Type* l_lhs,t_mx2_Type* l_rhs,bbArray<bbGCVar<t_mx2_Type>>* l_argTypes){
  struct f0_t : public bbGCFrame{
    t_mx2_Type* l_ltype{};
    t_mx2_PrimType* l_plhs{};
    t_mx2_PrimType* l_prhs{};
    t_mx2_Type* l_rtype{};
    t_mx2_Type* l_type{};
    void gcMark(){
      bbGCMarkPtr(l_ltype);
      bbGCMarkPtr(l_plhs);
      bbGCMarkPtr(l_prhs);
      bbGCMarkPtr(l_rtype);
      bbGCMarkPtr(l_type);
    }
  }f0{};
  f0.l_plhs=g_mx2_TCast_1Tt_mx2_PrimType_2(l_lhs);
  f0.l_prhs=g_mx2_TCast_1Tt_mx2_PrimType_2(l_rhs);
  if(l_op==BB_T("+")){
    if(bbBool(g_mx2_TCast_1Tt_mx2_PointerType_2(l_lhs))){
      f0.l_type=l_lhs;
      f0.l_rtype=g_mx2_BalanceIntegralTypes(f0.l_prhs,f0.l_prhs);
    }else if(bbBool(g_mx2_TCast_1Tt_mx2_PointerType_2(l_rhs))){
      f0.l_type=l_rhs;
      f0.l_ltype=g_mx2_BalanceIntegralTypes(f0.l_plhs,f0.l_plhs);
    }else{
      f0.l_type=g_mx2_BalancePrimTypes(f0.l_plhs,f0.l_prhs);
    }
  }else if(l_op==BB_T("-")){
    if(bbBool(g_mx2_TCast_1Tt_mx2_PointerType_2(l_lhs))){
      f0.l_type=l_lhs;
      f0.l_rtype=g_mx2_BalanceIntegralTypes(f0.l_prhs,f0.l_prhs);
    }else{
      f0.l_type=g_mx2_BalanceNumericTypes(f0.l_plhs,f0.l_prhs);
    }
  }else if(l_op==BB_T("*")||l_op==BB_T("/")||l_op==BB_T("mod")||l_op==BB_T("+")||l_op==BB_T("-")){
    f0.l_type=g_mx2_BalanceNumericTypes(f0.l_plhs,f0.l_prhs);
  }else if(l_op==BB_T("&")||l_op==BB_T("|")||l_op==BB_T("~")){
    if((bbBool(g_mx2_TCast_1Tt_mx2_EnumType_2(l_lhs))||bbBool(g_mx2_TCast_1Tt_mx2_EnumType_2(l_rhs)))){
      if(l_lhs->m_Equals(l_rhs)){
        f0.l_type=l_lhs;
      }
    }else{
      f0.l_type=g_mx2_BalanceIntegralTypes(f0.l_plhs,f0.l_prhs);
    }
  }else if(l_op==BB_T("shl")||l_op==BB_T("shr")){
    if((bbBool(f0.l_plhs)&&f0.l_plhs->m_IsIntegral())){
      f0.l_type=g_mx2_BalanceIntegralTypes(f0.l_plhs,f0.l_plhs);
      f0.l_rtype=((t_mx2_Type*)(g_mx2_Type_IntType));
    }
  }else if(l_op==BB_T("=")||l_op==BB_T("<>")||l_op==BB_T("<")||l_op==BB_T(">")||l_op==BB_T("<=")||l_op==BB_T(">=")){
    f0.l_type=((t_mx2_Type*)(g_mx2_Type_BoolType));
    f0.l_ltype=g_mx2_BalanceTypes(l_lhs,l_rhs);
    f0.l_rtype=f0.l_ltype;
  }else if(l_op==BB_T("<=>")){
    f0.l_type=((t_mx2_Type*)(g_mx2_Type_IntType));
    f0.l_ltype=g_mx2_BalanceTypes(l_lhs,l_rhs);
    f0.l_rtype=f0.l_ltype;
  }
  if(!bbBool(f0.l_type)){
    throw bbGCNew<t_mx2_SemantEx>(((BB_T("Invalid operand types for binary operator '")+l_op)+BB_T("'")));
  }
  l_argTypes->at(bbInt(0))=(bbBool(f0.l_ltype) ? f0.l_ltype : f0.l_type);
  l_argTypes->at(1)=(bbBool(f0.l_rtype) ? f0.l_rtype : f0.l_type);
  return f0.l_type;
}

t_mx2_Type* g_mx2_BalanceTypes(t_mx2_Type* l_lhs,t_mx2_Type* l_rhs){
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
    return g_mx2_BalancePrimTypes(f0.l_plhs,f0.l_prhs);
  }
  if((l_lhs->m_DistanceToType(l_rhs)>=bbInt(0))){
    return l_rhs;
  }
  if((l_rhs->m_DistanceToType(l_lhs)>=bbInt(0))){
    return l_lhs;
  }
  throw bbGCNew<t_mx2_SemantEx>(((((BB_T("Types '")+l_lhs->m_Name())+BB_T("' and '"))+l_rhs->m_Name())+BB_T("' are incompatible")));
}

t_mx2_Type* g_mx2_BalancePrimTypes(t_mx2_PrimType* l_lhs,t_mx2_PrimType* l_rhs){
  if((!bbBool(l_lhs)||!bbBool(l_rhs))){
    throw bbGCNew<t_mx2_SemantEx>(BB_T("Types must be primitive"));
  }
  if((l_lhs->m__eq(((t_mx2_Type*)(g_mx2_Type_StringType)))||l_rhs->m__eq(((t_mx2_Type*)(g_mx2_Type_StringType))))){
    return ((t_mx2_Type*)(g_mx2_Type_StringType));
  }
  return g_mx2_BalanceNumericTypes(l_lhs,l_rhs);
}

t_mx2_Type* g_mx2_BalanceNumericTypes(t_mx2_PrimType* l_lhs,t_mx2_PrimType* l_rhs){
  if((((!bbBool(l_lhs)||!bbBool(l_rhs))||!l_lhs->m_IsNumeric())||!l_rhs->m_IsNumeric())){
    throw bbGCNew<t_mx2_SemantEx>(BB_T("Types must be numeric"));
  }
  if((l_lhs->m__eq(((t_mx2_Type*)(g_mx2_Type_DoubleType)))||l_rhs->m__eq(((t_mx2_Type*)(g_mx2_Type_DoubleType))))){
    return ((t_mx2_Type*)(g_mx2_Type_DoubleType));
  }
  if((l_lhs->m__eq(((t_mx2_Type*)(g_mx2_Type_FloatType)))||l_rhs->m__eq(((t_mx2_Type*)(g_mx2_Type_FloatType))))){
    return ((t_mx2_Type*)(g_mx2_Type_FloatType));
  }
  return g_mx2_BalanceIntegralTypes(l_lhs,l_rhs);
}

t_mx2_Type* g_mx2_BalanceIntegralTypes(t_mx2_PrimType* l_lhs,t_mx2_PrimType* l_rhs){
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

void mx2_mx2cc_balance_init(){
  static bool done;
  if(done) return;
  done=true;
}

bbInit mx2_mx2cc_balance_init_v("mx2cc_balance",&mx2_mx2cc_balance_init);
