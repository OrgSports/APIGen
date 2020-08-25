// Static Model
#include "stdafx.h"
#include "apigen.h"

#include "CAG_CICS_QACOM_NET_VBN.h"

CAG_CICS_QACOM_NET_VBN::CAG_CICS_QACOM_NET_VBN()
{
	resetVariableFlags();	
}

CAG_CICS_QACOM_NET_VBN::~CAG_CICS_QACOM_NET_VBN()
{
	
}

void CAG_CICS_QACOM_NET_VBN::generateHeader(CStringArray* pcsaHeader,
											CStringArray* psaBody)
{

	CString csViewOutStuff;

	csViewOutStuff.Format( "//  ****************************************************************************");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "//                        Attachmate APIGen");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "//                    CICS Bridge VB.Net Program");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "// ");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "//  This file is a program that features the use of the Attachmate");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "//  QACom .Net API written in VB.Net.  This header is to include information");
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


void CAG_CICS_QACOM_NET_VBN::appendBody(int nFunctionNum,
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
			

		default:
		{
			csViewOutStuff.Format( "   // APIGen has not yet implemented this method." );
			pcsaBody->Add(csViewOutStuff);
		}
	}

	pcsaArguments->RemoveAll();
}


void CAG_CICS_QACOM_NET_VBN::finalize(CStringArray* pcsaBody)
{
	
}

void CAG_CICS_QACOM_NET_VBN::declareVariable(AG_VARIABLE agVariable,
											 CStringArray* pcsaHeader,
											 bool* bValue)
{
	
}

void CAG_CICS_QACOM_NET_VBN::checkDebug(bool b_Debug,
										CString csFunctionName,
										CStringArray* pcsaBody)
{
	
}

void CAG_CICS_QACOM_NET_VBN::resetVariableFlags()
{
}