// Static Model
#include "stdafx.h"
#include "apigen.h"

#include "CAG_MSI_CUSTOM_WS.h"

CAG_MSI_CUSTOM_WS::CAG_MSI_CUSTOM_WS()
{
	APIFlavor=MSI_CUSTOM_API;
	resetVariableFlags();	
}

CAG_MSI_CUSTOM_WS::~CAG_MSI_CUSTOM_WS()
{
	
}


void CAG_MSI_CUSTOM_WS::generateHeader(CStringArray* pcsaHeader,
										 CStringArray* pcsaBody)
{

	// output to Translator's output window
	CString csViewOutStuff;
	pcsaHeader->Add("' *********************************************************************APIGen");
	pcsaHeader->Add("'                Attachmate Windows Script");
	pcsaHeader->Add("'             MSI Installer Database Application");
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

	pcsaHeader->Add("Option Explicit");
	pcsaHeader->Add("");
	pcsaHeader->Add("On Error Resume Next");
	pcsaHeader->Add("");
	pcsaHeader->Add("Dim installer : Set installer = Nothing");
	pcsaHeader->Add( "Dim product, products, info, productList, version");
	pcsaHeader->Add( "");
	pcsaHeader->Add( "");
	pcsaHeader->Add( "");
	pcsaHeader->Add( "");

	pcsaBody->Add("");
	pcsaBody->Add("");
	pcsaBody->Add("Set installer = Wscript.CreateObject(\"WindowsInstaller.Installer\") : CheckError");
	pcsaBody->Add( "");
	pcsaBody->Add( "Set products = installer.Products : CheckError");
	pcsaBody->Add( "");
	pcsaBody->Add( "");

}



