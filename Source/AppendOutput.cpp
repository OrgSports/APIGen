#include "stdafx.h"
#include "APIGen.h"
#include "APIGenDlg.h"
#include "APIGenState.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif




/***************************************************************************DC

	Operation:	CAPIGenDlg::OnAppendSource() 

	Purpose:	Manages appending the code associated with the latest
				selected function so the correct language and API are used.

	Note:		Don't need to call SendAction because no states change.
				It may be desirable to make a distinction between generating
				and appending, but nothing seems apparent now -- other than
				the fact that we are enabling controls at the bottom of this
				through a mechanism outside of the state machine.


*****************************************************************************/
void CAPIGenDlg::OnAppendSource()
{
	CString csFunctionName;
	int nPosition=0;
	
	nPosition = m_listTranslateAPI.GetCurSel();
	LoadArgumentArray( &nPosition );
	cagtest->appendBody( nPosition, m_bPromptForValues, &csaArguments, &csaHeader, &csaBody );

	m_ButtonAppendSource.EnableWindow(TRUE);
	m_buttonFinalizeListing.EnableWindow(TRUE);
	m_ButtonGenerateSource.EnableWindow(FALSE);
	m_listTranslateLanguage.EnableWindow(FALSE);
	m_listTranslateAPI.EnableWindow(FALSE);

	WriteToView( m_bCheckFileInsert );

	m_listTranslateFunction.SetFocus();

}