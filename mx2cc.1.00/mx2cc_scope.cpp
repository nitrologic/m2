
#include "mx2cc_scope.h"

// ***** External *****

#include "mx2cc_builder.h"
#include "mx2cc_decl.h"
#include "mx2cc_errors.h"
#include "mx2cc_func.h"
#include "mx2cc_module.h"
#include "mx2cc_namespace.h"
#include "mx2cc_node.h"
#include "mx2cc_property.h"
#include "mx2cc_std_collections_2map.h"
#include "mx2cc_std_collections_2stack.h"
#include "mx2cc_stmt.h"
#include "mx2cc_stmtexpr.h"
#include "mx2cc_type.h"
#include "mx2cc_var.h"

// ***** Internal *****

void t_mx2_Scope::init(){
  m_inner=bbGCNew<t_std_collections_Stack_1Tt_mx2_Scope_2>();
  m_nodes=bbGCNew<t_std_collections_Map_1sTt_mx2_SNode_2>();
  m_transMembers=bbGCNew<t_std_collections_Stack_1Tt_mx2_SNode_2>();
}

void t_mx2_Scope::gcMark(){
  bbGCMark(m_outer);
  bbGCMark(m_inner);
  bbGCMark(m_nodes);
  bbGCMark(m_transMembers);
}

t_mx2_Scope::t_mx2_Scope(t_mx2_Scope* l_outer){
  init();
  this->m_outer=l_outer;
  if(bbBool(l_outer)){
    l_outer->m_inner->m_Push(this);
  }
}

bbString t_mx2_Scope::m_TypeId(){
  if(bbBool(this->m_outer)){
    return this->m_outer->m_Name();
  }
  return bbString{};
}

bbString t_mx2_Scope::m_ToString(){
  if(bbBool(this->m_outer)){
    return this->m_outer->m_ToString();
  }
  return bbString{};
}

bbString t_mx2_Scope::m_Name(){
  if(bbBool(this->m_outer)){
    return this->m_outer->m_Name();
  }
  return bbString{};
}

bbBool t_mx2_Scope::m_IsGeneric(){
  if(bbBool(this->m_outer)){
    return this->m_outer->m_IsGeneric();
  }
  return false;
}

bbBool t_mx2_Scope::m_Insert(bbString l_ident,t_mx2_SNode* l_node){
  try{
    struct f1_t : public bbGCFrame{
      t_mx2_FuncValue* l_func{};
      void gcMark(){
        bbGCMarkPtr(l_func);
      }
    }f1{};
    f1.l_func=bb_object_cast<t_mx2_FuncValue*>(l_node);
    if(bbBool(f1.l_func)){
      struct f2_t : public bbGCFrame{
        t_mx2_FuncList* l_flist{};
        void gcMark(){
          bbGCMarkPtr(l_flist);
        }
      }f2{};
      f2.l_flist=bb_object_cast<t_mx2_FuncList*>(this->m_nodes->m__idx(l_ident));
      if(bbBool(bb_object_cast<t_mx2_PropertyList*>(f2.l_flist))){
        f2.l_flist=((t_mx2_FuncList*)0);
      }
      if(!bbBool(f2.l_flist)){
        if(this->m_nodes->m_Contains(l_ident)){
          throw bbGCNew<t_mx2_SemantEx>(((BB_T("Duplicate identifier '")+l_ident)+BB_T("'")),l_node->m_pnode);
        }
        f2.l_flist=bbGCNew<t_mx2_FuncList>(l_ident,this);
        this->m_nodes->m__idxeq(l_ident,((t_mx2_SNode*)(f2.l_flist)));
      }
      f2.l_flist->m_PushFunc(f1.l_func);
      return true;
    }
    if(this->m_nodes->m_Contains(l_ident)){
      throw bbGCNew<t_mx2_SemantEx>(((BB_T("Duplicate identifier '")+l_ident)+BB_T("'")),l_node->m_pnode);
    }
    this->m_nodes->m__idxeq(l_ident,l_node);
    return true;
  }catch(t_mx2_SemantEx* ex){
    struct f1_t : public bbGCFrame{
      t_mx2_SemantEx* l_ex{};
      void gcMark(){
        bbGCMarkPtr(l_ex);
      }
    }f1{};
    f1.l_ex=ex;
  }
  return false;
}

