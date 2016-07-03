
#include "mx2cc_overload.h"

// ***** External *****

#include "../../../../../modules/monkey/monkey.buildv1.0.0/desktop_release_linux/monkey_types.h"
#include "mx2cc_expr.h"
#include "mx2cc_func.h"
#include "mx2cc_std_collections_2stack.h"
#include "mx2cc_type.h"
#include "mx2cc_var.h"

extern void g_mx2_SemantError(bbString l_func);
extern bbInt g_monkey_math_Min_1i(bbInt l_x,bbInt l_y);

// ***** Internal *****

t_mx2_FuncValue* g_mx2_overload_FindOverload(t_std_collections_Stack_1Tt_mx2_FuncValue_2* l_funcs,t_mx2_Type* l_ret,bbArray<bbGCVar<t_mx2_Type>>* l_args){
  struct f0_t : public bbGCFrame{
    t_std_collections_Stack_1Tt_mx2_FuncValue_2* l_candidates{};
    t_mx2_FuncValue* l_match{};
    void gcMark(){
      bbGCMarkPtr(l_candidates);
      bbGCMarkPtr(l_match);
    }
  }f0{};
  f0.l_candidates=bbGCNew<t_std_collections_Stack_1Tt_mx2_FuncValue_2>();
  {
    struct f1_t : public bbGCFrame{
      t_std_collections_Stack_1Tt_mx2_FuncValue_2_Iterator l_0{};
      void gcMark(){
        bbGCMark(l_0);
      }
    }f1{};
    f1.l_0=l_funcs->m_All();
    for(;!f1.l_0.m_AtEnd();f1.l_0.m_Bump()){
      struct f2_t : public bbGCFrame{
        t_mx2_FuncValue* l_func{};
        bbArray<bbGCVar<t_mx2_Type>>* l_infered{};
        void gcMark(){
          bbGCMarkPtr(l_func);
          bbGCMarkPtr(l_infered);
        }
      }f2{};
      f2.l_func=f1.l_0.m_Current();
      if(!f2.l_func->m_IsGeneric()){
        if(g_mx2_overload_IsCandidate(f2.l_func,l_ret,l_args,((bbArray<bbGCVar<t_mx2_Type>>*)0))){
          f0.l_candidates->m_Push(f2.l_func);
        }
        continue;
      }
      f2.l_infered=bbArray<bbGCVar<t_mx2_Type>>::create(f2.l_func->m_types->length());
      if(g_mx2_overload_IsCandidate(f2.l_func,l_ret,l_args,f2.l_infered)){
        g_mx2_overload_Linearize(f2.l_infered,f2.l_func,f0.l_candidates,bbInt(0));
      }
    }
  }
  {
    struct f1_t : public bbGCFrame{
      t_std_collections_Stack_1Tt_mx2_FuncValue_2_Iterator l_1{};
      void gcMark(){
        bbGCMark(l_1);
      }
    }f1{};
    f1.l_1=f0.l_candidates->m_All();
    for(;!f1.l_1.m_AtEnd();f1.l_1.m_Bump()){
      struct f2_t : public bbGCFrame{
        t_mx2_FuncValue* l_func{};
        void gcMark(){
          bbGCMarkPtr(l_func);
        }
      }f2{};
      f2.l_func=f1.l_1.m_Current();
      bbBool l_better=true;
      {
        struct f3_t : public bbGCFrame{
          t_std_collections_Stack_1Tt_mx2_FuncValue_2_Iterator l_2{};
          void gcMark(){
            bbGCMark(l_2);
          }
        }f3{};
        f3.l_2=f0.l_candidates->m_All();
        for(;!f3.l_2.m_AtEnd();f3.l_2.m_Bump()){
          struct f4_t : public bbGCFrame{
            t_mx2_FuncValue* l_func2{};
            void gcMark(){
              bbGCMarkPtr(l_func2);
            }
          }f4{};
          f4.l_func2=f3.l_2.m_Current();
          if((f4.l_func2==f2.l_func)){
            continue;
          }
          if(g_mx2_overload_IsBetter(f2.l_func,f4.l_func2,l_args)){
            continue;
          }
          l_better=false;
          break;
        }
      }
      if(!l_better){
        continue;
      }
      if(bbBool(f0.l_match)){
        return ((t_mx2_FuncValue*)0);
      }
      f0.l_match=f2.l_func;
    }
  }
  return f0.l_match;
}

