
#include "mx2cc_parser.h"

// ***** External *****

#include "mx2cc_alias.h"
#include "mx2cc_class.h"
#include "mx2cc_decl.h"
#include "mx2cc_enum.h"
#include "mx2cc_errors.h"
#include "mx2cc_expr.h"
#include "mx2cc_func.h"
#include "mx2cc_node.h"
#include "mx2cc_property.h"
#include "mx2cc_std_collections_2map.h"
#include "mx2cc_std_collections_2stack.h"
#include "mx2cc_stmtexpr.h"
#include "mx2cc_toker.h"
#include "mx2cc_typeexpr.h"
#include "mx2cc_var.h"
#include "../../../../../modules/std/std.buildv1.0.0/desktop_release_linux/std_collections_2stack.h"

extern bbString g_std_filesystem_ExtractExt(bbString l_path);
extern bbString g_std_stringio_LoadString(bbString l_path);

// ***** Internal *****

void t_mx2_Parser::init(){
  m__0stateStack=bbGCNew<t_std_collections_Stack_1Tt_mx2_Toker_2>();
  m__0usings=bbGCNew<t_std_collections_Stack_1s>();
  m__0errors=bbGCNew<t_std_collections_Stack_1Tt_mx2_ParseEx_2>();
  m__0docs=bbGCNew<t_std_collections_Stack_1s>();
  m__0imports=bbGCNew<t_std_collections_Stack_1s>();
}

void t_mx2_Parser::gcMark(){
  bbGCMark(m__0fdecl);
  bbGCMark(m__0toker);
  bbGCMark(m__0stateStack);
  bbGCMark(m__0usings);
  bbGCMark(m__0errors);
  bbGCMark(m__0ppsyms);
  bbGCMark(m__0docs);
  bbGCMark(m__0imports);
}

t_mx2_Parser::t_mx2_Parser(bbString l_source,t_std_collections_Map_1ss* l_ppsyms){
  init();
  this->m__0ppsyms=l_ppsyms;
  this->m__0toker=bbGCNew<t_mx2_Toker>(l_source);
  this->m_Bump();
}

t_mx2_Parser::t_mx2_Parser(){
  init();
}

void t_mx2_Parser::m_TryParseFailed(){
  struct f0_t : public bbGCFrame{
    t_mx2_Toker* l_state{};
    void gcMark(){
      bbGCMarkPtr(l_state);
    }
  }f0{};
  f0.l_state=this->m__0stateStack->m_Pop();
  this->m__0toker->m_State(f0.l_state);
}

bbInt t_mx2_Parser::m_TokeType(){
  return this->m__0toker->m_TokeType();
}

bbString t_mx2_Parser::m_Toke(){
  return this->m__0toker->m_Toke();
}

bbString t_mx2_Parser::m_ToBool(bbString l_v){
  if(((l_v==BB_T("false"))||(l_v==BB_T("\"\"")))){
    return BB_T("false");
  }
  return BB_T("true");
}

bbInt t_mx2_Parser::m_SrcPos(){
  return this->m__0toker->m_SrcPos();
}

void t_mx2_Parser::m_SkipToNextLine(){
  this->m_SkipToEol();
  this->m_EatEols();
}

void t_mx2_Parser::m_SkipToEol(){
  while((bbBool(this->m_TokeType())&&(this->m_TokeType()!=g_mx2_TOKE_0EOL))){
    this->m_Bump();
  }
}

void t_mx2_Parser::m_PreProcess(bbString l_text){
  struct f0_t : public bbGCFrame{
    t_mx2_Parser* l_p{};
    void gcMark(){
      bbGCMarkPtr(l_p);
    }
  }f0{};
  f0.l_p=bbGCNew<t_mx2_Parser>(l_text.slice(1),this->m__0ppsyms);
  try{
    bbString l_0=f0.l_p->m_Toke().toLower();
    if(l_0==BB_T("if")){
      if((this->m__0ccnest==this->m__0ifnest)){
        f0.l_p->m_Bump();
        if(f0.l_p->m_EvalBool()){
          this->m__0ccnest+=1;
        }
      }
      this->m__0ifnest+=1;
    }else if(l_0==BB_T("else")||l_0==BB_T("elseif")){
      if((this->m__0ccnest==this->m__0ifnest)){
        this->m__0ccnest|=65536;
      }else if((this->m__0ccnest==(this->m__0ifnest-1))){
        bbBool l_t=true;
        if(f0.l_p->m_CParse(BB_T("else"))){
          if(f0.l_p->m_CParse(BB_T("if"))){
            l_t=f0.l_p->m_EvalBool();
          }
        }else{
          f0.l_p->m_Bump();
          l_t=f0.l_p->m_EvalBool();
        }
        if(l_t){
          this->m__0ccnest+=1;
        }
      }
    }else if(l_0==BB_T("end")||l_0==BB_T("endif")){
      if(f0.l_p->m_CParse(BB_T("end"))){
        f0.l_p->m_CParse(BB_T("if"));
      }else{
        f0.l_p->m_Bump();
      }
      this->m__0doccing=false;
      this->m__0ccnest&=~65536;
      if((this->m__0ccnest==this->m__0ifnest)){
        this->m__0ccnest-=1;
      }
      this->m__0ifnest-=1;
    }else if(l_0==BB_T("rem")){
      if(((f0.l_p->m_Bump()==BB_T("monkeydoc"))&&(this->m__0ccnest==this->m__0ifnest))){
        bbString l_qhelp=f0.l_p->m__0toker->m_Text().slice((f0.l_p->m__0toker->m_TokePos()+9)).trim();
        this->m__0ccnest|=65536;
        this->m__0doccing=true;
        this->m__0docs->m_Clear();
        this->m__0docs->m_Push(l_qhelp);
      }
      this->m__0ifnest+=1;
    }else if(l_0==BB_T("import")){
      if((this->m__0ccnest==this->m__0ifnest)){
        f0.l_p->m_Bump();
        bbString l_path=f0.l_p->m_ParseString();
        if((l_path.startsWith(BB_T("<"))&&l_path.endsWith(BB_T(">")))){
          if(!bbBool(g_std_filesystem_ExtractExt(l_path))){
            l_path=(l_path.slice(bbInt(0),-1)+BB_T(".monkey2>"));
          }
        }else{
          if((!bbBool(g_std_filesystem_ExtractExt(l_path))&&!l_path.contains(BB_T("@/")))){
            l_path+=BB_T(".monkey2");
          }
        }
        this->m__0imports->m_Push(l_path);
      }
    }else if(l_0==BB_T("print")){
      if((this->m__0ccnest==this->m__0ifnest)){
        f0.l_p->m_Bump();
        puts(f0.l_p->m_Eval().c_str());fflush( stdout );
      }
    }
  }catch(t_mx2_ParseEx* ex){
    struct f1_t : public bbGCFrame{
      t_mx2_ParseEx* l_ex{};
      void gcMark(){
        bbGCMarkPtr(l_ex);
      }
    }f1{};
    f1.l_ex=ex;
  }
}

t_mx2_WhileStmtExpr* t_mx2_Parser::m_ParseWhile(){
  struct f0_t : public bbGCFrame{
    t_mx2_Expr* l_cond{};
    bbArray<bbGCVar<t_mx2_StmtExpr>>* l_stmts{};
    void gcMark(){
      bbGCMarkPtr(l_cond);
      bbGCMarkPtr(l_stmts);
    }
  }f0{};
  bbInt l_srcpos=this->m_SrcPos();
  try{
    this->m_Parse(BB_T("while"));
    f0.l_cond=this->m_ParseExpr();
    this->m_ParseEol();
  }catch(t_mx2_ParseEx* ex){
    struct f1_t : public bbGCFrame{
      t_mx2_ParseEx* l_ex{};
      void gcMark(){
        bbGCMarkPtr(l_ex);
      }
    }f1{};
    f1.l_ex=ex;
    this->m_SkipToNextLine();
  }
  f0.l_stmts=this->m_ParseStmts(true);
  try{
    if(this->m_CParse(BB_T("end"))){
      this->m_CParse(BB_T("while"));
    }else{
      this->m_Parse(BB_T("wend"));
    }
    this->m_ParseEol();
  }catch(t_mx2_ParseEx* ex){
    struct f1_t : public bbGCFrame{
      t_mx2_ParseEx* l_ex{};
      void gcMark(){
        bbGCMarkPtr(l_ex);
      }
    }f1{};
    f1.l_ex=ex;
    this->m_SkipToNextLine();
  }
  return bbGCNew<t_mx2_WhileStmtExpr>(f0.l_cond,f0.l_stmts,l_srcpos,this->m_EndPos());
}

void t_mx2_Parser::m_ParseVars(t_std_collections_Stack_1Tt_mx2_Decl_2* l_decls,bbInt l_flags){
  bbString l_kind=this->m_Parse();
  try{
    do{
      struct f2_t : public bbGCFrame{
        t_mx2_VarDecl* l_decl{};
        void gcMark(){
          bbGCMarkPtr(l_decl);
        }
      }f2{};
      f2.l_decl=bbGCNew<t_mx2_VarDecl>();
      f2.l_decl->m_srcpos=this->m_SrcPos();
      f2.l_decl->m_kind=l_kind;
      f2.l_decl->m_docs=this->m_Docs();
      f2.l_decl->m_flags=l_flags;
      f2.l_decl->m_ident=this->m_ParseIdent();
      if(bbBool((l_flags&g_mx2_DECL_0EXTERN))){
        this->m_Parse(BB_T(":"));
        f2.l_decl->m_type=this->m_ParseType(((t_mx2_IdentTypeExpr*)0));
        if(this->m_CParse(BB_T("="))){
          f2.l_decl->m_symbol=this->m_ParseString();
        }
      }else if(this->m_CParse(BB_T(":"))){
        f2.l_decl->m_type=this->m_ParseType(((t_mx2_IdentTypeExpr*)0));
        if(this->m_CParse(BB_T("="))){
          f2.l_decl->m_init=this->m_ParseExpr();
        }
      }else if(this->m_CParse(BB_T(":="))){
        f2.l_decl->m_init=this->m_ParseExpr();
      }
      f2.l_decl->m_endpos=this->m_EndPos();
      l_decls->m_Push(((t_mx2_Decl*)(f2.l_decl)));
    }while(!(!this->m_CParse(BB_T(","))));
    this->m_ParseEol();
  }catch(t_mx2_ParseEx* ex){
    struct f1_t : public bbGCFrame{
      t_mx2_ParseEx* l_ex{};
      void gcMark(){
        bbGCMarkPtr(l_ex);
      }
    }f1{};
    f1.l_ex=ex;
    this->m_SkipToNextLine();
  }
}

bbString t_mx2_Parser::m_ParseUsingIdent(){
  if(this->m_CParse(BB_T("*"))){
    return BB_T("*");
  }
  bbString l_ident=this->m_ParseIdent();
  while(this->m_CParse(BB_T("."))){
    if(this->m_CParse(BB_T("*"))){
      return (l_ident+BB_T(".*"));
    }
    if(this->m_CParse(BB_T("."))){
      return (l_ident+BB_T(".."));
    }
    l_ident+=(BB_T(".")+this->m_ParseIdent());
  }
  return l_ident;
}

bbArray<bbGCVar<t_mx2_TypeExpr>>* t_mx2_Parser::m_ParseTypes(){
  struct f0_t : public bbGCFrame{
    t_std_collections_Stack_1Tt_mx2_TypeExpr_2* l_types{};
    void gcMark(){
      bbGCMarkPtr(l_types);
    }
  }f0{};
  f0.l_types=bbGCNew<t_std_collections_Stack_1Tt_mx2_TypeExpr_2>();
  do{
    struct f1_t : public bbGCFrame{
      t_mx2_TypeExpr* t0{};
      void gcMark(){
        bbGCMarkPtr(t0);
      }
    }f1{};
    f0.l_types->m_Push(f1.t0=this->m_ParseType(((t_mx2_IdentTypeExpr*)0)));
  }while(!(!this->m_CParse(BB_T(","))));
  return f0.l_types->m_ToArray();
}

t_mx2_TypeExpr* t_mx2_Parser::m_ParseType(t_mx2_IdentTypeExpr* l_identType){
  struct f0_t : public bbGCFrame{
    t_mx2_TypeExpr* l_type{};
    void gcMark(){
      bbGCMarkPtr(l_type);
    }
  }f0{};
  f0.l_type=this->m_ParseBaseType(l_identType);
  bbInt l_srcpos=f0.l_type->m_srcpos;
  for(;;){
    bbString l_0=this->m_Toke();
    if(l_0==BB_T("[")){
      this->m_Bump();
      bbInt l_rank=1;
      while(this->m_CParse(BB_T(","))){
        l_rank+=1;
      }
      this->m_Parse(BB_T("]"));
      f0.l_type=((t_mx2_TypeExpr*)(bbGCNew<t_mx2_ArrayTypeExpr>(f0.l_type,l_rank,l_srcpos,this->m_EndPos())));
    }else if(l_0==BB_T("(")){
      f0.l_type=((t_mx2_TypeExpr*)(this->m_ParseFuncType(f0.l_type)));
    }else{
      break;
    }
  }
  return f0.l_type;
}

t_mx2_TryStmtExpr* t_mx2_Parser::m_ParseTry(){
  struct f0_t : public bbGCFrame{
    t_std_collections_Stack_1Tt_mx2_CatchExpr_2* l_catches{};
    bbArray<bbGCVar<t_mx2_StmtExpr>>* l_stmts{};
    bbArray<bbGCVar<t_mx2_CatchExpr>>* t0{};
    void gcMark(){
      bbGCMarkPtr(l_catches);
      bbGCMarkPtr(l_stmts);
      bbGCMarkPtr(t0);
    }
  }f0{};
  bbInt l_srcpos=this->m_SrcPos();
  try{
    this->m_Parse(BB_T("try"));
    this->m_ParseEol();
  }catch(t_mx2_ParseEx* ex){
    struct f1_t : public bbGCFrame{
      t_mx2_ParseEx* l_ex{};
      void gcMark(){
        bbGCMarkPtr(l_ex);
      }
    }f1{};
    f1.l_ex=ex;
    this->m_SkipToNextLine();
  }
  f0.l_stmts=this->m_ParseStmts(true);
  f0.l_catches=bbGCNew<t_std_collections_Stack_1Tt_mx2_CatchExpr_2>();
  while((this->m_Toke()==BB_T("catch"))){
    struct f1_t : public bbGCFrame{
      bbArray<bbGCVar<t_mx2_StmtExpr>>* l_stmts{};
      t_mx2_TypeExpr* l_varType{};
      t_mx2_CatchExpr* t0{};
      void gcMark(){
        bbGCMarkPtr(l_stmts);
        bbGCMarkPtr(l_varType);
        bbGCMarkPtr(t0);
      }
    }f1{};
    bbInt l_srcpos=this->m_SrcPos();
    this->m_Bump();
    bbString l_varIdent{};
    try{
      l_varIdent=this->m_ParseIdent();
      this->m_Parse(BB_T(":"));
      f1.l_varType=this->m_ParseType(((t_mx2_IdentTypeExpr*)0));
      this->m_ParseEol();
    }catch(t_mx2_ParseEx* ex){
      struct f2_t : public bbGCFrame{
        t_mx2_ParseEx* l_ex{};
        void gcMark(){
          bbGCMarkPtr(l_ex);
        }
      }f2{};
      f2.l_ex=ex;
      this->m_SkipToNextLine();
    }
    f1.l_stmts=this->m_ParseStmts(true);
    f0.l_catches->m_Push(f1.t0=bbGCNew<t_mx2_CatchExpr>(l_varIdent,f1.l_varType,f1.l_stmts));
  }
  try{
    this->m_Parse(BB_T("end"));
    this->m_CParse(BB_T("try"));
    this->m_ParseEol();
  }catch(t_mx2_ParseEx* ex){
    struct f1_t : public bbGCFrame{
      t_mx2_ParseEx* l_ex{};
      void gcMark(){
        bbGCMarkPtr(l_ex);
      }
    }f1{};
    f1.l_ex=ex;
    this->m_SkipToNextLine();
  }
  return bbGCNew<t_mx2_TryStmtExpr>(f0.l_stmts,f0.t0=f0.l_catches->m_ToArray(),l_srcpos,this->m_EndPos());
}

