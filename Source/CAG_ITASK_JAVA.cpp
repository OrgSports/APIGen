// Static Model
#include "stdafx.h"
#include "apigen.h"

#include "CAG_ITASK_JAVA.h"

CAG_ITASK_JAVA::CAG_ITASK_JAVA()
{
	resetVariableFlags();
}

CAG_ITASK_JAVA::~CAG_ITASK_JAVA()
{
	
}


void CAG_ITASK_JAVA::generateHeader(CStringArray* pcsaHeader,
										 CStringArray* pcsaBody)
{

	// output to Translator's output window
	CString csViewOutStuff;
	csViewOutStuff.Format( "%s", "// *********************************************************************APIGen");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "//          Attachmate Synapta Connectors");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "//           ITask Java Client Application");
	pcsaHeader->Add(csViewOutStuff);

	time_t ltime;
	time( &ltime );

	csViewOutStuff.Format( "//");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "//   Generated:   %s", ctime( &ltime ) );
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "//");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "// ****************************************************************************");
	pcsaHeader->Add(csViewOutStuff);

	pcsaHeader->Add( "");
	pcsaHeader->Add( "import com.attachmate.connectors.IConnectorAccess;");
	pcsaHeader->Add( "import com.attachmate.connectors.screen.ScreenConnectorAccessImpl;");
	pcsaHeader->Add( "");
	pcsaHeader->Add( "public class ITaskTest");
	pcsaHeader->Add( "{");
	pcsaHeader->Add( "");
	pcsaHeader->Add( "    public static void main(String[] args)");
	pcsaHeader->Add( "    {");

	pcsaBody->Add("");
	pcsaBody->Add("           INativeAccessEx nab = new ScreenNativeAccessEx();");

}



