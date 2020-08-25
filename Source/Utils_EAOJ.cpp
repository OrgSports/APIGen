#include "stdafx.h"
#include "APIGen.h"
#include "APIGenDlg.h"

/****************************************************************************DC
	Function	:	CAPIGenDlg::LoadEAOJArgumentArray()

	Purpose		:	Load the function arguments for EAO for Java.

*****************************************************************************/
void CAPIGenDlg::LoadEAOJArgumentArray( int* nFunctionPosition, BOOL bPromptForValues )
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
			
			case 0:		// AtmObject::getName
			case 1:		// AtmObject::getParentObject
			case 2:		// OIA::getErrorStatus
			case 3:		// OIA::getOiaType
			case 4:		// OIA::getText
			case 5:		// OIA::getXStatus
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
			case 23:	// Screen::refreshEvents
			case 34:	// Session::attach
			case 35:	// session.connect
			case 37:	// Session::disconnect
			case 38:	// Session::getAttached
			case 39:	// Session::getConnected
			case 40:	// Session::getConnection
			case 41:	// Session::getScreen
			case 42:	// Session::getState
			case 46:	// ITelnetProxy::getSocksAddress
			case 47:	// ITelnetProxy::getSocksPort
			case 48:	// ITelnetProxy::getTelnetAddress
			case 49:	// ITelnetProxy::getTelnetPort
			case 54:	// Debug
			{
			}
			break;


			case 6:		// OIA::waitForXStatus	
			{
				Read2L( &csaArguments );
			}
			break;

			case 8:		// Screen::fieldCount
			{
				Read1L( &csaArguments );
			}
			break;

			case 24:	// Screen::sendKeys
			{
				Read1E1L( &csaArguments );
			}
			break;

			case 26:	// Screen::setEabEnabled
			case 43:	// Session::setConnected
			{
				Read1C( &csaArguments );
			}
			break;

			case 29:	// Screen::setModel
			{
				Read1L( &csaArguments );
			}
			break;

			case 31:	// Screen::waitForKeys
			{
				Read1E2L( &csaArguments );
			}
			break;




			
			case 20:	// Screen::getString
			{
				// row
				csaArguments.Add( m_csEditArgument1 );
				// column
				csaArguments.Add( m_csEditArgument3 );
				// length
				csaArguments.Add( m_csEditArgument4 );
			}
			break;
			
			case 22:	// Screen::putString
			{
				// string
				csaArguments.Add( m_csEditArgument1 );
				// row
				csaArguments.Add( m_csEditArgument3 );
				// column
				csaArguments.Add( m_csEditArgument4 );
			}
			break;


			case 25:	// Screen::setCursor
			{
				// row
				csaArguments.Add( m_csEditArgument1 );
				// column
				csaArguments.Add( m_csEditArgument3 );
			}
			break;

			case 27:	// Screen::setHostCharSet
			{
				// char set
				csaArguments.Add( m_csEditArgument1 );
			}
			break;

			case 28:	// Screen::setHostCodePage
			{
				// code page
				csaArguments.Add( m_csEditArgument1 );
			}
			break;

			case 30:	// Screen::waitForCursor
			{
				// row
				csaArguments.Add( m_csEditArgument1 );
				// column
				csaArguments.Add( m_csEditArgument3 );
			}
			break;


			case 32:	// Screen::waitForString
			{
				// string
				csaArguments.Add( m_csEditArgument1 );
				// row
				csaArguments.Add( m_csEditArgument3 );
				// column
				csaArguments.Add( m_csEditArgument4 );
				// wait
				csaArguments.Add( m_csEditArgument5 );
			}
			break;


			case 33:	// Screen::waitHostQuiet
			{
				csaArguments.Add( m_csEditArgument1 );
			}
			break;



			case 50:	// ITelnetProxy::setSocksAddress
			case 52:	// ITelnetProxy::setTelnetAddress
			{
				csaArguments.Add( m_csEditArgument1 );
			}
			break;

			case 51:	// ITelnetProxy::setSocksPort
			case 53:	// ITelnetProxy::setTelnetPort
			{
				csaArguments.Add( m_csEditArgument1 );
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
			case 23:	// Screen::refreshEvents

			case 34:	// Session::attach
			case 35:	// session.connect
			case 36:	// Session::detach
			case 37:	// Session::disconnect
			case 38:	// Session::getAttached
			case 39:	// Session::getConnected
			case 40:	// Session::getConnection
			case 41:	// Session::getScreen
			case 42:	// Session::getState

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

			case 6:		// OIA::waitForXStatus
			{
				// get the wait condition from the list box
				csaArguments.Add( "XSW_PRESENT" );
				// get the one x-status from the list box
				csaArguments.Add( "XS_PRTBUSY" );
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

			case 26:	// Screen::setEabEnabled
			{
				// set EAB's
				csaArguments.Add( "TRUE" );
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

			case 31:	// Screen::waitForKeys
			{
				// string
				csaArguments.Add( "@E" );
				// type
				csaArguments.Add( "ATM_KEYTYPE_HLLAPI" );
				// mode
				csaArguments.Add( "WAITFORKEYS_AID" );
			}
			break;


			case 32:	// Screen::waitForString
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

			case 43:	// Session::setConnected
			{
				csaArguments.Add( "TRUE" );
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


		}

	}
}
			


/****************************************************************************DC
	Function	:	CAPIGenDlg::ShowEAOJControls()

	Purpose		:	Show the controls for the EAO Java function parameters.

*****************************************************************************/
void CAPIGenDlg::ShowEAOJControls( int nFunction )
{
	HideParameterControls();
	csaLabels.RemoveAll();
	BOOL bYouShouldGo=TRUE;

	switch ( nFunction )
	{
		case 0:		// AtmObject::getName
		case 1:		// AtmObject::getParentObject
		case 2:		// OIA::getErrorStatus
		case 3:		// OIA::getOiaType
		case 4:		// OIA::getText
		case 5:		// OIA::getXStatus
		
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

		case 35:	// session.connect
		case 37:	// Session::disconnect
		case 38:	// Session::getAttached
		case 39:	// Session::getConnected
		case 40:	// Session::getConnection
		case 41:	// Session::getScreen
		case 42:	// Session::getState
		case 46:	// ITelnetProxy::getSocksAddress
		case 47:	// ITelnetProxy::getSocksPort
		case 48:	// ITelnetProxy::getTelnetAddress
		case 49:	// ITelnetProxy::getTelnetPort
		{
		}
		break;

		case 6:		// OIA::waitForXStatus
		{
			m_groupAddParameterGroup.ShowWindow( SW_SHOW  );

			csaLabels.RemoveAll();
			csaLabels.Add("Wait condition");
			csaLabels.Add("X-status");
			bYouShouldGo=FALSE;
		}
		break;


		case 8:		// Screen::fieldCount
		{
			m_groupAddParameterGroup.ShowWindow( SW_SHOW  );

			csaLabels.RemoveAll();
			csaLabels.Add("Field type");
			bYouShouldGo=FALSE;
		}
		break;

		case 20:	// Screen::getString
		{
			csaLabels.Add("Row");
			csaLabels.Add("Column");
			csaLabels.Add("Length");
		}
		break;


		case 22:	// Screen::putString
		{
			csaLabels.Add("String");
			csaLabels.Add("Row");
			csaLabels.Add("Column");
		}
		break;

		case 24:	// Screen::sendKeys
		{
			m_groupAddParameterGroup.ShowWindow( SW_SHOW  );			

			csaLabels.RemoveAll();
			csaLabels.Add("Send string");
			csaLabels.Add("Mnemonic type");
			bYouShouldGo=FALSE;
		}
		break;


		case 25:	// Screen::setCursor
		{
			csaLabels.Add("Row");
			csaLabels.Add("Column");
		}
		break;

		case 26:	// Screen::setEabEnabled	3270ONLY
		{
			csaLabels.Add("Enable EAB's");
			m_groupAddParameterGroup.ShowWindow( SW_SHOW  );
			bYouShouldGo=FALSE;
		}
		break;

		case 27:	// Screen::setHostCharSet
		{
			csaLabels.Add("Host character set");
		}
		break;

		case 28:	// Screen::setHostCodePage
		{
			csaLabels.Add("Host code page");
		}
		break;

		case 29:	// Screen::setModel
		{
			m_groupAddParameterGroup.ShowWindow( SW_SHOW  );			

			csaLabels.RemoveAll();
			csaLabels.Add("Model type");
			bYouShouldGo=FALSE;
		}
		break;

		case 30:	// Screen::waitForCursor
		{
			csaLabels.Add("Row");
			csaLabels.Add("Column");
		}
		break;

		case 31:	// Screen::waitForKeys
		{
			csaLabels.Add("Keys");
			csaLabels.Add("Type");
			csaLabels.Add("Mode");
			bYouShouldGo=FALSE;
		}
		break;

		case 32:	// Screen::waitForString
		{
			csaLabels.Add("Text");
			csaLabels.Add("Row");
			csaLabels.Add("Column");
			csaLabels.Add("Wait duration (ms)");
		}
		break;
			
		case 33:		// screen.waithostquiet
		{
			csaLabels.Add("Settle time");
		}
		break;

		case 34:	// Session::attach	XXX -- needs a list control
		{
			csaLabels.Add("Attach mode");
		}
		break;

		case 36:	// Session::detach
		{
			csaLabels.Add("Flags (reserved)");
		}
		break;

		case 43:	// Session::setConnected
		{
			csaLabels.Add("Asynchronous connect");
		}
		break;

		case 44:	// Session::setConnection
		{
			csaLabels.Add("Connection name");
		}
		break;

		case 45:	// Session::setScreen
		{
			csaLabels.Add("Screen object name");
		}
		break;

		case 50:	// ITelnetProxy::setSocksAddress
		{
			csaLabels.Add("Socks address");
		}
		break;

		case 51:	// ITelnetProxy::setSocksPort
		{
			csaLabels.Add("Socks port");
		}
		break;

		case 52:	// ITelnetProxy::setTelnetAddress
		{
			csaLabels.Add("Telnet address");
		}
		break;


		case 53:	// ITelnetProxy::setTelnetPort
		{
			csaLabels.Add("Telnet port");
		}
		break;
		
	}

	if ( bYouShouldGo )
	{
		ShowEditControls( &csaLabels );
	}
	else
	{
		ShowMixedControls( EA0J_API, nFunction, &csaLabels );	
	}

}




