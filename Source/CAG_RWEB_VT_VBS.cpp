// Static Model
#include "stdafx.h"
#include "apigen.h"

#include "CAG_RWEB_VT_VBS.h"

CAG_RWEB_VT_VBS::CAG_RWEB_VT_VBS()
{
	resetVariableFlags();
}

CAG_RWEB_VT_VBS::~CAG_RWEB_VT_VBS()
{
	
}

void CAG_RWEB_VT_VBS::generateHeader(CStringArray* pcsaHeader,
									  CStringArray* pcsaBody)
{
	CString csViewOutStuff;

	pcsaHeader->Add( "<html>" );
	pcsaHeader->Add( "<head>" );
	pcsaHeader->Add("");
	pcsaHeader->Add("<script language=\"VBScript\">");
	pcsaHeader->Add("//  ****************************************************************************");
	pcsaHeader->Add("//                   Attachmate Reflection RWeb");
	pcsaHeader->Add("//                 APIGen VT Terminal VBScript Program");
	pcsaHeader->Add("// ");
	pcsaHeader->Add("//  This file is a program that features the use of the Reflection RWeb");
	pcsaHeader->Add("//  API written in VBScript.  This header is to include information");
	pcsaHeader->Add("//  on how to set up the environment to run this application, how to build");
	pcsaHeader->Add("//  it, and how to run it.");

	time_t ltime;
	time( &ltime );

	pcsaHeader->Add("//");

	csViewOutStuff.Format( "//   Generated:   %s", ctime( &ltime ) );
	pcsaHeader->Add(csViewOutStuff);

	pcsaHeader->Add( "//");
	pcsaHeader->Add("");
	pcsaHeader->Add("");

	pcsaHeader->Add( "Dim appletTarget = null;");
    pcsaHeader->Add( "Dim api = null;");
    pcsaHeader->Add( "Dim uname;");
    pcsaHeader->Add( "Dim pword;");
    pcsaHeader->Add( "Dim count = 0;");
    pcsaHeader->Add( "Dim errcount = 0;");
    pcsaHeader->Add( "Dim inited = 0;");

    pcsaHeader->Add( "");
    pcsaHeader->Add( "window.onerror = errHandler;");
    pcsaHeader->Add( "");


	pcsaHeader->Add("function handleLogonButton()");
	pcsaHeader->Add("{");
	pcsaHeader->Add("   // Validate the username and password.");
	pcsaHeader->Add("   if ( validateInputs() )");
	pcsaHeader->Add("   {");
	pcsaHeader->Add("      if ( !checkInit() )");
	pcsaHeader->Add("      {");
	pcsaHeader->Add("         return;");
	pcsaHeader->Add("      }");
	pcsaHeader->Add("      doConnect();");
	pcsaHeader->Add("   }");
	pcsaHeader->Add("}");

	pcsaHeader->Add("");
	pcsaHeader->Add("");


	pcsaHeader->Add("/*");
	pcsaHeader->Add("This function checks for a username and password, and if either is");
	pcsaHeader->Add("not present, displays an alert message.");
	pcsaHeader->Add("*/");

	pcsaHeader->Add("function validateInputs()");
	pcsaHeader->Add("{");
	pcsaHeader->Add("   uname = document.LogonForm.Username.value;");
	pcsaHeader->Add("   pword = document.LogonForm.Password.value;");
	pcsaHeader->Add("   if ( uname == \"\" )");
	pcsaHeader->Add("   {");
	pcsaHeader->Add("      alert( \"You must enter a Username to log on!\" );");
	pcsaHeader->Add("      document.LogonForm.Username.focus();");
	pcsaHeader->Add("      return false;");
	pcsaHeader->Add("   }");
	pcsaHeader->Add("");
	pcsaHeader->Add("   if ( pword == \"\" )");
	pcsaHeader->Add("   {");
	pcsaHeader->Add("      alert( \"You must enter a Password to log on!\" );");
	pcsaHeader->Add("      document.LogonForm.Password.focus();");
	pcsaHeader->Add("      return false;");
	pcsaHeader->Add("   }");
	pcsaHeader->Add("   return true;");
	pcsaHeader->Add("}");

	pcsaHeader->Add("");
	pcsaHeader->Add("");



	pcsaHeader->Add("/*");
	pcsaHeader->Add("This function gets a reference to the Reflection applet on the page,");
	pcsaHeader->Add("and gets the session's initialized status. If the getInitialized");
	pcsaHeader->Add("method fails because the session is not available, the error handler");
	pcsaHeader->Add("is invoked.");
	pcsaHeader->Add("*/");

	pcsaHeader->Add("function checkInit()");
	pcsaHeader->Add("{");
	pcsaHeader->Add("   appletTarget = document.VT;");
	pcsaHeader->Add("   api = appletTarget.getAPI(\"JSAPI\",\"VT\");");
	pcsaHeader->Add("   inited = api.getInitialized();");
	pcsaHeader->Add("   if ( inited > 0 )");
	pcsaHeader->Add("   {");
	pcsaHeader->Add("      return true;");
	pcsaHeader->Add("   }");
	pcsaHeader->Add("   else if ( inited < 0 )");
	pcsaHeader->Add("   {");
	pcsaHeader->Add("      alert( \"Reflection initialization failed.\" );");
	pcsaHeader->Add("      return false;");
	pcsaHeader->Add("   }");
	pcsaHeader->Add("   else if ( count < 10 )");
	pcsaHeader->Add("   {");
	pcsaHeader->Add("      count++;");
	pcsaHeader->Add("      setTimeout( \"checkInit()\", 2000 );");
	pcsaHeader->Add("   }");
	pcsaHeader->Add("   else");
	pcsaHeader->Add("   {");
	pcsaHeader->Add("      alert( \"Unable to initialize Reflection.\" );");
	pcsaHeader->Add("      return false;");
	pcsaHeader->Add("   }");
	pcsaHeader->Add("}");

	pcsaHeader->Add("");
	pcsaHeader->Add("");



	pcsaHeader->Add("/*");
	pcsaHeader->Add("This function starts the actual logon tasks. It determines if the session");
    pcsaHeader->Add("is connected, and if so, calls the function that finds the Username and ");
	pcsaHeader->Add("Password prompts on the display and transmits the user's data.");
    pcsaHeader->Add("*/");

	pcsaHeader->Add("sub doConnect()");
	pcsaHeader->Add("{");
	pcsaHeader->Add("   // If there's no connection, try to connect.");
	pcsaHeader->Add("   if ( !api.isConnected() )");
	pcsaHeader->Add("   {");
	pcsaHeader->Add("      self.status = \"Connecting...\";");
	pcsaHeader->Add("      api.connect();");
	pcsaHeader->Add("   }");
	pcsaHeader->Add("   else");
	pcsaHeader->Add("   {");
	pcsaHeader->Add("      alert( \"You're already connected!\" );");
	pcsaHeader->Add("      return;");
	pcsaHeader->Add("   }");
	pcsaHeader->Add("");
	pcsaHeader->Add("   // Wait 5 seconds for the Username prompt.");
	pcsaHeader->Add("   self.status = \"Waiting for Username prompt.\";");
	pcsaHeader->Add("   if ( !api.waitForString( \"Username:\", 5000 ) )");
	pcsaHeader->Add("   {");
	pcsaHeader->Add("      alert( \"Unable to find Username prompt. The script will stop, \" + ");
	pcsaHeader->Add("      \"but you may continue manually.\" );");
	pcsaHeader->Add("      return;");
	pcsaHeader->Add("   }");
	pcsaHeader->Add("");

	pcsaHeader->Add("   // Username prompt was found, so transmit the user's username,");
	pcsaHeader->Add("   // followed by a carriage return. The octal representation of the");
	pcsaHeader->Add("   // carriage return character--which is decimal 13--is used. You");
	pcsaHeader->Add("   // can also use the carriage return symbol \r or the hex value");
	pcsaHeader->Add("   // \x0D. You CANNOT use the decimal value 13, because this will be");
	pcsaHeader->Add("   // converted to a string and appended to the username.");

	pcsaHeader->Add("   api.transmitString( uname + \"\\015\" );");
	pcsaHeader->Add("");
	pcsaHeader->Add("   // Wait 5 seconds for the Password prompt.");
	pcsaHeader->Add("   self.status = \"Waiting for Password prompt.\";");
	pcsaHeader->Add("   if ( !api.waitForString( \"Password:\", 5000 ) )");
	pcsaHeader->Add("   {");
	pcsaHeader->Add("      alert( \"Unable to find Password prompt. The script will stop, \" + ");
	pcsaHeader->Add("      \"but you can try completing the logon manually.\" );");
	pcsaHeader->Add("      return;");
	pcsaHeader->Add("   }");
	pcsaHeader->Add("");

	pcsaHeader->Add("   // Password prompt was found, so transmit the user's password,");
	pcsaHeader->Add("   // followed by a carriage return. As above, the octal");
	pcsaHeader->Add("   // representation of the carriage return character is used.");
	pcsaHeader->Add("   api.transmitString( pword + \"\\015\" );");
	pcsaHeader->Add("");        
	pcsaHeader->Add("   // Done with logon, so display final status message, and set");
	pcsaHeader->Add("   // focus to the terminal display.");
	pcsaHeader->Add("   self.status = \"Ready to proceed.\";");
	pcsaHeader->Add("   api.requestDisplayFocus();");
	pcsaHeader->Add("}");

	pcsaHeader->Add("");

	pcsaHeader->Add("/*");
	pcsaHeader->Add("   This is the error handler function that will catch script errors.");
	pcsaHeader->Add("   The error we're most interested in may occur when trying to");
	pcsaHeader->Add("   get Reflection's initialized state in the checkInit() function.");
	pcsaHeader->Add("*/");
	pcsaHeader->Add("function errHandler( msg, url, line )");
	pcsaHeader->Add("{");
	pcsaHeader->Add("   if ( inited <= 0 ) ");
	pcsaHeader->Add("   {");
	pcsaHeader->Add("      if ( errcount < 10 ) ");
	pcsaHeader->Add("      {");
	pcsaHeader->Add("         errcount++;");
	pcsaHeader->Add("         setTimeout( \"checkInit()\", 2000 );");
	pcsaHeader->Add("      }");
	pcsaHeader->Add("      else"); 
	pcsaHeader->Add("      {");
	pcsaHeader->Add("         alert( \"Unable to initialize Reflection.\" );");
	pcsaHeader->Add("      }");
	pcsaHeader->Add("   }");
	pcsaHeader->Add("   return true;");
	pcsaHeader->Add("}");
	pcsaHeader->Add("");
	pcsaHeader->Add("");

	pcsaHeader->Add("function RunNewCode( msg, url, line )");
	pcsaHeader->Add("{");
	pcsaHeader->Add("");


}