void CAG_MSI_CUSTOM_WS::appendBody(int nFunctionNum,
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
		CString csArg1, csArg2, csArg3, csArg4;


		switch ( nFunctionNum )
		{
			case 0:     //MsiAdvertiseProduct
			{

				if ( !b_csPackagePath )
				{
					declareVariable( AG_PACKAGE_PATH, pcsaHeader, &b_csPackagePath );
				}

				if ( !b_csScriptPath )
				{
					declareVariable( AG_SCRIPT_PATH, pcsaHeader, &b_csScriptPath );
				}

				if ( !b_csTransforms )
				{
					declareVariable( AG_TRANSFORMS, pcsaHeader, &b_csTransforms );
				}
				
				if ( !b_nStatus )
				{
					declareVariable( AG_STATUS, pcsaHeader, &b_nStatus );
				}
				
				csArg1 = pcsaArguments->GetAt(1);
				csArg2 = pcsaArguments->GetAt(2);
				csArg3 = pcsaArguments->GetAt(5);
				csArg4 = pcsaArguments->GetAt(6);
				csArg1.Replace( "\\", "\\\\" );
				csArg2.Replace( "\\", "\\\\" );
					
				if ( "TRUE" == pcsaArguments->GetAt(3) )
				{
					csArg3 = "@" + csArg3;
				}

				if ( "TRUE" == pcsaArguments->GetAt(4) )
				{
					csArg3 = "|" + csArg3;
				}

				csViewOutStuff.Format( "     csPackagePath = \"%s\"", csArg1 );
				pcsaBody->Add(csViewOutStuff);

				csViewOutStuff.Format( "     csScriptPath = \"%s\"", csArg2 );
				pcsaBody->Add(csViewOutStuff);

				csViewOutStuff.Format( "     csTransforms = \"%s\"", csArg3 );
				pcsaBody->Add(csViewOutStuff);


				csViewOutStuff.Format( "   nStatus = pMSI->MsiAdvertiseProduct( csPackagePath, csScriptPath, csTransforms, %s )", csArg4 );
				pcsaBody->Add(csViewOutStuff);

				csViewOutStuff.Format( " " );
				pcsaBody->Add(csViewOutStuff);

			}
			break;

			case 1:     //MsiAdvertiseProductEx
			{
				csArg1 = pcsaArguments->GetAt(1);
				csArg2 = pcsaArguments->GetAt(2);
				csArg3 = pcsaArguments->GetAt(5);
				csArg4 = pcsaArguments->GetAt(6);
				csArg1.Replace( "\\", "\\\\" );
				csArg2.Replace( "\\", "\\\\" );
					
				if ( "TRUE" == pcsaArguments->GetAt(3) )
				{
					csArg3 = "@" + csArg3;
				}

				if ( "TRUE" == pcsaArguments->GetAt(4) )
				{
					csArg3 = "|" + csArg3;
				}

				csViewOutStuff.Format( "   nStatus = pMSI->MsiAdvertiseProduct( \"%s\", \"%s\", \"%s\", %s, %s, %s );", 
											csArg1, csArg2, csArg3, csArg4, pcsaArguments->GetAt(7), pcsaArguments->GetAt(8) );
				pcsaBody->Add(csViewOutStuff);

				csViewOutStuff.Format( " " );
				pcsaBody->Add(csViewOutStuff);

			}
			break;

			case 17:     //MsiEnumFeatures
			{
				if ( !b_csProductName )
				{
					declareVariable( AG_PRODUCT_NAME, pcsaHeader, &b_csProductName );
				}

				if ( !b_nFeatureIndex )
				{
					declareVariable( AG_FEATURE_INDEX, pcsaHeader, &b_nFeatureIndex );
				}

				if ( !b_bRet )
				{
					declareVariable( AG_RETURN, pcsaHeader, &b_bRet );
				}

				csViewOutStuff.Format( "     csProductName = \"%s\";", pcsaArguments->GetAt(1) );
				pcsaBody->Add(csViewOutStuff);

				csViewOutStuff.Format( "     nFeatureIndex = \"%s\";", pcsaArguments->GetAt(2) );
				pcsaBody->Add(csViewOutStuff);
				
				csViewOutStuff.Format( "   bRet = pMSI->MsiEnumFeatures( csProductName, nFeatureIndex, XXX, YYY );"); 
				pcsaBody->Add(csViewOutStuff);

				csViewOutStuff.Format( " " );
				pcsaBody->Add(csViewOutStuff);

			}
			break;

			case 2:     //MsiAdvertiseScript
			case 3:     //MsiApplyMultiplePatches
			case 4:     //MsiCloseAllHandles
			case 5:     //MsiCloseHandle
			case 6:     //MsiCreateRecord
			case 7:     //MsiDatabaseGetPrimaryKeys
			case 8:     //MsiDatabaseIsTablePersistent
			case 9:     //MsiDatabaseOpenView
			case 10:     //MsiDetermineApplicablePatches
			case 11:     //MsiDeterminePatchSequence
			case 12:     //MsiDoAction
			case 13:     //MsiEnumClients
			case 14:     //MsiEnumComponentCosts
			case 15:     //MsiEnumComponentQualifiers
			case 16:     //MsiEnumComponents
			case 18:     //MsiEnumPatches
			case 19:     //MsiEnumPatchesEx
			case 20:     //MsiEnumProducts
			case 21:     //MsiEnumProductsEx
			case 22:     //MsiEnumRelatedProducts
			case 23:     //MsiEvaluationCondition
			case 24:     //MsiExtractPatchXMLData
			case 25:     //MsiFormatRecord
			case 26:     //MsiGetActiveDatabase
			case 27:     //MsiGetComponentPath
			case 28:     //MsiGetComponentState
			case 29:     //MsiGetFeatureCost
			case 30:     //MsiGetFeatureState
			case 31:     //MsiGetFeatureUsage
			case 32:     //MsiGetFeatureValidStates
			case 33:     //MsiGetFileHash
			case 34:     //MsiGetFileSignatureInformation
			case 35:     //MsiGetFileVersion
			case 36:     //MsiGetLanguage
			case 37:     //MsiGetLastErrorRecord
			case 38:     //MsiGetMode
			case 39:     //MsiGetPatchInfoEx
			case 40:     //MsiGetProductInfo
			case 41:     //MsiGetProductInfoEx
			case 42:     //MsiGetProductInfoFromScript
			case 43:     //MsiGetProperty
			case 44:     //MsiGetShortcutTarget
			case 45:     //MsiGetSourcePath
			case 46:     //MsiGetSummaryInformation
			case 47:     //MsiGetTargetPath
			case 48:     //MsiGetUserInfo
			case 49:     //MsiIsProductElevated
			case 50:     //MsiLocateComponent
			case 51:     //MsiOpenPackageEx
			case 52:     //MsiProcessAdvertiseScript
			case 53:     //MsiProcessMessage
			case 54:     //MsiProvideAssembly
			case 55:     //MsiProvideComponent	// only if it doesn't start another installation
			case 56:     //MsiProvideQualifiedComponent	// only if it doesn't start another installation
			case 57:     //MsiProvideQualifiedComponentEx	// only if it doesn't start another installation
			case 58:     //MsiQueryComponentState
			case 59:     //MsiQueryFeatureState
			case 60:     //MsiQueryFeatureStateEx
			case 61:     //MsiQueryProductState
			case 62:     //MsiRecordClearData
			case 63:     //MsiRecordDataSize
			case 64:     //MsiRecordGetFieldCount
			case 65:     //MsiRecordGetInteger
			case 66:     //MsiRecordGetString
			case 67:     //MsiRecordIsNull
			case 68:     //MsiRecordReadStream
			case 69:     //MsiRecordSetInteger
			case 70:     //MsiRecordSetStream
			case 71:     //MsiRecordSetString
			case 72:     //MsiRemovePatches
			case 73:     //MsiSequence
			case 74:     //MsiSetComponentState
			case 75:     //MsiSetFeatureAttributes
			case 76:     //MsiSetFeatureState
			case 77:     //MsiSetInstallLevel
			case 78:     //MsiSetMode
			case 79:     //MsiSetProperty
			case 80:     //MsiSetTargetPath
			case 81:     //MsiSourceListAddMediaDisk
			case 82:     //MsiSourceListAddSource
			case 83:     //MsiSourceListAddSourceEx
			case 84:     //MsiSourceListClearAll
			case 85:     //MsiSourceListClearAllEx
			case 86:     //MsiSourceListClearSource
			case 87:     //MsiSourceListEnumMediaDisks
			case 88:     //MsiSourceListEnumSources
			case 89:     //MsiSourceListForceResolution
			case 90:     //MsiSourceListForceResolutionEx
			case 91:     //MsiSourceListGetInfo
			case 92:     //MsiSourceListSetInfo
			case 93:     //MsiSummaryInfoGetProperty
			case 94:     //MsiSummaryInfoGetPropertyCount
			case 95:     //MsiSummaryInfoPersist
			case 96:     //MsiSummaryInfoSetProperty
			case 97:     //MsiVerifyDiskSpace
			case 98:     //MsiViewClose
			case 99:     //MsiViewExecute
			case 100:     //MsiViewFetch
			case 101:     //MsiViewGetColumnInfo
			case 102:     //MsiViewGetError
			case 103:     //MsiViewModify
			{
				csViewOutStuff.Format( "   // APIGen has not yet implemented this method." );
				pcsaBody->Add(csViewOutStuff);
			}
			break;
		}
	}

	pcsaArguments->RemoveAll();
}




