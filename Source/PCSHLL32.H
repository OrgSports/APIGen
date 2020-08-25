//This file contains the return codes and structures used by 16 and 32 EHLLAPI

#ifndef HLLAPI_H
#define HLLAPI_H

#include <windows.h>

                //winapi
/*extern "C" void FAR PASCAL HLLAPI( USHORT	*lpwFunction,
                                   LPSTR	lpbyString,
                                   USHORT	*lpwLength,
                                   USHORT	*lpwReturnCode );
*/
// pda #60858 donc21497
extern "C" void FAR PASCAL HLLAPI( int	*lpwFunction,
                                   LPSTR	lpbyString,
                                   int	*lpwLength,
                                   int	*lpwReturnCode );

                      
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
#define HLL_STORAGEMANAGER              17
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

#define HLL_STARTCLOSEINTERCEPT         41
#define HLL_QUERYCLOSEINTERCEPT         42
#define HLL_STOPCLOSEINTERCEPT          43


#define HLL_STARTKEYSTROKEINTERCEPT     50
#define HLL_GETKEY                      51
#define HLL_POSTINTERCEPTSTATUS         52
#define HLL_STOPKEYSTROKEINTERCEPT      53
#define HLL_SENDFILE                    90

#define HLL_RECEIVEFILE                 91
#define HLL_CONVERT                     99

#define HLL_CONNECTWINDOWSERVICE       101
#define HLL_DISCONNECTWINDOWSERVICE    102
#define HLL_QUERYQWINDOWCOORDINATES    103
#define HLL_WINDOWSTATUS               104
#define HLL_CHANGESWITCHLISTNAME       105
#define HLL_CHANGEPSWINDOWNAME         106


/*********************************
informal list of HLL return codes
**********************************/
#define HLL_SUCCESS                     0
#define HLL_INVALIDPSID                 1
#define HLL_INVALIDPARAMETER            2
#define HLL_FILETRANSFER_COMPLETE       3
#define HLL_SESSIONOCCUPIED             4
#define HLL_TIMEOUT                     4       /*  e.g. Wait (XCLOCK/XSYSTEM)*/
#define HLL_PSLOCKED                    5       /*  e.g. ConnectPS  */
#define HLL_PROTECTED                   5
#define HLL_FIELDSIZEMISMATCH           6       /*  e.g. CopyFieldToString  */
#define HLL_DATATRUNCATED               6       /*  e.g. CopyStringToField  */
#define HLL_WSCTRLINVALID               6
#define HLL_INVALIDPSPOSITION           7
#define HLL_NOPRIORSTARTKEYSTROKE       8
#define HLL_NOPRIORSTARTHOSTNOTIFY      8
#define HLL_NOPRIORRESERVE              8
#define HLL_NOPRIORRELEASE              8
#define HLL_SYSTEMERROR                 9
#define HLL_FUNCTIONNOTSUPPORTED        10
#define HLL_RESOURCEUNAVAILABLE         11
#define HLL_OIAUPDATE                   21
#define HLL_PSUPDATE                    22
#define HLL_BOTHOIAANDPSUPDATE          23
#define HLL_SEARCHSTRINGNOTFOUND        24      /*  e.g. SearchField    */
#define HLL_UNFORMATTEDHOSTPS           24      /*  e.g. CopyFieldToString  */
#define HLL_NOSUCHFIELD                 24      /*  e.g. FindFieldPosition  */
#define HLL_NOHOSTSESSIONUPDATE         24      /*  new code for QueryHostUpdate    */
#define HLL_KEYSTROKESNOTAVAILABLE      25
#define HLL_HOSTSESSIONUPDATE           26      /*  end of Pause    */
#define HLL_ZEROFIELDLENGTH             28		/*  field length of zero bytes */
#define HLL_KEYSTROKEQUEUEOVERFLOW      31

#define HLL_MEMORYUNAVAILABLE           101     /*  cf StartKSIntercept   */
#define HLL_DELAYENDEDBYCLIENT          102     /*  Wait, Pause, GetKey */
#define HLL_UNCONFIGUREDPSID            103     /*  Connect, Intercept    */
#define HLL_NOEMULATORATTACHED          104     /*  keystroke intercept, etc */
#define HLL_WSCTRLFAILURE               105

#define WHLL_WINDOWSTATUS_SET			0x01
#define WHLL_WINDOWSTATUS_QUERY			0x02
#define WHLL_WINDOWSTATUS_EXTQUERY		0x04

#endif
