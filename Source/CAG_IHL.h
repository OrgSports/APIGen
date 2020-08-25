// Static Model


#ifndef __CAG_IHL__
#define __CAG_IHL__
#include "cag.h"

class CAG_IHL : public CAG
{

protected:

	unsigned short wGlobalPSMallocSize;

	bool b_pUtilityBuffer;

	bool b_pOIABuffer;

	bool bWHLLAPIDATA;

	bool bnRetCode;

	bool bOIA;

public:

	~CAG_IHL();
	void loadTerminalTypeList(CListBox* listTerminalTypes);

protected:

	CAG_IHL();

	void loadFunctionList(CListBox* m_listTranslateFunction);

	virtual void declareVariable(AG_VARIABLE agVariable,
							  CStringArray* pcsaHeader,
							  bool* bValue);

	void loadLanguageList(CListBox* listTranslateLanguage);

	virtual void checkDebug();

};// END CLASS DEFINITION CAG_IHL

#endif // __CAG_IHL__
