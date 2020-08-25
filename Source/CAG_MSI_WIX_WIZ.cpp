// Static Model
#include "stdafx.h"
#include "apigen.h"

#include "CAG_MSI_WIX_WIZ.h"

CAG_MSI_WIX_WIZ::CAG_MSI_WIX_WIZ()
{
	APIFlavor=MSI_WIXDLG_API;
	resetVariableFlags();	
}

CAG_MSI_WIX_WIZ::~CAG_MSI_WIX_WIZ()
{
	
}


void CAG_MSI_WIX_WIZ::generateHeader(CStringArray* pcsaHeader,
										 CStringArray* pcsaBody)
{

	// output to Translator's output window
	// output to Translator's output window
	CString csViewOutStuff;

	CString csDialogIDName;
	CString csDialogTitle;
	CString csBitmapID;
	CString csBitmapPath;

	BOOL	bBitmapSpecified=TRUE;
	
	if (IDOK == WIXCfgDlg.DoModal())
	{
		csDialogIDName = WIXCfgDlg.csDialogIDName;
		csDialogTitle = WIXCfgDlg.csDialogTitle;
		csBitmapID = WIXCfgDlg.csBitmapID;
		csBitmapPath = WIXCfgDlg.csBitmapPath;

		if ( 0 == csBitmapID.GetLength() )
		{
			bBitmapSpecified=false;
		}


	}
	else
	{
		csDialogIDName = "APIG_WIX_Dialog";
		csDialogTitle = "Default WIX dialog";
		bBitmapSpecified=false;
	}

	pcsaHeader->Add("<?xml version=\"1.0\" encoding=\"windows-1252\"?>");
	pcsaHeader->Add("<Wix xmlns=\"http://schemas.microsoft.com/wix/2003/01/wi\">");
	pcsaHeader->Add("  <Fragment>");
	pcsaHeader->Add("    <UI>");
	
	if ( bBitmapSpecified )
	{
		csViewOutStuff.Format( "    <Property Id=\"%s\" Value=\"%s\" />", csBitmapID, csBitmapPath );
		pcsaHeader->Add(csViewOutStuff);
	}

	csViewOutStuff.Format( "      <Dialog Id=\"%s\" Width=\"370\" Height=\"270\" Title=\"%s\" NoMinimize=\"yes\">", csDialogIDName, csDialogTitle );
	pcsaHeader->Add(csViewOutStuff);

}



void CAG_MSI_WIX_WIZ::appendBody(int nFunctionNum,
									 bool bPromptForValues,
									 CStringArray* pcsaArguments,
									 CStringArray* pcsaHeader,
									 CStringArray* pcsaBody)
{
	CString csViewOutStuff;
	CString csFunctionName;

//	csFunctionName = pcsaArguments->GetAt( 0 );

		CString	csLocal;

		switch ( nFunctionNum )
		{
			case 0:     //Bitmap
			{
				csViewOutStuff.Format( "        <Property Id=\"%s\" Value=\"%s\" />", pcsaArguments->GetAt(2), pcsaArguments->GetAt(1) );
				pcsaBody->Add(csViewOutStuff);
			}
			break;

			case 1:     //Control label
			{
				csViewOutStuff.Format( "        <Control Id=\"%s\" Type=\"Text\" X=\"%s\" Y=\"%s\" Width=\"%s\" Height=\"15\" TabSkip=\"no\" Text=\"%s\" />", 
												pcsaArguments->GetAt(1),
												pcsaArguments->GetAt(3), 
												pcsaArguments->GetAt(4), 
												pcsaArguments->GetAt(5), 
												pcsaArguments->GetAt(2) );
				pcsaBody->Add(csViewOutStuff);
			}
			break;

			case 2:     //Edit control
			{
				csViewOutStuff.Format( "        <Control Id=\"%s\" Type=\"Edit\" X=\"%s\" Y=\"%s\" Width=\"%s\" Height=\"18\" Property=\"%s\" Text=\"%s\" />", 
												pcsaArguments->GetAt(1), 
												pcsaArguments->GetAt(4), 
												pcsaArguments->GetAt(5), 
												pcsaArguments->GetAt(6), 
												pcsaArguments->GetAt(2), 
												pcsaArguments->GetAt(3) );
				pcsaBody->Add(csViewOutStuff);
			}
			break;

			case 3:     //Line
			{
				csViewOutStuff.Format( "        <Control Id=\"%s\" Type=\"Line\" X=\"%s\" Y=\"%s\" Width=\"%s\" Height=\"0\" />", 
												pcsaArguments->GetAt(1), 
												pcsaArguments->GetAt(2), 
												pcsaArguments->GetAt(3), 
												pcsaArguments->GetAt(4) );
				pcsaBody->Add(csViewOutStuff);
			}
			break;

			case 4:     //Masked edit control
			{
				csViewOutStuff.Format( "        <Control Id=\"%s\" Type=\"MaskedEdit\" X=\"%s\" Y=\"%s\" Width=\"%s\" Height=\"16\" Property=\"%s\" Text=\"%s\" />", 
												pcsaArguments->GetAt(1), 
												pcsaArguments->GetAt(4), 
												pcsaArguments->GetAt(5), 
												pcsaArguments->GetAt(6), 
												pcsaArguments->GetAt(2), 
												pcsaArguments->GetAt(3) );
				pcsaBody->Add(csViewOutStuff);
			}
			break;

			case 5:     //Pushbutton
			{
				csViewOutStuff.Format( "        <Control Id=\"%s\" Type=\"PushButton\" X=\"%s\" Y=\"%s\" Width=\"%s\" Height=\"17\" Text=\"%s\">", 
												pcsaArguments->GetAt(1), 
												pcsaArguments->GetAt(6), 
												pcsaArguments->GetAt(7), 
												pcsaArguments->GetAt(8), 
												pcsaArguments->GetAt(2) );
				pcsaBody->Add(csViewOutStuff);

				csViewOutStuff.Format( "          <Publish Event=\"%s\" Value=\"%s\">%s</Publish>", 
												pcsaArguments->GetAt(3), 
												pcsaArguments->GetAt(4), 
												pcsaArguments->GetAt(5) );
				pcsaBody->Add(csViewOutStuff);

				csViewOutStuff.Format( "        </Control>" );
				pcsaBody->Add(csViewOutStuff);
			}
			break;

			default:
			{
				csViewOutStuff.Format( "   // APIGen has not yet implemented this method." );
				pcsaBody->Add(csViewOutStuff);
			}
			break;
		}

	pcsaArguments->RemoveAll();
}




