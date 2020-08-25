// Static Model
#include "stdafx.h"
#include "apigen.h"

#include "CAG_EAOAx_5250_CPP.h"

CAG_EAOAx_5250_CPP::CAG_EAOAx_5250_CPP()
{
	resetVariableFlags();	
}

CAG_EAOAx_5250_CPP::~CAG_EAOAx_5250_CPP()
{
	
}


void CAG_EAOAx_5250_CPP::generateHeader(CStringArray* pcsaHeader,
										CStringArray* pcsaBody)
{

	CString csViewOutStuff;

	csViewOutStuff.Format( "//  ****************************************************************************");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "//                 Attachmate APIGen");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "//               EAO for ActiveX 5250 C++ Application");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "// ");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "//  This file is a program that features the use of the EAO for ActiveX 5250");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "//  API written in C++.  This header is to include information");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "//  on how to set up the environment to run this application, how to build");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "//  it, and how to run it.");
	pcsaHeader->Add(csViewOutStuff);


	time_t ltime;
	time( &ltime );

	csViewOutStuff.Format( "//");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "//   Generated:   %s", ctime( &ltime ) );
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "//");
	pcsaHeader->Add(csViewOutStuff);


}




void CAG_EAOAx_5250_CPP::appendBody(int nFunctionNum,
									bool bPromptForValues,
									CStringArray* pcsaArguments,
									CStringArray* pcsaHeader,
									CStringArray* pcsaBody)
{
	CString csViewOutStuff;
	CString csFunctionName, csFunctionNum, csString, csStringLength, csRetCode;

	csFunctionName = pcsaArguments->GetAt( 0 );

	csViewOutStuff.Format( " " );
	pcsaBody->Add(csViewOutStuff);

	csViewOutStuff.Format( "   // *** %s", csFunctionName );
	pcsaBody->Add(csViewOutStuff);

	switch ( nFunctionNum )
	{
		case 0:		// AtmFileTransfer::Cancel
		{
			if ( !b_nHRESULT )
			{
				declareVariable( AG_HRESULT, pcsaHeader, &b_nHRESULT );
			}
			
			if ( !b_nFLAG )
			{
				declareVariable( AG_FLAG, pcsaHeader, &b_nFLAG );
			}
			
			if ( !b_nATMFT )
			{
				declareVariable( AG_ATMFT, pcsaHeader, &b_nATMFT );
			}
			
			csViewOutStuff.Format( "   hr = pIAtmFileTransfer->Cancel( nFlag );" );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "" );
			pcsaBody->Add(csViewOutStuff);

		}
		break;

		case 1:		// AtmFileTransfer::GetStatus
		case 2:		// AtmFileTransfer::Transfer
		case 3:		// AtmFileTransfer::TransferEx
		case 4:		// AtmFont::GetRectangle
		case 5:		// AtmFont::GetSize
		case 6:		// AtmHllapiCollection::SetAsDefault
		case 7:		// AtmControl::AboutBox
		case 8:		// AtmControl::DoClick
		case 9:		// AtmControl::Refresh
		case 10:	// AtmOIA::GetOIALine
		case 11:	// AtmOIA::WaitForXStatus
		case 12:	// AtmPrinterCtrl::ViewSession
		case 13:	// AtmPrinterLUEscapeSequences::Add
		case 14:	// AtmPrinterLUEscapeSequences::Remove
		case 15:	// AtmPrinterLUEscapeSequences::RemoveAll
		case 16:	// AtmScreen::FieldCount
		case 17:	// AtmScreen::FindField
		case 18:	// AtmScreen::FindString
		case 19:	// AtmScreen::FindStringEx
		case 20:	// AtmScreen::GetCursor
		case 21:	// AtmScreen::GetData
		case 22:	// AtmScreen::GetString
		case 23:	// AtmScreen::GetStringEx
		case 24:	// AtmScreen::PutString
		case 25:	// AtmScreen::PutStringEx
		case 26:	// AtmScreen::RefreshEvents
		case 27:	// AtmScreen::SendKeys
		case 28:	// AtmScreen::SetCursor
		case 29:	// AtmScreen::WaitForCursor
		case 30:	// AtmScreen::WaitForKeys
		case 31:	// AtmScreen::WaitForString
		case 32:	// AtmScreen::WaitHostQuiet
/*
		case :	// AtmScreenAsync::ClearCommunications				// Async only block
		case :	// AtmScreenAsync::ClearScreen
		case :	// AtmScreenAsync::GetColor
		case :	// AtmScreenAsync::ReadStatusLine
		case :	// AtmScreenAsync::ResetTerminal
		case :	// AtmScreenAsync::SetColor
		case :	// AtmScreenVT420::ClearUDKs

		case :	// AtmScreen3270::SendLightPen			// 3270 only block

*/	
		case 33:	// AtmScreen5250::GetErrLineHostRow		// 5250 only block
		case 34:	// AtmScreen5250::GetErrLineText
		case 35:	// AtmScreen5250::GetMsgLineHostRow
		case 36:	// AtmScreen5250::GetMsgLineText
		case 37:	// AtmScreen5250::GetSysReqLineColumn
		case 38:	// AtmScreen5250::GetSysReqLineHostRow
		case 39:	// AtmScreen5250::GetSysReqLineText
		case 40:	// AtmScreen5250::SendLMouseClick

		case 41:	// AtmSelection::GetSelection
		case 42:	// AtmSelection::IsSelected
		case 43:	// AtmSelection::SelectAll
		case 44:	// AtmSelection::SetSelection
		case 45:	// AtmSelection::Unselect
		case 46:	// AtmSession::Attach
		case 47:	// AtmSession::Connect
		case 48:	// AtmSession::Detach
		case 49:	// AtmSession::Disconnect
		case 50:	// AtmSessionStatus::EnumItem
		case 51:	// AtmSessionStatus::GetValue
		case 52:	// AtmSessionStatusCollection::RefreshIfChanged
		case 53:	// AtmTerminal::ViewSession
		case 54:	// AtmWait::Reset
		case 55:	// AtmWait::Wait
		{
			csViewOutStuff.Format( "   // APIGen has not yet implemented this method." );
			pcsaBody->Add(csViewOutStuff);
		}
		break;
	}

	pcsaArguments->RemoveAll();
}



