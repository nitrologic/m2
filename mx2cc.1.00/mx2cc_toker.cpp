
#include "mx2cc_toker.h"

// ***** External *****

#include "mx2cc_std_collections_2map.h"

extern bbInt g_mx2_CHAR_0EOL;
extern bbInt g_mx2_CHAR_0UNDERSCORE;
extern bbInt g_mx2_CHAR_0DOT;
extern bbInt g_mx2_CHAR_0QUOTE;
extern bbInt g_mx2_CHAR_0DOLLAR;
extern bbInt g_mx2_CHAR_0HASH;
extern bbInt g_mx2_CHAR_0APOSTROPHE;

extern bbBool g_std_stringio_IsAlpha(bbInt l_chr);
extern bbBool g_std_stringio_IsIdent(bbInt l_chr);
extern bbBool g_std_stringio_IsDigit(bbInt l_chr);
extern bbBool g_std_stringio_IsHexDigit(bbInt l_chr);

// ***** Internal *****

bbInt g_mx2_TOKE_0EOF;
bbInt g_mx2_TOKE_0EOL;
bbInt g_mx2_TOKE_0IDENT;
bbInt g_mx2_TOKE_0KEYWORD;
bbInt g_mx2_TOKE_0INTLIT;
bbInt g_mx2_TOKE_0FLOATLIT;
bbInt g_mx2_TOKE_0STRINGLIT;
bbInt g_mx2_TOKE_0SYMBOL;
bbInt g_mx2_TOKE_0BADSTRINGLIT;
bbInt g_mx2_TOKE_0PREPROC;
bbGCRootVar<t_std_collections_Map_1ss> g_mx2_KeyWords;
bbGCRootVar<bbArray<bbString>> g_mx2_trigraphs;
bbGCRootVar<bbArray<bbString>> g_mx2_digraphs;
bbBool g_mx2_tokerInited;

void g_mx2_InitToker(){
  if(g_mx2_tokerInited){
    return;
  }
  g_mx2_tokerInited=true;
  bbString l_keyWords=BB_T("Namespace;Using;Import;Extern;");
  l_keyWords+=BB_T("Public;Private;Protected;Internal;Friend;");
  l_keyWords+=BB_T("Void;Bool;Byte;UByte;Short;UShort;Int;UInt;Long;ULong;Float;Double;String;Object;Continue;Exit;");
  l_keyWords+=BB_T("New;Self;Super;Eachin;True;False;Null;Where;");
  l_keyWords+=BB_T("Alias;Const;Local;Global;Field;Method;Function;Property;Getter;Setter;Operator;Lambda;");
  l_keyWords+=BB_T("Enum;Class;Interface;Struct;Extends;Implements;Virtual;Override;Abstract;Final;Inline;");
  l_keyWords+=BB_T("Var;Varptr;Ptr;");
  l_keyWords+=BB_T("Not;Mod;And;Or;Shl;Shr;End;");
  l_keyWords+=BB_T("If;Then;Else;Elseif;Endif;");
  l_keyWords+=BB_T("While;Wend;");
  l_keyWords+=BB_T("Repeat;Until;Forever;");
  l_keyWords+=BB_T("For;To;Step;Next;");
  l_keyWords+=BB_T("Select;Case;Default;");
  l_keyWords+=BB_T("Try;Catch;Throw;Throwable;");
  l_keyWords+=BB_T("Return;Print;Static;Cast;");
  l_keyWords+=BB_T("Extension;Protocol;Delete");
  g_mx2_KeyWords=bbGCNew<t_std_collections_Map_1ss>();
  {
    struct f1_t : public bbGCFrame{
      bbArray<bbString>* l_0{};
      void gcMark(){
        bbGCMarkPtr(l_0);
      }
    }f1{};
    f1.l_0=l_keyWords.split(BB_T(";"));
    bbInt l_1=bbInt(0);
    bbInt l_2=f1.l_0->length();
    for(;(l_1<l_2);l_1+=1){
      bbString l_kw=f1.l_0->at(l_1);
      g_mx2_KeyWords->m_Set(l_kw.toLower(),l_kw);
    }
  }
  g_mx2_trigraphs=BB_T("<=>").split(BB_T(","));
  g_mx2_digraphs=BB_T("->,:=,*=,/=,+=,-=,&=,|=,~=,<=,>=,<>").split(BB_T(","));
}

t_mx2_Toker::t_mx2_Toker(t_mx2_Toker* l_toker){
  g_mx2_InitToker();
  this->m_State(l_toker);
}

t_mx2_Toker::t_mx2_Toker(bbString l_text){
  g_mx2_InitToker();
  this->m_Text(l_text);
}

t_mx2_Toker::t_mx2_Toker(){
  g_mx2_InitToker();
  this->m_Text(bbString{});
}

bbInt t_mx2_Toker::m_TokeType(){
  return this->m__0tokeType;
}

bbInt t_mx2_Toker::m_TokePos(){
  return this->m__0tokePos;
}

bbString t_mx2_Toker::m_Toke(){
  return this->m__0toke;
}

