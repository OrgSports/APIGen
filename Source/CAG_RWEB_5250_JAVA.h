// Static Model


#ifndef __CAG_RWEB_5250_JAVA__
#define __CAG_RWEB_5250_JAVA__


// Include files
#include "CAG_RWEB_5250.h"
class CAG_RWEB_5250_JAVA : public CAG_RWEB_5250
{

public:

	CAG_RWEB_5250_JAVA();

	~CAG_RWEB_5250_JAVA();

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

	void checkDebug(bool b_Debug,
				 CString csFunctionName,
				 CStringArray* pcsaBody);

	void resetVariableFlags();

};// END CLASS DEFINITION CAG_RWEB_5250_JAVA

#endif // __CAG_RWEB_5250_JAVA__
