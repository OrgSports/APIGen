// Static Model
#include "stdafx.h"
#include "apigen.h"

#include "CAG_CICS_QACOM_COM_ASP.h"

CAG_CICS_QACOM_COM_ASP::CAG_CICS_QACOM_COM_ASP()
{
	resetVariableFlags();	
}

CAG_CICS_QACOM_COM_ASP::~CAG_CICS_QACOM_COM_ASP()
{
	
}

void CAG_CICS_QACOM_COM_ASP::generateHeader(CStringArray* pcsaHeader,
											CStringArray* pcsaBody)
{

	CString csViewOutStuff;

	pcsaHeader->Add("<%@ Language=VBScript %>");

	pcsaHeader->Add("'  ****************************************************************************");
	pcsaHeader->Add("'                       Attachmate CICS Bridge COM");
	pcsaHeader->Add("'                         API Generator ASP VBScript");
	pcsaHeader->Add("' ");
	pcsaHeader->Add("'  This file is a program that features the use of the Attachmate");
	pcsaHeader->Add("'  CICS Bridge QACom API written in ASP and VBScript.  You can set up the");
	pcsaHeader->Add("'  running environment and run the application by following these instructions:");
	pcsaHeader->Add("'     1. What product / componentes must be installed?  If it is important, where must");
	pcsaHeader->Add("'        this file be placed and how should it be launched?");
	pcsaHeader->Add("'     2. ");
	pcsaHeader->Add("'        ");

	time_t ltime;
	time( &ltime );

	pcsaHeader->Add("'");

	csViewOutStuff.Format( "'   Generated:   %s", ctime( &ltime ) );
	pcsaHeader->Add(csViewOutStuff);

	pcsaHeader->Add("'");

	pcsaHeader->Add("<HTML>");
	pcsaHeader->Add("<HEAD>");
	pcsaHeader->Add("</HEAD>");
	pcsaHeader->Add("<BODY>");
	pcsaHeader->Add("<PRE>");
	pcsaHeader->Add("<%");

	pcsaHeader->Add("");
	pcsaHeader->Add("dim qadll");

	pcsaBody->Add( "");
	pcsaBody->Add( "On Error Resume Next" );
	pcsaBody->Add( "");

	pcsaBody->Add( "   set qadll = server.CreateObject(\"BridgeAPI.BridgeAPIObject.1\")" );
	pcsaBody->Add( "");
	pcsaBody->Add( "   if Err.number <> 0 then" );
	pcsaBody->Add( "       Response.Write \"Error in server.CreateObject\"" );
	pcsaBody->Add( "       Response.Write \"Return Code = \" & Err.number & \"<BR>\"" );
	pcsaBody->Add( "   else" );
	pcsaBody->Add( "       Response.Write \"Successful server.CreateObject \" & \"<BR>\"" );
	pcsaBody->Add( "   end if" );
	pcsaBody->Add( "");

}


