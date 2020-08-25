// Static Model


#ifndef __CAG_RFTP_VB6__
#define __CAG_RFTP_VB6__


// Include files
#include "CAG_RFTP.h"
class CAG_RFTP_VB6 : public CAG_RFTP
{

public:

	CAG_RFTP_VB6();
	~CAG_RFTP_VB6();

	void generateHeader(CStringArray* pcsaHeader,
					 CStringArray* pcsaBody);

	void appendBody(int nFunctionNum,
				 bool bPromptForValues,
				 CStringArray* pcsaArguments,
				 CStringArray* pcsaHeader,
				 CStringArray* pcsaBody);

	void finalize(CStringArray* pcsaBody);

	void declareVariable(AG_VARIABLE agVariable,
					  CStringArray* pcsaBody,
					  bool* bValue);

	void checkDebug(bool b_Debug,
				 CString csFunctionName,
				 CStringArray* pcsaBody);

	void resetVariableFlags();


private:
	bool b_nRetVal;
	bool	b_nResponse;
	bool b_csRemoteDir;
	bool b_bSearching;

};// END CLASS DEFINITION CAG_RFTP_VB6

#endif // __CAG_RFTP_VB6__
