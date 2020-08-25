// Static Model
#include "stdafx.h"
#include "apigen.h"

#include "CAG_EHL_CPP.h"
#include "time.h"



CAG_EHL_CPP::CAG_EHL_CPP()
{
	APIFlavor = EHL_API;
	resetVariableFlags();
}


CAG_EHL_CPP::~CAG_EHL_CPP()
{
	
}


void CAG_EHL_CPP::generateHeader(CStringArray* pcsaHeader,
								 CStringArray* pcsaBody)
{
		// output to Translator's output window
		CString csViewOutStuff;
	
		pcsaHeader->Add("// ****************************************************************************");
		pcsaHeader->Add("// Attachmate APIGen EHLLAPI C++ Application");
		pcsaHeader->Add(" " );
		pcsaHeader->Add("// This file is source code for a freestanding EHLLAPI program written in C++");
		pcsaHeader->Add("// that is ready to build and run.  To build and run it please do the following:");
		pcsaHeader->Add("//  1. Install any version of Extra! after 6.1.  Create a new session via the");
		pcsaHeader->Add("//     file/new session wizard and save it.");
		pcsaHeader->Add("//  2. Associate a HLLAPI session short name to the new session within the");
		pcsaHeader->Add("//     Advanced property page of the Options/Global settings menu.");
		pcsaHeader->Add("//  3. Copy the acs3ehap.h file to the same folder where this source file will be built.");
		pcsaHeader->Add("//  4) Open Visual C++ or, if it's already running, close any open project. Open this file,");
		pcsaHeader->Add("//      and then select the Build\\Compile menu item.  Accept the prompt to start a new");
		pcsaHeader->Add("//      project and the compiler will generate your application.");
		pcsaHeader->Add("// ");
	
		time_t ltime;
		time( &ltime );
	
		csViewOutStuff.Format( "//   Generated:   %s", ctime( &ltime ) );
		pcsaHeader->Add(csViewOutStuff);
	
		pcsaHeader->Add("//");
		pcsaHeader->Add("// ****************************************************************************");
		pcsaHeader->Add("#include <windows.h>");
		pcsaHeader->Add("#include <stdio.h>");
		pcsaHeader->Add("#include \"acs3ehap.h\"" );
		pcsaHeader->Add( "" );
		pcsaHeader->Add("// prototype the EHLLAPI entry point");
		pcsaHeader->Add("void (WINAPI *EHLLAPI)(LPINT, LPSTR, LPINT, LPINT);" );
		pcsaHeader->Add("" );
		pcsaHeader->Add("// load the EHLLAPI dll and establish the entry point");
		pcsaHeader->Add("void LoadHllapi()");
		pcsaHeader->Add("{");
		pcsaHeader->Add("     HMODULE dllHandle = LoadLibrary(\"ehlapi32.dll\");");
		pcsaHeader->Add("     FARPROC pProcAddress;");
		pcsaHeader->Add("     pProcAddress = GetProcAddress(dllHandle, \"HLLAPI\" );");
		pcsaHeader->Add("     EHLLAPI = (void (WINAPI *)(LPINT, LPSTR, LPINT, LPINT)) pProcAddress;");
		pcsaHeader->Add("}");
		pcsaHeader->Add("" );
	
		pcsaHeader->Add("int main(int argc, CHAR* argv[])");
		pcsaHeader->Add("{");
		pcsaHeader->Add("     char cSession;");
		pcsaHeader->Add("     int nFunc;");
		pcsaHeader->Add("     int nLength;");
		pcsaHeader->Add("     int nRetCode;");
		pcsaHeader->Add("     char szString[1000];");
		pcsaHeader->Add("     char* pszString = szString;");
		
		// start of body
		pcsaHeader->Add("" );
		pcsaHeader->Add("     LoadHllapi();");
		pcsaHeader->Add("" );

}

void CAG_EHL_CPP::appendBody(int nFunctionNum,
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

void CAG_EHL_CPP::finalize(CStringArray* pcsaBody)
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


void CAG_EHL_CPP::declareVariable(CListBox* agVariable,
								  CStringArray* pcsaHeader,
								  bool bValue)
{
	
}

void CAG_EHL_CPP::checkDebug(bool b_Debug,
									   CString csFunctionName,
									   CStringArray* pcsaBody)
{
	
}

void CAG_EHL_CPP::resetVariableFlags()
{
   b_pUtilityBuffer = FALSE;
}