void CAG_RWEB_VT_VBS::appendBody(int nFunctionNum,
								  bool bPromptForValues,
								  CStringArray* pcsaArguments,
								  CStringArray* pcsaHeader,
								  CStringArray* pcsaBody)
{
	CString csViewOutStuff;
	CString csFunctionName, csFunctionNum, csString, csStringLength, csRetCode;

	csFunctionName = pcsaArguments->GetAt( 0 );

	csViewOutStuff.Format( " " );
	pcsaBody->Add(csViewOutStuff);

	csViewOutStuff.Format( "   // *** %s", csFunctionName );
	pcsaBody->Add(csViewOutStuff);

	switch ( nFunctionNum )
	{
		case 7: //ECLField::GetScreen
		{
			if ( !b_ECLFieldObj )
			{
				declareVariable( AG_FIELD, pcsaHeader, &b_ECLFieldObj );
			}

			if ( !b_scrBuffer )
			{
				declareVariable( AG_SCREEN_DATA, pcsaHeader, &b_scrBuffer );
			}

			if ( !b_nReturn )
			{
				declareVariable( AG_N_RETURN, pcsaHeader, &b_nReturn );
			}

			if ( !b_spScreenPlane )
			{
				declareVariable( AG_SCREEN_PLANE, pcsaHeader, &b_spScreenPlane );
			}

			if ( !b_nScreenSize )
			{
				declareVariable( AG_SCREEN_SIZE, pcsaHeader, &b_nScreenSize );
			}


			csViewOutStuff.Format( "   nScreenSize = %s;", pcsaArguments->GetAt(1) );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "   spScreenPlane = ECLFieldObj.%s;", pcsaArguments->GetAt(2) );
			pcsaBody->Add(csViewOutStuff);


			csViewOutStuff.Format( "   try " );
			pcsaBody->Add(csViewOutStuff);
			
			csViewOutStuff.Format( "   {" );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "      nReturn = ECLFieldObj.GetScreen( scrBuffer, nScreenSize, spScreenPlane );"  );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "   }" );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "   catch(e)" );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "   {" );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "      window.status = \"Status: ECLFieldObj.GetScreen \" + e.message");
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "   }" );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( " " );
			pcsaBody->Add(csViewOutStuff);
		}
		break;


		case 0:	// ECLField::clearField
		case 1: // ECLField::equals
		case 2: // ECLField::GetAttribute
		case 3: // 	ECLField::GetEnd
		case 4: // 	ECLField::GetEndCol
		case 5: // 	ECLField::GetEndRow
		case 6: // 	ECLField::GetLength

		case 8:	// ECLField::GetScreen 2
		case 9:	// ECLField::GetStart
		case 10:	// ECLField::GetStartCol	// 10
		case 11:	// ECLField::GetStartRow
		case 12:	// ECLField::GetString
		case 13:	// ECLField::GetString 2
		case 14:	// ECLField::IsDisplay
		case 15:	// ECLField::IsHighIntensity
		case 16:	// ECLField::IsModified
		case 17:	// ECLField::IsNumeric
		case 18:	// ECLField::IsPenDetectable
		case 19:	// ECLField::IsProtected

		case 20:	// ECLField::IsTransmitOnly	// 20
		case 21:	// ECLField::SetString
		case 22:	// ECLField::SetText
		case 23:	// ECLFieldList::FindField
		case 24:	// ECLFieldList::FindField 2
		case 25:	// ECLFieldList::FindField 3
		case 26:	// ECLFieldList::FindField 4
		case 27:	// ECLFieldList::FindField 5
		case 28:	// ECLFieldList::GetFieldCount
		case 29:	// ECLFieldList::GetFirstField

		case 30:	// ECLFieldList::GetFirstField 2	//30
		case 31:	// ECLFieldList::GetNextField
		case 32:	// ECLFieldList::GetNextField 2
		case 33:	// ECLFieldList::Refresh
		case 34:	// ECLFieldList::Refresh 2
		case 35:	// ECLOIA::GetHPStatusFlags
		case 36:	// ECLOIA::GetParent
		case 37:	// ECLOIA::GetStatusFlags
		case 38:	// ECLOIA::InputInhibited
		case 39:	// ECLOIA::IsAlphanumeric

		case 40:	// ECLOIA::IsCommErrorReminder	// 40
		case 41:	// ECLOIA::IsDBCS
		case 42:	// ECLOIA::IsHPBlockMode
		case 43:	// ECLOIA::IsHPFormatMode
		case 44:	// ECLOIA::IsInsertMode
		case 45:	// ECLOIA::IsMessageWaiting
		case 46:	// ECLOIA::IsNumeric
		case 47:	// ECLOIA::RegisterOIAEvent
		case 48:	// ECLOIA::setKeyboardUnlockDuration
		case 49:	// ECLOIA::UnregisterOIAEvent

		case 50:	// ECLOIA::WaitForInput			// 50
		case 51:	// ECLOIA::WaitForInput 2
		case 52:	// ECLPS::ConvertPosToCol
		case 53:	// ECLPS::ConvertPosToColX
		case 54:	// ECLPS::ConvertPosToRow
		case 55:	// ECLPS::ConvertPosToRowX
		case 56:	// ECLPS::ConvertRowColToPos
		case 57:	// ECLPS::ConvertRowColToPosX
		case 58:	// ECLPS::GetCursorCol
		case 59:	// ECLPS::GetCursorPos

		case 60:	// ECLPS::GetCursorRow				// 60
		case 61:	// ECLPS::GetCursorVisible
		case 62:	// ECLPS::GetFieldList
		case 63:	// ECLPS::GetFieldList
		case 64:	// ECLPS::GetParent
		case 65:	// ECLPS::GetPosForRowFromEnd
		case 66:	// ECLPS::getRow
		case 67:	// ECLPS::GetScreen
		case 68:	// ECLPS::GetScreen 2
		case 69:	// ECLPS::GetScreen 3

		case 70:	// ECLPS::GetScreen 4					// 70
		case 71:	// ECLPS::GetScreen 5
		case 72:	// ECLPS::GetScreen 6
		case 73:	// ECLPS::GetScreenRect
		case 74:	// ECLPS::GetScreenRect 2
		case 75:	// ECLPS::GetScreenRect 3
		case 76:	// ECLPS::GetScreenRect 4
		case 77:	// ECLPS::GetSendKeyMnemonics
		case 78:	// ECLPS::getSendKeysKeyboardUnlockTimeout
		case 79:	// ECLPS::GetSize

		case 80:	// ECLPS::GetSizeCols					// 80
		case 81:	// ECLPS::GetSizeRows
		case 82:	// ECLPS::GetString
		case 83:	// ECLPS::GetString 2
		case 84:	// ECLPS::GetString 3
		case 85:	// ECLPS::GetString 4
		case 86:	// ECLPS::GetString 5
		case 87:	// ECLPS::GetString 6
		case 88:	// ECLPS::RegisterPSEvent
		case 89:	// ECLPS::RegisterPSEvent 2

		case 90:	// ECLPS::SearchString				// 90
		case 91:	// ECLPS::SearchString 2
		case 92:	// ECLPS::SearchString 3
		case 93:	// ECLPS::SearchText
		case 94:	// ECLPS::SearchText 2
		case 95:	// ECLPS::SearchText 3
		case 96:	// ECLPS::SendKeys
		case 97:	// ECLPS::SendKeys 2
		case 98:	// ECLPS::SendKeys 3
		case 99:	// ECLPS::SetCursorPos

		case 100:	// ECLPS::SetCursorPos 2				// 100
		case 101:	// ECLPS::SetCursorVisible
		case 102:	// ECLPS::setSendKeysKeyboardUnlockTimeout
		case 103:	// ECLPS::SetString
		case 104:	// ECLPS::SetString 2
		case 105:	// ECLPS::SetString 3
		case 106:	// ECLPS::SetText
		case 107:	// ECLPS::SetText 2
		case 108:	// ECLPS::SetText 3
		case 109:	// ECLPS::spacePadString

		case 110:	// ECLPS::UnregisterPSEvent				// 110
		case 111:	// ECLPS::UnregisterPSEvent 2
		case 112:	// ECLPS::WaitForCursor
		case 113:	// ECLPS::WaitForCursor 2
		case 114:	// ECLPS::WaitForHostPrompt
		case 115:	// ECLPS::WaitForHostPrompt 2
		case 116:	// ECLPS::WaitForScreen
		case 117:	// ECLPS::WaitForScreen 2
		case 118:	// ECLPS::WaitForString
		case 119:	// ECLPS::WaitForString 2

		case 120:	// ECLPS::WaitForString 3					// 120
		case 121:	// ECLPS::WaitWhileCursor
		case 122:	// ECLPS::WaitWhileCursor 2
		case 123:	// ECLPS::WaitWhileScreen
		case 124:	// ECLPS::WaitWhileScreen 2
		case 125:	// ECLPS::WaitWhileString
		case 126:	// ECLPS::WaitWhileString 2
		case 127:	// ECLPS::WaitWhileString 3
		case 128:	// ECLSession::addMessageServiceListener
		case 129:	// ECLSession::apiExit

		case 130:	// ECLSession::apvuReceiveFile		// 130
		case 131:	// ECLSession::apvuSendFile
		case 132:	// ECLSession::cancelFileXfer
		case 133:	// ECLSession::cancelPrintJob
		case 134:	// ECLSession::closePrinter
		case 135:	// ECLSession::connect
		case 136:	// ECLSession::disconnect
		case 137:	// ECLSession::display
		case 138:	// ECLSession::dispose
		case 139:	// ECLSession::doJavaScriptCall

		case 140:	// ECLSession::doJavaScriptEval		// 140
		case 141:	// ECLSession::endPrintJob
		case 142:	// ECLSession::exit
		case 143:	// ECLSession::exportKeymap
		case 144:	// ECLSession::findField
		case 145:	// ECLSession::findText
		case 146:	// ECLSession::flushPrintJob
		case 147:	// ECLSession::ftpAbort
		case 148:	// ECLSession::ftpCd
		case 149:	// ECLSession::ftpDisconnect

		case 150:	// ECLSession::ftpGetLastServerResponse	// 150
		case 151:	// ECLSession::ftpLCd
		case 152:	// ECLSession::ftpLogin
		case 153:	// ECLSession::ftpPwd
		case 154:	// ECLSession::ftpReceiveFile
		case 155:	// ECLSession::ftpReceiveFiles
		case 156:	// ECLSession::ftpSendFile
		case 157:	// ECLSession::ftpSendFiles
		case 158:	// ECLSession::getBoolean
		case 159:	// ECLSession::getCursorColumn

		case 160:	// ECLSession::getCursorPosition		// 160
		case 161:	// ECLSession::getCursorRow
		case 162:	// ECLSession::getDisplayText
		case 163:	// ECLSession::getDisplayText
		case 164:	// ECLSession::getEmulatorApplet
		case 165:	// ECLSession::getFieldText
		case 166:	// ECLSession::getFrameBounds
		case 167:	// ECLSession::getHostName
		case 168:	// ECLSession::getHostStatusText
		case 169:	// ECLSession::getHostURL

		case 170:	// ECLSession::getInteger				// 170
		case 171:	// ECLSession::getJSAPI
		case 172:	// ECLSession::GetOIA
		case 173:	// ECLSession::getParameter(
		case 174:	// ECLSession::getPort
		case 175:	// ECLSession::getPrinterMargin
		case 176:	// ECLSession::getPrinterPageSize
		case 177:	// ECLSession::getPrintScaling
		case 178:	// ECLSession::getPrintToFileFolder
		case 179:	// ECLSession::getPrintToFileName

		case 180:	// ECLSession::GetPS					// 180
		case 181:	// ECLSession::getSelectionBounds
		case 182:	// ECLSession::getString
		case 183:	// ECLSession::GetXfer
		case 184:	// ECLSession::importKeymap
		case 185:	// ECLSession::indReceiveFile
		case 186:	// ECLSession::indSendFile
		case 187:	// ECLSession::isConnected
		case 188:	// ECLSession::isIBM
		case 189:	// ECLSession::isStream

		case 190:	// ECLSession::loadComponent			// 190
		case 191:	// ECLSession::makeTextSelection
		case 192:	// ECLSession::passwordPrompt
		case 193:	// ECLSession::playbackMacro
		case 194:	// ECLSession::printBytes
		case 195:	// ECLSession::printCharacter
		case 196:	// ECLSession::printString
		case 197:	// ECLSession::printTestPage
		case 198:	// ECLSession::removeMessageServiceListener
		case 199:	// ECLSession::requestDisplayFocus

		case 200:	// ECLSession::resetUserPreferences		// 200
		case 201:	// ECLSession::saveUserPreferences
		case 202:	// ECLSession::screenPrint
		case 203:	// ECLSession::setBoolean
		case 204:	// ECLSession::setCursorPosition
		case 205:	// ECLSession::setHostURL
		case 206:	// ECLSession::setInteger
		case 207:	// ECLSession::setPrinterMargin
		case 208:	// ECLSession::setPrinterPageSize
		case 209:	// ECLSession::setPrintScaling

		case 210:	// ECLSession::setPrintToFileFolder		// 210
		case 211:	// ECLSession::setPrintToFileName
		case 212:	// ECLSession::setString
		case 213:	// ECLSession::showDialog
		case 214:	// ECLSession::ShowPSDebugger
		case 215:	// ECLSession::startPrintJob
		case 216:	// ECLSession::transmitString
		case 217:	// ECLSession::transmitTerminalKey
		case 218:	// ECLSession::waitForCursorEntered
		case 219:	// ECLSession::waitForCursorLeft

		case 220:	// ECLSession::waitForDisplayString		// 220
		case 221:	// ECLSession::waitForDisplayString
		case 222:	// ECLSession::waitForDisplayStrings
		case 223:	// ECLSession::waitForHostPrompt
		case 224:	// ECLSession::waitForKeyboardLock
		case 225:	// ECLSession::waitForKeyboardUnlock
		case 226:	// ECLSession::waitForString
		case 227:	// ECLSession::waitWhileDisplayString	
		case 228:	// ECLSession::waitWhileDisplayString 2
		case 229:	// ECLSession::waitWhileDisplayString 3

		case 230:	// ECLXfer::Cancel						// 230
		case 231:	// ECLXfer::GetParent
		case 232:	// ECLXfer::GetStartTimeout
		case 233:	// ECLXfer::GetTimeout
		case 234:	// ECLXfer::ReceiveFile
		case 235:	// ECLXfer::RegisterXferEvent
		case 236:	// ECLXfer::SendFile
		case 237:	// ECLXfer::SetStartTimeout
		case 238:	// ECLXfer::SetTimeout
		case 239:	// ECLXfer::setTransferHostType

		case 240:	// ECLXfer::UnregisterXferEvent			// 240
		{
			csViewOutStuff.Format( "   // APIGen has not yet implemented this method." );
			pcsaBody->Add(csViewOutStuff);
		}
		break;

	}
	

	pcsaArguments->RemoveAll();
}


