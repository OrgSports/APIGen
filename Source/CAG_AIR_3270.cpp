// Static Model
#include "stdafx.h"
#include "apigen.h"

#include "CAG_AIR_3270.h"

void CAG_AIR_3270::loadFunctionList(CListBox* listTranslateFunction)
{
	csaFunctions.RemoveAll();

	csaFunctions.Add("IScreenListener::onConnectionLost");		// 0
	csaFunctions.Add("IScreenListener::onError");
	csaFunctions.Add("IScreenListener::onLostRemoteWindow");
	csaFunctions.Add("IScreenListener::onScreenChanged");
	csaFunctions.Add("IScreenListener::onScreenShapeChanged");
	csaFunctions.Add("IScreenUPG::addIScreenListener");			// 5
	csaFunctions.Add("IScreenUPG::clearCapturedData");
	csaFunctions.Add("IScreenUPG::Close");
	csaFunctions.Add("IScreenUPG::fieldCount");
	csaFunctions.Add("IScreenUPG::findField");
	csaFunctions.Add("IScreenUPG::findFieldEx");				// 10
	csaFunctions.Add("IScreenUPG::findString");
	csaFunctions.Add("IScreenUPG::findStringEx");
	csaFunctions.Add("IScreenUPG::getCapturedData");
	csaFunctions.Add("IScreenUPG::getColumns");
	csaFunctions.Add("IScreenUPG::getCursor");					// 15
	csaFunctions.Add("IScreenUPG::getCursorColumn");
	csaFunctions.Add("IScreenUPG::getCursorRow");
	csaFunctions.Add("IScreenUPG::getDataCapture");
	csaFunctions.Add("IScreenUPG::getDescription");
	csaFunctions.Add("IScreenUPG::getExtPS");					// 20
	csaFunctions.Add("IScreenUPG::getgetText_Display");
	csaFunctions.Add("IScreenUPG::getKeyboardLocked");
	csaFunctions.Add("IScreenUPG::getLastError");
	csaFunctions.Add("IScreenUPG::getMaxDataCaptureLength");
	csaFunctions.Add("IScreenUPG::getObjectVersion");			// 25
	csaFunctions.Add("IScreenUPG::getOIAContents");
	csaFunctions.Add("IScreenUPG::getOIAText");
	csaFunctions.Add("IScreenUPG::getRows");
	csaFunctions.Add("IScreenUPG::getScreenType");
	csaFunctions.Add("IScreenUPG::getString");					// 30
	csaFunctions.Add("IScreenUPG::getStringEx");
	csaFunctions.Add("IScreenUPG::getText");
	csaFunctions.Add("IScreenUPG::isConnected");
	csaFunctions.Add("IScreenUPG::isKeyboardLocked");
	csaFunctions.Add("IScreenUPG::Open");						// 35
	csaFunctions.Add("IScreenUPG::putString");
	csaFunctions.Add("IScreenUPG::putStringEx");
	csaFunctions.Add("IScreenUPG::removeIScreenListener");
	csaFunctions.Add("IScreenUPG::sendKeys");
	csaFunctions.Add("IScreenUPG::setCursor");					// 40
	csaFunctions.Add("IScreenUPG::setCursorColumn");
	csaFunctions.Add("IScreenUPG::setCursorRow");
	csaFunctions.Add("IScreenUPG::setDataCapture");
	csaFunctions.Add("IScreenUPG::setDescription");
	csaFunctions.Add("IScreenUPG::setgetText_Display");			// 45
	csaFunctions.Add("IScreenUPG::setMaxDataCaptureLength");
	csaFunctions.Add("IScreenUPG::waitForCursor");
	csaFunctions.Add("IScreenUPG::waitForString");
	csaFunctions.Add("IScreenUPG::waitHostQuiet");

	csaFunctions.Add("MutableInt()");							// 50
	csaFunctions.Add("MutableInt(int)");

	csaFunctions.Add("SessionLoader::getConfigurationIPAddress");
	csaFunctions.Add("SessionLoader::getTerminalType");
	csaFunctions.Add("SessionLoader::requestScreen");
	csaFunctions.Add("SessionLoader::requestScreenEx");			// 55
	csaFunctions.Add("SessionLoader::setConfigurationIPAddress");
	csaFunctions.Add("SessionLoader::setResourceManagerOptions");
	csaFunctions.Add("SessionLoader::setTerminalType");
	csaFunctions.Add("SessionLoader::Shutdown");

	listTranslateFunction->ResetContent();	
	
	for (int k=0; k<csaFunctions.GetSize(); k++)
	{
		listTranslateFunction->AddString( csaFunctions.GetAt(k) );
	}

	listTranslateFunction->SetCurSel(0);

}


CAG_AIR_3270::CAG_AIR_3270()
{
	
}

CAG_AIR_3270::~CAG_AIR_3270()
{
	
}

void CAG_AIR_3270::generateHeader(CStringArray* pcsaHeader,
								  CStringArray* pcsaBody)
{}

void CAG_AIR_3270::appendBody(int nFunctionNum,
							  bool bPromptForValues,
							  CStringArray* pcsaArguments,
							  CStringArray* pcsaHeader,
							  CStringArray* pcsaBody)
{}

void CAG_AIR_3270::finalize(CStringArray* pcsaBody)
{}

void CAG_AIR_3270::declareVariable(AG_VARIABLE agVariable,
								   CStringArray* pcsaHeader,
								   bool* bValue)
{
	
}

