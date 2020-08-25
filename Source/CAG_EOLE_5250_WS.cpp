// Static Model
#include "stdafx.h"
#include "apigen.h"

#include "CAG_EOLE_5250_WS.h"

CAG_EOLE_5250_WS::CAG_EOLE_5250_WS()
{
	resetVariableFlags();
}


CAG_EOLE_5250_WS::~CAG_EOLE_5250_WS()
{
	
}


void CAG_EOLE_5250_WS::generateHeader(CStringArray* pcsaHeader,
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

	pcsaHeader->Add("' ****************************************************************************");
	pcsaHeader->Add("'             Attachmate 5250 Host OLE Automation");
	pcsaHeader->Add("'                APIGen Windows VBScript Scripting");
	pcsaHeader->Add("'" );
	pcsaHeader->Add("'   This file consists of Windows VBScript commands that drive the Extra! X-treme");
	pcsaHeader->Add("'   ActiveX control.");
	pcsaHeader->Add("'" );
	pcsaHeader->Add("'   After this code is generated it will be necessary for you to double click on");
	pcsaHeader->Add("'   this .vbs file.  You may choose to modify this file in one or more of the ");
	pcsaHeader->Add("'   following ways:");
	pcsaHeader->Add("'   1) Timing issues/race conditions are more common in this type of scripting. So,");
	pcsaHeader->Add("'      a prompt is presented when you run the script that asks for a literal string");
	pcsaHeader->Add("'      that an initial WaitForString call can use in your session to better prepare");
	pcsaHeader->Add("'      the system for the generated automation calls.");
	pcsaHeader->Add("'   2) You may choose to change the 8-second timeout value on the WaitForString call");
	pcsaHeader->Add("'      to a value better suited for your system. Note that the WaitForString call will");
	pcsaHeader->Add("'      return as soon as the search string is found.");
	pcsaHeader->Add("'   3) You can encrypt this file using the Microsoft Script Encoder for Windows");
	pcsaHeader->Add("'      Script Files to prevent users from reading your source code.");
	pcsaHeader->Add("'   4) You can compile it into a script component to selectively expose its functionality");
	pcsaHeader->Add("'      and establish its Windows security credentials.");

	time_t ltime;
	time( &ltime );

	pcsaHeader->Add("'" );
	csViewOutStuff.Format( "'   Generated:   %s", ctime( &ltime ) );
	pcsaHeader->Add(csViewOutStuff);

	pcsaHeader->Add( "" );
	pcsaHeader->Add("' ****************************************************************************");
	pcsaHeader->Add( "" );
	pcsaHeader->Add("Dim System");
	pcsaHeader->Add("Dim Sessions" );
	pcsaHeader->Add("Dim Sess0" );
	pcsaHeader->Add("Dim Sessionname");
	pcsaHeader->Add("Dim Buffer" );
	pcsaHeader->Add("Dim nRow" );
	pcsaHeader->Add("Dim nColumn" );
	pcsaHeader->Add("Dim nPage" );
	pcsaHeader->Add("Dim nIdle" );
	pcsaHeader->Add("Dim nTimeout" );
	pcsaHeader->Add("Dim nOptions" );
	pcsaHeader->Add("Dim nType" );
	pcsaHeader->Add("Dim nEndRow" );
	pcsaHeader->Add("Dim nEndColumn" );
	pcsaHeader->Add("Dim bRet" );

	pcsaBody->Add("" );
	pcsaBody->Add("set System = CreateObject(\"EXTRA.System\")" );
	pcsaBody->Add("set Sessions = System.Sessions" );
	pcsaBody->Add("Set Sess0 = System.ActiveSession" );
	pcsaBody->Add("" );
	pcsaBody->Add("Sessionname = inputbox(\"EXTRA! session to open:\", \"Specify EXTRA! Session\", \"session1.edp\")");
	pcsaBody->Add("if Sessionname = \"\" then");
	pcsaBody->Add(" WScript.Quit(1)");
	pcsaBody->Add("else");
	pcsaBody->Add(" Set Sess0 = Sessions.Open( sessionname )" );
	pcsaBody->Add("end if");
	pcsaBody->Add("" );
	pcsaBody->Add("Buffer = inputbox(\"Please provide a ready state indicator string:\", \"Specify ready indicator\", \"userid\")");
	pcsaBody->Add(" " );
	pcsaBody->Add("' ****************************************************************************");
	pcsaBody->Add("" );

	pcsaBody->Add("");
	pcsaBody->Add("'*** Screen::WaitForString" );
	pcsaBody->Add("nRow = 0" );
	pcsaBody->Add("nColumn = 0" );
	pcsaBody->Add("nPage = 0" );
	pcsaBody->Add("nIdle = 0" );
	pcsaBody->Add("nTimeout = 8000" );
	pcsaBody->Add("nOptions = xRegExp" );
	pcsaBody->Add("nType = 1" );
	pcsaBody->Add("bRet = Sess0.screen.WaitForString(Buffer, nRow, nColumn, nPage, nIdle, nTimeout, nOptions, nType )" );
	pcsaBody->Add("" );


}



