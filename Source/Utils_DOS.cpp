#include "stdafx.h"
#include "APIGen.h"
#include "APIGenDlg.h"



/****************************************************************************DC
	Function	:	CAPIGenDlg::ShowDOSControls()

	Purpose		:	Show the controls for the DOS shell function parameters.

	Note		:	

*****************************************************************************/
void CAPIGenDlg::ShowDOSControls( int nFunction )
{
	HideParameterControls();
	csaLabels.RemoveAll();
	BOOL bYouShouldGo=TRUE;

	switch ( nFunction )
	{
		case 0:    //Append
		{
			csaLabels.Add("[Drive]");
			csaLabels.Add("Path");
			csaLabels.Add("/X:ON");
			csaLabels.Add("/PATH:ON");
			csaLabels.Add("Set APPEND environment variable");
			bYouShouldGo=FALSE;
		}
		break;

		case 81:    //Extended copy
		{
			csaLabels.Add("File(s)");
			csaLabels.Add("[Destination]");
			csaLabels.Add("[Attributes]");
			csaLabels.Add("[Files after this date]");
			csaLabels.Add("[Exclude files]");

			bYouShouldGo=FALSE;


/*

C:\Documents and Settings\Administrator>Help xCopy
Copies files and directory trees.

XCOPY source [destination] [/A | /M] [/D[:date]] [/P] [/S [/E]] [/V] [/W]
                           [/C] [/I] [/Q] [/F] [/L] [/G] [/H] [/R] [/T] [/U]
                           [/K] [/N] [/O] [/X] [/Y] [/-Y] [/Z]
                           [/EXCLUDE:file1[+file2][+file3]...]

  source       Specifies the file(s) to copy.
  destination  Specifies the location and/or name of new files.
  /A           Copies only files with the archive attribute set,
               doesn't change the attribute.
  /M           Copies only files with the archive attribute set,
               turns off the archive attribute.
  /D:m-d-y     Copies files changed on or after the specified date.
               If no date is given, copies only those files whose
               source time is newer than the destination time.
  /EXCLUDE:file1[+file2][+file3]...
               Specifies a list of files containing strings.  Each string
               should be in a separate line in the files.  When any of the
               strings match any part of the absolute path of the file to be
               copied, that file will be excluded from being copied.  For
               example, specifying a string like \obj\ or .obj will exclude
               all files underneath the directory obj or all files with the
               .obj extension respectively.
  /P           Prompts you before creating each destination file.
  /S           Copies directories and subdirectories except empty ones.
  /E           Copies directories and subdirectories, including empty ones.
               Same as /S /E. May be used to modify /T.
  /V           Verifies each new file.
  /W           Prompts you to press a key before copying.
  /C           Continues copying even if errors occur.
  /I           If destination does not exist and copying more than one file,
               assumes that destination must be a directory.
  /Q           Does not display file names while copying.
  /F           Displays full source and destination file names while copying.
  /L           Displays files that would be copied.
  /G           Allows the copying of encrypted files to destination that does
               not support encryption.
  /H           Copies hidden and system files also.
  /R           Overwrites read-only files.
  /T           Creates directory structure, but does not copy files. Does not
               include empty directories or subdirectories. /T /E includes
               empty directories and subdirectories.
  /U           Copies only files that already exist in destination.
  /K           Copies attributes. Normal Xcopy will reset read-only attributes.
  /N           Copies using the generated short names.
  /O           Copies file ownership and ACL information.
  /X           Copies file audit settings (implies /O).
  /Y           Suppresses prompting to confirm you want to overwrite an
               existing destination file.
  /-Y          Causes prompting to confirm you want to overwrite an
               existing destination file.
  /Z           Copies networked files in restartable mode.

The switch /Y may be preset in the COPYCMD environment variable.
This may be overridden with /-Y on the command line.

C:\Documents and Settings\Administrator>
*/
		}
		break;

		case 1:    //Assign
		case 2:    //Attribute
		case 3:    //Backup
		case 4:    //Break
		case 5:    //Buffers
		case 6:    //Call
		case 7:    //Change codepage
		case 8:    //Change directory
		case 9:    //Check disk
		case 10:    //Check state
		case 11:    //Choice
		case 12:    //Clear screen
		case 13:    //Command
		case 14:    //Compare
		case 15:    //Copy
		case 16:    //Country
		case 17:    //Ctty
		case 18:    //Date
		case 19:    //Defragmenter
		case 20:    //Delete
		case 21:    //Delete tree
		case 22:    //Device
		case 23:    //Devicehigh
		case 24:    //Directory
		case 25:    //Disk compare
		case 26:    //Diskcopy
		case 27:    //Doskey
		case 28:    //Dosshell
		case 29:    //Drive parameters
		case 30:    //Echo
		case 31:    //Edit
		case 32:    //Edlin
		case 33:    //Exit
		case 34:    //Expand
		case 35:    //Fast help
		case 36:    //Fast open
		case 37:    //File compare
		case 38:    //Find
		case 39:    //For
		case 40:    //Format
		case 41:    //Goto
		case 42:    //Help
		case 43:    //If
		case 44:    //Include
		case 45:    //Join
		case 46:    //Label
		case 47:    //Lastdrive
		case 48:    //Load high
		case 49:    //Make directory
		case 50:    //Memory display
		case 51:    //Mirror
		case 52:    //Mode
		case 53:    //More
		case 54:    //Move
		case 55:    //Number lock
		case 56:    //Path
		case 57:    //Pause
		case 58:    //Power
		case 59:    //Print
		case 60:    //Prompt
		case 61:    //Recover
		case 62:    //Remark
		case 63:    //Remove directory
		case 64:    //Rename
		case 65:    //Replace
		case 66:    //Set
		case 67:    //Set version
		case 68:    //Share
		case 69:    //Shell
		case 70:    //Shift
		case 71:    //Sort
		case 72:    //Stacks
		case 73:    //Substitute
		case 74:    //Time
		case 75:    //Tree
		case 76:    //Type
		case 77:    //Undelete
		case 78:    //Version
		case 79:    //Verify
		case 80:    //Volume
		{
		}
		break;

		default:
		{
			m_groupNoParametersNeeded.ShowWindow( SW_SHOW  );
		}

	}

	if ( bYouShouldGo )
	{
		ShowEditControls( &csaLabels );
	}
	else
	{
		ShowMixedControls( DOS_API, nFunction, &csaLabels );	
	}

}




