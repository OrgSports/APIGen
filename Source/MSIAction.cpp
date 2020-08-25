// MSIAction.cpp : implementation file
//

#include "stdafx.h"
#include "APIGen.h"
#include "MSIAction.h"


// CMSIActionDlg dialog

IMPLEMENT_DYNAMIC(CMSIActionDlg, CDialog)
CMSIActionDlg::CMSIActionDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMSIActionDlg::IDD, pParent)
	, csCustomActionClassName(_T(""))
	, csCustomActionFunctionName(_T(""))
{
}

CMSIActionDlg::~CMSIActionDlg()
{
}

void CMSIActionDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDEDIT_CUSTOMACTION_CLASS, csCustomActionClassName);
	DDX_Text(pDX, IDEDIT_CUSTOMACTION_FUNCNAME, csCustomActionFunctionName);
	DDX_Control(pDX, IDEDIT_CUSTOMACTION_CLASS, ebCustomActionClass);
	DDX_Control(pDX, IDEDIT_CUSTOMACTION_FUNCNAME, ebCustomActionFunction);
}


BEGIN_MESSAGE_MAP(CMSIActionDlg, CDialog)
END_MESSAGE_MAP()


// CMSIActionDlg message handlers
BOOL CMSIActionDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	ebCustomActionClass.SetWindowText("APIGAction");
	ebCustomActionClass.SetFocus();

	ebCustomActionFunction.SetWindowText("APIGFunction");
	ebCustomActionFunction.SetFocus();

	return TRUE;  // return TRUE  unless you set the focus to a control
}


void CMSIActionDlg::OnOK() 
{
	CDialog::OnOK();
}
