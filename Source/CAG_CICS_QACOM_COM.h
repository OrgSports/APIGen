// Static Model


#ifndef __CAG_CICS_QACOM_COM__
#define __CAG_CICS_QACOM_COM__


// Include files
#include "CAG_CICS_QACOM.h"
class CAG_CICS_QACOM_COM : public CAG_CICS_QACOM
{

public:

	CAG_CICS_QACOM_COM();

	~CAG_CICS_QACOM_COM();

	void loadFunctionList(CListBox* listTranslateFunction);

	void loadLanguageList(CListBox* listTranslateLanguage);

};// END CLASS DEFINITION CAG_CICS_QACOM_COM

#endif // __CAG_CICS_QACOM_COM__
