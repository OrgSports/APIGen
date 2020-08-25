// Static Model
#include "stdafx.h"
#include "apigen.h"

#include "CAG_CICS_QACOM_COM.h"

CAG_CICS_QACOM_COM::CAG_CICS_QACOM_COM()
{
	APIFlavor=CICS_COM_API;	
}

CAG_CICS_QACOM_COM::~CAG_CICS_QACOM_COM()
{
	
}

void CAG_CICS_QACOM_COM::loadFunctionList(CListBox* listTranslateFunction)
{
	listTranslateFunction->ResetContent();

	csaFunctions.Add( "ChangePassword" );
	csaFunctions.Add( "ConnectBridge" );
	csaFunctions.Add( "Disconnect" );
	csaFunctions.Add( "FindString" );
	csaFunctions.Add( "GetAllFieldInformation" );
	csaFunctions.Add( "GetConnectionStatus" );
	csaFunctions.Add( "GetCurrentScreenName" );
	csaFunctions.Add( "GetCursorPosition" );
	csaFunctions.Add( "GetFieldAttributes" );
	csaFunctions.Add( "GetFieldCoordinates" );
	csaFunctions.Add( "GetFieldCount" );
	csaFunctions.Add( "GetFieldNameFromIndex" );
	csaFunctions.Add( "GetFieldValue" );
	csaFunctions.Add( "GetScreenSize" );
	csaFunctions.Add( "GetString" );
	csaFunctions.Add( "GetTransactionSystemId" );
	csaFunctions.Add( "Initialize" );
	csaFunctions.Add( "Pause" );
	csaFunctions.Add( "PutString" );
	csaFunctions.Add( "SendKeys" );
	csaFunctions.Add( "SendKeysEx" );
	csaFunctions.Add( "SendKeysGetAllFieldInformation" );
	csaFunctions.Add( "SendKeysGetString" );
	csaFunctions.Add( "SetCursorPosition" );
	csaFunctions.Add( "SetFieldValue" );
	csaFunctions.Add( "SetSettleTime" );
	csaFunctions.Add( "SetTimeOut" );
	csaFunctions.Add( "SetTraceActive" );
	csaFunctions.Add( "SetTraceInactive" );
	csaFunctions.Add( "SetTraceName" );
	csaFunctions.Add( "Terminate" );
	csaFunctions.Add( "Debug" );


	listTranslateFunction->ResetContent();	
	
	for (int k=0; k<csaFunctions.GetSize(); k++)
	{
		listTranslateFunction->AddString( csaFunctions.GetAt(k) );
	}

	listTranslateFunction->SetCurSel(0);
	
}



void CAG_CICS_QACOM_COM::loadLanguageList(CListBox* listTranslateLanguage)
{
	int nPos = 0;

	listTranslateLanguage->ResetContent();

	listTranslateLanguage->InsertString( nPos++, "ASP" );
	listTranslateLanguage->InsertString( nPos++, "C++" );
	listTranslateLanguage->InsertString( nPos++, "VB 6.0" );
	listTranslateLanguage->SetCurSel(0);
	
}
