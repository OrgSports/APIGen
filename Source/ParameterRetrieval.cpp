#include "stdafx.h"
#include "APIGen.h"
#include "APIGenDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


/***************************************************************************DC

	Operation:	CAPIGenDlg::ReadMixedControls() 

	Purpose:	Sets up the controls used in entering function arguments.

	Arguments:	csaLabels -- the strings that are used to label each edit
				control.

				nControlBits -- an unsigned int that indicates which controls
				should be placed in the UI.
	
	Note:		

*****************************************************************************/
void CAPIGenDlg::ReadMixedControls( APIOption API, UINT uFunction, CStringArray* pcsaLabels )
{

	int topGroupStart=PARAM_TOP;
	int nGroupBoxHeight = 0;

	switch ( API )
	{
		case RWIN_OLE_API:
		case RWEB_API:
		case AIRJ_API:
		case VIEWMASTER_API:
		case EA0J_API:
		case RIBM_OLE_API:
		case CICS20_JAVA_API:	
		case RFTP_API:
		case CICS_COM_API:
		case EOLE_API:
		case ITASK_API:
		case ICONN_API:
		{
			// in utils file
		}
		break;

		case MCSJ_API:
		case AIRAx_API:
		case EAL_API:
		case HLL_API:
		case EA0Ax_API:
		case MCSAx_API:
		case QACOM_API:
		case VHI_API:
		{
			// not done yet
		}
		break;


		case EHL_API:
		case IHL_API:
		case PCS_API:
		case WHL_API:
		{
			ReadHLLArgs( &csaArguments );
		}
		break;


		default:
		{

		}

	}

}


/***************************************************************************DC

	Operation:	CAPIGenDlg::ReadHLLArgs() 

	Purpose:	Reads the three edit controls used with the standard
				HLLAPI library DLL's

	Arguments:	csaArguments	-- the argument array

	Note:		

*****************************************************************************/
void CAPIGenDlg::ReadHLLArgs( CStringArray* csaArguments )
{
	// first arg is func name and second is the number

	// string parameter
	if ( 0 == m_csEditArgument1.GetLength() )
	{
		csaArguments->Add( "0" );
	}
	else
	{
		csaArguments->Add( m_csEditArgument1 );
	}

	// string length
	if ( 0 == m_csEditArgument2.GetLength() )
	{
		csaArguments->Add( "0" );
	}
	else
	{
		csaArguments->Add( m_csEditArgument2 );
	}
	
	// return code
	if ( 0 == m_csEditArgument3.GetLength() )
	{
		csaArguments->Add( "0" );
	}
	else
	{
		csaArguments->Add( m_csEditArgument3 );
	}
			
}


/***************************************************************************DC

	Operation:	CAPIGenDlg::Read1L() 

	Purpose:	Reads one listbox

	Arguments:	csaArguments	-- the argument array

	Note:		

*****************************************************************************/
void CAPIGenDlg::Read1L( CStringArray* csaArguments )
{
	// listbox
	int nCurIndex = listParams1.GetCurSel();
	CString csCurSel;
	listParams1.GetText( nCurIndex, csCurSel );
	csaArguments->Add( csCurSel );
}



/***************************************************************************DC

	Operation:	CAPIGenDlg::Read1E() 

	Purpose:	Reads one edit control

	Arguments:	csaArguments	-- the argument array

	Note:		

*****************************************************************************/
void CAPIGenDlg::Read1E( CStringArray* csaArguments )
{
	csaArguments->Add( m_csEditArgument1 );
}



/***************************************************************************DC

	Operation:	CAPIGenDlg::Read1E1L() 

	Purpose:	Reads two edit controls + two listboxes + one checkbox

	Arguments:	csaArguments	-- the argument array

	Note:		

*****************************************************************************/
void CAPIGenDlg::Read1E1L( CStringArray* csaArguments )
{
	csaArguments->Add( m_csEditArgument1 );

	// listbox 1
	int nCurIndex = listParams1.GetCurSel();
	CString csCurSel;
	listParams1.GetText( nCurIndex, csCurSel );
	csaArguments->Add( csCurSel );
}



/***************************************************************************DC

	Operation:	CAPIGenDlg::Read1E1L4E1L() 

	Purpose:	Reads two edit controls + two listboxes + one checkbox

	Arguments:	csaArguments	-- the argument array

	Note:		

*****************************************************************************/
void CAPIGenDlg::Read1E1L4E1L( CStringArray* csaArguments )
{
	csaArguments->Add( m_csEditArgument1 );

	// listbox 1
	int nCurIndex = listParams1.GetCurSel();
	CString csCurSel;
	listParams1.GetText( nCurIndex, csCurSel );
	csaArguments->Add( csCurSel );

	csaArguments->Add( m_csEditArgument3 );
	csaArguments->Add( m_csEditArgument4 );
	csaArguments->Add( m_csEditArgument5 );
	csaArguments->Add( m_csEditArgument6 );

	// listbox 2
	nCurIndex = listParams2.GetCurSel();
	listParams2.GetText( nCurIndex, csCurSel );
	csaArguments->Add( csCurSel );

}


/***************************************************************************DC

	Operation:	CAPIGenDlg::Read2E() 

	Purpose:	Reads two edit controls + two listboxes + one checkbox

	Arguments:	csaArguments	-- the argument array

	Note:		

*****************************************************************************/
void CAPIGenDlg::Read2E( CStringArray* csaArguments )
{
	csaArguments->Add( m_csEditArgument1 );
	csaArguments->Add( m_csEditArgument3 );
}




/***************************************************************************DC

	Operation:	CAPIGenDlg::Read2E2L1C() 

	Purpose:	Reads two edit controls + two listboxes + one checkbox

	Arguments:	csaArguments	-- the argument array

	Note:		

*****************************************************************************/
void CAPIGenDlg::Read2E2L1C( CStringArray* csaArguments )
{
	csaArguments->Add( m_csEditArgument1 );
	csaArguments->Add( m_csEditArgument3 );

	// listbox 1
	int nCurIndex = listParams1.GetCurSel();
	CString csCurSel;
	listParams1.GetText( nCurIndex, csCurSel );
	csaArguments->Add( csCurSel );

	// listbox 2
	nCurIndex = listParams2.GetCurSel();
	listParams2.GetText( nCurIndex, csCurSel );
	csaArguments->Add( csCurSel );

	// checkbox
	if ( bCheckParam1 )
	{
		csaArguments->Add( "TRUE" );
	}
	else
	{
		csaArguments->Add( "FALSE" );
	}

}


/***************************************************************************DC

	Operation:	CAPIGenDlg::Read2E2L3E() 

	Purpose:	Reads two edit controls + two listboxes + three edit controls

	Arguments:	csaArguments	-- the argument array

	Note:		

*****************************************************************************/
void CAPIGenDlg::Read2E2L3E( CStringArray* csaArguments )
{
	// first two edit controls
	csaArguments->Add( m_csEditArgument1 );
	csaArguments->Add( m_csEditArgument3 );

	// listbox 1
	int nCurIndex = listParams1.GetCurSel();
	CString csCurSel;
	listParams1.GetText( nCurIndex, csCurSel );
	csaArguments->Add( csCurSel );

	// listbox 2
	nCurIndex = listParams2.GetCurSel();
	listParams2.GetText( nCurIndex, csCurSel );
	csaArguments->Add( csCurSel );

	// last three edit controls
	csaArguments->Add( m_csEditArgument4 );
	csaArguments->Add( m_csEditArgument5 );
	csaArguments->Add( m_csEditArgument6 );
}





/***************************************************************************DC

	Operation:	CAPIGenDlg::Read1E2L1C() 

	Purpose:	Reads one edit control + two listboxes + one checkbox

	Arguments:	csaArguments	-- the argument array

	Note:		

*****************************************************************************/
void CAPIGenDlg::Read1E2L1C( CStringArray* csaArguments )
{
	// first edit control
	csaArguments->Add( m_csEditArgument1 );

	// listbox 1
	int nCurIndex = listParams1.GetCurSel();
	CString csCurSel;
	listParams1.GetText( nCurIndex, csCurSel );
	csaArguments->Add( csCurSel );

	// listbox 2
	nCurIndex = listParams2.GetCurSel();
	listParams2.GetText( nCurIndex, csCurSel );
	csaArguments->Add( csCurSel );

	// checkbox
	if ( bCheckParam1 )
	{
		csaArguments->Add( "TRUE" );
	}
	else
	{
		csaArguments->Add( "FALSE" );
	}
}



/***************************************************************************DC

	Operation:	CAPIGenDlg::Read4E1C1L() 

	Purpose:	Reads four edit controls + one checkbox + one listbox

	Arguments:	csaArguments	-- the argument array

	Note:		

*****************************************************************************/
void CAPIGenDlg::Read4E1C1L( CStringArray* csaArguments )
{
	// first edit control
	csaArguments->Add( m_csEditArgument1 );
	csaArguments->Add( m_csEditArgument3 );
	csaArguments->Add( m_csEditArgument4 );
	csaArguments->Add( m_csEditArgument5 );

	// checkbox
	if ( bCheckParam1 )
	{
		csaArguments->Add( "TRUE" );
	}
	else
	{
		csaArguments->Add( "FALSE" );
	}

	// listbox 1
	int nCurIndex = listParams1.GetCurSel();
	CString csCurSel;
	listParams1.GetText( nCurIndex, csCurSel );
	csaArguments->Add( csCurSel );

}



