#pragma once
#include "afxwin.h"


// CAIRVMT27 dialog

class CAIRVMT27 : public CDialog
{
	DECLARE_DYNAMIC(CAIRVMT27)

public:
	CAIRVMT27(CWnd* pParent = NULL);   // standard constructor
	virtual ~CAIRVMT27();

// Dialog Data
	enum { IDD = IDD_AIRVM_T27 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()

protected:
	// Generated message map functions
	//{{AFX_MSG(CAPIGenDlg)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	//}}AFX_MSG

public:
	CString csEditT27HostAddress;
	CEdit cEditT27HostAddress;
	CEdit cEditT27StationID;
	CString csEditT27StationID;
};
