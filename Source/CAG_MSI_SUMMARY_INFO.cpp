// Static Model
#include "stdafx.h"
#include "apigen.h"

#include "CAG_MSI_SUMMARY_INFO.h"

CAG_MSI_SUMMARY_INFO::CAG_MSI_SUMMARY_INFO()
{
	APIFlavor=MSI_SUMMARY_API;
	resetVariableFlags();	
	csSummaryCommand="Msiinfo.exe <filename>";
}

CAG_MSI_SUMMARY_INFO::~CAG_MSI_SUMMARY_INFO()
{
	
}


void CAG_MSI_SUMMARY_INFO::generateHeader(CStringArray* pcsaHeader,
										 CStringArray* pcsaBody)
{

	// output to Translator's output window
	CString csViewOutStuff;

	pcsaHeader->Add("rem *********************************************************************APIGen");
	pcsaHeader->Add("rem               Attachmate MSI Summary Info Command Line");
	pcsaHeader->Add("rem");

	time_t ltime;
	time( &ltime );

	pcsaHeader->Add( "rem" );
	csViewOutStuff.Format( "rem   Generated:   %s", ctime( &ltime ) );
	pcsaHeader->Add(csViewOutStuff);
	pcsaHeader->Add( "rem" );
	pcsaHeader->Add( "rem ****************************************************************************");

	pcsaHeader->Add("");

}



void CAG_MSI_SUMMARY_INFO::appendBody(int nFunctionNum,
									 bool bPromptForValues,
									 CStringArray* pcsaArguments,
									 CStringArray* pcsaHeader,
									 CStringArray* pcsaBody)
{
	CString csViewOutStuff;
	CString csFunctionName;

	csFunctionName = pcsaArguments->GetAt( 0 );

	//pcsaBody->Add("" );

	//csViewOutStuff.Format( "rem   *** %s", csFunctionName );
	//pcsaBody->Add(csViewOutStuff);

	CString	csLocal;

	switch ( nFunctionNum )
	{
		case 0:		//Platform/Language
		{
			CString LangID;
			LangID = pcsaArguments->GetAt( 1 );

			if ( 0 == LangID.Find( "English" ) )
			{
				LangID = ";1033";
			}
			else if ( 0 == LangID.Find( "French" ) )
			{
				LangID = ";1036";
			}
			else if ( 0 == LangID.Find( "German" ) )
			{
				LangID = ";1031";
			}
			else if ( 0 == LangID.Find( "Italian" ) )
			{
				LangID = ";1040";
			}
			else	//Japanese
			{
				LangID = ";1041";
			}

			csViewOutStuff.Format( " -P %s", LangID );
			csSummaryCommand = csSummaryCommand + csViewOutStuff;

		}
		break;

		case 1:		//Revision number
		{
			csViewOutStuff.Format( " -V %s", pcsaArguments->GetAt( 1 ) );
			csSummaryCommand = csSummaryCommand + csViewOutStuff;
		}
		break;

		case 2:		//Page count
		{
			CString csPageCount;
			csPageCount = pcsaArguments->GetAt( 1 );

			if ( 0 == csPageCount.Find( "1.0" ) )
			{
				csPageCount = "100";
			}
			else if ( 0 == csPageCount.Find( "1.1" ) )
			{
				csPageCount = "110";
			}

			csViewOutStuff.Format( " -G %s", csPageCount );
			csSummaryCommand = csSummaryCommand + csViewOutStuff;

		}
		break;

		case 3:		//Word count
		{
			int nWordCount=0;
			if ( -1 == pcsaArguments->GetAt( 1 ).Find( "FALSE" ) )
			{
				nWordCount = 1;
			}

			if ( -1 == pcsaArguments->GetAt( 2 ).Find( "FALSE" ) )
			{
				nWordCount+=2;
			}

			if ( -1 == pcsaArguments->GetAt( 3 ).Find( "FALSE" ) )
			{
				nWordCount+=4;
			}

			csViewOutStuff.Format( " -W %i", nWordCount );
			csSummaryCommand = csSummaryCommand + csViewOutStuff;

		}
		break;


		case 4:		//Title
		{
			csViewOutStuff.Format( " -T %s", pcsaArguments->GetAt( 1 ) );
			csSummaryCommand = csSummaryCommand + csViewOutStuff;
		}
		break;

		case 5:		//Subject -- XXX Add quotes
		{
			csViewOutStuff.Format( " -J \"%s\"", pcsaArguments->GetAt( 1 ) );
			csSummaryCommand = csSummaryCommand + csViewOutStuff;
		}
		break;

		case 6:		//Keywords
		{
			csViewOutStuff.Format( " -K \"%s\"", pcsaArguments->GetAt( 1 ) );
			csSummaryCommand = csSummaryCommand + csViewOutStuff;
		}
		break;

		case 7:		//Author
		{
			csViewOutStuff.Format( " -A \"%s\"", pcsaArguments->GetAt( 1 ) );
			csSummaryCommand = csSummaryCommand + csViewOutStuff;
		}
		break;

		case 8:		//Comments
		{
			csViewOutStuff.Format( " -O \"%s\"", pcsaArguments->GetAt( 1 ) );
			csSummaryCommand = csSummaryCommand + csViewOutStuff;
		}
		break;

		case 9:		//Creating app
		{
			csViewOutStuff.Format( " -N %s", pcsaArguments->GetAt( 1 ) );
			csSummaryCommand = csSummaryCommand + csViewOutStuff;
		}
		break;

		case 10:	//Security
		case 11:	//Last saved by
		case 12:	//Last saved time/date
		case 13:	//Create time/date
		case 14:	//Last printed
		case 15:	//Character count
		case 16:	//Codepage
		{
			csViewOutStuff.Format( "   // APIGen has not yet implemented this method." );
			pcsaBody->Add(csViewOutStuff);
		}
		break;

	}

	pcsaBody->RemoveAll();
	pcsaBody->Add(csSummaryCommand);

	pcsaArguments->RemoveAll();
}




