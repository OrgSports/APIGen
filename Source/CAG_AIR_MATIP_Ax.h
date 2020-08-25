// Static Model


#ifndef __CAG_AIR_MATIP_AX__
#define __CAG_AIR_MATIP_AX__


// Include files
#include "CAG_AIR_MATIP.h"
class CAG_AIR_MATIP_Ax : public CAG_AIR_MATIP
{

public:

	CAG_AIR_MATIP_Ax();
	~CAG_AIR_MATIP_Ax();

	void checkDebug();

protected:

	void appendBody(int nFunctionNum,
				 bool bPromptForValues,
				 CStringArray* pcsaArguments,
				 CStringArray* pcsaHeader,
				 CStringArray* pcsaBody);

	void finalize(CStringArray* pcsaBody);

	void declareVariable(AG_VARIABLE agVariable,
					  CStringArray* pcsaHeader,
					  bool* bValue);

};// END CLASS DEFINITION CAG_AIR_MATIP_Ax

#endif // __CAG_AIR_MATIP_AX__
