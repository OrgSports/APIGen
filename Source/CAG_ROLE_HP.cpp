// Static Model
#include "stdafx.h"
#include "apigen.h"

#include "CAG_ROLE_HP.h"

CAG_ROLE_HP::~CAG_ROLE_HP()
{
	
}

void CAG_ROLE_HP::loadLanguageList(CListBox* listTranslateLanguage)
{
	
}

CAG_ROLE_HP::CAG_ROLE_HP()
{
	
}

void CAG_ROLE_HP::loadFunctionList(CListBox* listTranslateFunction)
{
	csaFunctions.RemoveAll();

	csaFunctions.Add("AbortTransfer");
	csaFunctions.Add("Activate");
	csaFunctions.Add("BackgroundColor");
	csaFunctions.Add("Break");
	csaFunctions.Add("CancelExitEvent");
	csaFunctions.Add("CancelTransfer");
	csaFunctions.Add("CharacterAttributes");
	csaFunctions.Add("CheckEvent");
	csaFunctions.Add("CheckEventNumber");
	csaFunctions.Add("Clear");						// 10

	csaFunctions.Add("ClearEvents");
	csaFunctions.Add("CloseAllConnections");
	csaFunctions.Add("CloseStatusBox");
	csaFunctions.Add("CommitLoginProperties");
	csaFunctions.Add("CompileScript");
	csaFunctions.Add("Connect");
	csaFunctions.Add("ConnectionSetting");
	csaFunctions.Add("ConnectTemplate");
	csaFunctions.Add("Copy");
	csaFunctions.Add("CopyAboutBoxInfo");			// 20

	csaFunctions.Add("DDEExecute");
	csaFunctions.Add("DDEInitiate");
	csaFunctions.Add("DDEPoke");
	csaFunctions.Add("DDEQueryServerTopics");
	csaFunctions.Add("DDERequest");
	csaFunctions.Add("DDETerminate");
	csaFunctions.Add("DDETerminateAll");
	csaFunctions.Add("DefineEvent");
	csaFunctions.Add("DestroyToolbar");
	csaFunctions.Add("Dial");						// 30

	csaFunctions.Add("Disconnect");
	csaFunctions.Add("Display");
	csaFunctions.Add("DisplayFile");
	csaFunctions.Add("DropDTR");
	csaFunctions.Add("EditScript");
	csaFunctions.Add("EnableOnEvent");
	csaFunctions.Add("EvaluateRCLExpression");
	csaFunctions.Add("EvaluateBuiltInFunction");
	csaFunctions.Add("ExecuteRCLCommand");
	csaFunctions.Add("FindText");					// 40

	csaFunctions.Add("FlashWindow");
	csaFunctions.Add("FlushPrinter");
	csaFunctions.Add("ForegroundColor");
	csaFunctions.Add("FTPGetCurrentHostDirectory");
	csaFunctions.Add("FTPReceiveFile");
	csaFunctions.Add("FTPSendFile");
	csaFunctions.Add("FTPSetCurrentHostDirectory");
	csaFunctions.Add("FTPStartServer");
	csaFunctions.Add("FTPStopServer");
	csaFunctions.Add("GetAnsiColorRGB");			// 50

	csaFunctions.Add("GetClipboardText");
	csaFunctions.Add("GetColorRGB");
	csaFunctions.Add("GetCommandGroupProfile");
	csaFunctions.Add("GetCommandProfile");
	csaFunctions.Add("GetFileType");
	csaFunctions.Add("GetFolderName");
	csaFunctions.Add("GetKeymapCommandArgs");
	csaFunctions.Add("GetKeymapCommands");
	csaFunctions.Add("GetKeymapCommandType");
	csaFunctions.Add("GetLoginProperty");			// 60

	csaFunctions.Add("GetOpenFilename");
	csaFunctions.Add("GetPassword");
	csaFunctions.Add("GetPropertyInformation");
	csaFunctions.Add("GetSaveAsFilename");
	csaFunctions.Add("GetSerialStatistics");
	csaFunctions.Add("GetText");
	csaFunctions.Add("Hangup");
	csaFunctions.Add("Help");
	csaFunctions.Add("InputBox");
	csaFunctions.Add("KermitReceiveFile");			// 70

	csaFunctions.Add("KermitSendFile");
	csaFunctions.Add("KermitStartServer");
	csaFunctions.Add("KermitStopServer");
	csaFunctions.Add("LockProfile");
	csaFunctions.Add("MsgBox");
	csaFunctions.Add("NewSession");
	csaFunctions.Add("OnEvent");
	csaFunctions.Add("OpenSettings");
	csaFunctions.Add("OpenSettingsExtended");
	csaFunctions.Add("PasswordBox");				// 80

	csaFunctions.Add("Paste");
	csaFunctions.Add("PlaySound");
	csaFunctions.Add("Print");
	csaFunctions.Add("PrintFile");
	csaFunctions.Add("PrintScreen");
	csaFunctions.Add("PrintString");
	csaFunctions.Add("PropertyIsModifiable");
	csaFunctions.Add("Quit");
	csaFunctions.Add("RaiseControlEvent");
	csaFunctions.Add("ReadChars");					// 90

	csaFunctions.Add("ReadLine");
	csaFunctions.Add("ReadUntil");
	csaFunctions.Add("RemoveEvent");
	csaFunctions.Add("RemoveOnEvent");
	csaFunctions.Add("ResetEvent");
	csaFunctions.Add("ResetTerminal");
	csaFunctions.Add("RestoreDefaults");
	csaFunctions.Add("ResumeConnection");
	csaFunctions.Add("RunExternalMacro");
	csaFunctions.Add("RunMacro");					// 100

	csaFunctions.Add("RunScript");
	csaFunctions.Add("SaveDisplayMemory");
	csaFunctions.Add("SaveSettings");
	csaFunctions.Add("SelectText");
	csaFunctions.Add("SetAnsiColorRGB");
	csaFunctions.Add("SetClipboardText");
	csaFunctions.Add("SetColorMap");
	csaFunctions.Add("SetColorRGB");
	csaFunctions.Add("SetCommandGroupProfile");
	csaFunctions.Add("SetCommandProfile");			// 110

	csaFunctions.Add("SetKeyMap");
	csaFunctions.Add("SetMouseMap");
	csaFunctions.Add("SetPropertyProfile");
	csaFunctions.Add("SetScanCodeName");
	csaFunctions.Add("Shell");
	csaFunctions.Add("StartRecording");
	csaFunctions.Add("StartRecordingExtended");
	csaFunctions.Add("StartRecordingSilently");
	csaFunctions.Add("StartTrace");
	csaFunctions.Add("StatusBox");					// 120

	csaFunctions.Add("StopMacro");
	csaFunctions.Add("StopRecording");
	csaFunctions.Add("StopRecordingMacro");
	csaFunctions.Add("StopScript");
	csaFunctions.Add("StopTrace");
	csaFunctions.Add("SuspendConnection");
	csaFunctions.Add("Transmit");
	csaFunctions.Add("TransmitFile");
	csaFunctions.Add("TransmitTerminalKey");
	csaFunctions.Add("UnlockProfile");				// 130

	csaFunctions.Add("Wait");
	csaFunctions.Add("WaitEvent");
	csaFunctions.Add("WaitEventNumber");
	csaFunctions.Add("WaitForCall");
	csaFunctions.Add("WaitForEvent");
	csaFunctions.Add("WaitForHostTrigger");
	csaFunctions.Add("WaitForIncomingData");
	csaFunctions.Add("WaitForSilence");
	csaFunctions.Add("WaitForString");
	csaFunctions.Add("WaitForStrings");				// 140

	csaFunctions.Add("WaitUntil");
	csaFunctions.Add("WRQReceiveFile");
	csaFunctions.Add("WRQSendFile");
	csaFunctions.Add("WRQStartServer");
	csaFunctions.Add("WRQStopServer");
	csaFunctions.Add("XmodemReceiveFile");
	csaFunctions.Add("XmodemSendFile");
	csaFunctions.Add("ZmodemReceiveFile");
	csaFunctions.Add("ZmodemSendFile");				// 149


	listTranslateFunction->ResetContent();	
	
	for (int k=0; k<csaFunctions.GetSize(); k++)
	{
		listTranslateFunction->AddString( csaFunctions.GetAt(k) );
	}

	listTranslateFunction->SetCurSel(0);
	
}