void CAG_MSI_SUMMARY_INFO::finalize(CStringArray* pcsaBody)
{
	pcsaBody->Add( "" );
}

void CAG_MSI_SUMMARY_INFO::declareVariable(AG_VARIABLE agVariable,
										  CStringArray* pcsaHeader,
										  bool* bValue)
{
	CString csLocal;
	*bValue = TRUE;
	
	switch ( agVariable )
	{
		case AG_TASK_ID:
		{
			csLocal.Format( "   Dim csTaskID");
		}
		break;

		case AG_UTILBUFFER:
		{
			csLocal.Format( "   Dim csBuffer");
		}
		break;

		case AG_BUFFER_SIZE:
		{
			csLocal.Format( "   Dim nBufferSize");
		}
		break;

		case AG_XML_DATA:
		{
			csLocal.Format( "   Dim XMLData");
		}
		break;

		case AG_MAX_SIZE:
		{
			csLocal.Format( "   Dim nMaxSize");
		}
		break;

		case AG_DATA_REF:
		{
			csLocal.Format( "   Dim csDataRef");
		}
		break;

		case AG_PATH:
		{
			csLocal.Format( "   Dim csPath");
		}
		break;

		case AG_TIMEOUT:
		{
			csLocal.Format( "   Dim nTimeout");
		}
		break;

	}

	pcsaHeader->Add(csLocal);

}


void CAG_MSI_SUMMARY_INFO::checkDebug( bool b_Debug, CString csFunctionName, CStringArray* pcsaBody )
{
}


void CAG_MSI_SUMMARY_INFO::resetVariableFlags()
{
	b_csTaskID=FALSE;
	b_csBuffer=FALSE;
	b_nBufferSize=FALSE;
	b_XMLData=FALSE;
	b_nMaxSize=FALSE;
	b_nTimeout=FALSE;
	b_csDataRef=FALSE;
	b_csPath=FALSE;

	b_Debug=FALSE;
}


void CAG_MSI_SUMMARY_INFO::loadLanguageList(CListBox* listTranslateLanguage)
{
	int nPos = 0;

	listTranslateLanguage->ResetContent();
	listTranslateLanguage->InsertString( nPos++, "DOS Command" );
//	listTranslateLanguage->InsertString( nPos++, "VBScript" );
//	listTranslateLanguage->InsertString( nPos++, "Windows Script" );
	listTranslateLanguage->SetCurSel(0);

}

void CAG_MSI_SUMMARY_INFO::loadTerminalTypeList(CListBox* listTerminalTypes)
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


void CAG_MSI_SUMMARY_INFO::loadFunctionList(CListBox* listTranslateFunction)
{
	csaFunctions.RemoveAll();

	listTranslateFunction->ResetContent();

	csaFunctions.Add("Platform/Language");
	csaFunctions.Add("Revision number");
	csaFunctions.Add("Page count");
	csaFunctions.Add("Word count");
	csaFunctions.Add("Title");
	csaFunctions.Add("Subject");
	csaFunctions.Add("Keywords");
	csaFunctions.Add("Author");
	csaFunctions.Add("Comments");
	csaFunctions.Add("Creating app");
	csaFunctions.Add("Security");
	csaFunctions.Add("Last saved by");
	csaFunctions.Add("Last saved time/date");
	csaFunctions.Add("Create time/date");
	csaFunctions.Add("Last printed");
	csaFunctions.Add("Character count");
	csaFunctions.Add("Codepage");

	listTranslateFunction->ResetContent();	
	
	for (int k=0; k<csaFunctions.GetSize(); k++)
	{
		listTranslateFunction->AddString( csaFunctions.GetAt(k) );
	}

	listTranslateFunction->SetCurSel(0);

}
