// Static Model
#include "stdafx.h"
#include "apigen.h"

#include "CAG_MCS_Ax_VT_VBS_HDR.h"

CAG_MCS_Ax_VT_VBS_HDR::CAG_MCS_Ax_VT_VBS_HDR()
{
	resetVariableFlags();	
}

CAG_MCS_Ax_VT_VBS_HDR::~CAG_MCS_Ax_VT_VBS_HDR()
{
	
}


void CAG_MCS_Ax_VT_VBS_HDR::generateHeader(CStringArray* pcsaHeader,
										   CStringArray* pcsaBody)
{
	
}

void CAG_MCS_Ax_VT_VBS_HDR::appendBody(int nFunctionNum,
									   bool bPromptForValues,
									   CStringArray* pcsaArguments,
									   CStringArray* pcsaHeader,
									   CStringArray* pcsaBody)
{
	
}

void CAG_MCS_Ax_VT_VBS_HDR::finalize(CStringArray* pcsaBody)
{
	
}

void CAG_MCS_Ax_VT_VBS_HDR::declareVariable(AG_VARIABLE agVariable,
											CStringArray* pcsaHeader,
											bool* bValue)
{
	
}

void CAG_MCS_Ax_VT_VBS_HDR::checkDebug(bool b_Debug,
										  CString csFunctionName,
										  CStringArray* pcsaBody)
{
	CString csLocal;
	
	if ( b_Debug )
	{
		csLocal.Format( "   MsgBox( \"%s\" )", csFunctionName );
		pcsaBody->Add(csLocal);
	}
}


void CAG_MCS_Ax_VT_VBS_HDR::resetVariableFlags()
{

}
