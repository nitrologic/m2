
#include "vpaint_vpaint.h"

// ***** External *****

#include "../../../../../../monkey2/modules/mojo/mojo.buildv010/desktop_release_macos/mojo_app_2app.h"
#include "../../../../../../monkey2/modules/mojo/mojo.buildv010/desktop_release_macos/mojo_app_2event.h"
#include "../../../../../../monkey2/modules/mojo/mojo.buildv010/desktop_release_macos/mojo_app_2view.h"
#include "../../../../../../monkey2/modules/mojo/mojo.buildv010/desktop_release_macos/mojo_audio_2audio.h"
#include "../../../../../../monkey2/modules/mojo/mojo.buildv010/desktop_release_macos/mojo_graphics_2canvas.h"
#include "../../../../../../monkey2/modules/monkey/monkey.buildv010/desktop_release_macos/monkey_math.h"
#include "../../../../../../monkey2/modules/std/std.buildv010/desktop_release_macos/std_graphics_2pixmap.h"
#include "../../../../../../monkey2/modules/std/std.buildv010/desktop_release_macos/std_stream_2filestream.h"

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
      bbGCMark(l_verts);
    }
  }f0{};
  f0.l_verts=bbArray<bbFloat>::create(((l_seg+1)*2));
  {
    bbInt l_i=bbInt(0);
    for(;(l_i<=l_seg);l_i+=1){
      bbFloat l_mu=((bbFloat(l_i)*1.0f)/bbFloat(l_seg));
      bbFloat l_x=g_default_VPane_CatmullInterpolate(l_p0.m_x,l_p1.m_x,l_p2.m_x,l_p3.m_x,l_mu);
      bbFloat l_y=g_default_VPane_CatmullInterpolate(l_p0.m_y,l_p1.m_y,l_p2.m_y,l_p3.m_y,l_mu);
      f0.l_verts->at(((l_i*2)+bbInt(0)))=l_x;
      f0.l_verts->at(((l_i*2)+1))=l_y;
    }
  }
  return f0.l_verts;
}

bbFloat g_default_VPane_CubicInterpolate2(bbFloat l_p0,bbFloat l_p1,bbFloat l_p2,bbFloat l_p3,bbFloat l_x){
  return (l_p1+((0.5f*l_x)*((l_p2-l_p0)+(l_x*(((((2.0f*l_p0)-(5.0f*l_p1))+(4.0f*l_p2))-l_p3)+(l_x*(((3.0f*(l_p1-l_p2))+l_p3)-l_p0)))))));
}

bbFloat g_default_VPane_CubicInterpolate(bbFloat l_y0,bbFloat l_y1,bbFloat l_y2,bbFloat l_y3,bbFloat l_mu){
  bbFloat l_a0{};
  bbFloat l_a1{};
  bbFloat l_a2{};
  bbFloat l_a3{};
  bbFloat l_mu2{};
  l_mu2=(l_mu*l_mu);
  l_a0=(((l_y3-l_y2)-l_y0)+l_y1);
  l_a1=((l_y0-l_y1)-l_a0);
  l_a2=(l_y2-l_y0);
  l_a3=l_y1;
  return (((((l_a0*l_mu)*l_mu2)+(l_a1*l_mu2))+(l_a2*l_mu))+l_a3);
}

bbFloat g_default_VPane_CatmullInterpolate(bbFloat l_y0,bbFloat l_y1,bbFloat l_y2,bbFloat l_y3,bbFloat l_mu){
  bbFloat l_a0{};
  bbFloat l_a1{};
  bbFloat l_a2{};
  bbFloat l_a3{};
  bbFloat l_mu2{};
  l_mu2=(l_mu*l_mu);
  l_a0=((((-0.5f*l_y0)+(1.5f*l_y1))-(1.5f*l_y2))+(0.5f*l_y3));
  l_a1=(((l_y0-(2.5f*l_y1))+(2.0f*l_y2))-(0.5f*l_y3));
  l_a2=((-0.5f*l_y0)+(0.5f*l_y2));
  l_a3=l_y1;
  return (((((l_a0*l_mu)*l_mu2)+(l_a1*l_mu2))+(l_a2*l_mu))+l_a3);
}

