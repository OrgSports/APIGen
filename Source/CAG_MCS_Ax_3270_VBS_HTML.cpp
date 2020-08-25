// Static Model
#include "stdafx.h"
#include "apigen.h"

#include "CAG_MCS_Ax_3270_VBS_HTML.h"

CAG_MCS_Ax_3270_VBS_HTML::CAG_MCS_Ax_3270_VBS_HTML()
{
	resetVariableFlags();	
}

CAG_MCS_Ax_3270_VBS_HTML::~CAG_MCS_Ax_3270_VBS_HTML()
{
	
}


void CAG_MCS_Ax_3270_VBS_HTML::generateHeader(CStringArray* pcsaHeader,
											 CStringArray* pcsaBody)
{
		// output to Translator's output window
		CString csViewOutStuff;

		csViewOutStuff.Format( "<SCRIPT LANGUAGE=\"VBScript\">");
		pcsaHeader->Add(csViewOutStuff);

		csViewOutStuff.Format( "// ****************************************************************************");
		pcsaHeader->Add(csViewOutStuff);
	
		csViewOutStuff.Format( "//             Attachmate APIGen 3270");
		pcsaHeader->Add(csViewOutStuff);
	
		csViewOutStuff.Format( "//   MCS ActiveX Viewer VBScript HTML Application");
		pcsaHeader->Add(csViewOutStuff);

		csViewOutStuff.Format( " " );
		pcsaHeader->Add(csViewOutStuff);
	
		csViewOutStuff.Format( "// This file is source code for a presenting an Attachmate EAO ActiveX Viewer");
		pcsaHeader->Add(csViewOutStuff);
	
		csViewOutStuff.Format( "// running in an HTML file.  Before the various MCS session objects are available");
		pcsaHeader->Add(csViewOutStuff);
	
		csViewOutStuff.Format( "// and properly registered on the PC that will be used in running this HTML file you");
		
		csViewOutStuff.Format( "//  must first download an instance of an MCS ActiveX presentation.");
		pcsaHeader->Add(csViewOutStuff);
	
		csViewOutStuff.Format( "// To build and run it please do the following:");
		pcsaHeader->Add(csViewOutStuff);
	
		csViewOutStuff.Format( "// 1) Install Attachmate MCS version 2.0.");
		pcsaHeader->Add(csViewOutStuff);
	
		csViewOutStuff.Format( "// 2) Download an MCS ActiveX presentation for the host type that is");
		pcsaHeader->Add(csViewOutStuff);
	
		csViewOutStuff.Format( "//    used in this HTML file.");
		pcsaHeader->Add(csViewOutStuff);
	
		csViewOutStuff.Format( "// 3) Click on this HTML file");
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

		csViewOutStuff.Format( "</SCRIPT>" );
		pcsaHeader->Add(csViewOutStuff);

		csViewOutStuff.Format( "" );
		pcsaHeader->Add(csViewOutStuff);

		csViewOutStuff.Format( "<HTML>");
		pcsaHeader->Add(csViewOutStuff);
	
		csViewOutStuff.Format( "<head>");
		pcsaHeader->Add(csViewOutStuff);
	
		csViewOutStuff.Format( "<title>Attachmate MCS ActiveX Viewer Using VBScript</title>" );
		pcsaHeader->Add(csViewOutStuff);
	
		csViewOutStuff.Format( " " );
		pcsaHeader->Add(csViewOutStuff);
	
		csViewOutStuff.Format( "<SCRIPT LANGUAGE=\"VBScript\">");
		pcsaHeader->Add(csViewOutStuff);
	
		csViewOutStuff.Format( "//*************************** Initialize ***************************" );
		pcsaHeader->Add(csViewOutStuff);
	
		csViewOutStuff.Format( "function Initialize()");
		pcsaHeader->Add(csViewOutStuff);
	
		csViewOutStuff.Format( "{");
		pcsaHeader->Add(csViewOutStuff);
	
		csViewOutStuff.Format( "   //Configure session");
		pcsaHeader->Add(csViewOutStuff);
	
		csViewOutStuff.Format( "   document.form.sess.Screen = document.form.screen;");
		pcsaHeader->Add(csViewOutStuff);
	
		csViewOutStuff.Format( "   document.form.sess.Connection = document.form.con;");
		pcsaHeader->Add(csViewOutStuff);
	
		csViewOutStuff.Format( "   document.form.term.Session = document.form.sess;");
		pcsaHeader->Add(csViewOutStuff);
	
		csViewOutStuff.Format( "}");
		pcsaHeader->Add(csViewOutStuff);
	
		csViewOutStuff.Format( "");
		pcsaHeader->Add(csViewOutStuff);
	
		csViewOutStuff.Format( "//*************************** Connect ***************************" );
		pcsaHeader->Add(csViewOutStuff);
	
		csViewOutStuff.Format( "function onConnect()");
		pcsaHeader->Add(csViewOutStuff);
	
		csViewOutStuff.Format( "{");
		pcsaHeader->Add(csViewOutStuff);
	
		csViewOutStuff.Format( "   document.form.sess.Connection;");
		pcsaHeader->Add(csViewOutStuff);
	
		csViewOutStuff.Format( "   document.form.sess.Connection.RemoteHostAddress = document.form.address.value;");
		pcsaHeader->Add(csViewOutStuff);
	
		csViewOutStuff.Format( "");
		pcsaHeader->Add(csViewOutStuff);
	
		csViewOutStuff.Format( "   //Connect to host");
		pcsaHeader->Add(csViewOutStuff);
	
		csViewOutStuff.Format( "   document.form.term.Session.Connect();");
		pcsaHeader->Add(csViewOutStuff);
	
		csViewOutStuff.Format( "   if ( !document.form.term.Session.Connected )");
		pcsaHeader->Add(csViewOutStuff);
	
		csViewOutStuff.Format( "   {" );
		pcsaHeader->Add(csViewOutStuff);
	
		csViewOutStuff.Format( "      alert( \"Connection attempt failed - check IP address and try again.\");");
		pcsaHeader->Add(csViewOutStuff);
	
		csViewOutStuff.Format( "   }" );
		pcsaHeader->Add(csViewOutStuff);

		csViewOutStuff.Format( "}");
		pcsaHeader->Add(csViewOutStuff);

		csViewOutStuff.Format( "" );
		pcsaHeader->Add(csViewOutStuff);

		csViewOutStuff.Format( "//*************************** Disconnect ***************************" );
		pcsaHeader->Add(csViewOutStuff);

		csViewOutStuff.Format( "function onDisconnect()" );
		pcsaHeader->Add(csViewOutStuff);

		csViewOutStuff.Format( "{" );
		pcsaHeader->Add(csViewOutStuff);

		csViewOutStuff.Format( "   document.form.sess.Disconnect();" );
		pcsaHeader->Add(csViewOutStuff);

		csViewOutStuff.Format( "}" );
		pcsaHeader->Add(csViewOutStuff);

		csViewOutStuff.Format( "" );
		pcsaHeader->Add(csViewOutStuff);

		csViewOutStuff.Format( "" );
		pcsaHeader->Add(csViewOutStuff);

		csViewOutStuff.Format( "//*************************** RunAPIGen ***************************" );
		pcsaHeader->Add(csViewOutStuff);

		csViewOutStuff.Format( "function RunAPIGen()" );
		pcsaHeader->Add(csViewOutStuff);

		csViewOutStuff.Format( "{" );
		pcsaHeader->Add(csViewOutStuff);

		csViewOutStuff.Format( "   document.form.sess.Screen.SendKeys(\"vmuser11vms11{Enter}\", 65536);" );
		pcsaBody->Add(csViewOutStuff);

		csViewOutStuff.Format( "" );
		pcsaBody->Add(csViewOutStuff);

		csViewOutStuff.Format( "   try" );
		pcsaBody->Add(csViewOutStuff);

		csViewOutStuff.Format( "   {" );
		pcsaBody->Add(csViewOutStuff);

		csViewOutStuff.Format( "      document.form.sess.Screen.WaitHostQuiet(679);" );
		pcsaBody->Add(csViewOutStuff);

		csViewOutStuff.Format( "   }" );
		pcsaBody->Add(csViewOutStuff);

		csViewOutStuff.Format( "   catch (e)" );
		pcsaBody->Add(csViewOutStuff);

		csViewOutStuff.Format( "   {" );
		pcsaBody->Add(csViewOutStuff);

		csViewOutStuff.Format( "         //alert(\"The host did not settle within 679 milliseconds\");" );
		pcsaBody->Add(csViewOutStuff);

		csViewOutStuff.Format( "   }" );
		pcsaBody->Add(csViewOutStuff);

		csViewOutStuff.Format( "" );
		pcsaBody->Add(csViewOutStuff);

		csViewOutStuff.Format( "   document.form.sess.Screen.SendKeys(\"logoff{Enter}\", 65536);" );
		pcsaBody->Add(csViewOutStuff);

		csViewOutStuff.Format( "" );
		pcsaBody->Add(csViewOutStuff);

		csViewOutStuff.Format( "   try" );
		pcsaBody->Add(csViewOutStuff);

		csViewOutStuff.Format( "   {" );
		pcsaBody->Add(csViewOutStuff);

		csViewOutStuff.Format( "      document.form.sess.Screen.WaitHostQuiet(679);" );
		pcsaBody->Add(csViewOutStuff);

		csViewOutStuff.Format( "   }" );
		pcsaBody->Add(csViewOutStuff);

		csViewOutStuff.Format( "   catch (e)" );
		pcsaBody->Add(csViewOutStuff);

		csViewOutStuff.Format( "   {" );
		pcsaBody->Add(csViewOutStuff);

		csViewOutStuff.Format( "      //alert(\"The host did not settle within 679 milliseconds\");" );
		pcsaBody->Add(csViewOutStuff);

		csViewOutStuff.Format( "   }" );
		pcsaBody->Add(csViewOutStuff);

		csViewOutStuff.Format( "" );
		pcsaBody->Add(csViewOutStuff);


}


