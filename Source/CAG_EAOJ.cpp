// Static Model
#include "stdafx.h"
#include "apigen.h"

#include "CAG_EAOJ.h"

CAG_EAOJ::CAG_EAOJ()
{
	APIFlavor=EA0J_API;
}

CAG_EAOJ::~CAG_EAOJ()
{
	
}

void CAG_EAOJ::loadLanguageList(CListBox* listTranslateLanguage)
{
	listTranslateLanguage->ResetContent();

	listTranslateLanguage->InsertString( 0, "Java" );

	listTranslateLanguage->SetCurSel(0);

}

void CAG_EAOJ::declareVariable(AG_VARIABLE agVariable,
							   CStringArray* pcsaHeader,
							   bool* bValue)
{
	
}

