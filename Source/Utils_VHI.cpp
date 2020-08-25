#include "stdafx.h"
#include "APIGen.h"
#include "APIGenDlg.h"

/****************************************************************************DC
	Function	:	CAPIGenDlg::ShowVHIControls()

	Purpose		:	Show the controls for the Extra! OLE Automation 
					function parameters.

*****************************************************************************/
void CAPIGenDlg::ShowVHIControls( int nFunction )
{
	HideParameterControls();
	csaLabels.RemoveAll();
	BOOL bYouShouldGo=TRUE;

	switch ( nFunction )
	{
		case 0:			// ConnectionTimeout
		{
			csaLabels.Add("Set timeout (vs get)");
			csaLabels.Add("Timeout value (secs)");
			bYouShouldGo=FALSE;
		}
		break;

		case 1:			// ConnectToModel
		{
			csaLabels.Add("Verastream server (DNS|IP)");
			csaLabels.Add("Verastream Model name");
			csaLabels.Add("[User ID]");
			csaLabels.Add("[Password]");
			csaLabels.Add("[Specify model variables]");
			bYouShouldGo=FALSE;
		}
		break;

		case 2:			// ConnectToModelViaDomain	
		{
			csaLabels.Add("Verastream server (DNS|IP)");
			csaLabels.Add("Verastream domain name");
			csaLabels.Add("Verastream Model name");
			csaLabels.Add("[User ID]");
			csaLabels.Add("[Password]");
			csaLabels.Add("[Specify model variables]");
			bYouShouldGo=FALSE;
		}
		break;

		case 3:			// ConnectToSession
		{
			csaLabels.Add("Verastream server (DNS or IP)");
			csaLabels.Add("Verastream session name");
			csaLabels.Add("[User ID]");
			csaLabels.Add("[Password]");
			csaLabels.Add("[Specify model variables]");
			bYouShouldGo=FALSE;
		}
		break;

		case 4:			// ConnectToSessionViaDomain
		{
			csaLabels.Add("Verastream server (DNS or IP)");
			csaLabels.Add("Verastream domain name");
			csaLabels.Add("Verastream session name");
			csaLabels.Add("[User ID]");
			csaLabels.Add("[Password]");
			csaLabels.Add("[Specify model variables]");
			bYouShouldGo=FALSE;
		}
		break;

		case 5:			// Comment
		{
			csaLabels.Add("Code comment");
		}
		break;

		case 6:			// Disconnect
		case 10:		// GetAttributeAtCursor
		case 15:		// GetCurrentEntity
		case 16:		// GetCurrentRecord
		case 17:		// GetCurrentRecordIndex
		case 18:		// GetCurrentRecordSetName
		case 25:		// GetHomeEntityName
		case 26:		// GetLastRequestID
		case 27:		// GetLocale
		case 28:		// GetLoggingLevel
		case 29:		// GetMajorVersion
		case 30:		// GetMethodTimeout
		case 31:		// GetMinorVersion
		case 32:		// GetModelEntities
		case 33:		// GetModelVariableNames
		case 34:		// GetModelVariables
		case 40:		// GetSessionID
		case 45:		// GetTableNames
		case 46:		// GetTableProcedures
		case 47:		// GetTerminalFieldAtCursor
		case 49:		// GetVersionString
		case 50:		// IsSecureConnection
		case 51:		// InsertRecord
		case 56:		// IsConnected
		case 57:		// LastErrorMessageList
		case 58:		// MetaDataOnly
		case 59:		// ModelName
		case 60:		// ModelVersionString
		case 68:		// ResumeConnection
		case 69:		// SelectCurrentRecord
		case 72:		// ServerName
		case 73:		// SessionType
		{
		}
		break;

		case 7:			// EnableTerminalAttributes
		{
			csaLabels.Add("Enable attributes");
			bYouShouldGo=FALSE;
		}
		break;

		case 8:			// ExecuteSQLStatement
		{
			// sql statement
			csaLabels.Add( "SQL statement" );
		}
		break;

		case 9:			// FetchRecords
		{
			csaLabels.Add("[Maximum rows]");
			csaLabels.Add("[Specify return fields]");
			csaLabels.Add("[Record filter]");
			bYouShouldGo=FALSE;
		}
		break;

		case 11:		// GetAttributeLocations
		case 13:		// GetAttributes
		{
			csaLabels.Add("Attribute names");
		}
		break;

		case 12:		// GetAttributeMetaData
		{
			csaLabels.Add("Entity name");
			csaLabels.Add("Attribute name");
		}
		break;

		case 14:		// GetColumnMetaData
		{
			csaLabels.Add("Table name");
			csaLabels.Add("Column name");
		}
		break;

		case 19:		// GetEntityAttributes
		case 20:		// GetEntityDescription
		case 21:		// GetEntityOperations
		case 22:		// GetEntityRecordSets
		{
			csaLabels.Add("Entity name");
		}
		break;

		case 23:		// GetFieldLocations
		{
			csaLabels.Add("Field names");
		}
		break;

		case 24:		// GetFieldMetaData
		{
			csaLabels.Add("Entity name");
			csaLabels.Add("Recordset name");
			csaLabels.Add("Field name");
		}
		break;

		case 35:		// GetOperationMetaData
		{
			csaLabels.Add("Entity name");
			csaLabels.Add("Operation name");
		}
		break;

		case 36:		// GetPatternLocations
		{
			csaLabels.Add("Pattern names");
		}
		break;

		case 37:		// GetProcedureMetaData
		{
			csaLabels.Add("Table name");
			csaLabels.Add("Procedure name");
		}
		break;

		case 38:		// GetRecordSetLocations
		{
			csaLabels.Add("Recordset names");
		}
		break;

		case 39:		// GetRecordSetMetaData
		{
			csaLabels.Add("Entity name");
			csaLabels.Add("Recordset name");
		}
		break;

		case 41:		// GetStringAtOffset
		{
			csaLabels.Add("Offset to string");
			csaLabels.Add("String length");
		}
		break;

		case 42:		// GetStringAtRowColumn
		{
			csaLabels.Add("Top row");
			csaLabels.Add("Left column");
			csaLabels.Add("Number of rows");
			csaLabels.Add("Number of columns");
		}
		break;

		case 43:		// GetTableColumns
		case 44:		// GetTableDescription
		{
			csaLabels.Add("Table name");
		}
		break;

		case 48:		// GetVariableMetaData
		{
			csaLabels.Add("Variable name");
		}
		break;

		case 52:		// InsertRecords
		{
			csaLabels.Add("Records set");
		}
		break;
		
		case 53:		// InsertStringAtCursor
		{
			csaLabels.Add("Insert string");
		}
		break;
		
		case 54:		// InsertStringAtOffset
		{
			csaLabels.Add("Insert string");
			csaLabels.Add("PS position");
		}
		break;
		
		case 55:		// InsertStringAtRowColumn
		{
			csaLabels.Add("Insert string");
			csaLabels.Add("Row");
			csaLabels.Add("Column");
		}
		break;
		
		case 61:		// MoveCurrentRecordIndex
		{
			csaLabels.Add("Movement type");
			bYouShouldGo=FALSE;
		}
		break;
		
		case 62:		// NextRecord
		{
			csaLabels.Add( "[Filter expression]" );
		}
		break;

		case 63:		// PerformAidKey
		{
			csaLabels.Add( "Aid key" );
		}
		break;

		case 64:		// PerformEntityOperation
		{
			csaLabels.Add( "Operation name" );
		}
		break;

		case 65:		// PerformTableProcedure
		{
			// table name
			csaLabels.Add( "Table name" );

			// procedure name
			csaLabels.Add( "Procedure name" );

			// data input values
			csaLabels.Add( "[Data input values]" );

			// sql statement
			csaLabels.Add( "[Filter values]" );

			// sql statement
			csaLabels.Add( "[Case sensitive filter]" );

			// sql statement
			csaLabels.Add( "[Output column names]" );

			// sql statement
			csaLabels.Add( "[Maximum rows]" );

			bYouShouldGo=FALSE;
		}
		break;

		case 66:		// ProcessString
		{
			csaLabels.Add( "String to process" );
		}
		break;

		case 67:		// RequireSecureConnection
		{
			csaLabels.Add( "Require secure connection" );
			bYouShouldGo=FALSE;
		}
		break;

		case 70:		// SelectRecordByFilter
		{
			csaLabels.Add( "Filter expression" );
		}
		break;

		case 71:		// SelectRecordByIndex
		{
			csaLabels.Add( "Record index" );
		}
		break;

		case 74:		// SetAttributes
		{
			csaLabels.Add( "Attribute name" );
			csaLabels.Add( "Attribute value" );
		}
		break;

		case 75:		// SetAttributesDelayed
		{
			csaLabels.Add( "Attribute name" );
			csaLabels.Add( "Attribute value" );
			csaLabels.Add( "Entity name" );
		}
		break;

		case 76:		// SetCurrentEntity
		{
			csaLabels.Add( "Entity name" );
		}
		break;

		case 77:		// SetCurrentRecordIndex
		{
			csaLabels.Add( "Index number" );
		}
		break;

		case 78:		// SetCurrentRecordSetByName
		{
			csaLabels.Add( "Recordset name" );
		}
		break;


		case 79:		// SetLocale
		{
			csaLabels.Add( "Locale" );
			bYouShouldGo=FALSE;
		}
		break;

		case 80:		// SetLoggingLevel
		{
			csaLabels.Add( "Logging level" );
			bYouShouldGo=FALSE;
		}
		break;

		case 81:		// SetMethodTimeout
		{
			csaLabels.Add( "Timeout (ms)" );
		}
		break;

		case 82:		// SetModelVariables
		case 84:		// UpdateCurrentRecord
		{
			csaLabels.Add( "Name" );
			csaLabels.Add( "Associated value" );
		}
		break;

		case 83:		// SuspendConnection
		{
			csaLabels.Add( "Suspend time (min)" );
		}
		break;

		case 85:		// UpdateRecordByFilter
		case 87:		// UpdateRecords
		{
			csaLabels.Add( "Name" );
			csaLabels.Add( "Associated value" );
			csaLabels.Add( "Filter expression" );
		}
		break;

		case 86:		// UpdateRecordByIndex
		{
			csaLabels.Add( "Name" );
			csaLabels.Add( "Associated value" );
			csaLabels.Add( "Index" );
		}
		break;

		case 88:		// WaitForCondition
		{
			csaLabels.Add( "Timeout (ms)" );
			csaLabels.Add( "[Expression]" );
			csaLabels.Add( "[Entity name]" );
		}
		break;

		case 89:		// WaitForCursor
		{
			csaLabels.Add( "Row" );
			csaLabels.Add( "Column" );
			csaLabels.Add( "Timeout (sec)" );
		}
		break;

		case 90:		// WaitForEntityChange
		{
			csaLabels.Add( "Entity name" );
			csaLabels.Add( "Timeout (sec)" );
		}
		break;

		case 91:		// WaitForString
		{
			csaLabels.Add( "String" );
			csaLabels.Add( "Row" );
			csaLabels.Add( "Column" );
			csaLabels.Add( "Timeout (sec)" );
		}
		break;

		case 92:		// WaitForStringRelCursor
		{
			csaLabels.Add( "String" );
			csaLabels.Add( "Cursor row offset" );
			csaLabels.Add( "Cursor column offset" );
			csaLabels.Add( "Timeout (sec)" );
		}
		break;

		case 93:		// Debug
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
		ShowMixedControls( VHI_API, nFunction, &csaLabels );	
	}

}