/****************************************************************************DC
	Function	:	CAG_EOLE_5250_WS::appendBody()

	Purpose		:	Formats the csaHeader and csaBody string arrays for
					use in output.

	Note		:	This will be written to assume that the parameters are
					entered by the calling module -- defaults or human entered.

*****************************************************************************/
void CAG_EOLE_5250_WS::appendBody(int nFunctionNum,
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

	csViewOutStuff.Format( "'*** %s", csFunctionName );
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

			pcsaBody->Add("nStatus = Sess0.screen.OIA.ConnectionStatus");
		}
		break;
			

		case 1:		// Screen.OIA.ErrorStatus
		{		
			if ( !b_nStatus )
			{
				declareVariable( AG_STATUS, pcsaHeader, &b_nStatus );
			}

			pcsaBody->Add("nStatus = Sess0.screen.OIA.ErrorStatus");  
		}
		break;


		case 2:		// Screen->OIA.Updated
		{
			if ( !b_bUpdated )
			{
				declareVariable( AG_UPDATED, pcsaHeader, &b_bUpdated );
			}

			pcsaBody->Add("bUpdated = Sess0.screen.OIA.Updated");  
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
				pcsaBody->Add("Sess0.screen.OIA.Value = Buffer;");
			}
			else
			{
				pcsaBody->Add("Buffer = Sess0.screen.OIA.Value");
			}
		}
		break;


		case 4:		// Screen.OIA.XStatus
		{
			if ( !b_nStatus )
			{
				declareVariable( AG_STATUS, pcsaHeader, &b_nStatus );
			}

			pcsaBody->Add("nStatus = Sess0.screen.OIA.XStatus");
		}
		break;


	
	// **************************** SCREEN ******************************	
	case 5:		// Screen::Col
		{		
			if ( !b_nColumn )
			{
				declareVariable( AG_COLUMN, pcsaHeader, &b_nColumn );
			}

			pcsaBody->Add("nColumn = Sess0.screen.Col");
		}
		break;


		case 6:		// Screen::Copy
		{		
			pcsaBody->Add("Sess0.screen.Copy");
		}
		break;

		case 7:		// Screen::FieldAttribute
		{			
			if ( !b_nColumn )
			{
				declareVariable( AG_COLUMN, pcsaHeader, &b_nColumn );
			}

			if ( !b_nRow )
			{
				declareVariable( AG_ROW, pcsaHeader, &b_nRow );
			}

			if ( !b_nAttribute )
			{
				declareVariable( AG_ATTRIBUTE, pcsaHeader, &b_nAttribute );
			}

			csViewOutStuff.Format( "nRow = %s", pcsaArguments->GetAt(1) );
			pcsaBody->Add(csViewOutStuff);
			csViewOutStuff.Format( "nColumn = %s", pcsaArguments->GetAt(2) );
			pcsaBody->Add(csViewOutStuff);
			
			pcsaBody->Add("nAttribute = Sess0.screen.FieldAttribute( nRow, nColumn )");
			
		}
		break;			

		case 8:		// Screen::GetString
		{			
			if ( !b_cString )
			{
				declareVariable( AG_STRING, pcsaHeader, &b_cString );			
			}

			if ( !b_nColumn )
			{
				declareVariable( AG_COLUMN, pcsaHeader, &b_nColumn );
			}

			if ( !b_nRow )
			{
				declareVariable( AG_ROW, pcsaHeader, &b_nRow );
			}

			if ( !b_nLength )
			{
				declareVariable( AG_LENGTH, pcsaHeader, &b_nLength );			
			}


			csViewOutStuff.Format( "nRow = %s", pcsaArguments->GetAt(1) );
			pcsaBody->Add(csViewOutStuff);
			csViewOutStuff.Format( "nColumn = %s", pcsaArguments->GetAt(2) );
			pcsaBody->Add(csViewOutStuff);
			csViewOutStuff.Format( "nLength = %s", pcsaArguments->GetAt(3) );
			pcsaBody->Add(csViewOutStuff);

			pcsaBody->Add("Buffer = Sess0.screen.GetString(nRow, nColumn, nLength)");			
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

			csViewOutStuff.Format( "nRow = %s", pcsaArguments->GetAt(1) );
			pcsaBody->Add(csViewOutStuff);
			csViewOutStuff.Format( "nColumn = %s", pcsaArguments->GetAt(2) );
			pcsaBody->Add(csViewOutStuff);
			
			pcsaBody->Add("Sess0.screen.MoveTo nRow, nColumn ");

		}
		break;


		case 10:		// Screen.PutString
		{			
			if ( !b_cString )
			{
				declareVariable( AG_STRING, pcsaHeader, &b_cString );			
			}

			if ( !b_nColumn )
			{
				declareVariable( AG_COLUMN, pcsaHeader, &b_nColumn );
			}

			if ( !b_nRow )
			{
				declareVariable( AG_ROW, pcsaHeader, &b_nRow );
			}

			csViewOutStuff.Format( "Buffer = \"%s\"", pcsaArguments->GetAt(1) );
			pcsaBody->Add(csViewOutStuff);						
			csViewOutStuff.Format( "nRow = %s", pcsaArguments->GetAt(2) );
			pcsaBody->Add(csViewOutStuff);
			csViewOutStuff.Format( "nColumn = %s", pcsaArguments->GetAt(3) );
			pcsaBody->Add(csViewOutStuff);

			pcsaBody->Add("Sess0.screen.PutString Buffer, nRow, nColumn" );
					
		}
		break;
		

		case 11:	// Screen.Row
		{			
			if ( !b_nRow )
			{
				declareVariable( AG_ROW, pcsaHeader, &b_nRow );
			}

			pcsaBody->Add("nRow = Sess0.screen.Row");
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
			

			csViewOutStuff.Format( "Buffer = \"%s\"", pcsaArguments->GetAt(1) );
			pcsaBody->Add(csViewOutStuff);
			csViewOutStuff.Format( "nRow = %s", pcsaArguments->GetAt(2) );
			pcsaBody->Add(csViewOutStuff);
			csViewOutStuff.Format( "nColumn = %s", pcsaArguments->GetAt(3) );
			pcsaBody->Add(csViewOutStuff);	

			pcsaBody->Add("set Area = Sess0.screen.Search(Buffer, nRow, nColumn) " );

		}
		break;


		case 13:	// Screen.SelectAll
		{			
			
			if ( !b_Area )
			{
				declareVariable( AG_AREA, pcsaHeader, &b_Area );
			}
			
			pcsaBody->Add("set Area = Sess0.screen.SelectAll()");
			
		}
		break;

		case 14:	// Screen.SendKeys
		{
			if ( !b_cString )
			{
				declareVariable( AG_STRING, pcsaHeader, &b_cString );			
			}

			csViewOutStuff.Format( "Buffer = \"%s\"", pcsaArguments->GetAt(1) );
			pcsaBody->Add(csViewOutStuff);
			csViewOutStuff.Format( "Sess0.screen.Sendkeys( Buffer )" );
			pcsaBody->Add(csViewOutStuff);
			
		}
		break;



		case 15:	// Screen.Updated
		{
			if ( !b_bUpdated )
			{
				declareVariable( AG_UPDATED, pcsaHeader, &b_bUpdated );
			}

			csViewOutStuff.Format( "  bUpdated = Sess0.screen.Updated" );
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

			csViewOutStuff.Format( "sys.TimeoutValue = 10000   ' 10 seconds (30 is default)" );
			pcsaBody->Add(csViewOutStuff);			
			csViewOutStuff.Format( "nRow = %s", pcsaArguments->GetAt(1) );
			pcsaBody->Add(csViewOutStuff);
			
			csViewOutStuff.Format( "nColumn = %s", pcsaArguments->GetAt(2) );
			pcsaBody->Add(csViewOutStuff);

			if ( 0 != pcsaArguments->GetAt(2).GetLength() && 0 != pcsaArguments->GetAt(3).GetLength() )
			{
				csViewOutStuff.Format( "nEndRow = %s", pcsaArguments->GetAt(3) );
				pcsaBody->Add(csViewOutStuff);
				csViewOutStuff.Format( "nEndColumn = %s", pcsaArguments->GetAt(4) );
				pcsaBody->Add(csViewOutStuff);
			}
			
			pcsaBody->Add("bRet = Sess0.screen.WaitForCursor( nRow, nColumn, nEndRow, nEndColumn )");

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

			csViewOutStuff.Format( "sys.TimeoutValue = 10000   ' 10 seconds (30 is default)" );
			pcsaBody->Add(csViewOutStuff);			
			csViewOutStuff.Format( "nRow = %s", pcsaArguments->GetAt(1) );
			pcsaBody->Add(csViewOutStuff);
			csViewOutStuff.Format( "nColumn = %s", pcsaArguments->GetAt(2) );
			pcsaBody->Add(csViewOutStuff);
			
			pcsaBody->Add( "   bRet = Sess0.screen.WaitForCursorMove( nRow, nColumn )");

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


			csViewOutStuff.Format( "nTimeout = %s", pcsaArguments->GetAt(1));
			pcsaBody->Add(csViewOutStuff);
			csViewOutStuff.Format( "sKeys = \"%s\"", pcsaArguments->GetAt(2));
			pcsaBody->Add(csViewOutStuff);
			csViewOutStuff.Format( "bProcess = %s", pcsaArguments->GetAt(3));
			pcsaBody->Add(csViewOutStuff);

			pcsaBody->Add("sKeys = Sess0.screen.WaitForKeys( nTimeout, sKeys, bProcess )" );
			
		}
		break;

		case 19:  //WaitForStream
		{
			if ( !b_nTimeout )
			{
				declareVariable( AG_TIMEOUT, pcsaHeader, &b_nTimeout );
			}

			if ( !b_nOptions )
			{
				declareVariable( AG_OPTIONS, pcsaHeader, &b_nOptions );
			}

			if ( !b_nIdle )
			{
				declareVariable( AG_IDLE_TIME, pcsaHeader, &b_nIdle );
			}

			if ( !b_cString )
			{
				declareVariable( AG_STRING, pcsaHeader, &b_cString );
			}

			if ( !b_bRet )
			{
				declareVariable( AG_RETURN, pcsaHeader, &b_bRet );
			}

			csViewOutStuff.Format( "Buffer = \"%s\"", pcsaArguments->GetAt(1));
			pcsaBody->Add(csViewOutStuff);
			csViewOutStuff.Format( "nIdle = %s", pcsaArguments->GetAt(2));
			pcsaBody->Add(csViewOutStuff);
			csViewOutStuff.Format( "nTimeout = %s", pcsaArguments->GetAt(3));
			pcsaBody->Add(csViewOutStuff);
			csViewOutStuff.Format( "nOptions = %s", pcsaArguments->GetAt(4));
			pcsaBody->Add(csViewOutStuff);

			pcsaBody->Add("bRet = Sess0.screen.WaitForStream(Buffer, nIdle, nTimeout, nOptions)" );

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


			csViewOutStuff.Format( "Buffer = \"%s\"", pcsaArguments->GetAt(1));
			pcsaBody->Add(csViewOutStuff);
			
			if ( 0 == pcsaArguments->GetAt(2).GetLength())
			{
				csViewOutStuff.Format( "nRow = 1" );
				pcsaBody->Add(csViewOutStuff);
			}
			else
			{
				csViewOutStuff.Format( "nRow = %s", pcsaArguments->GetAt(2));
				pcsaBody->Add(csViewOutStuff);
			}

			if ( 0 == pcsaArguments->GetAt(3).GetLength())
			{
				csViewOutStuff.Format( "nColumn = 1" );
				pcsaBody->Add(csViewOutStuff);
			}
			else
			{
				csViewOutStuff.Format( "nColumn = %s", pcsaArguments->GetAt(3));
				pcsaBody->Add(csViewOutStuff);
			}

			if ( 0 == pcsaArguments->GetAt(4).GetLength())
			{
				csViewOutStuff.Format( "nPage = 0" );
				pcsaBody->Add(csViewOutStuff);
			}
			else
			{
				csViewOutStuff.Format( "nPage = %s", pcsaArguments->GetAt(4));
				pcsaBody->Add(csViewOutStuff);
			}

			pcsaBody->Add("nIdle = 0");

			if ( 0 == pcsaArguments->GetAt(5).GetLength())
			{
				csViewOutStuff.Format( "nTimeout = 5000" );
				pcsaBody->Add(csViewOutStuff);
			}
			else
			{
				csViewOutStuff.Format( "nTimeout = %s", pcsaArguments->GetAt(5));
				pcsaBody->Add(csViewOutStuff);
			}


			csViewOutStuff.Format( "nOptions = %s", pcsaArguments->GetAt(6));
			pcsaBody->Add(csViewOutStuff);

			if ( -1 != pcsaArguments->GetAt(7).Find("Select string") )
			{
				pcsaBody->Add( "nType = 1" );
			}
			else
			{
				pcsaBody->Add( "nType = 2" );
			}


			// if the endrow/endcol arguments are not specified then don't insert them
			if ( 0 != pcsaArguments->GetAt(8).GetLength() || 0 != pcsaArguments->GetAt(9).GetLength() )
			{
				if ( 0 != pcsaArguments->GetAt(8).GetLength() )
				{
					csViewOutStuff.Format( "nEndRow = %s", pcsaArguments->GetAt(8));
					pcsaBody->Add(csViewOutStuff);
				}
				else
				{
					pcsaBody->Add( "   nEndRow = 0;");
				}

				if ( 0 != pcsaArguments->GetAt(9).GetLength() )
				{
					csViewOutStuff.Format( "nEndColumn = %s", pcsaArguments->GetAt(9));
					pcsaBody->Add(csViewOutStuff);
				}
				else
				{
					pcsaBody->Add( "nEndColumn = 0;");
				}

				pcsaBody->Add("bRet = Sess0.screen.WaitForString(Buffer, nRow, nColumn, nPage, nIdle, nTimeout, nOptions, nType, nEndRow, nEndColumn)" );
			}
			else
			{
				pcsaBody->Add("bRet = Sess0.screen.WaitForString(Buffer, nRow, nColumn, nPage, nIdle, nTimeout, nOptions, nType )" );
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


			csViewOutStuff.Format( "nSettleTime = %s", pcsaArguments->GetAt(1));
			pcsaBody->Add(csViewOutStuff);

			pcsaBody->Add("bRet = Sess0.screen.WaitHostQuiet(nSettleTime)" );

		}
		break;

		// **************************** SESSION ******************************
		case 22:	// Session::Activate
		{
			pcsaBody->Add( "   Sess0.Activate");			
			
		}
		break;


		case 23:	// Session::ClearComm
		{
			pcsaBody->Add( "   Sess0.ClearComm");			
		}
		break;

		case 24:	//	Session::ClearHistory
		{
			pcsaBody->Add( "   Sess0.ClearHistory");			
		}
		break;
	
		case 25:	// Session::Close
		{
			pcsaBody->Add( "   Sess0.Close");			
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

			csViewOutStuff.Format( "nCloseOption = %i", nOption );
			pcsaBody->Add(csViewOutStuff);

			pcsaBody->Add( "   Sess0.CloseEx( nCloseOption )");
		}
		break;

		case 27:	// Session::ClosePrintJob
		{
			pcsaBody->Add( "   Sess0.ClosePrintJob");			
		}
		break;

		case 28:	// Session::Connected
		{
			if ( !b_bRet )
			{
				declareVariable( AG_RETURN, pcsaHeader, &b_bRet );
			}

			pcsaBody->Add( "   bRet = Sess0.Connected");			
		}
		break;

		case 29:	// Session::EnlargeFont
		{
			pcsaBody->Add( "   Sess0.EnlargeFont");			
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
					csViewOutStuff.Format( "nFTHostOS = 0"  );
				}
				else if ( -1 != pcsaArguments->GetAt(2).Find("TSO") )
				{
					csViewOutStuff.Format( "nFTHostOS = 1"  );
				}
				else	// CICS
				{
					csViewOutStuff.Format( "nFTHostOS = 2"  );
				}
				pcsaBody->Add(csViewOutStuff);
				pcsaBody->Add( "   Sess0.FileTransferHostOS = nFTHostOS" );
			}
			else
			{
				pcsaBody->Add( "   nFTHostOS = Sess0.FileTransferHostOS" );
			}

		}
		break;

		case 31:	// FileTransferOptions
		{
			if ( !b_ftObj )
			{
				declareVariable( AG_FT_OBJ, pcsaHeader, &b_ftObj );
			}

			pcsaBody->Add("set ftObj = Sess0.FileTransferOptions");
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
				csViewOutStuff.Format( "FTScheme = \"%s\"", pcsaArguments->GetAt(1) );
				pcsaBody->Add(csViewOutStuff);
				pcsaBody->Add( "   Sess0.FileTransferScheme = FTScheme" );	
			}
			else
			{
				//get it
				pcsaBody->Add( "   FTScheme = Sess0.FileTransferScheme" );
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
				csViewOutStuff.Format( "font = \"%s\"", pcsaArguments->GetAt(2) );
				pcsaBody->Add(csViewOutStuff);
				pcsaBody->Add( "   Sess0.Font = font" );	
			}
			else
			{
				//get it
				pcsaBody->Add( "   font = Sess0.Font");
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
				csViewOutStuff.Format( "nHeight = %s", pcsaArguments->GetAt(2) );
				pcsaBody->Add(csViewOutStuff);
				
				pcsaBody->Add( "   Sess0.Height = nHeight");
			}
			else
			{
				//get it
				pcsaBody->Add( "   nHeight = Sess0.Height");
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
				csViewOutStuff.Format( "bScreenHeld = %s", pcsaArguments->GetAt(2) );
				pcsaBody->Add( csViewOutStuff );
				pcsaBody->Add( "   Sess0.HoldScreen = bScreenHeld");

			}
			else
			{
				pcsaBody->Add( "   bScreenHeld = Sess0.HoldScreen");
			}
		}
		break;


		case 36:	// Session::HostName
		{
			if ( !b_hostname )
			{
				declareVariable( AG_HOSTNAME, pcsaHeader, &b_hostname );
			}

			pcsaBody->Add( "   hostname = Sess0.HostName" );
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
				csViewOutStuff.Format( "settingsPage = %s", pcsaArguments->GetAt(1) );
				pcsaBody->Add(csViewOutStuff);

				pcsaBody->Add( "   Sess0.InvokeSettingsDialog( settingsPage )");
			}
			else
			{
				if ( !b_settingsTab )
				{
					declareVariable( AG_SETTINGS_TAB, pcsaHeader, &b_settingsTab );
				}

				csViewOutStuff.Format( "settingsPage = %s", pcsaArguments->GetAt(1) );
				pcsaBody->Add(csViewOutStuff);

				csViewOutStuff.Format( "settingsTab = %s", pcsaArguments->GetAt(2) );
				pcsaBody->Add(csViewOutStuff);

				pcsaBody->Add( "   Sess0.InvokeSettingsDialog( settingsPage, settingsTab )");

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
				csViewOutStuff.Format( "bKeyboardLocked = %s", pcsaArguments->GetAt(2) );
				pcsaBody->Add( csViewOutStuff );
				pcsaBody->Add( "   Sess0.KeyboardLocked = bKeyboardLocked");

			}
			else
			{
				pcsaBody->Add( "   bKeyboardLocked = Sess0.KeyboardLocked");
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
				csViewOutStuff.Format( "cString = \"%s\"", pcsaArguments->GetAt(2) );
				pcsaBody->Add(csViewOutStuff);
				pcsaBody->Add("Sess0.KeyMap=cString");

			}
			else
			{
				
				pcsaBody->Add("cString = Sess0.KeyMap");
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
				csViewOutStuff.Format( "Buffer = \"%s\"", pcsaArguments->GetAt(2) );
				pcsaBody->Add(csViewOutStuff);
				pcsaBody->Add("Sess0.Language = Buffer" );
			}
			else
			{
				pcsaBody->Add( "   Buffer = Sess0.Language");
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
				csViewOutStuff.Format( "bLocalMode = %s", pcsaArguments->GetAt(2) );
				pcsaBody->Add( csViewOutStuff );
				pcsaBody->Add( "   Sess0.Local = bLocalMode");

			}
			else
			{
				pcsaBody->Add( "   bLocalMode = Sess0.Local");
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
				csViewOutStuff.Format( "bMenuVisible = %s", pcsaArguments->GetAt(2) );
				pcsaBody->Add( csViewOutStuff );
				pcsaBody->Add( "   Sess0.Menu = bMenuVisible");

			}
			else
			{
				pcsaBody->Add( "   bMenuVisible = Sess0.Menu");
			}
		}
		break;

		case 43:	// Session::Name
		{
			if ( !b_cString )
			{
				declareVariable( AG_STRING, pcsaHeader, &b_cString );			
			}

			pcsaBody->Add( "   Buffer = Sess0.Name");
		}
		break;

		case 44:	// Session::PrintDisplay
		{
			pcsaBody->Add( "   Sess0.PrintDisplay" );
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
				csViewOutStuff.Format( "bSessionQuiet = %s", pcsaArguments->GetAt(2) );
				pcsaBody->Add( csViewOutStuff );
				pcsaBody->Add( "   Sess0.Quiet = bSessionQuiet");

			}
			else
			{
				pcsaBody->Add( "   bSessionQuiet = Sess0.Quiet");
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
			
			csViewOutStuff.Format( "bProcess = %s", pcsaArguments->GetAt(3) );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "bRet = Sess0.ReceiveFile( \"%s\", \"%s\", bProcess )", pcsaArguments->GetAt(1), pcsaArguments->GetAt(2) );
			pcsaBody->Add(csViewOutStuff);

		}
		break;

		case 47:	// Session::ReduceFont
		{
			csViewOutStuff.Format( "Sess0.ReduceFont" );
			pcsaBody->Add(csViewOutStuff);
		}
		break;


		case 48:	// Session::Reset
		{
			csViewOutStuff.Format( "Sess0.Reset" );
			pcsaBody->Add(csViewOutStuff);
		}
		break;


		case 49:	// Session::Save
		{
			csViewOutStuff.Format( "Sess0.Save" );
			pcsaBody->Add(csViewOutStuff);
		}
		break;


		case 50:	// Session::SaveAs
		{
			csViewOutStuff.Format( "Sess0.SaveAs( \"%s\" )", pcsaArguments->GetAt(1) );
			pcsaBody->Add(csViewOutStuff);
		}
		break;


		case 51:	// Session::Saved
		{
			if ( !b_bSessionSaved )
			{
				declareVariable( AG_SESS_SAVED, pcsaHeader, &b_bSessionSaved );
			}
			
			csViewOutStuff.Format( "bSessionSaved = Sess0.Saved" );
			pcsaBody->Add(csViewOutStuff);
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

			csViewOutStuff.Format( "bProcess = %s", pcsaArguments->GetAt(3) );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "bRet = Sess0.SendFile( \"%s\", \"%s\", bProcess )", pcsaArguments->GetAt(1), pcsaArguments->GetAt(2) );
			pcsaBody->Add(csViewOutStuff);
		}
		break;


		case 53:	// Session::Title
		{
			if ( !b_cString )
			{
				declareVariable( AG_STRING, pcsaHeader, &b_cString );			
			}

			csViewOutStuff.Format( "Buffer = \"%s\"", pcsaArguments->GetAt(1) );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "Sess0.Title( Buffer )");
			pcsaBody->Add(csViewOutStuff);
		}
		break;


		case 54:	// Session::TransferFile
		{
			csViewOutStuff.Format( "Sess0.TransferFile" );
			pcsaBody->Add(csViewOutStuff);
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
				csViewOutStuff.Format( "nType = %s", pcsaArguments->GetAt(2) );
				pcsaBody->Add(csViewOutStuff);
				pcsaBody->Add("Sess0.Type = nType" );
			}
			else
			{
				pcsaBody->Add( "   nType = Sess0.Type");
			}

		}
		break;


		case 56:	// Session::UpdateStatusBar
		{
			if ( !b_cString )
			{
				declareVariable( AG_STRING, pcsaHeader, &b_cString );			
			}

			csViewOutStuff.Format( "Buffer = \"%s\"", pcsaArguments->GetAt(1) );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "Sess0.UpdateStatusBar( Buffer )");
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
				csViewOutStuff.Format( "Sess0.Visible = %s", pcsaArguments->GetAt(2) );
				pcsaBody->Add(csViewOutStuff);
			}
			else
			{
				csViewOutStuff.Format( "bRet = Sess0.Visible" );
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

			csViewOutStuff.Format( "nTimeout = %s", pcsaArguments->GetAt(1) );
			pcsaBody->Add(csViewOutStuff);
			
			csViewOutStuff.Format( "bRet = Sess0.WaitForDisconnect( nTimeout )");
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

			csViewOutStuff.Format( "nTimeout = %s", pcsaArguments->GetAt(1) );
			pcsaBody->Add(csViewOutStuff);
			
			csViewOutStuff.Format( "bRet = Sess0.WaitForTimer( nTimeout, %s );", pcsaArguments->GetAt(2) );
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
				csViewOutStuff.Format( "nWidth = %s", pcsaArguments->GetAt(2) );
				pcsaBody->Add(csViewOutStuff);
				
				csViewOutStuff.Format( "Sess0.Width = nWidth");
				pcsaBody->Add(csViewOutStuff);
			}
			else
			{
				csViewOutStuff.Format( "nWidth = Sess0.Width");
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

			csViewOutStuff.Format( "hSession = Sess0.WindowHandle" );
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
				csViewOutStuff.Format( "nWindowState = %s", pcsaArguments->GetAt(2) );
				pcsaBody->Add(csViewOutStuff);				
				pcsaBody->Add("Sess0.WindowState = nWindowState");
			}
			else
			{
				pcsaBody->Add( "   nWindowState = Sess0.WindowState");
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

			csViewOutStuff.Format( "SessName = \"%s\"", pcsaArguments->GetAt(1) );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "set Sess = Sessions.Open( SessName )");
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
			pcsaBody->Add("Sessions.CloseAll" );
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
				csViewOutStuff.Format( "nTimeout = %s", pcsaArguments->GetAt(2) );
				pcsaBody->Add(csViewOutStuff);

				csViewOutStuff.Format( "sys.TimeoutValue = nTimeout");
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


