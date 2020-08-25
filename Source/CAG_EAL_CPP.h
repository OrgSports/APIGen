// Model


#ifndef __CAG_EAL_CPP__
#define __CAG_EAL_CPP__


// Include files
#include "CAG_EAL.h"
class CAG_EAL_CPP : public CAG_EAL
{

public:

	CAG_EAL_CPP();

	~CAG_EAL_CPP();

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
	bool	b_nType;
	bool	b_pUtilityBuffer;
	bool	b_pTitleBuffer;
	bool	b_nLength;
	bool	b_nTimeout;
	bool	b_nRow;
	bool	b_nColumn;
	bool	b_nIndex;
	bool	b_nSessState;
	bool	b_nPauseTime;
	bool	b_nOption;
	bool	b_nPosition;
	bool	b_pWaitForBuffer;
	bool	b_nSetting;
	bool	b_cEscape;
	bool	b_nSettleTime;
	bool	b_nRet;
	bool	b_cSession;
	bool	b_nTable;
	bool	b_nEvent;

};// END CLASS DEFINITION CAG_EAL_CPP

#endif // __CAG_EAL_CPP__
