// Static Model


#ifndef __CAG_ITASK__
#define __CAG_ITASK__
#include "cag.h"

class CAG_ITASK : public CAG
{

public:

	CAG_ITASK();

	~CAG_ITASK();

	virtual void loadLanguageList(CListBox* listTranslateLanguage);

	void loadTerminalTypeList(CListBox* listTerminalTypes);

	void loadFunctionList(CListBox* listTranslateFunction);

};// END CLASS DEFINITION CAG_ITASK

#endif // __CAG_ITASK__
