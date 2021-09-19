#include "types.h"
#include "functions.h"

/*
==============
BG_GetPlayerAnimScriptFileName
==============
*/
const char *BG_GetPlayerAnimScriptFileName()
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
TRACK_bg_animation_mp
==============
*/
void TRACK_bg_animation_mp()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BG_StringHashValue
==============
*/
int BG_StringHashValue(const char *fname)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_AnimParseError
==============
*/
void BG_AnimParseError(const char *msg, ...)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BG_AnimationIndexForString
==============
*/
unsigned int BG_AnimationIndexForString(const char *string)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_IndexForString
==============
*/
int BG_IndexForString(const char *token, animStringItem_t *strings, int allowFail)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_CopyStringIntoBuffer
==============
*/
char *BG_CopyStringIntoBuffer(const char *string, char *buffer, unsigned int bufSize, unsigned int *offset)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
BG_InitWeaponString
==============
*/
void BG_InitWeaponString(int index, const char *name)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BG_InitWeaponStrings
==============
*/
void BG_InitWeaponStrings()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BG_AddVehicleName
==============
*/
void BG_AddVehicleName(const char *vehName, int vehType, int drivers, int gunners, int passengers)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BG_AnimGetConditionValue
==============
*/
unsigned int BG_AnimGetConditionValue(animScriptItem_t *scriptItem, int conditionIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_GetVehicleAnimSetIndex
==============
*/
int BG_GetVehicleAnimSetIndex(unsigned __int16 animSetStr)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_SetupAnimNoteTypes
==============
*/
void BG_SetupAnimNoteTypes(animScriptData_t *scriptData)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BG_SetAnimConditionFlags
==============
*/
void BG_SetAnimConditionFlags(int condIndex, unsigned int result)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BG_ParseConditionBits
==============
*/
void BG_ParseConditionBits(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BG_ParseConditions
==============
*/
int BG_ParseConditions(const char **text_pp, animScriptItem_t *scriptItem)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_ParseCommands
==============
*/
void BG_ParseCommands(const char **input, animScriptItem_t *scriptItem, animScriptData_t *scriptData)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
GetWeaponTypeName
==============
*/
const char *GetWeaponTypeName(int type)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
GetValueForBitfield
==============
*/
int GetValueForBitfield(unsigned int bitfield)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_GetConditionString
==============
*/
const char *BG_GetConditionString(int condition, int value)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
BG_EvaluateConditions
==============
*/
int BG_EvaluateConditions(clientInfo_t *ci, animScriptItem_t *scriptItem)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_FirstValidItem
==============
*/
animScriptItem_t *BG_FirstValidItem(int client, animScript_t *script)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
BG_AnimScriptEventGetCommand
==============
*/
animScriptCommand_t *BG_AnimScriptEventGetCommand(
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
BG_SetConditionBit
==============
*/
void BG_SetConditionBit(ClientNum_t client, int condition, int value)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BG_GetConditionValue
==============
*/
unsigned int BG_GetConditionValue(const clientInfo_t *ci, const int condition)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_GetConditionBit
==============
*/
int BG_GetConditionBit(const clientInfo_t *ci, const int condition)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_GetPlayerStateWeapon
==============
*/
Weapon BG_GetPlayerStateWeapon(const pmove_t *pm)
{
	UNIMPLEMENTED(__FUNCTION__);
	Weapon tmp;
	return tmp;
}

/*
==============
BG_GetNextPlayerStateWeapon
==============
*/
Weapon BG_GetNextPlayerStateWeapon(const pmove_t *pm)
{
	UNIMPLEMENTED(__FUNCTION__);
	Weapon tmp;
	return tmp;
}

/*
==============
BG_AnimUpdatePlayerStateConditions
==============
*/
void BG_AnimUpdatePlayerStateConditions(pmove_t *pmove)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BG_IsCrouchingAnim
==============
*/
int BG_IsCrouchingAnim(const clientInfo_t *ci, int animNum)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_IsProneAnim
==============
*/
int BG_IsProneAnim(const clientInfo_t *ci, int animNum)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_IsKnifeMeleeAnim
==============
*/
int BG_IsKnifeMeleeAnim(const clientInfo_t *ci, int animNum)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_IsSliding
==============
*/
BOOL BG_IsSliding(const clientInfo_t *ci)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_SetNewAnimation
==============
*/
void BG_SetNewAnimation(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BG_RunLerpFrameRate
==============
*/
void BG_RunLerpFrameRate(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BG_PlayerAnimation_VerifyAnim
==============
*/
void BG_PlayerAnimation_VerifyAnim(XAnimTree_s *pAnimTree, lerpFrame_t *lf)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BG_SwingAngles
==============
*/
void BG_SwingAngles(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BG_PlayerAngles
==============
*/
void BG_PlayerAngles(LocalClientNum_t localClientNum, const entityState_s *es, clientInfo_t *ci)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BG_Player_DoControllersInternal
==============
*/
void BG_Player_DoControllersInternal(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BG_Player_DoControllersSetup
==============
*/
void BG_Player_DoControllersSetup(const entityState_s *es, clientInfo_t *ci, int frametime)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BG_PlayerAnimation
==============
*/
void BG_PlayerAnimation(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BG_UpdatePlayerDObj
==============
*/
void BG_UpdatePlayerDObj(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BG_FindAnims
==============
*/
void BG_FindAnims()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BG_FindAnimTree
==============
*/
scr_animtree_t BG_FindAnimTree(const char *filename, int bEnforceExists)
{
	UNIMPLEMENTED(__FUNCTION__);
	scr_animtree_t tmp;
	return tmp;
}

/*
==============
BG_FindAnimTrees
==============
*/
void BG_FindAnimTrees()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BG_ResetAnimSpeeds
==============
*/
void BG_ResetAnimSpeeds()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BG_SetSAnimSpeed
==============
*/
void BG_SetSAnimSpeed(int handle, float rate)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BG_GetSAnimSpeed
==============
*/
double BG_GetSAnimSpeed(int handle)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_SetCAnimSpeed
==============
*/
void BG_SetCAnimSpeed(int handle, float rate)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BG_GetCAnimSpeed
==============
*/
double BG_GetCAnimSpeed(int handle)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_AnimParseAnimScript
==============
*/
void BG_AnimParseAnimScript(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BG_GetCurrentMoveStatus
==============
*/
const char *BG_GetCurrentMoveStatus(playerState_s *ps)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
BG_PlayAnim
==============
*/
int BG_PlayAnim(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_ExecuteCommand
==============
*/
int BG_ExecuteCommand(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_AnimScriptAnimation
==============
*/
int BG_AnimScriptAnimation(pmove_t *pm, aistateEnum_t state, scriptAnimMoveTypes_t movetype, int force)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_AnimScriptEvent
==============
*/
int BG_AnimScriptEvent(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_SetConditionValue
==============
*/
void BG_SetConditionValue(ClientNum_t client, int condition, unsigned __int64 value)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BG_AddWorldModelWeaponAttachments
==============
*/
unsigned __int16 BG_AddWorldModelWeaponAttachments(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_AttachWeaponStowedModel
==============
*/
unsigned __int16 BG_AttachWeaponStowedModel(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_LoadAnim
==============
*/
void BG_LoadAnim(const char *levelName, bool canModifyChecksum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BG_FinalizePlayerAnims
==============
*/
void BG_FinalizePlayerAnims(const char *levelName)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BG_PostLoadAnim
==============
*/
void BG_PostLoadAnim(const char *levelName)
{
	UNIMPLEMENTED(__FUNCTION__);
}

