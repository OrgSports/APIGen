#include "stdafx.h"
#include "APIGen.h"
#include "APIGenDlg.h"



/****************************************************************************DC
	Function	:	CAPIGenDlg::ShowWIXWizControls()

	Purpose		:	Show the controls for the MSI Database function parameters.

*****************************************************************************/
void CAPIGenDlg::ShowWIXWizControls( int nFunction )
{
	HideParameterControls();
	csaLabels.RemoveAll();
	BOOL bYouShouldGo=TRUE;

	switch ( nFunction )
	{
		case 0:     //Bitmap
		{
			csaLabels.Add( "Bitmap file" );
			csaLabels.Add( "Bitmap ID" );
			bYouShouldGo=FALSE;
		}
		break;

		case 1:     //Control label
		{
			csaLabels.Add( "Label ID" );
			csaLabels.Add( "Text" );
			csaLabels.Add( "X-position" );
			csaLabels.Add( "Y-position" );
			csaLabels.Add( "Width (pixels)" );
		}
		break;

		case 2:     //Edit control
		case 4:     //Masked edit control
		{
			csaLabels.Add( "Control ID" );
			csaLabels.Add( "Property name" );
			csaLabels.Add( "Text" );
			csaLabels.Add( "X-position" );
			csaLabels.Add( "Y-position" );
			csaLabels.Add( "Width (pixels)" );
		}
		break;

		case 3:     //Line
		{
			csaLabels.Add( "Control ID" );
			csaLabels.Add( "X-position" );
			csaLabels.Add( "Y-position" );
			csaLabels.Add( "Length (pixels)" );
		}
		break;

		case 5:     //Pushbutton
		{
			csaLabels.Add( "Button ID" );
			csaLabels.Add( "Text" );
			csaLabels.Add( "Event" );
			csaLabels.Add( "Event value" );
			csaLabels.Add( "Initial value" );
			csaLabels.Add( "X-position" );
			csaLabels.Add( "Y-position" );
			csaLabels.Add( "Width (pixels)" );
		}
		break;

		default:
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
		ShowMixedControls( MSI_WIXDLG_API, nFunction, &csaLabels );	
	}


}


/****************************************************************************DC
	Function	:	CAPIGenDlg::LoadWIXWizArgumentArray()

	Purpose		:	Load the function arguments for a WIX Wizard

*****************************************************************************/
void CAPIGenDlg::LoadWIXWizArgumentArray( int* nFunctionPosition, BOOL bPromptForValues )
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
			case 0:     //Bitmap
			{
				Read2E( &csaArguments );
			}
			break;

			case 1:     //Control label
			{
				Read5E( &csaArguments );
			}
			break;

			case 2:     //Edit control
			case 4:     //Masked edit control
			{
				Read6E( &csaArguments );
			}
			break;

			case 3:     //Line
			{
				Read4E( &csaArguments );
			}
			break;

			case 5:     //Pushbutton
			{
				Read8E( &csaArguments );
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


