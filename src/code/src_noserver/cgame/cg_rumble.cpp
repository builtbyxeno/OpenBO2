#include "types.h"
#include "functions.h"

/*
==============
Rumble_Strcpy
==============
*/
void Rumble_Strcpy(unsigned __int8 *member, const char *keyValue)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
ParseRumbleGraph
==============
*/
bool ParseRumbleGraph(RumbleGraph *graph, const char *buffer, const char *fileName)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
ReadRumbleGraph
==============
*/
bool ReadRumbleGraph(RumbleGraph *graph, const char *rumbleFileName)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LoadRumbleGraph
==============
*/
/*char LoadRumbleGraph@<al>(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}*/

/*
==============
CG_LoadRumble
==============
*/
bool CG_LoadRumble(RumbleGraph *rumbleGraphArray, RumbleInfo *info, const char *name, int rumbleNameIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CG_RegisterRumbles
==============
*/
void CG_RegisterRumbles(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DrawActiveRumbles
==============
*/
void DrawActiveRumbles(LocalClientNum_t localClientNum, const ActiveRumble *activeRumbleArray)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
RemoveInactiveRumbles
==============
*/
void RemoveInactiveRumbles(LocalClientNum_t localClientNum, ActiveRumble *activeRumbleArray)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CalcActiveRumbles
==============
*/
void CalcActiveRumbles(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
GetRumbleInfoIndexFromName
==============
*/
int GetRumbleInfoIndexFromName(LocalClientNum_t localClientNum, const char *rumbleName)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
DuplicateRumbleExists
==============
*/
bool DuplicateRumbleExists(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
NextAvailableRumble
==============
*/
ActiveRumble *NextAvailableRumble(const cg_t *cgameGlob, ActiveRumble *arArray)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
PlayRumbleInternal
==============
*/
void PlayRumbleInternal(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_PlayRumbleOnEntity
==============
*/
void CG_PlayRumbleOnEntity(LocalClientNum_t localClientNum, const char *rumbleName, int entityNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_PlayRumbleOnPosition
==============
*/
void CG_PlayRumbleOnPosition(LocalClientNum_t localClientNum, const char *rumbleName, const vec3_t *pos)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_PlayRumbleLoopOnEntity
==============
*/
void CG_PlayRumbleLoopOnEntity(LocalClientNum_t localClientNum, const char *rumbleName, int entityNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_PlayRumbleLoopOnPosition
==============
*/
void CG_PlayRumbleLoopOnPosition(LocalClientNum_t localClientNum, const char *rumbleName, const vec3_t *pos)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_PlayRumbleOnClient
==============
*/
void CG_PlayRumbleOnClient(LocalClientNum_t localClientNum, const char *rumbleName)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_PlayLoopRumbleOnClient
==============
*/
void CG_PlayLoopRumbleOnClient(LocalClientNum_t localClientNum, const char *rumbleName)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_StopRumble
==============
*/
void CG_StopRumble(LocalClientNum_t localClientNum, int entityNum, const char *rumbleName)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_StopAllRumbles
==============
*/
void CG_StopAllRumbles(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_SetRumbleReceiver
==============
*/
void CG_SetRumbleReceiver(LocalClientNum_t localClientNum, int entityNum, const vec3_t *position)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_DrawRumbleDebug
==============
*/
void CG_DrawRumbleDebug(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
RumbleGraphEventCallback
==============
*/
void RumbleGraphEventCallback(const DevGraph *graph, DevEventType event, LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
RumbleGraphTextCallback
==============
*/
void RumbleGraphTextCallback(const DevGraph *graph, const float inputX, const float inputY, char *text)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
InitDevguiRumbleGraphInteral
==============
*/
void InitDevguiRumbleGraphInteral(const char *rumbleName, RumbleGraph *rumbleGraph, RumbleInfo *rumbleInfo)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_InitDevguiRumbleGraph
==============
*/
void CG_InitDevguiRumbleGraph(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_UpdateRumble
==============
*/
void CG_UpdateRumble(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

