// Model


#ifndef __CAG_MCS_AX_3270_JS_CRL__
#define __CAG_MCS_AX_3270_JS_CRL__


// Include files
#include "CAG_MCS_Ax_3270_JS.h"
class CAG_MCS_Ax_3270_JS_CRL : public CAG_MCS_Ax_3270_JS
{

public:

	CAG_MCS_Ax_3270_JS_CRL();

	~CAG_MCS_Ax_3270_JS_CRL();

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

};// END CLASS DEFINITION CAG_MCS_Ax_3270_JS_CRL

#endif // __CAG_MCS_AX_3270_JS_CRL__
