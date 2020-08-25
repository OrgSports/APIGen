#include "stdafx.h"
#include "APIGen.h"
#include "APIGenDlg.h"

/****************************************************************************DC
	Function	:	CAPIGenDlg::ShowEAOAx5250Controls()

	Purpose		:	Show the controls for the EAO ActiveX function parameters.

	Note		:	TODO: This isn't done, and won't be until it if found
					that the EAOJ is insufficient.

*****************************************************************************/
void CAPIGenDlg::ShowEAOAx5250Controls( int nFunction )
{
	HideParameterControls();
	csaLabels.RemoveAll();
	BOOL bYouShouldGo=TRUE;

	switch ( nFunction )
	{
		// no parameters
		case 0:		// AtmFileTransfer::Cancel
		case 1:		// AtmFileTransfer::GetStatus
		case 4:		// AtmFont::GetRectangle
		case 5:		// AtmFont::GetSize
		case 6:		// AtmHllapiCollection::SetAsDefault
		case 7:		// AtmControl::AboutBox
		case 8:		// AtmControl::DoClick
		case 9:		// AtmControl::Refresh
		case 12:	// AtmPrinterCtrl::ViewSession
		case 13:	// AtmPrinterLUEscapeSequences::Add
		case 14:	// AtmPrinterLUEscapeSequences::Remove
		case 15:	// AtmPrinterLUEscapeSequences::RemoveAll
		case 20:	// AtmScreen::GetCursor
		case 26:	// AtmScreen::RefreshEvents
		case 33:	// AtmScreen5250::GetErrLineHostRow
		case 34:	// AtmScreen5250::GetErrLineText
		case 35:	// AtmScreen5250::GetMsgLineHostRow
		case 36:	// AtmScreen5250::GetMsgLineText
		case 37:	// AtmScreen5250::GetSysReqLineColumn
		case 38:	// AtmScreen5250::GetSysReqLineHostRow
		case 39:	// AtmScreen5250::GetSysReqLineText
		case 41:	// AtmSelection::GetSelection
		case 42:	// AtmSelection::IsSelected
		case 43:	// AtmSelection::SelectAll
		case 45:	// AtmSelection::Unselect
		case 48:	// AtmSession::Detach
		case 52:	// AtmSessionStatusCollection::RefreshIfChanged
		case 53:	// AtmTerminal::ViewSession
		case 54:	// AtmWait::Reset
		{
		}
		break;

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

		case 2:	// AtmFileTransfer::Transfer
		{
			csaLabels.Add("Host file name");
			csaLabels.Add("PC file name");
			csaLabels.Add("Direction");
			csaLabels.Add("FT options");
			csaLabels.Add("Wait options");
		}
		break;

		case 3:	// AtmFileTransfer::TransferEx
		{
			csaLabels.Add("PC file name");
			csaLabels.Add("Direction");
			csaLabels.Add("Host command line");
			csaLabels.Add("FT options");
			csaLabels.Add("Wait options");
		}
		break;

		case 10:	// AtmOIA::GetOIALine
		{
			csaLabels.Add("Format");
		}
		break;

		case 11:	// AtmOIA::WaitForXStatus
		{
			csaLabels.Add("Wait condition");
			csaLabels.Add("X status array name");
			csaLabels.Add("Wait option");
		}
		break;

		case 16:	// AtmScreen::FieldCount
		{
			csaLabels.Add("Field type");
		}
		break;

		case 17:	// AtmScreen::FindField
		{
			csaLabels.Add("Start row");
			csaLabels.Add("Start column");
			csaLabels.Add("Direction");
			csaLabels.Add("Field type");
			csaLabels.Add("Wrap? (t/f)");
		}
		break;

		case 18:	// AtmScreen::FindString
		{
			csaLabels.Add("String");
			csaLabels.Add("Start row");
			csaLabels.Add("Start column");
		}
		break;

		case 19:	// AtmScreen::FindStringEx
		{
			csaLabels.Add("String");
			csaLabels.Add("Start row");
			csaLabels.Add("Start column");
			csaLabels.Add("End row");
			csaLabels.Add("End column");
			csaLabels.Add("Area type");
			csaLabels.Add("Wrap? (t/f)");
			csaLabels.Add("Direction");
		}
		break;

		case 21:	// AtmScreen::GetData
		{
			csaLabels.Add("Start row");
			csaLabels.Add("Start column");
			csaLabels.Add("Number of chars");
			csaLabels.Add("Number of positions");
			csaLabels.Add("Data type");
			csaLabels.Add("Data format");
			csaLabels.Add("Code page");
		}
		break;

		case 22:	// AtmScreen::GetString
		{
			csaLabels.Add("Start row");
			csaLabels.Add("Start column");
			csaLabels.Add("Length");
		}
		break;

		case 23:	// AtmScreen::GetStringEx
		{
			csaLabels.Add("Start row");
			csaLabels.Add("Start column");
			csaLabels.Add("End row");
			csaLabels.Add("End column");
			csaLabels.Add("Area type");
			csaLabels.Add("Wrap? (t/f)");
			csaLabels.Add("Field type");
			csaLabels.Add("Flags");
		}
		break;

		case 24:	// AtmScreen::PutString
		{
			csaLabels.Add("String");
			csaLabels.Add("Row");
			csaLabels.Add("Column");
		}
		break;

		case 25:	// AtmScreen::PutStringEx
		{
			csaLabels.Add("String");
			csaLabels.Add("Start row");
			csaLabels.Add("Start column");
			csaLabels.Add("End row");
			csaLabels.Add("End column");
			csaLabels.Add("Area type");
			csaLabels.Add("Wrap? (t/f)");
			csaLabels.Add("Handle protected");
			csaLabels.Add("Fill (t/f)");
		}
		break;

		case 27:	// AtmScreen::SendKeys
		{
			csaLabels.Add("String");
			csaLabels.Add("Mnemonic type");
		}
		break;

		case 28:	// AtmScreen::SetCursor
		case 40:	// AtmScreen5250::SendLMouseClick
		{
			csaLabels.Add("Row");
			csaLabels.Add("Column");
		}
		break;

		case 29:	// AtmScreen::WaitForCursor
		{
			csaLabels.Add("Row");
			csaLabels.Add("Column");
			csaLabels.Add("Options");
		}
		break;

		case 30:	// AtmScreen::WaitForKeys
		{
			csaLabels.Add("Keys");
			csaLabels.Add("Mnemonic type");
			csaLabels.Add("Mode");
			csaLabels.Add("Wait options");
		}
		break;

		case 31:	// AtmScreen::WaitForString
		{
			csaLabels.Add("String");
			csaLabels.Add("Row");
			csaLabels.Add("Column");
			csaLabels.Add("Options");
		}
		break;

		case 32:	// AtmScreen::WaitHostQuiet
		{
			csaLabels.Add("Settle time");
			csaLabels.Add("Wait options");
		}
		break;

		case 44:	// AtmSelection::SetSelection
		{
			csaLabels.Add("Start row");
			csaLabels.Add("Start column");
			csaLabels.Add("End row");
			csaLabels.Add("End column");
			csaLabels.Add("Area type");
		}
		break;

		case 46:	// AtmSession::Attach
		{
			csaLabels.Add("Attach mode");
		}
		break;

		case 47:	// AtmSession::Connect
		case 49:	// AtmSession::Disconnect
		{
			csaLabels.Add("Wait option");
		}
		break;

		case 50:	// AtmSessionStatus::EnumItem
		case 51:	// AtmSessionStatus::GetValue
		{
			csaLabels.Add("Status item ID");
		}
		break;

		case 55:	// AtmWait::Wait
		{
			csaLabels.Add("Timeout");
		}
		break;

		default:
		{
			m_groupNoParametersNeeded.ShowWindow( SW_SHOW  );
		}

	}

	ShowEditControls( &csaLabels );

}


