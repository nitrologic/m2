
#include "vpaint_vpaint.h"

// ***** External *****

#include "../../../../../../monkey2/modules/mojo/mojo.buildv010/desktop_debug_macos/mojo_app_2app.h"
#include "../../../../../../monkey2/modules/mojo/mojo.buildv010/desktop_debug_macos/mojo_app_2event.h"
#include "../../../../../../monkey2/modules/mojo/mojo.buildv010/desktop_debug_macos/mojo_app_2view.h"
#include "../../../../../../monkey2/modules/mojo/mojo.buildv010/desktop_debug_macos/mojo_audio_2audio.h"
#include "../../../../../../monkey2/modules/mojo/mojo.buildv010/desktop_debug_macos/mojo_graphics_2canvas.h"
#include "../../../../../../monkey2/modules/monkey/monkey.buildv010/desktop_debug_macos/monkey_math.h"
#include "../../../../../../monkey2/modules/std/std.buildv010/desktop_debug_macos/std_graphics_2pixmap.h"
#include "../../../../../../monkey2/modules/std/std.buildv010/desktop_debug_macos/std_stream_2filestream.h"

extern bbDouble g_monkey_math_Abs_1d(bbDouble l_x);

// ***** Internal *****

bbString g_default_title;
bbString g_default_AboutApp;
bbString g_default_Contact;
bbString g_default_Credits;
bbGCRootVar<t_mojo_app_AppInstance> g_default_instance;
bbString g_default_TickMark;

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
  bbDBStmt(323592);
  f0.l_verts=bbArray<bbFloat>::create(((l_seg+1)*2));
  bbDBLocal("verts",&f0.l_verts);
  bbDBStmt(327682);
  {
    bbDBLoop db_loop;
    bbInt l_i=bbInt(0);
    bbDBLocal("i",&l_i);
    bbDBStmt(327682);
    for(;(l_i<=l_seg);l_i+=1){
      bbDBBlock db_blk;
      bbDBStmt(331785);
      bbFloat l_mu=((bbFloat(l_i)*1.0f)/bbFloat(l_seg));
      bbDBLocal("mu",&l_mu);
      bbDBStmt(335887);
      bbFloat l_x=g_default_VPane_CatmullInterpolate(l_p0.m_x,l_p1.m_x,l_p2.m_x,l_p3.m_x,l_mu);
      bbDBLocal("x",&l_x);
      bbDBStmt(339983);
      bbFloat l_y=g_default_VPane_CatmullInterpolate(l_p0.m_y,l_p1.m_y,l_p2.m_y,l_p3.m_y,l_mu);
      bbDBLocal("y",&l_y);
      bbDBStmt(344075);
      f0.l_verts->at(((l_i*2)+bbInt(0)))=l_x;
      bbDBStmt(348169);
      f0.l_verts->at(((l_i*2)+1))=l_y;
    }
  }
  bbDBStmt(356354);
  return f0.l_verts;
}

bbFloat g_default_VPane_CubicInterpolate2(bbFloat l_p0,bbFloat l_p1,bbFloat l_p2,bbFloat l_p3,bbFloat l_x){
  bbDBFrame db_f{"CubicInterpolate2:Float(p0:Float,p1:Float,p2:Float,p3:Float,x:Float)","/Users/simon/nitrologic/m2/vpaint/vpaint.monkey2"};
  bbDBLocal("p0",&l_p0);
  bbDBLocal("p1",&l_p1);
  bbDBLocal("p2",&l_p2);
  bbDBLocal("p3",&l_p3);
  bbDBLocal("x",&l_x);
  bbDBStmt(528386);
  return (l_p1+((0.5f*l_x)*((l_p2-l_p0)+(l_x*(((((2.0f*l_p0)-(5.0f*l_p1))+(4.0f*l_p2))-l_p3)+(l_x*(((3.0f*(l_p1-l_p2))+l_p3)-l_p0)))))));
}

bbFloat g_default_VPane_CubicInterpolate(bbFloat l_y0,bbFloat l_y1,bbFloat l_y2,bbFloat l_y3,bbFloat l_mu){
  bbDBFrame db_f{"CubicInterpolate:Float(y0:Float,y1:Float,y2:Float,y3:Float,mu:Float)","/Users/simon/nitrologic/m2/vpaint/vpaint.monkey2"};
  bbDBLocal("y0",&l_y0);
  bbDBLocal("y1",&l_y1);
  bbDBLocal("y2",&l_y2);
  bbDBLocal("y3",&l_y3);
  bbDBLocal("mu",&l_mu);
  bbDBStmt(446472);
  bbFloat l_a0{};
  bbDBLocal("a0",&l_a0);
  bbDBStmt(446481);
  bbFloat l_a1{};
  bbDBLocal("a1",&l_a1);
  bbDBStmt(446490);
  bbFloat l_a2{};
  bbDBLocal("a2",&l_a2);
  bbDBStmt(446499);
  bbFloat l_a3{};
  bbDBLocal("a3",&l_a3);
  bbDBStmt(446508);
  bbFloat l_mu2{};
  bbDBLocal("mu2",&l_mu2);
  bbDBStmt(450562);
  l_mu2=(l_mu*l_mu);
  bbDBStmt(454658);
  l_a0=(((l_y3-l_y2)-l_y0)+l_y1);
  bbDBStmt(458754);
  l_a1=((l_y0-l_y1)-l_a0);
  bbDBStmt(462850);
  l_a2=(l_y2-l_y0);
  bbDBStmt(466946);
  l_a3=l_y1;
  bbDBStmt(471042);
  return (((((l_a0*l_mu)*l_mu2)+(l_a1*l_mu2))+(l_a2*l_mu))+l_a3);
}