void t_mx2_Toker::m_Text(bbString l_text){
  this->m__0text=l_text;
  this->m__0len=this->m__0text.length();
  this->m__0pos=bbInt(0);
  this->m__0toke=bbString{};
  this->m__0tokePos=bbInt(0);
  this->m__0tokeType=g_mx2_TOKE_0EOL;
  this->m__0line=bbInt(0);
  this->m__0srcPos=bbInt(0);
  this->m__0endPos=bbInt(0);
  this->m__0linePos=bbInt(0);
}

bbString t_mx2_Toker::m_Text(){
  return this->m__0text;
}

void t_mx2_Toker::m_State(t_mx2_Toker* l_toker){
  this->m__0text=l_toker->m__0text;
  this->m__0len=l_toker->m__0len;
  this->m__0pos=l_toker->m__0pos;
  this->m__0toke=l_toker->m__0toke;
  this->m__0tokePos=l_toker->m__0tokePos;
  this->m__0tokeType=l_toker->m__0tokeType;
  this->m__0line=l_toker->m__0line;
  this->m__0srcPos=l_toker->m__0srcPos;
  this->m__0endPos=l_toker->m__0endPos;
  this->m__0linePos=l_toker->m__0linePos;
}

t_mx2_Toker* t_mx2_Toker::m_State(){
  return bbGCNew<t_mx2_Toker>(this);
}

bbInt t_mx2_Toker::m_SrcPos(){
  return this->m__0srcPos;
}

bbInt t_mx2_Toker::m_LinePos(){
  return this->m__0linePos;
}

bbInt t_mx2_Toker::m_Line(){
  return this->m__0line;
}

bbInt t_mx2_Toker::m_EndPos(){
  return this->m__0endPos;
}

