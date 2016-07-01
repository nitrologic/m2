
#ifndef MX2_MX2CC_BUILDER_H
#define MX2_MX2CC_BUILDER_H

#include <bbmonkey.h>

// ***** External *****

#include "../../../../../modules/monkey/monkey.buildv1.0.0/desktop_release_linux/monkey_types.h"

struct t_std_collections_Stack_1Tt_mx2_ErrorEx_2;
struct t_std_collections_Map_1ss;
struct t_mx2_Module;
struct t_std_collections_Stack_1Tt_mx2_Module_2;
struct t_std_collections_Map_1sTt_mx2_Module_2;
struct t_mx2_NamespaceScope;
struct t_std_collections_Stack_1Tt_mx2_FuncValue_2;
struct t_std_collections_List_1Tt_mx2_ClassType_2;
struct t_std_collections_Map_1sz;
struct t_std_collections_Stack_1s;

// ***** Internal *****

struct t_mx2_BuildOpts;
struct t_mx2_Builder;

extern bbGCRootVar<t_mx2_Builder> g_mx2_Builder_instance;

struct t_mx2_BuildOpts : public bbObject{

  const char *typeName()const{return "t_mx2_BuildOpts";}

  bbString m_mainSource{};
  bbString m_productType{};
  bbString m_appType{};
  bbString m_target{};
  bbString m_config{};
  bbBool m_clean{};
  bbInt m_verbose{};
  bbBool m_fast{};
  bbBool m_run{};

  t_mx2_BuildOpts(){
  }
};

struct t_mx2_Builder : public bbObject{

  const char *typeName()const{return "t_mx2_Builder";}

  bbGCVar<t_std_collections_Stack_1Tt_mx2_ErrorEx_2> m_errors{};
  bbGCVar<t_mx2_BuildOpts> m_opts{};
  bbString m_modulesDir{};
  bbString m_profileName{};
  bbGCVar<t_std_collections_Map_1ss> m_ppsyms{};
  bbGCVar<t_mx2_Module> m_mainModule{};
  bbGCVar<t_mx2_Module> m_parsingModule{};
  bbGCVar<t_std_collections_Stack_1Tt_mx2_Module_2> m_modules{};
  bbGCVar<t_std_collections_Map_1sTt_mx2_Module_2> m_modulesMap{};
  bbGCVar<t_mx2_NamespaceScope> m_rootNamespace{};
  bbGCVar<t_mx2_NamespaceScope> m_monkeyNamespace{};
  bbGCVar<t_mx2_Module> m_semantingModule{};
  bbGCVar<t_std_collections_Stack_1Tt_mx2_FuncValue_2> m_semantStmts{};
  bbGCVar<t_std_collections_List_1Tt_mx2_ClassType_2> m_semantMembers{};
  bbGCVar<t_std_collections_Map_1sz> m_imported{};
  bbString m_currentDir{};
  bbInt m_tmpId{};
  bbLong m_maxObjTime{};
  bbGCVar<t_std_collections_Stack_1s> m_MX2_0SRCS{};
  bbGCVar<t_std_collections_Stack_1s> m_MX2_0LIBS{};
  bbGCVar<t_std_collections_Stack_1s> m_SRC_0FILES{};
  bbGCVar<t_std_collections_Stack_1s> m_OBJ_0FILES{};
  bbGCVar<t_std_collections_Stack_1s> m_LD_0OPTS{};
  bbGCVar<t_std_collections_Stack_1s> m_CC_0OPTS{};
  bbGCVar<t_std_collections_Stack_1s> m_CPP_0OPTS{};
  bbGCVar<t_std_collections_Stack_1s> m_LD_0LIBS{};
  bbGCVar<t_std_collections_Stack_1s> m_LD_0SYSLIBS{};
  bbGCVar<t_std_collections_Stack_1s> m_DLL_0FILES{};
  bbGCVar<t_std_collections_Stack_1s> m_ASSET_0FILES{};
  bbString m_AR_0CMD{};
  bbString m_CC_0CMD{};
  bbString m_CXX_0CMD{};
  bbString m_LD_0CMD{};

  void init();

  void gcMark();

  t_mx2_Builder(t_mx2_BuildOpts* l_opts);

  void m_Translate();
  void m_SortModules();
  void m_SortModules(t_mx2_Module* l_module,t_std_collections_Map_1sz* l_done,t_std_collections_Stack_1Tt_mx2_Module_2* l_deps);
  void m_Semant();
  void m_Parse();
  bbString m_Link();
  void m_ImportSystemFile(bbString l_path);
  void m_ImportLocalFile(bbString l_path);
  void m_ImportFile(bbString l_path);
  t_mx2_NamespaceScope* m_GetNamespace(bbString l_path);
  bbBool m_Exec(bbString l_cmd);
  void m_CreatePrimTypes();
  bbString m_CreateArchive();
  bbString m_CreateApp();
  bbBool m_CopyAll(bbString l_src,bbString l_dst);
  void m_Compile();
  void m_ClearPrimTypes();

  t_mx2_Builder(){
    init();
  }
};

#endif
