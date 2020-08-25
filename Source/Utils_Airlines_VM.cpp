#include "stdafx.h"
#include "APIGen.h"
#include "APIGenDlg.h"


/****************************************************************************DC
	Function	:	CAPIGenDlg::ShowAirVMControls()

	Purpose		:	Show the controls for the Viewmaster function 
					parameters.

	Note		:	

*****************************************************************************/
void CAPIGenDlg::ShowAirVMControls( int nFunction )
{
	HideParameterControls();
	csaLabels.RemoveAll();
	BOOL bYouShouldGo=TRUE;

	switch ( nFunction )
	{
		case 0:		// IScreenUPG::clearCapturedData
		case 6:		// IScreenUPG::focusTerminal
		case 7:		// IScreenUPG::getCapturedData
		case 8:		// IScreenUPG::getColumns
		case 9:		// IScreenUPG::getConnectStatus
		case 10:	// IScreenUPG::getCursor
		case 11:	// IScreenUPG::getCursorColumn
		case 12:	// IScreenUPG::getCursorRow
		case 13:	// IScreenUPG::getDataCapture
		case 15:	// IScreenUPG::getgetText_Display
		case 16:	// IScreenUPG::getKeyboardLocked
		case 17:	// IScreenUPG::getMaxDataCaptureLength
		case 18:	// IScreenUPG::getObjectVersion
		case 19:	// IScreenUPG::getOIAContents
		case 20:	// IScreenUPG::getOIAText
		case 21:	// IScreenUPG::getRows
		case 22:	// IScreenUPG::getScreenType
		case 25:	// IScreenUPG::getText
		case 26:	// IScreenUPG::hideTerminal
		case 27:	// IScreenUPG::isKeyboardLocked
		case 37:	// IScreenUPG::showColorDialog
		case 38:	// IScreenUPG::showTerminal
		{

		}
		break;

		case 1:		// IScreenUPG::fieldCount
		{
			csaLabels.Add("Field type");
			bYouShouldGo=FALSE;
		}
		break;

		case 2:		// IScreenUPG::findField
		{
			csaLabels.Add("Row");
			csaLabels.Add("Column");
			csaLabels.Add("Find mode");
			csaLabels.Add("Field type");
			csaLabels.Add("Wrap search");
			bYouShouldGo=FALSE;
		}
		break;

		case 3:	// IScreenUPG::findFieldEx				// 10
		{
			csaLabels.Add("Field index");
			csaLabels.Add("Find mode");
			csaLabels.Add("Field type");
			csaLabels.Add("Wrap search");
			bYouShouldGo=FALSE;
		}
		break;

		case 4:	// IScreenUPG::findString
		{
			csaLabels.Add("String");
			csaLabels.Add("Row");
			csaLabels.Add("Column");
		}
		break;

		case 5:	// IScreenUPG::findStringEx
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


		case 14:	// IScreenUPG::getExtPS
		case 23:	// IScreenUPG::getString
		{
			csaLabels.Add("Row");
			csaLabels.Add("Column");
			csaLabels.Add("Length");
		}
		break;

		case 24:	// IScreenUPG::getStringEx
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

		case 28:	// IScreenUPG::putString
		{
			csaLabels.Add("String");
			csaLabels.Add("Row");
			csaLabels.Add("Column");
		}
		break;

		case 29:	// IScreenUPG::putStringEx
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

		case 30:	// IScreenUPG::sendKeys
		{
			csaLabels.Add("String");
			csaLabels.Add("Mnemonic format");
			bYouShouldGo=FALSE;
		}
		break;

		case 31:	// IScreenUPG::setCursor
		{
			csaLabels.Add("Row");
			csaLabels.Add("Column");
		}
		break;

		case 32:	// IScreenUPG::setCursorColumn
		{
			csaLabels.Add("Cursor column");
		}
		break;

		case 33:	// IScreenUPG::setCursorRow
		{
			csaLabels.Add("Cursor row");
		}
		break;

		case 34:	// IScreenUPG::setDataCapture
		{
			csaLabels.Add("Data capture facility on");
			bYouShouldGo=FALSE;
		}
		break;

		case 35:	// IScreenUPG::setgetText_Display
		{
			csaLabels.Add("Output to Standard out");
			bYouShouldGo=FALSE;
		}
		break;

		case 36:	// IScreenUPG::setMaxDataCaptureLength
		{
			csaLabels.Add("Max buffer size");
		}
		break;

		case 39:	// IScreenUPG::waitForCursor
		{
			csaLabels.Add("Row");
			csaLabels.Add("Column");
			csaLabels.Add("Time (ms)");
		}
		break;

		case 40:	// IScreenUPG::waitForString
		{
			csaLabels.Add("String");
			csaLabels.Add("Row");
			csaLabels.Add("Column");
			csaLabels.Add("Time (ms)");
		}
		break;

		case 41:	// IScreenUPG::waitHostQuiet
		{
			csaLabels.Add("Settle time (ms)");
			csaLabels.Add("Wait time (ms)");
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
		ShowMixedControls( VIEWMASTER_API, nFunction, &csaLabels );	
	}
}




/****************************************************************************DC
	Function	:	CAPIGenDlg::LoadAirVMArgumentArray()

	Purpose		:	Load the function arguments for EAL.

*****************************************************************************/
void CAPIGenDlg::LoadAirVMArgumentArray( int* nFunctionPosition, BOOL bPromptForValues )
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
			case 0:		// IScreenUPG::clearCapturedData
			case 6:		// IScreenUPG::focusTerminal
			case 7:		// IScreenUPG::getCapturedData
			case 8:		// IScreenUPG::getColumns
			case 9:		// IScreenUPG::getConnectStatus
			case 10:	// IScreenUPG::getCursor
			case 11:	// IScreenUPG::getCursorColumn
			case 12:	// IScreenUPG::getCursorRow
			case 13:	// IScreenUPG::getDataCapture
			case 15:	// IScreenUPG::getgetText_Display
			case 16:	// IScreenUPG::getKeyboardLocked
			case 17:	// IScreenUPG::getMaxDataCaptureLength
			case 18:	// IScreenUPG::getObjectVersion
			case 19:	// IScreenUPG::getOIAContents
			case 20:	// IScreenUPG::getOIAText
			case 21:	// IScreenUPG::getRows
			case 22:	// IScreenUPG::getScreenType
			case 25:	// IScreenUPG::getText
			case 26:	// IScreenUPG::hideTerminal
			case 27:	// IScreenUPG::isKeyboardLocked
			case 37:		// IScreenUPG::showColorDialog
			case 38:		// IScreenUPG::showTerminal
			{
			}
			break;


			// single parameter
			case 32:	// IScreenUPG::setCursorColumn
			case 33:	// IScreenUPG::setCursorRow
			case 36:	// IScreenUPG::setMaxDataCaptureLength
			{
				Read1E( &csaArguments );
				//csaArguments.Add( m_csEditArgument1 );
			}
			break;


			case 34:	// IScreenUPG::setDataCapture
			case 35:	// IScreenUPG::setgetText_Display
			{
				Read1C( &csaArguments );
			}
			break;

			case 1:		// IScreenUPG::fieldCount
			{
				Read1L( &csaArguments );
			}
			break;

			case 2:		// IScreenUPG::findField
			{
				Read2E2L1C( &csaArguments );
			}
			break;

			case 3:	// IScreenUPG::findFieldEx
			{
				Read1E2L1C( &csaArguments );
			}
			break;

			case 24:	// IScreenUPG::getStringEx
			{
				Read4E1C1ML( &csaArguments );
			}
			break;

			case 30:	// IScreenUPG::sendKeys
			{
				Read1E1L( &csaArguments );
			}
			break;

			// two parameters
			case 31:	// IScreenUPG::setCursor
			case 41:	// IScreenUPG::waitHostQuiet
			{
				Read2E( &csaArguments );
			}
			break;

			// three parameters
			case 4:	// IScreenUPG::findString
			case 14:	// IScreenUPG::getExtPS
			case 23:	// IScreenUPG::getString
			case 28:	// IScreenUPG::putString
			case 39:	// IScreenUPG::waitForCursor
			{
				Read3E( &csaArguments );
			}
			break;

			// four parameters
			case 40:	// IScreenUPG::waitForString
			{
				Read4E( &csaArguments );
			}
			break;


			// seven parameter
			case 5:	// IScreenUPG::findStringEx
			{
				Read5E1C1L( &csaArguments );
			}
			break;

			// eight parameters
			case 29:	// IScreenUPG::putStringEx
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
			case 0:		// IScreenUPG::clearCapturedData
			case 6:		// IScreenUPG::focusTerminal
			case 7:		// IScreenUPG::getCapturedData
			case 8:		// IScreenUPG::getColumns
			case 9:		// IScreenUPG::getConnectStatus
			case 10:	// IScreenUPG::getCursor
			case 11:	// IScreenUPG::getCursorColumn
			case 12:	// IScreenUPG::getCursorRow
			case 13:	// IScreenUPG::getDataCapture
			case 15:	// IScreenUPG::getgetText_Display
			case 16:	// IScreenUPG::getKeyboardLocked
			case 17:	// IScreenUPG::getMaxDataCaptureLength
			case 18:	// IScreenUPG::getObjectVersion
			case 19:	// IScreenUPG::getOIAContents
			case 20:	// IScreenUPG::getOIAText
			case 21:	// IScreenUPG::getRows
			case 22:	// IScreenUPG::getScreenType
			case 25:	// IScreenUPG::getText
			case 26:	// IScreenUPG::hideTerminal
			case 27:	// IScreenUPG::isKeyboardLocked
			case 37:		// IScreenUPG::showColorDialog
			case 38:		// IScreenUPG::showTerminal
			{
			}
			break;


			// single parameter
			case 32:	// IScreenUPG::setCursorColumn
			case 33:	// IScreenUPG::setCursorRow
			case 36:	// IScreenUPG::setMaxDataCaptureLength
			{
				Read1E( &csaArguments );
				//csaArguments.Add( m_csEditArgument1 );
			}
			break;


			case 34:	// IScreenUPG::setDataCapture
			case 35:	// IScreenUPG::setgetText_Display
			{
				Read1C( &csaArguments );
			}
			break;

			case 1:		// IScreenUPG::fieldCount
			{
				Read1L( &csaArguments );
			}
			break;

			case 2:		// IScreenUPG::findField
			{
				Read2E2L1C( &csaArguments );
			}
			break;

			case 3:	// IScreenUPG::findFieldEx
			{
				Read1E2L1C( &csaArguments );
			}
			break;

			case 24:	// IScreenUPG::getStringEx
			{
				Read4E1C1ML( &csaArguments );
			}
			break;

			case 30:	// IScreenUPG::sendKeys
			{
				Read1E1L( &csaArguments );
			}
			break;

			// two parameters
			case 31:	// IScreenUPG::setCursor
			case 41:	// IScreenUPG::waitHostQuiet
			{
				Read2E( &csaArguments );
			}
			break;

			// three parameters
			case 4:	// IScreenUPG::findString
			case 14:	// IScreenUPG::getExtPS
			case 23:	// IScreenUPG::getString
			case 28:	// IScreenUPG::putString
			case 39:	// IScreenUPG::waitForCursor
			{
				Read3E( &csaArguments );
			}
			break;

			// four parameters
			case 40:	// IScreenUPG::waitForString
			{
				Read4E( &csaArguments );
			}
			break;


			// seven parameter
			case 5:	// IScreenUPG::findStringEx
			{
				Read5E1C1L( &csaArguments );
			}
			break;

			// eight parameters
			case 29:	// IScreenUPG::putStringEx
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
}
