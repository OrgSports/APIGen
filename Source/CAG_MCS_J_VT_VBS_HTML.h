// Static Model


#ifndef __CAG_MCS_J_VT_VBS_HTML__
#define __CAG_MCS_J_VT_VBS_HTML__


// Include files
#include "CAG_MCS_J_VT_VBS.h"
class CAG_MCS_J_VT_VBS_HTML : public CAG_MCS_J_VT_VBS
{

public:

	CAG_MCS_J_VT_VBS_HTML();

	~CAG_MCS_J_VT_VBS_HTML();

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

	void checkDebug(bool b_Debug,
				 CString csFunctionName,
				 CStringArray* pcsaBody);

	void resetVariableFlags();

};// END CLASS DEFINITION CAG_MCS_J_VT_VBS_HTML

#endif // __CAG_MCS_J_VT_VBS_HTML__
