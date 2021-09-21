#include "types.h"
#include "functions.h"

/*
==============
TRACK_msg
==============
*/
void TRACK_msg()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
MSG_LoopThroughFields
==============
*/
void MSG_LoopThroughFields(const NetFieldList *fieldToCheck)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
MSG_CheckForDuplicateOffsets
==============
*/
void MSG_CheckForDuplicateOffsets()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
MSG_GetStateFieldListForEntityType
==============
*/
const NetFieldList *MSG_GetStateFieldListForEntityType(const int eType, bool isDemoSnapshot)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
MSG_GetNetFieldList
==============
*/
const NetFieldList *MSG_GetNetFieldList(netFieldTypes_t fieldType, bool isDemoSnapshot)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
MSG_WriteReliableCommandToBuffer
==============
*/
void MSG_WriteReliableCommandToBuffer(const char *pszCommand, char **pszBuffer, char *allocBufferBase, int allocBufferLength, int *allocBufferPos)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
MSG_WriteOriginFloat
==============
*/
void MSG_WriteOriginFloat(const SnapshotInfo_s *snapInfo, const ClientNum_t clientNum, msg_t *msg, int bits, float value, float oldValue)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
MSG_WriteOriginZFloat
==============
*/
void MSG_WriteOriginZFloat(const SnapshotInfo_s *snapInfo, const ClientNum_t clientNum, msg_t *msg, float value, float oldValue)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
MSG_WriteDemoRoundedFloat
==============
*/
void MSG_WriteDemoRoundedFloat(msg_t *msg, int bits, float value, float oldValue, int diffBits, int fullBits)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
MSG_CompareRangedFloat
==============
*/
bool MSG_CompareRangedFloat(const float oldValue, const float value, const float begin, const float end, const int precision)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
MSG_ValuesAreEqual
==============
*/
bool MSG_ValuesAreEqual(const ClientNum_t clientNum, int bits, int size, const int *fromF, const int *toF)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
MSG_ShouldSendPsViewAngles
==============
*/
bool MSG_ShouldSendPsViewAngles(const SnapshotInfo_s *snapInfo, const playerState_s *ps, const playerState_s *oldPs, const NetField *field)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
MSG_ShouldSendPSField
==============
*/

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
}

