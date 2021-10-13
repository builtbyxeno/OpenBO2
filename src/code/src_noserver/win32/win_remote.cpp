#include "types.h"

/*
==============
NET_DebugConsoleBinarySendHandler
==============
*/
HRESULT NET_DebugConsoleBinarySendHandler(_DM_CMDCONT *pdmcc)
{
	UNIMPLEMENTED(__FUNCTION__);
	HRESULT tmp;
	return tmp;
}

/*
==============
NET_DebugConsoleBinaryReceiveHandler
==============
*/
char *NET_DebugConsoleBinaryReceiveHandler(_DM_CMDCONT *pdmcc)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
NET_AllocNode
==============
*/
DataNode *NET_AllocNode()
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
NET_InitDataNodes
==============
*/
unsigned int NET_InitDataNodes()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
NET_DebugConsoleCmdProcessor
==============
*/
HRESULT NET_DebugConsoleCmdProcessor(const char *strCommand, char *strResponse, unsigned int dwResponseLen, _DM_CMDCONT *pdmcc)
{
	UNIMPLEMENTED(__FUNCTION__);
	HRESULT tmp;
	return tmp;
}

/*
==============
NET_InitDebug
==============
*/
void NET_InitDebug()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Sys_IsRemoteDebugServer
==============
*/
int Sys_IsRemoteDebugServer()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Sys_EndWriteDebugSocket
==============
*/
void Sys_EndWriteDebugSocket()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Sys_RegisterDebugSocketDataHunk
==============
*/
void Sys_RegisterDebugSocketDataHunk(HunkUser *hunk)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Sys_AckDebugSocket
==============
*/
void Sys_AckDebugSocket()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
NET_ShutdownDebug
==============
*/
void NET_ShutdownDebug()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
NET_RestartDebug
==============
*/
void NET_RestartDebug()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Sys_DebugSocketError
==============
*/
void Sys_DebugSocketError(const char *message)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Sys_StartRemoteDebugServer
==============
*/
char Sys_StartRemoteDebugServer()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Sys_FlushDebugSocketData
==============
*/
void Sys_FlushDebugSocketData()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Sys_ReadDebugSocketData
==============
*/
int Sys_ReadDebugSocketData(void **buffer, int *len)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Sys_ReadDebugSocketString
==============
*/
const GfxViewParms *Sys_ReadDebugSocketString()
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Sys_ReadDebugSocketInt
==============
*/
int Sys_ReadDebugSocketInt()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Sys_WriteDebugSocketData
==============
*/
void Sys_WriteDebugSocketData(const void *buffer, int len)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Sys_WriteDebugSocketMessageType
==============
*/
void Sys_WriteDebugSocketMessageType(unsigned __int8 type)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Sys_WriteDebugSocketString
==============
*/
void Sys_WriteDebugSocketString(const void *text)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Sys_WriteDebugSocketInt
==============
*/
void Sys_WriteDebugSocketInt(int value)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Sys_WriteDebugSocketFloat
==============
*/
void Sys_WriteDebugSocketFloat(float value)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Sys_UpdateDebugSocket
==============
*/
int Sys_UpdateDebugSocket()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