void CAG_MSI_CUSTOM_WS::finalize(CStringArray* pcsaBody)
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
	pcsaBody->Add( "Sub CheckError" );
	pcsaBody->Add( "	Dim message, errRec" );
	pcsaBody->Add( "	If Err = 0 Then Exit Sub" );
	pcsaBody->Add( "	message = Err.Source & \" \" & Hex(Err) & \": \" & Err.Description" );
	pcsaBody->Add( "	If Not installer Is Nothing Then" );
	pcsaBody->Add( "		Set errRec = installer.LastErrorRecord" );
	pcsaBody->Add( "		If Not errRec Is Nothing Then message = message & vbNewLine & errRec.FormatText" );
	pcsaBody->Add( "	End If" );
	pcsaBody->Add( "	Wscript.Echo message" );
	pcsaBody->Add( "	Wscript.Quit 2" );
	pcsaBody->Add( "End Sub" );
}

void CAG_MSI_CUSTOM_WS::declareVariable(AG_VARIABLE agVariable,
										  CStringArray* pcsaHeader,
										  bool* bValue)
{
	CString csLocal;
	*bValue = TRUE;
	
	switch ( agVariable )
	{
		case AG_TASK_ID:
		{
			csLocal.Format( "   Dim csTaskID As String");
		}
		break;

		case AG_UTILBUFFER:
		{
			csLocal.Format( "   Dim csBuffer As String");
		}
		break;

		case AG_BUFFER_SIZE:
		{
			csLocal.Format( "   Dim nBufferSize As Integer");
		}
		break;

		case AG_XML_DATA:
		{
			csLocal.Format( "   Dim XMLData");
		}
		break;

		case AG_MAX_SIZE:
		{
			csLocal.Format( "   Dim nMaxSize As Integer");
		}
		break;

		case AG_DATA_REF:
		{
			csLocal.Format( "   Dim csDataRef As String");
		}
		break;

		case AG_PATH:
		{
			csLocal.Format( "   Dim csPath As String");
		}
		break;

		case AG_TIMEOUT:
		{
			csLocal.Format( "   Dim nTimeout As Integer");
		}
		break;

		case AG_PACKAGE_PATH:
		{
			csLocal.Format( "   Dim csPackagePath As String");
		}
		break;

		case AG_SCRIPT_PATH:
		{
			csLocal.Format( "   Dim csScriptPath As String");
		}
		break;

		case AG_STATUS:
		{
			csLocal.Format( "   Dim nStatus As Integer");
		}
		break;

		case AG_TRANSFORMS:
		{
			csLocal.Format( "   Dim csTransforms As TRANSFORMS");
		}
		break;

		case AG_PRODUCT_NAME:
		{
			csLocal.Format( "   Dim csProductName As String");
		}
		break;

		case AG_FEATURE_NAME:
		{
			csLocal.Format( "   Dim csFeatureName As String");
		}
		break;

		case AG_FEATURE_INDEX:
		{
			csLocal.Format( "   Dim nFeatureIndex As Integer");
		}
		break;

		case AG_INSTALLSTATE:
		{
			csLocal.Format( "   Dim uInstallState As INSTALLSTATE");
		}
		break;

		case AG_RETURN:
		{
			csLocal.Format( "   Dim bRet As Boolean");
		}
		break;

	}

	pcsaHeader->Add(csLocal);

}