bbString t_mx2_Parser::m_ParseString(){
  if((this->m_TokeType()!=g_mx2_TOKE_0STRINGLIT)){
    this->m_Error(BB_T("Expecting string literal"));
  }
  bbString l_str=this->m_Toke().slice(1,-1);
  this->m_Bump();
  return l_str;
}

bbArray<bbGCVar<t_mx2_StmtExpr>>* t_mx2_Parser::m_ParseStmts(bbBool l_block){
  if(l_block){
    return this->m_ParseBlockStmts();
  }
  return this->m_ParseSimpleStmts();
}

bbArray<bbGCVar<t_mx2_StmtExpr>>* t_mx2_Parser::m_ParseSimpleStmts(){
  struct f0_t : public bbGCFrame{
    t_std_collections_Stack_1Tt_mx2_StmtExpr_2* l_stmts{};
    void gcMark(){
      bbGCMarkPtr(l_stmts);
    }
  }f0{};
  f0.l_stmts=bbGCNew<t_std_collections_Stack_1Tt_mx2_StmtExpr_2>();
  try{
    do{
      struct f2_t : public bbGCFrame{
        t_mx2_StmtExpr* t0{};
        void gcMark(){
          bbGCMarkPtr(t0);
        }
      }f2{};
      f0.l_stmts->m_Push(f2.t0=this->m_ParseSimpleStmt());
    }while(!(!this->m_CParse(BB_T(";"))));
  }catch(t_mx2_ParseEx* ex){
    struct f1_t : public bbGCFrame{
      t_mx2_ParseEx* l_ex{};
      void gcMark(){
        bbGCMarkPtr(l_ex);
      }
    }f1{};
    f1.l_ex=ex;
    this->m_SkipToEol();
  }
  return f0.l_stmts->m_ToArray();
}

t_mx2_StmtExpr* t_mx2_Parser::m_ParseSimpleStmt(){
  bbInt l_srcpos=this->m_SrcPos();
  bbString l_0=this->m_Toke();
  if(l_0==BB_T("print")){
    struct f1_t : public bbGCFrame{
      t_mx2_Expr* l_expr{};
      void gcMark(){
        bbGCMarkPtr(l_expr);
      }
    }f1{};
    this->m_Bump();
    f1.l_expr=this->m_ParseExpr();
    return ((t_mx2_StmtExpr*)(bbGCNew<t_mx2_PrintStmtExpr>(f1.l_expr,l_srcpos,this->m_EndPos())));
  }else if(l_0==BB_T("return")){
    struct f1_t : public bbGCFrame{
      t_mx2_Expr* l_expr{};
      void gcMark(){
        bbGCMarkPtr(l_expr);
      }
    }f1{};
    this->m_Bump();
    if(!this->m_AtEos()){
      f1.l_expr=this->m_ParseExpr();
    }
    return ((t_mx2_StmtExpr*)(bbGCNew<t_mx2_ReturnStmtExpr>(f1.l_expr,l_srcpos,this->m_EndPos())));
  }else if(l_0==BB_T("throw")){
    struct f1_t : public bbGCFrame{
      t_mx2_Expr* l_expr{};
      void gcMark(){
        bbGCMarkPtr(l_expr);
      }
    }f1{};
    this->m_Bump();
    if(!this->m_AtEos()){
      f1.l_expr=this->m_ParseExpr();
    }
    return ((t_mx2_StmtExpr*)(bbGCNew<t_mx2_ThrowStmtExpr>(f1.l_expr,l_srcpos,this->m_EndPos())));
  }else if(l_0==BB_T("continue")){
    this->m_Bump();
    return ((t_mx2_StmtExpr*)(bbGCNew<t_mx2_ContinueStmtExpr>(l_srcpos,this->m_EndPos())));
  }else if(l_0==BB_T("exit")){
    this->m_Bump();
    return ((t_mx2_StmtExpr*)(bbGCNew<t_mx2_ExitStmtExpr>(l_srcpos,this->m_EndPos())));
  }
  return this->m_ParseExprStmt();
}

t_mx2_Expr* t_mx2_Parser::m_ParseShiftExpr(){
  struct f0_t : public bbGCFrame{
    t_mx2_Expr* l_expr{};
    void gcMark(){
      bbGCMarkPtr(l_expr);
    }
  }f0{};
  bbInt l_srcpos=this->m_SrcPos();
  f0.l_expr=this->m_ParseAddsubExpr();
  for(;;){
    bbString l_0=this->m_Toke();
    if(l_0==BB_T("shl")||l_0==BB_T("shr")){
      struct f2_t : public bbGCFrame{
        t_mx2_Expr* t0{};
        void gcMark(){
          bbGCMarkPtr(t0);
        }
      }f2{};
      bbString l_op=this->m_Parse();
      f0.l_expr=((t_mx2_Expr*)(bbGCNew<t_mx2_BinaryopExpr>(l_op,f0.l_expr,f2.t0=this->m_ParseAddsubExpr(),l_srcpos,this->m_EndPos())));
    }else{
      break;
    }
  }
  return f0.l_expr;
}

t_mx2_SelectStmtExpr* t_mx2_Parser::m_ParseSelect(){
  struct f0_t : public bbGCFrame{
    t_std_collections_Stack_1Tt_mx2_CaseExpr_2* l_cases{};
    t_mx2_Expr* l_expr{};
    bbArray<bbGCVar<t_mx2_CaseExpr>>* t0{};
    void gcMark(){
      bbGCMarkPtr(l_cases);
      bbGCMarkPtr(l_expr);
      bbGCMarkPtr(t0);
    }
  }f0{};
  bbInt l_srcpos=this->m_SrcPos();
  try{
    this->m_Parse(BB_T("select"));
    f0.l_expr=this->m_ParseExpr();
    this->m_ParseEol();
  }catch(t_mx2_ParseEx* ex){
    struct f1_t : public bbGCFrame{
      t_mx2_ParseEx* l_ex{};
      void gcMark(){
        bbGCMarkPtr(l_ex);
      }
    }f1{};
    f1.l_ex=ex;
    this->m_SkipToNextLine();
  }
  f0.l_cases=bbGCNew<t_std_collections_Stack_1Tt_mx2_CaseExpr_2>();
  while(this->m_CParse(BB_T("case"))){
    struct f1_t : public bbGCFrame{
      t_std_collections_Stack_1Tt_mx2_Expr_2* l_exprs{};
      bbArray<bbGCVar<t_mx2_StmtExpr>>* l_stmts{};
      bbArray<bbGCVar<t_mx2_Expr>>* t0{};
      t_mx2_CaseExpr* t1{};
      void gcMark(){
        bbGCMarkPtr(l_exprs);
        bbGCMarkPtr(l_stmts);
        bbGCMarkPtr(t0);
        bbGCMarkPtr(t1);
      }
    }f1{};
    f1.l_exprs=bbGCNew<t_std_collections_Stack_1Tt_mx2_Expr_2>();
    try{
      do{
        struct f3_t : public bbGCFrame{
          t_mx2_Expr* t0{};
          void gcMark(){
            bbGCMarkPtr(t0);
          }
        }f3{};
        f1.l_exprs->m_Push(f3.t0=this->m_ParseExpr());
      }while(!(!this->m_CParse(BB_T(","))));
      this->m_CParseEol();
    }catch(t_mx2_ParseEx* ex){
      struct f2_t : public bbGCFrame{
        t_mx2_ParseEx* l_ex{};
        void gcMark(){
          bbGCMarkPtr(l_ex);
        }
      }f2{};
      f2.l_ex=ex;
      this->m_SkipToNextLine();
    }
    f1.l_stmts=this->m_ParseStmts(true);
    f0.l_cases->m_Push(f1.t1=bbGCNew<t_mx2_CaseExpr>(f1.t0=f1.l_exprs->m_ToArray(),f1.l_stmts));
  }
  if(this->m_CParse(BB_T("default"))){
    struct f1_t : public bbGCFrame{
      bbArray<bbGCVar<t_mx2_StmtExpr>>* l_stmts{};
      t_mx2_CaseExpr* t0{};
      void gcMark(){
        bbGCMarkPtr(l_stmts);
        bbGCMarkPtr(t0);
      }
    }f1{};
    this->m_CParseEol();
    f1.l_stmts=this->m_ParseStmts(true);
    f0.l_cases->m_Push(f1.t0=bbGCNew<t_mx2_CaseExpr>(((bbArray<bbGCVar<t_mx2_Expr>>*)0),f1.l_stmts));
  }
  try{
    this->m_Parse(BB_T("end"));
    this->m_CParse(BB_T("select"));
    this->m_ParseEol();
  }catch(t_mx2_ParseEx* ex){
    struct f1_t : public bbGCFrame{
      t_mx2_ParseEx* l_ex{};
      void gcMark(){
        bbGCMarkPtr(l_ex);
      }
    }f1{};
    f1.l_ex=ex;
    this->m_SkipToNextLine();
  }
  return bbGCNew<t_mx2_SelectStmtExpr>(f0.l_expr,f0.t0=f0.l_cases->m_ToArray(),l_srcpos,this->m_EndPos());
}

t_mx2_RepeatStmtExpr* t_mx2_Parser::m_ParseRepeat(){
  struct f0_t : public bbGCFrame{
    t_mx2_Expr* l_cond{};
    bbArray<bbGCVar<t_mx2_StmtExpr>>* l_stmts{};
    void gcMark(){
      bbGCMarkPtr(l_cond);
      bbGCMarkPtr(l_stmts);
    }
  }f0{};
  bbInt l_srcpos=this->m_SrcPos();
  bbBool l_block=false;
  try{
    this->m_Parse(BB_T("repeat"));
    this->m_ParseEol();
  }catch(t_mx2_ParseEx* ex){
    struct f1_t : public bbGCFrame{
      t_mx2_ParseEx* l_ex{};
      void gcMark(){
        bbGCMarkPtr(l_ex);
      }
    }f1{};
    f1.l_ex=ex;
    this->m_SkipToNextLine();
  }
  f0.l_stmts=this->m_ParseStmts(true);
  try{
    if(this->m_CParse(BB_T("until"))){
      f0.l_cond=this->m_ParseExpr();
    }else if(!this->m_CParse(BB_T("forever"))){
      this->m_Error(BB_T("Expecting 'until' or 'forever'"));
    }
    this->m_ParseEol();
  }catch(t_mx2_ParseEx* ex){
    struct f1_t : public bbGCFrame{
      t_mx2_ParseEx* l_ex{};
      void gcMark(){
        bbGCMarkPtr(l_ex);
      }
    }f1{};
    f1.l_ex=ex;
    this->m_SkipToNextLine();
  }
  return bbGCNew<t_mx2_RepeatStmtExpr>(f0.l_stmts,f0.l_cond,l_srcpos,this->m_EndPos());
}

t_mx2_PropertyDecl* t_mx2_Parser::m_ParseProperty(bbInt l_flags){
  struct f0_t : public bbGCFrame{
    t_mx2_PropertyDecl* l_decl{};
    t_mx2_FuncDecl* l_func{};
    void gcMark(){
      bbGCMarkPtr(l_decl);
      bbGCMarkPtr(l_func);
    }
  }f0{};
  f0.l_decl=bbGCNew<t_mx2_PropertyDecl>();
  f0.l_decl->m_srcpos=this->m_SrcPos();
  f0.l_decl->m_flags=l_flags;
  f0.l_decl->m_kind=BB_T("property");
  f0.l_decl->m_docs=this->m_Docs();
  f0.l_func=this->m_ParseFunc(l_flags);
  f0.l_decl->m_ident=f0.l_func->m_ident;
  if(f0.l_func->m_IsGetter()){
    f0.l_decl->m_getFunc=f0.l_func;
    if((this->m_Toke()==BB_T("setter"))){
      f0.l_decl->m_setFunc=this->m_ParseFunc(l_flags);
      f0.l_decl->m_setFunc->m_ident=f0.l_decl->m_ident;
    }
  }else if(f0.l_func->m_IsSetter()){
    f0.l_decl->m_setFunc=f0.l_func;
    if((this->m_Toke()==BB_T("getter"))){
      f0.l_decl->m_getFunc=this->m_ParseFunc(l_flags);
      f0.l_decl->m_getFunc->m_ident=f0.l_decl->m_ident;
    }
  }
  f0.l_decl->m_endpos=this->m_EndPos();
  return f0.l_decl;
}

