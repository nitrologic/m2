
#include "mx2cc_docs_2docsmaker.h"

// ***** External *****

#include "../../../../../modules/monkey/monkey.buildv1.0.0/desktop_release_linux/monkey_debug.h"
#include "mx2cc_alias.h"
#include "mx2cc_class.h"
#include "mx2cc_decl.h"
#include "mx2cc_docs_2jsonbuffer.h"
#include "mx2cc_docs_2markdownbuffer.h"
#include "mx2cc_enum.h"
#include "mx2cc_errors.h"
#include "mx2cc_expr.h"
#include "mx2cc_func.h"
#include "mx2cc_module.h"
#include "mx2cc_namespace.h"
#include "mx2cc_node.h"
#include "mx2cc_property.h"
#include "mx2cc_scope.h"
#include "mx2cc_std_collections_2map.h"
#include "mx2cc_std_collections_2stack.h"
#include "mx2cc_type.h"
#include "mx2cc_typeexpr.h"
#include "mx2cc_value.h"
#include "mx2cc_var.h"
#include "../../../../../modules/std/std.buildv1.0.0/desktop_release_linux/std_collections_2stack.h"

extern bbBool g_std_stringio_SaveString(bbString l_str,bbString l_path);
extern bbString g_std_stringio_LoadString(bbString l_path);
extern bbBool g_std_filesystem_DeleteDir(bbString l_path,bbBool l_recursive);
extern bbBool g_std_filesystem_CreateDir(bbString l_path,bbBool l_recursive);
extern bbInt g_std_filesystem_GetFileType(bbString l_path);
extern bbBool g_std_stringio_IsIdent(bbInt l_chr);
extern bbString g_mx2_OpSym(bbString l_id);

// ***** Internal *****

bbString g_mx2_docs_PAGES_0DIR;

void t_mx2_docs_DocsMaker::gcMark(){
  bbGCMark(m__0nav);
  bbGCMark(m__0md);
  bbGCMark(m__0module);
  bbGCMark(m__0linkScope);
}

t_mx2_docs_DocsMaker::t_mx2_docs_DocsMaker(){
  this->m__0nav=bbGCNew<t_mx2_docs_JsonBuffer>();
  struct lambda0 : public bbFunction<bbString(bbString)>::Rep{
    t_mx2_docs_DocsMaker* l_self;
    lambda0(t_mx2_docs_DocsMaker* l_self):l_self(l_self){
    }
    bbString invoke(bbString l_link){
      return l_self->m_ResolveLink(l_link,l_self->m__0linkScope);
    }
    void gcMark(){
      bbGCMarkPtr(l_self);
    }
  };
  this->m__0md=bbGCNew<t_mx2_docs_MarkdownBuffer>(bbFunction<bbString(bbString)>(new lambda0(this)));
}

bbString t_mx2_docs_DocsMaker::m_TypeName(t_mx2_Type* l_type,t_mx2_Scope* l_scope){
  struct f0_t : public bbGCFrame{
    t_mx2_NamespaceScope* t0{};
    void gcMark(){
      bbGCMarkPtr(t0);
    }
  }f0{};
  bbString l_prefix=((f0.t0=l_scope->m_FindFile()->m_nmspace)->m_Name()+BB_T("."));
  return this->m_TypeName(l_type,l_prefix);
}

bbString t_mx2_docs_DocsMaker::m_TypeName(t_mx2_Type* l_type,bbString l_prefix){
  struct f0_t : public bbGCFrame{
    t_mx2_ArrayType* l_atype{};
    t_mx2_ClassType* l_ctype{};
    t_mx2_EnumType* l_etype{};
    t_mx2_FuncType* l_ftype{};
    t_mx2_GenArgType* l_gtype{};
    t_mx2_NamespaceType* l_ntype{};
    t_mx2_PrimType* l_ptype{};
    t_mx2_PointerType* l_qtype{};
    t_mx2_VoidType* l_vtype{};
    t_mx2_AliasType* l_xtype{};
    void gcMark(){
      bbGCMarkPtr(l_atype);
      bbGCMarkPtr(l_ctype);
      bbGCMarkPtr(l_etype);
      bbGCMarkPtr(l_ftype);
      bbGCMarkPtr(l_gtype);
      bbGCMarkPtr(l_ntype);
      bbGCMarkPtr(l_ptype);
      bbGCMarkPtr(l_qtype);
      bbGCMarkPtr(l_vtype);
      bbGCMarkPtr(l_xtype);
    }
  }f0{};
  f0.l_xtype=bb_object_cast<t_mx2_AliasType*>(l_type);
  if(bbBool(f0.l_xtype)){
    if(bbBool(f0.l_xtype->m_instanceOf)){
      f0.l_xtype=f0.l_xtype->m_instanceOf;
    }
    return this->m_MakeLink(this->m_Esc(f0.l_xtype->m_adecl->m_ident),((t_mx2_Decl*)(f0.l_xtype->m_adecl)),f0.l_xtype->m_scope);
  }
  f0.l_vtype=g_mx2_TCast_1Tt_mx2_VoidType_2(l_type);
  if(bbBool(f0.l_vtype)){
    return f0.l_vtype->m_Name();
  }
  f0.l_gtype=g_mx2_TCast_1Tt_mx2_GenArgType_2(l_type);
  if(bbBool(f0.l_gtype)){
    return f0.l_gtype->m_Name().replace(BB_T("?"),bbString{});
  }
  f0.l_ptype=g_mx2_TCast_1Tt_mx2_PrimType_2(l_type);
  if(bbBool(f0.l_ptype)){
    struct f1_t : public bbGCFrame{
      t_mx2_ClassType* l_ctype{};
      void gcMark(){
        bbGCMarkPtr(l_ctype);
      }
    }f1{};
    f1.l_ctype=f0.l_ptype->m_ctype;
    return this->m_MakeLink(this->m_Esc(f0.l_ptype->m_Name()),((t_mx2_Decl*)(f1.l_ctype->m_cdecl)),f1.l_ctype->m_scope->m_outer);
  }
  f0.l_ntype=g_mx2_TCast_1Tt_mx2_NamespaceType_2(l_type);
  if(bbBool(f0.l_ntype)){
    return this->m_Esc(f0.l_ntype->m_Name());
  }
  f0.l_ctype=g_mx2_TCast_1Tt_mx2_ClassType_2(l_type);
  if(bbBool(f0.l_ctype)){
    bbString l_args=bbString{};
    {
      bbInt l_0=bbInt(0);
      bbInt l_1=f0.l_ctype->m_types->length();
      for(;(l_0<l_1);l_0+=1){
        struct f3_t : public bbGCFrame{
          t_mx2_Type* l_type{};
          void gcMark(){
            bbGCMarkPtr(l_type);
          }
        }f3{};
        f3.l_type=f0.l_ctype->m_types->at(l_0);
        l_args+=(BB_T(",")+this->m_TypeName(f3.l_type,l_prefix));
      }
    }
    if(bbBool(l_args)){
      l_args=((BB_T("\\< ")+l_args.slice(1))+BB_T(" \\>"));
    }
    if(bbBool(f0.l_ctype->m_instanceOf)){
      f0.l_ctype=f0.l_ctype->m_instanceOf;
    }
    return (this->m_MakeLink(this->m_Esc(f0.l_ctype->m_cdecl->m_ident),((t_mx2_Decl*)(f0.l_ctype->m_cdecl)),f0.l_ctype->m_scope->m_outer)+l_args);
  }
  f0.l_etype=g_mx2_TCast_1Tt_mx2_EnumType_2(l_type);
  if(bbBool(f0.l_etype)){
    bbString l_name=f0.l_etype->m_Name();
    if(l_name.startsWith(l_prefix)){
      l_name=l_name.slice(l_prefix.length());
    }
    return this->m_MakeLink(this->m_Esc(l_name),((t_mx2_Decl*)(f0.l_etype->m_edecl)),f0.l_etype->m_scope->m_outer);
  }
  f0.l_qtype=g_mx2_TCast_1Tt_mx2_PointerType_2(l_type);
  if(bbBool(f0.l_qtype)){
    return (this->m_TypeName(f0.l_qtype->m_elemType,l_prefix)+BB_T(" Ptr"));
  }
  f0.l_atype=g_mx2_TCast_1Tt_mx2_ArrayType_2(l_type);
  if(bbBool(f0.l_atype)){
    if((f0.l_atype->m_rank==1)){
      return (this->m_TypeName(f0.l_atype->m_elemType,l_prefix)+BB_T("\\[ \\]"));
    }
    return ((this->m_TypeName(f0.l_atype->m_elemType,l_prefix)+BB_T("\\[ ,,,,,,,,,").slice(bbInt(0),(f0.l_atype->m_rank+2)))+BB_T(" \\]"));
  }
  f0.l_ftype=g_mx2_TCast_1Tt_mx2_FuncType_2(l_type);
  if(bbBool(f0.l_ftype)){
    bbString l_args=bbString{};
    {
      bbInt l_2=bbInt(0);
      bbInt l_3=f0.l_ftype->m_argTypes->length();
      for(;(l_2<l_3);l_2+=1){
        struct f3_t : public bbGCFrame{
          t_mx2_Type* l_arg{};
          void gcMark(){
            bbGCMarkPtr(l_arg);
          }
        }f3{};
        f3.l_arg=f0.l_ftype->m_argTypes->at(l_2);
        l_args+=(BB_T(",")+this->m_TypeName(f3.l_arg,l_prefix));
      }
    }
    l_args=l_args.slice(1);
    return (((this->m_TypeName(f0.l_ftype->m_retType,l_prefix)+BB_T("( "))+l_args)+BB_T(" )"));
  }
  puts((l_type->m_Name()+BB_T("!!!!!!")).c_str());fflush( stdout );
  bbAssert(false,BB_T("Assert failed"));
  return bbString{};
}

