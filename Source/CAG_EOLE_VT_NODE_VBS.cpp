// Static Model
#include "stdafx.h"
#include "apigen.h"

#include "CAG_EOLE_VT_NODE_VBS.h"

CAG_EOLE_VT_NODE_VBS::CAG_EOLE_VT_NODE_VBS()
{
	resetVariableFlags();
}

CAG_EOLE_VT_NODE_VBS::~CAG_EOLE_VT_NODE_VBS()
{
	
}


void CAG_EOLE_VT_NODE_VBS::generateHeader(CStringArray* pcsaHeader,
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

	pcsaHeader->Add("<script language=\"vbscript\">");
	pcsaHeader->Add("' ****************************************************************************");
	pcsaHeader->Add("'             Attachmate VT Host OLE Automation");
	pcsaHeader->Add("'                      APIGen VBScript");
	pcsaHeader->Add("'" );
	pcsaHeader->Add("'   This HTML file consists of VBScript code that loads and drives the Extra!");
	pcsaHeader->Add("'    X-treme ActiveX control.");
	pcsaHeader->Add("'" );
	pcsaHeader->Add("'   To use this code Extra! X-treme or newer must be installed on your PC ");
	pcsaHeader->Add("'   and a session file must be created, configured, and saved.");
	pcsaHeader->Add("'   Beyond that you must only double click on this HTML file, specify the Extra!");
	pcsaHeader->Add("'   session file that you intend to use when prompted, and then watch it work.");
	pcsaHeader->Add("'" );
	pcsaHeader->Add("'   Note that code generated concerning the Sessions and System objects may not");
	pcsaHeader->Add("'   work as the context in which this runs is not entirely understood by the APIGen");
	pcsaHeader->Add("'   nerd.");

	time_t ltime;
	time( &ltime );

	pcsaHeader->Add("'" );
	csViewOutStuff.Format( "'   Generated:   %s", ctime( &ltime ) );
	pcsaHeader->Add(csViewOutStuff);

	pcsaHeader->Add("'" );
	pcsaHeader->Add("' ****************************************************************************");
	pcsaHeader->Add("</script>");
	pcsaHeader->Add("");
	pcsaHeader->Add("");
	pcsaHeader->Add("<html>");
	pcsaHeader->Add("<head>");
	pcsaHeader->Add("<title>Extra! X-treme Launcher -- APIGen VBScript</title>");
	pcsaHeader->Add("");
	pcsaHeader->Add("<script language=\"vbscript\">");
	pcsaHeader->Add("");
	pcsaHeader->Add("sub startextra()");
	pcsaHeader->Add("  dim sessionname");
	pcsaHeader->Add("");
	pcsaHeader->Add("  sessionname = inputbox(\"EXTRA! session to open:\", \"EXTRA!\", \"session1.edp\")");
	pcsaHeader->Add("  if sessionname <> \"\" then");
	pcsaHeader->Add("     extra.launchfile = sessionname");
	pcsaHeader->Add("     extra.embedded = true");
	pcsaHeader->Add("     extra.onclose = \"cache\" 'close  - EXTRA! closes when browser closes");
	pcsaHeader->Add("                               'detach - EXTRA! stays open when browser closes");
	pcsaHeader->Add("                               'cached - session will remain at the same place");
	pcsaHeader->Add("                               '         after surfing away");
	pcsaHeader->Add("");
	pcsaHeader->Add("     if not extra.launch() then");
	pcsaHeader->Add("        msgbox \"failed to launch session!\"");
	pcsaHeader->Add("     end if");
	pcsaHeader->Add("");        
	pcsaHeader->Add("  end if");
	pcsaHeader->Add("end sub");
	pcsaHeader->Add("");
	pcsaHeader->Add("");
	pcsaHeader->Add("sub APIGenerated()");

	pcsaBody->Add("");
	pcsaBody->Add("   'hide the start button");
	pcsaBody->Add("   startform.style.display = \"none\"");
	pcsaBody->Add("");

}


