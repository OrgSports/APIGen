// Static Model


#ifndef __CAG_AIR_LANTERN_J_J__
#define __CAG_AIR_LANTERN_J_J__


// Include files
#include "CAG_AIR_LANTERN_J.h"
class CAG_AIR_LANTERN_J_J : public CAG_AIR_LANTERN_J
{

public:

	~CAG_AIR_LANTERN_J_J();

	void checkDebug(bool b_Debug,
				 CString csFunctionName,
				 CStringArray* pcsaBody);

protected:

	CAG_AIR_LANTERN_J_J();

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

};// END CLASS DEFINITION CAG_AIR_LANTERN_J_J

#endif // __CAG_AIR_LANTERN_J_J__
