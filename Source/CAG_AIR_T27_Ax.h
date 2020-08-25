// Static Model


#ifndef __CAG_AIR_T27_AX__
#define __CAG_AIR_T27_AX__


// Include files
#include "CAG_AIR_T27.h"
class CAG_AIR_T27_Ax : public CAG_AIR_T27
{

public:

	~CAG_AIR_T27_Ax();

protected:

	CAG_AIR_T27_Ax();

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

	virtual void checkDebug();

};// END CLASS DEFINITION CAG_AIR_T27_Ax

#endif // __CAG_AIR_T27_AX__
