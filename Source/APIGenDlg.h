// APIGenDlg.h : header file
//
#if !defined(AFX_APIGENDLG_H__155B49D9_09DB_4D6E_8512_EC07927C48B1__INCLUDED_)
#define AFX_APIGENDLG_H__155B49D9_09DB_4D6E_8512_EC07927C48B1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


#include <fstream>
using namespace std;

#include "SetupTranslate.h"
#include "apigenstate.h"
#include <afxtempl.h>

#include "cag.h"

#include "cag_air.h"
#include "cag_air_3270_J.h"
#include "cag_air_3270_J_J.h"
#include "cag_air_3270_Ax_CPP.h"

#include "cag_air_5250_J_J.h"
#include "cag_air_5250_Ax_cpp.h"

#include "cag_air_VT_J_J.h"
#include "cag_air_VT_Ax_cpp.h"

#include "cag_air_apollo_J.h"
#include "cag_air_apollo_Ax.h"

#include "cag_air_eds_J.h"
#include "cag_air_eds_Ax.h"

#include "cag_air_lantern_J.h"
#include "cag_air_lantern_Ax.h"

#include "cag_air_matip_J.h"
#include "cag_air_matip_Ax.h"

#include "cag_air_mcs_J.h"
#include "cag_air_mcs_Ax.h"

#include "cag_air_sabre_J.h"
#include "cag_air_sabre_Ax.h"

#include "cag_air_t27_J.h"
#include "cag_air_t27_Ax.h"

#include "cag_air_int1_J.h"
#include "cag_air_int1_Ax.h"

#include "cag_air_mcs_J.h"
#include "cag_air_mcs_Ax.h"

#include "cag_air_pepgate_J.h"
#include "cag_air_pepgate_Ax.h"

#include "cag_air_uts_matip_J.h"
#include "cag_air_uts_matip_Ax.h"

#include "cag_air_vm_3270_J.h"
#include "cag_air_vm_3270_vbs.h"
#include "cag_air_vm_t27_J.h"
#include "cag_air_vm_t27_vbs.h"
#include "cag_air_vm_uts_J.h"
#include "cag_air_vm_uts_vbs.h"

#include "cag_casl.h"

#include "cag_cics_qacom_com.h"
#include "cag_cics_qacom_com_asp.h"
#include "cag_cics_qacom_com_cpp.h"
#include "cag_cics_qacom_com_vb6.h"
#include "cag_cics_qacom_java.h"
#include "cag_cics11_qacom_java_j.h"
#include "cag_cics20_qacom_java_j.h"
#include "cag_cics_qacom_net.h"
#include "cag_cics_qacom_net_vbn.h"
#include "cag_cics_qacom_net_cs.h"

#include "cag_dos.h"

#include "cag_eal.h"
#include "cag_eal_cpp.h"
#include "cag_eal_cs.h"
#include "cag_eal_vb6.h"
#include "cag_eal_vbn.h"

#include "cag_eaoax.h"
#include "cag_eaoax_3270_cpp.h"
#include "cag_eaoax_3270_cs.h"
#include "cag_eaoax_3270_vb6.h"
#include "cag_eaoax_3270_vbn.h"
#include "cag_eaoax_3270_html_js.h"
#include "cag_eaoax_3270_html_vbs.h"

#include "cag_eaoax_5250_cpp.h"
#include "cag_eaoax_5250_cs.h"
#include "cag_eaoax_5250_vb6.h"
#include "cag_eaoax_5250_vbn.h"
#include "cag_eaoax_5250_html_js.h"
#include "cag_eaoax_5250_html_vbs.h"

#include "cag_eaoax_VT_cpp.h"
#include "cag_eaoax_VT_cs.h"
#include "cag_eaoax_VT_vb6.h"
#include "cag_eaoax_VT_vbn.h"
#include "cag_eaoax_vt_html_js.h"
#include "cag_eaoax_vt_html_vbs.h"


#include "cag_eaoj.h"
#include "cag_eaoj_3270_j.h"
#include "cag_eaoj_5250_j.h"
#include "cag_eaoj_VT_j.h"


#include "cag_ehl.h"
#include "cag_ehl_cpp.h"
#include "cag_ehl_cs.h"
#include "cag_ehl_vb6.h"
#include "cag_ehl_vbn.h"
#include "cag_ehl_xls.h"

#include "cag_eole.h"
#include "cag_eole_3270_cpp.h"
#include "cag_eole_3270_cs.h"
#include "cag_eole_3270_ebm.h"
#include "cag_eole_3270_ebm_test.h"
#include "cag_eole_3270_node_js.h"
#include "cag_eole_3270_node_vbs.h"
#include "cag_eole_3270_vb6.h"
#include "cag_eole_3270_vbn.h"
#include "cag_eole_3270_ws.h"
#include "cag_eole_3270_xls.h"
#include "cag_eole_3270_asp.h"

#include "cag_eole_5250_cpp.h"
#include "cag_eole_5250_cs.h"
#include "cag_eole_5250_ebm.h"
#include "cag_eole_5250_ebm_test.h"
#include "cag_eole_5250_node_vbs.h"
#include "cag_eole_5250_vb6.h"
#include "cag_eole_5250_vbn.h"
#include "cag_eole_5250_ws.h"
#include "cag_eole_5250_xls.h"
#include "cag_eole_5250_asp.h"

