// Static Model
#include "stdafx.h"
#include "apigen.h"

#include "CAG_ICONN_ASP.h"

CAG_ICONN_ASP::CAG_ICONN_ASP()
{
	resetVariableFlags();	
}

CAG_ICONN_ASP::~CAG_ICONN_ASP()
{
	
}


void CAG_ICONN_ASP::generateHeader(CStringArray* pcsaHeader,
										 CStringArray* pcsaBody)
{

	// output to Translator's output window
	CString csViewOutStuff;
	pcsaHeader->Add("<%@ Language=VBScript %>");

	pcsaHeader->Add("' *********************************************************************APIGen");
	pcsaHeader->Add("'          Attachmate Synapta Connectors");
	pcsaHeader->Add("'           ICONN ASP Client Application");
	pcsaHeader->Add("' ");
	pcsaHeader->Add("'  This file is a program that features the use of the Attachmate");
	pcsaHeader->Add("'  Synapta IConnectorAccess API written in ASP and VBScript.  You can set up the");
	pcsaHeader->Add("'  running environment and run the application by following these instructions:");
	pcsaHeader->Add("'     1. What product / componentes must be installed?  If it is important, where must");
	pcsaHeader->Add("'        this file be placed and how should it be launched?");
	pcsaHeader->Add("'     2. ");
	pcsaHeader->Add("'        ");

	time_t ltime;
	time( &ltime );

	pcsaHeader->Add( "'" );
	csViewOutStuff.Format( "'   Generated:   %s", ctime( &ltime ) );
	pcsaHeader->Add(csViewOutStuff);
	pcsaHeader->Add( "'" );
	pcsaHeader->Add( "'" );
	pcsaHeader->Add( "' ****************************************************************************");

	pcsaHeader->Add("<HTML>");
	pcsaHeader->Add("<HEAD>");
	pcsaHeader->Add("</HEAD>");
	pcsaHeader->Add("<BODY>");
	pcsaHeader->Add("<PRE>");
	pcsaHeader->Add("<%");

	pcsaHeader->Add( "" );
	pcsaHeader->Add( "Response.Buffer = true");
	pcsaHeader->Add( "On Error Resume Next");
	pcsaHeader->Add( "" );
	pcsaHeader->Add( "Dim connector");

	pcsaBody->Add("");
	pcsaBody->Add( "Set connector = CreateObject(\"Atm.ScreenConnector.1\")");
	pcsaBody->Add("");
	pcsaBody->Add( "");
	pcsaBody->Add( "   if Err.number <> 0 then" );
	pcsaBody->Add( "       Response.Write \"Error in CreateObject\"" );
	pcsaBody->Add( "       Response.Write \"Return Code = \" & Err.number & \"<BR>\"" );
	pcsaBody->Add( "   else" );
	pcsaBody->Add( "       Response.Write \"Successful CreateObject \" & \"<BR>\"" );
	pcsaBody->Add( "   end if" );
	pcsaBody->Add( "");

}



