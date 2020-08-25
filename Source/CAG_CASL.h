// Static Model


#ifndef __CAG_CASL__
#define __CAG_CASL__
#include "cag.h"

class CAG_CASL : public CAG
{

public:

	CAG_CASL();

	~CAG_CASL();

	void loadFunctionList(CListBox* listTranslateFunction);

	void loadLanguageList(CListBox* listTranslateLanguage);

	void loadTerminalTypeList(CListBox* listTerminalTypes);

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

	void declareVariable(AG_VARIABLE agVariable,
					  CStringArray* pcsaHeader,
					  bool* bValue);

private:
	bool b_nRetVal;
	bool b_nNumber;
	bool b_csName;
	bool b_csButton1;
	bool b_csButton2;
	bool b_csButton3;
	bool b_csButton4;
	bool b_csString;

};// END CLASS DEFINITION CAG_CASL

#endif // __CAG_CASL__
