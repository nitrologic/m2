
#include "gif_gif.h"

// ***** External *****

#include "../../../../../../monkey2/modules/std/std.buildv010/desktop_debug_macos/std_graphics_2pixmap.h"

// ***** Internal *****

void bbMain(){
  static bool done;
  if(done) return;
  done=true;
  void mx2_mojo_main();mx2_mojo_main();
  void mx2_std_main();mx2_std_main();
  struct f0_t : public bbGCFrame{
    t_std_graphics_Pixmap* l_pix{};
    void gcMark(){
      bbGCMark(l_pix);
    }
  }f0{};
  bbDBFrame db_f{"Main:Void()","/Users/simon/nitrologic/m2/gif64/gif.monkey2"};
  bbDBStmt(114689);
  puts(BB_T("gif tool").c_str());fflush( stdout );
  bbDBStmt(122887);
  f0.l_pix=bbGCNew<t_std_graphics_Pixmap>(256,256,5);
  bbDBLocal("pix",&f0.l_pix);
  bbDBStmt(131073);
  g_default_SaveGIF(f0.l_pix,BB_T("walk32.gif"));
}

void g_default_SaveGIF(t_std_graphics_Pixmap* l_pix,bbString l_filename){
  bbDBFrame db_f{"SaveGIF:Void(pix:std.graphics.Pixmap,filename:String)","/Users/simon/nitrologic/m2/gif64/gif.monkey2"};
  bbDBLocal("pix",&l_pix);
  bbDBLocal("filename",&l_filename);
  bbDBStmt(94209);
  GIFWrite_(bbCString(l_filename),((GIFStream*)0),bbInt(0));
}

void t_default_GifStream::dbEmit(){
  GIFStream::dbEmit();
}
bbString bbDBType(t_default_GifStream**){
  return "default.GifStream";
}
bbString bbDBValue(t_default_GifStream**p){
  return bbDBObjectValue(*p);
}

void mx2_gif_gif_init(){
  static bool done;
  if(done) return;
  done=true;
}

bbInit mx2_gif_gif_init_v("gif_gif",&mx2_gif_gif_init);
