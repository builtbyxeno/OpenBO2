#include "types.h"
#include "functions.h"

/*
==============
FindCommonAddrGroup
==============
*/
bdSecurityID *FindCommonAddrGroup(const bdSecurityID *id)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
CommonAddrToInAddr
==============
*/
unsigned int CommonAddrToInAddr(CommonAddrGroup *group, CommonAddr *addr)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
PacketSummaryString
==============
*/
const char *PacketSummaryString(const void *dataVoid, int length)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
InAddrToCommonAddr
==============
*/
bool InAddrToCommonAddr(unsigned int inaddr, CommonAddrGroup **resultGroup, CommonAddr **resultAddr)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
dwCheckConnections
==============
*/
int dwCheckConnections()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
dwNetadrToAddrHandle
==============
*/
/*bdReference<bdAddrHandle> *dwNetadrToAddrHandle(
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}*/

/*
==============
dwNetadrToCommonAddr
==============
*/
char dwNetadrToCommonAddr(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
dwCommonAddrToString
==============
*/
unsigned int dwCommonAddrToString(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
dwCommonAddrToInAddr
==============
*/
in_addr dwCommonAddrToInAddr(const unsigned __int8 *commonAddrBuf, const unsigned int commonAddrBufSize)
{
	UNIMPLEMENTED(__FUNCTION__);
	in_addr tmp;
	return tmp;
}

/*
==============
dwGetConnectionTaskStatus
==============
*/
int dwGetConnectionTaskStatus(netadr_t *const netadr)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
dwPrintAddrGroups
==============
*/
void dwPrintAddrGroups()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
dwNetInit
==============
*/
void dwNetInit()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
RegisterCommonAddrGroup
==============
*/
const char *RegisterCommonAddrGroup(const bdSecurityID *id)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
UnregisterCommonAddrGroup
==============
*/
const char *UnregisterCommonAddrGroup(const bdSecurityID *id)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
RegisterEndpoint
==============
*/
unsigned int RegisterEndpoint(const bdEndpoint *endpoint, const char **errorMsg)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
DeregisterEndpoint
==============
*/
const char *DeregisterEndpoint(const bdEndpoint *endpoint)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
dwRegisterSecIDAndKey
==============
*/
bool dwRegisterSecIDAndKey(const bdSecurityID *id, const bdSecurityKey *key)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
dwSendTo
==============
*/
int dwSendTo(const unsigned int length, const void *data, const netadr_t to)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
dwRecvFrom
==============
*/
int dwRecvFrom(netadr_t *const from, void *const data, const unsigned int size)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
dwCommonAddrToNetadr
==============
*/
char dwCommonAddrToNetadr(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
dwUnregisterSecIDAndKey
==============
*/
void dwUnregisterSecIDAndKey(const bdSecurityID *id)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
dwCloseConnection
==============
*/
char dwCloseConnection(netadr_t *const netadr)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
ClearCommonAddrGroups
==============
*/
void ClearCommonAddrGroups()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
dwNetStop
==============
*/
void dwNetStop()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
dwNetPump
==============
*/
void dwNetPump()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
dwNetStart
==============
*/
void dwNetStart(const bool online)
{
	UNIMPLEMENTED(__FUNCTION__);
}

