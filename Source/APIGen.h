// APIGen.h : main header file for the APIGEN application
//

#if !defined(AFX_APIGEN_H__733FC092_D773_49F6_B233_4BE86B4B3572__INCLUDED_)
#define AFX_APIGEN_H__733FC092_D773_49F6_B233_4BE86B4B3572__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CAPIGenApp:
// See APIGen.cpp for the implementation of this class
//

class CAPIGenApp : public CWinApp
{
public:
	CAPIGenApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAPIGenApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CAPIGenApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_APIGEN_H__733FC092_D773_49F6_B233_4BE86B4B3572__INCLUDED_)
