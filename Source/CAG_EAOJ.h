// Static Model


#ifndef __CAG_EAOJ__
#define __CAG_EAOJ__


// Include files
#include "CAG_EAO.h"
class CAG_EAOJ : public CAG_EAO
{

public:

	~CAG_EAOJ();

	void loadLanguageList(CListBox* listTranslateLanguage);

	virtual void declareVariable(AG_VARIABLE agVariable,
							  CStringArray* pcsaHeader,
							  bool* bValue);

protected:

	CAG_EAOJ();

};// END CLASS DEFINITION CAG_EAOJ

#endif // __CAG_EAOJ__
