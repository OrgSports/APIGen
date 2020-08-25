#include "stdafx.h"
#include "APIGen.h"
#include "APIGenDlg.h"

/****************************************************************************DC
	Function	:	CAPIGenDlg::LoadWHLArgumentArray()

	Purpose		:	Load the function arguments for WHLLAPI.

*****************************************************************************/
void CAPIGenDlg::LoadWHLArgumentArray( int* nFunctionPosition, BOOL bPromptForValues )
{
	CString	csFunctionName, csFunctionNum;
	*nFunctionPosition=0;

	if ( bPromptForValues )
	{
		
		UpdateData();

		*nFunctionPosition = m_listTranslateFunction.GetCurSel();
		m_listTranslateFunction.GetText( *nFunctionPosition, csFunctionName );

		//csFunctionName = pcsaHeader->GetAt(1);
		int nSpacePlace = csFunctionName.Find(" ");
		
		// full function name text
		csaArguments.Add( csFunctionName );
		// function number
		csFunctionNum = csFunctionName.Left(nSpacePlace);
		csaArguments.Add( csFunctionNum );
		
		if ( atoi(csFunctionNum) == 137 )	// SMARTWAIT
		{
			csaArguments.Add("A");
			csaArguments.Add("5000");
			csaArguments.Add("3220");
			csaArguments.Add("0");
		}
		else
		{
			ReadHLLArgs( &csaArguments );
		}
	}
	else
	{
		*nFunctionPosition = m_listTranslateFunction.GetCurSel();
		m_listTranslateFunction.GetText( *nFunctionPosition, csFunctionName );

		//csFunctionName = pcsaHeader->GetAt(1);
		int nSpacePlace = csFunctionName.Find(" ");
		
		// full function name text
		csaArguments.Add( csFunctionName );
		// function number
		csFunctionNum = csFunctionName.Left(nSpacePlace);
		csaArguments.Add( csFunctionNum );
		
		switch ( atoi( csFunctionNum ) )
		{
			case 0:	// WinHLLAPIStartup
			{
			}
			break;

			case 1:
			case 2:
			case 10:
			case 11:
			case 12:
			case 13:
			case 14:
			case 21:	// RESETSYSTEM
			case 24:	// QUERYHOSTUPDATE
			case 25:	// STOPHOSTNOTIFICATION
			case 41:	// STARTCLOSEINTERCEPT
			case 42:	// QUERYCLOSEINTERCEPT
			case 43:	// STOPCLOSEINTERCEPT
			case 53:	// STOPKSINTERCEPT
			{
				csaArguments.Add("A");
				csaArguments.Add("1");
				csaArguments.Add("0");
				csaArguments.Add("0");
			}
			break;

			case 3:
			{
				csaArguments.Add("ABC");
				csaArguments.Add("3");
				csaArguments.Add("0");
				csaArguments.Add("0");
			}
			break;

			case 4:
			case 7:
			{
				csaArguments.Add("0");
				csaArguments.Add("0");
				csaArguments.Add("0");
				csaArguments.Add("0");
			}
			break;

			case 5:
			{
				csaArguments.Add("0");
				CString csTemp;
				csTemp.Format( "%i", nGlobalPSMallocSize );
				csaArguments.Add( csTemp );
				csaArguments.Add("0");
				csaArguments.Add("0");
			}
			break;

			case 6:
			{
				csaArguments.Add("Running");
				csaArguments.Add("3");
				csaArguments.Add("1");
				csaArguments.Add("0");
			}
			break;

			case 8:
			{
				csaArguments.Add("0");
				csaArguments.Add("0");
				csaArguments.Add("1530");
				csaArguments.Add("0");
			}
			break;

			case 9:
			{
				csaArguments.Add("EAB");
				csaArguments.Add("3");
				csaArguments.Add("0");
				csaArguments.Add("0");
			}
			break;

			case 15:
			{
				csaArguments.Add("userid");
				csaArguments.Add("6");
				csaArguments.Add("1537");
				csaArguments.Add("0");
			}
			break;

			case 18:	// PAUSE
			{
				csaArguments.Add("0");
				csaArguments.Add("6");
				csaArguments.Add("0");
				csaArguments.Add("0");
			}
			break;

			case 22:	// QUERYSESSIONSTATUS
			{
				csaArguments.Add("A");
				csaArguments.Add("18");
				csaArguments.Add("0");
				csaArguments.Add("0");
			}
			break;

			case 23:	// STARTHOSTNOTIFICATION
			{
				csaArguments.Add("AO    ");
				csaArguments.Add("256");
				csaArguments.Add("0");
				csaArguments.Add("0");
			}
			break;

			case 30:	// SEARCHFIELD
			{
				csaArguments.Add("Running");
				csaArguments.Add("7");
				csaArguments.Add("1");
				csaArguments.Add("0");
			}
			break;

			case 31:	// FINDFIELDPOSITION
			{
				csaArguments.Add("NU");
				csaArguments.Add("2");
				csaArguments.Add("1537");
				csaArguments.Add("0");
			}
			break;
			
			case 32:	// FINDFIELDLENGTH
			{
				csaArguments.Add("^^");
				csaArguments.Add("2");
				csaArguments.Add("1537");
				csaArguments.Add("0");
			}
			break;


			case 33:	// COPYSTRINGTOFIELD
			{
				csaArguments.Add("Rain");
				csaArguments.Add("4");
				csaArguments.Add("1537");
				csaArguments.Add("0");
			}
			break;

			case 34:	// COPYFIELDTOSTRING
			{
				csaArguments.Add("        ");
				csaArguments.Add("8");
				csaArguments.Add("1537");
				csaArguments.Add("0");
			}
			break;

			case 40:	// SETCURSOR
			{
				csaArguments.Add(" ");
				csaArguments.Add("1");
				csaArguments.Add("1537");
				csaArguments.Add("0");
			}
			break;

			case 50:	// STARTKEYSTROKEINTERCEPT
			{
				csaArguments.Add("AD    ");
				csaArguments.Add("256");
				csaArguments.Add(" ");
				csaArguments.Add("0");
			}
			break;

			case 51:	// GETKEY
			{
				csaArguments.Add("        ");
				csaArguments.Add("8");
				csaArguments.Add(" ");
				csaArguments.Add("0");
			}
			break;

			case 52:	// POSTINTERCEPTSTATUS
			{
				csaArguments.Add("AA");
				csaArguments.Add("2");
				csaArguments.Add(" ");
				csaArguments.Add("0");
			}
			break;

			case 90:	// SENDFILE
			case 91:	// RECEIVEFILE
			{
				csaArguments.Add("*.txt a: * txt");
				csaArguments.Add("14");
				csaArguments.Add("1");
				csaArguments.Add("0");
			}
			break;
		
			case 99:	// CONVERTPOSITION
			{
				csaArguments.Add("AR");
				csaArguments.Add("15");
				csaArguments.Add("17");
				csaArguments.Add("0");
			}
			break;

			case 101:	// CONNECT WINDOW SERVICES
			{
				csaArguments.Add("A                ");
				csaArguments.Add("0");
				csaArguments.Add("0");
				csaArguments.Add("0");
			}
			break;

			case 102:	// DISCONNECT WINDOW SERVICES
			{
				csaArguments.Add("A                ");
				csaArguments.Add("0");
				csaArguments.Add("0");
				csaArguments.Add("0");
			}
			break;


			case 103:	// QUERYWINDOWCOORDINATES
			{
				csaArguments.Add("A                ");
				csaArguments.Add("17");
				csaArguments.Add("0");
				csaArguments.Add("0");
			}
			break;

			case 104:	// WINDOWSTATUS -- Change size
			{
				csaArguments.Add("A1010000FFFF00000000");
				csaArguments.Add("20");
				csaArguments.Add("0");
				csaArguments.Add("0");
			}
			break;

			case 105:	// CHANGELIST
			{
				csaArguments.Add("A100000000000000");
				csaArguments.Add("16");
				csaArguments.Add("0");
				csaArguments.Add("0");
			}
			break;

			case 106:	// CHANGENAME
			{
				csaArguments.Add("A1Title by APIGenerator");
				csaArguments.Add("24");
				csaArguments.Add("0");
				csaArguments.Add("0");
			}
			break;

			case 107:	// QUERY HANDLE
			{
				csaArguments.Add("A1Title by APIGenerator");
				csaArguments.Add("24");
				csaArguments.Add("0");
				csaArguments.Add("0");
			}
			break;

			case 120:	// CONNECT STRUCTURED FIELDS
			{
				csaArguments.Add("A1234      ");
				csaArguments.Add("11");
				csaArguments.Add("0");
				csaArguments.Add("0");
			}
			break;

			case 121:	// DISCONNECT STRUCTURED FIELDS
			{
				csaArguments.Add("A22");
				csaArguments.Add("3");
				csaArguments.Add("0");
				csaArguments.Add("0");
			}
			break;

			case 122:	// QUERY COMMUNICATIONS BUFFER SIZE
			{
				csaArguments.Add("A        ");
				csaArguments.Add("9");
				csaArguments.Add("0");
				csaArguments.Add("0");
			}
			break;

			case 123:	// ALLOCATE COMMUNICATIONS BUFFER
			{
				csaArguments.Add("11    ");
				csaArguments.Add("6");
				csaArguments.Add("0");
				csaArguments.Add("0");
			}
			break;

			case 124:	// FREE COMMUNICATIONS BUFFER
			{
				csaArguments.Add("111234");
				csaArguments.Add("6");
				csaArguments.Add("0");
				csaArguments.Add("0");
			}
			break;

			case 125:	// GET REQUEST COMPLETION
			{
				csaArguments.Add("AN22          ");
				csaArguments.Add("14");
				csaArguments.Add("0");
				csaArguments.Add("0");
			}
			break;

			case 126:	// READ STRUCTURED FIELDS
			{
				csaArguments.Add("AS112345");
				csaArguments.Add("8");
				csaArguments.Add("0");
				csaArguments.Add("0");
			}
			break;

			case 127:	// WRITE STRUCTURED FIELDS
			{
				csaArguments.Add("AS112345");
				csaArguments.Add("8");
				csaArguments.Add("0");
				csaArguments.Add("0");
			}
			break;

			case 137:	// SMARTWAIT
			{
				csaArguments.Add("A");
				csaArguments.Add("5000");
				csaArguments.Add("3220");
				csaArguments.Add("0");
			}
			break;

			case 911:	// ASSOCIATE PROFILE
			{
				csaArguments.Add("AC:\\PROGRAM FILES\\ATTACHMATE\\SESSIONS\\SESSION1.EDP");
				csaArguments.Add("0");
				csaArguments.Add("0");
				csaArguments.Add("0");
			}
			break;

			case 912:	// REMOVE PROFILE
			{
				csaArguments.Add("A");
				csaArguments.Add("0");
				csaArguments.Add("0");
				csaArguments.Add("0");
			}
			break;

			case 913:	// GET ASSOCIATIONS
			{
				csaArguments.Add("XXXXXXXXXXXXXXXXXXXXXXXXXX");
				csaArguments.Add("0");
				csaArguments.Add("0");
				csaArguments.Add("0");
			}
			break;

			case 914:	// FIND FILE NAME
			{
				csaArguments.Add("A");
				csaArguments.Add("0");
				csaArguments.Add("0");
				csaArguments.Add("0");
			}
			break;

			case 915:	// FIND SHORT NAME
			{
				csaArguments.Add("c:\\program files\\attachmate\\sessions\\es9000.edp");
				csaArguments.Add("0");
				csaArguments.Add("0");
				csaArguments.Add("0");
			}
			break;

		}
		
	}
}



/****************************************************************************DC
	Function	:	CAPIGenDlg::ShowWHLControls()

	Purpose		:	Show the controls for the EHLLAPI function parameters.

*****************************************************************************/
void CAPIGenDlg::ShowWHLControls()
{
	HideParameterControls();
	csaLabels.RemoveAll();

	csaLabels.Add("String");
	csaLabels.Add("String length");
	csaLabels.Add("Return code");

	ShowHLLControls( &csaLabels );
}