void CAG_ICONN_ASP::appendBody(int nFunctionNum,
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
	else
	{

		pcsaBody->Add("" );

		csViewOutStuff.Format( "'   *** %s", csFunctionName );
		pcsaBody->Add(csViewOutStuff);

		checkDebug( b_Debug, csFunctionName, pcsaBody );

		CString	csLocal;

		switch ( nFunctionNum )
		{
			case 0:     //IConnectionAccess::cancel
			{
				pcsaBody->Add("   connector.cancel");
				pcsaBody->Add("");
			}
			break;

			case 1:     //IConnectionAccess::close
			{
				pcsaBody->Add("   try");
				pcsaBody->Add("   {");
				pcsaBody->Add("      connector.close");
				pcsaBody->Add("   }");
				pcsaBody->Add("   catch (com.attachmate.connectors.ConnectorAccessException e)" );
				pcsaBody->Add("   {" );
				pcsaBody->Add("      MsgBox e.getMessage");
				pcsaBody->Add("   }" );
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

				csViewOutStuff.Format( "   csTaskID = \"%s\"", pcsaArguments->GetAt(1) );
				pcsaBody->Add(csViewOutStuff);
				csViewOutStuff.Format( "   csBuffer = \"%s\"", pcsaArguments->GetAt(2) );
				pcsaBody->Add(csViewOutStuff);

				pcsaBody->Add( "" );
				pcsaBody->Add( "   try");
				pcsaBody->Add( "   {");
				pcsaBody->Add( "      connector.execute nTaskID, csBuffer" );
				pcsaBody->Add( "   }");
				pcsaBody->Add( "   catch (com.attachmate.connectors.ConnectorAccessException e)" );
				pcsaBody->Add( "   {" );
				pcsaBody->Add( "      System.out.println( e.getMessage() );");
				pcsaBody->Add( "   }" );
				pcsaBody->Add( "" );

			}
			break;

			case 3:     //IConnectionAccess::getAvailable
			{
				if ( !b_nBufferSize )
				{
					declareVariable( AG_BUFFER_SIZE, pcsaHeader, &b_nBufferSize );
				}

				pcsaBody->Add("   nBufferSize = connector.getAvailable()" );
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
				pcsaBody->Add( "   try");
				pcsaBody->Add( "   {");
				pcsaBody->Add( "      XMLData = connector.getData()" );
				pcsaBody->Add( "   }");
				pcsaBody->Add( "   catch (com.attachmate.connectors.ConnectorAccessException e)" );
				pcsaBody->Add( "   {" );
				pcsaBody->Add( "      System.out.println( e.getMessage() );");
				pcsaBody->Add( "   }" );
				pcsaBody->Add( "" );

			}
			break;

			case 5:     //IConnectionAccess::getMaxSize
			{
				if ( !b_nMaxSize )
				{
					declareVariable( AG_MAX_SIZE, pcsaHeader, &b_nMaxSize );
				}

				pcsaBody->Add( "   nMaxSize = connector.getMaxSize()" );
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

				csViewOutStuff.Format( "   csTaskID = \"%s\"", pcsaArguments->GetAt(1) );
				pcsaBody->Add(csViewOutStuff);

				pcsaBody->Add( "" );
				pcsaBody->Add( "   try");
				pcsaBody->Add( "   {");
				pcsaBody->Add( "      csBuffer = connector.getMetaData( nTaskID )" );
				pcsaBody->Add( "   }");
				pcsaBody->Add( "   catch (com.attachmate.connectors.ConnectorAccessException e)" );
				pcsaBody->Add( "   {" );
				pcsaBody->Add( "      System.out.println( e.getMessage() );");
				pcsaBody->Add( "   }" );
				pcsaBody->Add( "" );

			}
			break;

			case 7:     //IConnectionAccess::getTimeOut
			{
				if ( !b_nTimeout )
				{
					declareVariable( AG_TIMEOUT, pcsaHeader, &b_nTimeout );
				}

				pcsaBody->Add( "   nTimeout = connector.getTimeOut()" );
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

				csViewOutStuff.Format( "   csPath = \"%s\"", pcsaArguments->GetAt(1) );
				pcsaBody->Add(csViewOutStuff);


				pcsaBody->Add( "" );
				pcsaBody->Add( "   try");
				pcsaBody->Add( "   {");
				pcsaBody->Add( "      csDataRef = connector.open( csPath )" );
				pcsaBody->Add( "   }");
				pcsaBody->Add( "   catch (com.attachmate.connectors.ConnectorAccessException e)" );
				pcsaBody->Add( "   {" );
				pcsaBody->Add( "      System.out.println( e.getMessage() );");
				pcsaBody->Add( "   }" );
				pcsaBody->Add( "" );

			}
			break;


			case 9:     //IConnectionAccess::setMaxSize
			{
				if ( !b_nMaxSize )
				{
					declareVariable( AG_MAX_SIZE, pcsaHeader, &b_nMaxSize );
				}

				csViewOutStuff.Format( "   nMaxSize = %s", pcsaArguments->GetAt(1) );
				pcsaBody->Add(csViewOutStuff);

				pcsaBody->Add( "" );
				pcsaBody->Add( "   connector.setMaxSize nMaxSize" );
				pcsaBody->Add( "" );

			}
			break;

			case 10:     //IConnectionAccess::setTimeOut
			{
				if ( !b_nTimeout )
				{
					declareVariable( AG_TIMEOUT, pcsaHeader, &b_nTimeout );
				}

				csViewOutStuff.Format( "   nTimeout = %s", pcsaArguments->GetAt(1) );
				pcsaBody->Add(csViewOutStuff);

				pcsaBody->Add( "" );
				pcsaBody->Add( "   connector.setTimeOut nTimeout" );
				pcsaBody->Add( "" );

			}
			break;


			case 11:	//debug
			{
				csViewOutStuff.Format( "   System.out.println( \"************ Toggling trace output ************\" );" );
				pcsaBody->Add(csViewOutStuff);
				pcsaBody->Add( "");
			}
			break;

		}
	}

	pcsaArguments->RemoveAll();
}




