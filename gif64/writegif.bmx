Strict

Import "wrgif.c"

Extern "C"
Function writegif2(file,lines,samples,pixels:Byte Ptr,colors:Byte Ptr,ctrl:Byte Ptr,ctrllength)
End Extern

' rgb->palette
' create palette from best fit or caller supplied
' match odd pixels to closest
' match even to closest+neighbor error bias+dither

Function SavePixmapGIF(pixmap:TPixmap,filename$)
	Local pix:TPixmap
	Local colors:Byte[768]
	Local ctrl:Byte[7]
	
	ctrl[0]=$21
	ctrl[1]=$f9	'startblock
	ctrl[2]=4	'n-size of block
	ctrl[3]=1	'flags 1=alphabackground'
	ctrl[4]=0	'delay
	ctrl[5]=0	'background color
	ctrl[6]=0	'end of blocks

	For Local i=0 To 255
		colors[i*3]=i;colors[i*3+1]=i;colors[i*3+2]=i
	Next
	pix=ConvertPixmap(pixmap,PF_A8)

	Local f=fopen_(filename,"wb")
	If Not f Return
	writegif2(f,pix.height,pix.pitch,PixmapPixelPtr(pix),colors,ctrl,7)
	fclose_(f)
End Function

Local pix:TPixmap

pix=LoadPixmap("walk32.png")

SavePixmapGif pix,"walk32.gif"


'	pix=ConvertPixmap(pixmap,PF_I8)
'	writegif(f,pix.height,pix.pitch,PixmapPixelPtr(pix))