t_mx2_Expr* t_mx2_Parser::m_ParsePrimaryExpr(){
  bbInt l_srcpos=this->m_SrcPos();
  bbString l_0=this->m_Toke();
  if(l_0==BB_T("(")){
    struct f1_t : public bbGCFrame{
      t_mx2_Expr* l_expr{};
      void gcMark(){
        bbGCMarkPtr(l_expr);
      }
    }f1{};
    this->m_Bump();
    f1.l_expr=this->m_ParseExpr();
    this->m_Parse(BB_T(")"));
    return f1.l_expr;
  }else if(l_0==BB_T("self")){
    this->m_Bump();
    return ((t_mx2_Expr*)(bbGCNew<t_mx2_SelfExpr>(l_srcpos,this->m_EndPos())));
  }else if(l_0==BB_T("super")){
    this->m_Bump();
    return ((t_mx2_Expr*)(bbGCNew<t_mx2_SuperExpr>(l_srcpos,this->m_EndPos())));
  }else if(l_0==BB_T("null")){
    this->m_Bump();
    return ((t_mx2_Expr*)(bbGCNew<t_mx2_NullExpr>(l_srcpos,this->m_EndPos())));
  }else if(l_0==BB_T("new")){
    struct f1_t : public bbGCFrame{
      t_mx2_TypeExpr* l_type{};
      void gcMark(){
        bbGCMarkPtr(l_type);
      }
    }f1{};
    this->m_Bump();
    f1.l_type=this->m_ParseNewType();
    if(this->m_CParse(BB_T("["))){
      struct f2_t : public bbGCFrame{
        bbArray<bbGCVar<t_mx2_Expr>>* l_sizes{};
        t_mx2_ArrayTypeExpr* t0{};
        void gcMark(){
          bbGCMarkPtr(l_sizes);
          bbGCMarkPtr(t0);
        }
      }f2{};
      f2.l_sizes=this->m_ParseExprs();
      this->m_Parse(BB_T("]"));
      return ((t_mx2_Expr*)(bbGCNew<t_mx2_NewArrayExpr>(f2.t0=bbGCNew<t_mx2_ArrayTypeExpr>(f1.l_type,f2.l_sizes->length(),l_srcpos,this->m_EndPos()),f2.l_sizes,((bbArray<bbGCVar<t_mx2_Expr>>*)0),l_srcpos,this->m_EndPos())));
    }
    if((this->m_Toke()==BB_T("("))){
      struct f2_t : public bbGCFrame{
        bbArray<bbGCVar<t_mx2_Expr>>* l_args{};
        t_mx2_ArrayTypeExpr* l_atype{};
        void gcMark(){
          bbGCMarkPtr(l_args);
          bbGCMarkPtr(l_atype);
        }
      }f2{};
      f2.l_atype=bb_object_cast<t_mx2_ArrayTypeExpr*>(f1.l_type);
      if(bbBool(f2.l_atype)){
        struct f3_t : public bbGCFrame{
          bbArray<bbGCVar<t_mx2_Expr>>* l_inits{};
          void gcMark(){
            bbGCMarkPtr(l_inits);
          }
        }f3{};
        this->m_Bump();
        f3.l_inits=this->m_ParseExprs();
        this->m_Parse(BB_T(")"));
        return ((t_mx2_Expr*)(bbGCNew<t_mx2_NewArrayExpr>(f2.l_atype,((bbArray<bbGCVar<t_mx2_Expr>>*)0),f3.l_inits,l_srcpos,this->m_EndPos())));
      }
      f2.l_args=this->m_ParseInvokeArgs();
      return ((t_mx2_Expr*)(bbGCNew<t_mx2_NewObjectExpr>(f1.l_type,f2.l_args,l_srcpos,this->m_EndPos())));
    }
    return ((t_mx2_Expr*)(bbGCNew<t_mx2_NewObjectExpr>(f1.l_type,((bbArray<bbGCVar<t_mx2_Expr>>*)0),l_srcpos,this->m_EndPos())));
  }else if(l_0==BB_T("lambda")){
    struct f1_t : public bbGCFrame{
      t_mx2_FuncDecl* l_decl{};
      void gcMark(){
        bbGCMarkPtr(l_decl);
      }
    }f1{};
    f1.l_decl=this->m_ParseFunc(g_mx2_DECL_0PUBLIC);
    return ((t_mx2_Expr*)(bbGCNew<t_mx2_LambdaExpr>(f1.l_decl,l_srcpos,this->m_EndPos())));
  }else if(l_0==BB_T("cast")){
    struct f1_t : public bbGCFrame{
      t_mx2_Expr* l_expr{};
      t_mx2_TypeExpr* l_type{};
      void gcMark(){
        bbGCMarkPtr(l_expr);
        bbGCMarkPtr(l_type);
      }
    }f1{};
    this->m_Bump();
    this->m_Parse(BB_T("<"));
    f1.l_type=this->m_ParseType(((t_mx2_IdentTypeExpr*)0));
    this->m_Parse(BB_T(">"));
    this->m_Parse(BB_T("("));
    f1.l_expr=this->m_ParseExpr();
    this->m_Parse(BB_T(")"));
    return ((t_mx2_Expr*)(bbGCNew<t_mx2_CastExpr>(f1.l_type,f1.l_expr,l_srcpos,this->m_EndPos())));
  }else if(l_0==BB_T("true")||l_0==BB_T("false")){
    bbString l_value=this->m_Parse();
    return ((t_mx2_Expr*)(bbGCNew<t_mx2_LiteralExpr>(l_value,g_mx2_TOKE_0KEYWORD,((t_mx2_TypeExpr*)0),l_srcpos,this->m_EndPos())));
  }
  bbInt l_1=this->m_TokeType();
  if(l_1==g_mx2_TOKE_0KEYWORD){
    if(this->m_IsTypeIdent(this->m_Toke())){
      bbString l_ident=this->m_Parse();
      if(((this->m_Toke()==BB_T("ptr"))||(this->m_Toke()==BB_T("(")))){
        struct f3_t : public bbGCFrame{
          t_mx2_Expr* l_expr{};
          t_mx2_TypeExpr* l_type{};
          t_mx2_IdentTypeExpr* t0{};
          void gcMark(){
            bbGCMarkPtr(l_expr);
            bbGCMarkPtr(l_type);
            bbGCMarkPtr(t0);
          }
        }f3{};
        f3.l_type=this->m_ParseBaseType(f3.t0=bbGCNew<t_mx2_IdentTypeExpr>(l_ident,l_srcpos,this->m_EndPos()));
        this->m_Parse(BB_T("("));
        f3.l_expr=this->m_ParseExpr();
        this->m_Parse(BB_T(")"));
        return ((t_mx2_Expr*)(bbGCNew<t_mx2_CastExpr>(f3.l_type,f3.l_expr,l_srcpos,this->m_EndPos())));
      }
      return ((t_mx2_Expr*)(bbGCNew<t_mx2_IdentExpr>(l_ident,l_srcpos,this->m_EndPos())));
    }
  }else if(l_1==g_mx2_TOKE_0IDENT){
    return ((t_mx2_Expr*)(bbGCNew<t_mx2_IdentExpr>(this->m_ParseIdent(),l_srcpos,this->m_EndPos())));
  }else if(l_1==g_mx2_TOKE_0INTLIT||l_1==g_mx2_TOKE_0FLOATLIT){
    struct f1_t : public bbGCFrame{
      t_mx2_TypeExpr* l_typeExpr{};
      void gcMark(){
        bbGCMarkPtr(l_typeExpr);
      }
    }f1{};
    bbString l_toke=this->m_Toke();
    bbInt l_tokeType=this->m_TokeType();
    this->m_Bump();
    if(this->m_CParse(BB_T(":"))){
      f1.l_typeExpr=this->m_ParseType(((t_mx2_IdentTypeExpr*)0));
    }
    return ((t_mx2_Expr*)(bbGCNew<t_mx2_LiteralExpr>(l_toke,l_tokeType,f1.l_typeExpr,l_srcpos,this->m_EndPos())));
  }else if(l_1==g_mx2_TOKE_0STRINGLIT){
    struct f1_t : public bbGCFrame{
      t_mx2_TypeExpr* l_typeExpr{};
      void gcMark(){
        bbGCMarkPtr(l_typeExpr);
      }
    }f1{};
    bbString l_toke=this->m_Toke();
    bbInt l_tokeType=this->m_TokeType();
    this->m_Bump();
    return ((t_mx2_Expr*)(bbGCNew<t_mx2_LiteralExpr>(l_toke,l_tokeType,f1.l_typeExpr,l_srcpos,this->m_EndPos())));
  }
  this->m_Error(((BB_T("Expecting expression but encountered '")+this->m_Toke())+BB_T("'")));
  return ((t_mx2_Expr*)0);
}

t_mx2_Expr* t_mx2_Parser::m_ParsePrefixExpr(){
  bbInt l_srcpos=this->m_SrcPos();
  bbString l_0=this->m_Toke();
  if(l_0==BB_T("varptr")){
    struct f1_t : public bbGCFrame{
      t_mx2_Expr* t0{};
      void gcMark(){
        bbGCMarkPtr(t0);
      }
    }f1{};
    this->m_Bump();
    return ((t_mx2_Expr*)(bbGCNew<t_mx2_VarptrExpr>(f1.t0=this->m_ParsePrefixExpr(),l_srcpos,this->m_EndPos())));
  }else if(l_0==BB_T("+")||l_0==BB_T("-")||l_0==BB_T("~")||l_0==BB_T("not")){
    struct f1_t : public bbGCFrame{
      t_mx2_Expr* t0{};
      void gcMark(){
        bbGCMarkPtr(t0);
      }
    }f1{};
    bbString l_op=this->m_Parse();
    return ((t_mx2_Expr*)(bbGCNew<t_mx2_UnaryopExpr>(l_op,f1.t0=this->m_ParsePrefixExpr(),l_srcpos,this->m_EndPos())));
  }
  return this->m_ParsePostfixExpr();
}

t_mx2_Expr* t_mx2_Parser::m_ParsePostfixExpr(){
  struct f0_t : public bbGCFrame{
    t_mx2_Expr* l_expr{};
    void gcMark(){
      bbGCMarkPtr(l_expr);
    }
  }f0{};
  f0.l_expr=this->m_ParsePrimaryExpr();
  while(bbBool(this->m_Toke())){
    bbInt l_srcpos=this->m_SrcPos();
    bbString l_0=this->m_Toke();
    if(l_0==BB_T(".")){
      this->m_Bump();
      bbString l_ident=this->m_CParseIdent();
      if((!bbBool(l_ident)&&(this->m_Toke()==BB_T("new")))){
        l_ident=this->m_Parse();
      }
      if(!bbBool(l_ident)){
        this->m_Error(BB_T("Expecting member identifier"));
      }
      f0.l_expr=((t_mx2_Expr*)(bbGCNew<t_mx2_MemberExpr>(f0.l_expr,l_ident,l_srcpos,this->m_EndPos())));
    }else if(l_0==BB_T("->")){
      struct f2_t : public bbGCFrame{
        t_mx2_LiteralExpr* l_zero{};
        bbArray<bbGCVar<t_mx2_Expr>>* t0{};
        void gcMark(){
          bbGCMarkPtr(l_zero);
          bbGCMarkPtr(t0);
        }
      }f2{};
      this->m_Bump();
      bbString l_ident=this->m_ParseIdent();
      f2.l_zero=bbGCNew<t_mx2_LiteralExpr>(BB_T("0"),g_mx2_TOKE_0INTLIT,((t_mx2_TypeExpr*)0),l_srcpos,this->m_EndPos());
      f0.l_expr=((t_mx2_Expr*)(bbGCNew<t_mx2_IndexExpr>(f0.l_expr,f2.t0=bbArray<bbGCVar<t_mx2_Expr>>::create({((t_mx2_Expr*)(f2.l_zero))},1),l_srcpos,this->m_EndPos())));
      f0.l_expr=((t_mx2_Expr*)(bbGCNew<t_mx2_MemberExpr>(f0.l_expr,l_ident,l_srcpos,this->m_EndPos())));
    }else if(l_0==BB_T("[")){
      struct f2_t : public bbGCFrame{
        bbArray<bbGCVar<t_mx2_Expr>>* l_args{};
        void gcMark(){
          bbGCMarkPtr(l_args);
        }
      }f2{};
      this->m_Bump();
      f2.l_args=this->m_ParseExprs();
      this->m_Parse(BB_T("]"));
      f0.l_expr=((t_mx2_Expr*)(bbGCNew<t_mx2_IndexExpr>(f0.l_expr,f2.l_args,l_srcpos,this->m_EndPos())));
    }else if(l_0==BB_T("(")){
      struct f2_t : public bbGCFrame{
        bbArray<bbGCVar<t_mx2_Expr>>* l_args{};
        void gcMark(){
          bbGCMarkPtr(l_args);
        }
      }f2{};
      f2.l_args=this->m_ParseInvokeArgs();
      f0.l_expr=((t_mx2_Expr*)(bbGCNew<t_mx2_InvokeExpr>(f0.l_expr,f2.l_args,l_srcpos,this->m_EndPos())));
    }else if(l_0==BB_T("<")){
      struct f2_t : public bbGCFrame{
        t_std_collections_Stack_1Tt_mx2_TypeExpr_2* l_args{};
        bbArray<bbGCVar<t_mx2_TypeExpr>>* t0{};
        void gcMark(){
          bbGCMarkPtr(l_args);
          bbGCMarkPtr(t0);
        }
      }f2{};
      this->m_BeginTryParse();
      f2.l_args=bbGCNew<t_std_collections_Stack_1Tt_mx2_TypeExpr_2>();
      try{
        this->m_Bump();
        do{
          struct f4_t : public bbGCFrame{
            t_mx2_TypeExpr* t0{};
            void gcMark(){
              bbGCMarkPtr(t0);
            }
          }f4{};
          f2.l_args->m_Push(f4.t0=this->m_ParseType(((t_mx2_IdentTypeExpr*)0)));
        }while(!(!this->m_CParse(BB_T(","))));
        this->m_Parse(BB_T(">"));
      }catch(t_mx2_TryParseEx* ex){
        struct f3_t : public bbGCFrame{
          t_mx2_TryParseEx* l_ex{};
          void gcMark(){
            bbGCMarkPtr(l_ex);
          }
        }f3{};
        f3.l_ex=ex;
        this->m_TryParseFailed();
        break;
      }
      this->m_EndTryParse();
      f0.l_expr=((t_mx2_Expr*)(bbGCNew<t_mx2_GenericExpr>(f0.l_expr,f2.t0=f2.l_args->m_ToArray(),l_srcpos,this->m_EndPos())));
    }else{
      break;
    }
  }
  return f0.l_expr;
}

t_mx2_Expr* t_mx2_Parser::m_ParseOrderExpr(){
  struct f0_t : public bbGCFrame{
    t_mx2_Expr* l_expr{};
    void gcMark(){
      bbGCMarkPtr(l_expr);
    }
  }f0{};
  bbInt l_srcpos=this->m_SrcPos();
  f0.l_expr=this->m_ParseBitorExpr();
  for(;;){
    bbString l_0=this->m_Toke();
    if(l_0==BB_T("<=>")){
      struct f2_t : public bbGCFrame{
        t_mx2_Expr* t0{};
        void gcMark(){
          bbGCMarkPtr(t0);
        }
      }f2{};
      bbString l_op=this->m_Parse();
      f0.l_expr=((t_mx2_Expr*)(bbGCNew<t_mx2_BinaryopExpr>(l_op,f0.l_expr,f2.t0=this->m_ParseBitorExpr(),l_srcpos,this->m_EndPos())));
    }else{
      break;
    }
  }
  return f0.l_expr;
}

