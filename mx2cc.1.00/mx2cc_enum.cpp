
#include "mx2cc_enum.h"

// ***** External *****

#include "../../../../../modules/monkey/monkey.buildv1.0.0/desktop_release_linux/monkey_types.h"
#include "mx2cc_errors.h"
#include "mx2cc_expr.h"
#include "mx2cc_node.h"
#include "mx2cc_typeexpr.h"
#include "mx2cc_value.h"
#include "mx2cc_var.h"

// ***** Internal *****

void t_mx2_EnumType::gcMark(){
  t_mx2_Type::gcMark();
  bbGCMark(m_edecl);
  bbGCMark(m_scope);
  bbGCMark(m_superType);
}

t_mx2_EnumType::t_mx2_EnumType(t_mx2_EnumDecl* l_edecl,t_mx2_Scope* l_outer){
  this->m_pnode=((t_mx2_PNode*)(l_edecl));
  this->m_edecl=l_edecl;
  this->m_scope=bbGCNew<t_mx2_EnumScope>(this,l_outer);
}

bbString t_mx2_EnumType::m_TypeId(){
  return ((this->m_scope->m_TypeId()+BB_T("_"))+this->m_edecl->m_ident);
}

bbString t_mx2_EnumType::m_ToString(){
  return this->m_edecl->m_ident;
}

t_mx2_SNode* t_mx2_EnumType::m_OnSemant(){
  if(bbBool(this->m_edecl->m_superType)){
    try{
      struct f2_t : public bbGCFrame{
        t_mx2_Type* t0{};
        void gcMark(){
          bbGCMarkPtr(t0);
        }
      }f2{};
      this->m_superType=g_mx2_TCast_1Tt_mx2_EnumType_2(f2.t0=this->m_edecl->m_superType->m_Semant(((t_mx2_Scope*)(this->m_scope)),false));
      if((!bbBool(this->m_superType)||(this->m_superType->m_edecl->m_kind!=BB_T("enum")))){
        throw bbGCNew<t_mx2_SemantEx>((BB_T("Cant find super type ")+this->m_edecl->m_superType->m_ToString()),((t_mx2_PNode*)(this->m_edecl)));
      }
      this->m_nextInit=this->m_superType->m_nextInit;
    }catch(t_mx2_ParseEx* ex){
      struct f2_t : public bbGCFrame{
        t_mx2_ParseEx* l_ex{};
        void gcMark(){
          bbGCMarkPtr(l_ex);
        }
      }f2{};
      f2.l_ex=ex;
    }
  }
  {
    bbInt l_0=bbInt(0);
    bbInt l_1=this->m_edecl->m_members->length();
    for(;(l_0<l_1);l_0+=1){
      struct f2_t : public bbGCFrame{
        t_mx2_Decl* l_decl{};
        t_mx2_VarDecl* l_vdecl{};
        void gcMark(){
          bbGCMarkPtr(l_decl);
          bbGCMarkPtr(l_vdecl);
        }
      }f2{};
      f2.l_decl=this->m_edecl->m_members->at(l_0);
      f2.l_vdecl=bb_object_cast<t_mx2_VarDecl*>(f2.l_decl);
      if(this->m_edecl->m_IsExtern()){
        struct f3_t : public bbGCFrame{
          t_mx2_LiteralValue* l_value{};
          void gcMark(){
            bbGCMarkPtr(l_value);
          }
        }f3{};
        bbString l_symbol=f2.l_vdecl->m_symbol;
        if(!bbBool(l_symbol)){
          l_symbol=(BB_T("@")+f2.l_vdecl->m_ident);
        }
        f3.l_value=bbGCNew<t_mx2_LiteralValue>(((t_mx2_Type*)(this)),l_symbol);
        this->m_scope->m_Insert(f2.l_decl->m_ident,((t_mx2_SNode*)(f3.l_value)));
      }else{
        struct f3_t : public bbGCFrame{
          t_mx2_LiteralValue* l_value{};
          void gcMark(){
            bbGCMarkPtr(l_value);
          }
        }f3{};
        if(bbBool(f2.l_vdecl->m_init)){
          try{
            struct f5_t : public bbGCFrame{
              t_mx2_LiteralValue* l_value{};
              void gcMark(){
                bbGCMarkPtr(l_value);
              }
            }f5{};
            f5.l_value=bb_object_cast<t_mx2_LiteralValue*>(f2.l_vdecl->m_init->m_SemantRValue(((t_mx2_Scope*)(this->m_scope)),((t_mx2_Type*)0)));
            if(!bbBool(f5.l_value)){
              throw bbGCNew<t_mx2_SemantEx>(((BB_T("Enum member '")+f2.l_vdecl->m_ToString())+BB_T("' initalizer must be constant")),((t_mx2_PNode*)(f2.l_vdecl)));
            }
            if((f5.l_value->m_type->m__ne(((t_mx2_Type*)(g_mx2_Type_IntType)))&&f5.l_value->m_type->m__ne(((t_mx2_Type*)(this))))){
              throw bbGCNew<t_mx2_SemantEx>(((BB_T("Enum member '")+f2.l_vdecl->m_ToString())+BB_T("' type error")));
            }
            this->m_nextInit=bbInt(f5.l_value->m_value);
          }catch(t_mx2_SemantEx* ex){
            struct f5_t : public bbGCFrame{
              t_mx2_SemantEx* l_ex{};
              void gcMark(){
                bbGCMarkPtr(l_ex);
              }
            }f5{};
            f5.l_ex=ex;
          }
        }
        f3.l_value=bbGCNew<t_mx2_LiteralValue>(((t_mx2_Type*)(this)),bbString(this->m_nextInit));
        this->m_scope->m_Insert(f2.l_decl->m_ident,((t_mx2_SNode*)(f3.l_value)));
        this->m_nextInit+=1;
      }
    }
  }
  return ((t_mx2_SNode*)(this));
}

