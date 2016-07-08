
#ifndef MX2_MX2CC_TRANSLATOR_0CPP_H
#define MX2_MX2CC_TRANSLATOR_0CPP_H

#include <bbmonkey.h>

// ***** External *****

#include "mx2cc_translator.h"

struct t_mx2_VarValue;
struct t_mx2_FileDecl;
struct t_mx2_GenArgType;
struct t_mx2_PointerType;
struct t_mx2_ArrayType;
struct t_mx2_FuncType;
struct t_mx2_PrimType;
struct t_mx2_EnumType;
struct t_mx2_ClassType;
struct t_mx2_Type;
struct t_mx2_Value;
struct t_mx2_FuncValue;
struct t_mx2_PointerValue;
struct t_mx2_IfThenElseValue;
struct t_mx2_BinaryopValue;
struct t_mx2_UnaryopValue;
struct t_mx2_PointerIndexValue;
struct t_mx2_StringIndexValue;
struct t_mx2_ArrayIndexValue;
struct t_mx2_NewArrayValue;
struct t_mx2_NewObjectValue;
struct t_mx2_MemberFuncValue;
struct t_mx2_MemberVarValue;
struct t_mx2_InvokeValue;
struct t_mx2_SuperValue;
struct t_mx2_SelfValue;
struct t_mx2_LiteralValue;
struct t_mx2_ExplicitCastValue;
struct t_mx2_UpCastValue;
struct t_mx2_Block;
struct t_mx2_ThrowStmt;
struct t_mx2_TryStmt;
struct t_mx2_ForStmt;
struct t_mx2_RepeatStmt;
struct t_mx2_WhileStmt;
struct t_mx2_SelectStmt;
struct t_mx2_IfStmt;
struct t_mx2_EvalStmt;
struct t_mx2_AssignStmt;
struct t_mx2_VarDeclStmt;
struct t_mx2_ReturnStmt;
struct t_mx2_ContinueStmt;
struct t_mx2_ExitStmt;
struct t_mx2_PrintStmt;
struct t_mx2_Stmt;
struct t_std_collections_Map_1sz;

// ***** Internal *****

struct t_mx2_Translator_0CPP;

struct t_mx2_Translator_0CPP : public t_mx2_Translator{

  const char *typeName()const{return "t_mx2_Translator_0CPP";}

  bbInt m__0lambdaId{};

  bbString m_VarType(t_mx2_VarValue* l_vvar);
  bbString m_VarProto(t_mx2_VarValue* l_vvar);
  void m_Translate(t_mx2_FileDecl* l_fdecl);
  bbString m_TransType(t_mx2_GenArgType* l_type);
  bbString m_TransType(t_mx2_PointerType* l_type);
  bbString m_TransType(t_mx2_ArrayType* l_type);
  bbString m_TransType(t_mx2_FuncType* l_type);
  bbString m_TransType(t_mx2_PrimType* l_type);
  bbString m_TransType(t_mx2_EnumType* l_type);
  bbString m_TransType(t_mx2_ClassType* l_type);
  bbString m_TransType(t_mx2_Type* l_type);
  bbString m_TransNull(t_mx2_Type* l_type);
  bbString m_TransMember(t_mx2_Value* l_instance,t_mx2_Value* l_member);
  bbString m_TransArgs(bbArray<bbGCVar<t_mx2_Value>>* l_args);
  bbString m_Trans(t_mx2_VarValue* l_value);
  bbString m_Trans(t_mx2_FuncValue* l_value);
  bbString m_Trans(t_mx2_PointerValue* l_value);
  bbString m_Trans(t_mx2_IfThenElseValue* l_value);
  bbString m_Trans(t_mx2_BinaryopValue* l_value);
  bbString m_Trans(t_mx2_UnaryopValue* l_value);
  bbString m_Trans(t_mx2_PointerIndexValue* l_value);
  bbString m_Trans(t_mx2_StringIndexValue* l_value);
  bbString m_Trans(t_mx2_ArrayIndexValue* l_value);
  bbString m_Trans(t_mx2_NewArrayValue* l_value);
  bbString m_Trans(t_mx2_NewObjectValue* l_value);
  bbString m_Trans(t_mx2_MemberFuncValue* l_value);
  bbString m_Trans(t_mx2_MemberVarValue* l_value);
  bbString m_Trans(t_mx2_InvokeValue* l_value);
  bbString m_Trans(t_mx2_SuperValue* l_value);
  bbString m_Trans(t_mx2_SelfValue* l_value);
  bbString m_Trans(t_mx2_LiteralValue* l_value);
  bbString m_Trans(t_mx2_ExplicitCastValue* l_value);
  bbString m_Trans(t_mx2_UpCastValue* l_value);
  bbString m_Trans(t_mx2_Value* l_value);
  bbBool m_IsVolatile(t_mx2_Value* l_arg);
  bbString m_GCVarTypeName(t_mx2_Type* l_type);
  bbString m_FuncProto(t_mx2_FuncValue* l_func,bbBool l_header);
  bbString m_FuncProto(t_mx2_FuncValue* l_func);
  void m_EndBlock();
  void m_EmitStmts(t_mx2_Block* l_block);
  void m_EmitStmt(t_mx2_ThrowStmt* l_stmt);
  void m_EmitStmt(t_mx2_TryStmt* l_stmt);
  void m_EmitStmt(t_mx2_ForStmt* l_stmt);
  void m_EmitStmt(t_mx2_RepeatStmt* l_stmt);
  void m_EmitStmt(t_mx2_WhileStmt* l_stmt);
  void m_EmitStmt(t_mx2_SelectStmt* l_stmt);
  void m_EmitStmt(t_mx2_IfStmt* l_stmt);
  void m_EmitStmt(t_mx2_EvalStmt* l_stmt);
  void m_EmitStmt(t_mx2_AssignStmt* l_stmt);
  void m_EmitStmt(t_mx2_VarDeclStmt* l_stmt);
  void m_EmitStmt(t_mx2_ReturnStmt* l_stmt);
  void m_EmitStmt(t_mx2_ContinueStmt* l_stmt);
  void m_EmitStmt(t_mx2_ExitStmt* l_stmt);
  void m_EmitStmt(t_mx2_PrintStmt* l_stmt);
  void m_EmitStmt(t_mx2_Stmt* l_stmt);
  bbString m_EmitLambda(t_mx2_FuncValue* l_func);
  void m_EmitGlobalInits(t_mx2_FileDecl* l_fdecl);
  void m_EmitFunc(t_mx2_FuncValue* l_func,bbBool l_init);
  void m_EmitDebugInfo(t_mx2_Stmt* l_stmt);
  void m_EmitClassProto(t_mx2_ClassType* l_ctype);
  void m_EmitClassProto(t_mx2_ClassType* l_ctype,t_mx2_FileDecl* l_fdecl,t_std_collections_Map_1sz* l_emitted);
  void m_EmitClassMembers(t_mx2_ClassType* l_ctype);
  void m_EmitBlock(t_mx2_FuncValue* l_func);
  void m_EmitBlock(t_mx2_Block* l_block);
  bbString m_ElementType(t_mx2_Type* l_type);
  bbString m_DebugInfo(t_mx2_Stmt* l_stmt);
  void m_BeginBlock();
  bbString m_ArrayName(t_mx2_ArrayType* l_type);

  t_mx2_Translator_0CPP(){
  }
};

#endif
