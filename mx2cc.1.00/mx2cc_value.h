
#ifndef MX2_MX2CC_VALUE_H
#define MX2_MX2CC_VALUE_H

#include <bbmonkey.h>

// ***** External *****

#include "mx2cc_node.h"

struct t_mx2_Decl;
struct t_mx2_Scope;
struct t_mx2_Type;
struct t_mx2_Block;
struct t_mx2_Stmt;
struct t_mx2_ClassType;
struct t_mx2_FuncType;
struct t_mx2_FuncValue;
struct t_mx2_ArrayType;

// ***** Internal *****

struct t_mx2_Value;
struct t_mx2_LiteralValue;
struct t_mx2_TypeValue;
struct t_mx2_UpCastValue;
struct t_mx2_ExplicitCastValue;
struct t_mx2_SelfValue;
struct t_mx2_SuperValue;
struct t_mx2_NullValue;
struct t_mx2_InvokeValue;
struct t_mx2_InvokeNewValue;
struct t_mx2_NewObjectValue;
struct t_mx2_NewArrayValue;
struct t_mx2_ArrayIndexValue;
struct t_mx2_StringIndexValue;
struct t_mx2_PointerIndexValue;
struct t_mx2_UnaryopValue;
struct t_mx2_BinaryopValue;
struct t_mx2_IfThenElseValue;
struct t_mx2_PointerValue;

extern bbInt g_mx2_VALUE_0LVALUE;
extern bbInt g_mx2_VALUE_0ASSIGNABLE;

extern t_mx2_LiteralValue* g_mx2_LiteralValue_IntValue(bbInt l_value);
extern t_mx2_LiteralValue* g_mx2_LiteralValue_BoolValue(bbBool l_value);
extern void g_mx2_Value_CheckAccess(t_mx2_Decl* l_decl,t_mx2_Scope* l_scope,t_mx2_Scope* l_tscope);

struct t_mx2_Value : public t_mx2_SNode{

  const char *typeName()const{return "t_mx2_Value";}

  bbGCVar<t_mx2_Type> m_type{};
  bbInt m_flags{};

  void gcMark();

  virtual t_mx2_Value* m_UpCast(t_mx2_Type* l_type);
  t_mx2_Value* m_ToValue(t_mx2_Value* l_instance);
  bbString m_ToString();
  virtual t_mx2_Value* m_ToRValue();
  virtual t_mx2_Value* m_RemoveSideEffects(t_mx2_Block* l_block);
  bbBool m_IsLValue();
  bbBool m_IsAssignable();
  virtual t_mx2_Value* m_Invoke(bbArray<bbGCVar<t_mx2_Value>>* l_args);
  virtual t_mx2_Value* m_Index(bbArray<bbGCVar<t_mx2_Value>>* l_args);
  virtual bbBool m_HasSideEffects();
  virtual t_mx2_Value* m_GenInstance(bbArray<bbGCVar<t_mx2_Type>>* l_types);
  virtual t_mx2_Value* m_FindValue(bbString l_ident);
  virtual void m_CheckAccess(t_mx2_Scope* l_tscope);
  virtual t_mx2_Stmt* m_Assign(t_mx2_PNode* l_pnode,bbString l_op,t_mx2_Value* l_value,t_mx2_Block* l_block);

  t_mx2_Value(){
  }
};

struct t_mx2_LiteralValue : public t_mx2_Value{

  const char *typeName()const{return "t_mx2_LiteralValue";}

  bbString m_value{};

  t_mx2_LiteralValue(t_mx2_Type* l_type,bbString l_value);

  t_mx2_Value* m_UpCast(t_mx2_Type* l_type);
  bbString m_ToString();
  t_mx2_Value* m_RemoveSideEffects(t_mx2_Block* l_block);
  bbBool m_HasSideEffects();

  t_mx2_LiteralValue(){
  }
};

struct t_mx2_TypeValue : public t_mx2_Value{

  const char *typeName()const{return "t_mx2_TypeValue";}

  bbGCVar<t_mx2_Type> m_ttype{};

  void gcMark();

  t_mx2_TypeValue(t_mx2_Type* l_ttype);

  bbString m_ToString();
  t_mx2_Value* m_FindValue(bbString l_ident);

  t_mx2_TypeValue(){
  }
};

struct t_mx2_UpCastValue : public t_mx2_Value{

  const char *typeName()const{return "t_mx2_UpCastValue";}

  bbGCVar<t_mx2_Value> m_value{};

  void gcMark();

