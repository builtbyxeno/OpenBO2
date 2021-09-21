#include "types.h"
#include "functions.h"

/*
==============
MSG_EntityIsLinked
==============
*/
bool MSG_EntityIsLinked(const entityState_s *ent)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
MSG_WriteGroundEntityNum
==============
*/
void MSG_WriteGroundEntityNum(const ClientNum_t clientNum, msg_t *msg, const int groundEntityNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
MSG_WriteDeltaField_Default
==============
*/
void MSG_WriteDeltaField_Default(const SnapshotInfo_s *snapInfo, msg_t *msg, const NetField *field, const int *fromF, const int *toF)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
MSG_WriteDeltaStruct
==============
*/
int MSG_WriteDeltaStruct(SnapshotInfo_s *snapInfo, msg_t *msg, const int time, unsigned __int8 *from, unsigned __int8 *to, int force, int numFields, int indexBits, const NetField *stateFields, int bChangeBit, int skippedFieldBits)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
MSG_WriteAppendedDeltaStruct
==============
*/
int MSG_WriteAppendedDeltaStruct(SnapshotInfo_s *snapInfo, msg_t *msg, const int time, unsigned __int8 *from, unsigned __int8 *to, int force, int numFields, int indexBits, const NetField *stateFields, int bChangeBit, int skippedFieldBits)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
MSG_WriteEntityDeltaFields
==============
*/
void MSG_WriteEntityDeltaFields(const SnapshotInfo_s *snapInfo, msg_t *msg, const int time, const entityState_s *fromES, const entityState_s *toES, const int force, int lastChanged, int numFields, const NetField *stateFields, const int skippedFieldBits, unsigned int *fieldsChanged)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
MSG_WriteEntityDelta
==============
*/
int MSG_WriteEntityDelta(const SnapshotInfo_s *snapInfo, msg_t *msg, const int time, const entityState_s *fromES, const entityState_s *toES, DeltaFlags flags, int numFields, int indexBits, const NetField *stateFields, const char *tableName, const BitField *bitFields)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
MSG_WriteDeltaArchivedEntity
==============
*/
bool MSG_WriteDeltaArchivedEntity(SnapshotInfo_s *snapInfo, msg_t *msg, const int time, const archivedEntity_s *from, const archivedEntity_s *to, DeltaFlags flags)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
UpdateEntTimesForTimeDelta
==============
*/
void UpdateEntTimesForTimeDelta(entityState_s *ent, const int timeDelta)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PrintChangedEntityFields
==============
*/
void PrintChangedEntityFields(SnapshotInfo_s *snapInfo, const entityState_s *from, const entityState_s *to)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SV_ValidateEntityState
==============
*/
void SV_ValidateEntityState(const entityState_s *entState)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
MSG_WriteEntity
==============
*/
int MSG_WriteEntity(SnapshotInfo_s *snapInfo, msg_t *msg, const int timeDeltaFrom, const int timeDeltaTo, const int time, const entityState_s *from, const entityState_s *to, DeltaFlags flags)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
MSG_WriteDeltaHudElems
==============
*/
void MSG_WriteDeltaHudElems(SnapshotInfo_s *snapInfo, msg_t *msg, const int time, const hudelem_s *from, const hudelem_s *to, int count)
{
	UNIMPLEMENTED(__FUNCTION__);
}

