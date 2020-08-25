#include "stdafx.h"
#include "APIGen.h"
#include "APIGenDlg.h"


/****************************************************************************DC
	Function	:	CAPIGenDlg::ShowAirJControls()

	Purpose		:	Show the controls for the Airlines SDK Java function 
					parameters.

	Note		:	

*****************************************************************************/
void CAPIGenDlg::ShowAirJControls( int nFunction )
{
	HideParameterControls();
	csaLabels.RemoveAll();
	BOOL bYouShouldGo=TRUE;

	switch ( nFunction )
	{
		case 0:		// IScreenListener::onConnectionLost
		case 1:		// IScreenListener::onError
		case 2:		// IScreenListener::onLostRemoteWindow
		case 3:		// IScreenListener::onScreenChanged
		case 4:		// IScreenListener::onScreenShapeChanged
		case 5:		// IScreenUPG::addIScreenListener
		case 6:		// IScreenUPG::clearCapturedData
		case 7:		// IScreenUPG::Close
		case 13:	// IScreenUPG::getCapturedData
		case 14:	// IScreenUPG::getColumns
		case 15:	// IScreenUPG::getCursor
		case 16:	// IScreenUPG::getCursorColumn
		case 17:	// IScreenUPG::getCursorRow
		case 18:	// IScreenUPG::getDataCapture
		case 19:	// IScreenUPG::getDescription
		case 21:	// IScreenUPG::getgetText_Display
		case 22:	// IScreenUPG::getKeyboardLocked
		case 23:	// IScreenUPG::getLastError
		case 24:	// IScreenUPG::getMaxDataCaptureLength
		case 25:	// IScreenUPG::getObjectVersion
		case 26:	// IScreenUPG::getOIAContents
		case 27:	// IScreenUPG::getOIAText
		case 28:	// IScreenUPG::getRows
		case 29:	// IScreenUPG::getScreenType
		case 32:	// IScreenUPG::getText
		case 33:	// IScreenUPG::isConnected
		case 34:	// IScreenUPG::isKeyboardLocked
		case 35:	// IScreenUPG::Open
		case 50:	// MutableInt()
		case 52:	// SessionLoader::getConfigurationIPAddress
		case 53:	// SessionLoader::getTerminalType
		case 59:	// SessionLoader::Shutdown
		{
		}
		break;

		case 8:		// IScreenUPG::fieldCount
		{
			csaLabels.Add("Field type");
			bYouShouldGo=FALSE;
		}
		break;

		case 9:		// IScreenUPG::findField
		{
			csaLabels.Add("Row");
			csaLabels.Add("Column");
			csaLabels.Add("Find mode");
			csaLabels.Add("Field type");
			csaLabels.Add("Wrap search");
			bYouShouldGo=FALSE;
		}
		break;

		case 10:	// IScreenUPG::findFieldEx				// 10
		{
			csaLabels.Add("Field index");
			csaLabels.Add("Find mode");
			csaLabels.Add("Field type");
			csaLabels.Add("Wrap search");
			bYouShouldGo=FALSE;
		}
		break;

		case 11:	// IScreenUPG::findString
		{
			csaLabels.Add("String");
			csaLabels.Add("Row");
			csaLabels.Add("Column");
		}
		break;

		case 12:	// IScreenUPG::findStringEx
		{
			csaLabels.Add("String");
			csaLabels.Add("Row");
			csaLabels.Add("Column");
			csaLabels.Add("End row");
			csaLabels.Add("End column");
			csaLabels.Add("Wrap search");
			csaLabels.Add("Direction");
			bYouShouldGo=FALSE;
		}
		break;

		case 20:	// IScreenUPG::getExtPS
		case 30:	// IScreenUPG::getString
		{
			csaLabels.Add("Row");
			csaLabels.Add("Column");
			csaLabels.Add("Length");
		}
		break;

		case 31:	// IScreenUPG::getStringEx
		{
			csaLabels.Add("Start row");
			csaLabels.Add("Start column");
			csaLabels.Add("End row");
			csaLabels.Add("End column");
			csaLabels.Add("Wrap text");
			csaLabels.Add("Attribute");
			bYouShouldGo=FALSE;
		}
		break;

		case 36:	// IScreenUPG::putString
		{
			csaLabels.Add("String");
			csaLabels.Add("Row");
			csaLabels.Add("Column");
		}
		break;

		case 37:	// IScreenUPG::putStringEx
		{
			csaLabels.Add("String");
			csaLabels.Add("Start row");
			csaLabels.Add("Start column");
			csaLabels.Add("End row");
			csaLabels.Add("End column");
			csaLabels.Add("Wrap text");
			csaLabels.Add("Protected field mode");
			csaLabels.Add("Fill char");
			bYouShouldGo=FALSE;
		}
		break;

		case 38:	// IScreenUPG::removeIScreenListener
		{
			csaLabels.Add("Listener name");
		}
		break;

		case 39:	// IScreenUPG::sendKeys
		{
			csaLabels.Add("String");
			csaLabels.Add("Mnemonic format");
			bYouShouldGo=FALSE;
		}
		break;

		case 40:	// IScreenUPG::setCursor
		{
			csaLabels.Add("Row");
			csaLabels.Add("Column");
		}
		break;

		case 41:	// IScreenUPG::setCursorColumn
		{
			csaLabels.Add("Cursor column");
		}
		break;

		case 42:	// IScreenUPG::setCursorRow
		{
			csaLabels.Add("Cursor row");
		}
		break;

		case 43:	// IScreenUPG::setDataCapture
		{
			csaLabels.Add("Data capture facility on");
			bYouShouldGo=FALSE;
		}
		break;

		case 44:	// IScreenUPG::setDescription
		{
			csaLabels.Add("Screen description");
		}
		break;

		case 45:	// IScreenUPG::setgetText_Display
		{
			csaLabels.Add("Output to Standard out");
			bYouShouldGo=FALSE;
		}
		break;

		case 46:	// IScreenUPG::setMaxDataCaptureLength
		{
			csaLabels.Add("Max buffer size");
		}
		break;

		case 47:	// IScreenUPG::waitForCursor
		{
			csaLabels.Add("Row");
			csaLabels.Add("Column");
			csaLabels.Add("Time (ms)");
		}
		break;

		case 48:	// IScreenUPG::waitForString
		{
			csaLabels.Add("String");
			csaLabels.Add("Row");
			csaLabels.Add("Column");
			csaLabels.Add("Time (ms)");
		}
		break;

		case 49:	// IScreenUPG::waitHostQuiet
		{
			csaLabels.Add("Settle time (ms)");
			csaLabels.Add("Wait time (ms)");
		}
		break;

		case 51:	// MutableInt(int)
		{
			csaLabels.Add("Initial value");
		}
		break;

		case 54:	// SessionLoader::requestScreen
		{
			csaLabels.Add("User ID");
			csaLabels.Add("Password");
			csaLabels.Add("HAS webview name");
		}
		break;

		case 55:	// SessionLoader::requestScreenEx
		{
			csaLabels.Add("User ID");
			csaLabels.Add("Password");
			csaLabels.Add("HAS XML webview name");
		}
		break;

		case 56:	// SessionLoader::setConfigurationIPAddress
		{
			csaLabels.Add("DNS name/IP address");
		}
		break;

		case 57:	// SessionLoader::setResourceManagerOptions
		{
			csaLabels.Add("Requested ID count");
			csaLabels.Add("ID increment rate");
			csaLabels.Add("ID Manager address");
		}
		break;

		case 58:	// SessionLoader::setTerminalType
		{
			csaLabels.Add("Terminal type");
			bYouShouldGo=FALSE;
		}
		break;

		default:
		{
			m_groupNoParametersNeeded.ShowWindow( SW_SHOW  );
		}

	}
	
	if ( bYouShouldGo )
	{
		ShowEditControls( &csaLabels );
	}
	else
	{
		ShowMixedControls( AIRJ_API, nFunction, &csaLabels );	
	}
}



