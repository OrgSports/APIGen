// Static Model
#include "stdafx.h"
#include "apigen.h"

#include "CAG_EOLE_VT_CPP.h"



CAG_EOLE_VT_CPP::CAG_EOLE_VT_CPP()
{
	resetVariableFlags();	
}

CAG_EOLE_VT_CPP::~CAG_EOLE_VT_CPP()
{
	
}

void CAG_EOLE_VT_CPP::declareVariable(AG_VARIABLE agVariable,
									  CStringArray* pcsaHeader,
									  bool* bValue)
{
	CString csLocal;
	*bValue = TRUE;
	
	switch ( agVariable )
	{
		case AG_STATUS:
		{
			csLocal.Format( "   int nStatus=0;");
		}
		break;

		case AG_UPDATED:
		{
			csLocal.Format( "   BOOL bUpdated=FALSE;");
		}
		break;

		case AG_UTILBUFFER:
		{
			csLocal.Format( "   char *pUtilityBuffer;");
		}
		break;

		case AG_BSTR:
		{
			csLocal.Format( "   CString csBStr;");
			pcsaHeader->Add(csLocal);

			csLocal.Format( "   VARIANT bstrUtility;");
			pcsaHeader->Add(csLocal);
			csLocal.Format( "   ::VariantInit(&bstrUtility);");
			pcsaHeader->Add(csLocal);
			csLocal.Format( "   bstrUtility.vt=VT_BSTR;");
		}
		break;

		case AG_ROW:
		{
			csLocal.Format( "   VARIANT nRow;");
			pcsaHeader->Add(csLocal);
			csLocal.Format( "   ::VariantInit(&nRow);");
			pcsaHeader->Add(csLocal);
			csLocal.Format( "   nRow.vt=VT_I2;");
		}
		break;


		case AG_SETTINGS_DIALOG:
		{
			csLocal.Format( "   VARIANT nSettingsDialogChoice;");
			pcsaHeader->Add(csLocal);
			csLocal.Format( "   ::VariantInit(&nSettingsDialogChoice);");
			pcsaHeader->Add(csLocal);
			csLocal.Format( "   nSettingsDialogChoice.vt=VT_I2;");
		}
		break;

		case AG_COLUMN:
		{
			csLocal.Format( "   VARIANT nColumn;");
			pcsaHeader->Add(csLocal);
			csLocal.Format( "   ::VariantInit(&nColumn);");
			pcsaHeader->Add(csLocal);
			csLocal.Format( "   nColumn.vt=VT_I2;");
		}
		break;

		case AG_ATTRIBUTE:
		{
			csLocal.Format( "   int nAttribute=0;");
		}
		break;

		case AG_LENGTH:
		{
			csLocal.Format( "   VARIANT nLength;");
			pcsaHeader->Add(csLocal);
			csLocal.Format( "   ::VariantInit(&nLength);");
			pcsaHeader->Add(csLocal);
			csLocal.Format( "   nLength.vt=VT_I4;");
		}
		break;

		case AG_VALUE:
		{
			csLocal.Format( "   int nValue=0;");
		}
		break;

		case AG_RETURN:
		{
			csLocal.Format( "   BOOL bRet=FALSE;");
		}
		break;

		case AG_CLOSEOPTION:
		{
			csLocal.Format( "   VARIANT nCloseOption;");
			pcsaHeader->Add(csLocal);
			csLocal.Format( "   ::VariantInit(&nCloseOption);");
			pcsaHeader->Add(csLocal);
			csLocal.Format( "   nCloseOption.vt=VT_I4;");	// XXX
		}
		break;

		case AG_HOST_OS:
		{
			csLocal.Format( "   VARIANT nFTHostOS;");
			pcsaHeader->Add(csLocal);
			csLocal.Format( "   ::VariantInit(&nFTHostOS);");
			pcsaHeader->Add(csLocal);
			csLocal.Format( "   nFTHostOS.vt=VT_I4;");	// XXX
		}
		break;

		case AG_HEIGHT:
		{
			csLocal.Format( "   short sHeight=0;");
		}
		break;

		case AG_LOCALMODE:
		{
			csLocal.Format( "   BOOL bLocalMode=FALSE;");
		}
		break;

		case AG_OIA:
		{
			csLocal.Format( "   poOIA = poScreen->OIA;");
		}
		break;

		case AG_SESS_SAVED:
		{
			csLocal.Format( "   BOOL bSessionSaved=FALSE;");
		}
		break;

		case AG_SESS_OPEN:
		{
			csLocal.Format( "   char SessName[512];");
			pcsaHeader->Add(csLocal);
			csLocal.Format( "   char* pSessName=SessName;");
		}
		break;


		case AG_SETTLE_TIME:
		{
			csLocal.Format( "   VARIANT nSettleTime;");
			pcsaHeader->Add(csLocal);
			csLocal.Format( "   ::VariantInit(&nSettleTime);");
			pcsaHeader->Add(csLocal);
			csLocal.Format( "   nSettleTime.vt=VT_I4;");	// XXX
		}
		break;

		case AG_SESS_QUIET:
		{
			csLocal.Format( "   BOOL bSessionQuiet=FALSE;");
		}
		break;

		case AG_MENU_VISIBLE:
		{
			csLocal.Format( "   BOOL bMenuVisible=FALSE;");
		}
		break;

		case AG_TYPE:
		{
			csLocal.Format( "   int nType=0;");
		}
		break;

		case AG_TIMEOUT:
		{
			csLocal.Format( "   VARIANT nTimeout;");
			pcsaHeader->Add(csLocal);
			csLocal.Format( "   ::VariantInit(&nTimeout);");
			pcsaHeader->Add(csLocal);
			csLocal.Format( "   nTimeout.vt=VT_I4;");	// XXX int
		}
		break;

		case AG_PROCESS_KEYSTROKES:
		{
			csLocal.Format( "   VARIANT bProcessKeystrokes;");
			pcsaHeader->Add(csLocal);
			csLocal.Format( "   ::VariantInit(&bProcessKeystrokes);");
			pcsaHeader->Add(csLocal);
			csLocal.Format( "   nColumn.vt=VT_I4;");	// XXX	BOOL
		}
		break;

		case AG_WIDTH:
		{
			csLocal.Format( "   int nWidth=0;");
		}
		break;

		case AG_WINDOW_HANDLE:
		{
			csLocal.Format( "   HANDLE hSession=NULL;");
		}
		break;

		case AG_WINDOW_STATE:
		{
			csLocal.Format( "   int nWindowState=0;");
		}
		break;

		case AG_COUNT:
		{
			csLocal.Format( "   int nCount=0;");
		}
		break;

		case AG_AREA:
		{
			csLocal.Format( "   int Area=0;");
		}
		break;

		case AG_HOSTNAME:
		{
			csLocal.Format( "   CString csHostName;");
		}
		break;

		case AG_FONTNAME:
		{
			csLocal.Format( "   CString csFontName;");
		}
		break;

		case AG_FT_SCHEME:
		{
			csLocal.Format( "   char ftSchemeString[512] = {0};");
			pcsaHeader->Add(csLocal);

			csLocal.Format( "   CString csFTTransferScheme;");
		}
		break;

		case AG_HOSTFILE_BSTR:
		{
			csLocal.Format( "   CString csFT_HostFileBSTR;");
			pcsaHeader->Add(csLocal);

			csLocal.Format( "   VARIANT FT_HostFileBSTR;");
			pcsaHeader->Add(csLocal);
			csLocal.Format( "   ::VariantInit(&FT_HostFileBSTR);");
			pcsaHeader->Add(csLocal);
			csLocal.Format( "   FT_HostFileBSTR.vt=VT_BSTR;");
		}
		break;

		case AG_PCFILE_BSTR:
		{
			csLocal.Format( "   CString csFT_PCFileBSTR;");
			pcsaHeader->Add(csLocal);

			csLocal.Format( "   VARIANT FT_PCFileBSTR;");
			pcsaHeader->Add(csLocal);
			csLocal.Format( "   ::VariantInit(&FT_PCFileBSTR);");
			pcsaHeader->Add(csLocal);
			csLocal.Format( "   FT_PCFileBSTR.vt=VT_BSTR;");
		}
		break;

		case AG_IDLE_TIME:
		{
			csLocal.Format( "   VARIANT nIdleTime;");
			pcsaHeader->Add(csLocal);
			csLocal.Format( "   ::VariantInit(&nIdleTime);");
			pcsaHeader->Add(csLocal);
			csLocal.Format( "   nIdleTime.vt=VT_I4;");
		}
		break;

		case AG_WAIT_OPTION:
		{
			csLocal.Format( "   VARIANT nWaitOption;");
			pcsaHeader->Add(csLocal);
			csLocal.Format( "   ::VariantInit(&nWaitOption);");
			pcsaHeader->Add(csLocal);
			csLocal.Format( "   nWaitOption.vt=VT_I4;");
		}
		break;

		case AG_WAIT_ID:
		{
			csLocal.Format( "   int nWaitID=0;");
		}
		break;

		case AG_RETURN_CODE:
		{
			csLocal.Format( "   int nRetCode=0;");
		}
		break;

		case AG_AREA_OUTPUT:
		{
			csLocal.Format( "   CString csAreaOutput;");
			pcsaHeader->Add(csLocal);

			csLocal.Format( "   short sRetCode1, sRetCode2, sRetCode3, sRetCode4;");
		}
		break;



	}

	pcsaHeader->Add(csLocal);

}


