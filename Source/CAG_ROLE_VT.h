// Static Model


#ifndef __CAG_ROLE_VT__
#define __CAG_ROLE_VT__


// Include files
#include "CAG_ROLE_WIN.h"
class CAG_ROLE_VT : public CAG_ROLE_WIN
{

public:

	~CAG_ROLE_VT();

	void loadLanguageList(CListBox* listTranslateLanguage);

protected:

	CAG_ROLE_VT();

private:

	void loadFunctionList(CListBox* listTranslateFunction);

};// END CLASS DEFINITION CAG_ROLE_VT

#endif // __CAG_ROLE_VT__