void CAG_ITASK_JAVA::appendBody(int nFunctionNum,
									 bool bPromptForValues,
									 CStringArray* pcsaArguments,
									 CStringArray* pcsaHeader,
									 CStringArray* pcsaBody)
{
	CString csViewOutStuff;
	CString csFunctionName;

	csFunctionName = pcsaArguments->GetAt( 0 );

	if ( csFunctionName.Find( "Debug", 0 ) != -1 )
	{
		if ( b_Debug )
		{
			b_Debug = FALSE;
		}
		else
		{
			b_Debug = TRUE;
		}
	}

	pcsaBody->Add("" );

	csViewOutStuff.Format( "            // *** %s", csFunctionName );
	pcsaBody->Add(csViewOutStuff);

	checkDebug( b_Debug, csFunctionName, pcsaBody );

	CString	csLocal;

	switch ( nFunctionNum )
	{
		case 0:     //ITask::addTaskListener
		{
			CString csLocalListener = pcsaArguments->GetAt(1);
			bool	bStringFound=FALSE;
			for ( int i=0; i<csaITaskListeners.GetCount(); i++ )
			{
				if ( csLocalListener == csaITaskListeners.GetAt( i ) )
				{
					bStringFound=TRUE;
				}
			}

			if ( bStringFound )
			{
				csViewOutStuff.Format( "            delete %s;", csLocalListener );
				pcsaBody->Add(csViewOutStuff);
			}
			else
			{
				csViewOutStuff.Format( "            ITaskListener %s;", csLocalListener );
				pcsaHeader->Add(csViewOutStuff);

				// add the string
				csaITaskListeners.Add( csLocalListener );
			}

			csViewOutStuff.Format( "            %s = new ITaskListener();", csLocalListener );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "            nab.addTaskListener( %s );", csLocalListener );
			pcsaBody->Add(csViewOutStuff);
		}
		break;

		case 1:     //ITask::cancel
		{
			pcsaBody->Add( "            nab.cancel();" );
		}
		break;

		case 2:     //ITask::clearContent
		{
			pcsaBody->Add( "            try");
			pcsaBody->Add( "            {");
			pcsaBody->Add( "               nab.clearContent();" );
			pcsaBody->Add( "            }");
			pcsaBody->Add( "            catch ( ResourceInUseException e )" );
			pcsaBody->Add( "            {" );
			pcsaBody->Add( "               System.out.println( e.getMessage() );");
			pcsaBody->Add( "            }" );
		}
		break;

		case 3:     //ITask::copyContext
		{
			CString csLocalContext = pcsaArguments->GetAt(1);
			bool	bStringFound=FALSE;
			for ( int i=0; i<csaITaskContexts.GetCount(); i++ )
			{
				if ( csLocalContext == csaITaskContexts.GetAt( i ) )
				{
					bStringFound=TRUE;
				}
			}

			if ( !bStringFound )
			{
				csViewOutStuff.Format( "            ITask %s;", csLocalContext );
				pcsaHeader->Add(csViewOutStuff);

				csViewOutStuff.Format( "            %s = new ITask();", csLocalContext );
				pcsaBody->Add(csViewOutStuff);
				pcsaBody->Add( "" );

				// add the string to the list of valid listeners
				csaITaskLocales.Add( csLocalContext );
			}

			pcsaBody->Add( "            try");
			pcsaBody->Add( "            {");
			csViewOutStuff.Format( "            nab.copyContext( %s );", csLocalContext );
			pcsaBody->Add( csViewOutStuff );
			pcsaBody->Add( "            }");
			pcsaBody->Add( "            catch ( UnsupportedOperationException e )" );
			pcsaBody->Add( "            {" );
			pcsaBody->Add( "               System.out.println( e.getMessage() );");
			pcsaBody->Add( "            }" );
			pcsaBody->Add( "" );
		}
		break;

		case 4:     //ITask::executeAsync
		{
			pcsaBody->Add( "            try");
			pcsaBody->Add( "            {");
			pcsaBody->Add( "               nab.executeAsync();" );
			pcsaBody->Add( "            }");
			pcsaBody->Add( "            catch ( ResourceInUseException e )" );
			pcsaBody->Add( "            {" );
			pcsaBody->Add( "               System.out.println( e.getMessage() );");
			pcsaBody->Add( "            }" );
		}
		break;

		case 5:     //ITask::executeSync
		{
			pcsaBody->Add( "            try");
			pcsaBody->Add( "            {");
			pcsaBody->Add( "               nab.executeSync();" );
			pcsaBody->Add( "            }");
			pcsaBody->Add( "            catch ( ResourceInUseException e )" );
			pcsaBody->Add( "            {" );
			pcsaBody->Add( "               System.out.println( e.getMessage() );");
			pcsaBody->Add( "            }" );
		}
		break;

		case 6:     //ITask::getInstanceName
		{
			if ( !b_csName )
			{
				declareVariable( AG_NAME, pcsaHeader, &b_csName );
			}

			pcsaBody->Add( "            csName = nab.getInstanceName();" );
		}
		break;

		case 7:     //ITask::getJobName
		{
			if ( !b_csName )
			{
				declareVariable( AG_NAME, pcsaHeader, &b_csName );
			}

			pcsaBody->Add( "            csName = nab.getJobName();" );
		}
		break;

		case 8:     //ITask::getLocale
		{
			CString csLocalLocale = pcsaArguments->GetAt(1);
			bool	bStringFound=FALSE;
			for ( int i=0; i<csaITaskLocales.GetCount(); i++ )
			{
				if ( csLocalLocale == csaITaskLocales.GetAt( i ) )
				{
					bStringFound=TRUE;
				}
			}

			if ( !bStringFound )
			{
				csViewOutStuff.Format( "            java.util.Locale %s;", csLocalLocale );
				pcsaHeader->Add(csViewOutStuff);

				csViewOutStuff.Format( "            %s = new java.util.Locale();", csLocalLocale );
				pcsaBody->Add(csViewOutStuff);
				pcsaBody->Add( "" );

				// add the string to the list of valid listeners
				csaITaskLocales.Add( csLocalLocale );
			}

			csViewOutStuff.Format( "            %s = nab.getLocale();", csLocalLocale );
			pcsaBody->Add( csViewOutStuff );
		}
		break;

		case 9:     //ITask::getPreserveContext
		{
			if ( !b_nContext )
			{
				declareVariable( AG_CONTEXT, pcsaHeader, &b_nContext );
			}

			pcsaBody->Add( "            nContext = nab.getPreserveContext();" );
		}
		break;

		case 10:     //ITask::getResourceName
		{
			if ( !b_csResourceName )
			{
				declareVariable( AG_RESOURCE_NAME, pcsaHeader, &b_csResourceName );
			}

			pcsaBody->Add( "            csResourceName = nab.getResourceName();" );
		}
		break;

		case 11:     //ITask::getStatus
		{
			if ( !b_itStatusChangeEvent )
			{
				declareVariable( AG_STATUS_EVENT, pcsaHeader, &b_itStatusChangeEvent );
			}

			pcsaBody->Add( "            itStatusChangeEvent = new TaskStatusChangeEvent();");
			pcsaBody->Add( "" );

			pcsaBody->Add( "            itStatusChangeEvent = nab.getStatus();" );
		}
		break;

		case 12:     //ITask::getTimeout
		{
			if ( !b_lTimeout )
			{
				declareVariable( AG_TIMEOUT, pcsaHeader, &b_lTimeout );
			}

			pcsaBody->Add( "            lTimeout = nab.getTimeOut();" );
		}
		break;

		case 13:     //ITask::getVersion
		{
			if ( !b_csVersion )
			{
				declareVariable( AG_VERSION, pcsaHeader, &b_csVersion );
			}

			pcsaBody->Add( "            csVersion = nab.getVersion();" );
		}
		break;

		case 14:     //ITask::removeTaskListener
		{
			CString csLocalListener = pcsaArguments->GetAt(1);
			bool	bStringFound=FALSE;
			for ( int i=0; i<csaITaskListeners.GetCount(); i++ )
			{
				if ( csLocalListener == csaITaskListeners.GetAt( i ) )
				{
					bStringFound=TRUE;
				}
			}

			if ( !bStringFound )
			{
				csViewOutStuff.Format( "            ITaskListener %s;", csLocalListener );
				pcsaHeader->Add(csViewOutStuff);

				csViewOutStuff.Format( "            %s = new ITaskListener();", csLocalListener );
				pcsaBody->Add(csViewOutStuff);

				// add the string to the list of valid listeners
				csaITaskListeners.Add( csLocalListener );
			}

			csViewOutStuff.Format( "            nab.removeTaskListener( %s );", pcsaArguments->GetAt(1) );
			pcsaBody->Add(csViewOutStuff);
		}
		break;

		case 15:     //ITask::setInstanceName
		{
			if ( !b_csName )
			{
				declareVariable( AG_NAME, pcsaHeader, &b_csName );
			}

			csViewOutStuff.Format( "            csName = \"%s\";", pcsaArguments->GetAt(1) );
			pcsaBody->Add(csViewOutStuff);

			pcsaBody->Add( "            nab.setInstanceName( csName );" );
		}
		break;

		case 16:     //ITask::setJobName
		{
			if ( !b_csName )
			{
				declareVariable( AG_NAME, pcsaHeader, &b_csName );
			}

			csViewOutStuff.Format( "            csName = \"%s\";", pcsaArguments->GetAt(1) );
			pcsaBody->Add(csViewOutStuff);

			pcsaBody->Add( "            nab.setJobName( csName );" );
		}
		break;

		case 17:     //ITask::setLocale 
		{
			CString csLocalLocale = pcsaArguments->GetAt(1);
			bool	bStringFound=FALSE;
			for ( int i=0; i<csaITaskLocales.GetCount(); i++ )
			{
				if ( csLocalLocale == csaITaskLocales.GetAt( i ) )
				{
					bStringFound=TRUE;
				}
			}

			if ( !bStringFound )
			{
				csViewOutStuff.Format( "            java.util.Locale %s;", csLocalLocale );
				pcsaHeader->Add(csViewOutStuff);

				csViewOutStuff.Format( "            %s = new java.util.Locale();", csLocalLocale );
				pcsaBody->Add(csViewOutStuff);
				pcsaBody->Add( "" );

				// add the string to the list of valid listeners
				csaITaskLocales.Add( csLocalLocale );
			}

			csViewOutStuff.Format( "            nab.setLocale( %s );", csLocalLocale );
			pcsaBody->Add( csViewOutStuff );
		}
		break;

		case 18:     //ITask::setPreserveContext
		{
			if ( !b_nContext )
			{
				declareVariable( AG_CONTEXT, pcsaHeader, &b_nContext );
			}

			csViewOutStuff.Format( "            nContext = %s;", pcsaArguments->GetAt(1) );
			pcsaBody->Add(csViewOutStuff);
			pcsaBody->Add( "" );
			pcsaBody->Add( "            try");
			pcsaBody->Add( "            {");
			csViewOutStuff.Format( "            nab.setPreserveContext( nContext );" );
			pcsaBody->Add(csViewOutStuff);
			pcsaBody->Add( "            }");
			pcsaBody->Add( "            catch ( java.lang.IllegalArgumentException e )" );
			pcsaBody->Add( "            {" );
			pcsaBody->Add( "               System.out.println( e.getMessage() );");
			pcsaBody->Add( "            }" );
			pcsaBody->Add( "" );
		}
		break;

		case 19:     //ITask::setResourceName
		{
			if ( !b_csResourceName )
			{
				declareVariable( AG_RESOURCE_NAME, pcsaHeader, &b_csResourceName );
			}

			csViewOutStuff.Format( "            csResourceName = \"%s\";", pcsaArguments->GetAt(1) );
			pcsaBody->Add(csViewOutStuff);

			pcsaBody->Add( "" );
			pcsaBody->Add( "            nab.setResourceName( csResourceName );" );
			pcsaBody->Add( "" );
		}
		break;

		case 20:     //ITask::setTimeout
		{
			if ( !b_lTimeout )
			{
				declareVariable( AG_TIMEOUT, pcsaHeader, &b_lTimeout );
			}

			csViewOutStuff.Format( "            lTimeout = %s;", pcsaArguments->GetAt(1) );
			pcsaBody->Add(csViewOutStuff);
			pcsaBody->Add( "            nab.setTimeOut( lTimeout );" );
			pcsaBody->Add( "" );

		}
		break;

		case 21:     //ITask::transferContext
		{
			CString csLocalContext = pcsaArguments->GetAt(1);
			bool	bStringFound=FALSE;
			for ( int i=0; i<csaITaskContexts.GetCount(); i++ )
			{
				if ( csLocalContext == csaITaskContexts.GetAt( i ) )
				{
					bStringFound=TRUE;
				}
			}

			if ( !bStringFound )
			{
				csViewOutStuff.Format( "            ITask %s;", csLocalContext );
				pcsaHeader->Add(csViewOutStuff);

				csViewOutStuff.Format( "            %s = new ITask();", csLocalContext );
				pcsaBody->Add(csViewOutStuff);
				pcsaBody->Add( "" );

				// add the string to the list of valid listeners
				csaITaskLocales.Add( csLocalContext );
			}

			pcsaBody->Add( "            try");
			pcsaBody->Add( "            {");
			csViewOutStuff.Format( "               nab.transferContext( %s );", csLocalContext );
			pcsaBody->Add( csViewOutStuff );
			pcsaBody->Add( "            }");
			pcsaBody->Add( "            catch ( ResourceInUseException e )" );
			pcsaBody->Add( "            {" );
			pcsaBody->Add( "               System.out.println( e.getMessage() );");
			pcsaBody->Add( "            }" );
			pcsaBody->Add( "" );
		}
		break;

		case 59:     //ScreenNativeAccess::setCurrentPage
		{
			csViewOutStuff.Format( "               nab.setCurrentPage( %s )", pcsaArguments->GetAt(1) );
			pcsaBody->Add( csViewOutStuff );
		}
		break;


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
			csViewOutStuff.Format( "            // APIGen has not yet implemented this method." );
			pcsaBody->Add(csViewOutStuff);
		}
		break;

	}

	pcsaArguments->RemoveAll();
}




