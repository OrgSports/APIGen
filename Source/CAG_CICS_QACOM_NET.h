// Static Model


#ifndef __CAG_CICS_QACOM_NET__
#define __CAG_CICS_QACOM_NET__


// Include files
#include "CAG_CICS_QACOM.h"
class CAG_CICS_QACOM_NET : public CAG_CICS_QACOM
{

public:

	CAG_CICS_QACOM_NET();

	~CAG_CICS_QACOM_NET();

	void loadFunctionList(CListBox* listTranslateFunction);

	void loadLanguageList(CListBox* listTranslateLanguage);

};// END CLASS DEFINITION CAG_CICS_QACOM_NET

#endif // __CAG_CICS_QACOM_NET__
