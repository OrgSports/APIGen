// Static Model
#include "stdafx.h"
#include "apigen.h"

#include "CAG_AIR_3270_Ax_CPP.h"
#include "time.h"



CAG_AIR_3270_Ax_CPP::CAG_AIR_3270_Ax_CPP()
{
	resetVariableFlags();
}


CAG_AIR_3270_Ax_CPP::~CAG_AIR_3270_Ax_CPP()
{
	
}

void CAG_AIR_3270_Ax_CPP::checkDebug(bool b_Debug,
								  CString csFunctionName,
								  CStringArray* pcsaBody)
{
	
}



void CAG_AIR_3270_Ax_CPP::generateHeader(CStringArray* pcsaHeader,
									  CStringArray* pcsaBody)
{
	// output to Translator's output window
	CString csViewOutStuff;

	pcsaHeader->Add("// ****************************************************************************");

	pcsaHeader->Add("//                  Attachmate APIGen Airlines SDK");

	pcsaHeader->Add("//                   3270 C++ ActiveX Application");

	pcsaHeader->Add("//");

	pcsaHeader->Add("//   When compiled, this becomes a freestanding ActiveX program that contains a list");

	pcsaHeader->Add("//    of Airlines SDK 3270 Applet C++ method calls specified to the APIGen code");

	pcsaHeader->Add("//    generator.");

	pcsaHeader->Add("//");

	pcsaHeader->Add("//    These conditions must be met before this source file can be used.");

	pcsaHeader->Add("//       1. ");

	pcsaHeader->Add("//       2. The Attachmate Airlines SDK must be installed using the keycode for 3270.");

	pcsaHeader->Add("//       3. ");

	pcsaHeader->Add("//       4. You must prepare a 3270 session XML configuration file that the");

	csViewOutStuff.Format( "//           generated program can use to configure its connection.");
	pcsaHeader->Add(csViewOutStuff);

	pcsaHeader->Add("//           One example of such a configuration file is 3270.xml which");

	pcsaHeader->Add("//           is listed below.");

	pcsaHeader->Add("//           <<stuff>>");

	pcsaHeader->Add("//           Note: As is currently prepared the XML config file isn't necessary.");

	#define SIZE 26

	time_t ltime;
	time( &ltime );
	errno_t err;
	
	char buf[SIZE];
	err = ctime_s( buf, SIZE, &ltime );


	pcsaHeader->Add("//");

	csViewOutStuff.Format( "//   Generated:   %s", buf );
	pcsaHeader->Add(csViewOutStuff);

	pcsaHeader->Add("//");

	pcsaHeader->Add("// ****************************************************************************");

	pcsaHeader->Add("");

	pcsaHeader->Add("void Screen::start(void)");

	pcsaHeader->Add("{");

	pcsaHeader->Add("     TRY");

	pcsaHeader->Add("     {");

	pcsaHeader->Add("          //The following is only applicable if you are using ID Manager to obtain IDs.");

	pcsaHeader->Add("          m_SessLoader.setResourceManagerOptions(75,25,\"\");");

	pcsaHeader->Add("          //End of ID Manager-specific code.");

	pcsaHeader->Add("");

	pcsaHeader->Add("          CLSID clsid;");

	pcsaHeader->Add("          HRESULT hr = ::CLSIDFromProgID(L\"SessionLoader.SessionLoader\", &clsid);");

	pcsaHeader->Add("          ");

	pcsaHeader->Add("          if (FAILED(hr))");

	pcsaHeader->Add("          {");

	pcsaHeader->Add("               AfxThrowOleException(hr);");

	pcsaHeader->Add("          }");

	pcsaHeader->Add("");

	pcsaHeader->Add("          if (m_sessLoader.CreateDispatch(clsid))");

	pcsaHeader->Add("          {");

	pcsaHeader->Add("               TRY");

	pcsaHeader->Add("               {");

	pcsaHeader->Add("                    IDispatch *lpScreenDisp = m_sessLoader.requestScreen(\"User\",\"Password\",\"WebView\");");

	pcsaHeader->Add("");

	pcsaHeader->Add("                    if (lpScreenDisp)");

	pcsaHeader->Add("                    {");

	pcsaHeader->Add("                         this->m_screenObj.AttachDispatch(lpScreenDisp);");

	pcsaHeader->Add("");

	pcsaHeader->Add("                         if (!this->m_screenObj.Open())");

	pcsaHeader->Add("                         {");

	pcsaHeader->Add("                              AfxMessageBox(\"open failed\");");

	pcsaHeader->Add("                              return;");

	pcsaHeader->Add("                         }");

	pcsaHeader->Add("");

	pcsaHeader->Add("                         //Start programming here.");

	pcsaHeader->Add("");

}



