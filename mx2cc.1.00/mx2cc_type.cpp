
#include "mx2cc_type.h"

// ***** External *****

#include "../../../../../modules/monkey/monkey.buildv1.0.0/desktop_release_linux/monkey_types.h"
#include "mx2cc_class.h"
#include "mx2cc_decl.h"
#include "mx2cc_enum.h"
#include "mx2cc_errors.h"
#include "mx2cc_func.h"
#include "mx2cc_namespace.h"
#include "mx2cc_value.h"

extern bbBool g_mx2_AnyTypeGeneric(bbArray<bbGCVar<t_mx2_Type>>* l_types);
extern bbString g_mx2_Join_1Tt_mx2_Type_2(bbArray<bbGCVar<t_mx2_Type>>* l_bits,bbString l_sep);
extern bbBool g_mx2_TypesEqual(bbArray<bbGCVar<t_mx2_Type>>* l_lhs,bbArray<bbGCVar<t_mx2_Type>>* l_rhs);

// ***** Internal *****

bbGCRootVar<t_mx2_ClassType> g_mx2_Type_ArrayClass;
bbGCRootVar<t_mx2_BadType> g_mx2_Type_BadType;
bbGCRootVar<t_mx2_PrimType> g_mx2_Type_BoolType;
bbGCRootVar<t_mx2_PrimType> g_mx2_Type_ByteType;
bbGCRootVar<t_mx2_ClassType> g_mx2_Type_CStringClass;
bbGCRootVar<t_mx2_PrimType> g_mx2_Type_DoubleType;
bbGCRootVar<t_mx2_ClassType> g_mx2_Type_ExceptionClass;
bbGCRootVar<t_mx2_PrimType> g_mx2_Type_FloatType;
bbGCRootVar<t_mx2_PrimType> g_mx2_Type_IntType;
bbGCRootVar<t_mx2_PrimType> g_mx2_Type_LongType;
bbInt g_mx2_Type_MAX_0DISTANCE;
bbGCRootVar<t_mx2_NullType> g_mx2_Type_NullType;
bbGCRootVar<t_mx2_ClassType> g_mx2_Type_ObjectClass;
bbGCRootVar<t_mx2_PrimType> g_mx2_Type_ShortType;
bbGCRootVar<t_mx2_PrimType> g_mx2_Type_StringType;
bbInt g_mx2_Type_TYPE_0GENERIC;
bbGCRootVar<t_mx2_ClassType> g_mx2_Type_ThrowableClass;
bbGCRootVar<t_mx2_PrimType> g_mx2_Type_UByteType;
bbGCRootVar<t_mx2_PrimType> g_mx2_Type_UIntType;
bbGCRootVar<t_mx2_PrimType> g_mx2_Type_ULongType;
bbGCRootVar<t_mx2_PrimType> g_mx2_Type_UShortType;
bbGCRootVar<t_mx2_ClassType> g_mx2_Type_Utf8StringClass;
bbGCRootVar<t_mx2_VoidType> g_mx2_Type_VoidType;
bbGCRootVar<t_mx2_ClassType> g_mx2_Type_WStringClass;

t_mx2_FuncType* g_mx2_TCast_1Tt_mx2_FuncType_2(t_mx2_Type* l_type){
  if(bbBool(l_type)){
    return bb_object_cast<t_mx2_FuncType*>(l_type->m__0alias);
  }
  return ((t_mx2_FuncType*)0);
}

t_mx2_GenArgType* g_mx2_TCast_1Tt_mx2_GenArgType_2(t_mx2_Type* l_type){
  if(bbBool(l_type)){
    return bb_object_cast<t_mx2_GenArgType*>(l_type->m__0alias);
  }
  return ((t_mx2_GenArgType*)0);
}

t_mx2_ClassType* g_mx2_TCast_1Tt_mx2_ClassType_2(t_mx2_Type* l_type){
  if(bbBool(l_type)){
    return bb_object_cast<t_mx2_ClassType*>(l_type->m__0alias);
  }
  return ((t_mx2_ClassType*)0);
}

t_mx2_PointerType* g_mx2_TCast_1Tt_mx2_PointerType_2(t_mx2_Type* l_type){
  if(bbBool(l_type)){
    return bb_object_cast<t_mx2_PointerType*>(l_type->m__0alias);
  }
  return ((t_mx2_PointerType*)0);
}

t_mx2_PrimType* g_mx2_TCast_1Tt_mx2_PrimType_2(t_mx2_Type* l_type){
  if(bbBool(l_type)){
    return bb_object_cast<t_mx2_PrimType*>(l_type->m__0alias);
  }
  return ((t_mx2_PrimType*)0);
}

t_mx2_ArrayType* g_mx2_TCast_1Tt_mx2_ArrayType_2(t_mx2_Type* l_type){
  if(bbBool(l_type)){
    return bb_object_cast<t_mx2_ArrayType*>(l_type->m__0alias);
  }
  return ((t_mx2_ArrayType*)0);
}

t_mx2_EnumType* g_mx2_TCast_1Tt_mx2_EnumType_2(t_mx2_Type* l_type){
  if(bbBool(l_type)){
    return bb_object_cast<t_mx2_EnumType*>(l_type->m__0alias);
  }
  return ((t_mx2_EnumType*)0);
}

t_mx2_VoidType* g_mx2_TCast_1Tt_mx2_VoidType_2(t_mx2_Type* l_type){
  if(bbBool(l_type)){
    return bb_object_cast<t_mx2_VoidType*>(l_type->m__0alias);
  }
  return ((t_mx2_VoidType*)0);
}

