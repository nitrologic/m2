namespace posix

#import "<stdio.h>"
#import "<fcntl.h>"
#import "<unistd.h>"
#import "<sys/ioctl.h>"
#import "<sys/types.h>"
#import "<sys/socket.h>"
#import "<sys/mman.h>"
#import "<netdb.h>"
#import "<errno.h>"
#import "<arpa/inet.h>"

#import "<libc>"

Using libc

extern 

Global errno:Int

Global AF_UNSPEC:Int
Global AF_INET:Int
Global AF_INET6:int
Global PF_INET6:int
Global SOCK_STREAM:int
Global SOCK_DGRAM:int
global INADDR_ANY:Int

Global FIONBIO:Int	'=126
Global MSG_DONTWAIT:Int	'=$40
global SOL_SOCKET:Int	':=$ffff
global SO_REUSEADDR:Int	':=$4

Global AI_PASSIVE:Int
Global AI_ADDRCONFIG:Int

Global PROT_WRITE:int
Global MAP_SHARED:Int

Global FBIOGET_FSCREENINFO:Int
Global FBIOGET_VSCREENINFO:Int

Class sockaddr Extends Void
	Field sin_family:Short
	Field sin_port:UShort
	Field sin_addr:ULong
	Field pad0:Int
	Field pad1:Int
End

Class sockaddr_in Extends sockaddr
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
Function bind:Int(fd:Int,addr:sockaddr,addrlen:Int)
Function setsockopt:Int(fd:Int,level:Int,name:Int,val:Void Ptr,size:Int)
Function accept:Int(fd:Int,addr:sockaddr,addrlen:uInt Ptr)
Function recv:Int(fd:int,buffer:Void ptr,BufferSize:int,flags:Int)
Function send:Int(fd:int,buffer:Void ptr,BufferSize:int,flags:Int)
Function recvfrom:Int(fd:Int,buffer:Void ptr,BufferSize:int,flags:Int,addr:sockaddr,addrlen:UInt Ptr)
Function getaddrinfo:Int(hostname:CString, servername:CString, hints:addrinfo, res:addrinfo ptr)
Function freeaddrinfo(ai:addrinfo)

Function socket:Int(domain:Int,socketType:Int,socketProtocol:Int)

function htons:ushort(hostshort:UShort)
function htonl:uint(hostlong:UInt)

function mmap:void ptr(address:void ptr,len:int,prot:Int,flags:int,fd:int,offset:int)
function munmap(memory:void ptr,len:int)

Function strerror:char_t Ptr(error:Int)

Public

Function ErrorString:String()
	Local result:=errno
	Local s:=strerror(errno)
	Return String.FromCString(s)
end