/****************************************************************************DC
	Function	:	CAPIGenDlg::LoadDOSArgumentArray()

	Purpose		:	Load the function arguments for MS-DOS commands

*****************************************************************************/
void CAPIGenDlg::LoadDOSArgumentArray( int* nFunction, BOOL bPromptForValues )
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
			case 0:    //Append
			{
				Read2E3C( &csaArguments );
			}
			break;

			case 1:    //Assign
			case 2:    //Attribute
			case 3:    //Backup
			case 4:    //Break
			case 5:    //Buffers
			case 6:    //Call
			case 7:    //Change codepage
			case 8:    //Change directory
			case 9:    //Check disk
			case 10:    //Check state
			case 11:    //Choice
			case 12:    //Clear screen
			case 13:    //Command
			case 14:    //Compare
			case 15:    //Copy
			case 16:    //Country
			case 17:    //Ctty
			case 18:    //Date
			case 19:    //Defragmenter
			case 20:    //Delete
			case 21:    //Delete tree
			case 22:    //Device
			case 23:    //Devicehigh
			case 24:    //Directory
			case 25:    //Disk compare
			case 26:    //Diskcopy
			case 27:    //Doskey
			case 28:    //Dosshell
			case 29:    //Drive parameters
			case 30:    //Echo
			case 31:    //Edit
			case 32:    //Edlin
			case 33:    //Exit
			case 34:    //Expand
			case 35:    //Fast help
			case 36:    //Fast open
			case 37:    //File compare
			case 38:    //Find
			case 39:    //For
			case 40:    //Format
			case 41:    //Goto
			case 42:    //Help
			case 43:    //If
			case 44:    //Include
			case 45:    //Join
			case 46:    //Label
			case 47:    //Lastdrive
			case 48:    //Load high
			case 49:    //Make directory
			case 50:    //Memory display
			case 51:    //Mirror
			case 52:    //Mode
			case 53:    //More
			case 54:    //Move
			case 55:    //Number lock
			case 56:    //Path
			case 57:    //Pause
			case 58:    //Power
			case 59:    //Print
			case 60:    //Prompt
			case 61:    //Recover
			case 62:    //Remark
			case 63:    //Remove directory
			case 64:    //Rename
			case 65:    //Replace
			case 66:    //Set
			case 67:    //Set version
			case 68:    //Share
			case 69:    //Shell
			case 70:    //Shift
			case 71:    //Sort
			case 72:    //Stacks
			case 73:    //Substitute
			case 74:    //Time
			case 75:    //Tree
			case 76:    //Type
			case 77:    //Undelete
			case 78:    //Version
			case 79:    //Verify
			case 80:    //Volume
			case 81:    //Extended copy
			{
				//Read1E( &csaArguments );
				csaArguments.Add( "" );
				csaArguments.Add( "" );
				csaArguments.Add( "" );
			}
			break;


		}
	}
	else
	{
		switch ( *nFunction )
		{
			case 0:    //Append
			{
				csaArguments.Add( "e:" );
				csaArguments.Add( "test" );
				csaArguments.Add( "TRUE" );
				csaArguments.Add( "TRUE" );
				csaArguments.Add( "FALSE" );
			}
			break;


			case 1:    //Assign
			case 2:    //Attribute
			case 3:    //Backup
			case 4:    //Break
			case 5:    //Buffers
			case 6:    //Call
			case 7:    //Change codepage
			case 8:    //Change directory
			case 9:    //Check disk
			case 10:    //Check state
			case 11:    //Choice
			case 12:    //Clear screen
			case 13:    //Command
			case 14:    //Compare
			case 15:    //Copy
			case 16:    //Country
			case 17:    //Ctty
			case 18:    //Date
			case 19:    //Defragmenter
			case 20:    //Delete
			case 21:    //Delete tree
			case 22:    //Device
			case 23:    //Devicehigh
			case 24:    //Directory
			case 25:    //Disk compare
			case 26:    //Diskcopy
			case 27:    //Doskey
			case 28:    //Dosshell
			case 29:    //Drive parameters
			case 30:    //Echo
			case 31:    //Edit
			case 32:    //Edlin
			case 33:    //Exit
			case 34:    //Expand
			case 35:    //Fast help
			case 36:    //Fast open
			case 37:    //File compare
			case 38:    //Find
			case 39:    //For
			case 40:    //Format
			case 41:    //Goto
			case 42:    //Help
			case 43:    //If
			case 44:    //Include
			case 45:    //Join
			case 46:    //Label
			case 47:    //Lastdrive
			case 48:    //Load high
			case 49:    //Make directory
			case 50:    //Memory display
			case 51:    //Mirror
			case 52:    //Mode
			case 53:    //More
			case 54:    //Move
			case 55:    //Number lock
			case 56:    //Path
			case 57:    //Pause
			case 58:    //Power
			case 59:    //Print
			case 60:    //Prompt
			case 61:    //Recover
			case 62:    //Remark
			case 63:    //Remove directory
			case 64:    //Rename
			case 65:    //Replace
			case 66:    //Set
			case 67:    //Set version
			case 68:    //Share
			case 69:    //Shell
			case 70:    //Shift
			case 71:    //Sort
			case 72:    //Stacks
			case 73:    //Substitute
			case 74:    //Time
			case 75:    //Tree
			case 76:    //Type
			case 77:    //Undelete
			case 78:    //Version
			case 79:    //Verify
			case 80:    //Volume
			case 81:    //Extended copy
			{
				csaArguments.Add( "" );
				csaArguments.Add( "" );
				csaArguments.Add( "" );
			}
			break;

		}
	}

}