  t_mx2_UpCastValue(t_mx2_Type* l_type,t_mx2_Value* l_value);

  bbString m_ToString();
  t_mx2_Value* m_RemoveSideEffects(t_mx2_Block* l_block);
  bbBool m_HasSideEffects();
  void m_CheckAccess(t_mx2_Scope* l_tscope);

  t_mx2_UpCastValue(){
  }
};

struct t_mx2_ExplicitCastValue : public t_mx2_Value{

  const char *typeName()const{return "t_mx2_ExplicitCastValue";}

  bbGCVar<t_mx2_Value> m_value{};

  void gcMark();

  t_mx2_ExplicitCastValue(t_mx2_Type* l_type,t_mx2_Value* l_value);

  bbString m_ToString();
  t_mx2_Value* m_RemoveSideEffects(t_mx2_Block* l_block);
  bbBool m_HasSideEffects();

  t_mx2_ExplicitCastValue(){
  }
};

struct t_mx2_SelfValue : public t_mx2_Value{

  const char *typeName()const{return "t_mx2_SelfValue";}

  bbGCVar<t_mx2_ClassType> m_ctype{};

  void gcMark();

  t_mx2_SelfValue(t_mx2_ClassType* l_ctype);

  bbString m_ToString();

  t_mx2_SelfValue(){
  }
};

struct t_mx2_SuperValue : public t_mx2_Value{

  const char *typeName()const{return "t_mx2_SuperValue";}

  bbGCVar<t_mx2_ClassType> m_ctype{};

  void gcMark();

  t_mx2_SuperValue(t_mx2_ClassType* l_ctype);

  bbString m_ToString();

  t_mx2_SuperValue(){
  }
};

struct t_mx2_NullValue : public t_mx2_Value{

  const char *typeName()const{return "t_mx2_NullValue";}

  t_mx2_NullValue();

  t_mx2_Value* m_UpCast(t_mx2_Type* l_type);
  bbString m_ToString();
  t_mx2_Value* m_ToRValue();
};

struct t_mx2_InvokeValue : public t_mx2_Value{

  const char *typeName()const{return "t_mx2_InvokeValue";}

  bbGCVar<t_mx2_FuncType> m_ftype{};
  bbGCVar<t_mx2_Value> m_value{};
  bbGCVar<bbArray<bbGCVar<t_mx2_Value>>> m_args{};

  void gcMark();

  t_mx2_InvokeValue(t_mx2_Value* l_value,bbArray<bbGCVar<t_mx2_Value>>* l_args);

  bbString m_ToString();
  t_mx2_Value* m_RemoveSideEffects(t_mx2_Block* l_block);
  bbBool m_HasSideEffects();
  void m_CheckAccess(t_mx2_Scope* l_scope);

  t_mx2_InvokeValue(){
  }
};

struct t_mx2_InvokeNewValue : public t_mx2_Value{

  const char *typeName()const{return "t_mx2_InvokeNewValue";}

  bbGCVar<t_mx2_ClassType> m_ctype{};
  bbGCVar<bbArray<bbGCVar<t_mx2_Value>>> m_args{};

  void gcMark();

  t_mx2_InvokeNewValue(t_mx2_ClassType* l_ctype,bbArray<bbGCVar<t_mx2_Value>>* l_args);

  bbString m_ToString();

  t_mx2_InvokeNewValue(){
  }
};

struct t_mx2_NewObjectValue : public t_mx2_Value{

  const char *typeName()const{return "t_mx2_NewObjectValue";}

  bbGCVar<t_mx2_ClassType> m_ctype{};
  bbGCVar<t_mx2_FuncValue> m_ctor{};
  bbGCVar<bbArray<bbGCVar<t_mx2_Value>>> m_args{};

  void gcMark();

  t_mx2_NewObjectValue(t_mx2_ClassType* l_ctype,t_mx2_FuncValue* l_ctor,bbArray<bbGCVar<t_mx2_Value>>* l_args);

  bbString m_ToString();
  t_mx2_Value* m_RemoveSideEffects(t_mx2_Block* l_block);
  bbBool m_HasSideEffects();

  t_mx2_NewObjectValue(){
  }
};

struct t_mx2_NewArrayValue : public t_mx2_Value{

  const char *typeName()const{return "t_mx2_NewArrayValue";}

  bbGCVar<t_mx2_ArrayType> m_atype{};
  bbGCVar<bbArray<bbGCVar<t_mx2_Value>>> m_sizes{};
  bbGCVar<bbArray<bbGCVar<t_mx2_Value>>> m_inits{};

