<%@ Language=VBScript %>
<HTML>
<HEAD>
</HEAD>
<BODY>
<PRE>
<%

dim qadll
dim outText
dim outNumChars
dim inScreen
dim outFieldCount
dim outFieldNames
dim outFieldValues
dim outFieldAttributes
dim outFieldRows
dim outFieldCols
dim outFieldLengths
dim outCurrentScreen
dim outColumn
dim outStatus
dim outTerminalID
dim MyVarMyVar
dim rc
dim start
dim finish

On Error Resume Next
	
set qadll = server.CreateObject("BridgeAPI.BridgeAPIObject.1")
if Err.number <> 0 then
			Response.Write "Error in server.CreateObject "
			Response.Write "Return Code = " & Err.number & "<BR>"
			else
			Response.Write "Successful server.CreateObject " & "<BR>"
	end if
	
	
	'TOM CICS region A using MCS on Brian's server
	qadll.ConnectBridge "149.82.215.1", 2317, 2, "DEVTST1", "DEVTST1", "BRIDGEPOOL"	
	
	if Err.number <> 0 then
			Response.Write "Error in ConnectBridge "
			Response.Write "Return Code = " & Err.number & "<BR>"
			else
			Response.Write "Successful ConnectBridge "  & "<BR>"
		end if
	
	qadll.SendKeysGetString "TCHP@E1@E10101@E", 1, 1, 0, outText	
	
	if Err.number <> 0 then
				Response.Write "Error in SendKeysGetString "
				Response.Write "Return Code = " & Err.number & "<BR>"
			else
				Response.Write "Successful SendKeysGetString " & "<BR>"
		
			end if
	
	for i = 1 to 1841 step 80
		MyVarMyVar = Mid(outText, i, 80)
		Response.Write MyVarMyVar & "<BR>"
	Next						
	
	qadll.SendKeys "@c@C"  'PF12 AND CLEAR FOR TCHx

	if Err.number <> 0 then
				Response.Write "Error in SendKeys for PF12 AND CLEAR "
				Response.Write "Return Code = " & Err.number & "<BR>"
				else
				Response.Write "Successful SendKeys for PF12 AND CLEAR " & "<BR>"
		
			end if
	
	qadll.Disconnect
	if Err.number <> 0 then
				Response.Write "Error in Disconnect "
				Response.Write "Return Code = " & Err.number & "<BR>"
				else
				Response.Write "Successful Disconnect" & "<BR>"
			end if

'---CLEANUP---------------		
set qadll = nothing
set outText = nothing
set outNumChars = nothing
set inScreen = nothing
set outFieldCount = nothing
set outFieldNames = nothing
set outFieldValues = nothing
set outFieldAttributes = nothing
set outFieldRows = nothing
set outFieldCols = nothing
set outFieldLengths	= nothing
set outTerminalID = nothing
set outCurrentScreen = nothing
set outColumn = nothing 
set outStatus = nothing
set MyVarMyVar = nothing
set rc = nothing
set start = nothing
set finish = nothing

session.Abandon
%>
</PRE>
</BODY>
</HTML>