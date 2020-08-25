// Static Model
#include "stdafx.h"
#include "apigen.h"

#include "CAG_CICS20_QACOM_JAVA_J.h"


////////////////////////////////////

CAG_CICS20_QACOM_JAVA_J::CAG_CICS20_QACOM_JAVA_J()
{
	APIFlavor=CICS20_JAVA_API;	
	resetVariableFlags();
}

CAG_CICS20_QACOM_JAVA_J::~CAG_CICS20_QACOM_JAVA_J()
{
	
}

void CAG_CICS20_QACOM_JAVA_J::generateHeader(CStringArray* pcsaHeader,
											 CStringArray* pcsaBody)
{

	CString csViewOutStuff;

	csViewOutStuff.Format( "//  ****************************************************************************");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "//                        Attachmate APIGen");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "//           Synapta Service Builder for CICS 3270 Bridge, version 2.0");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "// ");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "// To build or run this simple Java console application, insure that the BridgeAPI.jar from ");
	pcsaHeader->Add(csViewOutStuff);

    csViewOutStuff.Format( "// Synapta Service Builder for CICS 3270 Bridge, >>>>version 2.0<<<< is in the build/run classpath.");
	pcsaHeader->Add(csViewOutStuff);

	time_t ltime;
	time( &ltime );

	csViewOutStuff.Format( "//");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "//   Generated:   %s", ctime( &ltime ) );
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "//");
	pcsaHeader->Add(csViewOutStuff);

    csViewOutStuff.Format( "//  ****************************************************************************");
	pcsaHeader->Add(csViewOutStuff);

    pcsaHeader->Add(" ");
    pcsaHeader->Add("import com.attachmate.cicsbridge.ws.*;");
    pcsaHeader->Add("import com.attachmate.cicsbridge.j2ee.outputs.*;"); 
    pcsaHeader->Add(" ");
    pcsaHeader->Add("public class APIGenSample" );
    pcsaHeader->Add("{ ");
    pcsaHeader->Add("  public static void main(String args[])");
    pcsaHeader->Add("  {");
    pcsaHeader->Add("    int iRet = 0;");
    pcsaHeader->Add("    try {");
    pcsaHeader->Add("    BridgeAPI api = new BridgeAPI();");

    
}


