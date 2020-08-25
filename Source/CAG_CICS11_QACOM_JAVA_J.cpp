// Static Model
#include "stdafx.h"
#include "apigen.h"

#include "CAG_CICS11_QACOM_JAVA_J.h"

CAG_CICS11_QACOM_JAVA_J::CAG_CICS11_QACOM_JAVA_J()
{
	APIFlavor=CICS11_JAVA_API;
	resetVariableFlags();
}

CAG_CICS11_QACOM_JAVA_J::~CAG_CICS11_QACOM_JAVA_J()
{
	
}

void CAG_CICS11_QACOM_JAVA_J::generateHeader(CStringArray* pcsaHeader,
											 CStringArray* pcsaBody)
{

	CString csViewOutStuff;

	csViewOutStuff.Format( "//  ****************************************************************************");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "//                        Attachmate APIGen");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "//                    CICS 1.01 Bridge Program");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "// ");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "//  This file is a program that features the use of the Attachmate");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "//  QACom API for the CICS 1.01 Bridge written in Java.  This header is to include");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "//  information on how to set up the environment to run this application, how to");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "//  build it, and how to run it.");
	pcsaHeader->Add(csViewOutStuff);


	time_t ltime;
	time( &ltime );

	csViewOutStuff.Format( "//");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "//   Generated:   %s", ctime( &ltime ) );
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "//");
	pcsaHeader->Add(csViewOutStuff);


}