t_mx2_ClassType* g_mx2_TCast_1Tt_mx2_ClassType_2(t_mx2_SNode* l_node){
  struct f0_t : public bbGCFrame{
    t_mx2_Type* l_type{};
    void gcMark(){
      bbGCMarkPtr(l_type);
    }
  }f0{};
  f0.l_type=bb_object_cast<t_mx2_Type*>(l_node);
  if(bbBool(f0.l_type)){
    return bb_object_cast<t_mx2_ClassType*>(f0.l_type->m__0alias);
  }
  return ((t_mx2_ClassType*)0);
}

t_mx2_NamespaceType* g_mx2_TCast_1Tt_mx2_NamespaceType_2(t_mx2_Type* l_type){
  if(bbBool(l_type)){
    return bb_object_cast<t_mx2_NamespaceType*>(l_type->m__0alias);
  }
  return ((t_mx2_NamespaceType*)0);
}

t_mx2_NamespaceType* g_mx2_TCast_1Tt_mx2_NamespaceType_2(t_mx2_SNode* l_node){
  struct f0_t : public bbGCFrame{
    t_mx2_Type* l_type{};
    void gcMark(){
      bbGCMarkPtr(l_type);
    }
  }f0{};
  f0.l_type=bb_object_cast<t_mx2_Type*>(l_node);
  if(bbBool(f0.l_type)){
    return bb_object_cast<t_mx2_NamespaceType*>(f0.l_type->m__0alias);
  }
  return ((t_mx2_NamespaceType*)0);
}

t_mx2_EnumType* g_mx2_TCast_1Tt_mx2_EnumType_2(t_mx2_SNode* l_node){
  struct f0_t : public bbGCFrame{
    t_mx2_Type* l_type{};
    void gcMark(){
      bbGCMarkPtr(l_type);
    }
  }f0{};
  f0.l_type=bb_object_cast<t_mx2_Type*>(l_node);
  if(bbBool(f0.l_type)){
    return bb_object_cast<t_mx2_EnumType*>(f0.l_type->m__0alias);
  }
  return ((t_mx2_EnumType*)0);
}

t_mx2_FuncListType* g_mx2_TCast_1Tt_mx2_FuncListType_2(t_mx2_Type* l_type){
  if(bbBool(l_type)){
    return bb_object_cast<t_mx2_FuncListType*>(l_type->m__0alias);
  }
  return ((t_mx2_FuncListType*)0);
}

void t_mx2_Type::gcMark(){
  t_mx2_SNode::gcMark();
  bbGCMark(m__0alias);
}

t_mx2_Type::t_mx2_Type(){
  this->m__0alias=this;
}

t_mx2_Value* t_mx2_Type::m_ToValue(t_mx2_Value* l_instance){
  return ((t_mx2_Value*)(bbGCNew<t_mx2_TypeValue>(this)));
}

t_mx2_Type* t_mx2_Type::m_ToType(){
  return this;
}

bbBool t_mx2_Type::m_IsGeneric(){
  return bbBool((this->m_flags&g_mx2_Type_TYPE_0GENERIC));
}

t_mx2_Value* t_mx2_Type::m_Invoke(bbArray<bbGCVar<t_mx2_Value>>* l_args,t_mx2_Value* l_value){
  throw bbGCNew<t_mx2_SemantEx>(((BB_T("Type '")+this->m_ToString())+BB_T("' cannot be invoked")));
}

t_mx2_Type* t_mx2_Type::m_InferType(t_mx2_Type* l_type,bbArray<bbGCVar<t_mx2_Type>>* l_args){
  if(this->m_Equals(l_type)){
    return l_type;
  }
  return ((t_mx2_Type*)0);
}

t_mx2_Value* t_mx2_Type::m_Index(bbArray<bbGCVar<t_mx2_Value>>* l_args,t_mx2_Value* l_value){
  throw bbGCNew<t_mx2_SemantEx>(((BB_T("Type '")+this->m_ToString())+BB_T("' cannot be indexed")));
}

t_mx2_Type* t_mx2_Type::m_GenInstance(bbArray<bbGCVar<t_mx2_Type>>* l_types){
  throw bbGCNew<t_mx2_SemantEx>(((BB_T("Type '")+this->m_ToString())+BB_T("' is not generic")));
}

t_mx2_Type* t_mx2_Type::m_FindType(bbString l_ident){
  throw bbGCNew<t_mx2_SemantEx>(((BB_T("Type '")+this->m_ToString())+BB_T("' has no scope")));
}

t_mx2_SNode* t_mx2_Type::m_FindNode(bbString l_ident){
  return ((t_mx2_SNode*)0);
}

bbBool t_mx2_Type::m_ExtendsType(t_mx2_Type* l_type){
  return this->m_Equals(l_type);
}

bbBool t_mx2_Type::m_Equals(t_mx2_Type* l_type){
  return l_type->m__eq(this);
}

bbInt t_mx2_Type::m_DistanceToType(t_mx2_Type* l_type){
  if(this->m_Equals(l_type)){
    return bbInt(0);
  }
  return -1;
}

t_mx2_Type* t_mx2_Type::m_Dealias(){
  return this->m__0alias;
}

bbBool t_mx2_Type::m_CanCastToType(t_mx2_Type* l_type){
  return this->m_Equals(l_type);
}

bbBool t_mx2_Type::m__eq(t_mx2_Type* l_type){
  if(!bbBool(this)){
    return (((bbObject*)(l_type))==((bbObject*)0));
  }
  if(!bbBool(l_type)){
    return (((bbObject*)(this->m__0alias))==((bbObject*)0));
  }
  return (((bbObject*)(l_type->m__0alias))==((bbObject*)(this->m__0alias)));
}

