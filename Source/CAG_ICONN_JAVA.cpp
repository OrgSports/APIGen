// Static Model
#include "stdafx.h"
#include "apigen.h"

#include "CAG_ICONN_JAVA.h"

CAG_ICONN_JAVA::CAG_ICONN_JAVA()
{
	resetVariableFlags();	
}

CAG_ICONN_JAVA::~CAG_ICONN_JAVA()
{
	
}


void CAG_ICONN_JAVA::generateHeader(CStringArray* pcsaHeader,
										 CStringArray* pcsaBody)
{

	// output to Translator's output window
	CString csViewOutStuff;
	csViewOutStuff.Format( "%s", "// *********************************************************************APIGen");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "//          Attachmate Synapta Connectors");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "//           ICONN Java Client Application");
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

	pcsaHeader->Add( "package test; ");
	pcsaHeader->Add( "");
	pcsaHeader->Add( "import com.attachmate.connectors.IConnectorAccess;");
	pcsaHeader->Add( "import com.attachmate.connectors.screen.ScreenConnectorAccessImpl;");
	pcsaHeader->Add( "");
	pcsaHeader->Add( "public class ConnectorTest");
	pcsaHeader->Add( "{");
	pcsaHeader->Add( "");
	pcsaHeader->Add( "    public static void main(String[] args)");
	pcsaHeader->Add( "    {");

	pcsaBody->Add("");
	pcsaBody->Add("           IConnectorAccess connector = new ScreenConnectorAccessImpl();");
	pcsaBody->Add("");

}



void CAG_ICONN_JAVA::appendBody(int nFunctionNum,
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
		case 0:     //IConnectionAccess::cancel
		{
			pcsaBody->Add("            connector.cancel();");
			pcsaBody->Add("");
		}
		break;

		case 1:     //IConnectionAccess::close
		{
			pcsaBody->Add("            try");
			pcsaBody->Add("            {");
			pcsaBody->Add("               connector.close();");
			pcsaBody->Add("            }");
			pcsaBody->Add("            catch (com.attachmate.connectors.ConnectorAccessException e)" );
			pcsaBody->Add("            {" );
			pcsaBody->Add("               System.out.println( e.getMessage() );");
			pcsaBody->Add("            }" );
			pcsaBody->Add("");
		}
		break;

		case 2:     //IConnectionAccess::execute
		{
			if ( !b_csTaskID )
			{
				declareVariable( AG_TASK_ID, pcsaHeader, &b_csTaskID );
			}

			if ( !b_csBuffer )
			{
				declareVariable( AG_UTILBUFFER, pcsaHeader, &b_csBuffer );
			}

			csViewOutStuff.Format( "            csTaskID = \"%s\";", pcsaArguments->GetAt(1) );
			pcsaBody->Add(csViewOutStuff);
			csViewOutStuff.Format( "            csBuffer = \"%s\";", pcsaArguments->GetAt(2) );
			pcsaBody->Add(csViewOutStuff);

			pcsaBody->Add( "" );
			pcsaBody->Add( "            try");
			pcsaBody->Add( "            {");
			pcsaBody->Add( "               connector.execute( nTaskID, csBuffer );" );
			pcsaBody->Add( "            }");
			pcsaBody->Add( "            catch (com.attachmate.connectors.ConnectorAccessException e)" );
			pcsaBody->Add( "            {" );
			pcsaBody->Add( "               System.out.println( e.getMessage() );");
			pcsaBody->Add( "            }" );
			pcsaBody->Add( "" );

		}
		break;

		case 3:     //IConnectionAccess::getAvailable
		{
			if ( !b_nBufferSize )
			{
				declareVariable( AG_BUFFER_SIZE, pcsaHeader, &b_nBufferSize );
			}

			pcsaBody->Add("            nBufferSize = connector.getAvailable();" );
			pcsaBody->Add( "" );

		}
		break;

		case 4:     //IConnectionAccess::getData
		{
			if ( !b_XMLData )
			{
				declareVariable( AG_XML_DATA, pcsaHeader, &b_XMLData );
			}

			pcsaBody->Add( "" );
			pcsaBody->Add( "            try");
			pcsaBody->Add( "            {");
			pcsaBody->Add( "               XMLData = connector.getData();" );
			pcsaBody->Add( "            }");
			pcsaBody->Add( "            catch (com.attachmate.connectors.ConnectorAccessException e)" );
			pcsaBody->Add( "            {" );
			pcsaBody->Add( "               System.out.println( e.getMessage() );");
			pcsaBody->Add( "            }" );
			pcsaBody->Add( "" );

		}
		break;

		case 5:     //IConnectionAccess::getMaxSize
		{
			if ( !b_nMaxSize )
			{
				declareVariable( AG_MAX_SIZE, pcsaHeader, &b_nMaxSize );
			}

			pcsaBody->Add( "            nMaxSize = connector.getMaxSize();" );
			pcsaBody->Add( "" );

		}
		break;

		case 6:     //IConnectionAccess::getMetaData
		{
			if ( !b_csTaskID )
			{
				declareVariable( AG_TASK_ID, pcsaHeader, &b_csTaskID );
			}

			if ( !b_csBuffer )
			{
				declareVariable( AG_UTILBUFFER, pcsaHeader, &b_csBuffer );
			}

			csViewOutStuff.Format( "            csTaskID = \"%s\";", pcsaArguments->GetAt(1) );
			pcsaBody->Add(csViewOutStuff);

			pcsaBody->Add( "" );
			pcsaBody->Add( "            try");
			pcsaBody->Add( "            {");
			pcsaBody->Add( "               csBuffer = connector.getMetaData( nTaskID );" );
			pcsaBody->Add( "            }");
			pcsaBody->Add( "            catch (com.attachmate.connectors.ConnectorAccessException e)" );
			pcsaBody->Add( "            {" );
			pcsaBody->Add( "               System.out.println( e.getMessage() );");
			pcsaBody->Add( "            }" );
			pcsaBody->Add( "" );

		}
		break;

		case 7:     //IConnectionAccess::getTimeOut
		{
			if ( !b_nTimeout )
			{
				declareVariable( AG_TIMEOUT, pcsaHeader, &b_nTimeout );
			}

			pcsaBody->Add( "            nTimeout = connector.getTimeOut();" );
			pcsaBody->Add( "" );

		}
		break;

		case 8:     //IConnectionAccess::open
		{
			if ( !b_csPath )
			{
				declareVariable( AG_PATH, pcsaHeader, &b_csPath );
			}

			if ( !b_csDataRef )
			{
				declareVariable( AG_DATA_REF, pcsaHeader, &b_csDataRef );
			}

			csViewOutStuff.Format( "            csPath = \"%s\";", pcsaArguments->GetAt(1) );
			csViewOutStuff.Replace( "\\", "\\\\" );
			pcsaBody->Add(csViewOutStuff);


			pcsaBody->Add( "" );
			pcsaBody->Add( "            try");
			pcsaBody->Add( "            {");
			pcsaBody->Add( "               csDataRef = connector.open( csPath );" );
			pcsaBody->Add( "            }");
			pcsaBody->Add( "            catch (com.attachmate.connectors.ConnectorAccessException e)" );
			pcsaBody->Add( "            {" );
			pcsaBody->Add( "               System.out.println( e.getMessage() );");
			pcsaBody->Add( "            }" );
			pcsaBody->Add( "" );

		}
		break;


		case 9:     //IConnectionAccess::setMaxSize
		{
			if ( !b_nMaxSize )
			{
				declareVariable( AG_MAX_SIZE, pcsaHeader, &b_nMaxSize );
			}

			csViewOutStuff.Format( "            nMaxSize = %s;", pcsaArguments->GetAt(1) );
			pcsaBody->Add(csViewOutStuff);

			pcsaBody->Add( "" );
			pcsaBody->Add( "            connector.setMaxSize( nMaxSize );" );
			pcsaBody->Add( "" );

		}
		break;

		case 10:     //IConnectionAccess::setTimeOut
		{
			if ( !b_nTimeout )
			{
				declareVariable( AG_TIMEOUT, pcsaHeader, &b_nTimeout );
			}

			csViewOutStuff.Format( "            nTimeout = %s;", pcsaArguments->GetAt(1) );
			pcsaBody->Add(csViewOutStuff);

			pcsaBody->Add( "" );
			pcsaBody->Add( "            connector.setTimeOut( nTimeout );" );
			pcsaBody->Add( "" );

		}
		break;

	}

	pcsaArguments->RemoveAll();
}