/****************************************************************************DC
	Function	:	CAPIGenDlg::LoadVHIArgumentArray()

	Purpose		:	Load the function arguments for OLE Automation.

*****************************************************************************/
void CAPIGenDlg::LoadVHIArgumentArray( int* nFunctionPosition, BOOL bPromptForValues )
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
			case 0:			// ConnectionTimeout
			{
				Read1C1E( &csaArguments );
			}
			break;

			case 1:			// ConnectToModel
			case 3:			// ConnectToSession
			{
				Read4E1C( &csaArguments );
			}
			break;

			case 2:	// ConnectToModelViaDomain
			case 4:	// ConnectToSessionViaDomain
			{
				Read5E1C( &csaArguments );
			}
			break;


			case 5:			// Comment
			case 8:			// ExecuteSQLStatement
			case 11:		// GetAttributeLocations
			case 13:		// GetAttributes
			case 19:		// GetEntityAttributes
			case 20:		// GetEntityDescription
			case 21:		// GetEntityOperations
			case 22:		// GetEntityRecordSets
			case 23:		// GetFieldLocations
			case 36:		// GetPatternLocations
			case 38:		// GetRecordSetLocations
			case 43:		// GetTableColumns
			case 44:		// GetTableDescription
			case 48:		// GetVariableMetaData
			case 51:		// InsertRecord
			case 52:		// InsertRecords
			case 53:		// InsertStringAtCursor
			case 62:		// NextRecord
			case 63:		// PerformAidKey
			case 64:		// PerformEntityOperation
			case 66:		// ProcessString
			{
				Read1E( &csaArguments );
			}
			break;

			case 6:			// Disconnect
			case 10:		// GetAttributeAtCursor
			case 15:		// GetCurrentEntity
			case 16:		// GetCurrentRecord
			case 17:		// GetCurrentRecordIndex
			case 18:		// GetCurrentRecordSetName
			case 25:		// GetHomeEntityName
			case 26:		// GetLastRequestID
			case 27:		// GetLocale
			case 28:		// GetLoggingLevel
			case 29:		// GetMajorVersion
			case 30:		// GetMethodTimeout
			case 31:		// GetMinorVersion
			case 32:		// GetModelEntities
			case 33:		// GetModelVariableNames
			case 34:		// GetModelVariables
			case 40:		// GetSessionID
			case 45:		// GetTableNames
			case 46:		// GetTableProcedures
			case 47:		// GetTerminalFieldAtCursor
			case 49:		// GetVersionString
			case 50:		// IsSecureConnection
			case 56:		// IsConnected
			case 57:		// LastErrorMessageList
			case 58:		// MetaDataOnly
			case 59:		// ModelName
			case 60:		// ModelVersionString
			case 68:		// ResumeConnection
			case 69:		// SelectCurrentRecord
			case 72:		// ServerName
			case 73:		// SessionType
			{
			}
			break;

			case 7:		// EnableTerminalAttributes
			case 67:	// RequireSecureConnection
			{
				Read1C( &csaArguments );
			}
			break;

			case 9:			// FetchRecords
			{
				Read1E1C1E( &csaArguments );
			}
			break;

			case 24:		// GetFieldMetaData
			case 55:		// InsertStringAtRowColumn
			case 75:		// SetAttributesDelayed
			case 85:		// UpdateRecordByFilter
			case 86:		// UpdateRecordByIndex
			case 87:		// UpdateRecords
			case 88:		// WaitForCondition
			case 89:		// WaitForCursor
			{
				Read3E( &csaArguments );
			}
			break;

			case 12:		// GetAttributeMetaData
			case 14:		// GetColumnMetaData
			case 35:		// GetOperationMetaData
			case 37:		// GetProcedureMetaData
			case 39:		// GetRecordSetMetaData
			case 41:		// GetStringAtOffset
			case 54:		// InsertStringAtOffset
			case 74:		// SetAttributes
			case 82:		// SetModelVariables
			case 84:		// UpdateCurrentRecord
			case 90:		// WaitForEntityChange
			{
				Read2E( &csaArguments );
			}
			break;

			case 42:		// GetStringAtRowColumn
			case 91:		// WaitForString
			case 92:		// WaitForStringRelCursor
			{
				Read4E( &csaArguments );
			}
			break;

			case 61:		// MoveCurrentRecordIndex
			case 79:		// SetLocale
			case 80:		// SetLoggingLevel
			{
				Read1L( &csaArguments );
			}
			break;

			case 65:		// PerformTableProcedure
			{
				Read2E4C1E( &csaArguments );
			}
			break;

			case 70:		// SelectRecordByFilter
			case 71:		// SelectRecordByIndex
			case 76:		// SetCurrentEntity
			case 77:		// SetCurrentRecordIndex
			case 78:		// SetCurrentRecordSetByName
			case 81:		// SetMethodTimeout
			case 83:		// SuspendConnection
			case 93:		// Debug
			{
				Read1E( &csaArguments );
			}
			break;

		}
	}
	else
	{
		switch ( *nFunctionPosition )
		{
			case 0:			// ConnectionTimeout
			{
				// timeout
				csaArguments.Add( "29" );
			}
			break;

			case 1:			// ConnectToModel
			{
				// server
				csaArguments.Add( "localhost" );
				// model name
				csaArguments.Add( "CCSDemo" );
				// userID
				csaArguments.Add( "djones" );
				// password
				csaArguments.Add( "summer05" );
				// model variables
				csaArguments.Add( "" );
			}
			break;

			case 2:			// ConnectToModelViaDomain	
			{
				// server
				csaArguments.Add( "localhost" );
				// domain name
				csaArguments.Add( "HomeDomain" );
				// model name
				csaArguments.Add( "CCSDemo" );
				// userID
				csaArguments.Add( "djones" );
				// password
				csaArguments.Add( "summer05" );
				// model variables
				csaArguments.Add( "FALSE" );
			}
			break;

			case 3:			// ConnectToSession
			{
				// server
				csaArguments.Add( "localhost" );
				// session name
				csaArguments.Add( "Session1" );
				// userID
				csaArguments.Add( "djones" );
				// password
				csaArguments.Add( "summer05" );
				// model variables
				csaArguments.Add( "" );
			}
			break;

			case 4:			// ConnectToSessionViaDomain
			{
				// server
				csaArguments.Add( "myServer" );
				// domain
				csaArguments.Add( "myDomain" );
				// session name
				csaArguments.Add( "Session1" );
				// userID
				csaArguments.Add( "user05" );
				// password
				csaArguments.Add( "summer05" );
				// model variables
				csaArguments.Add( "FALSE" );
			}
			break;

			case 5:		// Comment
			{
				// comment
				csaArguments.Add( "'*** User specified comment placed here" );
			}
			break;

			case 8:			// ExecuteSQLStatement
			{
				// sql statement
				csaArguments.Add( "Select OrderNum Name Date from Orders WHERE AcctNum LT \"B\"" );
			}
			break;


			case 6:			// Disconnect
			case 10:		// GetAttributeAtCursor
			case 15:		// GetCurrentEntity
			case 16:		// GetCurrentRecord
			case 17:		// GetCurrentRecordIndex
			case 18:		// GetCurrentRecordSetName
			case 25:		// GetHomeEntityName
			case 26:		// GetLastRequestID
			case 27:		// GetLocale
			case 28:		// GetLoggingLevel
			case 29:		// GetMajorVersion
			case 30:		// GetMethodTimeout
			case 31:		// GetMinorVersion
			case 32:		// GetModelEntities
			case 33:		// GetModelVariableNames
			case 34:		// GetModelVariables
			case 40:		// GetSessionID
			case 45:		// GetTableNames
			case 46:		// GetTableProcedures
			case 47:		// GetTerminalFieldAtCursor
			case 49:		// GetVersionString
			case 50:		// IsSecureConnection
			case 56:		// IsConnected
			case 57:		// LastErrorMessageList
			case 58:		// MetaDataOnly
			case 59:		// ModelName
			case 60:		// ModelVersionString
			case 68:		// ResumeConnection
			case 69:		// SelectCurrentRecord
			case 72:		// ServerName
			case 73:		// SessionType
			{

			}
			break;

			case 7:			// EnableTerminalAttributes
			{
				csaArguments.Add( "FALSE" );
			}
			break;

			case 9:			// FetchRecords
			{
				csaArguments.Add( "" );
				csaArguments.Add( "" );
				csaArguments.Add( "" );
			}
			break;

			case 11:		// GetAttributeLocations
			case 13:		// GetAttributes
			{
				csaArguments.Add( "Color1" );
			}
			break;

			case 12:		// GetAttributeMetaData
			{
				csaArguments.Add( "BusinessEntity" );
				csaArguments.Add( "ColSize" );
			}
			break;

			case 14:		// GetColumnMetaData
			{
				csaArguments.Add( "CustAccounts" );
				csaArguments.Add( "Lastname" );
			}
			break;

			case 19:		// GetEntityAttributes
			case 20:		// GetEntityDescription
			case 21:		// GetEntityOperations
			case 22:		// GetEntityRecordSets
			{
				csaArguments.Add( "BusinessEntity" );
			}
			break;

			case 23:		// GetFieldLocations
			{
				csaArguments.Add( "Lastname Firstname ZipCode" );
			}
			break;

			case 24:		// GetFieldMetaData
			{
				csaArguments.Add( "BusinessEntity" );
				csaArguments.Add( "CreditAccounts" );
				csaArguments.Add( "Lastname" );
			}
			break;

			case 35:		// GetOperationMetaData
			{
				csaArguments.Add( "BusinessEntity" );
				csaArguments.Add( "ToNameSearch" );
			}
			break;

			case 36:		// GetPatternLocations
			{
				csaArguments.Add( "WriteAttribute" );
			}
			break;

			case 37:		// GetProcedureMetaData
			{
				csaArguments.Add( "Transactions" );
				csaArguments.Add( "Get_Transactions" );
			}
			break;

			case 38:		// GetRecordSetLocations
			{
				csaArguments.Add( "OverdueAccts" );
			}
			break;

			case 39:		// GetRecordSetMetaData
			{
				csaArguments.Add( "AcctTransactions" );
				csaArguments.Add( "AcctTransData" );
			}
			break;

			case 41:		// GetStringAtOffset
			{
				csaArguments.Add( "1487" );
				csaArguments.Add( "8" );
			}
			break;

			case 42:		// GetStringAtRowColumn
			{
				csaArguments.Add( "1" );
				csaArguments.Add( "1" );
				csaArguments.Add( "5" );
				csaArguments.Add( "8" );
			}
			break;

			case 43:		// GetTableColumns
			case 44:		// GetTableDescription
			{
				csaArguments.Add( "Transactions" );
			}
			break;

			case 48:		// GetVariableMetaData
			{
				csaArguments.Add( "cursorPosition" );
			}
			break;

			case 51:		// InsertRecord
			{
				csaArguments.Add( "recordMap" );
			}
			break;

			case 52:		// InsertRecords
			{
				csaArguments.Add( "vendorRecords" );
			}
			break;

			case 53:		// InsertStringAtCursor
			{
				csaArguments.Add( "user137" );
			}
			break;

			case 54:		// InsertStringAtOffset
			{
				csaArguments.Add( "vmuser11" );
				csaArguments.Add( "1637" );
			}
			break;

			case 55:		// InsertStringAtRowColumn
			{
				csaArguments.Add( "vmuser11" );
				csaArguments.Add( "21" );
				csaArguments.Add( "37" );
			}
			break;

			case 61:		// MoveCurrentRecordIndex
			{
				csaArguments.Add( "ScrollEnd" );
			}
			break;

			case 62:		// NextRecord
			{
				csaArguments.Add( "AccTransactions.Code=E6" );
			}
			break;

			case 63:		// PerformAidKey
			{
				csaArguments.Add( "<Enter>" );
			}
			break;

			case 64:		// PerformEntityOperation
			{
				csaArguments.Add( "ToMainMenu" );
			}
			break;

			case 65:		// PerformTableProcedure
			{
				csaArguments.Add( "Transactions" );
				csaArguments.Add( "GetTransactions" );
				csaArguments.Add( "Null" );
				csaArguments.Add( "Null" );
				csaArguments.Add( "Null" );
				csaArguments.Add( "Null" );
				csaArguments.Add( "Null" );
			}
			break;

			case 66:		// ProcessString
			{
				csaArguments.Add( "RunJob22" );
			}
			break;

			case 67:		// RequireSecureConnection
			{
				csaArguments.Add( "TRUE" );
			}
			break;

			case 70:		// SelectRecordByFilter
			{
				csaArguments.Add( "AcctTransData.Code=B6" );
			}
			break;

			case 71:		// SelectRecordByIndex
			{
				csaArguments.Add( "34" );
			}
			break;

			case 74:		// SetAttributes
			{
				csaArguments.Add( "AcctNumber" );
				csaArguments.Add( "167439459" );
			}
			break;

			case 75:		// SetAttributesDelayed
			{
				csaArguments.Add( "AcctNumber" );
				csaArguments.Add( "167439459" );
				csaArguments.Add( "CustomerInquiryPanel" );
			}
			break;

			case 76:		// SetCurrentEntity
			{
				csaArguments.Add( "CustomerInquiryPanel" );
			}
			break;

			case 77:		// SetCurrentRecordIndex
			{
				csaArguments.Add( "14" );
			}
			break;

			case 78:		// SetCurrentRecordSetByName
			{
				csaArguments.Add( "AcctTransData" );
			}
			break;

			case 79:		// SetLocale
			{
				csaArguments.Add( "en_us" );
			}
			break;

			case 80:		// SetLoggingLevel
			{
				csaArguments.Add( "Errors" );
			}
			break;

			case 81:		// SetMethodTimeout
			{
				csaArguments.Add( "3200" );
			}
			break;

			case 82:		// SetModelVariables
			case 84:		// UpdateCurrentRecord
			{
				csaArguments.Add( "userID" );
				csaArguments.Add( "test1" );
			}
			break;

			case 83:		// SuspendConnection
			{
				csaArguments.Add( "2" );
			}
			break;

			case 85:		// UpdateRecordByFilter
			case 87:		// UpdateRecords
			{
				csaArguments.Add( "userID" );
				csaArguments.Add( "test1" );
				csaArguments.Add( "AcctTransData.Code=B6" );
			}
			break;

			case 86:		// UpdateRecordByIndex
			{
				csaArguments.Add( "userID" );
				csaArguments.Add( "test1" );
				csaArguments.Add( "4565" );
			}
			break;

			case 88:		// WaitForCondition
			{
				csaArguments.Add( "1000" );
				csaArguments.Add( "" );
				csaArguments.Add( "" );
			}
			break;

			case 89:		// WaitForCursor
			{
				csaArguments.Add( "10" );
				csaArguments.Add( "3" );
				csaArguments.Add( "1" );
			}
			break;

			case 90:		// WaitForEntityChange
			{
				csaArguments.Add( "Calculate" );
				csaArguments.Add( "3" );
			}
			break;

			case 91:		// WaitForString
			{
				csaArguments.Add( "USERID" );
				csaArguments.Add( "10" );
				csaArguments.Add( "3" );
				csaArguments.Add( "1" );
			}
			break;

			case 92:		// WaitForStringRelCursor
			{
				csaArguments.Add( "USERID" );
				csaArguments.Add( "7" );
				csaArguments.Add( "19" );
				csaArguments.Add( "8" );
			}
			break;

			case 93:		// Debug
			{
				csaArguments.Add( "'***** Here is a user comment" );
			}
			break;

		}
	}
}



