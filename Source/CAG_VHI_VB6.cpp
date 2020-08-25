// Static Model
#include "stdafx.h"
#include "apigen.h"

#include "CAG_VHI_VB6.h"

int cStringMaps::count = 0;

CAG_VHI_VB6::CAG_VHI_VB6()
{
	resetVariableFlags();
}

CAG_VHI_VB6::~CAG_VHI_VB6()
{
	
}


void CAG_VHI_VB6::generateHeader(CStringArray* pcsaHeader,
									 CStringArray* pcsaBody)
{
		// name and open output file if specified
	SYSTEMTIME	systime;
	GetSystemTime(&systime);
	time_t osBinaryTime;
	time( &osBinaryTime ) ;
	CTime t( osBinaryTime );
	
	int nMonth = t.GetMonth();
	int nDay = t.GetDay();
	int nYear = t.GetYear();

	CString csViewOutStuff;

	pcsaHeader->Add("' ****************************************************************************");
	pcsaHeader->Add("'           Attachmate Verastream Host Integrator");
	pcsaHeader->Add("'             APIGen Visual Basic 6.0 Application");
	pcsaHeader->Add("'" );
	pcsaHeader->Add("'   This VB 6.0 code offers a freestanding module containing the set of Verastream");
	pcsaHeader->Add("'   Host Integrator clent-side function calls specified while running the API Generator.");
	pcsaHeader->Add("'   It and others generated in that way offer development speed to the experienced" );
	pcsaHeader->Add("'   Verastream client coder, a boost to the beginner, and a source of client test code" );
	pcsaHeader->Add("'   to the Verastream model developer." );
	pcsaHeader->Add("'" );
	pcsaHeader->Add("'   You can build and run this module by following these steps:");
	pcsaHeader->Add("'   1) Ensure that Microsoft Visual Studio for Visual Basic 6.0 is installed and");
	pcsaHeader->Add("'      available on your PC.");
	pcsaHeader->Add("'   2) Install either the Verastream Host Integrator Server or its Development");
	pcsaHeader->Add("'      Toolkit.  If you choose the latter, which will use the minimal memory and");
	pcsaHeader->Add("'      disk space footprint, specify to install only the Connectors in the Setup");
	pcsaHeader->Add("'      options and you'll have the minimum for what is necessary to run this module.");
	pcsaHeader->Add("'      It'll be a good idea while running Setup to select the Help file, too.");
	pcsaHeader->Add("'   3) The VHI Com object, AppConn.dll, should be registered on your system after");
	pcsaHeader->Add("'      you installed the toolkit, but you will need to add it as a reference in your ");
	pcsaHeader->Add("'      VB 6.0 IDE.  To do so, choose the Project\\References menu item and ensure that ");
	pcsaHeader->Add("'      the checkbox next to the reference \"WRQ Verastream Host Integrator ?.? is checked.\"");
	pcsaHeader->Add("'      Version numbers will show in place of the ? wildcard characters.");
	pcsaHeader->Add("'   4) Create a new VB 6.0 project. The Standard Exe option is fine. Then choose the");
	pcsaHeader->Add("'      Project\\<project name> properties menu item to launch the Project Properties dialog.");
	pcsaHeader->Add("'      Once there, change the selection in the Startup Object list control to \"Sub Main\".");
	pcsaHeader->Add("'   5) Choose the VB 6.0 Project\\Add module menu item, click on the Existing tab");
	pcsaHeader->Add("'      and specify this .bas file.");
	pcsaHeader->Add("'   6) You can now run this within the VB 6.0 IDE or you can compile it to run as");
	pcsaHeader->Add("'      a Windows executable.");

	time_t ltime;
	time( &ltime );

	pcsaHeader->Add("'" );
	csViewOutStuff.Format( "'   Generated:   %s", ctime( &ltime ) );
	pcsaHeader->Add(csViewOutStuff);

	pcsaHeader->Add( "" );
	pcsaHeader->Add("' ****************************************************************************");

	// prompt for server address before showing declaration.  Show the default value of 150.215.72.139
	// and assign it to VHIServerAddress. It is the VHI Server that Brian Davis maintains.
	// Prompt for the model name.  Show default of "CCSDemo".
	
	pcsaHeader->Add( "" );
	pcsaHeader->Add("Dim VHI_ServerAddress As String");
	pcsaHeader->Add("Dim VHI_Model As String");

	pcsaBody->Add( "" );
	pcsaBody->Add("Sub Main()" );
	pcsaBody->Add("" );
    pcsaBody->Add(" Dim VHI_Session  As AppConnSessionEx" );
    pcsaBody->Add(" Set VHI_Session = New AppConnSessionEx" );
	pcsaBody->Add( "" );
	pcsaBody->Add( "On Error GoTo Whoops" );

}

