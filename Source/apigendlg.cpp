
// APIGenDlg.cpp : implementation file
//

#include "stdafx.h"
#include "stdio.h"
#include "APIGen.h"
#include "APIGenDlg.h"
#include "APIGenState.h"
#include "afxwin.h"
#include "afxcmn.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CAG* CAPIGenDlg::cagtest=NULL;

int		CAPIGenDlg::WidthBig=0;
int		CAPIGenDlg::WidthSmall=0;
int		CAPIGenDlg::HeightBig=0;
int		CAPIGenDlg::HeightSmall=0;
int		CAPIGenDlg::HeightVariable=0;
int		CAPIGenDlg::WidthVariable=0;
int		CAPIGenDlg::nAPI_Index=7;
int		CAPIGenDlg::nTerminalType_Index=0;


/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
	CListCtrl lcAboutBoxProgress;
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
	DDX_Control(pDX, IDLISTCTRL_APIGEN_ABOUT, lcAboutBoxProgress);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


BOOL CAboutDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

    int WIDTH_API_NAME		= 110;	//pixels
    int WIDTH_TERMINAL_TYPE	= 80;
	int WIDTH_LANGUAGE_NAME	= 120;
	int WIDTH_STATUS = 60;
	int WIDTH_FRACTION = 50;
	int WIDTH_CONTRIBUTOR = 180;


	CString strColumn;

	//strColumn.LoadString(ID_API_NAME);
	strColumn="API";
	lcAboutBoxProgress.InsertColumn(0,
		                       strColumn,
							   LVCFMT_LEFT, 
							   WIDTH_API_NAME);

	//strColumn.LoadString(ID_LANGUAGE_NAME);
	strColumn="Terminal type";
	lcAboutBoxProgress.InsertColumn(1,
		                       strColumn,
							   LVCFMT_LEFT, 
							   WIDTH_TERMINAL_TYPE );

	//strColumn.LoadString(ID_LANGUAGE_NAME);
	strColumn="Language";
	lcAboutBoxProgress.InsertColumn(2,
		                       strColumn,
							   LVCFMT_LEFT, 
							   WIDTH_LANGUAGE_NAME );

	//strColumn.LoadString(ID_LANGUAGE_NAME);
	strColumn="Status";
	lcAboutBoxProgress.InsertColumn(3,
		                       strColumn,
							   LVCFMT_LEFT, 
							   WIDTH_STATUS );


	strColumn="Funcs";
	lcAboutBoxProgress.InsertColumn(4,
		                       strColumn,
							   LVCFMT_LEFT, 
							   WIDTH_FRACTION );

	//strColumn.LoadString(ID_CONTRIBUTOR_STRING);
	strColumn="Contributor";
	lcAboutBoxProgress.InsertColumn(5,
		                       strColumn,
							   LVCFMT_LEFT, 
							   WIDTH_CONTRIBUTOR );

	int currRow=0;
	int currCol=0;
	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "Airlines SDK" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "3270" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "Java" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "FORM" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "59/59" );
	lcAboutBoxProgress.SetItemText(currRow, currCol, "Don Cannon" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "C++" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "TRANS" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "59/59" );
	lcAboutBoxProgress.SetItemText(currRow, currCol, "" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "C#" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "TRANS" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "0/59" );
	lcAboutBoxProgress.SetItemText(currRow, currCol, "" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "VB6" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "TRANS" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "0/59" );
	lcAboutBoxProgress.SetItemText(currRow, currCol, "" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "VB.Net" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "TRANS" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "0/59" );
	lcAboutBoxProgress.SetItemText(currRow, currCol, "" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "Airlines SDK" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "5250" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "Java" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "FORM" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "59/59" );
	lcAboutBoxProgress.SetItemText(currRow, currCol, "Don Cannon" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "C++" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "TRANS" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "59/59" );
	lcAboutBoxProgress.SetItemText(currRow, currCol, "" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "C#" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "TRANS" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "0/59" );
	lcAboutBoxProgress.SetItemText(currRow, currCol, "" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "VB6" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "TRANS" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "0/59" );
	lcAboutBoxProgress.SetItemText(currRow, currCol, "" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "VB.Net" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "TRANS" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "0/59" );
	lcAboutBoxProgress.SetItemText(currRow, currCol, "" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "Airlines SDK" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "VT" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "Java" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "FORM" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "59/59" );
	lcAboutBoxProgress.SetItemText(currRow, currCol, "Don Cannon" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "C++" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "TRANS" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "59/59" );
	lcAboutBoxProgress.SetItemText(currRow, currCol, "" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "C#" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "TRANS" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "0/59" );
	lcAboutBoxProgress.SetItemText(currRow, currCol, "" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "VB6" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "TRANS" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "0/59" );
	lcAboutBoxProgress.SetItemText(currRow, currCol, "" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "VB.Net" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "TRANS" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "0/59" );
	lcAboutBoxProgress.SetItemText(currRow, currCol, "" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "Airlines SDK" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "T27/TCPA" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "Java" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "TRANS" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "0/59" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "C++" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "TRANS" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "59/59" );
	lcAboutBoxProgress.SetItemText(currRow, currCol, "" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "C#" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "TRANS" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "0/59" );
	lcAboutBoxProgress.SetItemText(currRow, currCol, "" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "VB6" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "TRANS" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "0/59" );
	lcAboutBoxProgress.SetItemText(currRow, currCol, "" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "VB.Net" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "TRANS" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "0/59" );
	lcAboutBoxProgress.SetItemText(currRow, currCol, "" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "Airlines SDK" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "UTS/INT1" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "Java" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "TRANS" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "0/59" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "C++" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "TRANS" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "59/59" );
	lcAboutBoxProgress.SetItemText(currRow, currCol, "" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "C#" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "TRANS" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "0/59" );
	lcAboutBoxProgress.SetItemText(currRow, currCol, "" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "VB6" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "TRANS" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "0/59" );
	lcAboutBoxProgress.SetItemText(currRow, currCol, "" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "VB.Net" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "TRANS" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "0/59" );
	lcAboutBoxProgress.SetItemText(currRow, currCol, "" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "Airlines SDK" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "UTS/MATIP" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "Java" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "TRANS" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "0/59" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "C++" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "TRANS" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "59/59" );
	lcAboutBoxProgress.SetItemText(currRow, currCol, "" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "C#" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "TRANS" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "0/59" );
	lcAboutBoxProgress.SetItemText(currRow, currCol, "" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "VB6" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "TRANS" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "0/59" );
	lcAboutBoxProgress.SetItemText(currRow, currCol, "" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "VB.Net" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "TRANS" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "0/59" );
	lcAboutBoxProgress.SetItemText(currRow, currCol, "" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "Airlines SDK" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "UTS/Pepgate" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "Java" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "TRANS" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "0/59" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "C++" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "TRANS" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "59/59" );
	lcAboutBoxProgress.SetItemText(currRow, currCol, "" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "C#" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "TRANS" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "0/59" );
	lcAboutBoxProgress.SetItemText(currRow, currCol, "" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "VB6" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "TRANS" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "0/59" );
	lcAboutBoxProgress.SetItemText(currRow, currCol, "" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "VB.Net" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "TRANS" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "0/59" );
	lcAboutBoxProgress.SetItemText(currRow, currCol, "" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "Airlines SDK" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "ALC/MATIP" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "Java" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "TRANS" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "0/59" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "C++" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "TRANS" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "59/59" );
	lcAboutBoxProgress.SetItemText(currRow, currCol, "" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "C#" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "TRANS" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "0/59" );
	lcAboutBoxProgress.SetItemText(currRow, currCol, "" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "VB6" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "TRANS" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "0/59" );
	lcAboutBoxProgress.SetItemText(currRow, currCol, "" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "VB.Net" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "TRANS" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "0/59" );
	lcAboutBoxProgress.SetItemText(currRow, currCol, "" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "Airlines SDK" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "ALC/EDS SHARES" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "Java" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "TRANS" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "0/59" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "C++" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "TRANS" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "59/59" );
	lcAboutBoxProgress.SetItemText(currRow, currCol, "" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "C#" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "TRANS" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "0/59" );
	lcAboutBoxProgress.SetItemText(currRow, currCol, "" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "VB6" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "TRANS" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "0/59" );
	lcAboutBoxProgress.SetItemText(currRow, currCol, "" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "VB.Net" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "TRANS" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "0/59" );
	lcAboutBoxProgress.SetItemText(currRow, currCol, "" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "Airlines SDK" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "ALC/SABRE" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "Java" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "TRANS" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "0/59" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "C++" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "TRANS" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "59/59" );
	lcAboutBoxProgress.SetItemText(currRow, currCol, "" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "C#" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "TRANS" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "0/59" );
	lcAboutBoxProgress.SetItemText(currRow, currCol, "" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "VB6" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "TRANS" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "0/59" );
	lcAboutBoxProgress.SetItemText(currRow, currCol, "" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "VB.Net" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "TRANS" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "0/59" );
	lcAboutBoxProgress.SetItemText(currRow, currCol, "" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "Airlines SDK" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "ALC/APOLLO" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "Java" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "TRANS" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "0/59" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "C++" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "TRANS" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "59/59" );
	lcAboutBoxProgress.SetItemText(currRow, currCol, "" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "C#" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "TRANS" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "0/59" );
	lcAboutBoxProgress.SetItemText(currRow, currCol, "" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "VB6" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "TRANS" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "0/59" );
	lcAboutBoxProgress.SetItemText(currRow, currCol, "" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "VB.Net" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "TRANS" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "0/59" );
	lcAboutBoxProgress.SetItemText(currRow, currCol, "" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "Airlines SDK" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "ALC/LANTERN" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "Java" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "TRANS" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "0/59" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "C++" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "TRANS" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "0/59" );
	lcAboutBoxProgress.SetItemText(currRow, currCol, "" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "C#" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "TRANS" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "0/59" );
	lcAboutBoxProgress.SetItemText(currRow, currCol, "" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "VB6" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "TRANS" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "0/59" );
	lcAboutBoxProgress.SetItemText(currRow, currCol, "" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "VB.Net" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "TRANS" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "0/59" );
	lcAboutBoxProgress.SetItemText(currRow, currCol, "" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "Airlines SDK" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "MCS" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "Java" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "TRANS" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "0/59" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "ATMAPI32 (EAL)" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "3270" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "C++" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "TEST" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "71/71" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "Don Cannon" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "C#" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "TRANS" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "0/71" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "VB 6.0" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "TEST" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "71/71" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "Ned Gerhart" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "VB.Net" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "TRANS" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "0/71" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "ATMAPI32 (EAL)" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "5250" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "C++" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "TEST" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "71/71" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "Don Cannon" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "C#" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "TRANS" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "0/71" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "VB 6.0" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "TEST" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "71/71" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "Ned Gerhart" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "VB.Net" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "TRANS" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "0/71" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "ATMAPI32 (EAL)" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "VT" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "C++" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "TEST" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "71/71" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "Don Cannon" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "C#" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "TRANS" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "0/71" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "VB 6.0" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "TEST" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "71/71" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "Ned Gerhart" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "VB.Net" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "TRANS" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "0/71" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "CASL Macros" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "TRANS" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "8/205" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "Al La Flamme" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "CICS Bridge" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "COM" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "ASP" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "FUNC" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "6/30" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "C++" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "TRANS" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "0/30" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "VB 6.0" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "TRANS" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "0/30" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "CICS Bridge" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "CICS 1.1" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "Java" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "TRANS" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "2/89" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "CICS Bridge" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "CICS 2.0" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "Java" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "FUNC" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "36/99" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "Ned Gerhart" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "CICS Bridge" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, ".Net" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "VB.Net" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "TRANS" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "0/99" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "C#" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "TRANS" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "0/99" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "DOS Shell" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "TRANS" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "1/82" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "EAO ActiveX" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "3270" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "C++" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "FUNC" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "1/48" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "C#" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "FUNC" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "0/48" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "JavaScript" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "FUNC" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "0/48" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "VB 6.0" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "FUNC" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "0/48" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "VB.Net" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "FUNC" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "0/48" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "VBScript" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "FUNC" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "0/48" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "EAO ActiveX" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "5250" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "C++" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "FUNC" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "1/48" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "C#" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "FUNC" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "0/48" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "JavaScript" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "FUNC" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "0/48" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "VB 6.0" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "FUNC" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "0/48" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "VB.Net" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "FUNC" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "0/48" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "VBScript" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "FUNC" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "0/48" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "EAO ActiveX" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "VT" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "C++" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "FUNC" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "1/54" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "C#" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "FUNC" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "0/54" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "JavaScript" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "FUNC" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "0/54" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "VB 6.0" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "FUNC" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "0/54" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "VB.Net" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "FUNC" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "0/54" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "VBScript" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "FUNC" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "0/54" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "EAO Java" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "3270" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "Java" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "FORM" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "53/53" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "EAO Java" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "5250" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "Java" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "FORM" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "53/53" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "EAO Java" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "VT" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "Java" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "FORM" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "53/53" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "EHLAPI32" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "3270" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "C++" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "TEST" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "52/52" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "Don Cannon" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "C#" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "TRANS" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "0/52" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "VB 6.0" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "TEST" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "52/52" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "Ned Gerhart" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "VB.Net" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "TRANS" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "52/52" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "XLS" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "TEST" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "52/52" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "EHLAPI32" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "5250" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "C++" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "TEST" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "52/52" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "Don Cannon" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "C#" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "TRANS" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "0/52" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "VB 6.0" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "TEST" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "52/52" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "Ned Gerhart" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "VB.Net" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "TRANS" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "52/52" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "XLS" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "TEST" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "52/52" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "EHLAPI32" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "VT" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "C++" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "TEST" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "52/52" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "Don Cannon" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "C#" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "TRANS" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "0/52" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "VB 6.0" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "TEST" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "52/52" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "Ned Gerhart" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "VB.Net" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "TRANS" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "52/52" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "XLS" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "TEST" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "52/52" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "Extra! OLE Auto" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "3270" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "C++" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "TEST" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "72/72" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "Don Cannon" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "C#" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "TRANS" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "0/72" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "EB Macro" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "TEST" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "72/72" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "Don Cannon" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "EB Macro Test" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "TEST" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "72/72" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "Ned Gerhart" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "VB 6.0" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "TEST" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "72/72" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "Ned Gerhart" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "VBScript Node" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "TEST" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "72/72" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "Don Cannon" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "Windows Script" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "TEST" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "72/72" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "Don Cannon" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "Extra! OLE Auto" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "5250" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "C++" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "TEST" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "72/72" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "Don Cannon" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "C#" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "TRANS" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "0/72" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "EB Macro" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "TEST" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "72/72" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "Don Cannon" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "EB Macro Test" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "TEST" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "72/72" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "Ned Gerhart" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "VB 6.0" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "TEST" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "72/72" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "Ned Gerhart" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "VBScript Node" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "TEST" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "72/72" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "Don Cannon" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "Windows Script" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "TEST" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "72/72" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "Don Cannon" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "Extra! OLE Auto" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "VT" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "C++" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "TEST" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "72/72" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "Don Cannon" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "C#" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "TRANS" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "0/72" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "EB Macro" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "TEST" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "72/72" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "Don Cannon" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "EB Macro Test" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "TEST" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "72/72" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "Ned Gerhart" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "VB 6.0" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "TEST" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "72/72" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "Ned Gerhart" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "VBScript Node" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "TEST" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "72/72" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "Don Cannon" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "Windows Script" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "TEST" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "72/72" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "Don Cannon" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "Extra! OLE Auto" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "Unisys" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "CISL" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "FPR" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "Brent Dickey" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;


	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "HLLAPI32" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "3270" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "C++" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "TEST" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "41/41" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "Don Cannon" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "C#" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "TRANS" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "0/41" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "HLLAPI32" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "5250" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "C++" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "TEST" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "41/41" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "Don Cannon" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "C#" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "TRANS" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "0/41" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "HLLAPI32" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "VT" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "C++" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "TEST" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "41/41" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "Don Cannon" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "C#" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "TRANS" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "0/41" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "IHLAPI32" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "Unisys" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "C++" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "TEST" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "57/57" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "Don Cannon" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "C#" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "TRANS" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "0/57" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "VB 6.0" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "TEST" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "57/57" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "Ned Gerhart" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "VB.Net" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "TRANS" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "0/57" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "MCS ActiveX" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "3270" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "JS CRL" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "FUNC" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "3/48" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "JS Deployed" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "FUNC" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "3/48" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "JS HDR" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "FUNC" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "3/48" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "JS HTML" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "FUNC" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "3/48" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "VBScript CRL" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "TRANS" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "VBScript Deployed" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "FUNC" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "3/48" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "VBScript HDR" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "FUNC" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "3/48" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "VBScript HTML" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "FUNC" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "3/48" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "MCS ActiveX" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "5250" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "JS CRL" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "FUNC" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "3/48" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "JS Deployed" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "FUNC" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "3/48" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "JS HDR" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "FUNC" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "3/48" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "JS HTML" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "FUNC" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "3/48" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "VBScript CRL" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "TRANS" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "VBScript Deployed" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "FUNC" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "3/48" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "VBScript HDR" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "FUNC" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "3/48" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "VBScript HTML" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "FUNC" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "3/48" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "MCS ActiveX" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "VT" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "JS CRL" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "FUNC" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "3/48" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "JS Deployed" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "FUNC" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "3/48" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "JS HDR" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "FUNC" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "3/48" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "JS HTML" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "FUNC" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "3/48" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "VBScript CRL" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "TRANS" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "VBScript Deployed" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "FUNC" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "3/48" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "VBScript HDR" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "FUNC" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "3/48" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "VBScript HTML" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "FUNC" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "3/48" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "MCS Java" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "3270" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "JS CRL" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "TRANS" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "53/53" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "Don Cannon" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "JS Deployed" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "FORM" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "53/53" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "JS HDR" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "TEST" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "53/53" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "Don Cannon" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "JS HTML" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "FUNC" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "53/53" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "VBScript CRL" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "TEST" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "53/53" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "Don Cannon" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "VBScript Deployed" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "FORM" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "53/53" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "VBScript HDR" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "TEST" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "53/53" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "Don Cannon" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "VBScript HTML" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "FORM" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "53/53" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "MCS Java" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "5250" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "JS CRL" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "TRANS" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "53/53" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "Don Cannon" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "JS Deployed" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "FORM" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "53/53" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "JS HDR" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "TEST" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "53/53" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "Don Cannon" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "JS HTML" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "FUNC" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "53/53" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "VBScript CRL" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "TEST" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "53/53" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "Don Cannon" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "VBScript Deployed" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "FORM" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "53/53" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "VBScript HDR" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "TEST" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "53/53" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "Don Cannon" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "VBScript HTML" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "FORM" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "53/53" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "MCS Java" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "VT" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "JS CRL" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "TRANS" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "53/53" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "Don Cannon" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "JS Deployed" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "FORM" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "53/53" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "JS HDR" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "TEST" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "53/53" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "Don Cannon" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "JS HTML" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "FUNC" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "53/53" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "VBScript CRL" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "TEST" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "53/53" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "Don Cannon" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "VBScript Deployed" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "FORM" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "53/53" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "VBScript HDR" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "TEST" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "53/53" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "Don Cannon" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "VBScript HTML" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "FORM" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "53/53" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;


	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "MSI" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "Installer App" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "C++" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "FUNC" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "1/81" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "Don Cannon" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "VBScript" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "FUNC" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "1/81" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "Don Cannon" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "Windows Script" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "FUNC" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "1/81" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "Don Cannon" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "MSI" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "Custom Action DLL" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "C++" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "FUNC" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "4/65" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "Don Cannon" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "VBScript" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "FUNC" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "1/65" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "Don Cannon" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "Windows Script" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "FUNC" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "1/65" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "Don Cannon" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "MSI" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "Database App" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "C++" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "FUNC" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "1/70" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "Don Cannon" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "VBScript" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "FUNC" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "1/70" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "Don Cannon" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "Windows Script" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "FUNC" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "1/70" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "Don Cannon" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "MSI" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "MSIExec" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "FUNC" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "0/18" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "Don Cannon" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "MSI" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "Summary Info" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "FUNC" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "4/18" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "Don Cannon" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "MSI" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "WIX dialog" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "XML" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "TEST" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "8/8" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "Don Cannon" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "MSI" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "WIX wizard" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "XML" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "FUNC" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "1/8" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "Don Cannon" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "Perforce" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "P4 Commands" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "FUNC" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "8/71" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "Don Cannon" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "PCSHLL32" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "3270" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "C++" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "TEST" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "32/32" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "Don Cannon" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "VB 6.0" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "TEST" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "32/32" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "Ned Gerhart" );

	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "PCSHLL32" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "5250" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "C++" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "TEST" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "32/32" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "Don Cannon" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "VB 6.0" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "TEST" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "32/32" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "Ned Gerhart" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "PCSHLL32" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "VT" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "C++" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "TEST" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "32/32" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "Don Cannon" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "VB 6.0" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "TEST" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "32/32" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "Ned Gerhart" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;


	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "Reflection FTP" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "C++" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "FORM" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "19/19" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "Don Cannon" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "C#" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "TRANS" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "0/19" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "VB 6.0" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "TRANS" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "0/19" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "Geoff Pfander" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "VB.Net" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "TRANS" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "0/19" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "Reflection for Web" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "3270" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "Java" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "FUNC" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "2/240" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "JavaScript" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "FUNC" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "2/240" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "VBScript" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "FUNC" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "2/240" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "Reflection for Web" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "5250" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "Java" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "FUNC" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "2/240" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "JavaScript" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "FUNC" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "2/240" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "VBScript" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "FUNC" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "2/240" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "Reflection for Web" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "HP" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "Java" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "TRANS" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "FUNC" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "0/241" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "JavaScript" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "FUNC" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "0/241" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "VBScript" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "TRANS" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "0/241" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "Reflection for Web" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "VT" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "Java" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "FUNC" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "0/241" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "JavaScript" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "FUNC" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "1/241" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "VBScript" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "FUNC" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "0/241" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "Reflection OLE Auto" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "3270" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "C++" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "FUNC" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "2/232" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "VB 6.0" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "FUNC" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "0/232" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "VB.Net" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "FUNC" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "0/232" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "Windows Script" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "FUNC" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "31/232" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "Don Cannon" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "VBA" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "TRANS" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "0/232" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "Reflection OLE Auto" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "5250" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "C++" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "FUNC" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "2/232" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "VB 6.0" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "FUNC" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "0/232" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "VB.Net" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "FUNC" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "0/232" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "Windows Script" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "FUNC" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "31/232" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "Don Cannon" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "VBA" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "FUNC" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "0/232" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "Reflection OLE Auto" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "HP" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "C++" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "FUNC" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "1/149" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "VB 6.0" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "FUNC" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "0/149" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "VB.Net" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "FUNC" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "0/149" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "Windows Script" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "FUNC" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "0/149" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "VBA" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "FUNC" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "0/149" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "Reflection OLE Auto" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "VT" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "C++" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "FUNC" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "VB 6.0" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "FUNC" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "VB.Net" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "FUNC" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "Windows Script" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "FUNC" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "VBA" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "FUNC" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "Synapta" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "IConnectorAccess" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "Java" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "TEST" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "11/11" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "Don Cannon" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "ASP" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "TRANS" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "11/11" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "Don Cannon" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "C#" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "TRANS" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "0/11" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "VB.Net" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "TRANS" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "0/11" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "Windows Script" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "FUNC" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "0/11" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "Synapta" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "ITask" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "Java" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "TEST" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "22/22" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "Don Cannon" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "Synapta" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "ScreenNativeAccess" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "Java" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "FUNC" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "0/44" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "Don Cannon" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "UNIX Shell" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "FUNC" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "7/33" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "Don Cannon" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "Verastream" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "C#" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "FUNC" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "0/93" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "VB 6.0" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "FUNC" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "16/93" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "Don Cannon" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "VB.Net" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "FUNC" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "0/93" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "Don Cannon" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "Windows Script" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "FUNC" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "0/93" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "Don Cannon" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "ViewMaster" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "3270" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "JavaScript" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "TEST" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "43/43" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "Don Cannon" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "VBScript" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "TEST" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "43/43" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "Don Cannon" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "ViewMaster" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "5250" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "JavaScript" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "TRANS" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "43/43" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "Don Cannon" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "VBScript" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "TRANS" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "43/43" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "Don Cannon" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "ViewMaster" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "T27/TCPA" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "JavaScript" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "TEST" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "43/43" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "Don Cannon" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "VBScript" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "TEST" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "43/43" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "Don Cannon" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;


	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "ViewMaster" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "VT" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "JavaScript" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "TRANS" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "43/43" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "Don Cannon" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "VBScript" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "TRANS" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "43/43" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "Don Cannon" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "ViewMaster" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "UTS/INT1" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "JavaScript" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "TEST" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "43/43" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "Don Cannon" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "VBScript" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "TEST" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "43/43" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "Don Cannon" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "WHLAPI32" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "3270" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "C++" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "TEST" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "57/57" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "Don Cannon" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "C#" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "TRANS" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "57/57" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );

	lcAboutBoxProgress.SetItemText( currRow, currCol++, "VB 6.0" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "TEST" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "57/57" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "Ned Gerhart" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "VB.Net" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "TRANS" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "57/57" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "WHLAPI32" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "5250" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "C++" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "TEST" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "57/57" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "Don Cannon" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "C#" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "TRANS" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "57/57" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "VB 6.0" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "TEST" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "57/57" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "Ned Gerhart" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "VB.Net" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "TRANS" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "57/57" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "WHLAPI32" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "VT" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "C++" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "TEST" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "57/57" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "Don Cannon" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "C#" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "TRANS" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "57/57" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "VB 6.0" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "TEST" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "57/57" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "Ned Gerhart" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	lcAboutBoxProgress.InsertItem( currRow, "", NULL);
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "VB.Net" );
	lcAboutBoxProgress.SetItemText( currRow, currCol++, "TRANS" );
	lcAboutBoxProgress.SetItemText(currRow, currCol++, "57/57" );
	lcAboutBoxProgress.SetItemText( currRow, currCol, "" );
	lcAboutBoxProgress.Update( currRow++ );
	currCol=0;

	return TRUE;  // return TRUE  unless you set the focus to a control
}

