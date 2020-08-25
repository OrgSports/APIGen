// Static Model
#include "stdafx.h"
#include "apigen.h"

#include "CAG_EHL_CS.h"

/////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////

CAG_EHL_CS::CAG_EHL_CS()
{
	resetVariableFlags();	
}

CAG_EHL_CS::~CAG_EHL_CS()
{
	
}


/////////////////////////////////////////////////////////////////////////////

void CAG_EHL_CS::generateHeader(CStringArray* pcsaHeader,
								CStringArray* pcsaBody)
{
		// output to Translator's output window
		CString csViewOutStuff;
	
		csViewOutStuff.Format( "// ****************************************************************************");
		pcsaHeader->Add(csViewOutStuff);
	
		csViewOutStuff.Format( "// Attachmate APIGen EHLLAPI C# Application");
		pcsaHeader->Add(csViewOutStuff);
	
		csViewOutStuff.Format( " " );
		pcsaHeader->Add(csViewOutStuff);
	
		csViewOutStuff.Format( "// This file is source code for a freestanding EHLLAPI program written in C#");
		pcsaHeader->Add(csViewOutStuff);
	
		csViewOutStuff.Format( "// that is ready to build and run.  To build and run it please do the following:");
		pcsaHeader->Add(csViewOutStuff);
	
		csViewOutStuff.Format( "//  1. Install any version of Extra! after 6.1.  Create a new session via the");
		pcsaHeader->Add(csViewOutStuff);

		csViewOutStuff.Format( "//     file/new session wizard and save it.");
		pcsaHeader->Add(csViewOutStuff);

		csViewOutStuff.Format( "//  2. Associate a HLLAPI session short name to the new session within the");
		pcsaHeader->Add(csViewOutStuff);

		csViewOutStuff.Format( "//     Advanced property page of the Options/Global settings menu.");
		pcsaHeader->Add(csViewOutStuff);

		csViewOutStuff.Format( "//  3. Copy the acs3ehap.h file to the same folder where this source file will be built.");
		pcsaHeader->Add(csViewOutStuff);
	
		csViewOutStuff.Format( "//  4) Open Visual Studio .Net or, if it's already running, close any open project. Open this file,");
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
	
		csViewOutStuff.Format( "#include \"acs3ehap.h\"" );
		pcsaHeader->Add(csViewOutStuff);
	
		csViewOutStuff.Format( "%s", "" );
		pcsaHeader->Add(csViewOutStuff);
	
		csViewOutStuff.Format( "// prototype the EHLLAPI entry point");
		pcsaHeader->Add(csViewOutStuff);
	
		csViewOutStuff.Format( "void (WINAPI *EHLLAPI)(LPINT, LPSTR, LPINT, LPINT);" );
		pcsaHeader->Add(csViewOutStuff);
	
		csViewOutStuff.Format( "%s", "" );
		pcsaHeader->Add(csViewOutStuff);
	
		csViewOutStuff.Format( "// load the EHLLAPI dll and establish the entry point");
		pcsaHeader->Add(csViewOutStuff);
	
		csViewOutStuff.Format( "%s", "void LoadHllapi()");
		pcsaHeader->Add(csViewOutStuff);
	
		csViewOutStuff.Format( "%s", "{");
		pcsaHeader->Add(csViewOutStuff);
	
		csViewOutStuff.Format( "     HMODULE dllHandle = LoadLibrary(\"ehlapi32.dll\");");
		pcsaHeader->Add(csViewOutStuff);
	
		csViewOutStuff.Format( "%s", "     FARPROC pProcAddress;");
		pcsaHeader->Add(csViewOutStuff);
	
		csViewOutStuff.Format( "     pProcAddress = GetProcAddress(dllHandle, \"HLLAPI\" );");
		pcsaHeader->Add(csViewOutStuff);
	
		csViewOutStuff.Format( "     EHLLAPI = (void (WINAPI *)(LPINT, LPSTR, LPINT, LPINT)) pProcAddress;");
		pcsaHeader->Add(csViewOutStuff);
	
		csViewOutStuff.Format( "%s", "}");
		pcsaHeader->Add(csViewOutStuff);
	
		csViewOutStuff.Format( "%s", "" );
		pcsaHeader->Add(csViewOutStuff);
	
		csViewOutStuff.Format( "int main(int argc, CHAR* argv[])");
		pcsaHeader->Add(csViewOutStuff);
	
		csViewOutStuff.Format( "%s", "{");
		pcsaHeader->Add(csViewOutStuff);
	
		csViewOutStuff.Format( "%s", "     char cSession;");
		pcsaHeader->Add(csViewOutStuff);
	
		csViewOutStuff.Format( "%s", "     int nFunc;");
		pcsaHeader->Add(csViewOutStuff);
	
		csViewOutStuff.Format( "%s", "     int nLength;");
		pcsaHeader->Add(csViewOutStuff);
	
		csViewOutStuff.Format( "%s", "     int nRetCode;");
		pcsaHeader->Add(csViewOutStuff);
	
		csViewOutStuff.Format( "%s", "     char szString[1000];");
		pcsaHeader->Add(csViewOutStuff);
	
		csViewOutStuff.Format( "%s", "     char* pszString = szString;");
		pcsaHeader->Add(csViewOutStuff);
	
		
		// start of body
		csViewOutStuff.Format( "%s", "" );
		pcsaBody->Add(csViewOutStuff);
	
		csViewOutStuff.Format( "%s", "     LoadHllapi();");
		pcsaBody->Add(csViewOutStuff);
	
		csViewOutStuff.Format( "%s", "" );
		pcsaBody->Add(csViewOutStuff);

}


