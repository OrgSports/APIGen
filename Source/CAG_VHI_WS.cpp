// Static Model
#include "stdafx.h"
#include "apigen.h"

#include "CAG_VHI_WS.h"

CAG_VHI_WS::CAG_VHI_WS()
{
	resetVariableFlags();
}

CAG_VHI_WS::~CAG_VHI_WS()
{
	
}


void CAG_VHI_WS::generateHeader(CStringArray* pcsaHeader,
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
	pcsaHeader->Add("'           Attachmate Verastream Host Integrator");
	pcsaHeader->Add("'          APIGen Windows Scripting 3270 Application");
	pcsaHeader->Add("'" );
	pcsaHeader->Add("'   This file consists of VBScript calls to the the Verastream Host");
	pcsaHeader->Add("'    Integrator 3270 OLE Automation interface.");
	pcsaHeader->Add("'" );
	pcsaHeader->Add("'   After this code is generated it will be necessary for you to double click on");
	pcsaHeader->Add("'   this .vbs file.  You may choose to modify this file in one or more of the ");
	pcsaHeader->Add("'   following ways:");
	pcsaHeader->Add("'   1) You can encrypt this file using the Microsoft Script Encoder for Windows");
	pcsaHeader->Add("'      Script Files to prevent users from reading your source code.");
	pcsaHeader->Add("'   2) You can compile it into a script component to selectively expose its functionality");
	pcsaHeader->Add("'      and establish its Windows security credentials.");

	time_t ltime;
	time( &ltime );

	pcsaHeader->Add("'" );
	csViewOutStuff.Format( "'   Generated:   %s", ctime( &ltime ) );
	pcsaHeader->Add(csViewOutStuff);

	pcsaHeader->Add( "" );
	pcsaHeader->Add("' ****************************************************************************");
	pcsaHeader->Add( "" );
	pcsaHeader->Add("Dim ACSession");

	pcsaBody->Add("" );
	pcsaBody->Add("set ACSession = CreateObject(\"AppConn.SessionEx\")" );
	pcsaBody->Add("" );

}