bbBool t_mx2_Type::m__ne(t_mx2_Type* l_type){
  if(!bbBool(this)){
    return (((bbObject*)(l_type))!=((bbObject*)0));
  }
  if(!bbBool(l_type)){
    return (((bbObject*)(this->m__0alias))!=((bbObject*)0));
  }
  return (((bbObject*)(l_type->m__0alias))!=((bbObject*)(this->m__0alias)));
}

bbInt t_mx2_Type::m__cmp(t_mx2_Type* l_type){
  g_mx2_SemantError(BB_T("Type.Operator<=>()"));
  return bbInt(0);
}

void t_mx2_PrimType::gcMark(){
  t_mx2_Type::gcMark();
  bbGCMark(m_ctype);
}

t_mx2_PrimType::t_mx2_PrimType(t_mx2_ClassType* l_ctype){
  if(!bbBool(l_ctype)){
    puts(BB_T("No class for primtype!").c_str());fflush( stdout );
  }
  this->m_ctype=l_ctype;
}

bbString t_mx2_PrimType::m_TypeId(){
  if(this==g_mx2_Type_IntType){
    return BB_T("i");
  }else if(this==g_mx2_Type_FloatType){
    return BB_T("f");
  }else if(this==g_mx2_Type_StringType){
    return BB_T("s");
  }
  return BB_T("?");
}

bbString t_mx2_PrimType::m_ToString(){
  return this->m_ctype->m_cdecl->m_ident.slice(1);
}

bbString t_mx2_PrimType::m_Name(){
  return this->m_ctype->m_Name();
}

bbBool t_mx2_PrimType::m_IsUnsignedIntegral(){
  if(this==g_mx2_Type_UByteType||this==g_mx2_Type_UShortType||this==g_mx2_Type_UIntType||this==g_mx2_Type_ULongType){
    return true;
  }
  return false;
}

bbBool t_mx2_PrimType::m_IsSignedIntegral(){
  if(this==g_mx2_Type_ByteType||this==g_mx2_Type_ShortType||this==g_mx2_Type_IntType||this==g_mx2_Type_LongType){
    return true;
  }
  return false;
}

bbBool t_mx2_PrimType::m_IsReal(){
  if(this==g_mx2_Type_FloatType||this==g_mx2_Type_DoubleType){
    return true;
  }
  return false;
}

bbBool t_mx2_PrimType::m_IsNumeric(){
  if(this==g_mx2_Type_FloatType||this==g_mx2_Type_DoubleType){
    return true;
  }else if(this==g_mx2_Type_ByteType||this==g_mx2_Type_ShortType||this==g_mx2_Type_IntType||this==g_mx2_Type_LongType){
    return true;
  }else if(this==g_mx2_Type_UByteType||this==g_mx2_Type_UShortType||this==g_mx2_Type_UIntType||this==g_mx2_Type_ULongType){
    return true;
  }
  return false;
}

bbBool t_mx2_PrimType::m_IsIntegral(){
  if(this==g_mx2_Type_ByteType||this==g_mx2_Type_ShortType||this==g_mx2_Type_IntType||this==g_mx2_Type_LongType){
    return true;
  }else if(this==g_mx2_Type_UByteType||this==g_mx2_Type_UShortType||this==g_mx2_Type_UIntType||this==g_mx2_Type_ULongType){
    return true;
  }
  return false;
}

t_mx2_Value* t_mx2_PrimType::m_Index(bbArray<bbGCVar<t_mx2_Value>>* l_args,t_mx2_Value* l_value){
  struct f0_t : public bbGCFrame{
    t_mx2_Value* t0{};
    void gcMark(){
      bbGCMarkPtr(t0);
    }
  }f0{};
  if(this->m__ne(((t_mx2_Type*)(g_mx2_Type_StringType)))){
    return t_mx2_Type::m_Index(l_args,l_value);
  }
  if((l_args->length()!=1)){
    throw bbGCNew<t_mx2_SemantEx>(BB_T("Wrong number of indices"));
  }
  return ((t_mx2_Value*)(bbGCNew<t_mx2_StringIndexValue>(l_value,f0.t0=l_args->at(bbInt(0))->m_UpCast(((t_mx2_Type*)(g_mx2_Type_IntType))))));
}

t_mx2_Type* t_mx2_PrimType::m_FindType(bbString l_ident){
  return this->m_ctype->m_FindType(l_ident);
}

t_mx2_SNode* t_mx2_PrimType::m_FindNode(bbString l_ident){
  return this->m_ctype->m_FindNode(l_ident);
}

bbBool t_mx2_PrimType::m_ExtendsType(t_mx2_Type* l_type){
  return (l_type->m__eq(((t_mx2_Type*)(this)))||(this->m_ctype->m_DistanceToType(l_type)>=bbInt(0)));
}

bbBool t_mx2_PrimType::m_Equals(t_mx2_Type* l_type){
  return l_type->m__eq(((t_mx2_Type*)(this)));
}

bbInt t_mx2_PrimType::m_DistanceToType(t_mx2_Type* l_type){
  if(l_type->m__eq(((t_mx2_Type*)(this)))){
    return bbInt(0);
  }
  if(bbBool(g_mx2_TCast_1Tt_mx2_PrimType_2(l_type))){
    return g_mx2_Type_MAX_0DISTANCE;
  }
  if(l_type==((t_mx2_Type*)(g_mx2_Type_CStringClass))||l_type==((t_mx2_Type*)(g_mx2_Type_WStringClass))||l_type==((t_mx2_Type*)(g_mx2_Type_Utf8StringClass))){
    return g_mx2_Type_MAX_0DISTANCE;
  }
  return -1;
}

