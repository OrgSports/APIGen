// Model


#ifndef __CAG_HLL_CPP__
#define __CAG_HLL_CPP__


// Include files
#include "CAG_HLL.h"
class CAG_HLL_CPP : public CAG_HLL
{

public:

	CAG_HLL_CPP();

	~CAG_HLL_CPP();

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


	// HLLAPI
	bool	b_ATMSYSTEM;
	bool	b_SESS_STATUS;
	bool	b_wRowColFlag;
	bool	b_ptPosition;
	bool	b_wLength;
	bool	b_wPosition;
	bool	b_wFieldSpecifier;
	bool	b_pKeystroke;
	bool	b_wType;
	bool	b_HLLParams;
	bool	b_wNumber;
	bool	b_Sessions;
	bool	b_ATMSystem;
	bool	b_wSequenceID;
	bool	b_msgFileTransferComplete;
	bool	b_StartIntercept;


};// END CLASS DEFINITION CAG_HLL_CPP

#endif // __CAG_HLL_CPP__
