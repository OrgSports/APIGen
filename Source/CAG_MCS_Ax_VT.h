// Static Model


#ifndef __CAG_MCS_AX_VT__
#define __CAG_MCS_AX_VT__


// Include files
#include "CAG_MCS_Ax.h"
class CAG_MCS_Ax_VT : public CAG_MCS_Ax
{

public:

	~CAG_MCS_Ax_VT();

	void loadFunctionList(CListBox* listTranslateFunction);

	void loadLanguageList(CListBox* listTranslateLanguage,
					   CStringArray* loadFunctionList);

protected:

	CAG_MCS_Ax_VT();

};// END CLASS DEFINITION CAG_MCS_Ax_VT

#endif // __CAG_MCS_AX_VT__
