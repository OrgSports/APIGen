' *********************************************************************APIGen
'                AttachmateWRQ Windows Script
'             MSI Installer Database Application
' 
'  This file uses the Microsoft Installer API in a freestanding installer.
'  application.
'     1. What product / componentes must be installed?  If it is important, where must
'        this file be placed and how should it be launched?
'     2. 
'        
'
'   Generated:   Fri Dec 23 23:21:27 2005

'
'
' ****************************************************************************

On Error Resume Next
Dim installer : Set installer = Nothing
Dim csProductName
Dim csProperty
Dim csRetString
Dim nStringLength


Set installer = Wscript.CreateObject("WindowsInstaller.Installer") : CheckError

Wscript.Echo installer

'   *** MsiGetProductInfo
csProductName = "QuickTime"
csProperty = "InstallDate"
csRetString = "                                "
nStringLength = 32
uFeatureState = installer.MsiGetProductInfo( csProductName, csProperty, csRetString, nStringLength )
 
Wscript.Echo uFeatureState

Wscript.Quit 0