void CAG_CICS20_QACOM_JAVA_J::appendBody(int nFunctionNum,
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
		case 0:		// AllFieldInformation::getFieldAttributes
		case 1:		// AllFieldInformation::getFieldColors
		case 2:		// AllFieldInformation::getFieldCols
		case 3:		// AllFieldInformation::getFieldCount
		case 4:		// AllFieldInformation::getFieldHighlights
		case 5:		// AllFieldInformation::getFieldLengths
		case 6:		// AllFieldInformation::getFieldNames
		case 7:		// AllFieldInformation::getFieldRows
		case 8:		// AllFieldInformation::getFieldValues
		case 9:		// AllFieldInformation::getReturnCode
		{
			csViewOutStuff.Format( "   // APIGen has not yet implemented this method." );
			pcsaBody->Add(csViewOutStuff);
		}
		break;

		case 10:		// ChangePassword
		{
            csViewOutStuff.Format("    iRet = api.changePassword(\"%s\",", pcsaArguments->GetAt(1));  
			pcsaBody->Add(csViewOutStuff);
            csViewOutStuff.Format("                              %s,", pcsaArguments->GetAt(2));
            pcsaBody->Add(csViewOutStuff);
            csViewOutStuff.Format("                              \"%s\",", pcsaArguments->GetAt(3));
            pcsaBody->Add(csViewOutStuff);
            csViewOutStuff.Format("                              \"%s\",", pcsaArguments->GetAt(4));
            pcsaBody->Add(csViewOutStuff);
            csViewOutStuff.Format("                              \"%s\");", pcsaArguments->GetAt(5));
            pcsaBody->Add(csViewOutStuff);
            pcsaBody->Add("    System.out.println(\"changePassword: \" + iRet + \" \" + api.getReturnCodeMessage(iRet));");
		}
		break;
			
		case 11:		// ConnectBridge
		{
			csViewOutStuff.Format("    iRet = api.connectBridge(\"%s\",", pcsaArguments->GetAt(1));  
			pcsaBody->Add(csViewOutStuff);
            csViewOutStuff.Format("                              %s,", pcsaArguments->GetAt(2));
            pcsaBody->Add(csViewOutStuff);
            csViewOutStuff.Format("                              %s,", pcsaArguments->GetAt(3).Right(1));
            pcsaBody->Add(csViewOutStuff);
            csViewOutStuff.Format("                              \"%s\",", pcsaArguments->GetAt(4));
            pcsaBody->Add(csViewOutStuff);
            csViewOutStuff.Format("                              \"%s\");", pcsaArguments->GetAt(5));
            pcsaBody->Add(csViewOutStuff);
            pcsaBody->Add("    System.out.println(\"connectBridge: \" + iRet + \" \" + api.getReturnCodeMessage(iRet));");

		}
		break;
			

		case 12:	// BridgeAPI::ConnectBridge Ex2
        {
            csViewOutStuff.Format("    iRet = api.connectBridge(\"%s\",", pcsaArguments->GetAt(1));  
			pcsaBody->Add(csViewOutStuff);
            csViewOutStuff.Format("                              %s,", pcsaArguments->GetAt(2));
            pcsaBody->Add(csViewOutStuff);
            csViewOutStuff.Format("                              %s,", pcsaArguments->GetAt(3).Right(1));
            pcsaBody->Add(csViewOutStuff);
            csViewOutStuff.Format("                              \"%s\",", pcsaArguments->GetAt(4));
            pcsaBody->Add(csViewOutStuff);
            csViewOutStuff.Format("                              \"%s\",", pcsaArguments->GetAt(5));
            pcsaBody->Add(csViewOutStuff);
            csViewOutStuff.Format("                              \"%s\");", pcsaArguments->GetAt(6));
            pcsaBody->Add(csViewOutStuff);
            pcsaBody->Add("    System.out.println(\"connectBridge: \" + iRet + \" \" + api.getReturnCodeMessage(iRet));");


        }
        break;

		case 13:	// BridgeAPI::ConnectBridge Ex3
        {
            csViewOutStuff.Format("    iRet = api.connectBridge(\"%s\",", pcsaArguments->GetAt(1));  
			pcsaBody->Add(csViewOutStuff);
            csViewOutStuff.Format("                              %s,", pcsaArguments->GetAt(2));
            pcsaBody->Add(csViewOutStuff);
            csViewOutStuff.Format("                              %s,", pcsaArguments->GetAt(3));
            pcsaBody->Add(csViewOutStuff);
            csViewOutStuff.Format("                              \"%s\",", pcsaArguments->GetAt(4));
            pcsaBody->Add(csViewOutStuff);
            csViewOutStuff.Format("                              \"%s\",", pcsaArguments->GetAt(5));
            pcsaBody->Add(csViewOutStuff);
            csViewOutStuff.Format("                              \"%s\",", pcsaArguments->GetAt(6));
            pcsaBody->Add(csViewOutStuff);
            csViewOutStuff.Format("                              \"%s\");", pcsaArguments->GetAt(7));
            pcsaBody->Add(csViewOutStuff);
            pcsaBody->Add("    System.out.println(\"connectBridge: \" + iRet + \" \" + api.getReturnCodeMessage(iRet);)");


        }
        break;

		case 14:	// BridgeAPI::connectBridge Ex4
        {
            csViewOutStuff.Format("    iRet = api.connectBridge(\"%s\",", pcsaArguments->GetAt(1));  
			pcsaBody->Add(csViewOutStuff);
            csViewOutStuff.Format("                              %s,", pcsaArguments->GetAt(2));
            pcsaBody->Add(csViewOutStuff);
            csViewOutStuff.Format("                              %s,", pcsaArguments->GetAt(3));
            pcsaBody->Add(csViewOutStuff);
            csViewOutStuff.Format("                              \"%s\",", pcsaArguments->GetAt(4));
            pcsaBody->Add(csViewOutStuff);
            csViewOutStuff.Format("                              \"%s\",", pcsaArguments->GetAt(5));
            pcsaBody->Add(csViewOutStuff);
            csViewOutStuff.Format("                              \"%s\",", pcsaArguments->GetAt(6));
            pcsaBody->Add(csViewOutStuff);
            csViewOutStuff.Format("                              \"%s\",", pcsaArguments->GetAt(7));
            pcsaBody->Add(csViewOutStuff);
            csViewOutStuff.Format("                              \"%s\");", pcsaArguments->GetAt(8));
            pcsaBody->Add(csViewOutStuff);
            pcsaBody->Add("    System.out.println(\"connectBridge: \" + iRet + \" \" + api.getReturnCodeMessage(iRet));");

        }
        break;

		case 15:	// BridgeAPI::Disconnect
        {
            csViewOutStuff.Format("    iRet = api.disconnect();");  
			pcsaBody->Add(csViewOutStuff);
            pcsaBody->Add("    System.out.println(\"disconnect: \" + iRet + \" \" + api.getReturnCodeMessage(iRet));");

        }
        break;

		case 16:	// BridgeAPI::FindString
        {
            if( !b_FindString )
            {
                b_FindString = TRUE;
                pcsaBody->Add("    FindString fs;");
            }
            
            csViewOutStuff.Format("    fs = api.findString(%s,", pcsaArguments->GetAt(1));
            pcsaBody->Add(csViewOutStuff);
            csViewOutStuff.Format("                        \"%s\",", pcsaArguments->GetAt(2));
            pcsaBody->Add(csViewOutStuff);
            csViewOutStuff.Format("                        %s,", pcsaArguments->GetAt(3));
            pcsaBody->Add(csViewOutStuff);
            csViewOutStuff.Format("                        %s,", pcsaArguments->GetAt(4));
            pcsaBody->Add(csViewOutStuff);
            csViewOutStuff.Format("                        %s);", pcsaArguments->GetAt(5));
            pcsaBody->Add(csViewOutStuff);
           
            pcsaBody->Add("    System.out.println(\"findString: \" + fs.getReturnCode() + \" \" + api.getReturnCodeMessage(fs.getReturnCode()));"); 
            pcsaBody->Add("    if(fs.getReturnCode() == 0)");
            pcsaBody->Add("       System.out.println(\"string found at row \" + fs.getRow() + \" column \" + fs.getColumn());");  
        }
        break;

		case 17:	// BridgeAPI::FindString Ex2
        {
            if( !b_outRow )
            {
                b_outRow = TRUE;
                pcsaBody->Add("    MutableInt outRow = new MutableInt();");
            }
             if( !b_outColumn )
            {
                b_outColumn = TRUE;
                pcsaBody->Add("    MutableInt outColumn = new MutableInt();");
            }

            csViewOutStuff.Format("    fs = api.findString(\"%s\",", pcsaArguments->GetAt(1));
            pcsaBody->Add(csViewOutStuff);
            csViewOutStuff.Format("                        \"%s\",", pcsaArguments->GetAt(2));
            pcsaBody->Add(csViewOutStuff);
            csViewOutStuff.Format("                        %s,", pcsaArguments->GetAt(3));
            pcsaBody->Add(csViewOutStuff);
            csViewOutStuff.Format("                        %s,", pcsaArguments->GetAt(4));
            pcsaBody->Add(csViewOutStuff);
            csViewOutStuff.Format("                        %s,", pcsaArguments->GetAt(5));
            pcsaBody->Add(csViewOutStuff);
            csViewOutStuff.Format("                        %s");
            pcsaBody->Add(csViewOutStuff);
            csViewOutStuff.Format("                        %s);");
            pcsaBody->Add(csViewOutStuff);

            pcsaBody->Add("    System.out.println(\"findString: \" + iRet + \" \" + api.getReturnCodeMessage(iRet));");
            pcsaBody->Add("    if(iRet == 0)");
            pcsaBody->Add("       System.out.println(\"string found at row \" + outRow.getInt() + \" column \" + outColumn.getInt());");  

        }
        break;

		case 18:	// BridgeAPI::GetAllFieldInformation
        {
            if ( !b_outFieldCount ) 
            {
                b_outFieldCount = TRUE;
                pcsaBody->Add("    MutableInt outFieldCount = new MutableInt();");
            }
            if ( !b_outFieldNames ) 
            {
                b_outFieldNames = TRUE;
                pcsaBody->Add("    MutableObject outFieldNames = new MutableObject();");
            }
            if ( !b_outFieldValues ) 
            {
                b_outFieldValues = TRUE;
                pcsaBody->Add("    MutableObject outFieldValues = new MutableObject();");
            }
            if ( !b_outFieldAttributes ) 
            {
                b_outFieldAttributes = TRUE;
                pcsaBody->Add("    MutableObject outFieldAttributes = new MutableObject();");
            }
            if ( !b_outFieldRows ) 
            {
                b_outFieldRows = TRUE;
                pcsaBody->Add("    MutableObject outFieldRows = new MutableObject();");
            }
            if ( !b_outFieldCols ) 
            {
                b_outFieldCols = TRUE;
                pcsaBody->Add("    MutableObject outFieldCols = new MutableObject();");
            }
            if ( !b_outFieldLengths ) 
            {
                b_outFieldLengths = TRUE;
                pcsaBody->Add("    MutableObject outFieldLengths = new MutableObject();");
            }
            if ( !b_outFieldColors ) 
            {
                b_outFieldColors = TRUE;
                pcsaBody->Add("    MutableObject outFieldColors = new MutableObject();");
            }
            if ( !b_outFieldHighlights ) 
            {
                b_outFieldHighlights = TRUE;
                pcsaBody->Add("    MutableObject outFieldHighlights = new MutableObject();");
            }
            pcsaBody->Add(" ");
            pcsaBody->Add("    iRet = api.getAllFieldInformation(-1, outFieldCount, outFieldNames, outFieldValues, outFieldAttributes,");
            pcsaBody->Add("         outFieldRows, outFieldCols, outFieldLengths, outFieldColors, outFieldHighlights);");  
            pcsaBody->Add(" ");
            pcsaBody->Add("    System.out.println(\"getAllFieldInformation: \" + iRet + \" \" + api.getReturnCodeMessage(iRet));");
            pcsaBody->Add("    if(iRet == 0){");
            pcsaBody->Add("      System.out.println(\"total fields this screen: \" + outFieldCount.getInt());");
            pcsaBody->Add("      for (int i=0; i<outFieldCount; i++){");
            pcsaBody->Add("        System.out.println(\"name: \" + outFieldNames[i] + \" attribute: \" + outFieldAttributes[i] + \" length: \" + outFieldLengths[i]);");
            pcsaBody->Add("        System.out.println(\"row: \" + outFieldRows[i] + \" column: \" + outFieldCols[i] + \" color: \" + outFieldColors[i] + \" highlight: \" + outFieldHighlights[i]);");
            pcsaBody->Add("        System.out.println(\"value: \" + outFieldValues[i] + \"\\n\");");
            pcsaBody->Add("      }");
            pcsaBody->Add("    }");

        }
        break;

		case 19:	// BridgeAPI::GetAllFieldInformation Ex2
                    ////remove this case...it is a duplicate.


		case 20:	// BridgeAPI::GetAllFieldInformation Ex3
        {
            if ( !b_outFieldCount ) 
            {
                b_outFieldCount = TRUE;
                pcsaBody->Add("    MutableInt outFieldCount = new MutableInt();");
            }
            if ( !b_outFieldNames ) 
            {
                b_outFieldNames = TRUE;
                pcsaBody->Add("    MutableObject outFieldNames = new MutableObject();");
            }
            if ( !b_outFieldValues ) 
            {
                b_outFieldValues = TRUE;
                pcsaBody->Add("    MutableObject outFieldValues = new MutableObject();");
            }
            if ( !b_outFieldAttributes ) 
            {
                b_outFieldAttributes = TRUE;
                pcsaBody->Add("    MutableObject outFieldAttributes = new MutableObject();");
            }
            if ( !b_outFieldRows ) 
            {
                b_outFieldRows = TRUE;
                pcsaBody->Add("    MutableObject outFieldRows = new MutableObject();");
            }
            if ( !b_outFieldCols ) 
            {
                b_outFieldCols = TRUE;
                pcsaBody->Add("    MutableObject outFieldCols = new MutableObject();");
            }
            if ( !b_outFieldLengths ) 
            {
                b_outFieldLengths = TRUE;
                pcsaBody->Add("    MutableObject outFieldLengths = new MutableObject();");
            }
           
            pcsaBody->Add(" ");
            pcsaBody->Add("    iRet = api.getAllFieldInformation(-1, outFieldCount, outFieldNames, outFieldValues, outFieldAttributes,");
            pcsaBody->Add("         outFieldRows, outFieldCols, outFieldLengths);");  
            pcsaBody->Add(" ");
            pcsaBody->Add("    System.out.println(\"getAllFieldInformation: \" + iRet + \" \" + api.getReturnCodeMessage(iRet));");
            pcsaBody->Add("    if(iRet == 0){");
            pcsaBody->Add("      System.out.println(\"total fields this screen: \" + outFieldCount.getInt());");
            pcsaBody->Add("      for (int i=0; i<outFieldCount; i++){");
            pcsaBody->Add("        System.out.println(\"name: \" + outFieldNames[i] + \" attribute: \" + outFieldAttributes[i] + \" length: \" + outFieldLengths[i]);");
            pcsaBody->Add("        System.out.println(\"row: \" + outFieldRows[i] + \" column: \" + outFieldCols[i] );");
            pcsaBody->Add("        System.out.println(\"value: \" + outFieldValues[i] + \"\\n\");");
            pcsaBody->Add("      }");
            pcsaBody->Add("    }");
        }
        break;

		case 21:	// BridgeAPI::GetAllFieldInformation Ex4
                    ////remove this case...it is a duplicate.

		case 22:	// BridgeAPI::GetConnectionStatus
        {
            if ( !b_outStatus) 
            {
                b_outStatus = TRUE;
                pcsaBody->Add("    MutableInt outStatus = new MutableInt();");
            }

            pcsaBody->Add("    iRet = api.getConnectionStatus(outStatus);");
            pcsaBody->Add("    System.out.println(\"getConnectionStatus: \" + iRet + \" \" + api.getReturnCodeMessage(iRet));");
            pcsaBody->Add("    if(iRet==0)");
            pcsaBody->Add("      System.out.println(\"status: \" + outStatus.getInt());");            


        }
        break;

		case 23:	// BridgeAPI::GetCurrentScreenName
        {
            if (!b_outScreenName)
            {
                b_outScreenName = TRUE;
                pcsaBody->Add("    MutableObject outScreenName = new MutableObject();");
            }
            pcsaBody->Add("    iRet = api.getCurrentScreenName(outScreenName);");            
            pcsaBody->Add("    System.out.println(\"getCurrentScreenName: \" + iRet + \" \" + api.getReturnCodeMessage(iRet));");
            pcsaBody->Add("    if(iRet==0)");
            pcsaBody->Add("      System.out.println(\"screen name: \" + outScreenName.toString());");

        }
        break;
    
		case 24:	// BridgeAPI::GetCursorPosition
        {
            if( !b_outRow )
            {
                b_outRow = TRUE;
                pcsaBody->Add("    MutableInt outRow = new MutableInt();");
            }
             if( !b_outColumn )
            {
                b_outColumn = TRUE;
                pcsaBody->Add("    MutableInt outColumn = new MutableInt();");
            }

            pcsaBody->Add("    iRet = api.getCursorPosition(outRow, outColumn);");
            pcsaBody->Add("    System.out.println(\"getCursorPosition: \" + iRet + \" \" + api.getReturnCodeMessage(iRet));");
            pcsaBody->Add("    if(iRet==0)");
            pcsaBody->Add("      System.out.println(\"cursor row: \" + outRow.getInt() + \" cursor column: \" + outColumn.getInt());");

        }
        break;

		case 25:	// BridgeAPI::GetFieldAttributes
        {
            if (!b_Attribute)
            {
                b_Attribute = TRUE;
                pcsaBody->Add("    MutableInt outAttribute = new MutableInt();");
            }
            pcsaBody->Add("    iRet = api.getFieldAttributes(-1,");
            csViewOutStuff.Format("                                  \"%s\",", pcsaArguments->GetAt(2));
            pcsaBody->Add(csViewOutStuff); 
            pcsaBody->Add("                                  outAttribute);");
            pcsaBody->Add("    System.out.println(\"getFieldAttributes: \" + iRet + \" \" + api.getReturnCodeMessage(iRet));");
            pcsaBody->Add("    if(iRet==0)");
            pcsaBody->Add("      System.out.println(\"attribute: \" + outAttribute.getInt());");


        }
        break;

		case 26:	// BridgeAPI::GetFieldAttributes Ex2
        {
            if (!b_Attribute)
            {
                b_Attribute = TRUE;
                pcsaBody->Add("    MutableInt outAttribute = new MutableInt();");
            }
            pcsaBody->Add("    iRet = api.getFieldAttributes(-1,");
            csViewOutStuff.Format("                                  %s,", pcsaArguments->GetAt(1));
            pcsaBody->Add(csViewOutStuff); 
            pcsaBody->Add("                                  outAttribute);");
            pcsaBody->Add("    System.out.println(\"getFieldAttributes: \" + iRet + \" \" + api.getReturnCodeMessage(iRet));");
            pcsaBody->Add("    if(iRet==0)");
            pcsaBody->Add("      System.out.println(\"attribute: \" + outAttribute.getInt());");


        }
        break;

		case 27:	// BridgeAPI::GetFieldAttributes Ex3
                    ////remove this case...it is a duplicate.
        
		case 28:	// BridgeAPI::GetFieldAttributes Ex4
                    ////remove this case...it is a duplicate.

		case 29:	// BridgeAPI::GetFieldCoordinates
        {
            if ( !b_outFieldRs ) 
            {
                b_outFieldRs = TRUE;
                pcsaBody->Add("    MutableInt outFieldRs = new MutableInt();");
            }
            if ( !b_outFieldCs ) 
            {
                b_outFieldCs = TRUE;
                pcsaBody->Add("    MutableInt outFieldCs = new MutableInt();");
            }
            if ( !b_outFieldLs ) 
            {
                b_outFieldLs = TRUE;
                pcsaBody->Add("    MutableObject outFieldLs = new MutableInt();");
            }

            pcsaBody->Add("   iRet = api.getFieldCoordinates(-1,");
            csViewOutStuff.Format("                                %s,", pcsaArguments->GetAt(1));
            pcsaBody->Add(csViewOutStuff);
            pcsaBody->Add("                                  outFieldRs,");
            pcsaBody->Add("                                  outFieldCs,");
            pcsaBody->Add("                                  outFieldLs);");
            pcsaBody->Add("    System.out.println(\"getFieldCoordinates: \" + iRet + \" \" + api.getReturnCodeMessage(iRet));");
            pcsaBody->Add("    if(iRet==0)");
            pcsaBody->Add("      System.out.println(\"field row: \" + outFieldRs.getInt() + \" field column: \" + outFieldCs.getInt()+ \" field length: \" + outFieldLs.getInt());");
        }
        break;

		case 30:	// BridgeAPI::GetFieldCoordinates Ex2
                    ////remove this case...it is a duplicate.


		case 31:	// BridgeAPI::GetFieldCoordinates Ex3
        {
            if ( !b_outFieldRs ) 
            {
                b_outFieldRs = TRUE;
                pcsaBody->Add("    MutableInt outFieldRs = new MutableInt();");
            }
            if ( !b_outFieldCs ) 
            {
                b_outFieldCs = TRUE;
                pcsaBody->Add("    MutableInt outFieldCs = new MutableInt();");
            }
            if ( !b_outFieldLs ) 
            {
                b_outFieldLs = TRUE;
                pcsaBody->Add("    MutableObject outFieldLs = new MutableInt();");
            }

            pcsaBody->Add("   iRet = api.getFieldCoordinates(-1,");
            csViewOutStuff.Format("                                \"%s,\"", pcsaArguments->GetAt(1));
            pcsaBody->Add(csViewOutStuff);
            pcsaBody->Add("                                  outFieldRs,");
            pcsaBody->Add("                                  outFieldCs,");
            pcsaBody->Add("                                  outFieldLs);");
            pcsaBody->Add("    System.out.println(\"getFieldCoordinates: \" + iRet + \" \" + api.getReturnCodeMessage(iRet));");
            pcsaBody->Add("    if(iRet==0)");
            pcsaBody->Add("      System.out.println(\"field row: \" + outFieldRs.getInt() + \" field column: \" + outFieldCs.getInt()+ \" field length: \" + outFieldLs.getInt());");
        }

		case 32:	// BridgeAPI::GetFieldCoordinates Ex4
                    ////remove this case...it is a duplicate.


		case 33:	// BridgeAPI::GetFieldCount
        {
            if ( !b_outFieldCount ) 
            {
                b_outFieldCount = TRUE;
                pcsaBody->Add("    MutableInt outFieldCount = new MutableInt();");
            }
            pcsaBody->Add("    iRet = api.getFieldCount(-1, outFieldCount);");
            pcsaBody->Add("    System.out.println(\"getFieldCount: \" + iRet + \" \" + api.getReturnCodeMessage(iRet));");
            pcsaBody->Add("    if(iRet==0)");
            pcsaBody->Add("      System.out.println(\"field count: \" + outFieldCount.getInt() );");
        }
        break;

		case 34:	// BridgeAPI::GetFieldCount Ex
                    ////remove this case...it is a duplicate.



		case 35:	// BridgeAPI::GetFieldNameFromIndex
        {
            if ( !b_outFieldN ) 
            {
                b_outFieldN = TRUE;
                pcsaBody->Add("    MutableObject outFieldName = new MutableObject();");
            }
            csViewOutStuff.Format("    iRet = api.getFieldNameFromIndex(-1, %s,", pcsaArguments->GetAt(1));
            pcsaBody->Add(csViewOutStuff);
            csViewOutStuff.Format("                                       outFieldName);");
            pcsaBody->Add(csViewOutStuff);
             
            pcsaBody->Add("    System.out.println(\"getFieldNameFromIndex: \" + iRet + \" \" + api.getReturnCodeMessage(iRet));");
            pcsaBody->Add("    if(iRet==0)");
            pcsaBody->Add("      System.out.println(\"field name: \" + outFieldName.toString() );");
        }
        break;


		case 36:	// BridgeAPI::GetFieldNameFromIndex Ex
                    ////remove this case...it is a duplicate.



		case 37:	// BridgeAPI::GetFieldValue
        {
            if ( !b_outFieldVal ) 
            {
                b_outFieldVal = TRUE;
                pcsaBody->Add("    MutableObject outFieldVal = new MutableObject();");
            }
            csViewOutStuff.Format("    iRet = api.getFieldValue(-1, \"%s\",", pcsaArguments->GetAt(1));
            pcsaBody->Add(csViewOutStuff);
            csViewOutStuff.Format("                                 outFieldVal);");
            pcsaBody->Add(csViewOutStuff);
             
            pcsaBody->Add("    System.out.println(\"getFieldValue: \" + iRet + \" \" + api.getReturnCodeMessage(iRet));");
            pcsaBody->Add("    if(iRet==0)");
            pcsaBody->Add("      System.out.println(\"field value: \" + outFieldVal.toString() );");

        }
        break;

		case 38:	// BridgeAPI::GetFieldValue Ex2
        {
            if ( !b_outFieldVal ) 
            {
                b_outFieldVal = TRUE;
                pcsaBody->Add("    MutableObject outFieldVal = new MutableObject();");
            }
            csViewOutStuff.Format("    iRet = api.getFieldValue(-1, %s,", pcsaArguments->GetAt(1));
            pcsaBody->Add(csViewOutStuff);
            csViewOutStuff.Format("                                outFieldVal);");
            pcsaBody->Add(csViewOutStuff);
             
            pcsaBody->Add("    System.out.println(\"getFieldValue: \" + iRet + \" \" + api.getReturnCodeMessage(iRet));");
            pcsaBody->Add("    if(iRet==0)");
            pcsaBody->Add("      System.out.println(\"field value: \" + outFieldVal.toString() );");

        }
        break;

		case 39:	// BridgeAPI::GetFieldValue Ex3
                    ////remove this case...it is a duplicate.


		case 40:	// BridgeAPI::GetFieldValue Ex4
                    ////remove this case...it is a duplicate.


		
        
        case 41:	// BridgeAPI::getReturnCodeMessage
        {
            csViewOutStuff.Format("    System.out.println(api.getReturnCodeMessage(%s));",  pcsaArguments->GetAt(1));
            pcsaBody->Add(csViewOutStuff);
        }
        break;

		case 42:	// BridgeAPI::GetScreenSize
                    ////remove this case...it is a duplicate.
        

		case 43:	// BridgeAPI::GetScreenSize Ex
         {
            if( !b_outRow )
            {
                b_outRow = TRUE;
                pcsaBody->Add("    MutableInt outRow = new MutableInt();");
            }
             if( !b_outColumn )
            {
                b_outColumn = TRUE;
                pcsaBody->Add("    MutableInt outColumn = new MutableInt();");
            }
            pcsaBody->Add("    iRet = api.getScreenSize(-1, outRow, outColumn);");
            pcsaBody->Add("    System.out.println(\"getScreenSize: \" + iRet + \" \" + api.getReturnCodeMessage(iRet));");
            pcsaBody->Add("    if(iRet==0)");
            pcsaBody->Add("      System.out.println(\"rows: \" + outRow.getInt() + \"columns: \" + outColumn.getInt() );");

        }
        break;

		case 44:	// BridgeAPI::GetString
        {
            if (!b_outText)
            {
                b_outText = TRUE;
                pcsaBody->Add("    MutableObject outText = new MutableObject();");
            }
            csViewOutStuff.Format("    iRet = api.getString(-1, %s,", pcsaArguments->GetAt(1));
            pcsaBody->Add(csViewOutStuff);
            csViewOutStuff.Format("                             %s,", pcsaArguments->GetAt(2));
            pcsaBody->Add(csViewOutStuff);
            csViewOutStuff.Format("                             %s,", pcsaArguments->GetAt(3));
            pcsaBody->Add(csViewOutStuff);
            pcsaBody->Add("                              outText);");

            pcsaBody->Add("    System.out.println(\"getString: \" + iRet + \" \" + api.getReturnCodeMessage(iRet));");
            pcsaBody->Add("    if(iRet==0)");
            pcsaBody->Add("      System.out.println(\"string: \" + outText.toString());");
        }
        break;

		case 45:	// BridgeAPI::GetString Ex
                    ////remove this case...it is a duplicate.


		case 46:	// BridgeAPI::GetTransactionSystemId
        {
            if(!b_outSystemID)
            {
                b_outSystemID = TRUE;
                pcsaBody->Add("    MutableObject outSystemID = new MutableObject();");
            }
            csViewOutStuff.Format("    iRet = api.getTransactionSystemID( \"%s\",", pcsaArguments->GetAt(1));
            pcsaBody->Add(csViewOutStuff);
            csViewOutStuff.Format("                                      %s,", pcsaArguments->GetAt(2));
            pcsaBody->Add(csViewOutStuff);
            csViewOutStuff.Format("                                      \"%s\",", pcsaArguments->GetAt(3));
            pcsaBody->Add(csViewOutStuff);
            pcsaBody->Add("                                    outSystemID);");

            pcsaBody->Add("    System.out.println(\"getTransactionSystemID: \" + iRet + \" \" + api.getReturnCodeMessage(iRet));");
            pcsaBody->Add("    if(iRet==0)");
            pcsaBody->Add("      System.out.println(\"ID: \" + outSystemID.toString());");

        }
        break;

		case 47:	// BridgeAPI::PutString
        {
            if(!b_outNumChars)
            {
                b_outNumChars = TRUE;
                pcsaBody->Add("    MutableInt outNumChars = new MutableInt();");
            }
            csViewOutStuff.Format("    iRet = api.putString( \"%s\",", pcsaArguments->GetAt(1));
            pcsaBody->Add(csViewOutStuff);
            csViewOutStuff.Format("                           %s,", pcsaArguments->GetAt(2));
            pcsaBody->Add(csViewOutStuff);
            csViewOutStuff.Format("                           %s,", pcsaArguments->GetAt(3));
            pcsaBody->Add(csViewOutStuff);
            pcsaBody->Add("                            outNumChars);");

            pcsaBody->Add("    System.out.println(\"putString: \" + iRet + \" \" + api.getReturnCodeMessage(iRet));");
            pcsaBody->Add("    if(iRet==0)");
            pcsaBody->Add("      System.out.println(\"characters put: \" + outNumChars.getInt());");
        }
        break;

		case 48:	// BridgeAPI::SendKeys
        {
            csViewOutStuff.Format("    iRet = api.sendKeys( \"%s\",", pcsaArguments->GetAt(1));
            pcsaBody->Add(csViewOutStuff);
            pcsaBody->Add("    System.out.println(\"sendKeys: \" + iRet + \" \" + api.getReturnCodeMessage(iRet));");
        }
        break;

		case 49:	// BridgeAPI::SendKeysEx
                    ////remove this case...it is a duplicate.
                    

		case 50:	// BridgeAPI::SendKeysGetAllFieldInformation
        {
            if ( !b_outFieldCount ) 
            {
                b_outFieldCount = TRUE;
                pcsaBody->Add("    MutableInt outFieldCount = new MutableInt();");
            }
            if ( !b_outFieldNames ) 
            {
                b_outFieldNames = TRUE;
                pcsaBody->Add("    MutableObject outFieldNames = new MutableObject();");
            }
            if ( !b_outFieldValues ) 
            {
                b_outFieldValues = TRUE;
                pcsaBody->Add("    MutableObject outFieldValues = new MutableObject();");
            }
            if ( !b_outFieldAttributes ) 
            {
                b_outFieldAttributes = TRUE;
                pcsaBody->Add("    MutableObject outFieldAttributes = new MutableObject();");
            }
            if ( !b_outFieldRows ) 
            {
                b_outFieldRows = TRUE;
                pcsaBody->Add("    MutableObject outFieldRows = new MutableObject();");
            }
            if ( !b_outFieldCols ) 
            {
                b_outFieldCols = TRUE;
                pcsaBody->Add("    MutableObject outFieldCols = new MutableObject();");
            }
            if ( !b_outFieldLengths ) 
            {
                b_outFieldLengths = TRUE;
                pcsaBody->Add("    MutableObject outFieldLengths = new MutableObject();");
            }
            if ( !b_outFieldColors ) 
            {
                b_outFieldColors = TRUE;
                pcsaBody->Add("    MutableObject outFieldColors = new MutableObject();");
            }
            if ( !b_outFieldHighlights ) 
            {
                b_outFieldHighlights = TRUE;
                pcsaBody->Add("    MutableObject outFieldHighlights = new MutableObject();");
            }
            pcsaBody->Add(" ");
            csViewOutStuff.Format("   iRet = api.sendKeysGetAllFieldInformation(\"%s\", outFieldCount, outFieldNames, outFieldValues, outFieldAttributes,", pcsaArguments->GetAt(1));
            pcsaBody->Add(csViewOutStuff);
            pcsaBody->Add("         outFieldRows, outFieldCols, outFieldLengths, outFieldColors, outFieldHighlights);");  
            pcsaBody->Add(" ");
            pcsaBody->Add("    System.out.println(\"sendKeysGetAllFieldInformation: \" + iRet + \" \" + api.getReturnCodeMessage(iRet));");
            pcsaBody->Add("    if(iRet == 0){");
            pcsaBody->Add("      System.out.println(\"total fields this screen: \" + outFieldCount.getInt());");
            pcsaBody->Add("      for (int i=0; i<outFieldCount; i++){");
            pcsaBody->Add("        System.out.println(\"name: \" + outFieldNames[i] + \" attribute: \" + outFieldAttributes[i] + \" length: \" + outFieldLengths[i]);");
            pcsaBody->Add("        System.out.println(\"row: \" + outFieldRows[i] + \" column: \" + outFieldCols[i] + \" color: \" + outFieldColors[i] + \" highlight: \" + outFieldHighlights[i]);");
            pcsaBody->Add("        System.out.println(\"value: \" + outFieldValues[i] + \"\\n\");");
            pcsaBody->Add("      }");
            pcsaBody->Add("    }");


        }
        break;

		case 51:	// BridgeAPI::SendKeysGetString
        {
            if(!b_outText)
            {
                b_outText = TRUE;
                pcsaBody->Add("    MutableObject outText = new MutableObject();");
            }
            csViewOutStuff.Format("    iRet = api.sendKeysGetString( \"%s\",", pcsaArguments->GetAt(1));
            pcsaBody->Add(csViewOutStuff);
            csViewOutStuff.Format("                           %s,", pcsaArguments->GetAt(2));
            pcsaBody->Add(csViewOutStuff);
            csViewOutStuff.Format("                           %s,", pcsaArguments->GetAt(3));
            pcsaBody->Add(csViewOutStuff);
            csViewOutStuff.Format("                           %s,", pcsaArguments->GetAt(4));
            pcsaBody->Add(csViewOutStuff);
            pcsaBody->Add("                            outText);");

            pcsaBody->Add("    System.out.println(\"sendKeysGetString: \" + iRet + \" \" + api.getReturnCodeMessage(iRet));");
            pcsaBody->Add("    if(iRet==0)");
            pcsaBody->Add("      System.out.println(\"string: \" + outText.toString());");
        }
        break;

		case 52:	// BridgeAPI::SetCursorPosition
        {
            csViewOutStuff.Format("    iRet = api.setCursorPosition(-1, %s,", pcsaArguments->GetAt(1));
            pcsaBody->Add(csViewOutStuff);
            csViewOutStuff.Format("                             %s);", pcsaArguments->GetAt(2));
            pcsaBody->Add(csViewOutStuff);
            pcsaBody->Add("    System.out.println(\"setCursorPosition: \" + iRet + \" \" + api.getReturnCodeMessage(iRet));");
        }
        break;

		case 53:	// BridgeAPI::SetFieldValue
        {
            csViewOutStuff.Format("    iRet = api.setFieldValue(\"%s\",", pcsaArguments->GetAt(1));
            pcsaBody->Add(csViewOutStuff);
            csViewOutStuff.Format("                             \"%s\");", pcsaArguments->GetAt(2));
            pcsaBody->Add(csViewOutStuff);
            pcsaBody->Add("    System.out.println(\"setFieldValue: \" + iRet + \" \" + api.getReturnCodeMessage(iRet));");
        }
        break;

		case 54:	// BridgeAPI::SetFieldValue Ex2
         {
            csViewOutStuff.Format("    iRet = api.setFieldValue(%s,", pcsaArguments->GetAt(1));
            pcsaBody->Add(csViewOutStuff);
            csViewOutStuff.Format("                             \"%s\");", pcsaArguments->GetAt(2));
            pcsaBody->Add(csViewOutStuff);
            pcsaBody->Add("    System.out.println(\"setFieldValue: \" + iRet + \" \" + api.getReturnCodeMessage(iRet));");
        }


		case 55:	// BridgeAPI::SetFieldValue Ex3
        {
            
//REMOVE UI FOR ARGS FOR THIS CASE - THEY ARE ARRAYS, NOT SIMPLE STRINGS

            pcsaBody->Add("    //TO DO: Initialize arrays, for example:");
            pcsaBody->Add("    //MutableObject inFieldNamesArray = (MutableObject) new String[] {\"firstfieldname\", \"secondfieldname\"};");
            pcsaBody->Add("    //MutableObject inFieldValuesArray = (MutableObject) new String[] {\"firstfieldvalue\", \"secondfieldvalue\"};");
            pcsaBody->Add(" ");
            pcsaBody->Add("    //iRet = api.setFieldValue(inFieldNamesArray, inFieldValuesArray);");
            pcsaBody->Add("    //System.out.println(\"setFieldValue: \" + iRet + \" \" + api.getReturnCodeMessage(iRet));");

        }
        break;

		case 56:	// BridgeAPI::SetSettleTime
                    ////remove this case


		case 57:	// BridgeAPI::SetTimeOut
                    ////remove this case


		case 58:	// BridgeAPI::SetTraceActive
        {
            csViewOutStuff.Format("    iRet = api.setTraceActive( \"%s\");", pcsaArguments->GetAt(1));
            pcsaBody->Add(csViewOutStuff);
            pcsaBody->Add("    System.out.println(\"setTraceActive: \" + iRet + \" \" + api.getReturnCodeMessage(iRet));");
        }
        break;

		case 59:	// BridgeAPI::SetTraceInactive
        {
            csViewOutStuff.Format("    iRet = api.setTraceInactive();");
            pcsaBody->Add(csViewOutStuff);
            pcsaBody->Add("    System.out.println(\"setTraceInactive: \" + iRet + \" \" + api.getReturnCodeMessage(iRet));");
        }

		case 60:	// BridgeAPI::SetTraceName
        {
            csViewOutStuff.Format("    iRet = api.setTraceName( \"%s\");", pcsaArguments->GetAt(1));
            pcsaBody->Add(csViewOutStuff);
            pcsaBody->Add("    System.out.println(\"setTraceName: \" + iRet + \" \" + api.getReturnCodeMessage(iRet));");
        }

		case 61:	// BridgeAPI::Terminate
                    ////remove this case


//hmmmm....looks like we will need the ejb version after all...

		case 62:	// BridgeAPI_EJB::changePassword
		case 63:	// BridgeAPI_EJB::connectBridge
		case 64:	// BridgeAPI_EJB::connectBridge Ex2
		case 65:	// BridgeAPI_EJB::connectBridge Ex3
		case 66:	// BridgeAPI_EJB::connectBridge Ex4
		case 67:	// BridgeAPI_EJB::disconnect
		case 68:	// BridgeAPI_EJB::findString
		case 69:	// BridgeAPI_EJB::findString Ex
		case 70:	// BridgeAPI_EJB::getAllFieldInformation
		case 71:	// BridgeAPI_EJB::getAllFieldInformation Ex
		case 72:	// BridgeAPI_EJB::getConnectionStatus
		case 73:	// BridgeAPI_EJB::getCurrentScreenName
		case 74:	// BridgeAPI_EJB::getCursorPosition
		case 75:	// BridgeAPI_EJB::getFieldAttributes
		case 76:	// BridgeAPI_EJB::getFieldAttributes Ex2
		case 77:	// BridgeAPI_EJB::getFieldAttributes Ex3
		case 78:	// BridgeAPI_EJB::getFieldAttributes Ex4
		case 79:	// BridgeAPI_EJB::getFieldCoordinates
		case 80:	// BridgeAPI_EJB::getFieldCoordinates Ex2
		case 81:	// BridgeAPI_EJB::getFieldCoordinates Ex3
		case 82:	// BridgeAPI_EJB::getFieldCoordinates Ex4
		case 83:	// BridgeAPI_EJB::getFieldCount
		case 84:	// BridgeAPI_EJB::getFieldCount Ex
		case 85:	// BridgeAPI_EJB::getFieldNameFromIndex
		case 86:	// BridgeAPI_EJB::getFieldNameFromIndex Ex
		case 87:	// BridgeAPI_EJB::getFieldValue
		case 88:	// BridgeAPI_EJB::getFieldValue Ex2
		case 89:	// BridgeAPI_EJB::getFieldValue Ex3
		case 90:	// BridgeAPI_EJB::getFieldValue Ex4
		case 91:	// BridgeAPI_EJB::getReturnCodeMessage
		case 92:	// BridgeAPI_EJB::getScreenSize
		case 93:	// BridgeAPI_EJB::getScreenSize Ex
		case 94:	// BridgeAPI_EJB::getString
		case 95:	// BridgeAPI_EJB::getString Ex
		case 96:	// BridgeAPI_EJB::getTransactionSystemId
		case 97:	// BridgeAPI_EJB::putString
		case 98:	// BridgeAPI_EJB::sendKeys
		case 99:	// BridgeAPI_EJB::sendKeysEx
		case 100:	// BridgeAPI_EJB::sendKeysGetAllFieldInformation
		case 101:	// BridgeAPI_EJB::sendKeysGetString
		case 102:	// BridgeAPI_EJB::setCursorPosition
		case 103:	// BridgeAPI_EJB::setFieldValue
		case 104:	// BridgeAPI_EJB::setFieldValue Ex2
		case 105:	// BridgeAPI_EJB::setFieldValue Ex3
		case 106:	// BridgeAPI_EJB::setSettleTime
		case 107:	// BridgeAPI_EJB::setTimeOut
		case 108:	// BridgeAPI_EJB::setTraceActive
		case 109:	// BridgeAPI_EJB::setTraceInactive
		case 110:	// BridgeAPI_EJB::setTraceName
		case 111:	// BridgeAPI_EJB::terminate

//remove the rest:
		case 112:	// ConnectionStatus::getReturnCode
		case 113:	// ConnectionStatus::getStatus
		case 114:	// CurrentScreenName::getReturnCode
		case 115:	// CurrentScreenName::getScreenName
		case 116:	// CursorPosition::getColumn
		case 117:	// CursorPosition::getReturnCode
		case 118:	// CursorPosition::getRow
		case 119:	// FieldAttributes::getAttributes
		case 120:	// FieldAttributes::getReturnCode
		case 121:	// FieldCoordinates::getFieldColumn
		case 122:	// FieldCoordinates::getFieldLength
		case 123:	// FieldCoordinates::getFieldRow
		case 124:	// FieldCoordinates::getReturnCode
		case 125:	// FieldCount::getFieldCount
		case 126:	// FieldCount::getReturnCode
		case 127:	// FieldName::getFieldName
		case 128:	// FieldName::getReturnCode
		case 129:	// FieldValue::getReturnCode
		case 130:	// FieldValue::getValue
		case 131:	// FindString::getColumn
		case 132:	// FindString::getReturnCode
		case 133:	// FindString::getRow
		case 134:	// GetString::getReturnCode
		case 135:	// GetString::getText
		case 136:	// PutString::getNumChars
		case 137:	// PutString::getReturnCode
		case 138:	// ScreenSize::getColumns
		case 139:	// ScreenSize::getReturnCode
		case 140:	// ScreenSize::getRows
		case 141:	// TransactionSystemid::getReturnCode
		case 142:	// TransactionSystemid::getSystemId
		{
			csViewOutStuff.Format( "   // APIGen has not yet implemented this method." );
			pcsaBody->Add(csViewOutStuff);
		}
	}

	pcsaArguments->RemoveAll();
}

