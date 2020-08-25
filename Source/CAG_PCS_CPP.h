// Model


#ifndef __CAG_PCS_CPP__
#define __CAG_PCS_CPP__


// Include files
#include "CAG_PCS.h"
class CAG_PCS_CPP : public CAG_PCS
{

public:

	CAG_PCS_CPP();

	~CAG_PCS_CPP();

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

};// END CLASS DEFINITION CAG_PCS_CPP

#endif // __CAG_PCS_CPP__
