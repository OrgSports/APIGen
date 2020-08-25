// Static Model


#ifndef __CAG_RWEB_3270__
#define __CAG_RWEB_3270__


// Include files
#include "CAG_RWEB.h"
class CAG_RWEB_3270 : public CAG_RWEB
{

public:

	CAG_RWEB_3270();

	virtual ~CAG_RWEB_3270();

	void loadFunctionList(CListBox* listTranslationFunction);

};// END CLASS DEFINITION CAG_RWEB_3270

#endif // __CAG_RWEB_3270__
