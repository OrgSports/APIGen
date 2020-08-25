//INCLUDE FILES

#ifdef __cplusplus
	#include "afxwin.h"
#endif

// to allow exporting the DLL functions

#ifdef VOY32DLL
	#define VOYAPI __declspec(dllexport) 
#else
	#define VOYAPI __declspec(dllimport)  
#endif

//constants

//Global variables

// Function prototypes

//#include "windows.h"

#ifndef IHLLAPIINC
#define IHLLAPIINC

#pragma pack(1)       // Pack HLLAPI structures on 1-byte boundary
#pragma message("Information: HLLAPI structures are packed on 1-byte boundaries.")

/****** Function numbers ****************************************************/

#define IHLL_OEMFUNCTION                0  /* OEM Function */
#define IHLL_CONNECTPS                  1  /* Connect Presentation Space */
#define IHLL_DISCONNECTPS               2  /* Disconnect Presentation Space */
#define IHLL_SENDKEY                    3  /* Send Key */
#define IHLL_WAIT                       4  /* Wait */
#define IHLL_COPYPS                     5  /* Copy Presentation Space */
#define IHLL_SEARCHPS                   6  /* Search Presentation Space */
#define IHLL_QUERYCURSORLOC             7  /* Query Cursor Location */
#define IHLL_COPYPSTOSTR                8  /* Copy Presentation Space To String */
#define IHLL_SETSESSIONPARAMETERS       9  /* Set Session Parameters */
#define IHLL_QUERYSESSIONS             10  /* Query Sessions */
#define IHLL_RESERVE                   11  /* Reserve */
#define IHLL_RELEASE                   12  /* Release */
#define IHLL_COPYOIA                   13  /* Copy OIA Information */
#define IHLL_QUERYFIELDATTRIBUTE       14  /* Query Field Attribute */
#define IHLL_COPYSTRTOPS               15  /* Copy String To Presentation Space */
#define IHLL_STORAGEMGR                17  /* Storage Manager */
#define IHLL_PAUSE                     18  /* Pause */
#define IHLL_QUERYSYSTEM               20  /* Query System */
#define IHLL_RESETSYSTEM               21  /* Reset System */
#define IHLL_QUERYSESSIONSTATUS        22  /* Query Session Status */
#define IHLL_STARTHOSTNOTIFICATION     23  /* Start Host Notification */
#define IHLL_QUERYHOSTUPDATE           24  /* Query Host Update */
#define IHLL_STOPHOSTNOTIFICATION      25  /* Stop Host Notification */
#define IHLL_SEARCHFIELD               30  /* Search Field */
#define IHLL_FINDFIELDPOSITION         31  /* Find Field Position */
#define IHLL_FINDFIELDLENGTH           32  /* Find Field Length */
#define IHLL_COPYSTRINGTOFIELD         33  /* Copy String To Field */
#define IHLL_COPYFIELDTOSTRING         34  /* Copy String To Field */
#define IHLL_SETCURSOR                 40  /* Set Cursor */
#define IHLL_STARTCLOSEINTERCEPT       41  /* Start Close Intercept */
#define IHLL_QUERYCLOSEINTERCEPT       42  /* Query Close Intercept */
#define IHLL_STOPCLOSEINTERCEPT        43  /* Stop Close Intercept */
#define IHLL_STARTKSINTERCEPT          50  /* Start Keystroke Intercept */
#define IHLL_GETKEY                    51  /* Get Key */
#define IHLL_POSTINTERCEPTSTATUS       52  /* Post Intercept Status */
#define IHLL_STOPKSINTERCEPT           53  /* Stop  Keystroke Intercept */
#define IHLL_LOCKPSAPI                 60  /* Lock Presentation Space API */
#define IHLL_LOCKWSAPI                 61  /* Lock Window Services API */
#define IHLL_SENDFILE                  90  /* Send File */
#define IHLL_RECEIVEFILE               91  /* Receive File */
#define IHLL_CONVERT                   99  /* Convert Position or RowCol */
#define IHLL_CONNECTWINDOWSERVICES    101  /* Connect Window Services */
#define IHLL_DISCONNECTWINDOWSERVICES 102  /* Disconnect Window Services */
#define IHLL_QUERYWINDOWCOORDINATES   103  /* Query or Set Window Coordinates */
#define IHLL_WINDOWSTATUS             104  /* Query or Set Window Status */
#define IHLL_CHANGEPSNAME             105  /* Change Presentation Space Name */
#define IHLL_CONNECTSTRFLDS           120  /* Connect Structured Fields */
#define IHLL_DISCONSTRFLDS            121  /* Disconnect Structured Fields */
#define IHLL_QUERYCOMMBUFSIZ          122  /* Query Communications Buffer Size */
#define IHLL_ALLOCCOMMBUFF            123  /* Allocate Communications Buffer */
#define IHLL_FREECOMMBUFF             124  /* Free Communications Buffer */
#define IHLL_GETREQUESTCOMP           125  /* Get Request Completion */
#define IHLL_READSTRFLDS              126  /* Read Structured Fields */
#define IHLL_WRITESTRFLDS             127  /* Write Structured Fields */

