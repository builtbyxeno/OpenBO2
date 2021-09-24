#include "types.h"

/*
==============
SV_GameClientNum
==============
*/
playerState_s *SV_GameClientNum(int num)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
SV_SvEntityForGentity
==============
*/
svEntity_s *SV_SvEntityForGentity(const gentity_t *gEnt)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
SV_GameSendServerCommand
==============
*/
void SV_GameSendServerCommand(ClientNum_t clientNum, svscmd_type type, const char *text)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SV_GameDropClient
==============
*/
void SV_GameDropClient(ClientNum_t clientNum, const char *reason)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SV_SetMapCenter
==============
*/
void SV_SetMapCenter(vec3_t *mapCenter)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SV_GetMapCenter
==============
*/
vec3_t *SV_GetMapCenter()
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
SV_SetGameEndTime
==============
*/
void SV_SetGameEndTime(int gameEndTime)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SV_SetBrushModel
==============
*/
bool SV_SetBrushModel(gentity_t *ent)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
SV_inSnapshot
==============
*/
BOOL SV_inSnapshot(const vec3_t *origin, int iEntityNum)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
SV_GetServerinfo
==============
*/
void SV_GetServerinfo(char *buffer, int bufferSize)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SV_LocateGameData
==============
*/
void SV_LocateGameData(gentity_t *gEnts, int numGEntities, int sizeofGEntity_t, playerState_s *clients, int sizeofGameClient, actor_t *gameActors, int sizeofGameActors)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SV_GetUsercmd
==============
*/
void SV_GetUsercmd(ClientNum_t clientNum, usercmd_s *cmd)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SV_AllocXModelPrecache
==============
*/
void *SV_AllocXModelPrecache(int size)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
SV_AllocXModelPrecacheColl
==============
*/
void *SV_AllocXModelPrecacheColl(int size)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
SV_XModelGet
==============
*/
XModel *SV_XModelGet(const char *name)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
SV_DObjDumpInfo
==============
*/
void SV_DObjDumpInfo(gentity_t *ent)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SV_ResetSkeletonCache
==============
*/
void SV_ResetSkeletonCache()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SV_AllocSkelMemory
==============
*/
char *SV_AllocSkelMemory(unsigned int size)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
SV_DObjCreateSkelForBone
==============
*/
int SV_DObjCreateSkelForBone(DObj *obj, int boneIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
SV_DObjCreateSkelForBones
==============
*/
int SV_DObjCreateSkelForBones(DObj *obj, int *partBits)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
SV_DObjUpdateServerTime
==============
*/
void SV_DObjUpdateServerTime(gentity_t *ent, float dtime, int bNotify)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SV_DObjInitServerTime
==============
*/
void SV_DObjInitServerTime(gentity_t *ent, float dtime)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SV_DObjGetBoneIndex
==============
*/
int SV_DObjGetBoneIndex(const gentity_t *ent, unsigned int boneName)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
SV_DObjGetParentBoneIndex
==============
*/
int SV_DObjGetParentBoneIndex(const gentity_t *ent, int childBoneIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
SV_DObjGetMatrixArray
==============
*/
DObjAnimMat *SV_DObjGetMatrixArray(const gentity_t *ent)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
SV_DObjDisplayAnim
==============
*/
void SV_DObjDisplayAnim(gentity_t *ent, const char *header)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SV_DObjGetRotTransArray
==============
*/
DObjAnimMat *SV_DObjGetRotTransArray(const gentity_t *ent)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
SV_DObjSetRotTransIndex
==============
*/
int SV_DObjSetRotTransIndex(const gentity_t *ent, int *partBits, int boneIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
SV_DObjGetBounds
==============
*/
void SV_DObjGetBounds(gentity_t *ent, vec3_t *mins, vec3_t *maxs)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SV_DObjGetTree
==============
*/
XAnimTree_s *SV_DObjGetTree(gentity_t *ent)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
SV_MapExists
==============
*/
BOOL SV_MapExists(const char *name)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
SV_DObjExists
==============
*/
BOOL SV_DObjExists(gentity_t *ent)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
SV_track_shutdown
==============
*/
void SV_track_shutdown()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SV_SavePaths
==============
*/
void SV_SavePaths(unsigned __int8 *buf, int size)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SV_GetGuid
==============
*/
int SV_GetGuid(ClientNum_t clientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
SV_GetClientPing
==============
*/
int SV_GetClientPing(ClientNum_t clientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
SV_IsLocalClient
==============
*/
BOOL SV_IsLocalClient(ClientNum_t clientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
SV_AllClientsAreLocal
==============
*/
char SV_AllClientsAreLocal()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
SV_SetGametype
==============
*/
void SV_SetGametype()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SV_InitGameVM
==============
*/
void SV_InitGameVM(int restart, int registerDvars, int savegame)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SV_ShutdownGameVM
==============
*/
void SV_ShutdownGameVM(int clearScripts)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SV_RestartGameProgs
==============
*/
void SV_RestartGameProgs(int savepersist)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SV_InitGameProgs
==============
*/
void SV_InitGameProgs(int savepersist, int savegame)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SV_GameCommand
==============
*/
int SV_GameCommand()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
SV_Archived_Dvar_GetVariantString
==============
*/
const char *SV_Archived_Dvar_GetVariantString(const char *dvarName)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
SV_Archived_Dvar_GetInt
==============
*/
int SV_Archived_Dvar_GetInt(int dvarHash)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
SV_Archived_Dvar_GetFloat
==============
*/
double SV_Archived_Dvar_GetFloat(int dvarHash)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
SV_EntityContact
==============
*/
int SV_EntityContact(unsigned int a1, const vec3_t *mins, const vec3_t *maxs, const gentity_t *gEnt)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
SV_ShutdownGameProgs
==============
*/
void SV_ShutdownGameProgs()
{
	UNIMPLEMENTED(__FUNCTION__);
}

