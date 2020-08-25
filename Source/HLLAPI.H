/*******************************************************************************
                Module Header
********************************************************************************

File:       hllapi.h
Purpose:    data structures, definitions & prototypes comprising HLLAPI

Notes:      
            13-Jun-1991:
            Added new hllapi functions HLL_CopyOIA5 and HLL_CopyOIA9.

            01-Apr-1991: 
            HLL_WSCTRLSTARTEMULATOR's EMULATORCONTROL structure byPower field
            has been renamed byReserved, reflecting the fact that the
            subfunction no longer affects the POWER condition of a new
            terminal emulator.

            30-Oct-1990:
            added HLL_PROTECTED as synonym for return code 5

            18-Oct-1990:
            added WSCTRL subfunctions: -BLOCKEMULATORUPDATES & 
            -ENABLEEMULATORUPDATES.

            05-Feb-1990:
            HLL_ReceiveFile and HLL_SendFile: additional parameter.
            
            11-Dec-1995:
            Changed HLL_EnumHLLWins to accept one instead of two arguments.
            
*******************************************************************************/

/***********************************************************
HLLAPI function selectors ~~ HLLAPI subfunction selectors
***********************************************************/

#define HLL_ATMQUERYSYSTEM              0
#define HLL_CONNECTPS                   1
#define HLL_DISCONNECTPS                2
#define HLL_SENDKEY                     3
#define HLL_WAIT                        4

#define HLL_COPYPS                      5
#define HLL_SEARCHPS                    6
#define HLL_QUERYCURSOR                 7
#define HLL_COPYPSTOSTRING              8
#define HLL_SETHLLWINPARAMETERS         9

#define HLL_QUERYSESSIONS               10
#define HLL_RESERVE                     11
#define HLL_RELEASE                     12
#define HLL_COPYOIA                     13
#define HLL_QUERYFIELDATTRIBUTE         14

#define HLL_COPYSTRINGTOPS              15
#define HLL_WSCTRL                      16
#define HLL_PAUSE                       18
#define HLL_QUERYSYSTEM                 20
#define HLL_RESETHLLWIN                 21

#define HLL_QUERYSESSIONSTATUS          22
#define HLL_STARTHOSTNOTIFICATION       23
#define HLL_QUERYHOSTUPDATE             24
#define HLL_STOPHOSTNOTIFICATION        25
#define HLL_SEARCHFIELD                 30

#define HLL_FINDFIELDPOSITION           31
#define HLL_FINDFIELDLENGTH             32
#define HLL_COPYSTRINGTOFIELD           33
#define HLL_COPYFIELDTOSTRING           34
#define HLL_SETCURSOR                   40

#define HLL_STARTKEYSTROKEINTERCEPT     50
#define HLL_GETKEY                      51
#define HLL_POSTINTERCEPTSTATUS         52
#define HLL_STOPKEYSTROKEINTERCEPT      53  

#define HLL_COPYOIA5					70   
#define HLL_COPYOIA9					71

#define HLL_SENDFILE                    90

#define HLL_RECEIVEFILE                 91
#define HLL_CONVERT                     99

/***********
sui generis
************/
#define HLL_HLLAPI                      500
#define HLL_ENUMHLLWINS                 501
#define HLL_QUERYHLLWINPARAMETERS       502
#define HLL_SETMESSAGELOOPCALLBACK      503


#ifndef RC_INVOKED

#pragma pack(1)       // Pack HLLAPI structures on 1-byte boundary
#pragma message("Information: HLLAPI structures are packed on 1-byte boundaries.")

/*************************
system manifest constants
*************************/
#define MAXSENDKEYLENGTH                255
#define MAXPAUSEDURATION                0xFFFF
#define MINKEYSTROKEBUFFERLENGTH        6
#define MAXFILETRANSFERSTRINGLENGTH     512     /*  07-Jun-1990 */

