namespace socket

#import "posix.monkey2"
#import "<arpa/inet.h>"

' #import "<linux/i2c-dev.h>"

Extern

function htons:ushort(hostshort:UShort)

public

Const FIONBIO:=126
Const MSG_DONTWAIT:=$40

Class Socket
	Field fd:int
	field buf:=new ubyte[65536]
	
	Method New(descriptor:Int)
		fd=descriptor
' make non blocking
'		Local iMode:Int=1
'		posix.ioctl(fd, FIONBIO, &iMode);		
	End
	
	Method Listen()
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
		Local flags:=MSG_DONTWAIT
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
nitroSocket* nitroSocket::connect(const char *host,int port){

	int result;

	int domain=AF_INET;
	int type=SOCK_STREAM;
	int protocol=0;

	int fd = socket(domain, type, protocol);	
	printf("nitroSocket::socket fd=%d\n",fd);

	hostent *server = gethostbyname(host);
	if (server == NULL) {
		printf("nitroSOcket::ERROR, no such host\n");
		return 0;
	}
	
	unsigned char *ip32=(unsigned char *)server->h_addr;	
	printf("gethostbyname %d.%d.%d.%d len=%d\n",
		ip32[0],ip32[1],ip32[2],ip32[3], 
		server->h_length);
	fflush(stdout);

	sockaddr_in address={0};
	address.sin_family=AF_INET;
	address.sin_port=htons(port);
	memcpy( &address.sin_addr.s_addr, ip32, server->h_length);

printf("connecting..\n");
	fflush(stdout);

	result=::connect(fd,(sockaddr *)&address,sizeof(sockaddr_in));

printf("connected result=%d\n",result);
	fflush(stdout);

	if (posixError(result)) return 0;

	printf("nitroSocket::socket connected\n");		
	return new nitroSocket(fd);
}

nitroSocket *nitroSocket::open(int port, int flags){
	int domain=AF_INET;
	int type=SOCK_STREAM;
	int protocol=0;
	int fd = socket(domain, type, protocol);	
	printf("nitroSocket::socket fd=%d\n",fd);
	if(fd<0){
		return 0;
	}
	int reuse=1;
	int setoptResult=setsockopt(fd,SOL_SOCKET,SO_REUSEADDR,&reuse,sizeof(reuse));
	sockaddr_in address={0};
	address.sin_family = AF_INET;
	address.sin_addr.s_addr = htonl(INADDR_ANY);
	address.sin_port = htons(port);
	// todo: make safe array access
	int result = bind(fd,(sockaddr *)&address,sizeof(sockaddr_in));
	if (posixError(result)) return 0;
	return new nitroSocket(fd);
}



int nitroSocket::listen(Connection *service)
{
	int backlog=32;
	int result=::listen(fd,backlog);
	if (posixError(result)) return 0;
	
	bool listening=true;

	while(listening){

		printf("nitroSocket::listening...\n");

		sockaddr_in from={0};
		socklen_t len=sizeof(sockaddr_in);
	
		int fd2;
		fd2=accept(fd,(sockaddr *) &from,&len);

		if(fd2<0){
			printf("nitroSocket::accept fd2=%d\n",fd2);
			listening=false;
			continue;
		}

		nitroSocket *link=new nitroSocket(fd2);
		if(service){
			std::string address(inet_ntoa(from.sin_addr));
			service->onConnect(link,address);
		}
	}
	
}

nitroSocket::nitroSocket(int descriptor){
	fd=descriptor;
}

nitroSocket::~nitroSocket(){
	if(fd){
		close();
	}
}

const char *nitroSocket::read(){
	buffer[0]=0;
	
	ssize_t count=::recv(fd,buffer,BufferSize-1,0);	//MSG_DONTWAIT
	if(count>0){
		buffer[count]=0;
//		printf("nitroSocket::read count=%d\n",count);
	}else{
		if (count==0){
			printf("nitroSocket::read is end of stream\n",count);				
			return 0;			
		}
		if (count==-1){
			printf("nitroSocket::read has error\n",count);
			return 0;			
		}
	}
	return buffer;
}

int nitroSocket::write(const char *bytes,int count){
	// todo: make me safe	
	if (count==0){
		count=strlen(bytes);
	}
	size_t result=::write(fd,bytes,count);	
//	printf("nitroSocket::write count=%d result=%d\n",count,result);	
	return result;
}
	
void nitroSocket::close(){
	::close(fd);
	fd=0;
}


#rem

