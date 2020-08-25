// Static Model
#include "stdafx.h"
#include "apigen.h"

#include "CAG_EOLE_VT_EBM_TEST.h"

CAG_EOLE_VT_EBM_TEST::CAG_EOLE_VT_EBM_TEST()
{
	resetVariableFlags();	
}

CAG_EOLE_VT_EBM_TEST::~CAG_EOLE_VT_EBM_TEST()
{
	
}



void CAG_EOLE_VT_EBM_TEST::generateHeader(CStringArray* pcsaHeader,
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

	csViewOutStuff.Format( "'                      Attachmate APIGen");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "'                  EXTRA! Basic VT Host Macro");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "'" );
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "'   Description: This is a freestanding EXTRA! Basic macro that was generated");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "'                using the API Generator. Scripting recorded begins at about line 100.");
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


	pcsaHeader->Add("'function declarations, global variables, constants...");
    pcsaHeader->Add(" ");
	pcsaHeader->Add("Declare Function MainDialogProc(id$, action%, suppvalue&)");
	pcsaHeader->Add("Declare Sub      AddStringToListBox(newstring$)");
	pcsaHeader->Add("Declare Function AtmGetOpenFileName(strTitle$, strFilter$, _");
	pcsaHeader->Add("                     strDefExtension$, strInitialDir$, bMustExist%) as String");
    pcsaHeader->Add(" ");
	pcsaHeader->Add("dim g_ListBoxContent$()   'array for updating ListBox on MainDialog");
	pcsaHeader->Add("dim g_Subscript%          'used with ListBox array");
	pcsaHeader->Add("dim g_IdleCounter&        'used with time display in MainDialogProc()");
	pcsaHeader->Add(" ");
	pcsaHeader->Add("'Win32 declarations needed for FileOpen dialog (to save output)");
	pcsaHeader->Add("Type OPENFILENAME");
	pcsaHeader->Add("   lStructSize As Long");
	pcsaHeader->Add("   hwndOwner As Long");
	pcsaHeader->Add("   hInstance As Long");
	pcsaHeader->Add("   lpstrFilter As Long");
	pcsaHeader->Add("   lpstrCustomFilter As Long");
	pcsaHeader->Add("   nMaxCustFilter As Long");
	pcsaHeader->Add("   nFilterIndex As Long");
	pcsaHeader->Add("   lpstrFile As Long");
	pcsaHeader->Add("   nMaxFile As Long");
	pcsaHeader->Add("   lpstrFileTitle As Long");
	pcsaHeader->Add("   nMaxFileTitle As Long");
	pcsaHeader->Add("   lpstrInitialDir As Long");
	pcsaHeader->Add("   lpstrTitle As Long");
	pcsaHeader->Add("   Flags As Long");
	pcsaHeader->Add("   nFileOffset As Integer");
	pcsaHeader->Add("   nFileExtension As Integer");
	pcsaHeader->Add("   lpstrDefExt As Long");
	pcsaHeader->Add("   lCustData As Long");
	pcsaHeader->Add("   lpfnHook As Long");
	pcsaHeader->Add("   lpTemplateName As Long");
	pcsaHeader->Add("End Type");
	pcsaHeader->Add(" ");
	pcsaHeader->Add("Declare Function GetOpenFileName Lib \"COMDLG32.DLL\" Alias \"GetOpenFileNameA\" (ofn As OPENFILENAME) As Integer");
	pcsaHeader->Add("Declare Function lstrcpy& Lib \"Kernel32\" (ByVal lpDestString As Any, ByVal lpSourceString As Any)");
    pcsaHeader->Add("Const OFN_HIDEREADONLY  = &H4");
	pcsaHeader->Add("Const OFN_FILEMUSTEXIST = &H1000");
    pcsaHeader->Add(" ");
    pcsaHeader->Add("'this is used within AtmGetOpenFileName...");
	pcsaHeader->Add("Function GetStrPointer( theStr as String ) As Long");
	pcsaHeader->Add("   GetStrPointer = lstrcpy( theStr, theStr )");
	pcsaHeader->Add("End Function");
	pcsaHeader->Add(" ");	
	pcsaHeader->Add("'================================================================================");
	pcsaHeader->Add("Sub Main()");
    pcsaHeader->Add("");
    pcsaHeader->Add("   g_Subscript% = -1   'ListBox in MainDialog is 0-based...if this isn't initialized ");
    pcsaHeader->Add("                       'like this here, the first line written to the list box would ");
    pcsaHeader->Add("                       'appear on the second line.  ");                                             
    pcsaHeader->Add(" ");
    pcsaHeader->Add("   Begin Dialog MainDialog 259, 138, \"Generated EXTRA! Basic test script\", .MainDialogProc ");               
    pcsaHeader->Add("       PushButton  3, 110, 58, 14, \"&Test\", .ButtonTest "); 
    pcsaHeader->Add("       PushButton  198, 110, 58, 14, \"&Close\", .ButtonClose ");    
    pcsaHeader->Add("       ListBox  0, 1, 258, 111, \"\", .ListBox1");
    pcsaHeader->Add("       Text  5, 128, 237, 9, \"\", .TextStatus");
    pcsaHeader->Add("   End Dialog");
    pcsaHeader->Add(" ");
    pcsaHeader->Add("   dim dlg as MainDialog");   
    pcsaHeader->Add(" ");      
    pcsaHeader->Add("   rc = Dialog(dlg)");     
    pcsaHeader->Add(" ");
	pcsaHeader->Add("End Sub");
	pcsaHeader->Add(" ");
	pcsaHeader->Add("'================================================================================");
	pcsaHeader->Add(" ");
	pcsaHeader->Add("Function MainDialogProc(id$, action%, suppvalue&)");    
	pcsaHeader->Add(" ");
	pcsaHeader->Add("   select case action% ");          
	pcsaHeader->Add(" ");      
	pcsaHeader->Add("      case 2   'A button has been pressed, or other non-text/combo control changed...");
	pcsaHeader->Add(" ");
	pcsaHeader->Add("         select case id$    'which button was it?");
	pcsaHeader->Add(" ");          
	pcsaHeader->Add("             case \"ButtonTest\"");      
	pcsaHeader->Add("                   'Hide the time display while test runs (idle handler will cause to resume)");                                        
	pcsaHeader->Add("                   DlgText DlgControlID(\"TextStatus\"), \"\" "); 
	pcsaHeader->Add(" ");                   
	pcsaHeader->Add("                   'Hide test button while test runs");
	pcsaHeader->Add("                   DlgVisible DlgControlId(\"ButtonTest\"), 0");
	pcsaHeader->Add(" ");                     
	pcsaHeader->Add("                   AddStringToListBox(Now + \"  Test started\")");                                     
	pcsaHeader->Add(" ");                   
	pcsaHeader->Add("'***********************************************************************");
	pcsaHeader->Add("'*           SCRIPTING YOU RECORDED WITH APIGEN                        *");    
	pcsaHeader->Add("'***********************************************************************");
    pcsaHeader->Add(" ");  
    pcsaHeader->Add("   'First, get a hold of an EXTRA! session to work with...");
    pcsaHeader->Add("   Dim sys As New ExtraSystem");
	pcsaHeader->Add("   Dim sess As ExtraSession");
	pcsaHeader->Add("   Dim area As ExtraArea       'returned by Search, Select, etc."); 
	pcsaHeader->Add(" ");
	pcsaHeader->Add("   If sys.ActiveSession Is Nothing Then");
	pcsaHeader->Add("      AddStringToListBox \"No ActiveSession - will try to open one\"");
	pcsaHeader->Add("      Set sess = sys.Sessions.Open()    'open a session if we don't already have one");     
	pcsaHeader->Add("      If sess Is Nothing Then");
	pcsaHeader->Add("         AddStringToListBox \"Sessions.Open failed, or you canceled the file-open dialog\" ");
    pcsaHeader->Add("         DlgVisible DlgControlId(\"ButtonTest\"), 1   're-show the test button");
    pcsaHeader->Add("         MainDialogProc = TRUE  'keeps this dialog box open");
	pcsaHeader->Add("         Exit Function");
	pcsaHeader->Add("      Else");
	pcsaHeader->Add("         sess.Visible = True");
	pcsaHeader->Add("         sess.Screen.WaitHostQuiet 500");
	pcsaHeader->Add("      AddStringToListBox \"Opened session: \" & sess.Name");
	pcsaHeader->Add("      End If");
	pcsaHeader->Add("   Else");
	pcsaHeader->Add("      Set sess = sys.ActiveSession   'use session that's already open");
	pcsaHeader->Add("      AddStringToListBox \"Using ActiveSession named: \" & sess.Name");
	pcsaHeader->Add("   End If");
	pcsaHeader->Add(" ");
		
}


