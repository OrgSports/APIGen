// Static Model
#include "stdafx.h"
#include "apigen.h"

#include "CAG_IHL.h"

CAG_IHL::~CAG_IHL()
{
	
}

CAG_IHL::CAG_IHL()
{
	APIFlavor=IHL_API;
	usGlobalPSMallocSize = 3840;
}

void CAG_IHL::loadFunctionList(CListBox* listTranslateFunction)
{
	csaFunctions.RemoveAll();

	csaFunctions.Add( "1 Connect PS");
	csaFunctions.Add( "2 Disconnect PS");
	csaFunctions.Add( "3 Send Key" );
	csaFunctions.Add( "4 Wait" );
	csaFunctions.Add( "5 Copy Presentation Space");
	csaFunctions.Add( "6 Search Presentation Space" );
	csaFunctions.Add( "7 Query Cursor Location" );
	csaFunctions.Add( "8 Copy PS To String" );
	csaFunctions.Add( "9 Set Session Parameters" );
	csaFunctions.Add( "10 Query Sessions" );
	csaFunctions.Add( "13 Copy OIA" );
	csaFunctions.Add( "14 Query Field Attribute" );
	csaFunctions.Add( "15 Copy String To PS" );
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
	csaFunctions.Add( "50 Start Keystroke Intercept" );
	csaFunctions.Add( "51 Get Key" );
	csaFunctions.Add( "52 Post Intercept Status" );
	csaFunctions.Add( "53 Stop  Keystroke Intercept" );
	csaFunctions.Add( "99 Convert Position or RowCol" );
	csaFunctions.Add( "101 Connect Window Services" );
	csaFunctions.Add( "102 Disconnect Window Services" );
	csaFunctions.Add( "103 Query or Set Window Coordinates" );
	csaFunctions.Add( "104 Window Status" );
	csaFunctions.Add( "911 Associate Profile" );
	csaFunctions.Add( "912 Remove Profile" );
	csaFunctions.Add( "913 Get Associations" );
	csaFunctions.Add( "914 Find File Name" );
	csaFunctions.Add( "915 Find Short Name" );
	
	listTranslateFunction->ResetContent();	
	
	for (int k=0; k<csaFunctions.GetSize(); k++)
	{
		listTranslateFunction->AddString( csaFunctions.GetAt(k) );
	}

	listTranslateFunction->SetCurSel(0);


}

void CAG_IHL::declareVariable(AG_VARIABLE agVariable,
							  CStringArray* pcsaHeader,
							  bool* bValue)
{
	
}

void CAG_IHL::loadLanguageList(CListBox* listTranslateLanguage)
{
	int nPos = 0;

	listTranslateLanguage->ResetContent();
	listTranslateLanguage->InsertString( nPos++, "C++" );
	listTranslateLanguage->InsertString( nPos++, "C#" );
	listTranslateLanguage->InsertString( nPos++, "VB 6.0" );
	listTranslateLanguage->InsertString( nPos++, "VB.Net" );
	
	listTranslateLanguage->SetCurSel(0);

}

void CAG_IHL::checkDebug()
{
	
}


void CAG_IHL::loadTerminalTypeList(CListBox* listTerminalTypes)
{
	listTerminalTypes->ResetContent();
	listTerminalTypes->InsertString( 0, "Unisys" );
	
	listTerminalTypes->SetCurSel(0);
}
