
#include "mx2cc_util.h"

// ***** External *****

#include "../../../../../modules/libc/libc.buildv1.0.0/desktop_release_linux/libc_libc.h"
#include "../../../../../modules/monkey/monkey.buildv1.0.0/desktop_release_linux/monkey_types.h"
#include "mx2cc_expr.h"
#include "mx2cc_node.h"
#include "mx2cc_type.h"
#include "mx2cc_typeexpr.h"
#include "mx2cc_value.h"
#include "mx2cc_var.h"

extern bbString g_std_filesystem_ExtractDir(bbString l_path);
extern bbString g_std_stringio_LoadString(bbString l_path);
extern bbBool g_std_stringio_SaveString(bbString l_str,bbString l_path);

// ***** Internal *****

bbString g_mx2_HostOS;
bbInt g_mx2_CHAR_0EOL;
bbInt g_mx2_CHAR_0TAB;
bbInt g_mx2_CHAR_0RETURN;
bbInt g_mx2_CHAR_0HASH;
bbInt g_mx2_CHAR_0QUOTE;
bbInt g_mx2_CHAR_0PLUS;
bbInt g_mx2_CHAR_0MINUS;
bbInt g_mx2_CHAR_0DOT;
bbInt g_mx2_CHAR_0UNDERSCORE;
bbInt g_mx2_CHAR_0APOSTROPHE;
bbInt g_mx2_CHAR_0DOLLAR;
bbInt g_mx2_CHAR_0TILDE;
bbInt g_mx2_CHAR_0BACKSLASH;
bbString g_mx2_STRING_0BACKSLASH;
bbString g_mx2_STRING_0TILDE;
bbString g_mx2_STRING_0QUOTE;
bbString g_mx2_STRING_0EOL;
bbString g_mx2_STRING_0RETURN;
bbString g_mx2_STRING_0TAB;
bbString g_mx2_STRING_0CPPBACKSLASH;
bbString g_mx2_STRING_0CPPQUOTE;
bbString g_mx2_STRING_0CPPEOL;
bbString g_mx2_STRING_0CPPRETURN;
bbString g_mx2_STRING_0CPPTAB;
bbString g_mx2_STRING_0MX2TILDE;
bbString g_mx2_STRING_0MX2QUOTE;
bbString g_mx2_STRING_0MX2EOL;
bbString g_mx2_STRING_0MX2RETURN;
bbString g_mx2_STRING_0MX2TAB;

bbString g_mx2_Join_1Tt_mx2_Value_2(bbArray<bbGCVar<t_mx2_Value>>* l_bits,bbString l_sep){
  struct f0_t : public bbGCFrame{
    bbArray<bbString>* t0{};
    void gcMark(){
      bbGCMarkPtr(t0);
    }
  }f0{};
  return l_sep.join(f0.t0=g_mx2_ToStrings_1Tt_mx2_Value_2(l_bits));
}

bbArray<bbString>* g_mx2_ToStrings_1Tt_mx2_Value_2(bbArray<bbGCVar<t_mx2_Value>>* l_bits){
  struct f0_t : public bbGCFrame{
    bbArray<bbString>* l_strs{};
    void gcMark(){
      bbGCMarkPtr(l_strs);
    }
  }f0{};
  f0.l_strs=bbArray<bbString>::create(l_bits->length());
  {
    bbInt l_i=bbInt(0);
    for(;(l_i<f0.l_strs->length());l_i+=1){
      if(bbBool(l_bits->at(l_i))){
        f0.l_strs->at(l_i)=l_bits->at(l_i)->m_ToString();
      }
    }
  }
  return f0.l_strs;
}

bbString g_mx2_Join_1Tt_mx2_Type_2(bbArray<bbGCVar<t_mx2_Type>>* l_bits,bbString l_sep){
  struct f0_t : public bbGCFrame{
    bbArray<bbString>* t0{};
    void gcMark(){
      bbGCMarkPtr(t0);
    }
  }f0{};
  return l_sep.join(f0.t0=g_mx2_ToStrings_1Tt_mx2_Type_2(l_bits));
}