#include "cag_eole_VT_cpp.h"
#include "cag_eole_VT_cs.h"
#include "cag_eole_VT_ebm.h"
#include "cag_eole_VT_ebm_test.h"
#include "cag_eole_VT_node_vbs.h"
#include "cag_eole_VT_vb6.h"
#include "cag_eole_VT_vbn.h"
#include "cag_eole_VT_ws.h"
#include "cag_eole_VT_xls.h"
#include "cag_eole_VT_asp.h"


#include "cag_hll.h"
#include "cag_hll_cpp.h"
#include "cag_hll_cs.h"


#include "cag_iconn_cs.h"
#include "cag_iconn_java.h"
#include "cag_iconn_vbn.h"
#include "cag_iconn_ws.h"
#include "cag_iconn_asp.h"

#include "cag_ihl.h"
#include "cag_ihl_cpp.h"
#include "cag_ihl_cs.h"
#include "cag_ihl_vb6.h"
#include "cag_ihl_vbn.h"

#include "cag_itask_java.h"

#include "cag_mcs_ax.h"
#include "cag_mcs_ax_3270_js_crl.h"
#include "cag_mcs_ax_3270_js_deploy.h"
#include "cag_mcs_ax_3270_js_hdr.h"
#include "cag_mcs_ax_3270_js_html.h"

#include "cag_mcs_ax_3270_vbs_crl.h"
#include "cag_mcs_ax_3270_vbs_deploy.h"
#include "cag_mcs_ax_3270_vbs_hdr.h"
#include "cag_mcs_ax_3270_vbs_html.h"

#include "cag_mcs_ax_5250_js_crl.h"
#include "cag_mcs_ax_5250_js_deploy.h"
#include "cag_mcs_ax_5250_js_hdr.h"
#include "cag_mcs_ax_5250_js_html.h"

#include "cag_mcs_ax_5250_vbs_crl.h"
#include "cag_mcs_ax_5250_vbs_deploy.h"
#include "cag_mcs_ax_5250_vbs_hdr.h"
#include "cag_mcs_ax_5250_vbs_html.h"

#include "cag_mcs_ax_vt_js_crl.h"
#include "cag_mcs_ax_vt_js_deploy.h"
#include "cag_mcs_ax_vt_js_hdr.h"
#include "cag_mcs_ax_vt_js_html.h"

#include "cag_mcs_ax_vt_vbs_crl.h"
#include "cag_mcs_ax_vt_vbs_deploy.h"
#include "cag_mcs_ax_vt_vbs_hdr.h"
#include "cag_mcs_ax_vt_vbs_html.h"

#include "cag_mcs_j_3270_js_crl.h"
#include "cag_mcs_j_3270_js_hdr.h"
#include "cag_mcs_j_3270_js_html.h"
#include "cag_mcs_j_3270_js_deploy.h"
#include "cag_mcs_j_3270_vbs_crl.h"
#include "cag_mcs_j_3270_vbs_hdr.h"
#include "cag_mcs_j_3270_vbs_html.h"
#include "cag_mcs_j_3270_vbs_deploy.h"

#include "cag_mcs_j_5250_js_crl.h"
#include "cag_mcs_j_5250_js_hdr.h"
#include "cag_mcs_j_5250_js_html.h"
#include "cag_mcs_j_5250_js_deploy.h"
#include "cag_mcs_j_5250_vbs_crl.h"
#include "cag_mcs_j_5250_vbs_hdr.h"
#include "cag_mcs_j_5250_vbs_html.h"
#include "cag_mcs_j_5250_vbs_deploy.h"

#include "cag_mcs_j_vt_js_crl.h"
#include "cag_mcs_j_vt_js_hdr.h"
#include "cag_mcs_j_vt_js_html.h"
#include "cag_mcs_j_vt_js_deploy.h"
#include "cag_mcs_j_vt_vbs_crl.h"
#include "cag_mcs_j_vt_vbs_hdr.h"
#include "cag_mcs_j_vt_vbs_html.h"
#include "cag_mcs_j_vt_vbs_deploy.h"

#include "cag_msi_app_cpp.h"
#include "cag_msi_app_vbs.h"
#include "cag_msi_app_ws.h"
#include "cag_msi_custom_cpp.h"
#include "cag_msi_custom_vbs.h"
#include "cag_msi_custom_ws.h"
#include "cag_msi_dbase_cpp.h"
#include "cag_msi_dbase_vbs.h"
#include "cag_msi_dbase_ws.h"
#include "cag_msi_msiexec.h"
#include "cag_msi_summary_info.h"
#include "cag_msi_wix_dlg.h"
#include "cag_msi_wix_wiz.h"


#include "cag_pb_qac.h"
#include "cag_pb_qac_j.h"
#include "cag_pb_qac_js.h"
#include "cag_pb_qac_vbs.h"


#include "cag_pcs.h"
#include "cag_pcs_cpp.h"
#include "cag_pcs_cs.h"
#include "cag_pcs_vb6.h"
#include "cag_pcs_vbn.h"
#include "cag_pcs_xls.h"

#include "cag_perforce.h"

#include "cag_rftp.h"
#include "cag_rftp_cpp.h"
#include "cag_rftp_cs.h"
#include "cag_rftp_vb6.h"
#include "cag_rftp_vbn.h"

