' work in progress conversion of a monkey1 project

' arm-t little endian machine emulation
' thanks to Martin Korth for definitive gbatek.txt
' r[15]=PC
' MOV R11,R11 = .break

Class CPU
	Field _id:int

	'16 general purpose regs + special temp register
	Field _r:Int[] 

	'128K byte 32 bit mini machine
	Field _ram:Int[]

	'address mask	
	Field _mask:Int

	Method Run(cycles:int)
	End
	
	method Dissassemble:string(address:int,lines:int)
		Return ""
	End
	
	method Status:string()
		Return ""
	end

'	Global digits:=New Byte[]('0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F')

	function hex16:string(op:int)
		return ""+digits[(op shr 12)&15]+digits[(op shr 8)&15]+digits[(op shr 4)&15]+digits[op&15]
	End
	
	Function hex32:string(op:int)
		return hex16((ushort)(op shr 16))+hex16((ushort)(op&$ffff))
	End

End

Class ThumbCPU Extends CPU

' local state 

		field _cpsr:Int 'NZCV synchronized from below on demand
		field _nzr:Int 'register value last generating NZ operation for on demand testing
		field _c:Int '0 1 for fast carry / borrow actions
		field _v:Bool 'true false for detecting signed overflow
		field _t:Bool 'thumb mode

		Method New(cpuid:int)
			Super(cpuid) 
			_id=cpuid
			_r=new int[17]
			_ram=new int[65536]
			_mask=65535
			setup()
			test()
		End
		
		Function Binary:String(b:Bool)
			If b Return "1"
			Return "0"
		End
		
		function Mask:Int(b:Bool)
			If b Return -1
			Return 0
		end

		Method Status:string() override
			local s:=""		
			s+="C="+_c+"~n"
			s+="N="+Binary(_r[_nzr]<0)+"~n"
			s+="Z="+Binary(_r[_nzr]=0)+"~n"
			s+="V="+_v+"~n"
			return s			
		End

		Method _cmp:void(a:int,b:int)	'a-b
			_r[16]=a-b
			_nzr=16
			_v=UInt(b)>uint(a)
			_c=((a-b) shr 31)&1
		End

		Method _ror:int(r32:int,op:int)
			Local r:=(UInt(r32) Shr op)
			Local l:=(r shl (31-op))
			return int(r|l)
		End

		Method _stb:void(addr:int, b:int)
			local q8:int=(b&3)*8
			addr=addr Shr 2
			addr&=_mask
			_ram[addr]= _ram[addr] & (-1 - ($ff shl q8) ) | ( (b&255)  shl  q8 )
		End

		Method _strh:void(addr:int, b:int)
			local q8:int=(b&2)*8
			addr=addr shr 2
			addr&=_mask
			_ram[addr]= _ram[addr] & (-1 - ($ffff shl q8) ) | ( (b&$ffff)  shl  q8 )
		End
	
		Method _ldb:int(addr:int)
			local q8:int=(addr&3)*8
			addr=addr shr 2
			addr&=_mask
			return (_ram[addr] shr q8)&255
		End
		Method _ldsb:int(addr:int)
			local q8:int=(addr&3)*8
			addr=addr shr 2
			addr&=_mask
			return ((_ram[addr] shr q8) shl 24) shr 24
		End
		Method _ldrh:int(addr:int)
			local q8:int=(addr&2)*8
			addr=addr shr 2
			addr&=_mask
			Return (_ram[addr] shr q8) & $ffff
		End
		Method _ldsh:int(addr:int)
			local q8:int=(addr&3)*8
			addr=addr shr 2
			addr&=_mask
			return ((_ram[addr] shr q8) shl 16) shr 16
		End

		Method _ldmia:void(b:int)
			local r:int
			local a:Int
			r=(b shr 8)&7
			a=_r[r] Shr 2
			a&=_mask
			if((b&$01)<>0) _r[0]=_ram[a];a+=1
			if((b&$02)<>0) _r[1]=_ram[a];a+=1
			if((b&$04)<>0) _r[2]=_ram[a];a+=1
			if((b&$08)<>0) _r[3]=_ram[a];a+=1
			if((b&$10)<>0) _r[4]=_ram[a];a+=1
			if((b&$20)<>0) _r[5]=_ram[a];a+=1
			if((b&$40)<>0) _r[6]=_ram[a];a+=1
			if((b&$80)<>0) _r[7]=_ram[a];a+=1
			_r[r]=a shl 2
		End

		Method _stmia:void(b:int)
			local r:=(b shr 8)&7
			local a:=_r[r] shr 2
			a&=_mask
			if((b&$01)<>0) _ram[a]=_r[0];a+=1
			if((b&$02)<>0) _ram[a]=_r[1];a+=1
			if((b&$04)<>0) _ram[a]=_r[2];a+=1
			if((b&$08)<>0) _ram[a]=_r[3];a+=1
			if((b&$10)<>0) _ram[a]=_r[4];a+=1
			if((b&$20)<>0) _ram[a]=_r[5];a+=1
			if((b&$40)<>0) _ram[a]=_r[6];a+=1
			if((b&$80)<>0) _ram[a]=_r[7];a+=1
			_r[r]=a shl 2
		End
	
		Method _push:void(b:int)
			local sp:=_r[13] shr 2
			sp&=_mask
			if ((b&$100)<>0) _ram[--sp]=_r[14]
			if ((b&$80)<>0) _ram[--sp]=_r[7]
			if ((b&$40)<>0) _ram[--sp]=_r[6]
			if ((b&$20)<>0) _ram[--sp]=_r[5]
			if ((b&$10)<>0) _ram[--sp]=_r[4]
			if ((b&$08)<>0) _ram[--sp]=_r[3]
			if ((b&$04)<>0) _ram[--sp]=_r[2]
			if ((b&$02)<>0) _ram[--sp]=_r[1]
			if ((b&$01)<>0) _ram[--sp]=_r[0]
			_r[13]=sp shl 2
		End

		Method _pop:void(b:int)
			local sp:=_r[13] shr 2
			sp&=_mask
			if ((b&$01)<>0) _r[0]=_ram[sp];sp+=1
			if ((b&$02)<>0) _r[1]=_ram[sp];sp+=1
			if ((b&$04)<>0) _r[2]=_ram[sp];sp+=1
			if ((b&$08)<>0) _r[3]=_ram[sp];sp+=1
			if ((b&$10)<>0) _r[4]=_ram[sp];sp+=1
			if ((b&$20)<>0) _r[5]=_ram[sp];sp+=1
			if ((b&$40)<>0) _r[6]=_ram[sp];sp+=1
			if ((b&$80)<>0) _r[7]=_ram[sp];sp+=1
			if ((b&$100)<>0) _r[15]=_ram[sp];sp+=1
			_r[13]=sp shl 2
		End

		Method _branch:void(op:ushort)
			local t:=false
			local n:=(_r[_nzr]<0)
			local z:=(_r[_nzr]=0)
			local o:Int

			Select((op shr 8)&15)
				case 0:t=z=true
				case 1:t=z=false
				case 2:t=_c=1
				case 3:t=_c=0
				case 4:t=n=true
				case 5:t=n=False
				case 6:t=_v=True
				case 7:t=_v=False
				case 8:t=(_c=1) & Mask(z=false)
				case 9:t=(_c=0) | Mask(z=true)
				case 10:t=(n=_v)
				case 11:t=(n<>_v)
				case 12:t=(z=false) & Mask(n=_v)
				case 13:t=(z=true) & Mask(n<>_v)
			End
			if (t)
				if((op&128)<>0)
					o=(2+((-128|(op&127))*2))
				else
					o=(2+(op&127)*2)
				endif
				_r[15]+=o' 2-256+(op&255)*2
			End
		End
	
		Method _swi:void(b:int)
		End

		field _longbranch:int

		Method _bl:void(b:int)
			_longbranch=_r[15] + 2 + ((b shl 21) shr 9)		' & $7ff) shl 12)	'upper 11 bits
		End

		Method _bh:void(b:int)
			_r[14]=_r[15]-1	'pc is prfetched ahead so -2, thumb is odd so +1
			_longbranch+=((b&$7ff) shl 1)
			_r[15]=_longbranch
		End
		
		Global thumb19:=new ushort[](
			$e000,$0000,'0
			$f800,$1800,'1
			$e000,$2000,'2
			$fc00,$4000,'3
			$fc00,$4400,'4
			$f800,$4800,'5
			$f200,$5000,'6
			$f200,$5200,'7
			$e000,$6000,'8
			$f000,$8000,'9
			$f000,$9000,'10
			$f000,$a000,'11
			$ff00,$b000,'12
			$f600,$b400,'13
			$f000,$c000,'14
			$f000,$d000,'15
			$ff00,$df00,'16
			$f800,$e000,'17
			$f000,$f000)'18
