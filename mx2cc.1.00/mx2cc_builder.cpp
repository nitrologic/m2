
#include "mx2cc_builder.h"

// ***** External *****

#include "../../../../../modules/libc/libc.buildv1.0.0/desktop_release_linux/libc_libc.h"
#include "mx2cc_class.h"
#include "mx2cc_decl.h"
#include "mx2cc_errors.h"
#include "mx2cc_func.h"
#include "mx2cc_module.h"
#include "mx2cc_namespace.h"
#include "mx2cc_node.h"
#include "mx2cc_parser.h"
#include "mx2cc_scope.h"
#include "mx2cc_std_collections_2list.h"
#include "mx2cc_std_collections_2map.h"
#include "mx2cc_std_collections_2stack.h"
#include "mx2cc_translator_0cpp.h"
#include "mx2cc_type.h"
#include "mx2cc_var.h"
#include "../../../../../modules/std/std.buildv1.0.0/desktop_release_linux/std_collections_2stack.h"
#include "../../../../../modules/std/std.buildv1.0.0/desktop_release_linux/std_misc_2filesystem.h"

extern bbString g_mx2_HostOS;
extern bbString g_mx2_MX2CC_0VERSION;

extern bbString g_mx2_GetEnv(bbString l_name);
extern bbString g_mx2_MakeRelativePath(bbString l_path,bbString l_baseDir);
extern bbString g_mx2_MungPath(bbString l_path);
extern bbString g_std_stringio_LoadString(bbString l_path);
extern bbBool g_std_stringio_SaveString(bbString l_str,bbString l_path);
extern bbLong g_monkey_math_Max_1l(bbLong l_x,bbLong l_y);

// ***** Internal *****

bbGCRootVar<t_mx2_Builder> g_mx2_Builder_instance;

void t_mx2_Builder::init(){
  m_errors=bbGCNew<t_std_collections_Stack_1Tt_mx2_ErrorEx_2>();
  m_ppsyms=bbGCNew<t_std_collections_Map_1ss>();
  m_modules=bbGCNew<t_std_collections_Stack_1Tt_mx2_Module_2>();
  m_modulesMap=bbGCNew<t_std_collections_Map_1sTt_mx2_Module_2>();
  m_semantStmts=bbGCNew<t_std_collections_Stack_1Tt_mx2_FuncValue_2>();
  m_semantMembers=bbGCNew<t_std_collections_List_1Tt_mx2_ClassType_2>();
  m_imported=bbGCNew<t_std_collections_Map_1sz>();
  m_MX2_0SRCS=bbGCNew<t_std_collections_Stack_1s>();
  m_MX2_0LIBS=bbGCNew<t_std_collections_Stack_1s>();
  m_SRC_0FILES=bbGCNew<t_std_collections_Stack_1s>();
  m_OBJ_0FILES=bbGCNew<t_std_collections_Stack_1s>();
  m_LD_0OPTS=bbGCNew<t_std_collections_Stack_1s>();
  m_CC_0OPTS=bbGCNew<t_std_collections_Stack_1s>();
  m_CPP_0OPTS=bbGCNew<t_std_collections_Stack_1s>();
  m_LD_0LIBS=bbGCNew<t_std_collections_Stack_1s>();
  m_LD_0SYSLIBS=bbGCNew<t_std_collections_Stack_1s>();
  m_DLL_0FILES=bbGCNew<t_std_collections_Stack_1s>();
  m_ASSET_0FILES=bbGCNew<t_std_collections_Stack_1s>();
  m_AR_0CMD=BB_T("ar");
  m_CC_0CMD=BB_T("gcc");
  m_CXX_0CMD=BB_T("g++");
  m_LD_0CMD=BB_T("g++");
}

void t_mx2_Builder::gcMark(){
  bbGCMark(m_errors);
  bbGCMark(m_opts);
  bbGCMark(m_ppsyms);
  bbGCMark(m_mainModule);
  bbGCMark(m_parsingModule);
  bbGCMark(m_modules);
  bbGCMark(m_modulesMap);
  bbGCMark(m_rootNamespace);
  bbGCMark(m_monkeyNamespace);
  bbGCMark(m_semantingModule);
  bbGCMark(m_semantStmts);
  bbGCMark(m_semantMembers);
  bbGCMark(m_imported);
  bbGCMark(m_MX2_0SRCS);
  bbGCMark(m_MX2_0LIBS);
  bbGCMark(m_SRC_0FILES);
  bbGCMark(m_OBJ_0FILES);
  bbGCMark(m_LD_0OPTS);
  bbGCMark(m_CC_0OPTS);
  bbGCMark(m_CPP_0OPTS);
  bbGCMark(m_LD_0LIBS);
  bbGCMark(m_LD_0SYSLIBS);
  bbGCMark(m_DLL_0FILES);
  bbGCMark(m_ASSET_0FILES);
}

t_mx2_Builder::t_mx2_Builder(t_mx2_BuildOpts* l_opts){
  init();
  this->m_opts=l_opts;
  g_mx2_Builder_instance=this;
  bbString l_copts=bbString{};
  l_copts=g_mx2_GetEnv((BB_T("MX2_LD_OPTS_")+l_opts->m_target.toUpper()));
  if(bbBool(l_copts)){
    this->m_LD_0OPTS->m_Push(l_copts);
  }
  l_copts=g_mx2_GetEnv((((BB_T("MX2_LD_OPTS_")+l_opts->m_target.toUpper())+BB_T("_"))+l_opts->m_config.toUpper()));
  if(bbBool(l_copts)){
    this->m_LD_0OPTS->m_Push(l_copts);
  }
  l_copts=g_mx2_GetEnv((BB_T("MX2_CC_OPTS_")+l_opts->m_target.toUpper()));
  if(bbBool(l_copts)){
    this->m_CC_0OPTS->m_Push(l_copts);
  }
  l_copts=g_mx2_GetEnv((((BB_T("MX2_CC_OPTS_")+l_opts->m_target.toUpper())+BB_T("_"))+l_opts->m_config.toUpper()));
  if(bbBool(l_copts)){
    this->m_CC_0OPTS->m_Push(l_copts);
  }
  l_copts=g_mx2_GetEnv((BB_T("MX2_CPP_OPTS_")+l_opts->m_target.toUpper()));
  if(bbBool(l_opts)){
    this->m_CPP_0OPTS->m_Push(l_copts);
  }
  l_copts=g_mx2_GetEnv((((BB_T("MX2_CPP_OPTS_")+l_opts->m_target.toUpper())+BB_T("_"))+l_opts->m_config.toUpper()));
  if(bbBool(l_copts)){
    this->m_CPP_0OPTS->m_Push(l_copts);
  }
  if(l_opts->m_target==BB_T("desktop")){
    this->m_AR_0CMD=BB_T("ar");
    this->m_CC_0CMD=BB_T("gcc");
    this->m_CXX_0CMD=BB_T("g++");
    this->m_LD_0CMD=BB_T("g++");
  }else if(l_opts->m_target==BB_T("emscripten")){
    this->m_AR_0CMD=BB_T("emar");
    this->m_CC_0CMD=BB_T("emcc");
    this->m_CXX_0CMD=BB_T("em++");
    this->m_LD_0CMD=BB_T("em++");
  }
  this->m_ppsyms->m__idxeq(BB_T("__HOSTOS__"),((BB_T("\"")+g_mx2_HostOS)+BB_T("\"")));
  this->m_ppsyms->m__idxeq(BB_T("__TARGET__"),((BB_T("\"")+l_opts->m_target)+BB_T("\"")));
  this->m_ppsyms->m__idxeq(BB_T("__CONFIG__"),((BB_T("\"")+l_opts->m_config)+BB_T("\"")));
  this->m_profileName=((((l_opts->m_target+BB_T("_"))+l_opts->m_config)+BB_T("_"))+g_mx2_HostOS);
  this->m_modulesDir=(g_std_filesystem_RealPath(BB_T("modules"))+BB_T("/"));
  this->m_ClearPrimTypes();
  this->m_rootNamespace=bbGCNew<t_mx2_NamespaceScope>(((t_mx2_NamespaceType*)0),((t_mx2_NamespaceScope*)0));
  this->m_monkeyNamespace=this->m_GetNamespace(BB_T("monkey"));
}

