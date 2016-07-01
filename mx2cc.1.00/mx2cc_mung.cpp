
#include "mx2cc_mung.h"

// ***** External *****

#include "../../../../../modules/monkey/monkey.buildv1.0.0/desktop_release_linux/monkey_types.h"
#include "mx2cc_class.h"
#include "mx2cc_decl.h"
#include "mx2cc_enum.h"
#include "mx2cc_func.h"
#include "mx2cc_scope.h"
#include "mx2cc_type.h"
#include "mx2cc_var.h"

extern bbBool g_std_stringio_IsIdent(bbInt l_chr);

// ***** Internal *****

bbString g_mx2_VarName(t_mx2_VarValue* l_vvar){
  struct f0_t : public bbGCFrame{
    t_mx2_VarDecl* l_vdecl{};
    void gcMark(){
      bbGCMarkPtr(l_vdecl);
    }
  }f0{};
  f0.l_vdecl=l_vvar->m_vdecl;
  if(bbBool(f0.l_vdecl->m_symbol)){
    return f0.l_vdecl->m_symbol;
  }
  if(f0.l_vdecl->m_IsExtern()){
    bbString l_symbol=f0.l_vdecl->m_ident;
    if(((f0.l_vdecl->m_kind==BB_T("global"))||(f0.l_vdecl->m_kind==BB_T("const")))){
      struct f2_t : public bbGCFrame{
        t_mx2_ClassScope* l_cscope{};
        void gcMark(){
          bbGCMarkPtr(l_cscope);
        }
      }f2{};
      f2.l_cscope=bb_object_cast<t_mx2_ClassScope*>(l_vvar->m_scope);
      if(bbBool(f2.l_cscope)){
        l_symbol=((g_mx2_ClassName(f2.l_cscope->m_ctype)+BB_T("::"))+l_symbol);
      }
    }
    return l_symbol;
  }
  bbString l_sym=g_mx2_MungIdent(f0.l_vdecl->m_ident);
  if(f0.l_vdecl->m_kind==BB_T("local")||f0.l_vdecl->m_kind==BB_T("param")||f0.l_vdecl->m_kind==BB_T("capture")){
    return (BB_T("l_")+l_sym);
  }else if(f0.l_vdecl->m_kind==BB_T("field")){
    return (BB_T("m_")+l_sym);
  }else if(f0.l_vdecl->m_kind==BB_T("global")||f0.l_vdecl->m_kind==BB_T("const")){
    if(bbBool(bb_object_cast<t_mx2_Block*>(l_vvar->m_scope))){
      return (BB_T("g_")+l_sym);
    }
    return (((BB_T("g_")+g_mx2_ScopeName(l_vvar->m_scope))+BB_T("_"))+l_sym);
  }
  return BB_T("????? VarName ?????");
}

bbString g_mx2_FuncName(t_mx2_FuncValue* l_func){
  struct f0_t : public bbGCFrame{
    t_mx2_FuncDecl* l_fdecl{};
    void gcMark(){
      bbGCMarkPtr(l_fdecl);
    }
  }f0{};
  if(bbBool(l_func->m_overrides)){
    return g_mx2_FuncName(l_func->m_overrides);
  }
  f0.l_fdecl=l_func->m_fdecl;
  if(bbBool(f0.l_fdecl->m_symbol)){
    return f0.l_fdecl->m_symbol;
  }
  if(f0.l_fdecl->m_IsExtern()){
    bbString l_symbol=f0.l_fdecl->m_ident;
    if((f0.l_fdecl->m_kind==BB_T("function"))){
      struct f2_t : public bbGCFrame{
        t_mx2_ClassScope* l_cscope{};
        void gcMark(){
          bbGCMarkPtr(l_cscope);
        }
      }f2{};
      f2.l_cscope=bb_object_cast<t_mx2_ClassScope*>(l_func->m_scope);
      if(bbBool(f2.l_cscope)){
        l_symbol=((g_mx2_ClassName(f2.l_cscope->m_ctype)+BB_T("::"))+l_symbol);
      }
    }
    return l_symbol;
  }
  if(((f0.l_fdecl->m_kind==BB_T("function"))||bbBool(l_func->m_types))){
    bbString l_sym=(((BB_T("g_")+g_mx2_ScopeName(l_func->m_scope))+BB_T("_"))+g_mx2_MungIdent(f0.l_fdecl->m_ident));
    if(bbBool(l_func->m_types)){
      l_sym+=g_mx2_MungArgs(l_func->m_types);
    }
    return l_sym;
  }else if((f0.l_fdecl->m_kind==BB_T("method"))){
    if((f0.l_fdecl->m_ident==BB_T("new"))){
      return g_mx2_ClassName(bb_object_cast<t_mx2_ClassScope*>(l_func->m_scope)->m_ctype);
    }
    bbString l_sym=(BB_T("m_")+g_mx2_MungIdent(f0.l_fdecl->m_ident));
    if(bbBool(l_func->m_types)){
      l_sym+=g_mx2_MungArgs(l_func->m_types);
    }
    return l_sym;
  }else if((f0.l_fdecl->m_kind==BB_T("lambda"))){
    return BB_T("invoke");
  }
  return BB_T("????? FuncName ?????");
}

