#pragma once
#include "afxwin.h"


// CXMLVT dialog

class CXMLVT : public CDialog
{
	DECLARE_DYNAMIC(CXMLVT)

public:
	CXMLVT(CWnd* pParent = NULL);   // standard constructor
	virtual ~CXMLVT();

// Dialog Data
	enum { IDD = IDD_XML_VT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CEdit cEditVTHostName;
	CString csEditVTHostName;
	CEdit cEditVTPortNumber;
	CString csEditVTPortNumber;
	CEdit cEditVTTabColumns;
	CString csEditVTTabColumns;
	CButton bCheckVTLocalMode;
	CButton bCheckVTInitiateNegotiation;
	CButton bCheckVTNegotiateBinary;
	CButton bCheckVTAutoWrap;

protected:
	// Generated message map functions
	//{{AFX_MSG(CAPIGenDlg)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	//}}AFX_MSG


};
