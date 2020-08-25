// Static Model


#ifndef __CAG_AIR_LANTERN_AX__
#define __CAG_AIR_LANTERN_AX__


// Include files
#include "CAG_AIR_LANTERN.h"
class CAG_AIR_LANTERN_Ax : public CAG_AIR_LANTERN
{

public:

	void checkDebug();

protected:

	CAG_AIR_LANTERN_Ax();

	~CAG_AIR_LANTERN_Ax();

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

};// END CLASS DEFINITION CAG_AIR_LANTERN_Ax

#endif // __CAG_AIR_LANTERN_AX__
