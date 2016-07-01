
#include "mx2cc_translator.h"

// ***** External *****

#include "mx2cc_builder.h"
#include "mx2cc_class.h"
#include "mx2cc_decl.h"
#include "mx2cc_errors.h"
#include "mx2cc_func.h"
#include "mx2cc_scope.h"
#include "mx2cc_std_collections_2map.h"
#include "mx2cc_std_collections_2stack.h"
#include "mx2cc_type.h"
#include "mx2cc_value.h"
#include "mx2cc_var.h"
#include "../../../../../modules/std/std.buildv1.0.0/desktop_release_linux/std_collections_2stack.h"

extern bbString g_mx2_ClassName(t_mx2_ClassType* l_ctype);
extern bbString g_mx2_VarName(t_mx2_VarValue* l_vvar);
extern bbString g_mx2_MakeRelativePath(bbString l_path,bbString l_baseDir);

// ***** Internal *****

bbBool g_mx2_IsGCPtrType(t_mx2_Type* l_type){
  struct f0_t : public bbGCFrame{
    t_mx2_ArrayType* l_atype{};
    t_mx2_ClassType* l_ctype{};
    void gcMark(){
      bbGCMarkPtr(l_atype);
      bbGCMarkPtr(l_ctype);
    }
  }f0{};
  f0.l_ctype=g_mx2_TCast_1Tt_mx2_ClassType_2(l_type);
  if(bbBool(f0.l_ctype)){
    return (!f0.l_ctype->m_IsVoid()&&!f0.l_ctype->m_IsStruct());
  }
  f0.l_atype=g_mx2_TCast_1Tt_mx2_ArrayType_2(l_type);
  if(bbBool(f0.l_atype)){
    return true;
  }
  return false;
}

bbBool g_mx2_IsGCType(t_mx2_Type* l_type){
  struct f0_t : public bbGCFrame{
    t_mx2_ClassType* l_ctype{};
    void gcMark(){
      bbGCMarkPtr(l_ctype);
    }
  }f0{};
  if(bbBool(g_mx2_TCast_1Tt_mx2_FuncType_2(l_type))){
    return true;
  }
  if(bbBool(g_mx2_TCast_1Tt_mx2_ArrayType_2(l_type))){
    return true;
  }
  f0.l_ctype=g_mx2_TCast_1Tt_mx2_ClassType_2(l_type);
  if(!bbBool(f0.l_ctype)){
    return false;
  }
  if(f0.l_ctype->m_IsVoid()){
    return false;
  }
  if(((f0.l_ctype->m_cdecl->m_kind==BB_T("class"))||(f0.l_ctype->m_cdecl->m_kind==BB_T("interface")))){
    return true;
  }
  if((f0.l_ctype->m_cdecl->m_kind==BB_T("struct"))){
    {
      struct f2_t : public bbGCFrame{
        t_std_collections_Stack_1Tt_mx2_VarValue_2_Iterator l_0{};
        void gcMark(){
          bbGCMark(l_0);
        }
      }f2{};
      f2.l_0=f0.l_ctype->m_fields->m_All();
      for(;!f2.l_0.m_AtEnd();f2.l_0.m_Bump()){
        struct f3_t : public bbGCFrame{
          t_mx2_VarValue* l_vvar{};
          void gcMark(){
            bbGCMarkPtr(l_vvar);
          }
        }f3{};
        f3.l_vvar=f2.l_0.m_Current();
        if(g_mx2_IsGCType(f3.l_vvar->m_type)){
          return true;
        }
      }
    }
    return false;
  }
  return false;
}

void t_mx2_Translator::init(){
  m__0buf=bbGCNew<t_std_collections_Stack_1s>();
  m__0insertStack=bbGCNew<t_std_collections_Stack_1Tt_std_collections_Stack_1s_2>();
  m__0usesFiles=bbGCNew<t_std_collections_Map_1sTt_mx2_FileDecl_2>();
  m__0usesTypes=bbGCNew<t_std_collections_Map_1sTt_mx2_ClassType_2>();
  m__0refs=bbGCNew<t_std_collections_Map_1Tt_mx2_SNode_2z>();
  m__0refsVars=bbGCNew<t_std_collections_Stack_1Tt_mx2_VarValue_2>();
  m__0refsFuncs=bbGCNew<t_std_collections_Stack_1Tt_mx2_FuncValue_2>();
  m__0refsTypes=bbGCNew<t_std_collections_Stack_1Tt_mx2_ClassType_2>();
  m__0incs=bbGCNew<t_std_collections_Map_1sTt_mx2_FileDecl_2>();
}