bbString g_mx2_ClassName(t_mx2_ClassType* l_ctype){
  struct f0_t : public bbGCFrame{
    t_mx2_ClassDecl* l_cdecl{};
    void gcMark(){
      bbGCMarkPtr(l_cdecl);
    }
  }f0{};
  f0.l_cdecl=l_ctype->m_cdecl;
  if(bbBool(f0.l_cdecl->m_symbol)){
    return f0.l_cdecl->m_symbol;
  }
  if(f0.l_cdecl->m_IsExtern()){
    struct f1_t : public bbGCFrame{
      t_mx2_ClassScope* l_cscope{};
      void gcMark(){
        bbGCMarkPtr(l_cscope);
      }
    }f1{};
    bbString l_symbol=f0.l_cdecl->m_ident;
    f1.l_cscope=bb_object_cast<t_mx2_ClassScope*>(l_ctype->m_scope->m_outer);
    if(bbBool(f1.l_cscope)){
      l_symbol=((g_mx2_ClassName(f1.l_cscope->m_ctype)+BB_T("::"))+l_symbol);
    }
    return l_symbol;
  }
  return (BB_T("t_")+g_mx2_ScopeName(((t_mx2_Scope*)(l_ctype->m_scope))));
}

bbString g_mx2_EnumValueName(t_mx2_EnumType* l_etype,bbString l_value){
  struct f0_t : public bbGCFrame{
    t_mx2_EnumDecl* l_edecl{};
    void gcMark(){
      bbGCMarkPtr(l_edecl);
    }
  }f0{};
  if(!l_value.startsWith(BB_T("@"))){
    return l_value;
  }
  l_value=l_value.slice(1);
  f0.l_edecl=l_etype->m_edecl;
  if(bbBool(f0.l_edecl->m_symbol)){
    if(f0.l_edecl->m_symbol.endsWith(BB_T("::"))){
      if((f0.l_edecl->m_symbol!=BB_T("::"))){
        l_value=(f0.l_edecl->m_symbol+l_value);
      }
      return ((BB_T("int(")+l_value)+BB_T(")"));
    }
    bbInt l_i=f0.l_edecl->m_symbol.findLast(BB_T("::"),bbInt(0));
    if((l_i!=-1)){
      return (f0.l_edecl->m_symbol.slice(bbInt(0),(l_i+2))+l_value);
    }
  }
  return l_value;
}

bbString g_mx2_EnumName(t_mx2_EnumType* l_etype){
  struct f0_t : public bbGCFrame{
    t_mx2_EnumDecl* l_edecl{};
    void gcMark(){
      bbGCMarkPtr(l_edecl);
    }
  }f0{};
  f0.l_edecl=l_etype->m_edecl;
  if(bbBool(f0.l_edecl->m_symbol)){
    if(f0.l_edecl->m_symbol.endsWith(BB_T("::"))){
      return BB_T("int");
    }
    return f0.l_edecl->m_symbol;
  }
  if(f0.l_edecl->m_IsExtern()){
    return f0.l_edecl->m_ident;
  }
  return BB_T("bbInt");
}

