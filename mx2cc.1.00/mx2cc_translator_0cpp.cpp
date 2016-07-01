
#include "mx2cc_translator_0cpp.h"

// ***** External *****

#include "../../../../../modules/monkey/monkey.buildv1.0.0/desktop_release_linux/monkey_types.h"
#include "mx2cc_builder.h"
#include "mx2cc_class.h"
#include "mx2cc_decl.h"
#include "mx2cc_enum.h"
#include "mx2cc_errors.h"
#include "mx2cc_func.h"
#include "mx2cc_module.h"
#include "mx2cc_node.h"
#include "mx2cc_scope.h"
#include "mx2cc_std_collections_2map.h"
#include "mx2cc_std_collections_2stack.h"
#include "mx2cc_stmt.h"
#include "mx2cc_type.h"
#include "mx2cc_value.h"
#include "mx2cc_var.h"
#include "../../../../../modules/std/std.buildv1.0.0/desktop_release_linux/std_collections_2stack.h"

extern bbString g_mx2_VarName(t_mx2_VarValue* l_vvar);
extern bbString g_std_filesystem_ExtractDir(bbString l_path);
extern bbString g_mx2_MakeRelativePath(bbString l_path,bbString l_baseDir);
extern bbString g_mx2_ClassName(t_mx2_ClassType* l_ctype);
extern void g_mx2_CSaveString(bbString l_str,bbString l_path);
extern bbString g_mx2_EnumName(t_mx2_EnumType* l_etype);
extern bbString g_mx2_FuncName(t_mx2_FuncValue* l_func);
extern bbString g_mx2_EnquoteCppString(bbString l_str);
extern bbString g_mx2_EnumValueName(t_mx2_EnumType* l_etype,bbString l_value);

// ***** Internal *****

bbString t_mx2_Translator_0CPP::m_VarType(t_mx2_VarValue* l_vvar){
  struct f0_t : public bbGCFrame{
    t_mx2_Type* l_type{};
    void gcMark(){
      bbGCMarkPtr(l_type);
    }
  }f0{};
  f0.l_type=l_vvar->m_type;
  bbString l_name=this->m_GCVarTypeName(f0.l_type);
  if(!bbBool(l_name)){
    return this->m_TransType(f0.l_type);
  }
  if(l_vvar->m_vdecl->m_kind==BB_T("local")){
    return (l_name+BB_T("*"));
  }else if(l_vvar->m_vdecl->m_kind==BB_T("field")){
    return ((BB_T("bbGCVar<")+l_name)+BB_T(">"));
  }else if(l_vvar->m_vdecl->m_kind==BB_T("global")||l_vvar->m_vdecl->m_kind==BB_T("const")){
    return ((BB_T("bbGCRootVar<")+l_name)+BB_T(">"));
  }
  g_mx2_TransError(BB_T("Translator.VarType (2)"));
  return bbString{};
}

bbString t_mx2_Translator_0CPP::m_VarProto(t_mx2_VarValue* l_vvar){
  return ((this->m_VarType(l_vvar)+BB_T(" "))+g_mx2_VarName(l_vvar));
}

void t_mx2_Translator_0CPP::m_Translate(t_mx2_FileDecl* l_fdecl){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1sz* l_emitted{};
    void gcMark(){
      bbGCMarkPtr(l_emitted);
    }
  }f0{};
  this->m__0incs->m__idxeq(l_fdecl->m_ident,l_fdecl);
  this->m__0buf->m_Clear();
  this->m_EmitBr();
  this->m_Emit(((BB_T("#ifndef MX2_")+l_fdecl->m_ident.toUpper())+BB_T("_H")));
  this->m_Emit(((BB_T("#define MX2_")+l_fdecl->m_ident.toUpper())+BB_T("_H")));
  this->m_EmitBr();
  this->m_Emit(BB_T("#include <bbmonkey.h>"));
  if(bbBool(l_fdecl->m_exhfile)){
    this->m_Emit(((BB_T("#include \"")+g_mx2_MakeRelativePath(l_fdecl->m_exhfile,g_std_filesystem_ExtractDir(l_fdecl->m_hfile)))+BB_T("\"")));
  }
  {
    bbInt l_0=bbInt(0);
    bbInt l_1=l_fdecl->m_imports->length();
    for(;(l_0<l_1);l_0+=1){
      bbString l_ipath=l_fdecl->m_imports->at(l_0);
      if(l_ipath.contains(BB_T("*."))){
        continue;
      }
      bbString l_imp=l_ipath.toLower();
      if(((l_imp.endsWith(BB_T(".h"))||l_imp.endsWith(BB_T(".hh")))||l_imp.endsWith(BB_T(".hpp")))){
        bbString l_path=(g_std_filesystem_ExtractDir(l_fdecl->m_path)+l_ipath);
        this->m_Emit(((BB_T("#include \"")+g_mx2_MakeRelativePath(l_path,g_std_filesystem_ExtractDir(l_fdecl->m_hfile)))+BB_T("\"")));
        continue;
      }
      if(((l_imp.endsWith(BB_T(".h>"))||l_imp.endsWith(BB_T(".hh>")))||l_imp.endsWith(BB_T(".hpp>")))){
        this->m_Emit((BB_T("#include ")+l_ipath));
        continue;
      }
    }
  }
  this->m_BeginDeps();
  this->m_Emit(BB_T("// ***** Internal *****"));
  this->m_EmitBr();
  {
    struct f1_t : public bbGCFrame{
      t_std_collections_Stack_1Tt_mx2_ClassType_2_Iterator l_2{};
      void gcMark(){
        bbGCMark(l_2);
      }
    }f1{};
    f1.l_2=l_fdecl->m_classes->m_All();
    for(;!f1.l_2.m_AtEnd();f1.l_2.m_Bump()){
      struct f2_t : public bbGCFrame{
        t_mx2_ClassType* l_ctype{};
        void gcMark(){
          bbGCMarkPtr(l_ctype);
        }
      }f2{};
      f2.l_ctype=f1.l_2.m_Current();
      this->m_Emit(((BB_T("struct ")+g_mx2_ClassName(f2.l_ctype))+BB_T(";")));
    }
  }
  this->m_EmitBr();
  {
    struct f1_t : public bbGCFrame{
      t_std_collections_Stack_1Tt_mx2_VarValue_2_Iterator l_3{};
      void gcMark(){
        bbGCMark(l_3);
      }
    }f1{};
    f1.l_3=l_fdecl->m_globals->m_All();
    for(;!f1.l_3.m_AtEnd();f1.l_3.m_Bump()){
      struct f2_t : public bbGCFrame{
        t_mx2_VarValue* l_vvar{};
        void gcMark(){
          bbGCMarkPtr(l_vvar);
        }
      }f2{};
      f2.l_vvar=f1.l_3.m_Current();
      this->m_Refs(f2.l_vvar->m_type);
      this->m_Emit(((BB_T("extern ")+this->m_VarProto(f2.l_vvar))+BB_T(";")));
    }
  }
  this->m_EmitBr();
  {
    struct f1_t : public bbGCFrame{
      t_std_collections_Stack_1Tt_mx2_FuncValue_2_Iterator l_4{};
      void gcMark(){
        bbGCMark(l_4);
      }
    }f1{};
    f1.l_4=l_fdecl->m_functions->m_All();
    for(;!f1.l_4.m_AtEnd();f1.l_4.m_Bump()){
      struct f2_t : public bbGCFrame{
        t_mx2_FuncValue* l_func{};
        void gcMark(){
          bbGCMarkPtr(l_func);
        }
      }f2{};
      f2.l_func=f1.l_4.m_Current();
      this->m_Refs(((t_mx2_Type*)(f2.l_func->m_ftype)));
      this->m_Emit(((BB_T("extern ")+this->m_FuncProto(f2.l_func,true))+BB_T(";")));
    }
  }
  f0.l_emitted=bbGCNew<t_std_collections_Map_1sz>();
  this->m_EmitBr();
  {
    struct f1_t : public bbGCFrame{
      t_std_collections_Stack_1Tt_mx2_ClassType_2_Iterator l_5{};
      void gcMark(){
        bbGCMark(l_5);
      }
    }f1{};
    f1.l_5=l_fdecl->m_classes->m_All();
    for(;!f1.l_5.m_AtEnd();f1.l_5.m_Bump()){
      struct f2_t : public bbGCFrame{
        t_mx2_ClassType* l_ctype{};
        void gcMark(){
          bbGCMarkPtr(l_ctype);
        }
      }f2{};
      f2.l_ctype=f1.l_5.m_Current();
      if(f0.l_emitted->m__idx(g_mx2_ClassName(f2.l_ctype))){
        continue;
      }
      this->m_EmitClassProto(f2.l_ctype,l_fdecl,f0.l_emitted);
    }
  }
  this->m_EndDeps(g_std_filesystem_ExtractDir(l_fdecl->m_hfile));
  this->m_EmitBr();
  this->m_Emit(BB_T("#endif"));
  this->m_EmitBr();
  g_mx2_CSaveString(this->m__0buf->m_Join(BB_T("\n")),l_fdecl->m_hfile);
  this->m__0buf->m_Clear();
  this->m_EmitBr();
  this->m_Emit(((BB_T("#include \"")+g_mx2_MakeRelativePath(l_fdecl->m_hfile,g_std_filesystem_ExtractDir(l_fdecl->m_cfile)))+BB_T("\"")));
  this->m_EmitBr();
  this->m_BeginDeps();
  this->m_Emit(BB_T("// ***** Internal *****"));
  this->m_EmitBr();
  {
    struct f1_t : public bbGCFrame{
      t_std_collections_Stack_1Tt_mx2_VarValue_2_Iterator l_6{};
      void gcMark(){
        bbGCMark(l_6);
      }
    }f1{};
    f1.l_6=l_fdecl->m_globals->m_All();
    for(;!f1.l_6.m_AtEnd();f1.l_6.m_Bump()){
      struct f2_t : public bbGCFrame{
        t_mx2_VarValue* l_vvar{};
        void gcMark(){
          bbGCMarkPtr(l_vvar);
        }
      }f2{};
      f2.l_vvar=f1.l_6.m_Current();
      this->m_Uses(f2.l_vvar->m_type);
      bbString l_proto=this->m_VarProto(f2.l_vvar);
      this->m_Emit((l_proto+BB_T(";")));
    }
  }
  {
    struct f1_t : public bbGCFrame{
      t_std_collections_Stack_1Tt_mx2_FuncValue_2_Iterator l_7{};
      void gcMark(){
        bbGCMark(l_7);
      }
    }f1{};
    f1.l_7=l_fdecl->m_functions->m_All();
    for(;!f1.l_7.m_AtEnd();f1.l_7.m_Bump()){
      struct f2_t : public bbGCFrame{
        t_mx2_FuncValue* l_func{};
        void gcMark(){
          bbGCMarkPtr(l_func);
        }
      }f2{};
      f2.l_func=f1.l_7.m_Current();
      this->m_EmitFunc(f2.l_func,false);
    }
  }
  {
    struct f1_t : public bbGCFrame{
      t_std_collections_Stack_1Tt_mx2_ClassType_2_Iterator l_8{};
      void gcMark(){
        bbGCMark(l_8);
      }
    }f1{};
    f1.l_8=l_fdecl->m_classes->m_All();
    for(;!f1.l_8.m_AtEnd();f1.l_8.m_Bump()){
      struct f2_t : public bbGCFrame{
        t_mx2_ClassType* l_ctype{};
        void gcMark(){
          bbGCMarkPtr(l_ctype);
        }
      }f2{};
      f2.l_ctype=f1.l_8.m_Current();
      this->m_EmitClassMembers(f2.l_ctype);
    }
  }
  this->m_EmitGlobalInits(l_fdecl);
  this->m_EndDeps(g_std_filesystem_ExtractDir(l_fdecl->m_cfile));
  this->m_EmitBr();
  g_mx2_CSaveString(this->m__0buf->m_Join(BB_T("\n")),l_fdecl->m_cfile);
}

bbString t_mx2_Translator_0CPP::m_TransType(t_mx2_GenArgType* l_type){
  return l_type->m_ToString();
}

bbString t_mx2_Translator_0CPP::m_TransType(t_mx2_PointerType* l_type){
  return (this->m_TransType(l_type->m_elemType)+BB_T("*"));
}

bbString t_mx2_Translator_0CPP::m_TransType(t_mx2_ArrayType* l_type){
  return (this->m_ArrayName(l_type)+BB_T("*"));
}

bbString t_mx2_Translator_0CPP::m_TransType(t_mx2_FuncType* l_type){
  return ((BB_T("bbFunction<")+this->m_CFuncType(l_type))+BB_T(">"));
}

bbString t_mx2_Translator_0CPP::m_TransType(t_mx2_PrimType* l_type){
  return l_type->m_ctype->m_cdecl->m_symbol;
}

bbString t_mx2_Translator_0CPP::m_TransType(t_mx2_EnumType* l_type){
  return g_mx2_EnumName(l_type);
}

bbString t_mx2_Translator_0CPP::m_TransType(t_mx2_ClassType* l_type){
  if(this->m_IsStruct(((t_mx2_Type*)(l_type)))){
    return g_mx2_ClassName(l_type);
  }
  return (g_mx2_ClassName(l_type)+BB_T("*"));
}

