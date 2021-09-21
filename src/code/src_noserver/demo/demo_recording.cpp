#include "types.h"
#include "functions.h"

/*
==============
Demo_PopulateStaticFooterInformation
==============
*/
void Demo_PopulateStaticFooterInformation(demoFooter *footer)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Demo_GetActiveMemoryBuffer
==============
*/
unsigned __int8 *Demo_GetActiveMemoryBuffer()
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Demo_WriteMemoryBlockDataToFile
==============
*/
int Demo_WriteMemoryBlockDataToFile()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Demo_WriteMemoryBlockDataToBuffer
==============
*/
int Demo_WriteMemoryBlockDataToBuffer(demoMemBlock *memBlock, unsigned __int8 *to, int maxBufferSize)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Demo_SetIntermissionPoint
==============
*/
void Demo_SetIntermissionPoint(vec3_t *origin, vec3_t *angles)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Demo_RecordPlayerSessionState
==============
*/
void Demo_RecordPlayerSessionState(ClientNum_t clientNum, int state)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Demo_IsInFinalKillcam
==============
*/
bool Demo_IsInFinalKillcam()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Demo_ClientConnected
==============
*/
void Demo_ClientConnected(ClientNum_t clientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Demo_GetDefaultClient
==============
*/
ClientNum_t Demo_GetDefaultClient()
{
	UNIMPLEMENTED(__FUNCTION__);
	ClientNum_t tmp;
	return tmp;
}

/*
==============
Demo_IsGameStateWritten
==============
*/
bool Demo_IsGameStateWritten()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Demo_WriteHeader
==============
*/
void Demo_WriteHeader(msg_t *msg, bool isDemoClip)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Demo_ShouldFilterServerCommand
==============
*/
bool Demo_ShouldFilterServerCommand(ClientNum_t clientNum, const char *cmd)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Demo_WriteServerCommands
==============
*/
void Demo_WriteServerCommands(msg_t *msg, bool liveStreamNoDelta)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Demo_WriteSnapshotStartData
==============
*/
void Demo_WriteSnapshotStartData(msg_t *msg, int msgSequence, int cmdSequence, int serverTime, int physicsTime, int lastFrame, int snapFlags, bool liveStreamNoDelta)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Demo_WriteMatchState
==============
*/
void Demo_WriteMatchState(msg_t *msg, bool liveStreamNoDelta)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Demo_WritePlayerStates
==============
*/
void Demo_WritePlayerStates(msg_t *msg, bool liveStreamNoDelta)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Demo_WritePacketEntities
==============
*/
void Demo_WritePacketEntities(msg_t *msg, bool liveStreamNoDelta)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Demo_InfoPlayerConnected
==============
*/
void Demo_InfoPlayerConnected(ClientNum_t clientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Demo_UpdatePlayerDisconnectInformation
==============
*/
void Demo_UpdatePlayerDisconnectInformation(ClientNum_t clientNum, int playerIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Demo_InfoPlayerDisconnected
==============
*/
void Demo_InfoPlayerDisconnected(ClientNum_t clientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Demo_WritePacketClients
==============
*/
void Demo_WritePacketClients(msg_t *msg, bool liveStreamNoDelta)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Demo_WritePacketActors
==============
*/
void Demo_WritePacketActors(msg_t *msg, bool liveStreamNoDelta)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Demo_WriteSpawnDebugBuffer
==============
*/
void Demo_WriteSpawnDebugBuffer(msg_t *msg, bool liveStreamNoDelta)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Demo_LogClientPacket
==============
*/
void Demo_LogClientPacket(netchan_t *pChan, int iSize, int bFragment)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Demo_LogReliableCmd
==============
*/
void Demo_LogReliableCmd(ClientNum_t cl, int iSize, char cmdChar)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Demo_WriteExtraNetworkProfileData
==============
*/
void Demo_WriteExtraNetworkProfileData(msg_t *msg)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Demo_BuildDemoSnapshotInternal
==============
*/
void __cdecl Demo_BuildDemoSnapshotInternal(msg_t *msg, bool liveStreamNoDelta)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Demo_WriteFooterInternal
==============
*/
void Demo_WriteFooterInternal(msg_t *msg, demoFooter *footer, bool isClip)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Demo_WriteClipFooterToBuffer
==============
*/
unsigned int Demo_WriteClipFooterToBuffer(demoFooter *footer, unsigned __int8 *buffer, int maxBufferSize, int clipDuration)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Demo_WriteFooter
==============
*/
void Demo_WriteFooter(int handle, demoFooter *footer)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Demo_AddBookmark
==============
*/
void Demo_AddBookmark(int type, int time, int clientNum1, int clientNum2, int scoreEventPriority, int entityNumber, int eType, int birthTime, int overrideEntityCamera, int actorNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Demo_SetLagFlag
==============
*/
void Demo_SetLagFlag(demoLagFlag_e flag)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Demo_GetLagFlag
==============
*/
demoLagFlag_e Demo_GetLagFlag()
{
	UNIMPLEMENTED(__FUNCTION__);
	demoLagFlag_e tmp;
	return tmp;
}

/*
==============
Demo_StartRecord
==============
*/
void Demo_StartRecord()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Demo_SaveInternal
==============
*/
void Demo_SaveInternal(unsigned __int8 *data, int size, bool writeFooter, bool gameState)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Demo_Save
==============
*/
void Demo_Save(unsigned __int8 *data, int size, unsigned __int8 *writeFooter, bool gameState)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Demo_ShouldBuildDemoSnapshot
==============
*/
bool Demo_ShouldBuildDemoSnapshot()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Demo_StartSaveProcess
==============
*/
void Demo_StartSaveProcess(bool gameState)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Demo_SaveCallback
==============
*/
int __cdecl Demo_SaveCallback(jqBatch *batch)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Demo_WriteGamestateToBuffer
==============
*/
void Demo_WriteGamestateToBuffer(ClientNum_t clientNum, msg_t *msg, int msgSequence)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Demo_BuildDemoSnapshot
==============
*/
void Demo_BuildDemoSnapshot()
{
	UNIMPLEMENTED(__FUNCTION__);
}

