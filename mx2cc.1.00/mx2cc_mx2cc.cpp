
#include "mx2cc_mx2cc.h"

// ***** External *****

#include "../../../../../modules/libc/libc.buildv1.0.0/desktop_release_linux/libc_libc.h"
#include "../../../../../modules/monkey/monkey.buildv1.0.0/desktop_release_linux/monkey_types.h"
#include "mx2cc_builder.h"
#include "mx2cc_docs_2docsmaker.h"
#include "mx2cc_errors.h"
#include "mx2cc_module.h"
#include "mx2cc_std_collections_2map.h"
#include "mx2cc_std_collections_2stack.h"
#include "../../../../../modules/std/std.buildv1.0.0/desktop_release_linux/std_collections_2stack.h"
#include "../../../../../modules/std/std.buildv1.0.0/desktop_release_linux/std_misc_2filesystem.h"
#include "../../../../../modules/std/std.buildv1.0.0/desktop_release_linux/std_misc_2json.h"

extern bbString g_mx2_MX2CC_0VERSION;
extern bbString g_mx2_HostOS;

extern bbString g_mx2_GetEnv(bbString l_name);
extern void g_mx2_SetEnv(bbString l_name,bbString l_value);
extern bbString g_std_stringio_LoadString(bbString l_path);
extern bbBool g_std_stringio_SaveString(bbString l_str,bbString l_path);

// ***** Internal *****

bbString g_mx2cc_StartDir;
bbString g_mx2cc_TestArgs;

void g_mx2cc_Fail(bbString l_msg){
  puts(bbString{}.c_str());fflush( stdout );
  puts(BB_T("***** Fatal mx2cc error *****").c_str());fflush( stdout );
  puts(bbString{}.c_str());fflush( stdout );
  puts(l_msg.c_str());fflush( stdout );
  exit(-1);
}

bbString g_mx2cc_ReplaceEnv(bbString l_str,bbInt l_lineid){
  bbInt l_i0=bbInt(0);
  for(;;){
    bbInt l_i1=l_str.find(BB_T("${"),l_i0);
    if((l_i1==-1)){
      return l_str;
    }
    bbInt l_i2=l_str.find(BB_T("}"),(l_i1+2));
    if((l_i2==-1)){
      g_mx2cc_Fail((BB_T("Env config file error at line ")+bbString(l_lineid)));
    }
    bbString l_name=l_str.slice((l_i1+2),l_i2).trim();
    bbString l_value=g_mx2_GetEnv(l_name);
    l_str=((l_str.slice(bbInt(0),l_i1)+l_value)+l_str.slice((l_i2+1)));
    l_i0=(l_i1+l_value.length());
  }
  return bbString{};
}

bbBool g_mx2cc_LoadEnv(bbString l_path){
  g_mx2_SetEnv(BB_T("MX2_HOME"),g_std_filesystem_CurrentDir());
  bbInt l_lineid=bbInt(0);
  {
    struct f1_t : public bbGCFrame{
      bbArray<bbString>* l_0{};
      void gcMark(){
        bbGCMarkPtr(l_0);
      }
    }f1{};
    f1.l_0=g_std_stringio_LoadString(l_path).split(BB_T("\n"));
    bbInt l_1=bbInt(0);
    bbInt l_2=f1.l_0->length();
    for(;(l_1<l_2);l_1+=1){
      bbString l_line=f1.l_0->at(l_1);
      l_lineid+=1;
      bbInt l_i=l_line.find(BB_T("'"),bbInt(0));
      if((l_i!=-1)){
        l_line=l_line.slice(bbInt(0),l_i);
      }
      l_line=l_line.trim();
      if(!bbBool(l_line)){
        continue;
      }
      l_i=l_line.find(BB_T("="),bbInt(0));
      if((l_i==-1)){
        g_mx2cc_Fail((BB_T("Env config file error at line ")+bbString(l_lineid)));
      }
      bbString l_name=l_line.slice(bbInt(0),l_i).trim();
      bbString l_value=l_line.slice((l_i+1)).trim();
      l_value=g_mx2cc_ReplaceEnv(l_value,l_lineid);
      g_mx2_SetEnv(l_name,l_value);
    }
  }
  return true;
}

