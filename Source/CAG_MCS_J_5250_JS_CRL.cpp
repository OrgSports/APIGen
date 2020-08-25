// Static Model
#include "stdafx.h"
#include "apigen.h"

#include "CAG_MCS_J_5250_JS_CRL.h"
#include "time.h"


CAG_MCS_J_5250_JS_CRL::CAG_MCS_J_5250_JS_CRL()
{
	resetVariableFlags();	
}

CAG_MCS_J_5250_JS_CRL::~CAG_MCS_J_5250_JS_CRL()
{
	
}

void CAG_MCS_J_5250_JS_CRL::generateHeader(CStringArray* pcsaHeader,
										   CStringArray* pcsaBody)
{
	CString	API_LANGUAGE = "JavaScript";

	CString csViewOutStuff;

	csViewOutStuff.Format( "//  ****************************************************************************");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "//                  Attachmate MCS 5250 Java Viewers");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "//              APIGen JavaScript Cached Run Local Script");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( " ");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "//  This file, below the END OF COMMENT line, contains a JavaScript code");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "//  block intended to be copied into an MCS Java Viewer cached-run-local");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "//  HTML file.  Copy everything after the END OF COMMENT line below over the");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "//  code that extends from the top of the cached run-local HTML file generated");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "//  by the MCS Server to the end of the <body> tag.  With that, this script will start when"); 
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "//  the HTML file loads and run as is.");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "//");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "//  Example:");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "//  <applet id=\"term\" name=\"term\" code=\"com.attachmate.emulation.gui.AtmApplet\" ");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "//");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "//  If you have questions about how to modify the JavaScript block in this");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "//  file, please consult the Attachmate JavaScript Guide for MCS Java Viewers.");
	pcsaHeader->Add(csViewOutStuff);

	time_t ltime;
	time( &ltime );

	csViewOutStuff.Format( "//");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "//   Generated:   %s", ctime( &ltime ) );
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "//");
	pcsaHeader->Add(csViewOutStuff);
	
	csViewOutStuff.Format( "//  **************************** END OF COMMENT *********************************");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( " ");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "<html>");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "<head>");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "  <title>Attachmate&#174; MCS Java Viewer -- APIGen</title>");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "</head>");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( " ");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "<script language=\"JavaScript\">");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( " ");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "var session");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "var screen");
	pcsaHeader->Add(csViewOutStuff);



	csViewOutStuff.Format( " ");
	pcsaBody->Add(csViewOutStuff);
	
	csViewOutStuff.Format( "function Initialize()");
	pcsaBody->Add(csViewOutStuff);

	csViewOutStuff.Format( "{");
	pcsaBody->Add(csViewOutStuff);

	csViewOutStuff.Format( "   session = document.applets[0].getSession();");
	pcsaBody->Add(csViewOutStuff);
	
	csViewOutStuff.Format( "   screen  = session.getScreen();");
	pcsaBody->Add(csViewOutStuff);

}


