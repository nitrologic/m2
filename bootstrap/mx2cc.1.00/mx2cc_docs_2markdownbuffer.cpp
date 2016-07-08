
#include "mx2cc_docs_2markdownbuffer.h"

// ***** External *****

#include "mx2cc_docs_2jsonbuffer.h"
#include "../../../../../modules/std/std.buildv1.0.0/desktop_release_linux/std_collections_2stack.h"

extern bbBool g_std_stringio_IsIdent(bbInt l_chr);
extern bbString g_hoedown_MarkdownToHtml(bbString l_markdown,bbBool l_toc);

// ***** Internal *****

bbString g_mx2_docs_Slugify(bbString l_str){
  bbInt l_st=bbInt(0);
  while(((l_st<l_str.length())&&!g_std_stringio_IsIdent(l_str[l_st]))){
    l_st+=1;
  }
  bbInt l_en=l_str.length();
  while(((l_en>l_st)&&!g_std_stringio_IsIdent(l_str[(l_en-1)]))){
    l_en-=1;
  }
  bbString l_out=bbString{};
  {
    bbInt l_i=l_st;
    for(;(l_i<l_en);l_i+=1){
      bbInt l_chr=l_str[l_i];
      if(g_std_stringio_IsIdent(l_chr)){
        l_out+=bbString::fromChar(l_chr).toLower();
        continue;
      }
      l_out+=BB_T("-");
    }
  }
  return l_out;
}

void t_mx2_docs_MarkdownBuffer::init(){
  m__0buf=bbGCNew<t_std_collections_Stack_1s>();
  m__0params=bbGCNew<t_std_collections_Stack_1s>();
  m__0toc=bbGCNew<t_mx2_docs_JsonBuffer>();
}

void t_mx2_docs_MarkdownBuffer::gcMark(){
  bbGCMark(m__0linkResolver);
  bbGCMark(m__0buf);
  bbGCMark(m__0params);
  bbGCMark(m__0toc);
}

t_mx2_docs_MarkdownBuffer::t_mx2_docs_MarkdownBuffer(bbFunction<bbString(bbString)> l_linkResolver){
  init();
  this->m__0linkResolver=l_linkResolver;
}

bbString t_mx2_docs_MarkdownBuffer::m_ReplaceLinks(bbString l_line){
  for(;;){
    bbInt l_i0=l_line.find(BB_T("[["),bbInt(0));
    if((l_i0==-1)){
      return l_line;
    }
    bbInt l_i1=l_line.find(BB_T("]]"),(l_i0+2));
    if((l_i1==-1)){
      return l_line;
    }
    bbString l_path=l_line.slice((l_i0+2),l_i1);
    bbString l_link=l_path;
    if((this->m__0linkResolver!=bbFunction<bbString(bbString)>{})){
      l_link=this->m__0linkResolver(l_path);
      if(!bbBool(l_link)){
        puts(((BB_T("Makedocs error: Can't resolve link '")+l_path)+BB_T("'")).c_str());fflush( stdout );
        l_link=l_path;
      }
    }
    l_line=((l_line.slice(bbInt(0),l_i0)+l_link)+l_line.slice((l_i1+2)));
  }
  return l_line;
}

bbString t_mx2_docs_MarkdownBuffer::m_Label(){
  return this->m__0label;
}

bbString t_mx2_docs_MarkdownBuffer::m_Flush(){
  if(bbBool(this->m__0params->m_Length())){
    this->m_EmitBr();
    this->m_Emit(BB_T("| Parameters |    |"));
    this->m_Emit(BB_T("|:-----------|:---|"));
    {
      struct f2_t : public bbGCFrame{
        t_std_collections_Stack_1s_Iterator l_0{};
        void gcMark(){
          bbGCMark(l_0);
        }
      }f2{};
      f2.l_0=this->m__0params->m_All();
      for(;!f2.l_0.m_AtEnd();f2.l_0.m_Bump()){
        bbString l_p=f2.l_0.m_Current();
        bbInt l_i=this->m_FindSpc(l_p);
        bbString l_id=l_p.slice(bbInt(0),l_i);
        l_p=l_p.slice(l_i).trim();
        if((!bbBool(l_id)||!bbBool(l_p))){
          continue;
        }
        this->m_Emit(((((BB_T("| `")+l_id)+BB_T("` | "))+l_p)+BB_T(" |")));
      }
    }
    this->m__0params->m_Clear();
  }
  bbString l_markdown=(this->m__0buf->m_Join(BB_T("\n")).trim()+BB_T("\n"));
  this->m__0buf->m_Clear();
  this->m__0return=bbString{};
  this->m__0label=bbString{};
  bbString l_docs=g_hoedown_MarkdownToHtml(l_markdown,false);
  return l_docs;
}

