namespace i2c

#import "<linux/i2c-dev.h>"

extern

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

Const ACT_THS:=Bin("0000100")
Const ACT_DUR:=Bin("0000101")
Const INT_GEN_CFG_XL:=Bin("0000110")
Const INT_GEN_THS_X_XL:=Bin("0000111")
Const INT_GEN_THS_Y_XL:=Bin("0001000")
Const INT_GEN_THS_Z_XL:=Bin("0001001")
Const INT_GEN_DUR_XL:=Bin("0001010")
Const REFERENCE_G:=Bin("0001011")
Const INT1_CTRL:=Bin("0001100")
Const INT2_CTRL:=Bin("0001101")

Const WHO_AM_I:=Bin("0001111")
Const CTRL_REG1_G:=Bin("0010000")
Const CTRL_REG2_G:=Bin("0010001")
Const CTRL_REG3_G:=Bin("0010010")
Const ORIENT_CFG_G:=Bin("0010011")
Const INT_GEN_SRC_G:=Bin("0010100")
Const OUT_TEMP_L:=Bin("0010101")
Const OUT_TEMP_H:=Bin("0010110")
Const STATUS_REG0:=Bin("0010111")
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

