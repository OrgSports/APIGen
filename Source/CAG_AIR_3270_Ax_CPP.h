// Static Model


#ifndef __CAG_AIR_3270_Ax_CPP__
#define __CAG_AIR_3270_Ax_CPP__


// Include files
#include "CAG_AIR_3270_Ax.h"

class CAG_AIR_3270_Ax_CPP : public CAG_AIR_3270_Ax
{

public:

	CAG_AIR_3270_Ax_CPP();

	~CAG_AIR_3270_Ax_CPP();

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

	void declareVariable(AG_VARIABLE agVariable,
					  CStringArray* pcsaHeader,
					  bool* bValue);

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
	bool	b_csName;
	bool	b_Terminal;
	bool	b_nMode;
	bool	b_nWait;
	bool	b_bConnected;
	bool	b_ConnectionObj;
	bool	b_ScreenObj;
	bool	b_nState;
	bool	b_nPort;
	bool	b_Debug;
	bool	b_slScreenListener;

};// END CLASS DEFINITION CAG_AIR_3270_Ax_CPP

#endif // __CAG_AIR_3270_Ax_CPP__
