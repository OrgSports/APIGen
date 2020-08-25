// Static Model


#ifndef __CAG_MCS_AX__
#define __CAG_MCS_AX__
#include "cag.h"

class CAG_MCS_Ax : public CAG
{

public:

	~CAG_MCS_Ax();

	void loadLanguageList(CListBox* listTranslateLanguage);
	void loadTerminalTypeList(CListBox* listTerminalTypes);

protected:

	CAG_MCS_Ax();

	virtual void declareVariable(AG_VARIABLE agVariable,
							  CStringArray* pcsaHeader,
							  bool* bValue);

	virtual void checkDebug();

};// END CLASS DEFINITION CAG_MCS_Ax

#endif // __CAG_MCS_AX__
