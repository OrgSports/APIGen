// Static Model


#ifndef __CAG_ROLE_3270__
#define __CAG_ROLE_3270__


// Include files
#include "CAG_ROLE_IBM.h"
class CAG_ROLE_3270 : public CAG_ROLE_IBM
{

public:

	CAG_ROLE_3270();

	~CAG_ROLE_3270();

	void loadLanguageList(CListBox* listTranslateLanguage);

private:

	void loadFunctionList(CListBox* listTranslateFunction);

};// END CLASS DEFINITION CAG_ROLE_3270

#endif // __CAG_ROLE_3270__
