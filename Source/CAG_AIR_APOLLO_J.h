// Static Model


#ifndef __CAG_AIR_APOLLO_J__
#define __CAG_AIR_APOLLO_J__


// Include files
#include "CAG_AIR_APOLLO.h"
class CAG_AIR_APOLLO_J : public CAG_AIR_APOLLO
{

public:

	void checkDebug();

protected:

	CAG_AIR_APOLLO_J();

	~CAG_AIR_APOLLO_J();

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

};// END CLASS DEFINITION CAG_AIR_APOLLO_J

#endif // __CAG_AIR_APOLLO_J__
