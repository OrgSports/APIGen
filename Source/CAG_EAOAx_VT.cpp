// Static Model
#include "stdafx.h"
#include "apigen.h"

#include "CAG_EAOAx_VT.h"

CAG_EAOAx_VT::CAG_EAOAx_VT()
{
	
}

CAG_EAOAx_VT::~CAG_EAOAx_VT()
{
	
}

void CAG_EAOAx_VT::loadFunctionList(CListBox* listTranslateFunction)
{
	listTranslateFunction->ResetContent();

	csaFunctions.Add( "AtmFileTransfer::Cancel" );
	csaFunctions.Add( "AtmFileTransfer::GetStatus" );
	csaFunctions.Add( "AtmFileTransfer::Transfer" );
	csaFunctions.Add( "AtmFileTransfer::TransferEx" );
	csaFunctions.Add( "AtmFont::GetRectangle" );
	csaFunctions.Add( "AtmFont::GetSize" );
	csaFunctions.Add( "AtmHllapiCollection::SetAsDefault" );
	csaFunctions.Add( "AtmControl::AboutBox" );
	csaFunctions.Add( "AtmControl::DoClick" );
	csaFunctions.Add( "AtmControl::Refresh" );
	csaFunctions.Add( "AtmOIA::GetOIALine" );
	csaFunctions.Add( "AtmOIA::WaitForXStatus" );
	csaFunctions.Add( "AtmPrinterCtrl::ViewSession" );
	csaFunctions.Add( "AtmPrinterLUEscapeSequences::Add" );
	csaFunctions.Add( "AtmPrinterLUEscapeSequences::Remove" );
	csaFunctions.Add( "AtmPrinterLUEscapeSequences::RemoveAll" );
	csaFunctions.Add( "AtmScreen::FieldCount" );
	csaFunctions.Add( "AtmScreen::FindField" );
	csaFunctions.Add( "AtmScreen::FindString" );
	csaFunctions.Add( "AtmScreen::FindStringEx" );
	csaFunctions.Add( "AtmScreen::GetCursor" );
	csaFunctions.Add( "AtmScreen::GetData" );
	csaFunctions.Add( "AtmScreen::GetString" );
	csaFunctions.Add( "AtmScreen::GetStringEx" );
	csaFunctions.Add( "AtmScreen::PutString" );
	csaFunctions.Add( "AtmScreen::PutStringEx" );
	csaFunctions.Add( "AtmScreen::RefreshEvents" );
	csaFunctions.Add( "AtmScreen::SendKeys" );
	csaFunctions.Add( "AtmScreen::SetCursor" );
	csaFunctions.Add( "AtmScreen::WaitForCursor" );
	csaFunctions.Add( "AtmScreen::WaitForKeys" );
	csaFunctions.Add( "AtmScreen::WaitForString" );
	csaFunctions.Add( "AtmScreen::WaitHostQuiet" );

	csaFunctions.Add( "AtmScreenAsync::ClearCommunications" );				// Async only block
	csaFunctions.Add( "AtmScreenAsync::ClearScreen" );
	csaFunctions.Add( "AtmScreenAsync::GetColor" );
	csaFunctions.Add( "AtmScreenAsync::ReadStatusLine" );
	csaFunctions.Add( "AtmScreenAsync::ResetTerminal" );
	csaFunctions.Add( "AtmScreenAsync::SetColor" );
	csaFunctions.Add( "AtmScreenVT420::ClearUDKs" );
/*
	csaFunctions.Add( "AtmScreen3270::SendLightPen" );			// 3270 only block

	csaFunctions.Add( "AtmScreen5250::GetErrLineHostRow" );		// 5250 only block
	csaFunctions.Add( "AtmScreen5250::GetErrLineText" );
	csaFunctions.Add( "AtmScreen5250::GetMsgLineHostRow" );
	csaFunctions.Add( "AtmScreen5250::GetMsgLineText" );
	csaFunctions.Add( "AtmScreen5250::GetSysReqLineColumn" );
	csaFunctions.Add( "AtmScreen5250::GetSysReqLineHostRow" );
	csaFunctions.Add( "AtmScreen5250::GetSysReqLineText" );
	csaFunctions.Add( "AtmScreen5250::SendLMouseClick" );
*/
	csaFunctions.Add( "AtmSelection::GetSelection" );
	csaFunctions.Add( "AtmSelection::IsSelected" );
	csaFunctions.Add( "AtmSelection::SelectAll" );
	csaFunctions.Add( "AtmSelection::SetSelection" );
	csaFunctions.Add( "AtmSelection::Unselect" );
	csaFunctions.Add( "AtmSession::Attach" );
	csaFunctions.Add( "AtmSession::Connect" );
	csaFunctions.Add( "AtmSession::Detach" );
	csaFunctions.Add( "AtmSession::Disconnect" );
	csaFunctions.Add( "AtmSessionStatus::EnumItem" );
	csaFunctions.Add( "AtmSessionStatus::GetValue" );
	csaFunctions.Add( "AtmSessionStatusCollection::RefreshIfChanged" );
	csaFunctions.Add( "AtmTerminal::ViewSession" );
	csaFunctions.Add( "AtmWait::Reset" );
	csaFunctions.Add( "AtmWait::Wait" );


	listTranslateFunction->ResetContent();	
	
	for (int k=0; k<csaFunctions.GetSize(); k++)
	{
		listTranslateFunction->AddString( csaFunctions.GetAt(k) );
	}

	listTranslateFunction->SetCurSel(0);
	
}

