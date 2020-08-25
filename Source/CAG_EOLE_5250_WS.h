// Static Model


#ifndef __CAG_EOLE_5250_WS__
#define __CAG_EOLE_5250_WS__


// Include files
#include "CAG_EOLE_5250.h"
class CAG_EOLE_5250_WS : public CAG_EOLE_5250
{

public:

	CAG_EOLE_5250_WS();

	~CAG_EOLE_5250_WS();

	void declareVariable(AG_VARIABLE agVariable,
					  CStringArray* pcsaHeader,
					  bool* bValue);

	void checkDebug(bool b_Debug,
				 CString csFunctionName,
				 CStringArray* pcsaBody);

	void resetVariableFlags();

private:

	void generateHeader(CStringArray* pcsaHeader,
					 CStringArray* pcsaBody);

	void appendBody(int nFunctionNum,
				 bool bPromptForValues,
				 CStringArray* pcsaArguments,
				 CStringArray* pcsaHeader,
				 CStringArray* pcsaBody);

	void finalize(CStringArray* pcsaBody);

private:
	bool b_Area;
	bool b_bRet;
	bool b_cString;
	bool b_nStatus;
	bool b_bUpdated;
	bool b_pOIAObject;
	bool b_nType;
	bool b_cText;
	bool b_nCount;
	bool b_nColumn;
	bool b_nRow;
	bool b_bEABs;
	bool b_nCharSet;
	bool b_nHostCodePage;
	bool b_bKeyboardLocked;
	bool b_nModel;
	bool b_nLength;
	bool b_nIdleTime;
	bool b_bAttached;
	bool b_nAttribute;
	bool b_csName;
	bool b_Terminal;
	bool b_nMode;
	bool b_nWait;
	bool b_bConnected;
	bool b_ConnectionObj;
	bool b_ScreenObj;
	bool b_nState;
	bool b_nPort;
	bool b_sKeys;
	bool b_nTimeout;
	bool b_bProcess;
	bool b_nIdle;
	bool b_nOptions;
	bool b_nPage;
	bool b_nEndColumn;
	bool b_nEndRow;
	bool b_nSettleTime;
	bool b_nCloseOption;
	bool b_nHostOS;
	bool b_ftObj;
	bool b_FTScheme;
	bool b_font;
	bool b_nHeight;
	bool b_hostname;
	bool b_bLocalMode;
	bool b_bScreenHeld;
	bool b_settingsPage;
	bool b_settingsTab;
	bool b_bMenuVisible;
	bool b_bSessionQuiet;
	bool b_bSessionSaved;
	bool b_nWidth;
	bool b_hSession;
	bool b_nWindowState;
	bool b_SessName;

	bool b_Debug;


};// END CLASS DEFINITION CAG_EOLE_5250_WS

#endif // __CAG_EOLE_5250_WS__
