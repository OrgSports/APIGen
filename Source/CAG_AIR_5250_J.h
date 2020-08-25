// Static Model


#ifndef __CAG_AIR_5250_J__
#define __CAG_AIR_5250_J__


// Include files
#include "CAG_AIR_5250.h"
class CAG_AIR_5250_J : public CAG_AIR_5250
{

public:

	CAG_AIR_5250_J();
	~CAG_AIR_5250_J();

	void checkDebug();

protected:


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

};// END CLASS DEFINITION CAG_AIR_5250_J

#endif // __CAG_AIR_5250_J__
