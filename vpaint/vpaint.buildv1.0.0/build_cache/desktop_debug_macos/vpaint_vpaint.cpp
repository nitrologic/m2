
#include "vpaint_vpaint.h"

// ***** External *****

#include "../../../../../../monkey2/modules/mojo/mojo.buildv1.0.0/desktop_debug_macos/mojo_app_2app.h"
#include "../../../../../../monkey2/modules/mojo/mojo.buildv1.0.0/desktop_debug_macos/mojo_app_2event.h"
#include "../../../../../../monkey2/modules/mojo/mojo.buildv1.0.0/desktop_debug_macos/mojo_app_2view.h"
#include "../../../../../../monkey2/modules/mojo/mojo.buildv1.0.0/desktop_debug_macos/mojo_audio_2audio.h"
#include "../../../../../../monkey2/modules/mojo/mojo.buildv1.0.0/desktop_debug_macos/mojo_graphics_2canvas.h"
#include "../../../../../../monkey2/modules/monkey/monkey.buildv1.0.0/desktop_debug_macos/monkey_math.h"
#include "../../../../../../monkey2/modules/portmidi/portmidi.buildv1.0.0/desktop_debug_macos/portmidi_portmidi.h"
#include "../../../../../../monkey2/modules/sdl2/sdl2.buildv1.0.0/desktop_debug_macos/sdl2_sdl2.h"
#include "../../../../../../monkey2/modules/std/std.buildv1.0.0/desktop_debug_macos/std_collections_2stack.h"
#include "../../../../../../monkey2/modules/std/std.buildv1.0.0/desktop_debug_macos/std_graphics_2pixmap.h"
#include "../../../../../../monkey2/modules/std/std.buildv1.0.0/desktop_debug_macos/std_stream_2filestream.h"

extern bbDouble g_monkey_math_Abs_1d(bbDouble l_x);

// ***** Internal *****

bbString g_default_title;
bbString g_default_AboutApp;
bbString g_default_Contact;
bbString g_default_Credits;
bbGCRootVar<t_mojo_app_AppInstance> g_default_instance;
bbString g_default_TickMark;
t_std_graphics_Color g_default_VPaint_Transparent;

bbArray<bbFloat>* g_default_VPane_Curve(bbInt l_seg,t_std_geom_Vec2_1f l_p0,t_std_geom_Vec2_1f l_p1,t_std_geom_Vec2_1f l_p2,t_std_geom_Vec2_1f l_p3){
  struct f0_t : public bbGCFrame{
    bbArray<bbFloat>* l_verts{};
    void gcMark(){
      bbGCMarkPtr(l_verts);
    }
  }f0{};
  bbDBFrame db_f{"Curve:Float[](seg:Int,p0:Vec2f:std.geom.Vec2<Float>,p1:Vec2f:std.geom.Vec2<Float>,p2:Vec2f:std.geom.Vec2<Float>,p3:Vec2f:std.geom.Vec2<Float>)","/Users/simon/nitrologic/m2/vpaint/vpaint.monkey2"};
  bbDBLocal("seg",&l_seg);
  bbDBLocal("p0",&l_p0);
  bbDBLocal("p1",&l_p1);
  bbDBLocal("p2",&l_p2);
  bbDBLocal("p3",&l_p3);
  bbDBStmt(339976);
  f0.l_verts=bbArray<bbFloat>::create(((l_seg+1)*2));
  bbDBLocal("verts",&f0.l_verts);
  bbDBStmt(344066);
  {
    bbDBLoop db_loop;
    bbInt l_i=bbInt(0);
    bbDBLocal("i",&l_i);
    bbDBStmt(344066);
    for(;(l_i<=l_seg);l_i+=1){
      bbDBBlock db_blk;
      bbDBStmt(348169);
      bbFloat l_mu=((bbFloat(l_i)*1.0f)/bbFloat(l_seg));
      bbDBLocal("mu",&l_mu);
      bbDBStmt(352271);
      bbFloat l_x=g_default_VPane_CatmullInterpolate(l_p0.m_x,l_p1.m_x,l_p2.m_x,l_p3.m_x,l_mu);
      bbDBLocal("x",&l_x);
      bbDBStmt(356367);
      bbFloat l_y=g_default_VPane_CatmullInterpolate(l_p0.m_y,l_p1.m_y,l_p2.m_y,l_p3.m_y,l_mu);
      bbDBLocal("y",&l_y);
      bbDBStmt(360459);
      f0.l_verts->at(((l_i*2)+bbInt(0)))=l_x;
      bbDBStmt(364553);
      f0.l_verts->at(((l_i*2)+1))=l_y;
    }
  }
  bbDBStmt(372738);
  return f0.l_verts;
}

bbFloat g_default_VPane_CubicInterpolate2(bbFloat l_p0,bbFloat l_p1,bbFloat l_p2,bbFloat l_p3,bbFloat l_x){
  bbDBFrame db_f{"CubicInterpolate2:Float(p0:Float,p1:Float,p2:Float,p3:Float,x:Float)","/Users/simon/nitrologic/m2/vpaint/vpaint.monkey2"};
  bbDBLocal("p0",&l_p0);
  bbDBLocal("p1",&l_p1);
  bbDBLocal("p2",&l_p2);
  bbDBLocal("p3",&l_p3);
  bbDBLocal("x",&l_x);
  bbDBStmt(544770);
  return (l_p1+((0.5f*l_x)*((l_p2-l_p0)+(l_x*(((((2.0f*l_p0)-(5.0f*l_p1))+(4.0f*l_p2))-l_p3)+(l_x*(((3.0f*(l_p1-l_p2))+l_p3)-l_p0)))))));
}

bbFloat g_default_VPane_CubicInterpolate(bbFloat l_y0,bbFloat l_y1,bbFloat l_y2,bbFloat l_y3,bbFloat l_mu){
  bbDBFrame db_f{"CubicInterpolate:Float(y0:Float,y1:Float,y2:Float,y3:Float,mu:Float)","/Users/simon/nitrologic/m2/vpaint/vpaint.monkey2"};
  bbDBLocal("y0",&l_y0);
  bbDBLocal("y1",&l_y1);
  bbDBLocal("y2",&l_y2);
  bbDBLocal("y3",&l_y3);
  bbDBLocal("mu",&l_mu);
  bbDBStmt(462856);
  bbFloat l_a0{};
  bbDBLocal("a0",&l_a0);
  bbDBStmt(462865);
  bbFloat l_a1{};
  bbDBLocal("a1",&l_a1);
  bbDBStmt(462874);
  bbFloat l_a2{};
  bbDBLocal("a2",&l_a2);
  bbDBStmt(462883);
  bbFloat l_a3{};
  bbDBLocal("a3",&l_a3);
  bbDBStmt(462892);
  bbFloat l_mu2{};
  bbDBLocal("mu2",&l_mu2);
  bbDBStmt(466946);
  l_mu2=(l_mu*l_mu);
  bbDBStmt(471042);
  l_a0=(((l_y3-l_y2)-l_y0)+l_y1);
  bbDBStmt(475138);
  l_a1=((l_y0-l_y1)-l_a0);
  bbDBStmt(479234);
  l_a2=(l_y2-l_y0);
  bbDBStmt(483330);
  l_a3=l_y1;
  bbDBStmt(487426);
  return (((((l_a0*l_mu)*l_mu2)+(l_a1*l_mu2))+(l_a2*l_mu))+l_a3);
}

