// Static Model


#ifndef __CAG_VHI_CS__
#define __CAG_VHI_CS__


// Include files
#include "CAG_VHI.h"
class CAG_VHI_CS : public CAG_VHI
{

public:

	CAG_VHI_CS();

	~CAG_VHI_CS();

	void declareVariable(AG_VARIABLE agVariable,
					  CStringArray* pcsaHeader,
					  bool* bValue);

	void checkDebug(bool b_Debug,
				 CString csFunctionName,
				 CStringArray* pcsaBody);

	void resetVariableFlags();


	void generateHeader(CStringArray* csaHeader,
					 CStringArray* csaBody);

	void appendBody(int nFunctionNum,
				 bool bPromptForValues,
				 CStringArray* csaArguments,
				 CStringArray* csaHeader,
				 CStringArray* csaBody);

	void finalize(CStringArray* pcsaBody);

private:
	bool b_Area;
	bool b_bAttached;
	bool b_bCaseSensitive;
	bool b_bConnected;
	bool b_csDomain;
	bool b_bEABs;
	bool b_bKeyboardLocked;
	bool b_bLocalMode;
	bool b_bMenuVisible;
	bool b_bProcess;
	bool b_bRet;
	bool b_bScreenHeld;
	bool b_bSessionQuiet;
	bool b_bSessionSaved;
	bool b_bUpdated;
	bool b_ConnectionObj;
	bool b_csCommand;
	bool b_csDataInputValues;
	bool b_csFilter;
	bool b_csModel;
	bool b_csModelVariable;
	bool b_csName;
	bool b_csOutputColNames;
	bool b_csPassword;
	bool b_csProcedure;
	bool b_csServer;
	bool b_csSQL;
	bool b_csTable;
	bool b_cString;
	bool b_csUserID;
	bool b_cText;
	bool b_Debug;
	bool b_font;
	bool b_ftObj;
	bool b_FTScheme;
	bool b_hostname;
	bool b_hSession;
	bool b_nAttribute;
	bool b_nCharSet;
	bool b_nCloseOption;
	bool b_nColumn;
	bool b_nCount;
	bool b_nEndColumn;
	bool b_nEndRow;
	bool b_nEventNum;
	bool b_nHeight;
	bool b_nHostCodePage;
	bool b_nHostOS;
	bool b_nIdle;
	bool b_nIdleTime;
	bool b_nKey;
	bool b_nLength;
	bool b_nMaxRows;
	bool b_nMode;
	bool b_nModel;
	bool b_nOptions;
	bool b_nPage;
	bool b_nPort;
	bool b_nRow;
	bool b_nSettleTime;
	bool b_nState;
	bool b_nStatus;
	bool b_nTimeout;
	bool b_nType;
	bool b_nWait;
	bool b_nWidth;
	bool b_nWindowState;
	bool b_pOIAObject;
	bool b_ScreenObj;
	bool b_SessName;
	bool b_settingsPage;
	bool b_settingsTab;
	bool b_sKeys;
	bool b_Terminal;

};// END CLASS DEFINITION CAG_VHI_CS

#endif // __CAG_VHI_CS__