#include <sys/types.h>
#include <sys/socket.h>
//#include <sys/unistd.h>
#include <unistd.h>
#include <netinet/in.h>
#include <netdb.h>
#include <errno.h>
#include <sys/ioctl.h>
#include <sys/uio.h>

// on nonzero result input prints string version of errno

bool posixError(int result){
	if(result==0) return false;
	result=errno;
	const char *err=strerror(errno);
	printf("nitroSocket::posix_error(%d) %s\n",errno,err);
	return true;
}

float peekf(void *p){
	// convert from big-endian (network btye order)
	const uint32_t i = ntohl(*((uint32_t *) p));
	return *((float *) (&i));
}


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


nitroSocket* nitroSocket::connect(const char *host,int port){

	int result;

	int domain=AF_INET;
	int type=SOCK_STREAM;
	int protocol=0;

	int fd = socket(domain, type, protocol);	
	printf("nitroSocket::socket fd=%d\n",fd);

	hostent *server = gethostbyname(host);
	if (server == NULL) {
		printf("nitroSOcket::ERROR, no such host\n");
		return 0;
	}
	
	unsigned char *ip32=(unsigned char *)server->h_addr;	
	printf("gethostbyname %d.%d.%d.%d len=%d\n",
		ip32[0],ip32[1],ip32[2],ip32[3], 
		server->h_length);
	fflush(stdout);

	sockaddr_in address={0};
	address.sin_family=AF_INET;
	address.sin_port=htons(port);
	memcpy( &address.sin_addr.s_addr, ip32, server->h_length);

printf("connecting..\n");
	fflush(stdout);

	result=::connect(fd,(sockaddr *)&address,sizeof(sockaddr_in));

printf("connected result=%d\n",result);
	fflush(stdout);

	if (posixError(result)) return 0;

	printf("nitroSocket::socket connected\n");		
	return new nitroSocket(fd);
}

nitroSocket *nitroSocket::open(int port, int flags){
	int domain=AF_INET;
	int type=SOCK_STREAM;
	int protocol=0;
	int fd = socket(domain, type, protocol);	
	printf("nitroSocket::socket fd=%d\n",fd);
	if(fd<0){
		return 0;
	}
	int reuse=1;
	int setoptResult=setsockopt(fd,SOL_SOCKET,SO_REUSEADDR,&reuse,sizeof(reuse));
	sockaddr_in address={0};
	address.sin_family = AF_INET;
	address.sin_addr.s_addr = htonl(INADDR_ANY);
	address.sin_port = htons(port);
	// todo: make safe array access
	int result = bind(fd,(sockaddr *)&address,sizeof(sockaddr_in));
	if (posixError(result)) return 0;
	return new nitroSocket(fd);
}

#include <arpa/inet.h>

int nitroSocket::listen(Connection *service)
{
	int backlog=32;
	int result=::listen(fd,backlog);
	if (posixError(result)) return 0;
	
	bool listening=true;

	while(listening){

		printf("nitroSocket::listening...\n");

		sockaddr_in from={0};
		socklen_t len=sizeof(sockaddr_in);
	
		int fd2;
		fd2=accept(fd,(sockaddr *) &from,&len);

		if(fd2<0){
			printf("nitroSocket::accept fd2=%d\n",fd2);
			listening=false;
			continue;
		}

		nitroSocket *link=new nitroSocket(fd2);
		if(service){
			std::string address(inet_ntoa(from.sin_addr));
			service->onConnect(link,address);
		}
	}
	
}

nitroSocket::nitroSocket(int descriptor){
	fd=descriptor;
// make non blocking
//	int iMode=1;
//	ioctl(fd, FIONBIO, &iMode);		
}

nitroSocket::~nitroSocket(){
	if(fd){
		close();
	}
}

const char *nitroSocket::read(){
	buffer[0]=0;
	
	ssize_t count=::recv(fd,buffer,BufferSize-1,0);	//MSG_DONTWAIT
	if(count>0){
		buffer[count]=0;
//		printf("nitroSocket::read count=%d\n",count);
	}else{
		if (count==0){
			printf("nitroSocket::read is end of stream\n",count);				
			return 0;			
		}
		if (count==-1){
			printf("nitroSocket::read has error\n",count);
			return 0;			
		}
	}
	return buffer;
}

int nitroSocket::write(const char *bytes,int count){
	// todo: make me safe	
	if (count==0){
		count=strlen(bytes);
	}
	size_t result=::write(fd,bytes,count);	
//	printf("nitroSocket::write count=%d result=%d\n",count,result);	
	return result;
}
	
void nitroSocket::close(){
	::close(fd);
	fd=0;
}

#endif

#end