bbFloat g_default_VPane_CatmullInterpolate(bbFloat l_y0,bbFloat l_y1,bbFloat l_y2,bbFloat l_y3,bbFloat l_mu){
  bbDBFrame db_f{"CatmullInterpolate:Float(y0:Float,y1:Float,y2:Float,y3:Float,mu:Float)","/Users/simon/nitrologic/m2/vpaint/vpaint.monkey2"};
  bbDBLocal("y0",&l_y0);
  bbDBLocal("y1",&l_y1);
  bbDBLocal("y2",&l_y2);
  bbDBLocal("y3",&l_y3);
  bbDBLocal("mu",&l_mu);
  bbDBStmt(487432);
  bbFloat l_a0{};
  bbDBLocal("a0",&l_a0);
  bbDBStmt(487441);
  bbFloat l_a1{};
  bbDBLocal("a1",&l_a1);
  bbDBStmt(487450);
  bbFloat l_a2{};
  bbDBLocal("a2",&l_a2);
  bbDBStmt(487459);
  bbFloat l_a3{};
  bbDBLocal("a3",&l_a3);
  bbDBStmt(487468);
  bbFloat l_mu2{};
  bbDBLocal("mu2",&l_mu2);
  bbDBStmt(491522);
  l_mu2=(l_mu*l_mu);
  bbDBStmt(495618);
  l_a0=((((-0.5f*l_y0)+(1.5f*l_y1))-(1.5f*l_y2))+(0.5f*l_y3));
  bbDBStmt(499714);
  l_a1=(((l_y0-(2.5f*l_y1))+(2.0f*l_y2))-(0.5f*l_y3));
  bbDBStmt(503810);
  l_a2=((-0.5f*l_y0)+(0.5f*l_y2));
  bbDBStmt(507906);
  l_a3=l_y1;
  bbDBStmt(512002);
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
  bbDBStmt(1937415);
  f0.l_stream=g_std_stream_FileStream_Open(l_path,BB_T("w"));
  bbDBLocal("stream",&f0.l_stream);
  bbDBStmt(1941511);
  f0.l_buffer=bbArray<bbByte>::create(18);
  bbDBLocal("buffer",&f0.l_buffer);
  bbDBStmt(1945607);
  bbInt l_w=l_pixmap->m_Width();
  bbDBLocal("w",&l_w);
  bbDBStmt(1949703);
  bbInt l_h=l_pixmap->m_Height();
  bbDBLocal("h",&l_h);
  bbDBStmt(1953793);
  f0.l_buffer->at(2)=2;
  bbDBStmt(1957889);
  f0.l_buffer->at(12)=bbByte((l_w&255));
  bbDBStmt(1961985);
  f0.l_buffer->at(13)=bbByte((l_w>>8));
  bbDBStmt(1966081);
  f0.l_buffer->at(14)=bbByte((l_h&255));
  bbDBStmt(1970177);
  f0.l_buffer->at(15)=bbByte((l_h>>8));
  bbDBStmt(1974273);
  f0.l_buffer->at(16)=32;
  bbDBStmt(1978369);
  f0.l_buffer->at(17)=8;
  bbDBStmt(1982465);
  f0.l_stream->m_Write(((void*)(&f0.l_buffer->at(bbInt(0)))),18);
  bbDBStmt(1986561);
  f0.l_stream->m_Write(((void*)(l_pixmap->m_Data())),((l_w*l_h)*4));
  bbDBStmt(1990657);
  f0.l_stream->m_Close();
}

