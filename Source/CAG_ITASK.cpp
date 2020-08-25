// Static Model
#include "stdafx.h"
#include "apigen.h"

#include "CAG_ITASK.h"

CAG_ITASK::CAG_ITASK()
{
	APIFlavor=ITASK_API;
}

CAG_ITASK::~CAG_ITASK()
{
	
}

void CAG_ITASK::loadLanguageList(CListBox* listTranslateLanguage)
{
	int nPos = 0;

	listTranslateLanguage->ResetContent();
	listTranslateLanguage->InsertString( nPos++, "Java" );
//	listTranslateLanguage->InsertString( nPos++, "C++" );
	listTranslateLanguage->InsertString( nPos++, "C#" );
//	listTranslateLanguage->InsertString( nPos++, "VB 6.0" );
	listTranslateLanguage->InsertString( nPos++, "VB.Net" );
	listTranslateLanguage->InsertString( nPos++, "Windows Script" );
	listTranslateLanguage->SetCurSel(0);

}

void CAG_ITASK::loadTerminalTypeList(CListBox* listTerminalTypes)
{
	int nPos = 0;

	listTerminalTypes->ResetContent();
	listTerminalTypes->InsertString( nPos++, "IConnectorAccess" );
	listTerminalTypes->InsertString( nPos++, "ITask" );
//	listTerminalTypes->InsertString( nPos++, "ScreenNativeAccess" );
	
	listTerminalTypes->SetCurSel(0);
}


void CAG_ITASK::loadFunctionList(CListBox* listTranslateFunction)
{
	csaFunctions.RemoveAll();

	listTranslateFunction->ResetContent();

	csaFunctions.Add("ITask::addTaskListener");
	csaFunctions.Add("ITask::cancel");
	csaFunctions.Add("ITask::clearContent");
	csaFunctions.Add("ITask::copyContext");
	csaFunctions.Add("ITask::executeAsync");
	csaFunctions.Add("ITask::executeSync");
	csaFunctions.Add("ITask::getInstanceName");
	csaFunctions.Add("ITask::getJobName");
	csaFunctions.Add("ITask::getLocale");
	csaFunctions.Add("ITask::getPreserveContext");
	csaFunctions.Add("ITask::getResourceName");
	csaFunctions.Add("ITask::getStatus");
	csaFunctions.Add("ITask::getTimeout");
	csaFunctions.Add("ITask::getVersion");
	csaFunctions.Add("ITask::removeTaskListener");
	csaFunctions.Add("ITask::setInstanceName");
	csaFunctions.Add("ITask::setJobName");
	csaFunctions.Add("ITask::setLocale");
	csaFunctions.Add("ITask::setPreserveContext");
	csaFunctions.Add("ITask::setResourceName");
	csaFunctions.Add("ITask::setTimeout");
	csaFunctions.Add("ITask::transferContext");

	csaFunctions.Add("ScreenNativeAccess::doExecute");
	csaFunctions.Add("ScreenNativeAccess::getCharacterAttr");
	csaFunctions.Add("ScreenNativeAccess::getColumns");
	csaFunctions.Add("ScreenNativeAccess::getCommand");
	csaFunctions.Add("ScreenNativeAccess::getCurrentPage");
	csaFunctions.Add("ScreenNativeAccess::getCursorColumn");
	csaFunctions.Add("ScreenNativeAccess::getCursorRow");
	csaFunctions.Add("ScreenNativeAccess::getFieldAttr");
	csaFunctions.Add("ScreenNativeAccess::getFieldAttr 2");
	csaFunctions.Add("ScreenNativeAccess::getFieldCount");
	csaFunctions.Add("ScreenNativeAccess::getFieldEndColumn");
	csaFunctions.Add("ScreenNativeAccess::getFieldEndColumn");
	csaFunctions.Add("ScreenNativeAccess::getFieldEndRow");
	csaFunctions.Add("ScreenNativeAccess::getFieldEndRow 2");
	csaFunctions.Add("ScreenNativeAccess::getFieldInputText");
	csaFunctions.Add("ScreenNativeAccess::getFieldInputText 2");
	csaFunctions.Add("ScreenNativeAccess::getFieldLength");
	csaFunctions.Add("ScreenNativeAccess::getFieldLength 2");
	csaFunctions.Add("ScreenNativeAccess::getFieldPage");
	csaFunctions.Add("ScreenNativeAccess::getFieldPage 2");
	csaFunctions.Add("ScreenNativeAccess::getFieldStartColumn");
	csaFunctions.Add("ScreenNativeAccess::getFieldStartColumn 2");
	csaFunctions.Add("ScreenNativeAccess::getFieldStartRow");
	csaFunctions.Add("ScreenNativeAccess::getFieldStartRow 2");
	csaFunctions.Add("ScreenNativeAccess::getFieldText");
	csaFunctions.Add("ScreenNativeAccess::getFieldText 2");
	csaFunctions.Add("ScreenNativeAccess::getHostFlags");
	csaFunctions.Add("ScreenNativeAccess::getHostMessage");
	csaFunctions.Add("ScreenNativeAccess::getHostType");
	csaFunctions.Add("ScreenNativeAccess::getPageCount");
	csaFunctions.Add("ScreenNativeAccess::getPoolName");
	csaFunctions.Add("ScreenNativeAccess::getRows");
	csaFunctions.Add("ScreenNativeAccess::getScreenName");
	csaFunctions.Add("ScreenNativeAccess::getSettleTime");
	csaFunctions.Add("ScreenNativeAccess::getShare");
	csaFunctions.Add("ScreenNativeAccess::setCommand");
	csaFunctions.Add("ScreenNativeAccess::setConfiguration");
	csaFunctions.Add("ScreenNativeAccess::setCurrentPage");
	csaFunctions.Add("ScreenNativeAccess::setCursorColumn");
	csaFunctions.Add("ScreenNativeAccess::setCursorRow");
	csaFunctions.Add("ScreenNativeAccess::setFieldInputText");
	csaFunctions.Add("ScreenNativeAccess::setFieldInputText 2");
	csaFunctions.Add("ScreenNativeAccess::setSettleTime");
	csaFunctions.Add("ScreenNativeAccess::setShare");

	listTranslateFunction->ResetContent();	
	
	for (int k=0; k<csaFunctions.GetSize(); k++)
	{
		listTranslateFunction->AddString( csaFunctions.GetAt(k) );
	}

	listTranslateFunction->SetCurSel(0);

}
