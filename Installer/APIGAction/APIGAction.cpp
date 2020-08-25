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
//     2. Enter the project name, "APIGAction", in the Project name edit field,
//        verify the Location field, and press the OK button.
//     3. When prompted on the next page of the Wizard choose one of the "Regular DLL"
//        options and press the Finish button.
//     4. The new project will include a file named, "APIGAction.cpp".  Replace it with
//        this file.
//     5. In the project settings add "msi.lib" to the link settings dialog.
//     6. Build the project to ensure that this generated code is good by choosing the
//        command from within the Build menu.
//     7. If step 5 succeeds then insert the function name, CheckPID, into the file
//         APIGAction.def in the section labeled, "EXPORTS".
//     8. Flesh out the CheckPID function below so it accomplishes your custom
//        action goals.
//
//   Generated:   Tue Jan 31 14:22:32 2006

//
//
// ****************************************************************************
//
// CAPIGAction.cpp : Defines the initialization routines for the DLL.
//

#include "stdafx.h"
#include "APIGAction.h"
#include <msi.h>
#include <msiquery.h>
#include <stdio.h>

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
// CAPIGActionApp

BEGIN_MESSAGE_MAP(CAPIGActionApp, CWinApp)
  //{{AFX_MSG_MAP(CAPIGActionApp)
      // NOTE - the ClassWizard will add and remove mapping macros here.
      //    DO NOT EDIT what you see in these blocks of generated code!
  //}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAPIGActionApp construction

CAPIGActionApp::CAPIGActionApp()
{
    // TODO: add construction code here,
    // Place all significant initialization in InitInstance
}
/////////////////////////////////////////////////////////////////////////////
// The one and only CAPIGActionApp object
CAPIGActionApp theApp;

UINT _stdcall CheckPID(MSIHANDLE hInstall)
{
	
	CString csLocal;

	csLocal.Format( "Inside CheckPID" );
	MessageBox( NULL, csLocal, "API Generator", MB_OK );
     
	char szProperty[255];
	char* pszProperty = szProperty;

	csLocal.Format( "After szProperty" );
	MessageBox( NULL, csLocal, "API Generator", MB_OK );


	char szUtility[255];
	char* pszUtility = szUtility;
	DWORD dwStringLength;
	DWORD dwResult;
	char szValue[255];
	char* pszValue = szValue;


	csLocal.Format( "Before MsiGetProperty" );
	MessageBox( NULL, csLocal, "API Generator", MB_OK );

	//     *** MsiGetProperty
     strcpy( pszProperty, "PIDKEY");
     dwResult = MsiGetProperty(hInstall, pszProperty, pszUtility, &dwStringLength);


	csLocal.Format( "After MsiGetProperty" );
	MessageBox( NULL, csLocal, "API Generator", MB_OK );

	csLocal.Format( "PIDKEY=\"%s\"", pszUtility );
	MessageBox( NULL, csLocal, "API Generator", MB_OK );
	 

     //     *** MsiSetProperty
     strcpy( pszProperty, "PIDACCEPTED");
     strcpy( pszValue, "1");
		
	csLocal.Format( "Before MsiSetProperty" );
	MessageBox( NULL, csLocal, "API Generator", MB_OK );

     dwResult = MsiSetProperty( hInstall, pszProperty, szUtility[0] == '1' ? "1" : "0");

	csLocal.Format( "dwResult = \"%i\"", dwResult );
	MessageBox( NULL, csLocal, "API Generator", MB_OK );


	csLocal.Format( "PIDKEY=\"%c\"", szUtility[0] );
	MessageBox( NULL, csLocal, "API Generator", MB_OK );
	 
   return ERROR_SUCCESS;
}

