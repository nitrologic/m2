Namespace nitro

#If __HOSTOS__="windows"

#Import "nitro.h"
#Import "nitroWindows.cpp"

Extern

Function EnableHighDPI()

#Endif

public 

function HighDPI()
    EnableHighDPI()
end
