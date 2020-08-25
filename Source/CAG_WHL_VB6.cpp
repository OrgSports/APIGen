// Static Model
#include "stdafx.h"
#include "apigen.h"

#include "CAG_WHL_VB6.h"

CAG_WHL_VB6::CAG_WHL_VB6()
{
	resetVariableFlags();
}

CAG_WHL_VB6::~CAG_WHL_VB6()
{
	
}


void CAG_WHL_VB6::generateHeader(CStringArray* pcsaHeader,
								 CStringArray* pcsaBody)
{
	// output to Translator's output window
	CString csViewOutStuff;

    pcsaHeader->Add("'****************************************************************************");
    pcsaHeader->Add("'");
    pcsaHeader->Add("'  Attachmate APIGEN recorded WHLLAPI test program for Visual Basic 6.0");
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
    pcsaHeader->Add("''''Essential WinHLLAPI declarations....");
    pcsaHeader->Add("Type StartupData");
    pcsaHeader->Add("   major As Byte");
    pcsaHeader->Add("   minor As Byte");
    pcsaHeader->Add("   Description As String * 128");
    pcsaHeader->Add("End Type");
    pcsaHeader->Add("Declare Sub WinHLLAPI Lib \"WHLAPI32.DLL\"  (nFunc%, ByVal Buffer$, nSize%, nRet%) ");
    pcsaHeader->Add("Declare Function WinHLLAPIStartup Lib \"WHLAPI32.DLL\" (ByVal version%, sdata As StartupData) As Long");
    pcsaHeader->Add("Declare Function WinHLLAPICleanup Lib \"WHLAPI32.DLL\" () As Long");
    pcsaHeader->Add(" ");
    pcsaHeader->Add(" ");
    pcsaHeader->Add("Sub Main");
    pcsaHeader->Add("   Dim nFunc%, sDataStr$, nDataLen%, nRetCode%");
    pcsaHeader->Add("   sDataStr$ = Space(7128)  'insure adequate room in buffer when retrieving screen data");
    pcsaHeader->Add(" ");
    pcsaHeader->Add("   'initialze StartupData for WinHLLAPIStartup call");
    
    pcsaHeader->Add("   Dim sd as StartupData");
    pcsaHeader->Add("   sd.major = 1");
    pcsaHeader->Add("   sd.minor = 1");
    pcsaHeader->Add("   'actual formula for version should be: sd.minor * 256 + sd.major,");
    pcsaHeader->Add("   'but major/minor values are unlikely to ever change, so...");
    pcsaHeader->Add("   version% = 257");
    pcsaHeader->Add("   rc& = WinHLLAPIStartup(version%, sd)");
    pcsaHeader->Add(" ");
}
void CAG_WHL_VB6::appendBody(int nFunctionNum,
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

	pcsaBody->Add( "   WinHLLAPI nFunc%, sDataStr$, nDataLen%, nRetCode%"  );			
    pcsaBody->Add(" ");					



	pcsaArguments->RemoveAll();

}

void CAG_WHL_VB6::finalize(CStringArray* pcsaBody)
{
	pcsaBody->Add("   rc& = WinHLLAPICleanup()");
    pcsaBody->Add("End Sub");

}




void CAG_WHL_VB6::declareVariable(AG_VARIABLE agVariable,
								  CStringArray* pcsaHeader,
								  bool* bValue)
{
	
}

void CAG_WHL_VB6::checkDebug(bool b_Debug,
							   CString csFunctionName,
							   CStringArray* pcsaBody)
{
	
}

void CAG_WHL_VB6::resetVariableFlags()
{
	b_pUtilityBuffer = FALSE;
	b_pOIABuffer = FALSE;
}
