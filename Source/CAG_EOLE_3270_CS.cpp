// Static Model
#include "stdafx.h"
#include "apigen.h"

#include "CAG_EOLE_3270_CS.h"



CAG_EOLE_3270_CS::CAG_EOLE_3270_CS()
{
	resetVariableFlags();
}

CAG_EOLE_3270_CS::~CAG_EOLE_3270_CS()
{
	
}


void CAG_EOLE_3270_CS::generateHeader(CStringArray* pcsaHeader,
									  CStringArray* pcsaBody)
{
	CString csViewOutStuff;
	
	csViewOutStuff.Format( "// ****************************************************************************");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "//                  Attachmate APIGen");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "//              OLE Automation C# Application");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "//" );
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "//   This source file provides a Form1 function prepared to run, as is,");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "//    in a Visual C# dialog application.  To use it, do the following:");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "//   1. run the C# New Application Wizard and specify that you want to create ");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "//      a dialog application.");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "//   2. When the wizard is done copy the text between the two asterisk lines below" );
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "//   3. Copy the file, extra.tlb, from the Extra! home folder into your new project's");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "//      folder. Add it to the references list by ...");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "//      Project\\Add Reference, COM tab, Attachmate EXTRA! 8.0 Object Library, Select button, OK");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "//   After those steps are completed, this source output should compile");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "//   and run as-is.");
	pcsaHeader->Add(csViewOutStuff);

	time_t ltime;
	time( &ltime );

	csViewOutStuff.Format( "//");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "//   Generated:   %s", ctime( &ltime ) );
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "//");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "// ************************* copy text below here ***********************************");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( " " );
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "EXTRA._System sys = new EXTRA.ExtraSystemClass();" );
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "EXTRA.Sessions sss = new EXTRA.ExtraSessionsClass();" );
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "EXTRA._Session ses;" );
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "EXTRA.Screen scr;" );
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "EXTRA.OIA oia;" );
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( " " );
	pcsaHeader->Add(csViewOutStuff);
	
	csViewOutStuff.Format( "       public Form1()" );
	pcsaHeader->Add(csViewOutStuff);
	
	csViewOutStuff.Format( "       {" );
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "            //" );
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "            // Required for Windows Form Designer support" );
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "            //" );
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "            InitializeComponent();" );
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( " " );
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( " " );
	pcsaHeader->Add(csViewOutStuff);

	declareVariable( AG_BSTR, pcsaHeader, &b_BSTR );	
	
	csViewOutStuff.Format( " " );
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "            CFileDialog fileDialog(true, NULL, NULL,");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "            (OFN_FILEMUSTEXIST | OFN_HIDEREADONLY | OFN_LONGNAMES | OFN_PATHMUSTEXIST),");
	pcsaHeader->Add(csViewOutStuff);

    csViewOutStuff.Format( "            _T(\"Extra! files (*.edp)|*.edp|INFOConnect files (*.adp)|*.adp|All Files (*.*)|*.*||\"));" );
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "            fileDialog.m_ofn.lpstrTitle = _T(\"Select session file\");" );
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "            TCHAR filenameBuffer[4096] = { 0 };");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "            fileDialog.m_ofn.lpstrFile = filenameBuffer;");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "            fileDialog.m_ofn.nMaxFile = sizeof(filenameBuffer) / sizeof(filenameBuffer[0]);" );
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( " " );
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "            // open the session file" );
	pcsaHeader->Add(csViewOutStuff);
	csViewOutStuff.Format( "            if (IDOK == fileDialog.DoModal())" );
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "            {" );
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "                csSessName = fileDialog.GetPathName();" );
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "            }" );
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "                else" );
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "            {" );
	pcsaHeader->Add(csViewOutStuff);
	csViewOutStuff.Format( "                AfxMessageBox(\"No session file, no program execution!\");" );
	pcsaHeader->Add(csViewOutStuff);
	csViewOutStuff.Format( "                return FALSE;" );
	pcsaHeader->Add(csViewOutStuff);
	csViewOutStuff.Format( "            }" );
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( " " );
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "            bstrUtility.bstrVal = csSessName.AllocSysString();");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "            poSessions = poSystem->Sessions;");
	pcsaHeader->Add(csViewOutStuff);
	   
	csViewOutStuff.Format( "            poSession = (EXTRA.ExtraSession) poSessions->Open( bstrUtility.bstrVal );" );
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "" );
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "            if ( poSession == null )" );
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "            {" );
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "                MessageBox.Show(this, \"Connect Session Failed\", \"Error\", MessageBoxButtons.OK );" );
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "            }" );
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "            else" );
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "            {" );
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "                   // display new screen when ready" );
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "                   //   scr = (EXTRA.ExtraScreen) ses.Screen;" );
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "                   poScreen = poSession->Screen;");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "                   poWaits = poSystem->GetWaits();");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( " " );
	pcsaHeader->Add(csViewOutStuff);




}