#include "cag_role.h"
#include "cag_role_3270_cpp.h"
#include "cag_role_3270_cs.h"
#include "cag_role_3270_vb6.h"
#include "cag_role_3270_vbn.h"
#include "cag_role_3270_vba.h"
#include "cag_role_3270_ws.h"
#include "cag_role_3270_xls.h"
#include "cag_role_3270_asp.h"

#include "cag_role_5250_cpp.h"
#include "cag_role_5250_cs.h"
#include "cag_role_5250_vb6.h"
#include "cag_role_5250_vbn.h"
#include "cag_role_5250_vba.h"
#include "cag_role_5250_ws.h"
#include "cag_role_5250_xls.h"
#include "cag_role_5250_asp.h"

#include "cag_role_vt_cpp.h"
#include "cag_role_vt_cs.h"
#include "cag_role_vt_vb6.h"
#include "cag_role_vt_vbn.h"
#include "cag_role_vt_vba.h"
#include "cag_role_vt_ws.h"
#include "cag_role_vt_xls.h"
#include "cag_role_vt_asp.h"

#include "cag_role_hp_cpp.h"
#include "cag_role_hp_cs.h"
#include "cag_role_hp_vb6.h"
#include "cag_role_hp_vbn.h"
#include "cag_role_hp_vba.h"
#include "cag_role_hp_ws.h"
#include "cag_role_hp_xls.h"
#include "cag_role_hp_asp.h"

#include "cag_rweb.h"
#include "cag_rweb_3270_java.h"
#include "cag_rweb_3270_js.h"
#include "cag_rweb_3270_vbs.h"
#include "cag_rweb_5250_java.h"
#include "cag_rweb_5250_js.h"
#include "cag_rweb_5250_vbs.h"
#include "cag_rweb_hp_java.h"
#include "cag_rweb_hp_js.h"
#include "cag_rweb_hp_vbs.h"
#include "cag_rweb_vt_java.h"
#include "cag_rweb_vt_js.h"
#include "cag_rweb_vt_vbs.h"

#include "cag_unix.h"


#include "cag_vhi_vb6.h"
#include "cag_vhi_cs.h"
#include "cag_vhi_vbn.h"
#include "cag_vhi_ws.h"

#include "cag_whl.h"
#include "cag_whl_cpp.h"
#include "cag_whl_cs.h"
#include "cag_whl_vb6.h"
#include "cag_whl_vbn.h"

#define PARAM_TOP 50
#define PARAM_LABEL_HEIGHT 11
#define PARAM_LINE_HEIGHT 46
#define	PARAM_LEFT_SIDE 630

#include "afxwin.h"


/////////////////////////////////////////////////////////////////////////////
// CAPIGenDlg dialog