void t_mx2_docs_DocsMaker::m_SavePage(bbString l_docs,bbString l_page){
  l_page=l_page.replace(BB_T("."),BB_T("-"));
  l_docs=this->m__0pageTemplate.replace(BB_T("${CONTENT}"),l_docs);
  g_std_stringio_SaveString(l_docs,((this->m__0pagesDir+l_page)+BB_T(".html")));
}

bbString t_mx2_docs_DocsMaker::m_ResolveLink(bbString l_path,t_mx2_Scope* l_scope){
  struct f0_t : public bbGCFrame{
    t_mx2_Scope* l_scope{};
    f0_t(t_mx2_Scope* l_scope):l_scope(l_scope){
    }
    void gcMark(){
      bbGCMarkPtr(l_scope);
    }
  }f0{l_scope};
  bbInt l_i0=bbInt(0);
  bbString l_tpath=bbString{};
  for(;;){
    struct f1_t : public bbGCFrame{
      t_mx2_ClassType* l_ctype{};
      t_mx2_EnumType* l_etype{};
      t_mx2_NamespaceType* l_ntype{};
      t_mx2_Type* l_type{};
      void gcMark(){
        bbGCMarkPtr(l_ctype);
        bbGCMarkPtr(l_etype);
        bbGCMarkPtr(l_ntype);
        bbGCMarkPtr(l_type);
      }
    }f1{};
    bbInt l_i1=l_path.find(BB_T("."),l_i0);
    if((l_i1==-1)){
      struct f2_t : public bbGCFrame{
        t_mx2_ClassType* l_ctype{};
        t_mx2_EnumType* l_etype{};
        t_mx2_FuncList* l_flist{};
        t_mx2_SNode* l_node{};
        t_mx2_NamespaceType* l_ntype{};
        t_mx2_VarValue* l_vvar{};
        void gcMark(){
          bbGCMarkPtr(l_ctype);
          bbGCMarkPtr(l_etype);
          bbGCMarkPtr(l_flist);
          bbGCMarkPtr(l_node);
          bbGCMarkPtr(l_ntype);
          bbGCMarkPtr(l_vvar);
        }
      }f2{};
      if(!bbBool(f0.l_scope)){
        return bbString{};
      }
      bbString l_id=l_path.slice(l_i0);
      f2.l_node=f0.l_scope->m_FindNode(l_id);
      if(!bbBool(f2.l_node)){
        return l_path;
      }
      l_tpath+=l_id;
      f2.l_vvar=bb_object_cast<t_mx2_VarValue*>(f2.l_node);
      if(bbBool(f2.l_vvar)){
        return this->m_MakeLink(l_tpath,((t_mx2_Decl*)(f2.l_vvar->m_vdecl)),f2.l_vvar->m_scope);
      }
      f2.l_flist=bb_object_cast<t_mx2_FuncList*>(f2.l_node);
      if(bbBool(f2.l_flist)){
        struct f3_t : public bbGCFrame{
          t_mx2_Decl* t0{};
          t_mx2_Scope* t1{};
          void gcMark(){
            bbGCMarkPtr(t0);
            bbGCMarkPtr(t1);
          }
        }f3{};
        return this->m_MakeLink(l_tpath,f3.t0=((t_mx2_Decl*)(f2.l_flist->m_funcs->m__idx(bbInt(0))->m_fdecl)),f3.t1=f2.l_flist->m_funcs->m__idx(bbInt(0))->m_scope);
      }
      f2.l_etype=g_mx2_TCast_1Tt_mx2_EnumType_2(f2.l_node);
      if(bbBool(f2.l_etype)){
        return this->m_MakeLink(l_tpath,((t_mx2_Decl*)(f2.l_etype->m_edecl)),f2.l_etype->m_scope->m_outer);
      }
      f2.l_ntype=g_mx2_TCast_1Tt_mx2_NamespaceType_2(f2.l_node);
      if(bbBool(f2.l_ntype)){
        return this->m_MakeLink(l_tpath,f2.l_ntype->m_scope);
      }
      f2.l_ctype=g_mx2_TCast_1Tt_mx2_ClassType_2(f2.l_node);
      if(bbBool(f2.l_ctype)){
        return this->m_MakeLink(l_tpath,((t_mx2_Decl*)(f2.l_ctype->m_cdecl)),f2.l_ctype->m_scope->m_outer);
      }
      return bbString{};
    }
    bbString l_id=l_path.slice(l_i0,l_i1);
    l_i0=(l_i1+1);
    if(bbBool(f0.l_scope)){
      try{
        f1.l_type=f0.l_scope->m_FindType(l_id);
      }catch(t_mx2_SemantEx* ex){
        struct f3_t : public bbGCFrame{
          t_mx2_SemantEx* l_ex{};
          void gcMark(){
            bbGCMarkPtr(l_ex);
          }
        }f3{};
        f3.l_ex=ex;
        puts(BB_T("Exception!").c_str());fflush( stdout );
      }
    }else if(!bbBool(l_tpath)){
      {
        struct f3_t : public bbGCFrame{
          t_std_collections_Stack_1Tt_mx2_FileScope_2_Iterator l_0{};
          void gcMark(){
            bbGCMark(l_0);
          }
        }f3{};
        f3.l_0=this->m__0module->m_fileScopes->m_All();
        for(;!f3.l_0.m_AtEnd();f3.l_0.m_Bump()){
          struct f4_t : public bbGCFrame{
            t_mx2_FileScope* l_fscope{};
            void gcMark(){
              bbGCMarkPtr(l_fscope);
            }
          }f4{};
          f4.l_fscope=f3.l_0.m_Current();
          if((l_id!=f4.l_fscope->m_nmspace->m_ntype->m_ident)){
            continue;
          }
          f1.l_type=((t_mx2_Type*)(f4.l_fscope->m_nmspace->m_ntype));
          break;
        }
      }
    }
    if(!bbBool(f1.l_type)){
      return l_path;
    }
    l_tpath+=(l_id+BB_T("."));
    f1.l_ntype=g_mx2_TCast_1Tt_mx2_NamespaceType_2(f1.l_type);
    if(bbBool(f1.l_ntype)){
      f0.l_scope=((t_mx2_Scope*)(f1.l_ntype->m_scope));
      continue;
    }
    f1.l_ctype=g_mx2_TCast_1Tt_mx2_ClassType_2(f1.l_type);
    if(bbBool(f1.l_ctype)){
      f0.l_scope=((t_mx2_Scope*)(f1.l_ctype->m_scope));
      continue;
    }
    f1.l_etype=g_mx2_TCast_1Tt_mx2_EnumType_2(f1.l_type);
    if(bbBool(f1.l_etype)){
      return this->m_MakeLink(((l_tpath+BB_T("."))+l_path.slice(l_i0)),((t_mx2_Decl*)(f1.l_etype->m_edecl)),f1.l_etype->m_scope->m_outer);
    }
    return bbString{};
  }
  return bbString{};
}

bbString t_mx2_docs_DocsMaker::m_NamespaceSlug(t_mx2_NamespaceScope* l_nmspace){
  bbString l_slug=((this->m__0module->m_name+BB_T(":"))+this->m_NamespacePath(l_nmspace).replace(BB_T("."),BB_T("-")));
  return l_slug;
}

bbString t_mx2_docs_DocsMaker::m_NamespacePath(t_mx2_NamespaceScope* l_nmspace){
  return l_nmspace->m_Name();
}

bbString t_mx2_docs_DocsMaker::m_MakeLink(bbString l_text,t_mx2_NamespaceScope* l_nmspace){
  bbString l_slug=this->m_NamespaceSlug(l_nmspace);
  return ((((((BB_T("<a href=\"javascript:void('")+l_slug)+BB_T("')\" onclick=\"openDocsPage('"))+l_slug)+BB_T("')\">"))+l_text)+BB_T("</a>"));
}

