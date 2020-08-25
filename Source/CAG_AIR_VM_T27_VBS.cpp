// Static Model
#include "stdafx.h"
#include "apigen.h"

#include "CAG_AIR_VM_T27_VBS.h"
#include "time.h"


CAG_AIR_VM_T27_VBS::CAG_AIR_VM_T27_VBS()
{
	resetVariableFlags();
}


CAG_AIR_VM_T27_VBS::~CAG_AIR_VM_T27_VBS()
{
	
}




void CAG_AIR_VM_T27_VBS::generateHeader(CStringArray* pcsaHeader,
									  CStringArray* pcsaBody)
{
	CString csHostNameString, csHostT27StationID;
	if (IDOK == AirT27HostnameDlg.DoModal())
	{
		csHostNameString = AirT27HostnameDlg.csEditT27HostAddress;
		if ( 0 == csHostNameString.GetLength() )
		{
			csHostNameString = "SomeT27Host";
		}

		csHostT27StationID = AirT27HostnameDlg.csEditT27StationID;
		if ( 0 == csHostT27StationID.GetLength() )
		{
			csHostT27StationID = "WKRP_Cincinnati";
		}

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
	pcsaHeader->Add("<script language=\"VBScript\">");
	pcsaHeader->Add("' ****************************************************************************");
	pcsaHeader->Add("'                     Attachmate T27 ViewMaster");
	pcsaHeader->Add("'                     APIGen VBScript Application");
	pcsaHeader->Add("'");
	pcsaHeader->Add("'   This is a freestanding HTML file that will load an Express Viewer and run the");
	pcsaHeader->Add("'   set of Java interface method calls specified to the APIGen code generator.");
	pcsaHeader->Add("'");
	pcsaHeader->Add("'    To run the T27 Express Viewer session configured and automated in this file");
	pcsaHeader->Add("'    you need to have XXX installed and then simply double-click on this file.");

	time_t ltime;
	time( &ltime );

	pcsaHeader->Add("'");

	csViewOutStuff.Format( "'   Generated:   %s", ctime( &ltime ) );
	pcsaHeader->Add(csViewOutStuff);
	pcsaHeader->Add("'");
	pcsaHeader->Add("' ****************************************************************************");
	pcsaHeader->Add("");

	pcsaHeader->Add("</script>");

	pcsaHeader->Add("<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 3.2 Final//EN\">");

	pcsaHeader->Add("<HTML>");
	pcsaHeader->Add("<HEAD>");
	pcsaHeader->Add("<TITLE>Attachmate e-Vantage ViewMaster");
	pcsaHeader->Add("</TITLE>");
	pcsaHeader->Add("</HEAD>");
	pcsaHeader->Add("<BODY bgColor=white vLink=red text=blue Link=olive>");
	pcsaHeader->Add("<FONT face=\"Microsoft Sans Serif\" size=2>");
	pcsaHeader->Add("");
	pcsaHeader->Add("<APPLET");
	pcsaHeader->Add("   codebase=\"T27\"");
	pcsaHeader->Add("   MAYSCRIPT");
	pcsaHeader->Add("   code=\"com.attachmate.cin.frame.AtmApplet\"");
	pcsaHeader->Add("   id=\"myAppletID\"");
	pcsaHeader->Add("   name=\"myAppletID\"");
	pcsaHeader->Add("   width=\"720\"");
	pcsaHeader->Add("   height=\"480\"");
	pcsaHeader->Add("   archive=\"T27.jar\" VIEWASTEXT>");
	pcsaHeader->Add("   <PARAM name=\"Pages\" value=\"2\">");
	pcsaHeader->Add("   <PARAM name=\"Rows\" value=\"24\">");
	pcsaHeader->Add("   <PARAM name=\"Columns\"  value=\"80\">");
	pcsaHeader->Add("   <PARAM name=\"Cabbase\" value=\"t27.cab\">");
	pcsaHeader->Add("   <PARAM name=\"HostType\" value=\"T27\">");
	pcsaHeader->Add("   <PARAM name=\"LowerCase\" value=\"TRUE\">");
	pcsaHeader->Add("   <PARAM name=\"SpecialScroll\" value=\"FALSE\">");
	pcsaHeader->Add("   <PARAM name=\"SafePaste\" value=\"FALSE\">");
	pcsaHeader->Add("   <PARAM name=\"AlarmLevel\" value=\"TRUE\">");
	pcsaHeader->Add("   <PARAM name=\"ColumnAlarm\" value=\"81\">");
	pcsaHeader->Add("   <PARAM name=\"RowAlarm\" value=\"25\">");
	pcsaHeader->Add("   <PARAM name=\"DC1_Function\" value=\"StayInRcv\">");
	pcsaHeader->Add("   <PARAM name=\"DC2_Function\" value=\"ToggleForms\">");
	pcsaHeader->Add("   <PARAM name=\"RcvModeHold\" value=\"TRUE\">");
	pcsaHeader->Add("   <PARAM name=\"FormXmitToCursor\" value=\"FALSE\">");
	pcsaHeader->Add("   <PARAM name=\"LineAtATimeXmit\" value=\"FALSE\">");
	pcsaHeader->Add("   <PARAM name=\"EnableMobileHome\" value=\"TRUE\">");
	pcsaHeader->Add("   <PARAM name=\"DisplayETX\" value=\"FALSE\">");
	pcsaHeader->Add("   <PARAM name=\"DisplayRcvdCR\" value=\"FALSE\">");
	pcsaHeader->Add("   <PARAM name=\"DisplayRcvdHT\" value=\"FALSE\">");
	pcsaHeader->Add("   <PARAM name=\"CursorBlink\" value=\"TRUE\">");

	csViewOutStuff.Format( "   <PARAM name=\"INetAddress\" value=\"%s\">", csHostNameString );
	pcsaHeader->Add(csViewOutStuff);

	pcsaHeader->Add("   <PARAM name=\"TerminalType\" value=\"Auto Select\">");

	csViewOutStuff.Format( "   <PARAM name=\"StationID\" value=\"%s\">", csHostT27StationID );
	pcsaHeader->Add(csViewOutStuff);

	pcsaHeader->Add("   <PARAM name=\"EnableForcedLines\" value=\"true\">");
	pcsaHeader->Add("   <PARAM name=\"ForcedLineCount\" value=\"60\">");
	pcsaHeader->Add("   <PARAM name=\"POPOUTWINDOW\" value=\"false\">");
	pcsaHeader->Add("   <PARAM name=\"Transport\" value=\"TCPA\">");
	pcsaHeader->Add("   <PARAM name=\"CursorShape\" value=\"Block\">");
	pcsaHeader->Add("   <PARAM name=\"AutoSizeWindow\" value=\"FALSE\">");
	pcsaHeader->Add("   <PARAM name=\"AutoSizeFont\" value=\"TRUE\">");
	pcsaHeader->Add("   <PARAM name=\"SelectionMode\" value=\"Rectangle\">");
	pcsaHeader->Add("   <PARAM name=\"Keymap\" value=\"T27PC.ekm\">");
	pcsaHeader->Add("   <PARAM name=\"XlateFilename\" value=\"\">");
	pcsaHeader->Add("   <PARAM name=\"BlinkText\" value=\"TRUE\">");
	pcsaHeader->Add("   <PARAM name=\"UseTidServer\" value=\"FALSE\">");
	pcsaHeader->Add("</APPLET>");
	pcsaHeader->Add("</CENTER>");
	pcsaHeader->Add("</P>");
	pcsaHeader->Add("");
	pcsaHeader->Add("<INPUT type=button value=\"Run Code\" name=\"runCode\" onclick=\"RunGeneratedCode();\">");
	pcsaHeader->Add("<br>");
	pcsaHeader->Add("");
	pcsaHeader->Add("<script language=\"VBScript\">");
	pcsaHeader->Add("Sub RunGeneratedCode");
	pcsaHeader->Add("{");

	pcsaBody->Add("");

}



void CAG_AIR_VM_T27_VBS::appendBody(int nFunctionNum,
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

	csViewOutStuff.Format( "        ' *** %s", csFunctionName );
	pcsaBody->Add(csViewOutStuff);

	checkDebug( b_Debug, csFunctionName, pcsaBody );

	CString	csLocal;

	switch ( nFunctionNum )
	{
		case 0:		// IScreenUPG::clearCapturedData
		{
			pcsaBody->Add("        if (ScreenT27 != null)");
			pcsaBody->Add("        {");
			pcsaBody->Add("         ScreenT27.clearCapturedData()");
			pcsaBody->Add("        }");
			pcsaBody->Add("" );
		}
		break;

		case 1:		// IScreenUPG::fieldCount
		{
			if ( !b_nCount )
			{
				declareVariable( AG_COUNT, pcsaHeader, &b_nCount );
			}

			int nLocalField=0;
			if ( -1 != pcsaArguments->GetAt(1).Find( "FIELDTYPE_PROTECTED" ) )
			{
				nLocalField=1;
				csViewOutStuff.Format( "        nCount = ScreenT27.fieldCount( %i )  'FIELDTYPE_PROTECTED", nLocalField );
			}
			else if ( -1 != pcsaArguments->GetAt(1).Find( "FIELDTYPE_UNPROTECTED" ) )
			{
				nLocalField=2;
				csViewOutStuff.Format( "        nCount = ScreenT27.fieldCount( %i )  'FIELDTYPE_UNPROTECTED", nLocalField );
			}
			else
			{
				nLocalField=3;
				csViewOutStuff.Format( "        nCount = ScreenT27.fieldCount( %i )  'FIELDTYPE_ANY", nLocalField );
			}
			pcsaBody->Add(csViewOutStuff);
			pcsaBody->Add(" " );
		}
		break;

		case 2:		// IScreenUPG::findField
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

			csViewOutStuff.Format( "        nRow = %s", pcsaArguments->GetAt(1) );
			pcsaBody->Add(csViewOutStuff);
			csViewOutStuff.Format( "        nColumn = %s", pcsaArguments->GetAt(2) );
			pcsaBody->Add(csViewOutStuff);

			int nLocalMode=0;
			if ( -1 != pcsaArguments->GetAt(3).Find( "FINDFIELD_CURRENT" ) )
			{
				nLocalMode=0;
				csViewOutStuff.Format( "        nMode =  %i  'FINDFIELD_CURRENT", nLocalMode );
			}
			else if ( -1 != pcsaArguments->GetAt(3).Find( "FINDFIELD_NEXT" ) )
			{
				nLocalMode=1;
				csViewOutStuff.Format( "        nMode =  %i  'FINDFIELD_NEXT", nLocalMode );
			}
			else
			{
				nLocalMode=2;
				csViewOutStuff.Format( "        nMode =  %i  'FINDFIELD_PREVIOUS", nLocalMode );
			}

			int nLocalField=0;
			if ( -1 != pcsaArguments->GetAt(4).Find( "FIELDTYPE_PROTECTED" ) )
			{
				nLocalField=1;
				csViewOutStuff.Format( "        nType = %i  'FIELDTYPE_PROTECTED", nLocalField );
			}
			else if ( -1 != pcsaArguments->GetAt(4).Find( "FIELDTYPE_UNPROTECTED" ) )
			{
				nLocalField=2;
				csViewOutStuff.Format( "        nType = %i  'FIELDTYPE_UNPROTECTED", nLocalField );
			}
			else
			{
				nLocalField=3;
				csViewOutStuff.Format( "        nType = %i  'FIELDTYPE_ANY", nLocalField );
			}
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "        bWrap = %s", pcsaArguments->GetAt(5) );
			pcsaBody->Add(csViewOutStuff);

			pcsaBody->Add("        bRet = ScreenT27.findField( nRow, nColumn, nMode, nType, bWrap, nOutRow, nOutColumn, nOutLength, nOutAttribute  )" );
			pcsaBody->Add(" " );
		}
		break;

		case 3:	// IScreenUPG::findFieldEx
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

			csViewOutStuff.Format( "        nIndex = %s", pcsaArguments->GetAt(1) );
			pcsaBody->Add(csViewOutStuff);


			int nLocalMode=0;
			if ( -1 != pcsaArguments->GetAt(2).Find( "FINDFIELD_CURRENT" ) )
			{
				nLocalMode=0;
				csViewOutStuff.Format( "        nMode =  %i  'FINDFIELD_CURRENT", nLocalMode );
			}
			else if ( -1 != pcsaArguments->GetAt(2).Find( "FINDFIELD_NEXT" ) )
			{
				nLocalMode=1;
				csViewOutStuff.Format( "        nMode =  %i  'FINDFIELD_NEXT", nLocalMode );
			}
			else
			{
				nLocalMode=2;
				csViewOutStuff.Format( "        nMode =  %i  'FINDFIELD_PREVIOUS", nLocalMode );
			}
			pcsaBody->Add(csViewOutStuff);

			int nLocalField=0;
			if ( -1 != pcsaArguments->GetAt(3).Find( "FIELDTYPE_PROTECTED" ) )
			{
				nLocalField=1;
				csViewOutStuff.Format( "        nType = %i  'FIELDTYPE_PROTECTED", nLocalField );
			}
			else if ( -1 != pcsaArguments->GetAt(3).Find( "FIELDTYPE_UNPROTECTED" ) )
			{
				nLocalField=2;
				csViewOutStuff.Format( "        nType = %i  'FIELDTYPE_UNPROTECTED", nLocalField );
			}
			else
			{
				nLocalField=3;
				csViewOutStuff.Format( "        nType = %i  'FIELDTYPE_ANY", nLocalField );
			}
			pcsaBody->Add(csViewOutStuff);


			if ( -1 != pcsaArguments->GetAt(4).Find( "TRUE" ) )
			{
				pcsaBody->Add("        bWrap = 1   'WRAP_ON" );
			}
			else
			{
				pcsaBody->Add("        bWrap = 0   'WRAP_OFF" );
			}

			pcsaBody->Add("" );
			pcsaBody->Add("        bRet = ScreenT27.findFieldEx( nIndex, nMode, nType, bWrap, nOutRow, nOutColumn, nOutLength, nOutAttribute  )" );
			pcsaBody->Add("" );
		}
		break;


		case 4:	// IScreenUPG::findString
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

			csViewOutStuff.Format( "        cText = \"%s\"", pcsaArguments->GetAt(1) );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "        nRow = %s", pcsaArguments->GetAt(2) );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "        nColumn = %s", pcsaArguments->GetAt(3) );
			pcsaBody->Add(csViewOutStuff);

			pcsaBody->Add("" );
			pcsaBody->Add("        bRet = ScreenT27.findString( cText, nRow, nColumn )" );
			pcsaBody->Add(" " );
		
		}
		break;

		case 5:	// IScreenUPG::findStringEx
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

			csViewOutStuff.Format( "        cText = \"%s\"", pcsaArguments->GetAt(1) );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "        nRow = %s", pcsaArguments->GetAt(2) );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "        nColumn = %s", pcsaArguments->GetAt(3) );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "        nEndRow = %s", pcsaArguments->GetAt(4) );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "        nEndColumn = %s", pcsaArguments->GetAt(5) );
			pcsaBody->Add(csViewOutStuff);

			if ( -1 != pcsaArguments->GetAt(6).Find( "TRUE" ) )
			{
				csViewOutStuff.Format( "        nWrap = 1   'WRAP_ON" );
			}
			else
			{
				csViewOutStuff.Format( "        nWrap = 0   'WRAP_OFF" );
			}
			pcsaBody->Add(csViewOutStuff);

			if ( -1 != pcsaArguments->GetAt(7).Find( "DIRECTION_FORWARD" ) )
			{
				csViewOutStuff.Format( "        nDir = 0   'DIRECTION_FORWARD" );
			}
			else
			{
				csViewOutStuff.Format( "        nDir = 4   'DIRECTION_BACKWARD" );
			}
			pcsaBody->Add(csViewOutStuff);

			pcsaBody->Add("" );
			pcsaBody->Add("        bRet = ScreenT27.findStringEx( cText, nRow, nColumn, nEndRow, nEndColumn, 0, nWrap, nDir )" );
			pcsaBody->Add(" " );

		}
		break;

		case 6:	// IScreenUPG::focusTerminal
		{
			pcsaBody->Add("        ScreenT27.focusTerminal()" );
			pcsaBody->Add(" " );
		}
		break;

		case 7:	// IScreenUPG::getCapturedData
		{
			if ( !b_nBuffer )
			{
				declareVariable( AG_UTILBUFFER, pcsaHeader, &b_nBuffer );
			}

			pcsaBody->Add("        Buffer = ScreenT27.getCapturedData()" );
			pcsaBody->Add(" " );

		}
		break;

		case 8:	// IScreenUPG::getColumns
		{
			if ( !b_nCount )
			{
				declareVariable( AG_COUNT, pcsaHeader, &b_nCount );
			}

			pcsaBody->Add("        nCount = ScreenT27.getColumns()" );
		}
		break;

		case 9:		// IScreenUPG::getConnectStatus
		{
			if ( !b_bRet )
			{
				declareVariable( AG_RETURN, pcsaHeader, &b_bRet );
			}

			pcsaBody->Add("        bRet = ScreenT27.getConnectStatus()" );

		}
		break;

		case 10:		// IScreenUPG::getCursor
		{
			if ( !b_nOutRow )
			{
				declareVariable( AG_OUTROW, pcsaHeader, &b_nOutRow );
			}

			if ( !b_nOutColumn )
			{
				declareVariable( AG_OUTCOLUMN, pcsaHeader, &b_nOutColumn );
			}

			pcsaBody->Add("        cursorObj = ScreenT27.getCursor()   'todo" );	
			pcsaBody->Add(" " );
		}
		break;

		case 11:		// IScreenUPG::getCursorColumn
		{
			if ( !b_nColumn )
			{
				declareVariable( AG_COLUMN, pcsaHeader, &b_nColumn );			
			}

			pcsaBody->Add("        nColumn = ScreenT27.getCursorColumn()" );
			pcsaBody->Add("" );
		}
		break;


		case 12:		// Screen::getCursorRow
		{
			if ( !b_nRow )
			{
				declareVariable( AG_ROW, pcsaHeader, &b_nRow );			
			}

			pcsaBody->Add("        nRow = ScreenT27.getCursorRow()" );
			pcsaBody->Add("" );
		}
		break;

		case 13:		// IScreenUPG::getDataCapture
		{
			if ( !b_bRet )
			{
				declareVariable( AG_RETURN, pcsaHeader, &b_bRet );
			}

			pcsaBody->Add("        bRet = ScreenT27.getDataCapture()" );
			pcsaBody->Add("" );
		}
		break;

		case 14:	// IScreenUPG::getExtPS
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

			csViewOutStuff.Format( "        nRow = %s", pcsaArguments->GetAt(1) );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "        nColumn = %s", pcsaArguments->GetAt(2) );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "        nLength = %s", pcsaArguments->GetAt(3) );
			pcsaBody->Add(csViewOutStuff);


			pcsaBody->Add("        Buffer = ScreenT27.getExtPS( nRow, nColumn, nLength )" );
			pcsaBody->Add("" );

		}
		break;


		case 15:	// IScreenUPG::getgetText_Display
		{
			if ( !b_bRet )
			{
				declareVariable( AG_RETURN, pcsaHeader, &b_bRet );
			}

			pcsaBody->Add("        bRet = ScreenT27.getgetText_Display()" );
			pcsaBody->Add("" );

		}
		break;


		case 16:	// IScreenUPG::getKeyboardLocked
		{
			if ( !b_bKeyboardLocked )
			{
				declareVariable( AG_KBD_LOCKED, pcsaHeader, &b_bKeyboardLocked );
			}

			pcsaBody->Add("        bKeyboardLocked = ScreenT27.getKeyboardLocked()" );
			pcsaBody->Add("");

		}
		break;


		case 17:	// IScreenUPG::getMaxDataCaptureLength
		{
			if ( !b_nLength )
			{
				declareVariable( AG_LENGTH, pcsaHeader, &b_nLength );
			}

			pcsaBody->Add("        nLength = ScreenT27.getMaxDataCaptureLength()");
			pcsaBody->Add("");


		}
		break;

		case 18:	// IScreenUPG::getObjectVersion
		{
			if ( !b_nValue )
			{
				declareVariable( AG_VALUE, pcsaHeader, &b_nValue );
			}

			pcsaBody->Add("        nValue = ScreenT27.getObjectVersion()" );
			pcsaBody->Add("");

		}
		break;


		case 19:	// IScreenUPG::getOIAContents
		{
			if ( !b_nBuffer )
			{
				declareVariable( AG_UTILBUFFER, pcsaHeader, &b_nBuffer );
			}

			pcsaBody->Add("        Buffer = ScreenT27.getOIAContents()");
			pcsaBody->Add("");

		}
		break;

		case 20:	// IScreenUPG::getOIAText
		{
			if ( !b_nBuffer )
			{
				declareVariable( AG_UTILBUFFER, pcsaHeader, &b_nBuffer );
			}

			pcsaBody->Add("        Buffer = ScreenT27.getOIAText()");
			pcsaBody->Add("");

		}
		break;

		case 21:	// IScreenUPG::getRows
		{
			if ( !b_nCount )
			{
				declareVariable( AG_COUNT, pcsaHeader, &b_nCount );
			}

			pcsaBody->Add("        nCount = ScreenT27.getRows()");
			pcsaBody->Add("");

		}
		break;

		case 22:	// IScreenUPG::getScreenType
		{
			if ( !b_nType )
			{
				declareVariable( AG_TYPE, pcsaHeader, &b_nType );
			}

			csViewOutStuff.Format( "        nType = ScreenT27.getScreenType()" );
			pcsaBody->Add(csViewOutStuff);
		}
		break;

		case 23:	// Screen::getString
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

			
			csViewOutStuff.Format( "        nRow = %s", pcsaArguments->GetAt(1) );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "        nColumn = %s", pcsaArguments->GetAt(2) );
			pcsaBody->Add(csViewOutStuff);
			

			csViewOutStuff.Format( "        nLength = %s", pcsaArguments->GetAt(3) );
			pcsaBody->Add(csViewOutStuff);
			
			csViewOutStuff.Format( "        cString = ScreenT27.getString( nRow, nColumn, nLength )");
			pcsaBody->Add(csViewOutStuff);


		}
		break;

		case 24:	// IScreenUPG::getStringEx
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

			csViewOutStuff.Format( "        nRow = %s", pcsaArguments->GetAt(1) );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "        nColumn = %s", pcsaArguments->GetAt(2) );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "        nEndRow = %s", pcsaArguments->GetAt(3) );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "        nEndColumn = %s", pcsaArguments->GetAt(4) );
			pcsaBody->Add(csViewOutStuff);

			if ( -1 != pcsaArguments->GetAt(5).Find( "TRUE" ) )
			{
				csViewOutStuff.Format( "        nWrap = 1   'WRAP_ON" );
			}
			else
			{
				csViewOutStuff.Format( "        nWrap = 0   'WRAP_OFF" );
			}
			pcsaBody->Add(csViewOutStuff);

			CString csAttributes;
			int nAttributeTally=0;
			csAttributes = pcsaArguments->GetAt(6);

			if ( -1 != csAttributes.Find("SCREENATTR_ANY") )
			{
				csViewOutStuff.Format( "        nAttribute = -1   'SCREENATTR_ANY" );
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

				csViewOutStuff.Format( "        nAttribute = %i", nAttributeTally );

			}
			pcsaBody->Add(csViewOutStuff);

			pcsaBody->Add("" );
			pcsaBody->Add("        cText = ScreenT27.getStringEx( nRow, nColumn, nEndRow, nEndColumn, 0, nWrap, nAttribute, 0 )" );
			pcsaBody->Add(" " );

		}
		break;

		case 25:	// Screen::getText
		{
			if ( !b_cText )
			{
				declareVariable( AG_TEXT, pcsaHeader, &b_cText );
			}

			csViewOutStuff.Format( "        cText = ScreenT27.getText()");
			pcsaBody->Add(csViewOutStuff);

		}
		break;

		case 26:	// IScreenUPG::hideTerminal
		{
			if ( !b_bRet )
			{
				declareVariable( AG_RETURN, pcsaHeader, &b_bRet );
			}

			csViewOutStuff.Format( "        ScreenT27.hideTerminal()");
			pcsaBody->Add(csViewOutStuff);

		}
		break;

		case 27:	// IScreenUPG::isKeyboardLocked
		{
			if ( !b_bKeyboardLocked )
			{
				declareVariable( AG_KBD_LOCKED, pcsaHeader, &b_bKeyboardLocked );
			}

			csViewOutStuff.Format( "        bKeyboardLocked = ScreenT27.isKeyboardLocked()");
			pcsaBody->Add(csViewOutStuff);

		}
		break;

		case 28:	// Screen::putString
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


			csViewOutStuff.Format( "        cString = %s", pcsaArguments->GetAt(1) );
			pcsaBody->Add(csViewOutStuff);
			
			csViewOutStuff.Format( "        nRow = %s", pcsaArguments->GetAt(2) );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "        nColumn = %s", pcsaArguments->GetAt(3) );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "        try");
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "        {");
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "         nLength = ScreenT27.putString( cString, nRow, nColumn )");
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "        }");
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "        catch( Exception e )");
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "        {");
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "         MsgBox e.getMessage() ");
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "        }");
			pcsaBody->Add(csViewOutStuff);

		}
		break;
	
		case 29:		// IScreenUPG::putStringEx
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



			csViewOutStuff.Format( "        cString = %s", pcsaArguments->GetAt(1) );
			pcsaBody->Add(csViewOutStuff);
			
			csViewOutStuff.Format( "        nRow = %s", pcsaArguments->GetAt(2) );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "        nColumn = %s", pcsaArguments->GetAt(3) );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "        nEndRow = %s", pcsaArguments->GetAt(4) );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "        nEndColumn = %s", pcsaArguments->GetAt(5) );
			pcsaBody->Add(csViewOutStuff);

			if ( -1 != pcsaArguments->GetAt(6).Find( "TRUE" ) )
			{
				csViewOutStuff.Format( "        nWrap = 1   'WRAP_ON" );
			}
			else
			{
				csViewOutStuff.Format( "        nWrap = 0   'WRAP_OFF" );
			}
			pcsaBody->Add(csViewOutStuff);

			CString csModes;
			int		nModeValue = 2;	// let this be the default
			csModes = pcsaArguments->GetAt(7);

			if ( -1 != csModes.Find("PUTSTRING_SKIP") )
			{
				csViewOutStuff.Format( "        nMode = 2   'PUTSTRING_SKIP" );			
			}
			else if ( -1 != csModes.Find("PUTSTRING_SPAN") )
			{
				csViewOutStuff.Format( "        nMode = 1   'PUTSTRING_SPAN" );			
			}
			else if ( -1 != csModes.Find("PUTSTRING_STOP") )
			{
				csViewOutStuff.Format( "        nMode = 0   'PUTSTRING_STOP" );			
			}
			pcsaBody->Add(csViewOutStuff);

			if ( -1 != pcsaArguments->GetAt(8).Find( "TRUE" ) )
			{
				pcsaBody->Add("        bFill = true" );
			}
			else
			{
				pcsaBody->Add("        bFill = false" );
			}
			pcsaBody->Add("");

			pcsaBody->Add("        try");
			pcsaBody->Add("        {");
			pcsaBody->Add("           nLength = ScreenT27.putStringEx( cString, nRow, nColumn, nEndRow, nEndColumn, 0, nWrap, nMode, bFill )");
			pcsaBody->Add("        }");
			pcsaBody->Add("        catch( Exception e )");
			pcsaBody->Add("        {");
			pcsaBody->Add("           MsgBox e.getMessage()");
			pcsaBody->Add("        }");
			pcsaBody->Add("");

		}
		break;

		case 30:		// IScreenUPG.sendkeys
		{
			if ( !b_cText )
			{
				declareVariable( AG_TEXT, pcsaHeader, &b_cText );
			}

			if ( !b_nType )
			{
				declareVariable( AG_TYPE, pcsaHeader, &b_nType );
			}

			csViewOutStuff.Format( "        cText = \"%s\"", pcsaArguments->GetAt(1) );
			pcsaBody->Add(csViewOutStuff);

			CString csType;
			csType = pcsaArguments->GetAt(2);

			if ( -1 != csType.Find("KEYTYPE_HLLAPI") )
			{
				csViewOutStuff.Format( "        nType = 131072   'KEYTYPE_HLLAPI" );
			}
			else
			{
				csViewOutStuff.Format( "        nType = 65536   'KEYTYPE_BRACES" );
			}
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( " " );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "        ScreenT27.sendkeys( cText, nType )" );
			pcsaBody->Add(csViewOutStuff);
		}
		break;

		case 31:	// IScreenUPG::setCursor
		{
			if ( !b_nRow )
			{
				declareVariable( AG_ROW, pcsaHeader, &b_nRow );
			}

			if ( !b_nColumn )
			{
				declareVariable( AG_COLUMN, pcsaHeader, &b_nColumn );			
			}

			csViewOutStuff.Format( "        nRow = %s", pcsaArguments->GetAt(1) );
			pcsaBody->Add(csViewOutStuff);
			csViewOutStuff.Format( "        nColumn = %s", pcsaArguments->GetAt(2) );
			pcsaBody->Add(csViewOutStuff);

			pcsaBody->Add(" " );
			pcsaBody->Add("        try" );
			pcsaBody->Add("        {" );
			pcsaBody->Add("           ScreenT27.setCursor( nRow, nColumn )");
			pcsaBody->Add("        }" );
			pcsaBody->Add("        catch (e)" );
			pcsaBody->Add("        {" );
			pcsaBody->Add("           MsgBox e.getMessage()");
			pcsaBody->Add("        }" );
			pcsaBody->Add(" " );


		}
		break;

		case 32:	// IScreenUPG::setCursorColumn
		{
			if ( !b_bRet )
			{
				declareVariable( AG_RETURN, pcsaHeader, &b_bRet );
			}

			if ( !b_nColumn )
			{
				declareVariable( AG_COLUMN, pcsaHeader, &b_nColumn );			
			}

			csViewOutStuff.Format( "        nColumn = %s", pcsaArguments->GetAt(1) );
			pcsaBody->Add(csViewOutStuff);

			pcsaBody->Add(" " );
			pcsaBody->Add("        try" );
			pcsaBody->Add("        {" );
			pcsaBody->Add("           bRet = ScreenT27.setCursorColumn( nColumn )");
			pcsaBody->Add("        }" );
			pcsaBody->Add("        catch (e)" );
			pcsaBody->Add("        {" );
			pcsaBody->Add("           MsgBox e.getMessage()");
			pcsaBody->Add("        }" );
			pcsaBody->Add(" " );

		}
		break;

		case 33:	// IScreenUPG::setCursorRow
		{
			if ( !b_bRet )
			{
				declareVariable( AG_RETURN, pcsaHeader, &b_bRet );
			}

			if ( !b_nRow )
			{
				declareVariable( AG_ROW, pcsaHeader, &b_nRow );
			}

			csViewOutStuff.Format( "        nRow = %s", pcsaArguments->GetAt(1) );
			pcsaBody->Add(csViewOutStuff);

			pcsaBody->Add(" " );
			pcsaBody->Add("        try" );
			pcsaBody->Add("        {" );
			pcsaBody->Add("           bRet = ScreenT27.setCursorRow( nRow )");
			pcsaBody->Add("        }" );
			pcsaBody->Add("        catch (e)" );
			pcsaBody->Add("        {" );
			pcsaBody->Add("           MsgBox e.getMessage() )");
			pcsaBody->Add("        }" );
			pcsaBody->Add(" " );

		}
		break;

		case 34:	// IScreenUPG::setDataCapture
		{
			if ( !b_bCaptureData )
			{
				declareVariable( AG_DATA_CAPTURE, pcsaHeader, &b_bCaptureData );
			}

			if ( -1 != pcsaArguments->GetAt(1).Find( "TRUE" ) )
			{
				pcsaBody->Add("        bCaptureData = true" );
			}
			else
			{
				pcsaBody->Add("        bCaptureData = false" );
			}

			pcsaBody->Add("        ScreenT27.setDataCapture( bCaptureData )" );
			pcsaBody->Add("");

		}
		break;

		case 35:		// IScreenUPG::setgetText_Display
		{
			if ( !b_bTextDisplay )
			{
				declareVariable( AG_TEXT_DISPLAY, pcsaHeader, &b_bTextDisplay );
			}

			if ( -1 != pcsaArguments->GetAt(1).Find( "TRUE" ) )
			{
				pcsaBody->Add("        bTextDisplay = true" );
			}
			else
			{
				pcsaBody->Add("        bTextDisplay = false" );
			}

			pcsaBody->Add("        ScreenT27.setgetText_Display( bTextDisplay )" );
			pcsaBody->Add("");

		}
		break;

		case 36:		// IScreenUPG::setMaxDataCaptureLength
		{
			if ( !b_nBufferSize )
			{
				declareVariable( AG_BUFFER_SIZE, pcsaHeader, &b_nBufferSize );
			}

			csViewOutStuff.Format( "        nBufferSize = %s", pcsaArguments->GetAt(1) );
			pcsaBody->Add(csViewOutStuff);

			pcsaBody->Add("        ScreenT27.setMaxDataCaptureLength( nBufferSize )" );
			pcsaBody->Add("");

		}
		break;

		case 37:		// IScreenUPG::showColorDialog
		{
			pcsaBody->Add("        ScreenT27.showColorDialog()" );
			pcsaBody->Add("");
		}
		break;

		case 38:		// IScreenUPG::showTerminal
		{
			pcsaBody->Add("        ScreenT27.showTerminal()" );
			pcsaBody->Add("");
		}
		break;

		case 39:		// IScreenUPG::waitForCursor
		{
			if ( !b_bRet )
			{
				declareVariable( AG_RETURN, pcsaHeader, &b_bRet );
			}

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

			csViewOutStuff.Format( "        nRow = %s", pcsaArguments->GetAt(1) );
			pcsaBody->Add(csViewOutStuff);
			csViewOutStuff.Format( "        nColumn = %s", pcsaArguments->GetAt(2) );
			pcsaBody->Add(csViewOutStuff);
			csViewOutStuff.Format( "        nTimeout = %s", pcsaArguments->GetAt(3) );
			pcsaBody->Add(csViewOutStuff);

			pcsaBody->Add("" );
			pcsaBody->Add("        try" );
			pcsaBody->Add("        {" );
			pcsaBody->Add("           bRet = ScreenT27.waitForCursor( nRow, nColumn, nTimeout )");
			pcsaBody->Add("        }" );
			pcsaBody->Add("        catch (e)" );
			pcsaBody->Add("        {" );
			pcsaBody->Add("           MsgBox e.getMessage()");
			pcsaBody->Add("        }" );
			pcsaBody->Add("" );

		}
		break;

		case 40:		// IScreenUPG::waitForString
		{
			if ( !b_bRet )
			{
				declareVariable( AG_RETURN, pcsaHeader, &b_bRet );
			}

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

			csViewOutStuff.Format( "        cText = \"%s\"", pcsaArguments->GetAt(1) );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "        nRow = %s", pcsaArguments->GetAt(2) );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "        nColumn = %s", pcsaArguments->GetAt(3) );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "        nWait = %s", pcsaArguments->GetAt(4) );
			pcsaBody->Add(csViewOutStuff);

			pcsaBody->Add("" );
			pcsaBody->Add("        try" );
			pcsaBody->Add("        {" );
			pcsaBody->Add("           bRet = ScreenT27.waitForString( cText, nRow, nColumn, nWait )");
			pcsaBody->Add("        }" );
			pcsaBody->Add("        catch (e)" );
			pcsaBody->Add("        {" );
			pcsaBody->Add("           MsgBox e.getMessage()");
			pcsaBody->Add("        }" );
			pcsaBody->Add("" );

		}
		break;


		case 41:		// IScreenUPG::waitHostQuiet
		{
			if ( !b_bRet )
			{
				declareVariable( AG_RETURN, pcsaHeader, &b_bRet );
			}
			if ( !b_nWait )
			{
				declareVariable( AG_WAIT, pcsaHeader, &b_nWait );
			}

			if ( !b_nSettleTime )
			{
				declareVariable( AG_SETTLE_TIME, pcsaHeader, &b_nSettleTime );
			}

			csViewOutStuff.Format( "        nWait = %s", pcsaArguments->GetAt(1) );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "        nSettleTime = %s", pcsaArguments->GetAt(2) );
			pcsaBody->Add(csViewOutStuff);

			pcsaBody->Add("" );
			pcsaBody->Add("        try" );
			pcsaBody->Add("        {" );
			pcsaBody->Add("           bRet = ScreenT27.waitHostQuiet( nWait, nSettleTime )");
			pcsaBody->Add("        }" );
			pcsaBody->Add("        catch (e)" );
			pcsaBody->Add("        {" );
			pcsaBody->Add("           MsgBox e.getMessage()");
			pcsaBody->Add("        }" );
			pcsaBody->Add("" );
		}
		break;

		case 42:		// debug
		{
		}
		break;

	}

	pcsaArguments->RemoveAll();
}


