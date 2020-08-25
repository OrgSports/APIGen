// Static Model
#include "stdafx.h"
#include "apigen.h"

#include "CAG_AIR_VM.h"

void CAG_AIR_VM::declareVariable()
{
	
}

void CAG_AIR_VM::loadLanguageList(CListBox* listTranslateLanguage)
{
	listTranslateLanguage->ResetContent();
	listTranslateLanguage->InsertString( 0, "JavaScript" );
	listTranslateLanguage->InsertString( 1, "VBScript" );
	listTranslateLanguage->SetCurSel(0);
}

CAG_AIR_VM::CAG_AIR_VM()
{
	APIFlavor = VIEWMASTER_API;
}

CAG_AIR_VM::~CAG_AIR_VM()
{
	
}

void CAG_AIR_VM::loadTerminalTypeList(CListBox* listTerminalTypes)
{
	int nPos = 0;
	listTerminalTypes->ResetContent();
	listTerminalTypes->InsertString( nPos++, "3270" );
//	listTerminalTypes->InsertString( nPos++, "5250" );
//	listTerminalTypes->InsertString( nPos++, "VT" );
	listTerminalTypes->InsertString( nPos++, "T27/TCPA" );
	listTerminalTypes->InsertString( nPos++, "UTS/INT1" );
//	listTerminalTypes->InsertString( nPos++, "UTS/MATIP" );
//	listTerminalTypes->InsertString( nPos++, "UTS/PEPGate" );
//	listTerminalTypes->InsertString( nPos++, "ALC/MATIP" );
//	listTerminalTypes->InsertString( nPos++, "ALC/EDS SHARES" );
//	listTerminalTypes->InsertString( nPos++, "ALC/SABRE" );
//	listTerminalTypes->InsertString( nPos++, "ALC/APOLLO" );
//	listTerminalTypes->InsertString( nPos++, "ALC/LANTERN" );
//	listTerminalTypes->InsertString( nPos++, "MCS" );

	listTerminalTypes->SetCurSel(0);
}
