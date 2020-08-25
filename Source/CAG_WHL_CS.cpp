// Static Model
#include "stdafx.h"
#include "apigen.h"

#include "CAG_WHL_CS.h"

CAG_WHL_CS::CAG_WHL_CS()
{
	resetVariableFlags();	
}

CAG_WHL_CS::~CAG_WHL_CS()
{
	
}

void CAG_WHL_CS::declareVariable(AG_VARIABLE agVariable,
								 CStringArray* pcsaHeader,
								 bool* bValue)
{
	
}


void CAG_WHL_CS::generateHeader(CStringArray* pcsaHeader,
								CStringArray* pcsaBody)
{
	// output to Translator's output window
	CString csViewOutStuff;
	
	csViewOutStuff.Format( "// ****************************************************************************");
	pcsaHeader->Add(csViewOutStuff);
	
	csViewOutStuff.Format( "// **********  PSSSST!! This is currently C++ STUFF! *************************");
	pcsaHeader->Add(csViewOutStuff);
	
	csViewOutStuff.Format( "// *******************  It's yet to be translated to C# *************************");
	pcsaHeader->Add(csViewOutStuff);
	
	csViewOutStuff.Format( "// Attachmate APIGen WHLLAPI C# Application");
	pcsaHeader->Add(csViewOutStuff);
	
	csViewOutStuff.Format( "//" );
	pcsaHeader->Add(csViewOutStuff);
	
	csViewOutStuff.Format( "// This file is a freestanding WHLLAPI program written in C#");
	pcsaHeader->Add(csViewOutStuff);
	
	csViewOutStuff.Format( "// that is ready to build and run.  To build and run it please do the following:");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "//  1. Install any version of EXTRA! after 6.1.  Create a new session via the");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "//     file/new session wizard and save it.");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "//  2. Associate a HLLAPI session short name to the new session within the");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "//     Advanced property page of the Options/Global settings menu.");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "//  3. Copy the whlapi32.h file to the same folder where this source file will be built.");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "//  4) Open Visual C++ or, if it's already running, close any open project. Open this file,");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "//      and then select the Build\\Compile menu item.  Accept the prompt to start a new");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "//      project and the compiler will generate your application.");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "// ");
	pcsaHeader->Add(csViewOutStuff);
	
	time_t ltime;
	time( &ltime );
	
	csViewOutStuff.Format( "//");
	pcsaHeader->Add(csViewOutStuff);
	
	csViewOutStuff.Format( "//   Generated:   %s", ctime( &ltime ) );
	pcsaHeader->Add(csViewOutStuff);
	
	csViewOutStuff.Format( "//");
	pcsaHeader->Add(csViewOutStuff);
	
	csViewOutStuff.Format( "// ****************************************************************************");
	pcsaHeader->Add(csViewOutStuff);
	
	
	csViewOutStuff.Format( "#include <windows.h>");
	pcsaHeader->Add(csViewOutStuff);
	
	csViewOutStuff.Format( "#include <stdio.h>");
	pcsaHeader->Add(csViewOutStuff);
	
	csViewOutStuff.Format( "#include \"whllapi.h\"" );
	pcsaHeader->Add(csViewOutStuff);
	
	csViewOutStuff.Format( " " );
	pcsaHeader->Add(csViewOutStuff);
	
	csViewOutStuff.Format( "// prototype the WHLLAPI entry points");
	pcsaHeader->Add(csViewOutStuff);
	
	csViewOutStuff.Format( "void (WINAPI *WHLLAPI)(LPWORD, LPSTR, LPWORD, LPWORD);");
	pcsaHeader->Add(csViewOutStuff);
	
	csViewOutStuff.Format( "int (WINAPI *WHLStartup)(WORD, LPWHLLAPIDATA);");
	pcsaHeader->Add(csViewOutStuff);
	
	csViewOutStuff.Format( "BOOL (WINAPI *WHLCleanup)(void);");
	pcsaHeader->Add(csViewOutStuff);
	
	
	csViewOutStuff.Format( "" );
	pcsaHeader->Add(csViewOutStuff);
	
	csViewOutStuff.Format( "// load the WHLLAPI dll and establish the entry point");
	pcsaHeader->Add(csViewOutStuff);
	
	csViewOutStuff.Format( "void LoadHllapi()");
	pcsaHeader->Add(csViewOutStuff);
	
	csViewOutStuff.Format( "{");
	pcsaHeader->Add(csViewOutStuff);
	
	csViewOutStuff.Format( "     HMODULE dllHandle = LoadLibrary(\"whlapi32.dll\");");
	pcsaHeader->Add(csViewOutStuff);
	
	csViewOutStuff.Format( "     FARPROC pProcAddress;");
	pcsaHeader->Add(csViewOutStuff);
	
	csViewOutStuff.Format( "     pProcAddress = GetProcAddress(dllHandle,\"WinHLLAPI\");");
	pcsaHeader->Add(csViewOutStuff);
	
	csViewOutStuff.Format( "     WHLLAPI = ( void (WINAPI *)(LPWORD, LPSTR, LPWORD, LPWORD) ) pProcAddress;");
	pcsaHeader->Add(csViewOutStuff);
	
	csViewOutStuff.Format( " ");
	pcsaHeader->Add(csViewOutStuff);
	
	csViewOutStuff.Format( "     FARPROC pStartupProcAddress;");
	pcsaHeader->Add(csViewOutStuff);
	
	csViewOutStuff.Format( "     pStartupProcAddress = GetProcAddress(dllHandle,\"WinHLLAPIStartup\");");
	pcsaHeader->Add(csViewOutStuff);
	
	csViewOutStuff.Format( "     WHLStartup = ( int (WINAPI *)(WORD, LPWHLLAPIDATA) ) pStartupProcAddress;");
	pcsaHeader->Add(csViewOutStuff);
	
	csViewOutStuff.Format( " ");
	pcsaHeader->Add(csViewOutStuff);
	
	csViewOutStuff.Format( "     FARPROC pCleanupProcAddress;");
	pcsaHeader->Add(csViewOutStuff);
	
	csViewOutStuff.Format( "     pCleanupProcAddress = GetProcAddress(dllHandle,\"WinHLLAPICleanup\");");
	pcsaHeader->Add(csViewOutStuff);
	
	csViewOutStuff.Format( "     WHLCleanup = ( BOOL (WINAPI *)(void) ) pCleanupProcAddress;");
	pcsaHeader->Add(csViewOutStuff);
	
	csViewOutStuff.Format( "}");
	pcsaHeader->Add(csViewOutStuff);
	
	csViewOutStuff.Format( " " );
	pcsaHeader->Add(csViewOutStuff);
	
	csViewOutStuff.Format( "int main(int argc, CHAR* argv[])");
	pcsaHeader->Add(csViewOutStuff);
	
	csViewOutStuff.Format( "{");
	pcsaHeader->Add(csViewOutStuff);
	
	csViewOutStuff.Format( "     char cSession;");
	pcsaHeader->Add(csViewOutStuff);
	
	csViewOutStuff.Format( "     WORD wFunc;");
	pcsaHeader->Add(csViewOutStuff);
	
	csViewOutStuff.Format( "     WORD wLength;");
	pcsaHeader->Add(csViewOutStuff);
	
	csViewOutStuff.Format( "     WORD wRetCode;");
	pcsaHeader->Add(csViewOutStuff);
	
	csViewOutStuff.Format( "     char szString[1000];");
	pcsaHeader->Add(csViewOutStuff);
	
	csViewOutStuff.Format( "     char* pszString = szString;");
	pcsaHeader->Add(csViewOutStuff);
	
	
	// start of body
	csViewOutStuff.Format( "" );
	pcsaBody->Add(csViewOutStuff);
	
	csViewOutStuff.Format( "     LoadHllapi();");
	pcsaBody->Add(csViewOutStuff);
	
	csViewOutStuff.Format( "" );
	pcsaBody->Add(csViewOutStuff);

}


