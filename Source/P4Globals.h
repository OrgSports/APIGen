#pragma once
#include "afxwin.h"


// CP4Globals dialog

class CP4Globals : public CDialog
{
	DECLARE_DYNAMIC(CP4Globals)

public:
	CP4Globals(CWnd* pParent = NULL);   // standard constructor
	virtual ~CP4Globals();

// Dialog Data
	enum { IDD = IDD_PERFORCE_GLOBALS };

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
	CButton cbClientName;
	CButton cbWorkingDir;
	CButton cbFormatOutput;
	CButton cbHostName;
	CButton cbPort;
	CButton cbPassword;
	CButton cbPrependLines;
	CButton cbUserName;
	CButton cbInputFile;
	CButton cbCharSet;
	CButton cbP4Version;
	CButton cbDisplayHelpInfo;
	CString csClientName;
	CString csWorkingDir;
	CString csHostName;
	CString csPortNumber;
	CString csPassword;
	CString csUserName;
	CString csFileName;
	CString csCharSet;
	BOOL bClientName;
	BOOL bWorkingDir;
	BOOL bFormatOutput;
	BOOL bHostName;
	BOOL bPort;
	BOOL bPassword;
	BOOL bPrependLines;
	BOOL bUserName;
	BOOL bInputFile;
	BOOL bCharSet;
	BOOL bP4Version;
	BOOL bDisplayHelpInfo;
};
