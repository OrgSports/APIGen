// Model


#ifndef __CAG_EAOJ_3270_J__
#define __CAG_EAOJ_3270_J__


// Include files
#include "CAG_EAOJ_3270.h"
class CAG_EAOJ_3270_J : public CAG_EAOJ_3270
{

public:

	CAG_EAOJ_3270_J();

	~CAG_EAOJ_3270_J();

	void declareVariable(AG_VARIABLE agVariable,
					  CStringArray* pcsaHeader,
					  bool* bValue);

	void checkDebug(bool b_Debug,
				 CString csFunctionName,
				 CStringArray* pcsaBody);

	void resetVariableFlags();

protected:

	void generateHeader(CStringArray* pcsaHeader,
					 CStringArray* pcsaBody);

	void appendBody(int nFunctionNum,
				 bool bPromptForValues,
				 CStringArray* pcsaArguments,
				 CStringArray* pcsaHeader,
				 CStringArray* pcsaBody);

	void finalize(CStringArray* pcsaBody);

private:
	bool	b_pOIAObject;
	bool	b_nStatus;
	bool	b_nType;
	bool	b_cText;
	bool	b_nCount;
	bool	b_nColumn;
	bool	b_nRow;
	bool	b_bEABs;
	bool	b_nCharSet;
	bool	b_nHostCodePage;
	bool	b_bKeyboardLocked;
	bool	b_nModel;
	bool	b_nLength;
	bool	b_cString;
	bool	b_nIdleTime;
	bool	b_bAttached;

	// new stuff 012605
	bool b_csName;
	bool b_Terminal;
	bool b_nMode;
	bool b_nWait;
	bool b_bConnected;
	bool b_ConnectionObj;
	bool b_ScreenObj;
	bool b_nState;
	bool b_nPort;
	bool b_nTimeout;
	bool b_cKeys;

	bool b_Debug;

};// END CLASS DEFINITION CAG_EAOJ_3270_J

#endif // __CAG_EAOJ_3270_J__