/****************************************************************************DC
	Function	:	CAPIGenDlg::ShowAirAxControls()

	Purpose		:	Show the controls for the Airlines SDK ActiveX function 
					parameters.

	Note		:	

*****************************************************************************/
void CAPIGenDlg::ShowAirAxControls( int nFunction )
{
	HideParameterControls();
	csaLabels.RemoveAll();
	BOOL bYouShouldGo=TRUE;

	switch ( nFunction )
	{
		case 0:	// IScreenListener::onConnectionLost		// 0
		case 1:	// IScreenListener::onError
		case 2:	// IScreenListener::onLostRemoteWindow
		case 3:	// IScreenListener::onScreenChanged
		case 4:	// IScreenListener::onScreenShapeChanged

		case 5:	// IScreenUPG::addIScreenListener			// 5
		case 6:	// IScreenUPG::clearCapturedData
		case 7:	// IScreenUPG::Close
		case 8:	// IScreenUPG::fieldCount
		case 9:	// IScreenUPG::findField
		case 10:	// IScreenUPG::findFieldEx				// 10
		case 11:	// IScreenUPG::findString
		case 12:	// IScreenUPG::findStringEx
		case 13:	// IScreenUPG::getCapturedData
		case 14:	// IScreenUPG::getColumns
		case 15:	// IScreenUPG::getCursor					// 15
		case 16:	// IScreenUPG::getCursorColumn
		case 17:	// IScreenUPG::getCursorRow
		case 18:	// IScreenUPG::getDataCapture
		case 19:	// IScreenUPG::getDescription
		case 20:	// IScreenUPG::getExtPS					// 20
		case 21:	// IScreenUPG::getgetText_Display
		case 22:	// IScreenUPG::getKeyboardLocked
		case 23:	// IScreenUPG::getLastError
		case 24:	// IScreenUPG::getMaxDataCaptureLength
		case 25:	// IScreenUPG::getObjectVersion			// 25
		case 26:	// IScreenUPG::getOIAContents
		case 27:	// IScreenUPG::getOIAText
		case 28:	// IScreenUPG::getRows
		case 29:	// IScreenUPG::getScreenType
		case 30:	// IScreenUPG::getString					// 30
		case 31:	// IScreenUPG::getStringEx
		case 32:	// IScreenUPG::getText
		case 33:	// IScreenUPG::isConnected
		case 34:	// IScreenUPG::isKeyboardLocked
		case 35:	// IScreenUPG::Open						// 35
		case 36:	// IScreenUPG::putString
		case 37:	// IScreenUPG::putStringEx
		case 38:	// IScreenUPG::removeIScreenListener
		case 39:	// IScreenUPG::sendKeys
		case 40:	// IScreenUPG::setCursor					// 40
		case 41:	// IScreenUPG::setCursorColumn
		case 42:	// IScreenUPG::setCursorRow
		case 43:	// IScreenUPG::setDataCapture
		case 44:	// IScreenUPG::setDescription
		case 45:	// IScreenUPG::setgetText_Display			// 45

		case 48:	// IScreenUPG::waitForString
		case 49:	// IScreenUPG::waitHostQuiet

		case 50:	// MutableInt()							// 50
		case 51:	// MutableInt(int)

		case 52:	// SessionLoader::getConfigurationIPAddress
		case 53:	// SessionLoader::getTerminalType
		case 54:	// SessionLoader::requestScreen
		case 55:	// SessionLoader::requestScreenEx			// 55
		case 56:	// SessionLoader::setConfigurationIPAddress
		case 57:	// SessionLoader::setResourceManagerOptions
		case 58:	// SessionLoader::setTerminalType
		case 59:	// SessionLoader::Shutdown
		{
			m_groupNoParametersNeeded.ShowWindow( SW_SHOW  );
		}
		break;

		case 46:	// IScreenUPG::setMaxDataCaptureLength
		{
			csaLabels.Add("Max buffer size");
		}
		break;

		case 47:	// IScreenUPG::waitForCursor
		{
			csaLabels.Add("Row");
			csaLabels.Add("Column");
			csaLabels.Add("Time (ms)");
		}
		break;


		default:
		{
			m_groupNoParametersNeeded.ShowWindow( SW_SHOW  );
		}

	}

	if ( bYouShouldGo )
	{
		ShowEditControls( &csaLabels );
	}
	else
	{
		ShowMixedControls( AIRJ_API, nFunction, &csaLabels );	
	}

}


