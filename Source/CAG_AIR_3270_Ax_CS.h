// Static Model


#ifndef __CAG_AIR_3270_AX_CS__
#define __CAG_AIR_3270_AX_CS__


// Include files
#include "CAG_AIR_3270_Ax.h"
class CAG_AIR_3270_Ax_CS : public CAG_AIR_3270_Ax
{

public:

	~CAG_AIR_3270_Ax_CS();

	void checkDebug(bool b_Debug,
				 CString csFunctionName,
				 CStringArray* pcsaBody);

	void resetVariableFlags();

protected:

	CAG_AIR_3270_Ax_CS();

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

};// END CLASS DEFINITION CAG_AIR_3270_Ax_CS

#endif // __CAG_AIR_3270_AX_CS__