/***************************************************************************DC

	Operation:	CAPIGenDlg::Read4E1C1ML() 

	Purpose:	Reads four edit controls + one checkbox + one multi-selection
				listbox

	Arguments:	csaArguments	-- the argument array

	Note:		

*****************************************************************************/
void CAPIGenDlg::Read4E1C1ML( CStringArray* csaArguments )
{
	// first edit control
	csaArguments->Add( m_csEditArgument1 );
	csaArguments->Add( m_csEditArgument3 );
	csaArguments->Add( m_csEditArgument4 );
	csaArguments->Add( m_csEditArgument5 );

	// checkbox
	if ( bCheckParam1 )
	{
		csaArguments->Add( "TRUE" );
	}
	else
	{
		csaArguments->Add( "FALSE" );
	}

	// multi-selection listbox
	int nCount = listMultiParams1.GetSelCount();
	CArray<int,int> caSelectedItems;
	CString csCurSel;
	CString csSelList;

	caSelectedItems.SetSize(nCount);
	listMultiParams1.GetSelItems(nCount, caSelectedItems.GetData());

	for ( int i=0; i<caSelectedItems.GetCount(); i++)
	{
		listMultiParams1.GetText(caSelectedItems.GetAt( i ), csCurSel );
		csSelList += csCurSel;
	}

	csaArguments->Add( csSelList );

}



/***************************************************************************DC

	Operation:	CAPIGenDlg::Read1E1C() 

	Purpose:	Reads one edit control + one checkbox

	Arguments:	csaArguments	-- the argument array

	Note:		

*****************************************************************************/
void CAPIGenDlg::Read1E1C( CStringArray* csaArguments )
{
	// edit control
	csaArguments->Add( m_csEditArgument1 );

	// checkbox
	if ( bCheckParam1 )
	{
		csaArguments->Add( "TRUE" );
	}
	else
	{
		csaArguments->Add( "FALSE" );
	}
}


/***************************************************************************DC

	Operation:	CAPIGenDlg::Read1E1C1E() 

	Purpose:	Reads one edit control + one checkbox + one edit control

	Arguments:	csaArguments	-- the argument array

	Note:		

*****************************************************************************/
void CAPIGenDlg::Read1E1C1E( CStringArray* csaArguments )
{
	// edit control
	csaArguments->Add( m_csEditArgument1 );

	// checkbox
	if ( bCheckParam1 )
	{
		csaArguments->Add( "TRUE" );
	}
	else
	{
		csaArguments->Add( "FALSE" );
	}

	// edit control
	csaArguments->Add( m_csEditArgument3 );


}


/***************************************************************************DC

	Operation:	CAPIGenDlg::Read2L() 

	Purpose:	Reads two edit controls + two listboxes + three edit controls

	Arguments:	csaArguments	-- the argument array

	Note:		

*****************************************************************************/
void CAPIGenDlg::Read2L( CStringArray* csaArguments )
{
	// listbox 1
	int nCurIndex = listParams1.GetCurSel();
	CString csCurSel;
	listParams1.GetText( nCurIndex, csCurSel );
	csaArguments->Add( csCurSel );

	// listbox 2
	nCurIndex = listParams2.GetCurSel();
	listParams2.GetText( nCurIndex, csCurSel );
	csaArguments->Add( csCurSel );
}



/***************************************************************************DC

	Operation:	CAPIGenDlg::Read1E1L3E1L() 

	Purpose:	Reads one edit control + one listbox + three edit controls + one listbox

	Arguments:	csaArguments	-- the argument array

	Note:		

*****************************************************************************/
void CAPIGenDlg::Read1E1L3E1L( CStringArray* csaArguments )
{
	// first edit control
	csaArguments->Add( m_csEditArgument1 );

	// listbox 1
	int nCurIndex = listParams1.GetCurSel();
	CString csCurSel;
	listParams1.GetText( nCurIndex, csCurSel );
	csaArguments->Add( csCurSel );

	// 2,3,4 edit controls
	csaArguments->Add( m_csEditArgument3 );
	csaArguments->Add( m_csEditArgument4 );
	csaArguments->Add( m_csEditArgument5 );

	// listbox 2
	nCurIndex = listParams2.GetCurSel();
	listParams2.GetText( nCurIndex, csCurSel );
	csaArguments->Add( csCurSel );

}


/***************************************************************************DC

	Operation:	CAPIGenDlg::Read2C() 

	Purpose:	Reads two checkboxes

	Arguments:	csaArguments	-- the argument array

	Note:		

*****************************************************************************/
void CAPIGenDlg::Read2C( CStringArray* csaArguments )
{
	// checkbox 1
	if ( bCheckParam1 )
	{
		csaArguments->Add( "TRUE" );
	}
	else
	{
		csaArguments->Add( "FALSE" );
	}

	// checkbox 1
	if ( bCheckParam2 )
	{
		csaArguments->Add( "TRUE" );
	}
	else
	{
		csaArguments->Add( "FALSE" );
	}

}


/***************************************************************************DC

	Operation:	CAPIGenDlg::Read3C() 

	Purpose:	Reads three checkboxes

	Arguments:	csaArguments	-- the argument array

	Note:		

*****************************************************************************/
void CAPIGenDlg::Read3C( CStringArray* csaArguments )
{
	// checkbox 1
	if ( bCheckParam1 )
	{
		csaArguments->Add( "TRUE" );
	}
	else
	{
		csaArguments->Add( "FALSE" );
	}

	// checkbox 2
	if ( bCheckParam2 )
	{
		csaArguments->Add( "TRUE" );
	}
	else
	{
		csaArguments->Add( "FALSE" );
	}

	// checkbox 3
	if ( bCheckParam3 )
	{
		csaArguments->Add( "TRUE" );
	}
	else
	{
		csaArguments->Add( "FALSE" );
	}

}




/***************************************************************************DC

	Operation:	CAPIGenDlg::Read6E2L2C() 

	Purpose:	Reads six edit controls + two listboxes + two checkboxes

	Arguments:	csaArguments	-- the argument array

	Note:		

*****************************************************************************/
void CAPIGenDlg::Read6E2L2C( CStringArray* csaArguments )
{
	// first edit control
	csaArguments->Add( m_csEditArgument1 );
	csaArguments->Add( m_csEditArgument3 );
	csaArguments->Add( m_csEditArgument4 );
	csaArguments->Add( m_csEditArgument5 );
	csaArguments->Add( m_csEditArgument6 );
	csaArguments->Add( m_csEditArgument7 );

	// listbox 1
	int nCurIndex = listParams1.GetCurSel();
	CString csCurSel;
	listParams1.GetText( nCurIndex, csCurSel );
	csaArguments->Add( csCurSel );

	// listbox 2
	nCurIndex = listParams2.GetCurSel();
	listParams2.GetText( nCurIndex, csCurSel );
	csaArguments->Add( csCurSel );

	// checkbox 1
	if ( bCheckParam1 )
	{
		csaArguments->Add( "TRUE" );
	}
	else
	{
		csaArguments->Add( "FALSE" );
	}

	if ( bCheckParam2 )
	{
		csaArguments->Add( "TRUE" );
	}
	else
	{
		csaArguments->Add( "FALSE" );
	}

}


/***************************************************************************DC

	Operation:	CAPIGenDlg::Read3E() 

	Purpose:	Reads three edit controls

	Arguments:	csaArguments	-- the argument array

	Note:		

*****************************************************************************/
void CAPIGenDlg::Read3E( CStringArray* csaArguments )
{
	// edit control
	csaArguments->Add( m_csEditArgument1 );
	csaArguments->Add( m_csEditArgument3 );
	csaArguments->Add( m_csEditArgument4 );
}




/***************************************************************************DC

	Operation:	CAPIGenDlg::Read3E1C() 

	Purpose:	Reads three edit controls + one checkbox

	Arguments:	csaArguments	-- the argument array

	Note:		

*****************************************************************************/
void CAPIGenDlg::Read3E1C( CStringArray* csaArguments )
{
	// edit control
	csaArguments->Add( m_csEditArgument1 );
	csaArguments->Add( m_csEditArgument3 );
	csaArguments->Add( m_csEditArgument4 );

	// checkbox
	if ( bCheckParam1 )
	{
		csaArguments->Add( "TRUE" );
	}
	else
	{
		csaArguments->Add( "FALSE" );
	}
}