void CAG_VHI_VB6::appendBody(int nFunctionNum,
								 bool bPromptForValues,
								 CStringArray* pcsaArguments,
								 CStringArray* pcsaHeader,
								 CStringArray* pcsaBody)
{
	CString csViewOutStuff;
	CString csFunctionName, csFunctionNum;

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

	csViewOutStuff.Format( " " );
	pcsaBody->Add(csViewOutStuff);

	csViewOutStuff.Format( "'*** %s", csFunctionName );
	pcsaBody->Add(csViewOutStuff);

	checkDebug( b_Debug, csFunctionName, pcsaBody );

	CString	csLocal;

	switch ( nFunctionNum )
	{
		case 0:		// ConnectionTimeout
		{
			if ( !b_nTimeout )
			{
				declareVariable( AG_TIMEOUT, pcsaHeader, &b_nTimeout );
			}

			if ( -1 != pcsaArguments->GetAt(1).Find("TRUE") )
			{
				csViewOutStuff.Format( "   nTimeout = %s", pcsaArguments->GetAt(2));
				pcsaBody->Add(csViewOutStuff);

				csViewOutStuff.Format( "   VHI_Session.ConnectionTimeout = nTimeout");
				pcsaBody->Add(csViewOutStuff);
			}
			else
			{
				csViewOutStuff.Format( "   nTimeout = VHI_Session.ConnectionTimeout");
				pcsaBody->Add(csViewOutStuff);
			}

		}
		break;

		case 1:			// ConnectToModel
		{
			if ( !b_csServer )
			{
				declareVariable( AG_SERVER, pcsaHeader, &b_csServer );
			}

			if ( !b_csModel )
			{
				declareVariable( AG_MODEL, pcsaHeader, &b_csModel );
			}

			if ( !b_csUserID )
			{
				declareVariable( AG_USER_ID, pcsaHeader, &b_csUserID );
			}

			if ( !b_csPassword )
			{
				declareVariable( AG_PASSWORD, pcsaHeader, &b_csPassword );
			}

			if ( !b_csaModelVariable )
			{
				declareVariable( AG_MODEL_VARIABLE, pcsaHeader, &b_csaModelVariable );
			}
			else
			{
				pcsaBody->Add( "   csaModelVariable = Nothing" );
			}

			csViewOutStuff.Format( "   csServer = \"%s\"", pcsaArguments->GetAt(1));
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "   csModel = \"%s\"", pcsaArguments->GetAt(2));
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "   csUserID = \"%s\"", pcsaArguments->GetAt(3));
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "   csPassword = \"%s\"", pcsaArguments->GetAt(4));
			pcsaBody->Add(csViewOutStuff);


			if ( -1 != pcsaArguments->GetAt(5).Find("TRUE") )
			{
				if (IDOK == stringMapDlg.DoModal())
				{
					//if ( BST_CHECKED == stringMapDlg.chkNewStringMap.GetCheck() ) skip this for now
					int nCount = stringMapDlg.csaNameValuePairs.GetCount();
					if ( nCount > 0 )
					{
						pcsaBody->Add("   Set csaModelVariable = New AppConnStringMap" );

						for ( int i=0; i< nCount/2; i++ )
						{
							csViewOutStuff.Format( "        csaModelVariable.Add \"%s\", \"%s\"", stringMapDlg.csaNameValuePairs.GetAt(2*i), stringMapDlg.csaNameValuePairs.GetAt(2*i+1) );
							pcsaBody->Add(csViewOutStuff);
						}

						stringMapDlg.csaNameValuePairs.RemoveAll();
					}

				}
			}
			else
			{
				pcsaBody->Add("   Set csaModelVariable = New AppConnStringMap" );
			}


			csViewOutStuff.Format( "");
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "   VHI_Session.ConnectToModel csServer, csModel, csUserID, csPassword, csaModelVariable");
			pcsaBody->Add(csViewOutStuff);

		}
		break;


		case 2:		// ConnectToModelViaDomain
		{
			if ( !b_csServer )
			{
				declareVariable( AG_SERVER, pcsaHeader, &b_csServer );
			}

			if ( !b_csDomain )
			{
				declareVariable( AG_DOMAIN, pcsaHeader, &b_csDomain );
			}

			if ( !b_csModel )
			{
				declareVariable( AG_MODEL, pcsaHeader, &b_csModel );
			}

			if ( !b_csUserID )
			{
				declareVariable( AG_USER_ID, pcsaHeader, &b_csUserID );
			}

			if ( !b_csPassword )
			{
				declareVariable( AG_PASSWORD, pcsaHeader, &b_csPassword );
			}

			if ( !b_csaModelVariable )
			{
				declareVariable( AG_MODEL_VARIABLE, pcsaHeader, &b_csaModelVariable );
			}
			else
			{
				pcsaBody->Add( "   csaModelVariable=nothing" );
			}

			csViewOutStuff.Format( "   csServer = \"%s\"", pcsaArguments->GetAt(1));
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "   csDomain = \"%s\"", pcsaArguments->GetAt(2));
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "   csModel = \"%s\"", pcsaArguments->GetAt(3));
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "   csUserID = \"%s\"", pcsaArguments->GetAt(4));
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "   csPassword = \"%s\"", pcsaArguments->GetAt(5));
			pcsaBody->Add(csViewOutStuff);

			if ( -1 != pcsaArguments->GetAt(6).Find("TRUE") )
			{
				if (IDOK == stringMapDlg.DoModal())
				{
					//if ( BST_CHECKED == stringMapDlg.chkNewStringMap.GetCheck() ) skip this for now
					int nCount = stringMapDlg.csaNameValuePairs.GetCount();
					if ( nCount > 0 )
					{
						pcsaBody->Add("   Set csaModelVariable = New AppConnStringMap" );

						for ( int i=0; i< nCount/2; i++ )
						{
							csViewOutStuff.Format( "        csaModelVariable.Add \"%s\", \"%s\"", stringMapDlg.csaNameValuePairs.GetAt(2*i), stringMapDlg.csaNameValuePairs.GetAt(2*i+1) );
							pcsaBody->Add(csViewOutStuff);
						}

						stringMapDlg.csaNameValuePairs.RemoveAll();
					}

				}
			}
			else
			{
				pcsaBody->Add("   csaModelVariable = New AppConnStringMap" );
			}

			csViewOutStuff.Format( "");
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "   VHI_Session.ConnectToModelViaDomain csServer, csDomain, csModel, csUserID, csPassword, csaModelVariable");
			pcsaBody->Add(csViewOutStuff);

		}
		break;

		case 3:			// ConnectToSession
		{
			if ( !b_csServer )
			{
				declareVariable( AG_SERVER, pcsaHeader, &b_csServer );
			}

			if ( !b_csSession )
			{
				declareVariable( AG_SESSION, pcsaHeader, &b_csSession );
			}

			if ( !b_csUserID )
			{
				declareVariable( AG_USER_ID, pcsaHeader, &b_csUserID );
			}

			if ( !b_csPassword )
			{
				declareVariable( AG_PASSWORD, pcsaHeader, &b_csPassword );
			}

			if ( !b_csaModelVariable )
			{
				declareVariable( AG_MODEL_VARIABLE, pcsaHeader, &b_csaModelVariable );
			}
			else
			{
				pcsaBody->Add( "   csaModelVariable=nothing" );
			}

			csViewOutStuff.Format( "   csServer = \"%s\"", pcsaArguments->GetAt(1));
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "   csSession = \"%s\"", pcsaArguments->GetAt(2));
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "   csUserID = \"%s\"", pcsaArguments->GetAt(3));
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "   csPassword = \"%s\"", pcsaArguments->GetAt(4));
			pcsaBody->Add(csViewOutStuff);


			if ( -1 != pcsaArguments->GetAt(5).Find("TRUE") )
			{
				if (IDOK == stringMapDlg.DoModal())
				{
					//if ( BST_CHECKED == stringMapDlg.chkNewStringMap.GetCheck() ) skip this for now
					int nCount = stringMapDlg.csaNameValuePairs.GetCount();
					if ( nCount > 0 )
					{
						pcsaBody->Add("   Set csaModelVariable = New AppConnStringMap" );

						for ( int i=0; i< nCount/2; i++ )
						{
							csViewOutStuff.Format( "        csaModelVariable.Add \"%s\", \"%s\"", stringMapDlg.csaNameValuePairs.GetAt(2*i), stringMapDlg.csaNameValuePairs.GetAt(2*i+1) );
							pcsaBody->Add(csViewOutStuff);
						}

						stringMapDlg.csaNameValuePairs.RemoveAll();
					}

				}
			}
			else
			{
				pcsaBody->Add("   csaModelVariable = New AppConnStringMap" );
			}


			csViewOutStuff.Format( "");
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "   VHI_Session.ConnectToSession csServer, csSession, csUserID, csPassword, csaModelVariable");
			pcsaBody->Add(csViewOutStuff);

		}
		break;

		case 4:			// ConnectToSessionViaDomain
		{
			if ( !b_csServer )
			{
				declareVariable( AG_SERVER, pcsaHeader, &b_csServer );
			}

			if ( !b_csDomain )
			{
				declareVariable( AG_DOMAIN, pcsaHeader, &b_csDomain );
			}

			if ( !b_csSession )
			{
				declareVariable( AG_SESSION, pcsaHeader, &b_csSession );
			}

			if ( !b_csUserID )
			{
				declareVariable( AG_USER_ID, pcsaHeader, &b_csUserID );
			}

			if ( !b_csPassword )
			{
				declareVariable( AG_PASSWORD, pcsaHeader, &b_csPassword );
			}

			if ( !b_csaModelVariable )
			{
				declareVariable( AG_MODEL_VARIABLE, pcsaHeader, &b_csaModelVariable );
			}
			else
			{
				pcsaBody->Add( "   csaModelVariable=nothing" );
			}

			csViewOutStuff.Format( "   csServer = \"%s\"", pcsaArguments->GetAt(1));
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "   csDomain = \"%s\"", pcsaArguments->GetAt(2));
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "   csSession = \"%s\"", pcsaArguments->GetAt(3));
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "   csUserID = \"%s\"", pcsaArguments->GetAt(4));
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "   csPassword = \"%s\"", pcsaArguments->GetAt(5));
			pcsaBody->Add(csViewOutStuff);

			if ( -1 != pcsaArguments->GetAt(6).Find("TRUE") )
			{
				if (IDOK == stringMapDlg.DoModal())
				{
					//if ( BST_CHECKED == stringMapDlg.chkNewStringMap.GetCheck() ) skip this for now
					int nCount = stringMapDlg.csaNameValuePairs.GetCount();
					if ( nCount > 0 )
					{
						pcsaBody->Add("   Set csaModelVariable = New AppConnStringMap" );

						for ( int i=0; i< nCount/2; i++ )
						{
							csViewOutStuff.Format( "        csaModelVariable.Add \"%s\", \"%s\"", stringMapDlg.csaNameValuePairs.GetAt(2*i), stringMapDlg.csaNameValuePairs.GetAt(2*i+1) );
							pcsaBody->Add(csViewOutStuff);
						}

						stringMapDlg.csaNameValuePairs.RemoveAll();
					}

				}
			}
			else
			{
				pcsaBody->Add("   csaModelVariable = New AppConnStringMap" );
			}


			csViewOutStuff.Format( "");
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "   VHI_Session.ConnectToSessionViaDomain csServer, csDomain csSession, csUserID, csPassword, csaModelVariable");
			pcsaBody->Add(csViewOutStuff);

		}
		break;

		case 5:			// Comment
		{
			csViewOutStuff.Format( "   '***** %s", pcsaArguments->GetAt(1));
			pcsaBody->Add(csViewOutStuff);
		}
		break;

		case 6:			// Disconnect
		{
			csViewOutStuff.Format( "   VHI_Session.Disconnect");
			pcsaBody->Add(csViewOutStuff);
		}
		break;


		case 7:			// EnableTerminalAttributes
		{
			csViewOutStuff.Format( "   VHI_Session.EnableTerminalAttributes %s", pcsaArguments->GetAt(1));
			pcsaBody->Add(csViewOutStuff);
		}
		break;

		case 8:			// ExecuteSQLStatement
		{
			if ( !b_csSQL )
			{
				declareVariable( AG_SQL, pcsaHeader, &b_csSQL );
			}

			csViewOutStuff.Format( "   csSQL = \"%s\"", pcsaArguments->GetAt(1));
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "   VHI_Session.ExecuteSQLStatement csSQL");
			pcsaBody->Add(csViewOutStuff);

		}
		break;

		case 9:			// FetchRecords
		{
			if ( !b_nMaxRows )
			{
				declareVariable( AG_MAX_ROWS, pcsaHeader, &b_nMaxRows );
			}

			if ( !b_csaFieldNames )
			{
				declareVariable( AG_FIELD_NAMES, pcsaHeader, &b_csaFieldNames );
			}
			else
			{
				pcsaBody->Add( "   csaFieldNames=Nothing" );
			}

			if ( !b_csFilter )
			{
				declareVariable( AG_FILTER, pcsaHeader, &b_csFilter );
			}

			if ( !b_RecordSet )
			{
				declareVariable( AG_RECORDSET, pcsaHeader, &b_RecordSet );
			}


			csViewOutStuff.Format( "   nMaxRows = %s", pcsaArguments->GetAt(1));
			pcsaBody->Add(csViewOutStuff);

			if ( -1 != pcsaArguments->GetAt(2).Find("TRUE") )
			{
				if (IDOK == stringListDlg.DoModal())
				{
					//if ( BST_CHECKED == stringListDlg.chkNewStringList.GetCheck() ) skip this for now
					int nCount = stringListDlg.csaNewStringList.GetCount();
					if ( nCount > 0 )
					{
						pcsaBody->Add("   Set csaFieldNames = New AppConnStringList" );

						for ( int i=0; i< nCount; i++ )
						{
							csViewOutStuff.Format( "        csaFieldNames.Add \"%s\"", stringListDlg.csaNewStringList.GetAt(i) );
							pcsaBody->Add(csViewOutStuff);
						}
						stringListDlg.csaNewStringList.RemoveAll();
					}
					else
					{
						pcsaBody->Add( "   csaFieldNames=Null");
					}

				}
			}
			else
			{
				pcsaBody->Add("   Set csaFieldNames = New AppConnStringList" );
			}

			csViewOutStuff.Format( "   csFilter = \"%s\"", pcsaArguments->GetAt(3));
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "");
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "   Set RecordSet = VHI_Session.FetchRecords( nMaxRows, csaFieldNames, csFilter )");
			pcsaBody->Add(csViewOutStuff);

		}
		break;


		case 10:		// GetAttributeAtCursor
		{
			if ( !b_csAttributeName )
			{
				declareVariable( AG_ATTRIBUTE_NAME, pcsaHeader, &b_csAttributeName );
			}

			csViewOutStuff.Format( "   csAttributeName = VHI_Session.GetAttributeAtCursor");
			pcsaBody->Add(csViewOutStuff);
			
		}
		break;



		case 13:	// GetAttributes
		{
			if ( !b_csaAttributeNames )
			{
				declareVariable( AG_ATTRIBUTE_NAMES, pcsaHeader, &b_csaAttributeNames );
			}
			else
			{
				pcsaBody->Add( "   csaAttributeNames=Nothing" );
			}

			if ( !b_RecordSet )
			{
				declareVariable( AG_RECORDSET, pcsaHeader, &b_RecordSet );
			}

			if ( -1 != pcsaArguments->GetAt(1).Find("TRUE") )
			{
				if (IDOK == stringListDlg.DoModal())
				{
					//if ( BST_CHECKED == stringListDlg.chkNewStringList.GetCheck() ) skip this for now
					int nCount = stringListDlg.csaNewStringList.GetCount();
					if ( nCount > 0 )
					{
						pcsaBody->Add("   Set csaAttributeNames = New AppConnStringList" );

						for ( int i=0; i< nCount; i++ )
						{
							csViewOutStuff.Format( "        csaAttributeNames.Add \"%s\"", stringListDlg.csaNewStringList.GetAt(i) );
							pcsaBody->Add(csViewOutStuff);
						}
						stringListDlg.csaNewStringList.RemoveAll();
					}
					else
					{
						pcsaBody->Add( "   csaAttributeNames=Null");
					}

				}
			}
			else
			{
				pcsaBody->Add("   Set csaAttributeNames = New AppConnStringList" );
			}

			csViewOutStuff.Format( "");
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "   Set RecordSet = VHI_Session.GetAttributes( csaAttributeNames )");
			pcsaBody->Add(csViewOutStuff);

		}
		break;

		case 51:		// InsertRecord
		{
			if ( !b_csaRecord )
			{
				declareVariable( AG_RECORDMAP, pcsaHeader, &b_csaRecord );
			}
			else
			{
				pcsaBody->Add( "   csaRecord=nothing" );
			}

			if (IDOK == stringMapDlg.DoModal())
			{
				//if ( BST_CHECKED == stringMapDlg.chkNewStringMap.GetCheck() ) skip this for now
				int nCount = stringMapDlg.csaNameValuePairs.GetCount();
				if ( nCount > 0 )
				{
					pcsaBody->Add("   Set csaRecord = New AppConnStringMap" );

					for ( int i=0; i< nCount/2; i++ )
					{
						csViewOutStuff.Format( "        csaRecord.Add \"%s\", \"%s\"", stringMapDlg.csaNameValuePairs.GetAt(2*i), stringMapDlg.csaNameValuePairs.GetAt(2*i+1) );
						pcsaBody->Add(csViewOutStuff);
					}

					stringMapDlg.csaNameValuePairs.RemoveAll();
				}

			}
			else
			{
				pcsaBody->Add( "   csaRecord=Null");
			}

			csViewOutStuff.Format( "");
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "   VHI_Session.InsertRecord csaRecord");
			pcsaBody->Add(csViewOutStuff);

		}
		break;


		case 11:		// GetAttributeLocations
		case 12:		// GetAttributeMetaData
		case 14:		// GetColumnMetaData
		case 15:		// GetCurrentEntity
		case 16:		// GetCurrentRecord
		case 17:		// GetCurrentRecordIndex
		case 18:		// GetCurrentRecordSetName
		case 19:		// GetEntityAttributes
		case 20:		// GetEntityDescription
		case 21:		// GetEntityOperations
		case 22:		// GetEntityRecordSets
		case 23:		// GetFieldLocations
		case 24:		// GetFieldMetaData
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
		case 35:		// GetOperationMetaData
		case 36:		// GetPatternLocations
		case 37:		// GetProcedureMetaData
		case 38:		// GetRecordSetLocations
		case 39:		// GetRecordSetMetaData
		case 40:		// GetSessionID
		case 41:		// GetStringAtOffset
		case 42:		// GetStringAtRowColumn
		case 43:		// GetTableColumns
		case 44:		// GetTableDescription
		case 45:		// GetTableNames
		case 46:		// GetTableProcedures
		case 47:		// GetTerminalFieldAtCursor
		case 48:		// GetVariableMetaData
		case 49:		// GetVersionString
		case 50:		// IsSecureConnection
		case 52:		// InsertRecords	//donc111605-add string map
		case 53:		// InsertStringAtCursor
		case 54:		// InsertStringAtOffset
		case 55:		// InsertStringAtRowColumn
		case 56:		// IsConnected
		case 57:		// LastErrorMessageList
		case 58:		// MetaDataOnly
		case 59:		// ModelName
		case 60:		// ModelVersionString
		case 61:		// MoveCurrentRecordIndex
		case 63:		// PerformAidKey
		case 64:		// PerformEntityOperation
		{

		}
		break;

		case 62:		// NextRecord
		{
			if ( !b_ModelRecord )
			{
				declareVariable( AG_MODEL_RECORD, pcsaHeader, &b_ModelRecord );
			}
			else
			{
				pcsaBody->Add( "   ModelRecord=nothing" );
			}

			if ( !b_csFilter )
			{
				declareVariable( AG_FILTER, pcsaHeader, &b_csFilter );
			}

			csViewOutStuff.Format( "   csFilter = \"%s\"", pcsaArguments->GetAt(1));
			pcsaBody->Add(csViewOutStuff);

			pcsaBody->Add("   Set ModelRecord = New AppConnModelRecord" );

			csViewOutStuff.Format( "");
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "   Set ModelRecord = VHI_Session.NextRecord csFilter");
			pcsaBody->Add(csViewOutStuff);
			
		}
		break;


		case 65:		// PerformTableProcedure
		{
			if ( !b_csTable )
			{
				declareVariable( AG_TABLE, pcsaHeader, &b_csTable );
			}

			if ( !b_csProcedure )
			{
				declareVariable( AG_PROCEDURE, pcsaHeader, &b_csProcedure );
			}

			if ( !b_csaDataInputValues )
			{
				declareVariable( AG_DATA_INPUT_VALUES, pcsaHeader, &b_csaDataInputValues );
			}
			else
			{
				pcsaBody->Add( "   csaDataInputValues=Nothing" );
			}

			if ( !b_csaFilterList )
			{
				declareVariable( AG_FILTER_LIST, pcsaHeader, &b_csaFilterList );
			}
			else
			{
				pcsaBody->Add( "   csaFilterList = Nothing" );
			}

			if ( !b_bCaseSensitive )
			{
				declareVariable( AG_CASE_SENSITIVE, pcsaHeader, &b_bCaseSensitive );
			}

			if ( !b_csOutputColNames )
			{
				declareVariable( AG_OUTPUT_COLNAMES, pcsaHeader, &b_csOutputColNames );
			}
			else
			{
				pcsaBody->Add( "   csOutputColNames=Nothing" );
			}

			if ( !b_nMaxRows )
			{
				declareVariable( AG_MAX_ROWS, pcsaHeader, &b_nMaxRows );
			}

			if ( !b_RecordSet )
			{
				declareVariable( AG_RECORDSET, pcsaHeader, &b_RecordSet );
			}



			csViewOutStuff.Format( "   csTable = \"%s\"", pcsaArguments->GetAt(1));
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "   csProcedure = \"%s\"", pcsaArguments->GetAt(2));
			pcsaBody->Add(csViewOutStuff);


			if ( -1 != pcsaArguments->GetAt(3).Find("TRUE") )
			{
				if (IDOK == stringMapDlg.DoModal())
				{
					//if ( BST_CHECKED == stringMapDlg.chkNewStringMap.GetCheck() ) skip this for now
					int nCount = stringMapDlg.csaNameValuePairs.GetCount();
					if ( nCount > 0 )
					{
						pcsaBody->Add("   Set csaDataInputValues = New AppConnStringMap" );

						for ( int i=0; i< nCount/2; i++ )
						{
							csViewOutStuff.Format( "        csaDataInputValues.Add \"%s\", \"%s\"", stringMapDlg.csaNameValuePairs.GetAt(2*i), stringMapDlg.csaNameValuePairs.GetAt(2*i+1) );
							pcsaBody->Add(csViewOutStuff);
						}
						stringMapDlg.csaNameValuePairs.RemoveAll();
					}
					else
					{
						pcsaBody->Add( "   csaDataInputValues=Null");
					}

				}
			}
			else
			{
				pcsaBody->Add("   Set csaDataInputValues = New AppConnStringMap" );
			}


			if ( -1 != pcsaArguments->GetAt(4).Find("TRUE") )
			{
				if (IDOK == stringMapDlg.DoModal())
				{
					//if ( BST_CHECKED == stringMapDlg.chkNewStringMap.GetCheck() ) skip this for now
					int nCount = stringMapDlg.csaNameValuePairs.GetCount();
					if ( nCount > 0 )
					{
						pcsaBody->Add("   Set csaFilterList = New AppConnStringMap" );

						for ( int i=0; i< nCount/2; i++ )
						{
							csViewOutStuff.Format( "        csaFilterList.Add \"%s\", \"%s\"", stringMapDlg.csaNameValuePairs.GetAt(2*i), stringMapDlg.csaNameValuePairs.GetAt(2*i+1) );
							pcsaBody->Add(csViewOutStuff);
						}
						stringMapDlg.csaNameValuePairs.RemoveAll();
					}
					else
					{
						pcsaBody->Add( "   csaFilterList=Null");
					}

				}
			}
			else
			{
				pcsaBody->Add("   csaFilterList=Null" );
			}


			csViewOutStuff.Format( "   bCaseSensitive = %s", pcsaArguments->GetAt(5));
			pcsaBody->Add(csViewOutStuff);


			if ( -1 != pcsaArguments->GetAt(6).Find("TRUE") )
			{
				if (IDOK == stringListDlg.DoModal())
				{
					//if ( BST_CHECKED == stringListDlg.chkNewStringList.GetCheck() ) skip this for now
					int nCount = stringListDlg.csaNewStringList.GetCount();
					if ( nCount > 0 )
					{
						pcsaBody->Add("   Set csOutputColNames = New AppConnStringList" );

						for ( int i=0; i< nCount; i++ )
						{
							csViewOutStuff.Format( "        csOutputColNames.Add \"%s\"", stringListDlg.csaNewStringList.GetAt(i) );
							pcsaBody->Add(csViewOutStuff);
						}
						stringListDlg.csaNewStringList.RemoveAll();
					}
					else
					{
						pcsaBody->Add( "   csOutputColNames=Null");
					}

				}
			}
			else
			{
				pcsaBody->Add("   Set csOutputColNames = New AppConnStringList" );
			}


			if ( 0 == pcsaArguments->GetAt(7).GetLength() )
			{
				csViewOutStuff.Format( "   nMaxRows = 0", pcsaArguments->GetAt(7));
				pcsaBody->Add(csViewOutStuff);
			}
			else
			{
				csViewOutStuff.Format( "   nMaxRows = %s", pcsaArguments->GetAt(7));
				pcsaBody->Add(csViewOutStuff);
			}

			csViewOutStuff.Format( "");
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "   Set RecordSet = VHI_Session.PerformTableProcedure( csTable, csProcedure, csaDataInputValues, csaFilterList, bCaseSensitive, csOutputColNames, nMaxRows )");
			pcsaBody->Add(csViewOutStuff);

		}
		break;

		case 74:		// SetAttributes
		{
			if ( !b_csaAttributes )
			{
				declareVariable( AG_ATTRIBUTE_ARRAY, pcsaHeader, &b_csaAttributes );
			}
			else
			{
				pcsaBody->Add( "   csaAttributes=nothing" );
			}

			if (IDOK == stringMapDlg.DoModal())
			{
				//if ( BST_CHECKED == stringMapDlg.chkNewStringMap.GetCheck() ) skip this for now
				int nCount = stringMapDlg.csaNameValuePairs.GetCount();
				if ( nCount > 0 )
				{
					pcsaBody->Add("   Set csaAttributes = New AppConnStringMap" );

					for ( int i=0; i< nCount/2; i++ )
					{
						csViewOutStuff.Format( "        csaAttributes.Add \"%s\", \"%s\"", stringMapDlg.csaNameValuePairs.GetAt(2*i), stringMapDlg.csaNameValuePairs.GetAt(2*i+1) );
						pcsaBody->Add(csViewOutStuff);
					}
					stringMapDlg.csaNameValuePairs.RemoveAll();
				}
				else
				{
					pcsaBody->Add( "   csaAttributes=Null");
				}

			}

			csViewOutStuff.Format( "");
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "   VHI_Session.SetAttributes csaAttributes");
			pcsaBody->Add(csViewOutStuff);
			
		}
		break;

		case 66:		// ProcessString
		case 67:		// RequireSecureConnection
		case 68:		// ResumeConnection
		case 69:		// SelectCurrentRecord
		case 70:		// SelectRecordByFilter
		case 71:		// SelectRecordByIndex
		case 72:		// ServerName
		case 73:		// SessionType
		case 75:		// SetAttributesDelayed		// *** Insert AppConnStringMap
		case 76:		// SetCurrentEntity
		case 77:		// SetCurrentRecordIndex
		case 78:		// SetCurrentRecordSetByName
		case 79:		// SetLocale
		case 80:		// SetLoggingLevel
		case 81:		// SetMethodTimeout
		case 82:		// SetModelVariables		// *** Insert AppConnStringMap
		case 83:		// SuspendConnection
		case 84:		// UpdateCurrentRecord		// *** Insert AppConnStringMap
		case 85:		// UpdateRecordByFilter		// *** Insert AppConnStringMap
		case 86:		// UpdateRecordByIndex		// *** Insert AppConnStringMap
		case 87:		// UpdateRecords			// *** Insert AppConnStringMap
		case 88:		// WaitForCondition
		case 89:		// WaitForCursor
		case 90:		// WaitForEntityChange
		case 91:		// WaitForString
		case 92:		// WaitForStringRelCursor
		case 93:		// Debug
		{
		}
		break;
	}

	pcsaArguments->RemoveAll();
}


