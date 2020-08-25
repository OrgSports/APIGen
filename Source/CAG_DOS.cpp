// Static Model
#include "stdafx.h"
#include "apigen.h"

#include "CAG_DOS.h"


CAG_DOS::CAG_DOS()
{
	APIFlavor=DOS_API;
	resetVariableFlags();
}

CAG_DOS::~CAG_DOS()
{
	
}

void CAG_DOS::loadFunctionList(CListBox* listTranslateFunction)
{
	csaFunctions.RemoveAll();

	csaFunctions.Add("Append");
	csaFunctions.Add("Assign");
	csaFunctions.Add("Attribute");
	csaFunctions.Add("Backup");
	csaFunctions.Add("Break");
	csaFunctions.Add("Buffers");
	csaFunctions.Add("Call");
	csaFunctions.Add("Change codepage");
	csaFunctions.Add("Change directory");
	csaFunctions.Add("Check disk");
	csaFunctions.Add("Check state");
	csaFunctions.Add("Choice");
	csaFunctions.Add("Clear screen");
	csaFunctions.Add("Command");
	csaFunctions.Add("Compare");
	csaFunctions.Add("Copy");
	csaFunctions.Add("Country");
	csaFunctions.Add("Ctty");
	csaFunctions.Add("Date");
	csaFunctions.Add("Defragmenter");
	csaFunctions.Add("Delete");
	csaFunctions.Add("Delete tree");
	csaFunctions.Add("Device");
	csaFunctions.Add("Devicehigh");
	csaFunctions.Add("Directory");
	csaFunctions.Add("Disk compare");
	csaFunctions.Add("Diskcopy");
	csaFunctions.Add("Doskey");
	csaFunctions.Add("Dosshell");
	csaFunctions.Add("Drive parameters");
	csaFunctions.Add("Echo");
	csaFunctions.Add("Edit");
	csaFunctions.Add("Edlin");
	csaFunctions.Add("Exit");
	csaFunctions.Add("Expand");
	csaFunctions.Add("Fast help");
	csaFunctions.Add("Fast open");
	csaFunctions.Add("File compare");
	csaFunctions.Add("Find");
	csaFunctions.Add("For");
	csaFunctions.Add("Format");
	csaFunctions.Add("Goto");
	csaFunctions.Add("Help");
	csaFunctions.Add("If");
	csaFunctions.Add("Include");
	csaFunctions.Add("Join");
	csaFunctions.Add("Label");
	csaFunctions.Add("Lastdrive");
	csaFunctions.Add("Load high");
	csaFunctions.Add("Make directory");
	csaFunctions.Add("Memory display");
	csaFunctions.Add("Mirror");
	csaFunctions.Add("Mode");
	csaFunctions.Add("More");
	csaFunctions.Add("Move");
	csaFunctions.Add("Number lock");
	csaFunctions.Add("Path");
	csaFunctions.Add("Pause");
	csaFunctions.Add("Power");
	csaFunctions.Add("Print");
	csaFunctions.Add("Prompt");
	csaFunctions.Add("Recover");
	csaFunctions.Add("Remark");
	csaFunctions.Add("Remove directory");
	csaFunctions.Add("Rename");
	csaFunctions.Add("Replace");
	csaFunctions.Add("Set");
	csaFunctions.Add("Set version");
	csaFunctions.Add("Share");
	csaFunctions.Add("Shell");
	csaFunctions.Add("Shift");
	csaFunctions.Add("Sort");
	csaFunctions.Add("Stacks");
	csaFunctions.Add("Substitute");
	csaFunctions.Add("Time");
	csaFunctions.Add("Tree");
	csaFunctions.Add("Type");
	csaFunctions.Add("Undelete");
	csaFunctions.Add("Version");
	csaFunctions.Add("Verify");
	csaFunctions.Add("Volume");
	csaFunctions.Add("Xcopy");
	
	listTranslateFunction->ResetContent();	
	
	for (int k=0; k<csaFunctions.GetSize(); k++)
	{
		listTranslateFunction->AddString( csaFunctions.GetAt(k) );
	}

	listTranslateFunction->SetCurSel(0);
	
}


void CAG_DOS::loadLanguageList(CListBox* listTranslateLanguage)
{
	int nPos = 0;

	listTranslateLanguage->ResetContent();
	listTranslateLanguage->InsertString( nPos++, "DOS commands" );
	
	listTranslateLanguage->SetCurSel(0);
	
}

void CAG_DOS::checkDebug(bool b_Debug,
						 CString csFunctionName,
						 CStringArray* pcsaBody)
{
	
}

