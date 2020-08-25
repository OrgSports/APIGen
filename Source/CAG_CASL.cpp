// Static Model
#include "stdafx.h"
#include "apigen.h"

#include "CAG_CASL.h"
#include "time.h"


CAG_CASL::CAG_CASL()
{
	APIFlavor=CASL_API;

	b_csName=FALSE;
	b_csButton1=FALSE;
	b_csButton2=FALSE;
	b_csButton3=FALSE;
	b_csButton4=FALSE;
	b_csString=FALSE;
}

CAG_CASL::~CAG_CASL()
{
	
}

void CAG_CASL::loadFunctionList(CListBox* listTranslateFunction)
{
	csaFunctions.RemoveAll();

	csaFunctions.Add("abs");
	csaFunctions.Add("activate");
	csaFunctions.Add("activatesession");
	csaFunctions.Add("alarm");
	csaFunctions.Add("alert");
	csaFunctions.Add("arg");
	csaFunctions.Add("asc");
	csaFunctions.Add("assume");
	csaFunctions.Add("backups");
	csaFunctions.Add("binary");
	csaFunctions.Add("bitstrip");
	csaFunctions.Add("busycursor");
	csaFunctions.Add("bye");
	csaFunctions.Add("capture");
	csaFunctions.Add("case/endcase");
	csaFunctions.Add("chain");
	csaFunctions.Add("chdir");
	csaFunctions.Add("choice");
	csaFunctions.Add("chr");
	csaFunctions.Add("cksum");
	csaFunctions.Add("class");
	csaFunctions.Add("clear");
	csaFunctions.Add("close");
	csaFunctions.Add("cls");
	csaFunctions.Add("comment");
	csaFunctions.Add("compile");
	csaFunctions.Add("connected");
	csaFunctions.Add("copy");
	csaFunctions.Add("count");
	csaFunctions.Add("crc");
	csaFunctions.Add("curday");
	csaFunctions.Add("curdir");
	csaFunctions.Add("curdrive");
	csaFunctions.Add("curhour");
	csaFunctions.Add("curminute");
	csaFunctions.Add("curmonth");
	csaFunctions.Add("cursecond");
	csaFunctions.Add("curyear");
	csaFunctions.Add("date");
	csaFunctions.Add("definput");
	csaFunctions.Add("defoutput");
	csaFunctions.Add("dehex");
	csaFunctions.Add("delete");
	csaFunctions.Add("delete 2");
	csaFunctions.Add("description");
	csaFunctions.Add("destore");
	csaFunctions.Add("detext");
	csaFunctions.Add("device");
	csaFunctions.Add("dialogbox");
	csaFunctions.Add("display");
	csaFunctions.Add("do");
	csaFunctions.Add("drive");
	csaFunctions.Add("end");
	csaFunctions.Add("enhex");
	csaFunctions.Add("enstore");
	csaFunctions.Add("entext");
	csaFunctions.Add("environ");
	csaFunctions.Add("eof");
	csaFunctions.Add("eol");
	csaFunctions.Add("errclass");
	csaFunctions.Add("errno");
	csaFunctions.Add("error");
	csaFunctions.Add("exists");
	csaFunctions.Add("exit");
	csaFunctions.Add("false");
	csaFunctions.Add("filefind");
	csaFunctions.Add("filesize");
	csaFunctions.Add("fncheck");
	csaFunctions.Add("fnstrip");
	csaFunctions.Add("footer");
	csaFunctions.Add("for/next");
	csaFunctions.Add("freemem");
	csaFunctions.Add("freetrack");
	csaFunctions.Add("func/endfunc");
	csaFunctions.Add("genlabels");
	csaFunctions.Add("genlines");
	csaFunctions.Add("get");
	csaFunctions.Add("go");
	csaFunctions.Add("gosub/return");
	csaFunctions.Add("goto");
	csaFunctions.Add("grab");
	csaFunctions.Add("halt");
	csaFunctions.Add("header");
	csaFunctions.Add("hex");
	csaFunctions.Add("hide");
	csaFunctions.Add("hideallquickpads");
	csaFunctions.Add("hidequickpad");
	csaFunctions.Add("hms");
	csaFunctions.Add("homedir");
	csaFunctions.Add("if/then/else");
	csaFunctions.Add("include");
	csaFunctions.Add("inject");
	csaFunctions.Add("inkey");
	csaFunctions.Add("input");
	csaFunctions.Add("inscript");
	csaFunctions.Add("insert");
	csaFunctions.Add("instr");
	csaFunctions.Add("intval");
	csaFunctions.Add("jump");
	csaFunctions.Add("keys");
	csaFunctions.Add("label");
	csaFunctions.Add("left");
	csaFunctions.Add("length");
	csaFunctions.Add("loadquickpad");
	csaFunctions.Add("loc");
	csaFunctions.Add("lowcase");
	csaFunctions.Add("lprint");
	csaFunctions.Add("match");
	csaFunctions.Add("max");
	csaFunctions.Add("maximize");
	csaFunctions.Add("mid");
	csaFunctions.Add("min");
	csaFunctions.Add("minimize");
	csaFunctions.Add("mkdir");
	csaFunctions.Add("mkint");
	csaFunctions.Add("mkstr");
	csaFunctions.Add("move");
	csaFunctions.Add("name");
	csaFunctions.Add("netid");
	csaFunctions.Add("new");
	csaFunctions.Add("nextchar");
	csaFunctions.Add("nextline");
	csaFunctions.Add("nextline 2");
	csaFunctions.Add("null");
	csaFunctions.Add("octal");
	csaFunctions.Add("off");
	csaFunctions.Add("on");
	csaFunctions.Add("online");
	csaFunctions.Add("ontime");
	csaFunctions.Add("open");
	csaFunctions.Add("pack");
	csaFunctions.Add("pad");
	csaFunctions.Add("passchar");
	csaFunctions.Add("password");
	csaFunctions.Add("perform");
	csaFunctions.Add("pop");
	csaFunctions.Add("press");
	csaFunctions.Add("print");
	csaFunctions.Add("printer");
	csaFunctions.Add("proc/endproc");
	csaFunctions.Add("protocol");
	csaFunctions.Add("put");
	csaFunctions.Add("quit");
	csaFunctions.Add("quote");
	csaFunctions.Add("read");
	csaFunctions.Add("read line");
	csaFunctions.Add("receive");
	csaFunctions.Add("rename");
	csaFunctions.Add("repeat/until");
	csaFunctions.Add("reply");
	csaFunctions.Add("request");
	csaFunctions.Add("restore");
	csaFunctions.Add("return");
	csaFunctions.Add("right");
	csaFunctions.Add("rmdir");
	csaFunctions.Add("run");
	csaFunctions.Add("save");
	csaFunctions.Add("script");
	csaFunctions.Add("scriptdesc");
	csaFunctions.Add("secno");
	csaFunctions.Add("seek");
	csaFunctions.Add("send");
	csaFunctions.Add("sendbreak");
	csaFunctions.Add("session");
	csaFunctions.Add("sessname");
	csaFunctions.Add("sessno");
	csaFunctions.Add("show");
	csaFunctions.Add("showquickpad");
	csaFunctions.Add("size");
	csaFunctions.Add("slice");
	csaFunctions.Add("startup");
	csaFunctions.Add("str");
	csaFunctions.Add("strip");
	csaFunctions.Add("stroke");
	csaFunctions.Add("subst");
	csaFunctions.Add("systime");
	csaFunctions.Add("tabwidth");
	csaFunctions.Add("terminal");
	csaFunctions.Add("terminate");
	csaFunctions.Add("time");
	csaFunctions.Add("timeout");
	csaFunctions.Add("trace");
	csaFunctions.Add("track statement");
	csaFunctions.Add("track function");
	csaFunctions.Add("trap");
	csaFunctions.Add("true");
	csaFunctions.Add("unloadallquickpads");
	csaFunctions.Add("unloadquickpad");
	csaFunctions.Add("upcase");
	csaFunctions.Add("userid");
	csaFunctions.Add("val");
	csaFunctions.Add("version");
	csaFunctions.Add("wait");
	csaFunctions.Add("watch/endwatch");
	csaFunctions.Add("weekday");
	csaFunctions.Add("while/wend");
	csaFunctions.Add("winchar");
	csaFunctions.Add("winsizex");
	csaFunctions.Add("winsizey");
	csaFunctions.Add("winstring");
	csaFunctions.Add("winversion");
	csaFunctions.Add("write");
	csaFunctions.Add("write line");
	csaFunctions.Add("xpos");
	csaFunctions.Add("ypos");
	csaFunctions.Add("zoom");
	
	listTranslateFunction->ResetContent();	
	
	for (int k=0; k<csaFunctions.GetSize(); k++)
	{
		listTranslateFunction->AddString( csaFunctions.GetAt(k) );
	}

	listTranslateFunction->SetCurSel(0);
	
}


