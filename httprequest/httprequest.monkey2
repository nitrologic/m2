' native win32 http requests

#Import "<libc>"
#Import "<windows.h>"
#Import "<wininet.h>"

#Import "<libwininet.a>"

Extern

Alias LPVOID:Void Ptr
Alias LPCTSTR:CString
Alias LPCWSTR:WString
Alias HMENU:Int
Alias DWORD:Int

Function HttpOpenRequest()
Function HttpSendRequest()
Function HttpQueryInfo()
Function HttpEndRequest()
Function InternetWriteFile()

Public

Function Main()
End
