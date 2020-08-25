// ****************************************************************************
// Attachmate APIGen WHLLAPI C++ Application
//
// This file is a freestanding WHLLAPI program written in C++
// that is ready to build and run.  To build and run it please do the following:
//  1. Install any version of EXTRA! after 6.1.  Create a new session via the
//     file/new session wizard and save it.
//  2. Associate a HLLAPI session short name to the new session within the
//     Advanced property page of the Options/Global settings menu.
//  3. Copy the whlapi32.h file to the same folder where this source file will be built.
//  4) Open Visual C++ or, if it's already running, close any open project. Open this file,
//      and then select the Build\Compile menu item.  Accept the prompt to start a new
//      project and the compiler will generate your application.
// 
//
//   Generated:   Mon Jun 12 06:57:33 2006

//
// ****************************************************************************
#include <windows.h>
#include <stdio.h>
#include "whllapi.h"
 
// prototype the WHLLAPI entry points
void (WINAPI *WHLLAPI)(LPWORD, LPSTR, LPWORD, LPWORD);
int (WINAPI *WHLStartup)(WORD, LPWHLLAPIDATA);
BOOL (WINAPI *WHLCleanup)(void);

// load the WHLLAPI dll and establish the entry point
void LoadHllapi()
{
     HMODULE dllHandle = LoadLibrary("whlapi32.dll");
     FARPROC pProcAddress;
     pProcAddress = GetProcAddress(dllHandle,"WinHLLAPI");
     WHLLAPI = ( void (WINAPI *)(LPWORD, LPSTR, LPWORD, LPWORD) ) pProcAddress;
 
     FARPROC pStartupProcAddress;
     pStartupProcAddress = GetProcAddress(dllHandle,"WinHLLAPIStartup");
     WHLStartup = ( int (WINAPI *)(WORD, LPWHLLAPIDATA) ) pStartupProcAddress;
 
     FARPROC pCleanupProcAddress;
     pCleanupProcAddress = GetProcAddress(dllHandle,"WinHLLAPICleanup");
     WHLCleanup = ( BOOL (WINAPI *)(void) ) pCleanupProcAddress;
}
 
int main(int argc, CHAR* argv[])
{
     char cSession;
     WORD wFunc;
     WORD wLength;
     WORD wRetCode;
     char szString[1000];
     char* pszString = szString;

     LoadHllapi();

     //Function: 1 Connect
     wFunc = 1;
     cSession = 'a';
     wLength = 1;
     wRetCode = 0;
 
     WHLLAPI( &wFunc, &cSession, &wLength, &wRetCode );
 
     //Function: 3 SendKeys
     wFunc = 3;
     strcpy( szString, "vmuser11vms11@E" );
     wLength = strlen(szString);
     wRetCode = 0;
 
     WHLLAPI( &wFunc, pszString, &wLength, &wRetCode );
 
     //Function: 3 SendKeys
     wFunc = 3;
     strcpy( szString, "filel@E" );
     wLength = strlen(szString);
     wRetCode = 0;
 
     WHLLAPI( &wFunc, pszString, &wLength, &wRetCode );
 
     //Function: 2 Disconnect
     wFunc = 2;
     cSession = 'a';
     wLength = 1;
     wRetCode = 0;
 
     WHLLAPI( &wFunc, &cSession, &wLength, &wRetCode );
 
 
     WHLCleanup();
 
     return 1;
 
}
 
