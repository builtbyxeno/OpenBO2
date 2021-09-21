#include "types.h"
#include "functions.h"

/*
==============
RemoveDuplicateBrushPlanes
==============
*/
char RemoveDuplicateBrushPlanes(vec4_t *planes, unsigned int *sideCount, const char *mapname, unsigned int brushnum)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
SnapAxialVector
==============
*/
bool SnapAxialVector(vec3_t *normal)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
SnapPlane
==============
*/
void SnapPlane(vec4_t *plane)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
GetPlaneIntersections
==============
*/
unsigned int GetPlaneIntersections(const vec4_t *planes, unsigned int planeCount, SimplePlaneIntersection *OutPts, unsigned int maxPtCount)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Map_SkipNamedFlags
==============
*/
bool Map_SkipNamedFlags(const char **file, const char *key)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
GetCollisionMaterial
==============
*/
void GetCollisionMaterial(const char *name, collision_material_t *cmat)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
IsAxisAligned
==============
*/
int IsAxisAligned(vec3_t *normal)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Xmodel_ParsePhysicsBrush
==============
*/
bool Xmodel_ParsePhysicsBrush(const char **file, const char *mapname, unsigned int brushCount, PhysGeomInfo *geom, unsigned int boneHash, DObjAnimMat *boneMat, void *(*Alloc)(int))
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Xmodel_ParsePhysicsBox
==============
*/
bool Xmodel_ParsePhysicsBox(const char **file, PhysGeomInfo *geom)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Xmodel_ParsePhysicsCylinder
==============
*/
bool Xmodel_ParsePhysicsCylinder(const char **file, PhysGeomInfo *geom)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
SkipEpair
==============
*/
char SkipEpair(const char *token, const char **file)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
AddBoneName
==============
*/
bool AddBoneName(unsigned int *boneNameArray, const int boneNameLen, const char *boneName)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Xmodel_CountPhysicsCollMaps
==============
*/
int Xmodel_CountPhysicsCollMaps(const char *name, const char **file, unsigned int *boneHashes, const int boneNameLen)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Xmodel_CountPhysicsCollMapGeoms
==============
*/
unsigned int Xmodel_CountPhysicsCollMapGeoms(const char **file, const char *name, unsigned int boneHash)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Xmodel_ParsePhysicsCollMap
==============
*/
PhysGeomList *Xmodel_ParsePhysicsCollMap(DObjAnimMat *boneMat, void *(*Alloc)(int), const char **file, const char *name, unsigned int geomCount, unsigned int boneHash)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
XModel_LoadCollMap
==============
*/
void XModel_LoadCollMap(const char *name, void *(*Alloc)(int), XModel *model, const char *xmodelName)
{
	UNIMPLEMENTED(__FUNCTION__);
}

