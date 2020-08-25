// Model


#ifndef __CAG_MCS_AX_3270_JS_HDR__
#define __CAG_MCS_AX_3270_JS_HDR__


// Include files
#include "CAG_MCS_Ax_3270_JS.h"
class CAG_MCS_Ax_3270_JS_HDR : public CAG_MCS_Ax_3270_JS
{

public:

	CAG_MCS_Ax_3270_JS_HDR();

	~CAG_MCS_Ax_3270_JS_HDR();

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

};// END CLASS DEFINITION CAG_MCS_Ax_3270_JS_HDR

#endif // __CAG_MCS_AX_3270_JS_HDR__
