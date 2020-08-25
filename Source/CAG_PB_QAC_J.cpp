// Static Model
#include "stdafx.h"
#include "apigen.h"

#include "CAG_PB_QAC_J.h"

CAG_PB_QAC_J::CAG_PB_QAC_J()
{
	resetVariableFlags();
}

CAG_PB_QAC_J::~CAG_PB_QAC_J()
{
	
}

void CAG_PB_QAC_J::declareVariable(AG_VARIABLE agVariable,
								   CStringArray* pcsaHeader,
								   bool* bValue)
{
	
}


void CAG_PB_QAC_J::generateHeader(CStringArray* pcsaHeader,
								  CStringArray* pcsaBody)
{

	CString csViewOutStuff;

	csViewOutStuff.Format( "//  ****************************************************************************");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "//                 Attachmate APIGen");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "//               Presentation Builder QACom Java Program");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "// ");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "//  This file is a program that features the use of the Presentation Builder");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "//  QACom API written in Java.  This header is to include information");
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


void CAG_PB_QAC_J::appendBody(int nFunctionNum,
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


void CAG_PB_QAC_J::finalize(CStringArray* pcsaBody)
{
	CString csViewOutStuff;

	csViewOutStuff.Format( " " );
	pcsaBody->Add(csViewOutStuff);

	csViewOutStuff.Format( "}");
	pcsaBody->Add(csViewOutStuff);

	csViewOutStuff.Format( " " );
	pcsaBody->Add(csViewOutStuff);

}

void CAG_PB_QAC_J::checkDebug(bool b_Debug,
									   CString csFunctionName,
									   CStringArray* pcsaBody)
{
}




void CAG_PB_QAC_J::resetVariableFlags()
{
}