void CAG_MSI_WIX_WIZ::finalize(CStringArray* pcsaBody)
{
	pcsaBody->Add( "      </Dialog>");
	pcsaBody->Add( "    </UI>");
	pcsaBody->Add( "  </Fragment>");
	pcsaBody->Add( "</Wix>");
}

void CAG_MSI_WIX_WIZ::declareVariable(AG_VARIABLE agVariable,
										  CStringArray* pcsaHeader,
										  bool* bValue)
{
	CString csLocal;
	*bValue = TRUE;

	pcsaHeader->Add(csLocal);

}


void CAG_MSI_WIX_WIZ::checkDebug( bool b_Debug, CString csFunctionName, CStringArray* pcsaBody )
{
	CString csLocal;
}


void CAG_MSI_WIX_WIZ::resetVariableFlags()
{
}


void CAG_MSI_WIX_WIZ::loadLanguageList(CListBox* listTranslateLanguage)
{
	int nPos = 0;

	listTranslateLanguage->ResetContent();
	listTranslateLanguage->InsertString( nPos++, "XML" );
	listTranslateLanguage->SetCurSel(0);

}

void CAG_MSI_WIX_WIZ::loadTerminalTypeList(CListBox* listTerminalTypes)
{
	int nPos = 0;

	listTerminalTypes->ResetContent();
	listTerminalTypes->InsertString( nPos++, "Installer App" );
	listTerminalTypes->InsertString( nPos++, "Custom Action DLL" );
	listTerminalTypes->InsertString( nPos++, "Database App" );
	listTerminalTypes->InsertString( nPos++, "MSIExec" );
	listTerminalTypes->InsertString( nPos++, "Summary Info" );
	listTerminalTypes->InsertString( nPos++, "WIX dialog" );
	listTerminalTypes->InsertString( nPos++, "WIX wizard" );
	
	listTerminalTypes->SetCurSel(0);
}


void CAG_MSI_WIX_WIZ::loadFunctionList(CListBox* listTranslateFunction)
{
	csaFunctions.RemoveAll();

	listTranslateFunction->ResetContent();

	csaFunctions.Add("Bitmap");
	csaFunctions.Add("Control label");
	csaFunctions.Add("Edit control");
	csaFunctions.Add("Line");
	csaFunctions.Add("Masked edit control");
	csaFunctions.Add("Pushbutton");

	listTranslateFunction->ResetContent();	
	
	for (int k=0; k<csaFunctions.GetSize(); k++)
	{
		listTranslateFunction->AddString( csaFunctions.GetAt(k) );
	}

	listTranslateFunction->SetCurSel(0);

}