void bbMain(){
  static bool done;
  if(done) return;
  done=true;
  void mx2_mojo_main();mx2_mojo_main();
  void mx2_std_main();mx2_std_main();
  bbDBFrame db_f{"Main:Void()","/Users/simon/nitrologic/m2/vpaint/vpaint.monkey2"};
  bbDBStmt(1908737);
  puts(g_default_title.c_str());fflush( stdout );
  bbDBStmt(1912833);
  g_default_instance=bbGCNew<t_mojo_app_AppInstance>();
  bbDBStmt(1916929);
  bbGCNew<t_default_VPaint>(g_default_title);
  bbDBStmt(1921025);
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
  bbDBStmt(98306);
  this->m_canvas=bbGCNew<t_mojo_graphics_Canvas>(((t_mojo_graphics_Image*)(this)));
  bbDBStmt(102402);
  this->m_canvas->m_Clear(l_bg);
  bbDBStmt(106498);
  this->m_canvas->m_Alpha(0.8f);
  bbDBStmt(110594);
  this->m_canvas->m_Translate(bbFloat((l_w/2)),bbFloat((l_h/2)));
  bbDBStmt(114690);
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
  bbDBStmt(544770);
  if(!bbBool(this->m_canvas)){
    bbDBBlock db_blk;
    bbDBStmt(544784);
    return;
  }
  bbDBStmt(548872);
  bbInt l_dy=(l_y1-l_y);
  bbDBLocal("dy",&l_dy);
  bbDBStmt(552968);
  bbInt l_dx=(l_x1-l_x);
  bbDBLocal("dx",&l_dx);
  bbDBStmt(557064);
  bbFloat l_len=bbFloat(std::sqrt(bbDouble(((l_dx*l_dx)+(l_dy*l_dy)))));
  bbDBLocal("len",&l_len);
  bbDBStmt(561160);
  bbFloat l_q=(l_fat/l_len);
  bbDBLocal("q",&l_q);
  bbDBStmt(565256);
  t_std_geom_Vec2_1f l_v0=t_std_geom_Vec2_1f((bbFloat(l_x)+(bbFloat(l_dy)*l_q)),(bbFloat(l_y)-(bbFloat(l_dx)*l_q)));
  bbDBLocal("v0",&l_v0);
  bbDBStmt(569352);
  t_std_geom_Vec2_1f l_v1=t_std_geom_Vec2_1f((bbFloat(l_x1)+(bbFloat(l_dy)*l_q)),(bbFloat(l_y1)-(bbFloat(l_dx)*l_q)));
  bbDBLocal("v1",&l_v1);
  bbDBStmt(573448);
  t_std_geom_Vec2_1f l_v2=t_std_geom_Vec2_1f((bbFloat(l_x1)-(bbFloat(l_dy)*l_q)),(bbFloat(l_y1)+(bbFloat(l_dx)*l_q)));
  bbDBLocal("v2",&l_v2);
  bbDBStmt(577544);
  t_std_geom_Vec2_1f l_v3=t_std_geom_Vec2_1f((bbFloat(l_x)-(bbFloat(l_dy)*l_q)),(bbFloat(l_y)+(bbFloat(l_dx)*l_q)));
  bbDBLocal("v3",&l_v3);
  bbDBStmt(581634);
  this->m_canvas->m_DrawTriangle(l_v0,l_v1,l_v2);
  bbDBStmt(585730);
  this->m_canvas->m_DrawTriangle(l_v0,l_v2,l_v3);
}

