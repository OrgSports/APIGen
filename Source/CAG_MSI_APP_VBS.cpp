// Static Model
#include "stdafx.h"
#include "apigen.h"

#include "CAG_MSI_APP_VBS.h"

CAG_MSI_APP_VBS::CAG_MSI_APP_VBS()
{
	APIFlavor=MSI_APP_API;
	resetVariableFlags();	
}

CAG_MSI_APP_VBS::~CAG_MSI_APP_VBS()
{
	
}


void CAG_MSI_APP_VBS::generateHeader(CStringArray* pcsaHeader,
										 CStringArray* pcsaBody)
{

	// output to Translator's output window
	CString csViewOutStuff;
	pcsaHeader->Add("' *********************************************************************APIGen");
	pcsaHeader->Add("'               Attachmate APIGenerator");
	pcsaHeader->Add("'              MSI VBS Installer Application");
	pcsaHeader->Add("' ");
	pcsaHeader->Add("'  This file uses the Microsoft Installer API in a freestanding installer.");
	pcsaHeader->Add("'  application.");
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



void CAG_MSI_APP_VBS::appendBody(int nFunctionNum,
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

				csViewOutStuff.Format( "     csPackagePath = \"%s\";", csArg1 );
				pcsaBody->Add(csViewOutStuff);

				csViewOutStuff.Format( "     csScriptPath = \"%s\";", csArg2 );
				pcsaBody->Add(csViewOutStuff);

				csViewOutStuff.Format( "     csTransforms = \"%s\";", csArg3 );
				pcsaBody->Add(csViewOutStuff);


				csViewOutStuff.Format( "   nStatus = pMSI->MsiAdvertiseProduct( csPackagePath, csScriptPath, csTransforms, %s );", csArg4 );
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

			case 53:     //MsiQueryFeatureState
			{
				if ( !b_csProductName )
				{
					declareVariable( AG_PRODUCT_NAME, pcsaHeader, &b_csProductName );
				}

				if ( !b_csFeatureName )
				{
					declareVariable( AG_FEATURE_NAME, pcsaHeader, &b_csFeatureName );
				}

				if ( !b_uFeatureState )
				{
					declareVariable( AG_FEATURE_STATE, pcsaHeader, &b_uFeatureState );
				}

				csViewOutStuff.Format( "     csProductName = \"%s\";", pcsaArguments->GetAt(1) );
				pcsaBody->Add(csViewOutStuff);

				csViewOutStuff.Format( "     csFeatureName = \"%s\";", pcsaArguments->GetAt(2) );
				pcsaBody->Add(csViewOutStuff);
				
				csViewOutStuff.Format( "   uFeatureState = pMSI->MsiQueryFeatureState( csProductName, csFeatureName );"); 
				pcsaBody->Add(csViewOutStuff);

				csViewOutStuff.Format( " " );
				pcsaBody->Add(csViewOutStuff);

			}
			break;

			case 73:     //MsiUseFeature
			{
				if ( !b_csProductName )
				{
					declareVariable( AG_PRODUCT_NAME, pcsaHeader, &b_csProductName );
				}

				if ( !b_csFeatureName )
				{
					declareVariable( AG_FEATURE_NAME, pcsaHeader, &b_csFeatureName );
				}

				if ( !b_uInstallState )
				{
					declareVariable( AG_INSTALLSTATE, pcsaHeader, &b_uInstallState );
				}

				csViewOutStuff.Format( "     csProductName = \"%s\";", pcsaArguments->GetAt(1) );
				pcsaBody->Add(csViewOutStuff);

				csViewOutStuff.Format( "     csFeatureName = \"%s\";", pcsaArguments->GetAt(2) );
				pcsaBody->Add(csViewOutStuff);
				
				csViewOutStuff.Format( "   uInstallState = pMSI->MsiUseFeature( csProductName, csFeatureName );"); 
				pcsaBody->Add(csViewOutStuff);

				csViewOutStuff.Format( " " );
				pcsaBody->Add(csViewOutStuff);

			}
			break;

			case 8:     //MsiConfigureFeature
			{
				if ( !b_csProductName )
				{
					declareVariable( AG_PRODUCT_NAME, pcsaHeader, &b_csProductName );
				}

				if ( !b_csFeatureName )
				{
					declareVariable( AG_FEATURE_NAME, pcsaHeader, &b_csFeatureName );
				}

				if ( !b_uInstallState )
				{
					declareVariable( AG_INSTALLSTATE, pcsaHeader, &b_uInstallState );
				}

				if ( !b_uRet )
				{
					declareVariable( AG_UINT_RETURN, pcsaHeader, &b_uRet );
				}

				csViewOutStuff.Format( "     csProductName = \"%s\";", pcsaArguments->GetAt(1) );
				pcsaBody->Add(csViewOutStuff);

				csViewOutStuff.Format( "     csFeatureName = \"%s\";", pcsaArguments->GetAt(2) );
				pcsaBody->Add(csViewOutStuff);
				
				csViewOutStuff.Format( "     uRet = \"%s\";", pcsaArguments->GetAt(3) );
				pcsaBody->Add(csViewOutStuff);

				csViewOutStuff.Format( "   uRet = pMSI->MsiConfigureFeature( csProductName, csFeatureName, uInstallState );"); 
				pcsaBody->Add(csViewOutStuff);

				csViewOutStuff.Format( " " );
				pcsaBody->Add(csViewOutStuff);

			}
			break;



			case 2:     //MsiAdvertiseScript
			case 3:     //MsiApplyMultiplePatches
			case 4:     //MsiApplyPatch
			case 5:     //MsiCloseAllHandles
			case 6:     //MsiCloseHandle
			case 7:     //MsiCollectUserInfo
			case 9:     //MsiConfigureProduct
			case 10:     //MsiConfigureProductEx
			case 11:     //MsiDetermineApplicablePatches
			case 12:     //MsiDeterminePatchSequence
			case 13:     //MsiEnableLog
			case 14:     //MsiEnumClients
			case 15:     //MsiEnumComponentQualifiers
			case 16:     //MsiEnumComponents
			case 18:     //MsiEnumPatches
			case 19:     //MsiEnumPatchesEx
			case 20:     //MsiEnumProducts
			case 21:     //MsiEnumProductsEx
			case 22:     //MsiEnumRelatedProducts
			case 23:     //MsiExtractPatchXMLData
			case 24:     //MsiGetComponentPath
			case 25:     //MsiGetFeatureInfo
			case 26:     //MsiGetFeatureUsage
			case 27:     //MsiGetFileHash
			case 28:     //MsiGetFileSignatureInformation
			case 29:     //MsiGetFileVersion
			case 30:     //MsiGetPatchInfo
			case 31:     //MsiGetPatchInfoEx
			case 32:     //MsiGetProductCode
			case 33:     //MsiGetProductInfo
			case 34:     //MsiGetProductInfoEx
			case 35:     //MsiGetProductInfoFromScript
			case 36:     //MsiGetProductProperty
			case 37:     //MsiGetShortcutTarget
			case 38:     //MsiGetUserInfo
			case 39:     //MsiInstallMissingComponent
			case 40:     //MsiInstallMissingFile
			case 41:     //MsiInstallProduct
			case 42:     //MsiIsProductElevated
			case 43:     //MsiLocateComponent
			case 44:     //MsiOpenPackage
			case 45:     //MsiOpenPackageEx
			case 46:     //MsiOpenProduct
			case 47:     //MsiProcessAdvertiseScript
			case 48:     //MsiProvideAssembly
			case 49:     //MsiProvideComponent
			case 50:     //MsiProvideQualifiedComponent
			case 51:     //MsiProvideQualifiedComponentEx
			case 52:     //MsiQueryComponentState
			case 54:     //MsiQueryFeatureStateEx
			case 55:     //MsiQueryProductState
			case 56:     //MsiReinstallFeature
			case 57:     //MsiReinstallProduct
			case 58:     //MsiRemovePatches
			case 59:     //MsiSetExternalUI
			case 60:     //MsiSetInternalUI
			case 61:     //MsiSourceListAddMediaDisk
			case 62:     //MsiSourceListAddSource
			case 63:     //MsiSourceListAddSourceEx
			case 64:     //MsiSourceListClearAll
			case 65:     //MsiSourceListClearAllEx
			case 66:     //MsiSourceListClearSource
			case 67:     //MsiSourceListEnumMediaDisks
			case 68:     //MsiSourceListEnumSources
			case 69:     //MsiSourceListForceResolution
			case 70:     //MsiSourceListForceResolutionEx
			case 71:     //MsiSourceListGetInfo
			case 72:     //MsiSourceListSetInfo
			case 74:     //MsiUseFeatureEx
			case 75:     //MsiVerifyPackage
			{
				csViewOutStuff.Format( "   // APIGen has not yet implemented this method." );
				pcsaBody->Add(csViewOutStuff);
			}
			break;

			case 76:	//debug
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




void CAG_MSI_APP_VBS::finalize(CStringArray* pcsaBody)
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

void CAG_MSI_APP_VBS::declareVariable(AG_VARIABLE agVariable,
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

		case AG_PACKAGE_PATH:
		{
			csLocal.Format( "   CString csPackagePath");
		}
		break;

		case AG_SCRIPT_PATH:
		{
			csLocal.Format( "   CString csScriptPath");
		}
		break;

		case AG_TRANSFORMS:
		{
			csLocal.Format( "   CString csTransforms");
		}
		break;

		case AG_PRODUCT_NAME:
		{
			csLocal.Format( "   CString csProductName");
		}
		break;

		case AG_FEATURE_NAME:
		{
			csLocal.Format( "   CString csFeatureName");
		}
		break;

		case AG_FEATURE_INDEX:
		{
			csLocal.Format( "   int b_nFeatureIndex");
		}
		break;

		case AG_INSTALLSTATE:
		{
			csLocal.Format( "   INSTALLSTATE uInstallState");
		}
		break;

		case AG_RETURN:
		{
			csLocal.Format( "   BOOL bRet");
		}
		break;

		case AG_UINT_RETURN:
		{
			csLocal.Format( "   UINT uRet");
		}
		break;

	}

	pcsaHeader->Add(csLocal);

}


void CAG_MSI_APP_VBS::checkDebug( bool b_Debug, CString csFunctionName, CStringArray* pcsaBody )
{
	CString csLocal;
	
	if ( b_Debug )
	{
		csLocal.Format( "    MsgBox \"%s\"", csFunctionName );
		pcsaBody->Add(csLocal);
	}
}


void CAG_MSI_APP_VBS::resetVariableFlags()
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

	b_csProductName=FALSE;
	b_uInstallState=FALSE;

	b_csFeatureName=FALSE;
	b_nFeatureIndex=FALSE;
	b_uFeatureState=FALSE;

	b_bRet=FALSE;
	b_uRet=FALSE;

	b_Debug=FALSE;
}