bbString t_mx2_Translator_0CPP::m_TransType(t_mx2_Type* l_type){
  struct f0_t : public bbGCFrame{
    t_mx2_ArrayType* l_arrayType{};
    t_mx2_ClassType* l_classType{};
    t_mx2_EnumType* l_enumType{};
    t_mx2_FuncType* l_funcType{};
    t_mx2_GenArgType* l_genArgType{};
    t_mx2_PointerType* l_pointerType{};
    t_mx2_PrimType* l_primType{};
    void gcMark(){
      bbGCMarkPtr(l_arrayType);
      bbGCMarkPtr(l_classType);
      bbGCMarkPtr(l_enumType);
      bbGCMarkPtr(l_funcType);
      bbGCMarkPtr(l_genArgType);
      bbGCMarkPtr(l_pointerType);
      bbGCMarkPtr(l_primType);
    }
  }f0{};
  if(bbBool(g_mx2_TCast_1Tt_mx2_VoidType_2(l_type))){
    return BB_T("void");
  }
  f0.l_classType=g_mx2_TCast_1Tt_mx2_ClassType_2(l_type);
  if(bbBool(f0.l_classType)){
    return this->m_TransType(f0.l_classType);
  }
  f0.l_enumType=g_mx2_TCast_1Tt_mx2_EnumType_2(l_type);
  if(bbBool(f0.l_enumType)){
    return this->m_TransType(f0.l_enumType);
  }
  f0.l_primType=g_mx2_TCast_1Tt_mx2_PrimType_2(l_type);
  if(bbBool(f0.l_primType)){
    return this->m_TransType(f0.l_primType);
  }
  f0.l_funcType=g_mx2_TCast_1Tt_mx2_FuncType_2(l_type);
  if(bbBool(f0.l_funcType)){
    return this->m_TransType(f0.l_funcType);
  }
  f0.l_arrayType=g_mx2_TCast_1Tt_mx2_ArrayType_2(l_type);
  if(bbBool(f0.l_arrayType)){
    return this->m_TransType(f0.l_arrayType);
  }
  f0.l_pointerType=g_mx2_TCast_1Tt_mx2_PointerType_2(l_type);
  if(bbBool(f0.l_pointerType)){
    return this->m_TransType(f0.l_pointerType);
  }
  f0.l_genArgType=g_mx2_TCast_1Tt_mx2_GenArgType_2(l_type);
  if(bbBool(f0.l_genArgType)){
    return this->m_TransType(f0.l_genArgType);
  }
  throw bbGCNew<t_mx2_TransEx>(((BB_T("Translator_CPP.Trans() Type '")+bbString::fromCString(l_type->typeName()))+BB_T("' not recognized")));
}

bbString t_mx2_Translator_0CPP::m_TransNull(t_mx2_Type* l_type){
  struct f0_t : public bbGCFrame{
    t_mx2_EnumType* l_etype{};
    t_mx2_PrimType* l_ptype{};
    void gcMark(){
      bbGCMarkPtr(l_etype);
      bbGCMarkPtr(l_ptype);
    }
  }f0{};
  f0.l_ptype=g_mx2_TCast_1Tt_mx2_PrimType_2(l_type);
  if(bbBool(f0.l_ptype)){
    if(f0.l_ptype->m_IsIntegral()){
      return BB_T("0");
    }
    if(f0.l_ptype->m__eq(((t_mx2_Type*)(g_mx2_Type_FloatType)))){
      return BB_T(".0f");
    }
    if(f0.l_ptype->m__eq(((t_mx2_Type*)(g_mx2_Type_DoubleType)))){
      return BB_T("0.0f");
    }
    if(f0.l_ptype->m__eq(((t_mx2_Type*)(g_mx2_Type_BoolType)))){
      return BB_T("false");
    }
  }
  f0.l_etype=g_mx2_TCast_1Tt_mx2_EnumType_2(l_type);
  if(bbBool(f0.l_etype)){
    return (g_mx2_EnumName(f0.l_etype)+BB_T("(0)"));
  }
  if(this->m_IsValue(l_type)){
    return (this->m_TransType(l_type)+BB_T("{}"));
  }
  return ((BB_T("((")+this->m_TransType(l_type))+BB_T(")0)"));
}

bbString t_mx2_Translator_0CPP::m_TransMember(t_mx2_Value* l_instance,t_mx2_Value* l_member){
  struct f0_t : public bbGCFrame{
    t_mx2_ClassType* l_ctype{};
    t_mx2_SuperValue* l_supr{};
    void gcMark(){
      bbGCMarkPtr(l_ctype);
      bbGCMarkPtr(l_supr);
    }
  }f0{};
  f0.l_ctype=g_mx2_TCast_1Tt_mx2_ClassType_2(l_instance->m_type);
  if(bbBool(f0.l_ctype)){
    this->m_Uses(f0.l_ctype);
  }
  f0.l_supr=bb_object_cast<t_mx2_SuperValue*>(l_instance);
  if(bbBool(f0.l_supr)){
    struct f1_t : public bbGCFrame{
      t_mx2_ClassType* t0{};
      void gcMark(){
        bbGCMarkPtr(t0);
      }
    }f1{};
    return ((g_mx2_ClassName(f1.t0=g_mx2_TCast_1Tt_mx2_ClassType_2(f0.l_supr->m_type))+BB_T("::"))+this->m_Trans(l_member));
  }
  bbString l_tinst=this->m_Trans(l_instance);
  bbString l_tmember=this->m_Trans(l_member);
  if(this->m_IsValue(l_instance->m_type)){
    return ((l_tinst+BB_T("."))+l_tmember);
  }
  if((bbBool(bb_object_cast<t_mx2_FuncValue*>(l_member))&&this->m_IsVolatile(l_instance))){
    l_tinst=((((BB_T("(")+this->m_AllocGCTmp(l_instance->m_type))+BB_T("="))+l_tinst)+BB_T(")"));
  }
  return ((l_tinst+BB_T("->"))+l_tmember);
}

bbString t_mx2_Translator_0CPP::m_TransArgs(bbArray<bbGCVar<t_mx2_Value>>* l_args){
  bbString l_targs=bbString{};
  {
    bbInt l_0=bbInt(0);
    bbInt l_1=l_args->length();
    for(;(l_0<l_1);l_0+=1){
      struct f2_t : public bbGCFrame{
        t_mx2_Value* l_arg{};
        void gcMark(){
          bbGCMarkPtr(l_arg);
        }
      }f2{};
      f2.l_arg=l_args->at(l_0);
      bbString l_t=this->m_Trans(f2.l_arg);
      if(this->m_IsVolatile(f2.l_arg)){
        l_t=((this->m_AllocGCTmp(f2.l_arg->m_type)+BB_T("="))+l_t);
      }
      if(bbBool(l_targs)){
        l_targs+=BB_T(",");
      }
      l_targs+=l_t;
    }
  }
  return l_targs;
}

bbString t_mx2_Translator_0CPP::m_Trans(t_mx2_VarValue* l_value){
  struct f0_t : public bbGCFrame{
    t_mx2_VarDecl* l_vdecl{};
    void gcMark(){
      bbGCMarkPtr(l_vdecl);
    }
  }f0{};
  this->m_Refs(l_value);
  f0.l_vdecl=l_value->m_vdecl;
  if((((f0.l_vdecl->m_kind==BB_T("local"))||(f0.l_vdecl->m_kind==BB_T("param")))&&g_mx2_IsGCType(l_value->m_type))){
    return this->m_FindGCTmp(l_value);
  }
  return g_mx2_VarName(l_value);
}

bbString t_mx2_Translator_0CPP::m_Trans(t_mx2_FuncValue* l_value){
  if((l_value->m_fdecl->m_kind==BB_T("lambda"))){
    this->m_Refs(((t_mx2_Type*)(l_value->m_ftype)));
    return this->m_EmitLambda(l_value);
  }
  this->m_Refs(l_value);
  return g_mx2_FuncName(l_value);
}

bbString t_mx2_Translator_0CPP::m_Trans(t_mx2_PointerValue* l_value){
  return (BB_T("&")+this->m_Trans(l_value->m_value));
}

bbString t_mx2_Translator_0CPP::m_Trans(t_mx2_IfThenElseValue* l_value){
  return ((((((BB_T("(")+this->m_Trans(l_value->m_value))+BB_T(" ? "))+this->m_Trans(l_value->m_thenValue))+BB_T(" : "))+this->m_Trans(l_value->m_elseValue))+BB_T(")"));
}

bbString t_mx2_Translator_0CPP::m_Trans(t_mx2_BinaryopValue* l_value){
  struct f0_t : public bbGCFrame{
    t_mx2_EnumType* l_etype{};
    void gcMark(){
      bbGCMarkPtr(l_etype);
    }
  }f0{};
  bbString l_op=l_value->m_op;
  if(l_op==BB_T("<=>")){
    return ((((BB_T("bbCompare(")+this->m_Trans(l_value->m_lhs))+BB_T(","))+this->m_Trans(l_value->m_rhs))+BB_T(")"));
  }else if(l_op==BB_T("=")||l_op==BB_T("<>")||l_op==BB_T("<")||l_op==BB_T(">")||l_op==BB_T("<=")||l_op==BB_T(">=")){
    if((l_op==BB_T("="))){
      l_op=BB_T("==");
    }else if((l_op==BB_T("<>"))){
      l_op=BB_T("!=");
    }
    if((this->m_IsStruct(l_value->m_lhs->m_type)||((bbBool(g_mx2_TCast_1Tt_mx2_FuncType_2(l_value->m_lhs->m_type))&&(l_op!=BB_T("==")))&&(l_op!=BB_T("!="))))){
      return ((((((BB_T("(bbCompare(")+this->m_Trans(l_value->m_lhs))+BB_T(","))+this->m_Trans(l_value->m_rhs))+BB_T(")"))+l_op)+BB_T("0)"));
    }
  }else if(l_op==BB_T("mod")){
    struct f1_t : public bbGCFrame{
      t_mx2_PrimType* l_ptype{};
      void gcMark(){
        bbGCMarkPtr(l_ptype);
      }
    }f1{};
    f1.l_ptype=g_mx2_TCast_1Tt_mx2_PrimType_2(l_value->m_type);
    if((f1.l_ptype->m__eq(((t_mx2_Type*)(g_mx2_Type_FloatType)))||f1.l_ptype->m__eq(((t_mx2_Type*)(g_mx2_Type_DoubleType))))){
      return ((((BB_T("std::fmod(")+this->m_Trans(l_value->m_lhs))+BB_T(","))+this->m_Trans(l_value->m_rhs))+BB_T(")"));
    }
    l_op=BB_T("%");
  }else if(l_op==BB_T("and")){
    l_op=BB_T("&&");
  }else if(l_op==BB_T("or")){
    l_op=BB_T("||");
  }else if(l_op==BB_T("~")){
    l_op=BB_T("^");
  }else if(l_op==BB_T("shl")){
    l_op=BB_T("<<");
  }else if(l_op==BB_T("shr")){
    l_op=BB_T(">>");
  }
  bbString l_t=((((BB_T("(")+this->m_Trans(l_value->m_lhs))+l_op)+this->m_Trans(l_value->m_rhs))+BB_T(")"));
  f0.l_etype=g_mx2_TCast_1Tt_mx2_EnumType_2(l_value->m_type);
  if((bbBool(f0.l_etype)&&f0.l_etype->m_edecl->m_IsExtern())){
    l_t=(g_mx2_EnumName(f0.l_etype)+l_t);
  }
  return l_t;
}

bbString t_mx2_Translator_0CPP::m_Trans(t_mx2_UnaryopValue* l_value){
  struct f0_t : public bbGCFrame{
    t_mx2_EnumType* l_etype{};
    void gcMark(){
      bbGCMarkPtr(l_etype);
    }
  }f0{};
  bbString l_op=l_value->m_op;
  if(l_op==BB_T("not")){
    l_op=BB_T("!");
  }
  bbString l_t=(l_op+this->m_Trans(l_value->m_value));
  f0.l_etype=g_mx2_TCast_1Tt_mx2_EnumType_2(l_value->m_type);
  if((bbBool(f0.l_etype)&&f0.l_etype->m_edecl->m_IsExtern())){
    l_t=(((g_mx2_EnumName(f0.l_etype)+BB_T("("))+l_t)+BB_T(")"));
  }
  return l_t;
}

bbString t_mx2_Translator_0CPP::m_Trans(t_mx2_PointerIndexValue* l_value){
  return (((this->m_Trans(l_value->m_value)+BB_T("["))+this->m_Trans(l_value->m_index))+BB_T("]"));
}

bbString t_mx2_Translator_0CPP::m_Trans(t_mx2_StringIndexValue* l_value){
  return (((this->m_Trans(l_value->m_value)+BB_T("["))+this->m_Trans(l_value->m_index))+BB_T("]"));
}

bbString t_mx2_Translator_0CPP::m_Trans(t_mx2_ArrayIndexValue* l_value){
  return (((this->m_Trans(l_value->m_value)+BB_T("->at("))+this->m_TransArgs(l_value->m_args))+BB_T(")"));
}

