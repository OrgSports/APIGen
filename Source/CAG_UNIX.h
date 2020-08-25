// Static Model


#ifndef __CAG_UNIX__
#define __CAG_UNIX__
#include "cag.h"

class CAG_UNIX : public CAG
{

public:

	CAG_UNIX();

	~CAG_UNIX();

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

};// END CLASS DEFINITION CAG_UNIX

#endif // __CAG_UNIX__
