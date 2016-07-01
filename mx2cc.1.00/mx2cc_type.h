
#ifndef MX2_MX2CC_TYPE_H
#define MX2_MX2CC_TYPE_H

#include <bbmonkey.h>

// ***** External *****

#include "mx2cc_node.h"

struct t_mx2_ClassType;
struct t_mx2_EnumType;
struct t_mx2_NamespaceType;
struct t_mx2_FuncListType;
struct t_mx2_Value;

// ***** Internal *****

struct t_mx2_Type;
struct t_mx2_PrimType;
struct t_mx2_ProxyType;
struct t_mx2_ArrayType;
struct t_mx2_PointerType;
struct t_mx2_FuncType;
struct t_mx2_GenArgType;
struct t_mx2_VoidType;
struct t_mx2_BadType;
struct t_mx2_NullType;

extern bbGCRootVar<t_mx2_ClassType> g_mx2_Type_ArrayClass;
extern bbGCRootVar<t_mx2_BadType> g_mx2_Type_BadType;
extern bbGCRootVar<t_mx2_PrimType> g_mx2_Type_BoolType;
extern bbGCRootVar<t_mx2_PrimType> g_mx2_Type_ByteType;
extern bbGCRootVar<t_mx2_ClassType> g_mx2_Type_CStringClass;
extern bbGCRootVar<t_mx2_PrimType> g_mx2_Type_DoubleType;
extern bbGCRootVar<t_mx2_ClassType> g_mx2_Type_ExceptionClass;
extern bbGCRootVar<t_mx2_PrimType> g_mx2_Type_FloatType;
extern bbGCRootVar<t_mx2_PrimType> g_mx2_Type_IntType;
extern bbGCRootVar<t_mx2_PrimType> g_mx2_Type_LongType;
extern bbInt g_mx2_Type_MAX_0DISTANCE;
extern bbGCRootVar<t_mx2_NullType> g_mx2_Type_NullType;
extern bbGCRootVar<t_mx2_ClassType> g_mx2_Type_ObjectClass;
extern bbGCRootVar<t_mx2_PrimType> g_mx2_Type_ShortType;
extern bbGCRootVar<t_mx2_PrimType> g_mx2_Type_StringType;
extern bbInt g_mx2_Type_TYPE_0GENERIC;
extern bbGCRootVar<t_mx2_ClassType> g_mx2_Type_ThrowableClass;
extern bbGCRootVar<t_mx2_PrimType> g_mx2_Type_UByteType;
extern bbGCRootVar<t_mx2_PrimType> g_mx2_Type_UIntType;
extern bbGCRootVar<t_mx2_PrimType> g_mx2_Type_ULongType;
extern bbGCRootVar<t_mx2_PrimType> g_mx2_Type_UShortType;
extern bbGCRootVar<t_mx2_ClassType> g_mx2_Type_Utf8StringClass;
extern bbGCRootVar<t_mx2_VoidType> g_mx2_Type_VoidType;
extern bbGCRootVar<t_mx2_ClassType> g_mx2_Type_WStringClass;

extern t_mx2_FuncType* g_mx2_TCast_1Tt_mx2_FuncType_2(t_mx2_Type* l_type);
extern t_mx2_GenArgType* g_mx2_TCast_1Tt_mx2_GenArgType_2(t_mx2_Type* l_type);
extern t_mx2_ClassType* g_mx2_TCast_1Tt_mx2_ClassType_2(t_mx2_Type* l_type);
extern t_mx2_PointerType* g_mx2_TCast_1Tt_mx2_PointerType_2(t_mx2_Type* l_type);
extern t_mx2_PrimType* g_mx2_TCast_1Tt_mx2_PrimType_2(t_mx2_Type* l_type);
extern t_mx2_ArrayType* g_mx2_TCast_1Tt_mx2_ArrayType_2(t_mx2_Type* l_type);
extern t_mx2_EnumType* g_mx2_TCast_1Tt_mx2_EnumType_2(t_mx2_Type* l_type);
extern t_mx2_VoidType* g_mx2_TCast_1Tt_mx2_VoidType_2(t_mx2_Type* l_type);
extern t_mx2_ClassType* g_mx2_TCast_1Tt_mx2_ClassType_2(t_mx2_SNode* l_node);
extern t_mx2_NamespaceType* g_mx2_TCast_1Tt_mx2_NamespaceType_2(t_mx2_Type* l_type);
extern t_mx2_NamespaceType* g_mx2_TCast_1Tt_mx2_NamespaceType_2(t_mx2_SNode* l_node);
extern t_mx2_EnumType* g_mx2_TCast_1Tt_mx2_EnumType_2(t_mx2_SNode* l_node);
extern t_mx2_FuncListType* g_mx2_TCast_1Tt_mx2_FuncListType_2(t_mx2_Type* l_type);

