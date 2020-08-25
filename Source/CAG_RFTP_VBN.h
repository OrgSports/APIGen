// Static Model


#ifndef __CAG_RFTP_VBN__
#define __CAG_RFTP_VBN__


// Include files
#include "CAG_RFTP.h"
class CAG_RFTP_VBN : public CAG_RFTP
{

public:
	CAG_RFTP_VBN();

	~CAG_RFTP_VBN();

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


};// END CLASS DEFINITION CAG_RFTP_VBN

#endif // __CAG_RFTP_VBN__
