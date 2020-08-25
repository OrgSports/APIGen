// Static Model
#include "stdafx.h"
#include "apigen.h"

#include "CAG_PERFORCE.h"


CAG_PERFORCE::CAG_PERFORCE()
{
	APIFlavor=PERFORCE_API;
	resetVariableFlags();
}

CAG_PERFORCE::~CAG_PERFORCE()
{
	
}

void CAG_PERFORCE::loadFunctionList(CListBox* listTranslateFunction)
{
	csaFunctions.RemoveAll();

	csaFunctions.Add("add");
	csaFunctions.Add("admin");
	csaFunctions.Add("annotate");
	csaFunctions.Add("branch");
	csaFunctions.Add("branches");
	csaFunctions.Add("change");
	csaFunctions.Add("changelists");
	csaFunctions.Add("changelist");
	csaFunctions.Add("changes");
	csaFunctions.Add("client");
	csaFunctions.Add("clients");
	csaFunctions.Add("counter");
	csaFunctions.Add("counters");
	csaFunctions.Add("delete");
	csaFunctions.Add("depot");
	csaFunctions.Add("depots");
	csaFunctions.Add("describe");
	csaFunctions.Add("diff");
	csaFunctions.Add("diff2");
	csaFunctions.Add("dirs");
	csaFunctions.Add("edit");
	csaFunctions.Add("filelog");
	csaFunctions.Add("files");
	csaFunctions.Add("fix");
	csaFunctions.Add("fixes");
	csaFunctions.Add("flush");
	csaFunctions.Add("fstat");
	csaFunctions.Add("group");
	csaFunctions.Add("groups");
	csaFunctions.Add("have");
	csaFunctions.Add("help");
	csaFunctions.Add("info");
	csaFunctions.Add("integrate");
	csaFunctions.Add("integrated");
	csaFunctions.Add("job");
	csaFunctions.Add("jobs");
	csaFunctions.Add("jobspec");
	csaFunctions.Add("label");
	csaFunctions.Add("labels");
	csaFunctions.Add("labelsync");
	csaFunctions.Add("lock");
	csaFunctions.Add("logger");
	csaFunctions.Add("login");
	csaFunctions.Add("logout");
	csaFunctions.Add("monitor");
	csaFunctions.Add("obliterate");
	csaFunctions.Add("opened");
	csaFunctions.Add("passwd");
	csaFunctions.Add("print");
	csaFunctions.Add("protect");
	csaFunctions.Add("rename");
	csaFunctions.Add("reopen");
	csaFunctions.Add("resolve");
	csaFunctions.Add("resolved");
	csaFunctions.Add("revert");
	csaFunctions.Add("review");
	csaFunctions.Add("reviews");
	csaFunctions.Add("set");
	csaFunctions.Add("submit");
	csaFunctions.Add("sync");
	csaFunctions.Add("tag");
	csaFunctions.Add("tickets");
	csaFunctions.Add("triggers");
	csaFunctions.Add("typemap");
	csaFunctions.Add("unlock");
	csaFunctions.Add("user");
	csaFunctions.Add("users");
	csaFunctions.Add("verify");
	csaFunctions.Add("where");
	csaFunctions.Add("workspace");
	csaFunctions.Add("workspaces");
	
	listTranslateFunction->ResetContent();	
	
	for (int k=0; k<csaFunctions.GetSize(); k++)
	{
		listTranslateFunction->AddString( csaFunctions.GetAt(k) );
	}

	listTranslateFunction->SetCurSel(0);
	
}


void CAG_PERFORCE::loadLanguageList(CListBox* listTranslateLanguage)
{
	int nPos = 0;

	listTranslateLanguage->ResetContent();
	listTranslateLanguage->InsertString( nPos++, "P4 commands" );
	
	listTranslateLanguage->SetCurSel(0);
	
}

void CAG_PERFORCE::checkDebug(bool b_Debug,
						 CString csFunctionName,
						 CStringArray* pcsaBody)
{
	
}

void CAG_PERFORCE::generateHeader(CStringArray* pcsaHeader,
							 CStringArray* pcsaBody)
{

	CString csViewOutStuff;

	pcsaHeader->Add("****************************************************************************");
	pcsaHeader->Add("                    Attachmate APIGen");
	pcsaHeader->Add("                   Perforce P4 Command File");
	pcsaHeader->Add("");
	pcsaHeader->Add("       This batch file features the use of Perforce P4 commands.");
	pcsaHeader->Add("");

	time_t ltime;
	time( &ltime );

	pcsaHeader->Add("");

	csViewOutStuff.Format( "   Generated:   %s", ctime( &ltime ) );
	pcsaHeader->Add(csViewOutStuff);

	pcsaHeader->Add("****************************************************************************");
	pcsaHeader->Add("");
}