void t_mx2_Builder::m_Translate(){
  struct f0_t : public bbGCFrame{
    t_mx2_Module* l_module{};
    void gcMark(){
      bbGCMarkPtr(l_module);
    }
  }f0{};
  if((this->m_opts->m_verbose==bbInt(0))){
    puts(BB_T("Translating...").c_str());fflush( stdout );
  }
  f0.l_module=this->m_mainModule;
  g_std_filesystem_CreateDir(f0.l_module->m_buildDir,true);
  g_std_filesystem_CreateDir((f0.l_module->m_buildDir+BB_T("build_cache")),true);
  if(!g_std_filesystem_CreateDir(f0.l_module->m_cacheDir,true)){
    puts((BB_T("Failed to create dir:")+f0.l_module->m_cacheDir).c_str());fflush( stdout );
  }
  if(!g_std_filesystem_CreateDir(f0.l_module->m_outputDir,true)){
    puts((BB_T("Failed to create dir:")+f0.l_module->m_outputDir).c_str());fflush( stdout );
  }
  {
    struct f1_t : public bbGCFrame{
      t_std_collections_Stack_1Tt_mx2_FileDecl_2_Iterator l_0{};
      void gcMark(){
        bbGCMark(l_0);
      }
    }f1{};
    f1.l_0=f0.l_module->m_fileDecls->m_All();
    for(;!f1.l_0.m_AtEnd();f1.l_0.m_Bump()){
      struct f2_t : public bbGCFrame{
        t_mx2_FileDecl* l_fdecl{};
        t_mx2_Translator_0CPP* l_translator{};
        void gcMark(){
          bbGCMarkPtr(l_fdecl);
          bbGCMarkPtr(l_translator);
        }
      }f2{};
      f2.l_fdecl=f1.l_0.m_Current();
      if((this->m_opts->m_verbose>bbInt(0))){
        puts((BB_T("Translating ")+f2.l_fdecl->m_path).c_str());fflush( stdout );
      }
      f2.l_translator=bbGCNew<t_mx2_Translator_0CPP>();
      try{
        f2.l_translator->m_Translate(f2.l_fdecl);
      }catch(t_mx2_TransEx* ex){
        struct f3_t : public bbGCFrame{
          t_mx2_TransEx* l_ex{};
          void gcMark(){
            bbGCMarkPtr(l_ex);
          }
        }f3{};
        f3.l_ex=ex;
      }
      this->m_SRC_0FILES->m_Push(f2.l_fdecl->m_cfile);
    }
  }
}

void t_mx2_Builder::m_SortModules(){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1sz* l_done{};
    t_std_collections_Stack_1Tt_mx2_Module_2* l_sorted{};
    t_mx2_Module* t0{};
    void gcMark(){
      bbGCMarkPtr(l_done);
      bbGCMarkPtr(l_sorted);
      bbGCMarkPtr(t0);
    }
  }f0{};
  f0.l_sorted=bbGCNew<t_std_collections_Stack_1Tt_mx2_Module_2>();
  f0.l_done=bbGCNew<t_std_collections_Map_1sz>();
  f0.l_sorted->m_Push(f0.t0=this->m_modulesMap->m__idx(BB_T("monkey")));
  f0.l_done->m__idxeq(BB_T("monkey"),true);
  {
    bbInt l_i=bbInt(0);
    for(;(l_i<this->m_modules->m_Length());l_i+=1){
      struct f2_t : public bbGCFrame{
        t_mx2_Module* t0{};
        void gcMark(){
          bbGCMarkPtr(t0);
        }
      }f2{};
      this->m_SortModules(f2.t0=this->m_modules->m__idx(l_i),f0.l_done,f0.l_sorted);
    }
  }
  this->m_modules=f0.l_sorted;
  {
    bbInt l_i=bbInt(0);
    for(;(l_i<this->m_modules->m_Length());l_i+=1){
      struct f2_t : public bbGCFrame{
        t_mx2_Module* l_module{};
        void gcMark(){
          bbGCMarkPtr(l_module);
        }
      }f2{};
      f2.l_module=this->m_modules->m__idx(((this->m_modules->m_Length()-l_i)-1));
      if((f2.l_module!=this->m_mainModule)){
        this->m_LD_0LIBS->m_Push(((f2.l_module->m_outputDir+f2.l_module->m_name)+BB_T(".a")));
      }
    }
  }
}

void t_mx2_Builder::m_SortModules(t_mx2_Module* l_module,t_std_collections_Map_1sz* l_done,t_std_collections_Stack_1Tt_mx2_Module_2* l_deps){
  if(l_done->m_Contains(l_module->m_name)){
    return;
  }
  {
    struct f1_t : public bbGCFrame{
      t_std_collections_Map_1sz_KeyIterator l_0{};
      void gcMark(){
        bbGCMark(l_0);
      }
    }f1{};
    f1.l_0=l_module->m_moduleDeps->m_Keys().m_All();
    for(;f1.l_0.m_Valid();f1.l_0.m_Bump()){
      struct f2_t : public bbGCFrame{
        t_mx2_Module* l_module2{};
        void gcMark(){
          bbGCMarkPtr(l_module2);
        }
      }f2{};
      bbString l_dep=f1.l_0.m_Current();
      f2.l_module2=this->m_modulesMap->m__idx(l_dep);
      this->m_SortModules(f2.l_module2,l_done,l_deps);
    }
  }
  if(l_done->m_Contains(l_module->m_name)){
    return;
  }
  l_done->m__idxeq(l_module->m_name,true);
  l_deps->m_Push(l_module);
}

