// Static Model


#ifndef __CAG_AIR_3270__
#define __CAG_AIR_3270__


// Include files
#include "CAG_AIR.h"
class CAG_AIR_3270 : public CAG_AIR
{

public:

	void loadFunctionList(CListBox* listTranslateFunction);

protected:

	CAG_AIR_3270();

	~CAG_AIR_3270();

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

};// END CLASS DEFINITION CAG_AIR_3270

#endif // __CAG_AIR_3270__
