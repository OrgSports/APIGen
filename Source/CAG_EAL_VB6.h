// Static Model


#ifndef __CAG_EAL_VB6__
#define __CAG_EAL_VB6__


// Include files
#include "CAG_EAL.h"
class CAG_EAL_VB6 : public CAG_EAL
{

public:

	CAG_EAL_VB6();

	~CAG_EAL_VB6();

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

};// END CLASS DEFINITION CAG_EAL_VB6

#endif // __CAG_EAL_VB6__