void t_mx2_Builder::m_Semant(){
  if((this->m_opts->m_verbose==bbInt(0))){
    puts(BB_T("Semanting...").c_str());fflush( stdout );
  }
  this->m_SortModules();
  {
    bbInt l_i=bbInt(0);
    for(;(l_i<this->m_modules->m_Length());l_i+=1){
      struct f2_t : public bbGCFrame{
        t_mx2_FuncValue* l_main{};
        t_mx2_Module* l_module{};
        t_std_collections_Map_1sTt_mx2_FileDecl_2* l_transFiles{};
        void gcMark(){
          bbGCMarkPtr(l_main);
          bbGCMarkPtr(l_module);
          bbGCMarkPtr(l_transFiles);
        }
      }f2{};
      f2.l_module=this->m_modules->m__idx(l_i);
      {
        struct f3_t : public bbGCFrame{
          t_std_collections_Stack_1Tt_mx2_FileDecl_2_Iterator l_0{};
          void gcMark(){
            bbGCMark(l_0);
          }
        }f3{};
        f3.l_0=f2.l_module->m_fileDecls->m_All();
        for(;!f3.l_0.m_AtEnd();f3.l_0.m_Bump()){
          struct f4_t : public bbGCFrame{
            t_mx2_FileDecl* l_fdecl{};
            t_mx2_FileScope* l_fscope{};
            void gcMark(){
              bbGCMarkPtr(l_fdecl);
              bbGCMarkPtr(l_fscope);
            }
          }f4{};
          f4.l_fdecl=f3.l_0.m_Current();
          f4.l_fscope=bbGCNew<t_mx2_FileScope>(f4.l_fdecl);
          f2.l_module->m_fileScopes->m_Push(f4.l_fscope);
        }
      }
      if((l_i==bbInt(0))){
        this->m_CreatePrimTypes();
      }
      this->m_semantingModule=f2.l_module;
      {
        struct f3_t : public bbGCFrame{
          t_std_collections_Stack_1Tt_mx2_FileScope_2_Iterator l_1{};
          void gcMark(){
            bbGCMark(l_1);
          }
        }f3{};
        f3.l_1=f2.l_module->m_fileScopes->m_All();
        for(;!f3.l_1.m_AtEnd();f3.l_1.m_Bump()){
          struct f4_t : public bbGCFrame{
            t_mx2_FileScope* l_fscope{};
            void gcMark(){
              bbGCMarkPtr(l_fscope);
            }
          }f4{};
          f4.l_fscope=f3.l_1.m_Current();
          if((this->m_opts->m_verbose>bbInt(0))){
            puts((BB_T("Semanting ")+f4.l_fscope->m_fdecl->m_path).c_str());fflush( stdout );
          }
          f4.l_fscope->m_Semant();
        }
      }
      for(;;){
        if(!this->m_semantMembers->m_Empty()){
          struct f4_t : public bbGCFrame{
            t_mx2_ClassType* l_ctype{};
            void gcMark(){
              bbGCMarkPtr(l_ctype);
            }
          }f4{};
          f4.l_ctype=this->m_semantMembers->m_RemoveFirst();
          g_mx2_PNode_semanting->m_Push(((t_mx2_PNode*)(f4.l_ctype->m_cdecl)));
          try{
            f4.l_ctype->m_SemantMembers();
          }catch(t_mx2_SemantEx* ex){
            struct f5_t : public bbGCFrame{
              t_mx2_SemantEx* l_ex{};
              void gcMark(){
                bbGCMarkPtr(l_ex);
              }
            }f5{};
            f5.l_ex=ex;
          }
          g_mx2_PNode_semanting->m_Pop();
        }else if(!this->m_semantStmts->m_Empty()){
          struct f4_t : public bbGCFrame{
            t_mx2_FuncValue* l_func{};
            void gcMark(){
              bbGCMarkPtr(l_func);
            }
          }f4{};
          f4.l_func=this->m_semantStmts->m_Pop();
          g_mx2_PNode_semanting->m_Push(((t_mx2_PNode*)(f4.l_func->m_fdecl)));
          try{
            f4.l_func->m_SemantStmts();
          }catch(t_mx2_SemantEx* ex){
            struct f5_t : public bbGCFrame{
              t_mx2_SemantEx* l_ex{};
              void gcMark(){
                bbGCMarkPtr(l_ex);
              }
            }f5{};
            f5.l_ex=ex;
          }
          g_mx2_PNode_semanting->m_Pop();
        }else{
          break;
        }
      }
      this->m_semantingModule=((t_mx2_Module*)0);
      f2.l_main=f2.l_module->m_main;
      if(((this->m_opts->m_productType==BB_T("app"))&&(f2.l_module==this->m_mainModule))){
        if(bbBool(f2.l_main)){
          f2.l_main->m_fdecl->m_symbol=BB_T("bbMain");
        }else{
          bbGCNew<t_mx2_BuildEx>(BB_T("Can't find Main:Void()"));
        }
      }else if((this->m_opts->m_productType==BB_T("module"))){
        if(bbBool(f2.l_main)){
          f2.l_main->m_fdecl->m_symbol=((BB_T("mx2_")+f2.l_module->m_ident)+BB_T("_main"));
        }
      }
      f2.l_transFiles=bbGCNew<t_std_collections_Map_1sTt_mx2_FileDecl_2>();
      {
        struct f3_t : public bbGCFrame{
          t_std_collections_Stack_1Tt_mx2_SNode_2_Iterator l_2{};
          void gcMark(){
            bbGCMark(l_2);
          }
        }f3{};
        f3.l_2=f2.l_module->m_genInstances->m_All();
        for(;!f3.l_2.m_AtEnd();f3.l_2.m_Bump()){
          struct f4_t : public bbGCFrame{
            t_mx2_ClassType* l_ctype{};
            t_mx2_FuncValue* l_func{};
            t_mx2_SNode* l_inst{};
            t_mx2_FileDecl* l_transFile{};
            t_mx2_FileDecl* l_transFile2{};
            t_mx2_VarValue* l_vvar{};
            void gcMark(){
              bbGCMarkPtr(l_ctype);
              bbGCMarkPtr(l_func);
              bbGCMarkPtr(l_inst);
              bbGCMarkPtr(l_transFile);
              bbGCMarkPtr(l_transFile2);
              bbGCMarkPtr(l_vvar);
            }
          }f4{};
          f4.l_inst=f3.l_2.m_Current();
          f4.l_vvar=bb_object_cast<t_mx2_VarValue*>(f4.l_inst);
          f4.l_func=bb_object_cast<t_mx2_FuncValue*>(f4.l_inst);
          f4.l_ctype=g_mx2_TCast_1Tt_mx2_ClassType_2(f4.l_inst);
          if(bbBool(f4.l_vvar)){
            f4.l_transFile=f4.l_vvar->m_transFile;
          }else if(bbBool(f4.l_func)){
            f4.l_transFile=f4.l_func->m_transFile;
          }else if(bbBool(f4.l_ctype)){
            f4.l_transFile=f4.l_ctype->m_transFile;
          }
          if((!bbBool(f4.l_transFile)||(f4.l_transFile->m_module==f2.l_module))){
            continue;
          }
          f4.l_transFile2=f4.l_transFile;
          f4.l_transFile=f2.l_transFiles->m__idx(f4.l_transFile2->m_ident);
          if(!bbBool(f4.l_transFile)){
            f4.l_transFile=bbGCNew<t_mx2_FileDecl>();
            f4.l_transFile->m_ident=((f2.l_module->m_ident+BB_T("_"))+f4.l_transFile2->m_ident);
            f4.l_transFile->m_path=f4.l_transFile2->m_path;
            f4.l_transFile->m_nmspace=f4.l_transFile2->m_nmspace;
            f4.l_transFile->m_usings=f4.l_transFile2->m_usings;
            f4.l_transFile->m_imports=f4.l_transFile2->m_imports;
            f4.l_transFile->m_module=f2.l_module;
            f4.l_transFile->m_exhfile=f4.l_transFile2->m_hfile;
            f4.l_transFile->m_hfile=((f2.l_module->m_hfileDir+f4.l_transFile->m_ident)+BB_T(".h"));
            f4.l_transFile->m_cfile=((f2.l_module->m_cfileDir+f4.l_transFile->m_ident)+BB_T(".cpp"));
            f2.l_transFiles->m__idxeq(f4.l_transFile2->m_ident,f4.l_transFile);
            f2.l_module->m_fileDecls->m_Push(f4.l_transFile);
          }
          if(bbBool(f4.l_vvar)){
            f4.l_vvar->m_transFile=f4.l_transFile;
            f4.l_transFile->m_globals->m_Push(f4.l_vvar);
          }else if(bbBool(f4.l_func)){
            f4.l_func->m_transFile=f4.l_transFile;
            f4.l_transFile->m_functions->m_Push(f4.l_func);
          }else if(bbBool(f4.l_ctype)){
            f4.l_ctype->m_transFile=f4.l_transFile;
            f4.l_transFile->m_classes->m_Push(f4.l_ctype);
          }
        }
      }
    }
  }
}

