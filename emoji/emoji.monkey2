' emojione
' (c) 2018 mojolabs
' All rights reserved

#Import "applet"
#Import "assets/emojione/"
#Import "assets/fonts/"

Using std..
Using mojo..
Using sdl2..

Const Glyphs:="ABCČĆDĐEFGHIJKLMNOPQRSŠTUVWXYZŽabcčćdđefghijklmnopqrsštuvwxyzžАБВГҐДЂЕЁЄЖЗЅИІЇЙЈКЛЉМНЊОПРСТЋУЎФХЦЧЏШЩЪЫЬЭЮЯабвгґдђеёєжзѕиіїйјклљмнњопрстћуўфхцчџшщъыьэюяΑΒΓΔΕΖΗΘΙΚΛΜΝΞΟΠΡΣΤΥΦΧΨΩαβγδεζηθικλμνξοπρστυφχψωάΆέΈέΉίϊΐΊόΌύΰϋΎΫΏĂÂÊÔƠƯăâêôơư1234567890‘?’“!”(%)[#]{@}/&\<-+÷×=>®©$€£¥¢:;,.*"

Global AppletName:="emoji"
Global AppletAuthor:="nitrologic"

Const Monkey:=$1f412
Const Hash:=$23

Class Emoji
	
	Field image:Image
	
	Method New(id:Int)
		Local hex:=std.stringio.Hex(id).ToLower()
		If hex.Length<4 hex=("0000"+hex).Right(4)
		image=Image.Load("asset::"+hex+".png")
		image.Handle=New Vec2f(0.5,0.5)
	End
	
	Field scale:=0.5
	Method Draw(canvas:Canvas,x:Int,y:Int,rot:Float)
		Local scalex:=scale*math.Cos(rot)
		canvas.DrawImage(image,x,y,0,scalex,scale)
	End
	
End

Alias Emojis:Emoji[]

Class EmojiGrid
	Field width:Int
	Field height:Int
	Field grid:Emoji[]
	Field emojis:Emojis
	
	Method Plot(x:Int,y:Int,code:Int)
		grid[y*width+x]=emojis[code]
	End

	Method New(emos:Emojis,w:Int, h:Int)
		emojis=emos
		width=w
		height=h
		grid=New Emoji[w*h]
		For Local x:=0 Until width
			Plot(x,0,Hash)
		Next
	End

	Field rot:=0.0
	Field cx:=80
	Field cy:=80
	
	Method Draw(canvas:Canvas)
		
		canvas.DrawText("Emoji Rr",20,20)
		canvas.DrawText(Glyphs,20,120)

		rot+=0.02
		For Local y:=0 Until height
			For Local x:=0 Until width
				Local emoji:=grid[y*width+x]
				If emoji
					
					Local face:Emoji
					
					face=(rot Mod math.Pi*2) > math.Pi ? emojis[Monkey] Else emoji
					

					face.Draw(canvas,cx+x*32,cy+y*32,rot)
				Endif
			Next
		Next
	End

End

Class Memory Extends EmojiGrid
	
	Method New(emo:Emojis)
		Super.New(emo,5,5)
	End
		
End
	

Class EmojiApp Extends Applet

	Field roboto:Font
	
	Field emos:=New Emoji[65536*4]

	Field memory:Memory
	
' TDIL no monkey2 virtual invokes from super constructor
	
	Method emoji:Emoji(id:Int)
		Local emoji:=New Emoji(id)
		emos[id]=emoji
		Return emoji
	End
	
	Method New()
		Init()
	End
	
	Method OnCreate() Override
		emoji(Hash)
		emoji(Monkey)		
		memory=New Memory(emos)		
		roboto=Font.Load("asset::Roboto-Regular.ttf",96)
	End
	
	Method OnRender(canvas:Canvas) Override
		canvas.Font=roboto
		memory.Draw(canvas)
	End
	
End

Function Main()
	New AppInstance
	New EmojiApp
	App.Run()
End
