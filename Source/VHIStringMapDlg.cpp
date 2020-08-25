// VHIStringMapDlg.cpp : implementation file
//

#include "stdafx.h"
#include "APIGen.h"
#include "VHIStringMapDlg.h"


int CVHIStringMapDlg::m_currRow=0;
int CVHIStringMapDlg::m_currCol=0;

// CVHIStringMapDlg dialog

IMPLEMENT_DYNAMIC(CVHIStringMapDlg, CDialog)
CVHIStringMapDlg::CVHIStringMapDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CVHIStringMapDlg::IDD, pParent)
	, csEditVHIName(_T(""))
	, csEditVHIValue(_T(""))
{
}

CVHIStringMapDlg::~CVHIStringMapDlg()
{
}

void CVHIStringMapDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDCHECK_ADDNEWSTRINGMAP, chkNewStringMap);
	DDX_Control(pDX, IDEDIT_VHI_STRINGMAP_NAME, editVHIName);
	DDX_Text(pDX, IDEDIT_VHI_STRINGMAP_NAME, csEditVHIName);
	DDX_Control(pDX, IDEDIT_VHI_STRINGMAP_VALUE, editVHIValue);
	DDX_Text(pDX, IDEDIT_VHI_STRINGMAP_VALUE, csEditVHIValue);
	DDX_Control(pDX, IDLIST_VHI_STRINGMAPPAIRS, lcVHINameValueList);
}


BEGIN_MESSAGE_MAP(CVHIStringMapDlg, CDialog)
	ON_BN_CLICKED(IDBUTTON_VHI_STRINGMAP_ADD, AddNameValuePair)
	ON_BN_CLICKED(IDBUTTON_VHI_STRINGMAP_REMOVE, RemoveNameValuePair)
END_MESSAGE_MAP()


// CVHIStringMapDlg message handlers
BOOL CVHIStringMapDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	chkNewStringMap.SetCheck( BST_UNCHECKED );
	chkNewStringMap.EnableWindow(FALSE);

    int WIDTH_NAME = 100;	//pixels
    int WIDTH_VALUE	= 160;


	CString strColumn;

	strColumn="Name";
	lcVHINameValueList.InsertColumn(0,
		                       strColumn,
							   LVCFMT_LEFT, 
							   WIDTH_NAME);

	strColumn="Value";
	lcVHINameValueList.InsertColumn(1,
		                       strColumn,
							   LVCFMT_LEFT, 
							   WIDTH_VALUE );


	return TRUE;  // return TRUE  unless you set the focus to a control
}


void CVHIStringMapDlg::OnOK() 
{
	CDialog::OnOK();
	
	
	for ( int i=0; i<lcVHINameValueList.GetItemCount(); i++ )
	{
		csaNameValuePairs.Add( lcVHINameValueList.GetItemText( i, 0 ) );
		csaNameValuePairs.Add( lcVHINameValueList.GetItemText( i, 1 ) );
	}

	m_currRow=0;
	m_currCol=0;

}

void CVHIStringMapDlg::AddNameValuePair()
{
	UpdateData();
	if ( 0 != csEditVHIName.GetLength() && 0 != csEditVHIValue.GetLength() )
	{
		lcVHINameValueList.InsertItem( m_currRow, "", NULL);
		lcVHINameValueList.SetItemText(m_currRow, m_currCol++, csEditVHIName );
		lcVHINameValueList.SetItemText(m_currRow, m_currCol, csEditVHIValue );
		lcVHINameValueList.Update( m_currRow++ );
		m_currCol=0;
	}
}

void CVHIStringMapDlg::RemoveNameValuePair()
{
	POSITION pos = lcVHINameValueList.GetFirstSelectedItemPosition();
	int i = lcVHINameValueList.GetNextSelectedItem(pos);
	lcVHINameValueList.DeleteItem( i );
}
