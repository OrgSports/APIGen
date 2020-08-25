// Static Model
#include "stdafx.h"
#include "apigen.h"

#include "CAG_EAOJ_VT_HTML_VBS.h"

CAG_EAOJ_VT_HTML_VBS::CAG_EAOJ_VT_HTML_VBS()
{
	resetVariableFlags();	
}

CAG_EAOJ_VT_HTML_VBS::~CAG_EAOJ_VT_HTML_VBS()
{
	
}

void CAG_EAOJ_VT_HTML_VBS::declareVariable(AG_VARIABLE agVariable,
										   CStringArray* pcsaHeader,
										   bool* bValue)
{
	
}


void CAG_EAOJ_VT_HTML_VBS::generateHeader(CStringArray* pcsaHeader,
										  CStringArray* pcsaBody)
{
		// output to Translator's output window
		CString csViewOutStuff;
	
		csViewOutStuff.Format( "// ****************************************************************************");
		pcsaHeader->Add(csViewOutStuff);
	
		csViewOutStuff.Format( "// Attachmate APIGen EHLLAPI C++ Application");
		pcsaHeader->Add(csViewOutStuff);
	
		csViewOutStuff.Format( " " );
		pcsaHeader->Add(csViewOutStuff);
	
		csViewOutStuff.Format( "// This file is source code for a freestanding EHLLAPI program written in C++");
		pcsaHeader->Add(csViewOutStuff);
	
		csViewOutStuff.Format( "// that is ready to build and run.  To build and run it please do the following:");
		pcsaHeader->Add(csViewOutStuff);
	
		csViewOutStuff.Format( "// 1) Copy the acs3ehap.h file to the same folder where this source file will be built.");
		pcsaHeader->Add(csViewOutStuff);
	
		csViewOutStuff.Format( "// 2) close any open Visual C++ project, open this file, and then select");
		pcsaHeader->Add(csViewOutStuff);
	
		csViewOutStuff.Format( "// the Build\\Compile menu item.  Accept the prompt to start a");
		pcsaHeader->Add(csViewOutStuff);
	
		csViewOutStuff.Format( "// new project and the compiler will generate your application.");
		pcsaHeader->Add(csViewOutStuff);
	
		time_t ltime;
		time( &ltime );
	
		csViewOutStuff.Format( "//");
		pcsaHeader->Add(csViewOutStuff);
	
		csViewOutStuff.Format( "//   Generated:   %s", ctime( &ltime ) );
		pcsaHeader->Add(csViewOutStuff);
	
		csViewOutStuff.Format( "//");
		pcsaHeader->Add(csViewOutStuff);
	
		csViewOutStuff.Format( "// ****************************************************************************");
		pcsaHeader->Add(csViewOutStuff);
	
		csViewOutStuff.Format( "#include <windows.h>");
		pcsaHeader->Add(csViewOutStuff);
	
		csViewOutStuff.Format( "#include <stdio.h>");
		pcsaHeader->Add(csViewOutStuff);
	
		csViewOutStuff.Format( "#include \"acs3ehap.h\"" );
		pcsaHeader->Add(csViewOutStuff);
	
		csViewOutStuff.Format( "%s", "" );
		pcsaHeader->Add(csViewOutStuff);
	
		csViewOutStuff.Format( "// prototype the EHLLAPI entry point");
		pcsaHeader->Add(csViewOutStuff);
	
		csViewOutStuff.Format( "void (WINAPI *EHLLAPI)(LPINT, LPSTR, LPINT, LPINT);" );
		pcsaHeader->Add(csViewOutStuff);
	
		csViewOutStuff.Format( "%s", "" );
		pcsaHeader->Add(csViewOutStuff);
	
		csViewOutStuff.Format( "// load the EHLLAPI dll and establish the entry point");
		pcsaHeader->Add(csViewOutStuff);
	
		csViewOutStuff.Format( "%s", "void LoadHllapi()");
		pcsaHeader->Add(csViewOutStuff);
	
		csViewOutStuff.Format( "%s", "{");
		pcsaHeader->Add(csViewOutStuff);
	
		csViewOutStuff.Format( "     HMODULE dllHandle = LoadLibrary(\"ehlapi32.dll\");");
		pcsaHeader->Add(csViewOutStuff);
	
		csViewOutStuff.Format( "%s", "     FARPROC pProcAddress;");
		pcsaHeader->Add(csViewOutStuff);
	
		csViewOutStuff.Format( "     pProcAddress = GetProcAddress(dllHandle, \"HLLAPI\" );");
		pcsaHeader->Add(csViewOutStuff);
	
		csViewOutStuff.Format( "     EHLLAPI = (void (WINAPI *)(LPINT, LPSTR, LPINT, LPINT)) pProcAddress;");
		pcsaHeader->Add(csViewOutStuff);
	
		csViewOutStuff.Format( "%s", "}");
		pcsaHeader->Add(csViewOutStuff);
	
		csViewOutStuff.Format( "%s", "" );
		pcsaHeader->Add(csViewOutStuff);
	
		csViewOutStuff.Format( "int main(int argc, CHAR* argv[])");
		pcsaHeader->Add(csViewOutStuff);
	
		csViewOutStuff.Format( "%s", "{");
		pcsaHeader->Add(csViewOutStuff);
	
		csViewOutStuff.Format( "%s", "     char cSession;");
		pcsaHeader->Add(csViewOutStuff);
	
		csViewOutStuff.Format( "%s", "     int nFunc;");
		pcsaHeader->Add(csViewOutStuff);
	
		csViewOutStuff.Format( "%s", "     int nLength;");
		pcsaHeader->Add(csViewOutStuff);
	
		csViewOutStuff.Format( "%s", "     int nRetCode;");
		pcsaHeader->Add(csViewOutStuff);
	
		csViewOutStuff.Format( "%s", "     char szString[1000];");
		pcsaHeader->Add(csViewOutStuff);
	
		csViewOutStuff.Format( "%s", "     char* pszString = szString;");
		pcsaHeader->Add(csViewOutStuff);
	
		
		// start of body
		csViewOutStuff.Format( "%s", "" );
		pcsaBody->Add(csViewOutStuff);
	
		csViewOutStuff.Format( "%s", "     LoadHllapi();");
		pcsaBody->Add(csViewOutStuff);
	
		csViewOutStuff.Format( "%s", "" );
		pcsaBody->Add(csViewOutStuff);

}

void CAG_EAOJ_VT_HTML_VBS::appendBody(int nFunctionNum,
									  bool bPromptForValues,
									  CStringArray* pcsaArguments,
									  CStringArray* pcsaHeader,
									  CStringArray* pcsaBody)
{}

void CAG_EAOJ_VT_HTML_VBS::finalize(CStringArray* pcsaBody)
{}


void CAG_EAOJ_VT_HTML_VBS::resetVariableFlags()
{
}

void CAG_EAOJ_VT_HTML_VBS::checkDebug(bool b_Debug,
									   CString csFunctionName,
									   CStringArray* pcsaBody)
{
	
}
