// Static Model


#ifndef __CAG_EOLE_VT_XLS__
#define __CAG_EOLE_VT_XLS__


// Include files
#include "CAG_EOLE_VT.h"
class CAG_EOLE_VT_XLS : public CAG_EOLE_VT
{

public:

	CAG_EOLE_VT_XLS();

	~CAG_EOLE_VT_XLS();

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

};// END CLASS DEFINITION CAG_EOLE_VT_XLS

#endif // __CAG_EOLE_VT_XLS__
