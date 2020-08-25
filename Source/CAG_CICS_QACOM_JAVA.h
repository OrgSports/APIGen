// Static Model


#ifndef __CAG_CICS_QACOM_JAVA__
#define __CAG_CICS_QACOM_JAVA__


// Include files
#include "CAG_CICS_QACOM.h"
class CAG_CICS_QACOM_JAVA : public CAG_CICS_QACOM
{

public:

	CAG_CICS_QACOM_JAVA();

	~CAG_CICS_QACOM_JAVA();

	void declareVariable(AG_VARIABLE agVariable,
					  CStringArray* pcsaHeader,
					  bool* bValue);

	void finalize(CStringArray* pcsaBody);

	void checkDebug(bool b_Debug,
				 CString csFunctionName,
				 CStringArray* pcsaBody);

	void resetVariableFlags();

	void loadLanguageList(CListBox* listTranslateLanguage);

};// END CLASS DEFINITION CAG_CICS_QACOM_JAVA

#endif // __CAG_CICS_QACOM_JAVA__
