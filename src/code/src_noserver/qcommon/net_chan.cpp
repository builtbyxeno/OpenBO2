#include "types.h"

// Only used inside NET_AdrToString
char s[64] = {};

// Only used inside NET_AdrToStringDW
char s_0[64] = {};

// Only used inside XNKEYToString
char str_0[34] = {};

char str_1[256] = {};

// Used within net_chan.cpp
PacketQueue loopbackQueues[5];
PacketQueue deferredQueue;

// Used within net_chan.cpp
char* netsrcString[5] =
{
	'client1', 'client2', 'client3', 'client4', 'client5'
};

/*
==============
NET_AdrToString
==============
*/
char *NET_AdrToString(netadr_t a)
{
	Com_sprintf(s, sizeof(s), "unknown");

	if (a.type == NA_LOOPBACK)
		Com_sprintf(s, sizeof(s), "loopback");

	else
	{
		if (a.type == NA_IP)
			Com_sprintf(s, sizeof(s), "%i.%i.%i.%i:%i:%i (%d)", a.ip[0], a.ip[1], a.ip[2], a.ip[3], BigShort(a.port), a.serverID, a.localNetID);
	}

	return s;
}

/*
==============
NET_AdrToStringDW
==============
*/
char *NET_AdrToStringDW(netadr_t a)
{
	Com_sprintf(s_0, sizeof(s_0), "unknown");

	if (a.type == NA_LOOPBACK)
		Com_sprintf(s_0, sizeof(s_0), "loopback");

	else
	{
		if (a.type == NA_IP)
			Com_sprintf(s_0, sizeof(s_0), "%i.%i.%i.%i:%i", a.ip[0], a.ip[1], a.ip[2], a.ip[3], a.port);
	}

	return s_0;
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
void Netchan_Setup(netsrc_t sock, netchan_t *chan, netadr_t adr, int qport, char *outgoingBuffer, int outgoingBufferSize, char *incomingBuffer, int incomingBufferSize)
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
	if (chan->unsentBuffer == ptr)
	{
		assert(chan->unsentOnLoan == qtrue);
		assert(chan->unsentFragments == qfalse);

		chan->unsentOnLoan = 0;
	}
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
	for (unsigned int i = 37; i >= 4; i -= 4)
	{
		if (*(DWORD*)a->addrBuff != *(DWORD*)b->addrBuff)
			break;

		b = (XNADDR*)((char*)b + 4);
		a = (XNADDR*)((char*)a + 4);
	}

	return a->addrBuff[0] == b->addrBuff[0] && i <= 1;
}

/*
==============
NET_IsLocalAddress
==============
*/
BOOL NET_IsLocalAddress(const netadr_t adr)
{
	return adr.type == NA_LOOPBACK || adr.type == NA_BOT;
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
	msg_t* msg = net_message;

	const unsigned __int8* data = net_message->data;
	const int maxsize = net_message->maxsize;
	unsigned int flags = 0;

	if (!NET_DequeuePacket(
		&loopbackQueues[sock],
		&flags,
		(netsrc_t*)&net_message,
		net_from,
		maxsize,
		&net_message->cursize,
		data))
		return 0;

	*(QWORD*)net_from->ip = 0;
	*(QWORD*)&net_from->type = 0;
	*(DWORD*)&net_from->serverID = 0;

	net_from->port = (unsigned __int16)msg;
	net_from->localNetID = (netsrc_t)msg;
	net_from->type = NA_LOOPBACK;

	return 1;
}

/*
==============
NET_SendLoopPacket
==============
*/
void NET_SendLoopPacket(netsrc_t sock, int length, const void *data, netadr_t to)
{
	netadr_t addr = to;

	assert(to.port == to.localNetID);

	NET_EnqueuePacket(&loopbackQueues[addr.port], 0, sock, &addr, length, data);
}

