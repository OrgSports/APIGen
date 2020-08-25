// Static Model


#ifndef __CAG_MSI_DBASE_VBS__
#define __CAG_MSI_DBASE_VBS__


// Include files
#include "CAG_ICONN.h"
class CAG_MSI_DBASE_VBS : public CAG_ICONN
{

public:

	CAG_MSI_DBASE_VBS();

	~CAG_MSI_DBASE_VBS();

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

	void loadLanguageList(CListBox* listTranslateLanguage);

	void loadTerminalTypeList(CListBox* listTerminalTypes);

	void loadFunctionList(CListBox* listTranslateFunction);

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

};// END CLASS DEFINITION CAG_MSI_DBASE_VBS

#endif // __CAG_MSI_DBASE_VBS__
