#include "types.h"

/*
==============
R_HashAssetName
==============
*/
int R_HashAssetName(const char *name)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
R_HashString
==============
*/
unsigned int R_HashString(const char *string, unsigned int hash)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
R_AllocGlobalVariable
==============
*/
void *R_AllocGlobalVariable(unsigned int bytes, const char *name)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
R_FreeGlobalVariable
==============
*/
void R_FreeGlobalVariable(void *var)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_CullPointAndRadius
==============
*/
char R_CullPointAndRadius(const vec3_t *pt, float radius, const DpvsPlane *clipPlanes, int clipPlaneCount)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
R_ConvertColorToBytes
==============
*/
void R_ConvertColorToBytes()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FresnelTerm
==============
*/
double FresnelTerm(float n0, float n1, float cosIncidentAngle)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
R_GetClearColor
==============
*/
char R_GetClearColor(vec4_t *unpackedRgba)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
R_PickEntityBone
==============
*/
int R_PickEntityBone(unsigned int a1, int traceMask, const vec3_t *org, const vec3_t *dir, int boneIndex, const char **boneName)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

