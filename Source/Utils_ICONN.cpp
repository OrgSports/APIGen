#include "stdafx.h"
#include "APIGen.h"
#include "APIGenDlg.h"



/****************************************************************************DC
	Function	:	CAPIGenDlg::ShowICONNControls()

	Purpose		:	Show the controls for the ITask function parameters.

*****************************************************************************/
void CAPIGenDlg::ShowICONNControls( int nFunction )
{
	HideParameterControls();
	csaLabels.RemoveAll();
	BOOL bYouShouldGo=TRUE;

	switch ( nFunction )
	{
		case 0:     //IConnectionAccess::cancel
		case 1:     //IConnectionAccess::close
		case 3:     //IConnectionAccess::getAvailable
		case 4:     //IConnectionAccess::getData
		case 5:     //IConnectionAccess::getMaxSize
		case 7:     //IConnectionAccess::getTimeOut
		{
		}
		break;

		case 2:     //IConnectionAccess::execute
		{
			csaLabels.Add("Task ID");
			csaLabels.Add("Input strings (csv)");
		}
		break;

		case 6:     //IConnectionAccess::getMetaData
		{
			csaLabels.Add("Task ID");
		}
		break;

		case 8:     //IConnectionAccess::open
		{
			csaLabels.Add("Path");
		}
		break;

		case 9:     //IConnectionAccess::setMaxSize
		{
			csaLabels.Add("Maximum data size");
		}
		break;

		case 10:     //IConnectionAccess::setTimeOut
		{
			csaLabels.Add("Timeout period (secs)");
		}
		break;

	}

	if ( bYouShouldGo )
	{
		ShowEditControls( &csaLabels );
	}
	else
	{
		ShowMixedControls( ICONN_API, nFunction, &csaLabels );	
	}


}


/****************************************************************************DC
	Function	:	CAPIGenDlg::LoadICONNArgumentArray()

	Purpose		:	Load the function arguments for OLE Automation.

*****************************************************************************/
void CAPIGenDlg::LoadICONNArgumentArray( int* nFunctionPosition, BOOL bPromptForValues )
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
			case 0:     //IConnectionAccess::cancel
			case 1:     //IConnectionAccess::close
			case 3:     //IConnectionAccess::getAvailable
			case 4:     //IConnectionAccess::getData
			case 5:     //IConnectionAccess::getMaxSize
			case 7:     //IConnectionAccess::getTimeOut
			{
			}
			break;

			case 2:     //IConnectionAccess::execute
			{
				Read2E( &csaArguments );
			}
			break;

			case 6:     //IConnectionAccess::getMetaData
			case 8:     //IConnectionAccess::open
			case 9:     //IConnectionAccess::setMaxSize
			case 10:     //IConnectionAccess::setTimeOut
			{
				Read1E( &csaArguments );
			}
			break;
			
		}
	}
	else
	{
		switch ( *nFunctionPosition )
		{
			case 0:     //IConnectionAccess::cancel
			case 1:     //IConnectionAccess::close
			case 3:     //IConnectionAccess::getAvailable
			case 4:     //IConnectionAccess::getData
			case 5:     //IConnectionAccess::getMaxSize
			case 7:     //IConnectionAccess::getTimeOut
			{
			}
			break;

			case 2:     //IConnectionAccess::execute
			{
				csaArguments.Add( "Task23" );
				csaArguments.Add( "a,b,c" );
			}
			break;

			case 6:     //IConnectionAccess::getMetaData
			{
				csaArguments.Add( "Task23" );
			}
			break;

			case 8:     //IConnectionAccess::open
			{
				csaArguments.Add( "Path137" );
			}
			break;

			case 9:     //IConnectionAccess::setMaxSize
			{
				csaArguments.Add( "1024" );
			}
			break;

			case 10:	//IConnectionAccess::setTimeOut
			{
				csaArguments.Add( "2000" );
			}
			break;
			
		}
	}

}