void g_mx2_overload_Linearize(bbArray<bbGCVar<t_mx2_Type>>* l_types,t_mx2_FuncValue* l_func,t_std_collections_Stack_1Tt_mx2_FuncValue_2* l_funcs,bbInt l_j){
  struct f0_t : public bbGCFrame{
    t_mx2_FuncValue* l_func2{};
    bbArray<bbGCVar<t_mx2_Type>>* l_types{};
    f0_t(bbArray<bbGCVar<t_mx2_Type>>* l_types):l_types(l_types){
    }
    void gcMark(){
      bbGCMarkPtr(l_func2);
      bbGCMarkPtr(l_types);
    }
  }f0{l_types};
  {
    bbInt l_i=l_j;
    for(;(l_i<f0.l_types->length());l_i+=1){
      struct f2_t : public bbGCFrame{
        t_mx2_FuncListType* l_flist{};
        t_mx2_Type* l_type{};
        void gcMark(){
          bbGCMarkPtr(l_flist);
          bbGCMarkPtr(l_type);
        }
      }f2{};
      f2.l_type=f0.l_types->at(l_i);
      f2.l_flist=g_mx2_TCast_1Tt_mx2_FuncListType_2(f2.l_type);
      if(!bbBool(f2.l_flist)){
        continue;
      }
      f0.l_types=f0.l_types->slice(bbInt(0));
      {
        struct f3_t : public bbGCFrame{
          t_std_collections_Stack_1Tt_mx2_FuncValue_2_Iterator l_0{};
          void gcMark(){
            bbGCMark(l_0);
          }
        }f3{};
        f3.l_0=f2.l_flist->m_funcs->m_All();
        for(;!f3.l_0.m_AtEnd();f3.l_0.m_Bump()){
          struct f4_t : public bbGCFrame{
            t_mx2_FuncValue* l_func2{};
            void gcMark(){
              bbGCMarkPtr(l_func2);
            }
          }f4{};
          f4.l_func2=f3.l_0.m_Current();
          f0.l_types->at(l_i)=((t_mx2_Type*)(f4.l_func2->m_ftype));
          g_mx2_overload_Linearize(f0.l_types,l_func,l_funcs,(l_i+1));
        }
      }
      return;
    }
  }
  f0.l_func2=l_func->m_TryGenInstance(f0.l_types);
  if(bbBool(f0.l_func2)){
    l_funcs->m_Push(f0.l_func2);
  }
}

bbBool g_mx2_overload_IsBetter(t_mx2_FuncValue* l_func,t_mx2_FuncValue* l_func2,bbArray<bbGCVar<t_mx2_Type>>* l_args){
  bbBool l_better=false;
  bbBool l_exact=true;
  {
    bbInt l_i=bbInt(0);
    for(;(l_i<l_args->length());l_i+=1){
      if(!bbBool(l_args->at(l_i))){
        continue;
      }
      bbInt l_dist1=l_args->at(l_i)->m_DistanceToType(l_func->m_ftype->m_argTypes->at(l_i));
      bbInt l_dist2=l_args->at(l_i)->m_DistanceToType(l_func2->m_ftype->m_argTypes->at(l_i));
      if(((l_dist1==-1)||(l_dist2==-1))){
        g_mx2_SemantError(BB_T("FuncListType.IsBetter()"));
      }
      if((l_dist1>l_dist2)){
        return false;
      }
      if((l_dist1<l_dist2)){
        l_better=true;
      }
      if(bbBool(l_dist1)){
        l_exact=false;
      }
    }
  }
  if(l_better){
    return true;
  }
  if(((l_exact&&!bbBool(l_func->m_instanceOf))&&bbBool(l_func2->m_instanceOf))){
    return true;
  }
  if((bbBool(l_func->m_instanceOf)&&bbBool(l_func2->m_instanceOf))){
    if(g_mx2_overload_CanInfer(l_func2->m_instanceOf,l_func->m_instanceOf->m_ftype->m_argTypes)){
      if(!g_mx2_overload_CanInfer(l_func->m_instanceOf,l_func2->m_instanceOf->m_ftype->m_argTypes)){
        return true;
      }
    }
  }
  return false;
}

bbBool g_mx2_overload_CanInfer(t_mx2_FuncValue* l_func,bbArray<bbGCVar<t_mx2_Type>>* l_args){
  struct f0_t : public bbGCFrame{
    bbArray<bbGCVar<t_mx2_Type>>* l_argTypes{};
    t_mx2_FuncType* l_ftype{};
    bbArray<bbGCVar<t_mx2_Type>>* l_infered{};
    void gcMark(){
      bbGCMarkPtr(l_argTypes);
      bbGCMarkPtr(l_ftype);
      bbGCMarkPtr(l_infered);
    }
  }f0{};
  if(!l_func->m_IsGeneric()){
    g_mx2_SemantError(BB_T("overload.CanInfer()"));
  }
  f0.l_ftype=l_func->m_ftype;
  f0.l_argTypes=f0.l_ftype->m_argTypes;
  f0.l_infered=bbArray<bbGCVar<t_mx2_Type>>::create(l_func->m_types->length());
  {
    bbInt l_i=bbInt(0);
    for(;(l_i<g_monkey_math_Min_1i(l_args->length(),f0.l_argTypes->length()));l_i+=1){
      if((f0.l_argTypes->at(l_i)->m_IsGeneric()&&!bbBool(f0.l_argTypes->at(l_i)->m_InferType(l_args->at(l_i),f0.l_infered)))){
        return false;
      }
    }
  }
  {
    bbInt l_i=bbInt(0);
    for(;(l_i<f0.l_infered->length());l_i+=1){
      if((!bbBool(f0.l_infered->at(l_i))||f0.l_infered->at(l_i)->m__eq(((t_mx2_Type*)(g_mx2_Type_BadType))))){
        return false;
      }
    }
  }
  return true;
}

