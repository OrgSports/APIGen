// Static Model


#ifndef __CAG_ROLE__
#define __CAG_ROLE__
#include "cag.h"

class CAG_ROLE : public CAG
{

public:

	~CAG_ROLE();
	void loadTerminalTypeList(CListBox* listTerminalTypes);

protected:

	CAG_ROLE();

	virtual void declareVariable(AG_VARIABLE agVariable,
							  CStringArray* pcsaHeader,
							  bool* bValue);

	virtual void loadLanguageList(CListBox* listTranslateLanguage);

};// END CLASS DEFINITION CAG_ROLE

#endif // __CAG_ROLE__
