// Model


#ifndef __CAG_EAOAX_5250_CS__
#define __CAG_EAOAX_5250_CS__


// Include files
#include "CAG_EAOAx_5250.h"
class CAG_EAOAx_5250_CS : public CAG_EAOAx_5250
{

public:

	CAG_EAOAx_5250_CS();

	~CAG_EAOAx_5250_CS();

	void declareVariable(AG_VARIABLE agVariable,
					  CStringArray* pcsaHeader,
					  bool* bValue);

	void checkDebug(bool b_Debug,
				 CString csFunctionName,
				 CStringArray* pcsaBody);

	void resetVariableFlags();

protected:

	void generateHeader(CStringArray* pcsaHeader,
					 CStringArray* pcsaBody);

	void appendBody(int nFunctionNum,
				 bool bPromptForValues,
				 CStringArray* pcsaArguments,
				 CStringArray* pcsaHeader,
				 CStringArray* pcsaBody);

	void finalize(CStringArray* pcsaBody);

private:
	bool b_nHRESULT;
	bool b_nFLAG;
	bool b_nATMFT;

	bool b_Debug;

};// END CLASS DEFINITION CAG_EAOAx_5250_CS

#endif // __CAG_EAOAX_5250_CS__
