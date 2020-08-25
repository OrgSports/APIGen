// Static Model


#ifndef __CAG_EHL_VB6__
#define __CAG_EHL_VB6__


// Include files
#include "CAG_EHL.h"
class CAG_EHL_VB6 : public CAG_EHL
{

public:

	CAG_EHL_VB6();

	~CAG_EHL_VB6();

	void declareVariable(CListBox* agVariable,
					  CStringArray* pcsaHeader,
					  bool bValue);

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

};// END CLASS DEFINITION CAG_EHL_VB6

#endif // __CAG_EHL_VB6__
