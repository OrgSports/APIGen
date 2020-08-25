// Static Model


#ifndef __CAG_PB_QAC__
#define __CAG_PB_QAC__
#include "cag.h"

class CAG_PB_QAC : public CAG
{

public:

	~CAG_PB_QAC();

	void loadFunctionList(CListBox* listTranslateFunction);
	void loadLanguageList(CListBox* listTranslateLanguage);
	void loadTerminalTypeList(CListBox* listTerminalTypes);

protected:

	CAG_PB_QAC();

	virtual void declareVariable(AG_VARIABLE agVariable,
							  CStringArray* pcsaHeader,
							  bool* bValue);

	virtual void checkDebug();

};// END CLASS DEFINITION CAG_PB_QAC

#endif // __CAG_PB_QAC__