void t_default_VPane::m_Smile(bbFloat l_x,bbFloat l_y,bbFloat l_r){
  bbDBFrame db_f{"Smile:Void(x:Float,y:Float,r:Float)","/Users/simon/nitrologic/m2/vpaint/vpaint.monkey2"};
  t_default_VPane*self=this;
  bbDBLocal("Self",&self);
  bbDBLocal("x",&l_x);
  bbDBLocal("y",&l_y);
  bbDBLocal("r",&l_r);
  bbDBStmt(606216);
  t_std_geom_Vec2_1f l_v0=t_std_geom_Vec2_1f((l_x-100.0f),(l_y+100.0f));
  bbDBLocal("v0",&l_v0);
  bbDBStmt(610312);
  t_std_geom_Vec2_1f l_v1=t_std_geom_Vec2_1f((l_x-100.0f),(l_y-20.0f));
  bbDBLocal("v1",&l_v1);
  bbDBStmt(614408);
  t_std_geom_Vec2_1f l_v2=t_std_geom_Vec2_1f((l_x+100.0f),(l_y-20.0f));
  bbDBLocal("v2",&l_v2);
  bbDBStmt(618504);
  t_std_geom_Vec2_1f l_v3=t_std_geom_Vec2_1f((l_x+100.0f),(l_y+100.0f));
  bbDBLocal("v3",&l_v3);
  bbDBStmt(622594);
  this->m_EndSegment();
  bbDBStmt(626690);
  this->m_OpenCurve(l_v0,l_v1,l_v2,l_v3,l_r);
  bbDBStmt(630786);
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
  bbDBStmt(372738);
  if(!bbBool(this->m_canvas)){
    bbDBBlock db_blk;
    bbDBStmt(372752);
    return;
  }
  bbDBStmt(376840);
  bbInt l_seg=9;
  bbDBLocal("seg",&l_seg);
  bbDBStmt(380936);
  f0.l_verts=g_default_VPane_Curve(l_seg,l_p0,l_p1,l_p2,l_p3);
  bbDBLocal("verts",&f0.l_verts);
  bbDBStmt(385026);
  {
    bbDBLoop db_loop;
    bbInt l_i=bbInt(0);
    bbDBLocal("i",&l_i);
    bbDBStmt(385026);
    for(;(l_i<l_seg);l_i+=1){
      bbDBBlock db_blk;
      bbDBStmt(389123);
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
  bbDBStmt(204802);
  if(!bbBool(this->m_canvas)){
    bbDBBlock db_blk;
    bbDBStmt(204816);
    return;
  }
  bbDBStmt(213000);
  f0.l_verts=bbArray<bbFloat>::create(8);
  bbDBLocal("verts",&f0.l_verts);
  bbDBStmt(221192);
  bbFloat l_dy=(l_y1-l_y);
  bbDBLocal("dy",&l_dy);
  bbDBStmt(225288);
  bbFloat l_dx=(l_x1-l_x);
  bbDBLocal("dx",&l_dx);
  bbDBStmt(233480);
  bbFloat l_len=bbFloat(std::sqrt(bbDouble(((l_dx*l_dx)+(l_dy*l_dy)))));
  bbDBLocal("len",&l_len);
  bbDBStmt(237576);
  bbFloat l_q=(l_fat/l_len);
  bbDBLocal("q",&l_q);
  bbDBStmt(245762);
  if((this->m_segcount==bbInt(0))){
    bbDBBlock db_blk;
    bbDBStmt(249859);
    this->m_edge0=t_std_geom_Vec2_1f((l_x+(l_dy*l_q)),(l_y-(l_dx*l_q)));
    bbDBStmt(253955);
    this->m_edge1=t_std_geom_Vec2_1f((l_x-(l_dy*l_q)),(l_y+(l_dx*l_q)));
  }
  bbDBStmt(262146);
  this->m_segcount+=1;
  bbDBStmt(270344);
  t_std_geom_Vec2_1f l_v0=this->m_edge0;
  bbDBLocal("v0",&l_v0);
  bbDBStmt(274440);
  t_std_geom_Vec2_1f l_v1=t_std_geom_Vec2_1f((l_x1+(l_dy*l_q)),(l_y1-(l_dx*l_q)));
  bbDBLocal("v1",&l_v1);
  bbDBStmt(278536);
  t_std_geom_Vec2_1f l_v2=t_std_geom_Vec2_1f((l_x1-(l_dy*l_q)),(l_y1+(l_dx*l_q)));
  bbDBLocal("v2",&l_v2);
  bbDBStmt(282632);
  t_std_geom_Vec2_1f l_v3=this->m_edge1;
  bbDBLocal("v3",&l_v3);
  bbDBStmt(290818);
  this->m_canvas->m_DrawTriangle(l_v0,l_v1,l_v2);
  bbDBStmt(294914);
  this->m_canvas->m_DrawTriangle(l_v0,l_v2,l_v3);
  bbDBStmt(303106);
  this->m_edge0=l_v1;
  bbDBStmt(307202);
  this->m_edge1=l_v2;
}

void t_default_VPane::m_EndSegment(){
  bbDBFrame db_f{"EndSegment:Void()","/Users/simon/nitrologic/m2/vpaint/vpaint.monkey2"};
  t_default_VPane*self=this;
  bbDBLocal("Self",&self);
  bbDBStmt(184322);
  this->m_segcount=bbInt(0);
}

void t_default_VPane::m_Draw(t_mojo_graphics_Canvas* l_display){
  bbDBFrame db_f{"Draw:Void(display:mojo.graphics.Canvas)","/Users/simon/nitrologic/m2/vpaint/vpaint.monkey2"};
  t_default_VPane*self=this;
  bbDBLocal("Self",&self);
  bbDBLocal("display",&l_display);
  bbDBStmt(131074);
  this->m_canvas->m_Flush();
  bbDBStmt(135170);
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
  bbDBStmt(409602);
  if(!bbBool(this->m_canvas)){
    bbDBBlock db_blk;
    bbDBStmt(409616);
    return;
  }
  bbDBStmt(413698);
  this->m_OpenCurve(l_p3,l_p0,l_p1,l_p2,l_fat);
  bbDBStmt(417794);
  this->m_OpenCurve(l_p0,l_p1,l_p2,l_p3,l_fat);
  bbDBStmt(421890);
  this->m_OpenCurve(l_p1,l_p2,l_p3,l_p0,l_fat);
  bbDBStmt(425986);
  this->m_OpenCurve(l_p2,l_p3,l_p0,l_p1,l_fat);
  bbDBStmt(430082);
  this->m_EndSegment();
}

void t_default_VPane::m_Clear(t_std_graphics_Color l_bg){
  bbDBFrame db_f{"Clear:Void(bg:std.graphics.Color)","/Users/simon/nitrologic/m2/vpaint/vpaint.monkey2"};
  t_default_VPane*self=this;
  bbDBLocal("Self",&self);
  bbDBLocal("bg",&l_bg);
  bbDBStmt(151554);
  this->m_canvas->m_Clear(l_bg);
}

void t_default_VPane::m_Circle(bbFloat l_x,bbFloat l_y,bbFloat l_r){
  bbDBFrame db_f{"Circle:Void(x:Float,y:Float,r:Float)","/Users/simon/nitrologic/m2/vpaint/vpaint.monkey2"};
  t_default_VPane*self=this;
  bbDBLocal("Self",&self);
  bbDBLocal("x",&l_x);
  bbDBLocal("y",&l_y);
  bbDBLocal("r",&l_r);
  bbDBStmt(647176);
  t_std_geom_Vec2_1f l_v0=t_std_geom_Vec2_1f((l_x-100.0f),(l_y-100.0f));
  bbDBLocal("v0",&l_v0);
  bbDBStmt(651272);
  t_std_geom_Vec2_1f l_v1=t_std_geom_Vec2_1f((l_x+100.0f),(l_y-100.0f));
  bbDBLocal("v1",&l_v1);
  bbDBStmt(655368);
  t_std_geom_Vec2_1f l_v2=t_std_geom_Vec2_1f((l_x+100.0f),(l_y+100.0f));
  bbDBLocal("v2",&l_v2);
  bbDBStmt(659464);
  t_std_geom_Vec2_1f l_v3=t_std_geom_Vec2_1f((l_x-100.0f),(l_y+100.0f));
  bbDBLocal("v3",&l_v3);
  bbDBStmt(663554);
  this->m_EndSegment();
  bbDBStmt(667650);
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
  m_history=bbArray<t_std_geom_Vec2_1f>::create(4);
}

void t_default_VPaint::gcMark(){
  t_mojo_app_Window::gcMark();
  bbGCMark(m_pane);
  bbGCMark(m_browse);
  bbGCMark(m_sample);
  bbGCMark(m_wheel);
  bbGCMark(m_history);
  bbGCMark(m_recentMouseEvent);
}

void t_default_VPaint::dbEmit(){
  t_mojo_app_Window::dbEmit();
  bbDBEmit("appState",&m_appState);
  bbDBEmit("pane",&m_pane);
  bbDBEmit("browse",&m_browse);
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
  bbDBEmit("titleCount",&m_titleCount);
  bbDBEmit("CommandKey",&m_CommandKey);
  bbDBEmit("history",&m_history);
  bbDBEmit("recentMouseEvent",&m_recentMouseEvent);
}

t_default_VPaint::t_default_VPaint(bbString l_title):t_mojo_app_Window(l_title,720,560,8){
  init();
  bbDBFrame db_f{"new:Void(title:String)","/Users/simon/nitrologic/m2/vpaint/vpaint.monkey2"};
  bbDBLocal("title",&l_title);
  bbDBStmt(933890);
  this->m_zoom=2.0f;
  bbDBStmt(942082);
  this->m_pane=bbGCNew<t_default_VPane>(4096,4096,g_std_graphics_Color_Black);
  bbDBStmt(946178);
  this->m_browse=bbGCNew<t_default_VBrowse>();
  bbDBStmt(950274);
  this->m_ink=t_std_graphics_Color(1.0f);
  bbDBStmt(954370);
  this->m_radius=2.5f;
  bbDBStmt(983042);
  this->m_sample=g_mojo_audio_Sound_Load(BB_T("asset::thrust.wav"));
  bbDBStmt(991234);
  if(bbBool(this->m_sample)){
    bbDBBlock db_blk;
    bbDBStmt(995331);
    this->m_wheel=this->m_sample->m_Play(-1);
    bbDBStmt(999427);
    this->m_wheel->m_Rate(5.0f);
  }else{
    bbDBStmt(1003522);
    bbDBBlock db_blk;
    bbDBStmt(1007619);
    puts(BB_T("Sample not found").c_str());fflush( stdout );
  }
}

void t_default_VPaint::m_ToggleTwo(){
  bbDBFrame db_f{"ToggleTwo:Void()","/Users/simon/nitrologic/m2/vpaint/vpaint.monkey2"};
  t_default_VPaint*self=this;
  bbDBLocal("Self",&self);
}

void t_default_VPaint::m_RefreshTitle(){
  bbDBFrame db_f{"RefreshTitle:Void()","/Users/simon/nitrologic/m2/vpaint/vpaint.monkey2"};
  t_default_VPaint*self=this;
  bbDBLocal("Self",&self);
  bbDBStmt(1032200);
  bbFloat l_r=((this->m_rotSpeed*this->m_rotSpeed)*this->m_rotSpeed);
  bbDBLocal("r",&l_r);
  bbDBStmt(1036296);
  bbFloat l_rpm=bbFloat(g_monkey_math_Abs_1d((bbDouble((3600.0f*l_r))/(g_monkey_math_Pi*2.0))));
  bbDBLocal("rpm",&l_rpm);
  bbDBStmt(1040392);
  bbInt l_velocity=bbInt((100.0*std::sqrt(bbDouble(((this->m_panxSpeed*this->m_panxSpeed)+(this->m_panySpeed*this->m_panySpeed))))));
  bbDBLocal("velocity",&l_velocity);
  bbDBStmt(1044488);
  bbString l_tooltype=BB_T("Line");
  bbDBLocal("tooltype",&l_tooltype);
  bbDBStmt(1048578);
  if((this->m_tool==1)){
    bbDBBlock db_blk;
    bbDBStmt(1048597);
    l_tooltype=BB_T("Curve");
  }
  bbDBStmt(1052674);
  this->m_Title((((((((BB_T("RPM ")+bbString(l_rpm))+BB_T(" Pan="))+bbString(l_velocity))+BB_T(" Tip="))+bbString(bbInt((this->m_radius*100.0f))))+BB_T(" Tool="))+l_tooltype));
  bbDBStmt(1056770);
  this->m_titleCount=200;
  bbDBStmt(1064962);
  this->m_wheel->m_Rate((l_rpm/60.0f));
}

void t_default_VPaint::m_OnRender(t_mojo_graphics_Canvas* l_display){
  bbDBFrame db_f{"OnRender:Void(display:mojo.graphics.Canvas)","/Users/simon/nitrologic/m2/vpaint/vpaint.monkey2"};
  t_default_VPaint*self=this;
  bbDBLocal("Self",&self);
  bbDBLocal("display",&l_display);
  bbDBStmt(1089538);
  g_mojo_app_App->m_RequestRender();
  bbDBStmt(1097730);
  if(this->m_appState==0){
    bbDBBlock db_blk;
    bbDBStmt(1110026);
    bbInt l_cy=40;
    bbDBLocal("cy",&l_cy);
    bbDBStmt(1114116);
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
        bbDBStmt(1118219);
        bbInt l_cx=50;
        bbDBLocal("cx",&l_cx);
        bbDBStmt(1122309);
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
            bbDBStmt(1126406);
            l_display->m_DrawText(l_tab,bbFloat(l_cx),bbFloat(l_cy),0.0f,0.0f);
            bbDBStmt(1130502);
            l_cx+=120;
          }
        }
        bbDBStmt(1138693);
        l_cy+=20;
      }
    }
  }else if(this->m_appState==1){
    bbDBBlock db_blk;
    bbDBStmt(1155076);
    this->m_rot+=((this->m_rotSpeed*this->m_rotSpeed)*this->m_rotSpeed);
    bbDBStmt(1163268);
    this->m_panx+=this->m_panxSpeed;
    bbDBStmt(1167364);
    this->m_pany+=this->m_panySpeed;
    bbDBStmt(1175556);
    if(((bbBool(this->m_rotSpeed)||bbBool(this->m_panxSpeed))||bbBool(this->m_panySpeed))){
      bbDBBlock db_blk;
      bbDBStmt(1179653);
      this->m_OnMouseEvent(this->m_recentMouseEvent);
    }
    bbDBStmt(1191940);
    l_display->m_PushMatrix();
    bbDBStmt(1196036);
    this->m_cx=(bbFloat((this->m_Width()/2))-this->m_panx);
    bbDBStmt(1200132);
    this->m_cy=(bbFloat((this->m_Height()/2))-this->m_pany);
    bbDBStmt(1204228);
    l_display->m_Translate(this->m_cx,this->m_cy);
    bbDBStmt(1208330);
    bbFloat l_scale=(-1.0f/this->m_zoom);
    bbDBLocal("scale",&l_scale);
    bbDBStmt(1212420);
    l_display->m_Scale(l_scale,l_scale);
    bbDBStmt(1216516);
    l_display->m_Rotate(this->m_rot);
    bbDBStmt(1224708);
    this->m_pane->m_Draw(l_display);
    bbDBStmt(1228804);
    this->m_framecount+=1;
    bbDBStmt(1232900);
    this->m_ink.m_r=(bbFloat((this->m_framecount&255))/255.0f);
    bbDBStmt(1236996);
    this->m_ink.m_g=(bbFloat((this->m_framecount&1023))/1023.0f);
    bbDBStmt(1241092);
    this->m_ink.m_b=(bbFloat((this->m_framecount&511))/511.0f);
    bbDBStmt(1253380);
    this->m_pane->m_canvas->m_Color(this->m_ink);
    bbDBStmt(1257476);
    l_display->m_PopMatrix();
  }else if(this->m_appState==2){
    bbDBBlock db_blk;
  }
  bbDBStmt(1277954);
  if(((this->m_titleCount>bbInt(0))&&this->m_Fullscreen())){
    bbDBBlock db_blk;
    bbDBStmt(1282051);
    l_display->m_DrawText(this->m_Title(),20.0f,20.0f,0.0f,0.0f);
    bbDBStmt(1286147);
    this->m_titleCount-=1;
  }
}