/*
==============
MSG_WriteEntityIndex
==============
*/
void MSG_WriteEntityIndex(const SnapshotInfo_s *snapInfo, msg_t *msg, const int index, const int indexBits)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
MSG_WriteLastChangedField
==============
*/
void MSG_WriteLastChangedField(msg_t *msg, const int lastChangedFieldNum, int numFields)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
MSG_WriteDeltaTime
==============
*/
void MSG_WriteDeltaTime(const ClientNum_t clientNum, msg_t *msg, int timeBase, int time)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
MSG_WriteDeltaFrameTime
==============
*/
void MSG_WriteDeltaFrameTime(const ClientNum_t clientNum, msg_t *msg, int timeBase, int time)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
MSG_WriteEFlags
==============
*/
void MSG_WriteEFlags(const ClientNum_t clientNum, msg_t *msg, const int oldFlags, const int newFlags)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
MSG_WriteEventNum
==============
*/
void MSG_WriteEventNum(const ClientNum_t clientNum, msg_t *msg, int eventNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
MSG_WriteEventParam
==============
*/
void MSG_WriteEventParam(const ClientNum_t clientNum, msg_t *msg, int eventParam)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
MSG_HighBitNumber
==============
*/
int MSG_HighBitNumber(unsigned int v)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
MSG_WriteRangedFloat
==============
*/
int MSG_WriteRangedFloat(const ClientNum_t clientNum, msg_t *msg, const float oldValue, const float value, const float begin, const float end, const int precision, const bool oftenZeroOrOne)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
MSG_GetPacketEntityTypeForEType
==============
*/
PacketEntityType MSG_GetPacketEntityTypeForEType(int eType)
{
	UNIMPLEMENTED(__FUNCTION__);
	PacketEntityType tmp;
	return tmp;
}

/*
==============
MSG_EncodeSkippedFields
==============
*/
void MSG_EncodeSkippedFields(const SnapshotInfo_s *snapInfo, msg_t *msg, int numFieldsSkipped, const int skippedFieldBits)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
MSG_WriteValueNoXor
==============
*/
void MSG_WriteValueNoXor(const SnapshotInfo_s *snapInfo, msg_t *msg, int value, const int bits)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
MSG_WriteValue
==============
*/
void MSG_WriteValue(const SnapshotInfo_s *snapInfo, msg_t *msg, const int *fromF, const int *toF, const int bits, const int size)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
MSG_WriteDeltaAngle
==============
*/
void MSG_WriteDeltaAngle(const SnapshotInfo_s *snapInfo, msg_t *msg, const float oldFloat, const float fullFloat)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
MSG_WriteDeltaField_Internal
==============
*/
bool MSG_WriteDeltaField_Internal(msg_t *a1, const SnapshotInfo_s *snapInfo, msg_t *msg, const int time, const unsigned __int8 *from, const unsigned __int8 *to, const NetField *field, const int fieldNum, const int *fromF, const int *toF)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
MSG_WriteDeltaField
==============
*/
/*bool MSG_WriteDeltaField@<al>(char *a1@<edi>, const SnapshotInfo_s *snapInfo, msg_t *msg, const int time, const unsigned __int8 *from, const unsigned __int8 *to, const NetField *field, const int fieldNum, const bool forceSend, const bool xorValue, const int lastChangedField, const int skippedFieldBits, const bool sendSkippedFields)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}*/

/*
==============
MSG_WriteDeltaFields
==============
*/
void MSG_WriteDeltaFields(const SnapshotInfo_s *snapInfo, msg_t *msg, const int time, const unsigned __int8 *from, const unsigned __int8 *to, const int force, int lastChanged, int numFields, const NetField *stateFields, const int skippedFieldBits, bool writeEntUnlinkBit)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
MSG_WriteEntityRemoval
==============
*/
void MSG_WriteEntityRemoval(SnapshotInfo_s *snapInfo, msg_t *msg, unsigned __int8 *from, int indexBits, bool changeBit)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
MSG_WriteEntityDeltaForEType
==============
*/
int MSG_WriteEntityDeltaForEType(SnapshotInfo_s *snapInfo, msg_t *msg, const int time, int eType, const entityState_s *from, const entityState_s *to, DeltaFlags flags)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
MSG_ShouldEntityFieldBeForcedSent
==============
*/
bool MSG_ShouldEntityFieldBeForcedSent(const SnapshotInfo_s *snapInfo, const NetField *field, const EntityFieldInfoFlags fromFlags, const EntityFieldInfoFlags toFlags)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
MSG_GetEntityFieldInfoFlags
==============
*/
void MSG_GetEntityFieldInfoFlags(const entityState_s *es, EntityFieldInfoFlags *flags)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
MSG_ShouldSendEntityField
==============
*/

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
}

/*
==============
MSG_WriteDeltaClient
==============
*/
void MSG_WriteDeltaClient(SnapshotInfo_s *snapInfo, msg_t *msg, const int time, const clientState_s *from, const clientState_s *to, int force)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
MSG_WriteDeltaActor
==============
*/
void MSG_WriteDeltaActor(SnapshotInfo_s *snapInfo, msg_t *msg, const int time, const actorState_s *from, const actorState_s *to, int force)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
MSG_WithinAllowedPredictionError
==============
*/
BOOL MSG_WithinAllowedPredictionError(float dist, const playerState_s *to)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
MSG_GetLastChangedField
==============
*/
int MSG_GetLastChangedField(const SnapshotInfo_s *snapInfo, const unsigned __int8 *from, const unsigned __int8 *to, int numFields, const NetField *stateFields)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
MSG_GetBitFieldIndex
==============
*/
unsigned int MSG_GetBitFieldIndex(unsigned int *fieldsChanged, const BitField *bitFields, bool *bMatch, int entNum)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
MSG_WriteDeltaPlayerstate
==============
*/

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
}

/*
==============
MSG_WriteDeltaMatchState
==============
*/

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
}

/*
==============
MSG_WriteDeltaHudElems_LastChangedField
==============
*/
int MSG_WriteDeltaHudElems_LastChangedField(SnapshotInfo_s *snapInfo, int i, const hudelem_s *from, const hudelem_s *to)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
MSG_WriteDeltaHudElems_ValidateHudElem
==============
*/
void MSG_WriteDeltaHudElems_ValidateHudElem(const hudelem_s *from, const hudelem_s *to)
{
	UNIMPLEMENTED(__FUNCTION__);
}

