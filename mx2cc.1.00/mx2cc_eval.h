
#ifndef MX2_MX2CC_EVAL_H
#define MX2_MX2CC_EVAL_H

#include <bbmonkey.h>

// ***** External *****

struct t_mx2_Value;
struct t_mx2_Type;
struct t_mx2_LiteralValue;

// ***** Internal *****

extern t_mx2_Value* g_mx2_EvalBinaryop(t_mx2_Type* l_type,bbString l_op,t_mx2_Value* l_lhs,t_mx2_Value* l_rhs);
extern t_mx2_LiteralValue* g_mx2_EvalBinaryop(t_mx2_Type* l_type,bbString l_op,t_mx2_LiteralValue* l_lhs,t_mx2_LiteralValue* l_rhs);
extern t_mx2_Value* g_mx2_EvalUnaryop(t_mx2_Type* l_type,bbString l_op,t_mx2_Value* l_arg);
extern t_mx2_LiteralValue* g_mx2_EvalUnaryop(t_mx2_Type* l_type,bbString l_op,t_mx2_LiteralValue* l_arg);

#endif
