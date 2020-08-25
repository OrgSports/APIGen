// Static Model


#ifndef __CAG_AIR_APOLLO_AX__
#define __CAG_AIR_APOLLO_AX__


// Include files
#include "CAG_AIR_APOLLO.h"
class CAG_AIR_APOLLO_Ax : public CAG_AIR_APOLLO
{

public:

	void checkDebug();

protected:

	CAG_AIR_APOLLO_Ax();

	~CAG_AIR_APOLLO_Ax();

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

};// END CLASS DEFINITION CAG_AIR_APOLLO_Ax

#endif // __CAG_AIR_APOLLO_AX__
