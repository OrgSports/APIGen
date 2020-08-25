// XMLVT.cpp : implementation file
//

#include "stdafx.h"
#include "APIGen.h"
#include "XMLVT.h"


// CXMLVT dialog

IMPLEMENT_DYNAMIC(CXMLVT, CDialog)
CXMLVT::CXMLVT(CWnd* pParent /*=NULL*/)
	: CDialog(CXMLVT::IDD, pParent)
	, csEditVTHostName(_T(""))
	, csEditVTPortNumber(_T(""))
	, csEditVTTabColumns(_T(""))
{
}

CXMLVT::~CXMLVT()
{
}

void CXMLVT::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDEDIT_XML_VT_HOSTNAME, cEditVTHostName);
	DDX_Text(pDX, IDEDIT_XML_VT_HOSTNAME, csEditVTHostName);
	DDX_Control(pDX, IDEDIT_XML_VT_PORTNUMBER, cEditVTPortNumber);
	DDX_Text(pDX, IDEDIT_XML_VT_PORTNUMBER, csEditVTPortNumber);
	DDX_Control(pDX, IDEDIT_XML_VT_TABCOLUMNS, cEditVTTabColumns);
	DDX_Text(pDX, IDEDIT_XML_VT_TABCOLUMNS, csEditVTTabColumns);
	DDX_Control(pDX, IDCHECK_XML_VT_LOCALMODE, bCheckVTLocalMode);
	DDX_Control(pDX, IDCHECK_XML_VT_INITNEGOTIATION, bCheckVTInitiateNegotiation);
	DDX_Control(pDX, IDCHECK_XML_VT_NEGOTIATE_BINARY, bCheckVTNegotiateBinary);
	DDX_Control(pDX, IDCHECK_XML_VT_AUTOWRAP, bCheckVTAutoWrap);
}


BEGIN_MESSAGE_MAP(CXMLVT, CDialog)
END_MESSAGE_MAP()


// CXMLVT message handlers
BOOL CXMLVT::OnInitDialog()
{
	CDialog::OnInitDialog();

	bCheckVTLocalMode.SetCheck( BST_UNCHECKED );
	bCheckVTInitiateNegotiation.SetCheck( BST_UNCHECKED );
	bCheckVTNegotiateBinary.SetCheck( BST_UNCHECKED );
	bCheckVTAutoWrap.SetCheck( BST_UNCHECKED );

	UpdateData();

	return TRUE;  // return TRUE  unless you set the focus to a control
}



void CXMLVT::OnOK() 
{
	CDialog::OnOK();


}
