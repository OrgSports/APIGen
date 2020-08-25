// Static Model
#include "stdafx.h"
#include "apigen.h"

#include "CAG_EOLE_3270_VB6.h"

CAG_EOLE_3270_VB6::CAG_EOLE_3270_VB6()
{
	resetVariableFlags();	
}

CAG_EOLE_3270_VB6::~CAG_EOLE_3270_VB6()
{
	
}


void CAG_EOLE_3270_VB6::generateHeader(CStringArray* pcsaHeader,
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
	
	csViewOutStuff.Format( "%s", "' ****************************************************************************");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "%s", "'             Attachmate 3270 Host OLE Automation");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "%s", "'                   APIGen Visual Basic 6.0");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "%s", "'" );
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "%s", "'   This file consists of a \"Main\" subroutine prepared for Visual Basic 6.0");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "%s", "'   that uses Attachmate's Extra! OLE Automation interface to perform the");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "%s", "'    functions that were specified while running the API Generator application.");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "'" );
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "%s", "'   To use this code in your own project: ");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "%s", "'     1. Create and save a new \"Standard EXE\" project.");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "%s", "'     2. In the project \"Properties\" (Project menu), on the \"General\" tab,  ");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "%s", "'        change the \"Startup Object\" to \"Sub Main\". ");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "%s", "'     3. In the project \"References\" (Project menu), ");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "%s", "'        select \"Attachmate EXTRA! x.x Object Library\". " );
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "%s", "'     4. Save this generated code to a file with a \".bas\" extension, and ");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "%s", "'        add this \".bas\" file (containing your new \"Sub Main\") to your project. ");
	pcsaHeader->Add(csViewOutStuff);

	time_t ltime;
	time( &ltime );

	csViewOutStuff.Format( "'" );
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "'   Generated:   %s", ctime( &ltime ) );
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "'" );
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "%s", "' ****************************************************************************");
	pcsaHeader->Add(csViewOutStuff);

	pcsaHeader->Add("");
	
	pcsaHeader->Add("Sub Main");
	pcsaHeader->Add(" ");	
	
	pcsaBody->Add("   Dim sys As New ExtraSystem");
	pcsaBody->Add("   Dim sess As ExtraSession");
	pcsaBody->Add("   Dim area As ExtraArea       'returned by Search, Select, etc."); 
	pcsaBody->Add(" ");
	pcsaBody->Add("   If sys.ActiveSession Is Nothing Then");
	pcsaBody->Add("      Debug.Print \"No ActiveSession - will try to open one\"");
	pcsaBody->Add("      Set sess = sys.Sessions.Open()    'open a session if we don't already have one");     
	pcsaBody->Add("      If sess Is Nothing Then");
	pcsaBody->Add("         Debug.Print \"Sessions.Open failed, or you canceled the file-open dialog\" ");
	pcsaBody->Add("         Exit Sub");
	pcsaBody->Add("      Else");
	pcsaBody->Add("         sess.Visible = True");
	pcsaBody->Add("         sess.Screen.WaitHostQuiet 500");
	pcsaBody->Add("      Debug.Print \"Opened session: \" & sess.Name");
	pcsaBody->Add("      End If");
	pcsaBody->Add("   Else");
	pcsaBody->Add("      Set sess = sys.ActiveSession   'use session that's already open");
	pcsaBody->Add("      Debug.Print \"Using ActiveSession named: \" & sess.Name");
	pcsaBody->Add("   End If");
	pcsaBody->Add(" ");	
}