/////////////////////////////////////////////////////////////////////////////
// CAPIGenDlg dialog

CAPIGenDlg::CAPIGenDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CAPIGenDlg::IDD, pParent)
	, m_csEditArgument1(_T(""))
	, m_csEditArgument2(_T(""))
	, m_csEditArgument3(_T(""))
	, m_csEditArgument4(_T(""))
	, m_csEditArgument5(_T(""))
	, bPassiveMode(FALSE)
	, m_csEditArgument6(_T(""))
	, bEABsEnabled(FALSE)
	, m_csEditArgument8(_T(""))
	, m_csEditArgument9(_T(""))
	, m_csEditArgument10(_T(""))
	, m_csEditArgument13(_T(""))
	, m_csEditArgument11(_T(""))
	, m_csEditArgument12(_T(""))
	, m_csEditArgument7(_T(""))
	, m_csEditArgument14(_T(""))
	, bCheckParam1(FALSE)
	, bCheckParam2(FALSE)
	, bCheckParam3(FALSE)
	, bCheckParam4(FALSE)
{
	//{{AFX_DATA_INIT(CAPIGenDlg)
	m_bPromptForValues = FALSE;
	m_csInputString = _T("");
	m_csInputStringLength = _T("");
	m_csInputReturnCode = _T("");
	m_csEditRow = _T("");
	m_csEditColumn = _T("");
	m_csEditLength = _T("");
	m_csEditPutString = _T("");
	m_csEditTimeout = _T("");
	m_bCheckContinueProcess = FALSE;
	m_csEditUserKeys = _T("");
	m_csEditSettleTime = _T("");
	m_csEditCloseOption = _T("");
	m_bSetFileTransferScheme = FALSE;
	m_csEditFileTransferScheme = _T("");
	m_bCheckKeyboardMap = FALSE;
	m_csKeyboardMapName = _T("");
	m_bCheckLanguage = FALSE;
	m_bCheckLocalMode = FALSE;
	m_bCheckSetMenuVisible = FALSE;
	m_bCheckSetSessionQuiet = FALSE;
	m_bCheckShowFTPRogress = FALSE;
	m_csEditHostFileName = _T("");
	m_csEditPC_Filename = _T("");
	m_bCheckSetVisible = FALSE;
	m_bCheckContinuousWait = FALSE;
	m_bCheckSetWidth = FALSE;
	m_bCheckSetHeight = FALSE;
	m_csEditWidth = _T("");
	m_csEditHeight = _T("");
	m_csListWindowState = _T("");
	m_bCheckSetWindowState = FALSE;
	m_csEditSessionFilename = _T("");
	m_bCheckSetTimeoutValue = FALSE;
	m_bCheckFileInsert = FALSE;
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}


void CAPIGenDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAPIGenDlg)
	DDX_Control(pDX, IDSTATIC_TELNET_ADDRESS, m_staticTelnetAddress);
	DDX_Control(pDX, IDSTATIC_TELNET_PORT, m_staticTelnetPort);
	DDX_Control(pDX, IDSTATIC_SOCKS_ADDRESS, m_staticSocksAddress);
	DDX_Control(pDX, IDSTATIC_SOCKS_PORT, m_staticSocksPort);
	DDX_Control(pDX, IDCHECK_SETTIMEOUT, m_checkSetTimeoutValue);
	DDX_Control(pDX, IDSTATIC_SESSIONFILE_NAME, m_staticSessionFileName);
	DDX_Control(pDX, IDEDIT_SESSION_FILENAME, m_editSessionFilename);
	DDX_Control(pDX, IDBUTTON_SESSION_FILENAME, m_buttonSessionFilename);
	DDX_Control(pDX, IDCHECK_SET_WINDOWSTATE, m_checkSetWindowState);
	DDX_Control(pDX, IDSTATIC_WINDOWSTATE, m_staticWindowState);
	DDX_Control(pDX, IDLIST_WINDOW_STATE, m_listWindowState);
	DDX_Control(pDX, IDEDIT_HEIGHT, m_editHeight);
	DDX_Control(pDX, IDEDIT_WIDTH, m_editWidth);
	DDX_Control(pDX, IDCHECK_HEIGHT, m_checkSetHeight);
	DDX_Control(pDX, IDCHECK_WIDTH, m_checkSetWidth);
	DDX_Control(pDX, IDSTATIC_WIDTH, m_staticNewWidth);
	DDX_Control(pDX, IDSTATIC_HEIGHT, m_staticNewHeight);
	DDX_Control(pDX, IDCCHECK_CONTINUOUS_WAIT, m_checkContinuousWait);
	DDX_Control(pDX, IDCHECK_VISIBLE, m_checkSetVisible);
	DDX_Control(pDX, IDSTATIC_PC_FILENAME, m_staticPC_Filename);
	DDX_Control(pDX, IDSTATIC_HOST_FILENAME, m_staticHostFileName);
	DDX_Control(pDX, IDEDIT_PC_FILENAME, m_editPC_Filename);
	DDX_Control(pDX, IDEDIT_HOSTFILENAME, m_editHostFileName);
	DDX_Control(pDX, IDCHECK_SHOW_FT_STATUS, m_checkShowFTProgress);
	DDX_Control(pDX, IDBUTTON_FT_FILENAME, m_buttonBrowseFileTransfer);
	DDX_Control(pDX, IDCHECK_SET_SESS_QUIET, m_checkSetSessionQuiet);
	DDX_Control(pDX, IDCHECK_SETMENU, m_checkSetMenuVisible);
	DDX_Control(pDX, IDCCHECK_LOCALMODE, m_checkLocalMode);
	DDX_Control(pDX, IDCHECK_LANGUAGE, m_checkLanguage);
	DDX_Control(pDX, IDSTATIC_LANGUAGE, m_staticLanguage);
	DDX_Control(pDX, IDSTATIC_IDLETIME, m_staticIdleTime);
	DDX_Control(pDX, IDLIST_SCREENMODEL, m_listScreenModel);
	DDX_Control(pDX, IDSTATIC_SCREENMODEL, m_staticScreenModel);
	DDX_Control(pDX, IDSTATIC_HOSTCODEPAGE, m_staticHostCodePage);
	DDX_Control(pDX, IDCSTATIC_HOSTCHARSET, m_staticHostCharSet);
	DDX_Control(pDX, IDSTATIC_MNEMONIC, m_staticMnemonicType);
	DDX_Control(pDX, IDLIST_MNEMONIC, m_listMnemonicType);
	DDX_Control(pDX, IDLIST_FIELDTYPE, m_listFieldType);
	DDX_Control(pDX, IDSTATIC_FIELDTYPE, m_staticFieldType);
	DDX_Control(pDX, IDSTATIC_KEYBOARD_MAP, m_staticKeyboardMap);
	DDX_Control(pDX, IDEDIT_KEYBOARD_MAP, m_EditKeyboardMapName);
	DDX_Control(pDX, IDCHECK_KEYBOARD_MAP, m_checkKeyboardMap);
	DDX_Control(pDX, IDBUTTON_BROWSE_KEYMAP, m_ButtonBrowseKeyMap);
	DDX_Control(pDX, IDBUTTON_FT_SCHEME_NAME, m_buttonBrowseFileTransferScheme);
	DDX_Control(pDX, IDEDIT_FILETRANSFER_SCHEME, m_EditFileTransferScheme);
	DDX_Control(pDX, IDCHECK_SET_FT_, m_checkSetFileTransferScheme);
	DDX_Control(pDX, IDSTATIC_FT_SCHEME, m_staticFileTransferScheme);
	DDX_Control(pDX, IDSTATIC_CLOSEOPTION, m_staticCloseOption);
	DDX_Control(pDX, IDEDIT_CLOSE_OPTION, m_editCloseOption);
	DDX_Control(pDX, IDSTATIC_SETTLETIME, m_staticSettleTime);
	DDX_Control(pDX, IDEDIT_SETTLE_TIME, m_EditSettleTime);
	DDX_Control(pDX, IDSTATIC_TIMEOUT, m_staticTimeout);
	DDX_Control(pDX, IDSTATIC_KEYS, m_staticUserKeys);
	DDX_Control(pDX, IDEDIT_USERKEYS, m_editUserKeys);
	DDX_Control(pDX, IDEDIT_TIMEOUT, m_editTimeout);
	DDX_Control(pDX, IDCHECK_PROCESS, m_checkContinueToProcess);
	DDX_Control(pDX, IDSTATIC_MOVE_ROWS, m_staticRowsMoved);
	DDX_Control(pDX, IDSTATIC_COLUMNS_MOVED, m_staticColumnsMoved);
	DDX_Control(pDX, IDSTATIC_PUTSTRING, m_staticPutString);
	DDX_Control(pDX, IDEDIT_PUTSTRING, m_EditPutString);
	DDX_Control(pDX, IDSTATIC_PARAMETER_GROUP, m_groupAddParameterGroup);
	DDX_Control(pDX, IDSTATIC_NO_PARAMETERS, m_groupNoParametersNeeded);
	DDX_Control(pDX, IDSTATIC_LENGTH, m_staticLength);
	DDX_Control(pDX, IDEDIT_LENGTH, m_EditLength);
	DDX_Control(pDX, IDEDIT_ROW, m_EditRow);
	DDX_Control(pDX, IDEDIT_COLUMN, m_EditColumn);
	DDX_Control(pDX, IDSTATIC_COLUMN, m_staticColumn);
	DDX_Control(pDX, IDSTATIC_ROW, m_staticRow);
	DDX_Control(pDX, IDEDIT_RETURN_CODE, m_EditReturnCode);
	DDX_Control(pDX, IDEDIT_STRING_LENGTH, m_EditStringLength);
	DDX_Control(pDX, IDSTATIC_STRINGLENGTH, m_staticString2);
	DDX_Control(pDX, IDSTATIC_STRING, m_staticString1);
	DDX_Control(pDX, IDSTATIC_RETURNCODE, m_staticString3);
	DDX_Control(pDX, IDEDIT_STRING, m_EditFunctionString);
	DDX_Control(pDX, IDBUTTON_NEW_PROJECT, m_ButtonNewProject);
	DDX_Control(pDX, IDBUTTON_FINALIZE, m_buttonFinalizeListing);
	DDX_Control(pDX, IDCHECK_PROMPT_FOR_VALUES, m_buttonPromptForValues);
	DDX_Control(pDX, IDLIST_OUTPUT_TEXT, m_listOutputText);
	DDX_Control(pDX, IDBUTTON_GENERATE_SOURCE, m_ButtonGenerateSource);
	DDX_Control(pDX, IDBUTTON_APPEND_SOURCE, m_ButtonAppendSource);
	DDX_Control(pDX, IDLIST_FUNCTION_CHOICE, m_listTranslateFunction);
	DDX_Control(pDX, IDLIST_LANGUAGE_CHOICE, m_listTranslateLanguage);
	DDX_Control(pDX, IDLIST_API_CHOICE, m_listTranslateAPI);
	DDX_Check(pDX, IDCHECK_PROMPT_FOR_VALUES, m_bPromptForValues);
	DDX_Text(pDX, IDEDIT_STRING, m_csInputString);
	DDX_Text(pDX, IDEDIT_STRING_LENGTH, m_csInputStringLength);
	DDX_Text(pDX, IDEDIT_RETURN_CODE, m_csInputReturnCode);
	DDV_MaxChars(pDX, m_csInputReturnCode, 3);
	DDX_Text(pDX, IDEDIT_ROW, m_csEditRow);
	DDX_Text(pDX, IDEDIT_COLUMN, m_csEditColumn);
	DDX_Text(pDX, IDEDIT_LENGTH, m_csEditLength);
	DDX_Text(pDX, IDEDIT_PUTSTRING, m_csEditPutString);
	DDX_Text(pDX, IDEDIT_TIMEOUT, m_csEditTimeout);
	DDX_Check(pDX, IDCHECK_PROCESS, m_bCheckContinueProcess);
	DDX_Text(pDX, IDEDIT_USERKEYS, m_csEditUserKeys);
	DDX_Text(pDX, IDEDIT_SETTLE_TIME, m_csEditSettleTime);
	DDX_Text(pDX, IDEDIT_CLOSE_OPTION, m_csEditCloseOption);
	DDX_Check(pDX, IDCHECK_SET_FT_, m_bSetFileTransferScheme);
	DDX_Text(pDX, IDEDIT_FILETRANSFER_SCHEME, m_csEditFileTransferScheme);
	DDX_Check(pDX, IDCHECK_KEYBOARD_MAP, m_bCheckKeyboardMap);
	DDX_Text(pDX, IDEDIT_KEYBOARD_MAP, m_csKeyboardMapName);
	DDX_Check(pDX, IDCHECK_LANGUAGE, m_bCheckLanguage);
	DDX_Check(pDX, IDCCHECK_LOCALMODE, m_bCheckLocalMode);
	DDX_Check(pDX, IDCHECK_SETMENU, m_bCheckSetMenuVisible);
	DDX_Check(pDX, IDCHECK_SET_SESS_QUIET, m_bCheckSetSessionQuiet);
	DDX_Check(pDX, IDCHECK_SHOW_FT_STATUS, m_bCheckShowFTPRogress);
	DDX_Text(pDX, IDEDIT_HOSTFILENAME, m_csEditHostFileName);
	DDX_Text(pDX, IDEDIT_PC_FILENAME, m_csEditPC_Filename);
	DDX_Check(pDX, IDCHECK_VISIBLE, m_bCheckSetVisible);
	DDX_Check(pDX, IDCCHECK_CONTINUOUS_WAIT, m_bCheckContinuousWait);
	DDX_Check(pDX, IDCHECK_WIDTH, m_bCheckSetWidth);
	DDX_Check(pDX, IDCHECK_HEIGHT, m_bCheckSetHeight);
	DDX_Text(pDX, IDEDIT_WIDTH, m_csEditWidth);
	DDX_Text(pDX, IDEDIT_HEIGHT, m_csEditHeight);
	DDX_LBString(pDX, IDLIST_WINDOW_STATE, m_csListWindowState);
	DDX_Check(pDX, IDCHECK_SET_WINDOWSTATE, m_bCheckSetWindowState);
	DDX_Text(pDX, IDEDIT_SESSION_FILENAME, m_csEditSessionFilename);
	DDX_Check(pDX, IDCHECK_SETTIMEOUT, m_bCheckSetTimeoutValue);
	DDX_Check(pDX, IDCHECK_FILE_INSERT, m_bCheckFileInsert);
	//}}AFX_DATA_MAP
	DDX_Control(pDX, IDCHECK_FILE_INSERT, m_checkInsertIntoFile);
	DDX_Control(pDX, IDBUTTON_SAVE_TO_FILE, m_buttonSaveToFile);
	DDX_Control(pDX, IDLIST_TERMINAL_TYPE, m_listTerminalType);
	DDX_Control(pDX, IDEDIT_ARGUMENT1, m_EditArgument1);
	DDX_Control(pDX, IDEDIT_ARGUMENT2, m_EditArgument2);
	DDX_Control(pDX, IDEDIT_ARGUMENT3, m_EditArgument3);
	DDX_Control(pDX, IDEDIT_ARGUMENT4, m_EditArgument4);
	DDX_Control(pDX, IDEDIT_ARGUMENT5, m_EditArgument5);
	DDX_Control(pDX, IDEDIT_ARGUMENT6, m_EditArgument6);
	DDX_Text(pDX, IDEDIT_ARGUMENT1, m_csEditArgument1);
	DDX_Text(pDX, IDEDIT_ARGUMENT2, m_csEditArgument2);
	DDX_Text(pDX, IDEDIT_ARGUMENT3, m_csEditArgument3);
	DDX_Text(pDX, IDEDIT_ARGUMENT4, m_csEditArgument4);
	DDX_Text(pDX, IDEDIT_ARGUMENT5, m_csEditArgument5);
	DDX_Text(pDX, IDEDIT_ARGUMENT6, m_csEditArgument6);
	DDX_Control(pDX, IDCHECK_PASSIVE_MODE, cb_PassiveMode);
	DDX_Check(pDX, IDCHECK_PASSIVE_MODE, bPassiveMode);
	DDX_Control(pDX, IDSTATIC_STRING4, m_staticString4);
	DDX_Control(pDX, IDSTATIC_STRING5, m_staticString5);
	DDX_Control(pDX, IDLIST_FILE_EXISTS, m_listFileExists);
	DDX_Control(pDX, IDLIST_TRANSFER_TYPE, m_listTransferType);
	DDX_Control(pDX, IDCHECK_EABs_ENABLED, cbEABsEnabled);
	DDX_Check(pDX, IDCHECK_EABs_ENABLED, bEABsEnabled);
	DDX_Control(pDX, IDSTATIC_TERMINAL_TYPE, staticTerminalType);
	DDX_Control(pDX, IDEDIT_ARGUMENT7, m_EditArgument7);
	DDX_Control(pDX, IDSTATIC_6, m_staticString6);
	DDX_Control(pDX, IDEDIT_ARGUMENT8, m_EditArgument8);
	DDX_Control(pDX, IDEDIT_ARGUMENT9, m_EditArgument9);
	DDX_Control(pDX, IDEDIT_ARGUMENT10, m_EditArgument10);
	DDX_Control(pDX, IDEDIT_ARGUMENT11, m_EditArgument11);
	DDX_Control(pDX, IDEDIT_ARGUMENT12, m_EditArgument12);
	DDX_Control(pDX, IDEDIT_ARGUMENT13, m_EditArgument13);
	DDX_Control(pDX, IDEDIT_ARGUMENT14, m_EditArgument14);
	DDX_Control(pDX, IDSTATICSTRING8, m_staticString8);
	DDX_Control(pDX, IDSTATICSTRING9, m_staticString9);
	DDX_Control(pDX, IDSTATICSTRING10, m_staticString10);
	DDX_Control(pDX, IDSTATICSTRING11, m_staticString11);
	DDX_Control(pDX, IDSTATICSTRING12, m_staticString12);
	DDX_Control(pDX, IDSTATICSTRING13, m_staticString13);
	DDX_Control(pDX, IDSTATICSTRING14, m_staticString14);
	DDX_Text(pDX, IDEDIT_ARGUMENT8, m_csEditArgument8);
	DDX_Text(pDX, IDEDIT_ARGUMENT9, m_csEditArgument9);
	DDX_Text(pDX, IDEDIT_ARGUMENT10, m_csEditArgument10);
	DDX_Text(pDX, IDEDIT_ARGUMENT13, m_csEditArgument13);
	DDX_Text(pDX, IDEDIT_ARGUMENT11, m_csEditArgument11);
	DDX_Text(pDX, IDEDIT_ARGUMENT12, m_csEditArgument12);
	DDX_Text(pDX, IDEDIT_ARGUMENT7, m_csEditArgument7);
	DDX_Text(pDX, IDEDIT_ARGUMENT14, m_csEditArgument14);
	DDX_Control(pDX, IDSTATICSTRING7, m_staticString7);
	DDX_Control(pDX, IDLIST_PARAMS_1, listParams1);
	DDX_Control(pDX, IDCHECK_PARAM1, checkParam1);
	DDX_Check(pDX, IDCHECK_PARAM1, bCheckParam1);
	DDX_Control(pDX, IDLIST_PARAMS2, listParams2);
	DDX_Control(pDX, IDCHECK_PARAM2, checkParam2);
	DDX_Check(pDX, IDCHECK_PARAM2, bCheckParam2);
	DDX_Control(pDX, IDLIST_PARAMS3, listParams3);
	DDX_Control(pDX, IDLIST_PARAMS4, listParams4);
	DDX_Control(pDX, IDLIST_PARAMS5, listParams5);
	DDX_Control(pDX, IDMULTILIST_PARAMS1, listMultiParams1);
	DDX_Control(pDX, IDMULTILIST_PARAMS2, listMultiParams2);
	DDX_Control(pDX, IDMULTILIST_PARAMS3, listMultiParams3);
	DDX_Control(pDX, IDMULTILIST_PARAMS4, listMultiParams4);
	DDX_Control(pDX, IDCHECK_PARAM3, checkParam3);
	DDX_Check(pDX, IDCHECK_PARAM3, bCheckParam3);
	DDX_Control(pDX, IDCHECK_PARAM4, checkParam4);
	DDX_Check(pDX, IDCHECK_PARAM4, bCheckParam4);
}

