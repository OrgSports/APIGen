#include "stdafx.h"
#include "APIGen.h"
#include "APIGenDlg.h"



/****************************************************************************DC
	Function	:	CAPIGenDlg::ShowRFTPControls()

	Purpose		:	Show the controls for the Reflection FTP function 
					parameters.

	Note		:	

*****************************************************************************/
void CAPIGenDlg::ShowRFTPControls( int nFunction )
{
	HideParameterControls();
	csaLabels.RemoveAll();
	BOOL bYouShouldGo=TRUE;

	switch ( nFunction )
	{
		case 0:		// Close
		case 1:		// CloseDirectoryListing
		case 7:		// GetCurrentDirectory
		case 8:		// GetNextFileDetails
		case 9:		// LoadDefaultSiteProperties
		{
		}
		break;

		case 2:		// Connect
		{
			m_groupAddParameterGroup.ShowWindow( SW_SHOW  );

			csaLabels.RemoveAll();
			csaLabels.Add("Site address");
			csaLabels.Add("Server port");
			csaLabels.Add("Passive connection");
			bYouShouldGo=FALSE;
		}
		break;

		case 3:		// CreateDirectory
		{
			csaLabels.Add("Create remote directory");
		}
		break;

		case 4:		// DeleteDirectory
		{
			csaLabels.Add("Delete remote directory");
		}
		break;

		case 5:		// DeleteFile
		{
			csaLabels.Add("Delete remote file");
		}
		break;

		case 6:		// ExecuteFTPCommand
		{
			csaLabels.Add("FTP command");
		}
		break;

		case 10:	// LoadSiteProperties
		case 16:	// SaveSiteProperties
		{
			csaLabels.Add("Site name");
		}
		break;


		case 11:	// Open
		{
			csaLabels.RemoveAll();
			csaLabels.Add("Site address");
			csaLabels.Add("Username");
			csaLabels.Add("Password");
			csaLabels.Add("Account");
			csaLabels.Add("Server port");
			csaLabels.Add("Passive connection");
			bYouShouldGo=FALSE;
		}
		break;

		case 12:	// OpenDirectoryListing
		{
			csaLabels.Add("Remote file");
		}
		break;

		case 13:	// ReceiveDirectory
		case 17:	// SendDirectory
		{
			csaLabels.RemoveAll();
			csaLabels.Add("Local directory");
			csaLabels.Add("Remote directory");
			csaLabels.Add("Transfer type");
			csaLabels.Add("If file exists...");
			bYouShouldGo=FALSE;
		}
		break;


		case 14:	// ReceiveFile
		{
			csaLabels.RemoveAll();
			csaLabels.Add("Local file");
			csaLabels.Add("Remote file");
			csaLabels.Add("Transfer type");
			csaLabels.Add("If file exists");
			bYouShouldGo=FALSE;
		}
		break;

		case 15:	// RenameFile
		{
			csaLabels.Add("Remote file");
			csaLabels.Add("New name");
		}
		break;


		case 18:	// SendFile
		{
			csaLabels.RemoveAll();
			csaLabels.Add("Local file");
			csaLabels.Add("Remote file");
			csaLabels.Add("Transfer type");
			csaLabels.Add("If file exists");
			bYouShouldGo=FALSE;
		}
		break;


		case 19:	// SetCurrentDirectory
		{
			csaLabels.Add("Remote directory");
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
		ShowMixedControls( RFTP_API, nFunction, &csaLabels );	
	}

}

/****************************************************************************DC
	Function	:	CAPIGenDlg::LoadRFTPArgumentArray()

	Purpose		:	Load the function arguments for Reflection FTP

*****************************************************************************/
void CAPIGenDlg::LoadRFTPArgumentArray( int* nFunctionPosition, BOOL bPromptForValues )
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
			case 0:		// Close
			case 1:		// CloseDirectoryListing
			case 7:		// GetCurrentDirectory
			case 8:		// GetNextFileDetails
			case 9:		// LoadDefaultSiteProperties
			{
			}
			break;

			case 3:		// CreateDirectory
			case 4:		// DeleteDirectory
			case 5:		// DeleteFile
			case 6:		// ExecuteFTPCommand
			case 10:	// LoadSiteProperties
			case 12:	// OpenDirectoryListing
			case 16:	// SaveSiteProperties
			case 19:	// SetCurrentDirectory
			{
				Read1E( &csaArguments );
			}
			break;

			case 2:		// Connect
			case 15:	// RenameFile
			{
				Read2E1C( &csaArguments );
			}
			break;

			case 13:	// ReceiveDirectory
			case 17:	// SendDirectory
			case 14:	// ReceiveFile
			case 18:	// SendFile
			{
				Read2E2L( &csaArguments );
			}
			break;

			case 11:	// Open
			{
				Read5E1C( &csaArguments );
			}
			break;

		}
	}
	else
	{
		switch ( *nFunctionPosition )
		{
			case 0:		// Close
			case 1:		// CloseDirectoryListing
			case 7:		// GetCurrentDirectory
			case 8:		// GetNextFileDetails
			case 9:		// LoadDefaultSiteProperties
			{
			}
			break;

			case 2:		// Connect
			{
				// site address
				csaArguments.Add( "ftp://supportweb.com/incoming/" );

				// server port
				csaArguments.Add( "" );

				// passive mode
				csaArguments.Add( "TRUE" );

			}
			break;

			case 3:		// CreateDirectory
			case 4:		// DeleteDirectory
			{
				// remote directory
				csaArguments.Add( "results" );
			}
			break;

			case 5:		// DeleteFile
			{
				// remote file
				csaArguments.Add( "test1.txt" );
			}
			break;

			case 6:		// ExecuteFTPCommand
			{
				// command
				csaArguments.Add( "pwd" );
			}
			break;

			case 10:	// LoadSiteProperties
			{
				// site name
				csaArguments.Add( "ftp://attachmate.com/" );
			}
			break;

			case 11:	// Open
			{
				// site address
				csaArguments.Add( "ftp://support.mtsaccess@ftp.attachmate.com/incoming/" );

				// user name
				csaArguments.Add( "support" );

				// password
				csaArguments.Add( "mtsaccess" );

				// account
				csaArguments.Add( "customer" );

				// server port
				csaArguments.Add( "122" );

				// passive mode
				csaArguments.Add( "TRUE" );

			}
			break;

			case 12:	// OpenDirectoryListing
			{
				// remote file specification
				csaArguments.Add( "sales" );
			}
			break;

			case 13:	// ReceiveDirectory
			{
				// local directory
				csaArguments.Add( "c:\\userinfo" );

				// remote directory
				csaArguments.Add( "userinfo" );

				// transfer type
				csaArguments.Add( "rcAscii" );

				// if file exists
				csaArguments.Add( "rcAskUser" );
			}
			break;

			case 14:	// ReceiveFile
			{
				// local file
				csaArguments.Add( "c:\\newsales\\today.txt" );

				// remote file
				csaArguments.Add( "today.txt" );

				// transfer type
				csaArguments.Add( "rcAppend" );

				// if file exists
				csaArguments.Add( "rcAskUser" );
			}
			break;

			case 15:	// RenameFile
			{
				// remote file
				csaArguments.Add( "today.txt" );

				// new name
				csaArguments.Add( "today08112005.txt" );
			}
			break;

			case 16:	// SaveSiteProperties
			{
				// site name
				csaArguments.Add( "ftp://atmwrq.com/sales/" );
			}
			break;

			case 17:	// SendDirectory
			{
				// local directory
				csaArguments.Add( "c:\\userinfo" );

				// remote directory
				csaArguments.Add( "userinfo" );

				// transfer type
				csaArguments.Add( "rcAscii" );

				// if file exists
				csaArguments.Add( "rcAskUser" );
			}
			break;

			case 18:	// SendFile
			{
				// local file
				csaArguments.Add( "c:\\newsales\\*.sls" );

				// remote file
				csaArguments.Add( "" );

				// transfer type
				csaArguments.Add( "rcBinary" );

				// if file exists
				csaArguments.Add( "rcAppend" );
			}
			break;

			case 19:	// SetCurrentDirectory
			{
				// remote directory
				csaArguments.Add( "userinfo" );
			}
			break;



		}
	}
}

