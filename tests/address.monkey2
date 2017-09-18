#Import "<std>"
' address issue server
Function Main()
	Print "1"
	Local s:=std.socket.Socket.Bind("0.0.0.0",8000)
	Print "2"
	Local d:=New std.memory.DataBuffer(8192)
	Local a:=New std.socket.SocketAddress
	While True
		Local n:=s.ReceiveFrom( d.Data,8192,a )
		Print "3 n="+n
		If n=-1 exit
		Print "4"	
		Print "s.Address="+a
		Print "5"
	Wend
End
