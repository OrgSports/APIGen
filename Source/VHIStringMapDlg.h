#pragma once
#include "afxwin.h"
#include "afxcmn.h"


// CVHIStringMapDlg dialog

class CVHIStringMapDlg : public CDialog
{
	DECLARE_DYNAMIC(CVHIStringMapDlg)

public:
	CVHIStringMapDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~CVHIStringMapDlg();

// Dialog Data
	enum { IDD = IDD_VHI_NEWSTRINGMAP };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CButton chkNewStringMap;
	CEdit editVHIName;
	CString csEditVHIName;
	CEdit editVHIValue;
	CString csEditVHIValue;
	CListCtrl lcVHINameValueList;
	CStringArray csaNameValuePairs;

protected:
	// Generated message map functions
	//{{AFX_MSG(CAPIGenDlg)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	//}}AFX_MSG

public:
	afx_msg void AddNameValuePair();
	afx_msg void RemoveNameValuePair();

private:
	static int m_currRow;
	static int m_currCol;

};
