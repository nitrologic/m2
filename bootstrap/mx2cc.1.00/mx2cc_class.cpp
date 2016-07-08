
#include "mx2cc_class.h"

// ***** External *****

#include "../../../../../modules/monkey/monkey.buildv1.0.0/desktop_release_linux/monkey_types.h"
#include "mx2cc_builder.h"
#include "mx2cc_errors.h"
#include "mx2cc_func.h"
#include "mx2cc_module.h"
#include "mx2cc_node.h"
#include "mx2cc_std_collections_2list.h"
#include "mx2cc_std_collections_2map.h"
#include "mx2cc_std_collections_2stack.h"
#include "mx2cc_stmt.h"
#include "mx2cc_typeexpr.h"
#include "mx2cc_var.h"

extern bbBool g_mx2_AnyTypeGeneric(bbArray<bbGCVar<t_mx2_Type>>* l_types);
extern bbString g_mx2_Join_1Tt_mx2_Type_2(bbArray<bbGCVar<t_mx2_Type>>* l_bits,bbString l_sep);
extern bbBool g_mx2_TypesEqual(bbArray<bbGCVar<t_mx2_Type>>* l_lhs,bbArray<bbGCVar<t_mx2_Type>>* l_rhs);
extern bbString g_mx2_Join_1Tt_mx2_TypeExpr_2(bbArray<bbGCVar<t_mx2_TypeExpr>>* l_bits,bbString l_sep);
extern bbString g_mx2_Join_1Tt_mx2_Value_2(bbArray<bbGCVar<t_mx2_Value>>* l_bits,bbString l_sep);
extern t_mx2_Type* g_mx2_BalanceAssignTypes(bbString l_op,t_mx2_Type* l_lhs,t_mx2_Type* l_rhs);

// ***** Internal *****

void t_mx2_ClassType::init(){
  m_ctors=bbGCNew<t_std_collections_Stack_1Tt_mx2_FuncValue_2>();
  m_methods=bbGCNew<t_std_collections_Stack_1Tt_mx2_FuncValue_2>();
  m_fields=bbGCNew<t_std_collections_Stack_1Tt_mx2_VarValue_2>();
}

void t_mx2_ClassType::gcMark(){
  t_mx2_Type::gcMark();
  bbGCMark(m_cdecl);
  bbGCMark(m_types);
  bbGCMark(m_instanceOf);
  bbGCMark(m_transFile);
  bbGCMark(m_scope);
  bbGCMark(m_superType);
  bbGCMark(m_ifaceTypes);
  bbGCMark(m_allIfaces);
  bbGCMark(m_instances);
  bbGCMark(m_abstractMethods);
  bbGCMark(m_ctors);
  bbGCMark(m_methods);
  bbGCMark(m_fields);
}

t_mx2_ClassType::t_mx2_ClassType(t_mx2_ClassDecl* l_cdecl,t_mx2_Scope* l_outer,bbArray<bbGCVar<t_mx2_Type>>* l_types,t_mx2_ClassType* l_instanceOf){
  init();
  this->m_pnode=((t_mx2_PNode*)(l_cdecl));
  this->m_cdecl=l_cdecl;
  this->m_types=l_types;
  this->m_instanceOf=l_instanceOf;
  this->m_transFile=l_outer->m_FindFile()->m_fdecl;
  if(g_mx2_AnyTypeGeneric(l_types)){
    this->m_flags|=g_mx2_Type_TYPE_0GENERIC;
  }
  this->m_scope=bbGCNew<t_mx2_ClassScope>(this,l_outer);
  {
    bbInt l_0=bbInt(0);
    bbInt l_1=l_cdecl->m_members->length();
    for(;(l_0<l_1);l_0+=1){
      struct f2_t : public bbGCFrame{
        t_mx2_Decl* l_member{};
        t_mx2_SNode* l_node{};
        void gcMark(){
          bbGCMarkPtr(l_member);
          bbGCMarkPtr(l_node);
        }
      }f2{};
      f2.l_member=l_cdecl->m_members->at(l_0);
      f2.l_node=f2.l_member->m_ToNode(((t_mx2_Scope*)(this->m_scope)));
      this->m_scope->m_Insert(f2.l_member->m_ident,f2.l_node);
      if(f2.l_member->m_kind==BB_T("field")){
        this->m_fields->m_Push(bb_object_cast<t_mx2_VarValue*>(f2.l_node));
      }
    }
  }
}

bbString t_mx2_ClassType::m_TypeId(){
  return this->m_scope->m_TypeId();
}

bbString t_mx2_ClassType::m_ToString(){
  bbString l_str=this->m_cdecl->m_ident;
  if(bbBool(this->m_types)){
    l_str+=((BB_T("<")+g_mx2_Join_1Tt_mx2_Type_2(this->m_types,BB_T(",")))+BB_T(">"));
  }
  return l_str;
}

