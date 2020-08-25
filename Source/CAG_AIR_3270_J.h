// Model


#ifndef __CAG_AIR_3270_J__
#define __CAG_AIR_3270_J__

// Include files
#include "CAG_AIR_3270.h"

class CAG_AIR_3270_J : public CAG_AIR_3270
{

public:

	CAG_AIR_3270_J();
	~CAG_AIR_3270_J();

	void checkDebug();


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

private:
	BOOL	b_pOIAObject;
	BOOL	b_nStatus;
	BOOL	b_nType;
	BOOL	b_cText;
	BOOL	b_nCount;
	BOOL	b_nColumn;
	BOOL	b_nRow;
	BOOL	b_bEABs;
	BOOL	b_nCharSet;
	BOOL	b_nHostCodePage;
	BOOL	b_bKeyboardLocked;
	BOOL	b_nModel;
	BOOL	b_nLength;
	BOOL	b_cString;
	BOOL	b_nIdleTime;
	BOOL	b_bAttached;

	// new stuff 012605
	BOOL b_csName;
	BOOL b_Terminal;
	BOOL b_nMode;
	BOOL b_nWait;
	BOOL b_bConnected;
	BOOL b_ConnectionObj;
	BOOL b_ScreenObj;
	BOOL b_nState;
	BOOL b_nPort;

	BOOL b_Debug;
	BOOL b_slScreenListener;

};// END CLASS DEFINITION CAG_AIR_3270_J

#endif // __CAG_AIR_3270_J__