t_mx2_Expr* t_mx2_Parser::m_ParseOrExpr(){
  struct f0_t : public bbGCFrame{
    t_mx2_Expr* l_expr{};
    void gcMark(){
      bbGCMarkPtr(l_expr);
    }
  }f0{};
  bbInt l_srcpos=this->m_SrcPos();
  f0.l_expr=this->m_ParseAndExpr();
  for(;;){
    bbString l_0=this->m_Toke();
    if(l_0==BB_T("or")){
      struct f2_t : public bbGCFrame{
        t_mx2_Expr* t0{};
        void gcMark(){
          bbGCMarkPtr(t0);
        }
      }f2{};
      bbString l_op=this->m_Parse();
      f0.l_expr=((t_mx2_Expr*)(bbGCNew<t_mx2_BinaryopExpr>(l_op,f0.l_expr,f2.t0=this->m_ParseAndExpr(),l_srcpos,this->m_EndPos())));
    }else{
      break;
    }
  }
  return f0.l_expr;
}

t_mx2_TypeExpr* t_mx2_Parser::m_ParseNewType(){
  struct f0_t : public bbGCFrame{
    t_mx2_TypeExpr* l_type{};
    void gcMark(){
      bbGCMarkPtr(l_type);
    }
  }f0{};
  bbInt l_srcpos=this->m_SrcPos();
  f0.l_type=this->m_ParseBaseType(((t_mx2_IdentTypeExpr*)0));
  for(;;){
    bbString l_0=this->m_Toke();
    if(l_0==BB_T("[")){
      this->m_BeginTryParse();
      this->m_Bump();
      bbInt l_rank=1;
      while(this->m_CParse(BB_T(","))){
        l_rank+=1;
      }
      if(!this->m_CParse(BB_T("]"))){
        this->m_TryParseFailed();
        break;
      }
      this->m_EndTryParse();
      f0.l_type=((t_mx2_TypeExpr*)(bbGCNew<t_mx2_ArrayTypeExpr>(f0.l_type,l_rank,l_srcpos,this->m_EndPos())));
    }else if(l_0==BB_T("(")){
      this->m_BeginTryParse();
      try{
        struct f3_t : public bbGCFrame{
          t_mx2_FuncTypeExpr* l_ftype{};
          void gcMark(){
            bbGCMarkPtr(l_ftype);
          }
        }f3{};
        f3.l_ftype=this->m_ParseFuncType(f0.l_type);
        if(((this->m_Toke()!=BB_T("["))&&(this->m_Toke()!=BB_T("(")))){
          this->m_TryParseFailed();
          return f0.l_type;
        }
        this->m_EndTryParse();
        f0.l_type=((t_mx2_TypeExpr*)(f3.l_ftype));
      }catch(t_mx2_TryParseEx* ex){
        struct f3_t : public bbGCFrame{
          t_mx2_TryParseEx* l_ex{};
          void gcMark(){
            bbGCMarkPtr(l_ex);
          }
        }f3{};
        f3.l_ex=ex;
        this->m_TryParseFailed();
        break;
      }
    }else{
      break;
    }
  }
  return f0.l_type;
}

bbString t_mx2_Parser::m_ParseNamespaceIdent(){
  bbString l_ident=this->m_ParseIdent();
  while(this->m_CParse(BB_T("."))){
    l_ident+=(BB_T(".")+this->m_ParseIdent());
  }
  return l_ident;
}

t_mx2_Expr* t_mx2_Parser::m_ParseMuldivExpr(){
  struct f0_t : public bbGCFrame{
    t_mx2_Expr* l_expr{};
    void gcMark(){
      bbGCMarkPtr(l_expr);
    }
  }f0{};
  bbInt l_srcpos=this->m_SrcPos();
  f0.l_expr=this->m_ParsePrefixExpr();
  for(;;){
    bbString l_0=this->m_Toke();
    if(l_0==BB_T("*")||l_0==BB_T("/")||l_0==BB_T("mod")){
      struct f2_t : public bbGCFrame{
        t_mx2_Expr* t0{};
        void gcMark(){
          bbGCMarkPtr(t0);
        }
      }f2{};
      bbString l_op=this->m_Parse();
      f0.l_expr=((t_mx2_Expr*)(bbGCNew<t_mx2_BinaryopExpr>(l_op,f0.l_expr,f2.t0=this->m_ParsePrefixExpr(),l_srcpos,this->m_EndPos())));
    }else{
      break;
    }
  }
  return f0.l_expr;
}

bbArray<bbGCVar<t_mx2_Expr>>* t_mx2_Parser::m_ParseInvokeArgs(){
  struct f0_t : public bbGCFrame{
    t_std_collections_Stack_1Tt_mx2_Expr_2* l_exprs{};
    void gcMark(){
      bbGCMarkPtr(l_exprs);
    }
  }f0{};
  f0.l_exprs=bbGCNew<t_std_collections_Stack_1Tt_mx2_Expr_2>();
  this->m_Parse(BB_T("("));
  if(!this->m_CParse(BB_T(")"))){
    do{
      if((this->m_Toke()==BB_T(")"))){
        f0.l_exprs->m_Push(((t_mx2_Expr*)0));
        break;
      }else if((this->m_Toke()==BB_T(","))){
        f0.l_exprs->m_Push(((t_mx2_Expr*)0));
      }else{
        struct f3_t : public bbGCFrame{
          t_mx2_Expr* t0{};
          void gcMark(){
            bbGCMarkPtr(t0);
          }
        }f3{};
        f0.l_exprs->m_Push(f3.t0=this->m_ParseExpr());
      }
    }while(!(!this->m_CParse(BB_T(","))));
    this->m_Parse(BB_T(")"));
  }
  return f0.l_exprs->m_ToArray();
}

t_mx2_Expr* t_mx2_Parser::m_ParseIfThenElseExpr(){
  struct f0_t : public bbGCFrame{
    t_mx2_Expr* l_elseExpr{};
    t_mx2_Expr* l_expr{};
    t_mx2_Expr* l_thenExpr{};
    void gcMark(){
      bbGCMarkPtr(l_elseExpr);
      bbGCMarkPtr(l_expr);
      bbGCMarkPtr(l_thenExpr);
    }
  }f0{};
  bbInt l_srcpos=this->m_SrcPos();
  f0.l_expr=this->m_ParseOrExpr();
  if(!this->m_CParse(BB_T("?"))){
    return f0.l_expr;
  }
  f0.l_thenExpr=this->m_ParseIfThenElseExpr();
  this->m_Parse(BB_T("else"));
  f0.l_elseExpr=this->m_ParseOrExpr();
  return ((t_mx2_Expr*)(bbGCNew<t_mx2_IfThenElseExpr>(f0.l_expr,f0.l_thenExpr,f0.l_elseExpr,l_srcpos,this->m_EndPos())));
}

t_mx2_IfStmtExpr* t_mx2_Parser::m_ParseIf(){
  struct f0_t : public bbGCFrame{
    t_mx2_Expr* l_cond{};
    t_mx2_IfStmtExpr* l_expr{};
    t_mx2_IfStmtExpr* l_pred{};
    bbArray<bbGCVar<t_mx2_StmtExpr>>* l_stmts{};
    void gcMark(){
      bbGCMarkPtr(l_cond);
      bbGCMarkPtr(l_expr);
      bbGCMarkPtr(l_pred);
      bbGCMarkPtr(l_stmts);
    }
  }f0{};
  bbInt l_srcpos=this->m_SrcPos();
  bbBool l_block{};
  try{
    this->m_Parse(BB_T("if"));
    f0.l_cond=this->m_ParseExpr();
    this->m_CParse(BB_T("then"));
    l_block=this->m_CParseEol();
  }catch(t_mx2_ParseEx* ex){
    struct f1_t : public bbGCFrame{
      t_mx2_ParseEx* l_ex{};
      void gcMark(){
        bbGCMarkPtr(l_ex);
      }
    }f1{};
    f1.l_ex=ex;
    this->m_SkipToNextLine();
    if(!l_block){
      return bbGCNew<t_mx2_IfStmtExpr>(f0.l_cond,((bbArray<bbGCVar<t_mx2_StmtExpr>>*)0),((t_mx2_IfStmtExpr*)0),l_srcpos,this->m_EndPos());
    }
  }
  f0.l_stmts=this->m_ParseStmts(l_block);
  f0.l_expr=bbGCNew<t_mx2_IfStmtExpr>(f0.l_cond,f0.l_stmts,((t_mx2_IfStmtExpr*)0),l_srcpos,this->m_EndPos());
  f0.l_pred=f0.l_expr;
  while(((this->m_Toke()==BB_T("elseif"))||(this->m_Toke()==BB_T("else")))){
    struct f1_t : public bbGCFrame{
      t_mx2_Expr* l_cond{};
      t_mx2_IfStmtExpr* l_expr{};
      bbArray<bbGCVar<t_mx2_StmtExpr>>* l_stmts{};
      void gcMark(){
        bbGCMarkPtr(l_cond);
        bbGCMarkPtr(l_expr);
        bbGCMarkPtr(l_stmts);
      }
    }f1{};
    bbInt l_srcpos=this->m_SrcPos();
    bbString l_toke=this->m_Parse();
    if(((l_toke==BB_T("else"))&&this->m_CParse(BB_T("if")))){
      l_toke=BB_T("elseif");
    }
    try{
      if((l_toke==BB_T("elseif"))){
        f1.l_cond=this->m_ParseExpr();
        if(l_block){
          this->m_ParseEol();
        }else{
          this->m_CParse(BB_T("then"));
        }
      }else{
        if(l_block){
          this->m_ParseEol();
        }
      }
    }catch(t_mx2_ParseEx* ex){
      struct f2_t : public bbGCFrame{
        t_mx2_ParseEx* l_ex{};
        void gcMark(){
          bbGCMarkPtr(l_ex);
        }
      }f2{};
      f2.l_ex=ex;
      this->m_SkipToNextLine();
      if(!l_block){
        return f0.l_expr;
      }
    }
    f1.l_stmts=this->m_ParseStmts(l_block);
    f1.l_expr=bbGCNew<t_mx2_IfStmtExpr>(f1.l_cond,f1.l_stmts,((t_mx2_IfStmtExpr*)0),l_srcpos,this->m_EndPos());
    f0.l_pred->m_succ=f1.l_expr;
    f0.l_pred=f1.l_expr;
    if((l_toke==BB_T("else"))){
      break;
    }
  }
  try{
    if(l_block){
      if(this->m_CParse(BB_T("end"))){
        this->m_CParse(BB_T("if"));
      }else{
        this->m_Parse(BB_T("endif"));
      }
    }
    this->m_ParseEol();
  }catch(t_mx2_ParseEx* ex){
    struct f1_t : public bbGCFrame{
      t_mx2_ParseEx* l_ex{};
      void gcMark(){
        bbGCMarkPtr(l_ex);
      }
    }f1{};
    f1.l_ex=ex;
    this->m_SkipToNextLine();
  }
  f0.l_pred->m_endpos=this->m_EndPos();
  return f0.l_expr;
}

t_mx2_IdentTypeExpr* t_mx2_Parser::m_ParseIdentType(){
  bbInt l_srcpos=this->m_SrcPos();
  bbString l_ident=this->m_CParseIdent();
  if((!bbBool(l_ident)&&this->m_IsTypeIdent(this->m_Toke()))){
    l_ident=this->m_Parse();
  }
  if(!bbBool(l_ident)){
    this->m_Error(BB_T("Expecting type identifier"));
  }
  return bbGCNew<t_mx2_IdentTypeExpr>(l_ident,l_srcpos,this->m_EndPos());
}

bbString t_mx2_Parser::m_ParseIdent(){
  if((this->m_CParse(BB_T("@"))&&bbBool(this->m_TokeType()))){
    return (BB_T("@")+this->m_Parse());
  }
  if((this->m_TokeType()!=g_mx2_TOKE_0IDENT)){
    this->m_Error(BB_T("Expecting identifier"));
  }
  bbString l_ident=this->m_Toke();
  this->m_Bump();
  return l_ident;
}

bbArray<bbString>* t_mx2_Parser::m_ParseGenArgs(){
  struct f0_t : public bbGCFrame{
    t_std_collections_Stack_1s* l_args{};
    void gcMark(){
      bbGCMarkPtr(l_args);
    }
  }f0{};
  if(!this->m_CParse(BB_T("<"))){
    return ((bbArray<bbString>*)0);
  }
  f0.l_args=bbGCNew<t_std_collections_Stack_1s>();
  do{
    f0.l_args->m_Push(this->m_ParseIdent());
  }while(!(!this->m_CParse(BB_T(","))));
  this->m_Parse(BB_T(">"));
  return f0.l_args->m_ToArray();
}

t_mx2_FuncTypeExpr* t_mx2_Parser::m_ParseFuncType(t_mx2_TypeExpr* l_retType){
  struct f0_t : public bbGCFrame{
    t_std_collections_Stack_1Tt_mx2_VarDecl_2* l_params{};
    bbArray<bbGCVar<t_mx2_VarDecl>>* t0{};
    void gcMark(){
      bbGCMarkPtr(l_params);
      bbGCMarkPtr(t0);
    }
  }f0{};
  this->m_Parse(BB_T("("));
  f0.l_params=bbGCNew<t_std_collections_Stack_1Tt_mx2_VarDecl_2>();
  if(!this->m_CParse(BB_T(")"))){
    do{
      struct f2_t : public bbGCFrame{
        t_mx2_VarDecl* l_decl{};
        void gcMark(){
          bbGCMarkPtr(l_decl);
        }
      }f2{};
      f2.l_decl=bbGCNew<t_mx2_VarDecl>();
      f2.l_decl->m_srcpos=this->m_SrcPos();
      f2.l_decl->m_kind=BB_T("param");
      f2.l_decl->m_flags=g_mx2_DECL_0PUBLIC;
      bbString l_ident=this->m_CParseIdent();
      if(bbBool(l_ident)){
        if(this->m_CParse(BB_T(":"))){
          f2.l_decl->m_ident=l_ident;
          f2.l_decl->m_type=this->m_ParseType(((t_mx2_IdentTypeExpr*)0));
          if(this->m_CParse(BB_T("="))){
            f2.l_decl->m_init=this->m_ParseExpr();
          }
        }else{
          struct f4_t : public bbGCFrame{
            t_mx2_IdentTypeExpr* t0{};
            void gcMark(){
              bbGCMarkPtr(t0);
            }
          }f4{};
          f2.l_decl->m_type=this->m_ParseType(f4.t0=bbGCNew<t_mx2_IdentTypeExpr>(l_ident,f2.l_decl->m_srcpos,this->m_EndPos()));
        }
      }else{
        f2.l_decl->m_type=this->m_ParseType(((t_mx2_IdentTypeExpr*)0));
      }
      f2.l_decl->m_endpos=this->m_EndPos();
      f0.l_params->m_Push(f2.l_decl);
    }while(!(!this->m_CParse(BB_T(","))));
    this->m_Parse(BB_T(")"));
  }
  return bbGCNew<t_mx2_FuncTypeExpr>(l_retType,f0.t0=f0.l_params->m_ToArray(),l_retType->m_srcpos,this->m_EndPos());
}

