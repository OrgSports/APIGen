// Static Model
#include "stdafx.h"
#include "apigen.h"

#include "CAG_EOLE_VT_EBM.h"



CAG_EOLE_VT_EBM::CAG_EOLE_VT_EBM()
{
	resetVariableFlags();
}

CAG_EOLE_VT_EBM::~CAG_EOLE_VT_EBM()
{
	
}



void CAG_EOLE_VT_EBM::generateHeader(CStringArray* pcsaHeader,
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
	
	csViewOutStuff.Format( "' ****************************************************************************");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "'                  Attachmate APIGen EXTRA! Basic Macro");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "'" );
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "'   Description: This is a freestanding EXTRA! Basic macro that was generated");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "'                using the API Generator.");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "'" );
	pcsaHeader->Add(csViewOutStuff);

	time_t ltime;
	time( &ltime );

	csViewOutStuff.Format( "'   Generated:   %s", ctime( &ltime ) );
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "'" );
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "' ****************************************************************************");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "%s", "" );
	pcsaHeader->Add(csViewOutStuff);
	
	csViewOutStuff.Format( "%s", "Dim System As Object");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "%s", "Dim Sessions As Object" );
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "%s", "Dim Sess0 As Object" );
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "%s", "" );
	pcsaHeader->Add(csViewOutStuff);

	// ********** BODY *********
	csViewOutStuff.Format( " " );
	pcsaBody->Add(csViewOutStuff);


	csViewOutStuff.Format( "Sub Main" );
	pcsaBody->Add(csViewOutStuff);

	csViewOutStuff.Format( " " );
	pcsaBody->Add(csViewOutStuff);

	csViewOutStuff.Format( "'  Get the main system object");
	pcsaBody->Add(csViewOutStuff);

	csViewOutStuff.Format( "   Set System = CreateObject(\"EXTRA.System\")");
	pcsaBody->Add(csViewOutStuff);

	csViewOutStuff.Format( "   If (System is Nothing) Then");
	pcsaBody->Add(csViewOutStuff);

	csViewOutStuff.Format( "        Msgbox \"Could not create the EXTRA System object.  Aborting macro playback.\"" );
	pcsaBody->Add(csViewOutStuff);

	csViewOutStuff.Format( "        Stop" );
	pcsaBody->Add(csViewOutStuff);

	csViewOutStuff.Format( "   End If" );
	pcsaBody->Add(csViewOutStuff);

	csViewOutStuff.Format( " " );
	pcsaBody->Add(csViewOutStuff);

	csViewOutStuff.Format( "'   Get the necessary Session Object" );
	pcsaBody->Add(csViewOutStuff);

	csViewOutStuff.Format( "   Set Sess0 = System.ActiveSession" );
	pcsaBody->Add(csViewOutStuff);

	csViewOutStuff.Format( "   If (Sess0 is Nothing) Then" );
	pcsaBody->Add(csViewOutStuff);

	csViewOutStuff.Format( "        Msgbox \"Could not create the Session object.  Aborting macro playback.\"" );
	pcsaBody->Add(csViewOutStuff);

	csViewOutStuff.Format( "        Stop" );
	pcsaBody->Add(csViewOutStuff);

	csViewOutStuff.Format( "   End If" );
	pcsaBody->Add(csViewOutStuff);

	csViewOutStuff.Format( " " );
	pcsaBody->Add(csViewOutStuff);
}



