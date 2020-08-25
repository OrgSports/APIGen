#include "stdafx.h"
#include "APIGen.h"
#include "APIGenDlg.h"

/****************************************************************************DC
	Function	:	CAPIGenDlg::LoadCICSJAVAArgumentArray()

	Purpose		:	Load the function arguments for CICS Bridge QACom Automation.

*****************************************************************************/
void CAPIGenDlg::LoadCICS11JAVAArgumentArray( int* nFunctionPosition, BOOL bPromptForValues )
{
	CString	csFunctionName, csFunctionNum;
	
	UpdateData();
	
	*nFunctionPosition=0;

	*nFunctionPosition = m_listTranslateFunction.GetCurSel();
	m_listTranslateFunction.GetText( *nFunctionPosition, csFunctionName );

	// full function name text
	csaArguments.Add( csFunctionName );

	switch ( *nFunctionPosition )
	{
		case 0:		// ApiLog::addComment
		case 1:		// ApiLog::encodeBytesToDisplayString
		case 2:		// ApiLog::logClose
		case 3:		// ApiLog::logErrorMsg
		case 4:		// ApiLog::logMethodException
		case 5:		// ApiLog::logRequest
		case 6:		// ApiLog::logResponse
		case 7:		// ApiLog::logStackTrace
		case 10:	// BridgeAPI::Disconnect
		case 36:	// BridgeAPI::GetHostDelay
		case 56:	// BridgeAPI::SetTraceInactive
		case 58:	// BridgeAPI::Terminate
		case 60:	// CICSResponse::getApiCargo
		case 61:	// CICSResponse::getCargoLength
		case 62:	// CICSResponse::getCicsRC
		case 63:	// CICSResponse::getFunction
		case 64:	// CICSResponse::getSessionId
		case 69:	// ConHTTP3270CICS::getCicsIPAddress
		case 70:	// ConHTTP3270CICS::getCicsSocketPort
		case 71:	// ConHTTP3270CICS::getHostDelay
		case 72:	// ConHTTP3270CICS::getMessageResponseData
		case 73:	// ConHTTP3270CICS::getRemoteHostAddress
		case 74:	// ConHTTP3270CICS::getRemoteHostPort
		{

		}
		break;

		case 8:		// BridgeAPI::ChangePassword
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

		case 9:		// BridgeAPI::ConnectBridge
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

		case 11:	// BridgeAPI::FindString
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

			// out row
			csaArguments.Add( "0" );

			// out column
			csaArguments.Add( "0" );

		}
		break;

		case 12:	// BridgeAPI::FindString Ex
		{
			// in screen
			csaArguments.Add( "" );

			// in string
			csaArguments.Add( "Ready" );

			// start row
			csaArguments.Add( "17" );

			// start column
			csaArguments.Add( "6" );

			// in flags
			csaArguments.Add( "12" );

			// out row
			csaArguments.Add( "0" );

			// out column
			csaArguments.Add( "0" );

		}
		break;

		case 13:	// BridgeAPI::GetAllFieldInformation
		{
			// in screen
			csaArguments.Add( "-1" );
			// field count
			csaArguments.Add( "0" );
			// field names
			csaArguments.Add( "0" );
			// field values
			csaArguments.Add( "0" );
			// field attributes
			csaArguments.Add( "0" );
			// field rows
			csaArguments.Add( "0" );
			// field columns
			csaArguments.Add( "0" );
			// field lengths
			csaArguments.Add( "0" );
			// field colors
			csaArguments.Add( "0" );
			// field highlights
			csaArguments.Add( "0" );

		}
		break;

		case 14:	// BridgeAPI::GetAllFieldInformation Ex2
		{
			// in screen
			csaArguments.Add( "" );
			// field count
			csaArguments.Add( "0" );
			// field names
			csaArguments.Add( "0" );
			// field values
			csaArguments.Add( "0" );
			// field attributes
			csaArguments.Add( "0" );
			// field rows
			csaArguments.Add( "0" );
			// field columns
			csaArguments.Add( "0" );
			// field lengths
			csaArguments.Add( "0" );
			// field colors
			csaArguments.Add( "0" );
			// field highlights
			csaArguments.Add( "0" );
		}
		break;

		case 15:	// BridgeAPI::GetAllFieldInformation Ex3
		{
			// in screen
			csaArguments.Add( "-1" );
			// field count
			csaArguments.Add( "0" );
			// field names
			csaArguments.Add( "0" );
			// field values
			csaArguments.Add( "0" );
			// field attributes
			csaArguments.Add( "0" );
			// field rows
			csaArguments.Add( "0" );
			// field columns
			csaArguments.Add( "0" );
			// field lengths
			csaArguments.Add( "0" );
		}
		break;

		case 16:	// BridgeAPI::GetAllFieldInformation Ex4
		{
			// in screen
			csaArguments.Add( "" );
			// field count
			csaArguments.Add( "0" );
			// field names
			csaArguments.Add( "0" );
			// field values
			csaArguments.Add( "0" );
			// field attributes
			csaArguments.Add( "0" );
			// field rows
			csaArguments.Add( "0" );
			// field columns
			csaArguments.Add( "0" );
			// field lengths
			csaArguments.Add( "0" );
		}
		break;

		case 17:	// BridgeAPI::GetConnectionStatus
		{
			// status
			csaArguments.Add( "0" );
		}
		break;


		case 18:	// BridgeAPI::GetCurrentScreenName
		{
			// timeout
			csaArguments.Add( "22" );

			// screen name
			csaArguments.Add( "0" );
		}
		break;

		case 19:	// BridgeAPI::GetCursorPosition
		{
			// row
			csaArguments.Add( "0" );
			// column
			csaArguments.Add( "0" );
		}
		break;

		case 20:	// BridgeAPI::GetFieldAttributes
		{
			// screen ID
			csaArguments.Add( "-1" );

			// field name
			csaArguments.Add( "accountID" );

			// out attributes
			csaArguments.Add( "0" );
		}
		break;

		case 21:	// BridgeAPI::GetFieldAttributes Ex2
		{
			// screen ID
			csaArguments.Add( "-1" );

			// field index
			csaArguments.Add( "6" );

			// out attributes
			csaArguments.Add( "0" );
		}
		break;

		case 22:	// BridgeAPI::GetFieldAttributes Ex3
		{
			// screen ID
			csaArguments.Add( "" );

			// field index
			csaArguments.Add( "3" );

			// out attributes
			csaArguments.Add( "0" );
		}
		break;

		case 23:	// BridgeAPI::GetFieldAttributes Ex4
		{
			// screen ID
			csaArguments.Add( "" );

			// field name
			csaArguments.Add( "companyName" );

			// out attributes
			csaArguments.Add( "0" );
		}
		break;

		case 24:	// BridgeAPI::GetFieldCoordinates
		{
			// screen ID
			csaArguments.Add( "-1" );

			// field index
			csaArguments.Add( "26" );

			// out field row
			csaArguments.Add( "19" );

			// out field column
			csaArguments.Add( "7" );

			// out field length
			csaArguments.Add( "8" );
		}
		break;

		case 25:	// BridgeAPI::GetFieldCoordinates Ex2
		{
			// screen ID
			csaArguments.Add( "" );

			// field name
			csaArguments.Add( "companyName" );

			// out field row
			csaArguments.Add( "19" );

			// out field column
			csaArguments.Add( "7" );

			// out field length
			csaArguments.Add( "8" );
		}
		break;

		case 26:	// BridgeAPI::GetFieldCoordinates Ex3
		{
			// screen ID
			csaArguments.Add( "-1" );

			// field index
			csaArguments.Add( "companyName" );

			// out field row
			csaArguments.Add( "19" );

			// out field column
			csaArguments.Add( "7" );

			// out field length
			csaArguments.Add( "8" );
		}
		break;

		case 27:	// BridgeAPI::GetFieldCoordinates Ex4
		{
			// screen ID
			csaArguments.Add( "" );

			// field index
			csaArguments.Add( "2" );

			// out field row
			csaArguments.Add( "19" );

			// out field column
			csaArguments.Add( "7" );

			// out field length
			csaArguments.Add( "8" );
		}
		break;

		case 28:	// BridgeAPI::GetFieldCount
		{
			// screen ID
			csaArguments.Add( "-1" );

			// out field count
			csaArguments.Add( "8" );
		}
		break;

		case 29:	// BridgeAPI::GetFieldCount Ex
		{
			// screen ID
			csaArguments.Add( "" );

			// out field count
			csaArguments.Add( "8" );
		}
		break;

		case 30:	// BridgeAPI::GetFieldNameFromIndex
		{
			// screen ID
			csaArguments.Add( "" );

			// field index
			csaArguments.Add( "3" );

			// out field name
			csaArguments.Add( "8" );
		}
		break;

		case 31:	// BridgeAPI::GetFieldNameFromIndex Ex
		{
			// screen ID
			csaArguments.Add( "-1" );

			// field index
			csaArguments.Add( "3" );

			// out field name
			csaArguments.Add( "8" );
		}
		break;

		case 32:	// BridgeAPI::GetFieldValue
		{
			// screen ID
			csaArguments.Add( "-1" );

			// field index
			csaArguments.Add( "totsales" );

			// out field name
			csaArguments.Add( "0" );
		}
		break;

		case 33:	// BridgeAPI::GetFieldValue Ex2
		{
			// screen ID
			csaArguments.Add( "-1" );

			// field index
			csaArguments.Add( "14" );

			// out field name
			csaArguments.Add( "0" );
		}
		break;

		case 34:	// BridgeAPI::GetFieldValue Ex3
		{
			// screen ID
			csaArguments.Add( "" );

			// field index
			csaArguments.Add( "34" );

			// out field name
			csaArguments.Add( "0" );
		}
		break;

		case 35:	// BridgeAPI::GetFieldValue Ex4
		{
			// screen ID
			csaArguments.Add( "" );

			// field index
			csaArguments.Add( "volume" );

			// out field name
			csaArguments.Add( "0" );
		}
		break;

		case 37:	// BridgeAPI::GetReturnCodeMessage
		{
			// return code
			csaArguments.Add( "-5" );
		}
		break;

		case 38:	// BridgeAPI::GetScreenSize
		{
			// screen ID
			csaArguments.Add( "" );

			// out rows
			csaArguments.Add( "0" );

			// out columns
			csaArguments.Add( "0" );
		}
		break;

		case 39:	// BridgeAPI::GetScreenSize Ex
		{
			// screen ID
			csaArguments.Add( "-1" );

			// out rows
			csaArguments.Add( "0" );

			// out columns
			csaArguments.Add( "0" );
		}
		break;

		case 40:	// BridgeAPI::GetString
		{
			// screen ID
			csaArguments.Add( "-1" );
			// row
			csaArguments.Add( "1" );
			// column
			csaArguments.Add( "7" );
			// length
			csaArguments.Add( "8" );
			// out text
			csaArguments.Add( "0" );
		}
		break;

		case 41:	// BridgeAPI::GetString Ex
		{
			// screen ID
			csaArguments.Add( "-1" );
			// row
			csaArguments.Add( "1" );
			// column
			csaArguments.Add( "7" );
			// length
			csaArguments.Add( "8" );
			// out text
			csaArguments.Add( "0" );
		}
		break;

		case 42:	// BridgeAPI::GetTransactionSystemId
		{
			// host IP
			csaArguments.Add( "234.164.88.1" );
			// host port
			csaArguments.Add( "16" );
			// transaction ID
			csaArguments.Add( "1222" );
			// out text
			csaArguments.Add( "0" );
		}
		break;

		case 43:	// BridgeAPI::PutString
		{
			// text
			csaArguments.Add( "amer069" );
			// row
			csaArguments.Add( "16" );
			// column
			csaArguments.Add( "7" );
			// num chars
			csaArguments.Add( "8" );
		}
		break;

		case 44:	// BridgeAPI::SendKeys
		{
			// text
			csaArguments.Add( "billw05@E" );
		}
		break;

		case 45:	// BridgeAPI::SendKeysEx
		{
			// text
			csaArguments.Add( "thadd@E" );
		}
		break;

		case 46:	// BridgeAPI::SendKeysGetAllFieldInformation
		{
			// keys
			csaArguments.Add( "jpm23i@1" );
			// out field count
			csaArguments.Add( "" );
			// out field names
			csaArguments.Add( "" );
			// out field values
			csaArguments.Add( "" );
			// out field attributes
			csaArguments.Add( "" );
			// out field rows
			csaArguments.Add( "" );
			// out field columns
			csaArguments.Add( "" );
			// out field field lengths
			csaArguments.Add( "" );
			// out field colors
			csaArguments.Add( "" );
			// out field highlights
			csaArguments.Add( "" );
		}
		break;

		case 47:	// BridgeAPI::SendKeysGetString
		{
			// keys
			csaArguments.Add( "armak18@E" );
			// start row
			csaArguments.Add( "4" );
			// start column
			csaArguments.Add( "2" );
			// length
			csaArguments.Add( "2" );
			// out text
			csaArguments.Add( "" );		
		}
		break;

		case 48:	// BridgeAPI::SetCursorPosition
		{
			// row
			csaArguments.Add( "16" );
			// column
			csaArguments.Add( "6" );
		}
		break;

		case 49:	// BridgeAPI::SetFieldValue
		{
			// screen ID
			csaArguments.Add( "" );

			// field index
			csaArguments.Add( "A6" );
		}
		break;

		case 50:	// BridgeAPI::SetFieldValue Ex2 
		{
			// screen ID
			csaArguments.Add( "-1" );

			// field index
			csaArguments.Add( "E6" );
		}
		break;

		case 51:	// BridgeAPI::SetFieldValue Ex3
		{
			// screen ID
			csaArguments.Add( "" );

			// field index
			csaArguments.Add( "" );
		}
		break;

		case 52:	// BridgeAPI::SetHostDelay
		{
			// delay
			csaArguments.Add( "10002" );
		}
		break;

		case 53:	// BridgeAPI::SetSettleTime
		{
			// settle time
			csaArguments.Add( "1" );
		}
		break;

		case 54:	// BridgeAPI::SetTimeOut
		{
			// timeout
			csaArguments.Add( "10000" );
		}
		break;

		case 55:	// BridgeAPI::SetTraceActive
		{
			// trace queue name
			csaArguments.Add( "hibach" );
		}
		break;

		case 57:	// BridgeAPI::SetTraceName
		{
			// trace queue name
			csaArguments.Add( "bahama14" );
		}
		break;

		case 59:	// CICSResponse::equalCompareBytes
		{
			// byte array 1
			csaArguments.Add( "array1" );
			// byte array 2
			csaArguments.Add( "array2" );
		}
		break;

		case 65:	// CICSResponse::parseResponseHeaderAndPacket
		{
			// byte array
			csaArguments.Add( "array123" );
		}
		break;

		case 66:	// CICSResponse::setAPITrace
		{
			// set trace on
			csaArguments.Add( "true" );
		}
		break;

		case 67:	// CICSResponse::setCiscRC
		{
			// set return code
			csaArguments.Add( "2" );
		}
		break;

		case 68:	// CICSResponse::setSessionId
		{
			// session id array
			csaArguments.Add( "sessarray3" );
		}
		break;

		case 75:	// ConHTTP3270CICS::sendRequestMessage
		{
			// name
			csaArguments.Add( "msg135" );
			// byte array 2
			csaArguments.Add( "array42" );
			// byte array 2
			csaArguments.Add( "array22" );
		}
		break;

		case 76:	// ConHTTP3270CICS::setAPITrace
		{
			// do trace boolean
			csaArguments.Add( "true" );
			// byte array 2
			csaArguments.Add( "log05.txt" );
		}
		break;

		case 77:	// ConHTTP3270CICS::setCicsIPAddress
		{
			// ip address
			csaArguments.Add( "149.82.3.3" );
		}
		break;

		case 78:	// ConHTTP3270CICS::SetCicsSocketPort
		{
			// port address
			csaArguments.Add( "9" );
		}
		break;

		case 79:	// ConHTTP3270CICS::setHostDelay
		{
			// host delay
			csaArguments.Add( "1219" );
		}
		break;

		case 80:	// ConHTTP3270CICS::setHostIpAddress
		{
			// ip address
			csaArguments.Add( "149.82.3.4" );
		}
		break;

		case 81:	// ConHTTP3270CICS::setHostIPPort
		{
			// port address
			csaArguments.Add( "9" );
		}
		break;

		case 82:	// ConHTTP3270CICS::setRemoteHostAddress
		{
			// ip address
			csaArguments.Add( "149.82.4.4" );
		}
		break;

		case 83:	// ConHTTP3270CICS::setRemoteHostPort
		{
			// port address
			csaArguments.Add( "88" );
		}
		break;

		case 84:	// ConHTTP3270CICS::setSessionId
		{
			// session ID
			csaArguments.Add( "array4" );
		}
		break;

		case 85:	// Encode::AtoE
		{
			// byte array
			csaArguments.Add( "ClientArray" );
			// begin ID
			csaArguments.Add( "id" );
			// num bytes
			csaArguments.Add( "1920" );
		}
		break;

		case 86:	// Encode::AtoEInPlace
		{
			// byte array
			csaArguments.Add( "ClientArray2" );
			// begin ID
			csaArguments.Add( "id2" );
			// num bytes
			csaArguments.Add( "40" );
		}
		break;

		case 87:	// Encode::EtoA
		{
			// byte array
			csaArguments.Add( "EBCDICArray" );
			// begin ID
			csaArguments.Add( "id" );
			// num bytes
			csaArguments.Add( "1920" );
		}
		break;

		case 88:	// Encode::EtoAInPlace
		{
			// byte array
			csaArguments.Add( "EBCDICArray2" );
			// begin ID
			csaArguments.Add( "id2" );
			// num bytes
			csaArguments.Add( "1920" );
		}
		break;

		case 89:	// Encode::padAtoE
		{
			// byte array
			csaArguments.Add( "InArray" );
			// begin ID
			csaArguments.Add( "id4" );
			// num bytes
			csaArguments.Add( "8" );
			// num bytes
			csaArguments.Add( "*" );
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




/****************************************************************************DC
	Function	:	CAPIGenDlg::ShowCICS11JAVAControls()

	Purpose		:	Show the controls for the CICS Bridge QACom Automation 
					function parameters.

*****************************************************************************/
void CAPIGenDlg::ShowCICS11JAVAControls( int nFunction )
{
	HideParameterControls();
	csaLabels.RemoveAll();
	BOOL bYouShouldGo=TRUE;

	switch ( nFunction )
	{
		case 0:		// ApiLog::addComment
		case 1:		// ApiLog::encodeBytesToDisplayString
		case 2:		// ApiLog::logClose
		case 3:		// ApiLog::logErrorMsg
		case 4:		// ApiLog::logMethodException
		case 5:		// ApiLog::logRequest
		case 6:		// ApiLog::logResponse
		case 7:		// ApiLog::logStackTrace
		case 8:		// ChangePassword
		case 9:		// ConnectBridge	
		case 10:	// BridgeAPI::Disconnect
		case 11:	// BridgeAPI::FindString
		case 12:	// BridgeAPI::FindString Ex
		case 13:	// BridgeAPI::GetAllFieldInformation
		case 14:	// BridgeAPI::GetAllFieldInformation Ex2
		case 15:	// BridgeAPI::GetAllFieldInformation Ex3
		case 16:	// BridgeAPI::GetAllFieldInformation Ex4
		case 17:	// BridgeAPI::GetConnectionStatus
		case 18:	// BridgeAPI::GetCurrentScreenName
		case 19:	// BridgeAPI::GetCursorPosition
		case 20:	// BridgeAPI::GetFieldAttributes
		case 21:	// BridgeAPI::GetFieldAttributes Ex2
		case 22:	// BridgeAPI::GetFieldAttributes Ex3
		case 23:	// BridgeAPI::GetFieldAttributes Ex4
		case 24:	// BridgeAPI::GetFieldCoordinates
		case 25:	// BridgeAPI::GetFieldCoordinates Ex2
		case 26:	// BridgeAPI::GetFieldCoordinates Ex3
		case 27:	// BridgeAPI::GetFieldCoordinates Ex4
		case 28:	// BridgeAPI::GetFieldCount
		case 29:	// BridgeAPI::GetFieldCount Ex
		case 30:	// BridgeAPI::GetFieldNameFromIndex
		case 31:	// BridgeAPI::GetFieldNameFromIndex Ex
		case 32:	// BridgeAPI::GetFieldValue
		case 33:	// BridgeAPI::GetFieldValue Ex2
		case 34:	// BridgeAPI::GetFieldValue Ex3
		case 35:	// BridgeAPI::GetFieldValue Ex4
		case 36:	// BridgeAPI::GetHostDelay
		case 37:	// BridgeAPI::GetReturnCodeMessage
		case 38:	// BridgeAPI::GetScreenSize
		case 39:	// BridgeAPI::GetScreenSize Ex
		case 40:	// BridgeAPI::GetString
		case 41:	// BridgeAPI::GetString Ex
		case 42:	// BridgeAPI::GetTransactionSystemId
		case 43:	// BridgeAPI::PutString
		case 44:	// BridgeAPI::SendKeys
		case 45:	// BridgeAPI::SendKeysEx
		case 46:	// BridgeAPI::SendKeysGetAllFieldInformation
		case 47:	// BridgeAPI::SendKeysGetString
		case 48:	// BridgeAPI::SetCursorPosition
		case 49:	// BridgeAPI::SetFieldValue
		case 50:	// BridgeAPI::SetFieldValue Ex2 
		case 51:	// BridgeAPI::SetFieldValue Ex3
		case 52:	// BridgeAPI::SetHostDelay
		case 53:	// BridgeAPI::SetSettleTime
		case 54:	// BridgeAPI::SetTimeOut
		case 55:	// BridgeAPI::SetTraceActive
		case 56:	// BridgeAPI::SetTraceInactive
		case 57:	// BridgeAPI::SetTraceName
		case 58:	// BridgeAPI::Terminate
		case 59:	// CICSResponse::equalCompareBytes
		case 60:	// CICSResponse::getApiCargo
		case 61:	// CICSResponse::getCargoLength
		case 62:	// CICSResponse::getCicsRC
		case 63:	// CICSResponse::getFunction
		case 64:	// CICSResponse::getSessionId
		case 65:	// CICSResponse::parseResponseHeaderAndPacket
		case 66:	// CICSResponse::setAPITrace
		case 67:	// CICSResponse::setCiscRC
		case 68:	// CICSResponse::setSessionId
		case 69:	// ConHTTP3270CICS::getCicsIPAddress
		case 70:	// ConHTTP3270CICS::getCicsSocketPort
		case 71:	// ConHTTP3270CICS::getHostDelay
		case 72:	// ConHTTP3270CICS::getMessageResponseData
		case 73:	// ConHTTP3270CICS::getRemoteHostAddress
		case 74:	// ConHTTP3270CICS::getRemoteHostPort
		case 75:	// ConHTTP3270CICS::sendRequestMessage
		case 76:	// ConHTTP3270CICS::setAPITrace
		case 77:	// ConHTTP3270CICS::setCicsIPAddress
		case 78:	// ConHTTP3270CICS::SetCicsSocketPort
		case 79:	// ConHTTP3270CICS::setHostDelay
		case 80:	// ConHTTP3270CICS::setHostIpAddress
		case 81:	// ConHTTP3270CICS::setHostIPPort
		case 82:	// ConHTTP3270CICS::setRemoteHostAddress
		case 83:	// ConHTTP3270CICS::setRemoteHostPort
		case 84:	// ConHTTP3270CICS::setSessionId
		case 85:	// Encode::AtoE
		case 86:	// Encode::AtoEInPlace
		case 87:	// Encode::EtoA
		case 88:	// Encode::EtoAInPlace
		case 89:	// Encode::padAtoE
		{
			m_groupNoParametersNeeded.ShowWindow( SW_SHOW  );
		}
		break;

	}

	if ( bYouShouldGo )
	{
		ShowEditControls( &csaLabels );
	}
	else
	{
		ShowMixedControls( CICS20_JAVA_API, nFunction, &csaLabels );	
	}

}



