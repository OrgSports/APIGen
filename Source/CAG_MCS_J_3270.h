// Static Model


#ifndef __CAG_MCS_J_3270__
#define __CAG_MCS_J_3270__


// Include files
#include "CAG_MCS_J.h"
class CAG_MCS_J_3270 : public CAG_MCS_J
{

public:

	~CAG_MCS_J_3270();

	void loadFunctionList(CListBox* listTranslateFunction);

	void loadLanguageList(CListBox* listTranslateLanguage,
					   CListBox* loadFunctionList);

protected:

	CAG_MCS_J_3270();

};// END CLASS DEFINITION CAG_MCS_J_3270

#endif // __CAG_MCS_J_3270__