#Rem
		Method delegate OpHandler:void<ThumbCPU>(op:ushort)
		OpHandler<ThumbCPU> [] _ophandlers

		cpu_op1:void(op:ushort)
		End

		setup:void()
			_ophandlers=new []
				new OpHandler<ThumbCPU>(cpu_op1)
			End
		End
#end
		Method Run(cycles:int) override
			local pc:int
			local op:ushort
			local op32:int

			if(_t)
				_r[15]+=2
			Else
				_r[15]+=4
			End

			while (cycles>0)
				cycles-=1
				if(_t)
' thumb mode rocks!
					pc=_r[15]-2
					_r[15]+=2					
					op=(ushort)(_ram[_mask&(pc shr 2)] shr ((pc&2)*8))
					thumbex(op)
				Else
' arm mode coming soon!
					pc=_r[15]-4
					_r[15]+=4					
					op32=_ram[_mask&(pc shr 2)]
					armex(op32)
				End
				_t=((_r[15]&1)=1)
			End

			if(_t)
				_r[15]-=2
			Else
				_r[15]-=4
			End
		End

		Global g1:=new String[]("LSL","LSR","ASR")
		Global g2:=new string[]("ADD","SUB")
		Global g3:=new string[]("MOV","CMP","ADD","SUB")
		Global g4:=new string[]("AND","EOR","LSL","LSR","ASR","ADC","SBC","ROR","TST","NEG","CMP","CMN","ORR","MUL","BIC","MVN")
		Global g5:=new string[]("ADD","CMP","MOV","BX")
		Global g6:=new string[]("LDR")
		Global g7:=new string[]("STR","STRB","LDR","LDRB")
		Global g8:=new string[]("STRH","LDSB","LDRH","LDSH")
		Global g9:=new string[]("STR","LDR","STRB","LDRB")
		Global g10:=new string[]("STRH","LDRH")
		Global g11:=new string[]("STR","LDR")
		Global g12:=new string[]("ADD")
		Global g13:=new string[]("ADD")
		Global g14:=new string[]("PUSH","POP")
		Global g15:=new string[]("STMIA","LDMIA")
		Global g16:=new string[]("BEQ","BNE","BCS","BCC","BMI","BPL","BVS","BVC","BHI","BLS","BGE","BLT","BGT","BLE","B","BNV")
		Global g17:=new string[]("SWI")
		Global g18:=new string[]("B")
		Global g19:=new string[]("BL","BLH")

		Global regs:=new string[]("R0","R1","R2","R3","R4","R5","R6","R7","R8","R9","R10","R11","R12","SP","LR","PC")

		Global cclist:=new string[]("eq","ne","cs","cc","mi","pl","vs","vc","hi","ls","ge","lt","gt","le","","???")
        Global opname:=new string[]("and","eor","sub","rsb","add","adc","sbc","rsc","tst","teq","cmp","cmn","orr","mov","bic","mvn")
		Global shifts:=new string[]("lsl","lsr","asr","ror")
		Global muls:=new string[]("umull","umlal","smull","smlal")
		Global strldr:=new string[]("str","ldr","strt","ldrt")
		Global bhsbsh:=new string[]("b","h","sb","sh")
		Global stmldm:=new string[]("stm","ldm")
		Global stcldc:=new string[]("stc","ldc")
		Global mcrmrc:=new string[]("mcr","mrc")


		Function  stop:void()
		End

		Function  test:void()
			local grp:int
			local op:ushort

			for op=0 to $ffff		

				for grp=18 to 0 step -1 
					if ((op&thumb19[grp*2])=thumb19[grp*2+1]) break
				Next

				if ((op&$f800)=$1800)'case 1:'add,sub
					if (grp<>1) stop()
				Elseif ((op&$e000)=0)  'case 0:lsl,lsr,asr,nop					
					if (grp<>0) stop()
				End
				
				if ((op&$e000)=$2000)'case 2:	'"MOV","CMP","ADD","SUB"
					if (grp<>2) stop()
				End

				if ((op&$fc00)=$4000)'case 3: '"AND","EOR","LSL","LSR","ASR","ADC","SBC","ROR","TST","NEG","CMP","CMN","ORR","MUL","BIC","MVN"
					if (grp<>3) stop()
				End

				if ((op&$fc00)=$4400)'case 4: '"ADD","CMP","MOV","BX"
					if (grp<>4) stop()
				End

				if ((op&$f800)=$4800)'case 5: '"LDR"
					if (grp<>5) stop()
				End
					
				if ((op&$f200)=$5000)'case 6: '"STR","STRB","LDR","LDRB"
					if (grp<>6) stop()
				End

				if ((op&$f200)=$5200) ' case 7: '"STRH","LDSB","LDRH","LDSH"
					if (grp<>7) stop()
				End

				if ((op&$e000)=$6000) 'case 8: '"STR","LDR","STRB","LDRB"
					if (grp<>8) stop()
				End

				if ((op&$f000)=$8000) 'case 9: '"STRH","LDRH"
					if (grp<>9) stop()
				End

				if ((op&$f000)=$9000) 'case 10: '"STR","LDR"
					if (grp<>10) stop()
				End

				if ((op&$f000)=$a000) 'case 11: '"ADD"
					if (grp<>11) stop()
				End

				if ((op&$ff00)=$b000) 'case 12: '"ADD SP,"
					if (grp<>12) stop()
				End

				if ((op&$f600)=$b400) 'case 13: '"PUSH","POP"
					if (grp<>13) stop()
				End

				if ((op&$f000)=$c000) 'case 14: '"STMIA","LDMIA"
					if (grp<>14) stop()
				End

				if ((op&$ff00)=$df00) 'case 16: '"SWI"
					if (grp<>16) stop()
				Elseif ((op&$f000)=$d000) 'case 15: '"BEQ","BNE","BCS","BCC","BMI","BPL","BVS","BVC","BHI","BLS","BGE","BLT","BGT","BLE","???","***"
					If (grp<>15) stop()
				End
				
				if ((op&$f800)=$e000) 'case 17: '"B"
					if (grp<>17) stop()
				End

				if ((op&$f000)=$f000) 'case 18: '"BL","BH"
					if (grp<>18) stop()
				End
			End
		End

		Method Dissassemble:string(address:int,lines:int) Override
			local addr:int
			local op:ushort
			local op32:int
			local asm:string

			if(_t)
				for local i:int=0 until lines
					op=(ushort)(_ram[_mask&(address shr 2)] shr ((address&2)*8))
					asm+="$"+CPU.hex32(address)+":"+CPU.hex16(op)		
					if ( (_mask&address) = (_mask&_r[15]))
						asm+=" > "
					Else
						asm+="   "
					End
					asm+=thumbop(op)+"~n"
					address+=2
				next
			Else
				for Local i:int=0 until lines
					op32=_ram[_mask&(address shr 2)]
					asm+="$"+CPU.hex32(address)+":"+CPU.hex32(op32)		
					if ( (_mask&address) = (_mask&_r[15]))
						asm+=" > "
					Else
						asm+="   "
					End
					asm+=armop(op32)+"~n"
					address+=4
				next
			End
			return asm
		End

		function reglist:string(m:int)
			local r:=1
			local t:=1
			local n:=0
			local s:=""
			while (t<>$10000)
				if ((m&t)=t)
					if (n<>0)
						s+=","
					End
					s+="r"
					s+=r
					n+=1
				End
				r+=1
				t=t shl 1
			End
			return s
		End


		Method armex:void(op:int)
			s:string
			grp:int,i,j,o,rd,rn,rm,rs
			cc:int
			
			bool n=(_r[_nzr]<0)?true:false
			bool z=(_r[_nzr]=0)?true:false

			bool t=true

			cc=(op shr 28)&15
			select(cc)
				case 0:t=z=true
				case 1:t=z=false
				case 2:t=_c=1
				case 3:t=_c=0
				case 4:t=n=true
				case 5:t=n=false
				case 6:t=_v=true
				case 7:t=_v=false
				case 8:t=(_c=1) && (z=false)
				case 9:t=(_c=0) || (z=true)
				case 10:t=(n=_v)
				case 11:t=(n<>_v)
				case 12:t=(z=false) && (n=_v)
				case 13:t=(z=true) && (n<>_v)
			End
			if(!t)
				return
			End
	
			grp=0
			s=""

			select ((op shr 25)&7)
				case 0:
					if ((op&$10)=0) if ((op&$01b00000)=$01200000) grp=7else grp=1End
					if ((op&$01b00000)=$01000000) grp=5End
					if ((op&$80)=0) if ((op&$01f000f0)=$01200010) grp=8else grp=2End
					if ((op&$01b000f0)=$01000090) grp=13End
					if ((op&$010000f0)=$00000090) if ((op&$00800000)<>0) grp=4else grp=3End
					if ((op&$00200000)<>0) grp=11else grp=12
				case 1:if ((op&$01b00000)=$01200000) grp=6else grp=0
				case 2:grp=9
				case 3:if ((op&$10)<>0) grp=20else grp=10
				case 4:grp=14
				case 5:grp=18
				case 6:grp=17
				case 7:if ((op&$01000000)<>0) grp=19Endif ((op&$10)<>0) grp=16else grp=15
			End

			rn=(op shr 16)&15
			rd=(op shr 12)&15
			rs=(op shr 8)&15
			rm=op&15

			select (grp)
			case 0:
				o=(op shr 21)&15
				s+=opname[o]
				s+=cc
				if ((op&$00100000)<>0)
					s+='s'
				End
	'			j=(op&255) shl ((op shr 7)&30)
				i=op&255
				j=(op shr 7)&30
				i=(i shr j)|(i shl (32-j))
