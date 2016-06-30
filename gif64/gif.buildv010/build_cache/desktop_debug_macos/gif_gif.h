
#ifndef MX2_GIF_GIF_H
#define MX2_GIF_GIF_H

#include <bbmonkey.h>

// ***** External *****

#include "../../../../../../monkey2/modules/monkey/monkey.buildv010/desktop_debug_macos/monkey_types.h"

struct t_std_graphics_Pixmap;
bbString bbDBType(t_std_graphics_Pixmap**);
bbString bbDBValue(t_std_graphics_Pixmap**);

// ***** Internal *****

struct t_default_GifStream;

extern void bbMain();
extern void g_default_SaveGIF(t_std_graphics_Pixmap* l_pix,bbString l_filename);

struct GIFStream : public bbObject{

  const char *typeName()const{return "GIFStream";}

  void dbEmit();

  GIFStream(){
  }
};
bbString bbDBType(GIFStream**);
bbString bbDBValue(GIFStream**);
struct t_default_GifStream : public GIFStream{

  const char *typeName()const{return "t_default_GifStream";}

  void dbEmit();

  t_default_GifStream(){
  }
};
bbString bbDBType(t_default_GifStream**);
bbString bbDBValue(t_default_GifStream**);

#endif