void t_mx2_Translator::gcMark(){
  bbGCMark(m__0buf);
  bbGCMark(m__0insertStack);
  bbGCMark(m__0gcframe);
  bbGCMark(m__0usesFiles);
  bbGCMark(m__0usesTypes);
  bbGCMark(m__0refs);
  bbGCMark(m__0refsVars);
  bbGCMark(m__0refsFuncs);
  bbGCMark(m__0refsTypes);
  bbGCMark(m__0incs);
}

t_mx2_Translator::t_mx2_Translator(){
  init();
  struct f0_t : public bbGCFrame{
    t_mx2_Builder* l_builder{};
    void gcMark(){
      bbGCMarkPtr(l_builder);
    }
  }f0{};
  f0.l_builder=g_mx2_Builder_instance;
  this->m_debug=(f0.l_builder->m_opts->m_config==BB_T("debug"));
}

void t_mx2_Translator::m_Uses(t_mx2_FileDecl* l_fdecl){
  this->m__0usesFiles->m__idxeq(l_fdecl->m_ident,l_fdecl);
}

void t_mx2_Translator::m_Uses(t_mx2_ClassType* l_ctype){
  this->m__0usesTypes->m__idxeq(g_mx2_ClassName(l_ctype),l_ctype);
  this->m_Uses(l_ctype->m_transFile);
}

void t_mx2_Translator::m_Uses(t_mx2_Type* l_type){
  struct f0_t : public bbGCFrame{
    t_mx2_ArrayType* l_atype{};
    t_mx2_ClassType* l_ctype{};
    void gcMark(){
      bbGCMarkPtr(l_atype);
      bbGCMarkPtr(l_ctype);
    }
  }f0{};
  f0.l_ctype=g_mx2_TCast_1Tt_mx2_ClassType_2(l_type);
  if(bbBool(f0.l_ctype)){
    this->m_Uses(f0.l_ctype);
  }
  f0.l_atype=g_mx2_TCast_1Tt_mx2_ArrayType_2(l_type);
  if(bbBool(f0.l_atype)){
    this->m_Uses(f0.l_atype->m_elemType);
  }
}

t_std_collections_Stack_1s* t_mx2_Translator::m_Slice(bbInt l_pos){
  struct f0_t : public bbGCFrame{
    t_std_collections_Stack_1s* l_buf{};
    void gcMark(){
      bbGCMarkPtr(l_buf);
    }
  }f0{};
  f0.l_buf=this->m__0buf->m_Slice(l_pos);
  this->m__0buf->m_Resize(l_pos);
  return f0.l_buf;
}

void t_mx2_Translator::m_Refs(t_mx2_Type* l_type){
  struct f0_t : public bbGCFrame{
    t_mx2_ArrayType* l_atype{};
    t_mx2_ClassType* l_ctype{};
    t_mx2_FuncType* l_ftype{};
    t_mx2_PointerType* l_ptype{};
    void gcMark(){
      bbGCMarkPtr(l_atype);
      bbGCMarkPtr(l_ctype);
      bbGCMarkPtr(l_ftype);
      bbGCMarkPtr(l_ptype);
    }
  }f0{};
  f0.l_ctype=g_mx2_TCast_1Tt_mx2_ClassType_2(l_type);
  if(bbBool(f0.l_ctype)){
    if(this->m_IsStruct(((t_mx2_Type*)(f0.l_ctype)))){
      this->m_Uses(f0.l_ctype);
      return;
    }
    if(this->m_AddRef(((t_mx2_SNode*)(f0.l_ctype)))){
      return;
    }
    this->m__0refsTypes->m_Push(f0.l_ctype);
    return;
  }
  f0.l_ftype=g_mx2_TCast_1Tt_mx2_FuncType_2(l_type);
  if(bbBool(f0.l_ftype)){
    this->m_Refs(f0.l_ftype->m_retType);
    {
      bbInt l_0=bbInt(0);
      bbInt l_1=f0.l_ftype->m_argTypes->length();
      for(;(l_0<l_1);l_0+=1){
        struct f3_t : public bbGCFrame{
          t_mx2_Type* l_type{};
          void gcMark(){
            bbGCMarkPtr(l_type);
          }
        }f3{};
        f3.l_type=f0.l_ftype->m_argTypes->at(l_0);
        this->m_Refs(f3.l_type);
      }
    }
    return;
  }
  f0.l_atype=g_mx2_TCast_1Tt_mx2_ArrayType_2(l_type);
  if(bbBool(f0.l_atype)){
    this->m_Refs(f0.l_atype->m_elemType);
    return;
  }
  f0.l_ptype=g_mx2_TCast_1Tt_mx2_PointerType_2(l_type);
  if(bbBool(f0.l_ptype)){
    this->m_Refs(f0.l_ptype->m_elemType);
    return;
  }
}

