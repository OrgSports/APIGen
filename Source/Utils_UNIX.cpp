#include "stdafx.h"
#include "APIGen.h"
#include "APIGenDlg.h"



/****************************************************************************DC
	Function	:	CAPIGenDlg::ShowUnixControls()

	Purpose		:	Show the controls for the UNIX shell function parameters.

	Note		:	

*****************************************************************************/
void CAPIGenDlg::ShowUNIXControls( int nFunction )
{
	HideParameterControls();
	csaLabels.RemoveAll();
	BOOL bYouShouldGo=TRUE;

	switch ( nFunction )
	{
		case 0:		//cat - concatenate files
		{
			csaLabels.Add("[Options]");
			csaLabels.Add("[Source file]");
			csaLabels.Add("[Redirect-to file]");
			bYouShouldGo=FALSE;
		}
		break;

		case 1:		//cd - change working directory
		{
			csaLabels.Add("Directory");
		}
		break;

		case 2:    //chmod - change file access
		{
			csaLabels.Add("[Options]");
			csaLabels.Add("Group/user");
			csaLabels.Add("Permissions on/off");
			csaLabels.Add("Mode permission");
			csaLabels.Add("Path name");
			bYouShouldGo=FALSE;
		}
		break;

		case 3:    //comment - insert comment
		{
			csaLabels.Add("Comment string");
		}
		break;

		case 4:    //cp - copy files
		{
			csaLabels.Add("[Reproduction option]");
			csaLabels.Add("[Options]");
			csaLabels.Add("Source(s) (csv)");
			csaLabels.Add("Destination");
			bYouShouldGo=FALSE;
		}
		break;

		case 5:    //csplit - split text file
		{
			csaLabels.Add("[Options]");
			csaLabels.Add("[Filename prefix]");
			csaLabels.Add("[Number of digits]");
			csaLabels.Add("Source file");
			csaLabels.Add("Argument list (csv)");
			bYouShouldGo=FALSE;
		}
		break;



		case 6:    //diff - compare text files
		case 7:    //dircmp - compare directories
		case 8:    //egrep - search files w/extended regexp
		case 9:	//env
		case 10:    //expand -- expand tabs to spaces
		case 11:	//find
		{
		}
		break;

		case 12:    //fgrep - search files for strings
		{
			csaLabels.Add("[Options]");
			csaLabels.Add("[-e Pattern string]");
			csaLabels.Add("[-f Pattern file]");
			csaLabels.Add("[Seek file]");
			bYouShouldGo=FALSE;
		}
		break;


		case 13:    //grep
		{
			csaLabels.Add("[Options]");
			csaLabels.Add("[-e Pattern string]");
			csaLabels.Add("[-f Pattern file]");
			csaLabels.Add("[Seek file]");
			bYouShouldGo=FALSE;
		}
		break;

		case 14:    //gres
		{
			csaLabels.Add("Pattern string");
			csaLabels.Add("Substitue string");
			csaLabels.Add("[File(s)]");
		}
		break;

		case 15:    //lc - list files/directories
		case 16:    //look - find lines
		case 17:    //ls - list files/directories
		case 18:	//mkdir
		case 19:    //mv - rename/move files
		case 20:    //pack - compress files
		case 21:	//passwd
		case 22:	//pwd
		case 23:	//rmdir
		case 24:    //sleep - pause for specified time
		case 25:    //sort - sort/merge
		case 26:	//stty
		case 27:    //tar - copy/backup files
		case 28:    //tr - translation
		case 29:    //tsort - topological sort
		case 30:    //uniq - display unique lines
		case 31:    //wc - word/char count
		case 32:    //who - display user info
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
		ShowMixedControls( UNIX_API, nFunction, &csaLabels );	
	}

}




/****************************************************************************DC
	Function	:	CAPIGenDlg::LoadUNIXArgumentArray()

	Purpose		:	Load the function arguments for the UNIX shell

*****************************************************************************/
void CAPIGenDlg::LoadUNIXArgumentArray( int* nFunction, BOOL bPromptForValues )
{
	CString	csFunctionName, csFunctionNum;
	
	UpdateData();
	
	*nFunction=0;

	*nFunction = m_listTranslateFunction.GetCurSel();
	m_listTranslateFunction.GetText( *nFunction, csFunctionName );

	// full function name text
	csaArguments.Add( csFunctionName );


	if ( bPromptForValues )
	{
		switch ( *nFunction )
		{
			case 1:		//cd - change directory
			case 3:    //comment - insert comment
			{
				Read1E( &csaArguments );
			}
			break;

			case 2:    //chmod - change file access
			{
				Read2ML1L1ML1E( &csaArguments );
			}
			break;

			case 4:    //cp - copy files
			{
				Read1L1ML2E( &csaArguments );
			}
			break;

			case 5:    //csplit - split text file
			{
				Read1ML4E( &csaArguments );
			}
			break;


			case 0:		//cat - concatenate files	
			{
				Read1ML2E( &csaArguments );
			}
			break;

			case 12:    //fgrep
			case 13:    //grep
			{
				Read1ML3E( &csaArguments );
			}
			break;

			case 14:    //gres
			{
				Read3E( &csaArguments );
			}
			break;
		}
	}
	else
	{
		switch ( *nFunction )
		{
			case 0:		//cat - concatenate files
			{
				csaArguments.Add( "-v display all characters -e end lines with $ character" );
				csaArguments.Add( "run1.txt" );
				csaArguments.Add( "infofile.txt" );
			}
			break;

			case 1:		//cd - change directory
			{
				csaArguments.Add( "salesDir" );
			}
			break;

			case 2:    //chmod - change file access
			{
				csaArguments.Add( "-f suppress error messages" );
				csaArguments.Add( "g - set group permissions" );
				csaArguments.Add( "+ - turn on permission" );
				csaArguments.Add( "x - execute permission w - write permission" );
				csaArguments.Add( "infoDir" );
			}
			break;

			case 4:    //cp - copy files
			{
				csaArguments.Add( "-r no special formats" );
				csaArguments.Add( "-c - prompt on full diskette" );
				csaArguments.Add( "Hello" );
				csaArguments.Add( "infofile.txt" );
			}
			break;

			case 5:    //csplit - split text file
			{
				csaArguments.Add( "-a lowercase filename chars" );
				csaArguments.Add( "testa16" );
				csaArguments.Add( "" );
				csaArguments.Add( "infofile.txt" );
				csaArguments.Add( "a(t*)achmatewrq" );
			}
			break;

			case 12:    //fgrep
			case 13:    //grep
			{
				csaArguments.Add( "-i ignore case" );
				csaArguments.Add( "Hello" );
				csaArguments.Add( "inputfile.in" );
				csaArguments.Add( "seekfile.txt" );
			}
			break;

			case 14:    //gres
			{
				csaArguments.Add( "Which" );
				csaArguments.Add( "That" );
				csaArguments.Add( "filelist.txt" );
			}
			break;


		}
	}

}