bbString t_mx2_Translator_0CPP::m_Trans(t_mx2_NewArrayValue* l_value){
  struct f0_t : public bbGCFrame{
    t_mx2_ArrayType* l_atype{};
    void gcMark(){
      bbGCMarkPtr(l_atype);
    }
  }f0{};
  f0.l_atype=l_value->m_atype;
  this->m_Uses(((t_mx2_Type*)(f0.l_atype)));
  if(bbBool(l_value->m_inits)){
    return (((((this->m_ArrayName(f0.l_atype)+BB_T("::create({"))+this->m_TransArgs(l_value->m_inits))+BB_T("},"))+bbString(l_value->m_inits->length()))+BB_T(")"));
  }
  return (((this->m_ArrayName(f0.l_atype)+BB_T("::create("))+this->m_TransArgs(l_value->m_sizes))+BB_T(")"));
}

bbString t_mx2_Translator_0CPP::m_Trans(t_mx2_NewObjectValue* l_value){
  struct f0_t : public bbGCFrame{
    t_mx2_ClassType* l_ctype{};
    void gcMark(){
      bbGCMarkPtr(l_ctype);
    }
  }f0{};
  f0.l_ctype=l_value->m_ctype;
  this->m_Uses(f0.l_ctype);
  if(f0.l_ctype->m_IsVoid()){
    return ((((BB_T("new ")+g_mx2_ClassName(f0.l_ctype))+BB_T("("))+this->m_TransArgs(l_value->m_args))+BB_T(")"));
  }
  if(this->m_IsStruct(((t_mx2_Type*)(f0.l_ctype)))){
    if(!bbBool(l_value->m_args)){
      return (g_mx2_ClassName(f0.l_ctype)+BB_T("(bbNullCtor)"));
    }
    if(l_value->m_args->at(bbInt(0))->m_type->m_Equals(((t_mx2_Type*)(f0.l_ctype)))){
      return (((g_mx2_ClassName(f0.l_ctype)+BB_T("("))+this->m_TransArgs(l_value->m_args))+BB_T(",bbNullCtor)"));
    }
    return (((g_mx2_ClassName(f0.l_ctype)+BB_T("("))+this->m_TransArgs(l_value->m_args))+BB_T(")"));
  }
  return ((((BB_T("bbGCNew<")+g_mx2_ClassName(f0.l_ctype))+BB_T(">("))+this->m_TransArgs(l_value->m_args))+BB_T(")"));
}

bbString t_mx2_Translator_0CPP::m_Trans(t_mx2_MemberFuncValue* l_value){
  struct f0_t : public bbGCFrame{
    t_mx2_ClassType* l_ctype{};
    void gcMark(){
      bbGCMarkPtr(l_ctype);
    }
  }f0{};
  f0.l_ctype=l_value->m_member->m_scope->m_FindClass();
  this->m_Uses(f0.l_ctype);
  bbString l_cname=g_mx2_ClassName(f0.l_ctype);
  return ((((((((BB_T("bbMethod((")+l_cname)+BB_T("*)("))+this->m_Trans(l_value->m_instance))+BB_T("),&"))+l_cname)+BB_T("::"))+this->m_Trans(l_value->m_member))+BB_T(")"));
}

bbString t_mx2_Translator_0CPP::m_Trans(t_mx2_MemberVarValue* l_value){
  return this->m_TransMember(l_value->m_instance,((t_mx2_Value*)(l_value->m_member)));
}

bbString t_mx2_Translator_0CPP::m_Trans(t_mx2_InvokeValue* l_value){
  struct f0_t : public bbGCFrame{
    t_mx2_MemberFuncValue* l_mfunc{};
    void gcMark(){
      bbGCMarkPtr(l_mfunc);
    }
  }f0{};
  f0.l_mfunc=bb_object_cast<t_mx2_MemberFuncValue*>(l_value->m_value);
  if(bbBool(f0.l_mfunc)){
    struct f1_t : public bbGCFrame{
      t_mx2_Value* l_instance{};
      t_mx2_FuncValue* l_member{};
      void gcMark(){
        bbGCMarkPtr(l_instance);
        bbGCMarkPtr(l_member);
      }
    }f1{};
    f1.l_instance=f0.l_mfunc->m_instance;
    f1.l_member=f0.l_mfunc->m_member;
    if(f1.l_member->m_IsExtension()){
      this->m_Refs(f1.l_member);
      bbString l_tinst=this->m_Trans(f1.l_instance);
      if(this->m_IsVolatile(f1.l_instance)){
        l_tinst=((((BB_T("(")+this->m_AllocGCTmp(f1.l_instance->m_type))+BB_T("="))+l_tinst)+BB_T(")"));
      }
      if(bbBool(l_value->m_args)){
        l_tinst+=BB_T(",");
      }
      return ((((this->m_Trans(f1.l_member)+BB_T("("))+l_tinst)+this->m_TransArgs(l_value->m_args))+BB_T(")"));
    }
    return (((this->m_TransMember(f1.l_instance,((t_mx2_Value*)(f1.l_member)))+BB_T("("))+this->m_TransArgs(l_value->m_args))+BB_T(")"));
  }
  return (((this->m_Trans(l_value->m_value)+BB_T("("))+this->m_TransArgs(l_value->m_args))+BB_T(")"));
}

bbString t_mx2_Translator_0CPP::m_Trans(t_mx2_SuperValue* l_value){
  bbString l_type=g_mx2_ClassName(l_value->m_ctype);
  if(this->m_IsStruct(((t_mx2_Type*)(l_value->m_ctype)))){
    return ((BB_T("(*static_cast<")+l_type)+BB_T("*>(this))"));
  }
  return ((BB_T("static_cast<")+l_type)+BB_T("*>(this)"));
}

bbString t_mx2_Translator_0CPP::m_Trans(t_mx2_SelfValue* l_value){
  if(this->m_IsStruct(((t_mx2_Type*)(l_value->m_ctype)))){
    return BB_T("(*this)");
  }
  return BB_T("this");
}

bbString t_mx2_Translator_0CPP::m_Trans(t_mx2_LiteralValue* l_value){
  struct f0_t : public bbGCFrame{
    t_mx2_EnumType* l_etype{};
    t_mx2_PrimType* l_ptype{};
    void gcMark(){
      bbGCMarkPtr(l_etype);
      bbGCMarkPtr(l_ptype);
    }
  }f0{};
  if(!bbBool(l_value->m_value)){
    return this->m_TransNull(l_value->m_type);
  }
  f0.l_ptype=g_mx2_TCast_1Tt_mx2_PrimType_2(l_value->m_type);
  if(f0.l_ptype==g_mx2_Type_FloatType||f0.l_ptype==g_mx2_Type_DoubleType){
    bbString l_t=l_value->m_value;
    if((((l_t.find(BB_T("."),bbInt(0))==-1)&&(l_t.find(BB_T("e"),bbInt(0))==-1))&&(l_t.find(BB_T("E"),bbInt(0))==-1))){
      l_t+=BB_T(".0");
    }
    if(f0.l_ptype->m__eq(((t_mx2_Type*)(g_mx2_Type_FloatType)))){
      return (l_t+BB_T("f"));
    }
    return l_t;
  }else if(f0.l_ptype==g_mx2_Type_StringType){
    return ((BB_T("BB_T(")+g_mx2_EnquoteCppString(l_value->m_value))+BB_T(")"));
  }
  f0.l_etype=g_mx2_TCast_1Tt_mx2_EnumType_2(l_value->m_type);
  if(bbBool(f0.l_etype)){
    return g_mx2_EnumValueName(f0.l_etype,l_value->m_value);
  }
  if((l_value->m_value==BB_T("0"))){
    return (this->m_TransType(l_value->m_type)+BB_T("(0)"));
  }
  return l_value->m_value;
}

bbString t_mx2_Translator_0CPP::m_Trans(t_mx2_ExplicitCastValue* l_value){
  struct f0_t : public bbGCFrame{
    t_mx2_ClassType* l_ctype{};
    void gcMark(){
      bbGCMarkPtr(l_ctype);
    }
  }f0{};
  f0.l_ctype=g_mx2_TCast_1Tt_mx2_ClassType_2(l_value->m_type);
  if(bbBool(f0.l_ctype)){
    this->m_Uses(f0.l_ctype);
    return ((((BB_T("bb_object_cast<")+g_mx2_ClassName(f0.l_ctype))+BB_T("*>("))+this->m_Trans(l_value->m_value))+BB_T(")"));
  }
  bbString l_t=((BB_T("(")+this->m_Trans(l_value->m_value))+BB_T(")"));
  if(this->m_IsValue(l_value->m_type)){
    return (this->m_TransType(l_value->m_type)+l_t);
  }
  return ((((BB_T("((")+this->m_TransType(l_value->m_type))+BB_T(")"))+l_t)+BB_T(")"));
}

bbString t_mx2_Translator_0CPP::m_Trans(t_mx2_UpCastValue* l_value){
  struct f0_t : public bbGCFrame{
    t_mx2_ClassType* l_ctype{};
    void gcMark(){
      bbGCMarkPtr(l_ctype);
    }
  }f0{};
  f0.l_ctype=g_mx2_TCast_1Tt_mx2_ClassType_2(l_value->m_value->m_type);
  if(bbBool(f0.l_ctype)){
    this->m_Uses(f0.l_ctype);
  }
  bbString l_t=((BB_T("(")+this->m_Trans(l_value->m_value))+BB_T(")"));
  if(this->m_IsValue(l_value->m_type)){
    return (this->m_TransType(l_value->m_type)+l_t);
  }
  return ((((BB_T("((")+this->m_TransType(l_value->m_type))+BB_T(")"))+l_t)+BB_T(")"));
}

bbString t_mx2_Translator_0CPP::m_Trans(t_mx2_Value* l_value){
  struct f0_t : public bbGCFrame{
    t_mx2_ArrayIndexValue* l_arrayIndexValue{};
    t_mx2_BinaryopValue* l_binaryopValue{};
    t_mx2_ExplicitCastValue* l_explicitCastValue{};
    t_mx2_FuncValue* l_funcValue{};
    t_mx2_IfThenElseValue* l_ifThenElseValue{};
    t_mx2_InvokeValue* l_invokeValue{};
    t_mx2_LiteralValue* l_literalValue{};
    t_mx2_MemberFuncValue* l_memberFuncValue{};
    t_mx2_MemberVarValue* l_memberVarValue{};
    t_mx2_NewArrayValue* l_newArrayValue{};
    t_mx2_NewObjectValue* l_newObjectValue{};
    t_mx2_PointerIndexValue* l_pointerIndexValue{};
    t_mx2_PointerValue* l_pointerValue{};
    t_mx2_SelfValue* l_selfValue{};
    t_mx2_StringIndexValue* l_stringIndexValue{};
    t_mx2_SuperValue* l_superValue{};
    t_mx2_UnaryopValue* l_unaryopValue{};
    t_mx2_UpCastValue* l_upCastValue{};
    t_mx2_VarValue* l_varValue{};
    void gcMark(){
      bbGCMarkPtr(l_arrayIndexValue);
      bbGCMarkPtr(l_binaryopValue);
      bbGCMarkPtr(l_explicitCastValue);
      bbGCMarkPtr(l_funcValue);
      bbGCMarkPtr(l_ifThenElseValue);
      bbGCMarkPtr(l_invokeValue);
      bbGCMarkPtr(l_literalValue);
      bbGCMarkPtr(l_memberFuncValue);
      bbGCMarkPtr(l_memberVarValue);
      bbGCMarkPtr(l_newArrayValue);
      bbGCMarkPtr(l_newObjectValue);
      bbGCMarkPtr(l_pointerIndexValue);
      bbGCMarkPtr(l_pointerValue);
      bbGCMarkPtr(l_selfValue);
      bbGCMarkPtr(l_stringIndexValue);
      bbGCMarkPtr(l_superValue);
      bbGCMarkPtr(l_unaryopValue);
      bbGCMarkPtr(l_upCastValue);
      bbGCMarkPtr(l_varValue);
    }
  }f0{};
  f0.l_upCastValue=bb_object_cast<t_mx2_UpCastValue*>(l_value);
  if(bbBool(f0.l_upCastValue)){
    return this->m_Trans(f0.l_upCastValue);
  }
  f0.l_explicitCastValue=bb_object_cast<t_mx2_ExplicitCastValue*>(l_value);
  if(bbBool(f0.l_explicitCastValue)){
    return this->m_Trans(f0.l_explicitCastValue);
  }
  f0.l_literalValue=bb_object_cast<t_mx2_LiteralValue*>(l_value);
  if(bbBool(f0.l_literalValue)){
    return this->m_Trans(f0.l_literalValue);
  }
  f0.l_selfValue=bb_object_cast<t_mx2_SelfValue*>(l_value);
  if(bbBool(f0.l_selfValue)){
    return this->m_Trans(f0.l_selfValue);
  }
  f0.l_superValue=bb_object_cast<t_mx2_SuperValue*>(l_value);
  if(bbBool(f0.l_superValue)){
    return this->m_Trans(f0.l_superValue);
  }
  f0.l_invokeValue=bb_object_cast<t_mx2_InvokeValue*>(l_value);
  if(bbBool(f0.l_invokeValue)){
    return this->m_Trans(f0.l_invokeValue);
  }
  f0.l_memberVarValue=bb_object_cast<t_mx2_MemberVarValue*>(l_value);
  if(bbBool(f0.l_memberVarValue)){
    return this->m_Trans(f0.l_memberVarValue);
  }
  f0.l_memberFuncValue=bb_object_cast<t_mx2_MemberFuncValue*>(l_value);
  if(bbBool(f0.l_memberFuncValue)){
    return this->m_Trans(f0.l_memberFuncValue);
  }
  f0.l_newObjectValue=bb_object_cast<t_mx2_NewObjectValue*>(l_value);
  if(bbBool(f0.l_newObjectValue)){
    return this->m_Trans(f0.l_newObjectValue);
  }
  f0.l_newArrayValue=bb_object_cast<t_mx2_NewArrayValue*>(l_value);
  if(bbBool(f0.l_newArrayValue)){
    return this->m_Trans(f0.l_newArrayValue);
  }
  f0.l_arrayIndexValue=bb_object_cast<t_mx2_ArrayIndexValue*>(l_value);
  if(bbBool(f0.l_arrayIndexValue)){
    return this->m_Trans(f0.l_arrayIndexValue);
  }
  f0.l_stringIndexValue=bb_object_cast<t_mx2_StringIndexValue*>(l_value);
  if(bbBool(f0.l_stringIndexValue)){
    return this->m_Trans(f0.l_stringIndexValue);
  }
  f0.l_pointerIndexValue=bb_object_cast<t_mx2_PointerIndexValue*>(l_value);
  if(bbBool(f0.l_pointerIndexValue)){
    return this->m_Trans(f0.l_pointerIndexValue);
  }
  f0.l_unaryopValue=bb_object_cast<t_mx2_UnaryopValue*>(l_value);
  if(bbBool(f0.l_unaryopValue)){
    return this->m_Trans(f0.l_unaryopValue);
  }
  f0.l_binaryopValue=bb_object_cast<t_mx2_BinaryopValue*>(l_value);
  if(bbBool(f0.l_binaryopValue)){
    return this->m_Trans(f0.l_binaryopValue);
  }
  f0.l_ifThenElseValue=bb_object_cast<t_mx2_IfThenElseValue*>(l_value);
  if(bbBool(f0.l_ifThenElseValue)){
    return this->m_Trans(f0.l_ifThenElseValue);
  }
  f0.l_pointerValue=bb_object_cast<t_mx2_PointerValue*>(l_value);
  if(bbBool(f0.l_pointerValue)){
    return this->m_Trans(f0.l_pointerValue);
  }
  f0.l_funcValue=bb_object_cast<t_mx2_FuncValue*>(l_value);
  if(bbBool(f0.l_funcValue)){
    return this->m_Trans(f0.l_funcValue);
  }
  f0.l_varValue=bb_object_cast<t_mx2_VarValue*>(l_value);
  if(bbBool(f0.l_varValue)){
    return this->m_Trans(f0.l_varValue);
  }
  return ((((BB_T("{* ")+l_value->m_ToString())+BB_T(" "))+bbString::fromCString(l_value->typeName()))+BB_T(" *}"));
}

