// Static Model


#ifndef __CAG_AIR__
#define __CAG_AIR__

#include "CAG.H"

class CAG_AIR : public CAG
{

public:

	void declareVariable();
	void loadLanguageList(CListBox* listTranslateLanguage);
	void loadTerminalTypeList(CListBox* listTerminalTypes);

protected:

	CAG_AIR();
	~CAG_AIR();

};// END CLASS DEFINITION CAG_AIR

#endif // __CAG_AIR__