void CAG_EOLE_3270_CS::appendBody(int nFunctionNum,
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

	csViewOutStuff.Format( "                  // *** %s", csFunctionName );
	pcsaBody->Add(csViewOutStuff);

	CString	csLocal;

	switch ( nFunctionNum )
	{
		
		// **************************** OIA ******************************		
		case 0:		// Screen.OIA.ConnectionStatus
		{
			if ( !bOIA )
			{
				declareVariable( AG_OIA, pcsaBody, &bOIA );
			}

			if ( !b_nStatus )
			{
				declareVariable( AG_STATUS, pcsaHeader, &b_nStatus );
			}

			csViewOutStuff.Format( "                  nStatus = poOIA->GetConnectionStatus();");
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( " " );
			pcsaBody->Add(csViewOutStuff);

		}
		break;
			


		case 1:		// Screen.OIA.ErrorStatus
		{
			if ( !bOIA )
			{
				declareVariable( AG_OIA, pcsaBody, &bOIA );
			}

			if ( !b_nStatus )
			{
				declareVariable( AG_STATUS, pcsaHeader, &b_nStatus );
			}

			csViewOutStuff.Format( "                  nStatus = poOIA->GetErrorStatus();");
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( " " );
			pcsaBody->Add(csViewOutStuff);

		}
		break;


		case 2:		// Screen->OIA.Updated
		{
			if ( !bOIA )
			{
				declareVariable( AG_OIA, pcsaBody, &bOIA );
			}

			if ( !b_bUpdated )
			{
				declareVariable( AG_UPDATED, pcsaHeader, &b_bUpdated );
			}
			
			csViewOutStuff.Format( "                  bUpdated = poOIA->GetUpdated();");
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( " " );
			pcsaBody->Add(csViewOutStuff);

		}
		break;


		case 3:		// Screen.OIA.Value
		{
			if ( !bOIA )
			{
				declareVariable( AG_OIA, pcsaBody, &bOIA );
			}

			if ( !b_BSTR )
			{
				declareVariable( AG_BSTR, pcsaHeader, &b_BSTR );
			}
			else
			{
				csLocal.Format( "                  SysFreeString (bstrUtility.bstrVal);");
				pcsaBody->Add(csLocal);
			}


			csViewOutStuff.Format( "                  bstrUtility.bstrVal = SysAllocString ( poOIA->GetValue() );" );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "                  CString csTest( bstrUtility.bstrVal );" );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( " " );
			pcsaBody->Add(csViewOutStuff);

		}
		break;


		case 4:		// Screen.OIA.XStatus
		{
			if ( !bOIA )
			{
				declareVariable( AG_OIA, pcsaBody, &bOIA );
			}

			if ( !b_nStatus )
			{
				declareVariable( AG_STATUS, pcsaHeader, &b_nStatus );
			}

			csViewOutStuff.Format( "                  nStatus = poOIA->GetXStatus();");
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( " " );
			pcsaBody->Add(csViewOutStuff);

		}
		break;


	
	// **************************** SCREEN ******************************	
	case 5:		// Screen::Col
		{
			if ( !b_nColumn )
			{
				declareVariable( AG_COLUMN, pcsaHeader, &b_nColumn );
			}
			csViewOutStuff.Format( "                  nColumn.iVal = poScreen->GetCol();");
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( " " );
			pcsaBody->Add(csViewOutStuff);
		}
		break;


		case 6:		// Screen::Copy
		{

			csViewOutStuff.Format( "                  poArea = poScreen->SelectAll();");
			pcsaBody->Add(csViewOutStuff);
			csViewOutStuff.Format( "                  poScreen->Copy();   // screen copied to clipboard");
			pcsaBody->Add(csViewOutStuff);
			csViewOutStuff.Format( " " );
			pcsaBody->Add(csViewOutStuff);

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


			csViewOutStuff.Format( "                  nRow.iVal = %s;", pcsaArguments->GetAt(1) );
			pcsaBody->Add(csViewOutStuff);
			csViewOutStuff.Format( "                  nColumn.iVal = %s;", pcsaArguments->GetAt(2) );
			pcsaBody->Add(csViewOutStuff);
			csViewOutStuff.Format( " " );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "                  nAttribute = poScreen->FieldAttribute( nRow.iVal, nColumn.iVal );");
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( " " );
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

			if ( !b_nLength )
			{
				declareVariable( AG_LENGTH, pcsaHeader, &b_nLength );
			}

			if ( !b_BSTR )
			{
				declareVariable( AG_BSTR, pcsaHeader, &b_BSTR );
			}
			else
			{
				csLocal.Format( "                  SysFreeString (bstrUtility.bstrVal);");
				pcsaBody->Add(csLocal);
			}

			
			csViewOutStuff.Format( "                  nRow.iVal = %s;", pcsaArguments->GetAt(1) );
			pcsaBody->Add(csViewOutStuff);
			csViewOutStuff.Format( "                  nColumn.iVal = %s;", pcsaArguments->GetAt(2) );
			pcsaBody->Add(csViewOutStuff);
			csViewOutStuff.Format( "                  nLength.lVal = %s;", pcsaArguments->GetAt(3) );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( " " );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "                  bstrUtility.bstrVal = SysAllocString ( poScreen->GetString( nRow.iVal, nColumn.iVal, nLength.lVal ) );" );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "                  CString csTest( bstrUtility.bstrVal );" );
			pcsaBody->Add(csViewOutStuff);


			csViewOutStuff.Format( " " );
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

			csViewOutStuff.Format( "                  nRow.iVal = %s;", pcsaArguments->GetAt(1) );
			pcsaBody->Add(csViewOutStuff);
			csViewOutStuff.Format( "                  nColumn.iVal = %s;", pcsaArguments->GetAt(2) );
			pcsaBody->Add(csViewOutStuff);
			csViewOutStuff.Format( " " );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "                  poScreen->MoveTo( nRow.iVal, nColumn.iVal );");
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( " " );
			pcsaBody->Add(csViewOutStuff);

		}
		break;


		case 10:		// Screen.PutString
		{
			if ( !b_nRow )
			{
				declareVariable( AG_ROW, pcsaHeader, &b_nRow );
			}

			if ( !b_nColumn )
			{
				declareVariable( AG_COLUMN, pcsaHeader, &b_nColumn );
			}

			if ( !b_BSTR )
			{
				declareVariable( AG_BSTR, pcsaHeader, &b_BSTR );
			}
			else
			{
				csLocal.Format( "                  SysFreeString (bstrUtility.bstrVal);");
				pcsaBody->Add(csLocal);
			}

			csViewOutStuff.Format( "                  nRow.iVal = %s;", pcsaArguments->GetAt(1) );
			pcsaBody->Add(csViewOutStuff);
			csViewOutStuff.Format( "                  nColumn.iVal = %s;", pcsaArguments->GetAt(2) );
			pcsaBody->Add(csViewOutStuff);
			
			csViewOutStuff.Format( " " );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "                  CsBStr = \"%s\";", pcsaArguments->GetAt(3) );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "                  bstrUtility.bstrVal = csBStr.AllocSysString();" );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "                  hr = poScreen->PutString( bstrUtility.bstrVal, nRow.iVal, nColumn.iVal );"  );
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
			csViewOutStuff.Format( "                  nRow.iVal = poScreen->GetRow();");
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( " " );
			pcsaBody->Add(csViewOutStuff);
		}
		break;

		
		case 12:	// Screen.Search
		{
			if ( !bAreaOutput )
			{
				declareVariable( AG_AREA_OUTPUT, pcsaHeader, &bAreaOutput );
			}

			if ( !b_nRow )
			{
				declareVariable( AG_ROW, pcsaHeader, &b_nRow );
			}

			if ( !b_nColumn )
			{
				declareVariable( AG_COLUMN, pcsaHeader, &b_nColumn );
			}

			if ( !b_BSTR )
			{
				declareVariable( AG_BSTR, pcsaHeader, &b_BSTR );
			}
			else
			{
				csLocal.Format( "                  SysFreeString (bstrUtility.bstrVal);");
				pcsaBody->Add(csLocal);
			}

			csViewOutStuff.Format( "                  nRow.iVal = %s;", pcsaArguments->GetAt(1) );
			pcsaBody->Add(csViewOutStuff);
			csViewOutStuff.Format( "                  nColumn.iVal = %s;", pcsaArguments->GetAt(2) );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( " " );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "                  CsBStr = \"%s\";", pcsaArguments->GetAt(3) );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "                  bstrUtility.bstrVal = csBStr.AllocSysString();" );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "                  poArea = poScreen->Search( bstrUtility.bstrVal, nRow.iVal, nColumn.iVal );" );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( " " );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "                  poArea->get_Top( &sRetCode1 );");
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "                  poArea->get_Left( &sRetCode2 );");
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "                  poArea->get_Bottom( &sRetCode3 );");
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "                  poArea->get_Right( &sRetCode4 );");
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "                  CsAreaOutput.Format( \"Search results: Area.top = %i; Area.left = %i; Area.bottom = %i; Area.right = %i\", sRetCode1, sRetCode2, sRetCode3, sRetCode4 );");
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "                  AfxMessageBox( csAreaOutput );");
			pcsaBody->Add(csViewOutStuff);

		}
		break;


		case 13:	// Screen.SelectAll
		{
			if ( !bAreaOutput )
			{
				declareVariable( AG_AREA_OUTPUT, pcsaHeader, &bAreaOutput );
			}

			csViewOutStuff.Format( "                  poArea = poScreen->SelectAll();");
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( " " );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "                  poArea->get_Top( &sRetCode1 );");
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "                  poArea->get_Left( &sRetCode2 );");
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "                  poArea->get_Bottom( &sRetCode3 );");
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "                  poArea->get_Right( &sRetCode4 );");
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "                  CsAreaOutput.Format( \"SelectAll results: Area.top = %i; Area.left = %i; Area.bottom = %i; Area.right = %i\", sRetCode1, sRetCode2, sRetCode3, sRetCode4 );");
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "                  AfxMessageBox( csAreaOutput );");
			pcsaBody->Add(csViewOutStuff);

		}
		break;

		case 14:	// Screen.SendKeys
		{
			if ( !b_BSTR )
			{
				declareVariable( AG_BSTR, pcsaHeader, &b_BSTR );
			}
			else
			{
				csLocal.Format( "                  SysFreeString (bstrUtility.bstrVal);");
				pcsaBody->Add(csLocal);
			}

			csViewOutStuff.Format( " " );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "                  CsBStr = \"%s\";", pcsaArguments->GetAt(1) );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "                  bstrUtility.bstrVal = csBStr.AllocSysString();" );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "                  poScreen->SendKeys( bstrUtility.bstrVal );");
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( " " );
			pcsaBody->Add(csViewOutStuff);
		}
		break;



		case 15:	// Screen.Updated
		{
			if ( !b_bUpdated )
			{
				declareVariable( AG_UPDATED, pcsaHeader, &b_bUpdated );
			}

			csViewOutStuff.Format( "                  bUpdated = poScreen->GetUpdated();" );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( " " );
			pcsaBody->Add(csViewOutStuff);

		}
		break;


		case 16:	// WaitForCursor
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

			
			csViewOutStuff.Format( "                  nValue = poSystem->GetTimeoutValue();" );
			pcsaBody->Add(csViewOutStuff);
			csViewOutStuff.Format( "                  poSystem->put_TimeoutValue( 10000 );   // 10 seconds" );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( " " );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "                  nRow.iVal = %s;", pcsaArguments->GetAt(1) );
			pcsaBody->Add(csViewOutStuff);
			csViewOutStuff.Format( "                  nColumn.iVal = %s;", pcsaArguments->GetAt(2) );
			pcsaBody->Add(csViewOutStuff);
			csViewOutStuff.Format( " " );
			pcsaBody->Add(csViewOutStuff);

			if ( nFunctionNum == 16 )
			{
				csViewOutStuff.Format( "                  bRet = poScreen->WaitForCursor( nRow.iVal, nColumn.iVal );");
			}
			else	// 17
			{
				csViewOutStuff.Format( "                  bRet = poScreen->WaitForCursorMove( nRow.iVal, nColumn.iVal );");
			}
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "                  poSystem->put_TimeoutValue( nValue );   // Reset to previous" );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( " " );
			pcsaBody->Add(csViewOutStuff);

		}
		break;



		case 18:	// WaitForKeys
		{
			if ( !b_bRet )
			{
				declareVariable( AG_RETURN, pcsaHeader, &b_bRet );
			}

			if ( !b_nTimeout )
			{
				declareVariable( AG_TIMEOUT, pcsaHeader, &b_nTimeout );
			}

			if ( !b_BSTR )
			{
				declareVariable( AG_BSTR, pcsaHeader, &b_BSTR );
			}
			else
			{
				csLocal.Format( "                  SysFreeString (bstrUtility.bstrVal);");
				pcsaBody->Add(csLocal);
			}

			if ( !b_bProcessKeystrokes )
			{
				declareVariable( AG_PROCESS_KEYSTROKES, pcsaHeader, &b_bProcessKeystrokes );
			}

			
			csViewOutStuff.Format( "                  nTimeout.lVal = %s;", pcsaArguments->GetAt(1) );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "                  CsBStr = \"%s\";", pcsaArguments->GetAt(2) );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "                  bstrUtility.bstrVal = csBStr.AllocSysString();" );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "                  bProcessKeystrokes.lVal = %s;", pcsaArguments->GetAt(3) );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( " " );
			pcsaBody->Add(csViewOutStuff);


			csViewOutStuff.Format( "                  bRet = poScreen->WaitForKeys( nTimeout.lVal, bstrUtility.bstrVal, bProcessKeystrokes.lVal);" );
			pcsaBody->Add(csViewOutStuff);

		}
		break;


		case 21:	// WaitHostQuiet
		{
			if ( !b_bRet )
			{
				declareVariable( AG_RETURN, pcsaHeader, &b_bRet );
			}

			if ( !b_nSettleTime )
			{
				declareVariable( AG_SETTLE_TIME, pcsaHeader, &b_nSettleTime );
			}

			csViewOutStuff.Format( "                  nSettleTime.lVal = %s;", pcsaArguments->GetAt(1) );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "                  bRet = poScreen->WaitHostQuiet( nSettleTime.lVal );" );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( " " );
			pcsaBody->Add(csViewOutStuff);

		}
		break;

		// **************************** SESSION ******************************
		case 22:	// Session::Activate
		{
			csViewOutStuff.Format( "                  poSession->Activate();");
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( " " );
			pcsaBody->Add(csViewOutStuff);

		}
		break;


		case 23:	// Session::ClearComm
		{
			csViewOutStuff.Format( "                  poSession->ClearComm();");
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( " " );
			pcsaBody->Add(csViewOutStuff);

		}
		break;

		case 24:	//	Session::ClearHistory
		{
			csViewOutStuff.Format( "                  poSession->ClearHistory();");
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( " " );
			pcsaBody->Add(csViewOutStuff);

		}
		break;

		case 19:	// WaitForStream
		{
			if ( !b_nTimeout )
			{
				declareVariable( AG_TIMEOUT, pcsaHeader, &b_nTimeout );
			}

			if ( !b_nIdleTime )
			{
				declareVariable( AG_IDLE_TIME, pcsaHeader, &b_nIdleTime );
			}

			if ( !b_nWaitOption )
			{
				declareVariable( AG_WAIT_OPTION, pcsaHeader, &b_nWaitOption );
			}

			if ( !b_nWaitID )
			{
				declareVariable( AG_WAIT_ID, pcsaHeader, &b_nWaitID );
			}

			if ( !b_nRetCode )
			{
				declareVariable( AG_RETURN_CODE, pcsaHeader, &b_nRetCode );
			}

			csViewOutStuff.Format( "                  nIdleTime.iVal = 1000;" );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "                  nTimeout.iVal = 5000;" );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "                  nWaitOption.iVal = xNoCase;" );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( " " );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "                  poScreenWait = poScreen->WaitForStream( \"Booger\", nIdleTime.iVal, nTimeout.iVal, nWaitOption.iVal );" );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( " " );
			pcsaBody->Add(csViewOutStuff);


			csViewOutStuff.Format( "                  nWaitID = poWaits->Add(poScreenWait);" );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "                  // nRetCode = poWaits->Wait( nTimeout.iVal );   // ERROR!  This is failing" );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "                  if ( nRetCode == nWaitID )" );
			pcsaBody->Add(csViewOutStuff);
			
			csViewOutStuff.Format( "                  {" );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "                        AfxMessageBox(\"String found in stream\");" );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "                  }");
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "                  else" );
			pcsaBody->Add(csViewOutStuff);
			
			csViewOutStuff.Format( "                  {" );
			pcsaBody->Add(csViewOutStuff);
			
			csViewOutStuff.Format( "                        AfxMessageBox(\"Stream search timed out\");" );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "                  }" );
			pcsaBody->Add(csViewOutStuff);

		}
		break;

		case 20:	// WaitForString
		{
			if ( !b_BSTR )
			{
				declareVariable( AG_BSTR, pcsaHeader, &b_BSTR );
			}
			else
			{
				csLocal.Format( "                  SysFreeString (bstrUtility.bstrVal);");
				pcsaBody->Add(csLocal);
			}

			if ( !b_nRow )
			{
				declareVariable( AG_ROW, pcsaHeader, &b_nRow );
			}

			if ( !b_nColumn )
			{
				declareVariable( AG_COLUMN, pcsaHeader, &b_nColumn );
			}

			csViewOutStuff.Format( "                  CsBStr = \"%s\";", pcsaArguments->GetAt(1) );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "                  bstrUtility.bstrVal = csBStr.AllocSysString();" );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "                  nRow.iVal = %s;", pcsaArguments->GetAt(2) );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "                  nColumn.iVal = %s;", pcsaArguments->GetAt(3) );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( " " );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "                  poScreenWait = poScreen->WaitForString( bstrUtility.bstrVal, nRow.iVal, nColumn.iVal );" );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( " " );
			pcsaBody->Add(csViewOutStuff);


			csViewOutStuff.Format( "                  nWaitID = poWaits->Add(poScreenWait);" );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "                  // nRetCode = poWaits->Wait( nTimeout.iVal );   // ERROR!  This is failing" );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "                  if ( nRetCode == nWaitID )" );
			pcsaBody->Add(csViewOutStuff);
			
			csViewOutStuff.Format( "                  {" );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "                        AfxMessageBox(\"String found\");" );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "                  }");
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "                  else" );
			pcsaBody->Add(csViewOutStuff);
			
			csViewOutStuff.Format( "                  {" );
			pcsaBody->Add(csViewOutStuff);
			
			csViewOutStuff.Format( "                        AfxMessageBox(\"String search timed out\");" );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "                  }" );
			pcsaBody->Add(csViewOutStuff);



		}
		break;


		case 31:	// FileTransferOptions
		{
			csViewOutStuff.Format( "                  //     Function %i is not implemented yet.", nFunctionNum );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( " " );
			pcsaBody->Add(csViewOutStuff);
		}
		break;

	
		case 25:	// Session::Close
		{
			csViewOutStuff.Format( "                  poSession->Close();");
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( " " );
			pcsaBody->Add(csViewOutStuff);

		}
		break;


		case 26:	// Session::CloseEx
		{
			
			if ( !b_nCloseOption )
			{
				declareVariable( AG_CLOSEOPTION, pcsaHeader, &b_nCloseOption );
			}

			csViewOutStuff.Format( "                  nCloseOption.lVal = %s;", pcsaArguments->GetAt(1) );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "                  poSession->CloseEx( nCloseOption );");
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( " " );
			pcsaBody->Add(csViewOutStuff);

		}
		break;


		case 27:	// Session::ClosePrintJob
		{
			csViewOutStuff.Format( "                  poSession->ClosePrintJob();");
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( " " );
			pcsaBody->Add(csViewOutStuff);

		}
		break;

		case 28:	// Session::Connected
		{
			if ( !b_bRet )
			{
				declareVariable( AG_RETURN, pcsaHeader, &b_bRet );
			}

			csViewOutStuff.Format( "                  bRet = poSession->GetConnected();");
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( " " );
			pcsaBody->Add(csViewOutStuff);

		}
		break;

		case 29:	// Session::EnlargeFont
		{
			csViewOutStuff.Format( "                  poSession->EnlargeFont();");
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( " " );
			pcsaBody->Add(csViewOutStuff);

		}
		break;


		case 30:	// Session::FileTransferHostOS
		{
			if ( !b_nFTHostOS )
			{
				declareVariable( AG_HOST_OS, pcsaHeader, &b_nFTHostOS );
			}

			csViewOutStuff.Format( "                  //   nFTHostOS.iVal = poSession->GetFileTransferHostOS();   //  causes an exception");
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( " " );
			pcsaBody->Add(csViewOutStuff);

		}
		break;


		case 32:	// Session::FileTransferScheme
		{
			CString csSetFTScheme;
			if ( !b_csFTScheme )
			{
				declareVariable( AG_FT_SCHEME, pcsaHeader, &b_csFTScheme );
			}

			csSetFTScheme= pcsaArguments->GetAt(1);
			
			if ( csSetFTScheme.Find( "FALSE", 0 ) != -1 )
			{
				csViewOutStuff.Format( "                  CsFTTransferScheme = ftSchemeString;" );
				pcsaBody->Add(csViewOutStuff);
				csViewOutStuff.Format( "                  bstrUtility.bstrVal = csFTTransferScheme.AllocSysString();");
				pcsaBody->Add(csViewOutStuff);

				csViewOutStuff.Format( "                  bstrUtility.bstrVal = poSession->GetFileTransferScheme();" );
				pcsaBody->Add(csViewOutStuff);

				csViewOutStuff.Format( "                  CsFTTransferScheme = bstrUtility.bstrVal;" );
				pcsaBody->Add(csViewOutStuff);

				csViewOutStuff.Format( " " );
				pcsaBody->Add(csViewOutStuff);
			}
			else
			{
				if ( !b_BSTR )
				{
					declareVariable( AG_BSTR, pcsaHeader, &b_BSTR );
				}
				else
				{
					csLocal.Format( "                  SysFreeString (bstrUtility.bstrVal);");
					pcsaBody->Add(csLocal);
				}


				csViewOutStuff.Format( "                  CsBStr = \"%s\";", pcsaArguments->GetAt(2) );
				csViewOutStuff.Replace( "\\", "\\\\" );
				pcsaBody->Add(csViewOutStuff);

				csViewOutStuff.Format( "                  bstrUtility.bstrVal = csBStr.AllocSysString();" );
				pcsaBody->Add(csViewOutStuff);

				csViewOutStuff.Format( " " );
				pcsaBody->Add(csViewOutStuff);

				csViewOutStuff.Format( "                  poSession->FileTransferScheme = bstrUtility.bstrVal;");
				pcsaBody->Add(csViewOutStuff);

				csViewOutStuff.Format( " " );
				pcsaBody->Add(csViewOutStuff);

			}

		}
		break;


		case 33:	// Session::Font
		{
			if ( !b_BSTR )
			{
				declareVariable( AG_BSTR, pcsaHeader, &b_BSTR );
			}
			else
			{
				csLocal.Format( "                  SysFreeString (bstrUtility.bstrVal);");
				pcsaBody->Add(csLocal);
			}

			if ( !b_csFontName )
			{
				declareVariable( AG_FONTNAME, pcsaHeader, &b_csFontName );
			}

			csViewOutStuff.Format( "                  CsBStr = \"%s\";", pcsaArguments->GetAt(1) );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "                  bstrUtility.bstrVal = csBStr.AllocSysString();" );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( " " );
			pcsaBody->Add(csViewOutStuff);
		
			csViewOutStuff.Format( "                  bstrUtility.bstrVal = poSession->GetFont();" );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "                  CsFontName = bstrUtility.bstrVal;" );
			pcsaBody->Add(csViewOutStuff);
			
			csViewOutStuff.Format( " " );
			pcsaBody->Add(csViewOutStuff);

		}
		break;


		case 34:	// Session::Height
		{
			if ( !b_sHeight )
			{
				declareVariable( AG_HEIGHT, pcsaHeader, &b_sHeight );
			}

			if ( pcsaArguments->GetAt(1) == "TRUE" )
			{
				csViewOutStuff.Format( "                  SHeight = %s;", pcsaArguments->GetAt(2) );
				pcsaBody->Add(csViewOutStuff);
				
				csViewOutStuff.Format( "                  poSession->put_Height( sHeight );");
				pcsaBody->Add(csViewOutStuff);
			}
			else
			{
				csViewOutStuff.Format( "                  SHeight = poSession->GetHeight();");
				pcsaBody->Add(csViewOutStuff);
			}

			//GetHeight

			csViewOutStuff.Format( " " );
			pcsaBody->Add(csViewOutStuff);
		}
		break;


		case 35:	// Session::HoldScreen
		{
			if ( "TRUE" == pcsaArguments->GetAt(1) )
			{
				csViewOutStuff.Format( "   poSession->put_HoldScreen( TRUE );");
			}
			else
			{
				csViewOutStuff.Format( "   poSession->put_HoldScreen( FALSE );");
			}

			pcsaBody->Add(csViewOutStuff);
			pcsaBody->Add( " " );
		}
		break;


		case 36:	// Session::HostName
		{
			if ( !b_BSTR )
			{
				declareVariable( AG_BSTR, pcsaHeader, &b_BSTR );
			}
			else
			{
				csLocal.Format( "                  SysFreeString (bstrUtility.bstrVal);");
				pcsaBody->Add(csLocal);
			}

			if ( !b_csHostName )
			{
				declareVariable( AG_HOSTNAME, pcsaHeader, &b_csHostName );
			}

			csViewOutStuff.Format( "                  CsBStr = \"%s\";", pcsaArguments->GetAt(2) );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "                  bstrUtility.bstrVal = csBStr.AllocSysString();" );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( " " );
			pcsaBody->Add(csViewOutStuff);
		
			csViewOutStuff.Format( "                  bstrUtility.bstrVal = poSession->GetHostName();" );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "                  CsHostName = bstrUtility.bstrVal;" );
			pcsaBody->Add(csViewOutStuff);
			
			csViewOutStuff.Format( " " );
			pcsaBody->Add(csViewOutStuff);

		}
		break;


		case 37:	// Session::InvokeSettingsDialog
		{
			if ( !b_SettingsDialog )
			{
				declareVariable( AG_SETTINGS_DIALOG, pcsaHeader, &b_SettingsDialog );
			}
	
			csViewOutStuff.Format( "                  // nSettingDialogChoice = xFontPage; // XXXX compile error");
			pcsaBody->Add(csViewOutStuff);
			
			csViewOutStuff.Format( "                  poSession->InvokeSettingsDialog( nSettingDialogChoice );");
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( " " );
			pcsaBody->Add(csViewOutStuff);

		}
		break;


		case 38:	// Session::KeyboardLocked
		{
			if ( "TRUE" == pcsaArguments->GetAt(1) )
			{
				pcsaBody->Add("   poSession->put_KeyboardLocked( TRUE );");
			}
			else
			{
				pcsaBody->Add("   poSession->put_KeyboardLocked( FALSE );");
			}

			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( " " );
			pcsaBody->Add(csViewOutStuff);

		}
		break;



		case 39:	// Session::KeyMap
		{
			CString csKeyMap;
			csKeyMap = pcsaArguments->GetAt(1);

			if ( csKeyMap.Find( "TRUE", 0 ) != -1 )
			{
				if ( !b_BSTR )
				{
					declareVariable( AG_BSTR, pcsaHeader, &b_BSTR );
				}
				else
				{
					csLocal.Format( "                  SysFreeString (bstrUtility.bstrVal);");
					pcsaBody->Add(csLocal);
				}

				csViewOutStuff.Format( "                  CsBStr = \"%s\";", pcsaArguments->GetAt(2) );
				csViewOutStuff.Replace( "\\", "\\\\" );
				pcsaBody->Add(csViewOutStuff);

				csViewOutStuff.Format( "                  bstrUtility.bstrVal = csBStr.AllocSysString();" );
				pcsaBody->Add(csViewOutStuff);

				csViewOutStuff.Format( "                  poSession->put_KeyMap( bstrUtility.bstrVal );" );
				pcsaBody->Add(csViewOutStuff);

				csViewOutStuff.Format( " " );
				pcsaBody->Add(csViewOutStuff);
			}
			else
			{
				if ( !b_pUtilityBuffer )
				{
					declareVariable( AG_UTILBUFFER, pcsaHeader, &b_pUtilityBuffer );
				}
				else
				{
					csLocal.Format( "                  free( pUtilityBuffer );");
					pcsaBody->Add(csLocal);
				}


				csViewOutStuff.Format( "                  pUtilityBuffer = (char *)malloc( 128 );");
				pcsaBody->Add(csViewOutStuff);

				csViewOutStuff.Format( " " );
				pcsaBody->Add(csViewOutStuff);

				csViewOutStuff.Format( "                  Strcpy( pUtilityBuffer, poSession->GetKeyMap() );");
				pcsaBody->Add(csViewOutStuff);

				csViewOutStuff.Format( " " );
				pcsaBody->Add(csViewOutStuff);

			}

		}
		break;


		case 40:	// Session::Language
		{
			CString csLanguage;
			csLanguage = pcsaArguments->GetAt(1);


			if ( csLanguage.Find( "TRUE", 0 ) != -1 )
			{
				if ( !b_BSTR )
				{
					declareVariable( AG_BSTR, pcsaHeader, &b_BSTR );
				}
				else
				{
					csLocal.Format( "                  SysFreeString (bstrUtility.bstrVal);");
					pcsaBody->Add(csLocal);
				}

				csViewOutStuff.Format( "                  CsBStr = \"%s\";", pcsaArguments->GetAt(2) );
				pcsaBody->Add(csViewOutStuff);

				csViewOutStuff.Format( "                  bstrUtility.bstrVal = csBStr.AllocSysString();" );
				pcsaBody->Add(csViewOutStuff);

				csViewOutStuff.Format( "                  poSession->put_Language( bstrUtility.bstrVal );" );
				pcsaBody->Add(csViewOutStuff);

				csViewOutStuff.Format( " " );
				pcsaBody->Add(csViewOutStuff);
			}
			else
			{
				if ( !b_pUtilityBuffer )
				{
					declareVariable( AG_UTILBUFFER, pcsaHeader, &b_pUtilityBuffer );
				}
				else
				{
					csLocal.Format( "                  free( pUtilityBuffer );");
					pcsaBody->Add(csLocal);
				}


				csViewOutStuff.Format( "                  pUtilityBuffer = (char *)malloc( 32 );");
				pcsaBody->Add(csViewOutStuff);

				csViewOutStuff.Format( " " );
				pcsaBody->Add(csViewOutStuff);

				csViewOutStuff.Format( "                  Strcpy( pUtilityBuffer, poSession->GetLanguage() );");
				pcsaBody->Add(csViewOutStuff);

				csViewOutStuff.Format( " " );
				pcsaBody->Add(csViewOutStuff);

			}

		}
		break;


		case 41:	// Session::Local
		{
			CString csLocalMode;
			csLocalMode = pcsaArguments->GetAt(1);

			if ( csLocalMode.Find( "TRUE", 0 ) != -1 )
			{
				csViewOutStuff.Format( "                  poSession->put_Local( TRUE );" );
				pcsaBody->Add(csViewOutStuff);
			}
			else
			{
				if ( !b_bLocalMode )
				{
					declareVariable( AG_LOCALMODE, pcsaHeader, &b_bLocalMode );
				}

				csViewOutStuff.Format( "                  bLocalMode = poSession->GetLocal();" );
				pcsaBody->Add(csViewOutStuff);
			}
		}
		break;

		case 42:	// Session::Menu
		{
			CString csLocalMode;
			csLocalMode = pcsaArguments->GetAt(1);

			if ( csLocalMode.Find( "TRUE", 0 ) != -1 )
			{
				csViewOutStuff.Format( "                  poSession->put_Menu( TRUE );" );
				pcsaBody->Add(csViewOutStuff);
			}
			else
			{
				if ( !b_bMenuVisible )
				{
					declareVariable( AG_MENU_VISIBLE, pcsaHeader, &b_bMenuVisible );
				}

				csViewOutStuff.Format( "                  bMenuVisible = poSession->GetMenu();" );
				pcsaBody->Add(csViewOutStuff);
			}
		}
		break;

		case 43:	// Session::Name
		{
			if ( !b_pUtilityBuffer )
			{
				declareVariable( AG_UTILBUFFER, pcsaHeader, &b_pUtilityBuffer );
			}
			else
			{
				csLocal.Format( "                  free( pUtilityBuffer );");
				pcsaBody->Add(csLocal);
			}

			csViewOutStuff.Format( " " );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "                  pUtilityBuffer = (char *)malloc( 128 );");
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( " " );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "                  Strcpy( pUtilityBuffer, poSession->Name );");
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( " " );
			pcsaBody->Add(csViewOutStuff);
		}
		break;

		case 44:	// Session::PrintDisplay
		{
			csViewOutStuff.Format( "                  poSession->PrintDisplay();" );
			pcsaBody->Add(csViewOutStuff);
		}
		break;

		case 45:	// Session::Quiet
		{
			CString csQuietState;
			csQuietState = pcsaArguments->GetAt(1);
			if ( csQuietState.Find( "TRUE", 0 ) != -1 )
			{
				csViewOutStuff.Format( "                  poSession->put_Quiet( TRUE );" );
				pcsaBody->Add(csViewOutStuff);
			}
			else
			{
				if ( !b_bSessionQuiet )
				{
					declareVariable( AG_SESS_QUIET, pcsaHeader, &b_bSessionQuiet );
				}

				csViewOutStuff.Format( "                  bSessionQuiet = poSession->GetQuiet();" );
				pcsaBody->Add(csViewOutStuff);
			}
		}
		break;


		case 46:	// Session::ReceiveFile
		{
			if ( !b_FT_PCFileBSTR )
			{
				declareVariable( AG_PCFILE_BSTR, pcsaHeader, &b_FT_PCFileBSTR );
			}
			else
			{
				csLocal.Format( "                  SysFreeString (FT_PCFileBSTR.bstrVal);");
				pcsaBody->Add(csLocal);
			}

			if ( !b_FT_HostFileBSTR )
			{
				declareVariable( AG_HOSTFILE_BSTR, pcsaHeader, &b_FT_HostFileBSTR );
			}
			else
			{
				csLocal.Format( "                  SysFreeString (FT_HostFileBSTR.bstrVal);");
				pcsaBody->Add(csLocal);
			}

			csViewOutStuff.Format( "                  CsFT_PCFileBSTR = \"%s\";", pcsaArguments->GetAt(1) );
			csViewOutStuff.Replace( "\\", "\\\\" );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "                  fT_PCFileBSTR.bstrVal = csFT_PCFileBSTR.AllocSysString();" );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "                  CsFT_HostFileBSTR = \"%s\";", pcsaArguments->GetAt(2) );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "                  fT_HostFileBSTR.bstrVal = csFT_HostFileBSTR.AllocSysString();" );
			pcsaBody->Add(csViewOutStuff);


			csViewOutStuff.Format( " " );
			pcsaBody->Add(csViewOutStuff);

			if ( !b_bRet )
			{
				declareVariable( AG_RETURN, pcsaHeader, &b_bRet );
			}

			CString csShowFTStatus;
			csShowFTStatus = pcsaArguments->GetAt(3);
			csViewOutStuff.Format( "                  bRet = poSession->ReceiveFile( FT_PCFileBSTR.bstrVal, FT_HostFileBSTR.bstrVal, %s );", csShowFTStatus );
			pcsaBody->Add(csViewOutStuff);
		}
		break;

		case 47:	// Session::ReduceFont
		{
			csViewOutStuff.Format( "                  poSession->ReduceFont();" );
			pcsaBody->Add(csViewOutStuff);
		}
		break;


		case 48:	// Session::Reset
		{
			csViewOutStuff.Format( "                  poSession->Reset();" );
			pcsaBody->Add(csViewOutStuff);
		}
		break;


		case 49:	// Session::Save
		{
			csViewOutStuff.Format( "                  poSession->Save();" );
			pcsaBody->Add(csViewOutStuff);
		}
		break;


		case 50:	// Session::SaveAs
		{
			csViewOutStuff.Format( "                  poSession->SaveAs( \"%s\" );", pcsaArguments->GetAt(1) );
			csViewOutStuff.Replace( "\\", "\\\\" );
			pcsaBody->Add(csViewOutStuff);
		}
		break;


		case 51:	// Session::Saved
		{
			if ( !b_bSessionSaved )
			{
				declareVariable( AG_SESS_SAVED, pcsaHeader, &b_bSessionSaved );
			}

			csViewOutStuff.Format( "                  bSessionSaved = poSession->GetSaved();" );
			pcsaBody->Add(csViewOutStuff);
		}
		break;

		case 52:	// Session::SendFile
		{
			if ( !b_FT_PCFileBSTR )
			{
				declareVariable( AG_PCFILE_BSTR, pcsaHeader, &b_FT_PCFileBSTR );
			}
			else
			{
				csLocal.Format( "                  SysFreeString (FT_PCFileBSTR.bstrVal);");
				pcsaBody->Add(csLocal);
			}

			if ( !b_FT_HostFileBSTR )
			{
				declareVariable( AG_HOSTFILE_BSTR, pcsaHeader, &b_FT_HostFileBSTR );
			}
			else
			{
				csLocal.Format( "                  SysFreeString (FT_HostFileBSTR.bstrVal);");
				pcsaBody->Add(csLocal);
			}

			csViewOutStuff.Format( "                  CsFT_PCFileBSTR = \"%s\";", pcsaArguments->GetAt(1) );
			csViewOutStuff.Replace( "\\", "\\\\" );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "                  fT_PCFileBSTR.bstrVal = csFT_PCFileBSTR.AllocSysString();" );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "                  CsFT_HostFileBSTR = \"%s\";", pcsaArguments->GetAt(2) );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "                  fT_HostFileBSTR.bstrVal = csFT_HostFileBSTR.AllocSysString();" );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( " " );
			pcsaBody->Add(csViewOutStuff);

			if ( !b_bRet )
			{
				declareVariable( AG_RETURN, pcsaHeader, &b_bRet );
			}


			CString csShowFTStatus;
			csShowFTStatus = pcsaArguments->GetAt(3);
			csViewOutStuff.Format( "                  bRet = poSession->SendFile( FT_PCFileBSTR.bstrVal, FT_HostFileBSTR.bstrVal, %s );", csShowFTStatus );
			pcsaBody->Add(csViewOutStuff);
		}
		break;


		case 53:	// Session::Title
		{
			if ( !b_pUtilityBuffer )
			{
				declareVariable( AG_UTILBUFFER, pcsaHeader, &b_pUtilityBuffer );
			}
			else
			{
				csLocal.Format( "                  free( pUtilityBuffer );");
				pcsaBody->Add(csLocal);
			}

			csViewOutStuff.Format( " " );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "                  pUtilityBuffer = (char *)malloc( %i );", (pcsaArguments->GetAt(1)).GetLength()+1 );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "                  Strcpy( pUtilityBuffer, \"%s\" )", pcsaArguments->GetAt(1) );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "                  poSession->Title( pUtilityBuffer );");
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( " " );
			pcsaBody->Add(csViewOutStuff);
		}
		break;


		case 54:	// Session::TransferFile
		{
			csViewOutStuff.Format( "                  poSession->TransferFile;" );
			pcsaBody->Add(csViewOutStuff);
		}
		break;

		case 55:	// Session::Type
		{
			if ( !b_nType )
			{
				declareVariable( AG_TYPE, pcsaHeader, &b_nType );
			}

			csViewOutStuff.Format( "                  nType = poSession->Type;" );
			pcsaBody->Add(csViewOutStuff);
		}
		break;


		case 56:	// Session::UpdateStatusBar
		{
			if ( !b_pUtilityBuffer )
			{
				declareVariable( AG_UTILBUFFER, pcsaHeader, &b_pUtilityBuffer );
			}
			else
			{
				csLocal.Format( "                  free( pUtilityBuffer );");
				pcsaBody->Add(csLocal);
			}

			csViewOutStuff.Format( " " );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "                  pUtilityBuffer = (char *)malloc( %i );", (pcsaArguments->GetAt(1)).GetLength()+1 );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "                  Strcpy( pUtilityBuffer, \"%s\" )", pcsaArguments->GetAt(1) );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "                  poSession->UpdateStatusBar( pUtilityBuffer );");
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( " " );
			pcsaBody->Add(csViewOutStuff);
		}
		break;


		case 57:	// Session::Visible
		{
			if ( !b_bRet )
			{
				declareVariable( AG_RETURN, pcsaHeader, &b_bRet );
			}

			CString csSessionVisible;
			csSessionVisible = pcsaArguments->GetAt(1);
			if ( csSessionVisible.Find( "TRUE", 0 ) != -1 )
			{
				csViewOutStuff.Format( "                  poSession->Visible = TRUE;" );
				pcsaBody->Add(csViewOutStuff);
			}
			else
			{
				csViewOutStuff.Format( "                  bRet = poSession->Visible;" );
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

			csViewOutStuff.Format( "                  nTimeout = %s;", pcsaArguments->GetAt(1) );
			pcsaBody->Add(csViewOutStuff);
			
			csViewOutStuff.Format( "                  bRet = poSession->WaitForDisconnect( nTimeout );");
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( " " );
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

			csViewOutStuff.Format( "                  nTimeout = %s;", pcsaArguments->GetAt(1) );
			pcsaBody->Add(csViewOutStuff);
			
			if ( pcsaArguments->GetAt(2) == "TRUE" )
			{
				csViewOutStuff.Format( "                  bRet = poSession->WaitForTimer( nTimeout, TRUE );");
				pcsaBody->Add(csViewOutStuff);
			}
			else
			{
				csViewOutStuff.Format( "                  bRet = poSession->WaitForTimer( nTimeout, FALSE );");
				pcsaBody->Add(csViewOutStuff);
			}

			csViewOutStuff.Format( " " );
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
				csViewOutStuff.Format( "                  nWidth = %s", pcsaArguments->GetAt(2) );
				pcsaBody->Add(csViewOutStuff);
				
				csViewOutStuff.Format( "                  poSession->Width = nWidth;");
				pcsaBody->Add(csViewOutStuff);
			}
			else
			{
				csViewOutStuff.Format( "                  nWidth = poSession->Width;");
				pcsaBody->Add(csViewOutStuff);
			}

			csViewOutStuff.Format( " " );
			pcsaBody->Add(csViewOutStuff);

		}
		break;


		case 61:	// Session::WindowHandle
		{
			if ( !b_bWindowHandle )
			{
				declareVariable( AG_WINDOW_HANDLE, pcsaHeader, &b_bWindowHandle );
			}

			csViewOutStuff.Format( "                  hSession = poScreen->WindowHandle;" );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( " " );
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
				csViewOutStuff.Format( "                  nWindowState = %s", pcsaArguments->GetAt(2) );
				pcsaBody->Add(csViewOutStuff);
				
				csViewOutStuff.Format( "                  poSession->WindowState = nWindowState;");
				pcsaBody->Add(csViewOutStuff);
			}
			else
			{
				csViewOutStuff.Format( "                  nWindowState = poSession->WindowState;");
				pcsaBody->Add(csViewOutStuff);
			}

			csViewOutStuff.Format( " " );
			pcsaBody->Add(csViewOutStuff);

		}
		break;

		// **************************** SESSIONS ******************************

		case 63:	// Sessions::Open
		{

			if ( !b_SessionOpen )
			{
				declareVariable( AG_SESS_OPEN, pcsaHeader, &b_SessionOpen );
			}

			csViewOutStuff.Format( "                  Strcpy( pSessName, \"%s\" );", pcsaArguments->GetAt(1) );
			csViewOutStuff.Replace( "\\", "\\\\" );
			//	\"c:\\\\program files\\\\attachmate\\\\extra!\\\\sessions\\\\auburn2.edp\");" );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( " " );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "                  Ses = (EXTRA.ExtraSession) sss.Open(SessName);");
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

			csViewOutStuff.Format( "                  nCount = poSessions->Count;" );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( " " );
			pcsaBody->Add(csViewOutStuff);

		}
		break;


		case 65:	// Sessions::CloseAll
		{
			csViewOutStuff.Format( "                  poSessions->CloseAll();" );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( " " );
			pcsaBody->Add(csViewOutStuff);

		}
		break;

		
		// **************************** SYSTEM ******************************

		case 66:	// System::ActiveSession
		{
			csViewOutStuff.Format( "                  poSession = poSystem->GetActiveSession();" );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( " " );
			pcsaBody->Add(csViewOutStuff);
		}
		break;

		case 67:	// System::Name
		{
			if ( !b_pUtilityBuffer )
			{
				declareVariable( AG_UTILBUFFER, pcsaHeader, &b_pUtilityBuffer );
			}
			else
			{
				csLocal.Format( "                  free( pUtilityBuffer );");
				pcsaBody->Add(csLocal);
			}


			csViewOutStuff.Format( " " );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "                  pUtilityBuffer = (char *)malloc( 32 );");
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( " " );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "                  Strcpy( pUtilityBuffer, poSystem->GetName() );");
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( " " );
			pcsaBody->Add(csViewOutStuff);

		}
		break;


		case 68:	// System::Quit
		{
			csViewOutStuff.Format( "                  poSystem->Quit();" );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( " " );
			pcsaBody->Add(csViewOutStuff);
		}
		break;


		case 69:	// System::Time
		{
			if ( !b_pUtilityBuffer )
			{
				declareVariable( AG_UTILBUFFER, pcsaHeader, &b_pUtilityBuffer );
			}
			else
			{
				csLocal.Format( "                  free( pUtilityBuffer );");
				pcsaBody->Add(csLocal);
			}


			csViewOutStuff.Format( " " );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "                  pUtilityBuffer = (char *)malloc( 32 );");
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( " " );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "                  Strcpy( pUtilityBuffer, poSystem->GetSystemTime(12) );");
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( " " );
			pcsaBody->Add(csViewOutStuff);

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
				csViewOutStuff.Format( "                  nTimeout.lVal = %s;", pcsaArguments->GetAt(2) );
				pcsaBody->Add(csViewOutStuff);

				csViewOutStuff.Format( "                  poSystem->put_TimeoutValue( nTimeout.lVal );" );
				pcsaBody->Add(csViewOutStuff);
				
				csViewOutStuff.Format( "                  // poSystem->GetTimeoutValue();" );
				pcsaBody->Add(csViewOutStuff);

			}
			else
			{
				csViewOutStuff.Format( "                  nTimeout.lVal = poSystem->GetTimeoutValue();" );
				pcsaBody->Add(csViewOutStuff);

				csViewOutStuff.Format( "                  // nTimeout.lVal = 3000;" );
				pcsaBody->Add(csViewOutStuff);

				csViewOutStuff.Format( "                  // poSystem->put_TimeoutValue( nTimeout.lVal );" );
				pcsaBody->Add(csViewOutStuff);

			}

			csViewOutStuff.Format( " " );
			pcsaBody->Add(csViewOutStuff);

		}
		break;


		case 71:	// System::Version
		{
			if ( !b_pUtilityBuffer )
			{
				declareVariable( AG_UTILBUFFER, pcsaHeader, &b_pUtilityBuffer );
			}
			else
			{
				csLocal.Format( "                  free( pUtilityBuffer );");
				pcsaBody->Add(csLocal);
			}


			csViewOutStuff.Format( " " );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "                  pUtilityBuffer = (char *)malloc( 32 );");
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( " " );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "                  Strcpy( pUtilityBuffer, poSystem->Version );");
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( " " );
			pcsaBody->Add(csViewOutStuff);

		}
		break;


		case 72:
		{
			csViewOutStuff.Format( "                  function ", nFunctionNum, ". is not implemented yet.  ");
			pcsaBody->Add(csViewOutStuff);
			csViewOutStuff.Format( " " );
			pcsaBody->Add(csViewOutStuff);
		}
		break;


		default:
		{
			csViewOutStuff.Format( "                  function ", nFunctionNum, ". Abandon hope, all ye who enter here.  ");
			pcsaBody->Add(csViewOutStuff);
		}

	}
	

	pcsaArguments->RemoveAll();
	
}


