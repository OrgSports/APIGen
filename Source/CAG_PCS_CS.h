// Static Model


#ifndef __CAG_PCS_CS__
#define __CAG_PCS_CS__


// Include files
#include "CAG_PCS.h"
class CAG_PCS_CS : public CAG_PCS
{

public:

	CAG_PCS_CS();

	~CAG_PCS_CS();

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

};// END CLASS DEFINITION CAG_PCS_CS

#endif // __CAG_PCS_CS__