/***************************************************************************DC

	Operation:	CAPIGenDlg::Read3E1L() 

	Purpose:	Reads three edit controls + one listbox

	Arguments:	csaArguments	-- the argument array

	Note:		

*****************************************************************************/
void CAPIGenDlg::Read3E1L( CStringArray* csaArguments )
{
	// first edit control
	csaArguments->Add( m_csEditArgument1 );
	csaArguments->Add( m_csEditArgument3 );
	csaArguments->Add( m_csEditArgument4 );

	// listbox 1
	int nCurIndex = listParams1.GetCurSel();
	CString csCurSel;
	listParams1.GetText( nCurIndex, csCurSel );
	csaArguments->Add( csCurSel );

}


/***************************************************************************DC

	Operation:	CAPIGenDlg::Read3E1ML() 

	Purpose:	Reads three edit controls + one multiple selection listbox

	Arguments:	csaArguments	-- the argument array

	Note:		

*****************************************************************************/
void CAPIGenDlg::Read3E1ML( CStringArray* csaArguments )
{
	// first edit control
	csaArguments->Add( m_csEditArgument1 );
	csaArguments->Add( m_csEditArgument3 );
	csaArguments->Add( m_csEditArgument4 );

	// multi selection listbox 1
	CString csCurSel;
	CString csSelList;
	
	int nCount = listMultiParams1.GetSelCount();
	CArray<int,int> caSelectedItems;

	caSelectedItems.SetSize(nCount);
	listMultiParams1.GetSelItems(nCount, caSelectedItems.GetData());

	for ( int i=0; i<caSelectedItems.GetCount(); i++)
	{
		listMultiParams1.GetText(caSelectedItems.GetAt( i ), csCurSel );
		csSelList += csCurSel;
	}

	// this must be moved to the leaf class as it is specific
	// to some Reflection constants
	if ( -1 != csSelList.Find("xRegExp",0) )
	{
		csaArguments->Add( " xRegExp" );
	}

	if ( -1 != csSelList.Find("xNoCase",0) )
	{
		csaArguments->Add( " xNoCase" );
	}

}



/***************************************************************************DC

	Operation:	CAPIGenDlg::Read4E1ML() 

	Purpose:	Reads four edit controls + one multiple selection listbox

	Arguments:	csaArguments	-- the argument array

	Note:		

*****************************************************************************/
void CAPIGenDlg::Read4E1ML( CStringArray* csaArguments )
{
	// first edit control
	csaArguments->Add( m_csEditArgument1 );
	csaArguments->Add( m_csEditArgument3 );
	csaArguments->Add( m_csEditArgument4 );
	csaArguments->Add( m_csEditArgument5 );

	// multi selection listbox 1
	CString csCurSel;
	CString csSelList;
	
	int nCount = listMultiParams1.GetSelCount();
	CArray<int,int> caSelectedItems;

	caSelectedItems.SetSize(nCount);
	listMultiParams1.GetSelItems(nCount, caSelectedItems.GetData());

	for ( int i=0; i<caSelectedItems.GetCount(); i++)
	{
		listMultiParams1.GetText(caSelectedItems.GetAt( i ), csCurSel );
		csSelList += csCurSel;
	}

	csaArguments->Add( csSelList );

}



/***************************************************************************DC

	Operation:	CAPIGenDlg::Read4E() 

	Purpose:	Reads four edit controls

	Arguments:	csaArguments	-- the argument array

	Note:		

*****************************************************************************/
void CAPIGenDlg::Read4E( CStringArray* csaArguments )
{
	// edit controls
	csaArguments->Add( m_csEditArgument1 );
	csaArguments->Add( m_csEditArgument3 );
	csaArguments->Add( m_csEditArgument4 );
	csaArguments->Add( m_csEditArgument5 );
}



/***************************************************************************DC

	Operation:	CAPIGenDlg::Read4E1C() 

	Purpose:	Reads four edit controls + one checkbox

	Arguments:	csaArguments	-- the argument array

	Note:		

*****************************************************************************/
void CAPIGenDlg::Read4E1C( CStringArray* csaArguments )
{
	// edit controls
	csaArguments->Add( m_csEditArgument1 );
	csaArguments->Add( m_csEditArgument3 );
	csaArguments->Add( m_csEditArgument4 );
	csaArguments->Add( m_csEditArgument5 );

	// checkbox
	if ( bCheckParam1 )
	{
		csaArguments->Add( "TRUE" );
	}
	else
	{
		csaArguments->Add( "FALSE" );
	}

}


/***************************************************************************DC

	Operation:	CAPIGenDlg::Read4E1C2E() 

	Purpose:	Reads four edit controls + one checkbox + three edit controls

	Arguments:	csaArguments	-- the argument array

	Note:		

*****************************************************************************/
void CAPIGenDlg::Read4E1C2E( CStringArray* csaArguments )
{
	// edit controls
	csaArguments->Add( m_csEditArgument1 );
	csaArguments->Add( m_csEditArgument3 );
	csaArguments->Add( m_csEditArgument4 );
	csaArguments->Add( m_csEditArgument5 );

	// checkbox
	if ( bCheckParam1 )
	{
		csaArguments->Add( "TRUE" );
	}
	else
	{
		csaArguments->Add( "FALSE" );
	}

	csaArguments->Add( m_csEditArgument6 );
	csaArguments->Add( m_csEditArgument7 );
}



/***************************************************************************DC

	Operation:	CAPIGenDlg::Read4E1L() 

	Purpose:	Reads four edit controls + one listbox

	Arguments:	csaArguments	-- the argument array

	Note:		

*****************************************************************************/
void CAPIGenDlg::Read4E1L( CStringArray* csaArguments )
{
	// first edit control
	csaArguments->Add( m_csEditArgument1 );
	csaArguments->Add( m_csEditArgument3 );
	csaArguments->Add( m_csEditArgument4 );
	csaArguments->Add( m_csEditArgument5 );

	// listbox 1
	int nCurIndex = listParams1.GetCurSel();
	CString csCurSel;
	listParams1.GetText( nCurIndex, csCurSel );
	csaArguments->Add( csCurSel );
}



/***************************************************************************DC

	Operation:	CAPIGenDlg::Read2E2L() 

	Purpose:	Reads two edit controls + two listboxes

	Arguments:	csaArguments	-- the argument array

	Note:		

*****************************************************************************/
void CAPIGenDlg::Read2E2L( CStringArray* csaArguments )
{
	// edit controls
	csaArguments->Add( m_csEditArgument1 );
	csaArguments->Add( m_csEditArgument3 );

	// listbox 1
	int nCurIndex = listParams1.GetCurSel();
	CString csCurSel;
	listParams1.GetText( nCurIndex, csCurSel );
	csaArguments->Add( csCurSel );

	// listbox 2
	nCurIndex = listParams2.GetCurSel();
	listParams2.GetText( nCurIndex, csCurSel );
	csaArguments->Add( csCurSel );
}



/***************************************************************************DC

	Operation:	CAPIGenDlg::Read2E1L() 

	Purpose:	Reads two edit controls + one listbox

	Arguments:	csaArguments	-- the argument array

	Note:		

*****************************************************************************/
void CAPIGenDlg::Read2E1L( CStringArray* csaArguments )
{
	// edit controls
	csaArguments->Add( m_csEditArgument1 );
	csaArguments->Add( m_csEditArgument3 );

	// listbox 1
	int nCurIndex = listParams1.GetCurSel();
	CString csCurSel;
	listParams1.GetText( nCurIndex, csCurSel );
	csaArguments->Add( csCurSel );
}



/***************************************************************************DC

	Operation:	CAPIGenDlg::Read2E1L5E() 

	Purpose:	Reads two edit controls + one listbox + five edit controls

	Arguments:	csaArguments	-- the argument array

	Note:		

*****************************************************************************/
void CAPIGenDlg::Read2E1L5E( CStringArray* csaArguments )
{
	// edit controls
	csaArguments->Add( m_csEditArgument1 );
	csaArguments->Add( m_csEditArgument3 );

	// listbox 1
	int nCurIndex = listParams1.GetCurSel();
	CString csCurSel;
	listParams1.GetText( nCurIndex, csCurSel );
	csaArguments->Add( csCurSel );

	// edit controls
	csaArguments->Add( m_csEditArgument4 );
	csaArguments->Add( m_csEditArgument5 );
	csaArguments->Add( m_csEditArgument6 );
	csaArguments->Add( m_csEditArgument7 );
	csaArguments->Add( m_csEditArgument8 );

}


/***************************************************************************DC

	Operation:	CAPIGenDlg::Read1C1E() 

	Purpose:	Reads one checkbox + one edit control

	Arguments:	csaArguments	-- the argument array

	Note:		

*****************************************************************************/
void CAPIGenDlg::Read1C1E( CStringArray* csaArguments )
{
	// checkbox
	if ( bCheckParam1 )
	{
		csaArguments->Add( "TRUE" );
	}
	else
	{
		csaArguments->Add( "FALSE" );
	}

	// edit control
	csaArguments->Add( m_csEditArgument1 );

}


