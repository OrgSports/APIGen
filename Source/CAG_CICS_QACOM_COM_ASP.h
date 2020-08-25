// Static Model


#ifndef __CAG_CICS_QACOM_COM_ASP__
#define __CAG_CICS_QACOM_COM_ASP__


// Include files
#include "CAG_CICS_QACOM_COM.h"
class CAG_CICS_QACOM_COM_ASP : public CAG_CICS_QACOM_COM
{

public:

	CAG_CICS_QACOM_COM_ASP();
	~CAG_CICS_QACOM_COM_ASP();

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
	bool b_csTerminalPool;
	bool b_csNetworkName;
	bool b_TerminalFacilityLike;
	bool b_csKeys;
	bool b_nRow;
	bool b_nOutRow;
	bool b_nColumn;
	bool b_nOutColumn;
	bool b_nLength;
	bool b_csOutText;
	bool b_Debug;
	bool b_csScreen;
	bool b_cString;
	bool b_nFlag;

};// END CLASS DEFINITION CAG_CICS_QACOM_COM_ASP

#endif // __CAG_CICS_QACOM_COM_ASP__