void t_mx2_ClassType::m_SemantMembers(){
  struct f0_t : public bbGCFrame{
    t_std_collections_Stack_1Tt_mx2_FuncValue_2* l_abstractMethods{};
    t_std_collections_Stack_1Tt_mx2_FuncList_2* l_flists{};
    void gcMark(){
      bbGCMarkPtr(l_abstractMethods);
      bbGCMarkPtr(l_flists);
    }
  }f0{};
  if((this->m_membersSemanted||this->m_membersSemanting)){
    return;
  }
  this->m_membersSemanting=true;
  f0.l_flists=bbGCNew<t_std_collections_Stack_1Tt_mx2_FuncList_2>();
  f0.l_abstractMethods=bbGCNew<t_std_collections_Stack_1Tt_mx2_FuncValue_2>();
  {
    struct f1_t : public bbGCFrame{
      t_std_collections_Map_1sTt_mx2_SNode_2_Iterator l_0{};
      void gcMark(){
        bbGCMark(l_0);
      }
    }f1{};
    f1.l_0=this->m_scope->m_nodes->m_All();
    for(;f1.l_0.m_Valid();f1.l_0.m_Bump()){
      struct f2_t : public bbGCFrame{
        t_mx2_FuncList* l_flist{};
        t_std_collections_Map_1sTt_mx2_SNode_2_Node* l_it{};
        void gcMark(){
          bbGCMarkPtr(l_flist);
          bbGCMarkPtr(l_it);
        }
      }f2{};
      f2.l_it=f1.l_0.m_Current();
      f2.l_flist=bb_object_cast<t_mx2_FuncList*>(f2.l_it->m_Value());
      if(!bbBool(f2.l_flist)){
        continue;
      }
      f2.l_flist->m_Semant();
      if((f2.l_flist->m_ident==BB_T("new"))){
        continue;
      }
      f0.l_flists->m_Push(f2.l_flist);
      {
        struct f3_t : public bbGCFrame{
          t_std_collections_Stack_1Tt_mx2_FuncValue_2_Iterator l_1{};
          void gcMark(){
            bbGCMark(l_1);
          }
        }f3{};
        f3.l_1=f2.l_flist->m_funcs->m_All();
        for(;!f3.l_1.m_AtEnd();f3.l_1.m_Bump()){
          struct f4_t : public bbGCFrame{
            t_mx2_FuncValue* l_func{};
            void gcMark(){
              bbGCMarkPtr(l_func);
            }
          }f4{};
          f4.l_func=f3.l_1.m_Current();
          if(f4.l_func->m_fdecl->m_IsIfaceMember()){
            f0.l_abstractMethods->m_Push(f4.l_func);
          }
        }
      }
    }
  }
  if((((this->m_cdecl->m_kind==BB_T("class"))||(this->m_cdecl->m_kind==BB_T("struct")))&&!this->m_scope->m_IsGeneric())){
    if(bbBool(this->m_superType)){
      {
        bbInt l_2=bbInt(0);
        bbInt l_3=this->m_superType->m_abstractMethods->length();
        for(;(l_2<l_3);l_2+=1){
          struct f4_t : public bbGCFrame{
            t_mx2_FuncValue* l_func{};
            void gcMark(){
              bbGCMarkPtr(l_func);
            }
          }f4{};
          f4.l_func=this->m_superType->m_abstractMethods->at(l_2);
          try{
            struct f5_t : public bbGCFrame{
              t_mx2_FuncList* l_flist{};
              void gcMark(){
                bbGCMarkPtr(l_flist);
              }
            }f5{};
            f5.l_flist=bb_object_cast<t_mx2_FuncList*>(this->m_scope->m_nodes->m__idx(f4.l_func->m_fdecl->m_ident));
            if(bbBool(f5.l_flist)){
              struct f6_t : public bbGCFrame{
                t_mx2_FuncValue* l_func2{};
                void gcMark(){
                  bbGCMarkPtr(l_func2);
                }
              }f6{};
              f6.l_func2=f5.l_flist->m_FindFunc(f4.l_func->m_ftype->m_argTypes);
              if(bbBool(f6.l_func2)){
                if(f6.l_func2->m_ftype->m_retType->m_ExtendsType(f4.l_func->m_ftype->m_retType)){
                  continue;
                }
                throw bbGCNew<t_mx2_SemantEx>(((BB_T("Overriding method '")+f6.l_func2->m_ToString())+BB_T("' has incompatible return type")),((t_mx2_PNode*)(f6.l_func2->m_fdecl)));
              }
            }
            f0.l_abstractMethods->m_Push(f4.l_func);
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
      }
    }
    {
      bbInt l_4=bbInt(0);
      bbInt l_5=this->m_allIfaces->length();
      for(;(l_4<l_5);l_4+=1){
        struct f3_t : public bbGCFrame{
          t_mx2_ClassType* l_iface{};
          void gcMark(){
            bbGCMarkPtr(l_iface);
          }
        }f3{};
        f3.l_iface=this->m_allIfaces->at(l_4);
        if((bbBool(this->m_superType)&&this->m_superType->m_ExtendsType(((t_mx2_Type*)(f3.l_iface))))){
          continue;
        }
        {
          bbInt l_6=bbInt(0);
          bbInt l_7=f3.l_iface->m_abstractMethods->length();
          for(;(l_6<l_7);l_6+=1){
            struct f5_t : public bbGCFrame{
              t_mx2_FuncValue* l_func{};
              void gcMark(){
                bbGCMarkPtr(l_func);
              }
            }f5{};
            f5.l_func=f3.l_iface->m_abstractMethods->at(l_6);
            try{
              struct f6_t : public bbGCFrame{
                t_mx2_FuncList* l_flist{};
                void gcMark(){
                  bbGCMarkPtr(l_flist);
                }
              }f6{};
              f6.l_flist=bb_object_cast<t_mx2_FuncList*>(this->m_scope->m_nodes->m__idx(f5.l_func->m_fdecl->m_ident));
              if(bbBool(f6.l_flist)){
                struct f7_t : public bbGCFrame{
                  t_mx2_FuncValue* l_func2{};
                  void gcMark(){
                    bbGCMarkPtr(l_func2);
                  }
                }f7{};
                f7.l_func2=f6.l_flist->m_FindFunc(f5.l_func->m_ftype->m_argTypes);
                if(bbBool(f7.l_func2)){
                  if(f7.l_func2->m_ftype->m_retType->m_ExtendsType(f5.l_func->m_ftype->m_retType)){
                    continue;
                  }
                  throw bbGCNew<t_mx2_SemantEx>(((BB_T("Overriding method '")+f7.l_func2->m_ToString())+BB_T("' has incompatible return type")),((t_mx2_PNode*)(f7.l_func2->m_fdecl)));
                }
              }
              if(f5.l_func->m_fdecl->m_IsDefault()){
                this->m_scope->m_Insert(f5.l_func->m_fdecl->m_ident,((t_mx2_SNode*)(f5.l_func)));
                continue;
              }
              f0.l_abstractMethods->m_Push(f5.l_func);
            }catch(t_mx2_SemantEx* ex){
              struct f6_t : public bbGCFrame{
                t_mx2_SemantEx* l_ex{};
                void gcMark(){
                  bbGCMarkPtr(l_ex);
                }
              }f6{};
              f6.l_ex=ex;
            }
          }
        }
      }
    }
    if(bbBool(this->m_superType)){
      {
        struct f3_t : public bbGCFrame{
          t_std_collections_Stack_1Tt_mx2_FuncList_2_Iterator l_8{};
          void gcMark(){
            bbGCMark(l_8);
          }
        }f3{};
        f3.l_8=f0.l_flists->m_All();
        for(;!f3.l_8.m_AtEnd();f3.l_8.m_Bump()){
          struct f4_t : public bbGCFrame{
            t_mx2_FuncList* l_flist{};
            t_mx2_FuncList* l_flist2{};
            void gcMark(){
              bbGCMarkPtr(l_flist);
              bbGCMarkPtr(l_flist2);
            }
          }f4{};
          f4.l_flist=f3.l_8.m_Current();
          f4.l_flist2=bb_object_cast<t_mx2_FuncList*>(this->m_superType->m_scope->m_GetNode(f4.l_flist->m_ident));
          if(!bbBool(f4.l_flist2)){
            continue;
          }
          {
            struct f5_t : public bbGCFrame{
              t_std_collections_Stack_1Tt_mx2_FuncValue_2_Iterator l_9{};
              void gcMark(){
                bbGCMark(l_9);
              }
            }f5{};
            f5.l_9=f4.l_flist2->m_funcs->m_All();
            for(;!f5.l_9.m_AtEnd();f5.l_9.m_Bump()){
              struct f6_t : public bbGCFrame{
                t_mx2_FuncValue* l_func2{};
                void gcMark(){
                  bbGCMarkPtr(l_func2);
                }
              }f6{};
              f6.l_func2=f5.l_9.m_Current();
              if(!bbBool(f4.l_flist->m_FindFunc(f6.l_func2->m_ftype->m_argTypes))){
                f4.l_flist->m_PushFunc(f6.l_func2);
              }
            }
          }
        }
      }
    }
  }
  this->m_abstractMethods=f0.l_abstractMethods->m_ToArray();
  this->m_membersSemanting=false;
  this->m_membersSemanted=true;
  {
    struct f1_t : public bbGCFrame{
      t_std_collections_Map_1sTt_mx2_SNode_2_Iterator l_10{};
      void gcMark(){
        bbGCMark(l_10);
      }
    }f1{};
    f1.l_10=this->m_scope->m_nodes->m_All();
    for(;f1.l_10.m_Valid();f1.l_10.m_Bump()){
      struct f2_t : public bbGCFrame{
        t_std_collections_Map_1sTt_mx2_SNode_2_Node* l_it{};
        void gcMark(){
          bbGCMarkPtr(l_it);
        }
      }f2{};
      f2.l_it=f1.l_10.m_Current();
      try{
        if(!bbBool(bb_object_cast<t_mx2_FuncList*>(f2.l_it->m_Value()))){
          struct f4_t : public bbGCFrame{
            t_mx2_SNode* t0{};
            void gcMark(){
              bbGCMarkPtr(t0);
            }
          }f4{};
          (f4.t0=f2.l_it->m_Value())->m_Semant();
        }
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
}

t_mx2_SNode* t_mx2_ClassType::m_OnSemant(){
  struct f0_t : public bbGCFrame{
    t_mx2_Builder* l_builder{};
    void gcMark(){
      bbGCMarkPtr(l_builder);
    }
  }f0{};
  if(bbBool(this->m_cdecl->m_superType)){
    try{
      struct f2_t : public bbGCFrame{
        t_mx2_Type* l_type{};
        void gcMark(){
          bbGCMarkPtr(l_type);
        }
      }f2{};
      f2.l_type=this->m_cdecl->m_superType->m_Semant(((t_mx2_Scope*)(this->m_scope)),false);
      if(bbBool(g_mx2_TCast_1Tt_mx2_VoidType_2(f2.l_type))){
        if((!this->m_cdecl->m_IsExtern()||(this->m_cdecl->m_kind!=BB_T("class")))){
          throw bbGCNew<t_mx2_SemantEx>(BB_T("Only extern classes can extend 'Void'"));
        }
        this->m_isvoid=true;
      }else{
        this->m_superType=g_mx2_TCast_1Tt_mx2_ClassType_2(f2.l_type);
        if((!bbBool(this->m_superType)||(this->m_superType->m_cdecl->m_kind!=this->m_cdecl->m_kind))){
          throw bbGCNew<t_mx2_SemantEx>(((BB_T("Type '")+f2.l_type->m_ToString())+BB_T("' is not a valid super class type")));
        }
        if((this->m_superType->m_state==g_mx2_SNODE_0SEMANTING)){
          throw bbGCNew<t_mx2_SemantEx>(((BB_T("Cyclic inheritance error for '")+this->m_ToString())+BB_T("'")),((t_mx2_PNode*)(this->m_cdecl)));
        }
        if(this->m_superType->m_cdecl->m_IsFinal()){
          throw bbGCNew<t_mx2_SemantEx>(((BB_T("Superclass '")+this->m_superType->m_ToString())+BB_T("' is final")));
        }
      }
    }catch(t_mx2_SemantEx* ex){
      struct f2_t : public bbGCFrame{
        t_mx2_SemantEx* l_ex{};
        void gcMark(){
          bbGCMarkPtr(l_ex);
        }
      }f2{};
      f2.l_ex=ex;
      this->m_superType=((t_mx2_ClassType*)0);
    }
  }else if(((this->m_cdecl->m_kind==BB_T("class"))&&this->m__ne(((t_mx2_Type*)(g_mx2_Type_ObjectClass))))){
    this->m_superType=g_mx2_Type_ObjectClass;
  }
  if(bbBool(this->m_cdecl->m_ifaceTypes)){
    struct f1_t : public bbGCFrame{
      t_std_collections_Stack_1Tt_mx2_ClassType_2* l_allifaces{};
      t_std_collections_Stack_1Tt_mx2_ClassType_2* l_ifaces{};
      void gcMark(){
        bbGCMarkPtr(l_allifaces);
        bbGCMarkPtr(l_ifaces);
      }
    }f1{};
    f1.l_ifaces=bbGCNew<t_std_collections_Stack_1Tt_mx2_ClassType_2>();
    f1.l_allifaces=bbGCNew<t_std_collections_Stack_1Tt_mx2_ClassType_2>();
    {
      bbInt l_0=bbInt(0);
      bbInt l_1=this->m_cdecl->m_ifaceTypes->length();
      for(;(l_0<l_1);l_0+=1){
        struct f3_t : public bbGCFrame{
          t_mx2_TypeExpr* l_iface{};
          void gcMark(){
            bbGCMarkPtr(l_iface);
          }
        }f3{};
        f3.l_iface=this->m_cdecl->m_ifaceTypes->at(l_0);
        try{
          struct f4_t : public bbGCFrame{
            t_mx2_ClassType* l_ifaceType{};
            t_mx2_Type* l_type{};
            void gcMark(){
              bbGCMarkPtr(l_ifaceType);
              bbGCMarkPtr(l_type);
            }
          }f4{};
          f4.l_type=f3.l_iface->m_Semant(((t_mx2_Scope*)(this->m_scope)),false);
          f4.l_ifaceType=g_mx2_TCast_1Tt_mx2_ClassType_2(f4.l_type);
          if((!bbBool(f4.l_ifaceType)||((f4.l_ifaceType->m_cdecl->m_kind!=BB_T("interface"))&&(f4.l_ifaceType->m_cdecl->m_kind!=BB_T("protocol"))))){
            throw bbGCNew<t_mx2_SemantEx>(((BB_T("Type '")+f4.l_type->m_ToString())+BB_T("' is not a valid interface type")));
          }
          if(((this->m_cdecl->m_kind==BB_T("interface"))&&(f4.l_ifaceType->m_cdecl->m_kind==BB_T("protocol")))){
            throw bbGCNew<t_mx2_SemantEx>(BB_T("Interfaces cannot extends protocols"));
          }
          if((f4.l_ifaceType->m_state==g_mx2_SNODE_0SEMANTING)){
            throw bbGCNew<t_mx2_SemantEx>(BB_T("Cyclic inheritance error"),((t_mx2_PNode*)(this->m_cdecl)));
          }
          if(f1.l_ifaces->m_Contains(f4.l_ifaceType)){
            throw bbGCNew<t_mx2_SemantEx>(((BB_T("Duplicate interface '")+f4.l_ifaceType->m_ToString())+BB_T("'")));
          }
          f1.l_ifaces->m_Push(f4.l_ifaceType);
          f1.l_allifaces->m_Push(f4.l_ifaceType);
          {
            bbInt l_2=bbInt(0);
            bbInt l_3=f4.l_ifaceType->m_allIfaces->length();
            for(;(l_2<l_3);l_2+=1){
              struct f6_t : public bbGCFrame{
                t_mx2_ClassType* l_iface{};
                void gcMark(){
                  bbGCMarkPtr(l_iface);
                }
              }f6{};
              f6.l_iface=f4.l_ifaceType->m_allIfaces->at(l_2);
              if(!f1.l_allifaces->m_Contains(f6.l_iface)){
                f1.l_allifaces->m_Push(f6.l_iface);
              }
            }
          }
        }catch(t_mx2_SemantEx* ex){
          struct f4_t : public bbGCFrame{
            t_mx2_SemantEx* l_ex{};
            void gcMark(){
              bbGCMarkPtr(l_ex);
            }
          }f4{};
          f4.l_ex=ex;
        }
      }
    }
    this->m_ifaceTypes=f1.l_ifaces->m_ToArray();
    this->m_allIfaces=f1.l_allifaces->m_ToArray();
  }
  f0.l_builder=g_mx2_Builder_instance;
  if((this->m_scope->m_IsGeneric()||this->m_cdecl->m_IsExtern())){
    f0.l_builder->m_semantMembers->m_AddLast(this);
  }else{
    if(this->m_IsGenInstance()){
      struct f2_t : public bbGCFrame{
        t_mx2_Module* l_module{};
        void gcMark(){
          bbGCMarkPtr(l_module);
        }
      }f2{};
      this->m_SemantMembers();
      f2.l_module=f0.l_builder->m_semantingModule;
      f2.l_module->m_genInstances->m_Push(((t_mx2_SNode*)(this)));
    }else{
      f0.l_builder->m_semantMembers->m_AddLast(this);
    }
    this->m_transFile->m_classes->m_Push(this);
  }
  return ((t_mx2_SNode*)(this));
}

bbString t_mx2_ClassType::m_Name(){
  return this->m_scope->m_Name();
}

bbBool t_mx2_ClassType::m_IsVoid(){
  return (this->m_isvoid||(bbBool(this->m_superType)&&this->m_superType->m_IsVoid()));
}

bbBool t_mx2_ClassType::m_IsVirtual(){
  return (this->m_cdecl->m_IsVirtual()||(bbBool(this->m_superType)&&this->m_superType->m_IsVirtual()));
}

bbBool t_mx2_ClassType::m_IsStruct(){
  return (this->m_cdecl->m_kind==BB_T("struct"));
}

bbBool t_mx2_ClassType::m_IsInterface(){
  return (this->m_cdecl->m_kind==BB_T("interface"));
}

bbBool t_mx2_ClassType::m_IsGenInstance(){
  struct f0_t : public bbGCFrame{
    t_mx2_ClassType* l_ctype{};
    void gcMark(){
      bbGCMarkPtr(l_ctype);
    }
  }f0{};
  if(bbBool(this->m_instanceOf)){
    return true;
  }
  f0.l_ctype=this->m_scope->m_outer->m_FindClass();
  if(bbBool(f0.l_ctype)){
    return f0.l_ctype->m_IsGenInstance();
  }
  return false;
}

bbBool t_mx2_ClassType::m_IsClass(){
  return (this->m_cdecl->m_kind==BB_T("class"));
}

bbBool t_mx2_ClassType::m_IsAbstract(){
  return (this->m_cdecl->m_IsAbstract()||bbBool(this->m_abstractMethods));
}

t_mx2_Type* t_mx2_ClassType::m_InferType(t_mx2_Type* l_type,bbArray<bbGCVar<t_mx2_Type>>* l_infered){
  struct f0_t : public bbGCFrame{
    t_mx2_ClassType* l_ctype{};
    bbArray<bbGCVar<t_mx2_Type>>* l_types{};
    void gcMark(){
      bbGCMarkPtr(l_ctype);
      bbGCMarkPtr(l_types);
    }
  }f0{};
  if(!this->m_IsGeneric()){
    return t_mx2_Type::m_InferType(l_type,l_infered);
  }
  f0.l_ctype=g_mx2_TCast_1Tt_mx2_ClassType_2(l_type);
  if(!bbBool(f0.l_ctype)){
    return ((t_mx2_Type*)0);
  }
  if((this->m_types->length()!=f0.l_ctype->m_types->length())){
    return ((t_mx2_Type*)0);
  }
  f0.l_types=this->m_types->slice(bbInt(0));
  {
    bbInt l_i=bbInt(0);
    for(;(l_i<f0.l_types->length());l_i+=1){
      f0.l_types->at(l_i)=f0.l_types->at(l_i)->m_InferType(f0.l_ctype->m_types->at(l_i),l_infered);
      if(!bbBool(f0.l_types->at(l_i))){
        return ((t_mx2_Type*)0);
      }
    }
  }
  return this->m_GenInstance(f0.l_types);
}

t_mx2_Value* t_mx2_ClassType::m_Index(bbArray<bbGCVar<t_mx2_Value>>* l_args,t_mx2_Value* l_value){
  return ((t_mx2_Value*)(bbGCNew<t_mx2_OpIndexValue>(this,l_args,l_value)));
}

t_mx2_Type* t_mx2_ClassType::m_GenInstance(bbArray<bbGCVar<t_mx2_Type>>* l_types){
  struct f0_t : public bbGCFrame{
    t_mx2_ClassType* l_inst{};
    void gcMark(){
      bbGCMarkPtr(l_inst);
    }
  }f0{};
  if(bbBool(this->m_instanceOf)){
    return this->m_instanceOf->m_GenInstance(l_types);
  }
  if(!this->m_IsGeneric()){
    throw bbGCNew<t_mx2_SemantEx>(((BB_T("Class '")+this->m_ToString())+BB_T("' is not generic")));
  }
  if((l_types->length()!=this->m_types->length())){
    throw bbGCNew<t_mx2_SemantEx>(BB_T("Wrong number of generic type parameters"));
  }
  if(!bbBool(this->m_instances)){
    this->m_instances=bbGCNew<t_std_collections_Stack_1Tt_mx2_ClassType_2>();
  }
  {
    struct f1_t : public bbGCFrame{
      t_std_collections_Stack_1Tt_mx2_ClassType_2_Iterator l_0{};
      void gcMark(){
        bbGCMark(l_0);
      }
    }f1{};
    f1.l_0=this->m_instances->m_All();
    for(;!f1.l_0.m_AtEnd();f1.l_0.m_Bump()){
      struct f2_t : public bbGCFrame{
        t_mx2_ClassType* l_inst{};
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
  f0.l_inst=bbGCNew<t_mx2_ClassType>(this->m_cdecl,this->m_scope->m_outer,l_types,this);
  this->m_instances->m_Push(f0.l_inst);
  f0.l_inst->m_Semant();
  return ((t_mx2_Type*)(f0.l_inst));
}

t_mx2_Type* t_mx2_ClassType::m_FindType(bbString l_ident){
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
  if(bbBool(this->m_superType)){
    return this->m_superType->m_FindType(l_ident);
  }
  return ((t_mx2_Type*)0);
}

t_mx2_SNode* t_mx2_ClassType::m_FindSuperNode(bbString l_ident){
  struct f0_t : public bbGCFrame{
    t_mx2_ClassType* l_ctype{};
    void gcMark(){
      bbGCMarkPtr(l_ctype);
    }
  }f0{};
  f0.l_ctype=this->m_superType;
  while(bbBool(f0.l_ctype)){
    struct f1_t : public bbGCFrame{
      t_mx2_SNode* l_node{};
      void gcMark(){
        bbGCMarkPtr(l_node);
      }
    }f1{};
    f1.l_node=f0.l_ctype->m_scope->m_GetNode(l_ident);
    if(bbBool(f1.l_node)){
      return f1.l_node;
    }
    f0.l_ctype=f0.l_ctype->m_superType;
  }
  return ((t_mx2_SNode*)0);
}

t_mx2_FuncValue* t_mx2_ClassType::m_FindSuperFunc(bbString l_ident,bbArray<bbGCVar<t_mx2_Type>>* l_argTypes){
  struct f0_t : public bbGCFrame{
    t_mx2_FuncList* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=bb_object_cast<t_mx2_FuncList*>(this->m_FindSuperNode(l_ident));
  if(bbBool(f0.l_node)){
    return f0.l_node->m_FindFunc(l_argTypes);
  }
  return ((t_mx2_FuncValue*)0);
}

t_mx2_SNode* t_mx2_ClassType::m_FindNode(bbString l_ident){
  struct f0_t : public bbGCFrame{
    t_mx2_SNode* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  if(this->m_membersSemanting){
    g_mx2_SemantError(((((BB_T("ClassType.FindNode() class='")+this->m_ToString())+BB_T("', ident='"))+l_ident)+BB_T("'")));
  }
  f0.l_node=this->m_scope->m_GetNode(l_ident);
  if((bbBool(f0.l_node)||(l_ident==BB_T("new")))){
    return f0.l_node;
  }
  if(bbBool(this->m_superType)){
    return this->m_superType->m_FindNode(l_ident);
  }
  return ((t_mx2_SNode*)0);
}

bbBool t_mx2_ClassType::m_ExtendsType(t_mx2_Type* l_type){
  bbInt l_t=this->m_DistanceToType(l_type);
  return ((l_t>=bbInt(0))&&(l_t<g_mx2_Type_MAX_0DISTANCE));
}

bbInt t_mx2_ClassType::m_DistanceToType(t_mx2_Type* l_type){
  struct f0_t : public bbGCFrame{
    t_mx2_ClassType* l_ctype{};
    t_mx2_ClassType* l_stype{};
    void gcMark(){
      bbGCMarkPtr(l_ctype);
      bbGCMarkPtr(l_stype);
    }
  }f0{};
  if(l_type->m__eq(((t_mx2_Type*)(this)))){
    return bbInt(0);
  }
  if(l_type->m__eq(((t_mx2_Type*)(g_mx2_Type_BoolType)))){
    return g_mx2_Type_MAX_0DISTANCE;
  }
  f0.l_ctype=g_mx2_TCast_1Tt_mx2_ClassType_2(l_type);
  if(!bbBool(f0.l_ctype)){
    return -1;
  }
  bbInt l_dist=bbInt(0);
  f0.l_stype=this;
  while(bbBool(f0.l_stype)){
    if(f0.l_stype->m_Equals(((t_mx2_Type*)(f0.l_ctype)))){
      return l_dist;
    }
    if(((f0.l_ctype->m_cdecl->m_kind==BB_T("interface"))||(f0.l_ctype->m_cdecl->m_kind==BB_T("protocol")))){
      {
        bbInt l_0=bbInt(0);
        bbInt l_1=f0.l_stype->m_allIfaces->length();
        for(;(l_0<l_1);l_0+=1){
          struct f4_t : public bbGCFrame{
            t_mx2_ClassType* l_iface{};
            void gcMark(){
              bbGCMarkPtr(l_iface);
            }
          }f4{};
          f4.l_iface=f0.l_stype->m_allIfaces->at(l_0);
          if(f4.l_iface->m_Equals(((t_mx2_Type*)(f0.l_ctype)))){
            return l_dist;
          }
        }
      }
    }
    f0.l_stype=f0.l_stype->m_superType;
    l_dist+=1;
  }
  return -1;
}

bbBool t_mx2_ClassType::m_CanCastToType(t_mx2_Type* l_type){
  struct f0_t : public bbGCFrame{
    t_mx2_ClassType* l_ctype{};
    void gcMark(){
      bbGCMarkPtr(l_ctype);
    }
  }f0{};
  f0.l_ctype=g_mx2_TCast_1Tt_mx2_ClassType_2(l_type);
  if(!bbBool(f0.l_ctype)){
    return false;
  }
  if(this->m_cdecl->m_kind==BB_T("class")){
    if((f0.l_ctype->m_cdecl->m_kind==BB_T("class"))){
      return f0.l_ctype->m_ExtendsType(((t_mx2_Type*)(this)));
    }
    if((f0.l_ctype->m_cdecl->m_kind==BB_T("interface"))){
      return true;
    }
  }else if(this->m_cdecl->m_kind==BB_T("interface")){
    if((f0.l_ctype->m_cdecl->m_kind==BB_T("class"))){
      return true;
    }
    if((f0.l_ctype->m_cdecl->m_kind==BB_T("interface"))){
      return true;
    }
  }
  return false;
}

void t_mx2_ClassDecl::gcMark(){
  t_mx2_Decl::gcMark();
  bbGCMark(m_genArgs);
  bbGCMark(m_superType);
  bbGCMark(m_ifaceTypes);
}

bbString t_mx2_ClassDecl::m_ToString(){
  bbString l_str=t_mx2_Decl::m_ToString();
  if(bbBool(this->m_genArgs)){
    l_str+=((BB_T("<")+BB_T(",").join(this->m_genArgs))+BB_T(">"));
  }
  if(bbBool(this->m_superType)){
    l_str+=(BB_T(" extends ")+this->m_superType->m_ToString());
  }
  if(bbBool(this->m_ifaceTypes)){
    l_str+=(BB_T(" implements ")+g_mx2_Join_1Tt_mx2_TypeExpr_2(this->m_ifaceTypes,BB_T(",")));
  }
  return l_str;
}

t_mx2_SNode* t_mx2_ClassDecl::m_ToNode(t_mx2_Scope* l_scope){
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
  return ((t_mx2_SNode*)(bbGCNew<t_mx2_ClassType>(this,l_scope,f0.l_types,((t_mx2_ClassType*)0))));
}

void t_mx2_OpIndexValue::gcMark(){
  t_mx2_Value::gcMark();
  bbGCMark(m_ctype);
  bbGCMark(m_args);
  bbGCMark(m_instance);
  bbGCMark(m_getters);
  bbGCMark(m_setters);
  bbGCMark(m_invokeGet);
}

t_mx2_OpIndexValue::t_mx2_OpIndexValue(t_mx2_ClassType* l_ctype,bbArray<bbGCVar<t_mx2_Value>>* l_args,t_mx2_Value* l_instance){
  this->m_type=((t_mx2_Type*)(g_mx2_Type_VoidType));
  this->m_args=l_args;
  this->m_instance=l_instance;
  this->m_getters=bb_object_cast<t_mx2_FuncList*>(l_ctype->m_FindNode(BB_T("[]")));
  this->m_setters=bb_object_cast<t_mx2_FuncList*>(l_ctype->m_FindNode(BB_T("[]=")));
  if((!bbBool(this->m_getters)&&!bbBool(this->m_setters))){
    throw bbGCNew<t_mx2_SemantEx>(((BB_T("Type '")+this->m_ToString())+BB_T("' cannot be indexed")));
  }
  if(bbBool(this->m_getters)){
    struct f1_t : public bbGCFrame{
      t_mx2_Value* t0{};
      void gcMark(){
        bbGCMarkPtr(t0);
      }
    }f1{};
    this->m_invokeGet=(f1.t0=this->m_getters->m_ToValue(l_instance))->m_Invoke(l_args);
    this->m_type=this->m_invokeGet->m_type;
  }
  if(bbBool(this->m_setters)){
    this->m_flags|=g_mx2_VALUE_0ASSIGNABLE;
  }
}

bbString t_mx2_OpIndexValue::m_ToString(){
  return (((this->m_instance->m_ToString()+BB_T("["))+g_mx2_Join_1Tt_mx2_Value_2(this->m_args,BB_T(",")))+BB_T("]"));
}

t_mx2_Value* t_mx2_OpIndexValue::m_ToRValue(){
  if(!bbBool(this->m_invokeGet)){
    throw bbGCNew<t_mx2_SemantEx>(BB_T("Value cannot be indexed"));
  }
  return this->m_invokeGet;
}

bbBool t_mx2_OpIndexValue::m_HasSideEffects(){
  g_mx2_SemantError(BB_T("OpIndexValue.HasSideEffects()"));
  return false;
}

t_mx2_Stmt* t_mx2_OpIndexValue::m_Assign(t_mx2_PNode* l_pnode,bbString l_op,t_mx2_Value* l_rvalue,t_mx2_Block* l_block){
  struct f0_t : public bbGCFrame{
    bbArray<bbGCVar<t_mx2_Value>>* l_args{};
    bbArray<bbGCVar<t_mx2_Value>>* l_args2{};
    t_mx2_Value* l_inst{};
    t_mx2_Value* l_rvalue{};
    t_mx2_Value* t0{};
    t_mx2_Value* t1{};
    f0_t(t_mx2_Value* l_rvalue):l_rvalue(l_rvalue){
    }
    void gcMark(){
      bbGCMarkPtr(l_args);
      bbGCMarkPtr(l_args2);
      bbGCMarkPtr(l_inst);
      bbGCMarkPtr(l_rvalue);
      bbGCMarkPtr(t0);
      bbGCMarkPtr(t1);
    }
  }f0{l_rvalue};
  if(!bbBool(this->m_setters)){
    throw bbGCNew<t_mx2_SemantEx>(BB_T("Value cannot be index assigned"));
  }
  f0.l_args=this->m_args;
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
    if(!bbBool(this->m_getters)){
      throw bbGCNew<t_mx2_SemantEx>(BB_T("Value cannot be indexed"));
    }
    f0.l_inst=f0.l_inst->m_RemoveSideEffects(l_block);
    f0.l_args=f0.l_args->slice(bbInt(0));
    {
      bbInt l_i=bbInt(0);
      for(;(l_i<f0.l_args->length());l_i+=1){
        if(bbBool(f0.l_args->at(l_i))){
          f0.l_args->at(l_i)=f0.l_args->at(l_i)->m_RemoveSideEffects(l_block);
        }
      }
    }
    f1.l_value=(f1.t0=this->m_getters->m_ToValue(f0.l_inst))->m_Invoke(f0.l_args);
    bbString l_op2=l_op.slice(bbInt(0),-1);
    f1.l_node=f1.l_value->m_FindValue(l_op2);
    if(bbBool(f1.l_node)){
      struct f2_t : public bbGCFrame{
        bbArray<bbGCVar<t_mx2_Value>>* l_args{};
        void gcMark(){
          bbGCMarkPtr(l_args);
        }
      }f2{};
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
  f0.l_args2=bbArray<bbGCVar<t_mx2_Value>>::create((this->m_args->length()+1));
  {
    bbInt l_i=bbInt(0);
    for(;(l_i<f0.l_args->length());l_i+=1){
      f0.l_args2->at(l_i)=f0.l_args->at(l_i);
    }
  }
  f0.l_args2->at(f0.l_args->length())=f0.l_rvalue;
  return ((t_mx2_Stmt*)(bbGCNew<t_mx2_EvalStmt>(l_pnode,f0.t1=(f0.t0=this->m_setters->m_ToValue(f0.l_inst))->m_Invoke(f0.l_args2))));
}

void t_mx2_ClassScope::gcMark(){
  t_mx2_Scope::gcMark();
  bbGCMark(m_ctype);
  bbGCMark(m_itype);
}

t_mx2_ClassScope::t_mx2_ClassScope(t_mx2_ClassType* l_ctype,t_mx2_Scope* l_outer):t_mx2_Scope(l_outer){
  this->m_ctype=l_ctype;
}

bbString t_mx2_ClassScope::m_TypeId(){
  bbString l_args=bbString{};
  {
    bbInt l_0=bbInt(0);
    bbInt l_1=this->m_ctype->m_types->length();
    for(;(l_0<l_1);l_0+=1){
      struct f2_t : public bbGCFrame{
        t_mx2_Type* l_arg{};
        void gcMark(){
          bbGCMarkPtr(l_arg);
        }
      }f2{};
      f2.l_arg=this->m_ctype->m_types->at(l_0);
      l_args+=f2.l_arg->m_TypeId();
    }
  }
  if(bbBool(l_args)){
    l_args=((BB_T("_1")+l_args)+BB_T("E"));
  }
  return (((((BB_T("T")+this->m_outer->m_TypeId())+BB_T("_"))+this->m_ctype->m_cdecl->m_ident.replace(BB_T("_"),BB_T("_0")))+l_args)+BB_T("_2"));
}

bbString t_mx2_ClassScope::m_Name(){
  bbString l_args=bbString{};
  {
    bbInt l_0=bbInt(0);
    bbInt l_1=this->m_ctype->m_types->length();
    for(;(l_0<l_1);l_0+=1){
      struct f2_t : public bbGCFrame{
        t_mx2_Type* l_arg{};
        void gcMark(){
          bbGCMarkPtr(l_arg);
        }
      }f2{};
      f2.l_arg=this->m_ctype->m_types->at(l_0);
      l_args+=(BB_T(",")+f2.l_arg->m_Name());
    }
  }
  if(bbBool(l_args)){
    l_args=((BB_T("<")+l_args.slice(1))+BB_T(">"));
  }
  if(this->m_ctype->m_cdecl->m_ident.startsWith(BB_T("@"))){
    return (this->m_ctype->m_cdecl->m_ident.slice(1).capitalize()+l_args);
  }
  return (((this->m_outer->m_Name()+BB_T("."))+this->m_ctype->m_cdecl->m_ident)+l_args);
}

bbBool t_mx2_ClassScope::m_IsGeneric(){
  if(this->m_ctype->m_IsGeneric()){
    return true;
  }
  return t_mx2_Scope::m_IsGeneric();
}

t_mx2_Type* t_mx2_ClassScope::m_FindType(bbString l_ident){
  struct f0_t : public bbGCFrame{
    t_mx2_Type* l_type{};
    void gcMark(){
      bbGCMarkPtr(l_type);
    }
  }f0{};
  if((l_ident==this->m_ctype->m_cdecl->m_ident)){
    if(!bbBool(this->m_itype)){
      if((bbBool(this->m_ctype->m_types)&&!bbBool(this->m_ctype->m_instanceOf))){
        this->m_itype=this->m_ctype->m_GenInstance(this->m_ctype->m_types);
      }else{
        this->m_itype=((t_mx2_Type*)(this->m_ctype));
      }
    }
    return this->m_itype;
  }
  {
    bbInt l_i=bbInt(0);
    for(;(l_i<this->m_ctype->m_cdecl->m_genArgs->length());l_i+=1){
      if((l_ident==this->m_ctype->m_cdecl->m_genArgs->at(l_i))){
        return this->m_ctype->m_types->at(l_i);
      }
    }
  }
  f0.l_type=this->m_ctype->m_FindType(l_ident);
  if(bbBool(f0.l_type)){
    return f0.l_type;
  }
  if(bbBool(this->m_outer)){
    return this->m_outer->m_FindType(l_ident);
  }
  return ((t_mx2_Type*)0);
}

t_mx2_SNode* t_mx2_ClassScope::m_FindNode(bbString l_ident){
  struct f0_t : public bbGCFrame{
    t_mx2_SNode* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m_ctype->m_FindNode(l_ident);
  if(bbBool(f0.l_node)){
    return f0.l_node;
  }
  if(bbBool(this->m_outer)){
    return this->m_outer->m_FindNode(l_ident);
  }
  return ((t_mx2_SNode*)0);
}

t_mx2_ClassType* t_mx2_ClassScope::m_FindClass(){
  return this->m_ctype;
}

void mx2_mx2cc_class_init(){
  static bool done;
  if(done) return;
  done=true;
}

bbInit mx2_mx2cc_class_init_v("mx2cc_class",&mx2_mx2cc_class_init);
