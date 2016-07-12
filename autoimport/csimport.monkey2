#import "<std>"

Global TypeList:=new String[]("void","int","ushort","string","int[]")

Function FixType:String(line:string,name:String)
	Local modified:=false
	While True
		Local p:=line.Find(name+" ")		
		If p=-1 exit
		Local q:=p+name.Length
		Local r:=q+1
		While r<line.Length
			Local char:=line[r]
			If char<48 Exit
			If char>57 And char<65 Exit
			If char>90 And char<95 Exit
			If char>122 Exit
			r+=1			
		Wend
		
		
'		line=line.Slice(0,p)+line.Slice(q+1,r)+line.Slice(p,q)+":"+name+line.Slice(r)	
'		line=line.Slice(0,p)+line.Slice(p,q)+":"+line.Slice(q+1,r)+"!"+name+line.Slice(r)	
		Local nametype:String
		If (r>q+1) nametype=line.Slice(q+1,r)+":"+name	
		line=line.Slice(0,p)+nametype+line.Slice(r)	
		modified=True
	Wend	
	Return line
end

Function TranslateCSToMonkey2(in:String,out:String)
	local cs:=std.stringio.LoadString(in)
	Local file:=std.stream.FileStream.Open(out,"w")

	For Local line:=Eachin cs.Split("~n")
	
		line=line.Replace("//","'")

		Local p:=line.Find("/*")
		Local q:=line.Find("*/")
		Local r:=q
		If q=-1 
			r=line.Length
		Else
			line=line.Slice(0,q)+"~n#End~n"+line.Slice(q+2)		
		Endif
		If p<>-1
			line=line.Slice(0,p)+"~n#Rem~n"+line.Slice(p+2)
		Endif			
		
		If line.Trim()="break" Continue
		line=line.Replace(";break;","")
				
		line=line.Replace(";","")
		line=line.Replace("0x","$")
		line=line.Replace("==","=")
		line=line.Replace("!=","<>")
		line=line.Replace(">>"," shr ")
		line=line.Replace("<<"," shl ")

		line=line.Replace(".length",".Length")
						
		For Local typename:=Eachin TypeList
			line=FixType(line,typename)
		next

		line=line.Replace("switch","select")
		line=line.Replace("abstract ","")
		line=line.Replace("public static class","Class")
		line=line.Replace("public class","Class")
		line=line.Replace("public static","Function ")
		line=line.Replace("public ","Method ")
		line=line.Replace("static []","Global ")

		line=line.Replace("{","")
		line=line.Replace("}else","Else")
		line=line.Replace("} else","Else")
		line=line.Replace("}","End")
		
global buffer:=new Byte[4096]
		local n:=line.Utf8Length
		line.ToUtf8String(buffer.Data,4096)
		file.Write(buffer.Data,n)

'		Print line
	Next
	
	file.Close()
End

Function Main()
	Print "CSImport v0.01"
	Local in:="/Users/simon/nitrologic/simon/xna/xnakernal/thumb.cs"
	Local out:="thumb.monkey2"
	TranslateCSToMonkey2(in,out)
End