void t_mx2_Translator::m_Refs(t_mx2_FuncValue* l_func){
  struct f0_t : public bbGCFrame{
    t_mx2_FuncDecl* l_fdecl{};
    void gcMark(){
      bbGCMarkPtr(l_fdecl);
    }
  }f0{};
  f0.l_fdecl=l_func->m_fdecl;
  if(f0.l_fdecl->m_IsExtern()){
    this->m_Uses(l_func->m_transFile);
    return;
  }
  if(((f0.l_fdecl->m_kind==BB_T("function"))||l_func->m_IsExtension())){
    if(this->m_AddRef(((t_mx2_SNode*)(l_func)))){
      return;
    }
    this->m__0refsFuncs->m_Push(l_func);
    this->m_Refs(((t_mx2_Type*)(l_func->m_ftype)));
  }else if((f0.l_fdecl->m_kind==BB_T("method"))){
    struct f1_t : public bbGCFrame{
      t_mx2_ClassType* t0{};
      void gcMark(){
        bbGCMarkPtr(t0);
      }
    }f1{};
    this->m_Uses(f1.t0=l_func->m_scope->m_FindClass());
    this->m_Refs(((t_mx2_Type*)(l_func->m_ftype)));
  }else if((f0.l_fdecl->m_kind==BB_T("lambda"))){
  }else{
    throw bbGCNew<t_mx2_TransEx>(((BB_T("Trans.Refs() FuncValue '")+bbString::fromCString(l_func->typeName()))+BB_T("' not recognized")));
  }
}

void t_mx2_Translator::m_Refs(t_mx2_VarValue* l_vvar){
  if(l_vvar->m_vdecl->m_IsExtern()){
    this->m_Uses(l_vvar->m_transFile);
    return;
  }
  if(l_vvar->m_vdecl->m_kind==BB_T("field")){
    struct f1_t : public bbGCFrame{
      t_mx2_ClassType* t0{};
      void gcMark(){
        bbGCMarkPtr(t0);
      }
    }f1{};
    this->m_Refs(l_vvar->m_type);
    this->m_Uses(f1.t0=l_vvar->m_scope->m_FindClass());
  }else if(l_vvar->m_vdecl->m_kind==BB_T("const")||l_vvar->m_vdecl->m_kind==BB_T("global")){
    if(this->m_AddRef(((t_mx2_SNode*)(l_vvar)))){
      return;
    }
    this->m__0refsVars->m_Push(l_vvar);
    this->m_Refs(l_vvar->m_type);
  }else if(l_vvar->m_vdecl->m_kind==BB_T("local")||l_vvar->m_vdecl->m_kind==BB_T("param")||l_vvar->m_vdecl->m_kind==BB_T("capture")){
  }else{
    throw bbGCNew<t_mx2_TransEx>(((BB_T("Trans.Refs() VarValue '")+bbString::fromCString(l_vvar->typeName()))+BB_T("' not recognized")));
  }
}

bbBool t_mx2_Translator::m_IsValue(t_mx2_Type* l_type){
  return ((bbBool(g_mx2_TCast_1Tt_mx2_PrimType_2(l_type))||bbBool(g_mx2_TCast_1Tt_mx2_FuncType_2(l_type)))||this->m_IsStruct(l_type));
}

