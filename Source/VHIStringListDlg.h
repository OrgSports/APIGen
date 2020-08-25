#pragma once
#include "afxwin.h"
#include "afxcmn.h"


// CVHIStringListDlg dialog

class CVHIStringListDlg : public CDialog
{
	DECLARE_DYNAMIC(CVHIStringListDlg)

public:
	CVHIStringListDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~CVHIStringListDlg();

// Dialog Data
	enum { IDD = IDD_VHI_NEWSTRINGLIST };

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
	CButton chkNewStringList;
	CEdit editVHINewString;
	CString csEditVHINewString;
	CListCtrl lcVHINewStringList;
	CStringArray csaNewStringList;

public:
	afx_msg void AddNewString();
	afx_msg void RemoveString();

private:
	static int m_currRow;
	static int m_currCol;

};