void CAG_VHI_VB6::finalize(CStringArray* pcsaBody)
{
	pcsaBody->Add( "" );
	pcsaBody->Add( "" );
	pcsaBody->Add( "   Set VHI_Session = Nothing" );
	pcsaBody->Add( "" );
	pcsaBody->Add( "   Exit Sub" );
	pcsaBody->Add( " " );
	pcsaBody->Add( "Whoops:" );
	pcsaBody->Add( "   MsgBox Err.Description, vbOKOnly, \"Whoops\"" );
	pcsaBody->Add( "" );
	pcsaBody->Add( "End Sub" );

}



void CAG_VHI_VB6::declareVariable(AG_VARIABLE agVariable,
									  CStringArray* pcsaHeader,
									  bool* bValue)
{
	CString csLocal;
	*bValue = TRUE;
	
	switch ( agVariable )
	{
		case AG_STRING:
		{
			csLocal.Format( "Dim cString");
		}
		break;

		case AG_STATUS:
		{
			csLocal.Format( "Dim nStatus");
		}
		break;

		case AG_UPDATED:
		{
			csLocal.Format( "Dim bUpdated");
		}
		break;

		case AG_BSTR:
		{
			csLocal.Format( "Dim v");
		}
		break;
	
		case AG_COMMAND:
		{
			csLocal.Format( "Dim csCommand");
		}
		break;

		case AG_ENDCOLUMN:
		{
			csLocal.Format( "Dim nEndColumn");
		}
		break;

		case AG_ENDROW:
		{
			csLocal.Format( "Dim nEndRow");
		}
		break;

		case AG_ROW:
		{
			csLocal.Format( "Dim nRow");
		}
		break;

		case AG_COLUMN:
		{
			csLocal.Format( "Dim nColumn");		
		}
		break;

		case AG_ATTRIBUTE:
		{
			csLocal.Format( "Dim nAttribute");
		}
		break;

		
		case AG_ATTRIBUTE_ARRAY:
		{
			csLocal.Format( "Dim csaAttributes As AppConnStringMap");
		}
		break;


		case AG_LENGTH:
		{
			csLocal.Format( "Dim nLength");
		}
		break;

		case AG_VALUE:
		{
			csLocal.Format( "Dim nValue");
		}
		break;

		case AG_RETURN:
		{
			csLocal.Format( "Dim bRet");
		}
		break;

		case AG_CLOSEOPTION:
		{
			csLocal.Format( "Dim nCloseOption");
		}
		break;

		case AG_FT_OBJ:
		{
			csLocal.Format( "Dim ftObj");
		}
		break;

		case AG_HOSTNAME:
		{
			csLocal.Format( "Dim hostname");
		}
		break;

		case AG_HOST_OS:
		{
			csLocal.Format( "Dim nFTHostOS");
		}
		break;

		case AG_HEIGHT:
		{
			csLocal.Format( "Dim nHeight");
		}
		break;

		case AG_LOCALMODE:
		{
			csLocal.Format( "Dim bLocalMode");
		}
		break;

		case AG_SCREEN_HELD:
		{
			csLocal.Format( "Dim bScreenHeld");
		}
		break;

		case AG_SESS_SAVED:
		{
			csLocal.Format( "Dim bSessionSaved");
		}
		break;

		case AG_SESSIONS_CREATED:
		{
			csLocal.Format( "Dim Sessions" );
		}
		break;

		case AG_SESS_OPEN:
		{
			csLocal.Format( "Dim SessName");
		}
		break;


		case AG_SETTLE_TIME:
		{
			csLocal.Format( "Dim nSettleTime");
		}
		break;

		case AG_SESS_QUIET:
		{
			csLocal.Format( "Dim bSessionQuiet");
		}
		break;

		case AG_SETTINGS_PAGE:
		{
			csLocal.Format( "Dim settingsPage");
		}
		break;

		case AG_SETTINGS_TAB:
		{
			csLocal.Format( "Dim settingsTab");
		}
		break;

		case AG_MENU_VISIBLE:
		{
			csLocal.Format( "Dim bMenuVisible");
		}
		break;

		case AG_IDLE_TIME:
		{
			csLocal.Format( "Dim nIdle");
		}
		break;

		case AG_OPTIONS:
		{
			csLocal.Format( "Dim nOptions");
		}
		break;

		case AG_PAGE:
		{
			csLocal.Format( "Dim nPage");
		}
		break;

		case AG_TYPE:
		{
			csLocal.Format( "Dim nType");
		}
		break;

		case AG_TIMEOUT:
		{
			csLocal.Format( "Dim nTimeout");
		}
		break;

		case AG_PROCESS:
		{
			csLocal.Format( "Dim bProcess");
		}
		break;

		case AG_PROCESS_KEYSTROKES:
		{
			csLocal.Format( "Dim sKeys");
		}
		break;

		case AG_WIDTH:
		{
			csLocal.Format( "Dim nWidth");
		}
		break;

		case AG_WINDOW_HANDLE:
		{
			csLocal.Format( "Dim hSession");
			//csLocal.Format( "HANDLE hSession=NULL");
		}
		break;

		case AG_WINDOW_STATE:
		{
			csLocal.Format( "Dim nWindowState");
		}
		break;

		case AG_COUNT:
		{
			csLocal.Format( "Dim nCount");
		}
		break;

		case AG_AREA:
		{
			csLocal.Format( "Dim Area");
		}
		break;

		case AG_DOMAIN:
		{
			csLocal.Format( "Dim csDomain" );
		}
		break;

		case AG_EVENT:
		{
			csLocal.Format( "Dim nEventNum" );
		}
		break;

		case AG_FONTNAME:
		{
			csLocal.Format( "Dim font" );
		}
		break;

		case AG_FIELD_NAMES:
		{
			csLocal.Format( "Dim csaFieldNames" );
		}
		break;

		case AG_FT_SCHEME:
		{
			csLocal.Format( "Dim FTScheme" );
		}
		break;

		// new stuff
		case AG_NAME:
		{
			csLocal.Format( "Dim csName" );
		}
		break;

		case AG_TERMINAL:
		{
			csLocal.Format( "Dim Terminal" );
		}
		break;

		case AG_OIAOBJ:
		{
			csLocal.Format( "Dim OIAObj" );
		}
		break;

		case AG_TEXT:
		{
			csLocal.Format( "Dim cText" );
		}
		break;

		case AG_EAB:
		{
			csLocal.Format( "Dim bEABs" );
		}
		break;

		case AG_HOST_CHARSET:
		{
			csLocal.Format( "Dim nCharSet" );
		}
		break;

		case AG_HOST_CODEPAGE:
		{
			csLocal.Format( "Dim nHostCodePage" );
		}
		break;

		case AG_KBD_LOCKED:
		{
			csLocal.Format( "Dim bKeyboardLocked" );
		}
		break;

		case AG_MODEL:	
		{
			csLocal.Format( "Dim csModel" );
		}
		break;

		case AG_MODEL_VARIABLE:	
		{
			csLocal.Format( "Dim csaModelVariable As AppConnStringMap" );
		}
		break;

		case AG_SERVER:	
		{
			csLocal.Format( "Dim csServer" );
		}
		break;

		case AG_SQL:	
		{
			csLocal.Format( "Dim csSQL" );
		}
		break;

		case AG_MODE:
		{
			csLocal.Format( "Dim nMode" );
		}
		break;

		case AG_WAIT:
		{
			csLocal.Format( "Dim nWait" );
		}
		break;

		case AG_ATTACHED:
		{
			csLocal.Format( "Dim bAttached" );
		}
		break;

		case AG_CONNECTED:
		{
			csLocal.Format( "Dim bConnected" );
		}
		break;

		case AG_CONNECTION_OBJ:
		{
			csLocal.Format( "Dim conn" );
		}
		break;

		case AG_SCREEN_OBJ:
		{
			csLocal.Format( "Dim screen" );
		}
		break;

		case AG_STATE:
		{
			csLocal.Format( "Dim nState" );
		}
		break;

		case AG_PORT:
		{
			csLocal.Format( "Dim nPort" );
		}
		break;

		case AG_KEY:
		{
			csLocal.Format( "Dim nKey" );
		}
		break;

		case AG_SESSION:
		{
			csLocal.Format( "Dim csSession" );
		}
		break;

		case AG_TABLE:
		{
			csLocal.Format( "Dim csTable" );
		}
		break;

		case AG_PROCEDURE:
		{
			csLocal.Format( "Dim csProcedure" );
		}
		break;

		case AG_DATA_INPUT_VALUES:
		{
			csLocal.Format( "Dim csaDataInputValues As AppConnStringMap" );
		}
		break;

		case AG_FILTER:
		{
			csLocal.Format( "Dim csFilter" );
		}
		break;

		case AG_FILTER_LIST:
		{
			csLocal.Format( "Dim csaFilterList As AppConnStringMap" );
		}
		break;

		case AG_CASE_SENSITIVE:
		{
			csLocal.Format( "Dim bCaseSensitive" );
		}
		break;

		case AG_OUTPUT_COLNAMES:
		{
			csLocal.Format( "Dim csOutputColNames As AppConnStringList" );
		}
		break;

		case AG_MAX_ROWS:
		{
			csLocal.Format( "Dim nMaxRows" );
		}
		break;

		case AG_USER_ID:
		{
			csLocal.Format( "Dim csUserID As String" );
		}
		break;

		case AG_PASSWORD:
		{
			csLocal.Format( "Dim csPassword As String" );
		}
		break;
	
		case AG_RECORDMAP:
		{
			csLocal.Format( "Dim csaRecord As AppConnStringMap" );
		}
		break;

		case AG_RECORDSET:
		{
			csLocal.Format( "Dim RecordSet As AppConnRecordSet" );
		}
		break;

		case AG_ATTRIBUTE_NAME:
		{
			csLocal.Format( "Dim csAttributeName");
		}
		break;

		case AG_ATTRIBUTE_NAMES:
		{
			csLocal.Format( "Dim csaAttributeNames As AppConnStringList" );
		}
		break;

		case AG_MODEL_RECORD:
		{
			csLocal.Format( "Dim ModelRecord As AppConnModelRecord" );
		}
		break;

	}

	pcsaHeader->Add(csLocal);
	
}

