#include "stdafx.h"
#include "APIGen.h"
#include "APIGenDlg.h"

/****************************************************************************DC
	Function	:	CAPIGenDlg::HideParameterControls()

	Purpose		:	Hide all of the parameter controls before writing
					those associated with the newly selected function.

*****************************************************************************/
void CAPIGenDlg::HideParameterControls()
{
	// parameter pane's group box
	m_groupAddParameterGroup.ShowWindow( SW_HIDE  );
	m_groupNoParametersNeeded.ShowWindow( SW_HIDE  );

	// 4 Argument API's
	m_staticString1.ShowWindow( SW_HIDE  );
	m_EditFunctionString.ShowWindow( SW_HIDE  );
	m_EditFunctionString.Clear();

	m_staticString2.ShowWindow( SW_HIDE  );
	m_EditStringLength.ShowWindow( SW_HIDE  );
	m_EditStringLength.Clear();

	m_staticString3.ShowWindow( SW_HIDE  );
	m_EditReturnCode.ShowWindow( SW_HIDE  );
	m_EditReturnCode.Clear();

	// OLE
	m_staticRow.ShowWindow( SW_HIDE );
	m_EditRow.ShowWindow( SW_HIDE );
	m_EditRow.Clear();
	m_staticColumn.ShowWindow( SW_HIDE );
	m_EditColumn.ShowWindow( SW_HIDE );
	m_EditColumn.Clear();
	m_staticLength.ShowWindow( SW_HIDE );
	m_EditLength.ShowWindow( SW_HIDE );
	m_EditLength.Clear();
	m_staticPutString.ShowWindow( SW_HIDE );
	m_EditPutString.ShowWindow( SW_HIDE );
	m_staticRowsMoved.ShowWindow( SW_HIDE );
	m_staticColumnsMoved.ShowWindow( SW_HIDE );

	m_staticTimeout.ShowWindow( SW_HIDE );
	m_staticUserKeys.ShowWindow( SW_HIDE );
	m_editUserKeys.ShowWindow( SW_HIDE );
	m_editTimeout.ShowWindow( SW_HIDE );
	m_checkContinueToProcess.ShowWindow( SW_HIDE );

	m_staticSettleTime.ShowWindow( SW_HIDE );
	m_EditSettleTime.ShowWindow( SW_HIDE );

	m_staticCloseOption.ShowWindow( SW_HIDE );
	m_editCloseOption.ShowWindow( SW_HIDE );

	m_buttonBrowseFileTransferScheme.ShowWindow( SW_HIDE );
	m_EditFileTransferScheme.ShowWindow( SW_HIDE );
	m_checkSetFileTransferScheme.ShowWindow( SW_HIDE );
	m_staticFileTransferScheme.ShowWindow( SW_HIDE );
	m_checkLanguage.ShowWindow( SW_HIDE );
	m_staticLanguage.ShowWindow( SW_HIDE );
	m_checkLocalMode.ShowWindow( SW_HIDE  );
	m_checkSetMenuVisible.ShowWindow( SW_HIDE  );
	m_checkSetSessionQuiet.ShowWindow( SW_HIDE  );

	// VBScript
	m_staticKeyboardMap.ShowWindow( SW_HIDE );
	m_EditKeyboardMapName.ShowWindow( SW_HIDE );
	m_checkKeyboardMap.ShowWindow( SW_HIDE );
	m_ButtonBrowseKeyMap.ShowWindow( SW_HIDE );
	m_listFieldType.ShowWindow( SW_HIDE  );
	m_staticFieldType.ShowWindow( SW_HIDE  );
	m_staticMnemonicType.ShowWindow( SW_HIDE  );
	m_listMnemonicType.ShowWindow( SW_HIDE  );
	m_staticHostCharSet.ShowWindow( SW_HIDE );
	m_staticHostCodePage.ShowWindow( SW_HIDE );
	m_staticScreenModel.ShowWindow( SW_HIDE  );
	m_listScreenModel.ShowWindow( SW_HIDE  );

	m_staticIdleTime.ShowWindow( SW_HIDE  );
	
	m_staticPC_Filename.ShowWindow( SW_HIDE  );
	m_staticHostFileName.ShowWindow( SW_HIDE  );
	m_editPC_Filename.ShowWindow( SW_HIDE  );
	m_editHostFileName.ShowWindow( SW_HIDE  );
	m_checkShowFTProgress.ShowWindow( SW_HIDE  );
	m_buttonBrowseFileTransfer.ShowWindow( SW_HIDE  );

	m_checkSetVisible.ShowWindow( SW_HIDE  );
	m_checkContinuousWait.ShowWindow( SW_HIDE  );

	m_staticNewHeight.ShowWindow( SW_HIDE  );
	m_staticNewWidth.ShowWindow( SW_HIDE  );

	m_checkSetHeight.ShowWindow( SW_HIDE  );
	m_checkSetWidth.ShowWindow( SW_HIDE  );

	m_editHeight.ShowWindow( SW_HIDE );
	m_editWidth.ShowWindow( SW_HIDE );

	m_checkSetWindowState.ShowWindow( SW_HIDE );
	m_staticWindowState.ShowWindow( SW_HIDE );
	m_listWindowState.ShowWindow( SW_HIDE );

	m_staticSessionFileName.ShowWindow( SW_HIDE );
	m_editSessionFilename.ShowWindow( SW_HIDE );
	m_buttonSessionFilename.ShowWindow( SW_HIDE );

	m_checkSetTimeoutValue.ShowWindow( SW_HIDE );

	// CRL JavaScript
	m_staticTelnetAddress.ShowWindow( SW_HIDE );
	m_staticTelnetPort.ShowWindow( SW_HIDE );
	m_staticSocksAddress.ShowWindow( SW_HIDE );
	m_staticSocksPort.ShowWindow( SW_HIDE );

	cb_PassiveMode.ShowWindow( SW_HIDE );
	cbEABsEnabled.ShowWindow( SW_HIDE );

	m_staticString4.ShowWindow( SW_HIDE );
	m_staticString5.ShowWindow( SW_HIDE );
	m_staticString6.ShowWindow( SW_HIDE );
	m_staticString7.ShowWindow( SW_HIDE );
	m_staticString8.ShowWindow( SW_HIDE );
	m_staticString9.ShowWindow( SW_HIDE );
	m_staticString10.ShowWindow( SW_HIDE );
	m_staticString11.ShowWindow( SW_HIDE );
	m_staticString12.ShowWindow( SW_HIDE );
	m_staticString13.ShowWindow( SW_HIDE );
	m_staticString14.ShowWindow( SW_HIDE );

	m_EditArgument1.ShowWindow( SW_HIDE );
	m_EditArgument1.Clear();
	m_EditArgument2.ShowWindow( SW_HIDE );
	m_EditArgument2.Clear();
	m_EditArgument3.ShowWindow( SW_HIDE );
	m_EditArgument3.Clear();
	m_EditArgument4.ShowWindow( SW_HIDE );
	m_EditArgument4.Clear();
	m_EditArgument5.ShowWindow( SW_HIDE );
	m_EditArgument5.Clear();
	m_EditArgument6.ShowWindow( SW_HIDE );
	m_EditArgument6.Clear();
	m_EditArgument7.ShowWindow( SW_HIDE );
	m_EditArgument7.Clear();
	m_EditArgument8.ShowWindow( SW_HIDE );
	m_EditArgument8.Clear();
	m_EditArgument9.ShowWindow( SW_HIDE );
	m_EditArgument9.Clear();
	m_EditArgument10.ShowWindow( SW_HIDE );
	m_EditArgument10.Clear();
	m_EditArgument11.ShowWindow( SW_HIDE );
	m_EditArgument11.Clear();
	m_EditArgument12.ShowWindow( SW_HIDE );
	m_EditArgument12.Clear();
	m_EditArgument13.ShowWindow( SW_HIDE );
	m_EditArgument13.Clear();
	m_EditArgument14.ShowWindow( SW_HIDE );
	m_EditArgument14.Clear();

	m_listTransferType.ShowWindow( SW_HIDE );
	m_listFileExists.ShowWindow( SW_HIDE );

	listParams1.ShowWindow( SW_HIDE );
	listParams2.ShowWindow( SW_HIDE );
	listParams3.ShowWindow( SW_HIDE );
	listParams4.ShowWindow( SW_HIDE );
	listParams5.ShowWindow( SW_HIDE );

	listMultiParams1.ShowWindow( SW_HIDE );
	listMultiParams2.ShowWindow( SW_HIDE );
	listMultiParams3.ShowWindow( SW_HIDE );
	listMultiParams4.ShowWindow( SW_HIDE );

	checkParam1.ShowWindow( SW_HIDE );
	checkParam2.ShowWindow( SW_HIDE );
	checkParam3.ShowWindow( SW_HIDE );
	checkParam4.ShowWindow( SW_HIDE );

}




