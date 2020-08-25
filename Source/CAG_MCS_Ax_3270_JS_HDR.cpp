// Static Model
#include "stdafx.h"
#include "apigen.h"

#include "CAG_MCS_Ax_3270_JS_HDR.h"

CAG_MCS_Ax_3270_JS_HDR::CAG_MCS_Ax_3270_JS_HDR()
{
	resetVariableFlags();	
}

CAG_MCS_Ax_3270_JS_HDR::~CAG_MCS_Ax_3270_JS_HDR()
{
	
}


void CAG_MCS_Ax_3270_JS_HDR::generateHeader(CStringArray* pcsaHeader,
											CStringArray* pcsaBody)
{
	CString csViewOutStuff;

	csViewOutStuff.Format( "<script language=\"JavaScript\">");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "//  ****************************************************************************");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "//          Attachmate APIGen 3270 MCS ActiveX Viewer");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "//                 JavaScript Header/Footer");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "//");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "//  This file contains both JavaScript MCS header and footer files generated");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "//  to automate an Attachmate MCS Java viewer.  When separated into individual");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "//  files and uploaded to an MCS Server they can be used to prepare an MCS");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "//  Presentation that will run the methods that you specified as you ran the");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "//  API Generator.");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "//  As you will find below, before the code specified by the user is appended");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "//  to this file's RunCode() method the Initialize() method will declare the");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "//  the basic set of objects and will connect to the session.");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "//");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "//  Steps to use this file:");
	pcsaHeader->Add(csViewOutStuff);
	
	csViewOutStuff.Format( "//  1. The code in this file was generated with the expectation that the latest");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "//     version of MCS is used.  As of this writing EXTRA! X-treme 8.0 is the");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "//     currently shipping product.");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "//  2. Separate the header from the footer and save them in separate files.");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "//  3. Start the MCS Management and Control Server and create a Java Terminal");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "//     Viewer.  This APIGen output file concerns 3270 hosts so, because it may");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "//     contain method calls not supported on other terminal types ensure that");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "//     a 3270 terminal viewer is ready for the following steps. See to it that the");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "//     terminal viewer is public and activated.");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "//  4. Start the MCS Presentation Integrator.  To upload your new header and footer files");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "//     to the MCS Server you must double click on the buttons on the top and bottom of the");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "//     right-side Design View pane that are labeled, \"Double-click Here\". ");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "//     After you have double-clicked one of the buttons, select the \"Select external header\"");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "//     radio button, press the Add button, browse to your HTML header/footer file, and then");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "//     press the Open, OK, and OK buttons.  Follow the same sequence for both the header and");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "//     footer files.");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "//  5. In the Presentation Integrator's Resources tree view select the viewer");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "//     that you intend to associate with this code. Then, from within the Properties control ");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "//     specify your choice for embedded or freestanding, the header file name, and the");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "//     footer file name.");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "//  6. Now drag the terminal viewer node from the Resources pane to the Design View grid on the left");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "//     grid.  From the choices that you specified in step #4 above you have already named the header");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "//     and footer for the presentation, so simply press the toolbar's Save Presentation button, name the");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "//     presentation, and then upload it to the MCS Server by pressing the Publish button.");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "//  7. Now open your MCS Server and from the Products option from its left-side treeview choose the");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "//     Presentation Manager and then \"Manage presentations\".");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "//  8. Select your new presentation from the list and then provide access to users by clicking on the");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "//     Assign Users and Activate buttons.  With that done the presentation is ready for use.");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "//  9. Run the presentation and APIGenerated code by opening your browser, navigating to the <URL>,");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "//      and selecting the new presentation from the provided list.");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "//");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "//      Note: The \"Debug\" function offered at the bottom of the function list will insert a");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "//            message box immediately before each call that is made.  With that, you have a");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "//            means to trace the progress of the JavaScript execution in the browser.");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "//");
	pcsaHeader->Add(csViewOutStuff);

	time_t ltime;
	time( &ltime );

	csViewOutStuff.Format( "//");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "//   Generated:   %s", ctime( &ltime ) );
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "//");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( " ");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "//**************************  START MCS HEADER  **************************");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( " ");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "var term");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "var session");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "var display");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "var screen");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "var conn");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "var ft");
	pcsaHeader->Add(csViewOutStuff);
	
	
	csViewOutStuff.Format( " ");
	pcsaBody->Add(csViewOutStuff);

	csViewOutStuff.Format( "/////////////////////////////////////////////////////////////////////////////DC");
	pcsaBody->Add(csViewOutStuff);

	csViewOutStuff.Format( "//");
	pcsaBody->Add(csViewOutStuff);

	csViewOutStuff.Format( "//   Function   :   Initialize");
	pcsaBody->Add(csViewOutStuff);

	csViewOutStuff.Format( "//");
	pcsaBody->Add(csViewOutStuff);

	csViewOutStuff.Format( "//   Purpose    :   Provides initialization code that will support using");
	pcsaBody->Add(csViewOutStuff);

	csViewOutStuff.Format( "//                  the methods and properties available in an MCS Java");
	pcsaBody->Add(csViewOutStuff);

	csViewOutStuff.Format( "//                  viewer.");
	pcsaBody->Add(csViewOutStuff);
	
	csViewOutStuff.Format( " ");
	pcsaBody->Add(csViewOutStuff);

	csViewOutStuff.Format( "//   Notes       :   This function is called via the onLoad specifier in ");
	pcsaBody->Add(csViewOutStuff);

	csViewOutStuff.Format( "//                   the footer file.");
	pcsaBody->Add(csViewOutStuff);

	csViewOutStuff.Format( "//");
	pcsaBody->Add(csViewOutStuff);
	
	csViewOutStuff.Format( "// ");
	pcsaBody->Add(csViewOutStuff);

	csViewOutStuff.Format( "///////////////////////////////////////////////////////////////////////////////");
	pcsaBody->Add(csViewOutStuff);
	
	csViewOutStuff.Format( "function Initialize()");
	pcsaBody->Add(csViewOutStuff);

	csViewOutStuff.Format( "{");
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
	   
	csViewOutStuff.Format( "}");
	pcsaBody->Add(csViewOutStuff);
	   

	csViewOutStuff.Format( "   /////////////////  User-specified code  /////////////////");
	pcsaBody->Add(csViewOutStuff);

	csViewOutStuff.Format( "function RunCode()");
	pcsaBody->Add(csViewOutStuff);

	csViewOutStuff.Format( "{");
	pcsaBody->Add(csViewOutStuff);


}


