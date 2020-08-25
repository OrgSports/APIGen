// AIRVM3270.cpp : implementation file
//

#include "stdafx.h"
#include "APIGen.h"
#include "AIRVM3270.h"


// CAIRVM3270 dialog

IMPLEMENT_DYNAMIC(CAIRVM3270, CDialog)
CAIRVM3270::CAIRVM3270(CWnd* pParent /*=NULL*/)
	: CDialog(CAIRVM3270::IDD, pParent)
	, csEdit3270HostAddress(_T(""))
{
}

CAIRVM3270::~CAIRVM3270()
{
}

void CAIRVM3270::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDEDIT_AIRVM3270_HOSTADDR, csEdit3270HostAddress);
	DDX_Control(pDX, IDEDIT_AIRVM3270_HOSTADDR, cEdit3270HostAddress);
}


BEGIN_MESSAGE_MAP(CAIRVM3270, CDialog)
END_MESSAGE_MAP()


// CAIRVM3270 message handlers
BOOL CAIRVM3270::OnInitDialog()
{
	CDialog::OnInitDialog();

	cEdit3270HostAddress.SetWindowText("es9000.attachmate.com");
	cEdit3270HostAddress.SetFocus();

	return TRUE;  // return TRUE  unless you set the focus to a control
}


// CAIRVM3270 message handlers
void CAIRVM3270::OnOK() 
{
	CDialog::OnOK();
}
