
#ifndef MX2_MX2CC_ERRORS_H
#define MX2_MX2CC_ERRORS_H

#include <bbmonkey.h>

// ***** External *****

#include "../../../../../modules/monkey/monkey.buildv1.0.0/desktop_release_linux/monkey_types.h"

struct t_mx2_PNode;
struct t_mx2_Value;
struct t_mx2_Type;

// ***** Internal *****

struct t_mx2_ErrorEx;
struct t_mx2_ParseEx;
struct t_mx2_SemantEx;
struct t_mx2_BuildEx;
struct t_mx2_TransEx;
struct t_mx2_IdentEx;
struct t_mx2_TypeIdentEx;
struct t_mx2_UpCastEx;
struct t_mx2_OverloadEx;

extern void g_mx2_TransError(bbString l_func);
extern void g_mx2_SemantError(bbString l_func);

struct t_mx2_ErrorEx : public bbThrowable{

  const char *typeName()const{return "t_mx2_ErrorEx";}

  bbString m_msg{};

  t_mx2_ErrorEx(bbString l_msg);

  virtual bbString m_ToString();

  t_mx2_ErrorEx(){
  }
};

struct t_mx2_ParseEx : public t_mx2_ErrorEx{

  const char *typeName()const{return "t_mx2_ParseEx";}

  bbString m_srcfile{};
  bbInt m_srcpos{};

  t_mx2_ParseEx(bbString l_msg,bbString l_srcfile,bbInt l_srcpos);

  bbString m_ToString();

  t_mx2_ParseEx(){
  }
};

struct t_mx2_SemantEx : public t_mx2_ErrorEx{

  const char *typeName()const{return "t_mx2_SemantEx";}

  bbGCVar<t_mx2_PNode> m_pnode{};

  void gcMark();

  t_mx2_SemantEx(bbString l_msg,t_mx2_PNode* l_pnode);
  t_mx2_SemantEx(bbString l_msg);

  bbString m_ToString();

  t_mx2_SemantEx(){
  }
};

struct t_mx2_BuildEx : public t_mx2_ErrorEx{

  const char *typeName()const{return "t_mx2_BuildEx";}

  t_mx2_BuildEx(bbString l_msg);

  bbString m_ToString();

  t_mx2_BuildEx(){
  }
};

struct t_mx2_TransEx : public t_mx2_BuildEx{

  const char *typeName()const{return "t_mx2_TransEx";}

  t_mx2_TransEx(bbString l_msg);

  bbString m_ToString();

  t_mx2_TransEx(){
  }
};

struct t_mx2_IdentEx : public t_mx2_SemantEx{

  const char *typeName()const{return "t_mx2_IdentEx";}

  t_mx2_IdentEx(bbString l_ident);

  t_mx2_IdentEx(){
  }
};

struct t_mx2_TypeIdentEx : public t_mx2_SemantEx{

  const char *typeName()const{return "t_mx2_TypeIdentEx";}

  t_mx2_TypeIdentEx(bbString l_ident);

  t_mx2_TypeIdentEx(){
  }
};

struct t_mx2_UpCastEx : public t_mx2_SemantEx{

  const char *typeName()const{return "t_mx2_UpCastEx";}

  t_mx2_UpCastEx(t_mx2_Value* l_value,t_mx2_Type* l_type);

  t_mx2_UpCastEx(){
  }
};

struct t_mx2_OverloadEx : public t_mx2_SemantEx{

  const char *typeName()const{return "t_mx2_OverloadEx";}

  t_mx2_OverloadEx(t_mx2_Value* l_value,bbArray<bbGCVar<t_mx2_Type>>* l_args);
  t_mx2_OverloadEx(t_mx2_Value* l_value,bbArray<bbGCVar<t_mx2_Value>>* l_args);

  t_mx2_OverloadEx(){
  }
};

#endif
