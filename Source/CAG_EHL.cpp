// Static Model
#include "stdafx.h"
#include "apigen.h"

#include "CAG_EHL.h"

CAG_EHL::CAG_EHL()
{
	APIFlavor = EHL_API;
}

CAG_EHL::~CAG_EHL()
{
	
}

void CAG_EHL::loadFunctionList(CListBox* listTranslationFunction)
{
	csaFunctions.RemoveAll();

	csaFunctions.Add( "1 Connect PS" );
	csaFunctions.Add( "2 Disconnect PS" );
	csaFunctions.Add( "3 Send Key" );
	csaFunctions.Add( "4 Wait" );
	csaFunctions.Add( "5 Copy Presentation Space");
	csaFunctions.Add( "6 Search Presentation Space" );
	csaFunctions.Add( "7 Query Cursor Location" );
	csaFunctions.Add( "8 Copy Presentation Space To String" );
	csaFunctions.Add( "9 Set Session Parameters" );
	csaFunctions.Add( "10 Query Sessions" );
	csaFunctions.Add( "11 Reserve" );
	csaFunctions.Add( "12 Release" );
	csaFunctions.Add( "13 Copy OIA" );
	csaFunctions.Add( "14 Query Field Attribute" );
	csaFunctions.Add( "15 Copy String To Presentation Space" );
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
	csaFunctions.Add( "90 Send File" );
	csaFunctions.Add( "91 Receive File" );
	csaFunctions.Add( "99 Convert Position or RowCol" );
	csaFunctions.Add( "101 Connect Window Services" );
	csaFunctions.Add( "102 Disconnect Window Services" );
	csaFunctions.Add( "103 Query Window Coordinates" );
	csaFunctions.Add( "104 Window Status" );
	csaFunctions.Add( "105 Change Switch List LT Name" );
	csaFunctions.Add( "106 Change PS Window Name" );
	csaFunctions.Add( "137 Smart Wait" );
	

	listTranslationFunction->ResetContent();	
	
	for (int k=0; k<csaFunctions.GetSize(); k++)
	{
		listTranslationFunction->AddString( csaFunctions.GetAt(k) );
	}

	listTranslationFunction->SetCurSel(0);
	
}

void CAG_EHL::loadLanguageList(CListBox* listTranslateLanguage)
{
	int nPos = 0;

	listTranslateLanguage->ResetContent();
	listTranslateLanguage->InsertString( nPos++, "C++" );
	listTranslateLanguage->InsertString( nPos++, "C#" );
//	listTranslateLanguage->InsertString( nPos++, "Excel VBA Macro" );
	listTranslateLanguage->InsertString( nPos++, "VB 6.0" );
	listTranslateLanguage->InsertString( nPos++, "VB.Net" );
	
	listTranslateLanguage->SetCurSel(0);
	
}

void CAG_EHL::loadTerminalTypeList(CListBox* listTerminalTypes)
{
	int nPos = 0;

	listTerminalTypes->ResetContent();
	listTerminalTypes->InsertString( nPos++, "3270" );
	listTerminalTypes->InsertString( nPos++, "5250" );
	listTerminalTypes->InsertString( nPos++, "VT" );
	
	listTerminalTypes->SetCurSel(0);
}