void g_default_SaveTGA(bbString l_path,t_std_graphics_Pixmap* l_pixmap){
  struct f0_t : public bbGCFrame{
    bbArray<bbByte>* l_buffer{};
    t_std_stream_FileStream* l_stream{};
    void gcMark(){
      bbGCMark(l_buffer);
      bbGCMark(l_stream);
    }
  }f0{};
  f0.l_stream=g_std_stream_FileStream_Open(l_path,BB_T("w"));
  f0.l_buffer=bbArray<bbByte>::create(18);
  bbInt l_w=l_pixmap->m_Width();
  bbInt l_h=l_pixmap->m_Height();
  f0.l_buffer->at(2)=2;
  f0.l_buffer->at(12)=bbByte((l_w&255));
  f0.l_buffer->at(13)=bbByte((l_w>>8));
  f0.l_buffer->at(14)=bbByte((l_h&255));
  f0.l_buffer->at(15)=bbByte((l_h>>8));
  f0.l_buffer->at(16)=32;
  f0.l_buffer->at(17)=8;
  f0.l_stream->m_Write(((void*)(&f0.l_buffer->at(bbInt(0)))),18);
  f0.l_stream->m_Write(((void*)(l_pixmap->m_Data())),((l_w*l_h)*4));
  f0.l_stream->m_Close();
}

void bbMain(){
  static bool done;
  if(done) return;
  done=true;
  void mx2_mojo_main();mx2_mojo_main();
  void mx2_std_main();mx2_std_main();
  puts(g_default_title.c_str());fflush( stdout );
  g_default_instance=bbGCNew<t_mojo_app_AppInstance>();
  bbGCNew<t_default_VPaint>(g_default_title);
  g_mojo_app_App->m_Run();
}

void t_default_VPane::gcMark(){
  t_mojo_graphics_Image::gcMark();
  bbGCMark(m_canvas);
  bbGCMark(m_pixmap);
}

t_default_VPane::t_default_VPane(bbInt l_w,bbInt l_h,t_std_graphics_Color l_bg):t_mojo_graphics_Image(l_w,l_h,4099,((t_mojo_graphics_Shader*)0)){
  this->m_canvas=bbGCNew<t_mojo_graphics_Canvas>(((t_mojo_graphics_Image*)(this)));
  this->m_canvas->m_Clear(l_bg);
  this->m_canvas->m_Alpha(0.8f);
  this->m_canvas->m_Translate(bbFloat((l_w/2)),bbFloat((l_h/2)));
  this->m_Handle(t_std_geom_Vec2_1f(0.5f,0.5f));
}

void t_default_VPane::m_StraightLine(bbInt l_x,bbInt l_y,bbInt l_x1,bbInt l_y1,bbFloat l_fat){
  if(!bbBool(this->m_canvas)){
    return;
  }
  bbInt l_dy=(l_y1-l_y);
  bbInt l_dx=(l_x1-l_x);
  bbFloat l_len=bbFloat(std::sqrt(bbDouble(((l_dx*l_dx)+(l_dy*l_dy)))));
  bbFloat l_q=(l_fat/l_len);
  t_std_geom_Vec2_1f l_v0=t_std_geom_Vec2_1f((bbFloat(l_x)+(bbFloat(l_dy)*l_q)),(bbFloat(l_y)-(bbFloat(l_dx)*l_q)));
  t_std_geom_Vec2_1f l_v1=t_std_geom_Vec2_1f((bbFloat(l_x1)+(bbFloat(l_dy)*l_q)),(bbFloat(l_y1)-(bbFloat(l_dx)*l_q)));
  t_std_geom_Vec2_1f l_v2=t_std_geom_Vec2_1f((bbFloat(l_x1)-(bbFloat(l_dy)*l_q)),(bbFloat(l_y1)+(bbFloat(l_dx)*l_q)));
  t_std_geom_Vec2_1f l_v3=t_std_geom_Vec2_1f((bbFloat(l_x)-(bbFloat(l_dy)*l_q)),(bbFloat(l_y)+(bbFloat(l_dx)*l_q)));
  this->m_canvas->m_DrawTriangle(l_v0,l_v1,l_v2);
  this->m_canvas->m_DrawTriangle(l_v0,l_v2,l_v3);
}