/****************************************************************************DC
	Function	:	CAPIGenDlg::LoadAirlinesJavaArgumentArray()

	Purpose		:	Load the function arguments for EAL.

*****************************************************************************/
void CAPIGenDlg::LoadAirlinesJavaArgumentArray( int* nFunctionPosition, BOOL bPromptForValues )
{
	CString	csFunctionName, csFunctionNum;

	UpdateData();

	*nFunctionPosition = m_listTranslateFunction.GetCurSel();
	m_listTranslateFunction.GetText( *nFunctionPosition, csFunctionName );

	// add the function name
	csaArguments.Add( csFunctionName );

	if ( bPromptForValues )
	{
		switch ( *nFunctionPosition )
		{
			case 0:	// IScreenListener::onConnectionLost
			case 1:	// IScreenListener::onError
			case 2:	// IScreenListener::onLostRemoteWindow
			case 3:	// IScreenListener::onScreenChanged
			case 4:	// IScreenListener::onScreenShapeChanged
			case 5:	// IScreenUPG::addIScreenListener
			case 6:	// IScreenUPG::clearCapturedData
			case 7:	// IScreenUPG::Close
			case 13:	// IScreenUPG::getCapturedData
			case 14:	// IScreenUPG::getColumns
			case 15:	// IScreenUPG::getCursor
			case 16:	// IScreenUPG::getCursorColumn
			case 17:	// IScreenUPG::getCursorRow
			case 18:	// IScreenUPG::getDataCapture
			case 19:	// IScreenUPG::getDescription
			case 21:	// IScreenUPG::getgetText_Display
			case 22:	// IScreenUPG::getKeyboardLocked
			case 23:	// IScreenUPG::getLastError
			case 24:	// IScreenUPG::getMaxDataCaptureLength
			case 25:	// IScreenUPG::getObjectVersion
			case 26:	// IScreenUPG::getOIAContents
			case 27:	// IScreenUPG::getOIAText
			case 28:	// IScreenUPG::getRows
			case 29:	// IScreenUPG::getScreenType
			case 32:	// IScreenUPG::getText
			case 33:	// IScreenUPG::isConnected
			case 34:	// IScreenUPG::isKeyboardLocked
			case 35:	// IScreenUPG::Open
			case 50:	// MutableInt()
			case 52:	// SessionLoader::getConfigurationIPAddress
			case 53:	// SessionLoader::getTerminalType
			case 59:	// SessionLoader::Shutdown
			{
			}
			break;

			
			// single parameter
			case 38:	// IScreenUPG::removeIScreenListener
			case 41:	// IScreenUPG::setCursorColumn
			case 42:	// IScreenUPG::setCursorRow
			case 44:	// IScreenUPG::setDescription
			case 46:	// IScreenUPG::setMaxDataCaptureLength
			case 51:	// MutableInt(int)
			case 56:	// SessionLoader::setConfigurationIPAddress
			{
				Read1E( &csaArguments );
				//csaArguments.Add( m_csEditArgument1 );
			}
			break;

			case 58:	// SessionLoader::setTerminalType
			{
				Read1L( &csaArguments );
			}
			break;


			case 43:	// IScreenUPG::setDataCapture
			case 45:	// IScreenUPG::setgetText_Display
			{
				Read1C( &csaArguments );
			}
			break;

			case 8:		// IScreenUPG::fieldCount
			{
				Read1L( &csaArguments );
			}
			break;

			case 9:		// IScreenUPG::findField
			{
				Read2E2L1C( &csaArguments );
			}
			break;

			case 10:	// IScreenUPG::findFieldEx
			{
				Read1E2L1C( &csaArguments );
			}
			break;

			case 31:	// IScreenUPG::getStringEx
			{
				Read4E1C1ML( &csaArguments );
			}
			break;

			case 39:	// IScreenUPG::sendKeys
			{
				Read1E1L( &csaArguments );
			}
			break;

			// two parameters
			case 40:	// IScreenUPG::setCursor
			case 49:	// IScreenUPG::waitHostQuiet
			{
				Read2E( &csaArguments );
			}
			break;

			// three parameters
			case 11:	// IScreenUPG::findString
			case 20:	// IScreenUPG::getExtPS
			case 30:	// IScreenUPG::getString
			case 36:	// IScreenUPG::putString
			case 47:	// IScreenUPG::waitForCursor
			case 54:	// SessionLoader::requestScreen
			case 55:	// SessionLoader::requestScreenEx
			case 57:	// SessionLoader::setResourceManagerOptions
			{
				Read3E( &csaArguments );
			}
			break;

			// four parameters
			case 48:	// IScreenUPG::waitForString
			{
				Read4E( &csaArguments );
			}
			break;


			// seven parameter
			case 12:	// IScreenUPG::findStringEx
			{
				Read5E1C1L( &csaArguments );
			}
			break;

			// eight parameters
			case 37:	// IScreenUPG::putStringEx
			{
				Read5E1C1L1C( &csaArguments );
			}
			break;

			default:
			{

			}
			break;
		}
	}
	else
	{

		switch ( *nFunctionPosition )
		{
			case 0:		// IScreenListener::onConnectionLost
			case 1:		// IScreenListener::onError
			case 2:		// IScreenListener::onLostRemoteWindow
			case 3:		// IScreenListener::onScreenChanged
			case 4:		// IScreenListener::onScreenShapeChanged
			{
			}
			break;


			case 5:	// IScreenUPG::addIScreenListener
			case 6:		// IScreenUPG::clearCapturedData
			case 7:		// IScreenUPG::Close
			{
				csaArguments.Add("700");	// table
				csaArguments.Add("701");	// event
			}
			break;


			case 8:		// IScreenUPG::fieldCount
			{
				csaArguments.Add("A");
			}
			break;


			case 9:	// IScreenUPG::findField
			case 10:	// IScreenUPG::findFieldEx
			case 11:	// IScreenUPG::findString
			case 12:	// IScreenUPG::findStringEx
			case 13:	// IScreenUPG::getCapturedData
			case 14:	// IScreenUPG::getColumns
			case 15:	// IScreenUPG::getCursor
			case 16:	// IScreenUPG::getCursorColumn
			case 17:	// IScreenUPG::getCursorRow
			case 18:	// IScreenUPG::getDataCapture
			case 19:	// IScreenUPG::getDescription
			case 20:	// IScreenUPG::getExtPS
			case 21:	// IScreenUPG::getgetText_Display
			case 22:	// IScreenUPG::getKeyboardLocked
			case 23:	// IScreenUPG::getLastError
			case 24:	// IScreenUPG::getMaxDataCaptureLength
			case 25:	// IScreenUPG::getObjectVersion
			case 26:	// IScreenUPG::getOIAContents
			case 27:	// IScreenUPG::getOIAText
			case 28:	// IScreenUPG::getRows
			case 29:	// IScreenUPG::getScreenType
			case 30:	// IScreenUPG::getString
			case 31:	// IScreenUPG::getStringEx
			case 32:	// IScreenUPG::getText
			case 33:	// IScreenUPG::isConnected
			{
			}
			break;


			case 34:	// IScreenUPG::isKeyboardLocked
			{
				csaArguments.Add("Hello.ebm");
				csaArguments.Add("3001");
			}
			break;

			case 35:	// IScreenUPG::Open
			{
				csaArguments.Add("ATM_XSTATUS");
			}
			break;

			
			case 36:	// IScreenUPG::putString
			{
				csaArguments.Add("20");
				csaArguments.Add("17");
				csaArguments.Add("ATM_ISFIELDHIDDEN");
				// ATM_ISFIELDPROTECTED
				// ATM_ISFIELDNUMERIC
				// ATM_ISFIELDSELECTORPENDETECTABLE
				// ATM_ISFIELDBOLD
				// ATM_ISFIELDHIDDEN
				// ATM_ISFIELDMODIFIED
			}
			break;
			

			case 37:	// IScreenUPG::putStringEx
			case 38:	// IScreenUPG::removeIScreenListener
			{
				csaArguments.Add("20");
				csaArguments.Add("17");
				csaArguments.Add("ATM_THISFIELD");
				// ATM_NEXTFIELD
				// ATM_PREVIOUSFIELD
				// ATM_NEXTPROTECTEDFIELD
				// ATM_NEXTUNPROTECTEDFIELD
				// ATM_PREVIOUSPROTECTED
				// ATM_PREVIOUSUNPROTECTED
			}
			break;

				
			case 39:	// IScreenUPG::sendKeys
			{
				csaArguments.Add("A");
			}
			break;
			

			case 40:	// IScreenUPG::setCursor
			{
				csaArguments.Add("ATM_ATTRIB");

				// ATM_ATTRIB
				// ATM_AUTORESET
				// ATM_CONNECTTYPE
				// ATM_EAB
				// ATM_PAUSE
				// ATM_SEARCHORG
				// ATM_SEARCHDIRECTION
				// ATM_TIMEOUT
				// ATM_TRACE
				// ATM_WAIT
				// ATM_XLATE
				// ATM_ESCAPE

			}
			break;


			case 41:	// IScreenUPG::setCursorColumn
			{
				csaArguments.Add("286");				// length
				csaArguments.Add("ATM_GETCONFIGURED");	// sessionState
				// ATM_GETCONFIGURED
				// ATM_GETOPENED
				// ATM_GETPOWERED
				// ATM_GETCONFIGUREDCOUNT
				// ATM_GETOPENEDCOUNT
				// ATM_GETPOWEREDCOUNT
				// ATM_GETEMULATED
				// ATM_GETEMULATEDPOWERED
				// ATM_GETEMULATEDCOUNT
				// ATM_GETEMULATEDPOWEREDCOUNT
			}
			break;



			case 42:	// IScreenUPG::setCursorRow
			{
				csaArguments.Add("A");
				csaArguments.Add("ATM_ISCONFIGURED");
				// ATM_ISCONFIGURED
				// ATM_ISOPENED
				// ATM_ISPOWERED
				// ATM_ISEMULATED
				// ATM_ISCONNECTED
				// ATM_ISFILETRANSFER

			}
			break;


			case 43:	// IScreenUPG::setDataCapture
			{
				csaArguments.Add("TRUE");
			}
			break;

			case 44:	// IScreenUPG::setDescription
			{
				csaArguments.Add("312");	// row
				csaArguments.Add("APIGen List Sessions Demo");	// column
				csaArguments.Add("12");	// type
				// 1	configured
				// 2	open
				// 3	powered
				// 11	emulated
				// 12	emulated and powered

			}
			break;

			case 45:	// IScreenUPG::setgetText_Display
			{
				csaArguments.Add( "TRUE" );
			}
			break;


			case 46:	// IScreenUPG::setMaxDataCaptureLength
			{
				csaArguments.Add( "1000" );
			}
			break;

			case 47:	// IScreenUPG::waitForCursor
			{
				csaArguments.Add( "2005" );
			}
			break;




			case 48:	// IScreenUPG::waitForString
			{
				csaArguments.Add( "logon UserID@E" );
			}
			break;



			case 49:	// IScreenUPG::waitHostQuiet
			case 50:	// MutableInt()
			{
				csaArguments.Add( "234" );
				csaArguments.Add( "567" );
			}
			break;

			case 51:	// MutableInt(int)
			{
				csaArguments.Add( "ATM_EXTRA" );
				// ATM_EXTRA
				// ATM_RALLY
				// ATM_KEA
				// ATM_IRMA
				// ATM_ICONN
				// ATM_HP

			}
			break;


			case 52:	// SessionLoader::getConfigurationIPAddress
			{
				csaArguments.Add( "1637" );
				csaArguments.Add( "ATM_GETROW" );
				// ATM_GETROW
				// ATM_GETCOLUMN
			}
			break;



			case 53:	// SessionLoader::getTerminalType
			case 54:	// SessionLoader::requestScreen
			{
				csaArguments.Add( "A" );
				CString csTemp("c:\\program files\\Attachmate\\EXTRA!\\Macros\\ENU\\Hello.ebm");
				csTemp.Replace( "\\", "\\\\" );
				csaArguments.Add( csTemp );
			}
			break;


			
			case 55:	// SessionLoader::requestScreenEx
				{
					csaArguments.Add( "User1" );
					csaArguments.Add( "Password2" );
					csaArguments.Add( "SYSTEM390.XML" );
				}
				break;


			case 56:	// SessionLoader::setConfigurationIPAddress
				{
					csaArguments.Add( "1" );
					csaArguments.Add( "2" );
					csaArguments.Add( "CROSSROADS" );
					csaArguments.Add( "ATM_SEARCHALL" );
					// ATM_SEARCHALL
					// ATM_SEARCHFROM
					// ATM_SEARCHAT
					// ATM_SEARCHBACK

				}
				break;


			case 57:	// SessionLoader::setResourceManagerOptions
				{
					csaArguments.Add( "19" );
					csaArguments.Add( "25" );
					csaArguments.Add( "" );
				}
				break;



			case 58:	// SessionLoader::setTerminalType
			{
				csaArguments.Add( "20" );
				csaArguments.Add( "17" );
				csaArguments.Add( "USERID" );
			}
			break;



			case 59:	// SessionLoader::Shutdown
			{
				csaArguments.Add("A");
				csaArguments.Add("H");

			}
			break;

		}
		
	}
}