bbFloat g_default_VPane_CatmullInterpolate(bbFloat l_y0,bbFloat l_y1,bbFloat l_y2,bbFloat l_y3,bbFloat l_mu){
  bbDBFrame db_f{"CatmullInterpolate:Float(y0:Float,y1:Float,y2:Float,y3:Float,mu:Float)","/Users/simon/nitrologic/m2/vpaint/vpaint.monkey2"};
  bbDBLocal("y0",&l_y0);
  bbDBLocal("y1",&l_y1);
  bbDBLocal("y2",&l_y2);
  bbDBLocal("y3",&l_y3);
  bbDBLocal("mu",&l_mu);
  bbDBStmt(503816);
  bbFloat l_a0{};
  bbDBLocal("a0",&l_a0);
  bbDBStmt(503825);
  bbFloat l_a1{};
  bbDBLocal("a1",&l_a1);
  bbDBStmt(503834);
  bbFloat l_a2{};
  bbDBLocal("a2",&l_a2);
  bbDBStmt(503843);
  bbFloat l_a3{};
  bbDBLocal("a3",&l_a3);
  bbDBStmt(503852);
  bbFloat l_mu2{};
  bbDBLocal("mu2",&l_mu2);
  bbDBStmt(507906);
  l_mu2=(l_mu*l_mu);
  bbDBStmt(512002);
  l_a0=((((-0.5f*l_y0)+(1.5f*l_y1))-(1.5f*l_y2))+(0.5f*l_y3));
  bbDBStmt(516098);
  l_a1=(((l_y0-(2.5f*l_y1))+(2.0f*l_y2))-(0.5f*l_y3));
  bbDBStmt(520194);
  l_a2=((-0.5f*l_y0)+(0.5f*l_y2));
  bbDBStmt(524290);
  l_a3=l_y1;
  bbDBStmt(528386);
  return (((((l_a0*l_mu)*l_mu2)+(l_a1*l_mu2))+(l_a2*l_mu))+l_a3);
}

void g_default_SaveTGA(bbString l_path,t_std_graphics_Pixmap* l_pixmap){
  struct f0_t : public bbGCFrame{
    bbArray<bbByte>* l_buffer{};
    t_std_stream_FileStream* l_stream{};
    void gcMark(){
      bbGCMarkPtr(l_buffer);
      bbGCMarkPtr(l_stream);
    }
  }f0{};
  bbDBFrame db_f{"SaveTGA:Void(path:String,pixmap:std.graphics.Pixmap)","/Users/simon/nitrologic/m2/vpaint/vpaint.monkey2"};
  bbDBLocal("path",&l_path);
  bbDBLocal("pixmap",&l_pixmap);
  bbDBStmt(2244615);
  f0.l_stream=g_std_stream_FileStream_Open(l_path,BB_T("w"));
  bbDBLocal("stream",&f0.l_stream);
  bbDBStmt(2248711);
  f0.l_buffer=bbArray<bbByte>::create(18);
  bbDBLocal("buffer",&f0.l_buffer);
  bbDBStmt(2252807);
  bbInt l_w=l_pixmap->m_Width();
  bbDBLocal("w",&l_w);
  bbDBStmt(2256903);
  bbInt l_h=l_pixmap->m_Height();
  bbDBLocal("h",&l_h);
  bbDBStmt(2260993);
  f0.l_buffer->at(2)=2;
  bbDBStmt(2265089);
  f0.l_buffer->at(12)=bbByte((l_w&255));
  bbDBStmt(2269185);
  f0.l_buffer->at(13)=bbByte((l_w>>8));
  bbDBStmt(2273281);
  f0.l_buffer->at(14)=bbByte((l_h&255));
  bbDBStmt(2277377);
  f0.l_buffer->at(15)=bbByte((l_h>>8));
  bbDBStmt(2281473);
  f0.l_buffer->at(16)=32;
  bbDBStmt(2285569);
  f0.l_buffer->at(17)=8;
  bbDBStmt(2289665);
  f0.l_stream->m_Write(((void*)(&f0.l_buffer->at(bbInt(0)))),18);
  bbDBStmt(2293761);
  f0.l_stream->m_Write(((void*)(l_pixmap->m_Data())),((l_w*l_h)*4));
  bbDBStmt(2297857);
  f0.l_stream->m_Close();
}

void bbMain(){
  static bool done;
  if(done) return;
  done=true;
  void mx2_mojo_main();mx2_mojo_main();
  void mx2_std_main();mx2_std_main();
  bbDBFrame db_f{"Main:Void()","/Users/simon/nitrologic/m2/vpaint/vpaint.monkey2"};
  bbDBStmt(2215937);
  puts(g_default_title.c_str());fflush( stdout );
  bbDBStmt(2220033);
  g_default_instance=bbGCNew<t_mojo_app_AppInstance>();
  bbDBStmt(2224129);
  bbGCNew<t_default_VPaint>(g_default_title);
  bbDBStmt(2228225);
  g_mojo_app_App->m_Run();
}

void t_default_VPane::gcMark(){
  t_mojo_graphics_Image::gcMark();
  bbGCMark(m_canvas);
  bbGCMark(m_pixmap);
}

void t_default_VPane::dbEmit(){
  t_mojo_graphics_Image::dbEmit();
  bbDBEmit("canvas",&m_canvas);
  bbDBEmit("pixmap",&m_pixmap);
  bbDBEmit("segcount",&m_segcount);
  bbDBEmit("edge0",&m_edge0);
  bbDBEmit("edge1",&m_edge1);
}

t_default_VPane::t_default_VPane(bbInt l_w,bbInt l_h,t_std_graphics_Color l_bg):t_mojo_graphics_Image(l_w,l_h,4099,((t_mojo_graphics_Shader*)0)){
  bbDBFrame db_f{"new:Void(w:Int,h:Int,bg:std.graphics.Color)","/Users/simon/nitrologic/m2/vpaint/vpaint.monkey2"};
  bbDBLocal("w",&l_w);
  bbDBLocal("h",&l_h);
  bbDBLocal("bg",&l_bg);
  bbDBStmt(114690);
  this->m_canvas=bbGCNew<t_mojo_graphics_Canvas>(((t_mojo_graphics_Image*)(this)));
  bbDBStmt(118786);
  this->m_canvas->m_Clear(l_bg);
  bbDBStmt(122882);
  this->m_canvas->m_Alpha(0.8f);
  bbDBStmt(126978);
  this->m_canvas->m_Translate(bbFloat((l_w/2)),bbFloat((l_h/2)));
  bbDBStmt(131074);
  this->m_Handle(t_std_geom_Vec2_1f(0.5f,0.5f));
}

