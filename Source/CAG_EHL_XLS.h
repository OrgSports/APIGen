// Model


#ifndef __CAG_EHL_XLS__
#define __CAG_EHL_XLS__


// Include files
#include "CAG_EHL.h"
class CAG_EHL_XLS : public CAG_EHL
{

public:

	CAG_EHL_XLS();

	~CAG_EHL_XLS();

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

private:

	BOOL	b_pUtilityBuffer;
	BOOL	b_pOIABuffer;

};// END CLASS DEFINITION CAG_EHL_XLS

#endif // __CAG_EHL_XLS__
