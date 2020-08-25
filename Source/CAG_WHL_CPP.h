// Static Model


#ifndef __CAG_WHL_CPP__
#define __CAG_WHL_CPP__


// Include files
#include "CAG_WHL.h"
class CAG_WHL_CPP : public CAG_WHL
{

public:

	CAG_WHL_CPP();

	~CAG_WHL_CPP();

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

};// END CLASS DEFINITION CAG_WHL_CPP

#endif // __CAG_WHL_CPP__
