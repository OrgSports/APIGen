#include "stdafx.h"
#include "APIGen.h"
#include "APIGenDlg.h"


/****************************************************************************DC
	Function	:	CAPIGenDlg::ShowITaskControls()

	Purpose		:	Show the controls for the ITask function parameters.

*****************************************************************************/
void CAPIGenDlg::ShowITaskControls( int nFunction )
{
	HideParameterControls();
	csaLabels.RemoveAll();
	BOOL bYouShouldGo=TRUE;

	switch ( nFunction )
	{
		case 0:     //ITask::addTaskListener
		case 14:     //ITask::removeTaskListener
		{
			csaLabels.Add("Task listener name");
		}
		break;



		case 1:     //ITask::cancel
		case 2:     //ITask::clearContent
		case 4:     //ITask::executeAsync
		case 5:     //ITask::executeSync
		case 6:     //ITask::getInstanceName
		case 7:     //ITask::getJobName
		case 9:     //ITask::getPreserveContext
		case 10:     //ITask::getResourceName
		case 11:     //ITask::getStatus
		case 12:     //ITask::getTimeout
		case 13:     //ITask::getVersion
		case 23:     //ScreenNativeAccess::getCharacterAttr
		case 24:     //ScreenNativeAccess::getColumns
		case 25:     //ScreenNativeAccess::getCommand
		case 26:     //ScreenNativeAccess::getCurrentPage
		case 27:     //ScreenNativeAccess::getCursorColumn
		case 28:     //ScreenNativeAccess::getCursorRow
		case 29:     //ScreenNativeAccess::getFieldAttr
		case 31:     //ScreenNativeAccess::getFieldCount
		case 32:     //ScreenNativeAccess::getFieldEndColumn
		case 34:     //ScreenNativeAccess::getFieldEndRow
		case 36:     //ScreenNativeAccess::getFieldInputText
		case 38:     //ScreenNativeAccess::getFieldLength
		case 40:     //ScreenNativeAccess::getFieldPage
		case 42:     //ScreenNativeAccess::getFieldStartColumn
		case 44:     //ScreenNativeAccess::getFieldStartRow
		case 46:     //ScreenNativeAccess::getFieldText
		case 48:     //ScreenNativeAccess::getHostFlags
		case 49:     //ScreenNativeAccess::getHostMessage
		case 50:     //ScreenNativeAccess::getHostType
		case 51:     //ScreenNativeAccess::getPageCount
		case 52:     //ScreenNativeAccess::getPoolName
		case 53:     //ScreenNativeAccess::getRows
		case 54:     //ScreenNativeAccess::getScreenName
		case 55:     //ScreenNativeAccess::getSettleTime
		case 56:     //ScreenNativeAccess::getShare
		{
		}
		break;

		case 3:     //ITask::copyContext
		case 21:     //ITask::transferContext
		{
			csaLabels.Add("Source bean");
		}
		break;

		case 15:     //ITask::setInstanceName
		{
			csaLabels.Add("Instance name");
		}
		break;

		case 16:     //ITask::setJobName
		{
			csaLabels.Add("Job name");
		}
		break;

		case 8:		//ITask::getLocale
		case 17:	//ITask::setLocale
		{
			csaLabels.Add("Locale name");
		}
		break;

		case 18:     //ITask::setPreserveContext
		{
			csaLabels.Add("Preserve context mode");
			bYouShouldGo=FALSE;
		}
		break;

		case 19:     //ITask::setResourceName
		{
			csaLabels.Add("Resource name");
		}
		break;

		case 20:     //ITask::setTimeout
		{
			csaLabels.Add("Timeout (ms)");
		}
		break;

		case 22:     //ScreenNativeAccess::doExecute
		case 58:     //ScreenNativeAccess::setConfiguration
		{
			csaLabels.Add("Server name");
		}
		break;


		case 30:     //ScreenNativeAccess::getFieldAttr 2
		case 33:     //ScreenNativeAccess::getFieldEndColumn
		case 35:     //ScreenNativeAccess::getFieldEndRow 2
		case 37:     //ScreenNativeAccess::getFieldInputText 2
		case 39:     //ScreenNativeAccess::getFieldLength 2
		case 41:     //ScreenNativeAccess::getFieldPage 2
		case 43:     //ScreenNativeAccess::getFieldStartColumn 2
		case 45:     //ScreenNativeAccess::getFieldStartRow 2
		case 47:     //ScreenNativeAccess::getFieldText 2
		{
			csaLabels.Add("Field's screen index");
		}
		break;

		case 57:     //ScreenNativeAccess::setCommand
		{
			csaLabels.Add("Command string");
		}
		break;

		case 59:     //ScreenNativeAccess::setCurrentPage
		{
			csaLabels.Add("Page number");
		}
		break;

		case 60:     //ScreenNativeAccess::setCursorColumn
		{
			csaLabels.Add("New cursor column");
		}
		break;

		case 61:     //ScreenNativeAccess::setCursorRow
		{
			csaLabels.Add("New cursor row");
		}
		break;

		case 62:     //ScreenNativeAccess::setFieldInputText
		{
			csaLabels.Add("Field index");
			csaLabels.Add("New text");
		}
		break;

		case 63:     //ScreenNativeAccess::setFieldInputText 2
		{
			csaLabels.Add("String array (csv)");
		}
		break;

		case 64:     //ScreenNativeAccess::setSettleTime
		{
			csaLabels.Add("Settle time (ms)");
		}
		break;

		case 65:     //ScreenNativeAccess::setShare
		{
			csaLabels.Add("Nav map name");
		}
		break;
	}

	if ( bYouShouldGo )
	{
		ShowEditControls( &csaLabels );
	}
	else
	{
		ShowMixedControls( ITASK_API, nFunction, &csaLabels );	
	}

}


