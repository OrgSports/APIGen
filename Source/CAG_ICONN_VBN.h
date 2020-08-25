// Static Model


#ifndef __CAG_ICONN_VBN__
#define __CAG_ICONN_VBN__


// Include files
#include "CAG_ICONN.h"
class CAG_ICONN_VBN : public CAG_ICONN
{

public:

	CAG_ICONN_VBN();

	~CAG_ICONN_VBN();

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

};// END CLASS DEFINITION CAG_ICONN_VBN

#endif // __CAG_ICONN_VBN__
