// Static Model


#ifndef __CAG_RWEB_VT_JS__
#define __CAG_RWEB_VT_JS__


// Include files
#include "CAG_RWEB_VT.h"
class CAG_RWEB_VT_JS : public CAG_RWEB_VT
{

public:

	CAG_RWEB_VT_JS();

	~CAG_RWEB_VT_JS();

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

private:
	bool b_ECLFieldObj;
	bool b_scrBuffer;
	bool b_nReturn;
	bool b_spScreenPlane;
	bool b_nScreenSize;

	bool b_Debug;

};// END CLASS DEFINITION CAG_RWEB_VT_JS

#endif // __CAG_RWEB_VT_JS__