void t_default_VPane::m_Smile(bbFloat l_x,bbFloat l_y,bbFloat l_r){
  t_std_geom_Vec2_1f l_v0=t_std_geom_Vec2_1f((l_x-100.0f),(l_y+100.0f));
  t_std_geom_Vec2_1f l_v1=t_std_geom_Vec2_1f((l_x-100.0f),(l_y-20.0f));
  t_std_geom_Vec2_1f l_v2=t_std_geom_Vec2_1f((l_x+100.0f),(l_y-20.0f));
  t_std_geom_Vec2_1f l_v3=t_std_geom_Vec2_1f((l_x+100.0f),(l_y+100.0f));
  this->m_EndSegment();
  this->m_OpenCurve(l_v0,l_v1,l_v2,l_v3,l_r);
  this->m_EndSegment();
}

void t_default_VPane::m_OpenCurve(t_std_geom_Vec2_1f l_p0,t_std_geom_Vec2_1f l_p1,t_std_geom_Vec2_1f l_p2,t_std_geom_Vec2_1f l_p3,bbFloat l_fat){
  struct f0_t : public bbGCFrame{
    bbArray<bbFloat>* l_verts{};
    void gcMark(){
      bbGCMark(l_verts);
    }
  }f0{};
  if(!bbBool(this->m_canvas)){
    return;
  }
  bbInt l_seg=9;
  f0.l_verts=g_default_VPane_Curve(l_seg,l_p0,l_p1,l_p2,l_p3);
  {
    bbInt l_i=bbInt(0);
    for(;(l_i<l_seg);l_i+=1){
      this->m_FatSegment(f0.l_verts->at(((l_i*2)+bbInt(0))),f0.l_verts->at(((l_i*2)+1)),f0.l_verts->at(((l_i*2)+2)),f0.l_verts->at(((l_i*2)+3)),l_fat);
    }
  }
}

void t_default_VPane::m_FatSegment(bbFloat l_x,bbFloat l_y,bbFloat l_x1,bbFloat l_y1,bbFloat l_fat){
  struct f0_t : public bbGCFrame{
    bbArray<bbFloat>* l_verts{};
    void gcMark(){
      bbGCMark(l_verts);
    }
  }f0{};
  if(!bbBool(this->m_canvas)){
    return;
  }
  f0.l_verts=bbArray<bbFloat>::create(8);
  bbFloat l_dy=(l_y1-l_y);
  bbFloat l_dx=(l_x1-l_x);
  bbFloat l_len=bbFloat(std::sqrt(bbDouble(((l_dx*l_dx)+(l_dy*l_dy)))));
  bbFloat l_q=(l_fat/l_len);
  if((this->m_segcount==bbInt(0))){
    this->m_edge0=t_std_geom_Vec2_1f((l_x+(l_dy*l_q)),(l_y-(l_dx*l_q)));
    this->m_edge1=t_std_geom_Vec2_1f((l_x-(l_dy*l_q)),(l_y+(l_dx*l_q)));
  }
  this->m_segcount+=1;
  t_std_geom_Vec2_1f l_v0=this->m_edge0;
  t_std_geom_Vec2_1f l_v1=t_std_geom_Vec2_1f((l_x1+(l_dy*l_q)),(l_y1-(l_dx*l_q)));
  t_std_geom_Vec2_1f l_v2=t_std_geom_Vec2_1f((l_x1-(l_dy*l_q)),(l_y1+(l_dx*l_q)));
  t_std_geom_Vec2_1f l_v3=this->m_edge1;
  this->m_canvas->m_DrawTriangle(l_v0,l_v1,l_v2);
  this->m_canvas->m_DrawTriangle(l_v0,l_v2,l_v3);
  this->m_edge0=l_v1;
  this->m_edge1=l_v2;
}

void t_default_VPane::m_EndSegment(){
  this->m_segcount=bbInt(0);
}

