// Model


#ifndef __CAG_EOLE_3270_VBN__
#define __CAG_EOLE_3270_VBN__


// Include files
#include "CAG_EOLE_3270.h"
class CAG_EOLE_3270_VBN : public CAG_EOLE_3270
{

public:

	CAG_EOLE_3270_VBN();

	~CAG_EOLE_3270_VBN();

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
	bool	b_BSTR;

	bool	b_csSessionName;
	
	bool	b_SessionOpen;
	bool	b_nAttribute;
	bool	b_nStatus;

	bool b_bUpdated;

	bool	b_nRow;
	bool	b_nColumn;

	bool	b_nLength;
	bool	b_nPosition;

	bool	b_nValue;
	bool	bAreaObject;

	bool	b_bRet;
	bool	b_nCloseOption;

	bool	b_nFTHostOS;

	bool	b_sHeight;
	bool	b_nWidth;

	bool	b_bLocalMode;
	bool	b_bMenuVisible;
	bool	b_bSessionQuiet;
	bool	b_bSessionSaved;

	bool	b_nType;
	bool	b_nTimeout;
	bool	b_bProcessKeystrokes;

	bool	b_bWindowHandle;
	bool	b_nWindowState;

	bool	b_nCount;
	bool	b_nSettleTime;

	// new
	bool	b_csHostName;
	bool	b_csFontName;
	bool	b_csFTScheme;
	bool	b_nIdleTime;
	bool	b_nWaitOption;
	bool	b_nWaitID;
	bool	b_nRetCode;
	bool	bAreaOutput;

	bool b_FT_HostFileBSTR;
	bool b_FT_PCFileBSTR;
	bool b_SettingsDialog;
	bool bOIA;

};// END CLASS DEFINITION CAG_EOLE_3270_VBN

#endif // __CAG_EOLE_3270_VBN__
