#include "stdafx.h"
#include "APIGen.h"
#include "APIGenDlg.h"



/****************************************************************************DC
	Function	:	CAPIGenDlg::ShowPerforceControls()

	Purpose		:	Show the controls for the Perforce P4 command parameters.

	Note		:	

*****************************************************************************/
void CAPIGenDlg::ShowPerforceControls( int nFunction )
{
	HideParameterControls();
	csaLabels.RemoveAll();
	BOOL bYouShouldGo=TRUE;

	switch ( nFunction )
	{
		case 0:   // add
		{
			csaLabels.Add("[Global options]");
			csaLabels.Add("[Changelist]");
			csaLabels.Add("[Filetype]");
			csaLabels.Add("[Filetype modifier]");
			csaLabels.Add("[Interpret wildcards]");
			csaLabels.Add("Filename(s)");
			bYouShouldGo=FALSE;
		}
		break;

		case 4:   // branches
		case 10:   // clients
		case 12:   // counters
		case 15:   // depots
		case 61:   // tickets
		case 70:   // workspaces
		{
			csaLabels.Add("[Global options]");
			bYouShouldGo=FALSE;
		}
		break;

		case 1:   // admin
		{
			csaLabels.Add("[Global options]");
			csaLabels.Add("Action");
			csaLabels.Add("[Save compressed]");
			csaLabels.Add("[Prefix]");
			bYouShouldGo=FALSE;
		}
		break;


		case 2:   // annotate
		case 3:   // branch
		case 5:   // change
		case 6:   // changelists
		case 7:   // changelist
		case 8:   // changes
		case 9:   // client
		case 11:   // counter
		case 13:   // delete
		case 14:   // depot
		case 16:   // describe
		case 17:   // diff
		case 18:   // diff2
		case 19:   // dirs
		case 20:   // edit
		case 21:   // filelog
		case 22:   // files
		case 23:   // fix
		case 24:   // fixes
		case 25:   // flush
		case 26:   // fstat
		case 27:   // group
		case 28:   // groups
		case 29:   // have
		case 30:   // help
		case 31:   // info
		case 32:   // integrate
		case 33:   // integrated
		case 34:   // job
		case 35:   // jobs
		case 36:   // jobspec
		case 37:   // label
		case 38:   // labels
		case 39:   // labelsync
		case 40:   // lock
		case 41:   // logger
		case 42:   // login
		case 43:   // logout
		case 44:   // monitor
		case 45:   // obliterate
		case 46:   // opened
		case 47:   // passwd
		case 48:   // print
		case 49:   // protect
		case 50:   // rename
		case 51:   // reopen
		case 52:   // resolve
		case 53:   // resolved
		case 54:   // revert
		case 55:   // review
		case 56:   // reviews
		case 57:   // set
		case 58:   // submit
		case 59:   // sync
		case 60:   // tag
		case 62:   // triggers
		case 63:   // typemap
		case 64:   // unlock
		case 65:   // user
		case 66:   // users
		case 67:   // verify
		case 68:   // where
		case 69:   // workspace
		{
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
		ShowMixedControls( PERFORCE_API, nFunction, &csaLabels );	
	}

}




/****************************************************************************DC
	Function	:	CAPIGenDlg::LoadPerforceArgumentArray()

	Purpose		:	Load the function arguments for Perforce P4 commands

*****************************************************************************/
void CAPIGenDlg::LoadPerforceArgumentArray( int* nFunction, BOOL bPromptForValues )
{
	CString	csFunctionName, csFunctionNum;
	
	UpdateData();
	
	*nFunction=0;

	*nFunction = m_listTranslateFunction.GetCurSel();
	m_listTranslateFunction.GetText( *nFunction, csFunctionName );

	// full function name text
	csaArguments.Add( csFunctionName );


	if ( bPromptForValues )
	{
		switch ( *nFunction )
		{
			case 0:   // add
			{
				Read1C1E1L1ML1C1E( &csaArguments );
			}
			break;

			case 1:   // admin
			{
				Read1C1L1C1E( &csaArguments );
			}
			break;

			case 4:   // branches
			case 10:   // clients
			case 12:   // counters
			case 15:   // depots
			case 61:   // tickets
			case 70:   // workspaces
			{
				Read1C( &csaArguments );
			}
			break;

			case 2:   // annotate
			case 3:   // branch
			case 5:   // change
			case 6:   // changelists
			case 7:   // changelist
			case 8:   // changes
			case 9:   // client
			case 11:   // counter
			case 13:   // delete
			case 14:   // depot
			case 16:   // describe
			case 17:   // diff
			case 18:   // diff2
			case 19:   // dirs
			case 20:   // edit
			case 21:   // filelog
			case 22:   // files
			case 23:   // fix
			case 24:   // fixes
			case 25:   // flush
			case 26:   // fstat
			case 27:   // group
			case 28:   // groups
			case 29:   // have
			case 30:   // help
			case 31:   // info
			case 32:   // integrate
			case 33:   // integrated
			case 34:   // job
			case 35:   // jobs
			case 36:   // jobspec
			case 37:   // label
			case 38:   // labels
			case 39:   // labelsync
			case 40:   // lock
			case 41:   // logger
			case 42:   // login
			case 43:   // logout
			case 44:   // monitor
			case 45:   // obliterate
			case 46:   // opened
			case 47:   // passwd
			case 48:   // print
			case 49:   // protect
			case 50:   // rename
			case 51:   // reopen
			case 52:   // resolve
			case 53:   // resolved
			case 54:   // revert
			case 55:   // review
			case 56:   // reviews
			case 57:   // set
			case 58:   // submit
			case 59:   // sync
			case 60:   // tag
			case 62:   // triggers
			case 63:   // typemap
			case 64:   // unlock
			case 65:   // user
			case 66:   // users
			case 67:   // verify
			case 68:   // where
			case 69:   // workspace
			{
				csaArguments.Add( "a" );
				csaArguments.Add( "b" );
				csaArguments.Add( "c" );
				csaArguments.Add( "d" );
				csaArguments.Add( "e" );
			}
			break;

			default:
			{
				m_groupNoParametersNeeded.ShowWindow( SW_SHOW  );
			}
		}

	}
	else
	{
		switch ( *nFunction )
		{
			Read1C1E1L1ML1C1E( &csaArguments );
	
			case 0:   // add
			{
				csaArguments.Add( "FALSE" );
				csaArguments.Add( "13" );
				csaArguments.Add( "unicode" );
				csaArguments.Add( "RCS keyword expansion" );
				csaArguments.Add( "TRUE" );
				csaArguments.Add( "File137" );
			}
			break;

			case 1:   // admin
			{
				csaArguments.Add( "checkpoint" );
				csaArguments.Add( "TRUE" );
				csaArguments.Add( "W05" );
			}
			break;

			case 4:   // branches
			case 10:   // clients
			case 12:   // counters
			case 15:   // depots
			case 61:   // tickets
			case 70:   // workspaces
			{
				csaArguments.Add( "FALSE" );
			}
			break;

			case 2:   // annotate
			case 3:   // branch
			case 5:   // change
			case 6:   // changelists
			case 7:   // changelist
			case 8:   // changes
			case 9:   // client
			case 11:   // counter
			case 13:   // delete
			case 14:   // depot
			case 16:   // describe
			case 17:   // diff
			case 18:   // diff2
			case 19:   // dirs
			case 20:   // edit
			case 21:   // filelog
			case 22:   // files
			case 23:   // fix
			case 24:   // fixes
			case 25:   // flush
			case 26:   // fstat
			case 27:   // group
			case 28:   // groups
			case 29:   // have
			case 30:   // help
			case 31:   // info
			case 32:   // integrate
			case 33:   // integrated
			case 34:   // job
			case 35:   // jobs
			case 36:   // jobspec
			case 37:   // label
			case 38:   // labels
			case 39:   // labelsync
			case 40:   // lock
			case 41:   // logger
			case 42:   // login
			case 43:   // logout
			case 44:   // monitor
			case 45:   // obliterate
			case 46:   // opened
			case 47:   // passwd
			case 48:   // print
			case 49:   // protect
			case 50:   // rename
			case 51:   // reopen
			case 52:   // resolve
			case 53:   // resolved
			case 54:   // revert
			case 55:   // review
			case 56:   // reviews
			case 57:   // set
			case 58:   // submit
			case 59:   // sync
			case 60:   // tag
			case 62:   // triggers
			case 63:   // typemap
			case 64:   // unlock
			case 65:   // user
			case 66:   // users
			case 67:   // verify
			case 68:   // where
			case 69:   // workspace
			{
				csaArguments.Add( "a" );
				csaArguments.Add( "b" );
				csaArguments.Add( "c" );
				csaArguments.Add( "d" );
				csaArguments.Add( "e" );
			}
			break;

			default:
			{
				m_groupNoParametersNeeded.ShowWindow( SW_SHOW  );
			}
		}

	}

}

