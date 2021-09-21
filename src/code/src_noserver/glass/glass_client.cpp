#include "types.h"
#include "functions.h"

/*
==============
GlassesClient::Allocate
==============
*/
/*void *GlassesClient::Allocate(int size, int align, const char *file, int line)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}*/

/*
==============
GlassesClient::Free
==============
*/
/*void GlassesClient::Free(void *ptr)
{
	UNIMPLEMENTED(__FUNCTION__);
}*/

/*
==============
GlassesClient::GetFreeMem
==============
*/
/*unsigned int GlassesClient::GetFreeMem()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}*/

/*
==============
GlassesClient::GetGlass
==============
*/
/*GlassClient *__thiscall GlassesClient::GetGlass(GlassesClient *this, int idx)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}*/

/*
==============
GlassesClient::WriteDemoSnapshot
==============
*/
/*void __thiscall GlassesClient::WriteDemoSnapshot(GlassesClient *this, msg_t *msg)
{
	UNIMPLEMENTED(__FUNCTION__);
}*/

/*
==============
compareOutlineEdges
==============
*/
int compareOutlineEdges(const void *s1, const void *s2)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
GlassClient::PlayShatterFX
==============
*/
/*void __thiscall GlassClient::PlayShatterFX(GlassClient *this, LocalClientNum_t localClientNum, const vec3_t *hitPos, const vec3_t *hitDir)
{
	UNIMPLEMENTED(__FUNCTION__);
}*/

/*
==============
GlassIsVisible
==============
*/
bool GlassIsVisible(LocalClientNum_t localClientNum, const Glass *glass)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
GlassClient::SetBrushMaterial
==============
*/
/*void __thiscall GlassClient::SetBrushMaterial(GlassClient *this, GlassState::State state)
{
	UNIMPLEMENTED(__FUNCTION__);
}*/

/*
==============
GlassCl_WriteDemoSnapshot
==============
*/
void GlassCl_WriteDemoSnapshot(msg_t *msg)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
GlassCl_BeginGenerateVerts
==============
*/
void GlassCl_BeginGenerateVerts(LocalClientNum_t localClientNum, unsigned int viewIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
GlassCl_WaitUpdate
==============
*/
void GlassCl_WaitUpdate()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
GlassCl_GenerateVerts
==============
*/
void GlassCl_GenerateVerts(LocalClientNum_t localClientNum, unsigned int viewIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
GlassCl_ExplosionEvent
==============
*/
void GlassCl_ExplosionEvent(LocalClientNum_t localClientNum, const vec3_t *origin, const float damageInner, const float damageOuter, const float radius, int mod)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
GlassCl_MeleeEvent
==============
*/
void GlassCl_MeleeEvent(LocalClientNum_t localClientNum, int attackerEntNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
GlassCl_DrawDebug
==============
*/
void GlassCl_DrawDebug(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
GlassesClient::AreaGlasses
==============
*/
/*unsigned int __thiscall GlassesClient::AreaGlasses(GlassesClient *this, const vec3_t *mins, const vec3_t *maxs, const Glass **glss, unsigned int maxGlasses)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}*/

/*
==============
GlassesClient::ClipMoveTrace
==============
*/
/*void __thiscall GlassesClient::ClipMoveTrace(GlassesClient *this, const moveclip_t *clip, trace_t *results)
{
	UNIMPLEMENTED(__FUNCTION__);
}*/

/*
==============
GlassesClient::Update
==============
*/
/*void __thiscall GlassesClient::Update(GlassesClient *this, LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}*/

/*
==============
GlassClient::Init
==============
*/
/*void __thiscall GlassClient::Init(GlassClient *this, const Glass *gls)
{
	UNIMPLEMENTED(__FUNCTION__);
}*/

/*
==============
GlassClient::SetState
==============
*/
/*void __thiscall GlassClient::SetState(GlassClient *this, LocalClientNum_t localClientNum, GlassState::State newState, const vec3_t *hitPos, const vec3_t *hitDir, bool gameState)
{
	UNIMPLEMENTED(__FUNCTION__);
}*/

/*
==============
GlassClient::Outlines::InitShards
==============
*/
/*unsigned int __thiscall GlassClient::Outlines::InitShards(GlassClient::Outlines *this, const Glass *glass, GlassShard **shards, int maxNewShards)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}*/

/*
==============
GlassCl_Update
==============
*/
void GlassCl_Update(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
GlassesClient::TracePoint
==============
*/
/*void __thiscall GlassesClient::TracePoint(GlassesClient *this, const pointtrace_t *clip, trace_t *results)
{
	UNIMPLEMENTED(__FUNCTION__);
}*/

/*
==============
GlassCl_AreaGlasses
==============
*/
unsigned int GlassCl_AreaGlasses(const vec3_t *mins, const vec3_t *maxs, const Glass **glasses, unsigned int maxGlasses)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
GlassCl_ClipMoveTrace
==============
*/
void GlassCl_ClipMoveTrace(const moveclip_t *clip, trace_t *results)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
GlassesClient::GlassesClient
==============
*/
/*void __thiscall GlassesClient::GlassesClient(GlassesClient *this, const Glasses *glss)
{
	UNIMPLEMENTED(__FUNCTION__);
}*/

/*
==============
GlassesClient::Reset
==============
*/
/*void __thiscall GlassesClient::Reset(GlassesClient *this)
{
	UNIMPLEMENTED(__FUNCTION__);
}*/

/*
==============
GlassesClient::ParseSnapshot
==============
*/
/*void __thiscall GlassesClient::ParseSnapshot(GlassesClient *this, LocalClientNum_t localClientNum, msg_t *msg, bool gameState)
{
	UNIMPLEMENTED(__FUNCTION__);
}*/

/*
==============
GlassClient::Outlines::SaveOutlines
==============
*/
/*void __thiscall GlassClient::Outlines::SaveOutlines(GlassClient::Outlines *this, FixedSizeAllocator<TempPackedOutline> *newOutlines)
{
	UNIMPLEMENTED(__FUNCTION__);
}*/

/*
==============
GlassCl_AllocateMemory
==============
*/
void GlassCl_AllocateMemory()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
GlassCl_FreeMemory
==============
*/
void GlassCl_FreeMemory()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
GlassCl_Reset
==============
*/
void GlassCl_Reset(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
GlassCl_ReadGameState
==============
*/
void GlassCl_ReadGameState(LocalClientNum_t localClientNum, msg_t *msg)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
GlassCl_ParseSnapshot
==============
*/
void GlassCl_ParseSnapshot(LocalClientNum_t localClientNum, msg_t *msg)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
GlassCl_TracePoint
==============
*/
void GlassCl_TracePoint(const pointtrace_t *clip, trace_t *results)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
GlassClient::Shatter
==============
*/
/*char __thiscall GlassClient::Shatter(GlassClient *this, GlassShard **newShards, int *numNewShards)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}*/

/*
==============
GlassesClient::PreShatterNext
==============
*/
/*void __thiscall GlassesClient::PreShatterNext(GlassesClient *this)
{
	UNIMPLEMENTED(__FUNCTION__);
}*/

/*
==============
GlassClient::Shatter
==============
*/
/*void __thiscall GlassClient::Shatter(GlassClient *this, const vec3_t *pos, const vec3_t *dir)
{
	UNIMPLEMENTED(__FUNCTION__);
}*/