void CAG_CICS_QACOM_COM_ASP::appendBody(int nFunctionNum,
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
	else
	{

		csViewOutStuff.Format( " " );
		pcsaBody->Add(csViewOutStuff);

		csViewOutStuff.Format( "   // *** %s", csFunctionName );
		pcsaBody->Add(csViewOutStuff);

		switch ( nFunctionNum )
		{
			case 0:		// ChangePassword
			{
				if ( !b_csIPAddr )
				{
					declareVariable( AG_IP_ADDRESS, pcsaHeader, &b_csIPAddr );
				}
				
				if ( !b_lPort )
				{
					declareVariable( AG_PORT, pcsaHeader, &b_lPort );
				}

				if ( !b_csUserID )
				{
					declareVariable( AG_USER_ID, pcsaHeader, &b_csUserID );
				}

				if ( !b_csPassword )
				{
					declareVariable( AG_PASSWORD, pcsaHeader, &b_csPassword );
				}
				
				if ( !b_csNewPassword )
				{
					declareVariable( AG_NEW_PASSWORD, pcsaHeader, &b_csNewPassword );
				}


				csViewOutStuff.Format( "   csIPAddr = \"%s\"", pcsaArguments->GetAt(1) );
				pcsaBody->Add(csViewOutStuff);

				csViewOutStuff.Format( "   lPort = %s", pcsaArguments->GetAt(2) );
				pcsaBody->Add(csViewOutStuff);

				csViewOutStuff.Format( "   csUserID = \"%s\"", pcsaArguments->GetAt(3) );
				pcsaBody->Add(csViewOutStuff);

				csViewOutStuff.Format( "   csPassword = \"%s\"", pcsaArguments->GetAt(4) );
				pcsaBody->Add(csViewOutStuff);

				csViewOutStuff.Format( "   csNewPassword = \"%s\"", pcsaArguments->GetAt(5) );
				pcsaBody->Add(csViewOutStuff);

				csViewOutStuff.Format( "" );
				pcsaBody->Add(csViewOutStuff);

				csViewOutStuff.Format( "   qadll.ChangePassword csIPAddr, lPort, csUserID, csPassword, csNewPassword" );
				pcsaBody->Add(csViewOutStuff);

				csViewOutStuff.Format( "" );
				pcsaBody->Add(csViewOutStuff);

				if ( b_Debug )
				{
					pcsaBody->Add( "   if Err.number <> 0 then" );
					csViewOutStuff.Format( "      Response.Write \"Error in %s\"", csFunctionName );
					pcsaBody->Add(csViewOutStuff);
					pcsaBody->Add( "      Response.Write \"Return Code = \" & Err.number & \"<BR>\"" );
					pcsaBody->Add( "   else" );
					csViewOutStuff.Format( "      Response.Write \"Successful  %s\" & \"<BR>\"", csFunctionName );
					pcsaBody->Add(csViewOutStuff);
					pcsaBody->Add( "   end if" );
				}
			}
			break;
				
			case 1:		// ConnectBridge
			{

				if ( !b_csIPAddr )
				{
					declareVariable( AG_IP_ADDRESS, pcsaHeader, &b_csIPAddr );
				}
				
				if ( !b_lPort )
				{
					declareVariable( AG_PORT, pcsaHeader, &b_lPort );
				}

				if ( !b_lTermModel )
				{
					declareVariable( AG_MODEL, pcsaHeader, &b_lTermModel );
				}

				if ( !b_csUserID )
				{
					declareVariable( AG_USER_ID, pcsaHeader, &b_csUserID );
				}

				if ( !b_csPassword )
				{
					declareVariable( AG_PASSWORD, pcsaHeader, &b_csPassword );
				}
				
				if ( !b_csTerminalPool )
				{
					declareVariable( AG_TERMINAL_POOL, pcsaHeader, &b_csTerminalPool );
				}
				
				if ( !b_csNetworkName )
				{
					declareVariable( AG_NETWORK_NAME, pcsaHeader, &b_csNetworkName );
				}
				
				if ( !b_TerminalFacilityLike )
				{
					declareVariable( AG_TERMINAL_FACILITY_LIKE, pcsaHeader, &b_TerminalFacilityLike );
				}
				

				csViewOutStuff.Format( "   csIPAddr = \"%s\"", pcsaArguments->GetAt(1) );
				pcsaBody->Add(csViewOutStuff);

				csViewOutStuff.Format( "   lPort = %s", pcsaArguments->GetAt(2) );
				pcsaBody->Add(csViewOutStuff);

				int nModel=0;
				if ( -1 != pcsaArguments->GetAt(3).Find("Model 2") )
				{
					nModel=2;
				}
				else if ( -1 != pcsaArguments->GetAt(3).Find("Model 3") )
				{
					nModel=3;
				}
				else if ( -1 != pcsaArguments->GetAt(3).Find("Model 4") )
				{
					nModel=4;
				}
				else if ( -1 != pcsaArguments->GetAt(3).Find("Model 5") )
				{
					nModel=5;
				}
				else
				{
					nModel=2;
				}
				
				csViewOutStuff.Format( "   lTermModel = %i", nModel );
				pcsaBody->Add(csViewOutStuff);

				csViewOutStuff.Format( "   csUserID = \"%s\"", pcsaArguments->GetAt(4) );
				pcsaBody->Add(csViewOutStuff);

				csViewOutStuff.Format( "   csPassword = \"%s\"", pcsaArguments->GetAt(5) );
				pcsaBody->Add(csViewOutStuff);

				csViewOutStuff.Format( "   csTerminalPool = \"%s\"", pcsaArguments->GetAt(6) );
				pcsaBody->Add(csViewOutStuff);

				csViewOutStuff.Format( "   csNetworkName = \"%s\"", pcsaArguments->GetAt(7) );
				pcsaBody->Add(csViewOutStuff);

				csViewOutStuff.Format( "   TerminalFacilityLike = \"%s\"", pcsaArguments->GetAt(8) );
				pcsaBody->Add(csViewOutStuff);

				csViewOutStuff.Format( "" );
				pcsaBody->Add(csViewOutStuff);

				csViewOutStuff.Format( "   qadll.ConnectBridge csIPAddr, lPort, lTermModel, csUserID, csPassword, csTerminalPool, csNetworkName, TerminalFacilityLike" );
				pcsaBody->Add(csViewOutStuff);

				csViewOutStuff.Format( "" );
				pcsaBody->Add(csViewOutStuff);

				if ( b_Debug )
				{
					pcsaBody->Add( "   if Err.number <> 0 then" );
					csViewOutStuff.Format( "      Response.Write \"Error in %s\"", csFunctionName );
					pcsaBody->Add(csViewOutStuff);
					pcsaBody->Add( "      Response.Write \"Return Code = \" & Err.number & \"<BR>\"" );
					pcsaBody->Add( "   else" );
					csViewOutStuff.Format( "      Response.Write \"Successful  %s\" & \"<BR>\"", csFunctionName );
					pcsaBody->Add(csViewOutStuff);
					pcsaBody->Add( "   end if" );
				}

			}
			break;
				
			case 2:		// Disconnect
			{
				csViewOutStuff.Format( "   qadll.Disconnect" );
				pcsaBody->Add(csViewOutStuff);

				if ( b_Debug )
				{
					pcsaBody->Add( "   if Err.number <> 0 then" );
					csViewOutStuff.Format( "      Response.Write \"Error in %s\"", csFunctionName );
					pcsaBody->Add(csViewOutStuff);
					pcsaBody->Add( "      Response.Write \"Return Code = \" & Err.number & \"<BR>\"" );
					pcsaBody->Add( "   else" );
					csViewOutStuff.Format( "      Response.Write \"Successful  %s\" & \"<BR>\"", csFunctionName );
					pcsaBody->Add(csViewOutStuff);
					pcsaBody->Add( "   end if" );
				}

				csViewOutStuff.Format( "" );
				pcsaBody->Add(csViewOutStuff);
			}
			break;

			case 19:	// SendKeys
			{
				if ( !b_csKeys )
				{
					declareVariable( AG_KEYS, pcsaHeader, &b_csKeys );
				}

				csViewOutStuff.Format( "   csKeys = \"%s\"", pcsaArguments->GetAt(1) );
				pcsaBody->Add(csViewOutStuff);

				csViewOutStuff.Format( "" );
				pcsaBody->Add(csViewOutStuff);

				csViewOutStuff.Format( "   qadll.SendKeys csKeys" );
				pcsaBody->Add(csViewOutStuff);

				csViewOutStuff.Format( "" );
				pcsaBody->Add(csViewOutStuff);

				if ( b_Debug )
				{
					pcsaBody->Add( "   if Err.number <> 0 then" );
					csViewOutStuff.Format( "      Response.Write \"Error in %s\"", csFunctionName );
					pcsaBody->Add(csViewOutStuff);
					pcsaBody->Add( "      Response.Write \"Return Code = \" & Err.number & \"<BR>\"" );
					pcsaBody->Add( "   else" );
					csViewOutStuff.Format( "      Response.Write \"Successful  %s\" & \"<BR>\"", csFunctionName );
					pcsaBody->Add(csViewOutStuff);
					pcsaBody->Add( "   end if" );
				}

			}
			break;


			case 22:	// SendKeysGetString
			{
				if ( !b_csKeys )
				{
					declareVariable( AG_KEYS, pcsaHeader, &b_csKeys );
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
				
				if ( !b_csOutText )
				{
					declareVariable( AG_OUTTEXT, pcsaHeader, &b_csOutText );
				}


				csViewOutStuff.Format( "   csKeys = \"%s\"", pcsaArguments->GetAt(1) );
				pcsaBody->Add(csViewOutStuff);

				csViewOutStuff.Format( "   nRow = %s", pcsaArguments->GetAt(2) );
				pcsaBody->Add(csViewOutStuff);

				csViewOutStuff.Format( "   nColumn = %s", pcsaArguments->GetAt(3) );
				pcsaBody->Add(csViewOutStuff);

				csViewOutStuff.Format( "   nLength = %s", pcsaArguments->GetAt(4) );
				pcsaBody->Add(csViewOutStuff);

				csViewOutStuff.Format( "" );
				pcsaBody->Add(csViewOutStuff);

				csViewOutStuff.Format( "   qadll.SendKeysGetString csKeys, nRow, nColumn, nLength, csOutText" );
				pcsaBody->Add(csViewOutStuff);

				csViewOutStuff.Format( "" );
				pcsaBody->Add(csViewOutStuff);

				if ( b_Debug )
				{
					pcsaBody->Add( "   if Err.number <> 0 then" );
					csViewOutStuff.Format( "      Response.Write \"Error in %s\"", csFunctionName );
					pcsaBody->Add(csViewOutStuff);
					pcsaBody->Add( "      Response.Write \"Return Code = \" & Err.number & \"<BR>\"" );
					pcsaBody->Add( "   else" );
					csViewOutStuff.Format( "      Response.Write \"Successful  %s\" & \"<BR>\"", csFunctionName );
					pcsaBody->Add(csViewOutStuff);
					pcsaBody->Add( "   end if" );
				}

			}
			break;

			case 3:		// FindString
			{
				if ( !b_csScreen )
				{
					declareVariable( AG_SCREEN, pcsaHeader, &b_csScreen );
				}
				
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

				if ( !b_nFlag )
				{
					declareVariable( AG_FLAG, pcsaHeader, &b_nFlag );
				}

				if ( !b_nOutRow )
				{
					declareVariable( AG_OUTROW, pcsaHeader, &b_nOutRow );
				}

				if ( !b_nOutColumn )
				{
					declareVariable( AG_OUTCOLUMN, pcsaHeader, &b_nOutColumn );
				}

				csViewOutStuff.Format( "   csScreen = \"%s\"", pcsaArguments->GetAt(1) );
				pcsaBody->Add(csViewOutStuff);

				csViewOutStuff.Format( "   cString = %s", pcsaArguments->GetAt(2) );
				pcsaBody->Add(csViewOutStuff);

				csViewOutStuff.Format( "   nRow = %s", pcsaArguments->GetAt(3) );
				pcsaBody->Add(csViewOutStuff);

				csViewOutStuff.Format( "   nColumn = %s", pcsaArguments->GetAt(4) );
				pcsaBody->Add(csViewOutStuff);

				int nLocalFlag=0;
				if ( -1 != pcsaArguments->GetAt(5).Find("Wrap") )
				{
					nLocalFlag+=1;
				}
				
				if ( -1 != pcsaArguments->GetAt(5).Find("Backwards") )
				{
					nLocalFlag+=2;
				}

				if ( -1 != pcsaArguments->GetAt(5).Find("field") )
				{
					nLocalFlag+=4;
				}

				if ( -1 != pcsaArguments->GetAt(5).Find("Ignore") )
				{
					nLocalFlag+=8;
				}

				csViewOutStuff.Format( "   nFlag = %i", nLocalFlag );
				pcsaBody->Add(csViewOutStuff);

				csViewOutStuff.Format( "" );
				pcsaBody->Add(csViewOutStuff);

				csViewOutStuff.Format( "   qadll.FindString csScreen, cString, nRow, nColumn, nFlag, nOutRow, nOutColumn" );
				pcsaBody->Add(csViewOutStuff);

				csViewOutStuff.Format( "" );
				pcsaBody->Add(csViewOutStuff);

				if ( b_Debug )
				{
					pcsaBody->Add( "   if Err.number <> 0 then" );
					csViewOutStuff.Format( "      Response.Write \"Error in %s\"", csFunctionName );
					pcsaBody->Add(csViewOutStuff);
					pcsaBody->Add( "      Response.Write \"Return Code = \" & Err.number & \"<BR>\"" );
					pcsaBody->Add( "   else" );
					csViewOutStuff.Format( "      Response.Write \"Successful  %s\" & \"<BR>\"", csFunctionName );
					pcsaBody->Add(csViewOutStuff);
					pcsaBody->Add( "   end if" );
				}

			}
			break;



			case 4:		// GetAllFieldInformation
			case 5:		// GetConnectionStatus
			case 6:		// GetCurrentScreenName
			case 7:		// GetCursorPosition
			case 8:		// GetFieldAttributes
			case 9:		// GetFieldCoordinates
			case 10:	// GetFieldCount
			case 11:	// GetFieldNameFromIndex
			case 12:	// GetFieldValue
			case 13:	// GetScreenSize
			case 14:	// GetString
			case 15:	// GetTransactionSystemId
			case 16:	// Initialize
			case 17:	// Pause
			case 18:	// PutString
			case 20:	// SendKeysEx
			case 21:	// SendKeysGetAllFieldInformation
			

			case 23:	// SetCursorPosition
			case 24:	// SetFieldValue
			case 25:	// SetSettleTime
			case 26:	// SetTimeOut
			case 27:	// SetTraceActive
			case 28:	// SetTraceInactive
			case 29:	// SetTraceName
			case 30:	// Terminate
			{
				csViewOutStuff.Format( "   // APIGen has not yet implemented this method." );
				pcsaBody->Add(csViewOutStuff);
			}
			break;

			default:
			{
				pcsaArguments->Add( "DANGER" );
				pcsaArguments->Add( "DANGER" );
				pcsaArguments->Add( "BIG" );
				pcsaArguments->Add( "PROBLEMS" );
				pcsaArguments->Add( "LIE" );
				pcsaArguments->Add( "AHEAD" );
			}
			break;
		}

	}

	pcsaArguments->RemoveAll();

}


void CAG_CICS_QACOM_COM_ASP::finalize(CStringArray* pcsaBody)
{
	CString csViewOutStuff;

	csViewOutStuff.Format( " " );
	pcsaBody->Add(csViewOutStuff);

	pcsaBody->Add( "   set qadll = nothing" );

	if ( b_csIPAddr )
	{
		pcsaBody->Add( "   set csIPAddr = nothing" );
	}

	if ( b_lPort )
	{
		pcsaBody->Add( "   set lPort = nothing" );
	}

	if ( b_lTermModel )
	{
		pcsaBody->Add( "   set lTermModel = nothing" );
	}

	if ( b_csUserID )
	{
		pcsaBody->Add( "   set csUserID = nothing" );
	}

	if ( b_csPassword )
	{
		pcsaBody->Add( "   set csPassword = nothing" );
	}

	if ( b_csNewPassword )
	{
		pcsaBody->Add( "   set csNewPassword = nothing" );
	}

	if ( b_csTerminalPool )
	{
		pcsaBody->Add( "   set csTerminalPool = nothing" );
	}

	if ( b_csScreen )
	{
		pcsaBody->Add( "   set csScreen = nothing" );
	}

	if ( b_cString )
	{
		pcsaBody->Add( "   set cString = nothing" );
	}

	if ( b_csNetworkName )
	{
		pcsaBody->Add( "   set csNetworkName = nothing" );
	}

	if ( b_TerminalFacilityLike )
	{
		pcsaBody->Add( "   set TerminalFacilityLike = nothing" );
	}


	if ( b_csKeys )
	{
		pcsaBody->Add( "   set csKeys = nothing" );
	}

	if ( b_nRow )
	{
		pcsaBody->Add( "   set nRow = nothing" );
	}

	if ( b_nColumn )
	{
		pcsaBody->Add( "   set nColumn = nothing" );
	}

	if ( b_nLength )
	{
		pcsaBody->Add( "   set nLength = nothing" );
	}

	if ( b_csOutText )
	{
		pcsaBody->Add( "   set csOutText = nothing" );
	}

	if ( b_nFlag )
	{
		pcsaBody->Add( "   set nFlag = nothing" );
	}

	if ( b_nOutRow )
	{
		pcsaBody->Add( "   set nOutRow = nothing" );
	}

	if ( b_nOutColumn )
	{
		pcsaBody->Add( "   set nOutColumn = nothing" );
	}
	

	pcsaBody->Add( "" );
	pcsaBody->Add( "   session.Abandon" );
	pcsaBody->Add( "" );
	pcsaBody->Add( "%>" );
	pcsaBody->Add( "</PRE>" );
	pcsaBody->Add( "</BODY>" );
	pcsaBody->Add( "</HTML>" );

}


void CAG_CICS_QACOM_COM_ASP::declareVariable(AG_VARIABLE agVariable,
											 CStringArray* pcsaHeader,
											 bool* bValue)
{
	CString csLocal;
	*bValue = TRUE;
	
	switch ( agVariable )
	{
		case AG_IP_ADDRESS:
		{
			csLocal.Format( "Dim csIPAddr");
		}
		break;

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

		case AG_FLAG:
		{
			csLocal.Format( "Dim nFlag");
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

		case AG_OUTROW:
		{
			csLocal.Format( "Dim nOutRow" );
		}
		break;

		case AG_OUTCOLUMN:
		{
			csLocal.Format( "Dim nOutColumn" );
		}
		break;

		case AG_ATTRIBUTE:
		{
			csLocal.Format( "Dim nAttribute");
		}
		break;

		
		case AG_ATTRIBUTE_ARRAY:
		{
			csLocal.Format( "Dim csaAttributes As AppConnStringMap");
		}
		break;

		case AG_KEYS:
		{
			csLocal.Format( "Dim csKeys");
		}
		break;

		case AG_LENGTH:
		{
			csLocal.Format( "Dim nLength");
		}
		break;

		case AG_OUTTEXT:
		{
			csLocal.Format( "Dim csOutText");
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

		case AG_SCREEN:
		{
			csLocal.Format( "Dim csScreen");
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

		case AG_FIELD_NAMES:
		{
			csLocal.Format( "Dim csaFieldNames" );
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
			csLocal.Format( "Dim lTermModel" );
		}
		break;

		case AG_MODEL_VARIABLE:	
		{
			csLocal.Format( "Dim csaModelVariable As AppConnStringMap" );
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
			csLocal.Format( "Dim lPort" );
		}
		break;

		case AG_KEY:
		{
			csLocal.Format( "Dim nKey" );
		}
		break;

		case AG_SESSION:
		{
			csLocal.Format( "Dim csSession" );
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
			csLocal.Format( "Dim csaDataInputValues As AppConnStringMap" );
		}
		break;

		case AG_FILTER:
		{
			csLocal.Format( "Dim csFilter" );
		}
		break;

		case AG_FILTER_LIST:
		{
			csLocal.Format( "Dim csaFilterList As AppConnStringList" );
		}
		break;

		case AG_CASE_SENSITIVE:
		{
			csLocal.Format( "Dim bCaseSensitive" );
		}
		break;

		case AG_OUTPUT_COLNAMES:
		{
			csLocal.Format( "Dim csOutputColNames As AppConnStringList" );
		}
		break;

		case AG_MAX_ROWS:
		{
			csLocal.Format( "Dim nMaxRows" );
		}
		break;

		case AG_USER_ID:
		{
			csLocal.Format( "Dim csUserID" );
		}
		break;

		case AG_PASSWORD:
		{
			csLocal.Format( "Dim csPassword" );
		}
		break;
	
		case AG_NEW_PASSWORD:
		{
			csLocal.Format( "Dim csNewPassword" );
		}
		break;

		case AG_RECORDMAP:
		{
			csLocal.Format( "Dim csaRecord As AppConnStringMap" );
		}
		break;

		case AG_RECORDSET:
		{
			csLocal.Format( "Dim RecordSet As AppConnRecordSet" );
		}
		break;

		case AG_ATTRIBUTE_NAMES:
		{
			csLocal.Format( "Dim csaAttributeNames As AppConnStringList" );
		}
		break;

		case AG_MODEL_RECORD:
		{
			csLocal.Format( "Dim ModelRecord As AppConnModelRecord" );
		}
		break;

		case AG_TERMINAL_POOL:
		{
			csLocal.Format( "Dim csTerminalPool" );
		}
		break;

		case AG_TERMINAL_FACILITY_LIKE:
		{
			csLocal.Format( "Dim TerminalFacilityLike" );
		}
		break;

	}

	pcsaHeader->Add(csLocal);
	
}

void CAG_CICS_QACOM_COM_ASP::checkDebug(bool b_Debug,
										CString csFunctionName,
										CStringArray* pcsaBody)
{
	
}


void CAG_CICS_QACOM_COM_ASP::resetVariableFlags()
{
	b_Debug=FALSE;

	b_csIPAddr=FALSE;
	b_lPort=FALSE;
	b_csUserID=FALSE;
	b_csPassword=FALSE;
	b_csNewPassword=FALSE;
	b_lTermModel=FALSE;
	b_csTerminalPool=FALSE;
	b_csNetworkName=FALSE;
	b_TerminalFacilityLike=FALSE;
	b_csKeys=FALSE;
	b_nRow=FALSE;
	b_nOutRow=FALSE;
	b_nColumn=FALSE;
	b_nOutColumn=FALSE;
	b_nLength=FALSE;
	b_csOutText=FALSE;
	b_csScreen=FALSE;
	b_cString=FALSE;
	b_nFlag=FALSE;

}