bbBool t_mx2_Translator::m_IsStruct(t_mx2_Type* l_type){
  struct f0_t : public bbGCFrame{
    t_mx2_ClassType* l_ctype{};
    void gcMark(){
      bbGCMarkPtr(l_ctype);
    }
  }f0{};
  f0.l_ctype=g_mx2_TCast_1Tt_mx2_ClassType_2(l_type);
  return (bbBool(f0.l_ctype)&&(f0.l_ctype->m_cdecl->m_kind==BB_T("struct")));
}

bbInt t_mx2_Translator::m_InsertPos(){
  return this->m__0buf->m_Length();
}

bbString t_mx2_Translator::m_InsertGCTmp(t_mx2_VarValue* l_vvar){
  this->m__0gcframe->m_vars->m__idxeq(l_vvar->m_vdecl->m_ident,l_vvar);
  return ((this->m__0gcframe->m_ident+BB_T("."))+g_mx2_VarName(l_vvar));
}

bbBool t_mx2_Translator::m_Included(t_mx2_FileDecl* l_fdecl){
  return this->m__0incs->m_Contains(l_fdecl->m_ident);
}

void t_mx2_Translator::m_FreeGCTmps(){
  {
    bbInt l_i=bbInt(0);
    for(;(l_i<this->m__0gcframe->m_tmps->m_Length());l_i+=1){
      this->m__0gcframe->m_tmps->m__idx(l_i)->m_used=false;
    }
  }
}

bbString t_mx2_Translator::m_FindGCTmp(t_mx2_VarValue* l_vvar){
  struct f0_t : public bbGCFrame{
    t_mx2_Translator_GCFrame* l_frame{};
    t_mx2_VarDecl* l_vdecl{};
    void gcMark(){
      bbGCMarkPtr(l_frame);
      bbGCMarkPtr(l_vdecl);
    }
  }f0{};
  f0.l_vdecl=l_vvar->m_vdecl;
  f0.l_frame=this->m__0gcframe;
  while(bbBool(f0.l_frame)){
    if((f0.l_frame->m_vars->m__idx(f0.l_vdecl->m_ident)==l_vvar)){
      return ((f0.l_frame->m_ident+BB_T("."))+g_mx2_VarName(l_vvar));
    }
    f0.l_frame=f0.l_frame->m_outer;
  }
  return g_mx2_VarName(l_vvar);
}

void t_mx2_Translator::m_EndInsert(){
  struct f0_t : public bbGCFrame{
    t_std_collections_Stack_1s* l_buf{};
    void gcMark(){
      bbGCMarkPtr(l_buf);
    }
  }f0{};
  f0.l_buf=this->m__0insertStack->m_Pop();
  g_std_collections_Stack_1s_Append_1Tt_std_collections_Stack_1s_2(this->m__0buf,f0.l_buf);
}