void t_default_VPaint::m_OnMouseEvent(t_mojo_app_MouseEvent* l_event){
  bbDBFrame db_f{"OnMouseEvent:Void(event:mojo.app.MouseEvent)","/Users/simon/nitrologic/m2/vpaint/vpaint.monkey2"};
  t_default_VPaint*self=this;
  bbDBLocal("Self",&self);
  bbDBLocal("event",&l_event);
  bbDBStmt(1617922);
  if((this->m_appState==0)){
    bbDBBlock db_blk;
    bbDBStmt(1622019);
    if((l_event->m_Type()==4)){
      bbDBBlock db_blk;
      bbDBStmt(1626116);
      this->m_DrawMode();
    }
    bbDBStmt(1634307);
    return;
  }
  bbDBStmt(1650690);
  if((l_event==((t_mojo_app_MouseEvent*)0))){
    bbDBBlock db_blk;
    bbDBStmt(1650704);
    return;
  }
  bbDBStmt(1658888);
  bbInt l_mx=l_event->m_Location().m_X();
  bbDBLocal("mx",&l_mx);
  bbDBStmt(1662984);
  bbInt l_my=l_event->m_Location().m_Y();
  bbDBLocal("my",&l_my);
  bbDBStmt(1667080);
  bbInt l_b=bbInt(l_event->m_Button());
  bbDBLocal("b",&l_b);
  bbDBStmt(1675266);
  l_mx=bbInt(((bbFloat(l_mx)-this->m_cx)*this->m_zoom));
  bbDBStmt(1679362);
  l_my=bbInt(((bbFloat(l_my)-this->m_cy)*this->m_zoom));
  bbDBStmt(1687560);
  bbDouble l_x=((-std::cos(bbDouble(this->m_rot))*bbDouble(l_mx))+(std::sin(bbDouble(this->m_rot))*bbDouble(l_my)));
  bbDBLocal("x",&l_x);
  bbDBStmt(1691656);
  bbDouble l_y=((-std::sin(bbDouble(this->m_rot))*bbDouble(l_mx))-(std::cos(bbDouble(this->m_rot))*bbDouble(l_my)));
  bbDBLocal("y",&l_y);
  bbDBStmt(1699848);
  bbInt l_w{};
  bbDBLocal("w",&l_w);
  bbDBStmt(1708034);
  if((this->m_recentMouseEvent!=l_event)){
    bbDBBlock db_blk;
    bbDBStmt(1708061);
    l_w=l_event->m_Wheel().m_Y();
  }
  bbDBStmt(1716226);
  if((((bbDouble(this->m_mousex)==l_x)&&(bbDouble(this->m_mousey)==l_y))&&(this->m_mousew==l_w))){
    bbDBBlock db_blk;
    bbDBStmt(1716264);
    return;
  }
  bbDBStmt(1724418);
  this->m_recentMouseEvent=l_event;
  bbInt l_0=l_event->m_Type();
  bbDBLocal("0",&l_0);
  bbDBStmt(1732610);
  if(l_0==7){
    bbDBBlock db_blk;
    bbDBStmt(1744899);
    this->m_zoom-=(bbFloat(l_w)/8.0f);
    bbDBStmt(1748995);
    if((this->m_zoom<(1.0f/8.0f))){
      bbDBBlock db_blk;
      bbDBStmt(1749009);
      this->m_zoom=(1.0f/8.0f);
    }
  }else if(l_0==5){
    bbDBBlock db_blk;
    bbDBStmt(1761283);
    this->m_pane->m_EndSegment();
    bbDBStmt(1765379);
    this->m_drawcount=bbInt(0);
  }else if(l_0==4){
    bbDBBlock db_blk;
    bbDBStmt(1777667);
    this->m_pane->m_EndSegment();
    bbDBStmt(1781763);
    this->m_drawcount=bbInt(0);
  }
  bbDBStmt(1794050);
  this->m_history->at(bbInt(0))=this->m_history->at(1);
  bbDBStmt(1798146);
  this->m_history->at(1)=this->m_history->at(2);
  bbDBStmt(1802242);
  this->m_history->at(2)=this->m_history->at(3);
  bbDBStmt(1806338);
  this->m_history->at(3)=t_std_geom_Vec2_1f(bbFloat(l_x),bbFloat(l_y));
  bbDBStmt(1814530);
  if(this->m_tool==0){
    bbDBBlock db_blk;
    bbDBStmt(1822724);
    if(bbBool(this->m_drawcount)){
      bbDBBlock db_blk;
      bbDBStmt(1826821);
      this->m_pane->m_StraightLine(this->m_mousex,this->m_mousey,bbInt(l_x),bbInt(l_y),this->m_radius);
    }
  }else if(this->m_tool==1){
    bbDBBlock db_blk;
    bbDBStmt(1839108);
    if(((this->m_drawcount>3)&&!bbBool(l_b))){
      bbDBBlock db_blk;
      bbDBStmt(1847301);
      this->m_pane->m_OpenCurve(this->m_history->at(bbInt(0)),this->m_history->at(1),this->m_history->at(2),this->m_history->at(3),this->m_radius);
    }
  }
  bbDBStmt(1863682);
  this->m_drawcount+=1;
  bbDBStmt(1871874);
  this->m_mousex=bbInt(l_x);
  bbDBStmt(1875970);
  this->m_mousey=bbInt(l_y);
  bbDBStmt(1880066);
  this->m_mousew=l_w;
  bbDBStmt(1888258);
  this->m_mousecount+=1;
}

