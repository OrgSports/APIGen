// Static Model


#ifndef __CAG_AIR_3270_AX_VB6__
#define __CAG_AIR_3270_AX_VB6__


// Include files
#include "CAG_AIR_3270_Ax.h"
class CAG_AIR_3270_Ax_VB6 : public CAG_AIR_3270_Ax
{

public:

	void checkDebug(bool b_Debug,
				 CString csFunctionName,
				 CStringArray* pcsaBody);

	void resetVariableFlags();

protected:

	CAG_AIR_3270_Ax_VB6();

	~CAG_AIR_3270_Ax_VB6();

	void generateHeader(CStringArray* pcsaHeader,
					 CStringArray* pcsaBody);

	void appendBody(int nFunctionNum,
				 bool bPromptForValues,
				 CStringArray* pcsaArguments,
				 CStringArray* pcsaHeader,
				 CStringArray* pcsaBody);

	void finalize(CStringArray* pcsaBody);

	void declareVariable(AG_VARIABLE agVariable,
					  CStringArray* pcsaHeader,
					  bool* bValue);

};// END CLASS DEFINITION CAG_AIR_3270_Ax_VB6

#endif // __CAG_AIR_3270_AX_VB6__
