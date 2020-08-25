// Static Model


#ifndef __CAG_MCS_J_3270_VBS_DEPLOY__
#define __CAG_MCS_J_3270_VBS_DEPLOY__


// Include files
#include "CAG_MCS_J_3270_VBS.h"
// This class provides the ability to generate a "Deployed Session" as explained in the product documentation at "xxx".  
class CAG_MCS_J_3270_VBS_DEPLOY : public CAG_MCS_J_3270_VBS
{

public:

	CAG_MCS_J_3270_VBS_DEPLOY();

	~CAG_MCS_J_3270_VBS_DEPLOY();

	void declareVariable(AG_VARIABLE agVariable,
					  CStringArray* pcsaHeader,
					  bool* bValue);

	void checkDebug(bool b_Debug,
				 CString csFunctionName,
				 CStringArray* pcsaBody);

	void resetVariableFlags();

	void generateHeader(CStringArray* pcsaHeader,
					 CStringArray* pcsaBody);

	void appendBody(int nFunctionNum,
				 bool bPromptForValues,
				 CStringArray* pcsaArguments,
				 CStringArray* pcsaHeader,
				 CStringArray* pcsaBody);

	void finalize(CStringArray* pcsaBody);

	void collectDeploymentParameters(CStringArray* pcsaDeploymentParameters);

};// END CLASS DEFINITION CAG_MCS_J_3270_VBS_DEPLOY

#endif // __CAG_MCS_J_3270_VBS_DEPLOY__
