// Static Model
#include "stdafx.h"
#include "apigen.h"

#include "CAG_ROLE_5250_WS.h"

CAG_ROLE_5250_WS::CAG_ROLE_5250_WS()
{
	resetVariableFlags();
}

CAG_ROLE_5250_WS::~CAG_ROLE_5250_WS()
{
	
}


void CAG_ROLE_5250_WS::generateHeader(CStringArray* pcsaHeader,
									  CStringArray* pcsaBody)
{
		// name and open output file if specified
	SYSTEMTIME	systime;
	GetSystemTime(&systime);
	time_t osBinaryTime;
	time( &osBinaryTime ) ;
	CTime t( osBinaryTime );
	
	int nMonth = t.GetMonth();
	int nDay = t.GetDay();
	int nYear = t.GetYear();

	CString csViewOutStuff;

	pcsaHeader->Add("' ****************************************************************************");
	pcsaHeader->Add("'                   Attachmate Reflection 5250");
	pcsaHeader->Add("'                 APIGen Windows VBScript Scripting");
	pcsaHeader->Add("'" );
	pcsaHeader->Add("'   This file consists of Windows VBScript commands that drive the Reflection for");
	pcsaHeader->Add("'   IBM OLE Automation interface.");
	pcsaHeader->Add("'" );
	pcsaHeader->Add("'   This script is prepared to launch a visible and connected session. For Reflection");
	pcsaHeader->Add("'   to automatically connect the session when it is loaded you must ensure that the \"Auto");
	pcsaHeader->Add("'   connect\" option is checked on the Session setup dialog that can be found in the");
	pcsaHeader->Add("'   Session menu.");
	pcsaHeader->Add("'" );
	pcsaHeader->Add("'   After this code is generated it will be necessary for you to double click on");
	pcsaHeader->Add("'   this .vbs file.  You may choose to modify this file in one or more of the ");
	pcsaHeader->Add("'   following ways:");
	pcsaHeader->Add("'   1) Timing issues/race conditions are more common in this type of scripting. So,");
	pcsaHeader->Add("'      a prompt is presented when you run the script that asks for a literal string");
	pcsaHeader->Add("'      that an initial WaitForDisplayString call can use in your session to better prepare");
	pcsaHeader->Add("'      the system for the generated automation calls that follow.");
	pcsaHeader->Add("'   2) You may choose to change the 10-second timeout value on the WaitForDisplayString");
	pcsaHeader->Add("'      call to a value better suited for your system. Note that the WaitForDisplayString");
	pcsaHeader->Add("'      call will return as soon as the search string is found and will not block the full.");
	pcsaHeader->Add("'      ten seconds unless the specified string is not found.");
	pcsaHeader->Add("'   3) You can encrypt this file using the Microsoft Script Encoder for Windows");
	pcsaHeader->Add("'      Script Files to prevent users from reading your source code.");
	pcsaHeader->Add("'   4) You can compile it into a script component to selectively expose its functionality");
	pcsaHeader->Add("'      and establish its Windows security credentials.");
	pcsaHeader->Add("'         ");
	pcsaHeader->Add("'   Note: You may see declarations for various constants just after the time stamp below that are");
	pcsaHeader->Add("'         used in some function calls.  This script does not link to a file with the actual constant");
	pcsaHeader->Add("'         definitions, but because the constants' names provide indications on about what is going");
	pcsaHeader->Add("'         on in a given call, and save work if you happen to ultimately use this file as a portion");
	pcsaHeader->Add("'         of a VB 6.0 or VBA application they will be used.  With that stated, if you DO copy this");
	pcsaHeader->Add("'         code for use in an enviroment in which the declarations are implicit, you must remove each");
	pcsaHeader->Add("'         line that fits the pattern \"Dim rcXXX\" where \"XXX\" stands in for a string such as \"AnyRow\"");
	pcsaHeader->Add("'         ");

	time_t ltime;
	time( &ltime );

	pcsaHeader->Add("'" );
	csViewOutStuff.Format( "'   Generated:   %s", ctime( &ltime ) );
	pcsaHeader->Add(csViewOutStuff);

	pcsaHeader->Add( "" );
	pcsaHeader->Add("' ****************************************************************************");
	pcsaHeader->Add( "" );
	pcsaHeader->Add("Dim System");
	pcsaHeader->Add("Dim RIBMSession");
	pcsaHeader->Add("Dim Sessionname");
	pcsaHeader->Add("Dim cString" );

	pcsaBody->Add("" );
	pcsaBody->Add("set RIBMSession = CreateObject(\"ReflectionIBM.Session\")" );
	pcsaBody->Add("" );
	pcsaBody->Add("Sessionname = inputbox(\"Open this Reflection 5250 session:\", \"Specify fully qualified Reflection session\", \"C:\\TEMP\\baker.rsf\")");
	pcsaBody->Add("RIBMSession.Visible = True");
	pcsaBody->Add("RIBMSession.OpenSettings 1, Sessionname");
	pcsaBody->Add("RIBMSession.WaitForEvent 1, \"30\", \"1\", 1, 1");
	pcsaBody->Add("on error resume next");
	pcsaBody->Add("if Sessionname = \"\" then");
	pcsaBody->Add("   WScript.Quit(1)");
	pcsaBody->Add("else");
	pcsaBody->Add("   cString = inputbox(\"Please provide a ready state indicator string:\", \"Specify ready indicator\", \"userid\")");

	if ( !b_rcAnyRow )
	{
		declareVariable( AG_rcANYROW, pcsaHeader, &b_rcAnyRow );
	}

	if ( !b_rcAnyCol )
	{
		declareVariable( AG_rcANYCOL, pcsaHeader, &b_rcAnyCol );
	}

	pcsaBody->Add("   Session.WaitForDisplayString cString, \"0:0:10\", rcAnyRow, rcAnyCol" );
	pcsaBody->Add("" );

}