BEGIN_MESSAGE_MAP(CAPIGenDlg, CDialog)
	//{{AFX_MSG_MAP(CAPIGenDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDBUTTON_APPEND_SOURCE, OnAppendSource)
	ON_BN_CLICKED(IDBUTTON_GENERATE_SOURCE, OnGenerateSource)
	ON_LBN_SELCHANGE(IDLIST_API_CHOICE, OnChangeAPIChoice)
	ON_BN_CLICKED(IDBUTTON_FINALIZE, OnFinalize)
	ON_BN_CLICKED(IDCHECK_PROMPT_FOR_VALUES, OnPromptForValues)
	ON_BN_CLICKED(IDBUTTON_NEW_PROJECT, OnNewProject)
	ON_EN_CHANGE(IDEDIT_STRING, OnChangeString)
	ON_BN_CLICKED(IDBUTTON_SAVE_TO_FILE, OnSaveToFile)
	ON_LBN_SELCHANGE(IDLIST_FUNCTION_CHOICE, OnChangeFunctionChoice)
	ON_BN_CLICKED(IDBUTTON_FT_SCHEME_NAME, OnFtSchemeName)
	ON_BN_CLICKED(IDCHECK_SET_FT_, OnCheckFTSchemeCheckBox)
	ON_BN_CLICKED(IDBUTTON_BROWSE_KEYMAP, OnBrowseKeymap)
	ON_BN_CLICKED(IDCHECK_KEYBOARD_MAP, OnKeyboardMap)
	ON_LBN_SELCHANGE(IDLIST_LANGUAGE_CHOICE, ChangeTerminalOrLanguage)
	ON_BN_CLICKED(IDCHECK_LANGUAGE, OnCheckLanguage)
	ON_BN_CLICKED(IDBUTTON_FT_FILENAME, OnBrowseFileTransFilename)
	ON_BN_CLICKED(IDCHECK_HEIGHT, OnSetHeight)
	ON_BN_CLICKED(IDCHECK_WIDTH, OnSetWidth)
	ON_BN_CLICKED(IDCHECK_SET_WINDOWSTATE, OnSetWindowState)
	ON_BN_CLICKED(IDBUTTON_SESSION_FILENAME, OnSessionFileName)
	ON_BN_CLICKED(IDCHECK_SETTIMEOUT, OnSettimeout)
	ON_BN_CLICKED(IDCHECK_FILE_INSERT, OnFileInsert)
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDBUTTON_HELP, OnHelp)
	ON_LBN_SELCHANGE(IDLIST_TERMINAL_TYPE, ChangeTerminal)
	ON_EN_CHANGE(IDEDIT_ARGUMENT1, OnChangeArgument1)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAPIGenDlg message handlers


void CAPIGenDlg::OnOK() 
{
	CDialog::OnOK();

	delete cagtest;
	m_listTranslateFunction.ResetContent();
	m_listTranslateLanguage.ResetContent();

}

BOOL CAPIGenDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	m_bCheckFileInsert=FALSE;
	
	// Initialize the state machine
	RunState.Initialize();

	cagtest = new CAG_EHL_CPP;
	m_buttonPromptForValues.EnableWindow(TRUE);
	cagtest->loadFunctionList( &m_listTranslateFunction );
	cagtest->loadLanguageList( &m_listTranslateLanguage );
	cagtest->loadTerminalTypeList( &m_listTerminalType );


	// Initialize the window size parameters
	SetWindowSizeLoc();
	WidthVariable=WidthSmall;
	
	SetUI();
	
	nGlobalPSMallocSize = 3840;

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CAPIGenDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}



void CAPIGenDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}



// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CAPIGenDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}



/***************************************************************************DC

	Operation:	CAPIGenDlg::OnGenerateSource()

	Purpose:	Manages the generation of the first function when the 
				Generate button is pressed.

	Notes:		Parameterize the outfile extension

*****************************************************************************/
void CAPIGenDlg::OnGenerateSource() 
{

	CString csAPI_Choice;
	CString csLanguage_Name;

	UpdateData();

	int nPosition = m_listTranslateAPI.GetCurSel();
	m_listTranslateAPI.GetText( nPosition, csAPI_Choice );

	nPosition = m_listTranslateLanguage.GetCurSel();
	m_listTranslateLanguage.GetText( nPosition, csLanguage_Name );
	
	// if a valid function is selected then prepare the file/view header
	nPosition = m_listTranslateFunction.GetCurSel();
	if ( nPosition == LB_ERR )
	{
	   MessageBox("No selection, no ouput!");
	   return;
	}
	else
	{
		if ( m_bCheckFileInsert )
		{
			csaHeader.RemoveAll();
			csaCaboose.RemoveAll();
			if ( !ReadyTargetOutFile( &csaHeader, &csaCaboose ) )
			{
				return;
			}
		}
		else
		{
			cagtest->generateHeader( &csaHeader, &csaBody );
		}
	}

	// set to Generating state
	RunState.SendAction( GENERATE_BUTTON );

	m_checkInsertIntoFile.EnableWindow( FALSE );

    SetUI();

	m_listTranslateFunction.SetFocus();

	LoadArgumentArray( &nPosition );

	cagtest->appendBody( nPosition, m_bPromptForValues, &csaArguments, &csaHeader, &csaBody );

	WriteToView( m_bCheckFileInsert );

}



/***************************************************************************DC

	Operation:	CAPIGenDlg::ReadyTargetOutFile()

	Purpose:	Prompt for the name of the output file to which we'll insert
				output and then establish the csaHeader, csaBody, and 
				csaCaboose.

	Notes:		

*****************************************************************************/
BOOL CAPIGenDlg::ReadyTargetOutFile( CStringArray* pcsaHeader, CStringArray* pcsaCaboose )
{
	BOOL	bRet=FALSE;
	CString csLanguage, csLanguageFileExtension;
	char szFilter[128];
	char* pszFilter = szFilter;

	CString	csAPI_Name;
	int nAPI_Index = m_listTranslateAPI.GetCurSel();
	int n = m_listTranslateAPI.GetTextLen( nAPI_Index );
    m_listTranslateAPI.GetText( nAPI_Index, csAPI_Name.GetBuffer(n) );
    csAPI_Name.ReleaseBuffer();

	int nPosition = m_listTranslateLanguage.GetCurSel();
	m_listTranslateLanguage.GetText( nPosition, csLanguage );
	int nSpacePlace = csLanguage.Find("C++");
	if ( csLanguage.Find("C++") >= 0 )
	{
		csLanguageFileExtension="cpp";
		strcpy( pszFilter, "Target C++ file (*.cpp)|*.cpp|All Files (*.*)|*.*||" );
	}
	else if ( csLanguage.Find("ASP") >= 0 )
	{
		csLanguageFileExtension="asp";
		strcpy( pszFilter, "Target ASP file (*.asp)|*.asp|All Files (*.*)|*.*||" );
	}
	else if ( csLanguage.Find("DOS command") >= 0 )
	{
		csLanguageFileExtension="bat";
		strcpy( pszFilter, "DOS batch file (*.bat)|*.bat|All Files (*.*)|*.*||" );
	}
	else if ( csLanguage.Find("JavaScript") >= 0 )
	{
		if ( -1 != csAPI_Name.Find("ViewMaster") )
		{
			csLanguageFileExtension="html";
			strcpy( pszFilter, "Target HTML file (*.html)|*.html|All Files (*.*)|*.*||" );
		}
		else
		{
			csLanguageFileExtension="js";
			strcpy( pszFilter, "Target JavaScript file (*.js)|*.js|All Files (*.*)|*.*||" );
		}
	}
	else if ( csLanguage.Find("Java") >= 0 )
	{
		csLanguageFileExtension="java";
		strcpy( pszFilter, "Target Java file (*.java)|*.java|All Files (*.*)|*.*||" );
	}
	else if ( csLanguage.Find("JavaScript Node") >= 0 )
	{
		csLanguageFileExtension="html";
		strcpy( pszFilter, "HTML file (*.html)|*.html|All Files (*.*)|*.*||" );
	}
	else if ( csLanguage.Find("VB.Net") >= 0 )
	{
		csLanguageFileExtension="vb";
		strcpy( pszFilter, "VB.Net file (*.vb)|*.vb|All Files (*.*)|*.*||" );
	}
	else if ( csLanguage.Find("VBScript Node") >= 0 )
	{
		csLanguageFileExtension="html";
		strcpy( pszFilter, "HTML file (*.html)|*.html|All Files (*.*)|*.*||" );
	}
	else if ( csLanguage.Find("VBScript") >= 0 )
	{
		if ( -1 != csAPI_Name.Find("ViewMaster") )
		{
			csLanguageFileExtension="html";
			strcpy( pszFilter, "Target HTML file (*.html)|*.html|All Files (*.*)|*.*||" );
		}
		else
		{
			csLanguageFileExtension="vbs";
			strcpy( pszFilter, "Target VBScript file (*.vbs)|*.vbs|All Files (*.*)|*.*||" );
		}
	}
	else if ( csLanguage.Find("VB 6") >= 0 )
	{
		csLanguageFileExtension="bas";
		strcpy( pszFilter, "Target Basic file (*.bas)|*.bas|All Files (*.*)|*.*||" );
	}
	else if ( csLanguage.Find("EB Macro") >= 0 )
	{
		csLanguageFileExtension="ebm";
		strcpy( pszFilter, "Extra! Basic Macro TEXT file (*.ebm)|*.ebm|All Files (*.*)|*.*||" );
	}
	else if ( csLanguage.Find("Windows Script") >= 0 )
	{
		csLanguageFileExtension="vbs";
		strcpy( pszFilter, "Windows Script (*.vbs)|*.ws|All Files (*.*)|*.*||" );
	}
	else if ( csLanguage.Find("Excel VBA Macro") >= 0 )
	{
		csLanguageFileExtension="xls";
		strcpy( pszFilter, "Target Excel VBA file (*.xls)|*.xls|All Files (*.*)|*.*||" );
	}
	else if ( csLanguage.Find("UNIX command") >= 0 )
	{
		csLanguageFileExtension="sh";
		strcpy( pszFilter, "UNIX shell file (*.sh)|*.sh|All Files (*.*)|*.*||" );
	}
	else if ( csLanguage.Find("XML") >= 0 )
	{
		csLanguageFileExtension="wxs";
		strcpy( pszFilter, "WIX XML (*.wxs)|*.wxs|All Files (*.*)|*.*||" );
	}
	else
	{
		csLanguageFileExtension="txt";
		strcpy( pszFilter, "Target txt file (*.txt)|*.txt|All Files (*.*)|*.*||" );
	}

	
	CFileDialog fileDialog(true, NULL, NULL, (OFN_FILEMUSTEXIST | OFN_HIDEREADONLY | OFN_LONGNAMES | OFN_PATHMUSTEXIST), pszFilter); 

	fileDialog.m_ofn.lpstrTitle = _T("Specify target filename for APIGen");

	TCHAR filenameBuffer[4096] = { 0 } ;
	fileDialog.m_ofn.lpstrFile = filenameBuffer;
	fileDialog.m_ofn.nMaxFile = sizeof(filenameBuffer) / sizeof(filenameBuffer[0]);


	// open the recording file that we're going to convert to a test file

	if (IDOK == fileDialog.DoModal())
	{
		m_csTargetFileName = fileDialog.GetPathName();
		// now open m_csTargetFileName and read it into the header
		ifstream infile(m_csTargetFileName, ios::in);
		char	csOutStuff[3840] = "";
		char*	pcsOutStuff = csOutStuff;
		CString	csReadLine;
		CStringArray*	csaLocal=pcsaHeader;

		while ( infile.getline( pcsOutStuff, 3840 ) )
		{
			if ( pcsOutStuff != NULL )
			{
				csReadLine.Format( "%s", pcsOutStuff);
				
				if ( csReadLine.IsEmpty() )
				{
					// add a blank string to csaHeader
					csaLocal->Add(" ");
				}
				else if ( csReadLine.Find("*APIGen*" ) != -1 )
				{
					bRet = TRUE;
					csaLocal=pcsaCaboose;
				}
				else	// add string just read to string array
				{
					csaLocal->Add(csReadLine);
				}
			}
			else
			{
				break;
			}
		}


	}   
	
	return bRet;
}





