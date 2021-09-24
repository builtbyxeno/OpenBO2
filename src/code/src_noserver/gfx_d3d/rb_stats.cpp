#include "types.h"

/*
==============
RB_Stats_GetStageName
==============
*/
const char *RB_Stats_GetStageName(GfxPrimStatsStage s)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
RB_Stats_GetTargetName
==============
*/
const char *RB_Stats_GetTargetName(GfxPrimStatsTarget t)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
RB_GetCounterSum
==============
*/
int RB_GetCounterSum(GfxPrimStatsCounters counter, GfxPrimStatsStage stageFrom, GfxPrimStatsStage stageTo, GfxPrimStatsTarget tgtFrom, GfxPrimStatsTarget tgtTo)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
RB_TrackStageBegin
==============
*/
void RB_TrackStageBegin(GfxFrameStats *stats, GfxPrimStatsStage stage)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
RB_TrackStageEnd
==============
*/
void RB_TrackStageEnd(GfxFrameStats *stats)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
RB_TrackPrimsBegin
==============
*/
void RB_TrackPrimsBegin(GfxFrameStats *stats, GfxPrimStatsTarget target)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
RB_TrackPrimsEnd
==============
*/
void RB_TrackPrimsEnd(GfxFrameStats *stats)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
RB_TrackDrawPrimCall
==============
*/
void RB_TrackDrawPrimCall(GfxFrameStats *stats, int triCount)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
RB_TrackDrawSurfMat
==============
*/
void RB_TrackDrawSurfMat(GfxFrameStats *stats, int surfCount, int matCount)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
RB_TrackDrawDynamic
==============
*/
void RB_TrackDrawDynamic(GfxFrameStats *stats, int dynamicIndexCount, int dynamicVertexCount)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
RB_TrackDrawStatic
==============
*/
void RB_TrackDrawStatic(GfxFrameStats *stats, int staticIndexCount, int staticVertexCount)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
RB_TrackGeoIndex
==============
*/
void RB_TrackGeoIndex(GfxFrameStats *stats, int geoIndexCount)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
RB_TrackFxIndex
==============
*/
void RB_TrackFxIndex(GfxFrameStats *stats, int fxIndexCount)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
RB_Stats_Accumulate
==============
*/
void RB_Stats_Accumulate(GfxFrameStats *dest, const GfxFrameStats *src)
{
	UNIMPLEMENTED(__FUNCTION__);
}

