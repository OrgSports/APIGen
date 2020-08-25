// Static Model
#include "stdafx.h"
#include "apigen.h"

#include "CAG_EAOAx.h"


CAG_EAOAx::CAG_EAOAx()
{
	APIFlavor=EA0Ax_API;	
}

CAG_EAOAx::~CAG_EAOAx()
{
	
}

void CAG_EAOAx::loadLanguageList(CListBox* listTranslateLanguage)
{
	int nPos = 0;

	listTranslateLanguage->ResetContent();

	listTranslateLanguage->InsertString( nPos++, "C++" );
	listTranslateLanguage->InsertString( nPos++, "C#" );
	listTranslateLanguage->InsertString( nPos++, "JavaScript HTML" );
	listTranslateLanguage->InsertString( nPos++, "VB 6.0" );
	listTranslateLanguage->InsertString( nPos++, "VB.Net" );
	listTranslateLanguage->InsertString( nPos++, "VBScript HTML" );
	listTranslateLanguage->SetCurSel(0);
	
}

void CAG_EAOAx::declareVariable(AG_VARIABLE agVariable,
								CStringArray* pcsaHeader,
								bool* bValue)
{
	
}

void CAG_EAOAx::loadTerminalTypeList(CListBox* listTerminalTypes)
{
	int nPos = 0;
	listTerminalTypes->ResetContent();
	listTerminalTypes->InsertString( nPos++, "3270" );
	listTerminalTypes->InsertString( nPos++, "5250" );
	listTerminalTypes->InsertString( nPos++, "VT" );
	
	listTerminalTypes->SetCurSel(0);
}
