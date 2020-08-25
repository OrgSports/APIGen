// Static Model
#include "stdafx.h"
#include "apigen.h"

#include "CAG_EOLE.h"

CAG_EOLE::CAG_EOLE()
{
	APIFlavor=EOLE_API;	
}

CAG_EOLE::~CAG_EOLE()
{
	
}

void CAG_EOLE::loadLanguageList(CListBox* listTranslateLanguage)
{
	int nPos = 0;

	listTranslateLanguage->ResetContent();
	listTranslateLanguage->InsertString( nPos++, "C++" );
	listTranslateLanguage->InsertString( nPos++, "C#" );
	listTranslateLanguage->InsertString( nPos++, "EB Macro" );
	listTranslateLanguage->InsertString( nPos++, "EB Macro Test" );
//	listTranslateLanguage->InsertString( nPos++, "JavaScript Node" );
	listTranslateLanguage->InsertString( nPos++, "VB 6.0" );
	listTranslateLanguage->InsertString( nPos++, "VBScript Node" );
	listTranslateLanguage->InsertString( nPos++, "Windows Script" );
//	listTranslateLanguage->InsertString( nPos++, "Excel VBA Macro" );
	listTranslateLanguage->SetCurSel(0);

}

void CAG_EOLE::loadTerminalTypeList(CListBox* listTerminalTypes)
{
	int nPos = 0;

	listTerminalTypes->ResetContent();
	listTerminalTypes->InsertString( nPos++, "3270" );
	listTerminalTypes->InsertString( nPos++, "5250" );
	listTerminalTypes->InsertString( nPos++, "VT" );
	
	listTerminalTypes->SetCurSel(0);
}
