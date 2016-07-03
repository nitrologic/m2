
#ifndef MX2_MX2CC_DOCS_2DOCSMAKER_H
#define MX2_MX2CC_DOCS_2DOCSMAKER_H

#include <bbmonkey.h>

// ***** External *****

#include "../../../../../modules/monkey/monkey.buildv1.0.0/desktop_release_linux/monkey_types.h"

struct t_mx2_docs_JsonBuffer;
struct t_mx2_docs_MarkdownBuffer;
struct t_mx2_Module;
struct t_mx2_Scope;
struct t_mx2_Type;
struct t_mx2_NamespaceScope;
struct t_mx2_Decl;

// ***** Internal *****

struct t_mx2_docs_DocsMaker;

extern bbString g_mx2_docs_PAGES_0DIR;

struct t_mx2_docs_DocsMaker : public bbObject{

  const char *typeName()const{return "t_mx2_docs_DocsMaker";}

  bbGCVar<t_mx2_docs_JsonBuffer> m__0nav{};
  bbGCVar<t_mx2_docs_MarkdownBuffer> m__0md{};
  bbGCVar<t_mx2_Module> m__0module{};
  bbString m__0pagesDir{};
  bbString m__0pageTemplate{};
  bbGCVar<t_mx2_Scope> m__0linkScope{};

  void gcMark();

  t_mx2_docs_DocsMaker();

  bbString m_TypeName(t_mx2_Type* l_type,t_mx2_Scope* l_scope);
  bbString m_TypeName(t_mx2_Type* l_type,bbString l_prefix);
  void m_SavePage(bbString l_docs,bbString l_page);
  bbString m_ResolveLink(bbString l_path,t_mx2_Scope* l_scope);
  bbString m_NamespaceSlug(t_mx2_NamespaceScope* l_nmspace);
  bbString m_NamespacePath(t_mx2_NamespaceScope* l_nmspace);
  bbString m_MakeLink(bbString l_text,t_mx2_NamespaceScope* l_nmspace);
  bbString m_MakeLink(bbString l_text,t_mx2_Decl* l_decl,t_mx2_Scope* l_scope);
  bbString m_MakeLangNav();
  bbString m_MakeDocs(t_mx2_Module* l_module);
  bbString m_Esc(bbString l_id);
  void m_EndNode();
  void m_EmitVars(t_mx2_Scope* l_scope,bbString l_kind);
  void m_EmitProperties(t_mx2_Scope* l_scope,bbString l_kind);
  void m_EmitNode(bbString l_name,t_mx2_Scope* l_scope,bbString l_page);
  void m_EmitNode(t_mx2_Decl* l_decl,t_mx2_Scope* l_scope,bbString l_page);
  void m_EmitNamespace(t_mx2_NamespaceScope* l_nmspace,bbString l_docs);
  void m_EmitMembers(bbString l_kind,t_mx2_Scope* l_scope,bbBool l_inherited);
  void m_EmitLeaf(t_mx2_Decl* l_decl,bbString l_page);
  void m_EmitLeaf(bbString l_name,bbString l_page);
  void m_EmitHeader(t_mx2_Decl* l_decl,t_mx2_Scope* l_scope);
  void m_EmitFuncs(t_mx2_Scope* l_scope,bbString l_kind);
  void m_EmitEnums(t_mx2_Scope* l_scope,bbString l_kind);
  void m_EmitClasses(t_mx2_Scope* l_scope,bbString l_kind);
  void m_EmitAliases(t_mx2_Scope* l_scope,bbString l_kind);
  bbBool m_DocsHidden(t_mx2_Decl* l_decl);
  bbString m_DeclSlug(t_mx2_Decl* l_decl,t_mx2_Scope* l_scope);
  bbString m_DeclPath(t_mx2_Decl* l_decl,t_mx2_Scope* l_scope);
  bbString m_DeclName(t_mx2_Decl* l_decl,t_mx2_Scope* l_scope);
  bbString m_DeclIdent(t_mx2_Decl* l_decl,t_mx2_Scope* l_scope,bbBool l_gen);
  bbString m_DeclIdent(t_mx2_Decl* l_decl,bbBool l_gen);
  bbString m_DeclDesc(t_mx2_Decl* l_decl);
  void m_BeginNode(bbString l_name,bbString l_page);
};

#endif
