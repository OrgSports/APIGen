// P4Globals.cpp : implementation file
//

#include "stdafx.h"
#include "APIGen.h"
#include "P4Globals.h"


// CP4Globals dialog

IMPLEMENT_DYNAMIC(CP4Globals, CDialog)
CP4Globals::CP4Globals(CWnd* pParent /*=NULL*/)
	: CDialog(CP4Globals::IDD, pParent)
	, csClientName(_T(""))
	, csWorkingDir(_T(""))
	, csHostName(_T(""))
	, csPortNumber(_T(""))
	, csPassword(_T(""))
	, csUserName(_T(""))
	, csFileName(_T(""))
	, csCharSet(_T(""))
	, bClientName(FALSE)
	, bWorkingDir(FALSE)
	, bFormatOutput(FALSE)
	, bHostName(FALSE)
	, bPort(FALSE)
	, bPassword(FALSE)
	, bPrependLines(FALSE)
	, bUserName(FALSE)
	, bInputFile(FALSE)
	, bCharSet(FALSE)
	, bP4Version(FALSE)
	, bDisplayHelpInfo(FALSE)
{
}

CP4Globals::~CP4Globals()
{
}

void CP4Globals::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDCHECK_PERFORCE_GLOBAL_CLIENT, cbClientName);
	DDX_Control(pDX, IDCHECK_PERFORCE_GLOBAL_PWD, cbWorkingDir);
	DDX_Control(pDX, IDCHECK_PERFORCE_PYTHON_DICTIONARIES, cbFormatOutput);
	DDX_Control(pDX, IDCHECK_PERFORCE_HOST, cbHostName);
	DDX_Control(pDX, IDCHECK_PERFORCE_PORT, cbPort);
	DDX_Control(pDX, IDCHECK_PERFORCE_PASSWORD, cbPassword);
	DDX_Control(pDX, IDCHECK_PERFORCE_PREPEND, cbPrependLines);
	DDX_Control(pDX, IDCHECK_PERFORCE_USERNAME, cbUserName);
	DDX_Control(pDX, IDCHECK_PERFORCE_INPUT_FILE, cbInputFile);
	DDX_Control(pDX, IDCHECK_PERFORCE_CHARACTER_SET, cbCharSet);
	DDX_Control(pDX, IDCHECK_PERFORCE_VERSION, cbP4Version);
	DDX_Control(pDX, IDCHECK_PERFORCE_DISPLAY_HELP, cbDisplayHelpInfo);
	DDX_Text(pDX, IDEDIT_PERFORCE_CLIENT_OVERRIDE, csClientName);
	DDX_Text(pDX, IDEDIT_PERFORCE_CLIENT_PWD, csWorkingDir);
	DDX_Text(pDX, IDEDIT_PERFORCE_HOST, csHostName);
	DDX_Text(pDX, IDEDIT_PERFORCE_PORT, csPortNumber);
	DDX_Text(pDX, IDEDIT_PERFORCE_PASSWORD, csPassword);
	DDX_Text(pDX, IDEDIT_PERFORCE_USERNAME, csUserName);
	DDX_Text(pDX, IDEDIT_PERFORCE_FILENAME, csFileName);
	DDX_Text(pDX, IDEDIT_PERFORCE_CHARSET, csCharSet);
	DDX_Check(pDX, IDCHECK_PERFORCE_GLOBAL_CLIENT, bClientName);
	DDX_Check(pDX, IDCHECK_PERFORCE_GLOBAL_PWD, bWorkingDir);
	DDX_Check(pDX, IDCHECK_PERFORCE_PYTHON_DICTIONARIES, bFormatOutput);
	DDX_Check(pDX, IDCHECK_PERFORCE_HOST, bHostName);
	DDX_Check(pDX, IDCHECK_PERFORCE_PORT, bPort);
	DDX_Check(pDX, IDCHECK_PERFORCE_PASSWORD, bPassword);
	DDX_Check(pDX, IDCHECK_PERFORCE_PREPEND, bPrependLines);
	DDX_Check(pDX, IDCHECK_PERFORCE_USERNAME, bUserName);
	DDX_Check(pDX, IDCHECK_PERFORCE_INPUT_FILE, bInputFile);
	DDX_Check(pDX, IDCHECK_PERFORCE_CHARACTER_SET, bCharSet);
	DDX_Check(pDX, IDCHECK_PERFORCE_VERSION, bP4Version);
	DDX_Check(pDX, IDCHECK_PERFORCE_DISPLAY_HELP, bDisplayHelpInfo);
}


BEGIN_MESSAGE_MAP(CP4Globals, CDialog)
END_MESSAGE_MAP()


// CP4Globals message handlers
BOOL CP4Globals::OnInitDialog()
{
	CDialog::OnInitDialog();

	return TRUE;  // return TRUE  unless you set the focus to a control
}


void CP4Globals::OnOK() 
{
	CDialog::OnOK();
}
