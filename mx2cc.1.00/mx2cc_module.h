
#ifndef MX2_MX2CC_MODULE_H
#define MX2_MX2CC_MODULE_H

#include <bbmonkey.h>

// ***** External *****

#include "../../../../../modules/monkey/monkey.buildv1.0.0/desktop_release_linux/monkey_types.h"

struct t_std_collections_Stack_1Tt_mx2_FileDecl_2;
struct t_std_collections_Stack_1Tt_mx2_FileScope_2;
struct t_std_collections_Stack_1Tt_mx2_SNode_2;
struct t_std_collections_Stack_1Tt_mx2_NamespaceScope_2;
struct t_mx2_FuncValue;
struct t_std_collections_Map_1sz;

// ***** Internal *****

struct t_mx2_Module;

struct t_mx2_Module : public bbObject{

  const char *typeName()const{return "t_mx2_Module";}

  bbString m_name{};
  bbString m_srcPath{};
  bbString m_productType{};
  bbString m_ident{};
  bbString m_baseDir{};
  bbString m_buildDir{};
  bbString m_cacheDir{};
  bbString m_outputDir{};
  bbString m_hfileDir{};
  bbString m_cfileDir{};
  bbGCVar<t_std_collections_Stack_1Tt_mx2_FileDecl_2> m_fileDecls{};
  bbGCVar<t_std_collections_Stack_1Tt_mx2_FileScope_2> m_fileScopes{};
  bbGCVar<t_std_collections_Stack_1Tt_mx2_SNode_2> m_genInstances{};
  bbGCVar<t_std_collections_Stack_1Tt_mx2_NamespaceScope_2> m_usings{};
  bbGCVar<t_mx2_FuncValue> m_main{};
  bbGCVar<t_std_collections_Map_1sz> m_moduleDeps{};

  void init();

  void gcMark();

  t_mx2_Module(bbString l_name,bbString l_srcPath,bbString l_productType,bbString l_version);

  t_mx2_Module(){
    init();
  }
};

#endif
