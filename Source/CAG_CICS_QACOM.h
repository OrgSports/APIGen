// Static Model


#ifndef __CAG_CICS_QACOM__
#define __CAG_CICS_QACOM__

#include "CAG.H"

class CAG_CICS_QACOM : public CAG
{

public:

	CAG_CICS_QACOM();

	~CAG_CICS_QACOM();

	void loadTerminalTypeList(CListBox* listTerminalTypes);

};// END CLASS DEFINITION CAG_CICS_QACOM

#endif // __CAG_CICS_QACOM__
