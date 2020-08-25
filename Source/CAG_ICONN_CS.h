// Static Model


#ifndef __CAG_ICONN_CS__
#define __CAG_ICONN_CS__


// Include files
#include "CAG_ICONN.h"
class CAG_ICONN_CS : public CAG_ICONN
{

public:

	CAG_ICONN_CS();

	~CAG_ICONN_CS();

	void declareVariable(AG_VARIABLE agVariable,
					  CStringArray* pcsaHeader,
					  bool* bValue);

	void checkDebug(bool b_Debug,
				 CString csFunctionName,
				 CStringArray* pcsaBody);

private:

	void generateHeader(CStringArray* csaHeader,
					 CStringArray* csaBody);

	void appendBody(int nFunctionNum,
				 bool bPromptForValues,
				 CStringArray* csaArguments,
				 CStringArray* csaHeader,
				 CStringArray* csaBody);

	void finalize(CStringArray* pcsaBody);

};// END CLASS DEFINITION CAG_ICONN_CS

#endif // __CAG_ICONN_CS__
