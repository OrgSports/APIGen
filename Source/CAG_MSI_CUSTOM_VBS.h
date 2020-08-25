// Static Model


#ifndef __CAG_MSI_CUSTOM_VBS__
#define __CAG_MSI_CUSTOM_VBS__


// Include files
#include "CAG_ICONN.h"
class CAG_MSI_CUSTOM_VBS : public CAG_ICONN
{

public:

	CAG_MSI_CUSTOM_VBS();

	~CAG_MSI_CUSTOM_VBS();

	void declareVariable(AG_VARIABLE agVariable,
					  CStringArray* pcsaHeader,
					  bool* bValue);

	void checkDebug(bool b_Debug,
				 CString csFunctionName,
				 CStringArray* pcsaBody);

	void resetVariableFlags();

private:

	void generateHeader(CStringArray* csaHeader,
					 CStringArray* csaBody);

	void appendBody(int nFunctionNum,
				 bool bPromptForValues,
				 CStringArray* csaArguments,
				 CStringArray* csaHeader,
				 CStringArray* csaBody);

	void finalize(CStringArray* pcsaBody);

	void loadLanguageList(CListBox* listTranslateLanguage);

	void loadTerminalTypeList(CListBox* listTerminalTypes);

	void loadFunctionList(CListBox* listTranslateFunction);

private:
	bool	b_Debug;
	bool	b_csTaskID;
	bool	b_csBuffer;
	bool	b_nBufferSize;
	bool	b_nBuffer;
	bool	b_XMLData;
	bool	b_nMaxSize;
	bool	b_nTimeout;
	bool	b_csPath;
	bool	b_csDataRef;

	bool	b_csPackagePath;
	bool	b_csScriptPath;
	bool	b_csTransforms;
	bool	b_csProductName;
	bool	b_csFeatureName;
	bool	b_uInstallState;
	bool	b_nFeatureIndex;
	bool	b_bRet;
	bool	b_nStatus;

};// END CLASS DEFINITION CAG_MSI_CUSTOM_VBS

#endif // __CAG_MSI_CUSTOM_VBS__
