// Static Model
#include "stdafx.h"
#include "apigen.h"

#include "CAG_MCS_Ax_VT_VBS_CRL.h"

CAG_MCS_Ax_VT_VBS_CRL::CAG_MCS_Ax_VT_VBS_CRL()
{
	resetVariableFlags();	
}

CAG_MCS_Ax_VT_VBS_CRL::~CAG_MCS_Ax_VT_VBS_CRL()
{
	
}


void CAG_MCS_Ax_VT_VBS_CRL::generateHeader(CStringArray* pcsaHeader,
										   CStringArray* pcsaBody)
{
	
}

void CAG_MCS_Ax_VT_VBS_CRL::appendBody(int nFunctionNum,
									   bool bPromptForValues,
									   CStringArray* pcsaArguments,
									   CStringArray* pcsaHeader,
									   CStringArray* pcsaBody)
{
	
}

void CAG_MCS_Ax_VT_VBS_CRL::finalize(CStringArray* pcsaBody)
{
	
}

void CAG_MCS_Ax_VT_VBS_CRL::declareVariable(AG_VARIABLE agVariable,
											CStringArray* pcsaHeader,
											bool* bValue)
{
	
}

void CAG_MCS_Ax_VT_VBS_CRL::checkDebug(bool b_Debug,
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


void CAG_MCS_Ax_VT_VBS_CRL::resetVariableFlags()
{

}
