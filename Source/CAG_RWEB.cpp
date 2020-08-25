// Static Model
#include "stdafx.h"
#include "apigen.h"

#include "CAG_RWeb.h"

CAG_RWEB::CAG_RWEB()
{
	APIFlavor=RWEB_API;	
}

CAG_RWEB::~CAG_RWEB()
{
	
}

void CAG_RWEB::declareVariable(AG_VARIABLE agVariable,
							   CStringArray* pcsaHeader,
							   bool* bValue)
{
	
}

void CAG_RWEB::loadLanguageList(CListBox* listTranslateLanguage)
{
	listTranslateLanguage->ResetContent();
	listTranslateLanguage->InsertString( 0, "Java" );
	listTranslateLanguage->InsertString( 1, "JavaScript" );
	listTranslateLanguage->InsertString( 2, "VBScript" );
	listTranslateLanguage->SetCurSel(0);
}


void CAG_RWEB::loadTerminalTypeList(CListBox* listTerminalTypes)
{
	listTerminalTypes->ResetContent();
	listTerminalTypes->InsertString( 0, "3270" );
	listTerminalTypes->InsertString( 1, "5250" );
	listTerminalTypes->InsertString( 2, "HP" );
	listTerminalTypes->InsertString( 3, "VT" );
	
	listTerminalTypes->SetCurSel(0);
}
