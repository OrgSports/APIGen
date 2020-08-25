#include "stdafx.h"
#include "APIGen.h"
#include "APIGenDlg.h"

/****************************************************************************DC
	Function	:	CAPIGenDlg::LoadCICSJAVAArgumentArray()

	Purpose		:	Load the function arguments for CICS Bridge QACom Automation.

*****************************************************************************/
void CAPIGenDlg::LoadCICS20JAVAArgumentArray( int* nFunctionPosition, BOOL bPromptForValues )
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
			case 0:		// AllFieldInformation::getFieldAttributes
			case 1:		// AllFieldInformation::getFieldColors
			case 2:		// AllFieldInformation::getFieldCols
			case 3:		// AllFieldInformation::getFieldCount
			case 4:		// AllFieldInformation::getFieldHighlights
			case 5:		// AllFieldInformation::getFieldLengths
			case 6:		// AllFieldInformation::getFieldNames
			case 7:		// AllFieldInformation::getFieldRows
			case 8:		// AllFieldInformation::getFieldValues
			case 9:		// AllFieldInformation::getReturnCode
			case 15:	// BridgeAPI::Disconnect
			case 22:	// BridgeAPI::GetConnectionStatus
			case 24:	// BridgeAPI::GetCursorPosition
			case 59:	// BridgeAPI::SetTraceInactive
			case 61:	// BridgeAPI::Terminate
			case 67:	// BridgeAPI_EJB::disconnect
			case 72:	// BridgeAPI_EJB::getConnectionStatus
			case 74:	// BridgeAPI_EJB::getCursorPosition
			case 109:	// BridgeAPI_EJB::setTraceInactive
			case 111:	// BridgeAPI_EJB::terminate
			case 112:	// ConnectionStatus::getReturnCode
			case 113:	// ConnectionStatus::getStatus
			case 114:	// CurrentScreenName::getReturnCode
			case 115:	// CurrentScreenName::getScreenName
			case 116:	// CursorPosition::getColumn
			case 117:	// CursorPosition::getReturnCode
			case 118:	// CursorPosition::getRow
			case 119:	// FieldAttributes::getAttributes
			case 120:	// FieldAttributes::getReturnCode
			case 121:	// FieldCoordinates::getFieldColumn
			case 122:	// FieldCoordinates::getFieldLength
			case 123:	// FieldCoordinates::getFieldRow
			case 124:	// FieldCoordinates::getReturnCode
			case 125:	// FieldCount::getFieldCount
			case 126:	// FieldCount::getReturnCode
			case 127:	// FieldName::getFieldName
			case 128:	// FieldName::getReturnCode
			case 129:	// FieldValue::getReturnCode
			case 130:	// FieldValue::getValue
			case 131:	// FindString::getColumn
			case 132:	// FindString::getReturnCode
			case 133:	// FindString::getRow
			case 134:	// GetString::getReturnCode
			case 135:	// GetString::getText
			case 136:	// PutString::getNumChars
			case 137:	// PutString::getReturnCode
			case 138:	// ScreenSize::getColumns
			case 139:	// ScreenSize::getReturnCode
			case 140:	// ScreenSize::getRows
			case 141:	// TransactionSystemid::getReturnCode
			case 142:	// TransactionSystemid::getSystemId
			{
			}
			break;

			case 23:	// BridgeAPI::GetCurrentScreenName
			case 33:	// BridgeAPI::GetFieldCount
			case 34:	// BridgeAPI::GetFieldCount Ex
			case 41:	// BridgeAPI::getReturnCodeMessage
			case 42:	// BridgeAPI::GetScreenSize
			case 43:	// BridgeAPI::GetScreenSize Ex
			case 48:	// BridgeAPI::SendKeys
			case 49:	// BridgeAPI::SendKeysEx
			case 50:	// BridgeAPI::SendKeysGetAllFieldInformation
			case 56:	// BridgeAPI::SetSettleTime
			case 57:	// BridgeAPI::SetTimeOut
			case 58:	// BridgeAPI::SetTraceActive
			case 60:	// BridgeAPI::SetTraceName
			case 73:	// BridgeAPI_EJB::getCurrentScreenName
			case 83:	// BridgeAPI_EJB::getFieldCount
			case 84:	// BridgeAPI_EJB::getFieldCount Ex
			case 91: // BridgeAPI_EJB::getReturnCodeMessage
			case 92:	// BridgeAPI_EJB::getScreenSize
			case 93:	// BridgeAPI_EJB::getScreenSize Ex
			case 98:	// BridgeAPI_EJB::sendKeys
			case 99:	// BridgeAPI_EJB::sendKeysEx
			case 100:	// BridgeAPI_EJB::sendKeysGetAllFieldInformation
			case 106:	// BridgeAPI_EJB::setSettleTime
			case 107:	// BridgeAPI_EJB::setTimeOut
			case 108:	// BridgeAPI_EJB::setTraceActive
			case 110:	// BridgeAPI_EJB::setTraceName
			{
				Read1E( &csaArguments );
			}
			break;


			case 18:	// BridgeAPI::GetAllFieldInformation
			case 19:	// BridgeAPI::GetAllFieldInformation Ex2
			case 20:	// BridgeAPI::GetAllFieldInformation Ex3
			case 21:	// BridgeAPI::GetAllFieldInformation Ex4
			case 25:	// BridgeAPI::GetFieldAttributes
			case 26:	// BridgeAPI::GetFieldAttributes Ex2
			case 27:	// BridgeAPI::GetFieldAttributes Ex3
			case 28:	// BridgeAPI::GetFieldAttributes Ex4
			case 29:	// BridgeAPI::GetFieldCoordinates
			case 30:	// BridgeAPI::GetFieldCoordinates Ex2
			case 31:	// BridgeAPI::GetFieldCoordinates Ex3
			case 32:	// BridgeAPI::GetFieldCoordinates Ex4
			case 35:	// BridgeAPI::GetFieldNameFromIndex
			case 36:	// BridgeAPI::GetFieldNameFromIndex Ex
			case 37:	// BridgeAPI::GetFieldValue
			case 38:	// BridgeAPI::GetFieldValue Ex2
			case 39:	// BridgeAPI::GetFieldValue Ex3
			case 40:	// BridgeAPI::GetFieldValue Ex4
			case 52:	// BridgeAPI::SetCursorPosition
			case 53:	// BridgeAPI::SetFieldValue
			case 54:	// BridgeAPI::SetFieldValue Ex2 
			case 55:	// BridgeAPI::SetFieldValue Ex3
			case 70:	// BridgeAPI_EJB::getAllFieldInformation
			case 71:	// BridgeAPI_EJB::getAllFieldInformation Ex
			case 75:	// BridgeAPI_EJB::getFieldAttributes
			case 76:	// BridgeAPI_EJB::getFieldAttributes Ex2
			case 77:	// BridgeAPI_EJB::getFieldAttributes Ex3
			case 78:	// BridgeAPI_EJB::getFieldAttributes Ex4
			case 79:	// BridgeAPI_EJB::getFieldCoordinates
			case 80:	// BridgeAPI_EJB::getFieldCoordinates Ex2
			case 81:	// BridgeAPI_EJB::getFieldCoordinates Ex3
			case 82:	// BridgeAPI_EJB::getFieldCoordinates Ex4
			case 85:	// BridgeAPI_EJB::getFieldNameFromIndex
			case 86:	// BridgeAPI_EJB::getFieldNameFromIndex Ex
			case 87:	// BridgeAPI_EJB::getFieldValue
			case 88:	// BridgeAPI_EJB::getFieldValue Ex2
			case 89:	// BridgeAPI_EJB::getFieldValue Ex3
			case 90:	// BridgeAPI_EJB::getFieldValue Ex4
			case 102:	// BridgeAPI_EJB::setCursorPosition
			case 103:	// BridgeAPI_EJB::setFieldValue
			case 104:	// BridgeAPI_EJB::setFieldValue Ex2
			case 105:	// BridgeAPI_EJB::setFieldValue Ex3
			{
				Read2E( &csaArguments );
			}
			break;

			case 11:	// BridgeAPI::ConnectBridge
			case 63:	// BridgeAPI_EJB::connectBridge
			{
				Read2E1L2E( &csaArguments );
			}
			break;

			case 12:	// BridgeAPI::ConnectBridge Ex2
			case 64:	// BridgeAPI_EJB::connectBridge Ex2
			{
				Read2E1L3E( &csaArguments );
			}
			break;


			case 13:	// BridgeAPI::ConnectBridge Ex3
			case 65:	// BridgeAPI_EJB::connectBridge Ex3
			{
				Read2E1L4E( &csaArguments );
			}
			break;

			case 14:	// BridgeAPI::ConnectBridge Ex4
			case 66:	// BridgeAPI_EJB::connectBridge Ex4
			{
				Read2E1L5E( &csaArguments );
			}
			break;

			case 46:	// BridgeAPI::GetTransactionSystemId
			case 47:	// BridgeAPI::PutString
			case 96:	// BridgeAPI_EJB::getTransactionSystemId
			case 97:	// BridgeAPI_EJB::putString
			{
				Read3E( &csaArguments );
			}
			break;

			case 44:	// BridgeAPI::GetString
			case 45:	// BridgeAPI::GetString Ex
			case 51:	// BridgeAPI::SendKeysGetString
			case 94:	// BridgeAPI_EJB::getString
			case 95:	// BridgeAPI_EJB::getString Ex
			case 101:	// BridgeAPI_EJB::sendKeysGetString
			{
				Read4E( &csaArguments );
			}
			break;


			case 10:	// BridgeAPI::ChangePassword
			case 16:	// BridgeAPI::FindString
			case 17:	// BridgeAPI::FindString Ex
			case 62:	// BridgeAPI_EJB::changePassword
			case 68:	// BridgeAPI_EJB::findString
			case 69:	// BridgeAPI_EJB::findString Ex
			{
				Read5E( &csaArguments );
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
			case 0:		// AllFieldInformation::getFieldAttributes
			case 1:		// AllFieldInformation::getFieldColors
			case 2:		// AllFieldInformation::getFieldCols
			case 3:		// AllFieldInformation::getFieldCount
			case 4:		// AllFieldInformation::getFieldHighlights
			case 5:		// AllFieldInformation::getFieldLengths
			case 6:		// AllFieldInformation::getFieldNames
			case 7:		// AllFieldInformation::getFieldRows
			case 8:		// AllFieldInformation::getFieldValues
			case 9:		// AllFieldInformation::getReturnCode
			case 15:	// BridgeAPI::Disconnect
			case 22:	// BridgeAPI::GetConnectionStatus
			case 24:	// BridgeAPI::GetCursorPosition
			case 59:	// BridgeAPI::SetTraceInactive
			case 61:	// BridgeAPI::Terminate
			case 67:	// BridgeAPI_EJB::disconnect
			case 72:	// BridgeAPI_EJB::getConnectionStatus
			case 74:	// BridgeAPI_EJB::getCursorPosition
			case 109:	// BridgeAPI_EJB::setTraceInactive
			case 111:	// BridgeAPI_EJB::terminate
			case 112:	// ConnectionStatus::getReturnCode
			case 113:	// ConnectionStatus::getStatus
			case 114:	// CurrentScreenName::getReturnCode
			case 115:	// CurrentScreenName::getScreenName
			case 116:	// CursorPosition::getColumn
			case 117:	// CursorPosition::getReturnCode
			case 118:	// CursorPosition::getRow
			case 119:	// FieldAttributes::getAttributes
			case 120:	// FieldAttributes::getReturnCode
			case 121:	// FieldCoordinates::getFieldColumn
			case 122:	// FieldCoordinates::getFieldLength
			case 123:	// FieldCoordinates::getFieldRow
			case 124:	// FieldCoordinates::getReturnCode
			case 125:	// FieldCount::getFieldCount
			case 126:	// FieldCount::getReturnCode
			case 127:	// FieldName::getFieldName
			case 128:	// FieldName::getReturnCode
			case 129:	// FieldValue::getReturnCode
			case 130:	// FieldValue::getValue
			case 131:	// FindString::getColumn
			case 132:	// FindString::getReturnCode
			case 133:	// FindString::getRow
			case 134:	// GetString::getReturnCode
			case 135:	// GetString::getText
			case 136:	// PutString::getNumChars
			case 137:	// PutString::getReturnCode
			case 138:	// ScreenSize::getColumns
			case 139:	// ScreenSize::getReturnCode
			case 140:	// ScreenSize::getRows
			case 141:	// TransactionSystemid::getReturnCode
			case 142:	// TransactionSystemid::getSystemId
			{
			}
			break;

			case 10:	// BridgeAPI::ChangePassword
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

			case 11:	// BridgeAPI::ConnectBridge
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
				csaArguments.Add( "1877-81" );

			}
			break;

			case 12:	// BridgeAPI::ConnectBridge Ex2
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
				csaArguments.Add( "1877-81" );

				// terminal pool name
				csaArguments.Add( "WRQPool2" );

			}
			break;

			case 13:	// BridgeAPI::ConnectBridge Ex3
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
				csaArguments.Add( "1877-81" );

				// terminal pool name
				csaArguments.Add( "terminal12" );

				// network name
				csaArguments.Add( "StarNetwork" );

			}
			break;

			case 14:	// BridgeAPI::ConnectBridge Ex4
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
				csaArguments.Add( "1877-81" );

				// terminal pool name
				csaArguments.Add( "terminal12" );

				// network name
				csaArguments.Add( "StarNetwork" );

				// term facility like
				csaArguments.Add( "" );

			}
			break;

			case 16:	// BridgeAPI::FindString
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

			case 17:	// BridgeAPI::FindString Ex
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

			}
			break;

			case 18:	// BridgeAPI::GetAllFieldInformation
			{
				// in screen
				csaArguments.Add( "-1" );

				// include color info
				csaArguments.Add( "true" );
			}
			break;

			case 19:	// BridgeAPI::GetAllFieldInformation Ex2
			{
				// in screen
				csaArguments.Add( "" );

				// include color info
				csaArguments.Add( "true" );
			}
			break;

			case 20:	// BridgeAPI::GetAllFieldInformation Ex3
			{
				// in screen
				csaArguments.Add( "-1" );

				// include color info
				csaArguments.Add( "true" );
			}
			break;

			case 21:	// BridgeAPI::GetAllFieldInformation Ex4
			{
				// in screen
				csaArguments.Add( "" );

				// include color info
				csaArguments.Add( "true" );
			}
			break;

			case 23:	// BridgeAPI::GetCurrentScreenName
			{
				// timeout
				csaArguments.Add( "22" );
			}
			break;

			case 25:	// BridgeAPI::GetFieldAttributes
			{
				// screen ID
				csaArguments.Add( "-1" );

				// field name
				csaArguments.Add( "accountID" );
			}
			break;

			case 26:	// BridgeAPI::GetFieldAttributes Ex2
			{
				// screen ID
				csaArguments.Add( "-1" );

				// field index
				csaArguments.Add( "6" );
			}
			break;

			case 27:	// BridgeAPI::GetFieldAttributes Ex3
			{
				// screen ID
				csaArguments.Add( "" );

				// field index
				csaArguments.Add( "3" );
			}
			break;

			case 28:	// BridgeAPI::GetFieldAttributes Ex4
			{
				// screen ID
				csaArguments.Add( "" );

				// field name
				csaArguments.Add( "companyName" );
			}
			break;

			case 29:	// BridgeAPI::GetFieldCoordinates
			{
				// screen ID
				csaArguments.Add( "-1" );

				// field index
				csaArguments.Add( "6" );
			}
			break;

			case 30:	// BridgeAPI::GetFieldCoordinates Ex2
			{
				// screen ID
				csaArguments.Add( "" );

				// field name
				csaArguments.Add( "companyName" );
			}
			break;

			case 31:	// BridgeAPI::GetFieldCoordinates Ex3
			{
				// screen ID
				csaArguments.Add( "" );

				// field index
				csaArguments.Add( "4" );
			}
			break;

			case 32:	// BridgeAPI::GetFieldCoordinates Ex4
			{
				// screen ID
				csaArguments.Add( "-1" );

				// field index
				csaArguments.Add( "3" );
			}
			break;

			case 33:	// BridgeAPI::GetFieldCount
			{
				// screen ID
				csaArguments.Add( "-1" );
			}
			break;

			case 34:	// BridgeAPI::GetFieldCount Ex
			{
				// screen ID
				csaArguments.Add( "" );
			}
			break;

			case 35:	// BridgeAPI::GetFieldNameFromIndex
			case 85:	// BridgeAPI_EJB::getFieldNameFromIndex
			{
				// screen ID
				csaArguments.Add( "" );

				// field index
				csaArguments.Add( "3" );
			}
			break;

			case 36:	// BridgeAPI::GetFieldNameFromIndex Ex
			case 86:	// BridgeAPI_EJB::getFieldNameFromIndex Ex
			{
				// screen ID
				csaArguments.Add( "-1" );

				// field index
				csaArguments.Add( "6" );
			}
			break;

			case 37:	// BridgeAPI::GetFieldValue
			case 87:	// BridgeAPI_EJB::getFieldValue
			{
				// screen ID
				csaArguments.Add( "-1" );

				// field index
				csaArguments.Add( "companyName" );
			}
			break;

			case 38:	// BridgeAPI::GetFieldValue Ex2
			case 88:	// BridgeAPI_EJB::getFieldValue Ex2
			{
				// screen ID
				csaArguments.Add( "-1" );

				// field index
				csaArguments.Add( "6" );
			}
			break;

			case 39:	// BridgeAPI::GetFieldValue Ex3
			case 89:	// BridgeAPI_EJB::getFieldValue Ex3
			{
				// screen ID
				csaArguments.Add( "" );

				// field index
				csaArguments.Add( "3" );
			}
			break;

			case 40:	// BridgeAPI::GetFieldValue Ex4
			case 90:	// BridgeAPI_EJB::getFieldValue Ex4
			{
				// screen ID
				csaArguments.Add( "" );

				// field index
				csaArguments.Add( "companyName" );
			}
			break;

			case 41:	// BridgeAPI::getReturnCodeMessage
			case 91: // BridgeAPI_EJB::getReturnCodeMessage
			{
				// return code
				csaArguments.Add( "-8" );
			}
			break;

			case 42:	// BridgeAPI::GetScreenSize
			case 92:	// BridgeAPI_EJB::getScreenSize
			{
				// screen ID
				csaArguments.Add( "" );
			}
			break;

			case 43:	// BridgeAPI::GetScreenSize Ex
			case 93:	// BridgeAPI_EJB::getScreenSize Ex
			{
				// screen ID
				csaArguments.Add( "-1" );
			}
			break;

			case 44:	// BridgeAPI::GetString
			case 94:	// BridgeAPI_EJB::getString
			{
				// screen ID
				csaArguments.Add( "-1" );
				// row
				csaArguments.Add( "1" );
				// column
				csaArguments.Add( "7" );
				// length
				csaArguments.Add( "8" );
			}
			break;

			case 45:	// BridgeAPI::GetString Ex
			case 95:	// BridgeAPI_EJB::getString Ex
			{
				// screen ID
				csaArguments.Add( "" );
				// row
				csaArguments.Add( "16" );
				// column
				csaArguments.Add( "6" );
				// length
				csaArguments.Add( "8" );
			}
			break;

			case 46:	// BridgeAPI::GetTransactionSystemId
			case 96:	// BridgeAPI_EJB::getTransactionSystemId
			{
				// host IP
				csaArguments.Add( "234.164.88.1" );
				// host port
				csaArguments.Add( "16" );
				// transaction ID
				csaArguments.Add( "636" );
			}
			break;

			case 47:	// BridgeAPI::PutString
			case 97:	// BridgeAPI_EJB::putString
			{
				// text string
				csaArguments.Add( "myuserid" );
				// row
				csaArguments.Add( "16" );
				// column
				csaArguments.Add( "7" );
			}
			break;

			case 48:	// BridgeAPI::SendKeys
			case 98:	// BridgeAPI_EJB::sendKeys
			{
				// send keys
				csaArguments.Add( "userid45user45@E" );
			}
			break;

			case 49:	// BridgeAPI::SendKeysEx
			case 99:	// BridgeAPI_EJB::sendKeysEx
			{
				// send keys
				csaArguments.Add( "userid46user46@E" );
			}
			break;

			case 50:	// BridgeAPI::SendKeysGetAllFieldInformation
			case 100:	// BridgeAPI_EJB::sendKeysGetAllFieldInformation
			{
				// send keys
				csaArguments.Add( "userid47user47@E" );
			}
			break;

			case 51:	// BridgeAPI::SendKeysGetString
			case 101:	// BridgeAPI_EJB::sendKeysGetString
			{
				// send keys
				csaArguments.Add( "userid47user47@E" );
				// row
				csaArguments.Add( "16" );
				// column
				csaArguments.Add( "6" );
				// length
				csaArguments.Add( "8" );
			}
			break;

			case 52:	// BridgeAPI::SetCursorPosition
			case 102:	// BridgeAPI_EJB::setCursorPosition
			{
				// row
				csaArguments.Add( "16" );
				// column
				csaArguments.Add( "6" );
			}
			break;

			case 53:	// BridgeAPI::SetFieldValue
			case 103:	// BridgeAPI_EJB::setFieldValue
			{
				// screen ID
				csaArguments.Add( "" );

				// field index
				csaArguments.Add( "A6" );
			}
			break;

			case 54:	// BridgeAPI::SetFieldValue Ex2 
			case 104:	// BridgeAPI_EJB::setFieldValue Ex2
			{
				// screen ID
				csaArguments.Add( "-1" );

				// field index
				csaArguments.Add( "E6" );
			}
			break;

			case 55:	// BridgeAPI::SetFieldValue Ex3
			case 105:	// BridgeAPI_EJB::setFieldValue Ex3
			{
				// screen ID
				csaArguments.Add( "" );

				// field index
				csaArguments.Add( "E2" );
			}
			break;

			case 56:	// BridgeAPI::SetSettleTime
			case 106:	// BridgeAPI_EJB::setSettleTime
			{
				// settle time
				csaArguments.Add( "501" );
			}
			break;

			case 57:	// BridgeAPI::SetTimeOut
			case 107:	// BridgeAPI_EJB::setTimeOut
			{
				// host timeout
				csaArguments.Add( "29000" );
			}
			break;

			case 58:	// BridgeAPI::SetTraceActive
			case 108:	// BridgeAPI_EJB::setTraceActive
			{
				// trace queue name
				csaArguments.Add( "overnight" );
			}
			break;

			case 60:	// BridgeAPI::SetTraceName
			case 110:	// BridgeAPI_EJB::setTraceName
			{
				// trace queue name
				csaArguments.Add( "bahama14" );
			}
			break;

			case 62:	// BridgeAPI_EJB::changePassword
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


			case 63:	// BridgeAPI_EJB::connectBridge
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

			case 64:	// BridgeAPI_EJB::connectBridge Ex2
			{
				// host IP
				csaArguments.Add( "149.2.23.21" );

				// host port
				csaArguments.Add( "83" );

				// terminal model
				csaArguments.Add( "2" );

				// user ID
				csaArguments.Add( "ulyssessgrant" );

				// terminal pool name
				csaArguments.Add( "Ohio1870" );

			}
			break;

			case 65:	// BridgeAPI_EJB::connectBridge Ex3
			{
				// host IP
				csaArguments.Add( "149.2.23.21" );

				// host port
				csaArguments.Add( "83" );

				// terminal model
				csaArguments.Add( "2" );

				// user ID
				csaArguments.Add( "grovercleveland1" );

				// password
				csaArguments.Add( "1886-90" );

				// terminal pool name
				csaArguments.Add( "newyork" );

				// network name
				csaArguments.Add( "allegheny" );

			}
			break;

			case 66:	// BridgeAPI_EJB::connectBridge Ex4
			{
				// host IP
				csaArguments.Add( "149.2.23.21" );

				// host port
				csaArguments.Add( "83" );

				// terminal model
				csaArguments.Add( "2" );

				// user ID
				csaArguments.Add( "benjaminharrison" );

				// password
				csaArguments.Add( "1890-94" );

				// terminal pool name
				csaArguments.Add( "indiana" );

				// network name
				csaArguments.Add( "harrison18k" );

				// term facility like
				csaArguments.Add( "" );

			}
			break;


			case 68:	// BridgeAPI_EJB::findString
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


			case 69:	// BridgeAPI_EJB::findString Ex
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

			}
			break;


			case 70:	// BridgeAPI_EJB::getAllFieldInformation
			{
				// in screen
				csaArguments.Add( "-1" );

				// include color info
				csaArguments.Add( "true" );
			}
			break;

			case 71:	// BridgeAPI_EJB::getAllFieldInformation Ex
			{
				// in screen
				csaArguments.Add( "" );

				// include color info
				csaArguments.Add( "true" );
			}
			break;


			case 73:	// BridgeAPI_EJB::getCurrentScreenName
			{
				// timeout
				csaArguments.Add( "78" );
			}
			break;



			case 75:	// BridgeAPI_EJB::getFieldAttributes
			{
				// screen ID
				csaArguments.Add( "-1" );

				// field name
				csaArguments.Add( "accountID" );
			}
			break;

			case 76:	// BridgeAPI_EJB::getFieldAttributes Ex2
			{
				// screen ID
				csaArguments.Add( "-1" );

				// field index
				csaArguments.Add( "6" );
			}
			break;

			case 77:	// BridgeAPI_EJB::getFieldAttributes Ex3
			{
				// screen ID
				csaArguments.Add( "" );

				// field index
				csaArguments.Add( "3" );
			}
			break;

			case 78:	// BridgeAPI_EJB::getFieldAttributes Ex4
			{
				// screen ID
				csaArguments.Add( "" );

				// field name
				csaArguments.Add( "companyName" );
			}
			break;

			case 79:	// BridgeAPI_EJB::getFieldCoordinates
			{
				// screen ID
				csaArguments.Add( "-1" );

				// field index
				csaArguments.Add( "6" );
			}
			break;

			case 80:	// BridgeAPI_EJB::getFieldCoordinates Ex2
			{
				// screen ID
				csaArguments.Add( "" );

				// field name
				csaArguments.Add( "companyName" );
			}
			break;

			case 81:	// BridgeAPI_EJB::getFieldCoordinates Ex3
			{
				// screen ID
				csaArguments.Add( "" );

				// field name
				csaArguments.Add( "companyName" );
			}
			break;

			case 82:	// BridgeAPI_EJB::getFieldCoordinates Ex4
			{
				// screen ID
				csaArguments.Add( "" );

				// field index
				csaArguments.Add( "3" );
			}
			break;

			case 83:	// BridgeAPI_EJB::getFieldCount
			{
				// screen ID
				csaArguments.Add( "-1" );
			}
			break;

			case 84:	// BridgeAPI_EJB::getFieldCount Ex
			{
				// screen ID
				csaArguments.Add( "" );
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
	Function	:	CAPIGenDlg::ShowCICS11JAVAControls()

	Purpose		:	Show the controls for the CICS Bridge QACom Automation 
					function parameters.

*****************************************************************************/
void CAPIGenDlg::ShowCICS20JAVAControls( int nFunction )
{
	HideParameterControls();
	csaLabels.RemoveAll();
	BOOL bYouShouldGo=TRUE;

	switch ( nFunction )
	{
		case 10:	// BridgeAPI::ChangePassword
		case 62:	// BridgeAPI_EJB::changePassword
		{
			csaLabels.Add("Host IP address");
			csaLabels.Add("Host port");
			csaLabels.Add("User ID");
			csaLabels.Add("Current password");
			csaLabels.Add("New password");
		}
		break;


		case 11:	// BridgeAPI::ConnectBridge
		case 63:	// BridgeAPI_EJB::connectBridge
		{
			csaLabels.Add("Host IP address");
			csaLabels.Add("Host port");
			csaLabels.Add("Terminal model");
			csaLabels.Add("User ID");
			csaLabels.Add("Current password");
			bYouShouldGo=FALSE;
		}
		break;

		case 12:	// BridgeAPI::ConnectBridge Ex2
		case 64:	// BridgeAPI_EJB::connectBridge Ex2
		{
			csaLabels.Add("Host IP address");
			csaLabels.Add("Host port");
			csaLabels.Add("Terminal model");
			csaLabels.Add("User ID");
			csaLabels.Add("Password");
			csaLabels.Add("Terminal pool");
			bYouShouldGo=FALSE;
		}
		break;

		case 13:	// BridgeAPI::ConnectBridge Ex3
		case 65:	// BridgeAPI_EJB::connectBridge Ex3
		{
			csaLabels.Add("Host IP address");
			csaLabels.Add("Host port");
			csaLabels.Add("Terminal model");
			csaLabels.Add("User ID");
			csaLabels.Add("Password");
			csaLabels.Add("Terminal pool");
			csaLabels.Add("Network name");
			bYouShouldGo=FALSE;
		}
		break;

		case 14:	// BridgeAPI::ConnectBridge Ex4
		case 66:	// BridgeAPI_EJB::connectBridge Ex4
		{
			csaLabels.Add("Host IP address");
			csaLabels.Add("Host port");
			csaLabels.Add("Terminal model");
			csaLabels.Add("User ID");
			csaLabels.Add("Password");
			csaLabels.Add("Terminal pool");
			csaLabels.Add("Network name");
			csaLabels.Add("Text format IP address");
			bYouShouldGo=FALSE;
		}
		break;

		case 16:	// BridgeAPI::FindString
		case 17:	// BridgeAPI::FindString Ex
		case 68:	// BridgeAPI_EJB::findString
		case 69:	// BridgeAPI_EJB::findString Ex
		{
			csaLabels.Add("Screen");
			csaLabels.Add("Find this string");
			csaLabels.Add("Start row");
			csaLabels.Add("Start column");
			csaLabels.Add("Flags");
		}
		break;


		case 18:	// BridgeAPI::GetAllFieldInformation
		case 19:	// BridgeAPI::GetAllFieldInformation Ex2
		case 20:	// BridgeAPI::GetAllFieldInformation Ex3
		case 21:	// BridgeAPI::GetAllFieldInformation Ex4
		case 70:	// BridgeAPI_EJB::getAllFieldInformation
		case 71:	// BridgeAPI_EJB::getAllFieldInformation Ex
		{
			csaLabels.Add("Screen");
		}
		break;

		case 23:	// BridgeAPI::GetCurrentScreenName
		case 73:	// BridgeAPI_EJB::getCurrentScreenName
		{
			csaLabels.Add("Timeout (ms)");
		}
		break;

		case 25:	// BridgeAPI::GetFieldAttributes
		case 26:	// BridgeAPI::GetFieldAttributes Ex2
		case 27:	// BridgeAPI::GetFieldAttributes Ex3
		case 28:	// BridgeAPI::GetFieldAttributes Ex4
		case 29:	// BridgeAPI::GetFieldCoordinates
		case 30:	// BridgeAPI::GetFieldCoordinates Ex2
		case 31:	// BridgeAPI::GetFieldCoordinates Ex3
		case 32:	// BridgeAPI::GetFieldCoordinates Ex4
		case 75:	// BridgeAPI_EJB::getFieldAttributes
		case 76:	// BridgeAPI_EJB::getFieldAttributes Ex2
		case 77:	// BridgeAPI_EJB::getFieldAttributes Ex3
		case 78:	// BridgeAPI_EJB::getFieldAttributes Ex4
		case 79:	// BridgeAPI_EJB::getFieldCoordinates
		case 80:	// BridgeAPI_EJB::getFieldCoordinates Ex2
		case 81:	// BridgeAPI_EJB::getFieldCoordinates Ex3
		case 82:	// BridgeAPI_EJB::getFieldCoordinates Ex4
		{
			csaLabels.Add("Screen");
			csaLabels.Add("Field");
		}
		break;

		case 33:	// BridgeAPI::GetFieldCount
		case 34:	// BridgeAPI::GetFieldCount Ex
		case 83:	// BridgeAPI_EJB::getFieldCount
		case 84:	// BridgeAPI_EJB::getFieldCount Ex
		{
			csaLabels.Add("Screen");
		}
		break;

		case 35:	// BridgeAPI::GetFieldNameFromIndex
		case 36:	// BridgeAPI::GetFieldNameFromIndex Ex
		case 37:	// BridgeAPI::GetFieldValue
		case 38:	// BridgeAPI::GetFieldValue Ex2
		case 39:	// BridgeAPI::GetFieldValue Ex3
		case 40:	// BridgeAPI::GetFieldValue Ex4
		case 85:	// BridgeAPI_EJB::getFieldNameFromIndex
		case 86:	// BridgeAPI_EJB::getFieldNameFromIndex Ex
		case 87:	// BridgeAPI_EJB::getFieldValue
		case 88:	// BridgeAPI_EJB::getFieldValue Ex2
		case 89:	// BridgeAPI_EJB::getFieldValue Ex3
		case 90:	// BridgeAPI_EJB::getFieldValue Ex4
		{
			csaLabels.Add("Screen");
			csaLabels.Add("Field");
		}
		break;

		case 41:	// BridgeAPI::getReturnCodeMessage
		case 91:	// BridgeAPI_EJB::getReturnCodeMessage
		{
			csaLabels.Add("Return code");
		}
		break;

		case 42:	// BridgeAPI::GetScreenSize
		case 43:	// BridgeAPI::GetScreenSize Ex
		case 92:	// BridgeAPI_EJB::getScreenSize
		case 93:	// BridgeAPI_EJB::getScreenSize Ex
		{
			csaLabels.Add("Screen");
		}
		break;

		case 44:	// BridgeAPI::GetString
		case 45:	// BridgeAPI::GetString Ex
		case 94:	// BridgeAPI_EJB::getString
		case 95:	// BridgeAPI_EJB::getString Ex
		{
			csaLabels.Add("Screen");
			csaLabels.Add("Start row");
			csaLabels.Add("Start column");
			csaLabels.Add("Length");
		}
		break;

		case 46:	// BridgeAPI::GetTransactionSystemId
		case 96:	// BridgeAPI_EJB::getTransactionSystemId
		{
			csaLabels.Add("Host IP address");
			csaLabels.Add("Host port");
			csaLabels.Add("Transaction ID");
		}
		break;

		case 47:	// BridgeAPI::PutString
		case 97:	// BridgeAPI_EJB::putString
		{
			csaLabels.Add("Text");
			csaLabels.Add("Row");
			csaLabels.Add("Column");
		}
		break;

		case 48:	// BridgeAPI::SendKeys
		case 49:	// BridgeAPI::SendKeysEx
		case 50:	// BridgeAPI::SendKeysGetAllFieldInformation
		case 98:	// BridgeAPI_EJB::sendKeys
		case 99:	// BridgeAPI_EJB::sendKeysEx
		case 100:	// BridgeAPI_EJB::sendKeysGetAllFieldInformation
		{
			csaLabels.Add("Keys");
		}
		break;

		case 51:	// BridgeAPI::SendKeysGetString
		case 101:	// BridgeAPI_EJB::sendKeysGetString
		{
			csaLabels.Add("Keys");
			csaLabels.Add("Row");
			csaLabels.Add("Column");
			csaLabels.Add("Length");
		}
		break;

		case 52:	// BridgeAPI::SetCursorPosition
		case 102:	// BridgeAPI_EJB::setCursorPosition
		{
			csaLabels.Add("Row");
			csaLabels.Add("Column");
		}
		break;

		case 53:	// BridgeAPI::SetFieldValue
		case 54:	// BridgeAPI::SetFieldValue Ex2
		case 55:	// BridgeAPI::SetFieldValue Ex3
		case 103:	// BridgeAPI_EJB::setFieldValue
		case 104:	// BridgeAPI_EJB::setFieldValue Ex2
		case 105:	// BridgeAPI_EJB::setFieldValue Ex3
		{
			csaLabels.Add("Field");
			csaLabels.Add("Value");
		}
		break;

		case 56:	// BridgeAPI::SetSettleTime
		case 106:	// BridgeAPI_EJB::setSettleTime
		{
			csaLabels.Add("Settle time");
		}
		break;

		case 57:	// BridgeAPI::SetTimeOut
		case 107:	// BridgeAPI_EJB::setTimeOut
		{
			csaLabels.Add("Timeout");
		}
		break;

		case 58:	// BridgeAPI::SetTraceActive
		case 60:	// BridgeAPI::SetTraceName
		case 108:	// BridgeAPI_EJB::setTraceActive
		case 110:	// BridgeAPI_EJB::setTraceName
		{
			csaLabels.Add("Temporary storage queue");
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



