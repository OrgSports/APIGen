#include "stdafx.h"
#include "APIGen.h"
#include "APIGenDlg.h"

/****************************************************************************DC
	Function	:	CAPIGenDlg::LoadCICSNETArgumentArray()

	Purpose		:	Load the function arguments for CICS Bridge QACom Automation.

*****************************************************************************/
void CAPIGenDlg::LoadCICSNETArgumentArray( int* nFunctionPosition, BOOL bPromptForValues )
{
	CString	csFunctionName, csFunctionNum;
	
	UpdateData();
	
	*nFunctionPosition=0;

	*nFunctionPosition = m_listTranslateFunction.GetCurSel();
	m_listTranslateFunction.GetText( *nFunctionPosition, csFunctionName );

	// full function name text
	csaArguments.Add( csFunctionName );

	if ( bPromptForValues )
	{
		switch ( *nFunctionPosition )
		{
			case 28:	// SetTraceInactive
			case 30:	// Terminate
			{
			}
			break;

			case 0:		// ChangePassword
			{
				Read5E( &csaArguments );
			}
			break;

			case 1:	// ConnectBridge
			{
				Read2E1L5E( &csaArguments );
			}
			break;

			case 3:		// FindString
			{
				Read4E1L( &csaArguments );
			}
			break;

			case 16:	// Initialize
			{
				Read1L( &csaArguments );
			}
			break;

			case 4:		// GetAllFieldInformation
			case 6:		// GetCurrentScreenName
			case 10:	// GetFieldCount
			case 13:	// GetScreenSize
			case 17:	// Pause
			case 19:	// SendKeys
			case 20:	// SendKeysEx
			case 21:	// SendKeysGetAllFieldInformation
			case 25:	// SetSettleTime
			case 26:	// SetTimeOut
			case 27:	// SetTraceActive
			case 29:	// SetTraceName
			{
				Read1E( &csaArguments );
			}
			break;

			case 8:		// GetFieldAttributes
			case 9:		// GetFieldCoordinates
			case 11:	// GetFieldNameFromIndex
			case 12:	// GetFieldValue
			case 23:	// SetCursorPosition
			case 24:	// SetFieldValue
			{
				Read2E( &csaArguments );
			}
			break;

			case 15:	// GetTransactionSystemId
			case 18:	// PutString
			{
				Read3E( &csaArguments );
			}
			break;

			case 14:	// GetString
			case 22:	// SendKeysGetString
			{
				Read4E( &csaArguments );
			}
			break;

			default:
			{
				csaArguments.Add( "DANGER" );
				csaArguments.Add( "DANGER" );
				csaArguments.Add( "BIG" );
				csaArguments.Add( "PROBLEMS" );
				csaArguments.Add( "LIE" );
				csaArguments.Add( "AHEAD" );
			}
			break;

		}
	}	
	else
	{
		switch ( *nFunctionPosition )
		{
			case 0:		// ChangePassword
			{
				// host IP
				csaArguments.Add( "149.2.23.21" );

				// host port
				csaArguments.Add( "83" );

				// user ID
				csaArguments.Add( "jamesdean" );

				// password
				csaArguments.Add( "spyder90" );

				// new password
				csaArguments.Add( "toofast" );

			}
			break;

			case 1:		// ConnectBridge
			{
				// host IP
				csaArguments.Add( "149.2.23.21" );

				// host port
				csaArguments.Add( "83" );

				// terminal model
				csaArguments.Add( "2" );

				// user ID
				csaArguments.Add( "rutherfordbhayes" );

				// password
				csaArguments.Add( "1878-82" );
			}
			break;

			case 2:		// Disconnect
			case 28:	// SetTraceInactive
			case 30:	// Terminate
			{

			}
			break;

			case 3:		// FindString
			{
				// in screen
				csaArguments.Add( "-1" );

				// in string
				csaArguments.Add( "Ready" );

				// start row
				csaArguments.Add( "17" );

				// start column
				csaArguments.Add( "6" );

				// in flags
				csaArguments.Add( "12" );
			}
			break;

			case 4:		// GetAllFieldInformation
			{
				// in screen
				csaArguments.Add( "" );
			}
			break;

			case 5:		// GetConnectionStatus
			{
				// out status
				csaArguments.Add( "" );
			}
			break;

			case 6:		// GetCurrentScreenName
			{
				// timeout
				csaArguments.Add( "0" );
			}
			break;

			case 7:		// GetCursorPosition
			{
				// out row
				csaArguments.Add( "" );

				// out column
				csaArguments.Add( "" );
			}
			break;

			case 8:		// GetFieldAttributes
			{
				// in screen
				csaArguments.Add( "-1" );

				// in field
				csaArguments.Add( "totalField" );
			}
			break;

			case 9:	// GetFieldCoordinates
			{
				// in screen
				csaArguments.Add( "-1" );

				// in field
				csaArguments.Add( "totalField" );
			}
			break;

			case 10:	// GetFieldCount
			{
				// in screen
				csaArguments.Add( "" );
			}
			break;

			case 11:	// GetFieldNameFromIndex
			{
				// in screen
				csaArguments.Add( "-1" );

				// in field index
				csaArguments.Add( "9" );
			}
			break;

			case 12:	// GetFieldValue
			{
				// in screen
				csaArguments.Add( "-1" );

				// in field name
				csaArguments.Add( "net" );
			}
			break;

			case 13:	// GetScreenSize
			{
				// in screen
				csaArguments.Add( "-1" );
			}
			break;

			case 14:	// GetString
			{
				// in screen
				csaArguments.Add( "" );
				// row
				csaArguments.Add( "16" );
				// column
				csaArguments.Add( "7" );
				// length
				csaArguments.Add( "8" );
			}
			break;

			case 15:	// GetTransactionSystemId
			{
				// host IP
				csaArguments.Add( "149.82.13.6" );
				// host port
				csaArguments.Add( "65" );
				// transaction
				csaArguments.Add( "CHDR" );
			}
			break;

			case 16:	// Initialize
			{
				// terminal type
				csaArguments.Add( "3" );
			}
			break;

			case 17:	// Pause
			{
				// pause (ms)
				csaArguments.Add( "3000" );
			}
			break;

			case 18:	// PutString
			{
				// text to write
				csaArguments.Add( "IND$FILE PUT" );
				// row
				csaArguments.Add( "1" );
				// column
				csaArguments.Add( "1" );
			}
			break;

			case 19:	// SendKeys
			{
				// text to write
				csaArguments.Add( "logon user49er@E" );
			}
			break;

			case 20:	// SendKeysEx
			{
				// text to write
				csaArguments.Add( "logon user21er@E" );
			}
			break;

			case 21:	// SendKeysGetAllFieldInformation
			{
				// in keys
				csaArguments.Add( "rhubarbio@E" );
			}
			break;

			case 22:	// SendKeysGetString
			{
				// in keys
				csaArguments.Add( "tomateo@E" );

				// rows
				csaArguments.Add( "14" );
		
				// cols
				csaArguments.Add( "62" );

				// length
				csaArguments.Add( "16" );
			}
			break;

			case 23:	// SetCursorPosition
			{
				// row
				csaArguments.Add( "14" );
		
				// col
				csaArguments.Add( "62" );
			}
			break;

			case 24:	// SetFieldValue
			{
				// in field
				csaArguments.Add( "field3" );
				// value
				csaArguments.Add( "E3" );
			}
			break;

			case 25:	// SetSettleTime
			{
				// settle time (ms)
				csaArguments.Add( "3200" );
			}
			break;

			case 26:	// SetTimeOut
			{
				// timeout length (ms)
				csaArguments.Add( "2300" );
			}
			break;

			case 27:	// SetTraceActive
			{
				// cics temporary storage queue
				csaArguments.Add( "TSQ11" );
			}
			break;

			case 29:	// SetTraceName
			{
				// cics temporary storage queue
				csaArguments.Add( "TSQ02" );
			}
			break;

			default:
			{
				csaArguments.Add( "DANGER" );
				csaArguments.Add( "DANGER" );
				csaArguments.Add( "BIG" );
				csaArguments.Add( "PROBLEMS" );
				csaArguments.Add( "LIE" );
				csaArguments.Add( "AHEAD" );
			}
			break;

		}
	}
}