bbArray<bbString>* g_mx2cc_EnumModules(){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1sTt_std_collections_Stack_1s_2* l_mods{};
    t_std_collections_Stack_1s* l_out{};
    void gcMark(){
      bbGCMarkPtr(l_mods);
      bbGCMarkPtr(l_out);
    }
  }f0{};
  f0.l_mods=bbGCNew<t_std_collections_Map_1sTt_std_collections_Stack_1s_2>();
  {
    struct f1_t : public bbGCFrame{
      bbArray<bbString>* l_0{};
      void gcMark(){
        bbGCMarkPtr(l_0);
      }
    }f1{};
    f1.l_0=g_std_filesystem_LoadDir(BB_T("modules"));
    bbInt l_1=bbInt(0);
    bbInt l_2=f1.l_0->length();
    for(;(l_1<l_2);l_1+=1){
      struct f2_t : public bbGCFrame{
        t_std_collections_Stack_1s* l_deps{};
        t_std_json_JsonValue* l_jdeps{};
        t_std_json_JsonObject* l_obj{};
        t_std_json_JsonValue* t0{};
        void gcMark(){
          bbGCMarkPtr(l_deps);
          bbGCMarkPtr(l_jdeps);
          bbGCMarkPtr(l_obj);
          bbGCMarkPtr(t0);
        }
      }f2{};
      bbString l_f=f1.l_0->at(l_1);
      bbString l_dir=((BB_T("modules/")+l_f)+BB_T("/"));
      if((g_std_filesystem_GetFileType(l_dir)!=2)){
        continue;
      }
      bbString l_str=g_std_stringio_LoadString((l_dir+BB_T("module.json")));
      if(!bbBool(l_str)){
        continue;
      }
      f2.l_obj=g_std_json_JsonObject_Parse(l_str);
      if(!bbBool(f2.l_obj)){
        puts(((BB_T("Error parsing json:")+l_dir)+BB_T("module.json")).c_str());fflush( stdout );
        continue;
      }
      bbString l_name=(f2.t0=f2.l_obj->m__idx(BB_T("module")))->m_ToString();
      if((l_name!=l_f)){
        continue;
      }
      f2.l_deps=bbGCNew<t_std_collections_Stack_1s>();
      if((l_name!=BB_T("monkey"))){
        f2.l_deps->m_Push(BB_T("monkey"));
      }
      f2.l_jdeps=f2.l_obj->m__idx(BB_T("depends"));
      if(bbBool(f2.l_jdeps)){
        {
          struct f4_t : public bbGCFrame{
            t_std_collections_Stack_1Tt_std_json_JsonValue_2_Iterator l_3{};
            t_std_collections_Stack_1Tt_std_json_JsonValue_2* t0{};
            void gcMark(){
              bbGCMark(l_3);
              bbGCMarkPtr(t0);
            }
          }f4{};
          f4.l_3=(f4.t0=f2.l_jdeps->m_ToArray())->m_All();
          for(;!f4.l_3.m_AtEnd();f4.l_3.m_Bump()){
            struct f5_t : public bbGCFrame{
              t_std_json_JsonValue* l_dep{};
              void gcMark(){
                bbGCMarkPtr(l_dep);
              }
            }f5{};
            f5.l_dep=f4.l_3.m_Current();
            f2.l_deps->m_Push(f5.l_dep->m_ToString());
          }
        }
      }
      f0.l_mods->m__idxeq(l_name,f2.l_deps);
    }
  }
  f0.l_out=bbGCNew<t_std_collections_Stack_1s>();
  {
    struct f1_t : public bbGCFrame{
      t_std_collections_Map_1sTt_std_collections_Stack_1s_2_KeyIterator l_4{};
      void gcMark(){
        bbGCMark(l_4);
      }
    }f1{};
    f1.l_4=f0.l_mods->m_Keys().m_All();
    for(;f1.l_4.m_Valid();f1.l_4.m_Bump()){
      bbString l_cur=f1.l_4.m_Current();
      g_mx2cc_EnumModules(f0.l_out,l_cur,f0.l_mods);
    }
  }
  return f0.l_out->m_ToArray();
}

