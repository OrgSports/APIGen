// Static Model


#ifndef __CAG_PCS_VB6__
#define __CAG_PCS_VB6__


// Include files
#include "CAG_PCS.h"
class CAG_PCS_VB6 : public CAG_PCS
{

public:

	CAG_PCS_VB6();

	~CAG_PCS_VB6();

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

};// END CLASS DEFINITION CAG_PCS_VB6

#endif // __CAG_PCS_VB6__
