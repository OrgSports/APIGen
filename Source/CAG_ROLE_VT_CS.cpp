// Static Model
#include "stdafx.h"
#include "apigen.h"

#include "CAG_ROLE_VT_CS.h"

CAG_ROLE_VT_CS::CAG_ROLE_VT_CS()
{
	resetVariableFlags();	
}

CAG_ROLE_VT_CS::~CAG_ROLE_VT_CS()
{
	
}

void CAG_ROLE_VT_CS::declareVariable(AG_VARIABLE agVariable,
									 CStringArray* pcsaHeader,
									 bool* bValue)
{
	
}


void CAG_ROLE_VT_CS::generateHeader(CStringArray* pcsaHeader,
									CStringArray* pcsaBody)
{

	CString csViewOutStuff;

	csViewOutStuff.Format( "//  ****************************************************************************");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "//                        Attachmate APIGen");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "//                    Reflection For VT C# Program");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "// ");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "//  This file is a program that features the use of the Reflection for VT");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "//  API written in C#.  This header is to include information");
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


void CAG_ROLE_VT_CS::appendBody(int nFunctionNum,
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


void CAG_ROLE_VT_CS::finalize(CStringArray* pcsaBody)
{
	CString csViewOutStuff;

	csViewOutStuff.Format( " " );
	pcsaBody->Add(csViewOutStuff);

	csViewOutStuff.Format( "   return;");
	pcsaBody->Add(csViewOutStuff);

	csViewOutStuff.Format( "} " );
	pcsaBody->Add(csViewOutStuff);

}

void CAG_ROLE_VT_CS::checkDebug(bool b_Debug,
								   CString csFunctionName,
								   CStringArray* pcsaBody)
{
	
}

void CAG_ROLE_VT_CS::resetVariableFlags()
{
}

