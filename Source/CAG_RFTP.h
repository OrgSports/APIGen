// Static Model


#ifndef __CAG_RFTP__
#define __CAG_RFTP__
#include "cag.h"

class CAG_RFTP : public CAG
{

public:

	CAG_RFTP();
	~CAG_RFTP();

	void loadFunctionList(CListBox* listTranslateFunction);

	void loadLanguageList(CListBox* listTranslateLanguage);

	void loadTerminalTypeList(CListBox* listTerminalTypes);
protected:



};// END CLASS DEFINITION CAG_RFTP

#endif // __CAG_RFTP__
