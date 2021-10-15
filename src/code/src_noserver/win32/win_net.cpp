#include "types.h"

/*
==============
TRACK_win_net
==============
*/
void TRACK_win_net()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
NET_ErrorString
==============
*/
char *NET_ErrorString()
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Sys_StringToSockaddr
==============
*/
int Sys_StringToSockaddr(const char *s, sockaddr *sadr)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
NetadrToSockadr
==============
*/
void NetadrToSockadr(netadr_t *a, sockaddr *s)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SockadrToNetadr
==============
*/
void SockadrToNetadr(sockaddr *s, netadr_t *a)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Sys_StringToAdr
==============
*/
int Sys_StringToAdr(const char *s, netadr_t *a)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Sys_GetPacket
==============
*/
int Sys_GetPacket(netadr_t *net_from, msg_t *net_message)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Sys_SendPacket
==============
*/
bool Sys_SendPacket(const char *a1, netsrc_t sock, int length, const void *data, netadr_t to)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Sys_ShowIP
==============
*/
void Sys_ShowIP()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
NET_IPSocket
==============
*/
SOCKET NET_IPSocket(const char *net_interface, int port)
{
	UNIMPLEMENTED(__FUNCTION__);
	SOCKET tmp;
	return tmp;
}

/*
==============
NET_GetLocalAddress
==============
*/
int NET_GetLocalAddress()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
NET_OpenIP
==============
*/
void NET_OpenIP()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
NET_GetDvars
==============
*/
int NET_GetDvars()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Sys_CheckForNATOverflow
==============
*/
void Sys_CheckForNATOverflow()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Sys_SocketPool_GetPacket
==============
*/
int Sys_SocketPool_GetPacket(netadr_t *net_from, msg_t *net_message)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
NET_Config
==============
*/
void NET_Config(int enableNetworking)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
NET_Restart
==============
*/
void NET_Restart()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Xenon_RegisterRemoteXenon
==============
*/
char Xenon_RegisterRemoteXenon(const XSESSION_INFO *info, netadr_t *addr)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
NET_IsWinsockReady
==============
*/
int NET_IsWinsockReady()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
NET_Init
==============
*/
void NET_Init()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Xenon_GetXNAddr
==============
*/
/*XNADDR *Xenon_GetXNAddr(bdReference<bdCommonAddr> renew)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}*/

/*
==============
dwPlatformInit
==============
*/
int dwPlatformInit(bdNetStartParams *params)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

