// Static Model
#include "stdafx.h"
#include "apigen.h"

#include "CAG_RWEB_3270.h"

CAG_RWEB_3270::CAG_RWEB_3270()
{
	
}

CAG_RWEB_3270::~CAG_RWEB_3270()
{
	
}

void CAG_RWEB_3270::loadFunctionList(CListBox* listTranslateFunction)
{
	csaFunctions.RemoveAll();

	csaFunctions.Add("ECLField::clearField");	// 0
	csaFunctions.Add("ECLField::equals");
	csaFunctions.Add("ECLField::GetAttribute");
	csaFunctions.Add("ECLField::GetEnd");
	csaFunctions.Add("ECLField::GetEndCol");
	csaFunctions.Add("ECLField::GetEndRow");
	csaFunctions.Add("ECLField::GetLength");
	csaFunctions.Add("ECLField::GetScreen");
	csaFunctions.Add("ECLField::GetScreen 2");
	csaFunctions.Add("ECLField::GetStart");
	csaFunctions.Add("ECLField::GetStartCol");	// 10
	csaFunctions.Add("ECLField::GetStartRow");
	csaFunctions.Add("ECLField::GetString");
	csaFunctions.Add("ECLField::GetString 2");
	csaFunctions.Add("ECLField::IsDisplay");
	csaFunctions.Add("ECLField::IsHighIntensity");
	csaFunctions.Add("ECLField::IsModified");
	csaFunctions.Add("ECLField::IsNumeric");
	csaFunctions.Add("ECLField::IsPenDetectable");
	csaFunctions.Add("ECLField::IsProtected");
	csaFunctions.Add("ECLField::IsTransmitOnly");	// 20
	csaFunctions.Add("ECLField::SetString");
	csaFunctions.Add("ECLField::SetText");
	
	csaFunctions.Add("ECLFieldList::FindField");
	csaFunctions.Add("ECLFieldList::FindField 2");
	csaFunctions.Add("ECLFieldList::FindField 3");
	csaFunctions.Add("ECLFieldList::FindField 4");
	csaFunctions.Add("ECLFieldList::FindField 5");
	csaFunctions.Add("ECLFieldList::GetFieldCount");
	csaFunctions.Add("ECLFieldList::GetFirstField");
	csaFunctions.Add("ECLFieldList::GetFirstField 2");	//30
	csaFunctions.Add("ECLFieldList::GetNextField");
	csaFunctions.Add("ECLFieldList::GetNextField 2");
	csaFunctions.Add("ECLFieldList::Refresh");
	csaFunctions.Add("ECLFieldList::Refresh 2");

	csaFunctions.Add("ECLOIA::GetHPStatusFlags");
	csaFunctions.Add("ECLOIA::GetParent");
	csaFunctions.Add("ECLOIA::GetStatusFlags");
	csaFunctions.Add("ECLOIA::InputInhibited");
	csaFunctions.Add("ECLOIA::IsAlphanumeric");
	csaFunctions.Add("ECLOIA::IsCommErrorReminder");	// 40
	csaFunctions.Add("ECLOIA::IsDBCS");
	csaFunctions.Add("ECLOIA::IsHPBlockMode");
	csaFunctions.Add("ECLOIA::IsHPFormatMode");
	csaFunctions.Add("ECLOIA::IsInsertMode");
	csaFunctions.Add("ECLOIA::IsMessageWaiting");
	csaFunctions.Add("ECLOIA::IsNumeric");
	csaFunctions.Add("ECLOIA::RegisterOIAEvent");
	csaFunctions.Add("ECLOIA::setKeyboardUnlockDuration");
	csaFunctions.Add("ECLOIA::UnregisterOIAEvent");
	csaFunctions.Add("ECLOIA::WaitForInput");			// 50
	csaFunctions.Add("ECLOIA::WaitForInput 2");

	csaFunctions.Add("ECLPS::ConvertPosToCol");
	csaFunctions.Add("ECLPS::ConvertPosToColX");
	csaFunctions.Add("ECLPS::ConvertPosToRow");
	csaFunctions.Add("ECLPS::ConvertPosToRowX");
	csaFunctions.Add("ECLPS::ConvertRowColToPos");
	csaFunctions.Add("ECLPS::ConvertRowColToPosX");
	csaFunctions.Add("ECLPS::GetCursorCol");
	csaFunctions.Add("ECLPS::GetCursorPos");
	csaFunctions.Add("ECLPS::GetCursorRow");				// 60
	csaFunctions.Add("ECLPS::GetCursorVisible");
	csaFunctions.Add("ECLPS::GetFieldList");
	csaFunctions.Add("ECLPS::GetFieldList");
	csaFunctions.Add("ECLPS::GetParent");
	csaFunctions.Add("ECLPS::GetPosForRowFromEnd");
	csaFunctions.Add("ECLPS::getRow");
	csaFunctions.Add("ECLPS::GetScreen");
	csaFunctions.Add("ECLPS::GetScreen 2");
	csaFunctions.Add("ECLPS::GetScreen 3");
	csaFunctions.Add("ECLPS::GetScreen 4");					// 70
	csaFunctions.Add("ECLPS::GetScreen 5");
	csaFunctions.Add("ECLPS::GetScreen 6");
	csaFunctions.Add("ECLPS::GetScreenRect");
	csaFunctions.Add("ECLPS::GetScreenRect 2");
	csaFunctions.Add("ECLPS::GetScreenRect 3");
	csaFunctions.Add("ECLPS::GetScreenRect 4");
	csaFunctions.Add("ECLPS::GetSendKeyMnemonics");
	csaFunctions.Add("ECLPS::getSendKeysKeyboardUnlockTimeout");
	csaFunctions.Add("ECLPS::GetSize");
	csaFunctions.Add("ECLPS::GetSizeCols");					// 80
	csaFunctions.Add("ECLPS::GetSizeRows");
	csaFunctions.Add("ECLPS::GetString");
	csaFunctions.Add("ECLPS::GetString 2");
	csaFunctions.Add("ECLPS::GetString 3");
	csaFunctions.Add("ECLPS::GetString 4");
	csaFunctions.Add("ECLPS::GetString 5");
	csaFunctions.Add("ECLPS::GetString 6");
	csaFunctions.Add("ECLPS::RegisterPSEvent");
	csaFunctions.Add("ECLPS::RegisterPSEvent 2");
	csaFunctions.Add("ECLPS::SearchString");				// 90
	csaFunctions.Add("ECLPS::SearchString 2");
	csaFunctions.Add("ECLPS::SearchString 3");
	csaFunctions.Add("ECLPS::SearchText");
	csaFunctions.Add("ECLPS::SearchText 2");
	csaFunctions.Add("ECLPS::SearchText 3");
	csaFunctions.Add("ECLPS::SendKeys");
	csaFunctions.Add("ECLPS::SendKeys 2");
	csaFunctions.Add("ECLPS::SendKeys 3");
	csaFunctions.Add("ECLPS::SetCursorPos");
	csaFunctions.Add("ECLPS::SetCursorPos 2");				// 100
	csaFunctions.Add("ECLPS::SetCursorVisible");
	csaFunctions.Add("ECLPS::setSendKeysKeyboardUnlockTimeout");
	csaFunctions.Add("ECLPS::SetString");
	csaFunctions.Add("ECLPS::SetString 2");
	csaFunctions.Add("ECLPS::SetString 3");
	csaFunctions.Add("ECLPS::SetText");
	csaFunctions.Add("ECLPS::SetText 2");
	csaFunctions.Add("ECLPS::SetText 3");
	csaFunctions.Add("ECLPS::spacePadString");
	csaFunctions.Add("ECLPS::UnregisterPSEvent");				// 110
	csaFunctions.Add("ECLPS::UnregisterPSEvent 2");
	csaFunctions.Add("ECLPS::WaitForCursor");
	csaFunctions.Add("ECLPS::WaitForCursor 2");
	csaFunctions.Add("ECLPS::WaitForHostPrompt");
	csaFunctions.Add("ECLPS::WaitForHostPrompt 2");
	csaFunctions.Add("ECLPS::WaitForScreen");
	csaFunctions.Add("ECLPS::WaitForScreen 2");
	csaFunctions.Add("ECLPS::WaitForString");
	csaFunctions.Add("ECLPS::WaitForString 2");
	csaFunctions.Add("ECLPS::WaitForString 3");					// 120
	csaFunctions.Add("ECLPS::WaitWhileCursor");
	csaFunctions.Add("ECLPS::WaitWhileCursor 2");
	csaFunctions.Add("ECLPS::WaitWhileScreen");
	csaFunctions.Add("ECLPS::WaitWhileScreen 2");
	csaFunctions.Add("ECLPS::WaitWhileString");
	csaFunctions.Add("ECLPS::WaitWhileString 2");
	csaFunctions.Add("ECLPS::WaitWhileString 3");
	
	csaFunctions.Add("ECLSession::addMessageServiceListener");
	csaFunctions.Add("ECLSession::apiExit");
	csaFunctions.Add("ECLSession::apvuReceiveFile");		// 130
	csaFunctions.Add("ECLSession::apvuSendFile");
	csaFunctions.Add("ECLSession::cancelFileXfer");
	csaFunctions.Add("ECLSession::cancelPrintJob");
	csaFunctions.Add("ECLSession::closePrinter");
	csaFunctions.Add("ECLSession::connect");
	csaFunctions.Add("ECLSession::disconnect");
	csaFunctions.Add("ECLSession::display");
	csaFunctions.Add("ECLSession::dispose");
	csaFunctions.Add("ECLSession::doJavaScriptCall");
	csaFunctions.Add("ECLSession::doJavaScriptEval");		// 140
	csaFunctions.Add("ECLSession::endPrintJob");
	csaFunctions.Add("ECLSession::exit");
	csaFunctions.Add("ECLSession::exportKeymap");
	csaFunctions.Add("ECLSession::findField");
	csaFunctions.Add("ECLSession::findText");
	csaFunctions.Add("ECLSession::flushPrintJob");
	csaFunctions.Add("ECLSession::ftpAbort");
	csaFunctions.Add("ECLSession::ftpCd");
	csaFunctions.Add("ECLSession::ftpDisconnect");
	csaFunctions.Add("ECLSession::ftpGetLastServerResponse");	// 150
	csaFunctions.Add("ECLSession::ftpLCd");
	csaFunctions.Add("ECLSession::ftpLogin");
	csaFunctions.Add("ECLSession::ftpPwd");
	csaFunctions.Add("ECLSession::ftpReceiveFile");
	csaFunctions.Add("ECLSession::ftpReceiveFiles");
	csaFunctions.Add("ECLSession::ftpSendFile");
	csaFunctions.Add("ECLSession::ftpSendFiles");
	csaFunctions.Add("ECLSession::getBoolean");
	csaFunctions.Add("ECLSession::getCursorColumn");
	csaFunctions.Add("ECLSession::getCursorPosition");		// 160
	csaFunctions.Add("ECLSession::getCursorRow");
	csaFunctions.Add("ECLSession::getDisplayText");
	csaFunctions.Add("ECLSession::getDisplayText");
	csaFunctions.Add("ECLSession::getEmulatorApplet");
	csaFunctions.Add("ECLSession::getFieldText");
	csaFunctions.Add("ECLSession::getFrameBounds");
	csaFunctions.Add("ECLSession::getHostName");
	csaFunctions.Add("ECLSession::getHostStatusText");
	csaFunctions.Add("ECLSession::getHostURL");
	csaFunctions.Add("ECLSession::getInteger");				// 170
	csaFunctions.Add("ECLSession::getJSAPI");
	csaFunctions.Add("ECLSession::GetOIA");
	csaFunctions.Add("ECLSession::getParameter");
	csaFunctions.Add("ECLSession::getPort");
	csaFunctions.Add("ECLSession::getPrinterMargin");
	csaFunctions.Add("ECLSession::getPrinterPageSize");
	csaFunctions.Add("ECLSession::getPrintScaling");
	csaFunctions.Add("ECLSession::getPrintToFileFolder");
	csaFunctions.Add("ECLSession::getPrintToFileName");
	csaFunctions.Add("ECLSession::GetPS");					// 180
	csaFunctions.Add("ECLSession::getSelectionBounds");
	csaFunctions.Add("ECLSession::getString");
	csaFunctions.Add("ECLSession::GetXfer");
	csaFunctions.Add("ECLSession::importKeymap");
	csaFunctions.Add("ECLSession::indReceiveFile");
	csaFunctions.Add("ECLSession::indSendFile");
	csaFunctions.Add("ECLSession::isConnected");
	csaFunctions.Add("ECLSession::isIBM");
	csaFunctions.Add("ECLSession::isStream");
	csaFunctions.Add("ECLSession::loadComponent");			// 190
	csaFunctions.Add("ECLSession::makeTextSelection");
	csaFunctions.Add("ECLSession::passwordPrompt");
	csaFunctions.Add("ECLSession::playbackMacro");
	csaFunctions.Add("ECLSession::printBytes");
	csaFunctions.Add("ECLSession::printCharacter");
	csaFunctions.Add("ECLSession::printString");
	csaFunctions.Add("ECLSession::printTestPage");
	csaFunctions.Add("ECLSession::removeMessageServiceListener");
	csaFunctions.Add("ECLSession::requestDisplayFocus");
	csaFunctions.Add("ECLSession::resetUserPreferences");		// 200
	csaFunctions.Add("ECLSession::saveUserPreferences");
	csaFunctions.Add("ECLSession::screenPrint");
	csaFunctions.Add("ECLSession::setBoolean");
	csaFunctions.Add("ECLSession::setCursorPosition");
	csaFunctions.Add("ECLSession::setHostURL");
	csaFunctions.Add("ECLSession::setInteger");
	csaFunctions.Add("ECLSession::setPrinterMargin");
	csaFunctions.Add("ECLSession::setPrinterPageSize");
	csaFunctions.Add("ECLSession::setPrintScaling");
	csaFunctions.Add("ECLSession::setPrintToFileFolder");		// 210
	csaFunctions.Add("ECLSession::setPrintToFileName");
	csaFunctions.Add("ECLSession::setString");
	csaFunctions.Add("ECLSession::showDialog");
	csaFunctions.Add("ECLSession::ShowPSDebugger");
	csaFunctions.Add("ECLSession::startPrintJob");
	csaFunctions.Add("ECLSession::transmitString");
	csaFunctions.Add("ECLSession::transmitTerminalKey");
	csaFunctions.Add("ECLSession::waitForCursorEntered");
	csaFunctions.Add("ECLSession::waitForCursorLeft");
	csaFunctions.Add("ECLSession::waitForDisplayString");		// 220
	csaFunctions.Add("ECLSession::waitForDisplayString");
	csaFunctions.Add("ECLSession::waitForDisplayStrings");
	csaFunctions.Add("ECLSession::waitForHostPrompt");
	csaFunctions.Add("ECLSession::waitForKeyboardLock");
	csaFunctions.Add("ECLSession::waitForKeyboardUnlock");
	csaFunctions.Add("ECLSession::waitForString");
	csaFunctions.Add("ECLSession::waitWhileDisplayString");	
	csaFunctions.Add("ECLSession::waitWhileDisplayString 2");
	csaFunctions.Add("ECLSession::waitWhileDisplayString 3");

	csaFunctions.Add("ECLXfer::Cancel");						// 230
	csaFunctions.Add("ECLXfer::GetParent");
	csaFunctions.Add("ECLXfer::GetStartTimeout");
	csaFunctions.Add("ECLXfer::GetTimeout");
	csaFunctions.Add("ECLXfer::ReceiveFile");
	csaFunctions.Add("ECLXfer::RegisterXferEvent");
	csaFunctions.Add("ECLXfer::SendFile");
	csaFunctions.Add("ECLXfer::SetStartTimeout");
	csaFunctions.Add("ECLXfer::SetTimeout");
	csaFunctions.Add("ECLXfer::setTransferHostType");
	csaFunctions.Add("ECLXfer::UnregisterXferEvent");			// 240



	listTranslateFunction->ResetContent();	
	
	for (int k=0; k<csaFunctions.GetSize(); k++)
	{
		listTranslateFunction->AddString( csaFunctions.GetAt(k) );
	}

	listTranslateFunction->SetCurSel(0);

}