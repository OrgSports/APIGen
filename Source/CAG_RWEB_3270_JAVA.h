// Static Model


#ifndef __CAG_RWEB_3270_JAVA__
#define __CAG_RWEB_3270_JAVA__


// Include files
#include "CAG_RWEB_3270.h"
class CAG_RWEB_3270_JAVA : public CAG_RWEB_3270
{

public:

	CAG_RWEB_3270_JAVA();

	~CAG_RWEB_3270_JAVA();

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

};// END CLASS DEFINITION CAG_RWEB_3270_JAVA

#endif // __CAG_RWEB_3270_JAVA__