bbArray<bbString>* g_mx2_ToStrings_1Tt_mx2_Type_2(bbArray<bbGCVar<t_mx2_Type>>* l_bits){
  struct f0_t : public bbGCFrame{
    bbArray<bbString>* l_strs{};
    void gcMark(){
      bbGCMarkPtr(l_strs);
    }
  }f0{};
  f0.l_strs=bbArray<bbString>::create(l_bits->length());
  {
    bbInt l_i=bbInt(0);
    for(;(l_i<f0.l_strs->length());l_i+=1){
      if(bbBool(l_bits->at(l_i))){
        f0.l_strs->at(l_i)=l_bits->at(l_i)->m_ToString();
      }
    }
  }
  return f0.l_strs;
}

bbString g_mx2_Join_1Tt_mx2_Expr_2(bbArray<bbGCVar<t_mx2_Expr>>* l_bits,bbString l_sep){
  struct f0_t : public bbGCFrame{
    bbArray<bbString>* t0{};
    void gcMark(){
      bbGCMarkPtr(t0);
    }
  }f0{};
  return l_sep.join(f0.t0=g_mx2_ToStrings_1Tt_mx2_Expr_2(l_bits));
}

bbArray<bbString>* g_mx2_ToStrings_1Tt_mx2_Expr_2(bbArray<bbGCVar<t_mx2_Expr>>* l_bits){
  struct f0_t : public bbGCFrame{
    bbArray<bbString>* l_strs{};
    void gcMark(){
      bbGCMarkPtr(l_strs);
    }
  }f0{};
  f0.l_strs=bbArray<bbString>::create(l_bits->length());
  {
    bbInt l_i=bbInt(0);
    for(;(l_i<f0.l_strs->length());l_i+=1){
      if(bbBool(l_bits->at(l_i))){
        f0.l_strs->at(l_i)=l_bits->at(l_i)->m_ToString();
      }
    }
  }
  return f0.l_strs;
}

bbString g_mx2_Join_1Tt_mx2_TypeExpr_2(bbArray<bbGCVar<t_mx2_TypeExpr>>* l_bits,bbString l_sep){
  struct f0_t : public bbGCFrame{
    bbArray<bbString>* t0{};
    void gcMark(){
      bbGCMarkPtr(t0);
    }
  }f0{};
  return l_sep.join(f0.t0=g_mx2_ToStrings_1Tt_mx2_TypeExpr_2(l_bits));
}

bbArray<bbString>* g_mx2_ToStrings_1Tt_mx2_TypeExpr_2(bbArray<bbGCVar<t_mx2_TypeExpr>>* l_bits){
  struct f0_t : public bbGCFrame{
    bbArray<bbString>* l_strs{};
    void gcMark(){
      bbGCMarkPtr(l_strs);
    }
  }f0{};
  f0.l_strs=bbArray<bbString>::create(l_bits->length());
  {
    bbInt l_i=bbInt(0);
    for(;(l_i<f0.l_strs->length());l_i+=1){
      if(bbBool(l_bits->at(l_i))){
        f0.l_strs->at(l_i)=l_bits->at(l_i)->m_ToString();
      }
    }
  }
  return f0.l_strs;
}

bbString g_mx2_Join_1Tt_mx2_VarDecl_2(bbArray<bbGCVar<t_mx2_VarDecl>>* l_bits,bbString l_sep){
  struct f0_t : public bbGCFrame{
    bbArray<bbString>* t0{};
    void gcMark(){
      bbGCMarkPtr(t0);
    }
  }f0{};
  return l_sep.join(f0.t0=g_mx2_ToStrings_1Tt_mx2_VarDecl_2(l_bits));
}

bbArray<bbString>* g_mx2_ToStrings_1Tt_mx2_VarDecl_2(bbArray<bbGCVar<t_mx2_VarDecl>>* l_bits){
  struct f0_t : public bbGCFrame{
    bbArray<bbString>* l_strs{};
    void gcMark(){
      bbGCMarkPtr(l_strs);
    }
  }f0{};
  f0.l_strs=bbArray<bbString>::create(l_bits->length());
  {
    bbInt l_i=bbInt(0);
    for(;(l_i<f0.l_strs->length());l_i+=1){
      if(bbBool(l_bits->at(l_i))){
        f0.l_strs->at(l_i)=l_bits->at(l_i)->m_ToString();
      }
    }
  }
  return f0.l_strs;
}

