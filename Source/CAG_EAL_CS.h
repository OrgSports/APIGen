// Model


#ifndef __CAG_EAL_CS__
#define __CAG_EAL_CS__


// Include files
#include "CAG_EAL.h"
class CAG_EAL_CS : public CAG_EAL
{

public:

	CAG_EAL_CS();

	~CAG_EAL_CS();

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
	BOOL	b_nType;
	BOOL	b_pUtilityBuffer;
	BOOL	b_pTitleBuffer;
	BOOL	b_nLength;
	BOOL	b_nTimeout;
	BOOL	b_nRow;
	BOOL	b_nColumn;
	BOOL	b_nIndex;
	BOOL	b_nSessState;
	BOOL	b_nPauseTime;
	BOOL	b_nOption;
	BOOL	b_nPosition;
	BOOL	b_pWaitForBuffer;
	BOOL	b_nSetting;
	BOOL	b_cEscape;
	BOOL	b_nSettleTime;
	BOOL	b_nRet;
	BOOL	b_cSession;
	BOOL	b_nTable;
	BOOL	b_nEvent;

};// END CLASS DEFINITION CAG_EAL_CS

#endif // __CAG_EAL_CS__