void CAG_ROLE_5250_WS::appendBody(int nFunctionNum,
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

	csViewOutStuff.Format( "'*** %s", csFunctionName );
	pcsaBody->Add(csViewOutStuff);

	switch ( nFunctionNum )
	{
		case 0:		// AbortTransfer
		{
			csViewOutStuff.Format( "RIBMSession.AbortTransfer" );
			pcsaBody->Add(csViewOutStuff);
		}
		break;

		case 1:		// AboutReflectionDlg
		{
			csViewOutStuff.Format( "RIBMSession.AboutReflectionDlg" );
			pcsaBody->Add(csViewOutStuff);
		}
		break;

		case 2:		// ActivateCommandLine
		{
			csViewOutStuff.Format( "RIBMSession.ActivateCommandLine" );
			pcsaBody->Add(csViewOutStuff);
		}
		break;

		case 3:		// AddHotListItem
		{
			if ( !b_cString )
			{
				declareVariable( AG_STRING, pcsaHeader, &b_cString );
			}

			if ( !b_csName )
			{
				declareVariable( AG_NAME, pcsaHeader, &b_csName );
			}

			if ( !b_csCommand )
			{
				declareVariable( AG_COMMAND, pcsaHeader, &b_csCommand );
			}

			if ( !b_nOptions )
			{
				declareVariable( AG_OPTIONS, pcsaHeader, &b_nOptions );
			}

			
			csViewOutStuff.Format( "cString = \"%s\"", pcsaArguments->GetAt(1) );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "csName = \"%s\"", pcsaArguments->GetAt(2) );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "csCommand = \"%s\"", pcsaArguments->GetAt(3) );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "nOptions = %s", pcsaArguments->GetAt(4) );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "RIBMSession.AddHotListItem cString, csName, csCommand, nOptions" );
			pcsaBody->Add(csViewOutStuff);

		}
		break;

		case 4:		// AddReference
		{
			if ( !b_cString )
			{
				declareVariable( AG_STRING, pcsaHeader, &b_cString );
			}

			csViewOutStuff.Format( "cString = \"%s\"", pcsaArguments->GetAt(1) );
			pcsaBody->Add(csViewOutStuff);


			csViewOutStuff.Format( "RIBMSession.AddReference cString" );
			pcsaBody->Add(csViewOutStuff);

		}
		break;

		case 5:		// AddReferenceDlg
		{
			csViewOutStuff.Format( "RIBMSession.AddReferenceDlg" );
			pcsaBody->Add(csViewOutStuff);
		}
		break;

		case 6:		// AppendSelection
		{
			csViewOutStuff.Format( "RIBMSession.AppendSelection" );
			pcsaBody->Add(csViewOutStuff);
		}
		break;

		case 7:		// AppendSQLStatement
		{
			if ( !b_nType )
			{
				declareVariable( AG_TYPE, pcsaHeader, &b_nType );
			}

			if ( !b_csCommand )
			{
				declareVariable( AG_COMMAND, pcsaHeader, &b_csCommand );
			}

			csViewOutStuff.Format( "nType = %s", pcsaArguments->GetAt(1) );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "csCommand = \"%s\"", pcsaArguments->GetAt(2) );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "RIBMSession.AppendSQLStatement nType, csCommand" );
			pcsaBody->Add(csViewOutStuff);

		}
		break;

		case 8:		// CancelSelection
		{
			csViewOutStuff.Format( "RIBMSession.CancelSelection" );
			pcsaBody->Add(csViewOutStuff);
		}
		break;

		case 9:		// CancelTransfer
		{
			csViewOutStuff.Format( "RIBMSession.CancelTransfer" );
			pcsaBody->Add(csViewOutStuff);
		}
		break;
	
		case 10:	// CheckEvent			// 10
		{
			csViewOutStuff.Format( "RIBMSession.CheckEvent" );
			pcsaBody->Add(csViewOutStuff);
		}
		break;
	
		case 11:	// CheckEventNumber
		{
			if ( !b_nEventNum )
			{
				declareVariable( AG_EVENT, pcsaHeader, &b_nEventNum );
			}

			csViewOutStuff.Format( "nEventNum = %s", pcsaArguments->GetAt(1) );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "RIBMSession.CheckEventNumber nEventNum" );
			pcsaBody->Add(csViewOutStuff);

		}
		break;

		case 12:	// ClearEvents
		{
			csViewOutStuff.Format( "RIBMSession.ClearEvents" );
			pcsaBody->Add(csViewOutStuff);
		}
		break;
	
		case 13:	// ClearHotlists
		{
			csViewOutStuff.Format( "RIBMSession.ClearHotlists" );
			pcsaBody->Add(csViewOutStuff);
		}
		break;
	
		case 14:	// ClearHotspots
		{
			csViewOutStuff.Format( "RIBMSession.ClearHotspots" );
			pcsaBody->Add(csViewOutStuff);
		}
		break;
	
		case 15:	// ClearIBMPrinterFonts
		{
			csViewOutStuff.Format( "RIBMSession.ClearIBMPrinterFonts" );
			pcsaBody->Add(csViewOutStuff);
		}
		break;
	
		case 16:	// ClearMenu
		{
			csViewOutStuff.Format( "RIBMSession.ClearMenu" );
			pcsaBody->Add(csViewOutStuff);
		}
		break;
	
		case 17:	// ClearNWSAA3270Config
		{
			csViewOutStuff.Format( "RIBMSession.ClearNWSAA3270Config" );
			pcsaBody->Add(csViewOutStuff);
		}
		break;
	
		case 18:	// ClearSelection
		{
			csViewOutStuff.Format( "RIBMSession.ClearSelection" );
			pcsaBody->Add(csViewOutStuff);
		}
		break;
	
		case 19:	// ClosePrinter
		{
			csViewOutStuff.Format( "RIBMSession.ClosePrinter" );
			pcsaBody->Add(csViewOutStuff);
		}
		break;
	
		case 20:	// CommitLoginProperties	// 20
		{
			csViewOutStuff.Format( "   // This method is obsolete." );
			pcsaBody->Add(csViewOutStuff);
		}
		break;

		case 21:	// CompileScript
		{
			if ( !b_cString )
			{
				declareVariable( AG_STRING, pcsaHeader, &b_cString );
			}

			csViewOutStuff.Format( "cString = \"%s\"", pcsaArguments->GetAt(1) );
			pcsaBody->Add(csViewOutStuff);


			csViewOutStuff.Format( "RIBMSession.CompileScript cString" );
			pcsaBody->Add(csViewOutStuff);

		}
		break;

		case 22:	// Connect
		{
			csViewOutStuff.Format( "RIBMSession.Connect" );
			pcsaBody->Add(csViewOutStuff);
		}
		break;
	
		case 23:	// CopyPasteSettingsDialog
		{
			csViewOutStuff.Format( "RIBMSession.CopyPasteSettingsDialog" );
			pcsaBody->Add(csViewOutStuff);
		}
		break;
	
		case 24:	// CopySelection
		{
			csViewOutStuff.Format( "RIBMSession.CopySelection" );
			pcsaBody->Add(csViewOutStuff);
		}
		break;
	
		case 25:	// CopyTable
		{
			csViewOutStuff.Format( "RIBMSession.CopyTable" );
			pcsaBody->Add(csViewOutStuff);
		}
		break;
	
		case 26:	// CutSelection
		{
			csViewOutStuff.Format( "RIBMSession.CutSelection" );
			pcsaBody->Add(csViewOutStuff);
		}
		break;
	
		case 27:	// DDESetupDlg
		{
			csViewOutStuff.Format( "RIBMSession.DDESetupDlg" );
			pcsaBody->Add(csViewOutStuff);
		}
		break;
	
		case 28:	// DefineEvent
		{
			if ( !b_nEventNum )
			{
				declareVariable( AG_EVENT, pcsaHeader, &b_nEventNum );
			}

			if ( !b_nType )
			{
				declareVariable( AG_TYPE, pcsaHeader, &b_nType );
			}

			if ( !b_cString )
			{
				declareVariable( AG_STRING, pcsaHeader, &b_cString );
			}

			if ( !b_nRow )
			{
				declareVariable( AG_ROW, pcsaHeader, &b_nRow );
			}

			if ( !b_nColumn )
			{
				declareVariable( AG_COLUMN, pcsaHeader, &b_nColumn );
			}

			if ( !b_nKey )
			{
				declareVariable( AG_KEY, pcsaHeader, &b_nKey );
			}

			csViewOutStuff.Format( "nEventNum = %s", pcsaArguments->GetAt(1) );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "nType = %s", pcsaArguments->GetAt(2) );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "cString = \"%s\"", pcsaArguments->GetAt(3) );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "nRow = %s", pcsaArguments->GetAt(4));
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "nColumn = %s", pcsaArguments->GetAt(5));
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "nKey = %s", pcsaArguments->GetAt(6));
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "RIBMSession.DefineEvent nEventNum, nType, cString, nRow, nColumn, nKey" );
			pcsaBody->Add(csViewOutStuff);

		}
		break;


		case 29:	// DefineHotspotEx

		case 30:	// DefineToolbarButton	// 30
		case 31:	// DeletePopupItem
		case 32:	// Disconnect
		case 33:	// DisplaySetupDlg
		case 34:	// EditMacro
		case 35:	// EditScript
		case 36:	// EditScriptDlg
		case 37:	// EnableInternalTrace
		case 38:	// EnableOnEvent
		case 39:	// Exit

		case 40:	// ExtendSelection	// 40
		case 41:	// ExtendSelectionLine
		case 42:	// ExtendSelectionPage
		case 43:	// ExtendSelectionRect
		case 44:	// ExtendSelectionWord
		case 45:	// FindField
		case 46:	// FindText
		case 47:	// GetBufferedTermKey
		case 48:	// GetButtonPictureFile
		case 49:	// GetClipboardText

		case 50:	// GetCommandProfile	// 50
		case 51:	// GetCommandRecording
		case 52:	// GetCurrentHotspot
		case 53:	// GetCurrentHotspotEx
		case 54:	// GetDisplayText
		case 55:	// GetErrorString
		case 56:	// GetFieldAttributes
		case 57:	// GetFieldColor
		case 58:	// GetFieldText
		case 59:	// GetHotlistItem

		case 60:	// GetHotlistItemCommands	// 60
		case 61:	// GetHotlistItemOptions
		case 62:	// GetHotlistName
		case 63:	// GetHotlistOptions
		case 64:	// GetHotlistShowPosition
		case 65:	// GetHotspotCommandsEx
		case 66:	// GetHotspotHelp
		case 67:	// GetHotspots
		case 68:	// GetHotspotsEx
		case 69:	// GetHotspotTip

		case 70:	// GetKeymap	// 70
		case 71:	// GetLastActiveInstance
		case 72:	// GetLoginProperty
		case 73:	// GetMouseMap
		case 74:	// GetMyWindow
		case 75:	// GetNumHotlists
		case 76:	// GetNumHotspots
		case 77:	// GetNumItems
		case 78:	// GetOpenFilename
		case 79:	// GetPassword

		case 80:	// GetSaveAsFilename	// 80
		case 81:	// GetScanCode
		case 82:	// GetSetProfile
		case 83:	// GetSetStringProfile
		case 84:	// GetSQLStatement
		case 85:	// GetVersionNumber
		case 86:	// GraphicsMouse
		case 87:	// Help
		case 88:	// HelpCursor
		case 89:	// HotlistSetupDlg

		case 90:	// HotspotSetupDlg	// 90
		case 91:	// IndReceiveFile
		case 92:	// IndSendFile
		case 93:	// InsertPopupItem
		case 94:	// InternalTraceDlg
		case 95:	// IssuePrinterCommand
		case 96:	// KeyboardMapSetupDlg
		case 97:	// LightPen
		case 98:	// MacrosDlg
		case 99:	// MenuSetupDlg

		case 100:	// MouseMapSetupDlg	// 100
		case 101:	// MoveCursor
		case 102:	// MoveGraphicsCursor
		case 103:	// NewHotlist
		case 104:	// NewSession
		case 105:	// NewSessionDlg
		case 106:	// NewToolbar
		case 107:	// OnEvent
		case 108:	// OnEventSetupDlg
		case 109:	// OpenSettings

		case 110:	// OpenSettingsDlg	// 110
		case 111:	// PageSetupDlg
		case 112:	// PasswordBox
		case 113:	// Paste
		case 114:	// PasteNext
		case 115:	// PasteRange
		case 116:	// PasteRangeDlg
		case 117:	// PcsReceiveFile
		case 118:	// PcsSendFile
		case 119:	// PlayBackTrace

		case 120:	// PlayBackTraceDlg	// 120
		case 121:	// PlayNextTraceRecord
		case 122:	// PlayPreviousTraceRecord
		case 123:	// PreferenceSetupDlg
		case 124:	// Print
		case 125:	// PrintControl
		case 126:	// PrintDlg
		case 127:	// PrintHostFile
		case 128:	// PrintScreen
		case 129:	// PrintSetupDlg

		case 130:	// PrintString
		case 131:	// PrintTransparentChar
		case 132:	// Quit
		case 133:	// ReadQuickTest
		case 134:	// RecordingSetupDlg
		case 135:	// RemoveAllToolbars
		case 136:	// RemoveEvent
		case 137:	// RemoveHotlist
		case 138:	// RemoveNWSAA3270Config
		case 139:	// RemoveOnEvent

		case 140:	// RemoveToolbar
		case 141:	// RemoveToolbarButton
		case 142:	// ResetCommands
		case 143:	// ResetEvent
		case 144:	// RestoreDefaults
		case 145:	// RunExternalMacro
		case 146:	// RunMacro
		case 147:	// RunScript
		case 148:	// RunScriptDlg
		case 149:	// SaveDisplay

		case 150:	// SaveDisplayDlg
		case 151:	// SaveSettings
		case 152:	// SaveSettingsAsDlg
		case 153:	// SaveSettingsDlg
		case 154:	// SaveXML
		case 155:	// SelectAll
		case 156:	// SelectLine
		case 157:	// SelectWord
		case 158:	// SendMail
		case 159:	// SendMailDlg

		case 160:	// SessionSetupDlg
		case 161:	// SetAPLKeyMap
		case 162:	// SetClipboardText
		case 163:	// SetColorMap
		case 164:	// SetCommandProfile
		case 165:	// SetCommandRecording
		case 166:	// SetDisplayAttribute
		case 167:	// SetEncryptedString
		case 168:	// SetIBMPrinterFont
		case 169:	// SetKeyMap

		case 170:	// SetMouseMap
		case 171:	// SetMousePos
		case 172:	// SetNumeric
		case 173:	// SetNumericProfile
		case 174:	// SetRecentlyUsedFile
		case 175:	// SetScanCodeName
		case 176:	// SetSelectionStartPos
		case 177:	// SetSQLStatement
		case 178:	// SetString
		case 179:	// SetStringProfile

		case 180:	// SetTerminalKbdPos
		case 181:	// SetTermKeyBuffer
		case 182:	// SetToolbarMode
		case 183:	// SetToolbarPosition
		case 184:	// SetupNWSAA3270Config
		case 185:	// SetupSession
		case 186:	// SetWindowsPos
		case 187:	// Shell
		case 188:	// ShowDBCSHostCodeInputWindow
		case 189:	// ShowDisplayAttribute

		case 190:	// ShotHotlist
		case 191:	// ShowToolbar
		case 192:	// ShowToolbarButtonsFixedWidth
		case 193:	// ShowToolbarColor
		case 194:	// ShowToolbarLabels
		case 195:	// ShowToolbarLarge
		case 196:	// ShowToolbarTips
		case 197:	// StartInternalTrace
		case 198:	// StartRecording
		case 199:	// StartTrace

		case 200:	// StartTraceDlg
		case 201:	// StopInternalTrace
		case 202:	// StopMacro
		case 203:	// StopRecording
		case 204:	// StopRecordingDlg
		case 205:	// StopRecordingMacro
		case 206:	// StopScript
		case 207:	// StopTrace
		case 208:	// SwitchToWindow
		case 209:	// TerminalMouse

		case 210:	// TerminalSetupDlg
		case 211:	// TetherToolbar
		case 212:	// Toggle
		case 213:	// ToobarSetupDlg
		case 214:	// TransferDlg
		case 215:	// TransferSetupDlg
		case 216:	// TransformXML
		{
			csViewOutStuff.Format( "' APIGen has not yet implemented this method." );
			pcsaBody->Add(csViewOutStuff);
		}
		break;

		case 217:	// TransmitAnsi
		{
			if ( !b_cString )
			{
				declareVariable( AG_STRING, pcsaHeader, &b_cString );
			}

			csViewOutStuff.Format( "cString = \"%s\"", pcsaArguments->GetAt(1) );
			pcsaBody->Add(csViewOutStuff);


			csViewOutStuff.Format( "RIBMSession.TransmitAnsi cString" );
			pcsaBody->Add(csViewOutStuff);

		}
		break;


		case 218:	// TransmitTerminalKey
		case 219:	// ViewSettingsDlg

		case 220:	// Wait
		case 221:	// WaitEvent
		case 222:	// WaitEventNumber
		case 223:	// WaitForCommString
		case 225:	// WaitForEvent
		case 226:	// WaitForPrinterStatusString
		case 227:	// WaitForPrinterString
		case 228:	// WaitForPrinterStringReplace
		case 229:	// WaitForTerminalKey

		case 230:	// WaitForTimeOfDay
		case 231:	// WriteQuickText
		{
			csViewOutStuff.Format( "' APIGen has not yet implemented this method." );
			pcsaBody->Add(csViewOutStuff);
		}
		break;

		case 224:	// WaitForDisplayString
		{
			if ( !b_cString )
			{
				declareVariable( AG_STRING, pcsaHeader, &b_cString );
			}

			if ( !b_nTimeout )
			{
				declareVariable( AG_TIMEOUT, pcsaHeader, &b_nTimeout );
			}

			if ( !b_nRow )
			{
				declareVariable( AG_ROW, pcsaHeader, &b_nRow );
			}

			if ( !b_nColumn )
			{
				declareVariable( AG_COLUMN, pcsaHeader, &b_nColumn );
			}

			csViewOutStuff.Format( "cString = \"%s\"", pcsaArguments->GetAt(1));
			pcsaBody->Add(csViewOutStuff);
			
			if ( 0 == pcsaArguments->GetAt(2).GetLength())
			{
				csViewOutStuff.Format( "nTimeout = 5000" );
				pcsaBody->Add(csViewOutStuff);
			}
			else
			{
				csViewOutStuff.Format( "nTimeout = %s", pcsaArguments->GetAt(2));
				pcsaBody->Add(csViewOutStuff);
			}

			if ( 0 == pcsaArguments->GetAt(3).GetLength())
			{
				csViewOutStuff.Format( "nRow = 1" );
				pcsaBody->Add(csViewOutStuff);
			}
			else
			{
				csViewOutStuff.Format( "nRow = %s", pcsaArguments->GetAt(3));
				pcsaBody->Add(csViewOutStuff);
			}

			if ( 0 == pcsaArguments->GetAt(4).GetLength())
			{
				csViewOutStuff.Format( "nColumn = 1" );
				pcsaBody->Add(csViewOutStuff);
			}
			else
			{
				csViewOutStuff.Format( "nColumn = %s", pcsaArguments->GetAt(4));
				pcsaBody->Add(csViewOutStuff);
			}

			pcsaBody->Add("RIBMSession.WaitForDisplayString cString, nRow, nColumn, nTimeout " );

		}
		break;
	}

	pcsaArguments->RemoveAll();
}