struct t_mx2_Type : public t_mx2_SNode{

  const char *typeName()const{return "t_mx2_Type";}

  bbGCVar<t_mx2_Type> m__0alias{};
  bbInt m_flags{};

  void gcMark();

  t_mx2_Type();

  virtual bbString m_TypeId()=0;
  t_mx2_Value* m_ToValue(t_mx2_Value* l_instance);
  t_mx2_Type* m_ToType();
  virtual bbString m_Name()=0;
  bbBool m_IsGeneric();
  virtual t_mx2_Value* m_Invoke(bbArray<bbGCVar<t_mx2_Value>>* l_args,t_mx2_Value* l_value);
  virtual t_mx2_Type* m_InferType(t_mx2_Type* l_type,bbArray<bbGCVar<t_mx2_Type>>* l_args);
  virtual t_mx2_Value* m_Index(bbArray<bbGCVar<t_mx2_Value>>* l_args,t_mx2_Value* l_value);
  virtual t_mx2_Type* m_GenInstance(bbArray<bbGCVar<t_mx2_Type>>* l_types);
  virtual t_mx2_Type* m_FindType(bbString l_ident);
  virtual t_mx2_SNode* m_FindNode(bbString l_ident);
  virtual bbBool m_ExtendsType(t_mx2_Type* l_type);
  virtual bbBool m_Equals(t_mx2_Type* l_type);
  virtual bbInt m_DistanceToType(t_mx2_Type* l_type);
  t_mx2_Type* m_Dealias();
  virtual bbBool m_CanCastToType(t_mx2_Type* l_type);
  bbBool m__eq(t_mx2_Type* l_type);
  bbBool m__ne(t_mx2_Type* l_type);
  bbInt m__cmp(t_mx2_Type* l_type);
};

struct t_mx2_PrimType : public t_mx2_Type{

  const char *typeName()const{return "t_mx2_PrimType";}

  bbGCVar<t_mx2_ClassType> m_ctype{};

  void gcMark();

  t_mx2_PrimType(t_mx2_ClassType* l_ctype);

  bbString m_TypeId();
  bbString m_ToString();
  bbString m_Name();
  bbBool m_IsUnsignedIntegral();
  bbBool m_IsSignedIntegral();
  bbBool m_IsReal();
  bbBool m_IsNumeric();
  bbBool m_IsIntegral();
  t_mx2_Value* m_Index(bbArray<bbGCVar<t_mx2_Value>>* l_args,t_mx2_Value* l_value);
  t_mx2_Type* m_FindType(bbString l_ident);
  t_mx2_SNode* m_FindNode(bbString l_ident);
  bbBool m_ExtendsType(t_mx2_Type* l_type);
  bbBool m_Equals(t_mx2_Type* l_type);
  bbInt m_DistanceToType(t_mx2_Type* l_type);
  bbBool m_CanCastToType(t_mx2_Type* l_type);

  t_mx2_PrimType(){
  }
};

struct t_mx2_ProxyType : public t_mx2_Type{

  const char *typeName()const{return "t_mx2_ProxyType";}

  bbString m_TypeId();
  t_mx2_Value* m_ToValue(t_mx2_Value* l_instance);
  bbString m_ToString();
  bbString m_Name();
  t_mx2_Value* m_Invoke(bbArray<bbGCVar<t_mx2_Value>>* l_args,t_mx2_Value* l_value);
  t_mx2_Type* m_InferType(t_mx2_Type* l_type,bbArray<bbGCVar<t_mx2_Type>>* l_args);
  t_mx2_Value* m_Index(bbArray<bbGCVar<t_mx2_Value>>* l_args,t_mx2_Value* l_value);
  t_mx2_Type* m_GenInstance(bbArray<bbGCVar<t_mx2_Type>>* l_types);
  t_mx2_Type* m_FindType(bbString l_ident);
  t_mx2_SNode* m_FindNode(bbString l_ident);
  bbBool m_ExtendsType(t_mx2_Type* l_type);
  bbBool m_Equals(t_mx2_Type* l_type);
  bbInt m_DistanceToType(t_mx2_Type* l_type);
  bbBool m_CanCastToType(t_mx2_Type* l_type);

  t_mx2_ProxyType(){
  }
};

struct t_mx2_ArrayType : public t_mx2_Type{

  const char *typeName()const{return "t_mx2_ArrayType";}

  bbGCVar<t_mx2_Type> m_elemType{};
  bbInt m_rank{};
  bbGCVar<t_mx2_ClassType> m_ctype{};