/*********************************
informal list of HLL return codes
**********************************/
#define HLL_SUCCESS                     0
#define HLL_INVALIDPSID                 1
#define HLL_INVALIDPARAMETER            2
#define HLL_SESSIONOCCUPIED             4
#define HLL_TIMEOUT                     4       /*  e.g. Wait (XCLOCK/XSYSTEM)*/
#define HLL_PSLOCKED                    5       /*  e.g. ConnectPS  */
#define HLL_PROTECTED                   5
#define HLL_FIELDSIZEMISMATCH           6       /*  e.g. CopyFieldToString  */
#define HLL_DATATRUNCATED               6       /*  e.g. CopyStringToField  */
#define HLL_INVALIDPSPOSITION           7
#define HLL_NOPRIORSTARTKEYSTROKE       8
#define HLL_NOPRIORSTARTHOSTNOTIFY      8
#define HLL_SYSTEMERROR                 9
#define HLL_RESOURCEUNAVAILABLE         11
#define HLL_SEARCHSTRINGNOTFOUND        24      /*  e.g. SearchField    */
#define HLL_UNFORMATTEDHOSTPS           24      /*  e.g. CopyFieldToString  */
#define HLL_NOSUCHFIELD                 24      /*  e.g. FindFieldPosition  */
#define HLL_NOHOSTSESSIONUPDATE         24      /*  new code for QueryHostUpdate    */
#define HLL_KEYSTROKESNOTAVAILABLE      25
#define HLL_HOSTSESSIONUPDATE           26      /*  end of Pause    */
#define HLL_KEYSTROKEQUEUEOVERFLOW      31

#define HLL_MEMORYUNAVAILABLE           101     /*  cf StartKSIntercept   */
#define HLL_DELAYENDEDBYCLIENT          102     /*  Wait, Pause, GetKey */
#define HLL_UNCONFIGUREDPSID            103     /*  Connect, Intercept    */
#define HLL_NOEMULATORATTACHED          104     /*  keystroke intercept, etc */
#define HLL_WSCTRLFAILURE               105

/********************************
values for Post Intercept Status
********************************/
#define HLL_INTERCEPTACCEPTED           0
#define HLL_INTERCEPTREJECTED           1

/*********************************
wOptionCode values for HLL_GetKey
**********************************/
#define HLL_GETKEYASCII                 0
#define HLL_GETKEYMNEMONIC              1
#define HLL_GETKEYSHIFTED               2

/*************************************
options for HLL_StartHostNotification
**************************************/
#define HLL_NOTIFYALLUPDATES            127
#define HLL_NOTIFYPSUPDATE              1
#define HLL_NOTIFYOIAUPDATE             2
#define HLL_NOTIFYCURSORUPDATE          4
#define HLL_NOTIFYBEEP                  8
#define HLL_NOTIFYBASECOLORCHANGE       16
#define HLL_NOTIFYMODELCHANGE           32
#define HLL_NOTIFYPOWERCHANGE           64

/*************************************************
field specifiers for HLL_FindFieldLength/Position
*************************************************/
#define HLL_THISFIELD                   0
#define HLL_NEXTFIELD                   1
#define HLL_PREVIOUSFIELD               2
#define HLL_NEXTPROTECTEDFIELD          3
#define HLL_NEXTUNPROTECTEDFIELD        4
#define HLL_PREVIOUSPROTECTEDFIELD      5
#define HLL_PREVIOUSUNPROTECTEDFIELD    6

/****************************************
session specifiers for HLL_QuerySessions
****************************************/
#define HLL_QUERYSESSIONSCONFIGURED     1   /*  in config file  */
#define HLL_QUERYSESSIONSOPENED         2   /*  opened, i.e. OpenSession () */
#define HLL_QUERYSESSIONSPOWERED        3   /*  terminal on */  /*  default */

/********************************
option specifiers for HLL_WSCtrl
********************************/
#define HLL_WSCTRLOPENCONFIGURATION     1
#define HLL_WSCTRLCLOSECONFIGURATION    2
#define HLL_WSCTRLQUERYCONFIGURATION    3
#define HLL_WSCTRLOPENLAYOUT            4
#define HLL_WSCTRLQUERYLAYOUT           5
#define HLL_WSCTRLEMULATORHANDLE        6
#define HLL_WSCTRLSTARTEMULATOR         7
#define HLL_WSCTRLSTOPEMULATOR          8
#define HLL_WSCTRLTERMINALON            9
#define HLL_WSCTRLTERMINALOFF           10
#define HLL_WSCTRLSETEXECUTEPATH        11
#define HLL_WSCTRLQUERYEXTRADIRECTORY   12
#define HLL_WSCTRLALLOWEMULATORUPDATES  13
#define HLL_WSCTRLBLOCKEMULATORUPDATES  14
#define HLL_WSCTRLSTARTMACRO     		40
#define HLL_WSCTRLSTARTMACROASYNC       41
#define HLL_WSCRTLFILETRANSFERDIALOG    42






