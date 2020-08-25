Attribute VB_Name = "Module1"
' ****************************************************************************
'           Attachmate Verastream Host Integrator
'             APIGen Visual Basic 6.0 Application
'
'   This VB 6.0 module offers entry and exit points together with the set of
'   Verastream Host Integrator clent-side function calls specified while
'   running the API Generator.
'
'   You can build and run this module by following these steps:
'   1) You must have Microsoft Visual Studio for Visual Basic 6.0
'      installed and available on your PC.
'   2) Either install the Verastream Host Integrator Server or its Development
'      Toolkit.  If you choose the latter you can specify to install only the
'      Connectors in the Setup options and you'll have what is necessary to run
'      this module.
'   3) The VHI Com object, AppConn.dll, should be registered on your system after
'      you installed the toolkit, but to verify it is you can select the VB 6.0
'      Project\References menu item and ensure that the checkbox next to the reference
'      "WRQ Verastream Host Integrator ?.?" is checked.  Version numbers will show
'      in place of the ? wildcard characters.
'   4) Create a new VB 6.0 project.  Then choose the Project\<project name>
'       properties menu item to launch the Project Properties property sheet. Once
'       there, change the selection in the Startup Object list control to "Sub Main".
'   5) Choose the VB 6.0 Project\Add module menu item, click on the Existing tab
'      and specify this .bas file.
'   6) You can now run this within the VB 6.0 IDE or you can compile it to run as
'      a Windows executable.
'
'   Generated:   Wed Nov 16 11:10:35 2005


' ****************************************************************************

Dim VHI_ServerAddress As String
Dim VHI_Model As String
Dim csServer
Dim csModel
Dim csUserID As String
Dim csPassword As String
Dim csaModelVariable As AppConnStringMap
Dim csTable
Dim csProcedure
Dim csaDataInputValues As AppConnStringMap
Dim csFilter
Dim bCaseSensitive
Dim csOutputColNames As AppConnStringList
Dim nMaxRows
Dim RecordSet As AppConnRecordSet

Sub Main()

 Dim VHI_Session  As AppConnSessionEx
 Set VHI_Session = New AppConnSessionEx

On Error GoTo Whoops
 
'*** ConnectToModel
   csServer = "150.215.72.139"
   csModel = "CCSDemo"
   csUserID = ""
   csPassword = ""
   Set csaModelVariable = New AppConnStringMap

   VHI_Session.ConnectToModel csServer, csModel, csUserID, csPassword, csaModelVariable
 
'*** PerformTableProcedure
   csTable = "Accounts"
   csProcedure = "AccountSearch"
   Set csaDataInputValues = New AppConnStringMap
   Set csFilter = New AppConnStringMap
        csFilter.Add "MiddleInitial", "c"
        csFilter.Add "LastName", "smith"
        csFilter.Add "State", "ri"
   bCaseSensitive = False
   Set csOutputColNames = New AppConnStringList
   nMaxRows = 0

   Set RecordSet = VHI_Session.PerformTableProcedure(csTable, csProcedure, csaDataInputValues, csFilter, bCaseSensitive, csOutputColNames, nMaxRows)

' *********************  crutch #1
    Dim rec As AppConnRecord
    For i = 1 To RecordSet.Count
        Set rec = RecordSet.Item(i)
        Debug.Print rec!Name & Chr(9) & rec!AcctNumber & Chr(9) & rec!ContractDate
    Next
' end of crutch #1



   Set VHI_Session = Nothing
    Exit Sub
Whoops:
   MsgBox Err.Description, vbOKOnly, "Whoops"

End Sub
 