t_mx2_FuncDecl* t_mx2_Parser::m_ParseFunc(bbInt l_flags){
  struct f0_t : public bbGCFrame{
    t_mx2_FuncDecl* l_decl{};
    bbArray<bbString>* l_genArgs{};
    t_mx2_FuncTypeExpr* l_type{};
    t_mx2_Expr* l_whereExpr{};
    void gcMark(){
      bbGCMarkPtr(l_decl);
      bbGCMarkPtr(l_genArgs);
      bbGCMarkPtr(l_type);
      bbGCMarkPtr(l_whereExpr);
    }
  }f0{};
  bbInt l_srcpos=this->m_SrcPos();
  bbString l_kind=this->m_Parse();
  bbString l_docs=this->m_Docs();
  bbString l_ident=BB_T("?????");
  bbString l_symbol{};
  try{
    if(l_kind==BB_T("lambda")){
    }else if(l_kind==BB_T("getter")){
      l_kind=BB_T("method");
      l_flags|=g_mx2_DECL_0GETTER;
    }else if(l_kind==BB_T("setter")){
      l_kind=BB_T("method");
      l_flags|=g_mx2_DECL_0SETTER;
    }else if(l_kind==BB_T("operator")){
      l_kind=BB_T("method");
      l_flags|=g_mx2_DECL_0OPERATOR;
      bbString l_0=this->m_Toke();
      if(l_0==BB_T("*")||l_0==BB_T("/")||l_0==BB_T("+")||l_0==BB_T("-")||l_0==BB_T("&")||l_0==BB_T("|")||l_0==BB_T("~")){
        l_ident=this->m_Parse();
      }else if(l_0==BB_T("*=")||l_0==BB_T("/=")||l_0==BB_T("+=")||l_0==BB_T("-=")||l_0==BB_T("&=")||l_0==BB_T("|=")||l_0==BB_T("~=")){
        l_ident=this->m_Parse();
      }else if(l_0==BB_T("<")||l_0==BB_T(">")||l_0==BB_T("<=")||l_0==BB_T(">=")||l_0==BB_T("=")||l_0==BB_T("<>")||l_0==BB_T("<=>")){
        l_ident=this->m_Parse();
      }else if(l_0==BB_T("cast")){
        l_ident=this->m_Parse();
      }else if(l_0==BB_T("[")){
        this->m_Bump();
        this->m_Parse(BB_T("]"));
        if(this->m_CParse(BB_T("="))){
          l_ident=BB_T("[]=");
        }else{
          l_ident=BB_T("[]");
        }
      }else{
        this->m_Error(BB_T("Operator must be one of: * / + - & | ~ [] < > <= >= = <> <=>"));
      }
    }else if(l_kind==BB_T("method")){
      if(this->m_CParse(BB_T("new"))){
        l_ident=BB_T("new");
      }else{
        l_ident=this->m_ParseIdent();
      }
    }else{
      l_ident=this->m_ParseIdent();
    }
    f0.l_genArgs=this->m_ParseGenArgs();
    if(this->m_CParse(BB_T(":"))){
      f0.l_type=bb_object_cast<t_mx2_FuncTypeExpr*>(this->m_ParseType(((t_mx2_IdentTypeExpr*)0)));
      if(!bbBool(f0.l_type)){
        this->m_Error(BB_T("Expecting function type"));
      }
    }else{
      struct f2_t : public bbGCFrame{
        t_mx2_TypeExpr* t0{};
        void gcMark(){
          bbGCMarkPtr(t0);
        }
      }f2{};
      f0.l_type=this->m_ParseFuncType(f2.t0=((t_mx2_TypeExpr*)(bbGCNew<t_mx2_IdentTypeExpr>(BB_T("void"),this->m_SrcPos(),this->m_SrcPos()))));
    }
    if(!bbBool((l_flags&g_mx2_DECL_0EXTERN))){
      {
        bbInt l_1=bbInt(0);
        bbInt l_2=f0.l_type->m_params->length();
        for(;(l_1<l_2);l_1+=1){
          struct f4_t : public bbGCFrame{
            t_mx2_VarDecl* l_param{};
            void gcMark(){
              bbGCMarkPtr(l_param);
            }
          }f4{};
          f4.l_param=f0.l_type->m_params->at(l_1);
          if(!bbBool(f4.l_param->m_ident)){
            this->m_Error(BB_T("Missing parameter identifier"));
          }
        }
      }
    }
    if(l_kind==BB_T("property")){
      if((f0.l_type->m_params->length()==bbInt(0))){
        l_kind=BB_T("method");
        l_flags|=g_mx2_DECL_0GETTER;
      }else if((f0.l_type->m_params->length()==1)){
        l_kind=BB_T("method");
        l_flags|=g_mx2_DECL_0SETTER;
      }else{
        this->m_Error(BB_T("Properties must have 0 or 1 parameters"));
      }
    }else if(l_kind==BB_T("method")){
      if(bbBool((l_flags&g_mx2_DECL_0GETTER))){
        if((f0.l_type->m_params->length()!=bbInt(0))){
          this->m_Error(BB_T("Getters must have 0 parameters"));
        }
      }else if(bbBool((l_flags&g_mx2_DECL_0SETTER))){
        if((f0.l_type->m_params->length()!=1)){
          this->m_Error(BB_T("Setters must have 1 parameter"));
        }
      }
    }
    bbString l_3=this->m_Toke();
    if(l_3==BB_T("virtual")||l_3==BB_T("abstract")||l_3==BB_T("override")||l_3==BB_T("final")||l_3==BB_T("extension")){
      if(bbBool((l_flags&g_mx2_DECL_0IFACEMEMBER))){
        this->m_Error(BB_T("Interface methods are implictly abstract"));
      }
      if(this->m_CParse(BB_T("virtual"))){
        l_flags|=g_mx2_DECL_0VIRTUAL;
      }else if(this->m_CParse(BB_T("abstract"))){
        l_flags|=g_mx2_DECL_0ABSTRACT;
      }else if(this->m_CParse(BB_T("override"))){
        l_flags|=g_mx2_DECL_0OVERRIDE;
        if(this->m_CParse(BB_T("final"))){
          l_flags|=g_mx2_DECL_0FINAL;
        }
      }else if(this->m_CParse(BB_T("final"))){
        l_flags|=g_mx2_DECL_0FINAL;
      }else if(this->m_CParse(BB_T("extension"))){
        if(((l_kind!=BB_T("method"))||!bbBool((l_flags&g_mx2_DECL_0EXTERN)))){
          this->m_Error(BB_T("Only extern methods can be declared 'Extension'"));
        }
        l_flags|=g_mx2_DECL_0EXTENSION;
      }
    }
    if(this->m_CParse(BB_T("="))){
      if(!bbBool((l_flags&g_mx2_DECL_0EXTERN))){
        this->m_Error(BB_T("Non-extern declarations cannot be assigned an extern symbol"));
      }
      l_symbol=this->m_ParseString();
    }
    if(this->m_CParse(BB_T("where"))){
      f0.l_whereExpr=this->m_ParseExpr();
    }
    if(this->m_CParse(BB_T("default"))){
      if(!bbBool((l_flags&g_mx2_DECL_0IFACEMEMBER))){
        this->m_Error(BB_T("Only interface methods can be declared 'Default'"));
      }
      l_flags&=~g_mx2_DECL_0ABSTRACT;
      l_flags|=g_mx2_DECL_0DEFAULT;
      if(this->m_CParse(BB_T("virtual"))){
        l_flags|=g_mx2_DECL_0VIRTUAL;
      }
    }
    this->m_ParseEol();
  }catch(t_mx2_ParseEx* ex){
    struct f1_t : public bbGCFrame{
      t_mx2_ParseEx* l_ex{};
      void gcMark(){
        bbGCMarkPtr(l_ex);
      }
    }f1{};
    f1.l_ex=ex;
    this->m_SkipToNextLine();
  }
  f0.l_decl=bbGCNew<t_mx2_FuncDecl>();
  f0.l_decl->m_srcpos=l_srcpos;
  f0.l_decl->m_kind=l_kind;
  f0.l_decl->m_docs=l_docs;
  f0.l_decl->m_ident=l_ident;
  f0.l_decl->m_flags=l_flags;
  f0.l_decl->m_genArgs=f0.l_genArgs;
  f0.l_decl->m_type=f0.l_type;
  f0.l_decl->m_whereExpr=f0.l_whereExpr;
  f0.l_decl->m_symbol=l_symbol;
  if((bbBool((l_flags&(g_mx2_DECL_0EXTERN|g_mx2_DECL_0ABSTRACT)))&&!bbBool((l_flags&g_mx2_DECL_0DEFAULT)))){
    f0.l_decl->m_endpos=this->m_EndPos();
    return f0.l_decl;
  }
  f0.l_decl->m_stmts=this->m_ParseStmts(true);
  try{
    bbString l_4=this->m_Toke();
    if(l_4==BB_T("setter")){
      if(!bbBool((l_flags&g_mx2_DECL_0GETTER))){
        this->m_Error(BB_T("Setter must appear after getter"));
      }
    }else if(l_4==BB_T("getter")){
      if(!bbBool((l_flags&g_mx2_DECL_0SETTER))){
        this->m_Error(BB_T("Getter must appear after setter"));
      }
    }else{
      this->m_Parse(BB_T("end"));
      this->m_CParse(l_kind);
      if((l_kind!=BB_T("lambda"))){
        this->m_ParseEol();
      }
    }
  }catch(t_mx2_ParseEx* ex){
    struct f1_t : public bbGCFrame{
      t_mx2_ParseEx* l_ex{};
      void gcMark(){
        bbGCMarkPtr(l_ex);
      }
    }f1{};
    f1.l_ex=ex;
    if((l_kind==BB_T("lambda"))){
      this->m_SkipToEol();
    }else{
      this->m_SkipToNextLine();
    }
  }
  f0.l_decl->m_endpos=this->m_EndPos();
  return f0.l_decl;
}

t_mx2_ForStmtExpr* t_mx2_Parser::m_ParseFor(){
  struct f0_t : public bbGCFrame{
    t_mx2_Expr* l_cond{};
    t_mx2_Expr* l_incr{};
    t_mx2_Expr* l_init{};
    bbArray<bbGCVar<t_mx2_StmtExpr>>* l_stmts{};
    t_mx2_Expr* l_varExpr{};
    t_mx2_TypeExpr* l_varType{};
    void gcMark(){
      bbGCMarkPtr(l_cond);
      bbGCMarkPtr(l_incr);
      bbGCMarkPtr(l_init);
      bbGCMarkPtr(l_stmts);
      bbGCMarkPtr(l_varExpr);
      bbGCMarkPtr(l_varType);
    }
  }f0{};
  bbInt l_srcpos=this->m_SrcPos();
  bbString l_varIdent{};
  bbString l_kind{};
  try{
    this->m_Parse(BB_T("for"));
    if(this->m_CParse(BB_T("local"))){
      l_varIdent=this->m_ParseIdent();
      if(this->m_CParse(BB_T(":"))){
        f0.l_varType=this->m_ParseType(((t_mx2_IdentTypeExpr*)0));
        this->m_Parse(BB_T("="));
      }else{
        this->m_Parse(BB_T(":="));
      }
    }else{
      f0.l_varExpr=this->m_ParsePostfixExpr();
      this->m_Parse(BB_T("="));
    }
    if(this->m_CParse(BB_T("eachin"))){
      f0.l_init=this->m_ParseExpr();
      l_kind=BB_T("eachin");
    }else{
      f0.l_init=this->m_ParseExpr();
      if(((this->m_Toke()!=BB_T("to"))&&(this->m_Toke()!=BB_T("until")))){
        this->m_Error(BB_T("Expecting 'To' or 'Until'"));
      }
      l_kind=this->m_Toke();
      this->m_Bump();
      f0.l_cond=this->m_ParseExpr();
      if(this->m_CParse(BB_T("step"))){
        f0.l_incr=this->m_ParseExpr();
      }
    }
    this->m_ParseEol();
  }catch(t_mx2_ParseEx* ex){
    struct f1_t : public bbGCFrame{
      t_mx2_ParseEx* l_ex{};
      void gcMark(){
        bbGCMarkPtr(l_ex);
      }
    }f1{};
    f1.l_ex=ex;
    this->m_SkipToNextLine();
  }
  f0.l_stmts=this->m_ParseStmts(true);
  try{
    if(this->m_CParse(BB_T("end"))){
      this->m_CParse(BB_T("for"));
    }else{
      this->m_Parse(BB_T("next"));
    }
    this->m_ParseEol();
  }catch(t_mx2_ParseEx* ex){
    struct f1_t : public bbGCFrame{
      t_mx2_ParseEx* l_ex{};
      void gcMark(){
        bbGCMarkPtr(l_ex);
      }
    }f1{};
    f1.l_ex=ex;
    this->m_SkipToNextLine();
  }
  return bbGCNew<t_mx2_ForStmtExpr>(l_varIdent,f0.l_varType,f0.l_varExpr,l_kind,f0.l_init,f0.l_cond,f0.l_incr,f0.l_stmts,l_srcpos,this->m_EndPos());
}

t_mx2_FileDecl* t_mx2_Parser::m_ParseFile(bbString l_ident,bbString l_srcPath,t_std_collections_Map_1ss* l_ppsyms){
  this->m__0ppsyms=l_ppsyms;
  this->m__0fdecl=bbGCNew<t_mx2_FileDecl>();
  this->m__0fdecl->m_ident=l_ident;
  this->m__0fdecl->m_path=l_srcPath;
  this->m__0fdecl->m_nmspace=bbString{};
  bbString l_source=g_std_stringio_LoadString(l_srcPath);
  this->m__0toker=bbGCNew<t_mx2_Toker>(l_source);
  g_mx2_PNode_parsing=this->m__0fdecl;
  this->m_Bump();
  this->m_CParseEol();
  this->m__0fdecl->m_members=this->m_ParseDecls(g_mx2_DECL_0PUBLIC,true);
  if(!bbBool(this->m__0fdecl->m_nmspace)){
    this->m__0fdecl->m_nmspace=BB_T("default");
  }
  this->m__0fdecl->m_usings=this->m__0usings->m_ToArray();
  this->m__0fdecl->m_imports=this->m__0imports->m_ToArray();
  this->m__0fdecl->m_errors=this->m__0errors->m_ToArray();
  this->m__0fdecl->m_endpos=this->m_EndPos();
  g_mx2_PNode_parsing=((t_mx2_FileDecl*)0);
  return this->m__0fdecl;
}