bbBool t_mx2_PrimType::m_CanCastToType(t_mx2_Type* l_type){
  if(bbBool(g_mx2_TCast_1Tt_mx2_PrimType_2(l_type))){
    return true;
  }
  if((this->m_IsIntegral()&&bbBool(g_mx2_TCast_1Tt_mx2_EnumType_2(l_type)))){
    return true;
  }
  if((this->m_IsIntegral()&&bbBool(g_mx2_TCast_1Tt_mx2_PointerType_2(l_type)))){
    return true;
  }
  return false;
}

bbString t_mx2_ProxyType::m_TypeId(){
  return this->m__0alias->m_TypeId();
}

t_mx2_Value* t_mx2_ProxyType::m_ToValue(t_mx2_Value* l_instance){
  return this->m__0alias->m_ToValue(l_instance);
}

bbString t_mx2_ProxyType::m_ToString(){
  return this->m__0alias->m_ToString();
}

bbString t_mx2_ProxyType::m_Name(){
  return this->m__0alias->m_Name();
}

t_mx2_Value* t_mx2_ProxyType::m_Invoke(bbArray<bbGCVar<t_mx2_Value>>* l_args,t_mx2_Value* l_value){
  return this->m__0alias->m_Invoke(l_args,l_value);
}

t_mx2_Type* t_mx2_ProxyType::m_InferType(t_mx2_Type* l_type,bbArray<bbGCVar<t_mx2_Type>>* l_args){
  return this->m__0alias->m_InferType(l_type,l_args);
}

t_mx2_Value* t_mx2_ProxyType::m_Index(bbArray<bbGCVar<t_mx2_Value>>* l_args,t_mx2_Value* l_value){
  return this->m__0alias->m_Index(l_args,l_value);
}

t_mx2_Type* t_mx2_ProxyType::m_GenInstance(bbArray<bbGCVar<t_mx2_Type>>* l_types){
  return this->m__0alias->m_GenInstance(l_types);
}

t_mx2_Type* t_mx2_ProxyType::m_FindType(bbString l_ident){
  return this->m__0alias->m_FindType(l_ident);
}

t_mx2_SNode* t_mx2_ProxyType::m_FindNode(bbString l_ident){
  return this->m__0alias->m_FindNode(l_ident);
}

bbBool t_mx2_ProxyType::m_ExtendsType(t_mx2_Type* l_type){
  return this->m__0alias->m_ExtendsType(l_type);
}

bbBool t_mx2_ProxyType::m_Equals(t_mx2_Type* l_type){
  return this->m__0alias->m_Equals(l_type);
}

bbInt t_mx2_ProxyType::m_DistanceToType(t_mx2_Type* l_type){
  return this->m__0alias->m_DistanceToType(l_type);
}

bbBool t_mx2_ProxyType::m_CanCastToType(t_mx2_Type* l_type){
  return this->m__0alias->m_CanCastToType(l_type);
}

void t_mx2_ArrayType::gcMark(){
  t_mx2_Type::gcMark();
  bbGCMark(m_elemType);
  bbGCMark(m_ctype);
}

t_mx2_ArrayType::t_mx2_ArrayType(t_mx2_Type* l_elemType,bbInt l_rank){
  this->m_elemType=l_elemType;
  this->m_rank=l_rank;
  this->m_ctype=g_mx2_Type_ArrayClass;
  if(l_elemType->m_IsGeneric()){
    this->m_flags|=g_mx2_Type_TYPE_0GENERIC;
  }
  if(!this->m_IsGeneric()){
    struct f1_t : public bbGCFrame{
      bbArray<bbGCVar<t_mx2_Type>>* l_types{};
      t_mx2_Type* t0{};
      void gcMark(){
        bbGCMarkPtr(l_types);
        bbGCMarkPtr(t0);
      }
    }f1{};
    f1.l_types=bbArray<bbGCVar<t_mx2_Type>>::create(1);
    f1.l_types->at(bbInt(0))=l_elemType;
    this->m_ctype=g_mx2_TCast_1Tt_mx2_ClassType_2(f1.t0=this->m_ctype->m_GenInstance(f1.l_types));
  }
  if(!bbBool(this->m_ctype)){
    g_mx2_SemantError(BB_T("ArrayType.New()"));
  }
}

bbString t_mx2_ArrayType::m_TypeId(){
  if((this->m_rank>1)){
    return ((BB_T("A")+bbString(this->m_rank))+this->m_elemType->m_TypeId());
  }
  return (BB_T("A")+this->m_elemType->m_TypeId());
}

bbString t_mx2_ArrayType::m_ToString(){
  return ((this->m_elemType->m_ToString()+BB_T("[,,,,,,,,,,").slice(bbInt(0),this->m_rank))+BB_T("]"));
}

bbString t_mx2_ArrayType::m_Name(){
  return ((this->m_elemType->m_Name()+BB_T("[,,,,,,,,,,").slice(bbInt(0),this->m_rank))+BB_T("]"));
}

t_mx2_Type* t_mx2_ArrayType::m_InferType(t_mx2_Type* l_type,bbArray<bbGCVar<t_mx2_Type>>* l_infered){
  struct f0_t : public bbGCFrame{
    t_mx2_ArrayType* l_atype{};
    t_mx2_Type* l_elemType{};
    void gcMark(){
      bbGCMarkPtr(l_atype);
      bbGCMarkPtr(l_elemType);
    }
  }f0{};
  if(!this->m_IsGeneric()){
    return t_mx2_Type::m_InferType(l_type,l_infered);
  }
  f0.l_atype=g_mx2_TCast_1Tt_mx2_ArrayType_2(l_type);
  if((!bbBool(f0.l_atype)||(this->m_rank!=f0.l_atype->m_rank))){
    return ((t_mx2_Type*)0);
  }
  f0.l_elemType=this->m_elemType->m_InferType(f0.l_atype->m_elemType,l_infered);
  if(!bbBool(f0.l_elemType)){
    return ((t_mx2_Type*)0);
  }
  return ((t_mx2_Type*)(bbGCNew<t_mx2_ArrayType>(f0.l_elemType,this->m_rank)));
}

