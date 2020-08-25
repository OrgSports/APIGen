// Static Model
#include "stdafx.h"
#include "apigen.h"

#include "CAG_ROLE.h"

CAG_ROLE::CAG_ROLE()
{

}


CAG_ROLE::~CAG_ROLE()
{

}


void CAG_ROLE::declareVariable(AG_VARIABLE agVariable,
							   CStringArray* pcsaHeader,
							   bool* bValue)
{
	
}

void CAG_ROLE::loadLanguageList(CListBox* listTranslateLanguage)
{
	
}

void CAG_ROLE::loadTerminalTypeList(CListBox* listTerminalTypes)
{
	listTerminalTypes->ResetContent();
	listTerminalTypes->InsertString( 0, "3270" );
	listTerminalTypes->InsertString( 1, "5250" );
	listTerminalTypes->InsertString( 2, "HP" );
	listTerminalTypes->InsertString( 3, "VT" );
		
	listTerminalTypes->SetCurSel(0);
}
