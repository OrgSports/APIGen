// Static Model
#include "stdafx.h"
#include "apigen.h"

#include "CAG_RFTP_VBN.h"
#include "time.h"


CAG_RFTP_VBN::CAG_RFTP_VBN()
{
	resetVariableFlags();	
}


CAG_RFTP_VBN::~CAG_RFTP_VBN()
{
	
}


void CAG_RFTP_VBN::generateHeader(CStringArray* pcsaHeader,
								  CStringArray* pcsaBody)
{

	CString csViewOutStuff;

	csViewOutStuff.Format( "'  ****************************************************************************");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "'                 Attachmate APIGen");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "'               Reflection FTP Visual Basic .Net Program");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( " ");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "'  This file is a program that features the use of the Reflection FTP");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "'  API written in Visual Basic .Net.  This header is to include information");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "'  on how to set up the environment to run this application, how to build");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "'  it, and how to run it.");
	pcsaHeader->Add(csViewOutStuff);


	time_t ltime;
	time( &ltime );

	csViewOutStuff.Format( "'");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "'   Generated:   %s", ctime( &ltime ) );
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "'");
	pcsaHeader->Add(csViewOutStuff);


}
void CAG_RFTP_VBN::appendBody(int nFunctionNum,
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

	csViewOutStuff.Format( "   ' *** %s", csFunctionName );
	pcsaBody->Add(csViewOutStuff);


	csViewOutStuff.Format( "   ' APIGen has not yet implemented this method." );
	pcsaBody->Add(csViewOutStuff);

	pcsaArguments->RemoveAll();
}


void CAG_RFTP_VBN::finalize(CStringArray* pcsaBody)
{
	CString csViewOutStuff;

	csViewOutStuff.Format( " " );
	pcsaBody->Add(csViewOutStuff);

	csViewOutStuff.Format( "End Sub");
	pcsaBody->Add(csViewOutStuff);

	csViewOutStuff.Format( " " );
	pcsaBody->Add(csViewOutStuff);

}

void CAG_RFTP_VBN::declareVariable(AG_VARIABLE agVariable,
								   CStringArray* pcsaBody,
								   bool* bValue)
{
	
}

void CAG_RFTP_VBN::checkDebug(bool b_Debug,
							  CString csFunctionName,
							  CStringArray* pcsaBody)
{
	
}


void CAG_RFTP_VBN::resetVariableFlags()
{
}