void t_default_VPane::m_Draw(t_mojo_graphics_Canvas* l_display){
  this->m_canvas->m_Flush();
  l_display->m_DrawImage(((t_mojo_graphics_Image*)(this)),0.0f,0.0f);
}

void t_default_VPane::m_ClosedCurve(t_std_geom_Vec2_1f l_p0,t_std_geom_Vec2_1f l_p1,t_std_geom_Vec2_1f l_p2,t_std_geom_Vec2_1f l_p3,bbFloat l_fat){
  if(!bbBool(this->m_canvas)){
    return;
  }
  this->m_OpenCurve(l_p3,l_p0,l_p1,l_p2,l_fat);
  this->m_OpenCurve(l_p0,l_p1,l_p2,l_p3,l_fat);
  this->m_OpenCurve(l_p1,l_p2,l_p3,l_p0,l_fat);
  this->m_OpenCurve(l_p2,l_p3,l_p0,l_p1,l_fat);
  this->m_EndSegment();
}

void t_default_VPane::m_Clear(t_std_graphics_Color l_bg){
  this->m_canvas->m_Clear(l_bg);
}

void t_default_VPane::m_Circle(bbFloat l_x,bbFloat l_y,bbFloat l_r){
  t_std_geom_Vec2_1f l_v0=t_std_geom_Vec2_1f((l_x-100.0f),(l_y-100.0f));
  t_std_geom_Vec2_1f l_v1=t_std_geom_Vec2_1f((l_x+100.0f),(l_y-100.0f));
  t_std_geom_Vec2_1f l_v2=t_std_geom_Vec2_1f((l_x+100.0f),(l_y+100.0f));
  t_std_geom_Vec2_1f l_v3=t_std_geom_Vec2_1f((l_x-100.0f),(l_y+100.0f));
  this->m_EndSegment();
  this->m_ClosedCurve(l_v0,l_v1,l_v2,l_v3,l_r);
}

