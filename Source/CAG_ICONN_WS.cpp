// Static Model
#include "stdafx.h"
#include "apigen.h"

#include "CAG_ICONN_WS.h"

CAG_ICONN_WS::CAG_ICONN_WS()
{
	resetVariableFlags();		
}

CAG_ICONN_WS::~CAG_ICONN_WS()
{
	
}


void CAG_ICONN_WS::generateHeader(CStringArray* pcsaHeader,
									   CStringArray* pcsaBody)
{
		// name and open output file if specified
	SYSTEMTIME	systime;
	GetSystemTime(&systime);
	time_t osBinaryTime;
	time( &osBinaryTime ) ;
	CTime t( osBinaryTime );
	
	int nMonth = t.GetMonth();
	int nDay = t.GetDay();
	int nYear = t.GetYear();

	CString csViewOutStuff;

	pcsaHeader->Add("' *********************************************************************APIGen");
	pcsaHeader->Add("'                   Attachmate Synapta");
	pcsaHeader->Add("'                IConnector Windows Scripting");
	pcsaHeader->Add("'" );
	pcsaHeader->Add("'   This file consists of Windows VBScript commands that drive the Synapta");
	pcsaHeader->Add("'   COM interface.");
	pcsaHeader->Add("'" );
	pcsaHeader->Add("'   After this code is generated it will be necessary for you to double click on");
	pcsaHeader->Add("'   this .vbs file.  You may choose to modify this file in one or more of the ");
	pcsaHeader->Add("'   following ways:");
	pcsaHeader->Add("'   1) ");
	pcsaHeader->Add("'      ");
	pcsaHeader->Add("'   2) ");
	pcsaHeader->Add("'      ");

	time_t ltime;
	time( &ltime );

	pcsaHeader->Add("'" );
	csViewOutStuff.Format( "'   Generated:   %s", ctime( &ltime ) );
	pcsaHeader->Add(csViewOutStuff);

	pcsaHeader->Add( "" );
	pcsaHeader->Add("' ****************************************************************************");
	pcsaHeader->Add( "" );
	pcsaHeader->Add("Dim XXX");

	pcsaBody->Add("" );
	pcsaBody->Add("set XXX = CreateObject(\"XXXXXX\")" );
	//pcsaBody->Add("set Sessions = System.Sessions" );
	//pcsaBody->Add("Set Sess0 = System.ActiveSession" );
	pcsaBody->Add("" );
	pcsaBody->Add("YYY = inputbox(\"Open this session:\", \"Specify Session\", \"session1.xyz\")");
	pcsaBody->Add("if YYY = \"\" then");
	pcsaBody->Add(" WScript.Quit(1)");
	pcsaBody->Add("else");
	pcsaBody->Add(" Set ZZZ = Sessions.Open( YYY )" );
	pcsaBody->Add("end if");
	pcsaBody->Add("" );
	pcsaBody->Add("' ****************************************************************************");
	pcsaBody->Add("" );

}



void CAG_ICONN_WS::appendBody(int nFunctionNum,
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

	pcsaBody->Add( " " );

	csViewOutStuff.Format( "   // *** %s", csFunctionName );
	pcsaBody->Add(csViewOutStuff);

	checkDebug( b_Debug, csFunctionName, pcsaBody );

	CString	csLocal;

	switch ( nFunctionNum )
	{
		case 0:     //IConnectionAccess::cancel
		{
			pcsaBody->Add("            ica.cancel");
			pcsaBody->Add("");
		}
		break;

		case 1:     //IConnectionAccess::close
		{
			pcsaBody->Add("            try");
			pcsaBody->Add("            {");
			pcsaBody->Add("               ica.close");
			pcsaBody->Add("            }");
			pcsaBody->Add("               catch (com.attachmate.connectors.ConnectorAccessException e)" );
			pcsaBody->Add("            {" );
			pcsaBody->Add("               MsgBox e.getMessage()");
			pcsaBody->Add("            }" );
			pcsaBody->Add("");
		}
		break;

		case 2:     //IConnectionAccess::execute
		{
			if ( !b_nTaskID )
			{
				declareVariable( AG_TASK_ID, pcsaHeader, &b_nTaskID );
			}

			if ( !b_nBuffer )
			{
				declareVariable( AG_UTILBUFFER, pcsaHeader, &b_nBuffer );
			}

			csViewOutStuff.Format( "            nTaskID = %s", pcsaArguments->GetAt(1) );
			pcsaBody->Add(csViewOutStuff);
			csViewOutStuff.Format( "            Buffer = %s", pcsaArguments->GetAt(2) );
			pcsaBody->Add(csViewOutStuff);

			pcsaBody->Add("" );
			pcsaBody->Add("            ica.execute nTaskID, Buffer" );
			pcsaBody->Add(" " );

		}
		break;

		case 3:     //IConnectionAccess::getAvailable
		{
			if ( !b_nBufferSize )
			{
				declareVariable( AG_BUFFER_SIZE, pcsaHeader, &b_nBufferSize );
			}

			pcsaBody->Add("" );
			pcsaBody->Add("            nBufferSize = ica.getAvailable();" );
			pcsaBody->Add(" " );

		}
		break;

		case 4:     //IConnectionAccess::getData
		case 5:     //IConnectionAccess::getMaxSize
		case 6:     //IConnectionAccess::getMetaData
		case 7:     //IConnectionAccess::getTimeOut
		case 8:     //IConnectionAccess::open
		case 9:     //IConnectionAccess::setMaxSize
		case 10:     //IConnectionAccess::setTimeOut
		case 11:	//debug
		{
			csViewOutStuff.Format( "   // APIGen has not yet implemented this method." );
			pcsaBody->Add(csViewOutStuff);
		}
		break;

	}

	pcsaArguments->RemoveAll();
}


void CAG_ICONN_WS::finalize(CStringArray* pcsaBody)
{
	
}


void CAG_ICONN_WS::declareVariable(AG_VARIABLE agVariable,
										CStringArray* pcsaHeader,
										bool* bValue)
{
	CString csLocal;
	*bValue = TRUE;
	
	switch ( agVariable )
	{
		case AG_TASK_ID:
		{
			csLocal.Format( "            Dim nTaskID");
		}
		break;

		case AG_UTILBUFFER:
		{
			csLocal.Format( "            Dim Buffer");
		}
		break;

		case AG_BUFFER_SIZE:
		{
			csLocal.Format( "            Dim nBufferSize");
		}
		break;


	}

	pcsaHeader->Add(csLocal);

}



void CAG_ICONN_WS::checkDebug(bool b_Debug,
								   CString csFunctionName,
								   CStringArray* pcsaBody)
{
	CString csLocal;
	
	if ( b_Debug )
	{
		csLocal.Format( "    MsgBox \"%s\"", csFunctionName );
		pcsaBody->Add(csLocal);
	}
}



void CAG_ICONN_WS::resetVariableFlags()
{
	b_Debug=FALSE;
}