// Static Model
#include "stdafx.h"
#include "apigen.h"

#include "CAG_UNIX.h"

CAG_UNIX::CAG_UNIX()
{
	APIFlavor=UNIX_API;
	resetVariableFlags();
}

CAG_UNIX::~CAG_UNIX()
{
	
}


void CAG_UNIX::generateHeader(CStringArray* pcsaHeader,
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

	// output to Translator's output window
	CString csViewOutStuff;
	pcsaHeader->Add( "rem ****************************************************************************");

	pcsaHeader->Add( "rem                   APIGen UNIX Shell Command File");
	pcsaHeader->Add( "rem");
	pcsaHeader->Add( "rem   This file is a batch file that contains command lines for Unix commands specified");
	pcsaHeader->Add( "rem   while running the Attachmate API Generator.  The format of the commands is");
	pcsaHeader->Add( "rem   taken from the MKS Toolkit and the file generated will be a .bat file intended");
	pcsaHeader->Add( "rem   to be run in a Windows command window.");
	pcsaHeader->Add( "rem");

	time_t ltime;
	time( &ltime );

	pcsaHeader->Add( "rem");

	csViewOutStuff.Format( "rem   Generated:   %s", ctime( &ltime ) );
	pcsaHeader->Add(csViewOutStuff);

	pcsaHeader->Add( "rem");
	pcsaHeader->Add( "rem ****************************************************************************");
	pcsaHeader->Add( "rem");

}