t_mx2_Expr* t_mx2_Parser::m_ParseExtendsExpr(){
  struct f0_t : public bbGCFrame{
    t_mx2_Expr* l_expr{};
    void gcMark(){
      bbGCMarkPtr(l_expr);
    }
  }f0{};
  bbInt l_srcpos=this->m_SrcPos();
  f0.l_expr=this->m_ParseCompareExpr();
  for(;;){
    bbString l_0=this->m_Toke();
    if(l_0==BB_T("extends")||l_0==BB_T("implements")){
      struct f2_t : public bbGCFrame{
        t_mx2_TypeExpr* t0{};
        void gcMark(){
          bbGCMarkPtr(t0);
        }
      }f2{};
      bbString l_op=this->m_Parse();
      f0.l_expr=((t_mx2_Expr*)(bbGCNew<t_mx2_ExtendsExpr>(l_op,f0.l_expr,f2.t0=this->m_ParseType(((t_mx2_IdentTypeExpr*)0)),l_srcpos,this->m_EndPos())));
    }else{
      break;
    }
  }
  return f0.l_expr;
}

bbArray<bbGCVar<t_mx2_Expr>>* t_mx2_Parser::m_ParseExprs(){
  struct f0_t : public bbGCFrame{
    t_std_collections_Stack_1Tt_mx2_Expr_2* l_exprs{};
    void gcMark(){
      bbGCMarkPtr(l_exprs);
    }
  }f0{};
  f0.l_exprs=bbGCNew<t_std_collections_Stack_1Tt_mx2_Expr_2>();
  do{
    struct f1_t : public bbGCFrame{
      t_mx2_Expr* t0{};
      void gcMark(){
        bbGCMarkPtr(t0);
      }
    }f1{};
    f0.l_exprs->m_Push(f1.t0=this->m_ParseExpr());
  }while(!(!this->m_CParse(BB_T(","))));
  return f0.l_exprs->m_ToArray();
}

t_mx2_StmtExpr* t_mx2_Parser::m_ParseExprStmt(){
  struct f0_t : public bbGCFrame{
    t_mx2_Expr* l_expr{};
    t_mx2_InvokeExpr* l_iexpr{};
    void gcMark(){
      bbGCMarkPtr(l_expr);
      bbGCMarkPtr(l_iexpr);
    }
  }f0{};
  bbInt l_srcpos=this->m_SrcPos();
  f0.l_expr=this->m_ParsePostfixExpr();
  bbString l_0=this->m_Toke();
  if(l_0==BB_T("=")||l_0==BB_T("*=")||l_0==BB_T("/=")||l_0==BB_T("+=")||l_0==BB_T("-=")||l_0==BB_T("&=")||l_0==BB_T("|=")||l_0==BB_T("~=")){
    struct f1_t : public bbGCFrame{
      t_mx2_Expr* l_rhs{};
      void gcMark(){
        bbGCMarkPtr(l_rhs);
      }
    }f1{};
    bbString l_op=this->m_Parse();
    f1.l_rhs=this->m_ParseExpr();
    return ((t_mx2_StmtExpr*)(bbGCNew<t_mx2_AssignStmtExpr>(l_op,f0.l_expr,f1.l_rhs,l_srcpos,this->m_EndPos())));
  }
  f0.l_iexpr=bb_object_cast<t_mx2_InvokeExpr*>(f0.l_expr);
  if(bbBool(f0.l_iexpr)){
    struct f1_t : public bbGCFrame{
      t_mx2_MemberExpr* l_mexpr{};
      void gcMark(){
        bbGCMarkPtr(l_mexpr);
      }
    }f1{};
    f1.l_mexpr=bb_object_cast<t_mx2_MemberExpr*>(f0.l_iexpr->m_expr);
    if((bbBool(f1.l_mexpr)&&(f1.l_mexpr->m_ident==BB_T("new")))){
      return ((t_mx2_StmtExpr*)(bbGCNew<t_mx2_InvokeNewStmtExpr>(f1.l_mexpr->m_expr,f0.l_iexpr->m_args,l_srcpos,this->m_EndPos())));
    }
  }
  return ((t_mx2_StmtExpr*)(bbGCNew<t_mx2_EvalStmtExpr>(f0.l_expr,l_srcpos,this->m_EndPos())));
}

t_mx2_Expr* t_mx2_Parser::m_ParseExpr(){
  return this->m_ParseIfThenElseExpr();
}

t_mx2_Expr* t_mx2_Parser::m_ParseEqualsExpr(){
  struct f0_t : public bbGCFrame{
    t_mx2_Expr* l_expr{};
    void gcMark(){
      bbGCMarkPtr(l_expr);
    }
  }f0{};
  bbInt l_srcpos=this->m_SrcPos();
  f0.l_expr=this->m_ParseExtendsExpr();
  for(;;){
    bbString l_0=this->m_Toke();
    if(l_0==BB_T("=")||l_0==BB_T("<>")){
      struct f2_t : public bbGCFrame{
        t_mx2_Expr* t0{};
        void gcMark(){
          bbGCMarkPtr(t0);
        }
      }f2{};
      bbString l_op=this->m_Parse();
      f0.l_expr=((t_mx2_Expr*)(bbGCNew<t_mx2_BinaryopExpr>(l_op,f0.l_expr,f2.t0=this->m_ParseExtendsExpr(),l_srcpos,this->m_EndPos())));
    }else{
      break;
    }
  }
  return f0.l_expr;
}

void t_mx2_Parser::m_ParseEol(){
  if((bbBool(this->m_TokeType())&&(this->m_TokeType()!=g_mx2_TOKE_0EOL))){
    this->m_Error(BB_T("Expecting end of line"));
  }
  this->m_EatEols();
}

t_mx2_EnumDecl* t_mx2_Parser::m_ParseEnum(bbInt l_flags){
  struct f0_t : public bbGCFrame{
    t_mx2_EnumDecl* l_decl{};
    t_std_collections_Stack_1Tt_mx2_Decl_2* l_members{};
    void gcMark(){
      bbGCMarkPtr(l_decl);
      bbGCMarkPtr(l_members);
    }
  }f0{};
  f0.l_decl=bbGCNew<t_mx2_EnumDecl>();
  f0.l_decl->m_srcpos=this->m_SrcPos();
  f0.l_decl->m_flags=l_flags;
  f0.l_decl->m_kind=this->m_Parse();
  f0.l_decl->m_docs=this->m_Docs();
  try{
    f0.l_decl->m_ident=this->m_ParseIdent();
    if(this->m_CParse(BB_T("extends"))){
      f0.l_decl->m_superType=this->m_ParseType(((t_mx2_IdentTypeExpr*)0));
    }
    if(this->m_CParse(BB_T("="))){
      if(!bbBool((l_flags&g_mx2_DECL_0EXTERN))){
        this->m_Error(BB_T("Non-extern declaration cannot be assigned an extern symbol"));
      }
      f0.l_decl->m_symbol=this->m_ParseString();
    }
    this->m_ParseEol();
  }catch(t_mx2_ParseEx* ex){
    struct f1_t : public bbGCFrame{
      t_mx2_ParseEx* l_ex{};
      void gcMark(){
        bbGCMarkPtr(l_ex);
      }
    }f1{};
    f1.l_ex=ex;
    this->m_SkipToNextLine();
  }
  f0.l_members=bbGCNew<t_std_collections_Stack_1Tt_mx2_Decl_2>();
  while((this->m_TokeType()==g_mx2_TOKE_0IDENT)){
    try{
      struct f2_t : public bbGCFrame{
        t_mx2_VarDecl* l_decl{};
        void gcMark(){
          bbGCMarkPtr(l_decl);
        }
      }f2{};
      f2.l_decl=bbGCNew<t_mx2_VarDecl>();
      f2.l_decl->m_srcpos=this->m_SrcPos();
      f2.l_decl->m_kind=BB_T("const");
      f2.l_decl->m_flags=(g_mx2_DECL_0PUBLIC|(l_flags&g_mx2_DECL_0EXTERN));
      f2.l_decl->m_ident=this->m_ParseIdent();
      f2.l_decl->m_docs=this->m_Docs();
      if(bbBool((l_flags&g_mx2_DECL_0EXTERN))){
        if(this->m_CParse(BB_T("="))){
          f2.l_decl->m_symbol=this->m_ParseString();
        }
      }else{
        if(this->m_CParse(BB_T("="))){
          f2.l_decl->m_init=this->m_ParseExpr();
        }
      }
      f2.l_decl->m_endpos=this->m_EndPos();
      f0.l_members->m_Push(((t_mx2_Decl*)(f2.l_decl)));
      if(!this->m_CParse(BB_T(","))){
        this->m_ParseEol();
      }else{
        this->m_CParseEol();
      }
    }catch(t_mx2_ParseEx* ex){
      struct f2_t : public bbGCFrame{
        t_mx2_ParseEx* l_ex{};
        void gcMark(){
          bbGCMarkPtr(l_ex);
        }
      }f2{};
      f2.l_ex=ex;
      this->m_SkipToNextLine();
    }
  }
  f0.l_decl->m_members=f0.l_members->m_ToArray();
  try{
    this->m_Parse(BB_T("end"));
    this->m_CParse(BB_T("enum"));
    this->m_ParseEol();
  }catch(t_mx2_ParseEx* ex){
    struct f1_t : public bbGCFrame{
      t_mx2_ParseEx* l_ex{};
      void gcMark(){
        bbGCMarkPtr(l_ex);
      }
    }f1{};
    f1.l_ex=ex;
    this->m_SkipToNextLine();
  }
  f0.l_decl->m_endpos=this->m_EndPos();
  return f0.l_decl;
}

bbArray<bbGCVar<t_mx2_Decl>>* t_mx2_Parser::m_ParseDecls(bbInt l_flags,bbBool l_fileScope){
  struct f0_t : public bbGCFrame{
    t_std_collections_Stack_1Tt_mx2_Decl_2* l_decls{};
    void gcMark(){
      bbGCMarkPtr(l_decls);
    }
  }f0{};
  f0.l_decls=bbGCNew<t_std_collections_Stack_1Tt_mx2_Decl_2>();
  while(bbBool(this->m_Toke())){
    try{
      bbString l_0=this->m_Toke();
      if(l_0==BB_T("end")){
        break;
      }else if(l_0==BB_T("const")){
        this->m_ParseVars(f0.l_decls,l_flags);
      }else if(l_0==BB_T("global")){
        this->m_ParseVars(f0.l_decls,l_flags);
      }else if(l_0==BB_T("field")){
        if(l_fileScope){
          this->m_Error(BB_T("Fields can only be declared inside a class, struct or interface"));
        }
        this->m_ParseVars(f0.l_decls,l_flags);
      }else if(l_0==BB_T("local")){
        this->m_Error(BB_T("Locals can only be declared in a statement block"));
      }else if(l_0==BB_T("alias")){
        this->m_ParseAliases(f0.l_decls,l_flags);
      }else if(l_0==BB_T("class")){
        struct f3_t : public bbGCFrame{
          t_mx2_Decl* t0{};
          void gcMark(){
            bbGCMarkPtr(t0);
          }
        }f3{};
        f0.l_decls->m_Push(f3.t0=((t_mx2_Decl*)(this->m_ParseClass(l_flags))));
      }else if(l_0==BB_T("struct")){
        struct f3_t : public bbGCFrame{
          t_mx2_Decl* t0{};
          void gcMark(){
            bbGCMarkPtr(t0);
          }
        }f3{};
        f0.l_decls->m_Push(f3.t0=((t_mx2_Decl*)(this->m_ParseClass(l_flags))));
      }else if(l_0==BB_T("interface")){
        struct f3_t : public bbGCFrame{
          t_mx2_Decl* t0{};
          void gcMark(){
            bbGCMarkPtr(t0);
          }
        }f3{};
        f0.l_decls->m_Push(f3.t0=((t_mx2_Decl*)(this->m_ParseClass(l_flags))));
      }else if(l_0==BB_T("enum")){
        struct f3_t : public bbGCFrame{
          t_mx2_Decl* t0{};
          void gcMark(){
            bbGCMarkPtr(t0);
          }
        }f3{};
        f0.l_decls->m_Push(f3.t0=((t_mx2_Decl*)(this->m_ParseEnum(l_flags))));
      }else if(l_0==BB_T("function")){
        struct f3_t : public bbGCFrame{
          t_mx2_Decl* t0{};
          void gcMark(){
            bbGCMarkPtr(t0);
          }
        }f3{};
        f0.l_decls->m_Push(f3.t0=((t_mx2_Decl*)(this->m_ParseFunc(l_flags))));
      }else if(l_0==BB_T("method")){
        struct f3_t : public bbGCFrame{
          t_mx2_Decl* t0{};
          void gcMark(){
            bbGCMarkPtr(t0);
          }
        }f3{};
        if(l_fileScope){
          this->m_Error(BB_T("Methods can only be declared inside a class, struct or interface"));
        }
        f0.l_decls->m_Push(f3.t0=((t_mx2_Decl*)(this->m_ParseFunc(l_flags))));
      }else if(l_0==BB_T("operator")){
        struct f3_t : public bbGCFrame{
          t_mx2_Decl* t0{};
          void gcMark(){
            bbGCMarkPtr(t0);
          }
        }f3{};
        if(l_fileScope){
          this->m_Error(BB_T("Operators can only be declared inside a class, struct or interface"));
        }
        f0.l_decls->m_Push(f3.t0=((t_mx2_Decl*)(this->m_ParseFunc(l_flags))));
      }else if(l_0==BB_T("property")){
        struct f3_t : public bbGCFrame{
          t_mx2_Decl* t0{};
          void gcMark(){
            bbGCMarkPtr(t0);
          }
        }f3{};
        if(l_fileScope){
          this->m_Error(BB_T("Properties can only be declared inside a class, struct or interface"));
        }
        f0.l_decls->m_Push(f3.t0=((t_mx2_Decl*)(this->m_ParseProperty(l_flags))));
      }else if(l_0==BB_T("namespace")){
        if(((!l_fileScope||bbBool(f0.l_decls->m_Length()))||bbBool(this->m__0usings->m_Length()))){
          this->m_Error(BB_T("'Namespace' must appear at the start of the file"));
        }
        if(bbBool(this->m__0fdecl->m_nmspace)){
          this->m_Error(BB_T("Duplicate namespace declaration"));
        }
        this->m_Bump();
        this->m__0fdecl->m_docs=this->m_Docs();
        this->m__0fdecl->m_nmspace=this->m_ParseNamespaceIdent();
        this->m_ParseEol();
      }else if(l_0==BB_T("using")){
        if((!l_fileScope||bbBool(f0.l_decls->m_Length()))){
          this->m_Error(BB_T("Usings must appear before any declarations in a file"));
        }
        this->m_Bump();
        this->m__0usings->m_Push(this->m_ParseUsingIdent());
        this->m_ParseEol();
      }else if(l_0==BB_T("extern")){
        if(!l_fileScope){
          this->m_Error(BB_T("'Extern' must appear at file scope"));
        }
        this->m_Bump();
        l_flags=((l_flags&~g_mx2_DECL_0ACCESSMASK)|g_mx2_DECL_0EXTERN);
        if(this->m_CParse(BB_T("private"))){
          l_flags|=g_mx2_DECL_0PRIVATE;
        }else{
          this->m_CParse(BB_T("public"));
          l_flags|=g_mx2_DECL_0PUBLIC;
        }
        this->m_ParseEol();
      }else if(l_0==BB_T("public")||l_0==BB_T("private")){
        l_flags&=~g_mx2_DECL_0ACCESSMASK;
        if(l_fileScope){
          l_flags&=~g_mx2_DECL_0EXTERN;
        }
        if(this->m_CParse(BB_T("private"))){
          l_flags|=g_mx2_DECL_0PRIVATE;
        }else{
          this->m_Parse(BB_T("public"));
          l_flags|=g_mx2_DECL_0PUBLIC;
        }
        this->m_ParseEol();
      }else if(l_0==BB_T("protected")){
        if(l_fileScope){
          this->m_Error(BB_T("'Protected' can only be used in a class, struct or interface"));
        }
        this->m_Bump();
        l_flags=((l_flags&~g_mx2_DECL_0ACCESSMASK)|g_mx2_DECL_0PROTECTED);
        this->m_ParseEol();
      }else{
        this->m_Error(((BB_T("Unexpected token '")+this->m_Toke())+BB_T("'")));
      }
    }catch(t_mx2_ParseEx* ex){
      struct f2_t : public bbGCFrame{
        t_mx2_ParseEx* l_ex{};
        void gcMark(){
          bbGCMarkPtr(l_ex);
        }
      }f2{};
      f2.l_ex=ex;
      this->m_SkipToNextLine();
    }
  }
  return f0.l_decls->m_ToArray();
}