void CAG_PERFORCE::appendBody(int nFunctionNum,
						 bool bPromptForValues,
						 CStringArray* pcsaArguments,
						 CStringArray* pcsaHeader,
						 CStringArray* pcsaBody)
{
	CString csViewOutStuff;
	CString csFunctionName;
	CString csParam1, csParam2, csParam3;

	csFunctionName = pcsaArguments->GetAt( 0 );

	csViewOutStuff.Format( " " );
	pcsaBody->Add(csViewOutStuff);

	csViewOutStuff.Format( ";  ****** %s", csFunctionName );
	pcsaBody->Add(csViewOutStuff);

	CString csGlobalSettings, csChangeList, csFileType, csWildCards;
	// global settings
	if ( "TRUE" == pcsaArguments->GetAt(1) )
	{
		if (IDOK == P4GlobalSettingsDlg.DoModal())
		{
			if ( P4GlobalSettingsDlg.bClientName && 0<P4GlobalSettingsDlg.csClientName.GetLength() )
			{
				csGlobalSettings += "-c" + P4GlobalSettingsDlg.csClientName + " ";
			}

			if ( P4GlobalSettingsDlg.bWorkingDir && 0<P4GlobalSettingsDlg.csWorkingDir.GetLength() )
			{
				csGlobalSettings += " -d" + P4GlobalSettingsDlg.csWorkingDir + " ";
			}

			if ( P4GlobalSettingsDlg.bFormatOutput )
			{
				csGlobalSettings += "-G ";
			}

			if ( P4GlobalSettingsDlg.bHostName && 0<P4GlobalSettingsDlg.csHostName.GetLength() )
			{
				csGlobalSettings += "-H" + P4GlobalSettingsDlg.csHostName + " ";
			}

			if ( P4GlobalSettingsDlg.bPort && 0<P4GlobalSettingsDlg.csPortNumber.GetLength() )
			{
				csGlobalSettings += "-p" + P4GlobalSettingsDlg.csPortNumber + " ";
			}

			if ( P4GlobalSettingsDlg.bPassword && 0<P4GlobalSettingsDlg.csPassword.GetLength() )
			{
				csGlobalSettings += "-P" + P4GlobalSettingsDlg.csPassword + " ";
			}

			if ( P4GlobalSettingsDlg.bPrependLines )
			{
				csGlobalSettings += "-s ";
			}

			if ( P4GlobalSettingsDlg.bUserName && 0<P4GlobalSettingsDlg.csUserName.GetLength() )
			{
				csGlobalSettings += "-u" + P4GlobalSettingsDlg.csUserName + " ";
			}

			if ( P4GlobalSettingsDlg.bInputFile && 0<P4GlobalSettingsDlg.csFileName.GetLength() )
			{
				csGlobalSettings += "-x" + P4GlobalSettingsDlg.csFileName + " ";
			}

			if ( P4GlobalSettingsDlg.bCharSet && 0<P4GlobalSettingsDlg.csCharSet.GetLength() )
			{
				csGlobalSettings += "-C" + P4GlobalSettingsDlg.csCharSet + " ";
			}

			if ( P4GlobalSettingsDlg.bP4Version )
			{
				csGlobalSettings += "-V ";
			}

			if ( P4GlobalSettingsDlg.bDisplayHelpInfo )
			{
				csGlobalSettings += "-h ";
			}

		}

	}	


	switch ( nFunctionNum )
	{
		case 0:	//add
		{
			// changelist
			if ( 0<pcsaArguments->GetAt(2).GetLength() )
			{
				csChangeList = "-c " + pcsaArguments->GetAt(2);
			}
			else
			{
				csChangeList = "";
			}

			// file type
			bool bFileType=FALSE;
			if ( -1 == pcsaArguments->GetAt(3).Find("none") )
			{
				csFileType = pcsaArguments->GetAt(3);
				bFileType=TRUE;
			}

			if ( bFileType )
			{
				if ( -1 == pcsaArguments->GetAt(4).Find("none") )
				{
					if ( -1 != pcsaArguments->GetAt(4).Find("Writable") )
					{
						csFileType += " +w";
					}

					if ( -1 != pcsaArguments->GetAt(4).Find("Execute") )
					{
						csFileType += " +x";
					}

					if ( -1 != pcsaArguments->GetAt(4).Find("Old-style") )
					{
						csFileType += " +ko";
					}

					if ( -1 != pcsaArguments->GetAt(4).Find("RCS keyword") )
					{
						csFileType += " +k";
					}

					if ( -1 != pcsaArguments->GetAt(4).Find("Exclusive") )
					{
						csFileType += " +l";
					}

					if ( -1 != pcsaArguments->GetAt(4).Find("compressed") )
					{
						csFileType += " +C";
					}

					if ( -1 != pcsaArguments->GetAt(4).Find("deltas") )
					{
						csFileType += " +D";
					}

					if ( -1 != pcsaArguments->GetAt(4).Find("full") )
					{
						csFileType += " +F";
					}

					if ( -1 != pcsaArguments->GetAt(4).Find("head") )
					{
						csFileType += " +S";
					}

					if ( -1 != pcsaArguments->GetAt(4).Find("modtime") )
					{
						csFileType += " +m";
					}

				}
			}

			// filename wildcards
			if ( "TRUE" == pcsaArguments->GetAt(5) )
			{
				csWildCards = "-f";
			}

			csViewOutStuff.Format( "p4%s add %s %s %s %s", csGlobalSettings, 
														csChangeList,
														csFileType,
														csWildCards,
														pcsaArguments->GetAt(6) );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "" );
			pcsaBody->Add(csViewOutStuff);

		}
		break;

		case 1:		//admin
		{
			// -z : Same in compressed form
			CString csCompress;
			csCompress = "";
			if ( "TRUE" == pcsaArguments->GetAt(3) )
			{
				if ( -1 == pcsaArguments->GetAt(2).Find( "stop" ) )
				{
					csCompress = " -z ";
				}
			}

			CString csPrefix;
			csPrefix = "";
			if ( -1 == pcsaArguments->GetAt(2).Find( "stop" ) )
			{
				csPrefix = pcsaArguments->GetAt(4);
			}


			csViewOutStuff.Format( "p4%s admin %s %s %s", csGlobalSettings, 
														pcsaArguments->GetAt(2),
														csCompress,
														csPrefix );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "" );
			pcsaBody->Add(csViewOutStuff);

		}
		break;


		case 4:		//branches
		{

			csViewOutStuff.Format( "p4%s branches", csGlobalSettings );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "" );
			pcsaBody->Add(csViewOutStuff);
		}
		break;

		case 10:	//clients
		{

			csViewOutStuff.Format( "p4%s clients", csGlobalSettings );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "" );
			pcsaBody->Add(csViewOutStuff);
		}
		break;

		case 12:	//counters
		{

			csViewOutStuff.Format( "p4%s counters", csGlobalSettings );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "" );
			pcsaBody->Add(csViewOutStuff);
		}
		break;

		case 15:	//depots
		{

			csViewOutStuff.Format( "p4%s depots", csGlobalSettings );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "" );
			pcsaBody->Add(csViewOutStuff);
		}
		break;

		case 61:	//tickets
		{

			csViewOutStuff.Format( "p4%s tickets", csGlobalSettings );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "" );
			pcsaBody->Add(csViewOutStuff);
		}
		break;

		case 70:	//workspaces
		{

			csViewOutStuff.Format( "p4%s workspaces", csGlobalSettings );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "" );
			pcsaBody->Add(csViewOutStuff);
		}
		break;


		case 2:		//annotate
		case 3:		//branch
		case 5:		//change
		case 6:		//changelists
		case 7:		//changelist
		case 8:		//changes
		case 9:		//client
		case 11:	//counter
		case 13:	//delete
		case 14:	//depot
		case 16:	//describe
		case 17:	//diff
		case 18:	//diff2
		case 19:	//dirs
		case 20:	//edit
		case 21:	//filelog
		case 22:	//files
		case 23:	//fix
		case 24:	//fixes
		case 25:	//flush
		case 26:	//fstat
		case 27:	//group
		case 28:	//groups
		case 29:	//have
		case 30:	//help
		case 31:	//info
		case 32:	//integrate
		case 33:	//integrated
		case 34:	//job
		case 35:	//jobs
		case 36:	//jobspec
		case 37:	//label
		case 38:	//labels
		case 39:	//labelsync
		case 40:	//lock
		case 41:	//logger
		case 42:	//login
		case 43:	//logout
		case 44:	//monitor
		case 45:	//obliterate
		case 46:	//opened
		case 47:	//passwd
		case 48:	//print
		case 49:	//protect
		case 50:	//rename
		case 51:	//reopen
		case 52:	//resolve
		case 53:	//resolved
		case 54:	//revert
		case 55:	//review
		case 56:	//reviews
		case 57:	//set
		case 58:	//submit
		case 59:	//sync
		case 60:	//tag
		case 62:	//triggers
		case 63:	//typemap
		case 64:	//unlock
		case 65:	//user
		case 66:	//users
		case 67:	//verify
		case 68:	//where
		case 69:	//workspace
		{
			csViewOutStuff.Format( ";   APIGen has not yet implemented this method." );
			pcsaBody->Add(csViewOutStuff);
		}
		break;


	}
	
	pcsaArguments->RemoveAll();
}


void CAG_PERFORCE::finalize(CStringArray* pcsaBody)
{
	CString csViewOutStuff;

	csViewOutStuff.Format( " " );
	pcsaBody->Add(csViewOutStuff);

}

void CAG_PERFORCE::declareVariable(AG_VARIABLE agVariable,
							  CStringArray* pcsaHeader,
							  bool* bValue)
{
	CString csLocal;
	*bValue = TRUE;
	
	switch ( agVariable )
	{
	
		case AG_NUMBER:
		{
			csLocal.Format( "   integer nNumber");
		}
		break;

		case AG_RETURN_CODE:
		{
			csLocal.Format( "   integer nRetVal");
		}
		break;

	}


	pcsaHeader->Add(csLocal);
	
}

void CAG_PERFORCE::loadTerminalTypeList(CListBox* listTerminalTypes)
{
	int nPos = 0;

	listTerminalTypes->ResetContent();
}


void CAG_PERFORCE::resetVariableFlags()
{
	b_nRetVal = FALSE;
	b_nNumber = FALSE;
}
