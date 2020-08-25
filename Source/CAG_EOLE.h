// Static Model


#ifndef __CAG_EOLE__
#define __CAG_EOLE__
#include "cag.h"

class CAG_EOLE : public CAG
{

public:

	CAG_EOLE();
	~CAG_EOLE();

	virtual void loadLanguageList(CListBox* listTranslateLanguage);
	void loadTerminalTypeList(CListBox* listTerminalTypes);

};// END CLASS DEFINITION CAG_EOLE

#endif // __CAG_EOLE__