class CAPIGenDlg : public CDialog
{
private:
	const static int CONTROL_TO_TEXT_JUMP=7;
	const static int STATIC_TO_CONTROL_JUMP=16;
	const static int STATIC_TO_STATIC_JUMP=44;
	const static int ROW_COL_WIDTH=45;
	const static int STANDARD_WIDTH=145;
	const static int LISTBOX_HEIGHT=60;

// Construction
public:
	CAPIGenDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CAPIGenDlg)
	enum { IDD = IDD_APIGEN_DIALOG };
	CStatic		m_staticTelnetAddress;
	CStatic		m_staticTelnetPort;
	CStatic		m_staticSocksAddress;
	CStatic		m_staticSocksPort;
	CButton		m_checkSetTimeoutValue;
	CStatic		m_staticSessionFileName;
	CEdit		m_editSessionFilename;
	CButton		m_buttonSessionFilename;
	CButton		m_checkSetWindowState;
	CStatic		m_staticWindowState;
	CListBox	m_listWindowState;
	CEdit		m_editHeight;
	CEdit		m_editWidth;
	CButton		m_checkSetHeight;
	CButton		m_checkSetWidth;
	CStatic		m_staticNewWidth;
	CStatic		m_staticNewHeight;
	CButton		m_checkContinuousWait;
	CButton		m_checkSetVisible;
	CStatic		m_staticPC_Filename;
	CStatic		m_staticHostFileName;
	CEdit		m_editPC_Filename;
	CEdit		m_editHostFileName;
	CButton		m_checkShowFTProgress;
	CButton		m_buttonBrowseFileTransfer;
	CButton		m_checkSetSessionQuiet;
	CButton		m_checkSetMenuVisible;
	CButton		m_checkLocalMode;
	CButton		m_checkLanguage;
	CStatic		m_staticLanguage;
	CStatic		m_staticIdleTime;
	CListBox	m_listScreenModel;
	CStatic		m_staticScreenModel;
	CStatic		m_staticHostCodePage;
	CStatic		m_staticHostCharSet;
	CStatic		m_staticMnemonicType;
	CListBox	m_listMnemonicType;
	CListBox	m_listFieldType;
	CStatic		m_staticFieldType;
	CStatic		m_staticKeyboardMap;
	CEdit		m_EditKeyboardMapName;
	CButton		m_checkKeyboardMap;
	CButton		m_ButtonBrowseKeyMap;
	CButton		m_radioLockKeyboard;
	CButton		m_checkLockKeyboard;
	CButton		m_buttonBrowseFileTransferScheme;
	CEdit		m_EditFileTransferScheme;
	CButton		m_checkSetFileTransferScheme;
	CStatic		m_staticFileTransferScheme;
	CStatic		m_staticCloseOption;
	CEdit		m_editCloseOption;
	CStatic		m_staticSettleTime;
	CEdit		m_EditSettleTime;
	CStatic		m_staticTimeout;
	CStatic		m_staticUserKeys;
	CEdit		m_editUserKeys;
	CEdit		m_editTimeout;
	CButton		m_checkContinueToProcess;
	CStatic		m_staticRowsMoved;
	CStatic		m_staticColumnsMoved;
	CStatic		m_staticPutString;
	CEdit		m_EditPutString;
	CButton		m_groupAddParameterGroup;
	CButton		m_groupNoParametersNeeded;
	CStatic		m_staticLength;
	CEdit		m_EditLength;
	CEdit		m_EditRow;
	CEdit		m_EditColumn;
	CStatic		m_staticColumn;
	CStatic		m_staticRow;
	CEdit		m_EditReturnCode;
	CEdit		m_EditStringLength;
	CStatic		m_staticString2;
	CStatic		m_staticString1;
	CStatic		m_staticString3;
	CEdit		m_EditFunctionString;
	CButton		m_ButtonSaveToFile;
	CButton		m_ButtonNewProject;
	CButton		m_buttonFinalizeListing;
	CButton		m_buttonPromptForValues;
	CListBox	m_listOutputText;
	CButton		m_ButtonGenerateSource;
	CButton		m_ButtonAppendSource;
	CEdit		m_editOutputText;
	CListBox	m_listTranslateFunction;
	CListBox	m_listTranslateLanguage;
	CListBox	m_listTranslateAPI;
	CListBox	m_listTerminalType;
	BOOL		m_bPromptForValues;
	CString		m_csInputString;
	CString		m_csInputStringLength;
	CString		m_csInputReturnCode;
	CString		m_csEditRow;
	CString		m_csEditColumn;
	CString		m_csEditLength;
	CString		m_csEditPutString;
	CString		m_csEditTimeout;
	BOOL		m_bCheckContinueProcess;
	CString		m_csEditUserKeys;
	CString		m_csEditSettleTime;
	CString		m_csEditCloseOption;
	BOOL		m_bSetFileTransferScheme;
	CString		m_csEditFileTransferScheme;
	BOOL		m_bLockKeyboard;
	int			m_nLockKeyboard;
	BOOL		m_bCheckKeyboardMap;
	CString		m_csKeyboardMapName;
	BOOL		m_bCheckLanguage;
	BOOL		m_bCheckLocalMode;
	BOOL		m_bCheckSetMenuVisible;
	BOOL		m_bCheckSetSessionQuiet;
	BOOL		m_bCheckShowFTPRogress;
	CString		m_csEditHostFileName;
	CString		m_csEditPC_Filename;
	BOOL		m_bCheckSetVisible;
	BOOL		m_bCheckContinuousWait;
	BOOL		m_bCheckSetWidth;
	BOOL		m_bCheckSetHeight;
	CString		m_csEditWidth;
	CString		m_csEditHeight;
	CString		m_csListWindowState;
	BOOL		m_bCheckSetWindowState;
	CString		m_csEditSessionFilename;
	BOOL		m_bCheckSetTimeoutValue;
	BOOL		m_bCheckFileInsert;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAPIGenDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CAPIGenDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnAppendSource();
	afx_msg void OnGenerateSource();
	virtual void OnOK();
	afx_msg void OnChangeAPIChoice();
	afx_msg void OnFinalize();
	afx_msg void OnPromptForValues();
	afx_msg void OnNewProject();
	afx_msg void OnChangeString();
	afx_msg void OnSaveToFile();
	afx_msg void OnChangeFunctionChoice();
	afx_msg void OnFtSchemeName();
	afx_msg void OnCheckFTSchemeCheckBox();
	afx_msg void OnBrowseKeymap();
	afx_msg void OnKeyboardMap();
	afx_msg void OnCheckLanguage();
	afx_msg void OnBrowseFileTransFilename();
	afx_msg void OnSetHeight();
	afx_msg void OnSetWidth();
	afx_msg void OnSetWindowState();
	afx_msg void OnSessionFileName();
	afx_msg void OnSettimeout();
	afx_msg void OnFileInsert();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

