// Static Model
#include "stdafx.h"
#include "apigen.h"

#include "CAG_CICS_QACOM_JAVA.h"

CAG_CICS_QACOM_JAVA::CAG_CICS_QACOM_JAVA()
{
}

CAG_CICS_QACOM_JAVA::~CAG_CICS_QACOM_JAVA()
{
	
}

void CAG_CICS_QACOM_JAVA::declareVariable(AG_VARIABLE agVariable,
										  CStringArray* pcsaHeader,
										  bool* bValue)
{
	
}

void CAG_CICS_QACOM_JAVA::finalize(CStringArray* pcsaBody)
{
		CString csLocal;
	
		csLocal.Format( "}" );
		pcsaBody->Add(csLocal);

		csLocal.Format( "" );
		pcsaBody->Add(csLocal);

}

void CAG_CICS_QACOM_JAVA::checkDebug(bool b_Debug,
									 CString csFunctionName,
									 CStringArray* pcsaBody)
{
	
}

void CAG_CICS_QACOM_JAVA::loadLanguageList(CListBox* listTranslateLanguage)
{
	int nPos = 0;

	listTranslateLanguage->ResetContent();

	listTranslateLanguage->InsertString( nPos++, "Java" );
	listTranslateLanguage->SetCurSel(0);
	
}


void CAG_CICS_QACOM_JAVA::resetVariableFlags()
{
}