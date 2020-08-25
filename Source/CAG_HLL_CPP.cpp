// Static Model
#include "stdafx.h"
#include "apigen.h"

#include "CAG_HLL_CPP.h"

/////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////

CAG_HLL_CPP::CAG_HLL_CPP()
{
	resetVariableFlags();	
}

CAG_HLL_CPP::~CAG_HLL_CPP()
{
	
}


/////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////

void CAG_HLL_CPP::generateHeader(CStringArray* pcsaHeader,
								 CStringArray* pcsaBody)
{
	// output to Translator's output window
	CString csViewOutStuff;
	csViewOutStuff.Format( "%s", "// ****************************************************************************");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "//   Attachmate APIGen C++ Attachmate HLLAPI Application");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "//   For demonstration purposes, this file contains a function that is intended");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "//   to be dropped into a MFC dialog application.  If the OnInitDialog function");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "//   shown below is copied over the one generated in the dialog class of a newly");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "//   generated MFC dialog application, the application should compile and run as-is.");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "//   Before compiling, be sure to move the line, #include hllapi.h, to" );
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "//   the top of your dialog class file.");
	pcsaHeader->Add(csViewOutStuff);

	time_t ltime;
	time( &ltime );

	csViewOutStuff.Format( "//");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "//   Generated:   %s", ctime( &ltime ) );
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "//");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "// ****************************************************************************");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "#include hllapi.h");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( " " );
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "bool CEALDlg::OnInitDialog()" );
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "{" );
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "     CDialog::OnInitDialog();");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( " " );
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "     SetIcon(m_hIcon, TRUE);     // Set big icon");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "     SetIcon(m_hIcon, FALSE);    // Set small icon");
	pcsaHeader->Add(csViewOutStuff);
	
	csViewOutStuff.Format( " " );
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "     HWND Handle;;");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "     char cSession;");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "     WORD   wRc;");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( "     DWORD   dwRc;");
	pcsaHeader->Add(csViewOutStuff);

	csViewOutStuff.Format( " " );
	pcsaBody->Add(csViewOutStuff);

	csViewOutStuff.Format( "     // ***************************************************************");
	pcsaBody->Add(csViewOutStuff);

	csViewOutStuff.Format( " " );
	pcsaBody->Add(csViewOutStuff);

	csViewOutStuff.Format( "     CWnd* pCWnd =  AfxGetMainWnd( );");
	pcsaBody->Add(csViewOutStuff);

	csViewOutStuff.Format( "     Handle = pCWnd->m_hWnd;");
	pcsaBody->Add(csViewOutStuff);

	csViewOutStuff.Format( " " );
	pcsaBody->Add(csViewOutStuff);

}



