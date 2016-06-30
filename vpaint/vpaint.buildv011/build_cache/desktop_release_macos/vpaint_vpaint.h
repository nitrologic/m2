
#ifndef MX2_VPAINT_VPAINT_H
#define MX2_VPAINT_VPAINT_H

#include <bbmonkey.h>

// ***** External *****

#include "../../../../../../monkey2/modules/mojo/mojo.buildv011/desktop_release_macos/mojo_app_2window.h"
#include "../../../../../../monkey2/modules/mojo/mojo.buildv011/desktop_release_macos/mojo_graphics_2image.h"
#include "../../../../../../monkey2/modules/monkey/monkey.buildv011/desktop_release_macos/monkey_types.h"
#include "../../../../../../monkey2/modules/std/std.buildv011/desktop_release_macos/std_geom_2vec2.h"
#include "../../../../../../monkey2/modules/std/std.buildv011/desktop_release_macos/std_graphics_2color.h"

struct t_mojo_app_AppInstance;
struct t_std_graphics_Pixmap;
struct t_mojo_graphics_Canvas;
struct t_mojo_audio_Sound;
struct t_mojo_audio_Channel;
struct t_mojo_app_MouseEvent;
struct t_mojo_app_KeyEvent;

// ***** Internal *****

struct t_default_VPane;
struct t_default_VBrowse;
struct t_default_VToolbar;
struct t_default_VPaint;

extern bbString g_default_title;
extern bbString g_default_AboutApp;
extern bbString g_default_Contact;
extern bbString g_default_Credits;
extern bbGCRootVar<t_mojo_app_AppInstance> g_default_instance;
extern bbString g_default_TickMark;

extern bbArray<bbFloat>* g_default_VPane_Curve(bbInt l_seg,t_std_geom_Vec2_1f l_p0,t_std_geom_Vec2_1f l_p1,t_std_geom_Vec2_1f l_p2,t_std_geom_Vec2_1f l_p3);
extern bbFloat g_default_VPane_CubicInterpolate2(bbFloat l_p0,bbFloat l_p1,bbFloat l_p2,bbFloat l_p3,bbFloat l_x);
extern bbFloat g_default_VPane_CubicInterpolate(bbFloat l_y0,bbFloat l_y1,bbFloat l_y2,bbFloat l_y3,bbFloat l_mu);
extern bbFloat g_default_VPane_CatmullInterpolate(bbFloat l_y0,bbFloat l_y1,bbFloat l_y2,bbFloat l_y3,bbFloat l_mu);
extern void g_default_SaveTGA(bbString l_path,t_std_graphics_Pixmap* l_pixmap);
extern void bbMain();

struct t_default_VPane : public t_mojo_graphics_Image{

  const char *typeName()const{return "t_default_VPane";}

  bbGCVar<t_mojo_graphics_Canvas> m_canvas{};
  bbGCVar<t_std_graphics_Pixmap> m_pixmap{};
  bbInt m_segcount{};
  t_std_geom_Vec2_1f m_edge0{};
  t_std_geom_Vec2_1f m_edge1{};

  void gcMark();

  t_default_VPane(bbInt l_w,bbInt l_h,t_std_graphics_Color l_bg);

  void m_StraightLine(bbInt l_x,bbInt l_y,bbInt l_x1,bbInt l_y1,bbFloat l_fat);
  void m_Smile(bbFloat l_x,bbFloat l_y,bbFloat l_r);
  void m_OpenCurve(t_std_geom_Vec2_1f l_p0,t_std_geom_Vec2_1f l_p1,t_std_geom_Vec2_1f l_p2,t_std_geom_Vec2_1f l_p3,bbFloat l_fat);
  void m_FatSegment(bbFloat l_x,bbFloat l_y,bbFloat l_x1,bbFloat l_y1,bbFloat l_fat);
  void m_EndSegment();
  void m_Draw(t_mojo_graphics_Canvas* l_display);
  void m_ClosedCurve(t_std_geom_Vec2_1f l_p0,t_std_geom_Vec2_1f l_p1,t_std_geom_Vec2_1f l_p2,t_std_geom_Vec2_1f l_p3,bbFloat l_fat);
  void m_Clear(t_std_graphics_Color l_bg);
  void m_Circle(bbFloat l_x,bbFloat l_y,bbFloat l_r);

  t_default_VPane(){
  }
};

struct t_default_VBrowse : public bbObject{

  const char *typeName()const{return "t_default_VBrowse";}

  t_default_VBrowse(){
  }
};

struct t_default_VToolbar : public t_mojo_app_Window{

  const char *typeName()const{return "t_default_VToolbar";}

  t_default_VToolbar(bbString l_title);

  t_default_VToolbar(){
  }
};

struct t_default_VPaint : public t_mojo_app_Window{

  const char *typeName()const{return "t_default_VPaint";}

  bbInt m_appState{};
  bbGCVar<t_default_VPane> m_pane{};
  bbGCVar<t_default_VBrowse> m_browse{};
  bbString m_status{};
  bbFloat m_zoom{};
  t_std_graphics_Color m_ink{};
  bbInt m_mousex{};
  bbInt m_mousey{};
  bbInt m_mousew{};
  bbInt m_framecount{};
  bbInt m_drawcount{};
  bbInt m_mousecount{};
  bbFloat m_cx{};
  bbFloat m_cy{};
  bbFloat m_rot{};
  bbFloat m_rotSpeed{};
  bbFloat m_radius{};
  bbInt m_tool=1;
  bbFloat m_panx{};
  bbFloat m_pany{};
  bbFloat m_panxSpeed{};
  bbFloat m_panySpeed{};
  bbGCVar<t_mojo_audio_Sound> m_sample{};
  bbGCVar<t_mojo_audio_Channel> m_wheel{};
  bbInt m_statusCount{};
  bbInt m_CommandKey=3072;
  bbGCVar<bbArray<t_std_geom_Vec2_1f>> m_history{};
  bbGCVar<t_mojo_app_MouseEvent> m_recentMouseEvent{};

  void init();

  void gcMark();

  t_default_VPaint(bbString l_title);

  void m_ToggleTwo();
  void m_RefreshStatus();
  void m_OnRender(t_mojo_graphics_Canvas* l_display);
  void m_OnMouseEvent(t_mojo_app_MouseEvent* l_event);
  void m_OnKeyEvent(t_mojo_app_KeyEvent* l_event);
  void m_Hold();
  void m_DrawMode();

  t_default_VPaint(){
    init();
  }
};

#endif