void t_mx2_Builder::m_Parse(){
  struct f0_t : public bbGCFrame{
    t_mx2_Module* l_module{};
    void gcMark(){
      bbGCMarkPtr(l_module);
    }
  }f0{};
  if((this->m_opts->m_verbose==bbInt(0))){
    puts(BB_T("Parsing...").c_str());fflush( stdout );
  }
  bbString l_name=g_std_filesystem_StripDir(g_std_filesystem_StripExt(this->m_opts->m_mainSource));
  f0.l_module=bbGCNew<t_mx2_Module>(l_name,this->m_opts->m_mainSource,this->m_opts->m_productType,g_mx2_MX2CC_0VERSION);
  this->m_modulesMap->m__idxeq(l_name,f0.l_module);
  this->m_modules->m_Push(f0.l_module);
  this->m_mainModule=f0.l_module;
  if(((l_name==BB_T("monkey"))&&(f0.l_module->m_productType==BB_T("module")))){
    this->m_modulesMap->m__idxeq(BB_T("monkey"),f0.l_module);
  }
  if(this->m_opts->m_clean){
    g_std_filesystem_DeleteDir(f0.l_module->m_outputDir,true);
    g_std_filesystem_DeleteDir(f0.l_module->m_cacheDir,true);
  }
  this->m_parsingModule=f0.l_module;
  this->m_MX2_0SRCS->m_Push(f0.l_module->m_srcPath);
  for(;;){
    struct f1_t : public bbGCFrame{
      t_mx2_FileDecl* l_fdecl{};
      t_mx2_Parser* l_parser{};
      void gcMark(){
        bbGCMarkPtr(l_fdecl);
        bbGCMarkPtr(l_parser);
      }
    }f1{};
    if(this->m_MX2_0SRCS->m_Empty()){
      this->m_parsingModule=((t_mx2_Module*)0);
      if(this->m_MX2_0LIBS->m_Empty()){
        if(bbBool(this->m_modulesMap->m__idx(BB_T("monkey")))){
          break;
        }
        this->m_MX2_0LIBS->m_Push(BB_T("monkey"));
      }
      bbString l_name=this->m_MX2_0LIBS->m_Pop();
      bbString l_srcPath=((((this->m_modulesDir+l_name)+BB_T("/"))+l_name)+BB_T(".monkey2"));
      f0.l_module=bbGCNew<t_mx2_Module>(l_name,l_srcPath,BB_T("module"),g_mx2_MX2CC_0VERSION);
      this->m_modulesMap->m__idxeq(l_name,f0.l_module);
      this->m_modules->m_Push(f0.l_module);
      this->m_parsingModule=f0.l_module;
      this->m_MX2_0SRCS->m_Push(f0.l_module->m_srcPath);
    }
    bbString l_path=this->m_MX2_0SRCS->m_Pop();
    if((this->m_opts->m_verbose>bbInt(0))){
      puts((BB_T("Parsing ")+l_path).c_str());fflush( stdout );
    }
    bbString l_ident=((f0.l_module->m_ident+BB_T("_"))+g_mx2_MungPath(g_mx2_MakeRelativePath(g_std_filesystem_StripExt(l_path),f0.l_module->m_baseDir)));
    f1.l_parser=bbGCNew<t_mx2_Parser>();
    bbString l_cd=this->m_currentDir;
    this->m_currentDir=g_std_filesystem_ExtractDir(l_path);
    f1.l_fdecl=f1.l_parser->m_ParseFile(l_ident,l_path,this->m_ppsyms);
    f1.l_fdecl->m_module=f0.l_module;
    f1.l_fdecl->m_hfile=((f0.l_module->m_hfileDir+l_ident)+BB_T(".h"));
    f1.l_fdecl->m_cfile=((f0.l_module->m_cfileDir+l_ident)+BB_T(".cpp"));
    f0.l_module->m_fileDecls->m_Push(f1.l_fdecl);
    {
      bbInt l_0=bbInt(0);
      bbInt l_1=f1.l_fdecl->m_imports->length();
      for(;(l_0<l_1);l_0+=1){
        bbString l_imp=f1.l_fdecl->m_imports->at(l_0);
        this->m_ImportFile(l_imp);
      }
    }
    this->m_currentDir=l_cd;
  }
}

bbString t_mx2_Builder::m_Link(){
  if(this->m_opts->m_productType==BB_T("app")){
    return this->m_CreateApp();
  }else if(this->m_opts->m_productType==BB_T("module")){
    return this->m_CreateArchive();
  }
  return bbString{};
}

void t_mx2_Builder::m_ImportSystemFile(bbString l_path){
  bbString l_ext=g_std_filesystem_ExtractExt(l_path);
  bbString l_name=g_std_filesystem_StripExt(l_path);
  if((l_ext==BB_T(".monkey2"))){
    this->m_parsingModule->m_moduleDeps->m__idxeq(l_name,true);
  }
  if(this->m_imported->m_Contains(l_path)){
    return;
  }
  this->m_imported->m__idxeq(l_path,true);
  bbString l_0=l_ext.toLower();
  if(l_0==BB_T(".a")){
    if(l_name.startsWith(BB_T("lib"))){
      l_name=l_name.slice(3);
    }else{
      l_name=l_path;
    }
    this->m_LD_0SYSLIBS->m_Push((BB_T("-l")+l_name));
  }else if(l_0==BB_T(".lib")||l_0==BB_T(".dylib")){
    this->m_LD_0SYSLIBS->m_Push((BB_T("-l")+l_name));
  }else if(l_0==BB_T(".framework")){
    this->m_LD_0SYSLIBS->m_Push((BB_T("-framework ")+l_name));
  }else if(l_0==BB_T(".h")||l_0==BB_T(".hh")||l_0==BB_T(".hpp")){
  }else if(l_0==BB_T(".monkey2")){
    this->m_MX2_0LIBS->m_Push(l_name);
  }else{
    bbGCNew<t_mx2_BuildEx>(((BB_T("Unrecognized import file type: '")+l_path)+BB_T("'")));
  }
}

void t_mx2_Builder::m_ImportLocalFile(bbString l_path){
  if(this->m_imported->m_Contains(l_path)){
    return;
  }
  this->m_imported->m__idxeq(l_path,true);
  bbString l_ext=g_std_filesystem_ExtractExt(l_path).toLower();
  bbString l_name=g_std_filesystem_StripDir(g_std_filesystem_StripExt(l_path));
  if((l_name==BB_T("*"))){
    bbString l_dir=g_std_filesystem_ExtractDir(l_path);
    if((g_std_filesystem_GetFileType(l_dir)!=g_std_filesystem_FILETYPE_0DIR)){
      bbGCNew<t_mx2_BuildEx>(((BB_T("Directory '")+l_dir)+BB_T("' not found")));
      return;
    }
    bbString l_qdir=((BB_T("\"")+l_dir)+BB_T("\""));
    if(l_ext==BB_T(".h")){
      this->m_CC_0OPTS->m_Push((BB_T("-I")+l_qdir));
      this->m_CPP_0OPTS->m_Push((BB_T("-I")+l_qdir));
    }else if(l_ext==BB_T(".hh")||l_ext==BB_T(".hpp")){
      this->m_CPP_0OPTS->m_Push((BB_T("-I")+l_qdir));
    }else if(l_ext==BB_T(".a")||l_ext==BB_T(".lib")||l_ext==BB_T(".dylib")){
      this->m_LD_0OPTS->m_Push((BB_T("-L")+l_qdir));
    }else if(l_ext==BB_T(".framework")){
      this->m_LD_0OPTS->m_Push((BB_T("-F")+l_qdir));
    }else{
      bbGCNew<t_mx2_BuildEx>(((BB_T("Unrecognized import file filter '*")+l_ext)+BB_T("'")));
    }
    return;
  }
  bbString l_qpath=((BB_T("\"")+l_path)+BB_T("\""));
  if(l_ext==BB_T(".framework")){
    if((g_std_filesystem_GetFileType(l_path)!=g_std_filesystem_FILETYPE_0DIR)){
      bbGCNew<t_mx2_BuildEx>(((BB_T("Framework ")+l_qpath)+BB_T(" not found")));
      return;
    }
  }else{
    bbString l_tpath=l_path;
    bbInt l_i=l_tpath.find(BB_T("@/"),bbInt(0));
    if((l_i!=-1)){
      l_tpath=l_tpath.slice(bbInt(0),l_i);
    }
    if((g_std_filesystem_GetFileType(l_tpath)!=g_std_filesystem_FILETYPE_0FILE)){
      bbGCNew<t_mx2_BuildEx>(((BB_T("File ")+l_qpath)+BB_T(" not found")));
      return;
    }
  }
  if(l_ext==BB_T(".mx2")||l_ext==BB_T(".monkey2")){
    this->m_MX2_0SRCS->m_Push(l_path);
  }else if(l_ext==BB_T(".h")||l_ext==BB_T(".hh")||l_ext==BB_T(".hpp")){
  }else if(l_ext==BB_T(".c")||l_ext==BB_T(".cc")||l_ext==BB_T(".cxx")||l_ext==BB_T(".cpp")||l_ext==BB_T(".m")||l_ext==BB_T(".mm")){
    if((this->m_parsingModule==this->m_mainModule)){
      this->m_SRC_0FILES->m_Push(l_path);
    }
  }else if(l_ext==BB_T(".o")){
    this->m_OBJ_0FILES->m_Push(l_path);
  }else if(l_ext==BB_T(".a")||l_ext==BB_T(".lib")){
    this->m_LD_0SYSLIBS->m_Push(l_qpath);
  }else if(l_ext==BB_T(".so")||l_ext==BB_T(".dll")||l_ext==BB_T(".exe")){
    this->m_DLL_0FILES->m_Push(l_path);
  }else if(l_ext==BB_T(".dylib")){
    this->m_LD_0SYSLIBS->m_Push(l_qpath);
    this->m_DLL_0FILES->m_Push(l_path);
  }else if(l_ext==BB_T(".framework")){
    this->m_ImportLocalFile((g_std_filesystem_ExtractDir(l_path)+BB_T("*.framework")));
    this->m_ImportSystemFile(g_std_filesystem_StripDir(l_path));
    this->m_DLL_0FILES->m_Push(l_path);
  }else{
    this->m_ASSET_0FILES->m_Push(l_path);
  }
}