/****************************************************************************DC
	Function	:	CAPIGenDlg::OnFtSchemeName()

	Purpose		:	Get the FT scheme name.

*****************************************************************************/
void CAPIGenDlg::OnFtSchemeName() 
{
	CFileDialog fileDialog(true, NULL, NULL,
    (OFN_FILEMUSTEXIST | OFN_HIDEREADONLY | OFN_LONGNAMES | OFN_PATHMUSTEXIST),
    _T("Recording files (*.eis)|*.eis|All Files (*.*)|*.*||"));

	fileDialog.m_ofn.lpstrTitle = _T("Specify file transfer scheme");

	TCHAR filenameBuffer[4096] = { 0 } ;
	fileDialog.m_ofn.lpstrFile = filenameBuffer;
	fileDialog.m_ofn.nMaxFile = sizeof(filenameBuffer) / sizeof(filenameBuffer[0]);


	// open the recording file that we're going to convert to a test file
	if (IDOK == fileDialog.DoModal())
	{
		m_csEditFileTransferScheme = fileDialog.GetPathName();
		m_EditArgument1.SetWindowText( m_csEditFileTransferScheme );
		UpdateData( TRUE );
	}   

}



/****************************************************************************DC
	Function	:	CAPIGenDlg::OnCheckFTSchemeCheckBox()

	Purpose		:	Enables/disables the FT scheme UI.

*****************************************************************************/
void CAPIGenDlg::OnCheckFTSchemeCheckBox() 
{
	UpdateData();

	if ( m_bSetFileTransferScheme )
	{
		m_EditFileTransferScheme.EnableWindow( TRUE );
		m_buttonBrowseFileTransferScheme.EnableWindow( TRUE );
	}
	else
	{
		m_EditFileTransferScheme.EnableWindow( FALSE );
		m_buttonBrowseFileTransferScheme.EnableWindow( FALSE );
	}

}



