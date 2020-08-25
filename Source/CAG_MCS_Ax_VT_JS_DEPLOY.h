// Model


#ifndef __CAG_MCS_AX_VT_JS_DEPLOY__
#define __CAG_MCS_AX_VT_JS_DEPLOY__


// Include files
#include "CAG_MCS_Ax_VT_JS.h"

#include "DeployParams.h"

class CAG_MCS_Ax_VT_JS_DEPLOY : public CAG_MCS_Ax_VT_JS
{

public:

	CAG_MCS_Ax_VT_JS_DEPLOY();

	~CAG_MCS_Ax_VT_JS_DEPLOY();

	void declareVariable(AG_VARIABLE agVariable,
					  CStringArray* pcsaHeader,
					  bool* bValue);

	void checkDebug(bool b_Debug,
				 CString csFunctionName,
				 CStringArray* pcsaBody);

	void resetVariableFlags();

	void collectDeploymentParameters(CStringArray* pcsaDeploymentParameters);

private:

	void generateHeader(CStringArray* pcsaHeader,
					 CStringArray* pcsaBody);

	void appendBody(int nFunctionNum,
				 bool bPromptForValues,
				 CStringArray* pcsaArguments,
				 CStringArray* pcsaHeader,
				 CStringArray* pcsaBody);

	void finalize(CStringArray* pcsaBody);

	CDeployParams deployParamsDlg;

private:
	bool b_nHRESULT;
	bool b_nFLAG;
	bool b_nATMFT;

	bool b_Debug;

};// END CLASS DEFINITION CAG_MCS_Ax_VT_JS_DEPLOY

#endif // __CAG_MCS_AX_VT_JS_DEPLOY__
