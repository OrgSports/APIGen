#pragma once
#include "afxwin.h"


// CWIXDialog dialog

class CWIXDialog : public CDialog
{
	DECLARE_DYNAMIC(CWIXDialog)

public:
	CWIXDialog(CWnd* pParent = NULL);   // standard constructor
	virtual ~CWIXDialog();

// Dialog Data
	enum { IDD = IDDLG_WIX_DLG };

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
	CString csBitmapID;
	CString csBitmapPath;
	CString csDialogIDName;
	CString csDialogTitle;
	afx_msg void BrowseWixBmp();
	CEdit cEdit_WIX_BMP;
};
