// Static Model
#include "stdafx.h"
#include "apigen.h"

#include "CAG_MCS_Ax_5250_JS_CRL.h"

CAG_MCS_Ax_5250_JS_CRL::CAG_MCS_Ax_5250_JS_CRL()
{
	resetVariableFlags();	
}

CAG_MCS_Ax_5250_JS_CRL::~CAG_MCS_Ax_5250_JS_CRL()
{
	
}

void CAG_MCS_Ax_5250_JS_CRL::declareVariable(AG_VARIABLE agVariable,
											 CStringArray* pcsaHeader,
											 bool* bValue)
{
	
}


void CAG_MCS_Ax_5250_JS_CRL::generateHeader(CStringArray* pcsaHeader,
											CStringArray* pcsaBody)
{
	
}

void CAG_MCS_Ax_5250_JS_CRL::appendBody(int nFunctionNum,
										bool bPromptForValues,
										CStringArray* pcsaArguments,
										CStringArray* pcsaHeader,
										CStringArray* pcsaBody)
{
	
}

void CAG_MCS_Ax_5250_JS_CRL::finalize(CStringArray* pcsaBody)
{
	
}

void CAG_MCS_Ax_5250_JS_CRL::checkDebug(bool b_Debug,
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

void CAG_MCS_Ax_5250_JS_CRL::resetVariableFlags()
{

}