  void gcMark();

  t_mx2_NewArrayValue(t_mx2_ArrayType* l_atype,bbArray<bbGCVar<t_mx2_Value>>* l_sizes,bbArray<bbGCVar<t_mx2_Value>>* l_inits);

  bbString m_ToString();
  t_mx2_Value* m_RemoveSideEffects(t_mx2_Block* l_block);
  bbBool m_HasSideEffects();

  t_mx2_NewArrayValue(){
  }
};

struct t_mx2_ArrayIndexValue : public t_mx2_Value{

  const char *typeName()const{return "t_mx2_ArrayIndexValue";}

  bbGCVar<t_mx2_ArrayType> m_atype{};
  bbGCVar<t_mx2_Value> m_value{};
  bbGCVar<bbArray<bbGCVar<t_mx2_Value>>> m_args{};

  void gcMark();

  t_mx2_ArrayIndexValue(t_mx2_ArrayType* l_atype,t_mx2_Value* l_value,bbArray<bbGCVar<t_mx2_Value>>* l_args);

  bbString m_ToString();
  t_mx2_Value* m_RemoveSideEffects(t_mx2_Block* l_block);
  bbBool m_HasSideEffects();

  t_mx2_ArrayIndexValue(){
  }
};

struct t_mx2_StringIndexValue : public t_mx2_Value{

  const char *typeName()const{return "t_mx2_StringIndexValue";}

  bbGCVar<t_mx2_Value> m_value{};
  bbGCVar<t_mx2_Value> m_index{};

  void gcMark();

  t_mx2_StringIndexValue(t_mx2_Value* l_value,t_mx2_Value* l_index);

  bbString m_ToString();
  t_mx2_Value* m_RemoveSideEffects(t_mx2_Block* l_block);
  bbBool m_HasSideEffects();

  t_mx2_StringIndexValue(){
  }
};

struct t_mx2_PointerIndexValue : public t_mx2_Value{

  const char *typeName()const{return "t_mx2_PointerIndexValue";}

  bbGCVar<t_mx2_Value> m_value{};
  bbGCVar<t_mx2_Value> m_index{};

  void gcMark();

  t_mx2_PointerIndexValue(t_mx2_Type* l_elemType,t_mx2_Value* l_value,t_mx2_Value* l_index);

  bbString m_ToString();
  t_mx2_Value* m_RemoveSideEffects(t_mx2_Block* l_block);
  bbBool m_HasSideEffects();

  t_mx2_PointerIndexValue(){
  }
};

struct t_mx2_UnaryopValue : public t_mx2_Value{

  const char *typeName()const{return "t_mx2_UnaryopValue";}

  bbString m_op{};
  bbGCVar<t_mx2_Value> m_value{};

  void gcMark();

  t_mx2_UnaryopValue(t_mx2_Type* l_type,bbString l_op,t_mx2_Value* l_value);

  bbString m_ToString();

  t_mx2_UnaryopValue(){
  }
};

struct t_mx2_BinaryopValue : public t_mx2_Value{

  const char *typeName()const{return "t_mx2_BinaryopValue";}

  bbString m_op{};
  bbGCVar<t_mx2_Value> m_lhs{};
  bbGCVar<t_mx2_Value> m_rhs{};

  void gcMark();

  t_mx2_BinaryopValue(t_mx2_Type* l_type,bbString l_op,t_mx2_Value* l_lhs,t_mx2_Value* l_rhs);

  bbString m_ToString();

  t_mx2_BinaryopValue(){
  }
};

struct t_mx2_IfThenElseValue : public t_mx2_Value{

  const char *typeName()const{return "t_mx2_IfThenElseValue";}

  bbGCVar<t_mx2_Value> m_value{};
  bbGCVar<t_mx2_Value> m_thenValue{};
  bbGCVar<t_mx2_Value> m_elseValue{};

  void gcMark();

  t_mx2_IfThenElseValue(t_mx2_Type* l_type,t_mx2_Value* l_value,t_mx2_Value* l_thenValue,t_mx2_Value* l_elseValue);

  t_mx2_IfThenElseValue(){
  }
};

struct t_mx2_PointerValue : public t_mx2_Value{

  const char *typeName()const{return "t_mx2_PointerValue";}

  bbGCVar<t_mx2_Value> m_value{};

  void gcMark();

  t_mx2_PointerValue(t_mx2_Value* l_value);

  bbString m_ToString();

  t_mx2_PointerValue(){
  }
};

#endif