void CAG_VHI_WS::appendBody(int nFunctionNum,
								 bool bPromptForValues,
								 CStringArray* pcsaArguments,
								 CStringArray* pcsaHeader,
								 CStringArray* pcsaBody)
{
	CString csViewOutStuff;
	CString csFunctionName, csFunctionNum;

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

	csViewOutStuff.Format( "'*** %s", csFunctionName );
	pcsaBody->Add(csViewOutStuff);

	checkDebug( b_Debug, csFunctionName, pcsaBody );

	CString	csLocal;

	switch ( nFunctionNum )
	{
		case 0:		// ConnectionTimeout
		{
			if ( !b_nTimeout )
			{
				declareVariable( AG_TIMEOUT, pcsaHeader, &b_nTimeout );
			}

			if ( -1 != pcsaArguments->GetAt(1).Find("TRUE") )
			{
				csViewOutStuff.Format( "nTimeout = %s", pcsaArguments->GetAt(2));
				pcsaBody->Add(csViewOutStuff);

				csViewOutStuff.Format( "ACSession.ConnectionTimeout = nTimeout");
				pcsaBody->Add(csViewOutStuff);
			}
			else
			{
				csViewOutStuff.Format( "nTimeout = ACSession.ConnectionTimeout");
				pcsaBody->Add(csViewOutStuff);
			}

		}
		break;

		case 1:			// ConnectToModel
		{
			if ( !b_csServer )
			{
				declareVariable( AG_SERVER, pcsaHeader, &b_csServer );
			}

			if ( !b_csModel )
			{
				declareVariable( AG_MODEL, pcsaHeader, &b_csModel );
			}

			if ( !b_csUserID )
			{
				declareVariable( AG_USER_ID, pcsaHeader, &b_csUserID );
			}

			if ( !b_csPassword )
			{
				declareVariable( AG_PASSWORD, pcsaHeader, &b_csPassword );
			}

			if ( !b_csModelVariable )
			{
				declareVariable( AG_MODEL_VARIABLE, pcsaHeader, &b_csModelVariable );
			}

			csViewOutStuff.Format( "csServer = \"%s\"", pcsaArguments->GetAt(1));
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "csModel = \"%s\"", pcsaArguments->GetAt(2));
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "csUserID = \"%s\"", pcsaArguments->GetAt(3));
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "csPassword = \"%s\"", pcsaArguments->GetAt(4));
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "csModelVariable = \"%s\"", pcsaArguments->GetAt(5));
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "");
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "ACSession.ConnectToModel csServer, csModel, csUserID, csPassword, csModelVariable");
			pcsaBody->Add(csViewOutStuff);

		}
		break;

		case 5:			// Comment
		{
			csViewOutStuff.Format( "'***** %s", pcsaArguments->GetAt(1));
			pcsaBody->Add(csViewOutStuff);
		}
		break;


		case 8:			// ExecuteSQLStatement
		{
			if ( !b_csSQL )
			{
				declareVariable( AG_SQL, pcsaHeader, &b_csSQL );
			}

			csViewOutStuff.Format( "csSQL = \"%s\"", pcsaArguments->GetAt(1));
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "ACSession.ExecuteSQLStatement csSQL");
			pcsaBody->Add(csViewOutStuff);

		}
		break;

		case 2:		// ConnectToModelViaDomain	
		{
			if ( !b_csServer )
			{
				declareVariable( AG_SERVER, pcsaHeader, &b_csServer );
			}

			if ( !b_csDomain )
			{
				declareVariable( AG_DOMAIN, pcsaHeader, &b_csDomain );
			}

			if ( !b_csModel )
			{
				declareVariable( AG_MODEL, pcsaHeader, &b_csModel );
			}

			if ( !b_csUserID )
			{
				declareVariable( AG_USER_ID, pcsaHeader, &b_csUserID );
			}

			if ( !b_csPassword )
			{
				declareVariable( AG_PASSWORD, pcsaHeader, &b_csPassword );
			}

			if ( !b_csModelVariable )
			{
				declareVariable( AG_MODEL_VARIABLE, pcsaHeader, &b_csModelVariable );
			}

			csViewOutStuff.Format( "csServer = \"%s\"", pcsaArguments->GetAt(1));
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "csDomain = \"%s\"", pcsaArguments->GetAt(2));
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "csModel = \"%s\"", pcsaArguments->GetAt(3));
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "csUserID = \"%s\"", pcsaArguments->GetAt(4));
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "csPassword = \"%s\"", pcsaArguments->GetAt(5));
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "csModelVariable = \"%s\"", pcsaArguments->GetAt(6));
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "");
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "ACSession.ConnectToModelViaDomain csServer, csDomain, csModel, csUserID, csPassword, csModelVariable");
			pcsaBody->Add(csViewOutStuff);

		}
		break;

		case 3:			// ConnectToSession
		case 4:			// ConnectToSessionViaDomain
		case 6:			// Disconnect
		case 7:			// EnableTerminalAttributes
		case 9:			// FetchRecords
		case 10:		// GetAttributeAtCursor
		case 11:		// GetAttributeLocations
		case 12:		// GetAttributeMetaData
		case 13:		// GetAttributes
		case 14:		// GetColumnMetaData
		case 15:		// GetCurrentEntity
		case 16:		// GetCurrentRecord
		case 17:		// GetCurrentRecordIndex
		case 18:		// GetCurrentRecordSetName
		case 19:		// GetEntityAttributes
		case 20:		// GetEntityDescription
		case 21:		// GetEntityOperations
		case 22:		// GetEntityRecordSets
		case 23:		// GetFieldLocations
		case 24:		// GetFieldMetaData
		case 25:		// GetHomeEntityName
		case 26:		// GetLastRequestID
		case 27:		// GetLocale
		case 28:		// GetLoggingLevel
		case 29:		// GetMajorVersion
		case 30:		// GetMethodTimeout
		case 31:		// GetMinorVersion
		case 32:		// GetModelEntities
		case 33:		// GetModelVariableNames
		case 34:		// GetModelVariables
		case 35:		// GetOperationMetaData
		case 36:		// GetPatternLocations
		case 37:		// GetProcedureMetaData
		case 38:		// GetRecordSetLocations
		case 39:		// GetRecordSetMetaData
		case 40:		// GetSessionID
		case 41:		// GetStringAtOffset
		case 42:		// GetStringAtRowColumn
		case 43:		// GetTableColumns
		case 44:		// GetTableDescription
		case 45:		// GetTableNames
		case 46:		// GetTableProcedures
		case 47:		// GetTerminalFieldAtCursor
		case 48:		// GetVariableMetaData
		case 49:		// GetVersionString
		case 50:		// IsSecureConnection
		case 51:		// InsertRecord
		case 52:		// InsertRecords
		case 53:		// InsertStringAtCursor
		case 54:		// InsertStringAtOffset
		case 55:		// InsertStringAtRowColumn
		case 56:		// IsConnected
		case 57:		// LastErrorMessageList
		case 58:		// MetaDataOnly
		case 59:		// ModelName
		case 60:		// ModelVersionString
		case 61:		// MoveCurrentRecordIndex
		case 62:		// NextRecord
		case 63:		// PerformAidKey
		case 64:		// PerformEntityOperation
		{

		}
		break;

		case 65:		// PerformTableProcedure
		{
			if ( !b_csTable )
			{
				declareVariable( AG_TABLE, pcsaHeader, &b_csTable );
			}

			if ( !b_csProcedure )
			{
				declareVariable( AG_PROCEDURE, pcsaHeader, &b_csProcedure );
			}

			if ( !b_csDataInputValues )
			{
				declareVariable( AG_DATA_INPUT_VALUES, pcsaHeader, &b_csDataInputValues );
			}

			if ( !b_csFilter )
			{
				declareVariable( AG_FILTER, pcsaHeader, &b_csFilter );
			}

			if ( !b_bCaseSensitive )
			{
				declareVariable( AG_CASE_SENSITIVE, pcsaHeader, &b_bCaseSensitive );
			}

			if ( !b_csOutputColNames )
			{
				declareVariable( AG_OUTPUT_COLNAMES, pcsaHeader, &b_csOutputColNames );
			}

			if ( !b_nMaxRows )
			{
				declareVariable( AG_MAX_ROWS, pcsaHeader, &b_nMaxRows );
			}


			csViewOutStuff.Format( "csTable = \"%s\"", pcsaArguments->GetAt(1));
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "csProcedure = \"%s\"", pcsaArguments->GetAt(2));
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "csDataInputValues = \"%s\"", pcsaArguments->GetAt(3));
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "csFilter = \"%s\"", pcsaArguments->GetAt(4));
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "bCaseSensitive = %s", pcsaArguments->GetAt(5));
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "csOutputColNames = \"%s\"", pcsaArguments->GetAt(6));
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "nMaxRows = \"%s\"", pcsaArguments->GetAt(7));
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "");
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "ACSession.PerformTableProcedure csTable, csProcedure, csDataInputValues, csFilter, bCaseSensitive, csOutputColNames, nMaxRows");
			pcsaBody->Add(csViewOutStuff);

		}
		break;



		case 66:		// ProcessString
		case 67:		// RequireSecureConnection
		case 68:		// ResumeConnection
		case 69:		// SelectCurrentRecord
		case 70:		// SelectRecordByFilter
		case 71:		// SelectRecordByIndex
		case 72:		// ServerName
		case 73:		// SessionType
		case 74:		// SetAttributes
		case 75:		// SetAttributesDelayed
		case 76:		// SetCurrentEntity
		case 77:		// SetCurrentRecordIndex
		case 78:		// SetCurrentRecordSetByName
		case 79:		// SetLocale
		case 80:		// SetLoggingLevel
		case 81:		// SetMethodTimeout
		case 82:		// SetModelVariables
		case 83:		// SuspendConnection
		case 84:		// UpdateCurrentRecord
		case 85:		// UpdateRecordByFilter
		case 86:		// UpdateRecordByIndex
		case 87:		// UpdateRecords
		case 88:		// WaitForCondition
		case 89:		// WaitForCursor
		case 90:		// WaitForEntityChange
		case 91:		// WaitForString
		case 92:		// WaitForStringRelCursor
		case 93:		// Debug
		{
		}
		break;
	}

	pcsaArguments->RemoveAll();
}