void t_mx2_Translator::m_EndGCFrame(){
  if((!this->m__0gcframe->m_vars->m_Empty()||!this->m__0gcframe->m_tmps->m_Empty())){
    this->m_BeginInsert(this->m__0gcframe->m_inspos);
    this->m_Emit(((BB_T("struct ")+this->m__0gcframe->m_ident)+BB_T("_t : public bbGCFrame{")));
    bbString l_ctorArgs=bbString{};
    bbString l_ctorInits=bbString{};
    bbString l_ctorVals=bbString{};
    {
      struct f2_t : public bbGCFrame{
        t_std_collections_Map_1sTt_mx2_VarValue_2_ValueIterator l_0{};
        void gcMark(){
          bbGCMark(l_0);
        }
      }f2{};
      f2.l_0=this->m__0gcframe->m_vars->m_Values().m_All();
      for(;f2.l_0.m_Valid();f2.l_0.m_Bump()){
        struct f3_t : public bbGCFrame{
          t_mx2_VarValue* l_varval{};
          void gcMark(){
            bbGCMarkPtr(l_varval);
          }
        }f3{};
        f3.l_varval=f2.l_0.m_Current();
        bbString l_varty=this->m_TransType(f3.l_varval->m_type);
        bbString l_varid=g_mx2_VarName(f3.l_varval);
        this->m_Emit((((l_varty+BB_T(" "))+l_varid)+BB_T("{};")));
        if((f3.l_varval->m_vdecl->m_kind==BB_T("param"))){
          l_ctorArgs+=(((BB_T(",")+l_varty)+BB_T(" "))+l_varid);
          l_ctorInits+=((((BB_T(",")+l_varid)+BB_T("("))+l_varid)+BB_T(")"));
          l_ctorVals+=(BB_T(",")+l_varid);
        }
      }
    }
    {
      struct f2_t : public bbGCFrame{
        t_std_collections_Stack_1Tt_mx2_Translator_GCTmp_2_Iterator l_1{};
        void gcMark(){
          bbGCMark(l_1);
        }
      }f2{};
      f2.l_1=this->m__0gcframe->m_tmps->m_All();
      for(;!f2.l_1.m_AtEnd();f2.l_1.m_Bump()){
        struct f3_t : public bbGCFrame{
          t_mx2_Translator_GCTmp* l_tmp{};
          void gcMark(){
            bbGCMarkPtr(l_tmp);
          }
        }f3{};
        f3.l_tmp=f2.l_1.m_Current();
        this->m_Emit((((this->m_TransType(f3.l_tmp->m_type)+BB_T(" "))+f3.l_tmp->m_ident)+BB_T("{};")));
      }
    }
    if(bbBool(l_ctorArgs)){
      l_ctorVals=((BB_T("{")+l_ctorVals.slice(1))+BB_T("}"));
      this->m_Emit((((((this->m__0gcframe->m_ident+BB_T("_t("))+l_ctorArgs.slice(1))+BB_T("):"))+l_ctorInits.slice(1))+BB_T("{")));
      this->m_Emit(BB_T("}"));
    }else{
      l_ctorVals=BB_T("{}");
    }
    this->m_Emit(BB_T("void gcMark(){"));
    {
      struct f2_t : public bbGCFrame{
        t_std_collections_Map_1sTt_mx2_VarValue_2_ValueIterator l_2{};
        void gcMark(){
          bbGCMark(l_2);
        }
      }f2{};
      f2.l_2=this->m__0gcframe->m_vars->m_Values().m_All();
      for(;f2.l_2.m_Valid();f2.l_2.m_Bump()){
        struct f3_t : public bbGCFrame{
          t_mx2_VarValue* l_vvar{};
          void gcMark(){
            bbGCMarkPtr(l_vvar);
          }
        }f3{};
        f3.l_vvar=f2.l_2.m_Current();
        this->m_Uses(f3.l_vvar->m_type);
        if(g_mx2_IsGCPtrType(f3.l_vvar->m_type)){
          this->m_Emit(((BB_T("bbGCMarkPtr(")+g_mx2_VarName(f3.l_vvar))+BB_T(");")));
        }else{
          this->m_Emit(((BB_T("bbGCMark(")+g_mx2_VarName(f3.l_vvar))+BB_T(");")));
        }
      }
    }
    {
      struct f2_t : public bbGCFrame{
        t_std_collections_Stack_1Tt_mx2_Translator_GCTmp_2_Iterator l_3{};
        void gcMark(){
          bbGCMark(l_3);
        }
      }f2{};
      f2.l_3=this->m__0gcframe->m_tmps->m_All();
      for(;!f2.l_3.m_AtEnd();f2.l_3.m_Bump()){
        struct f3_t : public bbGCFrame{
          t_mx2_Translator_GCTmp* l_tmp{};
          void gcMark(){
            bbGCMarkPtr(l_tmp);
          }
        }f3{};
        f3.l_tmp=f2.l_3.m_Current();
        this->m_Uses(f3.l_tmp->m_type);
        if(g_mx2_IsGCPtrType(f3.l_tmp->m_type)){
          this->m_Emit(((BB_T("bbGCMarkPtr(")+f3.l_tmp->m_ident)+BB_T(");")));
        }else{
          this->m_Emit(((BB_T("bbGCMark(")+f3.l_tmp->m_ident)+BB_T(");")));
        }
      }
    }
    this->m_Emit(BB_T("}"));
    this->m_Emit((((BB_T("}")+this->m__0gcframe->m_ident)+l_ctorVals)+BB_T(";")));
    this->m_EndInsert();
  }
  this->m__0gcframe=this->m__0gcframe->m_outer;
}

