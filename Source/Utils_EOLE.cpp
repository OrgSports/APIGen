#include "stdafx.h"
#include "APIGen.h"
#include "APIGenDlg.h"

/****************************************************************************DC
	Function	:	CAPIGenDlg::ShowEOLEControls()

	Purpose		:	Show the controls for the Extra! OLE Automation 
					function parameters.

*****************************************************************************/
void CAPIGenDlg::ShowEOLEControls( int nFunction )
{
	HideParameterControls();
	csaLabels.RemoveAll();
	BOOL bYouShouldGo=TRUE;

	switch ( nFunction )
	{
		case 0:		// Screen.OIA.ConnectionStatus
		case 1:		// Screen.OIA.ErrorStatus
		case 2:		// Screen->OIA.Updated
		case 4:		// Screen.OIA.XStatus
		case 5:		// Screen::Col
		case 6:		// Screen::Copy
		case 11:	// Screen::Row
		case 13:	// Screen.SelectAll
		case 15:	// Screen.Updated
		case 22:	// Session::Activate
		case 23:	// Session::ClearComm
		case 24:	// Session::ClearHistory
		case 25:	// Session::Close
		case 27:	// Session::ClosePrintJob
		case 28:	// Session::Connected
		case 29:	// Session::EnlargeFont
		case 31:	// Session::FileTransferOptions
		case 36:	// Session::HostName
		case 43:	// Session::Name
		case 44:	// Session::PrintDisplay
		case 47:	// Session::ReduceFont
		case 48:	// Session::Reset
		case 49:	// Session::Save
		case 51:	// Session::Saved
		case 54:	// Session::TransferFile
		case 61:	// Session::WindowHandle
		case 64:	// Sessions::Count
		case 65:	// Sessions::CloseAll
		case 66:	// System::ActiveSession
		case 67:	// System::Name
		case 68:	// System::Quit
		case 69:	// System::Time
		case 71:	// System::Version
		{
		}
		break;

		case 3:		// Screen.OIA.Value
		{
			csaLabels.RemoveAll();
			csaLabels.Add("Set the value (vs get)");
			bYouShouldGo=FALSE;
		}
		break;


		case 7:		// Screen::FieldAttribute
		case 9:		// Screen.MoveTo
		{
				csaLabels.Add("Row");
				csaLabels.Add("Column");
		}
		break;


		case 16:	// Screen::WaitForCursor
		{
				csaLabels.Add("Row");
				csaLabels.Add("[Column]");
				csaLabels.Add("[End row]");
				csaLabels.Add("[End column]");
				csaLabels.Add("[Page (VT only)]");
		}
		break;

		case 8:		// Screen::GetString
		{
			csaLabels.Add("Row");
			csaLabels.Add("Column");
			csaLabels.Add("Length");
			csaLabels.Add("[Page (VT only)]");
		}
		break;


		case 10:	// Screen::PutString
		case 12:	// Screen::Search
		{
			csaLabels.Add("String");
			csaLabels.Add("[Row]");
			csaLabels.Add("[Column]");
			csaLabels.Add("[Page (VT only)]");
		}
		break;

		case 14:	// Screen::SendKeys
		case 53:	// Session::Title
		case 56:	// Session::UpdateStatusBar
		{
			csaLabels.Add("String");
		}
		break;

		case 17:	// Screen::WaitForCursorMove
		{
			csaLabels.Add("Rows");
			csaLabels.Add("Columns");
			csaLabels.Add("[Page (VT only)]");
		}
		break;

		case 18:	// Screen::WaitForKeys
		{
			csaLabels.RemoveAll();
			csaLabels.Add("Timeout");
			csaLabels.Add("Keys");
			csaLabels.Add("Process");	//todo: add this to the leaf
			bYouShouldGo=FALSE;
		}
		break;

		case 19:	// Screen.WaitForStream
		{
			csaLabels.RemoveAll();
			csaLabels.Add("String");
			csaLabels.Add("[Idle time]");
			csaLabels.Add("[Timeout]");
			csaLabels.Add("[Options]");
			bYouShouldGo=FALSE;
		}
		break;

		case 20:	// Screen::WaitForString
		{
			csaLabels.RemoveAll();
			csaLabels.Add("Text");
			csaLabels.Add("[Row]");
			csaLabels.Add("[Column]");
			csaLabels.Add("[Page]");
			csaLabels.Add("[Timeout]");
			csaLabels.Add("[Options]");
			csaLabels.Add("[Type]");
			csaLabels.Add("[End row]");
			csaLabels.Add("[End column]");
			bYouShouldGo=FALSE;
		}
		break;


		case 21:	// Screen::WaitHostQuiet
		{
			csaLabels.Add("Host settle time");
		}
		break;

		case 26:	// Session::CloseEx
		{
			csaLabels.Add("Close option");
			bYouShouldGo=FALSE;
		}
		break;

		case 30:	// Session::FileTransferHostOS
		{
			csaLabels.Add("Set FT host type (vs get)");
			csaLabels.Add("File transfer host type");
			bYouShouldGo=FALSE;
		}
		break;

		case 32:	// Session::FileTransferScheme
		{
			csaLabels.Add("File transfer scheme");
			csaLabels.Add("Set scheme (vs get)");
			bYouShouldGo=FALSE;
		}
		break;

		case 33:	// Session::Font
		{
			csaLabels.Add("Set font size (vs get)");
			csaLabels.Add("New font size (pixels)");
			bYouShouldGo=FALSE;
		}
		break;

		case 34:	// Session::Height
		{
			csaLabels.Add("Set session height (vs get)");
			csaLabels.Add("New session height(pixels)");
			bYouShouldGo=FALSE;
		}
		break;


		case 35:	// Session::HoldScreen
		{
			csaLabels.Add("Set screen hold (vs get)");
			csaLabels.Add("Hold screen (vs release)");
			bYouShouldGo=FALSE;
		}
		break;

		case 37:	// Session::InvokeSettingsDialog
		{
			csaLabels.Add("Settings page");
			csaLabels.Add("[Settings tab]");
			bYouShouldGo=FALSE;
		}
		break;

		case 38:	// Session::KeyboardLocked
		{
			csaLabels.Add("Get state (vs set)");
			csaLabels.Add("Lock keyboard (vs unlock)");
			bYouShouldGo=FALSE;
		}
		break;

		case 39:	// Session::KeyMap
		{
			csaLabels.Add("Set keymap (or get)");
			csaLabels.Add("Keyboard map");
			bYouShouldGo=FALSE;
		}
		break;

		case 40:	// Session::Language
		{
			csaLabels.Add("Set (vs get)");
			csaLabels.Add("Language");
			bYouShouldGo=FALSE;
		}
		break;

		case 41:	// Session::Local
		{
			csaLabels.Add("Set Local Mode (vs get)");
			csaLabels.Add("Set Local Mode on (vs off)");
			bYouShouldGo=FALSE;
		}
		break;


		case 42:	// Session::Menu
		{
			csaLabels.Add("Set menu visible (vs get)");
			csaLabels.Add("Set menu visible (vs off)");
			bYouShouldGo=FALSE;
		}
		break;

	
		case 45:	// Session::Quiet
		{
			csaLabels.Add("Set session quiet (vs get)");
			csaLabels.Add("Set session quiet (vs not)");
			bYouShouldGo=FALSE;
		}
		break;

		case 46:	// Session::ReceiveFile
		case 52:	// Session::SendFile
		{
			m_groupAddParameterGroup.ShowWindow( SW_SHOW  );

			csaLabels.RemoveAll();
			csaLabels.Add("PC Filename");
			csaLabels.Add("Host Filename");
			csaLabels.Add("Show progress dialog");
			bYouShouldGo=FALSE;
		}
		break;


		case 50:	// Session::SaveAs
		{
			csaLabels.RemoveAll();
			csaLabels.Add("PC Filename");
			bYouShouldGo=FALSE;
		}
		break;


		case 55:	// Session::Type
		{
			csaLabels.RemoveAll();
			csaLabels.Add("Set property (vs get)");
			csaLabels.Add("Type property");
			bYouShouldGo=FALSE;
		}
		break;
	

		case 57:	// Session::Visible
		{
			csaLabels.Add("Set visible (vs get state)");
			csaLabels.Add("Set visible (vs hide)");
			bYouShouldGo=FALSE;
		}
		break;

		
		case 58:	// Session::WaitForDisconnect
		{
			csaLabels.Add("Timeout (ms)");
		}
		break;


		case 59:	// Session::WaitForTimer
		{
			csaLabels.Add("Timeout value (ms)");
			csaLabels.Add("Continuous signal?");
			bYouShouldGo=FALSE;
		}
		break;


		case 60:	// Session::Width
		{
			csaLabels.Add("Set width?");
			csaLabels.Add("Width value");
			bYouShouldGo=FALSE;
		}
		break;

		case 62:	// Session::WindowState
		{
			csaLabels.Add("Set state (vs get)");
			csaLabels.Add("Window state");
			bYouShouldGo=FALSE;
		}
		break;

		
		case 63:	// Sessions::Open
		{
			m_groupAddParameterGroup.ShowWindow( SW_SHOW  );

			csaLabels.RemoveAll();
			csaLabels.Add("Session filename");
			bYouShouldGo=FALSE;
		}
		break;

		case 70:	// System::TimeoutValue
		{
			csaLabels.Add("Set timeout (vs get)");
			csaLabels.Add("Timeout (ms)");
			bYouShouldGo=FALSE;
		}
		break;

	}



	if ( bYouShouldGo )
	{
		ShowEditControls( &csaLabels );
	}
	else
	{
		ShowMixedControls( EOLE_API, nFunction, &csaLabels );	
	}

}