/****************************************************************************DC
	Function	:	CAPIGenDlg::ShowCICSNETControls()

	Purpose		:	Show the controls for the CICS Bridge QACom Automation 
					function parameters.

*****************************************************************************/
void CAPIGenDlg::ShowCICSNETControls( int nFunction )
{
	HideParameterControls();
	csaLabels.RemoveAll();
	BOOL bYouShouldGo=TRUE;

	switch ( nFunction )
	{
		case 0:	// ChangePassword
		{
			csaLabels.Add("Host IP address");
			csaLabels.Add("Host port");
			csaLabels.Add("User ID");
			csaLabels.Add("Current password");
			csaLabels.Add("New password");
		}
		break;

		case 1:	// ConnectBridge
		{
			csaLabels.Add("Host IP address");
			csaLabels.Add("Host port");
			csaLabels.Add("Terminal model");
			csaLabels.Add("Data engine User ID");
			csaLabels.Add("Data engine password");
			csaLabels.Add("Terminal ID pool");
			csaLabels.Add("Network name");
			csaLabels.Add("Virtual facility like");
			bYouShouldGo=FALSE;
		}
		break;

		case 3:	// FindString
		{
			csaLabels.Add("Screen");
			csaLabels.Add("Search string");
			csaLabels.Add("Row");
			csaLabels.Add("Column");
			csaLabels.Add("Flags");
			bYouShouldGo=FALSE;
		}
		break;

		case 4:	// GetAllFieldInformation
		{
			csaLabels.Add("Screen");
		}
		break;

		case 6:	// GetCurrentScreenName
		{
			csaLabels.Add("Timeout (ms)");
		}
		break;

		case 8:	// GetFieldAttributes
		{
			csaLabels.Add("Screen");
			csaLabels.Add("Field");
		}
		break;

		case 9:	// GetFieldCoordinates
		{
			csaLabels.Add("Screen");
			csaLabels.Add("Field");
		}
		break;

		case 10:	// GetFieldCount
		case 13:	// GetScreenSize
		{
			csaLabels.Add("Screen");
		}
		break;

		case 11:	// GetFieldNameFromIndex
		case 12:	// GetFieldValue
		{
			csaLabels.Add("Screen");
			csaLabels.Add("Field index");
		}
		break;

		case 14:	// GetString
		{
			csaLabels.Add("Screen");
			csaLabels.Add("Row");
			csaLabels.Add("Column");
			csaLabels.Add("Length");
		}
		break;

		case 15:	// GetTransactionSystemId
		{
			csaLabels.Add("Host IP address");
			csaLabels.Add("Host port");
			csaLabels.Add("Transaction ID");
		}
		break;

		case 16:	// Initialize
		{
			csaLabels.Add("Terminal type");
			bYouShouldGo=FALSE;
		}
		break;

		case 17:	// Pause
		{
			csaLabels.Add("Pause time (ms)");
		}
		break;

		case 18:	// PutString
		{
			csaLabels.Add("String");
			csaLabels.Add("Row");
			csaLabels.Add("Column");
		}
		break;

		case 19:	// SendKeys
		case 20:	// SendKeysEx
		case 21:	// SendKeysGetAllFieldInformation
		{
			csaLabels.Add("Keystrokes");
		}
		break;

		case 22:	// SendKeysGetString
		{
			csaLabels.Add("Keys");
			csaLabels.Add("Row");
			csaLabels.Add("Column");
			csaLabels.Add("Length");
		}
		break;

		case 23:	// SetCursorPosition
		{
			csaLabels.Add("Row");
			csaLabels.Add("Column");
		}
		break;

		case 24:	// SetFieldValue
		{
			csaLabels.Add("Field array");
			csaLabels.Add("Value array");
		}
		break;

		case 25:	// SetSettleTime
		{
			csaLabels.Add("Settle time (ms)");
		}
		break;

		case 26:	// SetTimeOut
		{
			csaLabels.Add("Timeout (ms)");
		}
		break;

		case 27:	// SetTraceActive
		case 29:	// SetTraceName
		{
			csaLabels.Add("Temporary Storage Queue");
		}
		break;

	}
	
	if ( bYouShouldGo )
	{
		ShowEditControls( &csaLabels );
	}
	else
	{
		ShowMixedControls( CICS_NET_API, nFunction, &csaLabels );	
	}

}



