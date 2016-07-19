#Import "<std>"
#Import "assets/chopin.mid"

Using std..

Global HexDigits:=New String[]("0","1","2","3","4","5","6","7","8","9","A","B","C","D","E","F")

Function HexByte:String(value:Int)
	Local v0:=(value Shr 4)&15
	Local v1:=value&15
	Return HexDigits[v0]+HexDigits[v1]
End

Function HexList:String(binary:Int[])
	Local h:String
	For Local i:=0 Until binary.Length
		h+=HexByte(i)+","	
	Next
	Return h
End

Class MidiFile
	Private 
	
	Field stream:FileStream		
	Field clock:Int	

	Field databuffer:=New DataBuffer(256)
	Field midibuffer:=New List<Byte[]>
				
	Function ReadBigInt:Int(stream:FileStream)
		Local b0:=$ff&stream.ReadByte()
		Local b1:=$ff&stream.ReadByte()
		Local b2:=$ff&stream.ReadByte()
		Local b3:=$ff&stream.ReadByte()
		Return (b0 Shl 24)|(b1 Shl 16)|(b2 Shl 8)|b3
	End
	
	Function ReadBigShort:Short(stream:FileStream)
		Local b0:=$ff&stream.ReadByte()
		Local b1:=$ff&stream.ReadByte()
		Return (b0 Shl 8)|b1
	End
	
	Method Reset()	
	
		stream=FileStream.Open("/Users/simon/m2/vsynth/assets/chopin.mid","r")	
		
		If Not stream
			Print "Could not open file"
			Return
		Endif
		
		Local hdr:=New Byte[4]
		Local chunksize:Int
		Local fileformat:Int
		Local trackcount:Int
		Local timediv:Int
		
		hdr[0]=stream.ReadByte()
		hdr[1]=stream.ReadByte()
		hdr[2]=stream.ReadByte()
		hdr[3]=stream.ReadByte()
		
		If Not (hdr[0]=$4d And hdr[1]=$54 And hdr[2]=$68 And hdr[3]=$64)
			Print "Not a valid midi file"
			Return
		Endif
		
		chunksize=ReadBigInt(stream)

		fileformat=ReadBigShort(stream)
		trackcount=ReadBigShort(stream)
		timediv=ReadBigShort(stream)
		
		Print "chopin.mid "+chunksize+","+fileformat+","+trackcount+","+timediv
								
		For Local i:=0 Until trackcount
		
			hdr[0]=stream.ReadByte()
			hdr[1]=stream.ReadByte()
			hdr[2]=stream.ReadByte()
			hdr[3]=stream.ReadByte()
			
			If Not (hdr[0]=$4d And hdr[1]=$54 And hdr[2]=$72 And hdr[3]=$6B)
				Print "Error#"
				Exit				
			Endif
			
			chunksize=ReadBigInt(stream)		
			
			Print "track#"+i+" "+chunksize			

			Local p:=0
			Local status:=0
			
			While p<chunksize
				
				Local t:Int
				Local b:Int
				
				While True
					b=stream.ReadByte()
					p+=1
					t=(t Shl 7) | (b & $7f)
					If (b&$80)=0 Exit
				Wend
				
				Local cmd:Int,channel:Int,p0:Byte,p1:Byte,p2:Byte,p3:Byte,p4:Byte,n:Int
				
				cmd=stream.ReadByte()
				cmd&=$ff
				
				If cmd&$80=0
					p0=cmd
					cmd=status
					p+=1
				Else	
					status=cmd			
					p0=stream.ReadByte()				
					p+=2
				Endif				
				
				Select cmd
				
					Case 255
						Select p0
							Case 47
								n=stream.ReadByte()
								p+=1
								Print ":"+t+" [ END TRACK ] "+n
								
							Case 81
								n=stream.ReadByte()
								p1=stream.ReadByte()								
								p2=stream.ReadByte()								
								p3=stream.ReadByte()	
								p+=4
								Print ":"+t+" [ TEMPO ] "+HexByte(p1)+","+HexByte(p2)+","+HexByte(p3)
							Case 88
								n=stream.ReadByte()
								p1=stream.ReadByte()								
								p2=stream.ReadByte()								
								p3=stream.ReadByte()	
								p4=stream.ReadByte()							
								p+=5				
								Print ":"+t+" [ TIMESIG ] "+p1+","+p2+","+p3+","+p4
							Case 89
								n=stream.ReadByte()
								p1=stream.ReadByte()								
								p2=stream.ReadByte()								
								p+=3				
								Print ":"+t+" [ KEYSIG ] "+p1+","+p2
							Default
								p1=stream.ReadByte()								
								stream.Read(databuffer,0,p1)	
								Local text:String				
								For Local i:=0 Until p1
									Local char:=databuffer.PeekByte(i) & $ff
									text+=String.FromChar(char)
								Next					
								p+=1+p1				
								Print ":"+t+" [ META ] "+p0+","+p1+":"+text
						End

					Case 240,247
						Local t2:Int
						While True
							t2=(t2 Shl 7) | (p0 & $7f)
							If (p0&$80)=0 Exit
							p0=stream.ReadByte()
							p+=1
						Wend						
						Print ":"+t+" [ SYSEX ] "+t2
					
					Default
						channel=cmd & $f
						cmd=cmd Shr 4
					
						Select cmd
					
							Case 12
								Print " ["+cmd+"] #"+channel+","+p0+" +"+t					
							
							Case 13
								Print " ["+cmd+"] #"+channel+","+p0+" +"+t					
	
							Default				
								p1=stream.ReadByte()								
								p+=1
								print "["+cmd+"] #"+channel+","+p0+","+p1+" +"+t
								midibuffer.AddLast(New Byte[](cmd Shl 4,p0,p1))								
						End
				End
				
			Wend				
		
		Next		
				
	End

End

Function Main()
	Print "readmidi v0.0"	
	New MidiFile().Reset()
End
