// Static Model
#include "stdafx.h"
#include "apigen.h"

#include "CAG_CICS_QACOM_COM_CPP.h"


CAG_CICS_QACOM_COM_CPP::CAG_CICS_QACOM_COM_CPP()
{
	resetVariableFlags();	
}

CAG_CICS_QACOM_COM_CPP::~CAG_CICS_QACOM_COM_CPP()
{
	
}

void CAG_CICS_QACOM_COM_CPP::generateHeader(CStringArray* pcsaHeader,
											CStringArray* pcsaBody)
{

	CString csViewOutStuff;

	csViewOutStuff.Format( "//  ****************************************************************************");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "//                        Attachmate APIGen");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "//                    CICS Bridge C++/COM Program");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "// ");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "//  This file is a program that features the use of the Attachmate");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "//  QACom COM API written in C++.  This header is to include information");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "//  on how to set up the environment to run this application, how to build");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "//  it, and how to run it.");
	pcsaHeader->Add(csViewOutStuff);


	time_t ltime;
	time( &ltime );

	csViewOutStuff.Format( "//");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "//   Generated:   %s", ctime( &ltime ) );
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "//");
	pcsaHeader->Add(csViewOutStuff);


}
void CAG_CICS_QACOM_COM_CPP::appendBody(int nFunctionNum,
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


			csViewOutStuff.Format( "   csIPAddr = \"%s\";", pcsaArguments->GetAt(1) );
			pcsaBody->Add(csViewOutStuff);


			csViewOutStuff.Format( "   lPort = %s;", pcsaArguments->GetAt(2) );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "   csUserID = \"%s\";", pcsaArguments->GetAt(3) );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "   csPassword = \"%s\";", pcsaArguments->GetAt(4) );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "   csNewPassword = \"%s\";", pcsaArguments->GetAt(5) );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "" );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "   ChangePassword( csIPAddr, lPort, csUserID, csPassword, csNewPassword );" );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "" );
			pcsaBody->Add(csViewOutStuff);

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


			csViewOutStuff.Format( "   csIPAddr = \"%s\";", pcsaArguments->GetAt(1) );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "   lPort = %s;", pcsaArguments->GetAt(2) );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "   lTermModel = %s;", pcsaArguments->GetAt(3) );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "   csUserID = \"%s\";", pcsaArguments->GetAt(4) );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "   csPassword = \"%s\";", pcsaArguments->GetAt(5) );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "" );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "   ConnectBridge( csIPAddr, lPort, lTermModel, csUserID, csPassword );" );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "" );
			pcsaBody->Add(csViewOutStuff);

		}
		break;
			
		case 2:		// Disconnect
		{
			csViewOutStuff.Format( "   // APIGen has not yet implemented this method." );
			pcsaBody->Add(csViewOutStuff);
		}
		break;

		case 3:		// FindString
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
		case 19:	// SendKeys
		case 20:	// SendKeysEx
		case 21:	// SendKeysGetAllFieldInformation
		case 22:	// SendKeysGetString
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

	pcsaArguments->RemoveAll();
}


void CAG_CICS_QACOM_COM_CPP::finalize(CStringArray* pcsaBody)
{
	CString csViewOutStuff;

	csViewOutStuff.Format( " " );
	pcsaBody->Add(csViewOutStuff);

	csViewOutStuff.Format( "   return;");
	pcsaBody->Add(csViewOutStuff);

	csViewOutStuff.Format( "} " );
	pcsaBody->Add(csViewOutStuff);

}


void CAG_CICS_QACOM_COM_CPP::declareVariable(AG_VARIABLE agVariable,
											 CStringArray* pcsaHeader,
											 bool* bValue)
{
	CString csLocal;
	*bValue = TRUE;
	
	switch ( agVariable )
	{
		case AG_IP_ADDRESS:
		{
			csLocal.Format( "   CString csIPAddr;");
		}
		break;

		case AG_PORT:
		{
			csLocal.Format( "   long lPort=0;");
		}
		break;

		case AG_USER_ID:
		{
			csLocal.Format( "   CString csUserID;");
		}
		break;

		case AG_PASSWORD:
		{
			csLocal.Format( "   CString csPassword;");
		}
		break;

		case AG_NEW_PASSWORD:
		{
			csLocal.Format( "   CString csNewPassword;");
		}
		break;

		case AG_MODEL:
		{
			csLocal.Format( "   long lTermModel=0;");
		}
		break;

	}

	pcsaHeader->Add(csLocal);

}


void CAG_CICS_QACOM_COM_CPP::checkDebug(bool b_Debug,
										CString csFunctionName,
										CStringArray* pcsaBody)
{
	
}


void CAG_CICS_QACOM_COM_CPP::resetVariableFlags()
{
   b_csIPAddr = FALSE;
   b_lPort = FALSE;
   b_csUserID = FALSE;
   b_csPassword = FALSE;
   b_csNewPassword = FALSE;
   b_lTermModel = FALSE;
}