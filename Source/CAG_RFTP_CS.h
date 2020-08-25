// Static Model


#ifndef __CAG_RFTP_CS__
#define __CAG_RFTP_CS__


// Include files
#include "CAG_RFTP.h"
class CAG_RFTP_CS : public CAG_RFTP
{

public:
	CAG_RFTP_CS();
	~CAG_RFTP_CS();

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


};// END CLASS DEFINITION CAG_RFTP_CS

#endif // __CAG_RFTP_CS__
