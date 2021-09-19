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
void MSG_WriteReliableCommandToBuffer(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
MSG_WriteOriginFloat
==============
*/
void MSG_WriteOriginFloat(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
MSG_WriteOriginZFloat
==============
*/
void MSG_WriteOriginZFloat(
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
bool MSG_CompareRangedFloat(
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
bool MSG_ShouldSendPsViewAngles(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
MSG_ShouldSendPSField
==============
*/
bool MSG_ShouldSendPSField(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
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
int MSG_WriteRangedFloat(
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
void MSG_EncodeSkippedFields(
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
void MSG_WriteValue(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
MSG_WriteDeltaAngle
==============
*/
void MSG_WriteDeltaAngle(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
MSG_WriteDeltaField_Internal
==============
*/
/*bool MSG_WriteDeltaField_Internal@<al>(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}*/

/*
==============
MSG_WriteDeltaField
==============
*/
bool MSG_WriteDeltaField(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
MSG_WriteDeltaFields
==============
*/
void MSG_WriteDeltaFields(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
MSG_WriteEntityRemoval
==============
*/
void MSG_WriteEntityRemoval(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
MSG_WriteEntityDeltaForEType
==============
*/
int MSG_WriteEntityDeltaForEType(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
MSG_ShouldEntityFieldBeForcedSent
==============
*/
bool MSG_ShouldEntityFieldBeForcedSent(
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
/*char MSG_ShouldSendEntityField@<al>(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}*/

/*
==============
MSG_WriteDeltaClient
==============
*/
void MSG_WriteDeltaClient(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
MSG_WriteDeltaActor
==============
*/
void MSG_WriteDeltaActor(
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
int MSG_GetLastChangedField(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
MSG_GetBitFieldIndex
==============
*/
unsigned int MSG_GetBitFieldIndex(
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
int MSG_WriteDeltaHudElems_LastChangedField(
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

