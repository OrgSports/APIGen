// Static Model
#include "stdafx.h"
#include "apigen.h"

#include "CAG_WHL.h"

CAG_WHL::~CAG_WHL()
{
	
}

CAG_WHL::CAG_WHL()
{
}

void CAG_WHL::loadFunctionList(CListBox* listTranslateFunction)
{
	csaFunctions.RemoveAll();

	csaFunctions.Add( "0 OEM Function" );
	csaFunctions.Add( "1 Connect" );
	csaFunctions.Add( "2 Disconnect" );
	csaFunctions.Add( "3 SendKeys" );
	csaFunctions.Add( "4 Wait" );
	csaFunctions.Add( "5 Copy Presentation Space");
	csaFunctions.Add( "6 Search Presentation Space" );
	csaFunctions.Add( "7 Query Cursor Location" );
	csaFunctions.Add( "8 Copy Presentation Space To String" );
	csaFunctions.Add( "9 Set Session Parameters" );
	csaFunctions.Add( "10 Query Sessions" );
	csaFunctions.Add( "11 Reserve" );
	csaFunctions.Add( "12 Release" );
	csaFunctions.Add( "13 Copy OIA Information" );
	csaFunctions.Add( "14 Query Field Attribute" );
	csaFunctions.Add( "15 Copy String To Presentation Space" );
	csaFunctions.Add( "17 Storage Manager" );
	csaFunctions.Add( "18 Pause" );
	csaFunctions.Add( "20 Query System" );
	csaFunctions.Add( "21 Reset System" );
	csaFunctions.Add( "22 Query Session Status" );
	csaFunctions.Add( "23 Start Host Notification" );
	csaFunctions.Add( "24 Query Host Update" );
	csaFunctions.Add( "25 Stop Host Notification" );
	csaFunctions.Add( "30 Search Field" );
	csaFunctions.Add( "31 Find Field Position" );
	csaFunctions.Add( "32 Find Field Length" );
	csaFunctions.Add( "33 Copy String To Field" );
	csaFunctions.Add( "34 Copy Field To String" );
	csaFunctions.Add( "40 Set Cursor" );
	csaFunctions.Add( "41 Start Close Intercept" );
	csaFunctions.Add( "42 Query Close Intercept" );
	csaFunctions.Add( "43 Stop Close Intercept" );
	csaFunctions.Add( "50 Start Keystroke Intercept" );
	csaFunctions.Add( "51 Get Key" );
	csaFunctions.Add( "52 Post Intercept Status" );
	csaFunctions.Add( "53 Stop  Keystroke Intercept" );
	csaFunctions.Add( "60 Lock Presentation Space API" );
	csaFunctions.Add( "61 Lock Window Services API" );
	csaFunctions.Add( "90 Send File" );
	csaFunctions.Add( "91 Receive File" );
	csaFunctions.Add( "99 Convert Position or RowCol" );
	csaFunctions.Add( "101 Connect Window Services" );
	csaFunctions.Add( "102 Disconnect Window Services" );
	csaFunctions.Add( "103 Query or Set Window Coordinates" );
	csaFunctions.Add( "104 Query or Set Window Status" );
	csaFunctions.Add( "105 Change Presentation Space Name" );
	csaFunctions.Add( "106 Change Name" );
	csaFunctions.Add( "107 Query Handle" );
	csaFunctions.Add( "120 Connect Structured Fields" );
	csaFunctions.Add( "121 Disconnect Structured Fields" );
	csaFunctions.Add( "122 Query Communications Buffer Size" );
	csaFunctions.Add( "123 Allocate Communications Buffer" );
	csaFunctions.Add( "124 Free Communications Buffer" );
	csaFunctions.Add( "125 Get Request Completion" );
	csaFunctions.Add( "126 Read Structured Fields" );
	csaFunctions.Add( "127 Write Structured Fields" );

	listTranslateFunction->ResetContent();	
	
	for (int k=0; k<csaFunctions.GetSize(); k++)
	{
		listTranslateFunction->AddString( csaFunctions.GetAt(k) );
	}

	listTranslateFunction->SetCurSel(0);

}

void CAG_WHL::declareVariable(AG_VARIABLE agVariable,
							  CStringArray* pcsaHeader,
							  bool* bValue)
{
	
}

void CAG_WHL::loadLanguageList(CListBox* listTranslateLanguage)
{
	int nPos = 0;

	listTranslateLanguage->ResetContent();
	listTranslateLanguage->InsertString( nPos++, "C++" );
	listTranslateLanguage->InsertString( nPos++, "C#" );
	listTranslateLanguage->InsertString( nPos++, "VB 6.0" );
	listTranslateLanguage->InsertString( nPos++, "VB.Net" );
	
	listTranslateLanguage->SetCurSel(0);

}

void CAG_WHL::checkDebug()
{
	
}


void CAG_WHL::loadTerminalTypeList(CListBox* listTerminalTypes)
{
	listTerminalTypes->ResetContent();
	listTerminalTypes->InsertString( 0, "3270" );
	listTerminalTypes->InsertString( 1, "5250" );
	listTerminalTypes->InsertString( 2, "VT" );
	
	listTerminalTypes->SetCurSel(0);
}