void CAG_DOS::generateHeader(CStringArray* pcsaHeader,
							 CStringArray* pcsaBody)
{

	CString csViewOutStuff;

	csViewOutStuff.Format( "--  ****************************************************************************");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "--                    Attachmate APIGen");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "--                APIGen MS-DOS Shell Batch File");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "-- ");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "--  This batch file features the use of MS-DOS commands.");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "--  As it becomes known this header will include information");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "--  covering how to set up the running environment, and load and");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "--   run this macro.");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "--   1. XXX");
	pcsaHeader->Add(csViewOutStuff);


	time_t ltime;
	time( &ltime );

	csViewOutStuff.Format( "--");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "--   Generated:   %s", ctime( &ltime ) );
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "--");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "");
	pcsaHeader->Add(csViewOutStuff);

}



void CAG_DOS::appendBody(int nFunctionNum,
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

	switch ( nFunctionNum )
	{
		case 0:		//Append
		{
			
			if ( "TRUE" == pcsaArguments->GetAt(3) )
			{
				csParam1 = "/X:ON";
			}
			else
			{
				csParam1 = "/X:OFF";
			}

			if ( "TRUE" == pcsaArguments->GetAt(4) )
			{
				csParam2 = "/PATH:ON";
			}
			else
			{
				csParam2 = "/PATH:OFF";
			}

			if ( "TRUE" == pcsaArguments->GetAt(5) )
			{
				csParam3 = "/E";
			}


			csViewOutStuff.Format( "   append %s %s %s %s %s", pcsaArguments->GetAt(1),
														 pcsaArguments->GetAt(2),
														 csParam1,
														 csParam2,
														 csParam3);
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "" );
			pcsaBody->Add(csViewOutStuff);

		}
		break;

		case 81:	//xcopy
		{
	
		}
		break;

		case 1:		//Assign
		case 2:		//Attribute
		case 3:		//Backup
		case 4:		//Break
		case 5:		//Buffers
		case 6:		//Call
		case 7:		//Change codepage
		case 8:		//Change directory
		case 9:		//Check disk
		case 10:	//Check state
		case 11:	//Choice
		case 12:	//Clear screen
		case 13:	//Command
		case 14:	//Compare
		case 15:	//Copy
		case 16:	//Country
		case 17:	//Ctty
		case 18:	//Date
		case 19:	//Defragmenter
		case 20:	//Delete
		case 21:	//Delete tree
		case 22:	//Device
		case 23:	//Devicehigh
		case 24:	//Directory
		case 25:	//Disk compare
		case 26:	//Diskcopy
		case 27:	//Doskey
		case 28:	//Dosshell
		case 29:	//Drive parameters
		case 30:	//Echo
		case 31:	//Edit
		case 32:	//Edlin
		case 33:	//Exit
		case 34:	//Expand
		case 35:	//Fast help
		case 36:	//Fast open
		case 37:	//File compare
		case 38:	//Find
		case 39:	//For
		case 40:	//Format
		case 41:	//Goto
		case 42:	//Help
		case 43:	//If
		case 44:	//Include
		case 45:	//Join
		case 46:	//Label
		case 47:	//Lastdrive
		case 48:	//Load high
		case 49:	//Make directory
		case 50:	//Memory display
		case 51:	//Mirror
		case 52:	//Mode
		case 53:	//More
		case 54:	//Move
		case 55:	//Number lock
		case 56:	//Path
		case 57:	//Pause
		case 58:	//Power
		case 59:	//Print
		case 60:	//Prompt
		case 61:	//Recover
		case 62:	//Remark
		case 63:	//Remove directory
		case 64:	//Rename
		case 65:	//Replace
		case 66:	//Set
		case 67:	//Set version
		case 68:	//Share
		case 69:	//Shell
		case 70:	//Shift
		case 71:	//Sort
		case 72:	//Stacks
		case 73:	//Substitute
		case 74:	//Time
		case 75:	//Tree
		case 76:	//Type
		case 77:	//Undelete
		case 78:	//Version
		case 79:	//Verify
		case 80:	//Volume
		{
			csViewOutStuff.Format( ";   APIGen has not yet implemented this method." );
			pcsaBody->Add(csViewOutStuff);
		}
		break;


	}
	
	pcsaArguments->RemoveAll();
}


void CAG_DOS::finalize(CStringArray* pcsaBody)
{
	CString csViewOutStuff;

	csViewOutStuff.Format( " " );
	pcsaBody->Add(csViewOutStuff);

	csViewOutStuff.Format( "   return;");
	pcsaBody->Add(csViewOutStuff);

	csViewOutStuff.Format( "} " );
	pcsaBody->Add(csViewOutStuff);

}

void CAG_DOS::declareVariable(AG_VARIABLE agVariable,
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

void CAG_DOS::loadTerminalTypeList(CListBox* listTerminalTypes)
{
	int nPos = 0;

	listTerminalTypes->ResetContent();
}


void CAG_DOS::resetVariableFlags()
{
	b_nRetVal = FALSE;
	b_nNumber = FALSE;
}
