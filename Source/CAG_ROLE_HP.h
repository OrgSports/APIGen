// Static Model


#ifndef __CAG_ROLE_HP__
#define __CAG_ROLE_HP__


// Include files
#include "CAG_ROLE_WIN.h"
class CAG_ROLE_HP : public CAG_ROLE_WIN
{

public:

	~CAG_ROLE_HP();

	void loadLanguageList(CListBox* listTranslateLanguage);

protected:

	CAG_ROLE_HP();

private:

	void loadFunctionList(CListBox* listTranslateFunction);

};// END CLASS DEFINITION CAG_ROLE_HP

#endif // __CAG_ROLE_HP__