void CAG_MCS_Ax_3270_JS_HDR::appendBody(int nFunctionNum,
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

void CAG_MCS_Ax_3270_JS_HDR::finalize(CStringArray* pcsaBody)
{
	
}


void CAG_MCS_Ax_3270_JS_HDR::declareVariable(AG_VARIABLE agVariable,
											 CStringArray* pcsaHeader,
											 bool* bValue)
{
	CString csLocal;
	*bValue = TRUE;
	
	switch ( agVariable )
	{
		case AG_ATMFT:
		{
			csLocal.Format( "   IAtmFileTransfer* pIAtmFileTransfer;");
		}
		break;

		case AG_HRESULT:
		{
			csLocal.Format( "   HRESULT hr;" );
		}
		break;

		case AG_FLAG:
		{
			csLocal.Format( "   long nFlag=0;" );
		}
		break;

	}

	pcsaHeader->Add(csLocal);
	
}

void CAG_MCS_Ax_3270_JS_HDR::checkDebug(bool b_Debug,
									   CString csFunctionName,
									   CStringArray* pcsaBody)
{
	CString csLocal;
	
	if ( b_Debug )
	{
		csLocal.Format( "   alert( \"%s\" );", csFunctionName );
		pcsaBody->Add(csLocal);
	}
}

void CAG_MCS_Ax_3270_JS_HDR::resetVariableFlags()
{
   b_nHRESULT = FALSE;
   b_nFLAG = FALSE;
   b_nATMFT = FALSE;
   b_Debug=FALSE;
}