t_mx2_Value* t_mx2_ArrayType::m_Index(bbArray<bbGCVar<t_mx2_Value>>* l_args,t_mx2_Value* l_value){
  struct f0_t : public bbGCFrame{
    bbArray<bbGCVar<t_mx2_Value>>* l_args{};
    f0_t(bbArray<bbGCVar<t_mx2_Value>>* l_args):l_args(l_args){
    }
    void gcMark(){
      bbGCMarkPtr(l_args);
    }
  }f0{l_args};
  if((f0.l_args->length()!=this->m_rank)){
    throw bbGCNew<t_mx2_SemantEx>(BB_T("Wrong number of indices"));
  }
  f0.l_args=f0.l_args->slice(bbInt(0));
  {
    bbInt l_i=bbInt(0);
    for(;(l_i<f0.l_args->length());l_i+=1){
      if(!bbBool(f0.l_args->at(l_i))){
        throw bbGCNew<t_mx2_SemantEx>(BB_T("Missing array index"));
      }
      f0.l_args->at(l_i)=f0.l_args->at(l_i)->m_UpCast(((t_mx2_Type*)(g_mx2_Type_IntType)));
    }
  }
  return ((t_mx2_Value*)(bbGCNew<t_mx2_ArrayIndexValue>(this,l_value,f0.l_args)));
}

t_mx2_Type* t_mx2_ArrayType::m_FindType(bbString l_ident){
  return this->m_ctype->m_FindType(l_ident);
}

t_mx2_SNode* t_mx2_ArrayType::m_FindNode(bbString l_ident){
  return this->m_ctype->m_FindNode(l_ident);
}

bbBool t_mx2_ArrayType::m_Equals(t_mx2_Type* l_type){
  struct f0_t : public bbGCFrame{
    t_mx2_ArrayType* l_atype{};
    void gcMark(){
      bbGCMarkPtr(l_atype);
    }
  }f0{};
  if((l_type->m__eq(((t_mx2_Type*)(this)))||l_type->m__eq(((t_mx2_Type*)(this->m_ctype))))){
    return true;
  }
  f0.l_atype=g_mx2_TCast_1Tt_mx2_ArrayType_2(l_type);
  return ((bbBool(f0.l_atype)&&(this->m_rank==f0.l_atype->m_rank))&&this->m_elemType->m_Equals(f0.l_atype->m_elemType));
}

bbInt t_mx2_ArrayType::m_DistanceToType(t_mx2_Type* l_type){
  struct f0_t : public bbGCFrame{
    t_mx2_PrimType* t0{};
    void gcMark(){
      bbGCMarkPtr(t0);
    }
  }f0{};
  if(this->m_Equals(l_type)){
    return bbInt(0);
  }
  if((f0.t0=g_mx2_TCast_1Tt_mx2_PrimType_2(l_type))->m__eq(((t_mx2_Type*)(g_mx2_Type_BoolType)))){
    return g_mx2_Type_MAX_0DISTANCE;
  }
  return -1;
}

void t_mx2_PointerType::gcMark(){
  t_mx2_Type::gcMark();
  bbGCMark(m_elemType);
}

t_mx2_PointerType::t_mx2_PointerType(t_mx2_Type* l_elemType){
  this->m_elemType=l_elemType;
  if(l_elemType->m_IsGeneric()){
    this->m_flags|=g_mx2_Type_TYPE_0GENERIC;
  }
}

bbString t_mx2_PointerType::m_TypeId(){
  return (BB_T("P")+this->m_elemType->m_TypeId());
}

bbString t_mx2_PointerType::m_ToString(){
  return (this->m_elemType->m_ToString()+BB_T(" Ptr"));
}

bbString t_mx2_PointerType::m_Name(){
  return (this->m_elemType->m_Name()+BB_T(" Ptr"));
}

t_mx2_Type* t_mx2_PointerType::m_InferType(t_mx2_Type* l_type,bbArray<bbGCVar<t_mx2_Type>>* l_infered){
  struct f0_t : public bbGCFrame{
    t_mx2_Type* l_elemType{};
    t_mx2_PointerType* l_ptype{};
    void gcMark(){
      bbGCMarkPtr(l_elemType);
      bbGCMarkPtr(l_ptype);
    }
  }f0{};
  if(!this->m_IsGeneric()){
    return t_mx2_Type::m_InferType(l_type,l_infered);
  }
  f0.l_ptype=g_mx2_TCast_1Tt_mx2_PointerType_2(l_type);
  if(!bbBool(f0.l_ptype)){
    return ((t_mx2_Type*)0);
  }
  f0.l_elemType=this->m_elemType->m_InferType(f0.l_ptype->m_elemType,l_infered);
  if(!bbBool(f0.l_elemType)){
    return ((t_mx2_Type*)0);
  }
  return ((t_mx2_Type*)(bbGCNew<t_mx2_PointerType>(f0.l_elemType)));
}