void CAG_AIR_VM_T27_VBS::finalize(CStringArray* pcsaBody)
{
	pcsaBody->Add("End Sub");
	pcsaBody->Add("</script>");
	pcsaBody->Add("</BODY>");
	pcsaBody->Add("</HTML>");
}



/****************************************************************************DC
	Function	:	CAG_AIR_VM_T27_VBS::declareVariable()

	Purpose		:	Append variable declarations to the end of the header as 
					needed.

*****************************************************************************/
void CAG_AIR_VM_T27_VBS::declareVariable(AG_VARIABLE agVariable,
									   CStringArray* pcsaHeader,
									   bool* bValue)
{
	CString csLocal;
	*bValue = TRUE;
	
	switch ( agVariable )
	{
		case AG_STATUS:
		{
			csLocal.Format( "      Dim nStatus");
		}
		break;

		case AG_DIRECTION:
		{
			csLocal.Format( "      Dim nDirection");
		}
		break;

		case AG_UPDATED:
		{
			csLocal.Format( "      Dim bUpdated");
		}
		break;

		case AG_UTILBUFFER:
		{
			csLocal.Format( "      Dim Buffer");
		}
		break;

		case AG_ROW:
		{
			csLocal.Format( "      Dim nRow");
		}
		break;

		case AG_ENDROW:
		{
			csLocal.Format( "      Dim nEndRow");
		}
		break;

		case AG_COLUMN:
		{
			csLocal.Format( "      Dim nColumn");		
		}
		break;

	
		case AG_ENDCOLUMN:
		{
			csLocal.Format( "      Dim nEndColumn");		
		}
		break;


		case AG_ATTRIBUTE:
		{
			csLocal.Format( "      Dim nAttribute");
		}
		break;

		case AG_LENGTH:
		{
			csLocal.Format( "      Dim nLength");
		}
		break;

		case AG_VALUE:
		{
			csLocal.Format( "      Dim nValue");
		}
		break;

		case AG_RETURN:
		{
			csLocal.Format( "      Dim bRet");
		}
		break;

		case AG_CLOSEOPTION:
		{
			csLocal.Format( "      Dim nCloseOption");
		}
		break;

		case AG_HOST_OS:
		{
			csLocal.Format( "      Dim nFTHostOS");
		}
		break;

		case AG_HEIGHT:
		{
			csLocal.Format( "      Dim nHeight");
		}
		break;

		case AG_LOCALMODE:
		{
			csLocal.Format( "      Dim bLocalMode");
		}
		break;

		case AG_SESS_SAVED:
		{
			csLocal.Format( "      Dim bSessionSaved");
		}
		break;

		case AG_SESSIONS_CREATED:
		{
			csLocal.Format( "      Dim Sessions[]" );
		}
		break;

		case AG_SESS_OPEN:
		{
			csLocal.Format( "      Dim SessName");
		}
		break;


		case AG_SETTLE_TIME:
		{
			csLocal.Format( "      Dim nSettleTime");
		}
		break;

		case AG_SESS_QUIET:
		{
			csLocal.Format( "      Dim bSessionQuiet");
		}
		break;

		case AG_MENU_VISIBLE:
		{
			csLocal.Format( "      Dim bMenuVisible");
		}
		break;

		case AG_TYPE:
		{
			csLocal.Format( "      Dim nType");
		}
		break;

		case AG_TIMEOUT:
		{
			csLocal.Format( "      Dim nTimeout");
		}
		break;

		case AG_PROCESS_KEYSTROKES:
		{
			csLocal.Format( "      Dim bProcessKeystrokes");
		}
		break;

		case AG_WIDTH:
		{
			csLocal.Format( "      Dim nWidth");
		}
		break;

		case AG_WINDOW_HANDLE:
		{
			csLocal.Format( "      Dim hSession");
			//csLocal.Format( "   HANDLE hSession=NULL");
		}
		break;

		case AG_WINDOW_STATE:
		{
			csLocal.Format( "      Dim nWindowState");
		}
		break;

		case AG_COUNT:
		{
			csLocal.Format( "      Dim nCount");
		}
		break;

		case AG_AREA:
		{
			csLocal.Format( "      Dim Area");
		}
		break;

		// new stuff
		case AG_NAME:
		{
			csLocal.Format( "      Dim csName" );
		}
		break;

		case AG_SCREEN_LISTENER:
		{
			csLocal.Format( "      Dim isl" );
		}
		break;

		case AG_TERMINAL:
		{
			csLocal.Format( "      'Terminal" );
		}
		break;

		case AG_OIAOBJ:
		{
			csLocal.Format( "      Dim OIAObj" );
		}
		break;

		case AG_TEXT:
		{
			csLocal.Format( "      Dim cText" );
		}
		break;

		case AG_EAB:
		{
			csLocal.Format( "      Dim bEABs" );
		}
		break;

		case AG_HOST_CHARSET:
		{
			csLocal.Format( "      Dim nCharSet" );
		}
		break;

		case AG_HOST_CODEPAGE:
		{
			csLocal.Format( "      Dim nHostCodePage" );
		}
		break;

		case AG_INDEX:
		{
			csLocal.Format( "      Dim nIndex" );
		}
		break;

		case AG_KBD_LOCKED:
		{
			csLocal.Format( "      Dim bKeyboardLocked" );
		}
		break;

		case AG_MODEL:	
		{
			csLocal.Format( "      Dim nModel" );
		}
		break;

		case AG_STRING:
		{
			csLocal.Format( "      Dim cString" );
		}
		break;

		case AG_MODE:
		{
			csLocal.Format( "      Dim nMode" );
		}
		break;

		case AG_WAIT:
		{
			csLocal.Format( "      Dim nWait" );
		}
		break;

		case AG_ATTACHED:
		{
			csLocal.Format( "      Dim bAttached" );
		}
		break;

		case AG_CONNECTED:
		{
			csLocal.Format( "      Dim bConnected" );
		}
		break;

		case AG_CONNECTION_OBJ:
		{
			csLocal.Format( "      Dim conn" );
		}
		break;

		case AG_SCREEN_OBJ:
		{
			csLocal.Format( "      Dim screen" );
		}
		break;

		case AG_STATE:
		{
			csLocal.Format( "      Dim nState" );
		}
		break;

		case AG_PORT:
		{
			csLocal.Format( "      Dim nPort" );
		}
		break;

		case AG_WRAP:
		{
			csLocal.Format( "      Dim bWrap" );
		}
		break;


		case AG_FILL:
		{
			csLocal.Format( "      Dim bFill" );
		}
		break;

		case AG_DATA_CAPTURE:
		{
			csLocal.Format( "      Dim bCaptureData" );
		}
		break;

		case AG_TEXT_DISPLAY:
		{
			csLocal.Format( "      Dim bTextDisplay" );
		}
		break;

		case AG_BUFFER_SIZE:
		{
			csLocal.Format( "      Dim nBufferSize" );
		}
		break;


		case AG_USER_ID:
		{
			csLocal.Format( "      Dim csUserID");
		}
		break;

		case AG_PASSWORD:
		{
			csLocal.Format( "      Dim csPassword");
		}
		break;

		case AG_WEBVIEW_NAME:
		{
			csLocal.Format( "      Dim csWebView");
		}
		break;

		case AG_UPG_SCREEN:
		{
			csLocal.Format( "      Dim isUPG");
		}
		break;

		case AG_SERVER:	
		{
			csLocal.Format( "      Dim csServer" );
		}
		break;
			
		case AG_ID_COUNT:	
		{
			csLocal.Format( "      Dim nIDCount" );
		}
		break;
			
		case AG_ID_INCREMENT:	
		{
			csLocal.Format( "      Dim nIDIncrement" );
		}
		break;
			
		case AG_IDMGR_ADDRESS:	
		{
			csLocal.Format( "      Dim csIDManagerAddress" );
		}
		break;
			
	}

	pcsaHeader->Add(csLocal);

}


void CAG_AIR_VM_T27_VBS::checkDebug(bool b_Debug,
								  CString csFunctionName,
								  CStringArray* pcsaBody)
{
	CString csLocal;
	
	if ( b_Debug )
	{
		csLocal.Format( "   MsgBox \"%s\"", csFunctionName );
		pcsaBody->Add(csLocal);
	}
}


void CAG_AIR_VM_T27_VBS::resetVariableFlags()
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