void CAG_VHI_VB6::checkDebug(bool b_Debug,
							   CString csFunctionName,
							   CStringArray* pcsaBody)
{
	CString csLocal;
	
	if ( b_Debug )
	{
		csLocal.Format( "MsgBox \"%s\"", csFunctionName );
		pcsaBody->Add(csLocal);
	}
}


void CAG_VHI_VB6::resetVariableFlags()
{
	b_AppConnRecord=FALSE;
	b_bCaseSensitive=FALSE;
	b_csDomain=FALSE;
	b_bRet=FALSE;
	b_csCommand=FALSE;
	b_csAttributeName=FALSE;
	b_csaAttributes=FALSE;
	b_csaDataInputValues=FALSE;
	b_csaFieldNames=FALSE;
	b_csaRecord=FALSE;
	b_csFilter=FALSE;
	b_csaFilterList=FALSE;
	b_csModel=FALSE;
	b_csaModelVariable=FALSE;
	b_csName=FALSE;
	b_csOutputColNames=FALSE;
	b_csPassword=FALSE;
	b_csProcedure=FALSE;
	b_csSession=FALSE;
	b_csServer=FALSE;
	b_csSQL=FALSE;
	b_csTable=FALSE;
	b_cString=FALSE;
	b_csUserID=FALSE;
	b_Debug=FALSE;
	b_hostname=FALSE;
	b_hSession=FALSE;
	b_ModelRecord=FALSE;
	b_nAttribute=FALSE;
	b_nCharSet=FALSE;
	b_nColumn=FALSE;
	b_nCount=FALSE;
	b_nEndColumn=FALSE;
	b_nEndRow=FALSE;
	b_nEventNum=FALSE;
	b_nHeight=FALSE;
	b_nHostCodePage=FALSE;
	b_nHostOS=FALSE;
	b_nIdle=FALSE;
	b_nIdleTime=FALSE;
	b_nKey=FALSE;
	b_nLength=FALSE;
	b_nMaxRows=FALSE;
	b_nMode=FALSE;
	b_nModel=FALSE;
	b_nOptions=FALSE;
	b_nPort=FALSE;
	b_RecordSet=FALSE;
	b_nRow=FALSE;
	b_nSettleTime=FALSE;
	b_nState=FALSE;
	b_nStatus=FALSE;
	b_nTimeout=FALSE;
	b_nType=FALSE;
	b_nWait=FALSE;
	b_nWidth=FALSE;
	b_nWindowState=FALSE;
	b_RecordSet=FALSE;
	b_SessName=FALSE;
	b_settingsPage=FALSE;
	b_settingsTab=FALSE;
	b_sKeys=FALSE;
	b_Terminal=FALSE;
}


cStringMaps::cStringMaps()
{
	
}

cStringMaps::~cStringMaps()
{
	
}