bbString t_mx2_docs_DocsMaker::m_MakeLink(bbString l_text,t_mx2_Decl* l_decl,t_mx2_Scope* l_scope){
  bbString l_slug=this->m_DeclSlug(l_decl,l_scope);
  return ((((((BB_T("<a href=\"javascript:void('")+l_slug)+BB_T("')\" onclick=\"openDocsPage('"))+l_slug)+BB_T("')\">"))+l_text)+BB_T("</a>"));
}

bbString t_mx2_docs_DocsMaker::m_MakeLangNav(){
  bbString l_src=g_std_stringio_LoadString(BB_T("docs/The Monkey2 Language.html"));
  l_src=l_src.replace(BB_T("\r\n"),BB_T("\n"));
  bbString l_tag1=BB_T("<p><div class=\"toc\">");
  bbString l_tag2=BB_T("</div>");
  bbInt l_i=l_src.find(l_tag1,bbInt(0));
  if((l_i==-1)){
    puts(BB_T("Can't find lang TOC div").c_str());fflush( stdout );
    return bbString{};
  }
  bbInt l_i2=l_src.find(l_tag2,(l_i+l_tag1.length()));
  if((l_i2==-1)){
    puts(BB_T("Can't find lang TOC /div").c_str());fflush( stdout );
    return bbString{};
  }
  l_src=l_src.slice((l_i+l_tag1.length()),l_i2);
  bbInt l_nest=bbInt(0);
  {
    struct f1_t : public bbGCFrame{
      bbArray<bbString>* l_0{};
      void gcMark(){
        bbGCMarkPtr(l_0);
      }
    }f1{};
    f1.l_0=l_src.split(BB_T("\n"));
    bbInt l_1=bbInt(0);
    bbInt l_2=f1.l_0->length();
    for(;(l_1<l_2);l_1+=1){
      bbString l_line=f1.l_0->at(l_1);
      if((l_line==BB_T("</ul>"))){
        if(bbBool(l_nest)){
          this->m__0nav->m_Emit(BB_T("]}"));
          l_nest-=1;
        }
      }else if((l_line==BB_T("</li>"))){
      }else if(l_line.startsWith(BB_T("<li>"))){
        bbInt l_i=l_line.find(BB_T("<a href=\"#"),bbInt(0));
        if((l_i==-1)){
          continue;
        }
        bbInt l_i2=l_line.find(BB_T("\">"),(l_i+10));
        if((l_i2==-1)){
          continue;
        }
        bbInt l_i3=l_line.find(BB_T("</a>"),(l_i2+2));
        if((l_i3==-1)){
          continue;
        }
        bbString l_href=l_line.slice((l_i+10),l_i2);
        bbString l_text=l_line.slice((l_i2+2),l_i3);
        if(l_line.endsWith(BB_T("<ul>"))){
          l_nest+=1;
          this->m__0nav->m_Emit(((((BB_T("{text:\"")+l_text)+BB_T("\",data:{topic:\""))+l_href)+BB_T("\"},children:[")));
        }else if(l_line.endsWith(BB_T("</li>"))){
          this->m__0nav->m_Emit(((((BB_T("{text:\"")+l_text)+BB_T("\",data:{topic:\""))+l_href)+BB_T("\"}}")));
        }
      }
    }
  }
  bbString l_tree=this->m__0nav->m_Flush();
  return l_tree;
}

bbString t_mx2_docs_DocsMaker::m_MakeDocs(t_mx2_Module* l_module){
  struct f0_t : public bbGCFrame{
    t_std_collections_Map_1ss* l_nmspaceDocs{};
    t_std_collections_Map_1sTt_mx2_NamespaceScope_2* l_nmspaces{};
    void gcMark(){
      bbGCMarkPtr(l_nmspaceDocs);
      bbGCMarkPtr(l_nmspaces);
    }
  }f0{};
  this->m__0module=l_module;
  this->m__0pagesDir=(this->m__0module->m_baseDir+g_mx2_docs_PAGES_0DIR);
  this->m__0pageTemplate=g_std_stringio_LoadString(BB_T("docs/modules_page_template.html"));
  g_std_filesystem_DeleteDir(this->m__0pagesDir,true);
  g_std_filesystem_CreateDir(this->m__0pagesDir,true);
  f0.l_nmspaces=bbGCNew<t_std_collections_Map_1sTt_mx2_NamespaceScope_2>();
  f0.l_nmspaceDocs=bbGCNew<t_std_collections_Map_1ss>();
  {
    struct f1_t : public bbGCFrame{
      t_std_collections_Stack_1Tt_mx2_FileScope_2_Iterator l_0{};
      void gcMark(){
        bbGCMark(l_0);
      }
    }f1{};
    f1.l_0=this->m__0module->m_fileScopes->m_All();
    for(;!f1.l_0.m_AtEnd();f1.l_0.m_Bump()){
      struct f2_t : public bbGCFrame{
        t_mx2_FileScope* l_fscope{};
        t_mx2_NamespaceScope* l_nmspace{};
        void gcMark(){
          bbGCMarkPtr(l_fscope);
          bbGCMarkPtr(l_nmspace);
        }
      }f2{};
      f2.l_fscope=f1.l_0.m_Current();
      f2.l_nmspace=bb_object_cast<t_mx2_NamespaceScope*>(f2.l_fscope->m_outer);
      if(!bbBool(f2.l_nmspace)){
        continue;
      }
      f0.l_nmspaces->m__idxeq(f2.l_nmspace->m_Name(),f2.l_nmspace);
      bbString l_1=f2.l_nmspace->m_Name();
      f0.l_nmspaceDocs->m__idxeq(l_1,(f0.l_nmspaceDocs->m__idx(l_1)+f2.l_fscope->m_fdecl->m_docs));
    }
  }
  bbString l_page=bbString{};
  bbString l_mdocs=(this->m__0module->m_baseDir+BB_T("docs/module.md"));
  if((g_std_filesystem_GetFileType(l_mdocs)==1)){
    bbString l_md=g_std_stringio_LoadString(l_mdocs);
    this->m__0linkScope=((t_mx2_Scope*)0);
    this->m__0md->m_Emit(l_md);
    l_page=BB_T("module");
    this->m_SavePage(this->m__0md->m_Flush(),l_page);
  }
  this->m_BeginNode(this->m__0module->m_name,l_page);
  {
    struct f1_t : public bbGCFrame{
      t_std_collections_Map_1sTt_mx2_NamespaceScope_2_ValueIterator l_2{};
      void gcMark(){
        bbGCMark(l_2);
      }
    }f1{};
    f1.l_2=f0.l_nmspaces->m_Values().m_All();
    for(;f1.l_2.m_Valid();f1.l_2.m_Bump()){
      struct f2_t : public bbGCFrame{
        t_mx2_NamespaceScope* l_nmspace{};
        void gcMark(){
          bbGCMarkPtr(l_nmspace);
        }
      }f2{};
      f2.l_nmspace=f1.l_2.m_Current();
      this->m_EmitNamespace(f2.l_nmspace,f0.l_nmspaceDocs->m__idx(f2.l_nmspace->m_Name()));
    }
  }
  this->m_EndNode();
  bbString l_tree=this->m__0nav->m_Flush();
  g_std_stringio_SaveString(l_tree,(this->m__0pagesDir+BB_T("index.js")));
  return l_tree;
}

bbString t_mx2_docs_DocsMaker::m_Esc(bbString l_id){
  l_id=l_id.replace(BB_T("|"),BB_T("\\|"));
  l_id=l_id.replace(BB_T("_"),BB_T("\\_"));
  l_id=l_id.replace(BB_T("<"),BB_T("\\<"));
  l_id=l_id.replace(BB_T(">"),BB_T("\\>"));
  return l_id;
}

void t_mx2_docs_DocsMaker::m_EndNode(){
  this->m__0nav->m_Emit(BB_T("] }"));
}

