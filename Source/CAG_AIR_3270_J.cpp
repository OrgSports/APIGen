// Static Model
#include "stdafx.h"
#include "apigen.h"

#include "CAG_AIR_3270_J.h"



CAG_AIR_3270_J::CAG_AIR_3270_J()
{
	APIFlavor = AIRJ_API;	
}

CAG_AIR_3270_J::~CAG_AIR_3270_J()
{
	
}

void CAG_AIR_3270_J::generateHeader(CStringArray* pcsaHeader,
									CStringArray* pcsaBody)
{
	// name and open output file if specified
	SYSTEMTIME	systime;
	GetSystemTime(&systime);
	time_t osBinaryTime;
	time( &osBinaryTime ) ;
	CTime t( osBinaryTime );
	
	int nMonth = t.GetMonth();
	int nDay = t.GetDay();
	int nYear = t.GetYear();

	// output to Translator's output window
	CString csViewOutStuff;
	csViewOutStuff.Format( "%s", "// ****************************************************************************");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "//             Attachmate APIGen Airlines SDK 3270 Java Application");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "//");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "//   When compiled, this becomes a freestanding Java program that contains a list");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "//    of Airlines SDK 3270 Applet Java method calls specified to the APIGen code");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "//    generator.");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "//");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "//    These conditions must be met before this source file can be used.");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "//       1. Either the class name (Air3270) or the file name must be changed as");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "//          they must be the same.");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "//       2. The Attachmate Airlines SDK must be installed using the keycode for 3270. Its");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "//           class or jar files must be made accessible via the class path.");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "//       3. Depending on where you intend to run the compiled Java program");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "//           you may choose to append your system's CLASSPATH system variable");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "//           with the path to the folder where the class file will run.");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "//       4. You must prepare a 3270 session XML configuration file that the");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "//           generated program can use to configure its connection.");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "//           One example of such a configuration file is 3270.xml which");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "//           is listed below.");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "//           <<stuff>>");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "//           <<stuff>>");
	pcsaHeader->Add(csViewOutStuff);

	time_t ltime;
	time( &ltime );

	csViewOutStuff.Format( "//");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "//   Generated:   %s", ctime( &ltime ) );
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "//");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "// ****************************************************************************");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( " ");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "import com.attachmate.UPG.SessionLoader.*;" );
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "import com.attachmate.UPG.common.*;" );
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "import com.attachmate.UPG.screen.*;" );
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "import com.attachmate.common.types.MutableInt;" );
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "import com.attachmate.emulation.exception.*;" );
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( " ");
	pcsaHeader->Add(csViewOutStuff);
	
 	csViewOutStuff.Format( "public class Air3270 implements IScreenListener");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "{" );
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "   private Panel sessionPanel = null;" );
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( " " );
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( " " );
	pcsaBody->Add(csViewOutStuff);

	csViewOutStuff.Format( "   public static void main(String args[]) throws IOException" );
	pcsaBody->Add(csViewOutStuff);

	csViewOutStuff.Format( "   {" );
	pcsaBody->Add(csViewOutStuff);

	csViewOutStuff.Format( "      Air3270 a3270 = new Air3270();" );
	pcsaBody->Add(csViewOutStuff);

	csViewOutStuff.Format( "      Frame f = new Frame();" );
	pcsaBody->Add(csViewOutStuff);

	csViewOutStuff.Format( "      f.setLayout( new BorderLayout() );" );
	pcsaBody->Add(csViewOutStuff);

	csViewOutStuff.Format( " " );
	pcsaBody->Add(csViewOutStuff);

	csViewOutStuff.Format( "      boolean bRet;" );
	pcsaBody->Add(csViewOutStuff);

	csViewOutStuff.Format( "" );
	pcsaBody->Add(csViewOutStuff);

	csViewOutStuff.Format( "      try" );
	pcsaBody->Add(csViewOutStuff);

	csViewOutStuff.Format( "      {" );
	pcsaBody->Add(csViewOutStuff);

	csViewOutStuff.Format( "           a3270.processHost();" );
	pcsaBody->Add(csViewOutStuff);

	csViewOutStuff.Format( "           Thread.sleep(1000);" );
	pcsaBody->Add(csViewOutStuff);

	csViewOutStuff.Format( "      }" );
	pcsaBody->Add(csViewOutStuff);

	csViewOutStuff.Format( "      catch (Exception e)" );
	pcsaBody->Add(csViewOutStuff);

	csViewOutStuff.Format( "      {" );
	pcsaBody->Add(csViewOutStuff);

	csViewOutStuff.Format( "      System.out.println(e);" );
	pcsaBody->Add(csViewOutStuff);

	csViewOutStuff.Format( "      }" );
	pcsaBody->Add(csViewOutStuff);

	csViewOutStuff.Format( "   }" );
	pcsaBody->Add(csViewOutStuff);

	csViewOutStuff.Format( "" );
	pcsaBody->Add(csViewOutStuff);

	csViewOutStuff.Format( "   private String getXmlConfig()" );
	pcsaBody->Add(csViewOutStuff);

	csViewOutStuff.Format( "   {" );
	pcsaBody->Add(csViewOutStuff);

	csViewOutStuff.Format( "        String strConfig = "";" );
	pcsaBody->Add(csViewOutStuff);

	csViewOutStuff.Format( "        try" );
	pcsaBody->Add(csViewOutStuff);

	csViewOutStuff.Format( "        {" );
	pcsaBody->Add(csViewOutStuff);

	csViewOutStuff.Format( "             //Read XML file for Configuration and Host" );
	pcsaBody->Add(csViewOutStuff);

	csViewOutStuff.Format( "             String line = "";" );
	pcsaBody->Add(csViewOutStuff);

	csViewOutStuff.Format( "             FileInputStream fis = null;" );
	pcsaBody->Add(csViewOutStuff);

	csViewOutStuff.Format( "             fis = new FileInputStream(\"C:\\temp\\3270.xml\");" );
	pcsaBody->Add(csViewOutStuff);

	csViewOutStuff.Format( "             BufferedReader in =  new BufferedReader (new InputStreamReader (fis));" );
	pcsaBody->Add(csViewOutStuff);

	csViewOutStuff.Format( "             while ((line = in.readLine()) != null)" );
	pcsaBody->Add(csViewOutStuff);

	csViewOutStuff.Format( "             {" );
	pcsaBody->Add(csViewOutStuff);

	csViewOutStuff.Format( "                  strConfig += line;" );
	pcsaBody->Add(csViewOutStuff);

	csViewOutStuff.Format( "             }" );
	pcsaBody->Add(csViewOutStuff);

	csViewOutStuff.Format( "   " );
	pcsaBody->Add(csViewOutStuff);

	csViewOutStuff.Format( "        fis.close();" );
	pcsaBody->Add(csViewOutStuff);

	csViewOutStuff.Format( "   }" );
	pcsaBody->Add(csViewOutStuff);

	csViewOutStuff.Format( "   catch (Exception e)" );
	pcsaBody->Add(csViewOutStuff);

	csViewOutStuff.Format( "   {" );
	pcsaBody->Add(csViewOutStuff);

	csViewOutStuff.Format( "        System.out.println(e);" );
	pcsaBody->Add(csViewOutStuff);

	csViewOutStuff.Format( "   }" );
	pcsaBody->Add(csViewOutStuff);

	csViewOutStuff.Format( "   " );
	pcsaBody->Add(csViewOutStuff);

	csViewOutStuff.Format( "   return strConfig;" );
	pcsaBody->Add(csViewOutStuff);

	csViewOutStuff.Format( "   " );
	pcsaBody->Add(csViewOutStuff);

	csViewOutStuff.Format( "   private void processHost()" );
	pcsaBody->Add(csViewOutStuff);

	csViewOutStuff.Format( "   {" );
	pcsaBody->Add(csViewOutStuff);

	csViewOutStuff.Format( "        SessionLoader sl = new SessionLoader();" );
	pcsaBody->Add(csViewOutStuff);

	csViewOutStuff.Format( "        ScreenTn3270 so;" );
	pcsaBody->Add(csViewOutStuff);

	csViewOutStuff.Format( "        String strConfig = getXmlConfig();" );
	pcsaBody->Add(csViewOutStuff);

	csViewOutStuff.Format( "        System.out.println(\"DEBUG:    strConfig = \" + strConfig);" );
	pcsaBody->Add(csViewOutStuff);

	csViewOutStuff.Format( "        try" );
	pcsaBody->Add(csViewOutStuff);

	csViewOutStuff.Format( "        {" );
	pcsaBody->Add(csViewOutStuff);

	csViewOutStuff.Format( "             so = (ScreenTn3270) sl.requestScreenEx(\"\",\"\",strConfig,0);" );
	pcsaBody->Add(csViewOutStuff);

	csViewOutStuff.Format( "             if (!so.Open())" );
	pcsaBody->Add(csViewOutStuff);

	csViewOutStuff.Format( "             {" );
	pcsaBody->Add(csViewOutStuff);

	csViewOutStuff.Format( "                  System.out.println(\"Open Failed on Session \");" );
	pcsaBody->Add(csViewOutStuff);

	csViewOutStuff.Format( "             }" );
	pcsaBody->Add(csViewOutStuff);

	csViewOutStuff.Format( "             else" );
	pcsaBody->Add(csViewOutStuff);

	csViewOutStuff.Format( "             {" );
	pcsaBody->Add(csViewOutStuff);

	csViewOutStuff.Format( "                  so.waitHostQuiet(3000,6000);" );
	pcsaBody->Add(csViewOutStuff);

	csViewOutStuff.Format( "                  so.setgetText_Display(true);" );
	pcsaBody->Add(csViewOutStuff);

	csViewOutStuff.Format( "                  so.getText();" );
	pcsaBody->Add(csViewOutStuff);

	csViewOutStuff.Format( "                  so.Close();" );
	pcsaBody->Add(csViewOutStuff);

	csViewOutStuff.Format( "                  System.out.println(\"System closed\");" );
	pcsaBody->Add(csViewOutStuff);

	csViewOutStuff.Format( "                  System.out.println(\"Sleeping...\");" );
	pcsaBody->Add(csViewOutStuff);

	csViewOutStuff.Format( "                  Thread.sleep(5000);" );
	pcsaBody->Add(csViewOutStuff);

	csViewOutStuff.Format( "                  System.out.println(\"isConnected: \" + so.isConnected());" );
	pcsaBody->Add(csViewOutStuff);


}

void CAG_AIR_3270_J::appendBody(int nFunctionNum,
								bool bPromptForValues,
								CStringArray* pcsaArguments,
								CStringArray* pcsaHeader,
								CStringArray* pcsaBody)
{}

void CAG_AIR_3270_J::finalize(CStringArray* pcsaBody)
{}

void CAG_AIR_3270_J::declareVariable(AG_VARIABLE agVariable,
									 CStringArray* pcsaHeader,
									 bool* bValue)
{}


void CAG_AIR_3270_J::checkDebug()
{
}