t_mx2_Expr* t_mx2_Parser::m_ParseCompareExpr(){
  struct f0_t : public bbGCFrame{
    t_mx2_Expr* l_expr{};
    void gcMark(){
      bbGCMarkPtr(l_expr);
    }
  }f0{};
  bbInt l_srcpos=this->m_SrcPos();
  f0.l_expr=this->m_ParseOrderExpr();
  for(;;){
    bbString l_0=this->m_Toke();
    if(l_0==BB_T("<")||l_0==BB_T(">")||l_0==BB_T("<=")||l_0==BB_T(">=")){
      struct f2_t : public bbGCFrame{
        t_mx2_Expr* t0{};
        void gcMark(){
          bbGCMarkPtr(t0);
        }
      }f2{};
      bbString l_op=this->m_Parse();
      f0.l_expr=((t_mx2_Expr*)(bbGCNew<t_mx2_BinaryopExpr>(l_op,f0.l_expr,f2.t0=this->m_ParseOrderExpr(),l_srcpos,this->m_EndPos())));
    }else{
      break;
    }
  }
  return f0.l_expr;
}

t_mx2_ClassDecl* t_mx2_Parser::m_ParseClass(bbInt l_flags){
  struct f0_t : public bbGCFrame{
    t_mx2_ClassDecl* l_decl{};
    void gcMark(){
      bbGCMarkPtr(l_decl);
    }
  }f0{};
  f0.l_decl=bbGCNew<t_mx2_ClassDecl>();
  f0.l_decl->m_srcpos=this->m_SrcPos();
  f0.l_decl->m_kind=this->m_Parse();
  f0.l_decl->m_docs=this->m_Docs();
  f0.l_decl->m_ident=BB_T("?????");
  try{
    f0.l_decl->m_ident=this->m_ParseIdent();
    f0.l_decl->m_genArgs=this->m_ParseGenArgs();
    if(this->m_CParse(BB_T("extends"))){
      if(((f0.l_decl->m_kind==BB_T("interface"))||(f0.l_decl->m_kind==BB_T("protocol")))){
        f0.l_decl->m_ifaceTypes=this->m_ParseTypes();
      }else{
        f0.l_decl->m_superType=this->m_ParseType(((t_mx2_IdentTypeExpr*)0));
      }
    }
    if(this->m_CParse(BB_T("implements"))){
      if(((f0.l_decl->m_kind!=BB_T("class"))&&(f0.l_decl->m_kind!=BB_T("struct")))){
        this->m_Error(BB_T("'Implements' can only be used with classes and structs"));
      }
      f0.l_decl->m_ifaceTypes=this->m_ParseTypes();
    }
    bbString l_0=this->m_Toke();
    if(l_0==BB_T("virtual")||l_0==BB_T("abstract")||l_0==BB_T("final")){
      if((f0.l_decl->m_kind==BB_T("interface"))){
        this->m_Error(BB_T("Interfaces are implicitly abstract"));
      }
      if((f0.l_decl->m_kind==BB_T("protocol"))){
        this->m_Error(BB_T("Protocols cannot have modifiers"));
      }
      if(this->m_CParse(BB_T("virtual"))){
        l_flags|=g_mx2_DECL_0VIRTUAL;
      }else if(this->m_CParse(BB_T("abstract"))){
        l_flags|=g_mx2_DECL_0ABSTRACT;
      }else if(this->m_CParse(BB_T("final"))){
        l_flags|=g_mx2_DECL_0FINAL;
      }
    }
    if(this->m_CParse(BB_T("="))){
      if(!bbBool((l_flags&g_mx2_DECL_0EXTERN))){
        this->m_Error(BB_T("Non-extern declaration cannot be assigned an extern symbol"));
      }
      f0.l_decl->m_symbol=this->m_ParseString();
    }
    this->m_ParseEol();
  }catch(t_mx2_ParseEx* ex){
    struct f1_t : public bbGCFrame{
      t_mx2_ParseEx* l_ex{};
      void gcMark(){
        bbGCMarkPtr(l_ex);
      }
    }f1{};
    f1.l_ex=ex;
    this->m_SkipToNextLine();
  }
  f0.l_decl->m_flags=l_flags;
  bbInt l_mflags=((l_flags&g_mx2_DECL_0EXTERN)|g_mx2_DECL_0PUBLIC);
  if(((f0.l_decl->m_kind==BB_T("interface"))||(f0.l_decl->m_kind==BB_T("protocol")))){
    l_mflags|=(g_mx2_DECL_0IFACEMEMBER|g_mx2_DECL_0ABSTRACT);
  }
  f0.l_decl->m_members=this->m_ParseDecls(l_mflags,false);
  try{
    this->m_Parse(BB_T("end"));
    this->m_CParse(f0.l_decl->m_kind);
    this->m_ParseEol();
  }catch(t_mx2_ParseEx* ex){
    struct f1_t : public bbGCFrame{
      t_mx2_ParseEx* l_ex{};
      void gcMark(){
        bbGCMarkPtr(l_ex);
      }
    }f1{};
    f1.l_ex=ex;
    this->m_SkipToNextLine();
  }
  f0.l_decl->m_endpos=this->m_EndPos();
  return f0.l_decl;
}

bbArray<bbGCVar<t_mx2_StmtExpr>>* t_mx2_Parser::m_ParseBlockStmts(){
  struct f0_t : public bbGCFrame{
    t_std_collections_Stack_1Tt_mx2_StmtExpr_2* l_stmts{};
    void gcMark(){
      bbGCMarkPtr(l_stmts);
    }
  }f0{};
  f0.l_stmts=bbGCNew<t_std_collections_Stack_1Tt_mx2_StmtExpr_2>();
  while(bbBool(this->m_Toke())){
    bbString l_0=this->m_Toke();
    if(l_0==BB_T("if")){
      struct f2_t : public bbGCFrame{
        t_mx2_StmtExpr* t0{};
        void gcMark(){
          bbGCMarkPtr(t0);
        }
      }f2{};
      f0.l_stmts->m_Push(f2.t0=((t_mx2_StmtExpr*)(this->m_ParseIf())));
    }else if(l_0==BB_T("while")){
      struct f2_t : public bbGCFrame{
        t_mx2_StmtExpr* t0{};
        void gcMark(){
          bbGCMarkPtr(t0);
        }
      }f2{};
      f0.l_stmts->m_Push(f2.t0=((t_mx2_StmtExpr*)(this->m_ParseWhile())));
    }else if(l_0==BB_T("repeat")){
      struct f2_t : public bbGCFrame{
        t_mx2_StmtExpr* t0{};
        void gcMark(){
          bbGCMarkPtr(t0);
        }
      }f2{};
      f0.l_stmts->m_Push(f2.t0=((t_mx2_StmtExpr*)(this->m_ParseRepeat())));
    }else if(l_0==BB_T("for")){
      struct f2_t : public bbGCFrame{
        t_mx2_StmtExpr* t0{};
        void gcMark(){
          bbGCMarkPtr(t0);
        }
      }f2{};
      f0.l_stmts->m_Push(f2.t0=((t_mx2_StmtExpr*)(this->m_ParseFor())));
    }else if(l_0==BB_T("select")){
      struct f2_t : public bbGCFrame{
        t_mx2_StmtExpr* t0{};
        void gcMark(){
          bbGCMarkPtr(t0);
        }
      }f2{};
      f0.l_stmts->m_Push(f2.t0=((t_mx2_StmtExpr*)(this->m_ParseSelect())));
    }else if(l_0==BB_T("try")){
      struct f2_t : public bbGCFrame{
        t_mx2_StmtExpr* t0{};
        void gcMark(){
          bbGCMarkPtr(t0);
        }
      }f2{};
      f0.l_stmts->m_Push(f2.t0=((t_mx2_StmtExpr*)(this->m_ParseTry())));
    }else if(l_0==BB_T("local")||l_0==BB_T("const")||l_0==BB_T("global")){
      struct f2_t : public bbGCFrame{
        t_std_collections_Stack_1Tt_mx2_Decl_2* l_decls{};
        void gcMark(){
          bbGCMarkPtr(l_decls);
        }
      }f2{};
      f2.l_decls=bbGCNew<t_std_collections_Stack_1Tt_mx2_Decl_2>();
      this->m_ParseVars(f2.l_decls,g_mx2_DECL_0PUBLIC);
      {
        struct f3_t : public bbGCFrame{
          t_std_collections_Stack_1Tt_mx2_Decl_2_Iterator l_1{};
          void gcMark(){
            bbGCMark(l_1);
          }
        }f3{};
        f3.l_1=f2.l_decls->m_All();
        for(;!f3.l_1.m_AtEnd();f3.l_1.m_Bump()){
          struct f4_t : public bbGCFrame{
            t_mx2_Decl* l_decl{};
            t_mx2_StmtExpr* t0{};
            void gcMark(){
              bbGCMarkPtr(l_decl);
              bbGCMarkPtr(t0);
            }
          }f4{};
          f4.l_decl=f3.l_1.m_Current();
          f0.l_stmts->m_Push(f4.t0=((t_mx2_StmtExpr*)(bbGCNew<t_mx2_VarDeclStmtExpr>(bb_object_cast<t_mx2_VarDecl*>(f4.l_decl),f4.l_decl->m_srcpos,f4.l_decl->m_endpos))));
        }
      }
    }else if(l_0==BB_T("end")||l_0==BB_T("endif")||l_0==BB_T("wend")||l_0==BB_T("next")||l_0==BB_T("until")||l_0==BB_T("forever")||l_0==BB_T("else")||l_0==BB_T("elseif")||l_0==BB_T("setter")||l_0==BB_T("getter")||l_0==BB_T("case")||l_0==BB_T("default")||l_0==BB_T("catch")){
      break;
    }else{
      try{
        do{
          struct f4_t : public bbGCFrame{
            t_mx2_StmtExpr* t0{};
            void gcMark(){
              bbGCMarkPtr(t0);
            }
          }f4{};
          f0.l_stmts->m_Push(f4.t0=this->m_ParseSimpleStmt());
        }while(!(!this->m_CParse(BB_T(";"))));
        this->m_ParseEol();
      }catch(t_mx2_ParseEx* ex){
        struct f3_t : public bbGCFrame{
          t_mx2_ParseEx* l_ex{};
          void gcMark(){
            bbGCMarkPtr(l_ex);
          }
        }f3{};
        f3.l_ex=ex;
        this->m_SkipToNextLine();
      }
    }
  }
  return f0.l_stmts->m_ToArray();
}

t_mx2_Expr* t_mx2_Parser::m_ParseBitorExpr(){
  struct f0_t : public bbGCFrame{
    t_mx2_Expr* l_expr{};
    void gcMark(){
      bbGCMarkPtr(l_expr);
    }
  }f0{};
  bbInt l_srcpos=this->m_SrcPos();
  f0.l_expr=this->m_ParseBitandExpr();
  for(;;){
    bbString l_0=this->m_Toke();
    if(l_0==BB_T("|")){
      struct f2_t : public bbGCFrame{
        t_mx2_Expr* t0{};
        void gcMark(){
          bbGCMarkPtr(t0);
        }
      }f2{};
      bbString l_op=this->m_Parse();
      f0.l_expr=((t_mx2_Expr*)(bbGCNew<t_mx2_BinaryopExpr>(l_op,f0.l_expr,f2.t0=this->m_ParseBitandExpr(),l_srcpos,this->m_EndPos())));
    }else{
      break;
    }
  }
  return f0.l_expr;
}

t_mx2_Expr* t_mx2_Parser::m_ParseBitandExpr(){
  struct f0_t : public bbGCFrame{
    t_mx2_Expr* l_expr{};
    void gcMark(){
      bbGCMarkPtr(l_expr);
    }
  }f0{};
  bbInt l_srcpos=this->m_SrcPos();
  f0.l_expr=this->m_ParseShiftExpr();
  for(;;){
    bbString l_0=this->m_Toke();
    if(l_0==BB_T("&")||l_0==BB_T("~")){
      struct f2_t : public bbGCFrame{
        t_mx2_Expr* t0{};
        void gcMark(){
          bbGCMarkPtr(t0);
        }
      }f2{};
      bbString l_op=this->m_Parse();
      f0.l_expr=((t_mx2_Expr*)(bbGCNew<t_mx2_BinaryopExpr>(l_op,f0.l_expr,f2.t0=this->m_ParseShiftExpr(),l_srcpos,this->m_EndPos())));
    }else{
      break;
    }
  }
  return f0.l_expr;
}

