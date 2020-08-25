#pragma once
#include "afxwin.h"


// CAIRVM3270 dialog

class CAIRVM3270 : public CDialog
{
	DECLARE_DYNAMIC(CAIRVM3270)

public:
	CAIRVM3270(CWnd* pParent = NULL);   // standard constructor
	virtual ~CAIRVM3270();

// Dialog Data
	enum { IDD = IDD_AIRVM_3270 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CString csEdit3270HostAddress;
	CEdit cEdit3270HostAddress;

protected:
	// Generated message map functions
	//{{AFX_MSG(CAPIGenDlg)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	//}}AFX_MSG

};