void CAG_CICS11_QACOM_JAVA_J::appendBody(int nFunctionNum,
										 bool bPromptForValues,
										 CStringArray* pcsaArguments,
										 CStringArray* pcsaHeader,
										 CStringArray* pcsaBody)
{
	CString csViewOutStuff;
	CString csFunctionName, csFunctionNum, csString, csStringLength, csRetCode;

	csFunctionName = pcsaArguments->GetAt( 0 );

	csViewOutStuff.Format( " " );
	pcsaBody->Add(csViewOutStuff);

	csViewOutStuff.Format( "   // *** %s", csFunctionName );
	pcsaBody->Add(csViewOutStuff);

	switch ( nFunctionNum )
	{
		case 0:		// ApiLog::addComment
		case 1:		// ApiLog::encodeBytesToDisplayString
		case 2:		// ApiLog::logClose
		case 3:		// ApiLog::logErrorMsg
		case 4:		// ApiLog::logMethodException
		case 5:		// ApiLog::logRequest
		case 6:		// ApiLog::logResponse
		case 7:		// ApiLog::logStackTrace
		{
			csViewOutStuff.Format( "   // APIGen has not yet implemented this method." );
			pcsaBody->Add(csViewOutStuff);
		}
		break;

		case 8:		// ChangePassword
		{
			csViewOutStuff.Format( "   csIPAddr = \"%s\";", pcsaArguments->GetAt(1) );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "   lPort = %s;", pcsaArguments->GetAt(2) );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "   csUserID = \"%s\";", pcsaArguments->GetAt(3) );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "   csPassword = \"%s\";", pcsaArguments->GetAt(4) );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "   csNewPassword = \"%s\";", pcsaArguments->GetAt(5) );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "" );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "   ChangePassword( csIPAddr, lPort, csUserID, csPassword, csNewPassword );" );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "" );
			pcsaBody->Add(csViewOutStuff);

		}
		break;
			
		case 9:		// ConnectBridge
		{
			csViewOutStuff.Format( "   csIPAddr = \"%s\";", pcsaArguments->GetAt(1) );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "   lPort = %s;", pcsaArguments->GetAt(2) );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "   lTermModel = %s;", pcsaArguments->GetAt(3) );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "   csUserID = \"%s\";", pcsaArguments->GetAt(4) );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "   csPassword = \"%s\";", pcsaArguments->GetAt(5) );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "" );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "   ConnectBridge( csIPAddr, lPort, lTermModel, csUserID, csPassword );" );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "" );
			pcsaBody->Add(csViewOutStuff);

		}
		break;
			
		case 10:	// BridgeAPI::Disconnect
		case 11:	// BridgeAPI::FindString
		case 12:	// BridgeAPI::FindString Ex
		case 13:	// BridgeAPI::GetAllFieldInformation
		case 14:	// BridgeAPI::GetAllFieldInformation Ex2
		case 15:	// BridgeAPI::GetAllFieldInformation Ex3
		case 16:	// BridgeAPI::GetAllFieldInformation Ex4
		case 17:	// BridgeAPI::GetConnectionStatus
		case 18:	// BridgeAPI::GetCurrentScreenName
		case 19:	// BridgeAPI::GetCursorPosition
		case 20:	// BridgeAPI::GetFieldAttributes
		case 21:	// BridgeAPI::GetFieldAttributes Ex2
		case 22:	// BridgeAPI::GetFieldAttributes Ex3
		case 23:	// BridgeAPI::GetFieldAttributes Ex4
		case 24:	// BridgeAPI::GetFieldCoordinates
		case 25:	// BridgeAPI::GetFieldCoordinates Ex2
		case 26:	// BridgeAPI::GetFieldCoordinates Ex3
		case 27:	// BridgeAPI::GetFieldCoordinates Ex4
		case 28:	// BridgeAPI::GetFieldCount
		case 29:	// BridgeAPI::GetFieldCount Ex
		case 30:	// BridgeAPI::GetFieldNameFromIndex
		case 31:	// BridgeAPI::GetFieldNameFromIndex Ex
		case 32:	// BridgeAPI::GetFieldValue
		case 33:	// BridgeAPI::GetFieldValue Ex2
		case 34:	// BridgeAPI::GetFieldValue Ex3
		case 35:	// BridgeAPI::GetFieldValue Ex4
		case 36:	// BridgeAPI::GetHostDelay
		case 37:	// BridgeAPI::GetReturnCodeMessage
		case 38:	// BridgeAPI::GetScreenSize
		case 39:	// BridgeAPI::GetScreenSize Ex
		case 40:	// BridgeAPI::GetString
		case 41:	// BridgeAPI::GetString Ex
		case 42:	// BridgeAPI::GetTransactionSystemId
		case 43:	// BridgeAPI::PutString
		case 44:	// BridgeAPI::SendKeys
		case 45:	// BridgeAPI::SendKeysEx
		case 46:	// BridgeAPI::SendKeysGetAllFieldInformation
		case 47:	// BridgeAPI::SendKeysGetString
		case 48:	// BridgeAPI::SetCursorPosition
		case 49:	// BridgeAPI::SetFieldValue
		case 50:	// BridgeAPI::SetFieldValue Ex2 
		case 51:	// BridgeAPI::SetFieldValue Ex3
		case 52:	// BridgeAPI::SetHostDelay
		case 53:	// BridgeAPI::SetSettleTime
		case 54:	// BridgeAPI::SetTimeOut
		case 55:	// BridgeAPI::SetTraceActive
		case 56:	// BridgeAPI::SetTraceInactive
		case 57:	// BridgeAPI::SetTraceName
		case 58:	// BridgeAPI::Terminate
		case 59:	// CICSResponse::equalCompareBytes
		case 60:	// CICSResponse::getApiCargo
		case 61:	// CICSResponse::getCargoLength
		case 62:	// CICSResponse::getCicsRC
		case 63:	// CICSResponse::getFunction
		case 64:	// CICSResponse::getSessionId
		case 65:	// CICSResponse::parseResponseHeaderAndPacket
		case 66:	// CICSResponse::setAPITrace
		case 67:	// CICSResponse::setCiscRC
		case 68:	// CICSResponse::setSessionId
		case 69:	// ConHTTP3270CICS::getCicsIPAddress
		case 70:	// ConHTTP3270CICS::getCicsSocketPort
		case 71:	// ConHTTP3270CICS::getHostDelay
		case 72:	// ConHTTP3270CICS::getMessageResponseData
		case 73:	// ConHTTP3270CICS::getRemoteHostAddress
		case 74:	// ConHTTP3270CICS::getRemoteHostPort
		case 75:	// ConHTTP3270CICS::sendRequestMessage
		case 76:	// ConHTTP3270CICS::setAPITrace
		case 77:	// ConHTTP3270CICS::setCicsIPAddress
		case 78:	// ConHTTP3270CICS::SetCicsSocketPort
		case 79:	// ConHTTP3270CICS::setHostDelay
		case 80:	// ConHTTP3270CICS::setHostIpAddress
		case 81:	// ConHTTP3270CICS::setHostIPPort
		case 82:	// ConHTTP3270CICS::setRemoteHostAddress
		case 83:	// ConHTTP3270CICS::setRemoteHostPort
		case 84:	// ConHTTP3270CICS::setSessionId
		case 85:	// Encode::AtoE
		case 86:	// Encode::AtoEInPlace
		case 87:	// Encode::EtoA
		case 88:	// Encode::EtoAInPlace
		case 89:	// Encode::padAtoE
		{
			csViewOutStuff.Format( "   // APIGen has not yet implemented this method." );
			pcsaBody->Add(csViewOutStuff);
		}
	}

	pcsaArguments->RemoveAll();
}



