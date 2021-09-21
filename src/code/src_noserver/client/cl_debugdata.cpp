#include "types.h"
#include "functions.h"

/*
==============
CL_DebugInitSVThreadVariables
==============
*/
void CL_DebugInitSVThreadVariables()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CreateDebugStringsIfNeeded
==============
*/
BOOL CreateDebugStringsIfNeeded()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
AddDebugStringInternal
==============
*/
void AddDebugStringInternal(const float* xyz, const float* color, float scale, const char* text, int duration, clientDebugStringInfo_t* info)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CL_AddDebugString
==============
*/
void CL_AddDebugString(const char *a1, int a2, const vec3_t *xyz, const vec4_t *color, float scale, const char *text, int duration)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CreateDebugSpheresIfNeeded
==============
*/
BOOL CreateDebugSpheresIfNeeded()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
AddDebugSphereInternal
==============
*/
void AddDebugSphereInternal(const float* center, const float radius, const float* color, int sideCount, int depthTest, int duration, clientDebugSphereInfo_t* info)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CL_AddDebugSphere
==============
*/
void CL_AddDebugSphere(int a1, const vec3_t *center, const float radius, const vec4_t *color, int sideCount, int depthTest, int duration)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CreateDebugLinesIfNeeded
==============
*/
BOOL CreateDebugLinesIfNeeded()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
AddDebugLineInternal
==============
*/
void AddDebugLineInternal(const vec3_t *start, const vec3_t *end, const vec4_t *color, int depthTest, int duration, clientDebugLineInfo_t *info)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CL_AddDebugLine
==============
*/
void CL_AddDebugLine(clientDebugLineInfo_t *a1, const vec3_t *start, const vec3_t *end, const vec4_t *color, int depthTest, int duration)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CL_AddDebugAxis
==============
*/
void CL_AddDebugAxis(clientDebugLineInfo_t *a1, clientDebugLineInfo_t *a2, clientDebugLineInfo_t *origin, const vec3_t *axis, const vec3_t *length, float doDepthTest, int duration, int a8)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CL_AddDebugStarWithText
==============
*/
void CL_AddDebugStarWithText(clientDebugLineInfo_t *a1, const vec3_t *point, const vec4_t *starColor, const vec4_t *textColor, const char *string, float fontsize, int duration)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CL_AddDebugStar
==============
*/
void CL_AddDebugStar(clientDebugLineInfo_t *a1, const vec3_t *point, const vec4_t *color, int duration)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CL_AddDebugBox
==============
*/
void CL_AddDebugBox(const vec3_t *origin, const vec3_t *mins, const vec3_t *maxs, float yaw, const vec4_t *color, int depthTest, int duration)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FlushDebugStrings
==============
*/
void FlushDebugStrings(clientDebugStringInfo_t *info, int fromServer)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FlushDebugLines
==============
*/
void FlushDebugLines(clientDebugLineInfo_t *info, int fromServer)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FlushDebugSpheres
==============
*/
void FlushDebugSpheres(clientDebugSphereInfo_t *info, int fromServer)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CL_FlushDebugClientData
==============
*/
void CL_FlushDebugClientData(clientDebugStringInfo_t *a1, int a2)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CL_UpdateDebugClientData
==============
*/
void CL_UpdateDebugClientData()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CL_FlushDebugServerData
==============
*/
void CL_FlushDebugServerData(clientDebugStringInfo_t *a1, int a2)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CL_UpdateDebugServerData
==============
*/
void CL_UpdateDebugServerData()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CL_ShutdownDebugData
==============
*/
void CL_ShutdownDebugData()
{
	UNIMPLEMENTED(__FUNCTION__);
}

