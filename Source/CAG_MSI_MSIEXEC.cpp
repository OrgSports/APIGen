// Static Model
#include "stdafx.h"
#include "apigen.h"

#include "CAG_MSI_MSIEXEC.h"

CAG_MSI_MSIEXEC::CAG_MSI_MSIEXEC()
{
	APIFlavor=MSI_EXEC_API;
	resetVariableFlags();	
}

CAG_MSI_MSIEXEC::~CAG_MSI_MSIEXEC()
{
	
}


void CAG_MSI_MSIEXEC::generateHeader(CStringArray* pcsaHeader,
										 CStringArray* pcsaBody)
{

	// output to Translator's output window
	CString csViewOutStuff;
	pcsaHeader->Add("<%@ Language=VBScript %>");

	pcsaHeader->Add("' *********************************************************************APIGen");
	pcsaHeader->Add("'               Attachmate MSI MSIExec Command Line");
	pcsaHeader->Add("' ");
	pcsaHeader->Add("'  This file is an application that uses the Microsoft Installer API.");
	pcsaHeader->Add("'     1. What product / componentes must be installed?  If it is important, where must");
	pcsaHeader->Add("'        this file be placed and how should it be launched?");
	pcsaHeader->Add("'     2. ");
	pcsaHeader->Add("'        ");

	time_t ltime;
	time( &ltime );

	pcsaHeader->Add( "'" );
	csViewOutStuff.Format( "'   Generated:   %s", ctime( &ltime ) );
	pcsaHeader->Add(csViewOutStuff);
	pcsaHeader->Add( "'" );
	pcsaHeader->Add( "'" );
	pcsaHeader->Add( "' ****************************************************************************");

	pcsaHeader->Add("<HTML>");
	pcsaHeader->Add("<HEAD>");
	pcsaHeader->Add("</HEAD>");
	pcsaHeader->Add("<BODY>");
	pcsaHeader->Add("<PRE>");
	pcsaHeader->Add("<%");

	pcsaHeader->Add( "" );
	pcsaHeader->Add( "Response.Buffer = true");
	pcsaHeader->Add( "On Error Resume Next");
	pcsaHeader->Add( "" );
	pcsaHeader->Add( "Dim connector");

	pcsaBody->Add("");
	pcsaBody->Add( "Set connector = CreateObject(\"Atm.ScreenConnector.1\")");
	pcsaBody->Add("");
	pcsaBody->Add( "");
	pcsaBody->Add( "   if Err.number <> 0 then" );
	pcsaBody->Add( "       Response.Write \"Error in CreateObject\"" );
	pcsaBody->Add( "       Response.Write \"Return Code = \" & Err.number & \"<BR>\"" );
	pcsaBody->Add( "   else" );
	pcsaBody->Add( "       Response.Write \"Successful CreateObject \" & \"<BR>\"" );
	pcsaBody->Add( "   end if" );
	pcsaBody->Add( "");

}