t_mx2_Value* t_mx2_PointerType::m_Index(bbArray<bbGCVar<t_mx2_Value>>* l_args,t_mx2_Value* l_value){
  struct f0_t : public bbGCFrame{
    t_mx2_Value* t0{};
    void gcMark(){
      bbGCMarkPtr(t0);
    }
  }f0{};
  if((l_args->length()!=1)){
    throw bbGCNew<t_mx2_SemantEx>(BB_T("Wrong number of indices"));
  }
  return ((t_mx2_Value*)(bbGCNew<t_mx2_PointerIndexValue>(this->m_elemType,l_value,f0.t0=l_args->at(bbInt(0))->m_UpCast(((t_mx2_Type*)(g_mx2_Type_IntType))))));
}

bbBool t_mx2_PointerType::m_Equals(t_mx2_Type* l_type){
  struct f0_t : public bbGCFrame{
    t_mx2_PointerType* l_ptype{};
    void gcMark(){
      bbGCMarkPtr(l_ptype);
    }
  }f0{};
  if(l_type->m__eq(((t_mx2_Type*)(this)))){
    return true;
  }
  f0.l_ptype=g_mx2_TCast_1Tt_mx2_PointerType_2(l_type);
  return (bbBool(f0.l_ptype)&&this->m_elemType->m_Equals(f0.l_ptype->m_elemType));
}

bbInt t_mx2_PointerType::m_DistanceToType(t_mx2_Type* l_type){
  struct f0_t : public bbGCFrame{
    t_mx2_PointerType* l_ptype{};
    t_mx2_Type* t0{};
    void gcMark(){
      bbGCMarkPtr(l_ptype);
      bbGCMarkPtr(t0);
    }
  }f0{};
  if(l_type->m__eq(((t_mx2_Type*)(this)))){
    return bbInt(0);
  }
  if((f0.t0=l_type->m_Dealias())->m__eq(((t_mx2_Type*)(g_mx2_Type_BoolType)))){
    return g_mx2_Type_MAX_0DISTANCE;
  }
  f0.l_ptype=g_mx2_TCast_1Tt_mx2_PointerType_2(l_type);
  if(!bbBool(f0.l_ptype)){
    return -1;
  }
  if(this->m_elemType->m_Equals(f0.l_ptype->m_elemType)){
    return bbInt(0);
  }
  if(f0.l_ptype->m_elemType->m__eq(((t_mx2_Type*)(g_mx2_Type_VoidType)))){
    return g_mx2_Type_MAX_0DISTANCE;
  }
  return -1;
}

bbBool t_mx2_PointerType::m_CanCastToType(t_mx2_Type* l_type){
  struct f0_t : public bbGCFrame{
    t_mx2_PrimType* l_ptype{};
    void gcMark(){
      bbGCMarkPtr(l_ptype);
    }
  }f0{};
  if(bbBool(g_mx2_TCast_1Tt_mx2_PointerType_2(l_type))){
    return true;
  }
  f0.l_ptype=g_mx2_TCast_1Tt_mx2_PrimType_2(l_type);
  if((bbBool(f0.l_ptype)&&f0.l_ptype->m_IsIntegral())){
    return true;
  }
  return false;
}

void t_mx2_FuncType::gcMark(){
  t_mx2_Type::gcMark();
  bbGCMark(m_retType);
  bbGCMark(m_argTypes);
}

t_mx2_FuncType::t_mx2_FuncType(t_mx2_Type* l_retType,bbArray<bbGCVar<t_mx2_Type>>* l_argTypes){
  this->m_retType=l_retType;
  this->m_argTypes=l_argTypes;
  if((l_retType->m_IsGeneric()||g_mx2_AnyTypeGeneric(l_argTypes))){
    this->m_flags|=g_mx2_Type_TYPE_0GENERIC;
  }
}

bbString t_mx2_FuncType::m_TypeId(){
  bbString l_args=bbString{};
  {
    bbInt l_0=bbInt(0);
    bbInt l_1=this->m_argTypes->length();
    for(;(l_0<l_1);l_0+=1){
      struct f2_t : public bbGCFrame{
        t_mx2_Type* l_arg{};
        void gcMark(){
          bbGCMarkPtr(l_arg);
        }
      }f2{};
      f2.l_arg=this->m_argTypes->at(l_0);
      l_args+=f2.l_arg->m_TypeId();
    }
  }
  return (((BB_T("F")+this->m_retType->m_TypeId())+l_args)+BB_T("E"));
}

bbString t_mx2_FuncType::m_ToString(){
  return (((this->m_retType->m_ToString()+BB_T("("))+g_mx2_Join_1Tt_mx2_Type_2(this->m_argTypes,BB_T(",")))+BB_T(")"));
}

bbString t_mx2_FuncType::m_Name(){
  bbString l_args=bbString{};
  {
    bbInt l_0=bbInt(0);
    bbInt l_1=this->m_argTypes->length();
    for(;(l_0<l_1);l_0+=1){
      struct f2_t : public bbGCFrame{
        t_mx2_Type* l_arg{};
        void gcMark(){
          bbGCMarkPtr(l_arg);
        }
      }f2{};
      f2.l_arg=this->m_argTypes->at(l_0);
      l_args+=(BB_T(",")+f2.l_arg->m_Name());
    }
  }
  return (((this->m_retType->m_Name()+BB_T("("))+l_args.slice(1))+BB_T(")"));
}