void CAG_EAOAx_5250_CPP::finalize(CStringArray* pcsaBody)
{
	CString csViewOutStuff;

	if ( b_nATMFT )
	{
		csViewOutStuff.Format( "   free pIAtmFileTransfer;" );
		pcsaBody->Add(csViewOutStuff);
	}

	csViewOutStuff.Format( " " );
	pcsaBody->Add(csViewOutStuff);

	csViewOutStuff.Format( "}");
	pcsaBody->Add(csViewOutStuff);

	csViewOutStuff.Format( "" );
	pcsaBody->Add(csViewOutStuff);

}



void CAG_EAOAx_5250_CPP::declareVariable(AG_VARIABLE agVariable,
										 CStringArray* pcsaHeader,
										 bool* bValue)
{
	CString csLocal;
	*bValue = TRUE;
	
	switch ( agVariable )
	{
		case AG_ATMFT:
		{
			csLocal.Format( "   IAtmFileTransfer* pIAtmFileTransfer;");
		}
		break;

		case AG_HRESULT:
		{
			csLocal.Format( "   HRESULT hr;" );
		}
		break;

		case AG_FLAG:
		{
			csLocal.Format( "   long nFlag=0;" );
		}
		break;

	}

	pcsaHeader->Add(csLocal);
	
}


void CAG_EAOAx_5250_CPP::checkDebug(bool b_Debug,
								 CString csFunctionName,
								 CStringArray* pcsaBody)
{
	
}


void CAG_EAOAx_5250_CPP::resetVariableFlags()
{
   b_nHRESULT = FALSE;
   b_nFLAG = FALSE;
   b_nATMFT = FALSE;
   b_Debug=FALSE;
}