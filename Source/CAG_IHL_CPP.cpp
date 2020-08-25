// Static Model
#include "stdafx.h"
#include "apigen.h"

#include "CAG_IHL_CPP.h"


CAG_IHL_CPP::CAG_IHL_CPP()
{
	resetVariableFlags();	
}

CAG_IHL_CPP::~CAG_IHL_CPP()
{
	
}

void CAG_IHL_CPP::declareVariable(AG_VARIABLE agVariable,
								  CStringArray* pcsaHeader,
								  bool* bValue)
{
	CString csLocal;
	*bValue = TRUE;
		
	switch ( agVariable )
	{
		case AG_N_RETURN:
		{
			csLocal.Format( "      int nRetCode=FALSE;");
		}
		break;
	
		case AG_OIA:
		{
			csLocal.Format( "      poOIA = poScreen->OIA;");
		}
		break;
			
		case AG_UTILBUFFER:
		{
			csLocal.Format( "      char *pUtilityBuffer;");
		}
		break;
	
		case AG_WHLLAPIDATA:
		{
			csLocal.Format( "      WHLLAPIDATA   wData;");
		}
		break;
	
	}
	
	pcsaHeader->Add(csLocal);
}


void CAG_IHL_CPP::generateHeader(CStringArray* pcsaHeader,
								 CStringArray* pcsaBody)
{
	// output to Translator's output window
	CString csViewOutStuff;

	csViewOutStuff.Format( "// ****************************************************************************");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "// Attachmate APIGen IHLLAPI C++ Application");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "//" );
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "// This file is source code for a freestanding IHLLAPI program written in C++");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "// that is ready to build and run.  To build and run it please do the following:");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "//  1. Install any version of INFOConnect.  Create a new session via the");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "//     file/new session wizard and save it.");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "//  2. Associate a HLLAPI session short name to the new session within the");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "//     Advanced property page of the Options/Global settings menu.");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "//  3. Copy the ihlapi32.h file to the same folder where this source file will be built.");
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

	csViewOutStuff.Format( "#include <stdio.h>");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "#include \"ihlapi32.h\"" );
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( " " );
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "// prototype the IHLLAPI entry point");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "void (WINAPI *IHLLAPI)(LPWORD, LPSTR, LPWORD, LPWORD);");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "" );
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "// load the IHLLAPI dll and establish the entry point");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "void LoadHllapi()");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "{");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "     HMODULE dllHandle = LoadLibrary(\"ihlapi32.dll\");");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "     FARPROC pProcAddress;");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "     pProcAddress = GetProcAddress(dllHandle,\"WinHLLAPI\");");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "     IHLLAPI = ( void (WINAPI *)(LPWORD, LPSTR, LPWORD, LPWORD) ) pProcAddress;");
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

