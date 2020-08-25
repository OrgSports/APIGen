// Static Model
#include "stdafx.h"
#include "apigen.h"

#include "CAG_ROLE_HP_CPP.h"

CAG_ROLE_HP_CPP::CAG_ROLE_HP_CPP()
{
	resetVariableFlags();	
}

CAG_ROLE_HP_CPP::~CAG_ROLE_HP_CPP()
{
	
}


void CAG_ROLE_HP_CPP::generateHeader(CStringArray* pcsaHeader,
									   CStringArray* pcsaBody)
{

	CString csViewOutStuff;

	csViewOutStuff.Format( "//  ****************************************************************************");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "//                        Attachmate APIGen");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "//                    Reflection For HP C++ Program");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "// ");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "//  This file is a program that features the use of the Reflection for HP");
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


void CAG_ROLE_HP_CPP::appendBody(int nFunctionNum,
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

		case 1:		// Activate
		case 2:		// BackgroundColor
		case 3:		// Break
		case 4:		// CancelExitEvent
		case 5:		// CancelTransfer
		case 6:		// CharacterAttributes
		case 7:		// CheckEvent
		case 8:		// CheckEventNumber
		case 9:		// Clear					// 10

		case 10:		// ClearEvents
		case 11:		// CloseAllConnections
		case 12:		// CloseStatusBox
		case 13:		// CommitLoginProperties
		case 14:		// CompileScript
		case 15:		// Connect
		case 16:		// ConnectionSetting
		case 17:		// ConnectTemplate
		case 18:		// Copy
		case 19:		// CopyAboutBoxInfo			// 20

		case 20:		// DDEExecute
		case 21:		// DDEInitiate
		case 22:		// DDEPoke
		case 23:		// DDEQueryServerTopics
		case 24:		// DDERequest
		case 25:		// DDETerminate
		case 26:		// DDETerminateAll
		case 27:		// DefineEvent
		case 28:		// DestroyToolbar
		case 29:		// Dial						// 30

		case 30:		// Disconnect
		case 31:		// Display
		case 32:		// DisplayFile
		case 33:		// DropDTR
		case 34:		// EditScript
		case 35:		// EnableOnEvent
		case 36:		// EvaluateRCLExpression
		case 37:		// EvaluateBuiltInFunction
		case 38:		// ExecuteRCLCommand
		case 39:		// FindText					// 40

		case 40:		// FlashWindow
		case 41:		// FlushPrinter
		case 42:		// ForegroundColor
		case 43:		// FTPGetCurrentHostDirectory
		case 44:		// FTPReceiveFile
		case 45:		// FTPSendFile
		case 46:		// FTPSetCurrentHostDirectory
		case 47:		// FTPStartServer
		case 48:		// FTPStopServer
		case 49:		// GetAnsiColorRGB			// 50

		case 50:		// GetClipboardText
		case 51:		// GetColorRGB
		case 52:		// GetCommandGroupProfile
		case 53:		// GetCommandProfile
		case 54:		// GetFileType
		case 55:		// GetFolderName
		case 56:		// GetKeymapCommandArgs
		case 57:		// GetKeymapCommands
		case 58:		// GetKeymapCommandType
		case 59:		// GetLoginProperty			// 60

		case 60:		// GetOpenFilename
		case 61:		// GetPassword
		case 62:		// GetPropertyInformation
		case 63:		// GetSaveAsFilename
		case 64:		// GetSerialStatistics
		case 65:		// GetText
		case 66:		// Hangup
		case 67:		// Help
		case 68:		// InputBox
		case 69:		// KermitReceiveFile			// 70

		case 70:		// KermitSendFile
		case 71:		// KermitStartServer
		case 72:		// KermitStopServer
		case 73:		// LockProfile
		case 74:		// MsgBox
		case 75:		// NewSession
		case 76:		// OnEvent
		case 77:		// OpenSettings
		case 78:		// OpenSettingsExtended
		case 79:		// PasswordBox				// 80

		case 80:		// Paste
		case 81:		// PlaySound
		case 82:		// Print
		case 83:		// PrintFile
		case 84:		// PrintScreen
		case 85:		// PrintString
		case 86:		// PropertyIsModifiable
		case 87:		// Quit
		case 88:		// RaiseControlEvent
		case 89:		// ReadChars					// 90

		case 90:		// ReadLine
		case 91:		// ReadUntil
		case 92:		// RemoveEvent
		case 93:		// RemoveOnEvent
		case 94:		// ResetEvent
		case 95:		// ResetTerminal
		case 96:		// RestoreDefaults
		case 97:		// ResumeConnection
		case 98:		// RunExternalMacro
		case 99:		// RunMacro					// 100

		case 100:		// RunScript
		case 101:		// SaveDisplayMemory
		case 102:		// SaveSettings
		case 103:		// SelectText
		case 104:		// SetAnsiColorRGB
		case 105:		// SetClipboardText
		case 106:		// SetColorMap
		case 107:		// SetColorRGB
		case 108:		// SetCommandGroupProfile
		case 109:		// SetCommandProfile			// 110

		case 110:		// SetKeyMap
		case 111:		// SetMouseMap
		case 112:		// SetPropertyProfile
		case 113:		// SetScanCodeName
		case 114:		// Shell
		case 115:		// StartRecording
		case 116:		// StartRecordingExtended
		case 117:		// StartRecordingSilently
		case 118:		// StartTrace
		case 119:		// StatusBox					// 120

		case 120:		// StopMacro
		case 121:		// StopRecording
		case 122:		// StopRecordingMacro
		case 123:		// StopScript
		case 124:		// StopTrace
		case 125:		// SuspendConnection
		case 126:		// Transmit
		case 127:		// TransmitFile
		case 128:		// TransmitTerminalKey
		case 129:		// UnlockProfile				// 130

		case 130:		// Wait
		case 131:		// WaitEvent
		case 132:		// WaitEventNumber
		case 133:		// WaitForCall
		case 134:		// WaitForEvent
		case 135:		// WaitForHostTrigger
		case 136:		// WaitForIncomingData
		case 137:		// WaitForSilence
		case 138:		// WaitForString
		case 139:		// WaitForStrings				// 140

		case 140:		// WaitUntil
		case 141:		// WRQReceiveFile
		case 142:		// WRQSendFile
		case 143:		// WRQStartServer
		case 144:		// WRQStopServer
		case 145:		// XmodemReceiveFile
		case 146:		// XmodemSendFile
		case 147:		// ZmodemReceiveFile
		case 148:		// ZmodemSendFile				// 149
		{
			csViewOutStuff.Format( "   // APIGen has not yet implemented this method." );
			pcsaBody->Add(csViewOutStuff);
		}
		break;

	}

	pcsaArguments->RemoveAll();
}


void CAG_ROLE_HP_CPP::finalize(CStringArray* pcsaBody)
{
	CString csViewOutStuff;

	csViewOutStuff.Format( " " );
	pcsaBody->Add(csViewOutStuff);

	csViewOutStuff.Format( "   return;");
	pcsaBody->Add(csViewOutStuff);

	csViewOutStuff.Format( "} " );
	pcsaBody->Add(csViewOutStuff);

}


void CAG_ROLE_HP_CPP::declareVariable(AG_VARIABLE agVariable,
										CStringArray* pcsaHeader,
										bool* bValue)
{
	
}

void CAG_ROLE_HP_CPP::checkDebug(bool b_Debug,
								   CString csFunctionName,
								   CStringArray* pcsaBody)
{
	
}

void CAG_ROLE_HP_CPP::resetVariableFlags()
{
}

