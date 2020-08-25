// Static Model


#ifndef __CAG_ROLE_HP_VB6__
#define __CAG_ROLE_HP_VB6__


// Include files
#include "CAG_ROLE_HP.h"
class CAG_ROLE_HP_VB6 : public CAG_ROLE_HP
{

public:

	CAG_ROLE_HP_VB6();

	~CAG_ROLE_HP_VB6();

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

};// END CLASS DEFINITION CAG_ROLE_HP_VB6

#endif // __CAG_ROLE_HP_VB6__
