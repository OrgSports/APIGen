// Static Model


#ifndef __CAG_ROLE_3270_CPP__
#define __CAG_ROLE_3270_CPP__


// Include files
#include "CAG_ROLE_3270.h"
class CAG_ROLE_3270_CPP : public CAG_ROLE_3270
{

public:

	CAG_ROLE_3270_CPP();

	~CAG_ROLE_3270_CPP();

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

};// END CLASS DEFINITION CAG_ROLE_3270_CPP

#endif // __CAG_ROLE_3270_CPP__
