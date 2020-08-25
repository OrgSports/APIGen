// Static Model
#include "stdafx.h"
#include "apigen.h"

#include "CAG_AIR_VT_J_J.h"
#include "time.h"


CAG_AIR_VT_J_J::CAG_AIR_VT_J_J()
{
	resetVariableFlags();
}


CAG_AIR_VT_J_J::~CAG_AIR_VT_J_J()
{
	
}




void CAG_AIR_VT_J_J::generateHeader(CStringArray* pcsaHeader,
									  CStringArray* pcsaBody)
{
	// prepare the xml session file.
	// if the user presses OK then the xml file prepends the generated code.
	// if the user presses cancel then only the code is generated.
	if (IDOK == XMLVTDlg.DoModal())
	{
		CString csLocalString;
		pcsaHeader->Add("/* VT.XML Airlines SDK Configuration File");

		CString csConnectionParams, csScreenParams, csLightPen;

		// screen parameter
		csScreenParams = "<ScreenVt Columns=\"80\" Rows=\"24\"";
		
		if ( XMLVTDlg.csEditVTTabColumns.GetLength() != 0 )
		{
			CString csLocalScreenParam;
			csLocalScreenParam.Format( " TabsColumns=\"%s\"", XMLVTDlg.csEditVTTabColumns );
			csScreenParams+=csLocalScreenParam;
		}

		if ( XMLVTDlg.bCheckVTAutoWrap )
		{
			csScreenParams+=" AutoWrap=\"true\"";
		}
		csScreenParams+=">";


		// telnet connection tool
		csConnectionParams = "        <Telnetcon";
		if ( XMLVTDlg.bCheckVTLocalMode )
		{
			csConnectionParams+=" LocalEcho=\"true\"";
		}

		if ( XMLVTDlg.bCheckVTInitiateNegotiation )
		{
			csConnectionParams+=" InitiateNegotiation=\"true\"";
		}

		if ( XMLVTDlg.bCheckVTInitiateNegotiation )
		{
			csConnectionParams+=" NegotiateBinary=\"false\"";
		}

		csConnectionParams+=">";



		pcsaHeader->Add(csScreenParams);
		pcsaHeader->Add(csConnectionParams);
		csLocalString.Format( "               <TcpTelnetcon HostName=\"%s\" PortNumber=\"%s\"\\>", XMLVTDlg.csEditVTHostName, XMLVTDlg.csEditVTPortNumber );
		pcsaHeader->Add(csLocalString);
		pcsaHeader->Add("        <\\TnVTcon>");
		pcsaHeader->Add(csLocalString);
		pcsaHeader->Add("<\\ScreenTnVT>");
		pcsaHeader->Add(" *** END VT.XML Airlines SDK Configuration File ***/ ");
		pcsaHeader->Add("");
		pcsaHeader->Add("");
	}   

	// name and open output file if specified
	SYSTEMTIME	systime;
	GetSystemTime(&systime);
	time_t osBinaryTime;
	time( &osBinaryTime ) ;
	CTime t( osBinaryTime );
	
	int nMonth = t.GetMonth();
	int nDay = t.GetDay();
	int nYear = t.GetYear();

	// output to Translator's output window
	CString csViewOutStuff;
	pcsaHeader->Add("// ****************************************************************************");
	pcsaHeader->Add("//                Attachmate Airlines VT SDK");
	pcsaHeader->Add("//                   APIGen Java Application");
	pcsaHeader->Add("//");
	pcsaHeader->Add("//   When compiled, this becomes a freestanding Java program that contains a list");
	pcsaHeader->Add("//    of Airlines SDK VT Applet Java method calls specified to the APIGen code");
	pcsaHeader->Add("//    generator.");
	pcsaHeader->Add("//");
	pcsaHeader->Add("//    These conditions must be met before this source file can be used.");
	pcsaHeader->Add("//       1. Either the class name (AirVT) or the file name must be changed as");
	pcsaHeader->Add("//          they must be the same.");
	pcsaHeader->Add("//       2. The Attachmate Airlines SDK must be installed using the keycode for VT. Its");
	pcsaHeader->Add("//           class or jar files must be made accessible via the class path.");
	pcsaHeader->Add("//       3. If you specified the parameters for a VT session XML configuration file");
	pcsaHeader->Add("//          immediately after you pressed the API Generator's Generate button the text of");
	pcsaHeader->Add("//          th file is listed at the top of this file.  To use it you will need to move it");
	pcsaHeader->Add("//          to its own file and either place the new file named, \"VT.xml\" to the c:\\temp");
	pcsaHeader->Add("//          folder on your PC or change the xml file name and its location in the getXmlConfig");
	pcsaHeader->Add("//          function below.");
	pcsaHeader->Add("//       4. <<other stuff>>");

	time_t ltime;
	time( &ltime );

	pcsaHeader->Add("//");

	csViewOutStuff.Format( "//   Generated:   %s", ctime( &ltime ) );
	pcsaHeader->Add(csViewOutStuff);
	pcsaHeader->Add("//");
	pcsaHeader->Add("// ****************************************************************************");
	pcsaHeader->Add("");
	pcsaHeader->Add("import java.io.*;" );
	pcsaHeader->Add("import com.attachmate.UPG.screenTnVT.*;" );
	pcsaHeader->Add("import com.attachmate.UPG.SessionLoader.*;" );
	pcsaHeader->Add("import com.attachmate.emulation.exception.*;" );
	pcsaHeader->Add("");
	pcsaHeader->Add("public class AirVT implements IScreenListener");
	pcsaHeader->Add("{" );

	//***************************  Main  ***************************
	pcsaHeader->Add("   public static void main(String args[]) throws IOException" );
	pcsaHeader->Add("   {" );
	pcsaHeader->Add("      AirVT aVT = new AirVT();" );
	pcsaHeader->Add("" );
	pcsaHeader->Add("      try" );
	pcsaHeader->Add("      {" );
	pcsaHeader->Add("         c.processHost();" );
	pcsaHeader->Add("      }" );
	pcsaHeader->Add("      catch (Exception e)" );
	pcsaHeader->Add("      {" );
	pcsaHeader->Add("         System.out.println( e.getMessage() );");
	pcsaHeader->Add("      }" );
	pcsaHeader->Add("" );
	pcsaHeader->Add("   }" );

	pcsaHeader->Add("" );
	pcsaHeader->Add("" );

	pcsaHeader->Add("   private String getXmlConfig()" );
	pcsaHeader->Add("   {" );
	pcsaHeader->Add("      String strConfig = "";" );
	pcsaHeader->Add("      try" );
	pcsaHeader->Add("      {" );
	pcsaHeader->Add("         //Read XML file for Configuration and Host" );
	pcsaHeader->Add("         String line = "";" );
	pcsaHeader->Add("         FileInputStream fis = null;" );
	pcsaHeader->Add("         fis = new FileInputStream(\"C:\\temp\\VT.xml\");" );
	pcsaHeader->Add("         BufferedReader in =  new BufferedReader (new InputStreamReader (fis));" );
	pcsaHeader->Add("         while ((line = in.readLine()) != null)" );
	pcsaHeader->Add("         {" );
	pcsaHeader->Add("            strConfig += line;" );
	pcsaHeader->Add("         }" );
	pcsaHeader->Add("" );
	pcsaHeader->Add("        fis.close();" );
	pcsaHeader->Add("      }" );
	pcsaHeader->Add("      catch (Exception e)" );
	pcsaHeader->Add("      {" );
	pcsaHeader->Add("         System.out.println( e.getMessage() );");
	pcsaHeader->Add("      }" );
	pcsaHeader->Add("" );
	pcsaHeader->Add("      return strConfig;" );
	pcsaHeader->Add("" );
	pcsaHeader->Add("   }" );
	pcsaHeader->Add("" );
	pcsaHeader->Add("" );
	pcsaHeader->Add("   private void processHost()" );
	pcsaHeader->Add("   {" );
	pcsaHeader->Add("      SessionLoader sessLoader = new SessionLoader();" );
	pcsaHeader->Add("      ScreenTnVT screen;" );
	pcsaHeader->Add("      String strConfig = getXmlConfig();" );
	pcsaHeader->Add("      System.out.println(\"DEBUG:    strConfig = \" + strConfig);" );
	pcsaHeader->Add("" );
	pcsaHeader->Add("      try" );
	pcsaHeader->Add("      {" );
	pcsaHeader->Add("         screen = (ScreenTnVT) sessLoader.requestScreenEx(\"\",\"\",strConfig,0);" );
	pcsaHeader->Add("         if (!screen.Open())" );
	pcsaHeader->Add("         {" );
	pcsaHeader->Add("            System.out.println(\"Open Failed on Session \");" );
	pcsaHeader->Add("         }" );
	pcsaHeader->Add("         else" );
	pcsaHeader->Add("         {" );
	pcsaHeader->Add("            screen.waitHostQuiet(3000,6000);" );
	pcsaHeader->Add("            screen.setgetText_Display(true);" );
	pcsaHeader->Add("            screen.getText();" );
	pcsaHeader->Add("            screen.Close();" );
	pcsaHeader->Add("            System.out.println(\"System closed\");" );

	pcsaBody->Add("" );
	pcsaBody->Add("            System.out.println(\"Sleeping...\");" );
	pcsaBody->Add("            Thread.sleep(5000);" );
	pcsaBody->Add("            System.out.println(\"isConnected: \" + screen.isConnected());" );
	pcsaBody->Add("" );

}