void CAG_HLL_CPP::appendBody(int nFunctionNum,
							 bool bPromptForValues,
							 CStringArray* pcsaArguments,
							 CStringArray* pcsaHeader,
							 CStringArray* pcsaBody)
{
	CString csViewOutStuff;
	CString csFunctionName, csFunctionNum, csString, csStringLength, csRetCode;

	csFunctionName = pcsaArguments->GetAt( 0 );

	csViewOutStuff.Format( " " );
	pcsaBody->Add(csViewOutStuff);

	csViewOutStuff.Format( "%s%s", "     // *** ", csFunctionName );
	pcsaBody->Add(csViewOutStuff);

	CString	csLocal;

	switch ( nFunctionNum )
	{
		case 0:	// HLL_AttachmateQuerySystem
		{
			if ( !b_ATMSYSTEM )
			{
				declareVariable( AG_ATM_SYSTEM, pcsaHeader, &b_ATMSYSTEM );
			}

			csViewOutStuff.Format( "     wRc = %s( Handle, &ATMSys );", csFunctionName );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( " ");
			pcsaBody->Add(csViewOutStuff);
		}
		break;


		case 1:		// HLL_ConnectPS
		case 38:	// HLL_StopHostNotification
		case 39:	// HLL_StopKeystrokeIntercept
		{
			csViewOutStuff.Format( "%s", "     cSession ='A';");
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "%s%s%s", "     wRc = ", csFunctionName, "( Handle, &cSession );");
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( " ");
			pcsaBody->Add(csViewOutStuff);
		}
		break;


		case 2:		// HLL_Convert
		{
			if ( !b_wRowColFlag )
			{
				declareVariable( AG_ROWCOL_FLAG, pcsaHeader, &b_wRowColFlag );
			}

			if ( !b_ptPosition )
			{
				declareVariable( AG_POINT_POSITION, pcsaHeader, &b_ptPosition );
			}
			
			csViewOutStuff.Format( "%s", "     cSession ='A';");
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "%s", "     wRowColFlag = HLL_CONVERTROWCOLUMN;");
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "%s", "     ptPosition.y = 20;");
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "%s", "     ptPosition.x = 17;");
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "%s%s%s", "     wRc = ", csFunctionName, "( Handle, &cSession, wRowColFlag, &ptPosition );");
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( " ");
			pcsaBody->Add(csViewOutStuff);
		}
		break;


		case 3:		// HLL_CopyFieldToString
		{
			
			if ( !b_pUtilityBuffer )
			{
				declareVariable( AG_UTILBUFFER, pcsaHeader, &b_pUtilityBuffer );
			}
			else
			{
				csLocal.Format( "    free( pUtilityBuffer );");
				pcsaBody->Add(csLocal);
			}

			if ( !b_wLength )
			{
				declareVariable( AG_LENGTH, pcsaHeader, &b_wLength );
			}
			
			if ( !b_wPosition )
			{
				declareVariable( AG_POSITION, pcsaHeader, &b_wPosition );
			}


			csViewOutStuff.Format( "     wLength=10;");
			pcsaBody->Add(csViewOutStuff);
			csViewOutStuff.Format( "     pUtilityBuffer = (char *)malloc( wLength );");
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "     wPosition = 1537;");
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "     wRc = %s( Handle, pUtilityBuffer, wLength, wPosition );", csFunctionName );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( " ");
			pcsaBody->Add(csViewOutStuff);
		}
		break;




		case 4:		// HLL_CopyOIA
		case 5:		// HLL_CopyOIA5
		case 6:		// HLL_CopyOIA9
		{
			
			if ( !b_pUtilityBuffer )
			{
				declareVariable( AG_UTILBUFFER, pcsaHeader, &b_pUtilityBuffer );
			}
			else
			{
				csLocal.Format( "    free( pUtilityBuffer );");
				pcsaBody->Add(csLocal);
			}

			csViewOutStuff.Format( "%s", "     pUtilityBuffer = (char *)malloc( 105 );");
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "%s", "     memset( pUtilityBuffer, '\\0', 105 );");
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "%s%s%s", "     wRc = ", csFunctionName, "( Handle, pUtilityBuffer );");
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( " ");
			pcsaBody->Add(csViewOutStuff);
		}
		break;



		case 7:		// HLL_CopyPS
		{
			
			if ( !b_pUtilityBuffer )
			{
				declareVariable( AG_UTILBUFFER, pcsaHeader, &b_pUtilityBuffer );
			}
			else
			{
				csLocal.Format( "    free( pUtilityBuffer );");
				pcsaBody->Add(csLocal);
			}

			csViewOutStuff.Format( "%s", "     pUtilityBuffer = (char *)malloc( 1921 );");
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "%s", "     memset( pUtilityBuffer, '\\0', 1921 );");
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "%s%s%s", "     wRc = ", csFunctionName, "( Handle, pUtilityBuffer );");
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( " ");
			pcsaBody->Add(csViewOutStuff);
		}
		break;



		case 8:		// HLL_CopyPSToString
		{
			
			if ( !b_pUtilityBuffer )
			{
				declareVariable( AG_UTILBUFFER, pcsaHeader, &b_pUtilityBuffer );
			}
			else
			{
				csLocal.Format( "    free( pUtilityBuffer );");
				pcsaBody->Add(csLocal);
			}

			if ( !b_wLength )
			{
				declareVariable( AG_LENGTH, pcsaHeader, &b_wLength );
			}
			
			if ( !b_wPosition )
			{
				declareVariable( AG_POSITION, pcsaHeader, &b_wPosition );
			}


			csViewOutStuff.Format( "%s", "     wLength=10;");
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "%s", "     pUtilityBuffer = (char *)malloc( wLength );");
			pcsaBody->Add(csViewOutStuff);
			csViewOutStuff.Format( "%s", "     memset( pUtilityBuffer, '\\0', wLength );");
			pcsaBody->Add(csViewOutStuff);


			csViewOutStuff.Format( "%s", "     wPosition = 1530;");
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "%s%s%s", "     wRc = ", csFunctionName, "( Handle, pUtilityBuffer, wLength, wPosition );");
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( " ");
			pcsaBody->Add(csViewOutStuff);
		}
		break;



		case 9:		// HLL_CopyStringToField
		case 10:	// HLL_CopyStringToPS
		{
			
			if ( !b_pUtilityBuffer )
			{
				declareVariable( AG_UTILBUFFER, pcsaHeader, &b_pUtilityBuffer );
			}
			else
			{
				csLocal.Format( "    free( pUtilityBuffer );");
				pcsaBody->Add(csLocal);
			}

			if ( !b_wLength )
			{
				declareVariable( AG_LENGTH, pcsaHeader, &b_wLength );
			}
			
			if ( !b_wPosition )
			{
				declareVariable( AG_POSITION, pcsaHeader, &b_wPosition );
			}


			csViewOutStuff.Format( "%s", "     wLength=10;");
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "%s", "     pUtilityBuffer = (char *)malloc( wLength );");
			pcsaBody->Add(csViewOutStuff);
			csViewOutStuff.Format( "%s", "     memset( pUtilityBuffer, '\\0', wLength );");
			pcsaBody->Add(csViewOutStuff);
			csViewOutStuff.Format( "%s", "     strcpy( pUtilityBuffer, \"USERID\");");
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "%s", "     wLength = (WORD)strlen( pUtilityBuffer );");
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "%s", "     wPosition = 1537;");
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "%s%s%s", "     wRc = ", csFunctionName, "( Handle, pUtilityBuffer, wLength, wPosition );");
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( " ");
			pcsaBody->Add(csViewOutStuff);
		}
		break;
		

		case 11:	// HLL_DisconnectPS
		case 40:	// HLL_Wait
		{
			csViewOutStuff.Format( "%s%s%s", "     wRc = ", csFunctionName, "( Handle );");
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( " ");
			pcsaBody->Add(csViewOutStuff);
		}
		break;


		case 12:	// HLL_EnumHLLWins
		{
			csViewOutStuff.Format( "%s%s%s", "     dwRc = ", csFunctionName, "( 0 );");
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( " ");
			pcsaBody->Add(csViewOutStuff);
		}
		break;



		case 13:	// HLL_FindFieldLength  
		case 14:	// HLL_FindFieldPosition
		{
			if ( !b_wFieldSpecifier )
			{
				declareVariable( AG_FIELD_SPECIFIER, pcsaHeader, &b_wFieldSpecifier );
			}

			if ( !b_wPosition )
			{
				declareVariable( AG_POSITION, pcsaHeader, &b_wPosition );
			}
			
			if ( nFunctionNum == 13 )
			{
				csViewOutStuff.Format( "%s", "     wFieldSpecifier = HLL_THISFIELD;");
			}
			else
			{
				csViewOutStuff.Format( "%s", "     wFieldSpecifier = HLL_PREVIOUSUNPROTECTEDFIELD;");
			}
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "%s", "     wPosition = 1617;");
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "%s%s%s", "     dwRc = ", csFunctionName, "( Handle, wFieldSpecifier, wPosition );");
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( " ");
			pcsaBody->Add(csViewOutStuff);
		}
		break;



		case 15:	// HLL_GetKey
		{
			if ( !b_pKeystroke )
			{
				declareVariable( AG_KEYSTROKE, pcsaHeader, &b_pKeystroke );
			}

			csViewOutStuff.Format( "%s", "     Keystroke.cPSID = 'A';");
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "%s%s%s", "     wRc = ", csFunctionName, "( Handle, &Keystroke );");
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( " ");
			pcsaBody->Add(csViewOutStuff);
		}
		break;



		case 16:	// HLL_Pause
		{
			if ( !b_wLength )
			{
				declareVariable( AG_LENGTH, pcsaHeader, &b_wLength );
			}

			csViewOutStuff.Format( "%s", "     wLength=10;");
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "%s%s%s", "     wRc = ", csFunctionName, "( Handle, wLength );");
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( " ");
			pcsaBody->Add(csViewOutStuff);
		}
		break;




		case 17:	// HLL_PostInterceptStatus
		{
			if ( !b_wType )
			{
				declareVariable( AG_TYPE, pcsaHeader, &b_wType );
			}
			
			csViewOutStuff.Format( "   cSession ='A';");
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "   wType = API_INTERCEPTREJECTED;");
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "   wRc = %s( Handle, &cSession, wType );", csFunctionName );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( " ");
			pcsaBody->Add(csViewOutStuff);
		}
		break;



		case 18:	// HLL_QueryHLLWinParameters
		{
			if ( !b_HLLParams )
			{
				declareVariable( AG_HLL_PARAMS, pcsaHeader, &b_HLLParams );
			}

			csViewOutStuff.Format( "     wRc = %s( Handle, &HLLParams );", csFunctionName );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( " ");
			pcsaBody->Add(csViewOutStuff);
		}
		break;


		case 19:	// HLL_QueryCursor
		{
			csViewOutStuff.Format( "%s%s%s", "     dwRc = ", csFunctionName, "( Handle );");
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( " ");
			pcsaBody->Add(csViewOutStuff);
		}
		break;

		case 20:	// HLL_QueryFieldAttribute
		{
			if ( !b_wPosition )
			{
				declareVariable( AG_POSITION, pcsaHeader, &b_wPosition );
			}
			
			csViewOutStuff.Format( "   wPosition = 1617;");
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "     dwRc = %s( Handle, wPosition );", csFunctionName );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( " ");
			pcsaBody->Add(csViewOutStuff);
		}
		break;



		case 21:	// HLL_QueryHostUpdate
		{
			csViewOutStuff.Format( "   cSession ='A';");
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "   dwRc = %s( Handle, &cSession );", csFunctionName );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( " ");
			pcsaBody->Add(csViewOutStuff);
		}
		break;



		case 22:	// HLL_QuerySessions
		{
			
			if ( !b_Sessions )
			{
				declareVariable( AG_SESSIONS, pcsaHeader, &b_Sessions );
			}
			
			if ( !b_wType )
			{
				declareVariable( AG_TYPE, pcsaHeader, &b_wType );
			}

			if ( !b_wNumber )
			{
				declareVariable( AG_NUMBER, pcsaHeader, &b_wNumber );
			}

			csViewOutStuff.Format( "   wType = HLL_QUERYSESSIONSCONFIGURED;");
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "   wNumber = 5;");
			pcsaBody->Add(csViewOutStuff);

			

			csViewOutStuff.Format( "   dwRc = %s(Handle, &Sessions, wType, wNumber);", csFunctionName );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( " ");
			pcsaBody->Add(csViewOutStuff);

		}
		break;

		
		case 23:	// HLL_QuerySessionStatus
		{
			
			if ( !b_SESS_STATUS )
			{
				declareVariable( AG_SESS_STATUS, pcsaHeader, &b_SESS_STATUS );
			}

			csViewOutStuff.Format( "     SessStatus.cPSID = 'A';");
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "%s%s%s", "     wRc = ", csFunctionName, "(Handle, &SessStatus);");
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( " ");
			pcsaBody->Add(csViewOutStuff);

		}
		break;


		case 24:	// HLL_QuerySystem
		{
			if ( !b_ATMSYSTEM )
			{
				declareVariable( AG_ATM_SYSTEM, pcsaHeader, &b_ATMSYSTEM );
			}

			csViewOutStuff.Format( "%s%s%s", "     wRc = ", csFunctionName, "( Handle, &ATMSystem );");
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( " ");
			pcsaBody->Add(csViewOutStuff);

		}
		break;


		case 25:	// HLL_ReceiveFile
		case 31:	// HLL_SendFile
		{
			if ( !b_pUtilityBuffer )
			{
				declareVariable( AG_UTILBUFFER, pcsaHeader, &b_pUtilityBuffer );
			}
			else
			{
				csLocal.Format( "    free( pUtilityBuffer );");
				pcsaBody->Add(csLocal);
			}

			if ( !b_wSequenceID )
			{
				declareVariable( AG_SEQUENCE_ID, pcsaHeader, &b_wSequenceID );
			}

			if ( !b_HLLParams )
			{
				declareVariable( AG_HLL_PARAMS, pcsaHeader, &b_HLLParams );
			}


			if ( !b_msgFileTransferComplete )
			{
				b_msgFileTransferComplete = TRUE;
				csLocal.Format( "     const UINT wmsgXM_FILETRANSFERCOMPLETION = RegisterWindowMessage(\"XM_FILETRANSFERCOMPLETION\");");
				pcsaHeader->Add(csLocal);
				csLocal.Format( "     // For your application to learn when this asynchronous file transfer ");
				pcsaHeader->Add(csLocal);
				csLocal.Format( "     // is finished be sure to to add the following line within its BEGIN_MESSAGE_MAP:");
				pcsaHeader->Add(csLocal);
				csLocal.Format( "     // ON_REGISTERED_MESSAGE(wmsgXM_FILETRANSFERCOMPLETION, FileTransferHandler );");
				pcsaHeader->Add(csLocal);

			}


			csViewOutStuff.Format( "%s", "     wRc = HLL_QueryHLLWinParameters( Handle, &HLLParams );");
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( " ");
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "%s", "     HLLParams.byWait = HLLWIN_NWAIT;");	// set for async transfer
			pcsaBody->Add(csViewOutStuff);


			csViewOutStuff.Format( "%s", "     wRc = HLL_SetHLLWinParameters( Handle, &HLLParams );");
			pcsaBody->Add(csViewOutStuff);
			
			csViewOutStuff.Format( " ");
			pcsaBody->Add(csViewOutStuff);


			csViewOutStuff.Format( "%s", "     pUtilityBuffer = (char *)malloc( 32 );");
			pcsaBody->Add(csViewOutStuff);
			csViewOutStuff.Format( "%s", "     memset( pUtilityBuffer, '\\0', 32 );");
			pcsaBody->Add(csViewOutStuff);
			csViewOutStuff.Format( "%s", "     strcpy( pUtilityBuffer, \"* TXT a: *.txt\";");
			pcsaBody->Add(csViewOutStuff);


			csViewOutStuff.Format( "%s%s%s", "     dwRc = ", csFunctionName, "( Handle, pUtilityBuffer, &wSequenceID );");
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( " ");
			pcsaBody->Add(csViewOutStuff);

		}
		break;


		case 26:	// HLL_Release
		case 27:	// HLL_Reserve
		case 28:	// HLL_ResetHLLWin
		{
			csViewOutStuff.Format( "%s%s%s", "     wRc = ", csFunctionName, "( Handle );");
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( " ");
			pcsaBody->Add(csViewOutStuff);
		}
		break;


		case 29:	// HLL_SearchField
		case 30:	// HLL_SearchPS
		{
			
			if ( !b_pUtilityBuffer )
			{
				declareVariable( AG_UTILBUFFER, pcsaHeader, &b_pUtilityBuffer );
			}
			else
			{
				csLocal.Format( "    free( pUtilityBuffer );");
				pcsaBody->Add(csLocal);
			}

			if ( !b_wLength )
			{
				declareVariable( AG_LENGTH, pcsaHeader, &b_wLength );
			}
			
			if ( !b_wPosition )
			{
				declareVariable( AG_POSITION, pcsaHeader, &b_wPosition );
			}


			csViewOutStuff.Format( "%s", "     wLength = 10;");
			pcsaBody->Add(csViewOutStuff);
			csViewOutStuff.Format( "%s", "     pUtilityBuffer = (char *)malloc( wLength );");
			pcsaBody->Add(csViewOutStuff);
			csViewOutStuff.Format( "%s", "     memset( pUtilityBuffer, '\\0', wLength );");
			pcsaBody->Add(csViewOutStuff);
			csViewOutStuff.Format( "%s", "     strcpy( pUtilityBuffer, \"Ready\");");
			pcsaBody->Add(csViewOutStuff);
			csViewOutStuff.Format( "%s", "     wLength = strlen( pUtilitybuffer );");
			pcsaBody->Add(csViewOutStuff);


			csViewOutStuff.Format( "%s", "     wPosition = 1;");
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "%s%s%s", "     dwRc = ", csFunctionName, "( Handle, pUtilityBuffer, wLength, wPosition );");
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( " ");
			pcsaBody->Add(csViewOutStuff);
		}
		break;



		case 32:	// HLL_SendKey
		{
			
			if ( !b_pUtilityBuffer )
			{
				declareVariable( AG_UTILBUFFER, pcsaHeader, &b_pUtilityBuffer );
			}
			else
			{
				csLocal.Format( "    free( pUtilityBuffer );");
				pcsaBody->Add(csLocal);
			}

			csViewOutStuff.Format( "%s", "     pUtilityBuffer = (char *)malloc( 32 );");
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "%s", "     memset( pUtilityBuffer, '\\0', 32 );");
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "%s", "     strcpy( pUtilityBuffer, \"filel@E\");");
			pcsaBody->Add(csViewOutStuff);


			csViewOutStuff.Format( "%s%s%s", "     wRc = ", csFunctionName, "( Handle, pUtilityBuffer );");
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( " ");
			pcsaBody->Add(csViewOutStuff);
		}
		break;



		case 33:	// HLL_SetCursor
		{
			if ( !b_wPosition )
			{
				declareVariable( AG_POSITION, pcsaHeader, &b_wPosition );
			}
			
			csViewOutStuff.Format( "%s", "     wPosition = 1537;");
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "%s%s%s", "     wRc = ", csFunctionName, "( Handle, wPosition );");
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( " ");
			pcsaBody->Add(csViewOutStuff);
		}
		break;


		case 34:	// HLL_SetMessageLoopCallback -- not supported in 32-bit Extra!
		{
			csViewOutStuff.Format( "%s%s%s", "     ", csFunctionName, " isn't implemented in 32=bit Extra!");
			pcsaBody->Add(csViewOutStuff);
		}
		break;

		case 35:	// HLL_SetHLLWinParameters
		{
			if ( !b_HLLParams )
			{
				declareVariable( AG_HLL_PARAMS, pcsaHeader, &b_HLLParams );
			}

			csViewOutStuff.Format( "     wRc = HLL_QueryHLLWinParameters( Handle, &HLLParams );");
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( " ");
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "     HLLParams.bySearchOrigin = HLLWIN_SRCHBKWD;");
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "     HLLParams.byWait = HLLWIN_NWAIT;");
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "   wRc = %s( Handle, &HLLParams );", csFunctionName );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( " ");
			pcsaBody->Add(csViewOutStuff);
		}
		break;


		case 36:	// HLL_StartHostNotification
		{			
			if ( !b_wType )
			{
				declareVariable( AG_TYPE, pcsaHeader, &b_wType );
			}

			csViewOutStuff.Format( "   cSession = 'A';");
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "   wType = HLL_NOTIFYPSUPDATE;");
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "     wRc = %s( Handle, &cSession, wType, FALSE );", csFunctionName );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( " ");
			pcsaBody->Add(csViewOutStuff);

		}
		break;


		case 37:	// HLL_StartKeystrokeIntercept
		{
			if ( !b_StartIntercept )
			{
				b_StartIntercept = TRUE;
				csLocal.Format( "     STARTINTERCEPT StartIntercept;");
				pcsaHeader->Add(csLocal);

				csLocal.Format( "     const UINT wmsgXM_KEYSTROKEINTERCEPTED = RegisterWindowMessage(\"XM_KEYSTROKEINTERCEPTED\");");
				pcsaHeader->Add(csLocal);

				csLocal.Format( "     // For your application to learn when a keystroke is sensed");
				pcsaHeader->Add(csLocal);
				csLocal.Format( "     // be sure to to add the following line within its BEGIN_MESSAGE_MAP:");
				pcsaHeader->Add(csLocal);
				csLocal.Format( "     // ON_REGISTERED_MESSAGE(wmsgXM_KEYSTROKEINTERCEPTED, KeystrokeInterceptHandler );");
				pcsaHeader->Add(csLocal);

				
			}

			csViewOutStuff.Format( "     StartIntercept.cPSID = 'A';");
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "     StartIntercept.wKeyFilter = HLL_INTERCEPTAIDKEYS;");
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "     StartIntercept.wQueueLength = 32;");
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "     StartIntercept.bWindowsMessage = TRUE;   // receive notification in KeystrokeInterceptHandler()");
			pcsaBody->Add(csViewOutStuff);
			

			csViewOutStuff.Format( "     wRc = %s( Handle, StartIntercept );", csFunctionName );
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( " ");
			pcsaBody->Add(csViewOutStuff);

		}
		break;


		case 41:	// HLL_WSCtrl
		{

			if ( !b_pUtilityBuffer )
			{
				declareVariable( AG_UTILBUFFER, pcsaHeader, &b_pUtilityBuffer );
			}
			else
			{
				csLocal.Format( "    free( pUtilityBuffer );");
				pcsaBody->Add(csLocal);
			}

			if ( !b_wLength )
			{
				declareVariable( AG_LENGTH, pcsaHeader, &b_wLength );
			}
			
			if ( !b_wType )
			{
				declareVariable( AG_TYPE, pcsaHeader, &b_wType );
			}


			csViewOutStuff.Format( "%s", "     wLength=512;");
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( "%s", "     pUtilityBuffer = (char *)malloc( wLength );");
			pcsaBody->Add(csViewOutStuff);

			
			csViewOutStuff.Format( "%s", "     wType = HLL_WSCTRLQUERYEXTRADIRECTORY;");
			pcsaBody->Add(csViewOutStuff);


			csViewOutStuff.Format( "%s%s%s", "     wRc = ", csFunctionName, "( Handle, wType, pUtilityBuffer, wLength);");
			pcsaBody->Add(csViewOutStuff);

			csViewOutStuff.Format( " ");
			pcsaBody->Add(csViewOutStuff);

		}
		break;


		default:
		{
			csViewOutStuff.Format( "%s%i%s", "//     Function ", nFunctionNum, ". Abandon hope, all ye who enter here.  ");
			pcsaBody->Add(csViewOutStuff);
		}
		
	}

	pcsaArguments->RemoveAll();
}