void CAG_IHL_CPP::appendBody(int nFunctionNum,
							 bool bPromptForValues,
							 CStringArray* pcsaArguments,
							 CStringArray* pcsaHeader,
							 CStringArray* pcsaBody)
{
	CString csViewOutStuff;
	CString csFunctionName, csFunctionNum, csString, csStringLength, csRetCode;

	csFunctionName = pcsaArguments->GetAt( 0 );
	csFunctionNum = pcsaArguments->GetAt( 1 );
	csString = pcsaArguments->GetAt( 2 );
	csStringLength = pcsaArguments->GetAt( 3 );
	csRetCode = pcsaArguments->GetAt( 4 );

	switch ( atoi( csFunctionNum ) )
	{
		case 911:	// Associate Profile
		{
			csString.Replace( "\\", "\\\\" );
		}
		break;

		case 915:	// Find Short Name
		{
			csString.Replace( "\\", "\\\\" );
		}
		break;

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
			csViewOutStuff.Format( "     wFunc = %s;", csFunctionNum );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "     cSession = '%s';", csString );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "     wLength = %s;", csStringLength );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "     wRetCode = %s;", csRetCode );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format("%s", " " );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "     IHLLAPI( &wFunc, &cSession, &wLength, &wRetCode );"   );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format("%s", " " );
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
		{
			csViewOutStuff.Format( "     wFunc = %s;", csFunctionNum );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "     strcpy( szString, \"%s\" );", csString );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "     wLength = strlen(szString);" );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "     wRetCode = %s;", csRetCode );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format("%s", " " );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "     IHLLAPI( &wFunc, pszString, &wLength, &wRetCode );"  );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format("%s", " " );
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
				csViewOutStuff.Format( "     free( pUtilityBuffer );");
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

			csViewOutStuff.Format("%s", " " );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "     IHLLAPI( &wFunc, pUtilityBuffer, &wLength, &wRetCode );"  );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format("%s", " " );
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
				csViewOutStuff.Format( "     free( pUtilityBuffer );");
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

			csViewOutStuff.Format("%s", " " );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "     IHLLAPI( &wFunc, pUtilityBuffer, &wLength, &wRetCode );"  );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format("%s", " " );
			pcsaBody->Add(csViewOutStuff);

		}
		break;


		case 13:
		{
			if ( !b_pOIABuffer )
			{
				b_pOIABuffer = TRUE;
				csViewOutStuff.Format( "     char *pOIABuffer;" );
				pcsaHeader->Add(csViewOutStuff);
			}
			else
			{
				csViewOutStuff.Format( "     free( pOIABuffer );");
				pcsaBody->Add(csViewOutStuff);
			}


			csViewOutStuff.Format( "     wFunc = %s;", csFunctionNum );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "     pOIABuffer = (char *)malloc( 103 );" );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "     wLength = 103;" );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "     wRetCode = %s;", csRetCode );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format("%s", " " );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "     IHLLAPI( &wFunc, pOIABuffer, &wLength, &wRetCode );"  );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format("%s", " " );
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
				csViewOutStuff.Format( "     free( pUtilityBuffer );");
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

			csViewOutStuff.Format("%s", " " );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "     IHLLAPI( &wFunc, pUtilityBuffer, &wLength, &wRetCode );"  );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format("%s", " " );
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
				csViewOutStuff.Format( "     free( pUtilityBuffer );");
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

			csViewOutStuff.Format("%s", " " );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "     IHLLAPI( &wFunc, pUtilityBuffer, &wLength, &wRetCode );"  );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format("%s", " " );
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

			csViewOutStuff.Format("%s", " " );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "     IHLLAPI( &wFunc, &cSession, &wLength, &wRetCode );"  );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format("%s", " " );
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
				csViewOutStuff.Format( "     free( pUtilityBuffer );");
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

			csViewOutStuff.Format("%s", " " );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "     IHLLAPI( &wFunc, pUtilityBuffer, &wLength, &wRetCode );"  );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format("%s", " " );
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
				csViewOutStuff.Format( "     free( pUtilityBuffer );");
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

			csViewOutStuff.Format("%s", " " );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "     IHLLAPI( &wFunc, pUtilityBuffer, &wLength, &wRetCode );"  );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format("%s", " " );
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
				csViewOutStuff.Format( "     free( pUtilityBuffer );");
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

			csViewOutStuff.Format("%s", " " );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "     IHLLAPI( &wFunc, pUtilityBuffer, &wLength, &wRetCode );"  );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format("%s", " " );
			pcsaBody->Add(csViewOutStuff);

		}
		break;


		case 911:	// Associate Profile
		{
			if ( !b_pUtilityBuffer )
			{
				b_pUtilityBuffer = TRUE;
				csViewOutStuff.Format( "%s", "     char *pUtilityBuffer;");
				pcsaHeader->Add(csViewOutStuff);
			}
			else
			{
				csViewOutStuff.Format( "     free( pUtilityBuffer );");
				pcsaBody->Add(csViewOutStuff);
			}

			csViewOutStuff.Format( "     wFunc = %s;", csFunctionNum );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "     pUtilityBuffer = (char *)malloc( %i );", csString.GetLength() );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "     strcpy( pUtilityBuffer, \"%s\" );", csString );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "     wLength = 0;" );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "     wRetCode = 0;" );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format("%s", " " );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "     IHLLAPI( &wFunc, pUtilityBuffer, &wLength, &wRetCode );"  );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format("%s", " " );
			pcsaBody->Add(csViewOutStuff);

		}
		break;
	
		case 912:	// Remove Profile
		{
			csViewOutStuff.Format( "     wFunc = %s;", csFunctionNum );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "     cSession = '%s';", csString );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "     wLength = 0;" );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "     wRetCode = 0;" );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format("%s", " " );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "     IHLLAPI( &wFunc, &cSession, &wLength, &wRetCode );"   );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format("%s", " " );
			pcsaBody->Add(csViewOutStuff);

		}
		break;


		case 913:	// Get Associations
		{
			if ( !b_pUtilityBuffer )
			{
				b_pUtilityBuffer = TRUE;
				csViewOutStuff.Format( "%s", "     char *pUtilityBuffer;");
				pcsaHeader->Add(csViewOutStuff);
			}
			else
			{
				csViewOutStuff.Format( "     free( pUtilityBuffer );");
				pcsaBody->Add(csViewOutStuff);
			}

			csViewOutStuff.Format( "     wFunc = %s;", csFunctionNum );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "     pUtilityBuffer = (char *)malloc( 27 );" );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "     memset( pUtilityBuffer, '0', 27 );" );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "     wLength = 0;" );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "     wRetCode = 0;" );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format("%s", " " );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "     IHLLAPI( &wFunc, pUtilityBuffer, &wLength, &wRetCode );"  );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format("%s", " " );
			pcsaBody->Add(csViewOutStuff);

		}
		break;

		case 914:	// Find File Name
		{
			if ( !b_pUtilityBuffer )
			{
				b_pUtilityBuffer = TRUE;
				csViewOutStuff.Format( "%s", "     char *pUtilityBuffer;");
				pcsaHeader->Add(csViewOutStuff);
			}
			else
			{
				csViewOutStuff.Format( "     free( pUtilityBuffer );");
				pcsaBody->Add(csViewOutStuff);
			}

			csViewOutStuff.Format( "     wFunc = %s;", csFunctionNum );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "     pUtilityBuffer = (char *)malloc( 512 );" );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "     strcpy( pUtilityBuffer, \"%s\" );", csString );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "     wLength = 0;" );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "     wRetCode = 0;" );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format("%s", " " );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "     IHLLAPI( &wFunc, pUtilityBuffer, &wLength, &wRetCode );"  );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format("%s", " " );
			pcsaBody->Add(csViewOutStuff);

		}
		break;

		case 915:	// Find Short Name
		{
			if ( !b_pUtilityBuffer )
			{
				b_pUtilityBuffer = TRUE;
				csViewOutStuff.Format( "%s", "     char *pUtilityBuffer;");
				pcsaHeader->Add(csViewOutStuff);
			}
			else
			{
				csViewOutStuff.Format( "     free( pUtilityBuffer );");
				pcsaBody->Add(csViewOutStuff);
			}

			csViewOutStuff.Format( "     wFunc = %s;", csFunctionNum );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "     pUtilityBuffer = (char *)malloc( %i );", csString.GetLength() );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "     strcpy( pUtilityBuffer, \"%s\" );", csString );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "     wLength = 0;" );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "     wRetCode = 0;" );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format("%s", " " );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "     IHLLAPI( &wFunc, pUtilityBuffer, &wLength, &wRetCode );"  );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format("%s", " " );
			pcsaBody->Add(csViewOutStuff);

		}
		break;

		default:
		{
			csViewOutStuff.Format( "     wFunc = %s;", csFunctionNum );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "     strcpy( szString, \"%s\" );", csString );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "     wLength = %s;", csStringLength );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "     wRetCode = %s;", csRetCode );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format("%s", " " );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "     IHLLAPI( &wFunc, pszString, &wLength, &wRetCode );"  );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format("%s", " " );
			pcsaBody->Add(csViewOutStuff);
		}

		
	}

	pcsaArguments->RemoveAll();


}

