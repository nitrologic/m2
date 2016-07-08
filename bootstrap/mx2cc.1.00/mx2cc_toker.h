
#ifndef MX2_MX2CC_TOKER_H
#define MX2_MX2CC_TOKER_H

#include <bbmonkey.h>

// ***** External *****

#include "../../../../../modules/monkey/monkey.buildv1.0.0/desktop_release_linux/monkey_types.h"

struct t_std_collections_Map_1ss;

// ***** Internal *****

struct t_mx2_Toker;

extern bbInt g_mx2_TOKE_0EOF;
extern bbInt g_mx2_TOKE_0EOL;
extern bbInt g_mx2_TOKE_0IDENT;
extern bbInt g_mx2_TOKE_0KEYWORD;
extern bbInt g_mx2_TOKE_0INTLIT;
extern bbInt g_mx2_TOKE_0FLOATLIT;
extern bbInt g_mx2_TOKE_0STRINGLIT;
extern bbInt g_mx2_TOKE_0SYMBOL;
extern bbInt g_mx2_TOKE_0BADSTRINGLIT;
extern bbInt g_mx2_TOKE_0PREPROC;
extern bbGCRootVar<t_std_collections_Map_1ss> g_mx2_KeyWords;
extern bbGCRootVar<bbArray<bbString>> g_mx2_trigraphs;
extern bbGCRootVar<bbArray<bbString>> g_mx2_digraphs;
extern bbBool g_mx2_tokerInited;

extern void g_mx2_InitToker();

struct t_mx2_Toker : public bbObject{

  const char *typeName()const{return "t_mx2_Toker";}

  bbString m__0text{};
  bbInt m__0len{};
  bbInt m__0pos{};
  bbString m__0toke{};
  bbInt m__0tokeType{};
  bbInt m__0tokePos{};
  bbInt m__0line{};
  bbInt m__0srcPos{};
  bbInt m__0endPos{};
  bbInt m__0linePos{};

  t_mx2_Toker(t_mx2_Toker* l_toker);
  t_mx2_Toker(bbString l_text);
  t_mx2_Toker();

  bbInt m_TokeType();
  bbInt m_TokePos();
  bbString m_Toke();
  void m_Text(bbString l_text);
  bbString m_Text();
  void m_State(t_mx2_Toker* l_toker);
  t_mx2_Toker* m_State();
  bbInt m_SrcPos();
  bbInt m_LinePos();
  bbInt m_Line();
  bbInt m_EndPos();
  bbString m_Bump();
};

#endif
