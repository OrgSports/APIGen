#include "stdafx.h"
#include "APIGen.h"
#include "APIGenDlg.h"



/****************************************************************************DC
	Function	:	CAPIGenDlg::ShowMSIDBaseControls()

	Purpose		:	Show the controls for the MSI Database function parameters.

*****************************************************************************/
void CAPIGenDlg::ShowMSIDBaseControls( int nFunction )
{
	HideParameterControls();
	csaLabels.RemoveAll();
	BOOL bYouShouldGo=TRUE;

	switch ( nFunction )
	{
		case 0:	//MsiCreateRecord
		{
			csaLabels.Add( "Number of fields" );
		}
		break;

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
		}
		break;

	}

	if ( bYouShouldGo )
	{
		ShowEditControls( &csaLabels );
	}
	else
	{
		ShowMixedControls( MSI_DB_API, nFunction, &csaLabels );	
	}


}


/****************************************************************************DC
	Function	:	CAPIGenDlg::LoadMSIDBaseArgumentArray()

	Purpose		:	Load the function arguments for OLE Automation.

*****************************************************************************/
void CAPIGenDlg::LoadMSIDBaseArgumentArray( int* nFunctionPosition, BOOL bPromptForValues )
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
			case 0:	//MsiCreateRecord
			{
				Read1E(&csaArguments);
			}
			break;

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
			}
			break;
		}
	}
	else
	{
		switch ( *nFunctionPosition )
		{
			case 0:	//MsiCreateRecord
			{
				csaArguments.Add( "4" );
			}
			break;

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
			}
			break;

		}
	}

}