bbInt t_mx2_docs_MarkdownBuffer::m_FindSpc(bbString l_str){
  {
    bbInt l_i=bbInt(0);
    for(;(l_i<l_str.length());l_i+=1){
      if((l_str[l_i]<=32)){
        return l_i;
      }
    }
  }
  return l_str.length();
}

bbInt t_mx2_docs_MarkdownBuffer::m_FindChar(bbString l_str){
  {
    bbInt l_i=bbInt(0);
    for(;(l_i<l_str.length());l_i+=1){
      if((l_str[l_i]>32)){
        return l_i;
      }
    }
  }
  return -1;
}

void t_mx2_docs_MarkdownBuffer::m_EmitBr(){
  this->m__0buf->m_Push(bbString{});
}

void t_mx2_docs_MarkdownBuffer::m_Emit(bbString l_markdown){
  struct f0_t : public bbGCFrame{
    bbArray<bbString>* l_lines{};
    void gcMark(){
      bbGCMarkPtr(l_lines);
    }
  }f0{};
  if(!l_markdown.contains(BB_T("\n"))){
    this->m__0buf->m_Push(this->m_ReplaceLinks(l_markdown));
    return;
  }
  f0.l_lines=l_markdown.split(BB_T("\n"));
  {
    bbInt l_i=bbInt(0);
    for(;(l_i<f0.l_lines->length());l_i+=1){
      bbString l_line=f0.l_lines->at(l_i).trim();
      if(l_line.startsWith(BB_T("@"))){
        bbInt l_j=this->m_FindSpc(l_line);
        bbString l_id=l_line.slice(1,l_j);
        l_line=l_line.slice(l_j).trim();
        if(l_id==BB_T("label")){
          this->m__0label=l_line;
        }else if(l_id==BB_T("param")){
          this->m__0params->m_Push(l_line);
        }else if(l_id==BB_T("return")){
          this->m__0return=l_line;
        }else if(l_id==BB_T("example")){
          struct f4_t : public bbGCFrame{
            t_std_collections_Stack_1s* l_buf{};
            void gcMark(){
              bbGCMarkPtr(l_buf);
            }
          }f4{};
          bbInt l_indent=this->m_FindChar(f0.l_lines->at(l_i));
          l_i+=1;
          this->m__0buf->m_Push(BB_T("```"));
          f4.l_buf=bbGCNew<t_std_collections_Stack_1s>();
          while((l_i<f0.l_lines->length())){
            bbString l_line=f0.l_lines->at(l_i);
            if(l_line.trim().startsWith(BB_T("@end"))){
              break;
            }
            l_i+=1;
            l_line=l_line.slice(l_indent);
            if(l_line.startsWith(BB_T("\\#"))){
              l_line=l_line.slice(1);
            }
            f4.l_buf->m_Push(l_line);
          }
          this->m__0buf->m_Push(f4.l_buf->m_Join(BB_T("\n")).trim());
          this->m__0buf->m_Push(BB_T("```"));
        }else if(l_id==BB_T("see")){
          continue;
        }else{
          puts(((BB_T("MarkdownBuffer: unrecognized '")+f0.l_lines->at(l_i))+BB_T("'")).c_str());fflush( stdout );
        }
        continue;
      }
      this->m__0buf->m_Push(this->m_ReplaceLinks(l_line));
    }
  }
}

void mx2_mx2cc_docs_2markdownbuffer_init(){
  static bool done;
  if(done) return;
  done=true;
}

bbInit mx2_mx2cc_docs_2markdownbuffer_init_v("mx2cc_docs_2markdownbuffer",&mx2_mx2cc_docs_2markdownbuffer_init);
