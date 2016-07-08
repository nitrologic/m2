
#ifndef MX2_MX2CC_MX2CC_H
#define MX2_MX2CC_MX2CC_H

#include <bbmonkey.h>

// ***** External *****

struct t_std_collections_Stack_1s;
struct t_std_collections_Map_1sTt_std_collections_Stack_1s_2;
struct t_mx2_BuildOpts;

// ***** Internal *****

extern bbString g_mx2cc_StartDir;
extern bbString g_mx2cc_TestArgs;

extern void g_mx2cc_Fail(bbString l_msg);
extern bbString g_mx2cc_ReplaceEnv(bbString l_str,bbInt l_lineid);
extern bbBool g_mx2cc_LoadEnv(bbString l_path);
extern bbArray<bbString>* g_mx2cc_EnumModules();
extern void g_mx2cc_EnumModules(t_std_collections_Stack_1s* l_out,bbString l_cur,t_std_collections_Map_1sTt_std_collections_Stack_1s_2* l_deps);
extern bbArray<bbString>* g_mx2cc_ParseOpts(t_mx2_BuildOpts* l_opts,bbArray<bbString>* l_args);
extern void g_mx2cc_MakeDocs(bbArray<bbString>* l_args);
extern void g_mx2cc_MakeMods(bbArray<bbString>* l_args);
extern void g_mx2cc_MakeApp(bbArray<bbString>* l_args);
extern void bbMain();

#endif