void CAG_RWEB_VT_VBS::finalize(CStringArray* pcsaBody)
{
	CString csViewOutStuff;

	pcsaBody->Add( "}" );

	pcsaBody->Add( "</script>");
	pcsaBody->Add( "" );
	pcsaBody->Add( "<title>Reflection for the Web VT JavaScript</title>" );
	pcsaBody->Add( "</head>" );
	pcsaBody->Add( "" );
	pcsaBody->Add( "<body BGCOLOR=\"#C0C0C0\" LINK=\"#FFFFFF\" VLINK=\"#FFFFFF\" LEFTMARGIN=\"0\" TOPMARGIN=\"0\" Language=\"Javascript\">" );
	pcsaBody->Add( "<h1>WRQ Reflection for the Web -- VT Logon</h1><p>" );
	pcsaBody->Add( "" );
	pcsaBody->Add( "<!--");
	pcsaBody->Add( "   Create a basic VT applet on the page, but don't connect until");
	pcsaBody->Add( "   the user fills in the username and password information.");
	pcsaBody->Add( "   To use this example, change the hostURL parameter to one");
	pcsaBody->Add( "   appropriate for your network.");
	pcsaBody->Add( "-->");
	pcsaBody->Add( "<applet mayscript name=\"VT\"");
	pcsaBody->Add( "        codebase=\"./ex/\"");
	pcsaBody->Add( "        code=\"com.wrq.rweb.Launcher.class\"");
	pcsaBody->Add( "        width=\"600\" height=\"400\"");
	pcsaBody->Add( "        archive=\"Launcher.jar\">");
	pcsaBody->Add( "    <param name=\"hostURL\" value=\"telnet://accounts\">");
	pcsaBody->Add( "    <param name=\"autoconnect\" value=\"false\">");
	pcsaBody->Add( "    <param name=\"frame\" value=\"false\">");
	pcsaBody->Add( "    <param name=\"cabbase\" value=\"Launcher.cab\">");
	pcsaBody->Add( "    <param name=\"launcher.sessions\" value=\"VT\">");
	pcsaBody->Add( "    <param name=\"preloadJSAPI\" value=\"true\"> </applet> </p>");
	pcsaBody->Add( "<!--");
	pcsaBody->Add( "   Use <form> items to accept the Username and Password, and to create");
	pcsaBody->Add( "   a Logon button.");
	pcsaBody->Add( "-->");
	pcsaBody->Add( "<form name=\"LogonForm\">");
	pcsaBody->Add( "<p>Username: <input type=\"text\" name=\"Username\" default size=\"25\"></p>");
	pcsaBody->Add( "<p>Password: <input type=\"password\" name=\"Password\" size=\"25\"></p>");
	
	pcsaBody->Add( "<p><input type=\"button\" name=\"Logon\" value=\"Logon\" onClick=\"handleLogonButton()\"></p>");
	pcsaBody->Add( "<p><input type=\"button\" name=\"RunCode\" value=\"Run code\" onClick=\"RunNewCode()\"></p>");
	
	pcsaBody->Add( "</form>");
	pcsaBody->Add( "</body>");
	pcsaBody->Add( "</html>" );

}