void CAG_CICS20_QACOM_JAVA_J::finalize(CStringArray* pcsaBody)
{
    pcsaBody->Add(" ");
    pcsaBody->Add("  }catch(Exception e){System.out.println(\"EXCEPTION: \" + e.printStackTrace());}");   
    pcsaBody->Add("  }   //end of main");
    pcsaBody->Add("}     //end of class");
}

void CAG_CICS20_QACOM_JAVA_J::loadFunctionList(CListBox* listTranslateFunction)
{
	listTranslateFunction->ResetContent();
//don't need AllFieldInformation//////////////
	csaFunctions.Add( "AllFieldInformation::getFieldAttributes" );
	csaFunctions.Add( "AllFieldInformation::getFieldColors" );
	csaFunctions.Add( "AllFieldInformation::getFieldCols" );
	csaFunctions.Add( "AllFieldInformation::getFieldCount" );
	csaFunctions.Add( "AllFieldInformation::getFieldHighlights" );
	csaFunctions.Add( "AllFieldInformation::getFieldLengths" );
	csaFunctions.Add( "AllFieldInformation::getFieldNames" );
	csaFunctions.Add( "AllFieldInformation::getFieldRows" );
	csaFunctions.Add( "AllFieldInformation::getFieldValues" );
	csaFunctions.Add( "AllFieldInformation::getReturnCode" );
////////////////////////////////////////////////
//Remove indicated functions from list...

	csaFunctions.Add( "BridgeAPI::changePassword" );
	csaFunctions.Add( "BridgeAPI::connectBridge" );
	csaFunctions.Add( "BridgeAPI::connectBridge Ex2" );
	csaFunctions.Add( "BridgeAPI::connectBridge Ex3" );
	csaFunctions.Add( "BridgeAPI::connectBridge Ex4" );
	csaFunctions.Add( "BridgeAPI::disconnect" );
	csaFunctions.Add( "BridgeAPI::findString" );
	csaFunctions.Add( "BridgeAPI::findString Ex" );
	csaFunctions.Add( "BridgeAPI::getAllFieldInformation" );
	csaFunctions.Add( "BridgeAPI::getAllFieldInformation Ex2" );  //REMOVE
	csaFunctions.Add( "BridgeAPI::getAllFieldInformation Ex3" );
	csaFunctions.Add( "BridgeAPI::getAllFieldInformation Ex4" );  //REMOVE
	csaFunctions.Add( "BridgeAPI::getConnectionStatus" );
	csaFunctions.Add( "BridgeAPI::getCurrentScreenName" );
	csaFunctions.Add( "BridgeAPI::getCursorPosition" );
	csaFunctions.Add( "BridgeAPI::getFieldAttributes" );
	csaFunctions.Add( "BridgeAPI::getFieldAttributes Ex2" );
	csaFunctions.Add( "BridgeAPI::getFieldAttributes Ex3" );  //REMOVE
	csaFunctions.Add( "BridgeAPI::getFieldAttributes Ex4" );  //REMOVE
	csaFunctions.Add( "BridgeAPI::getFieldCoordinates" );
	csaFunctions.Add( "BridgeAPI::getFieldCoordinates Ex2" );
	csaFunctions.Add( "BridgeAPI::getFieldCoordinates Ex3" ); //REMOVE
	csaFunctions.Add( "BridgeAPI::getFieldCoordinates Ex4" ); //REMOVE
	csaFunctions.Add( "BridgeAPI::getFieldCount" );
	csaFunctions.Add( "BridgeAPI::getFieldCount Ex" );  //REMOVE
	csaFunctions.Add( "BridgeAPI::getFieldNameFromIndex" );
	csaFunctions.Add( "BridgeAPI::getFieldNameFromIndex Ex" ); //REMOVE
	csaFunctions.Add( "BridgeAPI::getFieldValue" );
	csaFunctions.Add( "BridgeAPI::getFieldValue Ex2" );  
	csaFunctions.Add( "BridgeAPI::getFieldValue Ex3" );  //REMOVE
	csaFunctions.Add( "BridgeAPI::getFieldValue Ex4" );  //REMOVE
	csaFunctions.Add( "BridgeAPI::getReturnCodeMessage" );
	csaFunctions.Add( "BridgeAPI::getScreenSize" );
	csaFunctions.Add( "BridgeAPI::getScreenSize Ex" );  //REMOVE
	csaFunctions.Add( "BridgeAPI::getString" );
	csaFunctions.Add( "BridgeAPI::getString Ex" );  //REMOVE
	csaFunctions.Add( "BridgeAPI::getTransactionSystemId" );
	csaFunctions.Add( "BridgeAPI::putString" );
	csaFunctions.Add( "BridgeAPI::sendKeys" );
	csaFunctions.Add( "BridgeAPI::sendKeysEx" );  //REMOVE
	csaFunctions.Add( "BridgeAPI::sendKeysGetAllFieldInformation" );
	csaFunctions.Add( "BridgeAPI::sendKeysGetString" );
	csaFunctions.Add( "BridgeAPI::setCursorPosition" );
	csaFunctions.Add( "BridgeAPI::setFieldValue" );
	csaFunctions.Add( "BridgeAPI::setFieldValue Ex2" );
	csaFunctions.Add( "BridgeAPI::setFieldValue Ex3" );
	csaFunctions.Add( "BridgeAPI::setSettleTime" );  //REMOVE
	csaFunctions.Add( "BridgeAPI::setTimeOut" );  //REMOVE
	csaFunctions.Add( "BridgeAPI::setTraceActive" );
	csaFunctions.Add( "BridgeAPI::setTraceInactive" );
	csaFunctions.Add( "BridgeAPI::setTraceName" );
	csaFunctions.Add( "BridgeAPI::terminate" );  //REMOVE

	csaFunctions.Add( "BridgeAPI_EJB::changePassword" );
	csaFunctions.Add( "BridgeAPI_EJB::connectBridge" );
	csaFunctions.Add( "BridgeAPI_EJB::connectBridge Ex2" );
	csaFunctions.Add( "BridgeAPI_EJB::connectBridge Ex3" );
	csaFunctions.Add( "BridgeAPI_EJB::connectBridge Ex4" );
	csaFunctions.Add( "BridgeAPI_EJB::disconnect" );
	csaFunctions.Add( "BridgeAPI_EJB::findString" );
	csaFunctions.Add( "BridgeAPI_EJB::findString Ex" );
	csaFunctions.Add( "BridgeAPI_EJB::getAllFieldInformation" );
	csaFunctions.Add( "BridgeAPI_EJB::getAllFieldInformation Ex" );
	csaFunctions.Add( "BridgeAPI_EJB::getConnectionStatus" );
	csaFunctions.Add( "BridgeAPI_EJB::getCurrentScreenName" );
	csaFunctions.Add( "BridgeAPI_EJB::getCursorPosition" );
	csaFunctions.Add( "BridgeAPI_EJB::getFieldAttributes" );
	csaFunctions.Add( "BridgeAPI_EJB::getFieldAttributes Ex2" );
	csaFunctions.Add( "BridgeAPI_EJB::getFieldAttributes Ex3" );
	csaFunctions.Add( "BridgeAPI_EJB::getFieldAttributes Ex4" );
	csaFunctions.Add( "BridgeAPI_EJB::getFieldCoordinates" );
	csaFunctions.Add( "BridgeAPI_EJB::getFieldCoordinates Ex2" );
	csaFunctions.Add( "BridgeAPI_EJB::getFieldCoordinates Ex3" );
	csaFunctions.Add( "BridgeAPI_EJB::getFieldCoordinates Ex4" );
	csaFunctions.Add( "BridgeAPI_EJB::getFieldCount" );
	csaFunctions.Add( "BridgeAPI_EJB::getFieldCount Ex" );
	csaFunctions.Add( "BridgeAPI_EJB::getFieldNameFromIndex" );
	csaFunctions.Add( "BridgeAPI_EJB::getFieldNameFromIndex Ex" );
	csaFunctions.Add( "BridgeAPI_EJB::getFieldValue" );
	csaFunctions.Add( "BridgeAPI_EJB::getFieldValue Ex2" );
	csaFunctions.Add( "BridgeAPI_EJB::getFieldValue Ex3" );
	csaFunctions.Add( "BridgeAPI_EJB::getFieldValue Ex4" );
	csaFunctions.Add( "BridgeAPI_EJB::getReturnCodeMessage" );
	csaFunctions.Add( "BridgeAPI_EJB::getScreenSize" );
	csaFunctions.Add( "BridgeAPI_EJB::getScreenSize Ex" );
	csaFunctions.Add( "BridgeAPI_EJB::getString" );
	csaFunctions.Add( "BridgeAPI_EJB::getString Ex" );
	csaFunctions.Add( "BridgeAPI_EJB::getTransactionSystemId" );
	csaFunctions.Add( "BridgeAPI_EJB::putString" );
	csaFunctions.Add( "BridgeAPI_EJB::sendKeys" );
	csaFunctions.Add( "BridgeAPI_EJB::sendKeysEx" );
	csaFunctions.Add( "BridgeAPI_EJB::sendKeysGetAllFieldInformation" );
	csaFunctions.Add( "BridgeAPI_EJB::sendKeysGetString" );
	csaFunctions.Add( "BridgeAPI_EJB::setCursorPosition" );
	csaFunctions.Add( "BridgeAPI_EJB::setFieldValue" );
	csaFunctions.Add( "BridgeAPI_EJB::setFieldValue Ex2" );
	csaFunctions.Add( "BridgeAPI_EJB::setFieldValue Ex3" );
	csaFunctions.Add( "BridgeAPI_EJB::setSettleTime" );  
	csaFunctions.Add( "BridgeAPI_EJB::setTimeOut" );  
	csaFunctions.Add( "BridgeAPI_EJB::setTraceActive" );
	csaFunctions.Add( "BridgeAPI_EJB::setTraceInactive" );
	csaFunctions.Add( "BridgeAPI_EJB::setTraceName" );
	csaFunctions.Add( "BridgeAPI_EJB::terminate" );  

//don't need these....
/*
	csaFunctions.Add( "ConnectionStatus::getReturnCode" );
	csaFunctions.Add( "ConnectionStatus::getStatus" );
	csaFunctions.Add( "CurrentScreenName::getReturnCode" );
	csaFunctions.Add( "CurrentScreenName::getScreenName" );
	csaFunctions.Add( "CursorPosition::getColumn" );
	csaFunctions.Add( "CursorPosition::getReturnCode" );
	csaFunctions.Add( "CursorPosition::getRow" );
	csaFunctions.Add( "FieldAttributes::getAttributes" );

	csaFunctions.Add( "FieldAttributes::getReturnCode" );
	csaFunctions.Add( "FieldCoordinates::getFieldColumn" );
	csaFunctions.Add( "FieldCoordinates::getFieldLength" );
	csaFunctions.Add( "FieldCoordinates::getFieldRow" );
	csaFunctions.Add( "FieldCoordinates::getReturnCode" );
	csaFunctions.Add( "FieldCount::getFieldCount" );
	csaFunctions.Add( "FieldCount::getReturnCode" );
	csaFunctions.Add( "FieldName::getFieldName" );
	csaFunctions.Add( "FieldName::getReturnCode" );
	csaFunctions.Add( "FieldValue::getReturnCode" );
	csaFunctions.Add( "FieldValue::getValue" );
	csaFunctions.Add( "FindString::getColumn" );
	csaFunctions.Add( "FindString::getReturnCode" );
	csaFunctions.Add( "FindString::getRow" );
	csaFunctions.Add( "GetString::getReturnCode" );
	csaFunctions.Add( "GetString::getText" );
	csaFunctions.Add( "PutString::getNumChars" );
	csaFunctions.Add( "PutString::getReturnCode" );
	csaFunctions.Add( "ScreenSize::getColumns" );
	csaFunctions.Add( "ScreenSize::getReturnCode" );

	csaFunctions.Add( "ScreenSize::getRows" );
	csaFunctions.Add( "TransactionSystemid::getReturnCode" );
	csaFunctions.Add( "TransactionSystemid::getSystemId" );
*/
	listTranslateFunction->ResetContent();	
	
	for (int k=0; k<csaFunctions.GetSize(); k++)
	{
		listTranslateFunction->AddString( csaFunctions.GetAt(k) );
	}

	listTranslateFunction->SetCurSel(0);
	
}


void CAG_CICS20_QACOM_JAVA_J::resetVariableFlags()
{
    b_FindString = FALSE;
    b_outRow = FALSE;
    b_outColumn = FALSE;
    b_outFieldCount = FALSE;
    b_outFieldNames = FALSE;
    b_outFieldValues = FALSE;
    b_outFieldAttributes = FALSE;
    b_outFieldRows = FALSE;
    b_outFieldCols = FALSE;
    b_outFieldLengths = FALSE;
    b_outFieldColors = FALSE;
    b_outFieldHighlights = FALSE;
    b_outStatus = FALSE;
    b_outScreenName = FALSE;
    b_Attribute = FALSE;
    b_outFieldRs = FALSE;
    b_outFieldCs = FALSE;
    b_outFieldLs = FALSE;
    b_outFieldN = FALSE;
    b_outFieldVal = FALSE;
    b_outText = FALSE;
    b_outNumChars = FALSE;
    b_outSystemID = FALSE;
    
}