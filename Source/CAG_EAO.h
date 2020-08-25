// Static Model


#ifndef __CAG_EAO__
#define __CAG_EAO__
#include "cag.h"

class CAG_EAO : public CAG
{

protected:

	bool b_pOIAObject;

	bool b_nStatus;

	bool b_nType;

	bool b_cText;

	bool b_nCount;

	bool b_nColumn;

	bool b_nRow;

	bool b_bEABs;

	bool b_nCharSet;

	bool b_nHostCodePage;

	bool b_bKeyboardLocked;

	bool b_nModel;

	bool b_nLength;

	bool b_cString;

	bool b_nIdleTime;

	bool b_bAttached;

	bool b_csName;

	bool b_Terminal;

	bool b_nMode;

	bool b_nWait;

	bool b_bConnected;

	bool b_ConnectionObj;

	bool b_ScreenObj;

	bool b_nState;

	bool b_nPort;

	bool b_Debug;

public:

	CAG_EAO();
	~CAG_EAO();

	virtual void declareVariable(AG_VARIABLE agVariable,
							  CStringArray* pcsaHeader,
							  bool* bValue);

protected:

	void loadTerminalTypeList(CListBox* listTerminalTypes);

};// END CLASS DEFINITION CAG_EAO

#endif // __CAG_EAO__
