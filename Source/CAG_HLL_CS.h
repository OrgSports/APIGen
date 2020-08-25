// Static Model


#ifndef __CAG_HLL_CS__
#define __CAG_HLL_CS__


// Include files
#include "CAG_HLL.h"
class CAG_HLL_CS : public CAG_HLL
{

public:

	CAG_HLL_CS();

	~CAG_HLL_CS();

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

};// END CLASS DEFINITION CAG_HLL_CS

#endif // __CAG_HLL_CS__