typedef struct tagEmulatorControl {
    char    cPSID;              /*  minimum requirement */
    BYTE    byVisibility;       /*  N(ormal) I(conic) M(aximized) H(idden)  */
    BYTE    byReserved;         /*  until 01-Apr-1991, byPower  */
    BYTE    byCase;             /*  U(pper) M(ixed) */
    WORD    wLeft;              /*  absolute position, in screen coordinates    */
    WORD    wBottom;
    WORD    wRight;
    WORD    wTop;
    }       EMULATORCONTROL, FAR * LPEMULATORCONTROL, NEAR * NPEMULATORCONTROL;
    /*******************************************************************
    19-Jul-1989 this structure is subject to expansion: e.g. fonts, ...
    *******************************************************************/

/*********************************
option specifiers for HLL_Convert
*********************************/
#define HLL_CONVERTPOSITION             1
#define HLL_CONVERTROWCOLUMN            2

typedef struct tagHLLParams {
    BYTE    byAttribute;        /*  ATTRB or NOATTRB    */
    BYTE    byAutoReset;        /*  AUTORESET or NOAUTORESET    */
    BYTE    byConnectType;      /*  CONLOG or CONPHYS   */
    BYTE    byEAB;              /*  EAB or NOEAB    */
    char    cEscape;            /*  default '@' */
    BYTE    byPause;            /*  IPAUSE or FPAUSE    */
    BYTE    bySearchOrigin;     /*  SRCHALL or SRCHFROM */
    BYTE    bySearchDirection;  /*  SRCHFORWARD or SRCHBKWD */
    WORD    wTimeOut;           /*  0..64k          */
    BYTE    byTrace;            /*  TRON or TROFF   */
    BYTE    byWait;             /*  TWAIT, LWAIT, NWAIT */
    BYTE    byXlate;            /*  ASCII<->3270DC translation or not   */
    }       HLLPARAMS, NEAR * NPHLLPARAMS, FAR * LPHLLPARAMS;

/******************************
values for fields of HLLPARAMS
******************************/
/******************
byAttribute values
******************/
#define HLLWIN_ATTRB            1
#define HLLWIN_NOATTRB          2

/******************
byAutoReset values
******************/
#define HLLWIN_AUTORESET        1
#define HLLWIN_NOAUTORESET      2

/***********************
byConnectionType values
***********************/
#define HLLWIN_CONLOG           1
#define HLLWIN_CONPHYS          2

/************
byEAB values
************/
#define HLLWIN_EAB              1
#define HLLWIN_NOEAB            2

/*************
byPause values
*************/
#define HLLWIN_FPAUSE           1
#define HLLWIN_IPAUSE           2

/*********************
bySearchOrigin values
*********************/
#define HLLWIN_SRCHALL          1
#define HLLWIN_SRCHFROM         2

/************************
bySearchDirection values
************************/
#define HLLWIN_SRCHFRWD         1
#define HLLWIN_SRCHBKWD         2

/**************
byTrace values
**************/
#define HLLWIN_TRON             1
#define HLLWIN_TROFF            2

/************
byWait values
************/
#define HLLWIN_TWAIT            1
#define HLLWIN_LWAIT            2
#define HLLWIN_NWAIT            3

/**************
byXlate values
**************/
#define HLLWIN_XLATE            1
#define HLLWIN_NOXLATE          2


typedef struct tagATMSystem {
    WORD    wHLLAPIVersionNumber;
    WORD    wHLLAPILevelNumber;
    }       ATMSYSTEM, NEAR * NPATMSYSTEM, FAR * LPATMSYSTEM;

typedef struct tagStartIntercept {
    char    cPSID;
    WORD    wKeyFilter;
    WORD    wQueueLength;
    BOOL    bWindowsMessage;
    }       STARTINTERCEPT, NEAR * NPSTARTINTERCEPT, FAR * LPSTARTINTERCEPT;

/**********************************
values for wKeyFilter interception
**********************************/
#define HLL_INTERCEPTAIDKEYS    1
#define HLL_INTERCEPTALLKEYS    2

typedef struct tagKeystroke {
    char    cPSID;
    char    szKeystroke [MINKEYSTROKEBUFFERLENGTH];
    }       KEYSTROKE, NEAR * NPKEYSTROKE, FAR * LPKEYSTROKE;

typedef struct tagOIAGroup {
    char    szOIAGroup [22];
    }       OIAGROUP, NEAR * NPOIAGROUP, FAR * LPOIAGROUP;

