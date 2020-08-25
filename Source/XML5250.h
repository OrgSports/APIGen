#pragma once
#include "afxwin.h"


// CXML5250 dialog

class CXML5250 : public CDialog
{
	DECLARE_DYNAMIC(CXML5250)

public:
	CXML5250(CWnd* pParent = NULL);   // standard constructor
	virtual ~CXML5250();

// Dialog Data
	enum { IDD = IDD_XML_5250 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CEdit cEdit5250HostName;
	CString csEdit5250HostName;
	CEdit cEdit5250PortNumber;
	CString csEdit5250PortNumber;
	CListBox cList5250CharCase;
	CString csList5250CharCase;
	CListBox cList5250AttributeChoice;
	CString csList5250AttributeChoice;
	BOOL bCheck5250NumericFieldOverride;
	BOOL bCheck5250DestructiveBackspace;

	CEdit cEdit5250XLateFileName;
	CString csEdit5250XLateFileName;

protected:
	// Generated message map functions
	//{{AFX_MSG(CAPIGenDlg)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	//}}AFX_MSG

public:
	CButton cbDestructiveBackspace;
};