t_mx2_Value* t_mx2_FuncType::m_Invoke(bbArray<bbGCVar<t_mx2_Value>>* l_args,t_mx2_Value* l_value){
  struct f0_t : public bbGCFrame{
    bbArray<bbGCVar<t_mx2_Value>>* l_args{};
    f0_t(bbArray<bbGCVar<t_mx2_Value>>* l_args):l_args(l_args){
    }
    void gcMark(){
      bbGCMarkPtr(l_args);
    }
  }f0{l_args};
  if((f0.l_args->length()!=this->m_argTypes->length())){
    throw bbGCNew<t_mx2_SemantEx>((((BB_T("Wrong number of arguments - expecting ")+bbString(this->m_argTypes->length()))+BB_T(" not "))+bbString(f0.l_args->length())));
  }
  f0.l_args=f0.l_args->slice(bbInt(0));
  {
    bbInt l_i=bbInt(0);
    for(;(l_i<f0.l_args->length());l_i+=1){
      f0.l_args->at(l_i)=f0.l_args->at(l_i)->m_UpCast(this->m_argTypes->at(l_i));
    }
  }
  return ((t_mx2_Value*)(bbGCNew<t_mx2_InvokeValue>(l_value,f0.l_args)));
}

t_mx2_Type* t_mx2_FuncType::m_InferType(t_mx2_Type* l_type,bbArray<bbGCVar<t_mx2_Type>>* l_infered){
  struct f0_t : public bbGCFrame{
    bbArray<bbGCVar<t_mx2_Type>>* l_argTypes{};
    t_mx2_FuncType* l_ftype{};
    t_mx2_Type* l_retType{};
    void gcMark(){
      bbGCMarkPtr(l_argTypes);
      bbGCMarkPtr(l_ftype);
      bbGCMarkPtr(l_retType);
    }
  }f0{};
  if(!this->m_IsGeneric()){
    return t_mx2_Type::m_InferType(l_type,l_infered);
  }
  f0.l_ftype=g_mx2_TCast_1Tt_mx2_FuncType_2(l_type);
  if((!bbBool(f0.l_ftype)||(this->m_argTypes->length()!=f0.l_ftype->m_argTypes->length()))){
    return ((t_mx2_Type*)0);
  }
  f0.l_retType=this->m_retType->m_InferType(f0.l_ftype->m_retType,l_infered);
  if(!bbBool(f0.l_retType)){
    return ((t_mx2_Type*)0);
  }
  f0.l_argTypes=this->m_argTypes->slice(bbInt(0));
  {
    bbInt l_i=bbInt(0);
    for(;(l_i<f0.l_argTypes->length());l_i+=1){
      f0.l_argTypes->at(l_i)=f0.l_argTypes->at(l_i)->m_InferType(f0.l_ftype->m_argTypes->at(l_i),l_infered);
      if(!bbBool(f0.l_argTypes->at(l_i))){
        return ((t_mx2_Type*)0);
      }
    }
  }
  return ((t_mx2_Type*)(bbGCNew<t_mx2_FuncType>(f0.l_retType,f0.l_argTypes)));
}

bbBool t_mx2_FuncType::m_Equals(t_mx2_Type* l_type){
  struct f0_t : public bbGCFrame{
    t_mx2_FuncType* l_ftype{};
    void gcMark(){
      bbGCMarkPtr(l_ftype);
    }
  }f0{};
  if(l_type->m__eq(((t_mx2_Type*)(this)))){
    return true;
  }
  f0.l_ftype=g_mx2_TCast_1Tt_mx2_FuncType_2(l_type);
  if((!bbBool(f0.l_ftype)||(this->m_argTypes->length()!=f0.l_ftype->m_argTypes->length()))){
    return false;
  }
  return (this->m_retType->m_Equals(f0.l_ftype->m_retType)&&g_mx2_TypesEqual(this->m_argTypes,f0.l_ftype->m_argTypes));
}

bbInt t_mx2_FuncType::m_DistanceToType(t_mx2_Type* l_type){
  if(this->m_Equals(l_type)){
    return bbInt(0);
  }
  return -1;
}

void t_mx2_GenArgType::gcMark(){
  t_mx2_Type::gcMark();
  bbGCMark(m_types);
  bbGCMark(m_instanceOf);
}

t_mx2_GenArgType::t_mx2_GenArgType(bbInt l_index,bbString l_ident,bbArray<bbGCVar<t_mx2_Type>>* l_types,t_mx2_GenArgType* l_instanceOf){
  this->m_index=l_index;
  this->m_ident=l_ident;
  this->m_types=l_types;
  this->m_instanceOf=l_instanceOf;
  this->m_flags|=g_mx2_Type_TYPE_0GENERIC;
}

bbString t_mx2_GenArgType::m_TypeId(){
  g_mx2_SemantError(BB_T("GenArgType.TypeId()"));
  return bbString{};
}

bbString t_mx2_GenArgType::m_ToString(){
  bbString l_str=(this->m_ident+BB_T("?"));
  if(bbBool(this->m_types)){
    l_str+=((BB_T("<")+g_mx2_Join_1Tt_mx2_Type_2(this->m_types,BB_T(",")))+BB_T(">"));
  }
  return l_str;
}

bbString t_mx2_GenArgType::m_Name(){
  bbString l_args=bbString{};
  {
    bbInt l_0=bbInt(0);
    bbInt l_1=this->m_types->length();
    for(;(l_0<l_1);l_0+=1){
      struct f2_t : public bbGCFrame{
        t_mx2_Type* l_arg{};
        void gcMark(){
          bbGCMarkPtr(l_arg);
        }
      }f2{};
      f2.l_arg=this->m_types->at(l_0);
      l_args+=(BB_T(",")+f2.l_arg->m_Name());
    }
  }
  if(bbBool(l_args)){
    l_args=((BB_T("<")+l_args.slice(1))+BB_T(">"));
  }
  return ((this->m_ident+BB_T("?"))+l_args);
}

