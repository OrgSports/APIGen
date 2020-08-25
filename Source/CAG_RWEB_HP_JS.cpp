// Static Model
#include "stdafx.h"
#include "apigen.h"

#include "CAG_RWEB_HP_JS.h"

CAG_RWEB_HP_JS::CAG_RWEB_HP_JS()
{
	resetVariableFlags();	
}

CAG_RWEB_HP_JS::~CAG_RWEB_HP_JS()
{
	
}

void CAG_RWEB_HP_JS::generateHeader(CStringArray* pcsaHeader,
									CStringArray* pcsaBody)
{
	
}

void CAG_RWEB_HP_JS::appendBody(int nFunctionNum,
								bool bPromptForValues,
								CStringArray* pcsaArguments,
								CStringArray* pcsaHeader,
								CStringArray* pcsaBody)
{
	
}

void CAG_RWEB_HP_JS::finalize(CStringArray* pcsaBody)
{
	
}

void CAG_RWEB_HP_JS::declareVariable(AG_VARIABLE agVariable,
									 CStringArray* pcsaHeader,
									 bool* bValue)
{
	
}

void CAG_RWEB_HP_JS::checkDebug(bool b_Debug,
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

void CAG_RWEB_HP_JS::resetVariableFlags()
{
}