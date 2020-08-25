// Static Model
#include "stdafx.h"
#include "apigen.h"

#include "CAG_CICS_QACOM.h"

CAG_CICS_QACOM::CAG_CICS_QACOM()
{
	
}

CAG_CICS_QACOM::~CAG_CICS_QACOM()
{
	
}

void CAG_CICS_QACOM::loadTerminalTypeList(CListBox* listTerminalTypes)
{
	int nPos = 0;
	listTerminalTypes->ResetContent();
	listTerminalTypes->InsertString( nPos++, "COM" );
	listTerminalTypes->InsertString( nPos++, "CICS 1.1 JAVA" );
	listTerminalTypes->InsertString( nPos++, "CICS 2.0 JAVA" );
	listTerminalTypes->InsertString( nPos++, ".Net" );
	
	listTerminalTypes->SetCurSel(0);
}
