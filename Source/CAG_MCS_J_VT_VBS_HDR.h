// Model


#ifndef __CAG_MCS_J_VT_VBS_HDR__
#define __CAG_MCS_J_VT_VBS_HDR__


// Include files
#include "CAG_MCS_J_VT_VBS.h"
class CAG_MCS_J_VT_VBS_HDR : public CAG_MCS_J_VT_VBS
{

public:

	CAG_MCS_J_VT_VBS_HDR();

	~CAG_MCS_J_VT_VBS_HDR();

	void generateHeader(CStringArray* pcsaHeader,
					 CStringArray* pcsaBody);

	void appendBody(int nFunctionNum,
				 bool bPromptForValues,
				 CStringArray* pcsaArguments,
				 CStringArray* pcsaHeader,
				 CStringArray* pcsaBody);

	void finalize(CStringArray* pcsaBody);

	void declareVariable(AG_VARIABLE agVariable,
					  CStringArray* pcsaHeader,
					  bool* bValue);

	void checkDebug(bool b_Debug,
				 CString csFunctionName,
				 CStringArray* pcsaBody);

	void resetVariableFlags();

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

	bool b_Debug;

};// END CLASS DEFINITION CAG_MCS_J_VT_VBS_HDR

#endif // __CAG_MCS_J_VT_VBS_HDR__
