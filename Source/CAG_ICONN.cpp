// Static Model
#include "stdafx.h"
#include "apigen.h"

#include "CAG_ICONN.h"

CAG_ICONN::CAG_ICONN()
{
	APIFlavor=ICONN_API;
}

CAG_ICONN::~CAG_ICONN()
{
	
}

void CAG_ICONN::loadLanguageList(CListBox* listTranslateLanguage)
{
	int nPos = 0;

	listTranslateLanguage->ResetContent();
	listTranslateLanguage->InsertString( nPos++, "Java" );
	listTranslateLanguage->InsertString( nPos++, "ASP" );
	listTranslateLanguage->InsertString( nPos++, "C#" );
	listTranslateLanguage->InsertString( nPos++, "VB.Net" );
	listTranslateLanguage->InsertString( nPos++, "Windows Script" );
	listTranslateLanguage->SetCurSel(0);

}

void CAG_ICONN::loadTerminalTypeList(CListBox* listTerminalTypes)
{
	int nPos = 0;

	listTerminalTypes->ResetContent();
	listTerminalTypes->InsertString( nPos++, "IConnectorAccess" );
	listTerminalTypes->InsertString( nPos++, "ITask" );
//	listTerminalTypes->InsertString( nPos++, "ScreenNativeAccess" );
	
	listTerminalTypes->SetCurSel(0);
}


void CAG_ICONN::loadFunctionList(CListBox* listTranslateFunction)
{
	csaFunctions.RemoveAll();

	listTranslateFunction->ResetContent();

	csaFunctions.Add("IConnectionAccess::cancel");
	csaFunctions.Add("IConnectionAccess::close");
	csaFunctions.Add("IConnectionAccess::execute");
	csaFunctions.Add("IConnectionAccess::getAvailable");
	csaFunctions.Add("IConnectionAccess::getData");
	csaFunctions.Add("IConnectionAccess::getMaxSize");
	csaFunctions.Add("IConnectionAccess::getMetaData");
	csaFunctions.Add("IConnectionAccess::getTimeOut");
	csaFunctions.Add("IConnectionAccess::open");
	csaFunctions.Add("IConnectionAccess::setMaxSize");
	csaFunctions.Add("IConnectionAccess::setTimeOut");
	csaFunctions.Add("Debug");

	listTranslateFunction->ResetContent();	
	
	for (int k=0; k<csaFunctions.GetSize(); k++)
	{
		listTranslateFunction->AddString( csaFunctions.GetAt(k) );
	}

	listTranslateFunction->SetCurSel(0);

}
