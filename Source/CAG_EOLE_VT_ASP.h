// Static Model


#ifndef __CAG_EOLE_VT_ASP__
#define __CAG_EOLE_VT_ASP__


// Include files
#include "CAG_EOLE_VT.h"
class CAG_EOLE_VT_ASP : public CAG_EOLE_VT
{

public:

	CAG_EOLE_VT_ASP();

	~CAG_EOLE_VT_ASP();

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

};// END CLASS DEFINITION CAG_EOLE_VT_ASP

#endif // __CAG_EOLE_VT_ASP__