void CAG_WHL_CS::appendBody(int nFunctionNum,
							bool bPromptForValues,
							CStringArray* pcsaArguments,
							CStringArray* pcsaHeader,
							CStringArray* pcsaBody)
{
		CString csViewOutStuff;
		CString csFunctionName, csFunctionNum, csString, csStringLength, csRetCode;
	
	
		if ( bPromptForValues )
		{
			csFunctionName = pcsaArguments->GetAt( 0 );
			csFunctionNum = pcsaArguments->GetAt( 1 );
	
			if ( atoi( csFunctionNum ) != 0 )
			{
				csString = pcsaArguments->GetAt( 2 );
				csStringLength = pcsaArguments->GetAt( 3 );
				csRetCode = pcsaArguments->GetAt( 4 );
			}
		}
		else
		{
			csFunctionName = pcsaArguments->GetAt( 0 );
			csFunctionNum = pcsaArguments->GetAt(1);
	
			if ( atoi( csFunctionNum ) != 0 )
			{
				csString = pcsaArguments->GetAt(2);
				csStringLength = pcsaArguments->GetAt(3);
				csRetCode = pcsaArguments->GetAt(4);
			}
		}
	
	
		csViewOutStuff.Format( "     //Function: %s", csFunctionName );
		pcsaBody->Add(csViewOutStuff);
	
		switch ( atoi( csFunctionNum ) )
		{
			case 0:		// WinHLLAPIStartup
			{
				if ( !bnRetCode )
				{
					declareVariable( AG_N_RETURN, pcsaHeader, &bnRetCode );
				}
	
				if ( !bWHLLAPIDATA )
				{
					declareVariable( AG_WHLLAPIDATA, pcsaHeader, &bWHLLAPIDATA );
				}
	
				csViewOutStuff.Format( "     nRetCode = WHLStartup(0x0101, &wData);" );
				pcsaBody->Add(csViewOutStuff);
	
				csViewOutStuff.Format( "     if ( 0 != nRetCode )" );
				pcsaBody->Add(csViewOutStuff);
	
				csViewOutStuff.Format( "     {" );
				pcsaBody->Add(csViewOutStuff);
	
				csViewOutStuff.Format( "          return 0;" );
				pcsaBody->Add(csViewOutStuff);
	
				csViewOutStuff.Format( "     }" );
				pcsaBody->Add(csViewOutStuff);
	
				csViewOutStuff.Format(" " );
				pcsaBody->Add(csViewOutStuff);
	
			}
			break;
	
			case 1:		// CONNECTPS 
			case 2:		// DISCONNECTPS
			case 4:		// WAIT
			case 7:		// QUERYCURSORLOCATION
			case 11:	// RESERVE
			case 12:	// RELEASE
			case 14:	// QUERYFIELDATTRIBUTE
			case 18:	// PAUSE
			case 21:	// RESETSYSTEM
			case 24:	// QUERYHOSTUPDATE
			case 25:	// STOPHOSTNOTIFICATION
			case 40:	// SETCURSOR
			case 41:	// STARTCLOSEINTERCEPT
			case 42:	// QUERYCLOSEINTERCEPT
			case 43:	// STOPCLOSEINTERCEPT
			case 53:	// STOPKSINTERCEPT
			case 101:	// CONNECTWINDOWSERVICES
			case 102:	// DISCONNECTWINDOWSERVICES
			{
				csViewOutStuff.Format( "     wFunc = %s;", csFunctionNum );
				pcsaBody->Add(csViewOutStuff);
	
				csViewOutStuff.Format( "     cSession = '%s';", csString );
				pcsaBody->Add(csViewOutStuff);
	
				csViewOutStuff.Format( "     wLength = %s;", csStringLength );
				pcsaBody->Add(csViewOutStuff);
	
				csViewOutStuff.Format( "     wRetCode = %s;", csRetCode );
				pcsaBody->Add(csViewOutStuff);
	
				csViewOutStuff.Format(" " );
				pcsaBody->Add(csViewOutStuff);
	
				csViewOutStuff.Format( "     WHLLAPI( &wFunc, &cSession, &wLength, &wRetCode );" );
				pcsaBody->Add(csViewOutStuff);
	
				csViewOutStuff.Format(" " );
				pcsaBody->Add(csViewOutStuff);
	
			}
			break;
	
			case 3:		// SENDKEY
			case 6:
			case 9:
			case 15:
			case 30:	// SEARCHFIELD
			case 31:	// FINDFIELDPOSITION
			case 32:	// FINDFIELDLENGTH
			case 33:	// COPYSTRINGTOFIELD
			case 52:
			case 90:	// SENDFILE
			case 91:	// RECEIVEFILE
			case 99:	// CONVERTPOSITION
			case 103:
			case 104:
			case 105:
			case 106:
			{
				csViewOutStuff.Format( "     wFunc = %s;", csFunctionNum );
				pcsaBody->Add(csViewOutStuff);
	
				csViewOutStuff.Format( "     strcpy( szString, \"%s\" );", csString );
				pcsaBody->Add(csViewOutStuff);
	
				csViewOutStuff.Format( "     wLength = strlen(szString);" );
				pcsaBody->Add(csViewOutStuff);
	
				csViewOutStuff.Format( "     wRetCode = %s;", csRetCode );
				pcsaBody->Add(csViewOutStuff);
	
				csViewOutStuff.Format(" " );
				pcsaBody->Add(csViewOutStuff);
	
				csViewOutStuff.Format( "     WHLLAPI( &wFunc, pszString, &wLength, &wRetCode );" );
				pcsaBody->Add(csViewOutStuff);
	
				csViewOutStuff.Format(" " );
				pcsaBody->Add(csViewOutStuff);
	
			}
			break;
	
	
			case 5:
			case 8:
			{
				if ( !b_pUtilityBuffer )
				{
					declareVariable( AG_UTILBUFFER, pcsaHeader, &b_pUtilityBuffer );
				}
				else
				{
					csViewOutStuff.Format( "    free( pUtilityBuffer );");
					pcsaBody->Add(csViewOutStuff);
				}
	
				csViewOutStuff.Format( "     wFunc = %s;", csFunctionNum );
				pcsaBody->Add(csViewOutStuff);
	
				csViewOutStuff.Format( "     pUtilityBuffer = (char *)malloc( %i );", wGlobalPSMallocSize );
				pcsaBody->Add(csViewOutStuff);
	
				csViewOutStuff.Format( "     wLength = %i;", wGlobalPSMallocSize );
				pcsaBody->Add(csViewOutStuff);
	
				csViewOutStuff.Format( "     wRetCode = %s;", csRetCode );
				pcsaBody->Add(csViewOutStuff);
	
				csViewOutStuff.Format(" " );
				pcsaBody->Add(csViewOutStuff);
	
				csViewOutStuff.Format( "     WHLLAPI( &wFunc, pUtilityBuffer, &wLength, &wRetCode );" );
				pcsaBody->Add(csViewOutStuff);
	
				csViewOutStuff.Format(" " );
				pcsaBody->Add(csViewOutStuff);
	
			}
			break;
	
	
			case 10:
			{
				if ( !b_pUtilityBuffer )
				{
					declareVariable( AG_UTILBUFFER, pcsaHeader, &b_pUtilityBuffer );
				}
				else
				{
					csViewOutStuff.Format( "    free( pUtilityBuffer );");
					pcsaBody->Add(csViewOutStuff);
				}
	
	
				csViewOutStuff.Format( "     wFunc = %s;", csFunctionNum );
				pcsaBody->Add(csViewOutStuff);
	
				csViewOutStuff.Format( "     pUtilityBuffer = (char *)malloc( 312 );" );
				pcsaBody->Add(csViewOutStuff);
	
				csViewOutStuff.Format( "     wLength = 312;" );
				pcsaBody->Add(csViewOutStuff);
	
				csViewOutStuff.Format( "     wRetCode = %s;", csRetCode );
				pcsaBody->Add(csViewOutStuff);
	
				csViewOutStuff.Format(" " );
				pcsaBody->Add(csViewOutStuff);
	
				csViewOutStuff.Format( "     WHLLAPI( &wFunc, pUtilityBuffer, &wLength, &wRetCode );" );
				pcsaBody->Add(csViewOutStuff);
	
				csViewOutStuff.Format(" " );
				pcsaBody->Add(csViewOutStuff);
	
			}
			break;
	
	
			case 13:	// COPYOIA
			{
				if ( !bOIA )
				{
					declareVariable( AG_OIA, pcsaBody, &bOIA );
				}
	
				csViewOutStuff.Format( "     wFunc = %s;", csFunctionNum );
				pcsaBody->Add(csViewOutStuff);
	
				csViewOutStuff.Format( "     pOIABuffer = (char *)malloc( 103 );" );
				pcsaBody->Add(csViewOutStuff);
	
				csViewOutStuff.Format( "     wLength = 103;" );
				pcsaBody->Add(csViewOutStuff);
	
				csViewOutStuff.Format( "     wRetCode = %s;", csRetCode );
				pcsaBody->Add(csViewOutStuff);
	
				csViewOutStuff.Format(" " );
				pcsaBody->Add(csViewOutStuff);
	
				csViewOutStuff.Format( "     WHLLAPI( &wFunc, pOIABuffer, &wLength, &wRetCode );" );
				pcsaBody->Add(csViewOutStuff);
	
				csViewOutStuff.Format(" " );
				pcsaBody->Add(csViewOutStuff);
	
			}
			break;
	
	
			case 20:	// QUERYSYSTEM
			{
				if ( !b_pUtilityBuffer )
				{
					declareVariable( AG_UTILBUFFER, pcsaHeader, &b_pUtilityBuffer );
				}
				else
				{
					csViewOutStuff.Format( "    free( pUtilityBuffer );");
					pcsaBody->Add(csViewOutStuff);
				}
	
	
				csViewOutStuff.Format( "     wFunc = %s;", csFunctionNum );
				pcsaBody->Add(csViewOutStuff);
	
				csViewOutStuff.Format( "     pUtilityBuffer = (char *)malloc( 35 );" );
				pcsaBody->Add(csViewOutStuff);
	
				csViewOutStuff.Format( "     wLength = 35;" );
				pcsaBody->Add(csViewOutStuff);
	
				csViewOutStuff.Format( "     wRetCode = %s;", csRetCode );
				pcsaBody->Add(csViewOutStuff);
	
				csViewOutStuff.Format(" " );
				pcsaBody->Add(csViewOutStuff);
	
				csViewOutStuff.Format( "     WHLLAPI( &wFunc, pUtilityBuffer, &wLength, &wRetCode );" );
				pcsaBody->Add(csViewOutStuff);
	
				csViewOutStuff.Format(" " );
				pcsaBody->Add(csViewOutStuff);
	
			}
			break;
	
	
	
			case 22:
			{
				if ( !b_pUtilityBuffer )
				{
					declareVariable( AG_UTILBUFFER, pcsaHeader, &b_pUtilityBuffer );
				}
				else
				{
					csViewOutStuff.Format( "    free( pUtilityBuffer );");
					pcsaBody->Add(csViewOutStuff);
				}
	
				csViewOutStuff.Format( "     wFunc = %s;", csFunctionNum );
				pcsaBody->Add(csViewOutStuff);
	
				csViewOutStuff.Format( "     pUtilityBuffer = (char *)malloc( 18 );" );
				pcsaBody->Add(csViewOutStuff);
	
				csViewOutStuff.Format( "     pUtilityBuffer[0] = '%s';", csString.Left(1) );
				pcsaBody->Add(csViewOutStuff);
	
				csViewOutStuff.Format( "     wLength = 18;" );
				pcsaBody->Add(csViewOutStuff);
	
				csViewOutStuff.Format( "     wRetCode = %s;", csRetCode );
				pcsaBody->Add(csViewOutStuff);
	
				csViewOutStuff.Format(" " );
				pcsaBody->Add(csViewOutStuff);
	
				csViewOutStuff.Format( "     WHLLAPI( &wFunc, pUtilityBuffer, &wLength, &wRetCode );" );
				pcsaBody->Add(csViewOutStuff);
	
				csViewOutStuff.Format(" " );
				pcsaBody->Add(csViewOutStuff);
	
			}
			break;
	
	
			case 23:
			{
				csViewOutStuff.Format( "     wFunc = %s;", csFunctionNum );
				pcsaBody->Add(csViewOutStuff);
	
				csViewOutStuff.Format( "     cSession = '%s';", csString );
				pcsaBody->Add(csViewOutStuff);
	
				csViewOutStuff.Format( "     wLength = 256;" );
				pcsaBody->Add(csViewOutStuff);
	
				csViewOutStuff.Format( "     wRetCode = %s;", csRetCode );
				pcsaBody->Add(csViewOutStuff);
	
				csViewOutStuff.Format(" " );
				pcsaBody->Add(csViewOutStuff);
	
				csViewOutStuff.Format( "     WHLLAPI( &wFunc, &cSession, &wLength, &wRetCode );" );
				pcsaBody->Add(csViewOutStuff);
	
				csViewOutStuff.Format(" " );
				pcsaBody->Add(csViewOutStuff);
	
			}
			break;
	
	
			case 34:
			{
				if ( !b_pUtilityBuffer )
				{
					declareVariable( AG_UTILBUFFER, pcsaHeader, &b_pUtilityBuffer );
				}
				else
				{
					csViewOutStuff.Format( "    free( pUtilityBuffer );");
					pcsaBody->Add(csViewOutStuff);
				}
	
				csViewOutStuff.Format( "     wFunc = %s;", csFunctionNum );
				pcsaBody->Add(csViewOutStuff);
	
				csViewOutStuff.Format( "     pUtilityBuffer = (char *)malloc( %i );", csString.GetLength() );
				pcsaBody->Add(csViewOutStuff);
	
				csViewOutStuff.Format( "     strcpy( pUtilityBuffer, %s );", csString );
				pcsaBody->Add(csViewOutStuff);
	
				csViewOutStuff.Format( "     wLength = 256;" );
				pcsaBody->Add(csViewOutStuff);
	
				csViewOutStuff.Format( "     wRetCode = %s;", csRetCode );
				pcsaBody->Add(csViewOutStuff);
	
				csViewOutStuff.Format(" " );
				pcsaBody->Add(csViewOutStuff);
	
				csViewOutStuff.Format( "     WHLLAPI( &wFunc, pUtilityBuffer, &wLength, &wRetCode );" );
				pcsaBody->Add(csViewOutStuff);
	
				csViewOutStuff.Format(" " );
				pcsaBody->Add(csViewOutStuff);
	
			}
			break;
	
	
			case 50:
			{
				if ( !b_pUtilityBuffer )
				{
					declareVariable( AG_UTILBUFFER, pcsaHeader, &b_pUtilityBuffer );
				}
				else
				{
					csViewOutStuff.Format( "    free( pUtilityBuffer );");
					pcsaBody->Add(csViewOutStuff);
				}
	
				csViewOutStuff.Format( "     wFunc = %s;", csFunctionNum );
				pcsaBody->Add(csViewOutStuff);
	
				csViewOutStuff.Format( "     pUtilityBuffer = (char *)malloc( 6 );" );
				pcsaBody->Add(csViewOutStuff);
	
				csViewOutStuff.Format( "     strcpy( pUtilityBuffer, %s );", csString );
				pcsaBody->Add(csViewOutStuff);
	
				csViewOutStuff.Format( "     wLength = 256;" );
				pcsaBody->Add(csViewOutStuff);
	
				csViewOutStuff.Format( "     wRetCode = %s;", csRetCode );
				pcsaBody->Add(csViewOutStuff);
	
				csViewOutStuff.Format(" " );
				pcsaBody->Add(csViewOutStuff);
	
				csViewOutStuff.Format( "     WHLLAPI( &wFunc, pUtilityBuffer, &wLength, &wRetCode );" );
				pcsaBody->Add(csViewOutStuff);
	
				csViewOutStuff.Format(" " );
				pcsaBody->Add(csViewOutStuff);
	
			}
			break;
	
	
	
			case 51:	// GETKEY
			{
				if ( !b_pUtilityBuffer )
				{
					declareVariable( AG_UTILBUFFER, pcsaHeader, &b_pUtilityBuffer );
				}
				else
				{
					csViewOutStuff.Format( "    free( pUtilityBuffer );");
					pcsaBody->Add(csViewOutStuff);
				}
	
	
				csViewOutStuff.Format( "     wFunc = %s;", csFunctionNum );
				pcsaBody->Add(csViewOutStuff);
	
				csViewOutStuff.Format( "     pUtilityBuffer = (char *)malloc( %i );", csString.GetLength()+1 );
				pcsaBody->Add(csViewOutStuff);
	
				csViewOutStuff.Format( "     strcpy( pUtilityBuffer, %s );", csString );
				pcsaBody->Add(csViewOutStuff);
	
				csViewOutStuff.Format( "     wLength = %s;", csStringLength );
				pcsaBody->Add(csViewOutStuff);
	
				csViewOutStuff.Format( "     wRetCode = %s;", csRetCode );
				pcsaBody->Add(csViewOutStuff);
	
				csViewOutStuff.Format(" " );
				pcsaBody->Add(csViewOutStuff);
	
				csViewOutStuff.Format( "     WHLLAPI( &wFunc, pUtilityBuffer, &wLength, &wRetCode );" );
				pcsaBody->Add(csViewOutStuff);
	
				csViewOutStuff.Format(" " );
				pcsaBody->Add(csViewOutStuff);
	
			}
			break;
	
	
			case 107:	// QUERYHANDLE
			case 120:	// CONNECTSTRFLDS
			case 121:	// DISCONSTRFLDS
			case 122:	// QUERYCOMMBUFSIZ
			case 123:	// ALLOCCOMMBUFF
			case 124:	// FREECOMMBUFF
			case 125:	// GETREQUESTCOMP
			case 126:	// READSTRFLDS
			case 127:	// WRITESTRFLDS
			{
	
				csViewOutStuff.Format( "     // %s is not yet implemented.", csFunctionName );
				pcsaBody->Add(csViewOutStuff);
	
				csViewOutStuff.Format(" " );
				pcsaBody->Add(csViewOutStuff);
	
			}
			break;
	
			default:
			{
				csViewOutStuff.Format( "     //Function: %s", csFunctionName );
				pcsaBody->Add(csViewOutStuff);
	
				csViewOutStuff.Format( "     wFunc = %s;", csFunctionNum );
				pcsaBody->Add(csViewOutStuff);
	
				csViewOutStuff.Format( "     strcpy( szString, \"%s\" );", csString );
				pcsaBody->Add(csViewOutStuff);
	
				csViewOutStuff.Format( "     wLength = %s;", csStringLength );
				pcsaBody->Add(csViewOutStuff);
	
				csViewOutStuff.Format( "     wRetCode = %s;", csRetCode );
				pcsaBody->Add(csViewOutStuff);
	
				csViewOutStuff.Format(" " );
				pcsaBody->Add(csViewOutStuff);
	
				csViewOutStuff.Format( "     WHLLAPI( &wFunc, pszString, &wLength, &wRetCode );" );
				pcsaBody->Add(csViewOutStuff);
	
				csViewOutStuff.Format(" " );
				pcsaBody->Add(csViewOutStuff);
			}
	
			
		}
	
		pcsaArguments->RemoveAll();

}


void CAG_WHL_CS::finalize(CStringArray* pcsaBody)
{
	
}

void CAG_WHL_CS::checkDebug(bool b_Debug,
							   CString csFunctionName,
							   CStringArray* pcsaBody)
{
	
}



void CAG_WHL_CS::resetVariableFlags()
{
}