void t_default_VPane::m_StraightLine(bbInt l_x,bbInt l_y,bbInt l_x1,bbInt l_y1,bbFloat l_fat){
  bbDBFrame db_f{"StraightLine:Void(x:Int,y:Int,x1:Int,y1:Int,fat:Float)","/Users/simon/nitrologic/m2/vpaint/vpaint.monkey2"};
  t_default_VPane*self=this;
  bbDBLocal("Self",&self);
  bbDBLocal("x",&l_x);
  bbDBLocal("y",&l_y);
  bbDBLocal("x1",&l_x1);
  bbDBLocal("y1",&l_y1);
  bbDBLocal("fat",&l_fat);
  bbDBStmt(561154);
  if(!bbBool(this->m_canvas)){
    bbDBBlock db_blk;
    bbDBStmt(561168);
    return;
  }
  bbDBStmt(565256);
  bbInt l_dy=(l_y1-l_y);
  bbDBLocal("dy",&l_dy);
  bbDBStmt(569352);
  bbInt l_dx=(l_x1-l_x);
  bbDBLocal("dx",&l_dx);
  bbDBStmt(573448);
  bbFloat l_len=bbFloat(std::sqrt(bbDouble(((l_dx*l_dx)+(l_dy*l_dy)))));
  bbDBLocal("len",&l_len);
  bbDBStmt(577544);
  bbFloat l_q=(l_fat/l_len);
  bbDBLocal("q",&l_q);
  bbDBStmt(581640);
  t_std_geom_Vec2_1f l_v0=t_std_geom_Vec2_1f((bbFloat(l_x)+(bbFloat(l_dy)*l_q)),(bbFloat(l_y)-(bbFloat(l_dx)*l_q)));
  bbDBLocal("v0",&l_v0);
  bbDBStmt(585736);
  t_std_geom_Vec2_1f l_v1=t_std_geom_Vec2_1f((bbFloat(l_x1)+(bbFloat(l_dy)*l_q)),(bbFloat(l_y1)-(bbFloat(l_dx)*l_q)));
  bbDBLocal("v1",&l_v1);
  bbDBStmt(589832);
  t_std_geom_Vec2_1f l_v2=t_std_geom_Vec2_1f((bbFloat(l_x1)-(bbFloat(l_dy)*l_q)),(bbFloat(l_y1)+(bbFloat(l_dx)*l_q)));
  bbDBLocal("v2",&l_v2);
  bbDBStmt(593928);
  t_std_geom_Vec2_1f l_v3=t_std_geom_Vec2_1f((bbFloat(l_x)-(bbFloat(l_dy)*l_q)),(bbFloat(l_y)+(bbFloat(l_dx)*l_q)));
  bbDBLocal("v3",&l_v3);
  bbDBStmt(598018);
  this->m_canvas->m_DrawTriangle(l_v0,l_v1,l_v2);
  bbDBStmt(602114);
  this->m_canvas->m_DrawTriangle(l_v0,l_v2,l_v3);
}

void t_default_VPane::m_Smile(bbFloat l_x,bbFloat l_y,bbFloat l_r){
  bbDBFrame db_f{"Smile:Void(x:Float,y:Float,r:Float)","/Users/simon/nitrologic/m2/vpaint/vpaint.monkey2"};
  t_default_VPane*self=this;
  bbDBLocal("Self",&self);
  bbDBLocal("x",&l_x);
  bbDBLocal("y",&l_y);
  bbDBLocal("r",&l_r);
  bbDBStmt(622600);
  t_std_geom_Vec2_1f l_v0=t_std_geom_Vec2_1f((l_x-100.0f),(l_y+100.0f));
  bbDBLocal("v0",&l_v0);
  bbDBStmt(626696);
  t_std_geom_Vec2_1f l_v1=t_std_geom_Vec2_1f((l_x-100.0f),(l_y-20.0f));
  bbDBLocal("v1",&l_v1);
  bbDBStmt(630792);
  t_std_geom_Vec2_1f l_v2=t_std_geom_Vec2_1f((l_x+100.0f),(l_y-20.0f));
  bbDBLocal("v2",&l_v2);
  bbDBStmt(634888);
  t_std_geom_Vec2_1f l_v3=t_std_geom_Vec2_1f((l_x+100.0f),(l_y+100.0f));
  bbDBLocal("v3",&l_v3);
  bbDBStmt(638978);
  this->m_EndSegment();
  bbDBStmt(643074);
  this->m_OpenCurve(l_v0,l_v1,l_v2,l_v3,l_r);
  bbDBStmt(647170);
  this->m_EndSegment();
}

void t_default_VPane::m_OpenCurve(t_std_geom_Vec2_1f l_p0,t_std_geom_Vec2_1f l_p1,t_std_geom_Vec2_1f l_p2,t_std_geom_Vec2_1f l_p3,bbFloat l_fat){
  struct f0_t : public bbGCFrame{
    bbArray<bbFloat>* l_verts{};
    void gcMark(){
      bbGCMarkPtr(l_verts);
    }
  }f0{};
  bbDBFrame db_f{"OpenCurve:Void(p0:Vec2f:std.geom.Vec2<Float>,p1:Vec2f:std.geom.Vec2<Float>,p2:Vec2f:std.geom.Vec2<Float>,p3:Vec2f:std.geom.Vec2<Float>,fat:Float)","/Users/simon/nitrologic/m2/vpaint/vpaint.monkey2"};
  t_default_VPane*self=this;
  bbDBLocal("Self",&self);
  bbDBLocal("p0",&l_p0);
  bbDBLocal("p1",&l_p1);
  bbDBLocal("p2",&l_p2);
  bbDBLocal("p3",&l_p3);
  bbDBLocal("fat",&l_fat);
  bbDBStmt(389122);
  if(!bbBool(this->m_canvas)){
    bbDBBlock db_blk;
    bbDBStmt(389136);
    return;
  }
  bbDBStmt(393224);
  bbInt l_seg=9;
  bbDBLocal("seg",&l_seg);
  bbDBStmt(397320);
  f0.l_verts=g_default_VPane_Curve(l_seg,l_p0,l_p1,l_p2,l_p3);
  bbDBLocal("verts",&f0.l_verts);
  bbDBStmt(401410);
  {
    bbDBLoop db_loop;
    bbInt l_i=bbInt(0);
    bbDBLocal("i",&l_i);
    bbDBStmt(401410);
    for(;(l_i<l_seg);l_i+=1){
      bbDBBlock db_blk;
      bbDBStmt(405507);
      this->m_FatSegment(f0.l_verts->at(((l_i*2)+bbInt(0))),f0.l_verts->at(((l_i*2)+1)),f0.l_verts->at(((l_i*2)+2)),f0.l_verts->at(((l_i*2)+3)),l_fat);
    }
  }
}