bbString g_mx2_EnquoteCppString(bbString l_str){
  l_str=l_str.replace(g_mx2_STRING_0BACKSLASH,g_mx2_STRING_0CPPBACKSLASH);
  l_str=l_str.replace(g_mx2_STRING_0QUOTE,g_mx2_STRING_0CPPQUOTE);
  l_str=l_str.replace(g_mx2_STRING_0EOL,g_mx2_STRING_0CPPEOL);
  l_str=l_str.replace(g_mx2_STRING_0RETURN,g_mx2_STRING_0CPPRETURN);
  l_str=l_str.replace(g_mx2_STRING_0TAB,g_mx2_STRING_0CPPTAB);
  return ((g_mx2_STRING_0QUOTE+l_str)+g_mx2_STRING_0QUOTE);
}

bbString g_mx2_DequoteMx2String(bbString l_str){
  if((((l_str.length()<2)||(l_str[bbInt(0)]!=g_mx2_CHAR_0QUOTE))||(l_str[(l_str.length()-1)]!=g_mx2_CHAR_0QUOTE))){
    puts((BB_T("MX2 string error:")+l_str).c_str());fflush( stdout );
    return l_str;
  }
  l_str=l_str.slice(1,-1);
  l_str=l_str.replace(g_mx2_STRING_0MX2TILDE,g_mx2_STRING_0TILDE);
  l_str=l_str.replace(g_mx2_STRING_0MX2QUOTE,g_mx2_STRING_0QUOTE);
  l_str=l_str.replace(g_mx2_STRING_0MX2EOL,g_mx2_STRING_0EOL);
  l_str=l_str.replace(g_mx2_STRING_0MX2RETURN,g_mx2_STRING_0RETURN);
  l_str=l_str.replace(g_mx2_STRING_0MX2TAB,g_mx2_STRING_0TAB);
  return l_str;
}

bbBool g_mx2_AllTypesGeneric(bbArray<bbGCVar<t_mx2_Type>>* l_types){
  {
    bbInt l_0=bbInt(0);
    bbInt l_1=l_types->length();
    for(;(l_0<l_1);l_0+=1){
      struct f2_t : public bbGCFrame{
        t_mx2_Type* l_type{};
        void gcMark(){
          bbGCMarkPtr(l_type);
        }
      }f2{};
      f2.l_type=l_types->at(l_0);
      if(!f2.l_type->m_IsGeneric()){
        return false;
      }
    }
  }
  return true;
}

bbBool g_mx2_AnyTypeGeneric(bbArray<bbGCVar<t_mx2_Type>>* l_types){
  {
    bbInt l_0=bbInt(0);
    bbInt l_1=l_types->length();
    for(;(l_0<l_1);l_0+=1){
      struct f2_t : public bbGCFrame{
        t_mx2_Type* l_type{};
        void gcMark(){
          bbGCMarkPtr(l_type);
        }
      }f2{};
      f2.l_type=l_types->at(l_0);
      if(f2.l_type->m_IsGeneric()){
        return true;
      }
    }
  }
  return false;
}

bbBool g_mx2_TypesEqual(bbArray<bbGCVar<t_mx2_Type>>* l_lhs,bbArray<bbGCVar<t_mx2_Type>>* l_rhs){
  if((l_lhs->length()!=l_rhs->length())){
    return false;
  }
  {
    bbInt l_i=bbInt(0);
    for(;(l_i<l_lhs->length());l_i+=1){
      if(!l_lhs->at(l_i)->m_Equals(l_rhs->at(l_i))){
        return false;
      }
    }
  }
  return true;
}

