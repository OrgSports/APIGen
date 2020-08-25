// Static Model


#ifndef __CAG_AIR_VM_T27__
#define __CAG_AIR_VM_T27__


// Include files
#include "CAG_AIR_VM.h"
class CAG_AIR_VM_T27 : public CAG_AIR_VM
{

public:

	void loadFunctionList(CListBox* listTranslateFunction);

protected:

	CAG_AIR_VM_T27();

	~CAG_AIR_VM_T27();

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

};// END CLASS DEFINITION CAG_AIR_VM_T27

#endif // __CAG_AIR_VM_T27__