typedef struct tagSessions {
    char    cPSID;
    char    szLongName [8];
    BYTE    byState;
            /******************************************
            bit 0:  configured?         bit 1:  opened?
            bit 2:  powered?
            *******************************************/
    WORD    wPSSize;
    }       SESSIONS, NEAR * NPSESSIONS, FAR * LPSESSIONS;

typedef struct tagSessionStatus {
    char    cPSID;  /*  session short name  */
    char    szLongName [8];
    WORD    bType;   /*  FALSE = CUT;    TRUE = DFT   */
    BYTE    byCharacteristics;
            /*****************************************************
            bit 0: EABs? Y/N        bit 1: Programmed Symbols Y/N
            *****************************************************/
    BYTE    byUsage;
            /****************************************************
            bit 0: Configured? Y/N  bit 1: Opened? Y/N
            bit 2: Powered? Y/N     bit 3: AutoPowered? Y/N
            bit 4: Emulated? Y/N    bit 5: HLLAPI-Connected? Y/N
            bit 6: FileTrans? Y/N
            ****************************************************/
            /******************************************************************
            note that bit 5, HLLAPI-Connected, may be either HLLWin connection,
            HLLWin keystroke interception, or HLLWin-initiated file transfer
            *******************************************************************/

    WORD    wRows;
    WORD    wColumns;
    }       SESSIONSTATUS, NEAR * NPSESSIONSTATUS, FAR * LPSESSIONSTATUS;

/****************************************************************
definitions for use in probing the bySessionCharacteristics byte
****************************************************************/
#define HLL_SESSIONEABS                 0x01
#define HLL_SESSIONPROGRAMMEDSYMBOLS    0x02

/**********************************************************************
definitions for use in probing the bySessionUsage byte in SessionStatus
**********************************************************************/
#define HLL_SESSIONCONFIGURED           0x01
#define HLL_SESSIONOPENED               0x02
#define HLL_SESSIONPOWERED              0x04
#define HLL_SESSIONAUTOPOWERED          0x08
#define HLL_SESSIONEMULATED             0x10
#define HLL_SESSIONCONNECTED            0x20    /****************************
                                                HLLWin connections, keystroke
                                                interception, or monitors
                                                *****************************/
#define HLL_SESSIONFILETRANSFER         0x40

typedef struct tagSystem {
    BYTE    byHLLAPIMonth;
    BYTE    byHLLAPIDay;
    WORD    wHLLAPIYear;
    char    cPSID;
    DWORD   dwSystemError;
    }       SYSTEM, NEAR * NPSYSTEM, FAR * LPSYSTEM;

/**************************************
exported routines, in alphabetic order
***************************************/