bbArray<bbGCVar<t_mx2_Type>>* g_mx2_Types(bbArray<bbGCVar<t_mx2_Value>>* l_args){
  struct f0_t : public bbGCFrame{
    bbArray<bbGCVar<t_mx2_Type>>* l_types{};
    void gcMark(){
      bbGCMarkPtr(l_types);
    }
  }f0{};
  f0.l_types=bbArray<bbGCVar<t_mx2_Type>>::create(l_args->length());
  {
    bbInt l_i=bbInt(0);
    for(;(l_i<f0.l_types->length());l_i+=1){
      if(bbBool(l_args->at(l_i))){
        f0.l_types->at(l_i)=l_args->at(l_i)->m_type;
      }
    }
  }
  return f0.l_types;
}

bbArray<bbGCVar<t_mx2_Value>>* g_mx2_UpCast(bbArray<bbGCVar<t_mx2_Value>>* l_args,t_mx2_Type* l_type){
  struct f0_t : public bbGCFrame{
    bbArray<bbGCVar<t_mx2_Value>>* l_args{};
    f0_t(bbArray<bbGCVar<t_mx2_Value>>* l_args):l_args(l_args){
    }
    void gcMark(){
      bbGCMarkPtr(l_args);
    }
  }f0{l_args};
  f0.l_args=f0.l_args->slice(bbInt(0));
  {
    bbInt l_i=bbInt(0);
    for(;(l_i<f0.l_args->length());l_i+=1){
      if(bbBool(f0.l_args->at(l_i))){
        f0.l_args->at(l_i)=f0.l_args->at(l_i)->m_UpCast(l_type);
      }
    }
  }
  return f0.l_args;
}

bbArray<bbGCVar<t_mx2_Value>>* g_mx2_SemantArgs(bbArray<bbGCVar<t_mx2_Expr>>* l_exprs,t_mx2_Scope* l_scope){
  struct f0_t : public bbGCFrame{
    bbArray<bbGCVar<t_mx2_Value>>* l_args{};
    void gcMark(){
      bbGCMarkPtr(l_args);
    }
  }f0{};
  f0.l_args=bbArray<bbGCVar<t_mx2_Value>>::create(l_exprs->length());
  {
    bbInt l_i=bbInt(0);
    for(;(l_i<f0.l_args->length());l_i+=1){
      if(bbBool(l_exprs->at(l_i))){
        f0.l_args->at(l_i)=l_exprs->at(l_i)->m_Semant(l_scope);
      }
    }
  }
  return f0.l_args;
}

bbArray<bbGCVar<t_mx2_Value>>* g_mx2_SemantRValues(bbArray<bbGCVar<t_mx2_Expr>>* l_exprs,t_mx2_Scope* l_scope){
  struct f0_t : public bbGCFrame{
    bbArray<bbGCVar<t_mx2_Value>>* l_args{};
    void gcMark(){
      bbGCMarkPtr(l_args);
    }
  }f0{};
  f0.l_args=bbArray<bbGCVar<t_mx2_Value>>::create(l_exprs->length());
  {
    bbInt l_i=bbInt(0);
    for(;(l_i<f0.l_args->length());l_i+=1){
      if(bbBool(l_exprs->at(l_i))){
        f0.l_args->at(l_i)=l_exprs->at(l_i)->m_SemantRValue(l_scope,((t_mx2_Type*)0));
      }
    }
  }
  return f0.l_args;
}

bbString g_mx2_MakeRelativePath(bbString l_path,bbString l_baseDir){
  while(l_baseDir.endsWith(BB_T("/"))){
    l_baseDir=l_baseDir.slice(bbInt(0),-1);
  }
  l_baseDir+=BB_T("/");
  bbString l_relpath=bbString{};
  while(!l_path.startsWith(l_baseDir)){
    bbString l_tdir=l_baseDir;
    l_baseDir=g_std_filesystem_ExtractDir(l_baseDir);
    if((l_baseDir==l_tdir)){
      return l_path;
    }
    l_relpath=(BB_T("../")+l_relpath);
  }
  l_relpath+=l_path.slice(l_baseDir.length());
  return l_relpath;
}