private:
	CString		csScriptFileName;
	int			m_nViewIndex;

	void	SetWindowSizeLoc();
	
	void	SetAPIList();
	void	LoadArgumentArray( int* nFunctionPosition );

	//int		EstablishProgrammingLanguage();
	BOOL	ReadyTargetOutFile( CStringArray* pcsaHeader, CStringArray* pcsaCaboose );
	void	AddCabooseToBody( CStringArray* pcsaHeader, CStringArray* pcsaCaboose );
	void	WriteToView( BOOL bFileInsert );

	static int	nAPI_Index;
	static int	nTerminalType_Index;

    static int	WidthBig;
    static int	WidthSmall;
    static int	HeightBig;
    static int	HeightSmall;
	static int	HeightVariable;
	static int	WidthVariable;
	
	void	PlaceWindow( LONG Width, LONG Height );

	void	ReadyState( BOOL bEnablePrompt );
	void	ReadyForParamsState();
	void	GeneratingState();
	
	void	HideParameterControls();

	void	ReadMixedControls( APIOption API, UINT uFunction, CStringArray* csaLabels );
	void	ReadHLLArgs( CStringArray* csaArguments );
	void	Read1L( CStringArray* csaArguments );
	void	Read1C1L1C1E( CStringArray* csaArguments );
	void	Read1L1ML2E( CStringArray* csaArguments );
	void	Read1E( CStringArray* csaArguments );
	void	Read1E1L( CStringArray* csaArguments );
	void	Read1E1L1E( CStringArray* csaArguments );
	void	Read1E1L2E( CStringArray* csaArguments );
	void	Read1E1L1C( CStringArray* csaArguments );
	void	Read1E1L4E1L( CStringArray* csaArguments );
	void	Read1E1L3E1L( CStringArray* csaArguments );
	void	Read1E1C( CStringArray* csaArguments );
	void	Read1E1C1E( CStringArray* csaArguments );
	void	Read1E1ML1E1C( CStringArray* csaArguments );
	void	Read1E2L( CStringArray* csaArguments );
	void	Read1E2L1C( CStringArray* csaArguments );
	void	Read1E2L1E2L3E1L1E( CStringArray* csaArguments  );
	void	Read1C( CStringArray* csaArguments );
	void	Read1C1E( CStringArray* csaArguments );
	void	Read1C2E( CStringArray* csaArguments );
	void	Read1C1L( CStringArray* csaArguments );
	void	Read1L1E( CStringArray* csaArguments );
	void	Read1L2E( CStringArray* csaArguments );
	void	Read1ML( CStringArray* csaArguments );
	void	Read1ML2E( CStringArray* csaArguments );
	void	Read1ML3E( CStringArray* csaArguments );
	void	Read1ML4E( CStringArray* csaArguments );
	void	Read2ML1L1ML1E( CStringArray* csaArguments );
	void	Read1L3E( CStringArray* csaArguments );
	void	Read1L5E1L( CStringArray* csaArguments );
	void	Read1L5E1C( CStringArray* csaArguments );
	void	Read2E( CStringArray* csaArguments );
	void	Read2E1C( CStringArray* csaArguments );
	void	Read2E1C1E( CStringArray* csaArguments );
	void	Read2E1C1E1C2E( CStringArray* csaArguments );
	void	Read2E2C( CStringArray* csaArguments );
	void	Read2E3C( CStringArray* csaArguments );
	void	Read2E4C1E( CStringArray* csaArguments );
	void	Read1C1E1L1ML1C1E( CStringArray* csaArguments );
	void	Read2E1L( CStringArray* csaArguments );
	void	Read2E1L5E( CStringArray* csaArguments );
	void	Read2E1L2E( CStringArray* csaArguments );
	void	Read2E1L3E( CStringArray* csaArguments );
	void	Read2E1L4E( CStringArray* csaArguments );
	void	Read2E2L( CStringArray* csaArguments  );
	void	Read2E2L1C( CStringArray* csaArguments  );
	void	Read2E2L3E( CStringArray* csaArguments );
	void	Read2E1L1C( CStringArray* csaArguments );
	void	Read2E2C1E1L( CStringArray* csaArguments );
	void	Read2E2C1E2L1E( CStringArray* csaArguments );
	void	Read2L( CStringArray* csaArguments );
	void	Read2C( CStringArray* csaArguments );
	void	Read3E( CStringArray* csaArguments );
	void	Read3E1L( CStringArray* csaArguments );
	void	Read3E1ML( CStringArray* csaArguments );
	void	Read3E1C( CStringArray* csaArguments );
	void	Read3C( CStringArray* csaArguments );
	void	Read3L( CStringArray* csaArguments );
	void	Read3L2E( CStringArray* csaArguments );
	void	Read4E( CStringArray* csaArguments  );
	void	Read4E1L( CStringArray* csaArguments  );
	void	Read4E1ML( CStringArray* csaArguments  );
	void	Read4E1C( CStringArray* csaArguments  );
	void	Read4E1C2E( CStringArray* csaArguments  );
	void	Read4E1C1L( CStringArray* csaArguments  );
	void	Read4E1C1ML( CStringArray* csaArguments  );
	void	Read4E2C( CStringArray* csaArguments  );
	void	Read5E( CStringArray* csaArguments  );
	void	Read5E1L( CStringArray* csaArguments  );
	void	Read5E1ML1L2E( CStringArray* csaArguments  );
	void	Read5E1C( CStringArray* csaArguments  );
	void	Read5E1C1L( CStringArray* csaArguments  );
	void	Read5E1C1L1C( CStringArray* csaArguments  );
	void	Read6E( CStringArray* csaArguments  );
	void	Read6E2L2C( CStringArray* csaArguments  );
	void	Read8E( CStringArray* csaArguments  );
	void	Read9E( CStringArray* csaArguments  );
	void	Read10E( CStringArray* csaArguments  );
	
	void	ShowMixedControls( APIOption API, UINT uFunction, CStringArray* csaLabels );
	void	Show1E( CStringArray* csaLabels );
	void	Show1E1B( CStringArray* csaLabels );
	void	Show1E1B1E( CStringArray* csaLabels );
	void	Show1E1B1C( CStringArray* csaLabels );
	void	Show1E1B1E1C( CStringArray* csaLabels );
	void	Show1E1L( CStringArray* csaLabels, CStringArray* csaListEntries  );
	void	Show1E1ML( CStringArray* csaLabels, CStringArray* csaListEntries  );
	void	Show1E1ML1E1C( CStringArray* csaLabels, CStringArray* csaListEntries  );
	void	Show1E1L1E( CStringArray* csaLabels, CStringArray* csaListEntries  );
	void	Show1E1L2E( CStringArray* csaLabels, CStringArray* csaListEntries  );
	void	Show1E1L1C( CStringArray* csaLabels, CStringArray* csaListEntries  );
	void	Show1E1L3E1L( CStringArray* csaLabels, CStringArray* csaListEntries, CStringArray* csaList2Entries );
	void	Show1E1L4E1L( CStringArray* csaLabels, CStringArray* csaListEntries, CStringArray* csaList2Entries );
	void	Show1E1C( CStringArray* csaLabels );
	void	Show1E1C1E( CStringArray* csaLabels );
	void	Show1E2L( CStringArray* csaLabels, CStringArray* csaListEntries, CStringArray* csaList2Entries );
	void	Show1E2L1C( CStringArray* csaLabels, CStringArray* csaListEntries, CStringArray* csaList2Entries );
	void	Show1E2L1E2L3E1L1E( CStringArray* csaLabels, CStringArray* csaListEntries, CStringArray* csaList2Entries, CStringArray* csaList3Entries, CStringArray* csaList4Entries, CStringArray* csaList5Entries );
	void	Show1L( CStringArray* csaLabels, CStringArray* csaListEntries  );
	void	Show1C1L1C1E( CStringArray* csaLabels, CStringArray* csaListEntries  );
	void	Show1C( CStringArray* csaLabels );
	void	Show1C1E1B( CStringArray* csaLabels );
	void	Show1C2E( CStringArray* csaLabels );
	void	Show1C2EB( CStringArray* csaLabels );
	void	Show1C1E( CStringArray* csaLabels );
	void	Show1L1E( CStringArray* csaLabels, CStringArray* csaListEntries  );
	void	Show1L1EB1E( CStringArray* csaLabels, CStringArray* csaListEntries  );
	void	Show1L2E( CStringArray* csaLabels, CStringArray* csaListEntries  );
	void	Show1ML( CStringArray* csaLabels, CStringArray* csaListEntries  );
	void	Show1ML2E( CStringArray* csaLabels, CStringArray* csaListEntries  );
	void	Show1ML3E( CStringArray* csaLabels, CStringArray* csaListEntries  );
	void	Show1ML4E( CStringArray* csaLabels, CStringArray* csaListEntries  );
	void	Show1L1ML2E( CStringArray* csaLabels, CStringArray* csaListEntries, CStringArray* csaListEntries2  );
	void	Show2ML1L1ML1E( CStringArray* csaLabels, CStringArray* csaListEntries, CStringArray* csaListEntries2, CStringArray* csaListEntries3, CStringArray* csaListEntries4  );
	void	Show1L3E( CStringArray* csaLabels, CStringArray* csaListEntries  );
	void	Show1L5E1L( CStringArray* csaLabels, CStringArray* csaListEntries, CStringArray* csaList2Entries );
	void	Show1L5E1C( CStringArray* csaLabels, CStringArray* csaListEntries );
	void	Show1C1L( CStringArray* csaLabels, CStringArray* csaListEntries  );
	void	Show2E( CStringArray* csaLabels );
	void	Show1EB1E( CStringArray* csaLabels );
	void	Show2E1ML( CStringArray* csaLabels, CStringArray* csaListEntries  );
	void	Show2E1C( CStringArray* csaLabels );
	void	Show2E1C1E( CStringArray* csaLabels );
	void	Show2E2C1E1L( CStringArray* csaLabels, CStringArray* csaListEntries  );
	void	Show2E2C1E2L1E( CStringArray* csaLabels, CStringArray* csaListEntries, CStringArray* csaList2Entries );
	void	Show2E1C1E1C2E( CStringArray* csaLabels );
	void	Show2E2C( CStringArray* csaLabels );
	void	Show2E3C( CStringArray* csaLabels );
	void	Show2E4C1E( CStringArray* csaLabels );
	void	Show2E1L1ML2E( CStringArray* csaLabels, CStringArray* csaListEntries, CStringArray* csaList2Entries );
	void	Show1C1E1L1ML1C1E( CStringArray* csaLabels, CStringArray* csaListEntries, CStringArray* csaList2Entries );
	void	Show2E1L( CStringArray* csaLabels, CStringArray* csaListEntries  );
	void	Show2E1L1E( CStringArray* csaLabels, CStringArray* csaListEntries  );
	void	Show2E1L2E( CStringArray* csaLabels, CStringArray* csaListEntries  );
	void	Show2E1L3E( CStringArray* csaLabels, CStringArray* csaListEntries  );
	void	Show2E1L4E( CStringArray* csaLabels, CStringArray* csaListEntries  );
	void	Show2E1L5E( CStringArray* csaLabels, CStringArray* csaListEntries  );
	void	Show2E2L( CStringArray* csaLabels, CStringArray* csaListEntries, CStringArray* csaList2Entries );
	void	Show2E2L1C( CStringArray* csaLabels, CStringArray* csaListEntries, CStringArray* csaList2Entries );
	void	Show2E2L3E( CStringArray* csaLabels, CStringArray* csaListEntries, CStringArray* csaList2Entries );
	void	Show2E1L1C( CStringArray* csaLabels, CStringArray* csaListEntries  );
	void	Show2L( CStringArray* csaLabels, CStringArray* csaListEntries, CStringArray* csaList2Entries );
	void	Show2C( CStringArray* csaLabels );
	void	Show3C( CStringArray* csaLabels );
	void	Show3E( CStringArray* csaLabels );
	void	Show3EB( CStringArray* csaLabels );
	void	Show3E1L( CStringArray* csaLabels, CStringArray* csaListEntries  );
	void	Show3E1ML( CStringArray* csaLabels, CStringArray* csaListEntries  );
	void	Show3E1C( CStringArray* csaLabels );
	void	Show3L( CStringArray* pcsaLabels, CStringArray* csaListEntries, CStringArray* csaList2Entries, CStringArray* csaList3Entries );
	void	Show3L2E( CStringArray* pcsaLabels, CStringArray* csaListEntries, CStringArray* csaList2Entries, CStringArray* csaList3Entries );
	void	Show4E( CStringArray* csaLabels );
	void	Show4E1L( CStringArray* csaLabels, CStringArray* csaListEntries  );
	void	Show4E1ML( CStringArray* csaLabels, CStringArray* csaListEntries  );
	void	Show4E1L2E( CStringArray* csaLabels, CStringArray* csaListEntries  );
	void	Show4E1C( CStringArray* csaLabels );
	void	Show4E1C1L( CStringArray* csaLabels, CStringArray* csaListEntries  );
	void	Show4E1C1ML( CStringArray* csaLabels, CStringArray* csaListEntries  );
	void	Show4E1C2E( CStringArray* csaLabels );
	void	Show4E2C( CStringArray* csaLabels );
	void	Show5E( CStringArray* csaLabels );
	void	Show5E1L( CStringArray* csaLabels, CStringArray* csaListEntries  );
	void	Show5E1ML1L2E( CStringArray* csaLabels, CStringArray* csaListEntries, CStringArray* csaList2Entries );
	void	Show5E1C1L( CStringArray* csaLabels, CStringArray* csaListEntries  );
	void	Show5E1C1L1C( CStringArray* csaLabels, CStringArray* csaListEntries  );
	void	Show5E1C( CStringArray* csaLabels );
	void	Show6E2L2C( CStringArray* csaLabels, CStringArray* csaListEntries, CStringArray* csaList2Entries );


	void	ShowEditControls( CStringArray* pcsaLabels );
	void	ShowHLLControls( CStringArray* pcsaLabels );

	void	ShowAirAxControls( int nFunction );
	void	ShowAirJControls( int nFunction );
	void	ShowAirVMControls( int nFunction );
	void	ShowCASLControls( int nFunction );
	void	ShowCICSCOMControls( int nFunction );
	void	ShowCICS11JAVAControls( int nFunction );
	void	ShowCICS20JAVAControls( int nFunction );
	void	ShowCICSNETControls( int nFunction );
	void	ShowDOSControls( int nFunction );
	void	ShowEALControls( int nFunction );
	void	ShowEAOJControls( int nFunction );
	void	ShowEAOAxVTControls( int nFunction );
	void	ShowEAOAx3270Controls( int nFunction );
	void	ShowEAOAx5250Controls( int nFunction );
	void	ShowEHLControls();
	void	ShowEOLEControls( int nFunction );
	void	ShowHLLControls( int nFunction );
	void	ShowICONNControls( int nFunction );
	void	ShowITaskControls( int nFunction );
	void	ShowMSIAppControls( int nFunction );
	void	ShowMSICustomControls( int nFunction );
	void	ShowMSIDBaseControls( int nFunction );
	void	ShowMSIExecControls( int nFunction );
	void	ShowMSISummaryControls( int nFunction );
	void	ShowWIXDlgControls( int nFunction );
	void	ShowWIXWizControls( int nFunction );
	void	ShowPerforceControls( int nFunction );
	void	ShowQAComControls( int nFunction );
	void	ShowRFTPControls( int nFunction );
	void	ShowRIBMControls( int nFunction );
	void	ShowROLEControls( int nFunction );
	void	ShowRWebControls( int nFunction );
	void	ShowUNIXControls( int nFunction );
	void	ShowRWinControls( int nFunction );
	void	ShowVHIControls( int nFunction );
	void	ShowWHLControls();


	void LoadAirlinesJavaArgumentArray( int* nFunctionPosition, BOOL m_bPromptForValues );
	void LoadAirlinesAxArgumentArray( int* nFunctionPosition, BOOL m_bPromptForValues );
	void LoadAirVMArgumentArray( int* nFunctionPosition, BOOL m_bPromptForValues );
	void LoadCASLArgumentArray( int* nFunctionPosition, BOOL m_bPromptForValues );
	void LoadCICSCOMArgumentArray( int* nFunctionPosition, BOOL m_bPromptForValues );
	void LoadCICS11JAVAArgumentArray( int* nFunctionPosition, BOOL m_bPromptForValues );
	void LoadCICS20JAVAArgumentArray( int* nFunctionPosition, BOOL m_bPromptForValues );
	void LoadCICSNETArgumentArray( int* nFunctionPosition, BOOL m_bPromptForValues );
	void LoadDOSArgumentArray( int* nFunctionPosition, BOOL m_bPromptForValues );
	void LoadEALArgumentArray( int* nFunctionPosition, BOOL m_bPromptForValues );
	void LoadEAOAxVTArgumentArray( int* nFunctionPosition, BOOL m_bPromptForValues );
	void LoadEAOAx3270ArgumentArray( int* nFunctionPosition, BOOL m_bPromptForValues );
	void LoadEAOAx5250ArgumentArray( int* nFunctionPosition, BOOL m_bPromptForValues );
	void LoadEAOJArgumentArray( int* nFunctionPosition, BOOL m_bPromptForValues );
	void LoadEHLArgumentArray( int* nFunctionPosition, BOOL m_bPromptForValues );
	void LoadHLLArgumentArray( int* nFunctionPosition, BOOL bPromptForValues );
	void LoadICONNArgumentArray( int* nFunctionPosition, BOOL bPromptForValues );
	void LoadITaskArgumentArray( int* nFunctionPosition, BOOL bPromptForValues );
	void LoadEOLEArgumentArray( int* nFunctionPosition, BOOL bPromptForValues );
	void LoadMSIAppArgumentArray( int* nFunctionPosition, BOOL bPromptForValues );
	void LoadMSICustomArgumentArray( int* nFunctionPosition, BOOL bPromptForValues );
	void LoadMSIDBaseArgumentArray( int* nFunctionPosition, BOOL bPromptForValues );
	void LoadMSIExecArgumentArray( int* nFunctionPosition, BOOL bPromptForValues );
	void LoadMSISummaryArgumentArray( int* nFunctionPosition, BOOL bPromptForValues );
	void LoadWIXDlgArgumentArray( int* nFunctionPosition, BOOL bPromptForValues );
	void LoadWIXWizArgumentArray( int* nFunctionPosition, BOOL bPromptForValues );
	void LoadPerforceArgumentArray( int* nFunctionPosition, BOOL bPromptForValues );
	void LoadRFTPArgumentArray( int* nFunctionPosition, BOOL bPromptForValues );
	void LoadRIBM_OLEArgumentArray( int* nFunctionPosition, BOOL bPromptForValues );
	void LoadRWeb_ArgumentArray( int* nFunctionPosition, BOOL bPromptForValues );
	void LoadRWIN_OLEArgumentArray( int* nFunctionPosition, BOOL bPromptForValues );
	void LoadQAComArgumentArray( int* nFunctionPosition, BOOL bPromptForValues );
	void LoadUNIXArgumentArray( int* nFunctionPosition, BOOL m_bPromptForValues );
	void LoadVHIArgumentArray( int* nFunctionPosition, BOOL bPromptForValues );
	void LoadWHLArgumentArray( int* nFunctionPosition, BOOL m_bPromptForValues );


	BOOL	m_bNoFileSpecified;

	void	SetUI();

	CAPIGenState	RunState;
	CStringArray	csaHeader;
	CStringArray	csaMidSection1;
	CStringArray	csaMidSection2;
	CStringArray	csaMidSection3;
	CStringArray	csaBody;
	CStringArray	csaFunctions;
	CStringArray	csaArguments;
	CStringArray	csaCaboose;
	CString			m_csTargetFileName;

	CStringArray	csaLabels;

	static CAG* cagtest;