void CAG_MCS_Ax_3270_VBS_HTML::appendBody(int nFunctionNum,
										 bool bPromptForValues,
										 CStringArray* pcsaArguments,
										 CStringArray* pcsaHeader,
										 CStringArray* pcsaBody)
{
	CString csViewOutStuff;
	CString csFunctionName, csFunctionNum, csString, csStringLength, csRetCode;

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

	csViewOutStuff.Format( "   // *** %s", csFunctionName );
	pcsaBody->Add(csViewOutStuff);

	checkDebug( b_Debug, csFunctionName, pcsaBody );

	switch ( nFunctionNum )
	{
		case 0:	// AtmFileTransfer::Cancel
		{
			if ( !b_nHRESULT )
			{
				declareVariable( AG_HRESULT, pcsaHeader, &b_nHRESULT );
			}
			
			if ( !b_nFLAG )
			{
				declareVariable( AG_FLAG, pcsaHeader, &b_nFLAG );
			}
			
			if ( !b_nATMFT )
			{
				declareVariable( AG_ATMFT, pcsaHeader, &b_nATMFT );
			}
			
			csViewOutStuff.Format( "   nFlag=0;" );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "   hr = ATMFTObj.Cancel( nFlag );" );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "" );
			pcsaBody->Add(csViewOutStuff);

		}
		break;

		case 1:	// AtmFileTransfer::GetStatus
		case 2:	// AtmFileTransfer::Transfer
		case 3:	// AtmFileTransfer::TransferEx
		case 4:	// AtmFont::GetRectangle
		case 5:	// AtmFont::GetSize
		case 6:	// AtmHllapiCollection::SetAsDefault
		case 7:	// AtmControl::AboutBox
		case 8:	// AtmControl::DoClick
		case 9:	// AtmControl::Refresh
		case 10:	// AtmOIA::GetOIALine
		case 11:	// AtmOIA::WaitForXStatus
		case 12:	// AtmPrinterCtrl::ViewSession
		case 13:	// AtmPrinterLUEscapeSequences::Add
		case 14:	// AtmPrinterLUEscapeSequences::Remove
		case 15:	// AtmPrinterLUEscapeSequences::RemoveAll
		case 16:	// AtmScreen::FieldCount
		case 17:	// AtmScreen::FindField
		case 18:	// AtmScreen::FindString
		case 19:	// AtmScreen::FindStringEx
		case 20:	// AtmScreen::GetCursor
		case 21:	// AtmScreen::GetData
		case 22:	// AtmScreen::GetString
		case 23:	// AtmScreen::GetStringEx
		case 24:	// AtmScreen::PutString
		case 25:	// AtmScreen::PutStringEx
		case 26:	// AtmScreen::RefreshEvents


		case 28:	// AtmScreen::SetCursor
		case 29:	// AtmScreen::WaitForCursor
		case 30:	// AtmScreen::WaitForKeys
		case 31:	// AtmScreen::WaitForString


	/*
		case :	// AtmScreenAsync::ClearCommunications				// Async only block
		case :	// AtmScreenAsync::ClearScreen
		case :	// AtmScreenAsync::GetColor
		case :	// AtmScreenAsync::ReadStatusLine
		case :	// AtmScreenAsync::ResetTerminal
		case :	// AtmScreenAsync::SetColor
		case :	// AtmScreenVT420::ClearUDKs
	*/
		case 33:	// AtmScreen3270::SendLightPen			// 3270 only block
	/*
		case :	// AtmScreen5250::GetErrLineHostRow		// 5250 only block
		case :	// AtmScreen5250::GetErrLineText
		case :	// AtmScreen5250::GetMsgLineHostRow
		case :	// AtmScreen5250::GetMsgLineText
		case :	// AtmScreen5250::GetSysReqLineColumn
		case :	// AtmScreen5250::GetSysReqLineHostRow
		case :	// AtmScreen5250::GetSysReqLineText
		case :	// AtmScreen5250::SendLMouseClick
	*/
		case 34:	// AtmSelection::GetSelection
		case 35:	// AtmSelection::IsSelected
		case 36:	// AtmSelection::SelectAll
		case 37:	// AtmSelection::SetSelection
		case 38:	// AtmSelection::Unselect
		case 39:	// AtmSession::Attach
		case 40:	// AtmSession::Connect
		case 41:	// AtmSession::Detach
		case 42:	// AtmSession::Disconnect
		case 43:	// AtmSessionStatus::EnumItem
		case 44:	// AtmSessionStatus::GetValue
		case 45:	// AtmSessionStatusCollection::RefreshIfChanged
		case 46:	// AtmTerminal::ViewSession
		case 47:	// AtmWait::Reset
		case 48:	// AtmWait::Wait
		{
			csViewOutStuff.Format( "   // APIGen has not yet implemented this method." );
			pcsaBody->Add(csViewOutStuff);
		}
		break;

		case 27:	// AtmScreen::SendKeys
		{
			csViewOutStuff.Format( "   document.form.sess.Screen.SendKeys(\"%s\", 65536);", pcsaArguments->GetAt(1) );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "" );
			pcsaBody->Add(csViewOutStuff);

		}
		break;

		case 32:	// AtmScreen::WaitHostQuiet
		{
			csViewOutStuff.Format( "   try" );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "   {" );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "      document.form.sess.Screen.WaitHostQuiet(%s);", pcsaArguments->GetAt(1) );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "   }" );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "   catch (e)" );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "   {" );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "      //alert(\"The host did not settle within %s milliseconds\");", pcsaArguments->GetAt(1) );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "   }" );
			pcsaBody->Add(csViewOutStuff);
		}
		break;


	}

	pcsaArguments->RemoveAll();
}


