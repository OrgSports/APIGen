// Model


#ifndef __CAG_EAOAx_VT_HTML_JS__
#define __CAG_EAOAx_VT_HTML_JS__


// Include files
#include "CAG_MCS_Ax_VT_JS.h"
class CAG_EAOAx_VT_HTML_JS : public CAG_MCS_Ax_VT_JS
{

public:

	CAG_EAOAx_VT_HTML_JS();

	~CAG_EAOAx_VT_HTML_JS();

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

private:
	bool b_nHRESULT;
	bool b_nFLAG;
	bool b_nATMFT;

	bool b_Debug;

};// END CLASS DEFINITION CAG_EAOAx_VT_HTML_JS

#endif // __CAG_EAOAx_VT_HTML_JS__
