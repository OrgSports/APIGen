// *********************************************************************APIGen
//                AttachmateWRQ APIGenerator
//                  MSI Custom Action DLL
// 
//  This file provides the basis for a Microsoft Installer custom action DLL.
//  It contains the class implementation file for a Microsoft Visual C++ 6.0 MFC DLL
//  that includes the function definitions specified in the API Generator and the
//  MSI calls specified for each.
//  
//  To build and run this DLL, please do the following:
//     1. With the Visual C++ 6.0 IDE, choose the File\New menu.  From the "Projects"
//        property page select "MFC AppWizard (dll)".
//     2. Enter the project name, "CustAct23", in the Project name edit field,
//        verify the Location field, and press the OK button.
//     3. When prompted on the next page of the Wizard choose one of the "Regular DLL"
//        options and press the Finish button.
//     4. The new project will include a file named, "CustAct23.cpp".  Replace it with
//        this file.
//     5. Build the project to ensure that this generated code is good by choosing the
//        command from within the Build menu.
//     6. If step 5 succeeds then start work on fleshing out the functions below that
//        were specified while running the API Generator.
//
//   Generated:   Wed Jan 04 22:31:13 2006

//
//
// ****************************************************************************
//
// CustAct23.cpp : Defines the initialization routines for the DLL.
//

#include "stdafx.h"
#include "CustAct23.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

//
//    Note!
//
//        If this DLL is dynamically linked against the MFC
//        DLLs, any functions exported from this DLL which
//        call into MFC must have the AFX_MANAGE_STATE macro
//        added at the very beginning of the function.
//
//        For example:
//
//        extern "C" BOOL PASCAL EXPORT ExportedFunction()
//        {
//            AFX_MANAGE_STATE(AfxGetStaticModuleState());
//            // normal function body here
//        }
//
//        It is very important that this macro appear in each
//        function, prior to any calls into MFC.  This means that
//        it must appear as the first statement within the 
//        function, even before any object variable declarations
//        as their constructors may generate calls into the MFC
//        DLL.
//
//        Please see MFC Technical Notes 33 and 58 for additional
//        details.
//

/////////////////////////////////////////////////////////////////////////////
// CustAct23App

BEGIN_MESSAGE_MAP(CustAct23App, CWinApp)
  //{{AFX_MSG_MAP(CustAct23App)
BEGIN_MESSAGE_MAP(CustAct23App, CWinApp)
  //{{AFX_MSG_MAP(CustAct23App)
      // NOTE - the ClassWizard will add and remove mapping macros here.
      //    DO NOT EDIT what you see in these blocks of generated code!
  //}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CustAct23App construction

CustAct23App::CustAct23App()
{
    // TODO: add construction code here,
    // Place all significant initialization in InitInstance
}
/////////////////////////////////////////////////////////////////////////////
// The one and only CustAct23App object
CustAct23App theApp;

UINT _stdcall CustFunc23(MSIHANDLE hInstall)
{

     CString csPackagePath;
     CString csScriptPath;
     CString csTransforms;



'   *** MsiAdvertiseProduct
     csPackagePath = "abc";
     csScriptPath = "def";
     csTransforms = "@eee";
     nStatus = pMSI->MsiAdvertiseProduct( csPackagePath, csScriptPath, csTransforms, English );
 
}