/****************************************************************************DC
	Function	:	CAPIGenDlg::LoadITaskArgumentArray()

	Purpose		:	Load the function arguments for OLE Automation.

*****************************************************************************/
void CAPIGenDlg::LoadITaskArgumentArray( int* nFunctionPosition, BOOL bPromptForValues )
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
			case 0:     //ITask::addTaskListener
			case 3:     //ITask::copyContext
			case 8:     //ITask::getLocale
			case 14:     //ITask::removeTaskListener
			case 17:     //ITask::setLocale
			case 21:     //ITask::transferContext
			case 15:     //ITask::setInstanceName
			case 16:     //ITask::setJobName
			case 19:     //ITask::setResourceName
			case 20:     //ITask::setTimeout
			case 59:     //ScreenNativeAccess::setCurrentPage
			{
				Read1E( &csaArguments );
			}
			break;

			case 18:     //ITask::setPreserveContext
			{
				Read1L( &csaArguments );
			}
			break;


			case 1:     //ITask::cancel
			case 2:     //ITask::clearContent
			case 4:     //ITask::executeAsync
			case 5:     //ITask::executeSync
			case 6:     //ITask::getInstanceName
			case 7:     //ITask::getJobName
			case 9:     //ITask::getPreserveContext
			case 10:     //ITask::getResourceName
			case 11:     //ITask::getStatus
			case 12:     //ITask::getTimeout
			case 13:     //ITask::getVersion

			case 22:     //ScreenNativeAccess::doExecute
			case 23:     //ScreenNativeAccess::getCharacterAttr
			case 24:     //ScreenNativeAccess::getColumns
			case 25:     //ScreenNativeAccess::getCommand
			case 26:     //ScreenNativeAccess::getCurrentPage
			case 27:     //ScreenNativeAccess::getCursorColumn
			case 28:     //ScreenNativeAccess::getCursorRow
			case 29:     //ScreenNativeAccess::getFieldAttr
			case 30:     //ScreenNativeAccess::getFieldAttr 2
			case 31:     //ScreenNativeAccess::getFieldCount
			case 32:     //ScreenNativeAccess::getFieldEndColumn
			case 33:     //ScreenNativeAccess::getFieldEndColumn
			case 34:     //ScreenNativeAccess::getFieldEndRow
			case 35:     //ScreenNativeAccess::getFieldEndRow 2
			case 36:     //ScreenNativeAccess::getFieldInputText
			case 37:     //ScreenNativeAccess::getFieldInputText 2
			case 38:     //ScreenNativeAccess::getFieldLength
			case 39:     //ScreenNativeAccess::getFieldLength 2
			case 40:     //ScreenNativeAccess::getFieldPage
			case 41:     //ScreenNativeAccess::getFieldPage 2
			case 42:     //ScreenNativeAccess::getFieldStartColumn
			case 43:     //ScreenNativeAccess::getFieldStartColumn 2
			case 44:     //ScreenNativeAccess::getFieldStartRow
			case 45:     //ScreenNativeAccess::getFieldStartRow 2
			case 46:     //ScreenNativeAccess::getFieldText
			case 47:     //ScreenNativeAccess::getFieldText 2
			case 48:     //ScreenNativeAccess::getHostFlags
			case 49:     //ScreenNativeAccess::getHostMessage
			case 50:     //ScreenNativeAccess::getHostType
			case 51:     //ScreenNativeAccess::getPageCount
			case 52:     //ScreenNativeAccess::getPoolName
			case 53:     //ScreenNativeAccess::getRows
			case 54:     //ScreenNativeAccess::getScreenName
			case 55:     //ScreenNativeAccess::getSettleTime
			case 56:     //ScreenNativeAccess::getShare
			case 57:     //ScreenNativeAccess::setCommand
			case 58:     //ScreenNativeAccess::setConfiguration
			case 60:     //ScreenNativeAccess::setCursorColumn
			case 61:     //ScreenNativeAccess::setCursorRow
			case 62:     //ScreenNativeAccess::setFieldInputText
			case 63:     //ScreenNativeAccess::setFieldInputText 2
			case 64:     //ScreenNativeAccess::setSettleTime
			case 65:     //ScreenNativeAccess::setShare
			{
				csaArguments.Add( "TRUE" );
				csaArguments.Add( "TRUE" );
				csaArguments.Add( "TRUE" );
			}
			break;

				
		}
	}
	else
	{
		switch ( *nFunctionPosition )
		{
			case 0:     //ITask::addTaskListener
			case 14:     //ITask::removeTaskListener
			{
				csaArguments.Add( "itAIDKeyListener" );
			}
			break;

			case 8:     //ITask::getLocale
			case 17:     //ITask::setLocale
			{
				csaArguments.Add( "itLocaleEN" );
			}
			break;

			case 3:     //ITask::copyContext
			case 21:     //ITask::transferContext
			{
				csaArguments.Add( "bean1" );
			}
			break;

			case 15:     //ITask::setInstanceName
			{
				csaArguments.Add( "DataStoreBean" );
			}
			break;

			case 16:     //ITask::setJobName
			{
				csaArguments.Add( "Job22" );
			}
			break;

			case 19:     //ITask::setResourceName
			{
				csaArguments.Add( "Resource12" );
			}
			break;

			case 18:     //ITask::setPreserveContext
			{
				csaArguments.Add( "PRESERVE_NEVER" );
			}
			break;

			case 20:     //ITask::setTimeout
			{
				csaArguments.Add( "1001" );
			}
			break;


			case 1:     //ITask::cancel
			case 2:     //ITask::clearContent
			case 4:     //ITask::executeAsync
			case 5:     //ITask::executeSync
			case 6:     //ITask::getInstanceName
			case 7:     //ITask::getJobName
			case 9:     //ITask::getPreserveContext
			case 10:     //ITask::getResourceName
			case 11:     //ITask::getStatus
			case 12:     //ITask::getTimeout
			case 13:     //ITask::getVersion

			case 22:     //ScreenNativeAccess::doExecute
			case 23:     //ScreenNativeAccess::getCharacterAttr
			case 24:     //ScreenNativeAccess::getColumns
			case 25:     //ScreenNativeAccess::getCommand
			case 26:     //ScreenNativeAccess::getCurrentPage
			case 27:     //ScreenNativeAccess::getCursorColumn
			case 28:     //ScreenNativeAccess::getCursorRow
			case 29:     //ScreenNativeAccess::getFieldAttr
			case 30:     //ScreenNativeAccess::getFieldAttr 2
			case 31:     //ScreenNativeAccess::getFieldCount
			case 32:     //ScreenNativeAccess::getFieldEndColumn
			case 33:     //ScreenNativeAccess::getFieldEndColumn
			case 34:     //ScreenNativeAccess::getFieldEndRow
			case 35:     //ScreenNativeAccess::getFieldEndRow 2
			case 36:     //ScreenNativeAccess::getFieldInputText
			case 37:     //ScreenNativeAccess::getFieldInputText 2
			case 38:     //ScreenNativeAccess::getFieldLength
			case 39:     //ScreenNativeAccess::getFieldLength 2
			case 40:     //ScreenNativeAccess::getFieldPage
			case 41:     //ScreenNativeAccess::getFieldPage 2
			case 42:     //ScreenNativeAccess::getFieldStartColumn
			case 43:     //ScreenNativeAccess::getFieldStartColumn 2
			case 44:     //ScreenNativeAccess::getFieldStartRow
			case 45:     //ScreenNativeAccess::getFieldStartRow 2
			case 46:     //ScreenNativeAccess::getFieldText
			case 47:     //ScreenNativeAccess::getFieldText 2
			case 48:     //ScreenNativeAccess::getHostFlags
			case 49:     //ScreenNativeAccess::getHostMessage
			case 50:     //ScreenNativeAccess::getHostType
			case 51:     //ScreenNativeAccess::getPageCount
			case 52:     //ScreenNativeAccess::getPoolName
			case 53:     //ScreenNativeAccess::getRows
			case 54:     //ScreenNativeAccess::getScreenName
			case 55:     //ScreenNativeAccess::getSettleTime
			case 56:     //ScreenNativeAccess::getShare
			case 57:     //ScreenNativeAccess::setCommand
			case 58:     //ScreenNativeAccess::setConfiguration
			case 59:     //ScreenNativeAccess::setCurrentPage
			case 60:     //ScreenNativeAccess::setCursorColumn
			case 61:     //ScreenNativeAccess::setCursorRow
			case 62:     //ScreenNativeAccess::setFieldInputText
			case 63:     //ScreenNativeAccess::setFieldInputText 2
			case 64:     //ScreenNativeAccess::setSettleTime
			case 65:     //ScreenNativeAccess::setShare
			{
				csaArguments.Add( "TRUE" );
				csaArguments.Add( "TRUE" );
				csaArguments.Add( "TRUE" );
				csaArguments.Add( "TRUE" );
				csaArguments.Add( "TRUE" );
				csaArguments.Add( "TRUE" );
				csaArguments.Add( "TRUE" );
				csaArguments.Add( "TRUE" );
				csaArguments.Add( "TRUE" );
			}
			break;

				
		}
	}
}
