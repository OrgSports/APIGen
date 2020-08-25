#include "stdafx.h"
#include "APIGen.h"
#include "APIGenDlg.h"



/****************************************************************************DC
	Function	:	CAPIGenDlg::ShowCASLControls()

	Purpose		:	Show the controls for the CASL Macro function parameters.

	Note		:	

*****************************************************************************/
void CAPIGenDlg::ShowCASLControls( int nFunction )
{
	HideParameterControls();
	csaLabels.RemoveAll();
	BOOL bYouShouldGo=TRUE;

	switch ( nFunction )
	{
		case 1:    //activate
		case 12:    //bye
		case 17:    //choice
		case 32:    //curdrive
		case 52:    //end
		case 59:    //errclass
		case 60:    //errno
		case 61:    //error
		case 63:    //exit
		case 71:    //freemem
		case 72:    //freetrack
		case 77:    //go
		case 80:    //grab
		case 81:    //halt
		case 84:    //hide
		case 85:    //hideallquickpads
		case 88:    //homedir
		case 92:    //inkey
		case 107:    //match
		case 109:    //maximize
		case 112:    //minimize
		case 117:    //name
		case 120:    //nextchar
		case 125:    //off
		case 126:    //on
		case 127:    //online			online & connected ARE IDENTICAL
		case 26:    //connected
		case 128:    //ontime
		case 135:    //pop
		case 142:    //quit
		case 151:    //restore
		case 162:    //sendbreak
		case 163:    //session
		case 166:    //show
		case 173:    //stroke
		case 175:    //systime
		case 176:    //tabwidth
		case 178:    //terminate
		case 180:    //timeout
		case 185:    //true
		case 186:    //unloadallquickpads
		case 191:    //version
		case 197:    //winsizex
		case 198:    //winsizey
		case 200:    //winversion
		case 203:    //xpos
		case 204:    //ypos
		case 205:    //zoom
		{
		}
		break;

		case 0:    //abs
		case 9:    //binary
		case 30:    //curday
		case 33:    //curhour
		case 34:    //curminute
		case 35:    //curmonth
		case 36:    //cursecond
		case 37:    //curyear
		{
			csaLabels.Add("Numeric value");
		}
		break;

		case 2:    //activatesession
		{
			csaLabels.Add("Session ID");
		}
		break;

		case 3:    //alarm
		{
			csaLabels.Add("Session ID");
			bYouShouldGo=FALSE;
		}
		break;

		case 4:    //alert
		{
			csaLabels.Add("Prompt string");
			csaLabels.Add("Button 1 text");
			csaLabels.Add("[Button 2 text]");
			csaLabels.Add("[Button 3 text]");
			csaLabels.Add("[Button 4 text]");
			csaLabels.Add("[Return string]");
		}
		break;

		case 5:    //arg
		{
			csaLabels.Add("[Argument number]");
		}
		break;

		case 6:    //asc
		{
			csaLabels.Add("Convert string");
		}
		break;

		case 7:    //assume
		{
			csaLabels.Add("Connection tool");
			csaLabels.Add("Terminal tool");
			csaLabels.Add("File transfer tool");
			bYouShouldGo=FALSE;
		}
		break;

		case 8:    //backups
		{
			csaLabels.Add("Backup option");
			bYouShouldGo=FALSE;
		}
		break;

		case 10:    //bitstrip
		{
			csaLabels.Add("Number");
			csaLabels.Add("Mask (default 0x7F)");
		}
		break;

		case 11:    //busycursor
		{
			csaLabels.Add("Busy cursor");
			bYouShouldGo=FALSE;
		}
		break;

		case 13:    //capture
		{
			csaLabels.Add("Option");
			csaLabels.Add("Filename");
			bYouShouldGo=FALSE;
		}
		break;

		case 14:    //case/endcase
		{
			csaLabels.Add("Test expression");
			csaLabels.Add("Expression/statement list (csv)");
		}
		break;

		case 15:    //chain
		{
			csaLabels.Add("Macro name");
			csaLabels.Add("Command line arguments (csv)");
			bYouShouldGo=FALSE;
		}
		break;

		case 16:    //chdir
		{
			csaLabels.Add("New directory");
		}
		break;

		case 18:    //chr
		{
			csaLabels.Add("ASCII offset number");
		}
		break;

		case 19:    //cksum
		case 20:    //class
		{
			csaLabels.Add("String");
		}
		break;

		case 21:    //clear
		case 23:    //cls
		{
			csaLabels.Add("Option");
			bYouShouldGo=FALSE;
		}
		break;

		case 22:    //close
		{
			csaLabels.Add("File number");
		}
		break;

		case 24:    //comment
		{
			csaLabels.Add("CASL code comment");
		}
		break;


		case 25:    //compile
		{
			csaLabels.Add("File name");
			bYouShouldGo=FALSE;
		}
		break;

		case 27:    //copy
		{
			csaLabels.Add("Prefix with \"some\"?");
			csaLabels.Add("From file source");
			csaLabels.Add("To file destination");
			bYouShouldGo=FALSE;
		}
		break;

		case 28:    //count
		{
			csaLabels.Add("In this string");
			csaLabels.Add("Count occurrences of:");
		}
		break;

		case 29:    //crc
		{
			csaLabels.Add("String");
			csaLabels.Add("[Start value]");
		}
		break;

		case 31:    //curdir
		{
			csaLabels.Add("[Directory]");
		}
		break;

		case 38:    //date
		{
			csaLabels.Add("[Day]");
		}
		break;

		case 39:    //definput
		case 40:    //defoutput
		{
			csaLabels.Add("File number");
		}
		break;


		case 41:    //dehex
		{
			csaLabels.Add("Number|variable");
		}
		break;

		case 42:    //delete
		{
			csaLabels.Add("Suppress user intervention");
			csaLabels.Add("{File}");
			bYouShouldGo=FALSE;
		}
		break;

		case 43:    //delete 2
		{
			csaLabels.Add("String");
			csaLabels.Add("Start");
			csaLabels.Add("Length");
		}
		break;

		case 44:    //description
		{
			csaLabels.Add("Set description (vs get)");
			csaLabels.Add("Description text");
			bYouShouldGo=FALSE;
		}
		break;

		case 45:    //destore
		case 46:    //detext
		case 53:    //enhex
		case 54:    //enstore
		case 55:    //entext
		case 102:    //length
		case 105:    //lowcase
		case 123:    //null
		case 143:    //quote
		{
			csaLabels.Add("String");
		}
		break;

		case 47:    //device
		{
			csaLabels.Add("Set tool name (vs get)");
			csaLabels.Add("Tool name");
			bYouShouldGo=FALSE;
		}
		break;

		case 48:    //dialogbox
		{
			csaLabels.Add("Top-left x-position");
			csaLabels.Add("Top-left y-position");
			csaLabels.Add("Width");
			csaLabels.Add("Height");
			csaLabels.Add("Caption");
		}
		break;

		case 49:    //display
		{
			csaLabels.Add("Display incoming chars");
			bYouShouldGo=FALSE;
		}
		break;

		case 50:    //do
		{
			csaLabels.Add("File name");
			csaLabels.Add("Options (csv)");
			bYouShouldGo=FALSE;
		}
		break;

		case 51:    //drive
		{
			csaLabels.Add("Drive");
		}
		break;

		case 56:    //environ
		{
			csaLabels.Add("Environment variable");
		}
		break;

		case 57:    //eof
		case 58:    //eol
		{
			csaLabels.Add("File number");
		}
		break;

		case 62:    //exists
		{
			csaLabels.Add("File | dir name");
		}
		break;

		case 64:    //false
		{
			csaLabels.Add("Variable name");
		}
		break;

		case 65:    //filefind
		{
			csaLabels.Add("Find file");
			csaLabels.Add("Attribute mask");
		}
		break;

		case 66:    //filesize
		case 67:    //fncheck
		case 90:    //include
		{
			csaLabels.Add("File name");
		}
		break;

		case 68:    //fnstrip
		{
			csaLabels.Add("File name");
			csaLabels.Add("Specifier");
			bYouShouldGo=FALSE;
		}
		break;

		case 69:    //footer
		{
			csaLabels.Add("Footer string");
		}
		break;

		case 70:    //for/next
		{
			csaLabels.Add("Variable name");
			csaLabels.Add("Start value");
			csaLabels.Add("End value");
			csaLabels.Add("Step size");
		}
		break;

		case 73:    //func/endfunc
		{
			csaLabels.Add("Function name");
			csaLabels.Add("[{([Type] argument),}]");
			csaLabels.Add("Return type");
		}
		break;

		case 74:    //genlabels
		{
			csaLabels.Add("Label option");
			bYouShouldGo=FALSE;
		}
		break;

		case 75:    //genlines
		{
			csaLabels.Add("Line option");
			bYouShouldGo=FALSE;
		}
		break;

		case 76:    //get
		{
			csaLabels.Add("File number");
			csaLabels.Add("Read bytes");
		}
		break;

		case 78:    //gosub/return
		{
			csaLabels.Add("Label name");
		}
		break;

		case 79:    //goto
		case 98:    //jump
		{
			csaLabels.Add("Label | expression");
		}
		break;

		case 82:    //header
		{
			csaLabels.Add("Header string");
		}
		break;

		case 83:    //hex
		{
			csaLabels.Add("Conversion integer");
		}
		break;

		case 87:    //hms
		{
			csaLabels.Add("Conversion integer (.1 secs)");
			csaLabels.Add("Time format (e.g. 101/10 secs)");
			bYouShouldGo=FALSE;
		}
		break;

		case 89:    //if/then/else
		{
			csaLabels.Add("Expression/Condition");
			csaLabels.Add("Statement");
			csaLabels.Add("Use else");
			csaLabels.Add("[Else statement]");
			bYouShouldGo=FALSE;
		}
		break;

		case 91:    //inject
		{
			csaLabels.Add("Original string");
			csaLabels.Add("Inject string");
			csaLabels.Add("[Start position]");
		}
		break;

		case 93:    //input
		{
			csaLabels.Add("Input string");
		}
		break;

		case 94:    //inscript
		{
			csaLabels.Add("Script label");
		}
		break;

		case 95:    //insert
		{
			csaLabels.Add("Original string");
			csaLabels.Add("Insert string");
			csaLabels.Add("[Start position]");
		}
		break;

		case 96:    //instr
		{
			csaLabels.Add("Original string");
			csaLabels.Add("Search string");
			csaLabels.Add("[Start position]");
		}
		break;

		case 97:    //intval
		{
			csaLabels.Add("Number string");
		}
		break;

		case 99:    //keys
		{
			csaLabels.Add("Set keyboard map");
			csaLabels.Add("Keyboard map filename");
			bYouShouldGo=FALSE;
		}
		break;

		case 100:    //label
		{
			csaLabels.Add("New label name");
		}
		break;

		case 101:    //left
		case 153:    //right
		{
			csaLabels.Add("Original string");
			csaLabels.Add("[Number of copied chars]");
		}
		break;

		case 103:    //loadquickpad
		case 167:    //showquickpad
		{
			csaLabels.Add("Quickpad name");
		}
		break;

		case 104:    //loc
		{
			csaLabels.Add("[File number]");
		}
		break;

		case 106:    //lprint
		{
			csaLabels.Add("Statement");
		}
		break;

		case 108:    //max
		case 111:    //min
		{
			csaLabels.Add("First number");
			csaLabels.Add("Second number");
		}
		break;

		case 110:    //mid
		{
			csaLabels.Add("String");
			csaLabels.Add("Start position");
			csaLabels.Add("[Length]");
		}
		break;

		case 113:    //mkdir
		{
			csaLabels.Add("Directory name");
		}
		break;

		case 114:    //mkint
		{
			csaLabels.Add("String to convert");
		}
		break;

		case 115:    //mkstr
		{
			csaLabels.Add("Integer to convert");
		}
		break;

		case 116:    //move
		{
			csaLabels.Add("Target x-coordinate");
			csaLabels.Add("Target y-coordinate");
		}
		break;

		case 118:    //netid
		{
			csaLabels.Add("Set network ID");
			csaLabels.Add("New network ID");
			bYouShouldGo=FALSE;
		}
		break;

		case 119:    //new
		{
			csaLabels.Add("Create or open file");
			bYouShouldGo=FALSE;
		}
		break;

		case 121:    //nextline
		case 122:    //nextline 2
		{
			csaLabels.Add("Expiration time (secs)");
			csaLabels.Add("Char accumulation limit");
		}
		break;

		case 124:    //octal
		{
			csaLabels.Add("Number");
		}
		break;

		case 129:    //open
		{
			csaLabels.Add("File-open mode");
			csaLabels.Add("File name");
			csaLabels.Add("File number");
			bYouShouldGo=FALSE;
		}
		break;

		case 130:    //pack
		{
			csaLabels.Add("String to compress");
			csaLabels.Add("Wild characters");
			csaLabels.Add("Compression mode");
			bYouShouldGo=FALSE;
		}
		break;

		case 131:    //pad
		{
			csaLabels.Add("String to pad");
			csaLabels.Add("Return string size");
			csaLabels.Add("Pad character");
			csaLabels.Add("Pad where");
			bYouShouldGo=FALSE;
		}
		break;

		case 132:    //passchar
		{
			csaLabels.Add("Password replacement char");
		}
		break;

		case 133:    //password
		{
			csaLabels.Add("Set password (vs get)");
			csaLabels.Add("New password");
			bYouShouldGo=FALSE;
		}
		break;

		case 134:    //perform
		{
			csaLabels.Add("Procedure name");
			csaLabels.Add("Argument list (csv)");
		}
		break;

		case 136:    //press
		{
			csaLabels.Add("Key sequence");
			csaLabels.Add("Append special chars");
			bYouShouldGo=FALSE;
		}
		break;

		case 137:    //print
		{
			csaLabels.Add("Print command line");
		}
		break;

		case 138:    //printer
		{
			csaLabels.Add("Print option");
			bYouShouldGo=FALSE;
		}
		break;

		case 139:    //proc/endproc
		{
			csaLabels.Add("Procedure name");
			csaLabels.Add("Argument names (csv)");
			csaLabels.Add("Argument types (csv)");
		}
		break;

		case 140:    //protocol
		{
			csaLabels.Add("Set protocol (vs get)");
			csaLabels.Add("File transfer protocol");
			bYouShouldGo=FALSE;
		}
		break;

		case 141:    //put
		{
			csaLabels.Add("File number");
			csaLabels.Add("Insert string");
		}
		break;

		case 144:    //read
		case 145:    //read line
		{
			csaLabels.Add("File number");
			csaLabels.Add("String variables (csv)");
		}
		break;

		case 146:    //receive
		case 150:    //request
		{
			csaLabels.Add("Host filename");
		}
		break;

		case 147:    //rename
		{
			csaLabels.Add("Prefix with \"some\"?");
			csaLabels.Add("{Original file name}");
			csaLabels.Add("{New file name}");
			bYouShouldGo=FALSE;
		}
		break;

		case 148:    //repeat/until
		{
			csaLabels.Add("Exit condition");
			csaLabels.Add("Repeated statements (csv)");
		}
		break;

		case 149:    //reply
		{
			csaLabels.Add("Send string");
		}
		break;

		case 152:    //return
		{
			csaLabels.Add("Function? (vs subroutine)");
			csaLabels.Add("Return expression");
			bYouShouldGo=FALSE;
		}
		break;

		case 154:    //rmdir
		{
			csaLabels.Add("Directory name");
		}
		break;

		case 155:    //run
		{
			csaLabels.Add("Application name");
		}
		break;

		case 156:    //save
		{
			csaLabels.Add("[Session name]");
		}
		break;

		case 157:    //script
		{
			csaLabels.Add("Session startup macro");
			bYouShouldGo=FALSE;
		}
		break;

		case 158:    //scriptdesc
		{
			csaLabels.Add("Macro description");
		}
		break;

		case 159:    //secno
		{
			csaLabels.Add("[hh,mm,ss]");
		}
		break;

		case 160:    //seek
		{
			csaLabels.Add("File number");
			csaLabels.Add("New file pointer offset");
		}
		break;

		case 161:    //send
		{
			csaLabels.Add("Transfer file name");
			bYouShouldGo=FALSE;
		}
		break;

		case 164:    //sessname
		{
			csaLabels.Add("Session number");
		}
		break;

		case 165:    //sessno
		{
			csaLabels.Add("Session name");
		}
		break;

		case 168:    //size
		{
			csaLabels.Add("Window width");
			csaLabels.Add("Window height");
		}
		break;

		case 169:    //slice
		{
			csaLabels.Add("Start string");
			csaLabels.Add("Target offset");
			csaLabels.Add("[Delimiter string]");
			csaLabels.Add("[Start location]");
		}
		break;

		case 170:    //startup
		{
			csaLabels.Add("Set startup macro (vs get)");
			csaLabels.Add("Macro filename");
			bYouShouldGo=FALSE;
		}
		break;

		case 171:    //str
		{
			csaLabels.Add("Convert number");
		}
		break;

		case 172:    //strip
		{
			csaLabels.Add("String to strip");
			csaLabels.Add("Wild characters");
			csaLabels.Add("Strip mode");
			bYouShouldGo=FALSE;
		}
		break;

		case 174:    //subst
		{
			csaLabels.Add("Original string");
			csaLabels.Add("String to replace");
			csaLabels.Add("Replace with:");
		}
		break;

		case 177:    //terminal
		{
			csaLabels.Add("Set emulation type (vs get)");
			csaLabels.Add("Terminal type");
			bYouShouldGo=FALSE;
		}
		break;

		case 179:    //time
		{
			csaLabels.Add("Seconds value");
		}
		break;

		case 181:    //trace
		{
			csaLabels.Add("Line numbers");
			bYouShouldGo=FALSE;
		}
		break;

		case 182:    //track statement
		{
			csaLabels.Add("Track number");
			csaLabels.Add("Condition");
		}
		break;

		case 183:    //track function
		{
			csaLabels.Add("Track number");
		}
		break;

		case 184:    //trap
		{
			csaLabels.Add("Error response");
			bYouShouldGo=FALSE;
		}
		break;

		case 187:    //unloadquickpad		// EQUIVALENT
		case 86:    //hidequickpad
		{
			csaLabels.Add("Quickpad name");
		}
		break;

		case 188:    //upcase
		{
			csaLabels.Add("Shift string to uppercase");
		}
		break;

		case 189:    //userid
		{
			csaLabels.Add("Set user ID (vs get)");
			csaLabels.Add("Set user ID to:");
			bYouShouldGo=FALSE;
		}
		break;

		case 190:    //val
		{
			csaLabels.Add("Return numeric value of:");
		}
		break;

		case 192:    //wait
		{
			csaLabels.Add("Time");
			csaLabels.Add("Condition type");
			csaLabels.Add("Condition");
			bYouShouldGo=FALSE;
		}
		break;

		case 193:    //watch/endwatch
		{
			csaLabels.Add("[Time]");
			csaLabels.Add("Condition type");
			csaLabels.Add("Condition");
			csaLabels.Add("CASL reaction");
			bYouShouldGo=FALSE;
		}
		break;

		case 194:    //weekday
		{
			csaLabels.Add("Date integer");
		}
		break;

		case 195:    //while/wend
		{
			csaLabels.Add("Condition");
			csaLabels.Add("statement [{, statement}]");
		}
		break;

		case 196:    //winchar
		{
			csaLabels.Add("Row");
			csaLabels.Add("Column");
		}
		break;

		case 199:    //winstring
		{
			csaLabels.Add("Row");
			csaLabels.Add("Column");
			csaLabels.Add("Length");
		}
		break;

		case 201:    //write
		{
			csaLabels.Add("[File number]");
			csaLabels.Add("Write string [{, write string}]");
			csaLabels.Add("[String delimiter char]");
		}
		break;

		case 202:    //write line
		{
			csaLabels.Add("[File number]");
			csaLabels.Add("Write string [{, write string}]");
			csaLabels.Add("[Line delimiter char]");
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
		ShowMixedControls( CASL_API, nFunction, &csaLabels );	
	}

}




/****************************************************************************DC
	Function	:	CAPIGenDlg::LoadCASLArgumentArray()

	Purpose		:	Load the function arguments for Reflection FTP

*****************************************************************************/
void CAPIGenDlg::LoadCASLArgumentArray( int* nFunction, BOOL bPromptForValues )
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
			case 1:    //activate
			case 12:    //bye
			case 17:    //choice
			case 52:    //end
			case 59:    //errclass
			case 60:    //errno
			case 61:    //error
			case 63:    //exit
			case 71:    //freemem
			case 72:    //freetrack
			case 77:    //go
			case 80:    //grab
			case 81:    //halt
			case 84:    //hide
			case 85:    //hideallquickpads
			case 88:    //homedir
			case 92:    //inkey
			case 107:    //match
			case 109:    //maximize
			case 112:    //minimize
			case 117:    //name
			case 120:    //nextchar
			case 125:    //off
			case 126:    //on
			case 127:    //online
			case 26:    //connected
			case 128:    //ontime
			case 135:    //pop
			case 142:    //quit
			case 151:    //restore
			case 163:    //session
			case 166:    //show
			case 173:    //stroke
			case 175:    //systime
			case 176:    //tabwidth
			case 178:    //terminate
			case 180:    //timeout
			case 185:    //true
			case 186:    //unloadallquickpads
			case 191:    //version
			case 197:    //winsizex
			case 198:    //winsizey
			case 200:    //winversion
			case 203:    //xpos
			case 204:    //ypos
			case 205:    //zoom
			{
			}
			break;

			case 30:    //curday
			case 31:    //curdir
			case 32:    //curdrive
			case 33:    //curhour
			case 34:    //curminute
			case 35:    //curmonth
			case 36:    //cursecond
			case 37:    //curyear
			case 38:    //date
			case 39:    //definput
			case 40:    //defoutput
			case 41:    //dehex
			case 45:    //destore
			case 46:    //detext
			case 51:    //drive
			case 53:    //enhex
			case 54:    //enstore
			case 55:    //entext
			case 56:    //environ
			case 57:    //eof
			case 58:    //eol
			case 62:    //exists
			case 64:    //false
			case 66:    //filesize
			case 67:    //fncheck
			case 69:    //footer
			case 78:    //gosub/return
			case 79:    //goto
			case 82:    //header
			case 83:    //hex
			case 86:    //hidequickpad
			case 90:    //include
			case 93:    //input
			case 94:    //inscript
			case 97:    //intval
			case 98:    //jump
			case 100:    //label
			case 102:    //length
			case 103:    //loadquickpad
			case 104:    //loc
			case 105:    //lowcase
			case 106:    //lprint
			case 113:    //mkdir
			case 114:    //mkint
			case 115:    //mkstr
			case 123:    //null
			case 124:    //octal
			case 132:    //passchar
			case 137:    //print
			case 143:    //quote
			case 146:    //receive
			case 149:    //reply
			case 150:    //request
			case 154:    //rmdir
			case 155:    //run
			case 156:    //save
			case 158:    //scriptdesc
			case 159:    //secno
			case 164:    //sessname
			case 165:    //sessno
			case 167:    //showquickpad
			case 171:    //str
			case 179:    //time
			case 183:    //track function
			case 187:    //unloadquickpad
			case 188:    //upcase
			case 190:    //val
			case 194:    //weekday
			case 0:    //abs
			case 2:    //activatesession
			case 5:    //arg
			case 6:    //asc
			case 9:    //binary
			case 16:    //chdir
			case 18:    //chr
			case 19:    //cksum
			case 20:    //class
			case 22:    //close
			case 24:    //comment
			case 25:    //compile
			case 119:    //new
			case 157:    //script
			case 161:    //send
			{
				Read1E( &csaArguments );
			}
			break;

			case 68:    //fnstrip
			case 87:    //hms
			case 136:    //press
			{
				Read1E1L( &csaArguments );
			}
			break;


			case 192:    //wait
			{
				Read1E1L1E( &csaArguments );
			}
			break;

			case 193:    //watch/endwatch
			{
				Read1E1L2E( &csaArguments );
			}
			break;


			case 3:    //alarm
			case 8:    //backups
			case 11:    //busycursor
			case 21:    //clear
			case 23:    //cls
			case 138:    //printer
			case 181:    //trace
			case 184:    //trap
			{
				Read1L( &csaArguments );
			}
			break;

			case 13:    //capture
			{
				Read1L1E( &csaArguments );
			}
			break;


			case 129:    //open
			{
				Read1L2E( &csaArguments );
			}
			break;

			case 49:    //display
			case 74:    //genlabels
			case 75:    //genlines
			{
				Read1C( &csaArguments );
			}
			break;

			case 42:    //delete
			case 44:    //description
			case 47:    //device
			case 118:    //netid
			case 133:    //password
			case 152:    //return
			case 99:    //keys
			case 170:    //startup
			case 189:    //userid
			{
				Read1C1E( &csaArguments );
			}
			break;

			case 140:    //protocol
			case 177:    //terminal
			{
				Read1C1L( &csaArguments );
			}
			break;


			case 27:    //copy
			case 147:    //rename
			{
				Read1C2E( &csaArguments );
			}
			break;


			case 4:    //alert
			{
				Read6E( &csaArguments );
			}
			break;

			case 10:   //bitstrip
			case 14:    //case/endcase
			case 15:    //chain
			case 50:    //do
			case 76:    //get
			{
				Read2E( &csaArguments );
			}
			break;

			case 130:    //pack
			case 172:    //strip
			{
				Read2E1L( &csaArguments );
			}
			break;

			case 89:    //if/then/else
			{
				Read2E1C1E( &csaArguments );
			}
			break;

			case 28:    //count
			case 29:    //crc
			case 65:    //filefind
			case 101:    //left
			case 108:    //max
			case 111:    //min
			case 116:    //move
			case 121:    //nextline
			case 122:    //nextline 2
			case 134:    //perform
			case 141:    //put
			case 144:    //read
			case 145:    //read line
			case 148:    //repeat/until
			case 153:    //right
			case 160:    //seek
			case 162:    //sendbreak
			case 168:    //size
			case 182:    //track statment
			case 195:    //while/wend
			case 196:    //winchar
			{
				Read2E( &csaArguments );
			}
			break;

			case 43:    //delete 2
			case 73:    //func/endfunc
			case 91:    //inject
			case 95:    //insert
			case 96:    //instr
			case 110:    //mid
			case 139:    //proc/endproc
			case 174:    //subst
			case 199:    //winstring
			case 201:    //write
			case 202:    //write line
			{
				Read3E( &csaArguments );
			}
			break;

			case 131:    //pad
			{
				Read3E1L( &csaArguments );
			}
			break;

			case 7:    //assume
			{
				Read3L( &csaArguments );
			}
			break;

			case 70:    //for/next
			case 169:    //slice
			{
				Read4E( &csaArguments );
			}
			break;


			case 48:    //dialogbox
			{
				Read5E( &csaArguments );
			}
			break;


		}
	}
	else
	{
		switch ( *nFunction )
		{
			case 1:    //activate
			case 12:    //bye
			case 17:    //choice
			case 30:    //curday
			case 32:    //curdrive
			case 33:    //curhour
			case 34:    //curminute
			case 35:    //curmonth
			case 36:    //cursecond
			case 37:    //curyear
			case 52:    //end
			case 59:    //errclass
			case 60:    //errno
			case 61:    //error
			case 63:    //exit
			case 71:    //freemem
			case 72:    //freetrack
			case 77:    //go
			case 80:    //grab
			case 81:    //halt
			case 84:    //hide
			case 85:    //hideallquickpads
			case 88:    //homedir
			case 92:    //inkey
			case 107:    //match
			case 109:    //maximize
			case 112:    //minimize
			case 117:    //name
			case 120:    //nextchar
			case 125:    //off
			case 126:    //on
			case 127:    //online
			case 26:    //connected
			case 128:    //ontime
			case 135:    //pop
			case 142:    //quit
			case 151:    //restore
			case 162:    //sendbreak
			case 163:    //session
			case 166:    //show
			case 173:    //stroke
			case 175:    //systime
			case 176:    //tabwidth
			case 178:    //terminate
			case 180:    //timeout
			case 185:    //true
			case 186:    //unloadallquickpads
			case 191:    //version
			case 197:    //winsizex
			case 198:    //winsizey
			case 200:    //winversion
			case 203:    //xpos
			case 204:    //ypos
			case 205:    //zoom
			{
			}
			break;

			case 0:    //abs
			case 9:    //binary
			{
				csaArguments.Add( "-137" );
			}
			break;

			case 2:    //activatesession
			{
				csaArguments.Add( "rc2200.adp" );
			}
			break;

			case 3:    //alarm
			case 5:    //arg
			{
				csaArguments.Add( "1" );
			}
			break;

			case 4:    //alert
			{
				csaArguments.Add( "Procedure parameters" );
				csaArguments.Add( "ok" );
				csaArguments.Add( "cancel" );
				csaArguments.Add( "" );
				csaArguments.Add( "" );
				csaArguments.Add( "Please enter your username:" );
			}
			break;

			case 6:    //asc
			{
				csaArguments.Add( "Carnation" );
			}
			break;

			case 7:    //assume
			{
				csaArguments.Add( "A2200" );
				csaArguments.Add( "" );
				csaArguments.Add( "" );
			}
			break;

			case 8:    //backups
			{
				csaArguments.Add( "Rename with .bak" );
			}
			break;

			case 10:    //bitstrip
			{
				csaArguments.Add( "aacbb" );
				csaArguments.Add( "0x5F" );
			}
			break;

			case 11:    //busycursor
			{
				csaArguments.Add( "On" );
			}
			break;

			case 13:    //capture
			{
				csaArguments.Add( "new" );
				csaArguments.Add( "c:\\projects\\sales.txt" );
			}
			break;

			case 14:    //case/endcase
			{
				csaArguments.Add( "function" );
				csaArguments.Add( "run,startFunction,quit,stopFunction" );
			}
			break;

			case 15:    //chain
			{
				csaArguments.Add( "e:\\test14.xws" );
				csaArguments.Add( "100605.txt,24" );
			}
			break;

			case 16:    //chdir
			{
				csaArguments.Add( "e:\\vegetables\\carrots" );
			}
			break;

			case 18:    //chr
			{
				csaArguments.Add( "65" );
			}
			break;

			case 19:    //cksum
			{
				csaArguments.Add( "Abraham" );
			}
			break;

			case 20:    //class
			{
				csaArguments.Add( "SSSSA" );
			}
			break;

			case 21:    //clear
			case 23:    //cls
			{
				csaArguments.Add( "eol" );
			}
			break;

			case 22:    //close
			{
				csaArguments.Add( "2" );
			}
			break;

			case 24:    //comment
			{
				csaArguments.Add( "-- CASL comment" );
			}
			break;

			case 25:    //compile
			{
				csaArguments.Add( "prospector2005" );
			}
			break;

			case 27:    //copy
			{
				csaArguments.Add( "TRUE" );
				csaArguments.Add( "*.eps" );
				csaArguments.Add( "*.bak" );
			}
			break;

			case 28:    //count
			{
				csaArguments.Add( "mainframe" );
				csaArguments.Add( "a" );
			}
			break;

			case 29:    //crc
			{
				csaArguments.Add( "am" );
				csaArguments.Add( "0" );
			}
			break;

			case 31:    //curdir
			{
				csaArguments.Add( "sales" );
			}
			break;

			case 38:    //date
			{
				csaArguments.Add( "31354" );
			}
			break;

			case 39:    //definput
			{
				csaArguments.Add( "3" );
			}
			break;

			case 40:    //defoutput
			{
				csaArguments.Add( "2" );
			}
			break;

			case 41:    //dehex
			{
				csaArguments.Add( "0031" );
			}
			break;

			case 42:    //delete
			{
				csaArguments.Add( "f:\\deltest.zyx" );
			}
			break;

			case 43:    //delete 2
			{
				csaArguments.Add( "batmanana" );
				csaArguments.Add( "3" );
				csaArguments.Add( "2" );
			}
			break;

			case 44:    //description
			{
				csaArguments.Add( "Agent 1 Session" );
			}
			break;

			case 45:    //destore
			{
				csaArguments.Add( "^g" );
			}
			break;

			case 46:    //detext
			{
				csaArguments.Add( "abc" );
			}
			break;

			case 47:    //device
			{
				csaArguments.Add( "ICSTOOL" );
			}
			break;

			case 48:    //dialogbox
			{
				csaArguments.Add( "10" );
				csaArguments.Add( "10" );
				csaArguments.Add( "160" );
				csaArguments.Add( "170" );
				csaArguments.Add( "New dialog" );
			}
			break;

			case 49:    //display
			{
				csaArguments.Add( "TRUE" );
			}
			break;

			case 50:    //do
			{
				csaArguments.Add( "TotalSales.xws" );
				csaArguments.Add( "10/2005" );
			}
			break;

			case 51:    //drive
			{
				csaArguments.Add( "G:" );
			}
			break;

			case 53:    //enhex
			{
				csaArguments.Add( "la flamme" );
			}
			break;

			case 54:    //enstore
			{
				csaArguments.Add( "aw...dod" );
			}
			break;

			case 55:    //entext
			{
				csaArguments.Add( "abc" );
			}
			break;

			case 56:    //environ
			{
				csaArguments.Add( "PATH" );
			}
			break;

			case 57:    //eof
			case 58:    //eol
			{
				csaArguments.Add( "3" );
			}
			break;

			case 62:    //exists
			{
				csaArguments.Add( "BACKUP" );
			}
			break;

			case 64:    //false
			{
				csaArguments.Add( "bTotal" );
			}
			break;

			case 65:    //filefind
			{
				csaArguments.Add( "c:\\test.txt" );
				csaArguments.Add( "" );
			}
			break;

			case 66:    //filesize
			{
				csaArguments.Add( "accmgr32.exe" );
			}
			break;

			case 67:    //fncheck
			{
				csaArguments.Add( "c:\\test.txt" );
			}
			break;

			case 68:    //fnstrip
			{
				csaArguments.Add( "c:\\test.txt" );
				csaArguments.Add( "1" );
			}
			break;

			case 69:    //footer
			{
				csaArguments.Add( "Automotive Group Sales Report     2005" );
			}
			break;

			case 70:    //for/next
			{
				csaArguments.Add( "nRows" );
				csaArguments.Add( "0" );
				csaArguments.Add( "133" );
				csaArguments.Add( "1" );
			}
			break;

			case 73:    //func/endfunc
			{
				csaArguments.Add( "Process" );
				csaArguments.Add( "integer" );
				csaArguments.Add( "x" );
			}
			break;

			case 74:    //genlabels
			case 75:    //genlines
			{
				csaArguments.Add( "TRUE" );
			}
			break;

			case 76:    //get
			{
				csaArguments.Add( "3" );
				csaArguments.Add( "1024" );
			}
			break;

			case 78:    //gosub/return
			{
				csaArguments.Add( "PrintReport1" );
			}
			break;

			case 79:    //goto
			case 98:    //jump
			{
				csaArguments.Add( "Cleanup" );
			}
			break;

			case 82:    //header
			{
				csaArguments.Add( "INFOConnect Report" );
			}
			break;

			case 83:    //hex
			{
				csaArguments.Add( "32" );
			}
			break;

			case 86:    //hidequickpad
			{
				csaArguments.Add( "QP22.eqp" );
			}
			break;

			case 87:    //hms
			{
				csaArguments.Add( "300011" );
				csaArguments.Add( "3" );
			}
			break;

			case 89:    //if/then/else
			{
				csaArguments.Add( "X=23" );
				csaArguments.Add( "goto Cleanup" );
				csaArguments.Add( "TRUE" );
				csaArguments.Add( "goto Next" );
			}
			break;

			case 90:    //include
			{
				csaArguments.Add( "intl850.xws" );
			}
			break;

			case 91:    //inject
			{
				csaArguments.Add( "booper" );
				csaArguments.Add( "kkee" );
				csaArguments.Add( "4" );
			}
			break;

			case 93:    //input
			{
				csaArguments.Add( "user21" );
			}
			break;

			case 94:    //inscript
			{
				csaArguments.Add( "func StdDev" );
			}
			break;

			case 95:    //insert
			{
				csaArguments.Add( "acmgr32.exe" );
				csaArguments.Add( "c" );
				csaArguments.Add( "3" );
			}
			break;

			case 96:    //instr
			{
				csaArguments.Add( "banana" );
				csaArguments.Add( "na" );
				csaArguments.Add( "4" );
			}
			break;

			case 97:    //intval
			{
				csaArguments.Add( "137" );
			}
			break;

			case 99:    //keys
			{
				csaArguments.Add( "TRUE" );
				csaArguments.Add( "e:\\usa437.ekm" );
			}
			break;

			case 100:    //label
			{
				csaArguments.Add( "Cleanup" );
			}
			break;

			case 101:    //left
			{
				csaArguments.Add( "Cleanup" );
				csaArguments.Add( "5" );
			}
			break;

			case 102:    //length
			{
				csaArguments.Add( "rhododendren" );
			}
			break;

			case 103:    //loadquickpad
			case 167:    //showquickpad
			{
				csaArguments.Add( "qp112.eqp" );
			}
			break;

			case 104:    //loc
			{
				csaArguments.Add( "3" );
			}
			break;

			case 105:    //lowcase
			{
				csaArguments.Add( "3" );
			}
			break;

			case 106:    //lprint
			{
				csaArguments.Add( "This is being sent to the printer" );
			}
			break;

			case 108:    //max
			{
				csaArguments.Add( "12" );
				csaArguments.Add( "3" );
			}
			break;

			case 110:    //mid
			{
				csaArguments.Add( "bookkeeper" );
				csaArguments.Add( "2" );
				csaArguments.Add( "4" );
			}
			break;

			case 111:    //min
			case 116:    //move
			{
				csaArguments.Add( "12" );
				csaArguments.Add( "3" );
			}
			break;

			case 113:    //mkdir
			{
				csaArguments.Add( "C:\\INFOCN32\\ACCMGR32\\FILE" );
			}
			break;

			case 114:    //mkint
			case 115:    //mkstr
			{
				csaArguments.Add( "123" );
			}
			break;

			case 118:    //netid
			{
				csaArguments.Add( "TRUE" );
				csaArguments.Add( "UMC2200" );
			}
			break;

			case 119:    //new
			{
				csaArguments.Add( "C:\\INFOCN32\\ACCMGR32\\TCPA_1.ADP" );
			}
			break;

			case 121:    //nextline statement
			case 122:    //nextline function
			{
				csaArguments.Add( "5.5" );
				csaArguments.Add( "100" );
			}
			break;

			case 123:    //null
			{
				csaArguments.Add( "Fido" );
			}
			break;

			case 124:    //octal
			{
				csaArguments.Add( "33" );
			}
			break;

			case 129:    //open
			{
				csaArguments.Add( "append" );
				csaArguments.Add( "trace.out" );
				csaArguments.Add( "4" );
			}
			break;

			case 130:    //pack
			{
				csaArguments.Add( "Hello" );
				csaArguments.Add( "l" );
				csaArguments.Add( "1" );
			}
			break;

			case 131:    //pad
			{
				csaArguments.Add( "Username" );
				csaArguments.Add( "16" );
				csaArguments.Add( "*" );
				csaArguments.Add( "9" );
			}
			break;

			case 132:    //passchar
			{
				csaArguments.Add( "*" );
			}
			break;

			case 133:    //password
			{
				csaArguments.Add( "FALSE" );
				csaArguments.Add( "" );
			}
			break;

			case 134:    //perform
			{
				csaArguments.Add( "LDTProcess" );
				csaArguments.Add( "am10,am11" );
			}
			break;

			case 136:    //press
			{
				csaArguments.Add( "xy6gc" );
				csaArguments.Add( "<F8>" );
			}
			break;

			case 137:    //print
			{
				csaArguments.Add( "This is a sign" );
			}
			break;

			case 138:    //printer
			{
				csaArguments.Add( "Stop" );
			}
			break;

			case 139:    //proc/endproc
			{
				csaArguments.Add( "DoRun1" );
				csaArguments.Add( "a" );
				csaArguments.Add( "integer" );
			}
			break;

			case 140:    //protocol
			{
				csaArguments.Add( "TRUE" );
				csaArguments.Add( "CANDE" );
			}
			break;

			case 141:    //put
			{
				csaArguments.Add( "1" );
				csaArguments.Add( "Hello buddy" );
			}
			break;

			case 143:    //quote
			{
				csaArguments.Add( "Hello" );
			}
			break;

			case 144:    //read
			{
				csaArguments.Add( "1" );
				csaArguments.Add( "alpha,beta,gamma" );
			}
			break;

			case 145:    //read line
			{
				csaArguments.Add( "1" );
				csaArguments.Add( "csInline" );
			}
			break;

			case 146:    //receive
			case 150:    //request
			{
				csaArguments.Add( "report123.txt" );
			}
			break;

			case 147:    //rename
			{
				csaArguments.Add( "TRUE" );
				csaArguments.Add( "*.txt" );
				csaArguments.Add( "*.txt" );
			}
			break;

			case 148:    //repeat/until
			{
				csaArguments.Add( "readline 2, csValue" );
				csaArguments.Add( "i>79" );
			}
			break;

			case 149:    //reply
			{
				csaArguments.Add( "slskdhhh" );
			}
			break;

			case 152:    //return
			{
				csaArguments.Add( "FALSE" );
				csaArguments.Add( "" );
			}
			break;

			case 153:    //right
			{
				csaArguments.Add( "CSTotals" );
				csaArguments.Add( "4" );
			}
			break;

			case 154:    //rmdir
			{
				csaArguments.Add( "c:\\Backup" );
			}
			break;

			case 155:    //run
			{
				csaArguments.Add( "notepad.exe" );
			}
			break;

			case 156:    //save
			{
				csaArguments.Add( "source.adp" );
			}
			break;

			case 157:    //script
			{
				csaArguments.Add( "logon.xwc" );
			}
			break;

			case 158:    //scriptdesc
			{
				csaArguments.Add( "Logon Routine" );
			}
			break;

			case 159:    //secno
			{
				csaArguments.Add( "14:22:01" );
			}
			break;

			case 160:    //seek
			{
				csaArguments.Add( "1" );
				csaArguments.Add( "1840" );
			}
			break;

			case 161:    //send
			{
				csaArguments.Add( "g:\\endtest.txt" );
			}
			break;

			case 164:    //sessname
			{
				csaArguments.Add( "3" );
			}
			break;

			case 165:    //sessno
			{
				csaArguments.Add( "sales.adp" );
			}
			break;

			case 168:    //size
			{
				csaArguments.Add( "800" );
				csaArguments.Add( "640" );
			}
			break;

			case 169:    //slice
			{
				csaArguments.Add( "a,b,c,d,e,f" );
				csaArguments.Add( "3" );
				csaArguments.Add( "," );
				csaArguments.Add( "3" );
			}
			break;

			case 170:    //startup
			{
				csaArguments.Add( "FALSE" );
				csaArguments.Add( "" );
			}
			break;

			case 171:    //str
			{
				csaArguments.Add( "640" );
			}
			break;

			case 172:    //strip
			{
				csaArguments.Add( "BR549STS" );
				csaArguments.Add( "ST" );
				csaArguments.Add( "Stop at non-wild from right" );
			}
			break;

			case 174:    //subst
			{
				csaArguments.Add( "sand" );
				csaArguments.Add( "s" );
				csaArguments.Add( "h" );
			}
			break;

			case 177:    //terminal
			{
				csaArguments.Add( "TRUE" );
				csaArguments.Add( "AMUTS" );
			}
			break;

			case 179:    //time
			case 190:    //val
			{
				csaArguments.Add( "32431" );
			}
			break;

			case 181:    //trace
			{
				csaArguments.Add( "Show line numbers" );
			}
			break;
				
			case 182:    //track statement
			{
				csaArguments.Add( "2" );
				csaArguments.Add( "space \"logoff or enter\"" );
			}
			break;

			case 183:    //track function
			{
				csaArguments.Add( "" );
			}
			break;

			case 184:    //trap
			{
				csaArguments.Add( "Errors interrupt macros" );
			}
			break;

			case 187:    //unloadquickpad
			{
				csaArguments.Add( "coolpad.eqp" );
			}
			break;

			case 188:    //upcase
			{
				csaArguments.Add( "ascii" );
			}
			break;

			case 189:    //userid
			{
				csaArguments.Add( "TRUE" );
				csaArguments.Add( "schmoejoseph" );
			}
			break;

			case 192:    //wait
			{
				csaArguments.Add( "" );
				csaArguments.Add( "Wait for char count" );
				csaArguments.Add( "count 80" );
			}
			break;
				
			case 193:    //watch/endwatch
			{
				csaArguments.Add( "14 seconds" );
				csaArguments.Add( "Wait for a string" );
				csaArguments.Add( "username:" );
				csaArguments.Add( "perform loginProc" );
			}
			break;

			case 194:    //weekday
			{
				csaArguments.Add( "12" );
			}
			break;

			case 195:    //while/wend
			{
				csaArguments.Add( "x<winsizex" );
				csaArguments.Add( "upcase" );
			}
			break;

			case 196:    //winchar
			{
				csaArguments.Add( "14" );
				csaArguments.Add( "7" );
			}
			break;

			case 199:    //winstring
			{
				csaArguments.Add( "14" );
				csaArguments.Add( "7" );
				csaArguments.Add( "8" );
			}
			break;

			case 201:    //write
			{
				csaArguments.Add( "1" );
				csaArguments.Add( "csTotal" );
				csaArguments.Add( ";" );
			}
			break;

			case 202:    //write line
			{
				csaArguments.Add( "2" );
				csaArguments.Add( "csSummary" );
				csaArguments.Add( "" );
			}
			break;

		}
	}

}