void CAG_AIR_VT_J_J::appendBody(int nFunctionNum,
								  bool bPromptForValues,
								  CStringArray* pcsaArguments,
								  CStringArray* pcsaHeader,
								  CStringArray* pcsaBody)
{
	CString csViewOutStuff;
	CString csFunctionName;

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

			pcsaBody->Add("              isl.onConnectionLost();" );
			pcsaBody->Add(" " );
		}
		break;

		case 1:		// IScreenListener::onError
		{
			if ( !b_slScreenListener )
			{
				declareVariable( AG_SCREEN_LISTENER, pcsaHeader, &b_slScreenListener );
			}

			pcsaBody->Add("              isl.onError();" );
			pcsaBody->Add(" " );
		}
		break;
		
		case 2:		// IScreenListener::onLostRemoteWindow
		{
			if ( !b_slScreenListener )
			{
				declareVariable( AG_SCREEN_LISTENER, pcsaHeader, &b_slScreenListener );
			}

			pcsaBody->Add("              isl.onLostRemoteWindow();" );
			pcsaBody->Add(" " );
		}
		break;

		case 3:		// IScreenListener::onScreenChanged
		{
			if ( !b_slScreenListener )
			{
				declareVariable( AG_SCREEN_LISTENER, pcsaHeader, &b_slScreenListener );
			}

			pcsaBody->Add("              isl.onScreenChanged(com.attachmate.UPG.screen.ScreenChangedEvent e);");
			pcsaBody->Add(" " );
		}
		break;


		case 4:		// IScreenListener::onScreenShapeChanged
		{
			if ( !b_slScreenListener )
			{
				declareVariable( AG_SCREEN_LISTENER, pcsaHeader, &b_slScreenListener );
			}

			pcsaBody->Add("              isl.onScreenShapeChanged(com.attachmate.UPG.screen.ScreenShapeChangeEvent e);");
			pcsaBody->Add(" " );
		}
		break;


		case 5:		// IScreenUPG::addIScreenListener
		{
			if ( !b_slScreenListener )
			{
				declareVariable( AG_SCREEN_LISTENER, pcsaHeader, &b_slScreenListener );
			}

			pcsaBody->Add("              ScreenTnVT = (ScreenType) sessLoader.requestScreen(User,Password,WebView);");
			pcsaBody->Add("              if (ScreenTnVT != null)");
			pcsaBody->Add("              {");
			pcsaBody->Add("                   ScreenTnVT.addIScreenListener(this);");
			pcsaBody->Add("                   if (ScreenTnVT.Open())");
			pcsaBody->Add("                   {");
			pcsaBody->Add("                   }");
			pcsaBody->Add("              }");
			pcsaBody->Add(" " );
		}
		break;
 
		case 6:		// IScreenUPG::clearCapturedData
		{
			pcsaBody->Add("            ScreenTnVT = (ScreenType) sessLoader.requestScreen(User,Password,WebView); //XXX declare vars");
			pcsaBody->Add("            if (ScreenTnVT != null)");
			pcsaBody->Add("            {");
			pcsaBody->Add("                 ScreenTnVT.clearCapturedData();");
			pcsaBody->Add("            }");
			pcsaBody->Add(" " );
		}
		break;

		case 7:		// IScreenUPG::Close
		{
			pcsaBody->Add("            screen.Close();");
			pcsaBody->Add(" " );
		}
		break;

		case 8:		// IScreenUPG::fieldCount
		{
			if ( !b_nCount )
			{
				declareVariable( AG_COUNT, pcsaHeader, &b_nCount );
			}

			csViewOutStuff.Format( "            nCount = screen.fieldCount( %s );", pcsaArguments->GetAt(1) );
			pcsaBody->Add(csViewOutStuff);

			pcsaBody->Add(" " );
		}
		break;

		case 9:		// IScreenUPG::findField
		{
			if ( !b_nRow )
			{
				declareVariable( AG_ROW, pcsaHeader, &b_nRow );			
			}

			if ( !b_nColumn )
			{
				declareVariable( AG_COLUMN, pcsaHeader, &b_nColumn );			
			}

			if ( !b_nMode )
			{
				declareVariable( AG_MODE, pcsaHeader, &b_nMode );
			}

			if ( !b_nType )
			{
				declareVariable( AG_TYPE, pcsaHeader, &b_nType );
			}

			if ( !b_bWrap )
			{
				declareVariable( AG_WRAP, pcsaHeader, &b_bWrap );
			}

			if ( !b_bRet )
			{
				declareVariable( AG_RETURN, pcsaHeader, &b_bRet );
			}

			if ( !b_nOutRow )
			{
				declareVariable( AG_OUTROW, pcsaHeader, &b_nOutRow );
			}

			if ( !b_nOutColumn )
			{
				declareVariable( AG_OUTCOLUMN, pcsaHeader, &b_nOutColumn );
			}

			if ( !b_nOutLength )
			{
				declareVariable( AG_OUTLENGTH, pcsaHeader, &b_nOutLength );
			}

			if ( !b_nOutAttribute )
			{
				declareVariable( AG_OUTATTRIBUTE, pcsaHeader, &b_nOutAttribute );
			}

			csViewOutStuff.Format( "            nRow = %s;", pcsaArguments->GetAt(1) );
			pcsaBody->Add(csViewOutStuff);
			csViewOutStuff.Format( "            nColumn = %s;", pcsaArguments->GetAt(2) );
			pcsaBody->Add(csViewOutStuff);
			csViewOutStuff.Format( "            nMode = %s;", pcsaArguments->GetAt(3) );
			pcsaBody->Add(csViewOutStuff);
			csViewOutStuff.Format( "            nType = %s;", pcsaArguments->GetAt(4) );
			pcsaBody->Add(csViewOutStuff);
			csViewOutStuff.Format( "            bWrap = %s;", pcsaArguments->GetAt(5) );
			pcsaBody->Add(csViewOutStuff);

			pcsaBody->Add("" );
			pcsaBody->Add("            bRet = screen.findField( nRow, nColumn, nMode, nType, bWrap, " );
			pcsaBody->Add("                                     nOutRow, nOutColumn, nOutLength, nOutAttribute  );" );
			pcsaBody->Add(" " );
		}
		break;

		case 10:	// IScreenUPG::findFieldEx
		{
			if ( !b_nIndex )
			{
				declareVariable( AG_INDEX, pcsaHeader, &b_nIndex );
			}

			if ( !b_nMode )
			{
				declareVariable( AG_MODE, pcsaHeader, &b_nMode );
			}

			if ( !b_nType )
			{
				declareVariable( AG_TYPE, pcsaHeader, &b_nType );
			}

			if ( !b_bWrap )
			{
				declareVariable( AG_WRAP, pcsaHeader, &b_bWrap );
			}

			if ( !b_bRet )
			{
				declareVariable( AG_RETURN, pcsaHeader, &b_bRet );
			}

			if ( !b_nOutRow )
			{
				declareVariable( AG_OUTROW, pcsaHeader, &b_nOutRow );
			}

			if ( !b_nOutColumn )
			{
				declareVariable( AG_OUTCOLUMN, pcsaHeader, &b_nOutColumn );
			}

			if ( !b_nOutLength )
			{
				declareVariable( AG_OUTLENGTH, pcsaHeader, &b_nOutLength );
			}

			if ( !b_nOutAttribute )
			{
				declareVariable( AG_OUTATTRIBUTE, pcsaHeader, &b_nOutAttribute );
			}

			csViewOutStuff.Format( "            nIndex = %s;", pcsaArguments->GetAt(1) );
			pcsaBody->Add(csViewOutStuff);
			csViewOutStuff.Format( "            nMode = %s;", pcsaArguments->GetAt(2) );
			pcsaBody->Add(csViewOutStuff);
			csViewOutStuff.Format( "            nType = %s;", pcsaArguments->GetAt(3) );
			pcsaBody->Add(csViewOutStuff);
			csViewOutStuff.Format( "            bWrap = %s;", pcsaArguments->GetAt(4) );
			pcsaBody->Add(csViewOutStuff);

			pcsaBody->Add("" );
			pcsaBody->Add("            bRet = screen.findFieldEx( nIndex, nMode, nType, bWrap," );
			pcsaBody->Add("                                       nOutRow, nOutColumn, nOutLength, nOutAttribute  );" );
			pcsaBody->Add("" );
		}
		break;


		case 11:	// IScreenUPG::findString
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

			if ( !b_nOutRow )
			{
				declareVariable( AG_OUTROW, pcsaHeader, &b_nOutRow );
			}

			if ( !b_nOutColumn )
			{
				declareVariable( AG_OUTCOLUMN, pcsaHeader, &b_nOutColumn );
			}

			csViewOutStuff.Format( "            cText = %s;", pcsaArguments->GetAt(1) );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "            nRow = %s;", pcsaArguments->GetAt(2) );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "            nColumn = %s;", pcsaArguments->GetAt(3) );
			pcsaBody->Add(csViewOutStuff);

			pcsaBody->Add("" );
			pcsaBody->Add("            bRet = screen.findString( cText, nRow, nColumn, nOutRow, nOutColumn );" );
			pcsaBody->Add(" " );
		
		}
		break;

		case 12:	// IScreenUPG::findStringEx
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

			if ( !b_nEndRow )
			{
				declareVariable( AG_ENDROW, pcsaHeader, &b_nEndRow );			
			}

			if ( !b_nEndColumn )
			{
				declareVariable( AG_ENDCOLUMN, pcsaHeader, &b_nEndColumn );			
			}

			if ( !b_bWrap )
			{
				declareVariable( AG_WRAP, pcsaHeader, &b_bWrap );
			}

			if ( !b_nDirection )
			{
				declareVariable( AG_DIRECTION, pcsaHeader, &b_nDirection );
			}

			if ( !b_nOutRow )
			{
				declareVariable( AG_OUTROW, pcsaHeader, &b_nOutRow );
			}

			if ( !b_nOutColumn )
			{
				declareVariable( AG_OUTCOLUMN, pcsaHeader, &b_nOutColumn );
			}

			csViewOutStuff.Format( "            cText = %s;", pcsaArguments->GetAt(1) );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "            nRow = %s;", pcsaArguments->GetAt(2) );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "            nColumn = %s;", pcsaArguments->GetAt(3) );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "            nEndRow = %s;", pcsaArguments->GetAt(4) );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "            nEndColumn = %s;", pcsaArguments->GetAt(5) );
			pcsaBody->Add(csViewOutStuff);

			if ( -1 != pcsaArguments->GetAt(6).Find( "TRUE" ) )
			{
				csViewOutStuff.Format( "            nWrap = true;" );
			}
			else
			{
				csViewOutStuff.Format( "            nWrap = false;" );
			}
			pcsaBody->Add(csViewOutStuff);

			if ( -1 != pcsaArguments->GetAt(7).Find( "DIRECTION_FORWARD" ) )
			{
				csViewOutStuff.Format( "            nDir = 0;" );
			}
			else
			{
				csViewOutStuff.Format( "            nDir = 4;" );
			}
			pcsaBody->Add(csViewOutStuff);

			pcsaBody->Add("" );
			pcsaBody->Add("            bRet = screen.findStringEx( cText, nRow, nColumn, nEndRow, nEndColumn," );
			pcsaBody->Add("                                        0, nWrap, nDir, nOutRow, nOutColumn );" );
			pcsaBody->Add(" " );

		}
		break;


		case 13:	// IScreenUPG::getCapturedData
		{
			if ( !b_nBuffer )
			{
				declareVariable( AG_UTILBUFFER, pcsaHeader, &b_nBuffer );
			}

			pcsaBody->Add("            Buffer = screen.getCapturedData()" );
			pcsaBody->Add(" " );

		}
		break;

		case 14:	// IScreenUPG::getColumns
		{
			if ( !b_nCount )
			{
				declareVariable( AG_COUNT, pcsaHeader, &b_nCount );
			}

			pcsaBody->Add("            nCount = screen.getColumns();" );
		}
		break;

		case 15:		// IScreenUPG::getCursor
		{
			if ( !b_nOutRow )
			{
				declareVariable( AG_OUTROW, pcsaHeader, &b_nOutRow );
			}

			if ( !b_nOutColumn )
			{
				declareVariable( AG_OUTCOLUMN, pcsaHeader, &b_nOutColumn );
			}

			pcsaBody->Add("            nCount = screen.getCursor( nOutRow, nOutColumn );" );
			pcsaBody->Add(" " );
		}
		break;

		case 16:		// IScreenUPG::getCursorColumn
		{
			if ( !b_nColumn )
			{
				declareVariable( AG_COLUMN, pcsaHeader, &b_nColumn );			
			}

			pcsaBody->Add("            nColumn = screen.getCursorColumn();" );
			pcsaBody->Add("" );
		}
		break;


		case 17:		// Screen::getCursorRow
		{
			if ( !b_nRow )
			{
				declareVariable( AG_ROW, pcsaHeader, &b_nRow );			
			}

			pcsaBody->Add("            nRow = screen.getCursorRow();" );
			pcsaBody->Add("" );
		}
		break;

		case 18:		// IScreenUPG::getDataCapture
		{
			if ( !b_bRet )
			{
				declareVariable( AG_RETURN, pcsaHeader, &b_bRet );
			}

			pcsaBody->Add("            bRet = screen.getDataCapture();" );
			pcsaBody->Add("" );
		}
		break;

		case 19:		// IScreenUPG::getDescription
		{
			if ( !b_nBuffer )
			{
				declareVariable( AG_UTILBUFFER, pcsaHeader, &b_nBuffer );
			}

			pcsaBody->Add("            Buffer = screen.getDescription();" );
			pcsaBody->Add("" );

		}
		break;


		case 20:	// IScreenUPG::getExtPS
		{
			if ( !b_nBuffer )
			{
				declareVariable( AG_UTILBUFFER, pcsaHeader, &b_nBuffer );
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

			csViewOutStuff.Format( "            nRow = %s;", pcsaArguments->GetAt(1) );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "            nColumn = %s;", pcsaArguments->GetAt(2) );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "            nLength = %s;", pcsaArguments->GetAt(3) );
			pcsaBody->Add(csViewOutStuff);


			pcsaBody->Add("            Buffer = screen.getExtPS( nRow, nColumn, nLength );" );
			pcsaBody->Add("" );

		}
		break;


		case 21:	// IScreenUPG::getgetText_Display
		{
			if ( !b_bRet )
			{
				declareVariable( AG_RETURN, pcsaHeader, &b_bRet );
			}

			pcsaBody->Add("            bRet = screen.getgetText_Display();" );
			pcsaBody->Add("" );

		}
		break;


		case 22:	// IScreenUPG::getKeyboardLocked
		{
			if ( !b_bKeyboardLocked )
			{
				declareVariable( AG_KBD_LOCKED, pcsaHeader, &b_bKeyboardLocked );
			}

			pcsaBody->Add("            bKeyboardLocked = screen.getKeyboardLocked();" );
			pcsaBody->Add("");

		}
		break;


		case 23:	// IScreenUPG::getLastError
		{
			if ( !b_nBuffer )
			{
				declareVariable( AG_UTILBUFFER, pcsaHeader, &b_nBuffer );
			}

			pcsaBody->Add("            Buffer = screen.getLastError();" );
			pcsaBody->Add("");

		}
		break;


		case 24:	// IScreenUPG::getMaxDataCaptureLength
		{
			if ( !b_nLength )
			{
				declareVariable( AG_LENGTH, pcsaHeader, &b_nLength );
			}

			pcsaBody->Add("            nLength = screen.getMaxDataCaptureLength();");
			pcsaBody->Add("");


		}
		break;

		case 25:	// IScreenUPG::getObjectVersion
		{
			if ( !b_nValue )
			{
				declareVariable( AG_VALUE, pcsaHeader, &b_nValue );
			}

			pcsaBody->Add("            nValue = screen.getObjectVersion();" );
			pcsaBody->Add("");

		}
		break;


		case 26:	// IScreenUPG::getOIAContents
		{
			if ( !b_nBuffer )
			{
				declareVariable( AG_UTILBUFFER, pcsaHeader, &b_nBuffer );
			}

			pcsaBody->Add("            Buffer = screen.getOIAContents();");
			pcsaBody->Add("");

		}
		break;

		case 27:	// IScreenUPG::getOIAText
		{
			if ( !b_nBuffer )
			{
				declareVariable( AG_UTILBUFFER, pcsaHeader, &b_nBuffer );
			}

			pcsaBody->Add("            Buffer = screen.getOIAText();");
			pcsaBody->Add("");

		}
		break;

		case 28:	// IScreenUPG::getRows
		{
			if ( !b_nCount )
			{
				declareVariable( AG_COUNT, pcsaHeader, &b_nCount );
			}

			pcsaBody->Add("            nCount = screen.getRows();");
			pcsaBody->Add("");

		}
		break;

		case 29:	// IScreenUPG::getScreenType
		{
			if ( !b_nType )
			{
				declareVariable( AG_TYPE, pcsaHeader, &b_nType );
			}

			csViewOutStuff.Format( "            nType = screen.getScreenType( );" );
			pcsaBody->Add(csViewOutStuff);
		}
		break;

		case 30:	// Screen::getString
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

			
			csViewOutStuff.Format( "            nRow = %s;", pcsaArguments->GetAt(1) );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "            nColumn = %s;", pcsaArguments->GetAt(2) );
			pcsaBody->Add(csViewOutStuff);
			

			csViewOutStuff.Format( "            nLength = %s;", pcsaArguments->GetAt(3) );
			pcsaBody->Add(csViewOutStuff);
			
			csViewOutStuff.Format( "            cString = screen.getString( nRow, nColumn, nLength );");
			pcsaBody->Add(csViewOutStuff);


		}
		break;

		case 31:	// IScreenUPG::getStringEx
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

			if ( !b_nEndRow )
			{
				declareVariable( AG_ENDROW, pcsaHeader, &b_nEndRow );			
			}

			if ( !b_nEndColumn )
			{
				declareVariable( AG_ENDCOLUMN, pcsaHeader, &b_nEndColumn );			
			}

			if ( !b_bWrap )
			{
				declareVariable( AG_WRAP, pcsaHeader, &b_bWrap );
			}

			if ( !b_nAttribute )
			{
				declareVariable( AG_ATTRIBUTE, pcsaHeader, &b_nAttribute );
			}

			csViewOutStuff.Format( "            nRow = %s;", pcsaArguments->GetAt(1) );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "            nColumn = %s;", pcsaArguments->GetAt(2) );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "            nEndRow = %s;", pcsaArguments->GetAt(3) );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "            nEndColumn = %s;", pcsaArguments->GetAt(4) );
			pcsaBody->Add(csViewOutStuff);

			if ( -1 != pcsaArguments->GetAt(5).Find( "TRUE" ) )
			{
				csViewOutStuff.Format( "            nWrap = true;" );
			}
			else
			{
				csViewOutStuff.Format( "            nWrap = false;" );
			}
			pcsaBody->Add(csViewOutStuff);

			CString csAttributes;
			int		nAttributeTally = 0;
			csAttributes = pcsaArguments->GetAt(6);

			if ( -1 != csAttributes.Find("SCREENATTR_ANY") )
			{
				nAttributeTally = -1;
			}
			else
			{
				if ( -1 != csAttributes.Find("SCREENATTR_PROTECTED") )
				{
					nAttributeTally+=1;
				}

				if ( -1 != csAttributes.Find("SCREENATTR_UNPROTECTED") )
				{
					nAttributeTally+=2;
				}

				if ( -1 != csAttributes.Find("SCREENATTR_HIDDEN") )
				{
					nAttributeTally+=4;
				}

				if ( -1 != csAttributes.Find("SCREENATTR_VISIBLE") )
				{
					nAttributeTally+=8;
				}

			}
			
			csViewOutStuff.Format( "            nAttribute = %i;", nAttributeTally );
			pcsaBody->Add(csViewOutStuff);

			pcsaBody->Add("" );
			pcsaBody->Add("            cText = screen.getStringEx( nRow, nColumn, nEndRow, nEndColumn," );
			pcsaBody->Add("                                        0, nWrap, nAttribute, 0 );" );
			pcsaBody->Add(" " );

		}
		break;

		case 32:	// Screen::getText
		{
			if ( !b_cText )
			{
				declareVariable( AG_TEXT, pcsaHeader, &b_cText );
			}

			csViewOutStuff.Format( "            cText = screen.getText();");
			pcsaBody->Add(csViewOutStuff);

		}
		break;

		case 33:	// IScreenUPG::isConnected
		{
			if ( !b_bRet )
			{
				declareVariable( AG_RETURN, pcsaHeader, &b_bRet );
			}

			csViewOutStuff.Format( "            bRet = screen.isConnected();");
			pcsaBody->Add(csViewOutStuff);

		}
		break;

		case 34:	// IScreenUPG::isKeyboardLocked
		{
			if ( !b_bKeyboardLocked )
			{
				declareVariable( AG_KBD_LOCKED, pcsaHeader, &b_bKeyboardLocked );
			}

			csViewOutStuff.Format( "            bKeyboardLocked = screen.isKeyboardLocked();");
			pcsaBody->Add(csViewOutStuff);

		}
		break;

		case 35:	// IScreenUPG::Open
		{
			if ( !b_bRet )
			{
				declareVariable( AG_RETURN, pcsaHeader, &b_bRet );
			}

			csViewOutStuff.Format( "            bRet = screen.Open();");
			pcsaBody->Add(csViewOutStuff);

		}
		break;

		case 36:	// Screen::putString
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


			csViewOutStuff.Format( "            cString = %s;", pcsaArguments->GetAt(1) );
			pcsaBody->Add(csViewOutStuff);
			
			csViewOutStuff.Format( "            nRow = %s;", pcsaArguments->GetAt(2) );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "            nColumn = %s;", pcsaArguments->GetAt(3) );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "            try");
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "            {");
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "               nLength = screen.putString( cString, nRow, nColumn );");
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "            }");
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "            catch( Exception e )");
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "            {");
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "               System.out.println( e.getMessage() );");
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "            }");
			pcsaBody->Add(csViewOutStuff);

		}
		break;
	
		case 37:		// IScreenUPG::putStringEx
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

			if ( !b_nEndRow )
			{
				declareVariable( AG_ENDROW, pcsaHeader, &b_nEndRow );			
			}

			if ( !b_nEndColumn )
			{
				declareVariable( AG_ENDCOLUMN, pcsaHeader, &b_nEndColumn );			
			}

			if ( !b_bWrap )
			{
				declareVariable( AG_WRAP, pcsaHeader, &b_bWrap );
			}

			if ( !b_nMode )
			{
				declareVariable( AG_MODE, pcsaHeader, &b_nMode );
			}

			if ( !b_bFill )
			{
				declareVariable( AG_FILL, pcsaHeader, &b_bFill );
			}



			csViewOutStuff.Format( "            cString = %s;", pcsaArguments->GetAt(1) );
			pcsaBody->Add(csViewOutStuff);
			
			csViewOutStuff.Format( "            nRow = %s;", pcsaArguments->GetAt(2) );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "            nColumn = %s;", pcsaArguments->GetAt(3) );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "            nEndRow = %s;", pcsaArguments->GetAt(4) );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "            nEndColumn = %s;", pcsaArguments->GetAt(5) );
			pcsaBody->Add(csViewOutStuff);

			if ( -1 != pcsaArguments->GetAt(6).Find( "TRUE" ) )
			{
				pcsaBody->Add("            nWrap = true;" );
			}
			else
			{
				pcsaBody->Add("            nWrap = false;" );
			}

			CString csModes;
			int		nModeValue = 2;	// let this be the default
			csModes = pcsaArguments->GetAt(7);

			if ( -1 != csModes.Find("PUTSTRING_SKIP") )
			{
				nModeValue=2;
			}
			else if ( -1 != csModes.Find("PUTSTRING_SPAN") )
			{
				nModeValue=1;
			}
			else if ( -1 != csModes.Find("PUTSTRING_STOP") )
			{
				nModeValue=0;
			}

			csViewOutStuff.Format( "            nMode = %i;", nModeValue );
			pcsaBody->Add(csViewOutStuff);

			if ( -1 != pcsaArguments->GetAt(8).Find( "TRUE" ) )
			{
				pcsaBody->Add("            bFill = true;" );
			}
			else
			{
				pcsaBody->Add("            bFill = false;" );
			}
			pcsaBody->Add("");

			pcsaBody->Add("            try");
			pcsaBody->Add("            {");
			pcsaBody->Add("               nLength = screen.putStringEx( cString, nRow, nColumn, nEndRow, nEndColumn, 0, nWrap, nMode, bFill );");
			pcsaBody->Add("            }");
			pcsaBody->Add("            catch( Exception e )");
			pcsaBody->Add("            {");
			pcsaBody->Add("               System.out.println( e.getMessage() );");
			pcsaBody->Add("            }");
			pcsaBody->Add("");

		}
		break;

		case 38:		// IScreenUPG::removeIScreenListener
		{
			if ( !b_slScreenListener )
			{
				declareVariable( AG_SCREEN_LISTENER, pcsaHeader, &b_slScreenListener );
			}

			pcsaBody->Add("            screen.removeIScreenListener( slScreenListener );" );
		}
		break;

		case 39:		// IScreenUPG.sendkeys
		{
			if ( !b_cText )
			{
				declareVariable( AG_TEXT, pcsaHeader, &b_cText );
			}

			if ( !b_nType )
			{
				declareVariable( AG_TYPE, pcsaHeader, &b_nType );
			}

			csViewOutStuff.Format( "            cText = \"%s\";", pcsaArguments->GetAt(1) );
			pcsaBody->Add(csViewOutStuff);

			CString csType;
			int		nTypeValue = 65536;	// let braces be the default
			csType = pcsaArguments->GetAt(2);

			if ( -1 != csType.Find("KEYTYPE_HLLAPI") )
			{
				nTypeValue=131072;
			}
			else if ( -1 != csType.Find("KEYTYPE_BRACES") )
			{
				nTypeValue=65536;
			}

			csViewOutStuff.Format( "            nType = %i;", nTypeValue );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( " " );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "            screen.sendkeys( cText, nType );" );
			pcsaBody->Add(csViewOutStuff);
		}
		break;

		case 40:	// IScreenUPG::setCursor
		{
			if ( !b_nRow )
			{
				declareVariable( AG_ROW, pcsaHeader, &b_nRow );
			}

			if ( !b_nColumn )
			{
				declareVariable( AG_COLUMN, pcsaHeader, &b_nColumn );			
			}

			csViewOutStuff.Format( "            nRow = %s;", pcsaArguments->GetAt(1) );
			pcsaBody->Add(csViewOutStuff);
			csViewOutStuff.Format( "            nColumn = %s;", pcsaArguments->GetAt(2) );
			pcsaBody->Add(csViewOutStuff);

			pcsaBody->Add(" " );
			pcsaBody->Add("            try" );
			pcsaBody->Add("            {" );
			pcsaBody->Add("               screen.setCursor( nRow, nColumn );");
			pcsaBody->Add("            }" );
			pcsaBody->Add("            catch (e)" );
			pcsaBody->Add("            {" );
			pcsaBody->Add("               System.out.println( e.getMessage() );");
			pcsaBody->Add("            }" );
			pcsaBody->Add(" " );


		}
		break;

		case 41:	// IScreenUPG::setCursorColumn
		{
			if ( !b_nColumn )
			{
				declareVariable( AG_COLUMN, pcsaHeader, &b_nColumn );			
			}

			csViewOutStuff.Format( "            nColumn = %s;", pcsaArguments->GetAt(1) );
			pcsaBody->Add(csViewOutStuff);

			pcsaBody->Add(" " );
			pcsaBody->Add("            try" );
			pcsaBody->Add("            {" );
			pcsaBody->Add("               screen.setCursorColumn( nColumn );");
			pcsaBody->Add("            }" );
			pcsaBody->Add("            catch (e)" );
			pcsaBody->Add("            {" );
			pcsaBody->Add("               System.out.println( e.getMessage() );");
			pcsaBody->Add("            }" );
			pcsaBody->Add(" " );

		}
		break;

		case 42:	// IScreenUPG::setCursorRow
		{
			if ( !b_nRow )
			{
				declareVariable( AG_ROW, pcsaHeader, &b_nRow );
			}

			csViewOutStuff.Format( "            nRow = %s;", pcsaArguments->GetAt(1) );
			pcsaBody->Add(csViewOutStuff);

			pcsaBody->Add(" " );
			pcsaBody->Add("            try" );
			pcsaBody->Add("            {" );
			pcsaBody->Add("               screen.setCursorRow( nRow );");
			pcsaBody->Add("            }" );
			pcsaBody->Add("            catch (e)" );
			pcsaBody->Add("            {" );
			pcsaBody->Add("               System.out.println( e.getMessage() );");
			pcsaBody->Add("            }" );
			pcsaBody->Add(" " );

		}
		break;

		case 43:	// IScreenUPG::setDataCapture
		{
			if ( !b_bCaptureData )
			{
				declareVariable( AG_DATA_CAPTURE, pcsaHeader, &b_bCaptureData );
			}

			if ( -1 != pcsaArguments->GetAt(1).Find( "TRUE" ) )
			{
				pcsaBody->Add("            bCaptureData = true;" );
			}
			else
			{
				pcsaBody->Add("            bCaptureData = false;" );
			}

			pcsaBody->Add("            screen.setDataCapture( bCaptureData );" );
			pcsaBody->Add("");

		}
		break;

		case 44:	// IScreenUPG::setDescription
		{
			if ( !b_nBuffer )
			{
				declareVariable( AG_UTILBUFFER, pcsaHeader, &b_nBuffer );
			}

			csViewOutStuff.Format( "            Buffer = \"%s\";", pcsaArguments->GetAt(1) );
			pcsaBody->Add(csViewOutStuff);

			pcsaBody->Add("            screen.setDescription( Buffer );");
			pcsaBody->Add("");

		}
		break;
		
		case 45:		// IScreenUPG::setgetText_Display
{
			if ( !b_bTextDisplay )
			{
				declareVariable( AG_TEXT_DISPLAY, pcsaHeader, &b_bTextDisplay );
			}

			if ( -1 != pcsaArguments->GetAt(1).Find( "TRUE" ) )
			{
				pcsaBody->Add("            bTextDisplay = true;" );
			}
			else
			{
				pcsaBody->Add("            bTextDisplay = false;" );
			}

			pcsaBody->Add("            screen.setgetText_Display( bTextDisplay );" );
			pcsaBody->Add("");

		}
		break;

		case 46:		// IScreenUPG::setMaxDataCaptureLength
		{
			if ( !b_nBufferSize )
			{
				declareVariable( AG_BUFFER_SIZE, pcsaHeader, &b_nBufferSize );
			}

			csViewOutStuff.Format( "            nBufferSize = %s;", pcsaArguments->GetAt(1) );
			pcsaBody->Add(csViewOutStuff);

			pcsaBody->Add("            screen.setMaxDataCaptureLength( nBufferSize );" );
			pcsaBody->Add("");

		}
		break;

		case 47:		// IScreenUPG::waitForCursor
		{
			if ( !b_nRow )
			{
				declareVariable( AG_ROW, pcsaHeader, &b_nRow );
			}

			if ( !b_nColumn )
			{
				declareVariable( AG_COLUMN, pcsaHeader, &b_nColumn );			
			}

			if ( !b_nTimeout )
			{
				declareVariable( AG_TIMEOUT, pcsaHeader, &b_nTimeout );			
			}

			csViewOutStuff.Format( "            nRow = %s;", pcsaArguments->GetAt(1) );
			pcsaBody->Add(csViewOutStuff);
			csViewOutStuff.Format( "            nColumn = %s;", pcsaArguments->GetAt(2) );
			pcsaBody->Add(csViewOutStuff);
			csViewOutStuff.Format( "            nTimeout = %s;", pcsaArguments->GetAt(3) );
			pcsaBody->Add(csViewOutStuff);

			pcsaBody->Add("" );
			pcsaBody->Add("            try" );
			pcsaBody->Add("            {" );
			pcsaBody->Add("               screen.waitForCursor( nRow, nColumn, nTimeout );");
			pcsaBody->Add("            }" );
			pcsaBody->Add("            catch (e)" );
			pcsaBody->Add("            {" );
			pcsaBody->Add("               System.out.println( e.getMessage() );");
			pcsaBody->Add("            }" );
			pcsaBody->Add("" );

		}
		break;

		case 48:		// IScreenUPG::waitForString
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

			csViewOutStuff.Format( "            cText = \"%s\";", pcsaArguments->GetAt(1) );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "            nRow = %s;", pcsaArguments->GetAt(2) );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "            nColumn = %s;", pcsaArguments->GetAt(3) );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "            nWait = %s;", pcsaArguments->GetAt(4) );
			pcsaBody->Add(csViewOutStuff);

			pcsaBody->Add("" );
			pcsaBody->Add("            try" );
			pcsaBody->Add("            {" );
			pcsaBody->Add("               screen.waitForString( cText, nRow, nColumn, nWait );");
			pcsaBody->Add("            }" );
			pcsaBody->Add("            catch (e)" );
			pcsaBody->Add("            {" );
			pcsaBody->Add("               System.out.println( e.getMessage() );");
			pcsaBody->Add("            }" );
			pcsaBody->Add("" );

		}
		break;


		case 49:		// IScreenUPG::waitHostQuiet
		{
			if ( !b_nWait )
			{
				declareVariable( AG_WAIT, pcsaHeader, &b_nWait );
			}

			if ( !b_nSettleTime )
			{
				declareVariable( AG_SETTLE_TIME, pcsaHeader, &b_nSettleTime );
			}

			csViewOutStuff.Format( "            nWait = %s;", pcsaArguments->GetAt(1) );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "            nSettleTime = %s;", pcsaArguments->GetAt(2) );
			pcsaBody->Add(csViewOutStuff);

			pcsaBody->Add("" );
			pcsaBody->Add("            try" );
			pcsaBody->Add("            {" );
			pcsaBody->Add("               screen.waitHostQuiet( nWait, nSettleTime );");
			pcsaBody->Add("            }" );
			pcsaBody->Add("            catch (e)" );
			pcsaBody->Add("            {" );
			pcsaBody->Add("               System.out.println( e.getMessage() );");
			pcsaBody->Add("            }" );
			pcsaBody->Add("" );
		}
		break;


		case 50:	// MutableInt()
		{
			if ( !b_miVariable1 )
			{
				declareVariable( AG_MUTABLE1, pcsaHeader, &b_miVariable1 );
			}
		}
		break;

		case 51:	// MutableInt(int)
		{
			if ( !b_miVariable2 )
			{
				csViewOutStuff.Format( "            MutableInt miVariable2 = new MutableInt( %s );", pcsaArguments->GetAt(1) );
				pcsaHeader->Add(csViewOutStuff);
				b_miVariable2=TRUE;
			}
		}
		break;


		case 52:	// SessionLoader::getConfigurationIPAddress
		{
			if ( !b_nBuffer )
			{
				declareVariable( AG_UTILBUFFER, pcsaHeader, &b_nBuffer );
			}
			pcsaBody->Add("            Buffer = sessLoader.getConfigurationIPAddress();");
			pcsaBody->Add("");
		}
		break;


		case 53:	// SessionLoader::getTerminalType
		{
			if ( !b_nType )
			{
				declareVariable( AG_TYPE, pcsaHeader, &b_nType );
			}
			pcsaBody->Add("            nType = sessLoader.getTerminalType( );" );
			pcsaBody->Add("");
		}
		break;

		
		case 54:	// SessionLoader::requestScreen
		{
				if ( !b_csUserID )
				{
					declareVariable( AG_USER_ID, pcsaHeader, &b_csUserID );
				}

				if ( !b_csPassword )
				{
					declareVariable( AG_PASSWORD, pcsaHeader, &b_csPassword );
				}

				if ( !b_csWebView )
				{
					declareVariable( AG_WEBVIEW_NAME, pcsaHeader, &b_csWebView );
				}

				if ( !b_isUPG )
				{
					declareVariable( AG_UPG_SCREEN, pcsaHeader, &b_isUPG );
				}


				csViewOutStuff.Format( "            csUserID = \"%s\";", pcsaArguments->GetAt(1) );
				pcsaBody->Add(csViewOutStuff);

				csViewOutStuff.Format( "            csPassword = \"%s\";", pcsaArguments->GetAt(2) );
				pcsaBody->Add(csViewOutStuff);

				csViewOutStuff.Format( "            csWebView = \"%s\";", pcsaArguments->GetAt(3) );
				pcsaBody->Add(csViewOutStuff);

				pcsaBody->Add("");

				csViewOutStuff.Format( "            try");
				pcsaBody->Add(csViewOutStuff);

				csViewOutStuff.Format( "            {");
				pcsaBody->Add(csViewOutStuff);

				csViewOutStuff.Format( "               isUPG = (ScreenUts) sessLoader.requestScreen( csUserID, csPassword, csWebView );");
				pcsaBody->Add(csViewOutStuff);

				csViewOutStuff.Format( "            }");
				pcsaBody->Add(csViewOutStuff);

				csViewOutStuff.Format( "            catch (e)");
				pcsaBody->Add(csViewOutStuff);

				csViewOutStuff.Format( "            {");
				pcsaBody->Add(csViewOutStuff);

				csViewOutStuff.Format( "               System.out.println( e.getMessage() );");
				pcsaBody->Add(csViewOutStuff);

				csViewOutStuff.Format( "            }");
				pcsaBody->Add(csViewOutStuff);

				csViewOutStuff.Format( "");
				pcsaBody->Add(csViewOutStuff);
				

		}
		break;


		case 55:	// SessionLoader::requestScreenEx
		{
				if ( !b_csUserID )
				{
					declareVariable( AG_USER_ID, pcsaHeader, &b_csUserID );
				}

				if ( !b_csPassword )
				{
					declareVariable( AG_PASSWORD, pcsaHeader, &b_csPassword );
				}

				if ( !b_csWebView )
				{
					declareVariable( AG_WEBVIEW_NAME, pcsaHeader, &b_csWebView );
				}

				if ( !b_isUPG )
				{
					declareVariable( AG_UPG_SCREEN, pcsaHeader, &b_isUPG );
				}


				csViewOutStuff.Format( "            csUserID = \"%s\";", pcsaArguments->GetAt(1) );
				pcsaBody->Add(csViewOutStuff);

				csViewOutStuff.Format( "            csPassword = \"%s\";", pcsaArguments->GetAt(2) );
				pcsaBody->Add(csViewOutStuff);

				csViewOutStuff.Format( "            csWebView = \"%s\";", pcsaArguments->GetAt(3) );
				pcsaBody->Add(csViewOutStuff);

				pcsaBody->Add("");

				csViewOutStuff.Format( "            try");
				pcsaBody->Add(csViewOutStuff);

				csViewOutStuff.Format( "            {");
				pcsaBody->Add(csViewOutStuff);

				csViewOutStuff.Format( "               isUPG = (ScreenUts) sessLoader.requestScreenEx( csUserID, csPassword, csWebView, 0 );");
				pcsaBody->Add(csViewOutStuff);

				csViewOutStuff.Format( "            }");
				pcsaBody->Add(csViewOutStuff);

				csViewOutStuff.Format( "            catch (e)");
				pcsaBody->Add(csViewOutStuff);

				csViewOutStuff.Format( "            {");
				pcsaBody->Add(csViewOutStuff);

				csViewOutStuff.Format( "               System.out.println( e.getMessage() );");
				pcsaBody->Add(csViewOutStuff);

				csViewOutStuff.Format( "            }");
				pcsaBody->Add(csViewOutStuff);

				csViewOutStuff.Format( "");
				pcsaBody->Add(csViewOutStuff);
				

		}
		break;


		case 56:	// SessionLoader::setConfigurationIPAddress
		{
			if ( !b_csServer )
			{
				declareVariable( AG_SERVER, pcsaHeader, &b_csServer );
			}

			csViewOutStuff.Format( "            csServer = \"%s\";", pcsaArguments->GetAt(1) );
			pcsaBody->Add(csViewOutStuff);

			pcsaBody->Add("            sessLoader.setConfigurationIPAddress( csServer );" );
			pcsaBody->Add("");

		}
		break;

		case 57:	// SessionLoader::setResourceManagerOptions
		{
				if ( !b_nIDCount )
				{
					declareVariable( AG_ID_COUNT, pcsaHeader, &b_nIDCount );
				}

				if ( !b_nIDIncrement )
				{
					declareVariable( AG_ID_INCREMENT, pcsaHeader, &b_nIDIncrement );
				}

				if ( !b_csIDManagerAddress )
				{
					declareVariable( AG_IDMGR_ADDRESS, pcsaHeader, &b_csIDManagerAddress );
				}


				csViewOutStuff.Format( "            nIDCount = %s;", pcsaArguments->GetAt(1) );
				pcsaBody->Add(csViewOutStuff);

				csViewOutStuff.Format( "            nIDIncrement = %s;", pcsaArguments->GetAt(2) );
				pcsaBody->Add(csViewOutStuff);

				csViewOutStuff.Format( "            csIDManagerAddress = \"%s\";", pcsaArguments->GetAt(3) );
				pcsaBody->Add(csViewOutStuff);

				pcsaBody->Add("");
				pcsaBody->Add("            sessLoader.setResourceManagerOptions( nIDCount, nIDIncrement, csIDManagerAddress );");
				pcsaBody->Add("");

		}
		break;

		
		case 58:	// SessionLoader::setTerminalType
		{
			if ( !b_nType )
			{
				declareVariable( AG_TYPE, pcsaHeader, &b_nType );
			}

			if ( -1 != pcsaArguments->GetAt(1).Find( "T27" ) )
			{
				csViewOutStuff.Format( "            nType = 100; //T27" );
			}
			else if ( -1 != pcsaArguments->GetAt(1).Find( "UTS" ) )
			{
				csViewOutStuff.Format( "            nType = 105; //UTS" );
			}
			else if ( -1 != pcsaArguments->GetAt(1).Find( "VT" ) )
			{
				csViewOutStuff.Format( "            nType = 110; //VT" );
			}
			else if ( -1 != pcsaArguments->GetAt(1).Find( "VT" ) )
			{
				csViewOutStuff.Format( "            nType = 115; //VT" );
			}
			else if ( -1 != pcsaArguments->GetAt(1).Find( "VT" ) )
			{
				csViewOutStuff.Format( "            nType = 120; //VT" );
			}
			else if ( -1 != pcsaArguments->GetAt(1).Find( "ALC" ) )
			{
				csViewOutStuff.Format( "            nType = 125; //ALC" );
			}
			else
			{
				csViewOutStuff.Format( "            nType = 110; //VT" );
			}
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "            session.setTerminalType( nType );");
			pcsaBody->Add(csViewOutStuff);
		}
		break;

		case 59:	// SessionLoader::Shutdown
		{
			pcsaBody->Add("            sessLoader.Shutdown();");
			pcsaBody->Add("");
		}
		break;

	}

	pcsaArguments->RemoveAll();
}


