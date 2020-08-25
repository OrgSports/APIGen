// Static Model


#ifndef __CAG_MCS_J_DEPLOY_JS__
#define __CAG_MCS_J_DEPLOY_JS__


// Include files
#include "CAG_MCS_J.h"
// This class provides the ability to generate a "Deployed Session" as explained in the product documentation at "xxx".  It must be implemented at a level above the choice of terminal type because the APIGen user specifies a fully configured and published presentation that an instance of this class will only load.  The method list will therefore need to include the union set of methods available to this API's terminal types.
class CAG_MCS_J_DEPLOY_JS : public CAG_MCS_J
{

public:

	CAG_MCS_J_DEPLOY_JS();

	~CAG_MCS_J_DEPLOY_JS();

	void loadFunctionList(CListBox* listTranslationFunction);

	void loadLanguageList(CListBox* listTranslateLanguage);

	void declareVariable(AG_VARIABLE agVariable,
					  CStringArray* pcsaHeader,
					  bool* bValue);

	void checkDebug(bool b_Debug,
				 CString csFunctionName,
				 CStringArray* pcsaBody);

	void generateHeader(CStringArray* pcsaHeader,
					 CStringArray* pcsaBody);

	void appendBody(int nFunctionNum,
				 bool bPromptForValues,
				 CStringArray* pcsaArguments,
				 CStringArray* pcsaHeader,
				 CStringArray* pcsaBody);

	void finalize(CStringArray* pcsaBody);

	void collectDeploymentParameters(CStringArray* pcsaDeploymentParameters);

};// END CLASS DEFINITION CAG_MCS_J_DEPLOY_JS

#endif // __CAG_MCS_J_DEPLOY_JS__
