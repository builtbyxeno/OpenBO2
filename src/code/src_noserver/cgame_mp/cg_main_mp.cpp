#include "types.h"

/*
==============
CG_GetClientNumForLocalClient
==============
*/
ClientNum_t CG_GetClientNumForLocalClient(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
	ClientNum_t tmp;
	return tmp;
}

/*
==============
CG_IsRagdollTrajectory
==============
*/
BOOL CG_IsRagdollTrajectory(const trajectory_t *trajectory)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CG_SetupSplitscreenDvars
==============
*/
void CG_SetupSplitscreenDvars(bool splitscreen)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_RegisterDvars_Project
==============
*/
void CG_RegisterDvars_Project()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
TRACK_cg_main_project
==============
*/
void TRACK_cg_main_project()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_GetDObjOrientation
==============
*/
void CG_GetDObjOrientation(LocalClientNum_t localClientNum, int dobjHandle, vec3_t *axis, vec3_t *origin)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_GetPredictedPlayerState
==============
*/
playerState_s *CG_GetPredictedPlayerState(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
CG_GameMessage
==============
*/
void CG_GameMessage(LocalClientNum_t localClientNum, const char *msg)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_BoldGameMessage
==============
*/
void CG_BoldGameMessage(LocalClientNum_t localClientNum, const char *msg, int duration)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_RegisterSurfaceTypeSounds
==============
*/
void CG_RegisterSurfaceTypeSounds(const char *pszType, unsigned int *sound)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_RegisterImpactTypeSounds
==============
*/
void CG_RegisterImpactTypeSounds(const char *pszType, unsigned int *sound)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_RegisterSounds
==============
*/
void CG_RegisterSounds(const char *a1, unsigned int *a2)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_RegisterGrenadeFx
==============
*/
void CG_RegisterGrenadeFx(LocalClientNum_t localClientNum, const FxEffectDef *fxHandle)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_RegisterGraphics
==============
*/
void CG_RegisterGraphics(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_PlayBattleChatter
==============
*/
void CG_PlayBattleChatter(LocalClientNum_t localClientNum, int entitynum, const vec3_t *origin, int firstSoundAlias, int secondSoundAlias)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_CheckBattleChatter
==============
*/
void CG_CheckBattleChatter()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_RestartSmokeGrenades
==============
*/
void CG_RestartSmokeGrenades(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_LoadHudMenu
==============
*/
void CG_LoadHudMenu(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_InitVote
==============
*/
void CG_InitVote(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_GetXModel
==============
*/
XModel *CG_GetXModel(const char *modelName)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
CG_CreateDObj
==============
*/
void CG_CreateDObj(DObjModel_s *dobjModels, unsigned __int16 numModels, XAnimTree_s *tree, int handle, LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_GetDObj
==============
*/
DObj *CG_GetDObj(int handle, LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
CG_FreeAnimTreeInstances
==============
*/
void CG_FreeAnimTreeInstances(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CScr_LoadGameType
==============
*/
void CScr_LoadGameType()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CScr_StartupGameType
==============
*/
void CScr_StartupGameType()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CScr_LoadGameTypeScript
==============
*/
int CScr_LoadGameTypeScript()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CScr_LoadDogAnimScripts
==============
*/
unsigned int CScr_LoadDogAnimScripts()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CScr_LoadZombieAnimScripts
==============
*/
unsigned int CScr_LoadZombieAnimScripts()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CScr_LoadZombieDogAnimScripts
==============
*/
unsigned int CScr_LoadZombieDogAnimScripts()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CScr_LoadScriptsForEntities
==============
*/
int CScr_LoadScriptsForEntities()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CScr_LoadServerSideScripts
==============
*/
void CScr_LoadServerSideScripts(const char *mapname, const char *gametype, int *scr_checksum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CGScr_LoadClientScripts
==============
*/
void CGScr_LoadClientScripts(const char *mapname)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CGScr_LoadClientScriptsZombies
==============
*/
void CGScr_LoadClientScriptsZombies(const char *mapname)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_InitEntities
==============
*/
void CG_InitEntities(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_InitViewDimensions
==============
*/
void CG_InitViewDimensions(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_GetClientNum
==============
*/
ClientNum_t CG_GetClientNum(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
	ClientNum_t tmp;
	return tmp;
}

/*
==============
CG_IsShoutcaster
==============
*/
bool CG_IsShoutcaster(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CG_IsShoutcasterListening
==============
*/
bool CG_IsShoutcasterListening(LocalClientNum_t localClientNum, ClientNum_t talker)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CG_ResetShoutcasterListenIn
==============
*/
void CG_ResetShoutcasterListenIn(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_SetShoutcasterListenIn
==============
*/
void CG_SetShoutcasterListenIn(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_AddShoutcasterListenIn
==============
*/
void CG_AddShoutcasterListenIn(LocalClientNum_t localClientNum, ClientNum_t client)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_RemoveShoutcasterListenIn
==============
*/
void CG_RemoveShoutcasterListenIn(LocalClientNum_t localClientNum, ClientNum_t client)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_IsMature
==============
*/
bool CG_IsMature()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CG_GetEntityOriginAngles
==============
*/
char CG_GetEntityOriginAngles(LocalClientNum_t localClientNum, int entityNum, vec3_t *origin, vec3_t *angles)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CG_GetVehicleTypeString
==============
*/
int CG_GetVehicleTypeString(ClientNum_t clientNum, int entityNum, VehicleDef **vehDef)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CachedTag_UpdateTagInternal
==============
*/
int CachedTag_UpdateTagInternal(const centity_t *ent, cached_client_tag_t *cachedTag, unsigned int tagName, int updateInterval, bool forceUpdate)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CachedTag_NoCache_GetTagPos
==============
*/
int CachedTag_NoCache_GetTagPos(const centity_t *ent, unsigned int tagName, vec3_t *pos)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CachedTag_GetCachedTagPos
==============
*/
int CachedTag_GetCachedTagPos(unsigned int a1, const centity_t *ent, cached_client_tag_t *cachedTag, unsigned int tagName, vec3_t *pos, int updateInterval, cached_client_tag_t *forceUpdate)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CachedTag_GetTagPos
==============
*/
int __cdecl CachedTag_GetTagPos(const centity_t *ent, unsigned int tagName, vec3_t *pos, int updateInterval, cached_client_tag_t *forceUpdate)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CG_AllClientsAreLocal
==============
*/
BOOL CG_AllClientsAreLocal()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CG_InitClientEntityCaches
==============
*/
void CG_InitClientEntityCaches(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_FreeClientEntityCaches
==============
*/
void CG_FreeClientEntityCaches(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_ProcessFullScreenBit
==============
*/
void CG_ProcessFullScreenBit(LocalClientNum_t localClientNum, int oldFlags, int newFlags)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_SetupGameInformation
==============
*/
void CG_SetupGameInformation(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_TestServerScriptChecksum
==============
*/
int CG_TestServerScriptChecksum(LocalClientNum_t localClientNum, int *scr_checksum)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CG_Scr_AddFloat_BGWrapper
==============
*/
void CG_Scr_AddFloat_BGWrapper(float val)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_Scr_AddString_BGWrapper
==============
*/
void CG_Scr_AddString_BGWrapper(const char *pStr)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_Scr_AddLocalClientNumber_BGWrapper
==============
*/
void CG_Scr_AddLocalClientNumber_BGWrapper(LocalClientNum_t num)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_Scr_ExecEntThreadNum_BGWrapper
==============
*/
void CG_Scr_ExecEntThreadNum_BGWrapper(LocalClientNum_t lcn, int entNum, int func, int numParam)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_GetServerHighestClientFieldVersion
==============
*/
unsigned int CG_GetServerHighestClientFieldVersion()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CG_ClientFieldServerVersionAllowsRegistration
==============
*/
BOOL CG_ClientFieldServerVersionAllowsRegistration(unsigned int version)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CG_ClientFieldVersionAllowsRegistration
==============
*/
BOOL CG_ClientFieldVersionAllowsRegistration(clientField_s *pField, unsigned int version)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CG_CompareClientFieldHashToGameState
==============
*/
void CG_CompareClientFieldHashToGameState(unsigned int hash)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_ProcessClientFieldsForEntity
==============
*/
void CG_ProcessClientFieldsForEntity(centity_t *pCent, LocalClientNum_t localClientNum, bool bNewEnt, bool bWasDemoJump, playerState_s *prevPs, playerState_s *ps)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_ShutdownOnceForAllClients
==============
*/
void CG_ShutdownOnceForAllClients()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_SaveMigrationPers
==============
*/
void CG_SaveMigrationPers(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_LoadMigrationPers
==============
*/
void CG_LoadMigrationPers(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_ProcessTriggerDebug
==============
*/
void CG_ProcessTriggerDebug(centity_t *ent, trigger_info_t *trigger_info)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_NotifyTriggers
==============
*/
int CG_NotifyTriggers()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CG_Trigger
==============
*/
void CG_Trigger(centity_t *self, centity_t *other)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_Touch_Multi
==============
*/
void CG_Touch_Multi(centity_t *self, centity_t *other)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Hunk_AllocXAnimClient
==============
*/
void *Hunk_AllocXAnimClient(int size)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Hunk_AllocAnimStateDefClient
==============
*/
void *Hunk_AllocAnimStateDefClient(int size)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
CG_IsClientInOurParty
==============
*/
bool CG_IsClientInOurParty(LocalClientNum_t localClientNum, ClientNum_t clientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CG_LoadAnimTreeInstances
==============
*/
void CG_LoadAnimTreeInstances(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_LoadAnimTrees
==============
*/
void CG_LoadAnimTrees(LocalClientNum_t localClientNum, cg_t *cgameGlob, const char *mapname, bool loading_scripts)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_Init
==============
*/
void CG_Init(char *a1, LocalClientNum_t localClientNum, int serverMessageNum, int serverCommandSequence, ClientNum_t clientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_Shutdown
==============
*/
void CG_Shutdown(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_GetXModel
==============
*/
XModel *CG_GetXModel(const char *name, LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