/****************************************************************************DC
	Function	:	CAG_EOLE_VT_EBM::appendBody()

	Purpose		:	Formats the csaHeader and csaBody string arrays for
					use in output.

	Note		:	This will be written to assume that the parameters are
					entered by the calling module -- defaults or human entered.

*****************************************************************************/
void CAG_EOLE_VT_EBM::appendBody(int nFunctionNum,
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

			pcsaBody->Add("     nStatus = Sess0.Screen.OIA.ConnectionStatus");
		}
		break;


		case 1:		// Screen.OIA.ErrorStatus
		{
			if ( !b_nStatus )
			{
				declareVariable( AG_STATUS, pcsaHeader, &b_nStatus );
			}

			pcsaBody->Add("     nStatus = Sess0.Screen.OIA.ErrorStatus" );
		}
		break;


		case 2:		// Screen->OIA.Updated
		{
			if ( !b_bUpdated )
			{
				declareVariable( AG_UPDATED, pcsaHeader, &b_bUpdated );
			}
			
			pcsaBody->Add("     bUpdated = Sess0.Screen.OIA.Updated" );
		}
		break;


		case 3:		// Screen.OIA.Value
		{
			if ( !b_pUtilityBuffer )
			{
				declareVariable( AG_UTILBUFFER, pcsaHeader, &b_pUtilityBuffer );
			}

            if ( "TRUE" == pcsaArguments->GetAt(1) )
			{
				pcsaBody->Add("   Sess0.Screen.OIA.Value = Buffer;");
			}
			else
			{
				pcsaBody->Add("   Buffer = Sess0.Screen.OIA.Value");
			}
		}
		break;


		case 4:		// Screen.OIA.XStatus
		{
			if ( !b_nStatus )
			{
				declareVariable( AG_STATUS, pcsaHeader, &b_nStatus );
			}

			pcsaBody->Add("     nStatus = Sess0.Screen.OIA.XStatus");
		}
		break;


	
	// **************************** SCREEN ******************************	
	case 5:		// Screen::Col
		{
			if ( !b_nColumn )
			{
				declareVariable( AG_COLUMN, pcsaHeader, &b_nColumn );
			}

			pcsaBody->Add("   nColumn = Sess0.Screen.Col");
		}
		break;


		case 6:		// Screen::Copy
		{
			pcsaBody->Add("     Sess0.Screen.SelectAll");
			pcsaBody->Add("     Sess0.Screen.Copy   ' screen copied to clipboard" );
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
			csViewOutStuff.Format( " " );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "   nAttribute = Sess0.Screen.FieldAttribute( nRow, nColumn )");
			pcsaBody->Add(csViewOutStuff);
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

			if ( !b_pUtilityBuffer )
			{
				declareVariable( AG_UTILBUFFER, pcsaHeader, &b_pUtilityBuffer );
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

			csViewOutStuff.Format( " " );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "   Buffer$ = Sess0.Screen.GetString(nRow, nColumn, nLength)");
			pcsaBody->Add(csViewOutStuff);

		}
		break;



		case 9:		// Screen.MoveTo
		{
			if ( !b_nRow )
			{
				declareVariable( AG_ROW, pcsaHeader, &b_nRow );
			}

			if ( !b_nColumn )
			{
				declareVariable( AG_COLUMN, pcsaHeader, &b_nColumn );
			}

			csViewOutStuff.Format( "   nRow = %s", pcsaArguments->GetAt(1) );
			pcsaBody->Add(csViewOutStuff);
			csViewOutStuff.Format( "   nColumn = %s", pcsaArguments->GetAt(2) );
			pcsaBody->Add(csViewOutStuff);
			csViewOutStuff.Format( " " );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "   Sess0.Screen.MoveTo nRow, nColumn ");
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( " " );
			pcsaBody->Add(csViewOutStuff);

		}
		break;


		case 10:		// Screen.PutString
		{
			if ( !b_pUtilityBuffer )
			{
				declareVariable( AG_UTILBUFFER, pcsaHeader, &b_pUtilityBuffer );
			}

			if ( !b_nRow )
			{
				declareVariable( AG_ROW, pcsaHeader, &b_nRow );
			}

			if ( !b_nColumn )
			{
				declareVariable( AG_COLUMN, pcsaHeader, &b_nColumn );
			}

			csViewOutStuff.Format( "   Buffer$ = \"%s\"", pcsaArguments->GetAt(1) );
			pcsaBody->Add(csViewOutStuff);
			csViewOutStuff.Format( "   nRow = %s", pcsaArguments->GetAt(2) );
			pcsaBody->Add(csViewOutStuff);
			csViewOutStuff.Format( "   nColumn = %s", pcsaArguments->GetAt(3) );
			pcsaBody->Add(csViewOutStuff);
			
			csViewOutStuff.Format( " " );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "   Sess0.Screen.PutString Buffer$, nRow, nColumn" );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( " " );
			pcsaBody->Add(csViewOutStuff);

		}
		break;
		

		case 11:	// Screen.Row
		{
			if ( !b_nRow )
			{
				declareVariable( AG_ROW, pcsaHeader, &b_nRow );
			}

			csViewOutStuff.Format( "   nRow = Sess0.Screen.Row");
			pcsaBody->Add(csViewOutStuff);
		}
		break;

		
		case 12:	// Screen.Search  --- XXX Must provide an Area object for return value
		{
			if ( !b_pUtilityBuffer )
			{
				declareVariable( AG_UTILBUFFER, pcsaHeader, &b_pUtilityBuffer );
			}

			if ( !b_nRow )
			{
				declareVariable( AG_ROW, pcsaHeader, &b_nRow );
			}

			if ( !b_nColumn )
			{
				declareVariable( AG_COLUMN, pcsaHeader, &b_nColumn );
			}

			if ( !bAreaObject )
			{
				declareVariable( AG_AREA, pcsaHeader, &bAreaObject );
			}
			
			csViewOutStuff.Format( "   Buffer$ = \"%s\"", pcsaArguments->GetAt(1) );
			pcsaBody->Add(csViewOutStuff);
			csViewOutStuff.Format( "   nRow = %s", pcsaArguments->GetAt(2) );
			pcsaBody->Add(csViewOutStuff);
			csViewOutStuff.Format( "   nColumn = %s", pcsaArguments->GetAt(3) );
			pcsaBody->Add(csViewOutStuff);
			
			csViewOutStuff.Format( " " );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "   set AreaObject = Sess0.Screen.Search Buffer, nRow, nColumn " );
			pcsaBody->Add(csViewOutStuff);
		}
		break;


		case 13:	// Screen.SelectAll
		{
			if ( !bAreaObject )
			{
				declareVariable( AG_AREA, pcsaHeader, &bAreaObject );
			}

			pcsaBody->Add("   set Area = Sess0.Screen.SelectAll()");
		}
		break;

		case 14:	// Screen.SendKeys
		{
			if ( !b_pUtilityBuffer )
			{
				declareVariable( AG_UTILBUFFER, pcsaHeader, &b_pUtilityBuffer );
			}

			csViewOutStuff.Format( "   Buffer$ = \"%s\"", pcsaArguments->GetAt(1) );
			pcsaBody->Add(csViewOutStuff);
			csViewOutStuff.Format( "   Sess0.Screen.Sendkeys( Buffer$ )" );
			pcsaBody->Add(csViewOutStuff);
		}
		break;


		case 15:	// Screen.Updated
		{
			if ( !b_bUpdated )
			{
				declareVariable( AG_UPDATED, pcsaHeader, &b_bUpdated );
			}

			csViewOutStuff.Format( "     bUpdated = Sess0.Screen.Updated" );
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
			
			pcsaBody->Add("   bRet = Sess0.Screen.WaitForCursor( nRow, nColumn, nEndRow, nEndColumn )");

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

			if ( !b_nValue )
			{
				declareVariable( AG_VALUE, pcsaHeader, &b_nValue );
			}

			if ( !b_bRet )
			{
				declareVariable( AG_RETURN, pcsaHeader, &b_bRet );
			}

			
			csViewOutStuff.Format( "     nValue = System.TimeoutValue" );
			pcsaBody->Add(csViewOutStuff);
			csViewOutStuff.Format( "     System.TimeoutValue = 10000   ' 10 seconds" );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( " " );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "   nRow = %s", pcsaArguments->GetAt(1) );
			pcsaBody->Add(csViewOutStuff);
			csViewOutStuff.Format( "   nColumn = %s", pcsaArguments->GetAt(2) );
			pcsaBody->Add(csViewOutStuff);
			
			pcsaBody->Add(" " );
			pcsaBody->Add("   bRet = Sess0.Screen.WaitForCursorMove( nRow, nColumn )");
			pcsaBody->Add("   System.TimeoutValue = nValue   ' Reset to previous" );
			pcsaBody->Add(" " );

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

			pcsaBody->Add("   sKeys = Sess0.screen.WaitForKeys( nTimeout, sKeys, bProcess )" );
			
		}
		break;

		case 19:  //WaitForStream
		{
			if ( !b_pUtilityBuffer )
			{
				declareVariable( AG_UTILBUFFER, pcsaHeader, &b_pUtilityBuffer );
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

			csViewOutStuff.Format("   Buffer$ = \"%s\"", pcsaArguments->GetAt(1));
			pcsaBody->Add(csViewOutStuff);
			csViewOutStuff.Format("   nIdle = %s", pcsaArguments->GetAt(2));
			pcsaBody->Add(csViewOutStuff);
			csViewOutStuff.Format("   nTimeout = %s", pcsaArguments->GetAt(3));
			pcsaBody->Add(csViewOutStuff);
			csViewOutStuff.Format("   nOptions = %s", pcsaArguments->GetAt(4));
			pcsaBody->Add(csViewOutStuff);

			pcsaBody->Add("   bRet = Sess0.screen.WaitForStream(Buffer$, nIdle, nTimeout, nOptions)" );

		}
		break;	


		case 20:	// WaitForString
		{
			if ( !b_pUtilityBuffer )
			{
				declareVariable( AG_UTILBUFFER, pcsaHeader, &b_pUtilityBuffer );
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


			csViewOutStuff.Format("   Buffer$ = \"%s\"", pcsaArguments->GetAt(1));
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

			pcsaBody->Add("   nIdle = 0");

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

				pcsaBody->Add("   bRet = Sess0.screen.WaitForString(Buffer$, nRow, nColumn, nPage, nIdle, nTimeout, nOptions, nType, nEndRow, nEndColumn)" );
			}
			else
			{
				pcsaBody->Add("   bRet = Sess0.screen.WaitForString(Buffer$, nRow, nColumn, nPage, nIdle, nTimeout, nOptions, nType )" );
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

			csViewOutStuff.Format( "   bRet = Sess0.Screen.WaitHostQuiet(nSettleTime)" );
			pcsaBody->Add(csViewOutStuff);
		}
		break;

		// **************************** SESSION ******************************
		case 22:	// Session::Activate
		{
			pcsaBody->Add("   Sess0.Activate");
		}
		break;

		case 23:	// Session::ClearComm
		{
			pcsaBody->Add("   Sess0.ClearComm");
		}
		break;

		case 24:	//	Session::ClearHistory
		{
			pcsaBody->Add("   Sess0.ClearHistory");
		}
		break;

		case 25:	// Session::Close
		{
			pcsaBody->Add("   Sess0.Close");
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

			pcsaBody->Add( "   Sess0.CloseEx( nCloseOption )");
		}
		break;

		case 27:	// Session::ClosePrintJob
		{
			pcsaBody->Add("   Sess0.ClosePrintJob");
		}
		break;

		case 28:	// Session::Connected
		{
			if ( !b_bRet )
			{
				declareVariable( AG_RETURN, pcsaHeader, &b_bRet );
			}

			pcsaBody->Add("   bRet = Sess0.Connected");
		}
		break;

		case 29:	// Session::EnlargeFont
		{
			pcsaBody->Add("   Sess0.EnlargeFont");
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

			pcsaBody->Add("   set ftObj = Sess0.FileTransferOptions");
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
				csViewOutStuff.Format("   font = \"%s\"", pcsaArguments->GetAt(2) );
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
				csViewOutStuff.Format( "   nHeight = %s", pcsaArguments->GetAt(2) );
				pcsaBody->Add(csViewOutStuff);
				
				pcsaBody->Add("   Sess0.Height = nHeight");
			}
			else
			{
				pcsaBody->Add("   nHeight = Sess0.Height");
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
			if ( !b_pUtilityBuffer )
			{
				declareVariable( AG_UTILBUFFER, pcsaHeader, &b_pUtilityBuffer );
			}
			
			csViewOutStuff.Format( "   Buffer$ = Sess0.HostName" );
			pcsaBody->Add(csViewOutStuff);
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

				pcsaBody->Add( "   Sess0.InvokeSettingsDialog( settingsPage )");
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
				csViewOutStuff.Format( "   bKeyboardLocked = %s", pcsaArguments->GetAt(2) );
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
				csViewOutStuff.Format( "   Buffer = \"%s\"", pcsaArguments->GetAt(2) );
				pcsaBody->Add(csViewOutStuff);
				pcsaBody->Add("   Sess0.KeyMap=Buffer");

			}
			else
			{
				
				pcsaBody->Add("   Buffer = Sess0.KeyMap");
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
				pcsaBody->Add("   Sess0.Language = Buffer$" );
			}
			else
			{
				pcsaBody->Add( "   Buffer$ = Sess0.Language");
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
				csViewOutStuff.Format( "   bMenuVisible = %s", pcsaArguments->GetAt(2) );
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
			if ( !b_pUtilityBuffer )
			{
				declareVariable( AG_UTILBUFFER, pcsaHeader, &b_pUtilityBuffer );
			}

			pcsaBody->Add("     Buffer$ = Sess0.Name");
		}
		break;

		case 44:	// Session::PrintDisplay
		{
			pcsaBody->Add("   Sess0.PrintDisplay" );
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
			
			csViewOutStuff.Format( "   bProcess = %s", pcsaArguments->GetAt(3) );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "   bRet = Sess0.ReceiveFile( \"%s\", \"%s\", bProcess )", pcsaArguments->GetAt(1), pcsaArguments->GetAt(2) );
			pcsaBody->Add(csViewOutStuff);

		}
		break;

		case 47:	// Session::ReduceFont
		{
			pcsaBody->Add("   Sess0.ReduceFont" );
		}
		break;


		case 48:	// Session::Reset
		{
			pcsaBody->Add("   Sess0.Reset" );
		}
		break;

		case 49:	// Session::Save
		{
			pcsaBody->Add("   Sess0.Save" );
		}
		break;

		case 50:	// Session::SaveAs
		{
			csViewOutStuff.Format( "   Sess0.SaveAs( \"%s\" )", pcsaArguments->GetAt(1) );
			pcsaBody->Add(csViewOutStuff);
		}
		break;

		case 51:	// Session::Saved
		{
			if ( !b_bSessionSaved )
			{
				declareVariable( AG_SESS_SAVED, pcsaHeader, &b_bSessionSaved );
			}
			pcsaBody->Add("   bSessionSaved = Sess0.Saved" );
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

			csViewOutStuff.Format( "   bRet = Sess0.SendFile( \"%s\", \"%s\", bProcess )", pcsaArguments->GetAt(1), pcsaArguments->GetAt(2) );
			pcsaBody->Add(csViewOutStuff);
		}
		break;

		case 53:	// Session::Title
		{
			if ( !b_pUtilityBuffer )
			{
				declareVariable( AG_UTILBUFFER, pcsaHeader, &b_pUtilityBuffer );
			}

			csViewOutStuff.Format( "   Buffer$ = \"%s\"", pcsaArguments->GetAt(1) );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "   Sess0.Title( Buffer$ )");
			pcsaBody->Add(csViewOutStuff);
		}
		break;

		case 54:	// Session::TransferFile
		{
			pcsaBody->Add("   Sess0.TransferFile" );
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
				pcsaBody->Add("   Sess0.Type = nType" );
			}
			else
			{
				pcsaBody->Add( "   nType = Sess0.Type");
			}

		}
		break;


		case 56:	// Session::UpdateStatusBar
		{
			if ( !b_pUtilityBuffer )
			{
				declareVariable( AG_UTILBUFFER, pcsaHeader, &b_pUtilityBuffer );
			}

			csViewOutStuff.Format( "   Buffer$ = \"%s\"", pcsaArguments->GetAt(1) );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "   Sess0.UpdateStatusBar( Buffer$ )");
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
				csViewOutStuff.Format( "   Sess0.Visible = %s", pcsaArguments->GetAt(2) );
				pcsaBody->Add(csViewOutStuff);
			}
			else
			{
				csViewOutStuff.Format( "   bRet = Sess0.Visible" );
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
			
			csViewOutStuff.Format( "   bRet = Sess0.WaitForDisconnect( nTimeout )");
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
			
			csViewOutStuff.Format( "   bRet = Sess0.WaitForTimer( nTimeout, %s );", pcsaArguments->GetAt(2) );
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
				
				csViewOutStuff.Format( "   Sess0.Width = nWidth");
				pcsaBody->Add(csViewOutStuff);
			}
			else
			{
				csViewOutStuff.Format( "   nWidth = Sess0.Width");
				pcsaBody->Add(csViewOutStuff);
			}
		}
		break;


		case 61:	// Session::WindowHandle	XXX Not working
		{
			if ( !b_bWindowHandle )
			{
				declareVariable( AG_WINDOW_HANDLE, pcsaHeader, &b_bWindowHandle );
			}

			csViewOutStuff.Format( "   hSession = Sess0.WindowHandle" );
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
				pcsaBody->Add("   Sess0.WindowState = nWindowState");
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

			if ( !b_SessionOpen )
			{
				declareVariable( AG_SESS_OPEN, pcsaHeader, &b_SessionOpen );
			}

			if ( !b_bSessionsCreated )
			{
				declareVariable( AG_SESSIONS_CREATED, pcsaBody, &b_bSessionsCreated );
			}


			csViewOutStuff.Format( "   SessName = \"%s\"", pcsaArguments->GetAt(1) );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "   Set Sess0 = Sessions.Open( SessName )");
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( " " );
			pcsaBody->Add(csViewOutStuff);

		}
		break;

		case 64:	// Sessions::Count
		{
			if ( !b_nCount )
			{
				declareVariable( AG_COUNT, pcsaHeader, &b_nCount );
			}

			if ( !b_bSessionsCreated )
			{
				declareVariable( AG_SESSIONS_CREATED, pcsaBody, &b_bSessionsCreated );
			}

			csViewOutStuff.Format( "   nCount = Sessions.Count" );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( " " );
			pcsaBody->Add(csViewOutStuff);

		}
		break;


		case 65:	// Sessions::CloseAll
		{
			if ( !b_bSessionsCreated )
			{
				declareVariable( AG_SESSIONS_CREATED, pcsaBody, &b_bSessionsCreated );
			}

			csViewOutStuff.Format( "   Sessions.CloseAll" );
			pcsaBody->Add(csViewOutStuff);
		}
		break;

		
		// **************************** SYSTEM ******************************

		case 66:	// System::ActiveSession
		{
			pcsaBody->Add("   Set Sess0 = System.ActiveSession" );
		}
		break;

		case 67:	// System::Name
		{
			if ( !b_pUtilityBuffer )
			{
				declareVariable( AG_UTILBUFFER, pcsaHeader, &b_pUtilityBuffer );
			}

			pcsaBody->Add("   Buffer$ = System.Name");
		}
		break;

		case 68:	// System::Quit
		{
			pcsaBody->Add("   System.Quit" );
		}
		break;

		case 69:	// System::Time	XXX  AT RUNTIME WE GET A "NO METHOD" MESSAGE   FIXED 1/21 -- PLEASE TEST
		{
			if ( !b_pUtilityBuffer )
			{
				declareVariable( AG_UTILBUFFER, pcsaHeader, &b_pUtilityBuffer );
			}

			pcsaBody->Add("   Buffer$ = System.Time()");
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

				csViewOutStuff.Format( "   System.TimeoutValue = nTimeout");
				pcsaBody->Add(csViewOutStuff);
			}
			else
			{
				csViewOutStuff.Format( "   nTimeout = System.TimeoutValue");
				pcsaBody->Add(csViewOutStuff);
			}
		}
		break;

		case 71:	// System::Version
		{
			if ( !b_pUtilityBuffer )
			{
				declareVariable( AG_UTILBUFFER, pcsaHeader, &b_pUtilityBuffer );
			}

			pcsaBody->Add("   Buffer$ = System.Version");
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


void CAG_EOLE_VT_EBM::finalize(CStringArray* pcsaBody)
{
	CString csLocal;

	csLocal.Format("%s", " " );
	pcsaBody->Add(csLocal);

	csLocal.Format("%s", "End Sub" );
	pcsaBody->Add(csLocal);

	csLocal.Format("%s", " " );
	pcsaBody->Add(csLocal);

}





void CAG_EOLE_VT_EBM::declareVariable(AG_VARIABLE agVariable,
										CStringArray* pcsaHeader,
										bool* bValue)
{
	CString csLocal;
	*bValue = TRUE;
	
	switch ( agVariable )
	{
		case AG_STATUS:
		{
			csLocal.Format( "Dim nStatus As Integer");
		}
		break;

		case AG_UPDATED:
		{
			csLocal.Format( "Dim bUpdated As Integer");
		}
		break;

		case AG_UTILBUFFER:
		{
			csLocal.Format( "Dim Buffer As String");
		}
		break;

		case AG_BSTR:
		{
			csLocal.Format( "Dim v As String");
		}
		break;

		case AG_ROW:
		{
			csLocal.Format( "Dim nRow As Integer");
		}
		break;

		case AG_COLUMN:
		{
			csLocal.Format( "Dim nColumn As Integer");		
		}
		break;

		case AG_ATTRIBUTE:
		{
			csLocal.Format( "Dim nAttribute As Integer");
		}
		break;

		case AG_LENGTH:
		{
			csLocal.Format( "Dim nLength As Integer");
		}
		break;

		case AG_VALUE:
		{
			csLocal.Format( "Dim nValue As Integer");
		}
		break;

		case AG_RETURN:
		{
			csLocal.Format( "Dim bRet As Integer");
		}
		break;

		case AG_CLOSEOPTION:
		{
			csLocal.Format( "Dim nCloseOption As Integer");
		}
		break;

		case AG_HOST_OS:
		{
			csLocal.Format( "Dim nFTHostOS As Integer");
		}
		break;

		case AG_HEIGHT:
		{
			csLocal.Format( "Dim nHeight As Integer");
		}
		break;

		case AG_LOCALMODE:
		{
			csLocal.Format( "Dim bLocalMode As Integer");
		}
		break;

		case AG_SESS_SAVED:
		{
			csLocal.Format( "Dim bSessionSaved As Integer");
		}
		break;

		case AG_SESSIONS_CREATED:
		{
			csLocal.Format( "Dim Sessions As New ExtraSessions" );
		}
		break;

		case AG_SESS_OPEN:
		{
			csLocal.Format( "Dim SessName As String");
		}
		break;


		case AG_SETTLE_TIME:
		{
			csLocal.Format( "Dim nSettleTime As Integer");
		}
		break;

		case AG_SESS_QUIET:
		{
			csLocal.Format( "Dim bSessionQuiet As Integer");
		}
		break;

		case AG_MENU_VISIBLE:
		{
			csLocal.Format( "Dim bMenuVisible As Integer");
		}
		break;

		case AG_TYPE:
		{
			csLocal.Format( "Dim nType As Integer");
		}
		break;

		case AG_TIMEOUT:
		{
			csLocal.Format( "Dim nTimeout As Integer");
		}
		break;

		case AG_PROCESS_KEYSTROKES:
		{
			csLocal.Format( "Dim bProcessKeystrokes As Integer");
		}
		break;

		case AG_WIDTH:
		{
			csLocal.Format( "Dim nWidth As Integer");
		}
		break;

		case AG_WINDOW_HANDLE:
		{
			csLocal.Format( "Dim hSession As Integer");
			//csLocal.Format( "   HANDLE hSession=NULL;");
		}
		break;

		case AG_WINDOW_STATE:
		{
			csLocal.Format( "Dim nWindowState As Integer");
		}
		break;

		case AG_COUNT:
		{
			csLocal.Format( "Dim nCount As Integer");
		}
		break;

		case AG_AREA:
		{
			csLocal.Format( "Dim Area As Object");
		}
		break;
	}

	pcsaHeader->Add(csLocal);

}


void CAG_EOLE_VT_EBM::checkDebug(bool b_Debug,
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

void CAG_EOLE_VT_EBM::resetVariableFlags()
{
	b_csSessionName = FALSE;
	b_SessionOpen = FALSE;
	b_nAttribute = FALSE;
	b_nStatus = FALSE;
	b_bUpdated = FALSE;
	b_nRow = FALSE;
	b_nColumn = FALSE;
	b_nLength = FALSE;
	b_pUtilityBuffer = FALSE;
	b_nPosition = FALSE;
	b_nValue = FALSE;
	bAreaObject = FALSE;
	b_bRet = FALSE;
	b_nCloseOption = FALSE;
	b_nFTHostOS = FALSE;
	b_nHeight = FALSE;
	b_nWidth = FALSE;
	b_bLocalMode = FALSE;
	b_bMenuVisible = FALSE;
	b_bSessionQuiet = FALSE;
	b_bSessionSaved = FALSE;
	b_bSessionsCreated = FALSE;
	b_nType = FALSE;
	b_nTimeout = FALSE;
	b_bWindowHandle = FALSE;
	b_nWindowState = FALSE;
	b_nCount = FALSE;
	b_nIdle=FALSE;
	b_nOptions=FALSE;
	b_nPage=FALSE;
	b_nEndColumn=FALSE;
	b_nEndRow=FALSE;
	b_sKeys=FALSE;
	b_bProcess=FALSE;

	b_Debug=FALSE;
}