void CAG_CICS11_QACOM_JAVA_J::loadFunctionList(CListBox* listTranslateFunction)
{
	listTranslateFunction->ResetContent();

	csaFunctions.Add( "ApiLog::addComment" );
	csaFunctions.Add( "ApiLog::encodeBytesToDisplayString" );
	csaFunctions.Add( "ApiLog::logClose" );
	csaFunctions.Add( "ApiLog::logErrorMsg" );
	csaFunctions.Add( "ApiLog::logMethodException" );
	csaFunctions.Add( "ApiLog::logRequest" );
	csaFunctions.Add( "ApiLog::logResponse" );
	csaFunctions.Add( "ApiLog::logStackTrace" );

	csaFunctions.Add( "BridgeAPI::changePassword" );
	csaFunctions.Add( "BridgeAPI::connectBridge" );
	csaFunctions.Add( "BridgeAPI::disconnect" );
	csaFunctions.Add( "BridgeAPI::findString" );
	csaFunctions.Add( "BridgeAPI::findString Ex" );
	csaFunctions.Add( "BridgeAPI::getAllFieldInformation" );
	csaFunctions.Add( "BridgeAPI::getAllFieldInformation Ex2" );
	csaFunctions.Add( "BridgeAPI::getAllFieldInformation Ex3" );
	csaFunctions.Add( "BridgeAPI::getAllFieldInformation Ex4" );
	csaFunctions.Add( "BridgeAPI::getConnectionStatus" );
	csaFunctions.Add( "BridgeAPI::getCurrentScreenName" );
	csaFunctions.Add( "BridgeAPI::getCursorPosition" );
	csaFunctions.Add( "BridgeAPI::getFieldAttributes" );
	csaFunctions.Add( "BridgeAPI::getFieldAttributes Ex2" );
	csaFunctions.Add( "BridgeAPI::getFieldAttributes Ex3" );
	csaFunctions.Add( "BridgeAPI::getFieldAttributes Ex4" );
	csaFunctions.Add( "BridgeAPI::getFieldCoordinates" );
	csaFunctions.Add( "BridgeAPI::getFieldCoordinates Ex2" );
	csaFunctions.Add( "BridgeAPI::getFieldCoordinates Ex3" );
	csaFunctions.Add( "BridgeAPI::getFieldCoordinates Ex4" );
	csaFunctions.Add( "BridgeAPI::getFieldCount" );
	csaFunctions.Add( "BridgeAPI::getFieldCount Ex" );
	csaFunctions.Add( "BridgeAPI::getFieldNameFromIndex" );
	csaFunctions.Add( "BridgeAPI::getFieldNameFromIndex Ex" );
	csaFunctions.Add( "BridgeAPI::getFieldValue" );
	csaFunctions.Add( "BridgeAPI::getFieldValue Ex2" );
	csaFunctions.Add( "BridgeAPI::getFieldValue Ex3" );
	csaFunctions.Add( "BridgeAPI::getFieldValue Ex4" );
	csaFunctions.Add( "BridgeAPI::getHostDelay" );
	csaFunctions.Add( "BridgeAPI::getReturnCodeMessage" );
	csaFunctions.Add( "BridgeAPI::getScreenSize" );
	csaFunctions.Add( "BridgeAPI::getScreenSize Ex" );
	csaFunctions.Add( "BridgeAPI::getString" );
	csaFunctions.Add( "BridgeAPI::getString Ex" );
	csaFunctions.Add( "BridgeAPI::getTransactionSystemId" );
	csaFunctions.Add( "BridgeAPI::putString" );
	csaFunctions.Add( "BridgeAPI::sendKeys" );
	csaFunctions.Add( "BridgeAPI::sendKeysEx" );
	csaFunctions.Add( "BridgeAPI::sendKeysGetAllFieldInformation" );
	csaFunctions.Add( "BridgeAPI::sendKeysGetString" );
	csaFunctions.Add( "BridgeAPI::setCursorPosition" );
	csaFunctions.Add( "BridgeAPI::setFieldValue" );
	csaFunctions.Add( "BridgeAPI::setFieldValue Ex2" );
	csaFunctions.Add( "BridgeAPI::setFieldValue Ex3" );
	csaFunctions.Add( "BridgeAPI::setHostDelay" );
	csaFunctions.Add( "BridgeAPI::setSettleTime" );
	csaFunctions.Add( "BridgeAPI::setTimeOut" );
	csaFunctions.Add( "BridgeAPI::setTraceActive" );
	csaFunctions.Add( "BridgeAPI::setTraceInactive" );
	csaFunctions.Add( "BridgeAPI::setTraceName" );
	csaFunctions.Add( "BridgeAPI::terminate" );

	csaFunctions.Add( "CICSResponse::equalCompareBytes" );
	csaFunctions.Add( "CICSResponse::getApiCargo" );
	csaFunctions.Add( "CICSResponse::getCargoLength" );
	csaFunctions.Add( "CICSResponse::getCicsRC" );
	csaFunctions.Add( "CICSResponse::getFunction" );
	csaFunctions.Add( "CICSResponse::getSessionId" );
	csaFunctions.Add( "CICSResponse::parseResponseHeaderAndPacket" );
	csaFunctions.Add( "CICSResponse::setAPITrace" );
	csaFunctions.Add( "CICSResponse::setCiscRC" );
	csaFunctions.Add( "CICSResponse::setSessionId" );

	csaFunctions.Add( "ConHTTP3270CICS::getCicsIPAddress" );
	csaFunctions.Add( "ConHTTP3270CICS::getCicsSocketPort" );
	csaFunctions.Add( "ConHTTP3270CICS::getHostDelay" );
	csaFunctions.Add( "ConHTTP3270CICS::getMessageResponseData" );
	csaFunctions.Add( "ConHTTP3270CICS::getRemoteHostAddress" );
	csaFunctions.Add( "ConHTTP3270CICS::getRemoteHostPort" );
	csaFunctions.Add( "ConHTTP3270CICS::sendRequestMessage" );
	csaFunctions.Add( "ConHTTP3270CICS::setAPITrace" );
	csaFunctions.Add( "ConHTTP3270CICS::setCicsIPAddress" );
	csaFunctions.Add( "ConHTTP3270CICS::SetCicsSocketPort" );
	csaFunctions.Add( "ConHTTP3270CICS::setHostDelay" );
	csaFunctions.Add( "ConHTTP3270CICS::setHostIpAddress" );
	csaFunctions.Add( "ConHTTP3270CICS::setHostIPPort" );
	csaFunctions.Add( "ConHTTP3270CICS::setRemoteHostAddress" );
	csaFunctions.Add( "ConHTTP3270CICS::setRemoteHostPort" );
	csaFunctions.Add( "ConHTTP3270CICS::setSessionId" );

	csaFunctions.Add( "Encode::AtoE" );
	csaFunctions.Add( "Encode::AtoEInPlace" );
	csaFunctions.Add( "Encode::EtoA" );
	csaFunctions.Add( "Encode::EtoAInPlace" );
	csaFunctions.Add( "Encode::padAtoE" );

	listTranslateFunction->ResetContent();	
	
	for (int k=0; k<csaFunctions.GetSize(); k++)
	{
		listTranslateFunction->AddString( csaFunctions.GetAt(k) );
	}

	listTranslateFunction->SetCurSel(0);
	
}

void CAG_CICS11_QACOM_JAVA_J::resetVariableFlags()
{
}