void CAG_MCS_Ax_3270_VBS_HTML::finalize(CStringArray* pcsaBody)
{
		CString csLocal;
	
		csLocal.Format( "}" );
		pcsaBody->Add(csLocal);

		csLocal.Format( "" );
		pcsaBody->Add(csLocal);

		csLocal.Format( "</SCRIPT>" );
		pcsaBody->Add(csLocal);

		csLocal.Format( "" );
		pcsaBody->Add(csLocal);

		csLocal.Format( "<style type=\"text/css\">" );
		pcsaBody->Add(csLocal);

		csLocal.Format( "<!--" );
		pcsaBody->Add(csLocal);

		csLocal.Format( ".navtop-blue {font-family: Verdana, Tahoma, Arial, sans-serif; font-size: 16px; color: #696FA5; text-decoration: none; font-weight: bold; }" );
		pcsaBody->Add(csLocal);

		csLocal.Format( "</style>" );
		pcsaBody->Add(csLocal);

		csLocal.Format( "" );
		pcsaBody->Add(csLocal);

		csLocal.Format( "</HEAD>" );
		pcsaBody->Add(csLocal);

		csLocal.Format( "" );
		pcsaBody->Add(csLocal);

		csLocal.Format( "<body Language=\"VBScript\" onLoad=\"Initialize()\">" );
		pcsaBody->Add(csLocal);

		csLocal.Format( "<center>" );
		pcsaBody->Add(csLocal);

		csLocal.Format( "<TABLE width=\"800\" border=\"0\" cellspacing=\"0\" cellpadding=\"0\">" );
		pcsaBody->Add(csLocal);

		csLocal.Format( "<TR>" );
		pcsaBody->Add(csLocal);

		csLocal.Format( "<TD align=\"center\"></td>" );
		pcsaBody->Add(csLocal);

		csLocal.Format( "<td align=\"center\" class=\"navtop-blue\">APIGen MCS ActiveX Viewer in VBScript</TD>" );
		pcsaBody->Add(csLocal);

		csLocal.Format( "</TR>" );
		pcsaBody->Add(csLocal);

		csLocal.Format( "</TABLE>" );
		pcsaBody->Add(csLocal);

		csLocal.Format( "</center>" );
		pcsaBody->Add(csLocal);

		csLocal.Format( "" );
		pcsaBody->Add(csLocal);

		csLocal.Format( "<P>" );
		pcsaBody->Add(csLocal);

		csLocal.Format( "<CENTER>" );
		pcsaBody->Add(csLocal);

		csLocal.Format( "<FORM NAME=\"form\">" );
		pcsaBody->Add(csLocal);

		csLocal.Format( "<P>" );
		pcsaBody->Add(csLocal);

		csLocal.Format( "TN3270 Host Address: <INPUT NAME=\"address\" TYPE=\"textarea\" VALUE=\"Your TN3270 Host\" SIZE=\"20,1\">" );
		pcsaBody->Add(csLocal);

		csLocal.Format( "<P>" );
		pcsaBody->Add(csLocal);

		csLocal.Format( "<object id=\"term\" classid=\"clsid:CD340A64-EF5F-11CF-95C6-0004AC32CCC9\" width=\"800\" height=\"350\"></object>" );
		pcsaBody->Add(csLocal);

		csLocal.Format( "<object id=\"sess\" classid=\"clsid:7F37B328-86F5-11CF-B401-08005AC024EB\"></object>" );
		pcsaBody->Add(csLocal);

		csLocal.Format( "<object id=\"screen\" classid=\"clsid:3DC1AC46-CA1A-11CF-BECD-08005A9B94B7\"></object>" );
		pcsaBody->Add(csLocal);

		csLocal.Format( "<object id=\"con\" classid=\"clsid:1356B571-7919-11CF-A2DA-08005A48F0E4\"></object>" );
		pcsaBody->Add(csLocal);

		csLocal.Format( "<object id=\"status\" classid=\"clsid:6C7C01D3-06A9-11D0-95C7-0004AC32CCC9\"></object>" );
		pcsaBody->Add(csLocal);

		csLocal.Format( "<object id=\"oia\" classid=\"clsid:B44CBC52-E0F8-11cf-BEEA-08005A9B94B7\"></object>" );
		pcsaBody->Add(csLocal);

		csLocal.Format( "<object id=\"keymap\" classid=\"clsid:9CFF5962-6D7D-11D0-95D4-0004AC32CCC9\"></object>" );
		pcsaBody->Add(csLocal);

		csLocal.Format( "<P>" );
		pcsaBody->Add(csLocal);

		csLocal.Format( "<INPUT TYPE=\"button\" NAME=\"Connect\"    VALUE=\"Connect\" OnClick=\"onConnect()\">" );
		pcsaBody->Add(csLocal);

		csLocal.Format( "<INPUT TYPE=\"button\" NAME=\"Disconnect\" VALUE=\"Disconnect\" OnClick=\"onDisconnect()\" LEFT=4644>" );
		pcsaBody->Add(csLocal);

		csLocal.Format( "<INPUT TYPE=\"button\" NAME=\"Macro\" VALUE=\"Macro\"  OnClick=\"RunAPIGen()\" LEFT=4644>" );
		pcsaBody->Add(csLocal);

		csLocal.Format( "</FORM>" );
		pcsaBody->Add(csLocal);

		csLocal.Format( "" );
		pcsaBody->Add(csLocal);

		csLocal.Format( "</CENTER>" );
		pcsaBody->Add(csLocal);

		csLocal.Format( "</BODY>" );
		pcsaBody->Add(csLocal);

		csLocal.Format( "</HTML>" );
		pcsaBody->Add(csLocal);


}


void CAG_MCS_Ax_3270_VBS_HTML::declareVariable(AG_VARIABLE agVariable,
											  CStringArray* pcsaHeader,
											  bool* bValue)
{
	
}

void CAG_MCS_Ax_3270_VBS_HTML::checkDebug(bool b_Debug,
								 CString csFunctionName,
								 CStringArray* pcsaBody)
{
	
}

void CAG_MCS_Ax_3270_VBS_HTML::resetVariableFlags()
{
   b_nHRESULT = FALSE;
   b_nFLAG = FALSE;
   b_nATMFT = FALSE;
   b_Debug=FALSE;
}
