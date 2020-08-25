// Static Model


#ifndef __CAG_AIR_T27_J__
#define __CAG_AIR_T27_J__


// Include files
#include "CAG_AIR_T27.h"
class CAG_AIR_T27_J : public CAG_AIR_T27
{

public:

	virtual void checkDebug();

protected:

	CAG_AIR_T27_J();

	~CAG_AIR_T27_J();

	virtual void generateHeader(CStringArray* pcsaHeader,
							 CStringArray* pcsaBody);

	virtual void appendBody(int nFunctionNum,
						 bool bPromptForValues,
						 CStringArray* pcsaArguments,
						 CStringArray* pcsaHeader,
						 CStringArray* pcsaBody);

	virtual void finalize(CStringArray* pcsaBody);

	virtual void declareVariable(AG_VARIABLE agVariable,
							  CStringArray* pcsaHeader,
							  bool* bValue);

};// END CLASS DEFINITION CAG_AIR_T27_J

#endif // __CAG_AIR_T27_J__