/***************************************************************************DC

	Operation:	CAPIGenDlg::Read1C1L() 

	Purpose:	Reads one checkbox + one listbox

	Arguments:	csaArguments	-- the argument array

	Note:		

*****************************************************************************/
void CAPIGenDlg::Read1C1L( CStringArray* csaArguments )
{
	// checkbox
	if ( bCheckParam1 )
	{
		csaArguments->Add( "TRUE" );
	}
	else
	{
		csaArguments->Add( "FALSE" );
	}

	// listbox 1
	int nCurIndex = listParams1.GetCurSel();
	CString csCurSel;
	listParams1.GetText( nCurIndex, csCurSel );
	csaArguments->Add( csCurSel );

}


/***************************************************************************DC

	Operation:	CAPIGenDlg::Read1L1E() 

	Purpose:	Reads one listbox + one edit control

	Arguments:	csaArguments	-- the argument array

	Note:		

*****************************************************************************/
void CAPIGenDlg::Read1L1E( CStringArray* csaArguments )
{
	// listbox 1
	int nCurIndex = listParams1.GetCurSel();
	CString csCurSel;
	listParams1.GetText( nCurIndex, csCurSel );
	csaArguments->Add( csCurSel );

	// edit controls
	csaArguments->Add( m_csEditArgument1 );
}


/***************************************************************************DC

	Operation:	CAPIGenDlg::Read1C1L1C1E() 

	Purpose:	Reads one listbox + one checkbox + one edit control

	Arguments:	csaArguments	-- the argument array

	Note:		

*****************************************************************************/
void CAPIGenDlg::Read1C1L1C1E( CStringArray* csaArguments )
{
	// checkbox 1
	if ( bCheckParam1 )
	{
		csaArguments->Add( "TRUE" );
	}
	else
	{
		csaArguments->Add( "FALSE" );
	}

	// listbox 1
	int nCurIndex = listParams1.GetCurSel();
	CString csCurSel;
	listParams1.GetText( nCurIndex, csCurSel );
	csaArguments->Add( csCurSel );

	// checkbox 2
	if ( bCheckParam2 )
	{
		csaArguments->Add( "TRUE" );
	}
	else
	{
		csaArguments->Add( "FALSE" );
	}

	// edit controls
	csaArguments->Add( m_csEditArgument1 );
}




/***************************************************************************DC

	Operation:	CAPIGenDlg::Read1E2L1E2L3E1L1E() 

	Purpose:	Reads one edit control + two listboxes + one edit control
				+ two listboxes + three edit controls + one listbox +
				one edit control

	Arguments:	csaArguments	-- the argument array

	Note:		

*****************************************************************************/
void CAPIGenDlg::Read1E2L1E2L3E1L1E( CStringArray* csaArguments )
{
	// first edit control
	csaArguments->Add( m_csEditArgument1 );

	// listbox 1
	int nCurIndex = listParams1.GetCurSel();
	CString csCurSel;
	listParams1.GetText( nCurIndex, csCurSel );
	csaArguments->Add( csCurSel );

	// listbox 2
	nCurIndex = listParams2.GetCurSel();
	listParams2.GetText( nCurIndex, csCurSel );
	csaArguments->Add( csCurSel );

	// second edit control
	csaArguments->Add( m_csEditArgument3 );

	// listbox 3
	nCurIndex = listParams3.GetCurSel();
	listParams3.GetText( nCurIndex, csCurSel );
	csaArguments->Add( csCurSel );

	// listbox 4
	nCurIndex = listParams4.GetCurSel();
	listParams4.GetText( nCurIndex, csCurSel );
	csaArguments->Add( csCurSel );

	// edit controls 3-5
	csaArguments->Add( m_csEditArgument4 );
	csaArguments->Add( m_csEditArgument5 );
	csaArguments->Add( m_csEditArgument6 );
	csaArguments->Add( m_csEditArgument7 );

	// listbox 5
	nCurIndex = listParams5.GetCurSel();
	listParams5.GetText( nCurIndex, csCurSel );
	csaArguments->Add( csCurSel );

	// edit control 6
	csaArguments->Add( m_csEditArgument8 );

}



/***************************************************************************DC

	Operation:	CAPIGenDlg::Read1E1L1C() 

	Purpose:	Reads one edit control + one listbox + one checkbox

	Arguments:	csaArguments	-- the argument array

	Note:		

*****************************************************************************/
void CAPIGenDlg::Read1E1L1C( CStringArray* csaArguments )
{
	// edit control
	csaArguments->Add( m_csEditArgument1 );

	// listbox 1
	int nCurIndex = listParams1.GetCurSel();
	CString csCurSel;
	listParams1.GetText( nCurIndex, csCurSel );
	csaArguments->Add( csCurSel );

	// checkbox 1
	if ( bCheckParam1 )
	{
		csaArguments->Add( "TRUE" );
	}
	else
	{
		csaArguments->Add( "FALSE" );
	}

}


/***************************************************************************DC

	Operation:	CAPIGenDlg::Read1E1L1E() 

	Purpose:	Reads one edit control + one listbox + one edit control

	Arguments:	csaArguments	-- the argument array

	Note:		

*****************************************************************************/
void CAPIGenDlg::Read1E1L1E( CStringArray* csaArguments )
{
	// edit control
	csaArguments->Add( m_csEditArgument1 );

	// listbox 1
	int nCurIndex = listParams1.GetCurSel();
	CString csCurSel;
	listParams1.GetText( nCurIndex, csCurSel );
	csaArguments->Add( csCurSel );

	// second edit control
	csaArguments->Add( m_csEditArgument3 );

}



/***************************************************************************DC

	Operation:	CAPIGenDlg::Read1E1L2E() 

	Purpose:	Reads one edit control + one listbox + two edit controls

	Arguments:	csaArguments	-- the argument array

	Note:		

*****************************************************************************/
void CAPIGenDlg::Read1E1L2E( CStringArray* csaArguments )
{
	// edit control
	csaArguments->Add( m_csEditArgument1 );

	// listbox 1
	int nCurIndex = listParams1.GetCurSel();
	CString csCurSel;
	listParams1.GetText( nCurIndex, csCurSel );
	csaArguments->Add( csCurSel );

	// second edit control
	csaArguments->Add( m_csEditArgument3 );
	csaArguments->Add( m_csEditArgument4 );

}


/***************************************************************************DC

	Operation:	CAPIGenDlg::Read1E2L() 

	Purpose:	Reads one edit control + two listboxes

	Arguments:	csaArguments	-- the argument array

	Note:		

*****************************************************************************/
void CAPIGenDlg::Read1E2L( CStringArray* csaArguments )
{
	// first edit control
	csaArguments->Add( m_csEditArgument1 );

	// listbox 1
	int nCurIndex = listParams1.GetCurSel();
	CString csCurSel;
	listParams1.GetText( nCurIndex, csCurSel );
	csaArguments->Add( csCurSel );

	// listbox 2
	nCurIndex = listParams2.GetCurSel();
	listParams2.GetText( nCurIndex, csCurSel );
	csaArguments->Add( csCurSel );

}


/***************************************************************************DC

	Operation:	CAPIGenDlg::Read1C2E() 

	Purpose:	Reads one checkbox + two edit controls

	Arguments:	csaArguments	-- the argument array

	Note:		

*****************************************************************************/
void CAPIGenDlg::Read1C2E( CStringArray* csaArguments )
{
	// checkbox
	if ( bCheckParam1 )
	{
		csaArguments->Add( "TRUE" );
	}
	else
	{
		csaArguments->Add( "FALSE" );
	}

	// edit control
	csaArguments->Add( m_csEditArgument1 );
	csaArguments->Add( m_csEditArgument3 );

}




/***************************************************************************DC

	Operation:	CAPIGenDlg::Read1L3E() 

	Purpose:	Reads one edit control + two listboxes

	Arguments:	csaArguments	-- the argument array

	Note:		

*****************************************************************************/
void CAPIGenDlg::Read1L3E( CStringArray* csaArguments )
{
	// listbox 1
	int nCurIndex = listParams1.GetCurSel();
	CString csCurSel;
	listParams1.GetText( nCurIndex, csCurSel );
	csaArguments->Add( csCurSel );

	// edit controls
	csaArguments->Add( m_csEditArgument1 );
	csaArguments->Add( m_csEditArgument3 );
	csaArguments->Add( m_csEditArgument4 );

}



/***************************************************************************DC

	Operation:	CAPIGenDlg::Read3L() 

	Purpose:	Reads three listboxes

	Arguments:	csaArguments	-- the argument array

	Note:		

*****************************************************************************/
void CAPIGenDlg::Read3L( CStringArray* csaArguments )
{
	// listbox 1
	int nCurIndex = listParams1.GetCurSel();
	CString csCurSel;
	listParams1.GetText( nCurIndex, csCurSel );
	csaArguments->Add( csCurSel );

	// listbox 2
	nCurIndex = listParams2.GetCurSel();
	listParams2.GetText( nCurIndex, csCurSel );
	csaArguments->Add( csCurSel );

	// listbox 3
	nCurIndex = listParams3.GetCurSel();
	listParams3.GetText( nCurIndex, csCurSel );
	csaArguments->Add( csCurSel );
}



