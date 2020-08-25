// Static Model
#include "stdafx.h"
#include "apigen.h"

#include "CAG_CICS_QACOM_COM_VB6.h"

CAG_CICS_QACOM_COM_VB6::CAG_CICS_QACOM_COM_VB6()
{
	resetVariableFlags();	
}

CAG_CICS_QACOM_COM_VB6::~CAG_CICS_QACOM_COM_VB6()
{
	
}

void CAG_CICS_QACOM_COM_VB6::generateHeader(CStringArray* pcsaHeader,
											CStringArray* pcsaBody)
{

	CString csViewOutStuff;

	csViewOutStuff.Format( "//  ****************************************************************************");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "//                        Attachmate APIGen");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "//                    CICS Bridge VB6.0 Program");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "// ");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "//  This file is a program that features the use of the Attachmate");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "//  CICS Bridge QACom API written in Visual Basic 6.0.  This header is");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "//  to include information on how to set up the environment to run this");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "//  application, how to build it, and how to run it.");
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


void CAG_CICS_QACOM_COM_VB6::appendBody(int nFunctionNum,
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


void CAG_CICS_QACOM_COM_VB6::finalize(CStringArray* pcsaBody)
{
	CString csViewOutStuff;

	csViewOutStuff.Format( " " );
	pcsaBody->Add(csViewOutStuff);

	csViewOutStuff.Format( "End Sub" );
	pcsaBody->Add(csViewOutStuff);

}
void CAG_CICS_QACOM_COM_VB6::declareVariable(AG_VARIABLE agVariable,
											 CStringArray* pcsaHeader,
											 bool* bValue)
{
	
}

void CAG_CICS_QACOM_COM_VB6::checkDebug(bool b_Debug,
										CString csFunctionName,
										CStringArray* pcsaBody)
{
	
}

void CAG_CICS_QACOM_COM_VB6::resetVariableFlags()
{
}