void CAG_EOLE_VT_CPP::generateHeader(CStringArray* pcsaHeader,
									 CStringArray* pcsaBody)
{
	CString csViewOutStuff;
	
	csViewOutStuff.Format( "// ****************************************************************************");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "//   Attachmate APIGen VT OLE Automation C++ Application");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "//" );
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "//   This source file provides an OnInitDialog function prepared to run, as is,");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "//    in a Visual C++ MFC dialog application.  To use it, do the following:");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "//   1. run the MFC New Application Wizard and specify that you want to create ");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "//      a dialog application.");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "//   2. When the wizard is done, replace the OnInitDialog function that you'll find");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "//      in the CPP file containing the class that inherits from CDialog with the one");
	pcsaHeader->Add(csViewOutStuff);
	
	csViewOutStuff.Format( "//   3. Copy the file, extra.tlb, from the Extra! home folder into your new project's");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "//      folder.");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "//   4. Move the following nine lines of text -- ");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "/*" );
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "         #import \"extra.tlb\" named_guids");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "" );
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "         EXTRA::_SystemPtr poSystem;" );
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "         EXTRA::SessionsPtr poSessions;" );
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "         EXTRA::_SessionPtr poSession;" );
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "         EXTRA::ScreenPtr poScreen;" );
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "         EXTRA::OIAPtr poOIA;" );
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "         EXTRA::AreaPtr poArea;" );
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "         EXTRA::_ScreenWaitPtr poScreenWait;" );
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "         EXTRA::WaitsPtr poWaits;" );
	pcsaHeader->Add(csViewOutStuff);
	
	csViewOutStuff.Format( "*/" );
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "//      to just after the #include statements in your CPP file.");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "//   5. Ensure that the name of the class name before the");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "//      OnInitDialog function's scope resolution operator (::)");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "//      is accurate.");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "//" );
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "//   After these three steps are completed, this source output should");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "//   compile and run as-is.");
	pcsaHeader->Add(csViewOutStuff);

	time_t ltime;
	time( &ltime );

	csViewOutStuff.Format( "//");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "//   Generated:   %s", ctime( &ltime ) );
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "//");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "// ****************************************************************************");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( " " );
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "BOOL COLE32CPPDlg::OnInitDialog()" );
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "{" );
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "   CDialog::OnInitDialog();" );
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( " " );
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "   SetIcon(m_hIcon, TRUE);" );
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "   SetIcon(m_hIcon, FALSE);" );
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( " " );
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "   HRESULT hr;" );
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "   CString csSessName;" );
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( " " );
	pcsaHeader->Add(csViewOutStuff);
	
	csViewOutStuff.Format( "   using namespace EXTRA;" );
	pcsaHeader->Add(csViewOutStuff);
	
	csViewOutStuff.Format( " " );
	pcsaHeader->Add(csViewOutStuff);
	
	csViewOutStuff.Format( "   poSystem = NULL;" );
	pcsaHeader->Add(csViewOutStuff);
	
	csViewOutStuff.Format( "   poSessions = NULL;" );
	pcsaHeader->Add(csViewOutStuff);
	
	csViewOutStuff.Format( "   poSession = NULL;" );
	pcsaHeader->Add(csViewOutStuff);
	
	csViewOutStuff.Format( "   poScreen = NULL;" );
	pcsaHeader->Add(csViewOutStuff);
	
	csViewOutStuff.Format( "   poOIA = NULL;" );
	pcsaHeader->Add(csViewOutStuff);
	
	csViewOutStuff.Format( "   poArea = NULL;" );
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "   poScreenWait = NULL;" );
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "   poWaits = NULL;" );
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "   int nConnectionTimeout=10;" );
	pcsaHeader->Add(csViewOutStuff);
	
	csViewOutStuff.Format( " " );
	pcsaHeader->Add(csViewOutStuff);
	
	csViewOutStuff.Format( "   hr = CoInitialize(NULL);" );
	pcsaHeader->Add(csViewOutStuff);
	
	csViewOutStuff.Format( " " );
	pcsaHeader->Add(csViewOutStuff);
	
	csViewOutStuff.Format( "   try" );
	pcsaHeader->Add(csViewOutStuff);
	
	csViewOutStuff.Format( "   {" );
	pcsaHeader->Add(csViewOutStuff);
	
	csViewOutStuff.Format( "      hr = poSystem.CreateInstance(\"Extra.System\", NULL);" );
	pcsaHeader->Add(csViewOutStuff);
	
	csViewOutStuff.Format( "      poSystem->put_TimeoutValue( nConnectionTimeout );" );
	pcsaHeader->Add(csViewOutStuff);
	
	csViewOutStuff.Format( "   }" );
	pcsaHeader->Add(csViewOutStuff);
	
	csViewOutStuff.Format( "   catch(COleException* pEx)" );
	pcsaHeader->Add(csViewOutStuff);
	
	csViewOutStuff.Format( "   {" );
	pcsaHeader->Add(csViewOutStuff);
	
	csViewOutStuff.Format( "      CString csMessage;" );
	pcsaHeader->Add(csViewOutStuff);
	
	csViewOutStuff.Format( "      csMessage.Format(\"Could not create EXTRA! System object: 0x%8.8x\", pEx->m_sc);" );
	pcsaHeader->Add(csViewOutStuff);
	
	csViewOutStuff.Format( "      CoUninitialize();" );
	pcsaHeader->Add(csViewOutStuff);
	
	csViewOutStuff.Format( "      pEx->Delete();" );
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "      AfxMessageBox(csMessage);" );
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "   }" );
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( " " );
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "   // ******************************************************" );
	pcsaHeader->Add(csViewOutStuff);
	
	csViewOutStuff.Format( " " );
	pcsaHeader->Add(csViewOutStuff);

	declareVariable( AG_BSTR, pcsaHeader, &b_BSTR );	
	
	csViewOutStuff.Format( " " );
	pcsaBody->Add(csViewOutStuff);

	csViewOutStuff.Format( "   CFileDialog fileDialog(true, NULL, NULL,");
	pcsaBody->Add(csViewOutStuff);

	csViewOutStuff.Format( "      (OFN_FILEMUSTEXIST | OFN_HIDEREADONLY | OFN_LONGNAMES | OFN_PATHMUSTEXIST),");
	pcsaBody->Add(csViewOutStuff);

    csViewOutStuff.Format( "   _T(\"Extra! files (*.edp)|*.edp|INFOConnect files (*.adp)|*.adp|All Files (*.*)|*.*||\"));" );
	pcsaBody->Add(csViewOutStuff);

	csViewOutStuff.Format( "   fileDialog.m_ofn.lpstrTitle = _T(\"Select session file\");" );
	pcsaBody->Add(csViewOutStuff);

	csViewOutStuff.Format( "   TCHAR filenameBuffer[4096] = { 0 };");
	pcsaBody->Add(csViewOutStuff);

	csViewOutStuff.Format( "   fileDialog.m_ofn.lpstrFile = filenameBuffer;");
	pcsaBody->Add(csViewOutStuff);

	csViewOutStuff.Format( "   fileDialog.m_ofn.nMaxFile = sizeof(filenameBuffer) / sizeof(filenameBuffer[0]);" );
	pcsaBody->Add(csViewOutStuff);

	csViewOutStuff.Format( " " );
	pcsaBody->Add(csViewOutStuff);

	csViewOutStuff.Format( "   // open the session file" );
	pcsaBody->Add(csViewOutStuff);
	csViewOutStuff.Format( "   if (IDOK == fileDialog.DoModal())" );
	pcsaBody->Add(csViewOutStuff);
	csViewOutStuff.Format( "   {" );
	pcsaBody->Add(csViewOutStuff);
	csViewOutStuff.Format( "      csSessName = fileDialog.GetPathName();" );
	pcsaBody->Add(csViewOutStuff);
	csViewOutStuff.Format( "   }" );
	pcsaBody->Add(csViewOutStuff);
	csViewOutStuff.Format( "   else" );
	pcsaBody->Add(csViewOutStuff);
	csViewOutStuff.Format( "   {" );
	pcsaBody->Add(csViewOutStuff);
	csViewOutStuff.Format( "      AfxMessageBox(\"No session file, no program execution!\");" );
	pcsaBody->Add(csViewOutStuff);
	csViewOutStuff.Format( "      return FALSE;" );
	pcsaBody->Add(csViewOutStuff);
	csViewOutStuff.Format( "   }" );
	pcsaBody->Add(csViewOutStuff);

	csViewOutStuff.Format( " " );
	pcsaBody->Add(csViewOutStuff);

	csViewOutStuff.Format( "   bstrUtility.bstrVal = csSessName.AllocSysString();");
	pcsaBody->Add(csViewOutStuff);

	csViewOutStuff.Format( "   poSessions = poSystem->Sessions;");
	pcsaBody->Add(csViewOutStuff);
	   
	csViewOutStuff.Format( "   poSession = poSessions->Open( bstrUtility.bstrVal );");
	pcsaBody->Add(csViewOutStuff);

	csViewOutStuff.Format( "   poScreen = poSession->Screen;");
	pcsaBody->Add(csViewOutStuff);

	csViewOutStuff.Format( "   poWaits = poSystem->GetWaits();");
	pcsaBody->Add(csViewOutStuff);

	csViewOutStuff.Format( " " );
	pcsaBody->Add(csViewOutStuff);

}