void CAG_IHL_CPP::finalize(CStringArray* pcsaBody)
{
	CString csLocal;

	if ( b_pUtilityBuffer )
	{
		csLocal.Format( "     free( pUtilityBuffer );");
		pcsaBody->Add(csLocal);
	}
	
	if ( b_pOIABuffer )
	{
		csLocal.Format( "     free( pOIABuffer );");
		pcsaBody->Add(csLocal);
	}

	csLocal.Format("%s", " " );
	pcsaBody->Add(csLocal);

	csLocal.Format("%s", "     return 1;" );
	pcsaBody->Add(csLocal);

	csLocal.Format("%s", " " );
	pcsaBody->Add(csLocal);

	csLocal.Format("%s", "}" );
	pcsaBody->Add(csLocal);

	csLocal.Format("%s", " " );
	pcsaBody->Add(csLocal);
}


void CAG_IHL_CPP::checkDebug(bool b_Debug,
									   CString csFunctionName,
									   CStringArray* pcsaBody)
{
	
}

void CAG_IHL_CPP::resetVariableFlags()
{
   b_pUtilityBuffer = FALSE;
   b_pOIABuffer = FALSE;
   bWHLLAPIDATA = FALSE;
   bnRetCode = FALSE;
   bOIA = FALSE;
}
