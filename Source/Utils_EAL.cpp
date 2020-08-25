#include "stdafx.h"
#include "APIGen.h"
#include "APIGenDlg.h"

/****************************************************************************DC
	Function	:	CAPIGenDlg::LoadEALArgumentArray()

	Purpose		:	Load the function arguments for EAL.

*****************************************************************************/
void CAPIGenDlg::LoadEALArgumentArray( int* nFunctionPosition, BOOL bPromptForValues )
{
	CString	csFunctionName, csFunctionNum;
//	*nFunctionPosition=0;

	if ( bPromptForValues )
	{
		//TODO: Load the argument array from the UI controls
		// in the same way done below in the else-condition

		UpdateData();

		*nFunctionPosition = m_listTranslateFunction.GetCurSel();
		m_listTranslateFunction.GetText( *nFunctionPosition, csFunctionName );

		//csFunctionName = pcsaHeader->GetAt(1);
		int nSpacePlace = csFunctionName.Find(" ");
		
		// full function name text
		csaArguments.Add( csFunctionName );


		switch ( *nFunctionPosition )
		{

			case 9:		// ATMAllowUpdates
			case 10:	// ATMBlockUpdates
			case 14:	// ATMDisconnectSession
			case 16:	// ATMGetATMAPIVersion		// two arguments, but both outvalues
			case 18:	// ATMGetCursorLocation
			case 19:	// ATMGetEmulatorPath		// two arguments, but both outvalues
			case 20:	// ATMGetEmulatorVersion	// two arguments, but both outvalues
			case 21:	// ATMGetError				// two arguments, but both outvalues
			case 26:	// ATMGetLayoutName			// two arguments, but both outvalues
			case 30:	// ATMGetSessionSize
			case 34:	// ATMHoldHost
			case 36:	// ATMLockKeyboard
			case 41:	// ATMResetSystem
			case 42:	// ATMResumeHost
			case 52:	// ATMSessionOff
			case 53:	// ATMSessionOn
			case 56:	// ATMShowLastError
			case 60:	// ATMStopSession
			case 61:	// ATMUnlockKeyboard
			case 62:	// ATMUnregisterClient 
			case 63:	// ATMWait 
			{

			}
			break;

			case 17:	// ATMGetConnectionStatus
			{
				Read1L( &csaArguments );
			}
			break;


			case 11:	// ATMClearEventTable
			case 12:	// ATMConnectSession
			case 25:	// ATMGetKeystroke			// three arguments, but last two are outvalues
			case 27:	// ATMGetParameter
			case 28:	// ATMGetSessionHandle
			case 37:	// ATMOpenLayout
			case 38:	// ATMPause
			case 40:	// ATMRegisterClient
			case 49:	// ATMSendKey
			case 59:	// ATMStopKeystrokeIntercept
			case 65:	// ATMWaitForCursorMove
			case 67:	// ATMWaitForHostConnect
			case 68:	// ATMWaitForHostDisconnect
			{
				// argument 1
				Read1E( &csaArguments );
			}
			break;

			case 29:	// ATMGetSessions
			case 31:	// ATMGetSessionStatus
			case 43:	// ATMRowColumn
			case 58:	// ATMStartSession
			{
				Read1E1L( &csaArguments );
			}
			break;



			case 0:		// ATMAddWait
			case 2:		// ATMAddWaitForCursorMove
			case 3:		// ATMAddWaitForHostConnect
			case 4:		// ATMAddWaitForHostDisconnect
			case 13:	// ATMDeleteEvent
			case 15:	// ATMExecute
			case 32:	// ATMGetString				// four arguments, last two are outvalues
			case 33:	// ATMGetStringFromField	// four arguments, last two are outvalues
			case 39:	// ATMReceiveFile
			case 44:	// ATMRunEmulatorMacro
			case 48:	// ATMSendFile
			case 54:	// ATMSetCursorLocation
			case 57:	// ATMStartKeystrokeIntercept
			case 66:	// ATMWaitForEvent
			case 69:	// ATMWaitForKey
			case 71:	// ATMWaitHostQuiet
			{
				Read2E( &csaArguments );
			}
			break;

			case 35:	// ATMListSessions
			{
				Read2E1L( &csaArguments );
			}
			break;



			case 5:		// ATMAddWaitForKey
			case 8:		// ATMAddWaitHostQuiet
			case 45:	// ATMSearchField
			case 47:	// ATMSendAndWait
			case 50:	// ATMSendString
			case 51:	// ATMSendStringToField
			case 64:	// ATMWaitForCursor
			{
				Read3E( &csaArguments );			
			}
			break;

			case 22:	// ATMGetFieldInfo
			case 23:	// ATMGetFieldLength
			case 24:	// ATMGetFieldPosition
			{
				Read2E1L( &csaArguments );			
			}
			break;

			case 55:	// ATMSetParameter
			{
				Read1L2E( &csaArguments );			
			}
			break;

			case 46:	// ATMSearchSession
			{
				Read3E1L( &csaArguments );			
			}
			break;

			case 1:		// ATMAddWaitForCursor
			case 70:	// ATMWaitForString
			{
				Read4E( &csaArguments );			
			}
			break;

			case 6:		// ATMAddWaitForString
			case 7:		// ATMAddWaitForStringNotAt
			{
				Read5E( &csaArguments );			
			}
			break;

			default:
			{

			}
			break;

		}

	}
	else
	{
		*nFunctionPosition = m_listTranslateFunction.GetCurSel();
		m_listTranslateFunction.GetText( *nFunctionPosition, csFunctionName );

		//csFunctionName = pcsaHeader->GetAt(1);
//		int nSpacePlace = csFunctionName.Find(" ");
		
		// full function name text
		csaArguments.Add( csFunctionName );


		switch ( *nFunctionPosition )
		{
			case 0:		// ATMAddWait
			{
				csaArguments.Add("100");	// table
				csaArguments.Add("101");	// event
			}
			break;

			case 1:		// ATMAddWaitForCursor
			{
				csaArguments.Add("200");	// table
				csaArguments.Add("201");	// event
				csaArguments.Add("20");		// row
				csaArguments.Add("17");		// column
			}
			break;


			case 2:		// ATMAddWaitForCursorMove
			{
				csaArguments.Add("300");	// table
				csaArguments.Add("301");	// event
			}
			break;


			case 3:		// ATMAddWaitForHostConnect
			{
				csaArguments.Add("400");	// table
				csaArguments.Add("401");	// event
			}
			break;


			case 4:		// ATMAddWaitForHostDisconnect
			{
				csaArguments.Add("500");	// table
				csaArguments.Add("501");	// event
			}
			break;


			case 5:		// ATMAddWaitForKey
			{
				csaArguments.Add("600");	// table
				csaArguments.Add("601");	// event
				csaArguments.Add("@E");		// key
			}
			break;


			case 6:		// ATMAddWaitForString
			{
				csaArguments.Add("700");	// table
				csaArguments.Add("701");	// event
				csaArguments.Add("20");		// row
				csaArguments.Add("17");		// column
				csaArguments.Add("Ready:");		// wait string
			}
			break;


			case 7:		// ATMAddWaitForStringNotAt
			{
				csaArguments.Add("800");	// table
				csaArguments.Add("801");	// event
				csaArguments.Add("20");		// row
				csaArguments.Add("17");		// column
				csaArguments.Add("Ready:");		// wait string
			}
			break;

			
			case 8:		// ATMAddWaitHostQuiet
			{
				csaArguments.Add("900");	// table
				csaArguments.Add("901");	// event
				csaArguments.Add("2000");		// settle time
			}
			break;

			case 11:	// ATMClearEventTable
			{
				csaArguments.Add("tbl2");	// table
			}
			break;


			case 12:		// ATMConnectSession
			case 28:		// ATMGetSessionHandle
			case 59:		// ATMStopKeystrokeIntercept
			{
				csaArguments.Add("A");
			}
			break;



			case 9:		// ATMAllowUpdates
			case 10:	// ATMBlockUpdates
			case 13:	// ATMDeleteEvent
			case 14:	// ATMDisconnectSession
			case 18:	// ATMGetCursorLocation
			case 19:	// ATMGetEmulatorPath
			case 21:	// ATMGetError
			case 26:	// ATMGetLayoutName
			case 30:	// ATMGetSessionSize
			case 34:	// ATMHoldHost
			case 36:	// ATMLockKeyboard
			case 41:	// ATMResetSystem
			case 42:	// ATMResumeHost
			case 52:	// ATMSessionOff
			case 53:	// ATMSessionOn
			case 56:	// ATMShowLastError
			case 60:	// ATMStopSession
			case 61:	// ATMUnlockKeyboard
			case 62:	// ATMUnregisterClient
			case 63:	// ATMWait
			{
			}
			break;


			case 15:	// ATMExecute
			{
				csaArguments.Add("Hello.ebm");
				csaArguments.Add("3001");
			}
			break;

			case 17:	// ATMGetConnectionStatus
			{
				csaArguments.Add("ATM_XSTATUS");
				// ATM_CONNECTION
				// ATM_ERROR
			}
			break;

			
			case 22:	// ATMGetFieldInfo
			{
				csaArguments.Add("20");
				csaArguments.Add("17");
				csaArguments.Add("ATM_ISFIELDHIDDEN");
				// ATM_ISFIELDPROTECTED
				// ATM_ISFIELDNUMERIC
				// ATM_ISFIELDSELECTORPENDETECTABLE
				// ATM_ISFIELDBOLD
				// ATM_ISFIELDHIDDEN
				// ATM_ISFIELDMODIFIED
			}
			break;
			

			case 23:	// ATMGetFieldLength
			{
				csaArguments.Add("20");
				csaArguments.Add("17");
				csaArguments.Add("ATM_THISFIELD");
				// ATM_NEXTFIELD
				// ATM_PREVIOUSFIELD
				// ATM_NEXTPROTECTEDFIELD
				// ATM_NEXTUNPROTECTEDFIELD
				// ATM_PREVIOUSPROTECTED
				// ATM_PREVIOUSUNPROTECTED
			}
			break;

				
			case 24:	// ATMGetFieldPosition
			{
				csaArguments.Add("A");
			}
			break;
			

			case 27:	// ATMGetParameter
			{
				csaArguments.Add("ATM_ATTRIB");

				// ATM_ATTRIB
				// ATM_AUTORESET
				// ATM_CONNECTTYPE
				// ATM_EAB
				// ATM_PAUSE
				// ATM_SEARCHORG
				// ATM_SEARCHDIRECTION
				// ATM_TIMEOUT
				// ATM_TRACE
				// ATM_WAIT
				// ATM_XLATE
				// ATM_ESCAPE

			}
			break;


			case 29:	// ATMGetSessions
			{
				csaArguments.Add("286");				// length
				csaArguments.Add("ATM_GETCONFIGURED");	// sessionState
				// ATM_GETCONFIGURED
				// ATM_GETOPENED
				// ATM_GETPOWERED
				// ATM_GETCONFIGUREDCOUNT
				// ATM_GETOPENEDCOUNT
				// ATM_GETPOWEREDCOUNT
				// ATM_GETEMULATED
				// ATM_GETEMULATEDPOWERED
				// ATM_GETEMULATEDCOUNT
				// ATM_GETEMULATEDPOWEREDCOUNT
			}
			break;



			case 31:	// ATMGetSessionStatus
			{
				csaArguments.Add("A");
				csaArguments.Add("ATM_ISCONFIGURED");
				// ATM_ISCONFIGURED
				// ATM_ISOPENED
				// ATM_ISPOWERED
				// ATM_ISEMULATED
				// ATM_ISCONNECTED
				// ATM_ISFILETRANSFER

			}
			break;


			case 32:	// ATMGetString
			case 33:	// ATMGetStringFromField
			{
				csaArguments.Add("20");	// row
				csaArguments.Add("11");	// column
				csaArguments.Add("10");	// length

			}
			break;

			case 35:	// ATMListSessions
			{
				csaArguments.Add("312");	// row
				csaArguments.Add("APIGen List Sessions Demo");	// column
				csaArguments.Add("12");	// type
				// 1	configured
				// 2	open
				// 3	powered
				// 11	emulated
				// 12	emulated and powered

			}
			break;

			case 37:	// ATMOpenLayout
			{
				CString csTemp("c:\\program files\\Attachmate\\EXTRA!\\Sessions\\es9000.elf");
				//csTemp.Replace( "\\", "\\\\" );
				csaArguments.Add( csTemp );
			}
			break;

			case 38:	// ATMPause
			{
				csaArguments.Add( "2005" );
			}
			break;


			case 49:	// ATMSendKey
			{
				csaArguments.Add( "logon UserID@E" );
			}
			break;


			case 39:	// ATMReceiveFile
			case 48:	// ATMSendFile
			{
				CString csTemp("c:\\work files\\*.txt a: * txt");
				//csTemp.Replace( "\\", "\\\\" );
				csaArguments.Add( csTemp );
			}
			break;

			case 40:	// ATMRegisterClient
			{
				csaArguments.Add( "ATM_EXTRA" );
				// ATM_EXTRA
				// ATM_RALLY
				// ATM_KEA
				// ATM_IRMA
				// ATM_ICONN
				// ATM_HP

			}
			break;


			case 43:	// ATMRowColumn
			{
				csaArguments.Add( "1637" );
				csaArguments.Add( "ATM_GETROW" );
				// ATM_GETROW
				// ATM_GETCOLUMN
			}
			break;



			case 44:	// ATMRunEmulatorMacro
			{
				csaArguments.Add( "A" );
				CString csTemp("c:\\program files\\Attachmate\\EXTRA!\\Macros\\ENU\\Hello.ebm");
				//csTemp.Replace( "\\", "\\\\" );
				csaArguments.Add( csTemp );
			}
			break;


			
			case 45:	// ATMSearchField
				{
					csaArguments.Add( "1" );
					csaArguments.Add( "2" );
					csaArguments.Add( "SYSTEM 390" );
				}
				break;


			case 46:	// ATMSearchSession
				{
					csaArguments.Add( "1" );
					csaArguments.Add( "2" );
					csaArguments.Add( "CROSSROADS" );
					csaArguments.Add( "ATM_SEARCHALL" );
					// ATM_SEARCHALL
					// ATM_SEARCHFROM
					// ATM_SEARCHAT
					// ATM_SEARCHBACK

				}
				break;


			case 47:	// ATMSendAndWait
				{
					csaArguments.Add( "19" );
					csaArguments.Add( "2" );
					csaArguments.Add( "USERID" );
					csaArguments.Add( "Ready:" );
					csaArguments.Add( "6" );

				}
				break;



			case 50:	// ATMSendString
			case 51:	// ATMSendStringToField
			{
				csaArguments.Add( "20" );
				csaArguments.Add( "17" );
				csaArguments.Add( "USERID" );
			}
			break;

			
			case 54:	// ATMSetCursorLocation
			{
				csaArguments.Add( "21" );
				csaArguments.Add( "17" );
			}
			break;


			case 55:	// ATMSetParameter
			{
				csaArguments.Add("ATM_EAB");
				// ATM_ATTRIB
				// ATM_AUTORESET
				// ATM_CONNECTTYPE
				// ATM_EAB
				// ATM_PAUSE
				// ATM_SEARCHORG
				// ATM_SEARCHDIRECTION
				// ATM_TIMEOUT
				// ATM_TRACE
				// ATM_WAIT
				// ATM_XLATE
				// ATM_ESCAPE

				csaArguments.Add("1");
				csaArguments.Add("#");


			}
			break;


			case 57:	// ATMStartKeystrokeIntercept
			{
				csaArguments.Add("A");
				csaArguments.Add("HLL_INTERCEPTALLKEYS");
				// HLL_INTERCEPTAIDKEYS
				// HLL_INTERCEPTALLKEYS

			}
			break;


			case 58:	// ATMStartSession
			{
				csaArguments.Add("A");
				csaArguments.Add("H");

			}
			break;


			case 64:	// ATMWaitForCursor
			{
				csaArguments.Add("20");	// row
				csaArguments.Add("11");	// column
				csaArguments.Add("10");	// length
			}
			break;

			case 65:	// ATMWaitForCursorMove
			case 67:	// ATMWaitForHostConnect
			{
				csaArguments.Add("10");	// length
			}
			break;


			case 66:	// ATMWaitForEvent
			{
				csaArguments.Add("20");	// row
				csaArguments.Add("17");	// column
			}
			break;


			case 68:	// ATMWaitForHostDisconnect
			{
				csaArguments.Add("10");	// timeout
			}
			break;


			case 69:	// ATMWaitForKey
			{
				csaArguments.Add("@T");	// tab key
				csaArguments.Add("10");	// timeout
			}
			break;


			case 70:	// ATMWaitForString
			{
				csaArguments.Add("1");	// row
				csaArguments.Add("2");	// column
				csaArguments.Add("Ready:");	// wait for string
				csaArguments.Add("8");	// column
			}
			break;

			case 71:	// ATMWaitHostQuiet
			{
				csaArguments.Add("2000");
				csaArguments.Add("8");
			}
			break;

		}
		
	}
}



