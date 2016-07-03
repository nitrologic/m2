
#ifndef MX2_MX2CC_DOCS_2MARKDOWNBUFFER_H
#define MX2_MX2CC_DOCS_2MARKDOWNBUFFER_H

#include <bbmonkey.h>

// ***** External *****

#include "../../../../../modules/monkey/monkey.buildv1.0.0/desktop_release_linux/monkey_types.h"

struct t_std_collections_Stack_1s;
struct t_mx2_docs_JsonBuffer;

// ***** Internal *****

struct t_mx2_docs_MarkdownBuffer;

extern bbString g_mx2_docs_Slugify(bbString l_str);

struct t_mx2_docs_MarkdownBuffer : public bbObject{

  const char *typeName()const{return "t_mx2_docs_MarkdownBuffer";}

  bbFunction<bbString(bbString)> m__0linkResolver{};
  bbGCVar<t_std_collections_Stack_1s> m__0buf{};
  bbGCVar<t_std_collections_Stack_1s> m__0params{};
  bbString m__0return{};
  bbString m__0label{};
  bbGCVar<t_mx2_docs_JsonBuffer> m__0toc{};
  bbInt m__0tocNest{};

  void init();

  void gcMark();

  t_mx2_docs_MarkdownBuffer(bbFunction<bbString(bbString)> l_linkResolver);

  bbString m_ReplaceLinks(bbString l_line);
  bbString m_Label();
  bbString m_Flush();
  bbInt m_FindSpc(bbString l_str);
  bbInt m_FindChar(bbString l_str);
  void m_EmitBr();
  void m_Emit(bbString l_markdown);

  t_mx2_docs_MarkdownBuffer(){
    init();
  }
};

#endif