bbString t_mx2_EnumType::m_Name(){
  return ((this->m_scope->m_Name()+BB_T("."))+this->m_edecl->m_ident);
}

t_mx2_SNode* t_mx2_EnumType::m_FindNode(bbString l_ident){
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
  if(bbBool(this->m_superType)){
    return this->m_superType->m_FindNode(l_ident);
  }
  return ((t_mx2_SNode*)0);
}

bbInt t_mx2_EnumType::m_DistanceToType(t_mx2_Type* l_type){
  struct f0_t : public bbGCFrame{
    t_mx2_EnumType* l_etype{};
    t_mx2_PrimType* l_ptype{};
    void gcMark(){
      bbGCMarkPtr(l_etype);
      bbGCMarkPtr(l_ptype);
    }
  }f0{};
  if(l_type->m__eq(((t_mx2_Type*)(this)))){
    return bbInt(0);
  }
  f0.l_ptype=g_mx2_TCast_1Tt_mx2_PrimType_2(l_type);
  if(bbBool(f0.l_ptype)){
    if(f0.l_ptype->m__eq(((t_mx2_Type*)(g_mx2_Type_BoolType)))){
      return g_mx2_Type_MAX_0DISTANCE;
    }
    if(f0.l_ptype->m_IsIntegral()){
      return g_mx2_Type_MAX_0DISTANCE;
    }
    return -1;
  }
  f0.l_etype=g_mx2_TCast_1Tt_mx2_EnumType_2(l_type);
  if(!bbBool(f0.l_etype)){
    return -1;
  }
  bbInt l_dist=bbInt(0);
  while(bbBool(f0.l_etype)){
    if(f0.l_etype->m__eq(((t_mx2_Type*)(this)))){
      return l_dist;
    }
    f0.l_etype=f0.l_etype->m_superType;
  }
  return -1;
}

void t_mx2_EnumDecl::gcMark(){
  t_mx2_Decl::gcMark();
  bbGCMark(m_superType);
}

t_mx2_SNode* t_mx2_EnumDecl::m_ToNode(t_mx2_Scope* l_scope){
  return ((t_mx2_SNode*)(bbGCNew<t_mx2_EnumType>(this,l_scope)));
}

void t_mx2_EnumScope::gcMark(){
  t_mx2_Scope::gcMark();
  bbGCMark(m_etype);
}

t_mx2_EnumScope::t_mx2_EnumScope(t_mx2_EnumType* l_etype,t_mx2_Scope* l_outer):t_mx2_Scope(l_outer){
  this->m_etype=l_etype;
}

void mx2_mx2cc_enum_init(){
  static bool done;
  if(done) return;
  done=true;
}

bbInit mx2_mx2cc_enum_init_v("mx2cc_enum",&mx2_mx2cc_enum_init);