void t_mx2_Builder::m_ImportFile(bbString l_path){
  if((l_path.startsWith(BB_T("<"))&&l_path.endsWith(BB_T(">")))){
    this->m_ImportSystemFile(l_path.slice(1,-1));
  }else{
    if(bbBool(this->m_currentDir)){
      l_path=(this->m_currentDir+l_path);
    }
    this->m_ImportLocalFile(l_path);
  }
}

t_mx2_NamespaceScope* t_mx2_Builder::m_GetNamespace(bbString l_path){
  struct f0_t : public bbGCFrame{
    t_mx2_NamespaceScope* l_nmspace{};
    void gcMark(){
      bbGCMarkPtr(l_nmspace);
    }
  }f0{};
  f0.l_nmspace=this->m_rootNamespace;
  bbInt l_i0=bbInt(0);
  while((l_i0<l_path.length())){
    struct f1_t : public bbGCFrame{
      t_mx2_NamespaceType* l_ntype{};
      t_mx2_Type* t0{};
      void gcMark(){
        bbGCMarkPtr(l_ntype);
        bbGCMarkPtr(t0);
      }
    }f1{};
    bbInt l_i1=l_path.find(BB_T("."),l_i0);
    if((l_i1==-1)){
      l_i1=l_path.length();
    }
    bbString l_id=l_path.slice(l_i0,l_i1);
    l_i0=(l_i1+1);
    f1.l_ntype=g_mx2_TCast_1Tt_mx2_NamespaceType_2(f1.t0=f0.l_nmspace->m_GetType(l_id));
    if(!bbBool(f1.l_ntype)){
      f1.l_ntype=bbGCNew<t_mx2_NamespaceType>(l_id,f0.l_nmspace);
      f0.l_nmspace->m_Insert(l_id,((t_mx2_SNode*)(f1.l_ntype)));
    }
    f0.l_nmspace=f1.l_ntype->m_scope;
  }
  return f0.l_nmspace;
}

bbBool t_mx2_Builder::m_Exec(bbString l_cmd){
  g_std_filesystem_CreateDir(BB_T("tmp"),true);
  bbString l_errs=bbString{};
  {
    bbInt l_i=1;
    for(;(l_i<10);l_i+=1){
      l_errs=((BB_T("tmp/errs")+bbString(l_i))+BB_T(".txt"));
      g_std_filesystem_DeleteFile(l_errs);
      if((g_std_filesystem_GetFileType(l_errs)==0)){
        break;
      }
      l_errs=bbString{};
    }
  }
  if(!bbBool(system_(bbCString(((l_cmd+BB_T(" 2>"))+l_errs))))){
    return true;
  }
  bbString l_terrs=g_std_stringio_LoadString(l_errs);
  throw bbGCNew<t_mx2_BuildEx>((((((BB_T("System command '")+l_cmd)+BB_T("' failed.\n\n"))+l_cmd)+BB_T("\n\n"))+l_terrs));
}

