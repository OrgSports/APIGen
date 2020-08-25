// Static Model


#ifndef __CAG_AIR_VM__
#define __CAG_AIR_VM__

#include "CAG.H"

class CAG_AIR_VM : public CAG
{

public:

	void declareVariable();
	void loadLanguageList(CListBox* listTranslateLanguage);
	void loadTerminalTypeList(CListBox* listTerminalTypes);

protected:

	CAG_AIR_VM();
	~CAG_AIR_VM();

};// END CLASS DEFINITION CAG_AIR

#endif // __CAG_AIR_VM__
