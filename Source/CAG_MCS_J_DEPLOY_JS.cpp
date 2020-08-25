// Static Model
#include "stdafx.h"
#include "apigen.h"

#include "CAG_MCS_J_DEPLOY_JS.h"

CAG_MCS_J_DEPLOY_JS::CAG_MCS_J_DEPLOY_JS()
{
	
}

CAG_MCS_J_DEPLOY_JS::~CAG_MCS_J_DEPLOY_JS()
{
	
}

void CAG_MCS_J_DEPLOY_JS::loadFunctionList(CListBox* listTranslationFunction)
{
	csaFunctions.RemoveAll();

	listTranslateFunction->ResetContent();

	csaFunctions.Add( "AtmObject::getName" );				// 0
	csaFunctions.Add( "AtmObject::getParentObject" );
	
	csaFunctions.Add( "OIA::getErrorStatus" );
	csaFunctions.Add( "OIA::getOiaType" );
	csaFunctions.Add( "OIA::getText" );
	csaFunctions.Add( "OIA::getXStatus" );					// 5
	csaFunctions.Add( "OIA::waitForXStatus" );

	csaFunctions.Add( "Screen::clearScreen" );
	csaFunctions.Add( "Screen::fieldCount" );
	csaFunctions.Add( "Screen::getColumns" );
	csaFunctions.Add( "Screen::getCursorColumn" );			// 10
	csaFunctions.Add( "Screen::getCursorRow" );
	csaFunctions.Add( "Screen::getEabEnabled" );
	csaFunctions.Add( "Screen::getHostCharSet" );
	csaFunctions.Add( "Screen::getHostCodePage" );
	csaFunctions.Add( "Screen::getKeyboardLocked" );		// 15
	csaFunctions.Add( "Screen::getModel" );
	csaFunctions.Add( "Screen::getOia" );
	csaFunctions.Add( "Screen::getRows" );
	csaFunctions.Add( "Screen::getScreenType" );
	csaFunctions.Add( "Screen::getString" );				// 20
	csaFunctions.Add( "Screen::getText" );
	csaFunctions.Add( "Screen::putString" );
	csaFunctions.Add( "Screen::refreshEvents" );
	csaFunctions.Add( "Screen::sendKeys" );
	csaFunctions.Add( "Screen::setCursor" );				// 25
	csaFunctions.Add( "Screen::setEabEnabled" );
	csaFunctions.Add( "Screen::setHostCharSet" );
	csaFunctions.Add( "Screen::setHostCodePage" );
	csaFunctions.Add( "Screen::setModel" );
	csaFunctions.Add( "Screen::waitForCursor" );			// 30
	csaFunctions.Add( "Screen::waitForKeys" );
	csaFunctions.Add( "Screen::waitForString" );
	csaFunctions.Add( "Screen::waitHostQuiet" );

	csaFunctions.Add( "Session::attach" );
	csaFunctions.Add( "Session::connect" );					// 35
	csaFunctions.Add( "Session::detach" );
	csaFunctions.Add( "Session::disconnect" );

	csaFunctions.Add( "Session::getAttached" );
	csaFunctions.Add( "Session::getConnected" );
	csaFunctions.Add( "Session::getConnection" );			// 40
	csaFunctions.Add( "Session::getScreen" );
	csaFunctions.Add( "Session::getState" );
	csaFunctions.Add( "Session::setConnected" );
	csaFunctions.Add( "Session::setConnection" );
	csaFunctions.Add( "Session::setScreen" );				// 45

	csaFunctions.Add( "ITelnetProxy::getSocksAddress" );
	csaFunctions.Add( "ITelnetProxy::getSocksPort" );
	csaFunctions.Add( "ITelnetProxy::getTelnetAddress" );
	csaFunctions.Add( "ITelnetProxy::getTelnetPort" );
	csaFunctions.Add( "ITelnetProxy::setSocksAddress" );	// 50
	csaFunctions.Add( "ITelnetProxy::setSocksPort" );
	csaFunctions.Add( "ITelnetProxy::setTelnetAddress" );
	csaFunctions.Add( "ITelnetProxy::setTelnetPort" );

	csaFunctions.Add( "Debug" );

	listTranslateFunction->ResetContent();	
	
	for (int k=0; k<csaFunctions.GetSize(); k++)
	{
		listTranslateFunction->AddString( csaFunctions.GetAt(k) );
	}

	listTranslateFunction->SetCurSel(0);
	
}


void CAG_MCS_J_DEPLOY_JS::loadLanguageList(CListBox* listTranslateLanguage)
{
	
}

void CAG_MCS_J_DEPLOY_JS::declareVariable(AG_VARIABLE agVariable,
										  CStringArray* pcsaHeader,
										  bool* bValue)
{
	
}

void CAG_MCS_J_DEPLOY_JS::checkDebug(bool b_Debug,
									 CString csFunctionName,
									 CStringArray* pcsaBody)
{
	
}

void CAG_MCS_J_DEPLOY_JS::generateHeader(CStringArray* pcsaHeader,
										 CStringArray* pcsaBody)
{
	
}

void CAG_MCS_J_DEPLOY_JS::appendBody(int nFunctionNum,
									 bool bPromptForValues,
									 CStringArray* pcsaArguments,
									 CStringArray* pcsaHeader,
									 CStringArray* pcsaBody)
{
	
}

void CAG_MCS_J_DEPLOY_JS::finalize(CStringArray* pcsaBody)
{
	
}

void CAG_MCS_J_DEPLOY_JS::collectDeploymentParameters(CStringArray* pcsaDeploymentParameters)
{
	
}