void CAG_ICONN_ASP::finalize(CStringArray* pcsaBody)
{
	if ( b_csTaskID )
	{
		pcsaBody->Add( "   csTaskID=Nothing" );
	}

	if ( b_csBuffer )
	{
		pcsaBody->Add( "   set csBuffer = nothing" );
	}

	if ( b_nBufferSize )
	{
		pcsaBody->Add( "   set nBufferSize = nothing" );
	}

	if ( b_XMLData )
	{
		pcsaBody->Add( "   set XMLData = nothing" );
	}

	if ( b_nMaxSize )
	{
		pcsaBody->Add( "   set nMaxSize = nothing" );
	}

	if ( b_nTimeout )
	{
		pcsaBody->Add( "   set nTimeout = nothing" );
	}

	if ( b_csDataRef )
	{
		pcsaBody->Add( "   set csDataRef = nothing" );
	}

	if ( b_csPath )
	{
		pcsaBody->Add( "   set csPath = nothing" );
	}

	if ( b_Debug )
	{
		pcsaBody->Add( "   set Debug = nothing" );
	}

	pcsaBody->Add( "" );
//	pcsaBody->Add( "   session.Abandon" );
//	pcsaBody->Add( "" );
	pcsaBody->Add( "%>" );
	pcsaBody->Add( "</PRE>" );
	pcsaBody->Add( "</BODY>" );
	pcsaBody->Add( "</HTML>" );
}

void CAG_ICONN_ASP::declareVariable(AG_VARIABLE agVariable,
										  CStringArray* pcsaHeader,
										  bool* bValue)
{
	CString csLocal;
	*bValue = TRUE;
	
	switch ( agVariable )
	{
		case AG_TASK_ID:
		{
			csLocal.Format( "   Dim csTaskID");
		}
		break;

		case AG_UTILBUFFER:
		{
			csLocal.Format( "   Dim csBuffer");
		}
		break;

		case AG_BUFFER_SIZE:
		{
			csLocal.Format( "   Dim nBufferSize");
		}
		break;

		case AG_XML_DATA:
		{
			csLocal.Format( "   Dim XMLData");
		}
		break;

		case AG_MAX_SIZE:
		{
			csLocal.Format( "   Dim nMaxSize");
		}
		break;

		case AG_DATA_REF:
		{
			csLocal.Format( "   Dim csDataRef");
		}
		break;

		case AG_PATH:
		{
			csLocal.Format( "   Dim csPath");
		}
		break;

		case AG_TIMEOUT:
		{
			csLocal.Format( "   Dim nTimeout");
		}
		break;

	}

	pcsaHeader->Add(csLocal);

}


void CAG_ICONN_ASP::checkDebug( bool b_Debug, CString csFunctionName, CStringArray* pcsaBody )
{
	CString csLocal;
	
	if ( b_Debug )
	{
		csLocal.Format( "    MsgBox \"%s\"", csFunctionName );
		pcsaBody->Add(csLocal);
	}
}


void CAG_ICONN_ASP::resetVariableFlags()
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