bbBool t_mx2_Translator_0CPP::m_IsVolatile(t_mx2_Value* l_arg){
  return (g_mx2_IsGCType(l_arg->m_type)&&l_arg->m_HasSideEffects());
}

bbString t_mx2_Translator_0CPP::m_GCVarTypeName(t_mx2_Type* l_type){
  struct f0_t : public bbGCFrame{
    t_mx2_ArrayType* l_atype{};
    t_mx2_ClassType* l_ctype{};
    void gcMark(){
      bbGCMarkPtr(l_atype);
      bbGCMarkPtr(l_ctype);
    }
  }f0{};
  f0.l_ctype=g_mx2_TCast_1Tt_mx2_ClassType_2(l_type);
  if(((bbBool(f0.l_ctype)&&!f0.l_ctype->m_IsVoid())&&((f0.l_ctype->m_cdecl->m_kind==BB_T("class"))||(f0.l_ctype->m_cdecl->m_kind==BB_T("interface"))))){
    return g_mx2_ClassName(f0.l_ctype);
  }
  f0.l_atype=g_mx2_TCast_1Tt_mx2_ArrayType_2(l_type);
  if(bbBool(f0.l_atype)){
    return this->m_ArrayName(f0.l_atype);
  }
  return bbString{};
}

bbString t_mx2_Translator_0CPP::m_FuncProto(t_mx2_FuncValue* l_func,bbBool l_header){
  struct f0_t : public bbGCFrame{
    t_mx2_ClassType* l_ctype{};
    t_mx2_FuncDecl* l_fdecl{};
    t_mx2_FuncType* l_ftype{};
    void gcMark(){
      bbGCMarkPtr(l_ctype);
      bbGCMarkPtr(l_fdecl);
      bbGCMarkPtr(l_ftype);
    }
  }f0{};
  f0.l_fdecl=l_func->m_fdecl;
  f0.l_ftype=l_func->m_ftype;
  f0.l_ctype=l_func->m_scope->m_FindClass();
  bbString l_retType=bbString{};
  if(!l_func->m_IsCtor()){
    l_retType=(this->m_TransType(f0.l_ftype->m_retType)+BB_T(" "));
  }
  bbString l_params=bbString{};
  if(l_func->m_IsExtension()){
    l_params=(this->m_TransType(f0.l_ctype)+BB_T(" l_self"));
  }
  {
    bbInt l_0=bbInt(0);
    bbInt l_1=l_func->m_params->length();
    for(;(l_0<l_1);l_0+=1){
      struct f2_t : public bbGCFrame{
        t_mx2_VarValue* l_p{};
        void gcMark(){
          bbGCMarkPtr(l_p);
        }
      }f2{};
      f2.l_p=l_func->m_params->at(l_0);
      if(bbBool(l_params)){
        l_params+=BB_T(",");
      }
      l_params+=((this->m_TransType(f2.l_p->m_type)+BB_T(" "))+g_mx2_VarName(f2.l_p));
    }
  }
  if((l_func->m_IsCtor()&&f0.l_ctype->m_IsStruct())){
    if((!bbBool(f0.l_ftype->m_argTypes->length())||f0.l_ftype->m_argTypes->at(bbInt(0))->m_Equals(((t_mx2_Type*)(f0.l_ctype))))){
      if(bbBool(l_params)){
        l_params+=BB_T(",");
      }
      l_params+=BB_T("bbNullCtor_t");
    }
  }
  bbString l_ident=g_mx2_FuncName(l_func);
  if(((!l_header&&(f0.l_fdecl->m_kind==BB_T("method")))&&!l_func->m_IsExtension())){
    l_ident=((g_mx2_ClassName(f0.l_ctype)+BB_T("::"))+l_ident);
  }
  bbString l_proto=((((l_retType+l_ident)+BB_T("("))+l_params)+BB_T(")"));
  if(((l_header&&l_func->m_IsMethod())&&!l_func->m_IsExtension())){
    if(((f0.l_fdecl->m_IsAbstract()||f0.l_fdecl->m_IsVirtual())||f0.l_ctype->m_IsVirtual())){
      l_proto=(BB_T("virtual ")+l_proto);
      if(f0.l_fdecl->m_IsAbstract()){
        l_proto+=BB_T("=0");
      }
    }
  }
  return l_proto;
}

bbString t_mx2_Translator_0CPP::m_FuncProto(t_mx2_FuncValue* l_func){
  return this->m_FuncProto(l_func,true);
}

void t_mx2_Translator_0CPP::m_EndBlock(){
  this->m_EndGCFrame();
}

void t_mx2_Translator_0CPP::m_EmitStmts(t_mx2_Block* l_block){
  {
    struct f1_t : public bbGCFrame{
      t_std_collections_Stack_1Tt_mx2_Stmt_2_Iterator l_0{};
      void gcMark(){
        bbGCMark(l_0);
      }
    }f1{};
    f1.l_0=l_block->m_stmts->m_All();
    for(;!f1.l_0.m_AtEnd();f1.l_0.m_Bump()){
      struct f2_t : public bbGCFrame{
        t_mx2_Stmt* l_stmt{};
        void gcMark(){
          bbGCMarkPtr(l_stmt);
        }
      }f2{};
      f2.l_stmt=f1.l_0.m_Current();
      this->m_EmitStmt(f2.l_stmt);
      this->m_FreeGCTmps();
    }
  }
}

void t_mx2_Translator_0CPP::m_EmitStmt(t_mx2_ThrowStmt* l_stmt){
  if(bbBool(l_stmt->m_value)){
    this->m_Emit(((BB_T("throw ")+this->m_Trans(l_stmt->m_value))+BB_T(";")));
  }else{
    this->m_Emit(BB_T("throw;"));
  }
}

void t_mx2_Translator_0CPP::m_EmitStmt(t_mx2_TryStmt* l_stmt){
  this->m_Emit(BB_T("try{"));
  this->m_EmitBlock(l_stmt->m_block);
  {
    bbInt l_0=bbInt(0);
    bbInt l_1=l_stmt->m_catches->length();
    for(;(l_0<l_1);l_0+=1){
      struct f2_t : public bbGCFrame{
        t_mx2_CatchStmt* l_cstmt{};
        t_mx2_VarValue* l_vvar{};
        void gcMark(){
          bbGCMarkPtr(l_cstmt);
          bbGCMarkPtr(l_vvar);
        }
      }f2{};
      f2.l_cstmt=l_stmt->m_catches->at(l_0);
      f2.l_vvar=f2.l_cstmt->m_vvar;
      this->m_Uses(f2.l_vvar->m_type);
      if(g_mx2_IsGCType(f2.l_vvar->m_type)){
        this->m_Emit(((BB_T("}catch(")+this->m_TransType(f2.l_vvar->m_type))+BB_T(" ex){")));
        this->m_BeginBlock();
        bbString l_tmp=this->m_InsertGCTmp(f2.l_vvar);
        this->m_Emit((l_tmp+BB_T("=ex;")));
        this->m_EmitStmts(f2.l_cstmt->m_block);
        this->m_EndBlock();
      }else{
        this->m_Emit(((BB_T("}catch(")+this->m_VarProto(f2.l_vvar))+BB_T("){")));
        this->m_EmitBlock(f2.l_cstmt->m_block);
      }
    }
  }
  this->m_Emit(BB_T("}"));
}

void t_mx2_Translator_0CPP::m_EmitStmt(t_mx2_ForStmt* l_stmt){
  this->m_Emit(BB_T("{"));
  this->m_BeginGCFrame();
  if(this->m_debug){
    this->m_Emit(BB_T("bbDBLoop db_loop;"));
  }
  this->m_EmitStmts(l_stmt->m_iblock);
  bbString l_cond=this->m_Trans(l_stmt->m_cond);
  if(bbBool(l_stmt->m_incr)){
    this->m_EmitStmt(l_stmt->m_incr);
    bbString l_incr=this->m__0buf->m_Pop().trim().slice(bbInt(0),-1);
    this->m_Emit(((((BB_T("for(;")+l_cond)+BB_T(";"))+l_incr)+BB_T("){")));
  }else{
    this->m_Emit(((BB_T("while(")+l_cond)+BB_T("){")));
  }
  this->m_EmitBlock(l_stmt->m_block);
  this->m_Emit(BB_T("}"));
  this->m_EndGCFrame();
  this->m_Emit(BB_T("}"));
}

void t_mx2_Translator_0CPP::m_EmitStmt(t_mx2_RepeatStmt* l_stmt){
  if(this->m_debug){
    this->m_Emit(BB_T("{"));
    this->m_Emit(BB_T("bbDBLoop db_loop;"));
  }
  if(bbBool(l_stmt->m_cond)){
    this->m_Emit(BB_T("do{"));
  }else{
    this->m_Emit(BB_T("for(;;){"));
  }
  this->m_EmitBlock(l_stmt->m_block);
  if(bbBool(l_stmt->m_cond)){
    this->m_Emit(((BB_T("}while(!(")+this->m_Trans(l_stmt->m_cond))+BB_T("));")));
  }else{
    this->m_Emit(BB_T("}"));
  }
  if(this->m_debug){
    this->m_Emit(BB_T("}"));
  }
}

void t_mx2_Translator_0CPP::m_EmitStmt(t_mx2_WhileStmt* l_stmt){
  if(this->m_debug){
    this->m_Emit(BB_T("{"));
    this->m_Emit(BB_T("bbDBLoop db_loop;"));
  }
  this->m_Emit(((BB_T("while(")+this->m_Trans(l_stmt->m_cond))+BB_T("){")));
  this->m_EmitBlock(l_stmt->m_block);
  this->m_Emit(BB_T("}"));
  if(this->m_debug){
    this->m_Emit(BB_T("}"));
  }
}