' "and","eor","sub","rsb","add","adc","sbc","rsc","tst","teq","cmp","cmn","orr","mov","bic","mvn"	
				select (o)
					case 0:_r[rd]&=i 'and
					case 1:_r[rd]^=i 'eor
					case 2:_r[rd]=_r[rd]-i 'sub
					case 3:_r[rd]=i-_r[rd] 'rsb
					case 4:_r[rd]+=i 'add
					case 5:_r[rd]+=i+_c 'adc
					case 6:_r[rd]=_r[rd]-i-_c 'sbc
					case 7:_r[rd]=i-_r[rd]-_c 'rsc
					case 8:rd=rn'tst
					case 9:rd=16_r[16]=_r[rn]^i'teq
					case 10:_cmp(_r[rn],i) 'cmp
					case 11:_cmp(_r[rd],_r[rs])'cmn
					case 12:_r[rd]|=_r[rs]'orr
					case 13:_r[rd]=i'mov
					case 14:_r[rd]=_r[rn]&~(i)'bic
					case 15:_r[rd]=~i'mvn
				End
				_nzr=rd
				return
			case 1:
				o=(op shr 21)&15
				s+=opname[o]
				s+=cc
				if ((op&$00100000)<>0)
					s+='s'
				End
				i=(op shr 5)&3j=(op shr 7)&31
				select (o)
					case 13:
					case 15:
						s+="\tr"+rd+",r"+rm
						break 'mov mvn
					case 8:
					case 9:
					case 10:
					case 11:
						s+="\tr"+rn+",r"+rm
						break	'tst teq cmp cmn
					default:
						s+="\tr"+rd+",r"+rn+",r"+rm
						break
				End
				if ((i=3)&&(j=0)) s+=",rrx"else s+=","+shifts[i]+" #"+j
				break
			case 2:
				s+=opname[(op shr 21)&15]
				s+=cc
				if ((op&$00100000)<>0) s+='s'
				i=(op shr 5)&3j=(op shr 7)&31
				s+="\tr"+rd+",r"+rn+",r"+rm+" "+shifts[i]+" r"+rs
				break
			case 3:
				if ((op&$00200000)=0)
				
					s+="mul"s+=cc
					if ((op&$00100000)<>0) s+='s'
					s+="\tr"+rd+",r"+rm+",r"+rs
				End
				else
				
					s+="mla"s+=cc
					if ((op&$00100000)<>0) s+='s'
					s+="\tr"+rn+",r"+rm+",r"+rs+",r"+rd	'rn<->rd???
				End
				break
			case 4:
				s+=muls[(op shr 21)&3]s+=cc
				if ((op&$00100000)<>0) s+='s'
				s+="\tr"+rd+",r"+rn+",r"+rm+",r"+rs
				break
			case 5:
				s+="mrs"s+=cc
				if ((op&$00400000)=0)
					s+="\tr"+rd+",cpsr"
				else
					s+="\tr"+rs+",spsr"
				break
			case 6:
				s+="msr"s+=cc
	'			i=(op&255) shl ((op shr 7)&30
				i=op&255
				j=(op shr 7)&30
				i=(i shr j)|(i shl (32-j))
				if ((op&$00400000)=0)
					s+="\tcpsr_"+rn+",#"+i
				else
					s+="\tspsr_"+rn+",#"+i
				break
			case 7:
				s+="msr"s+=cc
				if ((op&$00400000)=0)
					s+="\tcpsr_"+rn+",r"+rm
				else
					s+="\tspsr_"+rn+",r"+rm
				break
			case 8:
				s+="bx"s+=ccs+="\tr"s+=rm
			case 9:
				i=(op shr 20)&1
				if ((op&$01200000)=$00200000) i+=2
				i=op&$fffif ((op&$00800000)=0) i=-i
				select(i)
					case 0:break'"str"
					case 1:break'"ldr"
					case 2:break'"strt"
					case 3:break'"ldrt"
				End
				break
#Rem

				

				s+=strldr[i]s+=cc
				if ((op&$00400000)<>0) s+='b'
				s+="\tr"+rd+",[r"+rn			'r5,[r3
				if ((op&$01000000)=0)
				
					i=op&$fffif ((op&$00800000)=0) i=-i
					if (i=0) s+="]"else s+="],#"+i			'],#23
				End
				else
				
					i=op&$fffif ((op&$00800000)=0) i=-i
					if (i=0) s+="]"else s+=",#"+i+"]"			',#23]
					if ((op&$00200000)<>0) s+='!'
				End
				break

					
					ARM.9: Single Data Transfer (LDR, STR)
--------------------------------------

