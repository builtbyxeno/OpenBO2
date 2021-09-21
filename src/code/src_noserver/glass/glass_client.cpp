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
/*GlassClient *GlassesClient::GetGlass(GlassesClient *notthis, int idx)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}*/

/*
==============
GlassesClient::WriteDemoSnapshot
==============
*/
/*void GlassesClient::WriteDemoSnapshot(GlassesClient *notthis, msg_t *msg)
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
/*void GlassClient::PlayShatterFX(GlassClient *notthis, LocalClientNum_t localClientNum, const vec3_t *hitPos, const vec3_t *hitDir)
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
/*void GlassClient::SetBrushMaterial(GlassClient *notthis, GlassState::State state)
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
/*unsigned int GlassesClient::AreaGlasses(GlassesClient *notthis, const vec3_t *mins, const vec3_t *maxs, const Glass **glss, unsigned int maxGlasses)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}*/

/*
==============
GlassesClient::ClipMoveTrace
==============
*/
/*void GlassesClient::ClipMoveTrace(GlassesClient *notthis, const moveclip_t *clip, trace_t *results)
{
	UNIMPLEMENTED(__FUNCTION__);
}*/

/*
==============
GlassesClient::Update
==============
*/
/*void GlassesClient::Update(GlassesClient *notthis, LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}*/

/*
==============
GlassClient::Init
==============
*/
/*void GlassClient::Init(GlassClient *notthis, const Glass *gls)
{
	UNIMPLEMENTED(__FUNCTION__);
}*/

/*
==============
GlassClient::SetState
==============
*/
/*void GlassClient::SetState(GlassClient *notthis, LocalClientNum_t localClientNum, GlassState::State newState, const vec3_t *hitPos, const vec3_t *hitDir, bool gameState)
{
	UNIMPLEMENTED(__FUNCTION__);
}*/

/*
==============
GlassClient::Outlines::InitShards
==============
*/
/*unsigned int GlassClient::Outlines::InitShards(GlassClient::Outlines *notthis, const Glass *glass, GlassShard **shards, int maxNewShards)
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
/*void GlassesClient::TracePoint(GlassesClient *notthis, const pointtrace_t *clip, trace_t *results)
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
/*void GlassesClient::GlassesClient(GlassesClient *notthis, const Glasses *glss)
{
	UNIMPLEMENTED(__FUNCTION__);
}*/

/*
==============
GlassesClient::Reset
==============
*/
/*void GlassesClient::Reset(GlassesClient *notthis)
{
	UNIMPLEMENTED(__FUNCTION__);
}*/

/*
==============
GlassesClient::ParseSnapshot
==============
*/
/*void GlassesClient::ParseSnapshot(GlassesClient *notthis, LocalClientNum_t localClientNum, msg_t *msg, bool gameState)
{
	UNIMPLEMENTED(__FUNCTION__);
}*/

/*
==============
GlassClient::Outlines::SaveOutlines
==============
*/
/*void GlassClient::Outlines::SaveOutlines(GlassClient::Outlines *notthis, FixedSizeAllocator<TempPackedOutline> *newOutlines)
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
/*char GlassClient::Shatter(GlassClient *notthis, GlassShard **newShards, int *numNewShards)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}*/

/*
==============
GlassesClient::PreShatterNext
==============
*/
/*void GlassesClient::PreShatterNext(GlassesClient *notthis)
{
	UNIMPLEMENTED(__FUNCTION__);
}*/

/*
==============
GlassClient::Shatter
==============
*/
/*void GlassClient::Shatter(GlassClient *notthis, const vec3_t *pos, const vec3_t *dir)
{
	UNIMPLEMENTED(__FUNCTION__);
}*/

