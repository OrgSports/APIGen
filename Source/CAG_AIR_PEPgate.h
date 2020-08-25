// Static Model


#ifndef __CAG_AIR_PEPGATE__
#define __CAG_AIR_PEPGATE__


// Include files
#include "CAG_AIR.h"
class CAG_AIR_PEPgate : public CAG_AIR
{

public:

	void loadFunctionList(CListBox* listTranslateFunction);

	void loadLanguageList(CListBox* listTranslateLanguage);

protected:

	CAG_AIR_PEPgate();

	~CAG_AIR_PEPgate();

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

};// END CLASS DEFINITION CAG_AIR_PEPgate

#endif // __CAG_AIR_PEPGATE__
