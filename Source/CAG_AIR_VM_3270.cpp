// Static Model
#include "stdafx.h"
#include "apigen.h"

#include "CAG_AIR_VM_3270.h"

void CAG_AIR_VM_3270::loadFunctionList(CListBox* listTranslateFunction)
{
	csaFunctions.RemoveAll();

	csaFunctions.Add("IScreenUPG::clearCapturedData");
	csaFunctions.Add("IScreenUPG::fieldCount");
	csaFunctions.Add("IScreenUPG::findField");
	csaFunctions.Add("IScreenUPG::findFieldEx");
	csaFunctions.Add("IScreenUPG::findString");
	csaFunctions.Add("IScreenUPG::findStringEx");
	csaFunctions.Add("IScreenUPG::focusTerminal");
	csaFunctions.Add("IScreenUPG::getCapturedData");
	csaFunctions.Add("IScreenUPG::getColumns");
	csaFunctions.Add("IScreenUPG::getConnectStatus");
	csaFunctions.Add("IScreenUPG::getCursor");
	csaFunctions.Add("IScreenUPG::getCursorColumn");
	csaFunctions.Add("IScreenUPG::getCursorRow");
	csaFunctions.Add("IScreenUPG::getDataCapture");
	csaFunctions.Add("IScreenUPG::getExtPS");
	csaFunctions.Add("IScreenUPG::getgetText_Display");
	csaFunctions.Add("IScreenUPG::getKeyboardLocked");
	csaFunctions.Add("IScreenUPG::getMaxDataCaptureLength");
	csaFunctions.Add("IScreenUPG::getObjectVersion");
	csaFunctions.Add("IScreenUPG::getOIAContents");
	csaFunctions.Add("IScreenUPG::getOIAText");
	csaFunctions.Add("IScreenUPG::getRows");
	csaFunctions.Add("IScreenUPG::getScreenType");
	csaFunctions.Add("IScreenUPG::getString");
	csaFunctions.Add("IScreenUPG::getStringEx");
	csaFunctions.Add("IScreenUPG::getText");
	csaFunctions.Add("IScreenUPG::hideTerminal");
	csaFunctions.Add("IScreenUPG::isKeyboardLocked");
	csaFunctions.Add("IScreenUPG::putString");
	csaFunctions.Add("IScreenUPG::putStringEx");
	csaFunctions.Add("IScreenUPG::sendKeys");
	csaFunctions.Add("IScreenUPG::setCursor");
	csaFunctions.Add("IScreenUPG::setCursorColumn");
	csaFunctions.Add("IScreenUPG::setCursorRow");
	csaFunctions.Add("IScreenUPG::setDataCapture");
	csaFunctions.Add("IScreenUPG::setgetText_Display");
	csaFunctions.Add("IScreenUPG::setMaxDataCaptureLength");
	csaFunctions.Add("IScreenUPG::showColorDialog");
	csaFunctions.Add("IScreenUPG::showTerminal");
	csaFunctions.Add("IScreenUPG::waitForCursor");
	csaFunctions.Add("IScreenUPG::waitForString");
	csaFunctions.Add("IScreenUPG::waitHostQuiet");

	listTranslateFunction->ResetContent();	
	
	for (int k=0; k<csaFunctions.GetSize(); k++)
	{
		listTranslateFunction->AddString( csaFunctions.GetAt(k) );
	}

	listTranslateFunction->SetCurSel(0);

}


CAG_AIR_VM_3270::CAG_AIR_VM_3270()
{
	
}

CAG_AIR_VM_3270::~CAG_AIR_VM_3270()
{
	
}

void CAG_AIR_VM_3270::generateHeader(CStringArray* pcsaHeader,
								  CStringArray* pcsaBody)
{}

void CAG_AIR_VM_3270::appendBody(int nFunctionNum,
							  bool bPromptForValues,
							  CStringArray* pcsaArguments,
							  CStringArray* pcsaHeader,
							  CStringArray* pcsaBody)
{}

void CAG_AIR_VM_3270::finalize(CStringArray* pcsaBody)
{}

void CAG_AIR_VM_3270::declareVariable(AG_VARIABLE agVariable,
								   CStringArray* pcsaHeader,
								   bool* bValue)
{
	
}

