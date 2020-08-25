// Static Model


#ifndef __CAG_MSI_WIX_DLG__
#define __CAG_MSI_WIX_DLG__


// Include files
#include "CAG_ICONN.h"
#include "WIXDialog.h"
//#include "MSIAction.h"

class CAG_MSI_WIX_DLG : public CAG_ICONN
{

public:

	CAG_MSI_WIX_DLG();

	~CAG_MSI_WIX_DLG();

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
	CWIXDialog WIXCfgDlg;


//	CMSIActionDlg CustomActionParamDlg;

};// END CLASS DEFINITION CAG_MSI_WIX_DLG

#endif // __CAG_MSI_WIX_DLG__
