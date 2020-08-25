// Static Model


#ifndef __CAG_WHL_CS__
#define __CAG_WHL_CS__


// Include files
#include "CAG_WHL.h"
class CAG_WHL_CS : public CAG_WHL
{

public:

	CAG_WHL_CS();

	~CAG_WHL_CS();

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

};// END CLASS DEFINITION CAG_WHL_CS

#endif // __CAG_WHL_CS__
