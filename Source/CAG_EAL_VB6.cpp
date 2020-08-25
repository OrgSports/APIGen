// Static Model
#include "stdafx.h"
#include "apigen.h"

#include "CAG_EAL_VB6.h"


CAG_EAL_VB6::CAG_EAL_VB6()
{
	resetVariableFlags();	
}

CAG_EAL_VB6::~CAG_EAL_VB6()
{
	
}

void CAG_EAL_VB6::declareVariable(AG_VARIABLE agVariable,
								  CStringArray* pcsaHeader,
								  bool* bValue)
{
	
}

void CAG_EAL_VB6::checkDebug( bool b_Debug, CString csFunctionName, CStringArray* pcsaBody )
{

	
}

void CAG_EAL_VB6::generateHeader(CStringArray* pcsaHeader,
								 CStringArray* pcsaBody)
{
	// output to Translator's output window
	CString csViewOutStuff;
	pcsaHeader->Add("'****************************************************************************");
    pcsaHeader->Add("'");
    pcsaHeader->Add("'  Attachmate APIGEN recorded Enterprise Access Library (ATMAPI32.dll)");
    pcsaHeader->Add("'  test program for Visual Basic 6.0");
    pcsaHeader->Add("'");
    pcsaHeader->Add("'  Follow these steps to run this program:");
    pcsaHeader->Add("'      1. Create and save a new VB6 \"standard exe\" project.");
    pcsaHeader->Add("'      2. \"Add\" the atmapi32.bas file to the project.");
    pcsaHeader->Add("'      3. Place a command button on the form.");    
    pcsaHeader->Add("'      4. Copy this generated code to the \"OnClick\" event for the button.");
    pcsaHeader->Add("'      5. To view HLLAPI (Enterprise Access Library) return values, ");
    pcsaHeader->Add("'         start the EXTRA! \"Status\" utility and make sure it");
    pcsaHeader->Add("'         is active before running this program."); 
   	
	time_t ltime;
	time( &ltime );
	pcsaHeader->Add( "'");
	csViewOutStuff.Format( "'   Generated:   %s", ctime( &ltime ) );
	pcsaHeader->Add(csViewOutStuff);

	pcsaHeader->Add("'");	
	pcsaHeader->Add("'****************************************************************************");
    pcsaHeader->Add(" ");
    pcsaHeader->Add("   'Handle is a Long, declared in atmapi32.bas");
    pcsaHeader->Add("   Handle = Me.Hwnd");
    pcsaHeader->Add(" ");

}

