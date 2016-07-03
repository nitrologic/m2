
#include "mx2cc_node.h"

// ***** External *****

#include "mx2cc_decl.h"
#include "mx2cc_errors.h"
#include "mx2cc_std_collections_2stack.h"

// ***** Internal *****

bbBool g_mx2_DEBUG_0SEMANTS;
bbInt g_mx2_SNODE_0INIT;
bbInt g_mx2_SNODE_0SEMANTING;
bbInt g_mx2_SNODE_0SEMANTED;
bbString g_mx2_SNode_semtab;
bbGCRootVar<t_mx2_FileDecl> g_mx2_PNode_parsing;
bbGCRootVar<t_std_collections_Stack_1Tt_mx2_PNode_2> g_mx2_PNode_semanting;

void t_mx2_SNode::gcMark(){
  bbGCMark(m_pnode);
  bbGCMark(m_semanted);
}

t_mx2_Value* t_mx2_SNode::m_ToValue(t_mx2_Value* l_instance){
  puts(bbString::fromCString(this->typeName()).c_str());fflush( stdout );
  g_mx2_SemantError(BB_T("SNode.ToValue()"));
  return ((t_mx2_Value*)0);
}

t_mx2_Type* t_mx2_SNode::m_ToType(){
  g_mx2_SemantError(BB_T("SNode.ToType()"));
  return ((t_mx2_Type*)0);
}

bbString t_mx2_SNode::m_ToString(){
  if(bbBool(this->m_pnode)){
    return this->m_pnode->m_ToString();
  }
  puts(bbString::fromCString(this->typeName()).c_str());fflush( stdout );
  return BB_T("????? SNode.ToString() ?????");
}

t_mx2_SNode* t_mx2_SNode::m_Semant(){
  if(((this->m_state==g_mx2_SNODE_0SEMANTED)||bbBool(this->m_semanted))){
    return this->m_semanted;
  }
  if((this->m_state==g_mx2_SNODE_0SEMANTING)){
    throw bbGCNew<t_mx2_SemantEx>(((BB_T("Cyclic declaration of '")+this->m_ToString())+BB_T("'")));
  }
  try{
    if((g_mx2_DEBUG_0SEMANTS&&bbBool(this->m_pnode))){
      puts(((g_mx2_SNode_semtab+BB_T("Semanting  "))+this->m_pnode->m_ToString()).c_str());fflush( stdout );
      g_mx2_SNode_semtab+=BB_T("  ");
    }
    this->m_state=g_mx2_SNODE_0SEMANTING;
    g_mx2_PNode_semanting->m_Push(this->m_pnode);
    this->m_semanted=this->m_OnSemant();
    g_mx2_PNode_semanting->m_Pop();
    this->m_state=g_mx2_SNODE_0SEMANTED;
    if((g_mx2_DEBUG_0SEMANTS&&bbBool(this->m_pnode))){
      g_mx2_SNode_semtab=g_mx2_SNode_semtab.slice(bbInt(0),-2);
      puts(((g_mx2_SNode_semtab+BB_T("Semanted   "))+this->m_semanted->m_ToString()).c_str());fflush( stdout );
    }
    return this->m_semanted;
  }catch(t_mx2_SemantEx* ex){
    struct f1_t : public bbGCFrame{
      t_mx2_SemantEx* l_ex{};
      void gcMark(){
        bbGCMarkPtr(l_ex);
      }
    }f1{};
    f1.l_ex=ex;
    g_mx2_PNode_semanting->m_Pop();
    this->m_state=g_mx2_SNODE_0SEMANTED;
    if((g_mx2_DEBUG_0SEMANTS&&bbBool(this->m_pnode))){
      g_mx2_SNode_semtab=g_mx2_SNode_semtab.slice(bbInt(0),-2);
      puts(((g_mx2_SNode_semtab+BB_T("Semant failed for "))+this->m_pnode->m_ToString()).c_str());fflush( stdout );
    }
    throw f1.l_ex;
  }
  return ((t_mx2_SNode*)0);
}

t_mx2_SNode* t_mx2_SNode::m_OnSemant(){
  return this;
}

void t_mx2_PNode::gcMark(){
  bbGCMark(m_srcfile);
}

t_mx2_PNode::t_mx2_PNode(bbInt l_srcpos,bbInt l_endpos){
  this->m_srcfile=g_mx2_PNode_parsing;
  this->m_srcpos=l_srcpos;
  this->m_endpos=l_endpos;
}

t_mx2_PNode::t_mx2_PNode(){
  this->m_srcfile=g_mx2_PNode_parsing;
}

bbString t_mx2_PNode::m_ToString(){
  if(bbBool(this->m_srcfile)){
    return (((this->m_srcfile->m_path+BB_T(" ["))+bbString((this->m_srcpos>>12)))+BB_T("]"));
  }
  return ((BB_T("? [")+bbString((this->m_srcpos>>12)))+BB_T("]"));
}

bbString t_mx2_PNode::m_ToDebugString(){
  if(bbBool(this->m_srcfile)){
    return (((this->m_srcfile->m_path+BB_T(" ["))+bbString((this->m_srcpos>>12)))+BB_T("]"));
  }
  return ((BB_T("? [")+bbString((this->m_srcpos>>12)))+BB_T("]"));
}

void mx2_mx2cc_node_init(){
  static bool done;
  if(done) return;
  done=true;
  g_mx2_DEBUG_0SEMANTS=false;
  g_mx2_SNODE_0INIT=bbInt(0);
  g_mx2_SNODE_0SEMANTING=1;
  g_mx2_SNODE_0SEMANTED=2;
  g_mx2_PNode_semanting=bbGCNew<t_std_collections_Stack_1Tt_mx2_PNode_2>();
}

bbInit mx2_mx2cc_node_init_v("mx2cc_node",&mx2_mx2cc_node_init);
