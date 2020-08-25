// Static Model
#include "stdafx.h"
#include "apigen.h"

#include "CAG_AIR.h"

void CAG_AIR::declareVariable()
{
	
}

void CAG_AIR::loadLanguageList(CListBox* listTranslateLanguage)
{
	listTranslateLanguage->ResetContent();
	listTranslateLanguage->InsertString( 0, "Java" );
	listTranslateLanguage->InsertString( 1, "C++" );
	listTranslateLanguage->SetCurSel(0);
}

CAG_AIR::CAG_AIR()
{
	
}

CAG_AIR::~CAG_AIR()
{
	
}

void CAG_AIR::loadTerminalTypeList(CListBox* listTerminalTypes)
{
	int nPos = 0;
	listTerminalTypes->ResetContent();
	listTerminalTypes->InsertString( nPos++, "3270" );
	listTerminalTypes->InsertString( nPos++, "5250" );
	listTerminalTypes->InsertString( nPos++, "VT" );
	listTerminalTypes->InsertString( nPos++, "T27/TCPA" );
	listTerminalTypes->InsertString( nPos++, "UTS/INT1" );
	listTerminalTypes->InsertString( nPos++, "UTS/MATIP" );
	listTerminalTypes->InsertString( nPos++, "UTS/PEPGate" );
	listTerminalTypes->InsertString( nPos++, "ALC/MATIP" );
	listTerminalTypes->InsertString( nPos++, "ALC/EDS SHARES" );
	listTerminalTypes->InsertString( nPos++, "ALC/SABRE" );
	listTerminalTypes->InsertString( nPos++, "ALC/APOLLO" );
	listTerminalTypes->InsertString( nPos++, "ALC/LANTERN" );
	listTerminalTypes->InsertString( nPos++, "MCS" );

	listTerminalTypes->SetCurSel(0);
}
