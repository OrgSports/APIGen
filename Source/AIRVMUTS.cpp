// AIRVMUTS.cpp : implementation file
//

#include "stdafx.h"
#include "APIGen.h"
#include "AIRVMUTS.h"


// AIRVMUTS dialog

IMPLEMENT_DYNAMIC(AIRVMUTS, CDialog)
AIRVMUTS::AIRVMUTS(CWnd* pParent /*=NULL*/)
	: CDialog(AIRVMUTS::IDD, pParent)
	, csEditUTSHostAddress(_T(""))
	, csEditUTSEnvironmentName(_T(""))
	, csEditUTSTransport(_T(""))
{
}

AIRVMUTS::~AIRVMUTS()
{
}

void AIRVMUTS::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDEDIT_AIRVMUTS_HOSTADDR, csEditUTSHostAddress);
	DDX_Text(pDX, IDEDIT_AIRVMUTS_ENVNAME, csEditUTSEnvironmentName);
	DDX_Text(pDX, IDEDIT_AIRVMUTS_TRANSPORT, csEditUTSTransport);
	DDX_Control(pDX, IDEDIT_AIRVMUTS_HOSTADDR, cEditUTSHostAddress);
	DDX_Control(pDX, IDEDIT_AIRVMUTS_ENVNAME, cEditUTSEnvironmentName);
	DDX_Control(pDX, IDEDIT_AIRVMUTS_TRANSPORT, cEditUTSTransport);
}


BEGIN_MESSAGE_MAP(AIRVMUTS, CDialog)
END_MESSAGE_MAP()


// AIRVMUTS message handlers
BOOL AIRVMUTS::OnInitDialog()
{
	CDialog::OnInitDialog();

	cEditUTSHostAddress.SetWindowText("T319");
	cEditUTSEnvironmentName.SetWindowText("UDSSRC");
	cEditUTSTransport.SetWindowText("INT1");

	cEditUTSHostAddress.SetFocus();

	return TRUE;  // return TRUE  unless you set the focus to a control
}


// AIRVMUTS message handlers
void AIRVMUTS::OnOK() 
{
	CDialog::OnOK();
}