void CAG_EOLE_VT_NODE_VBS::appendBody(int nFunctionNum,
										bool bPromptForValues,
										CStringArray* pcsaArguments,
										CStringArray* pcsaHeader,
										CStringArray* pcsaBody)
{
	CString csViewOutStuff;
	CString csFunctionName, csFunctionNum;
	
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

	csViewOutStuff.Format( " " );
	pcsaBody->Add(csViewOutStuff);

	csViewOutStuff.Format( "'   *** %s", csFunctionName );
	pcsaBody->Add(csViewOutStuff);

	checkDebug( b_Debug, csFunctionName, pcsaBody );

	CString	csLocal;

	switch ( nFunctionNum )
	{
		
		// **************************** OIA ******************************		
		case 0:		// Screen.OIA.ConnectionStatus
		{		
			if ( !b_nStatus )
			{
				declareVariable( AG_STATUS, pcsaHeader, &b_nStatus );
			}

			pcsaBody->Add("   nStatus = extra.session.screen.OIA.ConnectionStatus");
		}
		break;
			

		case 1:		// Screen.OIA.ErrorStatus
		{		
			if ( !b_nStatus )
			{
				declareVariable( AG_STATUS, pcsaHeader, &b_nStatus );
			}

			pcsaBody->Add("   nStatus = extra.session.screen.OIA.ErrorStatus");  
		}
		break;


		case 2:		// Screen->OIA.Updated
		{
			if ( !b_bUpdated )
			{
				declareVariable( AG_UPDATED, pcsaHeader, &b_bUpdated );
			}

			pcsaBody->Add("   bUpdated = extra.session.screen.OIA.Updated");  
		}
		break;


		case 3:		// Screen.OIA.Value
		{		
			if ( !b_cString )
			{
				declareVariable( AG_STRING, pcsaHeader, &b_cString );			
			}

            if ( "TRUE" == pcsaArguments->GetAt(1) )
			{
				pcsaBody->Add("   extra.session.screen.OIA.Value = Buffer;");
			}
			else
			{
				pcsaBody->Add("   Buffer = extra.session.screen.OIA.Value");
			}
		}
		break;


		case 4:		// Screen.OIA.XStatus
		{
			if ( !b_nStatus )
			{
				declareVariable( AG_STATUS, pcsaHeader, &b_nStatus );
			}

			pcsaBody->Add("   nStatus = extra.session.screen.OIA.XStatus");
		}
		break;


	
	// **************************** SCREEN ******************************	
	case 5:		// Screen::Col
		{		
			if ( !b_nColumn )
			{
				declareVariable( AG_COLUMN, pcsaHeader, &b_nColumn );
			}

			pcsaBody->Add("   nColumn = extra.session.screen.Col");
		}
		break;


		case 6:		// Screen::Copy
		{		
			pcsaBody->Add("   extra.session.screen.Copy");
		}
		break;

		case 7:		// Screen::FieldAttribute
		{			
			if ( !b_nRow )
			{
				declareVariable( AG_ROW, pcsaHeader, &b_nRow );
			}

			if ( !b_nColumn )
			{
				declareVariable( AG_COLUMN, pcsaHeader, &b_nColumn );
			}

			if ( !b_nAttribute )
			{
				declareVariable( AG_ATTRIBUTE, pcsaHeader, &b_nAttribute );
			}

			csViewOutStuff.Format( "   nRow = %s", pcsaArguments->GetAt(1) );
			pcsaBody->Add(csViewOutStuff);
			csViewOutStuff.Format( "   nColumn = %s", pcsaArguments->GetAt(2) );
			pcsaBody->Add(csViewOutStuff);
			
			pcsaBody->Add("   nAttribute = extra.session.screen.FieldAttribute( nRow, nColumn )");
			
		}
		break;			

		case 8:		// Screen::GetString
		{			
			if ( !b_nRow )
			{
				declareVariable( AG_ROW, pcsaHeader, &b_nRow );
			}

			if ( !b_nColumn )
			{
				declareVariable( AG_COLUMN, pcsaHeader, &b_nColumn );
			}

			if ( !b_cString )
			{
				declareVariable( AG_STRING, pcsaHeader, &b_cString );			
			}

			if ( !b_nLength )
			{
				declareVariable( AG_LENGTH, pcsaHeader, &b_nLength );			
			}


			csViewOutStuff.Format( "   nRow = %s", pcsaArguments->GetAt(1) );
			pcsaBody->Add(csViewOutStuff);
			csViewOutStuff.Format( "   nColumn = %s", pcsaArguments->GetAt(2) );
			pcsaBody->Add(csViewOutStuff);
			csViewOutStuff.Format( "   nLength = %s", pcsaArguments->GetAt(3) );
			pcsaBody->Add(csViewOutStuff);

			pcsaBody->Add("   Buffer = extra.session.screen.GetString(nRow, nColumn, nLength)");			
		}
		break;


		case 9:		// Screen.MoveTo
		{			
			if ( !b_nColumn )
			{
				declareVariable( AG_COLUMN, pcsaHeader, &b_nColumn );
			}

			if ( !b_nRow )
			{
				declareVariable( AG_ROW, pcsaHeader, &b_nRow );
			}

			csViewOutStuff.Format( "   nRow = %s", pcsaArguments->GetAt(1) );
			pcsaBody->Add(csViewOutStuff);
			csViewOutStuff.Format( "   nColumn = %s", pcsaArguments->GetAt(2) );
			pcsaBody->Add(csViewOutStuff);
			
			pcsaBody->Add("   extra.session.screen.MoveTo nRow, nColumn ");

		}
		break;


		case 10:		// Screen.PutString
		{			
			if ( !b_cString )
			{
				declareVariable( AG_STRING, pcsaHeader, &b_cString );			
			}

			if ( !b_nRow )
			{
				declareVariable( AG_ROW, pcsaHeader, &b_nRow );
			}

			if ( !b_nColumn )
			{
				declareVariable( AG_COLUMN, pcsaHeader, &b_nColumn );
			}

			csViewOutStuff.Format( "   Buffer = \"%s\"", pcsaArguments->GetAt(1) );
			pcsaBody->Add(csViewOutStuff);						
			csViewOutStuff.Format( "   nRow = %s", pcsaArguments->GetAt(2) );
			pcsaBody->Add(csViewOutStuff);
			csViewOutStuff.Format( "   nColumn = %s", pcsaArguments->GetAt(3) );
			pcsaBody->Add(csViewOutStuff);

			pcsaBody->Add("   extra.session.screen.PutString Buffer, nRow, nColumn" );
					
		}
		break;
		

		case 11:	// Screen.Row
		{			
			if ( !b_nRow )
			{
				declareVariable( AG_ROW, pcsaHeader, &b_nRow );
			}

			pcsaBody->Add("   nRow = extra.session.screen.Row");
		}
		break;

		
		case 12:	// Screen.Search  
		{
			if ( !b_cString )
			{
				declareVariable( AG_STRING, pcsaHeader, &b_cString );			
			}

			if ( !b_nRow )
			{
				declareVariable( AG_ROW, pcsaHeader, &b_nRow );
			}
			
			if ( !b_nColumn )
			{
				declareVariable( AG_COLUMN, pcsaHeader, &b_nColumn );
			}

			if ( !b_Area )
			{
				declareVariable( AG_AREA, pcsaHeader, &b_Area );
			}
			
			csViewOutStuff.Format( "   Buffer = \"%s\"", pcsaArguments->GetAt(1) );
			pcsaBody->Add(csViewOutStuff);
			csViewOutStuff.Format( "   nRow = %s", pcsaArguments->GetAt(2) );
			pcsaBody->Add(csViewOutStuff);
			csViewOutStuff.Format( "   nColumn = %s", pcsaArguments->GetAt(3) );
			pcsaBody->Add(csViewOutStuff);	

			pcsaBody->Add("   set Area = extra.session.screen.Search(Buffer, nRow, nColumn) " );

		}
		break;


		case 13:	// Screen.SelectAll
		{			
			if ( !b_Area )
			{
				declareVariable( AG_AREA, pcsaHeader, &b_Area );
			}
			
			pcsaBody->Add("   set Area = extra.session.screen.SelectAll()");
			
		}
		break;

		case 14:	// Screen.SendKeys
		{
			if ( !b_cString )
			{
				declareVariable( AG_STRING, pcsaHeader, &b_cString );			
			}

			csViewOutStuff.Format( "   Buffer = \"%s\"", pcsaArguments->GetAt(1) );
			pcsaBody->Add(csViewOutStuff);
			csViewOutStuff.Format( "   extra.session.screen.Sendkeys( Buffer )" );
			pcsaBody->Add(csViewOutStuff);
		}
		break;



		case 15:	// Screen.Updated
		{
			if ( !b_bUpdated )
			{
				declareVariable( AG_UPDATED, pcsaHeader, &b_bUpdated );
			}

			csViewOutStuff.Format( "     bUpdated = extra.session.screen.Updated" );
			pcsaBody->Add(csViewOutStuff);

		}
		break;


		case 16:	// WaitForCursor
		{
			if ( !b_nColumn )
			{
				declareVariable( AG_COLUMN, pcsaHeader, &b_nColumn );
			}

			if ( !b_nRow )
			{
				declareVariable( AG_ROW, pcsaHeader, &b_nRow );
			}

			if ( !b_bRet )
			{
				declareVariable( AG_RETURN, pcsaHeader, &b_bRet );
			}

			if ( !b_nEndColumn )
			{
				declareVariable( AG_ENDCOLUMN, pcsaHeader, &b_nEndColumn );
			}

			if ( !b_nEndRow )
			{
				declareVariable( AG_ENDROW, pcsaHeader, &b_nEndRow );
			}

			csViewOutStuff.Format( "   sys.TimeoutValue = 10000   ' 10 seconds (30 is default)" );
			pcsaBody->Add(csViewOutStuff);			
			csViewOutStuff.Format( "   nRow = %s", pcsaArguments->GetAt(1) );
			pcsaBody->Add(csViewOutStuff);
			
			csViewOutStuff.Format( "   nColumn = %s", pcsaArguments->GetAt(2) );
			pcsaBody->Add(csViewOutStuff);

			if ( 0 != pcsaArguments->GetAt(2).GetLength() && 0 != pcsaArguments->GetAt(3).GetLength() )
			{
				csViewOutStuff.Format( "   nEndRow = %s", pcsaArguments->GetAt(3) );
				pcsaBody->Add(csViewOutStuff);
				csViewOutStuff.Format( "   nEndColumn = %s", pcsaArguments->GetAt(4) );
				pcsaBody->Add(csViewOutStuff);
			}
			
			pcsaBody->Add("   bRet = extra.session.screen.WaitForCursor( nRow, nColumn, nEndRow, nEndColumn )");

		}
		break;


		case 17:	// WaitForCursorMove
		{
			if ( !b_nRow )
			{
				declareVariable( AG_ROW, pcsaHeader, &b_nRow );
			}

			if ( !b_nColumn )
			{
				declareVariable( AG_COLUMN, pcsaHeader, &b_nColumn );
			}

			if ( !b_bRet )
			{
				declareVariable( AG_RETURN, pcsaHeader, &b_bRet );
			}

			csViewOutStuff.Format( "   sys.TimeoutValue = 10000   ' 10 seconds (30 is default)" );
			pcsaBody->Add(csViewOutStuff);			
			csViewOutStuff.Format( "   nRow = %s", pcsaArguments->GetAt(1) );
			pcsaBody->Add(csViewOutStuff);
			csViewOutStuff.Format( "   nColumn = %s", pcsaArguments->GetAt(2) );
			pcsaBody->Add(csViewOutStuff);
			
			pcsaBody->Add( "   bRet = extra.session.screen.WaitForCursorMove( nRow, nColumn )");

		}
		break;


		case 18:	// WaitForKeys
		{
			if ( !b_nTimeout )
			{
				declareVariable( AG_TIMEOUT, pcsaHeader, &b_nTimeout );
			}

			if ( !b_sKeys )
			{
				declareVariable( AG_PROCESS_KEYSTROKES, pcsaHeader, &b_sKeys );
			}

			if ( !b_bProcess )
			{
				declareVariable( AG_PROCESS, pcsaHeader, &b_bProcess );
			}


			csViewOutStuff.Format("   nTimeout = %s", pcsaArguments->GetAt(1));
			pcsaBody->Add(csViewOutStuff);
			csViewOutStuff.Format("   sKeys = \"%s\"", pcsaArguments->GetAt(2));
			pcsaBody->Add(csViewOutStuff);
			csViewOutStuff.Format("   bProcess = %s", pcsaArguments->GetAt(3));
			pcsaBody->Add(csViewOutStuff);

			pcsaBody->Add("   sKeys = extra.session.screen.WaitForKeys( nTimeout, sKeys, bProcess )" );
			
		}
		break;

		case 19:  //WaitForStream
		{
			if ( !b_cString )
			{
				declareVariable( AG_STRING, pcsaHeader, &b_cString );
			}

			if ( !b_nIdle )
			{
				declareVariable( AG_IDLE_TIME, pcsaHeader, &b_nIdle );
			}

			if ( !b_nTimeout )
			{
				declareVariable( AG_TIMEOUT, pcsaHeader, &b_nTimeout );
			}

			if ( !b_nOptions )
			{
				declareVariable( AG_OPTIONS, pcsaHeader, &b_nOptions );
			}

			if ( !b_bRet )
			{
				declareVariable( AG_RETURN, pcsaHeader, &b_bRet );
			}

			csViewOutStuff.Format("   Buffer = \"%s\"", pcsaArguments->GetAt(1));
			pcsaBody->Add(csViewOutStuff);
			csViewOutStuff.Format("   nIdle = %s", pcsaArguments->GetAt(2));
			pcsaBody->Add(csViewOutStuff);
			csViewOutStuff.Format("   nTimeout = %s", pcsaArguments->GetAt(3));
			pcsaBody->Add(csViewOutStuff);
			csViewOutStuff.Format("   nOptions = %s", pcsaArguments->GetAt(4));
			pcsaBody->Add(csViewOutStuff);

			pcsaBody->Add("   bRet = extra.session.screen.WaitForStream(Buffer, nIdle, nTimeout, nOptions)" );

		}
		break;	


		case 20:	// WaitForString
		{
			if ( !b_cString )
			{
				declareVariable( AG_STRING, pcsaHeader, &b_cString );
			}

			if ( !b_nRow )
			{
				declareVariable( AG_ROW, pcsaHeader, &b_nRow );
			}

			if ( !b_nColumn )
			{
				declareVariable( AG_COLUMN, pcsaHeader, &b_nColumn );
			}

			if ( !b_nPage )
			{
				declareVariable( AG_PAGE, pcsaHeader, &b_nPage );
			}

			if ( !b_nIdle )
			{
				declareVariable( AG_IDLE_TIME, pcsaHeader, &b_nIdle );
			}

			if ( !b_nTimeout )
			{
				declareVariable( AG_TIMEOUT, pcsaHeader, &b_nTimeout );
			}

			if ( !b_nOptions )
			{
				declareVariable( AG_OPTIONS, pcsaHeader, &b_nOptions );
			}

			if ( !b_nType )
			{
				declareVariable( AG_TYPE, pcsaHeader, &b_nType );
			}

			if ( !b_nEndRow )
			{
				declareVariable( AG_ENDROW, pcsaHeader, &b_nEndRow );
			}

			if ( !b_nEndColumn )
			{
				declareVariable( AG_ENDCOLUMN, pcsaHeader, &b_nEndColumn );
			}

			if ( !b_bRet )
			{
				declareVariable( AG_RETURN, pcsaHeader, &b_bRet );
			}


			csViewOutStuff.Format("   Buffer = \"%s\"", pcsaArguments->GetAt(1));
			pcsaBody->Add(csViewOutStuff);
			
			if ( 0 == pcsaArguments->GetAt(2).GetLength())
			{
				csViewOutStuff.Format("   nRow = 1" );
				pcsaBody->Add(csViewOutStuff);
			}
			else
			{
				csViewOutStuff.Format("   nRow = %s", pcsaArguments->GetAt(2));
				pcsaBody->Add(csViewOutStuff);
			}

			if ( 0 == pcsaArguments->GetAt(3).GetLength())
			{
				csViewOutStuff.Format("   nColumn = 1" );
				pcsaBody->Add(csViewOutStuff);
			}
			else
			{
				csViewOutStuff.Format("   nColumn = %s", pcsaArguments->GetAt(3));
				pcsaBody->Add(csViewOutStuff);
			}

			if ( 0 == pcsaArguments->GetAt(4).GetLength())
			{
				csViewOutStuff.Format("   nPage = 0" );
				pcsaBody->Add(csViewOutStuff);
			}
			else
			{
				csViewOutStuff.Format("   nPage = %s", pcsaArguments->GetAt(4));
				pcsaBody->Add(csViewOutStuff);
			}

			pcsaBody->Add("nIdle = 0");

			if ( 0 == pcsaArguments->GetAt(5).GetLength())
			{
				csViewOutStuff.Format("   nTimeout = 5000" );
				pcsaBody->Add(csViewOutStuff);
			}
			else
			{
				csViewOutStuff.Format("   nTimeout = %s", pcsaArguments->GetAt(5));
				pcsaBody->Add(csViewOutStuff);
			}


			csViewOutStuff.Format("   nOptions = %s", pcsaArguments->GetAt(6));
			pcsaBody->Add(csViewOutStuff);

			if ( -1 != pcsaArguments->GetAt(7).Find("Select string") )
			{
				pcsaBody->Add("   nType = 1" );
			}
			else
			{
				pcsaBody->Add("   nType = 2" );
			}


			// if the endrow/endcol arguments are not specified then don't insert them
			if ( 0 != pcsaArguments->GetAt(8).GetLength() || 0 != pcsaArguments->GetAt(9).GetLength() )
			{
				if ( 0 != pcsaArguments->GetAt(8).GetLength() )
				{
					csViewOutStuff.Format("   nEndRow = %s", pcsaArguments->GetAt(8));
					pcsaBody->Add(csViewOutStuff);
				}
				else
				{
					pcsaBody->Add( "   nEndRow = 0;");
				}

				if ( 0 != pcsaArguments->GetAt(9).GetLength() )
				{
					csViewOutStuff.Format("   nEndColumn = %s", pcsaArguments->GetAt(9));
					pcsaBody->Add(csViewOutStuff);
				}
				else
				{
					pcsaBody->Add( "   nEndColumn = 0;");
				}

				pcsaBody->Add("bRet = extra.session.screen.WaitForString(Buffer, nRow, nColumn, nPage, nIdle, nTimeout, nOptions, nType, nEndRow, nEndColumn)" );
			}
			else
			{
				pcsaBody->Add("bRet = extra.session.screen.WaitForString(Buffer, nRow, nColumn, nPage, nIdle, nTimeout, nOptions, nType )" );
			}

		}
		break;	

		case 21:	// WaitHostQuiet
		{
			if ( !b_nSettleTime )
			{
				declareVariable( AG_SETTLE_TIME, pcsaHeader, &b_nSettleTime );
			}

			if ( !b_bRet )
			{
				declareVariable( AG_RETURN, pcsaHeader, &b_bRet );
			}

			csViewOutStuff.Format("   nSettleTime = %s", pcsaArguments->GetAt(1));
			pcsaBody->Add(csViewOutStuff);

			pcsaBody->Add("   bRet = extra.session.screen.WaitHostQuiet(nSettleTime)" );

		}
		break;

		// **************************** SESSION ******************************
		case 22:	// Session::Activate
		{
			pcsaBody->Add( "   extra.session.Activate");			
		}
		break;

		case 23:	// Session::ClearComm
		{
			pcsaBody->Add( "   extra.session.ClearComm");			
		}
		break;

		case 24:	//	Session::ClearHistory
		{
			pcsaBody->Add( "   extra.session.ClearHistory");			
		}
		break;
	
		case 25:	// Session::Close
		{
			pcsaBody->Add( "   extra.session.Close");			
		}
		break;


		case 26:	// Session::CloseEx
		{
			int nOption=0;
			if ( !b_nCloseOption )
			{
				declareVariable( AG_CLOSEOPTION, pcsaHeader, &b_nCloseOption );
			}

			if ( -1 != pcsaArguments->GetAt(1).Find( "Disconnect", 0 ) )
			{
				nOption = 1;
			}

			if ( -1 != pcsaArguments->GetAt(1).Find( "exiting", 0 ) )
			{
				nOption += 4;
			}
			
			if ( -1 != pcsaArguments->GetAt(1).Find( "saving", 0 ) )
			{
				nOption += 8;
			}
			
			if ( -1 != pcsaArguments->GetAt(1).Find( "for", 0 ) )
			{
				nOption += 16;
			}

			csViewOutStuff.Format("   nCloseOption = %i", nOption );
			pcsaBody->Add(csViewOutStuff);

			pcsaBody->Add( "   extra.session.CloseEx( nCloseOption )");
		}
		break;

		case 27:	// Session::ClosePrintJob
		{
			pcsaBody->Add( "   extra.session.ClosePrintJob");			
		}
		break;

		case 28:	// Session::Connected
		{
			if ( !b_bRet )
			{
				declareVariable( AG_RETURN, pcsaHeader, &b_bRet );
			}

			pcsaBody->Add( "   bRet = extra.session.Connected");			
		}
		break;

		case 29:	// Session::EnlargeFont
		{
			pcsaBody->Add( "   extra.session.EnlargeFont");			
		}
		break;

		case 30:	// Session::FileTransferHostOS
		{
			if ( !b_nHostOS )
			{
				declareVariable( AG_HOST_OS, pcsaHeader, &b_nHostOS );
			}

			if ( -1 != pcsaArguments->GetAt(1).Find("TRUE") )
			{
				if ( -1 != pcsaArguments->GetAt(2).Find("CMS") )
				{
					csViewOutStuff.Format( "   nFTHostOS = 0"  );
				}
				else if ( -1 != pcsaArguments->GetAt(2).Find("TSO") )
				{
					csViewOutStuff.Format( "   nFTHostOS = 1"  );
				}
				else	// CICS
				{
					csViewOutStuff.Format( "   nFTHostOS = 2"  );
				}
				pcsaBody->Add(csViewOutStuff);
				pcsaBody->Add( "   extra.session.FileTransferHostOS = nFTHostOS" );
			}
			else
			{
				pcsaBody->Add( "   nFTHostOS = extra.session.FileTransferHostOS" );
			}

		}
		break;

		case 31:	// FileTransferOptions
		{
			if ( !b_ftObj )
			{
				declareVariable( AG_FT_OBJ, pcsaHeader, &b_ftObj );
			}

			pcsaBody->Add("   set ftObj = extra.session.FileTransferOptions");
		}
		break;

		case 32:	// Session::FileTransferScheme
		{
			CString csSetFTScheme;
			
			if ( !b_FTScheme )
			{
				declareVariable( AG_FT_SCHEME, pcsaHeader, &b_FTScheme );
			}

			if ( -1 != pcsaArguments->GetAt(2).Find("TRUE") )
			{
				//set it
				csViewOutStuff.Format("   FTScheme = \"%s\"", pcsaArguments->GetAt(1) );
				pcsaBody->Add(csViewOutStuff);
				pcsaBody->Add( "   extra.session.FileTransferScheme = FTScheme" );	
			}
			else
			{
				//get it
				pcsaBody->Add( "   FTScheme = extra.session.FileTransferScheme" );
			}

		}
		break;

		case 33:	// Session::Font
		{
			if ( !b_font )
			{
				declareVariable( AG_FONTNAME, pcsaHeader, &b_font );
			}

			if ( -1 != pcsaArguments->GetAt(1).Find("TRUE") )
			{
				//set it
				csViewOutStuff.Format("   font = \"%s\"", pcsaArguments->GetAt(2) );
				pcsaBody->Add(csViewOutStuff);
				pcsaBody->Add( "   extra.session.Font = font" );	
			}
			else
			{
				//get it
				pcsaBody->Add( "   font = extra.session.Font");
			}

		}
		break;


		case 34:	// Session::Height
		{
			if ( !b_nHeight )
			{
				declareVariable( AG_HEIGHT, pcsaHeader, &b_nHeight );
			}

			if ( pcsaArguments->GetAt(1) == "TRUE" )
			{
				//set it
				csViewOutStuff.Format( "   nHeight = %s", pcsaArguments->GetAt(2) );
				pcsaBody->Add(csViewOutStuff);
				
				pcsaBody->Add( "   extra.session.Height = nHeight");
			}
			else
			{
				//get it
				pcsaBody->Add( "   nHeight = extra.session.Height");
			}
			
		}
		break;

		case 35:	// Session::HoldScreen
		{
			if ( !b_bScreenHeld )
			{
				declareVariable( AG_SCREEN_HELD, pcsaHeader, &b_bScreenHeld );
			}

			// set or get???
			if ( -1 != pcsaArguments->GetAt(1).Find("TRUE") )
			{
				// set to true/false???
				csViewOutStuff.Format( "   bScreenHeld = %s", pcsaArguments->GetAt(2) );
				pcsaBody->Add( csViewOutStuff );
				pcsaBody->Add( "   extra.session.HoldScreen = bScreenHeld");

			}
			else
			{
				pcsaBody->Add( "   bScreenHeld = extra.session.HoldScreen");
			}
		}
		break;


		case 36:	// Session::HostName
		{
			if ( !b_hostname )
			{
				declareVariable( AG_HOSTNAME, pcsaHeader, &b_hostname );
			}

			pcsaBody->Add( "   hostname = extra.session.HostName" );
		}
		break;


		case 37:	// Session::InvokeSettingsDialog
		{
			if ( !b_settingsPage )
			{
				declareVariable( AG_SETTINGS_PAGE, pcsaHeader, &b_settingsPage );
			}

			if ( -1 != pcsaArguments->GetAt(2).Find("None") )
			{
				csViewOutStuff.Format( "   settingsPage = %s", pcsaArguments->GetAt(1) );
				pcsaBody->Add(csViewOutStuff);

				pcsaBody->Add( "   extra.session.InvokeSettingsDialog( settingsPage )");
			}
			else
			{
				if ( !b_settingsTab )
				{
					declareVariable( AG_SETTINGS_TAB, pcsaHeader, &b_settingsTab );
				}

				csViewOutStuff.Format( "   settingsPage = %s", pcsaArguments->GetAt(1) );
				pcsaBody->Add(csViewOutStuff);

				csViewOutStuff.Format( "   settingsTab = %s", pcsaArguments->GetAt(2) );
				pcsaBody->Add(csViewOutStuff);

				pcsaBody->Add( "   extra.session.InvokeSettingsDialog( settingsPage, settingsTab )");

			}
		}
		break;

		case 38:	// Session::KeyboardLocked
		{
			if ( !b_bKeyboardLocked )
			{
				declareVariable( AG_KBD_LOCKED, pcsaHeader, &b_bKeyboardLocked );
			}

			// set or get???
			if ( -1 != pcsaArguments->GetAt(1).Find("TRUE") )
			{
				// set to true/false???
				csViewOutStuff.Format( "   bKeyboardLocked = %s", pcsaArguments->GetAt(2) );
				pcsaBody->Add( csViewOutStuff );
				pcsaBody->Add( "   extra.session.KeyboardLocked = bKeyboardLocked");

			}
			else
			{
				pcsaBody->Add( "   bKeyboardLocked = extra.session.KeyboardLocked");
			}
		}
		break;


		case 39:	// Session::KeyMap
		{
			CString csKeyMap;
			csKeyMap = pcsaArguments->GetAt(1);

			if ( !b_cString )
			{
				declareVariable( AG_STRING, pcsaHeader, &b_cString );			
			}

			if ( -1 != pcsaArguments->GetAt(1).Find( "TRUE" ) )
			{
				csViewOutStuff.Format( "   Buffer = \"%s\"", pcsaArguments->GetAt(2) );
				pcsaBody->Add(csViewOutStuff);
				pcsaBody->Add("   extra.session.KeyMap=Buffer");

			}
			else
			{
				
				pcsaBody->Add("   Buffer = extra.session.KeyMap");
			}

		}
		break;


		case 40:	// Session::Language
		{
			if ( !b_cString )
			{
				declareVariable( AG_STRING, pcsaHeader, &b_cString );			
			}

			if ( -1 != pcsaArguments->GetAt(1).Find( "TRUE" ) )
			{
				csViewOutStuff.Format( "   Buffer = \"%s\"", pcsaArguments->GetAt(2) );
				pcsaBody->Add(csViewOutStuff);
				pcsaBody->Add("   extra.session.Language = Buffer" );
			}
			else
			{
				pcsaBody->Add( "   Buffer = extra.session.Language");
			}

		}
		break;

		case 41:	// Session::Local
		{
			if ( !b_bLocalMode )
			{
				declareVariable( AG_LOCALMODE, pcsaHeader, &b_bLocalMode );			
			}

			// set or get???
			if ( -1 != pcsaArguments->GetAt(1).Find("TRUE") )
			{
				// set to true/false???
				csViewOutStuff.Format( "   bLocalMode = %s", pcsaArguments->GetAt(2) );
				pcsaBody->Add( csViewOutStuff );
				pcsaBody->Add( "   extra.session.Local = bLocalMode");

			}
			else
			{
				pcsaBody->Add( "   bLocalMode = extra.session.Local");
			}
		}
		break;

		case 42:	// Session::Menu
		{
			if ( !b_bMenuVisible )
			{
				declareVariable( AG_MENU_VISIBLE, pcsaHeader, &b_bMenuVisible );
			}

			// set or get???
			if ( -1 != pcsaArguments->GetAt(1).Find("TRUE") )
			{
				// set to true/false???
				csViewOutStuff.Format( "   bMenuVisible = %s", pcsaArguments->GetAt(2) );
				pcsaBody->Add( csViewOutStuff );
				pcsaBody->Add( "   extra.session.Menu = bMenuVisible");

			}
			else
			{
				pcsaBody->Add( "   bMenuVisible = extra.session.Menu");
			}
		}
		break;

		case 43:	// Session::Name
		{
			if ( !b_cString )
			{
				declareVariable( AG_STRING, pcsaHeader, &b_cString );			
			}

			pcsaBody->Add( "   Buffer = extra.session.Name");
		}
		break;

		case 44:	// Session::PrintDisplay
		{
			pcsaBody->Add( "   extra.session.PrintDisplay" );
		}
		break;

		case 45:	// Session::Quiet
		{
			if ( !b_bSessionQuiet )
			{
				declareVariable( AG_SESS_QUIET, pcsaHeader, &b_bSessionQuiet );			
			}

			// set or get???
			if ( -1 != pcsaArguments->GetAt(1).Find("TRUE") )
			{
				// set to true/false???
				csViewOutStuff.Format( "   bSessionQuiet = %s", pcsaArguments->GetAt(2) );
				pcsaBody->Add( csViewOutStuff );
				pcsaBody->Add( "   extra.session.Quiet = bSessionQuiet");

			}
			else
			{
				pcsaBody->Add( "   bSessionQuiet = extra.session.Quiet");
			}

		}
		break;


		case 46:	// Session::ReceiveFile
		{
			if ( !b_bRet )
			{
				declareVariable( AG_RETURN, pcsaHeader, &b_bRet );
			}

			if ( !b_bProcess )
			{
				declareVariable( AG_PROCESS, pcsaHeader, &b_bProcess );
			}
			
			csViewOutStuff.Format( "   bProcess = %s", pcsaArguments->GetAt(3) );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "   bRet = extra.session.ReceiveFile( \"%s\", \"%s\", bProcess )", pcsaArguments->GetAt(1), pcsaArguments->GetAt(2) );
			pcsaBody->Add(csViewOutStuff);

		}
		break;

		case 47:	// Session::ReduceFont
		{
			pcsaBody->Add("   extra.session.ReduceFont" );
		}
		break;


		case 48:	// Session::Reset
		{
			pcsaBody->Add("   extra.session.Reset" );
		}
		break;

		case 49:	// Session::Save
		{
			pcsaBody->Add("   extra.session.Save" );
		}
		break;

		case 50:	// Session::SaveAs
		{
			csViewOutStuff.Format( "   extra.session.SaveAs( \"%s\" )", pcsaArguments->GetAt(1) );
			pcsaBody->Add(csViewOutStuff);
		}
		break;

		case 51:	// Session::Saved
		{
			if ( !b_bSessionSaved )
			{
				declareVariable( AG_SESS_SAVED, pcsaHeader, &b_bSessionSaved );
			}
			pcsaBody->Add("   bSessionSaved = extra.session.Saved" );
		}
		break;

		case 52:	// Session::SendFile
		{
			if ( !b_bRet )
			{
				declareVariable( AG_RETURN, pcsaHeader, &b_bRet );
			}

			if ( !b_bProcess )
			{
				declareVariable( AG_PROCESS, pcsaHeader, &b_bProcess );
			}

			csViewOutStuff.Format( "   bProcess = %s", pcsaArguments->GetAt(3) );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "   bRet = extra.session.SendFile( \"%s\", \"%s\", bProcess )", pcsaArguments->GetAt(1), pcsaArguments->GetAt(2) );
			pcsaBody->Add(csViewOutStuff);
		}
		break;

		case 53:	// Session::Title
		{
			if ( !b_cString )
			{
				declareVariable( AG_STRING, pcsaHeader, &b_cString );			
			}

			csViewOutStuff.Format( "   Buffer = \"%s\"", pcsaArguments->GetAt(1) );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "   extra.session.Title( Buffer )");
			pcsaBody->Add(csViewOutStuff);
		}
		break;

		case 54:	// Session::TransferFile
		{
			pcsaBody->Add("   extra.session.TransferFile" );
		}
		break;

		case 55:	// Session::Type
		{
			if ( !b_nType )
			{
				declareVariable( AG_TYPE, pcsaHeader, &b_nType );
			}

			if ( -1 != pcsaArguments->GetAt(1).Find( "TRUE" ) )
			{
				csViewOutStuff.Format( "   nType = %s", pcsaArguments->GetAt(2) );
				pcsaBody->Add(csViewOutStuff);
				pcsaBody->Add("   extra.session.Type = nType" );
			}
			else
			{
				pcsaBody->Add( "   nType = extra.session.Type");
			}

		}
		break;


		case 56:	// Session::UpdateStatusBar
		{
			if ( !b_cString )
			{
				declareVariable( AG_STRING, pcsaHeader, &b_cString );			
			}

			csViewOutStuff.Format( "   Buffer = \"%s\"", pcsaArguments->GetAt(1) );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "   extra.session.UpdateStatusBar( Buffer )");
			pcsaBody->Add(csViewOutStuff);
		}
		break;

		case 57:	// Session::Visible
		{
			if ( !b_bRet )
			{
				declareVariable( AG_RETURN, pcsaHeader, &b_bRet );
			}

			if ( -1 != pcsaArguments->GetAt(1).Find( "TRUE", 0 ) )
			{
				csViewOutStuff.Format( "   extra.session.Visible = %s", pcsaArguments->GetAt(2) );
				pcsaBody->Add(csViewOutStuff);
			}
			else
			{
				csViewOutStuff.Format( "   bRet = extra.session.Visible" );
				pcsaBody->Add(csViewOutStuff);
			}
		}
		break;

		case 58:	// Session::WaitForDisconnect
		{
			if ( !b_bRet )
			{
				declareVariable( AG_RETURN, pcsaHeader, &b_bRet );
			}

			if ( !b_nTimeout )
			{
				declareVariable( AG_TIMEOUT, pcsaHeader, &b_nTimeout );
			}

			csViewOutStuff.Format( "   nTimeout = %s", pcsaArguments->GetAt(1) );
			pcsaBody->Add(csViewOutStuff);
			
			csViewOutStuff.Format( "   bRet = extra.session.WaitForDisconnect( nTimeout )");
			pcsaBody->Add(csViewOutStuff);
		}
		break;

		case 59:	// Session::WaitForTimer	
		{
			if ( !b_bRet )
			{
				declareVariable( AG_RETURN, pcsaHeader, &b_bRet );
			}

			if ( !b_nTimeout )
			{
				declareVariable( AG_TIMEOUT, pcsaHeader, &b_nTimeout );
			}

			csViewOutStuff.Format( "   nTimeout = %s", pcsaArguments->GetAt(1) );
			pcsaBody->Add(csViewOutStuff);
			
			csViewOutStuff.Format( "   bRet = extra.session.WaitForTimer( nTimeout, %s );", pcsaArguments->GetAt(2) );
			pcsaBody->Add(csViewOutStuff);
			
		}
		break;


		case 60:	// Session::Width
		{
			if ( !b_nWidth )
			{
				declareVariable( AG_WIDTH, pcsaHeader, &b_nWidth );
			}

			if ( pcsaArguments->GetAt(1) == "TRUE" )
			{
				csViewOutStuff.Format( "   nWidth = %s", pcsaArguments->GetAt(2) );
				pcsaBody->Add(csViewOutStuff);
				
				csViewOutStuff.Format( "   extra.session.Width = nWidth");
				pcsaBody->Add(csViewOutStuff);
			}
			else
			{
				csViewOutStuff.Format( "   nWidth = extra.session.Width");
				pcsaBody->Add(csViewOutStuff);
			}			
		}
		break;

		case 61:	// Session::WindowHandle	
		{
			if ( !b_hSession )
			{
				declareVariable( AG_WINDOW_HANDLE, pcsaHeader, &b_hSession );
			}

			csViewOutStuff.Format( "   hSession = extra.session.WindowHandle" );
			pcsaBody->Add(csViewOutStuff);
		}
		break;


		case 62:	// Session::WindowState
		{			
			if ( !b_nWindowState )
			{
				declareVariable( AG_WINDOW_STATE, pcsaHeader, &b_nWindowState );
			}

			if ( pcsaArguments->GetAt(1) == "TRUE" )
			{
				csViewOutStuff.Format( "   nWindowState = %s", pcsaArguments->GetAt(2) );
				pcsaBody->Add(csViewOutStuff);				
				pcsaBody->Add("   extra.session.WindowState = nWindowState");
			}
			else
			{
				pcsaBody->Add( "   nWindowState = extra.session.WindowState");
			}
		}
		break;

		// **************************** SESSIONS ******************************

		case 63:	// Sessions::Open
		{
			if ( !b_SessName )
			{
				declareVariable( AG_SESS_OPEN, pcsaHeader, &b_SessName );
			}

			csViewOutStuff.Format( "   SessName = \"%s\"", pcsaArguments->GetAt(1) );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "   set Sess = Sessions.Open( SessName )");
			pcsaBody->Add(csViewOutStuff);
			
		}
		break;

		case 64:	// Sessions::Count
		{
			if ( !b_nCount )
			{
				declareVariable( AG_COUNT, pcsaHeader, &b_nCount );
			}
			pcsaBody->Add( "   nCount = Sessions.Count" );
		}
		break;


		case 65:	// Sessions::CloseAll
		{
			pcsaBody->Add("   Sessions.CloseAll" );
		}
		break;

		
		// **************************** SYSTEM ******************************

		case 66:	// System::ActiveSession
		{
			pcsaBody->Add( "   set sess = sys.ActiveSession" );
		}
		break;

		case 67:	// System::Name
		{
			if ( !b_cString )
			{
				declareVariable( AG_STRING, pcsaHeader, &b_cString );			
			}

			pcsaBody->Add( "   Buffer = sys.Name");
		}
		break;

		case 68:	// System::Quit
		{
			pcsaBody->Add( "   System.Quit" );
		}
		break;

		case 69:	// System::Time
		{
			if ( !b_cString )
			{
				declareVariable( AG_STRING, pcsaHeader, &b_cString );			
			}

			pcsaBody->Add( "   Buffer = sys.Time()");
		}
		break;


		case 70:	// System::TimeoutValue
		{			
			if ( !b_nTimeout )
			{
				declareVariable( AG_TIMEOUT, pcsaHeader, &b_nTimeout );
			}

			if ( pcsaArguments->GetAt(1) == "TRUE" )
			{
				csViewOutStuff.Format( "   nTimeout = %s", pcsaArguments->GetAt(2) );
				pcsaBody->Add(csViewOutStuff);

				csViewOutStuff.Format( "   sys.TimeoutValue = nTimeout");
				pcsaBody->Add(csViewOutStuff);
			}
			else
			{
				pcsaBody->Add( "   nTimeout = sys.TimeoutValue");
			}			

		}
		break;

		case 71:	// System::Version
		{			
			if ( !b_cString )
			{
				declareVariable( AG_STRING, pcsaHeader, &b_cString );			
			}

			pcsaBody->Add( "   Buffer = sys.Version");
		}
		break;

		case 72:
		{
			csViewOutStuff.Format( "%s%i%s", "'***     Function ", nFunctionNum, ". is not implemented yet.  ");
			pcsaBody->Add(csViewOutStuff);
			csViewOutStuff.Format( " " );
			pcsaBody->Add(csViewOutStuff);
		}
		break;


		default:
		{
			csViewOutStuff.Format( "'***************** Function %i. Abandon hope, all ye who enter here.", nFunctionNum );
			pcsaBody->Add(csViewOutStuff);
		}

	}
	

	pcsaArguments->RemoveAll();

}



