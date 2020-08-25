// Static Model


#ifndef __CAG_AIR_VM_3270_J__
#define __CAG_AIR_VM_3270_J__


// Include files
#include "CAG_AIR_VM_3270.h"
#include "AIRVM3270.h"

class CAG_AIR_VM_3270_J : public CAG_AIR_VM_3270
{

public:

	CAG_AIR_VM_3270_J();

	~CAG_AIR_VM_3270_J();

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

private:

	CAIRVM3270 Air3270HostnameDlg;
	bool	b_bAttached;
	bool	b_bConnected;
	bool	b_bCaptureData;
	bool	b_bTextDisplay;
	bool	b_bEABs;
	bool	b_bFill;
	bool	b_bKeyboardLocked;
	bool	b_bRet;
	bool	b_bWrap;
	bool	b_ConnectionObj;
	bool	b_csName;
	bool	b_cString;
	bool	b_cText;
	bool	b_csPassword;
	bool	b_csServer;
	bool	b_csUserID;
	bool	b_csWebView;
	bool	b_Debug;
	bool	b_isUPG;
	bool	b_miVariable1;
	bool	b_miVariable2;
	bool	b_miVariable3;
	bool	b_miVariable4;
	bool	b_miVariable5;
	bool	b_nAttribute;
	bool	b_nBuffer;
	bool	b_nBufferSize;
	bool	b_nCharSet;
	bool	b_nColumn;
	bool	b_nCount;
	bool	b_nDirection;
	bool	b_nEndColumn;
	bool	b_nEndRow;
	bool	b_nHostCodePage;
	bool	b_nIDCount;
	bool	b_nIDIncrement;
	bool	b_csIDManagerAddress;
	bool	b_nIdleTime;
	bool	b_nIndex;
	bool	b_nLength;
	bool	b_nMode;
	bool	b_nModel;
	bool	b_nOutAttribute;
	bool	b_nOutColumn;
	bool	b_nOutLength;
	bool	b_nOutRow;
	bool	b_nPort;
	bool	b_nRow;
	bool	b_nSettleTime;
	bool	b_nState;
	bool	b_nStatus;
	bool	b_nTimeout;
	bool	b_nType;
	bool	b_nValue;
	bool	b_nWait;
	bool	b_pOIAObject;
	bool	b_ScreenObj;
	bool	b_slScreenListener;
	bool	b_Terminal;
};// END CLASS DEFINITION CAG_AIR_VM_3270_J

#endif // __CAG_AIR_VM_3270_J__