bbString t_mx2_Toker::m_Bump(){
  bbBool l_newLine=false;
  if(((this->m__0tokeType==g_mx2_TOKE_0EOL)||(this->m__0tokeType==g_mx2_TOKE_0PREPROC))){
    this->m__0line+=1;
    this->m__0linePos=this->m__0pos;
    l_newLine=true;
  }
  while((((this->m__0pos<this->m__0len)&&(this->m__0text[this->m__0pos]<=32))&&(this->m__0text[this->m__0pos]!=g_mx2_CHAR_0EOL))){
    this->m__0pos+=1;
  }
  this->m__0tokePos=this->m__0pos;
  this->m__0endPos=(this->m__0srcPos+this->m__0toke.length());
  this->m__0srcPos=((this->m__0line<<12)|(this->m__0tokePos-this->m__0linePos));
  if((this->m__0pos==this->m__0len)){
    this->m__0toke=bbString{};
    this->m__0tokeType=g_mx2_TOKE_0EOF;
    return this->m__0toke;
  }
  bbInt l_ch=this->m__0text[this->m__0pos];
  this->m__0pos+=1;
  if((g_std_stringio_IsAlpha(l_ch)||(l_ch==g_mx2_CHAR_0UNDERSCORE))){
    while((this->m__0pos<this->m__0len)){
      bbInt l_ch=this->m__0text[this->m__0pos];
      if(!g_std_stringio_IsIdent(l_ch)){
        break;
      }
      this->m__0pos+=1;
    }
    this->m__0toke=this->m__0text.slice(this->m__0tokePos,this->m__0pos);
    bbString l_kw=this->m__0toke.toLower();
    if(bbBool(g_mx2_KeyWords->m_Get(l_kw))){
      this->m__0toke=l_kw;
      this->m__0tokeType=g_mx2_TOKE_0KEYWORD;
    }else{
      this->m__0tokeType=g_mx2_TOKE_0IDENT;
    }
    return this->m__0toke;
  }else if((g_std_stringio_IsDigit(l_ch)||(((l_ch==g_mx2_CHAR_0DOT)&&(this->m__0pos<this->m__0len))&&g_std_stringio_IsDigit(this->m__0text[this->m__0pos])))){
    this->m__0tokeType=g_mx2_TOKE_0INTLIT;
    if((l_ch==g_mx2_CHAR_0DOT)){
      this->m__0tokeType=g_mx2_TOKE_0FLOATLIT;
      this->m__0pos+=1;
    }
    while(((this->m__0pos<this->m__0len)&&g_std_stringio_IsDigit(this->m__0text[this->m__0pos]))){
      this->m__0pos+=1;
    }
    if((((((this->m__0pos+1)<this->m__0len)&&(this->m__0text[this->m__0pos]==g_mx2_CHAR_0DOT))&&g_std_stringio_IsDigit(this->m__0text[(this->m__0pos+1)]))&&(this->m__0tokeType==g_mx2_TOKE_0INTLIT))){
      this->m__0tokeType=g_mx2_TOKE_0FLOATLIT;
      this->m__0pos+=2;
      while(((this->m__0pos<this->m__0len)&&g_std_stringio_IsDigit(this->m__0text[this->m__0pos]))){
        this->m__0pos+=1;
      }
    }
    if((((this->m__0pos+1)<this->m__0len)&&((this->m__0text[this->m__0pos]==69)||(this->m__0text[this->m__0pos]==101)))){
      bbInt l_tpos=(this->m__0pos+1);
      if(((this->m__0text[l_tpos]==43)||(this->m__0text[l_tpos]==45))){
        l_tpos+=1;
      }
      if(((l_tpos<this->m__0len)&&g_std_stringio_IsDigit(this->m__0text[l_tpos]))){
        this->m__0tokeType=g_mx2_TOKE_0FLOATLIT;
        this->m__0pos=(l_tpos+1);
        while(((this->m__0pos<this->m__0len)&&g_std_stringio_IsDigit(this->m__0text[this->m__0pos]))){
          this->m__0pos+=1;
        }
      }
    }
  }else if((l_ch==g_mx2_CHAR_0QUOTE)){
    while((this->m__0pos<this->m__0len)){
      bbInt l_ch=this->m__0text[this->m__0pos];
      if(((l_ch==g_mx2_CHAR_0QUOTE)||(l_ch==g_mx2_CHAR_0EOL))){
        break;
      }
      this->m__0pos+=1;
    }
    if(((this->m__0pos<this->m__0len)&&(this->m__0text[this->m__0pos]==g_mx2_CHAR_0QUOTE))){
      this->m__0tokeType=g_mx2_TOKE_0STRINGLIT;
      this->m__0pos+=1;
    }else{
      this->m__0tokeType=g_mx2_TOKE_0BADSTRINGLIT;
    }
  }else if((((l_ch==g_mx2_CHAR_0DOLLAR)&&(this->m__0pos<this->m__0len))&&g_std_stringio_IsHexDigit(this->m__0text[this->m__0pos]))){
    this->m__0pos+=1;
    while(((this->m__0pos<this->m__0len)&&g_std_stringio_IsHexDigit(this->m__0text[this->m__0pos]))){
      this->m__0pos+=1;
    }
    this->m__0tokeType=g_mx2_TOKE_0INTLIT;
  }else if(((l_ch==g_mx2_CHAR_0HASH)&&l_newLine)){
    while(((this->m__0pos<this->m__0len)&&(this->m__0text[this->m__0pos]!=g_mx2_CHAR_0EOL))){
      this->m__0pos+=1;
    }
    if((this->m__0pos<this->m__0len)){
      this->m__0pos+=1;
    }
    this->m__0tokeType=g_mx2_TOKE_0PREPROC;
  }else if((l_ch==g_mx2_CHAR_0APOSTROPHE)){
    while(((this->m__0pos<this->m__0len)&&(this->m__0text[this->m__0pos]!=g_mx2_CHAR_0EOL))){
      this->m__0pos+=1;
    }
    this->m__0tokePos=this->m__0pos;
    if((this->m__0pos<this->m__0len)){
      this->m__0pos+=1;
    }
    this->m__0tokeType=g_mx2_TOKE_0EOL;
  }else if((l_ch==g_mx2_CHAR_0EOL)){
    this->m__0tokeType=g_mx2_TOKE_0EOL;
  }else{
    bbBool l_found=false;
    if((this->m__0pos<(this->m__0len-1))){
      bbInt l_ch2=this->m__0text[this->m__0pos];
      bbInt l_ch3=this->m__0text[(this->m__0pos+1)];
      {
        bbInt l_0=bbInt(0);
        bbInt l_1=g_mx2_trigraphs->length();
        for(;(l_0<l_1);l_0+=1){
          bbString l_t=g_mx2_trigraphs->at(l_0);
          if((((l_ch==l_t[bbInt(0)])&&(l_ch2==l_t[1]))&&(l_ch3==l_t[2]))){
            this->m__0pos+=2;
            l_found=true;
            break;
          }
        }
      }
    }
    if((!l_found&&(this->m__0pos<this->m__0len))){
      bbInt l_ch2=this->m__0text[this->m__0pos];
      {
        bbInt l_2=bbInt(0);
        bbInt l_3=g_mx2_digraphs->length();
        for(;(l_2<l_3);l_2+=1){
          bbString l_t=g_mx2_digraphs->at(l_2);
          if(((l_ch==l_t[bbInt(0)])&&(l_ch2==l_t[1]))){
            this->m__0pos+=1;
            break;
          }
        }
      }
    }
    this->m__0tokeType=g_mx2_TOKE_0SYMBOL;
  }
  this->m__0toke=this->m__0text.slice(this->m__0tokePos,this->m__0pos);
  return this->m__0toke;
}

void mx2_mx2cc_toker_init(){
  static bool done;
  if(done) return;
  done=true;
  g_mx2_TOKE_0EOF=bbInt(0);
  g_mx2_TOKE_0EOL=1;
  g_mx2_TOKE_0IDENT=2;
  g_mx2_TOKE_0KEYWORD=3;
  g_mx2_TOKE_0INTLIT=4;
  g_mx2_TOKE_0FLOATLIT=5;
  g_mx2_TOKE_0STRINGLIT=6;
  g_mx2_TOKE_0SYMBOL=7;
  g_mx2_TOKE_0BADSTRINGLIT=8;
  g_mx2_TOKE_0PREPROC=9;
}

bbInit mx2_mx2cc_toker_init_v("mx2cc_toker",&mx2_mx2cc_toker_init);