void CAG_RWEB_VT_VBS::declareVariable(AG_VARIABLE agVariable,
									   CStringArray* pcsaHeader,
									   bool* bValue)
{
	CString csLocal;
	*bValue = TRUE;
	
	switch ( agVariable )
	{
		case AG_FIELD:
		{
			csLocal.Format( "Dim ECLFieldObj");
		}
		break;

		case AG_N_RETURN:
		{
			csLocal.Format( "Dim nReturn" );
		}
		break;

		case AG_SCREEN_DATA:
		{
			csLocal.Format( "Dim scrBuffer" );
		}
		break;
		
		case AG_SCREEN_PLANE:
		{
			csLocal.Format( "Dim spScreenPlane" );
		}
		break;

		case AG_SCREEN_SIZE:
		{
			csLocal.Format( "Dim nScreenSize" );
		}
		break;

		
	}

	pcsaHeader->Add(csLocal);
	
}


void CAG_RWEB_VT_VBS::checkDebug(bool b_Debug,
								  CString csFunctionName,
								  CStringArray* pcsaBody)
{
	CString csLocal;
	
	if ( b_Debug )
	{
		csLocal.Format( "   alert( \"%s\" );", csFunctionName );
		pcsaBody->Add(csLocal);
	}
}

void CAG_RWEB_VT_VBS::resetVariableFlags()
{
	b_ECLFieldObj=0;
	b_scrBuffer=0;
	b_nReturn=0;
	b_Debug=0;
	b_spScreenPlane=0;
	b_nScreenSize=0;
}