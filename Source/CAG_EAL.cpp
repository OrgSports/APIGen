// Static Model
#include "stdafx.h"
#include "apigen.h"

#include "CAG_EAL.h"

CAG_EAL::CAG_EAL()
{
	APIFlavor=EAL_API;
}

CAG_EAL::~CAG_EAL()
{
	
}

void CAG_EAL::loadFunctionList(CListBox* listTranslateFunction)
{
	csaFunctions.RemoveAll();

	csaFunctions.Add("ATMAddWait");
	csaFunctions.Add("ATMAddWaitForCursor");
	csaFunctions.Add("ATMAddWaitForCursorMove");
	csaFunctions.Add("ATMAddWaitForHostConnect");
	csaFunctions.Add("ATMAddWaitForHostDisconnect");
	csaFunctions.Add("ATMAddWaitForKey");
	csaFunctions.Add("ATMAddWaitForString");
	csaFunctions.Add("ATMAddWaitForStringNotAt");
	csaFunctions.Add("ATMAddWaitHostQuiet");
	csaFunctions.Add("ATMAllowUpdates");
	csaFunctions.Add("ATMBlockUpdates");			// 10
	csaFunctions.Add("ATMClearEventTable");
	csaFunctions.Add("ATMConnectSession");
	csaFunctions.Add("ATMDeleteEvent");
	csaFunctions.Add("ATMDisconnectSession");
	csaFunctions.Add("ATMExecute");
	csaFunctions.Add("ATMGetATMAPIVersion");
	csaFunctions.Add("ATMGetConnectionStatus");
	csaFunctions.Add("ATMGetCursorLocation ");
	csaFunctions.Add("ATMGetEmulatorPath");
	csaFunctions.Add("ATMGetEmulatorVersion ");		// 20
	csaFunctions.Add("ATMGetError");
	csaFunctions.Add("ATMGetFieldInfo");
	csaFunctions.Add("ATMGetFieldLength");
	csaFunctions.Add("ATMGetFieldPosition");
	csaFunctions.Add("ATMGetKeystroke");
	csaFunctions.Add("ATMGetLayoutName");
	csaFunctions.Add("ATMGetParameter");
	csaFunctions.Add("ATMGetSessionHandle");
	csaFunctions.Add("ATMGetSessions");
	csaFunctions.Add("ATMGetSessionSize");			// 30
	csaFunctions.Add("ATMGetSessionStatus");
	csaFunctions.Add("ATMGetString");
	csaFunctions.Add("ATMGetStringFromField");
	csaFunctions.Add("ATMHoldHost");
	csaFunctions.Add("ATMListSessions");
	csaFunctions.Add("ATMLockKeyboard");
	csaFunctions.Add("ATMOpenLayout");
	csaFunctions.Add("ATMPause");
	csaFunctions.Add("ATMReceiveFile");
	csaFunctions.Add("ATMRegisterClient");			// 40
	csaFunctions.Add("ATMResetSystem");
	csaFunctions.Add("ATMResumeHost");
	csaFunctions.Add("ATMRowColumn");
	csaFunctions.Add("ATMRunEmulatorMacro");
	csaFunctions.Add("ATMSearchField");
	csaFunctions.Add("ATMSearchSession");
	csaFunctions.Add("ATMSendAndWait");
	csaFunctions.Add("ATMSendFile");
	csaFunctions.Add("ATMSendKey");
	csaFunctions.Add("ATMSendString");				// 50
	csaFunctions.Add("ATMSendStringToField");
	csaFunctions.Add("ATMSessionOff");
	csaFunctions.Add("ATMSessionOn");
	csaFunctions.Add("ATMSetCursorLocation");
	csaFunctions.Add("ATMSetParameter");
	csaFunctions.Add("ATMShowLastError");
	csaFunctions.Add("ATMStartKeystrokeIntercept");
	csaFunctions.Add("ATMStartSession");
	csaFunctions.Add("ATMStopKeystrokeIntercept");
	csaFunctions.Add("ATMStopSession");			// 60
	csaFunctions.Add("ATMUnlockKeyboard");
	csaFunctions.Add("ATMUnregisterClient ");
	csaFunctions.Add("ATMWait ");
	csaFunctions.Add("ATMWaitForCursor");
	csaFunctions.Add("ATMWaitForCursorMove");
	csaFunctions.Add("ATMWaitForEvent");
	csaFunctions.Add("ATMWaitForHostConnect");
	csaFunctions.Add("ATMWaitForHostDisconnect");
	csaFunctions.Add("ATMWaitForKey");
	csaFunctions.Add("ATMWaitForString");		// 70
	csaFunctions.Add("ATMWaitHostQuiet");

	
	listTranslateFunction->ResetContent();	
	
	for (int k=0; k<csaFunctions.GetSize(); k++)
	{
		listTranslateFunction->AddString( csaFunctions.GetAt(k) );
	}

	listTranslateFunction->SetCurSel(0);
	
}

void CAG_EAL::loadLanguageList(CListBox* listTranslateLanguage)
{
	int nPos = 0;

	listTranslateLanguage->ResetContent();
	listTranslateLanguage->InsertString( nPos++, "C++" );
	listTranslateLanguage->InsertString( nPos++, "C#" );
	listTranslateLanguage->InsertString( nPos++, "VB 6.0" );
	listTranslateLanguage->InsertString( nPos++, "VB.Net" );
	
	listTranslateLanguage->SetCurSel(0);
	
}

void CAG_EAL::declareVariable(AG_VARIABLE agVariable,
							  CStringArray* pcsaHeader,
							  bool* bValue)
{
	
}

void CAG_EAL::loadTerminalTypeList(CListBox* listTerminalTypes)
{
	int nPos = 0;

	listTerminalTypes->ResetContent();
	listTerminalTypes->InsertString( nPos++, "3270" );
	listTerminalTypes->InsertString( nPos++, "5250" );
	listTerminalTypes->InsertString( nPos++, "VT" );
	
	listTerminalTypes->SetCurSel(0);
}
