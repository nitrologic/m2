#import "posix.monkey2"

' #import "<linux/i2c-dev.h>"

namespace i2c

extern 

' note: not currently used

function i2c_smbus_read_word_data:int(file:int, reg:int)
function i2c_smbus_write_word_data(file:int, reg:int, value:int)

public

Function Bin:Int(s:string)
	Local b:=0
	For Local i:=0 Until 7
		If s[i]=49 b+=1 Shl (7-i)
	Next
	Return b
End

const I2C_SLAVE:=$703

Const ACT_THS:=$04		
Const ACT_DUR:=$05		
Const INT_GEN_CFG_XL:=$06	
Const INT_GEN_THS_X_XL:=$07	
Const INT_GEN_THS_Y_XL:=$08	
Const INT_GEN_THS_Z_XL:=$09	
Const INT_GEN_DUR_XL:=$0a	
Const REFERENCE_G:=$0b		
Const INT1_CTRL:=$0c		
Const INT2_CTRL:=$0d		
Const WHO_AM_I:=$0f		

Const CTRL_REG1_G:=$10		
Const CTRL_REG2_G:=$11	
Const CTRL_REG3_G:=$12	
Const CTRL_REG4_G:=$13	
Const ORIENT_CFG_G:=$13	

Const INT_GEN_SRC_G:=$24
Const OUT_TEMP_L:=$25		
Const OUT_TEMP_H:=$26		
Const STATUS_REG0:=$27

const OUT_X_L_A:=$28
const OUT_X_H_A:=$29
const OUT_Y_L_A:=$2a
const OUT_Y_H_A:=$2b

Const OUT_X_L_G:=Bin("0011000")
Const OUT_X_H_G:=Bin("0011001")
Const OUT_Y_L_G:=Bin("0011010")
Const OUT_Y_H_G:=Bin("0011011")
Const OUT_Z_L_G:=Bin("0011100")
Const OUT_Z_H_G:=Bin("0011101")
Const CTRL_REG4:=Bin("0011110")
Const CTRL_REG5_XL:=Bin("0011111")

Const CTRL_REG6_XL:=Bin("0100000")
Const CTRL_REG7_XL:=Bin("0100001")
Const CTRL_REG8:=Bin("0100010")
Const CTRL_REG9:=Bin("0100011")
Const CTRL_REG10:=Bin("0100100")

Const INT_GEN_SRC_XL:=Bin("0100110")
Const STATUS_REG:=Bin("0100111")
Const OUT_X_L_XL:=Bin("0101000")
Const OUT_X_H_XL:=Bin("0101001")
Const OUT_Y_L_XL:=Bin("0101010")
Const OUT_Y_H_XL:=Bin("0101011")
Const OUT_Z_L_XL:=Bin("0101100")
Const OUT_Z_H_XL:=Bin("0101101")
Const FIFO_CTRL:=Bin("0101110")
Const FIFO_SRC:=Bin("0101111")
Const INT_GEN_CFG_G:=Bin("0110000")
Const INT_GEN_THS_XH_G:=Bin("0110001")
Const INT_GEN_THS_XL_G:=Bin("0110010")
Const INT_GEN_THS_YH_G:=Bin("0110011")
Const INT_GEN_THS_YL_G:=Bin("0110100")
Const INT_GEN_THS_ZH_G:=Bin("0110101")
Const INT_GEN_THS_ZL_G:=Bin("0110110")
Const INT_GEN_DUR_G:=Bin("0110111")


Const OFFSET_X_REG_L_M:=Bin("0000101")
Const OFFSET_X_REG_H_M:=Bin("0000110")
Const OFFSET_Y_REG_L_M:=Bin("0000111")
Const OFFSET_Y_REG_H_M:=Bin("0001000")
Const OFFSET_Z_REG_L_M:=Bin("0001001")
Const OFFSET_Z_REG_H_M:=Bin("0001010")

Const WHO_AM_I_M:=Bin("0001111")

Const CTRL_REG1_M:=Bin("0100000")
Const CTRL_REG2_M:=Bin("0100001")
Const CTRL_REG3_M:=Bin("0100010")
Const CTRL_REG4_M:=Bin("0100011")
Const CTRL_REG5_M:=Bin("0100100")

Const STATUS_REG_M:=Bin("0100111")

Const OUT_X_L_M:=Bin("0101000")
Const OUT_X_H_M:=Bin("0101001")
Const OUT_Y_L_M:=Bin("0101010")
Const OUT_Y_H_M:=Bin("0101011")
Const OUT_Z_L_M:=Bin("0101100")
Const OUT_Z_H_M:=Bin("0101101")