void CAG_EOLE_3270_CS::finalize(CStringArray* pcsaBody)
{
	CString csLocal;

	csLocal.Format(" " );
	pcsaBody->Add(csLocal);

	csLocal.Format( "            }" );
	pcsaBody->Add(csLocal);

	csLocal.Format( " " );
	pcsaBody->Add(csLocal);
/*
	csLocal.Format( " " );
	pcsaBody->Add(csLocal);

	csLocal.Format( "       poScreen.Detach();" );
	pcsaBody->Add(csLocal);

	csLocal.Format( "       poScreen = NULL;" );
	pcsaBody->Add(csLocal);

	csLocal.Format( "       poSession.Detach();" );
	pcsaBody->Add(csLocal);

	csLocal.Format( "       poSession = NULL;" );
	pcsaBody->Add(csLocal);

	csLocal.Format( " " );
	pcsaBody->Add(csLocal);
*/
	if ( b_pUtilityBuffer )
	{
		csLocal.Format( "          free( pUtilityBuffer );");
		pcsaBody->Add(csLocal);
	}

	if ( b_BSTR )
	{
		csLocal.Format( "          sysFreeString (bstrUtility.bstrVal);");
		pcsaBody->Add(csLocal);
	}

	csLocal.Format(" " );
	pcsaBody->Add(csLocal);

	csLocal.Format( "          return 1;" );
	pcsaBody->Add(csLocal);

	csLocal.Format(" " );
	pcsaBody->Add(csLocal);

	csLocal.Format( "       }" );
	pcsaBody->Add(csLocal);

	csLocal.Format( "// ************************* copy text above here ***********************************");
	pcsaBody->Add(csLocal);
	
}