void t_mx2_docs_DocsMaker::m_EmitVars(t_mx2_Scope* l_scope,bbString l_kind){
  {
    struct f1_t : public bbGCFrame{
      t_std_collections_Map_1sTt_mx2_SNode_2_Iterator l_0{};
      void gcMark(){
        bbGCMark(l_0);
      }
    }f1{};
    f1.l_0=l_scope->m_nodes->m_All();
    for(;f1.l_0.m_Valid();f1.l_0.m_Bump()){
      struct f2_t : public bbGCFrame{
        t_mx2_VarDecl* l_decl{};
        t_std_collections_Map_1sTt_mx2_SNode_2_Node* l_node{};
        t_mx2_VarValue* l_vvar{};
        void gcMark(){
          bbGCMarkPtr(l_decl);
          bbGCMarkPtr(l_node);
          bbGCMarkPtr(l_vvar);
        }
      }f2{};
      f2.l_node=f1.l_0.m_Current();
      f2.l_vvar=bb_object_cast<t_mx2_VarValue*>(f2.l_node->m_Value());
      if((!bbBool(f2.l_vvar)||(f2.l_vvar->m_transFile->m_module!=this->m__0module))){
        continue;
      }
      f2.l_decl=f2.l_vvar->m_vdecl;
      if(((f2.l_decl->m_kind!=l_kind)||this->m_DocsHidden(((t_mx2_Decl*)(f2.l_decl))))){
        continue;
      }
      this->m__0linkScope=f2.l_vvar->m_scope;
      this->m_EmitHeader(((t_mx2_Decl*)(f2.l_decl)),f2.l_vvar->m_scope);
      this->m__0md->m_Emit((((((BB_T("##### ")+f2.l_decl->m_kind.capitalize())+BB_T(" "))+this->m_DeclIdent(((t_mx2_Decl*)(f2.l_decl)),false))+BB_T(" : "))+this->m_TypeName(f2.l_vvar->m_type,f2.l_vvar->m_scope)));
      this->m__0md->m_Emit(f2.l_decl->m_docs);
      bbString l_docs=this->m__0md->m_Flush();
      bbString l_page=this->m_DeclPath(((t_mx2_Decl*)(f2.l_vvar->m_vdecl)),f2.l_vvar->m_scope);
      this->m_SavePage(l_docs,l_page);
      this->m_EmitLeaf(((t_mx2_Decl*)(f2.l_vvar->m_vdecl)),l_page);
    }
  }
}

void t_mx2_docs_DocsMaker::m_EmitProperties(t_mx2_Scope* l_scope,bbString l_kind){
  {
    struct f1_t : public bbGCFrame{
      t_std_collections_Map_1sTt_mx2_SNode_2_Iterator l_0{};
      void gcMark(){
        bbGCMark(l_0);
      }
    }f1{};
    f1.l_0=l_scope->m_nodes->m_All();
    for(;f1.l_0.m_Valid();f1.l_0.m_Bump()){
      struct f2_t : public bbGCFrame{
        t_mx2_PropertyDecl* l_decl{};
        t_mx2_FuncValue* l_func{};
        t_std_collections_Map_1sTt_mx2_SNode_2_Node* l_node{};
        t_mx2_PropertyList* l_plist{};
        t_mx2_Type* l_type{};
        void gcMark(){
          bbGCMarkPtr(l_decl);
          bbGCMarkPtr(l_func);
          bbGCMarkPtr(l_node);
          bbGCMarkPtr(l_plist);
          bbGCMarkPtr(l_type);
        }
      }f2{};
      f2.l_node=f1.l_0.m_Current();
      f2.l_plist=bb_object_cast<t_mx2_PropertyList*>(f2.l_node->m_Value());
      if(!bbBool(f2.l_plist)){
        continue;
      }
      f2.l_decl=f2.l_plist->m_pdecl;
      if(((f2.l_decl->m_kind!=l_kind)||this->m_DocsHidden(((t_mx2_Decl*)(f2.l_decl))))){
        continue;
      }
      f2.l_func=f2.l_plist->m_getFunc;
      if(!bbBool(f2.l_func)){
        f2.l_func=f2.l_plist->m_setFunc;
        if(!bbBool(f2.l_func)){
          continue;
        }
      }
      f2.l_type=(bbBool(f2.l_func->m_ftype->m_argTypes) ? f2.l_func->m_ftype->m_argTypes->at(1) : f2.l_func->m_ftype->m_retType);
      this->m__0linkScope=f2.l_func->m_scope;
      this->m_EmitHeader(((t_mx2_Decl*)(f2.l_decl)),f2.l_func->m_scope);
      this->m__0md->m_Emit((((BB_T("##### Property ")+this->m_DeclIdent(((t_mx2_Decl*)(f2.l_decl)),false))+BB_T(" : "))+this->m_TypeName(f2.l_type,f2.l_func->m_scope)));
      this->m__0md->m_Emit(f2.l_decl->m_docs);
      bbString l_docs=this->m__0md->m_Flush();
      bbString l_page=this->m_DeclPath(((t_mx2_Decl*)(f2.l_plist->m_pdecl)),f2.l_plist->m_scope);
      this->m_SavePage(l_docs,l_page);
      this->m_EmitLeaf(((t_mx2_Decl*)(f2.l_plist->m_pdecl)),l_page);
    }
  }
}

void t_mx2_docs_DocsMaker::m_EmitNode(bbString l_name,t_mx2_Scope* l_scope,bbString l_page){
  this->m_BeginNode(l_name,l_page);
  this->m_BeginNode(BB_T("Aliases"),bbString{});
  this->m_EmitAliases(l_scope,BB_T("alias"));
  this->m_EndNode();
  this->m_BeginNode(BB_T("Enums"),bbString{});
  this->m_EmitEnums(l_scope,BB_T("enum"));
  this->m_EndNode();
  this->m_BeginNode(BB_T("Structs"),bbString{});
  this->m_EmitClasses(l_scope,BB_T("struct"));
  this->m_EndNode();
  this->m_BeginNode(BB_T("Classes"),bbString{});
  this->m_EmitClasses(l_scope,BB_T("class"));
  this->m_EndNode();
  this->m_BeginNode(BB_T("Interfaces"),bbString{});
  this->m_EmitClasses(l_scope,BB_T("interface"));
  this->m_EndNode();
  this->m_BeginNode(BB_T("Constants"),bbString{});
  this->m_EmitVars(l_scope,BB_T("const"));
  this->m_EndNode();
  this->m_BeginNode(BB_T("Globals"),bbString{});
  this->m_EmitVars(l_scope,BB_T("global"));
  this->m_EndNode();
  this->m_BeginNode(BB_T("Fields"),bbString{});
  this->m_EmitVars(l_scope,BB_T("field"));
  this->m_EndNode();
  this->m_BeginNode(BB_T("Contructors"),bbString{});
  this->m_EmitFuncs(l_scope,BB_T("constructor"));
  this->m_EndNode();
  this->m_BeginNode(BB_T("Properties"),bbString{});
  this->m_EmitProperties(l_scope,BB_T("property"));
  this->m_EndNode();
  this->m_BeginNode(BB_T("Operators"),bbString{});
  this->m_EmitFuncs(l_scope,BB_T("operator"));
  this->m_EndNode();
  this->m_BeginNode(BB_T("Methods"),bbString{});
  this->m_EmitFuncs(l_scope,BB_T("method"));
  this->m_EndNode();
  this->m_BeginNode(BB_T("Functions"),bbString{});
  this->m_EmitFuncs(l_scope,BB_T("function"));
  this->m_EndNode();
  this->m_EndNode();
}

void t_mx2_docs_DocsMaker::m_EmitNode(t_mx2_Decl* l_decl,t_mx2_Scope* l_scope,bbString l_page){
  this->m_EmitNode(l_decl->m_ident,l_scope,l_page);
}

void t_mx2_docs_DocsMaker::m_EmitNamespace(t_mx2_NamespaceScope* l_nmspace,bbString l_docs){
  this->m__0linkScope=((t_mx2_Scope*)(l_nmspace));
  this->m__0md->m_Emit(((BB_T("_Module: &lt;")+this->m__0module->m_name)+BB_T("&gt;_  ")));
  this->m__0md->m_Emit(((BB_T("_Namespace: ")+l_nmspace->m_Name())+BB_T("_")));
  this->m_EmitMembers(BB_T("alias"),((t_mx2_Scope*)(l_nmspace)),true);
  this->m_EmitMembers(BB_T("enum"),((t_mx2_Scope*)(l_nmspace)),true);
  this->m_EmitMembers(BB_T("struct"),((t_mx2_Scope*)(l_nmspace)),true);
  this->m_EmitMembers(BB_T("class"),((t_mx2_Scope*)(l_nmspace)),true);
  this->m_EmitMembers(BB_T("interface"),((t_mx2_Scope*)(l_nmspace)),true);
  this->m_EmitMembers(BB_T("const"),((t_mx2_Scope*)(l_nmspace)),true);
  this->m_EmitMembers(BB_T("global"),((t_mx2_Scope*)(l_nmspace)),true);
  this->m_EmitMembers(BB_T("function"),((t_mx2_Scope*)(l_nmspace)),true);
  this->m__0md->m_Emit(l_docs);
  l_docs=this->m__0md->m_Flush();
  bbString l_page=this->m_NamespacePath(l_nmspace);
  this->m_SavePage(l_docs,l_page);
  this->m_EmitNode(l_nmspace->m_ntype->m_Name(),((t_mx2_Scope*)(l_nmspace)),l_page);
}

