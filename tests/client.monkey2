#Import "<std>"

function Main()
	Local d:=New std.memory.DataBuffer(1024)
	Local s:=std.socket.Socket.Connect("255.255.255.255",8000,std.socket.SocketType.Datagram)
'	Local s:=std.socket.Socket.Connect("192.168.1.255",8000,std.socket.SocketType.Datagram)
'	s.SetOption("SO_BROADCAST",1)
	Local n:=s.Send(d.Data,d.Length)
	Print n
End