void CAG_EOLE_3270_CS::declareVariable(AG_VARIABLE agVariable,
									   CStringArray* pcsaHeader,
									   bool* bValue)
{
	CString csLocal;
	*bValue = TRUE;
	
	switch ( agVariable )
	{
		case AG_STATUS:
		{
			csLocal.Format( "                   int nStatus=0;");
		}
		break;

		case AG_UPDATED:
		{
			csLocal.Format( "                   BOOL bUpdated=FALSE;");
		}
		break;

		case AG_UTILBUFFER:
		{
			csLocal.Format( "                   char *pUtilityBuffer;");
		}
		break;

		case AG_BSTR:
		{
			csLocal.Format( "                   cString csBStr;");
			pcsaHeader->Add(csLocal);

			csLocal.Format( "                   VARIANT bstrUtility;");
			pcsaHeader->Add(csLocal);
			csLocal.Format( "                   ::VariantInit(&bstrUtility);");
			pcsaHeader->Add(csLocal);
			csLocal.Format( "                   BstrUtility.vt=VT_BSTR;");
		}
		break;

		case AG_ROW:
		{
			csLocal.Format( "                   VARIANT nRow;");
			pcsaHeader->Add(csLocal);
			csLocal.Format( "                   ::VariantInit(&nRow);");
			pcsaHeader->Add(csLocal);
			csLocal.Format( "                   nRow.vt=VT_I2;");
		}
		break;


		case AG_SETTINGS_DIALOG:
		{
			csLocal.Format( "                   VARIANT nSettingsDialogChoice;");
			pcsaHeader->Add(csLocal);
			csLocal.Format( "                   ::VariantInit(&nSettingsDialogChoice);");
			pcsaHeader->Add(csLocal);
			csLocal.Format( "                   nSettingsDialogChoice.vt=VT_I2;");
		}
		break;

		case AG_COLUMN:
		{
			csLocal.Format( "                   VARIANT nColumn;");
			pcsaHeader->Add(csLocal);
			csLocal.Format( "                   ::VariantInit(&nColumn);");
			pcsaHeader->Add(csLocal);
			csLocal.Format( "                   nColumn.vt=VT_I2;");
		}
		break;

		case AG_ATTRIBUTE:
		{
			csLocal.Format( "                   int nAttribute=0;");
		}
		break;

		case AG_LENGTH:
		{
			csLocal.Format( "                   VARIANT nLength;");
			pcsaHeader->Add(csLocal);
			csLocal.Format( "                   ::VariantInit(&nLength);");
			pcsaHeader->Add(csLocal);
			csLocal.Format( "                   nLength.vt=VT_I4;");
		}
		break;

		case AG_VALUE:
		{
			csLocal.Format( "                   int nValue=0;");
		}
		break;

		case AG_RETURN:
		{
			csLocal.Format( "                   BOOL bRet=FALSE;");
		}
		break;

		case AG_CLOSEOPTION:
		{
			csLocal.Format( "                   VARIANT nCloseOption;");
			pcsaHeader->Add(csLocal);
			csLocal.Format( "                   ::VariantInit(&nCloseOption);");
			pcsaHeader->Add(csLocal);
			csLocal.Format( "                   nCloseOption.vt=VT_I4;");	// XXX
		}
		break;

		case AG_HOST_OS:
		{
			csLocal.Format( "                   VARIANT nFTHostOS;");
			pcsaHeader->Add(csLocal);
			csLocal.Format( "                   ::VariantInit(&nFTHostOS);");
			pcsaHeader->Add(csLocal);
			csLocal.Format( "                   nFTHostOS.vt=VT_I4;");	// XXX
		}
		break;

		case AG_HEIGHT:
		{
			csLocal.Format( "                   short sHeight=0;");
		}
		break;

		case AG_LOCALMODE:
		{
			csLocal.Format( "                   BOOL bLocalMode=FALSE;");
		}
		break;

		case AG_OIA:
		{
			csLocal.Format( "                   poOIA = poScreen->OIA;");
		}
		break;

		case AG_SESS_SAVED:
		{
			csLocal.Format( "                   BOOL bSessionSaved=FALSE;");
		}
		break;

		case AG_SESS_OPEN:
		{
			csLocal.Format( "                   char SessName[512];");
			pcsaHeader->Add(csLocal);
			csLocal.Format( "                   char* pSessName=SessName;");
		}
		break;


		case AG_SETTLE_TIME:
		{
			csLocal.Format( "                   VARIANT nSettleTime;");
			pcsaHeader->Add(csLocal);
			csLocal.Format( "                   ::VariantInit(&nSettleTime);");
			pcsaHeader->Add(csLocal);
			csLocal.Format( "                   nSettleTime.vt=VT_I4;");	// XXX
		}
		break;

		case AG_SESS_QUIET:
		{
			csLocal.Format( "                   BOOL bSessionQuiet=FALSE;");
		}
		break;

		case AG_MENU_VISIBLE:
		{
			csLocal.Format( "                   BOOL bMenuVisible=FALSE;");
		}
		break;

		case AG_TYPE:
		{
			csLocal.Format( "                   int nType=0;");
		}
		break;

		case AG_TIMEOUT:
		{
			csLocal.Format( "                   VARIANT nTimeout;");
			pcsaHeader->Add(csLocal);
			csLocal.Format( "                   ::VariantInit(&nTimeout);");
			pcsaHeader->Add(csLocal);
			csLocal.Format( "                   nTimeout.vt=VT_I4;");	// XXX int
		}
		break;

		case AG_PROCESS_KEYSTROKES:
		{
			csLocal.Format( "                   VARIANT bProcessKeystrokes;");
			pcsaHeader->Add(csLocal);
			csLocal.Format( "                   ::VariantInit(&bProcessKeystrokes);");
			pcsaHeader->Add(csLocal);
			csLocal.Format( "                   nColumn.vt=VT_I4;");	// XXX	BOOL
		}
		break;

		case AG_WIDTH:
		{
			csLocal.Format( "                   int nWidth=0;");
		}
		break;

		case AG_WINDOW_HANDLE:
		{
			csLocal.Format( "                   HANDLE hSession=NULL;");
		}
		break;

		case AG_WINDOW_STATE:
		{
			csLocal.Format( "                   int nWindowState=0;");
		}
		break;

		case AG_COUNT:
		{
			csLocal.Format( "                   int nCount=0;");
		}
		break;

		case AG_AREA:
		{
			csLocal.Format( "                   int Area=0;");
		}
		break;

		case AG_HOSTNAME:
		{
			csLocal.Format( "                   cString csHostName;");
		}
		break;

		case AG_FONTNAME:
		{
			csLocal.Format( "                   cString csFontName;");
		}
		break;

		case AG_FT_SCHEME:
		{
			csLocal.Format( "                   char ftSchemeString[512] = {0};");
			pcsaHeader->Add(csLocal);

			csLocal.Format( "                   cString csFTTransferScheme;");
		}
		break;

		case AG_HOSTFILE_BSTR:
		{
			csLocal.Format( "                   cString csFT_HostFileBSTR;");
			pcsaHeader->Add(csLocal);

			csLocal.Format( "                   VARIANT FT_HostFileBSTR;");
			pcsaHeader->Add(csLocal);
			csLocal.Format( "                   ::VariantInit(&FT_HostFileBSTR);");
			pcsaHeader->Add(csLocal);
			csLocal.Format( "                   FT_HostFileBSTR.vt=VT_BSTR;");
		}
		break;

		case AG_PCFILE_BSTR:
		{
			csLocal.Format( "                   cString csFT_PCFileBSTR;");
			pcsaHeader->Add(csLocal);

			csLocal.Format( "                   VARIANT FT_PCFileBSTR;");
			pcsaHeader->Add(csLocal);
			csLocal.Format( "                   ::VariantInit(&FT_PCFileBSTR);");
			pcsaHeader->Add(csLocal);
			csLocal.Format( "                   FT_PCFileBSTR.vt=VT_BSTR;");
		}
		break;

		case AG_IDLE_TIME:
		{
			csLocal.Format( "                   VARIANT nIdleTime;");
			pcsaHeader->Add(csLocal);
			csLocal.Format( "                   ::VariantInit(&nIdleTime);");
			pcsaHeader->Add(csLocal);
			csLocal.Format( "                   nIdleTime.vt=VT_I4;");
		}
		break;

		case AG_WAIT_OPTION:
		{
			csLocal.Format( "                   VARIANT nWaitOption;");
			pcsaHeader->Add(csLocal);
			csLocal.Format( "                   ::VariantInit(&nWaitOption);");
			pcsaHeader->Add(csLocal);
			csLocal.Format( "                   nWaitOption.vt=VT_I4;");
		}
		break;

		case AG_WAIT_ID:
		{
			csLocal.Format( "                   int nWaitID=0;");
		}
		break;

		case AG_RETURN_CODE:
		{
			csLocal.Format( "                   int nRetCode=0;");
		}
		break;

		case AG_AREA_OUTPUT:
		{
			csLocal.Format( "                   cString csAreaOutput;");
			pcsaHeader->Add(csLocal);

			csLocal.Format( "                   short sRetCode1, sRetCode2, sRetCode3, sRetCode4;");
		}
		break;



	}

	pcsaHeader->Add(csLocal);

}


