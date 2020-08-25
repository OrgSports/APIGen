//**************************************************************************
//
//*Name:    ACS3EHAP.H
//
//*Purpose: This C Header is designed to prototype the HLLAPI entry point
//	        of ACS3EHAP.DLL and EHLAPI32.DLL and provide definitions for HLLAPI
//          function numbers.
//
//  Copyright (c) 1990-1996 by Attachmate Corporation, Bellevue, WA
//  All rights reserved.
//
//**************************************************************************
#ifdef __cplusplus
    extern "C" void FAR PASCAL HLLAPI(LPINT,LPSTR,LPINT,LPINT);
#else
    void FAR PASCAL HLLAPI(LPINT,LPSTR,LPINT,LPINT);
#endif

//--------------------------------------------------------------------------
//   Definition of HLLAPI Function Numbers
//--------------------------------------------------------------------------
#define ATMQUERYSYS           0
#define CONNECTPS             1
#define DISCONNECTPS          2
#define SENDKEY               3
#define WAIT                  4
#define COPYPS                5
#define SEARCHPS              6
#define QUERYCURSOR           7
#define COPYPSTOSTRING        8
#define SETSESSION            9
#define QUERYSESSIONS         10
#define RESERVE               11
#define RELEASE               12
#define COPYOIA               13
#define QUERYFIELDATT         14
#define COPYSTRINGTOPS        15
#define PAUSE                 18
#define QUERYSYSTEM           20
#define RESETSYSTEM           21
#define QUERYSESSIONSTATUS    22
#define STARTHOSTNOTIFY       23
#define QUERYHOSTUPDATE       24
#define STOPHOSTNOTIFY        25
#define SEARCHFIELD           30
#define FINDFIELDPOS          31
#define FINDFIELDLENGTH       32
#define COPYSTRINGTOFIELD     33
#define COPYFIELDTOSTRING     34
#define SETCURSOR             40
#define STARTCLOSEINTERCEPT   41
#define QUERYCLOSEINTERCEPT   42
#define STOPCLOSEINTERCEPT    43
#define STARTKEYINTERCEPT     50
#define GETKEY                51
#define POSTINTERCEPTSTATUS   52
#define STOPINTERCEPT         53
#define SENDFILE              90
#define RECIEVEFILE           91
#define CONVERTPOSITION       99
#define CONNECTPMSERVICES    101
#define DISCONNECTPMSERVICES 102
#define QUERYWINDOWCOORDINATES 103
#define PMWINDOWSTATUS       104
#define CHANGESWITCHLISTNAME 105
#define CHANGEPSWINDOWNAME   106
