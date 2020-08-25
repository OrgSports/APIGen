// Static Model


#ifndef __CAG_MCS_AX_VT_VBS_CRL__
#define __CAG_MCS_AX_VT_VBS_CRL__


// Include files
#include "CAG_MCS_Ax_VT_VBS.h"
class CAG_MCS_Ax_VT_VBS_CRL : public CAG_MCS_Ax_VT_VBS
{

public:

	CAG_MCS_Ax_VT_VBS_CRL();

	~CAG_MCS_Ax_VT_VBS_CRL();

	void declareVariable(AG_VARIABLE agVariable,
					  CStringArray* pcsaHeader,
					  bool* bValue);

	void checkDebug(bool b_Debug,
				 CString csFunctionName,
				 CStringArray* pcsaBody);

	void resetVariableFlags();

private:

	void generateHeader(CStringArray* pcsaHeader,
					 CStringArray* pcsaBody);

	void appendBody(int nFunctionNum,
				 bool bPromptForValues,
				 CStringArray* pcsaArguments,
				 CStringArray* pcsaHeader,
				 CStringArray* pcsaBody);

	void finalize(CStringArray* pcsaBody);

};// END CLASS DEFINITION CAG_MCS_Ax_VT_VBS_CRL

#endif // __CAG_MCS_AX_VT_VBS_CRL__