void t_mx2_docs_DocsMaker::m_EmitMembers(bbString l_kind,t_mx2_Scope* l_scope,bbBool l_inherited){
  bbBool l_init=true;
  {
    struct f1_t : public bbGCFrame{
      t_std_collections_Map_1sTt_mx2_SNode_2_Iterator l_0{};
      void gcMark(){
        bbGCMark(l_0);
      }
    }f1{};
    f1.l_0=l_scope->m_nodes->m_All();
    for(;f1.l_0.m_Valid();f1.l_0.m_Bump()){
      struct f2_t : public bbGCFrame{
        t_mx2_AliasType* l_atype{};
        t_mx2_ClassType* l_ctype{};
        t_mx2_EnumType* l_etype{};
        t_mx2_FuncList* l_flist{};
        t_std_collections_Map_1sTt_mx2_SNode_2_Node* l_node{};
        t_mx2_PropertyList* l_plist{};
        t_mx2_VarValue* l_vvar{};
        void gcMark(){
          bbGCMarkPtr(l_atype);
          bbGCMarkPtr(l_ctype);
          bbGCMarkPtr(l_etype);
          bbGCMarkPtr(l_flist);
          bbGCMarkPtr(l_node);
          bbGCMarkPtr(l_plist);
          bbGCMarkPtr(l_vvar);
        }
      }f2{};
      f2.l_node=f1.l_0.m_Current();
      f2.l_atype=bb_object_cast<t_mx2_AliasType*>(f2.l_node->m_Value());
      if(bbBool(f2.l_atype)){
        struct f3_t : public bbGCFrame{
          t_mx2_AliasDecl* l_decl{};
          void gcMark(){
            bbGCMarkPtr(l_decl);
          }
        }f3{};
        if((l_kind!=BB_T("alias"))){
          continue;
        }
        f3.l_decl=f2.l_atype->m_adecl;
        if(this->m_DocsHidden(((t_mx2_Decl*)(f3.l_decl)))){
          continue;
        }
        if((l_inherited!=(l_scope!=f2.l_atype->m_scope))){
          continue;
        }
        if(l_init){
          l_init=false;
          this->m__0md->m_EmitBr();
          this->m__0md->m_Emit(BB_T("| Aliases | &nbsp; |"));
          this->m__0md->m_Emit(BB_T("|:---|:---"));
        }
        this->m__0md->m_Emit(((((BB_T("| ")+this->m_DeclIdent(((t_mx2_Decl*)(f3.l_decl)),f2.l_atype->m_scope,false))+BB_T(" | "))+this->m_DeclDesc(((t_mx2_Decl*)(f3.l_decl))))+BB_T(" |")));
        continue;
      }
      f2.l_ctype=bb_object_cast<t_mx2_ClassType*>(f2.l_node->m_Value());
      if(bbBool(f2.l_ctype)){
        struct f3_t : public bbGCFrame{
          t_mx2_ClassDecl* l_decl{};
          void gcMark(){
            bbGCMarkPtr(l_decl);
          }
        }f3{};
        f3.l_decl=f2.l_ctype->m_cdecl;
        if((l_kind!=f3.l_decl->m_kind)){
          continue;
        }
        if(this->m_DocsHidden(((t_mx2_Decl*)(f3.l_decl)))){
          continue;
        }
        if((l_inherited!=(l_scope!=f2.l_ctype->m_scope->m_outer))){
          continue;
        }
        if(l_init){
          l_init=false;
          bbString l_kinds=(l_kind.capitalize()+((l_kind==BB_T("class")) ? BB_T("es") : BB_T("s")));
          this->m__0md->m_EmitBr();
          this->m__0md->m_Emit(((BB_T("| ")+l_kinds)+BB_T(" | |")));
          this->m__0md->m_Emit(BB_T("|:---|:---|"));
        }
        this->m__0md->m_Emit(((((BB_T("| ")+this->m_DeclIdent(((t_mx2_Decl*)(f3.l_decl)),f2.l_ctype->m_scope->m_outer,false))+BB_T(" | "))+this->m_DeclDesc(((t_mx2_Decl*)(f3.l_decl))))+BB_T(" |")));
        continue;
      }
      f2.l_etype=bb_object_cast<t_mx2_EnumType*>(f2.l_node->m_Value());
      if(bbBool(f2.l_etype)){
        struct f3_t : public bbGCFrame{
          t_mx2_EnumDecl* l_decl{};
          void gcMark(){
            bbGCMarkPtr(l_decl);
          }
        }f3{};
        if((l_kind!=BB_T("enum"))){
          continue;
        }
        f3.l_decl=f2.l_etype->m_edecl;
        if(this->m_DocsHidden(((t_mx2_Decl*)(f3.l_decl)))){
          continue;
        }
        if((l_inherited!=(l_scope!=f2.l_etype->m_scope->m_outer))){
          continue;
        }
        if(l_init){
          l_init=false;
          this->m__0md->m_EmitBr();
          this->m__0md->m_Emit(BB_T("| Enums | |"));
          this->m__0md->m_Emit(BB_T("|:---|:---|"));
        }
        this->m__0md->m_Emit(((((BB_T("| ")+this->m_DeclIdent(((t_mx2_Decl*)(f3.l_decl)),f2.l_etype->m_scope->m_outer,false))+BB_T(" | "))+this->m_DeclDesc(((t_mx2_Decl*)(f3.l_decl))))+BB_T(" |")));
        continue;
      }
      f2.l_vvar=bb_object_cast<t_mx2_VarValue*>(f2.l_node->m_Value());
      if(bbBool(f2.l_vvar)){
        struct f3_t : public bbGCFrame{
          t_mx2_VarDecl* l_decl{};
          void gcMark(){
            bbGCMarkPtr(l_decl);
          }
        }f3{};
        f3.l_decl=f2.l_vvar->m_vdecl;
        if((l_kind!=f3.l_decl->m_kind)){
          continue;
        }
        if(this->m_DocsHidden(((t_mx2_Decl*)(f3.l_decl)))){
          continue;
        }
        if((l_inherited!=(l_scope!=f2.l_vvar->m_scope))){
          continue;
        }
        if(l_init){
          l_init=false;
          this->m__0md->m_EmitBr();
          this->m__0md->m_Emit(((BB_T("| ")+l_kind.capitalize())+BB_T("s | |")));
          this->m__0md->m_Emit(BB_T("|:---|:---|"));
        }
        this->m__0md->m_Emit(((((BB_T("| ")+this->m_DeclIdent(((t_mx2_Decl*)(f3.l_decl)),f2.l_vvar->m_scope,false))+BB_T(" | "))+this->m_DeclDesc(((t_mx2_Decl*)(f3.l_decl))))+BB_T(" |")));
        continue;
      }
      f2.l_plist=bb_object_cast<t_mx2_PropertyList*>(f2.l_node->m_Value());
      if(bbBool(f2.l_plist)){
        struct f3_t : public bbGCFrame{
          t_mx2_PropertyDecl* l_decl{};
          void gcMark(){
            bbGCMarkPtr(l_decl);
          }
        }f3{};
        if((l_kind!=BB_T("property"))){
          continue;
        }
        f3.l_decl=f2.l_plist->m_pdecl;
        if(this->m_DocsHidden(((t_mx2_Decl*)(f3.l_decl)))){
          continue;
        }
        if((l_inherited!=(l_scope!=f2.l_plist->m_scope))){
          continue;
        }
        if(l_init){
          l_init=false;
          this->m__0md->m_EmitBr();
          this->m__0md->m_Emit(BB_T("| Properties | |"));
          this->m__0md->m_Emit(BB_T("|:---|:---|"));
        }
        this->m__0md->m_Emit(((((BB_T("| ")+this->m_DeclIdent(((t_mx2_Decl*)(f3.l_decl)),f2.l_plist->m_scope,false))+BB_T(" | "))+this->m_DeclDesc(((t_mx2_Decl*)(f3.l_decl))))+BB_T(" |")));
        continue;
      }
      f2.l_flist=bb_object_cast<t_mx2_FuncList*>(f2.l_node->m_Value());
      if(bbBool(f2.l_flist)){
        if(((((l_kind!=BB_T("constructor"))&&(l_kind!=BB_T("operator")))&&(l_kind!=BB_T("method")))&&(l_kind!=BB_T("function")))){
          continue;
        }
        {
          struct f4_t : public bbGCFrame{
            t_std_collections_Stack_1Tt_mx2_FuncValue_2_Iterator l_1{};
            void gcMark(){
              bbGCMark(l_1);
            }
          }f4{};
          f4.l_1=f2.l_flist->m_funcs->m_All();
          for(;!f4.l_1.m_AtEnd();f4.l_1.m_Bump()){
            struct f5_t : public bbGCFrame{
              t_mx2_FuncDecl* l_decl{};
              t_mx2_FuncValue* l_func{};
              void gcMark(){
                bbGCMarkPtr(l_decl);
                bbGCMarkPtr(l_func);
              }
            }f5{};
            f5.l_func=f4.l_1.m_Current();
            f5.l_decl=f5.l_func->m_fdecl;
            if(this->m_DocsHidden(((t_mx2_Decl*)(f5.l_decl)))){
              continue;
            }
            if((l_inherited!=(l_scope!=f5.l_func->m_scope))){
              continue;
            }
            if((l_kind==BB_T("constructor"))){
              if((f5.l_decl->m_ident!=BB_T("new"))){
                continue;
              }
            }else if((l_kind==BB_T("operator"))){
              if(!f5.l_decl->m_IsOperator()){
                continue;
              }
            }else if((((l_kind!=f5.l_decl->m_kind)||(f5.l_decl->m_ident==BB_T("new")))||f5.l_decl->m_IsOperator())){
              continue;
            }
            if(l_init){
              l_init=false;
              this->m__0md->m_EmitBr();
              this->m__0md->m_Emit(((BB_T("| ")+l_kind.capitalize())+BB_T("s | |")));
              this->m__0md->m_Emit(BB_T("|:---|:---|"));
            }
            this->m__0md->m_Emit(((((BB_T("| ")+this->m_DeclIdent(((t_mx2_Decl*)(f5.l_decl)),f5.l_func->m_scope,false))+BB_T(" | "))+this->m_DeclDesc(((t_mx2_Decl*)(f5.l_decl))))+BB_T(" |")));
            break;
          }
        }
        continue;
      }
    }
  }
}

