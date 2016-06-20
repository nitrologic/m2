#Import "<std>"
#Import "<mojo>"

#Import "writegif3.c"

Using std..

Extern

Class GIFStream
End

Function GIFWrite:Int(path:CString, stream:GIFStream, optimize:Int)

Public

Class GifStream Extends GIFStream
End


Function SaveGIF(pix:Pixmap,filename:String)
	
	GIFWrite(filename,Null,0)

End Function

Function Main()
	Print "gif tool"

	Local pix:=New Pixmap(256,256)

	SaveGIF(pix,"walk32.gif")

End

