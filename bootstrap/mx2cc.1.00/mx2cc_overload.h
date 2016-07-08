
#ifndef MX2_MX2CC_OVERLOAD_H
#define MX2_MX2CC_OVERLOAD_H

#include <bbmonkey.h>

// ***** External *****

struct t_mx2_FuncValue;
struct t_std_collections_Stack_1Tt_mx2_FuncValue_2;
struct t_mx2_Type;

// ***** Internal *****

extern t_mx2_FuncValue* g_mx2_overload_FindOverload(t_std_collections_Stack_1Tt_mx2_FuncValue_2* l_funcs,t_mx2_Type* l_ret,bbArray<bbGCVar<t_mx2_Type>>* l_args);
extern void g_mx2_overload_Linearize(bbArray<bbGCVar<t_mx2_Type>>* l_types,t_mx2_FuncValue* l_func,t_std_collections_Stack_1Tt_mx2_FuncValue_2* l_funcs,bbInt l_j);
extern bbBool g_mx2_overload_IsBetter(t_mx2_FuncValue* l_func,t_mx2_FuncValue* l_func2,bbArray<bbGCVar<t_mx2_Type>>* l_args);
extern bbBool g_mx2_overload_CanInfer(t_mx2_FuncValue* l_func,bbArray<bbGCVar<t_mx2_Type>>* l_args);
extern bbBool g_mx2_overload_IsCandidate(t_mx2_FuncValue* l_func,t_mx2_Type* l_ret,bbArray<bbGCVar<t_mx2_Type>>* l_args,bbArray<bbGCVar<t_mx2_Type>>* l_infered);

#endif
