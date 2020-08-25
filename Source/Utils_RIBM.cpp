#include "stdafx.h"
#include "APIGen.h"
#include "APIGenDlg.h"

/****************************************************************************DC
	Function	:	CAPIGenDlg::LoadRIBM_OLEArgumentArray()

	Purpose		:	Load the function arguments for RWIN OLE Automation.

*****************************************************************************/
void CAPIGenDlg::LoadRIBM_OLEArgumentArray( int* nFunctionPosition, BOOL bPromptForValues )
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
			case 0:		// AbortTransfer
			case 1:		// AboutReflectionDlg
			case 2:		// ActivateCommandLinE
			case 5:		// AddReferenceDlg
			case 6:		// AppendSelection
			case 8:		// CancelSelection
			case 9:		// CancelTransfer
			case 10:	// CheckEvent
			case 12:	// ClearEvents
			case 13:	// ClearHotlists
			case 14:	// ClearHotspots
			case 15:	// ClearIBMPrinterFonts
			case 16:	// ClearMenu
			case 17:	// ClearNWSAA3270Config
			case 18:	// ClearSelection
			case 19:	// ClosePrinter
			case 22:	// Connect
			case 23:	// CopyPasteSettingsDialog
			case 24:	// CopySelection
			case 25:	// CopyTable
			case 26:	// CutSelection
			case 27:	// DDESetupDlg
			case 32:	// Disconnect
			case 33:	// DisplaySetupDlg
			case 36:	// EditScriptDlg
			case 39:	// Exit
			case 47:	// GetBufferedTermKey
			case 49:	// GetClipboardText
			case 52:	// GetCurrentHotspot
			case 53:	// GetCurrentHotspotEx
			case 57:	// GetFieldColor
			case 71:	// GetLastActiveInstance
			case 74:	// GetMyWindow
			case 75:	// GetNumHotlists
			case 76:	// GetNumHotspots
			case 85:	// GetVersionNumber
			case 88:	// HelpCursor
			case 89:	// HotlistSetupDlg
			case 90:	// HotspotSetupDlg
			case 94:	// InternalTraceDlg
			case 96:	// KeyboardMapSetupDlg
			case 98:	// MacrosDlg
			case 99:	// MenuSetupDlg
			case 100:	// MouseMapSetupDlg
			case 105:	// NewSessionDlg
			case 108:	// OnEventSetupDlg
			case 110:	// OpenSettingsDlg
			case 111:	// PageSetupDlg
			case 113:	// Paste
			case 114:	// PasteNext
			case 116:	// PasteRangeDlg
			case 120:	// PlayBackTraceDlg
			case 121:	// PlayNextTraceRecord
			case 122:	// PlayPreviousTraceRecord
			case 123:	// PreferenceSetupDlg
			case 126:	// PrintDlg
			case 129:	// PrintSetupDlg
			case 132:	// Quit
			case 134:	// RecordingSetupDlg
			case 135:	// RemoveAllToolbars
			case 142:	// ResetCommands
			case 148:	// RunScriptDlg
			case 150:	// SaveDisplayDlg
			case 152:	// SaveSettingsAsDlg
			case 153:	// SaveSettingsDlg
			case 155:	// SelectAll
			case 159:	// SendMailDlg
			case 160:	// SessionSetupDlg
			case 198:	// StartRecording
			case 200:	// StartTraceDlg
			case 201:	// StopInternalTrace
			case 202:	// StopMacro
			case 204:	// StopRecordingDlg
			case 206:	// StopScript
			case 207:	// StopTrace
			case 210:	// TerminalSetupDlg
			case 213:	// ToobarSetupDlg
			case 214:	// TransferDlg
			case 215:	// TransferSetupDlg
			case 219:	// ViewSettingsDlg
			{
			}
			break;

			// single argument
			case 4:		// AddReference
			case 11:	// CheckEventNumber
			case 139:	// RemoveOnEvent
			case 20:	// CommitLoginProperties
			case 21:	// CompileScript
			case 34:	// EditMacro
			case 35:	// EditScript
			case 41:	// ExtendSelectionLine
			case 42:	// ExtendSelectionPage
			case 44:	// ExtendSelectionWord
			case 48:	// GetButtonPictureFile
			case 50:	// GetCommandProfile
			case 51:	// GetCommandRecording
			case 55:	// GetErrorString
			case 217:	// TransmitAnsi
			case 62:	// GetHotlistName
			case 67:	// GetHotspots
			case 68:	// GetHotspotsEx
			case 138:	// RemoveNWSAA3270Config
			case 63:	// GetHotlistOptions
			case 77:	// GetNumItems
			case 82:	// GetSetProfile
			case 83:	// GetSetStringProfile
			case 84:	// GetSQLStatement
			case 87:	// Help
			case 95:	// IssuePrinterCommand
			case 104:	// NewSession
			case 106:	// NewToolbar
			case 140:	// RemoveToolbar
			case 125:	// PrintControl
			case 130:	// PrintString
			case 131:	// PrintTransparentChar
			case 136:	// RemoveEvent
			case 143:	// ResetEvent
			case 144:	// RestoreDefaults
			case 156:	// SelectLine
			case 162:	// SetClipboardText
			case 188:	// ShowDBCSHostCodeInputWindow
			case 197:	// StartInternalTrace
			case 208:	// SwitchToWindow
			case 212:	// Toggle
			case 220:	// Wait
			case 221:	// WaitEvent
			case 230:	// WaitForTimeOfDay
			case 231:	// WriteQuickText
			{
				Read1E( &csaArguments );
			}
			break;
			
			case 218:	// TransmitTerminalKey
			{
				Read1L( &csaArguments );
			}
			break;
			
			case 7:		// one listbox + one edit control
			{
				Read1L1E( &csaArguments );
			}
			break;

			case 127:	// PrintHostFile
			{
				Read1E1L1C( &csaArguments );
			}
			break;


			// one edit control + one listbox + three edit controls + one listbox
			case 28:	// DefineEvent
			{
				Read1E1L3E1L( &csaArguments );
			}
			break;


			// two edit control
			case 31:	// DeletePopupItem
			case 37:	// EnableInternalTrace
			case 38:	// EnableOnEvent
			case 40:	// ExtendSelection
			case 43:	// ExtendSelectionRect
			case 56:	// GetFieldAttributes
			case 97:	// LightPen
			case 101:	// MoveCursor
			case 157:	// SelectWord
			case 171:	// SetMousePos
			case 176:	// SetSelectionStartPos
			case 59:	// GetHotlistItem
			case 60:	// GetHotlistItemCommands
			case 61:	// GetHotlistItemOptions
			case 70:	// GetKeymap
			case 73:	// GetMouseMap
			case 81:	// GetScanCode
			case 102:	// MoveGraphicsCursor
			case 103:	// NewHotlist
			case 137:	// RemoveHotlist
			case 109:	// OpenSettings	
			case 112:	// PasswordBox
			case 117:	// PcsReceiveFile
			case 118:	// PcsSendFile
			case 119:	// PlayBackTrace
			case 124:	// Print
			case 128:	// PrintScreen
			case 141:	// RemoveToolbarButton
			case 146:	// RunMacro
			case 147:	// RunScript
			case 164:	// SetCommandProfile
			case 165:	// SetCommandRecording
			case 167:	// SetEncryptedString
			case 168:	// SetIBMPrinterFont
			case 172:	// SetNumeric
			case 173:	// SetNumericProfile
			case 179:	// SetStringProfile
			case 177:	// SetSQLStatement
			case 178:	// SetString
			case 181:	// SetTermKeyBuffer
			case 182:	// SetToolbarMode
			case 189:	// ShowDisplayAttribute
			case 191:	// ShowToolbar
			case 192:	// ShowToolbarButtonsFixedWidth
			case 193:	// ShowToolbarColor
			case 194:	// ShowToolbarLabels
			case 195:	// ShowToolbarLarge
			case 196:	// ShowToolbarTips
			case 211:	// TetherToolbar
			case 229:	// WaitForTerminalKey
			case 222:	// WaitEventNumber
			case 223:	// WaitForCommString
			case 226:	// WaitForPrinterStatusString
			case 227:	// WaitForPrinterString
			{
				Read2E( &csaArguments );
			}
			break;


			// three edit control
			case 54:	// GetDisplayText
			case 58:	// GetFieldText
			case 64:	// GetHotlistShowPosition
			case 86:	// GraphicsMouse
			case 133:	// ReadQuickTest
			case 145:	// RunExternalMacro
			case 151:	// SaveSettings
			case 161:	// SetAPLKeyMap
			case 163:	// SetColorMap
			case 166:	// SetDisplayAttribute
			case 169:	// SetKeyMap
			case 170:	// SetMouseMap
			case 174:	// SetRecentlyUsedFile
			case 175:	// SetScanCodeName
			case 184:	// SetupNWSAA3270Config
			case 185:	// SetupSession
			case 187:	// Shell
			case 199:	// StartTrace
			case 203:	// StopRecording
			case 205:	// StopRecordingMacro
			case 209:	// TerminalMouse
			case 216:	// TransformXML
			case 228:	// WaitForPrinterStringReplace
			{
				Read3E( &csaArguments );
			}
			break;


			case 3:		// AddHotListItem
			{
				Read3E1L( &csaArguments );
			}
			break;


			// four argument
			case 45:	// FindField
			case 46:	// FindText
			case 65:	// GetHotspotCommandsEx
			case 66:	// GetHotspotHelp
			case 69:	// GetHotspotTip
			case 72:	// GetLoginProperty
			case 78:	// GetOpenFilename
			case 154:	// SaveXML
			case 158:	// SendMail
			case 180:	// SetTerminalKbdPos
			case 186:	// SetWindowsPos
			case 224:	// WaitForDisplayString
			{
				Read4E( &csaArguments );
			}
			break;

			// five argument
			case 91:	// IndReceiveFile
			case 92:	// IndSendFile
			case 93:	// InsertPopupItem
			case 149:	// SaveDisplay
			case 183:	// SetToolbarPosition
			case 190:	// ShotHotlist
			case 225:	// WaitForEvent
			{
				Read5E( &csaArguments );
			}
			break;


			// seven argument
			case 29:	// DefineHotspotEx
			{
				// first argument
				csaArguments.Add( m_csEditArgument1 );

				// second argument
				csaArguments.Add( m_csEditArgument3 );

				// third argument
				csaArguments.Add( m_csEditArgument4 );

				// fourth argument
				csaArguments.Add( m_csEditArgument5 );

				// fifth argument
				csaArguments.Add( m_csEditArgument6 );

				// sixth argument
				csaArguments.Add( m_csEditArgument7 );

				// seventh argument
				csaArguments.Add( m_csEditArgument8 );

			}
			break;

			// eighth argument
			case 107:	// OnEvent

			{
				// first argument
				csaArguments.Add( m_csEditArgument1 );

				// second argument
				csaArguments.Add( m_csEditArgument3 );

				// third argument
				csaArguments.Add( m_csEditArgument4 );

				// fourth argument
				csaArguments.Add( m_csEditArgument5 );

				// fifth argument
				csaArguments.Add( m_csEditArgument6 );

				// sixth argument
				csaArguments.Add( m_csEditArgument7 );

				// seventh argument
				csaArguments.Add( m_csEditArgument8 );

				// eighth argument
				csaArguments.Add( m_csEditArgument9 );

			}
			break;

			
			// eleven argument
			case 30:	// DefineToolbarButton
			case 115:	// PasteRange

			{
				// first argument
				csaArguments.Add( m_csEditArgument1 );

				// second argument
				csaArguments.Add( m_csEditArgument3 );

				// third argument
				csaArguments.Add( m_csEditArgument4 );

				// fourth argument
				csaArguments.Add( m_csEditArgument5 );

				// fifth argument
				csaArguments.Add( m_csEditArgument6 );

				// sixth argument
				csaArguments.Add( m_csEditArgument7 );

				// seventh argument
				csaArguments.Add( m_csEditArgument8 );

				// eighth argument
				csaArguments.Add( m_csEditArgument9 );

				// ninth argument
				csaArguments.Add( m_csEditArgument10 );

				// tenth argument
				csaArguments.Add( m_csEditArgument11 );

				// eleventh argument
				csaArguments.Add( m_csEditArgument12 );

			}
			break;

		}
	}
	else
	{
		switch ( *nFunctionPosition )
		{
			case 0:		// AbortTransfer
			case 1:		// AboutReflectionDlg
			case 2:		// ActivateCommandLinE
			case 5:		// AddReferenceDlg
			case 6:		// AppendSelection
			case 8:		// CancelSelection
			case 9:		// CancelTransfer
			case 10:	// CheckEvent
			case 12:	// ClearEvents
			case 13:	// ClearHotlists
			case 14:	// ClearHotspots
			case 15:	// ClearIBMPrinterFonts
			case 16:	// ClearMenu
			case 17:	// ClearNWSAA3270Config
			case 18:	// ClearSelection
			case 19:	// ClosePrinter
			case 22:	// Connect
			case 23:	// CopyPasteSettingsDialog
			case 24:	// CopySelection
			case 25:	// CopyTable
			case 26:	// CutSelection
			case 27:	// DDESetupDlg
			case 32:	// Disconnect
			case 33:	// DisplaySetupDlg
			case 36:	// EditScriptDlg
			case 39:	// Exit
			case 47:	// GetBufferedTermKey
			case 49:	// GetClipboardText
			case 52:	// GetCurrentHotspot
			case 53:	// GetCurrentHotspotEx
			case 57:	// GetFieldColor
			case 71:	// GetLastActiveInstance
			case 74:	// GetMyWindow
			case 75:	// GetNumHotlists
			case 76:	// GetNumHotspots
			case 85:	// GetVersionNumber
			case 88:	// HelpCursor
			case 89:	// HotlistSetupDlg
			case 90:	// HotspotSetupDlg
			case 94:	// InternalTraceDlg
			case 96:	// KeyboardMapSetupDlg
			case 98:	// MacrosDlg
			case 99:	// MenuSetupDlg
			case 100:	// MouseMapSetupDlg
			case 105:	// NewSessionDlg
			case 108:	// OnEventSetupDlg
			case 110:	// OpenSettingsDlg
			case 111:	// PageSetupDlg
			case 113:	// Paste
			case 114:	// PasteNext
			case 116:	// PasteRangeDlg
			case 120:	// PlayBackTraceDlg
			case 121:	// PlayNextTraceRecord
			case 122:	// PlayPreviousTraceRecord
			case 123:	// PreferenceSetupDlg
			case 126:	// PrintDlg
			case 129:	// PrintSetupDlg
			case 132:	// Quit
			case 134:	// RecordingSetupDlg
			case 135:	// RemoveAllToolbars
			case 142:	// ResetCommands
			case 148:	// RunScriptDlg
			case 150:	// SaveDisplayDlg
			case 152:	// SaveSettingsAsDlg
			case 153:	// SaveSettingsDlg
			case 155:	// SelectAll
			case 159:	// SendMailDlg
			case 160:	// SessionSetupDlg
			case 198:	// StartRecording
			case 200:	// StartTraceDlg
			case 201:	// StopInternalTrace
			case 202:	// StopMacro
			case 204:	// StopRecordingDlg
			case 206:	// StopScript
			case 207:	// StopTrace
			case 210:	// TerminalSetupDlg
			case 213:	// ToobarSetupDlg
			case 214:	// TransferDlg
			case 215:	// TransferSetupDlg
			case 219:	// ViewSettingsDlg
			{
			}
			break;

			case 3:		// AddHotListItem	
			{
				// name
				csaArguments.Add( "Midwest" );
				// selection
				csaArguments.Add( "Indiana" );
				// command
				csaArguments.Add( "RunMacro" );
				// option
				csaArguments.Add( "rcNoOptions" );
			}
			break;


			case 4:		// AddReference
			{
				// name
				csaArguments.Add( "c:\\Mypath\\Shared Macros.rsf" );
			}
			break;
			
			case 7:		// AppendSQLStatement
			{
				// type
				csaArguments.Add( "rcAS400Select" );

				// statment
				csaArguments.Add( "Name = Johnson" );

			}
			break;

			case 11:	// CheckEventNumber
			case 139:	// RemoveOnEvent
			{
				// event
				csaArguments.Add( "rcDisconnectEvent" );
			}
			break;

			case 20:	// CommitLoginProperties
			{
				// script name
				csaArguments.Add( "Unused method" );
			}
			break;

			case 21:	// CompileScript
			{
				// script name
				csaArguments.Add( "c:\\scripts\\login.bas" );
			}
			break;


			case 28:	// DefineEvent
			{
				// event
				csaArguments.Add( "1, rcDisplayString, \\\"\\\", items(1), rcAnyRow, rcAnyCol, 1" );
			}
			break;

			case 29:	// DefineHotspotEx
			{
				// string
				csaArguments.Add( "1" );
				// flags
				csaArguments.Add( "rcMatchWhole" );
				// row
				csaArguments.Add( "17" );
				// column
				csaArguments.Add( "6" );
				// tip
				csaArguments.Add( "Transmit 1" );
				// help
				csaArguments.Add( "Transmit 1 followed by enter" );
				// commands
				csaArguments.Add( ".TransmitTerminalKey rcIBMEnterKey" );
			}
			break;

			case 30:	// DefineToolbarButton
			{
				// toolbar name
				csaArguments.Add( "standard" );
				// index
				csaArguments.Add( "3" );
				// separator
				csaArguments.Add( "TRUE" );
				// small picture file
				csaArguments.Add( "rcBmpWRQ" );
				// small picture index
				csaArguments.Add( "0" );
				// large picture file
				csaArguments.Add( "rcBmpWRQ" );
				// large picture index
				csaArguments.Add( "1" );
				// label
				csaArguments.Add( "Sample" );
				// tip
				csaArguments.Add( "About Reflection" );
				// help
				csaArguments.Add( "Display the About Reflection About Box" );
				// commands
				csaArguments.Add( "AboutReflectionDlg" );
			}
			break;

			case 31:	// DeletePopupItem
			{
				// popup
				csaArguments.Add( "2" );

				// item
				csaArguments.Add( "12" );
			}
			break;

			case 34:	// EditMacro
			{
				// macro
				csaArguments.Add( "helloWorld" );
			}
			break;

			case 35:	// EditScript
			{
				// script
				csaArguments.Add( "c:\\scripts\\helloWorld.vba" );
			}
			break;

			case 37:	// EnableInternalTrace
			{
				// trace node
				csaArguments.Add( "Deep" );

				// enable or disable
				csaArguments.Add( "rcEnable" );
			}
			break;

			case 38:	// EnableOnEvent
			{
				// event number
				csaArguments.Add( "rcAllEvents" );

				// enable or disable
				csaArguments.Add( "rcEnable" );
			}
			break;

			case 40:	// ExtendSelection
			case 43:	// ExtendSelectionRect
			case 56:	// GetFieldAttributes
			case 97:	// LightPen
			case 101:	// MoveCursor
			case 157:	// SelectWord
			case 171:	// SetMousePos
			case 176:	// SetSelectionStartPos
			{
				// row
				csaArguments.Add( "16" );

				// column
				csaArguments.Add( "7" );
			}
			break;


			case 41:	// ExtendSelectionLine
			case 42:	// ExtendSelectionPage
			case 44:	// ExtendSelectionWord
			{
				// direction
				csaArguments.Add( "rcForward" );
			}
			break;

			case 45:	// FindField
			{
				// row
				csaArguments.Add( "16" );

				// column
				csaArguments.Add( "7" );

				// type
				csaArguments.Add( "rcNext" );

				// attribute type
				csaArguments.Add( "rcUnprotected" );
			}
			break;

			case 46:	// FindText
			{
				// find string
				csaArguments.Add( "userid" );

				// row
				csaArguments.Add( "6" );

				// column
				csaArguments.Add( "2" );

				// attribute type
				csaArguments.Add( "rcNoTranslation" );
			}
			break;

			case 48:	// GetButtonPictureFile
			{
				// toolbar button index
				csaArguments.Add( "2" );
			}
			break;

			case 50:	// GetCommandProfile
			case 51:	// GetCommandRecording
			{
				// command
				csaArguments.Add( "Connect" );
			}
			break;

			case 54:	// GetDisplayText
			case 58:	// GetFieldText
			{
				// row
				csaArguments.Add( "6" );

				// column
				csaArguments.Add( "2" );

				// number of chars returned
				csaArguments.Add( "8" );
			}
			break;

			case 55:	// GetErrorString
			case 217:	// TransmitAnsi
			{
				// error number
				csaArguments.Add( "137" );
			}
			break;

			case 218:	// TransmitTerminalKey
			{
				// error number
				csaArguments.Add( "rcIbmEnterKey" );
			}
			break;

			case 59:	// GetHotlistItem
			{
				// name
				csaArguments.Add( "HotlistA" );

				// index
				csaArguments.Add( "1" );
			}
			break;

			case 60:	// GetHotlistItemCommands
			case 61:	// GetHotlistItemOptions
			{
				// list
				csaArguments.Add( "HotlistA" );

				// item name
				csaArguments.Add( "Purpose" );
			}
			break;

			case 62:	// GetHotlistName
			case 67:	// GetHotspots
			case 68:	// GetHotspotsEx
			case 138:	// RemoveNWSAA3270Config
			{
				// item index
				csaArguments.Add( "3" );
			}
			break;

			case 63:	// GetHotlistOptions
			case 77:	// GetNumItems
			{
				// hostlist name
				csaArguments.Add( "HostlistB" );
			}
			break;

			case 64:	// GetHotlistShowPosition
			{
				// name
				csaArguments.Add( "HotlistC" );

				// item name
				csaArguments.Add( "0" );

				// item name
				csaArguments.Add( "0" );

			}
			break;

			case 65:	// GetHotspotCommandsEx
			case 66:	// GetHotspotHelp
			case 69:	// GetHotspotTip
			{
				// name
				csaArguments.Add( "HotSpot2" );

				// flags
				csaArguments.Add( "rcMatchWhole" );

				// row
				csaArguments.Add( "6" );

				// column
				csaArguments.Add( "2" );

			}
			break;

			case 70:	// GetKeymap
			{
				// modifiers
				csaArguments.Add( "rcNormal" );

				// key or chord
				csaArguments.Add( "F1" );
			}
			break;

			case 72:	// GetLoginProperty
			{
				// property
				csaArguments.Add( "xyz" );

				// host user name
				csaArguments.Add( "RufusTFirefly" );

				// host name
				csaArguments.Add( "Virginia" );

				// options
				csaArguments.Add( "optionX" );
			}
			break;

			case 73:	// GetMouseMap
			{
				// modifiers
				csaArguments.Add( "rcNormal" );

				// key or chord
				csaArguments.Add( "LeftBtn" );
			}
			break;

			case 78:	// GetOpenFilename
			{
				// file filter
				csaArguments.Add( "Text Files (*.txt),*.txt,Bitmaps (*.bmo),*.bmp" );

				// filter index
				csaArguments.Add( "1" );

				// title
				csaArguments.Add( "Open file" );

				// button text
				csaArguments.Add( "Open" );
			}
			break;

			case 81:	// GetScanCode
			{
				// scan type
				csaArguments.Add( "rcExtended" );

				// scan code
				csaArguments.Add( "34" );
			}
			break;

			case 82:	// GetSetProfile
			{
				// setting name
				csaArguments.Add( "rcFrameTerminalWindow" );
			}
			break;
			
			case 83:	// GetSetStringProfile
			{
				// setting name
				csaArguments.Add( "rcHostsFile " );
			}
			break;

			case 84:	// GetSQLStatement
			{
				// type
				csaArguments.Add( "rcAS400Select" );
			}
			break;

			case 86:	// GraphicsMouse
			{
				// type
				csaArguments.Add( "rcLeftClick" );

				// x coordinate
				csaArguments.Add( "rcCurrentGraphicsCursorX" );

				// y coordinate
				csaArguments.Add( "rcCurrentGraphicsCursorY" );
			}
			break;

			case 87:	// Help
			{
				// type
				csaArguments.Add( "rcHelpSearchForTopic" );
			}
			break;

			case 91:	// IndReceiveFile
			case 92:	// IndSendFile
			{
				// local file
				csaArguments.Add( "c:\\filestore\\datafile.txt" );

				// host file
				csaArguments.Add( "datafile txt" );

				// type
				csaArguments.Add( "rcXfrASCII" );

				// exists option
				csaArguments.Add( "rcAskUser" );

				// show status
				csaArguments.Add( "-1" );

			}
			break;

			case 93:	// InsertPopupItem
			{
				// item type
				csaArguments.Add( "rcHelpTopicsItem" );

				// popup
				csaArguments.Add( "rcMainMenu" );

				// item
				csaArguments.Add( "rcLastItem" );

				// name
				csaArguments.Add( "Connection patterns" );

				// description
				csaArguments.Add( "Connect" );

			}
			break;

			case 95:	// IssuePrinterCommand
			{
				// printer command
				csaArguments.Add( "rcFlushPrint" );
			}
			break;

			case 102:	// MoveGraphicsCursor
			{
				// x position
				csaArguments.Add( "60" );

				// y position
				csaArguments.Add( "201" );
			}
			break;

			case 103:	// NewHotlist
			case 137:	// RemoveHotlist
			{
				// name
				csaArguments.Add( "Hostlist2" );

				// options
				csaArguments.Add( "rcSort" );
			}
			break;

			case 104:	// NewSession
			{
				// file name
				csaArguments.Add( "c:\\session1.ref" );
			}
			break;

			case 106:	// NewToolbar
			case 140:	// RemoveToolbar
			{
				// toobar name
				csaArguments.Add( "Toolbar16" );
			}
			break;

			case 107:	// OnEvent
			{
				// event number
				csaArguments.Add( "16" );

				// event
				csaArguments.Add( "rcDisplayString" );

				// commands
				csaArguments.Add( "Connect" );

				// enable
				csaArguments.Add( "rcEnable" );

				// after event
				csaArguments.Add( "rcEventReenable" );

				// string
				csaArguments.Add( "Bologna" );

				// row
				csaArguments.Add( "2" );

				// column
				csaArguments.Add( "64" );

			}
			break;

			case 109:	// OpenSettings	
			{
				// settings type
				csaArguments.Add( "rcColors" );

				// file name
				csaArguments.Add( "RColors.col" );
			}
			break;

			case 112:	// PasswordBox
			{
				// prompt
				csaArguments.Add( "Please enter your password" );

				// title
				csaArguments.Add( "Access credentials" );
			}
			break;

			case 115:	// PasteRange
			{
				// top
				csaArguments.Add( "1" );

				// left
				csaArguments.Add( "1" );

				// bottom
				csaArguments.Add( "0" );

				// right
				csaArguments.Add( "0" );

				// rem top
				csaArguments.Add( "1" );

				// rem left
				csaArguments.Add( "1" );

				// rem bottom
				csaArguments.Add( "0" );

				// rem right
				csaArguments.Add( "0" );

				// key
				csaArguments.Add( "rcIBMPF8Key" );

				// wrap text
				csaArguments.Add( "rcYes" );

				// use field delimiter
				csaArguments.Add( "rcNo" );


			}
			break;

			case 117:	// PcsReceiveFile
			case 118:	// PcsSendFile
			{
				// transfer file
				csaArguments.Add( "c:\\datafiles\\data132.txt" );

				// show status
				csaArguments.Add( "0" );
			}
			break;

			case 119:	// PlayBackTrace
			{
				// type
				csaArguments.Add( "rcCommands" );

				// file name
				csaArguments.Add( "c:\\datafiles\\trace080705a.cmd" );
				
			}
			break;

			case 124:	// Print
			case 128:	// PrintScreen
			{
				// item
				csaArguments.Add( "rcPrintScreen" );

				// copies
				csaArguments.Add( "1" );
				
			}
			break;

			case 125:	// PrintControl
			{
				// print control
				csaArguments.Add( "rcPrintFF" );
				
			}
			break;

			case 127:	// PrintHostFile
			{
				// host file
				csaArguments.Add( "data bin" );

				// type
				csaArguments.Add( "rcXfrBinary" );

				// carriage control
				csaArguments.Add( "FALSE" );
			}
			break;

			case 130:	// PrintString
			{
				// string to print
				csaArguments.Add( "Have a nice day!" );
			}
			break;

			case 131:	// PrintTransparentChar
			{
				// ascii char code
				csaArguments.Add( "Asc(\"1\")" );
			}
			break;

			case 133:	// ReadQuickTest
			{
				// row
				csaArguments.Add( "1" );

				// column
				csaArguments.Add( "1" );

				// read option
				csaArguments.Add( "rcBestForSessionType" );
			}
			break;

			case 136:	// RemoveEvent
			case 143:	// ResetEvent
			{
				// event
				csaArguments.Add( "101" );
			}
			break;

			case 141:	// RemoveToolbarButton
			{
				// toolbar name
				csaArguments.Add( "Filetransfer" );
		
				// event
				csaArguments.Add( "1" );
			}
			break;

			case 144:	// RestoreDefaults
			{
				// settings type
				csaArguments.Add( "rcKeyMap" );
			}
			break;

			case 145:	// RunExternalMacro
			{
				// file name
				csaArguments.Add( "C:\\Mypath\\Myfile.rsf" );

				// macro name
				csaArguments.Add( "Myfile.ThisSession.MyMacro" );

				// macro data
				csaArguments.Add( " " );
			}
			break;

			case 146:	// RunMacro
			{
				// macro name
				csaArguments.Add( "Myfile.ThisSession.MyMacro" );

				// macro data
				csaArguments.Add( " " );
			}
			break;

			case 147:	// RunScript
			{
				// script name
				csaArguments.Add( "C:\\Mypath\\Myscript.rbs" );

				//	arguments
				csaArguments.Add( "-f" );
			}
			break;

			case 149:	// SaveDisplay
			{
				// layering option
				csaArguments.Add( "rcTextOnly" );

				// exist option
				csaArguments.Add( "rcOverwrite" );

				// filename
				csaArguments.Add( "C:\\Mypath\\Myfile.dis" );
				
				// color type
				csaArguments.Add( "rcBitmapColor" );

				// background
				csaArguments.Add( "rcBlackBkgrnd" );

			}
			break;

			case 151:	// SaveSettings
			{
				// type
				csaArguments.Add( "rcSettings" );

				// exist option
				csaArguments.Add( "rcOverwrite" );

				// filename
				csaArguments.Add( "C:\\Mypath\\session1.rsf" );
			}
			break;

			case 154:	// SaveXML
			{
				// filename
				csaArguments.Add( "c:\\settings\\session1.xml" );

				// XML type
				csaArguments.Add( "rcXMLProperties" );

				// exist option
				csaArguments.Add( "rcOverwrite" );

				// option
				csaArguments.Add( "rcAll" );

			}
			break;

			case 156:	// SelectLine
			{
				// line number
				csaArguments.Add( "rcMouseRow" );
			}
			break;

			case 158:	// SendMail
			{
				// recipient
				csaArguments.Add( "support@attachmate.com" );

				// subject
				csaArguments.Add( "Technical Question" );

				// content type
				csaArguments.Add( "rcSendText" );

				// content
				csaArguments.Add( "I'm getting a 510 when I click on my left mouse button." );

			}
			break;

			case 161:	// SetAPLKeyMap
			{
				// controls
				csaArguments.Add( "rcAltCtrlShift" );

				// key
				csaArguments.Add( "Equals" );

				// command
				csaArguments.Add( "TransmitAnsi \"Hello\" TransmitTerminalKey rcIBMEnterKey" );
			}
			break;

			case 162:	// SetClipboardText
			{
				// text
				csaArguments.Add( "The quick brown fox jumps over the lazy dog." );
			}
			break;

			case 163:	// SetColorMap
			{
				// attribute
				csaArguments.Add( "rcHostTurquoise" );

				// foreground
				csaArguments.Add( "rcWhite" );

				// background
				csaArguments.Add( "rcBlack" );

			}
			break;

			case 164:	// SetCommandProfile
			case 165:	// SetCommandRecording
			{
				// command name
				csaArguments.Add( "rcCmd" );

				// enable flag
				csaArguments.Add( "rcEnable" );

			}
			break;

			case 166:	// SetDisplayAttribute
			{
				// attribute index
				csaArguments.Add( "0x20" );

				// attribute type
				csaArguments.Add( "rcAttrUnderline" );

				// attribute value
				csaArguments.Add( "rcYes" );

			}
			break;

			case 167:	// SetEncryptedString
			{
				// encrypted setting
				csaArguments.Add( "rcPassword" );

				// string
				csaArguments.Add( "Make this unreadable" );

			}
			break;

			case 168:	// SetIBMPrinterFont
			{
				// font ID
				csaArguments.Add( "11" );

				// font description
				csaArguments.Add( " " );

			}
			break;

			case 169:	// SetKeyMap
			{
				// controls
				csaArguments.Add( "rcNormal" );

				// key
				csaArguments.Add( "t" );

				// commands
				csaArguments.Add( "TransmitTerminalKey rcIbmEnterKey" );

			}
			break;

			case 170:	// SetMouseMap
			{
				// controls
				csaArguments.Add( "rcNormal" );

				// chord
				csaArguments.Add( "MiddleBtn" );

				// commands
				csaArguments.Add( "TransmitTerminalKey rcIbmEnterKey" );

			}
			break;

			case 172:	// SetNumeric
			{
				// setting
				csaArguments.Add( "rcToolBarVisible" );

				// value
				csaArguments.Add( "rcYes" );

			}
			break;

			case 173:	// SetNumericProfile
			case 179:	// SetStringProfile
			{
				// setting
				csaArguments.Add( "rcFrameTerminalWindow" );

				// enable flag
				csaArguments.Add( "rcEnable" );

			}
			break;

			case 174:	// SetRecentlyUsedFile
			{
				// title
				csaArguments.Add( "Marketing" );

				// description
				csaArguments.Add( "Marketing Dept. session" );

				// commands
				csaArguments.Add( "Connect" );

			}
			break;

			case 175:	// SetScanCodeName
			{
				// scan type
				csaArguments.Add( "rcNormal" );

				// scan code
				csaArguments.Add( "32h" );

				// key
				csaArguments.Add( "g" );

			}
			break;

			case 177:	// SetSQLStatement
			{
				// type
				csaArguments.Add( "rcAS400Select" );

				// statement
				csaArguments.Add( "Name" );

			}
			break;

			case 178:	// SetString
			{
				// setting
				csaArguments.Add( "rcHostName" );

				// string
				csaArguments.Add( "Rainier" );

			}
			break;

			case 180:	// SetTerminalKbdPos
			case 186:	// SetWindowsPos
			{
				// left
				csaArguments.Add( "50" );

				// top
				csaArguments.Add( "10" );

				// width
				csaArguments.Add( "200" );

				// height
				csaArguments.Add( "48" );

			}
			break;

			case 181:	// SetTermKeyBuffer
			{
				// size
				csaArguments.Add( "1920" );

				// overflow
				csaArguments.Add( "rcOverflowIgnore" );

			}
			break;

			case 182:	// SetToolbarMode
			{
				// toolbar name
				csaArguments.Add( "File Transfer" );

				// mode
				csaArguments.Add( "rcFloating" );

			}
			break;

			case 183:	// SetToolbarPosition
			{
				// toolbar name
				csaArguments.Add( "File Transfer" );

				// left
				csaArguments.Add( "50" );

				// top
				csaArguments.Add( "10" );

				// width
				csaArguments.Add( "200" );

				// height
				csaArguments.Add( "48" );

			}
			break;

			case 184:	// SetupNWSAA3270Config
			{
				// server
				csaArguments.Add( "BASS" );

				// service
				csaArguments.Add( "comm1" );

				// LU
				csaArguments.Add( "T1322" );

			}
			break;

			case 185:	// SetupSession
			{
				// session type
				csaArguments.Add( "rc3270Printer" );

				// terminal model
				csaArguments.Add( "rc3287Printer" );

				// transport type
				csaArguments.Add( "rcTelnetExtended" );

			}
			break;

			case 187:	// Shell
			{
				// command string
				csaArguments.Add( "notepad.exe" );

				// argument string
				csaArguments.Add( "-l" );

				// window state
				csaArguments.Add( "rcNormal" );

			}
			break;

			case 188:	// ShowDBCSHostCodeInputWindow
			{
				// host code
				csaArguments.Add( "rcDecimalCode" );
			}
			break;

			case 189:	// ShowDisplayAttribute
			{
				// attribute
				csaArguments.Add( "rcAttrColumnSep" );

				// enable
				csaArguments.Add( "-1" );

			}
			break;

			case 190:	// ShotHotlist
			{
				// name
				csaArguments.Add( "List23" );

				// row
				csaArguments.Add( "50" );

				// column
				csaArguments.Add( "2" );

				// reserved
				csaArguments.Add( "0" );

				// length
				csaArguments.Add( "8" );

			}
			break;

			case 191:	// ShowToolbar
			case 192:	// ShowToolbarButtonsFixedWidth
			case 193:	// ShowToolbarColor
			case 194:	// ShowToolbarLabels
			case 195:	// ShowToolbarLarge
			case 196:	// ShowToolbarTips
			case 211:	// TetherToolbar
			{
				// name
				csaArguments.Add( "Standard" );

				// yes/no
				csaArguments.Add( "rcYes" );

			}
			break;

			case 197:	// StartInternalTrace
			{
				// file name
				csaArguments.Add( "c:\\traces\\trace080705.trc" );
			}
			break;

			case 199:	// StartTrace
			{
				// file type
				csaArguments.Add( "rcDataFromHost" );

				// if file exists
				csaArguments.Add( "rcOpenError" );

				// file name
				csaArguments.Add( "c:\\traces\\trace080705.trc" );

			}
			break;

			case 203:	// StopRecording
			{
				// destination
				csaArguments.Add( "rcVBSource" );

				// exists option
				csaArguments.Add( "rcOpenError" );

				// file name
				csaArguments.Add( "c:\\traces\\trace080705.vb" );

			}
			break;

			case 205:	// StopRecordingMacro
			{
				// destination
				csaArguments.Add( "rcMacro" );

				// name
				csaArguments.Add( "Macro787" );

				// description
				csaArguments.Add( "End of day backup file transfers." );

			}
			break;

			case 208:	// SwitchToWindow
			{
				// number
				csaArguments.Add( "rcNextWindow" );
			}
			break;

			case 209:	// TerminalMouse
			{
				// action
				csaArguments.Add( "rcLeftDblClick" );

				// row
				csaArguments.Add( "20" );

				// column
				csaArguments.Add( "17" );

			}
			break;

			case 212:	// Toggle
			{
				// setting
				csaArguments.Add( "rcFrameTerminalWindow " );
			}
			break;



			case 216:	// TransformXML
			{
				// input file
				csaArguments.Add( "c:\\transforms\\trans080705.xml" );

				// transform file
				csaArguments.Add( "c:\\transforms\\trans080705.xsl" );

				// output file
				csaArguments.Add( "c:\\transforms\\endofday080705.xml" );

			}
			break;

			case 229:	// WaitForTerminalKey
			{
				// key
				csaArguments.Add( "rcIbmAu5Key" );

				// timeout
				csaArguments.Add( "0:0:30" );
			}
			break;

			case 220:	// Wait
			{
				// time
				csaArguments.Add( "4" );
			}
			break;

			case 221:	// WaitEvent
			case 230:	// WaitForTimeOfDay
			{
				// timeout
				csaArguments.Add( "01:06:30" );
			}
			break;

			case 222:	// WaitEventNumber
			{
				// event
				csaArguments.Add( "1" );

				// timeout
				csaArguments.Add( "12" );
			}
			break;

			case 223:	// WaitForCommString
			{
				// comm string
				csaArguments.Add( "Username" );

				// timeout
				csaArguments.Add( "0:0:30" );
			}
			break;

			case 224:	// WaitForDisplayString
			{
				// display string
				csaArguments.Add( "Username" );

				// timeout
				csaArguments.Add( "0:0:30" );

				// row
				csaArguments.Add( "2" );

				// column
				csaArguments.Add( "41" );

			}
			break;

			case 225:	// WaitForEvent
			{
				// event type
				csaArguments.Add( "rcEvConnected" );

				// timeout
				csaArguments.Add( "0:0:30" );

				// duration
				csaArguments.Add( "0:0:03" );

				// row
				csaArguments.Add( "2" );

				// column
				csaArguments.Add( "41" );

			}
			break;

			case 226:	// WaitForPrinterStatusString
			case 227:	// WaitForPrinterString
			{
				// status string
				csaArguments.Add( "Printer Error" );

				// timeout
				csaArguments.Add( "0:0:03" );
			}
			break;

			case 228:	// WaitForPrinterStringReplace
			{
				// status string
				csaArguments.Add( "XYZ" );

				// timeout
				csaArguments.Add( "0:0:03" );

				// column
				csaArguments.Add( "1" );

			}
			break;

			case 231:	// WriteQuickText
			{
				// key
				csaArguments.Add( "rcIBMPF8Key" );
			}
			break;

		}

	}
}




