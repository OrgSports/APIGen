// Static Model
#include "stdafx.h"
#include "apigen.h"

#include "CAG_EAO.h"

CAG_EAO::CAG_EAO()
{
	
}

CAG_EAO::~CAG_EAO()
{
	
}

void CAG_EAO::declareVariable(AG_VARIABLE agVariable,
							  CStringArray* pcsaHeader,
							  bool* bValue)
{
	
}



void CAG_EAO::loadTerminalTypeList(CListBox* listTerminalTypes)
{
	listTerminalTypes->ResetContent();
	listTerminalTypes->InsertString( 0, "3270" );
	listTerminalTypes->InsertString( 1, "5250" );
	listTerminalTypes->InsertString( 2, "VT" );
	
	listTerminalTypes->SetCurSel(0);
}
