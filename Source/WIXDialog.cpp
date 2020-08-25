// WIXDialog.cpp : implementation file
//

#include "stdafx.h"
#include "APIGen.h"
#include "WIXDialog.h"


// CWIXDialog dialog

IMPLEMENT_DYNAMIC(CWIXDialog, CDialog)
CWIXDialog::CWIXDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CWIXDialog::IDD, pParent)
	, csBitmapID(_T(""))
	, csBitmapPath(_T(""))
	, csDialogIDName(_T(""))
	, csDialogTitle(_T(""))
{
}

CWIXDialog::~CWIXDialog()
{
}

void CWIXDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDEDIT_WIX_BMP_ID, csBitmapID);
	DDX_Text(pDX, IDEDIT_WIX_BMP_FILE, csBitmapPath);
	DDX_Text(pDX, IDEDIT_WIX_DLG_ID, csDialogIDName);
	DDX_Text(pDX, IDEDIT_WIX_DLG_TITLE, csDialogTitle);
	DDX_Control(pDX, IDEDIT_WIX_BMP_FILE, cEdit_WIX_BMP);
}


BEGIN_MESSAGE_MAP(CWIXDialog, CDialog)
	ON_BN_CLICKED(IDBUTTON_WIX_BMP, BrowseWixBmp)
END_MESSAGE_MAP()


// CWIXDialog message handlers
// CVHIStringMapDlg message handlers
BOOL CWIXDialog::OnInitDialog()
{
	CDialog::OnInitDialog();

    int WIDTH_NAME = 100;	//pixels
    int WIDTH_VALUE	= 160;




	return TRUE;  // return TRUE  unless you set the focus to a control
}


void CWIXDialog::OnOK() 
{
	CDialog::OnOK();
	

}

void CWIXDialog::BrowseWixBmp()
{
	char szFilter[128];
	char* pszFilter = szFilter;
	strcpy_s( pszFilter, 51, "Windows bitmap (*.bmp)|*.bmp|All Files (*.*)|*.*||" );

	CFileDialog fileDialog(true, NULL, NULL, (OFN_FILEMUSTEXIST | OFN_HIDEREADONLY | OFN_LONGNAMES | OFN_PATHMUSTEXIST), pszFilter); 

	fileDialog.m_ofn.lpstrTitle = _T("Specify new dialog's background image");

	TCHAR filenameBuffer[4096] = { 0 } ;
	fileDialog.m_ofn.lpstrFile = filenameBuffer;
	fileDialog.m_ofn.nMaxFile = sizeof(filenameBuffer) / sizeof(filenameBuffer[0]);


	// open the recording file that we're going to convert to a test file

	if (IDOK == fileDialog.DoModal())
	{
		csBitmapPath = fileDialog.GetPathName();
	}   
	else
	{
		csBitmapPath = "./dlg_background.bmp";
	}

	cEdit_WIX_BMP.SetWindowText( csBitmapPath );
}