public:

	CButton m_checkInsertIntoFile;
	afx_msg void OnHelp();
	// Save to a source file that you can run
	CButton m_buttonSaveToFile;

protected:
	int nGlobalPSMallocSize;
public:
	CListBox listTerminalType;
	afx_msg void ChangeTerminalOrLanguage();
	afx_msg void ChangeTerminal();

	CEdit m_EditArgument1;
	CString m_csEditArgument1;
	afx_msg void OnChangeArgument1();

	CEdit m_EditArgument2;
	CString m_csEditArgument2;

	CString m_csEditArgument3;
	CEdit m_EditArgument3;

	CEdit m_EditArgument4;
	CString m_csEditArgument4;
	CStatic m_staticString4;

	CEdit m_EditArgument5;
	CString m_csEditArgument5;
	CStatic m_staticString5;

	CEdit m_EditArgument6;
	CString m_csEditArgument6;
	CStatic m_staticString6;

	CEdit m_EditArgument7;
	CString m_csEditArgument7;
	CStatic m_staticString7;

	CEdit m_EditArgument8;
	CString m_csEditArgument8;
	CStatic m_staticString8;

	CEdit m_EditArgument9;
	CString m_csEditArgument9;
	CStatic m_staticString9;
	
	CEdit m_EditArgument10;
	CString m_csEditArgument10;
	CStatic m_staticString10;

	CEdit m_EditArgument11;
	CString m_csEditArgument11;
	CStatic m_staticString11;

	CEdit m_EditArgument12;
	CString m_csEditArgument12;
	CStatic m_staticString12;

	CEdit m_EditArgument13;
	CString m_csEditArgument13;
	CStatic m_staticString13;

	CEdit m_EditArgument14;
	CString m_csEditArgument14;
	CStatic m_staticString14;


	CButton cb_PassiveMode;
	BOOL bPassiveMode;
	
	CListBox m_listFileExists;
	CListBox m_listTransferType;
	CButton cbEABsEnabled;
	BOOL bEABsEnabled;
	CStatic staticTerminalType;

	CListBox listParams1;
	CListBox listParams2;
	CListBox listParams3;
	CListBox listParams4;
	CListBox listParams5;

	CButton checkParam1;
	CButton checkParam2;
	CButton checkParam3;
	CButton checkParam4;

	BOOL bCheckParam1;
	BOOL bCheckParam2;
	BOOL bCheckParam3;
	BOOL bCheckParam4;

	CListBox listMultiParams1;
	CListBox listMultiParams2;
	CListBox listMultiParams3;
	CListBox listMultiParams4;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_APIGENDLG_H__155B49D9_09DB_4D6E_8512_EC07927C48B1__INCLUDED_)