void t_default_VPane::m_FatSegment(bbFloat l_x,bbFloat l_y,bbFloat l_x1,bbFloat l_y1,bbFloat l_fat){
  struct f0_t : public bbGCFrame{
    bbArray<bbFloat>* l_verts{};
    void gcMark(){
      bbGCMarkPtr(l_verts);
    }
  }f0{};
  bbDBFrame db_f{"FatSegment:Void(x:Float,y:Float,x1:Float,y1:Float,fat:Float)","/Users/simon/nitrologic/m2/vpaint/vpaint.monkey2"};
  t_default_VPane*self=this;
  bbDBLocal("Self",&self);
  bbDBLocal("x",&l_x);
  bbDBLocal("y",&l_y);
  bbDBLocal("x1",&l_x1);
  bbDBLocal("y1",&l_y1);
  bbDBLocal("fat",&l_fat);
  bbDBStmt(221186);
  if(!bbBool(this->m_canvas)){
    bbDBBlock db_blk;
    bbDBStmt(221200);
    return;
  }
  bbDBStmt(229384);
  f0.l_verts=bbArray<bbFloat>::create(8);
  bbDBLocal("verts",&f0.l_verts);
  bbDBStmt(237576);
  bbFloat l_dy=(l_y1-l_y);
  bbDBLocal("dy",&l_dy);
  bbDBStmt(241672);
  bbFloat l_dx=(l_x1-l_x);
  bbDBLocal("dx",&l_dx);
  bbDBStmt(249864);
  bbFloat l_len=bbFloat(std::sqrt(bbDouble(((l_dx*l_dx)+(l_dy*l_dy)))));
  bbDBLocal("len",&l_len);
  bbDBStmt(253960);
  bbFloat l_q=(l_fat/l_len);
  bbDBLocal("q",&l_q);
  bbDBStmt(262146);
  if((this->m_segcount==bbInt(0))){
    bbDBBlock db_blk;
    bbDBStmt(266243);
    this->m_edge0=t_std_geom_Vec2_1f((l_x+(l_dy*l_q)),(l_y-(l_dx*l_q)));
    bbDBStmt(270339);
    this->m_edge1=t_std_geom_Vec2_1f((l_x-(l_dy*l_q)),(l_y+(l_dx*l_q)));
  }
  bbDBStmt(278530);
  this->m_segcount+=1;
  bbDBStmt(286728);
  t_std_geom_Vec2_1f l_v0=this->m_edge0;
  bbDBLocal("v0",&l_v0);
  bbDBStmt(290824);
  t_std_geom_Vec2_1f l_v1=t_std_geom_Vec2_1f((l_x1+(l_dy*l_q)),(l_y1-(l_dx*l_q)));
  bbDBLocal("v1",&l_v1);
  bbDBStmt(294920);
  t_std_geom_Vec2_1f l_v2=t_std_geom_Vec2_1f((l_x1-(l_dy*l_q)),(l_y1+(l_dx*l_q)));
  bbDBLocal("v2",&l_v2);
  bbDBStmt(299016);
  t_std_geom_Vec2_1f l_v3=this->m_edge1;
  bbDBLocal("v3",&l_v3);
  bbDBStmt(307202);
  this->m_canvas->m_DrawTriangle(l_v0,l_v1,l_v2);
  bbDBStmt(311298);
  this->m_canvas->m_DrawTriangle(l_v0,l_v2,l_v3);
  bbDBStmt(319490);
  this->m_edge0=l_v1;
  bbDBStmt(323586);
  this->m_edge1=l_v2;
}

void t_default_VPane::m_EndSegment(){
  bbDBFrame db_f{"EndSegment:Void()","/Users/simon/nitrologic/m2/vpaint/vpaint.monkey2"};
  t_default_VPane*self=this;
  bbDBLocal("Self",&self);
  bbDBStmt(200706);
  this->m_segcount=bbInt(0);
}

void t_default_VPane::m_Draw(t_mojo_graphics_Canvas* l_display){
  bbDBFrame db_f{"Draw:Void(display:mojo.graphics.Canvas)","/Users/simon/nitrologic/m2/vpaint/vpaint.monkey2"};
  t_default_VPane*self=this;
  bbDBLocal("Self",&self);
  bbDBLocal("display",&l_display);
  bbDBStmt(147458);
  this->m_canvas->m_Flush();
  bbDBStmt(151554);
  l_display->m_DrawImage(((t_mojo_graphics_Image*)(this)),0.0f,0.0f);
}

void t_default_VPane::m_ClosedCurve(t_std_geom_Vec2_1f l_p0,t_std_geom_Vec2_1f l_p1,t_std_geom_Vec2_1f l_p2,t_std_geom_Vec2_1f l_p3,bbFloat l_fat){
  bbDBFrame db_f{"ClosedCurve:Void(p0:Vec2f:std.geom.Vec2<Float>,p1:Vec2f:std.geom.Vec2<Float>,p2:Vec2f:std.geom.Vec2<Float>,p3:Vec2f:std.geom.Vec2<Float>,fat:Float)","/Users/simon/nitrologic/m2/vpaint/vpaint.monkey2"};
  t_default_VPane*self=this;
  bbDBLocal("Self",&self);
  bbDBLocal("p0",&l_p0);
  bbDBLocal("p1",&l_p1);
  bbDBLocal("p2",&l_p2);
  bbDBLocal("p3",&l_p3);
  bbDBLocal("fat",&l_fat);
  bbDBStmt(425986);
  if(!bbBool(this->m_canvas)){
    bbDBBlock db_blk;
    bbDBStmt(426000);
    return;
  }
  bbDBStmt(430082);
  this->m_OpenCurve(l_p3,l_p0,l_p1,l_p2,l_fat);
  bbDBStmt(434178);
  this->m_OpenCurve(l_p0,l_p1,l_p2,l_p3,l_fat);
  bbDBStmt(438274);
  this->m_OpenCurve(l_p1,l_p2,l_p3,l_p0,l_fat);
  bbDBStmt(442370);
  this->m_OpenCurve(l_p2,l_p3,l_p0,l_p1,l_fat);
  bbDBStmt(446466);
  this->m_EndSegment();
}

void t_default_VPane::m_Clear(t_std_graphics_Color l_bg){
  bbDBFrame db_f{"Clear:Void(bg:std.graphics.Color)","/Users/simon/nitrologic/m2/vpaint/vpaint.monkey2"};
  t_default_VPane*self=this;
  bbDBLocal("Self",&self);
  bbDBLocal("bg",&l_bg);
  bbDBStmt(167938);
  this->m_canvas->m_Clear(l_bg);
}

void t_default_VPane::m_Circle(bbFloat l_x,bbFloat l_y,bbFloat l_r){
  bbDBFrame db_f{"Circle:Void(x:Float,y:Float,r:Float)","/Users/simon/nitrologic/m2/vpaint/vpaint.monkey2"};
  t_default_VPane*self=this;
  bbDBLocal("Self",&self);
  bbDBLocal("x",&l_x);
  bbDBLocal("y",&l_y);
  bbDBLocal("r",&l_r);
  bbDBStmt(663560);
  t_std_geom_Vec2_1f l_v0=t_std_geom_Vec2_1f((l_x-100.0f),(l_y-100.0f));
  bbDBLocal("v0",&l_v0);
  bbDBStmt(667656);
  t_std_geom_Vec2_1f l_v1=t_std_geom_Vec2_1f((l_x+100.0f),(l_y-100.0f));
  bbDBLocal("v1",&l_v1);
  bbDBStmt(671752);
  t_std_geom_Vec2_1f l_v2=t_std_geom_Vec2_1f((l_x+100.0f),(l_y+100.0f));
  bbDBLocal("v2",&l_v2);
  bbDBStmt(675848);
  t_std_geom_Vec2_1f l_v3=t_std_geom_Vec2_1f((l_x-100.0f),(l_y+100.0f));
  bbDBLocal("v3",&l_v3);
  bbDBStmt(679938);
  this->m_EndSegment();
  bbDBStmt(684034);
  this->m_ClosedCurve(l_v0,l_v1,l_v2,l_v3,l_r);
}
bbString bbDBType(t_default_VPane**){
  return "default.VPane";
}
bbString bbDBValue(t_default_VPane**p){
  return bbDBObjectValue(*p);
}

void t_default_VBrowse::dbEmit(){
}
bbString bbDBType(t_default_VBrowse**){
  return "default.VBrowse";
}
bbString bbDBValue(t_default_VBrowse**p){
  return bbDBObjectValue(*p);
}

void t_default_VToolbar::dbEmit(){
  t_mojo_app_Window::dbEmit();
}