t_mx2_Type* t_mx2_GenArgType::m_InferType(t_mx2_Type* l_type,bbArray<bbGCVar<t_mx2_Type>>* l_infered){
  struct f0_t : public bbGCFrame{
    t_mx2_Type* l_type{};
    f0_t(t_mx2_Type* l_type):l_type(l_type){
    }
    void gcMark(){
      bbGCMarkPtr(l_type);
    }
  }f0{l_type};
  if(bbBool(this->m_types)){
    struct f1_t : public bbGCFrame{
      t_mx2_ClassType* l_ctype{};
      t_mx2_GenArgType* l_gtype{};
      bbArray<bbGCVar<t_mx2_Type>>* l_gtypes{};
      void gcMark(){
        bbGCMarkPtr(l_ctype);
        bbGCMarkPtr(l_gtype);
        bbGCMarkPtr(l_gtypes);
      }
    }f1{};
    f1.l_ctype=g_mx2_TCast_1Tt_mx2_ClassType_2(f0.l_type);
    f1.l_gtype=g_mx2_TCast_1Tt_mx2_GenArgType_2(f0.l_type);
    if(bbBool(f1.l_ctype)){
      f1.l_gtypes=f1.l_ctype->m_types;
      f0.l_type=((t_mx2_Type*)(f1.l_ctype->m_instanceOf));
    }else if(bbBool(f1.l_gtype)){
      f1.l_gtypes=f1.l_gtype->m_types;
      f0.l_type=((t_mx2_Type*)(f1.l_gtype->m_instanceOf));
    }else{
      return ((t_mx2_Type*)0);
    }
    if((this->m_types->length()!=f1.l_gtypes->length())){
      return ((t_mx2_Type*)0);
    }
    {
      bbInt l_i=bbInt(0);
      for(;(l_i<this->m_types->length());l_i+=1){
        if(!bbBool(this->m_types->at(l_i)->m_InferType(f1.l_gtypes->at(l_i),l_infered))){
          return ((t_mx2_Type*)0);
        }
      }
    }
  }
  if(!bbBool(l_infered->at(this->m_index))){
    l_infered->at(this->m_index)=f0.l_type;
    return f0.l_type;
  }
  if(l_infered->at(this->m_index)->m_Equals(f0.l_type)){
    return f0.l_type;
  }
  l_infered->at(this->m_index)=((t_mx2_Type*)(g_mx2_Type_BadType));
  return ((t_mx2_Type*)0);
}

t_mx2_Type* t_mx2_GenArgType::m_GenInstance(bbArray<bbGCVar<t_mx2_Type>>* l_types){
  if(bbBool(this->m_types)){
    g_mx2_SemantError(BB_T("GenArgType.GenInstance()"));
  }
  return ((t_mx2_Type*)(bbGCNew<t_mx2_GenArgType>(this->m_index,this->m_ident,l_types,this)));
}

bbBool t_mx2_GenArgType::m_Equals(t_mx2_Type* l_type){
  struct f0_t : public bbGCFrame{
    t_mx2_GenArgType* l_gtype{};
    void gcMark(){
      bbGCMarkPtr(l_gtype);
    }
  }f0{};
  if(l_type->m__eq(((t_mx2_Type*)(this)))){
    return true;
  }
  f0.l_gtype=g_mx2_TCast_1Tt_mx2_GenArgType_2(l_type);
  if((!bbBool(f0.l_gtype)||(this->m_ident!=f0.l_gtype->m_ident))){
    return false;
  }
  if((this->m_types->length()!=f0.l_gtype->m_types->length())){
    return false;
  }
  if(((bbBool(this->m_instanceOf)&&bbBool(f0.l_gtype->m_instanceOf))&&!this->m_instanceOf->m_Equals(((t_mx2_Type*)(f0.l_gtype->m_instanceOf))))){
    return false;
  }
  if((bbBool(this->m_instanceOf)||bbBool(f0.l_gtype->m_instanceOf))){
    return false;
  }
  return g_mx2_TypesEqual(this->m_types,f0.l_gtype->m_types);
}

bbString t_mx2_VoidType::m_TypeId(){
  return BB_T("v");
}

bbString t_mx2_VoidType::m_ToString(){
  return BB_T("Void");
}

bbString t_mx2_VoidType::m_Name(){
  return BB_T("Void");
}

bbString t_mx2_BadType::m_TypeId(){
  g_mx2_SemantError(BB_T("BadType.TypeId()"));
  return bbString{};
}

bbString t_mx2_BadType::m_ToString(){
  return BB_T("<BadType>");
}

bbString t_mx2_BadType::m_Name(){
  return BB_T("{BadType}");
}

bbBool t_mx2_BadType::m_Equals(t_mx2_Type* l_type){
  return false;
}

bbString t_mx2_NullType::m_TypeId(){
  g_mx2_SemantError(BB_T("NullType.TypeId()"));
  return bbString{};
}

bbString t_mx2_NullType::m_ToString(){
  return BB_T("<NullType>");
}

bbString t_mx2_NullType::m_Name(){
  return BB_T("{NullType}");
}

bbBool t_mx2_NullType::m_Equals(t_mx2_Type* l_type){
  return false;
}

bbInt t_mx2_NullType::m_DistanceToType(t_mx2_Type* l_type){
  return g_mx2_Type_MAX_0DISTANCE;
}

void mx2_mx2cc_type_init(){
  static bool done;
  if(done) return;
  done=true;
  g_mx2_Type_BadType=bbGCNew<t_mx2_BadType>();
  g_mx2_Type_MAX_0DISTANCE=10000;
  g_mx2_Type_NullType=bbGCNew<t_mx2_NullType>();
  g_mx2_Type_TYPE_0GENERIC=1;
  g_mx2_Type_VoidType=bbGCNew<t_mx2_VoidType>();
}

bbInit mx2_mx2cc_type_init_v("mx2cc_type",&mx2_mx2cc_type_init);
