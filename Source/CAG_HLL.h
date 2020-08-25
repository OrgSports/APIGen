// Static Model


#ifndef __CAG_HLL__
#define __CAG_HLL__
#include "cag.h"

class CAG_HLL : public CAG
{

private:

	bool b_ATMSYSTEM;

	bool b_SESS_STATUS;

	bool b_wRowColFlag;

	bool b_ptPosition;

	bool b_wLength;

	bool b_wPosition;

	bool b_wFieldSpecifier;

	bool b_pKeystroke;

	bool b_wType;

	bool b_HLLParams;

	bool b_wNumber;

	bool b_Sessions;

	bool b_ATMSystem;

	bool b_wSequenceID;

	bool b_msgFileTransferComplete;

	bool b_StartIntercept;

	bool b_pUtilityBuffer;

public:

	~CAG_HLL();

	void loadFunctionList(CListBox* listTranslateFunction);
	void loadLanguageList(CListBox* listTranslateLanguage);
	void loadTerminalTypeList(CListBox* listTerminalTypes);

protected:

	CAG_HLL();

};// END CLASS DEFINITION CAG_HLL

#endif // __CAG_HLL__
