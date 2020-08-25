// Static Model
#include "stdafx.h"
#include "apigen.h"

#include "CAG_ROLE_HP_WS.h"

CAG_ROLE_HP_WS::CAG_ROLE_HP_WS()
{
	resetVariableFlags();
}

CAG_ROLE_HP_WS::~CAG_ROLE_HP_WS()
{
	
}


void CAG_ROLE_HP_WS::generateHeader(CStringArray* pcsaHeader,
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

	pcsaHeader->Add("' ****************************************************************************");
	pcsaHeader->Add("'                   Attachmate Reflection for Win");
	pcsaHeader->Add("'                APIGen Windows Scripting for an HP Host");
	pcsaHeader->Add("'" );
	pcsaHeader->Add("'   This file consists of Windows VBScript commands that drive the Reflection for");
	pcsaHeader->Add("'   Windows OLE Automation interface.");
	pcsaHeader->Add("'" );
	pcsaHeader->Add("'   After this code is generated it will be necessary for you to double click on");
	pcsaHeader->Add("'   this .vbs file.  You may choose to modify this file in one or more of the ");
	pcsaHeader->Add("'   following ways:");
	pcsaHeader->Add("'   1) Timing issues/race conditions are more common in this type of scripting. So,");
	pcsaHeader->Add("'      a prompt is presented when you run the script that asks for a literal string");
	pcsaHeader->Add("'      that an initial WaitForDisplayString call can use in your session to better prepare");
	pcsaHeader->Add("'      the system for the generated automation calls that follow.");
	pcsaHeader->Add("'   2) You may choose to change the 10-second timeout value on the WaitForDisplayString");
	pcsaHeader->Add("'      call to a value better suited for your system. Note that the WaitForDisplayString");
	pcsaHeader->Add("'      call will return as soon as the search string is found and will not block the full.");
	pcsaHeader->Add("'      ten seconds unless the specified string is not found.");
	pcsaHeader->Add("'   3) You can encrypt this file using the Microsoft Script Encoder for Windows");
	pcsaHeader->Add("'      Script Files to prevent users from reading your source code.");
	pcsaHeader->Add("'   4) You can compile it into a script component to selectively expose its functionality");
	pcsaHeader->Add("'      and establish its Windows security credentials.");

	time_t ltime;
	time( &ltime );

	pcsaHeader->Add("'" );
	csViewOutStuff.Format( "'   Generated:   %s", ctime( &ltime ) );
	pcsaHeader->Add(csViewOutStuff);

	pcsaHeader->Add( "" );
	pcsaHeader->Add("' ****************************************************************************");
	pcsaHeader->Add( "" );
	pcsaHeader->Add("Dim System");
	pcsaHeader->Add("Dim Session");
	pcsaHeader->Add("Dim Sessionname");
	pcsaHeader->Add("Dim cString" );

	pcsaBody->Add("" );
	pcsaBody->Add("set Session = CreateObject(\"Reflection1.Session\")" );
	pcsaBody->Add("" );
	pcsaBody->Add("Sessionname = inputbox(\"Open this Reflection HP session:\", \"Specify fully qualified Reflection session\", \"C:\\TEMP\\auburn.rsf\")");
	pcsaBody->Add("Session.NewSession Sessionname");
	pcsaBody->Add("if Sessionname = \"\" then");
	pcsaBody->Add("   WScript.Quit(1)");
	pcsaBody->Add("else");
	pcsaBody->Add("   cString = inputbox(\"Please provide a ready state indicator string:\", \"Specify ready indicator\", \"userid\")");
	pcsaBody->Add("   Session.WaitForDisplayString \"cString\", \"0:0:10\", rcAnyRow, rcAnyCol" );
	pcsaBody->Add("" );

}


void CAG_ROLE_HP_WS::appendBody(int nFunctionNum,
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

	csViewOutStuff.Format( "   '*** %s", csFunctionName );
	pcsaBody->Add(csViewOutStuff);


	csViewOutStuff.Format( "   'APIGen has not yet implemented this method." );
	pcsaBody->Add(csViewOutStuff);

	pcsaArguments->RemoveAll();
}


void CAG_ROLE_HP_WS::finalize(CStringArray* pcsaBody)
{
	CString csViewOutStuff;

	pcsaBody->Add("end if");
	pcsaBody->Add(" " );

}