void CAG_MSI_MSIEXEC::appendBody(int nFunctionNum,
									 bool bPromptForValues,
									 CStringArray* pcsaArguments,
									 CStringArray* pcsaHeader,
									 CStringArray* pcsaBody)
{
	CString csViewOutStuff;
	CString csFunctionName;

	csFunctionName = pcsaArguments->GetAt( 0 );

	if ( csFunctionName.Find( "Debug", 0 ) != -1 )
	{
	
		if ( b_Debug )
		{
			b_Debug = FALSE;
		}
		else
		{
			b_Debug = TRUE;
		}
	
	}
	else
	{

		pcsaBody->Add("" );

		csViewOutStuff.Format( "'   *** %s", csFunctionName );
		pcsaBody->Add(csViewOutStuff);

		checkDebug( b_Debug, csFunctionName, pcsaBody );

		CString	csLocal;

		switch ( nFunctionNum )
		{
			case 0:	//MsiCreateRecord
			case 1:	//MsiCreateTransformSummaryInfo
			case 2:	//MsiDatabaseApplyTransform
			case 3:	//MsiDatabaseCommit
			case 4:	//MsiDatabaseExport
			case 5:	//MsiDatabaseGenerateTransform
			case 6:	//MsiDatabaseGetPrimaryKeys
			case 7:	//MsiDatabaseImport
			case 8:	//MsiDatabaseIsTablePersistent
			case 9:	//MsiDatabaseMerge
			case 10:	//MsiDatabaseOpenView
			case 11:	//MsiDoAction
			case 12:	//MsiEnableUIPreview
			case 13:	//MsiEnumComponentCosts
			case 14:	//MsiEvaluationCondition
			case 15:	//MsiFormatRecord
			case 16:	//MsiGetActiveDatabase
			case 17:	//MsiGetComponentState
			case 18:	//MsiGetDatabaseState
			case 19:	//MsiGetFeatureCost
			case 20:	//MsiGetFeatureState
			case 21:	//MsiGetFeatureValidStates
			case 22:	//MsiGetLanguage
			case 23:	//MsiGetLastErrorRecord
			case 24:	//MsiGetMode
			case 25:	//MsiGetMode
			case 26:	//MsiGetProperty
			case 27:	//MsiGetSourcePath
			case 28:	//MsiGetSummaryInformation
			case 29:	//MsiGetTargetPath
			case 30:	//MsiOpenDatabase
			case 31:	//MsiPreviewBillboard
			case 32:	//MsiPreviewDialog
			case 33:	//MsiProcessMessage
			case 34:	//MsiRecordClearData
			case 35:	//MsiRecordDataSize
			case 36:	//MsiRecordGetFieldCount
			case 37:	//MsiRecordGetInteger
			case 38:	//MsiRecordGetString
			case 39:	//MsiRecordIsNull
			case 40:	//MsiRecordReadStream
			case 41:	//MsiRecordSetInteger
			case 42:	//MsiRecordSetStream
			case 43:	//MsiRecordSetString
			case 44:	//MsiSequence
			case 45:	//MsiSetComponentState
			case 46:	//MsiSetFeatureAttributes
			case 47:	//MsiSetFeatureState
			case 48:	//MsiSetIinstallLevel
			case 49:	//MsiSetMode
			case 50:	//MsiSetProperty
			case 51:	//MsiSetTargetPath
			case 52:	//MsiSummaryInfoGetProperty
			case 53:	//MsiSummaryInfoGetPropertyCount
			case 54:	//MsiSummaryInfoPersist
			case 55:	//MsiSummaryInfoSetProperty
			case 56:	//MsiVerifyDiskSpace
			case 57:	//MsiViewClose
			case 58:	//MsiViewExecute
			case 59:	//MsiViewFetch
			case 60:	//MsiViewGetColumnInfo
			case 61:	//MsiViewGetError
			case 62:	//MsiViewModify
			{
				csViewOutStuff.Format( "   // APIGen has not yet implemented this method." );
				pcsaBody->Add(csViewOutStuff);
			}
			break;


			case 63:	//debug
			{
				csViewOutStuff.Format( "   System.out.println( \"************ Toggling trace output ************\" );" );
				pcsaBody->Add(csViewOutStuff);
				pcsaBody->Add( "");
			}
			break;

		}
	}

	pcsaArguments->RemoveAll();
}




void CAG_MSI_MSIEXEC::finalize(CStringArray* pcsaBody)
{
	if ( b_csTaskID )
	{
		pcsaBody->Add( "   csTaskID=Nothing" );
	}

	if ( b_csBuffer )
	{
		pcsaBody->Add( "   set csBuffer = nothing" );
	}

	if ( b_nBufferSize )
	{
		pcsaBody->Add( "   set nBufferSize = nothing" );
	}

	if ( b_XMLData )
	{
		pcsaBody->Add( "   set XMLData = nothing" );
	}

	if ( b_nMaxSize )
	{
		pcsaBody->Add( "   set nMaxSize = nothing" );
	}

	if ( b_nTimeout )
	{
		pcsaBody->Add( "   set nTimeout = nothing" );
	}

	if ( b_csDataRef )
	{
		pcsaBody->Add( "   set csDataRef = nothing" );
	}

	if ( b_csPath )
	{
		pcsaBody->Add( "   set csPath = nothing" );
	}

	if ( b_Debug )
	{
		pcsaBody->Add( "   set Debug = nothing" );
	}

	pcsaBody->Add( "" );
//	pcsaBody->Add( "   session.Abandon" );
//	pcsaBody->Add( "" );
	pcsaBody->Add( "%>" );
	pcsaBody->Add( "</PRE>" );
	pcsaBody->Add( "</BODY>" );
	pcsaBody->Add( "</HTML>" );
}

