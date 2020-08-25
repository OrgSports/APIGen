// XML3270.cpp : implementation file
//

#include "stdafx.h"
#include "APIGen.h"
#include "XML3270.h"


// CXML3270 dialog

IMPLEMENT_DYNAMIC(CXML3270, CDialog)
CXML3270::CXML3270(CWnd* pParent /*=NULL*/)
	: CDialog(CXML3270::IDD, pParent)
	, csEdit3270HostName(_T(""))
	, csEdit3270PortNumber(_T(""))
	, bCheck3270LightPen(FALSE)
	, csEdit3270XLateFileName(_T(""))
	, csList3270BackSpace(_T(""))
	, csList3270CharCase(_T(""))
{
}

CXML3270::~CXML3270()
{
}

void CXML3270::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDEDIT_XML_3270_HOSTNAME, cEdit3270HostName);
	DDX_Text(pDX, IDEDIT_XML_3270_HOSTNAME, csEdit3270HostName);
	DDX_Control(pDX, IDEDIT_XML_3270_PORTNUMBER, cEdit3270PortNumber);
	DDX_Text(pDX, IDEDIT_XML_3270_PORTNUMBER, csEdit3270PortNumber);
	DDX_Control(pDX, IDLIST_XML_3270_TEXTCASE, cList3270CharCase);
	DDX_Check(pDX, IDCHECK_XML_3270_LPENABLED, bCheck3270LightPen);
	DDX_Control(pDX, IDLIST_XML_3270_BACKSPACE, cList3270BackSpace);
	DDX_Control(pDX, IDEDIT_XML_3270_XLATEFILE, cEdit3270XLateFileName);
	DDX_Text(pDX, IDEDIT_XML_3270_XLATEFILE, csEdit3270XLateFileName);
	DDX_LBString(pDX, IDLIST_XML_3270_BACKSPACE, csList3270BackSpace);
	DDX_LBString(pDX, IDLIST_XML_3270_TEXTCASE, csList3270CharCase);
}


BEGIN_MESSAGE_MAP(CXML3270, CDialog)
END_MESSAGE_MAP()


BOOL CXML3270::OnInitDialog()
{
	CDialog::OnInitDialog();

	int nPos = 0;
	int nPosB = 0;

	cList3270CharCase.ResetContent();
	cList3270CharCase.InsertString( nPos++, "Mixed case" );
	cList3270CharCase.InsertString( nPos++, "Lower case" );
	cList3270CharCase.InsertString( nPos++, "Upper case" );
	cList3270CharCase.SetCurSel(0);

	cList3270BackSpace.ResetContent();
	cList3270BackSpace.InsertString( nPosB++, "Move cursor left one char" );
	cList3270BackSpace.InsertString( nPosB++, "Move cursor left and delete char" );
	cList3270BackSpace.SetCurSel(0);

	return TRUE;  // return TRUE  unless you set the focus to a control
}


// CXML3270 message handlers
void CXML3270::OnOK() 
{
	CDialog::OnOK();
	int nCharCasePosition, nBackSpacePosition;

	nCharCasePosition = cList3270CharCase.GetCurSel();
	cList3270CharCase.GetText( nCharCasePosition, csList3270CharCase );

	nBackSpacePosition = cList3270BackSpace.GetCurSel();
	cList3270BackSpace.GetText( nBackSpacePosition, csList3270BackSpace );

}
