#include "stdafx.h"
#include "APIGen.h"
#include "APIGenDlg.h"

#include "ParameterLayouts.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


/***************************************************************************DC

	Operation:	CAPIGenDlg::ShowMixedControls() 

	Purpose:	Sets up the controls used in entering function arguments.

	Arguments:	csaLabels -- the strings that are used to label each edit
				control.

				nControlBits -- an unsigned int that indicates which controls
				should be placed in the UI.
	
	Note:		

*****************************************************************************/
void CAPIGenDlg::ShowMixedControls( APIOption API, UINT uFunction, CStringArray* pcsaLabels )
{
	int topGroupStart=PARAM_TOP;
	int nGroupBoxHeight = 0;
	CStringArray csaListBox;
	CStringArray* pcsaListBox = &csaListBox;
	CStringArray csaListBox2;
	CStringArray* pcsaListBox2 = &csaListBox2;
	CStringArray csaListBox3;
	CStringArray* pcsaListBox3 = &csaListBox3;
	CStringArray csaListBox4;
	CStringArray* pcsaListBox4 = &csaListBox4;
	CStringArray csaListBox5;
	CStringArray* pcsaListBox5 = &csaListBox5;

	switch ( API )
	{
		case MSI_WIXWIZ_API:
		{
			switch ( uFunction )
			{
				case 0:     //bitmap
				{
					Show1EB1E( pcsaLabels );
				}
				break;
			}
		}
		break;
	
		case MSI_WIXDLG_API:
		{
			switch ( uFunction )
			{
				case 0:     //bitmap
				{
					Show1EB1E( pcsaLabels );
				}
				break;
			}
		}
		break;

		case MSI_SUMMARY_API:
		{
			switch ( uFunction )
			{
				case 0:     //Platform/Language
				{
					pcsaListBox->Add( "English" );	//convert to LANGID
					pcsaListBox->Add( "French" );
					pcsaListBox->Add( "German" );
					pcsaListBox->Add( "Italian" );
					pcsaListBox->Add( "Japanese" );

					Show1L( pcsaLabels, pcsaListBox );
				}
				break;
	
				case 2:		//Page count
				{
					pcsaListBox->Add( "1.0" );
					pcsaListBox->Add( "1.1" );

					Show1L( pcsaLabels, pcsaListBox );
				}
				break;
	
				case 3:		//Word count
				{
					Show3C( pcsaLabels );
				}
				break;
	
				case 10:	//Security
				{
					pcsaListBox->Add( "No restriction" );
					pcsaListBox->Add( "Read-only recommended" );
					pcsaListBox->Add( "Read-only enforced" );

					Show1L( pcsaLabels, pcsaListBox );
				}
				break;
	

			}
		}
		break;

		case MSI_CUSTOM_API:
		{
			switch ( uFunction )
			{
				case 0:     //MsiAdvertiseProduct
				{
					pcsaListBox->Add( "English" );	//convert to LANGID
					pcsaListBox->Add( "French" );
					pcsaListBox->Add( "German" );
					pcsaListBox->Add( "Italian" );
					pcsaListBox->Add( "Japanese" );

					Show2E2C1E1L( pcsaLabels, pcsaListBox );
				}
				break;

				case 1:     //MsiAdvertiseProductEx
				{
					pcsaListBox->Add( "English" );	//convert to LANGID
					pcsaListBox->Add( "French" );
					pcsaListBox->Add( "German" );
					pcsaListBox->Add( "Italian" );
					pcsaListBox->Add( "Japanese" );

					pcsaListBox2->Add( "None" );
					pcsaListBox2->Add( "X86" );
					pcsaListBox2->Add( "IA64" );
					pcsaListBox2->Add( "AMD64" );

					Show2E2C1E2L1E( pcsaLabels, pcsaListBox, pcsaListBox2 );
				}
				break;

				case 2:     //MsiAdvertiseScript
				{
					pcsaListBox->Add( "CACHE_INFO" );
					pcsaListBox->Add( "SHORTCUTS" );
					pcsaListBox->Add( "MACHINEASSIGN" );
					pcsaListBox->Add( "REGDATA_APPINFO" );
					pcsaListBox->Add( "REGDATA_CNFGINFO" );
					pcsaListBox->Add( "VALIDATE_TRANSFORMS_LIST" );
					pcsaListBox->Add( "REGDATA_CLASSINFO" );
					pcsaListBox->Add( "REGDATA_EXTENSIONINFO" );
					pcsaListBox->Add( "REGDATA" );

					Show1E1ML1E1C( pcsaLabels, pcsaListBox );
				}
				break;

				case 11:     //MsiDeterminePatchSequence
				{
					pcsaListBox->Add( "Per user managed" );
					pcsaListBox->Add( "Per user unmanaged" );
					pcsaListBox->Add( "Per machine" );

					Show2E1L2E( pcsaLabels, pcsaListBox );
				}
				break;

				case 19:     //MsiEnumPatchesEx
				{
					pcsaListBox->Add( "Per user managed" );
					pcsaListBox->Add( "Per user unmanaged" );
					pcsaListBox->Add( "Per machine" );

					pcsaListBox2->Add( "Applied" );
					pcsaListBox2->Add( "Superceded" );
					pcsaListBox2->Add( "Obsoleted" );
					pcsaListBox2->Add( "Registered" );
					pcsaListBox2->Add( "All" );

					Show2E1L1ML2E( pcsaLabels, pcsaListBox, pcsaListBox2 );
				}
				break;

				case 21:     //MsiEnumProductsEx
				{
					pcsaListBox->Add( "Per user managed" );
					pcsaListBox->Add( "Per user unmanaged" );
					pcsaListBox->Add( "Per machine" );

					Show2E1L1E( pcsaLabels, pcsaListBox );
				}
				break;

				case 29:     //MsiGetFeatureCost
				{
					pcsaListBox->Add( "Children" );
					pcsaListBox->Add( "Parents" );
					pcsaListBox->Add( "Self only" );

					pcsaListBox2->Add( "Unknown" );
					pcsaListBox2->Add( "Absent" );
					pcsaListBox2->Add( "Local" );
					pcsaListBox2->Add( "Source" );
					pcsaListBox2->Add( "Default" );

					Show2E2L( pcsaLabels, pcsaListBox, pcsaListBox2 );
				}
				break;

				case 34:     //MsiGetFileSignatureInformation
				{
					Show1E1C( pcsaLabels );
				}
				break;

				case 38:     //MsiGetMode
				{
					pcsaListBox->Add( "Admin" );
					pcsaListBox->Add( "Advertise" );
					pcsaListBox->Add( "Maintenance" );
					pcsaListBox->Add( "Rollback enabled" );
					pcsaListBox->Add( "Log enabled" );
					pcsaListBox->Add( "Operations" );
					pcsaListBox->Add( "Reboot at end" );
					pcsaListBox->Add( "Reboot now" );
					pcsaListBox->Add( "Cabinet" );
					pcsaListBox->Add( "Source short names" );
					pcsaListBox->Add( "Target short names" );
					pcsaListBox->Add( "Windows9X" );
					pcsaListBox->Add( "ZAW enabled" );
					pcsaListBox->Add( "Scheduled" );
					pcsaListBox->Add( "Rollback" );
					pcsaListBox->Add( "Commit" );

					Show1E1L( pcsaLabels, pcsaListBox );
				}
				break;

				case 40:     //MsiGetProductInfo
				{
					pcsaListBox->Add( "AssignmentType" );
					pcsaListBox->Add( "HelpLink" );
					pcsaListBox->Add( "HelpTelephone" );
					pcsaListBox->Add( "InstallDate" );
					pcsaListBox->Add( "InstalledProductName" );
					pcsaListBox->Add( "InstallLocation" );
					pcsaListBox->Add( "InstallSource" );
					pcsaListBox->Add( "InstanceType" );
					pcsaListBox->Add( "Language" );
					pcsaListBox->Add( "LocalPackage" );
					pcsaListBox->Add( "PackageCode" );
					pcsaListBox->Add( "PackageName" );
					pcsaListBox->Add( "ProductIcon" );
					pcsaListBox->Add( "ProductName" );
					pcsaListBox->Add( "Publisher" );
					pcsaListBox->Add( "Transforms" );
					pcsaListBox->Add( "URLInfoAbout" );
					pcsaListBox->Add( "URLUpdateInfo" );
					pcsaListBox->Add( "Version" );
					pcsaListBox->Add( "VersionMajor" );
					pcsaListBox->Add( "VersionMinor" );
					pcsaListBox->Add( "VersionString" );

					Show1E1L2E( pcsaLabels, pcsaListBox );
				}
				break;

				case 53:     //MsiProcessMessage
				{
					pcsaListBox->Add( "FATALEXIT" );
					pcsaListBox->Add( "ERROR" );
					pcsaListBox->Add( "WARNING" );
					pcsaListBox->Add( "USER" );
					pcsaListBox->Add( "INFO" );
					pcsaListBox->Add( "FILESINUSE" );
					pcsaListBox->Add( "RESOLVESOURCE" );
					pcsaListBox->Add( "OUTOFDISKSPACE" );
					pcsaListBox->Add( "ACTIONSTART" );
					pcsaListBox->Add( "ACTIONDATA" );
					pcsaListBox->Add( "PROGRESS" );
					pcsaListBox->Add( "COMMONDATA" );

					Show1L( pcsaLabels, pcsaListBox );
				}
				break;

			}
		}
		break;


		case MSI_APP_API:
		{
			switch ( uFunction )
			{
				case 0:     //MsiAdvertiseProduct
				{
					pcsaListBox->Add( "English" );
					pcsaListBox->Add( "French" );
					pcsaListBox->Add( "German" );
					pcsaListBox->Add( "Italian" );
					pcsaListBox->Add( "Japanese" );

					Show2E2C1E1L( pcsaLabels, pcsaListBox );
				}
				break;

				case 8:     //MsiConfigureFeature
				{
					pcsaListBox->Add( "Advertised" );
					pcsaListBox->Add( "Local" );
					pcsaListBox->Add( "Absent" );
					pcsaListBox->Add( "Source" );
					pcsaListBox->Add( "Default" );

					Show2E1L( pcsaLabels, pcsaListBox );
				}
				break;

				case 33:     //MsiGetProductInfo
				{
					pcsaListBox->Add( "AssignmentType" );
					pcsaListBox->Add( "HelpLink" );
					pcsaListBox->Add( "HelpTelephone" );
					pcsaListBox->Add( "InstallDate" );
					pcsaListBox->Add( "InstalledProductName" );
					pcsaListBox->Add( "InstallLocation" );
					pcsaListBox->Add( "InstallSource" );
					pcsaListBox->Add( "InstanceType" );
					pcsaListBox->Add( "Language" );
					pcsaListBox->Add( "LocalPackage" );
					pcsaListBox->Add( "PackageCode" );
					pcsaListBox->Add( "PackageName" );
					pcsaListBox->Add( "ProductIcon" );
					pcsaListBox->Add( "ProductName" );
					pcsaListBox->Add( "Publisher" );
					pcsaListBox->Add( "Transforms" );
					pcsaListBox->Add( "URLInfoAbout" );
					pcsaListBox->Add( "URLUpdateInfo" );
					pcsaListBox->Add( "Version" );
					pcsaListBox->Add( "VersionMajor" );
					pcsaListBox->Add( "VersionMinor" );
					pcsaListBox->Add( "VersionString" );

					Show1E1L2E( pcsaLabels, pcsaListBox );
				}
				break;

				case 56:     //MsiReinstallFeature
				{
					pcsaListBox->Add( "File missing" );
					pcsaListBox->Add( "Older version" );
					pcsaListBox->Add( "Equal/older version" );
					pcsaListBox->Add( "Different version" );
					pcsaListBox->Add( "Verify version" );
					pcsaListBox->Add( "Force replacement" );
					pcsaListBox->Add( "HKCU registry values" );
					pcsaListBox->Add( "HKLM registry values" );
					pcsaListBox->Add( "Shortcuts" );
					pcsaListBox->Add( "Re-cache local" );

					Show2E1ML( pcsaLabels, pcsaListBox );
				}
				break;

				case 57:     //MsiReinstallProduct
				{
					pcsaListBox->Add( "File missing" );
					pcsaListBox->Add( "Older version" );
					pcsaListBox->Add( "Equal/older version" );
					pcsaListBox->Add( "Different version" );
					pcsaListBox->Add( "Verify version" );
					pcsaListBox->Add( "Force replacement" );
					pcsaListBox->Add( "HKCU registry values" );
					pcsaListBox->Add( "HKLM registry values" );
					pcsaListBox->Add( "Shortcuts" );
					pcsaListBox->Add( "Re-cache local" );

					Show1E1ML( pcsaLabels, pcsaListBox );
				}
				break;


			}
		}
		break;

		case PERFORCE_API:
		{
				switch ( uFunction )
				{
					case 0:	// add
					{
						pcsaListBox->Add( "none" );
						pcsaListBox->Add( "text" );
						pcsaListBox->Add( "binary" );
						pcsaListBox->Add( "symlink" );
						pcsaListBox->Add( "apple" );
						pcsaListBox->Add( "resource" );
						pcsaListBox->Add( "unicode" );

						pcsaListBox2->Add( "none" );
						pcsaListBox2->Add( "Writable on client" );
						pcsaListBox2->Add( "Execute bit set" );
						pcsaListBox2->Add( "Old-style keyword expansion" );
						pcsaListBox2->Add( "RCS keyword expansion" );
						pcsaListBox2->Add( "Exclusive open" );
						pcsaListBox2->Add( "Store compressed version" );
						pcsaListBox2->Add( "Store deltas" );
						pcsaListBox2->Add( "Store full file" );
						pcsaListBox2->Add( "Store head only" );
						pcsaListBox2->Add( "Preserve modtime" );

						Show1C1E1L1ML1C1E( pcsaLabels, pcsaListBox, pcsaListBox2  );
					}
					break;

					case 1:		//admin
					{
						pcsaListBox->Add( "checkpoint" );
						pcsaListBox->Add( "journal" );
						pcsaListBox->Add( "stop" );

						Show1C1L1C1E( pcsaLabels, pcsaListBox );
					}
					break;

					case 4:   // branches
					case 10:   // clients
					case 12:   // counters
					case 15:   // depots
					case 61:   // tickets
					case 70:   // workspaces
					{
						Show1C( pcsaLabels );
					}
					break;

				}
		}
		break;

		case VHI_API:
		{
				switch ( uFunction )
				{
					case 0:	// ConnectionTimeout
					{
						Show1C1E( pcsaLabels);
					}
					break;

					case 1:	// ConnectToModel
					case 3:	// ConnectToSession
					{
						Show4E1C( pcsaLabels);
					}
					break;

					case 2:	// ConnectToModelViaDomain	
					case 4:	// ConnectToSessionViaDomain
					{
						Show5E1C( pcsaLabels);
					}
					break;


					case 7:	// EnableTerminalAttributes
					{
						Show1C( pcsaLabels);
					}
					break;

					case 9:			// FetchRecords
					{
						Show1E1C1E( pcsaLabels);
					}
					break;

					case 61:		// MoveCurrentRecordIndex
					{
						pcsaListBox->Add( "ScrollHome" );
						pcsaListBox->Add( "ScrollEnd" );
						pcsaListBox->Add( "ScrollLineUp" );
						pcsaListBox->Add( "ScrollLineDown" );
						pcsaListBox->Add( "ScrollPageUp" );
						pcsaListBox->Add( "ScrollPageDown" );

						Show1L( pcsaLabels, pcsaListBox );
					}
					break;

					case 65:	// PerformTableProcedure
					{
						Show2E4C1E( pcsaLabels);
					}
					break;

					case 79:		// SetLocale
					{
						pcsaListBox->Add( "en_us" );

						Show1L( pcsaLabels, pcsaListBox );
					}
					break;

					case 80:		// SetLoggingLevel
					{
						pcsaListBox->Add( "Errors" );
						pcsaListBox->Add( "All" );
						pcsaListBox->Add( "ErrorsAndWarnings" );

						Show1L( pcsaLabels, pcsaListBox );
					}
					break;


				}
				
		}
		break;

	
		case ITASK_API:
		{
			switch ( uFunction )
			{
				case 18:     //ITask::setPreserveContext
				{
					pcsaListBox->Add( "PRESERVE_NEVER" );
					pcsaListBox->Add( "PRESERVE_ON_ERROR" );
					pcsaListBox->Add( "PRESERVE_ALWAYS" );

					Show1L( pcsaLabels, pcsaListBox );
				}
				break;
			}

		}
		break;

		case VIEWMASTER_API:
		{
			switch ( uFunction )
			{
				case 1:		// IScreenUPG::fieldCount
				{
					pcsaListBox->Add( "FIELDTYPE_PROTECTED" );		//1
					pcsaListBox->Add( "FIELDTYPE_UNPROTECTED" );	//2
					pcsaListBox->Add( "FIELDTYPE_ANY" );			//3

					Show1L( pcsaLabels, pcsaListBox );
				}
				break;

				case 2:		// IScreenUPG::findField
				{
					pcsaListBox->Add( "FINDFIELD_CURRENT" );		//0
					pcsaListBox->Add( "FINDFIELD_NEXT" );			//1
					pcsaListBox->Add( "FINDFIELD_PREVIOUS" );		//2

					pcsaListBox2->Add( "FIELDTYPE_PROTECTED" );		//1
					pcsaListBox2->Add( "FIELDTYPE_UNPROTECTED" );	//2
					pcsaListBox2->Add( "FIELDTYPE_ANY" );			//3

					Show2E2L1C( pcsaLabels, pcsaListBox, pcsaListBox2  );
				}
				break;

				case 3:	// IScreenUPG::findFieldEx
				{
					pcsaListBox->Add( "FINDFIELD_CURRENT" );		//0
					pcsaListBox->Add( "FINDFIELD_NEXT" );			//1
					pcsaListBox->Add( "FINDFIELD_PREVIOUS" );		//2

					pcsaListBox2->Add( "FIELDTYPE_PROTECTED" );		//1
					pcsaListBox2->Add( "FIELDTYPE_UNPROTECTED" );	//2
					pcsaListBox2->Add( "FIELDTYPE_ANY" );			//3

					Show1E2L1C( pcsaLabels, pcsaListBox, pcsaListBox2  );
				}
				break;

				case 5:	// IScreenUPG::findStringEx
				{
					pcsaListBox->Add( "DIRECTION_FORWARD" );		//0
					pcsaListBox->Add( "DIRECTION_BACKWARD" );		//4

					Show5E1C1L( pcsaLabels, pcsaListBox );
				}
				break;

				case 24:	// IScreenUPG::getStringEx
				{
					pcsaListBox->Add( "SCREENATTR_ANY" );			//-1
					pcsaListBox->Add( "SCREENATTR_PROTECTED" );		//1
					pcsaListBox->Add( "SCREENATTR_UNPROTECTED" );	//2
					pcsaListBox->Add( "SCREENATTR_HIDDEN" );		//4
					pcsaListBox->Add( "SCREENATTR_VISIBLE" );		//8

					Show4E1C1ML( pcsaLabels, pcsaListBox );
				}
				break;

				case 29:	// IScreenUPG::putStringEx
				{
					pcsaListBox->Add( "PUTSTRING_STOP" );		//0
					pcsaListBox->Add( "PUTSTRING_SPAN" );		//1
					pcsaListBox->Add( "PUTSTRING_SKIP" );		//2

					Show5E1C1L1C( pcsaLabels, pcsaListBox );
				}
				break;


				case 30:	// IScreenUPG::sendKeys
				{
					pcsaListBox->Add( "KEYTYPE_BRACES" );		//0x00010000
					pcsaListBox->Add( "KEYTYPE_HLLAPI" );		//0x00020000

					Show1E1L( pcsaLabels, pcsaListBox );
				}
				break;

				case 34:	// IScreenUPG::setDataCapture
				case 35:	// IScreenUPG::setgetText_Display
				{
					Show1C( pcsaLabels );
				}
				break;

			}

		}
		break;

			case RIBM_OLE_API:
			{
				switch ( uFunction )
				{
					case 3:		// AddHotListItem
					{
						pcsaListBox->Add( "rcNoOptions" );
						pcsaListBox->Add( "rcAtNextField" );
						pcsaListBox->Add( "rcSeparator" );
						pcsaListBox->Add( "rcAtNextFieldAndSeparator" );

						Show3E1L( pcsaLabels, pcsaListBox );
					}
					break;

					case 4:		// AddReference
					case 21:	// CompileScript
					{
						Show1E1B( pcsaLabels );
					}
					break;

					case 7:		// AppendSQLStatement
					{
						pcsaListBox->Add( "rcAS400Select" );
						pcsaListBox->Add( "rcAS400Where" );
						pcsaListBox->Add( "rcAS400OrderBy" );
						pcsaListBox->Add( "rcAS400Having" );
						pcsaListBox->Add( "rcAS400GroupBy" );
						pcsaListBox->Add( "rcAS400JoinBy" );
						
						Show1L1E( pcsaLabels, pcsaListBox );
					}
					break;

					case 127:	// PrintHostFile
					{
						pcsaListBox->Add( "rcXfrASCII" );
						pcsaListBox->Add( "rcXfrBinary" );
						
						Show1E1L1C( pcsaLabels, pcsaListBox );
					}
					break;


					case 218:	// TransmitTerminalKey
					{
						pcsaListBox->Add( "rcIbmAltCursorKey" );
						pcsaListBox->Add( "rcIbmAttnKey" );
						pcsaListBox->Add( "rcIbmAu1Key" );
						pcsaListBox->Add( "rcIbmAu2Key" );
						pcsaListBox->Add( "rcIbmAu3Key" );
						pcsaListBox->Add( "rcIbmAu4Key" );
						pcsaListBox->Add( "rcIbmAu5Key" );
						pcsaListBox->Add( "rcIbmAu6Key" );
						pcsaListBox->Add( "rcIbmAu7Key" );
						pcsaListBox->Add( "rcIbmAu8Key" );
						pcsaListBox->Add( "rcIbmAu9Key" );
						pcsaListBox->Add( "rcIbmAu10Key" );
						pcsaListBox->Add( "rcIbmAu11Key" );
						pcsaListBox->Add( "rcIbmAu12Key" );
						pcsaListBox->Add( "rcIbmAu13Key" );
						pcsaListBox->Add( "rcIbmAu14Key" );
						pcsaListBox->Add( "rcIbmAu15Key" );
						pcsaListBox->Add( "rcIbmAu16Key" );
						pcsaListBox->Add( "rcIbmBackspaceKey" );
						pcsaListBox->Add( "rcIbmBackTabKey" );
						pcsaListBox->Add( "rcIbmClearKey" );
						pcsaListBox->Add( "rcIbmClearPartitionKey" );
						pcsaListBox->Add( "rcIbmCursorBlinkKey" );
						pcsaListBox->Add( "rcIbmCursorSelectKey" );
						pcsaListBox->Add( "rcIbmDeleteCharKey" );
						pcsaListBox->Add( "rcIbmDeleteKey" );
						pcsaListBox->Add( "rcIbmDeleteWordKey" );
						pcsaListBox->Add( "rcIbmDestrBackSpaceKey" );
						pcsaListBox->Add( "rcIbmDeviceCancelKey" );
						pcsaListBox->Add( "rcIbmDownKey" );
						pcsaListBox->Add( "rcIbmDupKey" );
						pcsaListBox->Add( "rcIbmDuplicateKey" );
						pcsaListBox->Add( "rcIbmEnterKey" );
						pcsaListBox->Add( "rcIbmEraseEofKey" );
						pcsaListBox->Add( "rcIbmEraseInputKey" );
						pcsaListBox->Add( "rcIbmExtGrKey" );
						pcsaListBox->Add( "rcIbmF1Key" );
						pcsaListBox->Add( "rcIbmF2Key" );
						pcsaListBox->Add( "rcIbmF3Key" );
						pcsaListBox->Add( "rcIbmF4Key" );
						pcsaListBox->Add( "rcIbmF5Key" );
						pcsaListBox->Add( "rcIbmF6Key" );
						pcsaListBox->Add( "rcIbmF7Key" );
						pcsaListBox->Add( "rcIbmF8Key" );
						pcsaListBox->Add( "rcIbmF9Key" );
						pcsaListBox->Add( "rcIbmF10Key" );
						pcsaListBox->Add( "rcIbmF11Key" );
						pcsaListBox->Add( "rcIbmF12Key" );
						pcsaListBox->Add( "rcIbmF13Key" );
						pcsaListBox->Add( "rcIbmF14Key" );
						pcsaListBox->Add( "rcIbmF15Key" );
						pcsaListBox->Add( "rcIbmF16Key" );
						pcsaListBox->Add( "rcIbmF17Key" );
						pcsaListBox->Add( "rcIbmF18Key" );
						pcsaListBox->Add( "rcIbmF19Key" );
						pcsaListBox->Add( "rcIbmF20Key" );
						pcsaListBox->Add( "rcIbmF21Key" );
						pcsaListBox->Add( "rcIbmF22Key" );
						pcsaListBox->Add( "rcIbmF23Key" );
						pcsaListBox->Add( "rcIbmF24Key" );
						pcsaListBox->Add( "rcIbmFieldDelimKey" );
						pcsaListBox->Add( "rcIbmFieldExitKey" );
						pcsaListBox->Add( "rcIbmFieldMarkKey" );
						pcsaListBox->Add( "rcIbmFieldMinusKey" );
						pcsaListBox->Add( "rcIbmFieldPlusKey" );
						pcsaListBox->Add( "rcIbmHelpKey" );
						pcsaListBox->Add( "rcIbmHexKey" );
						pcsaListBox->Add( "rcIbmHomeKey" );
						pcsaListBox->Add( "rcIbmIdentKey" );
						pcsaListBox->Add( "rcIbmInsertKey" );
						pcsaListBox->Add( "rcIbmKeyClickKey" );
						pcsaListBox->Add( "rcIbmLeftDoubleKey" );
						pcsaListBox->Add( "rcIbmLeftKey" );
						pcsaListBox->Add( "rcIbmNewLineKey" );
						pcsaListBox->Add( "rcIbmPa1Key" );
						pcsaListBox->Add( "rcIbmPa2Key" );
						pcsaListBox->Add( "rcIbmPa3Key" );
						pcsaListBox->Add( "rcIbmPageDownKey" );
						pcsaListBox->Add( "rcIbmPageUpKey" );
						pcsaListBox->Add( "rcIbmPanLeftKey" );
						pcsaListBox->Add( "rcIbmPanRightKey" );
						pcsaListBox->Add( "rcIbmPartitionJumpKey" );
						pcsaListBox->Add( "rcIbmPf1Key" );
						pcsaListBox->Add( "rcIbmPf2Key" );
						pcsaListBox->Add( "rcIbmPf3Key" );
						pcsaListBox->Add( "rcIbmPf4Key" );
						pcsaListBox->Add( "rcIbmPf5Key" );
						pcsaListBox->Add( "rcIbmPf6Key" );
						pcsaListBox->Add( "rcIbmPf7Key" );
						pcsaListBox->Add( "rcIbmPf8Key" );
						pcsaListBox->Add( "rcIbmPf9Key" );
						pcsaListBox->Add( "rcIbmPf10Key" );
						pcsaListBox->Add( "rcIbmPf11Key" );
						pcsaListBox->Add( "rcIbmPf12Key" );
						pcsaListBox->Add( "rcIbmPf13Key" );
						pcsaListBox->Add( "rcIbmPf14Key" );
						pcsaListBox->Add( "rcIbmPf15Key" );
						pcsaListBox->Add( "rcIbmPf16Key" );
						pcsaListBox->Add( "rcIbmPf17Key" );
						pcsaListBox->Add( "rcIbmPf18Key" );
						pcsaListBox->Add( "rcIbmPf19Key" );
						pcsaListBox->Add( "rcIbmPf20Key" );
						pcsaListBox->Add( "rcIbmPf21Key" );
						pcsaListBox->Add( "rcIbmPf22Key" );
						pcsaListBox->Add( "rcIbmPf23Key" );
						pcsaListBox->Add( "rcIbmPf24Key" );
						pcsaListBox->Add( "rcIbmPlusCrKey" );
						pcsaListBox->Add( "rcIbmPrintKey" );
						pcsaListBox->Add( "rcIbmPrintPartKey" );
						pcsaListBox->Add( "rcIbmResetKey" );
						pcsaListBox->Add( "rcIbmRightDoubleKey" );
						pcsaListBox->Add( "rcIbmRightKey" );
						pcsaListBox->Add( "rcIbmRuleKey" );
						pcsaListBox->Add( "rcIbmScrollDownKey" );
						pcsaListBox->Add( "rcIbmScrollLeftKey" );
						pcsaListBox->Add( "rcIbmScrollRightKey" );
						pcsaListBox->Add( "rcIbmScrollUpKey" );
						pcsaListBox->Add( "rcIbmSlpAutoEnterKey" );
						pcsaListBox->Add( "rcIbmSysReqstKey" );
						pcsaListBox->Add( "rcIbmTabKey" );
						pcsaListBox->Add( "rcIbmTestKey" );
						pcsaListBox->Add( "rcIbmUpKey" );

						Show1L( pcsaLabels, pcsaListBox );
					}
					break;


					// one edit control + one listbox + four edit controls + one listbox
					case 28:	// DefineEvent
					{
						pcsaListBox->Add( "rcSilence" );
						pcsaListBox->Add( "rcKbdEnabled" );
						pcsaListBox->Add( "rcEvConnected" );
						pcsaListBox->Add( "rcEvDisconnected" );
						pcsaListBox->Add( "rcEnterField" );
						pcsaListBox->Add( "rcExitField" );
						pcsaListBox->Add( "rcEnterPos" );
						pcsaListBox->Add( "rcExitPos" );
						pcsaListBox->Add( "rcCommString" );
						pcsaListBox->Add( "rcDisplayString" );
						pcsaListBox->Add( "rcTimeOfDay" );
						pcsaListBox->Add( "rcTime" );
						pcsaListBox->Add( "rcTerminalKeystroke" );
						pcsaListBox->Add( "rcNewHostScreen" );
						pcsaListBox->Add( "rcPrinterOpened" );
						pcsaListBox->Add( "rcPrinterStartOfPage" );
						pcsaListBox->Add( "rcPrinterEndOfPage" );
						pcsaListBox->Add( "rcBeforePrinterClosed" );
						pcsaListBox->Add( "rcPrinterClosed" );
						pcsaListBox->Add( "rcPrinterString" );
						pcsaListBox->Add( "rcPrinterStringReplace" );
						pcsaListBox->Add( "rcPrinterStatusString" );

						pcsaListBox2->Add( "rcIbmAltCursorKey" );
						pcsaListBox2->Add( "rcIbmAttnKey" );
						pcsaListBox2->Add( "cIbmAu1Key" );
						pcsaListBox2->Add( "rcIbmAu2Key" );
						pcsaListBox2->Add( "rcIbmAu3Key" );
						pcsaListBox2->Add( "rcIbmAu4Key" );
						pcsaListBox2->Add( "rcIbmAu5Key" );
						pcsaListBox2->Add( "rcIbmAu6Key" );
						pcsaListBox2->Add( "rcIbmAu7Key" );
						pcsaListBox2->Add( "rcIbmAu8Key" );
						pcsaListBox2->Add( "rcIbmAu9Key" );
						pcsaListBox2->Add( "rcIbmAu10Key" );
						pcsaListBox2->Add( "rcIbmAu11Key" );
						pcsaListBox2->Add( "rcIbmAu12Key" );
						pcsaListBox2->Add( "rcIbmAu13Key" );
						pcsaListBox2->Add( "rcIbmAu14Key" );
						pcsaListBox2->Add( "rcIbmAu15Key" );
						pcsaListBox2->Add( "rcIbmAu16Key" );
						pcsaListBox2->Add( "rcIbmBackspaceKey" );
						pcsaListBox2->Add( "rcIbmBackTabKey" );
						pcsaListBox2->Add( "rcIbmClearKey" );
						pcsaListBox2->Add( "rcIbmClearPartitionKey" );
						pcsaListBox2->Add( "rcIbmCursorBlinkKey" );
						pcsaListBox2->Add( "rcIbmCursorSelectKey" );
						pcsaListBox2->Add( "rcIbmDeleteCharKey" );
						pcsaListBox2->Add( "rcIbmDeleteKey" );
						pcsaListBox2->Add( "rcIbmDeleteWordKey" );
						pcsaListBox2->Add( "rcIbmDestrBackSpaceKey" );
						pcsaListBox2->Add( "rcIbmDeviceCancelKey" );
						pcsaListBox2->Add( "rcIbmDownKey" );
						pcsaListBox2->Add( "rcIbmDupKey" );
						pcsaListBox2->Add( "rcIbmDuplicateKey" );
						pcsaListBox2->Add( "rcIbmEnterKey" );
						pcsaListBox2->Add( "rcIbmEraseEofKey" );
						pcsaListBox2->Add( "rcIbmEraseInputKey" );
						pcsaListBox2->Add( "rcIbmExtGrKey" );
						pcsaListBox2->Add( "rcIbmF1Key" );
						pcsaListBox2->Add( "rcIbmF2Key" );
						pcsaListBox2->Add( "rcIbmF3Key" );
						pcsaListBox2->Add( "rcIbmF4Key" );
						pcsaListBox2->Add( "rcIbmF5Key" );
						pcsaListBox2->Add( "rcIbmF6Key" );
						pcsaListBox2->Add( "rcIbmF7Key" );
						pcsaListBox2->Add( "rcIbmF8Key" );
						pcsaListBox2->Add( "rcIbmF9Key" );
						pcsaListBox2->Add( "rcIbmF10Key" );
						pcsaListBox2->Add( "rcIbmF11Key" );
						pcsaListBox2->Add( "rcIbmF12Key" );
						pcsaListBox2->Add( "rcIbmF13Key" );
						pcsaListBox2->Add( "rcIbmF14Key" );
						pcsaListBox2->Add( "rcIbmF15Key" );
						pcsaListBox2->Add( "rcIbmF16Key" );
						pcsaListBox2->Add( "rcIbmF17Key" );
						pcsaListBox2->Add( "rcIbmF18Key" );
						pcsaListBox2->Add( "rcIbmF19Key" );
						pcsaListBox2->Add( "rcIbmF20Key" );
						pcsaListBox2->Add( "rcIbmF21Key" );
						pcsaListBox2->Add( "rcIbmF22Key" );
						pcsaListBox2->Add( "rcIbmF23Key" );
						pcsaListBox2->Add( "rcIbmF24Key" );
						pcsaListBox2->Add( "rcIbmFieldDelimKey" );
						pcsaListBox2->Add( "rcIbmFieldExitKey" );
						pcsaListBox2->Add( "rcIbmFieldMarkKey" );
						pcsaListBox2->Add( "rcIbmFieldMinusKey" );
						pcsaListBox2->Add( "rcIbmFieldPlusKey" );
						pcsaListBox2->Add( "rcIbmHelpKey" );
						pcsaListBox2->Add( "rcIbmHexKey" );
						pcsaListBox2->Add( "rcIbmHomeKey" );
						pcsaListBox2->Add( "rcIbmIdentKey" );
						pcsaListBox2->Add( "rcIbmInsertKey" );
						pcsaListBox2->Add( "rcIbmKeyClickKey" );
						pcsaListBox2->Add( "rcIbmLeftDoubleKey" );
						pcsaListBox2->Add( "rcIbmLeftKey" );
						pcsaListBox2->Add( "rcIbmNewLineKey" );
						pcsaListBox2->Add( "rcIbmPa1Key" );
						pcsaListBox2->Add( "rcIbmPa2Key" );
						pcsaListBox2->Add( "rcIbmPa3Key" );
						pcsaListBox2->Add( "rcIbmPageDownKey" );
						pcsaListBox2->Add( "rcIbmPageUpKey" );
						pcsaListBox2->Add( "rcIbmPanLeftKey" );
						pcsaListBox2->Add( "rcIbmPanRightKey" );
						pcsaListBox2->Add( "rcIbmPartitionJumpKey" );
						pcsaListBox2->Add( "rcIbmPf1Key" );
						pcsaListBox2->Add( "rcIbmPf2Key" );
						pcsaListBox2->Add( "rcIbmPf3Key" );
						pcsaListBox2->Add( "rcIbmPf4Key" );
						pcsaListBox2->Add( "rcIbmPf5Key" );
						pcsaListBox2->Add( "rcIbmPf6Key" );
						pcsaListBox2->Add( "rcIbmPf7Key" );
						pcsaListBox2->Add( "rcIbmPf8Key" );
						pcsaListBox2->Add( "rcIbmPf9Key" );
						pcsaListBox2->Add( "rcIbmPf10Key" );
						pcsaListBox2->Add( "rcIbmPf11Key" );
						pcsaListBox2->Add( "rcIbmPf12Key" );
						pcsaListBox2->Add( "rcIbmPf13Key" );
						pcsaListBox2->Add( "rcIbmPf14Key" );
						pcsaListBox2->Add( "rcIbmPf15Key" );
						pcsaListBox2->Add( "rcIbmPf16Key" );
						pcsaListBox2->Add( "rcIbmPf17Key" );
						pcsaListBox2->Add( "rcIbmPf18Key" );
						pcsaListBox2->Add( "rcIbmPf19Key" );
						pcsaListBox2->Add( "rcIbmPf20Key" );
						pcsaListBox2->Add( "rcIbmPf21Key" );
						pcsaListBox2->Add( "rcIbmPf22Key" );
						pcsaListBox2->Add( "rcIbmPf23Key" );
						pcsaListBox2->Add( "rcIbmPf24Key" );
						pcsaListBox2->Add( "rcIbmPlusCrKey" );
						pcsaListBox2->Add( "rcIbmPrintKey" );
						pcsaListBox2->Add( "rcIbmPrintPartKey" );
						pcsaListBox2->Add( "rcIbmResetKey" );
						pcsaListBox2->Add( "rcIbmRightDoubleKey" );
						pcsaListBox2->Add( "rcIbmRightKey" );
						pcsaListBox2->Add( "rcIbmRuleKey" );
						pcsaListBox2->Add( "rcIbmScrollDownKey" );
						pcsaListBox2->Add( "rcIbmScrollLeftKey" );
						pcsaListBox2->Add( "rcIbmScrollRightKey" );
						pcsaListBox2->Add( "rcIbmScrollUpKey" );
						pcsaListBox2->Add( "rcIbmSlpAutoEnterKey" );
						pcsaListBox2->Add( "rcIbmSysReqstKey" );
						pcsaListBox2->Add( "rcIbmTabKey" );
						pcsaListBox2->Add( "rcIbmTestKey" );
						pcsaListBox2->Add( "rcIbmUpKey" );

						Show1E1L3E1L( pcsaLabels, pcsaListBox, pcsaListBox2  );

					}
					break;


				}
		}
		break;


	
		case DOS_API:
		{
			switch ( uFunction )
			{
				case 0:    //Append
				{
					Show2E3C( pcsaLabels );
				}
				break;
			}
		}
		break;

		case UNIX_API:
		{
			switch ( uFunction )
			{
				case 0:		//cat - concatenate files
				{
					pcsaListBox->Add( "None" );
					pcsaListBox->Add( "-s suppress error messages" );
					pcsaListBox->Add( "-u do not buffer output" );
					pcsaListBox->Add( "-v display all characters" );
					pcsaListBox->Add( "-e end lines with $ character" );
					pcsaListBox->Add( "-t display tabs as ^I" );

					Show1ML2E( pcsaLabels, pcsaListBox );
				}
				break;

				case 2:    //chmod - change file access
				{
					pcsaListBox->Add( "None" );
					pcsaListBox->Add( "-f suppress error messages" );
					pcsaListBox->Add( "-R change all sub objects" );

					pcsaListBox2->Add( "u - set user permissions" );
					pcsaListBox2->Add( "g - set group permissions" );
					pcsaListBox2->Add( "o - set other permissions" );
					pcsaListBox2->Add( "a - set all permissions" );

					pcsaListBox3->Add( "+ - turn on permission" );
					pcsaListBox3->Add( "- - turn off permission" );
					pcsaListBox3->Add( "= - turn these on, others off" );

					pcsaListBox4->Add( "r - read permission" );
					pcsaListBox4->Add( "x - execute permission" );
					pcsaListBox4->Add( "X - Execute/search permission" );
					pcsaListBox4->Add( "w - write permission" );
					pcsaListBox4->Add( "h - hidden attribute" );
					pcsaListBox4->Add( "a - archive bit" );
					pcsaListBox4->Add( "s - setuid/system file" );
					pcsaListBox4->Add( "t - sticky bit/archive bit" );

					Show2ML1L1ML1E( pcsaLabels, pcsaListBox, pcsaListBox2, pcsaListBox3, pcsaListBox4 );
				}
				break;

				case 4:    //cp - copy files
				{
					pcsaListBox->Add( "None" );
					pcsaListBox->Add( "-r no special formats" );
					pcsaListBox->Add( "-R duplicates special files" );

					pcsaListBox2->Add( "None" );
					pcsaListBox2->Add( "-c - prompt on full diskette" );
					pcsaListBox2->Add( "-f - replace w/ no write permission" );
					pcsaListBox2->Add( "-i - prompt for overwrites" );
					pcsaListBox2->Add( "-m - preserve modify/access info" );
					pcsaListBox2->Add( "-p - m + mode and owners" );
					pcsaListBox2->Add( "-v - print names to stdio" );

					Show1L1ML2E( pcsaLabels, pcsaListBox, pcsaListBox2 );
				}
				break;

				case 5:    //csplit - split text file
				{
					pcsaListBox->Add( "None" );
					pcsaListBox->Add( "-a lowercase filename chars" );
					pcsaListBox->Add( "-A uppercase filename chars" );
					pcsaListBox->Add( "-k leave new files intact" );
					pcsaListBox->Add( "-e suppress file sizes" );

					Show1ML4E( pcsaLabels, pcsaListBox );
				}
				break;


				case 12:    //fgrep
				{
					pcsaListBox->Add( "None" );
					pcsaListBox->Add( "-b show file block #'s" );
					pcsaListBox->Add( "-c display line count" );
					pcsaListBox->Add( "-i ignore case" );
					pcsaListBox->Add( "-l only list file names" );
					pcsaListBox->Add( "-n show line numbers" );
					pcsaListBox->Add( "-q suppress output" );
					pcsaListBox->Add( "-s suppress error msgs" );
					pcsaListBox->Add( "-v show NON-matching lines" );
					pcsaListBox->Add( "-x entire line must match" );

					Show1ML3E( pcsaLabels, pcsaListBox );
				}
				break;


				case 13:    //grep
				{
					pcsaListBox->Add( "None" );
					pcsaListBox->Add( "-b show file block #'s" );
					pcsaListBox->Add( "-c display line count" );
					pcsaListBox->Add( "-E use basic regexp's" );
					pcsaListBox->Add( "-F do not use regexp's" );
					pcsaListBox->Add( "-i ignore case" );
					pcsaListBox->Add( "-l only list file names" );
					pcsaListBox->Add( "-n show line numbers" );
					pcsaListBox->Add( "-q suppress output" );
					pcsaListBox->Add( "-s suppress error msgs" );
					pcsaListBox->Add( "-v show NON-matching lines" );
					pcsaListBox->Add( "-x entire line must match" );

					Show1ML3E( pcsaLabels, pcsaListBox );
				}
				break;

			}
		}
		break;

		case CASL_API:
		{
			switch ( uFunction )
			{
				case 3:    //alarm
				{
					pcsaListBox->Add( "Short beep" );
					pcsaListBox->Add( "System asterisk" );
					pcsaListBox->Add( "System exclamation" );
					pcsaListBox->Add( "System hand" );
					pcsaListBox->Add( "System question" );
					pcsaListBox->Add( "System default" );

					Show1L( pcsaLabels, pcsaListBox );
				}
				break;

				case 7:    //assume
				{
					pcsaListBox->Add( "No preference" );
					pcsaListBox->Add( "ICSTOOL" );

					pcsaListBox2->Add( "No preference" );
					pcsaListBox2->Add( "DCAT27" );
					pcsaListBox2->Add( "AMUTS" );

					pcsaListBox3->Add( "No preference" );
					pcsaListBox3->Add( "CANDE" );
					pcsaListBox3->Add( "OS2200" );
					pcsaListBox3->Add( "MAPPER" );
					pcsaListBox3->Add( "NOFT" );


					Show3L( pcsaLabels, pcsaListBox, pcsaListBox2, pcsaListBox3 );
				}
				break;

				case 8:    //backups
				{
					pcsaListBox->Add( "Rename with .bak" );
					pcsaListBox->Add( "Delete old file" );

					Show1L( pcsaLabels, pcsaListBox );
				}
				break;

				case 11:    //busycursor
				{
					pcsaListBox->Add( "On" );
					pcsaListBox->Add( "Off" );

					Show1L( pcsaLabels, pcsaListBox );
				}
				break;

				case 13:    //capture
				{
					pcsaListBox->Add("new");
					pcsaListBox->Add("to");
					pcsaListBox->Add("on");
					pcsaListBox->Add("pause");
					pcsaListBox->Add("toggle");
					pcsaListBox->Add("to");
					pcsaListBox->Add("off");

					Show1L1E( pcsaLabels, pcsaListBox );
				}
				break;

				case 15:    //chain
				case 50:    //do
				{
					Show1E1B1E( pcsaLabels );		
				}
				break;

				case 21:    //clear
				case 23:    //cls
				{
					pcsaListBox->Add("window");
					pcsaListBox->Add("line");
					pcsaListBox->Add("eow");
					pcsaListBox->Add("bow");
					pcsaListBox->Add("eol");
					pcsaListBox->Add("bol");

					Show1L( pcsaLabels, pcsaListBox );
				}
				break;

				case 25:    //compile
				case 119:    //new
				case 157:    //script
				case 161:    //send
				{
					Show1E1B( pcsaLabels );		
				}
				break;

				case 27:    //copy
				{
					Show1C2EB( pcsaLabels );		
				}
				break;

				case 42:    //delete
				case 44:    //description
				case 47:    //device
				case 118:    //netid
				case 133:    //password
				case 152:    //return
				{
					Show1C1E( pcsaLabels );		
				}
				break;

				case 49:    //display
				{
					Show1C( pcsaLabels );		
				}
				break;

				case 68:    //fnstrip
				{
					pcsaListBox->Add("Full filename");
					pcsaListBox->Add("Dir/name/extension");
					pcsaListBox->Add("Drive/name/extension");
					pcsaListBox->Add("Filename/extension");
					pcsaListBox->Add("Drive/directory/name");
					pcsaListBox->Add("Directory/filename");
					pcsaListBox->Add("Drive/filename");
					pcsaListBox->Add("Filename");

					Show1E1L( pcsaLabels, pcsaListBox );
				}
				break;

				case 74:    //genlabels
				{
					pcsaListBox->Add( "Suppress label info" );

					Show1C( pcsaLabels );
				}
				break;

				case 75:    //genlines
				{
					pcsaListBox->Add( "Suppress line info" );

					Show1C( pcsaLabels );
				}
				break;

				case 87:    //hms
				{
					pcsaListBox->Add("0:00:10.1");
					pcsaListBox->Add("10.1");
					pcsaListBox->Add("0:00:10");
					pcsaListBox->Add("10");
					pcsaListBox->Add("0h0m10.1s");
					pcsaListBox->Add("10.1s");
					pcsaListBox->Add("0h0m10s");
					pcsaListBox->Add("10s");
					pcsaListBox->Add("default");

					Show1E1L( pcsaLabels, pcsaListBox );
				}
				break;

				case 89:    //if/then/else
				{
					Show2E1C1E( pcsaLabels );
				}
				break;

				case 99:    //keys
				case 170:    //startup
				{
					Show1C1E1B( pcsaLabels );
				}
				break;

				case 129:    //open
				{
					pcsaListBox->Add("random");
					pcsaListBox->Add("input");
					pcsaListBox->Add("output");
					pcsaListBox->Add("append");

					Show1L1EB1E( pcsaLabels, pcsaListBox );
				}
				break;

				case 130:    //pack
				{
					pcsaListBox->Add("Consecutive wild chars");
					pcsaListBox->Add("Identical consecutive chars");

					Show2E1L( pcsaLabels, pcsaListBox );
				}
				break;

				case 131:    //pad
				{
					pcsaListBox->Add("Right side");
					pcsaListBox->Add("Left side");
					pcsaListBox->Add("Frame");

					Show3E1L( pcsaLabels, pcsaListBox );
				}
				break;

				case 136:    //press
				{
					pcsaListBox->Add("<F1>");
					pcsaListBox->Add("<F2>");
					pcsaListBox->Add("<F3>");
					pcsaListBox->Add("<F4>");
					pcsaListBox->Add("<F5>");
					pcsaListBox->Add("<F6>");
					pcsaListBox->Add("<F7>");
					pcsaListBox->Add("<F8>");
					pcsaListBox->Add("<F9>");
					pcsaListBox->Add("<F10>");
					pcsaListBox->Add("<F11>");
					pcsaListBox->Add("<F12>");
					pcsaListBox->Add("<Transmit>");
					pcsaListBox->Add("<up>");
					pcsaListBox->Add("<left>");
					pcsaListBox->Add("<Back>");

					Show1E1L( pcsaLabels, pcsaListBox );
				}
				break;

				case 138:    //printer
				{
					pcsaListBox->Add("Start");
					pcsaListBox->Add("Stop");

					Show1L( pcsaLabels, pcsaListBox );
				}
				break;

				case 140:    //protocol
				{
					pcsaListBox->Add("CANDE");
					pcsaListBox->Add("OS2200");
					pcsaListBox->Add("MAPPER");
					pcsaListBox->Add("NOFT");

					Show1C1L( pcsaLabels, pcsaListBox );
				}
				break;

				case 147:	//rename
				{
					Show1C2E( pcsaLabels );		
				}
				break;

				case 172:    //strip
				{
					pcsaListBox->Add("Remove all wild chars");
					pcsaListBox->Add("Stop at non-wild from right");
					pcsaListBox->Add("Stop at non-wild from left");
					pcsaListBox->Add("Stop at non-wild on both");

					Show2E1L( pcsaLabels, pcsaListBox );
				}
				break;

				case 177:    //terminal
				{
					pcsaListBox->Add("DCAT27");
					pcsaListBox->Add("AMUTS");

					Show1C1L( pcsaLabels, pcsaListBox );
				}
				break;

				case 181:    //trace
				{
					pcsaListBox->Add("Show line numbers");
					pcsaListBox->Add("Hide line numbers");

					Show1L( pcsaLabels, pcsaListBox );
				}
				break;

				case 184:    //trap
				{
					pcsaListBox->Add("Errors interrupt macros");
					pcsaListBox->Add("Errors ignored");

					Show1L( pcsaLabels, pcsaListBox );
				}
				break;

				case 189:    //userid
				{
					Show1C1E( pcsaLabels );
				}
				break;

				case 192:    //wait
				{
					pcsaListBox->Add("Wait for a string");
					pcsaListBox->Add("Wait for char count");

					Show1E1L1E( pcsaLabels, pcsaListBox );
				}
				break;

				case 193:    //watch/endwatch
				{
					pcsaListBox->Add("Wait for a string");
					pcsaListBox->Add("Wait for char count");

					Show1E1L2E( pcsaLabels, pcsaListBox );
				}
				break;



			}
		}
		break;

		case EAL_API:
		{
			switch ( uFunction )
			{
				case 17:	// ATMGetConnectionStatus
				{
					pcsaListBox->Add( "ATM_XSTATUS" );
					pcsaListBox->Add( "ATM_CONNECTION" );
					pcsaListBox->Add( "ATM_ERROR" );

					Show1L( pcsaLabels, pcsaListBox );
				}
				break;

				case 22:	// ATMGetFieldInfo
				{
					pcsaListBox->Add( "ATM_ISFIELDPROTECTED" );
					pcsaListBox->Add( "ATM_ISFIELDNUMERIC" );
					pcsaListBox->Add( "ATM_ISFIELDSELECTORPENDETECTABLE" );
					pcsaListBox->Add( "ATM_ISFIELDBOLD" );
					pcsaListBox->Add( "ATM_ISFIELDHIDDEN" );
					pcsaListBox->Add( "ATM_ISFIELDMODIFIED" );

					Show2E1L( pcsaLabels, pcsaListBox );
				}
				break;

				case 23:	// ATMGetFieldLength
				case 24:	// ATMGetFieldPosition
				{
					pcsaListBox->Add( "ATM_THISFIELD" );
					pcsaListBox->Add( "ATM_NEXTFIELD" );
					pcsaListBox->Add( "ATM_PREVIOUSFIELD" );
					pcsaListBox->Add( "ATM_NEXTPROTECTEDFIELD" );
					pcsaListBox->Add( "ATM_NEXTUNPROTECTEDFIELD" );
					pcsaListBox->Add( "ATM_PREVIOUSPROTECTEDFIELD" );
					pcsaListBox->Add( "ATM_PREVIOUSUNPROTECTEDFIELD" );

					Show2E1L( pcsaLabels, pcsaListBox );
				}
				break;

				case 29:	// ATMGetSessions
				{
					pcsaListBox->Add( "ATM_GETCONFIGURED" );
					pcsaListBox->Add( "ATM_GETOPENED" );
					pcsaListBox->Add( "ATM_GETPOWERED" );
					pcsaListBox->Add( "ATM_GET_CONFIGUREDCOUNT" );
					pcsaListBox->Add( "ATM_GETOPENEDCOUNT" );
					pcsaListBox->Add( "ATM_GETPOWEREDCOUNT" );
					pcsaListBox->Add( "ATM_GETEMULATED" );
					pcsaListBox->Add( "ATM_GETEMULATEDPOWERED" );
					pcsaListBox->Add( "ATM_GETEMULATEDCOUNT" );
					pcsaListBox->Add( "ATM_GETEMULATEDPOWEREDCOUNT" );

					Show1E1L( pcsaLabels, pcsaListBox );
				}
				break;

				case 31:	// ATMGetSessionStatus
				{
					pcsaListBox->Add( "ATM_ISCONFIGURED" );
					pcsaListBox->Add( "ATM_ISOPENED" );
					pcsaListBox->Add( "ATM_ISPOWERED" );
					pcsaListBox->Add( "ATM_ISEMULATED" );
					pcsaListBox->Add( "ATM_ISCONNECTED" );
					pcsaListBox->Add( "ATM_ISFILETRANSFER" );

					Show1E1L( pcsaLabels, pcsaListBox );
				}
				break;

				case 35:	// ATMListSessions
				{
					pcsaListBox->Add( "ATM_GETCONFIGURED" );
					pcsaListBox->Add( "ATM_GETOPENED" );
					pcsaListBox->Add( "ATM_GETPOWERED" );
					pcsaListBox->Add( "ATM_GETEMULATED" );
					pcsaListBox->Add( "ATM_GETEMULATEDPOWERED" );

					Show2E1L( pcsaLabels, pcsaListBox );
				}
				break;

				case 43:	// ATMRowColumn
				{
					pcsaListBox->Add( "ATM_GETROW" );
					pcsaListBox->Add( "ATM_GETCOLUMN" );

					Show1E1L( pcsaLabels, pcsaListBox );
				}
				break;

				case 46:	// ATMSearchSession
				{
					pcsaListBox->Add( "ATM_SEARCHALL" );
					pcsaListBox->Add( "ATM_SEARCHFROM" );
					pcsaListBox->Add( "ATM_SEARCHAT" );
					pcsaListBox->Add( "ATM_SEARCHBACK" );

					Show3E1L( pcsaLabels, pcsaListBox );
				}
				break;

				case 55:	// ATMSetParameter
				{
					pcsaListBox->Add( "ATM_ATTRIB" );
					pcsaListBox->Add( "ATM_AUTORESET" );
					pcsaListBox->Add( "ATM_CONNECTYPE" );
					pcsaListBox->Add( "ATM_EAB" );
					pcsaListBox->Add( "ATM_SEARCHORG" );
					pcsaListBox->Add( "ATM_SEARCH_DIRECTION" );
					pcsaListBox->Add( "ATM_TIMEOUT" );
					pcsaListBox->Add( "ATM_TRACE" );
					pcsaListBox->Add( "ATM_WAIT" );
					pcsaListBox->Add( "ATM_XLATE" );
					pcsaListBox->Add( "ATM_ESCAPE" );

					Show1L2E( pcsaLabels, pcsaListBox );
				}
				break;

				case 58:	// ATMStartSession
				{
					pcsaListBox->Add( "Normal" );
					pcsaListBox->Add( "Maximized" );
					pcsaListBox->Add( "Hidden" );
					pcsaListBox->Add( "Minimized" );

					Show1E1L( pcsaLabels, pcsaListBox );
				}
				break;



			}
			
		}
		break;

		case AIRJ_API:
		{
			switch ( uFunction )
			{
				case 8:		// IScreenUPG::fieldCount
				{
					pcsaListBox->Add( "FIELDTYPE_ANY" );
					pcsaListBox->Add( "FIELDTYPE_PROTECTED" );
					pcsaListBox->Add( "FIELDTYPE_UNPROTECTED" );

					Show1L( pcsaLabels, pcsaListBox );
				}
				break;

				case 9:		// IScreenUPG::findField
				{
					pcsaListBox->Add( "FINDFIELD_CURRENT" );
					pcsaListBox->Add( "FINDFIELD_NEXT" );
					pcsaListBox->Add( "FINDFIELD_PREVIOUS" );

					pcsaListBox2->Add( "FIELDTYPE_ANY" );
					pcsaListBox2->Add( "FIELDTYPE_PROTECTED" );
					pcsaListBox2->Add( "FIELDTYPE_UNPROTECTED" );

					Show2E2L1C( pcsaLabels, pcsaListBox, pcsaListBox2  );
				}
				break;

				case 10:	// IScreenUPG::findFieldEx				// 10
				{
					pcsaListBox->Add( "FINDFIELD_CURRENT" );
					pcsaListBox->Add( "FINDFIELD_NEXT" );
					pcsaListBox->Add( "FINDFIELD_PREVIOUS" );

					pcsaListBox2->Add( "FIELDTYPE_ANY" );
					pcsaListBox2->Add( "FIELDTYPE_PROTECTED" );
					pcsaListBox2->Add( "FIELDTYPE_UNPROTECTED" );

					Show1E2L1C( pcsaLabels, pcsaListBox, pcsaListBox2  );
				}
				break;

				case 12:	// IScreenUPG::findStringEx
				{
					pcsaListBox->Add( "DIRECTION_BACKWARD" );
					pcsaListBox->Add( "DIRECTION_FORWARD" );

					Show5E1C1L( pcsaLabels, pcsaListBox );
				}
				break;

				case 31:	// IScreenUPG::getStringEx
				{
					pcsaListBox->Add( "SCREENATTR_ANY" );
					pcsaListBox->Add( "SCREENATTR_HIDDEN" );
					pcsaListBox->Add( "SCREENATTR_PROTECTED" );
					pcsaListBox->Add( "SCREENATTR_UNPROTECTED" );
					pcsaListBox->Add( "SCREENATTR_VISIBLE" );

					Show4E1C1ML( pcsaLabels, pcsaListBox );
				}
				break;

				case 37:	// IScreenUPG::putStringEx
				{
					pcsaListBox->Add( "PUTSTRING_SKIP" );
					pcsaListBox->Add( "PUTSTRING_SPAN" );
					pcsaListBox->Add( "PUTSTRING_STOP" );

					Show5E1C1L1C( pcsaLabels, pcsaListBox );
				}
				break;


				case 39:	// IScreenUPG::sendKeys
				{
					pcsaListBox->Add( "KEYTYPE_HLLAPI" );
					pcsaListBox->Add( "KEYTYPE_BRACES" );

					Show1E1L( pcsaLabels, pcsaListBox );
				}
				break;

				case 43:	// IScreenUPG::setDataCapture
				case 45:	// IScreenUPG::setgetText_Display
				{
					Show1C( pcsaLabels );
				}
				break;

				case 58:	// SessionLoader::setTerminalType
				{
					pcsaListBox->Add( "T27" );
					pcsaListBox->Add( "UTS" );
					pcsaListBox->Add( "3270" );
					pcsaListBox->Add( "5250" );
					pcsaListBox->Add( "VT" );
					pcsaListBox->Add( "ALC" );

					Show1L( pcsaLabels, pcsaListBox );
				}
				break;

			}

		}
		break;

		case RWIN_OLE_API:
		{
			switch ( uFunction )
			{
				case 2:		// BackgroundColor
				case 42:	// ForegroundColor
				{
					pcsaListBox->Add( "rcPlainAttribute" );
					pcsaListBox->Add( "rcBlinkAttribute" );
					pcsaListBox->Add( "rcInverseAttribute" );
					pcsaListBox->Add( "rcUnderlineAttribute" );
					pcsaListBox->Add( "rcBoldAttribute" );
					pcsaListBox->Add( "rcHalfbrightAttribute" );
					pcsaListBox->Add( "rcFunctionKeys" );

					Show1L( pcsaLabels, pcsaListBox );
				}
				break;

				case 9:		// Clear
				{
					pcsaListBox->Add( "rcSelection" );
					pcsaListBox->Add( "rcScreen" );
					pcsaListBox->Add( "rcAll" );

					Show1L( pcsaLabels, pcsaListBox );
				}
				break;

				case 13:	// CommitLoginProperties
				{
					pcsaListBox->Add( "rcChangesAskUser" );
					pcsaListBox->Add( "rcChangesAlways" );
					pcsaListBox->Add( "rcChangesNever" );

					Show1L( pcsaLabels, pcsaListBox );
				}
				break;

				case 14:	// CompileScript
				{
					Show1E1B1C( pcsaLabels );
				}
				break;


				case 17:	// ConnectTemplate
				case 32:	// DisplayFile
				case 36:	// EvaluateRCLExpression
				case 38:	// ExecuteRCLCommand
				case 112:	// SetPropertyProfile
				case 119:	// StatusBox
				case 131:	// WaitEvent
				case 136:	// WaitForIncomingData
				{
					Show1E1C( pcsaLabels );
				}
				break;

				case 18:	// Copy
				{
					pcsaListBox->Add( "rcSelection" );
					pcsaListBox->Add( "rcScreen" );
					pcsaListBox->Add( "rcAll" );

					pcsaListBox2->Add( "rcAsPlainText" );
					pcsaListBox2->Add( "rcAsTableText" );
					pcsaListBox2->Add( "rcAsRichText" );
					pcsaListBox2->Add( "rcAsBitmap" );

					Show2L( pcsaLabels, pcsaListBox, pcsaListBox2  );
				}
				break;

				case 27:	// DefineEvent
				{
					pcsaListBox->Add( "rcSilence" );
					pcsaListBox->Add( "rcKbdEnabled" );
					pcsaListBox->Add( "rcEvConnected" );
					pcsaListBox->Add( "rcEvDisconnected" );
					pcsaListBox->Add( "rcEnterPos" );
					pcsaListBox->Add( "rcExitPos" );
					pcsaListBox->Add( "rcCommString" );
					pcsaListBox->Add( "rcDisplayString" );
					pcsaListBox->Add( "rcTimeOfDay" );
					pcsaListBox->Add( "rcTime" );
					pcsaListBox->Add( "rcBlockModeEnter" );
					pcsaListBox->Add( "rcBlockModeExit" );
					pcsaListBox->Add( "rcFileTransferDone" );
					pcsaListBox->Add( "rcTerminalKeystroke" );

					pcsaListBox2->Add( "key1" );
					pcsaListBox2->Add( "key2" );
					pcsaListBox2->Add( "look these up" );

					Show1E1L3E1L( pcsaLabels, pcsaListBox, pcsaListBox2  );
				}
				break;

				case 29:	// Dial
				{
					pcsaListBox->Add( "rcSpeakerOn" );
					pcsaListBox->Add( "rcSpeakerOff" );
					pcsaListBox->Add( "rcSpeakerDialing" );

					pcsaListBox2->Add( "rcSpeakerLow" );
					pcsaListBox2->Add( "rcSpeakerMedium" );
					pcsaListBox2->Add( "rcSpeakerHigh" );

					Show6E2L2C( pcsaLabels, pcsaListBox, pcsaListBox2  );
				}
				break;

				case 31:	// Display
				{
					pcsaListBox->Add( "rcNoTranslation" );
					pcsaListBox->Add( "rcHexData" );
					pcsaListBox->Add( "No preference" );

					Show1E1L( pcsaLabels, pcsaListBox );
				}
				break;

				case 35:	// EnableOnEvent
				{
					pcsaListBox->Add( "rcEnable" );
					pcsaListBox->Add( "rcDisable" );

					Show1E1L( pcsaLabels, pcsaListBox );
				}
				break;

				case 39:	// FindText
				{
					Show3E1C( pcsaLabels );
				}
				break;

				case 44:	// FTPReceiveFile
				case 45:	// FTPSendFile
				case 141:	// WRQReceiveFile
				case 142:	// WRQSendFile
				{
					pcsaListBox->Add( "rcASCII" );
					pcsaListBox->Add( "rcBinary" );
					pcsaListBox->Add( "rcAutoDetect" );

					pcsaListBox2->Add( "rcAskUser" );
					pcsaListBox2->Add( "rcCancel" );
					pcsaListBox2->Add( "rcUpdate" );
					pcsaListBox2->Add( "rcDelete" );
					pcsaListBox2->Add( "rcAppend" );
					pcsaListBox2->Add( "rcRename" );
					pcsaListBox2->Add( "rcSkip" );

					Show2E2L3E( pcsaLabels, pcsaListBox, pcsaListBox2  );
				}
				break;

				case 47:	// FTPStartServer
				{
					pcsaListBox->Add( "rcAnonymous" );
					pcsaListBox->Add( "rcNoLoginDialog" );

					Show3E1L( pcsaLabels, pcsaListBox );
				}
				break;
					
				case 49:	// GetAnsiColorRGB
				{
					pcsaListBox->Add( "rcAnsiBlack" );
					pcsaListBox->Add( "rcAnsiBlue" );
					pcsaListBox->Add( "rcAnsiGreen" );
					pcsaListBox->Add( "rcAnsiCyan" );
					pcsaListBox->Add( "rcAnsiRed" );
					pcsaListBox->Add( "rcAnsiMagenta" );
					pcsaListBox->Add( "rcAnsiBrown" );
					pcsaListBox->Add( "rcAnsiWhite" );
					pcsaListBox->Add( "rcAnsiGrey (SCO-ANSI)" );
					pcsaListBox->Add( "rcAnsiLtBlue (SCO-ANSI)" );
					pcsaListBox->Add( "rcAnsiLtGreen (SCO-ANSI)" );
					pcsaListBox->Add( "rcAnsiLtCyan (SCO-ANSI)" );
					pcsaListBox->Add( "rcAnsiLtRed (SCO-ANSI)" );
					pcsaListBox->Add( "rcAnsiLtMagenta (SCO-ANSI)" );
					pcsaListBox->Add( "rcAnsiYellow (SCO-ANSI)" );
					pcsaListBox->Add( "rcAnsiLtWhite (SCO-ANSI)" );

					pcsaListBox2->Add( "rcRed" );
					pcsaListBox2->Add( "rcGreen" );
					pcsaListBox2->Add( "rcBlue" );

					Show2L( pcsaLabels, pcsaListBox, pcsaListBox2  );
				}
				break;

				case 51:	// GetColorRGB
				{
					pcsaListBox->Add( "rcWhite" );
					pcsaListBox->Add( "rcGrey" );
					pcsaListBox->Add( "rcRed" );
					pcsaListBox->Add( "rcBlue" );
					pcsaListBox->Add( "rcGreen" );
					pcsaListBox->Add( "rcYellow" );
					pcsaListBox->Add( "rcCyan" );
					pcsaListBox->Add( "rcMagenta" );
					pcsaListBox->Add( "rcBlack" );
					pcsaListBox->Add( "rcDkGrey" );
					pcsaListBox->Add( "rcDkRed" );
					pcsaListBox->Add( "rcDkBlue" );
					pcsaListBox->Add( "rcDkGreen" );
					pcsaListBox->Add( "rcDkYellow" );
					pcsaListBox->Add( "rcDkCyan" );
					pcsaListBox->Add( "rcDkMagenta" );					

					pcsaListBox2->Add( "rcRed" );
					pcsaListBox2->Add( "rcGreen" );
					pcsaListBox2->Add( "rcBlue" );

					Show2L( pcsaLabels, pcsaListBox, pcsaListBox2  );
				}
				break;

				case 52:	// GetCommandGroupProfile
				{
					pcsaListBox->Add( "rcSetup" );
					pcsaListBox->Add( "rcFileTransfer" );
					pcsaListBox->Add( "rcFileTransferReceive" );
					pcsaListBox->Add( "rcFileTransferSend" );
					pcsaListBox->Add( "rcTracing" );
					pcsaListBox->Add( "rcHostDirectory" );
					pcsaListBox->Add( "rcSavePasswords" );
					pcsaListBox->Add( "rcMenus" );
					pcsaListBox->Add( "rcVB" );
					pcsaListBox->Add( "rcHost" );
					pcsaListBox->Add( "rcVBLocal" );
					pcsaListBox->Add( "rcOLEAutomation" );
					pcsaListBox->Add( "rcRCL" );
					pcsaListBox->Add( "rcRCLLocal" );

					Show1L( pcsaLabels, pcsaListBox );
				}
				break;
					
				case 56:	// GetKeymapCommandArgs
				case 57:	// GetKeymapCommands
				case 58:	// GetKeymapCommandType
				{
					pcsaListBox->Add( "rcNormalKey" );
					pcsaListBox->Add( "rcAltKey" );
					pcsaListBox->Add( "rcCtrlKey" );
					pcsaListBox->Add( "rcShiftKey" );
					
					pcsaListBox2->Add( "Esc" );
					pcsaListBox2->Add( "A" );
					pcsaListBox2->Add( "B" );
					pcsaListBox2->Add( "C" );
					pcsaListBox2->Add( "D" );
					pcsaListBox2->Add( "E" );
					pcsaListBox2->Add( "F" );
					pcsaListBox2->Add( "G" );
					pcsaListBox2->Add( "H" );
					pcsaListBox2->Add( "I" );
					pcsaListBox2->Add( "J" );
					pcsaListBox2->Add( "K" );
					pcsaListBox2->Add( "L" );
					pcsaListBox2->Add( "M" );
					pcsaListBox2->Add( "N" );
					pcsaListBox2->Add( "O" );
					pcsaListBox2->Add( "P" );
					pcsaListBox2->Add( "Q" );
					pcsaListBox2->Add( "R" );
					pcsaListBox2->Add( "S" );
					pcsaListBox2->Add( "T" );
					pcsaListBox2->Add( "U" );
					pcsaListBox2->Add( "V" );
					pcsaListBox2->Add( "W" );
					pcsaListBox2->Add( "X" );
					pcsaListBox2->Add( "Y" );
					pcsaListBox2->Add( "Z" );

					pcsaListBox2->Add( "Apostrophe" );
					pcsaListBox2->Add( "BackSlash" );
					pcsaListBox2->Add( "Backspace" );
					pcsaListBox2->Add( "Break" );
					pcsaListBox2->Add( "BS" );
					pcsaListBox2->Add( "CapsLock" );
					pcsaListBox2->Add( "Center" );
					pcsaListBox2->Add( "CloseBracket" );
					pcsaListBox2->Add( "Comma" );
					pcsaListBox2->Add( "Compose" );
					pcsaListBox2->Add( "CR" );
					pcsaListBox2->Add( "Dash" );
					pcsaListBox2->Add( "Delete" );
					pcsaListBox2->Add( "Do" );
					pcsaListBox2->Add( "Equals" );
					pcsaListBox2->Add( "Escape" );
					pcsaListBox2->Add( "NumLock" );
					pcsaListBox2->Add( "OpenBracket" );
					pcsaListBox2->Add( "Period" );
					pcsaListBox2->Add( "PrintScreen" );
					pcsaListBox2->Add( "ScrollLock" );
					pcsaListBox2->Add( "Semicolon" );
					pcsaListBox2->Add( "Slash" );
					pcsaListBox2->Add( "Space" );
					pcsaListBox2->Add( "Tab" );
					pcsaListBox2->Add( "Up" );

					pcsaListBox2->Add( "F1" );
					pcsaListBox2->Add( "F2" );
					pcsaListBox2->Add( "F3" );
					pcsaListBox2->Add( "F4" );
					pcsaListBox2->Add( "F5" );
					pcsaListBox2->Add( "F6" );
					pcsaListBox2->Add( "F7" );
					pcsaListBox2->Add( "F8" );
					pcsaListBox2->Add( "F9" );
					pcsaListBox2->Add( "F10" );
					pcsaListBox2->Add( "F11" );
					pcsaListBox2->Add( "F12" );
					pcsaListBox2->Add( "F13" );
					pcsaListBox2->Add( "F14" );
					pcsaListBox2->Add( "F15" );
					pcsaListBox2->Add( "F16" );
					pcsaListBox2->Add( "F17" );
					pcsaListBox2->Add( "F18" );
					pcsaListBox2->Add( "F19" );
					pcsaListBox2->Add( "F20" );

					pcsaListBox2->Add( "CpDel" );
					pcsaListBox2->Add( "CpDelete" );
					pcsaListBox2->Add( "CpDown" );
					pcsaListBox2->Add( "CpEnd" );
					pcsaListBox2->Add( "CpHome" );
					pcsaListBox2->Add( "CpIns" );
					pcsaListBox2->Add( "CpInsert" );
					pcsaListBox2->Add( "CpLeft" );
					pcsaListBox2->Add( "CpPageDown" );
					pcsaListBox2->Add( "CpPageUp" );
					pcsaListBox2->Add( "CpPgDn" );
					pcsaListBox2->Add( "CpPgUp" );
					pcsaListBox2->Add( "CpRight" );
					pcsaListBox2->Add( "CpUp" );

					pcsaListBox2->Add( "CpEnter" );
					pcsaListBox2->Add( "Del" );
					pcsaListBox2->Add( "Kp0" );
					pcsaListBox2->Add( "Kp1" );
					pcsaListBox2->Add( "Kp2" );
					pcsaListBox2->Add( "Kp3" );
					pcsaListBox2->Add( "Kp4" );
					pcsaListBox2->Add( "Kp5" );
					pcsaListBox2->Add( "Kp6" );
					pcsaListBox2->Add( "Kp7" );
					pcsaListBox2->Add( "Kp8" );
					pcsaListBox2->Add( "Kp9" );
					pcsaListBox2->Add( "KPCenter" );
					pcsaListBox2->Add( "KpComma" );
					pcsaListBox2->Add( "KpDecimal" );
					pcsaListBox2->Add( "KpDivide" );
					pcsaListBox2->Add( "KpEnter" );
					pcsaListBox2->Add( "KpMinus" );
					pcsaListBox2->Add( "KpMultiply" );
					pcsaListBox2->Add( "KpPlus" );

					Show2L( pcsaLabels, pcsaListBox, pcsaListBox2  );
				}
				break;

				case 59:	// GetLoginProperty
				{
					Show4E1C( pcsaLabels );
				}
				break;

				case 64:	// GetSerialStatistics
				{
					pcsaListBox->Add( "rcReceiveOverruns" );
					pcsaListBox->Add( "rcParityErrors" );
					pcsaListBox->Add( "rcFramingErrors" );
					pcsaListBox->Add( "rcReceiveBufferOverflow" );
					pcsaListBox->Add( "rcBreakDetect" );

					Show1L( pcsaLabels, pcsaListBox );
				}
				break;

				case 65:	// GetText
				{
					pcsaListBox->Add( "rcRectRegion" );
					pcsaListBox->Add( "rcNoTranslation" );

					Show4E1L( pcsaLabels, pcsaListBox );
				}
				break;

				case 69:	// KermitReceiveFile
				{
					pcsaListBox->Add( "rcASCII" );
					pcsaListBox->Add( "rcBinary" );

					pcsaListBox2->Add( "rcAskUser" );
					pcsaListBox2->Add( "rcCancel" );
					pcsaListBox2->Add( "rcUpdate" );
					pcsaListBox2->Add( "rcDelete" );
					pcsaListBox2->Add( "rcAppend" );
					pcsaListBox2->Add( "rcRename" );

					Show2E2L( pcsaLabels, pcsaListBox, pcsaListBox2  );
				}
				break;

				case 70:	// KermitSendFile
				{
					pcsaListBox->Add( "rcASCII" );
					pcsaListBox->Add( "rcBinary" );
					pcsaListBox->Add( "rcAutoDetect" );

					Show2E1L( pcsaLabels, pcsaListBox );
				}
				break;

				case 72:	// KermitStopServer
				{
					pcsaListBox->Add( "rcNoLogoff" );
					pcsaListBox->Add( "rcLogoff" );

					Show1L( pcsaLabels, pcsaListBox );
				}
				break;

				case 73:	// LockProfile
				{
					Show1C1E( pcsaLabels );
				}
				break;

				case 75:	// NewSession
				{
					pcsaListBox->Add( "rcConnectionWizard" );
					pcsaListBox->Add( "rcReflection1" );
					pcsaListBox->Add( "rcReflection2" );
					pcsaListBox->Add( "rcReflection4" );
					pcsaListBox->Add( "rcReflectionIBM" );
					pcsaListBox->Add( "rcReflectionX" );
					pcsaListBox->Add( "rcFTPClient" );
					
					Show1L1E( pcsaLabels, pcsaListBox );
				}
				break;

				case 76:	// OnEvent
				{
					pcsaListBox->Add( "rcSilence" );
					pcsaListBox->Add( "rcKbdEnabled" );
					pcsaListBox->Add( "rcEvConnected" );
					pcsaListBox->Add( "rcEvDisconnected" );
					pcsaListBox->Add( "rcEnterPos" );
					pcsaListBox->Add( "rcExitPos" );
					pcsaListBox->Add( "rcCommString" );
					pcsaListBox->Add( "rcDisplayString" );
					pcsaListBox->Add( "rcTimeOfDay" );
					pcsaListBox->Add( "rcTime" );
					pcsaListBox->Add( "rcTerminalKeystroke" );
					pcsaListBox->Add( "rcBlockModeEnter" );
					pcsaListBox->Add( "rcBlockModeExit" );
					pcsaListBox->Add( "rcFileTransferDone" );
					pcsaListBox->Add( "rcReflectionStart" );
					pcsaListBox->Add( "rcReflectionExit" );
					pcsaListBox->Add( "rcLoadSettingsFile" );

					pcsaListBox2->Add( "rcBuiltInFunction" );
					pcsaListBox2->Add( "rcTransmitString" );
					pcsaListBox2->Add( "rcVBCommand" );
					pcsaListBox2->Add( "rcVBMacro" );
					pcsaListBox2->Add( "rcRBCommand" );
					pcsaListBox2->Add( "rcRBScript" );
					
					pcsaListBox3->Add( "rcEnable" );
					pcsaListBox3->Add( "rcDisable" );

					pcsaListBox4->Add( "rcEventEnable" );
					pcsaListBox4->Add( "rcEventReenable" );

					pcsaListBox5->Add( "Esc" );
					pcsaListBox5->Add( "A" );
					pcsaListBox5->Add( "B" );
					pcsaListBox5->Add( "C" );
					pcsaListBox5->Add( "D" );
					pcsaListBox5->Add( "E" );
					pcsaListBox5->Add( "F" );
					pcsaListBox5->Add( "G" );
					pcsaListBox5->Add( "H" );
					pcsaListBox5->Add( "I" );
					pcsaListBox5->Add( "J" );
					pcsaListBox5->Add( "K" );
					pcsaListBox5->Add( "L" );
					pcsaListBox5->Add( "M" );
					pcsaListBox5->Add( "N" );
					pcsaListBox5->Add( "O" );
					pcsaListBox5->Add( "P" );
					pcsaListBox5->Add( "Q" );
					pcsaListBox5->Add( "R" );
					pcsaListBox5->Add( "S" );
					pcsaListBox5->Add( "T" );
					pcsaListBox5->Add( "U" );
					pcsaListBox5->Add( "V" );
					pcsaListBox5->Add( "W" );
					pcsaListBox5->Add( "X" );
					pcsaListBox5->Add( "Y" );
					pcsaListBox5->Add( "Z" );

					pcsaListBox5->Add( "Apostrophe" );
					pcsaListBox5->Add( "BackSlash" );
					pcsaListBox5->Add( "Backspace" );
					pcsaListBox5->Add( "Break" );
					pcsaListBox5->Add( "BS" );
					pcsaListBox5->Add( "CapsLock" );
					pcsaListBox5->Add( "Center" );
					pcsaListBox5->Add( "CloseBracket" );
					pcsaListBox5->Add( "Comma" );
					pcsaListBox5->Add( "Compose" );
					pcsaListBox5->Add( "CR" );
					pcsaListBox5->Add( "Dash" );
					pcsaListBox5->Add( "Delete" );
					pcsaListBox5->Add( "Do" );
					pcsaListBox5->Add( "Equals" );
					pcsaListBox5->Add( "Escape" );
					pcsaListBox5->Add( "NumLock" );
					pcsaListBox5->Add( "OpenBracket" );
					pcsaListBox5->Add( "Period" );
					pcsaListBox5->Add( "PrintScreen" );
					pcsaListBox5->Add( "ScrollLock" );
					pcsaListBox5->Add( "Semicolon" );
					pcsaListBox5->Add( "Slash" );
					pcsaListBox5->Add( "Space" );
					pcsaListBox5->Add( "Tab" );
					pcsaListBox5->Add( "Up" );

					pcsaListBox5->Add( "F1" );
					pcsaListBox5->Add( "F2" );
					pcsaListBox5->Add( "F3" );
					pcsaListBox5->Add( "F4" );
					pcsaListBox5->Add( "F5" );
					pcsaListBox5->Add( "F6" );
					pcsaListBox5->Add( "F7" );
					pcsaListBox5->Add( "F8" );
					pcsaListBox5->Add( "F9" );
					pcsaListBox5->Add( "F10" );
					pcsaListBox5->Add( "F11" );
					pcsaListBox5->Add( "F12" );
					pcsaListBox5->Add( "F13" );
					pcsaListBox5->Add( "F14" );
					pcsaListBox5->Add( "F15" );
					pcsaListBox5->Add( "F16" );
					pcsaListBox5->Add( "F17" );
					pcsaListBox5->Add( "F18" );
					pcsaListBox5->Add( "F19" );
					pcsaListBox5->Add( "F20" );

					pcsaListBox5->Add( "CpDel" );
					pcsaListBox5->Add( "CpDelete" );
					pcsaListBox5->Add( "CpDown" );
					pcsaListBox5->Add( "CpEnd" );
					pcsaListBox5->Add( "CpHome" );
					pcsaListBox5->Add( "CpIns" );
					pcsaListBox5->Add( "CpInsert" );
					pcsaListBox5->Add( "CpLeft" );
					pcsaListBox5->Add( "CpPageDown" );
					pcsaListBox5->Add( "CpPageUp" );
					pcsaListBox5->Add( "CpPgDn" );
					pcsaListBox5->Add( "CpPgUp" );
					pcsaListBox5->Add( "CpRight" );
					pcsaListBox5->Add( "CpUp" );

					pcsaListBox5->Add( "CpEnter" );
					pcsaListBox5->Add( "Del" );
					pcsaListBox5->Add( "Kp0" );
					pcsaListBox5->Add( "Kp1" );
					pcsaListBox5->Add( "Kp2" );
					pcsaListBox5->Add( "Kp3" );
					pcsaListBox5->Add( "Kp4" );
					pcsaListBox5->Add( "Kp5" );
					pcsaListBox5->Add( "Kp6" );
					pcsaListBox5->Add( "Kp7" );
					pcsaListBox5->Add( "Kp8" );
					pcsaListBox5->Add( "Kp9" );
					pcsaListBox5->Add( "KPCenter" );
					pcsaListBox5->Add( "KpComma" );
					pcsaListBox5->Add( "KpDecimal" );
					pcsaListBox5->Add( "KpDivide" );
					pcsaListBox5->Add( "KpEnter" );
					pcsaListBox5->Add( "KpMinus" );
					pcsaListBox5->Add( "KpMultiply" );
					pcsaListBox5->Add( "KpPlus" );


					Show1E2L1E2L3E1L1E( pcsaLabels, pcsaListBox, pcsaListBox2, pcsaListBox3, pcsaListBox4, pcsaListBox5 );
				}
				break;

				case 77:	// OpenSettings
				{
					pcsaListBox->Add( "rcSettings" );
					pcsaListBox->Add( "rcColors" );
					pcsaListBox->Add( "rcConnection" );
					pcsaListBox->Add( "rcHotspots" );
					pcsaListBox->Add( "rcKeymap" );
					pcsaListBox->Add( "rcMenuMap" );
					pcsaListBox->Add( "rcToolbar" );

					Show1E1L( pcsaLabels, pcsaListBox );
				}
				break;

				case 78:	// OpenSettingsExtended
				{
					pcsaListBox->Add( "rcSettings" );
					pcsaListBox->Add( "rcColors" );
					pcsaListBox->Add( "rcConnection" );
					pcsaListBox->Add( "rcHotspots" );
					pcsaListBox->Add( "rcKeymap" );
					pcsaListBox->Add( "rcMenuMap" );
					pcsaListBox->Add( "rcToolbar" );

					Show1E1L1C( pcsaLabels, pcsaListBox );
				}
				break;

				case 81:	// PlaySound
				{
					Show1E1C( pcsaLabels );
				}
				break;

				case 84:	// PrintScreen
				{
					pcsaListBox->Add( "rcSelection" );
					pcsaListBox->Add( "rcScreen" );
					pcsaListBox->Add( "rcAll" );

					Show1L1E( pcsaLabels, pcsaListBox );
				}
				break;

				case 89:	// ReadChars
				case 91:	// ReadUntil
				{
					pcsaListBox->Add( "rcNoTranslation" );
					pcsaListBox->Add( "rcNoDisplay" );

					Show2E1L( pcsaLabels, pcsaListBox );
				}
				break;

				case 90:	// ReadLine
				{
					pcsaListBox->Add( "rcNoTranslation" );
					pcsaListBox->Add( "rcNoDisplay" );

					Show1E1L( pcsaLabels, pcsaListBox );
				}
				break;

				case 95:	// ResetTerminal
				{
					pcsaListBox->Add( "rcSoftReset" );
					pcsaListBox->Add( "rcHardReset" );
					pcsaListBox->Add( "rcSerialStats" );

					Show1L( pcsaLabels, pcsaListBox );
				}
				break;

				case 96:	// RestoreDefaults
				{
					pcsaListBox->Add( "rcSettings" );
					pcsaListBox->Add( "rcColors" );
					pcsaListBox->Add( "rcConnection" );
					pcsaListBox->Add( "rcHotspots" );
					pcsaListBox->Add( "rcKeymap" );
					pcsaListBox->Add( "rcMenuMap" );
					pcsaListBox->Add( "rcProfile" );
					pcsaListBox->Add( "rcToolbar" );

					Show1L( pcsaLabels, pcsaListBox );
				}
				break;

				case 101:	// SaveDisplayMemory
				{
					pcsaListBox->Add( "rcCancel" );
					pcsaListBox->Add( "rcOverwrite" );
					pcsaListBox->Add( "rcAppend" );

					Show1E1L1C( pcsaLabels, pcsaListBox );
				}
				break;

				case 102:	// SaveSettings
				{
					pcsaListBox->Add( "rcSettings" );
					pcsaListBox->Add( "rcColors" );
					pcsaListBox->Add( "rcConnection" );
					pcsaListBox->Add( "rcHotspots" );
					pcsaListBox->Add( "rcKeymap" );
					pcsaListBox->Add( "rcMenuMap" );
					pcsaListBox->Add( "rcToolbar" );

					pcsaListBox2->Add( "rcChangesAskUser" );
					pcsaListBox2->Add( "rcOverwrite" );
					pcsaListBox2->Add( "rcCancel" );

					Show1E2L( pcsaLabels, pcsaListBox, pcsaListBox2 );
				}
				break;

				case 103:	// SelectText
					{
						pcsaListBox->Add( "rcRectRegion" );
						pcsaListBox->Add( "rcWrappedRegion" );

						Show4E1L( pcsaLabels, pcsaListBox );
					}
					break;

				case 104:	// SetAnsiColorRGB
				case 107:	// SetColorRGB
					{
						pcsaListBox->Add( "rcAnsiBlack" );
						pcsaListBox->Add( "rcAnsiBlue" );
						pcsaListBox->Add( "rcAnsiGreen" );
						pcsaListBox->Add( "rcAnsiCyan" );
						pcsaListBox->Add( "rcAnsiRed" );
						pcsaListBox->Add( "rcAnsiMagenta" );
						pcsaListBox->Add( "rcAnsiBrown" );
						pcsaListBox->Add( "rcAnsiWhite" );
						pcsaListBox->Add( "rcAnsiGrey (SCO-ANSI)" );
						pcsaListBox->Add( "rcAnsiLtBlue (SCO-ANSI)" );
						pcsaListBox->Add( "rcAnsiLtGreen (SCO-ANSI)" );
						pcsaListBox->Add( "rcAnsiLtCyan (SCO-ANSI)" );
						pcsaListBox->Add( "rcAnsiLtRed (SCO-ANSI)" );
						pcsaListBox->Add( "rcAnsiLtMagenta (SCO-ANSI)" );
						pcsaListBox->Add( "rcAnsiYellow (SCO-ANSI)" );
						pcsaListBox->Add( "rcAnsiLtWhite (SCO-ANSI)" );

						Show1L3E( pcsaLabels, pcsaListBox );
					}
					break;

				case 106:	// SetColorMap
				{
					pcsaListBox->Add( "rcPlainAttribute" );
					pcsaListBox->Add( "rcBlinkAttribute" );
					pcsaListBox->Add( "rcInverseAttribute" );
					pcsaListBox->Add( "rcUnderlineAttribute" );
					pcsaListBox->Add( "rcBoldAttribute" );
					pcsaListBox->Add( "rcHalfbrightAttribute" );
					pcsaListBox->Add( "rcFunctionKeys" );

					pcsaListBox2->Add( "rcWhite" );
					pcsaListBox2->Add( "rcGrey" );
					pcsaListBox2->Add( "rcRed" );
					pcsaListBox2->Add( "rcBlue" );
					pcsaListBox2->Add( "rcGreen" );
					pcsaListBox2->Add( "rcYellow" );
					pcsaListBox2->Add( "rcCyan" );
					pcsaListBox2->Add( "rcMagenta" );
					pcsaListBox2->Add( "rcBlack" );
					pcsaListBox2->Add( "rcDkGrey" );
					pcsaListBox2->Add( "rcDkRed" );
					pcsaListBox2->Add( "rcDkBlue" );
					pcsaListBox2->Add( "rcDkGreen" );
					pcsaListBox2->Add( "rcDkYellow" );
					pcsaListBox2->Add( "rcDkCyan" );
					pcsaListBox2->Add( "rcDkMagenta" );					

					pcsaListBox3->Add( "rcWhite" );
					pcsaListBox3->Add( "rcGrey" );
					pcsaListBox3->Add( "rcRed" );
					pcsaListBox3->Add( "rcBlue" );
					pcsaListBox3->Add( "rcGreen" );
					pcsaListBox3->Add( "rcYellow" );
					pcsaListBox3->Add( "rcCyan" );
					pcsaListBox3->Add( "rcMagenta" );
					pcsaListBox3->Add( "rcBlack" );
					pcsaListBox3->Add( "rcDkGrey" );
					pcsaListBox3->Add( "rcDkRed" );
					pcsaListBox3->Add( "rcDkBlue" );
					pcsaListBox3->Add( "rcDkGreen" );
					pcsaListBox3->Add( "rcDkYellow" );
					pcsaListBox3->Add( "rcDkCyan" );
					pcsaListBox3->Add( "rcDkMagenta" );					

					Show3L( pcsaLabels, pcsaListBox, pcsaListBox2, pcsaListBox3 );
				}
				break;

				case 108:	// SetCommandGroupProfile
				{
					pcsaListBox->Add( "rcSetup" );
					pcsaListBox->Add( "rcFileTransfer" );
					pcsaListBox->Add( "rcFileTransferReceive" );
					pcsaListBox->Add( "rcFileTransferSend" );
					pcsaListBox->Add( "rcTracing" );
					pcsaListBox->Add( "rcHostDirectory" );
					pcsaListBox->Add( "rcSavePasswords" );
					pcsaListBox->Add( "rcMenus" );
					pcsaListBox->Add( "rcVB" );
					pcsaListBox->Add( "rcHost" );
					pcsaListBox->Add( "rcVBLocal" );
					pcsaListBox->Add( "rcOLEAutomation" );
					pcsaListBox->Add( "rcRCL" );
					pcsaListBox->Add( "rcRCLLocal" );

					pcsaListBox2->Add( "rcEnabled" );
					pcsaListBox2->Add( "rcDisabled" );

					Show2L( pcsaLabels, pcsaListBox, pcsaListBox2 );
				}
				break;
	
				case 109:	// SetCommandProfile
				{
					pcsaListBox->Add( "rcEnabled" );
					pcsaListBox->Add( "rcDisabled" );

					Show1E1L( pcsaLabels, pcsaListBox );
				}
				break;
	
				case 110:	// SetKeyMap
				{
					pcsaListBox->Add( "rcNormalKey" );
					pcsaListBox->Add( "rcAltKey" );
					pcsaListBox->Add( "rcCtrlKey" );
					pcsaListBox->Add( "rcShiftKey" );
					
					pcsaListBox2->Add( "Esc" );
					pcsaListBox2->Add( "A" );
					pcsaListBox2->Add( "B" );
					pcsaListBox2->Add( "C" );
					pcsaListBox2->Add( "D" );
					pcsaListBox2->Add( "E" );
					pcsaListBox2->Add( "F" );
					pcsaListBox2->Add( "G" );
					pcsaListBox2->Add( "H" );
					pcsaListBox2->Add( "I" );
					pcsaListBox2->Add( "J" );
					pcsaListBox2->Add( "K" );
					pcsaListBox2->Add( "L" );
					pcsaListBox2->Add( "M" );
					pcsaListBox2->Add( "N" );
					pcsaListBox2->Add( "O" );
					pcsaListBox2->Add( "P" );
					pcsaListBox2->Add( "Q" );
					pcsaListBox2->Add( "R" );
					pcsaListBox2->Add( "S" );
					pcsaListBox2->Add( "T" );
					pcsaListBox2->Add( "U" );
					pcsaListBox2->Add( "V" );
					pcsaListBox2->Add( "W" );
					pcsaListBox2->Add( "X" );
					pcsaListBox2->Add( "Y" );
					pcsaListBox2->Add( "Z" );

					pcsaListBox2->Add( "Apostrophe" );
					pcsaListBox2->Add( "BackSlash" );
					pcsaListBox2->Add( "Backspace" );
					pcsaListBox2->Add( "Break" );
					pcsaListBox2->Add( "BS" );
					pcsaListBox2->Add( "CapsLock" );
					pcsaListBox2->Add( "Center" );
					pcsaListBox2->Add( "CloseBracket" );
					pcsaListBox2->Add( "Comma" );
					pcsaListBox2->Add( "Compose" );
					pcsaListBox2->Add( "CR" );
					pcsaListBox2->Add( "Dash" );
					pcsaListBox2->Add( "Delete" );
					pcsaListBox2->Add( "Do" );
					pcsaListBox2->Add( "Equals" );
					pcsaListBox2->Add( "Escape" );
					pcsaListBox2->Add( "NumLock" );
					pcsaListBox2->Add( "OpenBracket" );
					pcsaListBox2->Add( "Period" );
					pcsaListBox2->Add( "PrintScreen" );
					pcsaListBox2->Add( "ScrollLock" );
					pcsaListBox2->Add( "Semicolon" );
					pcsaListBox2->Add( "Slash" );
					pcsaListBox2->Add( "Space" );
					pcsaListBox2->Add( "Tab" );
					pcsaListBox2->Add( "Up" );

					pcsaListBox2->Add( "F1" );
					pcsaListBox2->Add( "F2" );
					pcsaListBox2->Add( "F3" );
					pcsaListBox2->Add( "F4" );
					pcsaListBox2->Add( "F5" );
					pcsaListBox2->Add( "F6" );
					pcsaListBox2->Add( "F7" );
					pcsaListBox2->Add( "F8" );
					pcsaListBox2->Add( "F9" );
					pcsaListBox2->Add( "F10" );
					pcsaListBox2->Add( "F11" );
					pcsaListBox2->Add( "F12" );
					pcsaListBox2->Add( "F13" );
					pcsaListBox2->Add( "F14" );
					pcsaListBox2->Add( "F15" );
					pcsaListBox2->Add( "F16" );
					pcsaListBox2->Add( "F17" );
					pcsaListBox2->Add( "F18" );
					pcsaListBox2->Add( "F19" );
					pcsaListBox2->Add( "F20" );

					pcsaListBox2->Add( "CpDel" );
					pcsaListBox2->Add( "CpDelete" );
					pcsaListBox2->Add( "CpDown" );
					pcsaListBox2->Add( "CpEnd" );
					pcsaListBox2->Add( "CpHome" );
					pcsaListBox2->Add( "CpIns" );
					pcsaListBox2->Add( "CpInsert" );
					pcsaListBox2->Add( "CpLeft" );
					pcsaListBox2->Add( "CpPageDown" );
					pcsaListBox2->Add( "CpPageUp" );
					pcsaListBox2->Add( "CpPgDn" );
					pcsaListBox2->Add( "CpPgUp" );
					pcsaListBox2->Add( "CpRight" );
					pcsaListBox2->Add( "CpUp" );

					pcsaListBox2->Add( "CpEnter" );
					pcsaListBox2->Add( "Del" );
					pcsaListBox2->Add( "Kp0" );
					pcsaListBox2->Add( "Kp1" );
					pcsaListBox2->Add( "Kp2" );
					pcsaListBox2->Add( "Kp3" );
					pcsaListBox2->Add( "Kp4" );
					pcsaListBox2->Add( "Kp5" );
					pcsaListBox2->Add( "Kp6" );
					pcsaListBox2->Add( "Kp7" );
					pcsaListBox2->Add( "Kp8" );
					pcsaListBox2->Add( "Kp9" );
					pcsaListBox2->Add( "KPCenter" );
					pcsaListBox2->Add( "KpComma" );
					pcsaListBox2->Add( "KpDecimal" );
					pcsaListBox2->Add( "KpDivide" );
					pcsaListBox2->Add( "KpEnter" );
					pcsaListBox2->Add( "KpMinus" );
					pcsaListBox2->Add( "KpMultiply" );
					pcsaListBox2->Add( "KpPlus" );

					pcsaListBox3->Add( "rcBuiltInFunction" );
					pcsaListBox3->Add( "rcTransmitString" );
					pcsaListBox3->Add( "rcDefaultMap" );
					pcsaListBox3->Add( "rcVBCommand" );
					pcsaListBox3->Add( "rcVBMacro" );
					pcsaListBox3->Add( "rcRCLommand" );
					pcsaListBox3->Add( "rcRBScript" );

					Show3L2E( pcsaLabels, pcsaListBox, pcsaListBox2, pcsaListBox3 );
				}
				break;

				case 111:	// SetMouseMap
				{
					pcsaListBox->Add( "rcNormalKey" );
					pcsaListBox->Add( "rcAltKey" );
					pcsaListBox->Add( "rcCtrlKey" );
					pcsaListBox->Add( "rcShiftKey" );
					
					pcsaListBox2->Add( "LeftBtn" );
					pcsaListBox2->Add( "MiddleBtn" );
					pcsaListBox2->Add( "RightBtn" );
					pcsaListBox2->Add( "LeftBtn_DblClk" );
					pcsaListBox2->Add( "MiddleBtn_DblClk" );
					pcsaListBox2->Add( "RightBtn_DblClk" );

					pcsaListBox3->Add( "rcBuiltInFunction" );
					pcsaListBox3->Add( "rcTransmitString" );
					pcsaListBox3->Add( "rcDefaultMap" );
					pcsaListBox3->Add( "rcVBCommand" );
					pcsaListBox3->Add( "rcVBMacro" );
					pcsaListBox3->Add( "rcRBScript" );

					Show3L2E( pcsaLabels, pcsaListBox, pcsaListBox2, pcsaListBox3 );
				}
				break;

				case 113:	// SetScanCodeName
				{
					pcsaListBox->Add( "rcExtendedScanCode" );
					pcsaListBox->Add( "rcExtendedE1ScanCode" );
					pcsaListBox->Add( "rcNormalScanCode" );
					
					Show1L2E( pcsaLabels, pcsaListBox );
				}
				break;
	
				case 116:	// StartRecordingExtended
				{
					pcsaListBox->Add( "rcWithPrompts" );
					pcsaListBox->Add( "rcSilently" );

					Show1L( pcsaLabels, pcsaListBox );
				}
				break;

				case 118:	// StartTrace
				{
					pcsaListBox->Add( "rcCancel" );
					pcsaListBox->Add( "rcOverWrite" );
					pcsaListBox->Add( "rcAppend" );

					pcsaListBox2->Add( "rcTraceDefault" );
					pcsaListBox2->Add( "rcTraceEvents" );
					pcsaListBox2->Add( "rcTraceTimed" );
					pcsaListBox2->Add( "rcTraceIncomingOnly" );

					Show1E2L( pcsaLabels, pcsaListBox, pcsaListBox2 );
				}
				break;

				case 121:	// StopRecording
				{
					pcsaListBox->Add( "rcRBSource" );
					pcsaListBox->Add( "rcVBSource" );
					pcsaListBox->Add( "rcRCLSource" );

					pcsaListBox2->Add( "rcCancel" );
					pcsaListBox2->Add( "rcOverwrite" );

					Show1E2L( pcsaLabels, pcsaListBox, pcsaListBox2 );
				}
				break;

				case 122:	// StopRecordingMacro
				{
					pcsaListBox->Add( "rcMacro" );
					pcsaListBox->Add( "rcClipboard" );
					pcsaListBox->Add( "rcDiscard" );
					
					Show1L2E( pcsaLabels, pcsaListBox );
				}
				break;
	
				case 126:	// Transmit
				{
					pcsaListBox->Add( "rcDecodePassword" );
					pcsaListBox->Add( "rcHexData" );
					pcsaListBox->Add( "rcIgnoreBlockMode" );
					pcsaListBox->Add( "rcNoTranslation" );
					pcsaListBox->Add( "No preference" );

					Show1E1L( pcsaLabels, pcsaListBox );
				}
				break;

				case 127:	// TransmitFile
				{
					pcsaListBox->Add( "rcNoTranslation" );
					pcsaListBox->Add( "rcNoDisplay" );
					pcsaListBox->Add( "No preference" );

					Show3E1L( pcsaLabels, pcsaListBox );
				}
				break;

				case 130:	// Wait
				case 135:	// WaitForHostTrigger
				{
					pcsaListBox->Add( "rcAllowKeystrokes" );
					pcsaListBox->Add( "rcNoDisplay" );
					pcsaListBox->Add( "No preference" );

					Show1E1L( pcsaLabels, pcsaListBox );
				}
				break;

				case 132:	// WaitEventNumber
				{
					Show2E1C( pcsaLabels );
				}
				break;

				case 134:	// WaitForEvent
				{
					pcsaListBox->Add( "rcSilence" );
					pcsaListBox->Add( "rcKbdEnabled" );
					pcsaListBox->Add( "rcEvConnected" );
					pcsaListBox->Add( "rcEvDisconnected" );
					pcsaListBox->Add( "rcEnterPos" );
					pcsaListBox->Add( "rcExitPos" );
					pcsaListBox->Add( "rcCommString" );
					pcsaListBox->Add( "rcDisplayString" );
					pcsaListBox->Add( "rcTimeOfDay" );
					pcsaListBox->Add( "rcTime" );
					pcsaListBox->Add( "rcBlockModeEnter" );
					pcsaListBox->Add( "rcBlockModeExit" );
					pcsaListBox->Add( "rcFileTransferDone" );
					pcsaListBox->Add( "rcTerminalKeystroke" );
					
					Show1L5E1C( pcsaLabels, pcsaListBox );
				}
				break;

		 		case 137:	// WaitForSilence
				{
					pcsaListBox->Add( "rcAllowKeystrokes" );
					pcsaListBox->Add( "rcNoDisplay" );
					pcsaListBox->Add( "No preference" );

					Show2E1L( pcsaLabels, pcsaListBox );
				}
				break;

				case 138:	// WaitForString
				{
					pcsaListBox->Add( "rcAllowKeystrokes" );
					pcsaListBox->Add( "rcNoDisplay" );
					pcsaListBox->Add( "rcNoTranslation" );
					pcsaListBox->Add( "rcHexData" );
					pcsaListBox->Add( "No preference" );

					Show2E1L( pcsaLabels, pcsaListBox );
				}
				break;

				case 139:	// WaitForStrings
				{
					pcsaListBox->Add( "rcAllowKeystrokes" );
					pcsaListBox->Add( "rcNoDisplay" );
					pcsaListBox->Add( "rcNoTranslation" );
					pcsaListBox->Add( "No preference" );

					Show2E1L( pcsaLabels, pcsaListBox );
				}
				break;

				case 140:	// WaitUntil
				{
					pcsaListBox->Add( "rcAllowKeystrokes" );
					pcsaListBox->Add( "rcNoDisplay" );
					pcsaListBox->Add( "No preference" );

					Show1E1L( pcsaLabels, pcsaListBox );
				}
				break;

				case 145:	// XmodemReceiveFile
				{
					pcsaListBox->Add( "rcASCII" );
					pcsaListBox->Add( "rcBinary" );

					pcsaListBox2->Add( "rcAskUser" );
					pcsaListBox2->Add( "rcCancel" );
					pcsaListBox2->Add( "rcDelete" );
					pcsaListBox2->Add( "rcAppend" );
					pcsaListBox2->Add( "No preference" );

					Show1E2L( pcsaLabels, pcsaListBox, pcsaListBox2 );
				}
				break;

				case 146:	// XmodemSendFile
				{
					pcsaListBox->Add( "rcASCII" );
					pcsaListBox->Add( "rcBinary" );
					pcsaListBox->Add( "rcAutoDetect" );

					Show1E1L( pcsaLabels, pcsaListBox );
				}
				break;

				case 147:	// ZmodemReceiveFile
				{
					pcsaListBox->Add( "rcASCII" );
					pcsaListBox->Add( "rcBinary" );

					pcsaListBox2->Add( "rcAskUser" );
					pcsaListBox2->Add( "rcCancel" );
					pcsaListBox2->Add( "rcDelete" );
					pcsaListBox2->Add( "rcAppend" );
					pcsaListBox2->Add( "rcRename" );
					pcsaListBox2->Add( "rcResume" );
					pcsaListBox2->Add( "rcUpdate" );
					pcsaListBox2->Add( "rcUseRemote" );
					pcsaListBox2->Add( "No preference" );

					Show2E2L( pcsaLabels, pcsaListBox, pcsaListBox2 );
				}
				break;

				case 148:	// ZmodemSendFile
				{
					pcsaListBox->Add( "rcASCII" );
					pcsaListBox->Add( "rcAutoDetect" );
					pcsaListBox->Add( "rcBinary" );

					Show2E1L( pcsaLabels, pcsaListBox );
				}
				break;




			}
		}
		break;

		case RWEB_API:
		{
				switch ( uFunction )
				{
					case 0:		// ECLField::clearField
					case 1:		// ECLField::equals
					case 2:		// ECLField::GetAttribute
					case 3:		// 	ECLField::GetEnd
					case 4:		// 	ECLField::GetEndCol
					case 5:		// 	ECLField::GetEndRow
					case 6:		// 	ECLField::GetLength
					case 9:		// ECLField::GetStart
					case 10:	// ECLField::GetStartCol
					case 11:	// ECLField::GetStartRow
					case 12:	// ECLField::GetString
					{

					}
					break;

					case 7:		//ECLField::GetScreen
					case 67:	// ECLPS::GetScreen 1
					{
						pcsaListBox->Add( "TEXT_PLANE" );
						pcsaListBox->Add( "COLOR_PLANE" );
						pcsaListBox->Add( "EXFIELD_PLANE" );
						pcsaListBox->Add( "DBCS_PLANE" );
						pcsaListBox->Add( "GRID_PLANE" );
						
						Show1E1L( pcsaLabels, pcsaListBox );
					}
					break;

					case 8:		// ECLField::GetScreen 2
					case 70:	// ECLPS::GetScreen 4
					{
						pcsaListBox->Add( "TEXT_PLANE" );
						pcsaListBox->Add( "COLOR_PLANE" );
						pcsaListBox->Add( "EXFIELD_PLANE" );
						pcsaListBox->Add( "DBCS_PLANE" );
						pcsaListBox->Add( "GRID_PLANE" );

						Show1L( pcsaLabels, pcsaListBox );
					}
					break;

					case 25:	// ECLFieldList::FindField 3
					case 90:	// ECLPS::SearchString
					case 93:	// ECLPS::SearchText
					{
						pcsaListBox->Add( "SEARCH_FORWARD" );
						pcsaListBox->Add( "SEARCH_BACKWARD" );

						Show1E1L( pcsaLabels, pcsaListBox );
					}
					break;
					
					case 26:	// ECLFieldList::FindField 4
					case 71:	// ECLPS::GetScreen 5
					case 75:	// ECLPS::GetScreenRect 3
					case 91:	// ECLPS::SearchString 2
					case 94:	// ECLPS::SearchText 2
					{
						pcsaListBox->Add( "SEARCH_FORWARD" );
						pcsaListBox->Add( "SEARCH_BACKWARD" );

						Show2E1L( pcsaLabels, pcsaListBox );
					}
					break;
					
					case 27:	// ECLFieldList::FindField 5
					case 72:	// ECLPS::GetScreen 6
					case 92:	// ECLPS::SearchString 3
					case 95:	// ECLPS::SearchText 3
					{
						pcsaListBox->Add( "SEARCH_FORWARD" );
						pcsaListBox->Add( "SEARCH_BACKWARD" );

						Show3E1L( pcsaLabels, pcsaListBox );
					}
					break;
					
					case 30:	// ECLFieldList::GetFirstField 2
					{
						pcsaListBox->Add( "ALL_FIELDS" );
						pcsaListBox->Add( "MODIFIED_FIELD" );
						pcsaListBox->Add( "UNMODIFIED_FIELD" );
						pcsaListBox->Add( "ALPHANUM_FIELD" );
						pcsaListBox->Add( "NUMERIC_FIELD" );
						pcsaListBox->Add( "HILIGHT_FIELD" );
						pcsaListBox->Add( "LOLIGHT_FIELD" );
						pcsaListBox->Add( "PROTECTED_FIELD" );
						pcsaListBox->Add( "UNPROTECTED_FIELD" );
						pcsaListBox->Add( "DISPLAYABLE_FIELD" );
						pcsaListBox->Add( "NON_DISPLAYABLE_FIELD" );
						pcsaListBox->Add( "PENDETECTABLE_FIELD" );
						pcsaListBox->Add( "NON_PENDETECTABLE_FIELD" );
						pcsaListBox->Add( "TRANSMIT_ONLY_FIELD" );
						pcsaListBox->Add( "NON_PENDETECTABLE_FIELD" );

						Show1L( pcsaLabels, pcsaListBox );
					}
					break;

					case 32:	// ECLFieldList::GetNextField 2
					{
						pcsaListBox->Add( "ALL_FIELDS" );
						pcsaListBox->Add( "MODIFIED_FIELD" );
						pcsaListBox->Add( "UNMODIFIED_FIELD" );
						pcsaListBox->Add( "ALPHANUM_FIELD" );
						pcsaListBox->Add( "NUMERIC_FIELD" );
						pcsaListBox->Add( "HILIGHT_FIELD" );
						pcsaListBox->Add( "LOLIGHT_FIELD" );
						pcsaListBox->Add( "PROTECTED_FIELD" );
						pcsaListBox->Add( "UNPROTECTED_FIELD" );
						pcsaListBox->Add( "DISPLAYABLE_FIELD" );
						pcsaListBox->Add( "NON_DISPLAYABLE_FIELD" );
						pcsaListBox->Add( "PENDETECTABLE_FIELD" );
						pcsaListBox->Add( "NON_PENDETECTABLE_FIELD" );
						pcsaListBox->Add( "TRANSMIT_ONLY_FIELD" );
						pcsaListBox->Add( "NON_PENDETECTABLE_FIELD" );
						
						Show1E1L( pcsaLabels, pcsaListBox );
					}
					break;

					case 34:	// ECLFieldList::Refresh 2
					case 63:	// ECLPS::GetFieldList 2
					{
						pcsaListBox->Add( "TEXT_PLANE" );
						pcsaListBox->Add( "COLOR_PLANE" );
						pcsaListBox->Add( "FIELD_PLANE" );
						pcsaListBox->Add( "EXFIELD_PLANE" );
						pcsaListBox->Add( "DBCS_PLANE" );
						pcsaListBox->Add( "GRID_PLANE" );

						Show1L( pcsaLabels, pcsaListBox );
					}
					break;

					case 68:	// ECLPS::GetScreen 2
					case 73:	// ECLPS::GetScreenRect
					{
						pcsaListBox->Add( "TEXT_PLANE" );
						pcsaListBox->Add( "COLOR_PLANE" );
						pcsaListBox->Add( "FIELD_PLANE" );
						pcsaListBox->Add( "EXFIELD_PLANE" );
						pcsaListBox->Add( "DBCS_PLANE" );
						pcsaListBox->Add( "GRID_PLANE" );

						Show3E1L( pcsaLabels, pcsaListBox );
					}
					break;
					
					case 69:	// ECLPS::GetScreen 3
					case 76:	// ECLPS::GetScreenRect 4
					{
						pcsaListBox->Add( "TEXT_PLANE" );
						pcsaListBox->Add( "COLOR_PLANE" );
						pcsaListBox->Add( "FIELD_PLANE" );
						pcsaListBox->Add( "EXFIELD_PLANE" );
						pcsaListBox->Add( "DBCS_PLANE" );
						pcsaListBox->Add( "GRID_PLANE" );

						Show4E1L( pcsaLabels, pcsaListBox );
					}
					break;

					case 74:	// ECLPS::GetScreenRect 2
					{
						pcsaListBox->Add( "TEXT_PLANE" );
						pcsaListBox->Add( "COLOR_PLANE" );
						pcsaListBox->Add( "FIELD_PLANE" );
						pcsaListBox->Add( "EXFIELD_PLANE" );
						pcsaListBox->Add( "DBCS_PLANE" );
						pcsaListBox->Add( "GRID_PLANE" );

						Show5E1L( pcsaLabels, pcsaListBox );
					}
					break;

					case 89:	// ECLPS::RegisterPSEvent 2
					case 111:	// ECLPS::UnregisterPSEvent 2
					{
						pcsaListBox->Add( "ALL_EVENTS" );
						pcsaListBox->Add( "HOST_EVENTS" );
						pcsaListBox->Add( "USER_EVENTS" );

						Show1L( pcsaLabels, pcsaListBox );
					}
					break;


					case 101:	// ECLPS::SetCursorVisible
					case 214:	// ECLSession::ShowPSDebugger
					{
						Show1C( pcsaLabels );
					}
					break;


					case 113:	// ECLPS::WaitForCursor 2
					case 122:	// ECLPS::WaitWhileCursor 2
					case 145:	// ECLSession::findText
					{
						Show3E1C( pcsaLabels );
					}
					break;

					case 120:	// ECLPS::WaitForString 3
					{
						Show4E2C( pcsaLabels );
					}
					break;


					case 127:	// ECLPS::WaitWhileString 3
					case 191:	// ECLSession::makeTextSelection
					case 229:	// ECLSession::waitWhileDisplayString 3
					case 152:	// ECLSession::ftpLogin
					{
						Show4E1C( pcsaLabels );
					}
					break;

					case 130:	// ECLSession::apvuReceiveFile
					case 131:	// ECLSession::apvuSendFile
					{
						pcsaListBox->Add( "ID_HOST_TYPE_CICS" );
						pcsaListBox->Add( "ID_HOST_TYPE_CMS" );
						pcsaListBox->Add( "ID_HOST_TYPE_TSO" );

						Show2E1L1C( pcsaLabels, pcsaListBox );
					}
					break;

					case 155:	// ECLSession::ftpReceiveFiles
					case 157:	// ECLSession::ftpSendFiles
					{
						
						pcsaListBox->Add( "ID_HOST_TYPE_CICS" );
						pcsaListBox->Add( "ID_HOST_TYPE_CMS" );
						pcsaListBox->Add( "ID_HOST_TYPE_TSO" );

						Show1E1L( pcsaLabels, pcsaListBox );

					}
					break;



					case 137:	// ECLSession::display
					case 192:	// ECLSession::passwordPrompt
					case 203:	// ECLSession::setBoolean
					case 227:	// ECLSession::waitWhileDisplayString	
					{
						Show1E1C( pcsaLabels );
					}
					break;

					case 144:	// ECLSession::findField
					{
						pcsaListBox->Add( "SEARCH_FORWARD" );
						pcsaListBox->Add( "SEARCH_BACKWARD" );

						pcsaListBox2->Add( "ALL_FIELDS" );
						pcsaListBox2->Add( "MODIFIED_FIELD" );
						pcsaListBox2->Add( "UNMODIFIED_FIELD" );
						pcsaListBox2->Add( "ALPHANUM_FIELD" );
						pcsaListBox2->Add( "NUMERIC_FIELD" );
						pcsaListBox2->Add( "HILIGHT_FIELD" );
						pcsaListBox2->Add( "LOLIGHT_FIELD" );
						pcsaListBox2->Add( "PROTECTED_FIELD" );
						pcsaListBox2->Add( "UNPROTECTED_FIELD" );
						pcsaListBox2->Add( "DISPLAYABLE_FIELD" );
						pcsaListBox2->Add( "NON_DISPLAYABLE_FIELD" );
						pcsaListBox2->Add( "PENDETECTABLE_FIELD" );
						pcsaListBox2->Add( "NON_PENDETECTABLE_FIELD" );
						pcsaListBox2->Add( "TRANSMIT_ONLY_FIELD" );
						pcsaListBox2->Add( "NON_PENDETECTABLE_FIELD" );

						Show2E2L( pcsaLabels, pcsaListBox, pcsaListBox2  );
					}
					break;

					case 154:	// ECLSession::ftpReceiveFile
					{
						Show2E1C( pcsaLabels );
					}
					break;

					case 156:	// ECLSession::ftpSendFile
					case 185:	// ECLSession::indReceiveFile
					case 186:	// ECLSession::indSendFile
					{
						Show2E2C( pcsaLabels );
					}
					break;

					case 175:	// ECLSession::getPrinterMargin
					{
						pcsaListBox->Add( "MARGIN_TOP" );
						pcsaListBox->Add( "MARGIN_LEFT" );
						pcsaListBox->Add( "MARGIN_BOTTOM" );
						pcsaListBox->Add( "MARGIN_RIGHT" );

						Show1L( pcsaLabels, pcsaListBox );
					}
					break;

					case 207:	// ECLSession::setPrinterMargin
					{
						pcsaListBox->Add( "MARGIN_TOP" );
						pcsaListBox->Add( "MARGIN_LEFT" );
						pcsaListBox->Add( "MARGIN_BOTTOM" );
						pcsaListBox->Add( "MARGIN_RIGHT" );
						
						Show1L1E( pcsaLabels, pcsaListBox );
					}
					break;

					case 208:	// ECLSession::setPrinterPageSize
					{
						pcsaListBox->Add( "PRINTER_PAGE_WIDTH" );
						pcsaListBox->Add( "PRINTER_PAGE_HEIGHT" );
						
						Show1L1E( pcsaLabels, pcsaListBox );
					}
					break;

					case 209:	// ECLSession::setPrintScaling
					{
						pcsaListBox->Add( "PRINT_SCALING_HORIZONTAL" );
						pcsaListBox->Add( "PRINT_SCALING_VERTICAL" );
						
						Show1L1E( pcsaLabels, pcsaListBox );
					}
					break;

					case 234:	// ECLXfer::ReceiveFile
					case 236:	// ECLXfer::SendFile
					{
						pcsaListBox->Add( "ASCII" );
						pcsaListBox->Add( "JISCII" );
						pcsaListBox->Add( "CRLF" );
						pcsaListBox->Add( "SO" );
						pcsaListBox->Add( "NOSO" );
						pcsaListBox->Add( "USER" );

						Show2E1L( pcsaLabels, pcsaListBox );
					}
					break;
					
					case 239:	// ECLXfer::setTransferHostType
					{
						pcsaListBox->Add( "ID_HOST_TYPE_CICS" );
						pcsaListBox->Add( "ID_HOST_TYPE_CMS" );
						pcsaListBox->Add( "ID_HOST_TYPE_TSO" );
						pcsaListBox->Add( "DBCS_PLANE" );
						pcsaListBox->Add( "GRID_PLANE" );

						Show1L( pcsaLabels, pcsaListBox );
					}
					break;

			}


		}
		break;



		case EA0J_API:
		case MCSJ_API:					//TODO: Bring these API's up to level of others' UI 
		{
				switch ( uFunction )
				{
					case 6:		// OIA::waitForXStatus	
					{
						pcsaListBox->Add( "XSW_CLEAR" );
						pcsaListBox->Add( "XSW_HLLAPI" );
						pcsaListBox->Add( "XSW_NOTPRESENT" );
						pcsaListBox->Add( "XSW_PRESENT" );
						pcsaListBox->Add( "XSW_XANY" );

						pcsaListBox2->Add( "XS_BUSY" );
						pcsaListBox2->Add( "XS_CLEAR" );
						pcsaListBox2->Add( "XS_COMMCHECK" );
						pcsaListBox2->Add( "XS_INVALID_CHAR" );
						pcsaListBox2->Add( "XS_INVALID_FUNC" );
						pcsaListBox2->Add( "XS_INVALID_NUM" );
						pcsaListBox2->Add( "XS_MACHCHECK" );
						pcsaListBox2->Add( "XS_NUM_ONLY" );
						pcsaListBox2->Add( "XS_PAST_EOF" );
						pcsaListBox2->Add( "XS_PROGCHECK" );
						pcsaListBox2->Add( "XS_PROTECTED_FIELD" );
						pcsaListBox2->Add( "XS_PRTBUSTED" );
						pcsaListBox2->Add( "XS_PRTBUSY" );
						pcsaListBox2->Add( "XS_PRTVERYBUSY" );
						pcsaListBox2->Add( "XS_SYSTEM" );
						pcsaListBox2->Add( "XS_UNAUTHORIZED_PRINTER" );
						pcsaListBox2->Add( "XS_WHAT" );

						Show2L( pcsaLabels, pcsaListBox, pcsaListBox2  );
					}
					break;

					case 8:		// Screen::fieldCount
					{
						pcsaListBox->Add( "FIELDTYPE_PROTECTED" );
						pcsaListBox->Add( "FIELDTYPE_UNPROTECTED" );
						pcsaListBox->Add( "FIELDTYPE_ANY" );

						Show1L( pcsaLabels, pcsaListBox );
					}
					break;

					case 24:	// Screen::sendKeys
					{
						pcsaListBox->Add( "KEYTYPE_BRACES" );
						pcsaListBox->Add( "KEYTYPE_HLLAPI" );
						
						Show1E1L( pcsaLabels, pcsaListBox );
					}
					break;

					case 26:	// Screen::setEabEnabled
					case 43:	// Session::setConnected
					{
						Show1C( pcsaLabels );
					}
					break;

					case 29:	// Screen::setModel
					{
						pcsaListBox->Add( "MODEL_2" );
						pcsaListBox->Add( "MODEL_3" );
						pcsaListBox->Add( "MODEL_4" );
						pcsaListBox->Add( "MODEL_5" );
						pcsaListBox->Add( "MODEL_AUTOSENSE" );
						
						Show1L( pcsaLabels, pcsaListBox );
					}
					break;


					case 31:	// Screen::waitForKeys
					{
						pcsaListBox->Add( "ATM_KEYTYPE_BRACES" );
						pcsaListBox->Add( "ATM_KEYTYPE_HLLAPI" );
						pcsaListBox->Add( "ATM_KEYTYPE_IGNORE_INTERCEPT" );
						pcsaListBox->Add( "ATM_KEYTYPE_KEY_QUEUEABLE" );

						pcsaListBox2->Add( "WAITFORKEYS_INTERCEPT" );
						pcsaListBox2->Add( "WAITFORKEYS_NOTIFY" );
						pcsaListBox2->Add( "WAITFORKEYS_AID" );
						pcsaListBox2->Add( "WAITFORKEYS_NON_AID" );
						pcsaListBox2->Add( "WAITFORKEYS_ALL" );
						
						Show1E2L( pcsaLabels, pcsaListBox, pcsaListBox2  );
					}
					break;



				}

		}
		break;


		case EOLE_API:
		{
				switch ( uFunction )
				{
					case 3:		// Screen.OIA.Value
					{
						Show1C( pcsaLabels );
					}
					break;

				
					case 18:	// Screen::WaitForKeys
					{
						Show2E1C( pcsaLabels );
					}
					break;


					case 19:	// Screen.WaitForStream
					{
						pcsaListBox->Add( "xRegExp" );
						pcsaListBox->Add( "xNoCase" );

						Show3E1ML( pcsaLabels, pcsaListBox );
					}
					break;


					case 20:	// Screen::WaitForString
					{
						pcsaListBox->Add( "xRegExp" );
						pcsaListBox->Add( "xNoCase" );
						pcsaListBox->Add( "xStrip" );

						pcsaListBox2->Add( "1 - Select string" );
						pcsaListBox2->Add( "2 - Select block" );

						Show5E1ML1L2E( pcsaLabels, pcsaListBox, pcsaListBox2  );
					}
					break;

					case 26:	// Session::CloseEx
					{
						pcsaListBox->Add( "Disconnect w/o prompt" );
						pcsaListBox->Add( "Save while exiting" );
						pcsaListBox->Add( "Exit w/o saving" );
						pcsaListBox->Add( "Prompt for save" );

						Show1ML( pcsaLabels, pcsaListBox );
					}
					break;
		
					case 30:	// Session::FileTransferHostOS
					{
						pcsaListBox->Add( "CICS" );
						pcsaListBox->Add( "CMS" );
						pcsaListBox->Add( "TSO" );

						Show1C1L( pcsaLabels, pcsaListBox );
					}
					break;

					case 32:	// Session::FileTransferScheme
					{
						Show1E1B1C( pcsaLabels );
					}
					break;


					case 37:	// Session::InvokeSettingsDialog
				{
					pcsaListBox->Add( "xColorPage" );
					pcsaListBox->Add( "xFontPage" );
					pcsaListBox->Add( "xFileTransferPage" );
					pcsaListBox->Add( "xEditPage" );
					pcsaListBox->Add( "xHotSpotsPage" );
					pcsaListBox->Add( "xKeyboardMapPage" );
					pcsaListBox->Add( "xToolbarsPage" );
					pcsaListBox->Add( "xQuickPadsPage" );
					pcsaListBox->Add( "xConnectionPage" );
					pcsaListBox->Add( "xTerminalPage" );
					pcsaListBox->Add( "xPrinterPage" );
					pcsaListBox->Add( "xMacroPage" );
					pcsaListBox->Add( "xLanguagePage" );
					pcsaListBox->Add( "xMenuEditorPage" );
					pcsaListBox->Add( "xNavigationPage" );
					pcsaListBox->Add( "xGlobalPreferences" );
					pcsaListBox->Add( "xSessionType" );
					pcsaListBox->Add( "xPrintSetup" );

					pcsaListBox2->Add( "None" );
					pcsaListBox2->Add( "xGeneralTab" );
					pcsaListBox2->Add( "xProxiesTab" );
					pcsaListBox2->Add( "xFileHandlingTab" );
					pcsaListBox2->Add( "xFoldersTab" );
					pcsaListBox2->Add( "xFileTypesTab" );
					pcsaListBox2->Add( "xAssignmentsTab" );
					pcsaListBox2->Add( "xAdvancedTab" );
					pcsaListBox2->Add( "xSecurityTab" );
					pcsaListBox2->Add( "xDisplayTab" );
					pcsaListBox2->Add( "xColorTab" );
					pcsaListBox2->Add( "xKeyboardTab" );
					pcsaListBox2->Add( "xLocalEditTab" );
					pcsaListBox2->Add( "xHistoryTab" );
					pcsaListBox2->Add( "xPrinterTab" );
					pcsaListBox2->Add( "xGraphicsTab" );
					pcsaListBox2->Add( "xFileDirectories" );
					pcsaListBox2->Add( "xGlobalLanguageSetting" );

					Show2L( pcsaLabels, pcsaListBox, pcsaListBox2  );
				}
				break;


					case 39:	// Session::KeyMap
					{
						Show1C1E1B( pcsaLabels );
					}
					break;

					case 33:	// Session::Font
					case 34:	// Session::Height
					case 60:	// Session::Width
					case 70:	// System::TimeoutValue
					{
						Show1C1E( pcsaLabels );
					}
					break;

					case 40:	// Session::Language
				{
					pcsaListBox->Add("English");
					pcsaListBox->Add("Francais");
					pcsaListBox->Add("Deutsch");
					pcsaListBox->Add("Espanol");
					pcsaListBox->Add("Italiano");
					pcsaListBox->Add("Portugues");

					Show1C1L( pcsaLabels, pcsaListBox );
				}
				break;

				case 55:	// Session::Type
				{
					pcsaListBox->Add("xBLOCK");
					pcsaListBox->Add("xSTREAM");
					pcsaListBox->Add("xPOINT");
					pcsaListBox->Add("xNONE");
					pcsaListBox->Add("xCTTYPE_DEMO");
					pcsaListBox->Add("xCTTYPE_SERIAL");
					pcsaListBox->Add("xCTTYPE_MODEM");
					pcsaListBox->Add("xCTTYPE_TELNET");
					pcsaListBox->Add("x3270SESSION");
					pcsaListBox->Add("x5250SESSION");
					pcsaListBox->Add("xVTSESSION");

					Show1C1L( pcsaLabels, pcsaListBox );
				}
				break;


				case 59:	// Session::WaitForTimer
				{
					Show1E1C( pcsaLabels );
				}
				break;

				case 35:	// Session::HoldScreen
				case 38:	// Session::KeyboardLocked
				case 41:	// Session::Local
				case 42:	// Session::Menu
				case 45:	// Session::Quiet
				case 57:	// Session::Visible
				{
					Show2C( pcsaLabels );
				}
				break;


				case 46:	// Session::ReceiveFile
				case 52:	// Session::SendFile
				{
					Show1E1B1E1C( pcsaLabels );
				}
				break;


				case 50:	// Session::SaveAs
				case 63:	// Sessions::Open
				{
					Show1E1B( pcsaLabels );
				}
				break;


				case 58:	// Session::WaitForDisconnect
				{
					Show1E( pcsaLabels );
				}
				break;

				case 62:	// Session::WindowState
				{
					pcsaListBox->Add( "xMINIMIZED" );
					pcsaListBox->Add( "xNORMAL" );
					pcsaListBox->Add( "xMAXIMIZED" );

					Show1C1L( pcsaLabels, pcsaListBox );
				}
				break;

				default:
				{

				}

			}

		}
		break;


	
		case CICS20_JAVA_API:	
		{
				switch ( uFunction )
				{
					case 11:	// BridgeAPI::ConnectBridge
					case 63:	// BridgeAPI_EJB::connectBridge
					{
						pcsaListBox->Add( "Model 2" );
						pcsaListBox->Add( "Model 3" );
						pcsaListBox->Add( "Model 4" );
						pcsaListBox->Add( "Model 5" );

						Show2E1L2E( pcsaLabels, pcsaListBox );
					}
					break;

					case 12:	// BridgeAPI::ConnectBridge Ex2
					case 64:	// BridgeAPI_EJB::connectBridge Ex2
					{
						pcsaListBox->Add( "Model 2" );
						pcsaListBox->Add( "Model 3" );
						pcsaListBox->Add( "Model 4" );
						pcsaListBox->Add( "Model 5" );

						Show2E1L3E( pcsaLabels, pcsaListBox );
					}
					break;

					case 13:	// BridgeAPI::ConnectBridge Ex3
					case 65:	// BridgeAPI_EJB::connectBridge Ex3
					{
						pcsaListBox->Add( "Model 2" );
						pcsaListBox->Add( "Model 3" );
						pcsaListBox->Add( "Model 4" );
						pcsaListBox->Add( "Model 5" );

						Show2E1L4E( pcsaLabels, pcsaListBox );
					}
					break;

					case 14:	// BridgeAPI::ConnectBridge Ex4
					case 66:	// BridgeAPI_EJB::connectBridge Ex4
					{
						pcsaListBox->Add( "Model 2" );
						pcsaListBox->Add( "Model 3" );
						pcsaListBox->Add( "Model 4" );
						pcsaListBox->Add( "Model 5" );

						Show2E1L5E( pcsaLabels, pcsaListBox );
					}
					break;


				}
		}
		break;


		case CICS_COM_API:
		{
				switch ( uFunction )
				{
					case 1:	// ConnectBridge
					{
						pcsaListBox->Add( "Model 2" );
						pcsaListBox->Add( "Model 3" );
						pcsaListBox->Add( "Model 4" );
						pcsaListBox->Add( "Model 5" );

						Show2E1L5E( pcsaLabels, pcsaListBox );
					}
					break;
			
					case 3:	// FindString
					{
						pcsaListBox->Add( "Wrap search" );
						pcsaListBox->Add( "Backwards search" );
						pcsaListBox->Add( "One field search" );
						pcsaListBox->Add( "Ignore char case" );

						Show4E1ML( pcsaLabels, pcsaListBox );
					}
					break;


					case 16:	// Initialize
					{
						pcsaListBox->Add( "Model 2" );
						pcsaListBox->Add( "Model 3" );
						pcsaListBox->Add( "Model 4" );
						pcsaListBox->Add( "Model 5" );

						Show1L( pcsaLabels, pcsaListBox );
					}
					break;
			

				}
		}
		break;


		case CICS_NET_API:
		{
			switch ( uFunction )
			{
				case 1:	// ConnectBridge
				{
					pcsaListBox->Add( "Model 2" );
					pcsaListBox->Add( "Model 3" );
					pcsaListBox->Add( "Model 4" );
					pcsaListBox->Add( "Model 5" );

					Show2E1L5E( pcsaLabels, pcsaListBox );
				}
				break;
		
				case 3:	// FindString
				{
					pcsaListBox->Add( "Wrap search" );
					pcsaListBox->Add( "Backwards search" );
					pcsaListBox->Add( "One field search" );
					pcsaListBox->Add( "Ignore char case" );

					Show4E1L( pcsaLabels, pcsaListBox );
				}
				break;


				case 16:	// Initialize
				{
					pcsaListBox->Add( "Model 2" );
					pcsaListBox->Add( "Model 3" );
					pcsaListBox->Add( "Model 4" );
					pcsaListBox->Add( "Model 5" );

					Show1L( pcsaLabels, pcsaListBox );
				}
				break;
			}	
		}
		break;



		case RFTP_API:
		{
			switch ( uFunction )
			{
				case 2:		// Connect
				{
					Show2E1C( pcsaLabels );
				}
				break;

				case 11:	// Open
				{
					Show5E1C( pcsaLabels );
				}
				break;

				case 13:	// ReceiveDirectory
				case 17:	// SendDirectory
				{
					pcsaListBox->Add( "rcASCII" );
					pcsaListBox->Add( "rcBinary" );
					pcsaListBox->Add( "rcTenex" );
					pcsaListBox->Add( "rcSmart" );

					pcsaListBox2->Add( "rcAskAnswer" );
					pcsaListBox2->Add( "rcOverwrite" );
					pcsaListBox2->Add( "rcCancel" );

					if ( uFunction == 13 )
					{
						pcsaListBox2->Add( "rcAppend" );
						pcsaListBox2->Add( "rcUnique" );
					}

					pcsaListBox2->Add( "rcSkip" );

					Show2E2L( pcsaLabels, pcsaListBox, pcsaListBox2  );
				}
				break;

				case 14:	// ReceiveFile
				case 18:	// SendFile
				{
					pcsaListBox->Add( "rcASCII" );
					pcsaListBox->Add( "rcBinary" );
					pcsaListBox->Add( "rcTenex" );
					pcsaListBox->Add( "rcSmart" );

					pcsaListBox2->Add( "rcAskAnswer" );
					pcsaListBox2->Add( "rcOverwrite" );
					pcsaListBox2->Add( "rcCancel" );
					pcsaListBox2->Add( "rcAppend" );
					pcsaListBox2->Add( "rcUnique" );
					pcsaListBox2->Add( "rcSkip" );

					Show2E2L( pcsaLabels, pcsaListBox, pcsaListBox2  );
				}
				break;
			}
		}
		break;


	
		case AIRAx_API:
		case HLL_API:
		case ICONN_API:
		case EA0Ax_API:
		case MCSAx_API:
		case QACOM_API:
		{
		}
		break;


		case EHL_API:
		case IHL_API:
		case PCS_API:
		case WHL_API:
		{
			int nGroupBoxHeight = 0;

			nGroupBoxHeight	= 180;
			m_groupAddParameterGroup.ShowWindow( SW_SHOW  );
			m_groupAddParameterGroup.MoveWindow( PARAM_LEFT_SIDE-15, topGroupStart-25, STANDARD_WIDTH+30, nGroupBoxHeight );

			m_staticString1.SetWindowText( pcsaLabels->GetAt( 0 ) );
			m_staticString1.ShowWindow( SW_SHOW  );
			m_EditArgument1.MoveWindow( PARAM_LEFT_SIDE, PARAM_TOP, 145, 22 );
			m_EditArgument1.ShowWindow( SW_SHOW );
			m_EditArgument1.MoveWindow( PARAM_LEFT_SIDE, PARAM_TOP+PARAM_LABEL_HEIGHT, 145, 22 );

			m_staticString2.SetWindowText( pcsaLabels->GetAt( 1 ) );
			m_staticString2.ShowWindow( SW_SHOW  );
			m_staticString2.MoveWindow( PARAM_LEFT_SIDE, PARAM_TOP + PARAM_LINE_HEIGHT, 145, 22 );
			m_EditArgument2.ShowWindow( SW_SHOW );
			m_EditArgument2.MoveWindow( PARAM_LEFT_SIDE, 110, 145, 22 );

			m_staticString3.SetWindowText( pcsaLabels->GetAt( 2 ) );
			m_staticString3.ShowWindow( SW_SHOW  );
			m_staticString3.MoveWindow( PARAM_LEFT_SIDE, PARAM_TOP + (2*PARAM_LINE_HEIGHT), 145, 22 );
			m_EditArgument3.ShowWindow( SW_SHOW );
			m_EditArgument3.MoveWindow( PARAM_LEFT_SIDE, 159, 145, 22 );
		}
		break;


		default:
		{

		}

	}

	pcsaListBox->RemoveAll();

}


void CAPIGenDlg::ShowHLLControls( CStringArray* pcsaLabels )
{
	int nGroupBoxHeight	= 180;
	int topGroupStart=PARAM_TOP;

	m_groupAddParameterGroup.ShowWindow( SW_SHOW  );
	m_groupAddParameterGroup.MoveWindow( PARAM_LEFT_SIDE-15, topGroupStart-25, STANDARD_WIDTH+30, nGroupBoxHeight );

	m_staticString1.SetWindowText( pcsaLabels->GetAt( 0 ) );
	m_staticString1.ShowWindow( SW_SHOW );
	m_staticString1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
	m_EditArgument1.ShowWindow( SW_SHOW );
	m_EditArgument1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
	m_staticString2.SetWindowText( pcsaLabels->GetAt( 1 ) );
	m_staticString2.ShowWindow( SW_SHOW );
	m_staticString2.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
	m_EditArgument2.ShowWindow( SW_SHOW );
	m_EditArgument2.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
	m_staticString3.SetWindowText( pcsaLabels->GetAt( 2 ) );
	m_staticString3.ShowWindow( SW_SHOW );
	m_staticString3.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
	m_EditArgument3.ShowWindow( SW_SHOW );
	m_EditArgument3.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

}



/****************************************************************************DC
	Function	:	CAPIGenDlg::ShowEditControls()

	Purpose		:	Show the controls for the EHLLAPI function parameters.

*****************************************************************************/
void CAPIGenDlg::ShowEditControls( CStringArray* pcsaLabels )
{
	int topGroupStart=PARAM_TOP;
	UINT uEditboxCount = pcsaLabels->GetCount();

	int nGroupBoxHeight = 0;

	switch ( uEditboxCount )
	{
		case 0:	// no controls -- show the no-params group box
		{
			m_groupNoParametersNeeded.ShowWindow( SW_SHOW  );
		}
		break;

		case 1:	// one edit control
		{
			nGroupBoxHeight	= 100;
			m_groupAddParameterGroup.ShowWindow( SW_SHOW  );
			m_groupAddParameterGroup.MoveWindow( PARAM_LEFT_SIDE-15, topGroupStart-25, STANDARD_WIDTH+30, nGroupBoxHeight );

			m_staticString1.SetWindowText( pcsaLabels->GetAt( 0 ) );
			m_staticString1.ShowWindow( SW_SHOW );
			m_staticString1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 22 );
			m_EditArgument1.ShowWindow( SW_SHOW );
			m_EditArgument1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );
		}
		break;

		case 2:	// two edit controls
		{
			nGroupBoxHeight	= 140;
			m_groupAddParameterGroup.ShowWindow( SW_SHOW  );
			m_groupAddParameterGroup.MoveWindow( PARAM_LEFT_SIDE-15, topGroupStart-25, STANDARD_WIDTH+30, nGroupBoxHeight );

			m_staticString1.SetWindowText( pcsaLabels->GetAt( 0 ) );
			m_staticString1.ShowWindow( SW_SHOW );
			m_staticString1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 22 );
			m_EditArgument1.ShowWindow( SW_SHOW );
			m_EditArgument1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

			topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
			m_staticString2.SetWindowText( pcsaLabels->GetAt( 1 ) );
			m_staticString2.ShowWindow( SW_SHOW );
			m_staticString2.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 22 );
			m_EditArgument3.ShowWindow( SW_SHOW );
			m_EditArgument3.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );
		}
		break;

		case 3:	// three edit controls
		{
			nGroupBoxHeight	= 180;
			m_groupAddParameterGroup.ShowWindow( SW_SHOW  );
			m_groupAddParameterGroup.MoveWindow( PARAM_LEFT_SIDE-15, topGroupStart-25, STANDARD_WIDTH+30, nGroupBoxHeight );

			m_staticString1.SetWindowText( pcsaLabels->GetAt( 0 ) );
			m_staticString1.ShowWindow( SW_SHOW );
			m_staticString1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 22 );
			m_EditArgument1.ShowWindow( SW_SHOW );
			m_EditArgument1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

			topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
			m_staticString2.SetWindowText( pcsaLabels->GetAt( 1 ) );
			m_staticString2.ShowWindow( SW_SHOW );
			m_staticString2.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 22 );
			m_EditArgument3.ShowWindow( SW_SHOW );
			m_EditArgument3.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

			topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
			m_staticString3.SetWindowText( pcsaLabels->GetAt( 2 ) );
			m_staticString3.ShowWindow( SW_SHOW );
			m_staticString3.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 22 );
			m_EditArgument4.ShowWindow( SW_SHOW );
			m_EditArgument4.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

		}
		break;

		case 4:	// four edit controls
		{
			nGroupBoxHeight	= 220;
			m_groupAddParameterGroup.ShowWindow( SW_SHOW  );
			m_groupAddParameterGroup.MoveWindow( PARAM_LEFT_SIDE-15, topGroupStart-25, STANDARD_WIDTH+30, nGroupBoxHeight );

			m_staticString1.SetWindowText( pcsaLabels->GetAt( 0 ) );
			m_staticString1.ShowWindow( SW_SHOW );
			m_staticString1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 22 );
			m_EditArgument1.ShowWindow( SW_SHOW );
			m_EditArgument1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

			topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
			m_staticString2.SetWindowText( pcsaLabels->GetAt( 1 ) );
			m_staticString2.ShowWindow( SW_SHOW );
			m_staticString2.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 22 );
			m_EditArgument3.ShowWindow( SW_SHOW );
			m_EditArgument3.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

			topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
			m_staticString3.SetWindowText( pcsaLabels->GetAt( 2 ) );
			m_staticString3.ShowWindow( SW_SHOW );
			m_staticString3.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 22 );
			m_EditArgument4.ShowWindow( SW_SHOW );
			m_EditArgument4.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

			topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
			m_staticString4.SetWindowText( pcsaLabels->GetAt( 3 ) );
			m_staticString4.ShowWindow( SW_SHOW );
			m_staticString4.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
			m_EditArgument5.ShowWindow( SW_SHOW );
			m_EditArgument5.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );
		}
		break;

		case 5:	// five edit controls			
		{
			nGroupBoxHeight	= 260;
			m_groupAddParameterGroup.ShowWindow( SW_SHOW  );
			m_groupAddParameterGroup.MoveWindow( PARAM_LEFT_SIDE-15, topGroupStart-25, STANDARD_WIDTH+30, nGroupBoxHeight );

			m_staticString1.SetWindowText( pcsaLabels->GetAt( 0 ) );
			m_staticString1.ShowWindow( SW_SHOW );
			m_staticString1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 22 );
			m_EditArgument1.ShowWindow( SW_SHOW );
			m_EditArgument1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

			topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
			m_staticString2.SetWindowText( pcsaLabels->GetAt( 1 ) );
			m_staticString2.ShowWindow( SW_SHOW );
			m_staticString2.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 22 );
			m_EditArgument3.ShowWindow( SW_SHOW );
			m_EditArgument3.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

			topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
			m_staticString3.SetWindowText( pcsaLabels->GetAt( 2 ) );
			m_staticString3.ShowWindow( SW_SHOW );
			m_staticString3.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 22 );
			m_EditArgument4.ShowWindow( SW_SHOW );
			m_EditArgument4.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

			topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
			m_staticString4.SetWindowText( pcsaLabels->GetAt( 3 ) );
			m_staticString4.ShowWindow( SW_SHOW );
			m_staticString4.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
			m_EditArgument5.ShowWindow( SW_SHOW );
			m_EditArgument5.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

			topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
			m_staticString5.SetWindowText( pcsaLabels->GetAt( 4 ) );
			m_staticString5.ShowWindow( SW_SHOW );
			m_staticString5.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
			m_EditArgument6.ShowWindow( SW_SHOW );
			m_EditArgument6.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

		}
		break;

		case 6:	// six edit controls
		{
			nGroupBoxHeight	= 300;
			m_groupAddParameterGroup.ShowWindow( SW_SHOW  );
			m_groupAddParameterGroup.MoveWindow( PARAM_LEFT_SIDE-15, topGroupStart-25, STANDARD_WIDTH+30, nGroupBoxHeight );

			m_staticString1.SetWindowText( pcsaLabels->GetAt( 0 ) );
			m_staticString1.ShowWindow( SW_SHOW );
			m_staticString1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 22 );
			m_EditArgument1.ShowWindow( SW_SHOW );
			m_EditArgument1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

			topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
			m_staticString2.SetWindowText( pcsaLabels->GetAt( 1 ) );
			m_staticString2.ShowWindow( SW_SHOW );
			m_staticString2.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 22 );
			m_EditArgument3.ShowWindow( SW_SHOW );
			m_EditArgument3.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

			topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
			m_staticString3.SetWindowText( pcsaLabels->GetAt( 2 ) );
			m_staticString3.ShowWindow( SW_SHOW );
			m_staticString3.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 22 );
			m_EditArgument4.ShowWindow( SW_SHOW );
			m_EditArgument4.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

			topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
			m_staticString4.SetWindowText( pcsaLabels->GetAt( 3 ) );
			m_staticString4.ShowWindow( SW_SHOW );
			m_staticString4.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
			m_EditArgument5.ShowWindow( SW_SHOW );
			m_EditArgument5.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

			topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
			m_staticString5.SetWindowText( pcsaLabels->GetAt( 4 ) );
			m_staticString5.ShowWindow( SW_SHOW );
			m_staticString5.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
			m_EditArgument6.ShowWindow( SW_SHOW );
			m_EditArgument6.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

			topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
			m_staticString6.SetWindowText( pcsaLabels->GetAt( 5 ) );
			m_staticString6.ShowWindow( SW_SHOW );
			m_staticString6.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
			m_EditArgument7.ShowWindow( SW_SHOW );
			m_EditArgument7.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

		}
		break;


		case 7:	// seven edit controls
		{
			nGroupBoxHeight	= 340;
			m_groupAddParameterGroup.ShowWindow( SW_SHOW  );
			m_groupAddParameterGroup.MoveWindow( PARAM_LEFT_SIDE-15, topGroupStart-25, STANDARD_WIDTH+30, nGroupBoxHeight );

			m_staticString1.SetWindowText( pcsaLabels->GetAt( 0 ) );
			m_staticString1.ShowWindow( SW_SHOW );
			m_staticString1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 22 );
			m_EditArgument1.ShowWindow( SW_SHOW );
			m_EditArgument1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

			topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
			m_staticString2.SetWindowText( pcsaLabels->GetAt( 1 ) );
			m_staticString2.ShowWindow( SW_SHOW );
			m_staticString2.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 22 );
			m_EditArgument3.ShowWindow( SW_SHOW );
			m_EditArgument3.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

			topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
			m_staticString3.SetWindowText( pcsaLabels->GetAt( 2 ) );
			m_staticString3.ShowWindow( SW_SHOW );
			m_staticString3.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 22 );
			m_EditArgument4.ShowWindow( SW_SHOW );
			m_EditArgument4.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

			topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
			m_staticString4.SetWindowText( pcsaLabels->GetAt( 3 ) );
			m_staticString4.ShowWindow( SW_SHOW );
			m_staticString4.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
			m_EditArgument5.ShowWindow( SW_SHOW );
			m_EditArgument5.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

			topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
			m_staticString6.SetWindowText( pcsaLabels->GetAt( 4 ) );
			m_staticString6.ShowWindow( SW_SHOW );
			m_staticString6.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
			m_EditArgument7.ShowWindow( SW_SHOW );
			m_EditArgument7.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

			topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
			m_staticString7.SetWindowText( pcsaLabels->GetAt( 5 ) );
			m_staticString7.ShowWindow( SW_SHOW );
			m_staticString7.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
			m_EditArgument8.ShowWindow( SW_SHOW );
			m_EditArgument8.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

			topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
			m_staticString8.SetWindowText( pcsaLabels->GetAt( 6 ) );
			m_staticString8.ShowWindow( SW_SHOW );
			m_staticString8.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
			m_EditArgument9.ShowWindow( SW_SHOW );
			m_EditArgument9.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

		}
		break;

		case 8:	// eight edit controls
		{
			nGroupBoxHeight	= 380;
			m_groupAddParameterGroup.ShowWindow( SW_SHOW  );
			m_groupAddParameterGroup.MoveWindow( PARAM_LEFT_SIDE-15, topGroupStart-25, STANDARD_WIDTH+30, nGroupBoxHeight );

			m_staticString1.SetWindowText( pcsaLabels->GetAt( 0 ) );
			m_staticString1.ShowWindow( SW_SHOW );
			m_staticString1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 22 );
			m_EditArgument1.ShowWindow( SW_SHOW );
			m_EditArgument1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

			topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
			m_staticString2.SetWindowText( pcsaLabels->GetAt( 1 ) );
			m_staticString2.ShowWindow( SW_SHOW );
			m_staticString2.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 22 );
			m_EditArgument3.ShowWindow( SW_SHOW );
			m_EditArgument3.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

			topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
			m_staticString3.SetWindowText( pcsaLabels->GetAt( 2 ) );
			m_staticString3.ShowWindow( SW_SHOW );
			m_staticString3.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 22 );
			m_EditArgument4.ShowWindow( SW_SHOW );
			m_EditArgument4.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

			topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
			m_staticString4.SetWindowText( pcsaLabels->GetAt( 3 ) );
			m_staticString4.ShowWindow( SW_SHOW );
			m_staticString4.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
			m_EditArgument5.ShowWindow( SW_SHOW );
			m_EditArgument5.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

			topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
			m_staticString5.SetWindowText( pcsaLabels->GetAt( 4 ) );
			m_staticString5.ShowWindow( SW_SHOW );
			m_staticString5.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
			m_EditArgument6.ShowWindow( SW_SHOW );
			m_EditArgument6.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

			topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
			m_staticString6.SetWindowText( pcsaLabels->GetAt( 5 ) );
			m_staticString6.ShowWindow( SW_SHOW );
			m_staticString6.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
			m_EditArgument7.ShowWindow( SW_SHOW );
			m_EditArgument7.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

			topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
			m_staticString7.SetWindowText( pcsaLabels->GetAt( 6 ) );
			m_staticString7.ShowWindow( SW_SHOW );
			m_staticString7.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
			m_EditArgument8.ShowWindow( SW_SHOW );
			m_EditArgument8.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

			topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
			m_staticString8.SetWindowText( pcsaLabels->GetAt( 7 ) );
			m_staticString8.ShowWindow( SW_SHOW );
			m_staticString8.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
			m_EditArgument9.ShowWindow( SW_SHOW );
			m_EditArgument9.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

		}
		break;

		case 9:	// nine edit controls
		{
			nGroupBoxHeight	= 420;

			m_groupAddParameterGroup.ShowWindow( SW_SHOW  );
			m_groupAddParameterGroup.MoveWindow( PARAM_LEFT_SIDE-15, topGroupStart-25, STANDARD_WIDTH+30, nGroupBoxHeight );

			m_staticString1.SetWindowText( pcsaLabels->GetAt( 0 ) );
			m_staticString1.ShowWindow( SW_SHOW );
			m_staticString1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 22 );
			m_EditArgument1.ShowWindow( SW_SHOW );
			m_EditArgument1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

			topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
			m_staticString2.SetWindowText( pcsaLabels->GetAt( 1 ) );
			m_staticString2.ShowWindow( SW_SHOW );
			m_staticString2.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 22 );
			m_EditArgument3.ShowWindow( SW_SHOW );
			m_EditArgument3.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

			topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
			m_staticString3.SetWindowText( pcsaLabels->GetAt( 2 ) );
			m_staticString3.ShowWindow( SW_SHOW );
			m_staticString3.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 22 );
			m_EditArgument4.ShowWindow( SW_SHOW );
			m_EditArgument4.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

			topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
			m_staticString4.SetWindowText( pcsaLabels->GetAt( 3 ) );
			m_staticString4.ShowWindow( SW_SHOW );
			m_staticString4.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
			m_EditArgument5.ShowWindow( SW_SHOW );
			m_EditArgument5.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

			topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
			m_staticString6.SetWindowText( pcsaLabels->GetAt( 4 ) );
			m_staticString6.ShowWindow( SW_SHOW );
			m_staticString6.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
			m_EditArgument7.ShowWindow( SW_SHOW );
			m_EditArgument7.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

			topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
			m_staticString7.SetWindowText( pcsaLabels->GetAt( 5 ) );
			m_staticString7.ShowWindow( SW_SHOW );
			m_staticString7.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
			m_EditArgument8.ShowWindow( SW_SHOW );
			m_EditArgument8.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

			topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
			m_staticString8.SetWindowText( pcsaLabels->GetAt( 6 ) );
			m_staticString8.ShowWindow( SW_SHOW );
			m_staticString8.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
			m_EditArgument9.ShowWindow( SW_SHOW );
			m_EditArgument9.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

			topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
			m_staticString9.SetWindowText( pcsaLabels->GetAt( 7 ) );
			m_staticString9.ShowWindow( SW_SHOW );
			m_staticString9.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
			m_EditArgument10.ShowWindow( SW_SHOW );
			m_EditArgument10.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

			topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
			m_staticString10.SetWindowText( pcsaLabels->GetAt( 8 ) );
			m_staticString10.ShowWindow( SW_SHOW );
			m_staticString10.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
			m_EditArgument11.ShowWindow( SW_SHOW );
			m_EditArgument11.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

		}
		break;

		case 10:	// ten edit controls
		{
			nGroupBoxHeight	= 460;

			m_groupAddParameterGroup.ShowWindow( SW_SHOW  );
			m_groupAddParameterGroup.MoveWindow( PARAM_LEFT_SIDE-15, topGroupStart-25, STANDARD_WIDTH+30, nGroupBoxHeight );

			m_staticString1.SetWindowText( pcsaLabels->GetAt( 0 ) );
			m_staticString1.ShowWindow( SW_SHOW );
			m_staticString1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 22 );
			m_EditArgument1.ShowWindow( SW_SHOW );
			m_EditArgument1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

			topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
			m_staticString2.SetWindowText( pcsaLabels->GetAt( 1 ) );
			m_staticString2.ShowWindow( SW_SHOW );
			m_staticString2.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 22 );
			m_EditArgument3.ShowWindow( SW_SHOW );
			m_EditArgument3.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

			topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
			m_staticString3.SetWindowText( pcsaLabels->GetAt( 2 ) );
			m_staticString3.ShowWindow( SW_SHOW );
			m_staticString3.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 22 );
			m_EditArgument4.ShowWindow( SW_SHOW );
			m_EditArgument4.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

			topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
			m_staticString4.SetWindowText( pcsaLabels->GetAt( 3 ) );
			m_staticString4.ShowWindow( SW_SHOW );
			m_staticString4.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
			m_EditArgument5.ShowWindow( SW_SHOW );
			m_EditArgument5.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

			topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
			m_staticString6.SetWindowText( pcsaLabels->GetAt( 4 ) );
			m_staticString6.ShowWindow( SW_SHOW );
			m_staticString6.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
			m_EditArgument7.ShowWindow( SW_SHOW );
			m_EditArgument7.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

			topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
			m_staticString7.SetWindowText( pcsaLabels->GetAt( 5 ) );
			m_staticString7.ShowWindow( SW_SHOW );
			m_staticString7.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
			m_EditArgument8.ShowWindow( SW_SHOW );
			m_EditArgument8.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

			topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
			m_staticString8.SetWindowText( pcsaLabels->GetAt( 6 ) );
			m_staticString8.ShowWindow( SW_SHOW );
			m_staticString8.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
			m_EditArgument9.ShowWindow( SW_SHOW );
			m_EditArgument9.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

			topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
			m_staticString9.SetWindowText( pcsaLabels->GetAt( 7 ) );
			m_staticString9.ShowWindow( SW_SHOW );
			m_staticString9.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
			m_EditArgument10.ShowWindow( SW_SHOW );
			m_EditArgument10.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

			topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
			m_staticString10.SetWindowText( pcsaLabels->GetAt( 8 ) );
			m_staticString10.ShowWindow( SW_SHOW );
			m_staticString10.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
			m_EditArgument11.ShowWindow( SW_SHOW );
			m_EditArgument11.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

			topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
			m_staticString11.SetWindowText( pcsaLabels->GetAt( 9 ) );
			m_staticString11.ShowWindow( SW_SHOW );
			m_staticString11.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
			m_EditArgument12.ShowWindow( SW_SHOW );
			m_EditArgument12.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

		}
		break;

		case 11:	// eleven edit controls
		{
			nGroupBoxHeight	= 500;
			m_groupAddParameterGroup.ShowWindow( SW_SHOW  );
			m_groupAddParameterGroup.MoveWindow( PARAM_LEFT_SIDE-15, topGroupStart-25, STANDARD_WIDTH+30, nGroupBoxHeight );

			m_staticString1.SetWindowText( pcsaLabels->GetAt( 0 ) );
			m_staticString1.ShowWindow( SW_SHOW );
			m_staticString1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 22 );
			m_EditArgument1.ShowWindow( SW_SHOW );
			m_EditArgument1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

			topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
			m_staticString2.SetWindowText( pcsaLabels->GetAt( 1 ) );
			m_staticString2.ShowWindow( SW_SHOW );
			m_staticString2.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 22 );
			m_EditArgument3.ShowWindow( SW_SHOW );
			m_EditArgument3.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

			topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
			m_staticString3.SetWindowText( pcsaLabels->GetAt( 2 ) );
			m_staticString3.ShowWindow( SW_SHOW );
			m_staticString3.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 22 );
			m_EditArgument4.ShowWindow( SW_SHOW );
			m_EditArgument4.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

			topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
			m_staticString4.SetWindowText( pcsaLabels->GetAt( 3 ) );
			m_staticString4.ShowWindow( SW_SHOW );
			m_staticString4.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
			m_EditArgument5.ShowWindow( SW_SHOW );
			m_EditArgument5.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

			topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
			m_staticString5.SetWindowText( pcsaLabels->GetAt( 4 ) );
			m_staticString5.ShowWindow( SW_SHOW );
			m_staticString5.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
			m_EditArgument6.ShowWindow( SW_SHOW );
			m_EditArgument6.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

			topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
			m_staticString6.SetWindowText( pcsaLabels->GetAt( 5 ) );
			m_staticString6.ShowWindow( SW_SHOW );
			m_staticString6.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
			m_EditArgument7.ShowWindow( SW_SHOW );
			m_EditArgument7.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

			topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
			m_staticString7.SetWindowText( pcsaLabels->GetAt( 6 ) );
			m_staticString7.ShowWindow( SW_SHOW );
			m_staticString7.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
			m_EditArgument8.ShowWindow( SW_SHOW );
			m_EditArgument8.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

			topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
			m_staticString8.SetWindowText( pcsaLabels->GetAt( 7 ) );
			m_staticString8.ShowWindow( SW_SHOW );
			m_staticString8.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
			m_EditArgument9.ShowWindow( SW_SHOW );
			m_EditArgument9.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

			topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
			m_staticString9.SetWindowText( pcsaLabels->GetAt( 8 ) );
			m_staticString9.ShowWindow( SW_SHOW );
			m_staticString9.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
			m_EditArgument10.ShowWindow( SW_SHOW );
			m_EditArgument10.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

			topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
			m_staticString10.SetWindowText( pcsaLabels->GetAt( 9 ) );
			m_staticString10.ShowWindow( SW_SHOW );
			m_staticString10.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
			m_EditArgument11.ShowWindow( SW_SHOW );
			m_EditArgument11.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

			topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
			m_staticString11.SetWindowText( pcsaLabels->GetAt( 10 ) );
			m_staticString11.ShowWindow( SW_SHOW );
			m_staticString11.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
			m_EditArgument12.ShowWindow( SW_SHOW );
			m_EditArgument12.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

		}
		break;

		case 12:	// twelve edit controls
		{
			nGroupBoxHeight	= 500;
			m_groupAddParameterGroup.ShowWindow( SW_SHOW  );
			m_groupAddParameterGroup.MoveWindow( PARAM_LEFT_SIDE-15, topGroupStart-25, STANDARD_WIDTH+30, nGroupBoxHeight );

			m_staticString1.SetWindowText( pcsaLabels->GetAt( 0 ) );
			m_staticString1.ShowWindow( SW_SHOW );
			m_staticString1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 22 );
			m_EditArgument1.ShowWindow( SW_SHOW );
			m_EditArgument1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

			topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
			m_staticString2.SetWindowText( pcsaLabels->GetAt( 1 ) );
			m_staticString2.ShowWindow( SW_SHOW );
			m_staticString2.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 22 );
			m_EditArgument3.ShowWindow( SW_SHOW );
			m_EditArgument3.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

			topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
			m_staticString3.SetWindowText( pcsaLabels->GetAt( 2 ) );
			m_staticString3.ShowWindow( SW_SHOW );
			m_staticString3.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 22 );
			m_EditArgument4.ShowWindow( SW_SHOW );
			m_EditArgument4.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

			topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
			m_staticString4.SetWindowText( pcsaLabels->GetAt( 3 ) );
			m_staticString4.ShowWindow( SW_SHOW );
			m_staticString4.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
			m_EditArgument5.ShowWindow( SW_SHOW );
			m_EditArgument5.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

			topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
			m_staticString5.SetWindowText( pcsaLabels->GetAt( 4 ) );
			m_staticString5.ShowWindow( SW_SHOW );
			m_staticString5.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
			m_EditArgument6.ShowWindow( SW_SHOW );
			m_EditArgument6.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

			topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
			m_staticString6.SetWindowText( pcsaLabels->GetAt( 5 ) );
			m_staticString6.ShowWindow( SW_SHOW );
			m_staticString6.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
			m_EditArgument7.ShowWindow( SW_SHOW );
			m_EditArgument7.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

			topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
			m_staticString7.SetWindowText( pcsaLabels->GetAt( 6 ) );
			m_staticString7.ShowWindow( SW_SHOW );
			m_staticString7.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
			m_EditArgument8.ShowWindow( SW_SHOW );
			m_EditArgument8.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

			topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
			m_staticString8.SetWindowText( pcsaLabels->GetAt( 7 ) );
			m_staticString8.ShowWindow( SW_SHOW );
			m_staticString8.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
			m_EditArgument9.ShowWindow( SW_SHOW );
			m_EditArgument9.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

			topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
			m_staticString9.SetWindowText( pcsaLabels->GetAt( 8 ) );
			m_staticString9.ShowWindow( SW_SHOW );
			m_staticString9.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
			m_EditArgument10.ShowWindow( SW_SHOW );
			m_EditArgument10.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

			topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
			m_staticString10.SetWindowText( pcsaLabels->GetAt( 9 ) );
			m_staticString10.ShowWindow( SW_SHOW );
			m_staticString10.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
			m_EditArgument11.ShowWindow( SW_SHOW );
			m_EditArgument11.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

			topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
			m_staticString11.SetWindowText( pcsaLabels->GetAt( 10 ) );
			m_staticString11.ShowWindow( SW_SHOW );
			m_staticString11.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
			m_EditArgument12.ShowWindow( SW_SHOW );
			m_EditArgument12.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

			topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
			m_staticString12.SetWindowText( pcsaLabels->GetAt( 11 ) );
			m_staticString12.ShowWindow( SW_SHOW );
			m_staticString12.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
			m_EditArgument13.ShowWindow( SW_SHOW );
			m_EditArgument13.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

			topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
			m_staticString13.SetWindowText( pcsaLabels->GetAt( 12 ) );
			m_staticString13.ShowWindow( SW_SHOW );
			m_staticString13.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
			m_EditArgument14.ShowWindow( SW_SHOW );
			m_EditArgument14.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

		}
		break;



	}
}



/***************************************************************************DC

	Operation:	CAPIGenDlg::Show1E() 

	Purpose:	Sets up one edit control and one list control.

	Arguments:	csaLabels -- the strings that are used to label each control.

	Note:		

*****************************************************************************/
void CAPIGenDlg::Show1E( CStringArray* pcsaLabels )
{
	int topGroupStart=PARAM_TOP;
	int nGroupBoxHeight = 0;

	nGroupBoxHeight	= 85;
	m_groupAddParameterGroup.ShowWindow( SW_SHOW  );
	m_groupAddParameterGroup.MoveWindow( PARAM_LEFT_SIDE-15, topGroupStart-25, STANDARD_WIDTH+30, nGroupBoxHeight );

	m_staticString1.SetWindowText( pcsaLabels->GetAt( 0 ) );
	m_staticString1.ShowWindow( SW_SHOW );
	m_staticString1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 22 );
	m_EditArgument1.ShowWindow( SW_SHOW );
	m_EditArgument1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );
}



/***************************************************************************DC

	Operation:	CAPIGenDlg::Show1E1L() 

	Purpose:	Sets up one edit control and one list control.

	Arguments:	csaLabels -- the strings that are used to label each control.

	Note:		

*****************************************************************************/
void CAPIGenDlg::Show1E1L( CStringArray* pcsaLabels, CStringArray* csaListEntries  )
{
	int topGroupStart=PARAM_TOP;
	int nGroupBoxHeight = 0;

	nGroupBoxHeight	= 140;
	m_groupAddParameterGroup.ShowWindow( SW_SHOW  );
	m_groupAddParameterGroup.MoveWindow( PARAM_LEFT_SIDE-15, topGroupStart-25, STANDARD_WIDTH+30, nGroupBoxHeight );

	m_staticString1.SetWindowText( pcsaLabels->GetAt( 0 ) );
	m_staticString1.ShowWindow( SW_SHOW );
	m_staticString1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 22 );
	m_EditArgument1.ShowWindow( SW_SHOW );
	m_EditArgument1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
	m_staticString2.SetWindowText( pcsaLabels->GetAt( 1 ) );
	m_staticString2.ShowWindow( SW_SHOW );
	m_staticString2.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 22 );

	listParams1.ShowWindow( SW_SHOW  );
	listParams1.ResetContent();
	for ( int i=0; i<csaListEntries->GetCount(); i++)
	{
		listParams1.AddString( csaListEntries->GetAt(i) );
	}

	listParams1.SetCurSel(0);
	listParams1.ShowWindow( SW_SHOW  );
	listParams1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 40 );

}



/***************************************************************************DC

	Operation:	CAPIGenDlg::Show1E1L1E() 

	Purpose:	Sets up one edit control + one listbox + one edit control.

	Arguments:	csaLabels -- the strings that are used to label each control.

	Note:		

*****************************************************************************/
void CAPIGenDlg::Show1E1L1E( CStringArray* pcsaLabels, CStringArray* csaListEntries  )
{
	int topGroupStart=PARAM_TOP;
	int nGroupBoxHeight = 0;
	nGroupBoxHeight	= 195;

	m_groupAddParameterGroup.ShowWindow( SW_SHOW  );
	m_groupAddParameterGroup.MoveWindow( PARAM_LEFT_SIDE-15, topGroupStart-25, STANDARD_WIDTH+30, nGroupBoxHeight );

	m_staticString1.SetWindowText( pcsaLabels->GetAt( 0 ) );
	m_staticString1.ShowWindow( SW_SHOW );
	m_staticString1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
	m_EditArgument1.ShowWindow( SW_SHOW );
	m_EditArgument1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
	m_staticString2.SetWindowText( pcsaLabels->GetAt( 1 ) );
	m_staticString2.ShowWindow( SW_SHOW );
	m_staticString2.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );

	listParams1.ShowWindow( SW_SHOW  );
	listParams1.ResetContent();
	for ( int i=0; i<csaListEntries->GetCount(); i++)
	{
		listParams1.AddString( csaListEntries->GetAt(i) );
	}

	listParams1.SetCurSel(0);
	listParams1.ShowWindow( SW_SHOW  );
	listParams1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 40 );


	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP + 20;
	m_staticString3.SetWindowText( pcsaLabels->GetAt( 2 ) );
	m_staticString3.ShowWindow( SW_SHOW );
	m_staticString3.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
	m_EditArgument3.ShowWindow( SW_SHOW );
	m_EditArgument3.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );


}



/***************************************************************************DC

	Operation:	CAPIGenDlg::Show1E1L2E() 

	Purpose:	Sets up one edit control + one listbox + two edit controls.

	Arguments:	csaLabels -- the strings that are used to label each control.

	Note:		

*****************************************************************************/
void CAPIGenDlg::Show1E1L2E( CStringArray* pcsaLabels, CStringArray* csaListEntries  )
{
	int topGroupStart=PARAM_TOP;
	int nGroupBoxHeight = 0;
	nGroupBoxHeight	= 235;

	m_groupAddParameterGroup.ShowWindow( SW_SHOW  );
	m_groupAddParameterGroup.MoveWindow( PARAM_LEFT_SIDE-15, topGroupStart-25, STANDARD_WIDTH+30, nGroupBoxHeight );

	m_staticString1.SetWindowText( pcsaLabels->GetAt( 0 ) );
	m_staticString1.ShowWindow( SW_SHOW );
	m_staticString1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
	m_EditArgument1.ShowWindow( SW_SHOW );
	m_EditArgument1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP+5;
	m_staticString2.SetWindowText( pcsaLabels->GetAt( 1 ) );
	m_staticString2.ShowWindow( SW_SHOW );
	m_staticString2.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );

	listParams1.ShowWindow( SW_SHOW  );
	listParams1.ResetContent();
	for ( int i=0; i<csaListEntries->GetCount(); i++)
	{
		listParams1.AddString( csaListEntries->GetAt(i) );
	}

	listParams1.SetCurSel(0);
	listParams1.ShowWindow( SW_SHOW  );
	listParams1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 40 );


	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP + 20;
	m_staticString3.SetWindowText( pcsaLabels->GetAt( 2 ) );
	m_staticString3.ShowWindow( SW_SHOW );
	m_staticString3.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
	m_EditArgument3.ShowWindow( SW_SHOW );
	m_EditArgument3.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
	m_staticString4.SetWindowText( pcsaLabels->GetAt( 3 ) );
	m_staticString4.ShowWindow( SW_SHOW );
	m_staticString4.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
	m_EditArgument4.ShowWindow( SW_SHOW );
	m_EditArgument4.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );


}



/***************************************************************************DC

	Operation:	CAPIGenDlg::Show1E1L1C() 

	Purpose:	Sets up one edit control + one list control + one checkbox.

	Arguments:	csaLabels -- the strings that are used to label each control.

	Note:		

*****************************************************************************/
void CAPIGenDlg::Show1E1L1C( CStringArray* pcsaLabels, CStringArray* csaListEntries  )
{
	int topGroupStart=PARAM_TOP;
	int nGroupBoxHeight	= 160;
	m_groupAddParameterGroup.ShowWindow( SW_SHOW  );
	m_groupAddParameterGroup.MoveWindow( PARAM_LEFT_SIDE-15, topGroupStart-25, STANDARD_WIDTH+30, nGroupBoxHeight );

	m_staticString1.SetWindowText( pcsaLabels->GetAt( 0 ) );
	m_staticString1.ShowWindow( SW_SHOW );
	m_staticString1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 22 );
	m_EditArgument1.ShowWindow( SW_SHOW );
	m_EditArgument1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
	m_staticString2.SetWindowText( pcsaLabels->GetAt( 1 ) );
	m_staticString2.ShowWindow( SW_SHOW );
	m_staticString2.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 22 );

	listParams1.ShowWindow( SW_SHOW  );
	listParams1.ResetContent();
	for ( int i=0; i<csaListEntries->GetCount(); i++)
	{
		listParams1.AddString( csaListEntries->GetAt(i) );
	}

	listParams1.SetCurSel(0);
	listParams1.ShowWindow( SW_SHOW  );
	listParams1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 40 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP + 15;
	checkParam1.SetWindowText( pcsaLabels->GetAt( 2 ) );
	checkParam1.ShowWindow( SW_SHOW );
	checkParam1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 22 );

}




/***************************************************************************DC

	Operation:	CAPIGenDlg::Show1L1E() 

	Purpose:	Sets up one listbox + one edit control.

	Arguments:	csaLabels -- the strings that are used to label each control.

	Note:		

*****************************************************************************/
void CAPIGenDlg::Show1L1E( CStringArray* pcsaLabels, CStringArray* csaListEntries  )
{
	int topGroupStart=PARAM_TOP;
	int nGroupBoxHeight = 0;
	nGroupBoxHeight	= 140;

	m_groupAddParameterGroup.ShowWindow( SW_SHOW  );
	m_groupAddParameterGroup.MoveWindow( PARAM_LEFT_SIDE-15, topGroupStart-25, STANDARD_WIDTH+30, nGroupBoxHeight );

	m_staticString1.SetWindowText( pcsaLabels->GetAt( 0 ) );
	m_staticString1.ShowWindow( SW_SHOW );
	m_staticString1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 22 );

	listParams1.ShowWindow( SW_SHOW  );
	listParams1.ResetContent();
	for ( int i=0; i<csaListEntries->GetCount(); i++)
	{
		listParams1.AddString( csaListEntries->GetAt(i) );
	}

	listParams1.SetCurSel(0);
	listParams1.ShowWindow( SW_SHOW  );
	listParams1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 40 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP + 20;
	m_staticString2.SetWindowText( pcsaLabels->GetAt( 1 ) );
	m_staticString2.ShowWindow( SW_SHOW );
	m_staticString2.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 22 );
	m_EditArgument1.ShowWindow( SW_SHOW );
	m_EditArgument1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );


}



/***************************************************************************DC

	Operation:	CAPIGenDlg::Show1L1EB1E() 

	Purpose:	Sets up one listbox + one edit/button control + one edit 
				control.

	Arguments:	csaLabels -- the strings that are used to label each control.

	Note:		

*****************************************************************************/
void CAPIGenDlg::Show1L1EB1E( CStringArray* pcsaLabels, CStringArray* csaListEntries  )
{
	int topGroupStart=PARAM_TOP;
	int nGroupBoxHeight = 0;
	nGroupBoxHeight	= 235;

	m_groupAddParameterGroup.ShowWindow( SW_SHOW  );
	m_groupAddParameterGroup.MoveWindow( PARAM_LEFT_SIDE-15, topGroupStart-25, STANDARD_WIDTH+30, nGroupBoxHeight );

	m_staticString1.SetWindowText( pcsaLabels->GetAt( 0 ) );
	m_staticString1.ShowWindow( SW_SHOW );
	m_staticString1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );

	listParams1.ShowWindow( SW_SHOW  );
	listParams1.ResetContent();
	for ( int i=0; i<csaListEntries->GetCount(); i++)
	{
		listParams1.AddString( csaListEntries->GetAt(i) );
	}

	listParams1.SetCurSel(0);
	listParams1.ShowWindow( SW_SHOW  );
	listParams1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 40 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP + 20;
	m_staticString2.SetWindowText( pcsaLabels->GetAt( 1 ) );
	m_staticString2.ShowWindow( SW_SHOW );
	m_staticString2.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
	m_EditArgument1.ShowWindow( SW_SHOW );
	m_EditArgument1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
	m_buttonBrowseFileTransfer.ShowWindow( SW_SHOW  );
	m_buttonBrowseFileTransfer.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, 145, 22 );

	m_buttonBrowseFileTransfer.ShowWindow( SW_SHOW  );


	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP-5;
	m_staticString3.SetWindowText( pcsaLabels->GetAt( 2 ) );
	m_staticString3.ShowWindow( SW_SHOW );
	m_staticString3.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
	m_EditArgument3.ShowWindow( SW_SHOW );
	m_EditArgument3.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

}



/***************************************************************************DC

	Operation:	CAPIGenDlg::Show1L2E() 

	Purpose:	Sets up one edit control and one list control.

	Arguments:	csaLabels -- the strings that are used to label each control.

	Note:		

*****************************************************************************/
void CAPIGenDlg::Show1L2E( CStringArray* pcsaLabels, CStringArray* csaListEntries  )
{
	int topGroupStart=PARAM_TOP;
	int nGroupBoxHeight = 0;
	nGroupBoxHeight	= 185;

	m_groupAddParameterGroup.ShowWindow( SW_SHOW  );
	m_groupAddParameterGroup.MoveWindow( PARAM_LEFT_SIDE-15, topGroupStart-25, STANDARD_WIDTH+30, nGroupBoxHeight );

	m_staticString1.SetWindowText( pcsaLabels->GetAt( 0 ) );
	m_staticString1.ShowWindow( SW_SHOW );
	m_staticString1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 22 );

	listParams1.ShowWindow( SW_SHOW  );
	listParams1.ResetContent();
	for ( int i=0; i<csaListEntries->GetCount(); i++)
	{
		listParams1.AddString( csaListEntries->GetAt(i) );
	}

	listParams1.SetCurSel(0);
	listParams1.ShowWindow( SW_SHOW  );
	listParams1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 40 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP + 20;
	m_staticString2.SetWindowText( pcsaLabels->GetAt( 1 ) );
	m_staticString2.ShowWindow( SW_SHOW );
	m_staticString2.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 22 );
	m_EditArgument1.ShowWindow( SW_SHOW );
	m_EditArgument1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
	m_staticString3.SetWindowText( pcsaLabels->GetAt( 2 ) );
	m_staticString3.ShowWindow( SW_SHOW );
	m_staticString3.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 22 );
	m_EditArgument3.ShowWindow( SW_SHOW );
	m_EditArgument3.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );


}



/***************************************************************************DC

	Operation:	CAPIGenDlg::Show1ML() 

	Purpose:	Sets up one multiple selection list control

	Arguments:	csaLabels -- the strings that are used to label each control.

	Note:		

*****************************************************************************/
void CAPIGenDlg::Show1ML( CStringArray* pcsaLabels, CStringArray* csaListEntries  )
{
	int topGroupStart=PARAM_TOP;
	int nGroupBoxHeight = 0;
	nGroupBoxHeight	= 185;

	m_groupAddParameterGroup.ShowWindow( SW_SHOW  );
	m_groupAddParameterGroup.MoveWindow( PARAM_LEFT_SIDE-15, topGroupStart-25, STANDARD_WIDTH+30, nGroupBoxHeight );

	m_staticString1.SetWindowText( pcsaLabels->GetAt( 0 ) );
	m_staticString1.ShowWindow( SW_SHOW );
	m_staticString1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 22 );

	listMultiParams1.ShowWindow( SW_SHOW  );
	listMultiParams1.ResetContent();
	for ( int i=0; i<csaListEntries->GetCount(); i++)
	{
		listMultiParams1.AddString( csaListEntries->GetAt(i) );
	}

	listMultiParams1.SetSel(0,TRUE);
	listMultiParams1.ShowWindow( SW_SHOW  );
	listMultiParams1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 140 );

}




/***************************************************************************DC

	Operation:	CAPIGenDlg::Show1ML2E() 

	Purpose:	Sets up one multiple selection list control + two edit controls.

	Arguments:	csaLabels -- the strings that are used to label each control.

	Note:		

*****************************************************************************/
void CAPIGenDlg::Show1ML2E( CStringArray* pcsaLabels, CStringArray* csaListEntries  )
{
	int topGroupStart=PARAM_TOP;
	int nGroupBoxHeight = 0;
	nGroupBoxHeight	= 285;

	m_groupAddParameterGroup.ShowWindow( SW_SHOW  );
	m_groupAddParameterGroup.MoveWindow( PARAM_LEFT_SIDE-15, topGroupStart-25, STANDARD_WIDTH+30, nGroupBoxHeight );

	m_staticString1.SetWindowText( pcsaLabels->GetAt( 0 ) );
	m_staticString1.ShowWindow( SW_SHOW );
	m_staticString1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 22 );

	listMultiParams1.ShowWindow( SW_SHOW  );
	listMultiParams1.ResetContent();
	for ( int i=0; i<csaListEntries->GetCount(); i++)
	{
		listMultiParams1.AddString( csaListEntries->GetAt(i) );
	}

	listMultiParams1.SetSel(0,TRUE);
	listMultiParams1.ShowWindow( SW_SHOW  );
	listMultiParams1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 140 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP + 120;
	m_staticString2.SetWindowText( pcsaLabels->GetAt( 1 ) );
	m_staticString2.ShowWindow( SW_SHOW );
	m_staticString2.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 22 );
	m_EditArgument1.ShowWindow( SW_SHOW );
	m_EditArgument1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
	m_staticString3.SetWindowText( pcsaLabels->GetAt( 2 ) );
	m_staticString3.ShowWindow( SW_SHOW );
	m_staticString3.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 22 );
	m_EditArgument3.ShowWindow( SW_SHOW );
	m_EditArgument3.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );


}



/***************************************************************************DC

	Operation:	CAPIGenDlg::Show1ML3E() 

	Purpose:	Sets up one multiple selection list control + two edit controls.

	Arguments:	csaLabels -- the strings that are used to label each control.

	Note:		

*****************************************************************************/
void CAPIGenDlg::Show1ML3E( CStringArray* pcsaLabels, CStringArray* csaListEntries  )
{
	int topGroupStart=PARAM_TOP;
	int nGroupBoxHeight = 0;
	nGroupBoxHeight	= 335;

	m_groupAddParameterGroup.ShowWindow( SW_SHOW  );
	m_groupAddParameterGroup.MoveWindow( PARAM_LEFT_SIDE-15, topGroupStart-25, STANDARD_WIDTH+30, nGroupBoxHeight );

	m_staticString1.SetWindowText( pcsaLabels->GetAt( 0 ) );
	m_staticString1.ShowWindow( SW_SHOW );
	m_staticString1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );

	listMultiParams1.ShowWindow( SW_SHOW  );
	listMultiParams1.ResetContent();
	for ( int i=0; i<csaListEntries->GetCount(); i++)
	{
		listMultiParams1.AddString( csaListEntries->GetAt(i) );
	}

	listMultiParams1.SetSel(0,TRUE);
	listMultiParams1.ShowWindow( SW_SHOW  );
	listMultiParams1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 140 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP + 120;
	m_staticString2.SetWindowText( pcsaLabels->GetAt( 1 ) );
	m_staticString2.ShowWindow( SW_SHOW );
	m_staticString2.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
	m_EditArgument1.ShowWindow( SW_SHOW );
	m_EditArgument1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
	m_staticString3.SetWindowText( pcsaLabels->GetAt( 2 ) );
	m_staticString3.ShowWindow( SW_SHOW );
	m_staticString3.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
	m_EditArgument3.ShowWindow( SW_SHOW );
	m_EditArgument3.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
	m_staticString4.SetWindowText( pcsaLabels->GetAt( 3 ) );
	m_staticString4.ShowWindow( SW_SHOW );
	m_staticString4.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
	m_EditArgument4.ShowWindow( SW_SHOW );
	m_EditArgument4.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );


}



/***************************************************************************DC

	Operation:	CAPIGenDlg::Show1ML4E() 

	Purpose:	Sets up one multiple selection list control + four edit controls.

	Arguments:	csaLabels -- the strings that are used to label each control.

	Note:		

*****************************************************************************/
void CAPIGenDlg::Show1ML4E( CStringArray* pcsaLabels, CStringArray* csaListEntries  )
{
	int topGroupStart=PARAM_TOP;
	int nGroupBoxHeight = 0;
	nGroupBoxHeight	= 365;

	m_groupAddParameterGroup.ShowWindow( SW_SHOW  );
	m_groupAddParameterGroup.MoveWindow( PARAM_LEFT_SIDE-15, topGroupStart-25, STANDARD_WIDTH+30, nGroupBoxHeight );

	m_staticString1.SetWindowText( pcsaLabels->GetAt( 0 ) );
	m_staticString1.ShowWindow( SW_SHOW );
	m_staticString1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );

	listMultiParams1.ShowWindow( SW_SHOW  );
	listMultiParams1.ResetContent();
	for ( int i=0; i<csaListEntries->GetCount(); i++)
	{
		listMultiParams1.AddString( csaListEntries->GetAt(i) );
	}

	listMultiParams1.SetSel(0,TRUE);
	listMultiParams1.ShowWindow( SW_SHOW  );
	listMultiParams1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 90 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP + 70;
	m_staticString2.SetWindowText( pcsaLabels->GetAt( 1 ) );
	m_staticString2.ShowWindow( SW_SHOW );
	m_staticString2.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
	m_EditArgument1.ShowWindow( SW_SHOW );
	m_EditArgument1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
	m_staticString3.SetWindowText( pcsaLabels->GetAt( 2 ) );
	m_staticString3.ShowWindow( SW_SHOW );
	m_staticString3.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
	m_EditArgument3.ShowWindow( SW_SHOW );
	m_EditArgument3.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
	m_staticString4.SetWindowText( pcsaLabels->GetAt( 3 ) );
	m_staticString4.ShowWindow( SW_SHOW );
	m_staticString4.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
	m_EditArgument4.ShowWindow( SW_SHOW );
	m_EditArgument4.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
	m_staticString5.SetWindowText( pcsaLabels->GetAt( 4 ) );
	m_staticString5.ShowWindow( SW_SHOW );
	m_staticString5.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
	m_EditArgument5.ShowWindow( SW_SHOW );
	m_EditArgument5.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );


}





/***************************************************************************DC

	Operation:	CAPIGenDlg::Show1L1ML2E() 

	Purpose:	Sets up one listbox + one multiple selection listbox +
				two edit controls.

	Arguments:	csaLabels -- the strings that are used to label each control.

	Note:		

*****************************************************************************/
void CAPIGenDlg::Show1L1ML2E( CStringArray* pcsaLabels, 
								 CStringArray* csaListEntries, 
								 CStringArray* csaListEntries2 )
{
	int topGroupStart=PARAM_TOP;
	int nGroupBoxHeight = 0;
	int i;	//for loop counter
	nGroupBoxHeight	= 435;

	m_groupAddParameterGroup.ShowWindow( SW_SHOW  );
	m_groupAddParameterGroup.MoveWindow( PARAM_LEFT_SIDE-15, topGroupStart-25, STANDARD_WIDTH+30, nGroupBoxHeight );

	// single-selection listbox 1
	m_staticString1.SetWindowText( pcsaLabels->GetAt( 0 ) );
	m_staticString1.ShowWindow( SW_SHOW );
	m_staticString1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );

	listParams1.ShowWindow( SW_SHOW  );
	listParams1.ResetContent();
	for ( i=0; i<csaListEntries->GetCount(); i++)
	{
		listParams1.AddString( csaListEntries->GetAt(i) );
	}
	listParams1.SetCurSel(0);
	listParams1.ShowWindow( SW_SHOW  );
	listParams1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 50 );


	// multiple-selection listbox 2
	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP + 30;
	m_staticString2.SetWindowText( pcsaLabels->GetAt( 1 ) );
	m_staticString2.ShowWindow( SW_SHOW );
	m_staticString2.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );

	listMultiParams1.ShowWindow( SW_SHOW  );
	listMultiParams1.ResetContent();
	for ( i=0; i<csaListEntries2->GetCount(); i++)
	{
		listMultiParams1.AddString( csaListEntries2->GetAt(i) );
	}

	listMultiParams1.SetSel(0,TRUE);
	listMultiParams1.ShowWindow( SW_SHOW  );
	listMultiParams1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 50 );


	// edit control 1
	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP + 40;
	m_staticString3.SetWindowText( pcsaLabels->GetAt( 2 ) );
	m_staticString3.ShowWindow( SW_SHOW );
	m_staticString3.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
	m_EditArgument1.ShowWindow( SW_SHOW );
	m_EditArgument1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

	// edit control 2
	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
	m_staticString4.SetWindowText( pcsaLabels->GetAt( 3 ) );
	m_staticString4.ShowWindow( SW_SHOW );
	m_staticString4.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
	m_EditArgument3.ShowWindow( SW_SHOW );
	m_EditArgument3.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );



}


/***************************************************************************DC

	Operation:	CAPIGenDlg::Show3E1ML() 

	Purpose:	Sets up three edit controls + one multiple selection listbox

	Arguments:	csaLabels -- the strings that are used to label each control.

	Note:		

*****************************************************************************/
void CAPIGenDlg::Show3E1ML( CStringArray* pcsaLabels, CStringArray* csaListEntries )
{
	int topGroupStart=PARAM_TOP;
	int nGroupBoxHeight = 0;
	nGroupBoxHeight	= 335;
	int i;

	m_groupAddParameterGroup.ShowWindow( SW_SHOW  );
	m_groupAddParameterGroup.MoveWindow( PARAM_LEFT_SIDE-15, topGroupStart-25, STANDARD_WIDTH+30, nGroupBoxHeight );

	m_staticString1.SetWindowText( pcsaLabels->GetAt( 0 ) );
	m_staticString1.ShowWindow( SW_SHOW );
	m_staticString1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
	m_EditArgument1.ShowWindow( SW_SHOW );
	m_EditArgument1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
	m_staticString2.SetWindowText( pcsaLabels->GetAt( 1 ) );
	m_staticString2.ShowWindow( SW_SHOW );
	m_staticString2.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
	m_EditArgument3.ShowWindow( SW_SHOW );
	m_EditArgument3.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
	m_staticString3.SetWindowText( pcsaLabels->GetAt( 2 ) );
	m_staticString3.ShowWindow( SW_SHOW );
	m_staticString3.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
	m_EditArgument4.ShowWindow( SW_SHOW );
	m_EditArgument4.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

	m_staticString4.SetWindowText( pcsaLabels->GetAt( 3 ) );
	m_staticString4.ShowWindow( SW_SHOW );
	m_staticString4.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );

	listMultiParams1.ResetContent();
	for ( i=0; i<csaListEntries->GetCount(); i++)
	{
		listMultiParams1.AddString( csaListEntries->GetAt(i) );
	}

	listMultiParams1.SetSel(0,TRUE);
	listMultiParams1.ShowWindow( SW_SHOW  );
	listMultiParams1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 40 );

}


/***************************************************************************DC

	Operation:	CAPIGenDlg::Show4E1ML() 

	Purpose:	Sets up four edit controls + one multiple selection listbox

	Arguments:	csaLabels -- the strings that are used to label each control.

	Note:		

*****************************************************************************/
void CAPIGenDlg::Show4E1ML( CStringArray* pcsaLabels, CStringArray* csaListEntries )
{
	int topGroupStart=PARAM_TOP;
	int nGroupBoxHeight = 0;
	nGroupBoxHeight	= 385;
	int i;

	m_groupAddParameterGroup.ShowWindow( SW_SHOW  );
	m_groupAddParameterGroup.MoveWindow( PARAM_LEFT_SIDE-15, topGroupStart-25, STANDARD_WIDTH+30, nGroupBoxHeight );

	m_staticString1.SetWindowText( pcsaLabels->GetAt( 0 ) );
	m_staticString1.ShowWindow( SW_SHOW );
	m_staticString1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
	m_EditArgument1.ShowWindow( SW_SHOW );
	m_EditArgument1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
	m_staticString2.SetWindowText( pcsaLabels->GetAt( 1 ) );
	m_staticString2.ShowWindow( SW_SHOW );
	m_staticString2.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
	m_EditArgument3.ShowWindow( SW_SHOW );
	m_EditArgument3.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
	m_staticString3.SetWindowText( pcsaLabels->GetAt( 2 ) );
	m_staticString3.ShowWindow( SW_SHOW );
	m_staticString3.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
	m_EditArgument4.ShowWindow( SW_SHOW );
	m_EditArgument4.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
	m_staticString4.SetWindowText( pcsaLabels->GetAt( 3 ) );
	m_staticString4.ShowWindow( SW_SHOW );
	m_staticString4.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
	m_EditArgument5.ShowWindow( SW_SHOW );
	m_EditArgument5.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
	m_staticString5.SetWindowText( pcsaLabels->GetAt( 4 ) );
	m_staticString5.ShowWindow( SW_SHOW );
	m_staticString5.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );

	listMultiParams1.ResetContent();
	for ( i=0; i<csaListEntries->GetCount(); i++)
	{
		listMultiParams1.AddString( csaListEntries->GetAt(i) );
	}

	listMultiParams1.SetSel(0,TRUE);
	listMultiParams1.ShowWindow( SW_SHOW  );
	listMultiParams1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 40 );

}


/***************************************************************************DC

	Operation:	CAPIGenDlg::Show5E1ML1L2E() 

	Purpose:	Sets up five edit controls + one multiple selection listbox + 
				one listbox + two edit control2.

	Arguments:	csaLabels -- the strings that are used to label each control.

	Note:		

*****************************************************************************/
void CAPIGenDlg::Show5E1ML1L2E( CStringArray* pcsaLabels, 
								 CStringArray* csaListEntries, 
								 CStringArray* csaListEntries2  )
{
	int topGroupStart=PARAM_TOP;
	int nGroupBoxHeight = 0;
	nGroupBoxHeight	= 485;
	int i;

	m_groupAddParameterGroup.ShowWindow( SW_SHOW  );
	m_groupAddParameterGroup.MoveWindow( PARAM_LEFT_SIDE-15, topGroupStart-25, STANDARD_WIDTH+30, nGroupBoxHeight );

	m_staticString1.SetWindowText( pcsaLabels->GetAt( 0 ) );
	m_staticString1.ShowWindow( SW_SHOW );
	m_staticString1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
	m_EditArgument1.ShowWindow( SW_SHOW );
	m_EditArgument1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
	m_staticString2.SetWindowText( pcsaLabels->GetAt( 1 ) );
	m_staticString2.ShowWindow( SW_SHOW );
	m_staticString2.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
	m_EditArgument3.ShowWindow( SW_SHOW );
	m_EditArgument3.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
	m_staticString3.SetWindowText( pcsaLabels->GetAt( 2 ) );
	m_staticString3.ShowWindow( SW_SHOW );
	m_staticString3.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
	m_EditArgument4.ShowWindow( SW_SHOW );
	m_EditArgument4.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
	m_staticString4.SetWindowText( pcsaLabels->GetAt( 3 ) );
	m_staticString4.ShowWindow( SW_SHOW );
	m_staticString4.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
	m_EditArgument5.ShowWindow( SW_SHOW );
	m_EditArgument5.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
	m_staticString5.SetWindowText( pcsaLabels->GetAt( 4 ) );
	m_staticString5.ShowWindow( SW_SHOW );
	m_staticString5.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
	m_EditArgument6.ShowWindow( SW_SHOW );
	m_EditArgument6.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
	m_staticString6.SetWindowText( pcsaLabels->GetAt( 5 ) );
	m_staticString6.ShowWindow( SW_SHOW );
	m_staticString6.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );

	listMultiParams1.ResetContent();
	for ( i=0; i<csaListEntries->GetCount(); i++)
	{
		listMultiParams1.AddString( csaListEntries->GetAt(i) );
	}

	listMultiParams1.SetSel(0,TRUE);
	listMultiParams1.ShowWindow( SW_SHOW  );
	listMultiParams1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 40 );


	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP + 20;
	m_staticString7.SetWindowText( pcsaLabels->GetAt( 6 ) );
	m_staticString7.ShowWindow( SW_SHOW );
	m_staticString7.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );

	listParams1.ShowWindow( SW_SHOW  );
	listParams1.ResetContent();
	for ( int i=0; i<csaListEntries2->GetCount(); i++)
	{
		listParams1.AddString( csaListEntries2->GetAt(i) );
	}

	listParams1.SetCurSel(0);
	listParams1.ShowWindow( SW_SHOW  );
	listParams1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 40 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP + 20;
	m_staticString8.SetWindowText( pcsaLabels->GetAt( 7 ) );
	m_staticString8.ShowWindow( SW_SHOW );
	m_staticString8.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
	m_EditArgument7.ShowWindow( SW_SHOW );
	m_EditArgument7.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
	m_staticString9.SetWindowText( pcsaLabels->GetAt( 8 ) );
	m_staticString9.ShowWindow( SW_SHOW );
	m_staticString9.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
	m_EditArgument8.ShowWindow( SW_SHOW );
	m_EditArgument8.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );


}





/***************************************************************************DC

	Operation:	CAPIGenDlg::Show2ML1L1ML1E() 

	Purpose:	Sets up two multiple selection listboxes + one listbox +
				one multiple selection listbox + one edit control.

	Arguments:	csaLabels -- the strings that are used to label each control.

	Note:		

*****************************************************************************/
void CAPIGenDlg::Show2ML1L1ML1E( CStringArray* pcsaLabels, 
								 CStringArray* csaListEntries, 
								 CStringArray* csaListEntries2, 
								 CStringArray* csaListEntries3, 
								 CStringArray* csaListEntries4  )
{
	int topGroupStart=PARAM_TOP;
	int nGroupBoxHeight = 0;
	int i;	//for loop counter
	nGroupBoxHeight	= 435;

	m_groupAddParameterGroup.ShowWindow( SW_SHOW  );
	m_groupAddParameterGroup.MoveWindow( PARAM_LEFT_SIDE-15, topGroupStart-25, STANDARD_WIDTH+30, nGroupBoxHeight );

	// multiple-selection listbox 1
	m_staticString1.SetWindowText( pcsaLabels->GetAt( 0 ) );
	m_staticString1.ShowWindow( SW_SHOW );
	m_staticString1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );


	listMultiParams1.ResetContent();
	for ( i=0; i<csaListEntries->GetCount(); i++)
	{
		listMultiParams1.AddString( csaListEntries->GetAt(i) );
	}

	listMultiParams1.SetSel(0,TRUE);
	listMultiParams1.ShowWindow( SW_SHOW  );
	listMultiParams1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 50 );

	// multiple-selection listbox 2
	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP + 30;
	m_staticString2.SetWindowText( pcsaLabels->GetAt( 1 ) );
	m_staticString2.ShowWindow( SW_SHOW );
	m_staticString2.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );

	listMultiParams2.ShowWindow( SW_SHOW  );
	listMultiParams2.ResetContent();
	for ( i=0; i<csaListEntries2->GetCount(); i++)
	{
		listMultiParams2.AddString( csaListEntries2->GetAt(i) );
	}

	listMultiParams2.SetSel(0,TRUE);
	listMultiParams2.ShowWindow( SW_SHOW  );
	listMultiParams2.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 50 );


	// single-selection listbox 1
	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP + 30;
	m_staticString3.SetWindowText( pcsaLabels->GetAt( 2 ) );
	m_staticString3.ShowWindow( SW_SHOW );
	m_staticString3.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );

	listParams1.ShowWindow( SW_SHOW  );
	listParams1.ResetContent();
	for ( i=0; i<csaListEntries3->GetCount(); i++)
	{
		listParams1.AddString( csaListEntries3->GetAt(i) );
	}
	listParams1.SetCurSel(0);
	listParams1.ShowWindow( SW_SHOW  );
	listParams1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 50 );


	// multiple-selection listbox 3
	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP + 30;
	m_staticString4.SetWindowText( pcsaLabels->GetAt( 3 ) );
	m_staticString4.ShowWindow( SW_SHOW );
	m_staticString4.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );

	listMultiParams3.ShowWindow( SW_SHOW  );
	listMultiParams3.ResetContent();
	for ( i=0; i<csaListEntries4->GetCount(); i++)
	{
		listMultiParams3.AddString( csaListEntries4->GetAt(i) );
	}

	listMultiParams3.SetSel(0,TRUE);
	listMultiParams3.ShowWindow( SW_SHOW  );
	listMultiParams3.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 60 );


	// edit control
	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP + 40;
	m_staticString5.SetWindowText( pcsaLabels->GetAt( 4 ) );
	m_staticString5.ShowWindow( SW_SHOW );
	m_staticString5.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
	m_EditArgument1.ShowWindow( SW_SHOW );
	m_EditArgument1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );



}




/***************************************************************************DC

	Operation:	CAPIGenDlg::Show1L3E() 

	Purpose:	Sets up one listbox + one edit control.

	Arguments:	csaLabels -- the strings that are used to label each control.

	Note:		

*****************************************************************************/
void CAPIGenDlg::Show1L3E( CStringArray* pcsaLabels, CStringArray* csaListEntries  )
{
	int topGroupStart=PARAM_TOP;
	int nGroupBoxHeight = 0;
	nGroupBoxHeight	= 265;

	m_groupAddParameterGroup.ShowWindow( SW_SHOW  );
	m_groupAddParameterGroup.MoveWindow( PARAM_LEFT_SIDE-15, topGroupStart-25, STANDARD_WIDTH+30, nGroupBoxHeight );

	m_staticString1.SetWindowText( pcsaLabels->GetAt( 0 ) );
	m_staticString1.ShowWindow( SW_SHOW );
	m_staticString1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );

	listParams1.ShowWindow( SW_SHOW  );
	listParams1.ResetContent();
	for ( int i=0; i<csaListEntries->GetCount(); i++)
	{
		listParams1.AddString( csaListEntries->GetAt(i) );
	}

	listParams1.SetCurSel(0);
	listParams1.ShowWindow( SW_SHOW  );
	listParams1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 80 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP + 60;
	m_staticString2.SetWindowText( pcsaLabels->GetAt( 1 ) );
	m_staticString2.ShowWindow( SW_SHOW );
	m_staticString2.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
	m_EditArgument1.ShowWindow( SW_SHOW );
	m_EditArgument1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
	m_staticString3.SetWindowText( pcsaLabels->GetAt( 2 ) );
	m_staticString3.ShowWindow( SW_SHOW );
	m_staticString3.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
	m_EditArgument3.ShowWindow( SW_SHOW );
	m_EditArgument3.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
	m_staticString4.SetWindowText( pcsaLabels->GetAt( 3 ) );
	m_staticString4.ShowWindow( SW_SHOW );
	m_staticString4.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
	m_EditArgument4.ShowWindow( SW_SHOW );
	m_EditArgument4.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );


}



/***************************************************************************DC

	Operation:	CAPIGenDlg::Show1L5E1L() 

	Purpose:	Sets up one listbox + five edit controls + one listbox.

	Arguments:	csaLabels -- the strings that are used to label each control.

	Note:		ZModemReceiveFile & WaitForEvent are popping errors

*****************************************************************************/
void CAPIGenDlg::Show1L5E1L( CStringArray* pcsaLabels, CStringArray* csaListEntries, CStringArray* csaList2Entries )
{
	int topGroupStart=PARAM_TOP;
	int nGroupBoxHeight = 0;
	int i;
	nGroupBoxHeight	= 385;

	m_groupAddParameterGroup.ShowWindow( SW_SHOW  );
	m_groupAddParameterGroup.MoveWindow( PARAM_LEFT_SIDE-15, topGroupStart-25, STANDARD_WIDTH+30, nGroupBoxHeight );

	m_staticString1.SetWindowText( pcsaLabels->GetAt( 0 ) );
	m_staticString1.ShowWindow( SW_SHOW );
	m_staticString1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );

	listParams1.ShowWindow( SW_SHOW  );
	listParams1.ResetContent();
	for ( i=0; i<csaListEntries->GetCount(); i++)
	{
		listParams1.AddString( csaListEntries->GetAt(i) );
	}

	listParams1.SetCurSel(0);
	listParams1.ShowWindow( SW_SHOW  );
	listParams1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 80 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP + 60;
	m_staticString2.SetWindowText( pcsaLabels->GetAt( 1 ) );
	m_staticString2.ShowWindow( SW_SHOW );
	m_staticString2.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
	m_EditArgument1.ShowWindow( SW_SHOW );
	m_EditArgument1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
	m_staticString3.SetWindowText( pcsaLabels->GetAt( 2 ) );
	m_staticString3.ShowWindow( SW_SHOW );
	m_staticString3.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
	m_EditArgument3.ShowWindow( SW_SHOW );
	m_EditArgument3.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
	m_staticString4.SetWindowText( pcsaLabels->GetAt( 3 ) );
	m_staticString4.ShowWindow( SW_SHOW );
	m_staticString4.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
	m_EditArgument4.ShowWindow( SW_SHOW );
	m_EditArgument4.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
	m_staticString5.SetWindowText( pcsaLabels->GetAt( 4 ) );
	m_staticString5.ShowWindow( SW_SHOW );
	m_staticString5.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
	m_EditArgument5.ShowWindow( SW_SHOW );
	m_EditArgument5.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
	m_staticString6.SetWindowText( pcsaLabels->GetAt( 5 ) );
	m_staticString6.ShowWindow( SW_SHOW );
	m_staticString6.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
	m_EditArgument6.ShowWindow( SW_SHOW );
	m_EditArgument6.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP + 20;
	m_staticString7.SetWindowText( pcsaLabels->GetAt( 6 ) );
	m_staticString7.ShowWindow( SW_SHOW );
	m_staticString7.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 22 );

	listParams2.ShowWindow( SW_SHOW  );
	listParams2.ResetContent();
	for ( i=0; i<csaList2Entries->GetCount(); i++)
	{
		listParams2.AddString( csaList2Entries->GetAt(i) );
	}
	listParams2.SetCurSel(0);
	listParams2.ShowWindow( SW_SHOW  );
	listParams2.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 60 );

}



/***************************************************************************DC

	Operation:	CAPIGenDlg::Show1C1L1C1E() 

	Purpose:	Sets up one listbox + one checkbox + one edit control

	Arguments:	csaLabels -- the strings that are used to label each control.

	Note:		

*****************************************************************************/
void CAPIGenDlg::Show1C1L1C1E( CStringArray* pcsaLabels, CStringArray* csaListEntries )
{
	int topGroupStart=PARAM_TOP;
	int nGroupBoxHeight = 0;
	nGroupBoxHeight	= 285;

	m_groupAddParameterGroup.ShowWindow( SW_SHOW  );
	m_groupAddParameterGroup.MoveWindow( PARAM_LEFT_SIDE-15, topGroupStart-25, STANDARD_WIDTH+30, nGroupBoxHeight );

	checkParam1.SetWindowText( pcsaLabels->GetAt( 0 ) );
	checkParam1.ShowWindow( SW_SHOW );
	checkParam1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP - 10;
	m_staticString1.SetWindowText( pcsaLabels->GetAt( 1 ) );
	m_staticString1.ShowWindow( SW_SHOW );
	m_staticString1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );

	listParams1.ShowWindow( SW_SHOW  );
	listParams1.ResetContent();
	for ( int i=0; i<csaListEntries->GetCount(); i++)
	{
		listParams1.AddString( csaListEntries->GetAt(i) );
	}

	listParams1.SetCurSel(0);
	listParams1.ShowWindow( SW_SHOW  );
	listParams1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 50 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP + 35;
	checkParam2.SetWindowText( pcsaLabels->GetAt( 2 ) );
	checkParam2.ShowWindow( SW_SHOW );
	checkParam2.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP - 10;
	m_staticString2.SetWindowText( pcsaLabels->GetAt( 3 ) );
	m_staticString2.ShowWindow( SW_SHOW );
	m_staticString2.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
	m_EditArgument1.ShowWindow( SW_SHOW );
	m_EditArgument1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

}




/***************************************************************************DC

	Operation:	CAPIGenDlg::Show1L5E1C() 

	Purpose:	Sets up one listbox + five edit controls + one checkbox.

	Arguments:	csaLabels -- the strings that are used to label each control.

	Note:		

*****************************************************************************/
void CAPIGenDlg::Show1L5E1C( CStringArray* pcsaLabels, CStringArray* csaListEntries )
{
	int topGroupStart=PARAM_TOP;
	int nGroupBoxHeight = 0;
	nGroupBoxHeight	= 385;

	m_groupAddParameterGroup.ShowWindow( SW_SHOW  );
	m_groupAddParameterGroup.MoveWindow( PARAM_LEFT_SIDE-15, topGroupStart-25, STANDARD_WIDTH+30, nGroupBoxHeight );

	m_staticString1.SetWindowText( pcsaLabels->GetAt( 0 ) );
	m_staticString1.ShowWindow( SW_SHOW );
	m_staticString1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );

	listParams1.ShowWindow( SW_SHOW  );
	listParams1.ResetContent();
	for ( int i=0; i<csaListEntries->GetCount(); i++)
	{
		listParams1.AddString( csaListEntries->GetAt(i) );
	}

	listParams1.SetCurSel(0);
	listParams1.ShowWindow( SW_SHOW  );
	listParams1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 80 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP + 60;
	m_staticString2.SetWindowText( pcsaLabels->GetAt( 1 ) );
	m_staticString2.ShowWindow( SW_SHOW );
	m_staticString2.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
	m_EditArgument1.ShowWindow( SW_SHOW );
	m_EditArgument1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
	m_staticString3.SetWindowText( pcsaLabels->GetAt( 2 ) );
	m_staticString3.ShowWindow( SW_SHOW );
	m_staticString3.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
	m_EditArgument3.ShowWindow( SW_SHOW );
	m_EditArgument3.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
	m_staticString4.SetWindowText( pcsaLabels->GetAt( 3 ) );
	m_staticString4.ShowWindow( SW_SHOW );
	m_staticString4.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
	m_EditArgument4.ShowWindow( SW_SHOW );
	m_EditArgument4.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
	m_staticString5.SetWindowText( pcsaLabels->GetAt( 4 ) );
	m_staticString5.ShowWindow( SW_SHOW );
	m_staticString5.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
	m_EditArgument5.ShowWindow( SW_SHOW );
	m_EditArgument5.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
	m_staticString6.SetWindowText( pcsaLabels->GetAt( 5 ) );
	m_staticString6.ShowWindow( SW_SHOW );
	m_staticString6.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
	m_EditArgument6.ShowWindow( SW_SHOW );
	m_EditArgument6.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
	checkParam1.SetWindowText( pcsaLabels->GetAt( 6 ) );
	checkParam1.ShowWindow( SW_SHOW );
	checkParam1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 22 );

}




/***************************************************************************DC

	Operation:	CAPIGenDlg::Show1E1B() 

	Purpose:	Sets up one edit control + one button

	Arguments:	csaLabels -- the strings that are used to label each control.

	Note:		

*****************************************************************************/
void CAPIGenDlg::Show1E1B( CStringArray* pcsaLabels  )
{
	int topGroupStart=PARAM_TOP;
	int nGroupBoxHeight = 0;
	nGroupBoxHeight	= 115;

	m_groupAddParameterGroup.ShowWindow( SW_SHOW  );
	m_groupAddParameterGroup.MoveWindow( PARAM_LEFT_SIDE-15, topGroupStart-25, STANDARD_WIDTH+30, nGroupBoxHeight );

	m_staticString1.SetWindowText( pcsaLabels->GetAt( 0 ) );
	m_staticString1.ShowWindow( SW_SHOW );
	m_staticString1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 22 );
	m_EditArgument1.ShowWindow( SW_SHOW );
	m_EditArgument1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
	m_buttonBrowseFileTransfer.ShowWindow( SW_SHOW  );
	m_buttonBrowseFileTransfer.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, 145, 22 );

	m_buttonBrowseFileTransfer.ShowWindow( SW_SHOW  );
}


/***************************************************************************DC

	Operation:	CAPIGenDlg::Show1EB1E() 

	Purpose:	Sets up two edit controls + one button

	Arguments:	csaLabels -- the strings that are used to label each control.

	Note:		

*****************************************************************************/
void CAPIGenDlg::Show1EB1E( CStringArray* pcsaLabels  )
{
	int topGroupStart=PARAM_TOP;
	int nGroupBoxHeight = 0;
	nGroupBoxHeight	= 185;

	m_groupAddParameterGroup.ShowWindow( SW_SHOW  );
	m_groupAddParameterGroup.MoveWindow( PARAM_LEFT_SIDE-15, topGroupStart-25, STANDARD_WIDTH+30, nGroupBoxHeight );

	m_staticString1.SetWindowText( pcsaLabels->GetAt( 0 ) );
	m_staticString1.ShowWindow( SW_SHOW );
	m_staticString1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
	m_EditArgument1.ShowWindow( SW_SHOW );
	m_EditArgument1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
	m_buttonBrowseFileTransfer.ShowWindow( SW_SHOW  );
	m_buttonBrowseFileTransfer.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, 145, 22 );
	m_buttonBrowseFileTransfer.ShowWindow( SW_SHOW  );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
	m_staticString2.SetWindowText( pcsaLabels->GetAt( 1 ) );
	m_staticString2.ShowWindow( SW_SHOW );
	m_staticString2.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
	m_EditArgument3.ShowWindow( SW_SHOW );
	m_EditArgument3.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );


}



/***************************************************************************DC

	Operation:	CAPIGenDlg::Show1C2E() 

	Purpose:	Sets up one checkbox + two edit controls

	Arguments:	csaLabels -- the strings that are used to label each control.

	Note:		

*****************************************************************************/
void CAPIGenDlg::Show1C2E( CStringArray* pcsaLabels  )
{
	int topGroupStart=PARAM_TOP;
	int nGroupBoxHeight = 0;
	nGroupBoxHeight	= 285;

	m_groupAddParameterGroup.ShowWindow( SW_SHOW  );
	m_groupAddParameterGroup.MoveWindow( PARAM_LEFT_SIDE-15, topGroupStart-25, STANDARD_WIDTH+30, nGroupBoxHeight );

	checkParam1.SetWindowText( pcsaLabels->GetAt( 0 ) );
	checkParam1.ShowWindow( SW_SHOW );
	checkParam1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP - 10;
	m_staticString1.SetWindowText( pcsaLabels->GetAt( 1 ) );
	m_staticString1.ShowWindow( SW_SHOW );
	m_staticString1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
	m_EditArgument1.ShowWindow( SW_SHOW );
	m_EditArgument1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
	m_buttonSessionFilename.ShowWindow( SW_SHOW  );
	m_buttonSessionFilename.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, 145, 22 );

	m_buttonSessionFilename.ShowWindow( SW_SHOW  );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP - 10;
	m_staticString2.SetWindowText( pcsaLabels->GetAt( 2 ) );
	m_staticString2.ShowWindow( SW_SHOW );
	m_staticString2.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
	m_EditArgument3.ShowWindow( SW_SHOW );
	m_EditArgument3.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

}





/***************************************************************************DC

	Operation:	CAPIGenDlg::Show1C2EB() 

	Purpose:	Sets up one checkbox + two edit control + button pairs

	Arguments:	csaLabels -- the strings that are used to label each control.

	Note:		

*****************************************************************************/
void CAPIGenDlg::Show1C2EB( CStringArray* pcsaLabels  )
{
	int topGroupStart=PARAM_TOP;
	int nGroupBoxHeight = 0;
	nGroupBoxHeight	= 285;

	m_groupAddParameterGroup.ShowWindow( SW_SHOW  );
	m_groupAddParameterGroup.MoveWindow( PARAM_LEFT_SIDE-15, topGroupStart-25, STANDARD_WIDTH+30, nGroupBoxHeight );

	checkParam1.SetWindowText( pcsaLabels->GetAt( 0 ) );
	checkParam1.ShowWindow( SW_SHOW );
	checkParam1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP - 10;
	m_staticString1.SetWindowText( pcsaLabels->GetAt( 1 ) );
	m_staticString1.ShowWindow( SW_SHOW );
	m_staticString1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
	m_EditArgument1.ShowWindow( SW_SHOW );
	m_EditArgument1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
	m_buttonSessionFilename.ShowWindow( SW_SHOW  );
	m_buttonSessionFilename.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, 145, 22 );

	m_buttonSessionFilename.ShowWindow( SW_SHOW  );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP - 10;
	m_staticString2.SetWindowText( pcsaLabels->GetAt( 2 ) );
	m_staticString2.ShowWindow( SW_SHOW );
	m_staticString2.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
	m_EditArgument3.ShowWindow( SW_SHOW );
	m_EditArgument3.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
	m_ButtonBrowseKeyMap.ShowWindow( SW_SHOW  );
	m_ButtonBrowseKeyMap.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, 145, 22 );

	m_ButtonBrowseKeyMap.ShowWindow( SW_SHOW  );

}




/***************************************************************************DC

	Operation:	CAPIGenDlg::Show3EB() 

	Purpose:	Sets up three edit control + button pairs

	Arguments:	csaLabels -- the strings that are used to label each control.

	Note:		

*****************************************************************************/
void CAPIGenDlg::Show3EB( CStringArray* pcsaLabels  )
{
	int topGroupStart=PARAM_TOP;
	int nGroupBoxHeight = 0;
	nGroupBoxHeight	= 285;

	m_groupAddParameterGroup.ShowWindow( SW_SHOW  );
	m_groupAddParameterGroup.MoveWindow( PARAM_LEFT_SIDE-15, topGroupStart-25, STANDARD_WIDTH+30, nGroupBoxHeight );

	m_staticString1.SetWindowText( pcsaLabels->GetAt( 0 ) );
	m_staticString1.ShowWindow( SW_SHOW );
	m_staticString1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
	m_EditArgument1.ShowWindow( SW_SHOW );
	m_EditArgument1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
	m_buttonSessionFilename.ShowWindow( SW_SHOW  );
	m_buttonSessionFilename.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, 145, 22 );

	m_buttonSessionFilename.ShowWindow( SW_SHOW  );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP - 10;
	m_staticString2.SetWindowText( pcsaLabels->GetAt( 1 ) );
	m_staticString2.ShowWindow( SW_SHOW );
	m_staticString2.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
	m_EditArgument3.ShowWindow( SW_SHOW );
	m_EditArgument3.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
	m_ButtonBrowseKeyMap.ShowWindow( SW_SHOW  );
	m_ButtonBrowseKeyMap.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, 145, 22 );

	m_ButtonBrowseKeyMap.ShowWindow( SW_SHOW  );


	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP - 10;
	m_staticString3.SetWindowText( pcsaLabels->GetAt( 2 ) );
	m_staticString3.ShowWindow( SW_SHOW );
	m_staticString3.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
	m_EditArgument4.ShowWindow( SW_SHOW );
	m_EditArgument4.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
	m_buttonBrowseFileTransfer.ShowWindow( SW_SHOW  );
	m_buttonBrowseFileTransfer.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, 145, 22 );

	m_buttonBrowseFileTransfer.ShowWindow( SW_SHOW  );


}




/***************************************************************************DC

	Operation:	CAPIGenDlg::Show1E1B1C() 

	Purpose:	Sets up one edit control + one button + one edit control +
				one checkbox

	Arguments:	csaLabels -- the strings that are used to label each control.

	Note:		

*****************************************************************************/
void CAPIGenDlg::Show1E1B1C( CStringArray* pcsaLabels  )
{
	int topGroupStart=PARAM_TOP;
	int nGroupBoxHeight = 0;
	nGroupBoxHeight	= 155;

	m_groupAddParameterGroup.ShowWindow( SW_SHOW  );
	m_groupAddParameterGroup.MoveWindow( PARAM_LEFT_SIDE-15, topGroupStart-25, STANDARD_WIDTH+30, nGroupBoxHeight );

	m_staticString1.SetWindowText( pcsaLabels->GetAt( 0 ) );
	m_staticString1.ShowWindow( SW_SHOW );
	m_staticString1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 22 );
	m_EditArgument1.ShowWindow( SW_SHOW );
	m_EditArgument1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
	m_buttonBrowseFileTransfer.ShowWindow( SW_SHOW  );
	m_buttonBrowseFileTransfer.MoveWindow( PARAM_LEFT_SIDE+30, topGroupStart, 85, 22 );
	m_buttonBrowseFileTransfer.ShowWindow( SW_SHOW  );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP + 10;
	checkParam1.SetWindowText( pcsaLabels->GetAt( 1 ) );
	checkParam1.ShowWindow( SW_SHOW );
	checkParam1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 22 );

}


/***************************************************************************DC

	Operation:	CAPIGenDlg::Show1C1E1B() 

	Purpose:	Sets up one checkbox + edit control + one button

	Arguments:	csaLabels -- the strings that are used to label each control.

	Note:		

*****************************************************************************/
void CAPIGenDlg::Show1C1E1B( CStringArray* pcsaLabels  )
{
	int topGroupStart=PARAM_TOP;
	int nGroupBoxHeight = 0;
	nGroupBoxHeight	= 155;

	m_groupAddParameterGroup.ShowWindow( SW_SHOW  );
	m_groupAddParameterGroup.MoveWindow( PARAM_LEFT_SIDE-15, topGroupStart-25, STANDARD_WIDTH+30, nGroupBoxHeight );

	checkParam1.SetWindowText( pcsaLabels->GetAt( 0 ) );
	checkParam1.ShowWindow( SW_SHOW );
	checkParam1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP - 10;
	m_staticString1.SetWindowText( pcsaLabels->GetAt( 1 ) );
	m_staticString1.ShowWindow( SW_SHOW );
	m_staticString1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 22 );
	m_EditArgument1.ShowWindow( SW_SHOW );
	m_EditArgument1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
	m_buttonBrowseFileTransfer.ShowWindow( SW_SHOW  );
	m_buttonBrowseFileTransfer.MoveWindow( PARAM_LEFT_SIDE+30, topGroupStart, 85, 22 );
	m_buttonBrowseFileTransfer.ShowWindow( SW_SHOW  );

}


/***************************************************************************DC

	Operation:	CAPIGenDlg::Show1E1B1E() 

	Purpose:	Sets up one edit control + one button + one edit control

	Arguments:	csaLabels -- the strings that are used to label each control.

	Note:		

*****************************************************************************/
void CAPIGenDlg::Show1E1B1E( CStringArray* pcsaLabels  )
{
	int topGroupStart=PARAM_TOP;
	int nGroupBoxHeight = 0;
	nGroupBoxHeight	= 185;

	m_groupAddParameterGroup.ShowWindow( SW_SHOW  );
	m_groupAddParameterGroup.MoveWindow( PARAM_LEFT_SIDE-15, topGroupStart-25, STANDARD_WIDTH+30, nGroupBoxHeight );

	m_staticString1.SetWindowText( pcsaLabels->GetAt( 0 ) );
	m_staticString1.ShowWindow( SW_SHOW );
	m_staticString1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 22 );
	m_EditArgument1.ShowWindow( SW_SHOW );
	m_EditArgument1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
	m_buttonBrowseFileTransfer.ShowWindow( SW_SHOW  );
	m_buttonBrowseFileTransfer.MoveWindow( PARAM_LEFT_SIDE+30, topGroupStart, 85, 22 );
	m_buttonBrowseFileTransfer.ShowWindow( SW_SHOW  );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
	m_staticString2.SetWindowText( pcsaLabels->GetAt( 1 ) );
	m_staticString2.ShowWindow( SW_SHOW );
	m_staticString2.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 22 );
	m_EditArgument3.ShowWindow( SW_SHOW );
	m_EditArgument3.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

}




/***************************************************************************DC

	Operation:	CAPIGenDlg::Show1E1B1E1C() 

	Purpose:	Sets up one edit control + one button + one edit control +
				one checkbox

	Arguments:	csaLabels -- the strings that are used to label each control.

	Note:		

*****************************************************************************/
void CAPIGenDlg::Show1E1B1E1C( CStringArray* pcsaLabels  )
{
	int topGroupStart=PARAM_TOP;
	int nGroupBoxHeight = 0;
	nGroupBoxHeight	= 195;

	m_groupAddParameterGroup.ShowWindow( SW_SHOW  );
	m_groupAddParameterGroup.MoveWindow( PARAM_LEFT_SIDE-15, topGroupStart-25, STANDARD_WIDTH+30, nGroupBoxHeight );

	m_staticString1.SetWindowText( pcsaLabels->GetAt( 0 ) );
	m_staticString1.ShowWindow( SW_SHOW );
	m_staticString1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 22 );
	m_EditArgument1.ShowWindow( SW_SHOW );
	m_EditArgument1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
	m_buttonBrowseFileTransfer.ShowWindow( SW_SHOW  );
	m_buttonBrowseFileTransfer.MoveWindow( PARAM_LEFT_SIDE+30, topGroupStart, 85, 22 );
	m_buttonBrowseFileTransfer.ShowWindow( SW_SHOW  );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
	m_staticString2.SetWindowText( pcsaLabels->GetAt( 1 ) );
	m_staticString2.ShowWindow( SW_SHOW );
	m_staticString2.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 22 );
	m_EditArgument3.ShowWindow( SW_SHOW );
	m_EditArgument3.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP + 10;
	checkParam1.SetWindowText( pcsaLabels->GetAt( 2 ) );
	checkParam1.ShowWindow( SW_SHOW );
	checkParam1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 22 );

}



/***************************************************************************DC

	Operation:	CAPIGenDlg::Show1E1C() 

	Purpose:	Sets up one checkbox.

	Arguments:	csaLabels -- the strings that are used to label each control.

	Note:		

*****************************************************************************/
void CAPIGenDlg::Show1E1C( CStringArray* pcsaLabels  )
{
	int topGroupStart=PARAM_TOP;
	int nGroupBoxHeight = 0;
	nGroupBoxHeight	= 135;

	m_groupAddParameterGroup.ShowWindow( SW_SHOW  );
	m_groupAddParameterGroup.MoveWindow( PARAM_LEFT_SIDE-15, topGroupStart-25, STANDARD_WIDTH+30, nGroupBoxHeight );

	m_staticString1.SetWindowText( pcsaLabels->GetAt( 0 ) );
	m_staticString1.ShowWindow( SW_SHOW );
	m_staticString1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 22 );
	m_EditArgument1.ShowWindow( SW_SHOW );
	m_EditArgument1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
	checkParam1.SetWindowText( pcsaLabels->GetAt( 1 ) );
	checkParam1.ShowWindow( SW_SHOW );
	checkParam1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 22 );
}



/***************************************************************************DC

	Operation:	CAPIGenDlg::Show1E1C1E() 

	Purpose:	Sets up one edit control + one checkbox + one edit control.

	Arguments:	csaLabels -- the strings that are used to label each control.

	Note:		

*****************************************************************************/
void CAPIGenDlg::Show1E1C1E( CStringArray* pcsaLabels  )
{
	int topGroupStart=PARAM_TOP;
	int nGroupBoxHeight = 0;
	nGroupBoxHeight	= 185;

	m_groupAddParameterGroup.ShowWindow( SW_SHOW  );
	m_groupAddParameterGroup.MoveWindow( PARAM_LEFT_SIDE-15, topGroupStart-25, STANDARD_WIDTH+30, nGroupBoxHeight );

	m_staticString1.SetWindowText( pcsaLabels->GetAt( 0 ) );
	m_staticString1.ShowWindow( SW_SHOW );
	m_staticString1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
	m_EditArgument1.ShowWindow( SW_SHOW );
	m_EditArgument1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
	checkParam1.SetWindowText( pcsaLabels->GetAt( 1 ) );
	checkParam1.ShowWindow( SW_SHOW );
	checkParam1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP - 15;
	m_staticString2.SetWindowText( pcsaLabels->GetAt( 2 ) );
	m_staticString2.ShowWindow( SW_SHOW );
	m_staticString2.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
	m_EditArgument3.ShowWindow( SW_SHOW );
	m_EditArgument3.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

}


/***************************************************************************DC

	Operation:	CAPIGenDlg::Show1C1L() 

	Purpose:	Sets up one checkbox + one listbox

	Arguments:	csaLabels -- the strings that are used to label each control.

	Note:		

*****************************************************************************/
void CAPIGenDlg::Show1C1L( CStringArray* pcsaLabels, CStringArray* csaListEntries  )
{
	int topGroupStart=PARAM_TOP;
	int nGroupBoxHeight	= 160;

	m_groupAddParameterGroup.ShowWindow( SW_SHOW  );
	m_groupAddParameterGroup.MoveWindow( PARAM_LEFT_SIDE-15, topGroupStart-25, STANDARD_WIDTH+30, nGroupBoxHeight );

	checkParam1.SetWindowText( pcsaLabels->GetAt( 0 ) );
	checkParam1.ShowWindow( SW_SHOW );
	checkParam1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP - 10;
	m_staticString2.SetWindowText( pcsaLabels->GetAt( 1 ) );
	m_staticString2.ShowWindow( SW_SHOW );
	m_staticString2.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 22 );

	listParams1.ShowWindow( SW_SHOW  );
	listParams1.ResetContent();
	for ( int i=0; i<csaListEntries->GetCount(); i++)
	{
		listParams1.AddString( csaListEntries->GetAt(i) );
	}

	listParams1.SetCurSel(0);
	listParams1.ShowWindow( SW_SHOW  );
	listParams1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 40 );

}


/***************************************************************************DC

	Operation:	CAPIGenDlg::Show2E() 

	Purpose:	Sets up two edit controls

	Arguments:	csaLabels -- the strings that are used to label each control.

	Note:		

*****************************************************************************/
void CAPIGenDlg::Show2E( CStringArray* pcsaLabels  )
{
	int topGroupStart=PARAM_TOP;
	int nGroupBoxHeight = 0;
	nGroupBoxHeight	= 185;
	m_groupAddParameterGroup.ShowWindow( SW_SHOW  );
	m_groupAddParameterGroup.MoveWindow( PARAM_LEFT_SIDE-15, topGroupStart-25, STANDARD_WIDTH+30, nGroupBoxHeight );

	m_staticString1.SetWindowText( pcsaLabels->GetAt( 0 ) );
	m_staticString1.ShowWindow( SW_SHOW );
	m_staticString1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 22 );
	m_EditArgument1.ShowWindow( SW_SHOW );
	m_EditArgument1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
	m_staticString2.SetWindowText( pcsaLabels->GetAt( 1 ) );
	m_staticString2.ShowWindow( SW_SHOW );
	m_staticString2.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 22 );
	m_EditArgument3.ShowWindow( SW_SHOW );
	m_EditArgument3.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );
}



/***************************************************************************DC

	Operation:	CAPIGenDlg::Show2E1C() 

	Purpose:	Sets up two edit controls + one checkbox.

	Arguments:	csaLabels -- the strings that are used to label each control.

	Note:		

*****************************************************************************/
void CAPIGenDlg::Show2E1C( CStringArray* pcsaLabels  )
{
	int topGroupStart=PARAM_TOP;
	int nGroupBoxHeight = 0;
	nGroupBoxHeight	= 185;
	m_groupAddParameterGroup.ShowWindow( SW_SHOW  );
	m_groupAddParameterGroup.MoveWindow( PARAM_LEFT_SIDE-15, topGroupStart-25, STANDARD_WIDTH+30, nGroupBoxHeight );

	m_staticString1.SetWindowText( pcsaLabels->GetAt( 0 ) );
	m_staticString1.ShowWindow( SW_SHOW );
	m_staticString1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 22 );
	m_EditArgument1.ShowWindow( SW_SHOW );
	m_EditArgument1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
	m_staticString2.SetWindowText( pcsaLabels->GetAt( 1 ) );
	m_staticString2.ShowWindow( SW_SHOW );
	m_staticString2.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 22 );
	m_EditArgument3.ShowWindow( SW_SHOW );
	m_EditArgument3.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
	checkParam1.SetWindowText( pcsaLabels->GetAt( 2 ) );
	checkParam1.ShowWindow( SW_SHOW );
	checkParam1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 22 );
}



/***************************************************************************DC

	Operation:	CAPIGenDlg::Show2E3C() 

	Purpose:	Sets up two edit controls + three checkboxes

	Arguments:	csaLabels -- the strings that are used to label each control.

	Note:		

*****************************************************************************/
void CAPIGenDlg::Show2E3C( CStringArray* pcsaLabels  )
{
	int topGroupStart=PARAM_TOP;
	int nGroupBoxHeight = 0;
	nGroupBoxHeight	= 215;

	m_groupAddParameterGroup.ShowWindow( SW_SHOW  );
	m_groupAddParameterGroup.MoveWindow( PARAM_LEFT_SIDE-15, topGroupStart-25, STANDARD_WIDTH+30, nGroupBoxHeight );

	m_staticString1.SetWindowText( pcsaLabels->GetAt( 0 ) );
	m_staticString1.ShowWindow( SW_SHOW );
	m_staticString1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 22 );
	m_EditArgument1.ShowWindow( SW_SHOW );
	m_EditArgument1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
	m_staticString2.SetWindowText( pcsaLabels->GetAt( 1 ) );
	m_staticString2.ShowWindow( SW_SHOW );
	m_staticString2.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 22 );
	m_EditArgument3.ShowWindow( SW_SHOW );
	m_EditArgument3.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP + 10;
	checkParam1.SetWindowText( pcsaLabels->GetAt( 2 ) );
	checkParam1.ShowWindow( SW_SHOW );
	checkParam1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP - 15;
	checkParam2.SetWindowText( pcsaLabels->GetAt( 3 ) );
	checkParam2.ShowWindow( SW_SHOW );
	checkParam2.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP - 15;
	checkParam3.SetWindowText( pcsaLabels->GetAt( 4 ) );
	checkParam3.ShowWindow( SW_SHOW );
	checkParam3.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 22 );


}


/***************************************************************************DC

	Operation:	CAPIGenDlg::Show2E4C1E() 

	Purpose:	Sets up two edit controls + four checkboxes + one edit control

	Arguments:	csaLabels -- the strings that are used to label each control.

	Note:		

*****************************************************************************/
void CAPIGenDlg::Show2E4C1E( CStringArray* pcsaLabels  )
{
	int topGroupStart=PARAM_TOP;
	int nGroupBoxHeight = 0;
	nGroupBoxHeight	= 335;

	m_groupAddParameterGroup.ShowWindow( SW_SHOW  );
	m_groupAddParameterGroup.MoveWindow( PARAM_LEFT_SIDE-15, topGroupStart-25, STANDARD_WIDTH+30, nGroupBoxHeight );

	m_staticString1.SetWindowText( pcsaLabels->GetAt( 0 ) );
	m_staticString1.ShowWindow( SW_SHOW );
	m_staticString1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
	m_EditArgument1.ShowWindow( SW_SHOW );
	m_EditArgument1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
	m_staticString2.SetWindowText( pcsaLabels->GetAt( 1 ) );
	m_staticString2.ShowWindow( SW_SHOW );
	m_staticString2.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
	m_EditArgument3.ShowWindow( SW_SHOW );
	m_EditArgument3.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP + 10;
	checkParam1.SetWindowText( pcsaLabels->GetAt( 2 ) );
	checkParam1.ShowWindow( SW_SHOW );
	checkParam1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP - 15;
	checkParam2.SetWindowText( pcsaLabels->GetAt( 3 ) );
	checkParam2.ShowWindow( SW_SHOW );
	checkParam2.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP - 15;
	checkParam3.SetWindowText( pcsaLabels->GetAt( 4 ) );
	checkParam3.ShowWindow( SW_SHOW );
	checkParam3.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP - 15;
	checkParam4.SetWindowText( pcsaLabels->GetAt( 5 ) );
	checkParam4.ShowWindow( SW_SHOW );
	checkParam4.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP - 10;
	m_staticString3.SetWindowText( pcsaLabels->GetAt( 6 ) );
	m_staticString3.ShowWindow( SW_SHOW );
	m_staticString3.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
	m_EditArgument4.ShowWindow( SW_SHOW );
	m_EditArgument4.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

}


/***************************************************************************DC

	Operation:	CAPIGenDlg::Show2E1C1E() 

	Purpose:	Sets up two edit controls + one checkbox + one edit control

	Arguments:	csaLabels -- the strings that are used to label each control.

	Note:		

*****************************************************************************/
void CAPIGenDlg::Show2E1C1E( CStringArray* pcsaLabels  )
{
	int topGroupStart=PARAM_TOP;
	int nGroupBoxHeight = 0;
	nGroupBoxHeight	= 235;

	m_groupAddParameterGroup.ShowWindow( SW_SHOW  );
	m_groupAddParameterGroup.MoveWindow( PARAM_LEFT_SIDE-15, topGroupStart-25, STANDARD_WIDTH+30, nGroupBoxHeight );

	m_staticString1.SetWindowText( pcsaLabels->GetAt( 0 ) );
	m_staticString1.ShowWindow( SW_SHOW );
	m_staticString1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 22 );
	m_EditArgument1.ShowWindow( SW_SHOW );
	m_EditArgument1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
	m_staticString2.SetWindowText( pcsaLabels->GetAt( 1 ) );
	m_staticString2.ShowWindow( SW_SHOW );
	m_staticString2.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 22 );
	m_EditArgument3.ShowWindow( SW_SHOW );
	m_EditArgument3.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP + 10;
	checkParam1.SetWindowText( pcsaLabels->GetAt( 2 ) );
	checkParam1.ShowWindow( SW_SHOW );
	checkParam1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP - 15;
	m_staticString3.SetWindowText( pcsaLabels->GetAt( 3 ) );
	m_staticString3.ShowWindow( SW_SHOW );
	m_staticString3.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 22 );
	m_EditArgument4.ShowWindow( SW_SHOW );
	m_EditArgument4.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

}


/***************************************************************************DC

	Operation:	CAPIGenDlg::Show2E1C1E1C2E() 

	Purpose:	Sets up two edit controls + one checkbox + one edit control +
				one checkbox + two edit controls

	Arguments:	csaLabels -- the strings that are used to label each control.

	Note:		

*****************************************************************************/
void CAPIGenDlg::Show2E1C1E1C2E( CStringArray* pcsaLabels  )
{
	int topGroupStart=PARAM_TOP;
	int nGroupBoxHeight = 0;
	nGroupBoxHeight	= 335;

	m_groupAddParameterGroup.ShowWindow( SW_SHOW  );
	m_groupAddParameterGroup.MoveWindow( PARAM_LEFT_SIDE-15, topGroupStart-25, STANDARD_WIDTH+30, nGroupBoxHeight );

	m_staticString1.SetWindowText( pcsaLabels->GetAt( 0 ) );
	m_staticString1.ShowWindow( SW_SHOW );
	m_staticString1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
	m_EditArgument1.ShowWindow( SW_SHOW );
	m_EditArgument1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
	m_staticString2.SetWindowText( pcsaLabels->GetAt( 1 ) );
	m_staticString2.ShowWindow( SW_SHOW );
	m_staticString2.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
	m_EditArgument3.ShowWindow( SW_SHOW );
	m_EditArgument3.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP + 5;
	checkParam1.SetWindowText( pcsaLabels->GetAt( 2 ) );
	checkParam1.ShowWindow( SW_SHOW );
	checkParam1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP - 15;
	m_staticString3.SetWindowText( pcsaLabels->GetAt( 3 ) );
	m_staticString3.ShowWindow( SW_SHOW );
	m_staticString3.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
	m_EditArgument4.ShowWindow( SW_SHOW );
	m_EditArgument4.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP + 5;
	checkParam2.SetWindowText( pcsaLabels->GetAt( 4 ) );
	checkParam2.ShowWindow( SW_SHOW );
	checkParam2.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP - 15;
	m_staticString4.SetWindowText( pcsaLabels->GetAt( 5 ) );
	m_staticString4.ShowWindow( SW_SHOW );
	m_staticString4.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
	m_EditArgument5.ShowWindow( SW_SHOW );
	m_EditArgument5.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
	m_staticString5.SetWindowText( pcsaLabels->GetAt( 6 ) );
	m_staticString5.ShowWindow( SW_SHOW );
	m_staticString5.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
	m_EditArgument6.ShowWindow( SW_SHOW );
	m_EditArgument6.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

}





/***************************************************************************DC

	Operation:	CAPIGenDlg::Show1L() 

	Purpose:	Sets up one list control.

	Arguments:	csaLabels -- the strings that are used to label each control.

	Note:		

*****************************************************************************/
void CAPIGenDlg::Show1L( CStringArray* pcsaLabels, CStringArray* csaListEntries  )
{
	int topGroupStart=PARAM_TOP;
	int nGroupBoxHeight = 0;

	nGroupBoxHeight	= 145;
	m_groupAddParameterGroup.ShowWindow( SW_SHOW  );
	m_groupAddParameterGroup.MoveWindow( PARAM_LEFT_SIDE-15, topGroupStart-25, STANDARD_WIDTH+30, nGroupBoxHeight );

	m_staticString1.SetWindowText( pcsaLabels->GetAt( 0 ) );
	m_staticString1.ShowWindow( SW_SHOW );
	m_staticString1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 22 );

	listParams1.ShowWindow( SW_SHOW  );
	listParams1.ResetContent();
	for ( int i=0; i<csaListEntries->GetCount(); i++)
	{
		listParams1.AddString( csaListEntries->GetAt(i) );
	}


	listParams1.SetCurSel(0);
	listParams1.ShowWindow( SW_SHOW  );
	listParams1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 80 );
}


/***************************************************************************DC

	Operation:	CAPIGenDlg::Show1C() 

	Purpose:	Sets up one checkbox.

	Arguments:	csaLabels -- the strings that are used to label each control.

	Note:		

*****************************************************************************/
void CAPIGenDlg::Show1C( CStringArray* pcsaLabels  )
{
	int topGroupStart=PARAM_TOP;
	int nGroupBoxHeight = 0;
	nGroupBoxHeight	= 55;

	m_groupAddParameterGroup.ShowWindow( SW_SHOW  );
	m_groupAddParameterGroup.MoveWindow( PARAM_LEFT_SIDE-15, topGroupStart-25, STANDARD_WIDTH+30, nGroupBoxHeight );

	checkParam1.SetWindowText( pcsaLabels->GetAt( 0 ) );
	checkParam1.ShowWindow( SW_SHOW );
	checkParam1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 22 );
}



/***************************************************************************DC

	Operation:	CAPIGenDlg::Show1C1E() 

	Purpose:	Sets up one checkbox + one edit control.

	Arguments:	csaLabels -- the strings that are used to label each control.

	Note:		

*****************************************************************************/
void CAPIGenDlg::Show1C1E( CStringArray* pcsaLabels  )
{
	int topGroupStart=PARAM_TOP;
	int nGroupBoxHeight = 0;
	nGroupBoxHeight	= 135;

	m_groupAddParameterGroup.ShowWindow( SW_SHOW  );
	m_groupAddParameterGroup.MoveWindow( PARAM_LEFT_SIDE-15, topGroupStart-25, STANDARD_WIDTH+30, nGroupBoxHeight );

	checkParam1.SetWindowText( pcsaLabels->GetAt( 0 ) );
	checkParam1.ShowWindow( SW_SHOW );
	checkParam1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP - 20;
	m_staticString1.SetWindowText( pcsaLabels->GetAt( 1 ) );
	m_staticString1.ShowWindow( SW_SHOW );
	m_staticString1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 22 );
	m_EditArgument1.ShowWindow( SW_SHOW );
	m_EditArgument1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

}


/***************************************************************************DC

	Operation:	CAPIGenDlg::Show2C() 

	Purpose:	Sets up two checkboxes.

	Arguments:	csaLabels -- the strings that are used to label each control.

	Note:		

*****************************************************************************/
void CAPIGenDlg::Show2C( CStringArray* pcsaLabels  )
{
	int topGroupStart=PARAM_TOP;
	int nGroupBoxHeight = 0;
	nGroupBoxHeight	= 85;

	m_groupAddParameterGroup.ShowWindow( SW_SHOW  );
	m_groupAddParameterGroup.MoveWindow( PARAM_LEFT_SIDE-15, topGroupStart-25, STANDARD_WIDTH+30, nGroupBoxHeight );

	checkParam1.SetWindowText( pcsaLabels->GetAt( 0 ) );
	checkParam1.ShowWindow( SW_SHOW );
	checkParam1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP - 20;
	checkParam2.SetWindowText( pcsaLabels->GetAt( 1 ) );
	checkParam2.ShowWindow( SW_SHOW );
	checkParam2.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 22 );

}



/***************************************************************************DC

	Operation:	CAPIGenDlg::Show3C() 

	Purpose:	Sets up three checkboxes.

	Arguments:	csaLabels -- the strings that are used to label each control.

	Note:		

*****************************************************************************/
void CAPIGenDlg::Show3C( CStringArray* pcsaLabels  )
{
	int topGroupStart=PARAM_TOP;
	int nGroupBoxHeight = 0;
	nGroupBoxHeight	= 135;

	m_groupAddParameterGroup.ShowWindow( SW_SHOW  );
	m_groupAddParameterGroup.MoveWindow( PARAM_LEFT_SIDE-15, topGroupStart-25, STANDARD_WIDTH+30, nGroupBoxHeight );

	checkParam1.SetWindowText( pcsaLabels->GetAt( 0 ) );
	checkParam1.ShowWindow( SW_SHOW );
	checkParam1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP - 20;
	checkParam2.SetWindowText( pcsaLabels->GetAt( 1 ) );
	checkParam2.ShowWindow( SW_SHOW );
	checkParam2.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP - 20;
	checkParam3.SetWindowText( pcsaLabels->GetAt( 2 ) );
	checkParam3.ShowWindow( SW_SHOW );
	checkParam3.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 22 );

}



/***************************************************************************DC

	Operation:	CAPIGenDlg::Show2E1L1ML2E() 

	Purpose:	Sets up two edit controls + one list control + 
				one mulit-list control + one edit control

	Arguments:	csaLabels -- the strings that are used to label each control.

	Note:		

*****************************************************************************/
void CAPIGenDlg::Show2E1L1ML2E(	CStringArray* pcsaLabels, 
									CStringArray* csaListEntries, 
									CStringArray* csaList2Entries )
{
	int topGroupStart=PARAM_TOP;
	int nGroupBoxHeight = 0;
	nGroupBoxHeight	= 365;

	m_groupAddParameterGroup.ShowWindow( SW_SHOW  );
	m_groupAddParameterGroup.MoveWindow( PARAM_LEFT_SIDE-15, topGroupStart-25, STANDARD_WIDTH+30, nGroupBoxHeight );

	m_staticString1.SetWindowText( pcsaLabels->GetAt( 0 ) );
	m_staticString1.ShowWindow( SW_SHOW );
	m_staticString1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
	m_EditArgument1.ShowWindow( SW_SHOW );
	m_EditArgument1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
	m_staticString2.SetWindowText( pcsaLabels->GetAt( 1 ) );
	m_staticString2.ShowWindow( SW_SHOW );
	m_staticString2.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
	m_EditArgument3.ShowWindow( SW_SHOW );
	m_EditArgument3.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
	m_staticString3.SetWindowText( pcsaLabels->GetAt( 2 ) );
	m_staticString3.ShowWindow( SW_SHOW );
	m_staticString3.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );

	listParams1.ShowWindow( SW_SHOW  );
	listParams1.ResetContent();
	for ( int i=0; i<csaListEntries->GetCount(); i++)
	{
		listParams1.AddString( csaListEntries->GetAt(i) );
	}
	listParams1.SetCurSel(0);
	listParams1.ShowWindow( SW_SHOW  );
	listParams1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 50 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP + 30;
	m_staticString4.SetWindowText( pcsaLabels->GetAt( 3 ) );
	m_staticString4.ShowWindow( SW_SHOW );
	m_staticString4.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );

	listMultiParams1.ResetContent();
	for ( int i=0; i<csaList2Entries->GetCount(); i++)
	{
		listMultiParams1.AddString( csaList2Entries->GetAt(i) );
	}

	listMultiParams1.SetSel(0,TRUE);
	listMultiParams1.ShowWindow( SW_SHOW  );
	listMultiParams1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 50 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP + 35;
	m_staticString5.SetWindowText( pcsaLabels->GetAt( 4 ) );
	m_staticString5.ShowWindow( SW_SHOW );
	m_staticString5.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
	m_EditArgument4.ShowWindow( SW_SHOW );
	m_EditArgument4.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
	m_staticString6.SetWindowText( pcsaLabels->GetAt( 5 ) );
	m_staticString6.ShowWindow( SW_SHOW );
	m_staticString6.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
	m_EditArgument5.ShowWindow( SW_SHOW );
	m_EditArgument5.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

}



/***************************************************************************DC

	Operation:	CAPIGenDlg::Show1C1E1L1ML1C1E() 

	Purpose:	Sets up one checkbox + one edit control + one list control + 
				one mulit-list control + one checkbox + one edit control

	Arguments:	csaLabels -- the strings that are used to label each control.

	Note:		

*****************************************************************************/
void CAPIGenDlg::Show1C1E1L1ML1C1E(	CStringArray* pcsaLabels, 
									CStringArray* csaListEntries, 
									CStringArray* csaList2Entries )
{
	int topGroupStart=PARAM_TOP;
	int nGroupBoxHeight = 0;
	nGroupBoxHeight	= 365;

	m_groupAddParameterGroup.ShowWindow( SW_SHOW  );
	m_groupAddParameterGroup.MoveWindow( PARAM_LEFT_SIDE-15, topGroupStart-25, STANDARD_WIDTH+30, nGroupBoxHeight );

	//topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP + 10;
	checkParam1.SetWindowText( pcsaLabels->GetAt( 0 ) );
	checkParam1.ShowWindow( SW_SHOW );
	checkParam1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP - 15;
	m_staticString1.SetWindowText( pcsaLabels->GetAt( 1 ) );
	m_staticString1.ShowWindow( SW_SHOW );
	m_staticString1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
	m_EditArgument1.ShowWindow( SW_SHOW );
	m_EditArgument1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
	m_staticString2.SetWindowText( pcsaLabels->GetAt( 2 ) );
	m_staticString2.ShowWindow( SW_SHOW );
	m_staticString2.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );

	listParams1.ShowWindow( SW_SHOW  );
	listParams1.ResetContent();
	for ( int i=0; i<csaListEntries->GetCount(); i++)
	{
		listParams1.AddString( csaListEntries->GetAt(i) );
	}
	listParams1.SetCurSel(0);
	listParams1.ShowWindow( SW_SHOW  );
	listParams1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 70 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP + 50;
	m_staticString3.SetWindowText( pcsaLabels->GetAt( 3 ) );
	m_staticString3.ShowWindow( SW_SHOW );
	m_staticString3.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );

	listMultiParams1.ResetContent();
	for ( int i=0; i<csaList2Entries->GetCount(); i++)
	{
		listMultiParams1.AddString( csaList2Entries->GetAt(i) );
	}

	listMultiParams1.SetSel(0,TRUE);
	listMultiParams1.ShowWindow( SW_SHOW  );
	listMultiParams1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 50 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP + 30;
	checkParam2.SetWindowText( pcsaLabels->GetAt( 4 ) );
	checkParam2.ShowWindow( SW_SHOW );
	checkParam2.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP - 15;
	m_staticString4.SetWindowText( pcsaLabels->GetAt( 5 ) );
	m_staticString4.ShowWindow( SW_SHOW );
	m_staticString4.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
	m_EditArgument3.ShowWindow( SW_SHOW );
	m_EditArgument3.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

}




/***************************************************************************DC

	Operation:	CAPIGenDlg::Show2E1L() 

	Purpose:	Sets up two edit controls and one list control.

	Arguments:	csaLabels		-- the strings that are used to label each control.
				csaListEntries	-- the strings that go in the listbox

	Note:		

*****************************************************************************/
void CAPIGenDlg::Show2E1L( CStringArray* pcsaLabels, CStringArray* csaListEntries  )
{
	int topGroupStart=PARAM_TOP;
	int nGroupBoxHeight = 0;
	nGroupBoxHeight	= 185;

	m_groupAddParameterGroup.ShowWindow( SW_SHOW  );
	m_groupAddParameterGroup.MoveWindow( PARAM_LEFT_SIDE-15, topGroupStart-25, STANDARD_WIDTH+30, nGroupBoxHeight );

	m_staticString1.SetWindowText( pcsaLabels->GetAt( 0 ) );
	m_staticString1.ShowWindow( SW_SHOW );
	m_staticString1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 22 );
	m_EditArgument1.ShowWindow( SW_SHOW );
	m_EditArgument1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
	m_staticString2.SetWindowText( pcsaLabels->GetAt( 1 ) );
	m_staticString2.ShowWindow( SW_SHOW );
	m_staticString2.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 22 );
	m_EditArgument3.ShowWindow( SW_SHOW );
	m_EditArgument3.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
	m_staticString3.SetWindowText( pcsaLabels->GetAt( 2 ) );
	m_staticString3.ShowWindow( SW_SHOW );
	m_staticString3.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 22 );

	listParams1.ShowWindow( SW_SHOW  );
	listParams1.ResetContent();
	for ( int i=0; i<csaListEntries->GetCount(); i++)
	{
		listParams1.AddString( csaListEntries->GetAt(i) );
	}
	listParams1.SetCurSel(0);
	listParams1.ShowWindow( SW_SHOW  );
	listParams1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 40 );
}



/***************************************************************************DC

	Operation:	CAPIGenDlg::Show2E1L2E() 

	Purpose:	Sets up two edit controls + one listbox + two edit controls.

	Arguments:	csaLabels		-- the strings that are used to label each control.
				csaListEntries	-- the strings that go in the listbox

	Note:		

*****************************************************************************/
void CAPIGenDlg::Show2E1L2E( CStringArray* pcsaLabels, CStringArray* csaListEntries  )
{
	int topGroupStart=PARAM_TOP;
	int nGroupBoxHeight = 0;
	nGroupBoxHeight	= 285;

	m_groupAddParameterGroup.ShowWindow( SW_SHOW  );
	m_groupAddParameterGroup.MoveWindow( PARAM_LEFT_SIDE-15, topGroupStart-25, STANDARD_WIDTH+30, nGroupBoxHeight );

	m_staticString1.SetWindowText( pcsaLabels->GetAt( 0 ) );
	m_staticString1.ShowWindow( SW_SHOW );
	m_staticString1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
	m_EditArgument1.ShowWindow( SW_SHOW );
	m_EditArgument1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
	m_staticString2.SetWindowText( pcsaLabels->GetAt( 1 ) );
	m_staticString2.ShowWindow( SW_SHOW );
	m_staticString2.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
	m_EditArgument3.ShowWindow( SW_SHOW );
	m_EditArgument3.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
	m_staticString3.SetWindowText( pcsaLabels->GetAt( 2 ) );
	m_staticString3.ShowWindow( SW_SHOW );
	m_staticString3.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 22 );

	listParams1.ShowWindow( SW_SHOW  );
	listParams1.ResetContent();
	for ( int i=0; i<csaListEntries->GetCount(); i++)
	{
		listParams1.AddString( csaListEntries->GetAt(i) );
	}
	listParams1.SetCurSel(0);
	listParams1.ShowWindow( SW_SHOW  );
	listParams1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 40 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP + 20;
	m_staticString4.SetWindowText( pcsaLabels->GetAt( 3 ) );
	m_staticString4.ShowWindow( SW_SHOW );
	m_staticString4.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
	m_EditArgument4.ShowWindow( SW_SHOW );
	m_EditArgument4.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
	m_staticString5.SetWindowText( pcsaLabels->GetAt( 4 ) );
	m_staticString5.ShowWindow( SW_SHOW );
	m_staticString5.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
	m_EditArgument5.ShowWindow( SW_SHOW );
	m_EditArgument5.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );


}


/***************************************************************************DC

	Operation:	CAPIGenDlg::Show2E1L3E() 

	Purpose:	Sets up two edit controls + one listbox + two edit controls.

	Arguments:	csaLabels		-- the strings that are used to label each control.
				csaListEntries	-- the strings that go in the listbox

	Note:		

*****************************************************************************/
void CAPIGenDlg::Show2E1L3E( CStringArray* pcsaLabels, CStringArray* csaListEntries  )
{
	int topGroupStart=PARAM_TOP;
	int nGroupBoxHeight = 0;
	nGroupBoxHeight	= 325;

	m_groupAddParameterGroup.ShowWindow( SW_SHOW  );
	m_groupAddParameterGroup.MoveWindow( PARAM_LEFT_SIDE-15, topGroupStart-25, STANDARD_WIDTH+30, nGroupBoxHeight );

	m_staticString1.SetWindowText( pcsaLabels->GetAt( 0 ) );
	m_staticString1.ShowWindow( SW_SHOW );
	m_staticString1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
	m_EditArgument1.ShowWindow( SW_SHOW );
	m_EditArgument1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
	m_staticString2.SetWindowText( pcsaLabels->GetAt( 1 ) );
	m_staticString2.ShowWindow( SW_SHOW );
	m_staticString2.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
	m_EditArgument3.ShowWindow( SW_SHOW );
	m_EditArgument3.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
	m_staticString3.SetWindowText( pcsaLabels->GetAt( 2 ) );
	m_staticString3.ShowWindow( SW_SHOW );
	m_staticString3.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 22 );

	listParams1.ShowWindow( SW_SHOW  );
	listParams1.ResetContent();
	for ( int i=0; i<csaListEntries->GetCount(); i++)
	{
		listParams1.AddString( csaListEntries->GetAt(i) );
	}
	listParams1.SetCurSel(0);
	listParams1.ShowWindow( SW_SHOW  );
	listParams1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 40 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP + 20;
	m_staticString4.SetWindowText( pcsaLabels->GetAt( 3 ) );
	m_staticString4.ShowWindow( SW_SHOW );
	m_staticString4.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
	m_EditArgument4.ShowWindow( SW_SHOW );
	m_EditArgument4.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
	m_staticString5.SetWindowText( pcsaLabels->GetAt( 4 ) );
	m_staticString5.ShowWindow( SW_SHOW );
	m_staticString5.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
	m_EditArgument5.ShowWindow( SW_SHOW );
	m_EditArgument5.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
	m_staticString6.SetWindowText( pcsaLabels->GetAt( 5 ) );
	m_staticString6.ShowWindow( SW_SHOW );
	m_staticString6.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
	m_EditArgument6.ShowWindow( SW_SHOW );
	m_EditArgument6.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );


}



/***************************************************************************DC

	Operation:	CAPIGenDlg::Show2E1L4E() 

	Purpose:	Sets up two edit controls + one listbox + four edit controls.

	Arguments:	csaLabels		-- the strings that are used to label each control.
				csaListEntries	-- the strings that go in the listbox

	Note:		

*****************************************************************************/
void CAPIGenDlg::Show2E1L4E( CStringArray* pcsaLabels, CStringArray* csaListEntries  )
{
	int topGroupStart=PARAM_TOP;
	int nGroupBoxHeight = 0;
	nGroupBoxHeight	= 365;

	m_groupAddParameterGroup.ShowWindow( SW_SHOW  );
	m_groupAddParameterGroup.MoveWindow( PARAM_LEFT_SIDE-15, topGroupStart-25, STANDARD_WIDTH+30, nGroupBoxHeight );

	m_staticString1.SetWindowText( pcsaLabels->GetAt( 0 ) );
	m_staticString1.ShowWindow( SW_SHOW );
	m_staticString1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
	m_EditArgument1.ShowWindow( SW_SHOW );
	m_EditArgument1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
	m_staticString2.SetWindowText( pcsaLabels->GetAt( 1 ) );
	m_staticString2.ShowWindow( SW_SHOW );
	m_staticString2.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
	m_EditArgument3.ShowWindow( SW_SHOW );
	m_EditArgument3.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
	m_staticString3.SetWindowText( pcsaLabels->GetAt( 2 ) );
	m_staticString3.ShowWindow( SW_SHOW );
	m_staticString3.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 22 );

	listParams1.ShowWindow( SW_SHOW  );
	listParams1.ResetContent();
	for ( int i=0; i<csaListEntries->GetCount(); i++)
	{
		listParams1.AddString( csaListEntries->GetAt(i) );
	}
	listParams1.SetCurSel(0);
	listParams1.ShowWindow( SW_SHOW  );
	listParams1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 40 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP + 20;
	m_staticString4.SetWindowText( pcsaLabels->GetAt( 3 ) );
	m_staticString4.ShowWindow( SW_SHOW );
	m_staticString4.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
	m_EditArgument4.ShowWindow( SW_SHOW );
	m_EditArgument4.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
	m_staticString5.SetWindowText( pcsaLabels->GetAt( 4 ) );
	m_staticString5.ShowWindow( SW_SHOW );
	m_staticString5.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
	m_EditArgument5.ShowWindow( SW_SHOW );
	m_EditArgument5.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
	m_staticString6.SetWindowText( pcsaLabels->GetAt( 5 ) );
	m_staticString6.ShowWindow( SW_SHOW );
	m_staticString6.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
	m_EditArgument6.ShowWindow( SW_SHOW );
	m_EditArgument6.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
	m_staticString7.SetWindowText( pcsaLabels->GetAt( 6 ) );
	m_staticString7.ShowWindow( SW_SHOW );
	m_staticString7.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
	m_EditArgument7.ShowWindow( SW_SHOW );
	m_EditArgument7.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );


}




/***************************************************************************DC

	Operation:	CAPIGenDlg::Show2E1L5E() 

	Purpose:	Sets up two edit controls + one listbox + five edit controls.

	Arguments:	csaLabels		-- the strings that are used to label each control.
				csaListEntries	-- the strings that go in the listbox

	Note:		

*****************************************************************************/
void CAPIGenDlg::Show2E1L5E( CStringArray* pcsaLabels, CStringArray* csaListEntries  )
{
	int topGroupStart=PARAM_TOP;
	int nGroupBoxHeight = 0;
	nGroupBoxHeight	= 415;

	m_groupAddParameterGroup.ShowWindow( SW_SHOW  );
	m_groupAddParameterGroup.MoveWindow( PARAM_LEFT_SIDE-15, topGroupStart-25, STANDARD_WIDTH+30, nGroupBoxHeight );

	m_staticString1.SetWindowText( pcsaLabels->GetAt( 0 ) );
	m_staticString1.ShowWindow( SW_SHOW );
	m_staticString1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
	m_EditArgument1.ShowWindow( SW_SHOW );
	m_EditArgument1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
	m_staticString2.SetWindowText( pcsaLabels->GetAt( 1 ) );
	m_staticString2.ShowWindow( SW_SHOW );
	m_staticString2.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
	m_EditArgument3.ShowWindow( SW_SHOW );
	m_EditArgument3.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
	m_staticString3.SetWindowText( pcsaLabels->GetAt( 2 ) );
	m_staticString3.ShowWindow( SW_SHOW );
	m_staticString3.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 22 );

	listParams1.ShowWindow( SW_SHOW  );
	listParams1.ResetContent();
	for ( int i=0; i<csaListEntries->GetCount(); i++)
	{
		listParams1.AddString( csaListEntries->GetAt(i) );
	}
	listParams1.SetCurSel(0);
	listParams1.ShowWindow( SW_SHOW  );
	listParams1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 40 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP + 20;
	m_staticString4.SetWindowText( pcsaLabels->GetAt( 3 ) );
	m_staticString4.ShowWindow( SW_SHOW );
	m_staticString4.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
	m_EditArgument4.ShowWindow( SW_SHOW );
	m_EditArgument4.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
	m_staticString5.SetWindowText( pcsaLabels->GetAt( 4 ) );
	m_staticString5.ShowWindow( SW_SHOW );
	m_staticString5.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
	m_EditArgument5.ShowWindow( SW_SHOW );
	m_EditArgument5.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
	m_staticString6.SetWindowText( pcsaLabels->GetAt( 5 ) );
	m_staticString6.ShowWindow( SW_SHOW );
	m_staticString6.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
	m_EditArgument6.ShowWindow( SW_SHOW );
	m_EditArgument6.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
	m_staticString7.SetWindowText( pcsaLabels->GetAt( 6 ) );
	m_staticString7.ShowWindow( SW_SHOW );
	m_staticString7.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
	m_EditArgument7.ShowWindow( SW_SHOW );
	m_EditArgument7.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
	m_staticString8.SetWindowText( pcsaLabels->GetAt( 7 ) );
	m_staticString8.ShowWindow( SW_SHOW );
	m_staticString8.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
	m_EditArgument8.ShowWindow( SW_SHOW );
	m_EditArgument8.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

}



/***************************************************************************DC

	Operation:	CAPIGenDlg::Show1E1L3E1L() 

	Purpose:	Sets up one edit control + one list control + three edit 
				controls + one list control.

	Arguments:	csaLabels		-- the strings that are used to label each control.
				csaListEntries	-- the strings that go in the first listbox
				csaList2Entries -- the strings that go in the second listbox

	Note:		

*****************************************************************************/
void CAPIGenDlg::Show1E1L3E1L(	CStringArray* pcsaLabels, 
								CStringArray* csaListEntries, 
								CStringArray* csaList2Entries )
{
	int i=0;
	int topGroupStart=PARAM_TOP;
	int nGroupBoxHeight = 0;
	nGroupBoxHeight	= 385;

	m_groupAddParameterGroup.ShowWindow( SW_SHOW  );
	m_groupAddParameterGroup.MoveWindow( PARAM_LEFT_SIDE-15, topGroupStart-25, STANDARD_WIDTH+30, nGroupBoxHeight );

	m_staticString1.SetWindowText( pcsaLabels->GetAt( 0 ) );
	m_staticString1.ShowWindow( SW_SHOW );
	m_staticString1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
	m_EditArgument1.ShowWindow( SW_SHOW );
	m_EditArgument1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
	m_staticString2.SetWindowText( pcsaLabels->GetAt( 1 ) );
	m_staticString2.ShowWindow( SW_SHOW );
	m_staticString2.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );

	listParams1.ShowWindow( SW_SHOW  );
	listParams1.ResetContent();
	for ( i=0; i<csaListEntries->GetCount(); i++)
	{
		listParams1.AddString( csaListEntries->GetAt(i) );
	}
	listParams1.SetCurSel(0);
	listParams1.ShowWindow( SW_SHOW  );
	listParams1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 70 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP + 50;
	m_staticString3.SetWindowText( pcsaLabels->GetAt( 2 ) );
	m_staticString3.ShowWindow( SW_SHOW );
	m_staticString3.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
	m_EditArgument3.ShowWindow( SW_SHOW );
	m_EditArgument3.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
	m_staticString4.SetWindowText( pcsaLabels->GetAt( 3 ) );
	m_staticString4.ShowWindow( SW_SHOW );
	m_staticString4.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
	m_EditArgument4.ShowWindow( SW_SHOW );
	m_EditArgument4.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
	m_staticString5.SetWindowText( pcsaLabels->GetAt( 4 ) );
	m_staticString5.ShowWindow( SW_SHOW );
	m_staticString5.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
	m_EditArgument5.ShowWindow( SW_SHOW );
	m_EditArgument5.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
	m_staticString6.SetWindowText( pcsaLabels->GetAt( 5 ) );
	m_staticString6.ShowWindow( SW_SHOW );
	m_staticString6.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );

	listParams2.ShowWindow( SW_SHOW  );
	listParams2.ResetContent();
	for ( i=0; i<csaList2Entries->GetCount(); i++)
	{
		listParams2.AddString( csaList2Entries->GetAt(i) );
	}
	listParams2.SetCurSel(0);
	listParams2.ShowWindow( SW_SHOW  );
	listParams2.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 60 );
}



/***************************************************************************DC

	Operation:	CAPIGenDlg::Show1E1L4E1L() 

	Purpose:	Sets up one edit control + one list control + four edit 
				controls + one list control.

	Arguments:	csaLabels		-- the strings that are used to label each control.
				csaListEntries	-- the strings that go in the first listbox
				csaList2Entries -- the strings that go in the second listbox

	Note:		

*****************************************************************************/
void CAPIGenDlg::Show1E1L4E1L(	CStringArray* pcsaLabels, 
								CStringArray* csaListEntries, 
								CStringArray* csaList2Entries )
{
	int i=0;
	int topGroupStart=PARAM_TOP;
	int nGroupBoxHeight = 0;
	nGroupBoxHeight	= 385;

	m_groupAddParameterGroup.ShowWindow( SW_SHOW  );
	m_groupAddParameterGroup.MoveWindow( PARAM_LEFT_SIDE-15, topGroupStart-25, STANDARD_WIDTH+30, nGroupBoxHeight );

	m_staticString1.SetWindowText( pcsaLabels->GetAt( 0 ) );
	m_staticString1.ShowWindow( SW_SHOW );
	m_staticString1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
	m_EditArgument1.ShowWindow( SW_SHOW );
	m_EditArgument1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
	m_staticString2.SetWindowText( pcsaLabels->GetAt( 1 ) );
	m_staticString2.ShowWindow( SW_SHOW );
	m_staticString2.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );

	listParams1.ShowWindow( SW_SHOW  );
	listParams1.ResetContent();
	for ( i=0; i<csaListEntries->GetCount(); i++)
	{
		listParams1.AddString( csaListEntries->GetAt(i) );
	}
	listParams1.SetCurSel(0);
	listParams1.ShowWindow( SW_SHOW  );
	listParams1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 70 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP + 50;
	m_staticString3.SetWindowText( pcsaLabels->GetAt( 2 ) );
	m_staticString3.ShowWindow( SW_SHOW );
	m_staticString3.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
	m_EditArgument3.ShowWindow( SW_SHOW );
	m_EditArgument3.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
	m_staticString4.SetWindowText( pcsaLabels->GetAt( 3 ) );
	m_staticString4.ShowWindow( SW_SHOW );
	m_staticString4.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
	m_EditArgument4.ShowWindow( SW_SHOW );
	m_EditArgument4.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, ROW_COL_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
	m_staticString5.SetWindowText( pcsaLabels->GetAt( 4 ) );
	m_staticString5.ShowWindow( SW_SHOW );
	m_staticString5.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
	m_EditArgument5.ShowWindow( SW_SHOW );
	m_EditArgument5.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, ROW_COL_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
	m_staticString6.SetWindowText( pcsaLabels->GetAt( 5 ) );
	m_staticString6.ShowWindow( SW_SHOW );
	m_staticString6.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
	m_EditArgument6.ShowWindow( SW_SHOW );
	m_EditArgument6.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, ROW_COL_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
	m_staticString7.SetWindowText( pcsaLabels->GetAt( 6 ) );
	m_staticString7.ShowWindow( SW_SHOW );
	m_staticString7.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );

	listParams2.ShowWindow( SW_SHOW  );
	listParams2.ResetContent();
	for ( i=0; i<csaList2Entries->GetCount(); i++)
	{
		listParams2.AddString( csaList2Entries->GetAt(i) );
	}
	listParams2.SetCurSel(0);
	listParams2.ShowWindow( SW_SHOW  );
	listParams2.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 60 );
}




/***************************************************************************DC

	Operation:	CAPIGenDlg::Show1E2L() 

	Purpose:	Sets up one edit control + one list control + three edit 
				controls + one list control.

	Arguments:	csaLabels		-- the strings that are used to label each control.
				csaListEntries	-- the strings that go in the first listbox
				csaList2Entries -- the strings that go in the second listbox

	Note:		

*****************************************************************************/
void CAPIGenDlg::Show1E2L(  CStringArray* pcsaLabels, 
							CStringArray* csaListEntries, 
							CStringArray* csaList2Entries )
{
	int i=0;
	int topGroupStart=PARAM_TOP;
	int nGroupBoxHeight = 0;
	nGroupBoxHeight	= 255;

	m_groupAddParameterGroup.ShowWindow( SW_SHOW  );
	m_groupAddParameterGroup.MoveWindow( PARAM_LEFT_SIDE-15, topGroupStart-25, STANDARD_WIDTH+30, nGroupBoxHeight );

	m_staticString1.SetWindowText( pcsaLabels->GetAt( 0 ) );
	m_staticString1.ShowWindow( SW_SHOW );
	m_staticString1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
	m_EditArgument1.ShowWindow( SW_SHOW );
	m_EditArgument1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
	m_staticString2.SetWindowText( pcsaLabels->GetAt( 1 ) );
	m_staticString2.ShowWindow( SW_SHOW );
	m_staticString2.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );

	listParams1.ShowWindow( SW_SHOW  );
	listParams1.ResetContent();
	for ( i=0; i<csaListEntries->GetCount(); i++)
	{
		listParams1.AddString( csaListEntries->GetAt(i) );
	}
	listParams1.SetCurSel(0);
	listParams1.ShowWindow( SW_SHOW  );
	listParams1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 70 );


	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP + 50;
	m_staticString3.SetWindowText( pcsaLabels->GetAt( 2 ) );
	m_staticString3.ShowWindow( SW_SHOW );
	m_staticString3.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );

	listParams2.ShowWindow( SW_SHOW  );
	listParams2.ResetContent();
	for ( i=0; i<csaList2Entries->GetCount(); i++)
	{
		listParams2.AddString( csaList2Entries->GetAt(i) );
	}
	listParams2.SetCurSel(0);
	listParams2.ShowWindow( SW_SHOW  );
	listParams2.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 60 );

}


/***************************************************************************DC

	Operation:	CAPIGenDlg::Show1E2L1C() 

	Purpose:	Sets up one edit control + one list control + three edit 
				controls + one list control.

	Arguments:	csaLabels		-- the strings that are used to label each control.
				csaListEntries	-- the strings that go in the first listbox
				csaList2Entries -- the strings that go in the second listbox

	Note:		

*****************************************************************************/
void CAPIGenDlg::Show1E2L1C(  CStringArray* pcsaLabels, 
							CStringArray* csaListEntries, 
							CStringArray* csaList2Entries )
{
	int i=0;
	int topGroupStart=PARAM_TOP;
	int nGroupBoxHeight = 0;
	nGroupBoxHeight	= 285;

	m_groupAddParameterGroup.ShowWindow( SW_SHOW  );
	m_groupAddParameterGroup.MoveWindow( PARAM_LEFT_SIDE-15, topGroupStart-25, STANDARD_WIDTH+30, nGroupBoxHeight );

	m_staticString1.SetWindowText( pcsaLabels->GetAt( 0 ) );
	m_staticString1.ShowWindow( SW_SHOW );
	m_staticString1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
	m_EditArgument1.ShowWindow( SW_SHOW );
	m_EditArgument1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
	m_staticString2.SetWindowText( pcsaLabels->GetAt( 1 ) );
	m_staticString2.ShowWindow( SW_SHOW );
	m_staticString2.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );

	listParams1.ShowWindow( SW_SHOW  );
	listParams1.ResetContent();
	for ( i=0; i<csaListEntries->GetCount(); i++)
	{
		listParams1.AddString( csaListEntries->GetAt(i) );
	}
	listParams1.SetCurSel(0);
	listParams1.ShowWindow( SW_SHOW  );
	listParams1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 70 );


	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP + 50;
	m_staticString3.SetWindowText( pcsaLabels->GetAt( 2 ) );
	m_staticString3.ShowWindow( SW_SHOW );
	m_staticString3.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );

	listParams2.ShowWindow( SW_SHOW  );
	listParams2.ResetContent();
	for ( i=0; i<csaList2Entries->GetCount(); i++)
	{
		listParams2.AddString( csaList2Entries->GetAt(i) );
	}
	listParams2.SetCurSel(0);
	listParams2.ShowWindow( SW_SHOW  );
	listParams2.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 60 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP + 40;
	checkParam1.SetWindowText( pcsaLabels->GetAt( 3 ) );
	checkParam1.ShowWindow( SW_SHOW );
	checkParam1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 22 );

}



/***************************************************************************DC

	Operation:	CAPIGenDlg::Show1E2L1E2L3E1L1E() 

	Purpose:	Sets up one edit control + one list control + three edit 
				controls + one list control.

	Arguments:	csaLabels		-- the strings that are used to label each control.
				csaListEntries	-- the strings that go in the first listbox
				csaList2Entries -- the strings that go in the second listbox

	Note:		

*****************************************************************************/
void CAPIGenDlg::Show1E2L1E2L3E1L1E( CStringArray* pcsaLabels, 
									 CStringArray* csaListEntries, 
									 CStringArray* csaList2Entries, 
									 CStringArray* csaList3Entries, 
									 CStringArray* csaList4Entries, 
									 CStringArray* csaList5Entries )
{
	int i=0;
	int topGroupStart=PARAM_TOP;
	int nGroupBoxHeight = 0;
	nGroupBoxHeight	= 660;

	m_groupAddParameterGroup.ShowWindow( SW_SHOW  );
	m_groupAddParameterGroup.MoveWindow( PARAM_LEFT_SIDE-15, topGroupStart-25, STANDARD_WIDTH+30, nGroupBoxHeight );

	m_staticString1.SetWindowText( pcsaLabels->GetAt( 0 ) );
	m_staticString1.ShowWindow( SW_SHOW );
	m_staticString1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
	m_EditArgument1.ShowWindow( SW_SHOW );
	m_EditArgument1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
	m_staticString2.SetWindowText( pcsaLabels->GetAt( 1 ) );
	m_staticString2.ShowWindow( SW_SHOW );
	m_staticString2.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );

	listParams1.ShowWindow( SW_SHOW  );
	listParams1.ResetContent();
	for ( i=0; i<csaListEntries->GetCount(); i++)
	{
		listParams1.AddString( csaListEntries->GetAt(i) );
	}
	listParams1.SetCurSel(0);
	listParams1.ShowWindow( SW_SHOW  );
	listParams1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 70 );


	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP + 50;
	m_staticString3.SetWindowText( pcsaLabels->GetAt( 2 ) );
	m_staticString3.ShowWindow( SW_SHOW );
	m_staticString3.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );

	listParams2.ShowWindow( SW_SHOW  );
	listParams2.ResetContent();
	for ( i=0; i<csaList2Entries->GetCount(); i++)
	{
		listParams2.AddString( csaList2Entries->GetAt(i) );
	}
	listParams2.SetCurSel(0);
	listParams2.ShowWindow( SW_SHOW  );
	listParams2.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 60 );


	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP + 40;
	m_staticString4.SetWindowText( pcsaLabels->GetAt( 3 ) );
	m_staticString4.ShowWindow( SW_SHOW );
	m_staticString4.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
	m_EditArgument3.ShowWindow( SW_SHOW );
	m_EditArgument3.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );


	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
	m_staticString5.SetWindowText( pcsaLabels->GetAt( 4 ) );
	m_staticString5.ShowWindow( SW_SHOW );
	m_staticString5.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );

	listParams3.ShowWindow( SW_SHOW  );
	listParams3.ResetContent();
	for ( i=0; i<csaList3Entries->GetCount(); i++)
	{
		listParams3.AddString( csaList3Entries->GetAt(i) );
	}
	listParams3.SetCurSel(0);
	listParams3.ShowWindow( SW_SHOW  );
	listParams3.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 35 );


	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP + 15;
	m_staticString6.SetWindowText( pcsaLabels->GetAt( 5 ) );
	m_staticString6.ShowWindow( SW_SHOW );
	m_staticString6.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );

	listParams4.ShowWindow( SW_SHOW  );
	listParams4.ResetContent();
	for ( i=0; i<csaList4Entries->GetCount(); i++)
	{
		listParams4.AddString( csaList4Entries->GetAt(i) );
	}
	listParams4.SetCurSel(0);
	listParams4.ShowWindow( SW_SHOW  );
	listParams4.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 35 );


	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP + 15;
	m_staticString7.SetWindowText( pcsaLabels->GetAt( 6 ) );
	m_staticString7.ShowWindow( SW_SHOW );
	m_staticString7.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
	m_EditArgument4.ShowWindow( SW_SHOW );
	m_EditArgument4.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
	m_staticString8.SetWindowText( pcsaLabels->GetAt( 7 ) );
	m_staticString8.ShowWindow( SW_SHOW );
	m_staticString8.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
	m_EditArgument5.ShowWindow( SW_SHOW );
	m_EditArgument5.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
	m_staticString9.SetWindowText( pcsaLabels->GetAt( 8 ) );
	m_staticString9.ShowWindow( SW_SHOW );
	m_staticString9.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
	m_EditArgument6.ShowWindow( SW_SHOW );
	m_EditArgument6.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
	m_staticString10.SetWindowText( pcsaLabels->GetAt( 9 ) );
	m_staticString10.ShowWindow( SW_SHOW );
	m_staticString10.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );

	listParams5.ShowWindow( SW_SHOW  );
	listParams5.ResetContent();
	for ( i=0; i<csaList5Entries->GetCount(); i++)
	{
		listParams5.AddString( csaList5Entries->GetAt(i) );
	}
	listParams5.SetCurSel(0);
	listParams5.ShowWindow( SW_SHOW  );
	listParams5.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 55 );


	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP + 30;
	m_staticString11.SetWindowText( pcsaLabels->GetAt( 10 ) );
	m_staticString11.ShowWindow( SW_SHOW );
	m_staticString11.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
	m_EditArgument7.ShowWindow( SW_SHOW );
	m_EditArgument7.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );


}


/***************************************************************************DC

	Operation:	CAPIGenDlg::Show2E2L() 

	Purpose:	Sets up two edit controls + one list control.

	Arguments:	csaLabels		-- the strings that are used to label each control.
				csaListEntries	-- the strings that go in the listbox

	Note:		

*****************************************************************************/
void CAPIGenDlg::Show2E2L( CStringArray* pcsaLabels, 
						   CStringArray* csaListEntries,  
						   CStringArray* csaList2Entries  )
{
	int i=0;
	int topGroupStart=PARAM_TOP;
	int nGroupBoxHeight = 0;
	nGroupBoxHeight	= 285;

	m_groupAddParameterGroup.ShowWindow( SW_SHOW  );
	m_groupAddParameterGroup.MoveWindow( PARAM_LEFT_SIDE-15, topGroupStart-25, STANDARD_WIDTH+30, nGroupBoxHeight );

	m_staticString1.SetWindowText( pcsaLabels->GetAt( 0 ) );
	m_staticString1.ShowWindow( SW_SHOW );
	m_staticString1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 22 );
	m_EditArgument1.ShowWindow( SW_SHOW );
	m_EditArgument1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
	m_staticString2.SetWindowText( pcsaLabels->GetAt( 1 ) );
	m_staticString2.ShowWindow( SW_SHOW );
	m_staticString2.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 22 );
	m_EditArgument3.ShowWindow( SW_SHOW );
	m_EditArgument3.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
	m_staticString3.SetWindowText( pcsaLabels->GetAt( 2 ) );
	m_staticString3.ShowWindow( SW_SHOW );
	m_staticString3.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 22 );

	listParams1.ShowWindow( SW_SHOW  );
	listParams1.ResetContent();
	for ( i=0; i<csaListEntries->GetCount(); i++)
	{
		listParams1.AddString( csaListEntries->GetAt(i) );
	}
	listParams1.SetCurSel(0);
	listParams1.ShowWindow( SW_SHOW  );
	listParams1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 40 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP + 20;
	m_staticString4.SetWindowText( pcsaLabels->GetAt( 3 ) );
	m_staticString4.ShowWindow( SW_SHOW );
	m_staticString4.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 22 );

	listParams2.ShowWindow( SW_SHOW  );
	listParams2.ResetContent();
	for ( i=0; i<csaList2Entries->GetCount(); i++)
	{
		listParams2.AddString( csaList2Entries->GetAt(i) );
	}
	listParams2.SetCurSel(0);
	listParams2.ShowWindow( SW_SHOW  );
	listParams2.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 60 );
}


/***************************************************************************DC

	Operation:	CAPIGenDlg::Show2E2C() 

	Purpose:	Sets up two edit controls + two checkboxes.

	Arguments:	csaLabels -- the strings that are used to label each control.

	Note:		

*****************************************************************************/
void CAPIGenDlg::Show2E2C( CStringArray* pcsaLabels )
{
	int topGroupStart=PARAM_TOP;
	int nGroupBoxHeight = 0;
	nGroupBoxHeight	= 185;

	m_groupAddParameterGroup.ShowWindow( SW_SHOW  );
	m_groupAddParameterGroup.MoveWindow( PARAM_LEFT_SIDE-15, topGroupStart-25, STANDARD_WIDTH+30, nGroupBoxHeight );

	m_staticString1.SetWindowText( pcsaLabels->GetAt( 0 ) );
	m_staticString1.ShowWindow( SW_SHOW );
	m_staticString1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 22 );
	m_EditArgument1.ShowWindow( SW_SHOW );
	m_EditArgument1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
	m_staticString2.SetWindowText( pcsaLabels->GetAt( 1 ) );
	m_staticString2.ShowWindow( SW_SHOW );
	m_staticString2.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 22 );
	m_EditArgument3.ShowWindow( SW_SHOW );
	m_EditArgument3.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
	checkParam1.SetWindowText( pcsaLabels->GetAt( 2 ) );
	checkParam1.ShowWindow( SW_SHOW );
	checkParam1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP - 20;
	checkParam2.SetWindowText( pcsaLabels->GetAt( 3 ) );
	checkParam2.ShowWindow( SW_SHOW );
	checkParam2.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 22 );
}


/***************************************************************************DC

	Operation:	CAPIGenDlg::Show2E2C1E1L() 

	Purpose:	Sets up two edit controls + two checkboxes + one edit control +
				one listbox.

	Arguments:	csaLabels -- the strings that are used to label each control.

	Note:		

*****************************************************************************/
void CAPIGenDlg::Show2E2C1E1L( CStringArray* pcsaLabels, CStringArray* csaListEntries  )
{
	int topGroupStart=PARAM_TOP;
	int nGroupBoxHeight = 0;
	nGroupBoxHeight	= 315;

	m_groupAddParameterGroup.ShowWindow( SW_SHOW  );
	m_groupAddParameterGroup.MoveWindow( PARAM_LEFT_SIDE-15, topGroupStart-25, STANDARD_WIDTH+30, nGroupBoxHeight );

	m_staticString1.SetWindowText( pcsaLabels->GetAt( 0 ) );
	m_staticString1.ShowWindow( SW_SHOW );
	m_staticString1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
	m_EditArgument1.ShowWindow( SW_SHOW );
	m_EditArgument1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
	m_staticString2.SetWindowText( pcsaLabels->GetAt( 1 ) );
	m_staticString2.ShowWindow( SW_SHOW );
	m_staticString2.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
	m_EditArgument3.ShowWindow( SW_SHOW );
	m_EditArgument3.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
	checkParam1.SetWindowText( pcsaLabels->GetAt( 2 ) );
	checkParam1.ShowWindow( SW_SHOW );
	checkParam1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP - 20;
	checkParam2.SetWindowText( pcsaLabels->GetAt( 3 ) );
	checkParam2.ShowWindow( SW_SHOW );
	checkParam2.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP - 15;
	m_staticString3.SetWindowText( pcsaLabels->GetAt( 4 ) );
	m_staticString3.ShowWindow( SW_SHOW );
	m_staticString3.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
	m_EditArgument4.ShowWindow( SW_SHOW );
	m_EditArgument4.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
	m_staticString4.SetWindowText( pcsaLabels->GetAt( 5 ) );
	m_staticString4.ShowWindow( SW_SHOW );
	m_staticString4.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );

	listParams1.ShowWindow( SW_SHOW  );
	listParams1.ResetContent();

	for ( int i=0; i<csaListEntries->GetCount(); i++)
	{
		listParams1.AddString( csaListEntries->GetAt(i) );
	}

	listParams1.SetCurSel(0);
	listParams1.ShowWindow( SW_SHOW  );
	listParams1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 50 );

}


/***************************************************************************DC

	Operation:	CAPIGenDlg::Show2E2C1E2L1E() 

	Purpose:	Sets up two edit controls + two checkboxes + one edit control +
				two listboxes + one edit control.

	Arguments:	csaLabels -- the strings that are used to label each control.

	Note:		

*****************************************************************************/
void CAPIGenDlg::Show2E2C1E2L1E( CStringArray* pcsaLabels, CStringArray* csaListEntries,  CStringArray* csaList2Entries  )
{
	int topGroupStart=PARAM_TOP;
	int nGroupBoxHeight = 0;
	int i=0;
	nGroupBoxHeight	= 425;

	m_groupAddParameterGroup.ShowWindow( SW_SHOW  );
	m_groupAddParameterGroup.MoveWindow( PARAM_LEFT_SIDE-15, topGroupStart-25, STANDARD_WIDTH+30, nGroupBoxHeight );

	m_staticString1.SetWindowText( pcsaLabels->GetAt( 0 ) );
	m_staticString1.ShowWindow( SW_SHOW );
	m_staticString1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
	m_EditArgument1.ShowWindow( SW_SHOW );
	m_EditArgument1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
	m_staticString2.SetWindowText( pcsaLabels->GetAt( 1 ) );
	m_staticString2.ShowWindow( SW_SHOW );
	m_staticString2.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
	m_EditArgument3.ShowWindow( SW_SHOW );
	m_EditArgument3.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
	checkParam1.SetWindowText( pcsaLabels->GetAt( 2 ) );
	checkParam1.ShowWindow( SW_SHOW );
	checkParam1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP - 20;
	checkParam2.SetWindowText( pcsaLabels->GetAt( 3 ) );
	checkParam2.ShowWindow( SW_SHOW );
	checkParam2.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP - 15;
	m_staticString3.SetWindowText( pcsaLabels->GetAt( 4 ) );
	m_staticString3.ShowWindow( SW_SHOW );
	m_staticString3.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
	m_EditArgument4.ShowWindow( SW_SHOW );
	m_EditArgument4.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
	m_staticString4.SetWindowText( pcsaLabels->GetAt( 5 ) );
	m_staticString4.ShowWindow( SW_SHOW );
	m_staticString4.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );

	listParams1.ShowWindow( SW_SHOW  );
	listParams1.ResetContent();

	for ( i=0; i<csaListEntries->GetCount(); i++)
	{
		listParams1.AddString( csaListEntries->GetAt(i) );
	}

	listParams1.SetCurSel(0);
	listParams1.ShowWindow( SW_SHOW  );
	listParams1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 50 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP + 35;
	m_staticString5.SetWindowText( pcsaLabels->GetAt( 6 ) );
	m_staticString5.ShowWindow( SW_SHOW );
	m_staticString5.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 22 );

	listParams2.ShowWindow( SW_SHOW  );
	listParams2.ResetContent();
	for ( i=0; i<csaList2Entries->GetCount(); i++)
	{
		listParams2.AddString( csaList2Entries->GetAt(i) );
	}
	listParams2.SetCurSel(0);
	listParams2.ShowWindow( SW_SHOW  );
	listParams2.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 60 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP + 40;
	m_staticString6.SetWindowText( pcsaLabels->GetAt( 7 ) );
	m_staticString6.ShowWindow( SW_SHOW );
	m_staticString6.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
	m_EditArgument5.ShowWindow( SW_SHOW );
	m_EditArgument5.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

}


/***************************************************************************DC

	Operation:	CAPIGenDlg::Show2E1L1E() 

	Purpose:	Sets up two edit controls + one list control + one edit control.

	Arguments:	csaLabels		-- the strings that are used to label each control.
				csaListEntries	-- the strings that go in the listbox

	Note:		

*****************************************************************************/
void CAPIGenDlg::Show2E1L1E( CStringArray* pcsaLabels, CStringArray* csaListEntries  )
{
	int topGroupStart=PARAM_TOP;
	int nGroupBoxHeight = 0;
	nGroupBoxHeight	= 335;
	m_groupAddParameterGroup.ShowWindow( SW_SHOW  );
	m_groupAddParameterGroup.MoveWindow( PARAM_LEFT_SIDE-15, topGroupStart-25, STANDARD_WIDTH+30, nGroupBoxHeight );

	m_staticString1.SetWindowText( pcsaLabels->GetAt( 0 ) );
	m_staticString1.ShowWindow( SW_SHOW );
	m_staticString1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
	m_EditArgument1.ShowWindow( SW_SHOW );
	m_EditArgument1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
	m_staticString2.SetWindowText( pcsaLabels->GetAt( 1 ) );
	m_staticString2.ShowWindow( SW_SHOW );
	m_staticString2.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
	m_EditArgument3.ShowWindow( SW_SHOW );
	m_EditArgument3.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
	m_staticString3.SetWindowText( pcsaLabels->GetAt( 2 ) );
	m_staticString3.ShowWindow( SW_SHOW );
	m_staticString3.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 22 );

	listParams1.ShowWindow( SW_SHOW  );
	listParams1.ResetContent();

	for ( int i=0; i<csaListEntries->GetCount(); i++)
	{
		listParams1.AddString( csaListEntries->GetAt(i) );
	}

	listParams1.SetCurSel(0);
	listParams1.ShowWindow( SW_SHOW  );
	listParams1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 40 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP + 20;
	m_staticString4.SetWindowText( pcsaLabels->GetAt( 3 ) );
	m_staticString4.ShowWindow( SW_SHOW );
	m_staticString4.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
	m_EditArgument4.ShowWindow( SW_SHOW );
	m_EditArgument4.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );
}



/***************************************************************************DC

	Operation:	CAPIGenDlg::Show2E1L1C() 

	Purpose:	Sets up two edit controls + one list control + one checkbox.

	Arguments:	csaLabels		-- the strings that are used to label each control.
				csaListEntries	-- the strings that go in the listbox

	Note:		

*****************************************************************************/
void CAPIGenDlg::Show2E1L1C( CStringArray* pcsaLabels, CStringArray* csaListEntries  )
{
	int topGroupStart=PARAM_TOP;
	int nGroupBoxHeight = 0;
	nGroupBoxHeight	= 335;
	m_groupAddParameterGroup.ShowWindow( SW_SHOW  );
	m_groupAddParameterGroup.MoveWindow( PARAM_LEFT_SIDE-15, topGroupStart-25, STANDARD_WIDTH+30, nGroupBoxHeight );

	m_staticString1.SetWindowText( pcsaLabels->GetAt( 0 ) );
	m_staticString1.ShowWindow( SW_SHOW );
	m_staticString1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 22 );
	m_EditArgument1.ShowWindow( SW_SHOW );
	m_EditArgument1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
	m_staticString2.SetWindowText( pcsaLabels->GetAt( 1 ) );
	m_staticString2.ShowWindow( SW_SHOW );
	m_staticString2.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 22 );
	m_EditArgument3.ShowWindow( SW_SHOW );
	m_EditArgument3.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
	m_staticString3.SetWindowText( pcsaLabels->GetAt( 2 ) );
	m_staticString3.ShowWindow( SW_SHOW );
	m_staticString3.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 22 );

	listParams1.ShowWindow( SW_SHOW  );
	listParams1.ResetContent();

	for ( int i=0; i<csaListEntries->GetCount(); i++)
	{
		listParams1.AddString( csaListEntries->GetAt(i) );
	}

	listParams1.SetCurSel(0);
	listParams1.ShowWindow( SW_SHOW  );
	listParams1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 40 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP + 20;
	checkParam1.SetWindowText( pcsaLabels->GetAt( 3 ) );
	checkParam1.ShowWindow( SW_SHOW );
	checkParam1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 22 );
}



/***************************************************************************DC

	Operation:	CAPIGenDlg::Show2L() 

	Purpose:	Sets up two list controls.

	Arguments:	csaLabels		-- the strings that are used to label each control.
				csaListEntries	-- the strings that go in the listbox
				csaList2Entries -- the other strings for the other listbox

	Note:		

*****************************************************************************/
void CAPIGenDlg::Show2L( CStringArray* pcsaLabels, 
						   CStringArray* csaListEntries,  
						   CStringArray* csaList2Entries  )
{
	int i=0;
	int topGroupStart=PARAM_TOP;
	int nGroupBoxHeight = 0;
	nGroupBoxHeight	= 285;

	m_groupAddParameterGroup.ShowWindow( SW_SHOW  );
	m_groupAddParameterGroup.MoveWindow( PARAM_LEFT_SIDE-15, topGroupStart-25, STANDARD_WIDTH+30, nGroupBoxHeight );

	m_staticString1.SetWindowText( pcsaLabels->GetAt( 0 ) );
	m_staticString1.ShowWindow( SW_SHOW );
	m_staticString1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 22 );

	listParams1.ShowWindow( SW_SHOW  );
	listParams1.ResetContent();
	for ( i=0; i<csaListEntries->GetCount(); i++)
	{
		listParams1.AddString( csaListEntries->GetAt(i) );
	}
	listParams1.SetCurSel(0);
	listParams1.ShowWindow( SW_SHOW  );
	listParams1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 40 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP + 20;
	m_staticString2.SetWindowText( pcsaLabels->GetAt( 1 ) );
	m_staticString2.ShowWindow( SW_SHOW );
	m_staticString2.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 22 );

	listParams2.ShowWindow( SW_SHOW  );
	listParams2.ResetContent();
	for ( i=0; i<csaList2Entries->GetCount(); i++)
	{
		listParams2.AddString( csaList2Entries->GetAt(i) );
	}
	listParams2.SetCurSel(0);
	listParams2.ShowWindow( SW_SHOW  );
	listParams2.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 60 );
}


/***************************************************************************DC

	Operation:	CAPIGenDlg::Show3E() 

	Purpose:	Sets up three edit controls

	Arguments:	csaLabels		-- the strings that are used to label each control.

	Note:		

*****************************************************************************/
void CAPIGenDlg::Show3E( CStringArray* pcsaLabels )
{
	int topGroupStart=PARAM_TOP;
	int nGroupBoxHeight = 0;
	nGroupBoxHeight	= 235;

	m_groupAddParameterGroup.ShowWindow( SW_SHOW  );
	m_groupAddParameterGroup.MoveWindow( PARAM_LEFT_SIDE-15, topGroupStart-25, STANDARD_WIDTH+30, nGroupBoxHeight );

	m_staticString1.SetWindowText( pcsaLabels->GetAt( 0 ) );
	m_staticString1.ShowWindow( SW_SHOW );
	m_staticString1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 22 );
	m_EditArgument1.ShowWindow( SW_SHOW );
	m_EditArgument1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
	m_staticString2.SetWindowText( pcsaLabels->GetAt( 1 ) );
	m_staticString2.ShowWindow( SW_SHOW );
	m_staticString2.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 22 );
	m_EditArgument3.ShowWindow( SW_SHOW );
	m_EditArgument3.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
	m_staticString3.SetWindowText( pcsaLabels->GetAt( 2 ) );
	m_staticString3.ShowWindow( SW_SHOW );
	m_staticString3.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 22 );
	m_EditArgument4.ShowWindow( SW_SHOW );
	m_EditArgument4.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
	m_staticString4.SetWindowText( pcsaLabels->GetAt( 3 ) );
	m_staticString4.ShowWindow( SW_SHOW );
	m_staticString4.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 22 );

}





/***************************************************************************DC

	Operation:	CAPIGenDlg::Show3E1L() 

	Purpose:	Sets up three edit controls and one list control.

	Arguments:	csaLabels		-- the strings that are used to label each control.
				csaListEntries	-- the strings that go in the listbox

	Note:		

*****************************************************************************/
void CAPIGenDlg::Show3E1L( CStringArray* pcsaLabels, CStringArray* csaListEntries  )
{
	int topGroupStart=PARAM_TOP;
	int nGroupBoxHeight = 0;
	nGroupBoxHeight	= 235;

	m_groupAddParameterGroup.ShowWindow( SW_SHOW  );
	m_groupAddParameterGroup.MoveWindow( PARAM_LEFT_SIDE-15, topGroupStart-25, STANDARD_WIDTH+30, nGroupBoxHeight );

	m_staticString1.SetWindowText( pcsaLabels->GetAt( 0 ) );
	m_staticString1.ShowWindow( SW_SHOW );
	m_staticString1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 22 );
	m_EditArgument1.ShowWindow( SW_SHOW );
	m_EditArgument1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
	m_staticString2.SetWindowText( pcsaLabels->GetAt( 1 ) );
	m_staticString2.ShowWindow( SW_SHOW );
	m_staticString2.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 22 );
	m_EditArgument3.ShowWindow( SW_SHOW );
	m_EditArgument3.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
	m_staticString3.SetWindowText( pcsaLabels->GetAt( 2 ) );
	m_staticString3.ShowWindow( SW_SHOW );
	m_staticString3.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 22 );
	m_EditArgument4.ShowWindow( SW_SHOW );
	m_EditArgument4.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
	m_staticString4.SetWindowText( pcsaLabels->GetAt( 3 ) );
	m_staticString4.ShowWindow( SW_SHOW );
	m_staticString4.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 22 );

	listParams1.ShowWindow( SW_SHOW  );
	listParams1.ResetContent();
	for ( int i=0; i<csaListEntries->GetCount(); i++)
	{
		listParams1.AddString( csaListEntries->GetAt(i) );
	}
	listParams1.SetCurSel(0);
	listParams1.ShowWindow( SW_SHOW  );
	listParams1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 40 );
}




/***************************************************************************DC

	Operation:	CAPIGenDlg::Show2E2L1C() 

	Purpose:	Sets up two edit controls + two listboxes + one checkbox.

	Arguments:	csaLabels		-- the strings that are used to label each control.
				csaListEntries	-- the strings that go in the first listbox
				csaList2Entries -- the strings that go in the second listbox

	Note:		

*****************************************************************************/
void CAPIGenDlg::Show2E2L1C( CStringArray* pcsaLabels, 
						   CStringArray* csaListEntries,  
						   CStringArray* csaList2Entries  )
{
	int i=0;
	int topGroupStart=PARAM_TOP;
	int nGroupBoxHeight = 0;
	nGroupBoxHeight	= 325;

	m_groupAddParameterGroup.ShowWindow( SW_SHOW  );
	m_groupAddParameterGroup.MoveWindow( PARAM_LEFT_SIDE-15, topGroupStart-25, STANDARD_WIDTH+30, nGroupBoxHeight );

	m_staticString1.SetWindowText( pcsaLabels->GetAt( 0 ) );
	m_staticString1.ShowWindow( SW_SHOW );
	m_staticString1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
	m_EditArgument1.ShowWindow( SW_SHOW );
	m_EditArgument1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
	m_staticString2.SetWindowText( pcsaLabels->GetAt( 1 ) );
	m_staticString2.ShowWindow( SW_SHOW );
	m_staticString2.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
	m_EditArgument3.ShowWindow( SW_SHOW );
	m_EditArgument3.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
	m_staticString3.SetWindowText( pcsaLabels->GetAt( 2 ) );
	m_staticString3.ShowWindow( SW_SHOW );
	m_staticString3.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );

	listParams1.ShowWindow( SW_SHOW  );
	listParams1.ResetContent();
	for ( i=0; i<csaListEntries->GetCount(); i++)
	{
		listParams1.AddString( csaListEntries->GetAt(i) );
	}
	listParams1.SetCurSel(0);
	listParams1.ShowWindow( SW_SHOW  );
	listParams1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 50 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP + 30;
	m_staticString4.SetWindowText( pcsaLabels->GetAt( 3 ) );
	m_staticString4.ShowWindow( SW_SHOW );
	m_staticString4.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );

	listParams2.ShowWindow( SW_SHOW  );
	listParams2.ResetContent();
	for ( i=0; i<csaList2Entries->GetCount(); i++)
	{
		listParams2.AddString( csaList2Entries->GetAt(i) );
	}
	listParams2.SetCurSel(0);
	listParams2.ShowWindow( SW_SHOW  );
	listParams2.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 50 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP + 30;
	checkParam1.SetWindowText( pcsaLabels->GetAt( 4 ) );
	checkParam1.ShowWindow( SW_SHOW );
	checkParam1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 22 );

}


/***************************************************************************DC

	Operation:	CAPIGenDlg::Show2E2L3E() 

	Purpose:	Sets up two edit controls + two listboxes + 3 edit controls.

	Arguments:	csaLabels		-- the strings that are used to label each control.
				csaListEntries	-- the strings that go in the first listbox
				csaList2Entries -- the strings that go in the second listbox

	Note:		

*****************************************************************************/
void CAPIGenDlg::Show2E2L3E( CStringArray* pcsaLabels, 
						   CStringArray* csaListEntries,  
						   CStringArray* csaList2Entries  )
{
	int i=0;
	int topGroupStart=PARAM_TOP;
	int nGroupBoxHeight = 0;
	nGroupBoxHeight	= 425;

	m_groupAddParameterGroup.ShowWindow( SW_SHOW  );
	m_groupAddParameterGroup.MoveWindow( PARAM_LEFT_SIDE-15, topGroupStart-25, STANDARD_WIDTH+30, nGroupBoxHeight );

	m_staticString1.SetWindowText( pcsaLabels->GetAt( 0 ) );
	m_staticString1.ShowWindow( SW_SHOW );
	m_staticString1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
	m_EditArgument1.ShowWindow( SW_SHOW );
	m_EditArgument1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
	m_staticString2.SetWindowText( pcsaLabels->GetAt( 1 ) );
	m_staticString2.ShowWindow( SW_SHOW );
	m_staticString2.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
	m_EditArgument3.ShowWindow( SW_SHOW );
	m_EditArgument3.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
	m_staticString3.SetWindowText( pcsaLabels->GetAt( 2 ) );
	m_staticString3.ShowWindow( SW_SHOW );
	m_staticString3.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );

	listParams1.ShowWindow( SW_SHOW  );
	listParams1.ResetContent();
	for ( i=0; i<csaListEntries->GetCount(); i++)
	{
		listParams1.AddString( csaListEntries->GetAt(i) );
	}
	listParams1.SetCurSel(0);
	listParams1.ShowWindow( SW_SHOW  );
	listParams1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 40 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP + 20;
	m_staticString4.SetWindowText( pcsaLabels->GetAt( 3 ) );
	m_staticString4.ShowWindow( SW_SHOW );
	m_staticString4.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );

	listParams2.ShowWindow( SW_SHOW  );
	listParams2.ResetContent();
	for ( i=0; i<csaList2Entries->GetCount(); i++)
	{
		listParams2.AddString( csaList2Entries->GetAt(i) );
	}
	listParams2.SetCurSel(0);
	listParams2.ShowWindow( SW_SHOW  );
	listParams2.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 60 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP + 40;
	m_staticString5.SetWindowText( pcsaLabels->GetAt( 4 ) );
	m_staticString5.ShowWindow( SW_SHOW );
	m_staticString5.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
	m_EditArgument4.ShowWindow( SW_SHOW );
	m_EditArgument4.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
	m_staticString6.SetWindowText( pcsaLabels->GetAt( 5 ) );
	m_staticString6.ShowWindow( SW_SHOW );
	m_staticString6.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
	m_EditArgument5.ShowWindow( SW_SHOW );
	m_EditArgument5.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
	m_staticString7.SetWindowText( pcsaLabels->GetAt( 6 ) );
	m_staticString7.ShowWindow( SW_SHOW );
	m_staticString7.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
	m_EditArgument6.ShowWindow( SW_SHOW );
	m_EditArgument6.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

}



/***************************************************************************DC

	Operation:	CAPIGenDlg::Show3E1C() 

	Purpose:	Sets up three list controls + one checkbox.

	Arguments:	csaLabels -- the strings that are used to label each control.

	Note:		

*****************************************************************************/
void CAPIGenDlg::Show3E1C( CStringArray* pcsaLabels )
{
	int topGroupStart=PARAM_TOP;
	int nGroupBoxHeight = 0;
	nGroupBoxHeight	= 285;

	m_groupAddParameterGroup.ShowWindow( SW_SHOW  );
	m_groupAddParameterGroup.MoveWindow( PARAM_LEFT_SIDE-15, topGroupStart-25, STANDARD_WIDTH+30, nGroupBoxHeight );

	m_staticString1.SetWindowText( pcsaLabels->GetAt( 0 ) );
	m_staticString1.ShowWindow( SW_SHOW );
	m_staticString1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 22 );
	m_EditArgument1.ShowWindow( SW_SHOW );
	m_EditArgument1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
	m_staticString2.SetWindowText( pcsaLabels->GetAt( 1 ) );
	m_staticString2.ShowWindow( SW_SHOW );
	m_staticString2.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 22 );
	m_EditArgument3.ShowWindow( SW_SHOW );
	m_EditArgument3.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
	m_staticString3.SetWindowText( pcsaLabels->GetAt( 2 ) );
	m_staticString3.ShowWindow( SW_SHOW );
	m_staticString3.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 22 );
	m_EditArgument4.ShowWindow( SW_SHOW );
	m_EditArgument4.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP + 5;
	checkParam1.SetWindowText( pcsaLabels->GetAt( 3 ) );
	checkParam1.ShowWindow( SW_SHOW );
	checkParam1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 22 );
}



/***************************************************************************DC

	Operation:	CAPIGenDlg::Show3L() 

	Purpose:	Sets up three list controls.

	Arguments:	csaLabels		-- the strings that are used to label each control.
				csaListEntries	-- the strings that go in the listbox
				csaList2Entries -- the strings for the second listbox
				csaList3Entries -- the other strings for the other listbox

	Note:		

*****************************************************************************/
void CAPIGenDlg::Show3L( CStringArray* pcsaLabels, 
						   CStringArray* csaListEntries,  
						   CStringArray* csaList2Entries,
						   CStringArray* csaList3Entries  )
{
	int i=0;
	int topGroupStart=PARAM_TOP;
	int nGroupBoxHeight = 0;
	nGroupBoxHeight	= 285;

	m_groupAddParameterGroup.ShowWindow( SW_SHOW  );
	m_groupAddParameterGroup.MoveWindow( PARAM_LEFT_SIDE-15, topGroupStart-25, STANDARD_WIDTH+30, nGroupBoxHeight );

	m_staticString1.SetWindowText( pcsaLabels->GetAt( 0 ) );
	m_staticString1.ShowWindow( SW_SHOW );
	m_staticString1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 22 );

	listParams1.ShowWindow( SW_SHOW  );
	listParams1.ResetContent();
	for ( i=0; i<csaListEntries->GetCount(); i++)
	{
		listParams1.AddString( csaListEntries->GetAt(i) );
	}
	listParams1.SetCurSel(0);
	listParams1.ShowWindow( SW_SHOW  );
	listParams1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 60 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP + 40;
	m_staticString2.SetWindowText( pcsaLabels->GetAt( 1 ) );
	m_staticString2.ShowWindow( SW_SHOW );
	m_staticString2.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 22 );

	listParams2.ShowWindow( SW_SHOW  );
	listParams2.ResetContent();
	for ( i=0; i<csaList2Entries->GetCount(); i++)
	{
		listParams2.AddString( csaList2Entries->GetAt(i) );
	}
	listParams2.SetCurSel(0);
	listParams2.ShowWindow( SW_SHOW  );
	listParams2.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 60 );


	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP + 40;
	m_staticString3.SetWindowText( pcsaLabels->GetAt( 2 ) );
	m_staticString3.ShowWindow( SW_SHOW );
	m_staticString3.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 22 );

	listParams3.ShowWindow( SW_SHOW  );
	listParams3.ResetContent();
	for ( i=0; i<csaList3Entries->GetCount(); i++)
	{
		listParams3.AddString( csaList3Entries->GetAt(i) );
	}
	listParams3.SetCurSel(0);
	listParams3.ShowWindow( SW_SHOW  );
	listParams3.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 60 );

}



/***************************************************************************DC

	Operation:	CAPIGenDlg::Show3L2E() 

	Purpose:	Sets up three listboxes + two edit controls.

	Arguments:	csaLabels		-- the strings that are used to label each control.
				csaListEntries	-- the strings that go in the listbox
				csaList2Entries -- the strings for the second listbox
				csaList3Entries -- the other strings for the other listbox

	Note:		

*****************************************************************************/
void CAPIGenDlg::Show3L2E( CStringArray* pcsaLabels, 
						   CStringArray* csaListEntries,  
						   CStringArray* csaList2Entries,
						   CStringArray* csaList3Entries  )
{
	int i=0;
	int topGroupStart=PARAM_TOP;
	int nGroupBoxHeight = 0;
	nGroupBoxHeight	= 385;

	m_groupAddParameterGroup.ShowWindow( SW_SHOW  );
	m_groupAddParameterGroup.MoveWindow( PARAM_LEFT_SIDE-15, topGroupStart-25, STANDARD_WIDTH+30, nGroupBoxHeight );

	m_staticString1.SetWindowText( pcsaLabels->GetAt( 0 ) );
	m_staticString1.ShowWindow( SW_SHOW );
	m_staticString1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );

	listParams1.ShowWindow( SW_SHOW  );
	listParams1.ResetContent();
	for ( i=0; i<csaListEntries->GetCount(); i++)
	{
		listParams1.AddString( csaListEntries->GetAt(i) );
	}
	listParams1.SetCurSel(0);
	listParams1.ShowWindow( SW_SHOW  );
	listParams1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 60 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP + 40;
	m_staticString2.SetWindowText( pcsaLabels->GetAt( 1 ) );
	m_staticString2.ShowWindow( SW_SHOW );
	m_staticString2.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );

	listParams2.ShowWindow( SW_SHOW  );
	listParams2.ResetContent();
	for ( i=0; i<csaList2Entries->GetCount(); i++)
	{
		listParams2.AddString( csaList2Entries->GetAt(i) );
	}
	listParams2.SetCurSel(0);
	listParams2.ShowWindow( SW_SHOW  );
	listParams2.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 60 );


	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP + 40;
	m_staticString3.SetWindowText( pcsaLabels->GetAt( 2 ) );
	m_staticString3.ShowWindow( SW_SHOW );
	m_staticString3.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );

	listParams3.ShowWindow( SW_SHOW  );
	listParams3.ResetContent();
	for ( i=0; i<csaList3Entries->GetCount(); i++)
	{
		listParams3.AddString( csaList3Entries->GetAt(i) );
	}
	listParams3.SetCurSel(0);
	listParams3.ShowWindow( SW_SHOW  );
	listParams3.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 60 );


	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP + 40;
	m_staticString4.SetWindowText( pcsaLabels->GetAt( 3 ) );
	m_staticString4.ShowWindow( SW_SHOW );
	m_staticString4.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
	m_EditArgument1.ShowWindow( SW_SHOW );
	m_EditArgument1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
	m_staticString5.SetWindowText( pcsaLabels->GetAt( 4 ) );
	m_staticString5.ShowWindow( SW_SHOW );
	m_staticString5.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
	m_EditArgument3.ShowWindow( SW_SHOW );
	m_EditArgument3.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );


}



/***************************************************************************DC

	Operation:	CAPIGenDlg::Show4E() 

	Purpose:	Sets up four edit controls

	Arguments:	csaLabels		-- the strings that are used to label each control.

	Note:		

*****************************************************************************/
void CAPIGenDlg::Show4E( CStringArray* pcsaLabels )
{
	int topGroupStart=PARAM_TOP;
	int nGroupBoxHeight = 0;
	nGroupBoxHeight	= 235;

	m_groupAddParameterGroup.ShowWindow( SW_SHOW  );
	m_groupAddParameterGroup.MoveWindow( PARAM_LEFT_SIDE-15, topGroupStart-25, STANDARD_WIDTH+30, nGroupBoxHeight );

	m_staticString1.SetWindowText( pcsaLabels->GetAt( 0 ) );
	m_staticString1.ShowWindow( SW_SHOW );
	m_staticString1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
	m_EditArgument1.ShowWindow( SW_SHOW );
	m_EditArgument1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
	m_staticString2.SetWindowText( pcsaLabels->GetAt( 1 ) );
	m_staticString2.ShowWindow( SW_SHOW );
	m_staticString2.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
	m_EditArgument3.ShowWindow( SW_SHOW );
	m_EditArgument3.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
	m_staticString3.SetWindowText( pcsaLabels->GetAt( 2 ) );
	m_staticString3.ShowWindow( SW_SHOW );
	m_staticString3.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
	m_EditArgument4.ShowWindow( SW_SHOW );
	m_EditArgument4.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
	m_staticString4.SetWindowText( pcsaLabels->GetAt( 3 ) );
	m_staticString4.ShowWindow( SW_SHOW );
	m_staticString4.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
	m_EditArgument5.ShowWindow( SW_SHOW );
	m_EditArgument5.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

}




/***************************************************************************DC

	Operation:	CAPIGenDlg::Show4E1L() 

	Purpose:	Sets up three edit controls and one list control.

	Arguments:	csaLabels		-- the strings that are used to label each control.
				csaListEntries	-- the strings that go in the listbox

	Note:		

*****************************************************************************/
void CAPIGenDlg::Show4E1L( CStringArray* pcsaLabels, CStringArray* csaListEntries  )
{
	int topGroupStart=PARAM_TOP;
	int nGroupBoxHeight = 0;
	nGroupBoxHeight	= 285;

	m_groupAddParameterGroup.ShowWindow( SW_SHOW  );
	m_groupAddParameterGroup.MoveWindow( PARAM_LEFT_SIDE-15, topGroupStart-25, STANDARD_WIDTH+30, nGroupBoxHeight );

	m_staticString1.SetWindowText( pcsaLabels->GetAt( 0 ) );
	m_staticString1.ShowWindow( SW_SHOW );
	m_staticString1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
	m_EditArgument1.ShowWindow( SW_SHOW );
	m_EditArgument1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
	m_staticString2.SetWindowText( pcsaLabels->GetAt( 1 ) );
	m_staticString2.ShowWindow( SW_SHOW );
	m_staticString2.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
	m_EditArgument3.ShowWindow( SW_SHOW );
	m_EditArgument3.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
	m_staticString3.SetWindowText( pcsaLabels->GetAt( 2 ) );
	m_staticString3.ShowWindow( SW_SHOW );
	m_staticString3.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
	m_EditArgument4.ShowWindow( SW_SHOW );
	m_EditArgument4.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
	m_staticString4.SetWindowText( pcsaLabels->GetAt( 3 ) );
	m_staticString4.ShowWindow( SW_SHOW );
	m_staticString4.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
	m_EditArgument5.ShowWindow( SW_SHOW );
	m_EditArgument5.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
	m_staticString5.SetWindowText( pcsaLabels->GetAt( 4 ) );
	m_staticString5.ShowWindow( SW_SHOW );
	m_staticString5.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );

	listParams1.ShowWindow( SW_SHOW  );
	listParams1.ResetContent();

	for ( int i=0; i<csaListEntries->GetCount(); i++)
	{
		listParams1.AddString( csaListEntries->GetAt(i) );
	}

	listParams1.SetCurSel(0);
	listParams1.ShowWindow( SW_SHOW  );
	listParams1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 40 );
}


/***************************************************************************DC

	Operation:	CAPIGenDlg::Show4E1L2E() 

	Purpose:	Sets up four edit controls + one listbox + two edit controls.

	Arguments:	csaLabels		-- the strings that are used to label each control.
				csaListEntries	-- the strings that go in the listbox

	Note:		

*****************************************************************************/
void CAPIGenDlg::Show4E1L2E( CStringArray* pcsaLabels, CStringArray* csaListEntries  )
{
	int topGroupStart=PARAM_TOP;
	int nGroupBoxHeight = 0;
	nGroupBoxHeight	= 335;

	m_groupAddParameterGroup.ShowWindow( SW_SHOW  );
	m_groupAddParameterGroup.MoveWindow( PARAM_LEFT_SIDE-15, topGroupStart-25, STANDARD_WIDTH+30, nGroupBoxHeight );

	m_staticString1.SetWindowText( pcsaLabels->GetAt( 0 ) );
	m_staticString1.ShowWindow( SW_SHOW );
	m_staticString1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
	m_EditArgument1.ShowWindow( SW_SHOW );
	m_EditArgument1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
	m_staticString2.SetWindowText( pcsaLabels->GetAt( 1 ) );
	m_staticString2.ShowWindow( SW_SHOW );
	m_staticString2.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
	m_EditArgument3.ShowWindow( SW_SHOW );
	m_EditArgument3.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
	m_staticString3.SetWindowText( pcsaLabels->GetAt( 2 ) );
	m_staticString3.ShowWindow( SW_SHOW );
	m_staticString3.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
	m_EditArgument4.ShowWindow( SW_SHOW );
	m_EditArgument4.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
	m_staticString4.SetWindowText( pcsaLabels->GetAt( 3 ) );
	m_staticString4.ShowWindow( SW_SHOW );
	m_staticString4.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
	m_EditArgument5.ShowWindow( SW_SHOW );
	m_EditArgument5.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
	m_staticString5.SetWindowText( pcsaLabels->GetAt( 4 ) );
	m_staticString5.ShowWindow( SW_SHOW );
	m_staticString5.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );

	listParams1.ShowWindow( SW_SHOW  );
	listParams1.ResetContent();

	for ( int i=0; i<csaListEntries->GetCount(); i++)
	{
		listParams1.AddString( csaListEntries->GetAt(i) );
	}

	listParams1.SetCurSel(0);
	listParams1.ShowWindow( SW_SHOW  );
	listParams1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 40 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
	m_staticString6.SetWindowText( pcsaLabels->GetAt( 5 ) );
	m_staticString6.ShowWindow( SW_SHOW );
	m_staticString6.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
	m_EditArgument6.ShowWindow( SW_SHOW );
	m_EditArgument6.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
	m_staticString7.SetWindowText( pcsaLabels->GetAt( 6 ) );
	m_staticString7.ShowWindow( SW_SHOW );
	m_staticString7.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
	m_EditArgument7.ShowWindow( SW_SHOW );
	m_EditArgument7.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

}





/***************************************************************************DC

	Operation:	CAPIGenDlg::Show4E1C() 

	Purpose:	Sets up four list controls + one checkbox.

	Arguments:	csaLabels -- the strings that are used to label each control.

	Note:		

*****************************************************************************/
void CAPIGenDlg::Show4E1C( CStringArray* pcsaLabels )
{
	int topGroupStart=PARAM_TOP;
	int nGroupBoxHeight = 0;
	nGroupBoxHeight	= 335;

	m_groupAddParameterGroup.ShowWindow( SW_SHOW  );
	m_groupAddParameterGroup.MoveWindow( PARAM_LEFT_SIDE-15, topGroupStart-25, STANDARD_WIDTH+30, nGroupBoxHeight );

	m_staticString1.SetWindowText( pcsaLabels->GetAt( 0 ) );
	m_staticString1.ShowWindow( SW_SHOW );
	m_staticString1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 22 );
	m_EditArgument1.ShowWindow( SW_SHOW );
	m_EditArgument1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
	m_staticString2.SetWindowText( pcsaLabels->GetAt( 1 ) );
	m_staticString2.ShowWindow( SW_SHOW );
	m_staticString2.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 22 );
	m_EditArgument3.ShowWindow( SW_SHOW );
	m_EditArgument3.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
	m_staticString3.SetWindowText( pcsaLabels->GetAt( 2 ) );
	m_staticString3.ShowWindow( SW_SHOW );
	m_staticString3.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 22 );
	m_EditArgument4.ShowWindow( SW_SHOW );
	m_EditArgument4.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
	m_staticString4.SetWindowText( pcsaLabels->GetAt( 3 ) );
	m_staticString4.ShowWindow( SW_SHOW );
	m_staticString4.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
	m_EditArgument5.ShowWindow( SW_SHOW );
	m_EditArgument5.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
	checkParam1.SetWindowText( pcsaLabels->GetAt( 4 ) );
	checkParam1.ShowWindow( SW_SHOW );
	checkParam1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 22 );
	checkParam1.SetCheck( BST_UNCHECKED );
}



/***************************************************************************DC

	Operation:	CAPIGenDlg::Show1E1ML() 

	Purpose:	Sets up one edit control + one multi-selection list control.

	Arguments:	csaLabels		-- the strings that are used to label each control.
				csaListEntries	-- the strings in the listbox

	Note:		

*****************************************************************************/
void CAPIGenDlg::Show1E1ML( CStringArray* pcsaLabels, CStringArray* csaListEntries  )
{
	int topGroupStart=PARAM_TOP;
	int nGroupBoxHeight = 0;
	nGroupBoxHeight	= 285;

	m_groupAddParameterGroup.ShowWindow( SW_SHOW  );
	m_groupAddParameterGroup.MoveWindow( PARAM_LEFT_SIDE-15, topGroupStart-25, STANDARD_WIDTH+30, nGroupBoxHeight );

	m_staticString1.SetWindowText( pcsaLabels->GetAt( 0 ) );
	m_staticString1.ShowWindow( SW_SHOW );
	m_staticString1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
	m_EditArgument1.ShowWindow( SW_SHOW );
	m_EditArgument1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
	m_staticString2.SetWindowText( pcsaLabels->GetAt( 1 ) );
	m_staticString2.ShowWindow( SW_SHOW );
	m_staticString2.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );

	listMultiParams1.ResetContent();
	for ( int i=0; i<csaListEntries->GetCount(); i++)
	{
		listMultiParams1.AddString( csaListEntries->GetAt(i) );
	}

	listMultiParams1.SetSel(0,TRUE);
	listMultiParams1.ShowWindow( SW_SHOW  );
	listMultiParams1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 60 );

}



/***************************************************************************DC

	Operation:	CAPIGenDlg::Show1E1ML1E1C() 

	Purpose:	Sets up one edit control + one multi-selection listbox + 
				one edit control + one checkbox.

	Arguments:	csaLabels		-- the strings that are used to label each control.
				csaListEntries	-- the strings in the listbox

	Note:		

*****************************************************************************/
void CAPIGenDlg::Show1E1ML1E1C( CStringArray* pcsaLabels, CStringArray* csaListEntries  )
{
	int topGroupStart=PARAM_TOP;
	int nGroupBoxHeight = 0;
	nGroupBoxHeight	= 315;

	m_groupAddParameterGroup.ShowWindow( SW_SHOW  );
	m_groupAddParameterGroup.MoveWindow( PARAM_LEFT_SIDE-15, topGroupStart-25, STANDARD_WIDTH+30, nGroupBoxHeight );

	m_staticString1.SetWindowText( pcsaLabels->GetAt( 0 ) );
	m_staticString1.ShowWindow( SW_SHOW );
	m_staticString1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
	m_EditArgument1.ShowWindow( SW_SHOW );
	m_EditArgument1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
	m_staticString2.SetWindowText( pcsaLabels->GetAt( 1 ) );
	m_staticString2.ShowWindow( SW_SHOW );
	m_staticString2.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );

	listMultiParams1.ResetContent();
	for ( int i=0; i<csaListEntries->GetCount(); i++)
	{
		listMultiParams1.AddString( csaListEntries->GetAt(i) );
	}

	listMultiParams1.SetSel(0,TRUE);
	listMultiParams1.ShowWindow( SW_SHOW  );
	listMultiParams1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 60 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP + 40;
	m_staticString3.SetWindowText( pcsaLabels->GetAt( 2 ) );
	m_staticString3.ShowWindow( SW_SHOW );
	m_staticString3.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
	m_EditArgument3.ShowWindow( SW_SHOW );
	m_EditArgument3.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP + 10;
	checkParam1.SetWindowText( pcsaLabels->GetAt( 3 ) );
	checkParam1.ShowWindow( SW_SHOW );
	checkParam1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 22 );


}


/***************************************************************************DC

	Operation:	CAPIGenDlg::Show2E1ML() 

	Purpose:	Sets up two list controls + one multi-selection list control.

	Arguments:	csaLabels		-- the strings that are used to label each control.
				csaListEntries	-- the strings in the listbox

	Note:		

*****************************************************************************/
void CAPIGenDlg::Show2E1ML( CStringArray* pcsaLabels, CStringArray* csaListEntries  )
{
	int topGroupStart=PARAM_TOP;
	int nGroupBoxHeight = 0;
	nGroupBoxHeight	= 335;

	m_groupAddParameterGroup.ShowWindow( SW_SHOW  );
	m_groupAddParameterGroup.MoveWindow( PARAM_LEFT_SIDE-15, topGroupStart-25, STANDARD_WIDTH+30, nGroupBoxHeight );

	m_staticString1.SetWindowText( pcsaLabels->GetAt( 0 ) );
	m_staticString1.ShowWindow( SW_SHOW );
	m_staticString1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
	m_EditArgument1.ShowWindow( SW_SHOW );
	m_EditArgument1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
	m_staticString2.SetWindowText( pcsaLabels->GetAt( 1 ) );
	m_staticString2.ShowWindow( SW_SHOW );
	m_staticString2.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
	m_EditArgument3.ShowWindow( SW_SHOW );
	m_EditArgument3.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
	m_staticString3.SetWindowText( pcsaLabels->GetAt( 2 ) );
	m_staticString3.ShowWindow( SW_SHOW );
	m_staticString3.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );

	listMultiParams1.ResetContent();
	for ( int i=0; i<csaListEntries->GetCount(); i++)
	{
		listMultiParams1.AddString( csaListEntries->GetAt(i) );
	}

	listMultiParams1.SetSel(0,TRUE);
	listMultiParams1.ShowWindow( SW_SHOW  );
	listMultiParams1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 60 );

}




/***************************************************************************DC

	Operation:	CAPIGenDlg::Show4E1C1L() 

	Purpose:	Sets up four list controls + one checkbox + one list control.

	Arguments:	csaLabels		-- the strings that are used to label each control.
				csaListEntries	-- the strings in the listbox

	Note:		

*****************************************************************************/
void CAPIGenDlg::Show4E1C1L( CStringArray* pcsaLabels, CStringArray* csaListEntries  )
{
	int topGroupStart=PARAM_TOP;
	int nGroupBoxHeight = 0;
	nGroupBoxHeight	= 335;

	m_groupAddParameterGroup.ShowWindow( SW_SHOW  );
	m_groupAddParameterGroup.MoveWindow( PARAM_LEFT_SIDE-15, topGroupStart-25, STANDARD_WIDTH+30, nGroupBoxHeight );

	m_staticString1.SetWindowText( pcsaLabels->GetAt( 0 ) );
	m_staticString1.ShowWindow( SW_SHOW );
	m_staticString1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
	m_EditArgument1.ShowWindow( SW_SHOW );
	m_EditArgument1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
	m_staticString2.SetWindowText( pcsaLabels->GetAt( 1 ) );
	m_staticString2.ShowWindow( SW_SHOW );
	m_staticString2.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
	m_EditArgument3.ShowWindow( SW_SHOW );
	m_EditArgument3.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
	m_staticString3.SetWindowText( pcsaLabels->GetAt( 2 ) );
	m_staticString3.ShowWindow( SW_SHOW );
	m_staticString3.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
	m_EditArgument4.ShowWindow( SW_SHOW );
	m_EditArgument4.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
	m_staticString4.SetWindowText( pcsaLabels->GetAt( 3 ) );
	m_staticString4.ShowWindow( SW_SHOW );
	m_staticString4.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
	m_EditArgument5.ShowWindow( SW_SHOW );
	m_EditArgument5.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP+7;
	checkParam1.SetWindowText( pcsaLabels->GetAt( 4 ) );
	checkParam1.ShowWindow( SW_SHOW );
	checkParam1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP - 12;
	m_staticString6.SetWindowText( pcsaLabels->GetAt( 5 ) );
	m_staticString6.ShowWindow( SW_SHOW );
	m_staticString6.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );

	listParams1.ShowWindow( SW_SHOW  );
	listParams1.ResetContent();

	for ( int i=0; i<csaListEntries->GetCount(); i++)
	{
		listParams1.AddString( csaListEntries->GetAt(i) );
	}

	listParams1.SetCurSel(0);
	listParams1.ShowWindow( SW_SHOW  );
	listParams1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 50 );
}



/***************************************************************************DC

	Operation:	CAPIGenDlg::Show4E1C1ML() 

	Purpose:	Sets up four list controls + one checkbox + one multi-selection
				list control.

	Arguments:	csaLabels		-- the strings that are used to label each control.
				csaListEntries	-- the strings in the listbox

	Note:		

*****************************************************************************/
void CAPIGenDlg::Show4E1C1ML( CStringArray* pcsaLabels, CStringArray* csaListEntries  )
{
	int topGroupStart=PARAM_TOP;
	int nGroupBoxHeight = 0;
	nGroupBoxHeight	= 335;

	m_groupAddParameterGroup.ShowWindow( SW_SHOW  );
	m_groupAddParameterGroup.MoveWindow( PARAM_LEFT_SIDE-15, topGroupStart-25, STANDARD_WIDTH+30, nGroupBoxHeight );

	m_staticString1.SetWindowText( pcsaLabels->GetAt( 0 ) );
	m_staticString1.ShowWindow( SW_SHOW );
	m_staticString1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 22 );
	m_EditArgument1.ShowWindow( SW_SHOW );
	m_EditArgument1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
	m_staticString2.SetWindowText( pcsaLabels->GetAt( 1 ) );
	m_staticString2.ShowWindow( SW_SHOW );
	m_staticString2.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 22 );
	m_EditArgument3.ShowWindow( SW_SHOW );
	m_EditArgument3.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
	m_staticString3.SetWindowText( pcsaLabels->GetAt( 2 ) );
	m_staticString3.ShowWindow( SW_SHOW );
	m_staticString3.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 22 );
	m_EditArgument4.ShowWindow( SW_SHOW );
	m_EditArgument4.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
	m_staticString4.SetWindowText( pcsaLabels->GetAt( 3 ) );
	m_staticString4.ShowWindow( SW_SHOW );
	m_staticString4.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
	m_EditArgument5.ShowWindow( SW_SHOW );
	m_EditArgument5.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP+7;
	checkParam1.SetWindowText( pcsaLabels->GetAt( 4 ) );
	checkParam1.ShowWindow( SW_SHOW );
	checkParam1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP - 12;
	m_staticString6.SetWindowText( pcsaLabels->GetAt( 5 ) );
	m_staticString6.ShowWindow( SW_SHOW );
	m_staticString6.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );

	listMultiParams1.ResetContent();
	for ( int i=0; i<csaListEntries->GetCount(); i++)
	{
		listMultiParams1.AddString( csaListEntries->GetAt(i) );
	}

	listMultiParams1.SetSel(0,TRUE);
	listMultiParams1.ShowWindow( SW_SHOW  );
	listMultiParams1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 50 );

}





/***************************************************************************DC

	Operation:	CAPIGenDlg::Show4E1C2E() 

	Purpose:	Sets up four list controls + one checkbox + three edit controls.

	Arguments:	csaLabels -- the strings that are used to label each control.

	Note:		

*****************************************************************************/
void CAPIGenDlg::Show4E1C2E( CStringArray* pcsaLabels )
{
	int topGroupStart=PARAM_TOP;
	int nGroupBoxHeight = 0;
	nGroupBoxHeight	= 335;

	m_groupAddParameterGroup.ShowWindow( SW_SHOW  );
	m_groupAddParameterGroup.MoveWindow( PARAM_LEFT_SIDE-15, topGroupStart-25, STANDARD_WIDTH+30, nGroupBoxHeight );

	m_staticString1.SetWindowText( pcsaLabels->GetAt( 0 ) );
	m_staticString1.ShowWindow( SW_SHOW );
	m_staticString1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
	m_EditArgument1.ShowWindow( SW_SHOW );
	m_EditArgument1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
	m_staticString2.SetWindowText( pcsaLabels->GetAt( 1 ) );
	m_staticString2.ShowWindow( SW_SHOW );
	m_staticString2.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
	m_EditArgument3.ShowWindow( SW_SHOW );
	m_EditArgument3.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
	m_staticString3.SetWindowText( pcsaLabels->GetAt( 2 ) );
	m_staticString3.ShowWindow( SW_SHOW );
	m_staticString3.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
	m_EditArgument4.ShowWindow( SW_SHOW );
	m_EditArgument4.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
	m_staticString4.SetWindowText( pcsaLabels->GetAt( 3 ) );
	m_staticString4.ShowWindow( SW_SHOW );
	m_staticString4.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
	m_EditArgument5.ShowWindow( SW_SHOW );
	m_EditArgument5.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
	checkParam1.SetWindowText( pcsaLabels->GetAt( 4 ) );
	checkParam1.ShowWindow( SW_SHOW );
	checkParam1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP - 14;
	m_staticString5.SetWindowText( pcsaLabels->GetAt( 5 ) );
	m_staticString5.ShowWindow( SW_SHOW );
	m_staticString5.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
	m_EditArgument6.ShowWindow( SW_SHOW );
	m_EditArgument6.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
	m_staticString6.SetWindowText( pcsaLabels->GetAt( 6 ) );
	m_staticString6.ShowWindow( SW_SHOW );
	m_staticString6.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
	m_EditArgument7.ShowWindow( SW_SHOW );
	m_EditArgument7.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

}




/***************************************************************************DC

	Operation:	CAPIGenDlg::Show4E2C() 

	Purpose:	Sets up four list controls + two checkboxes.

	Arguments:	csaLabels -- the strings that are used to label each control.

	Note:		

*****************************************************************************/
void CAPIGenDlg::Show4E2C( CStringArray* pcsaLabels )
{
	int topGroupStart=PARAM_TOP;
	int nGroupBoxHeight = 0;
	nGroupBoxHeight	= 335;

	m_groupAddParameterGroup.ShowWindow( SW_SHOW  );
	m_groupAddParameterGroup.MoveWindow( PARAM_LEFT_SIDE-15, topGroupStart-25, STANDARD_WIDTH+30, nGroupBoxHeight );

	m_staticString1.SetWindowText( pcsaLabels->GetAt( 0 ) );
	m_staticString1.ShowWindow( SW_SHOW );
	m_staticString1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 22 );
	m_EditArgument1.ShowWindow( SW_SHOW );
	m_EditArgument1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
	m_staticString2.SetWindowText( pcsaLabels->GetAt( 1 ) );
	m_staticString2.ShowWindow( SW_SHOW );
	m_staticString2.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 22 );
	m_EditArgument3.ShowWindow( SW_SHOW );
	m_EditArgument3.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, ROW_COL_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
	m_staticString3.SetWindowText( pcsaLabels->GetAt( 2 ) );
	m_staticString3.ShowWindow( SW_SHOW );
	m_staticString3.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 22 );
	m_EditArgument4.ShowWindow( SW_SHOW );
	m_EditArgument4.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, ROW_COL_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
	m_staticString4.SetWindowText( pcsaLabels->GetAt( 3 ) );
	m_staticString4.ShowWindow( SW_SHOW );
	m_staticString4.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
	m_EditArgument5.ShowWindow( SW_SHOW );
	m_EditArgument5.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, ROW_COL_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
	checkParam1.SetWindowText( pcsaLabels->GetAt( 4 ) );
	checkParam1.ShowWindow( SW_SHOW );
	checkParam1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP - 20;
	checkParam2.SetWindowText( pcsaLabels->GetAt( 5 ) );
	checkParam2.ShowWindow( SW_SHOW );
	checkParam2.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 22 );
}

/***************************************************************************DC

	Operation:	CAPIGenDlg::Show5E() 

	Purpose:	Sets up five edit controls

	Arguments:	csaLabels -- the strings that are used to label each control.

	Note:		

*****************************************************************************/
void CAPIGenDlg::Show5E( CStringArray* pcsaLabels )
{
	int topGroupStart=PARAM_TOP;
	int nGroupBoxHeight = 0;
	nGroupBoxHeight	= 335;

	m_groupAddParameterGroup.ShowWindow( SW_SHOW  );
	m_groupAddParameterGroup.MoveWindow( PARAM_LEFT_SIDE-15, topGroupStart-25, STANDARD_WIDTH+30, nGroupBoxHeight );

	m_staticString1.SetWindowText( pcsaLabels->GetAt( 0 ) );
	m_staticString1.ShowWindow( SW_SHOW );
	m_staticString1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
	m_EditArgument1.ShowWindow( SW_SHOW );
	m_EditArgument1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
	m_staticString2.SetWindowText( pcsaLabels->GetAt( 1 ) );
	m_staticString2.ShowWindow( SW_SHOW );
	m_staticString2.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
	m_EditArgument3.ShowWindow( SW_SHOW );
	m_EditArgument3.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, ROW_COL_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
	m_staticString3.SetWindowText( pcsaLabels->GetAt( 2 ) );
	m_staticString3.ShowWindow( SW_SHOW );
	m_staticString3.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
	m_EditArgument4.ShowWindow( SW_SHOW );
	m_EditArgument4.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, ROW_COL_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
	m_staticString4.SetWindowText( pcsaLabels->GetAt( 3 ) );
	m_staticString4.ShowWindow( SW_SHOW );
	m_staticString4.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
	m_EditArgument5.ShowWindow( SW_SHOW );
	m_EditArgument5.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, ROW_COL_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
	m_staticString5.SetWindowText( pcsaLabels->GetAt( 4 ) );
	m_staticString5.ShowWindow( SW_SHOW );
	m_staticString5.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
	m_EditArgument6.ShowWindow( SW_SHOW );
	m_EditArgument6.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, ROW_COL_WIDTH, 22 );

}




/***************************************************************************DC

	Operation:	CAPIGenDlg::Show5E1L() 

	Purpose:	Sets up three edit controls and one list control.

	Arguments:	csaLabels		-- the strings that are used to label each control.
				csaListEntries	-- the strings that go in the listbox

	Note:		

*****************************************************************************/
void CAPIGenDlg::Show5E1L( CStringArray* pcsaLabels, CStringArray* csaListEntries  )
{
	int topGroupStart=PARAM_TOP;
	int nGroupBoxHeight = 0;
	nGroupBoxHeight	= 335;

	m_groupAddParameterGroup.ShowWindow( SW_SHOW  );
	m_groupAddParameterGroup.MoveWindow( PARAM_LEFT_SIDE-15, topGroupStart-25, STANDARD_WIDTH+30, nGroupBoxHeight );

	m_staticString1.SetWindowText( pcsaLabels->GetAt( 0 ) );
	m_staticString1.ShowWindow( SW_SHOW );
	m_staticString1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
	m_EditArgument1.ShowWindow( SW_SHOW );
	m_EditArgument1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
	m_staticString2.SetWindowText( pcsaLabels->GetAt( 1 ) );
	m_staticString2.ShowWindow( SW_SHOW );
	m_staticString2.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
	m_EditArgument3.ShowWindow( SW_SHOW );
	m_EditArgument3.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, ROW_COL_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
	m_staticString3.SetWindowText( pcsaLabels->GetAt( 2 ) );
	m_staticString3.ShowWindow( SW_SHOW );
	m_staticString3.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
	m_EditArgument4.ShowWindow( SW_SHOW );
	m_EditArgument4.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, ROW_COL_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
	m_staticString4.SetWindowText( pcsaLabels->GetAt( 3 ) );
	m_staticString4.ShowWindow( SW_SHOW );
	m_staticString4.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
	m_EditArgument5.ShowWindow( SW_SHOW );
	m_EditArgument5.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, ROW_COL_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
	m_staticString5.SetWindowText( pcsaLabels->GetAt( 4 ) );
	m_staticString5.ShowWindow( SW_SHOW );
	m_staticString5.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
	m_EditArgument6.ShowWindow( SW_SHOW );
	m_EditArgument6.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, ROW_COL_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
	m_staticString6.SetWindowText( pcsaLabels->GetAt( 5 ) );
	m_staticString6.ShowWindow( SW_SHOW );
	m_staticString6.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );

	listParams1.ShowWindow( SW_SHOW  );
	listParams1.ResetContent();

	for ( int i=0; i<csaListEntries->GetCount(); i++)
	{
		listParams1.AddString( csaListEntries->GetAt(i) );
	}

	listParams1.SetCurSel(0);
	listParams1.ShowWindow( SW_SHOW  );
	listParams1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 40 );
}



/***************************************************************************DC

	Operation:	CAPIGenDlg::Show5E1C1L() 

	Purpose:	Sets up three edit controls + one checkbox + one list control.

	Arguments:	csaLabels		-- the strings that are used to label each control.
				csaListEntries	-- the strings that go in the listbox

	Note:		

*****************************************************************************/
void CAPIGenDlg::Show5E1C1L( CStringArray* pcsaLabels, CStringArray* csaListEntries  )
{
	int topGroupStart=PARAM_TOP;
	int nGroupBoxHeight = 0;
	nGroupBoxHeight	= 355;

	m_groupAddParameterGroup.ShowWindow( SW_SHOW  );
	m_groupAddParameterGroup.MoveWindow( PARAM_LEFT_SIDE-15, topGroupStart-25, STANDARD_WIDTH+30, nGroupBoxHeight );

	m_staticString1.SetWindowText( pcsaLabels->GetAt( 0 ) );
	m_staticString1.ShowWindow( SW_SHOW );
	m_staticString1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
	m_EditArgument1.ShowWindow( SW_SHOW );
	m_EditArgument1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
	m_staticString2.SetWindowText( pcsaLabels->GetAt( 1 ) );
	m_staticString2.ShowWindow( SW_SHOW );
	m_staticString2.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
	m_EditArgument3.ShowWindow( SW_SHOW );
	m_EditArgument3.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
	m_staticString3.SetWindowText( pcsaLabels->GetAt( 2 ) );
	m_staticString3.ShowWindow( SW_SHOW );
	m_staticString3.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
	m_EditArgument4.ShowWindow( SW_SHOW );
	m_EditArgument4.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
	m_staticString4.SetWindowText( pcsaLabels->GetAt( 3 ) );
	m_staticString4.ShowWindow( SW_SHOW );
	m_staticString4.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
	m_EditArgument5.ShowWindow( SW_SHOW );
	m_EditArgument5.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
	m_staticString5.SetWindowText( pcsaLabels->GetAt( 4 ) );
	m_staticString5.ShowWindow( SW_SHOW );
	m_staticString5.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
	m_EditArgument6.ShowWindow( SW_SHOW );
	m_EditArgument6.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP+7;
	checkParam1.SetWindowText( pcsaLabels->GetAt( 5 ) );
	checkParam1.ShowWindow( SW_SHOW );
	checkParam1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP - 12;
	m_staticString6.SetWindowText( pcsaLabels->GetAt( 6 ) );
	m_staticString6.ShowWindow( SW_SHOW );
	m_staticString6.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );

	listParams1.ShowWindow( SW_SHOW  );
	listParams1.ResetContent();

	for ( int i=0; i<csaListEntries->GetCount(); i++)
	{
		listParams1.AddString( csaListEntries->GetAt(i) );
	}

	listParams1.SetCurSel(0);
	listParams1.ShowWindow( SW_SHOW  );
	listParams1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 40 );
}


/***************************************************************************DC

	Operation:	CAPIGenDlg::Show5E1C1L1C() 

	Purpose:	Sets up three edit controls + one checkbox + one list control
				+ one checkbox.

	Arguments:	csaLabels		-- the strings that are used to label each control.
				csaListEntries	-- the strings that go in the listbox

	Note:		

*****************************************************************************/
void CAPIGenDlg::Show5E1C1L1C( CStringArray* pcsaLabels, CStringArray* csaListEntries  )
{
	int topGroupStart=PARAM_TOP;
	int nGroupBoxHeight = 0;
	nGroupBoxHeight	= 370;

	m_groupAddParameterGroup.ShowWindow( SW_SHOW  );
	m_groupAddParameterGroup.MoveWindow( PARAM_LEFT_SIDE-15, topGroupStart-25, STANDARD_WIDTH+30, nGroupBoxHeight );

	m_staticString1.SetWindowText( pcsaLabels->GetAt( 0 ) );
	m_staticString1.ShowWindow( SW_SHOW );
	m_staticString1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
	m_EditArgument1.ShowWindow( SW_SHOW );
	m_EditArgument1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
	m_staticString2.SetWindowText( pcsaLabels->GetAt( 1 ) );
	m_staticString2.ShowWindow( SW_SHOW );
	m_staticString2.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
	m_EditArgument3.ShowWindow( SW_SHOW );
	m_EditArgument3.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
	m_staticString3.SetWindowText( pcsaLabels->GetAt( 2 ) );
	m_staticString3.ShowWindow( SW_SHOW );
	m_staticString3.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
	m_EditArgument4.ShowWindow( SW_SHOW );
	m_EditArgument4.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
	m_staticString4.SetWindowText( pcsaLabels->GetAt( 3 ) );
	m_staticString4.ShowWindow( SW_SHOW );
	m_staticString4.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
	m_EditArgument5.ShowWindow( SW_SHOW );
	m_EditArgument5.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
	m_staticString5.SetWindowText( pcsaLabels->GetAt( 4 ) );
	m_staticString5.ShowWindow( SW_SHOW );
	m_staticString5.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
	m_EditArgument6.ShowWindow( SW_SHOW );
	m_EditArgument6.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP+4;
	checkParam1.SetWindowText( pcsaLabels->GetAt( 5 ) );
	checkParam1.ShowWindow( SW_SHOW );
	checkParam1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP - 12;
	m_staticString6.SetWindowText( pcsaLabels->GetAt( 6 ) );
	m_staticString6.ShowWindow( SW_SHOW );
	m_staticString6.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );

	listParams1.ShowWindow( SW_SHOW  );
	listParams1.ResetContent();

	for ( int i=0; i<csaListEntries->GetCount(); i++)
	{
		listParams1.AddString( csaListEntries->GetAt(i) );
	}

	listParams1.SetCurSel(0);
	listParams1.ShowWindow( SW_SHOW  );
	listParams1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 40 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP+20;
	checkParam2.SetWindowText( pcsaLabels->GetAt( 7 ) );
	checkParam2.ShowWindow( SW_SHOW );
	checkParam2.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 22 );


}





/***************************************************************************DC

	Operation:	CAPIGenDlg::Show5E1C() 

	Purpose:	Sets up three edit controls and one list control.

	Arguments:	csaLabels		-- the strings that are used to label each control.
				csaListEntries	-- the strings that go in the listbox

	Note:		

*****************************************************************************/
void CAPIGenDlg::Show5E1C( CStringArray* pcsaLabels )
{
	int topGroupStart=PARAM_TOP;
	int nGroupBoxHeight = 0;
	nGroupBoxHeight	= 335;

	m_groupAddParameterGroup.ShowWindow( SW_SHOW  );
	m_groupAddParameterGroup.MoveWindow( PARAM_LEFT_SIDE-15, topGroupStart-25, STANDARD_WIDTH+30, nGroupBoxHeight );

	m_staticString1.SetWindowText( pcsaLabels->GetAt( 0 ) );
	m_staticString1.ShowWindow( SW_SHOW );
	m_staticString1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
	m_EditArgument1.ShowWindow( SW_SHOW );
	m_EditArgument1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
	m_staticString2.SetWindowText( pcsaLabels->GetAt( 1 ) );
	m_staticString2.ShowWindow( SW_SHOW );
	m_staticString2.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
	m_EditArgument3.ShowWindow( SW_SHOW );
	m_EditArgument3.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
	m_staticString3.SetWindowText( pcsaLabels->GetAt( 2 ) );
	m_staticString3.ShowWindow( SW_SHOW );
	m_staticString3.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
	m_EditArgument4.ShowWindow( SW_SHOW );
	m_EditArgument4.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
	m_staticString4.SetWindowText( pcsaLabels->GetAt( 3 ) );
	m_staticString4.ShowWindow( SW_SHOW );
	m_staticString4.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
	m_EditArgument5.ShowWindow( SW_SHOW );
	m_EditArgument5.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
	m_staticString5.SetWindowText( pcsaLabels->GetAt( 4 ) );
	m_staticString5.ShowWindow( SW_SHOW );
	m_staticString5.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
	m_EditArgument6.ShowWindow( SW_SHOW );
	m_EditArgument6.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP - 5;
	checkParam1.SetWindowText( pcsaLabels->GetAt( 5 ) );
	checkParam1.ShowWindow( SW_SHOW );
	checkParam1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 22 );
}



/***************************************************************************DC

	Operation:	CAPIGenDlg::Show6E2L2C() 

	Purpose:	Sets up six edit controls + two listboxes + two checkboxes.

	Arguments:	csaLabels -- the strings that are used to label each control.

	Note:		

*****************************************************************************/
void CAPIGenDlg::Show6E2L2C( CStringArray* pcsaLabels, CStringArray* csaListEntries, CStringArray* csaList2Entries )
{
	int topGroupStart=PARAM_TOP;
	int nGroupBoxHeight = 0;
	int i=0;
	nGroupBoxHeight	= 525;

	m_groupAddParameterGroup.ShowWindow( SW_SHOW  );
	m_groupAddParameterGroup.MoveWindow( PARAM_LEFT_SIDE-15, topGroupStart-25, STANDARD_WIDTH+30, nGroupBoxHeight );

	m_staticString1.SetWindowText( pcsaLabels->GetAt( 0 ) );
	m_staticString1.ShowWindow( SW_SHOW );
	m_staticString1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
	m_EditArgument1.ShowWindow( SW_SHOW );
	m_EditArgument1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
	m_staticString2.SetWindowText( pcsaLabels->GetAt( 1 ) );
	m_staticString2.ShowWindow( SW_SHOW );
	m_staticString2.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
	m_EditArgument3.ShowWindow( SW_SHOW );
	m_EditArgument3.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
	m_staticString3.SetWindowText( pcsaLabels->GetAt( 2 ) );
	m_staticString3.ShowWindow( SW_SHOW );
	m_staticString3.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
	m_EditArgument4.ShowWindow( SW_SHOW );
	m_EditArgument4.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
	m_staticString4.SetWindowText( pcsaLabels->GetAt( 3 ) );
	m_staticString4.ShowWindow( SW_SHOW );
	m_staticString4.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
	m_EditArgument5.ShowWindow( SW_SHOW );
	m_EditArgument5.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
	m_staticString5.SetWindowText( pcsaLabels->GetAt( 4 ) );
	m_staticString5.ShowWindow( SW_SHOW );
	m_staticString5.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
	m_EditArgument6.ShowWindow( SW_SHOW );
	m_EditArgument6.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, ROW_COL_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
	m_staticString6.SetWindowText( pcsaLabels->GetAt( 5 ) );
	m_staticString6.ShowWindow( SW_SHOW );
	m_staticString6.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );
	m_EditArgument7.ShowWindow( SW_SHOW );
	m_EditArgument7.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, ROW_COL_WIDTH, 22 );


	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP;
	m_staticString7.SetWindowText( pcsaLabels->GetAt( 6 ) );
	m_staticString7.ShowWindow( SW_SHOW );
	m_staticString7.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );

	listParams1.ShowWindow( SW_SHOW  );
	listParams1.ResetContent();
	for ( i=0; i<csaListEntries->GetCount(); i++)
	{
		listParams1.AddString( csaListEntries->GetAt(i) );
	}
	listParams1.SetCurSel(0);
	listParams1.ShowWindow( SW_SHOW  );
	listParams1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 50 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP + 30;
	m_staticString8.SetWindowText( pcsaLabels->GetAt( 7 ) );
	m_staticString8.ShowWindow( SW_SHOW );
	m_staticString8.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 16 );

	listParams2.ShowWindow( SW_SHOW  );
	listParams2.ResetContent();
	for ( i=0; i<csaList2Entries->GetCount(); i++)
	{
		listParams2.AddString( csaList2Entries->GetAt(i) );
	}
	listParams2.SetCurSel(0);
	listParams2.ShowWindow( SW_SHOW  );
	listParams2.MoveWindow( PARAM_LEFT_SIDE, topGroupStart+STATIC_TO_CONTROL_JUMP, STANDARD_WIDTH, 60 );


	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP + 40;
	checkParam1.SetWindowText( pcsaLabels->GetAt( 8 ) );
	checkParam1.ShowWindow( SW_SHOW );
	checkParam1.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 22 );

	topGroupStart = topGroupStart + STATIC_TO_STATIC_JUMP - 20;
	checkParam2.SetWindowText( pcsaLabels->GetAt( 9 ) );
	checkParam2.ShowWindow( SW_SHOW );
	checkParam2.MoveWindow( PARAM_LEFT_SIDE, topGroupStart, STANDARD_WIDTH, 22 );

}


