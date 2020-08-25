// Static Model


#ifndef __CAG_AIR_MATIP__
#define __CAG_AIR_MATIP__


// Include files
#include "CAG_AIR.h"
class CAG_AIR_MATIP : public CAG_AIR
{

public:

	void loadFunctionList(CListBox* listTranslateFunction);

	void loadLanguageList(CListBox* listTranslateLanguage);

protected:

	CAG_AIR_MATIP();

	~CAG_AIR_MATIP();

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

};// END CLASS DEFINITION CAG_AIR_MATIP

#endif // __CAG_AIR_MATIP__
