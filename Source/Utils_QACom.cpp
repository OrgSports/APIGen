#include "stdafx.h"
#include "APIGen.h"
#include "APIGenDlg.h"

/****************************************************************************DC
	Function	:	CAPIGenDlg::LoadQAComArgumentArray()

	Purpose		:	Load the function arguments for OLE Automation.

*****************************************************************************/
void CAPIGenDlg::LoadQAComArgumentArray( int* nFunctionPosition, BOOL bPromptForValues )
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
		case 0:		// Field::getAttributes
		case 1:		// Field::getFieldAttribute
		case 2:		// Field::getLength
		case 3:		// Field::getScreenPosition
		case 4:		// Field::getText
		case 5:		// Field::isAttribSpace
		case 6:		// Field::isModified
		case 7:		// Field::setText
		case 8:		// HostSyncCallBack::isHostSyncd
		case 9:		// HostSyncRule::getChildRules
		case 10:	// HostSyncRule::getProperties
		case 11:	// HostSyncRule::setChildRules
		case 12:	// HostSyncRule::setProperties
		case 13:	// HostSyncRule::sync
		case 14:	// HostSyncRule::version
		case 15:	// MatchScreen::match
		case 16:	// QAScreen::connect 1
		case 17:	// QAScreen::connect 2
		case 18:	// QAScreen::connect 3
		case 19:	// QAScreen::disconnect
		case 20:	// QAScreen::findField
		case 21:	// QAScreen::findString 1
		case 22:	// QAScreen::findString 2
		case 23:	// QAScreen::getAllFieldInformation
		case 24:	// QAScreen::getAttributes
		case 25:	// QAScreen::getCurrentScreenName
		case 26:	// QAScreen::getCursorPosition
		case 27:	// QAScreen::getDefaultRules
		case 28:	// QAScreen::getField 1
		case 29:	// QAScreen::getField 2
		case 30:	// QAScreen::getFieldCount
		case 31:	// QAScreen::getRules
		case 32:	// QAScreen::getScreenSize
		case 33:	// QAScreen::getString
		case 34:	// QAScreen::isConnected
		case 35:	// QAScreen::isCurrentScreen
		case 36:	// QAScreen::putString
		case 37:	// QAScreen::sendKeys 1
		case 38:	// QAScreen::sendKeys 2
		case 39:	// QAScreen::sendKeys 3
		case 40:	// QAScreen::sendKeys 4
		case 41:	// QAScreen::setCursorPosition
		case 42:	// QAScreen::setFieldValue 1
		case 43:	// QAScreen::setFieldValue 2
		case 44:	// QAScreenFactory::getInstance
		case 45:	// QAScreenFactory::hosts
		case 46:	// StackEventQueue::clear
		case 47:	// StackEventQueue::pop
		case 48:	// StackEventQueue::quiet
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
			case 0:			// IField::getAttributes
			case 1:			// IField::getFieldAttribute
			case 2:			// IField::getLength
			case 3:			// IField::getScreenPosition
			case 4:			// IField::getText
			case 5:			// IField::isAttribSpace
			case 6:			// IField::isModified
			case 7:			// IField::setText
			case 8:			// IQAScreen::connect 1
			case 9:			// IQAScreen::connect 2
			case 10:		// IQAScreen::connect 3
			case 11:		// IQAScreen::disconnect
			case 12:		// IQAScreen::findField
			case 13:		// IQAScreen::findString 1
			case 14:		// IQAScreen::findString 2
			case 15:		// IQAScreen::getAllFieldInformation
			case 16:		// IQAScreen::getAttributes
			case 17:		// IQAScreen::getCurrentScreenName
			case 18:		// IQAScreen::getCursorPosition
			case 19:		// IQAScreen::getDefaultRules
			case 20:		// IQAScreen::getField 1
			case 21:		// IQAScreen::getField 2
			case 22:		// IQAScreen::getFieldCount
			case 23:		// IQAScreen::getRules
			case 24:		// IQAScreen::getScreenSize
			case 25:		// IQAScreen::getString
			case 26:		// IQAScreen::isConnected
			case 27:		// IQAScreen::isCurrentScreen
			case 28:		// IQAScreen::putString
			case 29:		// IQAScreen::sendKeys 1
			case 30:		// IQAScreen::sendKeys 2
			case 31:		// IQAScreen::sendKeys 3
			case 32:		// IQAScreen::sendKeys 4
			case 33:		// IQAScreen::setCursorPosition
			case 34:		// IQAScreen::setFieldValue 1
			case 35:		// IQAScreen::setFieldValue 2
			case 36:		// IQAScreenFactory::getInstance
			case 37:		// IQAScreenFactory::hosts
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
	Function	:	CAPIGenDlg::ShowQAComControls()

	Purpose		:	Show the controls for the EAL function parameters.

*****************************************************************************/
void CAPIGenDlg::ShowQAComControls( int nFunction )
{
	switch ( nFunction )
	{
		case 0:		// Field::getAttributes
		case 1:		// Field::getFieldAttribute
		case 2:		// Field::getLength
		case 3:		// Field::getScreenPosition
		case 4:		// Field::getText
		case 5:		// Field::isAttribSpace
		case 6:		// Field::isModified
		case 7:		// Field::setText
		case 8:		// HostSyncCallBack::isHostSyncd
		case 9:		// HostSyncRule::getChildRules
		case 10:	// HostSyncRule::getProperties
		case 11:	// HostSyncRule::setChildRules
		case 12:	// HostSyncRule::setProperties
		case 13:	// HostSyncRule::sync
		case 14:	// HostSyncRule::version
		case 15:	// MatchScreen::match
		case 16:	// QAScreen::connect 1
		case 17:	// QAScreen::connect 2
		case 18:	// QAScreen::connect 3
		case 19:	// QAScreen::disconnect
		case 20:	// QAScreen::findField
		case 21:	// QAScreen::findString 1
		case 22:	// QAScreen::findString 2
		case 23:	// QAScreen::getAllFieldInformation
		case 24:	// QAScreen::getAttributes
		case 25:	// QAScreen::getCurrentScreenName
		case 26:	// QAScreen::getCursorPosition
		case 27:	// QAScreen::getDefaultRules
		case 28:	// QAScreen::getField 1
		case 29:	// QAScreen::getField 2
		case 30:	// QAScreen::getFieldCount
		case 31:	// QAScreen::getRules
		case 32:	// QAScreen::getScreenSize
		case 33:	// QAScreen::getString
		case 34:	// QAScreen::isConnected
		case 35:	// QAScreen::isCurrentScreen
		case 36:	// QAScreen::putString
		case 37:	// QAScreen::sendKeys 1
		case 38:	// QAScreen::sendKeys 2
		case 39:	// QAScreen::sendKeys 3
		case 40:	// QAScreen::sendKeys 4
		case 41:	// QAScreen::setCursorPosition
		case 42:	// QAScreen::setFieldValue 1
		case 43:	// QAScreen::setFieldValue 2
		case 44:	// QAScreenFactory::getInstance
		case 45:	// QAScreenFactory::hosts
		case 46:	// StackEventQueue::clear
		case 47:	// StackEventQueue::pop
		case 48:	// StackEventQueue::quiet

		{
			m_groupNoParametersNeeded.ShowWindow( SW_SHOW  );
		}
		break;

	}

}