#ifdef __cplusplus
	extern "C"
	{
#endif

WORD WINAPI
HLL_AttachmateQuerySystem (
    HWND        hWnd,
    LPATMSYSTEM lpATMSystem);

WORD WINAPI
HLL_ConnectPS (
    HWND        hWnd,
    char        cPSID);

WORD WINAPI
HLL_Convert (
    HWND        hWnd,
    char        cPSID,
    WORD        wPositionOrRowColumn,
    LPPOINT     lpPoint);

WORD WINAPI
HLL_CopyFieldToString (
    HWND        hWnd,
    LPSTR       lpBuffer,
    WORD        wBufferLength,
    WORD        wPSP);

WORD WINAPI
HLL_CopyOIA (                       // Xclock info switchable between 5/9
    HWND        hWnd,
    LPSTR       lpOIA);             /*  103 chars of binary data    */

WORD WINAPI                                                         
HLL_CopyOIA9 (                      // Xclock info in position 9        
    HWND        hWnd,                                                   
    LPSTR       lpOIA);             /*  103 chars of binary data    */  
                                                                        
WORD WINAPI                                                         
HLL_CopyOIA5 (                      // Xclock info in position 5        
    HWND        hWnd,                                                   
    LPSTR       lpOIA);             /*  103 chars of binary data    */  

WORD WINAPI
HLL_CopyPS (
    HWND        hWnd,
    LPSTR       lpBuffer);

WORD WINAPI
HLL_CopyPSToString (
    HWND        hWnd,
    LPSTR       lpBuffer,
    WORD        wBufferLength,
    WORD        wPSP);

WORD WINAPI
HLL_CopyStringToField (
    HWND        hWnd,
    LPSTR       lpBuffer,
    WORD        wBufferLength,
    WORD        wPSP);

WORD WINAPI
HLL_CopyStringToPS (
    HWND        hWnd,
    LPSTR       lpBuffer,
    WORD        wBufferLength,
    WORD        wPSP);

WORD WINAPI
HLL_DisconnectPS (
    HWND        hWnd);

DWORD WINAPI
HLL_EnumHLLWins (
    HWND        hQueryWnd );

DWORD WINAPI
HLL_FindFieldLength (
    HWND        hWnd,
    WORD        wFieldSpecifier,
    WORD        wTargetFieldPSP);

DWORD WINAPI
HLL_FindFieldPosition (
    HWND        hWnd,
    WORD        wFieldSpecifier,
    WORD        wTargetFieldPSP);

WORD WINAPI
HLL_GetKey (
    HWND        hWnd,
    LPKEYSTROKE lpKeystroke);

WORD WINAPI
HLL_Pause (
    HWND        hWnd,
    WORD        wDuration);     /*  500-millisecond units   */

WORD WINAPI
HLL_PostInterceptStatus (
    HWND        hWnd,
    char        cPSID,
    WORD        wStatus);

WORD WINAPI
HLL_QueryHLLWinParameters (
    HWND        hWnd,
    LPHLLPARAMS lpHLLParams);

DWORD WINAPI
HLL_QueryCursor (
    HWND        hWnd);

DWORD WINAPI
HLL_QueryFieldAttribute (
    HWND        hWnd,
    WORD        wPSP);

DWORD WINAPI
HLL_QueryHostUpdate (
    HWND        hWnd,
    char        cPSID);

DWORD WINAPI
HLL_QuerySessions (
    HWND        hWnd,
    LPSESSIONS  lpSessions,
    WORD        wSessionState,
    WORD        wNumberOfSessions);

WORD WINAPI
HLL_QuerySessionStatus (
    HWND            hWnd,
    LPSESSIONSTATUS lpSessionStatus);

WORD WINAPI
HLL_QuerySystem (
    HWND        hWnd,
    LPSYSTEM    lpSystem);

DWORD WINAPI
HLL_ReceiveFile (
    HWND        hWnd,
    LPSTR       lpszReceiveCommand,
    LPWORD      lpwSequenceID);

WORD WINAPI
HLL_Release (
    HWND        hWnd);

WORD WINAPI
HLL_Reserve (
    HWND        hWnd);

WORD WINAPI
HLL_ResetHLLWin (
    HWND        hWnd);

DWORD WINAPI
HLL_SearchField (
    HWND        hWnd,
    LPSTR       lpsSearchString,
    WORD        wStringLength,      /*  if HLLWIN_NOXLATE   */
    WORD        wPSP);              /*  if HLLWIN_SRCHFROM  */

DWORD WINAPI
HLL_SearchPS (
    HWND        hWnd,
    LPSTR       lpsSearchString,
    WORD        wStringLength,      /*  if HLLWIN_NOXLATE   */
    WORD        wPSP);              /*  either HLLWIN_SRCHALL or SRCHFROM   */

DWORD WINAPI
HLL_SendFile (
    HWND        hWnd,
    LPSTR       lpszReceiveCommand,
    LPWORD      lpwSequenceID);

WORD WINAPI
HLL_SendKey (
    HWND        hWnd,
    LPSTR       lpszKeys);

WORD WINAPI
HLL_SetCursor (
    HWND        hWnd,
    WORD        wCursorLocation);

WORD WINAPI
HLL_SetMessageLoopCallback (
    HWND        hWnd,
    FARPROC     lpfnCallback);

WORD WINAPI
HLL_SetHLLWinParameters (
    HWND        hWnd,
    LPHLLPARAMS lpHLLParams);

WORD WINAPI
HLL_StartHostNotification (
    HWND        hWnd,
    char        cPSID,
    WORD        wNotificationType,
    BOOL        bWindowsMessage);

WORD WINAPI
HLL_StartKeystrokeIntercept (
    HWND                hWnd,
    LPSTARTINTERCEPT    lpIntercept);

WORD WINAPI
HLL_StopHostNotification (
    HWND        hWnd,
    char        cPSID);

WORD WINAPI
HLL_StopKeystrokeIntercept (
    HWND        hWnd,
    char        cPSID);

WORD WINAPI
HLL_Wait (
    HWND        hWnd);

WORD WINAPI
HLL_WSCtrl (
    HWND	hWnd,
    WORD        wOption,
    LPVOID      lpvState,
    WORD        wStateLength);

#ifdef __cplusplus
	}
#endif


#pragma pack()      // Revert to previous packing

#endif  /*  RC_INVOKED  */
