#include "types.h"
#include "functions.h"

/*
==============
Rope_IsValid
==============
*/
BOOL Rope_IsValid(int rope_index)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Rope_Activate
==============
*/
void Rope_Activate(int rope_index)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Rope_SetFlag
==============
*/
void Rope_SetFlag(int rope_index, int flags, int onoff)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Rope_Reset
==============
*/
void Rope_Reset(int rope_index)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Rope_Reset
==============
*/
void Rope_Reset()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Rope_SetMaterial
==============
*/
void Rope_SetMaterial(int rope_index, Material *const material)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Rope_GetNumParticles
==============
*/
int Rope_GetNumParticles(int rope_index)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Rope_AddParticle
==============
*/
void Rope_AddParticle(int rope_index, const vec3_t *pos)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Rope_Init
==============
*/
void Rope_Init(int rope_index, int npars, const vec3_t *p0, const vec3_t *p1, float rope_len, float rope_width, float scale, float force_scale, int static_rope)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Rope_AddAnchor
==============
*/
void Rope_AddAnchor(int rope_index, int particle_index, const vec3_t *p, int entity_index, int bone_name_hash, rope_constraint_e type)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Rope_AddDynEntAnchor
==============
*/
void Rope_AddDynEntAnchor(int rope_index, int particle_index, const vec3_t *p, int entity_index)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Rope_AddEntAnchor
==============
*/
void Rope_AddEntAnchor(int rope_index, int particle_index, const vec3_t *p, int entity_index, int bone_name_hash)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Rope_RemoveAnchor
==============
*/
void Rope_RemoveAnchor(int rope_index, int particle_index)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Rope_ApplyPhysics
==============
*/
void Rope_ApplyPhysics(int rope_index, float dt)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Rope_ApplyContactConstraint
==============
*/
void Rope_ApplyContactConstraint(int rope_index, int contact_index)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Rope_ApplyConstraint
==============
*/
void Rope_ApplyConstraint(int rope_index, int constraint_index)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Rope_ApplyConstraints
==============
*/
void Rope_ApplyConstraints(int a1, int rope_index, bool forward)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Rope_UpdateVisible
==============
*/
void Rope_UpdateVisible(int rope_index)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Rope_DebugDraw
==============
*/
void Rope_DebugDraw(int rope_index)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Rope_GetPosition
==============
*/
void Rope_GetPosition(int rope_index, float frac, vec3_t *pos)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Rope_BuildCurve
==============
*/
void Rope_BuildCurve(const RopeUpdateCmdData *cmd, int rope_index)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Rope_Draw
==============
*/
void Rope_Draw(int rope_index, LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Rope_Create
==============
*/

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
}

/*
==============
Rope_Render
==============
*/
void Rope_Render(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Rope_ExplosionEvent
==============
*/
void Rope_ExplosionEvent(const vec3_t *origin, float innerRadius, float outerRadius, int innerDamage, int outerDamage)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Rope_Trace
==============
*/
void Rope_Trace(const vec3_t *p0, const vec3_t *p1)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Rope_CollideEntitiesHelper
==============
*/
void Rope_CollideEntitiesHelper(int rope_index, const vec3_t *origin)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Rope_CollideEntities
==============
*/
void Rope_CollideEntities(int rope_index)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Rope_CollideWorld
==============
*/

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
}

/*
==============
Rope_UpdateInternal
==============
*/
/*void Rope_UpdateInternal(const char *a1@<edi>, const RopeUpdateCmdData *cmd)
{
	UNIMPLEMENTED(__FUNCTION__);
}*/

/*
==============
Rope_Update
==============
*/
void Rope_Update(unsigned int a1, LocalClientNum_t localClientNum, int curtime)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Rope_Settle
==============
*/
/*void Rope_Settle(const char *a1@<esi>, int rope_index)
{
	UNIMPLEMENTED(__FUNCTION__);
}*/

