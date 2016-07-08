
#ifndef MX2_MX2CC_DECL_H
#define MX2_MX2CC_DECL_H

#include <bbmonkey.h>

// ***** External *****

#include "mx2cc_node.h"

struct t_mx2_Scope;
struct t_std_collections_Stack_1s;
struct t_mx2_ParseEx;
struct t_mx2_Module;
struct t_std_collections_Stack_1Tt_mx2_FuncValue_2;
struct t_std_collections_Stack_1Tt_mx2_ClassType_2;
struct t_std_collections_Stack_1Tt_mx2_VarValue_2;

// ***** Internal *****

struct t_mx2_Decl;
struct t_mx2_FileDecl;

extern bbInt g_mx2_DECL_0PUBLIC;
extern bbInt g_mx2_DECL_0PRIVATE;
extern bbInt g_mx2_DECL_0PROTECTED;
extern bbInt g_mx2_DECL_0INTERNAL;
extern bbInt g_mx2_DECL_0VIRTUAL;
extern bbInt g_mx2_DECL_0OVERRIDE;
extern bbInt g_mx2_DECL_0ABSTRACT;
extern bbInt g_mx2_DECL_0FINAL;
extern bbInt g_mx2_DECL_0EXTERN;
extern bbInt g_mx2_DECL_0EXTENSION;
extern bbInt g_mx2_DECL_0DEFAULT;
extern bbInt g_mx2_DECL_0GETTER;
extern bbInt g_mx2_DECL_0SETTER;
extern bbInt g_mx2_DECL_0OPERATOR;
extern bbInt g_mx2_DECL_0IFACEMEMBER;
extern bbInt g_mx2_DECL_0ACCESSMASK;

struct t_mx2_Decl : public t_mx2_PNode{

  const char *typeName()const{return "t_mx2_Decl";}

  bbString m_kind{};
  bbString m_ident{};
  bbInt m_flags{};
  bbString m_symbol{};
  bbString m_docs{};
  bbGCVar<bbArray<bbGCVar<t_mx2_Decl>>> m_members{};

  void gcMark();

  bbString m_ToString();
  virtual t_mx2_SNode* m_ToNode(t_mx2_Scope* l_scope);
  bbBool m_IsVirtual();
  bbBool m_IsSetter();
  bbBool m_IsPublic();
  bbBool m_IsProtected();
  bbBool m_IsPrivate();
  bbBool m_IsOverride();
  bbBool m_IsOperator();
  bbBool m_IsInternal();
  bbBool m_IsIfaceMember();
  bbBool m_IsGetter();
  bbBool m_IsFinal();
  bbBool m_IsExtern();
  bbBool m_IsExtension();
  bbBool m_IsDefault();
  bbBool m_IsAbstract();
  virtual void m_Emit(t_std_collections_Stack_1s* l_buf,bbString l_spc);

  t_mx2_Decl(){
  }
};

struct t_mx2_FileDecl : public t_mx2_Decl{

  const char *typeName()const{return "t_mx2_FileDecl";}

  bbString m_path{};
  bbString m_nmspace{};
  bbGCVar<bbArray<bbString>> m_usings{};
  bbGCVar<bbArray<bbString>> m_imports{};
  bbGCVar<bbArray<bbGCVar<t_mx2_ParseEx>>> m_errors{};
  bbGCVar<t_mx2_Module> m_module{};
  bbString m_exhfile{};
  bbString m_hfile{};
  bbString m_cfile{};
  bbGCVar<t_std_collections_Stack_1Tt_mx2_FuncValue_2> m_functions{};
  bbGCVar<t_std_collections_Stack_1Tt_mx2_ClassType_2> m_classes{};
  bbGCVar<t_std_collections_Stack_1Tt_mx2_VarValue_2> m_globals{};

  void init();

  void gcMark();

  t_mx2_FileDecl(){
    init();
  }
};

#endif
