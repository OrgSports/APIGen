// Static Model
#include "stdafx.h"
#include "apigen.h"

#include "CAG_RWEB_5250_JS.h"

CAG_RWEB_5250_JS::CAG_RWEB_5250_JS()
{
	resetVariableFlags();	
}

CAG_RWEB_5250_JS::~CAG_RWEB_5250_JS()
{
	
}

void CAG_RWEB_5250_JS::generateHeader(CStringArray* pcsaHeader,
									  CStringArray* pcsaBody)
{
	
}

void CAG_RWEB_5250_JS::appendBody(int nFunctionNum,
								  bool bPromptForValues,
								  CStringArray* pcsaArguments,
								  CStringArray* pcsaHeader,
								  CStringArray* pcsaBody)
{
	
}

void CAG_RWEB_5250_JS::finalize(CStringArray* pcsaBody)
{
	
}

void CAG_RWEB_5250_JS::declareVariable(AG_VARIABLE agVariable,
									   CStringArray* pcsaHeader,
									   bool* bValue)
{
	
}

void CAG_RWEB_5250_JS::checkDebug(bool b_Debug,
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

void CAG_RWEB_5250_JS::resetVariableFlags()
{
}