t_default_VToolbar::t_default_VToolbar(bbString l_title):t_mojo_app_Window(l_title,480,34,8){
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

t_default_VPaint::t_default_VPaint(bbString l_title):t_mojo_app_Window(l_title,720,560,8){
  init();
  this->m_zoom=2.0f;
  this->m_pane=bbGCNew<t_default_VPane>(4096,4096,g_std_graphics_Color_Black);
  this->m_browse=bbGCNew<t_default_VBrowse>();
  this->m_ink=t_std_graphics_Color(1.0f);
  this->m_radius=2.5f;
  this->m_sample=g_mojo_audio_Sound_Load(BB_T("assets/whale52hz.wav"));
  this->m_wheel=this->m_sample->m_Play(1);
}

void t_default_VPaint::m_ToggleTwo(){
}

void t_default_VPaint::m_RefreshTitle(){
  bbFloat l_r=((this->m_rotSpeed*this->m_rotSpeed)*this->m_rotSpeed);
  bbFloat l_rpm=bbFloat(g_monkey_math_Abs_1d((bbDouble((3600.0f*l_r))/(g_monkey_math_Pi*2.0))));
  bbInt l_velocity=bbInt((100.0*std::sqrt(bbDouble(((this->m_panxSpeed*this->m_panxSpeed)+(this->m_panySpeed*this->m_panySpeed))))));
  bbString l_tooltype=BB_T("Line");
  if((this->m_tool==1)){
    l_tooltype=BB_T("Curve");
  }
  this->m_Title((((((((BB_T("RPM ")+bbString(l_rpm))+BB_T(" Pan="))+bbString(l_velocity))+BB_T(" Tip="))+bbString(bbInt((this->m_radius*100.0f))))+BB_T(" Tool="))+l_tooltype));
  this->m_titleCount=200;
}

void t_default_VPaint::m_OnRender(t_mojo_graphics_Canvas* l_display){
  g_mojo_app_App->m_RequestRender();
  if(this->m_appState==0){
    bbInt l_cy=40;
    {
      struct f2_t : public bbGCFrame{
        bbArray<bbString>* l_0{};
        void gcMark(){
          bbGCMark(l_0);
        }
      }f2{};
      f2.l_0=((((g_default_AboutApp+BB_T(","))+g_default_Contact)+BB_T(","))+g_default_Credits).split(BB_T(","));
      bbInt l_1=bbInt(0);
      bbInt l_2=f2.l_0->length();
      for(;(l_1<l_2);l_1+=1){
        bbString l_line=f2.l_0->at(l_1);
        bbInt l_cx=50;
        {
          struct f4_t : public bbGCFrame{
            bbArray<bbString>* l_3{};
            void gcMark(){
              bbGCMark(l_3);
            }
          }f4{};
          f4.l_3=l_line.split(BB_T("="));
          bbInt l_4=bbInt(0);
          bbInt l_5=f4.l_3->length();
          for(;(l_4<l_5);l_4+=1){
            bbString l_tab=f4.l_3->at(l_4);
            l_display->m_DrawText(l_tab,bbFloat(l_cx),bbFloat(l_cy),0.0f,0.0f);
            l_cx+=120;
          }
        }
        l_cy+=20;
      }
    }
  }else if(this->m_appState==1){
    this->m_rot+=((this->m_rotSpeed*this->m_rotSpeed)*this->m_rotSpeed);
    this->m_panx+=this->m_panxSpeed;
    this->m_pany+=this->m_panySpeed;
    if(((bbBool(this->m_rotSpeed)||bbBool(this->m_panxSpeed))||bbBool(this->m_panySpeed))){
      this->m_OnMouseEvent(this->m_recentMouseEvent);
    }
    l_display->m_PushMatrix();
    this->m_cx=(bbFloat((this->m_Width()/2))-this->m_panx);
    this->m_cy=(bbFloat((this->m_Height()/2))-this->m_pany);
    l_display->m_Translate(this->m_cx,this->m_cy);
    bbFloat l_scale=(-1.0f/this->m_zoom);
    l_display->m_Scale(l_scale,l_scale);
    l_display->m_Rotate(this->m_rot);
    this->m_pane->m_Draw(l_display);
    this->m_framecount+=1;
    this->m_ink.m_r=(bbFloat((this->m_framecount&255))/255.0f);
    this->m_ink.m_g=(bbFloat((this->m_framecount&1023))/1023.0f);
    this->m_ink.m_b=(bbFloat((this->m_framecount&511))/511.0f);
    this->m_pane->m_canvas->m_Color(this->m_ink);
    l_display->m_PopMatrix();
  }else if(this->m_appState==2){
  }
  if(((this->m_titleCount>bbInt(0))&&this->m_Fullscreen())){
    l_display->m_DrawText(this->m_Title(),20.0f,20.0f,0.0f,0.0f);
    this->m_titleCount-=1;
  }
}

void t_default_VPaint::m_OnMouseEvent(t_mojo_app_MouseEvent* l_event){
  if((this->m_appState==0)){
    if((l_event->m_Type()==4)){
      this->m_DrawMode();
    }
    return;
  }
  if((l_event==((t_mojo_app_MouseEvent*)0))){
    return;
  }
  bbInt l_mx=l_event->m_Location().m_X();
  bbInt l_my=l_event->m_Location().m_Y();
  bbInt l_b=bbInt(l_event->m_Button());
  l_mx=bbInt(((bbFloat(l_mx)-this->m_cx)*this->m_zoom));
  l_my=bbInt(((bbFloat(l_my)-this->m_cy)*this->m_zoom));
  bbDouble l_x=((-std::cos(bbDouble(this->m_rot))*bbDouble(l_mx))+(std::sin(bbDouble(this->m_rot))*bbDouble(l_my)));
  bbDouble l_y=((-std::sin(bbDouble(this->m_rot))*bbDouble(l_mx))-(std::cos(bbDouble(this->m_rot))*bbDouble(l_my)));
  bbInt l_w{};
  if((this->m_recentMouseEvent!=l_event)){
    l_w=l_event->m_Wheel().m_Y();
  }
  if((((bbDouble(this->m_mousex)==l_x)&&(bbDouble(this->m_mousey)==l_y))&&(this->m_mousew==l_w))){
    return;
  }
  this->m_recentMouseEvent=l_event;
  bbInt l_0=l_event->m_Type();
  if(l_0==7){
    this->m_zoom-=(bbFloat(l_w)/8.0f);
    if((this->m_zoom<(1.0f/8.0f))){
      this->m_zoom=(1.0f/8.0f);
    }
  }else if(l_0==5){
    this->m_pane->m_EndSegment();
    this->m_drawcount=bbInt(0);
  }else if(l_0==4){
    this->m_pane->m_EndSegment();
    this->m_drawcount=bbInt(0);
  }
  this->m_history->at(bbInt(0))=this->m_history->at(1);
  this->m_history->at(1)=this->m_history->at(2);
  this->m_history->at(2)=this->m_history->at(3);
  this->m_history->at(3)=t_std_geom_Vec2_1f(bbFloat(l_x),bbFloat(l_y));
  if(this->m_tool==0){
    if(bbBool(this->m_drawcount)){
      this->m_pane->m_StraightLine(this->m_mousex,this->m_mousey,bbInt(l_x),bbInt(l_y),this->m_radius);
    }
  }else if(this->m_tool==1){
    if(((this->m_drawcount>3)&&!bbBool(l_b))){
      this->m_pane->m_OpenCurve(this->m_history->at(bbInt(0)),this->m_history->at(1),this->m_history->at(2),this->m_history->at(3),this->m_radius);
    }
  }
  this->m_drawcount+=1;
  this->m_mousex=bbInt(l_x);
  this->m_mousey=bbInt(l_y);
  this->m_mousew=l_w;
  this->m_mousecount+=1;
}

void t_default_VPaint::m_OnKeyEvent(t_mojo_app_KeyEvent* l_event){
  bbInt l_0=l_event->m_Type();
  if(l_0==0){
    bbInt l_1=l_event->m_Key();
    if(l_1==116){
      if(this->m_tool==1){
        this->m_tool=0;
      }else if(this->m_tool==0){
        this->m_tool=1;
      }
    }else if(l_1==115){
      this->m_pane->m_Smile(bbFloat(this->m_mousex),bbFloat(this->m_mousey),this->m_radius);
      this->m_pane->m_Circle(bbFloat(this->m_mousex),bbFloat(this->m_mousey),this->m_radius);
    }else if(l_1==99){
      this->m_pane->m_Clear(this->m_ink);
    }else if(l_1==27){
      g_default_instance->m_Terminate();
    }else if(l_1==129){
      this->m_Fullscreen(!this->m_Fullscreen());
    }else if(l_1==130){
      this->m_ToggleTwo();
    }else if(l_1==32){
      this->m_Hold();
      this->m_pane->m_EndSegment();
    }
    if(bbBool((l_event->m_Modifiers()&this->m_CommandKey))){
      bbInt l_2=l_event->m_Key();
      if(l_2==151){
        this->m_panxSpeed+=(1.0f/4.0f);
      }else if(l_2==150){
        this->m_panxSpeed-=(1.0f/4.0f);
      }else if(l_2==152){
        this->m_panySpeed+=(1.0f/4.0f);
      }else if(l_2==153){
        this->m_panySpeed-=(1.0f/4.0f);
      }
    }else{
      bbInt l_3=l_event->m_Key();
      if(l_3==151){
        this->m_rotSpeed+=(1.0f/16.0f);
      }else if(l_3==150){
        this->m_rotSpeed-=(1.0f/16.0f);
      }else if(l_3==152){
        this->m_radius*=0.8f;
      }else if(l_3==153){
        this->m_radius*=1.2f;
      }
    }
  }
  this->m_RefreshTitle();
}

void t_default_VPaint::m_Hold(){
  this->m_rotSpeed=0.0f;
  this->m_rot=0.0f;
  this->m_panxSpeed=0.0f;
  this->m_panySpeed=0.0f;
  this->m_panx=0.0f;
  this->m_pany=0.0f;
}

void t_default_VPaint::m_DrawMode(){
  this->m_appState=1;
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