void CAG_AIR_VT_J_J::finalize(CStringArray* pcsaBody)
{
	CString csViewOutStuff;

	csViewOutStuff.Format( "" );
	pcsaBody->Add(csViewOutStuff);

	csViewOutStuff.Format( "         }" );
	pcsaBody->Add(csViewOutStuff);

	csViewOutStuff.Format( "" );
	pcsaBody->Add(csViewOutStuff);

	csViewOutStuff.Format( "      }" );
	pcsaBody->Add(csViewOutStuff);

	csViewOutStuff.Format( "      catch(Exception e)" );
	pcsaBody->Add(csViewOutStuff);

	csViewOutStuff.Format( "      {" );
	pcsaBody->Add(csViewOutStuff);

	csViewOutStuff.Format( "          System.out.println( e.getMessage() );");
	pcsaBody->Add(csViewOutStuff);

	csViewOutStuff.Format( "      }" );
	pcsaBody->Add(csViewOutStuff);

	csViewOutStuff.Format( "" );
	pcsaBody->Add(csViewOutStuff);

	csViewOutStuff.Format( "   }" );
	pcsaBody->Add(csViewOutStuff);

	csViewOutStuff.Format( "" );
	pcsaBody->Add(csViewOutStuff);

	csViewOutStuff.Format( "}" );
	pcsaBody->Add(csViewOutStuff);

	b_Debug = FALSE;
}



