/****************************************************************************DC
	
	Filename	:	APIGenState.cpp

	Purpose		:	Encapsulates the handling of the API Generator UI


******************************************************************************

******************************************************************************/
#include "stdafx.h"
#include "apigenstate.h"
#include "StateTransitions.h"
#include <fstream>
using namespace std;
//////////////////////////////////////////////////////////////////////
// CAPIGenState
//////////////////////////////////////////////////////////////////////
APIGenState		CAPIGenState::CurrentState;
APIGenState		CAPIGenState::LastState;
APIGenState		CAPIGenState::GenerateState;
APIGenAction	CAPIGenState::LastAction;

////////////////////////////////
// Construction/Destruction
////////////////////////////////


/****************************************************************************DC
	Function	:	CAPIGenState()

	Purpose		:	Constructor

	Note		:	Not sure what initialization is required.
*****************************************************************************/
CAPIGenState::CAPIGenState()
{

}


/****************************************************************************DC
	Function	:	CAPIGenState()

	Purpose		:	Destructor

	Note		:	
*****************************************************************************/
CAPIGenState::~CAPIGenState()
{
}




/****************************************************************************DC
	Function	:	Initialize()

	Purpose		:	Initializer/Reset function

	Note		:	
					
*****************************************************************************/
void CAPIGenState::Initialize()
{
	CurrentState = EHL_READY;
	LastState = API_START_STATE;
	GenerateState = API_START_STATE;
}




/****************************************************************************DC
	Function	:	ChangeState()

	Note		:	Sets the speedbar state values to what is given in the 
					parameter.
*****************************************************************************/
void CAPIGenState::ChangeState(APIGenAction theAction)
{
	if ( theAction == GENERATE_BUTTON )
	{
		GenerateState = CurrentState;
	}
	
	LastState = CurrentState;

	CurrentState = StateTransition[theAction][LastState];
}



/****************************************************************************DC
	Function	:	SendAction(APIGenAction theAction)

	Note		:	This function is the public function that handles the 
					ChangeState() private function.
					
*****************************************************************************/
void CAPIGenState::SendAction(APIGenAction theAction)
{
	ChangeState( theAction );
}



APIGenAction  CAPIGenState::GetLastAction()
{
	return LastAction;
}


APIGenState CAPIGenState::GetState()
{
	return CurrentState;
}


APIGenState CAPIGenState::GetLastState()
{
	return LastState;
}