/****************************************************************************DC
	Function	:	CAPIGenDlg::ShowEALControls()

	Purpose		:	Show the controls for the EAL function parameters.

*****************************************************************************/
void CAPIGenDlg::ShowEALControls( int nFunction )
{
	HideParameterControls();
	csaLabels.RemoveAll();
	BOOL bYouShouldGo=TRUE;

	switch ( nFunction )
	{
		case 0:		// ATMAddWait
		case 2:		// ATMAddWaitForCursorMove
		case 3:		// ATMAddWaitForHostConnect
		case 4:		// ATMAddWaitForHostDisconnect
		case 13:	// ATMDeleteEvent
		{
			csaLabels.Add("Table name");
			csaLabels.Add("Event name");
		}
		break;

		case 1:		// ATMAddWaitForCursor
		{
			csaLabels.Add("Table name");
			csaLabels.Add("Event name");
			csaLabels.Add("Row");
			csaLabels.Add("Column");
		}
		break;

		case 5:		// ATMAddWaitForKey
		{
			csaLabels.Add("Table name");
			csaLabels.Add("Event name");
			csaLabels.Add("Key code");
		}
		break;

		case 6:		// ATMAddWaitForString
		case 7:		// ATMAddWaitForStringNotAt
		{
			csaLabels.Add("Table name");
			csaLabels.Add("Event name");
			csaLabels.Add("Row");
			csaLabels.Add("Column");
			csaLabels.Add("Wait string");
		}
		break;

		case 8:		// ATMAddWaitHostQuiet
		{
			csaLabels.Add("Table name");
			csaLabels.Add("Event name");
			csaLabels.Add("Settle time (ms)");
		}
		break;

		case 11:	// ATMClearEventTable
		{
			csaLabels.Add("Table ID");
		}
		break;

		case 12:	// ATMConnectSession
		{
			csaLabels.Add("Session ID");
		}
		break;

		case 15:	// ATMExecute
		{
			csaLabels.Add("Command string");
			csaLabels.Add("Timeout (sec/2)");
		}
		break;

		case 17:	// ATMGetConnectionStatus
		{
			csaLabels.Add("Status type");
			bYouShouldGo=FALSE;
		}
		break;

		case 22:	// ATMGetFieldInfo
		case 23:	// ATMGetFieldLength
		case 24:	// ATMGetFieldPosition
		{
			csaLabels.Add("Row");
			csaLabels.Add("Column");
			csaLabels.Add("Info type");
			bYouShouldGo=FALSE;
		}
		break;

		case 25:	// ATMGetKeystroke
		case 28:	// ATMGetSessionHandle
		{
			csaLabels.Add("Session ID");
		}
		break;

		case 27:	// ATMGetParameter
		{
			csaLabels.Add("Parameter index");
		}
		break;

		case 29:	// ATMGetSessions
		{
			csaLabels.Add("Session list length");
			csaLabels.Add("Session state");
			bYouShouldGo=FALSE;
		}
		break;

		case 31:	// ATMGetSessionStatus
		{
			csaLabels.Add("Session ID");
			csaLabels.Add("Session type");
			bYouShouldGo=FALSE;
		}
		break;

		case 32:	// ATMGetString
		case 33:	// ATMGetStringFromField
		{
			csaLabels.Add("Row");
			csaLabels.Add("Column");
		}
		break;

		case 35:	// ATMListSessions
		{
			csaLabels.Add("Length");
			csaLabels.Add("Title");
			csaLabels.Add("Status type");
			bYouShouldGo=FALSE;
		}
		break;

		case 37:	// ATMOpenLayout
		{
			csaLabels.Add("Layout file");
		}
		break;

		case 38:	// ATMPause
		{
			csaLabels.Add("Time delay (sec/2)");
		}
		break;

		case 39:	// ATMReceiveFile
		case 48:	// ATMSendFile
		{
			csaLabels.Add("FileTrans Command");
			csaLabels.Add("Size");
		}
		break;

		case 40:	// ATMRegisterClient
		{
			csaLabels.Add("Emulator type");
		}
		break;

		case 43:	// ATMRowColumn
		{
			csaLabels.Add("PS position");
			csaLabels.Add("Option");
			bYouShouldGo=FALSE;
		}
		break;

		case 44:	// ATMRunEmulatorMacro
		{
			csaLabels.Add("Session ID");
			csaLabels.Add("Macro name");
		}
		break;

		case 45:	// ATMSearchField
		{
			csaLabels.Add("Row");
			csaLabels.Add("Column");
			csaLabels.Add("Search string");
		}
		break;

		case 46:	// ATMSearchSession
		{
			csaLabels.Add("Row");
			csaLabels.Add("Column");
			csaLabels.Add("Search string");
			csaLabels.Add("Search option");
			bYouShouldGo=FALSE;
		}
		break;

		case 47:	// ATMSendAndWait
		case 50:	// ATMSendString
		case 51:	// ATMSendStringToField
		{
			csaLabels.Add("Row");
			csaLabels.Add("Column");
			csaLabels.Add("Send string");
		}
		break;

		case 49:	// ATMSendKey
		{
			csaLabels.Add("Send key");
		}
		break;

		case 54:	// ATMSetCursorLocation
		{
			csaLabels.Add("Row");
			csaLabels.Add("Column");
		}
		break;

		case 55:	// ATMSetParameter
		{
			csaLabels.Add("Parameter index");
			csaLabels.Add("Setting");
			csaLabels.Add("Escape char");
			bYouShouldGo=FALSE;
		}
		break;

		case 57:	// ATMStartKeystrokeIntercept
		{
			csaLabels.Add("Session ID");
			csaLabels.Add("Filter");
		}
		break;

		case 58:	// ATMStartSession
		{
			csaLabels.Add("Session ID");
			csaLabels.Add("Visibility");
			bYouShouldGo=FALSE;
		}
		break;

		case 59:	// ATMStopKeystrokeIntercept
		{
			csaLabels.Add("Session ID");
		}
		break;

		case 64:	// ATMWaitForCursor
		{
			csaLabels.Add("Row");
			csaLabels.Add("Column");
			csaLabels.Add("Timeout (sec/2)");
		}
		break;

		case 65:	// ATMWaitForCursorMove
		case 67:	// ATMWaitForHostConnect
		case 68:	// ATMWaitForHostDisconnect
		{
			csaLabels.Add("Wait time (sec/2)");
		}
		break;

		case 66:	// ATMWaitForEvent		//todo: this is KEA-only
		{
			csaLabels.Add("Table");
			csaLabels.Add("Timeout (sec/2)");
		}
		break;

		case 69:	// ATMWaitForKey
		{
			csaLabels.Add("Key");
			csaLabels.Add("Timeout (sec/2)");
		}
		break;

		case 70:	// ATMWaitForString
		{
			csaLabels.Add("Row");
			csaLabels.Add("Column");
			csaLabels.Add("Wait string");
			csaLabels.Add("Timeout (sec/2)");
		}
		break;

		case 71:	// ATMWaitHostQuiet
		{
			csaLabels.Add("Settle time (ms)");
			csaLabels.Add("Timeout (sec/2)");
		}
		break;


		case 9:		// ATMAllowUpdates
		case 10:	// ATMBlockUpdates
		case 14:	// ATMDisconnectSession
		case 16:	// ATMGetATMAPIVersion
		case 18:	// ATMGetCursorLocation
		case 19:	// ATMGetEmulatorPath
		case 20:	// ATMGetEmulatorVersion
		case 21:	// ATMGetError
		case 26:	// ATMGetLayoutName
		case 30:	// ATMGetSessionSize
		case 34:	// ATMHoldHost
		case 36:	// ATMLockKeyboard
		case 41:	// ATMResetSystem
		case 42:	// ATMResumeHost
		case 52:	// ATMSessionOff
		case 53:	// ATMSessionOn
		case 56:	// ATMShowLastError
		case 60:	// ATMStopSession
		case 61:	// ATMUnlockKeyboard
		case 62:	// ATMUnregisterClient
		case 63:	// ATMWait
		{
		}
		break;

	}
	
	if ( bYouShouldGo )
	{
		ShowEditControls( &csaLabels );
	}
	else
	{
		ShowMixedControls( EAL_API, nFunction, &csaLabels );	
	}

}



