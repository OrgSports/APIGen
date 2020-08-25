// Static Model
#include "stdafx.h"
#include "apigen.h"

#include "CAG_EHL_XLS.h"

CAG_EHL_XLS::CAG_EHL_XLS()
{
	resetVariableFlags();	
}

CAG_EHL_XLS::~CAG_EHL_XLS()
{
	
}


void CAG_EHL_XLS::generateHeader(CStringArray* pcsaHeader,
								 CStringArray* pcsaBody)
{
	// output to Translator's output window
	CString csViewOutStuff;

	csViewOutStuff.Format( "' ****************************************************************************");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "'     Attachmate APIGen Excel EHLLAPI VBA Application");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "'" );
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "// This file is source code for a freestanding EHLLAPI program written in C++");
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

	csViewOutStuff.Format( "//  4) Open Excel and then load this file. It will run...");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "// ");
	pcsaHeader->Add(csViewOutStuff);

	time_t ltime;
	time( &ltime );

	csViewOutStuff.Format( "'");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "'   Generated:   %s", ctime( &ltime ) );
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "'");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "' ****************************************************************************");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "Declare Function HLLAPI Lib \"EHLAPI32.DLL\" (func%, ByVal Buffer$, bSize%, retc%) As Long");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "Sub TestOLE()" );
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "   " );
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "   Dim nFunc As Integer" );
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "   Dim cSession As String" );
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "   Dim pszString As String" );
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "   Dim nLength As Integer" );
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "   Dim nRetCode As Integer" );
	pcsaHeader->Add(csViewOutStuff);


	// start of body
	csViewOutStuff.Format( "" );
	pcsaBody->Add(csViewOutStuff);

}