void CAG_VHI_WS::finalize(CStringArray* pcsaBody)
{
	pcsaBody->Add(" " );
}



void CAG_VHI_WS::declareVariable(AG_VARIABLE agVariable,
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

		case AG_DOMAIN:
		{
			csLocal.Format( "Dim csDomain" );
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
			csLocal.Format( "Dim csModel" );
		}
		break;

		case AG_MODEL_VARIABLE:	
		{
			csLocal.Format( "Dim csModelVariable" );
		}
		break;

		case AG_SERVER:	
		{
			csLocal.Format( "Dim csServer" );
		}
		break;

		case AG_SQL:	
		{
			csLocal.Format( "Dim csSQL" );
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

		case AG_TABLE:
		{
			csLocal.Format( "Dim csTable" );
		}
		break;

		case AG_PROCEDURE:
		{
			csLocal.Format( "Dim csProcedure" );
		}
		break;

		case AG_DATA_INPUT_VALUES:
		{
			csLocal.Format( "Dim csDataInputValues" );
		}
		break;

		case AG_FILTER:
		{
			csLocal.Format( "Dim csFilter" );
		}
		break;

		case AG_CASE_SENSITIVE:
		{
			csLocal.Format( "Dim bCaseSensitive" );
		}
		break;

		case AG_OUTPUT_COLNAMES:
		{
			csLocal.Format( "Dim csOutputColNames" );
		}
		break;

		case AG_MAX_ROWS:
		{
			csLocal.Format( "Dim nMaxRows" );
		}
		break;

	}

	pcsaHeader->Add(csLocal);
	
}

