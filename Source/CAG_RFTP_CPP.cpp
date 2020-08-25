// Static Model
#include "stdafx.h"
#include "apigen.h"

#include "CAG_RFTP_CPP.h"
#include "time.h"


CAG_RFTP_CPP::CAG_RFTP_CPP()
{
	resetVariableFlags();	
}

CAG_RFTP_CPP::~CAG_RFTP_CPP()
{
	
}

void CAG_RFTP_CPP::generateHeader(CStringArray* pcsaHeader,
								  CStringArray* pcsaBody)
{

	CString csViewOutStuff;

	pcsaHeader->Add("//  ****************************************************************************");
	pcsaHeader->Add("//                 Attachmate APIGen");
	pcsaHeader->Add("//               Reflection FTP C++ Program");
	pcsaHeader->Add("// ");
	pcsaHeader->Add("//  This program features the use of the Reflection FTP API written");
	pcsaHeader->Add("//  in C++.  As it becomes known this header will include information");
	pcsaHeader->Add("//  covering how to set up the RFTP application and running environment,");
	pcsaHeader->Add("//   and then how to build and run this application.");

	time_t ltime;
	time( &ltime );

	pcsaHeader->Add("//");

	csViewOutStuff.Format( "//   Generated:   %s", ctime( &ltime ) );
	pcsaHeader->Add(csViewOutStuff);

	pcsaHeader->Add("//");
	pcsaHeader->Add("//");
	pcsaHeader->Add("//");
	pcsaHeader->Add("// ****************************************************************************");
	
	pcsaHeader->Add("#include <windows.h>");
	pcsaHeader->Add("#include <stdio.h>");
	pcsaHeader->Add("");
	pcsaHeader->Add("   FTPObject ftpObj;");
	pcsaHeader->Add("");
	pcsaHeader->Add("int main(int argc, CHAR* argv[])");
	pcsaHeader->Add("{");
	pcsaHeader->Add("");

	pcsaBody->Add("");

}