t_mx2_TypeExpr* t_mx2_Parser::m_ParseBaseType(t_mx2_IdentTypeExpr* l_identType){
  struct f0_t : public bbGCFrame{
    t_mx2_TypeExpr* l_type{};
    void gcMark(){
      bbGCMarkPtr(l_type);
    }
  }f0{};
  f0.l_type=((t_mx2_TypeExpr*)(l_identType));
  if(!bbBool(f0.l_type)){
    f0.l_type=((t_mx2_TypeExpr*)(this->m_ParseIdentType()));
  }
  bbInt l_srcpos=f0.l_type->m_srcpos;
  for(;;){
    if((this->m_Toke()==BB_T("."))){
      this->m_Bump();
      bbString l_ident=this->m_ParseIdent();
      f0.l_type=((t_mx2_TypeExpr*)(bbGCNew<t_mx2_MemberTypeExpr>(f0.l_type,l_ident,l_srcpos,this->m_EndPos())));
    }else if((this->m_Toke()==BB_T("<"))){
      struct f2_t : public bbGCFrame{
        t_std_collections_Stack_1Tt_mx2_TypeExpr_2* l_args{};
        bbArray<bbGCVar<t_mx2_TypeExpr>>* t0{};
        void gcMark(){
          bbGCMarkPtr(l_args);
          bbGCMarkPtr(t0);
        }
      }f2{};
      this->m_Bump();
      f2.l_args=bbGCNew<t_std_collections_Stack_1Tt_mx2_TypeExpr_2>();
      do{
        struct f3_t : public bbGCFrame{
          t_mx2_TypeExpr* t0{};
          void gcMark(){
            bbGCMarkPtr(t0);
          }
        }f3{};
        f2.l_args->m_Push(f3.t0=this->m_ParseType(((t_mx2_IdentTypeExpr*)0)));
      }while(!(!this->m_CParse(BB_T(","))));
      this->m_Parse(BB_T(">"));
      f0.l_type=((t_mx2_TypeExpr*)(bbGCNew<t_mx2_GenericTypeExpr>(f0.l_type,f2.t0=f2.l_args->m_ToArray(),l_srcpos,this->m_EndPos())));
    }else{
      break;
    }
  }
  while(this->m_CParse(BB_T("ptr"))){
    f0.l_type=((t_mx2_TypeExpr*)(bbGCNew<t_mx2_PointerTypeExpr>(f0.l_type,l_srcpos,this->m_EndPos())));
  }
  return f0.l_type;
}

t_mx2_Expr* t_mx2_Parser::m_ParseAndExpr(){
  struct f0_t : public bbGCFrame{
    t_mx2_Expr* l_expr{};
    void gcMark(){
      bbGCMarkPtr(l_expr);
    }
  }f0{};
  bbInt l_srcpos=this->m_SrcPos();
  f0.l_expr=this->m_ParseEqualsExpr();
  for(;;){
    bbString l_0=this->m_Toke();
    if(l_0==BB_T("and")){
      struct f2_t : public bbGCFrame{
        t_mx2_Expr* t0{};
        void gcMark(){
          bbGCMarkPtr(t0);
        }
      }f2{};
      bbString l_op=this->m_Parse();
      f0.l_expr=((t_mx2_Expr*)(bbGCNew<t_mx2_BinaryopExpr>(l_op,f0.l_expr,f2.t0=this->m_ParseEqualsExpr(),l_srcpos,this->m_EndPos())));
    }else{
      break;
    }
  }
  return f0.l_expr;
}

void t_mx2_Parser::m_ParseAliases(t_std_collections_Stack_1Tt_mx2_Decl_2* l_decls,bbInt l_flags){
  bbString l_kind=this->m_Parse();
  try{
    do{
      struct f2_t : public bbGCFrame{
        t_mx2_AliasDecl* l_decl{};
        void gcMark(){
          bbGCMarkPtr(l_decl);
        }
      }f2{};
      f2.l_decl=bbGCNew<t_mx2_AliasDecl>();
      f2.l_decl->m_srcpos=this->m_SrcPos();
      f2.l_decl->m_kind=l_kind;
      f2.l_decl->m_docs=this->m_Docs();
      f2.l_decl->m_flags=l_flags;
      f2.l_decl->m_ident=this->m_ParseIdent();
      f2.l_decl->m_genArgs=this->m_ParseGenArgs();
      this->m_Parse(BB_T(":"));
      f2.l_decl->m_type=this->m_ParseType(((t_mx2_IdentTypeExpr*)0));
      f2.l_decl->m_endpos=this->m_EndPos();
      l_decls->m_Push(((t_mx2_Decl*)(f2.l_decl)));
    }while(!(!this->m_CParse(BB_T(","))));
    this->m_ParseEol();
  }catch(t_mx2_ParseEx* ex){
    struct f1_t : public bbGCFrame{
      t_mx2_ParseEx* l_ex{};
      void gcMark(){
        bbGCMarkPtr(l_ex);
      }
    }f1{};
    f1.l_ex=ex;
    this->m_SkipToNextLine();
  }
}

t_mx2_Expr* t_mx2_Parser::m_ParseAddsubExpr(){
  struct f0_t : public bbGCFrame{
    t_mx2_Expr* l_expr{};
    void gcMark(){
      bbGCMarkPtr(l_expr);
    }
  }f0{};
  bbInt l_srcpos=this->m_SrcPos();
  f0.l_expr=this->m_ParseMuldivExpr();
  for(;;){
    bbString l_0=this->m_Toke();
    if(l_0==BB_T("+")||l_0==BB_T("-")){
      struct f2_t : public bbGCFrame{
        t_mx2_Expr* t0{};
        void gcMark(){
          bbGCMarkPtr(t0);
        }
      }f2{};
      bbString l_op=this->m_Parse();
      f0.l_expr=((t_mx2_Expr*)(bbGCNew<t_mx2_BinaryopExpr>(l_op,f0.l_expr,f2.t0=this->m_ParseMuldivExpr(),l_srcpos,this->m_EndPos())));
    }else{
      break;
    }
  }
  return f0.l_expr;
}

bbString t_mx2_Parser::m_Parse(){
  bbString l_toke=this->m_Toke();
  this->m_Bump();
  return l_toke;
}

void t_mx2_Parser::m_Parse(bbString l_toke){
  if((this->m_Toke()!=l_toke)){
    this->m_Error(((((BB_T("Expecting '")+l_toke)+BB_T("' but encountered '"))+this->m_Toke())+BB_T("'")));
  }
  this->m_Bump();
}

bbBool t_mx2_Parser::m_IsTypeIdent(bbString l_ident){
  if(l_ident==BB_T("void")||l_ident==BB_T("bool")||l_ident==BB_T("byte")||l_ident==BB_T("ubyte")||l_ident==BB_T("short")||l_ident==BB_T("ushort")||l_ident==BB_T("int")||l_ident==BB_T("uint")||l_ident==BB_T("long")||l_ident==BB_T("ulong")||l_ident==BB_T("float")||l_ident==BB_T("double")||l_ident==BB_T("string")||l_ident==BB_T("object")||l_ident==BB_T("throwable")){
    return true;
  }
  return false;
}

bbBool t_mx2_Parser::m_IsBool(bbString l_v){
  return ((l_v==BB_T("true"))||(l_v==BB_T("false")));
}

bbString t_mx2_Parser::m_EvalUnary(){
  if(this->m_CParse(BB_T("not"))){
    bbString l_expr=this->m_ToBool(this->m_EvalUnary());
    if((l_expr==BB_T("true"))){
      return BB_T("false");
    }else{
      return BB_T("true");
    }
  }
  return this->m_EvalPrimary();
}

bbString t_mx2_Parser::m_EvalPrimary(){
  if(this->m_CParse(BB_T("("))){
    bbString l_expr=this->m_Eval();
    this->m_Parse(BB_T(")"));
    return l_expr;
  }
  bbInt l_0=this->m_TokeType();
  if(l_0==g_mx2_TOKE_0IDENT){
    bbString l_id=this->m_Parse();
    bbString l_t=this->m__0ppsyms->m__idx(l_id);
    if(!bbBool(l_t)){
      l_t=BB_T("false");
    }
    return l_t;
  }else if(l_0==g_mx2_TOKE_0STRINGLIT){
    return this->m_Parse();
  }
  this->m_EvalError();
  return bbString{};
}

bbString t_mx2_Parser::m_EvalOr(){
  bbString l_lhs=this->m_EvalAnd();
  while(this->m_CParse(BB_T("or"))){
    l_lhs=this->m_ToBool(l_lhs);
    bbString l_rhs=this->m_ToBool(this->m_EvalAnd());
    if(((l_lhs==BB_T("true"))||(l_rhs==BB_T("true")))){
      l_lhs=BB_T("true");
    }else{
      l_lhs=BB_T("false");
    }
  }
  return l_lhs;
}

void t_mx2_Parser::m_EvalError(){
  this->m_Error(((BB_T("Failed to evaluate preprocessor expression: toke='")+this->m_Toke())+BB_T("'")));
}

bbString t_mx2_Parser::m_EvalEquals(){
  bbString l_lhs=this->m_EvalUnary();
  while(((this->m_Toke()==BB_T("="))||(this->m_Toke()==BB_T("<>")))){
    bbString l_op=this->m_Parse();
    bbString l_rhs=this->m_EvalUnary();
    if((this->m_IsBool(l_lhs)||this->m_IsBool(l_rhs))){
      l_lhs=this->m_ToBool(l_lhs);
      l_rhs=this->m_ToBool(l_rhs);
    }
    if(l_op==BB_T("=")){
      if((l_lhs==l_rhs)){
        l_lhs=BB_T("true");
      }else{
        l_lhs=BB_T("false");
      }
    }else if(l_op==BB_T("<>")){
      if((l_lhs!=l_rhs)){
        l_lhs=BB_T("true");
      }else{
        l_lhs=BB_T("false");
      }
    }
  }
  return l_lhs;
}

bbBool t_mx2_Parser::m_EvalBool(){
  return (this->m_ToBool(this->m_Eval())==BB_T("true"));
}

bbString t_mx2_Parser::m_EvalAnd(){
  bbString l_lhs=this->m_EvalEquals();
  while(this->m_CParse(BB_T("and"))){
    l_lhs=this->m_ToBool(l_lhs);
    bbString l_rhs=this->m_ToBool(this->m_EvalEquals());
    if(((l_lhs==BB_T("true"))&&(l_rhs==BB_T("true")))){
      l_lhs=BB_T("true");
    }else{
      l_lhs=BB_T("false");
    }
  }
  return l_lhs;
}

bbString t_mx2_Parser::m_Eval(){
  return this->m_EvalOr();
}

void t_mx2_Parser::m_ErrorNx(bbString l_msg){
  if(!this->m__0stateStack->m_Empty()){
    throw bbGCNew<t_mx2_TryParseEx>();
  }
  bbGCNew<t_mx2_ParseEx>(l_msg,this->m__0fdecl->m_path,this->m_SrcPos());
}

void t_mx2_Parser::m_Error(bbString l_msg){
  if(!this->m__0stateStack->m_Empty()){
    throw bbGCNew<t_mx2_TryParseEx>();
  }
  throw bbGCNew<t_mx2_ParseEx>(l_msg,(bbBool(this->m__0fdecl) ? this->m__0fdecl->m_path : bbString{}),this->m_SrcPos());
}

void t_mx2_Parser::m_EndTryParse(){
  this->m__0stateStack->m_Pop();
}

bbInt t_mx2_Parser::m_EndPos(){
  return this->m__0toker->m_EndPos();
}

void t_mx2_Parser::m_EatEols(){
  while((this->m_TokeType()==g_mx2_TOKE_0EOL)){
    this->m_Bump();
  }
}

bbString t_mx2_Parser::m_Docs(){
  if(!bbBool(this->m__0docs->m_Length())){
    return bbString{};
  }
  bbString l_docs=this->m__0docs->m_Join(BB_T("\n"));
  this->m__0docs->m_Clear();
  return l_docs;
}

bbString t_mx2_Parser::m_CParseIdent(){
  if((this->m_TokeType()!=g_mx2_TOKE_0IDENT)){
    return bbString{};
  }
  bbString l_ident=this->m_Toke();
  this->m_Bump();
  return l_ident;
}

bbBool t_mx2_Parser::m_CParseEol(){
  if((this->m_TokeType()!=g_mx2_TOKE_0EOL)){
    return false;
  }
  this->m_EatEols();
  return true;
}

bbInt t_mx2_Parser::m_CParseAccess(bbInt l_flags){
  bbString l_0=this->m_Toke();
  if(l_0==BB_T("public")){
    l_flags=((l_flags&~g_mx2_DECL_0ACCESSMASK)|g_mx2_DECL_0PUBLIC);
  }else if(l_0==BB_T("private")){
    l_flags=((l_flags&~g_mx2_DECL_0ACCESSMASK)|g_mx2_DECL_0PRIVATE);
  }else if(l_0==BB_T("protected")){
    l_flags=((l_flags&~g_mx2_DECL_0ACCESSMASK)|g_mx2_DECL_0PROTECTED);
  }else if(l_0==BB_T("internal")){
    l_flags=((l_flags&~g_mx2_DECL_0ACCESSMASK)|g_mx2_DECL_0INTERNAL);
  }else{
    return l_flags;
  }
  this->m_Bump();
  return l_flags;
}

bbBool t_mx2_Parser::m_CParse(bbString l_toke){
  if((this->m_Toke()!=l_toke)){
    return false;
  }
  this->m_Bump();
  return true;
}

bbString t_mx2_Parser::m_Bump(){
  if(!bbBool(this->m__0fdecl)){
    return this->m__0toker->m_Bump();
  }
  bbString l_ptoke=this->m_Toke();
  for(;;){
    if(!bbBool(this->m__0toker->m_Bump())){
      break;
    }
    if((this->m__0toker->m_TokeType()==g_mx2_TOKE_0PREPROC)){
      this->m_PreProcess(this->m__0toker->m_Toke());
      continue;
    }else if((this->m__0ccnest!=this->m__0ifnest)){
      bbInt l_pos=this->m__0toker->m_LinePos();
      while((bbBool(this->m__0toker->m_TokeType())&&(this->m__0toker->m_TokeType()!=g_mx2_TOKE_0EOL))){
        this->m__0toker->m_Bump();
      }
      if(this->m__0doccing){
        this->m__0docs->m_Push(this->m__0toker->m_Text().slice(l_pos,this->m__0toker->m_TokePos()));
      }
      continue;
    }else{
      if(((this->m__0toker->m_TokeType()==g_mx2_TOKE_0EOL)&&(((l_ptoke==BB_T("("))||(l_ptoke==BB_T("[")))||(l_ptoke==BB_T(","))))){
        continue;
      }
    }
    break;
  }
  return this->m__0toker->m_Toke();
}

void t_mx2_Parser::m_BeginTryParse(){
  struct f0_t : public bbGCFrame{
    t_mx2_Toker* t0{};
    void gcMark(){
      bbGCMarkPtr(t0);
    }
  }f0{};
  this->m__0stateStack->m_Push(f0.t0=this->m__0toker->m_State());
}

bbBool t_mx2_Parser::m_AtEos(){
  return ((((this->m_TokeType()==g_mx2_TOKE_0EOL)||(this->m_Toke()==BB_T(";")))||(this->m_Toke()==BB_T("else")))||(this->m_Toke()==BB_T("elseif")));
}

void mx2_mx2cc_parser_init(){
  static bool done;
  if(done) return;
  done=true;
}

bbInit mx2_mx2cc_parser_init_v("mx2cc_parser",&mx2_mx2cc_parser_init);