/****************************************************************************DC
	Function	:	CAG_EOLE_3270_VB6::appendBody()

	Purpose		:	Formats the csaHeader and csaBody string arrays for
					use in output.

	Note		:	This will be written to assume that the parameters are
					entered by the calling module -- defaults or human entered.

*****************************************************************************/
void CAG_EOLE_3270_VB6::appendBody(int nFunctionNum,
								   bool bPromptForValues,
								   CStringArray* pcsaArguments,
								   CStringArray* pcsaHeader,
								   CStringArray* pcsaBody)
{
	CString csViewOutStuff;
	CString csFunctionName, csFunctionNum, csString, csStringLength, csRetCode;

	
	

	csFunctionName = pcsaArguments->GetAt( 0 );

	csViewOutStuff.Format( " " );
	pcsaBody->Add(csViewOutStuff);

	csViewOutStuff.Format( "'   *** %s", csFunctionName );
	pcsaBody->Add(csViewOutStuff);

	CString	csLocal;

	switch ( nFunctionNum )
	{
		
		// **************************** OIA ******************************		
		case 0:		// Screen.OIA.ConnectionStatus
		{		
			pcsaBody->Add("   nStatus% = sess.Screen.OIA.ConnectionStatus");
			pcsaBody->Add("   Debug.Print \"OIA.ConnectionStatus: \" & Str(nStatus%)");			
		}
		break;
			

		case 1:		// Screen.OIA.ErrorStatus
		{		
			pcsaBody->Add("   nStatus% = sess.Screen.OIA.ErrorStatus");  
			pcsaBody->Add("   Debug.Print \"OIA.ErrorStatus: \" & Str(nStatus%)");			
		}
		break;


		case 2:		// Screen->OIA.Updated
		{
			pcsaBody->Add("   bUpdated% = sess.Screen.OIA.Updated");  
			pcsaBody->Add("   Debug.Print \"OIA.Updated: \" & Str(bUpdated%)");			
		}
		break;


		case 3:		// Screen.OIA.Value
		{		
            pcsaBody->Add("   Buffer$ = sess.Screen.OIA.Value");
			pcsaBody->Add("   Debug.Print \"OIA.Value: \" & Buffer$");			
		}
		break;


		case 4:		// Screen.OIA.XStatus
		{
			pcsaBody->Add("   nStatus% = sess.Screen.OIA.XStatus");
			pcsaBody->Add("   Debug.Print \"OIA.XStatus: \" & Str(nStatus%)");
		}
		break;


	
	// **************************** SCREEN ******************************	
	case 5:		// Screen::Col
		{		
			pcsaBody->Add("   nColumn% = sess.Screen.Col");
			pcsaBody->Add("   Debug.Print \"Screen.Col: \" & Str(nColumn%)");
		}
		break;


		case 6:		// Screen::Copy
		{		
			pcsaBody->Add("   sess.Screen.Copy");
			pcsaBody->Add("   Debug.Print \"Invoked Screen.Copy\"");
		}
		break;

		case 7:		// Screen::FieldAttribute
		{			
			
			csViewOutStuff.Format( "   nRow%% = %s", pcsaArguments->GetAt(1) );
			pcsaBody->Add(csViewOutStuff);
			csViewOutStuff.Format( "   nColumn%% = %s", pcsaArguments->GetAt(2) );
			pcsaBody->Add(csViewOutStuff);
			
			pcsaBody->Add("   nAttribute% = sess.Screen.FieldAttribute( nRow%, nColumn% )");
			pcsaBody->Add("   Debug.Print \"Screen.FieldAttribute: \" & Str(nAttribute%)");
			
		}
		break;			

		case 8:		// Screen::GetString
		{			
			csViewOutStuff.Format( "   nRow%% = %s", pcsaArguments->GetAt(1) );
			pcsaBody->Add(csViewOutStuff);
			csViewOutStuff.Format( "   nColumn%% = %s", pcsaArguments->GetAt(2) );
			pcsaBody->Add(csViewOutStuff);
			csViewOutStuff.Format( "   nLength%% = %s", pcsaArguments->GetAt(3) );
			pcsaBody->Add(csViewOutStuff);

			pcsaBody->Add("   Buffer$ = sess.Screen.GetString(nRow%, nColumn%, nLength%)");			
			pcsaBody->Add("   Debug.Print \"Screen.GetString: \" & Buffer$");
		}
		break;


		case 9:		// Screen.MoveTo
		{			
			csViewOutStuff.Format( "   nRow%% = %s", pcsaArguments->GetAt(1) );
			pcsaBody->Add(csViewOutStuff);
			csViewOutStuff.Format( "   nColumn%% = %s", pcsaArguments->GetAt(2) );
			pcsaBody->Add(csViewOutStuff);
			
			pcsaBody->Add("   sess.Screen.MoveTo nRow%, nColumn% ");
			pcsaBody->Add("   Debug.Print \"Invoked Screen.MoveTo\" ");

		}
		break;


		case 10:		// Screen.PutString
		{			
			csViewOutStuff.Format( "   nRow%% = %s", pcsaArguments->GetAt(1) );
			pcsaBody->Add(csViewOutStuff);
			csViewOutStuff.Format( "   nColumn%% = %s", pcsaArguments->GetAt(2) );
			pcsaBody->Add(csViewOutStuff);
			csViewOutStuff.Format( "   Buffer$ = \"%s\"", pcsaArguments->GetAt(3) );
			pcsaBody->Add(csViewOutStuff);						

			pcsaBody->Add("   sess.Screen.PutString Buffer$, nRow%, nColumn%" );
			pcsaBody->Add("   Debug.Print \"Invoked Screen.PutString\" ");
					
		}
		break;
		

		case 11:	// Screen.Row
		{			

			pcsaBody->Add("   nRow% = sess.Screen.Row");
			pcsaBody->Add("   Debug.Print \"Screen.Row: \" & Str(nRow%)");
		}
		break;

		
		case 12:	// Screen.Search  
		{
			

			csViewOutStuff.Format( "   nRow%% = %s", pcsaArguments->GetAt(1) );
			pcsaBody->Add(csViewOutStuff);
			csViewOutStuff.Format( "   nColumn%% = %s", pcsaArguments->GetAt(2) );
			pcsaBody->Add(csViewOutStuff);	
			csViewOutStuff.Format( "   sSearchStr$ = \"%s\"", pcsaArguments->GetAt(3) );
			pcsaBody->Add(csViewOutStuff);

			pcsaBody->Add("   Set area = sess.Screen.Search(sSearchStr$, nRow%, nColumn%) " );
			pcsaBody->Add("   If area.Value = \"\" Then" );
			pcsaBody->Add("      Debug.Print \"Screen.Search: search string not found\"");
			pcsaBody->Add("   Else");
			pcsaBody->Add("      Debug.Print \"Screen.Search: search string found at row \" & Str(area.Top) & \" column \" & Str(area.Left)");
			pcsaBody->Add("   End If");

		}
		break;


		case 13:	// Screen.SelectAll
		{			
			
			pcsaBody->Add("   Set area = sess.Screen.SelectAll()");
			pcsaBody->Add("   If area Is Nothing Then");
			pcsaBody->Add("      Debug.Print \"Screen.SelectAll failed!\"");
			pcsaBody->Add("   Else");
			pcsaBody->Add("      Debug.Print \"Invoked Screen.SelectAll\"");
			pcsaBody->Add("   End If");
			
		}
		break;

		case 14:	// Screen.SendKeys
		{
			
			csViewOutStuff.Format( "   Buffer$ = \"%s\"", pcsaArguments->GetAt(1) );
			pcsaBody->Add(csViewOutStuff);
			csViewOutStuff.Format( "   sess.Screen.Sendkeys( Buffer$ )" );
			pcsaBody->Add(csViewOutStuff);
			pcsaBody->Add("   Debug.Print \"Invoked Screen.SendKeys\"");
			
		}
		break;



		case 15:	// Screen.Updated
		{
			

			csViewOutStuff.Format( "     bUpdated%% = sess.Screen.Updated" );
			pcsaBody->Add(csViewOutStuff);
			pcsaBody->Add("   Debug.Print \"Screen.Updated: \" & Str(bUpdated%)");
			

		}
		break;


		case 16:	// WaitForCursor
		case 17:	// WaitForCursorMove
		{
									
			csViewOutStuff.Format( "     sys.TimeoutValue = 10000   ' 10 seconds (30 is default)" );
			pcsaBody->Add(csViewOutStuff);			
			csViewOutStuff.Format( "   nRow%% = %s", pcsaArguments->GetAt(1) );
			pcsaBody->Add(csViewOutStuff);
			csViewOutStuff.Format( "   nColumn%% = %s", pcsaArguments->GetAt(2) );
			pcsaBody->Add(csViewOutStuff);
			
			if ( nFunctionNum == 16 )
			{
				pcsaBody->Add("   bRet% = sess.Screen.WaitForCursor( nRow%, nColumn% )");
				pcsaBody->Add("   Debug.Print \"Screen.WaitForCursor: \" & Str(bRet%)");
			}
			else	// 17
			{
				pcsaBody->Add( "   bRet% = sess.Screen.WaitForCursorMove( nRow%, nColumn% )");
				pcsaBody->Add("   Debug.Print \"Screen.WaitForCursorMove: \" & Str(bRet%)");
			}						

		}
		break;


		

		case 18:	// WaitForKeys
		{
			
			csViewOutStuff.Format("   nTimeout%% = %s", pcsaArguments->GetAt(1));
			pcsaBody->Add(csViewOutStuff);
			csViewOutStuff.Format("   sKeys$ = \"%s\"", pcsaArguments->GetAt(2));
			pcsaBody->Add(csViewOutStuff);
			csViewOutStuff.Format("   bProcess%% = %s", pcsaArguments->GetAt(3));
			pcsaBody->Add(csViewOutStuff);

			pcsaBody->Add("   retkeys$ = sess.Screen.WaitForKeys( nTimeout%, sKeys$, bProcess%)" );
			pcsaBody->Add("   Debug.Print \"Screen.WaitForKeys: \" & retkeys$");
			
		}
		break;

		case 19:  //WaitForStream
		{
			csViewOutStuff.Format("   sText$ = \"%s\"", pcsaArguments->GetAt(1));
			pcsaBody->Add(csViewOutStuff);
			csViewOutStuff.Format("   nIdle%% = %s", pcsaArguments->GetAt(2));
			pcsaBody->Add(csViewOutStuff);
			csViewOutStuff.Format("   nTimeout%% = %s", pcsaArguments->GetAt(3));
			pcsaBody->Add(csViewOutStuff);
			csViewOutStuff.Format("   nOptions%% = %s", pcsaArguments->GetAt(4));
			pcsaBody->Add(csViewOutStuff);

			pcsaBody->Add("   bRet% = sess.Screen.WaitForStream(sText$, nIdle%, nTimeout%, nOptions%)" );
			pcsaBody->Add("   Debug.Print \"Screen.WaitForStream: \" & Str(bRet%)" );

		}
		break;	


		case 20:	// WaitForString
		{
			csViewOutStuff.Format("   sText$ = \"%s\"", pcsaArguments->GetAt(1));
			pcsaBody->Add(csViewOutStuff);
			csViewOutStuff.Format("   nRow%% = %s", pcsaArguments->GetAt(2));
			pcsaBody->Add(csViewOutStuff);
			csViewOutStuff.Format("   nColumn%% = %s", pcsaArguments->GetAt(3));
			pcsaBody->Add(csViewOutStuff);
			csViewOutStuff.Format("   nPage%% = %s", pcsaArguments->GetAt(4));
			pcsaBody->Add(csViewOutStuff);
			csViewOutStuff.Format("   nIdle%% = %s", pcsaArguments->GetAt(5));
			pcsaBody->Add(csViewOutStuff);
			csViewOutStuff.Format("   nTimeout%% = %s", pcsaArguments->GetAt(6));
			pcsaBody->Add(csViewOutStuff);
			csViewOutStuff.Format("   nOptions%% = %s", pcsaArguments->GetAt(7));
			pcsaBody->Add(csViewOutStuff);
			csViewOutStuff.Format("   nType%% = %s", pcsaArguments->GetAt(8));
			pcsaBody->Add(csViewOutStuff);
			csViewOutStuff.Format("   nEndRow%% = %s", pcsaArguments->GetAt(9));
			pcsaBody->Add(csViewOutStuff);
			csViewOutStuff.Format("   nEndColumn%% = %s", pcsaArguments->GetAt(10));
			pcsaBody->Add(csViewOutStuff);

			pcsaBody->Add("   bRet% = sess.Screen.WaitForString(sText$, nRow%, nColumn%, nPage%, nIdle%, nTimeout%, nOptions%, nType%, nEndRow%, nEndColumn%)" );
			pcsaBody->Add("   Debug.Print \"Screen.WaitForString: \" & Str(bRet%)" );

		}
		break;	

		case 21:	// WaitHostQuiet
		{
			csViewOutStuff.Format("   nSettleTime%% = %s", pcsaArguments->GetAt(1));
			pcsaBody->Add(csViewOutStuff);

			pcsaBody->Add("   bRet% = sess.Screen.WaitHostQuiet(nSettleTime%)" );
			pcsaBody->Add("   Debug.Print \"Screen.WaitHostQuiet: \" & Str(bRet%)");
			

		}
		break;

		// **************************** SESSION ******************************
		case 22:	// Session::Activate
		{
			pcsaBody->Add( "   sess.Activate");			
			pcsaBody->Add( "   Debug.Print \"Invoked Session.Activate\"" );
			
		}
		break;


		case 23:	// Session::ClearComm
		{
			pcsaBody->Add( "   sess.ClearComm");			
			pcsaBody->Add( "   Debug.Print \"Invoked Session.ClearComm\"" );

			
		}
		break;

		case 24:	//	Session::ClearHistory
		{
			pcsaBody->Add( "   sess.ClearHistory");			
			pcsaBody->Add( "   Debug.Print \"Invoked Session.ClearHistory\"" );
		}
		break;

		
		

	
		case 25:	// Session::Close
		{
			pcsaBody->Add( "   sess.Close");			
			pcsaBody->Add( "   Debug.Print \"Invoked Session.Close\"" );

		}
		break;


		case 26:	// Session::CloseEx
		{
			
			

			csViewOutStuff.Format( "   nCloseOption%% = %s", pcsaArguments->GetAt(1) );
			pcsaBody->Add(csViewOutStuff);

			pcsaBody->Add( "   sess.CloseEx( nCloseOption% )");
			pcsaBody->Add( "   Debug.Print \"Invoked Session.CloseEx\"" );

		

		}
		break;


		case 27:	// Session::ClosePrintJob
		{
			pcsaBody->Add( "   sess.ClosePrintJob");			
			pcsaBody->Add( "   Debug.Print \"Invoked Session.ClosePrintJob\"" );

		}
		break;

		case 28:	// Session::Connected
		{
			
			pcsaBody->Add( "   bRet% = sess.Connected");			
			pcsaBody->Add( "   Debug.Print \"Session.Connected: \" & Str(bRet%)");

		}
		break;

		case 29:	// Session::EnlargeFont
		{
			pcsaBody->Add( "   sess.EnlargeFont");			
			pcsaBody->Add( "   Debug.Print \"Invoked Session.EnlargeFont\"" );
		}
		break;


		case 30:	// Session::FileTransferHostOS
		{
			csViewOutStuff.Format( "   nHostOS%% = %s", pcsaArguments->GetAt(1) );
			pcsaBody->Add(csViewOutStuff);

			pcsaBody->Add( "   sess.FileTransferHostOS = nHostOS%" );
			pcsaBody->Add( "   Debug.Print \"Set the Session.FileTransferHostOS: \" & Str(nHostOS%)");
		}
		break;

		case 31:	// FileTransferOptions
		{
			pcsaBody->Add("   Dim fto as ExtraFileTransfer");
			pcsaBody->Add("   Set fto = sess.FileTransferOptions");
			pcsaBody->Add("   If fto Is Nothing Then");
			pcsaBody->Add("      Debug.Print \"Failed to retrieve valid File Transfer Options object.\"");
			pcsaBody->Add("   Else");
			pcsaBody->Add("      Debug.Print \"Retrieved a valid File Transfer Options object.\"");
			pcsaBody->Add("   End If");
		}
		break;

		case 32:	// Session::FileTransferScheme
		{
			CString csSetFTScheme;
			csSetFTScheme= pcsaArguments->GetAt(1);
			if ( csSetFTScheme.Find( "TRUE", 0 ) != -1 )
			{
				//set it
				csViewOutStuff.Format("   FTScheme$ = \"%s\"", pcsaArguments->GetAt(2) );
				pcsaBody->Add(csViewOutStuff);

				pcsaBody->Add( "   sess.FileTransferScheme = FTScheme$" );	
				pcsaBody->Add( "   Debug.Print \"Set Session.FileTransferScheme\"");
			}
			else
			{
				//get it

				pcsaBody->Add( "   FTScheme$ = sess.FileTransferScheme" );
				pcsaBody->Add( "   Debug.Print \"Get Session.FileTransferScheme: \" & Str(FTScheme$)");

			}

		}
		break;


		case 33:	// Session::Font
		{
			
			csViewOutStuff.Format( "   font$ = sess.Font");
			pcsaBody->Add( "   Debug.Print \"Session.Font: \" & font$");

		}
		break;


		case 34:	// Session::Height
		{
			
			if ( pcsaArguments->GetAt(1) == "TRUE" )
			{
				//set it
				csViewOutStuff.Format( "   nHeight%% = %s", pcsaArguments->GetAt(2) );
				pcsaBody->Add(csViewOutStuff);
				
				pcsaBody->Add( "   sess.Height = nHeight%");
				pcsaBody->Add( "   Debug.Print \"Set Session.Height\"");
			}
			else
			{
				//get it

				pcsaBody->Add( "   nHeight% = sess.Height");
				pcsaBody->Add( "   Debug.Print \"Session.Height: \" & Str(nHeight%)");
			}
			
		}
		break;


		case 35:	// Session::HoldScreen
		{
			if ( "TRUE" == pcsaArguments->GetAt(1) )
			{
				csViewOutStuff.Format( "   sess.HoldScreen = TRUE");
			}
			else
			{
				csViewOutStuff.Format( "   sess.HoldScreen = FALSE");
			}

			pcsaBody->Add(csViewOutStuff);
			pcsaBody->Add( " " );

		}
		break;


		case 36:	// Session::HostName
		{
						
			pcsaBody->Add( "   hostname$ = sess.HostName" );
			pcsaBody->Add( "   Debug.Print \"Session.HostName: \" & hostname$");			

		}
		break;


		case 37:	// Session::InvokeSettingsDialog
		{
			pcsaBody->Add( "   sess.InvokeSettingsDialog( xFontPage )");
			pcsaBody->Add( "   Debug.Print \"Invoked Session.InvokeSettingsDialog\" ");			

		}
		break;


		case 38:	// Session::KeyboardLocked
		{
			if ( "TRUE" == pcsaArguments->GetAt(1) )
			{
				pcsaBody->Add("   sess.KeyboardLocked = TRUE");
			}
			else
			{
				pcsaBody->Add("   sess.KeyboardLocked = FALSE");
			}

			pcsaBody->Add(csViewOutStuff);
			pcsaBody->Add( " " );
		}
		break;



		case 39:	// Session::KeyMap
		{
			CString csKeyMap;
			csKeyMap = pcsaArguments->GetAt(1);
			if ( csKeyMap.Find( "TRUE", 0 ) != -1 )
			{
				csViewOutStuff.Format( "   sess.KeyMap = \"%s\"", pcsaArguments->GetAt(2) );
				pcsaBody->Add(csViewOutStuff);
				pcsaBody->Add("   Debug.Print \"" + csViewOutStuff + "\"");
				
			}
			else
			{
				
				pcsaBody->Add("   Buffer$ = sess.KeyMap");
				pcsaBody->Add("   Debug.Print \"Session.Keymap: \" & Buffer$");				

			}

		}
		break;


		case 40:	// Session::Language
		{
			CString csLanguage;
			csLanguage = pcsaArguments->GetAt(1);
			if ( csLanguage.Find( "TRUE", 0 ) != -1 )
			{
				csViewOutStuff.Format( "   sess.Language = \"%s\"", pcsaArguments->GetAt(2) );
				pcsaBody->Add(csViewOutStuff);
				pcsaBody->Add("   Debug.Print \"" + csViewOutStuff + "\"");
				
			}
			else
			{
				
				pcsaBody->Add( "   Buffer$ = sess.Language");
				pcsaBody->Add( "   Debug.Print \"Session.Language: \" & Buffer$");				

			}

		}
		break;


		case 41:	// Session::Local
		{
			CString csLocalMode;
			csLocalMode = pcsaArguments->GetAt(1);
			if ( csLocalMode.Find( "TRUE", 0 ) != -1 )
			{
				pcsaBody->Add( "   sess.Local = TRUE" );
				pcsaBody->Add( "   Debug.Print \"Session.Local set to TRUE\"");
			}
			else
			{				
				pcsaBody->Add( "   bLocalMode% = sess.Local" );
				pcsaBody->Add( "   Debug.Print \"Session.Local: \" & Str(bLocalMode%");
			}
		}
		break;

		case 42:	// Session::Menu
		{
			CString csLocalMode;
			csLocalMode = pcsaArguments->GetAt(1);
			if ( csLocalMode.Find( "TRUE", 0 ) != -1 )
			{
				pcsaBody->Add( "   sess.Menu = TRUE" );
				pcsaBody->Add( "   Debug.Print \"Session.Menu is TRUE\"");
			}
			else
			{				

				pcsaBody->Add( "   bMenuVisible% = sess.Menu" );
				pcsaBody->Add( "   Debug.Print \"Session.Menu: \" & Str(bMenuVisible)");
			}
		}
		break;

		case 43:	// Session::Name
		{
			
			pcsaBody->Add( "   Buffer$ = sess.Name");
			pcsaBody->Add( "   Debug.Print \"Session.Name: \" & Buffer$");
			
		}
		break;

		case 44:	// Session::PrintDisplay
		{
			pcsaBody->Add( "   sess.PrintDisplay" );
			pcsaBody->Add( "   Debug.Print \"invoked Session.PrintDisplay\"");
		}
		break;

		case 45:	// Session::Quiet
		{
			CString csQuietState;
			csQuietState = pcsaArguments->GetAt(1);
			if ( csQuietState.Find( "TRUE", 0 ) != -1 )
			{
				csViewOutStuff.Format( "   sess.Quiet = TRUE" );
				pcsaBody->Add(csViewOutStuff);
				pcsaBody->Add( "   Debug.Print \"" + csViewOutStuff + "\"");
			}
			else
			{				
				csViewOutStuff.Format( "   bSessionQuiet%% = sess.Quiet" );
				pcsaBody->Add(csViewOutStuff);
				pcsaBody->Add( "   Debug.Print \"Session.Quiet: \" & Str(bSessionQuiet)");
			}
		}
		break;


		case 46:	// Session::ReceiveFile
		{
			

			CString csShowFTStatus;
			csShowFTStatus = pcsaArguments->GetAt(3);
			if ( csShowFTStatus.Find( "TRUE", 0 ) != -1 )
			{
				csViewOutStuff.Format( "   bRet%% = sess.ReceiveFile( \"%s\", \"%s\", TRUE )", pcsaArguments->GetAt(1), pcsaArguments->GetAt(2) );
				pcsaBody->Add(csViewOutStuff);
				pcsaBody->Add( "   Debug.Print \"Session.ReceiveFile: \" & Str(bRet%)");
			}
			else
			{
				csViewOutStuff.Format( "   bRet%% = sess.ReceiveFile( \"%s\", \"%s\", FALSE )", pcsaArguments->GetAt(1), pcsaArguments->GetAt(2) );
				pcsaBody->Add(csViewOutStuff);
				pcsaBody->Add( "   Debug.Print \"Session.ReceiveFile: \" & Str(bRet%)");
			}
		}
		break;

		case 47:	// Session::ReduceFont
		{
			csViewOutStuff.Format( "   sess.ReduceFont" );
			pcsaBody->Add(csViewOutStuff);
			pcsaBody->Add( "   Debug.Print \"invoked Session.ReduceFont\"");
		}
		break;


		case 48:	// Session::Reset
		{
			csViewOutStuff.Format( "   sess.Reset" );
			pcsaBody->Add(csViewOutStuff);
			pcsaBody->Add( "   Debug.Print \"invoked Session.Reset\"");
		}
		break;


		case 49:	// Session::Save
		{
			csViewOutStuff.Format( "   sess.Save" );
			pcsaBody->Add(csViewOutStuff);
			pcsaBody->Add( "   Debug.Print \"invoked Session.Save\"");
		}
		break;


		case 50:	// Session::SaveAs
		{
			csViewOutStuff.Format( "   sess.SaveAs( \"%s\" )", pcsaArguments->GetAt(1) );
			pcsaBody->Add(csViewOutStuff);
			pcsaBody->Add( "   Debug.Print \"invoked Session.SaveAs\"");
		}
		break;


		case 51:	// Session::Saved
		{
			

			csViewOutStuff.Format( "   bSessionSaved%% = sess.Saved" );
			pcsaBody->Add(csViewOutStuff);
			pcsaBody->Add( "   Debug.Print \"Session.Saved: \" & Str(bSessionSaved%)");
		}
		break;

		case 52:	// Session::SendFile
		{
			

			CString csShowFTStatus;
			csShowFTStatus = pcsaArguments->GetAt(3);
			if ( csShowFTStatus.Find( "TRUE", 0 ) != -1 )
			{
				csViewOutStuff.Format( "   bRet%% = sess.SendFile( \"%s\", \"%s\", TRUE )", pcsaArguments->GetAt(1), pcsaArguments->GetAt(2) );
				pcsaBody->Add(csViewOutStuff);
				pcsaBody->Add( "   Debug.Print \"Session.SendFile: \" & Str(bRet)");
			}
			else
			{
				csViewOutStuff.Format( "   bRet%% = sess.SendFile( \"%s\", \"%s\", FALSE )", pcsaArguments->GetAt(1), pcsaArguments->GetAt(2) );
				pcsaBody->Add(csViewOutStuff);
				pcsaBody->Add( "   Debug.Print \"Session.SendFile: \" & Str(bRet%)");
			}
		}
		break;


		case 53:	// Session::Title
		{
			

			csViewOutStuff.Format( "   Buffer$ = \"%s\"", pcsaArguments->GetAt(1) );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "   sess.Title( Buffer$ )");
			pcsaBody->Add(csViewOutStuff);

			pcsaBody->Add( "   Debug.Print \"Session.Title: \" & Buffer$");
		}
		break;


		case 54:	// Session::TransferFile
		{
			csViewOutStuff.Format( "   sess.TransferFile" );
			pcsaBody->Add(csViewOutStuff);
			pcsaBody->Add( "   Debug.Print \"invoked Session.TransferFile\"");
		}
		break;

		case 55:	// Session::Type
		{			
			csViewOutStuff.Format( "   nType%% = sess.Type" );
			pcsaBody->Add(csViewOutStuff);
			pcsaBody->Add( "   Debug.Print \"Session.Type: \" & Str(nType%)");
		}
		break;


		case 56:	// Session::UpdateStatusBar
		{
			

			csViewOutStuff.Format( "   Buffer$ = \"%s\"", pcsaArguments->GetAt(1) );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "   sess.UpdateStatusBar( Buffer$ )");
			pcsaBody->Add(csViewOutStuff);
			pcsaBody->Add( "   Debug.Print \"invoked Session.UpdateStatusBar (VT only)\" ");

			
		}
		break;


		case 57:	// Session::Visible
		{
			

			CString csSessionVisible;
			csSessionVisible = pcsaArguments->GetAt(1);
			if ( csSessionVisible.Find( "TRUE", 0 ) != -1 )
			{
				csViewOutStuff.Format( "   Sess.Visible = TRUE" );
				pcsaBody->Add(csViewOutStuff);
				pcsaBody->Add( "   Debug.Print \"Session.Visible is TRUE\"");
			}
			else
			{
				csViewOutStuff.Format( "   bRet%% = sess.Visible" );
				pcsaBody->Add(csViewOutStuff);
				pcsaBody->Add( "   Debug.Print \"Session.Visible: \" & Str(bRet%)");
			}
		}
		break;


		case 58:	// Session::WaitForDisconnect
		{
			
			csViewOutStuff.Format( "   nTimeout%% = %s", pcsaArguments->GetAt(1) );
			pcsaBody->Add(csViewOutStuff);
			
			csViewOutStuff.Format( "   bRet%% = sess.WaitForDisconnect( nTimeout% )");
			pcsaBody->Add(csViewOutStuff);

			pcsaBody->Add( "   Debug.Print \"Session.WaitForDisconnect \" & Str(bRet%)");

		}
		break;


		case 59:	// Session::WaitForTimer	
		{
			
			csViewOutStuff.Format( "   nTimeout%% = %s", pcsaArguments->GetAt(1) );
			pcsaBody->Add(csViewOutStuff);
			
			if ( pcsaArguments->GetAt(2) == "TRUE" )
			{
				csViewOutStuff.Format( "   bRet%% = sess.WaitForTimer( nTimeout%, TRUE )");
				pcsaBody->Add(csViewOutStuff);
				pcsaBody->Add( "   Debug.Print \"Session.WaitForTimer: \" & Str(bRet%)");
			}
			else
			{
				csViewOutStuff.Format( "   bRet%% = sess.WaitForTimer( nTimeout%, FALSE )");
				pcsaBody->Add(csViewOutStuff);
				pcsaBody->Add( "   Debug.Print \"Session.WaitForTimer: \" & Str(bRet%)");
			}

			
		}
		break;


		case 60:	// Session::Width
		{
			
			if ( pcsaArguments->GetAt(1) == "TRUE" )
			{
				csViewOutStuff.Format( "   nWidth%% = %s", pcsaArguments->GetAt(2) );
				pcsaBody->Add(csViewOutStuff);
				
				csViewOutStuff.Format( "   sess.Width = nWidth%%");
				pcsaBody->Add(csViewOutStuff);
				pcsaBody->Add( "   Debug.Print \"Session.Width set to: \" & Str(nWidth%)");
			}
			else
			{
				csViewOutStuff.Format( "   nWidth%% = sess.Width");
				pcsaBody->Add(csViewOutStuff);
				pcsaBody->Add( "   Debug.Print \"Session.Width: \" & Str(nWidth%)");
			}			

		}
		break;


		case 61:	// Session::WindowHandle	
		{
			
			csViewOutStuff.Format( "   hSession& = sess.WindowHandle" );
			pcsaBody->Add(csViewOutStuff);
			pcsaBody->Add( "   Debug.Print \"Session.WindowHandle: \" & Str(hSession&)");
			

		}
		break;


		case 62:	// Session::WindowState
		{			

			if ( pcsaArguments->GetAt(1) == "TRUE" )
			{
				csViewOutStuff.Format( "   nWindowState%% = %s", pcsaArguments->GetAt(2) );
				pcsaBody->Add(csViewOutStuff);				
				
				csViewOutStuff.Format( "   sess.WindowState = nWindowState%%");
				pcsaBody->Add("   Debug.Print \"set Session.WindowState\"");

			}
			else
			{
				pcsaBody->Add( "   nWindowState% = sess.WindowState");
				pcsaBody->Add( "   Debug.Print \"Session.WindowState: \" & Str(nWindowState%)");
			}

			
		}
		break;

		// **************************** SESSIONS ******************************

		case 63:	// Sessions::Open
		{

			

			csViewOutStuff.Format( "   SessName$ = \"%s\"", pcsaArguments->GetAt(1) );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "   Set Sess = Sessions.Open( SessName$ )");
			pcsaBody->Add(csViewOutStuff);
			
			pcsaBody->Add("   Debug.Print \"invoked Sessions.Open\"");
			
		}
		break;

		case 64:	// Sessions::Count
		{
			
			pcsaBody->Add( "   nCount% = Sessions.Count" );
			pcsaBody->Add("   Debug.Print \"Sessions.Count: \" & Str(nCount%)");			

		}
		break;


		case 65:	// Sessions::CloseAll
		{
			
			pcsaBody->Add("   Sessions.CloseAll" );
			pcsaBody->Add("   Debug.Print \"invoked Sessions.CloseAll\"" );

	
		}
		break;

		
		// **************************** SYSTEM ******************************

		case 66:	// System::ActiveSession
		{
			pcsaBody->Add( "   Set sess = sys.ActiveSession" );
			pcsaBody->Add("   Debug.Print \"set sess = sys.ActiveSession\"");
			
			
		}
		break;

		case 67:	// System::Name
		{
			
			pcsaBody->Add( "   Buffer$ = sys.Name");
			pcsaBody->Add("   Debug.Print \"System.Name: \" & Buffer$");

			
		}
		break;


		case 68:	// System::Quit
		{
			pcsaBody->Add( "   System.Quit" );
			pcsaBody->Add("   Debug.Print \"System.Quit\"");

			
		}
		break;


		case 69:	// System::Time	XXX  AT RUNTIME WE GET A "NO METHOD" MESSAGE   FIXED 1/21 -- PLEASE TEST
		{
			

			pcsaBody->Add( "   Buffer$ = sys.Time()");
			pcsaBody->Add("   Debug.Print \"System.Time: \" & Buffer$");

			
		}
		break;


		case 70:	// System::TimeoutValue
		{			

			if ( pcsaArguments->GetAt(1) == "TRUE" )
			{
				csViewOutStuff.Format( "   nTimeout%% = %s", pcsaArguments->GetAt(2) );
				pcsaBody->Add(csViewOutStuff);

				csViewOutStuff.Format( "   sys.TimeoutValue = nTimeout%");
				pcsaBody->Add(csViewOutStuff);

				pcsaBody->Add("   Debug.Print \"set System.TimeoutValue\"" );
			}
			else
			{
				pcsaBody->Add( "   nTimeout% = sys.TimeoutValue");
				pcsaBody->Add("   Debug.Print \"System.TimeoutValue: \" & Str(nTimeout%)");
			}			

		}
		break;


		case 71:	// System::Version
		{			

			pcsaBody->Add( "   Buffer$ = sys.Version");
			pcsaBody->Add("   Debug.Print \"System.Version: \" & Buffer$");

			

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


void CAG_EOLE_3270_VB6::finalize(CStringArray* pcsaBody)
{
	pcsaBody->Add("");	
	pcsaBody->Add("End Sub");
	pcsaBody->Add("");	
}

void CAG_EOLE_3270_VB6::declareVariable(AG_VARIABLE agVariable,
										CStringArray* pcsaHeader,
										bool* bValue)
{
	
}

void CAG_EOLE_3270_VB6::checkDebug(bool b_Debug,
									   CString csFunctionName,
									   CStringArray* pcsaBody)
{
	
}

void CAG_EOLE_3270_VB6::resetVariableFlags()
{

}
