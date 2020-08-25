// Static Model


#ifndef __CAG_MCS_J_5250__
#define __CAG_MCS_J_5250__


// Include files
#include "CAG_MCS_J.h"
class CAG_MCS_J_5250 : public CAG_MCS_J
{

public:

	~CAG_MCS_J_5250();

	void loadFunctionList(CListBox* listTranslateFunction);

	void loadLanguageList(CListBox* listTranslateLanguage,
					   CListBox* loadFunctionList);

protected:

	CAG_MCS_J_5250();

};// END CLASS DEFINITION CAG_MCS_J_5250

#endif // __CAG_MCS_J_5250__
