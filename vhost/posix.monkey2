namespace posix

#import "<stdio.h>"
#import "<fcntl.h>"
#import "<unistd.h>"
#import "<sys/ioctl.h>"
#import "<sys/types.h>"
#import "<sys/socket.h>"
#import "<sys/mman.h>"
#import "<netdb.h>"
#import "<errno.h>"
#import "<arpa/inet.h>"
#import "<linux/fb.h>"

#import "<libc>"

Using libc

extern 

Global errno:Int

Global AF_UNSPEC:Int
Global AF_INET:Int
Global AF_INET6:int
Global PF_INET6:int
Global SOCK_STREAM:int
Global SOCK_DGRAM:int
global INADDR_ANY:Int

Global FIONBIO:Int	'=126
Global MSG_DONTWAIT:Int	'=$40
global SOL_SOCKET:Int	':=$ffff
global SO_REUSEADDR:Int	':=$4

Global AI_PASSIVE:Int
Global AI_ADDRCONFIG:Int

Global PROT_WRITE:int
Global MAP_SHARED:Int

Global FBIOGET_FSCREENINFO:Int
Global FBIOGET_VSCREENINFO:Int

Class sockaddr Extends Void
	Field sin_family:Short
	Field sin_port:UShort
	Field sin_addr:ULong
	Field pad0:Int
	Field pad1:Int
End

Class sockaddr_in Extends sockaddr
End

Class sockaddr_in6 Extends sockaddr
	Field sin6_family:Ushort
	Field sin6_port:UShort
	Field sin6_flowinfo:UInt
	Field sin6_addr:int
	Field sin6_addr1:Int
	Field sin6_addr2:Int
	Field sin6_addr3:Int
	Field sin6_scopeid:Int
End

Class addrinfo Extends Void
	Field ai_flags:Int ' input flags
	Field ai_family:Int ' protocol family for socket
	Field ai_socktype:Int	' socket type
	Field ai_protocol:Int ' protocol for socket
	Field ai_addrlen:Int	' length of socket-address
	Field ai_addr:sockaddr ' socket-address for socket
	Field ai_canonname:char_t ptr ' canonical name for service location
	Field ai_next:addrinfo ' pointer to next in list
end

struct fb_fix_screeninfo	' Extends Void
	field id0:char_t			' identification string eg "TT Builtin" 
	field id1:char_t
	field id2:char_t
	field id3:char_t
	field id4:char_t
	field id5:char_t
	field id6:char_t
	field id7:char_t
	field id8:char_t
	field id9:char_t
	field ida:char_t
	field idb:char_t
	field idc:char_t
	field idd:char_t
	field ide:char_t
	field idf:char_t
	field smem_start:ULong		' Start of frame buffer mem (physical address) 
	field smem_len:int			' Length of frame buffer mem 
	field type:int				' see FB_TYPE_*		
	field type_aux:int			' Interleave for interleaved Planes 
	field visual:int			' see FB_VISUAL_*		
	field xpanstep:short		' zero if no hardware panning  
	field ypanstep:short		' zero if no hardware panning  
	field ywrapstep:short		' zero if no hardware ywrap    
	field line_length:int		' length of a line in bytes    
	field mmio_start:ulong		' Start of Memory Mapped I/O (physical address) 
	field mmio_len:int			' Length of Memory Mapped I/O  
	field accel:int				' Indicate to driver which specific chip/card we have	
	field capabilities:short	' see FB_CAP_*			
	field reserved0:short		' Reserved for future compatibility 
	field reserved1:short		' Reserved for future compatibility 
End

struct fb_bitfield' Extends void
	Field offset:Int			' beginning of bitfield
	Field length:Int			' length of bitfield	
	field msb_right:Int			' != 0 : Most significant bit is right
End

Struct fb_var_screeninfo	' Extends void
	field xres:int				' visible resolution		
	field yres:Int
	field xres_virtual:int		' virtual resolution		
	field yres_virtual:Int
	field xoffset:int			' offset from virtual to visible 
	field yoffset:int			' resolution			
	field bits_per_pixel:int	' guess what			
	field grayscale:int			' 0 = color, 1 = grayscale, >1 = FOURCC			

	Field red:fb_bitfield		' bitfield in fb mem if true color, 
	Field green:fb_bitfield		' else only length is significant 
	Field blue:fb_bitfield
	Field transparent:fb_bitfield	' transparency			

	field nonstd:int			' != 0 Non standard pixel format 
	field activate:int			' see FB_ACTIVATE_*		
	field height:int			' height of picture in mm    
	field width:int				' width of picture in mm     
	field accel_flags:int		' (OBSOLETE) see fb_info.flags 

' Timing: All values in pixclocks, except pixclock (of course) 

	field pixclock:int			' pixel clock in ps (pico seconds) 
	field left_margin:int		' time from sync to picture	
	field right_margin:int		' time from picture to sync	
	field upper_margin:int		' time from sync to picture	
	field lower_margin:int
	field hsync_len:int			' length of horizontal sync	
	field vsync_len:int			' length of vertical sync	
	field sync:int				' see FB_SYNC_*		
	field vmode:int				' see FB_VMODE_*		
	field rotate:int			' angle we rotate counter clockwise 
	field colorspace:int		' colorspace for FOURCC-based modes 
	field reserved0:int			' Reserved for future compatibility 
	field reserved1:Int
	field reserved2:Int
	field reserved3:int
end

Function open:Int( path:CString,mode:Int )

function ioctl:int( fd:int,request:uint,memory:void ptr)
function ioctl:int( fd:int,request:uint,value:int)

function read:int( fd:int,buffer:void ptr,count:uint)
function write:int( fd:int,buffer:void ptr,count:uint)

Function close:Int( fd:int)

Function connect:int(sock:Int,addr:sockaddr,addrlen:Int)

Function listen:int(fd:Int,backlog:Int)
Function bind:Int(fd:Int,addr:sockaddr,addrlen:Int)
Function setsockopt:Int(fd:Int,level:Int,name:Int,val:Void Ptr,size:Int)
Function accept:Int(fd:Int,addr:sockaddr,addrlen:uInt Ptr)
Function recv:Int(fd:int,buffer:Void ptr,BufferSize:int,flags:Int)
Function send:Int(fd:int,buffer:Void ptr,BufferSize:int,flags:Int)
Function recvfrom:Int(fd:Int,buffer:Void ptr,BufferSize:int,flags:Int,addr:sockaddr,addrlen:UInt Ptr)
Function getaddrinfo:Int(hostname:CString, servername:CString, hints:addrinfo, res:addrinfo ptr)
Function freeaddrinfo(ai:addrinfo)

Function socket:Int(domain:Int,socketType:Int,socketProtocol:Int)

function htons:ushort(hostshort:UShort)
function htonl:uint(hostlong:UInt)

function mmap:void ptr(address:void ptr,len:int,prot:Int,flags:int,fd:int,offset:int)
function munmap(memory:void ptr,len:int)

Function strerror:char_t Ptr(error:Int)

Public

Function ErrorString:String()
	Local result:=errno
	Local s:=strerror(errno)
	Return String.FromCString(s)
end
