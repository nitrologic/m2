
#include "listimports_listimports.h"

// ***** External *****

#include "../../../../../../monkey2/modules/monkey/monkey.buildv010/desktop_release_macos/monkey_types.h"
#include "../../../../../../monkey2/modules/std/std.buildv010/desktop_release_macos/std_collections_2list.h"

extern void g_std_filesystem_ChangeDir(bbString l_path);
extern bbArray<bbString>* g_std_filesystem_LoadDir(bbString l_path);
extern bbInt g_std_filesystem_GetFileType(bbString l_path);
extern bbString g_std_stringio_LoadString(bbString l_path);

// ***** Internal *****

void bbMain(){
  static bool done;
  if(done) return;
  done=true;
  void mx2_std_main();mx2_std_main();
  puts(BB_T("ListImports v0.01").c_str());fflush( stdout );
  g_std_filesystem_ChangeDir(BB_T("/Users/simon/monkey2/modules/box2d"));
  g_default_ListHeaders(BB_T("."),BB_T(".h"));
}

void g_default_ListImports(bbString l_filepath,bbString l_ext){
  struct f0_t : public bbGCFrame{
    bbArray<bbString>* l_files{};
    void gcMark(){
      bbGCMark(l_files);
    }
  }f0{};
  f0.l_files=g_std_filesystem_LoadDir(l_filepath);
  {
    bbInt l_0=bbInt(0);
    bbInt l_1=f0.l_files->length();
    for(;(l_0<l_1);l_0+=1){
      bbString l_file=f0.l_files->at(l_0);
      bbString l_path=((l_filepath+BB_T("/"))+l_file);
      bbInt l_2=g_std_filesystem_GetFileType(l_path);
      if(l_2==1){
        if(l_file.endsWith(l_ext)){
          bbString l_subpath=l_path.slice(2);
          puts(((BB_T("#Import \"")+l_subpath)+BB_T("\"")).c_str());fflush( stdout );
        }
      }else if(l_2==2){
        g_default_ListImports(l_path,l_ext);
      }
    }
  }
}

void g_default_ListHeaders(bbString l_filepath,bbString l_ext){
  struct f0_t : public bbGCFrame{
    bbArray<bbString>* l_files{};
    void gcMark(){
      bbGCMark(l_files);
    }
  }f0{};
  f0.l_files=g_std_filesystem_LoadDir(l_filepath);
  {
    bbInt l_0=bbInt(0);
    bbInt l_1=f0.l_files->length();
    for(;(l_0<l_1);l_0+=1){
      bbString l_file=f0.l_files->at(l_0);
      bbString l_path=((l_filepath+BB_T("/"))+l_file);
      bbInt l_2=g_std_filesystem_GetFileType(l_path);
      if(l_2==1){
        if(l_file.endsWith(l_ext)){
          g_default_DecodeCHeader(l_path);
        }
      }else if(l_2==2){
        g_default_ListHeaders(l_path,l_ext);
      }
    }
  }
}