void CAG_EHL_XLS::appendBody(int nFunctionNum,
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


	csViewOutStuff.Format( "     '*** Function: %s", csFunctionName );
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
			csViewOutStuff.Format( "     nFunc = %s", csFunctionNum );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "     cSession = \"%s\"", csString );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "     nLength = %s", csStringLength );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "     nRetCode = %s", csRetCode );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format(" " );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "     HLLAPI nFunc, cSession, nLength, nRetCode"  );
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
			csViewOutStuff.Format( "     nFunc = %s", csFunctionNum );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "     pszString = \"%s\"", csString );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "     nLength = %i", csString.GetLength() );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "     nRetCode = %s", csRetCode );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format(" " );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "     HLLAPI nFunc, pszString, nLength, nRetCode" );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format(" " );
			pcsaBody->Add(csViewOutStuff);

		}
		break;


		case 5:	// CopyPSToString
		case 8:	// CopyFieldToString
		{
			
			if ( !b_pUtilityBuffer )
			{
				b_pUtilityBuffer = TRUE;
				csViewOutStuff.Format( "Dim pUtilityBuffer As String");
				pcsaHeader->Add(csViewOutStuff);
			}

			csViewOutStuff.Format( "     nFunc = %s", csFunctionNum );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "     pUtilityBuffer = String( 1920 )" );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "     nLength = 1920" );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "     nRetCode = %s", csRetCode );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format("%s", " " );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "     HLLAPI nFunc, pUtilityBuffer, nLength, nRetCode" );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format(" " );
			pcsaBody->Add(csViewOutStuff);

		}
		break;


		case 10:
		{
			if ( !b_pUtilityBuffer )
			{
				b_pUtilityBuffer = TRUE;
				csViewOutStuff.Format( "Dim pUtilityBuffer As String");
				pcsaHeader->Add(csViewOutStuff);
			}

			csViewOutStuff.Format( "     nFunc = %s", csFunctionNum );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "     pUtilityBuffer = String( 312 )" );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "     nLength = 312" );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "     nRetCode = %s", csRetCode );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format("%s", " " );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "     HLLAPI nFunc, pUtilityBuffer, nLength, nRetCode;" );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format(" " );
			pcsaBody->Add(csViewOutStuff);

		}
		break;


		case 13:
		{
			if ( !b_pOIABuffer )
			{
				b_pOIABuffer = TRUE;
				csViewOutStuff.Format( "Dim pOIABuffer As String");
				pcsaHeader->Add(csViewOutStuff);
			}

			csViewOutStuff.Format( "     nFunc = %s", csFunctionNum );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "     pOIABuffer = String( 103 )" );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "     nLength = 103" );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "     nRetCode = %s", csRetCode );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format(" " );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "     HLLAPI nFunc, pOIABuffer, nLength, nRetCode" );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format(" " );
			pcsaBody->Add(csViewOutStuff);

		}
		break;


		case 20:	// QUERYSYSTEM
		{
			if ( !b_pUtilityBuffer )
			{
				b_pUtilityBuffer = TRUE;
				csViewOutStuff.Format( "Dim pUtilityBuffer As String");
				pcsaHeader->Add(csViewOutStuff);
			}

			
			csViewOutStuff.Format( "     nFunc = %s", csFunctionNum );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "     pUtilityBuffer = String( 35 )" );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "     nLength = 35" );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "     nRetCode = %s", csRetCode );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format(" " );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "     HLLAPI nFunc, pUtilityBuffer, nLength, nRetCode" );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format(" " );
			pcsaBody->Add(csViewOutStuff);

		}
		break;



		case 22:
		{
			if ( !b_pUtilityBuffer )
			{
				b_pUtilityBuffer = TRUE;
				csViewOutStuff.Format( "Dim pUtilityBuffer As String");
				pcsaHeader->Add(csViewOutStuff);
			}
			
			csViewOutStuff.Format( "     nFunc = %s", csFunctionNum );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "     pUtilityBuffer = String( 18 )" );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "     pUtilityBuffer[0] = '%s'", csString.Left(1) );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "     nLength = 18" );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "     nRetCode = %s", csRetCode );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format(" " );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "     HLLAPI nFunc, pUtilityBuffer, nLength, nRetCode" );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format(" " );
			pcsaBody->Add(csViewOutStuff);

		}
		break;


		case 23:	// STARTHOSTNOTIFICATION
		{
			csViewOutStuff.Format( "     nFunc = %s", csFunctionNum );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "     cSession = '%s'", csString );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "     nLength = 256" );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "     nRetCode = %s", csRetCode );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format("%s", " " );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "     HLLAPI nFunc, cSession, nLength, nRetCode" );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format(" " );
			pcsaBody->Add(csViewOutStuff);

		}
		break;


		case 34:
		{
			if ( !b_pUtilityBuffer )
			{
				b_pUtilityBuffer = TRUE;
				csViewOutStuff.Format( "Dim pUtilityBuffer As String");
				pcsaHeader->Add(csViewOutStuff);
			}
			
			csViewOutStuff.Format( "     nFunc = %s", csFunctionNum );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "     pUtilityBuffer = String( %i )", csString.GetLength()+1 );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "     pUtilityBuffer = \"%s\"", csString );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "     nLength = 256" );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "     nRetCode = %s", csRetCode );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format(" " );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "     HLLAPI nFunc, pUtilityBuffer, nLength, nRetCode" );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format(" " );
			pcsaBody->Add(csViewOutStuff);

		}
		break;


		case 50:
		{
			if ( !b_pUtilityBuffer )
			{
				b_pUtilityBuffer = TRUE;
				csViewOutStuff.Format( "Dim pUtilityBuffer As String");
				pcsaHeader->Add(csViewOutStuff);
			}
			
			csViewOutStuff.Format( "     nFunc = %s", csFunctionNum );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "     pUtilityBuffer = String( %i )", csString.GetLength()+1 );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "     pUtilityBuffer = \"%s\"", csString );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "     nLength = 256;" );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "     nRetCode = %s;", csRetCode );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format("%s", " " );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "     HLLAPI nFunc, pUtilityBuffer, nLength, nRetCode" );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format(" " );
			pcsaBody->Add(csViewOutStuff);

		}
		break;


		case 51:	// GETKEY
		{
			if ( !b_pUtilityBuffer )
			{
				b_pUtilityBuffer = TRUE;
				csViewOutStuff.Format( "Dim pUtilityBuffer As String");
				pcsaHeader->Add(csViewOutStuff);
			}
			
			csViewOutStuff.Format( "     nFunc = %s", csFunctionNum );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "     pUtilityBuffer = String( %i )", csString.GetLength()+1 );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "     pUtilityBuffer = \"%s\"", csString );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "     nLength = %s", csStringLength );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "     nRetCode = %s", csRetCode );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format("%s", " " );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "     HLLAPI nFunc, pUtilityBuffer, nLength, nRetCode" );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format(" " );
			pcsaBody->Add(csViewOutStuff);

		}
		break;



		default:
		{
			csViewOutStuff.Format( "     nFunc = %s", csFunctionNum );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "     szString = \"%s\"", csString );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "     nLength = %s", csStringLength );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "     nRetCode = %s", csRetCode );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format("%s", " " );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "     HLLAPI nFunc, pszString, nLength, nRetCode" );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format(" " );
			pcsaBody->Add(csViewOutStuff);

		}

		
	}

	pcsaArguments->RemoveAll();


}

void CAG_EHL_XLS::finalize(CStringArray* pcsaBody)
{
	CString csLocal;

	csLocal.Format("" );
	pcsaBody->Add(csLocal);

	csLocal.Format("End Sub" );
	pcsaBody->Add(csLocal);

}


void CAG_EHL_XLS::declareVariable(CListBox* agVariable,
								  CStringArray* pcsaHeader,
								  bool bValue)
{
	
}

void CAG_EHL_XLS::checkDebug(bool b_Debug,
									   CString csFunctionName,
									   CStringArray* pcsaBody)
{
	
}

void CAG_EHL_XLS::resetVariableFlags()
{
   b_pUtilityBuffer = FALSE;
   b_pOIABuffer = FALSE;
}
