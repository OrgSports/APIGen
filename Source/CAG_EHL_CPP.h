// Static Model


#ifndef __CAG_EHL_CPP__
#define __CAG_EHL_CPP__


// Include files
#include "CAG_EHL.h"
class CAG_EHL_CPP : public CAG_EHL
{

public:

	CAG_EHL_CPP();

	~CAG_EHL_CPP();

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

	bool	b_pUtilityBuffer;

};// END CLASS DEFINITION CAG_EHL_CPP

#endif // __CAG_EHL_CPP__
