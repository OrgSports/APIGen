// Static Model


#ifndef __CAG_ICONN_ASP__
#define __CAG_ICONN_ASP__


// Include files
#include "CAG_ICONN.h"
class CAG_ICONN_ASP : public CAG_ICONN
{

public:

	CAG_ICONN_ASP();

	~CAG_ICONN_ASP();

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
	bool	b_csTaskID;
	bool	b_csBuffer;
	bool	b_nBufferSize;
	bool	b_nBuffer;
	bool	b_XMLData;
	bool	b_nMaxSize;
	bool	b_nTimeout;
	bool	b_csPath;
	bool	b_csDataRef;

};// END CLASS DEFINITION CAG_ICONN_ASP

#endif // __CAG_ICONN_ASP__
