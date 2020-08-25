// Static Model


#ifndef __CAG_PB_QAC_VBS__
#define __CAG_PB_QAC_VBS__


// Include files
#include "CAG_PB_QAC.h"
class CAG_PB_QAC_VBS : public CAG_PB_QAC
{

public:

	CAG_PB_QAC_VBS();

	~CAG_PB_QAC_VBS();

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

};// END CLASS DEFINITION CAG_PB_QAC_VBS

#endif // __CAG_PB_QAC_VBS__
