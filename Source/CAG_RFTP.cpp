// Static Model
#include "stdafx.h"
#include "apigen.h"

#include "CAG_RFTP.h"
#include "time.h"

CAG_RFTP::CAG_RFTP()
{
	APIFlavor=RFTP_API;		
}

CAG_RFTP::~CAG_RFTP()
{
	
}

void CAG_RFTP::loadFunctionList(CListBox* listTranslateFunction)
{
	csaFunctions.RemoveAll();

	csaFunctions.Add("Close");
	csaFunctions.Add("CloseDirectoryListing");
	csaFunctions.Add("Connect");
	csaFunctions.Add("CreateDirectory");
	csaFunctions.Add("DeleteDirectory");
	csaFunctions.Add("DeleteFile");
	csaFunctions.Add("ExecuteFTPCommand");
	csaFunctions.Add("GetCurrentDirectory");
	csaFunctions.Add("GetNextFileDetails");
	csaFunctions.Add("LoadDefaultSiteProperties");
	csaFunctions.Add("LoadSiteProperties");			// 10
	csaFunctions.Add("Open");
	csaFunctions.Add("OpenDirectoryListing");
	csaFunctions.Add("ReceiveDirectory");
	csaFunctions.Add("ReceiveFile");
	csaFunctions.Add("RenameFile");
	csaFunctions.Add("SaveSiteProperties");
	csaFunctions.Add("SendDirectory");
	csaFunctions.Add("SendFile");
	csaFunctions.Add("SetCurrentDirectory");		// 19
	
	listTranslateFunction->ResetContent();	
	
	for (int k=0; k<csaFunctions.GetSize(); k++)
	{
		listTranslateFunction->AddString( csaFunctions.GetAt(k) );
	}

	listTranslateFunction->SetCurSel(0);
	
}


void CAG_RFTP::loadLanguageList(CListBox* listTranslateLanguage)
{
	int nPos = 0;

	listTranslateLanguage->ResetContent();
	listTranslateLanguage->InsertString( nPos++, "C++" );
	listTranslateLanguage->InsertString( nPos++, "C#" );
	listTranslateLanguage->InsertString( nPos++, "VB 6.0" );
	listTranslateLanguage->InsertString( nPos++, "VB.Net" );
	
	listTranslateLanguage->SetCurSel(0);
	
}

void CAG_RFTP::loadTerminalTypeList(CListBox* listTerminalTypes)
{
	int nPos = 0;

	listTerminalTypes->ResetContent();
/*
	listTerminalTypes->InsertString( nPos++, "3270" );
	listTerminalTypes->InsertString( nPos++, "5250" );
	listTerminalTypes->InsertString( nPos++, "VT" );
	
	listTerminalTypes->SetCurSel(0);
*/
}