/***************************************************************************DC

	Operation:	CAPIGenDlg::OnChangeAPIChoice() 

	Purpose:	Reset the global application parameters to values
				appropriate for the selected API.  

	Notes:		I'm enabling/disabling the "Prompt for values" checkbox
				as needed until it's supported for all API's.

				Remember that the language choice is determined by which 
				programming language is at the top of the language list
				and which terminal type is currently selected.  The selection 
				will be placed at the top of the list when the API choice is 
				changed.  The user must select a different language for a 
				different class to be created.

				The API will always take on the top terminal type in the 
				terminal type list.

*****************************************************************************/
void CAPIGenDlg::OnChangeAPIChoice() 
{
	UpdateData();
	CString	csAPI_Name;
	nAPI_Index = m_listTranslateAPI.GetCurSel();
	int n = m_listTranslateAPI.GetTextLen( nAPI_Index );
    m_listTranslateAPI.GetText( nAPI_Index, csAPI_Name.GetBuffer(n) );
    csAPI_Name.ReleaseBuffer();

	delete cagtest;
	m_listTranslateFunction.ResetContent();
	m_listTranslateLanguage.ResetContent();
	m_listTerminalType.ResetContent();

	staticTerminalType.SetWindowText( "Terminal type" );

	if ( csAPI_Name == "Airlines SDK" )
	{
		cagtest = new CAG_AIR_3270_J_J;
		m_buttonPromptForValues.EnableWindow(TRUE);
		RunState.SendAction( AIR_NOW );
	}

	else if ( csAPI_Name == "ViewMaster" )
	{
		cagtest = new CAG_AIR_VM_3270_J;
		m_buttonPromptForValues.EnableWindow(TRUE);
		RunState.SendAction( AIR_VM_NOW );
	}

	else if ( csAPI_Name == "CASL Macro" )
	{
		cagtest = new CAG_CASL;
		m_buttonPromptForValues.EnableWindow(TRUE);
		RunState.SendAction( CASL_NOW );

		if(m_bPromptForValues)
		{
			HideParameterControls();
			ShowCASLControls(0);
		}

	}

	else if ( csAPI_Name == "DOS shell" )
	{
		cagtest = new CAG_DOS;
		m_buttonPromptForValues.EnableWindow(TRUE);
		RunState.SendAction( DOS_NOW );

		if(m_bPromptForValues)
		{
			HideParameterControls();
			ShowDOSControls(0);
		}

	}

	else if ( csAPI_Name == "CICS Bridge QACom" )
	{
		cagtest = new CAG_CICS_QACOM_COM_ASP;
		m_buttonPromptForValues.EnableWindow(TRUE);
		staticTerminalType.SetWindowText( "API flavor" );
		RunState.SendAction( CICS_NOW );

		if(m_bPromptForValues)
		{
			HideParameterControls();
			ShowCICSCOMControls(0);
		}

	}

	else if ( csAPI_Name == "ATMAPI32" )
	{
		cagtest = new CAG_EAL_CPP;
		m_buttonPromptForValues.EnableWindow(FALSE);
		RunState.SendAction( EAL_NOW );
	}
	else if ( csAPI_Name == "EAO ActiveX" )
	{
		cagtest = new CAG_EAOAx_3270_CPP;
		m_buttonPromptForValues.EnableWindow(TRUE);
		RunState.SendAction( EAOAx_NOW );
	}
	else if ( csAPI_Name == "EAO Java" )
	{
		cagtest = new CAG_EAOJ_3270_J;
		m_buttonPromptForValues.EnableWindow(TRUE);
		RunState.SendAction( EAOJ_NOW );

		if(m_bPromptForValues)
		{
			HideParameterControls();
			ShowEAOJControls(0);
		}
	}
	else if ( csAPI_Name == "EHLAPI32" )
	{
		cagtest = new CAG_EHL_CPP;
		m_buttonPromptForValues.EnableWindow(TRUE);
		RunState.SendAction( EHL_NOW );

		if(m_bPromptForValues)
		{
			HideParameterControls();
			ShowEHLControls();
		}
	}
	else if ( csAPI_Name == "HLLAPI32" )
	{
		cagtest = new CAG_HLL_CPP;
		m_buttonPromptForValues.EnableWindow(FALSE);
		RunState.SendAction( HLL_NOW );
	}
	else if ( csAPI_Name == "IHLAPI32" )
	{
		cagtest = new CAG_IHL_CPP;
		m_buttonPromptForValues.EnableWindow(TRUE);
		RunState.SendAction( IHL_NOW );

		if(m_bPromptForValues)
		{
			HideParameterControls();
			ShowEHLControls();
		}
	}
	else if ( csAPI_Name == "Extra! OLE Auto" )
	{
		cagtest = new CAG_EOLE_3270_CPP;
		m_buttonPromptForValues.EnableWindow(TRUE);
		RunState.SendAction( EOLE_NOW );

		if(m_bPromptForValues)
		{
			HideParameterControls();
			ShowEOLEControls(0);
		}

	}
	else if ( csAPI_Name == "Synapta" )
	{
		cagtest = new CAG_ICONN_JAVA;
		m_buttonPromptForValues.EnableWindow(TRUE);
		staticTerminalType.SetWindowText( "Interface" );
		RunState.SendAction( ITASK_NOW );

		if(m_bPromptForValues)
		{
			HideParameterControls();
			ShowITaskControls(0);
		}

	}
	else if ( csAPI_Name == "MCS ActiveX" )
	{
		cagtest = new CAG_MCS_Ax_3270_JS_CRL;
		m_buttonPromptForValues.EnableWindow(TRUE);
		RunState.SendAction( MCSAx_NOW );
	}
	else if ( csAPI_Name == "MCS Java" )
	{
		cagtest = new CAG_MCS_J_3270_JS_CRL;
		m_buttonPromptForValues.EnableWindow(FALSE);
		RunState.SendAction( MCSJ_NOW );
	}
	else if ( csAPI_Name == "MSI" )
	{
		cagtest = new CAG_MSI_APP_CPP;
		m_buttonPromptForValues.EnableWindow(TRUE);
		staticTerminalType.SetWindowText( "Application type" );
		RunState.SendAction( MSI_NOW );

		if(m_bPromptForValues)
		{
			HideParameterControls();
			ShowMSIAppControls(0);
		}

	}

	else if ( csAPI_Name == "Perforce" )
	{
		cagtest = new CAG_PERFORCE;
		m_buttonPromptForValues.EnableWindow(TRUE);
		RunState.SendAction( PERFORCE_NOW );

		if(m_bPromptForValues)
		{
			HideParameterControls();
			ShowPerforceControls(0);
		}
	}
	else if ( csAPI_Name == "PCSHLL32" )
	{
		cagtest = new CAG_PCS_CPP;
		m_buttonPromptForValues.EnableWindow(TRUE);
		RunState.SendAction( PCS_NOW );

		if(m_bPromptForValues)
		{
			HideParameterControls();
			ShowEHLControls();
		}
	}
	else if ( csAPI_Name == "PB QACom" )
	{
		cagtest = new CAG_PB_QAC_J;
		m_buttonPromptForValues.EnableWindow(FALSE);
		RunState.SendAction( QAC_NOW );
	}

	else if ( csAPI_Name == "Reflection for Web" )
	{
		cagtest = new CAG_RWEB_3270_JAVA;
		m_buttonPromptForValues.EnableWindow(FALSE);
		RunState.SendAction( RWEB_NOW );
	}
	
	else if ( csAPI_Name == "Reflection FTP" )
	{
		cagtest = new CAG_RFTP_CPP;
		m_buttonPromptForValues.EnableWindow(TRUE);
		RunState.SendAction( RFTP_NOW );

		if(m_bPromptForValues)
		{
			HideParameterControls();
			ShowRFTPControls(0);
		}

	}

	else if ( csAPI_Name == "Reflection OLE Auto" )
	{
		cagtest = new CAG_ROLE_3270_CPP;
		m_buttonPromptForValues.EnableWindow(TRUE);
		RunState.SendAction( ROLE_NOW );

		if(m_bPromptForValues)
		{
			HideParameterControls();
			ShowRIBMControls(0);
		}

	}
	else if ( csAPI_Name == "UNIX shell" )
	{
		cagtest = new CAG_UNIX;
		m_buttonPromptForValues.EnableWindow(TRUE);
		RunState.SendAction( UNIX_NOW );

		if(m_bPromptForValues)
		{
			HideParameterControls();
			ShowUNIXControls(0);
		}

	}
	else if ( csAPI_Name == "Verastream Host Integrator" )	//donc102605
	{
		cagtest = new CAG_VHI_CS;
		m_buttonPromptForValues.EnableWindow(TRUE);
		RunState.SendAction( VHI_NOW );

		if(m_bPromptForValues)
		{
			HideParameterControls();
			ShowVHIControls(0);
		}

	}

	else if ( csAPI_Name == "WHLAPI32" )
	{
		cagtest = new CAG_WHL_CPP;
		m_buttonPromptForValues.EnableWindow(TRUE);
		RunState.SendAction( WHL_NOW );

		if(m_bPromptForValues)
		{
			HideParameterControls();
			ShowEHLControls();
		}

	}

	cagtest->loadFunctionList( &m_listTranslateFunction );
	cagtest->loadLanguageList( &m_listTranslateLanguage );
	cagtest->loadTerminalTypeList( &m_listTerminalType );

	//	m_listTranslateLanguage.SetSel( 0 );

	OnChangeFunctionChoice();	//donc090905 inserted because it seems like a good idea

	UpdateData();

	SetUI();

}





/***************************************************************************DC

	Operation:	CAPIGenDlg::OnFinalize() 

	Purpose:	Add the return and end of main function curly bracket for
				C++ code.

	Notes:		

*****************************************************************************/
void CAPIGenDlg::OnFinalize() 
{
	if ( m_bCheckFileInsert )
	{
		AddCabooseToBody( &csaBody, &csaCaboose );
		WriteToView( m_bCheckFileInsert );
	}
	else
	{
		cagtest->finalize( &csaBody );	//donc072005
		WriteToView( m_bCheckFileInsert );
	}

	RunState.SendAction( FINALIZE );

	SetUI();
}




/***************************************************************************DC

	Operation:	CAPIGenDlg::AddCabooseToBody()

	Purpose:	When the user specified that output is to be inserted into
				an existing file, then this will be called when the Finalize 
				button is pressed.  It will append the remaining portion of the
				user-specified target file that lies after the file's 
				*APIGen* tag to csaBody so WriteToView or SaveToFile can 
				dump csaHeader and csaBody as before.

	Notes:		

*****************************************************************************/
void CAPIGenDlg::AddCabooseToBody( CStringArray* pcsaBody, CStringArray* pcsaCaboose )
{
	// add one line space
	pcsaBody->Add( " " );

	int	i;
	for ( i=0; i<csaCaboose.GetSize(); i++ )
	{
		pcsaBody->Add( pcsaCaboose->GetAt( i ) );
	}
}

/***************************************************************************DC

	Operation:	CAPIGenDlg::OnPromptForValues()

	Purpose:	If the checkbox specifies that we should use the user's
				choice of input values then we'll read them here.

	Notes:		Currently this function is only set up for the four-argument
				signature API's.

*****************************************************************************/
void CAPIGenDlg::OnPromptForValues()
{
	UpdateData();

	int n, nPosition, nTerminalType_Index;

	CString	csTerminalType;
	nTerminalType_Index = m_listTerminalType.GetCurSel();
	n = m_listTerminalType.GetTextLen( nTerminalType_Index );
    m_listTerminalType.GetText( nTerminalType_Index, csTerminalType.GetBuffer(n) );
    csTerminalType.ReleaseBuffer();

	RunState.SendAction( PARAMETERS_CHECKBOX );

    RECT rectDlg;
    GetWindowRect(&rectDlg);

    if(m_bPromptForValues)
	{
		MoveWindow(rectDlg.left, rectDlg.top, WidthBig, HeightSmall);
		WidthVariable=WidthBig;
		HideParameterControls();

		nPosition = m_listTranslateFunction.GetCurSel();
		HideParameterControls();

		switch ( cagtest->APIFlavor )
		{
			case AIRAx_API:
			{
				ShowAirAxControls( nPosition );
			}
			break;

			case AIRJ_API:
			{
				ShowAirJControls( nPosition );
			}
			break;

			case VIEWMASTER_API:
			{
				ShowAirVMControls( nPosition );
			}
			break;


			case CASL_API:
			{
				ShowCASLControls( nPosition );
			}
			break;

			case CICS_COM_API:
			{
				ShowCICSCOMControls( nPosition );
			}
			break;

			case CICS11_JAVA_API:
			{
				ShowCICS11JAVAControls( nPosition );
			}
			break;

			case CICS20_JAVA_API:
			{
				ShowCICS20JAVAControls( nPosition );
			}
			break;

			case CICS_NET_API:
			{
				ShowCICSNETControls( nPosition );
			}
			break;

			case DOS_API:
			{
				ShowDOSControls( nPosition );
			}
			break;

			case EAL_API:
			{
				ShowEALControls( nPosition );
			}
			break;

			case EA0Ax_API:
			case MCSAx_API:
			{
				if ( csTerminalType == "3270" )
				{
					ShowEAOAx3270Controls( nPosition );
				}
				else if ( csTerminalType == "5250" )
				{
					ShowEAOAx5250Controls( nPosition );
				}
				else
				{
					ShowEAOAxVTControls( nPosition );
				}
			}
			break;


			case EA0J_API:
			case MCSJ_API:
			{
				ShowEAOJControls( nPosition );
			}
			break;


			case EHL_API:
			case IHL_API:
			case PCS_API:
			case WHL_API:
			{
				ShowEHLControls();
			}
			break;

			case EOLE_API:
			{
				ShowEOLEControls( nPosition );
			}
			break;


			case HLL_API:
			{
				//ShowHLLControls();
			}
			break;

			case ICONN_API:
			{
				ShowICONNControls( nPosition );
			}
			break;

			case ITASK_API:
			{
				ShowITaskControls( nPosition );
			}
			break;

			case MSI_APP_API:
			{
				ShowMSIAppControls( nPosition );
			}
			break;

			case MSI_CUSTOM_API:
			{
				ShowMSICustomControls( nPosition );
			}
			break;

			case MSI_DB_API:
			{
				ShowMSIDBaseControls( nPosition );
			}
			break;

			case MSI_EXEC_API:
			{
				ShowMSIExecControls( nPosition );
			}
			break;

			case MSI_SUMMARY_API:
			{
				ShowMSISummaryControls( nPosition );
			}
			break;

			case MSI_WIXDLG_API:
			{
				ShowWIXDlgControls( nPosition );
			}
			break;

			case MSI_WIXWIZ_API:
			{
				ShowWIXDlgControls( nPosition );
			}
			break;

			case PERFORCE_API:
			{
				ShowPerforceControls( nPosition );
			}
			break;

			case QACOM_API:
			{
				//ShowOLEControls( nPosition );
			}
			break;

			case RIBM_OLE_API:
			{
				ShowRIBMControls( nPosition );
			}
			break;

			case RWEB_API:
			{
				ShowRWebControls( nPosition );
			}
			break;

			case RWIN_OLE_API:
			{
				ShowRWinControls( nPosition );
			}
			break;

			case RFTP_API:
			{
				ShowRFTPControls( nPosition );
			}
			break;

			case VHI_API:
			{
				ShowVHIControls( nPosition );
			}
			break;


			case UNIX_API:
			{
				ShowUNIXControls( nPosition );
			}
			break;


		}
    }
	else
	{
        MoveWindow(rectDlg.left, rectDlg.top, WidthSmall, HeightSmall);
		WidthVariable=WidthSmall;
    }
}



/***************************************************************************DC

	Operation:	CAPIGenDlg::OnNewProject()

	Purpose:	Clear the output window and the two string arrays.

	Notes:		

*****************************************************************************/
void CAPIGenDlg::OnNewProject()
{
	cagtest->resetVariableFlags();
	m_listOutputText.ResetContent();

	csaBody.RemoveAll();
	csaHeader.RemoveAll();
	csaCaboose.RemoveAll();

	m_checkInsertIntoFile.EnableWindow( TRUE );

	SetUI();
}






/***************************************************************************DC

	Operation:	CAPIGenDlg::SetAPIList()

	Purpose:	Inserts the list of supported API's into the list control.

	Notes:		

*****************************************************************************/
void CAPIGenDlg::SetAPIList()
{
	m_listTranslateAPI.ResetContent();

	// add the API's
	int nPos = 0;
	m_listTranslateAPI.InsertString( nPos++, "Airlines SDK" );
	m_listTranslateAPI.InsertString( nPos++, "ATMAPI32" );
	m_listTranslateAPI.InsertString( nPos++, "CASL Macro" );
	m_listTranslateAPI.InsertString( nPos++, "CICS Bridge QACom" );
	m_listTranslateAPI.InsertString( nPos++, "DOS shell" );
	m_listTranslateAPI.InsertString( nPos++, "EAO ActiveX" );
	m_listTranslateAPI.InsertString( nPos++, "EAO Java" );
	m_listTranslateAPI.InsertString( nPos++, "EHLAPI32" );
	m_listTranslateAPI.InsertString( nPos++, "Extra! OLE Auto" );
	m_listTranslateAPI.InsertString( nPos++, "HLLAPI32" );
	m_listTranslateAPI.InsertString( nPos++, "IHLAPI32" );
	m_listTranslateAPI.InsertString( nPos++, "MCS ActiveX" );
	m_listTranslateAPI.InsertString( nPos++, "MCS Java" );
	m_listTranslateAPI.InsertString( nPos++, "MSI" );
	//m_listTranslateAPI.InsertString( nPos++, "PB QACom" );
	m_listTranslateAPI.InsertString( nPos++, "Perforce" );
	m_listTranslateAPI.InsertString( nPos++, "PCSHLL32" );
	m_listTranslateAPI.InsertString( nPos++, "Reflection FTP" );
	m_listTranslateAPI.InsertString( nPos++, "Reflection for Web" );
	m_listTranslateAPI.InsertString( nPos++, "Reflection OLE Auto" );
	m_listTranslateAPI.InsertString( nPos++, "Synapta" );
	m_listTranslateAPI.InsertString( nPos++, "UNIX shell" );
	m_listTranslateAPI.InsertString( nPos++, "Verastream Host Integrator" );
	m_listTranslateAPI.InsertString( nPos++, "ViewMaster" );
	m_listTranslateAPI.InsertString( nPos++, "WHLAPI32" );
	m_listTranslateAPI.SetCurSel(nAPI_Index);

}	



/***************************************************************************DC

	Operation:	CAPIGenDlg::SetWindowSizeLoc()

	Purpose:	Establishes the window size for use as the state and API
				change.

	Notes:		

*****************************************************************************/
void CAPIGenDlg::SetWindowSizeLoc()
{
	// size the window to intro version
	RECT rectDlg;
	GetWindowRect(&rectDlg);

	WidthBig = rectDlg.right - rectDlg.left;
	WidthSmall = WidthBig - 200;
	HeightBig = rectDlg.bottom - rectDlg.top;
	HeightSmall = HeightBig - 300;

}