void g_mx2cc_EnumModules(t_std_collections_Stack_1s* l_out,bbString l_cur,t_std_collections_Map_1sTt_std_collections_Stack_1s_2* l_deps){
  if(l_out->m_Contains(l_cur)){
    return;
  }
  {
    struct f1_t : public bbGCFrame{
      t_std_collections_Stack_1s_Iterator l_0{};
      t_std_collections_Stack_1s* t0{};
      void gcMark(){
        bbGCMark(l_0);
        bbGCMarkPtr(t0);
      }
    }f1{};
    f1.l_0=(f1.t0=l_deps->m__idx(l_cur))->m_All();
    for(;!f1.l_0.m_AtEnd();f1.l_0.m_Bump()){
      bbString l_dep=f1.l_0.m_Current();
      g_mx2cc_EnumModules(l_out,l_dep,l_deps);
    }
  }
  l_out->m_Push(l_cur);
}

bbArray<bbString>* g_mx2cc_ParseOpts(t_mx2_BuildOpts* l_opts,bbArray<bbString>* l_args){
  l_opts->m_verbose=bbInt(g_mx2_GetEnv(BB_T("MX2_VERBOSE")));
  {
    bbInt l_i=bbInt(0);
    for(;(l_i<l_args->length());l_i+=1){
      bbString l_arg=l_args->at(l_i);
      bbInt l_j=l_arg.find(BB_T("="),bbInt(0));
      if((l_j==-1)){
        if(l_arg==BB_T("-run")){
          l_opts->m_run=true;
        }else if(l_arg==BB_T("-build")){
          l_opts->m_run=false;
        }else if(l_arg==BB_T("-clean")){
          l_opts->m_clean=true;
        }else if(l_arg==BB_T("-verbose")){
          l_opts->m_verbose=1;
        }else{
          return l_args->slice(l_i);
        }
        continue;
      }
      bbString l_opt=l_arg.slice(bbInt(0),l_j);
      bbString l_val=l_arg.slice((l_j+1)).toLower();
      if(l_opt==BB_T("-apptype")){
        if(l_val==BB_T("gui")||l_val==BB_T("console")){
          l_opts->m_appType=l_val;
        }else{
          g_mx2cc_Fail(((BB_T("Invalid value for 'apptype' option: '")+l_val)+BB_T("' - must be 'gui' or 'console'")));
        }
      }else if(l_opt==BB_T("-target")){
        if(l_val==BB_T("desktop")||l_val==BB_T("emscripten")){
          l_opts->m_target=l_val;
        }else{
          g_mx2cc_Fail(((BB_T("Invalid value for 'target' option: '")+l_val)+BB_T("' - must be 'desktop' or 'emscripten'")));
        }
      }else if(l_opt==BB_T("-config")){
        if(l_val==BB_T("debug")||l_val==BB_T("release")){
          l_opts->m_config=l_val;
        }else{
          g_mx2cc_Fail(((BB_T("Invalid value for 'config' option: '")+l_val)+BB_T("' - must be 'debug' or 'release'")));
        }
      }else if(l_opt==BB_T("-verbose")){
        if(l_val==BB_T("0")||l_val==BB_T("1")||l_val==BB_T("2")||l_val==BB_T("-1")){
          l_opts->m_verbose=bbInt(l_val);
        }else{
          g_mx2cc_Fail(((BB_T("Invalid value for 'verbose' option: '")+l_val)+BB_T("' - must be '0', '1', '2' or '-1'")));
        }
      }else{
        g_mx2cc_Fail(((BB_T("Invalid option: '")+l_opt)+BB_T("'")));
      }
    }
  }
  return ((bbArray<bbString>*)0);
}

