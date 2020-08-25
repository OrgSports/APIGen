// Static Model
#include "stdafx.h"
#include "apigen.h"

#include "CAG_PB_QAC.h"

CAG_PB_QAC::CAG_PB_QAC()
{
	APIFlavor = QACOM_API;
}


CAG_PB_QAC::~CAG_PB_QAC()
{
	
}

void CAG_PB_QAC::loadFunctionList(CListBox* listTranslateFunction)
{
	csaFunctions.RemoveAll();

	csaFunctions.Add("Field::getAttributes");
	csaFunctions.Add("Field::getFieldAttribute");
	csaFunctions.Add("Field::getLength");
	csaFunctions.Add("Field::getScreenPosition");
	csaFunctions.Add("Field::getText");
	csaFunctions.Add("Field::isAttribSpace");
	csaFunctions.Add("Field::isModified");
	csaFunctions.Add("Field::setText");
	csaFunctions.Add("HostSyncCallBack::isHostSyncd");
	csaFunctions.Add("HostSyncRule::getChildRules");
	csaFunctions.Add("HostSyncRule::getProperties");
	csaFunctions.Add("HostSyncRule::setChildRules");
	csaFunctions.Add("HostSyncRule::setProperties");
	csaFunctions.Add("HostSyncRule::sync");
	csaFunctions.Add("HostSyncRule::version");
	csaFunctions.Add("MatchScreen::match");
	csaFunctions.Add("QAScreen::connect 1");
	csaFunctions.Add("QAScreen::connect 2");
	csaFunctions.Add("QAScreen::connect 3");
	csaFunctions.Add("QAScreen::disconnect");
	csaFunctions.Add("QAScreen::findField");
	csaFunctions.Add("QAScreen::findString 1");
	csaFunctions.Add("QAScreen::findString 2");
	csaFunctions.Add("QAScreen::getAllFieldInformation");
	csaFunctions.Add("QAScreen::getAttributes");
	csaFunctions.Add("QAScreen::getCurrentScreenName");
	csaFunctions.Add("QAScreen::getCursorPosition");
	csaFunctions.Add("QAScreen::getDefaultRules");
	csaFunctions.Add("QAScreen::getField 1");
	csaFunctions.Add("QAScreen::getField 2");
	csaFunctions.Add("QAScreen::getFieldCount");
	csaFunctions.Add("QAScreen::getRules");
	csaFunctions.Add("QAScreen::getScreenSize");
	csaFunctions.Add("QAScreen::getString");
	csaFunctions.Add("QAScreen::isConnected");
	csaFunctions.Add("QAScreen::isCurrentScreen");
	csaFunctions.Add("QAScreen::putString");
	csaFunctions.Add("QAScreen::sendKeys 1");
	csaFunctions.Add("QAScreen::sendKeys 2");
	csaFunctions.Add("QAScreen::sendKeys 3");
	csaFunctions.Add("QAScreen::sendKeys 4");
	csaFunctions.Add("QAScreen::setCursorPosition");
	csaFunctions.Add("QAScreen::setFieldValue 1");
	csaFunctions.Add("QAScreen::setFieldValue 2");
	csaFunctions.Add("QAScreenFactory::getInstance");
	csaFunctions.Add("QAScreenFactory::hosts");
	csaFunctions.Add("StackEventQueue::clear");
	csaFunctions.Add("StackEventQueue::pop");
	csaFunctions.Add("StackEventQueue::quiet");

	listTranslateFunction->ResetContent();	
	
	for (int k=0; k<csaFunctions.GetSize(); k++)
	{
		listTranslateFunction->AddString( csaFunctions.GetAt(k) );
	}

	listTranslateFunction->SetCurSel(0);


}


void CAG_PB_QAC::loadLanguageList(CListBox* listTranslateLanguage)
{
	int nPos = 0;

	listTranslateLanguage->ResetContent();
	listTranslateLanguage->InsertString( nPos++, "JavaScript" );
	listTranslateLanguage->InsertString( nPos++, "Java" );
	listTranslateLanguage->InsertString( nPos++, "VBScript" );
	
	listTranslateLanguage->SetCurSel(0);

}



void CAG_PB_QAC::declareVariable(AG_VARIABLE agVariable,
								 CStringArray* pcsaHeader,
								 bool* bValue)
{
	
}

void CAG_PB_QAC::checkDebug()
{
	
}


void CAG_PB_QAC::loadTerminalTypeList(CListBox* listTerminalTypes)
{
	listTerminalTypes->ResetContent();
	listTerminalTypes->InsertString( 0, "3270" );
	listTerminalTypes->InsertString( 1, "5250" );
	listTerminalTypes->InsertString( 2, "VT" );
	
	listTerminalTypes->SetCurSel(0);
}