void CAG_MSI_CUSTOM_WS::checkDebug( bool b_Debug, CString csFunctionName, CStringArray* pcsaBody )
{
	CString csLocal;
	
	if ( b_Debug )
	{
		csLocal.Format( "    MsgBox \"%s\"", csFunctionName );
		pcsaBody->Add(csLocal);
	}
}


void CAG_MSI_CUSTOM_WS::resetVariableFlags()
{
	b_csTaskID=FALSE;
	b_csBuffer=FALSE;
	b_nBufferSize=FALSE;
	b_XMLData=FALSE;
	b_nMaxSize=FALSE;
	b_nTimeout=FALSE;
	b_csDataRef=FALSE;
	b_csPath=FALSE;

	b_csPackagePath=FALSE;
	b_csScriptPath=FALSE;
	b_csTransforms=FALSE;

	b_Debug=FALSE;
}


void CAG_MSI_CUSTOM_WS::loadLanguageList(CListBox* listTranslateLanguage)
{
	int nPos = 0;

	listTranslateLanguage->ResetContent();
	listTranslateLanguage->InsertString( nPos++, "C++" );
	listTranslateLanguage->InsertString( nPos++, "VBScript" );
	listTranslateLanguage->InsertString( nPos++, "Windows Script" );
	listTranslateLanguage->SetCurSel(0);

}

void CAG_MSI_CUSTOM_WS::loadTerminalTypeList(CListBox* listTerminalTypes)
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