void CAG_EOLE_VT_NODE_VBS::finalize(CStringArray* pcsaBody)
{
	pcsaBody->Add("");
	pcsaBody->Add("end sub");
	pcsaBody->Add("");
	pcsaBody->Add("</script>");
	pcsaBody->Add("");
	pcsaBody->Add("</head>");
	pcsaBody->Add("");
	pcsaBody->Add("<body style=\"margin:0\" >");
	pcsaBody->Add("");
	pcsaBody->Add("<form name=\"startform\">");
	pcsaBody->Add("&nbsp;<br>");
	pcsaBody->Add("<center>");
	pcsaBody->Add("<input  type=\"button\" value=\"Start EXTRA!\" onclick=\"startextra()\">");
	pcsaBody->Add("<input  type=\"button\" value=\"Run Script\" onclick=\"APIGenerated()\">");
	pcsaBody->Add("</center>");
	pcsaBody->Add("</form>");
	pcsaBody->Add("");
	pcsaBody->Add("");
	pcsaBody->Add("<!-- ");
	pcsaBody->Add("required \"launcher\" object - height, width can be a");
	pcsaBody->Add("specific pixel value or a percentage");
	pcsaBody->Add("-->");
	pcsaBody->Add("<object id=\"extra\" classid=\"clsid:036E962F-9B09-43A1-9D3D-DB619F3EA70C\" height=100% width=100%  />");
	pcsaBody->Add("");
	pcsaBody->Add("");
	pcsaBody->Add("</body>");
	pcsaBody->Add("</html>");
}