/****************************************************************************DC
	Function	:	CAPIGenDlg::LoadEOLEArgumentArray()

	Purpose		:	Load the function arguments for OLE Automation.

*****************************************************************************/
void CAPIGenDlg::LoadEOLEArgumentArray( int* nFunctionPosition, BOOL bPromptForValues )
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
			
			case 0:		// OIA.ConnectionStatus
			case 1:		// OIA.ErrorStatus
			case 2:		// OIA.Updated
			case 4:		// OIA.XStatus
			case 5:		// Screen::Col
			case 6:		// Screen::Copy
			case 11:	// Screen::Row						
			case 13:	// Screen::SelectAll
			case 15:	// Screen::Updated
			case 22:	// Session::Activate
			case 23:	// Session::ClearComm
			case 24:	// Session::ClearHistory
			case 25:	// Session::Close
			case 27:	// Session::ClosePrintJob
			case 28:	// Session::Connected
			case 29:	// Session::EnlargeFont		
			case 31:	// Session::FileTransferOptions		
			case 43:	// Session::Name
			case 44:	// Session::PrintDisplay
			case 47:	// Session::ReduceFont
			case 48:	// Session::Reset
			case 49:	// Session::Save
			case 51:	// Session::Saved
			case 54:	// Session::TransferFile
			case 61:	// Session::WindowHandle
			case 64:	// Sessions::Count
			case 65:	// Sessions::CloseAll
			case 66:	// System::ActiveSession
			case 67:	// System::Name
			case 68:	// System::Quit
			case 69:	// System::Time
			case 71:	// System::Version
			{
			}
			break;

			case 3:		// Screen.OIA.Value
			{
				Read1C( &csaArguments );
			}
			break;

			case 18:	// Screen::WaitForKeys
			case 46:	// Session::ReceiveFile
			case 52:	// Session::SendFile
			{
				Read2E1C( &csaArguments );	//todo: fix the addargumentarray to use the right checkbox
			}
			break;

			case 32:	// Session::FileTransferScheme
			case 59:	// Session::WaitForTimer
			{
				Read1E1C( &csaArguments );
			}
			break;

			case 37:	// Session::InvokeSettingsDialog
			{
				Read2L( &csaArguments );
			}
			break;


			case 33:	// Session::Font
			case 34:	// Session::Height
			case 39:	// Session::KeyMap
			case 60:	// Session::Width
			case 70:	// System::TimeoutValue
			{
				Read1C1E( &csaArguments );
			}
			break;

			case 42:	// Session::Menu
			case 45:	// Session::Quiet
			case 57:	// Session::Visible
			{
				Read2C( &csaArguments );
			}
			break;

			case 35:	// Session::HoldScreen
			case 38:	// Session::KeyboardLocked
			case 41:	// Session::Local
			{
				Read2C( &csaArguments );
			}
			break;

			case 50:	// Session::SaveAs
			case 63:	// Sessions::Open
			case 58:	// Session::WaitForDisconnect
			{
				Read1E( &csaArguments );
			}
			break;

			case 40:	// Session::Language
			case 55:	// Session::Type
			case 62:	// Session::WindowState
			{
				Read1C1L( &csaArguments );
			}
			break;


			case 7:		// Screen::FieldAttribute
			case 9:		// Screen::MoveTo
			case 16:	// Screen::WaitForCursor		//todo: this doesn't look like the right layout
			case 17:	// Screen::WaitForCursorMove
			{
				// row
				csaArguments.Add( m_csEditArgument1 );
				// column
				csaArguments.Add( m_csEditArgument3 );
				// end row
				csaArguments.Add( m_csEditArgument4 );
				// end column
				csaArguments.Add( m_csEditArgument5 );
				// page
				csaArguments.Add( m_csEditArgument6 );

			}
			break;

			case 8:
			{
				// row
				csaArguments.Add( m_csEditArgument1 );
				// column
				csaArguments.Add( m_csEditArgument3 );
				// length
				csaArguments.Add( m_csEditArgument4 );
			}
			break;

			case 10:	// Screen::PutString
			case 12:	// Screen::Search
			{
				Read3E( &csaArguments );
			}
			break;

			case 14:	// Screen::SendKeys
			case 53:	// Session::Title
			case 56:	// Session::UpdateStatusBar
			{
				// put string
				csaArguments.Add( m_csEditArgument1 );
			}
			break;


			case 19:	// Screen::WaitForStream			
			{
				Read3E1ML( &csaArguments );
			}
			break;

			case 20:	// Screen::WaitForString			
			{				
				Read5E1ML1L2E( &csaArguments );
			}
			break;


			case 21:	// Screen::WaitHostQuiet
			{
				// settle time
				csaArguments.Add( m_csEditArgument1 );
			}
			break;

			case 26:	// Session::CloseEx
			{
				// close option
				Read1ML( &csaArguments );
			}
			break;

			case 30:	// Session::FileTransferHostOS
			{
				Read1C1L( &csaArguments );
			}
			break;


			case 36:	// Session::HostName
			{
				// hold host name
				csaArguments.Add( "                                " );
			}
			break;


		}
	}
	else
	{
		switch ( *nFunctionPosition )
		{
			case 0:		// OIA.ConnectionStatus
			case 1:		// OIA.ErrorStatus
			case 2:		// OIA.Updated
			case 3:		// OIA.Value
			case 4:		// OIA.XStatus
			case 5:		// Screen::Col
			case 6:		// Screen::Copy
			case 11:	// Screen::Row						// not supported
			case 13:	// Screen::SelectAll
			case 15:	// Screen::Updated
			case 22:	// Session::Activate
			case 23:	// Session::ClearComm
			case 24:	// Session::ClearHistory
			case 25:	// Session::Close
			case 27:	// Session::ClosePrintJob
			case 28:	// Session::Connected
			case 29:	// Session::EnlargeFont			
			case 31:	// Session::FileTransferOptions
			case 43:	// Session::Name
			case 44:	// Session::PrintDisplay
			case 47:	// Session::ReduceFont
			case 48:	// Session::Reset
			case 49:	// Session::Save
			case 51:	// Session::Saved
			case 54:	// Session::TransferFile
			case 55:	// Session::Type
			case 61:	// Session::WindowHandle
			case 64:	// Sessions::Count
			case 65:	// Sessions::CloseAll
			case 66:	// System::ActiveSession
			case 67:	// System::Name
			case 68:	// System::Quit
			case 69:	// System::Time
			case 71:	// System::Version
			{
			}
			break;
				
			case 7:		// Screen::FieldAttribute
			case 9:		// Screen::MoveTo
			case 16:	// Screen::WaitForCursor
			case 17:	// Screen::WaitForCursorMove
			{
				// row
				csaArguments.Add( "4" );
				// column
				csaArguments.Add( "45" );
				// end row
				csaArguments.Add( "7" );
				// end column
				csaArguments.Add( "49" );
				// page
				csaArguments.Add( "1" );

			}
			break;

			case 8:
			{
				// row
				csaArguments.Add( "4" );
				// column
				csaArguments.Add( "45" );
				// length
				csaArguments.Add( "8" );
			}
			break;

			case 10:	// Screen::PutString
			case 12:	// Screen::Search
			{
				// row
				csaArguments.Add( "4" );
				// column
				csaArguments.Add( "45" );
				// put string
				csaArguments.Add( "string put" );
			}
			break;


			case 14:	// Screen::SendKeys
			{
				// put string
				csaArguments.Add( "user1<Enter>" );
			}
			break;

			case 18:	// Screen::WaitForKeys
			{
				// timeout
				csaArguments.Add( "3000" );
				// user keys
				csaArguments.Add( "xxx" );
				
				// continue processing
				csaArguments.Add( "TRUE" );

			}
			break;

			case 19:	// Screen::WaitForStream			
			{
				csaArguments.Add("I want to be more like Ned.");
				csaArguments.Add("250");
				csaArguments.Add("5000");
				csaArguments.Add("xNoCase");
			}
			break;

			case 20:	// Screen::WaitForString			
			{				
				csaArguments.Add( "Ned is a great guy." );
				csaArguments.Add( "1" );
				csaArguments.Add( "2" );
				csaArguments.Add( "1" );
				csaArguments.Add( "0" );
				csaArguments.Add( "5000" );
				csaArguments.Add( "xNoCase" );
				csaArguments.Add( "2" );
				csaArguments.Add( "24" );
				csaArguments.Add( "80" );
			}
			break;


			case 21:	// Screen::WaitHostQuiet
			{
				// settle time
				csaArguments.Add( "3100" );
			}
			break;

			case 26:	// Session::CloseEx
			{
				// close option
				csaArguments.Add( "4" );
			}
			break;

			case 30:    //Session::FileTransferHostOS
			{
				csaArguments.Add("TRUE");
				csaArguments.Add("CMS");
			}
			break;

			case 32:	// Session::FileTransferScheme
			{
				csaArguments.Add( "TRUE" );
				csaArguments.Add( "Text Default.eis" );
			}
			break;

			case 33:	// Session::Font
			{
				// hold font name
				csaArguments.Add( "                                " );
			}
			break;

			case 34:	// Session::Height
			{
				csaArguments.Add( "TRUE" );
				csaArguments.Add( "620" );
			}
			break;

			case 36:	// Session::HostName
			{
				// hold host name
				csaArguments.Add( "                                " );
			}
			break;

			case 37:	// Session::InvokeSettingsDialog
			{
				csaArguments.Add( "xConnectionPage" );
				csaArguments.Add( "xGeneralTab" );
			}
			break;

			case 38:	// Session::KeyboardLocked
			{
				csaArguments.Add( "TRUE" );
				csaArguments.Add( "FALSE" );
			}
			break;

			case 39:	// Session::KeyMap
			{
				csaArguments.Add( "TRUE" );
				csaArguments.Add( "SCO-ANSI (101 key).ekm" );
			}
			break;


			case 40:	// Session::Language
			{
				csaArguments.Add( "TRUE" );
				csaArguments.Add( "Martian" );
			}
			break;

			case 35:	// Session::HoldScreen
			{
				csaArguments.Add( "FALSE" );
			}
			break;

			case 41:	// Session::Local
			{
				csaArguments.Add( "FALSE" );
				csaArguments.Add( "FALSE" );
			}
			break;

			case 42:	// Session::Menu
			{
				csaArguments.Add( "TRUE" );
				csaArguments.Add( "FALSE" );
			}
			break;

			case 45:	// Session::Quiet
			{
				csaArguments.Add( "TRUE" );
				csaArguments.Add( "FALSE" );
			}
			break;

			case 46:	// Session::ReceiveFile
			case 52:	// Session::SendFile
			{
				csaArguments.Add( "testfile.txt" );
				csaArguments.Add( "testfile txt");					

				if ( m_bCheckShowFTPRogress )
				{
					csaArguments.Add( "TRUE" );					
				}
				else
				{
					csaArguments.Add( "FALSE" );
				}

			}
			break;
			
			case 50:	// Session::SaveAs
			{
				csaArguments.Add( "testfile2.txt" );
			}
			break;

			case 53:	// Session::Title
			{
				// put string
				csaArguments.Add( "New Title" );
			}
			break;

			case 56:	// Session::UpdateStatusBar
			{
				csaArguments.Add( "New status" );
			}
			break;


			case 57:	// Session::Visible
			{
				csaArguments.Add( "TRUE" );					
				csaArguments.Add( "TRUE" );					
			}
			break;


			case 58:	// Session::WaitForDisconnect
			{
				// timeout
				csaArguments.Add( "3001" );
			}
			break;

			case 59:	// Session::WaitForTimer
			{
				// timeout
				csaArguments.Add( "3002" );

				csaArguments.Add( "TRUE" );					

			}
			break;

			case 60:	// Session::Width
			{
				csaArguments.Add( "TRUE" );

				// width
				csaArguments.Add( "432" );
			}
			break;

			case 62:	// Session::WindowState
			{
				csaArguments.Add( "TRUE" );
				csaArguments.Add( "xMAXIMIZED" );
			}
			break;

			case 63:	// Sessions::Open
			{
				csaArguments.Add( "c:\\program files\\attachmate\\extra!\\sessions\\auburn2.edp\"" );
			}
			break;

			case 70:	// System::TimeoutValue
			{
				csaArguments.Add( "TRUE" );					
				// timeout value
				csaArguments.Add( "2999" );
			}
			break;

		}
	}

}