void t_mx2_Translator_0CPP::m_EmitStmt(t_mx2_SelectStmt* l_stmt){
  bbString l_tvalue=this->m_Trans(l_stmt->m_value);
  bbBool l_head=true;
  {
    bbInt l_0=bbInt(0);
    bbInt l_1=l_stmt->m_cases->length();
    for(;(l_0<l_1);l_0+=1){
      struct f2_t : public bbGCFrame{
        t_mx2_CaseStmt* l_cstmt{};
        void gcMark(){
          bbGCMarkPtr(l_cstmt);
        }
      }f2{};
      f2.l_cstmt=l_stmt->m_cases->at(l_0);
      if(bbBool(f2.l_cstmt->m_values)){
        bbString l_cmps=bbString{};
        {
          bbInt l_2=bbInt(0);
          bbInt l_3=f2.l_cstmt->m_values->length();
          for(;(l_2<l_3);l_2+=1){
            struct f5_t : public bbGCFrame{
              t_mx2_Value* l_value{};
              void gcMark(){
                bbGCMarkPtr(l_value);
              }
            }f5{};
            f5.l_value=f2.l_cstmt->m_values->at(l_2);
            if(bbBool(l_cmps)){
              l_cmps+=BB_T("||");
            }
            l_cmps+=((l_tvalue+BB_T("=="))+this->m_Trans(f5.l_value));
          }
        }
        l_cmps=((BB_T("if(")+l_cmps)+BB_T("){"));
        if(!l_head){
          l_cmps=(BB_T("}else ")+l_cmps);
        }
        this->m_Emit(l_cmps);
      }else{
        this->m_Emit(BB_T("}else{"));
      }
      l_head=false;
      this->m_EmitBlock(f2.l_cstmt->m_block);
    }
  }
  this->m_Emit(BB_T("}"));
}

void t_mx2_Translator_0CPP::m_EmitStmt(t_mx2_IfStmt* l_stmt){
  struct f0_t : public bbGCFrame{
    t_mx2_IfStmt* l_stmt{};
    f0_t(t_mx2_IfStmt* l_stmt):l_stmt(l_stmt){
    }
    void gcMark(){
      bbGCMarkPtr(l_stmt);
    }
  }f0{l_stmt};
  this->m_Emit(((BB_T("if(")+this->m_Trans(f0.l_stmt->m_cond))+BB_T("){")));
  this->m_EmitBlock(f0.l_stmt->m_block);
  while(bbBool(f0.l_stmt->m_succ)){
    f0.l_stmt=f0.l_stmt->m_succ;
    if(bbBool(f0.l_stmt->m_cond)){
      bbString l_db=this->m_DebugInfo(((t_mx2_Stmt*)(f0.l_stmt)));
      if(bbBool(l_db)){
        l_db+=BB_T(",");
      }
      this->m_Emit((((BB_T("}else if(")+l_db)+this->m_Trans(f0.l_stmt->m_cond))+BB_T("){")));
    }else{
      this->m_Emit(BB_T("}else{"));
      this->m_EmitDebugInfo(((t_mx2_Stmt*)(f0.l_stmt)));
    }
    this->m_EmitBlock(f0.l_stmt->m_block);
  }
  this->m_Emit(BB_T("}"));
}

void t_mx2_Translator_0CPP::m_EmitStmt(t_mx2_EvalStmt* l_stmt){
  this->m_Emit((this->m_Trans(l_stmt->m_value)+BB_T(";")));
}

void t_mx2_Translator_0CPP::m_EmitStmt(t_mx2_AssignStmt* l_stmt){
  struct f0_t : public bbGCFrame{
    t_mx2_EnumType* l_etype{};
    void gcMark(){
      bbGCMarkPtr(l_etype);
    }
  }f0{};
  bbString l_op=l_stmt->m_op;
  if(l_op==BB_T("~=")){
    l_op=BB_T("^=");
  }else if(l_op==BB_T("mod=")){
    l_op=BB_T("%=");
  }else if(l_op==BB_T("shl=")){
    l_op=BB_T("<<=");
  }else if(l_op==BB_T("shr")){
    l_op=BB_T(">>=");
  }else if(l_op==BB_T("=")){
    struct f1_t : public bbGCFrame{
      t_mx2_VarValue* l_vvar{};
      void gcMark(){
        bbGCMarkPtr(l_vvar);
      }
    }f1{};
    f1.l_vvar=bb_object_cast<t_mx2_VarValue*>(l_stmt->m_lhs);
    if((bbBool(f1.l_vvar)&&(f1.l_vvar->m_vdecl->m_kind==BB_T("param")))){
      this->m_FindGCTmp(f1.l_vvar);
    }
  }
  bbString l_lhs=this->m_Trans(l_stmt->m_lhs);
  bbString l_rhs=this->m_Trans(l_stmt->m_rhs);
  f0.l_etype=g_mx2_TCast_1Tt_mx2_EnumType_2(l_stmt->m_lhs->m_type);
  if((bbBool(f0.l_etype)&&f0.l_etype->m_edecl->m_IsExtern())){
    if((l_op!=BB_T("="))){
      if(l_stmt->m_lhs->m_HasSideEffects()){
        puts(BB_T("Danger Will Robinson!!!!!!").c_str());fflush( stdout );
      }
      l_rhs=((l_lhs+l_op.slice(bbInt(0),-1))+l_rhs);
      l_op=BB_T("=");
    }
    l_rhs=(((g_mx2_EnumName(f0.l_etype)+BB_T("("))+l_rhs)+BB_T(")"));
  }
  this->m_Emit((((l_lhs+l_op)+l_rhs)+BB_T(";")));
}

void t_mx2_Translator_0CPP::m_EmitStmt(t_mx2_VarDeclStmt* l_stmt){
  struct f0_t : public bbGCFrame{
    t_mx2_VarDecl* l_vdecl{};
    t_mx2_VarValue* l_vvar{};
    void gcMark(){
      bbGCMarkPtr(l_vdecl);
      bbGCMarkPtr(l_vvar);
    }
  }f0{};
  f0.l_vvar=l_stmt->m_varValue;
  f0.l_vdecl=f0.l_vvar->m_vdecl;
  this->m_Refs(f0.l_vvar->m_type);
  bbString l_dbvar=bbString{};
  if(((f0.l_vdecl->m_kind==BB_T("local"))&&g_mx2_IsGCType(f0.l_vvar->m_type))){
    l_dbvar=this->m_InsertGCTmp(f0.l_vvar);
    if(bbBool(f0.l_vvar->m_init)){
      this->m_Emit((((l_dbvar+BB_T("="))+this->m_Trans(f0.l_vvar->m_init))+BB_T(";")));
    }
  }else{
    l_dbvar=g_mx2_VarName(f0.l_vvar);
    bbString l_type=this->m_VarType(f0.l_vvar);
    if(((f0.l_vdecl->m_kind==BB_T("global"))||(f0.l_vdecl->m_kind==BB_T("const")))){
      l_type=(BB_T("static ")+l_type);
    }
    bbString l_init=BB_T("{}");
    if(bbBool(f0.l_vvar->m_init)){
      l_init=(BB_T("=")+this->m_Trans(f0.l_vvar->m_init));
    }
    this->m_Emit(((((l_type+BB_T(" "))+l_dbvar)+l_init)+BB_T(";")));
  }
  if((this->m_debug&&(f0.l_vdecl->m_kind==BB_T("local")))){
    this->m_Emit(((((BB_T("bbDBLocal(\"")+f0.l_vvar->m_vdecl->m_ident)+BB_T("\",&"))+l_dbvar)+BB_T(");")));
  }
}

void t_mx2_Translator_0CPP::m_EmitStmt(t_mx2_ReturnStmt* l_stmt){
  if(!bbBool(l_stmt->m_value)){
    this->m_Emit(BB_T("return;"));
    return;
  }
  this->m_Emit(((BB_T("return ")+this->m_Trans(l_stmt->m_value))+BB_T(";")));
}

void t_mx2_Translator_0CPP::m_EmitStmt(t_mx2_ContinueStmt* l_stmt){
  this->m_Emit(BB_T("continue;"));
}

void t_mx2_Translator_0CPP::m_EmitStmt(t_mx2_ExitStmt* l_stmt){
  this->m_Emit(BB_T("break;"));
}

void t_mx2_Translator_0CPP::m_EmitStmt(t_mx2_PrintStmt* l_stmt){
  this->m_Emit(((BB_T("puts(")+this->m_Trans(l_stmt->m_value))+BB_T(".c_str());fflush( stdout );")));
}

void t_mx2_Translator_0CPP::m_EmitStmt(t_mx2_Stmt* l_stmt){
  struct f0_t : public bbGCFrame{
    t_mx2_AssignStmt* l_assignStmt{};
    t_mx2_ContinueStmt* l_continueStmt{};
    t_mx2_EvalStmt* l_evalStmt{};
    t_mx2_ExitStmt* l_exitStmt{};
    t_mx2_ForStmt* l_forStmt{};
    t_mx2_IfStmt* l_ifStmt{};
    t_mx2_PrintStmt* l_printStmt{};
    t_mx2_RepeatStmt* l_repeatStmt{};
    t_mx2_ReturnStmt* l_returnStmt{};
    t_mx2_SelectStmt* l_selectStmt{};
    t_mx2_ThrowStmt* l_throwStmt{};
    t_mx2_TryStmt* l_tryStmt{};
    t_mx2_VarDeclStmt* l_varDeclStmt{};
    t_mx2_WhileStmt* l_whileStmt{};
    void gcMark(){
      bbGCMarkPtr(l_assignStmt);
      bbGCMarkPtr(l_continueStmt);
      bbGCMarkPtr(l_evalStmt);
      bbGCMarkPtr(l_exitStmt);
      bbGCMarkPtr(l_forStmt);
      bbGCMarkPtr(l_ifStmt);
      bbGCMarkPtr(l_printStmt);
      bbGCMarkPtr(l_repeatStmt);
      bbGCMarkPtr(l_returnStmt);
      bbGCMarkPtr(l_selectStmt);
      bbGCMarkPtr(l_throwStmt);
      bbGCMarkPtr(l_tryStmt);
      bbGCMarkPtr(l_varDeclStmt);
      bbGCMarkPtr(l_whileStmt);
    }
  }f0{};
  if(!bbBool(l_stmt)){
    return;
  }
  this->m_EmitDebugInfo(l_stmt);
  f0.l_exitStmt=bb_object_cast<t_mx2_ExitStmt*>(l_stmt);
  if(bbBool(f0.l_exitStmt)){
    this->m_EmitStmt(f0.l_exitStmt);
    return;
  }
  f0.l_continueStmt=bb_object_cast<t_mx2_ContinueStmt*>(l_stmt);
  if(bbBool(f0.l_continueStmt)){
    this->m_EmitStmt(f0.l_continueStmt);
    return;
  }
  f0.l_returnStmt=bb_object_cast<t_mx2_ReturnStmt*>(l_stmt);
  if(bbBool(f0.l_returnStmt)){
    this->m_EmitStmt(f0.l_returnStmt);
    return;
  }
  f0.l_varDeclStmt=bb_object_cast<t_mx2_VarDeclStmt*>(l_stmt);
  if(bbBool(f0.l_varDeclStmt)){
    this->m_EmitStmt(f0.l_varDeclStmt);
    return;
  }
  f0.l_assignStmt=bb_object_cast<t_mx2_AssignStmt*>(l_stmt);
  if(bbBool(f0.l_assignStmt)){
    this->m_EmitStmt(f0.l_assignStmt);
    return;
  }
  f0.l_evalStmt=bb_object_cast<t_mx2_EvalStmt*>(l_stmt);
  if(bbBool(f0.l_evalStmt)){
    this->m_EmitStmt(f0.l_evalStmt);
    return;
  }
  f0.l_ifStmt=bb_object_cast<t_mx2_IfStmt*>(l_stmt);
  if(bbBool(f0.l_ifStmt)){
    this->m_EmitStmt(f0.l_ifStmt);
    return;
  }
  f0.l_whileStmt=bb_object_cast<t_mx2_WhileStmt*>(l_stmt);
  if(bbBool(f0.l_whileStmt)){
    this->m_EmitStmt(f0.l_whileStmt);
    return;
  }
  f0.l_repeatStmt=bb_object_cast<t_mx2_RepeatStmt*>(l_stmt);
  if(bbBool(f0.l_repeatStmt)){
    this->m_EmitStmt(f0.l_repeatStmt);
    return;
  }
  f0.l_selectStmt=bb_object_cast<t_mx2_SelectStmt*>(l_stmt);
  if(bbBool(f0.l_selectStmt)){
    this->m_EmitStmt(f0.l_selectStmt);
    return;
  }
  f0.l_forStmt=bb_object_cast<t_mx2_ForStmt*>(l_stmt);
  if(bbBool(f0.l_forStmt)){
    this->m_EmitStmt(f0.l_forStmt);
    return;
  }
  f0.l_tryStmt=bb_object_cast<t_mx2_TryStmt*>(l_stmt);
  if(bbBool(f0.l_tryStmt)){
    this->m_EmitStmt(f0.l_tryStmt);
    return;
  }
  f0.l_throwStmt=bb_object_cast<t_mx2_ThrowStmt*>(l_stmt);
  if(bbBool(f0.l_throwStmt)){
    this->m_EmitStmt(f0.l_throwStmt);
    return;
  }
  f0.l_printStmt=bb_object_cast<t_mx2_PrintStmt*>(l_stmt);
  if(bbBool(f0.l_printStmt)){
    this->m_EmitStmt(f0.l_printStmt);
    return;
  }
  throw bbGCNew<t_mx2_TransEx>(((BB_T("Translator_CPP.EmitStmt() Stmt '")+bbString::fromCString(l_stmt->typeName()))+BB_T("' not recognized")));
}