bbString g_mx2_ScopeName(t_mx2_Scope* l_scope){
  struct f0_t : public bbGCFrame{
    t_mx2_ClassScope* l_cscope{};
    t_mx2_FileScope* l_fscope{};
    void gcMark(){
      bbGCMarkPtr(l_cscope);
      bbGCMarkPtr(l_fscope);
    }
  }f0{};
  if(!bbBool(l_scope)){
    return BB_T("????? ScopeName ?????");
  }
  f0.l_fscope=bb_object_cast<t_mx2_FileScope*>(l_scope);
  if(bbBool(f0.l_fscope)){
    return g_mx2_MungIdent(f0.l_fscope->m_fdecl->m_nmspace).replace(BB_T("."),BB_T("_"));
  }
  f0.l_cscope=bb_object_cast<t_mx2_ClassScope*>(l_scope);
  if(bbBool(f0.l_cscope)){
    struct f1_t : public bbGCFrame{
      t_mx2_ClassType* l_ctype{};
      void gcMark(){
        bbGCMarkPtr(l_ctype);
      }
    }f1{};
    f1.l_ctype=f0.l_cscope->m_ctype;
    bbString l_sym=((g_mx2_ScopeName(l_scope->m_outer)+BB_T("_"))+g_mx2_MungIdent(f1.l_ctype->m_cdecl->m_ident));
    if(bbBool(f1.l_ctype->m_types)){
      l_sym+=g_mx2_MungArgs(f1.l_ctype->m_types);
    }
    return l_sym;
  }
  return g_mx2_ScopeName(l_scope->m_outer);
}

bbString g_mx2_MungArgs(bbArray<bbGCVar<t_mx2_Type>>* l_types){
  bbString l_sym=BB_T("_1");
  {
    bbInt l_0=bbInt(0);
    bbInt l_1=l_types->length();
    for(;(l_0<l_1);l_0+=1){
      struct f2_t : public bbGCFrame{
        t_mx2_Type* l_ty{};
        void gcMark(){
          bbGCMarkPtr(l_ty);
        }
      }f2{};
      f2.l_ty=l_types->at(l_0);
      if(bbBool(g_mx2_TCast_1Tt_mx2_GenArgType_2(f2.l_ty))){
        continue;
      }
      l_sym+=g_mx2_MungArg(f2.l_ty);
    }
  }
  return l_sym;
}

bbString g_mx2_MungArg(t_mx2_Type* l_type){
  struct f0_t : public bbGCFrame{
    t_mx2_ArrayType* l_atype{};
    t_mx2_ClassType* l_ctype{};
    t_mx2_EnumType* l_etype{};
    t_mx2_FuncType* l_ftype{};
    t_mx2_PrimType* l_ptype{};
    t_mx2_PointerType* l_qtype{};
    t_mx2_Type* t0{};
    void gcMark(){
      bbGCMarkPtr(l_atype);
      bbGCMarkPtr(l_ctype);
      bbGCMarkPtr(l_etype);
      bbGCMarkPtr(l_ftype);
      bbGCMarkPtr(l_ptype);
      bbGCMarkPtr(l_qtype);
      bbGCMarkPtr(t0);
    }
  }f0{};
  if((f0.t0=l_type->m_Dealias())->m__eq(((t_mx2_Type*)(g_mx2_Type_VoidType)))){
    return BB_T("v");
  }
  f0.l_ptype=g_mx2_TCast_1Tt_mx2_PrimType_2(l_type);
  if(bbBool(f0.l_ptype)){
    if(f0.l_ptype==g_mx2_Type_BoolType){
      return BB_T("z");
    }else if(f0.l_ptype==g_mx2_Type_ByteType){
      return BB_T("b");
    }else if(f0.l_ptype==g_mx2_Type_UByteType){
      return BB_T("c");
    }else if(f0.l_ptype==g_mx2_Type_ShortType){
      return BB_T("h");
    }else if(f0.l_ptype==g_mx2_Type_UShortType){
      return BB_T("t");
    }else if(f0.l_ptype==g_mx2_Type_IntType){
      return BB_T("i");
    }else if(f0.l_ptype==g_mx2_Type_UIntType){
      return BB_T("j");
    }else if(f0.l_ptype==g_mx2_Type_LongType){
      return BB_T("l");
    }else if(f0.l_ptype==g_mx2_Type_ULongType){
      return BB_T("m");
    }else if(f0.l_ptype==g_mx2_Type_FloatType){
      return BB_T("f");
    }else if(f0.l_ptype==g_mx2_Type_DoubleType){
      return BB_T("d");
    }else if(f0.l_ptype==g_mx2_Type_StringType){
      return BB_T("s");
    }
    return BB_T("????? MungArg ?????");
  }
  f0.l_atype=g_mx2_TCast_1Tt_mx2_ArrayType_2(l_type);
  if(bbBool(f0.l_atype)){
    bbString l_sym=BB_T("A");
    if((f0.l_atype->m_rank>1)){
      l_sym+=bbString(f0.l_atype->m_rank);
    }
    return (l_sym+g_mx2_MungArg(f0.l_atype->m_elemType));
  }
  f0.l_ftype=g_mx2_TCast_1Tt_mx2_FuncType_2(l_type);
  if(bbBool(f0.l_ftype)){
    bbString l_sym=(BB_T("F")+g_mx2_MungArg(f0.l_ftype->m_retType));
    {
      bbInt l_0=bbInt(0);
      bbInt l_1=f0.l_ftype->m_argTypes->length();
      for(;(l_0<l_1);l_0+=1){
        struct f3_t : public bbGCFrame{
          t_mx2_Type* l_ty{};
          void gcMark(){
            bbGCMarkPtr(l_ty);
          }
        }f3{};
        f3.l_ty=f0.l_ftype->m_argTypes->at(l_0);
        l_sym+=g_mx2_MungArg(f3.l_ty);
      }
    }
    return (l_sym+BB_T("E"));
  }
  f0.l_ctype=g_mx2_TCast_1Tt_mx2_ClassType_2(l_type);
  if(bbBool(f0.l_ctype)){
    return ((BB_T("T")+g_mx2_ClassName(f0.l_ctype))+BB_T("_2"));
  }
  f0.l_etype=g_mx2_TCast_1Tt_mx2_EnumType_2(l_type);
  if(bbBool(f0.l_etype)){
    return ((BB_T("T")+g_mx2_EnumName(f0.l_etype))+BB_T("_2"));
  }
  f0.l_qtype=g_mx2_TCast_1Tt_mx2_PointerType_2(l_type);
  if(bbBool(f0.l_qtype)){
    return (BB_T("P")+g_mx2_MungArg(f0.l_qtype->m_elemType));
  }
  return ((BB_T("????? MungArg ")+bbString::fromCString(l_type->typeName()))+BB_T(" ?????"));
}