Opcode Format
  Bit    Expl.
  31-28  Condition
  27-26  Must be 01b for this instruction

  25     I - Immediate Offset Flag (0=Immediate, 1=Shifted Register)
  24     P - Pre/Post (0=post add offset after transfer, 1=pre before trans.)
  23     U - Up/Down Bit (0=down subtract offset from base, 1=up add to base)
  22     B - Byte/Word bit (0=transfer word quantity, 1=transfer byte quantity)
  When above Bit 24 P=0 (Post-indexing, write-back is ALWAYS enabled):
    21     T - Memory Managment (0=Normal, 1=Force non-privileged access)
  When above Bit 24 P=1 (Pre-indexing, write-back is optional):
    21     W - Write-back bit (0=no write-back, 1=write address into base)
  20     L - Load/Store bit (0=Store to memory, 1=Load from memory)
          0: STRcondEndBEndTEnd Rd,<Address>   [Rn+/-<offset>]=Rd
          1: LDRcondEndBEndTEnd Rd,<Address>   Rd=[Rn+/-<offset>]
          Whereas, B=Byte, T=Force User Mode (only for POST-Indexing)
  19-16  Rn - Base register               (R0..R15) (including R15=PC+8)
  15-12  Rd - Source/Destination Register (R0..R15) (including R15=PC+12)
  When above I=0 (Immediate as Offset)
    11-0   Unsigned 12bit Immediate Offset (0-4095, steps of 1)
  When above I=1 (Register shifted by Immediate as Offset)
    11-7   Is - Shift amount      (1-31, 0=Special/See below)
    6-5    Shift Type             (0=LSL, 1=LSR, 2=ASR, 3=ROR)
    4      Must be 0 (Reserved, see ARM.17, The Undefined Instruction)
    3-0    Rm - Offset Register   (R0..R14) (not including PC=R15)

Instruction Formats for <Address>
An expression which generates an address:
  <expression>                  an immediate used as address
  *** restriction: must be located in range PC+/-4095+8, if so,
  *** assembler will calculate offset and use PC (R15) as base.
