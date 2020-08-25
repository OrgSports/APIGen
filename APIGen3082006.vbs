' ****************************************************************************
'                   AttachmateWRQ Reflection 3270
'                 APIGen Windows VBScript Scripting
'
'   This file consists of Windows VBScript commands that drive the Reflection for
'   IBM OLE Automation interface.
'
'   This script is prepared to launch a visible and connected session. For Reflection
'   to automatically connect the session when it is loaded you must ensure that the "Auto
'   connect" option is checked on the Session setup dialog that can be found in the
'   Session menu.
'
'   After this code is generated it will be necessary for you to double click on
'   this .vbs file.  You may choose to modify this file in one or more of the 
'   following ways:
'   1) Timing issues/race conditions are more common in this type of scripting. So,
'      a prompt is presented when you run the script that asks for a literal string
'      that an initial WaitForDisplayString call can use in your session to better prepare
'      the system for the generated automation calls that follow.
'   2) You may choose to change the 10-second timeout value on the WaitForDisplayString
'      call to a value better suited for your system. Note that the WaitForDisplayString
'      call will return as soon as the search string is found and will not block the full.
'      ten seconds unless the specified string is not found.
'   3) You can encrypt this file using the Microsoft Script Encoder for Windows
'      Script Files to prevent users from reading your source code.
'   4) You can compile it into a script component to selectively expose its functionality
'      and establish its Windows security credentials.
'         
'   Note: You may see declarations for various constants just after the time stamp below that are
'         used in some function calls.  This script does not link to a file with the actual constant
'         definitions, but because the constants' names provide indications on about what is going
'         on in a given call, and save work if you happen to ultimately use this file as a portion
'         of a VB 6.0 or VBA application they will be used.  With that stated, if you DO copy this
'         code for use in an enviroment in which the declarations are implicit, you must remove each
'         line that fits the pattern "Dim rcXXX" where "XXX" stands in for a string such as "AnyRow"
'         
'
'   Generated:   Wed Mar 08 11:52:21 2006


' ****************************************************************************

Dim System
Dim RIBMSession
Dim Sessionname
Dim cString
Dim rcAnyRow
rcAnyRow=0
Dim rcAnyCol
rcAnyCol=0

set RIBMSession = CreateObject("ReflectionIBM.Session")

Sessionname = inputbox("Open this Reflection 3270 session:", "Specify fully qualified Reflection session", "C:\TEMP\es9000.rsf")
RIBMSession.Visible = True
RIBMSession.OpenSettings 1, Sessionname
RIBMSession.WaitForEvent 1, "30", "1", 1, 1
on error resume next
if Sessionname = "" then
   WScript.Quit(1)
else
   cString = inputbox("Please provide a ready state indicator string:", "Specify ready indicator", "userid")
   Session.WaitForDisplayString cString, "0:0:10", rcAnyRow, rcAnyCol

 
'*** TransmitAnsi
cString = "Hello world"
RIBMSession.TransmitAnsi cString
end if
 
