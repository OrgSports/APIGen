// Static Model


#ifndef __CAG_ROLE_5250__
#define __CAG_ROLE_5250__


// Include files
#include "CAG_ROLE_IBM.h"
class CAG_ROLE_5250 : public CAG_ROLE_IBM
{

public:

	~CAG_ROLE_5250();

	void loadLanguageList(CListBox* listTranslateLanguage);

protected:

	CAG_ROLE_5250();

private:

	void loadFunctionList(CListBox* listTranslateFunction);

};// END CLASS DEFINITION CAG_ROLE_5250

#endif // __CAG_ROLE_5250__