bbString t_mx2_Translator_0CPP::m_EmitLambda(t_mx2_FuncValue* l_func){
  bbString l_ident=(BB_T("lambda")+bbString(this->m__0lambdaId));
  this->m__0lambdaId+=1;
  bbString l_bbtype=((BB_T("bbFunction<")+this->m_CFuncType(l_func->m_ftype))+BB_T(">"));
  this->m_Emit(((((BB_T("struct ")+l_ident)+BB_T(" : public "))+l_bbtype)+BB_T("::Rep{")));
  bbString l_ctorArgs=bbString{};
  bbString l_ctorInits=bbString{};
  bbString l_ctorVals=bbString{};
  {
    struct f1_t : public bbGCFrame{
      t_std_collections_Stack_1Tt_mx2_VarValue_2_Iterator l_0{};
      void gcMark(){
        bbGCMark(l_0);
      }
    }f1{};
    f1.l_0=l_func->m_captures->m_All();
    for(;!f1.l_0.m_AtEnd();f1.l_0.m_Bump()){
      struct f2_t : public bbGCFrame{
        t_mx2_VarValue* l_vvar{};
        void gcMark(){
          bbGCMarkPtr(l_vvar);
        }
      }f2{};
      f2.l_vvar=f1.l_0.m_Current();
      bbString l_varty=this->m_TransType(f2.l_vvar->m_type);
      bbString l_varid=g_mx2_VarName(f2.l_vvar);
      this->m_Emit((((l_varty+BB_T(" "))+l_varid)+BB_T(";")));
      l_ctorArgs+=(((BB_T(",")+l_varty)+BB_T(" "))+l_varid);
      l_ctorInits+=((((BB_T(",")+l_varid)+BB_T("("))+l_varid)+BB_T(")"));
      l_ctorVals+=(BB_T(",")+this->m_Trans(f2.l_vvar->m_init));
    }
  }
  if(bbBool(l_ctorArgs)){
    l_ctorVals=((BB_T("(")+l_ctorVals.slice(1))+BB_T(")"));
    this->m_Emit((((((l_ident+BB_T("("))+l_ctorArgs.slice(1))+BB_T("):"))+l_ctorInits.slice(1))+BB_T("{")));
    this->m_Emit(BB_T("}"));
  }
  bbString l_retType=this->m_TransType(l_func->m_ftype->m_retType);
  bbString l_params=bbString{};
  {
    bbInt l_1=bbInt(0);
    bbInt l_2=l_func->m_params->length();
    for(;(l_1<l_2);l_1+=1){
      struct f2_t : public bbGCFrame{
        t_mx2_VarValue* l_p{};
        void gcMark(){
          bbGCMarkPtr(l_p);
        }
      }f2{};
      f2.l_p=l_func->m_params->at(l_1);
      if(bbBool(l_params)){
        l_params+=BB_T(",");
      }
      l_params+=((this->m_TransType(f2.l_p->m_type)+BB_T(" "))+g_mx2_VarName(f2.l_p));
    }
  }
  this->m_Emit((((l_retType+BB_T(" invoke("))+l_params)+BB_T("){")));
  this->m_EmitBlock(l_func);
  this->m_Emit(BB_T("}"));
  this->m_Emit(BB_T("void gcMark(){"));
  {
    struct f1_t : public bbGCFrame{
      t_std_collections_Stack_1Tt_mx2_VarValue_2_Iterator l_3{};
      void gcMark(){
        bbGCMark(l_3);
      }
    }f1{};
    f1.l_3=l_func->m_captures->m_All();
    for(;!f1.l_3.m_AtEnd();f1.l_3.m_Bump()){
      struct f2_t : public bbGCFrame{
        t_mx2_VarValue* l_vvar{};
        void gcMark(){
          bbGCMarkPtr(l_vvar);
        }
      }f2{};
      f2.l_vvar=f1.l_3.m_Current();
      if(!g_mx2_IsGCType(f2.l_vvar->m_type)){
        continue;
      }
      this->m_Uses(f2.l_vvar->m_type);
      if(g_mx2_IsGCPtrType(f2.l_vvar->m_type)){
        this->m_Emit(((BB_T("bbGCMarkPtr(")+g_mx2_VarName(f2.l_vvar))+BB_T(");")));
      }else{
        this->m_Emit(((BB_T("bbGCMark(")+g_mx2_VarName(f2.l_vvar))+BB_T(");")));
      }
    }
  }
  this->m_Emit(BB_T("}"));
  this->m_Emit(BB_T("};"));
  return ((((l_bbtype+BB_T("(new "))+l_ident)+l_ctorVals)+BB_T(")"));
}

void t_mx2_Translator_0CPP::m_EmitGlobalInits(t_mx2_FileDecl* l_fdecl){
  this->m_EmitBr();
  this->m_Emit(((BB_T("void mx2_")+l_fdecl->m_ident)+BB_T("_init(){")));
  this->m_BeginGCFrame();
  this->m_Emit(BB_T("static bool done;"));
  this->m_Emit(BB_T("if(done) return;"));
  this->m_Emit(BB_T("done=true;"));
  {
    struct f1_t : public bbGCFrame{
      t_std_collections_Stack_1Tt_mx2_VarValue_2_Iterator l_0{};
      void gcMark(){
        bbGCMark(l_0);
      }
    }f1{};
    f1.l_0=l_fdecl->m_globals->m_All();
    for(;!f1.l_0.m_AtEnd();f1.l_0.m_Bump()){
      struct f2_t : public bbGCFrame{
        t_mx2_VarValue* l_vvar{};
        void gcMark(){
          bbGCMarkPtr(l_vvar);
        }
      }f2{};
      f2.l_vvar=f1.l_0.m_Current();
      if(bbBool(f2.l_vvar->m_init)){
        this->m_Emit((((this->m_Trans(f2.l_vvar)+BB_T("="))+this->m_Trans(f2.l_vvar->m_init))+BB_T(";")));
      }
    }
  }
  this->m_EndGCFrame();
  this->m_Emit(BB_T("}"));
  this->m_EmitBr();
  this->m_Emit(((((((BB_T("bbInit mx2_")+l_fdecl->m_ident)+BB_T("_init_v(\""))+l_fdecl->m_ident)+BB_T("\",&mx2_"))+l_fdecl->m_ident)+BB_T("_init);")));
}

void t_mx2_Translator_0CPP::m_EmitFunc(t_mx2_FuncValue* l_func,bbBool l_init){
  struct f0_t : public bbGCFrame{
    t_mx2_Module* l_module{};
    void gcMark(){
      bbGCMarkPtr(l_module);
    }
  }f0{};
  if(l_func->m_fdecl->m_IsAbstract()){
    return;
  }
  bbString l_proto=this->m_FuncProto(l_func,false);
  if(bbBool(l_func->m_invokeNew)){
    struct f1_t : public bbGCFrame{
      t_mx2_ClassScope* l_cscope{};
      void gcMark(){
        bbGCMarkPtr(l_cscope);
      }
    }f1{};
    l_proto+=((((BB_T(":")+g_mx2_ClassName(l_func->m_invokeNew->m_ctype))+BB_T("("))+this->m_TransArgs(l_func->m_invokeNew->m_args))+BB_T(")"));
    f1.l_cscope=bb_object_cast<t_mx2_ClassScope*>(l_func->m_scope);
    if(l_func->m_invokeNew->m_ctype->m__eq(((t_mx2_Type*)(f1.l_cscope->m_ctype)))){
      l_init=false;
    }
  }
  this->m_EmitBr();
  this->m_Emit((l_proto+BB_T("{")));
  if(l_init){
    this->m_Emit(BB_T("init();"));
  }
  f0.l_module=l_func->m_scope->m_FindFile()->m_fdecl->m_module;
  if((l_func==f0.l_module->m_main)){
    struct f1_t : public bbGCFrame{
      t_mx2_Builder* l_builder{};
      void gcMark(){
        bbGCMarkPtr(l_builder);
      }
    }f1{};
    this->m_Emit(BB_T("static bool done;"));
    this->m_Emit(BB_T("if(done) return;"));
    this->m_Emit(BB_T("done=true;"));
    f1.l_builder=g_mx2_Builder_instance;
    {
      struct f2_t : public bbGCFrame{
        t_std_collections_Map_1sz_KeyIterator l_0{};
        void gcMark(){
          bbGCMark(l_0);
        }
      }f2{};
      f2.l_0=f0.l_module->m_moduleDeps->m_Keys().m_All();
      for(;f2.l_0.m_Valid();f2.l_0.m_Bump()){
        struct f3_t : public bbGCFrame{
          t_mx2_Module* l_mod2{};
          void gcMark(){
            bbGCMarkPtr(l_mod2);
          }
        }f3{};
        bbString l_dep=f2.l_0.m_Current();
        f3.l_mod2=f1.l_builder->m_modulesMap->m__idx(l_dep);
        if(bbBool(f3.l_mod2->m_main)){
          this->m_Emit(((((BB_T("void mx2_")+f3.l_mod2->m_ident)+BB_T("_main();mx2_"))+f3.l_mod2->m_ident)+BB_T("_main();")));
        }
      }
    }
  }
  if((this->m_debug&&l_func->m_IsMethod())){
    if((!l_func->m_IsVirtual()&&!l_func->m_IsExtension())){
    }
  }
  this->m_EmitBlock(l_func);
  this->m_Emit(BB_T("}"));
}

void t_mx2_Translator_0CPP::m_EmitDebugInfo(t_mx2_Stmt* l_stmt){
  bbString l_db=this->m_DebugInfo(l_stmt);
  if(bbBool(l_db)){
    this->m_Emit((l_db+BB_T(";")));
  }
}

