// Static Model


#ifndef __CAG_AIR_T27_J_J__
#define __CAG_AIR_T27_J_J__


// Include files
#include "CAG_AIR_T27_J.h"
class CAG_AIR_T27_J_J : public CAG_AIR_T27_J
{

public:

	CAG_AIR_T27_J_J();

	~CAG_AIR_T27_J_J();

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

	void declareVariable(AG_VARIABLE agVariable,
					  CStringArray* pcsaHeader,
					  bool* bValue);

};// END CLASS DEFINITION CAG_AIR_T27_J_J

#endif // __CAG_AIR_T27_J_J__
