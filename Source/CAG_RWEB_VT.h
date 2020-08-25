// Static Model


#ifndef __CAG_RWEB_VT__
#define __CAG_RWEB_VT__


// Include files
#include "CAG_RWEB.h"
class CAG_RWEB_VT : public CAG_RWEB
{

public:

	CAG_RWEB_VT();

	virtual ~CAG_RWEB_VT();

	void loadFunctionList(CListBox* listTranslationFunction);

};// END CLASS DEFINITION CAG_RWEB_VT

#endif // __CAG_RWEB_VT__