void t_mx2_Translator::m_EndDeps(bbString l_baseDir){
  this->m_BeginInsert(this->m__0depsPos);
  this->m_EmitBr();
  this->m_Emit(BB_T("// ***** External *****"));
  this->m_EmitBr();
  {
    struct f1_t : public bbGCFrame{
      t_std_collections_Map_1sTt_mx2_FileDecl_2_ValueIterator l_0{};
      void gcMark(){
        bbGCMark(l_0);
      }
    }f1{};
    f1.l_0=this->m__0usesFiles->m_Values().m_All();
    for(;f1.l_0.m_Valid();f1.l_0.m_Bump()){
      struct f2_t : public bbGCFrame{
        t_mx2_FileDecl* l_fdecl{};
        void gcMark(){
          bbGCMarkPtr(l_fdecl);
        }
      }f2{};
      f2.l_fdecl=f1.l_0.m_Current();
      this->m_EmitInclude(f2.l_fdecl,l_baseDir);
    }
  }
  this->m_EmitBr();
  {
    struct f1_t : public bbGCFrame{
      t_std_collections_Stack_1Tt_mx2_ClassType_2_Iterator l_1{};
      void gcMark(){
        bbGCMark(l_1);
      }
    }f1{};
    f1.l_1=this->m__0refsTypes->m_All();
    for(;!f1.l_1.m_AtEnd();f1.l_1.m_Bump()){
      struct f2_t : public bbGCFrame{
        t_mx2_ClassType* l_ctype{};
        void gcMark(){
          bbGCMarkPtr(l_ctype);
        }
      }f2{};
      f2.l_ctype=f1.l_1.m_Current();
      if(!this->m_Included(f2.l_ctype->m_transFile)){
        bbString l_cname=g_mx2_ClassName(f2.l_ctype);
        this->m_Emit(((BB_T("struct ")+g_mx2_ClassName(f2.l_ctype))+BB_T(";")));
        if((this->m_debug&&!f2.l_ctype->m_cdecl->m_IsExtern())){
          bbString l_tname=l_cname;
          if(!this->m_IsStruct(((t_mx2_Type*)(f2.l_ctype)))){
            l_tname+=BB_T("*");
          }
          this->m_Emit(((BB_T("bbString bbDBType(")+l_tname)+BB_T("*);")));
          this->m_Emit(((BB_T("bbString bbDBValue(")+l_tname)+BB_T("*);")));
        }
      }
    }
  }
  this->m__0refsTypes->m_Clear();
  this->m_EmitBr();
  {
    struct f1_t : public bbGCFrame{
      t_std_collections_Stack_1Tt_mx2_VarValue_2_Iterator l_2{};
      void gcMark(){
        bbGCMark(l_2);
      }
    }f1{};
    f1.l_2=this->m__0refsVars->m_All();
    for(;!f1.l_2.m_AtEnd();f1.l_2.m_Bump()){
      struct f2_t : public bbGCFrame{
        t_mx2_VarValue* l_vvar{};
        void gcMark(){
          bbGCMarkPtr(l_vvar);
        }
      }f2{};
      f2.l_vvar=f1.l_2.m_Current();
      if(!this->m_Included(f2.l_vvar->m_transFile)){
        this->m_Emit(((BB_T("extern ")+this->m_VarProto(f2.l_vvar))+BB_T(";")));
      }
    }
  }
  this->m__0refsVars->m_Clear();
  this->m_EmitBr();
  {
    struct f1_t : public bbGCFrame{
      t_std_collections_Stack_1Tt_mx2_FuncValue_2_Iterator l_3{};
      void gcMark(){
        bbGCMark(l_3);
      }
    }f1{};
    f1.l_3=this->m__0refsFuncs->m_All();
    for(;!f1.l_3.m_AtEnd();f1.l_3.m_Bump()){
      struct f2_t : public bbGCFrame{
        t_mx2_FuncValue* l_func{};
        void gcMark(){
          bbGCMarkPtr(l_func);
        }
      }f2{};
      f2.l_func=f1.l_3.m_Current();
      if(!this->m_Included(f2.l_func->m_transFile)){
        this->m_Emit(((BB_T("extern ")+this->m_FuncProto(f2.l_func))+BB_T(";")));
      }
    }
  }
  this->m__0refsFuncs->m_Clear();
  this->m_EmitBr();
  this->m_EndInsert();
}

