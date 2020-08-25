#include "stdafx.h"
#include "APIGen.h"
#include "APIGenDlg.h"

/****************************************************************************DC
	Function	:	CAPIGenDlg::LoadRWIN_OLEArgumentArray()

	Purpose		:	Load the function arguments for RWIN OLE Automation.

*****************************************************************************/
void CAPIGenDlg::LoadRWIN_OLEArgumentArray( int* nFunctionPosition, BOOL bPromptForValues )
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
			case 1:		// Activate
			case 3:		// Break
			case 4:		// CancelExitEvent
			case 5:		// CancelTransfer
			case 7:		// CheckEvent
			case 10:	// ClearEvents
			case 11:	// CloseAllConnections
			case 12:	// CloseStatusBox
			case 19:	// CopyAboutBoxInfo
			case 26:	// DDETerminateAll
			case 30:	// Disconnect
			case 33:	// DropDTR
			case 41:	// FlushPrinter
			case 43:	// FTPGetCurrentHostDirectory
			case 48:	// FTPStopServer
			case 50:	// GetClipboardText
			case 66:	// Hangup
			case 71:	// KermitStartServer
			case 80:	// Paste
			case 87:	// Quit
			case 115:	// StartRecording
			case 120:	// StopMacro
			case 123:	// StopScript
			case 124:	// StopTrace
			case 125:	// SuspendConnection
			case 143:	// WRQStartServer
			case 144:	// WRQStopServer
			{
			}
			break;

			case 2:		// BackgroundColor
			case 42:	// ForegroundColor
			case 9:		// Clear
			case 13:	// CommitLoginProperties
			case 52:	// GetCommandGroupProfile
			case 64:	// GetSerialStatistics
			case 72:	// KermitStopServer
			case 95:	// ResetTerminal
			case 96:	// RestoreDefaults
			case 116:	// StartRecordingExtended
			{
				Read1L( &csaArguments );
			}
			break;

			case 17:	// ConnectTemplate
			case 32:	// DisplayFile
			case 36:	// EvaluateRCLExpression
			case 38:	// ExecuteRCLCommand
			case 112:	// SetPropertyProfile
			case 119:	// StatusBox
			case 131:	// WaitEvent
			case 136:	// WaitForIncomingData
			case 81:	// PlaySound
			{
				Read1E1C( &csaArguments );
			}
			break;

			case 18:	// Copy
			case 49:	// GetAnsiColorRGB
			case 51:	// GetColorRGB
			case 56:	// GetKeymapCommandArgs
			case 57:	// GetKeymapCommands
			case 58:	// GetKeymapCommandType
			case 108:	// SetCommandGroupProfile
			{
				Read2L( &csaArguments );
			}
			break;

			case 27:	// DefineEvent
			{
				Read1E1L3E1L( &csaArguments );
			}
			break;

			case 29:	// Dial
			{
				Read6E2L2C( &csaArguments );
			}
			break;

			case 31:	// Display
			case 35:	// EnableOnEvent
			case 77:	// OpenSettings
			case 90:	// ReadLine
			case 109:	// SetCommandProfile
			case 126:	// Transmit
			case 130:	// Wait
			case 135:	// WaitForHostTrigger
			case 140:	// WaitUntil
			case 146:	// XmodemSendFile
			{
				Read1E1L( &csaArguments );
			}
			break;

			case 39:	// FindText
			{
				Read3E1C( &csaArguments );
			}
			break;

			case 44:	// FTPReceiveFile
			case 45:	// FTPSendFile
			case 141:	// WRQReceiveFile
			case 142:	// WRQSendFile
			{
				Read2E2L3E( &csaArguments );
			}
			break;

			case 47:	// FTPStartServer
			case 127:	// TransmitFile
			{
				Read3E1L( &csaArguments );
			}
			break;
				
			case 59:	// GetLoginProperty
			{
				Read4E1C( &csaArguments );
			}
			break;

			case 65:	// GetText
			{
				Read4E1L( &csaArguments );
			}
			break;

			case 69:	// KermitReceiveFile
			{
				Read2E2L( &csaArguments );
			}
			break;

			case 70:	// KermitSendFile
			case 89:	// ReadChars
			case 91:	// ReadUntil
			{
				Read2E1L( &csaArguments );
			}
			break;

			case 73:	// LockProfile
			{
				Read1C1E( &csaArguments );
			}
			break;

			case 75:	// NewSession
			case 84:	// PrintScreen
			{
				Read1L1E( &csaArguments );
			}
			break;

			case 76:	// OnEvent
			{
				Read1E2L1E2L3E1L1E( &csaArguments );
			}
			break;

			case 78:	// OpenSettingsExtended
			{
				Read1E1L1C( &csaArguments );
			}
			break;

			case 101:	// SaveDisplayMemory
			{
				Read1E1L1C( &csaArguments );
			}
			break;

			case 102:	// SaveSettings
			{
				Read1E2L( &csaArguments );
			}
			break;

			case 103:	// SelectText
			{
				Read4E1L( &csaArguments );
			}
			break;

			case 104:	// SetAnsiColorRGB
			case 107:	// SetColorRGB
			{
				Read1L3E( &csaArguments );
			}
			break;

			case 106:	// SetColorMap
			{
				Read3L( &csaArguments );
			}
			break;

			case 110:	// SetKeyMap
			{
				Read3L2E( &csaArguments );
			}
			break;

			case 111:	// SetMouseMap
			{
				Read3L2E( &csaArguments );
			}
			break;

			case 113:	// SetScanCodeName
			{
				Read1L2E( &csaArguments );
			}
			break;

			case 118:	// StartTrace
			{
				Read1E2L( &csaArguments );
			}
			break;

			case 121:	// StopRecording
			{
				Read1E2L( &csaArguments );
			}
			break;

			case 122:	// StopRecordingMacro
			{
				Read1L2E( &csaArguments );
			}
			break;

			case 132:	// WaitEventNumber
			{
				Read2E1C( &csaArguments );
			}
			break;

			case 134:	// WaitForEvent
			{
				Read1L5E1C( &csaArguments );
			}
			break;

		 	case 137:	// WaitForSilence
			case 138:	// WaitForString
			case 139:	// WaitForStrings
			case 148:	// ZmodemSendFile
			{
				Read2E1L( &csaArguments );
			}
			break;

			case 145:	// XmodemReceiveFile
			{
				Read1E2L( &csaArguments );
			}
			break;

			case 147:	// ZmodemReceiveFile
			{
				Read2E2L( &csaArguments );
			}
			break;
		}
	}	
	else
	{
		switch ( *nFunctionPosition )
		{
			case 0:		// AbortTransfer
			case 1:		// Activate
			case 3:		// Break
			case 4:		// CancelExitEvent
			case 5:		// CancelTransfer
			case 7:		// CheckEvent
			case 10:	// ClearEvents
			case 11:	// CloseAllConnections
			case 12:	// CloseStatusBox
			case 19:	// CopyAboutBoxInfo
			case 26:	// DDETerminateAll
			case 30:	// Disconnect
			case 33:	// DropDTR
			case 41:	// FlushPrinter
			case 43:	// FTPGetCurrentHostDirectory
			case 48:	// FTPStopServer
			case 50:	// GetClipboardText
			case 66:	// Hangup
			case 71:	// KermitStartServer
			case 80:	// Paste
			case 87:	// Quit
			case 115:	// StartRecording
			case 120:	// StopMacro
			case 123:	// StopScript
			case 124:	// StopTrace
			case 125:	// SuspendConnection
			case 143:	// WRQStartServer
			case 144:	// WRQStopServer
			{
			}
			break;

			case 2:		// BackgroundColor
			{
				// attribute
				csaArguments.Add( "rcInverseAttribute+rcBlinkAttribute" );
			}
			break;

			case 6:		// CharacterAttributes
			{
				// row
				csaArguments.Add( "1" );

				// column
				csaArguments.Add( "4" );
			}
			break;

			case 8:		// CheckEventNumber
			{
				// event number
				csaArguments.Add( "2" );
			}
			break;

			case 9:		// Clear
			{
				// clear what
				csaArguments.Add( "rcAll" );
			}
			break;

			case 13:	// CommitLoginProperties
			{
				// options
				csaArguments.Add( "rcChangesAskUser" );
			}
			break;

			case 14:	// CompileScript
			{
				// script name
				csaArguments.Add( "C:\\doFileTrans.rbs" );
			}
			break;

			case 15:	// Connect
			{
				// connection name
				csaArguments.Add( "es9000" );
			}
			break;

			case 16:	// ConnectionSetting
			{
				// connection setting
				csaArguments.Add( "host" );
			}
			break;

			case 17:	// ConnectTemplate
			{
				// connection name
				csaArguments.Add( "es9000" );

				// options
				csaArguments.Add( "rcNoConnect" );
			}
			break;

			case 18:	// Copy
			{
				// copy what
				csaArguments.Add( "rcScreen" );

				// format
				csaArguments.Add( "rcAsBitmap" );
			}
			break;

			case 20:	// DDEExecute
			case 25:	// DDETerminate
			{
				// conversation ID
				csaArguments.Add( "14" );

				// command
				csaArguments.Add( "rcDDEDisconnect" );
			}
			break;

			case 21:	// DDEInitiate
			case 23:	// DDEQueryServerTopics
			{
				// app name
				csaArguments.Add( " " );

				// topic name
				csaArguments.Add( " " );
			}
			break;

			case 22:	// DDEPoke
			case 24:	// DDERequest
			{
				// conversation ID
				csaArguments.Add( "14" );

				//	item name
				csaArguments.Add( "DDEItem1" );

				// value
				csaArguments.Add( "Sunny day" );
			}
			break;

			case 27:	// DefineEvent
			{
				// event
				csaArguments.Add( "14" );

				//	event type
				csaArguments.Add( "rcEvConnected" );

				// string
				csaArguments.Add( " " );

				// row
				csaArguments.Add( "1" );

				//	column
				csaArguments.Add( "41" );

				// key
				csaArguments.Add( "rcVtF8Key" );

			}
			break;

			case 28:	// DestroyToolbar
			{
				// toolbar name
				csaArguments.Add( "FTToolbar" );
			}
			break;

			case 29:	// Dial
			{
				// phone number
				csaArguments.Add( "2066280888" );

				//	description
				csaArguments.Add( "Dialing Ticketmaster..." );

				// init string
				csaArguments.Add( " " );

				// answer timeout
				csaArguments.Add( "0:0:30" );

				//	retry times
				csaArguments.Add( "3" );

				// retry interval
				csaArguments.Add( "0:0:09" );

				// speaker mode
				csaArguments.Add( "rcSpeakerOff" );

				// speaker volume
				csaArguments.Add( "rcSpeakerLow" );

				//	speaker off after redial
				csaArguments.Add( "TRUE" );

				// ignore mode errors
				csaArguments.Add( "FALSE" );

			}
			break;

			case 31:	// Display
			{
				// display string
				csaArguments.Add( "Hello world" );

				// options
				csaArguments.Add( "rcHexData" );

			}
			break;

			case 32:	// DisplayFile
			{
				// filename
				csaArguments.Add( "c:\\sales reports\\annual.txt" );

				// options
				csaArguments.Add( " " );

			}
			break;

			case 34:	// EditScript
			case 54:	// GetFileType
			{
				// script
				csaArguments.Add( "c:\\scripts\\helloWorld.vba" );
			}
			break;

			case 35:	// EnableOnEvent
			{
				// event number
				csaArguments.Add( "rcAllEvents" );

				// enable or disable
				csaArguments.Add( "rcEnable" );
			}
			break;

			case 36:	// EvaluateRCLExpression
			{
				// expression
				csaArguments.Add( "$DATE" );

				// options
				csaArguments.Add( " " );

			}
			break;

			case 37:	// EvaluateBuiltInFunction
			{
				// function name
				csaArguments.Add( "EditPaste" );
			}
			break;

			case 38:	// ExecuteRCLCommand
			{
				// command
				csaArguments.Add( "DISPLAY" );

				// options
				csaArguments.Add( "Hello^M^J" );
			}
			break;

			case 39:	// FindText
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

			case 40:	// FlashWindow
			{
				// rate
				csaArguments.Add( "00:00:01" );
			}
			break;

			case 42:	// ForegroundColor
			{
				// host attribute
				csaArguments.Add( "rcPlainAttribute" );
			}
			break;

			case 44:	// FTPReceiveFile
			case 45:	// FTPSendFile
			case 69:	// KermitReceiveFile
			case 70:	// KermitSendFile
			{
				// local file
				csaArguments.Add( "c:\\receivefiles\\data132.txt" );

				// remote file
				csaArguments.Add( "data132 txt" );

				// transfer type
				csaArguments.Add( "rcASCII" );

				// if file exists
				csaArguments.Add( "rcAppend" );

				// before
				csaArguments.Add( "#August 8, 2005#" );

				// since
				csaArguments.Add( "#August 4, 2005#" );

				// exclude
				csaArguments.Add( "data12? txt" );

			}
			break;

			case 46:	// FTPSetCurrentHostDirectory
			{
				// host directory
				csaArguments.Add( "Sales05" );
			}
			break;

			case 47:	// FTPStartServer
			{
				// user name
				csaArguments.Add( "scottvi" );

				// password
				csaArguments.Add( "macon62521" );

				// host name
				csaArguments.Add( "es9000" );

				// options
				csaArguments.Add( "rcNoLogInDialog" );
			}
			break;

			case 49:	// GetAnsiColorRGB
			case 51:	// GetColorRGB
			{
				// color
				csaArguments.Add( "rcDkRed" );

				// which value
				csaArguments.Add( "rcRed" );
			}
			break;

			case 52:	// GetCommandGroupProfile
			{
				// command group
				csaArguments.Add( "rcHostDirectory" );
			}
			break;

			case 53:	// GetCommandProfile
			{
				// command name
				csaArguments.Add( "EditPaste" );
			}
			break;

			case 55:	// GetFolderName
			{
				// title
				csaArguments.Add( "Folder browsing" );

				// text
				csaArguments.Add( "Use this folder" );

				// start-in folder
				csaArguments.Add( "c:\\salesrpts\\2005" );
			}
			break;

			case 56:	// GetKeymapCommandArgs
			case 57:	// GetKeymapCommands
			case 58:	// GetKeymapCommandType
			{
				// modifiers
				csaArguments.Add( "rcAltKey" );

				// keys
				csaArguments.Add( "F2" );
			}
			break;

			case 59:	// GetLoginProperty
			{
				// property
				csaArguments.Add( "UserName" );

				// prompt
				csaArguments.Add( "Login ID" );

				// host user name
				csaArguments.Add( "MikeRob" );

				// host name
				csaArguments.Add( "ES9000" );

				// options
				csaArguments.Add( "rcIsPassword" );
			}
			break;

			case 60:	// GetOpenFilename
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

			case 61:	// GetPassword
			{
				// prompt
				csaArguments.Add( "Password is " );

				// host user name
				csaArguments.Add( "ToddVi" );

				// host name
				csaArguments.Add( "ES9000" );

				// options
				csaArguments.Add( " " );
			}
			break;

			case 62:	// GetPropertyInformation
			{
				// name
				csaArguments.Add( "ConnectionType" );

				// options
				csaArguments.Add( " " );
			}
			break;

			case 63:	// GetSaveAsFilename
			{
				// initial file name
				csaArguments.Add( "c:\\sales2005\\August.dat" );

				// file filter
				csaArguments.Add( "Database files (*.dat),*.dat,Text (*.txt),*.txt" );

				// filter index
				csaArguments.Add( "1" );

				// title
				csaArguments.Add( "Save file as..." );

				// button text
				csaArguments.Add( "Save as..." );
			}
			break;

			case 64:	// GetSerialStatistics
			{
				// which statistic
				csaArguments.Add( "rcBreakDetect" );
			}
			break;

			case 65:	// GetText
			{
				// start row
				csaArguments.Add( "1" );

				// start column
				csaArguments.Add( "1" );

				// end row
				csaArguments.Add( "4" );

				// end column
				csaArguments.Add( "17" );

				// options
				csaArguments.Add( "rcRectRegion" );
			}
			break;

			case 67:	// Help
			{
				// help topic
				csaArguments.Add( "rcHelpSearchForTopic" );

				// help file
				csaArguments.Add( "c:\\program files\\Refl12\\R4win.hlp" );
			}
			break;

			case 68:	// InputBox
			{
				// prompt
				csaArguments.Add( "Please Enter Your Login Name" );

				// title
				csaArguments.Add( "Login" );

				// default
				csaArguments.Add( "Default response" );
			}
			break;

			case 72:	// KermitStopServer
			{
				// logoff
				csaArguments.Add( "rcLogoff" );
			}
			break;

			case 73:	// LockProfile
			{
				// allow unlock
				csaArguments.Add( "TRUE" );

				// password
				csaArguments.Add( "secret#" );
			}
			break;

			case 74:	// MsgBox
			{
				// message
				csaArguments.Add( "Connection has dropped" );

				// type
				csaArguments.Add( "0" );

				// caption
				csaArguments.Add( "Comm notice" );
			}
			break;

			case 75:	// NewSession
			{
				// session type
				csaArguments.Add( "rcReflection1" );

				// settings file
				csaArguments.Add( " " );
			}
			break;

			case 76:	// OnEvent
			{
				// event number
				csaArguments.Add( "16" );

				// event
				csaArguments.Add( "rcDisplayString" );

				// command type
				csaArguments.Add( "rcRBCommand" );

				// commands
				csaArguments.Add( "Connect" );

				// enable
				csaArguments.Add( "rcEnable" );

				// after event
				csaArguments.Add( "rcEventReenable" );

				// string
				csaArguments.Add( "" );

				// row
				csaArguments.Add( "2" );

				// column
				csaArguments.Add( "64" );

				// key
				csaArguments.Add( " " );

				// command arguments
				csaArguments.Add( "-i" );
			}
			break;

			case 77:	// OpenSettings
			case 78:	// OpenSettingsExtended
			{
				// file name
				csaArguments.Add( "c:\\profiles\\RColors.set" );

				// settings type
				csaArguments.Add( "rcColors" );

				// options
				csaArguments.Add( " " );
			}
			break;

			case 79:	// PasswordBox
			{
				// prompt
				csaArguments.Add( "Please enter your password" );

				// title
				csaArguments.Add( "Access credentials" );

				// default
				csaArguments.Add( "guestpass" );
			}
			break;

			case 81:	// PlaySound
			{
				// sound file
				csaArguments.Add( "c:\\sounds\\noAccessPermitted.wav" );

				// asynchronous
				csaArguments.Add( "TRUE" );
			}
			break;

			case 82:	// Print
			case 84:	// PrintScreen
			{
				// range
				csaArguments.Add( "rcSelection" );

				// copies
				csaArguments.Add( "2" );
			}
			break;

			case 83:	// PrintFile
			{
				// file name
				csaArguments.Add( "c:\\reports\\sales0805.wpd" );
			}
			break;

			case 85:	// PrintString
			{
				// string
				csaArguments.Add( "take me to the water" );
			}
			break;

			case 86:	// PropertyIsModifiable
			{
				// property name
				csaArguments.Add( "DisplayRows" );
			}
			break;

			case 88:	// RaiseControlEvent
			{
				// param1
				csaArguments.Add( "22" );

				// param2
				csaArguments.Add( "UML 2.0" );

			}
			break;

			case 89:	// ReadChars
			{
				// count
				csaArguments.Add( "22" );

				// timeout
				csaArguments.Add( "00:00:04" );

				// options
				csaArguments.Add( "rcNoDisplay" );
			}
			break;

			case 90:	// ReadLine
			{
				// count
				csaArguments.Add( "22" );

				// options
				csaArguments.Add( "rcNoDisplay" );

				// save end of line
				csaArguments.Add( "TRUE" );

			}
			break;

			case 91:	// ReadUntil
			{
				// until chars
				csaArguments.Add( "Chr$(rcCR)" );

				// timeout
				csaArguments.Add( "00:00:04" );

				// options
				csaArguments.Add( "rcNoDisplay" );

				// which terminator
				csaArguments.Add( " " );

			}
			break;

			case 92:	// RemoveEvent
			case 93:	// RemoveOnEvent
			case 94:	// ResetEvent
			{
				// event
				csaArguments.Add( "6" );
			}
			break;

			case 95:	// ResetTerminal
			{
				// reset mode
				csaArguments.Add( "rcSerialStats" );
			}
			break;

			case 96:	// RestoreDefaults
			{
				// setting type
				csaArguments.Add( "rcColors" );
			}
			break;

			case 97:	// ResumeConnection
			{
				// connection ID
				csaArguments.Add( "rcConn1" );
			}
			break;

			case 98:	// RunExternalMacro
			{
				// file name
				csaArguments.Add( "C:\\Mypath\\Myfile.rsf" );

				// macro name
				csaArguments.Add( "Myfile.ThisSession.MyMacro" );

				// macro data
				csaArguments.Add( " " );
			}
			break;

			case 99:	// RunMacro
			{
				// macro name
				csaArguments.Add( "Myfile.ThisSession.MyMacro" );

				// macro data
				csaArguments.Add( " " );
			}
			break;

			case 100:	// RunScript
			{
				// script name
				csaArguments.Add( "C:\\Mypath\\Myscript.rbs" );

				//	arguments
				csaArguments.Add( "-f" );
			}
			break;

			case 101:	// SaveDisplayMemory
			{
				// file name
				csaArguments.Add( "C:\\work080805\\samples.txt" );

				//	if file exists
				csaArguments.Add( "rcAppend" );

				//	options
				csaArguments.Add( " " );
			}
			break;

			case 102:	// SaveSettings
			{
				// filename
				csaArguments.Add( "C:\\Mypath\\session1.rsf" );

				// type
				csaArguments.Add( "rcSettings" );

				// exist option
				csaArguments.Add( "rcOverwrite" );

			}
			break;

			case 103:	// SelectText
			{
				// start row
				csaArguments.Add( "1" );

				// start column
				csaArguments.Add( "1" );

				// end row
				csaArguments.Add( "4" );

				// end column
				csaArguments.Add( "17" );

				// options
				csaArguments.Add( "rcRectRegion" );
			}
			break;

			case 104:	// SetAnsiColorRGB
			case 107:	// SetColorRGB
			{
				// color
				csaArguments.Add( "rcDkRed" );

				// red
				csaArguments.Add( "201" );

				// green
				csaArguments.Add( "202" );

				// blue
				csaArguments.Add( "200" );

			}
			break;

			case 105:	// SetClipboardText
			{
				// text
				csaArguments.Add( "The quick brown fox jumps over the lazy dog." );
			}
			break;

			case 106:	// SetColorMap
			{
				// attribute
				csaArguments.Add( "rcHostTurquoise" );

				// foreground
				csaArguments.Add( "rcWhite" );

				// background
				csaArguments.Add( "rcBlack" );

			}
			break;

			case 108:	// SetCommandGroupProfile
			{
				// command group
				csaArguments.Add( "rcHostDirectory" );
			}
			break;

			case 109:	// SetCommandProfile
			{
				// command
				csaArguments.Add( "Connect" );

				// is enabled
				csaArguments.Add( "rcEnabled" );

			}
			break;

			case 110:	// SetKeyMap
			{
				// modifiers
				csaArguments.Add( "rcNormalKey" );

				// key
				csaArguments.Add( "F1" );

				// command type
				csaArguments.Add( "rcTransmitString" );

				// commands
				csaArguments.Add( "TransmitTerminalKey rcIbmEnterKey" );

				// command arguments
				csaArguments.Add( " " );

			}
			break;

			case 111:	// SetMouseMap
			{
				// modifiers
				csaArguments.Add( "rcNormal" );

				// chord
				csaArguments.Add( "MiddleBtn" );

				// command type
				csaArguments.Add( "rcTransmitString" );

				// commands
				csaArguments.Add( "TransmitTerminalKey rcIbmEnterKey" );

				// command arguments
				csaArguments.Add( " " );

			}
			break;

			case 112:	// SetPropertyProfile
			{
				// property name
				csaArguments.Add( "ShowTerminalFrame" );

				// is enabled
				csaArguments.Add( "FALSE" );
			}
			break;

			case 113:	// SetScanCodeName
			{
				// scan type
				csaArguments.Add( "rcNormalScanCode" );

				// scan code
				csaArguments.Add( "32h" );

				// key
				csaArguments.Add( "Interrupt 9" );

			}
			break;

			case 114:	// Shell
			{
				// command string
				csaArguments.Add( "notepad.exe" );

				// window state
				csaArguments.Add( "rcNormal" );

				// wait
				csaArguments.Add( "FALSE" );

			}
			break;

			case 116:	// StartRecordingExtended
			case 117:	// StartRecordingSilently
			{
				// options
				csaArguments.Add( "rcSilently" );
			}
			break;

			case 118:	// StartTrace
			{
				// file name
				csaArguments.Add( "c:\\traces\\trace080705.trc" );

				// if file exists
				csaArguments.Add( "rcAppend" );

				// trace format
				csaArguments.Add( "rcTraceEvents" );

			}
			break;

			case 119:	// StatusBox
			{
				// text
				csaArguments.Add( "Please wait" );

				// options
				csaArguments.Add( "rcStatusBoxTitleBar" );

			}
			break;

			case 121:	// StopRecording
			{
				// file name
				csaArguments.Add( "c:\\traces\\trace080805.vb" );

				// target
				csaArguments.Add( "rcVBSource" );

				// exists option
				csaArguments.Add( "rcCancel" );

			}
			break;

			case 122:	// StopRecordingMacro
			{
				// destination
				csaArguments.Add( "rcMacro" );

				// name
				csaArguments.Add( "c:\\traces\\trace080805.rfm" );

				// description
				csaArguments.Add( "Count protected fields" );

				// options
				csaArguments.Add( " " );

			}
			break;

			case 126:	// Transmit
			{
				// string
				csaArguments.Add( "login user122x" );

				// options
				csaArguments.Add( "rcIgnoreBlockMode" );

			}
			break;

			case 127:	// TransmitFile
			{
				// file name
				csaArguments.Add( "c:\\wsreports\\report080805.txt" );

				// pause time
				csaArguments.Add( "00:00:00.4" );

				// prompt char
				csaArguments.Add( " " );

				// options
				csaArguments.Add( "rcNoDisplay" );

			}
			break;

			case 128:	// TransmitTerminalKey
			{
				// key
				csaArguments.Add( "rcVtF8" );
			}
			break;

			case 129:	// UnlockProfile
			{
				// password
				csaArguments.Add( "12345" );
			}
			break;

			case 130:	// Wait
			case 131:	// WaitEvent
			case 135:	// WaitForHostTrigger
			case 136:	// WaitForIncomingData
			{
				// how long
				csaArguments.Add( "0:0:00.5" );

				// options
				csaArguments.Add( "rcAllowKeystrokes" );
			}
			break;

			case 132:	// WaitEventNumber
			{
				// event
				csaArguments.Add( "15" );

				// timeout
				csaArguments.Add( "0:0:00.5" );

				// options
				csaArguments.Add( "rcAllowKeystrokes" );
			}
			break;

			case 133:	// WaitForCall
			{
				// description
				csaArguments.Add( "Waiting for disconnect..." );

				// init string
				csaArguments.Add( " " );
			}
			break;

			case 134:	// WaitForEvent
			{
				// event type
				csaArguments.Add( "rcEvConnected" );

				// timeout
				csaArguments.Add( "0:0:10" );

				// string
				csaArguments.Add( " " );

				// row
				csaArguments.Add( "1" );

				// column
				csaArguments.Add( "2" );

				// key
				csaArguments.Add( "rcVtF8Key" );

				// options
				csaArguments.Add( "rcAllowKeystrokes" );

			}
			break;

			case 137:	// WaitForSilence
			{
				// silence time
				csaArguments.Add( "0:0:03" );

				// timeout
				csaArguments.Add( "0:0:15" );

				// options
				csaArguments.Add( "rcAllowKeystrokes" );
			}
			break;

			case 138:	// WaitForString
			{
				// string
				csaArguments.Add( "Ready:" );

				// timeout
				csaArguments.Add( "0:0:15" );

				// options
				csaArguments.Add( "rcAllowKeystrokes" );
			}
			break;

			case 139:	// WaitForStrings
			{
				// string array
				csaArguments.Add( "array1" );

				// timeout
				csaArguments.Add( "0:0:10" );

				// options
				csaArguments.Add( "rcAllowKeystrokes" );
			}
			break;

			case 140:	// WaitUntil
			{
				// date/time
				csaArguments.Add( "#August 8, 2005#" );

				// options
				csaArguments.Add( "rcAllowKeystrokes" );

			}
			break;

			case 141:	// WRQReceiveFile
			case 142:	// WRQSendFile
			{
				// local file
				csaArguments.Add( "c:\\receivefiles\\data132.txt" );

				// remote file
				csaArguments.Add( "data132 txt" );

				// transfer type
				csaArguments.Add( "rcASCII" );

				// if file exists
				csaArguments.Add( "rcAppend" );

				// before
				csaArguments.Add( "#August 8, 2005#" );

				// since
				csaArguments.Add( "#August 4, 2005#" );

				// exclude
				csaArguments.Add( "data12? txt" );

				// attributes
				csaArguments.Add( " " );

			}
			break;

			case 145:	// XmodemReceiveFile
			case 146:	// XmodemSendFile
			{
				// local file
				csaArguments.Add( "c:\\receivefiles\\data132.txt" );

				// transfer type
				csaArguments.Add( "rcASCII" );

				// if file exists
				csaArguments.Add( "rcAppend" );
			}
			break;


			case 147:	// ZmodemReceiveFile
			case 148:	// ZmodemSendFile
			{
				// local file
				csaArguments.Add( "c:\\receivefiles\\data132.txt" );

				// remote file
				csaArguments.Add( "data132 txt" );

				// transfer type
				csaArguments.Add( "rcASCII" );

				// if file exists
				csaArguments.Add( "rcAppend" );
			}
			break;


		}

	}

}




