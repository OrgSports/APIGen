// Static Model
#include "stdafx.h"
#include "apigen.h"

#include "CAG_MCS_Ax_3270_VBS_DEPLOY.h"

#include "DeployParams.h"

CAG_MCS_Ax_3270_VBS_DEPLOY::CAG_MCS_Ax_3270_VBS_DEPLOY()
{
	resetVariableFlags();	
}

CAG_MCS_Ax_3270_VBS_DEPLOY::~CAG_MCS_Ax_3270_VBS_DEPLOY()
{
	
}


void CAG_MCS_Ax_3270_VBS_DEPLOY::generateHeader(CStringArray* pcsaHeader,
												CStringArray* pcsaBody)
{
	CString csViewOutStuff;
	CDeployParams deployParamsDlg;

	csViewOutStuff.Format( "<script language=\"VBScript\">");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "'  ****************************************************************************");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "'          Attachmate APIGen 3270 MCS ActiveX Viewer");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "'                 VBScript Deployed HTML");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "'");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "'  This file is an HTML file generated by the API Generator to automate");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "'  an Attachmate MCS ActiveX viewer.  It is in a form that can be specified");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "'   in a link to a user");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "'  As you will find below, before the code specified by the user is appended");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "'  to this file's RunCode method the Initialize method will declare the");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "'  the basic set of objects and will connect to the session.");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "'");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "'  Steps to use this file:");
	pcsaHeader->Add(csViewOutStuff);
	
	csViewOutStuff.Format( "'  1. The code in this file was generated with the expectation that the latest");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "'     version of MCS is used.  As of this writing EXTRA! X-treme 8.0 is the");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "'     currently shipping product.");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "'  2. Start the MCS Management and Control Server and create a Java Terminal");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "'     Viewer.  This APIGen output file concerns 3270 hosts so, because it may");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "'     contain method calls not supported on other terminal types ensure that");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "'     a 3270 terminal viewer is ready for the following steps. See to it that the");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "'     terminal viewer is public and activated.");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "'  3. In the Presentation Integrator's Resources tree view select the viewer");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "'     that you intend to associate with this code. Then, from within the Properties control ");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "'     specify your choice for embedded or freestanding, the header file name, and the");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "'     footer file name.");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "'  4. Now drag the terminal viewer node from the Resources pane to the Design View grid on the left");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "'     grid.  From the choices that you specified in step #4 above you have already named the header");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "'     and footer for the presentation, so simply press the toolbar's Save Presentation button, name the");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "'     presentation, and then upload it to the MCS Server by pressing the Publish button.");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "'  5. Now open your MCS Server and from the Products option from its left-side treeview choose the");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "'     Presentation Manager and then \"Manage presentations\".");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "'  6. Select your new presentation from the list and then provide access to users by clicking on the");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "'     Assign Users and Activate buttons.  With that done the presentation is ready for use.");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "'  7. Now, by clicking on this HTML file in Windows Explorer or loading it via a link it should load");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "'      the session and provide a Run button that will start the sequence of commands specified while");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "'      running APIGen.");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "'");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "'      Note: The \"Debug\" function offered at the bottom of the function list will insert a");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "'            message box immediately before each call that is made.  With that, you have a");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "'            means to trace the progress of the VBScript execution in the browser.");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "'");
	pcsaHeader->Add(csViewOutStuff);

	time_t ltime;
	time( &ltime );

	csViewOutStuff.Format( "'");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "'   Generated:   %s", ctime( &ltime ) );
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "'");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "</script>");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( " ");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0 Transitional//%s\">", (deployParamsDlg.csEditDeployLanguageCode).MakeUpper() );
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "<html>");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "<head>");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "<title>MCS Ax Viewer Deployed by APIGen</title>");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "<script id=deployedViewer language=VBScript>");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "Dim term");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "Dim session");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "Dim display");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "Dim screen");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "Dim conn");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "Dim ft");
	pcsaHeader->Add(csViewOutStuff);
	

	csViewOutStuff.Format( "'///////////////////////////////////////////////////////////////////////////DC");
	pcsaBody->Add(csViewOutStuff);

	csViewOutStuff.Format( "'");
	pcsaBody->Add(csViewOutStuff);

	csViewOutStuff.Format( "'   Function   :   Initialize");
	pcsaBody->Add(csViewOutStuff);

	csViewOutStuff.Format( "'");
	pcsaBody->Add(csViewOutStuff);

	csViewOutStuff.Format( "'   Purpose    :   Provides initialization code that will support using");
	pcsaBody->Add(csViewOutStuff);

	csViewOutStuff.Format( "'                  the methods and properties available in an MCS ActiveX");
	pcsaBody->Add(csViewOutStuff);

	csViewOutStuff.Format( "'                  viewer.");
	pcsaBody->Add(csViewOutStuff);
	
	csViewOutStuff.Format( " ");
	pcsaBody->Add(csViewOutStuff);

	csViewOutStuff.Format( "'   Notes       :   ");
	pcsaBody->Add(csViewOutStuff);

	csViewOutStuff.Format( "'");
	pcsaBody->Add(csViewOutStuff);
	
	csViewOutStuff.Format( "' ");
	pcsaBody->Add(csViewOutStuff);

	csViewOutStuff.Format( "'/////////////////////////////////////////////////////////////////////////////");
	pcsaBody->Add(csViewOutStuff);
	
	csViewOutStuff.Format( "Sub Initialize()");
	pcsaBody->Add(csViewOutStuff);

	csViewOutStuff.Format( "");
	pcsaBody->Add(csViewOutStuff);

	csViewOutStuff.Format( "   term = document.Res1;");
	pcsaBody->Add(csViewOutStuff);

	csViewOutStuff.Format( "   session = term.getSession();");
	pcsaBody->Add(csViewOutStuff);
	
	csViewOutStuff.Format( "   screen  = session.getScreen();");
	pcsaBody->Add(csViewOutStuff);

	csViewOutStuff.Format( "   conn = session.getConnection();");
	pcsaBody->Add(csViewOutStuff);

	csViewOutStuff.Format( "   ft = session.getFileTransfer();");
	pcsaBody->Add(csViewOutStuff);

	csViewOutStuff.Format( " ");
	pcsaBody->Add(csViewOutStuff);

	csViewOutStuff.Format( "  session.Connect();");
	pcsaBody->Add(csViewOutStuff);

	csViewOutStuff.Format( " ");
	pcsaBody->Add(csViewOutStuff);
	   
	csViewOutStuff.Format( "End Sub");
	pcsaBody->Add(csViewOutStuff);
	   
	csViewOutStuff.Format( " ");
	pcsaBody->Add(csViewOutStuff);

	csViewOutStuff.Format( "'   /////////////////  User-specified code  /////////////////");
	pcsaBody->Add(csViewOutStuff);

	csViewOutStuff.Format( "Sub RunCode()");
	pcsaBody->Add(csViewOutStuff);

	csViewOutStuff.Format( "");
	pcsaBody->Add(csViewOutStuff);


	// end of preloaded header



}

