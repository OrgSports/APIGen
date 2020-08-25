// Static Model


#ifndef __CAG_ROLE_3270_XLS__
#define __CAG_ROLE_3270_XLS__


// Include files
#include "CAG_ROLE_3270.h"
class CAG_ROLE_3270_XLS : public CAG_ROLE_3270
{

public:

	CAG_ROLE_3270_XLS();

	~CAG_ROLE_3270_XLS();

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

};// END CLASS DEFINITION CAG_ROLE_3270_XLS

#endif // __CAG_ROLE_3270_XLS__