void g_default_DecodeCHeader(bbString l_path){
  bbString l_header=g_std_stringio_LoadString(l_path);
  bbInt l_inclass=bbInt(0);
  bbBool l_isPublic=false;
  {
    struct f1_t : public bbGCFrame{
      bbArray<bbString>* l_0{};
      void gcMark(){
        bbGCMark(l_0);
      }
    }f1{};
    f1.l_0=l_header.split(BB_T("\r\n"));
    bbInt l_1=bbInt(0);
    bbInt l_2=f1.l_0->length();
    for(;(l_1<l_2);l_1+=1){
      bbString l_line=f1.l_0->at(l_1);
      if((l_line.startsWith(BB_T("class "))&&!l_line.endsWith(BB_T(";")))){
        l_line=l_line.replace(BB_T(": public"),BB_T("extends"));
        puts(l_line.c_str());fflush( stdout );
        l_inclass=1;
        continue;
      }
      if((l_line.startsWith(BB_T("struct "))&&!l_line.endsWith(BB_T(";")))){
        l_line=l_line.replace(BB_T(": public"),BB_T("extends"));
        puts(l_line.c_str());fflush( stdout );
        l_inclass=1;
        continue;
      }
      if((l_line.startsWith(BB_T("};"))&&bbBool(l_inclass))){
        l_inclass-=1;
        if((l_inclass==1)){
          puts(BB_T("end\n").c_str());fflush( stdout );
          l_inclass=bbInt(0);
        }
      }
      bbInt l_semi=l_line.find(BB_T(";"),bbInt(0));
      if((l_semi>bbInt(0))){
        l_line=l_line.slice(bbInt(0),l_semi);
      }
      l_line=l_line.trim();
      l_line=l_line.replace(BB_T("const "),bbString{});
      l_line=l_line.replace(BB_T(" const"),bbString{});
      if((l_line==BB_T("{"))){
        l_inclass+=1;
        continue;
      }
      if((l_line==BB_T("}"))){
        l_inclass-=1;
        continue;
      }
      if(((l_inclass==2)&&bbBool(l_line.length()))){
        if(l_line.startsWith(BB_T("///"))){
          continue;
        }
        if(l_line.startsWith(BB_T("#"))){
          continue;
        }
        if((l_line==BB_T("public:"))){
          continue;
        }
        if(l_line.startsWith(BB_T("virtual "))){
          l_line=l_line.slice(8);
        }
        bbInt l_s=l_line.find(BB_T(" "),bbInt(0));
        bbInt l_b0=l_line.find(BB_T("("),bbInt(0));
        bbInt l_b1=l_line.find(BB_T(")"),bbInt(0));
        if((l_b0>bbInt(0))){
          if((l_s>bbInt(0))){
            struct f5_t : public bbGCFrame{
              t_std_collections_List_1s* l_args{};
              void gcMark(){
                bbGCMark(l_args);
              }
            }f5{};
            bbString l_t=l_line.slice(bbInt(0),l_s);
            bbString l_f=l_line.slice((l_s+1),l_b0);
            if((l_t==BB_T("int32"))){
              l_t=BB_T("Int");
            }
            if((l_t==BB_T("float32"))){
              l_t=BB_T("Float");
            }
            l_t=l_t.replace(BB_T("*"),bbString{});
            if((l_t==BB_T("void"))){
              l_t=bbString{};
            }else{
              l_t=(BB_T(":")+l_t);
            }
            f5.l_args=bbGCNew<t_std_collections_List_1s>();
            bbString l_b=l_line.slice((l_b0+1),l_b1);
            {
              struct f6_t : public bbGCFrame{
                bbArray<bbString>* l_3{};
                void gcMark(){
                  bbGCMark(l_3);
                }
              }f6{};
              f6.l_3=l_b.split(BB_T(","));
              bbInt l_4=bbInt(0);
              bbInt l_5=f6.l_3->length();
              for(;(l_4<l_5);l_4+=1){
                bbString l_a=f6.l_3->at(l_4);
                l_a=l_a.trim();
                if((l_a==bbString{})){
                  continue;
                }
                bbInt l_p=l_a.find(BB_T(" "),bbInt(0));
                bbString l_c=l_a.slice(bbInt(0),l_p);
                bbString l_n=l_a.slice((l_p+1));
                l_c=l_c.replace(BB_T("*"),bbString{});
                l_c=l_c.replace(BB_T("&"),bbString{});
                if((l_c==BB_T("uint8"))){
                  l_c=BB_T("Byte");
                }
                if((l_c==BB_T("int32"))){
                  l_c=BB_T("Int");
                }
                if((l_c==BB_T("float32"))){
                  l_c=BB_T("Float");
                }
                f5.l_args->m_AddLast(((l_n+BB_T(":"))+l_c));
              }
            }
            puts((((((BB_T("\tMethod ")+l_f)+l_t)+BB_T("("))+f5.l_args->m_Join(BB_T(",")))+BB_T(")")).c_str());fflush( stdout );
          }
        }else{
          if((l_s>bbInt(0))){
            bbString l_t=l_line.slice(bbInt(0),l_s);
            bbString l_f=l_line.slice((l_s+1));
            l_t=l_t.replace(BB_T("*"),bbString{});
            if((l_t==BB_T("uint8"))){
              l_t=BB_T("Byte");
            }
            if((l_t==BB_T("int32"))){
              l_t=BB_T("Int");
            }
            if((l_t==BB_T("float32"))){
              l_t=BB_T("Float");
            }
            if((l_t==BB_T("void"))){
              l_t=bbString{};
            }else{
              l_t=(BB_T(":")+l_t);
            }
            puts(((BB_T("\tField ")+l_f)+l_t).c_str());fflush( stdout );
          }
        }
      }
    }
  }
}

void mx2_listimports_listimports_init(){
  static bool done;
  if(done) return;
  done=true;
}

bbInit mx2_listimports_listimports_init_v("listimports_listimports",&mx2_listimports_listimports_init);