void CAG_EOLE_5250_WS::finalize(CStringArray* pcsaBody)
{
	pcsaBody->Add("");	
	pcsaBody->Add("'End Script");
	pcsaBody->Add("");	
}

void CAG_EOLE_5250_WS::declareVariable(AG_VARIABLE agVariable,
										CStringArray* pcsaHeader,
										bool* bValue)
{
	CString csLocal;
	*bValue = TRUE;
	
	switch ( agVariable )
	{
		case AG_STRING:
		{
			csLocal.Format( "Dim Buffer");
		}
		break;

		case AG_STATUS:
		{
			csLocal.Format( "Dim nStatus");
		}
		break;

		case AG_UPDATED:
		{
			csLocal.Format( "Dim bUpdated");
		}
		break;

		case AG_BSTR:
		{
			csLocal.Format( "Dim v");
		}
		break;
	
		case AG_ENDCOLUMN:
		{
			csLocal.Format( "Dim nEndColumn");
		}
		break;

		case AG_ENDROW:
		{
			csLocal.Format( "Dim nEndRow");
		}
		break;

		case AG_ROW:
		{
			csLocal.Format( "Dim nRow");
		}
		break;

		case AG_COLUMN:
		{
			csLocal.Format( "Dim nColumn");		
		}
		break;

		case AG_ATTRIBUTE:
		{
			csLocal.Format( "Dim nAttribute");
		}
		break;

		case AG_LENGTH:
		{
			csLocal.Format( "Dim nLength");
		}
		break;

		case AG_VALUE:
		{
			csLocal.Format( "Dim nValue");
		}
		break;

		case AG_RETURN:
		{
			csLocal.Format( "Dim bRet");
		}
		break;

		case AG_CLOSEOPTION:
		{
			csLocal.Format( "Dim nCloseOption");
		}
		break;

		case AG_FT_OBJ:
		{
			csLocal.Format( "Dim ftObj");
		}
		break;

		case AG_HOSTNAME:
		{
			csLocal.Format( "Dim hostname");
		}
		break;

		case AG_HOST_OS:
		{
			csLocal.Format( "Dim nFTHostOS");
		}
		break;

		case AG_HEIGHT:
		{
			csLocal.Format( "Dim nHeight");
		}
		break;

		case AG_LOCALMODE:
		{
			csLocal.Format( "Dim bLocalMode");
		}
		break;

		case AG_SCREEN_HELD:
		{
			csLocal.Format( "Dim bScreenHeld");
		}
		break;

		case AG_SESS_SAVED:
		{
			csLocal.Format( "Dim bSessionSaved");
		}
		break;

		case AG_SESSIONS_CREATED:
		{
			csLocal.Format( "Dim Sessions" );
		}
		break;

		case AG_SESS_OPEN:
		{
			csLocal.Format( "Dim SessName");
		}
		break;


		case AG_SETTLE_TIME:
		{
			csLocal.Format( "Dim nSettleTime");
		}
		break;

		case AG_SESS_QUIET:
		{
			csLocal.Format( "Dim bSessionQuiet");
		}
		break;

		case AG_SETTINGS_PAGE:
		{
			csLocal.Format( "Dim settingsPage");
		}
		break;

		case AG_SETTINGS_TAB:
		{
			csLocal.Format( "Dim settingsTab");
		}
		break;

		case AG_MENU_VISIBLE:
		{
			csLocal.Format( "Dim bMenuVisible");
		}
		break;

		case AG_IDLE_TIME:
		{
			csLocal.Format( "Dim nIdle");
		}
		break;

		case AG_OPTIONS:
		{
			csLocal.Format( "Dim nOptions");
		}
		break;

		case AG_PAGE:
		{
			csLocal.Format( "Dim nPage");
		}
		break;

		case AG_TYPE:
		{
			csLocal.Format( "Dim nType");
		}
		break;

		case AG_TIMEOUT:
		{
			csLocal.Format( "Dim nTimeout");
		}
		break;

		case AG_PROCESS:
		{
			csLocal.Format( "Dim bProcess");
		}
		break;

		case AG_PROCESS_KEYSTROKES:
		{
			csLocal.Format( "Dim sKeys");
		}
		break;

		case AG_WIDTH:
		{
			csLocal.Format( "Dim nWidth");
		}
		break;

		case AG_WINDOW_HANDLE:
		{
			csLocal.Format( "Dim hSession");
			//csLocal.Format( "HANDLE hSession=NULL");
		}
		break;

		case AG_WINDOW_STATE:
		{
			csLocal.Format( "Dim nWindowState");
		}
		break;

		case AG_COUNT:
		{
			csLocal.Format( "Dim nCount");
		}
		break;

		case AG_AREA:
		{
			csLocal.Format( "Dim Area");
		}
		break;

		case AG_FONTNAME:
		{
			csLocal.Format( "Dim font" );
		}
		break;

		case AG_FT_SCHEME:
		{
			csLocal.Format( "Dim FTScheme" );
		}
		break;

		// new stuff
		case AG_NAME:
		{
			csLocal.Format( "Dim csName" );
		}
		break;

		case AG_TERMINAL:
		{
			csLocal.Format( "Dim Terminal" );
		}
		break;

		case AG_OIAOBJ:
		{
			csLocal.Format( "Dim OIAObj" );
		}
		break;

		case AG_TEXT:
		{
			csLocal.Format( "Dim cText" );
		}
		break;

		case AG_EAB:
		{
			csLocal.Format( "Dim bEABs" );
		}
		break;

		case AG_HOST_CHARSET:
		{
			csLocal.Format( "Dim nCharSet" );
		}
		break;

		case AG_HOST_CODEPAGE:
		{
			csLocal.Format( "Dim nHostCodePage" );
		}
		break;

		case AG_KBD_LOCKED:
		{
			csLocal.Format( "Dim bKeyboardLocked" );
		}
		break;

		case AG_MODEL:	
		{
			csLocal.Format( "Dim nModel" );
		}
		break;

		case AG_MODE:
		{
			csLocal.Format( "Dim nMode" );
		}
		break;

		case AG_WAIT:
		{
			csLocal.Format( "Dim nWait" );
		}
		break;

		case AG_ATTACHED:
		{
			csLocal.Format( "Dim bAttached" );
		}
		break;

		case AG_CONNECTED:
		{
			csLocal.Format( "Dim bConnected" );
		}
		break;

		case AG_CONNECTION_OBJ:
		{
			csLocal.Format( "Dim conn" );
		}
		break;

		case AG_SCREEN_OBJ:
		{
			csLocal.Format( "Dim screen" );
		}
		break;

		case AG_STATE:
		{
			csLocal.Format( "Dim nState" );
		}
		break;

		case AG_PORT:
		{
			csLocal.Format( "Dim nPort" );
		}
		break;

	}

	pcsaHeader->Add(csLocal);
	
}

void CAG_EOLE_5250_WS::checkDebug(bool b_Debug,
									   CString csFunctionName,
									   CStringArray* pcsaBody)
{
	CString csLocal;
	
	if ( b_Debug )
	{
		csLocal.Format( "MsgBox( \"%s\" )", csFunctionName );
		pcsaBody->Add(csLocal);
	}
}

void CAG_EOLE_5250_WS::resetVariableFlags()
{
	b_cString=TRUE;
	b_Area=FALSE;
	b_bRet=TRUE;
	b_nStatus=FALSE;
	b_bUpdated=FALSE;
	b_pOIAObject=FALSE;
	b_nType=TRUE;
	b_cText=FALSE;
	b_nCount=FALSE;
	b_nColumn=TRUE;
	b_nRow=TRUE;
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
	b_nTimeout=TRUE;
	b_bProcess=FALSE;
	b_nIdle=TRUE;
	b_nOptions=TRUE;
	b_nPage=TRUE;
	b_nEndColumn=TRUE;
	b_nEndRow=TRUE;
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