/****************************************************************************DC
	Function	:	CAG_AIR_VT_J_J::declareVariable()

	Purpose		:	Append variable declarations to the end of the header as 
					needed.

*****************************************************************************/
void CAG_AIR_VT_J_J::declareVariable(AG_VARIABLE agVariable,
									   CStringArray* pcsaHeader,
									   bool* bValue)
{
	CString csLocal;
	*bValue = TRUE;
	
	switch ( agVariable )
	{
		case AG_STATUS:
		{
			csLocal.Format( "            int nStatus=0;");
		}
		break;

		case AG_DIRECTION:
		{
			csLocal.Format( "            int nDirection=0;");
		}
		break;

		case AG_UPDATED:
		{
			csLocal.Format( "            boolean bUpdated=false;");
		}
		break;

		case AG_UTILBUFFER:
		{
			csLocal.Format( "            String Buffer=\" \";");
		}
		break;

		case AG_ROW:
		{
			csLocal.Format( "            int nRow=0;");
		}
		break;

		case AG_ENDROW:
		{
			csLocal.Format( "            int nEndRow=0;");
		}
		break;

		case AG_COLUMN:
		{
			csLocal.Format( "            int nColumn=0;");		
		}
		break;

	
		case AG_ENDCOLUMN:
		{
			csLocal.Format( "            int nEndColumn=0;");		
		}
		break;


		case AG_ATTRIBUTE:
		{
			csLocal.Format( "            int nAttribute=0;");
		}
		break;

		case AG_LENGTH:
		{
			csLocal.Format( "            int nLength=0;");
		}
		break;

		case AG_VALUE:
		{
			csLocal.Format( "            int nValue=0;");
		}
		break;

		case AG_RETURN:
		{
			csLocal.Format( "            boolean bRet=false;");
		}
		break;

		case AG_CLOSEOPTION:
		{
			csLocal.Format( "            int nCloseOption=0;");
		}
		break;

		case AG_HOST_OS:
		{
			csLocal.Format( "            int nFTHostOS=0;");
		}
		break;

		case AG_HEIGHT:
		{
			csLocal.Format( "            int nHeight=0;");
		}
		break;

		case AG_LOCALMODE:
		{
			csLocal.Format( "            boolean bLocalMode=false;");
		}
		break;

		case AG_SESS_SAVED:
		{
			csLocal.Format( "            boolean bSessionSaved=false;");
		}
		break;

		case AG_SESSIONS_CREATED:
		{
			csLocal.Format( "            String Sessions[];" );
		}
		break;

		case AG_SESS_OPEN:
		{
			csLocal.Format( "            String SessName=\" \";");
		}
		break;


		case AG_SETTLE_TIME:
		{
			csLocal.Format( "            int nSettleTime=0;");
		}
		break;

		case AG_SESS_QUIET:
		{
			csLocal.Format( "            boolean bSessionQuiet=false;");
		}
		break;

		case AG_MENU_VISIBLE:
		{
			csLocal.Format( "            boolean bMenuVisible=false;");
		}
		break;

		case AG_TYPE:
		{
			csLocal.Format( "            int nType=0;");
		}
		break;

		case AG_TIMEOUT:
		{
			csLocal.Format( "            int nTimeout=0;");
		}
		break;

		case AG_PROCESS_KEYSTROKES:
		{
			csLocal.Format( "            boolean bProcessKeystrokes=false;");
		}
		break;

		case AG_WIDTH:
		{
			csLocal.Format( "            int nWidth=0;");
		}
		break;

		case AG_WINDOW_HANDLE:
		{
			csLocal.Format( "            int hSession=0;");
			//csLocal.Format( "   HANDLE hSession=NULL;");
		}
		break;

		case AG_WINDOW_STATE:
		{
			csLocal.Format( "            int nWindowState=0;");
		}
		break;

		case AG_COUNT:
		{
			csLocal.Format( "            int nCount=0;");
		}
		break;

		case AG_AREA:
		{
			csLocal.Format( "            //String Area=\" \";");
		}
		break;

		// new stuff
		case AG_NAME:
		{
			csLocal.Format( "            String csName=\" \";" );
		}
		break;

		case AG_SCREEN_LISTENER:
		{
			csLocal.Format( "            IScreenListener isl;" );
		}
		break;

		case AG_TERMINAL:
		{
			csLocal.Format( "            //Terminal;" );
		}
		break;

		case AG_OIAOBJ:
		{
			csLocal.Format( "            OiaVT OIAObj;" );
		}
		break;

		case AG_TEXT:
		{
			csLocal.Format( "            String cText=\" \";" );
		}
		break;

		case AG_EAB:
		{
			csLocal.Format( "            boolean bEABs=false;" );
		}
		break;

		case AG_HOST_CHARSET:
		{
			csLocal.Format( "            int nCharSet=0;" );
		}
		break;

		case AG_HOST_CODEPAGE:
		{
			csLocal.Format( "            int nHostCodePage=0;" );
		}
		break;

		case AG_INDEX:
		{
			csLocal.Format( "            int nIndex=0;" );
		}
		break;

		case AG_KBD_LOCKED:
		{
			csLocal.Format( "            boolean bKeyboardLocked=false;" );
		}
		break;

		case AG_MODEL:	
		{
			csLocal.Format( "            int nModel=0;" );
		}
		break;

		case AG_STRING:
		{
			csLocal.Format( "            String cString=\" \";" );
		}
		break;

		case AG_MODE:
		{
			csLocal.Format( "            int nMode=0;" );
		}
		break;

		case AG_WAIT:
		{
			csLocal.Format( "            int nWait=0;" );
		}
		break;

		case AG_ATTACHED:
		{
			csLocal.Format( "            boolean bAttached=false;" );
		}
		break;

		case AG_CONNECTED:
		{
			csLocal.Format( "            boolean bConnected=false;" );
		}
		break;

		case AG_CONNECTION_OBJ:
		{
			csLocal.Format( "            ConTNVT conn;" );
		}
		break;

		case AG_SCREEN_OBJ:
		{
			csLocal.Format( "            ScreenVT screen;" );
		}
		break;

		case AG_STATE:
		{
			csLocal.Format( "            int nState=0;" );
		}
		break;

		case AG_PORT:
		{
			csLocal.Format( "            int nPort=0;" );
		}
		break;

		case AG_WRAP:
		{
			csLocal.Format( "            bool bWrap=false;" );
		}
		break;

		case AG_OUTROW:
		{
			csLocal.Format( "            MutableInt nOutRow = new MutableInt(0);" );
		}
		break;

		case AG_OUTCOLUMN:
		{
			csLocal.Format( "            MutableInt nOutColumn = new MutableInt(0);" );
		}
		break;

		case AG_OUTLENGTH:
		{
			csLocal.Format( "            MutableInt nOutLength = new MutableInt(0);" );
		}
		break;

		case AG_OUTATTRIBUTE:
		{
			csLocal.Format( "            MutableInt nOutAttribute = new MutableInt(0);" );
		}
		break;

		case AG_FILL:
		{
			csLocal.Format( "            bool bFill=false;" );
		}
		break;

		case AG_DATA_CAPTURE:
		{
			csLocal.Format( "            bool bCaptureData=false;" );
		}
		break;

		case AG_TEXT_DISPLAY:
		{
			csLocal.Format( "            bool bTextDisplay=false;" );
		}
		break;

		case AG_BUFFER_SIZE:
		{
			csLocal.Format( "            int nBufferSize=0;" );
		}
		break;

		case AG_MUTABLE1:
		{
			csLocal.Format( "            MutableInt miVariable1 = new MutableInt(0);" );
		}
		break;

		case AG_USER_ID:
		{
			csLocal.Format( "            String csUserID=\"\";");
		}
		break;

		case AG_PASSWORD:
		{
			csLocal.Format( "            String csPassword=\"\";");
		}
		break;

		case AG_WEBVIEW_NAME:
		{
			csLocal.Format( "            String csWebView=\"\";");
		}
		break;

		case AG_UPG_SCREEN:
		{
			csLocal.Format( "            ScreenUts isUPG;");
		}
		break;

		case AG_SERVER:	
		{
			csLocal.Format( "            String csServer=\"\";" );
		}
		break;
			
		case AG_ID_COUNT:	
		{
			csLocal.Format( "            int nIDCount;" );
		}
		break;
			
		case AG_ID_INCREMENT:	
		{
			csLocal.Format( "            int nIDIncrement;" );
		}
		break;
			
		case AG_IDMGR_ADDRESS:	
		{
			csLocal.Format( "            String csIDManagerAddress;" );
		}
		break;
			
	}

	pcsaHeader->Add(csLocal);

}


