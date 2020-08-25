// Static Model
#include "stdafx.h"
#include "apigen.h"

#include "CAG_VHI.h"

CAG_VHI::CAG_VHI()
{
	APIFlavor=VHI_API;		
}

CAG_VHI::~CAG_VHI()
{
	
}

void CAG_VHI::loadLanguageList(CListBox* listTranslateLanguage)
{
	int nPos = 0;

	listTranslateLanguage->ResetContent();
	listTranslateLanguage->InsertString( nPos++, "C#" );
	listTranslateLanguage->InsertString( nPos++, "VB 6.0" );
	listTranslateLanguage->InsertString( nPos++, "VB.Net" );
	listTranslateLanguage->InsertString( nPos++, "Windows Script" );
	listTranslateLanguage->SetCurSel(0);

}

void CAG_VHI::loadTerminalTypeList(CListBox* listTerminalTypes)
{
	int nPos = 0;

	listTerminalTypes->ResetContent();
	listTerminalTypes->InsertString( nPos++, "" );
	
	listTerminalTypes->SetCurSel(0);
}


void CAG_VHI::loadFunctionList(CListBox* listTranslateFunction)
{
	csaFunctions.RemoveAll();

	listTranslateFunction->ResetContent();

	csaFunctions.Add( "ConnectionTimeout" );
	csaFunctions.Add( "ConnectToModel" );
	csaFunctions.Add( "ConnectToModelViaDomain" );	
	csaFunctions.Add( "ConnectToSession" );
	csaFunctions.Add( "ConnectToSessionViaDomain" );
	csaFunctions.Add( "Comment" );
	csaFunctions.Add( "Disconnect" );
	csaFunctions.Add( "EnableTerminalAttributes" );
	csaFunctions.Add( "ExecuteSQLStatement" );
	csaFunctions.Add( "FetchRecords" );
	csaFunctions.Add( "GetAttributeAtCursor" );
	csaFunctions.Add( "GetAttributeLocations" );
	csaFunctions.Add( "GetAttributeMetaData" );
	csaFunctions.Add( "GetAttributes" );
	csaFunctions.Add( "GetColumnMetaData" );
	csaFunctions.Add( "GetCurrentEntity" );
	csaFunctions.Add( "GetCurrentRecord" );
	csaFunctions.Add( "GetCurrentRecordIndex" );
	csaFunctions.Add( "GetCurrentRecordSetName" );
	csaFunctions.Add( "GetEntityAttributes" );
	csaFunctions.Add( "GetEntityDescription" );
	csaFunctions.Add( "GetEntityOperations" );
	csaFunctions.Add( "GetEntityRecordSets" );
	csaFunctions.Add( "GetFieldLocations" );
	csaFunctions.Add( "GetFieldMetaData" );
	csaFunctions.Add( "GetHomeEntityName" );
	csaFunctions.Add( "GetLastRequestID" );
	csaFunctions.Add( "GetLocale" );
	csaFunctions.Add( "GetLoggingLevel" );
	csaFunctions.Add( "GetMajorVersion" );
	csaFunctions.Add( "GetMethodTimeout" );
	csaFunctions.Add( "GetMinorVersion" );
	csaFunctions.Add( "GetModelEntities" );
	csaFunctions.Add( "GetModelVariableNames" );
	csaFunctions.Add( "GetModelVariables" );
	csaFunctions.Add( "GetOperationMetaData" );
	csaFunctions.Add( "GetPatternLocations" );
	csaFunctions.Add( "GetProcedureMetaData" );
	csaFunctions.Add( "GetRecordSetLocations" );
	csaFunctions.Add( "GetRecordSetMetaData" );
	csaFunctions.Add( "GetSessionID" );
	csaFunctions.Add( "GetStringAtOffset" );
	csaFunctions.Add( "GetStringAtRowColumn" );
	csaFunctions.Add( "GetTableColumns" );
	csaFunctions.Add( "GetTableDescription" );
	csaFunctions.Add( "GetTableNames" );
	csaFunctions.Add( "GetTableProcedures" );
	csaFunctions.Add( "GetTerminalFieldAtCursor" );
	csaFunctions.Add( "GetVariableMetaData" );
	csaFunctions.Add( "GetVersionString" );
	csaFunctions.Add( "IsSecureConnection" );
	csaFunctions.Add( "InsertRecord" );
	csaFunctions.Add( "InsertRecords" );
	csaFunctions.Add( "InsertStringAtCursor" );
	csaFunctions.Add( "InsertStringAtOffset" );
	csaFunctions.Add( "InsertStringAtRowColumn" );
	csaFunctions.Add( "IsConnected" );
	csaFunctions.Add( "LastErrorMessageList" );
	csaFunctions.Add( "MetaDataOnly" );
	csaFunctions.Add( "ModelName" );
	csaFunctions.Add( "ModelVersionString" );
	csaFunctions.Add( "MoveCurrentRecordIndex" );
	csaFunctions.Add( "NextRecord" );
	csaFunctions.Add( "PerformAidKey" );
	csaFunctions.Add( "PerformEntityOperation" );
	csaFunctions.Add( "PerformTableProcedure" );
	csaFunctions.Add( "ProcessString" );
	csaFunctions.Add( "RequireSecureConnection" );
	csaFunctions.Add( "ResumeConnection" );
	csaFunctions.Add( "SelectCurrentRecord" );
	csaFunctions.Add( "SelectRecordByFilter" );
	csaFunctions.Add( "SelectRecordByIndex" );
	csaFunctions.Add( "ServerName" );
	csaFunctions.Add( "SessionType" );
	csaFunctions.Add( "SetAttributes" );
	csaFunctions.Add( "SetAttributesDelayed" );
	csaFunctions.Add( "SetCurrentEntity" );
	csaFunctions.Add( "SetCurrentRecordIndex" );
	csaFunctions.Add( "SetCurrentRecordSetByName" );
	csaFunctions.Add( "SetLocale" );
	csaFunctions.Add( "SetLoggingLevel" );
	csaFunctions.Add( "SetMethodTimeout" );
	csaFunctions.Add( "SetModelVariables" );
	csaFunctions.Add( "SuspendConnection" );
	csaFunctions.Add( "UpdateCurrentRecord" );
	csaFunctions.Add( "UpdateRecordByFilter" );
	csaFunctions.Add( "UpdateRecordByIndex" );
	csaFunctions.Add( "UpdateRecords" );
	csaFunctions.Add( "WaitForCondition" );
	csaFunctions.Add( "WaitForCursor" );
	csaFunctions.Add( "WaitForEntityChange" );
	csaFunctions.Add( "WaitForString" );
	csaFunctions.Add( "WaitForStringRelCursor" );
	csaFunctions.Add( "Debug" );

	listTranslateFunction->ResetContent();	
	
	for (int k=0; k<csaFunctions.GetSize(); k++)
	{
		listTranslateFunction->AddString( csaFunctions.GetAt(k) );
	}

	listTranslateFunction->SetCurSel(0);


}
