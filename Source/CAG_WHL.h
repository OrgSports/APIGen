// Static Model


#ifndef __CAG_WHL__
#define __CAG_WHL__
#include "cag.h"

class CAG_WHL : public CAG
{

protected:

	unsigned short wGlobalPSMallocSize;

	bool b_pUtilityBuffer;

	bool b_pOIABuffer;

	bool bWHLLAPIDATA;

	bool bnRetCode;

	bool bOIA;

public:

	~CAG_WHL();
	void loadTerminalTypeList(CListBox* listTerminalTypes);

protected:

	CAG_WHL();

	void loadFunctionList(CListBox* listTranslateFunction);

	virtual void declareVariable(AG_VARIABLE agVariable,
							  CStringArray* pcsaHeader,
							  bool* bValue);

	void loadLanguageList(CListBox* listTranslateLanguage);

	virtual void checkDebug();

};// END CLASS DEFINITION CAG_WHL

#endif // __CAG_WHL__