void t_mx2_Builder::m_CreatePrimTypes(){
  struct f0_t : public bbGCFrame{
    t_mx2_NamespaceScope* l_types{};
    t_mx2_SNode* t0{};
    t_mx2_ClassType* t1{};
    void gcMark(){
      bbGCMarkPtr(l_types);
      bbGCMarkPtr(t0);
      bbGCMarkPtr(t1);
    }
  }f0{};
  f0.l_types=this->m_monkeyNamespace;
  {
    struct f1_t : public bbGCFrame{
      t_std_collections_Stack_1Tt_mx2_Scope_2_Iterator l_0{};
      void gcMark(){
        bbGCMark(l_0);
      }
    }f1{};
    f1.l_0=this->m_monkeyNamespace->m_inner->m_All();
    for(;!f1.l_0.m_AtEnd();f1.l_0.m_Bump()){
      struct f2_t : public bbGCFrame{
        t_mx2_NamespaceScope* l_nmspace{};
        t_mx2_Scope* l_scope{};
        void gcMark(){
          bbGCMarkPtr(l_nmspace);
          bbGCMarkPtr(l_scope);
        }
      }f2{};
      f2.l_scope=f1.l_0.m_Current();
      f2.l_nmspace=bb_object_cast<t_mx2_NamespaceScope*>(f2.l_scope);
      if((!bbBool(f2.l_nmspace)||(f2.l_nmspace->m_ntype->m_ident!=BB_T("types")))){
        continue;
      }
      f0.l_types=f2.l_nmspace;
      break;
    }
  }
  g_mx2_Type_BoolType=bbGCNew<t_mx2_PrimType>(f0.t1=g_mx2_TCast_1Tt_mx2_ClassType_2(f0.t0=f0.l_types->m_nodes->m__idx(BB_T("@bool"))));
  g_mx2_Type_ByteType=bbGCNew<t_mx2_PrimType>(f0.t1=g_mx2_TCast_1Tt_mx2_ClassType_2(f0.t0=f0.l_types->m_nodes->m__idx(BB_T("@byte"))));
  g_mx2_Type_UByteType=bbGCNew<t_mx2_PrimType>(f0.t1=g_mx2_TCast_1Tt_mx2_ClassType_2(f0.t0=f0.l_types->m_nodes->m__idx(BB_T("@ubyte"))));
  g_mx2_Type_ShortType=bbGCNew<t_mx2_PrimType>(f0.t1=g_mx2_TCast_1Tt_mx2_ClassType_2(f0.t0=f0.l_types->m_nodes->m__idx(BB_T("@short"))));
  g_mx2_Type_UShortType=bbGCNew<t_mx2_PrimType>(f0.t1=g_mx2_TCast_1Tt_mx2_ClassType_2(f0.t0=f0.l_types->m_nodes->m__idx(BB_T("@ushort"))));
  g_mx2_Type_IntType=bbGCNew<t_mx2_PrimType>(f0.t1=g_mx2_TCast_1Tt_mx2_ClassType_2(f0.t0=f0.l_types->m_nodes->m__idx(BB_T("@int"))));
  g_mx2_Type_UIntType=bbGCNew<t_mx2_PrimType>(f0.t1=g_mx2_TCast_1Tt_mx2_ClassType_2(f0.t0=f0.l_types->m_nodes->m__idx(BB_T("@uint"))));
  g_mx2_Type_LongType=bbGCNew<t_mx2_PrimType>(f0.t1=g_mx2_TCast_1Tt_mx2_ClassType_2(f0.t0=f0.l_types->m_nodes->m__idx(BB_T("@long"))));
  g_mx2_Type_ULongType=bbGCNew<t_mx2_PrimType>(f0.t1=g_mx2_TCast_1Tt_mx2_ClassType_2(f0.t0=f0.l_types->m_nodes->m__idx(BB_T("@ulong"))));
  g_mx2_Type_FloatType=bbGCNew<t_mx2_PrimType>(f0.t1=g_mx2_TCast_1Tt_mx2_ClassType_2(f0.t0=f0.l_types->m_nodes->m__idx(BB_T("@float"))));
  g_mx2_Type_DoubleType=bbGCNew<t_mx2_PrimType>(f0.t1=g_mx2_TCast_1Tt_mx2_ClassType_2(f0.t0=f0.l_types->m_nodes->m__idx(BB_T("@double"))));
  g_mx2_Type_StringType=bbGCNew<t_mx2_PrimType>(f0.t1=g_mx2_TCast_1Tt_mx2_ClassType_2(f0.t0=f0.l_types->m_nodes->m__idx(BB_T("@string"))));
  g_mx2_Type_ArrayClass=g_mx2_TCast_1Tt_mx2_ClassType_2(f0.t0=f0.l_types->m_nodes->m__idx(BB_T("@Array")));
  g_mx2_Type_ObjectClass=g_mx2_TCast_1Tt_mx2_ClassType_2(f0.t0=f0.l_types->m_nodes->m__idx(BB_T("@object")));
  g_mx2_Type_ThrowableClass=g_mx2_TCast_1Tt_mx2_ClassType_2(f0.t0=f0.l_types->m_nodes->m__idx(BB_T("@throwable")));
  g_mx2_Type_CStringClass=g_mx2_TCast_1Tt_mx2_ClassType_2(f0.t0=f0.l_types->m_nodes->m__idx(BB_T("CString")));
  g_mx2_Type_WStringClass=g_mx2_TCast_1Tt_mx2_ClassType_2(f0.t0=f0.l_types->m_nodes->m__idx(BB_T("WString")));
  g_mx2_Type_Utf8StringClass=g_mx2_TCast_1Tt_mx2_ClassType_2(f0.t0=f0.l_types->m_nodes->m__idx(BB_T("Utf8String")));
  g_mx2_Type_ExceptionClass=g_mx2_TCast_1Tt_mx2_ClassType_2(f0.t0=f0.l_types->m_nodes->m__idx(BB_T("@Exception")));
  this->m_rootNamespace->m_Insert(BB_T("void"),((t_mx2_SNode*)(g_mx2_Type_VoidType)));
  this->m_rootNamespace->m_Insert(BB_T("bool"),((t_mx2_SNode*)(g_mx2_Type_BoolType)));
  this->m_rootNamespace->m_Insert(BB_T("byte"),((t_mx2_SNode*)(g_mx2_Type_ByteType)));
  this->m_rootNamespace->m_Insert(BB_T("ubyte"),((t_mx2_SNode*)(g_mx2_Type_UByteType)));
  this->m_rootNamespace->m_Insert(BB_T("short"),((t_mx2_SNode*)(g_mx2_Type_ShortType)));
  this->m_rootNamespace->m_Insert(BB_T("ushort"),((t_mx2_SNode*)(g_mx2_Type_UShortType)));
  this->m_rootNamespace->m_Insert(BB_T("int"),((t_mx2_SNode*)(g_mx2_Type_IntType)));
  this->m_rootNamespace->m_Insert(BB_T("uint"),((t_mx2_SNode*)(g_mx2_Type_UIntType)));
  this->m_rootNamespace->m_Insert(BB_T("long"),((t_mx2_SNode*)(g_mx2_Type_LongType)));
  this->m_rootNamespace->m_Insert(BB_T("ulong"),((t_mx2_SNode*)(g_mx2_Type_ULongType)));
  this->m_rootNamespace->m_Insert(BB_T("float"),((t_mx2_SNode*)(g_mx2_Type_FloatType)));
  this->m_rootNamespace->m_Insert(BB_T("double"),((t_mx2_SNode*)(g_mx2_Type_DoubleType)));
  this->m_rootNamespace->m_Insert(BB_T("string"),((t_mx2_SNode*)(g_mx2_Type_StringType)));
  this->m_rootNamespace->m_Insert(BB_T("object"),((t_mx2_SNode*)(g_mx2_Type_ObjectClass)));
  this->m_rootNamespace->m_Insert(BB_T("throwable"),((t_mx2_SNode*)(g_mx2_Type_ThrowableClass)));
  this->m_rootNamespace->m_Insert(BB_T("CString"),((t_mx2_SNode*)(g_mx2_Type_CStringClass)));
  this->m_rootNamespace->m_Insert(BB_T("WString"),((t_mx2_SNode*)(g_mx2_Type_WStringClass)));
  this->m_rootNamespace->m_Insert(BB_T("Utf8String"),((t_mx2_SNode*)(g_mx2_Type_Utf8StringClass)));
  this->m_rootNamespace->m_Insert(BB_T("Exception"),((t_mx2_SNode*)(g_mx2_Type_ExceptionClass)));
  g_mx2_Type_BoolType->m_Semant();
  g_mx2_Type_ByteType->m_Semant();
  g_mx2_Type_UByteType->m_Semant();
  g_mx2_Type_ShortType->m_Semant();
  g_mx2_Type_UShortType->m_Semant();
  g_mx2_Type_IntType->m_Semant();
  g_mx2_Type_UIntType->m_Semant();
  g_mx2_Type_LongType->m_Semant();
  g_mx2_Type_ULongType->m_Semant();
  g_mx2_Type_FloatType->m_Semant();
  g_mx2_Type_DoubleType->m_Semant();
  g_mx2_Type_StringType->m_Semant();
  g_mx2_Type_ArrayClass->m_Semant();
  g_mx2_Type_ObjectClass->m_Semant();
  g_mx2_Type_ThrowableClass->m_Semant();
}

bbString t_mx2_Builder::m_CreateArchive(){
  struct f0_t : public bbGCFrame{
    t_mx2_Module* l_module{};
    void gcMark(){
      bbGCMarkPtr(l_module);
    }
  }f0{};
  f0.l_module=this->m_mainModule;
  bbString l_outputFile=((f0.l_module->m_outputDir+f0.l_module->m_name)+BB_T(".a"));
  if((g_std_filesystem_GetFileTime(l_outputFile)>this->m_maxObjTime)){
    return l_outputFile;
  }
  if((this->m_opts->m_verbose>=bbInt(0))){
    puts((BB_T("Archiving ")+l_outputFile).c_str());fflush( stdout );
  }
  g_std_filesystem_DeleteFile(l_outputFile);
  bbString l_objs=bbString{};
  {
    bbInt l_i=bbInt(0);
    for(;(l_i<this->m_OBJ_0FILES->m_Length());l_i+=1){
      l_objs+=((BB_T(" \"")+this->m_OBJ_0FILES->m_Get(l_i))+BB_T("\""));
      if(((l_objs.length()<1000)&&(l_i<(this->m_OBJ_0FILES->m_Length()-1)))){
        continue;
      }
      bbString l_cmd=((((this->m_AR_0CMD+BB_T(" q \""))+l_outputFile)+BB_T("\""))+l_objs);
      this->m_Exec(l_cmd);
      l_objs=bbString{};
    }
  }
  return l_outputFile;
}

