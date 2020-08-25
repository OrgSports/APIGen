// Static Model


#ifndef __CAG_EOLE_3270_CPP__
#define __CAG_EOLE_3270_CPP__


// Include files
#include "CAG_EOLE_3270.h"
class CAG_EOLE_3270_CPP : public CAG_EOLE_3270
{

public:

	CAG_EOLE_3270_CPP();

	~CAG_EOLE_3270_CPP();

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
	bool     b_bKeyboardLocked;
	bool     b_bLocalMode;
	bool     b_bMenuVisible;
	bool     b_bProcess;
	bool     b_bProcessKeystrokes;
	bool     b_bRet;
	bool     b_bSessionQuiet;
	bool     b_bSessionSaved;
	bool     b_BSTR;
	bool     b_bUpdated;
	bool     b_bWindowHandle;
	bool     b_csFontName;
	bool     b_csFTScheme;
	bool     b_csHostName;
	bool     b_csSessionName;
	bool     b_FT_HostFileBSTR;
	bool     b_FT_PCFileBSTR;
	bool     b_ftObj;
	bool     b_nAttribute;
	bool     b_nCloseOption;
	bool     b_nColumn;
	bool     b_nColumnEnd;
	bool     b_nCount;
	bool     b_nFTHostOS;
	bool     b_nIdleTime;
	bool     b_nLength;
	bool     b_nPosition;
	bool     b_nRetCode;
	bool     b_nRow;
	bool     b_nRowEnd;
	bool     b_nSettingsPage;
	bool     b_nSettingsPageTab;
	bool     b_nSettleTime;
	bool     b_nStatus;
	bool     b_nTimeout;
	bool     b_nType;
	bool     b_nValue;
	bool     b_nWaitID;
	bool     b_nWaitOption;
	bool     b_nWidth;
	bool     b_nWindowState;
	bool     b_pUtilityBuffer;
	bool     b_SessionOpen;
	bool     b_SettingsDialog;
	bool     b_sHeight;
	bool     bAreaObject;
	bool     bAreaOutput;
	bool     bOIA;

};// END CLASS DEFINITION CAG_EOLE_3270_CPP

#endif // __CAG_EOLE_3270_CPP__
