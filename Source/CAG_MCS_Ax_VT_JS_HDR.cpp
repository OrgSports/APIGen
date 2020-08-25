// Static Model
#include "stdafx.h"
#include "apigen.h"

#include "CAG_MCS_Ax_VT_JS_HDR.h"

CAG_MCS_Ax_VT_JS_HDR::CAG_MCS_Ax_VT_JS_HDR()
{
	resetVariableFlags();	
}

CAG_MCS_Ax_VT_JS_HDR::~CAG_MCS_Ax_VT_JS_HDR()
{
	
}

void CAG_MCS_Ax_VT_JS_HDR::generateHeader(CStringArray* pcsaHeader,
										  CStringArray* pcsaBody)
{
	
}

void CAG_MCS_Ax_VT_JS_HDR::appendBody(int nFunctionNum,
									  bool bPromptForValues,
									  CStringArray* pcsaArguments,
									  CStringArray* pcsaHeader,
									  CStringArray* pcsaBody)
{
	
}

void CAG_MCS_Ax_VT_JS_HDR::finalize(CStringArray* pcsaBody)
{
	
}

void CAG_MCS_Ax_VT_JS_HDR::declareVariable(AG_VARIABLE agVariable,
										   CStringArray* pcsaHeader,
										   bool* bValue)
{
	
}

void CAG_MCS_Ax_VT_JS_HDR::checkDebug(bool b_Debug,
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


void CAG_MCS_Ax_VT_JS_HDR::resetVariableFlags()
{

}
