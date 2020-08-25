// Static Model


#ifndef __CAG_ITASK_ASP__
#define __CAG_ITASK_ASP__


// Include files
#include "CAG_ITASK.h"
class CAG_ITASK_ASP : public CAG_ITASK
{

public:

	CAG_ITASK_ASP();

	~CAG_ITASK_ASP();

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
	bool b_Debug;

	bool b_itListener;
	bool b_itSource;
	bool b_csName;
	bool b_itLocale;
	bool b_nContext;
	bool b_csResourceName;
	bool b_itStatusChangeEvent;
	bool b_lTimeout;

};// END CLASS DEFINITION CAG_ITASK_ASP

#endif // __CAG_ITASK_ASP__
