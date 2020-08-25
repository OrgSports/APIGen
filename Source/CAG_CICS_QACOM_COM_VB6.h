// Static Model


#ifndef __CAG_CICS_QACOM_COM_VB6__
#define __CAG_CICS_QACOM_COM_VB6__


// Include files
#include "CAG_CICS_QACOM_COM.h"
class CAG_CICS_QACOM_COM_VB6 : public CAG_CICS_QACOM_COM
{

public:

	CAG_CICS_QACOM_COM_VB6();
	~CAG_CICS_QACOM_COM_VB6();

	void checkDebug(bool b_Debug,
				 CString csFunctionName,
				 CStringArray* pcsaBody);

	void resetVariableFlags();

	void generateHeader(CStringArray* csaHeader,
					 CStringArray* csaBody);

	void appendBody(int nFunctionNum,
				 bool bPromptForValues,
				 CStringArray* csaArguments,
				 CStringArray* csaHeader,
				 CStringArray* csaBody);

	void finalize(CStringArray* pcsaBody);

	void declareVariable(AG_VARIABLE agVariable,
					  CStringArray* pcsaHeader,
					  bool* bValue);


};// END CLASS DEFINITION CAG_CICS_QACOM_COM_VB6

#endif // __CAG_CICS_QACOM_COM_VB6__
