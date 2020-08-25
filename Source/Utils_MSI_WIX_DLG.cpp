#include "stdafx.h"
#include "APIGen.h"
#include "APIGenDlg.h"



/****************************************************************************DC
	Function	:	CAPIGenDlg::ShowWIXDlgControls()

	Purpose		:	Show the controls for the MSI Database function parameters.

*****************************************************************************/
void CAPIGenDlg::ShowWIXDlgControls( int nFunction )
{
	HideParameterControls();
	csaLabels.RemoveAll();
	BOOL bYouShouldGo=TRUE;

	switch ( nFunction )
	{
		case 0:     //Bitmap
		{
			csaLabels.Add( "Bitmap file" );
			csaLabels.Add( "Bitmap ID" );
			bYouShouldGo=FALSE;
		}
		break;

		case 1:     //Control label
		{
			csaLabels.Add( "Label ID" );
			csaLabels.Add( "Text" );
			csaLabels.Add( "X-position" );
			csaLabels.Add( "Y-position" );
			csaLabels.Add( "Width (pixels)" );
		}
		break;

		case 2:     //Edit control
		case 4:     //Masked edit control
		{
			csaLabels.Add( "Control ID" );
			csaLabels.Add( "Property name" );
			csaLabels.Add( "Text" );
			csaLabels.Add( "X-position" );
			csaLabels.Add( "Y-position" );
			csaLabels.Add( "Width (pixels)" );
		}
		break;

		case 3:     //Line
		{
			csaLabels.Add( "Control ID" );
			csaLabels.Add( "X-position" );
			csaLabels.Add( "Y-position" );
			csaLabels.Add( "Length (pixels)" );
		}
		break;

		case 5:     //Pushbutton
		{
			csaLabels.Add( "Button ID" );
			csaLabels.Add( "Text" );
			csaLabels.Add( "Event" );
			csaLabels.Add( "Event value" );
			csaLabels.Add( "Initial value" );
			csaLabels.Add( "X-position" );
			csaLabels.Add( "Y-position" );
			csaLabels.Add( "Width (pixels)" );
		}
		break;

		case 6:     //Pushbutton - 2 actions
		{
			csaLabels.Add( "Button ID" );
			csaLabels.Add( "Text" );
			csaLabels.Add( "Event" );
			csaLabels.Add( "Event value" );
			csaLabels.Add( "Initial value" );
			csaLabels.Add( "X-position" );
			csaLabels.Add( "Y-position" );
			csaLabels.Add( "Width (pixels)" );
		}
		break;

		case 7:     //Pushbutton - 3 actions
		{
			csaLabels.Add( "Button ID" );
			csaLabels.Add( "Text" );
			csaLabels.Add( "Event" );
			csaLabels.Add( "Event value" );
			csaLabels.Add( "Initial value" );
			csaLabels.Add( "X-position" );
			csaLabels.Add( "Y-position" );
			csaLabels.Add( "Width (pixels)" );
		}
		break;

		default:
		{

		}
		break;

	}

	if ( bYouShouldGo )
	{
		ShowEditControls( &csaLabels );
	}
	else
	{
		ShowMixedControls( MSI_WIXDLG_API, nFunction, &csaLabels );	
	}


}


/****************************************************************************DC
	Function	:	CAPIGenDlg::LoadWIXDlgArgumentArray()

	Purpose		:	Load the function arguments for OLE Automation.

*****************************************************************************/
void CAPIGenDlg::LoadWIXDlgArgumentArray( int* nFunctionPosition, BOOL bPromptForValues )
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
			case 0:     //Bitmap
			{
				Read2E( &csaArguments );
			}
			break;

			case 1:     //Control label
			{
				Read5E( &csaArguments );
			}
			break;

			case 2:     //Edit control
			case 4:     //Masked edit control
			{
				Read6E( &csaArguments );
			}
			break;

			case 3:     //Line
			{
				Read4E( &csaArguments );
			}
			break;

			case 5:     //Pushbutton - one action
			{
				Read8E( &csaArguments );
			}
			break;

			case 6:     //Pushbutton - two actions
			{
				Read9E( &csaArguments );
			}
			break;

			case 7:     //Pushbutton - three actions
			{
				Read10E( &csaArguments );
			}
			break;


		}

	}
	else
	{
		switch ( *nFunctionPosition )
		{
			case 0:     //MsiAdvertiseProduct
			{
				csaArguments.Add( "c:\\temp\\packages" );
				csaArguments.Add( "c:\\temp\\scripts" );
				csaArguments.Add( "FALSE" );
				csaArguments.Add( "TRUE" );
				csaArguments.Add( "Transform24" );
				csaArguments.Add( "English" );
			}
			break;

			case 1:     //MsiAdvertiseProductEx
			{
				csaArguments.Add( "c:\\temp\\packages" );
				csaArguments.Add( "c:\\temp\\scripts" );
				csaArguments.Add( "FALSE" );
				csaArguments.Add( "TRUE" );
				csaArguments.Add( "Transform24" );
				csaArguments.Add( "English" );
				csaArguments.Add( "1" );
				csaArguments.Add( "1" );
			}
			break;

			case 2:     //MsiAdvertiseScript
			{
				csaArguments.Add( "c:\\scripts\\script1.sh" );
				csaArguments.Add( "SCRIPTFLAGS_SHORTCUTS" );
				csaArguments.Add( "HKLM\\SOFTWARE\\Attachmate\\RWeb" );
				csaArguments.Add( "TRUE" );
			}
			break;

			case 5:     //MsiCloseHandle
			{
				csaArguments.Add( "hCurrentInstall" );
			}
			break;

			case 17:     //MsiEnumFeatures
			{
				csaArguments.Add( "{ECF246DF-E871-11D2-8CC2-00C04F72C0ED}" );
				csaArguments.Add( "0" );
			}
			break;


			case 43:     //MsiGetProperty
			{
				csaArguments.Add( "TRACEPROPERTY" );
			}
			break;

			case 53:     //MsiProcessMessage
			{
				csaArguments.Add( "INSTALLMESSAGE_OUTOFDISKSPACE" );
			}
			break;

			case 79:     //MsiSetProperty
			{
				csaArguments.Add( "PIDKEY" );
				csaArguments.Add( "123-451" );
			}
			break;


			case 3:     //MsiApplyMultiplePatches
			case 4:     //MsiCloseAllHandles
			case 6:     //MsiCreateRecord
			case 7:     //MsiDatabaseGetPrimaryKeys
			case 8:     //MsiDatabaseIsTablePersistent
			case 9:     //MsiDatabaseOpenView
			case 10:     //MsiDetermineApplicablePatches
			{
			}
			break;

		}
	}

}


