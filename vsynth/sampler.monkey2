#Import "<std>"
#Import "<sdl2>"
#Import "<sdl2-mixer>"

Using std..
Using sdl2..
	
const RIFF:=$46464952      ' "RIFF" 
const WAVE:=$45564157      ' "WAVE" 
const FORM:=$4d524f46      ' "FORM" 
const OGGS:=$5367674f      ' "OggS" 
const CREA:=$61657243      ' "Crea" 
const FLAC:=$43614C66      ' "fLaC" 

Const AudioFrequency:=44100

Class Sample
	Field sample:UByte Ptr
	field length:UInt

	Method New(path:String)	
		Local spec1:SDL_AudioSpec
		Local spec:SDL_AudioSpec Ptr
				
		Local data:=DataBuffer.Load( path )
		If Not data Return		
		Print data.Length
				
		Local rwops:=SDL_RWFromMem( data.Data,data.Length )
		If rwops Print "rwops"
	
		Select data.PeekInt(0)
			Case RIFF,WAVE
				spec=SDL_LoadWAV_RW(rwops,0,varptr spec1,varptr sample,varptr length)		
			Case FORM
				spec=Mix_LoadAIFF_RW(rwops,0,varptr spec1,varptr sample,varptr length)			
'			Case OGGS
'				spec=Mix_LoadOGG_RW(rwops,0,varptr spec1,varptr sample,varptr length)			
		End
		
		If spec
			Print length
			Print spec->freq+" hz"
			Print Spec(spec->format)
			Print spec->channels+" channels"
		endif
	End
	
	Function Spec:String(format:Short)
		Local spec:=""
		If format<0 spec=spec+"signed"
		If format&$1000 spec=spec+" bigendian"
		If format&$100 spec=spec+" float"
		spec=spec+" "+(format&$ff)
		Return spec
	End
		
End


#rem
    ++-----------------------sample is signed if set
    ||
    ||       ++-----------sample is bigendian if set
    ||       ||
    ||       ||          ++---sample is float if set
    ||       ||          ||
    ||       ||          || +---sample bit size---+
    ||       ||          || |                     |
    15 14 13 12 11 10 09 08 07 06 05 04 03 02 01 00

Struct SDL_AudioSpec2
	Field freq:Int
	Field format:SDL_AudioFormat
	Field channels:Byte
	Field silence:Byte
	Field samples:Short
	Field padding:Short
	Field size:Int
	Field callback:SDL_AudioCallback
	Field userdata:Void Ptr
end

#end


Function Main()
	Mix_Init( 0 )
	Mix_OpenAudio( 44100,MIX_DEFAULT_FORMAT,2,1024 )
'	Local sam:=New Sample("/Users/simon/m2/vsynth/assets/bang.wav")	
'	Local sam:=New Sample("/Users/simon/m2/vsynth/assets/bassdrum1.wav")	
	Local sam:=New Sample("/Users/simon/Music/MainStage/arpstein 14-04-04 17.50.06.aiff")
End