void CAG_EHL_CS::appendBody(int nFunctionNum,
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
			csString = pcsaArguments->GetAt( 2 );
			csStringLength = pcsaArguments->GetAt( 3 );
			csRetCode = pcsaArguments->GetAt( 4 );
		}
		else
		{
			csFunctionName = pcsaArguments->GetAt( 0 );
			csFunctionNum = pcsaArguments->GetAt(1);
			csString = pcsaArguments->GetAt(2);
			csStringLength = pcsaArguments->GetAt(3);
			csRetCode = pcsaArguments->GetAt(4);
		}
	
		csViewOutStuff.Format( "     //Function: %s", csFunctionName );
		pcsaBody->Add(csViewOutStuff);
	
	
		switch ( atoi( csFunctionNum ) )
		{
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
				csViewOutStuff.Format( "     nFunc = %s;", csFunctionNum );
				pcsaBody->Add(csViewOutStuff);
	
				csViewOutStuff.Format( "     cSession = '%s';", csString );
				pcsaBody->Add(csViewOutStuff);
	
				csViewOutStuff.Format( "     nLength = %s;", csStringLength );
				pcsaBody->Add(csViewOutStuff);
	
				csViewOutStuff.Format( "     nRetCode = %s;", csRetCode );
				pcsaBody->Add(csViewOutStuff);
	
				csViewOutStuff.Format( " " );
				pcsaBody->Add(csViewOutStuff);
	
				csViewOutStuff.Format( "     EHLLAPI( &nFunc, &cSession, &nLength, &nRetCode );"  );
				pcsaBody->Add(csViewOutStuff);
	
				csViewOutStuff.Format( " " );
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
				csViewOutStuff.Format( "     nFunc = %s;", csFunctionNum );
				pcsaBody->Add(csViewOutStuff);
	
				csViewOutStuff.Format( "     strcpy( pszString, \"%s\" );", csString );
				pcsaBody->Add(csViewOutStuff);
	
				csViewOutStuff.Format( "     nLength = strlen(pszString);" );
				pcsaBody->Add(csViewOutStuff);
	
				csViewOutStuff.Format( "     nRetCode = %s;", csRetCode );
				pcsaBody->Add(csViewOutStuff);
	
				csViewOutStuff.Format( " " );
				pcsaBody->Add(csViewOutStuff);
	
				csViewOutStuff.Format( "     EHLLAPI( &nFunc, pszString, &nLength, &nRetCode );" );
				pcsaBody->Add(csViewOutStuff);
	
				csViewOutStuff.Format( " " );
				pcsaBody->Add(csViewOutStuff);
	
			}
			break;
	
	
			case 5:
			case 8:
			{
				
				if ( !b_pUtilityBuffer )
				{
					b_pUtilityBuffer = TRUE;
					csViewOutStuff.Format( "%s", "     char *pUtilityBuffer;");
					pcsaHeader->Add(csViewOutStuff);
				}
				else
				{
					csViewOutStuff.Format( "    free( pUtilityBuffer );");
					pcsaBody->Add(csViewOutStuff);
				}
	
	
				csViewOutStuff.Format( "     nFunc = %s;", csFunctionNum );
				pcsaBody->Add(csViewOutStuff);
	
				csViewOutStuff.Format( "     pUtilityBuffer = (char *)malloc( %i );", usGlobalPSMallocSize );
				pcsaBody->Add(csViewOutStuff);
	
				csViewOutStuff.Format( "     nLength = %i;", usGlobalPSMallocSize );
				pcsaBody->Add(csViewOutStuff);
	
				csViewOutStuff.Format( "     nRetCode = %s;", csRetCode );
				pcsaBody->Add(csViewOutStuff);
	
				csViewOutStuff.Format( " " );
				pcsaBody->Add(csViewOutStuff);
	
				csViewOutStuff.Format( "     EHLLAPI( &nFunc, pUtilityBuffer, &nLength, &nRetCode );"  );
				pcsaBody->Add(csViewOutStuff);
	
				csViewOutStuff.Format( " " );
				pcsaBody->Add(csViewOutStuff);
	
			}
			break;
	
	
			case 10:
			{
				if ( !b_pUtilityBuffer )
				{
					b_pUtilityBuffer = TRUE;
					csViewOutStuff.Format( "%s", "     char *pUtilityBuffer;");
					pcsaHeader->Add(csViewOutStuff);
				}
				else
				{
					csViewOutStuff.Format( "    free( pUtilityBuffer );");
					pcsaBody->Add(csViewOutStuff);
				}
	
				csViewOutStuff.Format( "     nFunc = %s;", csFunctionNum );
				pcsaBody->Add(csViewOutStuff);
	
				csViewOutStuff.Format( "     pUtilityBuffer = (char *)malloc( 312 );" );
				pcsaBody->Add(csViewOutStuff);
	
				csViewOutStuff.Format( "     nLength = 312;" );
				pcsaBody->Add(csViewOutStuff);
	
				csViewOutStuff.Format( "     nRetCode = %s;", csRetCode );
				pcsaBody->Add(csViewOutStuff);
	
				csViewOutStuff.Format( " " );
				pcsaBody->Add(csViewOutStuff);
	
				csViewOutStuff.Format( "     EHLLAPI( &nFunc, pUtilityBuffer, &nLength, &nRetCode );"  );
				pcsaBody->Add(csViewOutStuff);
	
				csViewOutStuff.Format( " " );
				pcsaBody->Add(csViewOutStuff);
	
			}
			break;
	
	
			case 13:
			{
				csViewOutStuff.Format( "     nFunc = %s;", csFunctionNum );
				pcsaBody->Add(csViewOutStuff);
	
				csViewOutStuff.Format( "     char *pOIABuffer = (char *)malloc( 103 );" );
				pcsaBody->Add(csViewOutStuff);
	
				csViewOutStuff.Format( "     nLength = 103;" );
				pcsaBody->Add(csViewOutStuff);
	
				csViewOutStuff.Format( "     nRetCode = %s;", csRetCode );
				pcsaBody->Add(csViewOutStuff);
	
				csViewOutStuff.Format( " " );
				pcsaBody->Add(csViewOutStuff);
	
				csViewOutStuff.Format( "     EHLLAPI( &nFunc, pOIABuffer, &nLength, &nRetCode );"  );
				pcsaBody->Add(csViewOutStuff);
	
				csViewOutStuff.Format( " " );
				pcsaBody->Add(csViewOutStuff);
	
				csViewOutStuff.Format( "     free( pOIABuffer );");
				pcsaBody->Add(csViewOutStuff);
	
				csViewOutStuff.Format( " " );
				pcsaBody->Add(csViewOutStuff);
	
			}
			break;
	
	
			case 20:	// QUERYSYSTEM
			{
				if ( !b_pUtilityBuffer )
				{
					b_pUtilityBuffer = TRUE;
					csViewOutStuff.Format( "%s", "     char *pUtilityBuffer;");
					pcsaHeader->Add(csViewOutStuff);
				}
				else
				{
					csViewOutStuff.Format( "    free( pUtilityBuffer );");
					pcsaBody->Add(csViewOutStuff);
				}
	
				
				csViewOutStuff.Format( "     nFunc = %s;", csFunctionNum );
				pcsaBody->Add(csViewOutStuff);
	
				csViewOutStuff.Format( "     pUtilityBuffer = (char *)malloc( 35 );" );
				pcsaBody->Add(csViewOutStuff);
	
				csViewOutStuff.Format( "     nLength = 35;" );
				pcsaBody->Add(csViewOutStuff);
	
				csViewOutStuff.Format( "     nRetCode = %s;", csRetCode );
				pcsaBody->Add(csViewOutStuff);
	
				csViewOutStuff.Format( " " );
				pcsaBody->Add(csViewOutStuff);
	
				csViewOutStuff.Format( "     EHLLAPI( &nFunc, pUtilityBuffer, &nLength, &nRetCode );"  );
				pcsaBody->Add(csViewOutStuff);
	
				csViewOutStuff.Format( " " );
				pcsaBody->Add(csViewOutStuff);
	
			}
			break;
	
	
	
			case 22:
			{
				if ( !b_pUtilityBuffer )
				{
					b_pUtilityBuffer = TRUE;
					csViewOutStuff.Format( "%s", "     char *pUtilityBuffer;");
					pcsaHeader->Add(csViewOutStuff);
				}
				else
				{
					csViewOutStuff.Format( "    free( pUtilityBuffer );");
					pcsaBody->Add(csViewOutStuff);
				}
	
				
				csViewOutStuff.Format( "     nFunc = %s;", csFunctionNum );
				pcsaBody->Add(csViewOutStuff);
	
				csViewOutStuff.Format( "     pUtilityBuffer = (char *)malloc( 18 );" );
				pcsaBody->Add(csViewOutStuff);
	
				csViewOutStuff.Format( "     pUtilityBuffer[0] = '%s';", csString.Left(1) );
				pcsaBody->Add(csViewOutStuff);
	
				csViewOutStuff.Format( "     nLength = 18;" );
				pcsaBody->Add(csViewOutStuff);
	
				csViewOutStuff.Format( "     nRetCode = %s;", csRetCode );
				pcsaBody->Add(csViewOutStuff);
	
				csViewOutStuff.Format( " " );
				pcsaBody->Add(csViewOutStuff);
	
				csViewOutStuff.Format( "     EHLLAPI( &nFunc, pUtilityBuffer, &nLength, &nRetCode );"  );
				pcsaBody->Add(csViewOutStuff);
	
				csViewOutStuff.Format( " " );
				pcsaBody->Add(csViewOutStuff);
	
			}
			break;
	
	
			case 23:	// STARTHOSTNOTIFICATION
			{
				csViewOutStuff.Format( "     nFunc = %s;", csFunctionNum );
				pcsaBody->Add(csViewOutStuff);
	
				csViewOutStuff.Format( "     cSession = '%s';", csString );
				pcsaBody->Add(csViewOutStuff);
	
				csViewOutStuff.Format( "     nLength = 256;" );
				pcsaBody->Add(csViewOutStuff);
	
				csViewOutStuff.Format( "     nRetCode = %s;", csRetCode );
				pcsaBody->Add(csViewOutStuff);
	
				csViewOutStuff.Format( " " );
				pcsaBody->Add(csViewOutStuff);
	
				csViewOutStuff.Format( "     EHLLAPI( &nFunc, &cSession, &nLength, &nRetCode );"  );
				pcsaBody->Add(csViewOutStuff);
	
				csViewOutStuff.Format( " " );
				pcsaBody->Add(csViewOutStuff);
	
			}
			break;
	
	
			case 34:
			{
				if ( !b_pUtilityBuffer )
				{
					b_pUtilityBuffer = TRUE;
					csViewOutStuff.Format( "%s", "     char *pUtilityBuffer;");
					pcsaHeader->Add(csViewOutStuff);
				}
				else
				{
					csViewOutStuff.Format( "    free( pUtilityBuffer );");
					pcsaBody->Add(csViewOutStuff);
				}
	
				
				csViewOutStuff.Format( "     nFunc = %s;", csFunctionNum );
				pcsaBody->Add(csViewOutStuff);
	
				csViewOutStuff.Format( "     pUtilityBuffer = (char *)malloc( %i );", csString.GetLength()+1 );
				pcsaBody->Add(csViewOutStuff);
	
				csViewOutStuff.Format( "     strcpy( pUtilityBuffer, %s );", csString );
				pcsaBody->Add(csViewOutStuff);
	
				csViewOutStuff.Format( "     nLength = 256;" );
				pcsaBody->Add(csViewOutStuff);
	
				csViewOutStuff.Format( "     nRetCode = %s;", csRetCode );
				pcsaBody->Add(csViewOutStuff);
	
				csViewOutStuff.Format( " " );
				pcsaBody->Add(csViewOutStuff);
	
				csViewOutStuff.Format( "     EHLLAPI( &nFunc, pUtilityBuffer, &nLength, &nRetCode );"  );
				pcsaBody->Add(csViewOutStuff);
	
				csViewOutStuff.Format( " " );
				pcsaBody->Add(csViewOutStuff);
	
			}
			break;
	
	
			case 50:
			{
				if ( !b_pUtilityBuffer )
				{
					b_pUtilityBuffer = TRUE;
					csViewOutStuff.Format( "%s", "     char *pUtilityBuffer;");
					pcsaHeader->Add(csViewOutStuff);
				}
				else
				{
					csViewOutStuff.Format( "    free( pUtilityBuffer );");
					pcsaBody->Add(csViewOutStuff);
				}
	
				
				csViewOutStuff.Format( "     nFunc = %s;", csFunctionNum );
				pcsaBody->Add(csViewOutStuff);
	
				csViewOutStuff.Format( "     pUtilityBuffer = (char *)malloc( %i );", csString.GetLength()+1 );
				pcsaBody->Add(csViewOutStuff);
	
				csViewOutStuff.Format( "     strcpy( pUtilityBuffer, %s );", csString );
				pcsaBody->Add(csViewOutStuff);
	
				csViewOutStuff.Format( "     nLength = 256;" );
				pcsaBody->Add(csViewOutStuff);
	
				csViewOutStuff.Format( "     nRetCode = %s;", csRetCode );
				pcsaBody->Add(csViewOutStuff);
	
				csViewOutStuff.Format( " " );
				pcsaBody->Add(csViewOutStuff);
	
				csViewOutStuff.Format( "     EHLLAPI( &nFunc, pUtilityBuffer, &nLength, &nRetCode );"  );
				pcsaBody->Add(csViewOutStuff);
	
				csViewOutStuff.Format( " " );
				pcsaBody->Add(csViewOutStuff);
	
				csViewOutStuff.Format( " " );
				pcsaBody->Add(csViewOutStuff);
	
	
			}
			break;
	
	
			case 51:	// GETKEY
			{
				if ( !b_pUtilityBuffer )
				{
					b_pUtilityBuffer = TRUE;
					csViewOutStuff.Format( "%s", "     char *pUtilityBuffer;");
					pcsaHeader->Add(csViewOutStuff);
				}
				else
				{
					csViewOutStuff.Format( "    free( pUtilityBuffer );");
					pcsaBody->Add(csViewOutStuff);
				}
	
				
				csViewOutStuff.Format( "     nFunc = %s;", csFunctionNum );
				pcsaBody->Add(csViewOutStuff);
	
				csViewOutStuff.Format( "     pUtilityBuffer = (char *)malloc( %i );", csString.GetLength()+1 );
				pcsaBody->Add(csViewOutStuff);
	
				csViewOutStuff.Format( "     strcpy( pUtilityBuffer, %s );", csString );
				pcsaBody->Add(csViewOutStuff);
	
				csViewOutStuff.Format( "     nLength = %s;", csStringLength );
				pcsaBody->Add(csViewOutStuff);
	
				csViewOutStuff.Format( "     nRetCode = %s;", csRetCode );
				pcsaBody->Add(csViewOutStuff);
	
				csViewOutStuff.Format( " " );
				pcsaBody->Add(csViewOutStuff);
	
				csViewOutStuff.Format( "     EHLLAPI( &nFunc, pUtilityBuffer, &nLength, &nRetCode );"  );
				pcsaBody->Add(csViewOutStuff);
	
				csViewOutStuff.Format( " " );
				pcsaBody->Add(csViewOutStuff);
	
			}
			break;
	
			case 137:
			{
				csViewOutStuff.Format( "     // int nWFQRet = HLLAPIWaitForQuiet (cSessID, dwSettleTime,dwTimeOut);" );  
	 			pcsaBody->Add(csViewOutStuff);
	
				csViewOutStuff.Format( " " );
				pcsaBody->Add(csViewOutStuff);
			}
			break;
	
	
			default:
			{
				csViewOutStuff.Format( "     nFunc = %s;", csFunctionNum );
				pcsaBody->Add(csViewOutStuff);
	
				csViewOutStuff.Format( "     strcpy( szString, \"%s\" );", csString );
				pcsaBody->Add(csViewOutStuff);
	
				csViewOutStuff.Format( "     nLength = %s;", csStringLength );
				pcsaBody->Add(csViewOutStuff);
	
				csViewOutStuff.Format( "     nRetCode = %s;", csRetCode );
				pcsaBody->Add(csViewOutStuff);
	
				csViewOutStuff.Format( " " );
				pcsaBody->Add(csViewOutStuff);
	
				csViewOutStuff.Format( "     EHLLAPI( &nFunc, pszString, &nLength, &nRetCode );"  );
				pcsaBody->Add(csViewOutStuff);
	
				csViewOutStuff.Format( " " );
				pcsaBody->Add(csViewOutStuff);
	
			}
	
			
		}
	
		pcsaArguments->RemoveAll();
	

}

void CAG_EHL_CS::finalize(CStringArray* pcsaBody)
{
		CString csLocal;
	
		if ( b_pUtilityBuffer )
		{
			csLocal.Format( "     free( pUtilityBuffer );");
			pcsaBody->Add(csLocal);
	
			csLocal.Format( " ");
			pcsaBody->Add(csLocal);
		}
	
		csLocal.Format( " " );
		pcsaBody->Add(csLocal);
	
		csLocal.Format("%s", "     return 1;" );
		pcsaBody->Add(csLocal);
	
		csLocal.Format( " " );
		pcsaBody->Add(csLocal);
	
		csLocal.Format("%s", "}" );
		pcsaBody->Add(csLocal);
	
		csLocal.Format( " " );
		pcsaBody->Add(csLocal);

}
/////////////////////////////////////////////////////////////////////////////


void CAG_EHL_CS::declareVariable(CListBox* agVariable,
								 CStringArray* pcsaHeader,
								 bool bValue)
{
	
}

void CAG_EHL_CS::checkDebug(bool b_Debug,
									   CString csFunctionName,
									   CStringArray* pcsaBody)
{
	
}

void CAG_EHL_CS::resetVariableFlags()
{
   b_pUtilityBuffer = FALSE;
}