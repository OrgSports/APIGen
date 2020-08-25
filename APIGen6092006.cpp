// ****************************************************************************
// Attachmate APIGen EHLLAPI C++ Application
 
// This file is source code for a freestanding EHLLAPI program written in C++
// that is ready to build and run.  To build and run it please do the following:
//  1. Install any version of Extra! after 6.1.  Create a new session via the
//     file/new session wizard and save it.
//  2. Associate a HLLAPI session short name to the new session within the
//     Advanced property page of the Options/Global settings menu.
//  3. Copy the acs3ehap.h file to the same folder where this source file will be built.
//  4) Open Visual C++ or, if it's already running, close any open project. Open this file,
//      and then select the Build\Compile menu item.  Accept the prompt to start a new
//      project and the compiler will generate your application.
// 
//   Generated:   Fri Jun 09 10:16:26 2006

//
// ****************************************************************************
#include <windows.h>
#include <stdio.h>
#include "acs3ehap.h"

// prototype the EHLLAPI entry point
void (WINAPI *EHLLAPI)(LPINT, LPSTR, LPINT, LPINT);

// load the EHLLAPI dll and establish the entry point
void LoadHllapi()
{
     HMODULE dllHandle = LoadLibrary("ehlapi32.dll");
     FARPROC pProcAddress;
     pProcAddress = GetProcAddress(dllHandle, "HLLAPI" );
     EHLLAPI = (void (WINAPI *)(LPINT, LPSTR, LPINT, LPINT)) pProcAddress;
}

int main(int argc, CHAR* argv[])
{
     char cSession;
     int nFunc;
     int nLength;
     int nRetCode;
     char szString[1000];
     char* pszString = szString;

     LoadHllapi();

     //Function: 1 Connect PS
     nFunc = 1;
     cSession = 'a';
     nLength = 1;
     nRetCode = 0;
 
     EHLLAPI( &nFunc, &cSession, &nLength, &nRetCode );
 
     //Function: 3 Send Key
     nFunc = 3;
     strcpy( pszString, "vmuser11vms11@E" );
     nLength = strlen(pszString);
     nRetCode = 0;
 
     EHLLAPI( &nFunc, pszString, &nLength, &nRetCode );
 
     //Function: 3 Send Key
     nFunc = 3;
     strcpy( pszString, "filel@E" );
     nLength = strlen(pszString);
     nRetCode = 0;
 
     EHLLAPI( &nFunc, pszString, &nLength, &nRetCode );
 
 
     //Function: 2 Disconnect PS
     nFunc = 2;
     cSession = 'a';
     nLength = 1;
     nRetCode = 0;
 
     EHLLAPI( &nFunc, &cSession, &nLength, &nRetCode );
 
 
     return 1;
 
}
 