void t_mx2_docs_DocsMaker::m_EmitLeaf(t_mx2_Decl* l_decl,bbString l_page){
  this->m_EmitLeaf(l_decl->m_ident,l_page);
}

void t_mx2_docs_DocsMaker::m_EmitLeaf(bbString l_name,bbString l_page){
  if(bbBool(l_page)){
    l_page=((((BB_T(",data:{page:'")+this->m__0module->m_name)+BB_T(":"))+l_page)+BB_T("'}"));
  }
  this->m__0nav->m_Emit(((((BB_T("{ text:'")+l_name)+BB_T("'"))+l_page)+BB_T(",children:[] }")));
}

void t_mx2_docs_DocsMaker::m_EmitHeader(t_mx2_Decl* l_decl,t_mx2_Scope* l_scope){
  struct f0_t : public bbGCFrame{
    t_mx2_FileScope* l_fscope{};
    t_mx2_Module* l_module{};
    t_mx2_NamespaceScope* l_nmspace{};
    void gcMark(){
      bbGCMarkPtr(l_fscope);
      bbGCMarkPtr(l_module);
      bbGCMarkPtr(l_nmspace);
    }
  }f0{};
  f0.l_fscope=l_scope->m_FindFile();
  f0.l_nmspace=f0.l_fscope->m_nmspace;
  f0.l_module=f0.l_fscope->m_fdecl->m_module;
  this->m__0md->m_Emit(((BB_T("_Module: &lt;")+f0.l_module->m_name)+BB_T("&gt;_  ")));
  this->m__0md->m_Emit(((BB_T("_Namespace:_ _")+this->m_MakeLink(this->m_NamespacePath(f0.l_nmspace),f0.l_nmspace))+BB_T("_")));
  this->m__0md->m_EmitBr();
  this->m__0md->m_Emit((BB_T("#### ")+this->m_DeclName(l_decl,l_scope)));
  this->m__0md->m_EmitBr();
}

void t_mx2_docs_DocsMaker::m_EmitFuncs(t_mx2_Scope* l_scope,bbString l_kind){
  {
    struct f1_t : public bbGCFrame{
      t_std_collections_Map_1sTt_mx2_SNode_2_Iterator l_0{};
      void gcMark(){
        bbGCMark(l_0);
      }
    }f1{};
    f1.l_0=l_scope->m_nodes->m_All();
    for(;f1.l_0.m_Valid();f1.l_0.m_Bump()){
      struct f2_t : public bbGCFrame{
        t_std_collections_Stack_1s* l_buf{};
        t_mx2_FuncList* l_flist{};
        t_std_collections_Map_1sTt_mx2_SNode_2_Node* l_node{};
        t_mx2_Decl* t0{};
        t_mx2_Scope* t1{};
        void gcMark(){
          bbGCMarkPtr(l_buf);
          bbGCMarkPtr(l_flist);
          bbGCMarkPtr(l_node);
          bbGCMarkPtr(t0);
          bbGCMarkPtr(t1);
        }
      }f2{};
      f2.l_node=f1.l_0.m_Current();
      f2.l_flist=bb_object_cast<t_mx2_FuncList*>(f2.l_node->m_Value());
      if((!bbBool(f2.l_flist)||bbBool(bb_object_cast<t_mx2_PropertyList*>(f2.l_flist)))){
        continue;
      }
      {
        struct f3_t : public bbGCFrame{
          t_std_collections_Stack_1Tt_mx2_FuncValue_2_Iterator l_1{};
          void gcMark(){
            bbGCMark(l_1);
          }
        }f3{};
        f3.l_1=f2.l_flist->m_funcs->m_All();
        for(;!f3.l_1.m_AtEnd();f3.l_1.m_Bump()){
          struct f4_t : public bbGCFrame{
            t_mx2_FuncDecl* l_decl{};
            t_mx2_FuncValue* l_func{};
            void gcMark(){
              bbGCMarkPtr(l_decl);
              bbGCMarkPtr(l_func);
            }
          }f4{};
          f4.l_func=f3.l_1.m_Current();
          f4.l_decl=f4.l_func->m_fdecl;
          if(this->m_DocsHidden(((t_mx2_Decl*)(f4.l_decl)))){
            continue;
          }
          if((l_kind==BB_T("constructor"))){
            if((f4.l_decl->m_ident!=BB_T("new"))){
              continue;
            }
          }else if((l_kind==BB_T("operator"))){
            if(!f4.l_decl->m_IsOperator()){
              continue;
            }
          }else if((((l_kind!=f4.l_decl->m_kind)||(f4.l_decl->m_ident==BB_T("new")))||f4.l_decl->m_IsOperator())){
            continue;
          }
          this->m__0linkScope=f4.l_func->m_scope;
          if(!bbBool(f2.l_buf)){
            f2.l_buf=bbGCNew<t_std_collections_Stack_1s>();
            this->m_EmitHeader(((t_mx2_Decl*)(f4.l_decl)),f4.l_func->m_scope);
          }
          f2.l_buf->m_Push(f4.l_decl->m_docs);
          bbString l_tkind=(f4.l_decl->m_kind.capitalize()+BB_T(" "));
          if(f4.l_decl->m_IsOperator()){
            l_tkind=bbString{};
          }
          bbString l_params=bbString{};
          {
            bbInt l_i=bbInt(0);
            for(;(l_i<f4.l_func->m_ftype->m_argTypes->length());l_i+=1){
              bbString l_ident=this->m_Esc(f4.l_func->m_fdecl->m_type->m_params->at(l_i)->m_ident);
              bbString l_type=this->m_TypeName(f4.l_func->m_ftype->m_argTypes->at(l_i),f4.l_func->m_scope);
              bbString l_init=bbString{};
              if(bbBool(f4.l_func->m_fdecl->m_type->m_params->at(l_i)->m_init)){
                l_init=(BB_T(" =")+f4.l_func->m_fdecl->m_type->m_params->at(l_i)->m_init->m_ToString());
              }
              l_params+=((((BB_T(" , ")+l_ident)+BB_T(" : "))+l_type)+l_init);
            }
          }
          l_params=l_params.slice(3);
          this->m__0md->m_Emit((((((((BB_T("##### ")+l_tkind)+this->m_DeclIdent(((t_mx2_Decl*)(f4.l_decl)),true))+BB_T(" : "))+this->m_TypeName(f4.l_func->m_ftype->m_retType,f4.l_func->m_scope))+BB_T(" ( "))+l_params)+BB_T(" ) ")));
        }
      }
      if(!bbBool(f2.l_buf)){
        continue;
      }
      {
        struct f3_t : public bbGCFrame{
          t_std_collections_Stack_1s_Iterator l_2{};
          void gcMark(){
            bbGCMark(l_2);
          }
        }f3{};
        f3.l_2=f2.l_buf->m_All();
        for(;!f3.l_2.m_AtEnd();f3.l_2.m_Bump()){
          bbString l_doc=f3.l_2.m_Current();
          this->m__0md->m_Emit(l_doc);
        }
      }
      bbString l_docs=this->m__0md->m_Flush();
      bbString l_page=this->m_DeclPath(f2.t0=((t_mx2_Decl*)(f2.l_flist->m_funcs->m__idx(bbInt(0))->m_fdecl)),f2.t1=f2.l_flist->m_funcs->m__idx(bbInt(0))->m_scope);
      this->m_SavePage(l_docs,l_page);
      this->m_EmitLeaf(f2.t0=((t_mx2_Decl*)(f2.l_flist->m_funcs->m__idx(bbInt(0))->m_fdecl)),l_page);
    }
  }
}