/****************************************************************************DC
	Function	:	CAPIGenDlg::LoadAirlinesAxArgumentArray()

	Purpose		:	Load the function arguments for EAL.

*****************************************************************************/
void CAPIGenDlg::LoadAirlinesAxArgumentArray( int* nFunctionPosition, BOOL bPromptForValues )
{
	CString	csFunctionName, csFunctionNum;

	UpdateData();

	*nFunctionPosition = m_listTranslateFunction.GetCurSel();
	m_listTranslateFunction.GetText( *nFunctionPosition, csFunctionName );

	// add the function name
	csaArguments.Add( csFunctionName );

	if ( bPromptForValues )
	{
		switch ( *nFunctionPosition )
		{
			case 0:	// IScreenListener::onConnectionLost
			case 1:	// IScreenListener::onError
			case 2:	// IScreenListener::onLostRemoteWindow
			case 3:	// IScreenListener::onScreenChanged
			case 4:	// IScreenListener::onScreenShapeChanged
			case 5:	// IScreenUPG::addIScreenListener
			case 6:	// IScreenUPG::clearCapturedData
			case 7:	// IScreenUPG::Close
			case 13:	// IScreenUPG::getCapturedData
			case 14:	// IScreenUPG::getColumns
			case 15:	// IScreenUPG::getCursor
			case 16:	// IScreenUPG::getCursorColumn
			case 17:	// IScreenUPG::getCursorRow
			case 18:	// IScreenUPG::getDataCapture
			case 19:	// IScreenUPG::getDescription
			case 21:	// IScreenUPG::getgetText_Display
			case 22:	// IScreenUPG::getKeyboardLocked
			case 23:	// IScreenUPG::getLastError
			case 24:	// IScreenUPG::getMaxDataCaptureLength
			case 25:	// IScreenUPG::getObjectVersion
			case 26:	// IScreenUPG::getOIAContents
			case 27:	// IScreenUPG::getOIAText
			case 28:	// IScreenUPG::getRows
			case 29:	// IScreenUPG::getScreenType
			case 32:	// IScreenUPG::getText
			case 33:	// IScreenUPG::isConnected
			case 34:	// IScreenUPG::isKeyboardLocked
			case 35:	// IScreenUPG::Open
			case 50:	// MutableInt()
			case 52:	// SessionLoader::getConfigurationIPAddress
			case 53:	// SessionLoader::getTerminalType
			case 59:	// SessionLoader::Shutdown
			{
			}
			break;

			
			// single parameter
			case 38:	// IScreenUPG::removeIScreenListener
			case 41:	// IScreenUPG::setCursorColumn
			case 42:	// IScreenUPG::setCursorRow
			case 44:	// IScreenUPG::setDescription
			case 46:	// IScreenUPG::setMaxDataCaptureLength
			case 51:	// MutableInt(int)
			case 56:	// SessionLoader::setConfigurationIPAddress
			case 58:	// SessionLoader::setTerminalType
			{
				Read1E( &csaArguments );
				//csaArguments.Add( m_csEditArgument1 );
			}
			break;

			case 43:	// IScreenUPG::setDataCapture
			case 45:	// IScreenUPG::setgetText_Display
			{
				Read1C( &csaArguments );
			}
			break;



			// one listbox
			case 8:		// IScreenUPG::fieldCount
			{
				Read1L( &csaArguments );
			}
			break;

			// two parameters
			case 39:	// IScreenUPG::sendKeys
			case 40:	// IScreenUPG::setCursor
			case 49:	// IScreenUPG::waitHostQuiet
			{
				Read2E( &csaArguments );
			}
			break;


			// three parameters
			case 11:	// IScreenUPG::findString
			case 20:	// IScreenUPG::getExtPS
			case 30:	// IScreenUPG::getString
			case 36:	// IScreenUPG::putString
			case 47:	// IScreenUPG::waitForCursor
			case 54:	// SessionLoader::requestScreen
			case 55:	// SessionLoader::requestScreenEx
			case 57:	// SessionLoader::setResourceManagerOptions
			{
				Read3E( &csaArguments );
			}
			break;

			// four parameters
			case 10:	// IScreenUPG::findFieldEx
			case 48:	// IScreenUPG::waitForString
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


			// five parameters
			case 9:	// IScreenUPG::findField
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

			// seven parameter
			case 12:	// IScreenUPG::findStringEx
			case 31:	// IScreenUPG::getStringEx
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

			// eight parameters
			case 37:	// IScreenUPG::putStringEx
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

			default:
			{

			}
			break;
		}
	}
	else
	{

		switch ( *nFunctionPosition )
		{
			case 0:		// IScreenListener::onConnectionLost
			case 1:		// IScreenListener::onError
			case 2:		// IScreenListener::onLostRemoteWindow
			case 3:		// IScreenListener::onScreenChanged
			case 4:		// IScreenListener::onScreenShapeChanged
			{
			}
			break;


			case 5:	// IScreenUPG::addIScreenListener
			case 6:		// IScreenUPG::clearCapturedData
			case 7:		// IScreenUPG::Close
			{
				csaArguments.Add("700");	// table
				csaArguments.Add("701");	// event
			}
			break;


			case 8:		// IScreenUPG::fieldCount
			{
				csaArguments.Add("A");
			}
			break;


			case 9:	// IScreenUPG::findField
			case 10:	// IScreenUPG::findFieldEx
			case 11:	// IScreenUPG::findString
			case 12:	// IScreenUPG::findStringEx
			case 13:	// IScreenUPG::getCapturedData
			case 14:	// IScreenUPG::getColumns
			case 15:	// IScreenUPG::getCursor
			case 16:	// IScreenUPG::getCursorColumn
			case 17:	// IScreenUPG::getCursorRow
			case 18:	// IScreenUPG::getDataCapture
			case 19:	// IScreenUPG::getDescription
			case 20:	// IScreenUPG::getExtPS
			case 21:	// IScreenUPG::getgetText_Display
			case 22:	// IScreenUPG::getKeyboardLocked
			case 23:	// IScreenUPG::getLastError
			case 24:	// IScreenUPG::getMaxDataCaptureLength
			case 25:	// IScreenUPG::getObjectVersion
			case 26:	// IScreenUPG::getOIAContents
			case 27:	// IScreenUPG::getOIAText
			case 28:	// IScreenUPG::getRows
			case 29:	// IScreenUPG::getScreenType
			case 30:	// IScreenUPG::getString
			case 31:	// IScreenUPG::getStringEx
			case 32:	// IScreenUPG::getText
			case 33:	// IScreenUPG::isConnected
			{
			}
			break;


			case 34:	// IScreenUPG::isKeyboardLocked
			{
				csaArguments.Add("Hello.ebm");
				csaArguments.Add("3001");
			}
			break;

			case 35:	// IScreenUPG::Open
			{
				csaArguments.Add("ATM_XSTATUS");
			}
			break;

			
			case 36:	// IScreenUPG::putString
			{
				csaArguments.Add("20");
				csaArguments.Add("17");
				csaArguments.Add("ATM_ISFIELDHIDDEN");
				// ATM_ISFIELDPROTECTED
				// ATM_ISFIELDNUMERIC
				// ATM_ISFIELDSELECTORPENDETECTABLE
				// ATM_ISFIELDBOLD
				// ATM_ISFIELDHIDDEN
				// ATM_ISFIELDMODIFIED
			}
			break;
			

			case 37:	// IScreenUPG::putStringEx
			case 38:	// IScreenUPG::removeIScreenListener
			{
				csaArguments.Add("20");
				csaArguments.Add("17");
				csaArguments.Add("ATM_THISFIELD");
				// ATM_NEXTFIELD
				// ATM_PREVIOUSFIELD
				// ATM_NEXTPROTECTEDFIELD
				// ATM_NEXTUNPROTECTEDFIELD
				// ATM_PREVIOUSPROTECTED
				// ATM_PREVIOUSUNPROTECTED
			}
			break;

				
			case 39:	// IScreenUPG::sendKeys
			{
				csaArguments.Add("A");
			}
			break;
			

			case 40:	// IScreenUPG::setCursor
			{
				csaArguments.Add("ATM_ATTRIB");

				// ATM_ATTRIB
				// ATM_AUTORESET
				// ATM_CONNECTTYPE
				// ATM_EAB
				// ATM_PAUSE
				// ATM_SEARCHORG
				// ATM_SEARCHDIRECTION
				// ATM_TIMEOUT
				// ATM_TRACE
				// ATM_WAIT
				// ATM_XLATE
				// ATM_ESCAPE

			}
			break;


			case 41:	// IScreenUPG::setCursorColumn
			{
				csaArguments.Add("286");				// length
				csaArguments.Add("ATM_GETCONFIGURED");	// sessionState
				// ATM_GETCONFIGURED
				// ATM_GETOPENED
				// ATM_GETPOWERED
				// ATM_GETCONFIGUREDCOUNT
				// ATM_GETOPENEDCOUNT
				// ATM_GETPOWEREDCOUNT
				// ATM_GETEMULATED
				// ATM_GETEMULATEDPOWERED
				// ATM_GETEMULATEDCOUNT
				// ATM_GETEMULATEDPOWEREDCOUNT
			}
			break;



			case 42:	// IScreenUPG::setCursorRow
			{
				csaArguments.Add("A");
				csaArguments.Add("ATM_ISCONFIGURED");
				// ATM_ISCONFIGURED
				// ATM_ISOPENED
				// ATM_ISPOWERED
				// ATM_ISEMULATED
				// ATM_ISCONNECTED
				// ATM_ISFILETRANSFER

			}
			break;


			case 43:	// IScreenUPG::setDataCapture
			{
				csaArguments.Add("TRUE");
			}
			break;

			case 44:	// IScreenUPG::setDescription
			{
				csaArguments.Add("312");	// row
				csaArguments.Add("APIGen List Sessions Demo");	// column
				csaArguments.Add("12");	// type
				// 1	configured
				// 2	open
				// 3	powered
				// 11	emulated
				// 12	emulated and powered

			}
			break;

			case 45:	// IScreenUPG::setgetText_Display
			{
				CString csTemp("c:\\program files\\Attachmate\\EXTRA!\\Sessions\\es9000.edp");
				csTemp.Replace( "\\", "\\\\" );
				csaArguments.Add( csTemp );
			}
			break;


			case 46:	// IScreenUPG::setMaxDataCaptureLength
			{
				csaArguments.Add( "200" );
			}
			break;

			case 47:	// IScreenUPG::waitForCursor
			{
				csaArguments.Add( "2005" );
			}
			break;




			case 48:	// IScreenUPG::waitForString
			{
				csaArguments.Add( "logon UserID@E" );
			}
			break;



			case 49:	// IScreenUPG::waitHostQuiet
			case 50:	// MutableInt()
			{
				csaArguments.Add( "234" );
				csaArguments.Add( "567" );
			}
			break;

			case 51:	// MutableInt(int)
			{
				csaArguments.Add( "ATM_EXTRA" );
				// ATM_EXTRA
				// ATM_RALLY
				// ATM_KEA
				// ATM_IRMA
				// ATM_ICONN
				// ATM_HP

			}
			break;


			case 52:	// SessionLoader::getConfigurationIPAddress
			{
				csaArguments.Add( "1637" );
				csaArguments.Add( "ATM_GETROW" );
				// ATM_GETROW
				// ATM_GETCOLUMN
			}
			break;



			case 53:	// SessionLoader::getTerminalType
			case 54:	// SessionLoader::requestScreen
			{
				csaArguments.Add( "A" );
				CString csTemp("c:\\program files\\Attachmate\\EXTRA!\\Macros\\ENU\\Hello.ebm");
				csTemp.Replace( "\\", "\\\\" );
				csaArguments.Add( csTemp );
			}
			break;


			
			case 55:	// SessionLoader::requestScreenEx
				{
					csaArguments.Add( "1" );
					csaArguments.Add( "2" );
					csaArguments.Add( "SYSTEM 390" );
				}
				break;


			case 56:	// SessionLoader::setConfigurationIPAddress
				{
					csaArguments.Add( "1" );
					csaArguments.Add( "2" );
					csaArguments.Add( "CROSSROADS" );
					csaArguments.Add( "ATM_SEARCHALL" );
					// ATM_SEARCHALL
					// ATM_SEARCHFROM
					// ATM_SEARCHAT
					// ATM_SEARCHBACK

				}
				break;


			case 57:	// SessionLoader::setResourceManagerOptions
				{
					csaArguments.Add( "19" );
					csaArguments.Add( "19" );
					csaArguments.Add( "149.82.2.75" );
				}
				break;



			case 58:	// SessionLoader::setTerminalType
			{
				csaArguments.Add( "20" );
				csaArguments.Add( "17" );
				csaArguments.Add( "USERID" );
			}
			break;



			case 59:	// SessionLoader::Shutdown
			{
				csaArguments.Add("A");
				csaArguments.Add("H");

			}
			break;



		}
		
	}
}