/****************************************************************************DC
	Function	:	StateString( int )

	Purpose		:	Returns the string description of the current state.

*****************************************************************************/
CString CAPIGenState::StateString(int StateEnumValue )
{
	CString csReturn;

	switch ( StateEnumValue )
	{
		case AIRLINES_READY:
			csReturn = "AIRLINES_READY";
			break;

		case AIRLINES_PARAM_READY:
			csReturn = "AIRLINES_PARAM_READY";
			break;

		case AIRLINES_GENERATING:
			csReturn = "AIRLINES_GENERATING";
			break;

		case AIR_VM_READY:
			csReturn = "AIR_VM_READY";
			break;

		case AIR_VM_PARAM_READY:
			csReturn = "AIR_VM_PARAM_READY";
			break;

		case AIR_VM_GENERATING:
			csReturn = "AIR_VM_GENERATING";
			break;

		case CASL_READY:
			csReturn = "CASL_READY";
			break;

		case CASL_PARAM_READY:
			csReturn = "CASL_PARAM_READY";
			break;

		case CASL_GENERATING:
			csReturn = "CASL_GENERATING";
			break;

		case CICS_READY:
			csReturn = "CICS_READY";
			break;

		case CICS_PARAM_READY:
			csReturn = "CICS_PARAM_READY";
			break;

		case CICS_GENERATING:
			csReturn = "CICS_GENERATING";
			break;

		case DOS_READY:
			csReturn = "DOS_READY";
			break;

		case DOS_PARAM_READY:
			csReturn = "DOS_PARAM_READY";
			break;

		case DOS_GENERATING:
			csReturn = "DOS_GENERATING";
			break;

		case EAL_READY:
			csReturn = "EAL_READY";
			break;

		case EAL_PARAM_READY:
			csReturn = "EAL_PARAM_READY";
			break;

		case EAL_GENERATING:
			csReturn = "EAL_GENERATING";
			break;

		case EAOAx_READY:
			csReturn = "EAOAx_READY";
			break;

		case EAOAx_PARAM_READY:
			csReturn = "EAOAx_PARAM_READY";
			break;

		case EAOAx_GENERATING:
			csReturn = "EAOAx_GENERATING";
			break;
		

		case EAOJ_READY:
			csReturn = "EAOJ_READY";
			break;
		
		case EAOJ_PARAM_READY:
			csReturn = "EAOJ_PARAM_READY";
			break;

		case EAOJ_GENERATING:
			csReturn = "EAOJ_GENERATING";
			break;


		case EHL_READY:
			csReturn = "EHL_READY";
			break;
		
		case EHL_PARAM_READY:
			csReturn = "EHL_PARAM_READY";
			break;

		case EHL_GENERATING:
			csReturn = "EHL_GENERATING";
			break;

		case EOLE_READY:
			csReturn = "EOLE_READY";
			break;

		case EOLE_PARAM_READY:
			csReturn = "EOLE_PARAM_READY";
			break;

		case EOLE_GENERATING:
			csReturn = "EOLE_GENERATING";
			break;

		case HLL_READY:
			csReturn = "HLL_READY";
			break;

		case HLL_PARAM_READY:
			csReturn = "HLL_PARAM_READY";
			break;

		case HLL_GENERATING:
			csReturn = "HLL_GENERATING";
			break;

		case IHL_READY:
			csReturn = "IHL_READY";
			break;

		case IHL_PARAM_READY:
			csReturn = "IHL_PARAM_READY";
			break;

		case IHL_GENERATING:
			csReturn = "IHL_GENERATING";
			break;

		case MCSAx_READY:
			csReturn = "MCSAx_READY";
			break;

		case MCSAx_PARAM_READY:
			csReturn = "MCSAx_PARAM_READY";
			break;

		case MCSAx_GENERATING:
			csReturn = "MCSAx_GENERATING";
			break;

		case MCSJ_READY:
			csReturn = "MCSJ_READY";
			break;

		case MCSJ_PARAM_READY:
			csReturn = "MCSJ_PARAM_READY";
			break;

		case MCSJ_GENERATING:
			csReturn = "MCSJ_GENERATING";
			break;

		case PCS_READY:
			csReturn = "PCS_READY";
			break;

		case PCS_PARAM_READY:
			csReturn = "PCS_PARAM_READY";
			break;

		case PCS_GENERATING:
			csReturn = "PCS_GENERATING";
			break;

		case PERFORCE_READY:
			csReturn = "PERFORCE_READY";
			break;

		case PERFORCE_PARAM_READY:
			csReturn = "PERFORCE_PARAM_READY";
			break;

		case PERFORCE_GENERATING:
			csReturn = "PERFORCE_GENERATING";
			break;

		case QAC_READY:
			csReturn = "QAC_READY";
			break;

		case QAC_PARAM_READY:
			csReturn = "QAC_PARAM_READY";
			break;

		case QAC_GENERATING:
			csReturn = "QAC_GENERATING";
			break;

		case RFTP_READY:
			csReturn = "RFTP_READY";
			break;

		case RFTP_PARAM_READY:
			csReturn = "RFTP_PARAM_READY";
			break;

		case RFTP_GENERATING:
			csReturn = "RFTP_GENERATING";
			break;

		case ROLE_READY:
			csReturn = "ROLE_READY";
			break;

		case ROLE_PARAM_READY:
			csReturn = "ROLE_PARAM_READY";
			break;

		case ROLE_GENERATING:
			csReturn = "ROLE_GENERATING";
			break;

		case RWEB_READY:
			csReturn = "RWEB_READY";
			break;

		case RWEB_PARAM_READY:
			csReturn = "RWEB_PARAM_READY";
			break;

		case RWEB_GENERATING:
			csReturn = "RWEB_GENERATING";
			break;

		case UNIX_READY:
			csReturn = "UNIX_READY";
			break;

		case UNIX_PARAM_READY:
			csReturn = "UNIX_PARAM_READY";
			break;

		case UNIX_GENERATING:
			csReturn = "UNIX_GENERATING";
			break;
	
		case WHL_READY:
			csReturn = "WHL_READY";
			break;

		case WHL_PARAM_READY:
			csReturn = "WHL_PARAM_READY";
			break;

		case WHL_GENERATING:
			csReturn = "WHL_GENERATING";
			break;


		case NO_CAN_DO:
			csReturn = "NO_CAN_DO";
			break;

		case API_START_STATE:
			csReturn = "API_START_STATE";
			break;

		case DONE:
			csReturn = "DONE";
			break;
	
	}

	return csReturn;
}


