// Static Model
#include "stdafx.h"
#include "apigen.h"

#include "CAG_AIR_VT_J.h"


CAG_AIR_VT_J::CAG_AIR_VT_J()
{
	APIFlavor = AIRJ_API;
}

CAG_AIR_VT_J::~CAG_AIR_VT_J()
{
	
}

void CAG_AIR_VT_J::generateHeader(CStringArray* pcsaHeader,
								  CStringArray* pcsaBody)
{}

void CAG_AIR_VT_J::appendBody(int nFunctionNum,
							  bool bPromptForValues,
							  CStringArray* pcsaArguments,
							  CStringArray* pcsaHeader,
							  CStringArray* pcsaBody)
{}

void CAG_AIR_VT_J::finalize(CStringArray* pcsaBody)
{}

void CAG_AIR_VT_J::declareVariable(AG_VARIABLE agVariable,
								   CStringArray* pcsaHeader,
								   bool* bValue)
{
	
}


void CAG_AIR_VT_J::checkDebug()
{
	
}
