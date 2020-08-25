#include "stdafx.h"
#include "APIGen.h"
#include "APIGenDlg.h"



/****************************************************************************DC
	Function	:	CAPIGenDlg::ShowMSICustomControls()

	Purpose		:	Show the controls for the MSI Database function parameters.

*****************************************************************************/
void CAPIGenDlg::ShowMSICustomControls( int nFunction )
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

		case 2:     //MsiAdvertiseScript
		{
			csaLabels.Add( "Script file path" );
			csaLabels.Add( "Script flag(s)" );
			csaLabels.Add( "Registry temp key" );
			csaLabels.Add( "Remove items (vs create)" );
			bYouShouldGo=FALSE;
		}
		break;

		case 3:     //MsiApplyMultiplePatches
		{
			csaLabels.Add( "Patch package(s)" );
			csaLabels.Add( "[Product GUID]" );
			csaLabels.Add( "[Property {;Property}]" );
		}
		break;

		case 4:     //MsiCloseAllHandles
		{
		}
		break;

		case 5:     //MsiCloseHandle
		{
			csaLabels.Add( "Handle name" );
		}
		break;

		case 6:     //MsiCreateRecord
		{
			csaLabels.Add( "Field count" );
		}
		break;

		case 7:     //MsiDatabaseGetPrimaryKeys
		case 8:     //MsiDatabaseIsTablePersistent
		{
			csaLabels.Add( "Database handle" );
			csaLabels.Add( "Table name" );
		}
		break;

		case 9:     //MsiDatabaseOpenView
		{
			csaLabels.Add( "Database handle" );
			csaLabels.Add( "SQL query string" );
		}
		break;

		case 10:     //MsiDetermineApplicablePatches
		{
			csaLabels.Add( "MSI file path" );
			csaLabels.Add( "Number of patches" );
			csaLabels.Add( "Patch sequence array" );
		}
		break;

		case 11:     //MsiDeterminePatchSequence
		{
			csaLabels.Add( "Product GUID" );
			csaLabels.Add( "[SID of user]" );
			csaLabels.Add( "Context" );
			csaLabels.Add( "Number of patches" );
			csaLabels.Add( "Patch sequence array" );
			bYouShouldGo=FALSE;
		}
		break;

		case 12:     //MsiDoAction
		{
			csaLabels.Add( "Action handle" );
			csaLabels.Add( "Action name" );
		}
		break;

		case 13:     //MsiEnumClients
		{
			csaLabels.Add( "Component name" );
			csaLabels.Add( "Client index" );
		}
		break;

		case 14:     //MsiEnumComponentCosts
		{
			csaLabels.Add( "Installation handle" );
			csaLabels.Add( "Component name" );
			csaLabels.Add( "Drive index" );
			csaLabels.Add( "Drive name" );
			csaLabels.Add( "Drive name size" );
		}
		break;

		case 15:     //MsiEnumComponentQualifiers
		{
			csaLabels.Add( "Component name" );
			csaLabels.Add( "Qualifier index" );
			csaLabels.Add( "Qualifier buffer size" );
			csaLabels.Add( "App data buffer size" );
		}
		break;

		case 16:     //MsiEnumComponents
		{
			csaLabels.Add( "Component index" );
		}
		break;

		case 17:     //MsiEnumFeatures
		{
			csaLabels.Add( "Product code" );
			csaLabels.Add( "Feature index" );
		}
		break;

		case 18:     //MsiEnumPatches
		{
			csaLabels.Add( "Product code" );
			csaLabels.Add( "Patch index" );
			csaLabels.Add( "Buffer size" );
		}
		break;

		case 19:     //MsiEnumPatchesEx
		{
			csaLabels.Add( "Product code" );
			csaLabels.Add( "[SID of user]" );
			csaLabels.Add( "Context" );
			csaLabels.Add( "Filter" );
			csaLabels.Add( "Patch index" );
			csaLabels.Add( "[SID of target user]" );
			bYouShouldGo=FALSE;
		}
		break;

		case 20:     //MsiEnumProducts
		{
			csaLabels.Add( "Product index" );
		}
		break;

		case 21:     //MsiEnumProductsEx
		{
			csaLabels.Add( "Product code" );
			csaLabels.Add( "[SID of user]" );
			csaLabels.Add( "Context" );
			csaLabels.Add( "Product index" );
			bYouShouldGo=FALSE;
		}
		break;

		case 22:     //MsiEnumRelatedProducts
		{
			csaLabels.Add( "Upgrade code" );
			csaLabels.Add( "Product index" );
		}
		break;

		case 23:     //MsiEvaluationCondition
		{
			csaLabels.Add( "Action handle" );
			csaLabels.Add( "Condition statement" );
		}
		break;

		case 24:     //MsiExtractPatchXMLData
		{
			csaLabels.Add( "Patch path" );
		}
		break;

		case 25:     //MsiFormatRecord
		{
			csaLabels.Add( "Install handle" );
			csaLabels.Add( "Record handle" );
		}
		break;

		case 26:     //MsiGetActiveDatabase
		{
			csaLabels.Add( "Install handle" );
		}
		break;

		case 27:     //MsiGetComponentPath
		{
			csaLabels.Add( "Product code" );
			csaLabels.Add( "Component ID" );
			csaLabels.Add( "Component path" );
			csaLabels.Add( "Component path size" );
		}
		break;

		case 28:     //MsiGetComponentState
		{
			csaLabels.Add( "Install handle" );
			csaLabels.Add( "Component name" );
		}
		break;

		case 29:     //MsiGetFeatureCost
		{
			csaLabels.Add( "Install handle" );
			csaLabels.Add( "Feature name" );
			csaLabels.Add( "Cost tree" );
			csaLabels.Add( "Install state" );
			bYouShouldGo=FALSE;
		}
		break;

		case 30:     //MsiGetFeatureState
		case 32:     //MsiGetFeatureValidStates
		{
			csaLabels.Add( "Install handle" );
			csaLabels.Add( "Feature name" );
		}
		break;

		case 31:     //MsiGetFeatureUsage
		{
			csaLabels.Add( "Product code" );
			csaLabels.Add( "Feature code" );
		}
		break;

		case 33:     //MsiGetFileHash
		{
			csaLabels.Add( "File path" );
		}
		break;

		case 34:     //MsiGetFileSignatureInformation
		{
			csaLabels.Add( "Full file path" );
			csaLabels.Add( "Fatal invalid flash" );
			bYouShouldGo=FALSE;
		}
		break;

		case 59:     //MsiQueryFeatureState
		{
			csaLabels.Add( "Product name" );
			csaLabels.Add( "Feature name" );
		}
		break;

		case 35:     //MsiGetFileVersion
		{
			csaLabels.Add( "File path" );
		}
		break;

		case 36:     //MsiGetLanguage
		{
			csaLabels.Add( "Install handle" );
		}
		break;

		case 37:     //MsiGetLastErrorRecord
		case 39:     //MsiGetPatchInfoEx
		{

		}
		break;

		case 38:     //MsiGetMode
		{
			csaLabels.Add( "Install handle" );
			csaLabels.Add( "Run mode" );
			bYouShouldGo=FALSE;
		}
		break;

		case 40:     //MsiGetProductInfo
		{
			csaLabels.Add( "Product code" );
			csaLabels.Add( "Property" );
			csaLabels.Add( "Value variable" );
			csaLabels.Add( "Value length" );
			bYouShouldGo=FALSE;
		}
		break;

		case 43:     //MsiGetProperty
		{
			csaLabels.Add( "MSI property name" );
		}
		break;

		case 53:     //MsiProcessMessage
		{
			csaLabels.Add( "Message type" );
			bYouShouldGo=FALSE;
		}
		break;

		case 79:     //MsiSetProperty
		{
			csaLabels.Add( "Property name" );
			csaLabels.Add( "Set to this value" );
		}
		break;


		case 41:     //MsiGetProductInfoEx
		case 42:     //MsiGetProductInfoFromScript
		case 44:     //MsiGetShortcutTarget
		case 45:     //MsiGetSourcePath
		case 46:     //MsiGetSummaryInformation
		case 47:     //MsiGetTargetPath
		case 48:     //MsiGetUserInfo
		case 49:     //MsiIsProductElevated
		case 50:     //MsiLocateComponent
		case 51:     //MsiOpenPackageEx
		case 52:     //MsiProcessAdvertiseScript
		case 54:     //MsiProvideAssembly
		case 55:     //MsiProvideComponent	// only if it doesn't start another installation
		case 56:     //MsiProvideQualifiedComponent	// only if it doesn't start another installation
		case 57:     //MsiProvideQualifiedComponentEx	// only if it doesn't start another installation
		case 58:     //MsiQueryComponentState
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

		}
		break;

	}

	if ( bYouShouldGo )
	{
		ShowEditControls( &csaLabels );
	}
	else
	{
		ShowMixedControls( MSI_CUSTOM_API, nFunction, &csaLabels );	
	}


}