void CAG_MCS_J_5250_JS_CRL::appendBody(int nFunctionNum,
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
			if ( !b_pOIAObject )
			{
				declareVariable( AG_OIAOBJ, pcsaHeader, &b_pOIAObject );
			}

			csViewOutStuff.Format( "   OIAObj.waitForXStatus( OIAObj.%s, OIAObj.%s );",	pcsaArguments->GetAt(1), pcsaArguments->GetAt(2) );
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

			csViewOutStuff.Format( "   nCount = screen.fieldCount( screen.%s );", pcsaArguments->GetAt(1) );
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
			csViewOutStuff.Format( "   screen.refreshEvents();" );
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

			csViewOutStuff.Format( "   nType = screen.%s;", pcsaArguments->GetAt(2) );
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

			csViewOutStuff.Format( "   bEABs = %s;", pcsaArguments->GetAt(1) );
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


			csViewOutStuff.Format( "   try");
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "   {");
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "      screen.waitForCursor( nRow, nColumn );");
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "   }");
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "   catch (e)");
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "   {");
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "      window.status = \"Status: waitForCursor \" + e.message");
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "   }");
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

			csViewOutStuff.Format( "   nType = screen.%s;", pcsaArguments->GetAt(2) );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "   nMode = screen.%s;", pcsaArguments->GetAt(3) );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( " " );
			pcsaBody->Add(csViewOutStuff);


			csViewOutStuff.Format( "   try");
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "   {");
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "   // Note: current test results indicate the keystroke");
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "   // mnemonics are not sensed as expected in this function.");
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "      screen.waitForKeys( cText, nType, nMode );" );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "   }");
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "   catch (e)");
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "   {");
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "      window.status = \"Status: waitForKeys \" + e.message");
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "   }");
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


			csViewOutStuff.Format( "   try");
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "   {");
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "      screen.waitForString( cText, nRow, nColumn, nWait );");
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "   }");
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "   catch (e)");
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "   {");
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "      window.status = \"Status: waitForString \" + e.message");
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "   }");
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


			csViewOutStuff.Format( "   try");
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "   {");
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "   // Note: current test results show this function returns");
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "   // immediately, ignoring the wait idle time.");
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "      screen.waithostquiet( nWait );");
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "   }");
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "   catch (e)");
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "   {");
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "      window.status = \"Status: waithostquiet \" + e.message");
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "   }");
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

			csViewOutStuff.Format( "      window.status = \"Status: attach \" + e.message");
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "   }" );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( " " );
			pcsaBody->Add(csViewOutStuff);

		}
		break;


		case 35:	// session.connect
		{
			csViewOutStuff.Format( "   session.connect();");
			pcsaBody->Add(csViewOutStuff);
		}
		break;


		case 36:	// Session::detach
		{
			csViewOutStuff.Format( "   session.detach(0);");
			pcsaBody->Add(csViewOutStuff);
		}
		break;


		case 37:	// Session::disconnect 
		{
			csViewOutStuff.Format( "   session.disconnect(0);");
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

				csViewOutStuff.Format( "      window.status = \"Status: getAttached \" + e.message");
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

				csViewOutStuff.Format( "         window.status = \"Status: getConnected \" + e.message");
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

				csViewOutStuff.Format( "      window.status = \"Status: getConnection \" + e.message");
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

				csViewOutStuff.Format( "      window.status = \"Status: getScreen \" + e.message");
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

				csViewOutStuff.Format( "      window.status = \"Status: setConnected \" + e.message");
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

				csViewOutStuff.Format( "      window.status = \"Status: setConnection \" + e.message");
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

				csViewOutStuff.Format( "      window.status = \"Status: setScreen \" + e.message");
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


void CAG_MCS_J_5250_JS_CRL::finalize(CStringArray* pcsaBody)
{
	CString csViewOutStuff;

	csViewOutStuff.Format( " " );
	pcsaBody->Add(csViewOutStuff);

	csViewOutStuff.Format( "}");
	pcsaBody->Add(csViewOutStuff);

	csViewOutStuff.Format( " " );
	pcsaBody->Add(csViewOutStuff);

	csViewOutStuff.Format( "</script>");
	pcsaBody->Add(csViewOutStuff);

	csViewOutStuff.Format( " " );
	pcsaBody->Add(csViewOutStuff);

	
	csViewOutStuff.Format( "<BODY BGCOLOR=\"#C0C0C0\" LINK=\"#FFFFFF\" VLINK=\"#FFFFFF\"  LEFTMARGIN=0 TOPMARGIN=0 Language=Javascript onLoad=\"Initialize()\">" );
	pcsaBody->Add(csViewOutStuff);

	csViewOutStuff.Format( " " );
	pcsaBody->Add(csViewOutStuff);

	b_Debug = FALSE;

}



/****************************************************************************DC
	Function	:	CAG_MCS_J_5250_JS_CRL::declareVariable()

	Purpose		:	Append variable declarations to the end of the header as 
					needed.

*****************************************************************************/
void CAG_MCS_J_5250_JS_CRL::declareVariable(AG_VARIABLE agVariable,
											CStringArray* pcsaHeader,
											bool* bValue)
{
	CString csLocal;
	*bValue = TRUE;
	
	switch ( agVariable )
	{
		case AG_STATUS:
		{
			csLocal.Format( "var nStatus");
		}
		break;

		case AG_UPDATED:
		{
			csLocal.Format( "var bUpdated");
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
			csLocal.Format( "var nRow");
		}
		break;

		case AG_COLUMN:
		{
			csLocal.Format( "var nColumn");		
		}
		break;

		case AG_ATTRIBUTE:
		{
			csLocal.Format( "var nAttribute");
		}
		break;

		case AG_LENGTH:
		{
			csLocal.Format( "var nLength");
		}
		break;

		case AG_VALUE:
		{
			csLocal.Format( "var nValue");
		}
		break;

		case AG_RETURN:
		{
			csLocal.Format( "var bRet");
		}
		break;

		case AG_CLOSEOPTION:
		{
			csLocal.Format( "var nCloseOption");
		}
		break;

		case AG_HOST_OS:
		{
			csLocal.Format( "var nFTHostOS");
		}
		break;

		case AG_HEIGHT:
		{
			csLocal.Format( "var nHeight");
		}
		break;

		case AG_LOCALMODE:
		{
			csLocal.Format( "var bLocalMode");
		}
		break;

		case AG_SESS_SAVED:
		{
			csLocal.Format( "var bSessionSaved");
		}
		break;

		case AG_SESSIONS_CREATED:
		{
			csLocal.Format( "var Sessions" );
		}
		break;

		case AG_SESS_OPEN:
		{
			csLocal.Format( "var SessName");
		}
		break;


		case AG_SETTLE_TIME:
		{
			csLocal.Format( "var nSettleTime");
		}
		break;

		case AG_SESS_QUIET:
		{
			csLocal.Format( "var bSessionQuiet");
		}
		break;

		case AG_MENU_VISIBLE:
		{
			csLocal.Format( "var bMenuVisible");
		}
		break;

		case AG_TYPE:
		{
			csLocal.Format( "var nType");
		}
		break;

		case AG_TIMEOUT:
		{
			csLocal.Format( "var nTimeout");
		}
		break;

		case AG_PROCESS_KEYSTROKES:
		{
			csLocal.Format( "var bProcessKeystrokes");
		}
		break;

		case AG_WIDTH:
		{
			csLocal.Format( "var nWidth");
		}
		break;

		case AG_WINDOW_HANDLE:
		{
			csLocal.Format( "var hSession");
			//csLocal.Format( "   HANDLE hSession=NULL;");
		}
		break;

		case AG_WINDOW_STATE:
		{
			csLocal.Format( "var nWindowState");
		}
		break;

		case AG_COUNT:
		{
			csLocal.Format( "var nCount");
		}
		break;

		case AG_AREA:
		{
			csLocal.Format( "var Area");
		}
		break;

		// new stuff
		case AG_NAME:
		{
			csLocal.Format( "var csName" );
		}
		break;

		case AG_TERMINAL:
		{
			csLocal.Format( "var Terminal" );
		}
		break;

		case AG_OIAOBJ:
		{
			csLocal.Format( "var OIAObj" );
		}
		break;

		case AG_TEXT:
		{
			csLocal.Format( "var cText" );
		}
		break;

		case AG_EAB:
		{
			csLocal.Format( "var bEABs" );
		}
		break;

		case AG_HOST_CHARSET:
		{
			csLocal.Format( "var nCharSet" );
		}
		break;

		case AG_HOST_CODEPAGE:
		{
			csLocal.Format( "var nHostCodePage" );
		}
		break;

		case AG_KBD_LOCKED:
		{
			csLocal.Format( "var bKeyboardLocked" );
		}
		break;

		case AG_MODEL:	
		{
			csLocal.Format( "var nModel" );
		}
		break;

		case AG_STRING:
		{
			csLocal.Format( "var cString" );
		}
		break;

		case AG_MODE:
		{
			csLocal.Format( "var nMode" );
		}
		break;

		case AG_WAIT:
		{
			csLocal.Format( "var nWait" );
		}
		break;

		case AG_ATTACHED:
		{
			csLocal.Format( "var bAttached" );
		}
		break;

		case AG_CONNECTED:
		{
			csLocal.Format( "var bConnected" );
		}
		break;

		case AG_CONNECTION_OBJ:
		{
			csLocal.Format( "var conn" );
		}
		break;

		case AG_SCREEN_OBJ:
		{
			csLocal.Format( "var screen" );
		}
		break;

		case AG_STATE:
		{
			csLocal.Format( "var nState" );
		}
		break;

		case AG_PORT:
		{
			csLocal.Format( "var nPort" );
		}
		break;

	}

	pcsaHeader->Add(csLocal);

}


void CAG_MCS_J_5250_JS_CRL::checkDebug(bool b_Debug,
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


void CAG_MCS_J_5250_JS_CRL::resetVariableFlags()
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