void CAG_ROLE_5250_WS::finalize(CStringArray* pcsaBody)
{
	CString csViewOutStuff;

	pcsaBody->Add("end if");
	pcsaBody->Add(" " );

}

void CAG_ROLE_5250_WS::declareVariable(AG_VARIABLE agVariable,
									   CStringArray* pcsaHeader,
									   bool* bValue)
{
	CString csLocal;
	*bValue = TRUE;
	
	switch ( agVariable )
	{
		case AG_STRING:
		{
			csLocal.Format( "Dim cString");
		}
		break;

		case AG_STATUS:
		{
			csLocal.Format( "Dim nStatus");
		}
		break;

		case AG_UPDATED:
		{
			csLocal.Format( "Dim bUpdated");
		}
		break;

		case AG_rcANYROW:
		{
			csLocal.Format( "Dim rcAnyRow");
			pcsaHeader->Add(csLocal);
			csLocal.Format( "rcAnyRow=0");
		}
		break;
	
		case AG_rcANYCOL:
		{
			csLocal.Format( "Dim rcAnyCol");
			pcsaHeader->Add(csLocal);
			csLocal.Format( "rcAnyCol=0");
		}
		break;
	
		case AG_BSTR:
		{
			csLocal.Format( "Dim v");
		}
		break;
	
		case AG_COMMAND:
		{
			csLocal.Format( "Dim csCommand");
		}
		break;

		case AG_ENDCOLUMN:
		{
			csLocal.Format( "Dim nEndColumn");
		}
		break;

		case AG_ENDROW:
		{
			csLocal.Format( "Dim nEndRow");
		}
		break;

		case AG_ROW:
		{
			csLocal.Format( "Dim nRow");
		}
		break;

		case AG_COLUMN:
		{
			csLocal.Format( "Dim nColumn");		
		}
		break;

		case AG_ATTRIBUTE:
		{
			csLocal.Format( "Dim nAttribute");
		}
		break;

		case AG_LENGTH:
		{
			csLocal.Format( "Dim nLength");
		}
		break;

		case AG_VALUE:
		{
			csLocal.Format( "Dim nValue");
		}
		break;

		case AG_RETURN:
		{
			csLocal.Format( "Dim bRet");
		}
		break;

		case AG_CLOSEOPTION:
		{
			csLocal.Format( "Dim nCloseOption");
		}
		break;

		case AG_FT_OBJ:
		{
			csLocal.Format( "Dim ftObj");
		}
		break;

		case AG_HOSTNAME:
		{
			csLocal.Format( "Dim hostname");
		}
		break;

		case AG_HOST_OS:
		{
			csLocal.Format( "Dim nFTHostOS");
		}
		break;

		case AG_HEIGHT:
		{
			csLocal.Format( "Dim nHeight");
		}
		break;

		case AG_LOCALMODE:
		{
			csLocal.Format( "Dim bLocalMode");
		}
		break;

		case AG_SCREEN_HELD:
		{
			csLocal.Format( "Dim bScreenHeld");
		}
		break;

		case AG_SESS_SAVED:
		{
			csLocal.Format( "Dim bSessionSaved");
		}
		break;

		case AG_SESSIONS_CREATED:
		{
			csLocal.Format( "Dim Sessions" );
		}
		break;

		case AG_SESS_OPEN:
		{
			csLocal.Format( "Dim SessName");
		}
		break;


		case AG_SETTLE_TIME:
		{
			csLocal.Format( "Dim nSettleTime");
		}
		break;

		case AG_SESS_QUIET:
		{
			csLocal.Format( "Dim bSessionQuiet");
		}
		break;

		case AG_SETTINGS_PAGE:
		{
			csLocal.Format( "Dim settingsPage");
		}
		break;

		case AG_SETTINGS_TAB:
		{
			csLocal.Format( "Dim settingsTab");
		}
		break;

		case AG_MENU_VISIBLE:
		{
			csLocal.Format( "Dim bMenuVisible");
		}
		break;

		case AG_IDLE_TIME:
		{
			csLocal.Format( "Dim nIdle");
		}
		break;

		case AG_OPTIONS:
		{
			csLocal.Format( "Dim nOptions");
		}
		break;

		case AG_PAGE:
		{
			csLocal.Format( "Dim nPage");
		}
		break;

		case AG_TYPE:
		{
			csLocal.Format( "Dim nType");
		}
		break;

		case AG_TIMEOUT:
		{
			csLocal.Format( "Dim nTimeout");
		}
		break;

		case AG_PROCESS:
		{
			csLocal.Format( "Dim bProcess");
		}
		break;

		case AG_PROCESS_KEYSTROKES:
		{
			csLocal.Format( "Dim sKeys");
		}
		break;

		case AG_WIDTH:
		{
			csLocal.Format( "Dim nWidth");
		}
		break;

		case AG_WINDOW_HANDLE:
		{
			csLocal.Format( "Dim hSession");
			//csLocal.Format( "HANDLE hSession=NULL");
		}
		break;

		case AG_WINDOW_STATE:
		{
			csLocal.Format( "Dim nWindowState");
		}
		break;

		case AG_COUNT:
		{
			csLocal.Format( "Dim nCount");
		}
		break;

		case AG_AREA:
		{
			csLocal.Format( "Dim Area");
		}
		break;

		case AG_EVENT:
		{
			csLocal.Format( "Dim nEventNum" );
		}
		break;


		case AG_FONTNAME:
		{
			csLocal.Format( "Dim font" );
		}
		break;

		case AG_FT_SCHEME:
		{
			csLocal.Format( "Dim FTScheme" );
		}
		break;

		// new stuff
		case AG_NAME:
		{
			csLocal.Format( "Dim csName" );
		}
		break;

		case AG_TERMINAL:
		{
			csLocal.Format( "Dim Terminal" );
		}
		break;

		case AG_OIAOBJ:
		{
			csLocal.Format( "Dim OIAObj" );
		}
		break;

		case AG_TEXT:
		{
			csLocal.Format( "Dim cText" );
		}
		break;

		case AG_EAB:
		{
			csLocal.Format( "Dim bEABs" );
		}
		break;

		case AG_HOST_CHARSET:
		{
			csLocal.Format( "Dim nCharSet" );
		}
		break;

		case AG_HOST_CODEPAGE:
		{
			csLocal.Format( "Dim nHostCodePage" );
		}
		break;

		case AG_KBD_LOCKED:
		{
			csLocal.Format( "Dim bKeyboardLocked" );
		}
		break;

		case AG_MODEL:	
		{
			csLocal.Format( "Dim nModel" );
		}
		break;

		case AG_MODE:
		{
			csLocal.Format( "Dim nMode" );
		}
		break;

		case AG_WAIT:
		{
			csLocal.Format( "Dim nWait" );
		}
		break;

		case AG_ATTACHED:
		{
			csLocal.Format( "Dim bAttached" );
		}
		break;

		case AG_CONNECTED:
		{
			csLocal.Format( "Dim bConnected" );
		}
		break;

		case AG_CONNECTION_OBJ:
		{
			csLocal.Format( "Dim conn" );
		}
		break;

		case AG_SCREEN_OBJ:
		{
			csLocal.Format( "Dim screen" );
		}
		break;

		case AG_STATE:
		{
			csLocal.Format( "Dim nState" );
		}
		break;

		case AG_PORT:
		{
			csLocal.Format( "Dim nPort" );
		}
		break;

		case AG_KEY:
		{
			csLocal.Format( "Dim nKey" );
		}
		break;


	}

	pcsaHeader->Add(csLocal);
	
}