void CAG_ROLE_HP_WS::declareVariable(AG_VARIABLE agVariable,
									   CStringArray* pcsaHeader,
									   bool* bValue)
{
	CString csLocal;
	*bValue = TRUE;
	
	switch ( agVariable )
	{
		case AG_STRING:
		{
			csLocal.Format( "Dim cString");
		}
		break;

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

		case AG_BSTR:
		{
			csLocal.Format( "Dim v");
		}
		break;
	
		case AG_COMMAND:
		{
			csLocal.Format( "Dim csCommand");
		}
		break;

		case AG_ENDCOLUMN:
		{
			csLocal.Format( "Dim nEndColumn");
		}
		break;

		case AG_ENDROW:
		{
			csLocal.Format( "Dim nEndRow");
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

		case AG_FT_OBJ:
		{
			csLocal.Format( "Dim ftObj");
		}
		break;

		case AG_HOSTNAME:
		{
			csLocal.Format( "Dim hostname");
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

		case AG_SCREEN_HELD:
		{
			csLocal.Format( "Dim bScreenHeld");
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

		case AG_SETTINGS_PAGE:
		{
			csLocal.Format( "Dim settingsPage");
		}
		break;

		case AG_SETTINGS_TAB:
		{
			csLocal.Format( "Dim settingsTab");
		}
		break;

		case AG_MENU_VISIBLE:
		{
			csLocal.Format( "Dim bMenuVisible");
		}
		break;

		case AG_IDLE_TIME:
		{
			csLocal.Format( "Dim nIdle");
		}
		break;

		case AG_OPTIONS:
		{
			csLocal.Format( "Dim nOptions");
		}
		break;

		case AG_PAGE:
		{
			csLocal.Format( "Dim nPage");
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

		case AG_PROCESS:
		{
			csLocal.Format( "Dim bProcess");
		}
		break;

		case AG_PROCESS_KEYSTROKES:
		{
			csLocal.Format( "Dim sKeys");
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
			//csLocal.Format( "HANDLE hSession=NULL");
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

		case AG_EVENT:
		{
			csLocal.Format( "Dim nEventNum" );
		}
		break;


		case AG_FONTNAME:
		{
			csLocal.Format( "Dim font" );
		}
		break;

		case AG_FT_SCHEME:
		{
			csLocal.Format( "Dim FTScheme" );
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

		case AG_KEY:
		{
			csLocal.Format( "Dim nKey" );
		}
		break;


	}

	pcsaHeader->Add(csLocal);
	
}


void CAG_ROLE_HP_WS::checkDebug(bool b_Debug,
								  CString csFunctionName,
								  CStringArray* pcsaBody)
{
	CString csLocal;
	
	if ( b_Debug )
	{
		csLocal.Format( "MsgBox( \"%s\" )", csFunctionName );
		pcsaBody->Add(csLocal);
	}
}

void CAG_ROLE_HP_WS::resetVariableFlags()
{
	b_Area=FALSE;
	b_bAttached=FALSE;
	b_bConnected=FALSE;
	b_bEABs=FALSE;
	b_bKeyboardLocked=FALSE;
	b_bLocalMode=FALSE;
	b_bMenuVisible=FALSE;
	b_bProcess=FALSE;
	b_bRet=FALSE;
	b_bScreenHeld=FALSE;
	b_bSessionQuiet=FALSE;
	b_bSessionSaved=FALSE;
	b_bUpdated=FALSE;
	b_ConnectionObj=FALSE;
	b_csCommand=FALSE;
	b_csName=FALSE;
	b_cString=TRUE;
	b_cText=FALSE;
	b_Debug=FALSE;
	b_font=FALSE;
	b_ftObj=FALSE;
	b_FTScheme=FALSE;
	b_hostname=FALSE;
	b_hSession=FALSE;
	b_nAttribute=FALSE;
	b_nCharSet=FALSE;
	b_nCloseOption=FALSE;
	b_nColumn=FALSE;
	b_nCount=FALSE;
	b_nEndColumn=FALSE;
	b_nEndRow=FALSE;
	b_nEventNum=FALSE;
	b_nHeight=FALSE;
	b_nHostCodePage=FALSE;
	b_nHostOS=FALSE;
	b_nIdle=FALSE;
	b_nIdleTime=FALSE;
	b_nKey=FALSE;
	b_nLength=FALSE;
	b_nMode=FALSE;
	b_nModel=FALSE;
	b_nOptions=FALSE;
	b_nPage=FALSE;
	b_nPort=FALSE;
	b_nRow=FALSE;
	b_nSettleTime=FALSE;
	b_nState=FALSE;
	b_nStatus=FALSE;
	b_nTimeout=FALSE;
	b_nType=FALSE;
	b_nWait=FALSE;
	b_nWidth=FALSE;
	b_nWindowState=FALSE;
	b_pOIAObject=FALSE;
	b_ScreenObj=FALSE;
	b_SessName=FALSE;
	b_settingsPage=FALSE;
	b_settingsTab=FALSE;
	b_sKeys=FALSE;
	b_Terminal=FALSE;
}