bbString t_mx2_Builder::m_CreateApp(){
  struct f0_t : public bbGCFrame{
    t_mx2_Module* l_module{};
    void gcMark(){
      bbGCMarkPtr(l_module);
    }
  }f0{};
  f0.l_module=this->m_mainModule;
  bbString l_outputFile=bbString{};
  bbString l_assetsDir=bbString{};
  bbString l_dllsDir=bbString{};
  bbString l_cmd=this->m_LD_0CMD;
  l_cmd+=(BB_T(" ")+this->m_LD_0OPTS->m_Join(BB_T(" ")));
  if((this->m_opts->m_target==BB_T("emscripten"))){
    l_outputFile=((f0.l_module->m_outputDir+f0.l_module->m_name)+BB_T(".html"));
    l_assetsDir=(f0.l_module->m_buildDir+BB_T("assets/"));
    l_dllsDir=g_std_filesystem_ExtractDir(l_outputFile);
    l_cmd+=((BB_T(" --preload-file \"")+l_assetsDir)+BB_T("@/assets\""));
  }else if((g_mx2_HostOS==BB_T("windows"))){
    if((this->m_opts->m_appType==BB_T("gui"))){
      l_cmd+=BB_T(" -mwindows");
    }
    l_outputFile=((f0.l_module->m_outputDir+f0.l_module->m_name)+BB_T(".exe"));
    l_assetsDir=(f0.l_module->m_outputDir+BB_T("assets/"));
    l_dllsDir=g_std_filesystem_ExtractDir(l_outputFile);
  }else if((g_mx2_HostOS==BB_T("macos"))){
    if((this->m_opts->m_appType==BB_T("gui"))){
      bbString l_productName=f0.l_module->m_name;
      bbString l_outputDir=((f0.l_module->m_outputDir+f0.l_module->m_name)+BB_T(".app/"));
      l_outputFile=((l_outputDir+BB_T("Contents/MacOS/"))+f0.l_module->m_name);
      l_assetsDir=(l_outputDir+BB_T("Contents/Resources/"));
      l_dllsDir=g_std_filesystem_ExtractDir(l_outputFile);
      g_std_filesystem_CreateDir(l_outputDir,true);
      g_std_filesystem_CreateDir((l_outputDir+BB_T("Contents")),true);
      g_std_filesystem_CreateDir((l_outputDir+BB_T("Contents/MacOS")),true);
      g_std_filesystem_CreateDir((l_outputDir+BB_T("Contents/Resources")),true);
      bbString l_plist=bbString{};
      l_plist+=BB_T("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n");
      l_plist+=BB_T("<!DOCTYPE plist PUBLIC \"-//Apple Computer//DTD PLIST 1.0//EN\" \"http://www.apple.com/DTDs/PropertyList-1.0.dtd\">\n");
      l_plist+=BB_T("<plist version=\"1.0\">\n");
      l_plist+=BB_T("<dict>\n");
      l_plist+=BB_T("\t<key>CFBundleExecutable</key>\n");
      l_plist+=((BB_T("\t<string>")+l_productName)+BB_T("</string>\n"));
      l_plist+=BB_T("\t<key>CFBundleIconFile</key>\n");
      l_plist+=((BB_T("\t<string>")+l_productName)+BB_T("</string>\n"));
      l_plist+=BB_T("\t<key>CFBundlePackageType</key>\n");
      l_plist+=BB_T("\t<string>APPL</string>\n");
      l_plist+=BB_T("</dict>\n");
      l_plist+=BB_T("</plist>\n");
      g_std_stringio_SaveString(l_plist,(l_outputDir+BB_T("Contents/Info.plist")));
    }else{
      l_outputFile=(f0.l_module->m_outputDir+f0.l_module->m_name);
      l_assetsDir=(f0.l_module->m_outputDir+BB_T("assets/"));
      l_dllsDir=g_std_filesystem_ExtractDir(l_outputFile);
    }
  }else{
    l_outputFile=(f0.l_module->m_outputDir+f0.l_module->m_name);
    l_assetsDir=(f0.l_module->m_outputDir+BB_T("assets/"));
    l_dllsDir=g_std_filesystem_ExtractDir(l_outputFile);
  }
  if((this->m_opts->m_verbose>=bbInt(0))){
    puts((BB_T("Linking ")+l_outputFile).c_str());fflush( stdout );
  }
  g_std_filesystem_DeleteDir(l_assetsDir,true);
  g_std_filesystem_CreateDir(l_assetsDir,true);
  {
    struct f1_t : public bbGCFrame{
      t_std_collections_Stack_1s_Iterator l_0{};
      void gcMark(){
        bbGCMark(l_0);
      }
    }f1{};
    f1.l_0=this->m_ASSET_0FILES->m_All();
    for(;!f1.l_0.m_AtEnd();f1.l_0.m_Bump()){
      bbString l_ass=f1.l_0.m_Current();
      bbInt l_i=l_ass.find(BB_T("@/"),bbInt(0));
      if((l_i==-1)){
        bbFileSystem::copyFile(l_ass,(l_assetsDir+g_std_filesystem_StripDir(l_ass)));
        continue;
      }
      bbString l_dst=(l_assetsDir+l_ass.slice((l_i+2)));
      if(!l_dst.endsWith(BB_T("/"))){
        l_dst+=BB_T("/");
      }
      g_std_filesystem_CreateDir(l_dst,true);
      l_ass=l_ass.slice(bbInt(0),l_i);
      bbFileSystem::copyFile(l_ass,(l_dst+g_std_filesystem_StripDir(l_ass)));
    }
  }
  l_cmd+=((BB_T(" -o \"")+l_outputFile)+BB_T("\""));
  {
    struct f1_t : public bbGCFrame{
      t_std_collections_Stack_1s_Iterator l_1{};
      void gcMark(){
        bbGCMark(l_1);
      }
    }f1{};
    f1.l_1=this->m_OBJ_0FILES->m_All();
    for(;!f1.l_1.m_AtEnd();f1.l_1.m_Bump()){
      bbString l_obj=f1.l_1.m_Current();
      l_cmd+=((BB_T(" \"")+l_obj)+BB_T("\""));
    }
  }
  {
    struct f1_t : public bbGCFrame{
      t_std_collections_Stack_1s_Iterator l_2{};
      void gcMark(){
        bbGCMark(l_2);
      }
    }f1{};
    f1.l_2=this->m_LD_0LIBS->m_All();
    for(;!f1.l_2.m_AtEnd();f1.l_2.m_Bump()){
      bbString l_lib=f1.l_2.m_Current();
      l_cmd+=((BB_T(" \"")+l_lib)+BB_T("\""));
    }
  }
  l_cmd+=(BB_T(" ")+this->m_LD_0SYSLIBS->m_Join(BB_T(" ")));
  this->m_Exec(l_cmd);
  {
    struct f1_t : public bbGCFrame{
      t_std_collections_Stack_1s_Iterator l_3{};
      void gcMark(){
        bbGCMark(l_3);
      }
    }f1{};
    f1.l_3=this->m_DLL_0FILES->m_All();
    for(;!f1.l_3.m_AtEnd();f1.l_3.m_Bump()){
      bbString l_src=f1.l_3.m_Current();
      bbString l_dir=l_dllsDir;
      bbString l_ext=g_std_filesystem_ExtractExt(l_src);
      if(bbBool(l_ext)){
        bbString l_rdir=g_mx2_GetEnv((BB_T("MX2_APP_DIR_")+l_ext.slice(1).toUpper()));
        if(bbBool(l_rdir)){
          l_dir=g_std_filesystem_RealPath((l_dir+l_rdir));
        }
      }
      if(!l_dir.endsWith(BB_T("/"))){
        l_dir+=BB_T("/");
      }
      bbString l_dst=(l_dir+g_std_filesystem_StripDir(l_src));
      if(!this->m_CopyAll(l_src,l_dst)){
        throw bbGCNew<t_mx2_BuildEx>(((((BB_T("Failed to copy '")+l_src)+BB_T("' to '"))+l_dst)+BB_T("'")));
      }
    }
  }
  if(!this->m_opts->m_run){
    return l_outputFile;
  }
  bbString l_run=bbString{};
  if((this->m_opts->m_target==BB_T("emscripten"))){
    bbString l_mserver=g_mx2_GetEnv(BB_T("MX2_MSERVER"));
    l_run=(((l_mserver+BB_T(" \""))+l_outputFile)+BB_T("\""));
  }else{
    l_run=((BB_T("\"")+l_outputFile)+BB_T("\""));
  }
  if((this->m_opts->m_verbose>=bbInt(0))){
    puts((BB_T("Running ")+l_outputFile).c_str());fflush( stdout );
  }
  this->m_Exec(l_run);
  return l_outputFile;
}