void CAG_EOLE_VT_NODE_VBS::declareVariable(AG_VARIABLE agVariable,
											 CStringArray* pcsaHeader,
											 bool* bValue)
{
	CString csLocal;
	*bValue = TRUE;
	
	switch ( agVariable )
	{
		case AG_STRING:
		{
			csLocal.Format( "   Dim Buffer");
		}
		break;

		case AG_STATUS:
		{
			csLocal.Format( "   Dim nStatus");
		}
		break;

		case AG_UPDATED:
		{
			csLocal.Format( "   Dim bUpdated");
		}
		break;

		case AG_BSTR:
		{
			csLocal.Format( "   Dim v");
		}
		break;
	
		case AG_ENDCOLUMN:
		{
			csLocal.Format( "   Dim nEndColumn");
		}
		break;

		case AG_ENDROW:
		{
			csLocal.Format( "   Dim nEndRow");
		}
		break;

		case AG_ROW:
		{
			csLocal.Format( "   Dim nRow");
		}
		break;

		case AG_COLUMN:
		{
			csLocal.Format( "   Dim nColumn");		
		}
		break;

		case AG_ATTRIBUTE:
		{
			csLocal.Format( "   Dim nAttribute");
		}
		break;

		case AG_LENGTH:
		{
			csLocal.Format( "   Dim nLength");
		}
		break;

		case AG_VALUE:
		{
			csLocal.Format( "   Dim nValue");
		}
		break;

		case AG_RETURN:
		{
			csLocal.Format( "   Dim bRet");
		}
		break;

		case AG_CLOSEOPTION:
		{
			csLocal.Format( "   Dim nCloseOption");
		}
		break;

		case AG_FT_OBJ:
		{
			csLocal.Format( "   Dim ftObj");
		}
		break;

		case AG_HOSTNAME:
		{
			csLocal.Format( "   Dim hostname");
		}
		break;

		case AG_HOST_OS:
		{
			csLocal.Format( "   Dim nFTHostOS");
		}
		break;

		case AG_HEIGHT:
		{
			csLocal.Format( "   Dim nHeight");
		}
		break;

		case AG_LOCALMODE:
		{
			csLocal.Format( "   Dim bLocalMode");
		}
		break;

		case AG_SCREEN_HELD:
		{
			csLocal.Format( "   Dim bScreenHeld");
		}
		break;

		case AG_SESS_SAVED:
		{
			csLocal.Format( "   Dim bSessionSaved");
		}
		break;

		case AG_SESSIONS_CREATED:
		{
			csLocal.Format( "   Dim Sessions" );
		}
		break;

		case AG_SESS_OPEN:
		{
			csLocal.Format( "   Dim SessName");
		}
		break;


		case AG_SETTLE_TIME:
		{
			csLocal.Format( "   Dim nSettleTime");
		}
		break;

		case AG_SESS_QUIET:
		{
			csLocal.Format( "   Dim bSessionQuiet");
		}
		break;

		case AG_SETTINGS_PAGE:
		{
			csLocal.Format( "   Dim settingsPage");
		}
		break;

		case AG_SETTINGS_TAB:
		{
			csLocal.Format( "   Dim settingsTab");
		}
		break;

		case AG_MENU_VISIBLE:
		{
			csLocal.Format( "   Dim bMenuVisible");
		}
		break;

		case AG_IDLE_TIME:
		{
			csLocal.Format( "   Dim nIdle");
		}
		break;

		case AG_OPTIONS:
		{
			csLocal.Format( "   Dim nOptions");
		}
		break;

		case AG_PAGE:
		{
			csLocal.Format( "   Dim nPage");
		}
		break;

		case AG_TYPE:
		{
			csLocal.Format( "   Dim nType");
		}
		break;

		case AG_TIMEOUT:
		{
			csLocal.Format( "   Dim nTimeout");
		}
		break;

		case AG_PROCESS:
		{
			csLocal.Format( "   Dim bProcess");
		}
		break;

		case AG_PROCESS_KEYSTROKES:
		{
			csLocal.Format( "   Dim sKeys");
		}
		break;

		case AG_WIDTH:
		{
			csLocal.Format( "   Dim nWidth");
		}
		break;

		case AG_WINDOW_HANDLE:
		{
			csLocal.Format( "   Dim hSession");
			//csLocal.Format( "   HANDLE hSession=NULL");
		}
		break;

		case AG_WINDOW_STATE:
		{
			csLocal.Format( "   Dim nWindowState");
		}
		break;

		case AG_COUNT:
		{
			csLocal.Format( "   Dim nCount");
		}
		break;

		case AG_AREA:
		{
			csLocal.Format( "   Dim Area");
		}
		break;

		case AG_FONTNAME:
		{
			csLocal.Format( "   Dim font" );
		}
		break;

		case AG_FT_SCHEME:
		{
			csLocal.Format( "   Dim FTScheme" );
		}
		break;

		// new stuff
		case AG_NAME:
		{
			csLocal.Format( "   Dim csName" );
		}
		break;

		case AG_TERMINAL:
		{
			csLocal.Format( "   Dim Terminal" );
		}
		break;

		case AG_OIAOBJ:
		{
			csLocal.Format( "   Dim OIAObj" );
		}
		break;

		case AG_TEXT:
		{
			csLocal.Format( "   Dim cText" );
		}
		break;

		case AG_EAB:
		{
			csLocal.Format( "   Dim bEABs" );
		}
		break;

		case AG_HOST_CHARSET:
		{
			csLocal.Format( "   Dim nCharSet" );
		}
		break;

		case AG_HOST_CODEPAGE:
		{
			csLocal.Format( "   Dim nHostCodePage" );
		}
		break;

		case AG_KBD_LOCKED:
		{
			csLocal.Format( "   Dim bKeyboardLocked" );
		}
		break;

		case AG_MODEL:	
		{
			csLocal.Format( "   Dim nModel" );
		}
		break;

		case AG_MODE:
		{
			csLocal.Format( "   Dim nMode" );
		}
		break;

		case AG_WAIT:
		{
			csLocal.Format( "   Dim nWait" );
		}
		break;

		case AG_ATTACHED:
		{
			csLocal.Format( "   Dim bAttached" );
		}
		break;

		case AG_CONNECTED:
		{
			csLocal.Format( "   Dim bConnected" );
		}
		break;

		case AG_CONNECTION_OBJ:
		{
			csLocal.Format( "   Dim conn" );
		}
		break;

		case AG_SCREEN_OBJ:
		{
			csLocal.Format( "   Dim screen" );
		}
		break;

		case AG_STATE:
		{
			csLocal.Format( "   Dim nState" );
		}
		break;

		case AG_PORT:
		{
			csLocal.Format( "   Dim nPort" );
		}
		break;

	}

	pcsaHeader->Add(csLocal);
	
}