void CAG_MSI_CUSTOM_WS::loadFunctionList(CListBox* listTranslateFunction)
{
	csaFunctions.RemoveAll();

	listTranslateFunction->ResetContent();

	csaFunctions.Add("MsiAdvertiseProduct");
	csaFunctions.Add("MsiAdvertiseProductEx");
	csaFunctions.Add("MsiAdvertiseScript");
	csaFunctions.Add("MsiApplyMultiplePatches");
	csaFunctions.Add("MsiCloseAllHandles");
	csaFunctions.Add("MsiCloseHandle");
	csaFunctions.Add("MsiCreateRecord");
	csaFunctions.Add("MsiDatabaseGetPrimaryKeys");
	csaFunctions.Add("MsiDatabaseIsTablePersistent");
	csaFunctions.Add("MsiDatabaseOpenView");
	csaFunctions.Add("MsiDetermineApplicablePatches");
	csaFunctions.Add("MsiDeterminePatchSequence");
	csaFunctions.Add("MsiDoAction");
	csaFunctions.Add("MsiEnumClients");
	csaFunctions.Add("MsiEnumComponentCosts");
	csaFunctions.Add("MsiEnumComponentQualifiers");
	csaFunctions.Add("MsiEnumComponents");
	csaFunctions.Add("MsiEnumFeatures");
	csaFunctions.Add("MsiEnumPatches");
	csaFunctions.Add("MsiEnumPatchesEx");
	csaFunctions.Add("MsiEnumProducts");
	csaFunctions.Add("MsiEnumProductsEx");
	csaFunctions.Add("MsiEnumRelatedProducts");
	csaFunctions.Add("MsiEvaluationCondition");
	csaFunctions.Add("MsiExtractPatchXMLData");
	csaFunctions.Add("MsiFormatRecord");
	csaFunctions.Add("MsiGetActiveDatabase");
	csaFunctions.Add("MsiGetComponentPath");
	csaFunctions.Add("MsiGetComponentState");
	csaFunctions.Add("MsiGetFeatureCost");
	csaFunctions.Add("MsiGetFeatureState");
	csaFunctions.Add("MsiGetFeatureUsage");
	csaFunctions.Add("MsiGetFeatureValidStates");
	csaFunctions.Add("MsiGetFileHash");
	csaFunctions.Add("MsiGetFileSignatureInformation");
	csaFunctions.Add("MsiGetFileVersion");
	csaFunctions.Add("MsiGetLanguage");
	csaFunctions.Add("MsiGetLastErrorRecord");
	csaFunctions.Add("MsiGetMode");
	csaFunctions.Add("MsiGetPatchInfoEx");
	csaFunctions.Add("MsiGetProductInfo");
	csaFunctions.Add("MsiGetProductInfoEx");
	csaFunctions.Add("MsiGetProductInfoFromScript");
	csaFunctions.Add("MsiGetProperty");
	csaFunctions.Add("MsiGetShortcutTarget");
	csaFunctions.Add("MsiGetSourcePath");
	csaFunctions.Add("MsiGetSummaryInformation");
	csaFunctions.Add("MsiGetTargetPath");
	csaFunctions.Add("MsiGetUserInfo");
	csaFunctions.Add("MsiIsProductElevated");
	csaFunctions.Add("MsiLocateComponent");
	csaFunctions.Add("MsiOpenPackageEx");
	csaFunctions.Add("MsiProcessAdvertiseScript");
	csaFunctions.Add("MsiProcessMessage");
	csaFunctions.Add("MsiProvideAssembly");
	csaFunctions.Add("MsiProvideComponent");
	csaFunctions.Add("MsiProvideQualifiedComponent");
	csaFunctions.Add("MsiProvideQualifiedComponentEx");
	csaFunctions.Add("MsiQueryComponentState");
	csaFunctions.Add("MsiQueryFeatureState");
	csaFunctions.Add("MsiQueryFeatureStateEx");
	csaFunctions.Add("MsiQueryProductState");
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
	csaFunctions.Add("MsiRemovePatches");
	csaFunctions.Add("MsiSequence");
	csaFunctions.Add("MsiSetComponentState");
	csaFunctions.Add("MsiSetFeatureAttributes");
	csaFunctions.Add("MsiSetFeatureState");
	csaFunctions.Add("MsiSetInstallLevel");
	csaFunctions.Add("MsiSetMode");
	csaFunctions.Add("MsiSetProperty");
	csaFunctions.Add("MsiSetTargetPath");
	csaFunctions.Add("MsiSourceListAddMediaDisk");
	csaFunctions.Add("MsiSourceListAddSource");
	csaFunctions.Add("MsiSourceListAddSourceEx");
	csaFunctions.Add("MsiSourceListClearAll");
	csaFunctions.Add("MsiSourceListClearAllEx");
	csaFunctions.Add("MsiSourceListClearSource");
	csaFunctions.Add("MsiSourceListEnumMediaDisks");
	csaFunctions.Add("MsiSourceListEnumSources");
	csaFunctions.Add("MsiSourceListForceResolution");
	csaFunctions.Add("MsiSourceListForceResolutionEx");
	csaFunctions.Add("MsiSourceListGetInfo");
	csaFunctions.Add("MsiSourceListSetInfo");
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

	listTranslateFunction->ResetContent();	
	
	for (int k=0; k<csaFunctions.GetSize(); k++)
	{
		listTranslateFunction->AddString( csaFunctions.GetAt(k) );
	}

	listTranslateFunction->SetCurSel(0);

}
