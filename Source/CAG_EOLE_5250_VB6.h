// Static Model


#ifndef __CAG_EOLE_5250_VB6__
#define __CAG_EOLE_5250_VB6__


// Include files
#include "CAG_EOLE_5250.h"
class CAG_EOLE_5250_VB6 : public CAG_EOLE_5250
{

public:

	CAG_EOLE_5250_VB6();

	~CAG_EOLE_5250_VB6();

	void declareVariable(AG_VARIABLE agVariable,
					  CStringArray* pcsaHeader,
					  bool* bValue);

	void checkDebug(bool b_Debug,
				 CString csFunctionName,
				 CStringArray* pcsaBody);

	void resetVariableFlags();

private:

	void generateHeader(CStringArray* csaHeader,
					 CStringArray* csaBody);

	void appendBody(int nFunctionNum,
				 bool bPromptForValues,
				 CStringArray* csaArguments,
				 CStringArray* csaHeader,
				 CStringArray* csaBody);

	void finalize(CStringArray* pcsaBody);

};// END CLASS DEFINITION CAG_EOLE_5250_VB6

#endif // __CAG_EOLE_5250_VB6__
