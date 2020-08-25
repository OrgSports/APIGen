// Static Model
#include "stdafx.h"
#include "apigen.h"

#include "CAG_MCS_J_VT_VBS_DEPLOY.h"

CAG_MCS_J_VT_VBS_DEPLOY::CAG_MCS_J_VT_VBS_DEPLOY()
{
	resetVariableFlags();
}

CAG_MCS_J_VT_VBS_DEPLOY::~CAG_MCS_J_VT_VBS_DEPLOY()
{
	
}

void CAG_MCS_J_VT_VBS_DEPLOY::declareVariable(AG_VARIABLE agVariable,
											  CStringArray* pcsaHeader,
											  bool* bValue)
{
	
}


void CAG_MCS_J_VT_VBS_DEPLOY::generateHeader(CStringArray* pcsaHeader,
											 CStringArray* pcsaBody)
{
	
}

void CAG_MCS_J_VT_VBS_DEPLOY::appendBody(int nFunctionNum,
										 bool bPromptForValues,
										 CStringArray* pcsaArguments,
										 CStringArray* pcsaHeader,
										 CStringArray* pcsaBody)
{
	
}

void CAG_MCS_J_VT_VBS_DEPLOY::finalize(CStringArray* pcsaBody)
{
	
}

void CAG_MCS_J_VT_VBS_DEPLOY::collectDeploymentParameters(CStringArray* pcsaDeploymentParameters)
{
	
}

void CAG_MCS_J_VT_VBS_DEPLOY::checkDebug(bool b_Debug,
										 CString csFunctionName,
										 CStringArray* pcsaBody)
{
	CString csLocal;
	
	if ( b_Debug )
	{
		csLocal.Format( "   MsgBox \"%s\"", csFunctionName );
		pcsaBody->Add(csLocal);
	}
}


void CAG_MCS_J_VT_VBS_DEPLOY::resetVariableFlags()
{
}