void t_mx2_Translator::m_EmitInclude(t_mx2_FileDecl* l_fdecl,bbString l_baseDir){
  if(this->m__0incs->m_Contains(l_fdecl->m_ident)){
    return;
  }
  this->m_Emit(((BB_T("#include \"")+g_mx2_MakeRelativePath(l_fdecl->m_hfile,l_baseDir))+BB_T("\"")));
  this->m__0incs->m__idxeq(l_fdecl->m_ident,l_fdecl);
}

void t_mx2_Translator::m_EmitBr(){
  if((bbBool(this->m__0buf->m_Length())&&!bbBool(this->m__0buf->m_Top()))){
    return;
  }
  this->m__0buf->m_Push(bbString{});
}

void t_mx2_Translator::m_Emit(bbString l_str){
  if(!bbBool(l_str)){
    return;
  }
  if(l_str.startsWith(BB_T("}"))){
    this->m__0indent=this->m__0indent.slice(bbInt(0),-2);
  }
  this->m__0buf->m_Push((this->m__0indent+l_str));
  if(l_str.endsWith(BB_T("{"))){
    this->m__0indent+=BB_T("  ");
  }
}

bbString t_mx2_Translator::m_CFuncType(t_mx2_FuncType* l_type){
  bbString l_retType=this->m_TransType(l_type->m_retType);
  bbString l_argTypes=bbString{};
  {
    bbInt l_i=bbInt(0);
    for(;(l_i<l_type->m_argTypes->length());l_i+=1){
      if(bbBool(l_argTypes)){
        l_argTypes+=BB_T(",");
      }
      l_argTypes+=this->m_TransType(l_type->m_argTypes->at(l_i));
    }
  }
  return (((l_retType+BB_T("("))+l_argTypes)+BB_T(")"));
}

void t_mx2_Translator::m_BeginInsert(bbInt l_pos){
  struct f0_t : public bbGCFrame{
    t_std_collections_Stack_1s* l_buf{};
    void gcMark(){
      bbGCMarkPtr(l_buf);
    }
  }f0{};
  f0.l_buf=this->m__0buf->m_Slice(l_pos);
  this->m__0insertStack->m_Push(f0.l_buf);
  this->m__0buf->m_Resize(l_pos);
}

void t_mx2_Translator::m_BeginGCFrame(t_mx2_FuncValue* l_func){
  struct f0_t : public bbGCFrame{
    t_mx2_AssignedGCParamsVisitor* l_visitor{};
    void gcMark(){
      bbGCMarkPtr(l_visitor);
    }
  }f0{};
  this->m_BeginGCFrame();
  f0.l_visitor=bbGCNew<t_mx2_AssignedGCParamsVisitor>();
  f0.l_visitor->m_Visit(l_func->m_block);
  {
    struct f1_t : public bbGCFrame{
      t_std_collections_Map_1sTt_mx2_VarValue_2_Iterator l_0{};
      void gcMark(){
        bbGCMark(l_0);
      }
    }f1{};
    f1.l_0=f0.l_visitor->m_gcparams->m_All();
    for(;f1.l_0.m_Valid();f1.l_0.m_Bump()){
      struct f2_t : public bbGCFrame{
        t_std_collections_Map_1sTt_mx2_VarValue_2_Node* l_it{};
        t_mx2_VarValue* t0{};
        void gcMark(){
          bbGCMarkPtr(l_it);
          bbGCMarkPtr(t0);
        }
      }f2{};
      f2.l_it=f1.l_0.m_Current();
      this->m_InsertGCTmp(f2.t0=f2.l_it->m_Value());
    }
  }
}

void t_mx2_Translator::m_BeginGCFrame(){
  this->m__0gcframe=bbGCNew<t_mx2_Translator_GCFrame>(this->m__0gcframe,this->m_InsertPos());
}

