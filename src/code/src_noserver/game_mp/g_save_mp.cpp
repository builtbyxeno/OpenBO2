#include "types.h"
#include "functions.h"

/*
==============
ConsumeSentinelBlock
==============
*/
void ConsumeSentinelBlock(MemoryFile *memFile, const int content)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
ReadField
==============
*/
void ReadField(const saveField_t *field, unsigned __int8 *base, MemoryFile *memFile)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
G_SaveError
==============
*/
void G_SaveError(errorParm_t code, SaveErrorType errorType, const char *fmt, ...)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SV_LoadConfigstrings
==============
*/
void SV_LoadConfigstrings(const int first, const int count, MemoryFile *memFile)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
LoadWeapons
==============
*/
int LoadWeapons(MemoryFile *memFile)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
G_LoadLevelBGS
==============
*/
void G_LoadLevelBGS(MemoryFile *memFile)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
LoadClientFields
==============
*/
int LoadClientFields(MemoryFile *memFile)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
ReadVehicleIndex
==============
*/
int ReadVehicleIndex(MemoryFile *memFile)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Scr_FreeFields
==============
*/
void Scr_FreeFields(const saveField_t *fields, unsigned __int8 *base)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
LoadPlayerCorpses
==============
*/
void LoadPlayerCorpses(MemoryFile *memFile)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
ReadLerpFrame
==============
*/
void ReadLerpFrame(MemoryFile *memFile, lerpFrame_t *lerpFrame)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
ReadClientInfo
==============
*/
void ReadClientInfo(MemoryFile *memFile, const ClientNum_t clientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
G_LoadModelPrecacheList
==============
*/
void G_LoadModelPrecacheList(MemoryFile *memFile)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
G_LoadInitState
==============
*/
void __cdecl G_LoadInitState(MemoryFile *memFile)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Scr_FreeActorFields
==============
*/
void Scr_FreeActorFields(actor_t *pActor)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Scr_FreeSentientFields
==============
*/
void Scr_FreeSentientFields(sentient_t *sentient)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
ReadActorPotentialCoverNodes
==============
*/
void ReadActorPotentialCoverNodes(actor_t *pActor, MemoryFile *memFile)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
VerifySaveGame
==============
*/
void VerifySaveGame(SaveGame *saveGame, SaveHeader *header)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
G_PreLoadGame
==============
*/
void G_PreLoadGame(SaveGame **saveGame, int *levelTime)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
G_ReadStruct
==============
*/
void G_ReadStruct(const saveField_t *fields, unsigned __int8 *dest, int tempsize, MemoryFile *memFile)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
ReadEntity
==============
*/
void ReadEntity(gentity_t *ent, SaveGame *save)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
ReadTurretInfo
==============
*/
void ReadTurretInfo(TurretInfo *turret, SaveGame *save)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
ReadPathNodes
==============
*/
void ReadPathNodes(MemoryFile *memFile)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
ReadSentient
==============
*/
void ReadSentient(sentient_t *sentient, MemoryFile *memFile)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
ReadVehicle
==============
*/
void ReadVehicle(vehicle_t *pVehicle, MemoryFile *memFile)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
ReadActor
==============
*/
void ReadActor(actor_t *pActor, MemoryFile *memFile)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
G_LoadLevelState
==============
*/
void G_LoadLevelState(SaveGame *save)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
G_LoadMainState
==============
*/
void G_LoadMainState(SaveGame *save, int scriptRunning, int demoSave)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
G_LoadGame
==============
*/
void G_LoadGame(int checksum, SaveGame *save, int scriptRunning, int demoSave)
{
	UNIMPLEMENTED(__FUNCTION__);
}