void CAG_MSI_APP_VBS::loadLanguageList(CListBox* listTranslateLanguage)
{
	int nPos = 0;

	listTranslateLanguage->ResetContent();
	listTranslateLanguage->InsertString( nPos++, "C++" );
	listTranslateLanguage->InsertString( nPos++, "VBScript" );
	listTranslateLanguage->SetCurSel(0);

}

void CAG_MSI_APP_VBS::loadTerminalTypeList(CListBox* listTerminalTypes)
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


void CAG_MSI_APP_VBS::loadFunctionList(CListBox* listTranslateFunction)
{
	csaFunctions.RemoveAll();

	listTranslateFunction->ResetContent();

	csaFunctions.Add("MsiAdvertiseProduct");
	csaFunctions.Add("MsiAdvertiseProductEx");
	csaFunctions.Add("MsiAdvertiseScript");
	csaFunctions.Add("MsiApplyMultiplePatches");
	csaFunctions.Add("MsiApplyPatch");
	csaFunctions.Add("MsiCloseAllHandles");
	csaFunctions.Add("MsiCloseHandle");
	csaFunctions.Add("MsiCollectUserInfo");
	csaFunctions.Add("MsiConfigureFeature");
	csaFunctions.Add("MsiConfigureProduct");
	csaFunctions.Add("MsiConfigureProductEx");
	csaFunctions.Add("MsiDetermineApplicablePatches");
	csaFunctions.Add("MsiDeterminePatchSequence");
	csaFunctions.Add("MsiEnableLog");
	csaFunctions.Add("MsiEnumClients");
	csaFunctions.Add("MsiEnumComponentQualifiers");
	csaFunctions.Add("MsiEnumComponents");
	csaFunctions.Add("MsiEnumFeatures");
	csaFunctions.Add("MsiEnumPatches");
	csaFunctions.Add("MsiEnumPatchesEx");
	csaFunctions.Add("MsiEnumProducts");
	csaFunctions.Add("MsiEnumProductsEx");
	csaFunctions.Add("MsiEnumRelatedProducts");
	csaFunctions.Add("MsiExtractPatchXMLData");
	csaFunctions.Add("MsiGetComponentPath");
	csaFunctions.Add("MsiGetFeatureInfo");
	csaFunctions.Add("MsiGetFeatureUsage");
	csaFunctions.Add("MsiGetFileHash");
	csaFunctions.Add("MsiGetFileSignatureInformation");
	csaFunctions.Add("MsiGetFileVersion");
	csaFunctions.Add("MsiGetPatchInfo");
	csaFunctions.Add("MsiGetPatchInfoEx");
	csaFunctions.Add("MsiGetProductCode");
	csaFunctions.Add("MsiGetProductInfo");
	csaFunctions.Add("MsiGetProductInfoEx");
	csaFunctions.Add("MsiGetProductInfoFromScript");
	csaFunctions.Add("MsiGetProductProperty");
	csaFunctions.Add("MsiGetShortcutTarget");
	csaFunctions.Add("MsiGetUserInfo");
	csaFunctions.Add("MsiInstallMissingComponent");
	csaFunctions.Add("MsiInstallMissingFile");
	csaFunctions.Add("MsiInstallProduct");
	csaFunctions.Add("MsiIsProductElevated");
	csaFunctions.Add("MsiLocateComponent");
	csaFunctions.Add("MsiOpenPackage");
	csaFunctions.Add("MsiOpenPackageEx");
	csaFunctions.Add("MsiOpenProduct");
	csaFunctions.Add("MsiProcessAdvertiseScript");
	csaFunctions.Add("MsiProvideAssembly");
	csaFunctions.Add("MsiProvideComponent");
	csaFunctions.Add("MsiProvideQualifiedComponent");
	csaFunctions.Add("MsiProvideQualifiedComponentEx");
	csaFunctions.Add("MsiQueryComponentState");
	csaFunctions.Add("MsiQueryFeatureState");
	csaFunctions.Add("MsiQueryFeatureStateEx");
	csaFunctions.Add("MsiQueryProductState");
	csaFunctions.Add("MsiReinstallFeature");
	csaFunctions.Add("MsiReinstallProduct");
	csaFunctions.Add("MsiRemovePatches");
	csaFunctions.Add("MsiSetExternalUI");
	csaFunctions.Add("MsiSetInternalUI");
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
	csaFunctions.Add("MsiUseFeature");
	csaFunctions.Add("MsiUseFeatureEx");
	csaFunctions.Add("MsiVerifyPackage");

	listTranslateFunction->ResetContent();	
	
	for (int k=0; k<csaFunctions.GetSize(); k++)
	{
		listTranslateFunction->AddString( csaFunctions.GetAt(k) );
	}

	listTranslateFunction->SetCurSel(0);

}
