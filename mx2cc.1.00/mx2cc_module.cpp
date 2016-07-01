
#include "mx2cc_module.h"

// ***** External *****

#include "mx2cc_builder.h"
#include "mx2cc_func.h"
#include "mx2cc_std_collections_2map.h"
#include "mx2cc_std_collections_2stack.h"

extern bbString g_mx2_MungPath(bbString l_path);
extern bbString g_std_filesystem_ExtractDir(bbString l_path);

// ***** Internal *****

void t_mx2_Module::init(){
  m_fileDecls=bbGCNew<t_std_collections_Stack_1Tt_mx2_FileDecl_2>();
  m_fileScopes=bbGCNew<t_std_collections_Stack_1Tt_mx2_FileScope_2>();
  m_genInstances=bbGCNew<t_std_collections_Stack_1Tt_mx2_SNode_2>();
  m_usings=bbGCNew<t_std_collections_Stack_1Tt_mx2_NamespaceScope_2>();
  m_moduleDeps=bbGCNew<t_std_collections_Map_1sz>();
}

void t_mx2_Module::gcMark(){
  bbGCMark(m_fileDecls);
  bbGCMark(m_fileScopes);
  bbGCMark(m_genInstances);
  bbGCMark(m_usings);
  bbGCMark(m_main);
  bbGCMark(m_moduleDeps);
}

t_mx2_Module::t_mx2_Module(bbString l_name,bbString l_srcPath,bbString l_productType,bbString l_version){
  init();
  struct f0_t : public bbGCFrame{
    t_mx2_Builder* l_builder{};
    void gcMark(){
      bbGCMarkPtr(l_builder);
    }
  }f0{};
  this->m_name=l_name;
  this->m_srcPath=l_srcPath;
  this->m_productType=l_productType;
  f0.l_builder=g_mx2_Builder_instance;
  this->m_ident=g_mx2_MungPath(l_name);
  this->m_baseDir=g_std_filesystem_ExtractDir(l_srcPath);
  this->m_buildDir=((((this->m_baseDir+l_name)+BB_T(".buildv"))+l_version)+BB_T("/"));
  this->m_outputDir=((this->m_buildDir+f0.l_builder->m_profileName)+BB_T("/"));
  this->m_cacheDir=(((this->m_buildDir+BB_T("build_cache/"))+f0.l_builder->m_profileName)+BB_T("/"));
  this->m_cfileDir=this->m_cacheDir;
  if((l_productType==BB_T("module"))){
    this->m_hfileDir=this->m_outputDir;
  }else{
    this->m_hfileDir=this->m_cacheDir;
  }
}

void mx2_mx2cc_module_init(){
  static bool done;
  if(done) return;
  done=true;
}

bbInit mx2_mx2cc_module_init_v("mx2cc_module",&mx2_mx2cc_module_init);
