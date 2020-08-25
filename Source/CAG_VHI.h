// Static Model


#ifndef __CAG_VHI__
#define __CAG_VHI__
#include "cag.h"

class CAG_VHI : public CAG
{

public:

	CAG_VHI();

	~CAG_VHI();

	virtual void loadLanguageList(CListBox* listTranslateLanguage);
	void loadTerminalTypeList(CListBox* listTerminalTypes);
	void loadFunctionList(CListBox* listTranslateFunction);

};// END CLASS DEFINITION CAG_VHI

#endif // __CAG_VHI__
