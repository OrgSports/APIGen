// Static Model
#include "stdafx.h"
#include "apigen.h"

#include "CAG_ROLE_3270_XLS.h"
#include "time.h"

CAG_ROLE_3270_XLS::CAG_ROLE_3270_XLS()
{
	resetVariableFlags();	
}

CAG_ROLE_3270_XLS::~CAG_ROLE_3270_XLS()
{
	
}

void CAG_ROLE_3270_XLS::declareVariable(AG_VARIABLE agVariable,
										CStringArray* pcsaHeader,
										bool* bValue)
{
	
}


void CAG_ROLE_3270_XLS::generateHeader(CStringArray* pcsaHeader,
									   CStringArray* pcsaBody)
{

	CString csViewOutStuff;

	csViewOutStuff.Format( "//  ****************************************************************************");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "//                 Attachmate APIGen");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "//               Reflection For 3270 Excel Automation Script");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "// ");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "//  This file is a program that features the use of the Reflection for 3270");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "//  API written in Visual Basic For Applications for Excel.  This header is to include information");
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


void CAG_ROLE_3270_XLS::appendBody(int nFunctionNum,
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


void CAG_ROLE_3270_XLS::finalize(CStringArray* pcsaBody)
{
	CString csViewOutStuff;

	csViewOutStuff.Format( "" );
	pcsaBody->Add(csViewOutStuff);

	csViewOutStuff.Format( "End Sub");
	pcsaBody->Add(csViewOutStuff);

	csViewOutStuff.Format( "" );
	pcsaBody->Add(csViewOutStuff);

}

void CAG_ROLE_3270_XLS::checkDebug(bool b_Debug,
								   CString csFunctionName,
								   CStringArray* pcsaBody)
{
	
}

void CAG_ROLE_3270_XLS::resetVariableFlags()
{
}

