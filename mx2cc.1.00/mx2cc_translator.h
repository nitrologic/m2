
#ifndef MX2_MX2CC_TRANSLATOR_H
#define MX2_MX2CC_TRANSLATOR_H

#include <bbmonkey.h>

// ***** External *****

#include "../../../../../modules/monkey/monkey.buildv1.0.0/desktop_release_linux/monkey_types.h"
#include "mx2cc_stmt.h"

struct t_mx2_Type;
struct t_std_collections_Stack_1s;
struct t_std_collections_Stack_1Tt_std_collections_Stack_1s_2;
struct t_std_collections_Map_1sTt_mx2_FileDecl_2;
struct t_std_collections_Map_1sTt_mx2_ClassType_2;
struct t_std_collections_Map_1Tt_mx2_SNode_2z;
struct t_std_collections_Stack_1Tt_mx2_VarValue_2;
struct t_std_collections_Stack_1Tt_mx2_FuncValue_2;
struct t_std_collections_Stack_1Tt_mx2_ClassType_2;
struct t_mx2_VarValue;
struct t_mx2_FileDecl;
struct t_mx2_ClassType;
struct t_mx2_Value;
struct t_mx2_FuncValue;
struct t_mx2_FuncType;
struct t_mx2_SNode;
struct t_std_collections_Map_1sTt_mx2_VarValue_2;
struct t_std_collections_Stack_1Tt_mx2_Translator_GCTmp_2;

// ***** Internal *****

struct t_mx2_Translator;
struct t_mx2_AssignedGCParamsVisitor;
struct t_mx2_Translator_GCFrame;
struct t_mx2_Translator_GCTmp;

extern bbBool g_mx2_IsGCPtrType(t_mx2_Type* l_type);
extern bbBool g_mx2_IsGCType(t_mx2_Type* l_type);

struct t_mx2_Translator : public bbObject{

  const char *typeName()const{return "t_mx2_Translator";}

  bbBool m_debug{};
  bbGCVar<t_std_collections_Stack_1s> m__0buf{};
  bbString m__0indent{};
  bbGCVar<t_std_collections_Stack_1Tt_std_collections_Stack_1s_2> m__0insertStack{};
  bbGCVar<t_mx2_Translator_GCFrame> m__0gcframe{};
  bbGCVar<t_std_collections_Map_1sTt_mx2_FileDecl_2> m__0usesFiles{};
  bbGCVar<t_std_collections_Map_1sTt_mx2_ClassType_2> m__0usesTypes{};
  bbGCVar<t_std_collections_Map_1Tt_mx2_SNode_2z> m__0refs{};
  bbGCVar<t_std_collections_Stack_1Tt_mx2_VarValue_2> m__0refsVars{};
  bbGCVar<t_std_collections_Stack_1Tt_mx2_FuncValue_2> m__0refsFuncs{};
  bbGCVar<t_std_collections_Stack_1Tt_mx2_ClassType_2> m__0refsTypes{};
  bbGCVar<t_std_collections_Map_1sTt_mx2_FileDecl_2> m__0incs{};
  bbInt m__0depsPos{};

  void init();

  void gcMark();

  t_mx2_Translator();

  virtual bbString m_VarProto(t_mx2_VarValue* l_vvar)=0;
  void m_Uses(t_mx2_FileDecl* l_fdecl);
  void m_Uses(t_mx2_ClassType* l_ctype);
  void m_Uses(t_mx2_Type* l_type);
  virtual bbString m_TransType(t_mx2_Type* l_type)=0;
  virtual bbString m_Trans(t_mx2_Value* l_value)=0;
  t_std_collections_Stack_1s* m_Slice(bbInt l_pos);
  void m_Refs(t_mx2_Type* l_type);
  void m_Refs(t_mx2_FuncValue* l_func);
  void m_Refs(t_mx2_VarValue* l_vvar);
  bbBool m_IsValue(t_mx2_Type* l_type);
  bbBool m_IsStruct(t_mx2_Type* l_type);
  bbInt m_InsertPos();
  bbString m_InsertGCTmp(t_mx2_VarValue* l_vvar);
  bbBool m_Included(t_mx2_FileDecl* l_fdecl);
  virtual bbString m_FuncProto(t_mx2_FuncValue* l_func)=0;
  void m_FreeGCTmps();
  bbString m_FindGCTmp(t_mx2_VarValue* l_vvar);
  void m_EndInsert();
  void m_EndGCFrame();
  void m_EndDeps(bbString l_baseDir);
  void m_EmitInclude(t_mx2_FileDecl* l_fdecl,bbString l_baseDir);
  void m_EmitBr();
  void m_Emit(bbString l_str);
  bbString m_CFuncType(t_mx2_FuncType* l_type);
  void m_BeginInsert(bbInt l_pos);
  void m_BeginGCFrame(t_mx2_FuncValue* l_func);
  void m_BeginGCFrame();
  void m_BeginDeps();
  bbString m_AllocGCTmp(t_mx2_Type* l_type);
  bbBool m_AddRef(t_mx2_SNode* l_node);
};

struct t_mx2_AssignedGCParamsVisitor : public t_mx2_StmtVisitor{

  using t_mx2_StmtVisitor::m_Visit;
  const char *typeName()const{return "t_mx2_AssignedGCParamsVisitor";}

  bbGCVar<t_std_collections_Map_1sTt_mx2_VarValue_2> m_gcparams{};

  void init();

  void gcMark();

  void m_Visit(t_mx2_AssignStmt* l_stmt);

  t_mx2_AssignedGCParamsVisitor(){
    init();
  }
};

struct t_mx2_Translator_GCFrame : public bbObject{

  const char *typeName()const{return "t_mx2_Translator_GCFrame";}

  bbGCVar<t_mx2_Translator_GCFrame> m_outer{};
  bbInt m_inspos{};
  bbInt m_depth{};
  bbString m_ident{};
  bbGCVar<t_std_collections_Map_1sTt_mx2_VarValue_2> m_vars{};
  bbGCVar<t_std_collections_Stack_1Tt_mx2_Translator_GCTmp_2> m_tmps{};

  void init();

  void gcMark();

  t_mx2_Translator_GCFrame(t_mx2_Translator_GCFrame* l_outer,bbInt l_inspos);

  t_mx2_Translator_GCFrame(){
    init();
  }
};

struct t_mx2_Translator_GCTmp : public bbObject{

  const char *typeName()const{return "t_mx2_Translator_GCTmp";}

  bbBool m_used{};
  bbGCVar<t_mx2_Type> m_type{};
  bbString m_ident{};

  void gcMark();

  t_mx2_Translator_GCTmp(){
  }
};

#endif
