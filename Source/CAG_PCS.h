// Static Model


#ifndef __CAG_PCS__
#define __CAG_PCS__
#include "cag.h"

class CAG_PCS : public CAG
{

protected:

	int nGlobalPSMallocSize;

private:

	bool b_pUtilityBuffer;

	bool b_pOIABuffer;

public:

	CAG_PCS();

	~CAG_PCS();

	void loadFunctionList(CListBox* listTranslateFunction);
	void loadLanguageList(CListBox* listTranslateLanguage);
	void loadTerminalTypeList(CListBox* listTerminalTypes);

};// END CLASS DEFINITION CAG_PCS

#endif // __CAG_PCS__
