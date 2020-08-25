// Static Model


#ifndef __CAG_MCS_J__
#define __CAG_MCS_J__
#include "cag.h"

class CAG_MCS_J : public CAG
{

public:

	~CAG_MCS_J();

	void loadFunctionList(CListBox* listTranslateFunction);
	void loadLanguageList(CListBox* listTranslateLanguage);
	void loadTerminalTypeList(CListBox* listTerminalTypes);

protected:

	CAG_MCS_J();

	virtual void declareVariable(AG_VARIABLE agVariable,
							  CStringArray* pcsaHeader,
							  BOOL* bValue);

	virtual void checkDebug();

};// END CLASS DEFINITION CAG_MCS_J

#endif // __CAG_MCS_J__
