// Static Model
#include "stdafx.h"
#include "apigen.h"

#include "CAG_MCS_Ax.h"

CAG_MCS_Ax::CAG_MCS_Ax()
{
	APIFlavor=MCSAx_API;	
}

CAG_MCS_Ax::~CAG_MCS_Ax()
{
	
}



void CAG_MCS_Ax::loadLanguageList(CListBox* listTranslateLanguage)
{
	int nPos = 0;

	listTranslateLanguage->ResetContent();

	listTranslateLanguage->InsertString( nPos++, "JavaScript CRL" );
	listTranslateLanguage->InsertString( nPos++, "JavaScript Deployed" );
	listTranslateLanguage->InsertString( nPos++, "JavaScript HDR" );
	listTranslateLanguage->InsertString( nPos++, "JavaScript HTML" );
	listTranslateLanguage->InsertString( nPos++, "VBScript CRL" );
	listTranslateLanguage->InsertString( nPos++, "VBScript Deployed" );
	listTranslateLanguage->InsertString( nPos++, "VBScript HDR" );
	listTranslateLanguage->InsertString( nPos++, "VBScript HTML" );
	listTranslateLanguage->SetCurSel(0);
	
}


void CAG_MCS_Ax::declareVariable(AG_VARIABLE agVariable,
								 CStringArray* pcsaHeader,
								 bool* bValue)
{
	
}

void CAG_MCS_Ax::checkDebug()
{
	
}


void CAG_MCS_Ax::loadTerminalTypeList(CListBox* listTerminalTypes)
{
	listTerminalTypes->ResetContent();
	listTerminalTypes->InsertString( 0, "3270" );
	listTerminalTypes->InsertString( 1, "5250" );
	listTerminalTypes->InsertString( 2, "VT" );
	
	listTerminalTypes->SetCurSel(0);
}