void CAG_EOLE_3270_CS::checkDebug(bool b_Debug,
									   CString csFunctionName,
									   CStringArray* pcsaBody)
{
	CString csLocal;
	
	if ( b_Debug )
	{
		csLocal.Format( "             MessageBox( \"%s\" );", csFunctionName );
		pcsaBody->Add(csLocal);
	}
}


void CAG_EOLE_3270_CS::resetVariableFlags()
{
   b_SessionOpen = FALSE;
   b_nAttribute = FALSE;
   b_nStatus = FALSE;

   b_bUpdated = FALSE;

   b_nRow = FALSE;
   b_nColumn = FALSE;

   b_nLength = FALSE;
   b_pUtilityBuffer = FALSE;
   b_BSTR = FALSE;
   b_nPosition = FALSE;
   b_nSettleTime = FALSE;

   b_nValue = FALSE;
   bAreaObject = FALSE;

   b_bRet = FALSE;
   b_nCloseOption = FALSE;

   b_nFTHostOS = FALSE;

   b_sHeight = FALSE;
   b_nWidth = FALSE;

   b_bLocalMode = FALSE;
   b_bMenuVisible = FALSE;
   b_bSessionQuiet = FALSE;
   b_bSessionSaved = FALSE;

   b_nType = FALSE;
   b_nTimeout = FALSE;
   b_bProcessKeystrokes = FALSE;
   b_bWindowHandle = FALSE;
   b_nWindowState = FALSE;
   b_nCount = FALSE;

   b_csHostName = FALSE;
   b_csFontName = FALSE;
   b_csFTScheme = FALSE;
   b_nIdleTime = FALSE;
   b_nWaitOption = FALSE;
   b_nWaitID = FALSE;
   b_nRetCode = FALSE;
   bAreaOutput = FALSE;

   bOIA = FALSE;
   b_SettingsDialog = FALSE;
   b_FT_PCFileBSTR = FALSE;
   b_FT_HostFileBSTR = FALSE;

}
