// Static Model
#include "stdafx.h"
#include "apigen.h"

#include "CAG_HLL.h"


CAG_HLL::CAG_HLL()
{
	APIFlavor=HLL_API;
	usGlobalPSMallocSize = 3840;

}


CAG_HLL::~CAG_HLL()
{
	
}

void CAG_HLL::loadFunctionList(CListBox* listTranslateFunction)
{
	csaFunctions.RemoveAll();

	csaFunctions.Add("HLL_AttachmateQuerySystem");
	csaFunctions.Add("HLL_ConnectPS" );
	csaFunctions.Add("HLL_Convert" );
	csaFunctions.Add("HLL_CopyFieldToString" );
	csaFunctions.Add("HLL_CopyOIA" );
	csaFunctions.Add("HLL_CopyOIA5" );
	csaFunctions.Add("HLL_CopyOIA9" );
	csaFunctions.Add("HLL_CopyPS" );
	csaFunctions.Add("HLL_CopyPSToString" );
	csaFunctions.Add("HLL_CopyStringToField" );
	csaFunctions.Add("HLL_CopyStringToPS" );
	csaFunctions.Add("HLL_DisconnectPS" );
	csaFunctions.Add("HLL_EnumHLLWins" );
	csaFunctions.Add("HLL_FindFieldLength" );
	csaFunctions.Add("HLL_FindFieldPosition" );
	csaFunctions.Add("HLL_GetKey" );
	csaFunctions.Add("HLL_Pause" );
	csaFunctions.Add("HLL_PostInterceptStatus" );
	csaFunctions.Add("HLL_QueryHLLWinParameters" );
	csaFunctions.Add("HLL_QueryCursor" );
	csaFunctions.Add("HLL_QueryFieldAttribute" );
	csaFunctions.Add("HLL_QueryHostUpdate" );
	csaFunctions.Add("HLL_QuerySessions" );
	csaFunctions.Add("HLL_QuerySessionStatus" );
	csaFunctions.Add("HLL_QuerySystem" );
	csaFunctions.Add("HLL_ReceiveFile" );
	csaFunctions.Add("HLL_Release" );
	csaFunctions.Add("HLL_Reserve" );
	csaFunctions.Add("HLL_ResetHLLWin" );
	csaFunctions.Add("HLL_SearchField" );
	csaFunctions.Add("HLL_SearchPS" );
	csaFunctions.Add("HLL_SendFile" );
	csaFunctions.Add("HLL_SendKey" );
	csaFunctions.Add("HLL_SetCursor" );
	csaFunctions.Add("HLL_SetMessageLoopCallback");
	csaFunctions.Add("HLL_SetHLLWinParameters" );
	csaFunctions.Add("HLL_StartHostNotification" );
	csaFunctions.Add("HLL_StartKeystrokeIntercept" );
	csaFunctions.Add("HLL_StopHostNotification" );
	csaFunctions.Add("HLL_StopKeystrokeIntercept" );
	csaFunctions.Add("HLL_Wait" );
	csaFunctions.Add("HLL_WSCtrl" );


	listTranslateFunction->ResetContent();	
	
	for (int k=0; k<csaFunctions.GetSize(); k++)
	{
		listTranslateFunction->AddString( csaFunctions.GetAt(k) );
	}

	listTranslateFunction->SetCurSel(0);



}

void CAG_HLL::loadLanguageList(CListBox* listTranslateLanguage)
{
	listTranslateLanguage->ResetContent();
	listTranslateLanguage->InsertString( 0, "C++" );
	listTranslateLanguage->InsertString( 1, "C#" );
	
	listTranslateLanguage->SetCurSel(0);

}


void CAG_HLL::loadTerminalTypeList(CListBox* listTerminalTypes)
{
	listTerminalTypes->ResetContent();
	listTerminalTypes->InsertString( 0, "3270" );
	listTerminalTypes->InsertString( 1, "5250" );
	listTerminalTypes->InsertString( 2, "VT" );
	
	listTerminalTypes->SetCurSel(0);
}