t_default_VToolbar::t_default_VToolbar(bbString l_title):t_mojo_app_Window(l_title,480,34,8){
  bbDBFrame db_f{"new:Void(title:String)","/Users/simon/nitrologic/m2/vpaint/vpaint.monkey2"};
  bbDBLocal("title",&l_title);
}
bbString bbDBType(t_default_VToolbar**){
  return "default.VToolbar";
}
bbString bbDBValue(t_default_VToolbar**p){
  return bbDBObjectValue(*p);
}

void t_default_VPaint::init(){
  m_control=bbArray<bbInt>::create(128);
  m_history=bbArray<t_std_geom_Vec2_1f>::create(4);
}

void t_default_VPaint::gcMark(){
  t_mojo_app_Window::gcMark();
  bbGCMark(m_pane);
  bbGCMark(m_browse);
  bbGCMark(m_sample);
  bbGCMark(m_wheel);
  bbGCMark(m_portMidi);
  bbGCMark(m_control);
  bbGCMark(m_history);
  bbGCMark(m_recentMouseEvent);
}

void t_default_VPaint::dbEmit(){
  t_mojo_app_Window::dbEmit();
  bbDBEmit("appState",&m_appState);
  bbDBEmit("pane",&m_pane);
  bbDBEmit("browse",&m_browse);
  bbDBEmit("status",&m_status);
  bbDBEmit("zoom",&m_zoom);
  bbDBEmit("ink",&m_ink);
  bbDBEmit("mousex",&m_mousex);
  bbDBEmit("mousey",&m_mousey);
  bbDBEmit("mousew",&m_mousew);
  bbDBEmit("framecount",&m_framecount);
  bbDBEmit("drawcount",&m_drawcount);
  bbDBEmit("mousecount",&m_mousecount);
  bbDBEmit("cx",&m_cx);
  bbDBEmit("cy",&m_cy);
  bbDBEmit("rot",&m_rot);
  bbDBEmit("rotSpeed",&m_rotSpeed);
  bbDBEmit("radius",&m_radius);
  bbDBEmit("tool",&m_tool);
  bbDBEmit("panx",&m_panx);
  bbDBEmit("pany",&m_pany);
  bbDBEmit("panxSpeed",&m_panxSpeed);
  bbDBEmit("panySpeed",&m_panySpeed);
  bbDBEmit("sample",&m_sample);
  bbDBEmit("wheel",&m_wheel);
  bbDBEmit("portMidi",&m_portMidi);
  bbDBEmit("statusCount",&m_statusCount);
  bbDBEmit("control",&m_control);
  bbDBEmit("CommandKey",&m_CommandKey);
  bbDBEmit("history",&m_history);
  bbDBEmit("recentMouseEvent",&m_recentMouseEvent);
}

t_default_VPaint::t_default_VPaint(bbString l_title):t_mojo_app_Window(l_title,720,560,8){
  init();
  bbDBFrame db_f{"new:Void(title:String)","/Users/simon/nitrologic/m2/vpaint/vpaint.monkey2"};
  bbDBLocal("title",&l_title);
  bbDBStmt(962562);
  this->m_zoom=2.0f;
  bbDBStmt(970754);
  this->m_pane=bbGCNew<t_default_VPane>(4096,4096,g_default_VPaint_Transparent);
  bbDBStmt(974850);
  this->m_browse=bbGCNew<t_default_VBrowse>();
  bbDBStmt(978946);
  this->m_ink=t_std_graphics_Color(1.0f);
  bbDBStmt(983042);
  this->m_radius=2.5f;
  bbDBStmt(1011714);
  this->m_sample=g_mojo_audio_Sound_Load(BB_T("asset::thrust.wav"));
  bbDBStmt(1019906);
  if(bbBool(this->m_sample)){
    bbDBBlock db_blk;
    bbDBStmt(1024003);
    this->m_wheel=this->m_sample->m_Play(-1);
    bbDBStmt(1028099);
    this->m_wheel->m_Rate(5.0f);
  }else{
    bbDBStmt(1032194);
    bbDBBlock db_blk;
    bbDBStmt(1036291);
    puts(BB_T("Sample not found").c_str());fflush( stdout );
  }
  bbDBStmt(1048578);
  SDL_ShowCursor(bbInt(0));
  bbDBStmt(1056770);
  this->m_InitMidi();
}

void t_default_VPaint::m_ToggleTwo(){
  bbDBFrame db_f{"ToggleTwo:Void()","/Users/simon/nitrologic/m2/vpaint/vpaint.monkey2"};
  t_default_VPaint*self=this;
  bbDBLocal("Self",&self);
}

void t_default_VPaint::m_RefreshStatus(){
  bbDBFrame db_f{"RefreshStatus:Void()","/Users/simon/nitrologic/m2/vpaint/vpaint.monkey2"};
  t_default_VPaint*self=this;
  bbDBLocal("Self",&self);
  bbDBStmt(1241096);
  bbFloat l_r=((this->m_rotSpeed*this->m_rotSpeed)*this->m_rotSpeed);
  bbDBLocal("r",&l_r);
  bbDBStmt(1245192);
  bbFloat l_rpm=bbFloat(g_monkey_math_Abs_1d((bbDouble((3600.0f*l_r))/(g_monkey_math_Pi*2.0))));
  bbDBLocal("rpm",&l_rpm);
  bbDBStmt(1249288);
  bbInt l_velocity=bbInt((100.0*std::sqrt(bbDouble(((this->m_panxSpeed*this->m_panxSpeed)+(this->m_panySpeed*this->m_panySpeed))))));
  bbDBLocal("velocity",&l_velocity);
  bbDBStmt(1253384);
  bbString l_tooltype=BB_T("Line");
  bbDBLocal("tooltype",&l_tooltype);
  bbDBStmt(1257474);
  if((this->m_tool==1)){
    bbDBBlock db_blk;
    bbDBStmt(1257493);
    l_tooltype=BB_T("Curve");
  }
  bbDBStmt(1261570);
  this->m_status=(((((((BB_T("RPM ")+bbString(l_rpm))+BB_T(" Pan="))+bbString(l_velocity))+BB_T(" Tip="))+bbString(bbInt((this->m_radius*100.0f))))+BB_T(" Tool="))+l_tooltype);
  bbDBStmt(1265666);
  this->m_statusCount=200;
  bbDBStmt(1269762);
  this->m_wheel->m_Rate((l_rpm/60.0f));
}