/***************************************************************************DC

	Operation:	CAPIGenDlg::Read3L2E() 

	Purpose:	Reads three listboxes

	Arguments:	csaArguments	-- the argument array

	Note:		

*****************************************************************************/
void CAPIGenDlg::Read3L2E( CStringArray* csaArguments )
{
	// listbox 1
	int nCurIndex = listParams1.GetCurSel();
	CString csCurSel;
	listParams1.GetText( nCurIndex, csCurSel );
	csaArguments->Add( csCurSel );

	// listbox 2
	nCurIndex = listParams2.GetCurSel();
	listParams2.GetText( nCurIndex, csCurSel );
	csaArguments->Add( csCurSel );

	// listbox 3
	nCurIndex = listParams3.GetCurSel();
	listParams3.GetText( nCurIndex, csCurSel );
	csaArguments->Add( csCurSel );

	// edit controls
	csaArguments->Add( m_csEditArgument1 );
	csaArguments->Add( m_csEditArgument3 );

}



/***************************************************************************DC

	Operation:	CAPIGenDlg::Read1L2E() 

	Purpose:	Reads one listbox + two edit controls

	Arguments:	csaArguments	-- the argument array

	Note:		

*****************************************************************************/
void CAPIGenDlg::Read1L2E( CStringArray* csaArguments )
{
	// listbox 1
	int nCurIndex = listParams1.GetCurSel();
	CString csCurSel;
	listParams1.GetText( nCurIndex, csCurSel );
	csaArguments->Add( csCurSel );

	// edit controls
	csaArguments->Add( m_csEditArgument1 );
	csaArguments->Add( m_csEditArgument3 );

}


/***************************************************************************DC

	Operation:	CAPIGenDlg::Read1ML() 

	Purpose:	Reads one multiple selection listbox

	Arguments:	csaArguments	-- the argument array

	Note:		

*****************************************************************************/
void CAPIGenDlg::Read1ML( CStringArray* csaArguments )
{
	// multi selection listbox 1
	CString csCurSel;
	CString csSelList;
	
	int nCount = listMultiParams1.GetSelCount();
	CArray<int,int> caSelectedItems;

	caSelectedItems.SetSize(nCount);
	listMultiParams1.GetSelItems(nCount, caSelectedItems.GetData());

	for ( int i=0; i<caSelectedItems.GetCount(); i++)
	{
		listMultiParams1.GetText(caSelectedItems.GetAt( i ), csCurSel );
		csSelList += csCurSel;
	}
	csaArguments->Add( csSelList );

}



/***************************************************************************DC

	Operation:	CAPIGenDlg::Read1ML2E() 

	Purpose:	Reads one multiple selection listbox + two edit controls

	Arguments:	csaArguments	-- the argument array

	Note:		

*****************************************************************************/
void CAPIGenDlg::Read1ML2E( CStringArray* csaArguments )
{
	// multi selection listbox 1
	CString csCurSel;
	CString csSelList;
	
	int nCount = listMultiParams1.GetSelCount();
	CArray<int,int> caSelectedItems;

	caSelectedItems.SetSize(nCount);
	listMultiParams1.GetSelItems(nCount, caSelectedItems.GetData());

	for ( int i=0; i<caSelectedItems.GetCount(); i++)
	{
		listMultiParams1.GetText(caSelectedItems.GetAt( i ), csCurSel );
		csSelList += csCurSel;
	}
	csaArguments->Add( csSelList );

	// edit controls
	csaArguments->Add( m_csEditArgument1 );
	csaArguments->Add( m_csEditArgument3 );

}


/***************************************************************************DC

	Operation:	CAPIGenDlg::Read1ML3E() 

	Purpose:	Reads one multiple selection listbox + three edit controls

	Arguments:	csaArguments	-- the argument array

	Note:		

*****************************************************************************/
void CAPIGenDlg::Read1ML3E( CStringArray* csaArguments )
{
	// multi selection listbox 1
	CString csCurSel;
	CString csSelList;
	
	int nCount = listMultiParams1.GetSelCount();
	CArray<int,int> caSelectedItems;

	caSelectedItems.SetSize(nCount);
	listMultiParams1.GetSelItems(nCount, caSelectedItems.GetData());

	for ( int i=0; i<caSelectedItems.GetCount(); i++)
	{
		listMultiParams1.GetText(caSelectedItems.GetAt( i ), csCurSel );
		csSelList += csCurSel;
	}
	csaArguments->Add( csSelList );

	// edit controls
	csaArguments->Add( m_csEditArgument1 );
	csaArguments->Add( m_csEditArgument3 );
	csaArguments->Add( m_csEditArgument4 );

}


/***************************************************************************DC

	Operation:	CAPIGenDlg::Read1ML4E() 

	Purpose:	Reads one multiple selection listbox + four edit controls

	Arguments:	csaArguments	-- the argument array

	Note:		

*****************************************************************************/
void CAPIGenDlg::Read1ML4E( CStringArray* csaArguments )
{
	// multi selection listbox 1
	//int nCurIndex; // = listMultiParams1.GetCurSel();
	CString csCurSel;
	CString csSelList;
	
	int nCount = listMultiParams1.GetSelCount();
	CArray<int,int> caSelectedItems;

	caSelectedItems.SetSize(nCount);
	listMultiParams1.GetSelItems(nCount, caSelectedItems.GetData());

	for ( int i=0; i<caSelectedItems.GetCount(); i++)
	{
		listMultiParams1.GetText(caSelectedItems.GetAt( i ), csCurSel );
		csSelList += csCurSel;
	}
	csaArguments->Add( csSelList );

	// edit controls
	csaArguments->Add( m_csEditArgument1 );
	csaArguments->Add( m_csEditArgument3 );
	csaArguments->Add( m_csEditArgument4 );
	csaArguments->Add( m_csEditArgument5 );

}



/***************************************************************************DC

	Operation:	CAPIGenDlg::Read1L1ML2E() 

	Purpose:	Reads one single selection listbox + one multiple selection 
				listbox + two edit controls

	Arguments:	csaArguments	-- the argument array

	Note:		

*****************************************************************************/
void CAPIGenDlg::Read1L1ML2E( CStringArray* csaArguments )
{
	CString csCurSel;
	CString csSelList;
	int i, nCount;
	

	// single selection listbox
	int nCurIndex = listParams1.GetCurSel();
	listParams1.GetText( nCurIndex, csCurSel );
	csaArguments->Add( csCurSel );

	// multiselection listbox
	nCount = listMultiParams1.GetSelCount();
	CArray<int,int> caSelectedItems;

	caSelectedItems.SetSize(nCount);
	listMultiParams1.GetSelItems(nCount, caSelectedItems.GetData());

	for ( i=0; i<caSelectedItems.GetCount(); i++)
	{
		listMultiParams1.GetText(caSelectedItems.GetAt( i ), csCurSel );
		csSelList += csCurSel;
	}
	csaArguments->Add( csSelList );


	// edit controls
	csaArguments->Add( m_csEditArgument1 );
	csaArguments->Add( m_csEditArgument3 );

}



/***************************************************************************DC

	Operation:	CAPIGenDlg::Read2ML1L1ML1E() 

	Purpose:	Reads two multiple selection listboxes + one single selection
				listbox + one multiple selection listbox + one edit control

	Arguments:	csaArguments	-- the argument array

	Note:		

*****************************************************************************/
void CAPIGenDlg::Read2ML1L1ML1E( CStringArray* csaArguments )
{
	CString csCurSel;
	CString csSelList;
	int i, nCount;
	
	// first multiselection listbox
	nCount = listMultiParams1.GetSelCount();
	CArray<int,int> caSelectedItems;

	caSelectedItems.SetSize(nCount);
	listMultiParams1.GetSelItems(nCount, caSelectedItems.GetData());

	for ( i=0; i<caSelectedItems.GetCount(); i++)
	{
		listMultiParams1.GetText(caSelectedItems.GetAt( i ), csCurSel );
		csSelList += csCurSel;
	}
	csaArguments->Add( csSelList );

	// second multiselection listbox
	csSelList="";
	nCount = listMultiParams2.GetSelCount();
	caSelectedItems.SetSize(nCount);
	listMultiParams2.GetSelItems(nCount, caSelectedItems.GetData());

	for ( i=0; i<caSelectedItems.GetCount(); i++)
	{
		listMultiParams2.GetText(caSelectedItems.GetAt( i ), csCurSel );
		csSelList += csCurSel;
	}
	csaArguments->Add( csSelList );


	// single selection listbox
	int nCurIndex = listParams1.GetCurSel();
	listParams1.GetText( nCurIndex, csCurSel );
	csaArguments->Add( csCurSel );


	// third multiselection listbox
	csSelList="";
	nCount = listMultiParams3.GetSelCount();
	caSelectedItems.SetSize(nCount);
	listMultiParams3.GetSelItems(nCount, caSelectedItems.GetData());

	for ( i=0; i<caSelectedItems.GetCount(); i++)
	{
		listMultiParams3.GetText(caSelectedItems.GetAt( i ), csCurSel );
		csSelList += csCurSel;
	}
	csaArguments->Add( csSelList );


	// edit control
	csaArguments->Add( m_csEditArgument1 );

}