/****************************************************************************DC
	Function	:	ActionString(int )

	Purpose		:	Returns the string description of the action currently
					being handled.

*****************************************************************************/
CString CAPIGenState::ActionString(int ActionEnumValue )
{
	CString csReturn("No Known Action");

	switch ( ActionEnumValue )
	{

		case PARAMETERS_CHECKBOX:
			csReturn = "PARAMETERS_CHECKBOX";
			break;
		case GENERATE_BUTTON:
			csReturn = "GENERATE_BUTTON";
			break;
		case APPEND_BUTTON:
			csReturn = "APPEND_BUTTON";
			break;
		case FINALIZE:
			csReturn = "FINALIZE";
			break;
		case NEW_BUTTON:
			csReturn = "NEW_BUTTON";
			break;

		case AIR_NOW:
			csReturn = "AIR_NOW";
			break;

		case AIR_VM_NOW:
			csReturn = "AIR_VM_NOW";
			break;

		case CASL_NOW:
			csReturn = "CASL_NOW";
			break;

		case DOS_NOW:
			csReturn = "DOS_NOW";
			break;

		case EAL_NOW:
			csReturn = "EAL_NOW";
			break;

		case EAOAx_NOW:
			csReturn = "EAOAx_NOW";
			break;

		case EAOJ_NOW:
			csReturn = "EAOJ_NOW";
			break;

		case EHL_NOW:
			csReturn = "EHL_NOW";
			break;

		case EOLE_NOW:
			csReturn = "EOLE_NOW";
			break;

		case HLL_NOW:
			csReturn = "HLL_NOW";
			break;

		case IHL_NOW:
			csReturn = "IHL_NOW";
			break;

		case ITASK_NOW:
			csReturn = "ITASK_NOW";
			break;

		case MCSAx_NOW:
			csReturn = "MCSAx_NOW";
			break;

		case MCSJ_NOW:
			csReturn = "MCSJ_NOW";
			break;

		case MSI_NOW:
			csReturn = "MSI_NOW";
			break;

		case PCS_NOW:
			csReturn = "PCS_NOW";
			break;

		case QAC_NOW:
			csReturn = "QAC_NOW";
			break;

		case RFTP_NOW:
			csReturn = "RFTP_NOW";
			break;

		case ROLE_NOW:
			csReturn = "ROLE_NOW";
			break;

		case UNIX_NOW:
			csReturn = "UNIX_NOW";
			break;

		case WHL_NOW:
			csReturn = "WHL_NOW";
			break;

	}

	return csReturn;
}


/****************************************************************************DC
	Function	:	OutputErrorMessage( APIGenAction, APIGenState )

	Purpose		:	Dumps unexpected action/state change info to a log file
					written to the working directory when a registry value named
					"LogAPIGenState" is set nonzero in 
					HKLM\SOFTWARE\Attachmate\APIGen\Settings.

*****************************************************************************/
void CAPIGenState::OutputErrorMessage( APIGenAction theAction, APIGenState theState )
{
	// obtain the date and time info for use in naming the output file
	// and labeling the output in the file
	SYSTEMTIME	systime;
	GetSystemTime(&systime);
	time_t osBinaryTime;
	time( &osBinaryTime ) ;
	CTime t( osBinaryTime );
	
	int nMonth = t.GetMonth();
	int nDay = t.GetDay();
	int nYear = t.GetYear();
	int nHour = t.GetHour();
	int nMinute = t.GetMinute();
	int nSecond = t.GetSecond();
	
	CString csDateTimeInfo;
	csDateTimeInfo.Format(_T("\n%i/%02i/%02i  %i:%02i:%02i\n"), nMonth,nDay,nYear,nHour,nMinute,nSecond);

	CString csStateChangeInfo;
	csStateChangeInfo.Format(_T("Unexpected state transition\nInitial state - %s\nAction - %s\n"),
							StateString( theState ), ActionString( theAction ));

	CString csLogFileName;
	csLogFileName.Format(_T("APIGen%i%i%i.txt"), nMonth, nDay, nYear);

	// open the file
	ofstream outfile(csLogFileName, ios::app);

	// output to the file	
	outfile << csDateTimeInfo << csStateChangeInfo;

}


void CAPIGenState::RenewState()
{
	CurrentState = GenerateState;
	/*
	switch ( GenerateState )
	{

		case EAL_READY:
		case EAL_PARAM_READY:
			CurrentState = EAL_READY;
			break;
			
		case COOLTOOL_READY:
		case COOLTOOL_PARAM_READY:
			CurrentState = COOLTOOL_READY;
			break;

		case EAOAx_READY:
		case EAOAx_PARAM_READY:
			CurrentState = EAOAx_READY;
			break;
		
		case EAOJ_READY:
		case EAOJ_PARAM_READY:
			CurrentState = EAOJ_READY;
			break;

		case EHL_READY:
			CurrentState = EHL_READY;
			break;

		case EHL_PARAM_READY:
			CurrentState = EHL_PARAM_READY;
			break;

		case HLL_READY:
		case HLL_PARAM_READY:
			CurrentState = HLL_READY;
			break;

		case IHL_READY:
			CurrentState = IHL_READY;
			break;

		case IHL_PARAM_READY:
			CurrentState = IHL_PARAM_READY;
			break;

		case OLE_READY:
		case OLE_PARAM_READY:
			CurrentState = OLE_READY;
			break;

		case PCS_READY:
		case PCS_PARAM_READY:
			CurrentState = PCS_READY;
			break;

		case QAC_READY:
		case QAC_PARAM_READY:
			CurrentState = QAC_READY;
			break;

		case WHL_READY:
			CurrentState = WHL_READY;
			break;

		case WHL_PARAM_READY:
			CurrentState = WHL_PARAM_READY;
			break;
			
	}
	*/

	LastState = DONE;

}