void t_mx2_Translator_0CPP::m_EmitClassProto(t_mx2_ClassType* l_ctype){
  struct f0_t : public bbGCFrame{
    t_mx2_ClassDecl* l_cdecl{};
    void gcMark(){
      bbGCMarkPtr(l_cdecl);
    }
  }f0{};
  f0.l_cdecl=l_ctype->m_cdecl;
  bbString l_cname=g_mx2_ClassName(l_ctype);
  bbString l_xtends=bbString{};
  bbString l_superName{};
  if(f0.l_cdecl->m_kind==BB_T("class")){
    if(bbBool(l_ctype->m_superType)){
      this->m_Uses(l_ctype->m_superType);
      l_superName=g_mx2_ClassName(l_ctype->m_superType);
      l_xtends=(BB_T("public ")+l_superName);
    }else{
      l_xtends=BB_T("public bbObject");
    }
  }else if(f0.l_cdecl->m_kind==BB_T("interface")){
    if(!bbBool(l_ctype->m_ifaceTypes)){
      l_xtends=BB_T("public bbInterface");
    }
  }else if(f0.l_cdecl->m_kind==BB_T("struct")){
  }
  if((f0.l_cdecl->m_kind!=BB_T("struct"))){
    {
      bbInt l_0=bbInt(0);
      bbInt l_1=l_ctype->m_ifaceTypes->length();
      for(;(l_0<l_1);l_0+=1){
        struct f3_t : public bbGCFrame{
          t_mx2_ClassType* l_iface{};
          void gcMark(){
            bbGCMarkPtr(l_iface);
          }
        }f3{};
        f3.l_iface=l_ctype->m_ifaceTypes->at(l_0);
        if((f3.l_iface->m_cdecl->m_kind==BB_T("protocol"))){
          continue;
        }
        this->m_Uses(f3.l_iface);
        if(bbBool(l_xtends)){
          l_xtends+=BB_T(",");
        }
        l_xtends+=(BB_T("public virtual ")+g_mx2_ClassName(f3.l_iface));
      }
    }
  }
  if(bbBool(l_xtends)){
    l_xtends=(BB_T(" : ")+l_xtends);
  }
  this->m_EmitBr();
  this->m_Emit((((BB_T("struct ")+l_cname)+l_xtends)+BB_T("{")));
  if(bbBool(l_ctype->m_superType)){
    struct f1_t : public bbGCFrame{
      t_std_collections_Map_1sz* l_done{};
      void gcMark(){
        bbGCMarkPtr(l_done);
      }
    }f1{};
    f1.l_done=bbGCNew<t_std_collections_Map_1sz>();
    this->m_EmitBr();
    {
      struct f2_t : public bbGCFrame{
        t_std_collections_Map_1sTt_mx2_SNode_2_Iterator l_2{};
        void gcMark(){
          bbGCMark(l_2);
        }
      }f2{};
      f2.l_2=l_ctype->m_scope->m_nodes->m_All();
      for(;f2.l_2.m_Valid();f2.l_2.m_Bump()){
        struct f3_t : public bbGCFrame{
          t_mx2_FuncList* l_flist{};
          t_std_collections_Map_1sTt_mx2_SNode_2_Node* l_it{};
          void gcMark(){
            bbGCMarkPtr(l_flist);
            bbGCMarkPtr(l_it);
          }
        }f3{};
        f3.l_it=f2.l_2.m_Current();
        f3.l_flist=bb_object_cast<t_mx2_FuncList*>(f3.l_it->m_Value());
        if((!bbBool(f3.l_flist)||(f3.l_it->m_Key()==BB_T("new")))){
          continue;
        }
        {
          struct f4_t : public bbGCFrame{
            t_std_collections_Stack_1Tt_mx2_FuncValue_2_Iterator l_3{};
            void gcMark(){
              bbGCMark(l_3);
            }
          }f4{};
          f4.l_3=f3.l_flist->m_funcs->m_All();
          for(;!f4.l_3.m_AtEnd();f4.l_3.m_Bump()){
            struct f5_t : public bbGCFrame{
              t_mx2_FuncValue* l_func{};
              void gcMark(){
                bbGCMarkPtr(l_func);
              }
            }f5{};
            f5.l_func=f4.l_3.m_Current();
            if((!f5.l_func->m_IsMethod()||(f5.l_func->m_scope!=((t_mx2_Scope*)(l_ctype->m_superType->m_scope))))){
              continue;
            }
            bbString l_sym=g_mx2_FuncName(f5.l_func);
            if(f1.l_done->m__idx(l_sym)){
              continue;
            }
            f1.l_done->m__idxeq(l_sym,true);
            this->m_Emit(((((BB_T("using ")+l_superName)+BB_T("::"))+l_sym)+BB_T(";")));
          }
        }
      }
    }
  }
  this->m_Emit(((BB_T("const char *typeName()const{return \"")+l_cname)+BB_T("\";}")));
  bbBool l_needsInit=false;
  bbBool l_needsMark=false;
  this->m_EmitBr();
  {
    struct f1_t : public bbGCFrame{
      t_std_collections_Stack_1Tt_mx2_VarValue_2_Iterator l_4{};
      void gcMark(){
        bbGCMark(l_4);
      }
    }f1{};
    f1.l_4=l_ctype->m_fields->m_All();
    for(;!f1.l_4.m_AtEnd();f1.l_4.m_Bump()){
      struct f2_t : public bbGCFrame{
        t_mx2_VarValue* l_vvar{};
        void gcMark(){
          bbGCMarkPtr(l_vvar);
        }
      }f2{};
      f2.l_vvar=f1.l_4.m_Current();
      this->m_Refs(f2.l_vvar->m_type);
      if(g_mx2_IsGCType(f2.l_vvar->m_type)){
        l_needsMark=true;
      }
      bbString l_proto=this->m_VarProto(f2.l_vvar);
      if(bbBool(f2.l_vvar->m_init)){
        if(f2.l_vvar->m_init->m_HasSideEffects()){
          this->m_Emit((l_proto+BB_T("{};")));
          l_needsInit=true;
        }else{
          this->m_Emit((((l_proto+BB_T("="))+this->m_Trans(f2.l_vvar->m_init))+BB_T(";")));
        }
      }else{
        this->m_Emit((l_proto+BB_T("{};")));
      }
    }
  }
  if(l_needsInit){
    this->m_EmitBr();
    this->m_Emit(BB_T("void init();"));
  }
  if((f0.l_cdecl->m_kind==BB_T("class"))){
    if(l_needsMark){
      this->m_EmitBr();
      this->m_Emit(BB_T("void gcMark();"));
    }
  }
  if(this->m_debug){
    if((f0.l_cdecl->m_kind==BB_T("class"))){
      this->m_Emit(BB_T("void dbEmit();"));
    }else if((f0.l_cdecl->m_kind==BB_T("struct"))){
      this->m_Emit(((BB_T("static void dbEmit(")+l_cname)+BB_T("*);")));
    }
  }
  bbBool l_hasCtor=false;
  bbBool l_hasDefaultCtor=false;
  this->m_EmitBr();
  {
    struct f1_t : public bbGCFrame{
      t_std_collections_Stack_1Tt_mx2_FuncValue_2_Iterator l_5{};
      void gcMark(){
        bbGCMark(l_5);
      }
    }f1{};
    f1.l_5=l_ctype->m_methods->m_All();
    for(;!f1.l_5.m_AtEnd();f1.l_5.m_Bump()){
      struct f2_t : public bbGCFrame{
        t_mx2_FuncValue* l_func{};
        t_mx2_FuncValue* l_node{};
        void gcMark(){
          bbGCMarkPtr(l_func);
          bbGCMarkPtr(l_node);
        }
      }f2{};
      f2.l_node=f1.l_5.m_Current();
      f2.l_func=f2.l_node;
      if((!bbBool(f2.l_func)||(f2.l_func->m_fdecl->m_ident!=BB_T("new")))){
        continue;
      }
      l_hasCtor=true;
      if(!bbBool(f2.l_func->m_ftype->m_argTypes)){
        l_hasDefaultCtor=true;
      }
      this->m_Refs(((t_mx2_Type*)(f2.l_func->m_ftype)));
      this->m_Emit((this->m_FuncProto(f2.l_func,true)+BB_T(";")));
    }
  }
  bbBool l_hasCmp=false;
  this->m_EmitBr();
  {
    struct f1_t : public bbGCFrame{
      t_std_collections_Stack_1Tt_mx2_FuncValue_2_Iterator l_6{};
      void gcMark(){
        bbGCMark(l_6);
      }
    }f1{};
    f1.l_6=l_ctype->m_methods->m_All();
    for(;!f1.l_6.m_AtEnd();f1.l_6.m_Bump()){
      struct f2_t : public bbGCFrame{
        t_mx2_FuncValue* l_func{};
        t_mx2_FuncValue* l_node{};
        void gcMark(){
          bbGCMarkPtr(l_func);
          bbGCMarkPtr(l_node);
        }
      }f2{};
      f2.l_node=f1.l_6.m_Current();
      f2.l_func=f2.l_node;
      if((!bbBool(f2.l_func)||(f2.l_func->m_fdecl->m_ident==BB_T("new")))){
        continue;
      }
      if((f2.l_func->m_fdecl->m_ident==BB_T("<=>"))){
        l_hasCmp=true;
      }
      this->m_Refs(((t_mx2_Type*)(f2.l_func->m_ftype)));
      this->m_Emit((this->m_FuncProto(f2.l_func,true)+BB_T(";")));
    }
  }
  if((f0.l_cdecl->m_kind==BB_T("struct"))){
    if((l_hasCtor||!l_hasDefaultCtor)){
      this->m_EmitBr();
      this->m_Emit((l_cname+BB_T("(){")));
      this->m_Emit(BB_T("}"));
    }
    if(!l_hasDefaultCtor){
      this->m_EmitBr();
      this->m_Emit((l_cname+BB_T("(bbNullCtor_t){")));
      if(l_needsInit){
        this->m_Emit(BB_T("init();"));
      }
      this->m_Emit(BB_T("}"));
    }
  }else if((f0.l_cdecl->m_kind==BB_T("class"))){
    if(!l_hasDefaultCtor){
      this->m_EmitBr();
      this->m_Emit((l_cname+BB_T("(){")));
      if(l_needsInit){
        this->m_Emit(BB_T("init();"));
      }
      this->m_Emit(BB_T("}"));
    }
  }
  this->m_Emit(BB_T("};"));
  if(this->m_debug){
    bbString l_tname=l_cname;
    if(!this->m_IsStruct(((t_mx2_Type*)(l_ctype)))){
      l_tname+=BB_T("*");
    }
    this->m_Emit(((BB_T("bbString bbDBType(")+l_tname)+BB_T("*);")));
    this->m_Emit(((BB_T("bbString bbDBValue(")+l_tname)+BB_T("*);")));
  }
  if(this->m_IsStruct(((t_mx2_Type*)(l_ctype)))){
    this->m_EmitBr();
    if(l_hasCmp){
      this->m_Emit(((((BB_T("inline int bbCompare(const ")+l_cname)+BB_T("&x,const "))+l_cname)+BB_T("&y){return x.m__cmp(y);}")));
    }else{
      this->m_Emit(((((BB_T("int bbCompare(const ")+l_cname)+BB_T("&x,const "))+l_cname)+BB_T("&y);")));
    }
    if(l_needsMark){
      this->m_EmitBr();
      this->m_Emit(((BB_T("void bbGCMark(const ")+g_mx2_ClassName(l_ctype))+BB_T("&);")));
    }
  }
}

void t_mx2_Translator_0CPP::m_EmitClassProto(t_mx2_ClassType* l_ctype,t_mx2_FileDecl* l_fdecl,t_std_collections_Map_1sz* l_emitted){
  if((l_ctype->m_cdecl->m_kind==BB_T("protocol"))){
    return;
  }
  bbInt l_insPos=this->m_InsertPos();
  this->m_EmitClassProto(l_ctype);
  l_emitted->m__idxeq(g_mx2_ClassName(l_ctype),true);
  {
    struct f1_t : public bbGCFrame{
      t_std_collections_Map_1sTt_mx2_ClassType_2_ValueIterator l_0{};
      void gcMark(){
        bbGCMark(l_0);
      }
    }f1{};
    f1.l_0=this->m__0usesTypes->m_Values().m_All();
    for(;f1.l_0.m_Valid();f1.l_0.m_Bump()){
      struct f2_t : public bbGCFrame{
        t_mx2_ClassType* l_ctype2{};
        void gcMark(){
          bbGCMarkPtr(l_ctype2);
        }
      }f2{};
      f2.l_ctype2=f1.l_0.m_Current();
      if(((f2.l_ctype2->m_transFile!=l_fdecl)||l_emitted->m__idx(g_mx2_ClassName(f2.l_ctype2)))){
        continue;
      }
      if((l_insPos!=-1)){
        this->m_EmitBr();
        this->m_BeginInsert(l_insPos);
        l_insPos=-1;
      }
      this->m_EmitClassProto(f2.l_ctype2,l_fdecl,l_emitted);
    }
  }
  if((l_insPos==-1)){
    this->m_EndInsert();
  }
}

