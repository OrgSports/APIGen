// AIRVMT27.cpp : implementation file
//

#include "stdafx.h"
#include "APIGen.h"
#include "AIRVMT27.h"


// CAIRVMT27 dialog

IMPLEMENT_DYNAMIC(CAIRVMT27, CDialog)
CAIRVMT27::CAIRVMT27(CWnd* pParent /*=NULL*/)
	: CDialog(CAIRVMT27::IDD, pParent)
	, csEditT27HostAddress(_T(""))
	, csEditT27StationID(_T(""))
{
}

CAIRVMT27::~CAIRVMT27()
{
}

void CAIRVMT27::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDEDIT_AIRVMT27_HOSTADDR, csEditT27HostAddress);
	DDX_Control(pDX, IDEDIT_AIRVMT27_HOSTADDR, cEditT27HostAddress);
	DDX_Control(pDX, IDEDIT_AIRVMT27_STATIONID, cEditT27StationID);
	DDX_Text(pDX, IDEDIT_AIRVMT27_STATIONID, csEditT27StationID);
}


BEGIN_MESSAGE_MAP(CAIRVMT27, CDialog)
END_MESSAGE_MAP()


// CAIRVMT27 message handlers
BOOL CAIRVMT27::OnInitDialog()
{
	CDialog::OnInitDialog();

	cEditT27HostAddress.SetWindowText("unisyslxa.attachmate.com");
	cEditT27StationID.SetWindowText("WLS_Chicago");
	cEditT27HostAddress.SetFocus();

	return TRUE;  // return TRUE  unless you set the focus to a control
}


// CAIRVMT27 message handlers
void CAIRVMT27::OnOK() 
{
	CDialog::OnOK();
}
