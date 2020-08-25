#pragma once
#include "afxwin.h"


// CXML3270 dialog

class CXML3270 : public CDialog
{
	DECLARE_DYNAMIC(CXML3270)

public:
	CXML3270(CWnd* pParent = NULL);   // standard constructor
	virtual ~CXML3270();

// Dialog Data
	enum { IDD = IDD_XML_3270 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CEdit cEdit3270HostName;
	CString csEdit3270HostName;
	CEdit cEdit3270PortNumber;
	CString csEdit3270PortNumber;
	CListBox cList3270CharCase;
	BOOL bCheck3270LightPen;
	CListBox cList3270BackSpace;
	CEdit cEdit3270XLateFileName;
	CString csEdit3270XLateFileName;

	CString csList3270BackSpace;
	CString csList3270CharCase;

protected:
	// Generated message map functions
	//{{AFX_MSG(CAPIGenDlg)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	//}}AFX_MSG

};
