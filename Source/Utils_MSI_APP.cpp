#include "stdafx.h"
#include "APIGen.h"
#include "APIGenDlg.h"



/****************************************************************************DC
	Function	:	CAPIGenDlg::ShowMSIAppControls()

	Purpose		:	Show the controls for the MSI Database function parameters.

*****************************************************************************/
void CAPIGenDlg::ShowMSIAppControls( int nFunction )
{
	HideParameterControls();
	csaLabels.RemoveAll();
	BOOL bYouShouldGo=TRUE;

	switch ( nFunction )
	{
		case 0:     //MsiAdvertiseProduct
		{
			csaLabels.Add( "Package path" );
			csaLabels.Add( "Script file path" );
			csaLabels.Add( "Secure source transforms" );
			csaLabels.Add( "Secure path transforms" );
			csaLabels.Add( "Transform[{; Transform}]" );
			csaLabels.Add( "Language" );
			bYouShouldGo=FALSE;
		}
		break;

		case 1:     //MsiAdvertiseProductEx
		{
			csaLabels.Add( "Package path" );
			csaLabels.Add( "Script file path" );
			csaLabels.Add( "Secure source transforms" );
			csaLabels.Add( "Secure path transforms" );
			csaLabels.Add( "Transform[{; Transform}]" );
			csaLabels.Add( "Language" );
			csaLabels.Add( "Platform" );
			csaLabels.Add( "Options" );
			bYouShouldGo=FALSE;
		}
		break;

		case 8:     //MsiConfigureFeature
		{
			csaLabels.Add( "Product code" );
			csaLabels.Add( "Feature ID" );
			csaLabels.Add( "Install state" );
			bYouShouldGo=FALSE;
		}
		break;

		case 24:     //MsiGetComponentPath
		{
			csaLabels.Add( "Product code" );
			csaLabels.Add( "Component ID" );
			csaLabels.Add( "Component path" );
			csaLabels.Add( "Component path size" );
		}
		break;

		case 25:     //MsiGetFeatureInfo
		{
			csaLabels.Add( "Product code" );
			csaLabels.Add( "Feature code" );
		}
		break;

		case 33:     //MsiGetProductInfo
		{
			csaLabels.Add( "Product code" );
			csaLabels.Add( "Product property" );
			csaLabels.Add( "Return string" );
			csaLabels.Add( "String length" );
			bYouShouldGo=FALSE;
		}
		break;


		case 53:     //MsiQueryFeatureState
		{
			csaLabels.Add( "Product name" );
			csaLabels.Add( "Feature name" );
		}
		break;

		case 56:     //MsiReinstallFeature
		{
			csaLabels.Add( "Product code" );
			csaLabels.Add( "Feature ID" );
			csaLabels.Add( "Install mode" );
			bYouShouldGo=FALSE;
		}
		break;

		case 57:     //MsiReinstallProduct
		{
			csaLabels.Add( "Product code" );
			csaLabels.Add( "Install mode" );
			bYouShouldGo=FALSE;
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
		case 26:     //MsiGetFeatureUsage
		case 27:     //MsiGetFileHash
		case 28:     //MsiGetFileSignatureInformation
		case 29:     //MsiGetFileVersion
		case 30:     //MsiGetPatchInfo
		case 31:     //MsiGetPatchInfoEx
		case 32:     //MsiGetProductCode
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
		}
		break;

		case 17:     //MsiEnumFeatures
		{
			csaLabels.Add( "Product code" );
			csaLabels.Add( "Feature index" );
			csaLabels.Add( "Feature name" );
			csaLabels.Add( "Parent name" );
		}
		break;

		case 73:     //MsiUseFeature
		{
			csaLabels.Add( "Product code" );
			csaLabels.Add( "Feature name" );
		}
		break;


	}

	if ( bYouShouldGo )
	{
		ShowEditControls( &csaLabels );
	}
	else
	{
		ShowMixedControls( MSI_APP_API, nFunction, &csaLabels );	
	}


}