bbBool g_mx2_overload_IsCandidate(t_mx2_FuncValue* l_func,t_mx2_Type* l_ret,bbArray<bbGCVar<t_mx2_Type>>* l_args,bbArray<bbGCVar<t_mx2_Type>>* l_infered){
  struct f0_t : public bbGCFrame{
    bbArray<bbGCVar<t_mx2_Type>>* l_argTypes{};
    t_mx2_FuncType* l_ftype{};
    t_mx2_Type* l_retType{};
    void gcMark(){
      bbGCMarkPtr(l_argTypes);
      bbGCMarkPtr(l_ftype);
      bbGCMarkPtr(l_retType);
    }
  }f0{};
  f0.l_ftype=l_func->m_ftype;
  f0.l_retType=f0.l_ftype->m_retType;
  f0.l_argTypes=f0.l_ftype->m_argTypes;
  if((l_args->length()>f0.l_argTypes->length())){
    return false;
  }
  if(bbBool(l_ret)){
    if(f0.l_retType->m_IsGeneric()){
      if(!bbBool(f0.l_retType->m_InferType(l_ret,l_infered))){
        return false;
      }
    }else if(!l_ret->m_IsGeneric()){
      if(!f0.l_retType->m_ExtendsType(l_ret)){
        return false;
      }
    }
  }
  if(((bbBool(l_ret)&&f0.l_retType->m_IsGeneric())&&!bbBool(f0.l_retType->m_InferType(l_ret,l_infered)))){
    return false;
  }
  {
    bbInt l_i=bbInt(0);
    for(;(l_i<f0.l_argTypes->length());l_i+=1){
      if(((l_i>=l_args->length())||!bbBool(l_args->at(l_i)))){
        struct f3_t : public bbGCFrame{
          t_mx2_VarDecl* l_pdecl{};
          void gcMark(){
            bbGCMarkPtr(l_pdecl);
          }
        }f3{};
        f3.l_pdecl=l_func->m_pdecls->at(l_i);
        if(!bbBool(f3.l_pdecl->m_init)){
          return false;
        }
      }else if(f0.l_argTypes->at(l_i)->m_IsGeneric()){
        struct f3_t : public bbGCFrame{
          t_mx2_Type* l_arg{};
          t_mx2_FuncListType* l_flist{};
          void gcMark(){
            bbGCMarkPtr(l_arg);
            bbGCMarkPtr(l_flist);
          }
        }f3{};
        f3.l_arg=l_args->at(l_i);
        f3.l_flist=g_mx2_TCast_1Tt_mx2_FuncListType_2(f3.l_arg);
        if(bbBool(f3.l_flist)){
          struct f4_t : public bbGCFrame{
            t_mx2_FuncType* l_ftype{};
            t_mx2_FuncValue* l_func{};
            void gcMark(){
              bbGCMarkPtr(l_ftype);
              bbGCMarkPtr(l_func);
            }
          }f4{};
          f4.l_ftype=g_mx2_TCast_1Tt_mx2_FuncType_2(f0.l_argTypes->at(l_i));
          if(!bbBool(f4.l_ftype)){
            return false;
          }
          f4.l_func=f3.l_flist->m_FindOverload(((t_mx2_Type*)0),f4.l_ftype->m_argTypes);
          if(!bbBool(f4.l_func)){
            return false;
          }
          f3.l_arg=((t_mx2_Type*)(f4.l_func->m_ftype));
        }
        if(!bbBool(f0.l_argTypes->at(l_i)->m_InferType(f3.l_arg,l_infered))){
          return false;
        }
      }else{
        if((l_args->at(l_i)->m_DistanceToType(f0.l_argTypes->at(l_i))<bbInt(0))){
          return false;
        }
      }
    }
  }
  {
    bbInt l_i=bbInt(0);
    for(;(l_i<l_infered->length());l_i+=1){
      if((!bbBool(l_infered->at(l_i))||l_infered->at(l_i)->m__eq(((t_mx2_Type*)(g_mx2_Type_BadType))))){
        return false;
      }
    }
  }
  return true;
}

void mx2_mx2cc_overload_init(){
  static bool done;
  if(done) return;
  done=true;
}

bbInit mx2_mx2cc_overload_init_v("mx2cc_overload",&mx2_mx2cc_overload_init);