t_mx2_Type* t_mx2_Scope::m_GetType(bbString l_ident){
  struct f0_t : public bbGCFrame{
    t_mx2_SNode* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m_nodes->m__idx(l_ident);
  if(!bbBool(bb_object_cast<t_mx2_Type*>(f0.l_node))){
    return ((t_mx2_Type*)0);
  }
  f0.l_node=f0.l_node->m_Semant();
  if(bbBool(f0.l_node)){
    return f0.l_node->m_ToType();
  }
  return ((t_mx2_Type*)0);
}

t_mx2_SNode* t_mx2_Scope::m_GetNode(bbString l_ident){
  struct f0_t : public bbGCFrame{
    t_mx2_SNode* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m_nodes->m__idx(l_ident);
  if(bbBool(f0.l_node)){
    return f0.l_node->m_Semant();
  }
  return ((t_mx2_SNode*)0);
}

t_mx2_Value* t_mx2_Scope::m_FindValue(bbString l_ident){
  struct f0_t : public bbGCFrame{
    t_mx2_SNode* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m_FindNode(l_ident);
  if(bbBool(f0.l_node)){
    return f0.l_node->m_ToValue(((t_mx2_Value*)0));
  }
  return ((t_mx2_Value*)0);
}

t_mx2_Type* t_mx2_Scope::m_FindType(bbString l_ident){
  struct f0_t : public bbGCFrame{
    t_mx2_Type* l_type{};
    void gcMark(){
      bbGCMarkPtr(l_type);
    }
  }f0{};
  f0.l_type=this->m_GetType(l_ident);
  if(bbBool(f0.l_type)){
    return f0.l_type;
  }
  if(bbBool(this->m_outer)){
    return this->m_outer->m_FindType(l_ident);
  }
  return ((t_mx2_Type*)0);
}

t_mx2_SNode* t_mx2_Scope::m_FindNode(bbString l_ident){
  struct f0_t : public bbGCFrame{
    t_mx2_SNode* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m_GetNode(l_ident);
  if(bbBool(f0.l_node)){
    return f0.l_node;
  }
  if(bbBool(this->m_outer)){
    return this->m_outer->m_FindNode(l_ident);
  }
  return ((t_mx2_SNode*)0);
}

t_mx2_FileScope* t_mx2_Scope::m_FindFile(){
  if(bbBool(this->m_outer)){
    return this->m_outer->m_FindFile();
  }
  g_mx2_SemantError(BB_T("Scope.FindFile()"));
  return ((t_mx2_FileScope*)0);
}

t_mx2_ClassType* t_mx2_Scope::m_FindClass(){
  if(bbBool(this->m_outer)){
    return this->m_outer->m_FindClass();
  }
  return ((t_mx2_ClassType*)0);
}

void t_mx2_FileScope::init(){
  m_toSemant=bbGCNew<t_std_collections_Stack_1Tt_mx2_SNode_2>();
}

void t_mx2_FileScope::gcMark(){
  t_mx2_Scope::gcMark();
  bbGCMark(m_fdecl);
  bbGCMark(m_nmspace);
  bbGCMark(m_usings);
  bbGCMark(m_toSemant);
}

t_mx2_FileScope::t_mx2_FileScope(t_mx2_FileDecl* l_fdecl):t_mx2_Scope(((t_mx2_Scope*)0)){
  init();
  struct f0_t : public bbGCFrame{
    t_mx2_Builder* l_builder{};
    t_mx2_Module* l_module{};
    void gcMark(){
      bbGCMarkPtr(l_builder);
      bbGCMarkPtr(l_module);
    }
  }f0{};
  f0.l_module=l_fdecl->m_module;
  this->m_fdecl=l_fdecl;
  this->m_usings=f0.l_module->m_usings;
  f0.l_builder=g_mx2_Builder_instance;
  this->m_nmspace=f0.l_builder->m_GetNamespace(l_fdecl->m_nmspace);
  this->m_nmspace->m_inner->m_Push(((t_mx2_Scope*)(this)));
  this->m_outer=((t_mx2_Scope*)(this->m_nmspace));
  {
    bbInt l_0=bbInt(0);
    bbInt l_1=l_fdecl->m_members->length();
    for(;(l_0<l_1);l_0+=1){
      struct f2_t : public bbGCFrame{
        t_mx2_Decl* l_member{};
        t_mx2_SNode* l_node{};
        void gcMark(){
          bbGCMarkPtr(l_member);
          bbGCMarkPtr(l_node);
        }
      }f2{};
      f2.l_member=l_fdecl->m_members->at(l_0);
      f2.l_node=f2.l_member->m_ToNode(((t_mx2_Scope*)(this)));
      if(f2.l_member->m_IsPublic()){
        if(!this->m_nmspace->m_Insert(f2.l_member->m_ident,f2.l_node)){
          continue;
        }
      }else{
        if(!this->m_Insert(f2.l_member->m_ident,f2.l_node)){
          continue;
        }
      }
      this->m_toSemant->m_Push(f2.l_node);
    }
  }
}

bbBool t_mx2_FileScope::m_UsingNamespace(t_mx2_NamespaceScope* l_nmspace){
  if(this->m_usings->m_Contains(l_nmspace)){
    return true;
  }
  this->m_usings->m_Push(l_nmspace);
  return false;
}

void t_mx2_FileScope::m_UsingInner(t_mx2_NamespaceScope* l_nmspace){
  {
    struct f1_t : public bbGCFrame{
      t_std_collections_Stack_1Tt_mx2_Scope_2_Iterator l_0{};
      void gcMark(){
        bbGCMark(l_0);
      }
    }f1{};
    f1.l_0=l_nmspace->m_inner->m_All();
    for(;!f1.l_0.m_AtEnd();f1.l_0.m_Bump()){
      struct f2_t : public bbGCFrame{
        t_mx2_NamespaceScope* l_nmspace{};
        t_mx2_Scope* l_scope{};
        void gcMark(){
          bbGCMarkPtr(l_nmspace);
          bbGCMarkPtr(l_scope);
        }
      }f2{};
      f2.l_scope=f1.l_0.m_Current();
      f2.l_nmspace=bb_object_cast<t_mx2_NamespaceScope*>(f2.l_scope);
      if(bbBool(f2.l_nmspace)){
        this->m_UsingNamespace(f2.l_nmspace);
      }
    }
  }
}

void t_mx2_FileScope::m_UsingAll(t_mx2_NamespaceScope* l_nmspace){
  if(this->m_UsingNamespace(l_nmspace)){
    return;
  }
  {
    struct f1_t : public bbGCFrame{
      t_std_collections_Stack_1Tt_mx2_Scope_2_Iterator l_0{};
      void gcMark(){
        bbGCMark(l_0);
      }
    }f1{};
    f1.l_0=l_nmspace->m_inner->m_All();
    for(;!f1.l_0.m_AtEnd();f1.l_0.m_Bump()){
      struct f2_t : public bbGCFrame{
        t_mx2_NamespaceScope* l_nmspace{};
        t_mx2_Scope* l_scope{};
        void gcMark(){
          bbGCMarkPtr(l_nmspace);
          bbGCMarkPtr(l_scope);
        }
      }f2{};
      f2.l_scope=f1.l_0.m_Current();
      f2.l_nmspace=bb_object_cast<t_mx2_NamespaceScope*>(f2.l_scope);
      if(bbBool(f2.l_nmspace)){
        this->m_UsingAll(f2.l_nmspace);
      }
    }
  }
}

void t_mx2_FileScope::m_Semant(){
  struct f0_t : public bbGCFrame{
    t_mx2_Builder* l_builder{};
    void gcMark(){
      bbGCMarkPtr(l_builder);
    }
  }f0{};
  f0.l_builder=g_mx2_Builder_instance;
  if((this->m_nmspace!=f0.l_builder->m_monkeyNamespace)){
    this->m_UsingAll(f0.l_builder->m_monkeyNamespace);
  }
  {
    bbInt l_0=bbInt(0);
    bbInt l_1=this->m_fdecl->m_usings->length();
    for(;(l_0<l_1);l_0+=1){
      struct f2_t : public bbGCFrame{
        t_mx2_NamespaceScope* l_nmspace{};
        void gcMark(){
          bbGCMarkPtr(l_nmspace);
        }
      }f2{};
      bbString l_use=this->m_fdecl->m_usings->at(l_0);
      if((l_use==BB_T("*"))){
        this->m_UsingAll(f0.l_builder->m_rootNamespace);
        continue;
      }
      if(l_use.endsWith(BB_T(".."))){
        struct f3_t : public bbGCFrame{
          t_mx2_NamespaceScope* l_nmspace{};
          void gcMark(){
            bbGCMarkPtr(l_nmspace);
          }
        }f3{};
        f3.l_nmspace=f0.l_builder->m_GetNamespace(l_use.slice(bbInt(0),-2));
        this->m_UsingAll(f3.l_nmspace);
        continue;
      }
      if(l_use.endsWith(BB_T(".*"))){
        struct f3_t : public bbGCFrame{
          t_mx2_NamespaceScope* l_nmspace{};
          void gcMark(){
            bbGCMarkPtr(l_nmspace);
          }
        }f3{};
        f3.l_nmspace=f0.l_builder->m_GetNamespace(l_use.slice(bbInt(0),-2));
        this->m_UsingInner(f3.l_nmspace);
        continue;
      }
      f2.l_nmspace=f0.l_builder->m_GetNamespace(l_use);
      if(bbBool(f2.l_nmspace)){
        this->m_UsingNamespace(f2.l_nmspace);
      }
    }
  }
  {
    struct f1_t : public bbGCFrame{
      t_std_collections_Stack_1Tt_mx2_SNode_2_Iterator l_2{};
      void gcMark(){
        bbGCMark(l_2);
      }
    }f1{};
    f1.l_2=this->m_toSemant->m_All();
    for(;!f1.l_2.m_AtEnd();f1.l_2.m_Bump()){
      struct f2_t : public bbGCFrame{
        t_mx2_SNode* l_node{};
        void gcMark(){
          bbGCMarkPtr(l_node);
        }
      }f2{};
      f2.l_node=f1.l_2.m_Current();
      try{
        f2.l_node->m_Semant();
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

t_mx2_Type* t_mx2_FileScope::m_FindType(bbString l_ident){
  struct f0_t : public bbGCFrame{
    t_mx2_Type* l_type{};
    void gcMark(){
      bbGCMarkPtr(l_type);
    }
  }f0{};
  f0.l_type=this->m_GetType(l_ident);
  if(bbBool(f0.l_type)){
    return f0.l_type;
  }
  {
    struct f1_t : public bbGCFrame{
      t_std_collections_Stack_1Tt_mx2_NamespaceScope_2_Iterator l_0{};
      void gcMark(){
        bbGCMark(l_0);
      }
    }f1{};
    f1.l_0=this->m_usings->m_All();
    for(;!f1.l_0.m_AtEnd();f1.l_0.m_Bump()){
      struct f2_t : public bbGCFrame{
        t_mx2_NamespaceScope* l_scope{};
        t_mx2_Type* l_type2{};
        void gcMark(){
          bbGCMarkPtr(l_scope);
          bbGCMarkPtr(l_type2);
        }
      }f2{};
      f2.l_scope=f1.l_0.m_Current();
      f2.l_type2=f2.l_scope->m_GetType(l_ident);
      if(!bbBool(f2.l_type2)){
        continue;
      }
      if(bbBool(f0.l_type)){
        throw bbGCNew<t_mx2_SemantEx>(((BB_T("Duplicate identifier '")+l_ident)+BB_T("'")));
      }
      f0.l_type=f2.l_type2;
    }
  }
  if(bbBool(f0.l_type)){
    return f0.l_type;
  }
  if(bbBool(this->m_outer)){
    return this->m_outer->m_FindType(l_ident);
  }
  return ((t_mx2_Type*)0);
}

t_mx2_SNode* t_mx2_FileScope::m_FindNode(bbString l_ident){
  struct f0_t : public bbGCFrame{
    t_mx2_FuncList* l_flist{};
    t_mx2_SNode* l_node{};
    void gcMark(){
      bbGCMarkPtr(l_flist);
      bbGCMarkPtr(l_node);
    }
  }f0{};
  f0.l_node=this->m_GetNode(l_ident);
  if(bbBool(f0.l_node)){
    return f0.l_node;
  }
  {
    struct f1_t : public bbGCFrame{
      t_std_collections_Stack_1Tt_mx2_NamespaceScope_2_Iterator l_0{};
      void gcMark(){
        bbGCMark(l_0);
      }
    }f1{};
    f1.l_0=this->m_usings->m_All();
    for(;!f1.l_0.m_AtEnd();f1.l_0.m_Bump()){
      struct f2_t : public bbGCFrame{
        t_mx2_FuncList* l_flist2{};
        t_mx2_SNode* l_node2{};
        t_mx2_NamespaceScope* l_scope{};
        void gcMark(){
          bbGCMarkPtr(l_flist2);
          bbGCMarkPtr(l_node2);
          bbGCMarkPtr(l_scope);
        }
      }f2{};
      f2.l_scope=f1.l_0.m_Current();
      f2.l_node2=f2.l_scope->m_GetNode(l_ident);
      if(!bbBool(f2.l_node2)){
        continue;
      }
      if(!bbBool(f0.l_node)){
        f0.l_node=f2.l_node2;
        continue;
      }
      f2.l_flist2=bb_object_cast<t_mx2_FuncList*>(f2.l_node2);
      if(bbBool(f2.l_flist2)){
        if(!bbBool(f0.l_flist)){
          struct f4_t : public bbGCFrame{
            t_mx2_FuncList* l_flist2{};
            void gcMark(){
              bbGCMarkPtr(l_flist2);
            }
          }f4{};
          f4.l_flist2=bb_object_cast<t_mx2_FuncList*>(f0.l_node);
          if(bbBool(f4.l_flist2)){
            f0.l_flist=bbGCNew<t_mx2_FuncList>(f4.l_flist2->m_ident,((t_mx2_Scope*)(this)));
          }
        }
        if(bbBool(f0.l_flist)){
          {
            struct f5_t : public bbGCFrame{
              t_std_collections_Stack_1Tt_mx2_FuncValue_2_Iterator l_1{};
              void gcMark(){
                bbGCMark(l_1);
              }
            }f5{};
            f5.l_1=f2.l_flist2->m_funcs->m_All();
            for(;!f5.l_1.m_AtEnd();f5.l_1.m_Bump()){
              struct f6_t : public bbGCFrame{
                t_mx2_FuncValue* l_func{};
                void gcMark(){
                  bbGCMarkPtr(l_func);
                }
              }f6{};
              f6.l_func=f5.l_1.m_Current();
              if(bbBool(f0.l_flist->m_FindFunc(f6.l_func->m_ftype->m_argTypes))){
                throw bbGCNew<t_mx2_SemantEx>(((BB_T("Duplicate identifier '")+l_ident)+BB_T("'")));
              }
              f0.l_flist->m_funcs->m_Push(f6.l_func);
            }
          }
          continue;
        }
      }
      throw bbGCNew<t_mx2_SemantEx>(((BB_T("Duplicate identifier '")+l_ident)+BB_T("'")));
    }
  }
  if(bbBool(f0.l_flist)){
    return ((t_mx2_SNode*)(f0.l_flist));
  }
  if(bbBool(f0.l_node)){
    return f0.l_node;
  }
  if(bbBool(this->m_outer)){
    return this->m_outer->m_FindNode(l_ident);
  }
  return ((t_mx2_SNode*)0);
}

t_mx2_FileScope* t_mx2_FileScope::m_FindFile(){
  return this;
}

void t_mx2_Block::init(){
  m_stmts=bbGCNew<t_std_collections_Stack_1Tt_mx2_Stmt_2>();
}

void t_mx2_Block::gcMark(){
  t_mx2_Scope::gcMark();
  bbGCMark(m_func);
  bbGCMark(m_stmts);
}

t_mx2_Block::t_mx2_Block(t_mx2_Block* l_outer):t_mx2_Scope(((t_mx2_Scope*)(l_outer))){
  init();
  this->m_func=l_outer->m_func;
  this->m_loop=l_outer->m_loop;
  this->m_inex=l_outer->m_inex;
}

t_mx2_Block::t_mx2_Block(t_mx2_FuncValue* l_func):t_mx2_Scope(l_func->m_scope){
  init();
  this->m_func=l_func;
}

void t_mx2_Block::m_Semant(bbArray<bbGCVar<t_mx2_StmtExpr>>* l_stmts){
  {
    bbInt l_0=bbInt(0);
    bbInt l_1=l_stmts->length();
    for(;(l_0<l_1);l_0+=1){
      struct f2_t : public bbGCFrame{
        t_mx2_StmtExpr* l_expr{};
        void gcMark(){
          bbGCMarkPtr(l_expr);
        }
      }f2{};
      f2.l_expr=l_stmts->at(l_0);
      try{
        struct f3_t : public bbGCFrame{
          t_mx2_Stmt* l_stmt{};
          void gcMark(){
            bbGCMarkPtr(l_stmt);
          }
        }f3{};
        f3.l_stmt=f2.l_expr->m_Semant(this);
        if(bbBool(f3.l_stmt)){
          this->m_Emit(f3.l_stmt);
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

t_mx2_Value* t_mx2_Block::m_FindValue(bbString l_ident){
  struct f0_t : public bbGCFrame{
    t_mx2_SNode* l_node{};
    t_mx2_VarValue* l_vvar{};
    void gcMark(){
      bbGCMarkPtr(l_node);
      bbGCMarkPtr(l_vvar);
    }
  }f0{};
  f0.l_node=this->m_FindNode(l_ident);
  if(!bbBool(f0.l_node)){
    return ((t_mx2_Value*)0);
  }
  f0.l_vvar=bb_object_cast<t_mx2_VarValue*>(f0.l_node);
  if(bbBool(f0.l_vvar)){
    if(f0.l_vvar->m_vdecl->m_kind==BB_T("local")||f0.l_vvar->m_vdecl->m_kind==BB_T("param")||f0.l_vvar->m_vdecl->m_kind==BB_T("capture")){
      if((bb_object_cast<t_mx2_Block*>(f0.l_vvar->m_scope)->m_func!=this->m_func)){
        if((this->m_func->m_fdecl->m_kind!=BB_T("lambda"))){
          return ((t_mx2_Value*)0);
        }
        f0.l_vvar=bbGCNew<t_mx2_VarValue>(BB_T("capture"),f0.l_vvar->m_vdecl->m_ident,((t_mx2_Value*)(f0.l_vvar)),((t_mx2_Scope*)(this->m_func->m_block)));
        this->m_func->m_block->m_Insert(f0.l_vvar->m_vdecl->m_ident,((t_mx2_SNode*)(f0.l_vvar)));
        this->m_func->m_captures->m_Push(f0.l_vvar);
        f0.l_node=((t_mx2_SNode*)(f0.l_vvar));
      }
    }
  }
  return f0.l_node->m_ToValue(this->m_func->m_selfValue);
}

void t_mx2_Block::m_Emit(t_mx2_Stmt* l_stmt){
  if(this->m_reachable){
    this->m_stmts->m_Push(l_stmt);
  }
}

t_mx2_VarValue* t_mx2_Block::m_AllocLocal(bbString l_ident,t_mx2_Value* l_init){
  struct f0_t : public bbGCFrame{
    t_mx2_VarValue* l_varValue{};
    t_mx2_Stmt* t0{};
    void gcMark(){
      bbGCMarkPtr(l_varValue);
      bbGCMarkPtr(t0);
    }
  }f0{};
  f0.l_varValue=bbGCNew<t_mx2_VarValue>(BB_T("local"),l_ident,l_init,((t_mx2_Scope*)(this)));
  this->m_stmts->m_Push(f0.t0=((t_mx2_Stmt*)(bbGCNew<t_mx2_VarDeclStmt>(((t_mx2_PNode*)0),f0.l_varValue))));
  this->m_Insert(l_ident,((t_mx2_SNode*)(f0.l_varValue)));
  return f0.l_varValue;
}

t_mx2_VarValue* t_mx2_Block::m_AllocLocal(t_mx2_Value* l_init){
  struct f0_t : public bbGCFrame{
    t_mx2_VarValue* l_varValue{};
    t_mx2_Stmt* t0{};
    void gcMark(){
      bbGCMarkPtr(l_varValue);
      bbGCMarkPtr(t0);
    }
  }f0{};
  bbString l_ident=(bbString{}+bbString(this->m_func->m_nextLocalId));
  this->m_func->m_nextLocalId+=1;
  f0.l_varValue=bbGCNew<t_mx2_VarValue>(BB_T("local"),l_ident,l_init,((t_mx2_Scope*)(this)));
  this->m_stmts->m_Push(f0.t0=((t_mx2_Stmt*)(bbGCNew<t_mx2_VarDeclStmt>(((t_mx2_PNode*)0),f0.l_varValue))));
  return f0.l_varValue;
}

t_mx2_FuncBlock::t_mx2_FuncBlock(t_mx2_FuncValue* l_func):t_mx2_Block(l_func){
}

bbBool t_mx2_FuncBlock::m_IsGeneric(){
  if(this->m_func->m_IsGeneric()){
    return true;
  }
  return t_mx2_Block::m_IsGeneric();
}

t_mx2_Type* t_mx2_FuncBlock::m_FindType(bbString l_ident){
  {
    bbInt l_i=bbInt(0);
    for(;(l_i<this->m_func->m_types->length());l_i+=1){
      if((l_ident==this->m_func->m_fdecl->m_genArgs->at(l_i))){
        return this->m_func->m_types->at(l_i);
      }
    }
  }
  return t_mx2_Block::m_FindType(l_ident);
}

void mx2_mx2cc_scope_init(){
  static bool done;
  if(done) return;
  done=true;
}

bbInit mx2_mx2cc_scope_init_v("mx2cc_scope",&mx2_mx2cc_scope_init);
