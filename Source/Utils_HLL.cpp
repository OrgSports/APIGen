#include "stdafx.h"
#include "APIGen.h"
#include "APIGenDlg.h"

/****************************************************************************DC
	Function	:	CAPIGenDlg::LoadHLLArgumentArray()

	Purpose		:	Load the function arguments for Attachmate HLLAPI.

*****************************************************************************/
void CAPIGenDlg::LoadHLLArgumentArray( int* nFunctionPosition, BOOL bPromptForValues )
{
	CString	csFunctionName, csFunctionNum;
	
	UpdateData();
	
	*nFunctionPosition=0;

	*nFunctionPosition = m_listTranslateFunction.GetCurSel();
	m_listTranslateFunction.GetText( *nFunctionPosition, csFunctionName );

	// full function name text
	csaArguments.Add( csFunctionName );

	if ( bPromptForValues )
	{
		switch ( *nFunctionPosition )
		{
			
			case 0:     // HLL_AttachmateQuerySystem
			case 1:		// HLL_ConnectPS
			case 2:     // HLL_Convert
			case 3:     // HLL_CopyFieldToString
			case 4:     // HLL_CopyOIA
			case 5:     // HLL_CopyOIA5
			case 6:     // HLL_CopyOIA9
			case 7:     // HLL_CopyPS
			case 8:     // HLL_CopyPSToString
			case 9:     // HLL_CopyStringToField
			case 10:    // HLL_CopyStringToPS
			case 11:    // HLL_DisconnectPS
			case 12:    // HLL_EnumHLLWins
			case 13:    // HLL_FindFieldLength
			case 14:    // HLL_FindFieldPosition
			case 15:    // HLL_GetKey
			case 16:    // HLL_Pause
			case 17:    // HLL_PostInterceptStatus
			case 18:    // HLL_QueryHLLWinParameters
			case 19:    // HLL_QueryCursor
			case 20:    // HLL_QueryFieldAttribute
			case 21:    // HLL_QueryHostUpdate
			case 22:    // HLL_QuerySessions
			case 23:    // HLL_QuerySessionStatus
			case 24:    // HLL_QuerySystem
			case 25:    // HLL_ReceiveFile
			case 26:    // HLL_Release
			case 27:    // HLL_Reserve
			case 28:    // HLL_ResetHLLWin
			case 29:    // HLL_SearchField
			case 30:    // HLL_SearchPS
			case 31:    // HLL_SendFile
			case 32:    // HLL_SendKey
			case 33:    // HLL_SetCursor
			case 34:    // HLL_SetMessageLoopCallback
			case 35:    // HLL_SetHLLWinParameters
			case 36:    // HLL_StartHostNotification
			case 37:    // HLL_StartKeystrokeIntercept
			case 38:    // HLL_StopHostNotification
			case 39:    // HLL_StopKeystrokeIntercept
			case 40:    // HLL_Wait
			case 41:    // HLL_WSCtrl
			{
				csaArguments.Add( "TRUE" );
				csaArguments.Add( "TRUE" );
				csaArguments.Add( "TRUE" );
			}
			break;

				
		}
	}
	else
	{
		switch ( *nFunctionPosition )
		{
			
			case 0:     // HLL_AttachmateQuerySystem
			case 1:		// HLL_ConnectPS
			case 2:     // HLL_Convert
			case 3:     // HLL_CopyFieldToString
			case 4:     // HLL_CopyOIA
			case 5:     // HLL_CopyOIA5
			case 6:     // HLL_CopyOIA9
			case 7:     // HLL_CopyPS
			case 8:     // HLL_CopyPSToString
			case 9:     // HLL_CopyStringToField
			case 10:    // HLL_CopyStringToPS
			case 11:    // HLL_DisconnectPS
			case 12:    // HLL_EnumHLLWins
			case 13:    // HLL_FindFieldLength
			case 14:    // HLL_FindFieldPosition
			case 15:    // HLL_GetKey
			case 16:    // HLL_Pause
			case 17:    // HLL_PostInterceptStatus
			case 18:    // HLL_QueryHLLWinParameters
			case 19:    // HLL_QueryCursor
			case 20:    // HLL_QueryFieldAttribute
			case 21:    // HLL_QueryHostUpdate
			case 22:    // HLL_QuerySessions
			case 23:    // HLL_QuerySessionStatus
			case 24:    // HLL_QuerySystem
			case 25:    // HLL_ReceiveFile
			case 26:    // HLL_Release
			case 27:    // HLL_Reserve
			case 28:    // HLL_ResetHLLWin
			case 29:    // HLL_SearchField
			case 30:    // HLL_SearchPS
			case 31:    // HLL_SendFile
			case 32:    // HLL_SendKey
			case 33:    // HLL_SetCursor
			case 34:    // HLL_SetMessageLoopCallback
			case 35:    // HLL_SetHLLWinParameters
			case 36:    // HLL_StartHostNotification
			case 37:    // HLL_StartKeystrokeIntercept
			case 38:    // HLL_StopHostNotification
			case 39:    // HLL_StopKeystrokeIntercept
			case 40:    // HLL_Wait
			case 41:    // HLL_WSCtrl
			{
				csaArguments.Add( "TRUE" );
				csaArguments.Add( "TRUE" );
				csaArguments.Add( "TRUE" );
			}
			break;

				
		}
	}

}