void CAG_MCS_Ax_3270_VBS_DEPLOY::appendBody(int nFunctionNum,
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


void CAG_MCS_Ax_3270_VBS_DEPLOY::finalize(CStringArray* pcsaBody)
{
	CString csViewOutStuff;

	csViewOutStuff.Format( "");
	pcsaBody->Add(csViewOutStuff);

	csViewOutStuff.Format( "End Sub");
	pcsaBody->Add(csViewOutStuff);

	csViewOutStuff.Format( "");
	pcsaBody->Add(csViewOutStuff);

	csViewOutStuff.Format( "</script>");
	pcsaBody->Add(csViewOutStuff);

	csViewOutStuff.Format( "</head>");
	pcsaBody->Add(csViewOutStuff);

	csViewOutStuff.Format( "");
	pcsaBody->Add(csViewOutStuff);

	csViewOutStuff.Format( "<body onload=\"Initialize();\">");
	pcsaBody->Add(csViewOutStuff);

	csViewOutStuff.Format( " ");
	pcsaBody->Add(csViewOutStuff);

	csViewOutStuff.Format( "<DIV style=\"WIDTH: 788px; POSITION: relative; HEIGHT: 572px\" ms_positioning=\"GridLayout\" id=DIV1 language=VBScript >");
	pcsaBody->Add(csViewOutStuff);

	csViewOutStuff.Format( "<IFRAME id=iFrame2 ");
	pcsaBody->Add(csViewOutStuff);
	
	csViewOutStuff.Format( "style=\"Z-INDEX: 101; LEFT: 12px; WIDTH: 760px; POSITION: absolute; TOP: 48px; HEIGHT: 520px\" ");
	pcsaBody->Add(csViewOutStuff);

	csViewOutStuff.Format( "frameBorder=0 width=40 scrolling=no height=100");
	pcsaBody->Add(csViewOutStuff);
	csViewOutStuff.Format( "onloadTag=\"setTimeout('btnDisableToolbar2()',3000)\" ");
	pcsaBody->Add(csViewOutStuff);
	csViewOutStuff.Format( "src=\"http://doncamcs/mcs/uibroker?SERVICEID=AtmClientUIService&METHODNAME=startClientAccessModule&ACTIONITEMS=en%3BTest051005Ax%3B\">");
	pcsaBody->Add(csViewOutStuff);
	csViewOutStuff.Format( "        Sorry, your browser doesn't support iFrames. </IFRAME>");
	pcsaBody->Add(csViewOutStuff);

	csViewOutStuff.Format( "<INPUT id=txtTest ");
	pcsaBody->Add(csViewOutStuff);

	csViewOutStuff.Format( "   style=\"Z-INDEX: 102; LEFT: 12px; WIDTH: 760px; COLOR: red; FONT-FAMILY: verdana; POSITION: absolute; TOP: 8px; HEIGHT: 22px\" ");
	pcsaBody->Add(csViewOutStuff);

	csViewOutStuff.Format( "   type=text value=\"Help!\" name=Text1 size=121 title=\"\"> ");
	pcsaBody->Add(csViewOutStuff);

	csViewOutStuff.Format( "");
	pcsaBody->Add(csViewOutStuff);

	csViewOutStuff.Format( "</body>");
	pcsaBody->Add(csViewOutStuff);

	csViewOutStuff.Format( "</html>");
	pcsaBody->Add(csViewOutStuff);

	b_Debug = FALSE;

}

void CAG_MCS_Ax_3270_VBS_DEPLOY::declareVariable(AG_VARIABLE agVariable,
												 CStringArray* pcsaHeader,
												 bool* bValue)
{
	CString csLocal;
	*bValue = TRUE;
	
	switch ( agVariable )
	{
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

		case AG_MENU_VISIBLE:
		{
			csLocal.Format( "Dim bMenuVisible");
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

		case AG_PROCESS_KEYSTROKES:
		{
			csLocal.Format( "Dim bProcessKeystrokes");
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
			//csLocal.Format( "   HANDLE hSession=NULL;");
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

		case AG_STRING:
		{
			csLocal.Format( "Dim cString" );
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


void CAG_MCS_Ax_3270_VBS_DEPLOY::checkDebug(bool b_Debug,
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


void CAG_MCS_Ax_3270_VBS_DEPLOY::collectDeploymentParameters(CStringArray* pcsaDeploymentParameters)
{
	
}

void CAG_MCS_Ax_3270_VBS_DEPLOY::resetVariableFlags()
{
   b_nHRESULT = FALSE;
   b_nFLAG = FALSE;
   b_nATMFT = FALSE;
   b_Debug=FALSE;
}
