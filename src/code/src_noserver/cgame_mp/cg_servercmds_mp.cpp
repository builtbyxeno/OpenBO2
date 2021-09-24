#include "types.h"

/*
==============
CG_ParseServerInfo
==============
*/
void CG_ParseServerInfo(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_ParseCodInfo
==============
*/
void CG_ParseCodInfo(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_ParseCullDist
==============
*/
void CG_ParseCullDist()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_ParseTimeScale
==============
*/
void CG_ParseTimeScale(const LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_BuildPartyList
==============
*/
void CG_BuildPartyList()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_ParseGameEndTime
==============
*/
void CG_ParseGameEndTime(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_ParseFog
==============
*/
void CG_ParseFog(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_RegisterServerMaterial
==============
*/
void CG_RegisterServerMaterial(int configStringIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_SetConfigValues
==============
*/
void CG_SetConfigValues(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_UpdateVoteString
==============
*/
void CG_UpdateVoteString(LocalClientNum_t localClientNum, const char *rawVoteString)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_ParseClientSystemStateChange
==============
*/
void CG_ParseClientSystemStateChange(LocalClientNum_t localClientNum, int sysIndex, const char *pState)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_ParseAirsupport
==============
*/
void CG_ParseAirsupport(LocalClientNum_t localClientNum, float x, float y, float z, int yaw, char *type, char *teamFaction, char *team, int owner, char *exitType, int serverTime, int height)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_AddToTeamChat
==============
*/
void CG_AddToTeamChat(LocalClientNum_t localClientNum, const char *str)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_RemoveChatEscapeChar
==============
*/
void CG_RemoveChatEscapeChar(char *text)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_ClearEntityFxHandles
==============
*/
void CG_ClearEntityFxHandles(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_ClearGenericFilter
==============
*/
void CG_ClearGenericFilter(cg_t *gameglob)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_MapReset
==============
*/
void CG_MapReset(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_OpenScriptMenu
==============
*/
void CG_OpenScriptMenu(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_CheckOpenWaitingScriptMenu
==============
*/
void CG_CheckOpenWaitingScriptMenu(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_CloseScriptMenu
==============
*/
void CG_CloseScriptMenu(LocalClientNum_t localClientNum, bool allowResponse)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_MenuShowNotify
==============
*/
void CG_MenuShowNotify(LocalClientNum_t localClientNum, int menuToShow)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_SetTeamScore
==============
*/
void CG_SetTeamScore(LocalClientNum_t localClientNum, int team, int score)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
LocalSound
==============
*/
bool LocalSound(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LocalSoundStop
==============
*/
void LocalSoundStop(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_SetScriptMainMenu
==============
*/
void CG_SetScriptMainMenu(cg_t *cgameGlob, const char *text)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_SetClientDvarFromServer
==============
*/
void CG_SetClientDvarFromServer(cg_t *cgameGlob, dvar_cmd_t dvarCmd, const char *value)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_BurnServerCommand
==============
*/
void CG_BurnServerCommand(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_ElectrifiedServerCommand
==============
*/
void CG_ElectrifiedServerCommand(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_ParseExploderCommand
==============
*/
void CG_ParseExploderCommand(LocalClientNum_t localClientNum, int exploderId)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_WaterDropsServerCommand
==============
*/
void CG_WaterDropsServerCommand(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_ScrCamera
==============
*/
void CG_ScrCamera(LocalClientNum_t localClientNum, int cmd)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_BlurServerCommand
==============
*/
void CG_BlurServerCommand(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_StartFadingBlurServerCommand
==============
*/
void CG_StartFadingBlurServerCommand(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_ParsePlayerInfos
==============
*/
void CG_ParsePlayerInfos(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_ConfigStringModified
==============
*/
void CG_ConfigStringModified(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_MapRestart
==============
*/
void CG_MapRestart(LocalClientNum_t localClientNum, int savepersist)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_DeployServerCommand
==============
*/
void CG_DeployServerCommand(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_ExecuteNewServerCommands
==============
*/
void CG_ExecuteNewServerCommands(LocalClientNum_t localClientNum, int latestSequence)
{
	UNIMPLEMENTED(__FUNCTION__);
}