void CAG_MSI_MSIEXEC::declareVariable(AG_VARIABLE agVariable,
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


void CAG_MSI_MSIEXEC::checkDebug( bool b_Debug, CString csFunctionName, CStringArray* pcsaBody )
{
	CString csLocal;
	
	if ( b_Debug )
	{
		csLocal.Format( "    MsgBox \"%s\"", csFunctionName );
		pcsaBody->Add(csLocal);
	}
}


void CAG_MSI_MSIEXEC::resetVariableFlags()
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


void CAG_MSI_MSIEXEC::loadLanguageList(CListBox* listTranslateLanguage)
{
	int nPos = 0;

	listTranslateLanguage->ResetContent();
	listTranslateLanguage->InsertString( nPos++, "DOS Command" );
//	listTranslateLanguage->InsertString( nPos++, "VBScript" );
//	listTranslateLanguage->InsertString( nPos++, "Windows Script" );
	listTranslateLanguage->SetCurSel(0);

}

void CAG_MSI_MSIEXEC::loadTerminalTypeList(CListBox* listTerminalTypes)
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


void CAG_MSI_MSIEXEC::loadFunctionList(CListBox* listTranslateFunction)
{
	csaFunctions.RemoveAll();

	listTranslateFunction->ResetContent();

	csaFunctions.Add("Install-Configure");
	csaFunctions.Add("Repair");
	csaFunctions.Add("Uninstall");
	csaFunctions.Add("Advertise");
	csaFunctions.Add("Write log info");
	csaFunctions.Add("Generate status file");
	csaFunctions.Add("Apply patch");
	csaFunctions.Add("Set UI level");
	csaFunctions.Add("Display copyright");
	csaFunctions.Add("Register modules");
	csaFunctions.Add("Unregister modules");
	csaFunctions.Add("Advertise new instance");
	csaFunctions.Add("Specify instance");
	csaFunctions.Add("Help");
	csaFunctions.Add("Quiet");
	csaFunctions.Add("Passive");
	csaFunctions.Add("MsiGetComponentState");
	csaFunctions.Add("MsiGetDatabaseState");
	csaFunctions.Add("MsiGetFeatureCost");
	csaFunctions.Add("MsiGetFeatureState");
	csaFunctions.Add("MsiGetFeatureValidStates");
	csaFunctions.Add("MsiGetLanguage");
	csaFunctions.Add("MsiGetLastErrorRecord");
	csaFunctions.Add("MsiGetMode");
	csaFunctions.Add("MsiGetProperty");
	csaFunctions.Add("MsiGetSourcePath");
	csaFunctions.Add("MsiGetSummaryInformation");
	csaFunctions.Add("MsiGetTargetPath");
	csaFunctions.Add("MsiOpenDatabase");
	csaFunctions.Add("MsiPreviewBillboard");
	csaFunctions.Add("MsiPreviewDialog");
	csaFunctions.Add("MsiProcessMessage");
	csaFunctions.Add("MsiRecordClearData");
	csaFunctions.Add("MsiRecordDataSize");
	csaFunctions.Add("MsiRecordGetFieldCount");
	csaFunctions.Add("MsiRecordGetInteger");
	csaFunctions.Add("MsiRecordGetString");
	csaFunctions.Add("MsiRecordIsNull");
	csaFunctions.Add("MsiRecordReadStream");
	csaFunctions.Add("MsiRecordSetInteger");
	csaFunctions.Add("MsiRecordSetStream");
	csaFunctions.Add("MsiRecordSetString");
	csaFunctions.Add("MsiSequence");
	csaFunctions.Add("MsiSetComponentState");
	csaFunctions.Add("MsiSetFeatureAttributes");
	csaFunctions.Add("MsiSetFeatureState");
	csaFunctions.Add("MsiSetIinstallLevel");
	csaFunctions.Add("MsiSetMode");
	csaFunctions.Add("MsiSetProperty");
	csaFunctions.Add("MsiSetTargetPath");
	csaFunctions.Add("MsiSummaryInfoGetProperty");
	csaFunctions.Add("MsiSummaryInfoGetPropertyCount");
	csaFunctions.Add("MsiSummaryInfoPersist");
	csaFunctions.Add("MsiSummaryInfoSetProperty");
	csaFunctions.Add("MsiVerifyDiskSpace");
	csaFunctions.Add("MsiViewClose");
	csaFunctions.Add("MsiViewExecute");
	csaFunctions.Add("MsiViewFetch");
	csaFunctions.Add("MsiViewGetColumnInfo");
	csaFunctions.Add("MsiViewGetError");
	csaFunctions.Add("MsiViewModify");
	csaFunctions.Add("Debug");

	listTranslateFunction->ResetContent();	
	
	for (int k=0; k<csaFunctions.GetSize(); k++)
	{
		listTranslateFunction->AddString( csaFunctions.GetAt(k) );
	}

	listTranslateFunction->SetCurSel(0);

}