#define	PROFILEASSOCIATE		  	  911
#define	PROFILEREMOVE			  	  912
#define	PROFILEGETASSOCIATIONS	  	  913
#define	PROFILEFINDFILENAME		  	  914
#define	PROFILEFINDSHORTNAME	  	  915

/****** SetSessionParameters values *****************************************/

#define WHLL_SSP_NEWRET      (DWORD)0x00000001
#define WHLL_SSP_OLDRET      (DWORD)0x00000002
#define WHLL_SSP_ATTRB       (DWORD)0x00000004
#define WHLL_SSP_NOATTRB     (DWORD)0x00000008
#define WHLL_SSP_NWAIT       (DWORD)0x00000010
#define WHLL_SSP_LWAIT       (DWORD)0x00000020
#define WHLL_SSP_TWAIT       (DWORD)0x00000040
#define WHLL_SSP_EAB         (DWORD)0x00000080
#define WHLL_SSP_NOEAB       (DWORD)0x00000100
#define WHLL_SSP_AUTORESET   (DWORD)0x00000200
#define WHLL_SSP_NORESET     (DWORD)0x00000400
#define WHLL_SSP_SRCHALL     (DWORD)0x00001000
#define WHLL_SSP_SRCHFROM    (DWORD)0x00002000
#define WHLL_SSP_SRCHFRWD    (DWORD)0x00004000
#define WHLL_SSP_SRCHBKWD    (DWORD)0x00008000
#define WHLL_SSP_FPAUSE      (DWORD)0x00010000
#define WHLL_SSP_IPAUSE      (DWORD)0x00020000

/****** Convert Row or Column values ****************************************/

#define WHLL_CONVERT_POSITION 'P'
#define WHLL_CONVERT_ROW      'R'

/******* Storage Manager Sub-Function values ********************************/

#define WHLL_GETSTORAGE        1
#define WHLL_FREESTORAGE       2
#define WHLL_FREEALLSTORAGE    3
#define WHLL_QUERYFREESTORAGE  4

/****** Change PS Name values ***********************************************/

#define WHLL_CHANGEPSNAME_SET			0x01
#define WHLL_CHANGEPSNAME_RESET			0x02

/****** Window Status values ************************************************/

#define WHLL_WINDOWSTATUS_SET				0x01
#define WHLL_WINDOWSTATUS_QUERY				0x02
#define WHLL_WINDOWSTATUS_EXTQUERY			0x03

#define WHLL_WINDOWSTATUS_NULL				0x0000
#define WHLL_WINDOWSTATUS_SIZE				0x0001
#define WHLL_WINDOWSTATUS_MOVE				0x0002
#define WHLL_WINDOWSTATUS_ZORDER			0x0004
#define WHLL_WINDOWSTATUS_SHOW				0x0008
#define WHLL_WINDOWSTATUS_HIDE				0x0010
#define WHLL_WINDOWSTATUS_ACTIVATE			0x0080
#define WHLL_WINDOWSTATUS_DEACTIVATE		0x0100
#define WHLL_WINDOWSTATUS_MINIMIZE			0x0400
#define WHLL_WINDOWSTATUS_MAXIMIZE			0x0800
#define WHLL_WINDOWSTATUS_RESTORE			0x1000

#define WHLL_WINDOWSTATUS_FRONT		(DWORD)0x00000003
#define WHLL_WINDOWSTATUS_BACK		(DWORD)0x00000004

/****** Lock API values *****************************************************/

#define WHLL_LOCKAPI_LOCK			'L'
#define WHLL_LOCKAPI_UNLOCK			'U'
#define WHLL_LOCKAPI_RETURN			'R'
#define WHLL_LOCKAPI_QUEUE			'Q'

 /****** Windows HLLAPI Return Codes *****************************************/

