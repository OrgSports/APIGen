// Static Model


#ifndef __CAG_EAOAX__
#define __CAG_EAOAX__


// Include files
#include "CAG_EAO.h"
class CAG_EAOAx : public CAG_EAO
{

public:

	~CAG_EAOAx();

	void loadTerminalTypeList(CListBox* listTerminalTypes);
	void loadLanguageList(CListBox* listTranslateLanguage);

	virtual void declareVariable(AG_VARIABLE agVariable,
							  CStringArray* pcsaHeader,
							  bool* bValue);

protected:

	CAG_EAOAx();

};// END CLASS DEFINITION CAG_EAOAx

#endif // __CAG_EAOAX__
