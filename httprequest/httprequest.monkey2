' native win32 http requests

#Import "<libc>"
#Import "<std>"

#Import "<windows.h>"
#Import "<wininet.h>"

#Import "<libwininet.a>"

Extern

Alias INTERNET_PORT:Int
Alias DWORD:UInt
Alias LPVOID:Void Ptr

Global INTERNET_OPEN_TYPE_DIRECT:DWORD
Global INTERNET_OPEN_TYPE_PRECONFIG:DWORD
Global INTERNET_OPEN_TYPE_PRECONFIG_WITH_NO_AUTOPROXY:DWORD
Global INTERNET_OPEN_TYPE_PROXY:DWORD

Global INTERNET_SERVICE_FTP:DWORD
Global INTERNET_SERVICE_GOPHER:DWORD
Global INTERNET_SERVICE_HTTP:DWORD

Global HTTP_QUERY_ACCEPT:DWORD

Struct HINTERNET
End

Struct DWORD_PTR
End

Struct LPCTSTR
End

Struct LPDWORD
End

Function InternetOpen:HINTERNET(agent:CString, accessType:DWORD, proxyName:CString, proxyBypass:CString, flags:DWORD)
Function InternetCloseHandle:Bool(internet:HINTERNET)

Function InternetConnect:HINTERNET(internet:HINTERNET, server:CString, port:int, username:CString, password:CString, service:DWORD, flags:int, context:DWORD_PTR)
Function InternetReadFile:Bool(file:HINTERNET,buffer:UByte Ptr, size:UInt, bytesRead:LPDWORD)

Function InternetWriteFile()

Function HttpOpenRequest:HINTERNET(http:HINTERNET, verb:CString, objectName:CString, version:CString, referer:CString, types:LPCTSTR Ptr, flags:DWORD, context:DWORD_PTR)
Function HttpSendRequest:Bool(request:HINTERNET, headers:CString, headersLength:DWORD, optional:LPVOID, optionalLength:DWORD)

Function HttpQueryInfo:Bool(request:HINTERNET, infoLevel:DWORD, buffer:UByte ptr, bufferLength:UInt Ptr, index:DWORD)

Function HttpEndRequest()

Public

Function Main()

	Local context:DWORD_PTR
	Local acceptTypes:LPCTSTR
	Local option:LPVOID
	
	Local host:String="wasted.nz"
'	Local host:String="google.com"
	Local page:String="/"

	Local internet:=InternetOpen("monkey2-httprequest/1.1.0.5", INTERNET_OPEN_TYPE_DIRECT, "", "", Null)
	If internet=Null Print("InternetOpen Failed")	

	Local http:=InternetConnect(internet, host, 80, "", "", INTERNET_SERVICE_HTTP, 0, context)
	If http=Null Print("InternetConnect Failed")

	Local request:=HttpOpenRequest(http, "GET", page, "HTTP/1.1", "", Varptr acceptTypes, 0, context)
	If request=Null Print("HttpOpenRequest Failed")
	
	Local result1:=HttpSendRequest(request, "", 0, option, 0)
	Print "result1="+(result1?"True"Else"False")
		
	Local data:=New std.memory.DataBuffer(500)
	Local length:UInt=data.Length

	Local bytesRead:LPDWORD
	Local result2:Bool=InternetReadFile(request,data.Data,data.Length,bytesRead)
	Print "result2="+(result2?"True"Else"False")
	
	Local raw:=data.Data
	For Local i:=0 Until 12
		Print raw[i]
	Next
	
	Print String.FromCString(data.Data,24)
		
	InternetCloseHandle(http)
	InternetCloseHandle(internet)

End
