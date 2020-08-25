/****************************************************************************DC
	
	Filename	:	APIGenState.h

	Purpose		:	Encapsulates the handling of the APIGen control enabling

******************************************************************************/
#if !defined(AFX_APIGEN_STATE_H__INCLUDED)
#define AFX_APIGEN_STATE_H__INCLUDED

#include <afxwin.h>                                                                   

// Note: If you add or remove an enumerated symbol below the state machine that
// controls the windows shape and control enabling will be changed in ungood ways
// You must ensure that the order these items show up in this list is the same
// order they show up in the APIGenTransitions.xls file.
typedef enum 
{
	API_START_STATE,
	DONE,
	NO_CAN_DO,

	AIRLINES_READY,
	AIRLINES_PARAM_READY,
	AIRLINES_GENERATING,

	AIR_VM_READY,
	AIR_VM_PARAM_READY,
	AIR_VM_GENERATING,

	CASL_READY,
	CASL_PARAM_READY,
	CASL_GENERATING,

	CICS_READY,
	CICS_PARAM_READY,
	CICS_GENERATING,

	DOS_READY,
	DOS_PARAM_READY,
	DOS_GENERATING,

	EAL_READY,
	EAL_PARAM_READY,
	EAL_GENERATING,

	EAOAx_READY,
	EAOAx_PARAM_READY,
	EAOAx_GENERATING,

	EAOJ_READY,
	EAOJ_PARAM_READY,
	EAOJ_GENERATING,

	EHL_READY,
	EHL_PARAM_READY,
	EHL_GENERATING,

	EOLE_READY,
	EOLE_PARAM_READY,
	EOLE_GENERATING,

	HLL_READY,
	HLL_PARAM_READY,
	HLL_GENERATING,

	IHL_READY,
	IHL_PARAM_READY,
	IHL_GENERATING,

	ITASK_READY,
	ITASK_PARAM_READY,
	ITASK_GENERATING,

	MCSAx_READY,
	MCSAx_PARAM_READY,
	MCSAx_GENERATING,

	MCSJ_READY,
	MCSJ_PARAM_READY,
	MCSJ_GENERATING,

	MSI_READY,
	MSI_PARAM_READY,
	MSI_GENERATING,

	PCS_READY,
	PCS_PARAM_READY,
	PCS_GENERATING,

	PERFORCE_READY,
	PERFORCE_PARAM_READY,
	PERFORCE_GENERATING,

	QAC_READY,
	QAC_PARAM_READY,
	QAC_GENERATING,

	RFTP_READY,
	RFTP_PARAM_READY,
	RFTP_GENERATING,

	ROLE_READY,
	ROLE_PARAM_READY,
	ROLE_GENERATING,

	RWEB_READY,
	RWEB_PARAM_READY,
	RWEB_GENERATING,

	UNIX_READY,
	UNIX_PARAM_READY,
	UNIX_GENERATING,

	VHI_READY,
	VHI_PARAM_READY,
	VHI_GENERATING,

	WHL_READY,
	WHL_PARAM_READY,
	WHL_GENERATING,

	APIGEN_STATES

}APIGenState;


// Note: If you add or remove an enumerated symbol below the state machine that
// controls the windows shape and control enabling will be changed in ungood ways
// You must ensure that the order these items show up in this list is the same
// order they show up in the APIGenTransitions.xls file.
typedef enum 
{
	PARAMETERS_CHECKBOX,
	GENERATE_BUTTON,
	APPEND_BUTTON,
	FINALIZE,
	NEW_BUTTON,
	AIR_NOW,
	AIR_VM_NOW,
	CASL_NOW,
	CICS_NOW,
	DOS_NOW,
	EAL_NOW,
	EAOAx_NOW,
	EAOJ_NOW,
	EHL_NOW,
	EOLE_NOW,
	HLL_NOW,
	IHL_NOW,
	ITASK_NOW,
	MCSAx_NOW,
	MCSJ_NOW,
	MSI_NOW,
	PCS_NOW,
	PERFORCE_NOW,
	QAC_NOW,
	RFTP_NOW,
	ROLE_NOW,
	RWEB_NOW,
	UNIX_NOW,
	VHI_NOW,
	WHL_NOW,
	APIGEN_ACTIONS

}APIGenAction;


class CAPIGenState
{

private:
	static	APIGenState	CurrentState;
	static	APIGenState	LastState;
	static	APIGenState	GenerateState;
	static APIGenAction	LastAction;

	static void ChangeState(APIGenAction);
	
	static CString ActionString(int);
	static CString StateString(int);
	static void OutputErrorMessage(APIGenAction, APIGenState);

public:
	CAPIGenState();
	~CAPIGenState();

	static void Initialize();

	static void SendAction(APIGenAction theAction);
	static APIGenAction GetLastAction();
	static APIGenState GetState();
	static APIGenState GetLastState();
	static void RenewState();


};

#endif // !defined(AFX_APIGEN_STATE_H__INCLUDED)