void t_default_VPaint::m_OnKeyEvent(t_mojo_app_KeyEvent* l_event){
  bbDBFrame db_f{"OnKeyEvent:Void(event:mojo.app.KeyEvent)","/Users/simon/nitrologic/m2/vpaint/vpaint.monkey2"};
  t_default_VPaint*self=this;
  bbDBLocal("Self",&self);
  bbDBLocal("event",&l_event);
  bbInt l_0=l_event->m_Type();
  bbDBLocal("0",&l_0);
  bbDBStmt(1355778);
  if(l_0==0){
    bbDBBlock db_blk;
    bbInt l_1=l_event->m_Key();
    bbDBLocal("1",&l_1);
    bbDBStmt(1363971);
    if(l_1==116){
      bbDBBlock db_blk;
      bbDBStmt(1372164);
      if(this->m_tool==1){
        bbDBBlock db_blk;
        bbDBStmt(1380357);
        this->m_tool=0;
      }else if(this->m_tool==0){
        bbDBBlock db_blk;
        bbDBStmt(1388549);
        this->m_tool=1;
      }
    }else if(l_1==115){
      bbDBBlock db_blk;
      bbDBStmt(1400836);
      this->m_pane->m_Smile(bbFloat(this->m_mousex),bbFloat(this->m_mousey),this->m_radius);
      bbDBStmt(1404932);
      this->m_pane->m_Circle(bbFloat(this->m_mousex),bbFloat(this->m_mousey),this->m_radius);
    }else if(l_1==99){
      bbDBBlock db_blk;
      bbDBStmt(1413124);
      this->m_pane->m_Clear(this->m_ink);
    }else if(l_1==27){
      bbDBBlock db_blk;
      bbDBStmt(1421316);
      g_default_instance->m_Terminate();
    }else if(l_1==129){
      bbDBBlock db_blk;
      bbDBStmt(1429508);
      this->m_Fullscreen(!this->m_Fullscreen());
    }else if(l_1==130){
      bbDBBlock db_blk;
      bbDBStmt(1437700);
      this->m_ToggleTwo();
    }else if(l_1==32){
      bbDBBlock db_blk;
      bbDBStmt(1445892);
      this->m_Hold();
      bbDBStmt(1449988);
      this->m_pane->m_EndSegment();
    }
    bbDBStmt(1462275);
    if(bbBool((l_event->m_Modifiers()&this->m_CommandKey))){
      bbDBBlock db_blk;
      bbInt l_2=l_event->m_Key();
      bbDBLocal("2",&l_2);
      bbDBStmt(1466372);
      if(l_2==151){
        bbDBBlock db_blk;
        bbDBStmt(1474565);
        this->m_panxSpeed+=(1.0f/4.0f);
      }else if(l_2==150){
        bbDBBlock db_blk;
        bbDBStmt(1482757);
        this->m_panxSpeed-=(1.0f/4.0f);
      }else if(l_2==152){
        bbDBBlock db_blk;
        bbDBStmt(1490949);
        this->m_panySpeed+=(1.0f/4.0f);
      }else if(l_2==153){
        bbDBBlock db_blk;
        bbDBStmt(1499141);
        this->m_panySpeed-=(1.0f/4.0f);
      }
    }else{
      bbDBStmt(1507331);
      bbDBBlock db_blk;
      bbInt l_3=l_event->m_Key();
      bbDBLocal("3",&l_3);
      bbDBStmt(1511428);
      if(l_3==151){
        bbDBBlock db_blk;
        bbDBStmt(1519621);
        this->m_rotSpeed+=(1.0f/16.0f);
      }else if(l_3==150){
        bbDBBlock db_blk;
        bbDBStmt(1527813);
        this->m_rotSpeed-=(1.0f/16.0f);
      }else if(l_3==152){
        bbDBBlock db_blk;
        bbDBStmt(1536005);
        this->m_radius*=0.8f;
      }else if(l_3==153){
        bbDBBlock db_blk;
        bbDBStmt(1544197);
        this->m_radius*=1.2f;
      }
    }
  }
  bbDBStmt(1564674);
  this->m_RefreshTitle();
}

