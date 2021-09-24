#include "types.h"

/*
==============
G_EntLinkToUpdateOffset
==============
*/
int G_EntLinkToUpdateOffset(gentity_t *ent, const vec3_t *originOffset, const vec3_t *anglesOffset)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
G_EntIsLinked
==============
*/
BOOL G_EntIsLinked(gentity_t *ent)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
G_EntIsLinkedTo
==============
*/
BOOL G_EntIsLinkedTo(gentity_t *ent, gentity_t *parent)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
G_UpdateTagInfoOfChildren
==============
*/
void G_UpdateTagInfoOfChildren(gentity_t *parent, int bHasDObj)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
G_CalcTagParentAxis
==============
*/
void G_CalcTagParentAxis(gentity_t *ent, vec3_t *parentAxis)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
G_CalcTagParentRelAxis
==============
*/
void G_CalcTagParentRelAxis(gentity_t *ent, vec3_t *parentRelAxis)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
G_CalcTagAxis
==============
*/
void G_CalcTagAxis(gentity_t *ent, int bAnglesOnly)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
G_CalcFixedLinkTargetAxis
==============
*/
void G_CalcFixedLinkTargetAxis(gentity_t *ent, vec3_t *axis)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
G_SetFixedLinkNonPlayer
==============
*/
int G_SetFixedLinkNonPlayer(gentity_t *ent, const int eAngles, const int contentMask, vec3_t *outTargetOrigin)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
G_DefaultViewAngleClampGoal
==============
*/
void G_DefaultViewAngleClampGoal(viewClampState *clamp)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
G_SnapToViewAngleClampGoal
==============
*/
void G_SnapToViewAngleClampGoal(viewClampState *clamp)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CalcLerpFraction
==============
*/
__int64 CalcLerpFraction(float startTime, __int64 a2, float a3, float a4)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
G_UpdateViewAngleClamp
==============
*/
void G_UpdateViewAngleClamp(gclient_t *,vec3_t const &)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
G_InitPlayerLinkAngles
==============
*/
void G_InitPlayerLinkAngles(gentity_t *ent)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
G_GeneralLink
==============
*/
void G_GeneralLink(gentity_t *ent)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SetPlayerVehicleLinkViewAngles
==============
*/
bool SetPlayerVehicleLinkViewAngles(gentity_t *ent)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
SetPlayerFixedLinkViewAngles
==============
*/
void SetPlayerFixedLinkViewAngles(gentity_t *ent, const vec3_t *worldAxis, float lerpFraction)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SetPlayerFixedLinkOrigin
==============
*/
void SetPlayerFixedLinkOrigin(gentity_t *ent, const vec3_t *worldAxis, float lerpFraction)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
G_SetFixedLinkPlayer
==============
*/
void G_SetFixedLinkPlayer(char *a1, gentity_t *ent)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
G_TransferLinkedEntities
==============
*/
void G_TransferLinkedEntities(gentity_t *from, gentity_t *to)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
G_ShouldClientLinkTo
==============
*/
char G_ShouldClientLinkTo()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
EntUnlink_Internal
==============
*/
void EntUnlink_Internal(gentity_t *ent)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
EntLinkTo_Internal
==============
*/
int EntLinkTo_Internal(gentity_t *ent, gentity_t *parent, unsigned int tagName)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
G_EntLinkTo
==============
*/
int __cdecl G_EntLinkTo(gentity_t *ent, gentity_t *parent, unsigned int tagName)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
G_EntLinkToWithOffset
==============
*/
int __cdecl G_EntLinkToWithOffset(gentity_t *ent, gentity_t *parent, unsigned int tagName, const vec3_t *originOffset, const vec3_t *anglesOffset)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
G_EntUnlink
==============
*/
void G_EntUnlink(gentity_t *ent)
{
	UNIMPLEMENTED(__FUNCTION__);
}

