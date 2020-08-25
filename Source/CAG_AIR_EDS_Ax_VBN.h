// Static Model


#ifndef __CAG_AIR_EDS_AX_VBN__
#define __CAG_AIR_EDS_AX_VBN__


// Include files
#include "CAG_AIR_EDS_Ax.h"
class CAG_AIR_EDS_Ax_VBN : public CAG_AIR_EDS_Ax
{

public:

	CAG_AIR_EDS_Ax_VBN();
	~CAG_AIR_EDS_Ax_VBN();

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

	void declareVariable(AG_VARIABLE agVariable,
					  CStringArray* pcsaHeader,
					  bool* bValue);

};// END CLASS DEFINITION CAG_AIR_EDS_Ax_VBN

#endif // __CAG_AIR_EDS_AX_VBN__