void g_mx2cc_MakeDocs(bbArray<bbString>* l_args){
  struct f0_t : public bbGCFrame{
    bbArray<bbString>* l_args{};
    t_mx2_docs_DocsMaker* l_docsMaker{};
    t_mx2_BuildOpts* l_opts{};
    f0_t(bbArray<bbString>* l_args):l_args(l_args){
    }
    void gcMark(){
      bbGCMarkPtr(l_args);
      bbGCMarkPtr(l_docsMaker);
      bbGCMarkPtr(l_opts);
    }
  }f0{l_args};
  f0.l_opts=bbGCNew<t_mx2_BuildOpts>();
  f0.l_opts->m_productType=BB_T("module");
  f0.l_opts->m_target=BB_T("desktop");
  f0.l_opts->m_config=BB_T("debug");
  f0.l_opts->m_clean=false;
  f0.l_opts->m_fast=true;
  f0.l_opts->m_verbose=bbInt(0);
  f0.l_args=g_mx2cc_ParseOpts(f0.l_opts,f0.l_args);
  f0.l_opts->m_clean=false;
  if(!bbBool(f0.l_args)){
    f0.l_args=g_mx2cc_EnumModules();
  }
  f0.l_docsMaker=bbGCNew<t_mx2_docs_DocsMaker>();
  bbString l_mx2_0api=bbString{};
  {
    bbInt l_0=bbInt(0);
    bbInt l_1=f0.l_args->length();
    for(;(l_0<l_1);l_0+=1){
      struct f2_t : public bbGCFrame{
        t_mx2_Builder* l_builder{};
        t_mx2_Module* t0{};
        void gcMark(){
          bbGCMarkPtr(l_builder);
          bbGCMarkPtr(t0);
        }
      }f2{};
      bbString l_modid=f0.l_args->at(l_0);
      bbString l_path=((((BB_T("modules/")+l_modid)+BB_T("/"))+l_modid)+BB_T(".monkey2"));
      if((g_std_filesystem_GetFileType(l_path)!=g_std_filesystem_FILETYPE_0FILE)){
        g_mx2cc_Fail(((BB_T("Module file '")+l_path)+BB_T("' not found")));
      }
      puts(bbString{}.c_str());fflush( stdout );
      puts(((BB_T("***** Doccing module '")+l_modid)+BB_T("' *****")).c_str());fflush( stdout );
      puts(bbString{}.c_str());fflush( stdout );
      f0.l_opts->m_mainSource=g_std_filesystem_RealPath(l_path);
      f2.l_builder=bbGCNew<t_mx2_Builder>(f0.l_opts);
      f2.l_builder->m_Parse();
      if(bbBool(f2.l_builder->m_errors->m_Length())){
        continue;
      }
      f2.l_builder->m_Semant();
      if(bbBool(f2.l_builder->m_errors->m_Length())){
        continue;
      }
      bbString l_tree=f0.l_docsMaker->m_MakeDocs(f2.t0=f2.l_builder->m_modules->m_Top());
      if(bbBool(l_mx2_0api)){
        l_mx2_0api+=BB_T(",");
      }
      l_mx2_0api+=l_tree;
    }
  }
  bbString l_mods=g_std_stringio_LoadString(BB_T("docs/modules_template.html"));
  l_mods=l_mods.replace(BB_T("${MX2_API}"),l_mx2_0api);
  g_std_stringio_SaveString(l_mods,BB_T("docs/modules.html"));
  bbString l_lang_0nav=f0.l_docsMaker->m_MakeLangNav();
  bbString l_lang=g_std_stringio_LoadString(BB_T("docs/language_template.html"));
  l_lang=l_lang.replace(BB_T("${LANG_NAV}"),l_lang_0nav);
  g_std_stringio_SaveString(l_lang,BB_T("docs/language.html"));
}