/***************************************************************************DC

	Operation:	CAPIGenDlg::Read2E1C() 

	Purpose:	Reads two edit controls + one checkbox

	Arguments:	csaArguments	-- the argument array

	Note:		

*****************************************************************************/
void CAPIGenDlg::Read2E1C( CStringArray* csaArguments )
{
	// edit controls
	csaArguments->Add( m_csEditArgument1 );
	csaArguments->Add( m_csEditArgument3 );

	// checkbox 1
	if ( bCheckParam1 )
	{
		csaArguments->Add( "TRUE" );
	}
	else
	{
		csaArguments->Add( "FALSE" );
	}

}


/***************************************************************************DC

	Operation:	CAPIGenDlg::Read2E1C1E() 

	Purpose:	Reads two edit controls + one checkbox + one edit control

	Arguments:	csaArguments	-- the argument array

	Note:		

*****************************************************************************/
void CAPIGenDlg::Read2E1C1E( CStringArray* csaArguments )
{
	// edit controls
	csaArguments->Add( m_csEditArgument1 );
	csaArguments->Add( m_csEditArgument3 );

	// checkbox 1
	if ( bCheckParam1 )
	{
		csaArguments->Add( "TRUE" );
	}
	else
	{
		csaArguments->Add( "FALSE" );
	}

	csaArguments->Add( m_csEditArgument4 );
}



/***************************************************************************DC

	Operation:	CAPIGenDlg::Read2E1C1E1C2E() 

	Purpose:	Reads two edit controls + one checkbox + one edit control +
				one checkbox + two edit controls

	Arguments:	csaArguments	-- the argument array

	Note:		

*****************************************************************************/
void CAPIGenDlg::Read2E1C1E1C2E( CStringArray* csaArguments )
{
	// edit controls
	csaArguments->Add( m_csEditArgument1 );
	csaArguments->Add( m_csEditArgument3 );

	// checkbox 1
	if ( bCheckParam1 )
	{
		csaArguments->Add( "TRUE" );
	}
	else
	{
		csaArguments->Add( "FALSE" );
	}

	csaArguments->Add( m_csEditArgument4 );

	// checkbox 2
	if ( bCheckParam2 )
	{
		csaArguments->Add( "TRUE" );
	}
	else
	{
		csaArguments->Add( "FALSE" );
	}

	// edit controls
	csaArguments->Add( m_csEditArgument5 );
	csaArguments->Add( m_csEditArgument6 );

}


/***************************************************************************DC

	Operation:	CAPIGenDlg::Read1L5E1C() 

	Purpose:	Reads one listbox + five edit controls + one checkbox

	Arguments:	csaArguments	-- the argument array

	Note:		

*****************************************************************************/
void CAPIGenDlg::Read1L5E1C( CStringArray* csaArguments )
{
	// listbox 1
	int nCurIndex = listParams1.GetCurSel();
	CString csCurSel;
	listParams1.GetText( nCurIndex, csCurSel );
	csaArguments->Add( csCurSel );

	// edit controls
	csaArguments->Add( m_csEditArgument1 );
	csaArguments->Add( m_csEditArgument3 );
	csaArguments->Add( m_csEditArgument4 );
	csaArguments->Add( m_csEditArgument5 );
	csaArguments->Add( m_csEditArgument6 );

	// checkbox 1
	if ( bCheckParam1 )
	{
		csaArguments->Add( "TRUE" );
	}
	else
	{
		csaArguments->Add( "FALSE" );
	}

}


/***************************************************************************DC

	Operation:	CAPIGenDlg::Read5E() 

	Purpose:	Reads five edit controls

	Arguments:	csaArguments	-- the argument array

	Note:		

*****************************************************************************/
void CAPIGenDlg::Read5E( CStringArray* csaArguments )
{
	// edit controls
	csaArguments->Add( m_csEditArgument1 );
	csaArguments->Add( m_csEditArgument3 );
	csaArguments->Add( m_csEditArgument4 );
	csaArguments->Add( m_csEditArgument5 );
	csaArguments->Add( m_csEditArgument6 );
}


/***************************************************************************DC

	Operation:	CAPIGenDlg::Read6E() 

	Purpose:	Reads six edit controls

	Arguments:	csaArguments	-- the argument array

	Note:		

*****************************************************************************/
void CAPIGenDlg::Read6E( CStringArray* csaArguments )
{
	// edit controls
	csaArguments->Add( m_csEditArgument1 );
	csaArguments->Add( m_csEditArgument3 );
	csaArguments->Add( m_csEditArgument4 );
	csaArguments->Add( m_csEditArgument5 );
	csaArguments->Add( m_csEditArgument6 );
	csaArguments->Add( m_csEditArgument7 );
}


/***************************************************************************DC

	Operation:	CAPIGenDlg::Read8E() 

	Purpose:	Reads eight edit controls

	Arguments:	csaArguments	-- the argument array

	Note:		

*****************************************************************************/
void CAPIGenDlg::Read8E( CStringArray* csaArguments )
{
	// edit controls
	csaArguments->Add( m_csEditArgument1 );
	csaArguments->Add( m_csEditArgument3 );
	csaArguments->Add( m_csEditArgument4 );
	csaArguments->Add( m_csEditArgument5 );
	csaArguments->Add( m_csEditArgument6 );
	csaArguments->Add( m_csEditArgument7 );
	csaArguments->Add( m_csEditArgument8 );
	csaArguments->Add( m_csEditArgument9 );
}


/***************************************************************************DC

	Operation:	CAPIGenDlg::Read9E() 

	Purpose:	Reads nine edit controls

	Arguments:	csaArguments	-- the argument array

	Note:		

*****************************************************************************/
void CAPIGenDlg::Read9E( CStringArray* csaArguments )
{
	// edit controls
	csaArguments->Add( m_csEditArgument1 );
	csaArguments->Add( m_csEditArgument3 );
	csaArguments->Add( m_csEditArgument4 );
	csaArguments->Add( m_csEditArgument5 );
	csaArguments->Add( m_csEditArgument6 );
	csaArguments->Add( m_csEditArgument7 );
	csaArguments->Add( m_csEditArgument8 );
	csaArguments->Add( m_csEditArgument9 );
	csaArguments->Add( m_csEditArgument10 );
}

/***************************************************************************DC

	Operation:	CAPIGenDlg::Read10E() 

	Purpose:	Reads ten edit controls

	Arguments:	csaArguments	-- the argument array

	Note:		

*****************************************************************************/
void CAPIGenDlg::Read10E( CStringArray* csaArguments )
{
	// edit controls
	csaArguments->Add( m_csEditArgument1 );
	csaArguments->Add( m_csEditArgument3 );
	csaArguments->Add( m_csEditArgument4 );
	csaArguments->Add( m_csEditArgument5 );
	csaArguments->Add( m_csEditArgument6 );
	csaArguments->Add( m_csEditArgument7 );
	csaArguments->Add( m_csEditArgument8 );
	csaArguments->Add( m_csEditArgument9 );
	csaArguments->Add( m_csEditArgument10 );
	csaArguments->Add( m_csEditArgument11 );
}


/***************************************************************************DC

	Operation:	CAPIGenDlg::Read5E1L() 

	Purpose:	Reads five edit controls + one listbox

	Arguments:	csaArguments	-- the argument array

	Note:		

*****************************************************************************/
void CAPIGenDlg::Read5E1L( CStringArray* csaArguments )
{
	// edit controls
	csaArguments->Add( m_csEditArgument1 );
	csaArguments->Add( m_csEditArgument3 );
	csaArguments->Add( m_csEditArgument4 );
	csaArguments->Add( m_csEditArgument5 );
	csaArguments->Add( m_csEditArgument6 );

	// listbox 1
	int nCurIndex = listParams1.GetCurSel();
	CString csCurSel;
	listParams1.GetText( nCurIndex, csCurSel );
	csaArguments->Add( csCurSel );

}



/***************************************************************************DC

	Operation:	CAPIGenDlg::Read5E1ML1L2E() 

	Purpose:	Reads five edit controls + one multi-selection listbox +
				one listbox + two edit controls

	Arguments:	csaArguments	-- the argument array

	Note:		

*****************************************************************************/
void CAPIGenDlg::Read5E1ML1L2E( CStringArray* csaArguments )
{
	CString csCurSel;
	CString csSelList;
	
	// edit controls
	csaArguments->Add( m_csEditArgument1 );
	csaArguments->Add( m_csEditArgument3 );
	csaArguments->Add( m_csEditArgument4 );
	csaArguments->Add( m_csEditArgument5 );
	csaArguments->Add( m_csEditArgument6 );

	int nCount = listMultiParams1.GetSelCount();
	CArray<int,int> caSelectedItems;

	caSelectedItems.SetSize(nCount);
	listMultiParams1.GetSelItems(nCount, caSelectedItems.GetData());

	for ( int i=0; i<caSelectedItems.GetCount(); i++)
	{
		listMultiParams1.GetText(caSelectedItems.GetAt( i ), csCurSel );
		csSelList += csCurSel;
	}
	csaArguments->Add( csSelList );

	// listbox
	int nCurIndex = listParams1.GetCurSel();
	listParams1.GetText( nCurIndex, csCurSel );
	csaArguments->Add( csCurSel );

	csaArguments->Add( m_csEditArgument7 );
	csaArguments->Add( m_csEditArgument8 );
}