void t_default_VPaint::m_PollMidi(){
  bbDBFrame db_f{"PollMidi:Void()","/Users/simon/nitrologic/m2/vpaint/vpaint.monkey2"};
  t_default_VPaint*self=this;
  bbDBLocal("Self",&self);
  bbDBStmt(1130504);
  static bbInt g_NoteOn=144;
  bbDBStmt(1134600);
  static bbInt g_NoteOff=128;
  bbDBStmt(1138696);
  static bbInt g_Controller=176;
  bbDBStmt(1142792);
  static bbInt g_PitchWheel=224;
  bbDBStmt(1150978);
  {
    bbDBLoop db_loop;
    while(bbBool(this->m_portMidi->m_HasEvent())){
      struct f1_t : public bbGCFrame{
        bbArray<bbUByte>* l_b{};
        void gcMark(){
          bbGCMarkPtr(l_b);
        }
      }f1{};
      bbDBBlock db_blk;
      bbDBStmt(1155081);
      f1.l_b=this->m_portMidi->m_EventDataBytes();
      bbDBLocal("b",&f1.l_b);
      bbDBStmt(1159177);
      bbUByte l_note=f1.l_b->at(1);
      bbDBLocal("note",&l_note);
      bbDBStmt(1163273);
      bbUByte l_velocity=f1.l_b->at(2);
      bbDBLocal("velocity",&l_velocity);
      bbDBStmt(1167369);
      bbInt l_word=bbInt((bbUInt(l_note)+(bbUInt(l_velocity)<<7)));
      bbDBLocal("word",&l_word);
      bbDBStmt(1171459);
      if(f1.l_b->at(bbInt(0))==bbUByte(g_NoteOn)){
        bbDBBlock db_blk;
      }else if(f1.l_b->at(bbInt(0))==bbUByte(g_NoteOff)){
        bbDBBlock db_blk;
      }else if(f1.l_b->at(bbInt(0))==bbUByte(g_PitchWheel)){
        bbDBBlock db_blk;
      }else if(f1.l_b->at(bbInt(0))==bbUByte(g_Controller)){
        bbDBBlock db_blk;
        bbDBStmt(1204229);
        this->m_OnControl(bbInt(f1.l_b->at(1)),bbInt(f1.l_b->at(2)));
      }else{
        bbDBBlock db_blk;
        bbDBStmt(1212421);
        puts(((((((bbString(f1.l_b->at(bbInt(0)))+BB_T(" "))+bbString(f1.l_b->at(1)))+BB_T(" "))+bbString(f1.l_b->at(2)))+BB_T(" "))+bbString(f1.l_b->at(3))).c_str());fflush( stdout );
      }
    }
  }
}

void t_default_VPaint::m_OnRender(t_mojo_graphics_Canvas* l_display){
  bbDBFrame db_f{"OnRender:Void(display:mojo.graphics.Canvas)","/Users/simon/nitrologic/m2/vpaint/vpaint.monkey2"};
  t_default_VPaint*self=this;
  bbDBLocal("Self",&self);
  bbDBLocal("display",&l_display);
  bbDBStmt(1298434);
  this->m_PollMidi();
  bbDBStmt(1306626);
  g_mojo_app_App->m_RequestRender();
  bbDBStmt(1314818);
  if(this->m_appState==0){
    bbDBBlock db_blk;
    bbDBStmt(1327114);
    bbInt l_cy=40;
    bbDBLocal("cy",&l_cy);
    bbDBStmt(1331204);
    {
      struct f2_t : public bbGCFrame{
        bbArray<bbString>* l_0{};
        void gcMark(){
          bbGCMarkPtr(l_0);
        }
      }f2{};
      bbDBLoop db_loop;
      f2.l_0=((((g_default_AboutApp+BB_T(","))+g_default_Contact)+BB_T(","))+g_default_Credits).split(BB_T(","));
      bbDBLocal("0",&f2.l_0);
      bbInt l_1=bbInt(0);
      bbDBLocal("1",&l_1);
      bbInt l_2=f2.l_0->length();
      bbDBLocal("2",&l_2);
      for(;(l_1<l_2);l_1+=1){
        bbDBBlock db_blk;
        bbString l_line=f2.l_0->at(l_1);
        bbDBLocal("line",&l_line);
        bbDBStmt(1335307);
        bbInt l_cx=50;
        bbDBLocal("cx",&l_cx);
        bbDBStmt(1339397);
        {
          struct f4_t : public bbGCFrame{
            bbArray<bbString>* l_3{};
            void gcMark(){
              bbGCMarkPtr(l_3);
            }
          }f4{};
          bbDBLoop db_loop;
          f4.l_3=l_line.split(BB_T("="));
          bbDBLocal("3",&f4.l_3);
          bbInt l_4=bbInt(0);
          bbDBLocal("4",&l_4);
          bbInt l_5=f4.l_3->length();
          bbDBLocal("5",&l_5);
          for(;(l_4<l_5);l_4+=1){
            bbDBBlock db_blk;
            bbString l_tab=f4.l_3->at(l_4);
            bbDBLocal("tab",&l_tab);
            bbDBStmt(1343494);
            l_display->m_DrawText(l_tab,bbFloat(l_cx),bbFloat(l_cy),0.0f,0.0f);
            bbDBStmt(1347590);
            l_cx+=120;
          }
        }
        bbDBStmt(1355781);
        l_cy+=20;
      }
    }
  }else if(this->m_appState==1){
    bbDBBlock db_blk;
    bbDBStmt(1372164);
    this->m_rot+=((this->m_rotSpeed*this->m_rotSpeed)*this->m_rotSpeed);
    bbDBStmt(1380356);
    this->m_panx+=this->m_panxSpeed;
    bbDBStmt(1384452);
    this->m_pany+=this->m_panySpeed;
    bbDBStmt(1392644);
    if(((bbBool(this->m_rotSpeed)||bbBool(this->m_panxSpeed))||bbBool(this->m_panySpeed))){
      bbDBBlock db_blk;
      bbDBStmt(1396741);
      this->m_OnMouseEvent(this->m_recentMouseEvent);
    }
    bbDBStmt(1409028);
    l_display->m_PushMatrix();
    bbDBStmt(1413124);
    this->m_cx=(bbFloat((this->m_Width()/2))-this->m_panx);
    bbDBStmt(1417220);
    this->m_cy=(bbFloat((this->m_Height()/2))-this->m_pany);
    bbDBStmt(1421316);
    l_display->m_Translate(this->m_cx,this->m_cy);
    bbDBStmt(1425418);
    bbFloat l_scale=(-1.0f/this->m_zoom);
    bbDBLocal("scale",&l_scale);
    bbDBStmt(1429508);
    l_display->m_Scale(l_scale,l_scale);
    bbDBStmt(1433604);
    l_display->m_Rotate(this->m_rot);
    bbDBStmt(1441796);
    this->m_pane->m_Draw(l_display);
    bbDBStmt(1445892);
    this->m_framecount+=1;
    bbDBStmt(1449988);
    this->m_ink.m_r=(bbFloat((this->m_framecount&255))/255.0f);
    bbDBStmt(1454084);
    this->m_ink.m_g=(bbFloat((this->m_framecount&1023))/1023.0f);
    bbDBStmt(1458180);
    this->m_ink.m_b=(bbFloat((this->m_framecount&511))/511.0f);
    bbDBStmt(1470468);
    this->m_pane->m_canvas->m_Color(this->m_ink);
    bbDBStmt(1474564);
    l_display->m_PopMatrix();
  }else if(this->m_appState==2){
    bbDBBlock db_blk;
  }
  bbDBStmt(1495042);
  if((this->m_statusCount>bbInt(0))){
    bbDBBlock db_blk;
    bbDBStmt(1499139);
    l_display->m_DrawText(this->m_status,20.0f,20.0f,0.0f,0.0f);
    bbDBStmt(1503235);
    this->m_statusCount-=1;
  }
}