void t_mx2_Translator::m_BeginDeps(){
  this->m__0depsPos=this->m_InsertPos();
}

bbString t_mx2_Translator::m_AllocGCTmp(t_mx2_Type* l_type){
  struct f0_t : public bbGCFrame{
    t_mx2_Translator_GCTmp* l_tmp{};
    void gcMark(){
      bbGCMarkPtr(l_tmp);
    }
  }f0{};
  {
    bbInt l_i=bbInt(0);
    for(;(l_i<this->m__0gcframe->m_tmps->m_Length());l_i+=1){
      struct f2_t : public bbGCFrame{
        t_mx2_Translator_GCTmp* l_tmp{};
        void gcMark(){
          bbGCMarkPtr(l_tmp);
        }
      }f2{};
      f2.l_tmp=this->m__0gcframe->m_tmps->m__idx(l_i);
      if((f2.l_tmp->m_used||!f2.l_tmp->m_type->m_Equals(l_type))){
        continue;
      }
      f2.l_tmp->m_used=true;
      return ((this->m__0gcframe->m_ident+BB_T("."))+f2.l_tmp->m_ident);
    }
  }
  f0.l_tmp=bbGCNew<t_mx2_Translator_GCTmp>();
  f0.l_tmp->m_used=true;
  f0.l_tmp->m_type=l_type;
  f0.l_tmp->m_ident=(BB_T("t")+bbString(this->m__0gcframe->m_tmps->m_Length()));
  this->m__0gcframe->m_tmps->m_Push(f0.l_tmp);
  return ((this->m__0gcframe->m_ident+BB_T("."))+f0.l_tmp->m_ident);
}

bbBool t_mx2_Translator::m_AddRef(t_mx2_SNode* l_node){
  if(this->m__0refs->m__idx(l_node)){
    return true;
  }
  this->m__0refs->m__idxeq(l_node,true);
  return false;
}

void t_mx2_AssignedGCParamsVisitor::init(){
  m_gcparams=bbGCNew<t_std_collections_Map_1sTt_mx2_VarValue_2>();
}

void t_mx2_AssignedGCParamsVisitor::gcMark(){
  t_mx2_StmtVisitor::gcMark();
  bbGCMark(m_gcparams);
}

void t_mx2_AssignedGCParamsVisitor::m_Visit(t_mx2_AssignStmt* l_stmt){
  struct f0_t : public bbGCFrame{
    t_mx2_VarValue* l_vvar{};
    void gcMark(){
      bbGCMarkPtr(l_vvar);
    }
  }f0{};
  f0.l_vvar=bb_object_cast<t_mx2_VarValue*>(l_stmt->m_lhs);
  if(((bbBool(f0.l_vvar)&&(f0.l_vvar->m_vdecl->m_kind==BB_T("param")))&&g_mx2_IsGCType(f0.l_vvar->m_type))){
    this->m_gcparams->m__idxeq(f0.l_vvar->m_vdecl->m_ident,f0.l_vvar);
  }
}

void t_mx2_Translator_GCFrame::init(){
  m_vars=bbGCNew<t_std_collections_Map_1sTt_mx2_VarValue_2>();
  m_tmps=bbGCNew<t_std_collections_Stack_1Tt_mx2_Translator_GCTmp_2>();
}

void t_mx2_Translator_GCFrame::gcMark(){
  bbGCMark(m_outer);
  bbGCMark(m_vars);
  bbGCMark(m_tmps);
}

t_mx2_Translator_GCFrame::t_mx2_Translator_GCFrame(t_mx2_Translator_GCFrame* l_outer,bbInt l_inspos){
  init();
  this->m_outer=l_outer;
  this->m_inspos=l_inspos;
  if(bbBool(l_outer)){
    this->m_depth=(l_outer->m_depth+1);
  }
  this->m_ident=(BB_T("f")+bbString(this->m_depth));
}

void t_mx2_Translator_GCTmp::gcMark(){
  bbGCMark(m_type);
}

void mx2_mx2cc_translator_init(){
  static bool done;
  if(done) return;
  done=true;
}

bbInit mx2_mx2cc_translator_init_v("mx2cc_translator",&mx2_mx2cc_translator_init);
