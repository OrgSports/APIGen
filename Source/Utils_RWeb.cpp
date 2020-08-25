#include "stdafx.h"
#include "APIGen.h"
#include "APIGenDlg.h"

/****************************************************************************DC
	Function	:	CAPIGenDlg::LoadRWeb_ArgumentArray()

	Purpose		:	Load the function arguments for RWeb.

*****************************************************************************/
void CAPIGenDlg::LoadRWeb_ArgumentArray( int* nFunctionPosition, BOOL bPromptForValues )
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
			// zero arguments
			case 0:	// ECLField::clearField
			case 2: // ECLField::GetAttribute
			case 3: // 	ECLField::GetEnd
			case 4: // 	ECLField::GetEndCol
			case 5: // 	ECLField::GetEndRow
			case 6: // 	ECLField::GetLength
			case 9:		// ECLField::GetStart
			case 10:	// ECLField::GetStartCol
			case 11:	// ECLField::GetStartRow
			case 12:	// ECLField::GetString
			case 14:	// ECLField::IsDisplay
			case 15:	// ECLField::IsHighIntensity
			case 16:	// ECLField::IsModified
			case 17:	// ECLField::IsNumeric
			case 18:	// ECLField::IsPenDetectable
			case 19:	// ECLField::IsProtected
			case 20:	// ECLField::IsTransmitOnly
			case 28:	// ECLFieldList::GetFieldCount
			case 29:	// ECLFieldList::GetFirstField
			case 31:	// ECLFieldList::GetNextField
			case 33:	// ECLFieldList::Refresh
			case 35:	// ECLOIA::GetHPStatusFlags
			case 36:	// ECLOIA::GetParent
			case 37:	// ECLOIA::GetStatusFlags
			case 38:	// ECLOIA::InputInhibited
			case 39:	// ECLOIA::IsAlphanumeric
			case 40:	// ECLOIA::IsCommErrorReminder
			case 41:	// ECLOIA::IsDBCS
			case 42:	// ECLOIA::IsHPBlockMode
			case 43:	// ECLOIA::IsHPFormatMode
			case 44:	// ECLOIA::IsInsertMode
			case 45:	// ECLOIA::IsMessageWaiting
			case 46:	// ECLOIA::IsNumeric
			case 47:	// ECLOIA::RegisterOIAEvent
			case 49:	// ECLOIA::UnregisterOIAEvent
			case 50:	// ECLOIA::WaitForInput
			case 58:	// ECLPS::GetCursorCol
			case 59:	// ECLPS::GetCursorPos
			case 60:	// ECLPS::GetCursorRow
			case 61:	// ECLPS::GetCursorVisible
			case 62:	// ECLPS::GetFieldList
			case 64:	// ECLPS::GetParent
			case 77:	// ECLPS::GetSendKeyMnemonics
			case 78:	// ECLPS::getSendKeysKeyboardUnlockTimeout
			case 79:	// ECLPS::GetSize
			case 80:	// ECLPS::GetSizeCols
			case 81:	// ECLPS::GetSizeRows
			case 82:	// ECLPS::GetString
			case 88:	// ECLPS::RegisterPSEvent
			case 110:	// ECLPS::UnregisterPSEvent
			case 116:	// ECLPS::WaitForScreen
			case 123:	// ECLPS::WaitWhileScreen
			case 128:	// ECLSession::addMessageServiceListener
			case 129:	// ECLSession::apiExit
			case 132:	// ECLSession::cancelFileXfer
			case 133:	// ECLSession::cancelPrintJob
			case 134:	// ECLSession::closePrinter
			case 135:	// ECLSession::connect
			case 136:	// ECLSession::disconnect
			case 138:	// ECLSession::dispose
			case 141:	// ECLSession::endPrintJob
			case 142:	// ECLSession::exit
			case 146:	// ECLSession::flushPrintJob
			case 147:	// ECLSession::ftpAbort
			case 149:	// ECLSession::ftpDisconnect
			case 150:	// ECLSession::ftpGetLastServerResponse
			case 153:	// ECLSession::ftpPwd
			case 159:	// ECLSession::getCursorColumn
			case 160:	// ECLSession::getCursorPosition
			case 161:	// ECLSession::getCursorRow
			case 164:	// ECLSession::getEmulatorApplet
			case 166:	// ECLSession::getFrameBounds
			case 167:	// ECLSession::getHostName
			case 169:	// ECLSession::getHostURL
			case 171:	// ECLSession::getJSAPI
			case 172:	// ECLSession::GetOIA
			case 174:	// ECLSession::getPort
			case 178:	// ECLSession::getPrintToFileFolder
			case 179:	// ECLSession::getPrintToFileName
			case 180:	// ECLSession::GetPS					// 180
			case 181:	// ECLSession::getSelectionBounds
			case 183:	// ECLSession::GetXfer
			case 187:	// ECLSession::isConnected
			case 188:	// ECLSession::isIBM
			case 189:	// ECLSession::isStream
			case 197:	// ECLSession::printTestPage
			case 199:	// ECLSession::requestDisplayFocus
			case 200:	// ECLSession::resetUserPreferences
			case 201:	// ECLSession::saveUserPreferences
			case 202:	// ECLSession::screenPrint
			case 215:	// ECLSession::startPrintJob
			case 230:	// ECLXfer::Cancel
			case 231:	// ECLXfer::GetParent
			case 232:	// ECLXfer::GetStartTimeout
			case 233:	// ECLXfer::GetTimeout
			{

			}
			break;

			// ***** one edit control		
			case 1:		// ECLField::equals
			case 13:	// ECLField::GetString 2
			case 21:	// ECLField::SetString
			case 22:	// ECLField::SetText
			case 23:	// ECLFieldList::FindField
			case 48:	// ECLOIA::setKeyboardUnlockDuration
			case 51:	// ECLOIA::WaitForInput 2
			case 52:	// ECLPS::ConvertPosToCol
			case 54:	// ECLPS::ConvertPosToRow
			case 65:	// ECLPS::GetPosForRowFromEnd
			case 83:	// ECLPS::GetString 2
			case 96:	// ECLPS::SendKeys
			case 99:	// ECLPS::SetCursorPos
			case 102:	// ECLPS::setSendKeysKeyboardUnlockTimeout
			case 103:	// ECLPS::SetString
			case 104:	// ECLPS::SetString 2
			case 106:	// ECLPS::SetText
			case 114:	// ECLPS::WaitForHostPrompt
			case 117:	// ECLPS::WaitForScreen 2
			case 118:	// ECLPS::WaitForString
			case 124:	// ECLPS::WaitWhileScreen 2
			case 125:	// ECLPS::WaitWhileString
			case 140:	// ECLSession::doJavaScriptEval
			case 143:	// ECLSession::exportKeymap
			case 148:	// ECLSession::ftpCd
			case 151:	// ECLSession::ftpLCd
			case 158:	// ECLSession::getBoolean
			case 170:	// ECLSession::getInteger
			case 173:	// ECLSession::getParameter
			case 182:	// ECLSession::getString
			case 184:	// ECLSession::importKeymap
			case 190:	// ECLSession::loadComponent
			case 193:	// ECLSession::playbackMacro
			case 194:	// ECLSession::printBytes
			case 195:	// ECLSession::printCharacter
			case 196:	// ECLSession::printString
			case 198:	// ECLSession::removeMessageServiceListener
			case 205:	// ECLSession::setHostURL
			case 210:	// ECLSession::setPrintToFileFolder
			case 211:	// ECLSession::setPrintToFileName
			case 213:	// ECLSession::showDialog
			case 216:	// ECLSession::transmitString
			case 217:	// ECLSession::transmitTerminalKey
			case 237:	// ECLXfer::SetStartTimeout
			case 238:	// ECLXfer::SetTimeout
			case 235:	// ECLXfer::RegisterXferEvent
			case 240:	// ECLXfer::UnregisterXferEvent
			{
				// single argument
				csaArguments.Add( m_csEditArgument1 );
			}
			break;


			// ***** two edit controls
			case 24:	// ECLFieldList::FindField 2
			case 56:	// ECLPS::ConvertRowColToPos
			case 66:	// ECLPS::getRow
			case 86:	// ECLPS::GetString 5
			case 97:	// ECLPS::SendKeys 2
			case 100:	// ECLPS::SetCursorPos 2				// 100
			case 107:	// ECLPS::SetText 2
			case 109:	// ECLPS::spacePadString
			case 112:	// ECLPS::WaitForCursor
			case 115:	// ECLPS::WaitForHostPrompt 2
			case 121:	// ECLPS::WaitWhileCursor
			case 139:	// ECLSession::doJavaScriptCall
			case 168:	// ECLSession::getHostStatusText
			case 204:	// ECLSession::setCursorPosition
			case 221:	// ECLSession::waitForDisplayString
			case 222:	// ECLSession::waitForDisplayStrings
			case 223:	// ECLSession::waitForHostPrompt
			case 224:	// ECLSession::waitForKeyboardLock
			case 225:	// ECLSession::waitForKeyboardUnlock
			case 226:	// ECLSession::waitForString
			case 206:	// ECLSession::setInteger
			case 212:	// ECLSession::setString
			{
				// first argument
				csaArguments.Add( m_csEditArgument1 );

				// second argument
				csaArguments.Add( m_csEditArgument3 );
			}
			break;


			case 7:		//ECLField::GetScreen
			case 67:	// ECLPS::GetScreen 1
			case 25:	// ECLFieldList::FindField 3
			case 90:	// ECLPS::SearchString
			case 93:	// ECLPS::SearchText
			case 32:	// ECLFieldList::GetNextField 2
			case 155:	// ECLSession::ftpReceiveFiles
			case 157:	// ECLSession::ftpSendFiles
			{
				Read1E1L( &csaArguments );
			}
			break;

			case 8:		// ECLField::GetScreen 2
			case 70:	// ECLPS::GetScreen 4
			case 30:	// ECLFieldList::GetFirstField 2
			case 34:	// ECLFieldList::Refresh 2
			case 63:	// ECLPS::GetFieldList 2
			case 89:	// ECLPS::RegisterPSEvent 2
			case 111:	// ECLPS::UnregisterPSEvent 2
			case 175:	// ECLSession::getPrinterMargin
			case 239:	// ECLXfer::setTransferHostType
			{
				Read1L( &csaArguments );
			}
			break;

			case 26:	// ECLFieldList::FindField 4
			case 71:	// ECLPS::GetScreen 5
			case 75:	// ECLPS::GetScreenRect 3
			case 91:	// ECLPS::SearchString 2
			case 94:	// ECLPS::SearchText 2
			case 234:	// ECLXfer::ReceiveFile
			case 236:	// ECLXfer::SendFile
			{
				Read2E1L( &csaArguments );
			}
			break;
			
			case 27:	// ECLFieldList::FindField 5
			case 72:	// ECLPS::GetScreen 6
			case 92:	// ECLPS::SearchString 3
			case 95:	// ECLPS::SearchText 3
			case 68:	// ECLPS::GetScreen 2
			case 73:	// ECLPS::GetScreenRect
			{
				Read3E1L( &csaArguments );
			}
			break;
			
			case 69:	// ECLPS::GetScreen 3
			case 76:	// ECLPS::GetScreenRect 4
			{
				Read4E1L( &csaArguments );
			}
			break;

			case 74:	// ECLPS::GetScreenRect 2
			{
				Read5E1L( &csaArguments );
			}
			break;

			case 101:	// ECLPS::SetCursorVisible
			case 214:	// ECLSession::ShowPSDebugger
			{
				Read1C( &csaArguments );
			}
			break;


			case 113:	// ECLPS::WaitForCursor 2
			case 122:	// ECLPS::WaitWhileCursor 2
			case 145:	// ECLSession::findText
			{
				Read3E1C( &csaArguments );
			}
			break;

			case 120:	// ECLPS::WaitForString 3
			{
				Read4E2C( &csaArguments );
			}
			break;


			case 127:	// ECLPS::WaitWhileString 3
			case 191:	// ECLSession::makeTextSelection
			case 229:	// ECLSession::waitWhileDisplayString 3
			case 152:	// ECLSession::ftpLogin
			{
				Read4E1C( &csaArguments );
			}
			break;

			case 130:	// ECLSession::apvuReceiveFile
			case 131:	// ECLSession::apvuSendFile
			{
				Read2E1L1C( &csaArguments );
			}
			break;

			case 137:	// ECLSession::display
			case 192:	// ECLSession::passwordPrompt
			case 203:	// ECLSession::setBoolean
			case 227:	// ECLSession::waitWhileDisplayString	
			{
				Read1E1C( &csaArguments );
			}
			break;

			case 144:	// ECLSession::findField
			{
				Read2E2L( &csaArguments );
			}
			break;

			case 154:	// ECLSession::ftpReceiveFile
			{
				Read2E1C( &csaArguments );
			}
			break;

			case 156:	// ECLSession::ftpSendFile
			case 185:	// ECLSession::indReceiveFile
			case 186:	// ECLSession::indSendFile
			{
				Read2E2C( &csaArguments );
			}
			break;

			case 207:	// ECLSession::setPrinterMargin
			{
				Read1L1E( &csaArguments );
			}
			break;

			case 208:	// ECLSession::setPrinterPageSize
			{
				Read1L1E( &csaArguments );
			}
			break;

			case 209:	// ECLSession::setPrintScaling
			{
				Read1L1E( &csaArguments );
			}
			break;


			// three edit controls
			case 53:	// ECLPS::ConvertPosToColX
			case 55:	// ECLPS::ConvertPosToRowX
			case 57:	// ECLPS::ConvertRowColToPosX
			case 84:	// ECLPS::GetString 3
			case 87:	// ECLPS::GetString 6
			case 98:	// ECLPS::SendKeys 3
			case 105:	// ECLPS::SetString 3
			case 108:	// ECLPS::SetText 3
			case 119:	// ECLPS::WaitForString 2
			case 126:	// ECLPS::WaitWhileString 2
			case 162:	// ECLSession::getDisplayText
			case 165:	// ECLSession::getFieldText
			case 218:	// ECLSession::waitForCursorEntered
			case 219:	// ECLSession::waitForCursorLeft
			{
				// first argument
				csaArguments.Add( m_csEditArgument1 );

				// second argument
				csaArguments.Add( m_csEditArgument3 );

				// third argument
				csaArguments.Add( m_csEditArgument4 );
			}
			break;


			// four edit controls
			case 85:	// ECLPS::GetString 4
			case 163:	// ECLSession::getDisplayText
			case 220:	// ECLSession::waitForDisplayString
			{
				// first argument
				csaArguments.Add( m_csEditArgument1 );

				// second argument
				csaArguments.Add( m_csEditArgument3 );

				// third argument
				csaArguments.Add( m_csEditArgument4 );

				// fourth argument
				csaArguments.Add( m_csEditArgument5 );

			}
			break;

		}
	}
	else
	{
		switch ( *nFunctionPosition )
		{
			case 0:	// ECLField::clearField
			case 2: // ECLField::GetAttribute
			case 3: // 	ECLField::GetEnd
			case 4: // 	ECLField::GetEndCol
			case 5: // 	ECLField::GetEndRow
			case 6: // 	ECLField::GetLength
			case 9:		// ECLField::GetStart
			case 10:	// ECLField::GetStartCol
			case 11:	// ECLField::GetStartRow
			case 12:	// ECLField::GetString
			case 14:	// ECLField::IsDisplay
			case 15:	// ECLField::IsHighIntensity
			case 16:	// ECLField::IsModified
			case 17:	// ECLField::IsNumeric
			case 18:	// ECLField::IsPenDetectable
			case 19:	// ECLField::IsProtected
			case 20:	// ECLField::IsTransmitOnly
			case 28:	// ECLFieldList::GetFieldCount
			case 29:	// ECLFieldList::GetFirstField
			case 33:	// ECLFieldList::Refresh
			case 35:	// ECLOIA::GetHPStatusFlags
			case 36:	// ECLOIA::GetParent
			case 37:	// ECLOIA::GetStatusFlags
			case 38:	// ECLOIA::InputInhibited
			case 39:	// ECLOIA::IsAlphanumeric
			case 40:	// ECLOIA::IsCommErrorReminder
			case 41:	// ECLOIA::IsDBCS
			case 42:	// ECLOIA::IsHPBlockMode
			case 43:	// ECLOIA::IsHPFormatMode
			case 44:	// ECLOIA::IsInsertMode
			case 45:	// ECLOIA::IsMessageWaiting
			case 46:	// ECLOIA::IsNumeric
			case 50:	// ECLOIA::WaitForInput
			case 58:	// ECLPS::GetCursorCol
			case 59:	// ECLPS::GetCursorPos
			case 60:	// ECLPS::GetCursorRow
			case 61:	// ECLPS::GetCursorVisible
			case 62:	// ECLPS::GetFieldList
			case 64:	// ECLPS::GetParent
			case 77:	// ECLPS::GetSendKeyMnemonics
			case 78:	// ECLPS::getSendKeysKeyboardUnlockTimeout
			case 79:	// ECLPS::GetSize
			case 80:	// ECLPS::GetSizeCols
			case 81:	// ECLPS::GetSizeRows
			case 82:	// ECLPS::GetString
			case 88:	// ECLPS::RegisterPSEvent
			case 110:	// ECLPS::UnregisterPSEvent
			case 116:	// ECLPS::WaitForScreen
			case 123:	// ECLPS::WaitWhileScreen
			case 128:	// ECLSession::addMessageServiceListener
			case 129:	// ECLSession::apiExit
			case 132:	// ECLSession::cancelFileXfer
			case 133:	// ECLSession::cancelPrintJob
			case 134:	// ECLSession::closePrinter
			case 135:	// ECLSession::connect
			case 136:	// ECLSession::disconnect
			case 138:	// ECLSession::dispose
			case 141:	// ECLSession::endPrintJob
			case 142:	// ECLSession::exit
			case 146:	// ECLSession::flushPrintJob
			case 147:	// ECLSession::ftpAbort
			case 149:	// ECLSession::ftpDisconnect
			case 150:	// ECLSession::ftpGetLastServerResponse
			case 153:	// ECLSession::ftpPwd
			case 159:	// ECLSession::getCursorColumn
			case 160:	// ECLSession::getCursorPosition
			case 161:	// ECLSession::getCursorRow
			case 164:	// ECLSession::getEmulatorApplet
			case 166:	// ECLSession::getFrameBounds
			case 167:	// ECLSession::getHostName
			case 169:	// ECLSession::getHostURL
			case 171:	// ECLSession::getJSAPI
			case 172:	// ECLSession::GetOIA
			case 174:	// ECLSession::getPort
			case 178:	// ECLSession::getPrintToFileFolder
			case 179:	// ECLSession::getPrintToFileName
			case 180:	// ECLSession::GetPS
			case 181:	// ECLSession::getSelectionBounds
			case 183:	// ECLSession::GetXfer
			case 184:	// ECLSession::importKeymap
			case 187:	// ECLSession::isConnected
			case 188:	// ECLSession::isIBM
			case 189:	// ECLSession::isStream
			case 197:	// ECLSession::printTestPage
			case 199:	// ECLSession::requestDisplayFocus
			case 200:	// ECLSession::resetUserPreferences
			case 201:	// ECLSession::saveUserPreferences
			case 202:	// ECLSession::screenPrint
			case 215:	// ECLSession::startPrintJob
			case 230:	// ECLXfer::Cancel
			case 231:	// ECLXfer::GetParent
			case 232:	// ECLXfer::GetStartTimeout
			case 233:	// ECLXfer::GetTimeout
			{
			}
			break;

			case 1: // ECLField::equals
			{
				// screen plane
				csaArguments.Add( "FieldX" );
			}
			break;

			case 7:		// ECLField::GetScreen
			{
				// buffer size
				csaArguments.Add( "8" );
				// screen plane
				csaArguments.Add( "TEXT_PLANE" );
			}
			break;

			case 8:	// ECLField::GetScreen 2
			{
				// screen plane
				csaArguments.Add( "TEXT_PLANE" );
			}
			break;

			case 13:	// ECLField::GetString 2
			{
				// buffer size
				csaArguments.Add( "8" );
			}
			break;

			case 21:	// ECLField::SetString
			case 22:	// ECLField::SetText
			case 103:	// ECLPS::SetString
			case 106:	// ECLPS::SetText
			{
				// string
				csaArguments.Add( "myUserID" );
			}
			break;

			case 23:	// ECLFieldList::FindField
			case 52:	// ECLPS::ConvertPosToCol
			case 54:	// ECLPS::ConvertPosToRow
			{
				// position
				csaArguments.Add( "1637" );
			}
			break;

			case 24:	// ECLFieldList::FindField 2
			case 204:	// ECLSession::setCursorPosition
			{
				// row
				csaArguments.Add( "21" );

				// column
				csaArguments.Add( "8" );
			}
			break;

			case 25:	// ECLFieldList::FindField 3
			case 90:	// ECLPS::SearchString
			case 93:	// ECLPS::SearchText
			{
				// search text
				csaArguments.Add( "Username" );

				// direction
				csaArguments.Add( "SEARCH_FORWARD" );
			}
			break;

			case 26:	// ECLFieldList::FindField 4
			case 91:	// ECLPS::SearchString 2
			case 94:	// ECLPS::SearchText 2
			{
				// search text
				csaArguments.Add( "Username" );

				// position
				csaArguments.Add( "8" );

				// direction
				csaArguments.Add( "SEARCH_FORWARD" );
			}
			break;

			case 27:	// ECLFieldList::FindField 5
			case 92:	// ECLPS::SearchString 3
			case 95:	// ECLPS::SearchText 3
			{
				// search text
				csaArguments.Add( "Username" );

				// row
				csaArguments.Add( "21" );

				// column
				csaArguments.Add( "8" );

				// direction
				csaArguments.Add( "SEARCH_FORWARD" );
			}
			break;

			case 30:	// ECLFieldList::GetFirstField 2	//30
			{
				// field type
				csaArguments.Add( "NUMERIC_FIELD" );
			}
			break;

			case 31:	// ECLFieldList::GetNextField
			{
				// field name
				csaArguments.Add( "field16" );
			}
			break;

			case 32:	// ECLFieldList::GetNextField 2
			{
				// field name
				csaArguments.Add( "field16" );
				// field type
				csaArguments.Add( "NUMERIC_FIELD" );
			}
			break;

			case 34:	// ECLFieldList::Refresh 2
			{
				// plane
				csaArguments.Add( "COLOR_PLANE" );
			}
			break;

			case 47:	// ECLOIA::RegisterOIAEvent
			{
				// event
				csaArguments.Add( "EventHandler1" );
			}
			break;

			case 48:	// ECLOIA::setKeyboardUnlockDuration
			case 51:	// ECLOIA::WaitForInput 2
			case 83:	// ECLPS::GetString 2
			case 102:	// ECLPS::setSendKeysKeyboardUnlockTimeout
			case 117:	// ECLPS::WaitForScreen 2
			case 124:	// ECLPS::WaitWhileScreen 2
			case 237:	// ECLXfer::SetStartTimeout
			case 238:	// ECLXfer::SetTimeout
			{
				// duration
				csaArguments.Add( "101" );
			}
			break;

			case 49:	// ECLOIA::UnregisterOIAEvent
			case 111:	// ECLPS::UnregisterPSEvent 2
			{
				// event
				csaArguments.Add( "AIDKeyEvent" );
			}
			break;

			case 53:	// ECLPS::ConvertPosToColX
			case 55:	// ECLPS::ConvertPosToRowX
			{
				// position
				csaArguments.Add( "1921" );

				// rows
				csaArguments.Add( "43" );

				// columns
				csaArguments.Add( "80" );

			}
			break;

			case 56:	// ECLPS::ConvertRowColToPos
			{
				// row
				csaArguments.Add( "11" );

				// column
				csaArguments.Add( "8" );

			}
			break;

			case 57:	// ECLPS::ConvertRowColToPosX
			{
				// row
				csaArguments.Add( "11" );

				// column
				csaArguments.Add( "8" );

				// columns
				csaArguments.Add( "80" );

			}
			break;

			case 63:	// ECLPS::GetFieldList
			case 70:	// ECLPS::GetScreen 4
			{
				// screen plane
				csaArguments.Add( "TEXT_PLANE" );
			}
			break;

			case 65:	// ECLPS::GetPosForRowFromEnd
			{
				// rows back
				csaArguments.Add( "11" );
			}
			break;

			case 66:	// ECLPS::getRow
			{
				// position
				csaArguments.Add( "111" );
				// columns
				csaArguments.Add( "80" );

			}
			break;

			case 67:	// ECLPS::GetScreen
			{
				// length
				csaArguments.Add( "1920" );

				// screen plane
				csaArguments.Add( "TEXT_PLANE" );
			}
			break;

			case 68:	// ECLPS::GetScreen 2
			{
				// buffer length
				csaArguments.Add( "1920" );

				// position
				csaArguments.Add( "111" );

				// length
				csaArguments.Add( "18" );

				// screen plane
				csaArguments.Add( "TEXT_PLANE" );
			}
			break;

			case 69:	// ECLPS::GetScreen 3
			{
				// buffer length
				csaArguments.Add( "1920" );

				// row
				csaArguments.Add( "21" );

				// column
				csaArguments.Add( "1" );

				// length
				csaArguments.Add( "18" );

				// screen plane
				csaArguments.Add( "TEXT_PLANE" );
			}
			break;

			case 71:	// ECLPS::GetScreen 5
			{
				// position
				csaArguments.Add( "111" );

				// length
				csaArguments.Add( "18" );

				// screen plane
				csaArguments.Add( "TEXT_PLANE" );
			}
			break;

			case 72:	// ECLPS::GetScreen 6
			case 73:	// ECLPS::GetScreenRect
			{
				// row
				csaArguments.Add( "21" );

				// column
				csaArguments.Add( "1" );

				// length
				csaArguments.Add( "18" );

				// screen plane
				csaArguments.Add( "TEXT_PLANE" );
			}
			break;

			case 74:	// ECLPS::GetScreenRect 2
			{
				// buffer length
				csaArguments.Add( "64" );

				// row
				csaArguments.Add( "21" );

				// column
				csaArguments.Add( "1" );

				// row
				csaArguments.Add( "21" );

				// column
				csaArguments.Add( "43" );

				// screen plane
				csaArguments.Add( "TEXT_PLANE" );
			}
			break;

			case 75:	// ECLPS::GetScreenRect 3
			{
				// column
				csaArguments.Add( "1" );

				// length
				csaArguments.Add( "18" );

				// screen plane
				csaArguments.Add( "TEXT_PLANE" );
			}
			break;

			case 76:	// ECLPS::GetScreenRect 4
			{
				// row
				csaArguments.Add( "21" );

				// column
				csaArguments.Add( "1" );

				// row
				csaArguments.Add( "21" );

				// column
				csaArguments.Add( "43" );

				// screen plane
				csaArguments.Add( "TEXT_PLANE" );
			}
			break;

			case 84:	// ECLPS::GetString 3
			{
				// buffer length
				csaArguments.Add( "64" );

				// position
				csaArguments.Add( "21" );

				// length
				csaArguments.Add( "101" );
			}
			break;

			case 85:	// ECLPS::GetString 4
			{
				// buffer length
				csaArguments.Add( "64" );

				// row
				csaArguments.Add( "1" );

				// column
				csaArguments.Add( "21" );

				// length
				csaArguments.Add( "101" );
			}
			break;

			case 86:	// ECLPS::GetString 5
			{
				// position
				csaArguments.Add( "21" );

				// length
				csaArguments.Add( "101" );
			}
			break;

			case 87:	// ECLPS::GetString 6
			{
				// row
				csaArguments.Add( "1" );

				// column
				csaArguments.Add( "21" );

				// length
				csaArguments.Add( "101" );
			}
			break;

			case 89:	// ECLPS::RegisterPSEvent 2
			{
				// event type
				csaArguments.Add( "USER_EVENTS" );
			}
			break;

			case 96:	// ECLPS::SendKeys
			{
				// string
				csaArguments.Add( "myUserID[enter]" );
			}
			break;

			case 97:	// ECLPS::SendKeys 2
			{
				// string
				csaArguments.Add( "myUserID[enter]" );

				// position
				csaArguments.Add( "1637" );
			}
			break;

			case 98:	// ECLPS::SendKeys 3
			{
				// string
				csaArguments.Add( "myUserID[enter]" );

				// row
				csaArguments.Add( "16" );

				// column
				csaArguments.Add( "1517" );

			}
			break;

			case 99:	// ECLPS::SetCursorPos
			{
				// position
				csaArguments.Add( "1637" );
			}
			break;

			case 100:	// ECLPS::SetCursorPos 2				// 100
			case 112:	// ECLPS::WaitForCursor
			case 121:	// ECLPS::WaitWhileCursor
			{
				// row
				csaArguments.Add( "1" );

				// column
				csaArguments.Add( "21" );
			}
			break;

			case 101:	// ECLPS::SetCursorVisible
			case 214:	// ECLSession::ShowPSDebugger
			{
				// position
				csaArguments.Add( "TRUE" );
			}
			break;

			case 104:	// ECLPS::SetString 2
			case 107:	// ECLPS::SetText 2
			{
				// string
				csaArguments.Add( "MyUserID" );

				// position
				csaArguments.Add( "1637" );
			}
			break;

			case 105:	// ECLPS::SetString 3
			case 108:	// ECLPS::SetText 3
			{
				// string
				csaArguments.Add( "MyUserID" );

				// row
				csaArguments.Add( "1" );

				// column
				csaArguments.Add( "21" );
			}
			break;

			case 109:	// ECLPS::spacePadString
			{
				// string
				csaArguments.Add( "VST2330" );

				// columns
				csaArguments.Add( "8" );
			}
			break;

			case 113:	// ECLPS::WaitForCursor 2
			case 122:	// ECLPS::WaitWhileCursor 2
			{
				// row
				csaArguments.Add( "1" );

				// column
				csaArguments.Add( "21" );

				// timeout
				csaArguments.Add( "3000" );

				// wait for input
				csaArguments.Add( "TRUE" );

			}
			break;

			case 114:	// ECLPS::WaitForHostPrompt
			case 118:	// ECLPS::WaitForString
			case 125:	// ECLPS::WaitWhileString
			{
				// host string
				csaArguments.Add( "Ready" );

			}
			break;

			case 115:	// ECLPS::WaitForHostPrompt 2
			{
				// host string
				csaArguments.Add( "Ready" );

				// timeout
				csaArguments.Add( "3000" );
			}
			break;

			case 119:	// ECLPS::WaitForString 2
			case 126:	// ECLPS::WaitWhileString 2
			{
				// string
				csaArguments.Add( "Ready" );

				// row
				csaArguments.Add( "1" );

				// column
				csaArguments.Add( "21" );
			}
			break;

			case 120:	// ECLPS::WaitForString 3
			{
				// string
				csaArguments.Add( "Ready" );

				// row
				csaArguments.Add( "1" );

				// column
				csaArguments.Add( "21" );

				// timeout
				csaArguments.Add( "3000" );

				// wait for input
				csaArguments.Add( "TRUE" );

				// case
				csaArguments.Add( "FALSE" );

			}
			break;

			case 127:	// ECLPS::WaitWhileString 3
			{
				// string
				csaArguments.Add( "Ready" );

				// row
				csaArguments.Add( "1" );

				// column
				csaArguments.Add( "21" );

				// timeout
				csaArguments.Add( "3000" );

				// wait for input
				csaArguments.Add( "TRUE" );

				// case
				csaArguments.Add( "FALSE" );
			}
			break;

			case 130:	// ECLSession::apvuReceiveFile		// 130
			case 131:	// ECLSession::apvuSendFile
			{
				// PC filename
				csaArguments.Add( "c:\\sysback\\marketfile.txt" );

				// Host filename
				csaArguments.Add( "market txt" );

				// transfer type
				csaArguments.Add( "ID_HOST_TYPE_CMS" );

				// show status
				csaArguments.Add( "TRUE" );

			}
			break;

			case 137:	// ECLSession::display
			{
				// string
				csaArguments.Add( "Over here!" );

				// interpret
				csaArguments.Add( "TRUE" );
			}
			break;

			case 139:	// ECLSession::doJavaScriptCall
			{
				// function
				csaArguments.Add( "getNetSales" );

				// arguments
				csaArguments.Add( "gnsArgs" );
			}
			break;

			case 140:	// ECLSession::doJavaScriptEval		// 140
			{
				// function
				csaArguments.Add( "getNetSales" );
			}
			break;

			case 143:	// ECLSession::exportKeymap
			{
				// function
				csaArguments.Add( "keyboard3279.kbd" );
			}
			break;

			case 144:	// ECLSession::findField
			{
				// row
				csaArguments.Add( "21" );

				// column
				csaArguments.Add( "8" );

				// direction
				csaArguments.Add( "SEARCH_FORWARD" );

				// attribute
				csaArguments.Add( "ALPHANUM_FIELD" );
			}
			break;

			case 145:	// ECLSession::findText
			{
				// text
				csaArguments.Add( "Username" );

				// row
				csaArguments.Add( "17" );

				// column
				csaArguments.Add( "8" );

				// direction
				csaArguments.Add( "TRUE" );
			}
			break;

			case 148:	// ECLSession::ftpCd
			case 210:	// ECLSession::setPrintToFileFolder
			{
				// directory
				csaArguments.Add( "todateSales" );
			}
			break;

			case 151:	// ECLSession::ftpLCd
			case 211:	// ECLSession::setPrintToFileName
			{
				// local dir
				csaArguments.Add( "d:\\salesdata" );
			}
			break;

			case 152:	// ECLSession::ftpLogin
			{
				// host
				csaArguments.Add( "HAL" );

				// user
				csaArguments.Add( "Dave" );

				// password
				csaArguments.Add( "dave2001" );

				// account
				csaArguments.Add( "NASA" );

				// use pasv
				csaArguments.Add( "TRUE" );
			}
			break;

			case 154:	// ECLSession::ftpReceiveFile
			{
				// Host filename
				csaArguments.Add( "market txt" );

				// PC filename
				csaArguments.Add( "c:\\sysback\\marketfile.txt" );

				// ASCII
				csaArguments.Add( "TRUE" );

			}
			break;

			case 155:	// ECLSession::ftpReceiveFiles
			case 157:	// ECLSession::ftpSendFiles
			{
				// Host filename
				csaArguments.Add( "market *" );

				// PC filename
				csaArguments.Add( "ID_HOST_TYPE_CMS" );

			}
			break;

			case 156:	// ECLSession::ftpSendFile
			{
				// Host filename
				csaArguments.Add( "market txt" );

				// PC filename
				csaArguments.Add( "c:\\sysback\\marketfile.txt" );

				// make subdirectories
				csaArguments.Add( "TRUE" );

				// ASCII
				csaArguments.Add( "TRUE" );
			}
			break;

			case 158:	// ECLSession::getBoolean
			case 170:	// ECLSession::getInteger
			case 173:	// ECLSession::getParameter
			case 182:	// ECLSession::getString
			{
				// property name
				csaArguments.Add( "rScreenSize" );
			}
			break;

			case 162:	// ECLSession::getDisplayText
			case 165:	// ECLSession::getFieldText
			{
				// row
				csaArguments.Add( "21" );

				// column
				csaArguments.Add( "8" );

				// chars
				csaArguments.Add( "8" );
			}
			break;

			case 163:	// ECLSession::getDisplayText
			{
				// row
				csaArguments.Add( "21" );

				// column
				csaArguments.Add( "8" );

				// end row
				csaArguments.Add( "21" );

				// end column
				csaArguments.Add( "15" );
			}
			break;

			case 168:	// ECLSession::getHostStatusText
			{
				// column
				csaArguments.Add( "10" );

				// chars
				csaArguments.Add( "2" );
			}
			break;

			case 175:	// ECLSession::getPrinterMargin
			{
				// margin
				csaArguments.Add( "MARGIN_TOP" );
			}
			break;

			case 176:	// ECLSession::getPrinterPageSize
			case 177:	// ECLSession::getPrintScaling
			{
				// dimension
				csaArguments.Add( "PRINTER_PAGE_HEIGHT" );
			}
			break;

			case 185:	// ECLSession::indReceiveFile
			case 186:	// ECLSession::indSendFile
			{
				// PC filename
				csaArguments.Add( "c:\\sysback\\marketfile.txt" );

				// Host filename
				csaArguments.Add( "market txt" );

				// is ASCII
				csaArguments.Add( "TRUE" );

				// show status
				csaArguments.Add( "TRUE" );

			}
			break;

			case 190:	// ECLSession::loadComponent
			{
				// component
				csaArguments.Add( "Keymapper" );
			}
			break;

			case 191:	// ECLSession::makeTextSelection
			{
				// top
				csaArguments.Add( "21" );

				// left
				csaArguments.Add( "8" );

				// bottom
				csaArguments.Add( "24" );

				// right
				csaArguments.Add( "15" );

				// rect
				csaArguments.Add( "TRUE" );
			}
			break;

			case 192:	// ECLSession::passwordPrompt
			{
				// message
				csaArguments.Add( "Pleaes enter your password" );

				// rect
				csaArguments.Add( "TRUE" );
			}
			break;

			case 193:	// ECLSession::playbackMacro
			{
				// message
				csaArguments.Add( "checkConnect" );
			}
			break;

			case 194:	// ECLSession::printBytes
			case 216:	// ECLSession::transmitString
			{
				// byte string
				csaArguments.Add( "password22" );
			}
			break;

			case 195:	// ECLSession::printCharacter
			{
				// byte
				csaArguments.Add( "*" );
			}
			break;

			case 196:	// ECLSession::printString
			{
				// string
				csaArguments.Add( "Outside sales : July 2005" );
			}
			break;

			case 198:	// ECLSession::removeMessageServiceListener
			{
				// string
				csaArguments.Add( "rwListObj" );
			}
			break;

			case 203:	// ECLSession::setBoolean
			{
				// property name
				csaArguments.Add( "rScreenSize" );

				// value
				csaArguments.Add( "TRUE" );
			}
			break;

			case 205:	// ECLSession::setHostURL
			{
				// URL
				csaArguments.Add( "12.129.19.128" );
			}
			break;

			case 206:	// ECLSession::setInteger
			{
				// property name
				csaArguments.Add( "rScreenSize" );

				// value
				csaArguments.Add( "1920" );
			}
			break;

			case 207:	// ECLSession::setPrinterMargin
			{
				// dimension
				csaArguments.Add( "MARGIN_TOP" );

				// value
				csaArguments.Add( "1.37" );
			}
			break;

			case 208:	// ECLSession::setPrinterPageSize
			{
				// dimension
				csaArguments.Add( "PRINTER_PAGE_HEIGHT" );

				// value
				csaArguments.Add( "1.37" );
			}
			break;

			case 209:	// ECLSession::setPrintScaling
			{
				// dimension
				csaArguments.Add( "PRINTER_PAGE_HEIGHT" );

				// scaling
				csaArguments.Add( "110" );
			}
			break;

			case 212:	// ECLSession::setString
			{
				// property name
				csaArguments.Add( "rwFTScheme" );

				// value
				csaArguments.Add( "SBC" );
			}
			break;

			case 213:	// ECLSession::showDialog
			{
				// dialog name
				csaArguments.Add( "PrinterConfig" );
			}
			break;

			case 217:	// ECLSession::transmitTerminalKey
			{
				// byte
				csaArguments.Add( "[enter]" );
			}
			break;

			case 218:	// ECLSession::waitForCursorEntered
			case 219:	// ECLSession::waitForCursorLeft
			{
				// row
				csaArguments.Add( "21" );

				// column
				csaArguments.Add( "8" );

				// timeout
				csaArguments.Add( "3000" );
			}
			break;

			case 220:	// ECLSession::waitForDisplayString		// 220
			{
				// string
				csaArguments.Add( "Ready" );

				// row
				csaArguments.Add( "21" );

				// column
				csaArguments.Add( "8" );

				// timeout
				csaArguments.Add( "3000" );
			}
			break;

			case 221:	// ECLSession::waitForDisplayString
			case 223:	// ECLSession::waitForHostPrompt
			case 226:	// ECLSession::waitForString
			{
				// string
				csaArguments.Add( "Ready" );

				// timeout
				csaArguments.Add( "3000" );
			}
			break;

			case 222:	// ECLSession::waitForDisplayStrings
			{
				// string
				csaArguments.Add( "csaWaitStrings" );

				// timeout
				csaArguments.Add( "3000" );
			}
			break;

			case 224:	// ECLSession::waitForKeyboardLock
			case 225:	// ECLSession::waitForKeyboardUnlock
			{
				// duration
				csaArguments.Add( "1000" );

				// timeout
				csaArguments.Add( "3000" );
			}
			break;

			case 227:	// ECLSession::waitWhileDisplayString	
			{
				// string
				csaArguments.Add( "Ready" );

				// case
				csaArguments.Add( "TRUE" );
			}
			break;

			case 228:	// ECLSession::waitWhileDisplayString 2
			{
				// string
				csaArguments.Add( "Ready" );

				// row
				csaArguments.Add( "21" );

				// column
				csaArguments.Add( "8" );

				// timeout
				csaArguments.Add( "3000" );

				// case
				csaArguments.Add( "TRUE" );
			}
			break;

			case 229:	// ECLSession::waitWhileDisplayString 3
			{
				// string
				csaArguments.Add( "Ready" );

				// timeout
				csaArguments.Add( "3000" );
			}
			break;

			case 234:	// ECLXfer::ReceiveFile
			{
				// PC filename
				csaArguments.Add( "c:\\sysback\\marketfile.txt" );

				// Host filename
				csaArguments.Add( "market txt" );

				// options
				csaArguments.Add( "ASCII CRLF" );
			}
			break;

			case 235:	// ECLXfer::RegisterXferEvent
			case 240:	// ECLXfer::UnregisterXferEvent
			{
				// event listener object
				csaArguments.Add( "ftNotifyObj" );
			}
			break;

			case 236:	// ECLXfer::SendFile
			{
				// Host filename
				csaArguments.Add( "market txt" );

				// PC filename
				csaArguments.Add( "c:\\sysback\\marketfile.txt" );

				// options
				csaArguments.Add( "ASCII CRLF" );
			}
			break;

			case 239:	// ECLXfer::setTransferHostType
			{
				// ft host type
				csaArguments.Add( "ID_HOST_TYPE_CICS" );
			}
			break;

		}
	}
}