Pre-indexed addressing specification:
  [Rn]                          offset = zero
  [Rn, <#+/-Endexpression>]!End   offset = immediate
  [Rn, +/-EndRm,<shift>End ]!End   offset = register shifted by immediate
Post-indexed addressing specification:
  [Rn], <#+/-Endexpression>      offset = immediate
  [Rn], +/-EndRm,<shift>End       offset = register shifted by immediate
Whereas...
  <shift>  immediate shift such like LSL#4, ROR#2, etc. (see ARM.5).
  !End      exclamation mark ("!") indicates write-back (Rn will be updated).

Notes
Shift amount 0 has special meaning, as described in ARM.5 Data Processing.
When writing a word (32bit) to memory, the address should be word-aligned.
When reading a byte from memory, upper 24 bits of Rd are zero-extended.

When reading a word from a halfword-aligned address (which is located in the
middle between two word-aligned addresses), the lower 16bit of Rd will contain
[address] ie. the addressed halfword, and the upper 16bit of Rd will contain
[Rd-2] ie. more or less unwanted garbage. However, by isolating lower bits this
may be used to read a halfword from memory. (Above applies to little endian
mode, as used in GBA.)

In a virtual memory based environment (ie. not in the GBA), aborts (ie. page
faults) may take place during execution, if so, Rm and Rn should not specify
the same register when post-indexing is used, as the abort-handler might have
problems to reconstruate the original value of the register.
#End


			case 10:
				i=(op shr 20)&1if ((op&$01200000)=$00200000) i+=2		'str|ldrtEnd
				s+=strldr[i]s+=cc
				if ((op&$00400000)<>0) s+='b'
				s+="\tr"+rd+",[r"+rn			'r5,[r3
				if ((op&$01000000)=0)
				
					s+="],"
					if ((op&$00800000)=0) s+='-'
					s+="r"+rm
					if ((op&$0ff0)<>0)
					
						i=(op shr 5)&3j=(op shr 7)&31
						if ((i=3)&&(j=0))
							s+=",rrx"
						else
							s+=","+shifts[i]+" #"+j
					End
				End
				else
				
					if ((op&$00800000)=0) s+='-'
					s+="r"+rm
					if ((op&$0ff0)<>0)
					
						i=(op shr 5)&3j=(op shr 7)&31
						if ((i=3)&&(j=0))
							s+=",rrx"
						else
							s+=","+shifts[i]+" #"+j
					End
					s+=']'
					if ((op&$00200000)<>0) s+='!'
				End
				break
			case 11:
				s+=strldr[(op shr 20)&1]s+=cc
				s+=bhsbsh[(op shr 5)&3]
				s+="\tr"+rd+",["+rn
				i=((op&$0f00) shr 4)|(op&$0f)if ((op&$00800000)=0) i=-i
				if ((op&$01000000)=0)
				
					s+="],#"+i
				End
				else
				
					s+="#"+i+"]"
					if ((op&$00200000)<>0) s+='!'
				End
				break
			case 12:
				s+=strldr[(op shr 20)&1]s+=cc
				s+=bhsbsh[(op shr 5)&3]
				s+="\tr"+rd+",["+rn
				i=((op&$0f00) shr 4)|(op&$0f)if ((op&$00800000)=0) i=-i
				if ((op&$01000000)=0)
				
					if ((op&$00800000)=0) s+="],-r" else s+="],r"
					s+=rm
				End
				else
				
					if ((op&$00800000)=0) s+=",-r" else s+=",r"
					s+=rms+=']'
					if ((op&$00200000)<>0) s+='!'
				End
				break
			case 13:
				s+="swp"s+=ccs+="\tr"+rd+",r"+rm+",[r"+rn+"]"
				break 
			case 14:
				s+=stmldm[(op shr 20)&1]s+=cc
				if ((op&$00800000)=0) s+='d'else s+='i'
				if ((op&$01000000)=0) s+='a'else s+='b'
				s+="\tr"+rnif ((op&$00200000)<>0) s+='!'
				s+=','
				s+=reglist(op&$ffff)
				if ((op&$00400000)<>0) s+='^'
				break
			case 15:
				s+="cdp"s+=cc
				s+="\ts"+rs+","+((op shr 20)&15)+",c"+rd+",c"+rn+",c"+rm+","+((op shr 5)&7)
				break
			case 16:
				s+=mcrmrc[(op shr 20)&1]s+=cc
				s+="\ts"+rs+","+((op shr 21)&7)+",c"+rd+",c"+rn+",c"+rm+","+((op shr 5)&7)
				break
			case 17:
				s+=stcldc[(op shr 20)&1]s+=cc
				s+="\tc"+rs+"cr"+rd+",[r"+rn	'cp_num,crd,[r
				i=op&255if ((op&$00800000)=0) i=-i
				if ((op&$01000000)=0) s+="],#"+i*4End
				else s+="#"+i*4+"]"if ((op&$00200000)<>0) s+='!'End
				break
			case 18:
				's+='b'if ((op&$01000000)<>0) s+='l's+=ccs+='\t'i=(op&$00ffffff) shl 8i=i shr 6s+=i
				i=(op&$00ffffff) shl 8
				i=i shr 6
				_r[15]+=4+i
				break
			case 19:
				s+="swi"s+=cc
				s+='\t's+=op&$00ffffff
				break
			case 20:
				s+="undefined"
				break
			End
		End


		Method armop:string(op:int)
			int			i,j,o,n,rd,rn,rm,rs
			string		cc,s

			n=0
			s=""

			select ((op shr 25)&7)
				case 0:
					if ((op&$10)=0) if ((op&$01b00000)=$01200000) n=7else n=1End
					if ((op&$01b00000)=$01000000) n=5End
					if ((op&$80)=0) if ((op&$01f000f0)=$01200010) n=8else n=2End
					if ((op&$01b000f0)=$01000090) n=13End
					if ((op&$010000f0)=$00000090) if ((op&$00800000)<>0) n=4else n=3End
					if ((op&$00200000)<>0) n=11else n=12
				case 1:if ((op&$01b00000)=$01200000) n=6else n=0
				case 2:n=9
				case 3:if ((op&$10)<>0) n=20else n=10
				case 4:n=14
				case 5:n=18
				case 6:n=17
				case 7:if ((op&$01000000)<>0) n=19Endif ((op&$10)<>0) n=16else n=15
			End

			cc=cclist[(op shr 28)&15]
			rn=(op shr 16)&15rd=(op shr 12)&15rs=(op shr 8)&15rm=op&15

			select (n)
			case 0:
				o=(op shr 21)&15
				s+=opname[o]
				s+=cc
				if ((op&$00100000)<>0)
					s+='s'
				End
	'			j=(op&255) shl ((op shr 7)&30)
				i=op&255
				j=(op shr 7)&30
				i=(i shr j)|(i shl (32-j))
				select (o)
					case 13:
					case 15:
						s+="\tr"+rd+",#"+hex32(i)
						break 'mov mvn
					case 8:
					case 9:
					case 10:
					case 11:
						s+="\tr"+rn+",#"+hex32(i)
						break 'tst teq cmp cmn
					default:
						s+="\tr"+rd+",r"+rn+",#"+hex32(i)
						break
				End
				break
			case 1:
				o=(op shr 21)&15
				s+=opname[o]
				s+=cc
				if ((op&$00100000)<>0)
					s+='s'
				End
				i=(op shr 5)&3j=(op shr 7)&31
				select (o)
					case 13:
					case 15:
						s+="\tr"+rd+",r"+rm
						break 'mov mvn
					case 8:
					case 9:
					case 10:
					case 11:
						s+="\tr"+rn+",r"+rm
						break	'tst teq cmp cmn
					default:
						s+="\tr"+rd+",r"+rn+",r"+rm
						break
				End
				if ((i=3)&&(j=0)) s+=",rrx"else s+=","+shifts[i]+" #"+j
				break
			case 2:
				s+=opname[(op shr 21)&15]
				s+=cc
				if ((op&$00100000)<>0) s+='s'
				i=(op shr 5)&3j=(op shr 7)&31
				s+="\tr"+rd+",r"+rn+",r"+rm+" "+shifts[i]+" r"+rs
				break
			case 3:
				if ((op&$00200000)=0)
				
					s+="mul"s+=cc
					if ((op&$00100000)<>0) s+='s'
					s+="\tr"+rd+",r"+rm+",r"+rs
				End
				else
				
					s+="mla"s+=cc
					if ((op&$00100000)<>0) s+='s'
					s+="\tr"+rn+",r"+rm+",r"+rs+",r"+rd	'rn<->rd???
				End
				break
			case 4:
				s+=muls[(op shr 21)&3]s+=cc
				if ((op&$00100000)<>0) s+='s'
				s+="\tr"+rd+",r"+rn+",r"+rm+",r"+rs
				break
			case 5:
				s+="mrs"s+=cc
				if ((op&$00400000)=0)
					s+="\tr"+rd+",cpsr"
				else
					s+="\tr"+rs+",spsr"
				break
			case 6:
				s+="msr"s+=cc
	'			i=(op&255) shl ((op shr 7)&30
				i=op&255
				j=(op shr 7)&30
				i=(i shr j)|(i shl (32-j))
				if ((op&$00400000)=0)
					s+="\tcpsr_"+rn+",#"+i
				else
					s+="\tspsr_"+rn+",#"+i
				break
			case 7:
				s+="msr"s+=cc
				if ((op&$00400000)=0)
					s+="\tcpsr_"+rn+",r"+rm
				else
					s+="\tspsr_"+rn+",r"+rm
				break
			case 8:
				s+="bx"s+=ccs+="\tr"s+=rm
			case 9:
				i=(op shr 20)&1if ((op&$01200000)=$00200000) i+=2		'str|ldrtEnd
				s+=strldr[i]s+=cc
				if ((op&$00400000)<>0) s+='b'
				s+="\tr"+rd+",[r"+rn			'r5,[r3
				if ((op&$01000000)=0)
				
					i=op&$fffif ((op&$00800000)=0) i=-i
					if (i=0) s+="]"else s+="],#"+i			'],#23
				End
				else
				
					i=op&$fffif ((op&$00800000)=0) i=-i
					if (i=0) s+="]"else s+=",#"+i+"]"			',#23]
					if ((op&$00200000)<>0) s+='!'
				End
				break
			case 10:
				i=(op shr 20)&1if ((op&$01200000)=$00200000) i+=2		'str|ldrtEnd
				s+=strldr[i]s+=cc
				if ((op&$00400000)<>0) s+='b'
				s+="\tr"+rd+",[r"+rn			'r5,[r3
				if ((op&$01000000)=0)
				
					s+="],"
					if ((op&$00800000)=0) s+='-'
					s+="r"+rm
					if ((op&$0ff0)<>0)
					
						i=(op shr 5)&3j=(op shr 7)&31
						if ((i=3)&&(j=0))
							s+=",rrx"
						else
							s+=","+shifts[i]+" #"+j
					End
				End
				else
				
					if ((op&$00800000)=0) s+='-'
					s+="r"+rm
					if ((op&$0ff0)<>0)
					
						i=(op shr 5)&3j=(op shr 7)&31
						if ((i=3)&&(j=0))
							s+=",rrx"
						else
							s+=","+shifts[i]+" #"+j
					End
					s+=']'
					if ((op&$00200000)<>0) s+='!'
				End
				break
			case 11:
				s+=strldr[(op shr 20)&1]s+=cc
				s+=bhsbsh[(op shr 5)&3]
				s+="\tr"+rd+",["+rn
				i=((op&$0f00) shr 4)|(op&$0f)if ((op&$00800000)=0) i=-i
				if ((op&$01000000)=0)
				
					s+="],#"+i
				End
				else
				
					s+="#"+i+"]"
					if ((op&$00200000)<>0) s+='!'
				End
				break
			case 12:
				s+=strldr[(op shr 20)&1]s+=cc
				s+=bhsbsh[(op shr 5)&3]
				s+="\tr"+rd+",["+rn
				i=((op&$0f00) shr 4)|(op&$0f)if ((op&$00800000)=0) i=-i
				if ((op&$01000000)=0)
				
					if ((op&$00800000)=0) s+="],-r" else s+="],r"
					s+=rm
				End
				else
				
					if ((op&$00800000)=0) s+=",-r" else s+=",r"
					s+=rms+=']'
					if ((op&$00200000)<>0) s+='!'
				End
				break
			case 13:
				s+="swp"s+=ccs+="\tr"+rd+",r"+rm+",[r"+rn+"]"
				break 
			case 14:
				s+=stmldm[(op shr 20)&1]s+=cc
				if ((op&$00800000)=0) s+='d'else s+='i'
				if ((op&$01000000)=0) s+='a'else s+='b'
				s+="\tr"+rnif ((op&$00200000)<>0) s+='!'
				s+=','
				s+=reglist(op&$ffff)
				if ((op&$00400000)<>0) s+='^'
				break
			case 15:
				s+="cdp"s+=cc
				s+="\ts"+rs+","+((op shr 20)&15)+",c"+rd+",c"+rn+",c"+rm+","+((op shr 5)&7)
				break
			case 16:
				s+=mcrmrc[(op shr 20)&1]s+=cc
				s+="\ts"+rs+","+((op shr 21)&7)+",c"+rd+",c"+rn+",c"+rm+","+((op shr 5)&7)
				break
			case 17:
				s+=stcldc[(op shr 20)&1]s+=cc
				s+="\tc"+rs+"cr"+rd+",[r"+rn	'cp_num,crd,[r
				i=op&255if ((op&$00800000)=0) i=-i
				if ((op&$01000000)=0) s+="],#"+i*4End
				else s+="#"+i*4+"]"if ((op&$00200000)<>0) s+='!'End
				break
			case 18:
				s+='b'if ((op&$01000000)<>0) s+='l's+=cc
				s+='\t'i=(op&$00ffffff) shl 8i=i shr 6s+=i
				break
			case 19:
				s+="swi"s+=cc
				s+='\t's+=op&$00ffffff
				break
			case 20:
				s+="undefined"
				break
			End
			return s
		End


		Method thumbex:void(op:ushort)
			shft:int
			rd:int
			a:int,b

			if ((op&$f800)=$1800)'case 1:'add,sub
				select((op shr 9)&1)
					case 0:'add	
						if ((op&$0400)=0)
							a=_r[(op shr 3)&7]
							b=_r[(op shr 6)&7]
	'								b="r"+(op&7)+"=r"+((op shr 3)&7)+"+r"+((op shr 6)&7)
	'								_r[op&7]=_r[(op shr 3)&7]+_r[(op shr 6)&7]
						Else 
							'b="r"+(op&7)+"=r"+((op shr 3)&7)+"+"+((op shr 6)&7)
							a=_r[(op shr 3)&7]
							b=(op shr 6)&7
	'								_r[op&7]=_r[(op shr 3)&7]+(op shr 6)&7
						End
						_v=a+b<a
						_c=((a+b) shr 31)&1
						break
					case 1:'sub
						if ((op&$0400)=0)
							'b="r"+(op&7)+"=r"+((op shr 3)&7)+"-r"+((op shr 6)&7)
							'_r[op&7]=_r[(op shr 3)&7]-_r[(op shr 6)&7]
							a=_r[(op shr 3)&7]
							b=_r[(op shr 6)&7]
						Else 
							'b="r"+(op&7)+"=r"+((op shr 3)&7)+"-"+((op shr 6)&7)
							'_r[op&7]=_r[(op shr 3)&7]-(op shr 6)&7
							a=_r[(op shr 3)&7]
							b=(op shr 6)&7
						End
						_r[op&7]=a-b
						_v=(uint)b > (uint)a
						_c=1-((a-b) shr 31)&1
						break
				End
				_nzr=op&7
				return
			End
			
			if ((op&$e000)=0)  'case 0:lsl,lsr,asr,nop
				shft=((op shr 6)&31)
				select(op shr 11)
				case 0:'lsl					
					'b="r"+(op&7)+"=r"+((op shr 3)&7)+" shl "+shft
					_r[op&7]=_r[((op shr 3)&7)] shl shft
					break
				case 1:'lsr
					if (shft=0) shft=32
					'b="r"+(op&7)+"=r"+((op shr 3)&7)+" shr >"+shft
					_r[op&7]=(int) ((uint)_r[((op shr 3)&7)]) shr shft
					break
				case 2:'asr
					if (shft=0) shft=32
					'b="r"+(op&7)+"=r"+((op shr 3)&7)+" shr "+shft
					_r[op&7]=_r[((op shr 3)&7)] shr shft
					break
				case 3:
					'b=""
					break
				End
				_nzr=op&7
				return
			End

			
			if ((op&$e000)=$2000)'case 2:	'"MOV","CMP","ADD","SUB"
				select((op shr 11)&3)
					case 0:
						'b=" r"+((op shr 8)&7)+"="+(op&255)
						_r[(op shr 8)&7]=op&255
						break
					case 1:
						'b=" cmp=r"+((op shr 8)&7)+"="+(op&255)
						_cmp(_r[(op shr 8)&7],op&255)
						break
					case 2:
						'b=" r"+((op shr 8)&7)+"+="+(op&255)
						_r[(op shr 8)&7]+=op&255
						break
					case 3:
						'b=" r"+((op shr 8)&7)+"-="+(op&255)
						_r[(op shr 8)&7]-=op&255
						break
				End
				return
			End

			if ((op&$fc00)=$4000)'case 3: '"AND","EOR","LSL","LSR","ASR","ADC","SBC","ROR","TST","NEG","CMP","CMN","ORR","MUL","BIC","MVN"
				select((op shr 6)&15)
					case 0:'b="r"+(op&7)+"&=r"+((op shr 3)&7)
						_r[op&7]&=_r[(op shr 3)&7]
					case 1:'b="r"+(op&7)+"^=r"+((op shr 3)&7)
						_r[op&7]^=_r[(op shr 3)&7]
					case 2:'b="r"+(op&7)+" shl =r"+((op shr 3)&7)
						_r[op&7] shl =_r[(op shr 3)&7]
					case 3:'b="r"+(op&7)+" shr =r"+((op shr 3)&7)
						_r[op&7] shr =_r[(op shr 3)&7]
					case 4:'b="r"+(op&7)+" shr >=r"+((op shr 3)&7)
						_r[op&7]=(int) ((uint)_r[op&7]) shr _r[(op shr 3)&7]
					case 5:'b="r"+(op&7)+"+=c+r"+((op shr 3)&7)
						_r[op&7]+=_c+_r[(op shr 3)&7]
					case 6:'b="r"+(op&7)+"-=c+r"+((op shr 3)&7)
						_r[op&7]-=_c+_r[(op shr 3)&7]
					case 7:'b="r"+(op&7)+"=ror(r"+(op&7)+",r"+((op shr 3)&7)+")"							
						_r[op&7]=_ror(_r[op&7],_r[(op shr 3)&7])
					case 8:'b="tst(r"+(op&7)+",r"+((op shr 3)&7)+")"
						_cmp(_r[op&7],_r[(op shr 3)&7])
					case 9:'b="r"+(op&7)+"=-"+((op shr 3)&7)
						_r[op&7]=-_r[(op shr 3)&7]
					case 10:'b="cmp(r"+(op&7)+",r"+((op shr 3)&7)+")"
						_cmp(_r[op&7],_r[(op shr 3)&7])
					case 11:'b="cmp(r"+(op&7)+",-r"+((op shr 3)&7)+")"
						_cmp(_r[op&7],-_r[(op shr 3)&7])
					case 12:'b="r"+(op&7)+"|=r"+((op shr 3)&7)
						_r[op&7]|=_r[(op shr 3)&7]
					case 13:'b="r"+(op&7)+"*=r"+((op shr 3)&7)
						_r[op&7]*=_r[(op shr 3)&7]
					case 14:'b="r"+(op&7)+"&=~(1 shl "+((op shr 3)&7)+")"
						_r[op&7]&=~_r[(op shr 3)&7]
					case 15:'b="r"+(op&7)+"=~r"+((op shr 3)&7)
						_r[op&7]=~_r[(op shr 3)&7]
				End
				_nzr=op&7
				return
			End

			if ((op&$fc00)=$4400)'case 4: '"ADD","CMP","MOV","BX"
				rd=(op&7)|((op shr 4)&8)
				select((op shr 8)&3)
					case 0:'b="r"+rd+"+=r"+((op shr 3)&15)
						_r[rd]+=_r[(op shr 3)&15]
						_nzr=rd
						break
					case 1:'b="cmp(r"+rd+",r"+((op shr 3)&15)+")"
						_cmp(_r[rd],_r[(op shr 3)&15])
						break
					case 2:'b="r"+rd+"=r"+((op shr 3)&15)
						_r[rd]=_r[(op shr 3)&15]
						' todo: add cross bank exceptions
						_nzr=rd
						_c=0
						_v=false
						break
					case 3:'b="r15=r"+((op shr 3)&15)	'PC=
						_r[15]=_r[(op shr 3)&15]
						break
				End
				return
			End

			if ((op&$f800)=$4800)'case 5: '"LDR"
				'b="r"+((op shr 8)&7)+"=ld(r15+"+((op&255)*4)+")"
				_r[(op shr 8)&7]=_ram[_mask&((_r[15] shr 2)+(op&255))]
				_nzr=(op shr 8)&7
				return
			End
				
			if ((op&$f200)=$5000)'case 6: '"STR","STRB","LDR","LDRB"
				select((op shr 10)&3)
					case 0:'b="st(r"+((op shr 3)&7)+"+"+((op shr 6)&7)+",r"+(op&7)+")"
						_ram[ _mask&( (_r[(op shr 3)&7] shr 2) + ((op shr 6)&7) )]=_r[op&7]
						break
					case 1:'b="stb(r"+((op shr 3)&7)+"+"+((op shr 6)&7)+",r"+(op&7)
						_stb(_r[(op shr 3)&7]+((op shr 6)&7),_r[op&7])
						break
					case 2:'b="r"+(op&7)+"=ld(r"+((op shr 3)&7)+"+r"+(((op shr 6)&7)*4)+")"
						_r[op&7]=_ram[ _mask&( (_r[(op shr 3)&7] shr 2) + _r[(op shr 6)&7] ) ]
						break
					case 3:'b="r"+(op&7)+"=ldb(r"+((op shr 3)&7)+"+r"+((op shr 6)&7)+")"
						_r[op&7]=_ldb( _r[(op shr 3)&7] + _r[(op shr 6)&7] )
						break
				End
				return
			End

			if ((op&$f200)=$5200) ' case 7: '"STRH","LDSB","LDRH","LDSH"
				select((op shr 10)&3)
					case 0:'b="sth(r"+((op shr 3)&7)+"+r"+((op shr 6)&7)+",r"+(op&7)+")"
						_strh(_r[(op shr 3)&7]+_r[(op shr 6)&7],_r[op&7])
						break
					case 1:'b="r"+(op&7)+"=ldsb(r"+((op shr 3)&7)+"+r"+((op shr 6)&7)+")"
						_r[op&7]=_ldsb(_r[(op shr 3)&7]+_r[(op shr 6)&7])
						_nzr=op&7
						break
					case 2:'b="r"+(op&7)+"=ldh(r"+((op shr 3)&7)+"+r"+((op shr 6)&7)+")"
						_r[op&7]=_ldrh(_r[(op shr 3)&7]+_r[(op shr 6)&7])
						_nzr=op&7
						break
					case 3:'b="r"+(op&7)+"=ldsh(r"+((op shr 3)&7)+"+r"+((op shr 6)&7)+")"
						_r[op&7]=_ldsh(_r[(op shr 3)&7]+_r[(op shr 6)&7])
						_nzr=op&7
						break
				End
				return
			End

			if ((op&$e000)=$6000) 'case 8: '"STR","LDR","STRB","LDRB"
				select((op shr 11)&3)	
					case 0:'b="st(r"+((op shr 3)&7)+"+"+(((op shr 6)&7)*4)+",r"+(op&7)+")"
						_ram[_mask&( (_r[(op shr 3)&7] shr 2) + _r[(op shr 6)&7] )] = _r[op&7]
						break
					case 1:'b="r"+(op&7)+"=ld(r"+((op shr 3)&7)+"+"+(((op shr 6)&7)*4)+")"
						_r[op&7]=_ram[_mask&( (_r[(op shr 3)&7] shr 2) +((op shr 6)&7) )]
						break
					case 2:'b="stb(r"+((op shr 3)&7)+"+"+((op shr 6)&7)+"+"+(op&7)+")"
						_stb( _r[(op shr 3)&7]+((op shr 6)&7),(op&7))
						break
					case 3:'b="r"+(op&7)+"=ldb(r"+((op shr 3)&7)+"+"+((op shr 6)&7)+")"
						_r[op&7]=_ldb(_r[(op shr 3)&7]+((op shr 7)&7))
						break
				End
				return
			End

			if ((op&$f000)=$8000) 'case 9: '"STRH","LDRH"
				select((op shr 11)&1)
					case 0:'b="sth(r"+(op&7)+(((op shr 6)&31)*2)+",r"+((op shr 3)&7)+")"
						_strh(_r[op&7]+((op shr 6)&31)*2,_r[(op shr 3)&7])
						break
					case 1:''b="r"+(op&7)+"=ldh(r"+((op shr 3)&7)+"+"+(((op shr 6)&31)*2)+")"
						_r[op&7]=_ldrh( _r[(op shr 3)&7]+((op shr 6)&31)*2 )
						break
				End
				return
			End

			if ((op&$f000)=$9000) 'case 10: '"STR","LDR"
				select((op shr 11)&1)
					case 0:'b="st(r"+(op&7)+(((op shr 6)&31)*4)+",r"+((op shr 3)&7)+")"
						_ram[_mask&( (_r[op&7] shr 2)+((op shr 6)&31) )] = _r[(op shr 3)&7]
						break
					case 1:'b="r"+(op&7)+"=ld(r"+((op shr 3)&7)+"+"+(((op shr 6)&31)*4)+")"
						_r[op&7]=_ram[_mask&( (_r[(op shr 3)&7] shr 2)+((op shr 6)&31) )]
						break
				End
				return
			End

			if ((op&$f000)=$a000) 'case 11: '"ADD"
				'b="r"+((op shr 8)&7)+"="
				if ((op&$800)<>0) 
					'b+="r13+"
					_r[(op shr 8)&7]=_r[13]+(op&255)*4
				Else 
					'b+="r15+"
					_r[(op shr 8)&7]=_r[15]+(op&255)*4
					'b+=((op&255)*4)
				End
				_nzr=(op shr 8)&7
				return
			End

			if ((op&$ff00)=$b000) 'case 12: '"ADD SP,"
				'b="r15+="+((op&255-128)*4)
				a=(op&127)*4
				if((op&128)=128)
					a=-a
				End
				_r[13]+=a
	'					_r[13]+=((op&255-128)*4)
				_nzr=13
				return
			End

			if ((op&$f600)=$b400) 'case 13: '"PUSH","POP"
				select((op shr 11)&1)
					case 0:'b="push("+(op&255)+")"
						_push(op)
						break
					case 1:'b="pop("+(op&255)+")"
						_pop(op)
						break
				End
				return
			End

			if ((op&$f000)=$c000) 'case 14: '"STMIA","LDMIA"
				select((op shr 11)&1)
					case 0:'b="stmia("+(op&255)+")"
						_stmia(op&255)
						break
					case 1:'b="ldmia("+(op&255)+")"
						_ldmia(op&255)
						break
				End
				return
			End

			if ((op&$ff00)=$df00) 'case 16: '"SWI"
				'b="swi("+(op&255)+")"
				_swi(op&255)
				return
			Else if ((op&$f000)=$d000) 'case 15: '"BEQ","BNE","BCS","BCC","BMI","BPL","BVS","BVC","BHI","BLS","BGE","BLT","BGT","BLE","???","***"
				'b="branch("+op+")"
				_branch(op)
				return
			End
			
			if ((op&$f800)=$e000) 'case 17: '"B"
				if((op&$400)<>0)
					'b="r15+="+(4+((-$400|(op&$3ff))*2))
					_r[15]+=(2+((-$400|(op&$3ff))*2))
				else
					'b="r15+="+(4+(op&$3ff)*2)
					_r[15]+=+(2+(op&$3ff)*2)
				return
			End

			if ((op&$f000)=$f000) 'case 18: '"BL","BH"
				select((op shr 11)&1)
					case 0:'b="bl="+(op&$7ff)
						_bl(op&$7ff)
						break
					case 1:'b="bh="+(op&$7ff)
						_bh(op&$7ff)
						break
				End
				return
			End
		End
		
		Method thumbop:string(op:ushort)
			b:string
			grp:int
			i:int
			t:int
			
			for (grp=18grp>=0grp--) 
				if ((op&thumb19[grp*2])=thumb19[grp*2+1]) break
			End

			b=""

			select (grp)
				case -1:
					b+="???"
					break
				case 0:
					b+=g1[op shr 11]
					b+=" r"+(op&7)+",r"+((op shr 3)&7)+","+((op shr 6)&31)
					break
				case 1:
					b+=g2[(op shr 9)&1]
					if ((op&$0400)=0)
						b+=" r"+(op&7)+",r"+((op shr 3)&7)+",r"+((op shr 6)&7)
					Else 
						b+=" r"+(op&7)+",r"+((op shr 3)&7)+","+((op shr 6)&7)
					End
					break
				case 2:
					b+=g3[(op shr 11)&3]
					b+=" r"+((op shr 8)&7)+","+(op&255)
					break
				case 3:
					b+=g4[(op shr 6)&15]
					b+=" r"+(op&7)+",r"+((op shr 3)&7)
					break
				case 4:
					b+=g5[(op shr 8)&3]
					if ((op&$0300)=$300) 	'bx
						b+=" r"+((op shr 3)&15)
					Else 
						b+=" r"+((op&7)+((op shr 4)&8))+",r"+((op shr 3)&15)
					End
					break
				case 5:
					b+=g6[0] 'ldr
					b+=" r"+((op shr 8)&7)+",[PC+"+((op&255)*4)+"]"
					break
				case 6:
					b+=g7[(op shr 10)&3]		
					b+=" r"+(op&7)+",[r"+((op shr 3)&7)+",r"+((op shr 6)&7)+"]"
					break
				case 7:
					b+=g8[(op shr 10)&3]		
					b+=" r"+(op&7)+",[r"+((op shr 3)&7)+",r"+((op shr 6)&7)+"]"
					break
				case 8:
					b+=g9[(op shr 11)&3]		
					if((op&$1000)<>0)
						b+=" r"+(op&7)+",[r"+((op shr 3)&7)+","+((op shr 6)&31)+"]"
					Else
						b+=" r"+(op&7)+",[r"+((op shr 3)&7)+","+(((op shr 6)&31)*4)+"]"
					End
					break
				case 9:
					b+=g10[(op shr 11)&1]		
					b+=" r"+(op&7)+",r"+((op shr 3)&7)+","+(((op shr 6)&31)*2)
					break
				case 10:
					b+=g11[(op shr 11)&1]		
					b+=" r"+((op shr 8)&7)+",[SP+"+((op&255)*4)+"]"
					break
				case 11:
					b+=g12[0]		
					b+=" r"+((op shr 8)&7)+","
					if ((op&$800)<>0) b+="SP,"else b+="PC,"
					b+=((op&255)*4)
					break
				case 12:
					b+=g13[0]	'ADD SP,#+-127
					t=(op&127)*4
					if((op&128)=128)
						t=-t
					End
					b+=" SP,"+t
'					b+=" SP,"+((op&255-128)*4)
'					_r[13]+=((op&255-128)*4)

					break
				case 13:
					b+=g14[(op shr 11)&1]+" "
					if((op&$100)<>0)
						if((op&$800)<>0)	'pop
							b+="r15,"
						Else
							b+="r14,"
						End
					End
					for(i=7i>=0i--)
						if((op&(1 shl i))<>0)
							b+="r"+i+","
						End
					End
'trim??					b=b.subString(0,b.Length-1)
					break
				case 14:
					b+=g15[(op shr 11)&1]
					b+=" r"+((op shr 8)&7)
					for(i=7i>=0i--)
						if((op&(1 shl i))<>0)
							b+=",r"+i
						End
					End
					break
				case 15:
					b+=g16[(op shr 8)&15]
					if((op&128)<>0)
						b+=" $"+(4+((-128|(op&127))*2))
					else
						b+=" $+"+(4+(op&127)*2)
					break
				case 16:
					b+=g17[0]
					b+=" "+(op&255)
					break
				case 17:
					b+=g18[0]
					if((op&$400)<>0)
						b+=" $"+(4+((-$400|(op&$3ff))*2))
					else
						b+=" $+"+(4+(op&$3ff)*2)
					break
				case 18:
					b+=g19[(op shr 11)&1]
					b+=" $"+hex16((ushort)(op&$7ff))
					break
			End
			return b
		End

	End
End

#Rem

  ADD Rd,Rs,Imm3bit   1S     NZCV  2   Rd=Rs+nn
  ADD Rd,Imm8bit      1S     NZCV  3   Rd=Rd+nn
  ADD Rd,Rs,Rn        1S     NZCV  2   Rd=Rs+Rn
  ADC Rd,Rs           1S     NZCV  4   Rd=Rd+Rs+Cy
  SUB Rd,Rs,Imm3Bit   1S     NZCV  2   Rd=Rs-nn
  SUB Rd,Imm8bit      1S     NZCV  3   Rd=Rd-nn
  SUB Rd,Rs,Rn        1S     NZCV  2   Rd=Rs-Rn
  SBC Rd,Rs           1S     NZCV  4   Rd=Rd-Rs-NOT Cy
  NEG Rd,Rs           1S     NZCV  4   Rd=0-Rs
  CMP Rd,Imm8bit      1S     NZCV  3 Void=Rd-nn
  CMP Rd,Rs           1S     NZCV  4 Void=Rd-Rs
  CMP R0-15,R8-15     1S     NZCV  5 Void=Rd-Rs
  CMP R8-15,R0-15     1S     NZCV  5 Void=Rd-Rs
  CMN Rd,Rs           1S     NZCV  4 Void=Rd+Rs
  MUL Rd,Rs           1S+mI  NZx-  4   Rd=Rd*Rs

  MOV Rd,Imm8bit      1S     NZ--  3   Rd=nn
  MOV Rd,Rs           1S     NZ00  2   Rd=Rs+0
  MVN Rd,Rs           1S     NZ--  4   Rd=NOT Rs
  AND Rd,Rs           1S     NZ--  4   Rd=Rd AND Rs
  TST Rd,Rs           1S     NZ--  4 Void=Rd AND Rs
  BIC Rd,Rs           1S     NZ--  4   Rd=Rd AND NOT Rs
  ORR Rd,Rs           1S     NZ--  4   Rd=Rd OR Rs
  EOR Rd,Rs           1S     NZ--  4   Rd=Rd XOR Rs

  LSL Rd,Rs,Imm5bit   1S     NZc-  1   Rd=Rs SHL nn
  LSL Rd,Rs           1S+1I  NZc-  4   Rd=Rd SHL (Rs AND 0FFh)
  LSR Rd,Rs,Imm5bit   1S     NZc-  1   Rd=Rs SHR nn
  LSR Rd,Rs           1S+1I  NZc-  4   Rd=Rd SHR (Rs AND 0FFh)
  ASR Rd,Rs,Imm5bit   1S     NZc-  1   Rd=Rs SRA nn
  ASR Rd,Rs           1S+1I  NZc-  4   Rd=Rd SRA (Rs AND 0FFh)
  ROR Rd,Rs           1S+1I  NZc-  4   Rd=Rd ROR (Rs AND 0FFh)

Carry flag affected only if shift amount is non-zero.

  NOP                 1S     ----  5   R8=R8
  MOV R0..14,R8..15   1S     ----  5   Rd=Rs
  MOV R8..14,R0..15   1S     ----  5   Rd=Rs
  MOV R15,R0..15      2S+1N  ----  5   PC=Rs

  ADD R0..14,R8..15   1S     ----  5   Rd=Rd+Rs
  ADD R8..14,R0..15   1S     ----  5   Rd=Rd+Rs
  ADD R15,R0..15      2S+1N  ----  5   PC=Rd+Rs
  ADD Rd,PC,Imm8bit*4 1S     ---- 12   Rd=(($+4) AND NOT 2)+nn
  ADD Rd,SP,Imm8bit*4 1S     ---- 12   Rd=SP+nn
  ADD SP,Imm7bit*4    1S     ---- 13   SP=SP+nn
  ADD SP,-Imm7bit*4   1S     ---- 13   SP=SP-nn
#End