void t_default_VPaint::m_Hold(){
  bbDBFrame db_f{"Hold:Void()","/Users/simon/nitrologic/m2/vpaint/vpaint.monkey2"};
  t_default_VPaint*self=this;
  bbDBLocal("Self",&self);
  bbDBStmt(1310722);
  this->m_rotSpeed=0.0f;
  bbDBStmt(1314818);
  this->m_rot=0.0f;
  bbDBStmt(1318914);
  this->m_panxSpeed=0.0f;
  bbDBStmt(1323010);
  this->m_panySpeed=0.0f;
  bbDBStmt(1327106);
  this->m_panx=0.0f;
  bbDBStmt(1331202);
  this->m_pany=0.0f;
}

void t_default_VPaint::m_DrawMode(){
  bbDBFrame db_f{"DrawMode:Void()","/Users/simon/nitrologic/m2/vpaint/vpaint.monkey2"};
  t_default_VPaint*self=this;
  bbDBLocal("Self",&self);
  bbDBStmt(1597442);
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
  g_default_title=BB_T("VPaint 0.2 Beta-Testers-Deployment-One Release");
  g_default_AboutApp=BB_T("VPaint Control,,Cursor Left=-RPM,Cursor Right=+RPM,,Mouse Button=Lift Pen,Mouse Wheel=Zoom,Space Key=Hold,S Key=Smile Box,C Key=Clear,Cursor Up=+Pen Size,Cursor Down=-Pen Size,Hold,F1=Toggle Fullscreen,Click To Start");
  g_default_Contact=BB_T(",,Latest Source: github.com/nitrologic/m2/tree/master/vpaint");
  g_default_Credits=BB_T(",,Machine translated by Monkey2 the primate language of champions.");
  g_default_TickMark=bbString::fromChar(65);
}

bbInit mx2_vpaint_vpaint_init_v("vpaint_vpaint",&mx2_vpaint_vpaint_init);
