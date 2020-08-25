// Static Model
#include "stdafx.h"
#include "apigen.h"

#include "CAG_ROLE_5250.h"

CAG_ROLE_5250::~CAG_ROLE_5250()
{
	
}

void CAG_ROLE_5250::loadLanguageList(CListBox* listTranslateLanguage)
{
	
}

CAG_ROLE_5250::CAG_ROLE_5250()
{
	
}

void CAG_ROLE_5250::loadFunctionList(CListBox* listTranslateFunction)
{
	csaFunctions.RemoveAll();

	csaFunctions.Add("AbortTransfer");
	csaFunctions.Add("AboutReflectionDlg");
	csaFunctions.Add("ActivateCommandLine");
	csaFunctions.Add("AddHotListItem");
	csaFunctions.Add("AddReference");
	csaFunctions.Add("AddReferenceDlg");
	csaFunctions.Add("AppendSelection");
	csaFunctions.Add("AppendSQLStatement");
	csaFunctions.Add("CancelSelection");
	csaFunctions.Add("CancelTransfer");
	csaFunctions.Add("CheckEvent");			// 10
	
	csaFunctions.Add("CheckEventNumber");
	csaFunctions.Add("ClearEvents");
	csaFunctions.Add("ClearHotlists");
	csaFunctions.Add("ClearHotspots");
	csaFunctions.Add("ClearIBMPrinterFonts");
	csaFunctions.Add("ClearMenu");
	csaFunctions.Add("ClearNWSAA3270Config");
	csaFunctions.Add("ClearSelection");
	csaFunctions.Add("ClosePrinter");
	csaFunctions.Add("CommitLoginProperties");	// 20
	
	csaFunctions.Add("CompileScript");
	csaFunctions.Add("Connect");
	csaFunctions.Add("CopyPasteSettingsDialog");
	csaFunctions.Add("CopySelection");
	csaFunctions.Add("CopyTable");
	csaFunctions.Add("CutSelection");
	csaFunctions.Add("DDESetupDlg");
	csaFunctions.Add("DefineEvent");
	csaFunctions.Add("DefineHotspotEx");
	csaFunctions.Add("DefineToolbarButton");	// 30

	csaFunctions.Add("DeletePopupItem");
	csaFunctions.Add("Disconnect");
	csaFunctions.Add("DisplaySetupDlg");
	csaFunctions.Add("EditMacro");
	csaFunctions.Add("EditScript");
	csaFunctions.Add("EditScriptDlg");
	csaFunctions.Add("EnableInternalTrace");
	csaFunctions.Add("EnableOnEvent");
	csaFunctions.Add("Exit");
	csaFunctions.Add("ExtendSelection");	// 40

	csaFunctions.Add("ExtendSelectionPage");
	csaFunctions.Add("ExtendSelectionRect");
	csaFunctions.Add("ExtendSelectionWord");
	csaFunctions.Add("FindField");
	csaFunctions.Add("FindText");
	csaFunctions.Add("GetBufferedTermKey");
	csaFunctions.Add("GetButtonPictureFile");
	csaFunctions.Add("GetClipboardText");
	csaFunctions.Add("GetCommandProfile");
	csaFunctions.Add("GetCommandRecording");	// 50

	csaFunctions.Add("GetCurrentHotspot");
	csaFunctions.Add("GetCurrentHotspotEx");
	csaFunctions.Add("GetDisplayText");
	csaFunctions.Add("GetErrorString");
	csaFunctions.Add("GetFieldAttributes");
	csaFunctions.Add("GetFieldColor");
	csaFunctions.Add("GetFieldText");
	csaFunctions.Add("GetHotlistItem");
	csaFunctions.Add("GetHotlistItemCommands");
	csaFunctions.Add("GetHotlistItemOptions");	// 60

	csaFunctions.Add("GetHotlistName");
	csaFunctions.Add("GetHotlistOptions");
	csaFunctions.Add("GetHotlistShowPosition");
	csaFunctions.Add("GetHotspotCommandsEx");
	csaFunctions.Add("GetHotspotHelp");
	csaFunctions.Add("GetHotspots");
	csaFunctions.Add("GetHotspotsEx");
	csaFunctions.Add("GetHotspotTip");
	csaFunctions.Add("GetKeymap");
	csaFunctions.Add("GetLastActiveInstance");	// 70

	csaFunctions.Add("GetLoginProperty");
	csaFunctions.Add("GetMouseMap");
	csaFunctions.Add("GetMyWindow");
	csaFunctions.Add("GetNumHotlists");
	csaFunctions.Add("GetNumHotspots");
	csaFunctions.Add("GetNumItems");
	csaFunctions.Add("GetOpenFilename");
	csaFunctions.Add("GetScanCode");
	csaFunctions.Add("GetSetProfile");
	csaFunctions.Add("GetSetStringProfile");	// 80

	csaFunctions.Add("GetSQLStatement");
	csaFunctions.Add("GetVersionNumber");
	csaFunctions.Add("GraphicsMouse");
	csaFunctions.Add("Help");
	csaFunctions.Add("HelpCursor");
	csaFunctions.Add("HotlistSetupDlg");
	csaFunctions.Add("HotspotSetupDlg");
	csaFunctions.Add("IndReceiveFile");
	csaFunctions.Add("IndSendFile");
	csaFunctions.Add("InsertPopupItem");	// 90

	csaFunctions.Add("InternalTraceDlg");
	csaFunctions.Add("IssuePrinterCommand");
	csaFunctions.Add("KeyboardMapSetupDlg");
	csaFunctions.Add("LightPen");
	csaFunctions.Add("MacrosDlg");
	csaFunctions.Add("MenuSetupDlg");
	csaFunctions.Add("MouseMapSetupDlg");
	csaFunctions.Add("MoveCursor");
	csaFunctions.Add("MoveGraphicsCursor");
	csaFunctions.Add("NewHotlist");	// 100

	csaFunctions.Add("NewSession");
	csaFunctions.Add("NewSessionDlg");
	csaFunctions.Add("NewToolbar");
	csaFunctions.Add("OnEvent");
	csaFunctions.Add("OnEventSetupDlg");
	csaFunctions.Add("OpenSettings");
	csaFunctions.Add("OpenSettingsDlg");
	csaFunctions.Add("PageSetupDlg");
	csaFunctions.Add("PasswordBox");
	csaFunctions.Add("Paste");	// 110

	csaFunctions.Add("PasteNext");
	csaFunctions.Add("PasteRange");
	csaFunctions.Add("PasteRangeDlg");
	csaFunctions.Add("PcsReceiveFile");
	csaFunctions.Add("PcsSendFile");
	csaFunctions.Add("PlayBackTrace");
	csaFunctions.Add("PlayBackTraceDlg");
	csaFunctions.Add("PlayNextTraceRecord");
	csaFunctions.Add("PlayPreviousTraceRecord");
	csaFunctions.Add("PreferenceSetupDlg");	// 120

	csaFunctions.Add("Print");
	csaFunctions.Add("PrintControl");
	csaFunctions.Add("PrintDlg");
	csaFunctions.Add("PrintHostFile");
	csaFunctions.Add("PrintScreen");
	csaFunctions.Add("PrintSetupDlg");
	csaFunctions.Add("PrintString");
	csaFunctions.Add("PrintTransparentChar");
	csaFunctions.Add("Quit");
	csaFunctions.Add("ReadQuickTest");					// 130

	csaFunctions.Add("RecordingSetupDlg");
	csaFunctions.Add("RemoveAllToolbars");
	csaFunctions.Add("RemoveEvent");
	csaFunctions.Add("RemoveHotlist");
	csaFunctions.Add("RemoveNWSAA3270Config");
	csaFunctions.Add("RemoveOnEvent");
	csaFunctions.Add("RemoveToolbar");
	csaFunctions.Add("RemoveToolbarButton");
	csaFunctions.Add("ResetCommands");
	csaFunctions.Add("ResetEvent");					// 140

	csaFunctions.Add("RestoreDefaults");
	csaFunctions.Add("RunExternalMacro");
	csaFunctions.Add("RunMacro");
	csaFunctions.Add("RunScript");
	csaFunctions.Add("RunScriptDlg");
	csaFunctions.Add("SaveDisplay");
	csaFunctions.Add("SaveDisplayDlg");
	csaFunctions.Add("SaveSettings");
	csaFunctions.Add("SaveSettingsAsDlg");
	csaFunctions.Add("SaveSettingsDlg");					// 150

	csaFunctions.Add("SaveXML");
	csaFunctions.Add("SelectAll");
	csaFunctions.Add("SelectLine");
	csaFunctions.Add("SelectWord");
	csaFunctions.Add("SendMail");
	csaFunctions.Add("SendMailDlg");
	csaFunctions.Add("SessionSetupDlg");
	csaFunctions.Add("SetAPLKeyMap");
	csaFunctions.Add("SetClipboardText");
	csaFunctions.Add("SetColorMap");					// 160

	csaFunctions.Add("SetCommandProfile");
	csaFunctions.Add("SetCommandRecording");
	csaFunctions.Add("SetDisplayAttribute");
	csaFunctions.Add("SetEncryptedString");
	csaFunctions.Add("SetIBMPrinterFont");
	csaFunctions.Add("SetKeyMap");
	csaFunctions.Add("SetMouseMap");
	csaFunctions.Add("SetMousePos");
	csaFunctions.Add("SetNumeric");
	csaFunctions.Add("SetNumericProfile");				// 170

	csaFunctions.Add("SetRecentlyUsedFile");
	csaFunctions.Add("SetScanCodeName");
	csaFunctions.Add("SetSelectionStartPos");
	csaFunctions.Add("SetSQLStatement");
	csaFunctions.Add("SetString");
	csaFunctions.Add("SetStringProfile");
	csaFunctions.Add("SetTerminalKbdPos");
	csaFunctions.Add("SetTermKeyBuffer");
	csaFunctions.Add("SetToolbarMode");
	csaFunctions.Add("SetToolbarPosition");				// 180

	csaFunctions.Add("SetupNWSAA3270Config");
	csaFunctions.Add("SetupSession");
	csaFunctions.Add("SetWindowsPos");
	csaFunctions.Add("Shell");
	csaFunctions.Add("ShowDBCSHostCodeInputWindow");
	csaFunctions.Add("ShowDisplayAttribute");
	csaFunctions.Add("ShotHotlist");
	csaFunctions.Add("ShowToolbar");
	csaFunctions.Add("ShowToolbarButtonsFixedWidth");
	csaFunctions.Add("ShowToolbarColor");				// 190

	csaFunctions.Add("ShowToolbarLabels");
	csaFunctions.Add("ShowToolbarLarge");
	csaFunctions.Add("ShowToolbarTips");
	csaFunctions.Add("StartInternalTrace");
	csaFunctions.Add("StartRecording");
	csaFunctions.Add("StartTrace");
	csaFunctions.Add("StartTraceDlg");
	csaFunctions.Add("StopInternalTrace");
	csaFunctions.Add("StopMacro");
	csaFunctions.Add("StopRecording");					// 200

	csaFunctions.Add("StopRecordingDlg");
	csaFunctions.Add("StopRecordingMacro");
	csaFunctions.Add("StopScript");
	csaFunctions.Add("StopTrace");
	csaFunctions.Add("SwitchToWindow");
	csaFunctions.Add("TerminalMouse");
	csaFunctions.Add("TerminalSetupDlg");
	csaFunctions.Add("TetherToolbar");
	csaFunctions.Add("Toggle");
	csaFunctions.Add("ToobarSetupDlg");					// 210

	csaFunctions.Add("TransferDlg");
	csaFunctions.Add("TransferSetupDlg");
	csaFunctions.Add("TransformXML");
	csaFunctions.Add("TransmitAnsi");
	csaFunctions.Add("TransmitTerminalKey");
	csaFunctions.Add("ViewSettingsDlg");
	csaFunctions.Add("Wait");
	csaFunctions.Add("WaitEvent");
	csaFunctions.Add("WaitEventNumber");
	csaFunctions.Add("WaitForCommString");				// 220

	csaFunctions.Add("WaitForDisplayString");
	csaFunctions.Add("WaitForEvent");
	csaFunctions.Add("WaitForPrinterStatusString");
	csaFunctions.Add("WaitForPrinterString");
	csaFunctions.Add("WaitForPrinterStringReplace");
	csaFunctions.Add("WaitForTerminalKey");
	csaFunctions.Add("WaitForTimeOfDay");
	csaFunctions.Add("WriteQuickText");					// 228



	listTranslateFunction->ResetContent();	
	
	for (int k=0; k<csaFunctions.GetSize(); k++)
	{
		listTranslateFunction->AddString( csaFunctions.GetAt(k) );
	}

	listTranslateFunction->SetCurSel(0);
	
}