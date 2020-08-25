// Static Model
#include "stdafx.h"
#include "apigen.h"

#include "CAG_ROLE_3270_ASP.h"

CAG_ROLE_3270_ASP::CAG_ROLE_3270_ASP()
{
	resetVariableFlags();	
}

CAG_ROLE_3270_ASP::~CAG_ROLE_3270_ASP()
{
	
}

void CAG_ROLE_3270_ASP::declareVariable(AG_VARIABLE agVariable,
										CStringArray* pcsaHeader,
										bool* bValue)
{
	
}


void CAG_ROLE_3270_ASP::generateHeader(CStringArray* pcsaHeader,
									   CStringArray* pcsaBody)
{

	CString csViewOutStuff;

	csViewOutStuff.Format( "//  ****************************************************************************");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "//                 Attachmate APIGen");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "//               Reflection For 3270 for Active Server Pages");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "// ");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "//  This file is a program that features the use of the Reflection for 3270");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "//  API written in Active Server Pages.  This header is to include information");
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


void CAG_ROLE_3270_ASP::appendBody(int nFunctionNum,
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


	csViewOutStuff.Format( "   // APIGen has not yet implemented this method." );
	pcsaBody->Add(csViewOutStuff);

	pcsaArguments->RemoveAll();
}


void CAG_ROLE_3270_ASP::finalize(CStringArray* pcsaBody)
{
	CString csViewOutStuff;

	csViewOutStuff.Format( "" );
	pcsaBody->Add(csViewOutStuff);

	csViewOutStuff.Format( "");
	pcsaBody->Add(csViewOutStuff);

	csViewOutStuff.Format( "} " );
	pcsaBody->Add(csViewOutStuff);

}

void CAG_ROLE_3270_ASP::checkDebug(bool b_Debug,
							 CString csFunctionName,
							 CStringArray* pcsaBody)
{
	
}




void CAG_ROLE_3270_ASP::resetVariableFlags()
{
}

