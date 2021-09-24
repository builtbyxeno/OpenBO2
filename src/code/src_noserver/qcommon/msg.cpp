#include "types.h"

/*
==============
MSG_GetMapCenter
==============
*/
vec3_t *__cdecl MSG_GetMapCenter()
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
GetMinBitCountForNum
==============
*/
int GetMinBitCountForNum(const unsigned int num)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
MSG_BeginReading
==============
*/
void MSG_BeginReading(msg_t *msg)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
MSG_Discard
==============
*/
void MSG_Discard(msg_t *msg)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
MSG_GetBytes
==============
*/
void MSG_GetBytes(msg_t *msg, int where, unsigned __int8 *dest, int len)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
MSG_GetUsedBitCount
==============
*/
int MSG_GetUsedBitCount(const msg_t *msg)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
MSG_GetNumBitsRead
==============
*/
int MSG_GetNumBitsRead(const msg_t *msg)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
MSG_SetBookmark
==============
*/
void MSG_SetBookmark(const msg_t *msg, msg_bookmark_t *bookmark)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
MSG_GotoBookmark
==============
*/
void MSG_GotoBookmark(msg_t *msg, const msg_bookmark_t *bookmark)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
MSG_ReadBit
==============
*/
int MSG_ReadBit(msg_t *msg)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
showHuffmanData
==============
*/
void showHuffmanData()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
MSG_RecordHuffmanDistribution
==============
*/
void MSG_RecordHuffmanDistribution()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
MSG_ReadBitsCompress
==============
*/
int MSG_ReadBitsCompress(const unsigned __int8 *from, int fromSizeBytes, unsigned __int8 *to, int toSizeBytes)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
MSG_Embed
==============
*/
void MSG_Embed(msg_t *dest, msg_t *src)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
MSG_UnEmbed
==============
*/
void MSG_UnEmbed(msg_t *msg)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
MSG_WriteByte
==============
*/
void MSG_WriteByte(msg_t *msg, int c)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
MSG_WriteData
==============
*/
void MSG_WriteData(msg_t *buf, const void *data, int length)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
MSG_WriteFloat
==============
*/
void MSG_WriteFloat(msg_t *msg, float f)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
MSG_WriteAngle
==============
*/
void MSG_WriteAngle(msg_t *sb, int bits, float f)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
MSG_WriteAngle16
==============
*/
void MSG_WriteAngle16(msg_t *sb, float f)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
MSG_WriteRangedFloatBits
==============
*/
void MSG_WriteRangedFloatBits(msg_t *sb, float f, float begin, float end, int bits)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
MSG_WriteRiceGolomb
==============
*/
void MSG_WriteRiceGolomb(msg_t *sb, unsigned int c, int mbits)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
MSG_WriteExpGolomb0
==============
*/
void MSG_WriteExpGolomb0(msg_t *sb, unsigned int q)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
MSG_WriteSignedExpGolomb0
==============
*/
void MSG_WriteSignedExpGolomb0(msg_t *sb, int c)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
MSG_WriteSignedExpGolomb
==============
*/
void MSG_WriteSignedExpGolomb(msg_t *sb, int c, int kbits)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
MSG_WriteSignedNonZeroExpGolomb0
==============
*/
void MSG_WriteSignedNonZeroExpGolomb0(msg_t *sb, int c)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
MSG_WriteSignedNonZeroExpGolomb
==============
*/
void MSG_WriteSignedNonZeroExpGolomb(msg_t *sb, int c, int kbits)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
MSG_WriteBits64
==============
*/
void MSG_WriteBits64(msg_t *msg, __int64 value, int bits)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
MSG_WriteInt64
==============
*/
void MSG_WriteInt64(msg_t *msg, unsigned __int64 c)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
MSG_WriteString
==============
*/
void MSG_WriteString(msg_t *sb, const char *s)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
MSG_WriteBigString
==============
*/
void MSG_WriteBigString(msg_t *sb, const char *s)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
MSG_ReadByte
==============
*/
int MSG_ReadByte(msg_t *msg)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
MSG_ReadShort
==============
*/
int MSG_ReadShort(msg_t *msg)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
MSG_ReadLong
==============
*/
int MSG_ReadLong(msg_t *msg)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
MSG_ReadInt64
==============
*/
unsigned __int64 MSG_ReadInt64(msg_t *msg)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
MSG_ReadFloat
==============
*/
double MSG_ReadFloat(msg_t *msg)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
MSG_ReadString
==============
*/
char *MSG_ReadString(msg_t *msg, char *string, unsigned int maxChars)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
MSG_ReadBigString
==============
*/
char *MSG_ReadBigString(msg_t *msg)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
MSG_ReadStringLine
==============
*/
char *MSG_ReadStringLine(msg_t *msg, char *string, unsigned int maxChars)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
MSG_ReadAngle
==============
*/
double MSG_ReadAngle(msg_t *msg, int bits)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
MSG_ReadAngle16
==============
*/
double MSG_ReadAngle16(msg_t *msg)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
MSG_ReadRangedFloatBits
==============
*/
double MSG_ReadRangedFloatBits(msg_t *sb, float begin, float end, int bits)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
MSG_ReadRiceGolomb
==============
*/
int MSG_ReadRiceGolomb(msg_t *msg, int mbits)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
MSG_ReadExpGolomb0
==============
*/
int MSG_ReadExpGolomb0(msg_t *msg)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
MSG_ReadSignedExpGolomb0
==============
*/
int MSG_ReadSignedExpGolomb0(msg_t *msg)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
MSG_ReadSignedNonZeroExpGolomb
==============
*/
int MSG_ReadSignedNonZeroExpGolomb(msg_t *msg, int kbits)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
MSG_ReadSignedNonZeroExpGolomb0
==============
*/
int MSG_ReadSignedNonZeroExpGolomb0(msg_t *msg)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
MSG_ReadBits64
==============
*/
int MSG_ReadBits64(msg_t *msg, int bits)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
MSG_ReadData
==============
*/
void MSG_ReadData(msg_t *msg, void *data, int len)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
MSG_WriteDeltaKey
==============
*/
void MSG_WriteDeltaKey(msg_t *msg, int key, int oldV, int newV, int bits)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
MSG_ReadDeltaKey
==============
*/
int MSG_ReadDeltaKey(msg_t *msg, int key, int oldV, int bits)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
MSG_WriteKey
==============
*/
void MSG_WriteKey(msg_t *msg, int key, int newV, int bits)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
MSG_ReadKey
==============
*/
unsigned int MSG_ReadKey(msg_t *msg, int key, int bits)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
MSG_WriteDeltaKeyByte
==============
*/
void MSG_WriteDeltaKeyByte(msg_t *msg, int key, int oldV, int newV)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
MSG_ReadDeltaKeyByte
==============
*/
int MSG_ReadDeltaKeyByte(msg_t *msg, int key, int oldV)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
MSG_WriteDeltaKeyShort
==============
*/
void MSG_WriteDeltaKeyShort(msg_t *msg, int key, int oldV, int newV)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
MSG_ReadDeltaKeyShort
==============
*/
int MSG_ReadDeltaKeyShort(msg_t *msg, int key, int oldV)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
MSG_ReadDeltaTime
==============
*/
int MSG_ReadDeltaTime(msg_t *msg, int timeBase)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
MSG_ReadDeltaEventField
==============
*/
int MSG_ReadDeltaEventField(msg_t *msg)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
MSG_ReadDeltaEventParamField
==============
*/
int MSG_ReadDeltaEventParamField(msg_t *msg)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
MSG_ReadEFlags
==============
*/
int MSG_ReadEFlags(msg_t *msg, const int oldFlags)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
MSG_ReadOriginFloat
==============
*/
double MSG_ReadOriginFloat(int bits, msg_t *msg, float oldValue)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
MSG_ReadOriginZFloat
==============
*/
double MSG_ReadOriginZFloat(msg_t *msg, float oldValue)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
MSG_ReadRangedFloat
==============
*/
double MSG_ReadRangedFloat(msg_t *msg, const float oldValue, const float begin, const float end, const int precision, const bool oftenZeroOrOne)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
MSG_ReadEntityIndex
==============
*/
int MSG_ReadEntityIndex(msg_t *msg, int indexBits)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
MSG_InitHuffman
==============
*/
void MSG_InitHuffman()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
MSG_ReadValueNoXor
==============
*/
int MSG_ReadValueNoXor(msg_t *msg, const int bits)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
MSG_ReadValue
==============
*/
int MSG_ReadValue(msg_t *msg, const int *fromF, int *toF, const int bits, const int size)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
MSG_ReadDeltaAngle
==============
*/
double MSG_ReadDeltaAngle(msg_t *msg, const float oldFloat)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
MSG_ReadLastChangedField
==============
*/
int MSG_ReadLastChangedField(msg_t *msg, int totalFields)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
MSG_ReadNumFieldsSkipped
==============
*/
int MSG_ReadNumFieldsSkipped(msg_t *msg, const int skippedFieldBits, const int maxVal)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
MSG_CopyFieldOver
==============
*/
void MSG_CopyFieldOver(const NetField *stateFields, const void *from, void *to, const int fieldNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
MSG_ReadDeltaFields
==============
*/
void MSG_ReadDeltaFields(msg_t *msg, const int time, const void *from, void *to, int numFields, const NetField *stateFields, const int skippedFieldBits)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
MSG_ReadDeltaStruct
==============
*/
int MSG_ReadDeltaStruct(msg_t *msg, const int time, const void *from, void *to, unsigned int number, int numFields, int indexBits, const NetField *stateFields, const int skippedFieldBits)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
MSG_ReadDeltaMatchState
==============
*/
void MSG_ReadDeltaMatchState(int a1, msg_t *msg, const int time, const MatchState *remoteFrom, const MatchState *remoteTo)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
MSG_ReadDeltaClient
==============
*/
int MSG_ReadDeltaClient(msg_t *msg, const int time, const clientState_s *remoteFrom, clientState_s *remoteTo, int number)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
MSG_ReadDeltaActor
==============
*/
int MSG_ReadDeltaActor(msg_t *msg, const int time, const actorState_s *remoteFrom, actorState_s *remoteTo, int number)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
MSG_ReadDeltaEntity
==============
*/
int MSG_ReadDeltaEntity(msg_t *msg, const int time, const entityState_s *from, entityState_s *to, int number, const ClientNum_t clientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
MSG_Init
==============
*/
void MSG_Init(msg_t *buf, unsigned __int8 *data, int length)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
MSG_InitReadOnly
==============
*/
void MSG_InitReadOnly(msg_t *buf, unsigned __int8 *data, int length)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
MSG_InitReadOnlySplit
==============
*/
void MSG_InitReadOnlySplit(msg_t *buf, unsigned __int8 *data, int length, unsigned __int8 *data2, int length2)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
MSG_SetDefaultUserCmd
==============
*/
void MSG_SetDefaultUserCmd(playerState_s *ps, usercmd_s *cmd)
{
	UNIMPLEMENTED(__FUNCTION__);
}

