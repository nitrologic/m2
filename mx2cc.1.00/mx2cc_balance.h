
#ifndef MX2_MX2CC_BALANCE_H
#define MX2_MX2CC_BALANCE_H

#include <bbmonkey.h>

// ***** External *****

struct t_mx2_Type;
struct t_mx2_PrimType;

// ***** Internal *****

extern t_mx2_Type* g_mx2_BalanceAssignTypes(bbString l_op,t_mx2_Type* l_lhs,t_mx2_Type* l_rhs);
extern t_mx2_Type* g_mx2_BalanceBinaryopTypes(bbString l_op,t_mx2_Type* l_lhs,t_mx2_Type* l_rhs,bbArray<bbGCVar<t_mx2_Type>>* l_argTypes);
extern t_mx2_Type* g_mx2_BalanceTypes(t_mx2_Type* l_lhs,t_mx2_Type* l_rhs);
extern t_mx2_Type* g_mx2_BalancePrimTypes(t_mx2_PrimType* l_lhs,t_mx2_PrimType* l_rhs);
extern t_mx2_Type* g_mx2_BalanceNumericTypes(t_mx2_PrimType* l_lhs,t_mx2_PrimType* l_rhs);
extern t_mx2_Type* g_mx2_BalanceIntegralTypes(t_mx2_PrimType* l_lhs,t_mx2_PrimType* l_rhs);

#endif
