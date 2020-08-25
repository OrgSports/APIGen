// Model


#ifndef __CAG_RFTP_CPP__
#define __CAG_RFTP_CPP__


// Include files
#include "CAG_RFTP.h"
class CAG_RFTP_CPP : public CAG_RFTP
{

public:
	CAG_RFTP_CPP();
	~CAG_RFTP_CPP();

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

};// END CLASS DEFINITION CAG_RFTP_CPP

#endif // __CAG_RFTP_CPP__
