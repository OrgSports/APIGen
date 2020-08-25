# Microsoft Developer Studio Project File - Name="APIGen" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=APIGen - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "APIGen.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "APIGen.mak" CFG="APIGen - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "APIGen - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "APIGen - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""$/Level 4 - Work In Progress/DonCa/APIGen", DLGAAAAA"
# PROP Scc_LocalPath "."
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "APIGen - Win32 Release"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /d "NDEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /machine:I386
# ADD LINK32 /nologo /subsystem:windows /machine:I386

!ELSEIF  "$(CFG)" == "APIGen - Win32 Debug"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /FR /Yu"stdafx.h" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /d "_DEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept

!ENDIF 

# Begin Target

# Name "APIGen - Win32 Release"
# Name "APIGen - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\AG.cpp
# End Source File
# Begin Source File

SOURCE=.\AG_CT.cpp
# End Source File
# Begin Source File

SOURCE=.\AG_EAL.cpp
# End Source File
# Begin Source File

SOURCE=.\AG_EAL_CPP.cpp
# End Source File
# Begin Source File

SOURCE=.\AG_EAOAx.cpp
# End Source File
# Begin Source File

SOURCE=.\AG_EAOJ.cpp
# End Source File
# Begin Source File

SOURCE=.\AG_EAOJ_CRLJ.cpp
# End Source File
# Begin Source File

SOURCE=.\AG_EAOJ_CRLV.cpp
# End Source File
# Begin Source File

SOURCE=.\AG_EAOJ_MCSJ.cpp
# End Source File
# Begin Source File

SOURCE=.\AG_EAOJ_MCSV.cpp
# End Source File
# Begin Source File

SOURCE=.\AG_EHL.cpp
# End Source File
# Begin Source File

SOURCE=.\AG_EHL_CPP.cpp
# End Source File
# Begin Source File

SOURCE=.\AG_EHL_CS.cpp
# End Source File
# Begin Source File

SOURCE=.\AG_EHL_VB.cpp
# End Source File
# Begin Source File

SOURCE=.\AG_EHL_VBN.cpp
# End Source File
# Begin Source File

SOURCE=.\AG_HLL.cpp
# End Source File
# Begin Source File

SOURCE=.\AG_HLL_CPP.cpp
# End Source File
# Begin Source File

SOURCE=.\AG_HLL_VB.cpp
# End Source File
# Begin Source File

SOURCE=.\AG_IHL.cpp
# End Source File
# Begin Source File

SOURCE=.\AG_IHL_CPP.cpp
# End Source File
# Begin Source File

SOURCE=.\AG_IHL_CS.cpp
# End Source File
# Begin Source File

SOURCE=.\AG_IHL_VB.cpp
# End Source File
# Begin Source File

SOURCE=.\AG_IHL_VBN.cpp
# End Source File
# Begin Source File

SOURCE=.\AG_ITask.cpp
# End Source File
# Begin Source File

SOURCE=.\AG_ITask_Java.cpp
# End Source File
# Begin Source File

SOURCE=.\AG_OLE.cpp
# End Source File
# Begin Source File

SOURCE=.\AG_OLE_ASP.cpp
# End Source File
# Begin Source File

SOURCE=.\AG_OLE_CPP.cpp
# End Source File
# Begin Source File

SOURCE=.\AG_OLE_EBM.cpp
# End Source File
# Begin Source File

SOURCE=.\AG_OLE_VB.cpp
# End Source File
# Begin Source File

SOURCE=.\AG_OLE_WS.cpp
# End Source File
# Begin Source File

SOURCE=.\AG_PCS.cpp
# End Source File
# Begin Source File

SOURCE=.\AG_PCS_CPP.cpp
# End Source File
# Begin Source File

SOURCE=.\AG_PCS_CS.cpp
# End Source File
# Begin Source File

SOURCE=.\AG_PCS_VB.cpp
# End Source File
# Begin Source File

SOURCE=.\AG_PCS_VBN.cpp
# End Source File
# Begin Source File

SOURCE=.\AG_QACom.cpp
# End Source File
# Begin Source File

SOURCE=.\AG_QACom_Java.cpp
# End Source File
# Begin Source File

SOURCE=.\AG_QACom_JS.cpp
# End Source File
# Begin Source File

SOURCE=.\AG_QACom_VBS.cpp
# End Source File
# Begin Source File

SOURCE=.\AG_WHL.cpp
# End Source File
# Begin Source File

SOURCE=.\AG_WHL_CPP.cpp
# End Source File
# Begin Source File

SOURCE=.\AG_WHL_CS.cpp
# End Source File
# Begin Source File

SOURCE=.\AG_WHL_VB.cpp
# End Source File
# Begin Source File

SOURCE=.\AG_WHL_VBN.cpp
# End Source File
# Begin Source File

