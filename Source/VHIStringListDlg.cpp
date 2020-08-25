// VHIStringListDlg.cpp : implementation file
//

#include "stdafx.h"
#include "APIGen.h"
#include "VHIStringListDlg.h"

int CVHIStringListDlg::m_currRow=0;
int CVHIStringListDlg::m_currCol=0;

// CVHIStringListDlg dialog

IMPLEMENT_DYNAMIC(CVHIStringListDlg, CDialog)
CVHIStringListDlg::CVHIStringListDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CVHIStringListDlg::IDD, pParent)
	, csEditVHINewString(_T(""))
{
}

CVHIStringListDlg::~CVHIStringListDlg()
{
}

void CVHIStringListDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDCHECK_ADDNEWSTRINGLIST, chkNewStringList);
	DDX_Control(pDX, IDEDIT_VHI_STRINGLIST_STRING, editVHINewString);
	DDX_Text(pDX, IDEDIT_VHI_STRINGLIST_STRING, csEditVHINewString);
	DDX_Control(pDX, IDLIST_VHI_STRINGLIST, lcVHINewStringList);
}


BEGIN_MESSAGE_MAP(CVHIStringListDlg, CDialog)
	ON_BN_CLICKED(IDBUTTON_VHI_STRINGLIST_ADD, AddNewString)
	ON_BN_CLICKED(IDBUTTON_VHI_STRINGLIST_REMOVE, RemoveString)
END_MESSAGE_MAP()


BOOL CVHIStringListDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	chkNewStringList.SetCheck( BST_UNCHECKED );
	chkNewStringList.EnableWindow(FALSE);

    int WIDTH_STRING = 260;	//pixels

	CString strColumn;

	strColumn="String list";
	lcVHINewStringList.InsertColumn(0,
		                       strColumn,
							   LVCFMT_LEFT, 
							   WIDTH_STRING);

	return TRUE;  // return TRUE  unless you set the focus to a control
}


void CVHIStringListDlg::OnOK() 
{
	CDialog::OnOK();
	
	
	for ( int i=0; i<lcVHINewStringList.GetItemCount(); i++ )
	{
		csaNewStringList.Add( lcVHINewStringList.GetItemText( i, 0 ) );
	}

	m_currRow=0;
	m_currCol=0;

}


// CVHIStringListDlg message handlers

void CVHIStringListDlg::AddNewString()
{
	UpdateData();
	if ( 0 != csEditVHINewString.GetLength()  )
	{
		lcVHINewStringList.InsertItem( m_currRow, "", NULL);
		lcVHINewStringList.SetItemText(m_currRow, 0, csEditVHINewString );
		lcVHINewStringList.Update( m_currRow++ );
//		m_currCol=0;
	}
}



void CVHIStringListDlg::RemoveString()
{
	POSITION pos = lcVHINewStringList.GetFirstSelectedItemPosition();
	int i = lcVHINewStringList.GetNextSelectedItem(pos);
	lcVHINewStringList.DeleteItem( i );
}
