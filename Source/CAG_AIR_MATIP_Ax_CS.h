// Static Model


#ifndef __CAG_AIR_MATIP_AX_CS__
#define __CAG_AIR_MATIP_AX_CS__


// Include files
#include "CAG_AIR_MATIP_Ax.h"
class CAG_AIR_MATIP_Ax_CS : public CAG_AIR_MATIP_Ax
{

public:

	CAG_AIR_MATIP_Ax_CS();
	~CAG_AIR_MATIP_Ax_CS();

	void checkDebug(bool b_Debug,
				 CString csFunctionName,
				 CStringArray* pcsaBody);

	void resetVariableFlags();

protected:

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

};// END CLASS DEFINITION CAG_AIR_MATIP_Ax_CS

#endif // __CAG_AIR_MATIP_AX_CS__
