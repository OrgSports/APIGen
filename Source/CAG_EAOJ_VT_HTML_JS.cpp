// Static Model
#include "stdafx.h"
#include "apigen.h"

#include "CAG_EAOJ_VT_HTML_JS.h"

CAG_EAOJ_VT_HTML_JS::CAG_EAOJ_VT_HTML_JS()
{
	resetVariableFlags();
}

CAG_EAOJ_VT_HTML_JS::~CAG_EAOJ_VT_HTML_JS()
{
	
}

void CAG_EAOJ_VT_HTML_JS::declareVariable(AG_VARIABLE agVariable,
										  CStringArray* pcsaHeader,
										  bool* bValue)
{
	
}

void CAG_EAOJ_VT_HTML_JS::checkDebug(bool b_Debug,
									   CString csFunctionName,
									   CStringArray* pcsaBody)
{
	CString csLocal;
	
	if ( b_Debug )
	{
		csLocal.Format( "   alert( \"%s\", \"Progress notice\", MB_OK );", csFunctionName );
		pcsaBody->Add(csLocal);
	}
}

void CAG_EAOJ_VT_HTML_JS::generateHeader(CStringArray* pcsaHeader,
										 CStringArray* pcsaBody)
{}

void CAG_EAOJ_VT_HTML_JS::appendBody(int nFunctionNum,
									 bool bPromptForValues,
									 CStringArray* pcsaArguments,
									 CStringArray* pcsaHeader,
									 CStringArray* pcsaBody)
{}

void CAG_EAOJ_VT_HTML_JS::finalize(CStringArray* pcsaBody)
{}

void CAG_EAOJ_VT_HTML_JS::resetVariableFlags()
{
}