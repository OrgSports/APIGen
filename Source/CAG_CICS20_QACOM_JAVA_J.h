// Static Model


#ifndef __CAG_CICS20_QACOM_JAVA_J__
#define __CAG_CICS20_QACOM_JAVA_J__


// Include files
#include "CAG_CICS_QACOM_JAVA.h"
class CAG_CICS20_QACOM_JAVA_J : public CAG_CICS_QACOM_JAVA
{

public:

	CAG_CICS20_QACOM_JAVA_J();
	~CAG_CICS20_QACOM_JAVA_J();

	void checkDebug(bool b_Debug,
				 CString csFunctionName,
				 CStringArray* pcsaBody);

	void resetVariableFlags();

	void generateHeader(CStringArray* csaHeader,
					 CStringArray* csaBody);

	void appendBody(int nFunctionNum,
				 bool bPromptForValues,
				 CStringArray* csaArguments,
				 CStringArray* csaHeader,
				 CStringArray* csaBody);

	void loadFunctionList(CListBox* listTranslateFunction);

    void finalize(CStringArray* pcsaBody);

private:
    bool b_FindString;
    bool b_outRow;
    bool b_outColumn;
    bool b_outFieldCount;
    bool b_outFieldNames;
    bool b_outFieldValues ;
    bool b_outFieldAttributes;
    bool b_outFieldRows;
    bool b_outFieldCols;
    bool b_outFieldLengths;
    bool b_outFieldColors;
    bool b_outFieldHighlights;
    bool b_outStatus;
    bool b_outScreenName;
    bool b_Attribute;
    bool b_outFieldRs;
    bool b_outFieldCs;
    bool b_outFieldLs;
    bool b_outFieldN;
    bool b_outFieldVal;
    bool b_outText;
    bool b_outNumChars;
    bool b_outSystemID;
    

};// END CLASS DEFINITION CAG_CICS20_QACOM_JAVA_J

#endif // __CAG_CICS20_QACOM_JAVA_J__
