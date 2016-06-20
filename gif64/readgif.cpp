// readgif.cpp

#include "host.h"

//int readgif(canvas *m,input *in,int f=0);
void parsegif(canvas *can,input *in,int *pal,int canflags,bool squash);

#define MAXCODES 4096

int CODEMASK[]={0,0x0001,0x0003,0x0007,0x000F,0x001F,0x003F,0x007F,0x00FF,0x01FF,0x03FF,0x07FF,0x0FFF};

short stack[MAXCODES];
short suffix[MAXCODES];
short prefix[MAXCODES];

int buff[256];
int	bbptr,bits,bytes,bval;

int readgif(canvas *root,input *in,int canflags)
{
	canvas		*can;
	int			*pal,bgcol,aspect;
	int			i,r,g,b,w,h,f,n,t;
	int			delay,start,end,loop;

	delay=start=end=loop=0;
// GIF89a
	if (in->read()!='G') return 0;//throw new IOException("gif format error");
	if (in->read()!='I') return 0;//throw new IOException("gif format error");
	if (in->read()!='F') return 0;//throw new IOException("gif format error");
	in->skip(3);	//read();in->read();in->read();	//89a
// screen descriptor
	w=in->readshort();
	h=in->readshort();
	f=in->read();
	bgcol=in->read();
	aspect=in->read();
//	system.debug(" w="+w+" h="+h+" f="+f+" bgcol="+bgcol+" aspect="+aspect);
// global color table
	pal=0;
	can=root;
	if ((f&128)!=0)
	{
		n=2<<(f&7);
		pal=new int[n];
		for (i=0;i<n;i++)
		{
			r=in->read();g=in->read();b=in->read();
			pal[i]=0xff000000|(r<<16)|(g<<8)|(b);
		}
	}
	delay=-1;
// image descriptor

	while (true)
	{
		n=in->read();
		switch (n)
		{
		case -1:
			if (pal) delete pal;
			return 1;

		case 0x2c:
			if (can==0) can=root->clone(canvas::CLONEFRAME);
			parsegif(can,in,pal,canflags,0);
			can->setdelay(delay*10);
			can=0;
			break;

		case 0x21:
			switch (n=in->read())
			{
			case 0xf9:	//graphic control block
				n=in->read();		//blocksize
				f=in->read();		//flags transflag=1
				delay=in->readshort();	//delay
				t=in->read();		//transparency
				if ((f&1)!=0) {pal[t]=0;canflags|=canvas::ALPHA;}
				in->skip(n-4);
				while (true) {n=in->read();if (n==0) break;in->skip(n);}
				break;

			default:
				n=in->read();	//11
				in->skip(n);
				while (true)
				{
					n=in->read();
					if (n==0) break;
					in->skip(n);
				}
				break;
			}
			break;
		}		
	}
}

int lzhread(input *in,int currsize)
{
	int		i,r;

	if (bits==0)
	{
		if (bytes<=0)
		{
			bbptr=0;bytes=in->read();for (i=0;i<bytes;++i) buff[i]=in->read();
		}
		bval=buff[bbptr++];
		bits=8;
		--bytes;
	}

	r=bval>>(8-bits);
	
	while (bits<currsize)
	{
		if (bytes<=0)
		{
			bbptr=0;bytes=in->read();for (i=0;i<bytes;++i) buff[i]=in->read();
		}	
		bval=buff[bbptr++];
		r|=bval<<bits;
		bits+=8;
		--bytes;
	}
	bits-=currsize;
	return r&CODEMASK[currsize];
}

void parsegif(canvas *can,input *in,int *pal,int canflags,bool squash)
{
	int			x,y,w,h,f;			//i,r,g,b,n
	int			size,csize,topslot,clear,ending,slot,newcodes,avail,bitsleft;
	int			c,code,oc,fc,sp,bptr;
	int			yinc,lpass;

	x=in->readshort();
	y=in->readshort();
	w=in->readshort();
	h=in->readshort();
	f=in->read();

	lpass=0;yinc=1;if ((f&64)!=0) yinc=8;

	can->sethandle(-x,-y);

	if (squash)
		can->resize(w,(h+1)>>1,canflags,false);
	else
		can->resize(w,h,canflags,false);

// image data
	size=in->read();//system.debug("size="+size);
	csize=size+1;topslot=1<<csize;clear=1<<size;ending=clear+1;
	slot=newcodes=ending+1;avail=bitsleft=0;oc=fc=sp=bptr=0;
	bbptr=0;bits=0;bytes=0;bval=0;	//reset lzh globals
	x=y=0;

	nitro->lock(can,canvas::WRITELOCK);

	while ((c=lzhread(in,csize))!=ending)
	{
		if (c==clear)
		{
			csize=size+1;
			slot=newcodes;
			topslot=1<<csize;
			while ((c=lzhread(in,csize))==clear) {}
			if (c==ending) break;
			if (c>=slot) c=0;
			oc=fc=c;
			if (squash)
			{
				if ((x&1)==(y&1)) can->writepixel(x,y>>1,pal[c]);
			}
			else
			{
				can->writepixel(x,y,pal[c]);
			}
			x++;if (x==w) {x=0;y+=yinc;if (y>=h) {y=4>>lpass;yinc=y*2;lpass++;}}
		}
		else
		{
			code=c;
			if (code>=slot) {code=oc;stack[sp++]=(short)fc;}		//simon was here
			while (code>=newcodes) {stack[sp++]=suffix[code];code=prefix[code];}
			stack[sp++]=(short)code;	//simon was here
			if (slot<topslot) {fc=code;suffix[slot]=(short)fc;prefix[slot++]=(short)oc;oc=c;}			
			if (slot>=topslot && csize<12) {topslot<<=1;++csize;}

			while (sp>0) 
			{
				c=stack[--sp];
				if (squash)
				{
					if ( (y==h-1) || ((x&1)==(y&1)) ) can->writepixel(x,y>>1,pal[c]);
				}
				else
				{
					can->writepixel(x,y,pal[c]);
				}
				x++;if (x==w) {x=0;y+=yinc;if (y>=h) {y=4>>lpass;yinc=y*2;lpass++;}}
			}
		}
	}
	nitro->release();
}

//	texture		*p;
//	p=new texture();p.init(pal);can.setclut(p.tx,p.ty);

/*	
	if (squash)
		can=(texture)axis.system.localhost.alloctexture(w,(h+1)>>1,1);
	else
		can=(texture)axis.system.localhost.alloctexture(w,h,1);
*/