/****************************************************************************DC
	Function	:	CAPIGenDlg::OnSettimeout()

	Purpose		:	Enables/disables the System::SetTimeout UI.

*****************************************************************************/
void CAPIGenDlg::OnSettimeout() 
{
	UpdateData();

	if ( m_bCheckSetTimeoutValue )
	{
		m_EditRow.EnableWindow( TRUE );
	}
	else
	{
		m_EditRow.EnableWindow( FALSE );
	}

}


/****************************************************************************DC
	Function	:	CAPIGenDlg::OnBrowseKeymap()

	Purpose		:	File dialog for selecting keymap.

*****************************************************************************/
void CAPIGenDlg::OnBrowseKeymap() 
{
	CFileDialog fileDialog(true, NULL, NULL,
    (OFN_FILEMUSTEXIST | OFN_HIDEREADONLY | OFN_LONGNAMES | OFN_PATHMUSTEXIST),
    _T("Recording files (*.ekm)|*.ekm|All Files (*.*)|*.*||"));

	fileDialog.m_ofn.lpstrTitle = _T("Specify key map file");

	TCHAR filenameBuffer[4096] = { 0 } ;
	fileDialog.m_ofn.lpstrFile = filenameBuffer;
	fileDialog.m_ofn.nMaxFile = sizeof(filenameBuffer) / sizeof(filenameBuffer[0]);


	// open the recording file that we're going to convert to a test file
	if (IDOK == fileDialog.DoModal())
	{
		m_csKeyboardMapName = fileDialog.GetPathName();
		m_EditArgument1.SetWindowText( m_csKeyboardMapName );
		UpdateData( TRUE );
	}   
}



/****************************************************************************DC
	Function	:	CAPIGenDlg::OnKeyboardMap()

	Purpose		:	Enables/disables the keyboard map UI.

*****************************************************************************/
void CAPIGenDlg::OnKeyboardMap() 
{
	UpdateData();

	if ( m_bCheckKeyboardMap )
	{
		m_EditKeyboardMapName.EnableWindow( TRUE );
		m_ButtonBrowseKeyMap.EnableWindow( TRUE );
	}
	else
	{
		m_EditKeyboardMapName.EnableWindow( FALSE );
		m_ButtonBrowseKeyMap.EnableWindow( FALSE );
	}

}