void CAG_AIR_3270_Ax_CPP::appendBody(int nFunctionNum,
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


	csViewOutStuff.Format( "              // *** %s", csFunctionName );
	pcsaBody->Add(csViewOutStuff);

	checkDebug( b_Debug, csFunctionName, pcsaBody );

	CString	csLocal;

	switch ( nFunctionNum )
	{
		case 0:		// IScreenListener::onConnectionLost
		{
			if ( !b_slScreenListener )
			{
				declareVariable( AG_SCREEN_LISTENER, pcsaHeader, &b_slScreenListener );
			}

			csViewOutStuff.Format( "              isl.onConnectionLost();" );
			pcsaBody->Add(csViewOutStuff);

		}
		break;

		case 1:		// IScreenListener::onError
		{
			if ( !b_slScreenListener )
			{
				declareVariable( AG_SCREEN_LISTENER, pcsaHeader, &b_slScreenListener );
			}

			csViewOutStuff.Format( "              isl.onError();" );
			pcsaBody->Add(csViewOutStuff);

		}
		break;
		
		case 2:		// IScreenListener::onLostRemoteWindow
		{
			if ( !b_slScreenListener )
			{
				declareVariable( AG_SCREEN_LISTENER, pcsaHeader, &b_slScreenListener );
			}

			csViewOutStuff.Format( "              isl.onLostRemoteWindow();" );
			pcsaBody->Add(csViewOutStuff);

		}
		break;

		case 3:		// IScreenListener::onScreenChanged
		{
			if ( !b_slScreenListener )
			{
				declareVariable( AG_SCREEN_LISTENER, pcsaHeader, &b_slScreenListener );
			}

			csViewOutStuff.Format( "              isl.onScreenChanged(com.attachmate.UPG.screen.ScreenChangedEvent e);");
			pcsaBody->Add(csViewOutStuff);

		}
		break;


		case 4:		// IScreenListener::onScreenShapeChanged
		{
			if ( !b_slScreenListener )
			{
				declareVariable( AG_SCREEN_LISTENER, pcsaHeader, &b_slScreenListener );
			}

			csViewOutStuff.Format( "              isl.onScreenShapeChanged(com.attachmate.UPG.screen.ScreenShapeChangeEvent e);");
			pcsaBody->Add(csViewOutStuff);

		}
		break;


		case 5:		// IScreenUPG::addIScreenListener
		{
			if ( !b_slScreenListener )
			{
				declareVariable( AG_SCREEN_LISTENER, pcsaHeader, &b_slScreenListener );
			}

			csViewOutStuff.Format( "              ScreenTn3270 = (ScreenType) sl.requestScreen(User,Password,WebView);");
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "              if (ScreenTn3270 != null)");
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "              {");
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "                   ScreenTn3270.addIScreenListener(this);");
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "                   if (ScreenTn3270.Open())");
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "                   {");
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "                   }");
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "              }");
			pcsaBody->Add(csViewOutStuff);

		}
		break;
 
		case 6:		// IScreenUPG::clearCapturedData
		{
			csViewOutStuff.Format( "         ScreenTn3270 = (ScreenType) sl.requestScreen(User,Password,WebView);");
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "         if (ScreenTn3270 != null)");
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "         {");
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "              ScreenTn3270.clearCapturedData();");
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "         }");
			pcsaBody->Add(csViewOutStuff);

		}
		break;

		case 7:		// IScreenUPG::Close
		{
			csViewOutStuff.Format( "         screen.clearScreen();");
			pcsaBody->Add(csViewOutStuff);
		}
		break;

		case 8:		// Screen::fieldCount
		{
			if ( !b_nCount )
			{
				declareVariable( AG_COUNT, pcsaHeader, &b_nCount );
			}

			csViewOutStuff.Format( "         nCount = screen.fieldCount( %s );", pcsaArguments->GetAt(1) );
			pcsaBody->Add(csViewOutStuff);

		}
		break;


		case 9:		// Screen::getColumns
		{
			if ( !b_nCount )
			{
				declareVariable( AG_COUNT, pcsaHeader, &b_nCount );
			}

			csViewOutStuff.Format( "         nCount = screen.getColumns();" );
			pcsaBody->Add(csViewOutStuff);

		}
		break;


		case 10:		// Screen::getCursorColumn
		{
			if ( !b_nColumn )
			{
				declareVariable( AG_COLUMN, pcsaHeader, &b_nColumn );			
			}

			csViewOutStuff.Format( "         nColumn = screen.getCursorColumn();" );
			pcsaBody->Add(csViewOutStuff);

		}
		break;


		case 11:		// Screen::getCursorRow
		{
			if ( !b_nRow )
			{
				declareVariable( AG_ROW, pcsaHeader, &b_nRow );			
			}

			csViewOutStuff.Format( "         nRow = screen.getCursorRow();" );
			pcsaBody->Add(csViewOutStuff);

		}
		break;


		case 12:		// Screen::getEabEnabled
		{
			if ( !b_bEABs )
			{
				declareVariable( AG_EAB, pcsaHeader, &b_bEABs );			
			}

			csViewOutStuff.Format( "         bEABs = screen.getEabEnabled();" );
			pcsaBody->Add(csViewOutStuff);

		}
		break;


		case 13:	// Screen::getHostCharSet
		{
			if ( !b_nCharSet )
			{
				declareVariable( AG_HOST_CHARSET, pcsaHeader, &b_nCharSet );
			}

			csViewOutStuff.Format( "         nCharSet = screen.getHostCharSet();" );
			pcsaBody->Add(csViewOutStuff);

		}
		break;


		case 14:	// Screen::getHostCodePage 
		{
			if ( !b_nHostCodePage )
			{
				declareVariable( AG_HOST_CODEPAGE, pcsaHeader, &b_nHostCodePage );
			}

			csViewOutStuff.Format( "         nHostCodePage = screen.getHostCodePage();" );
			pcsaBody->Add(csViewOutStuff);

		}
		break;


		case 15:	// Screen::getKeyboardLocked
		{
			if ( !b_bKeyboardLocked )
			{
				declareVariable( AG_KBD_LOCKED, pcsaHeader, &b_bKeyboardLocked );
			}

			csViewOutStuff.Format( "         bKeyboardLocked = screen.getKeyboardLocked();" );
			pcsaBody->Add(csViewOutStuff);

		}
		break;


		case 16:	// Screen::getModel
		{
			if ( !b_nModel )
			{
				declareVariable( AG_MODEL, pcsaHeader, &b_nModel );
			}

			csViewOutStuff.Format( "         nModel = screen.getModel();" );
			pcsaBody->Add(csViewOutStuff);

		}
		break;


		case 17:	// Screen::getOia
		{
			if ( !b_pOIAObject )
			{
				declareVariable( AG_OIAOBJ, pcsaHeader, &b_pOIAObject );
			}

			csViewOutStuff.Format( "         OIAObj = screen.getOia();");
			pcsaBody->Add(csViewOutStuff);


		}
		break;

		case 18:	// Screen::getRows
		{
			if ( !b_nCount )
			{
				declareVariable( AG_COUNT, pcsaHeader, &b_nCount );
			}

			csViewOutStuff.Format( "         nCount = screen.getRows();" );
			pcsaBody->Add(csViewOutStuff);

		}
		break;


		case 19:	// Screen::getScreenType
		{
			if ( !b_nType )
			{
				declareVariable( AG_TYPE, pcsaHeader, &b_nType );
			}

			csViewOutStuff.Format( "         nType = screen.getScreenType();");
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

			
			csViewOutStuff.Format( "         nRow = %s;", pcsaArguments->GetAt(1) );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "         nColumn = %s;", pcsaArguments->GetAt(2) );
			pcsaBody->Add(csViewOutStuff);
			

			csViewOutStuff.Format( "         nLength = %s;", pcsaArguments->GetAt(3) );
			pcsaBody->Add(csViewOutStuff);
			
			csViewOutStuff.Format( "         cString = screen.getString( nRow, nColumn, nLength );");
			pcsaBody->Add(csViewOutStuff);


		}
		break;



		case 21:	// Screen::getText
		{
			if ( !b_cText )
			{
				declareVariable( AG_TEXT, pcsaHeader, &b_cText );
			}

			csViewOutStuff.Format( "         cText = screen.getText();");
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


			csViewOutStuff.Format( "         cString = %s;", pcsaArguments->GetAt(1) );
			pcsaBody->Add(csViewOutStuff);
			
			csViewOutStuff.Format( "         nRow = %s;", pcsaArguments->GetAt(2) );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "         nColumn = %s;", pcsaArguments->GetAt(3) );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "         try");
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "         {");
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "            nLength = screen.putString( cString, nRow, nColumn );");
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "         }");
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "         catch( Exception e )");
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "         {");
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "            System.out.println( \"putString failed\" );");
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "         }");
			pcsaBody->Add(csViewOutStuff);

		}
		break;
	

		case 23:		// screen::refreshEvents
		{
			csViewOutStuff.Format( "	   screen.refreshEvents();" );
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

			csViewOutStuff.Format( "         cText = \"%s\";", pcsaArguments->GetAt(1) );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "         nType = %s;", pcsaArguments->GetAt(2) );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( " " );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "         screen.sendkeys( cText, nType );" );
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

			csViewOutStuff.Format( "         nRow = %s;", pcsaArguments->GetAt(1) );
			pcsaBody->Add(csViewOutStuff);
			csViewOutStuff.Format( "         nColumn = %s;", pcsaArguments->GetAt(2) );
			pcsaBody->Add(csViewOutStuff);
			csViewOutStuff.Format( " " );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "         screen.setCursor( nRow, nColumn );");
			pcsaBody->Add(csViewOutStuff);

		}
		break;

		
		case 26:	// Screen::setEabEnabled
		{
			if ( !b_bEABs )
			{
				declareVariable( AG_EAB, pcsaHeader, &b_bEABs );			
			}

			csViewOutStuff.Format( "         bEABs = TRUE;"); //%s;", pcsaArguments->GetAt(1) );
			pcsaBody->Add(csViewOutStuff);
			csViewOutStuff.Format( " " );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "         screen.setEabEnabled( bEABs );");
			pcsaBody->Add(csViewOutStuff);

		}
		break;


		case 27:	// Screen::setHostCharSet
		{
			if ( !b_nCharSet )
			{
				declareVariable( AG_HOST_CHARSET, pcsaHeader, &b_nCharSet );
			}

			csViewOutStuff.Format( "         nCharSet = %s;", pcsaArguments->GetAt(1) );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "         screen.setHostCharSet( nCharSet );" );
			pcsaBody->Add(csViewOutStuff);

		}
		break;


		case 28:	// Screen::setHostCodePage
		{
			if ( !b_nHostCodePage )
			{
				declareVariable( AG_HOST_CODEPAGE, pcsaHeader, &b_nHostCodePage );
			}

			csViewOutStuff.Format( "         nHostCodePage = %s;", pcsaArguments->GetAt(1) );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "         screen.setHostCodePage( nHostCodePage );" );
			pcsaBody->Add(csViewOutStuff);

		}
		break;


		case 29:	// Screen::setModel
		{
			if ( !b_nModel )
			{
				declareVariable( AG_MODEL, pcsaHeader, &b_nModel );
			}

			csViewOutStuff.Format( "         nModel = %s;", pcsaArguments->GetAt(1) );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( " " );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "         screen.setModel( nModel );" );
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

			csViewOutStuff.Format( "         nRow = %s;", pcsaArguments->GetAt(1) );
			pcsaBody->Add(csViewOutStuff);
			csViewOutStuff.Format( "         nColumn = %s;", pcsaArguments->GetAt(2) );
			pcsaBody->Add(csViewOutStuff);
			csViewOutStuff.Format( " " );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "         screen.waitForCursor( nRow, nColumn );");
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


			csViewOutStuff.Format( "         cText = \"%s\";", pcsaArguments->GetAt(1) );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "         nType = %s;", pcsaArguments->GetAt(2) );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "         nMode = %s;", pcsaArguments->GetAt(3) );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( " " );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "         screen.waitForKeys( cText, nType, nMode );  //XXX" );
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

			csViewOutStuff.Format( "         cText = \"%s\";", pcsaArguments->GetAt(1) );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "         nRow = %s;", pcsaArguments->GetAt(2) );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "         nColumn = %s;", pcsaArguments->GetAt(3) );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "         nWait = %s;", pcsaArguments->GetAt(4) );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( " " );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "         screen.waitForString( cText, nRow, nColumn, nWait );  //XXX");
			pcsaBody->Add(csViewOutStuff);
		}
		break;


		case 33:		// screen.waithostquiet
		{
			if ( !b_nWait )
			{
				declareVariable( AG_WAIT, pcsaHeader, &b_nWait );
			}

			csViewOutStuff.Format( "         nWait = %s;", pcsaArguments->GetAt(1) );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( " " );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "         screen.waithostquiet( nWait );");
			pcsaBody->Add(csViewOutStuff);
		}
		break;


		case 34:	// Session::attach
		{
			csViewOutStuff.Format( "         try" );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "         {" );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "            session.attach(session.ATTACH_MUSTBELOADED);" );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "         }" );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "         catch (e)" );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "         {" );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "            alert( \"attach exception thrown\");" );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "         }" );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( " " );
			pcsaBody->Add(csViewOutStuff);

		}
		break;


		case 35:	// session.connect
		{
			csViewOutStuff.Format( "         term.session.connect();");
			pcsaBody->Add(csViewOutStuff);
		}
		break;


		case 36:	// Session::detach
		{
			csViewOutStuff.Format( "         term.session.detach(0);");
			pcsaBody->Add(csViewOutStuff);
		}
		break;


		case 37:	// Session::disconnect 
		{
			csViewOutStuff.Format( "         term.session.disconnect(0);");
			pcsaBody->Add(csViewOutStuff);
		}
		break;

		
		case 38:	// Session::getAttached
		{
			
				if ( !b_bAttached )
				{
					declareVariable( AG_ATTACHED, pcsaHeader, &b_bAttached );				
				}

				csViewOutStuff.Format( "         try");
				pcsaBody->Add(csViewOutStuff);

				csViewOutStuff.Format( "         {");
				pcsaBody->Add(csViewOutStuff);

				csViewOutStuff.Format( "            bAttached = session.getAttached();");
				pcsaBody->Add(csViewOutStuff);

				csViewOutStuff.Format( "         }");
				pcsaBody->Add(csViewOutStuff);

				csViewOutStuff.Format( "         catch (e)");
				pcsaBody->Add(csViewOutStuff);

				csViewOutStuff.Format( "         {");
				pcsaBody->Add(csViewOutStuff);

				csViewOutStuff.Format( "            alert( \"getAttached exception thrown\" );");
				pcsaBody->Add(csViewOutStuff);

				csViewOutStuff.Format( "         }");
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

				csViewOutStuff.Format( "         try");
				pcsaBody->Add(csViewOutStuff);

				csViewOutStuff.Format( "         {");
				pcsaBody->Add(csViewOutStuff);

				csViewOutStuff.Format( "            bConnected = session.getConnected();");
				pcsaBody->Add(csViewOutStuff);

				csViewOutStuff.Format( "         }");
				pcsaBody->Add(csViewOutStuff);

				csViewOutStuff.Format( "         catch (e)");
				pcsaBody->Add(csViewOutStuff);

				csViewOutStuff.Format( "         {");
				pcsaBody->Add(csViewOutStuff);

				csViewOutStuff.Format( "            alert( \"getConnected exception thrown\" );");
				pcsaBody->Add(csViewOutStuff);

				csViewOutStuff.Format( "         }");
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

				csViewOutStuff.Format( "         try");
				pcsaBody->Add(csViewOutStuff);

				csViewOutStuff.Format( "         {");
				pcsaBody->Add(csViewOutStuff);

				csViewOutStuff.Format( "            conn = session.getConnection();");
				pcsaBody->Add(csViewOutStuff);

				csViewOutStuff.Format( "         }");
				pcsaBody->Add(csViewOutStuff);

				csViewOutStuff.Format( "         catch (e)");
				pcsaBody->Add(csViewOutStuff);

				csViewOutStuff.Format( "         {");
				pcsaBody->Add(csViewOutStuff);

				csViewOutStuff.Format( "            alert( \"getConnection exception thrown\" );");
				pcsaBody->Add(csViewOutStuff);

				csViewOutStuff.Format( "         }");
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

				csViewOutStuff.Format( "         try");
				pcsaBody->Add(csViewOutStuff);

				csViewOutStuff.Format( "         {");
				pcsaBody->Add(csViewOutStuff);

				csViewOutStuff.Format( "            screen = session.getScreen();");
				pcsaBody->Add(csViewOutStuff);

				csViewOutStuff.Format( "         }");
				pcsaBody->Add(csViewOutStuff);

				csViewOutStuff.Format( "         catch (e)");
				pcsaBody->Add(csViewOutStuff);

				csViewOutStuff.Format( "         {");
				pcsaBody->Add(csViewOutStuff);

				csViewOutStuff.Format( "            alert( \"getScreen exception thrown\" );");
				pcsaBody->Add(csViewOutStuff);

				csViewOutStuff.Format( "         }");
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
			
			csViewOutStuff.Format( "         nState = session.getState();");
			pcsaBody->Add(csViewOutStuff);
		}
		break;

		case 43:	// Session::setConnected
		{
			
				if ( !b_bConnected )
				{
					declareVariable( AG_CONNECTED, pcsaHeader, &b_bConnected  );
				}

				csViewOutStuff.Format( "         bConnected = TRUE;" );
				pcsaBody->Add(csViewOutStuff);

				csViewOutStuff.Format( " " );
				pcsaBody->Add(csViewOutStuff);

				csViewOutStuff.Format( "         try");
				pcsaBody->Add(csViewOutStuff);

				csViewOutStuff.Format( "         {");
				pcsaBody->Add(csViewOutStuff);

				csViewOutStuff.Format( "            session.setConnected( bConnected );");
				pcsaBody->Add(csViewOutStuff);

				csViewOutStuff.Format( "         }");
				pcsaBody->Add(csViewOutStuff);

				csViewOutStuff.Format( "         catch (e)");
				pcsaBody->Add(csViewOutStuff);

				csViewOutStuff.Format( "         {");
				pcsaBody->Add(csViewOutStuff);

				csViewOutStuff.Format( "            alert( \"setConnected exception thrown\" );");
				pcsaBody->Add(csViewOutStuff);

				csViewOutStuff.Format( "         }");
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

				csViewOutStuff.Format( "         try");
				pcsaBody->Add(csViewOutStuff);

				csViewOutStuff.Format( "         {");
				pcsaBody->Add(csViewOutStuff);

				csViewOutStuff.Format( "            session.setConnection( conn );");
				pcsaBody->Add(csViewOutStuff);

				csViewOutStuff.Format( "         }");
				pcsaBody->Add(csViewOutStuff);

				csViewOutStuff.Format( "         catch (e)");
				pcsaBody->Add(csViewOutStuff);

				csViewOutStuff.Format( "         {");
				pcsaBody->Add(csViewOutStuff);

				csViewOutStuff.Format( "            alert( \"setConnection exception thrown\" );");
				pcsaBody->Add(csViewOutStuff);

				csViewOutStuff.Format( "         }");
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

				csViewOutStuff.Format( "         try");
				pcsaBody->Add(csViewOutStuff);

				csViewOutStuff.Format( "         {");
				pcsaBody->Add(csViewOutStuff);

				csViewOutStuff.Format( "            session.setScreen( screen );");
				pcsaBody->Add(csViewOutStuff);

				csViewOutStuff.Format( "         }");
				pcsaBody->Add(csViewOutStuff);

				csViewOutStuff.Format( "         catch (e)");
				pcsaBody->Add(csViewOutStuff);

				csViewOutStuff.Format( "         {");
				pcsaBody->Add(csViewOutStuff);

				csViewOutStuff.Format( "            alert( \"setScreen exception thrown\" );");
				pcsaBody->Add(csViewOutStuff);

				csViewOutStuff.Format( "         }");
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

				csViewOutStuff.Format( "         cText = conn.getSocksAddress();" );
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

				csViewOutStuff.Format( "         nPort = conn.getSocksPort();" );
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

				csViewOutStuff.Format( "         cText = conn.getTelnetAddress();" );
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

				csViewOutStuff.Format( "         nPort = conn.getTelnetPort();" );
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

				csViewOutStuff.Format( "         cText = \"%s\";", pcsaArguments->GetAt(1) );
				pcsaBody->Add(csViewOutStuff);

				csViewOutStuff.Format( "         conn.setSocksAddress( cText );" );
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

				csViewOutStuff.Format( "         nPort = %s;", pcsaArguments->GetAt(1) );
				pcsaBody->Add(csViewOutStuff);

				csViewOutStuff.Format( "         conn.setSocksPort( nPort );" );
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

				csViewOutStuff.Format( "         cText = \"%s\";", pcsaArguments->GetAt(1) );
				pcsaBody->Add(csViewOutStuff);

				csViewOutStuff.Format( "         conn.setTelnetAddress( cText );" );
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

				csViewOutStuff.Format( "         nPort = %s;", pcsaArguments->GetAt(1) );
				pcsaBody->Add(csViewOutStuff);

				csViewOutStuff.Format( "         conn.setTelnetPort( nPort );" );
				pcsaBody->Add(csViewOutStuff);

				csViewOutStuff.Format( "");
				pcsaBody->Add(csViewOutStuff);
				
		}
		break;


	}

	pcsaArguments->RemoveAll();
}


