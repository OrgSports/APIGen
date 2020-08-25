// Static Model


#ifndef __CAG_RWEB__
#define __CAG_RWEB__
#include "cag.h"

class CAG_RWEB : public CAG
{

public:

	CAG_RWEB();

	virtual ~CAG_RWEB();

	virtual void declareVariable(AG_VARIABLE agVariable,
							  CStringArray* pcsaHeader,
							  bool* bValue);

	void loadLanguageList(CListBox* listTranslateLanguage);

	void loadTerminalTypeList(CListBox* listTerminalTypes);

};// END CLASS DEFINITION CAG_RWEB

#endif // __CAG_RWEB__
