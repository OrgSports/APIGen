// Static Model


#ifndef __CAG_MCS_J_3270_JS_HTML__
#define __CAG_MCS_J_3270_JS_HTML__


// Include files
#include "CAG_MCS_J_3270_JS.h"
class CAG_MCS_J_3270_JS_HTML : public CAG_MCS_J_3270_JS
{

public:

	CAG_MCS_J_3270_JS_HTML();

	~CAG_MCS_J_3270_JS_HTML();

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

};// END CLASS DEFINITION CAG_MCS_J_3270_JS_HTML

#endif // __CAG_MCS_J_3270_JS_HTML__
