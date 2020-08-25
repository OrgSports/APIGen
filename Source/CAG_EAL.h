// Static Model


#ifndef __CAG_EAL__
#define __CAG_EAL__
#include "cag.h"

class CAG_EAL : public CAG
{

private:

	bool b_nType;

	bool b_pUtilityBuffer;

	bool b_pTitleBuffer;

	bool b_nLength;

	bool b_nTimeout;

	bool b_nRow;

	bool b_nColumn;

	bool b_nIndex;

	bool b_nSessState;

	bool b_nPauseTime;

	bool b_nOption;

	bool b_nPosition;

	bool b_pWaitForBuffer;

	bool b_nSetting;

	bool b_cEscape;

	bool b_nSettleTime;

	bool b_nRet;

	bool b_cSession;

	bool b_nTable;

	bool b_nEvent;

public:

	~CAG_EAL();

	void loadFunctionList(CListBox* listTranslateFunction);
	void loadLanguageList(CListBox* listTranslateLanguage);
	void loadTerminalTypeList(CListBox* listTerminalTypes);

	virtual void declareVariable(AG_VARIABLE agVariable,
							  CStringArray* pcsaHeader,
							  bool* bValue);

protected:

	CAG_EAL();

};// END CLASS DEFINITION CAG_EAL

#endif // __CAG_EAL__
