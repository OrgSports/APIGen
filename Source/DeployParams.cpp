// DeployParams.cpp : implementation file
//

#include "stdafx.h"
#include "APIGen.h"
#include "DeployParams.h"


// CDeployParams dialog

IMPLEMENT_DYNCREATE(CDeployParams, CDHtmlDialog)

CDeployParams::CDeployParams(CWnd* pParent /*=NULL*/)
	: CDHtmlDialog(CDeployParams::IDD, CDeployParams::IDH, pParent)
	, csEditDeployURL(_T(""))
	, csEditDeployUsername(_T(""))
	, csEditDeployPassword(_T(""))
	, csEditDeployLanguageCode(_T(""))
	, csEditDeployChannel(_T(""))
	, csEditDeployPresentationID(_T(""))
	, csEditDeployPresentationMode(_T(""))
{
}

CDeployParams::~CDeployParams()
{
}

void CDeployParams::DoDataExchange(CDataExchange* pDX)
{
	CDHtmlDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDEDIT_DEPLOY_URL, csEditDeployURL);
	DDX_Text(pDX, IDEDIT_DEPLOY_USERNAME, csEditDeployUsername);
	DDX_Text(pDX, IDEDIT_DEPLOY_PASSWORD, csEditDeployPassword);
	DDX_LBString(pDX, IDLIST_DEPLOY_LANGUAGE, csEditDeployLanguageCode);
	DDX_Text(pDX, IDEDIT_DEPLOY_CHANNEL, csEditDeployChannel);
	DDX_Text(pDX, IDEDIT_DEPLOY_PRESENTATION_ID, csEditDeployPresentationID);
	DDX_Text(pDX, IDEDIT_DEPLOY_APPLICATION_MODE, csEditDeployPresentationMode);
	DDX_Control(pDX, IDLIST_DEPLOY_LANGUAGE, listDeployLanguage);
}

BOOL CDeployParams::OnInitDialog()
{
	CDHtmlDialog::OnInitDialog();

	int nPos = 0;

	listDeployLanguage.ResetContent();
	listDeployLanguage.InsertString( nPos++, "de" );
	listDeployLanguage.InsertString( nPos++, "en" );
	listDeployLanguage.InsertString( nPos++, "es" );
	listDeployLanguage.InsertString( nPos++, "fr" );
	listDeployLanguage.InsertString( nPos++, "gr" );
	listDeployLanguage.SetCurSel(1);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

BEGIN_MESSAGE_MAP(CDeployParams, CDHtmlDialog)
END_MESSAGE_MAP()

BEGIN_DHTML_EVENT_MAP(CDeployParams)
	DHTML_EVENT_ONCLICK(_T("ButtonOK"), OnButtonOK)
	DHTML_EVENT_ONCLICK(_T("ButtonCancel"), OnButtonCancel)
END_DHTML_EVENT_MAP()



// CDeployParams message handlers

HRESULT CDeployParams::OnButtonOK(IHTMLElement* /*pElement*/)
{
	OnOK();
	return S_OK;  // return TRUE  unless you set the focus to a control
}

HRESULT CDeployParams::OnButtonCancel(IHTMLElement* /*pElement*/)
{
	OnCancel();
	return S_OK;  // return TRUE  unless you set the focus to a control
}


