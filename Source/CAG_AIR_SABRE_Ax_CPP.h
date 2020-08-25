// Static Model


#ifndef __CAG_AIR_SABRE_AX_CPP__
#define __CAG_AIR_SABRE_AX_CPP__


// Include files
#include "CAG_AIR_SABRE_Ax.h"
class CAG_AIR_SABRE_Ax_CPP : public CAG_AIR_SABRE_Ax
{

public:

	CAG_AIR_SABRE_Ax_CPP();
	~CAG_AIR_SABRE_Ax_CPP();

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

};// END CLASS DEFINITION CAG_AIR_SABRE_Ax_CPP

#endif // __CAG_AIR_SABRE_AX_CPP__