/****************************************************************************DC
	Function	:	CAPIGenDlg::SetUI()

	Purpose		:	Set the window to the size associated with the current
					state and enables controls as appropriate for that state.

	Note		:	The API_START_STATE case may be obsolete

*****************************************************************************/
void CAPIGenDlg::SetUI()
{

	switch( RunState.GetState() )
	{

		case AIRLINES_READY:
			{
				ReadyState(TRUE);
				PlaceWindow( WidthSmall, HeightSmall );
			}
			break;

		case AIRLINES_PARAM_READY:
			{
				ReadyForParamsState();
				PlaceWindow( WidthBig, HeightSmall );
			}
			break;

		case AIRLINES_GENERATING:
			{
				GeneratingState();
				PlaceWindow( WidthVariable, HeightBig );
			}
			break;
	
		case AIR_VM_READY:
		case CASL_READY:
		case CICS_READY:
		case DOS_READY:
		case PERFORCE_READY:
		case UNIX_READY:
		case VHI_READY:
		{
				ReadyState(TRUE);
				PlaceWindow( WidthSmall, HeightSmall );
			}
			break;

		case AIR_VM_PARAM_READY:
		case CASL_PARAM_READY:
		case CICS_PARAM_READY:
		case DOS_PARAM_READY:
		case PERFORCE_PARAM_READY:
		case UNIX_PARAM_READY:
		case VHI_PARAM_READY:
			{
				ReadyForParamsState();
				PlaceWindow( WidthBig, HeightSmall );
			}
			break;

		case AIR_VM_GENERATING:
		case CASL_GENERATING:
		case CICS_GENERATING:
		case DOS_GENERATING:
		case PERFORCE_GENERATING:
		case UNIX_GENERATING:
		case VHI_GENERATING:
			{
				GeneratingState();
				PlaceWindow( WidthVariable, HeightBig );
			}
			break;

		case EAL_READY:
			{
				ReadyState(TRUE);
				PlaceWindow( WidthSmall, HeightSmall );
			}
			break;

		case EAL_PARAM_READY:
			{
				ReadyForParamsState();
				PlaceWindow( WidthBig, HeightSmall );
			}
			break;

		case EAL_GENERATING:
			{
				GeneratingState();
				PlaceWindow( WidthVariable, HeightBig );
			}
			break;


		case EAOJ_READY:
			{
				ReadyState(TRUE);
				PlaceWindow( WidthSmall, HeightSmall );
			}
			break;

		case EAOJ_PARAM_READY:
			{
				ReadyForParamsState();
				PlaceWindow( WidthBig, HeightSmall );
			}
			break;

		case EAOJ_GENERATING:
			{
				GeneratingState();
				PlaceWindow( WidthVariable, HeightBig );
			}
			break;


		case EAOAx_READY:
			{
				//donc073005 ReadyState(FALSE);
				ReadyState(TRUE);
				PlaceWindow( WidthSmall, HeightSmall );
			}
			break;

		case EAOAx_PARAM_READY:
			{
				ReadyForParamsState();
				PlaceWindow( WidthBig, HeightSmall );
			}
			break;

		case EAOAx_GENERATING:
			{
				GeneratingState();
				PlaceWindow( WidthVariable, HeightBig );
			}
			break;


		case EHL_READY:
			{
				SetAPIList();
				//SetEHLLAPIFunctionStrings();
				ReadyState(TRUE);
				PlaceWindow( WidthVariable, HeightSmall );
			}
			break;

		case EHL_PARAM_READY:
			{
				ReadyForParamsState();
				PlaceWindow( WidthBig, HeightSmall );
			}
			break;

		case EHL_GENERATING:
			{
				GeneratingState();
				PlaceWindow( WidthVariable, HeightBig );
			}
			break;


		case HLL_READY:
			{
				ReadyState(FALSE);
				PlaceWindow( WidthSmall, HeightSmall );
			}
			break;

		case HLL_PARAM_READY:
			{
				ReadyForParamsState();
				PlaceWindow( WidthBig, HeightSmall );
			}
			break;

		case HLL_GENERATING:
			{
				GeneratingState();
				PlaceWindow( WidthVariable, HeightBig );
			}
			break;


		case IHL_READY:
			{
				ReadyState(TRUE);
				PlaceWindow( WidthVariable, HeightSmall );
			}
			break;

		case IHL_PARAM_READY:
			{
				ReadyForParamsState();
				PlaceWindow( WidthBig, HeightSmall );
			}
			break;

		case IHL_GENERATING:
			{
				GeneratingState();
				PlaceWindow( WidthVariable, HeightBig );
			}
			break;


		case MCSAx_READY:
			{
				ReadyState(TRUE);
				PlaceWindow( WidthSmall, HeightSmall );
			}
			break;

		case MCSAx_PARAM_READY:
			{
				ReadyForParamsState();
				PlaceWindow( WidthBig, HeightSmall );
			}
			break;

		case MCSAx_GENERATING:
			{
				GeneratingState();
				PlaceWindow( WidthVariable, HeightBig );
			}
			break;


		case MCSJ_READY:
			{
				ReadyState(TRUE);
				PlaceWindow( WidthSmall, HeightSmall );
			}
			break;

		case MCSJ_PARAM_READY:
			{
				ReadyForParamsState();
				PlaceWindow( WidthBig, HeightSmall );
			}
			break;

		case MCSJ_GENERATING:
			{
				GeneratingState();
				PlaceWindow( WidthVariable, HeightBig );
			}
			break;

		case EOLE_READY:
			{
				ReadyState(TRUE);
				PlaceWindow( WidthVariable, HeightSmall );
			}
			break;

		case EOLE_PARAM_READY:
			{
				ReadyForParamsState();
				PlaceWindow( WidthBig, HeightSmall );
			}
			break;

		case EOLE_GENERATING:
			{
				GeneratingState();
				PlaceWindow( WidthVariable, HeightBig );
			}
			break;

		case ITASK_READY:
			{
				ReadyState(TRUE);
				PlaceWindow( WidthVariable, HeightSmall );
			}
			break;

		case ITASK_PARAM_READY:
			{
				ReadyForParamsState();
				PlaceWindow( WidthBig, HeightSmall );
			}
			break;

		case ITASK_GENERATING:
			{
				GeneratingState();
				PlaceWindow( WidthVariable, HeightBig );
			}
			break;

		case MSI_READY:
			{
				ReadyState(TRUE);
				PlaceWindow( WidthVariable, HeightSmall );
			}
			break;

		case MSI_PARAM_READY:
			{
				ReadyForParamsState();
				PlaceWindow( WidthBig, HeightSmall );
			}
			break;

		case MSI_GENERATING:
			{
				GeneratingState();
				PlaceWindow( WidthVariable, HeightBig );
			}
			break;


		case PCS_READY:
			{
				ReadyState(TRUE);
				PlaceWindow( WidthVariable, HeightSmall );
			}
			break;

		case PCS_PARAM_READY:
			{
				ReadyForParamsState();
				PlaceWindow( WidthBig, HeightSmall );
			}
			break;

		case PCS_GENERATING:
			{
				GeneratingState();
				PlaceWindow( WidthVariable, HeightBig );
			}
			break;


		case QAC_READY:
			{
				ReadyState(TRUE);
				PlaceWindow( WidthSmall, HeightSmall );
			}
			break;

		case QAC_PARAM_READY:
			{
				ReadyForParamsState();
				PlaceWindow( WidthBig, HeightSmall );
			}
			break;

		case QAC_GENERATING:
			{
				GeneratingState();
				PlaceWindow( WidthVariable, HeightBig );
			}
			break;

		case RFTP_READY:
			{
				ReadyState(TRUE);
				PlaceWindow( WidthVariable, HeightSmall );
			}
			break;


		case RFTP_PARAM_READY:
			{
				ReadyForParamsState();
				PlaceWindow( WidthBig, HeightSmall );
			}
			break;

		case RFTP_GENERATING:
			{
				GeneratingState();
				PlaceWindow( WidthVariable, HeightBig );
			}
			break;

		case ROLE_READY:
			{
				ReadyState(TRUE);
				PlaceWindow( WidthVariable, HeightSmall );
			}
			break;

		case ROLE_PARAM_READY:
			{
				ReadyForParamsState();
				PlaceWindow( WidthBig, HeightSmall );
			}
			break;

		case ROLE_GENERATING:
			{
				GeneratingState();
				PlaceWindow( WidthVariable, HeightBig );
			}
			break;


		case RWEB_READY:
			{
				ReadyState(TRUE);
				PlaceWindow( WidthVariable, HeightSmall );
			}
			break;

		case RWEB_PARAM_READY:
			{
				ReadyForParamsState();
				PlaceWindow( WidthBig, HeightSmall );
			}
			break;

		case RWEB_GENERATING:
			{
				GeneratingState();
				PlaceWindow( WidthVariable, HeightBig );
			}
			break;


		case WHL_READY:
			{
				//SetAPIList();
				//SetWHLLAPIFunctionStrings();
				ReadyState(TRUE);
				PlaceWindow( WidthVariable, HeightSmall );
			}
			break;

		case WHL_PARAM_READY:
			{
				ReadyForParamsState();
				PlaceWindow( WidthBig, HeightSmall );
			}
			break;

		case WHL_GENERATING:
			{
				GeneratingState();
				PlaceWindow( WidthVariable, HeightBig );
			}
			break;


		case NO_CAN_DO:
			{
				MessageBox("Sorry, your running state is not expected.  Run away! Run away!");
				return;
			}
			break;


		case DONE:
			{
				RunState.RenewState();

				m_ButtonAppendSource.EnableWindow(FALSE);
				m_buttonFinalizeListing.EnableWindow(FALSE);
				m_ButtonNewProject.EnableWindow(TRUE);
				m_buttonSaveToFile.EnableWindow(TRUE);
				m_buttonSaveToFile.SetFocus();

				PlaceWindow( WidthVariable, HeightBig );

			}
			break;


	}

}



/****************************************************************************DC
	Function	:	CAPIGenDlg::PlaceWindow()

	Purpose		:	Sets the window position and layout

*****************************************************************************/
void CAPIGenDlg::PlaceWindow( LONG Width, LONG Height )
{
	RECT rectDlg;
	GetWindowRect(&rectDlg);
	MoveWindow(rectDlg.left, rectDlg.top, Width, Height);
}





/****************************************************************************DC
	Function	:	CAPIGenDlg::ReadyState()

	Purpose		:	Enables the dialog controls as is appropriate for
					the app when the user can still change the API.  It
					shows the window size such that access to the parameter
					input controls is unavailable.

*****************************************************************************/
void CAPIGenDlg::ReadyState( BOOL bEnablePrompt )
{
	m_buttonPromptForValues.EnableWindow(bEnablePrompt);
	if ( !bEnablePrompt )
	{
		// uncheck checkbox
		m_buttonPromptForValues.SetCheck(0);
		m_bPromptForValues=FALSE;
		WidthVariable=WidthSmall;
	}


	m_ButtonGenerateSource.EnableWindow(TRUE);
	m_ButtonGenerateSource.SetFocus();


	m_listTranslateLanguage.EnableWindow(TRUE);
	m_listTranslateAPI.EnableWindow(TRUE);
	m_listTerminalType.EnableWindow(TRUE);

	m_ButtonAppendSource.EnableWindow(FALSE);

	m_buttonFinalizeListing.EnableWindow(FALSE);

	m_buttonSaveToFile.EnableWindow(FALSE);

	m_ButtonNewProject.EnableWindow(FALSE);

}





/****************************************************************************DC
	Function	:	CAPIGenDlg::ReadyForParamsState()

	Purpose		:	Enables the dialog controls as is appropriate for
					the app when the user can still change the API.  It
					shows the window in a size such that access to the 
					parameter input controls is available.

*****************************************************************************/
void CAPIGenDlg::ReadyForParamsState()
{
	m_buttonPromptForValues.EnableWindow(TRUE);
	m_bPromptForValues=TRUE;

	m_ButtonGenerateSource.EnableWindow(TRUE);
	m_ButtonGenerateSource.SetFocus();

	m_listTranslateLanguage.EnableWindow(TRUE);
	m_listTranslateAPI.EnableWindow(TRUE);
	m_listTerminalType.EnableWindow(TRUE);

	m_ButtonAppendSource.EnableWindow(FALSE);

	m_buttonFinalizeListing.EnableWindow(FALSE);

	m_buttonSaveToFile.EnableWindow(FALSE);

	m_ButtonNewProject.EnableWindow(FALSE);
}



/****************************************************************************DC
	Function	:	CAPIGenDlg::GeneratingState()

	Purpose		:	Enables the dialog controls as is appropriate for
					the app when the user has committed to a specific API.
					That commitment is established when the user clicks
					on the Generate button.
					The window width does not change when the Generate
					button is pressed, but the height expands to expose
					the New and Print buttons.

*****************************************************************************/
void CAPIGenDlg::GeneratingState()
{
	m_buttonPromptForValues.EnableWindow(FALSE);

	m_ButtonGenerateSource.EnableWindow(FALSE);
	m_listTranslateLanguage.EnableWindow(FALSE);
	m_listTranslateAPI.EnableWindow(FALSE);
	m_listTerminalType.EnableWindow(FALSE);

	m_ButtonAppendSource.EnableWindow(TRUE);
	m_ButtonAppendSource.SetFocus();

	m_buttonFinalizeListing.EnableWindow(TRUE);

	m_buttonSaveToFile.EnableWindow(FALSE);

	m_ButtonNewProject.EnableWindow(FALSE);

}



/****************************************************************************DC
	Function	:	CAPIGenDlg::OnChangeString()

	Purpose		:	Keeps an eye on the string entered as a function parameter
					and updates the size control's value to match any change
					in the string control.

*****************************************************************************/
void CAPIGenDlg::OnChangeString() 
{
	UpdateData();
	char buffer[20];
	itoa(m_csInputString.GetLength(), buffer, 10 );
	SetDlgItemText(IDEDIT_STRING_LENGTH, buffer);
}




/****************************************************************************DC
	Function	:	CAPIGenDlg::OnFileInsert()

	Purpose		:	Handles event where user wants to output generated 
					code into an existing file marked with a tag that
					indicates where the input is to be done.
					
					The input tag is, "*** APIGen ***".

*****************************************************************************/
void CAPIGenDlg::OnFileInsert() 
{
	UpdateData();
	if ( m_bCheckFileInsert )
	{
		m_checkInsertIntoFile.SetCheck( BST_CHECKED );
	}
	else
	{
		m_checkInsertIntoFile.SetCheck( BST_UNCHECKED );
	}
}


/****************************************************************************DC
	Function	:	CAPIGenDlg::WriteToView()

	Purpose		:	Dumps the contents of the csaHeader and csaBody string
					arrays to the output view.  

*****************************************************************************/
void CAPIGenDlg::WriteToView( BOOL bFileInsert )
{
	m_listOutputText.ResetContent();

	int i=0;
	for (int k=0; k<csaHeader.GetSize(); k++, i++ )
	{
		m_listOutputText.InsertString( k, csaHeader.GetAt(k) );
	}

	for (int j=0; j<csaBody.GetSize(); j++ )
	{
		m_listOutputText.InsertString( i+j, csaBody.GetAt(j) );
	}

	m_listOutputText.SetCurSel( m_listOutputText.GetCount()-1 );
}





/****************************************************************************DC
	Function	:	CAPIGenDlg::OnSaveToFile()

	Purpose		:	Dumps the contents of the csaHeader and csaBody string
					arrays to a file.  

*****************************************************************************/
void CAPIGenDlg::OnSaveToFile() 
{
	CString csLanguage, csLanguageFileExtension;

	// name and open output file if specified
	SYSTEMTIME	systime;
	GetSystemTime(&systime);
	time_t osBinaryTime;
	time( &osBinaryTime ) ;
	CTime t( osBinaryTime );
	
	int nMonth = t.GetMonth();
	int nDay = t.GetDay();
	int nYear = t.GetYear();

	CString	csAPI_Name;
	int nAPI_Index = m_listTranslateAPI.GetCurSel();
	int n = m_listTranslateAPI.GetTextLen( nAPI_Index );
    m_listTranslateAPI.GetText( nAPI_Index, csAPI_Name.GetBuffer(n) );
    csAPI_Name.ReleaseBuffer();


	int nPosition = m_listTranslateLanguage.GetCurSel();
	m_listTranslateLanguage.GetText( nPosition, csLanguage );
	int nSpacePlace = csLanguage.Find("C++");
	if ( csLanguage.Find("ASP") >= 0 )
	{
		csLanguageFileExtension="asp";
	}
	else if ( csLanguage.Find("C++") >= 0 )
	{
		csLanguageFileExtension="cpp";
	}
	else if ( csLanguage.Find("C#") >= 0 )
	{
		csLanguageFileExtension="cs";
	}
	else if ( csLanguage.Find("DOS command") >= 0 )
	{
		csLanguageFileExtension="bat";
	}
	else if ( csLanguage.Find("HTML") >= 0 )
	{
		csLanguageFileExtension="html";
	}
	else if ( csLanguage.Find("JavaScript") >= 0 )
	{
		if ( -1 != csAPI_Name.Find("ViewMaster") )
		{
			csLanguageFileExtension="html";
		}
		else
		{
			csLanguageFileExtension="js";
		}
	}
	else if ( csLanguage.Find("Java") >= 0 )
	{
		csLanguageFileExtension="java";
	}
	else if ( csLanguage.Find("Node") >= 0 )
	{
		csLanguageFileExtension="html";
	}
	else if ( csLanguage.Find("VBScript") >= 0 )
	{
		if ( -1 != csAPI_Name.Find("ViewMaster") )
		{
			csLanguageFileExtension="html";
		}
		else
		{
			csLanguageFileExtension="vbs";
		}
	}
	else if ( csLanguage.Find("VB 6") >= 0 )
	{
		csLanguageFileExtension="bas";
	}
	else if ( csLanguage.Find("VB.Net") >= 0 )
	{
		csLanguageFileExtension="vb";
	}
	else if ( csLanguage.Find("EB Macro") >= 0 )
	{
		csLanguageFileExtension="ebm";
	}
	else if ( csLanguage.Find("UNIX command") >= 0 )
	{
		csLanguageFileExtension="sh";
	}
	else if ( csLanguage.Find("Windows Script") >= 0 )
	{
		csLanguageFileExtension="vbs";
	}
	else if ( csLanguage.Find("Excel VBA Macro") >= 0 )
	{
		csLanguageFileExtension="xls";
	}
	else
	{
		csLanguageFileExtension="txt";
	}

	

	csScriptFileName.Format(_T("APIGen%i%02i%04i.%s"), nMonth, nDay, nYear, csLanguageFileExtension);
	CString csMask;
	csMask.Format(_T("Source File (*.%s)|*.%s|All Files (*.*)|*.*||"), csLanguageFileExtension, csLanguageFileExtension  );

	CFileDialog fileDialog(FALSE, csLanguageFileExtension, NULL,
	(OFN_HIDEREADONLY | OFN_PATHMUSTEXIST | OFN_OVERWRITEPROMPT), csMask );

	fileDialog.m_ofn.lpstrTitle = _T("Specify name for new source file");

	TCHAR filenameBuffer[4096] = { 0 } ;
	fileDialog.m_ofn.lpstrFile = filenameBuffer;
	fileDialog.m_ofn.nMaxFile = sizeof(filenameBuffer) / sizeof(filenameBuffer[0]);

	strcpy( fileDialog.m_ofn.lpstrFile, csScriptFileName );

	if (IDOK == fileDialog.DoModal())
	{
		csScriptFileName = fileDialog.GetPathName();
		ofstream outfile(csScriptFileName, ios::out);

		for (int k=0; k<csaHeader.GetSize(); k++ )
		{
			outfile << csaHeader.GetAt(k) + '\n';
		}

		for (int j=0; j<csaBody.GetSize(); j++ )
		{
			outfile << csaBody.GetAt(j) + '\n';
		}

		m_checkInsertIntoFile.EnableWindow( FALSE );
	}

	UpdateData(TRUE);
	OnFileInsert();

}



/****************************************************************************DC
	Function	:	CAPIGenDlg::LoadArgumentArray()

	Purpose		:	Load up the arguments for the current function call.

*****************************************************************************/
void CAPIGenDlg::LoadArgumentArray( int* nFunctionPosition )
{
	CString	csFunctionName, csFunctionNum;
	int n, nTerminalType_Index;

	CString	csTerminalType;
	nTerminalType_Index = m_listTerminalType.GetCurSel();
	n = m_listTerminalType.GetTextLen( nTerminalType_Index );
    m_listTerminalType.GetText( nTerminalType_Index, csTerminalType.GetBuffer(n) );
    csTerminalType.ReleaseBuffer();

	switch ( cagtest->APIFlavor )
	{
		case AIRJ_API:
		{
			LoadAirlinesJavaArgumentArray( nFunctionPosition, m_bPromptForValues );
		}
		break;

		case AIRAx_API:
		{
			LoadAirlinesAxArgumentArray( nFunctionPosition, m_bPromptForValues );
		}
		break;

		case VIEWMASTER_API:
		{
			LoadAirVMArgumentArray( nFunctionPosition, m_bPromptForValues );
		}
		break;


		case CASL_API:
		{
			LoadCASLArgumentArray( nFunctionPosition, m_bPromptForValues );
		}
		break;

		case CICS_COM_API:
		{
			LoadCICSCOMArgumentArray( nFunctionPosition, m_bPromptForValues );
		}
		break;

		case CICS11_JAVA_API:
		{
			LoadCICS11JAVAArgumentArray( nFunctionPosition, m_bPromptForValues );
		}
		break;

		case CICS20_JAVA_API:
		{
			LoadCICS20JAVAArgumentArray( nFunctionPosition, m_bPromptForValues );
		}
		break;

		case CICS_NET_API:
		{
			LoadCICSNETArgumentArray( nFunctionPosition, m_bPromptForValues );
		}
		break;

		case DOS_API:
		{
			LoadDOSArgumentArray( nFunctionPosition, m_bPromptForValues );
		}
		break;

		case EAL_API:
		{
			LoadEALArgumentArray( nFunctionPosition, m_bPromptForValues );
		}
		break;

		case EA0J_API:
		case MCSJ_API:
		{
			LoadEAOJArgumentArray( nFunctionPosition, m_bPromptForValues );
		}
		break;


		case EA0Ax_API:
		case MCSAx_API:
		{
			if ( csTerminalType == "3270" )
			{
				LoadEAOAx3270ArgumentArray( nFunctionPosition, m_bPromptForValues );
			}
			else if ( csTerminalType == "5250" )
			{
				LoadEAOAx5250ArgumentArray( nFunctionPosition, m_bPromptForValues );
			}
			else
			{
				LoadEAOAxVTArgumentArray( nFunctionPosition, m_bPromptForValues );
			}
		}
		break;


		case EHL_API:
		case PCS_API:
		{
			
			LoadEHLArgumentArray( nFunctionPosition, m_bPromptForValues );
		}
		break;

		case HLL_API:
		{
			LoadHLLArgumentArray( nFunctionPosition, m_bPromptForValues );
		}
		break;

		case IHL_API:
		case WHL_API:
		{
			LoadWHLArgumentArray( nFunctionPosition, m_bPromptForValues );
		}
		break;

		case EOLE_API:
		{
			LoadEOLEArgumentArray( nFunctionPosition, m_bPromptForValues );
		}
		break;
		
		case ICONN_API:
		{
			LoadICONNArgumentArray( nFunctionPosition, m_bPromptForValues );
		}
		break;

		case ITASK_API:
		{
			LoadITaskArgumentArray( nFunctionPosition, m_bPromptForValues );
		}
		break;

		case MSI_APP_API:
		{
			LoadMSIAppArgumentArray( nFunctionPosition, m_bPromptForValues );
		}
		break;

		case MSI_CUSTOM_API:
		{
			LoadMSICustomArgumentArray( nFunctionPosition, m_bPromptForValues );
		}
		break;

		case MSI_DB_API:
		{
			LoadMSIDBaseArgumentArray( nFunctionPosition, m_bPromptForValues );
		}
		break;

		case MSI_EXEC_API:
		{
			LoadMSIExecArgumentArray( nFunctionPosition, m_bPromptForValues );
		}
		break;

		case MSI_SUMMARY_API:
		{
			LoadMSISummaryArgumentArray( nFunctionPosition, m_bPromptForValues );
		}
		break;

		case MSI_WIXDLG_API:
		{
			LoadWIXDlgArgumentArray( nFunctionPosition, m_bPromptForValues );
		}
		break;

		case MSI_WIXWIZ_API:
		{
			LoadWIXWizArgumentArray( nFunctionPosition, m_bPromptForValues );
		}
		break;

		case PERFORCE_API:
		{
			LoadPerforceArgumentArray( nFunctionPosition, m_bPromptForValues );
		}
		break;

		case QACOM_API:
		{
			LoadQAComArgumentArray( nFunctionPosition, m_bPromptForValues );
		}
		break;

		case RFTP_API:
		{
			LoadRFTPArgumentArray( nFunctionPosition, m_bPromptForValues );
		}
		break;
		
		case RIBM_OLE_API:
		{
			LoadRIBM_OLEArgumentArray( nFunctionPosition, m_bPromptForValues );
		}
		break;

		case RWEB_API:
		{
			LoadRWeb_ArgumentArray( nFunctionPosition, m_bPromptForValues );
		}
		break;

		case RWIN_OLE_API:
		{
			LoadRWIN_OLEArgumentArray( nFunctionPosition, m_bPromptForValues );
		}
		break;

		case UNIX_API:
		{
			LoadUNIXArgumentArray( nFunctionPosition, m_bPromptForValues );
		}
		break;

		case VHI_API:
		{
			LoadVHIArgumentArray( nFunctionPosition, m_bPromptForValues );
		}
		break;



	}

}




