// Static Model


#ifndef __CAG_MSI_WIX_WIZ__
#define __CAG_MSI_WIX_WIZ__


// Include files
#include "CAG_ICONN.h"
#include "WIXDialog.h"
//#include "MSIAction.h"

class CAG_MSI_WIX_WIZ : public CAG_ICONN
{

public:

	CAG_MSI_WIX_WIZ();

	~CAG_MSI_WIX_WIZ();

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

};// END CLASS DEFINITION CAG_MSI_WIX_WIZ

#endif // __CAG_MSI_WIX_WIZ__