void CAG_AIR_VT_J_J::checkDebug(bool b_Debug,
								  CString csFunctionName,
								  CStringArray* pcsaBody)
{
	
}


void CAG_AIR_VT_J_J::resetVariableFlags()
{
	b_bCaptureData = FALSE;
	b_bRet = FALSE;
	b_bTextDisplay = FALSE;
	b_isUPG = FALSE;
	b_csPassword = FALSE;
	b_csUserID = FALSE;
	b_csWebView = FALSE;
	b_pOIAObject = FALSE;
	b_nAttribute = FALSE;
	b_nIDCount = FALSE;
	b_nIDIncrement = FALSE;
	b_csIDManagerAddress = FALSE;
	b_nStatus = FALSE;
	b_nTimeout = FALSE;
	b_nType = FALSE;
	b_cText = FALSE;
	b_nCount = FALSE;
	b_nColumn = FALSE;
	b_nRow = FALSE;
	b_bEABs = FALSE;
	b_bFill = FALSE;
	b_miVariable1 = FALSE;
	b_miVariable2 = FALSE;
	b_nBuffer = FALSE;
	b_nBufferSize = FALSE;
	b_nDirection = FALSE;
	b_nEndColumn = FALSE;
	b_nEndRow = FALSE;
	b_nCharSet = FALSE;
	b_nHostCodePage = FALSE;
	b_nIndex = FALSE;
	b_bKeyboardLocked = FALSE;
	b_nModel = FALSE;
	b_nLength = FALSE;
	b_nOutAttribute = FALSE;
	b_nOutColumn = FALSE;
	b_nOutLength = FALSE;
	b_nOutRow = FALSE;
	b_nSettleTime = FALSE;
	b_nValue = FALSE;
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
	b_slScreenListener=FALSE;
	b_bWrap=FALSE;

	b_Debug=FALSE;

}
