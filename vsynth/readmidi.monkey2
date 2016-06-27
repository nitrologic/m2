#Import "<std>"

Using std..

Global RIFF:=$46464952
Global RMID:=$44494d52

Global MThd:=$6468544d
Global MTrk:=$6b72544d

Function readTime:Int(p:UByte Ptr)
	Local t:Int	
	While True
		Local u8:=p[0]
		t=(t Shl 7) + u8
		If u8&128 Exit
		p+=1
	Wend
	Return t
End

Function Main()
	Print "readmidi v0.0"
End

#rem

struct synth;
struct track;
struct mtrak;

uint readtime(uchar *&ptr)
{
	uint	t=0;
	do {t=(t<<7)+(*ptr&0x7f);}while (*ptr++&0x80);
	return t;
}

struct mtrak
{
	int		size;
	uchar	*start,*end,*a,cmd;
	uint	stime,ptime;		//sequence time && previous time

	mtrak(uchar *pos,int len)
	{
		uint	t;
		uchar	meta;

		start=pos;
		end=start+len;
		size=0;
		a=start;
		
		while (a<end)
		{
			readtime(a);
			switch (*a)
			{
			case 0xf0:
				a++;t=readtime(a);a+=t;break;
			case 0xff:
				a++;meta=*a++;t=readtime(a);
				switch (meta)
				{
					case (0x51):size+=3;break;
				}
				a+=t;
				break;
			default:
				if (*a & 0x80) cmd=*a++;
				a++;
				if (cmd<0xc0 || cmd>0xdf) a++;
				size+=3;
				break;
			}
		}
		a=start;stime=0;	//running sequencer variables
	}

	uint sequence(uint *data,int &i,uint time,uint &gap)
	{
		uint	etime,t;
		uchar	*bakup,*c,meta;

		while (a<end)
		{
			bakup=a;
			etime=readtime(a)+stime;
			if (etime>time) {a=bakup;return (etime);}
			stime=etime;

			switch (*a)
			{
			case 0xf0:
				a++;t=readtime(a);a+=t;break;
			case 0xff:
				a++;meta=*a++;t=readtime(a);
				switch (meta)
				{
				case (0x51):
					data[i+0]=gap;		//time;
					data[i+1]=0;
					data[i+2]=(MEVT_TEMPO<<24)+(a[0]<<16)+(a[1]<<8)+(a[2]);
					gap=0;i+=3;
					break;
				}
				a+=t;
				break;
			default:
				data[i+0]=gap;			//time;
				data[i+1]=0;
				data[i+2]=0;
				c=(uchar *)&data[i+2];
				if (*a & 0x80) {cmd=*a;a++;}
				*c++=cmd;
				*c++=*a++;
				if (cmd<0xc0 || cmd>0xdf) *c++=*a++;
				gap=0;i+=3;
				break;
			}
		}
		return (0xffffffff);
	}
};

int getlong(uchar *h) {return (h[3])+(h[2]<<8)+(h[1]<<16)+(h[0]<<24);}
int getword(uchar *h) {return (h[1])+(h[0]<<8);}

struct track
{
	int		length;
	uint	*data;
	int		format,tcount,division;
	int		filesize;

	track(int len)
	{
		length=len;data=new uint[len];
	}
	
	track(char *filename)
	{
		uchar	*buffer,*ptr;
		int		len,i,dpos;
		uint	time,ctime,ntime,gap;
		mtrak	*trax[16];
		int		numtrax;

		data=0;length=0;

		buffer=(uchar *)loadfile(filename);
		if (buffer==0) return;

		ptr=buffer;

		if (*(int *)ptr==RIFF && *(int *)(ptr+8)==RMID) ptr+=20;

		numtrax=0;

		while (ptr<buffer+filesize)
		{
			len=getlong(ptr+4);

			switch(*(uint *)ptr)
			{
			case MThd:
				format=getword(ptr+8);
				tcount=getword(ptr+10);
				division=getword(ptr+12);
				break;
			case MTrk:
				trax[numtrax++]=new mtrak(ptr+8,len);
				break;
			}
			ptr+=len+8;
		}

		length=0;for (i=0;i<numtrax;i++) length+=trax[i]->size;
		data=new uint[length];
		
		dpos=0;time=0;gap=0;
		
		while (dpos<length)
		{
			ctime=0xffffffff;
			for (i=0;i<numtrax;i++)
			{
				ntime=trax[i]->sequence(data,dpos,time,gap);
				if (ntime<ctime) ctime=ntime;
			}
			if (ctime==0xffffffff) break;
			gap+=(ctime-time);
			time=ctime;
		}

		for (i=0;i<numtrax;i++) delete trax[i];
	}

	void *loadfile(const char *name,void *dest=0)
	{
		FILE    *file;
		ulong   len;
		char    *start=NULL;

		file=fopen(name,"rb");
		if (!file) return NULL;
		fseek(file,0,SEEK_END);
		len=ftell(file);
		filesize=len;
		if (len)
		{
			rewind(file);
			start=(char*)(dest?dest:malloc(len));
			if (start) fread(start,1,len,file);
		}
		fclose(file);
		return start;
	}
};

#end