/***************************************************************************DC

	Operation:	CAPIGenDlg::Read1C() 

	Purpose:	Reads one checkbox

	Arguments:	csaArguments	-- the argument array

	Note:		

*****************************************************************************/
void CAPIGenDlg::Read1C( CStringArray* csaArguments )
{
	// checkbox 1
	if ( bCheckParam1 )
	{
		csaArguments->Add( "TRUE" );
	}
	else
	{
		csaArguments->Add( "FALSE" );
	}

}




/***************************************************************************DC

	Operation:	CAPIGenDlg::Read1L5E1L() 

	Purpose:	Reads one listbox + five edit controls + one listbox

	Arguments:	csaArguments	-- the argument array

	Note:		

*****************************************************************************/
void CAPIGenDlg::Read1L5E1L( CStringArray* csaArguments )
{
	// listbox 1
	int nCurIndex = listParams1.GetCurSel();
	CString csCurSel;
	listParams1.GetText( nCurIndex, csCurSel );
	csaArguments->Add( csCurSel );

	// edit controls
	csaArguments->Add( m_csEditArgument1 );
	csaArguments->Add( m_csEditArgument3 );
	csaArguments->Add( m_csEditArgument4 );
	csaArguments->Add( m_csEditArgument5 );
	csaArguments->Add( m_csEditArgument6 );

	// listbox 2
	nCurIndex = listParams2.GetCurSel();
	listParams2.GetText( nCurIndex, csCurSel );
	csaArguments->Add( csCurSel );

}



/***************************************************************************DC

	Operation:	CAPIGenDlg::Read2E2C() 

	Purpose:	Reads two edit controls + two checkboxes

	Arguments:	csaArguments	-- the argument array

	Note:		

*****************************************************************************/
void CAPIGenDlg::Read2E2C( CStringArray* csaArguments )
{
	// two edit controls
	csaArguments->Add( m_csEditArgument1 );
	csaArguments->Add( m_csEditArgument3 );

	// checkbox 1
	if ( bCheckParam1 )
	{
		csaArguments->Add( "TRUE" );
	}
	else
	{
		csaArguments->Add( "FALSE" );
	}

	// checkbox 2
	if ( bCheckParam2 )
	{
		csaArguments->Add( "TRUE" );
	}
	else
	{
		csaArguments->Add( "FALSE" );
	}

}




/***************************************************************************DC

	Operation:	CAPIGenDlg::Read2E2C1E1L() 

	Purpose:	Reads two edit controls + two checkboxes + one edit control +
				one listbox

	Arguments:	csaArguments	-- the argument array

	Note:		

*****************************************************************************/
void CAPIGenDlg::Read2E2C1E1L( CStringArray* csaArguments )
{
	// two edit controls
	csaArguments->Add( m_csEditArgument1 );
	csaArguments->Add( m_csEditArgument3 );

	// checkbox 1
	if ( bCheckParam1 )
	{
		csaArguments->Add( "TRUE" );
	}
	else
	{
		csaArguments->Add( "FALSE" );
	}

	// checkbox 2
	if ( bCheckParam2 )
	{
		csaArguments->Add( "TRUE" );
	}
	else
	{
		csaArguments->Add( "FALSE" );
	}

	csaArguments->Add( m_csEditArgument4 );

	int nCurIndex = listParams1.GetCurSel();
	CString csCurSel;
	listParams1.GetText( nCurIndex, csCurSel );
	csaArguments->Add( csCurSel );

}


/***************************************************************************DC

	Operation:	CAPIGenDlg::Read2E2C1E2L1E() 

	Purpose:	Reads two edit controls + two checkboxes + one edit control +
				two listboxes + one edit control

	Arguments:	csaArguments	-- the argument array

	Note:		

*****************************************************************************/
void CAPIGenDlg::Read2E2C1E2L1E( CStringArray* csaArguments )
{
	// two edit controls
	csaArguments->Add( m_csEditArgument1 );
	csaArguments->Add( m_csEditArgument3 );

	// checkbox 1
	if ( bCheckParam1 )
	{
		csaArguments->Add( "TRUE" );
	}
	else
	{
		csaArguments->Add( "FALSE" );
	}

	// checkbox 2
	if ( bCheckParam2 )
	{
		csaArguments->Add( "TRUE" );
	}
	else
	{
		csaArguments->Add( "FALSE" );
	}

	csaArguments->Add( m_csEditArgument4 );

	int nCurIndex = listParams1.GetCurSel();
	CString csCurSel;
	listParams1.GetText( nCurIndex, csCurSel );
	csaArguments->Add( csCurSel );

	nCurIndex = listParams2.GetCurSel();
	listParams2.GetText( nCurIndex, csCurSel );
	if ( -1 != csCurSel.Find("None") )
	{
		csaArguments->Add( "0" );
	}
	else if ( -1 != csCurSel.Find("AMD64") )
	{
		csaArguments->Add( "4" );
	}
	else if ( -1 != csCurSel.Find("IA64") )
	{
		csaArguments->Add( "2" );
	}
	else if ( -1 != csCurSel.Find("X86") )
	{
		csaArguments->Add( "1" );
	}
	else
	{
		csaArguments->Add( "0" );
	}



	// two edit controls
	csaArguments->Add( m_csEditArgument5 );
}



/***************************************************************************DC

	Operation:	CAPIGenDlg::Read2E3C() 

	Purpose:	Reads two edit controls + two checkboxes

	Arguments:	csaArguments	-- the argument array

	Note:		

*****************************************************************************/
void CAPIGenDlg::Read2E3C( CStringArray* csaArguments )
{
	// two edit controls
	csaArguments->Add( m_csEditArgument1 );
	csaArguments->Add( m_csEditArgument3 );

	// checkbox 1
	if ( bCheckParam1 )
	{
		csaArguments->Add( "TRUE" );
	}
	else
	{
		csaArguments->Add( "FALSE" );
	}

	// checkbox 2
	if ( bCheckParam2 )
	{
		csaArguments->Add( "TRUE" );
	}
	else
	{
		csaArguments->Add( "FALSE" );
	}

	// checkbox 3
	if ( bCheckParam3 )
	{
		csaArguments->Add( "TRUE" );
	}
	else
	{
		csaArguments->Add( "FALSE" );
	}

}


/***************************************************************************DC

	Operation:	CAPIGenDlg::Read2E4C1E() 

	Purpose:	Reads two edit controls + four checkboxes + one edit control

	Arguments:	csaArguments	-- the argument array

	Note:		

*****************************************************************************/
void CAPIGenDlg::Read2E4C1E( CStringArray* csaArguments )
{
	// two edit controls
	csaArguments->Add( m_csEditArgument1 );
	csaArguments->Add( m_csEditArgument3 );

	// checkbox 1
	if ( bCheckParam1 )
	{
		csaArguments->Add( "TRUE" );
	}
	else
	{
		csaArguments->Add( "FALSE" );
	}

	// checkbox 2
	if ( bCheckParam2 )
	{
		csaArguments->Add( "TRUE" );
	}
	else
	{
		csaArguments->Add( "FALSE" );
	}

	// checkbox 3
	if ( bCheckParam3 )
	{
		csaArguments->Add( "TRUE" );
	}
	else
	{
		csaArguments->Add( "FALSE" );
	}

	// checkbox 4
	if ( bCheckParam4 )
	{
		csaArguments->Add( "TRUE" );
	}
	else
	{
		csaArguments->Add( "FALSE" );
	}

	csaArguments->Add( m_csEditArgument4 );

}



/***************************************************************************DC

	Operation:	CAPIGenDlg::Read1E1ML1E1C() 

	Purpose:	Reads one checkbox + one edit control + one listbox + 
				one multilist control + one checkbox + one edit control

	Arguments:	csaArguments -- the argument array

	Note:		

*****************************************************************************/
void CAPIGenDlg::Read1E1ML1E1C( CStringArray* csaArguments )
{
	// edit control #1
	csaArguments->Add( m_csEditArgument1 );

	// multi-selection listbox
	int nCount = listMultiParams1.GetSelCount();
	CArray<int,int> caSelectedItems;
	CString csCurSel2;
	CString csSelList;

	caSelectedItems.SetSize(nCount);
	listMultiParams1.GetSelItems(nCount, caSelectedItems.GetData());

	for ( int i=0; i<caSelectedItems.GetCount(); i++)
	{
		listMultiParams1.GetText(caSelectedItems.GetAt( i ), csCurSel2 );
		csSelList += csCurSel2;
	}

	csaArguments->Add( csSelList );

	csaArguments->Add( m_csEditArgument3 );

	// checkbox 1
	if ( bCheckParam1 )
	{
		csaArguments->Add( "TRUE" );
	}
	else
	{
		csaArguments->Add( "FALSE" );
	}


}