void t_mx2_docs_DocsMaker::m_EmitEnums(t_mx2_Scope* l_scope,bbString l_kind){
  {
    struct f1_t : public bbGCFrame{
      t_std_collections_Map_1sTt_mx2_SNode_2_Iterator l_0{};
      void gcMark(){
        bbGCMark(l_0);
      }
    }f1{};
    f1.l_0=l_scope->m_nodes->m_All();
    for(;f1.l_0.m_Valid();f1.l_0.m_Bump()){
      struct f2_t : public bbGCFrame{
        t_mx2_EnumDecl* l_decl{};
        t_mx2_EnumType* l_etype{};
        t_std_collections_Map_1sTt_mx2_SNode_2_Node* l_node{};
        void gcMark(){
          bbGCMarkPtr(l_decl);
          bbGCMarkPtr(l_etype);
          bbGCMarkPtr(l_node);
        }
      }f2{};
      f2.l_node=f1.l_0.m_Current();
      f2.l_etype=bb_object_cast<t_mx2_EnumType*>(f2.l_node->m_Value());
      if(!bbBool(f2.l_etype)){
        continue;
      }
      f2.l_decl=f2.l_etype->m_edecl;
      if(((f2.l_decl->m_kind!=l_kind)||this->m_DocsHidden(((t_mx2_Decl*)(f2.l_decl))))){
        continue;
      }
      this->m__0linkScope=f2.l_etype->m_scope->m_outer;
      this->m_EmitHeader(((t_mx2_Decl*)(f2.l_decl)),f2.l_etype->m_scope->m_outer);
      this->m__0md->m_Emit((BB_T("##### Enum ")+this->m_DeclIdent(((t_mx2_Decl*)(f2.l_decl)),false)));
      this->m__0md->m_Emit(f2.l_decl->m_docs);
      bbString l_docs=this->m__0md->m_Flush();
      bbString l_page=this->m_DeclPath(((t_mx2_Decl*)(f2.l_etype->m_edecl)),f2.l_etype->m_scope->m_outer);
      this->m_SavePage(l_docs,l_page);
      this->m_EmitLeaf(((t_mx2_Decl*)(f2.l_etype->m_edecl)),l_page);
    }
  }
}

void t_mx2_docs_DocsMaker::m_EmitClasses(t_mx2_Scope* l_scope,bbString l_kind){
  {
    struct f1_t : public bbGCFrame{
      t_std_collections_Map_1sTt_mx2_SNode_2_Iterator l_0{};
      void gcMark(){
        bbGCMark(l_0);
      }
    }f1{};
    f1.l_0=l_scope->m_nodes->m_All();
    for(;f1.l_0.m_Valid();f1.l_0.m_Bump()){
      struct f2_t : public bbGCFrame{
        t_mx2_ClassType* l_ctype{};
        t_mx2_ClassDecl* l_decl{};
        t_std_collections_Map_1sTt_mx2_SNode_2_Node* l_node{};
        void gcMark(){
          bbGCMarkPtr(l_ctype);
          bbGCMarkPtr(l_decl);
          bbGCMarkPtr(l_node);
        }
      }f2{};
      f2.l_node=f1.l_0.m_Current();
      f2.l_ctype=bb_object_cast<t_mx2_ClassType*>(f2.l_node->m_Value());
      if((!bbBool(f2.l_ctype)||(f2.l_ctype->m_transFile->m_module!=this->m__0module))){
        continue;
      }
      f2.l_decl=f2.l_ctype->m_cdecl;
      if(((f2.l_decl->m_kind!=l_kind)||this->m_DocsHidden(((t_mx2_Decl*)(f2.l_decl))))){
        continue;
      }
      this->m__0linkScope=((t_mx2_Scope*)(f2.l_ctype->m_scope));
      this->m_EmitHeader(((t_mx2_Decl*)(f2.l_decl)),f2.l_ctype->m_scope->m_outer);
      bbString l_xtends=bbString{};
      if(bbBool(f2.l_ctype->m_superType)){
        if(f2.l_ctype->m_superType->m__ne(((t_mx2_Type*)(g_mx2_Type_ObjectClass)))){
          l_xtends=(BB_T(" Extends ")+this->m_TypeName(((t_mx2_Type*)(f2.l_ctype->m_superType)),f2.l_ctype->m_scope->m_outer));
        }
      }else if(f2.l_ctype->m_isvoid){
        l_xtends=BB_T(" Extends Void");
      }
      bbString l_implments=bbString{};
      if(bbBool(f2.l_decl->m_ifaceTypes)){
        bbString l_ifaces=bbString{};
        {
          bbInt l_1=bbInt(0);
          bbInt l_2=f2.l_ctype->m_ifaceTypes->length();
          for(;(l_1<l_2);l_1+=1){
            struct f5_t : public bbGCFrame{
              t_mx2_ClassType* l_iface{};
              void gcMark(){
                bbGCMarkPtr(l_iface);
              }
            }f5{};
            f5.l_iface=f2.l_ctype->m_ifaceTypes->at(l_1);
            l_ifaces+=(BB_T(",")+this->m_TypeName(((t_mx2_Type*)(f5.l_iface)),f2.l_ctype->m_scope->m_outer));
          }
        }
        l_ifaces=l_ifaces.slice(1);
        if((f2.l_decl->m_kind==BB_T("interface"))){
          l_xtends=(BB_T(" Extends ")+l_ifaces);
        }else{
          l_implments=(BB_T(" Implements ")+l_ifaces);
        }
      }
      bbString l_mods=bbString{};
      if(f2.l_decl->m_IsVirtual()){
        l_mods+=BB_T(" Virtual");
      }else if(f2.l_decl->m_IsAbstract()){
        l_mods+=BB_T(" Abstract");
      }else if(f2.l_decl->m_IsFinal()){
        l_mods+=BB_T(" Final");
      }
      this->m__0md->m_Emit(((((((BB_T("##### ")+f2.l_decl->m_kind.capitalize())+BB_T(" "))+this->m_DeclIdent(((t_mx2_Decl*)(f2.l_decl)),true))+l_xtends)+l_implments)+l_mods));
      this->m__0md->m_Emit(f2.l_decl->m_docs);
      {
        bbInt l_inh=bbInt(0);
        for(;(l_inh<1);l_inh+=1){
          this->m_EmitMembers(BB_T("alias"),((t_mx2_Scope*)(f2.l_ctype->m_scope)),bbBool(l_inh));
          this->m_EmitMembers(BB_T("enum"),((t_mx2_Scope*)(f2.l_ctype->m_scope)),bbBool(l_inh));
          this->m_EmitMembers(BB_T("struct"),((t_mx2_Scope*)(f2.l_ctype->m_scope)),bbBool(l_inh));
          this->m_EmitMembers(BB_T("class"),((t_mx2_Scope*)(f2.l_ctype->m_scope)),bbBool(l_inh));
          this->m_EmitMembers(BB_T("interface"),((t_mx2_Scope*)(f2.l_ctype->m_scope)),bbBool(l_inh));
          this->m_EmitMembers(BB_T("const"),((t_mx2_Scope*)(f2.l_ctype->m_scope)),bbBool(l_inh));
          this->m_EmitMembers(BB_T("global"),((t_mx2_Scope*)(f2.l_ctype->m_scope)),bbBool(l_inh));
          this->m_EmitMembers(BB_T("field"),((t_mx2_Scope*)(f2.l_ctype->m_scope)),bbBool(l_inh));
          this->m_EmitMembers(BB_T("property"),((t_mx2_Scope*)(f2.l_ctype->m_scope)),bbBool(l_inh));
          this->m_EmitMembers(BB_T("constructor"),((t_mx2_Scope*)(f2.l_ctype->m_scope)),bbBool(l_inh));
          this->m_EmitMembers(BB_T("operator"),((t_mx2_Scope*)(f2.l_ctype->m_scope)),bbBool(l_inh));
          this->m_EmitMembers(BB_T("method"),((t_mx2_Scope*)(f2.l_ctype->m_scope)),bbBool(l_inh));
          this->m_EmitMembers(BB_T("function"),((t_mx2_Scope*)(f2.l_ctype->m_scope)),bbBool(l_inh));
        }
      }
      bbString l_docs=this->m__0md->m_Flush();
      bbString l_page=this->m_DeclPath(((t_mx2_Decl*)(f2.l_ctype->m_cdecl)),f2.l_ctype->m_scope->m_outer);
      this->m_SavePage(l_docs,l_page);
      this->m_EmitNode(((t_mx2_Decl*)(f2.l_ctype->m_cdecl)),((t_mx2_Scope*)(f2.l_ctype->m_scope)),l_page);
    }
  }
}