/****************************************************************************DC
	Function	:	CAG_EOLE_VT_EBM_TEST::appendBody()

	Purpose		:	Formats the csaHeader and csaBody string arrays for
					use in output.

	Note		:	This will be written to assume that the parameters are
					entered by the calling module -- defaults or human entered.

*****************************************************************************/
void CAG_EOLE_VT_EBM_TEST::appendBody(int nFunctionNum,
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
			pcsaBody->Add("   AddStringToListBox \"OIA.ConnectionStatus: \" & Str(nStatus%)");			
		}
		break;
			

		case 1:		// Screen.OIA.ErrorStatus
		{		
			pcsaBody->Add("   nStatus% = sess.Screen.OIA.ErrorStatus");  
			pcsaBody->Add("   AddStringToListBox \"OIA.ErrorStatus: \" & Str(nStatus%)");			
		}
		break;


		case 2:		// Screen->OIA.Updated
		{
			pcsaBody->Add("   bUpdated% = sess.Screen.OIA.Updated");  
			pcsaBody->Add("   AddStringToListBox \"OIA.Updated: \" & Str(bUpdated%)");			
		}
		break;


		case 3:		// Screen.OIA.Value
		{		
            pcsaBody->Add("   Buffer$ = sess.Screen.OIA.Value");
			pcsaBody->Add("   AddStringToListBox \"OIA.Value: \" & Buffer$");			
		}
		break;


		case 4:		// Screen.OIA.XStatus
		{
			pcsaBody->Add("   nStatus% = sess.Screen.OIA.XStatus");
			pcsaBody->Add("   AddStringToListBox \"OIA.XStatus: \" & Str(nStatus%)");
		}
		break;


	
	// **************************** SCREEN ******************************	
	case 5:		// Screen::Col
		{		
			pcsaBody->Add("   nColumn% = sess.Screen.Col");
			pcsaBody->Add("   AddStringToListBox \"Screen.Col: \" & Str(nColumn%)");
		}
		break;


		case 6:		// Screen::Copy
		{		
			pcsaBody->Add("   sess.Screen.Copy");
			pcsaBody->Add("   AddStringToListBox \"Invoked Screen.Copy\"");
		}
		break;

		case 7:		// Screen::FieldAttribute
		{			
			
			csViewOutStuff.Format( "   nRow%% = %s", pcsaArguments->GetAt(1) );
			pcsaBody->Add(csViewOutStuff);
			csViewOutStuff.Format( "   nColumn%% = %s", pcsaArguments->GetAt(2) );
			pcsaBody->Add(csViewOutStuff);
			
			pcsaBody->Add("   nAttribute% = sess.Screen.FieldAttribute( nRow%, nColumn% )");
			pcsaBody->Add("   AddStringToListBox \"Screen.FieldAttribute: \" & Str(nAttribute%)");
			
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
			pcsaBody->Add("   AddStringToListBox \"Screen.GetString: \" & Buffer$");
		}
		break;


		case 9:		// Screen.MoveTo
		{			
			csViewOutStuff.Format( "   nRow%% = %s", pcsaArguments->GetAt(1) );
			pcsaBody->Add(csViewOutStuff);
			csViewOutStuff.Format( "   nColumn%% = %s", pcsaArguments->GetAt(2) );
			pcsaBody->Add(csViewOutStuff);
			
			pcsaBody->Add("   sess.Screen.MoveTo nRow%, nColumn% ");
			pcsaBody->Add("   AddStringToListBox \"Invoked Screen.MoveTo\" ");

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
			pcsaBody->Add("   AddStringToListBox \"Invoked Screen.PutString\" ");
					
		}
		break;
		

		case 11:	// Screen.Row
		{			

			pcsaBody->Add("   nRow% = sess.Screen.Row");
			pcsaBody->Add("   AddStringToListBox \"Screen.Row: \" & Str(nRow%)");
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
			pcsaBody->Add("      AddStringToListBox \"Screen.Search: search string not found\"");
			pcsaBody->Add("   Else");
			pcsaBody->Add("      AddStringToListBox \"Screen.Search: search string found at row \" & Str(area.Top) & \" column \" & Str(area.Left)");
			pcsaBody->Add("   End If");

		}
		break;


		case 13:	// Screen.SelectAll
		{			
			
			pcsaBody->Add("   Set area = sess.Screen.SelectAll()");
			pcsaBody->Add("   If area Is Nothing Then");
			pcsaBody->Add("      AddStringToListBox \"Screen.SelectAll failed!\"");
			pcsaBody->Add("   Else");
			pcsaBody->Add("      AddStringToListBox \"Invoked Screen.SelectAll\"");
			pcsaBody->Add("   End If");
			
		}
		break;

		case 14:	// Screen.SendKeys
		{
			
			csViewOutStuff.Format( "   Buffer$ = \"%s\"", pcsaArguments->GetAt(1) );
			pcsaBody->Add(csViewOutStuff);
			csViewOutStuff.Format( "   sess.Screen.Sendkeys( Buffer$ )" );
			pcsaBody->Add(csViewOutStuff);
			pcsaBody->Add("   AddStringToListBox \"Invoked Screen.SendKeys\"");
			
		}
		break;



		case 15:	// Screen.Updated
		{
			

			csViewOutStuff.Format( "     bUpdated%% = sess.Screen.Updated" );
			pcsaBody->Add(csViewOutStuff);
			pcsaBody->Add("   AddStringToListBox \"Screen.Updated: \" & Str(bUpdated%)");
			

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
				pcsaBody->Add("   AddStringToListBox \"Screen.WaitForCursor: \" & Str(bRet%)");
			}
			else	// 17
			{
				pcsaBody->Add( "   bRet% = sess.Screen.WaitForCursorMove( nRow%, nColumn% )");
				pcsaBody->Add("   AddStringToListBox \"Screen.WaitForCursorMove: \" & Str(bRet%)");
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
			pcsaBody->Add("   AddStringToListBox \"Screen.WaitForKeys: \" & retkeys$");
			
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
			pcsaBody->Add("   AddStringToListBox \"Screen.WaitForStream: \" & Str(bRet%)" );

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
			pcsaBody->Add("   AddStringToListBox \"Screen.WaitForString: \" & Str(bRet%)" );

		}
		break;	

		case 21:	// WaitHostQuiet
		{
			csViewOutStuff.Format("   nSettleTime%% = %s", pcsaArguments->GetAt(1));
			pcsaBody->Add(csViewOutStuff);

			pcsaBody->Add("   bRet% = sess.Screen.WaitHostQuiet(nSettleTime%)" );
			pcsaBody->Add("   AddStringToListBox \"Screen.WaitHostQuiet: \" & Str(bRet%)");
			

		}
		break;

		// **************************** SESSION ******************************
		case 22:	// Session::Activate
		{
			pcsaBody->Add( "   sess.Activate");			
			pcsaBody->Add( "   AddStringToListBox \"Invoked Session.Activate\"" );
			
		}
		break;


		case 23:	// Session::ClearComm
		{
			pcsaBody->Add( "   sess.ClearComm");			
			pcsaBody->Add( "   AddStringToListBox \"Invoked Session.ClearComm\"" );

			
		}
		break;

		case 24:	//	Session::ClearHistory
		{
			pcsaBody->Add( "   sess.ClearHistory");			
			pcsaBody->Add( "   AddStringToListBox \"Invoked Session.ClearHistory\"" );
		}
		break;

		
		

	
		case 25:	// Session::Close
		{
			pcsaBody->Add( "   sess.Close");			
			pcsaBody->Add( "   AddStringToListBox \"Invoked Session.Close\"" );

		}
		break;


		case 26:	// Session::CloseEx
		{
			
			

			csViewOutStuff.Format( "   nCloseOption%% = %s", pcsaArguments->GetAt(1) );
			pcsaBody->Add(csViewOutStuff);

			pcsaBody->Add( "   sess.CloseEx( nCloseOption% )");
			pcsaBody->Add( "   AddStringToListBox \"Invoked Session.CloseEx\"" );

		

		}
		break;


		case 27:	// Session::ClosePrintJob
		{
			pcsaBody->Add( "   sess.ClosePrintJob");			
			pcsaBody->Add( "   AddStringToListBox \"Invoked Session.ClosePrintJob\"" );

		}
		break;

		case 28:	// Session::Connected
		{
			
			pcsaBody->Add( "   bRet% = sess.Connected");			
			pcsaBody->Add( "   AddStringToListBox \"Session.Connected: \" & Str(bRet%)");

		}
		break;

		case 29:	// Session::EnlargeFont
		{
			pcsaBody->Add( "   sess.EnlargeFont");			
			pcsaBody->Add( "   AddStringToListBox \"Invoked Session.EnlargeFont\"" );
		}
		break;


		case 30:	// Session::FileTransferHostOS
		{
			csViewOutStuff.Format( "   nHostOS%% = %s", pcsaArguments->GetAt(1) );
			pcsaBody->Add(csViewOutStuff);

			pcsaBody->Add( "   sess.FileTransferHostOS = nHostOS%" );
			pcsaBody->Add( "   AddStringToListBox \"Set the Session.FileTransferHostOS: \" & Str(nHostOS%)");
		}
		break;

		case 31:	// FileTransferOptions
		{
			pcsaBody->Add("   Dim fto as ExtraFileTransfer");
			pcsaBody->Add("   Set fto = sess.FileTransferOptions");
			pcsaBody->Add("   If fto Is Nothing Then");
			pcsaBody->Add("      AddStringToListBox \"Failed to retrieve valid File Transfer Options object.\"");
			pcsaBody->Add("   Else");
			pcsaBody->Add("      AddStringToListBox \"Retrieved a valid File Transfer Options object.\"");
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
				pcsaBody->Add( "   AddStringToListBox \"Set Session.FileTransferScheme\"");
			}
			else
			{
				//get it

				pcsaBody->Add( "   FTScheme$ = sess.FileTransferScheme" );
				pcsaBody->Add( "   AddStringToListBox \"Get Session.FileTransferScheme: \" & Str(FTScheme$)");

			}

		}
		break;


		case 33:	// Session::Font
		{
			
			csViewOutStuff.Format( "   font$ = sess.Font");
			pcsaBody->Add( "   AddStringToListBox \"Session.Font: \" & font$");

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
				pcsaBody->Add( "   AddStringToListBox \"Set Session.Height\"");
			}
			else
			{
				//get it

				pcsaBody->Add( "   nHeight% = sess.Height");
				pcsaBody->Add( "   AddStringToListBox \"Session.Height: \" & Str(nHeight%)");
			}
			
		}
		break;


		case 35:	// Session::HoldScreen
		{
			csViewOutStuff.Format( "   sess.HoldScreen = TRUE");        //TODO: allow to set T/F
			pcsaBody->Add(csViewOutStuff);
			
		}
		break;


		case 36:	// Session::HostName
		{
						
			pcsaBody->Add( "   hostname$ = sess.HostName" );
			pcsaBody->Add( "   AddStringToListBox \"Session.HostName: \" & hostname$");			

		}
		break;


		case 37:	// Session::InvokeSettingsDialog
		{
			pcsaBody->Add( "   sess.InvokeSettingsDialog( xFontPage )");
			pcsaBody->Add( "   AddStringToListBox \"Invoked Session.InvokeSettingsDialog\" ");			

		}
		break;


		case 38:	// Session::KeyboardLocked
		{
			pcsaBody->Add("   sess.KeyboardLocked = TRUE");    //TODO: allow to set T/F
			pcsaBody->Add("   AddStringToListBox \"Session.KeyboardLocked = TRUE!!!\"");
			
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
				pcsaBody->Add("   AddStringToListBox \"" + csViewOutStuff + "\"");
				
			}
			else
			{
				
				pcsaBody->Add("   Buffer$ = sess.KeyMap");
				pcsaBody->Add("   AddStringToListBox \"Session.Keymap: \" & Buffer$");				

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
				pcsaBody->Add("   AddStringToListBox \"" + csViewOutStuff + "\"");
				
			}
			else
			{
				
				pcsaBody->Add( "   Buffer$ = sess.Language");
				pcsaBody->Add( "   AddStringToListBox \"Session.Language: \" & Buffer$");				

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
				pcsaBody->Add( "   AddStringToListBox \"Session.Local set to TRUE\"");
			}
			else
			{				
				pcsaBody->Add( "   bLocalMode% = sess.Local" );
				pcsaBody->Add( "   AddStringToListBox \"Session.Local: \" & Str(bLocalMode%");
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
				pcsaBody->Add( "   AddStringToListBox \"Session.Menu is TRUE\"");
			}
			else
			{				

				pcsaBody->Add( "   bMenuVisible% = sess.Menu" );
				pcsaBody->Add( "   AddStringToListBox \"Session.Menu: \" & Str(bMenuVisible)");
			}
		}
		break;

		case 43:	// Session::Name
		{
			
			pcsaBody->Add( "   Buffer$ = sess.Name");
			pcsaBody->Add( "   AddStringToListBox \"Session.Name: \" & Buffer$");
			
		}
		break;

		case 44:	// Session::PrintDisplay
		{
			pcsaBody->Add( "   sess.PrintDisplay" );
			pcsaBody->Add( "   AddStringToListBox \"invoked Session.PrintDisplay\"");
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
				pcsaBody->Add( "   AddStringToListBox \"" + csViewOutStuff + "\"");
			}
			else
			{				
				csViewOutStuff.Format( "   bSessionQuiet%% = sess.Quiet" );
				pcsaBody->Add(csViewOutStuff);
				pcsaBody->Add( "   AddStringToListBox \"Session.Quiet: \" & Str(bSessionQuiet)");
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
				pcsaBody->Add( "   AddStringToListBox \"Session.ReceiveFile: \" & Str(bRet%)");
			}
			else
			{
				csViewOutStuff.Format( "   bRet%% = sess.ReceiveFile( \"%s\", \"%s\", FALSE )", pcsaArguments->GetAt(1), pcsaArguments->GetAt(2) );
				pcsaBody->Add(csViewOutStuff);
				pcsaBody->Add( "   AddStringToListBox \"Session.ReceiveFile: \" & Str(bRet%)");
			}
		}
		break;

		case 47:	// Session::ReduceFont
		{
			csViewOutStuff.Format( "   sess.ReduceFont" );
			pcsaBody->Add(csViewOutStuff);
			pcsaBody->Add( "   AddStringToListBox \"invoked Session.ReduceFont\"");
		}
		break;


		case 48:	// Session::Reset
		{
			csViewOutStuff.Format( "   sess.Reset" );
			pcsaBody->Add(csViewOutStuff);
			pcsaBody->Add( "   AddStringToListBox \"invoked Session.Reset\"");
		}
		break;


		case 49:	// Session::Save
		{
			csViewOutStuff.Format( "   sess.Save" );
			pcsaBody->Add(csViewOutStuff);
			pcsaBody->Add( "   AddStringToListBox \"invoked Session.Save\"");
		}
		break;


		case 50:	// Session::SaveAs
		{
			csViewOutStuff.Format( "   sess.SaveAs( \"%s\" )", pcsaArguments->GetAt(1) );
			pcsaBody->Add(csViewOutStuff);
			pcsaBody->Add( "   AddStringToListBox \"invoked Session.SaveAs\"");
		}
		break;


		case 51:	// Session::Saved
		{
			

			csViewOutStuff.Format( "   bSessionSaved%% = sess.Saved" );
			pcsaBody->Add(csViewOutStuff);
			pcsaBody->Add( "   AddStringToListBox \"Session.Saved: \" & Str(bSessionSaved%)");
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
				pcsaBody->Add( "   AddStringToListBox \"Session.SendFile: \" & Str(bRet)");
			}
			else
			{
				csViewOutStuff.Format( "   bRet%% = sess.SendFile( \"%s\", \"%s\", FALSE )", pcsaArguments->GetAt(1), pcsaArguments->GetAt(2) );
				pcsaBody->Add(csViewOutStuff);
				pcsaBody->Add( "   AddStringToListBox \"Session.SendFile: \" & Str(bRet%)");
			}
		}
		break;


		case 53:	// Session::Title
		{
			

			csViewOutStuff.Format( "   Buffer$ = \"%s\"", pcsaArguments->GetAt(1) );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "   sess.Title( Buffer$ )");
			pcsaBody->Add(csViewOutStuff);

			pcsaBody->Add( "   AddStringToListBox \"Session.Title: \" & Buffer$");
		}
		break;


		case 54:	// Session::TransferFile
		{
			csViewOutStuff.Format( "   sess.TransferFile" );
			pcsaBody->Add(csViewOutStuff);
			pcsaBody->Add( "   AddStringToListBox \"invoked Session.TransferFile\"");
		}
		break;

		case 55:	// Session::Type
		{			
			csViewOutStuff.Format( "   nType%% = sess.Type" );
			pcsaBody->Add(csViewOutStuff);
			pcsaBody->Add( "   AddStringToListBox \"Session.Type: \" & Str(nType%)");
		}
		break;


		case 56:	// Session::UpdateStatusBar
		{
			

			csViewOutStuff.Format( "   Buffer$ = \"%s\"", pcsaArguments->GetAt(1) );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "   sess.UpdateStatusBar( Buffer$ )");
			pcsaBody->Add(csViewOutStuff);
			pcsaBody->Add( "   AddStringToListBox \"invoked Session.UpdateStatusBar (VT only)\" ");

			
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
				pcsaBody->Add( "   AddStringToListBox \"Session.Visible is TRUE\"");
			}
			else
			{
				csViewOutStuff.Format( "   bRet%% = sess.Visible" );
				pcsaBody->Add(csViewOutStuff);
				pcsaBody->Add( "   AddStringToListBox \"Session.Visible: \" & Str(bRet%)");
			}
		}
		break;


		case 58:	// Session::WaitForDisconnect
		{
			
			csViewOutStuff.Format( "   nTimeout%% = %s", pcsaArguments->GetAt(1) );
			pcsaBody->Add(csViewOutStuff);
			
			csViewOutStuff.Format( "   bRet%% = sess.WaitForDisconnect( nTimeout% )");
			pcsaBody->Add(csViewOutStuff);

			pcsaBody->Add( "   AddStringToListBox \"Session.WaitForDisconnect \" & Str(bRet%)");

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
				pcsaBody->Add( "   AddStringToListBox \"Session.WaitForTimer: \" & Str(bRet%)");
			}
			else
			{
				csViewOutStuff.Format( "   bRet%% = sess.WaitForTimer( nTimeout%, FALSE )");
				pcsaBody->Add(csViewOutStuff);
				pcsaBody->Add( "   AddStringToListBox \"Session.WaitForTimer: \" & Str(bRet%)");
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
				pcsaBody->Add( "   AddStringToListBox \"Session.Width set to: \" & Str(nWidth%)");
			}
			else
			{
				csViewOutStuff.Format( "   nWidth%% = sess.Width");
				pcsaBody->Add(csViewOutStuff);
				pcsaBody->Add( "   AddStringToListBox \"Session.Width: \" & Str(nWidth%)");
			}			

		}
		break;


		case 61:	// Session::WindowHandle	
		{
			
			csViewOutStuff.Format( "   hSession& = sess.WindowHandle" );
			pcsaBody->Add(csViewOutStuff);
			pcsaBody->Add( "   AddStringToListBox \"Session.WindowHandle: \" & Str(hSession&)");
			

		}
		break;


		case 62:	// Session::WindowState
		{			

			if ( pcsaArguments->GetAt(1) == "TRUE" )
			{
				csViewOutStuff.Format( "   nWindowState%% = %s", pcsaArguments->GetAt(2) );
				pcsaBody->Add(csViewOutStuff);				
				
				csViewOutStuff.Format( "   sess.WindowState = nWindowState%%");
				pcsaBody->Add("   AddStringToListBox \"set Session.WindowState\"");

			}
			else
			{
				pcsaBody->Add( "   nWindowState% = sess.WindowState");
				pcsaBody->Add( "   AddStringToListBox \"Session.WindowState: \" & Str(nWindowState%)");
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
			
			pcsaBody->Add("   AddStringToListBox \"invoked Sessions.Open\"");
			
		}
		break;

		case 64:	// Sessions::Count
		{
			
			pcsaBody->Add( "   nCount% = Sessions.Count" );
			pcsaBody->Add("   AddStringToListBox \"Sessions.Count: \" & Str(nCount%)");			

		}
		break;


		case 65:	// Sessions::CloseAll
		{
			
			pcsaBody->Add("   Sessions.CloseAll" );
			pcsaBody->Add("   AddStringToListBox \"invoked Sessions.CloseAll\"" );

	
		}
		break;

		
		// **************************** SYSTEM ******************************

		case 66:	// System::ActiveSession
		{
			pcsaBody->Add( "   Set sess = sys.ActiveSession" );
			pcsaBody->Add("   AddStringToListBox \"set sess = sys.ActiveSession\"");
			
			
		}
		break;

		case 67:	// System::Name
		{
			
			pcsaBody->Add( "   Buffer$ = sys.Name");
			pcsaBody->Add("   AddStringToListBox \"System.Name: \" & Buffer$");

			
		}
		break;


		case 68:	// System::Quit
		{
			pcsaBody->Add( "   System.Quit" );
			pcsaBody->Add("   AddStringToListBox \"System.Quit\"");

			
		}
		break;


		case 69:	// System::Time	XXX  AT RUNTIME WE GET A "NO METHOD" MESSAGE   FIXED 1/21 -- PLEASE TEST
		{
			

			pcsaBody->Add( "   Buffer$ = sys.Time()");
			pcsaBody->Add("   AddStringToListBox \"System.Time: \" & Buffer$");

			
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

				pcsaBody->Add("   AddStringToListBox \"set System.TimeoutValue\"" );
			}
			else
			{
				pcsaBody->Add( "   nTimeout% = sys.TimeoutValue");
				pcsaBody->Add("   AddStringToListBox \"System.TimeoutValue: \" & Str(nTimeout%)");
			}			

		}
		break;


		case 71:	// System::Version
		{			

			pcsaBody->Add( "   Buffer$ = sys.Version");
			pcsaBody->Add("   AddStringToListBox \"System.Version: \" & Buffer$");

			

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


void CAG_EOLE_VT_EBM_TEST::finalize(CStringArray* pcsaBody)
{
    pcsaBody->Add(" ");
	pcsaBody->Add("'********************************************************************");
	pcsaBody->Add("'*                  END RECORDED SCRIPTING                          *");    
	pcsaBody->Add("'********************************************************************");
	pcsaBody->Add(" ");                   
	pcsaBody->Add("                 AddStringToListBox(Now + \"  Test ended\")"); 
	pcsaBody->Add(" ");                   
	pcsaBody->Add("                 'Make test button visible again");
	pcsaBody->Add("                 DlgVisible DlgControlId(\"ButtonTest\"), 1");
	pcsaBody->Add(" ");                   
	pcsaBody->Add("                 'causes MainDialog to remain open after button click");
	pcsaBody->Add("                 MainDialogProc = TRUE ");   
	pcsaBody->Add(" ");                                                        
	pcsaBody->Add("            case \"ButtonClose\"    'Optionally, you can save the record of what's occurred ");                                                                                                            
	pcsaBody->Add(" ");                   
	pcsaBody->Add("                 'Don't bother saving if list is empty");
	pcsaBody->Add("                 if DlgListBoxArray(DlgControlId(\"ListBox1\")) <> 0 then"); 
	pcsaBody->Add(" ");                                                                
	pcsaBody->Add("                     rc = msgbox(\"    Save test output?\", 36, \"APIGEN\") ");                     
	pcsaBody->Add("                     if rc = 6 then");     
	pcsaBody->Add("                         'yes...save output");                                                    
	pcsaBody->Add("                         filter$ =  \"Text (*.txt)\" & Chr$(0) & \"*.txt\" & Chr$(0)");
	pcsaBody->Add("                         filter$ = filter$ & \"Any (*.*)\" & Chr$(0) & \"*.*\" & Chr$(0) & Chr$(0)");
	pcsaBody->Add(" ");                              
	pcsaBody->Add("                         fname$ = AtmGetOpenFileName(\"Save output as...\", filter$, \".txt\", \"\", FALSE)");
	pcsaBody->Add(" ");                              
	pcsaBody->Add("                         if fname$ <> \"\" then");
	pcsaBody->Add("                             'user did not cancel save dialog");                                                                                       
	pcsaBody->Add("                             filenum = FreeFile ");                           
	pcsaBody->Add("                             open fname$ for output as # filenum");
	pcsaBody->Add("                             for i% = 0 to g_Subscript%");
	pcsaBody->Add("                                print # filenum, g_ListBoxContent$(i%)");
	pcsaBody->Add("                             next i%");
	pcsaBody->Add("                             close # filenum ");                                                                                                     
	pcsaBody->Add("                          end if");                                                                                         
	pcsaBody->Add("                     end if");
	pcsaBody->Add(" ");                        
	pcsaBody->Add("                     MainDialogProc = FALSE");                        
	pcsaBody->Add("                  end if");
	pcsaBody->Add(" ");                           
	pcsaBody->Add("         end select   'select id$");
	pcsaBody->Add(" ");                                             
	pcsaBody->Add("     case 5   'The code here updates the label at the bottom of the dialog");
	pcsaBody->Add("              'with the current time. ");
	pcsaBody->Add(" ");                   
	pcsaBody->Add("             g_IdleCounter& = g_IdleCounter& + 1");
	pcsaBody->Add("             if (g_IdleCounter& mod 100 = 0) then     'check about once per second");      
	pcsaBody->Add(" ");               
	pcsaBody->Add("             'update the label ");                          
	pcsaBody->Add("                 DlgText (DlgControlID(\"TextStatus\")), Now");                                                                  
	pcsaBody->Add(" ");                
	pcsaBody->Add("                 if g_IdleCounter& > 10000 then       'don't let the value in ");                                                      
	pcsaBody->Add("                    g_IdleCounter& = 0               'counter get to big");
	pcsaBody->Add("                 end if");
	pcsaBody->Add(" ");                        
	pcsaBody->Add("                 doevents   'necessary, otherwise processor usage will remain at 100%");
	pcsaBody->Add("              end if");
	pcsaBody->Add(" ");               
	pcsaBody->Add("              MainDialogProc = TRUE  'causes this function to receive notifications constantly "); 
	pcsaBody->Add(" ");                                                                    
	pcsaBody->Add("   end select   'select action%");
	pcsaBody->Add(" ");            
	pcsaBody->Add("End Function");
	pcsaBody->Add(" ");
	pcsaBody->Add("'================================================================================");
    pcsaBody->Add(" ");
	pcsaBody->Add("Sub AddStringToListBox(newstring$)");
	pcsaBody->Add(" ");    
	pcsaBody->Add("   g_Subscript% = g_Subscript% + 1 ");    
	pcsaBody->Add("   redim preserve g_ListboxContent$(g_Subscript%) ");    
	pcsaBody->Add("   g_ListBoxContent$(g_Subscript%) = newstring$");    
	pcsaBody->Add("   DlgListBoxArray DlgControlID(\"ListBox1\"), g_ListBoxContent$()   'update the ListBox ");
	pcsaBody->Add("   DlgValue DlgControlID(\"ListBox1\"), g_Subscript%   'cause the last item in the box to be selected");
	pcsaBody->Add(" ");                                 
	pcsaBody->Add("End Sub");
	pcsaBody->Add(" ");
	pcsaBody->Add("'==========================================================================================");
	pcsaBody->Add(" ");
	pcsaBody->Add("Function AtmGetOpenFileName(strTitle as String, strFilter as String, _");
	pcsaBody->Add("      strDefExtension as String, strInitialDir as String, bMustExist as Integer) as String");
	pcsaBody->Add(" ");
	pcsaBody->Add("   dim title   as string");
	pcsaBody->Add("   dim filter  as string");
	pcsaBody->Add("   dim defext  as string");
	pcsaBody->Add("   dim initdir as string");    
	pcsaBody->Add("   dim filename  as string");
	pcsaBody->Add("   dim filetitle as string");
	pcsaBody->Add("   dim flags   as long");
	pcsaBody->Add("   dim ofn as OPENFILENAME");
	pcsaBody->Add("   dim nRet as Integer");	  
	pcsaBody->Add(" ");   
	pcsaBody->Add("   'ASSIGN DEFAULT VALUES IF NECESSARY");
	pcsaBody->Add("   if strTitle = \"\" then");
	pcsaBody->Add("      title = \" \" & chr$(0)");
	pcsaBody->Add("   else");
	pcsaBody->Add("      title = strTitle & chr$(0)");
	pcsaBody->Add("   end if");    
	pcsaBody->Add(" ");  
	pcsaBody->Add("   if strFilter = \"\" then");
	pcsaBody->Add("      filter = \"All Files (*.*)\" & Chr$(0) & \"*.*\" & Chr$(0) & Chr$(0)");
	pcsaBody->Add("   else");
	pcsaBody->Add("      filter = strFilter 'if you provide a custom filter, it must follow the example");
	pcsaBody->Add("   end if                 'for \"All Files\" above, and the last item in the list must");
	pcsaBody->Add("                     'be followed by 2 nulls rather than just one. For example:");
	pcsaBody->Add("                     '");
	pcsaBody->Add("                     ' Filter = \"SBL Files (*.sbl)\" & Chr$(0) & \"*.SBL;*.SBH\" & Chr$(0)");
	pcsaBody->Add("                     ' Filter = Filter$ & \"Text (*.txt)\" & Chr$(0) & \"*.TXT\" & Chr$(0)");
	pcsaBody->Add("                     ' Filter = Filter$ & \"Any (*.*)\" & Chr$(0) & \"*.*\" & Chr$(0) & Chr$(0)");
	pcsaBody->Add(" ");                          
	pcsaBody->Add("   if strDefExtension = \"\" then");
	pcsaBody->Add("      defext = \"\" & chr$(0)");
	pcsaBody->Add("   else");
	pcsaBody->Add("      defext = strDefExtension & chr$(0)");
	pcsaBody->Add("   end if");
	pcsaBody->Add(" ");   
	pcsaBody->Add("   if strInitialDir = \"\" then");
	pcsaBody->Add("      initdir = CurDir$ & chr$(0)");
	pcsaBody->Add("   else");
	pcsaBody->Add("      initdir = strInitialDir & chr$(0)");
	pcsaBody->Add("   end if");
	pcsaBody->Add(" ");   
	pcsaBody->Add("   if bMustExist then");
	pcsaBody->Add("      flags = OFN_HIDEREADONLY Or OFN_FILEMUSTEXIST");
	pcsaBody->Add("  else");
	pcsaBody->Add("      flags = OFN_HIDEREADONLY");
	pcsaBody->Add("  end if");
	pcsaBody->Add(" ");   
	pcsaBody->Add("   'ALLOCATE SPACE FOR RETURNED FILENAME");
	pcsaBody->Add("   filename  =  Space$(255) & chr$(0)");
	pcsaBody->Add("   filetitle =  Space$(255) & chr$(0)");
	pcsaBody->Add(" ");   
	pcsaBody->Add("   ofn.lStructSize = Len(ofn)");
	pcsaBody->Add("   ofn.hwndOwner = 0&");
	pcsaBody->Add("   ofn.lpstrFilter = GetStrPointer(filter)");
	pcsaBody->Add("   ofn.nFilterIndex = 1");
	pcsaBody->Add("   ofn.lpstrFile = GetStrPointer(filename)");
	pcsaBody->Add("   ofn.nMaxFile = Len(filename)");
	pcsaBody->Add("   ofn.lpstrFileTitle = GetStrPointer(filetitle)");
	pcsaBody->Add("   ofn.nMaxFileTitle = Len(filetitle)");
	pcsaBody->Add("   ofn.lpstrTitle = GetStrPointer(title)");
	pcsaBody->Add("   ofn.Flags = flags ");         
	pcsaBody->Add("   ofn.lpstrDefExt = GetStrPointer(defext)");
	pcsaBody->Add("   ofn.hInstance = 0");
	pcsaBody->Add("   ofn.lpstrCustomFilter = 0");
	pcsaBody->Add("   ofn.nMaxCustFilter = 0");
	pcsaBody->Add("   ofn.lpstrInitialDir = GetStrPointer(initdir)");
	pcsaBody->Add("   ofn.nFileOffset = 0");
	pcsaBody->Add("   ofn.nFileExtension = 0");
	pcsaBody->Add("   ofn.lCustData = 0");
	pcsaBody->Add("   ofn.lpfnHook = 0");
	pcsaBody->Add("   ofn.lpTemplateName = 0");
	pcsaBody->Add(" ");   
	pcsaBody->Add("   nRet = GetOpenFileName(ofn)");    
	pcsaBody->Add(" ");   
	pcsaBody->Add("   if nRet <> 0 then ");  
	pcsaBody->Add("      'REMOVE EMBEDDED CHR(0) AT END BEFORE RETURNING STRING");        
	pcsaBody->Add("      AtmGetOpenFileName = Left$(filename, InStr(filename, Chr$(0)) - 1)");                       
	pcsaBody->Add("   else ");
	pcsaBody->Add("      'USER CANCELED DIALOG, OR ERROR OCCURRED");        
	pcsaBody->Add("      AtmGetOpenFileName = \"\" ");
	pcsaBody->Add("   end if ");     
	pcsaBody->Add(" ");  
	pcsaBody->Add("End Function");
	pcsaBody->Add(" ");
}


void CAG_EOLE_VT_EBM_TEST::declareVariable(AG_VARIABLE agVariable,
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

void CAG_EOLE_VT_EBM_TEST::checkDebug(bool b_Debug,
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



void CAG_EOLE_VT_EBM_TEST::resetVariableFlags()
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