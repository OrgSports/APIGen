// Static Model


#ifndef __CAG_CICS11_QACOM_JAVA_J__
#define __CAG_CICS11_QACOM_JAVA_J__


// Include files
#include "CAG_CICS_QACOM_JAVA.h"
class CAG_CICS11_QACOM_JAVA_J : public CAG_CICS_QACOM_JAVA
{

public:

	CAG_CICS11_QACOM_JAVA_J();

	~CAG_CICS11_QACOM_JAVA_J();

	void generateHeader(CStringArray* csaHeader,
					 CStringArray* csaBody);

	void appendBody(int nFunctionNum,
				 bool bPromptForValues,
				 CStringArray* csaArguments,
				 CStringArray* csaHeader,
				 CStringArray* csaBody);

	void loadFunctionList(CListBox* listTranslateFunction);

	void checkDebug(bool b_Debug,
				 CString csFunctionName,
				 CStringArray* pcsaBody);

	void resetVariableFlags();


};// END CLASS DEFINITION CAG_CICS11_QACOM_JAVA_J

#endif // __CAG_CICS11_QACOM_JAVA_J__
