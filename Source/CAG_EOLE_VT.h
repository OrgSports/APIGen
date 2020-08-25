// Static Model


#ifndef __CAG_EOLE_VT__
#define __CAG_EOLE_VT__


// Include files
#include "CAG_EOLE.h"
class CAG_EOLE_VT : public CAG_EOLE
{

public:

	~CAG_EOLE_VT();

	void loadFunctionList(CListBox* listTranslateFunction);

	void loadLanguageList(CListBox* listTranslateLanguage);

protected:

	CAG_EOLE_VT();

};// END CLASS DEFINITION CAG_EOLE_VT

#endif // __CAG_EOLE_VT__
