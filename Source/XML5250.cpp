// XML5250.cpp : implementation file
//

#include "stdafx.h"
#include "APIGen.h"
#include "XML5250.h"


// CXML5250 dialog

IMPLEMENT_DYNAMIC(CXML5250, CDialog)
CXML5250::CXML5250(CWnd* pParent /*=NULL*/)
	: CDialog(CXML5250::IDD, pParent)
	, csEdit5250HostName(_T(""))
	, csEdit5250PortNumber(_T(""))
	, bCheck5250NumericFieldOverride(FALSE)
	, bCheck5250DestructiveBackspace(FALSE)
	, csEdit5250XLateFileName(_T(""))
{
}

CXML5250::~CXML5250()
{
}

void CXML5250::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDEDIT_XML_5250_HOSTNAME, cEdit5250HostName);
	DDX_Text(pDX, IDEDIT_XML_5250_HOSTNAME, csEdit5250HostName);
	DDX_Control(pDX, IDEDIT_XML_5250_PORTNUMBER, cEdit5250PortNumber);
	DDX_Text(pDX, IDEDIT_XML_5250_PORTNUMBER, csEdit5250PortNumber);
	DDX_Control(pDX, IDLIST_XML_5250_TEXTCASE, cList5250CharCase);
	DDX_Control(pDX, IDLIST_XML_5250_ATTRIBUTE_STYLE, cList5250AttributeChoice);
	DDX_Check(pDX, IDCHECK_XML_5250_NUMERICFIELDOVERRIDE, bCheck5250NumericFieldOverride);
	DDX_Check(pDX, IDCHECK_XML_5250_DESTRUCIVE_BACKSPACE, bCheck5250DestructiveBackspace);
	DDX_Control(pDX, IDEDIT_XML_5250_XLATEFILE, cEdit5250XLateFileName);
	DDX_Text(pDX, IDEDIT_XML_5250_XLATEFILE, csEdit5250XLateFileName);
	DDX_Control(pDX, IDCHECK_XML_5250_DESTRUCIVE_BACKSPACE, cbDestructiveBackspace);
}


BEGIN_MESSAGE_MAP(CXML5250, CDialog)
END_MESSAGE_MAP()


// CXML5250 message handlers
BOOL CXML5250::OnInitDialog()
{
	CDialog::OnInitDialog();

	int nPos = 0;
	int nPosB = 0;

	cList5250CharCase.ResetContent();
	cList5250CharCase.InsertString( nPos++, "Mixed case" );
	cList5250CharCase.InsertString( nPos++, "Lower case" );
	cList5250CharCase.InsertString( nPos++, "Upper case" );
	cList5250CharCase.SetCurSel(0);

	cList5250AttributeChoice.ResetContent();
	cList5250AttributeChoice.InsertString( nPosB++, "Display attributes processed by viewer" );
	cList5250AttributeChoice.InsertString( nPosB++, "Display attributes as asterisks" );
	cList5250AttributeChoice.InsertString( nPosB++, "Display attributes as periods" );
	cList5250AttributeChoice.SetCurSel(0);

	cbDestructiveBackspace.SetCheck( BST_CHECKED );
	bCheck5250DestructiveBackspace=TRUE;

	UpdateData();

	return TRUE;  // return TRUE  unless you set the focus to a control
}


// CXML5250 message handlers
void CXML5250::OnOK() 
{
	CDialog::OnOK();
	int nCharCasePosition, nAttributePosition;

	nCharCasePosition = cList5250CharCase.GetCurSel();
	cList5250CharCase.GetText( nCharCasePosition, csList5250CharCase );

	nAttributePosition = cList5250AttributeChoice.GetCurSel();
	cList5250AttributeChoice.GetText( nAttributePosition, csList5250AttributeChoice );

}