void CAG_ROLE_5250_WS::checkDebug(bool b_Debug,
								  CString csFunctionName,
								  CStringArray* pcsaBody)
{
	CString csLocal;
	
	if ( b_Debug )
	{
		csLocal.Format( "MsgBox( \"%s\" )", csFunctionName );
		pcsaBody->Add(csLocal);
	}
}

void CAG_ROLE_5250_WS::resetVariableFlags()
{
	b_Area=FALSE;
	b_bAttached=FALSE;
	b_bConnected=FALSE;
	b_bEABs=FALSE;
	b_bKeyboardLocked=FALSE;
	b_bLocalMode=FALSE;
	b_bMenuVisible=FALSE;
	b_bProcess=FALSE;
	b_bRet=FALSE;
	b_bScreenHeld=FALSE;
	b_bSessionQuiet=FALSE;
	b_bSessionSaved=FALSE;
	b_bUpdated=FALSE;
	b_ConnectionObj=FALSE;
	b_csCommand=FALSE;
	b_csName=FALSE;
	b_cString=TRUE;
	b_cText=FALSE;
	b_Debug=FALSE;
	b_font=FALSE;
	b_ftObj=FALSE;
	b_FTScheme=FALSE;
	b_hostname=FALSE;
	b_hSession=FALSE;
	b_nAttribute=FALSE;
	b_nCharSet=FALSE;
	b_nCloseOption=FALSE;
	b_nColumn=FALSE;
	b_nCount=FALSE;
	b_nEndColumn=FALSE;
	b_nEndRow=FALSE;
	b_nEventNum=FALSE;
	b_nHeight=FALSE;
	b_nHostCodePage=FALSE;
	b_nHostOS=FALSE;
	b_nIdle=FALSE;
	b_nIdleTime=FALSE;
	b_nKey=FALSE;
	b_nLength=FALSE;
	b_nMode=FALSE;
	b_nModel=FALSE;
	b_nOptions=FALSE;
	b_nPage=FALSE;
	b_nPort=FALSE;
	b_nRow=FALSE;
	b_nSettleTime=FALSE;
	b_nState=FALSE;
	b_nStatus=FALSE;
	b_nTimeout=FALSE;
	b_nType=FALSE;
	b_nWait=FALSE;
	b_nWidth=FALSE;
	b_nWindowState=FALSE;
	b_pOIAObject=FALSE;
	b_ScreenObj=FALSE;
	b_SessName=FALSE;
	b_settingsPage=FALSE;
	b_settingsTab=FALSE;
	b_sKeys=FALSE;
	b_Terminal=FALSE;

	b_rcAnyRow=FALSE;
	b_rcAnyCol=FALSE;
}