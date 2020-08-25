// Static Model


#ifndef __CAG_ICONN_WS__
#define __CAG_ICONN_WS__


// Include files
#include "CAG_ICONN.h"
class CAG_ICONN_WS : public CAG_ICONN
{

public:

	CAG_ICONN_WS();

	~CAG_ICONN_WS();

	void declareVariable(AG_VARIABLE agVariable,
					  CStringArray* pcsaHeader,
					  bool* bValue);

	void checkDebug(bool b_Debug,
				 CString csFunctionName,
				 CStringArray* pcsaBody);

	void resetVariableFlags();

private:

	void generateHeader(CStringArray* csaHeader,
					 CStringArray* csaBody);

	void appendBody(int nFunctionNum,
				 bool bPromptForValues,
				 CStringArray* csaArguments,
				 CStringArray* csaHeader,
				 CStringArray* csaBody);

	void finalize(CStringArray* pcsaBody);

private:
	bool	b_Debug;
	bool	b_nTaskID;
	bool	b_nBuffer;
	bool	b_nBufferSize;

};// END CLASS DEFINITION CAG_ICONN_WS

#endif // __CAG_ICONN_WS__
