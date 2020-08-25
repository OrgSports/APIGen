#pragma once
#include "afxwin.h"

// CDeployParams dialog

class CDeployParams : public CDHtmlDialog
{
	DECLARE_DYNCREATE(CDeployParams)

public:
	CDeployParams(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDeployParams();
// Overrides
	HRESULT OnButtonOK(IHTMLElement *pElement);
	HRESULT OnButtonCancel(IHTMLElement *pElement);

// Dialog Data
	enum { IDD = IDD_DEPLOY_PARAMS, IDH = IDR_HTML_DEPLOYPARAMS };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnInitDialog();

	DECLARE_MESSAGE_MAP()
	DECLARE_DHTML_EVENT_MAP()
public:
	// the URL where the presentation is located on the MCS Server
	CString csEditDeployURL;
	CString csEditDeployUsername;
	CString csEditDeployPassword;
	CString csEditDeployLanguageCode;
	CString csEditDeployChannel;
	CString csEditDeployPresentationID;
	CString csEditDeployPresentationMode;
	CListBox listDeployLanguage;
};
#pragma once

