#pragma once
#include "afxwin.h"


// CMSIActionDlg dialog

class CMSIActionDlg : public CDialog
{
	DECLARE_DYNAMIC(CMSIActionDlg)

public:
	CMSIActionDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~CMSIActionDlg();

// Dialog Data
	enum { IDD = IDD_CUSTOM_ACTIONS };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()

protected:
	// Generated message map functions
	//{{AFX_MSG(CMSIActionDlg)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	//}}AFX_MSG

public:
	CString csCustomActionClassName;
	CString csCustomActionFunctionName;
	CEdit ebCustomActionClass;
	CEdit ebCustomActionFunction;
};
