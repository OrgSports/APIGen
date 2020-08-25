// Static Model


#ifndef __CAG_IHL_CS__
#define __CAG_IHL_CS__


// Include files
#include "CAG_IHL.h"
class CAG_IHL_CS : public CAG_IHL
{

public:

	CAG_IHL_CS();

	~CAG_IHL_CS();

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

};// END CLASS DEFINITION CAG_IHL_CS

#endif // __CAG_IHL_CS__
