#ifndef NITROWINDOWS
#define NITROWINDOWS

#define WIN32_LEAN_AND_MEAN 1

#include <windows.h>

#include "nitro.h"

typedef HRESULT (WINAPI *SetInt)(int value);

void EnableHighDPI(){
    HMODULE shCore=LoadLibraryA("SHCORE.DLL");
    if(shCore){
        SetInt setProcessDpiAwareness=(SetInt)GetProcAddress(shCore,"SetProcessDpiAwareness");
        if(setProcessDpiAwareness){
            HRESULT result = setProcessDpiAwareness(2);
        }
        FreeLibrary(shCore);
    }
}

#endif
