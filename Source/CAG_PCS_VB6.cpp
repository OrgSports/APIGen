// Static Model
#include "stdafx.h"
#include "apigen.h"

#include "CAG_PCS_VB6.h"

CAG_PCS_VB6::CAG_PCS_VB6()
{
	resetVariableFlags();	
}

CAG_PCS_VB6::~CAG_PCS_VB6()
{
	
}

void CAG_PCS_VB6::declareVariable(AG_VARIABLE agVariable,
								  CStringArray* pcsaHeader,
								  bool* bValue)
{
	
}


void CAG_PCS_VB6::generateHeader(CStringArray* pcsaHeader,
								 CStringArray* pcsaBody)
{
    // output to Translator's output window
	CString csViewOutStuff;

    pcsaHeader->Add("'****************************************************************************");
    pcsaHeader->Add("'");
    pcsaHeader->Add("'  Attachmate APIGEN recorded PCSHLLAPI test program for Visual Basic 6.0");
    pcsaHeader->Add("'");
    pcsaHeader->Add("'  Follow these steps to run this program:");
    pcsaHeader->Add("'      1. Create and save a new VB6 \"standard exe\" project.");
    pcsaHeader->Add("'      2. \"Add\" this .bas module file to the project.");
    pcsaHeader->Add("'      3. On the \"Project\" menu, choose \"<project> Properties...\", and ");
    pcsaHeader->Add("'         and switch the \"Startup Object\" to \"Sub Main\".");
    pcsaHeader->Add("'      4. To view HLLAPI return values, start the EXTRA! \"Status\" utility");
    pcsaHeader->Add("'         and make sure it is active before running this program."); 
   	
	time_t ltime;
	time( &ltime );

	pcsaHeader->Add( "'");

	csViewOutStuff.Format( "'   Generated:   %s", ctime( &ltime ) );
	pcsaHeader->Add(csViewOutStuff);

	pcsaHeader->Add("'");	
	pcsaHeader->Add("'****************************************************************************");
	pcsaHeader->Add(" ");
    pcsaHeader->Add("Declare Sub HLLAPI Lib \"pcshll32.dll\" (nFunc%, ByVal sDataStr$, nDatalen%, nRetCode%)");
    pcsaHeader->Add(" ");
    pcsaHeader->Add(" ");
    pcsaHeader->Add("Sub Main");
    pcsaHeader->Add("   Dim nFunc%, sDataStr$, nDataLen%, nRetCode%");
    pcsaHeader->Add("   sDataStr$ = Space(7128)  'insure adequate room in buffer when retrieving screen data");
    pcsaHeader->Add(" ");

	
}

void CAG_PCS_VB6::appendBody(int nFunctionNum,
							 bool bPromptForValues,
							 CStringArray* pcsaArguments,
							 CStringArray* pcsaHeader,
							 CStringArray* pcsaBody)
{
    CString csViewOutStuff;
	CString csFunctionName, csFunctionNum, csString, csStringLength, csRetCode;


	if ( bPromptForValues )
	{
		csFunctionName = pcsaArguments->GetAt( 0 );
		csFunctionNum = pcsaArguments->GetAt( 1 );
		csString = pcsaArguments->GetAt( 2 );
		csStringLength = pcsaArguments->GetAt( 3 );
		csRetCode = pcsaArguments->GetAt( 4 );
	}
	else
	{
		csFunctionName = pcsaArguments->GetAt( 0 );
		csFunctionNum = pcsaArguments->GetAt(1);
		csString = pcsaArguments->GetAt(2);
		csStringLength = pcsaArguments->GetAt(3);
		csRetCode = pcsaArguments->GetAt(4);
	}

	csViewOutStuff.Format( "''''Function: %s", csFunctionName.MakeUpper() );
	pcsaBody->Add(csViewOutStuff);

	
	csViewOutStuff.Format( "   nFunc%% = %s", csFunctionNum );
	pcsaBody->Add(csViewOutStuff);

	csViewOutStuff.Format( "   sDataStr$ = \"%s\"", csString );
	pcsaBody->Add(csViewOutStuff);

	csViewOutStuff.Format( "   nDataLen%% = %s", csStringLength );
	pcsaBody->Add(csViewOutStuff);

	csViewOutStuff.Format( "   nRetCode%% = %s", csRetCode );
	pcsaBody->Add(csViewOutStuff);

	pcsaBody->Add( "   HLLAPI nFunc%, sDataStr$, nDataLen%, nRetCode%"  );			
    pcsaBody->Add(" ");					


	pcsaArguments->RemoveAll();
	
}

void CAG_PCS_VB6::finalize(CStringArray* pcsaBody)
{
	pcsaBody->Add("End Sub");
}

void CAG_PCS_VB6::checkDebug(bool b_Debug,
									   CString csFunctionName,
									   CStringArray* pcsaBody)
{
}




void CAG_PCS_VB6::resetVariableFlags()
{
}

