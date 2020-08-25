// Static Model
#include "stdafx.h"
#include "apigen.h"

#include "CAG_MCS_Ax_5250_VBS_HTML.h"



CAG_MCS_Ax_5250_VBS_HTML::CAG_MCS_Ax_5250_VBS_HTML()
{
	resetVariableFlags();	
}

CAG_MCS_Ax_5250_VBS_HTML::~CAG_MCS_Ax_5250_VBS_HTML()
{
	
}

void CAG_MCS_Ax_5250_VBS_HTML::declareVariable(AG_VARIABLE agVariable,
											  CStringArray* pcsaHeader,
											  bool* bValue)
{
	
}


void CAG_MCS_Ax_5250_VBS_HTML::generateHeader(CStringArray* pcsaHeader,
											 CStringArray* pcsaBody)
{
		// output to Translator's output window
		CString csViewOutStuff;

		csViewOutStuff.Format( "<SCRIPT LANGUAGE=\"VBScript\">");
		pcsaHeader->Add(csViewOutStuff);

		csViewOutStuff.Format( "// ****************************************************************************");
		pcsaHeader->Add(csViewOutStuff);
	
		csViewOutStuff.Format( "//             Attachmate APIGen 5250");
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


void CAG_MCS_Ax_5250_VBS_HTML::appendBody(int nFunctionNum,
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

	CString	csLocal;

	switch ( nFunctionNum )
	{
		case 0:		// ATMObject::getName
		{
			if ( !b_csName )
			{
				declareVariable( AG_NAME, pcsaHeader, &b_csName );
			}

			csViewOutStuff.Format( "   csName = session.getName();" );
			pcsaBody->Add(csViewOutStuff);

		}
		break;

		case 1:		// ATMObject::getParentObject
		{
			if ( !b_Terminal )
			{
				declareVariable( AG_TERMINAL, pcsaHeader, &b_Terminal );
			}

			csViewOutStuff.Format( "   Terminal = session.getParentObject();" );
			pcsaBody->Add(csViewOutStuff);

		}
		break;
		
		case 2:		// OIA::getErrorStatus
		{
			if ( !b_pOIAObject )
			{
				declareVariable( AG_OIAOBJ, pcsaHeader, &b_pOIAObject );
			}

			if ( !b_nStatus )
			{
				declareVariable( AG_STATUS, pcsaHeader, &b_nStatus );
			}

			csViewOutStuff.Format( "   OIAObj = screen.getOia();");
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "   nStatus = OIAObj.getErrorStatus();");
			pcsaBody->Add(csViewOutStuff);


		}
		break;

		case 3:		// OIA::getOiaType
		{
			if ( !b_pOIAObject )
			{
				declareVariable( AG_OIAOBJ, pcsaHeader, &b_pOIAObject );
			}

			if ( !b_nType )
			{
				declareVariable( AG_TYPE, pcsaHeader, &b_nType );
			}


			csViewOutStuff.Format( "   OIAObj = screen.getOia();");
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "   nType = OIAObj.getOiaType();");
			pcsaBody->Add(csViewOutStuff);


		}
		break;


		case 4:		// OIA::getText
		{
			if ( !b_pOIAObject )
			{
				declareVariable( AG_OIAOBJ, pcsaHeader, &b_pOIAObject );
			}

			if ( !b_cText )
			{
				declareVariable( AG_TEXT, pcsaHeader, &b_cText );
			}

			csViewOutStuff.Format( "   OIAObj = screen.getOia();");
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "   cText = OIAObj.getText();");
			pcsaBody->Add(csViewOutStuff);


		}
		break;


		case 5:		// OIA::getXStatus
		{
			if ( !b_pOIAObject )
			{
				declareVariable( AG_OIAOBJ, pcsaHeader, &b_pOIAObject );
			}

			if ( !b_nStatus )
			{
				declareVariable( AG_STATUS, pcsaHeader, &b_nStatus );
			}


			csViewOutStuff.Format( "   OIAObj = screen.getOia();");
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "   nStatus = OIAObj.getXStatus();");
			pcsaBody->Add(csViewOutStuff);


		}
		break;

		case 6:		// OIA::waitForXStatus
		{
			csViewOutStuff.Format( "   // this one isn't there yet");
			pcsaBody->Add(csViewOutStuff);

		}
		break;

		case 7:		// Screen::clearScreen
		{
			csViewOutStuff.Format( "   screen.clearScreen();");
			pcsaBody->Add(csViewOutStuff);
		}
		break;

		case 8:		// Screen::fieldCount
		{
			if ( !b_nCount )
			{
				declareVariable( AG_COUNT, pcsaHeader, &b_nCount );
			}

			csViewOutStuff.Format( "   nCount = screen.fieldCount( %s );", pcsaArguments->GetAt(1) );
			pcsaBody->Add(csViewOutStuff);

		}
		break;


		case 9:		// Screen::getColumns
		{
			if ( !b_nCount )
			{
				declareVariable( AG_COUNT, pcsaHeader, &b_nCount );
			}

			csViewOutStuff.Format( "   nCount = screen.getColumns();" );
			pcsaBody->Add(csViewOutStuff);

		}
		break;


		case 10:		// Screen::getCursorColumn
		{
			if ( !b_nColumn )
			{
				declareVariable( AG_COLUMN, pcsaHeader, &b_nColumn );			
			}

			csViewOutStuff.Format( "   nColumn = screen.getCursorColumn();" );
			pcsaBody->Add(csViewOutStuff);

		}
		break;


		case 11:		// Screen::getCursorRow
		{
			if ( !b_nRow )
			{
				declareVariable( AG_ROW, pcsaHeader, &b_nRow );			
			}

			csViewOutStuff.Format( "   nRow = screen.getCursorRow();" );
			pcsaBody->Add(csViewOutStuff);

		}
		break;


		case 12:		// Screen::getEabEnabled
		{
			if ( !b_bEABs )
			{
				declareVariable( AG_EAB, pcsaHeader, &b_bEABs );			
			}

			csViewOutStuff.Format( "   bEABs = screen.getEabEnabled();" );
			pcsaBody->Add(csViewOutStuff);

		}
		break;


		case 13:	// Screen::getHostCharSet
		{
			if ( !b_nCharSet )
			{
				declareVariable( AG_HOST_CHARSET, pcsaHeader, &b_nCharSet );
			}

			csViewOutStuff.Format( "   nCharSet = screen.getHostCharSet();" );
			pcsaBody->Add(csViewOutStuff);

		}
		break;


		case 14:	// Screen::getHostCodePage 
		{
			if ( !b_nHostCodePage )
			{
				declareVariable( AG_HOST_CODEPAGE, pcsaHeader, &b_nHostCodePage );
			}

			csViewOutStuff.Format( "   nHostCodePage = screen.getHostCodePage();" );
			pcsaBody->Add(csViewOutStuff);

		}
		break;


		case 15:	// Screen::getKeyboardLocked
		{
			if ( !b_bKeyboardLocked )
			{
				declareVariable( AG_KBD_LOCKED, pcsaHeader, &b_bKeyboardLocked );
			}

			csViewOutStuff.Format( "   bKeyboardLocked = screen.getKeyboardLocked();" );
			pcsaBody->Add(csViewOutStuff);

		}
		break;


		case 16:	// Screen::getModel
		{
			if ( !b_nModel )
			{
				declareVariable( AG_MODEL, pcsaHeader, &b_nModel );
			}

			csViewOutStuff.Format( "   nModel = screen.getModel();" );
			pcsaBody->Add(csViewOutStuff);

		}
		break;


		case 17:	// Screen::getOia
		{
			if ( !b_pOIAObject )
			{
				declareVariable( AG_OIAOBJ, pcsaHeader, &b_pOIAObject );
			}

			csViewOutStuff.Format( "   OIAObj = screen.getOia();");
			pcsaBody->Add(csViewOutStuff);


		}
		break;

		case 18:	// Screen::getRows
		{
			if ( !b_nCount )
			{
				declareVariable( AG_COUNT, pcsaHeader, &b_nCount );
			}

			csViewOutStuff.Format( "   nCount = screen.getRows();" );
			pcsaBody->Add(csViewOutStuff);

		}
		break;


		case 19:	// Screen::getScreenType
		{
			if ( !b_nType )
			{
				declareVariable( AG_TYPE, pcsaHeader, &b_nType );
			}

			csViewOutStuff.Format( "   nType = screen.getScreenType();");
			pcsaBody->Add(csViewOutStuff);

		}
		break;


		case 20:	// Screen::getString
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

			if ( !b_cString )
			{
				declareVariable( AG_STRING, pcsaHeader, &b_cString );			
			}

			
			csViewOutStuff.Format( "   nRow = %s;", pcsaArguments->GetAt(1) );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "   nColumn = %s;", pcsaArguments->GetAt(2) );
			pcsaBody->Add(csViewOutStuff);
			

			csViewOutStuff.Format( "   nLength = %s;", pcsaArguments->GetAt(3) );
			pcsaBody->Add(csViewOutStuff);
			
			csViewOutStuff.Format( "   cString = screen.getString( nRow, nColumn, nLength );");
			pcsaBody->Add(csViewOutStuff);


		}
		break;



		case 21:	// Screen::getText
		{
			if ( !b_cText )
			{
				declareVariable( AG_TEXT, pcsaHeader, &b_cText );
			}

			csViewOutStuff.Format( "   cText = screen.getText();");
			pcsaBody->Add(csViewOutStuff);

		}
		break;


		case 22:	// Screen::putString
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

			if ( !b_nLength )
			{
				declareVariable( AG_LENGTH, pcsaHeader, &b_nLength );			
			}


			csViewOutStuff.Format( "   cString = %s;", pcsaArguments->GetAt(1) );
			pcsaBody->Add(csViewOutStuff);
			
			csViewOutStuff.Format( "   nRow = %s;", pcsaArguments->GetAt(2) );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "   nColumn = %s;", pcsaArguments->GetAt(3) );
			pcsaBody->Add(csViewOutStuff);
			
			csViewOutStuff.Format( "   nLength = screen.putString( cString, nRow, nColumn );");
			pcsaBody->Add(csViewOutStuff);
		}
		break;
	

		case 23:		// screen::refreshEvents
		{
			csViewOutStuff.Format( "	screen.refreshEvents();" );
			pcsaBody->Add(csViewOutStuff);
		}
		break;


		case 24:		// screen.sendkeys
		{
			if ( !b_cText )
			{
				declareVariable( AG_TEXT, pcsaHeader, &b_cText );
			}

			if ( !b_nType )
			{
				declareVariable( AG_TYPE, pcsaHeader, &b_nType );
			}

			csViewOutStuff.Format( "   cText = \"%s\";", pcsaArguments->GetAt(1) );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "   nType = %s;", pcsaArguments->GetAt(2) );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( " " );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "   screen.sendkeys( cText, nType );" );
			pcsaBody->Add(csViewOutStuff);
		}
		break;


		case 25:	// Screen::setCursor
		{
			if ( !b_nRow )
			{
				declareVariable( AG_ROW, pcsaHeader, &b_nRow );
			}

			if ( !b_nColumn )
			{
				declareVariable( AG_COLUMN, pcsaHeader, &b_nColumn );			
			}

			csViewOutStuff.Format( "   nRow = %s;", pcsaArguments->GetAt(1) );
			pcsaBody->Add(csViewOutStuff);
			csViewOutStuff.Format( "   nColumn = %s;", pcsaArguments->GetAt(2) );
			pcsaBody->Add(csViewOutStuff);
			csViewOutStuff.Format( " " );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "   screen.setCursor( nRow, nColumn );");
			pcsaBody->Add(csViewOutStuff);

		}
		break;

		
		case 26:	// Screen::setEabEnabled
		{
			if ( !b_bEABs )
			{
				declareVariable( AG_EAB, pcsaHeader, &b_bEABs );			
			}

			csViewOutStuff.Format( "   bEABs = TRUE;"); //%s;", pcsaArguments->GetAt(1) );
			pcsaBody->Add(csViewOutStuff);
			csViewOutStuff.Format( " " );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "   screen.setEabEnabled( bEABs );");
			pcsaBody->Add(csViewOutStuff);

		}
		break;


		case 27:	// Screen::setHostCharSet
		{
			if ( !b_nCharSet )
			{
				declareVariable( AG_HOST_CHARSET, pcsaHeader, &b_nCharSet );
			}

			csViewOutStuff.Format( "   nCharSet = %s;", pcsaArguments->GetAt(1) );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "   screen.setHostCharSet( nCharSet );" );
			pcsaBody->Add(csViewOutStuff);

		}
		break;


		case 28:	// Screen::setHostCodePage
		{
			if ( !b_nHostCodePage )
			{
				declareVariable( AG_HOST_CODEPAGE, pcsaHeader, &b_nHostCodePage );
			}

			csViewOutStuff.Format( "   nHostCodePage = %s;", pcsaArguments->GetAt(1) );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "   screen.setHostCodePage( nHostCodePage );" );
			pcsaBody->Add(csViewOutStuff);

		}
		break;


		case 29:	// Screen::setModel
		{
			if ( !b_nModel )
			{
				declareVariable( AG_MODEL, pcsaHeader, &b_nModel );
			}

			csViewOutStuff.Format( "   nModel = %s;", pcsaArguments->GetAt(1) );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( " " );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "   screen.setModel( nModel );" );
			pcsaBody->Add(csViewOutStuff);
		}
		break;
		

		case 30:		// screen.waitForCursor
		{
			if ( !b_nRow )
			{
				declareVariable( AG_ROW, pcsaHeader, &b_nRow );
			}

			if ( !b_nColumn )
			{
				declareVariable( AG_COLUMN, pcsaHeader, &b_nColumn );			
			}

			csViewOutStuff.Format( "   nRow = %s;", pcsaArguments->GetAt(1) );
			pcsaBody->Add(csViewOutStuff);
			csViewOutStuff.Format( "   nColumn = %s;", pcsaArguments->GetAt(2) );
			pcsaBody->Add(csViewOutStuff);
			csViewOutStuff.Format( " " );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "   screen.waitForCursor( nRow, nColumn );");
			pcsaBody->Add(csViewOutStuff);

		}
		break;

		
		case 31:		// screen.waitForKeys
		{
			if ( !b_cText )
			{
				declareVariable( AG_TEXT, pcsaHeader, &b_cText );
			}

			if ( !b_nType )
			{
				declareVariable( AG_TYPE, pcsaHeader, &b_nType );
			}

			if ( !b_nMode )
			{
				declareVariable( AG_MODE, pcsaHeader, &b_nMode );
			}


			csViewOutStuff.Format( "   cText = \"%s\";", pcsaArguments->GetAt(1) );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "   nType = %s;", pcsaArguments->GetAt(2) );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "   nMode = %s;", pcsaArguments->GetAt(3) );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( " " );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "   screen.waitForKeys( cText, nType, nMode );  //XXX" );
			pcsaBody->Add(csViewOutStuff);
		}
		break;


		case 32:		// screen.waitForString
		{
			if ( !b_cText )
			{
				declareVariable( AG_TEXT, pcsaHeader, &b_cText );
			}

			if ( !b_nRow )
			{
				declareVariable( AG_ROW, pcsaHeader, &b_nRow );
			}

			if ( !b_nColumn )
			{
				declareVariable( AG_COLUMN, pcsaHeader, &b_nColumn );			
			}

			if ( !b_nWait )
			{
				declareVariable( AG_WAIT, pcsaHeader, &b_nWait );
			}

			csViewOutStuff.Format( "   cText = \"%s\";", pcsaArguments->GetAt(1) );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "   nRow = %s;", pcsaArguments->GetAt(2) );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "   nColumn = %s;", pcsaArguments->GetAt(3) );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "   nWait = %s;", pcsaArguments->GetAt(4) );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( " " );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "   screen.waitForString( cText, nRow, nColumn, nWait );  //XXX");
			pcsaBody->Add(csViewOutStuff);
		}
		break;


		case 33:		// screen.waithostquiet
		{
			if ( !b_nWait )
			{
				declareVariable( AG_WAIT, pcsaHeader, &b_nWait );
			}

			csViewOutStuff.Format( "   nWait = %s;", pcsaArguments->GetAt(1) );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( " " );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "   screen.waithostquiet( nWait );");
			pcsaBody->Add(csViewOutStuff);
		}
		break;


		case 34:	// Session::attach
		{
			csViewOutStuff.Format( "   try" );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "   {" );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "      session.attach(session.ATTACH_MUSTBELOADED);" );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "   }" );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "   catch (e)" );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "   {" );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "      alert( \"attach exception thrown\");" );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "   }" );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( " " );
			pcsaBody->Add(csViewOutStuff);

		}
		break;


		case 35:	// session.connect
		{
			csViewOutStuff.Format( "   term.session.connect();");
			pcsaBody->Add(csViewOutStuff);
		}
		break;


		case 36:	// Session::detach
		{
			csViewOutStuff.Format( "   term.session.detach(0);");
			pcsaBody->Add(csViewOutStuff);
		}
		break;


		case 37:	// Session::disconnect 
		{
			csViewOutStuff.Format( "   term.session.disconnect(0);");
			pcsaBody->Add(csViewOutStuff);
		}
		break;

		
		case 38:	// Session::getAttached
		{
			
				if ( !b_bAttached )
				{
					declareVariable( AG_ATTACHED, pcsaHeader, &b_bAttached );				
				}

				csViewOutStuff.Format( "   try");
				pcsaBody->Add(csViewOutStuff);

				csViewOutStuff.Format( "   {");
				pcsaBody->Add(csViewOutStuff);

				csViewOutStuff.Format( "      bAttached = session.getAttached();");
				pcsaBody->Add(csViewOutStuff);

				csViewOutStuff.Format( "   }");
				pcsaBody->Add(csViewOutStuff);

				csViewOutStuff.Format( "   catch (e)");
				pcsaBody->Add(csViewOutStuff);

				csViewOutStuff.Format( "   {");
				pcsaBody->Add(csViewOutStuff);

				csViewOutStuff.Format( "      alert( \"getAttached exception thrown\" );");
				pcsaBody->Add(csViewOutStuff);

				csViewOutStuff.Format( "   }");
				pcsaBody->Add(csViewOutStuff);

				csViewOutStuff.Format( "");
				pcsaBody->Add(csViewOutStuff);
				

		}
		break;


		case 39:	// Session::getConnected
		{
			
				if ( !b_bConnected )
				{
					declareVariable( AG_CONNECTED, pcsaHeader, &b_bConnected  );
				}

				csViewOutStuff.Format( "   try");
				pcsaBody->Add(csViewOutStuff);

				csViewOutStuff.Format( "   {");
				pcsaBody->Add(csViewOutStuff);

				csViewOutStuff.Format( "      bConnected = session.getConnected();");
				pcsaBody->Add(csViewOutStuff);

				csViewOutStuff.Format( "   }");
				pcsaBody->Add(csViewOutStuff);

				csViewOutStuff.Format( "   catch (e)");
				pcsaBody->Add(csViewOutStuff);

				csViewOutStuff.Format( "   {");
				pcsaBody->Add(csViewOutStuff);

				csViewOutStuff.Format( "      alert( \"getConnected exception thrown\" );");
				pcsaBody->Add(csViewOutStuff);

				csViewOutStuff.Format( "   }");
				pcsaBody->Add(csViewOutStuff);

				csViewOutStuff.Format( "");
				pcsaBody->Add(csViewOutStuff);
				

		}
		break;


		case 40:	// Session::getConnection
		{
			
				if ( !b_ConnectionObj )
				{
					declareVariable( AG_CONNECTION_OBJ, pcsaHeader, &b_ConnectionObj );
				}

				csViewOutStuff.Format( "   try");
				pcsaBody->Add(csViewOutStuff);

				csViewOutStuff.Format( "   {");
				pcsaBody->Add(csViewOutStuff);

				csViewOutStuff.Format( "      conn = session.getConnection();");
				pcsaBody->Add(csViewOutStuff);

				csViewOutStuff.Format( "   }");
				pcsaBody->Add(csViewOutStuff);

				csViewOutStuff.Format( "   catch (e)");
				pcsaBody->Add(csViewOutStuff);

				csViewOutStuff.Format( "   {");
				pcsaBody->Add(csViewOutStuff);

				csViewOutStuff.Format( "      alert( \"getConnection exception thrown\" );");
				pcsaBody->Add(csViewOutStuff);

				csViewOutStuff.Format( "   }");
				pcsaBody->Add(csViewOutStuff);

				csViewOutStuff.Format( "");
				pcsaBody->Add(csViewOutStuff);
				

		}
		break;
				

		case 41:	// Session::getScreen
		{
				
				if ( !b_ScreenObj )
				{
				//	declareVariable( AG_SCREEN_OBJ, pcsaHeader, &b_ScreenObj );
				}

				csViewOutStuff.Format( "   try");
				pcsaBody->Add(csViewOutStuff);

				csViewOutStuff.Format( "   {");
				pcsaBody->Add(csViewOutStuff);

				csViewOutStuff.Format( "      screen = session.getScreen();");
				pcsaBody->Add(csViewOutStuff);

				csViewOutStuff.Format( "   }");
				pcsaBody->Add(csViewOutStuff);

				csViewOutStuff.Format( "   catch (e)");
				pcsaBody->Add(csViewOutStuff);

				csViewOutStuff.Format( "   {");
				pcsaBody->Add(csViewOutStuff);

				csViewOutStuff.Format( "      alert( \"getScreen exception thrown\" );");
				pcsaBody->Add(csViewOutStuff);

				csViewOutStuff.Format( "   }");
				pcsaBody->Add(csViewOutStuff);

				csViewOutStuff.Format( "");
				pcsaBody->Add(csViewOutStuff);
				

		}
		break;

		
		case 42:	// Session::getState
		{
			if ( !b_nState )
			{
				declareVariable( AG_STATE, pcsaHeader, &b_nState );
			}
			
			csViewOutStuff.Format( "   nState = session.getState();");
			pcsaBody->Add(csViewOutStuff);
		}
		break;

		case 43:	// Session::setConnected
		{
			
				if ( !b_bConnected )
				{
					declareVariable( AG_CONNECTED, pcsaHeader, &b_bConnected  );
				}

				csViewOutStuff.Format( "   bConnected = TRUE;" );
				pcsaBody->Add(csViewOutStuff);

				csViewOutStuff.Format( " " );
				pcsaBody->Add(csViewOutStuff);

				csViewOutStuff.Format( "   try");
				pcsaBody->Add(csViewOutStuff);

				csViewOutStuff.Format( "   {");
				pcsaBody->Add(csViewOutStuff);

				csViewOutStuff.Format( "      session.setConnected( bConnected );");
				pcsaBody->Add(csViewOutStuff);

				csViewOutStuff.Format( "   }");
				pcsaBody->Add(csViewOutStuff);

				csViewOutStuff.Format( "   catch (e)");
				pcsaBody->Add(csViewOutStuff);

				csViewOutStuff.Format( "   {");
				pcsaBody->Add(csViewOutStuff);

				csViewOutStuff.Format( "      alert( \"setConnected exception thrown\" );");
				pcsaBody->Add(csViewOutStuff);

				csViewOutStuff.Format( "   }");
				pcsaBody->Add(csViewOutStuff);

				csViewOutStuff.Format( "");
				pcsaBody->Add(csViewOutStuff);
				

		}
		break;


		case 44:	// Session::setConnection
		{
			
				if ( !b_ConnectionObj )
				{
					declareVariable( AG_CONNECTION_OBJ, pcsaHeader, &b_ConnectionObj );
				}

				csViewOutStuff.Format( "   try");
				pcsaBody->Add(csViewOutStuff);

				csViewOutStuff.Format( "   {");
				pcsaBody->Add(csViewOutStuff);

				csViewOutStuff.Format( "      session.setConnection( conn );");
				pcsaBody->Add(csViewOutStuff);

				csViewOutStuff.Format( "   }");
				pcsaBody->Add(csViewOutStuff);

				csViewOutStuff.Format( "   catch (e)");
				pcsaBody->Add(csViewOutStuff);

				csViewOutStuff.Format( "   {");
				pcsaBody->Add(csViewOutStuff);

				csViewOutStuff.Format( "      alert( \"setConnection exception thrown\" );");
				pcsaBody->Add(csViewOutStuff);

				csViewOutStuff.Format( "   }");
				pcsaBody->Add(csViewOutStuff);

				csViewOutStuff.Format( "");
				pcsaBody->Add(csViewOutStuff);
				

		}
		break;

		case 45:	// Session::setScreen
		{
				
				if ( !b_ScreenObj )
				{
					//declareVariable( AG_SCREEN_OBJ, pcsaHeader, &b_ScreenObj );
				}

				csViewOutStuff.Format( "   try");
				pcsaBody->Add(csViewOutStuff);

				csViewOutStuff.Format( "   {");
				pcsaBody->Add(csViewOutStuff);

				csViewOutStuff.Format( "      session.setScreen( screen );");
				pcsaBody->Add(csViewOutStuff);

				csViewOutStuff.Format( "   }");
				pcsaBody->Add(csViewOutStuff);

				csViewOutStuff.Format( "   catch (e)");
				pcsaBody->Add(csViewOutStuff);

				csViewOutStuff.Format( "   {");
				pcsaBody->Add(csViewOutStuff);

				csViewOutStuff.Format( "      alert( \"setScreen exception thrown\" );");
				pcsaBody->Add(csViewOutStuff);

				csViewOutStuff.Format( "   }");
				pcsaBody->Add(csViewOutStuff);

				csViewOutStuff.Format( "");
				pcsaBody->Add(csViewOutStuff);
				

		}
		break;


		case 46:	// ITelnetProxy::getSocksAddress
		{
				
				if ( !b_ConnectionObj )
				{
					declareVariable( AG_CONNECTION_OBJ, pcsaHeader, &b_ConnectionObj );
				}
				
				if ( !b_cText )
				{
					declareVariable( AG_TEXT, pcsaHeader, &b_cText );
				}

				csViewOutStuff.Format( "   cText = conn.getSocksAddress();" );
				pcsaBody->Add(csViewOutStuff);

				csViewOutStuff.Format( "");
				pcsaBody->Add(csViewOutStuff);
				
		}
		break;


		case 47:	// ITelnetProxy::getSocksPort
		{
				
				if ( !b_ConnectionObj )
				{
					declareVariable( AG_CONNECTION_OBJ, pcsaHeader, &b_ConnectionObj );
				}
				
				if ( !b_nPort )
				{
					declareVariable( AG_PORT, pcsaHeader, &b_nPort );
				}

				csViewOutStuff.Format( "   nPort = conn.getSocksPort();" );
				pcsaBody->Add(csViewOutStuff);

				csViewOutStuff.Format( "");
				pcsaBody->Add(csViewOutStuff);
				
		}
		break;


		case 48:	// ITelnetProxy::getTelnetAddress
		{
				
				if ( !b_ConnectionObj )
				{
					declareVariable( AG_CONNECTION_OBJ, pcsaHeader, &b_ConnectionObj );
				}
				
				if ( !b_cText )
				{
					declareVariable( AG_TEXT, pcsaHeader, &b_cText );
				}

				csViewOutStuff.Format( "   cText = conn.getTelnetAddress();" );
				pcsaBody->Add(csViewOutStuff);

				csViewOutStuff.Format( "");
				pcsaBody->Add(csViewOutStuff);
				
		}
		break;


		case 49:	// ITelnetProxy::getTelnetPort
		{
				
				if ( !b_ConnectionObj )
				{
					declareVariable( AG_CONNECTION_OBJ, pcsaHeader, &b_ConnectionObj );
				}
				
				if ( !b_nPort )
				{
					declareVariable( AG_PORT, pcsaHeader, &b_nPort );
				}

				csViewOutStuff.Format( "   nPort = conn.getTelnetPort();" );
				pcsaBody->Add(csViewOutStuff);

				csViewOutStuff.Format( "");
				pcsaBody->Add(csViewOutStuff);
				
		}
		break;


		case 50:	// ITelnetProxy::setSocksAddress
		{
				
				if ( !b_ConnectionObj )
				{
					declareVariable( AG_CONNECTION_OBJ, pcsaHeader, &b_ConnectionObj );
				}
				
				if ( !b_cText )
				{
					declareVariable( AG_TEXT, pcsaHeader, &b_cText );
				}

				csViewOutStuff.Format( "   cText = \"%s\";", pcsaArguments->GetAt(1) );
				pcsaBody->Add(csViewOutStuff);

				csViewOutStuff.Format( "   conn.setSocksAddress( cText );" );
				pcsaBody->Add(csViewOutStuff);

				csViewOutStuff.Format( "");
				pcsaBody->Add(csViewOutStuff);
				
		}
		break;


		case 51:	// ITelnetProxy::setSocksPort
		{
				
				if ( !b_ConnectionObj )
				{
					declareVariable( AG_CONNECTION_OBJ, pcsaHeader, &b_ConnectionObj );
				}
				
				if ( !b_nPort )
				{
					declareVariable( AG_PORT, pcsaHeader, &b_nPort );
				}

				csViewOutStuff.Format( "   nPort = %s;", pcsaArguments->GetAt(1) );
				pcsaBody->Add(csViewOutStuff);

				csViewOutStuff.Format( "   conn.setSocksPort( nPort );" );
				pcsaBody->Add(csViewOutStuff);

				csViewOutStuff.Format( "");
				pcsaBody->Add(csViewOutStuff);
				
		}
		break;


		case 52:	// ITelnetProxy::setTelnetAddress
		{
				
				if ( !b_ConnectionObj )
				{
					declareVariable( AG_CONNECTION_OBJ, pcsaHeader, &b_ConnectionObj );
				}
				
				if ( !b_cText )
				{
					declareVariable( AG_TEXT, pcsaHeader, &b_cText );
				}

				csViewOutStuff.Format( "   cText = \"%s\";", pcsaArguments->GetAt(1) );
				pcsaBody->Add(csViewOutStuff);

				csViewOutStuff.Format( "   conn.setTelnetAddress( cText );" );
				pcsaBody->Add(csViewOutStuff);

				csViewOutStuff.Format( "");
				pcsaBody->Add(csViewOutStuff);
				
		}
		break;


		case 53:	// ITelnetProxy::setTelnetPort
		{
				
				if ( !b_ConnectionObj )
				{
					declareVariable( AG_CONNECTION_OBJ, pcsaHeader, &b_ConnectionObj );
				}
				
				if ( !b_nPort )
				{
					declareVariable( AG_PORT, pcsaHeader, &b_nPort );
				}

				csViewOutStuff.Format( "   nPort = %s;", pcsaArguments->GetAt(1) );
				pcsaBody->Add(csViewOutStuff);

				csViewOutStuff.Format( "   conn.setTelnetPort( nPort );" );
				pcsaBody->Add(csViewOutStuff);

				csViewOutStuff.Format( "");
				pcsaBody->Add(csViewOutStuff);
				
		}
		break;


	}

	pcsaArguments->RemoveAll();
}


