namespace socket

#import "posix.monkey2"
#import "<arpa/inet.h>"

Extern

function htons:ushort(hostshort:UShort)
function htonl:uint(hostlong:UInt)

public

Const FIONBIO:=126
Const MSG_DONTWAIT:=$40
Const SOL_SOCKET:=$ffff
Const SO_REUSEADDR:=$4
Const INADDR_ANY:=0

Class Socket

	Field fd:int
	field buf:=new ubyte[65536]
	
	Method New(descriptor:Int)
		fd=descriptor
' make non blocking
'		Local iMode:Int=1
'		posix.ioctl(fd, FIONBIO, &iMode);		
	End
	
	Function Listen:Socket(port:Int)
		Local fd:=posix.socket(AF_INET,SOCK_STREAM,0)
		If fd=-1 
			Print "posix.socket create failure "+posix.ErrorString()
			Return Null
		Endif
		Local reuse:Int=1
		Local setoptResult:=posix.setsockopt(fd,SOL_SOCKET,SO_REUSEADDR,Varptr reuse,4)
		Local address:=New sockaddr_in
		address.sin_family = AF_INET
'		address.sin_addr = htonl(INADDR_ANY)
		address.sin_port = htons(port)
' make safe array access
		Local result:=posix.bind(fd,address,16)
		If result=-1
			Print "posix.bind error "+posix.ErrorString()
			Return null
		Endif

		Local backlog:=32
		result=posix.listen(fd,backlog)
		if result=-1
			Print "posix.listen error "+posix.ErrorString()
			Return Null	
		Endif

		return new Socket(fd)
	End
	
	Method Accept:Socket()
		Local from:=New sockaddr_in
		Local len:UInt=20
		Local flags:=0
		
		Local fd2:=posix.accept(fd,from,Varptr len)

		If fd2=-1
			Print "posix.accept error "+posix.ErrorString()
			Return Null	
		Endif
		
		Return New Socket(fd2)
	End
	
	Function Connect:Socket(host:String,port:Int)
			
		Local service:=String(port)
		Local hints:=New posix.addrinfo		
		local result:posix.addrinfo
'		hints.ai_family=AF_INET6
		hints.ai_socktype=SOCK_STREAM		
		Local res:=posix.getaddrinfo(host,service,hints,Varptr result)
		If res<>0
			Print "posix.getaddrinfo="+res+":"+posix.ErrorString()
			Return Null
		Endif

'		Local info:=result
'		While info
'			Print "flags,family,socktype,addrlen "+info.ai_flags+","+info.ai_family+","+info.ai_socktype+","+info.ai_addrlen
'			info=info.ai_next
'		Wend

		Local addrSize:=result.ai_addrlen
		Local family:=result.ai_family
		
		Local fd:Int
				
		Select family
			Case AF_INET6		
				fd=posix.socket(AF_INET6,SOCK_STREAM,0)
				If fd=-1 
					Print "posix.socket inet6 failure "+posix.ErrorString()
					Return Null
				Endif
			Case AF_INET
				fd=posix.socket(AF_INET,SOCK_STREAM,0)
				If fd=-1 
					Print "posix.socket inet failure "+posix.ErrorString()
					Return Null
				Endif
		End
	
		res=posix.connect(fd,result.ai_addr,addrSize)
		If res=-1
			Print "posix.connect failed "+posix.ErrorString()
			Return Null
		else
			Print "connected"
		endif
		
		posix.freeaddrinfo(result)

		Return New Socket(fd)		
	End

	Function Open:Socket(port:Int,flags:Int)
		Return Null
	End
	
	Method Read:String()
		Local buffer:=New char_t[1024]
		Local flags:=0'MSG_DONTWAIT
		Local n:=posix.recv(fd,buffer.Data,1024,flags)
		If n=-1
			Print "socket read error:"+posix.ErrorString()
			Return Null
		Endif
		Return String.FromCString(buffer.Data,n)
	End
	
	Method Write:Int(s:String)
		Local buffer:=New char_t[1024]
		s.ToCString(buffer.Data,1024)
		Local n:=posix.write(fd,buffer.Data,s.Length)
		If n=-1
			Print "socket write error:"+posix.ErrorString()		
		endif
		Return n
	End
	
	method Close()
		posix.close(fd)
		fd=0
	End
	
end


#rem

// thanks to http://www.microhowto.info/howto/listen_for_and_receive_udp_datagrams_in_c.html

int nitroSocket::testOSCIn(){
	const char *host=0;
	const char *port="7000";

	addrinfo hints={0};
	hints.ai_family=AF_UNSPEC;
	hints.ai_socktype=SOCK_DGRAM;
	hints.ai_protocol=0;
	hints.ai_flags=AI_PASSIVE|AI_ADDRCONFIG;

	addrinfo* res=0;
	int err=getaddrinfo(host,port,&hints,&res);
	if (err!=0) {
		printf("failed to resolve local socket address (err=%d)\n",err);
		return -1;
	}


	int fd=socket(res->ai_family,res->ai_socktype,res->ai_protocol);
	if (fd==-1) {
		printf("%s\n",strerror(errno));
		return -2;
	}
	
	if (bind(fd,res->ai_addr,res->ai_addrlen)==-1) {
		printf("%s\n",strerror(errno));
		return -3;
	}
	
	freeaddrinfo(res);

	char buffer[549];
	
	struct sockaddr_storage src_addr;
	socklen_t src_addr_len=sizeof(src_addr);

	while(true){
		ssize_t count=recvfrom(fd,buffer,sizeof(buffer),0,(struct sockaddr*)&src_addr,&src_addr_len);
		if (count==-1) {
			printf("%s\n",strerror(errno));
		} else if (count==sizeof(buffer)) {
			printf("datagram too large for buffer: truncated\n");
		} else {
			processOSC(buffer,count);
		}
	}

}

int nitroSocket::testOSCOut(){

	const char *host="192.168.1.255";
//	const char *host="192.168.1.114";
	const char *port="7000";
	
//	char content[32];
	
	char content[]={"/1/rotary1\0\0,f\0\0\0\0\0\0"};
	
	addrinfo hints={0};
	hints.ai_family=AF_UNSPEC;
	hints.ai_socktype=SOCK_DGRAM;
	hints.ai_protocol=0;
	hints.ai_flags=AI_ADDRCONFIG;
	
	addrinfo* res=0;
	int err=getaddrinfo(host,port,&hints,&res);
	if (err!=0) {
		printf("failed to resolve remote socket address (err=%d)\n",err);
		return -1;
	}
	
	int fd=socket(res->ai_family,res->ai_socktype,res->ai_protocol);
	if (fd==-1) {
		printf("%s\n",strerror(errno));
		return -2;
	}
	
	
	int broadcast=1;
	if (setsockopt(fd,SOL_SOCKET,SO_BROADCAST, &broadcast,sizeof(broadcast))==-1) {
		printf("%s\n",strerror(errno));
		return -3;
	}
	
	
	if (sendto(fd,content,sizeof(content),0, res->ai_addr,res->ai_addrlen)==-1) {
		printf("%s\n",strerror(errno));
		return -3;
	}

	return 0;
}

#end