/****************************************************************************DC
	Function	:	CAPIGenDlg::OnChangeFunctionChoice()

	Purpose		:	Change the list of arguments that display in the 
					parameter view as the function selection changes.

*****************************************************************************/
void CAPIGenDlg::OnChangeFunctionChoice() 
{
	int n, nTerminalType_Index;

	CString	csTerminalType;
	nTerminalType_Index = m_listTerminalType.GetCurSel();
	n = m_listTerminalType.GetTextLen( nTerminalType_Index );
    m_listTerminalType.GetText( nTerminalType_Index, csTerminalType.GetBuffer(n) );
    csTerminalType.ReleaseBuffer();
	
	if ( !(cagtest->APIFlavor == EHL_API ||
		 cagtest->APIFlavor == IHL_API ||
		 cagtest->APIFlavor == PCS_API ||
		 cagtest->APIFlavor == WHL_API ) )
	{

		int nPosition = m_listTranslateFunction.GetCurSel();
		HideParameterControls();

		switch ( cagtest->APIFlavor )
		{
			case AIRAx_API:
			{
				ShowAirAxControls( nPosition );
			}
			break;

			case AIRJ_API:
			{
				ShowAirJControls( nPosition );
			}
			break;

			case VIEWMASTER_API:
			{
				ShowAirVMControls( nPosition );
			}
			break;



			case CASL_API:
			{
				ShowCASLControls( nPosition );
			}
			break;

			case CICS_COM_API:
			{
				ShowCICSCOMControls( nPosition );
			}
			break;

			case CICS11_JAVA_API:
			{
				ShowCICS11JAVAControls( nPosition );
			}
			break;

			case CICS20_JAVA_API:
			{
				ShowCICS20JAVAControls( nPosition );
			}
			break;

			case CICS_NET_API:
			{
				ShowCICSNETControls( nPosition );
			}
			break;

			case DOS_API:
			{
				ShowDOSControls( nPosition );
			}
			break;

			case EAL_API:
			{
				ShowEALControls( nPosition );
			}
			break;

			case EA0Ax_API:
			case MCSAx_API:
			{
				if ( csTerminalType == "3270" )
				{
					ShowEAOAx3270Controls( nPosition );
				}
				else if ( csTerminalType == "5250" )
				{
					ShowEAOAx5250Controls( nPosition );
				}
				else
				{
					ShowEAOAxVTControls( nPosition );
				}
			}
			break;


			case EA0J_API:
			case MCSJ_API:
			{
				ShowEAOJControls( nPosition );
			}
			break;


			case EHL_API:
			case IHL_API:
			case PCS_API:
			case WHL_API:
			{
				ShowEHLControls();
			}
			break;

			case EOLE_API:
			{
				ShowEOLEControls( nPosition );
			}
			break;

			case HLL_API:
			{
				//ShowHLLControls();
			}
			break;

			case ICONN_API:
			{
				ShowICONNControls( nPosition );
			}
			break;

			case ITASK_API:
			{
				ShowITaskControls( nPosition );
			}
			break;
			
			case MSI_APP_API:
			{
				ShowMSIAppControls( nPosition );
			}
			break;

			case MSI_CUSTOM_API:
			{
				ShowMSICustomControls( nPosition );
			}
			break;

			case MSI_DB_API:
			{
				ShowMSIDBaseControls( nPosition );
			}
			break;

			case MSI_EXEC_API:
			{
				ShowMSIExecControls( nPosition );
			}
			break;

			case MSI_SUMMARY_API:
			{
				ShowMSISummaryControls( nPosition );
			}
			break;

			case MSI_WIXDLG_API:
			{
				ShowWIXDlgControls( nPosition );
			}
			break;

			case MSI_WIXWIZ_API:
			{
				ShowWIXWizControls( nPosition );
			}
			break;

			case QACOM_API:
			{
				//ShowOLEControls( nPosition );
			}
			break;

			case PERFORCE_API:
			{
				ShowPerforceControls( nPosition );
			}
			break;

			case RIBM_OLE_API:
			{
				ShowRIBMControls( nPosition );
			}
			break;

			case RWEB_API:
			{
				ShowRWebControls( nPosition );
			}
			break;

			case RWIN_OLE_API:
			{
				ShowRWinControls( nPosition );
			}
			break;

			case RFTP_API:
			{
				ShowRFTPControls( nPosition );
			}
			break;

			case UNIX_API:
			{
				ShowUNIXControls( nPosition );
			}
			break;

			case VHI_API:
			{
				ShowVHIControls( nPosition );
			}
			break;


		}
	}
}





void CAPIGenDlg::OnHelp()
{
	HINSTANCE hinstShell = ShellExecute (NULL, _T("Open"), "help.htm", _T(""), _T(""), SW_SHOWNORMAL);
}


// this next block is to handle the CICS QACom special case where
// the terminal types all are supported by a mutually exclusive list
// of programming languages
// This is only relevant if the user changes the API flavor in the 
//  terminal type control
void CAPIGenDlg::ChangeTerminal()
{
	CString	csAPI_Name;
	nAPI_Index = m_listTranslateAPI.GetCurSel();
	int n = m_listTranslateAPI.GetTextLen( nAPI_Index );
    m_listTranslateAPI.GetText( nAPI_Index, csAPI_Name.GetBuffer(n) );
    csAPI_Name.ReleaseBuffer();

	CString	csTerminalType;
	nTerminalType_Index = m_listTerminalType.GetCurSel();
	n = m_listTerminalType.GetTextLen( nTerminalType_Index );
    m_listTerminalType.GetText( nTerminalType_Index, csTerminalType.GetBuffer(n) );
    csTerminalType.ReleaseBuffer();

	// if changed api flavor only then reset the language list
	if ( csAPI_Name == "CICS Bridge QACom" )
	{
		int nPos = 0;
		m_listTranslateLanguage.ResetContent();

		if ( csTerminalType == "COM" )
		{
			m_listTranslateLanguage.InsertString( nPos++, "ASP" );
			m_listTranslateLanguage.InsertString( nPos++, "C++" );
			m_listTranslateLanguage.InsertString( nPos++, "VB 6.0" );
		}
		else if ( csTerminalType == "CICS 1.1 JAVA" )
		{
			m_listTranslateLanguage.InsertString( nPos++, "Java" );
		}
		else if ( csTerminalType == "CICS 2.0 JAVA" )
		{
			m_listTranslateLanguage.InsertString( nPos++, "Java" );
		}
		else if ( csTerminalType == ".Net" )
		{
			m_listTranslateLanguage.InsertString( nPos++, "VB.Net" );
			m_listTranslateLanguage.InsertString( nPos++, "C#" );
		}

		m_listTranslateLanguage.SetCurSel(0);

	}
	else if ( csAPI_Name == "Synapta" )
	{
		int nPos = 0;
		m_listTranslateLanguage.ResetContent();

		if ( csTerminalType == "IConnectorAccess" )
		{
			m_listTranslateLanguage.InsertString( nPos++, "Java" );
			m_listTranslateLanguage.InsertString( nPos++, "ASP" );
			m_listTranslateLanguage.InsertString( nPos++, "C#" );
			m_listTranslateLanguage.InsertString( nPos++, "VB.Net" );
			m_listTranslateLanguage.InsertString( nPos++, "Windows Script" );
		}
		else if ( csTerminalType == "ITask" || csTerminalType == "ScreenNativeAccess" )
		{
			m_listTranslateLanguage.InsertString( nPos++, "Java" );
		}

		m_listTranslateLanguage.SetCurSel(0);

	}
	else if ( csAPI_Name == "MSI" )
	{
		int nPos = 0;
		m_listTranslateLanguage.ResetContent();

		if ( csTerminalType == "Installer App" )
		{
			m_listTranslateLanguage.InsertString( nPos++, "C++" );
			m_listTranslateLanguage.InsertString( nPos++, "VBScript" );
			m_listTranslateLanguage.InsertString( nPos++, "Windows Script" );
		}
		else if ( csTerminalType == "Custom Action DLL" )
		{
			m_listTranslateLanguage.InsertString( nPos++, "C++" );
			m_listTranslateLanguage.InsertString( nPos++, "VBScript" );
			m_listTranslateLanguage.InsertString( nPos++, "Windows Script" );
		}
		else if ( csTerminalType == "Database App" )
		{
			m_listTranslateLanguage.InsertString( nPos++, "C++" );
			m_listTranslateLanguage.InsertString( nPos++, "VBScript" );
			m_listTranslateLanguage.InsertString( nPos++, "Windows Script" );
		}
		else // if ( csTerminalType == "WIX dialog" || csTerminalType == "WIX wizard" )
		{
			m_listTranslateLanguage.InsertString( nPos++, "XML" );
		}

		m_listTranslateLanguage.SetCurSel(0);

	}


	ChangeTerminalOrLanguage();
}