/*
==============
NET_DeferPacketToClient
==============
*/
void NET_DeferPacketToClient(netadr_t *net_from, msg_t *net_message)
{
	assert(Sys_IsServerThread());
	assert(net_from);
	assert(net_message);

	NET_EnqueuePacket(&deferredQueue, 0, net_message->targetLocalNetID, net_from, net_message->cursize, net_message->data);
}

/*
==============
NET_GetDeferredClientPacket
==============
*/
bool NET_GetDeferredClientPacket(netadr_t *net_from, msg_t *net_message)
{
	assert(Sys_IsMainThread());
	assert(net_from);
	assert(net_message);

	const unsigned __int8* data = net_message->data;
	const int maxsize = net_message->maxsize;
	unsigned int flags = 0;

	return NET_DequeuePacket(
		&deferredQueue,
		&flags,
		&net_message->targetLocalNetID,
		net_from,
		maxsize,
		&net_message->cursize,
		data);
}

/*
==============
NET_DeferNonVoicePacket
==============
*/
void NET_DeferNonVoicePacket(netadr_t *net_from, msg_t *net_message)
{
	assert(Sys_IsMainThread());
	assert(net_from);
	assert(net_message);

	const unsigned __int8* data = net_message->data;
	const int maxsize = net_message->maxsize;
	unsigned int flags = 0;

	return NET_DequeuePacket(
		&deferredQueue,
		&flags,
		&net_message->targetLocalNetID,
		net_from,
		maxsize,
		&net_message->cursize,
		data);
}

/*
==============
NET_GetNonVoiceDeferred
==============
*/
bool NET_GetNonVoiceDeferred(netadr_t *net_from, msg_t *net_message)
{
	assert(net_from);
	assert(net_message);

	netadr_t* v2 = net_from;
	const unsigned __int8 *data = net_message->data;
	const int maxsize = net_message->maxsize;
	net_from = 0;

	return NET_DequeuePacket(
		&nonVoiceDeferredQueue,
		(unsigned int*)&net_from,
		&net_message->targetLocalNetID,
		v2,
		maxsize,
		&net_message->cursize,
		data);
}

/*
==============
NET_SendPacket
==============
*/
bool NET_SendPacket(netsrc_t sock, int length, const void *data, netadr_t to)
{
	if (Dvar_GetInt(showpackets) && *(DWORD*)data == -1)
		Com_Printf(10, "[%s] send packet %4i\n", netsrcString[sock], length);

	if (to.type != NA_LOOPBACK)
		return to.type != NA_BAD && to.type && Sys_SendPacket(sock, length, data, to);

	NET_SendLoopPacket(sock, length, data, to);

	return true;
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
	_snprintf(str, 0x11u, "%08x%08x", (DWORD)int64, DWORD(int64));
}

/*
==============
XUIDToString
==============
*/
void XUIDToString(const unsigned __int64 *xuid, char *str)
{
	_ui64toa(*xuid, str, 16);
}

/*
==============
XUIDToStringDecimal
==============
*/
void XUIDToStringDecimal(const unsigned __int64 *xuid, char *str)
{
	_ui64toa(*xuid, str, 10);
}

/*
==============
StringToXUID
==============
*/
void StringToXUID(const char *str, unsigned __int64 *xuid)
{
	*xuid = _strtoui64(str, 0, 16);
}

