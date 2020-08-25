// Model


#ifndef __CAG_IHL_CPP__
#define __CAG_IHL_CPP__


// Include files
#include "CAG_IHL.h"



class CAG_IHL_CPP : public CAG_IHL
{

public:

	CAG_IHL_CPP();

	~CAG_IHL_CPP();

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
	bool	b_pOIABuffer;
	bool	bWHLLAPIDATA;
	bool	bnRetCode;
	bool	bOIA;



};// END CLASS DEFINITION CAG_IHL_CPP

#endif // __CAG_IHL_CPP__
