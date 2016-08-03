namespace posix

#import "<unistd.h>"
#import "<sys/ioctl.h>"
#import "<sys/types.h>"
#import "<sys/socket.h>"
#import "<netdb.h>"
#import "<errno.h>"
#import "<libc>"

Using libc

'#if __HOSTOS__="pi"

extern 

Class sockaddr Extends Void
End

Class sockaddr_in Extends sockaddr
	Field sin_family:Short
	Field sin_port:UShort
	Field sin_addr:ULong
	Field pad0:Int
	Field pad1:Int
End

Class sockaddr_in6 Extends sockaddr
	Field sin6_family:Ushort
	Field sin6_port:UShort
	Field sin6_flowinfo:UInt
	Field sin6_addr:int
	Field sin6_addr1:Int
	Field sin6_addr2:Int
	Field sin6_addr3:Int
	Field sin6_scopeid:Int
End

Class addrinfo Extends Void
	Field ai_flags:Int ' input flags
	Field ai_family:Int ' protocol family for socket
	Field ai_socktype:Int	' socket type
	Field ai_protocol:Int ' protocol for socket
	Field ai_addrlen:Int	' length of socket-address
	Field ai_addr:sockaddr ' socket-address for socket
	Field ai_canonname:char_t ptr ' canonical name for service location
	Field ai_next:addrinfo ' pointer to next in list
end

Function open:Int( path:CString,mode:Int )

function ioctl:int( fd:int,request:uint,memory:void ptr)
function ioctl:int( fd:int,request:uint,value:int)

function read:int( fd:int,buffer:void ptr,count:uint)
function write:int( fd:int,buffer:void ptr,count:uint)

Function close:Int( fd:int)

Function connect:int(sock:Int,addr:sockaddr,addrlen:Int)

Function listen:int(fd:Int,backlog:Int)
Function accept:Int(addr:sockaddr_in ptr,addrlen:Int Ptr,flags:int)
Function recv:Int(fd:int,buffer:Void ptr,BufferSize:int,flags:Int)
Function send:Int(fd:int,buffer:Void ptr,BufferSize:int,flags:Int)

Function getaddrinfo:Int(hostname:CString, servername:CString, hints:addrinfo, res:addrinfo ptr)
Function freeaddrinfo(ai:addrinfo)

Function socket:Int(domain:Int,socketType:Int,socketProtocol:Int)

Global errno:Int
Global AF_INET:Int
Global AF_INET6:int
Global PF_INET6:int
Global SOCK_STREAM:int

Function strerror:char_t Ptr(error:Int)

Public

Function ErrorString:String()
	Local result:=errno
	Local s:=strerror(errno)
	Return String.FromCString(s)
end


'#endif