void CAG_AIR_3270_Ax_CPP::finalize(CStringArray* pcsaBody)
{
	pcsaBody->Add("                         this->m_screenObj.Close()");

	pcsaBody->Add("                    }");

	pcsaBody->Add("                    CATCH_ALL(e)");

	pcsaBody->Add("                    {");

	pcsaBody->Add("                       char buff[1024];");

	pcsaBody->Add("                       e->GetErrorMessage(buff,1024,NULL);");

	pcsaBody->Add("                       AfxMessageBox(buff);");

	pcsaBody->Add("                       this->m_screenObj.Close();");

	pcsaBody->Add("                    }");

	pcsaBody->Add("                    END_CATCH_ALL");

	pcsaBody->Add("                }");

	pcsaBody->Add("                CATCH_ALL(e)");

	pcsaBody->Add("           }");

	pcsaBody->Add("         }");

	pcsaBody->Add("         CATCH_ALL(e)");
	pcsaBody->Add("         {");
	pcsaBody->Add("              AfxMessageBox(\"Error:  Failed to create 'SessionLoader.SessionLoader' object\");");
	pcsaBody->Add("              return;");
	pcsaBody->Add("         }");
	pcsaBody->Add("         END_CATCH_ALL");

	pcsaBody->Add("    }");

	b_Debug = FALSE;
}



