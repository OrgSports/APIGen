#include "stdafx.h"
#include "APIGen.h"
#include "APIGenDlg.h"



/****************************************************************************DC
	Function	:	CAPIGenDlg::ShowMSISummaryControls()

	Purpose		:	Show the controls for the MSI Summary Info function parameters.

*****************************************************************************/
void CAPIGenDlg::ShowMSISummaryControls( int nFunction )
{
	HideParameterControls();
	csaLabels.RemoveAll();
	BOOL bYouShouldGo=TRUE;

	switch ( nFunction )
	{
		case 0:		//Platform/Language
		{
			csaLabels.Add( "Platform/Language" );
			bYouShouldGo=FALSE;
		}
		break;

		case 1:		//Revision number
		{
			csaLabels.Add( "Package GUID" );
		}
		break;

		case 2:		//Page count
		{
			csaLabels.Add( "Installer version" );
			bYouShouldGo=FALSE;
		}
		break;

		case 3:		//Word count
		{
			csaLabels.Add( "Long filenames (vs short)" );
			csaLabels.Add( "Compressed files (vs not)" );
			csaLabels.Add( "Original media (vs admin)" );
			bYouShouldGo=FALSE;
		}
		break;

		case 4:		//Title
		{
			csaLabels.Add( "Title" );
		}
		break;

		case 5:		//Subject
		{
			csaLabels.Add( "Subject" );
		}
		break;

		case 6:		//Keywords
		{
			csaLabels.Add( "[Keyword {,Keyword}]" );
		}
		break;

		case 7:		//Author
		{
			csaLabels.Add( "Author" );
		}
		break;

		case 8:		//Comments
		{
			csaLabels.Add( "Comments" );
		}
		break;

		case 9:		//Creating app
		{
			csaLabels.Add( "Creating app (e.g. Orca)" );
		}
		break;

		case 10:	//Security
		{
			csaLabels.Add( "Security" );
			bYouShouldGo=FALSE;
		}
		break;


		case 11:	//Last saved by
		{
			csaLabels.Add( "Last saved by" );
		}
		break;

		case 12:	//Last saved time/date
		{
			csaLabels.Add( "Last saved time/date" );
		}
		break;

		case 13:	//Create time/date
		{
			csaLabels.Add( "Create time/date" );
		}
		break;

		case 14:	//Last printed
		{
			csaLabels.Add( "Last printed" );
		}
		break;

		case 15:	//Character count
		{
			csaLabels.Add( "Character count" );
		}
		break;

		case 16:	//Codepage
		{
			csaLabels.Add( "Codepage" );
		}
		break;


	}

	if ( bYouShouldGo )
	{
		ShowEditControls( &csaLabels );
	}
	else
	{
		ShowMixedControls( MSI_SUMMARY_API, nFunction, &csaLabels );	
	}


}


/****************************************************************************DC
	Function	:	CAPIGenDlg::LoadMSISummaryArgumentArray()

	Purpose		:	Load the function arguments for OLE Automation.

*****************************************************************************/
void CAPIGenDlg::LoadMSISummaryArgumentArray( int* nFunctionPosition, BOOL bPromptForValues )
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
			case 0:		//Platform/Language
			{
				Read1L(&csaArguments);
			}
			break;

			case 1:		//Revision number
			{
				Read1E(&csaArguments);
			}
			break;

			case 2:		//Page count
			{
				Read1L(&csaArguments);
			}
			break;

			case 3:		//Word count
			{
				Read3C(&csaArguments);
			}
			break;

			case 4:		//Title
			case 5:		//Subject
			case 6:		//Keywords
			case 7:		//Author
			case 8:		//Comments
			case 9:		//Creating app
			{
				Read1E(&csaArguments);
			}
			break;

			case 10:	//Security
			case 11:	//Last saved by
			case 12:	//Last saved time/date
			case 13:	//Create time/date
			case 14:	//Last printed
			case 15:	//Character count
			case 16:	//Codepage
			{
			}
			break;
		}
	}
	else
	{
		switch ( *nFunctionPosition )
		{
			case 0:		//Platform/Language
			{
				csaArguments.Add( "4" );
			}
			break;

			case 1:		//Revision number
			{
				csaArguments.Add( "{4966AEC4-3C59-4B07-9B98-1B6A7103C0D3}" );
			}
			break;

			case 2:		//Page count
			{
				csaArguments.Add( "1.1" );
			}
			break;

			case 3:		//Word count
			{
				csaArguments.Add( "TRUE" );
				csaArguments.Add( "FALSE" );
				csaArguments.Add( "FALSE" );
			}
			break;

			case 4:		//Title
			{
				csaArguments.Add( "Sub Transform" );
			}
			break;

			case 5:		//Subject
			{
				csaArguments.Add( "Red Park" );
			}
			break;

			case 6:		//Keywords
			{
				csaArguments.Add( "Installer, Holidays" );
			}
			break;

			case 7:		//Author
			{
				csaArguments.Add( "Red Green" );
			}
			break;

			case 8:		//Comments
			{
				csaArguments.Add( "Activity Calendar" );
			}
			break;

			case 9:		//Creating app
			{
				csaArguments.Add( "Orca" );
			}
			break;

			case 10:	//Security
			case 11:	//Last saved by
			case 12:	//Last saved time/date
			case 13:	//Create time/date
			case 14:	//Last printed
			case 15:	//Character count
			case 16:	//Codepage
			{
			}
			break;

		}
	}

}