void CAG_HLL_CPP::finalize(CStringArray* pcsaBody)
{
	CString csLocal;

	csLocal.Format("%s", " " );
	pcsaBody->Add(csLocal);

	csLocal.Format("%s", "     return 1;" );
	pcsaBody->Add(csLocal);

	csLocal.Format("%s", " " );
	pcsaBody->Add(csLocal);

	csLocal.Format("%s", "}" );
	pcsaBody->Add(csLocal);

	csLocal.Format("%s", " " );
	pcsaBody->Add(csLocal);
}



void CAG_HLL_CPP::declareVariable(AG_VARIABLE agVariable,
								  CStringArray* pcsaHeader,
								  bool* bValue)
{
	CString csLocal;
	*bValue = TRUE;
	
	switch ( agVariable )
	{
		case AG_ATM_SYSTEM:
		{
			csLocal.Format( "     ATMSYSTEM ATMSys;");
		}
		break;

		case AG_STATUS:
		{
			csLocal.Format( "     int nStatus=0;");
		}
		break;

		case AG_UPDATED:
		{
			csLocal.Format( "     bool bUpdated=FALSE;");
		}
		break;

		case AG_UTILBUFFER:
		{
			csLocal.Format( "     char *pUtilityBuffer;");
		}
		break;

		case AG_BSTR:
		{
			csLocal.Format( "     VARIANT v;");
			pcsaHeader->Add(csLocal);
			csLocal.Format( "     ::VariantInit(&v);");
			pcsaHeader->Add(csLocal);
			csLocal.Format( "     v.vt=VT_BSTR;");
		}
		break;

		case AG_ROW:
		{
			csLocal.Format( "     VARIANT nRow;");
			pcsaHeader->Add(csLocal);
			csLocal.Format( "     ::VariantInit(&nRow);");
			pcsaHeader->Add(csLocal);
			csLocal.Format( "     nRow.vt=VT_I4;");
		}
		break;

		case AG_COLUMN:
		{
			csLocal.Format( "     VARIANT nColumn;");
			pcsaHeader->Add(csLocal);
			csLocal.Format( "     ::VariantInit(&nColumn);");
			pcsaHeader->Add(csLocal);
			csLocal.Format( "     nColumn.vt=VT_I4;");
		}
		break;

		case AG_ATTRIBUTE:
		{
			csLocal.Format( "     int nAttribute=0;");
		}
		break;

		case AG_LENGTH:
		{
			csLocal.Format( "     WORD wLength=0;");			
		}
		break;

		case AG_VALUE:
		{
			csLocal.Format( "     int nValue=0;");
		}
		break;

		case AG_RETURN:
		{
			csLocal.Format( "     bool bRet=FALSE;");
		}
		break;

		case AG_CLOSEOPTION:
		{
			csLocal.Format( "     VARIANT nCloseOption;");
			pcsaHeader->Add(csLocal);
			csLocal.Format( "     ::VariantInit(&nCloseOption);");
			pcsaHeader->Add(csLocal);
			csLocal.Format( "     nCloseOption.vt=VT_I4;");	// XXX
		}
		break;

		case AG_FIELD_SPECIFIER:
		{
			csLocal.Format( "     WORD wFieldSpecifier = 0;");
		}
		break;

		case AG_HOST_OS:
		{
			csLocal.Format( "     int nFTHostOS=0;");
		}
		break;

		case AG_HEIGHT:
		{
			csLocal.Format( "     int nHeight=0;");
		}
		break;

		case AG_HLL_PARAMS:
		{
			csLocal.Format( "     HLLPARAMS HLLParams;");
		}
		break;

		case AG_KEYSTROKE:
		{
			csLocal.Format( "     KEYSTROKE Keystroke;");
		}
		break;

		case AG_LOCALMODE:
		{
			csLocal.Format( "     bool bLocalMode=FALSE;");
		}
		break;

		case AG_POSITION:
		{
			csLocal.Format( "     WORD wPosition=0;");
		}
		break;

		case AG_SESS_SAVED:
		{
			csLocal.Format( "     bool bSessionSaved=FALSE;");
		}
		break;

		case AG_SESS_OPEN:
		{
			csLocal.Format( "     char SessName[512];");
			pcsaHeader->Add(csLocal);
			csLocal.Format( "     char* pSessName=SessName;");
		}
		break;


		case AG_SETTLE_TIME:
		{
			csLocal.Format( "     VARIANT nSettleTime;");
			pcsaHeader->Add(csLocal);
			csLocal.Format( "     ::VariantInit(&nSettleTime);");
			pcsaHeader->Add(csLocal);
			csLocal.Format( "     nSettleTime.vt=VT_I4;");	// XXX
		}
		break;

		case AG_SESS_QUIET:
		{
			csLocal.Format( "     bool bSessionQuiet=FALSE;");
		}
		break;

		case AG_SESS_STATUS:
		{
			csLocal.Format( "     SESSIONSTATUS SessStatus;");
		}
		break;

		case AG_MENU_VISIBLE:
		{
			csLocal.Format( "     bool bMenuVisible=FALSE;");
		}
		break;

		case AG_NUMBER:
		{
			csLocal.Format( "     WORD wNumber=0;");
		}
		break;

		case AG_POINT_POSITION:
		{
			csLocal.Format( "     POINT ptPosition;");
		}
		break;


		case AG_TYPE:
		{
			csLocal.Format( "     WORD wType=0;");
		}
		break;

		case AG_TIMEOUT:
		{
			csLocal.Format( "     VARIANT nTimeout;");
			pcsaHeader->Add(csLocal);
			csLocal.Format( "     ::VariantInit(&nTimeout);");
			pcsaHeader->Add(csLocal);
			csLocal.Format( "     nTimeout.vt=VT_I4;");	// XXX int
		}
		break;

		case AG_PROCESS_KEYSTROKES:
		{
			csLocal.Format( "     VARIANT bProcessKeystrokes;");
			pcsaHeader->Add(csLocal);
			csLocal.Format( "     ::VariantInit(&bProcessKeystrokes);");
			pcsaHeader->Add(csLocal);
			csLocal.Format( "     nColumn.vt=VT_I4;");	// XXX	bool
		}
		break;

		case AG_ROWCOL_FLAG:
		{
			csLocal.Format( "     WORD wRowColFlag = 0;");
		}
		break;

		case AG_SEQUENCE_ID:
		{
			csLocal.Format( "     WORD wSequenceID;");
		}
		break;

		case AG_SESSIONS:
		{
			csLocal.Format( "     SESSIONS Sessions[5];");
		}
		break;

		case AG_WIDTH:
		{
			csLocal.Format( "     int nWidth=0;");
		}
		break;

		case AG_WINDOW_HANDLE:
		{
			csLocal.Format( "     HANDLE hSession=NULL;");
		}
		break;

		case AG_WINDOW_STATE:
		{
			csLocal.Format( "     int nWindowState=0;");
		}
		break;

		case AG_COUNT:
		{
			csLocal.Format( "     int nCount=0;");
		}
		break;

		case AG_AREA:
		{
			csLocal.Format( "     int Area=0;");
		}
		break;
	}

	pcsaHeader->Add(csLocal);
}


void CAG_HLL_CPP::checkDebug(bool b_Debug,
									   CString csFunctionName,
									   CStringArray* pcsaBody)
{
	
}

void CAG_HLL_CPP::resetVariableFlags()
{
   b_ATMSYSTEM = FALSE;
   b_SESS_STATUS = FALSE;
   b_wRowColFlag = FALSE;
   b_ptPosition = FALSE;
   b_wLength = FALSE;
   b_wPosition = FALSE;
   b_wFieldSpecifier = FALSE;
   b_pKeystroke = FALSE;
   b_wType = FALSE;
   b_HLLParams = FALSE;
   b_wNumber = FALSE;
   b_Sessions = FALSE;
   b_ATMSystem = FALSE;
   b_wSequenceID = FALSE;
   b_msgFileTransferComplete = FALSE;
   b_StartIntercept = FALSE;
   b_pUtilityBuffer = FALSE;
}
