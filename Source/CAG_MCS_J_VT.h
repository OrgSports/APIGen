// Static Model


#ifndef __CAG_MCS_J_VT__
#define __CAG_MCS_J_VT__


// Include files
#include "CAG_MCS_J.h"
class CAG_MCS_J_VT : public CAG_MCS_J
{

public:

	~CAG_MCS_J_VT();

	void loadFunctionList(CListBox* listTranslateFunction);

	void loadLanguageList(CListBox* listTranslateLanguage,
					   CListBox* loadFunctionList);

protected:

	CAG_MCS_J_VT();

};// END CLASS DEFINITION CAG_MCS_J_VT

#endif // __CAG_MCS_J_VT__
