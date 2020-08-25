#include "stdafx.h"
#include "APIGen.h"
#include "APIGenDlg.h"

/****************************************************************************DC
	Function	:	CAPIGenDlg::ShowEAOAxControls()

	Purpose		:	Show the controls for the EAO ActiveX function parameters.

	Note		:	TODO: This isn't done, and won't be until it if found
					that the EAOJ is insufficient.

*****************************************************************************/
void CAPIGenDlg::ShowEAOAxControls( int nFunction )
{
	HideParameterControls();
	csaLabels.RemoveAll();
	BOOL bYouShouldGo=TRUE;

	switch ( nFunction )
	{
		case 2:		// AtmConnectionWait::Reset
		case 3:		// AtmConnectionWait::Wait
		case 4:		// AtmCursorWait::Reset
		case 5:		// AtmCursorWait::Wait
		case 6:		// AtmEdit3270::CanCopy
		case 7:		// AtmEdit3270::CanCut
		case 8:		// AtmEdit3270::CanPaste
		case 9:		// AtmEdit3270::Copy
		case 10:	// AtmEdit3270::CopyData
		case 11:	// AtmEdit3270::Cut
		case 12:	// AtmEdit3270::CutData
		case 13:	// AtmEdit3270::Delete
		case 14:	// AtmEdit3270::Paste
		case 15:	// AtmEdit3270::PasteContinue
		case 16:	// AtmEdit3270::PasteData
		case :	// AtmFileTransfer::Cancel
		case :	// AtmFileTransfer::GetStatus
		case :	// AtmFileTransfer::Transfer
		case :	// AtmFileTransfer::TransferEx
		case 21:	// AtmFileTransfer::TransferFiles
		case 22:	// AtmFileTransferWait::Reset
		case 23:	// AtmFileTransferWait::Wait
		case :	// AtmFont::GetRectangle
		case :	// AtmFont::GetSize
		case 26:	// AtmGraphics3270::GetCursor
		case 27:	// AtmGraphics3270::GetPictureList 
		case 28:	// AtmGraphics3270::RefreshEvents
		case 29:	// AtmGraphics3270::SetCursor
		case 30:	// AtmHllapiCollection::Add
		case 31:	// AtmHllapiCollection::IndexOf
		case 32:	// AtmHllapiCollection::Move
		case 33:	// AtmHllapiCollection::Remove
		case 34:	// AtmHllapiCollection::RemoveAll
		case :	// AtmHllapiCollection::SetAsDefault
		case 36:	// AtmHostQuietWait::Reset
		case 37:	// AtmHostQuietWait::Wait
		case 38:	// AtmIUnknownCollection::Add
		case 39:	// AtmIUnknownCollection::IndexOf
		case 40:	// AtmIUnknownCollection::Move
		case 41:	// AtmIUnknownCollection::Remove
		case 42:	// AtmIUnknownCollection::RemoveAll
		case 43:	// AtmIUnknownCollection::SetAsDefault
		case 44:	// AtmKeyWait::Reset
		case 45:	// AtmKeyWait::Wait
		case 46:	// AtmLongCollection::Add
		case 47:	// AtmLongCollection::IndexOf
		case 48:	// AtmLongCollection::Move
		case 49:	// AtmLongCollection::Remove
		case 50:	// AtmLongCollection::RemoveAll
		case 51:	// AtmLongCollection::SetAsDefault
		
		case :	// AtmControl::AboutBox
		case :	// AtmControl::DoClick
		case :	// AtmControl::Refresh
		
		case 52:	// AtmObjectCollection::Add
		case 53:	// AtmObjectCollection::IndexOf
		case 54:	// AtmObjectCollection::Move
		case 55:	// AtmObjectCollection::Remove
		case 56:	// AtmObjectCollection::RemoveAll
		case 57:	// AtmObjectCollection::SetAsDefault
		
		case :	// AtmOIA::GetOIALine
		case :	// AtmOIA::WaitForXStatus

		case 58:	// AtmOia3270::GetAttributeStatus
		case 59:	// AtmOia3270::GetOIALine
		case 60:	// AtmOia3270::WaitForXStatus
		case 61:	// AtmPrinter3270::AlignForm
		case 62:	// AtmPrinter3270::SendCommand
		case 63:	// AtmPrinterCtrl::AboutBox
		case 64:	// AtmPrinterCtrl::DoClick
		case 65:	// AtmPrinterCtrl::Refresh
		case :	// AtmPrinterCtrl::ViewSession
		case 67:	// AtmPrinterLUEscapeSequences::Add
		case 68:	// AtmPrinterLUEscapeSequences::Remove
		case 69:	// AtmPrinterLUEscapeSequences::RemoveAll
		case 70:	// AtmPrinterOia3270::GetAttributeStatus
		case 71:	// AtmPrinterOia3270::GetOIALine
		case 72:	// AtmPrinterOia3270::WaitForXStatus
		case 73:	// AtmPrinterRenderer::OnStatusChanged
		case 74:	// AtmPrintScreen::PrintScreen

		case :	// AtmScreen::FieldCount
		case :	// AtmScreen::FindField
		case :	// AtmScreen::FindString
		case :	// AtmScreen::FindStringEx
		case :	// AtmScreen::GetCursor
		case :	// AtmScreen::GetData
		case :	// AtmScreen::GetString
		case :	// AtmScreen::GetStringEx
		case :	// AtmScreen::PutString
		case :	// AtmScreen::PutStringEx
		case :	// AtmScreen::RefreshEvents
		case :	// AtmScreen::SendKeys
		case :	// AtmScreen::SetCursor
		case :	// AtmScreen::WaitForCursor
		case :	// AtmScreen::WaitForKeys
		case :	// AtmScreen::WaitForString
		case :	// AtmScreen::WaitHostQuiet

		case :	// AtmScreenAsync::ClearCommunications				// Async only block
		case :	// AtmScreenAsync::ClearScreen
		case :	// AtmScreenAsync::GetColor
		case :	// AtmScreenAsync::ReadStatusLine
		case :	// AtmScreenAsync::ResetTerminal
		case :	// AtmScreenAsync::SetColor

		case :	// AtmScreenVT420::ClearUDKs


		case :	// AtmScreen3270::SendLightPen			// 3270 only block

		case :	// AtmScreen5250::GetErrLineHostRow		// 5250 only block
		case :	// AtmScreen5250::GetErrLineText
		case :	// AtmScreen5250::GetMsgLineHostRow
		case :	// AtmScreen5250::GetMsgLineText
		case :	// AtmScreen5250::GetSysReqLineColumn
		case :	// AtmScreen5250::GetSysReqLineHostRow
		case :	// AtmScreen5250::GetSysReqLineText
		case :	// AtmScreen5250::SendLMouseClick

		case :	// AtmSelection::GetSelection
		case :	// AtmSelection::IsSelected
		case :	// AtmSelection::SelectAll
		case :	// AtmSelection::SetSelection
		case :	// AtmSelection::Unselect

		case 93:	// AtmSelection3270::GetSelection
		case 94:	// AtmSelection3270::IsSelected
		case 95:	// AtmSelection3270::SelectAll
		case 96:	// AtmSelection3270::SetSelection
		case 97:	// AtmSelection3270::Unselect

		case :	// AtmSession::Attach
		case :	// AtmSession::Connect
		case :	// AtmSession::Detach
		case :	// AtmSession::Disconnect
		
		case 102:	// AtmSession::ReleaseSession
		case 103:	// AtmSession::ReserveSession

		case 104:	// AtmSessionStatus::EnumItem
		case 105:	// AtmSessionStatus::GetValue
		case 106:	// AtmSessionStatusCollection::Add
		case 107:	// AtmSessionStatusCollection::IndexOf
		case 108:	// AtmSessionStatusCollection::Move
		case 109:	// AtmSessionStatusCollection::RefreshIfChanged
		case 110:	// AtmSessionStatusCollection::Remove
		case 111:	// AtmSessionStatusCollection::RemoveAll
		case 112:	// AtmShortCollection::Add
		case 113:	// AtmShortCollection::IndexOf
		case 114:	// AtmShortCollection::Move
		case 115:	// AtmShortCollection::Remove
		case 116:	// AtmShortCollection::RemoveAll
		case 117:	// AtmStringCollection::Add
		case 118:	// AtmStringCollection::IndexOf
		case 119:	// AtmStringCollection::Move
		case 120:	// AtmStringCollection::Remove
		case 121:	// AtmStringCollection::RemoveAll
		case 122:	// AtmStringWait::Reset
		case 123:	// AtmStringWait::Wait

		case :	// AtmTerminal::ViewSession

		case 128:	// AtmTrace::EventWanted
		case 129:	// AtmTrace::LockEvents
		case 130:	// AtmTrace::Trace
		case 131:	// AtmTrace::TraceParams
		case 132:	// AtmTrace::UnlockEvents
		case 133:	// AtmTraceArgument::GetArgumentText
		case 134:	// AtmTraceArgument::GetTypeText
		case 135:	// AtmTraceFilter::LockConfiguration
		case 136:	// AtmTraceFilter::Match
		case 137:	// AtmTraceFilter::SetDefault
		case 138:	// AtmTraceFilter::UnlockConfiguration
		case 139:	// AtmTraceLog::LogEvent
		case 140:	// AtmTraceLog::LogStart
		case 141:	// AtmTraceLog::LogStop
		case 142:	// AtmTraceLog::UnlogEvent
		case 143:	// AtmTraceLog::UnlogStart
		case 144:	// AtmTraceLog::UnlogStop
		case 145:	// AtmTraceServer::LockEvents
		case 146:	// AtmTraceServer::RegCategory
		case 147:	// AtmTraceServer::RegEventDef
		case 148:	// AtmTraceServer::Start
		case 149:	// AtmTraceServer::Stop
		case 150:	// AtmTraceServer::UnlockEvents
		case 151:	// AtmTraceServer::UnRegCategory
		case 152:	// AtmTraceServer::UnRegEventDef
		case 153:	// AtmVARIANTCollection::Add
		case 154:	// AtmVARIANTCollection::IndexOf
		case 155:	// AtmVARIANTCollection::Move
		case 156:	// AtmVARIANTCollection::Remove
		case 157:	// AtmVARIANTCollection::RemoveAll
		case 158:	// AtmWait::Reset
		case 159:	// AtmWait::Wait
		case 160:	// AtmXStatusWait::Reset
		case 161:	// AtmXStatusWait::Wait
		{
			m_groupNoParametersNeeded.ShowWindow( SW_SHOW  );
		}
		break;

		case 75:	// AtmScreen3270::FieldCount
		{
			csaLabels.Add("Field type");
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
	Function	:	CAPIGenDlg::LoadEAOAxArgumentArray()

	Purpose		:	Load the function arguments for EAO for ActiveX.

*****************************************************************************/
void CAPIGenDlg::LoadEAOAxArgumentArray( int* nFunctionPosition, BOOL bPromptForValues )
{

	CString	csFunctionName, csFunctionNum;
	*nFunctionPosition=0;

	*nFunctionPosition = m_listTranslateFunction.GetCurSel();
	m_listTranslateFunction.GetText( *nFunctionPosition, csFunctionName );

	// full function name text
	csaArguments.Add( csFunctionName );

	if ( bPromptForValues )
	{
		UpdateData();

		switch ( *nFunctionPosition )
		{
			
			case 0:		// AtmColor3270::GetColor
			case 1:		// AtmColor3270::SetColor
			case 2:		// AtmConnectionWait::Reset
			case 3:		// AtmConnectionWait::Wait
			case 4:		// AtmCursorWait::Reset
			case 5:		// AtmCursorWait::Wait
			case 6:		// AtmEdit3270::CanCopy
			case 7:		// AtmEdit3270::CanCut
			case 8:		// AtmEdit3270::CanPaste
			case 9:		// AtmEdit3270::Copy
			case 10:	// AtmEdit3270::CopyData
			case 11:	// AtmEdit3270::Cut
			case 12:	// AtmEdit3270::CutData
			case 13:	// AtmEdit3270::Delete
			case 14:	// AtmEdit3270::Paste
			case 15:	// AtmEdit3270::PasteContinue
			case 16:	// AtmEdit3270::PasteData
			case 17:	// AtmFileTransfer::Cancel
			case 18:	// AtmFileTransfer::GetStatus
			case 19:	// AtmFileTransfer::Transfer
			case 20:	// AtmFileTransfer::TransferEx
			case 21:	// AtmFileTransfer::TransferFiles
			case 22:	// AtmFileTransferWait::Reset
			case 23:	// AtmFileTransferWait::Wait
			case 24:	// AtmFont::GetRectangle
			case 25:	// AtmFont::GetSize
			case 26:	// AtmGraphics3270::GetCursor
			case 27:	// AtmGraphics3270::GetPictureList
			case 28:	// AtmGraphics3270::RefreshEvents
			case 29:	// AtmGraphics3270::SetCursor
			case 30:	// AtmHllapiCollection::Add
			case 31:	// AtmHllapiCollection::IndexOf
			case 32:	// AtmHllapiCollection::Move
			case 33:	// AtmHllapiCollection::Remove
			case 34:	// AtmHllapiCollection::RemoveAll
			case 35:	// AtmHllapiCollection::SetAsDefault
			case 36:	// AtmHostQuietWait::Reset
			case 37:	// AtmHostQuietWait::Wait
			case 38:	// AtmIUnknownCollection::Add
			case 39:	// AtmIUnknownCollection::IndexOf
			case 40:	// AtmIUnknownCollection::Move
			case 41:	// AtmIUnknownCollection::Remove
			case 42:	// AtmIUnknownCollection::RemoveAll
			case 43:	// AtmIUnknownCollection::SetAsDefault
			case 44:	// AtmKeyWait::Reset
			case 45:	// AtmKeyWait::Wait
			case 46:	// AtmLongCollection::Add
			case 47:	// AtmLongCollection::IndexOf
			case 48:	// AtmLongCollection::Move
			case 49:	// AtmLongCollection::Remove
			case 50:	// AtmLongCollection::RemoveAll
			case 51:	// AtmLongCollection::SetAsDefault
			case 52:	// AtmObjectCollection::Add
			case 53:	// AtmObjectCollection::IndexOf
			case 54:	// AtmObjectCollection::Move
			case 55:	// AtmObjectCollection::Remove
			case 56:	// AtmObjectCollection::RemoveAll
			case 57:	// AtmObjectCollection::SetAsDefault
			case 58:	// AtmOia3270::GetAttributeStatus
			case 59:	// AtmOia3270::GetOIALine
			case 60:	// AtmOia3270::WaitForXStatus
			case 61:	// AtmPrinter3270::AlignForm
			case 62:	// AtmPrinter3270::SendCommand
			case 63:	// AtmPrinterCtrl::AboutBox
			case 64:	// AtmPrinterCtrl::DoClick
			case 65:	// AtmPrinterCtrl::Refresh
			case 66:	// AtmPrinterCtrl::ViewSession
			case 67:	// AtmPrinterLUEscapeSequences::Add
			case 68:	// AtmPrinterLUEscapeSequences::Remove
			case 69:	// AtmPrinterLUEscapeSequences::RemoveAll
			case 70:	// AtmPrinterOia3270::GetAttributeStatus
			case 71:	// AtmPrinterOia3270::GetOIALine
			case 72:	// AtmPrinterOia3270::WaitForXStatus
			case 73:	// AtmPrinterRenderer::OnStatusChanged
			case 74:	// AtmPrintScreen::PrintScreen
			case 75:	// AtmScreen3270::FieldCount
			case 76:	// AtmScreen3270::FindField
			case 77:	// AtmScreen3270::FindString
			case 78:	// AtmScreen3270::FindStringEx
			case 79:	// AtmScreen3270::GetCursor
			case 80:	// AtmScreen3270::GetData
			case 81:	// AtmScreen3270::GetString
			case 82:	// AtmScreen3270::GetStringEx
			case 83:	// AtmScreen3270::PutString
			case 84:	// AtmScreen3270::PutStringEx
			case 85:	// AtmScreen3270::RefreshEvents
			case 86:	// AtmScreen3270::SendKeys
			case 87:	// AtmScreen3270::SendLightPen
			case 88:	// AtmScreen3270::SetCursor
			case 89:	// AtmScreen3270::WaitForCursor
			case 90:	// AtmScreen3270::WaitForKeys
			case 91:	// AtmScreen3270::WaitForString
			case 92:	// AtmScreen3270::WaitHostQuiet
			case 93:	// AtmSelection3270::GetSelection
			case 94:	// AtmSelection3270::IsSelected
			case 95:	// AtmSelection3270::SelectAll
			case 96:	// AtmSelection3270::SetSelection
			case 97:	// AtmSelection3270::Unselect
			case 98:	// AtmSession::Attach
			case 99:	// AtmSession::Connect
			case 100:	// AtmSession::Detach
			case 101:	// AtmSession::Disconnect
			case 102:	// AtmSession::ReleaseSession
			case 103:	// AtmSession::ReserveSession
			case 104:	// AtmSessionStatus::EnumItem
			case 105:	// AtmSessionStatus::GetValue
			case 106:	// AtmSessionStatusCollection::Add
			case 107:	// AtmSessionStatusCollection::IndexOf
			case 108:	// AtmSessionStatusCollection::Move
			case 109:	// AtmSessionStatusCollection::RefreshIfChanged
			case 110:	// AtmSessionStatusCollection::Remove
			case 111:	// AtmSessionStatusCollection::RemoveAll
			case 112:	// AtmShortCollection::Add
			case 113:	// AtmShortCollection::IndexOf
			case 114:	// AtmShortCollection::Move
			case 115:	// AtmShortCollection::Remove
			case 116:	// AtmShortCollection::RemoveAll
			case 117:	// AtmStringCollection::Add
			case 118:	// AtmStringCollection::IndexOf
			case 119:	// AtmStringCollection::Move
			case 120:	// AtmStringCollection::Remove
			case 121:	// AtmStringCollection::RemoveAll
			case 122:	// AtmStringWait::Reset
			case 123:	// AtmStringWait::Wait
			case 124:	// AtmTerminal::AboutBox
			case 125:	// AtmTerminal::DoClick
			case 126:	// AtmTerminal::Refresh
			case 127:	// AtmTerminal::ViewSession
			case 128:	// AtmTrace::EventWanted
			case 129:	// AtmTrace::LockEvents
			case 130:	// AtmTrace::Trace
			case 131:	// AtmTrace::TraceParams
			case 132:	// AtmTrace::UnlockEvents
			case 133:	// AtmTraceArgument::GetArgumentText
			case 134:	// AtmTraceArgument::GetTypeText
			case 135:	// AtmTraceFilter::LockConfiguration
			case 136:	// AtmTraceFilter::Match
			case 137:	// AtmTraceFilter::SetDefault
			case 138:	// AtmTraceFilter::UnlockConfiguration
			case 139:	// AtmTraceLog::LogEvent
			case 140:	// AtmTraceLog::LogStart
			case 141:	// AtmTraceLog::LogStop
			case 142:	// AtmTraceLog::UnlogEvent
			case 143:	// AtmTraceLog::UnlogStart
			case 144:	// AtmTraceLog::UnlogStop
			case 145:	// AtmTraceServer::LockEvents
			case 146:	// AtmTraceServer::RegCategory
			case 147:	// AtmTraceServer::RegEventDef
			case 148:	// AtmTraceServer::Start
			case 149:	// AtmTraceServer::Stop
			case 150:	// AtmTraceServer::UnlockEvents
			case 151:	// AtmTraceServer::UnRegCategory
			case 152:	// AtmTraceServer::UnRegEventDef
			case 153:	// AtmVARIANTCollection::Add
			case 154:	// AtmVARIANTCollection::IndexOf
			case 155:	// AtmVARIANTCollection::Move
			case 156:	// AtmVARIANTCollection::Remove
			case 157:	// AtmVARIANTCollection::RemoveAll
			case 158:	// AtmWait::Reset
			case 159:	// AtmWait::Wait
			case 160:	// AtmXStatusWait::Reset
			case 161:	// AtmXStatusWait::Wait
			{
			}
			break;

/*
			case 8:		// Screen::fieldCount
			{
				int nSelection = m_listFieldType.GetCurSel();

				if ( nSelection == 0 )
				{
					csaArguments.Add( "FIELDTYPE_PROTECTED" );
				}
				else if ( nSelection == 1 )
				{
					csaArguments.Add( "FIELDTYPE_UNPROTECTED" );
				}
				else
				{
					csaArguments.Add( "FIELDTYPE_ANY" );
				}
			}
			break;

			
			case 20:	// Screen::getString
			{
				// row
				csaArguments.Add( m_csEditRow );
				// column
				csaArguments.Add( m_csEditColumn );
				// length
				csaArguments.Add( m_csEditLength );
			}
			break;
			
			case 22:	// Screen::putString
			{
				// row
				csaArguments.Add( m_csEditRow );
				// column
				csaArguments.Add( m_csEditColumn );
				// put string
				csaArguments.Add( m_csEditPutString );
			}
			break;



			case 24:		// screen.sendkeys
			{
				// string parameter
				csaArguments.Add( m_csInputString );

				int nSelection = m_listMnemonicType.GetCurSel();

				if ( nSelection == 0 )
				{
					csaArguments.Add( "screen.KEYTYPE_BRACES" );							
				}
				else
				{
					csaArguments.Add( "screen.KEYTYPE_HLLAPI" );
				}

			}
			break;


			case 25:	// Screen::setCursor
			{
				// row
				csaArguments.Add( m_csEditRow );
				// column
				csaArguments.Add( m_csEditColumn );
			}
			break;

			case 27:	// Screen::setHostCharSet
			{
				// char set
				csaArguments.Add( m_csEditRow );
			}
			break;

			case 28:	// Screen::setHostCodePage
			{
				// code page
				csaArguments.Add( m_csEditRow );
			}
			break;

			case 29:	// Screen::setModel
			{
				int nSelection = m_listScreenModel.GetCurSel();

				if ( nSelection == 0 )
				{
					csaArguments.Add( "MODEL_2" );
				}
				else if ( nSelection == 1 )
				{
					csaArguments.Add( "MODEL_3" );
				}
				else if ( nSelection == 2 )
				{
					csaArguments.Add( "MODEL_4" );
				}
				else if ( nSelection == 3 )
				{
					csaArguments.Add( "MODEL_5" );
				}
				else
				{
					csaArguments.Add( "MODEL_AUTOSENSE" );
				}

			}
			break;

			case 30:	// Screen::waitForCursor
			{
				// row
				csaArguments.Add( m_csEditRow );
				// column
				csaArguments.Add( m_csEditColumn );
			}
			break;

			case 31:	// Screen::waitForKeys	XXX
			{
				// string parameter
				csaArguments.Add( m_csInputString );

				// type
				csaArguments.Add( "type" );
				// mode
				csaArguments.Add( "mode" );
			}
			break;


			case 32:	// Screen::waitForString	XXX
			{
				// string
				csaArguments.Add( "string" );
				// row
				csaArguments.Add( "row" );
				// column
				csaArguments.Add( "column" );
				// wait
				csaArguments.Add( "wait" );
			}
			break;


			case 33:	// Screen::waitHostQuiet
			{
				csaArguments.Add( m_csEditRow );
			}
			break;

			case 50:	// ITelnetProxy::setSocksAddress
			case 52:	// ITelnetProxy::setTelnetAddress
			{
				csaArguments.Add( m_csInputString );
			}
			break;

			case 51:	// ITelnetProxy::setSocksPort
			case 53:	// ITelnetProxy::setTelnetPort
			{
				csaArguments.Add( m_csEditRow );
			}
			break;



		}
	}
	else
	{
		switch ( *nFunctionPosition )
		{
			
			case 0:		// AtmObject::getName
			case 1:		// AtmObject::getParentObject
			case 2:		// OIA::getErrorStatus
			case 3:		// OIA::getOiaType
			case 4:		// OIA::getText
			case 5:		// OIA::getXStatus
			case 6:		// OIA::waitForXStatus
			case 7:		// Screen::clearScreen
			case 9:		// Screen::getColumns
			case 10:	// Screen::getCursorColumn
			case 11:	// Screen::getCursorRow
			case 12:	// Screen::getEabEnabled
			case 13:	// Screen::getHostCharSet
			case 14:	// Screen::getHostCodePage 
			case 15:	// Screen::getKeyboardLocked
			case 16:	// Screen::getModel
			case 17:	// Screen::getOia
			case 18:	// Screen::getRows
			case 19:	// Screen::getScreenType
			case 21:	// Screen::getText
			case 23:	// Screen::Screen::refreshEvents
			case 26:	// Screen::setEabEnabled
			case 34:	// Session::attach
			case 35:	// session.connect
			case 36:	// Session::detach
			case 37:	// Session::disconnect
			case 38:	// Session::getAttached
			case 39:	// Session::getConnected
			case 40:	// Session::getConnection
			case 41:	// Session::getScreen
			case 42:	// Session::getState
			case 43:	// Session::setConnected
			case 44:	// Session::setConnection
			case 45:	// Session::setScreen
			case 46:	// ITelnetProxy::getSocksAddress
			case 47:	// ITelnetProxy::getSocksPort
			case 48:	// ITelnetProxy::getTelnetAddress
			case 49:	// ITelnetProxy::getTelnetPort
			case 54:	// Debug
			{
			}
			break;


			case 8:		// Screen::fieldCount
			{
				csaArguments.Add( "FIELDTYPE_PROTECTED" );
			}
			break;


			
			case 20:	// Screen::getString
			{
				// row
				csaArguments.Add( "20" );
				// column
				csaArguments.Add( "8" );
				// length
				csaArguments.Add( "10" );
			}
			break;

			
			case 22:	// Screen::putString
			{
				// row
				csaArguments.Add( "20" );
				// column
				csaArguments.Add( "17" );
				// put string
				csaArguments.Add( "userID" );
			}
			break;


			case 24:		// screen.sendkeys
			{
				// string parameter
				csaArguments.Add( "sample string" );
				csaArguments.Add( "KEYTYPE_BRACES" );							
			}
			break;


			case 25:	// Screen::setCursor
			{
				// row
				csaArguments.Add( "1" );
				// column
				csaArguments.Add( "2" );
			}
			break;

			case 27:	// Screen::setHostCharSet
			{
				// char set
				csaArguments.Add( "1259" );
			}
			break;

			case 28:	// Screen::setHostCodePage
			{
				// code page
				csaArguments.Add( "437" );
			}
			break;

			case 29:	// Screen::setModel
			{
				csaArguments.Add( "MODEL_3" );
			}
			break;


			case 30:	// Screen::waitForCursor
			{
				// row
				csaArguments.Add( "20" );
				// column
				csaArguments.Add( "10" );
			}
			break;

			case 31:	// Screen::waitForKeys	XXX
			{
				// string
				csaArguments.Add( "@E" );
				// type
				csaArguments.Add( "ATM_KEYTYPE_HLLAPI" );
				// mode
				csaArguments.Add( "WAITFORKEYS_AID" );
			}
			break;


			case 32:	// Screen::waitForString	XXX
			{
				// string
				csaArguments.Add( "Ready:" );
				// row
				csaArguments.Add( "1" );
				// column
				csaArguments.Add( "2" );
				// wait
				csaArguments.Add( "8000" );
			}
			break;


			case 33:	// Screen::waitHostQuiet
			{
				csaArguments.Add( "3000" );
			}
			break;


			case 50:	// ITelnetProxy::setSocksAddress
			case 52:	// ITelnetProxy::setTelnetAddress
			{
				csaArguments.Add( "207.46.250.119" );
			}
			break;

			case 51:	// ITelnetProxy::setSocksPort
			case 53:	// ITelnetProxy::setTelnetPort
			{
				csaArguments.Add( "80" );
			}
			break;

*/
		}

	}
	
}
