
#ifndef MX2_MX2CC_UTIL_H
#define MX2_MX2CC_UTIL_H

#include <bbmonkey.h>

// ***** External *****

struct t_mx2_Value;
struct t_mx2_Type;
struct t_mx2_Expr;
struct t_mx2_TypeExpr;
struct t_mx2_VarDecl;
struct t_mx2_Scope;

// ***** Internal *****

extern bbString g_mx2_HostOS;
extern bbInt g_mx2_CHAR_0EOL;
extern bbInt g_mx2_CHAR_0TAB;
extern bbInt g_mx2_CHAR_0RETURN;
extern bbInt g_mx2_CHAR_0HASH;
extern bbInt g_mx2_CHAR_0QUOTE;
extern bbInt g_mx2_CHAR_0PLUS;
extern bbInt g_mx2_CHAR_0MINUS;
extern bbInt g_mx2_CHAR_0DOT;
extern bbInt g_mx2_CHAR_0UNDERSCORE;
extern bbInt g_mx2_CHAR_0APOSTROPHE;
extern bbInt g_mx2_CHAR_0DOLLAR;
extern bbInt g_mx2_CHAR_0TILDE;
extern bbInt g_mx2_CHAR_0BACKSLASH;
extern bbString g_mx2_STRING_0BACKSLASH;
extern bbString g_mx2_STRING_0TILDE;
extern bbString g_mx2_STRING_0QUOTE;
extern bbString g_mx2_STRING_0EOL;
extern bbString g_mx2_STRING_0RETURN;
extern bbString g_mx2_STRING_0TAB;
extern bbString g_mx2_STRING_0CPPBACKSLASH;
extern bbString g_mx2_STRING_0CPPQUOTE;
extern bbString g_mx2_STRING_0CPPEOL;
extern bbString g_mx2_STRING_0CPPRETURN;
extern bbString g_mx2_STRING_0CPPTAB;
extern bbString g_mx2_STRING_0MX2TILDE;
extern bbString g_mx2_STRING_0MX2QUOTE;
extern bbString g_mx2_STRING_0MX2EOL;
extern bbString g_mx2_STRING_0MX2RETURN;
extern bbString g_mx2_STRING_0MX2TAB;

extern bbString g_mx2_Join_1Tt_mx2_Value_2(bbArray<bbGCVar<t_mx2_Value>>* l_bits,bbString l_sep);
extern bbArray<bbString>* g_mx2_ToStrings_1Tt_mx2_Value_2(bbArray<bbGCVar<t_mx2_Value>>* l_bits);
extern bbString g_mx2_Join_1Tt_mx2_Type_2(bbArray<bbGCVar<t_mx2_Type>>* l_bits,bbString l_sep);
extern bbArray<bbString>* g_mx2_ToStrings_1Tt_mx2_Type_2(bbArray<bbGCVar<t_mx2_Type>>* l_bits);
extern bbString g_mx2_Join_1Tt_mx2_Expr_2(bbArray<bbGCVar<t_mx2_Expr>>* l_bits,bbString l_sep);
extern bbArray<bbString>* g_mx2_ToStrings_1Tt_mx2_Expr_2(bbArray<bbGCVar<t_mx2_Expr>>* l_bits);
extern bbString g_mx2_Join_1Tt_mx2_TypeExpr_2(bbArray<bbGCVar<t_mx2_TypeExpr>>* l_bits,bbString l_sep);
extern bbArray<bbString>* g_mx2_ToStrings_1Tt_mx2_TypeExpr_2(bbArray<bbGCVar<t_mx2_TypeExpr>>* l_bits);
extern bbString g_mx2_Join_1Tt_mx2_VarDecl_2(bbArray<bbGCVar<t_mx2_VarDecl>>* l_bits,bbString l_sep);
extern bbArray<bbString>* g_mx2_ToStrings_1Tt_mx2_VarDecl_2(bbArray<bbGCVar<t_mx2_VarDecl>>* l_bits);
extern bbString g_mx2_EnquoteCppString(bbString l_str);
extern bbString g_mx2_DequoteMx2String(bbString l_str);
extern bbBool g_mx2_AllTypesGeneric(bbArray<bbGCVar<t_mx2_Type>>* l_types);
extern bbBool g_mx2_AnyTypeGeneric(bbArray<bbGCVar<t_mx2_Type>>* l_types);
extern bbBool g_mx2_TypesEqual(bbArray<bbGCVar<t_mx2_Type>>* l_lhs,bbArray<bbGCVar<t_mx2_Type>>* l_rhs);
extern bbArray<bbGCVar<t_mx2_Type>>* g_mx2_Types(bbArray<bbGCVar<t_mx2_Value>>* l_args);
extern bbArray<bbGCVar<t_mx2_Value>>* g_mx2_UpCast(bbArray<bbGCVar<t_mx2_Value>>* l_args,t_mx2_Type* l_type);
extern bbArray<bbGCVar<t_mx2_Value>>* g_mx2_SemantArgs(bbArray<bbGCVar<t_mx2_Expr>>* l_exprs,t_mx2_Scope* l_scope);
extern bbArray<bbGCVar<t_mx2_Value>>* g_mx2_SemantRValues(bbArray<bbGCVar<t_mx2_Expr>>* l_exprs,t_mx2_Scope* l_scope);
extern bbString g_mx2_MakeRelativePath(bbString l_path,bbString l_baseDir);
extern void g_mx2_CSaveString(bbString l_str,bbString l_path);
extern void g_mx2_SetEnv(bbString l_name,bbString l_value);
extern bbString g_mx2_GetEnv(bbString l_name);
extern bbString g_mx2_MungPath(bbString l_path);

#endif