void CAG_EAL_VB6::appendBody(int nFunctionNum,
							 bool bPromptForValues,
							 CStringArray* pcsaArguments,
							 CStringArray* pcsaHeader,
							 CStringArray* pcsaBody)
{
	CString csViewOutStuff;
	CString csFunctionName, csFunctionNum, csString, csStringLength, csRetCode;
	CString csLocal;

	csFunctionName = pcsaArguments->GetAt( 0 );
	csViewOutStuff.Format( "''''Function: %s", csFunctionName );
	pcsaBody->Add(csViewOutStuff);

	switch ( nFunctionNum )
	{
		case 0:		// ATMAddWait
		case 2:		// ATMAddWaitForCursorMove
		case 3:		// ATMAddWaitForHostConnect
		case 4:		// ATMAddWaitForHostDisconnect
		{
			
			csViewOutStuff.Format( "     nTable%% = %s", pcsaArguments->GetAt( 1 ) );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "     nEvent%% = %s", pcsaArguments->GetAt( 2 ) );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "     nRet%% = %s( Handle, nTable%%, nEvent%% )", csFunctionName );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( " ");
			pcsaBody->Add(csViewOutStuff);

		}
		break;

		case 1:		// ATMAddWaitForCursor
		{
			

			csViewOutStuff.Format( "     nTable%% = %s", pcsaArguments->GetAt( 1 ) );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "     nEvent%% = %s", pcsaArguments->GetAt( 2 ) );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "     nRow%% = %s", pcsaArguments->GetAt( 3 ) );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "     nColumn%% = %s", pcsaArguments->GetAt( 4 ) );
			pcsaBody->Add(csViewOutStuff);


			csViewOutStuff.Format( "     nRet%% = %s( Handle, nTable%%, nEvent%%, nRow%%, nColumn%% )", csFunctionName );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( " ");
			pcsaBody->Add(csViewOutStuff);

		}
		break;


		case 5:		// ATMAddWaitForKey
		{
			
			
			csViewOutStuff.Format( "     nTable%% = %s", pcsaArguments->GetAt( 1 ) );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "     nEvent%% = %s", pcsaArguments->GetAt( 2 ) );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "     Buffer$ = \"%s\"", pcsaArguments->GetAt( 3 ));
			pcsaBody->Add(csViewOutStuff);			

			csViewOutStuff.Format( "     nRet%% = %s( Handle, nTable%%, nEvent%%, Buffer$ )", csFunctionName );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( " ");
			pcsaBody->Add(csViewOutStuff);

		}
		break;


		case 6:		// ATMAddWaitForString
		case 7:		// ATMAddWaitForStringNotAt
		{
			

			csViewOutStuff.Format( "     nTable%% = %s", pcsaArguments->GetAt( 1 ) );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "     nEvent%% = %s", pcsaArguments->GetAt( 2 ) );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "     nRow%% = %s", pcsaArguments->GetAt( 3 ) );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "     nColumn%% = %s", pcsaArguments->GetAt( 4 ) );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "     Buffer$ = \"%s\"", pcsaArguments->GetAt( 5 ));

			csViewOutStuff.Format( "     nRet%% = %s( Handle, nTable%%, nEvent%%, nRow%%, nColumn%%, Buffer$ )", csFunctionName );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( " ");
			pcsaBody->Add(csViewOutStuff);

		}
		break;



		case 8:		// ATMAddWaitHostQuiet
		{
			


			csViewOutStuff.Format( "     nTable%% = %s", pcsaArguments->GetAt( 1 ) );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "     nEvent%% = %s", pcsaArguments->GetAt( 2 ) );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "     nSettleTime%% = %s", pcsaArguments->GetAt( 3 ) );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "     nRet%% = %s( Handle, nTable%%, nEvent%%, nSettleTime%% )", csFunctionName );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( " ");
			pcsaBody->Add(csViewOutStuff);

		}
		break;



		case 14:	// ATMDeleteEvent
		{
			
			csViewOutStuff.Format( "     nTable%% = %s", pcsaArguments->GetAt( 1 ) );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "     nEvent%% = %s", pcsaArguments->GetAt( 2 ) );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "     nRet%% = %s( Handle, nTable%%, nEvent%% )", csFunctionName );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( " ");
			pcsaBody->Add(csViewOutStuff);

		}
		break;


		case 9:		// ATMAllowUpdates
		case 10:	// ATMBlockUpdates
		case 12:	// ATMCloseConfiguration
		case 15:	// ATMDisconnectSession
		case 34:	// ATMGetSessionSize
		case 38:	// ATMHoldHost
		case 40:	// ATMLockKeyboard
		case 46:	// ATMResetSystem
		case 47:	// ATMResumeHost
		case 58:	// ATMSessionOff
		case 59:	// ATMSessionOn
		case 62:	// ATMShowLastError
		case 66:	// ATMStopSession
		case 67:	// ATMUnlockKeyboard
		case 68:	// ATMUnregisterClient
		case 69:	// ATMWait
		{
						
			
			csViewOutStuff.Format( "     nRet%% = %s( Handle )", csFunctionName );
			pcsaBody->Add(csViewOutStuff);
			csViewOutStuff.Format( " ");
			pcsaBody->Add(csViewOutStuff);
		}
		break;


		case 13:		// ATMConnectSession
		case 32:		// ATMGetSessionHandle
		case 65:		// ATMStopKeystrokeIntercept
		{
			

			csViewOutStuff.Format( "     cSession$ = \"%s\"", pcsaArguments->GetAt( 1 ) );
			pcsaBody->Add(csViewOutStuff);
			csViewOutStuff.Format( "     nRet%% = %s( Handle, cSession$ )", csFunctionName );
			pcsaBody->Add(csViewOutStuff);
			csViewOutStuff.Format( " ");
			pcsaBody->Add(csViewOutStuff);
		}
		break;


		case 16:		// ATMExecute
		{

			


			csViewOutStuff.Format( "     Buffer$ = \"%s\"", pcsaArguments->GetAt( 1 ) );
			pcsaBody->Add(csViewOutStuff);
			

			csViewOutStuff.Format( "     nTimeout%% = %s", pcsaArguments->GetAt( 2 ) );
			pcsaBody->Add(csViewOutStuff);


			csViewOutStuff.Format( "     nRet = %s( Handle, Buffer, nTimeout%% )", csFunctionName );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( " ");
			pcsaBody->Add(csViewOutStuff);

		}
		break;

		case 17:		// ATMGetATMAPIVersion
		{
			


			csViewOutStuff.Format( "%s", "     nLength%% = 6");
			pcsaBody->Add(csViewOutStuff);
			csViewOutStuff.Format( "%s", "     Buffer$ = Space(6)");
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "     nRet%% = %s(Buffer$, nLength%% )", csFunctionName );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( " ");
			pcsaBody->Add(csViewOutStuff);

		}
		break;

		
		case 18:	// ATMGetConfiguration
		case 21:	// ATMGetEmulatorPath
		case 23:	// ATMGetError
		case 24:	// ATMGetEXTRAPath
		case 25:	// ATMGetEXTRAVersion
		case 30:	// ATMGetLayoutName
		{
			

			csViewOutStuff.Format( "%s", "     nLength%% = 512");
			pcsaBody->Add(csViewOutStuff);
			csViewOutStuff.Format( "%s", "     Buffer$ = Space(512)");
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "%s%s%s", "     nRet%% = ", csFunctionName, "( Handle, Buffer$, nLength%% )");
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( " ");
			pcsaBody->Add(csViewOutStuff);

		}
		break;



		case 19:		// ATMGetConnectionStatus
		{
			

			csViewOutStuff.Format( "     nType%% = %s", pcsaArguments->GetAt( 1 ) );
			pcsaBody->Add(csViewOutStuff);
			
			csViewOutStuff.Format( "     nRet%% = %s( Handle, nType%% )", csFunctionName );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( " ");
			pcsaBody->Add(csViewOutStuff);
		}
		break;

		case 20:	// ATMGetCursorLocation
		{
			

			csViewOutStuff.Format( "     nRet%% = %s( Handle )", csFunctionName );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( " ");
			pcsaBody->Add(csViewOutStuff);

		}
		break;

		case 22:	// ATMGetEmulatorVersion
		{
			


			csViewOutStuff.Format( "%s", "     nLength%% = 6;");
			pcsaBody->Add(csViewOutStuff);
			csViewOutStuff.Format( "%s", "     Buffer = Space(6)");
			pcsaBody->Add(csViewOutStuff);


			csViewOutStuff.Format( "     nRet%% = %s( Handle, Buffer$, nLength%% )", csFunctionName );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( " ");
			pcsaBody->Add(csViewOutStuff);

		}
		break;


		case 26:	// ATMGetFieldInfo
		case 27:	// ATMGetFieldLength
		case 28:	// ATMGetFieldPosition
		{
			

			csViewOutStuff.Format( "     nRow%% = %s", pcsaArguments->GetAt( 1 ) );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "     nColumn%% = %s", pcsaArguments->GetAt( 2 ) );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "     nType%% = %s", pcsaArguments->GetAt( 3 ) );
			pcsaBody->Add(csViewOutStuff);


			csViewOutStuff.Format( "     nRet%% = %s( Handle, nRow%%, nColumn%%, nType%% )", csFunctionName );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( " ");
			pcsaBody->Add(csViewOutStuff);
		}
		break;


		case 29:	// ATMGetKeyStroke
		{
			
			csViewOutStuff.Format( "     cSession$ = \"%s\"", pcsaArguments->GetAt( 1 ) );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "     nLength%% = %s", "512" );
			pcsaBody->Add(csViewOutStuff);
			csViewOutStuff.Format( "%s", "     Buffer$ = Space(512)");
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "     nRet%% = %s( Handle, cSession$, Buffer$, nLength%% )", csFunctionName );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( " ");
			pcsaBody->Add(csViewOutStuff);

		}
		break;
			

		case 31:	// ATMGetParameter
		{
			

			csViewOutStuff.Format( "     nIndex%% = %s", pcsaArguments->GetAt( 1 ) );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "     nRet%% = %s( Handle, nIndex%% )", csFunctionName );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( " ");
			pcsaBody->Add(csViewOutStuff);
		}
		break;


		case 33:	// ATMGetSessions
		{
			

			csViewOutStuff.Format( "     nLength%% = %s", pcsaArguments->GetAt( 1 ) );
			pcsaBody->Add(csViewOutStuff);
			csViewOutStuff.Format( "     Buffer% = Space( nLength%% + 1 )");
			pcsaBody->Add(csViewOutStuff);
			csViewOutStuff.Format( "     nSessState%% = %s", pcsaArguments->GetAt( 2 ) );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "     nRet%% = %s( Handle, Buffer$, nLength%%, nSessState%% )", csFunctionName );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( " ");
			pcsaBody->Add(csViewOutStuff);

		}
		break;


		case 35:	// ATMGetSessionStatus
		case 63:	// ATMStartKeystrokeIntercept
		{			

			csViewOutStuff.Format( "     cSession$ = \"%s\"", pcsaArguments->GetAt( 1 ) );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "     nType%% = %s", pcsaArguments->GetAt( 2 ) );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "     nRet = %s( Handle, cSession$, nType%% )", csFunctionName );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( " ");
			pcsaBody->Add(csViewOutStuff);
		}
		break;


		case 36:	// ATMGetString
		case 37:	// ATMGetStringFromField
		{
			

			csViewOutStuff.Format( "     nRow%% = %s", pcsaArguments->GetAt( 1 ) );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "     nColumn%% = %s", pcsaArguments->GetAt( 2 ) );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "     nLength%% = %s", pcsaArguments->GetAt( 3 ) );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "%s", "     Buffer$ = Space( nLength%% + 1 )");
			pcsaBody->Add(csViewOutStuff);


			csViewOutStuff.Format( "     nRet%% = %s( Handle, nRow%%, nColumn%%, Buffer$, nLength%% )", csFunctionName );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( " ");
			pcsaBody->Add(csViewOutStuff);

		}
		break;


		case 39:	// ATMListSessions
		{
			
			csViewOutStuff.Format( "     nLength%% = %s", pcsaArguments->GetAt( 1 ) );
			pcsaBody->Add(csViewOutStuff);
			csViewOutStuff.Format( "     Title$ =  \"%s\"", pcsaArguments->GetAt( 2 )  );
			pcsaBody->Add(csViewOutStuff);
			
			csViewOutStuff.Format( "     nType%% = %s", pcsaArguments->GetAt( 3 ) );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "%s", "     Buffer = Space( nLength%% + 1 )");
			pcsaBody->Add(csViewOutStuff);


			csViewOutStuff.Format( "     nRet%% = %s( Handle, Buffer$, nLength%%, Title$, nType%% )", csFunctionName );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( " ");
			pcsaBody->Add(csViewOutStuff);

		}
		break;


		case 41:	// ATMOpenConfiguration
		case 42:	// ATMOpenLayout
		case 55:	// ATMSendKey
		{
			


			csViewOutStuff.Format( "     Buffer$ = \"%s\"", pcsaArguments->GetAt( 1 ));
			pcsaBody->Add(csViewOutStuff);
						

			csViewOutStuff.Format( "     nRet%% = %s( Handle, Buffer$ )", csFunctionName );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( " ");
			pcsaBody->Add(csViewOutStuff);

		}
		break;


		case 43:	// ATMPause
		{
			

			csViewOutStuff.Format( "     nPauseTime%% = %s", pcsaArguments->GetAt( 1 ) );
			pcsaBody->Add(csViewOutStuff);
			
			csViewOutStuff.Format( "     nRet%% = %s( Handle, nPauseTime%% )", csFunctionName );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( " ");
			pcsaBody->Add(csViewOutStuff);
		}
		break;

		case 44:	// ATMReceiveFile
		{					


			csViewOutStuff.Format( "     nLength%% = %i", (pcsaArguments->GetAt( 1 )).GetLength()+1 );
			pcsaBody->Add(csViewOutStuff);
			csViewOutStuff.Format( "     Buffer$ = \"%s\"", pcsaArguments->GetAt( 1 ));
			pcsaBody->Add(csViewOutStuff);
			

			csViewOutStuff.Format( "     nRet%% = %s( Handle, Buffer$, nLength%% )", csFunctionName );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( " ");
			pcsaBody->Add(csViewOutStuff);

		}
		break;

		
		case 45:		// ATMRegisterClient
		{
		

			csViewOutStuff.Format( "     nType%% = %s", pcsaArguments->GetAt( 1 ) );
			pcsaBody->Add(csViewOutStuff);
			
			csViewOutStuff.Format( "     nRet%% = %s( Handle, nType%% )", csFunctionName );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( " ");
			pcsaBody->Add(csViewOutStuff);
		}
		break;


		case 48:	// ATMRowColumn
		{
			

			csViewOutStuff.Format( "     nPosition%% = %s", pcsaArguments->GetAt( 1 ) );
			pcsaBody->Add(csViewOutStuff);
			
			csViewOutStuff.Format( "     nOption%% = %s;", pcsaArguments->GetAt( 2 ) );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "     nRet%% = %s( Handle, nPosition%%, nOption%% )", csFunctionName );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( " ");
			pcsaBody->Add(csViewOutStuff);
		}
		break;


		case 49:	// ATMRunEmulatorMacro
		case 50:	// ATMRunExtraMacro
		{
			

			csViewOutStuff.Format( "     cSession$ = \"%s\"", pcsaArguments->GetAt( 1 ) );
			pcsaBody->Add(csLocal);

			csViewOutStuff.Format( "     Buffer$ = \"%s\"", pcsaArguments->GetAt( 2 ) );
			pcsaBody->Add(csViewOutStuff);
			
			
			csViewOutStuff.Format( "     nRet%% = %s( Handle, cSession$, Buffer$ )", csFunctionName );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( " ");
			pcsaBody->Add(csViewOutStuff);

		}
		break;

		case 51:	// ATMSearchField
		case 56:	// ATMSendString
		case 57:	// ATMSendStringToField
		{
			



			csViewOutStuff.Format( "     nRow%% = %s", pcsaArguments->GetAt( 1 ) );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "     nColumn%% = %s", pcsaArguments->GetAt( 2 ) );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "     Buffer = \"%s\"", pcsaArguments->GetAt( 3 ));
			pcsaBody->Add(csViewOutStuff);

			
			csViewOutStuff.Format( "     nRet%% = %s( Handle, nRow%%, nColum%%n, Buffer$ )", csFunctionName );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( " ");
			pcsaBody->Add(csViewOutStuff);

		}
		break;


		case 52:	// ATMSearchSession
		{
						

			csViewOutStuff.Format( "     nRow%% = %s", pcsaArguments->GetAt( 1 ) );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "     nColumn%% = %s", pcsaArguments->GetAt( 2 ) );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "     Buffer$ = \"%s\"", pcsaArguments->GetAt( 3 ) );
			pcsaBody->Add(csViewOutStuff);
			
			csViewOutStuff.Format( "     nOption%% = %s", pcsaArguments->GetAt( 4 ) );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "     nRet = %s( Handle, nRow%%, nColumn%%, Buffer$, nOption%% )", csFunctionName );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( " ");
			pcsaBody->Add(csViewOutStuff);

		}
		break;


		case 53:	// ATMSendAndWait
		{
			

			csViewOutStuff.Format( "     nRow%% = %s", pcsaArguments->GetAt( 1 ) );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "     nColumn%% = %s", pcsaArguments->GetAt( 2 ) );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "     Buffer$ = \"%s\"", pcsaArguments->GetAt( 3 ) );
			pcsaBody->Add(csViewOutStuff);
			
			csViewOutStuff.Format( "     WaitForBuffer$ = \"%s\"", pcsaArguments->GetAt( 4 ) );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "     nTimeout%% = %s", pcsaArguments->GetAt( 5 ) );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "     nRet%% = %s( Handle, nRow%%, nColumn%%, Buffer$, WaitForBuffer$, nTimeout%% )", csFunctionName );
			pcsaBody->Add(csViewOutStuff);

            csViewOutStuff.Format( " ");
			pcsaBody->Add(csViewOutStuff);

		}
		break;


		case 54:	// ATMSendFile
		{
			
			csViewOutStuff.Format( "     nLength%% = %i", (pcsaArguments->GetAt( 1 )).GetLength()+1 );
			pcsaBody->Add(csViewOutStuff);
			csViewOutStuff.Format( "     Buffer$ =  \"%s\"", pcsaArguments->GetAt( 1 ));
			pcsaBody->Add(csViewOutStuff);
			
			csViewOutStuff.Format( "     nRet%% = %s( Handle, Buffer$, nLength%% )", csFunctionName );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( " ");
			pcsaBody->Add(csViewOutStuff);

		}
		break;


		case 60:	// ATMSetCursorLocation
		{
			

			csViewOutStuff.Format( "     nRow%% = %s", pcsaArguments->GetAt( 1 ) );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "     nColumn%% = %s", pcsaArguments->GetAt( 2 ) );
			pcsaBody->Add(csViewOutStuff);


			csViewOutStuff.Format( "     nRet%% = %s( Handle, nRow%%, nColumn%% )", csFunctionName );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( " ");
			pcsaBody->Add(csViewOutStuff);
		}
		break;


		case 61:	// ATMSetParameter
		{
			

			csViewOutStuff.Format( "     nIndex%% = %s", pcsaArguments->GetAt( 1 ) );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "     nSetting%% = %s", pcsaArguments->GetAt( 2 ) );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "     cEscape$ = \"%s\"", pcsaArguments->GetAt( 3 ) );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "     nRet%% = %s( Handle, nIndex%%, nSetting%%, cEscape$ )", csFunctionName );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( " ");
			pcsaBody->Add(csViewOutStuff);
		}
		break;



		case 64:	// ATMStartSession
		{
			


			csViewOutStuff.Format( "     cSession$ = \"%s\"", pcsaArguments->GetAt( 1 ) );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "     Buffer$ = \"%s\"", pcsaArguments->GetAt( 2 ));
			pcsaBody->Add(csViewOutStuff);
			
			csViewOutStuff.Format( "     nRet = %s( Handle, cSession$, Buffer$ )", csFunctionName );
			pcsaBody->Add(csViewOutStuff);

		}
		break;


		case 70:	// ATMWaitForCursor
		{
			

			csViewOutStuff.Format( "     nRow%% = %s", pcsaArguments->GetAt( 1 ) );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "     nColumn%% = %s", pcsaArguments->GetAt( 2 ) );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "     nTimeout%% = %s", pcsaArguments->GetAt( 3 ) );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "     nRet%% = %s( Handle, nRow%%, nColumn%%, nTimeout%% )", csFunctionName );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( " ");
			pcsaBody->Add(csViewOutStuff);
		}
		break;



		case 71:	// ATMWaitForCursorMove
		case 73:	// ATMWaitForHostConnect
		case 74:	// ATMWaitForHostDisconnect
		{
			

			csViewOutStuff.Format( "     nTimeout%% = %s", pcsaArguments->GetAt( 1 ) );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "     nRet%% = %s( Handle, nTimeout%% )", csFunctionName );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( " ");
			pcsaBody->Add(csViewOutStuff);
		}
		break;


		case 72:	// ATMWaitForEvent
		{			


			csViewOutStuff.Format( "     nTable%% = %s", pcsaArguments->GetAt( 1 ) );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "     nTimeout%% = %s", pcsaArguments->GetAt( 2 ) );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "     nRet%% = %s( Handle, nTable%%, nTimeout%% )", csFunctionName );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( " ");
			pcsaBody->Add(csViewOutStuff);

		}
		break;


		case 75:	// ATMWaitForKey
		{
			
			csViewOutStuff.Format( "     Buffer$ = \"%s\"", pcsaArguments->GetAt( 1 ));
			pcsaBody->Add(csViewOutStuff);
			
			csViewOutStuff.Format( "     nTimeout%% = %s", pcsaArguments->GetAt( 2 ) );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "     nRet%% = %s( Handle, Buffer$, nTimeout%% )", csFunctionName );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( " ");
			pcsaBody->Add(csViewOutStuff);

		}
		break;


		case 76:	// ATMWaitForString
		{
			
			


			csViewOutStuff.Format( "     nRow%% = %s", pcsaArguments->GetAt( 1 ) );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "     nColumn%% = %s", pcsaArguments->GetAt( 2 ) );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "     Buffer$ = \"%s\"", pcsaArguments->GetAt( 3 ) );
			pcsaBody->Add(csViewOutStuff);
			
			csViewOutStuff.Format( "     nTimeout%% = %s", pcsaArguments->GetAt( 4 ) );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "     nRet%% = %s( Handle, nRow%%, nColumn%%, Buffer$, nTimeout%% )", csFunctionName );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( " ");
			pcsaBody->Add(csViewOutStuff);

		}
		break;



		case 77:	// ATMWaitHostQuiet
		{
			

			csViewOutStuff.Format( "     nSettleTime%% = %s", pcsaArguments->GetAt( 1 ) );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "     nTimeout%% = %s", pcsaArguments->GetAt( 2 ) );
			pcsaBody->Add(csViewOutStuff);


			csViewOutStuff.Format( "     nRet%% = %s( Handle, nSettleTime%%, nTimeout%% )", csFunctionName );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( " ");
			pcsaBody->Add(csViewOutStuff);
		}
		break;


		default:
		{
			csViewOutStuff.Format( "%s%i%s", "//     Function ", nFunctionNum, ". Abandon hope, all ye who enter here.  ");
			pcsaBody->Add(csViewOutStuff);
		}
		
	}

	pcsaArguments->RemoveAll();

}

void CAG_EAL_VB6::finalize(CStringArray* pcsaBody)
{
	//nothing here - end user will copy generated code to a pre-existing button onclick handler
}

void CAG_EAL_VB6::resetVariableFlags()
{
}