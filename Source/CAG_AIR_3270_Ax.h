// Static Model


#ifndef __CAG_AIR_3270_AX__
#define __CAG_AIR_3270_AX__


// Include files
#include "CAG_AIR_3270.h"
class CAG_AIR_3270_Ax : public CAG_AIR_3270
{

public:

	CAG_AIR_3270_Ax();

	virtual void checkDebug();

protected:

	~CAG_AIR_3270_Ax();

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

};// END CLASS DEFINITION CAG_AIR_3270_Ax

#endif // __CAG_AIR_3270_AX__