void t_default_VPaint::m_OnMouseEvent(t_mojo_app_MouseEvent* l_event){
  bbDBFrame db_f{"OnMouseEvent:Void(event:mojo.app.MouseEvent)","/Users/simon/nitrologic/m2/vpaint/vpaint.monkey2"};
  t_default_VPaint*self=this;
  bbDBLocal("Self",&self);
  bbDBLocal("event",&l_event);
  bbDBStmt(1925122);
  if((this->m_appState==0)){
    bbDBBlock db_blk;
    bbDBStmt(1929219);
    if((l_event->m_Type()==4)){
      bbDBBlock db_blk;
      bbDBStmt(1933316);
      this->m_DrawMode();
    }
    bbDBStmt(1941507);
    return;
  }
  bbDBStmt(1957890);
  if((l_event==((t_mojo_app_MouseEvent*)0))){
    bbDBBlock db_blk;
    bbDBStmt(1957904);
    return;
  }
  bbDBStmt(1966088);
  bbInt l_mx=l_event->m_Location().m_X();
  bbDBLocal("mx",&l_mx);
  bbDBStmt(1970184);
  bbInt l_my=l_event->m_Location().m_Y();
  bbDBLocal("my",&l_my);
  bbDBStmt(1974280);
  bbInt l_b=bbInt(l_event->m_Button());
  bbDBLocal("b",&l_b);
  bbDBStmt(1982466);
  l_mx=bbInt(((bbFloat(l_mx)-this->m_cx)*this->m_zoom));
  bbDBStmt(1986562);
  l_my=bbInt(((bbFloat(l_my)-this->m_cy)*this->m_zoom));
  bbDBStmt(1994760);
  bbDouble l_x=((-std::cos(bbDouble(this->m_rot))*bbDouble(l_mx))+(std::sin(bbDouble(this->m_rot))*bbDouble(l_my)));
  bbDBLocal("x",&l_x);
  bbDBStmt(1998856);
  bbDouble l_y=((-std::sin(bbDouble(this->m_rot))*bbDouble(l_mx))-(std::cos(bbDouble(this->m_rot))*bbDouble(l_my)));
  bbDBLocal("y",&l_y);
  bbDBStmt(2007048);
  bbInt l_w{};
  bbDBLocal("w",&l_w);
  bbDBStmt(2015234);
  if((this->m_recentMouseEvent!=l_event)){
    bbDBBlock db_blk;
    bbDBStmt(2015261);
    l_w=l_event->m_Wheel().m_Y();
  }
  bbDBStmt(2023426);
  if((((bbDouble(this->m_mousex)==l_x)&&(bbDouble(this->m_mousey)==l_y))&&(this->m_mousew==l_w))){
    bbDBBlock db_blk;
    bbDBStmt(2023464);
    return;
  }
  bbDBStmt(2031618);
  this->m_recentMouseEvent=l_event;
  bbInt l_0=l_event->m_Type();
  bbDBLocal("0",&l_0);
  bbDBStmt(2039810);
  if(l_0==7){
    bbDBBlock db_blk;
    bbDBStmt(2052099);
    this->m_zoom-=(bbFloat(l_w)/8.0f);
    bbDBStmt(2056195);
    if((this->m_zoom<(1.0f/8.0f))){
      bbDBBlock db_blk;
      bbDBStmt(2056209);
      this->m_zoom=(1.0f/8.0f);
    }
  }else if(l_0==5){
    bbDBBlock db_blk;
    bbDBStmt(2068483);
    this->m_pane->m_EndSegment();
    bbDBStmt(2072579);
    this->m_drawcount=bbInt(0);
  }else if(l_0==4){
    bbDBBlock db_blk;
    bbDBStmt(2084867);
    this->m_pane->m_EndSegment();
    bbDBStmt(2088963);
    this->m_drawcount=bbInt(0);
  }
  bbDBStmt(2101250);
  this->m_history->at(bbInt(0))=this->m_history->at(1);
  bbDBStmt(2105346);
  this->m_history->at(1)=this->m_history->at(2);
  bbDBStmt(2109442);
  this->m_history->at(2)=this->m_history->at(3);
  bbDBStmt(2113538);
  this->m_history->at(3)=t_std_geom_Vec2_1f(bbFloat(l_x),bbFloat(l_y));
  bbDBStmt(2121730);
  if(this->m_tool==0){
    bbDBBlock db_blk;
    bbDBStmt(2129924);
    if(bbBool(this->m_drawcount)){
      bbDBBlock db_blk;
      bbDBStmt(2134021);
      this->m_pane->m_StraightLine(this->m_mousex,this->m_mousey,bbInt(l_x),bbInt(l_y),this->m_radius);
    }
  }else if(this->m_tool==1){
    bbDBBlock db_blk;
    bbDBStmt(2146308);
    if(((this->m_drawcount>3)&&!bbBool(l_b))){
      bbDBBlock db_blk;
      bbDBStmt(2154501);
      this->m_pane->m_OpenCurve(this->m_history->at(bbInt(0)),this->m_history->at(1),this->m_history->at(2),this->m_history->at(3),this->m_radius);
    }
  }
  bbDBStmt(2170882);
  this->m_drawcount+=1;
  bbDBStmt(2179074);
  this->m_mousex=bbInt(l_x);
  bbDBStmt(2183170);
  this->m_mousey=bbInt(l_y);
  bbDBStmt(2187266);
  this->m_mousew=l_w;
  bbDBStmt(2195458);
  this->m_mousecount+=1;
}

void t_default_VPaint::m_OnKeyEvent(t_mojo_app_KeyEvent* l_event){
  bbDBFrame db_f{"OnKeyEvent:Void(event:mojo.app.KeyEvent)","/Users/simon/nitrologic/m2/vpaint/vpaint.monkey2"};
  t_default_VPaint*self=this;
  bbDBLocal("Self",&self);
  bbDBLocal("event",&l_event);
  bbInt l_0=l_event->m_Type();
  bbDBLocal("0",&l_0);
  bbDBStmt(1662978);
  if(l_0==0){
    bbDBBlock db_blk;
    bbInt l_1=l_event->m_Key();
    bbDBLocal("1",&l_1);
    bbDBStmt(1671171);
    if(l_1==116){
      bbDBBlock db_blk;
      bbDBStmt(1679364);
      if(this->m_tool==1){
        bbDBBlock db_blk;
        bbDBStmt(1687557);
        this->m_tool=0;
      }else if(this->m_tool==0){
        bbDBBlock db_blk;
        bbDBStmt(1695749);
        this->m_tool=1;
      }
    }else if(l_1==115){
      bbDBBlock db_blk;
      bbDBStmt(1708036);
      this->m_pane->m_Smile(bbFloat(this->m_mousex),bbFloat(this->m_mousey),this->m_radius);
      bbDBStmt(1712132);
      this->m_pane->m_Circle(bbFloat(this->m_mousex),bbFloat(this->m_mousey),this->m_radius);
    }else if(l_1==99){
      bbDBBlock db_blk;
      bbDBStmt(1720324);
      this->m_pane->m_Clear(g_default_VPaint_Transparent);
    }else if(l_1==27){
      bbDBBlock db_blk;
      bbDBStmt(1728516);
      g_default_instance->m_Terminate();
    }else if(l_1==186){
      bbDBBlock db_blk;
      bbDBStmt(1736708);
      this->m_Fullscreen(!this->m_Fullscreen());
    }else if(l_1==187){
      bbDBBlock db_blk;
      bbDBStmt(1744900);
      this->m_ToggleTwo();
    }else if(l_1==32){
      bbDBBlock db_blk;
      bbDBStmt(1753092);
      this->m_Hold();
      bbDBStmt(1757188);
      this->m_pane->m_EndSegment();
    }
    bbDBStmt(1769475);
    if(bbBool((l_event->m_Modifiers()&this->m_CommandKey))){
      bbDBBlock db_blk;
      bbInt l_2=l_event->m_Key();
      bbDBLocal("2",&l_2);
      bbDBStmt(1773572);
      if(l_2==208){
        bbDBBlock db_blk;
        bbDBStmt(1781765);
        this->m_panxSpeed+=(1.0f/4.0f);
      }else if(l_2==207){
        bbDBBlock db_blk;
        bbDBStmt(1789957);
        this->m_panxSpeed-=(1.0f/4.0f);
      }else if(l_2==209){
        bbDBBlock db_blk;
        bbDBStmt(1798149);
        this->m_panySpeed+=(1.0f/4.0f);
      }else if(l_2==210){
        bbDBBlock db_blk;
        bbDBStmt(1806341);
        this->m_panySpeed-=(1.0f/4.0f);
      }
    }else{
      bbDBStmt(1814531);
      bbDBBlock db_blk;
      bbInt l_3=l_event->m_Key();
      bbDBLocal("3",&l_3);
      bbDBStmt(1818628);
      if(l_3==208){
        bbDBBlock db_blk;
        bbDBStmt(1826821);
        this->m_rotSpeed+=(1.0f/16.0f);
      }else if(l_3==207){
        bbDBBlock db_blk;
        bbDBStmt(1835013);
        this->m_rotSpeed-=(1.0f/16.0f);
      }else if(l_3==209){
        bbDBBlock db_blk;
        bbDBStmt(1843205);
        this->m_radius*=0.8f;
      }else if(l_3==210){
        bbDBBlock db_blk;
        bbDBStmt(1851397);
        this->m_radius*=1.2f;
      }
    }
  }
  bbDBStmt(1871874);
  this->m_RefreshStatus();
}

