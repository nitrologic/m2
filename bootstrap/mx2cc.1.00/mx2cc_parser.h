
#ifndef MX2_MX2CC_PARSER_H
#define MX2_MX2CC_PARSER_H

#include <bbmonkey.h>

// ***** External *****

#include "../../../../../modules/monkey/monkey.buildv1.0.0/desktop_release_linux/monkey_types.h"

struct t_mx2_FileDecl;
struct t_mx2_Toker;
struct t_std_collections_Stack_1Tt_mx2_Toker_2;
struct t_std_collections_Stack_1s;
struct t_std_collections_Stack_1Tt_mx2_ParseEx_2;
struct t_std_collections_Map_1ss;
struct t_mx2_WhileStmtExpr;
struct t_std_collections_Stack_1Tt_mx2_Decl_2;
struct t_mx2_TypeExpr;
struct t_mx2_IdentTypeExpr;
struct t_mx2_TryStmtExpr;
struct t_mx2_StmtExpr;
struct t_mx2_Expr;
struct t_mx2_SelectStmtExpr;
struct t_mx2_RepeatStmtExpr;
struct t_mx2_PropertyDecl;
struct t_mx2_IfStmtExpr;
struct t_mx2_FuncTypeExpr;
struct t_mx2_FuncDecl;
struct t_mx2_ForStmtExpr;
struct t_mx2_EnumDecl;
struct t_mx2_Decl;
struct t_mx2_ClassDecl;

// ***** Internal *****

struct t_mx2_TryParseEx;
struct t_mx2_Parser;

struct t_mx2_TryParseEx : public bbThrowable{

  const char *typeName()const{return "t_mx2_TryParseEx";}

  t_mx2_TryParseEx(){
  }
};

struct t_mx2_Parser : public bbObject{

  const char *typeName()const{return "t_mx2_Parser";}

  bbGCVar<t_mx2_FileDecl> m__0fdecl{};
  bbGCVar<t_mx2_Toker> m__0toker{};
  bbGCVar<t_std_collections_Stack_1Tt_mx2_Toker_2> m__0stateStack{};
  bbGCVar<t_std_collections_Stack_1s> m__0usings{};
  bbGCVar<t_std_collections_Stack_1Tt_mx2_ParseEx_2> m__0errors{};
  bbGCVar<t_std_collections_Map_1ss> m__0ppsyms{};
  bbInt m__0ccnest{};
  bbInt m__0ifnest{};
  bbGCVar<t_std_collections_Stack_1s> m__0docs{};
  bbBool m__0doccing{};
  bbGCVar<t_std_collections_Stack_1s> m__0imports{};

  void init();

  void gcMark();

  t_mx2_Parser(bbString l_source,t_std_collections_Map_1ss* l_ppsyms);
  t_mx2_Parser();