void CAG_CASL::loadLanguageList(CListBox* listTranslateLanguage)
{
	int nPos = 0;

	listTranslateLanguage->ResetContent();
	listTranslateLanguage->InsertString( nPos++, "CASL Macro" );
	
	listTranslateLanguage->SetCurSel(0);
	
}

void CAG_CASL::loadTerminalTypeList(CListBox* listTerminalTypes)
{
	int nPos = 0;

	listTerminalTypes->ResetContent();
/*
	listTerminalTypes->InsertString( nPos++, "3270" );
	listTerminalTypes->InsertString( nPos++, "5250" );
	listTerminalTypes->InsertString( nPos++, "VT" );
	
	listTerminalTypes->SetCurSel(0);
*/
}


void CAG_CASL::generateHeader(CStringArray* pcsaHeader,
								  CStringArray* pcsaBody)
{

	CString csViewOutStuff;

	csViewOutStuff.Format( "--  ****************************************************************************");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "--                    Attachmate APIGen");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "--               Extra!-INFOConnect CASL Macro");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "-- ");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "--  This program features the use of an Extra!-INFOConnect CASL Macro.");
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



void CAG_CASL::appendBody(int nFunctionNum,
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

	csViewOutStuff.Format( "   -- *** %s", csFunctionName );
	pcsaBody->Add(csViewOutStuff);

	switch ( nFunctionNum )
	{
		case 0:    //abs
		{
			if ( !b_nNumber )
			{
				declareVariable( AG_NUMBER, pcsaHeader, &b_nNumber );
			}

			csViewOutStuff.Format( "   nNumber = abs( %s )", pcsaArguments->GetAt(1) );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "" );
			pcsaBody->Add(csViewOutStuff);

		}
		break;

		case 1:    //activate
		{
			csViewOutStuff.Format( "   activate" );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "" );
			pcsaBody->Add(csViewOutStuff);

		}
		break;

		case 2:    //activatesession
		{
			csViewOutStuff.Format( "   activatesession %s", pcsaArguments->GetAt(1) );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "" );
			pcsaBody->Add(csViewOutStuff);

		}
		break;

		case 3:    //alarm
		{
			CString csAlarm;
			if ( -1 != pcsaArguments->GetAt(1).Find("beep") )
			{
				csAlarm="0";
			}
			else if ( -1 != pcsaArguments->GetAt(1).Find("asterisk") )
			{
				csAlarm="1";
			}
			else if ( -1 != pcsaArguments->GetAt(1).Find("exclamation") )
			{
				csAlarm="2";
			}
			else if ( -1 != pcsaArguments->GetAt(1).Find("hand") )
			{
				csAlarm="3";
			}
			else if ( -1 != pcsaArguments->GetAt(1).Find("question") )
			{
				csAlarm="4";
			}
			else
			{
				csAlarm="5";
			}


			csViewOutStuff.Format( "   alarm %s", csAlarm );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "" );
			pcsaBody->Add(csViewOutStuff);
		}
		break;


		case 4:    //alert
		{
			CString csButt1, csButt2, csButt3, csButt4;

			if ( -1 != pcsaArguments->GetAt(2).Find("ok") )
			{
				csButt1 = "ok";
			}
			else if ( -1 != pcsaArguments->GetAt(2).Find("cancel") )
			{
				csButt1 = "cancel";
			}
			else
			{
				csButt1.Format( "\"%s\"", pcsaArguments->GetAt(2) );
			}

			if ( -1 != pcsaArguments->GetAt(3).Find("ok") )
			{
				csButt2 = " ok";
			}
			else if ( -1 != pcsaArguments->GetAt(3).Find("cancel") )
			{
				csButt2 = " cancel";
			}
			else
			{
				csButt2.Format( "\"%s\"", pcsaArguments->GetAt(3) );
			}

			if ( -1 != pcsaArguments->GetAt(4).Find("ok") )
			{
				csButt3 = "ok";
			}
			else if ( -1 != pcsaArguments->GetAt(4).Find("cancel") )
			{
				csButt3 = "cancel";
			}
			else
			{
				csButt3.Format( "\"%s\"", pcsaArguments->GetAt(4) );
			}

			if ( -1 != pcsaArguments->GetAt(5).Find("ok") )
			{
				csButt4 = "ok";
			}
			else if ( -1 != pcsaArguments->GetAt(5).Find("cancel") )
			{
				csButt4 = "cancel";
			}
			else
			{
				csButt4.Format( "\"%s\"", pcsaArguments->GetAt(5) );
			}

			
			csViewOutStuff.Format( "alert \"%s\" %s,%s,%s,%s, \"%s\"", pcsaArguments->GetAt(1), csButt1, csButt2, csButt3, csButt4, pcsaArguments->GetAt(6) );
			pcsaBody->Add(csViewOutStuff);
			pcsaBody->Add("");
				
		}
		break;

		case 5:    //arg
		{
			if ( !b_csString )
			{
				declareVariable( AG_STRING, pcsaHeader, &b_csString );
			}

			if ( pcsaArguments->GetAt(1).IsEmpty() )
			{
				csViewOutStuff.Format( "   csString = arg" );
			}
			else
			{
				csViewOutStuff.Format( "   csString = arg( %s )", pcsaArguments->GetAt(1) );
			}
			pcsaBody->Add(csViewOutStuff);

			pcsaBody->Add( "" );

		}
		break;


		case 24:	//comment
		{
			csViewOutStuff.Format( "-- %s", pcsaArguments->GetAt(1) );
			pcsaBody->Add(csViewOutStuff);
		}
		break;

		case 7:    //assume
		{
			if ( -1 != pcsaArguments->GetAt(1).Find( "preference" ) )
			{
				if ( -1 != pcsaArguments->GetAt(2).Find( "preference" ) )
				{
					if ( -1 != pcsaArguments->GetAt(3).Find( "preference" ) )
					{
						csViewOutStuff.Format( "-- no assume arguments provided" );
					}
					else
					{
						csViewOutStuff.Format( "   assume protocol \"%s\"", pcsaArguments->GetAt(3) );
					}
				}
				else
				{
					if ( -1 != pcsaArguments->GetAt(3).Find( "preference" ) )
					{
						csViewOutStuff.Format( "   assume terminal \"%s\"", pcsaArguments->GetAt(2) );
					}
					else
					{
						csViewOutStuff.Format( "   assume terminal \"%s\", protocol \"%s\"", pcsaArguments->GetAt(2), pcsaArguments->GetAt(3) );
					}
				}
			}
			else
			{
				if ( -1 != pcsaArguments->GetAt(2).Find( "preference" ) )
				{
					if ( -1 != pcsaArguments->GetAt(3).Find( "preference" ) )
					{
						csViewOutStuff.Format( "   assume device \"ICSTOOL\"" );
					}
					else
					{
						csViewOutStuff.Format( "   assume device \"ICSTOOL\", protocol \"%s\"", pcsaArguments->GetAt(3) );
					}
				}
				else
				{
					if ( -1 != pcsaArguments->GetAt(3).Find( "preference" ) )
					{
						csViewOutStuff.Format( "   assume device \"ICSTOOL\", terminal \"%s\"", pcsaArguments->GetAt(2) );
					}
					else
					{
						csViewOutStuff.Format( "   assume device \"ICSTOOL\", terminal \"%s\", protocol \"%s\"", pcsaArguments->GetAt(2), pcsaArguments->GetAt(3) );
					}
				}
			}

			pcsaBody->Add(csViewOutStuff);
			pcsaBody->Add("");

		}
		break;

		case 6:    //asc
		case 8:    //backups
		case 9:    //binary
		case 10:    //bitstrip
		case 11:    //busycursor
		case 12:    //bye
		case 13:    //capture
		case 14:    //case/endcase
		case 15:    //chain
		case 16:    //chdir
		case 17:    //choice
		case 18:    //chr
		case 19:    //cksum
		case 20:    //class
		case 21:    //clear
		case 22:    //close
		case 23:    //cls
		case 25:    //compile
		case 27:    //copy
		case 28:    //count
		case 29:    //crc
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

		case 42:    //delete
		case 43:    //delete 2
		case 44:    //description
		case 45:    //destore
		case 46:    //detext
		case 47:    //device
		case 48:    //dialogbox
		case 49:    //display
		case 50:    //do
		case 51:    //drive
		case 52:    //end
		case 53:    //enhex
		case 54:    //enstore
		case 55:    //entext
		case 56:    //environ
		case 57:    //eof
		case 58:    //eol
		case 59:    //errclass
		case 60:    //errno
		case 61:    //error
		case 62:    //exists
		case 63:    //exit
		case 64:    //false
		case 65:    //filefind
		case 66:    //filesize
		case 67:    //fncheck
		case 68:    //fnstrip
		case 69:    //footer
		case 70:    //for/next
		case 71:    //freemem
		case 72:    //freetrack
		case 73:    //func/endfunc
		case 74:    //genlabels
		case 75:    //genlines
		case 76:    //get
		case 77:    //go
		case 78:    //gosub/return
		case 79:    //goto
		case 80:    //grab
		case 81:    //halt
		case 82:    //header
		case 83:    //hex
		case 84:    //hide
		case 87:    //hms
		case 88:    //homedir
		case 89:    //if/then/else
		case 90:    //include
		case 91:    //inject
		case 92:    //inkey
		case 93:    //input
		case 94:    //inscript
		case 95:    //insert
		case 96:    //instr
		case 97:    //intval
		case 98:    //jump
		case 99:    //keys
		case 100:    //label
		case 101:    //left
		case 102:    //length
		case 103:    //loadquickpad
		case 104:    //loc
		case 105:    //lowcase
		case 106:    //lprint
		case 107:    //match
		case 108:    //max
		case 109:    //maximize
		case 110:    //mid
		case 111:    //min
		case 112:    //minimize
		case 113:    //mkdir
		case 114:    //mkint
		case 115:    //mkstr
		case 116:    //move
		case 117:    //name
		case 118:    //netid
		case 119:    //new
		case 120:    //nextchar
		case 121:    //nextline
		case 122:    //nextline 2
		case 123:    //null
		case 124:    //octal
		case 125:    //off
		case 126:    //on

		case 127:    //online			THESE TWO ARE IDENTICAL
		case 26:    //connected

		case 128:    //ontime
		case 129:    //open
		case 130:    //pack
		case 131:    //pad
		case 132:    //passchar
		case 133:    //password
		case 134:    //perform
		case 135:    //pop
		case 136:    //press
		case 137:    //print
		case 138:    //printer
		case 139:    //proc/endproc
		case 140:    //protocol
		case 141:    //put
		case 142:    //quit
		case 143:    //quote
		case 144:    //read
		case 145:    //read line
		case 146:    //receive
		case 147:    //rename
		case 148:    //repeat/until
		case 149:    //reply
		case 150:    //request
		case 151:    //restore
		case 152:    //return
		case 153:    //right
		case 154:    //rmdir
		case 155:    //run
		case 156:    //save
		case 157:    //script
		case 158:    //scriptdesc
		case 159:    //secno
		case 160:    //seek
		case 161:    //send
		case 162:    //sendbreak
		case 163:    //session
		case 164:    //sessname
		case 165:    //sessno
		case 166:    //show
		case 167:    //showquickpad
		case 168:    //size
		case 169:    //slice
		case 170:    //startup
		case 171:    //str
		case 172:    //strip
		case 173:    //stroke
		case 174:    //subst
		case 175:    //systime
		case 176:    //tabwidth
		case 177:    //terminal
		case 178:    //terminate
		case 179:    //time
		case 180:    //timeout
		case 181:    //trace
		case 182:    //track
		case 183:    //track 2
		case 184:    //trap
		case 185:    //true


		case 186:    //unloadallquickpads	// EQUIVALENT
		case 85:    //hideallquickpads


		case 187:    //unloadquickpad		// EQUIVALENT
		case 86:    //hidequickpad


		case 188:    //upcase
		case 189:    //userid
		case 190:    //val
		case 191:    //version
		case 192:    //wait
		case 193:    //watch/endwatch
		case 194:    //weekday
		case 195:    //while/wend
		case 196:    //winchar
		case 197:    //winsizex
		case 198:    //winsizey
		case 199:    //winstring
		case 200:    //winversion
		case 201:    //write
		case 202:    //write line
		case 203:    //xpos
		case 204:    //ypos
		case 205:    //zoom
		{
			csViewOutStuff.Format( "   // APIGen has not yet implemented this method." );
			pcsaBody->Add(csViewOutStuff);
		}
		break;


	}
	
	pcsaArguments->RemoveAll();
}



void CAG_CASL::finalize(CStringArray* pcsaBody)
{
	CString csViewOutStuff;

	csViewOutStuff.Format( " " );
	pcsaBody->Add(csViewOutStuff);

}


void CAG_CASL::declareVariable(AG_VARIABLE agVariable,
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

		case AG_NAME:
		{
			csLocal.Format( "   string csName");
		}
		break;

		case AG_BUTTON1:
		{
			csLocal.Format( "   string csButton1");
		}
		break;

		case AG_BUTTON2:
		{
			csLocal.Format( "   string csButton2");
		}
		break;

		case AG_BUTTON3:
		{
			csLocal.Format( "   string csButton3");
		}
		break;

		case AG_BUTTON4:
		{
			csLocal.Format( "   string csButton4");
		}
		break;

		case AG_STRING:
		{
			csLocal.Format( "   string csString");
		}
		break;



	}


	pcsaHeader->Add(csLocal);
	
}

void CAG_CASL::checkDebug(bool b_Debug,
							  CString csFunctionName,
							  CStringArray* pcsaBody)
{
	
}


