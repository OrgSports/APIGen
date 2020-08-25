// Static Model


#ifndef __CAG_ROLE_3270_ASP__
#define __CAG_ROLE_3270_ASP__


// Include files
#include "CAG_ROLE_3270.h"
class CAG_ROLE_3270_ASP : public CAG_ROLE_3270
{

public:

	CAG_ROLE_3270_ASP();

	~CAG_ROLE_3270_ASP();

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

};// END CLASS DEFINITION CAG_ROLE_3270_ASP

#endif // __CAG_ROLE_3270_ASP__