void CAG_EOLE_VT_NODE_VBS::checkDebug(bool b_Debug,
										  CString csFunctionName,
										  CStringArray* pcsaBody)
{
	CString csLocal;
	
	if ( b_Debug )
	{
		csLocal.Format( "   MsgBox( \"%s\" )", csFunctionName );
		pcsaBody->Add(csLocal);
	}
}


void CAG_EOLE_VT_NODE_VBS::resetVariableFlags()
{
	b_cString=FALSE;
	b_Area=FALSE;
	b_bRet=FALSE;
	b_nStatus=FALSE;
	b_bUpdated=FALSE;
	b_pOIAObject=FALSE;
	b_nType=FALSE;
	b_cText=FALSE;
	b_nCount=FALSE;
	b_nColumn=FALSE;
	b_nRow=FALSE;
	b_bEABs=FALSE;
	b_nCharSet=FALSE;
	b_nHostCodePage=FALSE;
	b_bKeyboardLocked=FALSE;
	b_nModel=FALSE;
	b_nLength=FALSE;
	b_nIdleTime=FALSE;
	b_bAttached=FALSE;
	b_nAttribute=FALSE;
	b_csName=FALSE;
	b_Terminal=FALSE;
	b_nMode=FALSE;
	b_nWait=FALSE;
	b_bConnected=FALSE;
	b_ConnectionObj=FALSE;
	b_ScreenObj=FALSE;
	b_nState=FALSE;
	b_nPort=FALSE;
	b_sKeys=FALSE;
	b_nTimeout=FALSE;
	b_bProcess=FALSE;
	b_nIdle=FALSE;
	b_nOptions=FALSE;
	b_nPage=FALSE;
	b_nEndColumn=FALSE;
	b_nEndRow=FALSE;
	b_nSettleTime=FALSE;
	b_nCloseOption=FALSE;
	b_nHostOS=FALSE;
	b_ftObj=FALSE;
	b_FTScheme=FALSE;
	b_font=FALSE;
	b_nHeight=FALSE;
	b_hostname=FALSE;
	b_bLocalMode=FALSE;
	b_bScreenHeld=FALSE;
	b_settingsPage=FALSE;
	b_settingsTab=FALSE;
	b_bMenuVisible=FALSE;
	b_bSessionQuiet=FALSE;
	b_bSessionSaved=FALSE;
	b_nWidth=FALSE;
	b_hSession=FALSE;
	b_nWindowState=FALSE;
	b_SessName=FALSE;

	b_Debug=FALSE;
}