/****************************************************************************DC
	Function	:	CAPIGenDlg::ShowRWinControls()

	Purpose		:	Show the controls for the Extra! OLE Automation 
					function parameters.

*****************************************************************************/
void CAPIGenDlg::ShowRWinControls( int nFunction )
{
	HideParameterControls();
	csaLabels.RemoveAll();
	BOOL bYouShouldGo=TRUE;

	switch ( nFunction )
	{
		case 0:		// AbortTransfer
		case 1:		// Activate
		case 3:		// Break
		case 4:		// CancelExitEvent
		case 5:		// CancelTransfer
		case 7:		// CheckEvent
		case 10:	// ClearEvents
		case 11:	// CloseAllConnections
		case 12:	// CloseStatusBox
		case 19:	// CopyAboutBoxInfo
		case 26:	// DDETerminateAll
		case 30:	// Disconnect
		case 33:	// DropDTR
		case 41:	// FlushPrinter
		case 43:	// FTPGetCurrentHostDirectory
		case 48:	// FTPStopServer
		case 50:	// GetClipboardText
		case 66:	// Hangup
		case 71:	// KermitStartServer
		case 80:	// Paste
		case 87:	// Quit
		case 115:	// StartRecording
		case 117:	// StartRecordingSilently
		case 120:	// StopMacro
		case 123:	// StopScript
		case 124:	// StopTrace
		case 125:	// SuspendConnection
		case 143:	// WRQStartServer
		case 144:	// WRQStopServer
		{
		}
		break;

		case 2:		// BackgroundColor
		{
			csaLabels.Add("Attribute");
			bYouShouldGo=FALSE;
		}
		break;

		case 6:		// CharacterAttributes
		{
			csaLabels.Add("Row");
			csaLabels.Add("Column");
		}
		break;

		case 8:		// CheckEventNumber
		{
			csaLabels.Add("Event number");
		}
		break;

		case 9:		// Clear
		{
			csaLabels.Add("Clear what");
			bYouShouldGo=FALSE;
		}
		break;

		case 13:	// CommitLoginProperties
		{
			csaLabels.Add("Option");
			bYouShouldGo=FALSE;
		}
		break;

		case 14:	// CompileScript
		case 34:	// EditScript
		{
			csaLabels.Add("Script name");
			bYouShouldGo=FALSE;
		}
		break;

		case 15:	// Connect
		{
			csaLabels.Add("Connection name");
		}
		break;

		case 16:	// ConnectionSetting
		{
			csaLabels.Add("Setting");
		}
		break;

		case 17:	// ConnectTemplate
		{
			csaLabels.Add("Connection name");
			csaLabels.Add("rcNoConnect");
			bYouShouldGo=FALSE;
		}
		break;

		case 18:	// Copy
		{
			csaLabels.Add("Copy what");
			csaLabels.Add("Format");
			bYouShouldGo=FALSE;
		}
		break;

		case 20:	// DDEExecute
		{
			csaLabels.Add("Conversation ID");
			csaLabels.Add("Command");
		}
		break;

		case 25:	// DDETerminate
		{
			csaLabels.Add("Conversation ID");
		}
		break;

		case 21:	// DDEInitiate
		case 23:	// DDEQueryServerTopics
		{
			csaLabels.Add("Application name");
			csaLabels.Add("Topic name");
		}
		break;

		case 22:	// DDEPoke
		{
			csaLabels.Add("Conversation ID");
			csaLabels.Add("Item name");
			csaLabels.Add("Value");
		}
		break;

		case 24:	// DDERequest
		{
			csaLabels.Add("Conversation ID");
			csaLabels.Add("Item name");
		}
		break;

		case 27:	// DefineEvent
		{
			csaLabels.Add("Event");
			csaLabels.Add("Event type");
			csaLabels.Add("String");
			csaLabels.Add("Row");
			csaLabels.Add("Column");
			csaLabels.Add("Key");
			bYouShouldGo=FALSE;
		}
		break;

		case 28:	// DestroyToolbar
		{
			csaLabels.Add("Toolbar name");
		}
		break;

		case 29:	// Dial
		{
			csaLabels.Add("Phone number");
			csaLabels.Add("Description");
			csaLabels.Add("Init string");
			csaLabels.Add("Answer timeout (HH:MM:SS)");
			csaLabels.Add("Number of retries");
			csaLabels.Add("Retry interval (HH:MM:SS:hh)");
			csaLabels.Add("Speaker mode");
			csaLabels.Add("Speaker volume");
			csaLabels.Add("Speaker off after redial");
			csaLabels.Add("Ignore modem errors");
			bYouShouldGo=FALSE;
		}
		break;

		case 31:	// Display
		{
			csaLabels.Add("String");
			csaLabels.Add("Options");
			bYouShouldGo=FALSE;
		}
		break;

		case 32:	// DisplayFile
		{
			csaLabels.Add("File name");
			csaLabels.Add("rcNoTranslation");
			bYouShouldGo=FALSE;
		}
		break;

		case 54:	// GetFileType
		{
			csaLabels.Add("File name");
		}
		break;

		case 35:	// EnableOnEvent
		{
			csaLabels.Add("Event number");
			csaLabels.Add("Enable/disable");
			bYouShouldGo=FALSE;
		}
		break;

		case 36:	// EvaluateRCLExpression
		{
			csaLabels.Add("Expression");
			csaLabels.Add("rcNoTranslation");
			bYouShouldGo=FALSE;
		}
		break;

		case 37:	// EvaluateBuiltInFunction
		{
			csaLabels.Add("Function name");
		}
		break;

		case 38:	// ExecuteRCLCommand
		{
			csaLabels.Add("Command");
			csaLabels.Add("rcNoTranslation");
			bYouShouldGo=FALSE;
		}
		break;

		case 39:	// FindText
		{
			csaLabels.Add("Search for");
			csaLabels.Add("Start row");
			csaLabels.Add("Start column");
			csaLabels.Add("rcNoTranslation");
			bYouShouldGo=FALSE;
		}
		break;

		case 40:	// FlashWindow
		{
			csaLabels.Add("Flash rate (hh-mm-ss.hh)");
		}
		break;

		case 42:	// ForegroundColor
		{
			csaLabels.Add("Attribute");
			bYouShouldGo=FALSE;
		}
		break;

		case 44:	// FTPReceiveFile
		case 45:	// FTPSendFile
		case 141:	// WRQReceiveFile
		case 142:	// WRQSendFile
		{
			csaLabels.Add("Local file");
			csaLabels.Add("Remote file");
			csaLabels.Add("Transfer type");
			csaLabels.Add("If file exists...");
			csaLabels.Add("Before date/time");
			csaLabels.Add("Since date/time");
			csaLabels.Add("Exclude");
			bYouShouldGo=FALSE;
		}
		break;

		case 46:	// FTPSetCurrentHostDirectory
		{
			csaLabels.Add("Host directory");
		}
		break;

		case 47:	// FTPStartServer
		{
			csaLabels.Add("Username");
			csaLabels.Add("Password");
			csaLabels.Add("Host name");
			csaLabels.Add("Options");
			bYouShouldGo=FALSE;
		}
		break;

		case 49:	// GetAnsiColorRGB		// got here at EOD 09/30
		{
			csaLabels.Add("Color");
			csaLabels.Add("Which component?");
			bYouShouldGo=FALSE;
		}
		break;

		case 51:	// GetColorRGB
		{
			csaLabels.Add("Color");
			csaLabels.Add("Which component?");
			bYouShouldGo=FALSE;
		}
		break;

		case 52:	// GetCommandGroupProfile
		{
			csaLabels.Add("Command group");
			bYouShouldGo=FALSE;
		}
		break;

		case 53:	// GetCommandProfile
		{
			csaLabels.Add("Command name");
		}
		break;

		case 55:	// GetFolderName
		{
			csaLabels.Add("Title");
			csaLabels.Add("Text");
			csaLabels.Add("Start-in folder");
		}
		break;

		case 56:	// GetKeymapCommandArgs
		case 57:	// GetKeymapCommands
		case 58:	// GetKeymapCommandType
		{
			csaLabels.Add("Modifiers");
			csaLabels.Add("Key");
			bYouShouldGo=FALSE;
		}
		break;

		case 59:	// GetLoginProperty
		{
			csaLabels.Add("Property name");
			csaLabels.Add("Prompt");
			csaLabels.Add("Host user name");
			csaLabels.Add("Host name");
			csaLabels.Add("rclsPassword");
			bYouShouldGo=FALSE;
		}
		break;

		case 60:	// GetOpenFilename
		{
			csaLabels.Add("File filter");
			csaLabels.Add("Filter index");
			csaLabels.Add("Title");
			csaLabels.Add("Button Text");
		}
		break;

		case 61:	// GetPassword
		{
			csaLabels.Add("Prompt");
			csaLabels.Add("Host user name");
			csaLabels.Add("Host name");
		}
		break;

		case 62:	// GetPropertyInformation
		{
			csaLabels.Add("Property name");
		}
		break;

		case 63:	// GetSaveAsFilename
		{
			csaLabels.Add("Initial filename");
			csaLabels.Add("File filter");
			csaLabels.Add("Filter index");
			csaLabels.Add("Title");
			csaLabels.Add("Button Text");
		}
		break;

		case 64:	// GetSerialStatistics
		{
			csaLabels.Add("Which statistic");
			bYouShouldGo=FALSE;
		}
		break;

		case 65:	// GetText
		{
			csaLabels.Add("Start row");
			csaLabels.Add("Start column");
			csaLabels.Add("End row");
			csaLabels.Add("End column");
			csaLabels.Add("Option");
			bYouShouldGo=FALSE;
		}
		break;

		case 67:	// Help
		{
			csaLabels.Add("Help topic");
			csaLabels.Add("Help file");
		}
		break;

		case 68:	// InputBox
		{
			csaLabels.Add("Prompt");
			csaLabels.Add("Title");
			csaLabels.Add("Default");
		}
		break;

		case 69:	// KermitReceiveFile
		{
			csaLabels.Add("Local file");
			csaLabels.Add("Remote file");
			csaLabels.Add("Transfer type");
			csaLabels.Add("If file exists...");
			bYouShouldGo=FALSE;
		}
		break;

		case 70:	// KermitSendFile
		{
			csaLabels.Add("Local file");
			csaLabels.Add("Remote file");
			csaLabels.Add("Transfer type");
			bYouShouldGo=FALSE;
		}
		break;

		case 72:	// KermitStopServer
		{
			csaLabels.Add("Logoff option");
			bYouShouldGo=FALSE;
		}
		break;

		case 73:	// LockProfile
		{
			csaLabels.Add("Allow unlock");
			csaLabels.Add("Password");
			bYouShouldGo=FALSE;
		}
		break;

		case 74:	// MsgBox
		{
			csaLabels.Add("Message");
			csaLabels.Add("Type");
			csaLabels.Add("Caption");
		}
		break;

		case 75:	// NewSession
		{
			csaLabels.Add("Session type");
			csaLabels.Add("Settings file");
			bYouShouldGo=FALSE;
		}
		break;

		case 76:	// OnEvent
		{
			csaLabels.Add("Event number");
			csaLabels.Add("Event");
			csaLabels.Add("Command type");
			csaLabels.Add("Commands");
			csaLabels.Add("Enable");
			csaLabels.Add("After event");
			csaLabels.Add("String");
			csaLabels.Add("Row");
			csaLabels.Add("Column");
			csaLabels.Add("Key");
			csaLabels.Add("Command arguments");
			bYouShouldGo=FALSE;
		}
		break;

		case 77:	// OpenSettings
		{
			csaLabels.Add("Filename");
			csaLabels.Add("Type");
			bYouShouldGo=FALSE;
		}
		break;

		case 78:	// OpenSettingsExtended
		{
			csaLabels.Add("Filename");
			csaLabels.Add("Type");
			csaLabels.Add("rcNoConnect");
			bYouShouldGo=FALSE;
		}
		break;

		case 79:	// PasswordBox
		{
			csaLabels.Add("Prompt");
			csaLabels.Add("Title");
			csaLabels.Add("Default password");
		}
		break;

		case 81:	// PlaySound
		{
			csaLabels.Add("Sound file");
			csaLabels.Add("Play asynchronously");
			bYouShouldGo=FALSE;
		}
		break;

		case 82:	// Print
		case 83:	// PrintFile
		{
			csaLabels.Add("Filename");
		}
		break;

		case 84:	// PrintScreen
		{
			csaLabels.Add("Screen range");
			csaLabels.Add("Copies to print");
			bYouShouldGo=FALSE;
		}
		break;

		case 85:	// PrintString
		{
			csaLabels.Add("String");
		}
		break;

		case 86:	// PropertyIsModifiable
		{
			csaLabels.Add("Property name");
		}
		break;

		case 88:	// RaiseControlEvent
		{
			csaLabels.Add("1st parameter");
			csaLabels.Add("2nd parameter");
		}
		break;

		case 89:	// ReadChars
		{
			csaLabels.Add("Read this number chars");
			csaLabels.Add("Timeout (HH:MM:SS:hh)");
			csaLabels.Add("Read options");
			bYouShouldGo=FALSE;
		}
		break;

		case 90:	// ReadLine
		{
			csaLabels.Add("Timeout (HH:MM:SS:hh)");
			csaLabels.Add("Read options");
			bYouShouldGo=FALSE;
		}
		break;

		case 91:	// ReadUntil
		{
			csaLabels.Add("Read until chars");
			csaLabels.Add("Timeout (HH:MM:SS:hh)");
			csaLabels.Add("Read options");
			bYouShouldGo=FALSE;
		}
		break;

		case 92:	// RemoveEvent
		case 93:	// RemoveOnEvent
		case 94:	// ResetEvent
		{
			csaLabels.Add("Event");
		}
		break;

		case 95:	// ResetTerminal
		{
			csaLabels.Add("Reset mode");
			bYouShouldGo=FALSE;
		}
		break;

		case 96:	// RestoreDefaults
		{
			csaLabels.Add("Setting type");
			bYouShouldGo=FALSE;
		}
		break;

		case 97:	// ResumeConnection
		{
			csaLabels.Add("Connection ID");
		}
		break;

		case 98:	// RunExternalMacro
		{
			csaLabels.Add("Filename");
			csaLabels.Add("Macro name");
			csaLabels.Add("Macro data");
		}
		break;

		case 99:	// RunMacro
		{
			csaLabels.Add("Macro name");
			csaLabels.Add("Macro data");
		}
		break;

		case 100:	// RunScript
		{
			csaLabels.Add("Script name");
			csaLabels.Add("Script arguments");
		}
		break;

		case 101:	// SaveDisplayMemory
		{
			csaLabels.Add("Filename");
			csaLabels.Add("If file exists...");
			csaLabels.Add("rcNoTranslation");
			bYouShouldGo=FALSE;
		}
		break;

		case 102:	// SaveSettings
		{
			csaLabels.Add("Filename");
			csaLabels.Add("Type");
			csaLabels.Add("If file exists...");
			bYouShouldGo=FALSE;
		}
		break;

		case 103:	// SelectText
		{
			csaLabels.Add("Start row");
			csaLabels.Add("Start column");
			csaLabels.Add("End row");
			csaLabels.Add("End column");
			csaLabels.Add("Selection type");
			bYouShouldGo=FALSE;
		}
		break;

		case 104:	// SetAnsiColorRGB
		case 107:	// SetColorRGB
		{
			csaLabels.Add("Color");
			csaLabels.Add("Red (0..255)");
			csaLabels.Add("Green (0..255)");
			csaLabels.Add("Blue (0..255)");
			bYouShouldGo=FALSE;
		}
		break;

		case 105:	// SetClipboardText
		{
			csaLabels.Add("Clipboard text");
		}
		break;

		case 106:	// SetColorMap
		{
			csaLabels.Add("Attribute");
			csaLabels.Add("Foreground");
			csaLabels.Add("Background");
			bYouShouldGo=FALSE;
		}
		break;

		case 108:	// SetCommandGroupProfile
		{
			csaLabels.Add("Command group");
			csaLabels.Add("Is enabled?");
			bYouShouldGo=FALSE;
		}
		break;

		case 109:	// SetCommandProfile
		{
			csaLabels.Add("Command name");
			csaLabels.Add("Is enabled?");
			bYouShouldGo=FALSE;
		}
		break;

		case 110:	// SetKeyMap
		case 111:	// SetMouseMap
		{
			csaLabels.Add("Modifiers");
			csaLabels.Add("Key");
			csaLabels.Add("Command type");
			csaLabels.Add("Commands");
			csaLabels.Add("Command arguments");
			bYouShouldGo=FALSE;
		}
		break;

		case 112:	// SetPropertyProfile
		{
			csaLabels.Add("Property name");
			csaLabels.Add("Is enabled?");
			bYouShouldGo=FALSE;
		}
		break;

		case 113:	// SetScanCodeName
		{
			csaLabels.Add("Scan type");
			csaLabels.Add("Scan code");
			csaLabels.Add("Scan name");
			bYouShouldGo=FALSE;
		}
		break;

		case 114:	// Shell
		{
			csaLabels.Add("Application");
			csaLabels.Add("Command line");
			csaLabels.Add("Wait");
		}
		break;

		case 116:	// StartRecordingExtended
		{
			csaLabels.Add("Options");
			bYouShouldGo=FALSE;
		}
		break;

		case 118:	// StartTrace
		{
			csaLabels.Add("Filename");
			csaLabels.Add("If file exists...");
			csaLabels.Add("Trace format");
			bYouShouldGo=FALSE;
		}
		break;

		case 119:	// StatusBox
		{
			csaLabels.Add("Text");
			csaLabels.Add("Include title bar");
			bYouShouldGo=FALSE;
		}
		break;

		case 121:	// StopRecording
		{
			csaLabels.Add("Filename");
			csaLabels.Add("Output language");
			csaLabels.Add("If file exists...");
			bYouShouldGo=FALSE;
		}
		break;

		case 122:	// StopRecordingMacro
		{
			csaLabels.Add("Destination");
			csaLabels.Add("Name");
			csaLabels.Add("Description");
			bYouShouldGo=FALSE;
		}
		break;

		case 126:	// Transmit
		{
			csaLabels.Add("String");
			csaLabels.Add("Options");
			bYouShouldGo=FALSE;
		}
		break;

		case 127:	// TransmitFile
		{
			csaLabels.Add("Filename");
			csaLabels.Add("Pause time (HH:MM:SS:hh)");
			csaLabels.Add("Prompt char");
			csaLabels.Add("Options");
			bYouShouldGo=FALSE;
		}
		break;

		case 128:	// TransmitTerminalKey
		{
			csaLabels.Add("Terminal key");
		}
		break;

		case 129:	// UnlockProfile
		{
			csaLabels.Add("Password");
		}
		break;

		case 130:	// Wait
		case 135:	// WaitForHostTrigger
		{
			csaLabels.Add("Time (HH:MM:SS:hh)");
			csaLabels.Add("Options");
			bYouShouldGo=FALSE;
		}
		break;

		case 131:	// WaitEvent
		case 136:	// WaitForIncomingData
		{
			csaLabels.Add("Timeout (HH:MM:SS:hh)");
			csaLabels.Add("Allow keystrokes");
			bYouShouldGo=FALSE;
		}
		break;

		case 132:	// WaitEventNumber
		{
			csaLabels.Add("Event");
			csaLabels.Add("Timeout (HH:MM:SS:hh)");
			csaLabels.Add("Options");
			bYouShouldGo=FALSE;
		}
		break;

		case 133:	// WaitForCall
		{
			csaLabels.Add("Description");
			csaLabels.Add("Initialize string");
		}
		break;

		case 134:	// WaitForEvent
		{
			csaLabels.Add("Event type");
			csaLabels.Add("Timeout");
			csaLabels.Add("String");
			csaLabels.Add("Row");
			csaLabels.Add("Column");
			csaLabels.Add("Key");
			csaLabels.Add("Allow keystrokes");
			bYouShouldGo=FALSE;
		}
		break;

		case 137:	// WaitForSilence
		{
			csaLabels.Add("Silence (HH:MM:SS:hh)");
			csaLabels.Add("Timeout (HH:MM:SS:hh)");
			csaLabels.Add("Options");
			bYouShouldGo=FALSE;
		}
		break;

		case 138:	// WaitForString
		{
			csaLabels.Add("String");
			csaLabels.Add("Timeout (HH:MM:SS:hh)");
			csaLabels.Add("Options");
			bYouShouldGo=FALSE;
		}
		break;

		case 139:	// WaitForStrings
		{
			csaLabels.Add("String array");
			csaLabels.Add("Timeout (HH:MM:SS:hh)");
			csaLabels.Add("Options");
			bYouShouldGo=FALSE;
		}
		break;

		case 140:	// WaitUntil
		{
			csaLabels.Add("Date/Time");
			csaLabels.Add("Options");
			bYouShouldGo=FALSE;
		}
		break;

		case 145:	// XmodemReceiveFile
		{
			csaLabels.Add("Local file");
			csaLabels.Add("Transfer type");
			csaLabels.Add("If file exists...");
			bYouShouldGo=FALSE;
		}
		break;

		case 146:	// XmodemSendFile
		{
			csaLabels.Add("Local file");
			csaLabels.Add("Transfer type");
			bYouShouldGo=FALSE;
		}
		break;

		case 147:	// ZmodemReceiveFile
		{
			csaLabels.Add("Local file");
			csaLabels.Add("Transfer type");
			csaLabels.Add("If file exists...");
			bYouShouldGo=FALSE;
		}
		break;

		case 148:	// ZmodemSendFile
		{
			csaLabels.Add("Local file");
			csaLabels.Add("Remote file");
			csaLabels.Add("Transfer type");
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
		ShowMixedControls( RWIN_OLE_API, nFunction, &csaLabels );	
	}

}