  void m_TryParseFailed();
  bbInt m_TokeType();
  bbString m_Toke();
  bbString m_ToBool(bbString l_v);
  bbInt m_SrcPos();
  void m_SkipToNextLine();
  void m_SkipToEol();
  void m_PreProcess(bbString l_text);
  t_mx2_WhileStmtExpr* m_ParseWhile();
  void m_ParseVars(t_std_collections_Stack_1Tt_mx2_Decl_2* l_decls,bbInt l_flags);
  bbString m_ParseUsingIdent();
  bbArray<bbGCVar<t_mx2_TypeExpr>>* m_ParseTypes();
  t_mx2_TypeExpr* m_ParseType(t_mx2_IdentTypeExpr* l_identType);
  t_mx2_TryStmtExpr* m_ParseTry();
  bbString m_ParseString();
  bbArray<bbGCVar<t_mx2_StmtExpr>>* m_ParseStmts(bbBool l_block);
  bbArray<bbGCVar<t_mx2_StmtExpr>>* m_ParseSimpleStmts();
  t_mx2_StmtExpr* m_ParseSimpleStmt();
  t_mx2_Expr* m_ParseShiftExpr();
  t_mx2_SelectStmtExpr* m_ParseSelect();
  t_mx2_RepeatStmtExpr* m_ParseRepeat();
  t_mx2_PropertyDecl* m_ParseProperty(bbInt l_flags);
  t_mx2_Expr* m_ParsePrimaryExpr();
  t_mx2_Expr* m_ParsePrefixExpr();
  t_mx2_Expr* m_ParsePostfixExpr();
  t_mx2_Expr* m_ParseOrderExpr();
  t_mx2_Expr* m_ParseOrExpr();
  t_mx2_TypeExpr* m_ParseNewType();
  bbString m_ParseNamespaceIdent();
  t_mx2_Expr* m_ParseMuldivExpr();
  bbArray<bbGCVar<t_mx2_Expr>>* m_ParseInvokeArgs();
  t_mx2_Expr* m_ParseIfThenElseExpr();
  t_mx2_IfStmtExpr* m_ParseIf();
  t_mx2_IdentTypeExpr* m_ParseIdentType();
  bbString m_ParseIdent();
  bbArray<bbString>* m_ParseGenArgs();
  t_mx2_FuncTypeExpr* m_ParseFuncType(t_mx2_TypeExpr* l_retType);
  t_mx2_FuncDecl* m_ParseFunc(bbInt l_flags);
  t_mx2_ForStmtExpr* m_ParseFor();
  t_mx2_FileDecl* m_ParseFile(bbString l_ident,bbString l_srcPath,t_std_collections_Map_1ss* l_ppsyms);
  t_mx2_Expr* m_ParseExtendsExpr();
  bbArray<bbGCVar<t_mx2_Expr>>* m_ParseExprs();
  t_mx2_StmtExpr* m_ParseExprStmt();
  t_mx2_Expr* m_ParseExpr();
  t_mx2_Expr* m_ParseEqualsExpr();
  void m_ParseEol();
  t_mx2_EnumDecl* m_ParseEnum(bbInt l_flags);
  bbArray<bbGCVar<t_mx2_Decl>>* m_ParseDecls(bbInt l_flags,bbBool l_fileScope);
  t_mx2_Expr* m_ParseCompareExpr();
  t_mx2_ClassDecl* m_ParseClass(bbInt l_flags);
  bbArray<bbGCVar<t_mx2_StmtExpr>>* m_ParseBlockStmts();
  t_mx2_Expr* m_ParseBitorExpr();
  t_mx2_Expr* m_ParseBitandExpr();
  t_mx2_TypeExpr* m_ParseBaseType(t_mx2_IdentTypeExpr* l_identType);
  t_mx2_Expr* m_ParseAndExpr();
  void m_ParseAliases(t_std_collections_Stack_1Tt_mx2_Decl_2* l_decls,bbInt l_flags);
  t_mx2_Expr* m_ParseAddsubExpr();
  bbString m_Parse();
  void m_Parse(bbString l_toke);
  bbBool m_IsTypeIdent(bbString l_ident);
  bbBool m_IsBool(bbString l_v);
  bbString m_EvalUnary();
  bbString m_EvalPrimary();
  bbString m_EvalOr();
  void m_EvalError();
  bbString m_EvalEquals();
  bbBool m_EvalBool();
  bbString m_EvalAnd();
  bbString m_Eval();
  void m_ErrorNx(bbString l_msg);
  void m_Error(bbString l_msg);
  void m_EndTryParse();
  bbInt m_EndPos();
  void m_EatEols();
  bbString m_Docs();
  bbString m_CParseIdent();
  bbBool m_CParseEol();
  bbInt m_CParseAccess(bbInt l_flags);
  bbBool m_CParse(bbString l_toke);
  bbString m_Bump();
  void m_BeginTryParse();
  bbBool m_AtEos();
};

#endif
