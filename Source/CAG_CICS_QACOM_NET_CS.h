// Static Model


#ifndef __CAG_CICS_QACOM_NET_CS__
#define __CAG_CICS_QACOM_NET_CS__


// Include files
#include "CAG_CICS_QACOM_NET.h"
class CAG_CICS_QACOM_NET_CS : public CAG_CICS_QACOM_NET
{

public:

	CAG_CICS_QACOM_NET_CS();
	~CAG_CICS_QACOM_NET_CS();

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


};// END CLASS DEFINITION CAG_CICS_QACOM_NET_CS

#endif // __CAG_CICS_QACOM_NET_CS__