void t_mx2_Translator_0CPP::m_EmitClassMembers(t_mx2_ClassType* l_ctype){
  struct f0_t : public bbGCFrame{
    t_mx2_ClassDecl* l_cdecl{};
    void gcMark(){
      bbGCMarkPtr(l_cdecl);
    }
  }f0{};
  f0.l_cdecl=l_ctype->m_cdecl;
  if((f0.l_cdecl->m_kind==BB_T("protocol"))){
    return;
  }
  bbString l_cname=g_mx2_ClassName(l_ctype);
  bbBool l_needsInit=false;
  bbBool l_needsMark=false;
  this->m_EmitBr();
  {
    struct f1_t : public bbGCFrame{
      t_std_collections_Stack_1Tt_mx2_VarValue_2_Iterator l_0{};
      void gcMark(){
        bbGCMark(l_0);
      }
    }f1{};
    f1.l_0=l_ctype->m_fields->m_All();
    for(;!f1.l_0.m_AtEnd();f1.l_0.m_Bump()){
      struct f2_t : public bbGCFrame{
        t_mx2_VarValue* l_vvar{};
        void gcMark(){
          bbGCMarkPtr(l_vvar);
        }
      }f2{};
      f2.l_vvar=f1.l_0.m_Current();
      if(g_mx2_IsGCType(f2.l_vvar->m_type)){
        l_needsMark=true;
      }
      if((bbBool(f2.l_vvar->m_init)&&f2.l_vvar->m_init->m_HasSideEffects())){
        l_needsInit=true;
      }
    }
  }
  if(l_needsInit){
    this->m_EmitBr();
    this->m_Emit(((BB_T("void ")+l_cname)+BB_T("::init(){")));
    this->m_BeginGCFrame();
    {
      struct f2_t : public bbGCFrame{
        t_std_collections_Stack_1Tt_mx2_VarValue_2_Iterator l_1{};
        void gcMark(){
          bbGCMark(l_1);
        }
      }f2{};
      f2.l_1=l_ctype->m_fields->m_All();
      for(;!f2.l_1.m_AtEnd();f2.l_1.m_Bump()){
        struct f3_t : public bbGCFrame{
          t_mx2_VarValue* l_vvar{};
          void gcMark(){
            bbGCMarkPtr(l_vvar);
          }
        }f3{};
        f3.l_vvar=f2.l_1.m_Current();
        if((!bbBool(f3.l_vvar->m_init)||!f3.l_vvar->m_init->m_HasSideEffects())){
          continue;
        }
        this->m_Emit((((this->m_Trans(f3.l_vvar)+BB_T("="))+this->m_Trans(f3.l_vvar->m_init))+BB_T(";")));
      }
    }
    this->m_EndGCFrame();
    this->m_Emit(BB_T("}"));
  }
  if((f0.l_cdecl->m_kind==BB_T("class"))){
    if(l_needsMark){
      this->m_EmitBr();
      this->m_Emit(((BB_T("void ")+l_cname)+BB_T("::gcMark(){")));
      if((bbBool(l_ctype->m_superType)&&l_ctype->m_superType->m__ne(((t_mx2_Type*)(g_mx2_Type_ObjectClass))))){
        this->m_Emit((g_mx2_ClassName(l_ctype->m_superType)+BB_T("::gcMark();")));
      }
      {
        struct f3_t : public bbGCFrame{
          t_std_collections_Stack_1Tt_mx2_VarValue_2_Iterator l_2{};
          void gcMark(){
            bbGCMark(l_2);
          }
        }f3{};
        f3.l_2=l_ctype->m_fields->m_All();
        for(;!f3.l_2.m_AtEnd();f3.l_2.m_Bump()){
          struct f4_t : public bbGCFrame{
            t_mx2_VarValue* l_vvar{};
            void gcMark(){
              bbGCMarkPtr(l_vvar);
            }
          }f4{};
          f4.l_vvar=f3.l_2.m_Current();
          if(!g_mx2_IsGCType(f4.l_vvar->m_type)){
            continue;
          }
          this->m_Uses(f4.l_vvar->m_type);
          this->m_Emit(((BB_T("bbGCMark(")+g_mx2_VarName(f4.l_vvar))+BB_T(");")));
        }
      }
      this->m_Emit(BB_T("}"));
    }
  }
  if((this->m_debug&&(f0.l_cdecl->m_kind==BB_T("class")))){
    this->m_EmitBr();
    this->m_Emit(((BB_T("void ")+l_cname)+BB_T("::dbEmit(){")));
    if((bbBool(l_ctype->m_superType)&&l_ctype->m_superType->m__ne(((t_mx2_Type*)(g_mx2_Type_ObjectClass))))){
      this->m_Emit((g_mx2_ClassName(l_ctype->m_superType)+BB_T("::dbEmit();")));
    }
    {
      struct f2_t : public bbGCFrame{
        t_std_collections_Stack_1Tt_mx2_VarValue_2_Iterator l_3{};
        void gcMark(){
          bbGCMark(l_3);
        }
      }f2{};
      f2.l_3=l_ctype->m_fields->m_All();
      for(;!f2.l_3.m_AtEnd();f2.l_3.m_Bump()){
        struct f3_t : public bbGCFrame{
          t_mx2_VarValue* l_vvar{};
          void gcMark(){
            bbGCMarkPtr(l_vvar);
          }
        }f3{};
        f3.l_vvar=f2.l_3.m_Current();
        this->m_Emit(((((BB_T("bbDBEmit(\"")+f3.l_vvar->m_vdecl->m_ident)+BB_T("\",&"))+g_mx2_VarName(f3.l_vvar))+BB_T(");")));
      }
    }
    this->m_Emit(BB_T("}"));
  }
  if((this->m_debug&&(f0.l_cdecl->m_kind==BB_T("struct")))){
    this->m_EmitBr();
    this->m_Emit(((((BB_T("void ")+l_cname)+BB_T("::dbEmit("))+l_cname)+BB_T("*p){")));
    {
      struct f2_t : public bbGCFrame{
        t_std_collections_Stack_1Tt_mx2_VarValue_2_Iterator l_4{};
        void gcMark(){
          bbGCMark(l_4);
        }
      }f2{};
      f2.l_4=l_ctype->m_fields->m_All();
      for(;!f2.l_4.m_AtEnd();f2.l_4.m_Bump()){
        struct f3_t : public bbGCFrame{
          t_mx2_VarValue* l_vvar{};
          void gcMark(){
            bbGCMarkPtr(l_vvar);
          }
        }f3{};
        f3.l_vvar=f2.l_4.m_Current();
        this->m_Emit(((((BB_T("bbDBEmit(\"")+f3.l_vvar->m_vdecl->m_ident)+BB_T("\",&p->"))+g_mx2_VarName(f3.l_vvar))+BB_T(");")));
      }
    }
    this->m_Emit(BB_T("}"));
  }
  {
    struct f1_t : public bbGCFrame{
      t_std_collections_Stack_1Tt_mx2_FuncValue_2_Iterator l_5{};
      void gcMark(){
        bbGCMark(l_5);
      }
    }f1{};
    f1.l_5=l_ctype->m_methods->m_All();
    for(;!f1.l_5.m_AtEnd();f1.l_5.m_Bump()){
      struct f2_t : public bbGCFrame{
        t_mx2_FuncValue* l_func{};
        t_mx2_FuncValue* l_node{};
        void gcMark(){
          bbGCMarkPtr(l_func);
          bbGCMarkPtr(l_node);
        }
      }f2{};
      f2.l_node=f1.l_5.m_Current();
      f2.l_func=f2.l_node;
      if((!bbBool(f2.l_func)||(f2.l_func->m_fdecl->m_ident!=BB_T("new")))){
        continue;
      }
      this->m_EmitBr();
      this->m_EmitFunc(f2.l_func,l_needsInit);
    }
  }
  bbBool l_hasCmp=false;
  {
    struct f1_t : public bbGCFrame{
      t_std_collections_Stack_1Tt_mx2_FuncValue_2_Iterator l_6{};
      void gcMark(){
        bbGCMark(l_6);
      }
    }f1{};
    f1.l_6=l_ctype->m_methods->m_All();
    for(;!f1.l_6.m_AtEnd();f1.l_6.m_Bump()){
      struct f2_t : public bbGCFrame{
        t_mx2_FuncValue* l_func{};
        t_mx2_FuncValue* l_node{};
        void gcMark(){
          bbGCMarkPtr(l_func);
          bbGCMarkPtr(l_node);
        }
      }f2{};
      f2.l_node=f1.l_6.m_Current();
      f2.l_func=f2.l_node;
      if((!bbBool(f2.l_func)||(f2.l_func->m_fdecl->m_ident==BB_T("new")))){
        continue;
      }
      if((f2.l_func->m_fdecl->m_ident==BB_T("<=>"))){
        l_hasCmp=true;
      }
      this->m_EmitBr();
      this->m_EmitFunc(f2.l_func,false);
    }
  }
  if(this->m_debug){
    bbString l_tname=l_cname;
    if(!this->m_IsStruct(((t_mx2_Type*)(l_ctype)))){
      l_tname+=BB_T("*");
    }
    this->m_Emit(((BB_T("bbString bbDBType(")+l_tname)+BB_T("*){")));
    this->m_Emit(((BB_T("return \"")+l_ctype->m_Name())+BB_T("\";")));
    this->m_Emit(BB_T("}"));
    this->m_Emit(((BB_T("bbString bbDBValue(")+l_tname)+BB_T("*p){")));
    if(f0.l_cdecl->m_kind==BB_T("class")){
      this->m_Emit(BB_T("return bbDBObjectValue(*p);"));
    }else if(f0.l_cdecl->m_kind==BB_T("interface")){
      this->m_Emit(BB_T("return bbDBInterfaceValue(*p);"));
    }else if(f0.l_cdecl->m_kind==BB_T("struct")){
      this->m_Emit(BB_T("return bbDBStructValue(p);"));
    }
    this->m_Emit(BB_T("}"));
  }
  if(this->m_IsStruct(((t_mx2_Type*)(l_ctype)))){
    if(!l_hasCmp){
      this->m_EmitBr();
      this->m_Emit(((((BB_T("int bbCompare(const ")+l_cname)+BB_T("&x,const "))+l_cname)+BB_T("&y){")));
      {
        struct f3_t : public bbGCFrame{
          t_std_collections_Stack_1Tt_mx2_VarValue_2_Iterator l_7{};
          void gcMark(){
            bbGCMark(l_7);
          }
        }f3{};
        f3.l_7=l_ctype->m_fields->m_All();
        for(;!f3.l_7.m_AtEnd();f3.l_7.m_Bump()){
          struct f4_t : public bbGCFrame{
            t_mx2_VarValue* l_vvar{};
            void gcMark(){
              bbGCMarkPtr(l_vvar);
            }
          }f4{};
          f4.l_vvar=f3.l_7.m_Current();
          bbString l_vname=g_mx2_VarName(f4.l_vvar);
          this->m_Emit(((((BB_T("if(int t=bbCompare(x.")+l_vname)+BB_T(",y."))+l_vname)+BB_T(")) return t;")));
        }
      }
      this->m_Emit(BB_T("return 0;"));
      this->m_Emit(BB_T("}"));
    }
    if(l_needsMark){
      this->m_EmitBr();
      this->m_Emit(((BB_T("void bbGCMark(const ")+l_cname)+BB_T("&t){")));
      if((bbBool(l_ctype->m_superType)&&l_ctype->m_superType->m__ne(((t_mx2_Type*)(g_mx2_Type_ObjectClass))))){
        this->m_Emit(((BB_T("bbGCMark((")+g_mx2_ClassName(l_ctype->m_superType))+BB_T("&)t);")));
      }
      {
        struct f3_t : public bbGCFrame{
          t_std_collections_Stack_1Tt_mx2_VarValue_2_Iterator l_8{};
          void gcMark(){
            bbGCMark(l_8);
          }
        }f3{};
        f3.l_8=l_ctype->m_fields->m_All();
        for(;!f3.l_8.m_AtEnd();f3.l_8.m_Bump()){
          struct f4_t : public bbGCFrame{
            t_mx2_VarValue* l_vvar{};
            void gcMark(){
              bbGCMarkPtr(l_vvar);
            }
          }f4{};
          f4.l_vvar=f3.l_8.m_Current();
          if(!g_mx2_IsGCType(f4.l_vvar->m_type)){
            continue;
          }
          this->m_Uses(f4.l_vvar->m_type);
          this->m_Emit(((BB_T("bbGCMark(t.")+g_mx2_VarName(f4.l_vvar))+BB_T(");")));
        }
      }
      this->m_Emit(BB_T("}"));
    }
  }
}

void t_mx2_Translator_0CPP::m_EmitBlock(t_mx2_FuncValue* l_func){
  this->m_BeginGCFrame(l_func);
  if(this->m_debug){
    this->m_Emit(((((((((BB_T("bbDBFrame db_f{\"")+l_func->m_Name())+BB_T(":"))+l_func->m_ftype->m_retType->m_Name())+BB_T("("))+l_func->m_ParamNames())+BB_T(")\",\""))+l_func->m_pnode->m_srcfile->m_path)+BB_T("\"};")));
    if(l_func->m_IsMethod()){
      if(l_func->m_cscope->m_ctype->m_cdecl->m_kind==BB_T("struct")){
        this->m_Emit((((g_mx2_ClassName(l_func->m_cscope->m_ctype)+BB_T("*self=&"))+this->m_Trans(l_func->m_selfValue))+BB_T(";")));
        this->m_Emit(BB_T("bbDBLocal(\"Self\",self);"));
      }else if(l_func->m_cscope->m_ctype->m_cdecl->m_kind==BB_T("class")){
        this->m_Emit((((g_mx2_ClassName(l_func->m_cscope->m_ctype)+BB_T("*self="))+this->m_Trans(l_func->m_selfValue))+BB_T(";")));
        this->m_Emit(BB_T("bbDBLocal(\"Self\",&self);"));
      }
    }
    {
      bbInt l_0=bbInt(0);
      bbInt l_1=l_func->m_params->length();
      for(;(l_0<l_1);l_0+=1){
        struct f3_t : public bbGCFrame{
          t_mx2_VarValue* l_vvar{};
          void gcMark(){
            bbGCMarkPtr(l_vvar);
          }
        }f3{};
        f3.l_vvar=l_func->m_params->at(l_0);
        this->m_Emit(((((BB_T("bbDBLocal(\"")+f3.l_vvar->m_vdecl->m_ident)+BB_T("\",&"))+this->m_Trans(f3.l_vvar))+BB_T(");")));
      }
    }
  }
  this->m_EmitStmts(l_func->m_block);
  this->m_EndGCFrame();
}

void t_mx2_Translator_0CPP::m_EmitBlock(t_mx2_Block* l_block){
  this->m_BeginBlock();
  this->m_EmitStmts(l_block);
  this->m_EndBlock();
}

bbString t_mx2_Translator_0CPP::m_ElementType(t_mx2_Type* l_type){
  bbString l_name=this->m_GCVarTypeName(l_type);
  if(!bbBool(l_name)){
    return this->m_TransType(l_type);
  }
  return ((BB_T("bbGCVar<")+l_name)+BB_T(">"));
}

bbString t_mx2_Translator_0CPP::m_DebugInfo(t_mx2_Stmt* l_stmt){
  if((this->m_debug&&bbBool(l_stmt->m_pnode))){
    return ((BB_T("bbDBStmt(")+bbString(l_stmt->m_pnode->m_srcpos))+BB_T(")"));
  }
  return bbString{};
}

void t_mx2_Translator_0CPP::m_BeginBlock(){
  this->m_BeginGCFrame();
  if(this->m_debug){
    this->m_Emit(BB_T("bbDBBlock db_blk;"));
  }
}

bbString t_mx2_Translator_0CPP::m_ArrayName(t_mx2_ArrayType* l_type){
  if((l_type->m_rank==1)){
    return ((BB_T("bbArray<")+this->m_ElementType(l_type->m_elemType))+BB_T(">"));
  }
  return ((((BB_T("bbArray<")+this->m_ElementType(l_type->m_elemType))+BB_T(","))+bbString(l_type->m_rank))+BB_T(">"));
}

void mx2_mx2cc_translator_0cpp_init(){
  static bool done;
  if(done) return;
  done=true;
}

bbInit mx2_mx2cc_translator_0cpp_init_v("mx2cc_translator_0cpp",&mx2_mx2cc_translator_0cpp_init);