/****************************************************************************DC
	Function	:	CAPIGenDlg::ShowRIBMControls()

	Purpose		:	Show the controls for the Extra! OLE Automation 
					function parameters.

*****************************************************************************/
void CAPIGenDlg::ShowRIBMControls( int nFunction )
{
	HideParameterControls();
	csaLabels.RemoveAll();
	BOOL bYouShouldGo=TRUE;

	switch ( nFunction )
	{
		case 0:		// AbortTransfer
		case 1:		// AboutReflectionDlg
		case 2:		// ActivateCommandLinE

		case 5:		// AddReferenceDlg
		case 6:		// AppendSelection

		case 8:		// CancelSelection
		case 9:		// CancelTransfer
		case 10:	// CheckEvent

		case 12:	// ClearEvents
		case 13:	// ClearHotlists
		case 14:	// ClearHotspots
		case 15:	// ClearIBMPrinterFonts
		case 16:	// ClearMenu
		case 17:	// ClearNWSAA3270Config
		case 18:	// ClearSelection
		case 19:	// ClosePrinter
		case 20:	// CommitLoginProperties
		case 22:	// Connect
		case 23:	// CopyPasteSettingsDialog
		case 24:	// CopySelection
		case 25:	// CopyTable
		case 26:	// CutSelection
		case 27:	// DDESetupDlg

		case 32:	// Disconnect
		case 33:	// DisplaySetupDlg

		case 36:	// EditScriptDlg

		case 39:	// Exit

		case 47:	// GetBufferedTermKey

		case 49:	// GetClipboardText

		case 52:	// GetCurrentHotspot
		case 53:	// GetCurrentHotspotEx

		case 57:	// GetFieldColor

		case 71:	// GetLastActiveInstance

		case 74:	// GetMyWindow
		case 75:	// GetNumHotlists
		case 76:	// GetNumHotspots

		case 85:	// GetVersionNumber

		case 88:	// HelpCursor
		case 89:	// HotlistSetupDlg
		case 90:	// HotspotSetupDlg

		case 94:	// InternalTraceDlg

		case 96:	// KeyboardMapSetupDlg

		case 98:	// MacrosDlg
		case 99:	// MenuSetupDlg
		case 100:	// MouseMapSetupDlg

		case 105:	// NewSessionDlg

		case 108:	// OnEventSetupDlg

		case 110:	// OpenSettingsDlg
		case 111:	// PageSetupDlg

		case 113:	// Paste
		case 114:	// PasteNext

		case 116:	// PasteRangeDlg

		case 120:	// PlayBackTraceDlg
		case 121:	// PlayNextTraceRecord
		case 122:	// PlayPreviousTraceRecord
		case 123:	// PreferenceSetupDlg

		case 126:	// PrintDlg

		case 129:	// PrintSetupDlg

		case 132:	// Quit

		case 134:	// RecordingSetupDlg
		case 135:	// RemoveAllToolbars

		case 142:	// ResetCommands

		case 148:	// RunScriptDlg

		case 150:	// SaveDisplayDlg

		case 152:	// SaveSettingsAsDlg
		case 153:	// SaveSettingsDlg

		case 155:	// SelectAll

		case 159:	// SendMailDlg
		case 160:	// SessionSetupDlg

		case 198:	// StartRecording

		case 200:	// StartTraceDlg
		case 201:	// StopInternalTrace
		case 202:	// StopMacro

		case 204:	// StopRecordingDlg

		case 206:	// StopScript
		case 207:	// StopTrace

		case 210:	// TerminalSetupDlg

		case 213:	// ToobarSetupDlg
		case 214:	// TransferDlg
		case 215:	// TransferSetupDlg

		case 219:	// ViewSettingsDlg
		{
		}
		break;


		case 3:		// AddHotListItem
		{
			csaLabels.Add("Name");
			csaLabels.Add("Selection string");
			csaLabels.Add("Reflection command(s)");
			csaLabels.Add("Option");
			bYouShouldGo=FALSE;
		}
		break;

		case 4:		// AddReference
		{
			csaLabels.Add("Project file (.rsf)");
			bYouShouldGo=FALSE;
		}
		break;

		case 7:		// AppendSQLStatement
		{
			csaLabels.Add("Type");
			csaLabels.Add("Statement");
			bYouShouldGo=FALSE;
		}
		break;

		case 11:	// CheckEventNumber
		{
			csaLabels.Add("Event number");
		}
		break;

		case 21:	// CompileScript
		{
			csaLabels.Add("Reflection Basic script");
			bYouShouldGo=FALSE;
		}
		break;

		case 28:	// DefineEvent
		{
			csaLabels.Add("Event number");
			csaLabels.Add("Event type");
			csaLabels.Add("Event string");
			csaLabels.Add("Row");
			csaLabels.Add("Column");
			csaLabels.Add("Key");
			bYouShouldGo=FALSE;
		}
		break;

		case 29:	// DefineHotspotEx
		{
			csaLabels.Add("String");
			csaLabels.Add("Flags");
			csaLabels.Add("Row");
			csaLabels.Add("Column");
			csaLabels.Add("Tip");
			csaLabels.Add("Help");
			csaLabels.Add("Commands");
		}
		break;

		case 30:	// DefineToolbarButton
		{
			csaLabels.Add("Toolbar name");
			csaLabels.Add("Index");
			csaLabels.Add("Separator");
			csaLabels.Add("Small picture file");
			csaLabels.Add("Small picture index");
			csaLabels.Add("Large picture file");
			csaLabels.Add("Large picture index");
			csaLabels.Add("Label");
			csaLabels.Add("Tip");
			csaLabels.Add("Help");
			csaLabels.Add("Commands");
		}
		break;

		case 31:	// DeletePopupItem
		{
			csaLabels.Add("Popup");
			csaLabels.Add("Item");
		}
		break;

		case 34:	// EditMacro
		{
			csaLabels.Add("Macro");
		}
		break;

		case 35:	// EditScript
		{
			csaLabels.Add("Script file");
		}
		break;

		case 37:	// EnableInternalTrace
		{
			csaLabels.Add("Trace node");
			csaLabels.Add("Enable (True/False)");
		}
		break;

		case 38:	// EnableOnEvent
		{
			csaLabels.Add("Event number");
			csaLabels.Add("Enable (True/False)");
		}
		break;

		case 40:	// ExtendSelection
		case 43:	// ExtendSelectionRect
		case 56:	// GetFieldAttributes
		{
			csaLabels.Add("Row");
			csaLabels.Add("Column");
		}
		break;

		case 41:	// ExtendSelectionLine
		case 42:	// ExtendSelectionPage
		case 44:	// ExtendSelectionWord
		{
			csaLabels.Add("Direction");
		}
		break;

		case 45:	// FindField
		{
			csaLabels.Add("Row");
			csaLabels.Add("Column");
			csaLabels.Add("Find type");
			csaLabels.Add("Find attribute");
		}
		break;

		case 46:	// FindText
		{
			csaLabels.Add("Search for");
			csaLabels.Add("Start row");
			csaLabels.Add("Start column");
			csaLabels.Add("Options");
		}
		break;

		case 48:	// GetButtonPictureFile
		{
			csaLabels.Add("Index");
		}
		break;

		case 50:	// GetCommandProfile
		case 51:	// GetCommandRecording
		{
			csaLabels.Add("Command");
		}
		break;

		case 54:	// GetDisplayText
		case 58:	// GetFieldText
		{
			csaLabels.Add("Row");
			csaLabels.Add("Column");
			csaLabels.Add("Chars");
		}
		break;

		case 55:	// GetErrorString
		{
			csaLabels.Add("Error number");
		}
		break;

		case 59:	// GetHotlistItem
		{
			csaLabels.Add("Name");
			csaLabels.Add("Index");
		}
		break;

		case 60:	// GetHotlistItemCommands
		case 61:	// GetHotlistItemOptions
		{
			csaLabels.Add("List");
			csaLabels.Add("Item");
		}
		break;

		case 62:	// GetHotlistName
		case 67:	// GetHotspots
		case 68:	// GetHotspotsEx
		{
			csaLabels.Add("Index");
		}
		break;

		case 63:	// GetHotlistOptions
		case 64:	// GetHotlistShowPosition
		{
			csaLabels.Add("Name");
		}
		break;

		case 65:	// GetHotspotCommandsEx
		case 66:	// GetHotspotHelp
		case 69:	// GetHotspotTip
		{
			csaLabels.Add("Name");
			csaLabels.Add("Flags");
			csaLabels.Add("Row");
			csaLabels.Add("Column");
		}
		break;

		case 70:	// GetKeymap
		case 73:	// GetMouseMap
		{
			csaLabels.Add("Modifiers");
			csaLabels.Add("Key or chord");
		}
		break;

		case 72:	// GetLoginProperty
		{
			csaLabels.Add("Property");
			csaLabels.Add("Host username");
			csaLabels.Add("Host name");
			csaLabels.Add("Options");
		}
		break;

		case 77:	// GetNumItems
		{
			csaLabels.Add("List");
		}
		break;

		case 78:	// GetOpenFilename
		{
			csaLabels.Add("File filter");
			csaLabels.Add("Filter index");
			csaLabels.Add("Title");
			csaLabels.Add("Button text");
		}
		break;

		case 79:	// GetPassword
		{
			csaLabels.Add("Prompt");
			csaLabels.Add("Host username");
			csaLabels.Add("Host name");
			csaLabels.Add("Options");
		}
		break;

		case 80:	// GetSaveAsFilename
		{
			csaLabels.Add("Initial filename");
			csaLabels.Add("File filter");
			csaLabels.Add("Filter index");
			csaLabels.Add("Title");
			csaLabels.Add("Button text");
		}
		break;

		case 81:	// GetScanCode
		{
			csaLabels.Add("Scan type");
			csaLabels.Add("Scan code");
		}
		break;

		case 82:	// GetSetProfile
		case 83:	// GetSetStringProfile
		{
			csaLabels.Add("Setting name");
		}
		break;

		case 84:	// GetSQLStatement
		{
			csaLabels.Add("Type");
		}
		break;

		case 86:	// GraphicsMouse
		{
			csaLabels.Add("Type");
			csaLabels.Add("X-coordinate");
			csaLabels.Add("Y-coordinate");
		}
		break;

		case 87:	// Help
		{
			csaLabels.Add("Topic");
		}
		break;

		case 91:	// IndReceiveFile
		case 92:	// IndSendFile
		{
			csaLabels.Add("Local file");
			csaLabels.Add("Host file");
			csaLabels.Add("Type");
			csaLabels.Add("Exists option");
			csaLabels.Add("Show status (Y/N)");
		}
		break;


		case 93:	// InsertPopupItem
		{
			csaLabels.Add("Item type");
			csaLabels.Add("Popup");
			csaLabels.Add("Item");
			csaLabels.Add("Name");
			csaLabels.Add("Description");
			csaLabels.Add("Commands");
		}
		break;

		case 95:	// IssuePrinterCommand
		{
			csaLabels.Add("Printer command");
		}
		break;

		case 97:	// LightPen
		case 101:	// MoveCursor
		case 157:	// SelectWord
		case 171:	// SetMousePos
		case 176:	// SetSelectionStartPos
		{
			csaLabels.Add("Row");
			csaLabels.Add("Column");
		}
		break;

		case 102:	// MoveGraphicsCursor
		{
			csaLabels.Add("X-coordinate");
			csaLabels.Add("Y-coordinate");
		}
		break;

		case 103:	// NewHotlist
		{
			csaLabels.Add("Name");
			csaLabels.Add("Options");
		}
		break;

		case 104:	// NewSession
		case 197:	// StartInternalTrace
		{
			csaLabels.Add("Filename");
		}
		break;

		case 106:	// NewToolbar
		case 140:	// RemoveToolbar
		{
			csaLabels.Add("Name");
		}
		break;

		case 107:	// OnEvent
		{
			csaLabels.Add("Event number");
			csaLabels.Add("Event");
			csaLabels.Add("Commands");
			csaLabels.Add("Enable");
			csaLabels.Add("After event");
			csaLabels.Add("String");
			csaLabels.Add("Row");
			csaLabels.Add("Column");
		}
		break;

		case 109:	// OpenSettings	
		{
			csaLabels.Add("Settings type");
			csaLabels.Add("Filename");
		}
		break;

		case 112:	// PasswordBox
		{
			csaLabels.Add("Prompt");
			csaLabels.Add("Title");
		}
		break;

		case 115:	// PasteRange
		{
			csaLabels.Add("Top");
			csaLabels.Add("Left");
			csaLabels.Add("Bottom");
			csaLabels.Add("Right");
			csaLabels.Add("RemTop");
			csaLabels.Add("RemLeft");
			csaLabels.Add("RemBottom");
			csaLabels.Add("RemRight");
			csaLabels.Add("Key");
			csaLabels.Add("Wrap text");
			csaLabels.Add("Use field delimiter");
		}
		break;

		case 117:	// PcsReceiveFile
		case 118:	// PcsSendFile
		{
			csaLabels.Add("Transfer file");
			csaLabels.Add("Show status");
		}
		break;

		case 119:	// PlayBackTrace
		{
			csaLabels.Add("Trace type");
			csaLabels.Add("Filename");
		}
		break;

		case 124:	// Print
		case 128:	// PrintScreen
		{
			csaLabels.Add("Item");
			csaLabels.Add("Copies");
		}
		break;

		case 125:	// PrintControl
		{
			csaLabels.Add("Print control");
		}
		break;

		case 127:	// PrintHostFile
		{
			csaLabels.Add("Host file");
			csaLabels.Add("File type");
			csaLabels.Add("Carriage control");
			bYouShouldGo=FALSE;
		}
		break;

		case 130:	// PrintString
		{
			csaLabels.Add("String");
		}
		break;

		case 131:	// PrintTransparentChar
		{
			csaLabels.Add("ASCII code");
		}
		break;

		case 133:	// ReadQuickTest
		{
			csaLabels.Add("Row");
			csaLabels.Add("Column");
			csaLabels.Add("Read option");
		}
		break;

		case 136:	// RemoveEvent
		case 139:	// RemoveOnEvent
		case 143:	// ResetEvent
		{
			csaLabels.Add("Event");
		}
		break;

		case 137:	// RemoveHotlist
		{
			csaLabels.Add("Hotlist name");
		}
		break;

		case 138:	// RemoveNWSAA3270Config
		{
			csaLabels.Add("Remove this index");
		}
		break;

		case 141:	// RemoveToolbarButton
		{
			csaLabels.Add("Toolbar name");
			csaLabels.Add("Button index (1..n)");
		}
		break;

		case 144:	// RestoreDefaults
		{
			csaLabels.Add("Settings type");
		}
		break;

		case 145:	// RunExternalMacro
		{
			csaLabels.Add("File name");
			csaLabels.Add("Macro name");
			csaLabels.Add("Macro data");
		}
		break;

		case 146:	// RunMacro
		{
			csaLabels.Add("Macro name");
			csaLabels.Add("Macro data");
		}
		break;

		case 147:	// RunScript
		{
			csaLabels.Add("Script file");
			csaLabels.Add("Arguments");
		}
		break;

		case 149:	// SaveDisplay
		{
			csaLabels.Add("Layering option");
			csaLabels.Add("Exists option");
			csaLabels.Add("File name");
			csaLabels.Add("Color type");
			csaLabels.Add("Background color");
		}
		break;

		case 151:	// SaveSettings
		case 154:	// SaveXML
		{
			csaLabels.Add("Type");
			csaLabels.Add("Exists option");
			csaLabels.Add("File name");
		}
		break;

		case 156:	// SelectLine
		{
			csaLabels.Add("Line number");
		}
		break;

		case 158:	// SendMail
		{
			csaLabels.Add("Recipient");
			csaLabels.Add("Subject");
			csaLabels.Add("Content type");
			csaLabels.Add("Content");
		}
		break;

		case 161:	// SetAPLKeyMap
		{
			csaLabels.Add("Controls");
			csaLabels.Add("Key");
			csaLabels.Add("Command");
		}
		break;

		case 162:	// SetClipboardText
		{
			csaLabels.Add("Text");
		}
		break;

		case 163:	// SetColorMap
		{
			csaLabels.Add("Attribute");
			csaLabels.Add("Foreground color");
			csaLabels.Add("Background color");
		}
		break;

		case 164:	// SetCommandProfile
		case 165:	// SetCommandRecording
		{
			csaLabels.Add("Command name");
			csaLabels.Add("Enable flag");
		}
		break;

		case 166:	// SetDisplayAttribute
		{
			csaLabels.RemoveAll();
			csaLabels.Add("Attribute index");
			csaLabels.Add("Attribute type");
			csaLabels.Add("Attribute value");
		}
		break;

		case 167:	// SetEncryptedString
		{
			csaLabels.RemoveAll();
			csaLabels.Add("Encrypted setting");
			csaLabels.Add("String");
		}
		break;

		case 168:	// SetIBMPrinterFont
		{
			csaLabels.RemoveAll();
			csaLabels.Add("Font ID");
			csaLabels.Add("Font description");
		}
		break;

		case 169:	// SetKeyMap
		{
			csaLabels.RemoveAll();
			csaLabels.Add("Controls");
			csaLabels.Add("Key");
			csaLabels.Add("Command");
		}
		break;

		case 170:	// SetMouseMap
		{
			csaLabels.RemoveAll();
			csaLabels.Add("Controls");
			csaLabels.Add("Chord");
			csaLabels.Add("Command");
		}
		break;

		case 172:	// SetNumeric
		{
			csaLabels.RemoveAll();
			csaLabels.Add("Setting");
			csaLabels.Add("Value");
		}
		break;

		case 173:	// SetNumericProfile
		{
			csaLabels.RemoveAll();
			csaLabels.Add("Setting");
			csaLabels.Add("Enable flag");
		}
		break;

		case 174:	// SetRecentlyUsedFile
		{
			csaLabels.Add("Title");
			csaLabels.Add("Description");
			csaLabels.Add("Commands");
		}
		break;

		case 175:	// SetScanCodeName
		{
			csaLabels.Add("Scan type");
			csaLabels.Add("Scan code");
			csaLabels.Add("Key");
		}
		break;

		case 177:	// SetSQLStatement
		{
			csaLabels.Add("Type");
			csaLabels.Add("Statement");
		}
		break;

		case 178:	// SetString
		{
			csaLabels.Add("Setting");
			csaLabels.Add("String");
		}
		break;

		case 179:	// SetStringProfile
		{
			csaLabels.Add("Setting");
			csaLabels.Add("Enable flag");
		}
		break;

		case 180:	// SetTerminalKbdPos
		case 186:	// SetWindowsPos
		{
			csaLabels.Add("Left");
			csaLabels.Add("Top");
			csaLabels.Add("Width");
			csaLabels.Add("Height");
		}
		break;

		case 181:	// SetTermKeyBuffer
		{
			csaLabels.Add("Size");
			csaLabels.Add("Overflow");
		}
		break;

		case 182:	// SetToolbarMode
		{
			csaLabels.Add("Toolbar name");
			csaLabels.Add("Mode");
		}
		break;

		case 183:	// SetToolbarPosition
		{
			csaLabels.Add("Toolbar name");
			csaLabels.Add("Left");
			csaLabels.Add("Top");
			csaLabels.Add("Width");
			csaLabels.Add("Height");
		}
		break;

		case 184:	// SetupNWSAA3270Config
		{
			csaLabels.Add("Server");
			csaLabels.Add("Service");
			csaLabels.Add("LU");
		}
		break;

		case 185:	// SetupSession
		{
			csaLabels.Add("Session type");
			csaLabels.Add("Terminal model");
			csaLabels.Add("Transport type");
		}
		break;

		case 187:	// Shell
		{
			csaLabels.Add("Command string");
			csaLabels.Add("Argument string");
			csaLabels.Add("Window state");
		}
		break;

		case 188:	// ShowDBCSHostCodeInputWindow
		{
			csaLabels.Add("Host code");
		}
		break;

		case 189:	// ShowDisplayAttribute
		{
			csaLabels.Add("Attribute");
			csaLabels.Add("Enable");
		}
		break;

		case 190:	// ShotHotlist
		{
			csaLabels.Add("Name");
			csaLabels.Add("Row");
			csaLabels.Add("Column");
			csaLabels.Add("Reserved");
			csaLabels.Add("Length");
		}
		break;

		case 191:	// ShowToolbar
		case 192:	// ShowToolbarButtonsFixedWidth
		case 193:	// ShowToolbarColor
		case 194:	// ShowToolbarLabels
		case 195:	// ShowToolbarLarge
		case 196:	// ShowToolbarTips
		case 211:	// TetherToolbar
		{
			csaLabels.Add("Toolbar name");
			csaLabels.Add("True/false");
		}
		break;

		case 199:	// StartTrace
		{
			csaLabels.Add("File type");
			csaLabels.Add("If file exists");
			csaLabels.Add("File name");
		}
		break;

		case 203:	// StopRecording
		{
			csaLabels.Add("Destination");
			csaLabels.Add("If file exists");
			csaLabels.Add("File name");
		}
		break;

		case 205:	// StopRecordingMacro
		{
			csaLabels.Add("Destination");
			csaLabels.Add("Macro name");
			csaLabels.Add("Description");
		}
		break;

		case 208:	// SwitchToWindow
		{
			csaLabels.Add("Window number");
		}
		break;

		case 209:	// TerminalMouse
		{
			csaLabels.Add("Action");
			csaLabels.Add("Row");
			csaLabels.Add("Column");
		}
		break;

		case 212:	// Toggle
		{
			csaLabels.Add("Setting");
		}
		break;

		case 216:	// TransformXML
		{
			csaLabels.Add("Input file");
			csaLabels.Add("Transform file");
			csaLabels.Add("Output file");
		}
		break;

		case 217:	// TransmitAnsi
		{
			csaLabels.Add("ANSI string");
		}
		break;

		case 218:	// TransmitTerminalKey
		{
			csaLabels.Add("Terminal key");
			bYouShouldGo=FALSE;
		}
		break;

		case 220:	// Wait
		{
			csaLabels.Add("Time");
		}
		break;

		case 221:	// WaitEvent
		{
			csaLabels.Add("Timeout");
		}
		break;

		case 222:	// WaitEventNumber
		{
			csaLabels.Add("Event number");
			csaLabels.Add("Timeout");
		}
		break;

		case 223:	// WaitForCommString
		{
			csaLabels.Add("Command string");
			csaLabels.Add("Timeout");
		}
		break;

		case 224:	// WaitForDisplayString
		{
			csaLabels.Add("Display string");
			csaLabels.Add("Timeout (HH:MM:SS)");
			csaLabels.Add("Row");
			csaLabels.Add("Column");
		}
		break;

		case 225:	// WaitForEvent
		{
			csaLabels.Add("Event type");
			csaLabels.Add("Timeout");
			csaLabels.Add("Duration");
			csaLabels.Add("Row");
			csaLabels.Add("Column");
		}
		break;

		case 226:	// WaitForPrinterStatusString
		case 227:	// WaitForPrinterString
		{
			csaLabels.Add("Status string");
			csaLabels.Add("Timeout");
		}
		break;

		case 228:	// WaitForPrinterStringReplace
		{
			csaLabels.Add("String");
			csaLabels.Add("Timeout");
			csaLabels.Add("Column");
		}
		break;

		case 229:	// WaitForTerminalKey
		{
			csaLabels.Add("Key");
			csaLabels.Add("Timeout");
		}
		break;

		case 230:	// WaitForTimeOfDay
		{
			csaLabels.Add("Time");
		}
		break;

		case 231:	// WriteQuickText
		{
			csaLabels.Add("Key");
		}
		break;

	}

	if ( bYouShouldGo )
	{
		ShowEditControls( &csaLabels );
	}
	else
	{
		ShowMixedControls( RIBM_OLE_API, nFunction, &csaLabels );
	}

}
