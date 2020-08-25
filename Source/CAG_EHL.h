// Static Model


#ifndef __CAG_EHL__
#define __CAG_EHL__
#include "cag.h"

class CAG_EHL : public CAG
{

private:



public:

	~CAG_EHL();

	void loadFunctionList(CListBox* listTranslationFunction);

	void loadLanguageList(CListBox* listTranslateLanguage);

	void loadTerminalTypeList(CListBox* listTerminalTypes);

	bool b_pUtilityBuffer;

protected:

	CAG_EHL();

};// END CLASS DEFINITION CAG_EHL

#endif // __CAG_EHL__