#define WHLLOK                   0   /* Successful */
#define WHLLNOTCONNECTED         1   /* Not Connected To Presentation Space */
#define WHLLBLOCKNOTAVAIL        1   /* Requested size is not available */
#define WHLLPARAMETERERROR       2   /* Parameter Error/Invalid Function */
#define WHLLBLOCKIDINVALID       2   /* Invalid Block ID was specified */
#define WHLLFTXCOMPLETE          3   /* File Transfer Complete */
#define WHLLFTXSEGMENTED         4   /* File Transfer Complete / segmented */
#define WHLLPSBUSY               4   /* Presentation Space is Busy */
#define WHLLINHIBITED            5   /* Inhibited/Keyboard Locked */
#define WHLLTRUNCATED            6   /* Data Truncated */
#define WHLLPOSITIONERROR        7   /* Invalid Presentation Space Position */
#define WHLLNOTAVAILABLE         8   /* Unavailable Operation */
#define WHLLSYSERROR             9   /* System Error */
#define WHLLNOTSUPPORTED         10  /* Function Not Supported */
#define WHLLUNAVAILABLE          11  /* Resource is unavailable */
#define WHLLPSENDED              12  /* The session was stopped */
#define WHLLUNDEFINEDKEY         20  /* Undefined Key Combination */
#define WHLLOIAUPDATE            21  /* OIA Updated */
#define WHLLPSUPDATE             22  /* PS Updated */
#define WHLLBOTHUPDATE           23  /* Both PS And OIA Updated */
#define WHLLNOFIELD              24  /* No Such Field Found */
#define WHLLNOKEYSTROKES         25  /* No Keystrokes are available */
#define WHLLPSCHANGED            26  /* PS or OIA changed */
#define WHLLFTXABORTED           27  /* File transfer aborted */
#define WHLLZEROLENFIELD         28  /* Field length is zero */
#define WHLLKEYOVERFLOW          31  /* Keystroke overflow */
#define WHLLSFACONN              32  /* Other application already connected */
#define WHLLTRANCANCLI           34  /* Message sent inbound to host cancelled */
#define WHLLTRANCANCL            35  /* Outbound trans from host cancelled */
#define WHLLHOSTCLOST            36  /* Contact with host was lost */
#define WHLLOKDISABLED           37  /* The function was successful */
#define WHLLNOTCOMPLETE          38  /* The requested fn was not completed */
#define WHLLSFDDM                39  /* One DDM session already connected */
#define WHLLSFDPEND              40  /* Disconnected w async requests pending */
#define WHLLBUFFINUSE            41  /* Specified buffer currently in use */
#define WHLLNOMATCH              42  /* No matching request found */
#define WHLLLOCKERROR            43  /* API already locked or unlocked */

#define WHLLINVALIDFUNCTIONNUM  301  /* Invalid function number */
#define WHLLFILENOTFOUND        302  /* File Not Found */
#define WHLLACCESSDENIED        305  /* Access Denied */
#define WHLLMEMORY              308  /* Insufficient Memory */
#define WHLLINVALIDENVIRONMENT  310  /* Invalid environment */
#define WHLLINVALIDFORMAT       311  /* Invalid format */

#define WHLLINVALIDPSID        9998  /* Invalid Presentation Space ID */
#define WHLLINVALIDRC          9999  /* Invalid Row or Column Code */

/****** Windows HLLAPI Extentions Return Codes ******************************/

#define WHLLALREADY         0xF000   /* An async call is already outstanding */
#define WHLLINVALID         0xF001   /* Async Task Id is invalid */
#define WHLLCANCEL          0xF002   /* Blocking call was cancelled */
#define WHLLSYSNOTREADY     0xF003   /* Underlying subsystem not started */
#define WHLLVERNOTSUPPORTED 0xF004   /* Application version not supported */

/****** Windows HLLAPI structure ********************************************/

#define WHLLDESCRIPTION_LEN	127

typedef struct tagIHLLAPIDATA {
	WORD	wVersion;
	char	szDescription[WHLLDESCRIPTION_LEN+1];
} IHLLAPIDATA, * PIHLLAPIDATA, FAR * LPIHLLAPIDATA;


#ifdef __cplusplus
	extern "C"
{
#endif

/****** Windows HLLAPI Function Prototypes **********************************/

extern void WINAPI WinHLLAPI(LPWORD, LPSTR, LPWORD, LPWORD);
extern HANDLE WINAPI WinHLLAPIAsync(HWND, LPWORD, LPSTR, LPWORD, LPWORD);
extern BOOL WINAPI WinHLLAPICleanup(void);
extern BOOL WINAPI WinHLLAPIIsBlocking(void);
extern int WINAPI WinHLLAPICancelAsyncRequest(HANDLE, WORD);
extern int WINAPI WinHLLAPICancelBlockingCall(void);
extern int WINAPI WinHLLAPIStartup(WORD, LPIHLLAPIDATA);
extern FARPROC WINAPI WinHLLAPISetBlockingHook(FARPROC);
extern BOOL WINAPI WinHLLAPIUnhookBlockingHook(void);
//donc010603 */

#ifdef __cplusplus
}
#endif

#pragma pack()      // Revert to previous packing

#endif