void t_mx2_docs_DocsMaker::m_EmitAliases(t_mx2_Scope* l_scope,bbString l_kind){
  {
    struct f1_t : public bbGCFrame{
      t_std_collections_Map_1sTt_mx2_SNode_2_Iterator l_0{};
      void gcMark(){
        bbGCMark(l_0);
      }
    }f1{};
    f1.l_0=l_scope->m_nodes->m_All();
    for(;f1.l_0.m_Valid();f1.l_0.m_Bump()){
      struct f2_t : public bbGCFrame{
        t_mx2_AliasType* l_atype{};
        t_mx2_AliasDecl* l_decl{};
        t_std_collections_Map_1sTt_mx2_SNode_2_Node* l_node{};
        void gcMark(){
          bbGCMarkPtr(l_atype);
          bbGCMarkPtr(l_decl);
          bbGCMarkPtr(l_node);
        }
      }f2{};
      f2.l_node=f1.l_0.m_Current();
      f2.l_atype=bb_object_cast<t_mx2_AliasType*>(f2.l_node->m_Value());
      if(!bbBool(f2.l_atype)){
        continue;
      }
      f2.l_decl=f2.l_atype->m_adecl;
      if(((f2.l_decl->m_kind!=l_kind)||this->m_DocsHidden(((t_mx2_Decl*)(f2.l_decl))))){
        continue;
      }
      this->m__0linkScope=f2.l_atype->m_scope;
      this->m_EmitHeader(((t_mx2_Decl*)(f2.l_decl)),f2.l_atype->m_scope);
      this->m__0md->m_Emit((((BB_T("##### Alias ")+this->m_DeclIdent(((t_mx2_Decl*)(f2.l_decl)),true))+BB_T(" : "))+this->m_TypeName(f2.l_atype->m__0alias,f2.l_atype->m_scope)));
      this->m__0md->m_Emit(f2.l_decl->m_docs);
      bbString l_docs=this->m__0md->m_Flush();
      bbString l_page=this->m_DeclPath(((t_mx2_Decl*)(f2.l_atype->m_adecl)),f2.l_atype->m_scope);
      this->m_SavePage(l_docs,l_page);
      this->m_EmitLeaf(((t_mx2_Decl*)(f2.l_atype->m_adecl)),l_page);
    }
  }
}

bbBool t_mx2_docs_DocsMaker::m_DocsHidden(t_mx2_Decl* l_decl){
  return ((l_decl->m_IsPrivate()&&!bbBool(l_decl->m_docs))||l_decl->m_docs.startsWith(BB_T("@hidden")));
}

bbString t_mx2_docs_DocsMaker::m_DeclSlug(t_mx2_Decl* l_decl,t_mx2_Scope* l_scope){
  bbString l_module=l_scope->m_FindFile()->m_fdecl->m_module->m_name;
  bbString l_slug=((l_module+BB_T(":"))+this->m_DeclPath(l_decl,l_scope).replace(BB_T("."),BB_T("-")));
  return l_slug;
}

bbString t_mx2_docs_DocsMaker::m_DeclPath(t_mx2_Decl* l_decl,t_mx2_Scope* l_scope){
  bbString l_ident=l_decl->m_ident.replace(BB_T("@"),bbString{});
  if(!g_std_stringio_IsIdent(l_ident[bbInt(0)])){
    l_ident=g_mx2_OpSym(l_ident);
  }
  bbString l_slug=((l_scope->m_Name()+BB_T("."))+l_ident);
  for(;;){
    bbInt l_i=l_slug.find(BB_T("<"),bbInt(0));
    if((l_i==-1)){
      break;
    }
    bbInt l_i2=l_slug.find(BB_T(">"),(l_i+1));
    if((l_i2==-1)){
      break;
    }
    l_slug=(l_slug.slice(bbInt(0),l_i)+l_slug.slice((l_i2+1)));
  }
  return l_slug;
}

bbString t_mx2_docs_DocsMaker::m_DeclName(t_mx2_Decl* l_decl,t_mx2_Scope* l_scope){
  struct f0_t : public bbGCFrame{
    t_mx2_NamespaceScope* l_nmspace{};
    t_mx2_Scope* l_scope{};
    f0_t(t_mx2_Scope* l_scope):l_scope(l_scope){
    }
    void gcMark(){
      bbGCMarkPtr(l_nmspace);
      bbGCMarkPtr(l_scope);
    }
  }f0{l_scope};
  bbString l_path=bbString{};
  f0.l_nmspace=f0.l_scope->m_FindFile()->m_nmspace;
  while((f0.l_scope!=((t_mx2_Scope*)(f0.l_nmspace)))){
    struct f1_t : public bbGCFrame{
      t_mx2_ClassScope* l_cscope{};
      void gcMark(){
        bbGCMarkPtr(l_cscope);
      }
    }f1{};
    if(!bbBool(f0.l_scope)){
      return BB_T("?????");
    }
    f1.l_cscope=bb_object_cast<t_mx2_ClassScope*>(f0.l_scope);
    if(bbBool(f1.l_cscope)){
      struct f2_t : public bbGCFrame{
        t_mx2_ClassDecl* l_decl{};
        void gcMark(){
          bbGCMarkPtr(l_decl);
        }
      }f2{};
      f2.l_decl=f1.l_cscope->m_ctype->m_cdecl;
      l_path=((this->m_DeclIdent(((t_mx2_Decl*)(f2.l_decl)),f1.l_cscope->m_outer,true)+BB_T("."))+l_path);
    }
    f0.l_scope=f0.l_scope->m_outer;
  }
  if(bbBool(l_path)){
    l_path=(l_path.slice(bbInt(0),-1)+BB_T("."));
  }
  return (l_path+this->m_DeclIdent(l_decl,false));
}

bbString t_mx2_docs_DocsMaker::m_DeclIdent(t_mx2_Decl* l_decl,t_mx2_Scope* l_scope,bbBool l_gen){
  return this->m_MakeLink(this->m_DeclIdent(l_decl,l_gen),l_decl,l_scope);
}

bbString t_mx2_docs_DocsMaker::m_DeclIdent(t_mx2_Decl* l_decl,bbBool l_gen){
  bbString l_ident=l_decl->m_ident;
  if(l_decl->m_IsOperator()){
    l_ident=(BB_T("Operator ")+l_ident);
  }else if((l_ident==BB_T("new"))){
    l_ident=BB_T("New");
  }else if(l_ident.startsWith(BB_T("@"))){
    l_ident=l_ident.slice(1).capitalize();
  }
  if(l_gen){
    struct f1_t : public bbGCFrame{
      t_mx2_AliasDecl* l_adecl{};
      t_mx2_ClassDecl* l_cdecl{};
      t_mx2_FuncDecl* l_fdecl{};
      void gcMark(){
        bbGCMarkPtr(l_adecl);
        bbGCMarkPtr(l_cdecl);
        bbGCMarkPtr(l_fdecl);
      }
    }f1{};
    f1.l_adecl=bb_object_cast<t_mx2_AliasDecl*>(l_decl);
    if((bbBool(f1.l_adecl)&&bbBool(f1.l_adecl->m_genArgs))){
      l_ident+=((BB_T("<")+BB_T(",").join(f1.l_adecl->m_genArgs))+BB_T(">"));
    }
    f1.l_cdecl=bb_object_cast<t_mx2_ClassDecl*>(l_decl);
    if((bbBool(f1.l_cdecl)&&bbBool(f1.l_cdecl->m_genArgs))){
      l_ident+=((BB_T("<")+BB_T(",").join(f1.l_cdecl->m_genArgs))+BB_T(">"));
    }
    f1.l_fdecl=bb_object_cast<t_mx2_FuncDecl*>(l_decl);
    if((bbBool(f1.l_fdecl)&&bbBool(f1.l_fdecl->m_genArgs))){
      l_ident+=((BB_T("<")+BB_T(",").join(f1.l_fdecl->m_genArgs))+BB_T(">"));
    }
  }
  return this->m_Esc(l_ident);
}

bbString t_mx2_docs_DocsMaker::m_DeclDesc(t_mx2_Decl* l_decl){
  bbString l_desc=l_decl->m_docs;
  bbInt l_i=l_desc.find(BB_T("\n"),bbInt(0));
  if((l_i!=-1)){
    l_desc=l_desc.slice(bbInt(0),l_i);
  }
  return l_desc;
}

void t_mx2_docs_DocsMaker::m_BeginNode(bbString l_name,bbString l_page){
  if(bbBool(l_page)){
    l_page=((((BB_T(",data:{page:'")+this->m__0module->m_name)+BB_T(":"))+l_page)+BB_T("'}"));
  }
  this->m__0nav->m_Emit(((((BB_T("{ text:'")+l_name)+BB_T("'"))+l_page)+BB_T(",children:[")));
}

void mx2_mx2cc_docs_2docsmaker_init(){
  static bool done;
  if(done) return;
  done=true;
  g_mx2_docs_PAGES_0DIR=BB_T("docs/__PAGES__/");
}

bbInit mx2_mx2cc_docs_2docsmaker_init_v("mx2cc_docs_2docsmaker",&mx2_mx2cc_docs_2docsmaker_init);
