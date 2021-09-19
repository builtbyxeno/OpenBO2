#include "types.h"
#include "functions.h"

/*
==============
NET_AdrToString
==============
*/
char *NET_AdrToString(netadr_t a)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
NET_AdrToStringDW
==============
*/
char *NET_AdrToStringDW(netadr_t a)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
NetProf_PrepProfiling
==============
*/
void NetProf_PrepProfiling(netProfileInfo_t *prof)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
NetProf_AddPacket
==============
*/
void NetProf_AddPacket(netProfileStream_t *pProfStream, int iSize, int bFragment)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
NetProf_NewRecievePacket
==============
*/
void NetProf_NewRecievePacket(netchan_t *pChan, int iSize, int bFragment)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
NetProf_UpdateStatistics
==============
*/
void NetProf_UpdateStatistics(netProfileStream_t *pStream)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Net_DumpProfile_f
==============
*/
void Net_DumpProfile_f()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Net_GetQPort_f
==============
*/
void Net_GetQPort_f()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Net_SetQPort_f
==============
*/
void Net_SetQPort_f()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Net_DisplayProfile
==============
*/
void Net_DisplayProfile(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
TRACK_net_chan
==============
*/
void TRACK_net_chan()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Netchan_Init
==============
*/
void Netchan_Init(int port)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Netchan_Setup
==============
*/
void Netchan_Setup(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Netchan_BorrowBuffer
==============
*/
unsigned __int8 *Netchan_BorrowBuffer(netchan_t *chan, int size)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Netchan_ReturnBuffer
==============
*/
void Netchan_ReturnBuffer(netchan_t *chan, unsigned __int8 *ptr)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
NET_CompareBaseAdrSigned
==============
*/
int NET_CompareBaseAdrSigned(netadr_t *a, netadr_t *b, bool skipLocalClient)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
NET_CompareBaseAdr
==============
*/
BOOL NET_CompareBaseAdr(netadr_t a, netadr_t b)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
NET_CompareIPAdr
==============
*/
BOOL NET_CompareIPAdr(netadr_t a, netadr_t b)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
NET_CompareAdrSigned
==============
*/
int NET_CompareAdrSigned(netadr_t *a, netadr_t *b)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
NET_CompareAdr
==============
*/
BOOL NET_CompareAdr(netadr_t a, netadr_t b)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
NET_CompareXNAddr
==============
*/
BOOL NET_CompareXNAddr(XNADDR *a, XNADDR *b)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
NET_IsLocalAddress
==============
*/
BOOL NET_IsLocalAddress(const netadr_t adr)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
NET_IsLocalIP
==============
*/
BOOL NET_IsLocalIP(const netadr_t adr)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
NET_IsZeroIP
==============
*/
BOOL NET_IsZeroIP(const netadr_t adr)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
NET_SetNetAdrLoopbackIP
==============
*/
void NET_SetNetAdrLoopbackIP(netadr_t *src)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
NET_GetLoopPacket
==============
*/
int NET_GetLoopPacket(netsrc_t sock, netadr_t *net_from, msg_t *net_message)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
NET_SendLoopPacket
==============
*/
void NET_SendLoopPacket(netsrc_t sock, int length, const void *data, netadr_t to)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
NET_DeferPacketToClient
==============
*/
void NET_DeferPacketToClient(netadr_t *net_from, msg_t *net_message)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
NET_GetDeferredClientPacket
==============
*/
bool NET_GetDeferredClientPacket(netadr_t *net_from, msg_t *net_message)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
NET_DeferNonVoicePacket
==============
*/
void NET_DeferNonVoicePacket(netadr_t *net_from, msg_t *net_message)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
NET_GetNonVoiceDeferred
==============
*/
bool NET_GetNonVoiceDeferred(netadr_t *net_from, msg_t *net_message)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
NET_SendPacket
==============
*/
bool NET_SendPacket(netsrc_t sock, int length, const void *data, netadr_t to)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
NET_OutOfBandPrint
==============
*/
bool NET_OutOfBandPrint(netsrc_t sock, netadr_t adr, const char *data)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
NET_OutOfBandData
==============
*/
BOOL NET_OutOfBandData(netsrc_t sock, netadr_t adr, const unsigned __int8 *format, int len)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
NET_OutOfBandVoiceData
==============
*/
BOOL NET_OutOfBandVoiceData(netsrc_t sock, netadr_t adr, unsigned __int8 *format, int len)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
NET_StringToAdr
==============
*/
int NET_StringToAdr(const char *s, netadr_t *a)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Int64ToString
==============
*/
void Int64ToString(__int64 int64, char *str)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
XUIDToString
==============
*/
void XUIDToString(const unsigned __int64 *xuid, char *str)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
XUIDToStringDecimal
==============
*/
void XUIDToStringDecimal(const unsigned __int64 *xuid, char *str)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
StringToXUID
==============
*/
void StringToXUID(const char *str, unsigned __int64 *xuid)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
StringToXUIDDecimal
==============
*/
void StringToXUIDDecimal(const char *str, unsigned __int64 *xuid)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
ByteArrayToString
==============
*/
void ByteArrayToString(const void *from, unsigned int fromSize, char *to, unsigned int toSize)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
StringToByteArray
==============
*/
void StringToByteArray(const char *from, unsigned int fromSize, void *to, unsigned int toSize)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
XNAddrToString
==============
*/
void XNAddrToString(const XNADDR *xnaddr, char *str)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
StringToXNAddr
==============
*/
void StringToXNAddr(const char *str, XNADDR *xnaddr)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Sys_Checksum
==============
*/
unsigned __int16 Sys_Checksum(const unsigned __int8 *src, int len)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Sys_ChecksumCopy
==============
*/
unsigned __int16 Sys_ChecksumCopy(unsigned __int8 *dest, const unsigned __int8 *src, int len)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Sys_VerifyPacketChecksum
==============
*/
/*int Sys_VerifyPacketChecksum@<eax>(int a1@<edx>, const unsigned __int8 *payload, int paylen)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}*/

/*
==============
Sys_CheckSumPacketCopy
==============
*/
/*unsigned int Sys_CheckSumPacketCopy@<eax>(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}*/

/*
==============
XNKEYToString
==============
*/
char *XNKEYToString(const bdSecurityKey *xnkey)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
XNAddrToString
==============
*/
char *XNAddrToString(const XNADDR *xnaddr)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Netchan_TransmitFragment
==============
*/
int Netchan_TransmitFragment(netchan_t *chan, int fragmentLength, int fragmentIndex, int maxFragmentIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Netchan_TransmitNextFragment
==============
*/
bool Netchan_TransmitNextFragment(netchan_t *chan)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Netchan_Transmit
==============
*/
bool Netchan_Transmit(netchan_t *chan, int length, const unsigned __int8 *data, bool reliable_fragments)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Netchan_Process
==============
*/
int Netchan_Process(netchan_t *chan, msg_t *msg)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
NET_GetClientPacket
==============
*/
int NET_GetClientPacket(netadr_t *net_from, msg_t *net_message)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
NET_GetServerPacket
==============
*/
int NET_GetServerPacket(netadr_t *net_from, msg_t *net_message)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
XSessionToString
==============
*/
char *XSessionToString(const XSESSION_INFO *info)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

