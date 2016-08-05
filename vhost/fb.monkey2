namespace fb

#import "<linux/fb.h>"
#import "<libc>"
#import "posix.monkey2"

Using libc
Using posix

extern 

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

public

function queryFramebuffer:int(fd:int,width:int ptr,height:int ptr,depth:int ptr,len:int ptr)

	Local fixed:fb_fix_screeninfo
	if ioctl(fd,FBIOGET_FSCREENINFO,Varptr fixed)=-1
		Print "Error reading fixed information"
		return -1
	endif

	Local variable:fb_var_screeninfo
	if ioctl(fd,FBIOGET_VSCREENINFO,Varptr variable)=-1
		Print "Error reading fixed information"
		return -2
	endif

	width[0]=variable.xres
	height[0]=variable.yres
	depth[0]=variable.bits_per_pixel

	len[0]=width[0]*height[0]*depth[0]/8

	return 0
end

function mapFramebuffer:void ptr(fd:int,sizeBytes:int)

	Local memory:=mmap(Void Ptr(0),sizeBytes,PROT_WRITE,MAP_SHARED,fd,0)
	
	Local badPointer:=Void Ptr(-1)

'	if memory-badPointer=0
'		print "mmap failure on fd"
'		return null
'	endif

	print "Framebuffer mapped to memory"
	return memory
end

function unmapFrameBuffer(memory:void ptr,len:int)
	munmap(memory,len)
end
