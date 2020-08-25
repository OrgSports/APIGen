// Static Model


#ifndef __CAG_ITASK_JAVA__
#define __CAG_ITASK_JAVA__


// Include files
#include "CAG_ITASK.h"
class CAG_ITASK_JAVA : public CAG_ITASK
{

public:

	CAG_ITASK_JAVA();

	~CAG_ITASK_JAVA();

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
	bool b_csVersion;
	bool b_nPageNum;

	CStringArray csaITaskListeners;
	CStringArray csaITaskLocales;
	CStringArray csaITaskContexts;

};// END CLASS DEFINITION CAG_ITASK_JAVA

#endif // __CAG_ITASK_JAVA__