void CAG_EOLE_VT_CPP::appendBody(int nFunctionNum,
								 bool bPromptForValues,
								 CStringArray* csaArguments,
								 CStringArray* csaHeader,
								 CStringArray* csaBody)
{
	
}

void CAG_EOLE_VT_CPP::finalize(CStringArray* pcsaBody)
{
	
}


void CAG_EOLE_VT_CPP::checkDebug(bool b_Debug,
									   CString csFunctionName,
									   CStringArray* pcsaBody)
{
	
}

void CAG_EOLE_VT_CPP::resetVariableFlags()
{
   b_SessionOpen = FALSE;
   b_nAttribute = FALSE;
   b_nStatus = FALSE;

   b_bUpdated = FALSE;

   b_nRow = FALSE;
   b_nColumn = FALSE;

   b_nLength = FALSE;
   b_pUtilityBuffer = FALSE;
   b_BSTR = FALSE;
   b_nPosition = FALSE;
   b_nSettleTime = FALSE;

   b_nValue = FALSE;
   bAreaObject = FALSE;

   b_bRet = FALSE;
   b_nCloseOption = FALSE;

   b_nFTHostOS = FALSE;

   b_sHeight = FALSE;
   b_nWidth = FALSE;

   b_bLocalMode = FALSE;
   b_bMenuVisible = FALSE;
   b_bSessionQuiet = FALSE;
   b_bSessionSaved = FALSE;

   b_nType = FALSE;
   b_nTimeout = FALSE;
   b_bProcessKeystrokes = FALSE;
   b_bWindowHandle = FALSE;
   b_nWindowState = FALSE;
   b_nCount = FALSE;

   b_csHostName = FALSE;
   b_csFontName = FALSE;
   b_csFTScheme = FALSE;
   b_nIdleTime = FALSE;
   b_nWaitOption = FALSE;
   b_nWaitID = FALSE;
   b_nRetCode = FALSE;
   bAreaOutput = FALSE;

   bOIA = FALSE;
   b_SettingsDialog = FALSE;
   b_FT_PCFileBSTR = FALSE;
   b_FT_HostFileBSTR = FALSE;

}
