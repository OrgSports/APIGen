#pragma once
#include "afxwin.h"


// AIRVMUTS dialog

class AIRVMUTS : public CDialog
{
	DECLARE_DYNAMIC(AIRVMUTS)

public:
	AIRVMUTS(CWnd* pParent = NULL);   // standard constructor
	virtual ~AIRVMUTS();

// Dialog Data
	enum { IDD = IDD_AIRVM_UTS };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CString csEditUTSHostAddress;
	CString csEditUTSEnvironmentName;
	CString csEditUTSTransport;

protected:
	// Generated message map functions
	//{{AFX_MSG(CAPIGenDlg)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	//}}AFX_MSG

public:
	CEdit cEditUTSHostAddress;
	CEdit cEditUTSEnvironmentName;
	CEdit cEditUTSTransport;
};