Const INT_CFG_M:=Bin("0110000")
Const INT_SRC_M:=Bin("0110001")
Const INT_THS_L_M:=Bin("0110010")
Const INT_THS_H_M:=Bin("0110011")


Class I2C
	Field file:int
	field buf:=new ubyte[4]
	
	Method New(fd:Int)
		file=fd
		TestGyro()
	End

	method Close()
		posix.close(file)
		file=0
	end
	
	method Write(reg:int,value:int)
		buf[0]=ubyte(reg)
		buf[1]=ubyte(value)
		buf[2]=ubyte(value shr 8)
		write(file,buf.Data,3)
'		i2c_smbus_write_word_data(file,reg,value)
	end
	
	method Read:int(reg:int,buffer:ubyte ptr,count:int)
		return read(file,buffer,count)
'		return is2_smbus_read_word_data(file,reg)
	end
	
	Method TestGyro()
		if posix.ioctl(file, i2c.I2C_SLAVE, $6a) < 0
			Print "Could not select gyro"
			Return
		endif

		Write(CTRL_REG1_G,$0f)	'power onm axes enables
		Write(CTRL_REG4_G,$30)	'continuous
		
		local gyroData:=new ubyte[6]

		for local i:=0 until 50
			local n:=Read($80|OUT_X_L_A,gyroData.Data,8)
			if n<>8 exit	
			print gyroData[0]
		next
		print "gyro test complete"

#rem
	writeGyrReg(CTRL_REG1_G, 0b00001111)") // Normal power mode, all axes enabled
	writeGyrReg(CTRL_REG4_G, 0b00110000)") // Continuos update, 2000 dps full scale

	while(true){
	 uint8_t b[6]")
 	readBlock(0x80 | OUT_X_L_A, sizeof(b), b)")
		printf("packet $d $d $d $d $d $d\n",b[0],b[1],b[2],b[3],b[4],b[5])")
	}

#end

	End
End


#rem

int main(){
	char filename[128]")

	sprintf(filename, "/dev/i2c-%d", 1)")

	int file= open(filename, O_RDWR)")
	if (file<0) {
		printf("Unable to open I2C bus!")")
		return 1")
	}

	if (ioctl(file, I2C_SLAVE, 0x6a) < 0) {
		printf("Error: Could not select gyro\n")")
	}

	writeGyrReg(CTRL_REG1_G, 0b00001111)") // Normal power mode, all axes enabled
	writeGyrReg(CTRL_REG4_G, 0b00110000)") // Continuos update, 2000 dps full scale

	while(true){
	 uint8_t b[6]")
 	readBlock(0x80 | OUT_X_L_A, sizeof(b), b)")
		printf("packet $d $d $d $d $d $d\n",b[0],b[1],b[2],b[3],b[4],b[5])")
	}

// Enable accelerometer.
//	writeAccReg(CTRL_REG1_XM, 0b01100111)") // z,y,x axis enabled, continuos update, 100Hz data rate
//	writeAccReg(CTRL_REG2_XM, 0b00100000)") // +/- 16G full scale

	printf("i2C 1 is A ok\n")")

	close(file)")

	return 0")
}

#end


struct fb_fix_screeninfo
	field id0:t_char			' identification string eg "TT Builtin" 
	field id1:t_char
	field id2:t_char
	field id3:t_char
	field id4:t_char
	field id5:t_char
	field id6:t_char
	field id7:t_char
	field id8:t_char
	field id9:t_char
	field ida:t_char
	field idb:t_char
	field idc:t_char
	field idd:t_char
	field ide:t_char
	field idf:t_char
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

struct fb_bitfield
	Field offset:Int			' beginning of bitfield
	Field length:Int			' length of bitfield	
	field msb_right:Int			' != 0 : Most significant bit is right
end

struct fb_var_screeninfo
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
	field width:int			' width of picture in mm     
	field accel_flags:int		' (OBSOLETE) see fb_info.flags 

' Timing: All values in pixclocks, except pixclock (of course) 

	field pixclock:int			' pixel clock in ps (pico seconds) 
	field left_margin:int		' time from sync to picture	
	field right_margin:int		' time from picture to sync	
	field upper_margin:int		' time from sync to picture	
	field lower_margin:int
	field hsync_len:int		' length of horizontal sync	
	field vsync_len:int		' length of vertical sync	
	field sync:int			' see FB_SYNC_*		
	field vmode:int			' see FB_VMODE_*		
	field rotate:int			' angle we rotate counter clockwise 
	field colorspace:int		' colorspace for FOURCC-based modes 
	field reserved0:int		' Reserved for future compatibility 
	field reserved1:Int
	field reserved2:Int
	field reserved3:int
end