void CAG_UNIX::appendBody(int nFunctionNum,
						 bool bPromptForValues,
						 CStringArray* pcsaArguments,
						 CStringArray* pcsaHeader,
						 CStringArray* pcsaBody)
{
	CString csViewOutStuff;
	CString csFunctionName;

	csFunctionName = pcsaArguments->GetAt( 0 );

	csViewOutStuff.Format( " " );
	pcsaBody->Add(csViewOutStuff);

	csViewOutStuff.Format( "rem *** %s", csFunctionName );
	pcsaBody->Add(csViewOutStuff);

	switch ( nFunctionNum )
	{
		case 0:		//cat - concatenate files
		{
			// output options
			CString csStoredSwitches;
			CString csLocal( pcsaArguments->GetAt(1) );
			if ( -1 != csLocal.Find( "None") )
			{
				csStoredSwitches="";
			}
			else 			
			{
				
				if ( -1 != csLocal.Find( "-s") || -1 != csLocal.Find( "-u") )
				{
					csStoredSwitches+="-";

					if ( -1 != csLocal.Find( "-s") )
					{
						csStoredSwitches+="s";
					}

					if ( -1 != csLocal.Find( "-u") )
					{
						csStoredSwitches+="u";
					}

					csStoredSwitches+=" ";

				}
				

				if ( -1 != csLocal.Find( "-v") )
				{
					csStoredSwitches+="-v";
					
					if ( -1 != csLocal.Find( "-e") )
					{
						csStoredSwitches+="e";
					}
						
					if ( -1 != csLocal.Find( "-t") )
					{
						csStoredSwitches+="t";
					}

				}	
				
				// add a space after any mode who
				if ( csStoredSwitches.GetLength() != 0 )
				{
					csStoredSwitches+=" ";
				}
			}


			csViewOutStuff.Format( "cat %s %s %s",	csStoredSwitches, pcsaArguments->GetAt(2), pcsaArguments->GetAt(3) );
			pcsaBody->Add(csViewOutStuff);

		}
		break;

		case 1:		//cd - change directory
		{
			csViewOutStuff.Format( "cd %s", pcsaArguments->GetAt(1) );
			pcsaBody->Add(csViewOutStuff);
		}
		break;
	
		case 2:    //chmod - change file access
		{
			// options
			CString csStoredSwitches;
			CString csLocal( pcsaArguments->GetAt(1) );
			if ( -1 != csLocal.Find( "None") )
			{
				csStoredSwitches="";
			}
			else 			
			{
				
				if ( -1 != csLocal.Find( "-f") || -1 != csLocal.Find( "-R") )
				{
					csStoredSwitches="-";

					if ( -1 != csLocal.Find( "-f") )
					{
						csStoredSwitches+="f";
					}
					
					if ( -1 != csLocal.Find( "-R") )
					{
						csStoredSwitches+="R";
					}
				}
			}

			// mode who
			CString csStoredModeWho;
			csLocal = pcsaArguments->GetAt(2);
			if ( -1 != csLocal.Find( "u -") )
			{
				csStoredModeWho+="u";
			}
				
			if ( -1 != csLocal.Find( "g -") )
			{
				csStoredModeWho+="g";
			}
				
			if ( -1 != csLocal.Find( "o -") )
			{
				csStoredModeWho+="o";
			}
	
			if ( -1 != csLocal.Find( "a -") )
			{
				csStoredModeWho+="a";
			}
			
			// add a space after any mode who
			if ( csStoredModeWho.GetLength() != 0 )
			{
				csStoredModeWho+=" ";
			}

			// mode op
			CString csStoredModeop;
			csLocal = pcsaArguments->GetAt(3);
			if ( -1 != csLocal.Find( "+ -") )
			{
				csStoredModeop+="+ ";
			}
			else if ( -1 != csLocal.Find( "- -") )
			{
				csStoredModeop+="- ";
			}
			else // "="
			{
				csStoredModeop+="= ";
			}


			// mode permission
			CString csStoredModePermission;
			csLocal = pcsaArguments->GetAt(4);
			if ( -1 != csLocal.Find( "r -") )
			{
				csStoredModePermission+="r";
			}

			if ( -1 != csLocal.Find( "x -") )
			{
				csStoredModePermission+="x";
			}

			if ( -1 != csLocal.Find( "X -") )
			{
				csStoredModePermission+="X";
			}

			if ( -1 != csLocal.Find( "w -") )
			{
				csStoredModePermission+="w";
			}

			if ( -1 != csLocal.Find( "h -") )
			{
				csStoredModePermission+="h";
			}

			if ( -1 != csLocal.Find( "a -") )
			{
				csStoredModePermission+="a";
			}

			if ( -1 != csLocal.Find( "s -") )
			{
				csStoredModePermission+="s";
			}

			if ( -1 != csLocal.Find( "t -") )
			{
				csStoredModePermission+="t";
			}


			csViewOutStuff.Format( "chmod %s %s %s %s %s",	csStoredSwitches, 
															csStoredModeWho, 
															csStoredModeop, 
															csStoredModePermission, 
															pcsaArguments->GetAt(5) );
			pcsaBody->Add(csViewOutStuff);

		}
		break;

		case 3:    //comment - insert comment
		{
			csViewOutStuff.Format( "rem ********** %s", pcsaArguments->GetAt(1) );
			pcsaBody->Add(csViewOutStuff);
		}
		break;

		case 4:		//cp - copy files
		{
			// reproduction options
			CString csReproductionOptions;
			CString csLocal( pcsaArguments->GetAt(1) );
			if ( -1 != csLocal.Find( "None") )
			{
				csReproductionOptions="";
			}
			else 			
			{
				
				if ( -1 != csLocal.Find( "-r") || -1 != csLocal.Find( "-R") )
				{
					csReproductionOptions="-";

					if ( -1 != csLocal.Find( "-r") )
					{
						csReproductionOptions+="r";
					}
					
					if ( -1 != csLocal.Find( "-R") )
					{
						csReproductionOptions+="R";
					}
				}
			}

			// general options
			CString csGeneralOptions;
			csLocal = pcsaArguments->GetAt(2);
			if ( -1 != csLocal.Find( "-c") || 
				 -1 != csLocal.Find( "-f") ||
				 -1 != csLocal.Find( "-i") ||
				 -1 != csLocal.Find( "-m") ||
				 -1 != csLocal.Find( "-p") ||
				 -1 != csLocal.Find( "-v") )
			{
				csGeneralOptions="-";
			}

			if ( -1 != csLocal.Find( "c -") )
			{
				csGeneralOptions+="c";
			}
				
			if ( -1 != csLocal.Find( "f -") )
			{
				csGeneralOptions+="f";
			}
				
			if ( -1 != csLocal.Find( "i -") )
			{
				csGeneralOptions+="i";
			}
	
			if ( -1 != csLocal.Find( "m -") )
			{
				csGeneralOptions+="m";
			}
			
			if ( -1 != csLocal.Find( "p -") )
			{
				csGeneralOptions+="p";
			}
			
			if ( -1 != csLocal.Find( "v -") )
			{
				csGeneralOptions+="v";
			}
			

			csViewOutStuff.Format( "cp %s %s %s %s",	csReproductionOptions, 
															csGeneralOptions, 
															pcsaArguments->GetAt(3),
															pcsaArguments->GetAt(4) );
			pcsaBody->Add(csViewOutStuff);

		}
		break;

		case 5:		//csplit - split text file
		{
			CString csStoredSwitches="";
			CString csLocal( pcsaArguments->GetAt(1) );
			if ( -1 != csLocal.Find( "None") )
			{
				csStoredSwitches="";
			}
			else 			
			{
				
				if ( -1 != csLocal.Find( "-A") ||
					 -1 != csLocal.Find( "-a") ||
					 -1 != csLocal.Find( "-k") ||
					 -1 != csLocal.Find( "-e") )
				{
					csStoredSwitches="-";
				}

				if ( -1 != csLocal.Find( "-a") )
				{
					csStoredSwitches+="a";
				}
				
				if ( -1 != csLocal.Find( "-A") )
				{
					csStoredSwitches+="A";
				}
				
				if ( -1 != csLocal.Find( "-k") )
				{
					csStoredSwitches+="k";
				}
				
				if ( -1 != csLocal.Find( "-e") )
				{
					csStoredSwitches+="e";
				}

			}

			csViewOutStuff.Format( "csplit %s %s %s %s %s", csStoredSwitches, 
															pcsaArguments->GetAt(2), 
															pcsaArguments->GetAt(3),
															pcsaArguments->GetAt(4),
															pcsaArguments->GetAt(5) );
			pcsaBody->Add(csViewOutStuff);

		}
		break;
	
		case 6:		//diff - compare text files
		case 7:		//dircmp - compare directories
		case 8:		//egrep - search files w/extended regexp
		case 9:		//env
		case 10:    //expand -- expand tabs to spaces
		case 11:    //find
		{
		}
		break;

		case 12:    //fgrep - search files for strings
		case 13:    //grep
		{
			CString csStoredSwitches;
			CString csLocal( pcsaArguments->GetAt(1) );
			if ( -1 != csLocal.Find( "None") )
			{
				csStoredSwitches="";
			}
			else 			
			{
				
				if ( -1 != csLocal.Find( "-b") )
				{
					csStoredSwitches+=" -b";
				}
				
				if ( -1 != csLocal.Find( "-c") )
				{
					csStoredSwitches+=" -c";
				}
				
				if ( -1 != csLocal.Find( "-E") )
				{
					csStoredSwitches+=" -E";
				}
				
				if ( -1 != csLocal.Find( "-i") )
				{
					csStoredSwitches+=" -i";
				}
				
				if ( -1 != csLocal.Find( "-l") )
				{
					csStoredSwitches+=" -l";
				}
				
				if ( -1 != csLocal.Find( "-n") )
				{
					csStoredSwitches+=" -n";
				}
				
				if ( -1 != csLocal.Find( "-q") )
				{
					csStoredSwitches+=" -q";
				}

				if ( -1 != csLocal.Find( "-s") )
				{
					csStoredSwitches+=" -s";
				}
				
				if ( -1 != csLocal.Find( "-v") )
				{
					csStoredSwitches+=" -v";
				}
				
				if ( -1 != csLocal.Find( "-x") )
				{
					csStoredSwitches+=" -x";
				}

			}

			CString csPattern, csPatternFile, csSeekFile;
			
			if ( 0 < pcsaArguments->GetAt(2).GetLength() )
			{
				csPattern  = "-e \"" + pcsaArguments->GetAt(2) + "\"";
			}
			
			if ( 0 < pcsaArguments->GetAt(3).GetLength() )
			{
				csPatternFile = "-f " + pcsaArguments->GetAt(3);
			}

			if ( 0 < pcsaArguments->GetAt(4).GetLength() )
			{
				csSeekFile = pcsaArguments->GetAt(4);
			}

			

			if ( nFunctionNum == 12 )	// fgrep
			{
				csViewOutStuff.Format( "fgrep %s %s %s %s", csStoredSwitches, csPattern, csPatternFile, csSeekFile );
			}
			else	// egrep (e.g. egrep  -n -f test.in *.cpp >test.out)
			{
				csViewOutStuff.Format( "egrep %s %s %s %s", csStoredSwitches, csPattern, csPatternFile, csSeekFile );
			}

			pcsaBody->Add(csViewOutStuff);

		}
		break;

		case 14:		//gres
		{
			csViewOutStuff.Format( "gres %s %s %s", pcsaArguments->GetAt(1), pcsaArguments->GetAt(2), pcsaArguments->GetAt(3) );
			pcsaBody->Add(csViewOutStuff);
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

	pcsaArguments->RemoveAll();

}



void CAG_UNIX::finalize(CStringArray* pcsaBody)
{
	
}



void CAG_UNIX::declareVariable(AG_VARIABLE agVariable,
							  CStringArray* pcsaHeader,
							  bool* bValue)
{
	
}



void CAG_UNIX::loadTerminalTypeList(CListBox* listTerminalTypes)
{
	listTerminalTypes->ResetContent();
}


void CAG_UNIX::loadFunctionList(CListBox* listTranslateFunction)
{
	csaFunctions.RemoveAll();

	csaFunctions.Add("cat - concatenate files");
	csaFunctions.Add("cd - change working directory");
	csaFunctions.Add("chmod - change file access");
	csaFunctions.Add("comment - insert comment");
	csaFunctions.Add("cp - copy files");
	csaFunctions.Add("csplit - split text file");
	csaFunctions.Add("diff - compare text files");
	csaFunctions.Add("dircmp - compare directories");
	csaFunctions.Add("egrep - search files w/extended regexp");
	csaFunctions.Add("env -- ***");
	csaFunctions.Add("expand -- expand tabs to spaces");
	csaFunctions.Add("find -- ***");
	csaFunctions.Add("fgrep - search files for strings");

	csaFunctions.Add("grep - search files w/basic regexp");
	csaFunctions.Add("gres - substitue patterns in files");
	
	csaFunctions.Add("lc - list files/directories");
	csaFunctions.Add("look - find lines");
	csaFunctions.Add("ls - list files/directories");
	csaFunctions.Add("mkdir - ***");
	csaFunctions.Add("mv - rename/move files");
	csaFunctions.Add("pack - compress files");
	csaFunctions.Add("passwd - ***");
	csaFunctions.Add("pwd - ***");
	csaFunctions.Add("rmdir - ***");
	csaFunctions.Add("sleep - pause for specified time");
	csaFunctions.Add("sort - sort/merge");
	csaFunctions.Add("stty - ***");
	csaFunctions.Add("tar - copy/backup files");
	csaFunctions.Add("tr - translation");
	csaFunctions.Add("tsort - topological sort");
	csaFunctions.Add("uniq - display unique lines");
	csaFunctions.Add("wc - word/char count");
	csaFunctions.Add("who - display user info");

	listTranslateFunction->ResetContent();	
	
	for (int k=0; k<csaFunctions.GetSize(); k++)
	{
		listTranslateFunction->AddString( csaFunctions.GetAt(k) );
	}

	listTranslateFunction->SetCurSel(0);
	
}

void CAG_UNIX::loadLanguageList(CListBox* listTranslateLanguage)
{
	int nPos = 0;

	listTranslateLanguage->ResetContent();
	listTranslateLanguage->InsertString( nPos++, "UNIX command" );
	
	listTranslateLanguage->SetCurSel(0);
	
}

void CAG_UNIX::checkDebug(bool b_Debug,
						 CString csFunctionName,
						 CStringArray* pcsaBody)
{
	
}


void CAG_UNIX::resetVariableFlags()
{
}

