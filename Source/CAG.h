// Static Model


#ifndef __CAG__
#define __CAG__




#include "SetupTranslate.h"

typedef enum
{
	AG_rcANYCOL=0,
	AG_rcANYROW,
	AG_AREA_OUTPUT,
	AG_AREA,
	AG_ATM_SYSTEM,
	AG_ATMFT,
	AG_ATTACHED,
	AG_ATTRIBUTE,
	AG_ATTRIBUTE_ARRAY,
	AG_ATTRIBUTE_NAME,
	AG_ATTRIBUTE_NAMES,
	AG_BOOL,
	AG_BSTR,
	AG_BUFFER_SIZE,
	AG_BUTTON1,
	AG_BUTTON2,
	AG_BUTTON3,
	AG_BUTTON4,
	AG_CASE_SENSITIVE,
	AG_CLOSEOPTION,
	AG_COLUMN,
	AG_COLUMN_END,
	AG_COMMAND,
	AG_CONNECTED,
	AG_CONNECTION_OBJ,
	AG_CONTEXT,
	AG_COUNT,
	AG_DATA_CAPTURE,
	AG_DATA_INPUT_VALUES,
	AG_DATA_REF,
	AG_DIRECTION,
	AG_DOMAIN,
	AG_DWRET,
	AG_EAB,
	AG_ENDCOLUMN,
	AG_ENDROW,
	AG_EVENT,
	AG_FEATURE_NAME,
	AG_FEATURE_ID,
	AG_FEATURE_INDEX,
	AG_FEATURE_STATE,
	AG_FIELD,
	AG_FIELD_NAMES,
	AG_FIELD_SPECIFIER,
	AG_FILL,
	AG_FILTER,
	AG_FILTER_LIST,
	AG_FLAG,
	AG_FLAGS,
	AG_FONTNAME,
	AG_FT_OBJ,
	AG_FT_SCHEME,
	AG_FUNCTION_NAME,
	AG_HANDLE_INSTALLER,
	AG_HANDLE,
	AG_HEIGHT,
	AG_HLL_PARAMS,
	AG_HOST_CHARSET,
	AG_HOST_CODEPAGE,
	AG_HOST_OS,
	AG_HOSTFILE_BSTR,
	AG_HOSTNAME,
	AG_HRESULT,
	AG_ID_COUNT,
	AG_ID_INCREMENT,
	AG_IDMGR_ADDRESS,
	AG_IDLE_TIME,
	AG_INDEX,
	AG_INSTALLSTATE,
	AG_IP_ADDRESS,
	AG_IRET,
	AG_ITASK_SOURCE,
	AG_KBD_LOCKED,
	AG_KEY,
	AG_KEYS,
	AG_KEYSTROKE,
	AG_LENGTH,
	AG_LOCALE,
	AG_LOCALMODE,
	AG_MAX_ROWS,
	AG_MAX_SIZE,
	AG_MENU_VISIBLE,
	AG_MESSAGE,
	AG_MODE,
	AG_MODEL,
	AG_MODEL_RECORD,
	AG_MODEL_VARIABLE,
	AG_MSI_HANDLE,
	AG_MUTABLE1,
	AG_MUTABLE2,
	AG_MUTABLE3,
	AG_MUTABLE4,
	AG_MUTABLE5,
	AG_N_RETURN,
	AG_NAME,
	AG_NETWORK_NAME,
	AG_NEW_PASSWORD,
	AG_NUMBER,
	AG_OIA,
	AG_OIAOBJ,
	AG_OPTIONS,
	AG_OUTATTRIBUTE,
	AG_OUTCOLUMN,
	AG_OUTLENGTH,
	AG_OUTPUT_COLNAMES,
	AG_OUTROW,
	AG_OUTTEXT,
	AG_PAGE,
	AG_PASSWORD,
	AG_PACKAGE_PATH,
	AG_SCRIPT_PATH,
	AG_PARENT_ID,
	AG_PATH,
	AG_PCFILE_BSTR,
	AG_PLATFORM,
	AG_POINT_POSITION,
	AG_PORT,
	AG_POSITION,
	AG_PROCEDURE,
	AG_PROCESS,
	AG_PROCESS_KEYSTROKES,
	AG_PRODUCT_NAME,
	AG_PRODUCT_PROPERTY,
	AG_PROPERTY,
	AG_RECORDMAP,
	AG_RECORDSET,
	AG_REMOTE_DIR,
	AG_RESOURCE_NAME,
	AG_RESPONSE,
	AG_RETURN,
	AG_RETURN_CODE,
	AG_RETURN_STRING,
	AG_ROW,
	AG_ROW_END,
	AG_ROWCOL_FLAG,
	AG_SCREEN_DATA,
	AG_SCREEN_HELD,
	AG_SCREEN_LISTENER,
	AG_SCREEN_OBJ,
	AG_SCREEN,
	AG_SCREEN_PLANE,
	AG_SCREEN_SIZE,
	AG_SZSCRIPTFILE,
	AG_SEARCHING,
	AG_SEQUENCE_ID,
	AG_SERVER,
	AG_SESS_OPEN,
	AG_SESS_QUIET,
	AG_SESS_SAVED,
	AG_SESS_STATUS,
	AG_SESSION,
	AG_SESSIONS,
	AG_SESSIONS_CREATED,
	AG_SETTINGS_DIALOG,
	AG_SETTINGS_PAGE,
	AG_SETTINGS_TAB,
	AG_SETTLE_TIME,
	AG_SQL,
	AG_STATE,
	AG_STATUS,
	AG_STATUS_EVENT,
	AG_STRING,
	AG_STRING_LENGTH,
	AG_SZ_STRING,
	AG_SZ_VALUE,
	AG_TABLE,
	AG_TASK_ID,
	AG_TASK_LISTENER,
	AG_TERMINAL,
	AG_TERMINAL_FACILITY_LIKE,
	AG_TERMINAL_POOL,
	AG_TEXT,
	AG_TEXT_DISPLAY,
	AG_TIMEOUT,
	AG_TRANSFORMS,
	AG_TYPE,
	AG_UINT_RETURN,
	AG_UPDATED,
	AG_UPG_SCREEN,
	AG_USER_ID,
	AG_UTILBUFFER,
	AG_VALUE,
	AG_VERSION,
	AG_WAIT,
	AG_WAIT_ID,
	AG_WAIT_OPTION,
	AG_WEBVIEW_NAME,
	AG_WHLLAPIDATA,
	AG_WIDTH,
	AG_WINDOW_HANDLE,
	AG_WINDOW_STATE,
	AG_WRAP,
	AG_XML_DATA

} AG_VARIABLE;



class CAG
{

	public:

		// Test comment for APIFlavor
		APIOption APIFlavor;


		virtual ~CAG();

		virtual void loadFunctionList(CListBox* listTranslateFunction) = 0;

		virtual void loadLanguageList(CListBox* listTranslateLanguage) = 0;
		
		virtual void loadTerminalTypeList(CListBox* listTerminalTypes) = 0;

		virtual void generateHeader(CStringArray* pcsaHeader,
								CStringArray* pcsaBody) = 0;

		virtual void appendBody(int nFunctionNum,
							bool bPromptForValues,
							CStringArray* pcsaArguments,
							CStringArray* pcsaHeader,
							CStringArray* pcsaBody) = 0;

		virtual void finalize(CStringArray* pcsaBody) = 0;

		virtual void checkDebug();

		virtual void resetVariableFlags();


	protected:

		unsigned short usGlobalPSMallocSize;

		CStringArray csaFunctions;


		CAG();

		virtual void declareVariable(AG_VARIABLE agVariable,
								CStringArray* pcsaHeader,
								bool* bValue);





};
// END CLASS DEFINITION CAG

#endif // __CAG__