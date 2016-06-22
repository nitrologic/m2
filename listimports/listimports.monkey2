#Import "<std>"

Using std..

Function DecodeCHeader(path:String)

	Local header:=LoadString(path)
	Local inclass:=0
	Local isPublic:=False
	
	For Local line:=Eachin header.Split("~r~n")
		
		If line.StartsWith("class ") And Not line.EndsWith(";")
			line=line.Replace(": public", "extends")
			Print line
			inclass=1
			Continue
		Endif
			
		If line.StartsWith("struct ") And Not line.EndsWith(";")
			line=line.Replace(": public", "extends")
			Print line
			inclass=1
			Continue
		Endif
		
		If line.StartsWith("};") And inclass
			inclass-=1
			If inclass=1 
				Print "end~n"
				inclass=0
			Endif
		Endif
		
		Local semi:=line.Find(";")
		If semi>0 line=line.Slice(0,semi)
		
		line=line.Trim()
		line=line.Replace("const ","")
		line=line.Replace(" const","") 
		
		If line="{" 
			inclass+=1
			Continue
		Endif
		If line="}" 
			inclass-=1
			Continue
		Endif

		If inclass=2 And line.Length
			If line.StartsWith("///") Continue
			If line.StartsWith("#") Continue
			
			If line="public:" Continue
						
			If line.StartsWith("virtual ") line=line.Slice(8)
			
			Local s:Int=line.Find(" ")
			Local b0:Int=line.Find("(")
			Local b1:Int=line.Find(")")
			
			If b0>0
				If s>0				
					Local t:String=line.Slice(0,s)
					Local f:String=line.Slice(s+1,b0)
					If t="int32" t="Int"
					If t="float32" t="Float"
					t=t.Replace("*","")
					If t="void" t="" Else t=":"+t
					
					Local args:=New List<String>
	
					Local b:String=line.Slice(b0+1,b1)
					For Local a:=Eachin b.Split(",")
					
						a=a.Trim()
						
						Local p:=a.Find(" ")
						Local c:=a.Slice(0,p)
						Local n:=a.Slice(p+1)
						
						c=c.Replace("*","")
						c=c.Replace("&","")
						
						If c="uint8" c="Byte"
						If c="int32" c="Int"
						If c="float32" c="Float"

						args.AddLast(n+":"+c)
					
					Next
					Print "~tMethod "+f+t+"("+args.Join(",")+")"
				
				Endif
			Else				
				If s>0
					Local t:String=line.Slice(0,s)
					Local f:String=line.Slice(s+1)
'					t=t.Trim()
					t=t.Replace("*","")
					
					If t="uint8" t="Byte"
					If t="int32" t="Int"
					If t="float32" t="Float"
					If t="void" t="" Else t=":"+t
				
					Print "~tField "+f+t
				Endif
			Endif
			
			
'			Print "~t"+line
		
		Endif
			
	Next
End

Function ListHeaders(filepath:String, ext:String)
	Local files:=LoadDir(filepath)
	For Local file:=Eachin files
		Local path:=filepath+"/"+file
		Select GetFileType(path)		
			Case FileType.File			
				If file.EndsWith(ext)		
					DecodeCHeader(path)
				Endif				
			Case FileType.Directory
				ListHeaders(path,ext)				
		End
	Next
End


Function ListImports(filepath:String, ext:String)
	Local files:=LoadDir(filepath)
	For Local file:=Eachin files
		Local path:=filepath+"/"+file
		Select GetFileType(path)		
			Case FileType.File			
				If file.EndsWith(ext)		
					Local subpath:=path.Slice(2)
					Print "#Import ~q"+subpath+"~q"				
				Endif				
			Case FileType.Directory
				ListImports(path,ext)				
		End
	Next
End



Function Main()
	Print "ListImports v0.01"
	ChangeDir("/Users/simon/monkey2/modules/box2d")
	'ListImports(".",".cpp")
	ListHeaders(".",".h")
End

