// Static Model


#ifndef __CAG_EOLE_5250__
#define __CAG_EOLE_5250__


// Include files
#include "CAG_EOLE.h"
class CAG_EOLE_5250 : public CAG_EOLE
{

public:

	~CAG_EOLE_5250();

	void loadFunctionList(CListBox* listTranslateFunction);

	void loadLanguageList(CListBox* listTranslateLanguage);

protected:

	CAG_EOLE_5250();

};// END CLASS DEFINITION CAG_EOLE_5250

#endif // __CAG_EOLE_5250__