/****************************************************************************DC
	Function	:	CAPIGenDlg::ShowRWebControls()

	Purpose		:	Show the controls for the Extra! OLE Automation 
					function parameters.

*****************************************************************************/
void CAPIGenDlg::ShowRWebControls( int nFunction )
{
	HideParameterControls();
	csaLabels.RemoveAll();
	BOOL bYouShouldGo=TRUE;

	switch ( nFunction )
	{
		case 0:	// ECLField::clearField
		case 2: // ECLField::GetAttribute
		case 3: // 	ECLField::GetEnd
		case 4: // 	ECLField::GetEndCol
		case 5: // 	ECLField::GetEndRow
		case 6: // 	ECLField::GetLength
		case 9:		// ECLField::GetStart
		case 10:	// ECLField::GetStartCol
		case 11:	// ECLField::GetStartRow
		case 12:	// ECLField::GetString
		case 14:	// ECLField::IsDisplay
		case 15:	// ECLField::IsHighIntensity
		case 16:	// ECLField::IsModified
		case 17:	// ECLField::IsNumeric
		case 18:	// ECLField::IsPenDetectable
		case 19:	// ECLField::IsProtected
		case 20:	// ECLField::IsTransmitOnly
		case 28:	// ECLFieldList::GetFieldCount
		case 29:	// ECLFieldList::GetFirstField
		case 33:	// ECLFieldList::Refresh
		case 35:	// ECLOIA::GetHPStatusFlags
		case 36:	// ECLOIA::GetParent
		case 37:	// ECLOIA::GetStatusFlags
		case 38:	// ECLOIA::InputInhibited
		case 39:	// ECLOIA::IsAlphanumeric
		case 40:	// ECLOIA::IsCommErrorReminder
		case 41:	// ECLOIA::IsDBCS
		case 42:	// ECLOIA::IsHPBlockMode
		case 43:	// ECLOIA::IsHPFormatMode
		case 44:	// ECLOIA::IsInsertMode
		case 45:	// ECLOIA::IsMessageWaiting
		case 46:	// ECLOIA::IsNumeric
		case 48:	// ECLOIA::setKeyboardUnlockDuration
		case 50:	// ECLOIA::WaitForInput
		case 51:	// ECLOIA::WaitForInput 2
		case 58:	// ECLPS::GetCursorCol
		case 59:	// ECLPS::GetCursorPos
		case 60:	// ECLPS::GetCursorRow
		case 61:	// ECLPS::GetCursorVisible
		case 62:	// ECLPS::GetFieldList
		case 64:	// ECLPS::GetParent
		case 77:	// ECLPS::GetSendKeyMnemonics
		case 78:	// ECLPS::getSendKeysKeyboardUnlockTimeout
		case 79:	// ECLPS::GetSize
		case 80:	// ECLPS::GetSizeCols
		case 81:	// ECLPS::GetSizeRows
		case 82:	// ECLPS::GetString
		case 88:	// ECLPS::RegisterPSEvent
		case 110:	// ECLPS::UnregisterPSEvent
		case 116:	// ECLPS::WaitForScreen
		case 123:	// ECLPS::WaitWhileScreen
		case 128:	// ECLSession::addMessageServiceListener
		case 129:	// ECLSession::apiExit
		case 132:	// ECLSession::cancelFileXfer
		case 133:	// ECLSession::cancelPrintJob
		case 134:	// ECLSession::closePrinter
		case 135:	// ECLSession::connect
		case 136:	// ECLSession::disconnect
		case 138:	// ECLSession::dispose
		case 141:	// ECLSession::endPrintJob
		case 142:	// ECLSession::exit
		case 146:	// ECLSession::flushPrintJob
		case 147:	// ECLSession::ftpAbort
		case 149:	// ECLSession::ftpDisconnect
		case 150:	// ECLSession::ftpGetLastServerResponse
		case 153:	// ECLSession::ftpPwd
		case 159:	// ECLSession::getCursorColumn
		case 160:	// ECLSession::getCursorPosition
		case 161:	// ECLSession::getCursorRow
		case 164:	// ECLSession::getEmulatorApplet
		case 166:	// ECLSession::getFrameBounds
		case 167:	// ECLSession::getHostName
		case 169:	// ECLSession::getHostURL
		case 171:	// ECLSession::getJSAPI
		case 172:	// ECLSession::GetOIA
		case 174:	// ECLSession::getPort
		case 178:	// ECLSession::getPrintToFileFolder
		case 179:	// ECLSession::getPrintToFileName
		case 180:	// ECLSession::GetPS
		case 181:	// ECLSession::getSelectionBounds
		case 183:	// ECLSession::GetXfer
		case 187:	// ECLSession::isConnected
		case 188:	// ECLSession::isIBM
		case 189:	// ECLSession::isStream
		case 197:	// ECLSession::printTestPage
		case 199:	// ECLSession::requestDisplayFocus
		case 200:	// ECLSession::resetUserPreferences
		case 201:	// ECLSession::saveUserPreferences
		case 202:	// ECLSession::screenPrint
		case 215:	// ECLSession::startPrintJob
		case 230:	// ECLXfer::Cancel
		case 231:	// ECLXfer::GetParent
		case 232:	// ECLXfer::GetStartTimeout
		case 233:	// ECLXfer::GetTimeout
		{
		}
		break;

		case 1: // ECLField::equals
		{
			csaLabels.Add("ECL field name");
		}
		break;

		case 7:		// ECLField::GetScreen
		case 67:	// ECLPS::GetScreen 1
		{
			csaLabels.Add("Buffer length");
			csaLabels.Add("Screen plane");
			bYouShouldGo=FALSE;
		}
		break;
		
		case 8:		// ECLField::GetScreen 2
		case 70:	// ECLPS::GetScreen 4
		{
			csaLabels.Add("Screen plane");
			bYouShouldGo=FALSE;
		}
		break;

		case 13:	// ECLField::GetString Ex2
		{
			csaLabels.Add("Buffer length");
		}
		break;

		case 21:	// ECLField::SetString
		case 22:	// ECLField::SetText
		{
			csaLabels.Add("String");
		}
		break;

		case 23:	// ECLFieldList::FindField
		{
			csaLabels.Add("Screen position");
		}
		break;

		case 24:	// ECLFieldList::FindField 2
		{
			csaLabels.Add("Row");
			csaLabels.Add("Column");
		}
		break;

		case 25:	// ECLFieldList::FindField 3
		{
			csaLabels.Add("Search string");
			csaLabels.Add("Direction");
			bYouShouldGo=FALSE;
		}
		break;

		case 26:	// ECLFieldList::FindField 4
		{
			csaLabels.Add("Search string");
			csaLabels.Add("Screen position");
			csaLabels.Add("Direction");
			bYouShouldGo=FALSE;
		}
		break;

		case 27:	// ECLFieldList::FindField 5
		{
			csaLabels.Add("Search string");
			csaLabels.Add("Row");
			csaLabels.Add("Column");
			csaLabels.Add("Direction");
			bYouShouldGo=FALSE;
		}
		break;

		case 30:	// ECLFieldList::GetFirstField 2	//30
		{
			csaLabels.Add("Field attribute");
			bYouShouldGo=FALSE;
		}
		break;

		case 31:	// ECLFieldList::GetNextField
		{
			csaLabels.Add("Field name");
		}
		break;

		case 32:	// ECLFieldList::GetNextField 2
		{
			csaLabels.Add("Field name");
			csaLabels.Add("Field attribute");
			bYouShouldGo=FALSE;
		}
		break;

		case 34:	// ECLFieldList::Refresh 2
		case 63:	// ECLPS::GetFieldList 2
		{
			csaLabels.Add("Plane");
			bYouShouldGo=FALSE;
		}
		break;

		case 47:	// ECLOIA::RegisterOIAEvent
		case 49:	// ECLOIA::UnregisterOIAEvent
		{
			csaLabels.Add("Event handler object");
		}
		break;

		case 52:	// ECLPS::ConvertPosToCol
		case 54:	// ECLPS::ConvertPosToRow
		{
			csaLabels.Add("Screen position");
		}
		break;

		case 53:	// ECLPS::ConvertPosToColX
		case 55:	// ECLPS::ConvertPosToRowX
		{
			csaLabels.Add("Screen position");
			csaLabels.Add("Number rows");
			csaLabels.Add("Number columns");
		}
		break;

		case 56:	// ECLPS::ConvertRowColToPos
		{
			csaLabels.Add("Screen row");
			csaLabels.Add("Screen column");
		}
		break;

		case 57:	// ECLPS::ConvertRowColToPosX
		{
			csaLabels.Add("Screen row");
			csaLabels.Add("Screen column");
			csaLabels.Add("Number columns");
		}
		break;

		case 65:	// ECLPS::GetPosForRowFromEnd
		{
			csaLabels.Add("Rows back");
		}
		break;

		case 66:	// ECLPS::getRow
		{
			csaLabels.Add("Screen position");
			csaLabels.Add("Number columns");
		}
		break;


		case 68:	// ECLPS::GetScreen 2
		{
			csaLabels.Add("Buffer length");
			csaLabels.Add("Screen position");
			csaLabels.Add("Number of chars");
			csaLabels.Add("Plane");
			bYouShouldGo=FALSE;
		}
		break;

		case 69:	// ECLPS::GetScreen 3
		{
			csaLabels.Add("Buffer length");
			csaLabels.Add("Row");
			csaLabels.Add("Column");
			csaLabels.Add("Number of chars");
			csaLabels.Add("Plane");
			bYouShouldGo=FALSE;
		}
		break;

		case 71:	// ECLPS::GetScreen 5
		{
			csaLabels.Add("Screen position");
			csaLabels.Add("Length");
			csaLabels.Add("Plane");
			bYouShouldGo=FALSE;
		}
		break;

		case 72:	// ECLPS::GetScreen 6
		{
			csaLabels.Add("Row");
			csaLabels.Add("Column");
			csaLabels.Add("Length");
			csaLabels.Add("Plane");
			bYouShouldGo=FALSE;
		}
		break;

		case 73:	// ECLPS::GetScreenRect
		{
			csaLabels.Add("Length");
			csaLabels.Add("Start position");
			csaLabels.Add("End position");
			csaLabels.Add("Plane");
			bYouShouldGo=FALSE;
		}
		break;

		case 74:	// ECLPS::GetScreenRect 2
		{
			csaLabels.Add("Length");
			csaLabels.Add("Start row");
			csaLabels.Add("Start column");
			csaLabels.Add("End row");
			csaLabels.Add("End column");
			csaLabels.Add("Plane");
			bYouShouldGo=FALSE;
		}
		break;

		case 75:	// ECLPS::GetScreenRect 3
		{
			csaLabels.Add("Start position");
			csaLabels.Add("End position");
			csaLabels.Add("Plane");
			bYouShouldGo=FALSE;
		}
		break;

		case 76:	// ECLPS::GetScreenRect 4
		{
			csaLabels.Add("Start row");
			csaLabels.Add("Start column");
			csaLabels.Add("End row");
			csaLabels.Add("End column");
			csaLabels.Add("Plane");
			bYouShouldGo=FALSE;
		}
		break;

		case 83:	// ECLPS::GetString 2
		{
			csaLabels.Add("Buffer length");
		}
		break;

		case 84:	// ECLPS::GetString 3
		{
			csaLabels.Add("Buffer length");
			csaLabels.Add("Screen position");
			csaLabels.Add("Copy length");
		}
		break;

		case 85:	// ECLPS::GetString 4
		{
			csaLabels.Add("Buffer length");
			csaLabels.Add("Screen row");
			csaLabels.Add("Screen column");
			csaLabels.Add("Copy length");
		}
		break;

		case 86:	// ECLPS::GetString 5
		{
			csaLabels.Add("Screen position");
			csaLabels.Add("Copy length");
		}
		break;

		case 87:	// ECLPS::GetString 6
		{
			csaLabels.Add("Screen row");
			csaLabels.Add("Screen column");
			csaLabels.Add("Copy length");
		}
		break;

		case 89:	// ECLPS::RegisterPSEvent 2
		case 111:	// ECLPS::UnregisterPSEvent 2
		{
			csaLabels.Add("Event type");
			bYouShouldGo=FALSE;
		}
		break;

		case 90:	// ECLPS::SearchString				// 90
		case 93:	// ECLPS::SearchText
		{
			csaLabels.Add("Search string");
			csaLabels.Add("Direction");
			bYouShouldGo=FALSE;
		}
		break;

		case 91:	// ECLPS::SearchString 2
		case 94:	// ECLPS::SearchText 2
		{
			csaLabels.Add("Search string");
			csaLabels.Add("Position");
			csaLabels.Add("Direction");
			bYouShouldGo=FALSE;
		}
		break;

		case 92:	// ECLPS::SearchString 3
		case 95:	// ECLPS::SearchText 3
		{
			csaLabels.Add("Search string");
			csaLabels.Add("Row");
			csaLabels.Add("Column");
			csaLabels.Add("Direction");
			bYouShouldGo=FALSE;
		}
		break;

		case 96:	// ECLPS::SendKeys
		case 103:	// ECLPS::SetString
		case 106:	// ECLPS::SetText
		case 216:	// ECLSession::transmitString
		{
			csaLabels.Add("String");
		}
		break;

		case 97:	// ECLPS::SendKeys 2
		case 104:	// ECLPS::SetString 2
		case 107:	// ECLPS::SetText 2
		{
			csaLabels.Add("Search string");
			csaLabels.Add("Position");
		}
		break;

		case 98:	// ECLPS::SendKeys 3
		case 105:	// ECLPS::SetString 3
		case 108:	// ECLPS::SetText 3
		{
			csaLabels.Add("Search string");
			csaLabels.Add("Row");
			csaLabels.Add("Column");
		}
		break;

		case 99:	// ECLPS::SetCursorPos
		{
			csaLabels.Add("Position");
		}
		break;

		case 100:	// ECLPS::SetCursorPos 2				// 100
		case 112:	// ECLPS::WaitForCursor
		{
			csaLabels.Add("Row");
			csaLabels.Add("Column");
		}
		break;

		case 101:	// ECLPS::SetCursorVisible
		{
			csaLabels.Add("Make cursor visible");
			bYouShouldGo=FALSE;
		}
		break;

		case 102:	// ECLPS::setSendKeysKeyboardUnlockTimeout
		{
			csaLabels.Add("Timeout (ms)");
		}
		break;

		case 109:	// ECLPS::spacePadString
		{
			csaLabels.Add("In string");
			csaLabels.Add("Pad columns");
		}
		break;

		case 113:	// ECLPS::WaitForCursor 2
		{
			csaLabels.Add("Row");
			csaLabels.Add("Column");
			csaLabels.Add("Timeout (ms)");
			csaLabels.Add("Wait for input");
			bYouShouldGo=FALSE;
		}
		break;

		case 114:	// ECLPS::WaitForHostPrompt
		{
			csaLabels.Add("String");
		}
		break;

		case 115:	// ECLPS::WaitForHostPrompt 2
		{
			csaLabels.Add("String");
			csaLabels.Add("Timeout (ms)");
		}
		break;

		case 117:	// ECLPS::WaitForScreen 2
		case 124:	// ECLPS::WaitWhileScreen 2
		{
			csaLabels.Add("Timeout (ms)");
		}
		break;

		case 118:	// ECLPS::WaitForString
		case 125:	// ECLPS::WaitWhileString
		{
			csaLabels.Add("String");
		}
		break;

		case 119:	// ECLPS::WaitForString 2
		case 126:	// ECLPS::WaitWhileString 2
		{
			csaLabels.Add("String");
			csaLabels.Add("Row");
			csaLabels.Add("Column");
		}
		break;

		case 120:	// ECLPS::WaitForString 3					// 120	NOTE!!! TODO XXX ANOTHER CHECKBOX NEEDED
		{
			csaLabels.Add("Search string");
			csaLabels.Add("Row");
			csaLabels.Add("Column");
			csaLabels.Add("Timeout (ms)");
			csaLabels.Add("Wait for input");
			csaLabels.Add("Ignore case");
			bYouShouldGo=FALSE;
		}
		break;

		case 121:	// ECLPS::WaitWhileCursor
		case 204:	// ECLSession::setCursorPosition
		{
			csaLabels.Add("Row");
			csaLabels.Add("Column");
		}
		break;

		case 122:	// ECLPS::WaitWhileCursor 2
		{
			csaLabels.Add("Row");
			csaLabels.Add("Column");
			csaLabels.Add("Timeout (ms)");
			csaLabels.Add("Wait for input");
			bYouShouldGo=FALSE;
		}
		break;

		case 127:	// ECLPS::WaitWhileString 3
		{
			csaLabels.Add("String");
			csaLabels.Add("Row");
			csaLabels.Add("Column");
			csaLabels.Add("Timeout (ms)");
			csaLabels.Add("Wait for input");
			bYouShouldGo=FALSE;
		}
		break;

		case 130:	// ECLSession::apvuReceiveFile		// 130
		case 131:	// ECLSession::apvuSendFile
		{
			csaLabels.Add("PC filename");
			csaLabels.Add("Host filename");
			csaLabels.Add("Transfer type");
			csaLabels.Add("Show status dialog");
			bYouShouldGo=FALSE;
		}
		break;

		case 137:	// ECLSession::display
		{
			csaLabels.Add("String");
			csaLabels.Add("Interpret");
			bYouShouldGo=FALSE;
		}
		break;

		case 139:	// ECLSession::doJavaScriptCall
		{
			csaLabels.Add("JavaScript function");
			csaLabels.Add("Argument array");
		}
		break;

		case 140:	// ECLSession::doJavaScriptEval		// 140
		{
			csaLabels.Add("Evaluation string");
		}
		break;

		case 143:	// ECLSession::exportKeymap
		{
			csaLabels.Add("I/O stream name");
		}
		break;

		case 144:	// ECLSession::findField
		{
			csaLabels.Add("Row");
			csaLabels.Add("Column");
			csaLabels.Add("Direction");
			csaLabels.Add("Attribute");
			bYouShouldGo=FALSE;
		}
		break;

		case 145:	// ECLSession::findText
		{
			csaLabels.Add("Text");
			csaLabels.Add("Row");
			csaLabels.Add("Column");
			csaLabels.Add("Ignore case");
			bYouShouldGo=FALSE;
		}
		break;

		case 148:	// ECLSession::ftpCd
		{
			csaLabels.Add("Server directory");
		}
		break;

		case 151:	// ECLSession::ftpLCd
		{
			csaLabels.Add("Local directory");
		}
		break;

		case 152:	// ECLSession::ftpLogin
		{
			csaLabels.Add("Host name");
			csaLabels.Add("User name");
			csaLabels.Add("Password");
			csaLabels.Add("Account");
			csaLabels.Add("Use PASV");
			bYouShouldGo=FALSE;
		}
		break;

		case 154:	// ECLSession::ftpReceiveFile
		{
			csaLabels.Add("Remote file");
			csaLabels.Add("Local file");
			csaLabels.Add("ASCII");
			bYouShouldGo=FALSE;
		}
		break;

		case 155:	// ECLSession::ftpReceiveFiles
		case 157:	// ECLSession::ftpSendFiles
		{
			csaLabels.Add("Transfer files");
			csaLabels.Add("Transfer type");
			bYouShouldGo=FALSE;
		}
		break;

		case 156:	// ECLSession::ftpSendFile
		{
			csaLabels.Add("Remote file");
			csaLabels.Add("Local file");
			csaLabels.Add("Make host directory");
			csaLabels.Add("ASCII");
			bYouShouldGo=FALSE;
		}
		break;

		case 158:	// ECLSession::getBoolean
		{
			csaLabels.Add("Reflection property");
		}
		break;

		case 162:	// ECLSession::getDisplayText
		case 165:	// ECLSession::getFieldText
		{
			csaLabels.Add("Row");
			csaLabels.Add("Column");
			csaLabels.Add("Number of chars");
		}
		break;

		case 163:	// ECLSession::getDisplayText
		{
			csaLabels.Add("Start row");
			csaLabels.Add("Start column");
			csaLabels.Add("End row");
			csaLabels.Add("End column");
			csaLabels.Add("Rectangular (t/f)");
			csaLabels.Add("Line ending");
		}
		break;

		case 168:	// ECLSession::getHostStatusText
		{
			csaLabels.Add("Status line column");
			csaLabels.Add("Number of chars");
		}
		break;

		case 170:	// ECLSession::getInteger				// 170
		case 182:	// ECLSession::getString
		{
			csaLabels.Add("Property name");
		}
		break;

		case 173:	// ECLSession::getParameter
		{
			csaLabels.Add("Parameter name");
		}
		break;

		case 175:	// ECLSession::getPrinterMargin
		{
			csaLabels.Add("Margin type");
			bYouShouldGo=FALSE;
		}
		break;

		case 176:	// ECLSession::getPrinterPageSize
		case 177:	// ECLSession::getPrintScaling
		{
			csaLabels.Add("Width or height?");
		}
		break;

		case 184:	// ECLSession::importKeymap
		{
			csaLabels.Add("Input stream name");
		}
		break;

		case 185:	// ECLSession::indReceiveFile
		case 186:	// ECLSession::indSendFile
		{
			csaLabels.Add("Host file");
			csaLabels.Add("PC file");
			csaLabels.Add("ASCII");
			csaLabels.Add("Show status dialog");
			bYouShouldGo=FALSE;
		}
		break;

		case 190:	// ECLSession::loadComponent			// 190
		{
			csaLabels.Add("Component name");
		}
		break;

		case 191:	// ECLSession::makeTextSelection
		{
			csaLabels.Add("Start row");
			csaLabels.Add("Start column");
			csaLabels.Add("End row");
			csaLabels.Add("End column");
			csaLabels.Add("Rectangular selection");
			bYouShouldGo=FALSE;
		}
		break;

		case 192:	// ECLSession::passwordPrompt
		{
			csaLabels.Add("Password prompt");
			csaLabels.Add("Return as string");
			bYouShouldGo=FALSE;
		}
		break;

		case 193:	// ECLSession::playbackMacro
		{
			csaLabels.Add("Macro name");
		}
		break;

		case 194:	// ECLSession::printBytes
		{
			csaLabels.Add("Byte array name");
		}
		break;

		case 195:	// ECLSession::printCharacter
		{
			csaLabels.Add("Character");
		}
		break;

		case 196:	// ECLSession::printString
		{
			csaLabels.Add("String");
		}
		break;

		case 198:	// ECLSession::removeMessageServiceListener
		{
			csaLabels.Add("Message listener");
		}
		break;

		case 203:	// ECLSession::setBoolean
		{
			csaLabels.Add("Property name");
			csaLabels.Add("Set property TRUE");
			bYouShouldGo=FALSE;
		}
		break;

		case 205:	// ECLSession::setHostURL
		{
			csaLabels.Add("URL");
		}
		break;

		case 206:	// ECLSession::setInteger
		{
			csaLabels.Add("Property name");
			csaLabels.Add("Integer value");
		}
		break;

		case 207:	// ECLSession::setPrinterMargin
		{
			csaLabels.Add("Margin name");
			csaLabels.Add("New size");
			bYouShouldGo=FALSE;
		}
		break;

		case 208:	// ECLSession::setPrinterPageSize
		{
			csaLabels.Add("Screen dimension");
			csaLabels.Add("New size");
			bYouShouldGo=FALSE;
		}
		break;

		case 209:	// ECLSession::setPrintScaling
		{
			csaLabels.Add("Direction");
			csaLabels.Add("Scale % (1-1000)");
			bYouShouldGo=FALSE;
		}
		break;

		case 210:	// ECLSession::setPrintToFileFolder		// 210
		{
			csaLabels.Add("Folder name");
		}
		break;

		case 211:	// ECLSession::setPrintToFileName
		{
			csaLabels.Add("File name");
		}
		break;

		case 212:	// ECLSession::setString
		{
			csaLabels.Add("Property name");
			csaLabels.Add("String value");
		}
		break;

		case 213:	// ECLSession::showDialog
		{
			csaLabels.Add("Dialog name");
		}
		break;

		case 214:	// ECLSession::ShowPSDebugger
		{
			csaLabels.Add("Show PS debugger");
			bYouShouldGo=FALSE;
		}
		break;

		case 217:	// ECLSession::transmitTerminalKey
		{
			csaLabels.Add("Key");
		}
		break;

		case 218:	// ECLSession::waitForCursorEntered
		case 219:	// ECLSession::waitForCursorLeft
		{
			csaLabels.Add("Row");
			csaLabels.Add("Column");
			csaLabels.Add("Timeout (ms)");
		}
		break;

		case 220:	// ECLSession::waitForDisplayString		// 220
		{
			csaLabels.Add("String");
			csaLabels.Add("Row");
			csaLabels.Add("Column");
			csaLabels.Add("Timeout (ms)");
		}
		break;

		case 221:	// ECLSession::waitForDisplayString
		{
			csaLabels.Add("String");
			csaLabels.Add("Timeout (ms)");
		}
		break;

		case 222:	// ECLSession::waitForDisplayStrings
		{
			csaLabels.Add("String vector");
			csaLabels.Add("Timeout (ms)");
		}
		break;

		case 223:	// ECLSession::waitForHostPrompt
		{
			csaLabels.Add("Host prompt");
			csaLabels.Add("Timeout (ms)");
		}
		break;

		case 224:	// ECLSession::waitForKeyboardLock
		case 225:	// ECLSession::waitForKeyboardUnlock
		{
			csaLabels.Add("Duration");
			csaLabels.Add("Timeout (ms)");
		}
		break;

		case 226:	// ECLSession::waitForString
		{
			csaLabels.Add("Screen string");
			csaLabels.Add("Timeout (ms)");
		}
		break;

		case 227:	// ECLSession::waitWhileDisplayString	
		{
			csaLabels.Add("Screen string");
			csaLabels.Add("Sense case?");
			bYouShouldGo=FALSE;
		}
		break;

		case 228:	// ECLSession::waitWhileDisplayString 2
		{
			csaLabels.Add("Screen string");
			csaLabels.Add("Timeout (ms)");
		}
		break;

		case 229:	// ECLSession::waitWhileDisplayString 3
		{
			csaLabels.Add("Screen string");
			csaLabels.Add("Row");
			csaLabels.Add("Column");
			csaLabels.Add("Timeout (ms)");
			csaLabels.Add("Sense case?");
			bYouShouldGo=FALSE;
		}
		break;

		case 234:	// ECLXfer::ReceiveFile
		{
			csaLabels.Add("Host filename");
			csaLabels.Add("PC filename");
			csaLabels.Add("Transfer options");
			bYouShouldGo=FALSE;
		}
		break;

		case 235:	// ECLXfer::RegisterXferEvent
		case 240:	// ECLXfer::UnregisterXferEvent			// 240
		{
			csaLabels.Add("Event handler");
		}
		break;

		case 236:	// ECLXfer::SendFile
		{
			csaLabels.Add("PC filename");
			csaLabels.Add("Host filename");
			csaLabels.Add("Transfer options");
			bYouShouldGo=FALSE;
		}
		break;

		case 237:	// ECLXfer::SetStartTimeout
		case 238:	// ECLXfer::SetTimeout
		{
			csaLabels.Add("Timeout (sec)");
		}
		break;

		case 239:	// ECLXfer::setTransferHostType
		{
			csaLabels.Add("Host type");
			bYouShouldGo=FALSE;
		}
		break;

	}

	if ( bYouShouldGo )
	{
		ShowEditControls( &csaLabels );
	}
	else
	{
		ShowMixedControls( RWEB_API, nFunction, &csaLabels );	
	}

}