/****************************************************************************DC
	Function	:	CAG_AIR_3270_Ax_CPP::declareVariable()

	Purpose		:	Append variable declarations to the end of the header as 
					needed.

*****************************************************************************/
void CAG_AIR_3270_Ax_CPP::declareVariable(AG_VARIABLE agVariable,
									   CStringArray* pcsaHeader,
									   bool* bValue)
{
	CString csLocal;
	*bValue = TRUE;
	
	switch ( agVariable )
	{
		case AG_STATUS:
		{
			csLocal.Format( "   int nStatus=0;");
		}
		break;

		case AG_UPDATED:
		{
			csLocal.Format( "   boolean bUpdated=false;");
		}
		break;

		case AG_UTILBUFFER:
		{
			csLocal.Format( "   String Buffer=\" \";");
		}
		break;

		case AG_ROW:
		{
			csLocal.Format( "   int nRow=0;");
		}
		break;

		case AG_COLUMN:
		{
			csLocal.Format( "   int nColumn=0;");		
		}
		break;

		case AG_ATTRIBUTE:
		{
			csLocal.Format( "   int nAttribute=0;");
		}
		break;

		case AG_LENGTH:
		{
			csLocal.Format( "   int nLength=0;");
		}
		break;

		case AG_VALUE:
		{
			csLocal.Format( "   int nValue=0;");
		}
		break;

		case AG_RETURN:
		{
			csLocal.Format( "   boolean bRet=false;");
		}
		break;

		case AG_CLOSEOPTION:
		{
			csLocal.Format( "   int nCloseOption=0;");
		}
		break;

		case AG_HOST_OS:
		{
			csLocal.Format( "   int nFTHostOS=0;");
		}
		break;

		case AG_HEIGHT:
		{
			csLocal.Format( "   int nHeight=0;");
		}
		break;

		case AG_LOCALMODE:
		{
			csLocal.Format( "   boolean bLocalMode=false;");
		}
		break;

		case AG_SESS_SAVED:
		{
			csLocal.Format( "   boolean bSessionSaved=false;");
		}
		break;

		case AG_SESSIONS_CREATED:
		{
			csLocal.Format( "   String Sessions[];" );
		}
		break;

		case AG_SESS_OPEN:
		{
			csLocal.Format( "   String SessName=\" \";");
		}
		break;


		case AG_SETTLE_TIME:
		{
			csLocal.Format( "   int nSettleTime=0;");
		}
		break;

		case AG_SESS_QUIET:
		{
			csLocal.Format( "   boolean bSessionQuiet=false;");
		}
		break;

		case AG_MENU_VISIBLE:
		{
			csLocal.Format( "   boolean bMenuVisible=false;");
		}
		break;

		case AG_TYPE:
		{
			csLocal.Format( "   int nType=0;");
		}
		break;

		case AG_TIMEOUT:
		{
			csLocal.Format( "   int nTimeout=0;");
		}
		break;

		case AG_PROCESS_KEYSTROKES:
		{
			csLocal.Format( "   boolean bProcessKeystrokes=false;");
		}
		break;

		case AG_WIDTH:
		{
			csLocal.Format( "   int nWidth=0;");
		}
		break;

		case AG_WINDOW_HANDLE:
		{
			csLocal.Format( "   int hSession=0;");
			//csLocal.Format( "   HANDLE hSession=NULL;");
		}
		break;

		case AG_WINDOW_STATE:
		{
			csLocal.Format( "   int nWindowState=0;");
		}
		break;

		case AG_COUNT:
		{
			csLocal.Format( "   int nCount=0;");
		}
		break;

		case AG_AREA:
		{
			csLocal.Format( "   //String Area=\" \";");
		}
		break;

		// new stuff
		case AG_NAME:
		{
			csLocal.Format( "   String csName=\" \";" );
		}
		break;

		case AG_SCREEN_LISTENER:
		{
			csLocal.Format( "   IScreenListener isl;" );
		}
		break;

		case AG_TERMINAL:
		{
			csLocal.Format( "   //Terminal;" );
		}
		break;

		case AG_OIAOBJ:
		{
			csLocal.Format( "   Oia3270 OIAObj;" );
		}
		break;

		case AG_TEXT:
		{
			csLocal.Format( "   String cText=\" \";" );
		}
		break;

		case AG_EAB:
		{
			csLocal.Format( "   boolean bEABs=false;" );
		}
		break;

		case AG_HOST_CHARSET:
		{
			csLocal.Format( "   int nCharSet=0;" );
		}
		break;

		case AG_HOST_CODEPAGE:
		{
			csLocal.Format( "   int nHostCodePage=0;" );
		}
		break;

		case AG_KBD_LOCKED:
		{
			csLocal.Format( "   boolean bKeyboardLocked=false;" );
		}
		break;

		case AG_MODEL:	
		{
			csLocal.Format( "   int nModel=0;" );
		}
		break;

		case AG_STRING:
		{
			csLocal.Format( "   String cString=\" \";" );
		}
		break;

		case AG_MODE:
		{
			csLocal.Format( "   int nMode=0;" );
		}
		break;

		case AG_WAIT:
		{
			csLocal.Format( "   int nWait=0;" );
		}
		break;

		case AG_ATTACHED:
		{
			csLocal.Format( "   boolean bAttached=false;" );
		}
		break;

		case AG_CONNECTED:
		{
			csLocal.Format( "   boolean bConnected=false;" );
		}
		break;

		case AG_CONNECTION_OBJ:
		{
			csLocal.Format( "   ConTN3270 conn;" );
		}
		break;

		case AG_SCREEN_OBJ:
		{
			csLocal.Format( "   Screen3270 screen;" );
		}
		break;

		case AG_STATE:
		{
			csLocal.Format( "   int nState=0;" );
		}
		break;

		case AG_PORT:
		{
			csLocal.Format( "   int nPort=0;" );
		}
		break;




	}

	pcsaHeader->Add(csLocal);

}


void CAG_AIR_3270_Ax_CPP::resetVariableFlags()
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
   b_slScreenListener=FALSE;

}