void CAG_RFTP_CPP::appendBody(int nFunctionNum,
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
		
		case 0:		// Close
		{
			csViewOutStuff.Format( "   ftpObj->Close();" );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( " " );
			pcsaBody->Add(csViewOutStuff);
		}
		break;

		case 1:		// CloseDirectoryListing
		{
			csViewOutStuff.Format( "   ftpObj->CloseDirectoryListing();" );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( " " );
			pcsaBody->Add(csViewOutStuff);
		}
		break;

		case 2:		// Connect
		{
			if ( !b_nRetVal )
			{
				declareVariable( AG_RETURN_CODE, pcsaHeader, &b_nRetVal );
			}

			csViewOutStuff.Format( "   nRetVal = ftpObj->Connect( %s, %s, %s);", pcsaArguments->GetAt(1), pcsaArguments->GetAt(2), pcsaArguments->GetAt(3));
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( " " );
			pcsaBody->Add(csViewOutStuff);

		}
		break;

		case 3:		// CreateDirectory
		{
			csViewOutStuff.Format( "   CreateDirectory( \"%s\" );", pcsaArguments->GetAt(1) );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( " " );
			pcsaBody->Add(csViewOutStuff);
		}
		break;

		case 4:		// DeleteDirectory
		{
			csViewOutStuff.Format( "   DeleteDirectory( \"%s\" );", pcsaArguments->GetAt(1) );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( " " );
			pcsaBody->Add(csViewOutStuff);
		}
		break;

		case 5:		// DeleteFile
		{
			csViewOutStuff.Format( "   DeleteFile( \"%s\" );", pcsaArguments->GetAt(1) );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( " " );
			pcsaBody->Add(csViewOutStuff);
		}
		break;

		case 6:		// ExecuteFTPCommand
		{
			if ( !b_nResponse )
			{
				declareVariable( AG_RESPONSE, pcsaHeader, &b_nResponse );
			}

			csViewOutStuff.Format( "   nResponse = ftpObj->ExecuteFTPCommand( \"%s\" );", pcsaArguments->GetAt(1) );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( " " );
			pcsaBody->Add(csViewOutStuff);
		}
		break;

		case 7:		// GetCurrentDirectory
		{
			if ( !b_csRemoteDir )
			{
				declareVariable( AG_REMOTE_DIR, pcsaHeader, &b_csRemoteDir );
			}

			csViewOutStuff.Format( "   csRemoteDir = ftpObj->GetCurrentDirectory();" );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( " " );
			pcsaBody->Add(csViewOutStuff);
		}
		break;

		case 8:		// GetNextFileDetails
		{
			if ( !b_bSearching )
			{
				declareVariable( AG_SEARCHING, pcsaHeader, &b_bSearching );
			}

			csViewOutStuff.Format( "   bSearching = ftpObj->GetNextFileDetails();" );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( " " );
			pcsaBody->Add(csViewOutStuff);
		}
		break;

		case 9:		// LoadDefaultSiteProperties
		{
			csViewOutStuff.Format( "   ftpObj->LoadDefaultSiteProperties();" );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( " " );
			pcsaBody->Add(csViewOutStuff);
		}
		break;

		case 10:	// LoadSiteProperties
		{
			csViewOutStuff.Format( "   ftpObj->LoadSiteProperties( \"%s\" );", pcsaArguments->GetAt(1) );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( " " );
			pcsaBody->Add(csViewOutStuff);
		}
		break;

		case 11:	// Open
		{
			csViewOutStuff.Format( "   ftpObj->Open( \"%s\", \"%s\", \"%s\", \"%s\", %s, \"%s\" );", pcsaArguments->GetAt(1),
																									 pcsaArguments->GetAt(2),
																									 pcsaArguments->GetAt(3),
																									 pcsaArguments->GetAt(4),
																									 pcsaArguments->GetAt(5),
																									 pcsaArguments->GetAt(6) );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( " " );
			pcsaBody->Add(csViewOutStuff);
		}
		break;

		case 12:	// OpenDirectoryListing
		{
			csViewOutStuff.Format( "   ftpObj->OpenDirectoryListing( \"%s\" );", pcsaArguments->GetAt(1) );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( " " );
			pcsaBody->Add(csViewOutStuff);
		}
		break;

		case 13:	// ReceiveDirectory
		{
			csViewOutStuff.Format( "   ftpObj->ReceiveDirectory( \"%s\", \"%s\", %s, %s );", pcsaArguments->GetAt(1),
																							 pcsaArguments->GetAt(2),
																							 pcsaArguments->GetAt(3),
																							 pcsaArguments->GetAt(4) );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( " " );
			pcsaBody->Add(csViewOutStuff);
		}
		break;

		case 14:	// ReceiveFile
		{
			csViewOutStuff.Format( "   ftpObj->ReceiveFile( \"%s\", \"%s\", %s, %s );", pcsaArguments->GetAt(1),
																							 pcsaArguments->GetAt(2),
																							 pcsaArguments->GetAt(3),
																							 pcsaArguments->GetAt(4) );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( " " );
			pcsaBody->Add(csViewOutStuff);
		}
		break;

		case 15:	// RenameFile
		{
			csViewOutStuff.Format( "   ftpObj->RenameFile( \"%s\", \"%s\" );", pcsaArguments->GetAt(1), pcsaArguments->GetAt(2) );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( " " );
			pcsaBody->Add(csViewOutStuff);

		}
		break;

		case 16:	// SaveSiteProperties
		{
			csViewOutStuff.Format( "   ftpObj->SaveSiteProperties( \"%s\" );", pcsaArguments->GetAt(1) );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( " " );
			pcsaBody->Add(csViewOutStuff);
		}
		break;

		case 17:	// SendDirectory
		{
			csViewOutStuff.Format( "   ftpObj->SendDirectory( \"%s\", \"%s\", %s, %s );", pcsaArguments->GetAt(1),
																						 pcsaArguments->GetAt(2),
																						 pcsaArguments->GetAt(3),
																						 pcsaArguments->GetAt(4) );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( " " );
			pcsaBody->Add(csViewOutStuff);
		}
		break;

		case 18:	// SendFile
		{
			csViewOutStuff.Format( "   ftpObj->SendFile( \"%s\", \"%s\", %s, %s );", pcsaArguments->GetAt(1),
																					 pcsaArguments->GetAt(2),
																					 pcsaArguments->GetAt(3),
																					 pcsaArguments->GetAt(4) );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( " " );
			pcsaBody->Add(csViewOutStuff);
		}
		break;

		case 19:	// SetCurrentDirectory
		{
			csViewOutStuff.Format( "   ftpObj->SetCurrentDirectory( \"%s\" );", pcsaArguments->GetAt(1) );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( " " );
			pcsaBody->Add(csViewOutStuff);
		}
		break;


		default:
		{
			csViewOutStuff.Format( "   // APIGen has not yet implemented this method." );
			pcsaBody->Add(csViewOutStuff);
		}
		break;
	}
	
	pcsaArguments->RemoveAll();
}



void CAG_RFTP_CPP::finalize(CStringArray* pcsaBody)
{
	CString csViewOutStuff;

	csViewOutStuff.Format( " " );
	pcsaBody->Add(csViewOutStuff);

	csViewOutStuff.Format( "   return;");
	pcsaBody->Add(csViewOutStuff);

	csViewOutStuff.Format( "} " );
	pcsaBody->Add(csViewOutStuff);

}


void CAG_RFTP_CPP::declareVariable(AG_VARIABLE agVariable,
								   CStringArray* pcsaHeader,
								   bool* bValue)
{
	CString csLocal;
	*bValue = TRUE;
	
	switch ( agVariable )
	{

		case AG_RETURN_CODE:
		{
			csLocal.Format( "   int nRetVal;");
		}
		break;

		case AG_RESPONSE:
		{
			csLocal.Format( "   int nResponse;");
		}
		break;

		case AG_REMOTE_DIR:
		{
			csLocal.Format( "   CString csRemoteDir;");
		}
		break;

		case AG_SEARCHING:
		{
			csLocal.Format( "   BOOL bSearching;");
		}
		break;

	}


	pcsaHeader->Add(csLocal);
	
}

void CAG_RFTP_CPP::checkDebug(bool b_Debug,
							  CString csFunctionName,
							  CStringArray* pcsaBody)
{
	
}



void CAG_RFTP_CPP::resetVariableFlags()
{
   b_nRetVal = FALSE;
   b_nResponse = FALSE;
   b_csRemoteDir = FALSE;
   b_bSearching = FALSE;
}