bbBool t_mx2_Builder::m_CopyAll(bbString l_src,bbString l_dst){
  bbInt l_0=g_std_filesystem_GetFileType(l_src);
  if(l_0==g_std_filesystem_FILETYPE_0FILE){
    if(!g_std_filesystem_CreateDir(g_std_filesystem_ExtractDir(l_dst),true)){
      return false;
    }
    if((g_std_filesystem_GetFileTime(l_src)>g_std_filesystem_GetFileTime(l_dst))){
      if(!bbFileSystem::copyFile(l_src,l_dst)){
        return false;
      }
    }
    return true;
  }else if(l_0==g_std_filesystem_FILETYPE_0DIR){
    if(!g_std_filesystem_CreateDir(l_dst,true)){
      return false;
    }
    {
      struct f2_t : public bbGCFrame{
        bbArray<bbString>* l_1{};
        void gcMark(){
          bbGCMarkPtr(l_1);
        }
      }f2{};
      f2.l_1=g_std_filesystem_LoadDir(l_src);
      bbInt l_2=bbInt(0);
      bbInt l_3=f2.l_1->length();
      for(;(l_2<l_3);l_2+=1){
        bbString l_file=f2.l_1->at(l_2);
        if(!this->m_CopyAll(((l_src+BB_T("/"))+l_file),((l_dst+BB_T("/"))+l_file))){
          return false;
        }
      }
    }
    return true;
  }
  return false;
}

void t_mx2_Builder::m_Compile(){
  struct f0_t : public bbGCFrame{
    t_mx2_Module* l_module{};
    void gcMark(){
      bbGCMarkPtr(l_module);
    }
  }f0{};
  if((this->m_opts->m_verbose==bbInt(0))){
    puts(BB_T("Compiling....").c_str());fflush( stdout );
  }
  f0.l_module=this->m_mainModule;
  {
    struct f1_t : public bbGCFrame{
      t_std_collections_Stack_1s_Iterator l_0{};
      void gcMark(){
        bbGCMark(l_0);
      }
    }f1{};
    f1.l_0=this->m_SRC_0FILES->m_All();
    for(;!f1.l_0.m_AtEnd();f1.l_0.m_Bump()){
      bbString l_src=f1.l_0.m_Current();
      bbString l_obj=((f0.l_module->m_cacheDir+g_mx2_MungPath(g_mx2_MakeRelativePath(l_src,f0.l_module->m_cacheDir)))+BB_T(".o"));
      bbString l_cmd=bbString{};
      bbString l_1=g_std_filesystem_ExtractExt(l_src);
      if(l_1==BB_T(".c")||l_1==BB_T(".m")){
        l_cmd=((this->m_CC_0CMD+BB_T(" "))+this->m_CC_0OPTS->m_Join(BB_T(" ")));
      }else if(l_1==BB_T(".cc")||l_1==BB_T(".cxx")||l_1==BB_T(".cpp")||l_1==BB_T(".mm")){
        l_cmd=((this->m_CXX_0CMD+BB_T(" "))+this->m_CPP_0OPTS->m_Join(BB_T(" ")));
      }
      l_cmd+=((BB_T(" -I\"")+this->m_modulesDir)+BB_T("monkey/native\""));
      bbLong l_objTime=g_std_filesystem_GetFileTime(l_obj);
      bbString l_deps=(g_std_filesystem_StripExt(l_obj)+BB_T(".deps"));
      if((this->m_opts->m_fast&&(l_objTime>=g_std_filesystem_GetFileTime(l_src)))){
        struct f3_t : public bbGCFrame{
          bbArray<bbString>* l_srcs{};
          void gcMark(){
            bbGCMarkPtr(l_srcs);
          }
        }f3{};
        if((g_std_filesystem_GetFileType(l_deps)==g_std_filesystem_FILETYPE_0NONE)){
          if((this->m_opts->m_verbose>bbInt(0))){
            puts((BB_T("Scanning ")+l_src).c_str());fflush( stdout );
          }
          this->m_Exec((((((l_cmd+BB_T(" -MM \""))+l_src)+BB_T("\" >\""))+l_deps)+BB_T("\"")));
        }
        bbBool l_uptodate=true;
        f3.l_srcs=g_std_stringio_LoadString(l_deps).split(BB_T(" \\"));
        {
          bbInt l_i=1;
          for(;(l_i<f3.l_srcs->length());l_i+=1){
            if((g_std_filesystem_GetFileTime(f3.l_srcs->at(l_i).trim())>l_objTime)){
              l_uptodate=false;
              break;
            }
          }
        }
        if(l_uptodate){
          this->m_maxObjTime=g_monkey_math_Max_1l(this->m_maxObjTime,l_objTime);
          this->m_OBJ_0FILES->m_Push(l_obj);
          continue;
        }
      }else{
        g_std_filesystem_DeleteFile(l_deps);
      }
      if((this->m_opts->m_verbose>bbInt(0))){
        puts((BB_T("Compiling ")+l_src).c_str());fflush( stdout );
      }
      l_cmd+=((((BB_T(" -c -o \"")+l_obj)+BB_T("\" \""))+l_src)+BB_T("\""));
      this->m_Exec(l_cmd);
      this->m_maxObjTime=g_monkey_math_Max_1l(this->m_maxObjTime,g_std_filesystem_GetFileTime(l_obj));
      this->m_OBJ_0FILES->m_Push(l_obj);
    }
  }
}

void t_mx2_Builder::m_ClearPrimTypes(){
  g_mx2_Type_BoolType=((t_mx2_PrimType*)0);
  g_mx2_Type_ByteType=((t_mx2_PrimType*)0);
  g_mx2_Type_UByteType=((t_mx2_PrimType*)0);
  g_mx2_Type_ShortType=((t_mx2_PrimType*)0);
  g_mx2_Type_UShortType=((t_mx2_PrimType*)0);
  g_mx2_Type_IntType=((t_mx2_PrimType*)0);
  g_mx2_Type_UIntType=((t_mx2_PrimType*)0);
  g_mx2_Type_LongType=((t_mx2_PrimType*)0);
  g_mx2_Type_ULongType=((t_mx2_PrimType*)0);
  g_mx2_Type_FloatType=((t_mx2_PrimType*)0);
  g_mx2_Type_DoubleType=((t_mx2_PrimType*)0);
  g_mx2_Type_StringType=((t_mx2_PrimType*)0);
  g_mx2_Type_ArrayClass=((t_mx2_ClassType*)0);
  g_mx2_Type_ObjectClass=((t_mx2_ClassType*)0);
  g_mx2_Type_ThrowableClass=((t_mx2_ClassType*)0);
}

void mx2_mx2cc_builder_init(){
  static bool done;
  if(done) return;
  done=true;
}

bbInit mx2_mx2cc_builder_init_v("mx2cc_builder",&mx2_mx2cc_builder_init);
