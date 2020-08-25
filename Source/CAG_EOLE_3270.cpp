// Static Model
#include "stdafx.h"
#include "apigen.h"

#include "CAG_EOLE_3270.h"


CAG_EOLE_3270::CAG_EOLE_3270()
{
	
}

CAG_EOLE_3270::~CAG_EOLE_3270()
{
	
}

void CAG_EOLE_3270::loadFunctionList(CListBox* listTranslateFunction)
{
	csaFunctions.RemoveAll();

	listTranslateFunction->ResetContent();

	csaFunctions.Add( "OIA.ConnectionStatus" );
	csaFunctions.Add( "OIA.ErrorStatus" );
	csaFunctions.Add( "OIA.Updated" );	
	csaFunctions.Add( "OIA.Value" );
	csaFunctions.Add( "OIA.XStatus" );

	csaFunctions.Add( "Screen::Col" );
	csaFunctions.Add( "Screen::Copy" );
	csaFunctions.Add( "Screen::FieldAttribute" );
	csaFunctions.Add( "Screen::GetString" );
	csaFunctions.Add( "Screen::MoveTo" );
	csaFunctions.Add( "Screen::PutString" );	// 10
	csaFunctions.Add( "Screen::Row" );
	csaFunctions.Add( "Screen::Search" );
	csaFunctions.Add( "Screen::SelectAll" );	// use this with and before Copy	
	csaFunctions.Add( "Screen::SendKeys" );
	csaFunctions.Add( "Screen::Updated" );

	csaFunctions.Add( "Screen::WaitForCursor" );
	csaFunctions.Add( "Screen::WaitForCursorMove" );
	csaFunctions.Add( "Screen::WaitForKeys" );
	csaFunctions.Add( "Screen::WaitForStream" );
	csaFunctions.Add( "Screen::WaitForString" );	// 20
	csaFunctions.Add( "Screen::WaitHostQuiet" );
	csaFunctions.Add( "Session::Activate" );
	csaFunctions.Add( "Session::ClearComm" );
	csaFunctions.Add( "Session::ClearHistory" );
	csaFunctions.Add( "Session::Close" );
	csaFunctions.Add( "Session::CloseEx" );
	csaFunctions.Add( "Session::ClosePrintJob" );
	csaFunctions.Add( "Session::Connected" );
	csaFunctions.Add( "Session::EnlargeFont" );
	csaFunctions.Add( "Session::FileTransferHostOS" );	// 30
	csaFunctions.Add( "Session::FileTransferOptions" );
	csaFunctions.Add( "Session::FileTransferScheme" );
	csaFunctions.Add( "Session::Font" );
	csaFunctions.Add( "Session::Height" );
	csaFunctions.Add( "Session::HoldScreen" );
	csaFunctions.Add( "Session::HostName" );
	csaFunctions.Add( "Session::InvokeSettingsDialog" );
	csaFunctions.Add( "Session::KeyboardLocked" );
	csaFunctions.Add( "Session::KeyMap" );
	csaFunctions.Add( "Session::Language" );		// 40
	csaFunctions.Add( "Session::Local" );
	csaFunctions.Add( "Session::Menu" );
	csaFunctions.Add( "Session::Name" );
	csaFunctions.Add( "Session::PrintDisplay" );
	csaFunctions.Add( "Session::Quiet" );
	csaFunctions.Add( "Session::ReceiveFile" );
	csaFunctions.Add( "Session::ReduceFont" );
	csaFunctions.Add( "Session::Reset" );
	csaFunctions.Add( "Session::Save" );
	csaFunctions.Add( "Session::SaveAs" );			// 50
	csaFunctions.Add( "Session::Saved" );
	csaFunctions.Add( "Session::SendFile" );
	csaFunctions.Add( "Session::Title" );
	csaFunctions.Add( "Session::TransferFile" );
	csaFunctions.Add( "Session::Type" );
	csaFunctions.Add( "Session::UpdateStatusBar" );
	csaFunctions.Add( "Session::Visible" );
	csaFunctions.Add( "Session::WaitForDisconnect" );
	csaFunctions.Add( "Session::WaitForTimer" );
	csaFunctions.Add( "Session::Width" );			// 60
	csaFunctions.Add( "Session::WindowHandle" );
	csaFunctions.Add( "Session::WindowState" );
	csaFunctions.Add( "Sessions::Open" );
	csaFunctions.Add( "Sessions::Count" );
	csaFunctions.Add( "Sessions::CloseAll" );
	csaFunctions.Add( "System::ActiveSession" );
	csaFunctions.Add( "System::Name" );
	csaFunctions.Add( "System::Quit" );
	csaFunctions.Add( "System::Time" );
	csaFunctions.Add( "System::TimeoutValue" );		// 70
	csaFunctions.Add( "System::Version" );
	csaFunctions.Add( "Debug" );

	listTranslateFunction->ResetContent();	
	
	for (int k=0; k<csaFunctions.GetSize(); k++)
	{
		listTranslateFunction->AddString( csaFunctions.GetAt(k) );
	}

	listTranslateFunction->SetCurSel(0);

}


