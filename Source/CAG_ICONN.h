// Static Model


#ifndef __CAG_ICONN__
#define __CAG_ICONN__
#include "cag.h"

class CAG_ICONN : public CAG
{

public:

	CAG_ICONN();

	~CAG_ICONN();

	virtual void loadLanguageList(CListBox* listTranslateLanguage);

	void loadTerminalTypeList(CListBox* listTerminalTypes);

	void loadFunctionList(CListBox* listTranslateFunction);

};// END CLASS DEFINITION CAG_ICONN

#endif // __CAG_ICONN__