void g_mx2_CSaveString(bbString l_str,bbString l_path){
  bbString l_t=g_std_stringio_LoadString(l_path);
  if((l_t!=l_str)){
    g_std_stringio_SaveString(l_str,l_path);
  }
}

void g_mx2_SetEnv(bbString l_name,bbString l_value){
  setenv_(bbCString(l_name),bbCString(l_value),1);
}

bbString g_mx2_GetEnv(bbString l_name){
  char* l_p=getenv(bbCString(l_name));
  if(bbBool(l_p)){
    return bbString::fromCString(((void*)(l_p)));
  }
  return bbString{};
}

bbString g_mx2_MungPath(bbString l_path){
  bbString l_id=l_path;
  l_id=l_id.replace(BB_T("_"),BB_T("_0"));
  l_id=l_id.replace(BB_T("../"),BB_T("_1"));
  l_id=l_id.replace(BB_T("/"),BB_T("_2"));
  l_id=l_id.replace(BB_T(":"),BB_T("_3"));
  l_id=l_id.replace(BB_T(" "),BB_T("_4"));
  l_id=l_id.replace(BB_T("-"),BB_T("_5"));
  return l_id;
}

void mx2_mx2cc_util_init(){
  static bool done;
  if(done) return;
  done=true;
  g_mx2_HostOS=BB_T("linux");
  g_mx2_CHAR_0EOL=10;
  g_mx2_CHAR_0TAB=9;
  g_mx2_CHAR_0RETURN=13;
  g_mx2_CHAR_0HASH=35;
  g_mx2_CHAR_0QUOTE=34;
  g_mx2_CHAR_0PLUS=43;
  g_mx2_CHAR_0MINUS=45;
  g_mx2_CHAR_0DOT=46;
  g_mx2_CHAR_0UNDERSCORE=95;
  g_mx2_CHAR_0APOSTROPHE=39;
  g_mx2_CHAR_0DOLLAR=36;
  g_mx2_CHAR_0TILDE=126;
  g_mx2_CHAR_0BACKSLASH=92;
  g_mx2_STRING_0BACKSLASH=bbString::fromChar(g_mx2_CHAR_0BACKSLASH);
  g_mx2_STRING_0TILDE=bbString::fromChar(g_mx2_CHAR_0TILDE);
  g_mx2_STRING_0QUOTE=bbString::fromChar(g_mx2_CHAR_0QUOTE);
  g_mx2_STRING_0EOL=bbString::fromChar(g_mx2_CHAR_0EOL);
  g_mx2_STRING_0RETURN=bbString::fromChar(g_mx2_CHAR_0RETURN);
  g_mx2_STRING_0TAB=bbString::fromChar(g_mx2_CHAR_0TAB);
  g_mx2_STRING_0CPPBACKSLASH=(g_mx2_STRING_0BACKSLASH+g_mx2_STRING_0BACKSLASH);
  g_mx2_STRING_0CPPQUOTE=(g_mx2_STRING_0BACKSLASH+g_mx2_STRING_0QUOTE);
  g_mx2_STRING_0CPPEOL=(g_mx2_STRING_0BACKSLASH+BB_T("n"));
  g_mx2_STRING_0CPPRETURN=(g_mx2_STRING_0BACKSLASH+BB_T("r"));
  g_mx2_STRING_0CPPTAB=(g_mx2_STRING_0BACKSLASH+BB_T("t"));
  g_mx2_STRING_0MX2TILDE=(g_mx2_STRING_0TILDE+g_mx2_STRING_0TILDE);
  g_mx2_STRING_0MX2QUOTE=(g_mx2_STRING_0TILDE+BB_T("q"));
  g_mx2_STRING_0MX2EOL=(g_mx2_STRING_0TILDE+BB_T("n"));
  g_mx2_STRING_0MX2RETURN=(g_mx2_STRING_0TILDE+BB_T("r"));
  g_mx2_STRING_0MX2TAB=(g_mx2_STRING_0TILDE+BB_T("t"));
}

bbInit mx2_mx2cc_util_init_v("mx2cc_util",&mx2_mx2cc_util_init);