/*
==============
StringToXUIDDecimal
==============
*/
void StringToXUIDDecimal(const char *str, unsigned __int64 *xuid)
{
	*xuid = _strtoui64(str, 0, 10);
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
int Sys_VerifyPacketChecksum(int a1, const unsigned __int8 *payload, int paylen)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Sys_CheckSumPacketCopy
==============
*/
unsigned int Sys_CheckSumPacketCopy(const unsigned __int8 *a1, unsigned __int8 *dest, const unsigned __int8 *payload, int paylen)
{
	if (paylen <= 1264)
		return Sys_ChecksumCopy(dest, payload, paylen);

	assertMsg("paylen exceeds MAX_PACKETLEN");

	return 65535;
}

/*
==============
XNKEYToString
==============
*/
char *XNKEYToString(const bdSecurityKey *xnkey)
{
	_snprintf(
		str_0,
		sizeof(str_0),
		"%02x%02x%02x%02x%02x%02x%02x%02x %02x%02x%02x%02x%02x%02x%02x%02x",
		xnkey->ab[0],
		xnkey->ab[1],
		xnkey->ab[2],
		xnkey->ab[3],
		xnkey->ab[4],
		xnkey->ab[5],
		xnkey->ab[6],
		xnkey->ab[7],
		xnkey->ab[8],
		xnkey->ab[9],
		xnkey->ab[10],
		xnkey->ab[11],
		xnkey->ab[12],
		xnkey->ab[13],
		xnkey->ab[14],
		xnkey->ab[15]);

	return str_0;
}

/*
==============
XNAddrToString
==============
*/
char *XNAddrToString(const XNADDR *xnaddr)
{
	dwCommonAddrToString(xnaddr->addrBuff, sizeof(xnaddr->addrBuff), str_1, sizeof(str_1));

	return str_1;
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
	assert(chan->unsentOnLoan == qfalse);

	MSG_Init(&send, send_buf, 1264);

	if (chan->reliable_fragments)
		MSG_WriteLong(&send, chan->outgoingSequence | 0xC0000000);
	else
		MSG_WriteLong(&send, chan->outgoingSequence | 0x80000000);

	if (chan->sock < NS_SERVER)
		MSG_WriteShort(&send, chan->qport);

	MSG_WriteByte(&send, (unsigned __int8)fragmentIndex);
	MSG_WriteByte(&send, (unsigned __int8)maxFragmentIndex);
	MSG_WriteShort(&send, 1232);
	MSG_WriteShort(&send, fragmentLength);
	MSG_WriteData(&send, &chan->unsentBuffer[1232 * fragmentIndex], fragmentLength);

	const int res = NET_SendPacket(chan->sock, send.cursize, send.data, chan->remoteAddress);
	const iSize = send.cursize;

	Demo_LogClientPacket(chan, send.cursize, 1);

	if (net_iProfilingOn)
	{
		NetProf_AddPacket(&chan->prof.send, iSize, 1);

		if ((Dvar_GetInt(net_showprofile) & 2) != 0)
			Com_Printf(10, "[%s] send%s: %i\n", netsrcString[chan->sock], " fragment", iSize);
	}

	Int = Dvar_GetInt(showpackets);

	if (Int && (Int > 1 || chan->remoteAddress.type != NA_LOOPBACK))
		Com_Printf(
			10,
			"[%s] send %4i : s=%i fragment=%i,%i\n",
			netsrcString[chan->sock],
			send.cursize,
			chan->outgoingSequence - 1,
			1232 * fragmentIndex,
			fragmentLength);

	return res;
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
	PIXBeginNamedEvent(-1, "NET_GetClientPacket");

	if (NET_GetNonVoiceDeferred(net_from, net_message))
	{
		if (Sys_IsRenderThread())
			D3DPERF_EndEvent();
	}

	else
	{
		if (Sys_IsRenderThread())
			D3DPERF_EndEvent();
		return Sys_GetPacket(net_from, net_message);
	};

	return 1;
}

/*
==============
NET_GetServerPacket
==============
*/
int NET_GetServerPacket(netadr_t *net_from, msg_t *net_message)
{
	PIXBeginNamedEvent(-1, "NET_GetServerPacket");

	if (NET_GetNonVoiceDeferred(net_from, net_message))
	{
		if (Sys_IsRenderThread())
			D3DPERF_EndEvent();
	}

	else
	{
		if (Sys_IsRenderThread())
			D3DPERF_EndEvent();

		return Sys_GetPacket(net_from, net_message);
	}

	return 1;
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