/****************************************************************************DC
	Function	:	CAPIGenDlg::ShowHLLControls()

	Purpose		:	Show the controls for the Attachmate HLLAPI function 
					parameters.

*****************************************************************************/
void CAPIGenDlg::ShowHLLControls( int nFunction )
{
	switch ( nFunction )
	{
			case 0:     // HLL_AttachmateQuerySystem
			case 1:		// HLL_ConnectPS
			case 2:     // HLL_Convert
			case 3:     // HLL_CopyFieldToString
			case 4:     // HLL_CopyOIA
			case 5:     // HLL_CopyOIA5
			case 6:     // HLL_CopyOIA9
			case 7:     // HLL_CopyPS
			case 8:     // HLL_CopyPSToString
			case 9:     // HLL_CopyStringToField
			case 10:    // HLL_CopyStringToPS
			case 11:    // HLL_DisconnectPS
			case 12:    // HLL_EnumHLLWins
			case 13:    // HLL_FindFieldLength
			case 14:    // HLL_FindFieldPosition
			case 15:    // HLL_GetKey
			case 16:    // HLL_Pause
			case 17:    // HLL_PostInterceptStatus
			case 18:    // HLL_QueryHLLWinParameters
			case 19:    // HLL_QueryCursor
			case 20:    // HLL_QueryFieldAttribute
			case 21:    // HLL_QueryHostUpdate
			case 22:    // HLL_QuerySessions
			case 23:    // HLL_QuerySessionStatus
			case 24:    // HLL_QuerySystem
			case 25:    // HLL_ReceiveFile
			case 26:    // HLL_Release
			case 27:    // HLL_Reserve
			case 28:    // HLL_ResetHLLWin
			case 29:    // HLL_SearchField
			case 30:    // HLL_SearchPS
			case 31:    // HLL_SendFile
			case 32:    // HLL_SendKey
			case 33:    // HLL_SetCursor
			case 34:    // HLL_SetMessageLoopCallback
			case 35:    // HLL_SetHLLWinParameters
			case 36:    // HLL_StartHostNotification
			case 37:    // HLL_StartKeystrokeIntercept
			case 38:    // HLL_StopHostNotification
			case 39:    // HLL_StopKeystrokeIntercept
			case 40:    // HLL_Wait
			case 41:    // HLL_WSCtrl
		{
			m_groupNoParametersNeeded.ShowWindow( SW_SHOW  );
		}
		break;

	}

}