/****************************************************************************DC
	Function	:	CAPIGenDlg::LoadEAOAx5250ArgumentArray()

	Purpose		:	Load the function arguments for EAO for ActiveX.

*****************************************************************************/
void CAPIGenDlg::LoadEAOAx5250ArgumentArray( int* nFunctionPosition, BOOL bPromptForValues )
{
	CString	csFunctionName, csFunctionNum;
	
	UpdateData();
	
	*nFunctionPosition=0;

	*nFunctionPosition = m_listTranslateFunction.GetCurSel();
	m_listTranslateFunction.GetText( *nFunctionPosition, csFunctionName );

	// full function name text
	csaArguments.Add( csFunctionName );

	if ( bPromptForValues )
	{
		switch ( *nFunctionPosition )
		{
			case 0:		// AtmFileTransfer::Cancel
			case 1:		// AtmFileTransfer::GetStatus
			case 4:		// AtmFont::GetRectangle
			case 5:		// AtmFont::GetSize
			case 6:		// AtmHllapiCollection::SetAsDefault
			case 7:		// AtmControl::AboutBox
			case 8:		// AtmControl::DoClick
			case 9:		// AtmControl::Refresh
			case 12:	// AtmPrinterCtrl::ViewSession
			case 13:	// AtmPrinterLUEscapeSequences::Add
			case 14:	// AtmPrinterLUEscapeSequences::Remove
			case 15:	// AtmPrinterLUEscapeSequences::RemoveAll
			case 20:	// AtmScreen::GetCursor
			case 26:	// AtmScreen::RefreshEvents
			case 33:	// AtmScreen5250::GetErrLineHostRow
			case 34:	// AtmScreen5250::GetErrLineText
			case 35:	// AtmScreen5250::GetMsgLineHostRow
			case 36:	// AtmScreen5250::GetMsgLineText
			case 37:	// AtmScreen5250::GetSysReqLineColumn
			case 38:	// AtmScreen5250::GetSysReqLineHostRow
			case 39:	// AtmScreen5250::GetSysReqLineText
			case 41:	// AtmSelection::GetSelection
			case 42:	// AtmSelection::IsSelected
			case 43:	// AtmSelection::SelectAll
			case 45:	// AtmSelection::Unselect
			case 48:	// AtmSession::Detach
			case 52:	// AtmSessionStatusCollection::RefreshIfChanged
			case 53:	// AtmTerminal::ViewSession
			case 54:	// AtmWait::Reset
			{
			}
			break;

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

			case 10:	// AtmOIA::GetOIALine
			case 16:	// AtmScreen::FieldCount
			case 46:	// AtmSession::Attach
			case 47:	// AtmSession::Connect
			case 49:	// AtmSession::Disconnect
			case 50:	// AtmSessionStatus::EnumItem
			case 51:	// AtmSessionStatus::GetValue
			case 55:	// AtmWait::Wait
			{
				// single argument
				csaArguments.Add( m_csEditArgument1 );
			}
			break;


			case 27:	// AtmScreen::SendKeys
			case 28:	// AtmScreen::SetCursor
			case 32:	// AtmScreen::WaitHostQuiet
			case 40:	// AtmScreen5250::SendLMouseClick
			{
				// first argument
				csaArguments.Add( m_csEditArgument1 );

				// second argument
				csaArguments.Add( m_csEditArgument3 );
			}
			break;


			case 11:	// AtmOIA::WaitForXStatus
			case 18:	// AtmScreen::FindString
			case 22:	// AtmScreen::GetString
			case 24:	// AtmScreen::PutString
			case 29:	// AtmScreen::WaitForCursor
			{
				// first argument
				csaArguments.Add( m_csEditArgument1 );

				// second argument
				csaArguments.Add( m_csEditArgument3 );

				// third argument
				csaArguments.Add( m_csEditArgument4 );
			}
			break;


			case 30:	// AtmScreen::WaitForKeys
			case 31:	// AtmScreen::WaitForString
			{
				// first argument
				csaArguments.Add( m_csEditArgument1 );

				// second argument
				csaArguments.Add( m_csEditArgument3 );

				// third argument
				csaArguments.Add( m_csEditArgument4 );

				// fourth argument
				csaArguments.Add( m_csEditArgument5 );
			}
			break;


			case 2:	// AtmFileTransfer::Transfer
			case 3:	// AtmFileTransfer::TransferEx
			case 17:	// AtmScreen::FindField
			case 44:	// AtmSelection::SetSelection
			{
				// first argument
				csaArguments.Add( m_csEditArgument1 );

				// second argument
				csaArguments.Add( m_csEditArgument3 );

				// third argument
				csaArguments.Add( m_csEditArgument4 );

				// fourth argument
				csaArguments.Add( m_csEditArgument5 );

				// fifth argument
				csaArguments.Add( m_csEditArgument6 );
			}
			break;


			case 21:	// AtmScreen::GetData
			{
				// first argument
				csaArguments.Add( m_csEditArgument1 );

				// second argument
				csaArguments.Add( m_csEditArgument3 );

				// third argument
				csaArguments.Add( m_csEditArgument4 );

				// fourth argument
				csaArguments.Add( m_csEditArgument5 );

				// fifth argument
				csaArguments.Add( m_csEditArgument6 );

				// sixth argument
				csaArguments.Add( m_csEditArgument7 );

				// seventh argument
				csaArguments.Add( m_csEditArgument8 );
			}
			break;


			case 19:	// AtmScreen::FindStringEx
			case 23:	// AtmScreen::GetStringEx
			{
				// first argument
				csaArguments.Add( m_csEditArgument1 );

				// second argument
				csaArguments.Add( m_csEditArgument3 );

				// third argument
				csaArguments.Add( m_csEditArgument4 );

				// fourth argument
				csaArguments.Add( m_csEditArgument5 );

				// fifth argument
				csaArguments.Add( m_csEditArgument6 );

				// sixth argument
				csaArguments.Add( m_csEditArgument7 );

				// seventh argument
				csaArguments.Add( m_csEditArgument8 );

				// eighth argument
				csaArguments.Add( m_csEditArgument9 );
			}
			break;


			case 25:	// AtmScreen::PutStringEx
			{
				// first argument
				csaArguments.Add( m_csEditArgument1 );

				// second argument
				csaArguments.Add( m_csEditArgument3 );

				// third argument
				csaArguments.Add( m_csEditArgument4 );

				// fourth argument
				csaArguments.Add( m_csEditArgument5 );

				// fifth argument
				csaArguments.Add( m_csEditArgument6 );

				// sixth argument
				csaArguments.Add( m_csEditArgument7 );

				// seventh argument
				csaArguments.Add( m_csEditArgument8 );

				// eighth argument
				csaArguments.Add( m_csEditArgument9 );

				// ninth argument
				csaArguments.Add( m_csEditArgument10 );
			}
			break;

			default:
			{
			}
		}
	}
	else
	{
		switch ( *nFunctionPosition )
		{
			// no parameters
			case 0:		// AtmFileTransfer::Cancel
			case 1:		// AtmFileTransfer::GetStatus
			case 4:		// AtmFont::GetRectangle
			case 5:		// AtmFont::GetSize
			case 6:		// AtmHllapiCollection::SetAsDefault
			case 7:		// AtmControl::AboutBox
			case 8:		// AtmControl::DoClick
			case 9:		// AtmControl::Refresh
			case 12:	// AtmPrinterCtrl::ViewSession
			case 13:	// AtmPrinterLUEscapeSequences::Add
			case 14:	// AtmPrinterLUEscapeSequences::Remove
			case 15:	// AtmPrinterLUEscapeSequences::RemoveAll
			case 20:	// AtmScreen::GetCursor
			case 26:	// AtmScreen::RefreshEvents
		case 33:	// AtmScreen5250::GetErrLineHostRow
		case 34:	// AtmScreen5250::GetErrLineText
		case 35:	// AtmScreen5250::GetMsgLineHostRow
		case 36:	// AtmScreen5250::GetMsgLineText
		case 37:	// AtmScreen5250::GetSysReqLineColumn
		case 38:	// AtmScreen5250::GetSysReqLineHostRow
		case 39:	// AtmScreen5250::GetSysReqLineText
			case 41:	// AtmSelection::GetSelection
			case 42:	// AtmSelection::IsSelected
			case 43:	// AtmSelection::SelectAll
			case 45:	// AtmSelection::Unselect
			case 48:	// AtmSession::Detach
			case 52:	// AtmSessionStatusCollection::RefreshIfChanged
			case 53:	// AtmTerminal::ViewSession
			case 54:	// AtmWait::Reset
			{
			}
			break;

	/*
			case :	// AtmScreenAsync::ClearCommunications				// Async only block
			case :	// AtmScreenAsync::ClearScreen
			case :	// AtmScreenAsync::GetColor
			case :	// AtmScreenAsync::ReadStatusLine
			case :	// AtmScreenAsync::ResetTerminal
			case :	// AtmScreenAsync::SetColor
			case :	// AtmScreenVT420::ClearUDKs
	*/
	/*
			case 33:	// AtmScreen3270::SendLightPen			// 3270 only block
*/

			case 2:	// AtmFileTransfer::Transfer
			{
				csaArguments.Add("hostfile txt");
				csaArguments.Add("pcfile.txt");
				csaArguments.Add("ATM_FT_PCTOHOST");
				csaArguments.Add("VT_EMPTY");
				csaArguments.Add("ATM_WAIT_FOREVER");
			}
			break;

			case 3:	// AtmFileTransfer::TransferEx
			{
				csaArguments.Add("hostfile txt");
				csaArguments.Add("pcfile.txt");
				csaArguments.Add("ATM_FT_PCTOHOST");
				csaArguments.Add("VT_EMPTY");
				csaArguments.Add("ATM_WAIT_FOREVER,");
			}
			break;

			case 10:	// AtmOIA::GetOIALine
			{
				csaArguments.Add("ATM_OIA_FMT_ASCII");
			}
			break;

			case 11:	// AtmOIA::WaitForXStatus
			{
				csaArguments.Add("ATM_OIA_XSW_CLEAR");
				csaArguments.Add("");
				csaArguments.Add("4000");
			}
			break;

			case 16:	// AtmScreen::FieldCount
			{
				csaArguments.Add("ATM_FIELDTYPE_ANY");
			}
			break;

			case 17:	// AtmScreen::FindField
			{
				csaArguments.Add("1");
				csaArguments.Add("2");
				csaArguments.Add("ATM_FINDFIELD_CURRENT");
				csaArguments.Add("ATM_FIELDTYPE_UNPROTECTED	");
				csaArguments.Add("ATM_WRAP_OFF");
			}
			break;

			case 18:	// AtmScreen::FindString
			{
				csaArguments.Add("Ready:");
				csaArguments.Add("16");
				csaArguments.Add("6");
			}
			break;

			case 19:	// AtmScreen::FindStringEx
			{
				csaArguments.Add("Ready:");
				csaArguments.Add("16");
				csaArguments.Add("6");
				csaArguments.Add("21");
				csaArguments.Add("80");
				csaArguments.Add("ATM_AREA_STREAM");
				csaArguments.Add("ATM_WRAP_OFF");
				csaArguments.Add("ATM_DIRECTION_FORWARD");
			}
			break;

			case 21:	// AtmScreen::GetData
			{
				csaArguments.Add("20");
				csaArguments.Add("17");
				csaArguments.Add("8");
				csaArguments.Add("1");
				csaArguments.Add("ATM_GETDATA_TYPE_HLLAPI");
				csaArguments.Add("ATM_GETDATA_FMT_TEXT");
				csaArguments.Add("1252");
			}
			break;

			case 22:	// AtmScreen::GetString
			{
				csaArguments.Add("1");
				csaArguments.Add("2");
				csaArguments.Add("12");
			}
			break;

			case 23:	// AtmScreen::GetStringEx
			{
				csaArguments.Add("16");
				csaArguments.Add("6");
				csaArguments.Add("21");
				csaArguments.Add("80");
				csaArguments.Add("ATM_AREA_STREAM");
				csaArguments.Add("ATM_WRAP_OFF");
				csaArguments.Add("ATM_SCREENATTR_ANY");
				csaArguments.Add("ATM_GETSTRING_CR");
			}
			break;

			case 24:	// AtmScreen::PutString
			{
				csaArguments.Add("Freakout");
				csaArguments.Add("12");
				csaArguments.Add("67");
			}
			break;

			case 25:	// AtmScreen::PutStringEx
			{
				csaArguments.Add("Freakout");
				csaArguments.Add("12");
				csaArguments.Add("67");
				csaArguments.Add("12");
				csaArguments.Add("80");
				csaArguments.Add("ATM_AREA_STREAM");
				csaArguments.Add("ATM_WRAP_OFF");
				csaArguments.Add("ATM_PUTSTRING_STOP");
				csaArguments.Add("VARIANT_TRUE");
			}
			break;

			case 27:	// AtmScreen::SendKeys
			{
				csaArguments.Add("@E");
				csaArguments.Add("ATM_KEYTYPE_HLLAPI");
			}
			break;

			case 28:	// AtmScreen::SetCursor
			case 40:	// AtmScreen5250::SendLMouseClick
			{
				csaArguments.Add("23");
				csaArguments.Add("17");
			}
			break;

			case 29:	// AtmScreen::WaitForCursor
			{
				csaArguments.Add("20");
				csaArguments.Add("17");
				csaArguments.Add("ATM_WAIT_FOREVER");
			}
			break;

			case 30:	// AtmScreen::WaitForKeys
			{
				csaArguments.Add("@E");
				csaArguments.Add("ATM_KEYTYPE_HLLAPI");
				csaArguments.Add("ATM_WAITFORKEYS_AID");
				csaArguments.Add("10000");
			}
			break;

			case 31:	// AtmScreen::WaitForString
			{
				csaArguments.Add("Ready:");
				csaArguments.Add("0");
				csaArguments.Add("0");
				csaArguments.Add("ATM_WAIT_ASYNC");
			}
			break;

			case 32:	// AtmScreen::WaitHostQuiet
			{
				csaArguments.Add("1000");
				csaArguments.Add("20000");
			}
			break;


			case 44:	// AtmSelection::SetSelection
			{
				csaArguments.Add("1");
				csaArguments.Add("2");
				csaArguments.Add("3");
				csaArguments.Add("9");
				csaArguments.Add("ATM_AREA_BLOCK");
			}
			break;

			case 46:	// AtmSession::Attach
			{
				csaArguments.Add("ATM_ATTACH_LOADIFNECESSARY");
			}
			break;

			case 47:	// AtmSession::Connect
			case 49:	// AtmSession::Disconnect
			{
				csaArguments.Add("ATM_WAIT_FOREVER");
			}
			break;

			case 50:	// AtmSessionStatus::EnumItem
			case 51:	// AtmSessionStatus::GetValue
			{
				csaArguments.Add("State.Description");
			}
			break;

			case 55:	// AtmWait::Wait
			{
				csaArguments.Add("ATM_WAIT_FOREVER");
			}
			break;

			default:
			{
				m_groupNoParametersNeeded.ShowWindow( SW_SHOW  );
			}
		}
	}
}