void CAG_ITASK_JAVA::finalize(CStringArray* pcsaBody)
{
	CString csViewOutStuff;

	for ( int i=0; i<csaITaskListeners.GetCount(); i++ )
	{
		csViewOutStuff.Format( "            delete %s;", csaITaskListeners.GetAt( i ) );
		pcsaBody->Add(csViewOutStuff);
	}

	pcsaBody->Add( "" );

	for ( int j=0; j<csaITaskLocales.GetCount(); j++ )
	{
		csViewOutStuff.Format( "            delete %s;", csaITaskLocales.GetAt( j ) );
		pcsaBody->Add(csViewOutStuff);
	}

	pcsaBody->Add( "" );

	for ( int k=0; k<csaITaskContexts.GetCount(); k++ )
	{
		csViewOutStuff.Format( "            delete %s;", csaITaskContexts.GetAt( k ) );
		pcsaBody->Add(csViewOutStuff);
	}

	pcsaBody->Add( "" );

	pcsaBody->Add( "" );
	pcsaBody->Add( "   } // end main" );
	pcsaBody->Add( "" );
	pcsaBody->Add( "}" );

}



void CAG_ITASK_JAVA::declareVariable(AG_VARIABLE agVariable,
										  CStringArray* pcsaHeader,
										  bool* bValue)
{
	CString csLocal;
	*bValue = TRUE;
	
	switch ( agVariable )
	{
		case AG_NAME:
		{
			csLocal.Format( "            String csName=\"\";" );
		}
		break;

		case AG_PAGE:
		{
			csLocal.Format( "            int nPageNum;" );
		}
		break;


		case AG_TASK_LISTENER:
		{
			csLocal.Format( "            ITaskListener itListener;" );
		}
		break;

		case AG_ITASK_SOURCE:
		{
			csLocal.Format( "            ITask itSource;" );
		}
		break;

		case AG_CONTEXT:
		{
			csLocal.Format( "            int nContext;" );
		}
		break;

		case AG_LOCALE:
		{
			csLocal.Format( "            Locale itLocale;" );
		}
		break;

		case AG_RESOURCE_NAME:
		{
			csLocal.Format( "            String csResourceName=\"\";" );
		}
		break;

		case AG_STATUS_EVENT:
		{
			csLocal.Format( "            TaskStatusChangeEvent itStatusChangeEvent;" );
		}
		break;

		case AG_TIMEOUT:
		{
			csLocal.Format( "            long lTimeout=0;");
		}
		break;

		case AG_VERSION:
		{
			csLocal.Format( "            String csVersion=\"\";" );
		}
		break;

		default:
		{
			csLocal.Format( "            // Declaration failed" );
		}
		break;
	}

	pcsaHeader->Add(csLocal);

}


void CAG_ITASK_JAVA::checkDebug( bool b_Debug, CString csFunctionName, CStringArray* pcsaBody )
{
	CString csLocal;
	
	if ( b_Debug )
	{
		csLocal.Format( "    System.out.println( \"%s\" );", csFunctionName );
		pcsaBody->Add(csLocal);
	}
}


void CAG_ITASK_JAVA::resetVariableFlags()
{
	b_itListener=FALSE;
	b_itSource=FALSE;
	b_csName=FALSE;
	b_itLocale=FALSE;
	b_nContext=FALSE;
	b_csResourceName=FALSE;
	b_itStatusChangeEvent=FALSE;
	b_csVersion=FALSE;
	b_lTimeout=FALSE;
	b_nPageNum=FALSE;

	b_Debug=FALSE;
}