  void gcMark();

  t_mx2_ArrayType(t_mx2_Type* l_elemType,bbInt l_rank);

  bbString m_TypeId();
  bbString m_ToString();
  bbString m_Name();
  t_mx2_Type* m_InferType(t_mx2_Type* l_type,bbArray<bbGCVar<t_mx2_Type>>* l_infered);
  t_mx2_Value* m_Index(bbArray<bbGCVar<t_mx2_Value>>* l_args,t_mx2_Value* l_value);
  t_mx2_Type* m_FindType(bbString l_ident);
  t_mx2_SNode* m_FindNode(bbString l_ident);
  bbBool m_Equals(t_mx2_Type* l_type);
  bbInt m_DistanceToType(t_mx2_Type* l_type);

  t_mx2_ArrayType(){
  }
};

struct t_mx2_PointerType : public t_mx2_Type{

  const char *typeName()const{return "t_mx2_PointerType";}

  bbGCVar<t_mx2_Type> m_elemType{};

  void gcMark();

  t_mx2_PointerType(t_mx2_Type* l_elemType);

  bbString m_TypeId();
  bbString m_ToString();
  bbString m_Name();
  t_mx2_Type* m_InferType(t_mx2_Type* l_type,bbArray<bbGCVar<t_mx2_Type>>* l_infered);
  t_mx2_Value* m_Index(bbArray<bbGCVar<t_mx2_Value>>* l_args,t_mx2_Value* l_value);
  bbBool m_Equals(t_mx2_Type* l_type);
  bbInt m_DistanceToType(t_mx2_Type* l_type);
  bbBool m_CanCastToType(t_mx2_Type* l_type);

  t_mx2_PointerType(){
  }
};

struct t_mx2_FuncType : public t_mx2_Type{

  const char *typeName()const{return "t_mx2_FuncType";}

  bbGCVar<t_mx2_Type> m_retType{};
  bbGCVar<bbArray<bbGCVar<t_mx2_Type>>> m_argTypes{};

  void gcMark();

  t_mx2_FuncType(t_mx2_Type* l_retType,bbArray<bbGCVar<t_mx2_Type>>* l_argTypes);

  bbString m_TypeId();
  bbString m_ToString();
  bbString m_Name();
  t_mx2_Value* m_Invoke(bbArray<bbGCVar<t_mx2_Value>>* l_args,t_mx2_Value* l_value);
  t_mx2_Type* m_InferType(t_mx2_Type* l_type,bbArray<bbGCVar<t_mx2_Type>>* l_infered);
  bbBool m_Equals(t_mx2_Type* l_type);
  bbInt m_DistanceToType(t_mx2_Type* l_type);

  t_mx2_FuncType(){
  }
};

struct t_mx2_GenArgType : public t_mx2_Type{

  const char *typeName()const{return "t_mx2_GenArgType";}

  bbInt m_index{};
  bbString m_ident{};
  bbGCVar<bbArray<bbGCVar<t_mx2_Type>>> m_types{};
  bbGCVar<t_mx2_GenArgType> m_instanceOf{};

  void gcMark();

  t_mx2_GenArgType(bbInt l_index,bbString l_ident,bbArray<bbGCVar<t_mx2_Type>>* l_types,t_mx2_GenArgType* l_instanceOf);

  bbString m_TypeId();
  bbString m_ToString();
  bbString m_Name();
  t_mx2_Type* m_InferType(t_mx2_Type* l_type,bbArray<bbGCVar<t_mx2_Type>>* l_infered);
  t_mx2_Type* m_GenInstance(bbArray<bbGCVar<t_mx2_Type>>* l_types);
  bbBool m_Equals(t_mx2_Type* l_type);

  t_mx2_GenArgType(){
  }
};

struct t_mx2_VoidType : public t_mx2_Type{

  const char *typeName()const{return "t_mx2_VoidType";}

  bbString m_TypeId();
  bbString m_ToString();
  bbString m_Name();

  t_mx2_VoidType(){
  }
};

struct t_mx2_BadType : public t_mx2_Type{

  const char *typeName()const{return "t_mx2_BadType";}

  bbString m_TypeId();
  bbString m_ToString();
  bbString m_Name();
  bbBool m_Equals(t_mx2_Type* l_type);

  t_mx2_BadType(){
  }
};

struct t_mx2_NullType : public t_mx2_Type{

  const char *typeName()const{return "t_mx2_NullType";}

  bbString m_TypeId();
  bbString m_ToString();
  bbString m_Name();
  bbBool m_Equals(t_mx2_Type* l_type);
  bbInt m_DistanceToType(t_mx2_Type* l_type);

  t_mx2_NullType(){
  }
};

#endif
