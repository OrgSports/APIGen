// Static Model


#ifndef __CAG_AIR_EDS_J__
#define __CAG_AIR_EDS_J__


// Include files
#include "CAG_AIR_EDS.h"
class CAG_AIR_EDS_J : public CAG_AIR_EDS
{

public:

	void checkDebug();

protected:

	CAG_AIR_EDS_J();

	~CAG_AIR_EDS_J();

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

};// END CLASS DEFINITION CAG_AIR_EDS_J

#endif // __CAG_AIR_EDS_J__
