// Static Model
#include "stdafx.h"
#include "apigen.h"

#include "CAG_MCS_Ax_3270_VBS_CRL.h"

CAG_MCS_Ax_3270_VBS_CRL::CAG_MCS_Ax_3270_VBS_CRL()
{
	resetVariableFlags();	
}


CAG_MCS_Ax_3270_VBS_CRL::~CAG_MCS_Ax_3270_VBS_CRL()
{
	
}




void CAG_MCS_Ax_3270_VBS_CRL::generateHeader(CStringArray* pcsaHeader,
											 CStringArray* pcsaBody)
{
	
}



void CAG_MCS_Ax_3270_VBS_CRL::appendBody(int nFunctionNum,
										 bool bPromptForValues,
										 CStringArray* pcsaArguments,
										 CStringArray* pcsaHeader,
										 CStringArray* pcsaBody)
{
	CString csViewOutStuff;
	CString csFunctionName, csFunctionNum, csString, csStringLength, csRetCode;

	csFunctionName = pcsaArguments->GetAt( 0 );

	if ( csFunctionName.Find( "Debug", 0 ) != -1 )
	{
		if ( b_Debug )
		{
			b_Debug = FALSE;
		}
		else
		{
			b_Debug = TRUE;
		}
	}

	csViewOutStuff.Format( " " );
	pcsaBody->Add(csViewOutStuff);

	csViewOutStuff.Format( "   // *** %s", csFunctionName );
	pcsaBody->Add(csViewOutStuff);

	checkDebug( b_Debug, csFunctionName, pcsaBody );

	switch ( nFunctionNum )
	{
		case 0:	// AtmFileTransfer::Cancel
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
			
			csViewOutStuff.Format( "   nFlag=0;" );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "   hr = ATMFTObj.Cancel( nFlag );" );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "" );
			pcsaBody->Add(csViewOutStuff);

		}
		break;

		case 1:	// AtmFileTransfer::GetStatus
		case 2:	// AtmFileTransfer::Transfer
		case 3:	// AtmFileTransfer::TransferEx
		case 4:	// AtmFont::GetRectangle
		case 5:	// AtmFont::GetSize
		case 6:	// AtmHllapiCollection::SetAsDefault
		case 7:	// AtmControl::AboutBox
		case 8:	// AtmControl::DoClick
		case 9:	// AtmControl::Refresh
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


		case 28:	// AtmScreen::SetCursor
		case 29:	// AtmScreen::WaitForCursor
		case 30:	// AtmScreen::WaitForKeys
		case 31:	// AtmScreen::WaitForString


	/*
		case :	// AtmScreenAsync::ClearCommunications				// Async only block
		case :	// AtmScreenAsync::ClearScreen
		case :	// AtmScreenAsync::GetColor
		case :	// AtmScreenAsync::ReadStatusLine
		case :	// AtmScreenAsync::ResetTerminal
		case :	// AtmScreenAsync::SetColor
		case :	// AtmScreenVT420::ClearUDKs
	*/
		case 33:	// AtmScreen3270::SendLightPen			// 3270 only block
	/*
		case :	// AtmScreen5250::GetErrLineHostRow		// 5250 only block
		case :	// AtmScreen5250::GetErrLineText
		case :	// AtmScreen5250::GetMsgLineHostRow
		case :	// AtmScreen5250::GetMsgLineText
		case :	// AtmScreen5250::GetSysReqLineColumn
		case :	// AtmScreen5250::GetSysReqLineHostRow
		case :	// AtmScreen5250::GetSysReqLineText
		case :	// AtmScreen5250::SendLMouseClick
	*/
		case 34:	// AtmSelection::GetSelection
		case 35:	// AtmSelection::IsSelected
		case 36:	// AtmSelection::SelectAll
		case 37:	// AtmSelection::SetSelection
		case 38:	// AtmSelection::Unselect
		case 39:	// AtmSession::Attach
		case 40:	// AtmSession::Connect
		case 41:	// AtmSession::Detach
		case 42:	// AtmSession::Disconnect
		case 43:	// AtmSessionStatus::EnumItem
		case 44:	// AtmSessionStatus::GetValue
		case 45:	// AtmSessionStatusCollection::RefreshIfChanged
		case 46:	// AtmTerminal::ViewSession
		case 47:	// AtmWait::Reset
		case 48:	// AtmWait::Wait
		{
			csViewOutStuff.Format( "   // APIGen has not yet implemented this method." );
			pcsaBody->Add(csViewOutStuff);
		}
		break;

		case 27:	// AtmScreen::SendKeys
		{
			csViewOutStuff.Format( "   document.form.sess.Screen.SendKeys(\"%s\", 65536);", pcsaArguments->GetAt(1) );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "" );
			pcsaBody->Add(csViewOutStuff);

		}
		break;

		case 32:	// AtmScreen::WaitHostQuiet
		{
			csViewOutStuff.Format( "   try" );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "   {" );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "      document.form.sess.Screen.WaitHostQuiet(%s);", pcsaArguments->GetAt(1) );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "   }" );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "   catch (e)" );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "   {" );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "      //alert(\"The host did not settle within %s milliseconds\");", pcsaArguments->GetAt(1) );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "   }" );
			pcsaBody->Add(csViewOutStuff);
		}
		break;


	}

	pcsaArguments->RemoveAll();
}

void CAG_MCS_Ax_3270_VBS_CRL::finalize(CStringArray* pcsaBody)
{
	
}


void CAG_MCS_Ax_3270_VBS_CRL::declareVariable(AG_VARIABLE agVariable,
											  CStringArray* pcsaHeader,
											  bool* bValue)
{
	
}

void CAG_MCS_Ax_3270_VBS_CRL::checkDebug(bool b_Debug,
										  CString csFunctionName,
										  CStringArray* pcsaBody)
{
	CString csLocal;
	
	if ( b_Debug )
	{
		csLocal.Format( "   MsgBox( \"%s\" )", csFunctionName );
		pcsaBody->Add(csLocal);
	}
}

void CAG_MCS_Ax_3270_VBS_CRL::resetVariableFlags()
{
   b_nHRESULT = FALSE;
   b_nFLAG = FALSE;
   b_nATMFT = FALSE;
   b_Debug=FALSE;
}