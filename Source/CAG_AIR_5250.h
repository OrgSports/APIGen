// Static Model


#ifndef __CAG_AIR_5250__
#define __CAG_AIR_5250__

// Include files
#include "CAG_AIR.h"

class CAG_AIR_5250 : public CAG_AIR
{

public:

	CAG_AIR_5250();
	~CAG_AIR_5250();

	void loadFunctionList(CListBox* listTranslateFunction);

	void loadLanguageList(CListBox* listTranslateLanguage);

protected:

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

};// END CLASS DEFINITION CAG_AIR_5250

#endif // __CAG_AIR_5250__
