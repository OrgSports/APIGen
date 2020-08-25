// Static Model
#include "stdafx.h"
#include "apigen.h"

#include "CAG_MCS_J_5250_JS_HTML.h"

CAG_MCS_J_5250_JS_HTML::CAG_MCS_J_5250_JS_HTML()
{
	resetVariableFlags();	
}

CAG_MCS_J_5250_JS_HTML::~CAG_MCS_J_5250_JS_HTML()
{
	
}

void CAG_MCS_J_5250_JS_HTML::generateHeader(CStringArray* pcsaHeader,
											CStringArray* pcsaBody)
{
	
}

void CAG_MCS_J_5250_JS_HTML::appendBody(int nFunctionNum,
										bool bPromptForValues,
										CStringArray* pcsaArguments,
										CStringArray* pcsaHeader,
										CStringArray* pcsaBody)
{
	
}

void CAG_MCS_J_5250_JS_HTML::finalize(CStringArray* pcsaBody)
{
	
}

void CAG_MCS_J_5250_JS_HTML::declareVariable(AG_VARIABLE agVariable,
											 CStringArray* pcsaHeader,
											 bool* bValue)
{
	
}

void CAG_MCS_J_5250_JS_HTML::checkDebug(bool b_Debug,
									   CString csFunctionName,
									   CStringArray* pcsaBody)
{
	CString csLocal;
	
	if ( b_Debug )
	{
		csLocal.Format( "   alert( \"%s\" );", csFunctionName );
		pcsaBody->Add(csLocal);
	}
}


void CAG_MCS_J_5250_JS_HTML::resetVariableFlags()
{

}
