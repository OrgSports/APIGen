// Static Model


#ifndef __CAG_WHL_VBN__
#define __CAG_WHL_VBN__


// Include files
#include "CAG_WHL.h"
class CAG_WHL_VBN : public CAG_WHL
{

public:

	CAG_WHL_VBN();

	~CAG_WHL_VBN();

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

};// END CLASS DEFINITION CAG_WHL_VBN

#endif // __CAG_WHL_VBN__