/****************************************************************************DC
	Function	:	CAPIGenDlg::LoadMSICustomArgumentArray()

	Purpose		:	Load the function arguments for OLE Automation.

*****************************************************************************/
void CAPIGenDlg::LoadMSICustomArgumentArray( int* nFunctionPosition, BOOL bPromptForValues )
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

			case 17:     //MsiEnumFeatures
			case 79:     //MsiSetProperty
			{
				Read2E(&csaArguments);
			}
			break;

			case 5:		//MsiCloseHandle
			case 43:	//MsiGetProperty
			{
				Read1E(&csaArguments);
			}
			break;

			case 53:     //MsiProcessMessage
			{
				Read1L(&csaArguments);
			}
			break;


			case 2:     //MsiAdvertiseScript
			{
				Read1E1ML1E1C(&csaArguments);
			}
			break;



			case 3:     //MsiApplyMultiplePatches
			case 4:     //MsiCloseAllHandles

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
			case 44:     //MsiGetShortcutTarget
			case 45:     //MsiGetSourcePath
			case 46:     //MsiGetSummaryInformation
			case 47:     //MsiGetTargetPath
			case 48:     //MsiGetUserInfo
			case 49:     //MsiIsProductElevated
			case 50:     //MsiLocateComponent
			case 51:     //MsiOpenPackageEx
			case 52:     //MsiProcessAdvertiseScript
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

			case 2:     //MsiAdvertiseScript
			{
				csaArguments.Add( "c:\\scripts\\script1.sh" );
				csaArguments.Add( "SCRIPTFLAGS_SHORTCUTS" );
				csaArguments.Add( "HKLM\\SOFTWARE\\Attachmate\\RWeb" );
				csaArguments.Add( "TRUE" );
			}
			break;

			case 5:     //MsiCloseHandle
			{
				csaArguments.Add( "hCurrentInstall" );
			}
			break;

			case 17:     //MsiEnumFeatures
			{
				csaArguments.Add( "{ECF246DF-E871-11D2-8CC2-00C04F72C0ED}" );
				csaArguments.Add( "0" );
			}
			break;


			case 43:     //MsiGetProperty
			{
				csaArguments.Add( "TRACEPROPERTY" );
			}
			break;

			case 53:     //MsiProcessMessage
			{
				csaArguments.Add( "INSTALLMESSAGE_OUTOFDISKSPACE" );
			}
			break;

			case 79:     //MsiSetProperty
			{
				csaArguments.Add( "PIDKEY" );
				csaArguments.Add( "123-451" );
			}
			break;


			case 3:     //MsiApplyMultiplePatches
			case 4:     //MsiCloseAllHandles
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
			case 44:     //MsiGetShortcutTarget
			case 45:     //MsiGetSourcePath
			case 46:     //MsiGetSummaryInformation
			case 47:     //MsiGetTargetPath
			case 48:     //MsiGetUserInfo
			case 49:     //MsiIsProductElevated
			case 50:     //MsiLocateComponent
			case 51:     //MsiOpenPackageEx
			case 52:     //MsiProcessAdvertiseScript
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
			}
			break;

		}
	}

}


