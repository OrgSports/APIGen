// Static Model


#ifndef __CAG_EHL_CS__
#define __CAG_EHL_CS__


// Include files
#include "CAG_EHL.h"
class CAG_EHL_CS : public CAG_EHL
{

public:

	CAG_EHL_CS();

	~CAG_EHL_CS();

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

};// END CLASS DEFINITION CAG_EHL_CS

#endif // __CAG_EHL_CS__
