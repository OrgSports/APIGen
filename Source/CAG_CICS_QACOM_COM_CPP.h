// Static Model


#ifndef __CAG_CICS_QACOM_COM_CPP__
#define __CAG_CICS_QACOM_COM_CPP__


// Include files
#include "CAG_CICS_QACOM_COM.h"
class CAG_CICS_QACOM_COM_CPP : public CAG_CICS_QACOM_COM
{

public:

	CAG_CICS_QACOM_COM_CPP();

	~CAG_CICS_QACOM_COM_CPP();

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


private:
	bool b_csIPAddr;
	bool b_lPort;
	bool b_csUserID;
	bool b_csPassword;
	bool b_csNewPassword;
	bool b_lTermModel;

};// END CLASS DEFINITION CAG_CICS_QACOM_COM_CPP

#endif // __CAG_CICS_QACOM_COM_CPP__