/***************************************************************************DC

	Operation:	CAPIGenDlg::Read1C1E1L1ML1C1E() 

	Purpose:	Reads one checkbox + one edit control + one listbox + 
				one multilist control + one checkbox + one edit control

	Arguments:	csaArguments -- the argument array

	Note:		

*****************************************************************************/
void CAPIGenDlg::Read1C1E1L1ML1C1E( CStringArray* csaArguments )
{
	// checkbox 1
	if ( bCheckParam1 )
	{
		csaArguments->Add( "TRUE" );
	}
	else
	{
		csaArguments->Add( "FALSE" );
	}

	// edit control #1
	csaArguments->Add( m_csEditArgument1 );

	
	// listbox 1
	int nCurIndex = listParams1.GetCurSel();
	CString csCurSel;
	listParams1.GetText( nCurIndex, csCurSel );
	csaArguments->Add( csCurSel );

	// multi-selection listbox
	int nCount = listMultiParams1.GetSelCount();
	CArray<int,int> caSelectedItems;
	CString csCurSel2;
	CString csSelList;

	caSelectedItems.SetSize(nCount);
	listMultiParams1.GetSelItems(nCount, caSelectedItems.GetData());

	for ( int i=0; i<caSelectedItems.GetCount(); i++)
	{
		listMultiParams1.GetText(caSelectedItems.GetAt( i ), csCurSel2 );
		csSelList += csCurSel2;
	}

	csaArguments->Add( csSelList );

	// checkbox 3
	if ( bCheckParam2 )
	{
		csaArguments->Add( "TRUE" );
	}
	else
	{
		csaArguments->Add( "FALSE" );
	}

	csaArguments->Add( m_csEditArgument3 );

}



/***************************************************************************DC

	Operation:	CAPIGenDlg::Read2E1L2E() 

	Purpose:	Reads two edit controls + one listbox + two edit controls

	Arguments:	csaArguments	-- the argument array

	Note:		

*****************************************************************************/
void CAPIGenDlg::Read2E1L2E( CStringArray* csaArguments )
{
	// first two edit controls
	csaArguments->Add( m_csEditArgument1 );
	csaArguments->Add( m_csEditArgument3 );

	// listbox 1
	int nCurIndex = listParams1.GetCurSel();
	CString csCurSel;
	listParams1.GetText( nCurIndex, csCurSel );
	csaArguments->Add( csCurSel );

	// last two edit controls
	csaArguments->Add( m_csEditArgument4 );
	csaArguments->Add( m_csEditArgument5 );
}



/***************************************************************************DC

	Operation:	CAPIGenDlg::Read2E1L3E() 

	Purpose:	Reads two edit controls + one listbox + three edit controls

	Arguments:	csaArguments	-- the argument array

	Note:		

*****************************************************************************/
void CAPIGenDlg::Read2E1L3E( CStringArray* csaArguments )
{
	// first two edit controls
	csaArguments->Add( m_csEditArgument1 );
	csaArguments->Add( m_csEditArgument3 );

	// listbox 1
	int nCurIndex = listParams1.GetCurSel();
	CString csCurSel;
	listParams1.GetText( nCurIndex, csCurSel );
	csaArguments->Add( csCurSel );

	// last three edit controls
	csaArguments->Add( m_csEditArgument4 );
	csaArguments->Add( m_csEditArgument5 );
	csaArguments->Add( m_csEditArgument6 );
}



/***************************************************************************DC

	Operation:	CAPIGenDlg::Read2E1L4E() 

	Purpose:	Reads two edit controls + one listbox + four edit controls

	Arguments:	csaArguments	-- the argument array

	Note:		

*****************************************************************************/
void CAPIGenDlg::Read2E1L4E( CStringArray* csaArguments )
{
	// first two edit controls
	csaArguments->Add( m_csEditArgument1 );
	csaArguments->Add( m_csEditArgument3 );

	// listbox 1
	int nCurIndex = listParams1.GetCurSel();
	CString csCurSel;
	listParams1.GetText( nCurIndex, csCurSel );
	csaArguments->Add( csCurSel );

	// last three edit controls
	csaArguments->Add( m_csEditArgument4 );
	csaArguments->Add( m_csEditArgument5 );
	csaArguments->Add( m_csEditArgument6 );
	csaArguments->Add( m_csEditArgument7 );
}




/***************************************************************************DC

	Operation:	CAPIGenDlg::Read2E1L1C() 

	Purpose:	Reads two edit controls + one listbox + one checkbox

	Arguments:	csaArguments	-- the argument array

	Note:		

*****************************************************************************/
void CAPIGenDlg::Read2E1L1C( CStringArray* csaArguments )
{
	// edit controls
	csaArguments->Add( m_csEditArgument1 );
	csaArguments->Add( m_csEditArgument3 );

	// listbox 1
	int nCurIndex = listParams1.GetCurSel();
	CString csCurSel;
	listParams1.GetText( nCurIndex, csCurSel );
	csaArguments->Add( csCurSel );

	// checkbox 1
	if ( bCheckParam1 )
	{
		csaArguments->Add( "TRUE" );
	}
	else
	{
		csaArguments->Add( "FALSE" );
	}

}



/***************************************************************************DC

	Operation:	CAPIGenDlg::Read4E2C() 

	Purpose:	Reads four edit controls + two checkboxes

	Arguments:	csaArguments	-- the argument array

	Note:		

*****************************************************************************/
void CAPIGenDlg::Read4E2C( CStringArray* csaArguments )
{
	// two edit controls
	csaArguments->Add( m_csEditArgument1 );
	csaArguments->Add( m_csEditArgument3 );
	csaArguments->Add( m_csEditArgument4 );
	csaArguments->Add( m_csEditArgument5 );

	// checkbox 1
	if ( bCheckParam1 )
	{
		csaArguments->Add( "TRUE" );
	}
	else
	{
		csaArguments->Add( "FALSE" );
	}

	// checkbox 2
	if ( bCheckParam2 )
	{
		csaArguments->Add( "TRUE" );
	}
	else
	{
		csaArguments->Add( "FALSE" );
	}

}



/***************************************************************************DC

	Operation:	CAPIGenDlg::Read5E1C() 

	Purpose:	Reads five edit controls + one checkbox

	Arguments:	csaArguments	-- the argument array

	Note:		

*****************************************************************************/
void CAPIGenDlg::Read5E1C( CStringArray* csaArguments )
{
	// two edit controls
	csaArguments->Add( m_csEditArgument1 );
	csaArguments->Add( m_csEditArgument3 );
	csaArguments->Add( m_csEditArgument4 );
	csaArguments->Add( m_csEditArgument5 );
	csaArguments->Add( m_csEditArgument6 );

	// checkbox 1
	if ( bCheckParam1 )
	{
		csaArguments->Add( "TRUE" );
	}
	else
	{
		csaArguments->Add( "FALSE" );
	}

}

/***************************************************************************DC

	Operation:	CAPIGenDlg::Read5E1C1L() 

	Purpose:	Reads five edit controls + one checkbox + one listbox

	Arguments:	csaArguments	-- the argument array

	Note:		

*****************************************************************************/
void CAPIGenDlg::Read5E1C1L( CStringArray* csaArguments )
{
	// two edit controls
	csaArguments->Add( m_csEditArgument1 );
	csaArguments->Add( m_csEditArgument3 );
	csaArguments->Add( m_csEditArgument4 );
	csaArguments->Add( m_csEditArgument5 );
	csaArguments->Add( m_csEditArgument6 );

	// checkbox 1
	if ( bCheckParam1 )
	{
		csaArguments->Add( "TRUE" );
	}
	else
	{
		csaArguments->Add( "FALSE" );
	}

	// listbox 1
	int nCurIndex = listParams1.GetCurSel();
	CString csCurSel;
	listParams1.GetText( nCurIndex, csCurSel );
	csaArguments->Add( csCurSel );

}

/***************************************************************************DC

	Operation:	CAPIGenDlg::Read5E1C1L1C() 

	Purpose:	Reads five edit controls + one checkbox + one listbox

	Arguments:	csaArguments	-- the argument array

	Note:		

*****************************************************************************/
void CAPIGenDlg::Read5E1C1L1C( CStringArray* csaArguments )
{
	// two edit controls
	csaArguments->Add( m_csEditArgument1 );
	csaArguments->Add( m_csEditArgument3 );
	csaArguments->Add( m_csEditArgument4 );
	csaArguments->Add( m_csEditArgument5 );
	csaArguments->Add( m_csEditArgument6 );

	// checkbox 1
	if ( bCheckParam1 )
	{
		csaArguments->Add( "TRUE" );
	}
	else
	{
		csaArguments->Add( "FALSE" );
	}

	// listbox 1
	int nCurIndex = listParams1.GetCurSel();
	CString csCurSel;
	listParams1.GetText( nCurIndex, csCurSel );
	csaArguments->Add( csCurSel );

	// checkbox 2
	if ( bCheckParam2 )
	{
		csaArguments->Add( "TRUE" );
	}
	else
	{
		csaArguments->Add( "FALSE" );
	}

}

