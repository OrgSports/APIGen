// Static Model


#ifndef __CAG_MSI_CUSTOM_CPP__
#define __CAG_MSI_CUSTOM_CPP__


// Include files
#include "CAG_ICONN.h"
#include "MSIAction.h"

class CAG_MSI_CUSTOM_CPP : public CAG_ICONN
{

public:

	CAG_MSI_CUSTOM_CPP();

	~CAG_MSI_CUSTOM_CPP();

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
	bool	b_szTaskID;
	bool	b_szBuffer;
	bool	b_nBufferSize;
	bool	b_nBuffer;
	bool	b_XMLData;
	bool	b_nMaxSize;
	bool	b_nTimeout;
	bool	b_szPath;
	bool	b_szDataRef;

	bool	b_szPackagePath;
	bool	b_szScriptPath;
	bool	b_szTransforms;
	bool	b_szProductName;
	bool	b_szFeatureName;
	bool	b_uInstallState;
	bool	b_dwFeatureIndex;
	bool	b_bRet;

	bool	b_hInstall;
	bool	b_hInstallation;
	bool	b_hRecord;
	bool	b_pszProperty;
	bool	b_pszValue;

	bool	b_pszUtility;
	bool	b_dwStringLength;
	bool	b_dwResult;
	bool	b_iResult;
	bool	b_INSTALLMessage;

	bool	b_szScriptFile;
	bool	b_dwFlags;
	bool	b_hRegKey;
	bool	b_bRemove;

	bool	b_uResult;

	bool	b_dwPlatform;
	bool	b_dwOptions;

	bool	b_szParentID;
	bool	b_szFeatureID;


	CMSIActionDlg CustomActionParamDlg;

};// END CLASS DEFINITION CAG_MSI_CUSTOM_CPP

#endif // __CAG_MSI_CUSTOM_CPP__
