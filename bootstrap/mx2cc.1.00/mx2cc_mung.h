
#ifndef MX2_MX2CC_MUNG_H
#define MX2_MX2CC_MUNG_H

#include <bbmonkey.h>

// ***** External *****

struct t_mx2_VarValue;
struct t_mx2_FuncValue;
struct t_mx2_ClassType;
struct t_mx2_EnumType;
struct t_mx2_Scope;
struct t_mx2_Type;

// ***** Internal *****

extern bbString g_mx2_VarName(t_mx2_VarValue* l_vvar);
extern bbString g_mx2_FuncName(t_mx2_FuncValue* l_func);
extern bbString g_mx2_ClassName(t_mx2_ClassType* l_ctype);
extern bbString g_mx2_EnumValueName(t_mx2_EnumType* l_etype,bbString l_value);
extern bbString g_mx2_EnumName(t_mx2_EnumType* l_etype);
extern bbString g_mx2_ScopeName(t_mx2_Scope* l_scope);
extern bbString g_mx2_MungArgs(bbArray<bbGCVar<t_mx2_Type>>* l_types);
extern bbString g_mx2_MungArg(t_mx2_Type* l_type);
extern bbString g_mx2_MungIdent(bbString l_ident);
extern bbString g_mx2_OpSym(bbString l_id);

#endif
