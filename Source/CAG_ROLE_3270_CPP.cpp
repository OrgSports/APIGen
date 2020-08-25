// Static Model
#include "stdafx.h"
#include "apigen.h"

#include "CAG_ROLE_3270_CPP.h"

CAG_ROLE_3270_CPP::CAG_ROLE_3270_CPP()
{
	resetVariableFlags();	
}

CAG_ROLE_3270_CPP::~CAG_ROLE_3270_CPP()
{
	
}


void CAG_ROLE_3270_CPP::generateHeader(CStringArray* pcsaHeader,
									   CStringArray* pcsaBody)
{

	CString csViewOutStuff;

	csViewOutStuff.Format( "//  ****************************************************************************");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "//                        Attachmate APIGen");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "//                    Reflection For 3270 C++ Program");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "// ");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "//  This file is a program that features the use of the Reflection for 3270");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "//  API written in C++.  This header is to include information");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "//  on how to set up the environment to run this application, how to build");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "//  it, and how to run it.");
	pcsaHeader->Add(csViewOutStuff);


	time_t ltime;
	time( &ltime );

	csViewOutStuff.Format( "//");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "//   Generated:   %s", ctime( &ltime ) );
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "//");
	pcsaHeader->Add(csViewOutStuff);


}
void CAG_ROLE_3270_CPP::appendBody(int nFunctionNum,
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
		case 0:		// AbortTransfer
		{
			csViewOutStuff.Format( "   someObj->AbortTransfer();" );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "" );
			pcsaBody->Add(csViewOutStuff);

		}
		break;

		case 3:		// AddHotListItem
		{
			csViewOutStuff.Format( "   someObj->AddHotListItem( \"%s\", \"%s\", \"%s\", %s );", 
												pcsaArguments->GetAt( 1 ),
												pcsaArguments->GetAt( 2 ),
												pcsaArguments->GetAt( 3 ),
												pcsaArguments->GetAt( 4 ) );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "" );
			pcsaBody->Add(csViewOutStuff);

		}
		break;


		case 1:		// AboutReflectionDlg
		case 2:		// ActivateCommandLine
		case 4:		// AddReference
		case 5:		// AddReferenceDlg
		case 6:		// AppendSelection
		case 7:		// AppendSQLStatement
		case 8:		// CancelSelection
		case 9:		// CancelTransfer
	
		case 10:	// CheckEvent			// 10
		case 11:	// CheckEventNumber
		case 12:	// ClearEvents
		case 13:	// ClearHotlists
		case 14:	// ClearHotspots
		case 15:	// ClearIBMPrinterFonts
		case 16:	// ClearMenu
		case 17:	// ClearNWSAA3270Config
		case 18:	// ClearSelection
		case 19:	// ClosePrinter

		case 20:	// CommitLoginProperties	// 20
		case 21:	// CompileScript
		case 22:	// Connect
		case 23:	// CopyPasteSettingsDialog
		case 24:	// CopySelection
		case 25:	// CopyTable
		case 26:	// CutSelection
		case 27:	// DDESetupDlg
		case 28:	// DefineEvent
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
		case 217:	// TransmitAnsi
		case 218:	// TransmitTerminalKey
		case 219:	// ViewSettingsDlg

		case 220:	// Wait
		case 221:	// WaitEvent
		case 222:	// WaitEventNumber
		case 223:	// WaitForCommString
		case 224:	// WaitForDisplayString
		case 225:	// WaitForEvent
		case 226:	// WaitForPrinterStatusString
		case 227:	// WaitForPrinterString
		case 228:	// WaitForPrinterStringReplace
		case 229:	// WaitForTerminalKey

		case 230:	// WaitForTimeOfDay
		case 231:	// WriteQuickText
		{
			csViewOutStuff.Format( "   // APIGen has not yet implemented this method." );
			pcsaBody->Add(csViewOutStuff);
		}
		break;

	}

	pcsaArguments->RemoveAll();
}


void CAG_ROLE_3270_CPP::finalize(CStringArray* pcsaBody)
{
	CString csViewOutStuff;

	csViewOutStuff.Format( " " );
	pcsaBody->Add(csViewOutStuff);

	csViewOutStuff.Format( "   return;");
	pcsaBody->Add(csViewOutStuff);

	csViewOutStuff.Format( "} " );
	pcsaBody->Add(csViewOutStuff);

}


void CAG_ROLE_3270_CPP::declareVariable(AG_VARIABLE agVariable,
										CStringArray* pcsaHeader,
										bool* bValue)
{
	
}

void CAG_ROLE_3270_CPP::checkDebug(bool b_Debug,
								   CString csFunctionName,
								   CStringArray* pcsaBody)
{
	
}

void CAG_ROLE_3270_CPP::resetVariableFlags()
{
}