/****************************************************************************DC
	Function	:	CAPIGenDlg::OnBrowseFileTransFilename()

	Purpose		:	File dialog for selecting file transfer PC filename.

*****************************************************************************/
void CAPIGenDlg::OnBrowseFileTransFilename() 
{
	CFileDialog fileDialog(true, NULL, NULL,
    (OFN_FILEMUSTEXIST | OFN_HIDEREADONLY | OFN_LONGNAMES | OFN_PATHMUSTEXIST),
    _T("Recording files (*.*)|*.*|All Files (*.*)|*.*||"));

	fileDialog.m_ofn.lpstrTitle = _T("Specify PC-side filename");

	TCHAR filenameBuffer[4096] = { 0 } ;
	fileDialog.m_ofn.lpstrFile = filenameBuffer;
	fileDialog.m_ofn.nMaxFile = sizeof(filenameBuffer) / sizeof(filenameBuffer[0]);


	// open the recording file that we're going to convert to a test file
	if (IDOK == fileDialog.DoModal())
	{
		m_csEditArgument1 = fileDialog.GetPathName();
		m_EditArgument1.SetWindowText( m_csEditArgument1 );
		UpdateData( TRUE );
	}   
}

/****************************************************************************DC
	Function	:	CAPIGenDlg::OnCheckLanguage()

	Purpose		:	Enables/disables the specify-language UI.

*****************************************************************************/
void CAPIGenDlg::OnCheckLanguage() 
{
	UpdateData();

	if ( m_bCheckLanguage )
	{
		m_EditKeyboardMapName.EnableWindow( TRUE );
	}
	else
	{
		m_EditKeyboardMapName.EnableWindow( FALSE );
	}

}


/****************************************************************************DC
	Function	:	CAPIGenDlg::OnSetHeight()

	Purpose		:	Enables/disables the specify-height UI.

*****************************************************************************/
void CAPIGenDlg::OnSetHeight() 
{
	UpdateData();

	if ( m_bCheckSetHeight )
	{
		m_editHeight.EnableWindow( TRUE );
	}
	else
	{
		m_editHeight.EnableWindow( FALSE );
	}
	
}


/****************************************************************************DC
	Function	:	CAPIGenDlg::OnSetWidth()

	Purpose		:	Enables/disables the specify-width UI.

*****************************************************************************/
void CAPIGenDlg::OnSetWidth() 
{
	UpdateData();

	if ( m_bCheckSetWidth )
	{
		m_editWidth.EnableWindow( TRUE );
	}
	else
	{
		m_editWidth.EnableWindow( FALSE );
	}
	
}



/****************************************************************************DC
	Function	:	CAPIGenDlg::OnSetWindowState()

	Purpose		:	Enables/disables the specify-state UI.

*****************************************************************************/
void CAPIGenDlg::OnSetWindowState() 
{
	UpdateData();

	if ( m_bCheckSetWindowState )
	{
		m_listWindowState.EnableWindow( TRUE );
	}
	else
	{
		m_listWindowState.EnableWindow( FALSE );
	}
	
}



void CAPIGenDlg::OnSessionFileName() 
{
	CFileDialog fileDialog(true, NULL, NULL,
    (OFN_FILEMUSTEXIST | OFN_HIDEREADONLY | OFN_LONGNAMES | OFN_PATHMUSTEXIST),
    _T("Recording files (*.edp)|*.adp|All Files (*.*)|*.*||"));

	fileDialog.m_ofn.lpstrTitle = _T("Select session file");

	TCHAR filenameBuffer[4096] = { 0 } ;
	fileDialog.m_ofn.lpstrFile = filenameBuffer;
	fileDialog.m_ofn.nMaxFile = sizeof(filenameBuffer) / sizeof(filenameBuffer[0]);


	// open the recording file that we're going to convert to a test file
	if (IDOK == fileDialog.DoModal())
	{
		m_csEditSessionFilename = fileDialog.GetPathName();
		m_editSessionFilename.SetWindowText( m_csEditSessionFilename );
		UpdateData( TRUE );
	}   
}