SOURCE=.\APIGen.cpp
# End Source File
# Begin Source File

SOURCE=.\APIGen.rc
# End Source File
# Begin Source File

SOURCE=.\APIGenDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\APIGenState.cpp
# End Source File
# Begin Source File

SOURCE=.\AppendOutput.cpp
# End Source File
# Begin Source File

SOURCE=.\CustomFiles.cpp
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\AG.h
# End Source File
# Begin Source File

SOURCE=.\AG_CT.h
# End Source File
# Begin Source File

SOURCE=.\AG_EAL.h
# End Source File
# Begin Source File

SOURCE=.\AG_EAL_CPP.h
# End Source File
# Begin Source File

SOURCE=.\AG_EAOAx.h
# End Source File
# Begin Source File

SOURCE=.\AG_EAOJ.h
# End Source File
# Begin Source File

SOURCE=.\AG_EAOJ_CRLJ.h
# End Source File
# Begin Source File

SOURCE=.\AG_EAOJ_CRLV.h
# End Source File
# Begin Source File

SOURCE=.\AG_EAOJ_MCSJ.h
# End Source File
# Begin Source File

SOURCE=.\AG_EAOJ_MCSV.h
# End Source File
# Begin Source File

SOURCE=.\AG_EHL.h
# End Source File
# Begin Source File

SOURCE=.\AG_EHL_CPP.h
# End Source File
# Begin Source File

SOURCE=.\AG_EHL_CS.h
# End Source File
# Begin Source File

SOURCE=.\AG_EHL_VB.h
# End Source File
# Begin Source File

SOURCE=.\AG_EHL_VBN.h
# End Source File
# Begin Source File

SOURCE=.\AG_HLL.h
# End Source File
# Begin Source File

SOURCE=.\AG_HLL_CPP.h
# End Source File
# Begin Source File

SOURCE=.\AG_HLL_VB.h
# End Source File
# Begin Source File

SOURCE=.\AG_IHL.h
# End Source File
# Begin Source File

SOURCE=.\AG_IHL_CPP.h
# End Source File
# Begin Source File

SOURCE=.\AG_IHL_CS.h
# End Source File
# Begin Source File

SOURCE=.\AG_IHL_VB.h
# End Source File
# Begin Source File

SOURCE=.\AG_IHL_VBN.h
# End Source File
# Begin Source File

SOURCE=.\AG_ITask.h
# End Source File
# Begin Source File

SOURCE=.\AG_ITask_Java.h
# End Source File
# Begin Source File

SOURCE=.\AG_OLE.h
# End Source File
# Begin Source File

SOURCE=.\AG_OLE_ASP.h
# End Source File
# Begin Source File

SOURCE=.\AG_OLE_CPP.h
# End Source File
# Begin Source File

SOURCE=.\AG_OLE_EBM.h
# End Source File
# Begin Source File

SOURCE=.\AG_OLE_VB.h
# End Source File
# Begin Source File

SOURCE=.\AG_OLE_WS.h
# End Source File
# Begin Source File

SOURCE=.\AG_PCS.h
# End Source File
# Begin Source File

SOURCE=.\AG_PCS_CPP.h
# End Source File
# Begin Source File

SOURCE=.\AG_PCS_CS.h
# End Source File
# Begin Source File

SOURCE=.\AG_PCS_VB.h
# End Source File
# Begin Source File

SOURCE=.\AG_PCS_VBN.h
# End Source File
# Begin Source File

SOURCE=.\AG_QACom.h
# End Source File
# Begin Source File

SOURCE=.\AG_QACom_Java.h
# End Source File
# Begin Source File

SOURCE=.\AG_QACom_JS.h
# End Source File
# Begin Source File

SOURCE=.\AG_QACom_VBS.h
# End Source File
# Begin Source File

SOURCE=.\AG_WHL.h
# End Source File
# Begin Source File

SOURCE=.\AG_WHL_CPP.h
# End Source File
# Begin Source File

SOURCE=.\AG_WHL_CS.h
# End Source File
# Begin Source File

SOURCE=.\AG_WHL_VB.h
# End Source File
# Begin Source File

SOURCE=.\AG_WHL_VBN.h
# End Source File
# Begin Source File

SOURCE=.\APIGen.h
# End Source File
# Begin Source File

SOURCE=.\APIGenDlg.h
# End Source File
# Begin Source File

SOURCE=.\APIGenState.h
# End Source File
# Begin Source File

SOURCE=.\CustomFiles.h
# End Source File
# Begin Source File

SOURCE=.\Resource.h
# End Source File
# Begin Source File

SOURCE=.\SetupTranslate.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\res\APIGen.ico
# End Source File
# Begin Source File

SOURCE=.\res\APIGen.rc2
# End Source File
# End Group
# Begin Source File

SOURCE=.\ReadMe.txt
# End Source File
# End Target
# End Project