void g_mx2cc_MakeMods(bbArray<bbString>* l_args){
  struct f0_t : public bbGCFrame{
    bbArray<bbString>* l_args{};
    t_mx2_BuildOpts* l_opts{};
    f0_t(bbArray<bbString>* l_args):l_args(l_args){
    }
    void gcMark(){
      bbGCMarkPtr(l_args);
      bbGCMarkPtr(l_opts);
    }
  }f0{l_args};
  f0.l_opts=bbGCNew<t_mx2_BuildOpts>();
  f0.l_opts->m_productType=BB_T("module");
  f0.l_opts->m_target=BB_T("desktop");
  f0.l_opts->m_config=BB_T("debug");
  f0.l_opts->m_clean=false;
  f0.l_opts->m_fast=true;
  f0.l_opts->m_verbose=bbInt(0);
  f0.l_args=g_mx2cc_ParseOpts(f0.l_opts,f0.l_args);
  if(!bbBool(f0.l_args)){
    f0.l_args=g_mx2cc_EnumModules();
  }
  {
    bbInt l_0=bbInt(0);
    bbInt l_1=f0.l_args->length();
    for(;(l_0<l_1);l_0+=1){
      struct f2_t : public bbGCFrame{
        t_mx2_Builder* l_builder{};
        void gcMark(){
          bbGCMarkPtr(l_builder);
        }
      }f2{};
      bbString l_modid=f0.l_args->at(l_0);
      bbString l_path=((((BB_T("modules/")+l_modid)+BB_T("/"))+l_modid)+BB_T(".monkey2"));
      if((g_std_filesystem_GetFileType(l_path)!=g_std_filesystem_FILETYPE_0FILE)){
        g_mx2cc_Fail(((BB_T("Module file '")+l_path)+BB_T("' not found")));
      }
      puts(bbString{}.c_str());fflush( stdout );
      puts(((BB_T("***** Making module '")+l_modid)+BB_T("' *****")).c_str());fflush( stdout );
      puts(bbString{}.c_str());fflush( stdout );
      f0.l_opts->m_mainSource=g_std_filesystem_RealPath(l_path);
      f2.l_builder=bbGCNew<t_mx2_Builder>(f0.l_opts);
      f2.l_builder->m_Parse();
      if(bbBool(f2.l_builder->m_errors->m_Length())){
        continue;
      }
      f2.l_builder->m_Semant();
      if(bbBool(f2.l_builder->m_errors->m_Length())){
        continue;
      }
      f2.l_builder->m_Translate();
      if(bbBool(f2.l_builder->m_errors->m_Length())){
        continue;
      }
      f2.l_builder->m_Compile();
      if(bbBool(f2.l_builder->m_errors->m_Length())){
        continue;
      }
      f2.l_builder->m_Link();
    }
  }
}

void g_mx2cc_MakeApp(bbArray<bbString>* l_args){
  struct f0_t : public bbGCFrame{
    bbArray<bbString>* l_args{};
    t_mx2_Builder* l_builder{};
    t_mx2_BuildOpts* l_opts{};
    f0_t(bbArray<bbString>* l_args):l_args(l_args){
    }
    void gcMark(){
      bbGCMarkPtr(l_args);
      bbGCMarkPtr(l_builder);
      bbGCMarkPtr(l_opts);
    }
  }f0{l_args};
  f0.l_opts=bbGCNew<t_mx2_BuildOpts>();
  f0.l_opts->m_productType=BB_T("app");
  f0.l_opts->m_appType=BB_T("gui");
  f0.l_opts->m_target=BB_T("desktop");
  f0.l_opts->m_config=BB_T("debug");
  f0.l_opts->m_clean=false;
  f0.l_opts->m_fast=true;
  f0.l_opts->m_run=true;
  f0.l_opts->m_verbose=bbInt(0);
  f0.l_args=g_mx2cc_ParseOpts(f0.l_opts,f0.l_args);
  if((f0.l_args->length()!=1)){
    g_mx2cc_Fail(BB_T("Invalid app source file"));
  }
  bbString l_cd=g_std_filesystem_CurrentDir();
  g_std_filesystem_ChangeDir(g_mx2cc_StartDir);
  bbString l_srcPath=g_std_filesystem_RealPath(f0.l_args->at(bbInt(0)).replace(BB_T("\\"),BB_T("/")));
  g_std_filesystem_ChangeDir(l_cd);
  f0.l_opts->m_mainSource=l_srcPath;
  puts(bbString{}.c_str());fflush( stdout );
  puts(((BB_T("***** Building app '")+f0.l_opts->m_mainSource)+BB_T("' *****")).c_str());fflush( stdout );
  puts(bbString{}.c_str());fflush( stdout );
  f0.l_builder=bbGCNew<t_mx2_Builder>(f0.l_opts);
  f0.l_builder->m_Parse();
  if(bbBool(f0.l_builder->m_errors->m_Length())){
    return;
  }
  f0.l_builder->m_Semant();
  if(bbBool(f0.l_builder->m_errors->m_Length())){
    return;
  }
  f0.l_builder->m_Translate();
  if(bbBool(f0.l_builder->m_errors->m_Length())){
    return;
  }
  f0.l_builder->m_Compile();
  if(bbBool(f0.l_builder->m_errors->m_Length())){
    return;
  }
  bbString l_app=f0.l_builder->m_Link();
  if(bbBool(f0.l_builder->m_errors->m_Length())){
    return;
  }
  if(!f0.l_opts->m_run){
    puts((BB_T("Application built:")+l_app).c_str());fflush( stdout );
  }
}

