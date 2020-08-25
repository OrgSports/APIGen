// Static Model


#ifndef __CAG_IHL_VB6__
#define __CAG_IHL_VB6__


// Include files
#include "CAG_IHL.h"
class CAG_IHL_VB6 : public CAG_IHL
{

public:

	CAG_IHL_VB6();

	~CAG_IHL_VB6();

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

};// END CLASS DEFINITION CAG_IHL_VB6

#endif // __CAG_IHL_VB6__
