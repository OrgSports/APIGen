// Static Model


#ifndef __CAG_DOS__
#define __CAG_DOS__
#include "cag.h"


class CAG_DOS : public CAG
{

public:

	CAG_DOS();

	~CAG_DOS();

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

};// END CLASS DEFINITION CAG_DOS

#endif // __CAG_DOS__
