// Static Model


#ifndef __CAG_EAOJ_VT_HTML_VBS__
#define __CAG_EAOJ_VT_HTML_VBS__


// Include files
#include "CAG_EAOJ_VT.h"
class CAG_EAOJ_VT_HTML_VBS : public CAG_EAOJ_VT
{

public:

	CAG_EAOJ_VT_HTML_VBS();

	~CAG_EAOJ_VT_HTML_VBS();

	void declareVariable(AG_VARIABLE agVariable,
					  CStringArray* pcsaHeader,
					  bool* bValue);

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

};// END CLASS DEFINITION CAG_EAOJ_VT_HTML_VBS

#endif // __CAG_EAOJ_VT_HTML_VBS__
