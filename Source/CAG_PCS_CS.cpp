// Static Model
#include "stdafx.h"
#include "apigen.h"

#include "CAG_PCS_CS.h"


/////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////

CAG_PCS_CS::CAG_PCS_CS()
{
	resetVariableFlags();	
}

CAG_PCS_CS::~CAG_PCS_CS()
{
	
}

void CAG_PCS_CS::declareVariable(AG_VARIABLE agVariable,
								 CStringArray* pcsaHeader,
								 bool* bValue)
{
	
}


/////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////

void CAG_PCS_CS::generateHeader(CStringArray* pcsaHeader,
								CStringArray* pcsaBody)
{
	
}

void CAG_PCS_CS::appendBody(int nFunctionNum,
							bool bPromptForValues,
							CStringArray* pcsaArguments,
							CStringArray* pcsaHeader,
							CStringArray* pcsaBody)
{
	
}

void CAG_PCS_CS::finalize(CStringArray* pcsaBody)
{
	
}


void CAG_PCS_CS::checkDebug(bool b_Debug,
									   CString csFunctionName,
									   CStringArray* pcsaBody)
{
}




void CAG_PCS_CS::resetVariableFlags()
{
}