void bbMain(){
  static bool done;
  if(done) return;
  done=true;
  void mx2_std_main();mx2_std_main();
  struct f0_t : public bbGCFrame{
    bbArray<bbString>* l_args{};
    void gcMark(){
      bbGCMarkPtr(l_args);
    }
  }f0{};
  puts((BB_T("mx2cc version ")+g_mx2_MX2CC_0VERSION).c_str());fflush( stdout );
  g_mx2cc_StartDir=g_std_filesystem_CurrentDir();
  g_std_filesystem_ChangeDir(bbFileSystem::appDir());
  bbString l_env=((BB_T("bin/env_")+g_mx2_HostOS)+BB_T(".txt"));
  while((!g_std_filesystem_IsRootDir(g_std_filesystem_CurrentDir())&&(g_std_filesystem_GetFileType(l_env)!=g_std_filesystem_FILETYPE_0FILE))){
    g_std_filesystem_ChangeDir(g_std_filesystem_ExtractDir(g_std_filesystem_CurrentDir()));
  }
  if((g_std_filesystem_GetFileType(l_env)!=g_std_filesystem_FILETYPE_0FILE)){
    g_mx2cc_Fail(BB_T("Unable to locate mx2cc 'bin' directory"));
  }
  g_mx2cc_LoadEnv(l_env);
  f0.l_args=bbFileSystem::appArgs();
  if((f0.l_args->length()<2)){
    puts(BB_T("Usage: mx2cc makeapp|makemods|makedocs [-run] [-clean] [-verbose] [-target=desktop|emscripten] [-config=debug|release] source|modules...").c_str());fflush( stdout );
    exit(bbInt(0));
    f0.l_args=g_mx2cc_TestArgs.split(BB_T(" "));
  }
  try{
    bbString l_cmd=f0.l_args->at(1);
    f0.l_args=f0.l_args->slice(2);
    if(l_cmd==BB_T("makeapp")){
      g_mx2cc_MakeApp(f0.l_args);
    }else if(l_cmd==BB_T("makemods")){
      g_mx2cc_MakeMods(f0.l_args);
    }else if(l_cmd==BB_T("makedocs")){
      g_mx2cc_MakeDocs(f0.l_args);
    }else{
      g_mx2cc_Fail(((BB_T("Unrecognized mx2cc command: '")+l_cmd)+BB_T("'")));
    }
  }catch(t_mx2_BuildEx* ex){
    struct f1_t : public bbGCFrame{
      t_mx2_BuildEx* l_ex{};
      void gcMark(){
        bbGCMarkPtr(l_ex);
      }
    }f1{};
    f1.l_ex=ex;
    g_mx2cc_Fail(BB_T("Build error."));
  }
}

void mx2_mx2cc_mx2cc_init(){
  static bool done;
  if(done) return;
  done=true;
  g_mx2cc_TestArgs=BB_T("mx2cc makedocs monkey std mojo");
}

bbInit mx2_mx2cc_mx2cc_init_v("mx2cc_mx2cc",&mx2_mx2cc_mx2cc_init);
