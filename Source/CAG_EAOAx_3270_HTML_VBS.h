// Static Model


#ifndef __CAG_EAOAx_3270_HTML_VBS__
#define __CAG_EAOAx_3270_HTML_VBS__


// Include files
#include "CAG_MCS_Ax_3270_VBS.h"
class CAG_EAOAx_3270_HTML_VBS : public CAG_MCS_Ax_3270_VBS
{

public:

	CAG_EAOAx_3270_HTML_VBS();

	~CAG_EAOAx_3270_HTML_VBS();

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

};// END CLASS DEFINITION CAG_EAOAx_3270_HTML_VBS

#endif // __CAG_EAOAx_3270_HTML_VBS__