bbString g_mx2_MungIdent(bbString l_ident){
  if(!g_std_stringio_IsIdent(l_ident[bbInt(0)])){
    return g_mx2_OpSym(l_ident);
  }
  return l_ident.replace(BB_T("_"),BB_T("_0"));
}

bbString g_mx2_OpSym(bbString l_id){
  if(l_id==BB_T("*")){
    return BB_T("_mul");
  }else if(l_id==BB_T("/")){
    return BB_T("_div");
  }else if(l_id==BB_T("+")){
    return BB_T("_add");
  }else if(l_id==BB_T("-")){
    return BB_T("_sub");
  }else if(l_id==BB_T("&")){
    return BB_T("_and");
  }else if(l_id==BB_T("|")){
    return BB_T("_or");
  }else if(l_id==BB_T("~")){
    return BB_T("_xor");
  }else if(l_id==BB_T("[]")){
    return BB_T("_idx");
  }else if(l_id==BB_T("*=")){
    return BB_T("_muleq");
  }else if(l_id==BB_T("/=")){
    return BB_T("_diveq");
  }else if(l_id==BB_T("+=")){
    return BB_T("_addeq");
  }else if(l_id==BB_T("-=")){
    return BB_T("_subeq");
  }else if(l_id==BB_T("&=")){
    return BB_T("_andeq");
  }else if(l_id==BB_T("|=")){
    return BB_T("_oreq");
  }else if(l_id==BB_T("~=")){
    return BB_T("_xoreq");
  }else if(l_id==BB_T("[]=")){
    return BB_T("_idxeq");
  }else if(l_id==BB_T("<")){
    return BB_T("_lt");
  }else if(l_id==BB_T("<=")){
    return BB_T("_le");
  }else if(l_id==BB_T(">")){
    return BB_T("_gt");
  }else if(l_id==BB_T(">=")){
    return BB_T("_ge");
  }else if(l_id==BB_T("=")){
    return BB_T("_eq");
  }else if(l_id==BB_T("<>")){
    return BB_T("_ne");
  }else if(l_id==BB_T("<=>")){
    return BB_T("_cmp");
  }
  return BB_T("????? OpSym ?????");
}

void mx2_mx2cc_mung_init(){
  static bool done;
  if(done) return;
  done=true;
}

bbInit mx2_mx2cc_mung_init_v("mx2cc_mung",&mx2_mx2cc_mung_init);
