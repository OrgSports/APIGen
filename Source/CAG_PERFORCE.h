// Static Model


#ifndef __CAG_PERFORCE__
#define __CAG_PERFORCE__
#include "cag.h"
#include "P4Globals.h"

class CAG_PERFORCE : public CAG
{

public:

	CAG_PERFORCE();

	~CAG_PERFORCE();

	void loadFunctionList(CListBox* listTranslateFunction);

	void loadLanguageList(CListBox* listTranslateLanguage);

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

	void declareVariable(AG_VARIABLE agVariable,
					  CStringArray* pcsaHeader,
					  bool* bValue);

	void loadTerminalTypeList(CListBox* listTerminalTypes);

private:
	bool b_nRetVal;
	bool	b_nNumber;

	CP4Globals P4GlobalSettingsDlg;

};// END CLASS DEFINITION CAG_PERFORCE

#endif // __CAG_PERFORCE__