/****************************************************************************DC
	Function	:	CAPIGenDlg::LoadMSIAppArgumentArray()

	Purpose		:	Load the function arguments for an application using the 
					MSI API.

*****************************************************************************/
void CAPIGenDlg::LoadMSIAppArgumentArray( int* nFunctionPosition, BOOL bPromptForValues )
{
	CString	csFunctionName, csFunctionNum;
	
	UpdateData();
	
	*nFunctionPosition=0;

	*nFunctionPosition = m_listTranslateFunction.GetCurSel();
	m_listTranslateFunction.GetText( *nFunctionPosition, csFunctionName );

	// full function name text
	csaArguments.Add( csFunctionName );

	if ( bPromptForValues )
	{
		switch ( *nFunctionPosition )
		{
			case 0:     //MsiAdvertiseProduct
			{
				Read2E2C1E1L(&csaArguments);
			}
			break;

			case 1:     //MsiAdvertiseProductEx
			{
				Read2E2C1E2L1E(&csaArguments);
			}
			break;

			case 33:     //MsiGetProductInfo
			{
				Read1E1L2E(&csaArguments);
			}
			break;

			case 2:     //MsiAdvertiseScript
			case 3:     //MsiApplyMultiplePatches
			case 4:     //MsiApplyPatch
			case 5:     //MsiCloseAllHandles
			case 6:     //MsiCloseHandle
			case 7:     //MsiCollectUserInfo
			case 8:     //MsiConfigureFeature
			case 9:     //MsiConfigureProduct
			case 10:     //MsiConfigureProductEx
			case 11:     //MsiDetermineApplicablePatches
			case 12:     //MsiDeterminePatchSequence
			case 13:     //MsiEnableLog
			case 14:     //MsiEnumClients
			case 15:     //MsiEnumComponentQualifiers
			case 16:     //MsiEnumComponents
			case 17:     //MsiEnumFeatures
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
			case 53:     //MsiQueryFeatureState
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
			case 73:     //MsiUseFeature
			case 74:     //MsiUseFeatureEx
			case 75:     //MsiVerifyPackage
			{
			}
			break;
		}
	}
	else
	{
		switch ( *nFunctionPosition )
		{
			case 0:     //MsiAdvertiseProduct
			{
				csaArguments.Add( "c:\\temp\\packages" );
				csaArguments.Add( "c:\\temp\\scripts" );
				csaArguments.Add( "FALSE" );
				csaArguments.Add( "TRUE" );
				csaArguments.Add( "Transform24" );
				csaArguments.Add( "English" );
			}
			break;

			case 1:     //MsiAdvertiseProductEx
			{
				csaArguments.Add( "c:\\temp\\packages" );
				csaArguments.Add( "c:\\temp\\scripts" );
				csaArguments.Add( "FALSE" );
				csaArguments.Add( "TRUE" );
				csaArguments.Add( "Transform24" );
				csaArguments.Add( "English" );
				csaArguments.Add( "1" );
				csaArguments.Add( "1" );
			}
			break;

			case 33:     //MsiGetProductInfo
			{
				csaArguments.Add( "QuickTime" );
				csaArguments.Add( "Install date" );
				csaArguments.Add( "csDateInfo" );
				csaArguments.Add( "32" );
			}
			break;


			case 2:     //MsiAdvertiseScript
			case 3:     //MsiApplyMultiplePatches
			case 4:     //MsiApplyPatch
			case 5:     //MsiCloseAllHandles
			case 6:     //MsiCloseHandle
			case 7:     //MsiCollectUserInfo
			case 8:     //MsiConfigureFeature
			case 9:     //MsiConfigureProduct
			case 10:     //MsiConfigureProductEx
			case 11:     //MsiDetermineApplicablePatches
			case 12:     //MsiDeterminePatchSequence
			case 13:     //MsiEnableLog
			case 14:     //MsiEnumClients
			case 15:     //MsiEnumComponentQualifiers
			case 16:     //MsiEnumComponents
			case 17:     //MsiEnumFeatures
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
			case 53:     //MsiQueryFeatureState
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
			case 73:     //MsiUseFeature
			case 74:     //MsiUseFeatureEx
			case 75:     //MsiVerifyPackage
			{
			}
			break;

		}
	}

}