void CAG_MCS_Ax_5250_VBS_HTML::finalize(CStringArray* pcsaBody)
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

		csLocal.Format( "TN5250 Host Address: <INPUT NAME=\"address\" TYPE=\"textarea\" VALUE=\"Your TN5250 Host\" SIZE=\"20,1\">" );
		pcsaBody->Add(csLocal);

		csLocal.Format( "<P>" );
		pcsaBody->Add(csLocal);

		csLocal.Format( "<object id=\"term\" classid=\"clsid:CD340A64-EF5F-11CF-95C6-0004AC32CCC9\" width=\"800\" height=\"350\"></object>" );
		pcsaBody->Add(csLocal);

		csLocal.Format( "<object id=\"sess\" classid=\"clsid:7F37B328-86F5-11CF-B401-08005AC024EB\"></object>" );
		pcsaBody->Add(csLocal);

		csLocal.Format( "<object id=\"screen\" classid=\"clsid:F8100BE8-5072-11d1-B176-006097A4AEB1\"></object>" );
		pcsaBody->Add(csLocal);

		csLocal.Format( "<object id=\"con\" classid=\"clsid:F8100BC5-5072-11d1-B176-006097A4AEB1\"></object>" );
		pcsaBody->Add(csLocal);

		csLocal.Format( "<object id=\"status\" classid=\"clsid:F8100C00-5072-11D1-B176-006097A4AEB1\"></object>" );
		pcsaBody->Add(csLocal);

		csLocal.Format( "<object id=\"oia\" classid=\"clsid:F8100BE7-5072-11d1-B176-006097A4AEB1\"></object>" );
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

void CAG_MCS_Ax_5250_VBS_HTML::checkDebug(bool b_Debug,
								 CString csFunctionName,
								 CStringArray* pcsaBody)
{
	
}

void CAG_MCS_Ax_5250_VBS_HTML::resetVariableFlags()
{
   b_pOIAObject = FALSE;
   b_nStatus = FALSE;
   b_nType = FALSE;
   b_cText = FALSE;
   b_nCount = FALSE;
   b_nColumn = FALSE;
   b_nRow = FALSE;
   b_bEABs = FALSE;
   b_nCharSet = FALSE;
   b_nHostCodePage = FALSE;
   b_bKeyboardLocked = FALSE;
   b_nModel = FALSE;
   b_nLength = FALSE;
   b_cString = FALSE;
   b_bAttached = FALSE;
   b_csName=FALSE;
   b_Terminal=FALSE;
   b_nMode=FALSE;
   b_nWait=FALSE;
   b_bConnected=FALSE;
   b_ConnectionObj=FALSE;
   b_ScreenObj=FALSE;
   b_nState=FALSE;
   b_nPort=FALSE;
   b_Debug=FALSE;
}
