// Static Model


#ifndef __CAG_EOLE_5250_EBM_TEST__
#define __CAG_EOLE_5250_EBM_TEST__


// Include files
#include "CAG_EOLE_3270.h"
class CAG_EOLE_5250_EBM_TEST : public CAG_EOLE_3270
{

public:

	CAG_EOLE_5250_EBM_TEST();

	~CAG_EOLE_5250_EBM_TEST();

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
	bool	b_pUtilityBuffer;
	bool	b_csSessionName;
	bool	b_SessionOpen;
	bool	b_nAttribute;
	bool	b_nStatus;
	bool	b_bUpdated;
	bool	b_nRow;
	bool	b_nColumn;
	bool	b_nLength;
	bool	b_nPosition;
	bool	b_nValue;
	bool	bAreaObject;
	bool	b_bRet;
	bool	b_nCloseOption;
	bool	b_nFTHostOS;
	bool	b_nHeight;
	bool	b_nWidth;
	bool	b_bLocalMode;
	bool	b_bMenuVisible;
	bool	b_bSessionQuiet;
	bool	b_bSessionSaved;
	bool	b_bSessionsCreated;
	bool	b_nType;
	bool	b_nTimeout;
	bool	b_bWindowHandle;
	bool	b_nWindowState;
	bool	b_nCount;
	bool	b_nIdle;
	bool	b_nOptions;
	bool	b_nPage;
	bool	b_nEndColumn;
	bool	b_nEndRow;
	bool	b_sKeys;
	bool	b_bProcess;
	bool	b_nSettleTime;
	bool	b_nHostOS;
	bool	b_ftObj;
	bool	b_FTScheme;
	bool	b_font;
	bool	b_bScreenHeld;
	bool	b_settingsPage;
	bool	b_settingsTab;
	bool	b_bKeyboardLocked;
	bool	b_cString;

	bool	b_Debug;

};// END CLASS DEFINITION CAG_EOLE_5250_EBM_TEST

#endif // __CAG_EOLE_5250_EBM_TEST__