void t_default_VPaint::m_OnControl(bbInt l_index,bbInt l_value){
  bbDBFrame db_f{"OnControl:Void(index:Int,value:Int)","/Users/simon/nitrologic/m2/vpaint/vpaint.monkey2"};
  t_default_VPaint*self=this;
  bbDBLocal("Self",&self);
  bbDBLocal("index",&l_index);
  bbDBLocal("value",&l_value);
  bbDBStmt(1572866);
  this->m_control->at(l_index)=l_value;
  bbDBStmt(1576962);
  if(l_index==15){
    bbDBBlock db_blk;
    bbDBStmt(1585155);
    this->m_radius=(bbFloat(l_value)/4.0f);
  }else if(l_index==16){
    bbDBBlock db_blk;
    bbDBStmt(1593347);
    this->m_ClearColor(t_std_graphics_Color((bbFloat(l_value)/128.0f),this->m_ClearColor().m_G(),this->m_ClearColor().m_B(),1.0f));
  }else if(l_index==17){
    bbDBBlock db_blk;
    bbDBStmt(1601539);
    this->m_ClearColor(t_std_graphics_Color(this->m_ClearColor().m_R(),(bbFloat(l_value)/128.0f),this->m_ClearColor().m_B(),1.0f));
  }else if(l_index==18){
    bbDBBlock db_blk;
    bbDBStmt(1609731);
    this->m_ClearColor(t_std_graphics_Color(this->m_ClearColor().m_R(),this->m_ClearColor().m_G(),(bbFloat(l_value)/128.0f),1.0f));
  }else if(l_index==3){
    bbDBBlock db_blk;
    bbDBStmt(1617923);
    this->m_zoom=bbFloat((l_value/8));
  }else{
    bbDBBlock db_blk;
    bbDBStmt(1626115);
    puts((((BB_T("OnControl:")+bbString(l_index))+BB_T(" "))+bbString(l_value)).c_str());fflush( stdout );
  }
  bbDBStmt(1634306);
  this->m_rotSpeed=((bbFloat((64-this->m_control->at(14)))/512.0f)*bbFloat(this->m_control->at(2)));
}

void t_default_VPaint::m_InitMidi(){
  bbDBFrame db_f{"InitMidi:Void()","/Users/simon/nitrologic/m2/vpaint/vpaint.monkey2"};
  t_default_VPaint*self=this;
  bbDBLocal("Self",&self);
  bbDBStmt(1081346);
  puts(BB_T("PortMidi test 0.1").c_str());fflush( stdout );
  bbDBStmt(1085442);
  puts(BB_T("Scanning Midi Bus, please wait.").c_str());fflush( stdout );
  bbDBStmt(1089538);
  this->m_portMidi=bbGCNew<t_portmidi_PortMidi>();
  bbDBStmt(1093640);
  bbInt l_inputs=this->m_portMidi->m_inputDevices->m_Length();
  bbDBLocal("inputs",&l_inputs);
  bbDBStmt(1097730);
  puts((BB_T("inputs=")+bbString(l_inputs)).c_str());fflush( stdout );
  bbDBStmt(1101826);
  {
    bbDBLoop db_loop;
    bbInt l_i=bbInt(0);
    bbDBLocal("i",&l_i);
    bbDBStmt(1101826);
    for(;(l_i<l_inputs);l_i+=1){
      bbDBBlock db_blk;
      bbDBStmt(1105923);
      this->m_portMidi->m_OpenInput(l_i);
    }
  }
}

void t_default_VPaint::m_Hold(){
  bbDBFrame db_f{"Hold:Void()","/Users/simon/nitrologic/m2/vpaint/vpaint.monkey2"};
  t_default_VPaint*self=this;
  bbDBLocal("Self",&self);
  bbDBStmt(1527810);
  this->m_rotSpeed=0.0f;
  bbDBStmt(1531906);
  this->m_rot=0.0f;
  bbDBStmt(1536002);
  this->m_panxSpeed=0.0f;
  bbDBStmt(1540098);
  this->m_panySpeed=0.0f;
  bbDBStmt(1544194);
  this->m_panx=0.0f;
  bbDBStmt(1548290);
  this->m_pany=0.0f;
}

void t_default_VPaint::m_DrawMode(){
  bbDBFrame db_f{"DrawMode:Void()","/Users/simon/nitrologic/m2/vpaint/vpaint.monkey2"};
  t_default_VPaint*self=this;
  bbDBLocal("Self",&self);
  bbDBStmt(1904642);
  this->m_appState=1;
}
bbString bbDBType(t_default_VPaint**){
  return "default.VPaint";
}
bbString bbDBValue(t_default_VPaint**p){
  return bbDBObjectValue(*p);
}

void mx2_vpaint_vpaint_init(){
  static bool done;
  if(done) return;
  done=true;
  g_default_title=BB_T("VPaint 0.3");
  g_default_AboutApp=BB_T("VPaint Control,,Cursor Left=-RPM,Cursor Right=+RPM,,Mouse Button=Lift Pen,Mouse Wheel=Zoom,Space Key=Hold,S Key=Smile Box,C Key=Clear,Cursor Up=+Pen Size,Cursor Down=-Pen Size,Hold,F1=Toggle Fullscreen,Click To Start");
  g_default_Contact=BB_T(",,Latest Source: github.com/nitrologic/m2/tree/master/vpaint");
  g_default_Credits=BB_T(",,Transpiled by Monkey2 the primate language of champions.");
  g_default_TickMark=bbString::fromChar(65);
  g_default_VPaint_Transparent=t_std_graphics_Color(0.0f,0.0f,0.0f,0.0f);
}

bbInit mx2_vpaint_vpaint_init_v("vpaint_vpaint",&mx2_vpaint_vpaint_init);