void CAG_ICONN_JAVA::finalize(CStringArray* pcsaBody)
{
	pcsaBody->Add( "     }" );
	pcsaBody->Add( "" );
	pcsaBody->Add( "}" );
}

void CAG_ICONN_JAVA::declareVariable(AG_VARIABLE agVariable,
										  CStringArray* pcsaHeader,
										  bool* bValue)
{
	CString csLocal;
	*bValue = TRUE;
	
	switch ( agVariable )
	{
		case AG_TASK_ID:
		{
			csLocal.Format( "            String csTaskID=\"\";");
		}
		break;

		case AG_UTILBUFFER:
		{
			csLocal.Format( "            String csBuffer=\"\";");
		}
		break;

		case AG_BUFFER_SIZE:
		{
			csLocal.Format( "            int nBufferSize=0;");
		}
		break;

		case AG_XML_DATA:
		{
			csLocal.Format( "            String XMLData=\"\";");
		}
		break;

		case AG_MAX_SIZE:
		{
			csLocal.Format( "            int nMaxSize=0;");
		}
		break;

		case AG_DATA_REF:
		{
			csLocal.Format( "            String csDataRef=\"\";");
		}
		break;

		case AG_PATH:
		{
			csLocal.Format( "            String csPath=\"\";");
		}
		break;

		case AG_TIMEOUT:
		{
			csLocal.Format( "            int nTimeout=0;");
		}
		break;

	}

	pcsaHeader->Add(csLocal);

}


void CAG_ICONN_JAVA::checkDebug( bool b_Debug, CString csFunctionName, CStringArray* pcsaBody )
{
	CString csLocal;
	
	if ( b_Debug )
	{
		csLocal.Format( "            System.out.println( \"%s\" );", csFunctionName );
		pcsaBody->Add(csLocal);
	}
}


void CAG_ICONN_JAVA::resetVariableFlags()
{
	b_csTaskID=FALSE;
	b_csBuffer=FALSE;
	b_nBufferSize=FALSE;
	b_XMLData=FALSE;
	b_nMaxSize=FALSE;
	b_nTimeout=FALSE;
	b_csDataRef=FALSE;
	b_csPath=FALSE;

	b_Debug=FALSE;
}