void CAPIGenDlg::ChangeTerminalOrLanguage()
{

	CString	csAPI_Name;
	nAPI_Index = m_listTranslateAPI.GetCurSel();
	int n = m_listTranslateAPI.GetTextLen( nAPI_Index );
    m_listTranslateAPI.GetText( nAPI_Index, csAPI_Name.GetBuffer(n) );
    csAPI_Name.ReleaseBuffer();

	CString	csTerminalType;
	nTerminalType_Index = m_listTerminalType.GetCurSel();
	n = m_listTerminalType.GetTextLen( nTerminalType_Index );
    m_listTerminalType.GetText( nTerminalType_Index, csTerminalType.GetBuffer(n) );
    csTerminalType.ReleaseBuffer();

	CString csLanguage_Name;
	int nTranslateLanguage_Index = m_listTranslateLanguage.GetCurSel();
	n = m_listTranslateLanguage.GetTextLen( nTranslateLanguage_Index );
	m_listTranslateLanguage.GetText( nTranslateLanguage_Index, csLanguage_Name );
    csLanguage_Name.ReleaseBuffer();

	delete cagtest;
//	m_listTranslateFunction.ResetContent();
//	m_listTranslateLanguage.ResetContent();
//	m_listTerminalType.ResetContent();

	// the language will be set assuming that the terminal type
	// is java 3270 and programming language is java
	if ( csAPI_Name == "Airlines SDK" )
	{
		if ( csTerminalType == "3270" )
		{
			if ( csLanguage_Name == "Java" )
			{
				cagtest = new CAG_AIR_3270_J_J;
			}
			else	// C++ or ASP
			{
				cagtest = new CAG_AIR_3270_Ax_CPP;
			}
		}
		else if ( csTerminalType == "5250" )
		{
			if ( csLanguage_Name == "Java" )
			{
				cagtest = new CAG_AIR_5250_J_J;
			}
			else	// C++ or ASP
			{
				cagtest = new CAG_AIR_5250_Ax_CPP;
			}
		}
		else if ( csTerminalType == "VT" )
		{
			if ( csLanguage_Name == "Java" )
			{
				cagtest = new CAG_AIR_VT_J_J;
			}
			else	// C++ or ASP
			{
				cagtest = new CAG_AIR_VT_Ax_CPP;
			}
		}
		else if ( csTerminalType == "T27/TCPA" )
		{
			cagtest = new CAG_AIR_3270_J;
		}
		else if ( csTerminalType == "UTS/INT1" )
		{
			cagtest = new CAG_AIR_3270_J;
		}
		else if ( csTerminalType == "UTS/MATIP" )
		{
			cagtest = new CAG_AIR_UTS_MATIP_J;
		}
		else if ( csTerminalType == "UTS/PEPGate" )
		{
			cagtest = new CAG_AIR_3270_J;
		}
		else if ( csTerminalType == "ALC/MATIP" )
		{
			cagtest = new CAG_AIR_3270_J;
		}
		else if ( csTerminalType == "ALC/EDS SHARES" )
		{
			cagtest = new CAG_AIR_3270_J;
		}
		else if ( csTerminalType == "ALC/SABRE" )
		{
			cagtest = new CAG_AIR_3270_J;
		}
		else if ( csTerminalType == "ALC/APOLLO" )
		{
			cagtest = new CAG_AIR_3270_J;
		}
		else if ( csTerminalType == "ALC/LANTERN" )
		{
			cagtest = new CAG_AIR_3270_J;
		}
		else // MCS
		{
			cagtest = new CAG_AIR_3270_J;
		}

		m_buttonPromptForValues.EnableWindow(TRUE);

		RunState.SendAction( AIR_NOW );

	}
	else if ( csAPI_Name == "ViewMaster" )
	{
		if ( csTerminalType == "3270" )
		{
			if ( csLanguage_Name == "JavaScript" )
			{
				cagtest = new CAG_AIR_VM_3270_J;
			}
			else	// VBScript
			{
				cagtest = new CAG_AIR_VM_3270_VBS;
			}
		}
/*		else if ( csTerminalType == "5250" )
		{
			if ( csLanguage_Name == "JavaScript" )
			{
				cagtest = new CAG_AIR_VM_5250_J;
			}
			else	// VBScript
			{
				cagtest = new CAG_AIR_VM_5250_VBS;
			}
		} */
		else if ( csTerminalType == "T27/TCPA" )
		{
			if ( csLanguage_Name == "JavaScript" )
			{
				cagtest = new CAG_AIR_VM_T27_J;
			}
			else	// VBScript
			{
				cagtest = new CAG_AIR_VM_T27_VBS;
			}
		}
		else if ( csTerminalType == "UTS/INT1" )
		{
			if ( csLanguage_Name == "JavaScript" )
			{
				cagtest = new CAG_AIR_VM_UTS_J;
			}
			else	// VBScript
			{
				cagtest = new CAG_AIR_VM_UTS_VBS;
			}
		}
	}
	else if ( csAPI_Name == "MCS ActiveX" )
	{
		if ( csTerminalType == "3270" )
		{
			if ( csLanguage_Name == "JavaScript CRL" )
			{
				cagtest = new CAG_MCS_Ax_3270_JS_CRL;
			}
			else if ( csLanguage_Name == "JavaScript Deployed" )
			{
				cagtest = new CAG_MCS_Ax_3270_JS_DEPLOY;
			}
			else if ( csLanguage_Name == "JavaScript HDR" )
			{
				cagtest = new CAG_MCS_Ax_3270_JS_HDR;
			}
			else if ( csLanguage_Name == "JavaScript HTML" )
			{
				cagtest = new CAG_MCS_Ax_3270_JS_HTML;
			}
			else if ( csLanguage_Name == "VBScript CRL" )
			{
				cagtest = new CAG_MCS_Ax_3270_VBS_HDR;
			}
			else if ( csLanguage_Name == "VBScript Deployed" )
			{
				cagtest = new CAG_MCS_Ax_3270_VBS_DEPLOY;
			}
			else if ( csLanguage_Name == "VBScript HDR" )
			{
				cagtest = new CAG_MCS_Ax_3270_VBS_HDR;
			}
			else // VBScript HTML
			{
				cagtest = new CAG_MCS_Ax_3270_VBS_HTML;
			}
		}
		else if ( csTerminalType == "5250" )
		{
			if ( csLanguage_Name == "JavaScript CRL" )
			{
				cagtest = new CAG_MCS_Ax_5250_JS_CRL;
			}
			else if ( csLanguage_Name == "JavaScript Deployed" )
			{
				cagtest = new CAG_MCS_Ax_5250_JS_DEPLOY;
			}
			else if ( csLanguage_Name == "JavaScript HDR" )
			{
				cagtest = new CAG_MCS_Ax_5250_JS_HDR;
			}
			else if ( csLanguage_Name == "JavaScript HTML" )
			{
				cagtest = new CAG_MCS_Ax_5250_JS_HTML;
			}
			else if ( csLanguage_Name == "VBScript CRL" )
			{
				cagtest = new CAG_MCS_Ax_5250_VBS_CRL;
			}
			else if ( csLanguage_Name == "VBScript Deployed" )
			{
				cagtest = new CAG_MCS_Ax_5250_VBS_DEPLOY;
			}
			else if ( csLanguage_Name == "VBScript HDR" )
			{
				cagtest = new CAG_MCS_Ax_5250_VBS_HDR;
			}
			else // VBScript HTML
			{
				cagtest = new CAG_MCS_Ax_5250_VBS_HTML;
			}
		}
		else	// VT
		{
			if ( csLanguage_Name == "JavaScript CRL" )
			{
				cagtest = new CAG_MCS_Ax_VT_JS_CRL;
			}
			else if ( csLanguage_Name == "JavaScript Deployed" )
			{
				cagtest = new CAG_MCS_Ax_VT_JS_DEPLOY;
			}
			else if ( csLanguage_Name == "JavaScript HDR" )
			{
				cagtest = new CAG_MCS_Ax_VT_JS_HDR;
			}
			else if ( csLanguage_Name == "JavaScript HTML" )
			{
				cagtest = new CAG_MCS_Ax_VT_JS_HTML;
			}
			else if ( csLanguage_Name == "VBScript CRL" )
			{
				cagtest = new CAG_MCS_Ax_VT_VBS_CRL;
			}
			else if ( csLanguage_Name == "VBScript Deployed" )
			{
				cagtest = new CAG_MCS_Ax_VT_VBS_DEPLOY;
			}
			else if ( csLanguage_Name == "VBScript HDR" )
			{
				cagtest = new CAG_MCS_Ax_VT_VBS_HDR;
			}
			else // VBScript HTML
			{
				cagtest = new CAG_MCS_Ax_VT_VBS_HTML;
			}
		}

		m_buttonPromptForValues.EnableWindow(FALSE);
		RunState.SendAction( MCSAx_NOW );
	
	}
	else if ( csAPI_Name == "MCS Java" )
	{
		if ( csLanguage_Name == "JavaScript CRL" )
		{
			if ( csTerminalType == "3270" )
			{
				cagtest = new CAG_MCS_J_3270_JS_CRL;
				m_buttonPromptForValues.EnableWindow(TRUE);
			}
			else if ( csTerminalType == "5250" )
			{
				cagtest = new CAG_MCS_J_5250_JS_CRL;
				m_buttonPromptForValues.EnableWindow(TRUE);
			}
			else
			{
				cagtest = new CAG_MCS_J_VT_JS_CRL;
				m_buttonPromptForValues.EnableWindow(TRUE);
			}
		}
		else if ( csLanguage_Name == "JavaScript Deployed" )
		{
			if ( csTerminalType == "3270" )
			{
				cagtest = new CAG_MCS_J_3270_JS_DEPLOY;
				m_buttonPromptForValues.EnableWindow(TRUE);
			}
			else if ( csTerminalType == "5250" )
			{
				cagtest = new CAG_MCS_J_5250_JS_DEPLOY;
				m_buttonPromptForValues.EnableWindow(TRUE);
			}
			else
			{
				cagtest = new CAG_MCS_J_VT_JS_DEPLOY;
				m_buttonPromptForValues.EnableWindow(TRUE);
			}
		}
		else if ( csLanguage_Name == "JavaScript HDR" )
		{
			if ( csTerminalType == "3270" )
			{
				cagtest = new CAG_MCS_J_3270_JS_HDR;
				m_buttonPromptForValues.EnableWindow(TRUE);
			}
			else if ( csTerminalType == "5250" )
			{
				cagtest = new CAG_MCS_J_5250_JS_HDR;
				m_buttonPromptForValues.EnableWindow(TRUE);
			}
			else
			{
				cagtest = new CAG_MCS_J_VT_JS_HDR;
				m_buttonPromptForValues.EnableWindow(TRUE);
			}
		}
		else if ( csLanguage_Name == "VBScript CRL" )
		{
			if ( csTerminalType == "3270" )
			{
				cagtest = new CAG_MCS_J_3270_VBS_CRL;
				m_buttonPromptForValues.EnableWindow(TRUE);
			}
			else if ( csTerminalType == "5250" )
			{
				cagtest = new CAG_MCS_J_5250_VBS_CRL;
				m_buttonPromptForValues.EnableWindow(TRUE);
			}
			else
			{
				cagtest = new CAG_MCS_J_VT_VBS_CRL;
				m_buttonPromptForValues.EnableWindow(TRUE);
			}
		}
		else if ( csLanguage_Name == "VBScript Deployed" )
		{
			if ( csTerminalType == "3270" )
			{
				cagtest = new CAG_MCS_J_3270_VBS_DEPLOY;
				m_buttonPromptForValues.EnableWindow(TRUE);
			}
			else if ( csTerminalType == "5250" )
			{
				cagtest = new CAG_MCS_J_5250_VBS_DEPLOY;
				m_buttonPromptForValues.EnableWindow(TRUE);
			}
			else
			{
				cagtest = new CAG_MCS_J_VT_VBS_DEPLOY;
				m_buttonPromptForValues.EnableWindow(TRUE);
			}
		}
		else if ( csLanguage_Name == "VBScript HDR" )
		{
			if ( csTerminalType == "3270" )
			{
				cagtest = new CAG_MCS_J_3270_VBS_HDR;
				m_buttonPromptForValues.EnableWindow(TRUE);
			}
			else if ( csTerminalType == "5250" )
			{
				cagtest = new CAG_MCS_J_5250_VBS_HDR;
				m_buttonPromptForValues.EnableWindow(TRUE);
			}
			else
			{
				cagtest = new CAG_MCS_J_VT_VBS_HDR;
				m_buttonPromptForValues.EnableWindow(TRUE);
			}
		}
		else if ( csLanguage_Name == "JavaScript HTML" )
		{
			if ( csTerminalType == "3270" )
			{
				cagtest = new CAG_MCS_J_3270_JS_HTML;
				m_buttonPromptForValues.EnableWindow(TRUE);
			}
			else if ( csTerminalType == "5250" )
			{
				cagtest = new CAG_MCS_J_5250_JS_HTML;
				m_buttonPromptForValues.EnableWindow(TRUE);
			}
			else
			{
				cagtest = new CAG_MCS_J_VT_JS_HTML;
				m_buttonPromptForValues.EnableWindow(TRUE);
			}
		}
		else if ( csLanguage_Name == "VBScript HTML" )
		{
			if ( csTerminalType == "3270" )
			{
				cagtest = new CAG_MCS_J_3270_VBS_HTML;
				m_buttonPromptForValues.EnableWindow(TRUE);
			}
			else if ( csTerminalType == "5250" )
			{
				cagtest = new CAG_MCS_J_5250_VBS_HTML;
				m_buttonPromptForValues.EnableWindow(TRUE);
			}
			else
			{
				cagtest = new CAG_MCS_J_VT_VBS_HTML;
				m_buttonPromptForValues.EnableWindow(TRUE);
			}
		}
		m_buttonPromptForValues.EnableWindow(TRUE);
		RunState.SendAction( MCSJ_NOW );
	}


	else if ( csAPI_Name == "MSI" )
	{
		if ( csTerminalType == "Installer App"  )
		{
			if ( csLanguage_Name == "C++" )
			{
				cagtest = new CAG_MSI_APP_CPP;
				m_buttonPromptForValues.EnableWindow(TRUE);
			}
			else if ( csLanguage_Name == "VBScript" )
			{
				cagtest = new CAG_MSI_APP_VBS;
				m_buttonPromptForValues.EnableWindow(TRUE);
			}
			else if ( csLanguage_Name == "Windows Script" )
			{
				cagtest = new CAG_MSI_APP_WS;
				m_buttonPromptForValues.EnableWindow(TRUE);
			}
		}
		else if ( csTerminalType == "Custom Action DLL" )
		{
			if ( csLanguage_Name == "C++" )
			{
				cagtest = new CAG_MSI_CUSTOM_CPP;
				m_buttonPromptForValues.EnableWindow(TRUE);
			}
			else if ( csLanguage_Name == "VBScript" )
			{
				cagtest = new CAG_MSI_CUSTOM_VBS;
				m_buttonPromptForValues.EnableWindow(TRUE);
			}
			else if ( csLanguage_Name == "Windows Script" )
			{
				cagtest = new CAG_MSI_CUSTOM_WS;
				m_buttonPromptForValues.EnableWindow(TRUE);
			}
		}
		else if ( csTerminalType == "Database App" )
		{
			if ( csLanguage_Name == "C++" )
			{
				cagtest = new CAG_MSI_DBASE_CPP;
				m_buttonPromptForValues.EnableWindow(TRUE);
			}
			else if ( csLanguage_Name == "VBScript" )
			{
				cagtest = new CAG_MSI_DBASE_VBS;
				m_buttonPromptForValues.EnableWindow(TRUE);
			}
			else if ( csLanguage_Name == "Windows Script" )
			{
				cagtest = new CAG_MSI_DBASE_WS;
				m_buttonPromptForValues.EnableWindow(TRUE);
			}
		}
		else if ( csTerminalType == "Summary Info" )
		{
			cagtest = new CAG_MSI_SUMMARY_INFO;
			m_buttonPromptForValues.EnableWindow(TRUE);

			int nPos = 0;
			m_listTranslateLanguage.ResetContent();
			m_listTranslateLanguage.InsertString( nPos++, "DOS Command" );
			m_listTranslateLanguage.SetCurSel(0);
		}
		else if ( csTerminalType == "MSIExec" )
		{
			cagtest = new CAG_MSI_MSIEXEC;
			m_buttonPromptForValues.EnableWindow(TRUE);

			int nPos = 0;
			m_listTranslateLanguage.ResetContent();
			m_listTranslateLanguage.InsertString( nPos++, "DOS Command" );
			m_listTranslateLanguage.SetCurSel(0);
		}
		else if ( csTerminalType == "WIX dialog" )
		{
			cagtest = new CAG_MSI_WIX_DLG;
			m_buttonPromptForValues.EnableWindow(TRUE);

			int nPos = 0;
			m_listTranslateLanguage.ResetContent();
			m_listTranslateLanguage.InsertString( nPos++, "XML" );
			m_listTranslateLanguage.SetCurSel(0);
		}
		else if ( csTerminalType == "WIX wizard" )
		{
			cagtest = new CAG_MSI_WIX_WIZ;
			m_buttonPromptForValues.EnableWindow(TRUE);

			int nPos = 0;
			m_listTranslateLanguage.ResetContent();
			m_listTranslateLanguage.InsertString( nPos++, "XML" );
			m_listTranslateLanguage.SetCurSel(0);
		}


		m_buttonPromptForValues.EnableWindow(TRUE);
		RunState.SendAction( MSI_NOW );

	}

	else if ( csAPI_Name == "CASL Macro" )
	{
		cagtest = new CAG_CASL;
		m_buttonPromptForValues.EnableWindow(TRUE);
	}
	else if ( csAPI_Name == "DOS shell" )
	{
		cagtest = new CAG_DOS;
		m_buttonPromptForValues.EnableWindow(TRUE);
	}
	else if ( csAPI_Name == "CICS Bridge QACom" )
	{
		if ( csTerminalType == "COM" )
		{
			if ( csLanguage_Name == "ASP" )
			{
				cagtest = new CAG_CICS_QACOM_COM_ASP;
				m_buttonPromptForValues.EnableWindow(TRUE);
			}
			else if ( csLanguage_Name == "C++" )
			{
				cagtest = new CAG_CICS_QACOM_COM_CPP;

				m_buttonPromptForValues.EnableWindow(TRUE);
			}
			else if ( csLanguage_Name == "VB 6.0" )
			{
				cagtest = new CAG_CICS_QACOM_COM_VB6;
				m_buttonPromptForValues.EnableWindow(TRUE);
			}

			if(m_bPromptForValues)
			{
				HideParameterControls();
				ShowCICSCOMControls(0);
			}

		}
		else if ( csTerminalType == "CICS 1.1 JAVA" )
		{
			cagtest = new CAG_CICS11_QACOM_JAVA_J;
			m_buttonPromptForValues.EnableWindow(TRUE);

			if(m_bPromptForValues)
			{
				HideParameterControls();
				ShowCICS11JAVAControls(0);
			}
		}
		else if ( csTerminalType == "CICS 2.0 JAVA" )
		{
			cagtest = new CAG_CICS20_QACOM_JAVA_J;
			m_buttonPromptForValues.EnableWindow(TRUE);

			if(m_bPromptForValues)
			{
				HideParameterControls();
				ShowCICS20JAVAControls(0);
			}
		}
		else if ( csTerminalType == ".Net" )
		{
			if ( csLanguage_Name == "VB.Net" )
			{
				cagtest = new CAG_CICS_QACOM_NET_VBN;
				m_buttonPromptForValues.EnableWindow(TRUE);
			}
			else if ( csLanguage_Name == "C#" )
			{
				cagtest = new CAG_CICS_QACOM_NET_CS;
				m_buttonPromptForValues.EnableWindow(TRUE);
			}

			if(m_bPromptForValues)
			{
				HideParameterControls();
				ShowCICSNETControls(0);
			}

		}

		RunState.SendAction( CICS_NOW );
	}

	else if ( csAPI_Name == "ATMAPI32" )
	{
        if ( csLanguage_Name == "C++" )
        {
			cagtest = new CAG_EAL_CPP;
			m_buttonPromptForValues.EnableWindow(FALSE);
		}
		else if ( csLanguage_Name == "C#" )
        {
			cagtest = new CAG_EAL_CS;
			m_buttonPromptForValues.EnableWindow(FALSE);
		}
		else if ( csLanguage_Name == "VB 6.0" )
        {
			cagtest = new CAG_EAL_VB6;
			m_buttonPromptForValues.EnableWindow(FALSE);
		}
		else // VB.Net
        {
			cagtest = new CAG_EAL_VBN;
			m_buttonPromptForValues.EnableWindow(FALSE);
		}

		m_buttonPromptForValues.EnableWindow(FALSE);
		RunState.SendAction( EAL_NOW );
	}
	else if ( csAPI_Name == "EAO ActiveX" )
	{
        if ( csLanguage_Name == "C++" )
        {
			if ( csTerminalType == "3270" )
			{
				cagtest = new CAG_EAOAx_3270_CPP;
				m_buttonPromptForValues.EnableWindow(FALSE);
			}
			else if ( csTerminalType == "5250" )
			{
				cagtest = new CAG_EAOAx_5250_CPP;
				m_buttonPromptForValues.EnableWindow(FALSE);
			}
			else // VT
			{
				cagtest = new CAG_EAOAx_VT_CPP;
				m_buttonPromptForValues.EnableWindow(FALSE);
			}
        }
		else if ( csLanguage_Name == "C#" )
        {
			if ( csTerminalType == "3270" )
			{
				cagtest = new CAG_EAOAx_3270_CS;
				m_buttonPromptForValues.EnableWindow(FALSE);
			}
			else if ( csTerminalType == "5250" )
			{
				cagtest = new CAG_EAOAx_5250_CS;
				m_buttonPromptForValues.EnableWindow(FALSE);
			}
			else
			{
				cagtest = new CAG_EAOAx_VT_CS;
				m_buttonPromptForValues.EnableWindow(FALSE);
			}
        }
		else if ( csLanguage_Name == "JavaScript HTML" )
        {
            if ( csTerminalType == "3270" )
			{
				cagtest = new CAG_EAOAx_3270_HTML_JS;
				m_buttonPromptForValues.EnableWindow(FALSE);
			}
			else if ( csTerminalType == "5250" )
			{
				cagtest = new CAG_EAOAx_5250_HTML_JS;
				m_buttonPromptForValues.EnableWindow(FALSE);
			}
			else	// VT
			{
				cagtest = new CAG_EAOAx_VT_HTML_JS;
				m_buttonPromptForValues.EnableWindow(FALSE);
			}
        }
		else if ( csLanguage_Name == "VB 6.0" )
        {
            if ( csTerminalType == "3270" )
			{
				cagtest = new CAG_EAOAx_3270_VB6;
				m_buttonPromptForValues.EnableWindow(FALSE);
			}
            else if ( csTerminalType == "5250" )
			{
				cagtest = new CAG_EAOAx_5250_VB6;
				m_buttonPromptForValues.EnableWindow(FALSE);
			}
			else // VT
			{
				cagtest = new CAG_EAOAx_VT_VB6;
				m_buttonPromptForValues.EnableWindow(FALSE);
			}
        }
		else if ( csLanguage_Name == "VB.Net" )
        {
            if ( csTerminalType == "3270" )
			{
				cagtest = new CAG_EAOAx_3270_VBN;
				m_buttonPromptForValues.EnableWindow(FALSE);
			}
            else if ( csTerminalType == "5250" )
			{
				cagtest = new CAG_EAOAx_5250_VBN;
				m_buttonPromptForValues.EnableWindow(FALSE);
			}
			else	// VT
			{
				cagtest = new CAG_EAOAx_VT_VBN;
				m_buttonPromptForValues.EnableWindow(FALSE);
			}
        }
		else if ( csLanguage_Name == "VBScript HTML" )
		{
            if ( csTerminalType == "3270" )
			{
				cagtest = new CAG_EAOAx_3270_HTML_VBS;
				m_buttonPromptForValues.EnableWindow(FALSE);
			}
            else if ( csTerminalType == "5250" )
			{
				cagtest = new CAG_EAOAx_5250_HTML_VBS;
				m_buttonPromptForValues.EnableWindow(FALSE);
			}
			else	 //VT
			{
				cagtest = new CAG_EAOAx_VT_HTML_VBS;
				m_buttonPromptForValues.EnableWindow(FALSE);
			}
		}

		m_buttonPromptForValues.EnableWindow(FALSE);
		RunState.SendAction( EAOAx_NOW );
	}

	else if ( csAPI_Name == "EAO Java" )
	{
		if ( csTerminalType == "3270" )
		{
			cagtest = new CAG_EAOJ_3270_J;
		}
		else if ( csTerminalType == "5250" )
		{
			cagtest = new CAG_EAOJ_5250_J;
		}
		else	// VT
		{
			cagtest = new CAG_EAOJ_VT_J;
		}
		
		m_buttonPromptForValues.EnableWindow(TRUE);
		RunState.SendAction( EAOJ_NOW );

		if(m_bPromptForValues)
		{
			HideParameterControls();
			ShowEAOJControls(0);
		}
	}
	else if ( csAPI_Name == "EHLAPI32" )
	{
		if ( csLanguage_Name == "C++" )
		{
			cagtest = new CAG_EHL_CPP;
			m_buttonPromptForValues.EnableWindow(TRUE);
		}
		else if ( csLanguage_Name == "C#" )
		{
			cagtest = new CAG_EHL_CS;
			m_buttonPromptForValues.EnableWindow(TRUE);
		}
		else if ( csLanguage_Name == "VB 6.0" )
		{
			cagtest = new CAG_EHL_VB6;
			m_buttonPromptForValues.EnableWindow(TRUE);
		}
		else if ( csLanguage_Name == "VB.Net" )
		{
			cagtest = new CAG_EHL_VBN;
			m_buttonPromptForValues.EnableWindow(TRUE);
		}

		m_buttonPromptForValues.EnableWindow(TRUE);
		RunState.SendAction( EHL_NOW );

		if(m_bPromptForValues)
		{
			HideParameterControls();
			ShowEHLControls();
		}
	}
	else if ( csAPI_Name == "HLLAPI32" )
	{
		if ( csLanguage_Name == "C++" )
		{
			cagtest = new CAG_HLL_CPP;
		}
		else if ( csLanguage_Name == "C#" )
		{
			cagtest = new CAG_HLL_CS;
		}

		m_buttonPromptForValues.EnableWindow(FALSE);
		RunState.SendAction( HLL_NOW );
	}
	else if ( csAPI_Name == "IHLAPI32" )
	{
		if ( csLanguage_Name == "C++" )
		{
			cagtest = new CAG_IHL_CPP;
		}
		else if ( csLanguage_Name == "C#" )
		{
			cagtest = new CAG_IHL_CS;
		}
		else if ( csLanguage_Name == "VB 6.0" )
		{
			cagtest = new CAG_IHL_VB6;
		}
		else if ( csLanguage_Name == "VB.Net" )
		{
			cagtest = new CAG_IHL_VBN;
		}

		m_buttonPromptForValues.EnableWindow(TRUE);
		RunState.SendAction( IHL_NOW );

		if(m_bPromptForValues)
		{
			HideParameterControls();
			ShowEHLControls();
		}
	}

	else if ( csAPI_Name == "Verastream Host Integrator" )
	{
		if ( csLanguage_Name == "VB 6.0" )
		{
			cagtest = new CAG_VHI_VB6;
			m_buttonPromptForValues.EnableWindow(TRUE);
		}
		else if ( csLanguage_Name == "VB.Net" )

		{
			cagtest = new CAG_VHI_VBN;
			m_buttonPromptForValues.EnableWindow(TRUE);
		}
		else if ( csLanguage_Name == "C#" )
		{
			cagtest = new CAG_VHI_CS;
			m_buttonPromptForValues.EnableWindow(TRUE);
		}
		else if ( csLanguage_Name == "Windows Script" )
		{
			cagtest = new CAG_VHI_WS;
			m_buttonPromptForValues.EnableWindow(TRUE);
		}

		m_buttonPromptForValues.EnableWindow(TRUE);
		RunState.SendAction( VHI_NOW );

		if(m_bPromptForValues)
		{
			HideParameterControls();
		}

	}

	else if ( csAPI_Name == "Synapta" )
	{
		if ( csLanguage_Name == "Java" )
		{
			if ( csTerminalType == "ITask" || csTerminalType == "ScreenNativeAccess" )
			{
				cagtest = new CAG_ITASK_JAVA;
				m_buttonPromptForValues.EnableWindow(TRUE);
			}
			else if ( csTerminalType == "IConnectorAccess" )
			{
				cagtest = new CAG_ICONN_JAVA;
				m_buttonPromptForValues.EnableWindow(TRUE);
			}
			else
			{
				//todo cagtest = new CAG_ICONN_JAVA;
				m_buttonPromptForValues.EnableWindow(TRUE);
			}
		}
		else if	( csLanguage_Name == "ASP"  )
		{
			if ( csTerminalType == "IConnectorAccess" )
			{
				cagtest = new CAG_ICONN_ASP;
				m_buttonPromptForValues.EnableWindow(TRUE);
			}
			else	// catch any problems
			{
				cagtest = new CAG_ICONN_ASP;
				m_buttonPromptForValues.EnableWindow(TRUE);
			}
		}
		else if	( csLanguage_Name == "Windows Script"  )
		{
			if ( csTerminalType == "IConnectorAccess" )
			{
				cagtest = new CAG_ICONN_WS;
				m_buttonPromptForValues.EnableWindow(TRUE);
			}
			else	// catch any problems
			{
				cagtest = new CAG_ICONN_WS;
				m_buttonPromptForValues.EnableWindow(TRUE);
			}
		}
		else if ( csLanguage_Name == "C#" )
		{
			if ( csTerminalType == "IConnectorAccess" )
			{
				cagtest = new CAG_ICONN_CS;
				m_buttonPromptForValues.EnableWindow(TRUE);
			}
			else	// catch any problems
			{
				cagtest = new CAG_ICONN_CS;
				m_buttonPromptForValues.EnableWindow(TRUE);
			}
		}
		else if ( csLanguage_Name == "VB.Net" )
		{
			if ( csTerminalType == "IConnectorAccess" )
			{
				cagtest = new CAG_ICONN_VBN;
				m_buttonPromptForValues.EnableWindow(TRUE);
			}
			else	// catch any problems
			{
				cagtest = new CAG_ICONN_VBN;
				m_buttonPromptForValues.EnableWindow(TRUE);
			}
		}

	}
	else if ( csAPI_Name == "Extra! OLE Auto" )
	{
		if ( csLanguage_Name == "C++" )
		{
			if ( csTerminalType == "3270" )
			{
				cagtest = new CAG_EOLE_3270_CPP;
				m_buttonPromptForValues.EnableWindow(TRUE);
			}
			else if ( csTerminalType == "5250" )
			{
				cagtest = new CAG_EOLE_5250_CPP;
				m_buttonPromptForValues.EnableWindow(TRUE);
			}
			else
			{
				cagtest = new CAG_EOLE_VT_CPP;
				m_buttonPromptForValues.EnableWindow(TRUE);
			}
		}
		else if ( csLanguage_Name == "VB.Net" )
		{
			if ( csTerminalType == "3270" )
			{
				cagtest = new CAG_EOLE_3270_VBN;
				m_buttonPromptForValues.EnableWindow(TRUE);
			}
			else if ( csTerminalType == "5250" )
			{
				cagtest = new CAG_EOLE_5250_VBN;
				m_buttonPromptForValues.EnableWindow(TRUE);
			}
			else
			{
				cagtest = new CAG_EOLE_VT_VBN;
				m_buttonPromptForValues.EnableWindow(TRUE);
			}
		}
		else if ( csLanguage_Name == "VB 6.0" )
		{
			if ( csTerminalType == "3270" )
			{
				cagtest = new CAG_EOLE_3270_VB6;
				m_buttonPromptForValues.EnableWindow(TRUE);
			}
			else if ( csTerminalType == "5250" )
			{
				cagtest = new CAG_EOLE_5250_VB6;
				m_buttonPromptForValues.EnableWindow(TRUE);
			}
			else
			{
				cagtest = new CAG_EOLE_VT_VB6;
				m_buttonPromptForValues.EnableWindow(TRUE);
			}
		}
		else if ( csLanguage_Name == "JavaScript Node" )
		{
			if ( csTerminalType == "3270" )
			{
				cagtest = new CAG_EOLE_3270_NODE_JS;
				m_buttonPromptForValues.EnableWindow(TRUE);
			}
			else if ( csTerminalType == "5250" )
			{
				cagtest = new CAG_EOLE_3270_NODE_JS;
				m_buttonPromptForValues.EnableWindow(TRUE);
			}
			else
			{
				cagtest = new CAG_EOLE_3270_NODE_JS;
				m_buttonPromptForValues.EnableWindow(TRUE);
			}

		}
		else if ( csLanguage_Name == "VBScript Node" )
		{
			if ( csTerminalType == "3270" )
			{
				cagtest = new CAG_EOLE_3270_NODE_VBS;
				m_buttonPromptForValues.EnableWindow(TRUE);
			}
			else if ( csTerminalType == "5250" )
			{
				cagtest = new CAG_EOLE_5250_NODE_VBS;
				m_buttonPromptForValues.EnableWindow(TRUE);
			}
			else
			{
				cagtest = new CAG_EOLE_VT_NODE_VBS;
				m_buttonPromptForValues.EnableWindow(TRUE);
			}

		}
		else if ( csLanguage_Name == "Excel VBA Macro" )
		{
			if ( csTerminalType == "3270" )
			{
				cagtest = new CAG_EOLE_3270_XLS;
				m_buttonPromptForValues.EnableWindow(TRUE);
			}
			else if ( csTerminalType == "5250" )
			{
				cagtest = new CAG_EOLE_5250_XLS;
				m_buttonPromptForValues.EnableWindow(TRUE);
			}
			else
			{
				cagtest = new CAG_EOLE_VT_XLS;
				m_buttonPromptForValues.EnableWindow(TRUE);
			}
		}
		else if ( csLanguage_Name == "C#" )
		{
			if ( csTerminalType == "3270" )
			{
				cagtest = new CAG_EOLE_3270_CS;
				m_buttonPromptForValues.EnableWindow(TRUE);
			}
			else if ( csTerminalType == "5250" )
			{
				cagtest = new CAG_EOLE_5250_CS;
				m_buttonPromptForValues.EnableWindow(TRUE);
			}
			else
			{
				cagtest = new CAG_EOLE_VT_CS;
				m_buttonPromptForValues.EnableWindow(TRUE);
			}
		}
		else if ( csLanguage_Name == "EB Macro" )
		{
			if ( csTerminalType == "3270" )
			{
				cagtest = new CAG_EOLE_3270_EBM;
				m_buttonPromptForValues.EnableWindow(TRUE);
			}
			else if ( csTerminalType == "5250" )
			{
				cagtest = new CAG_EOLE_5250_EBM;
				m_buttonPromptForValues.EnableWindow(TRUE);
			}
			else
			{
				cagtest = new CAG_EOLE_VT_EBM;
				m_buttonPromptForValues.EnableWindow(TRUE);
			}
		}
		else if ( csLanguage_Name == "EB Macro Test" )
		{
			if ( csTerminalType == "3270" )
			{
				cagtest = new CAG_EOLE_3270_EBM_TEST;
				m_buttonPromptForValues.EnableWindow(TRUE);
			}
			else if ( csTerminalType == "5250" )
			{
				cagtest = new CAG_EOLE_5250_EBM_TEST;
				m_buttonPromptForValues.EnableWindow(TRUE);
			}
			else
			{
				cagtest = new CAG_EOLE_VT_EBM_TEST;
				m_buttonPromptForValues.EnableWindow(TRUE);
			}
		}
		else if ( csLanguage_Name == "Windows Script" )
		{
			if ( csTerminalType == "3270" )
			{
				cagtest = new CAG_EOLE_3270_WS;
				m_buttonPromptForValues.EnableWindow(TRUE);
			}
			else if ( csTerminalType == "5250" )
			{
				cagtest = new CAG_EOLE_5250_WS;
				m_buttonPromptForValues.EnableWindow(TRUE);
			}
			else
			{
				cagtest = new CAG_EOLE_VT_WS;
				m_buttonPromptForValues.EnableWindow(TRUE);
			}
		}
		else if ( csLanguage_Name == "ASP" )
		{
			if ( csTerminalType == "3270" )
			{
				cagtest = new CAG_EOLE_3270_ASP;
				m_buttonPromptForValues.EnableWindow(TRUE);
			}
			else if ( csTerminalType == "5250" )
			{
				cagtest = new CAG_EOLE_5250_ASP;
				m_buttonPromptForValues.EnableWindow(TRUE);
			}
			else
			{
				cagtest = new CAG_EOLE_VT_ASP;
				m_buttonPromptForValues.EnableWindow(TRUE);
			}
		}

		m_buttonPromptForValues.EnableWindow(TRUE);
		RunState.SendAction( EOLE_NOW );

		if(m_bPromptForValues)
		{
			HideParameterControls();
			//ShowEOLEControls(0);
		}

	}
	else if ( csAPI_Name == "PCSHLL32" )
	{
		if ( csLanguage_Name == "C++" )
		{
			cagtest = new CAG_PCS_CPP;
			m_buttonPromptForValues.EnableWindow(TRUE);
		}
		else if ( csLanguage_Name == "C#" )
		{
			cagtest = new CAG_PCS_CS;
			m_buttonPromptForValues.EnableWindow(TRUE);
		}
		else if ( csLanguage_Name == "VB 6.0" )
		{
			cagtest = new CAG_PCS_VB6;
			m_buttonPromptForValues.EnableWindow(TRUE);
		}
		else if ( csLanguage_Name == "VB.Net" )
		{
			cagtest = new CAG_PCS_VBN;
			m_buttonPromptForValues.EnableWindow(TRUE);
		}

		m_buttonPromptForValues.EnableWindow(TRUE);
		RunState.SendAction( PCS_NOW );

		if(m_bPromptForValues)
		{
			HideParameterControls();
			ShowEHLControls();
		}
	}
	else if ( csAPI_Name == "Perforce" )
	{
		cagtest = new CAG_PERFORCE;
		m_buttonPromptForValues.EnableWindow(TRUE);
	}
	else if ( csAPI_Name == "PB QACom" )
	{
		cagtest = new CAG_PB_QAC_J;
		
		m_buttonPromptForValues.EnableWindow(FALSE);
		RunState.SendAction( QAC_NOW );
	}


	else if ( csAPI_Name == "Reflection FTP" )
	{
		if ( csLanguage_Name == "C++" )
		{
			cagtest = new CAG_RFTP_CPP;
		}
		else if ( csLanguage_Name == "C#" )
		{
			cagtest = new CAG_RFTP_CS;
		}
		else if ( csLanguage_Name == "VB 6.0" )
		{
			cagtest = new CAG_RFTP_VB6;
		}
		else if ( csLanguage_Name == "VB.Net" )
		{
			cagtest = new CAG_RFTP_VBN;
		}
		
		m_buttonPromptForValues.EnableWindow(FALSE);
		RunState.SendAction( RFTP_NOW );
	}

	else if ( csAPI_Name == "Reflection for Web" )
	{
		if ( csLanguage_Name == "Java" )
		{
			if ( csTerminalType == "3270" )
			{
				cagtest = new CAG_RWEB_3270_JAVA;
				m_buttonPromptForValues.EnableWindow(TRUE);
			}
			else if ( csTerminalType == "5250" )
			{
				cagtest = new CAG_RWEB_5250_JAVA;
				m_buttonPromptForValues.EnableWindow(TRUE);
			}
			else if ( csTerminalType == "HP" )
			{
				cagtest = new CAG_RWEB_HP_JAVA;
				m_buttonPromptForValues.EnableWindow(TRUE);
			}
			else // VT
			{
				cagtest = new CAG_RWEB_VT_JAVA;
				m_buttonPromptForValues.EnableWindow(TRUE);
			}
		}
		else if ( csLanguage_Name == "JavaScript" )
		{
			if ( csTerminalType == "3270" )
			{
				cagtest = new CAG_RWEB_3270_JS;
				m_buttonPromptForValues.EnableWindow(TRUE);
			}
			else if ( csTerminalType == "5250" )
			{
				cagtest = new CAG_RWEB_5250_JS;
				m_buttonPromptForValues.EnableWindow(TRUE);
			}
			else if ( csTerminalType == "HP" )
			{
				cagtest = new CAG_RWEB_HP_JS;
				m_buttonPromptForValues.EnableWindow(TRUE);
			}
			else // VT
			{
				cagtest = new CAG_RWEB_VT_JS;
				m_buttonPromptForValues.EnableWindow(TRUE);
			}
		}
		else if ( csLanguage_Name == "VBScript" )
		{
			if ( csTerminalType == "3270" )
			{
				cagtest = new CAG_RWEB_3270_VBS;
				m_buttonPromptForValues.EnableWindow(TRUE);
			}
			else if ( csTerminalType == "5250" )
			{
				cagtest = new CAG_RWEB_5250_VBS;
				m_buttonPromptForValues.EnableWindow(TRUE);
			}
			else if ( csTerminalType == "HP" )
			{
				cagtest = new CAG_RWEB_HP_VBS;
				m_buttonPromptForValues.EnableWindow(TRUE);
			}
			else // VT
			{
				cagtest = new CAG_RWEB_VT_VBS;
				m_buttonPromptForValues.EnableWindow(TRUE);
			}
		}
		
		RunState.SendAction( RFTP_NOW );
	}

	else if ( csAPI_Name == "Reflection OLE Auto" )
	{
		if ( csLanguage_Name == "C++" )
		{
			if ( csTerminalType == "3270" )
			{
				cagtest = new CAG_ROLE_3270_CPP;
				m_buttonPromptForValues.EnableWindow(TRUE);
			}
			else if ( csTerminalType == "5250" )
			{
				cagtest = new CAG_ROLE_5250_CPP;
				m_buttonPromptForValues.EnableWindow(TRUE);
			}
			else if ( csTerminalType == "VT" )
			{
				cagtest = new CAG_ROLE_VT_CPP;
				m_buttonPromptForValues.EnableWindow(TRUE);
			}
			else
			{
				cagtest = new CAG_ROLE_HP_CPP;
				m_buttonPromptForValues.EnableWindow(TRUE);
			}
		}
		else if ( csLanguage_Name == "VB.Net" )
		{
			if ( csTerminalType == "3270" )
			{
				cagtest = new CAG_ROLE_3270_VBN;
				m_buttonPromptForValues.EnableWindow(TRUE);
			}
			else if ( csTerminalType == "5250" )
			{
				cagtest = new CAG_ROLE_5250_VBN;
				m_buttonPromptForValues.EnableWindow(TRUE);
			}
			else if ( csTerminalType == "VT" )
			{
				cagtest = new CAG_ROLE_VT_VBN;
				m_buttonPromptForValues.EnableWindow(TRUE);
			}
			else
			{
				cagtest = new CAG_ROLE_HP_VBN;
				m_buttonPromptForValues.EnableWindow(TRUE);
			}

		}
		else if ( csLanguage_Name == "VB 6.0" )
		{
			if ( csTerminalType == "3270" )
			{
				cagtest = new CAG_ROLE_3270_VB6;
				m_buttonPromptForValues.EnableWindow(TRUE);
			}
			else if ( csTerminalType == "5250" )
			{
				cagtest = new CAG_ROLE_5250_VB6;
				m_buttonPromptForValues.EnableWindow(TRUE);
			}
			else if ( csTerminalType == "VT" )
			{
				cagtest = new CAG_ROLE_VT_VB6;
				m_buttonPromptForValues.EnableWindow(TRUE);
			}
			else
			{
				cagtest = new CAG_ROLE_HP_VB6;
				m_buttonPromptForValues.EnableWindow(TRUE);
			}

		}
		else if ( csLanguage_Name == "Excel VBA Macro" )
		{
			if ( csTerminalType == "3270" )
			{
				cagtest = new CAG_ROLE_3270_XLS;
				m_buttonPromptForValues.EnableWindow(TRUE);
			}
			else if ( csTerminalType == "5250" )
			{
				cagtest = new CAG_ROLE_5250_XLS;
				m_buttonPromptForValues.EnableWindow(TRUE);
			}
			else if ( csTerminalType == "VT" )
			{
				cagtest = new CAG_ROLE_VT_XLS;
				m_buttonPromptForValues.EnableWindow(TRUE);
			}
			else
			{
				cagtest = new CAG_ROLE_HP_XLS;
				m_buttonPromptForValues.EnableWindow(TRUE);
			}

		}
		else if ( csLanguage_Name == "C#" )
		{
			if ( csTerminalType == "3270" )
			{
				cagtest = new CAG_ROLE_3270_CS;
				m_buttonPromptForValues.EnableWindow(TRUE);
			}
			else if ( csTerminalType == "5250" )
			{
				cagtest = new CAG_ROLE_5250_CS;
				m_buttonPromptForValues.EnableWindow(TRUE);
			}
			else if ( csTerminalType == "VT" )
			{
				cagtest = new CAG_ROLE_VT_CS;
				m_buttonPromptForValues.EnableWindow(TRUE);
			}
			else
			{
				cagtest = new CAG_ROLE_HP_CS;
				m_buttonPromptForValues.EnableWindow(TRUE);
			}

		}
		else if ( csLanguage_Name == "Windows Script" )
		{
			if ( csTerminalType == "3270" )
			{
				cagtest = new CAG_ROLE_3270_WS;
				m_buttonPromptForValues.EnableWindow(TRUE);
			}
			else if ( csTerminalType == "5250" )
			{
				cagtest = new CAG_ROLE_5250_WS;
				m_buttonPromptForValues.EnableWindow(TRUE);
			}
			else if ( csTerminalType == "VT" )
			{
				cagtest = new CAG_ROLE_VT_WS;
				m_buttonPromptForValues.EnableWindow(TRUE);
			}
			else
			{
				cagtest = new CAG_ROLE_HP_WS;
				m_buttonPromptForValues.EnableWindow(TRUE);
			}

		}
		else if ( csLanguage_Name == "ASP" )
		{
			if ( csTerminalType == "3270" )
			{
				cagtest = new CAG_ROLE_3270_ASP;
				m_buttonPromptForValues.EnableWindow(TRUE);
			}
			else if ( csTerminalType == "5250" )
			{
				cagtest = new CAG_ROLE_5250_ASP;
				m_buttonPromptForValues.EnableWindow(TRUE);
			}
			else if ( csTerminalType == "VT" )
			{
				cagtest = new CAG_ROLE_VT_ASP;
				m_buttonPromptForValues.EnableWindow(TRUE);
			}
			else
			{
				cagtest = new CAG_ROLE_HP_ASP;
				m_buttonPromptForValues.EnableWindow(TRUE);
			}

		}

		m_buttonPromptForValues.EnableWindow(FALSE);
		RunState.SendAction( ROLE_NOW );
	}

	else if ( csAPI_Name == "UNIX shell" )
	{
		cagtest = new CAG_UNIX;
		m_buttonPromptForValues.EnableWindow(TRUE);
	}


	else if ( csAPI_Name == "WHLAPI32" )
	{
        if ( csLanguage_Name == "C++" )
        {
		    cagtest = new CAG_WHL_CPP;
        }
		else if ( csLanguage_Name == "C#" )
        {
            cagtest = new CAG_WHL_CS;
        }
		else if ( csLanguage_Name == "Visual Basic .Net" )
        {
            cagtest = new CAG_WHL_VBN;
        }

		else
        {
            cagtest = new CAG_WHL_VB6;
        }

		m_buttonPromptForValues.EnableWindow(TRUE);
		RunState.SendAction( WHL_NOW );

		if(m_bPromptForValues)
		{
			HideParameterControls();
			ShowEHLControls();
		}

	}

	cagtest->loadFunctionList( &m_listTranslateFunction );

	OnChangeFunctionChoice();	//donc090905 inserted because it seems like a good idea

	SetUI();


}


/****************************************************************************DC
	Function	:	CAPIGenDlg::OnChangeArgument1()

	Purpose		:	Keeps an eye on the string entered as a function parameter
					and updates the size control's value to match any change
					in the string control.

*****************************************************************************/
void CAPIGenDlg::OnChangeArgument1()
{
	UpdateData();
	char buffer[20];
	itoa(m_csEditArgument1.GetLength(), buffer, 10 );
	SetDlgItemText(IDEDIT_ARGUMENT2, buffer);

	UpdateData();
}