void CAG_VHI_WS::checkDebug(bool b_Debug,
							   CString csFunctionName,
							   CStringArray* pcsaBody)
{
	CString csLocal;
	
	if ( b_Debug )
	{
		csLocal.Format( "MsgBox \"%s\"", csFunctionName );
		pcsaBody->Add(csLocal);
	}
}


void CAG_VHI_WS::resetVariableFlags()
{
	b_bCaseSensitive=FALSE;
	b_csDomain=FALSE;
	b_bRet=FALSE;
	b_csCommand=FALSE;
	b_csDataInputValues=FALSE;
	b_csFilter=FALSE;
	b_csModel=FALSE;
	b_csModelVariable=FALSE;
	b_csName=FALSE;
	b_csOutputColNames=FALSE;
	b_csPassword=FALSE;
	b_csProcedure=FALSE;
	b_csServer=FALSE;
	b_csSQL=FALSE;
	b_csTable=FALSE;
	b_cString=FALSE;
	b_csUserID=FALSE;
	b_Debug=FALSE;
	b_hostname=FALSE;
	b_hSession=FALSE;
	b_nAttribute=FALSE;
	b_nCharSet=FALSE;
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
	b_nMaxRows=FALSE;
	b_nMode=FALSE;
	b_nModel=FALSE;
	b_nOptions=FALSE;
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
	b_SessName=FALSE;
	b_settingsPage=FALSE;
	b_settingsTab=FALSE;
	b_sKeys=FALSE;
	b_Terminal=FALSE;
}