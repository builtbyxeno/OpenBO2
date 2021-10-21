#include "types.h"
#include "vars.h"
#include <gfx_d3d/r_pix_profile.h>
#include <gfx_d3d/gfx_d3d_public.h>
#include <qcommon/qcommon_public.h>

GPUTimerDisplayMode s_displayMode;
GPUTimeStamp* s_firstFreeTimeStamp;
PerfTimerStyle s_gpuTimerStyle;
GPUTimerFrame s_timerFrames[64];

unsigned int LastGoodElapsed[40];
unsigned int LastGoodTime;

volatile unsigned int s_totalTime;

/*
==============
R_GPU_CalcDerivedTimers
==============
*/
void R_GPU_CalcDerivedTimers(GPUTimerFrame *timerFrame)
{
	GPUTimer* timers;
	unsigned int beginTime, totalTime;
	int i;

	totalTime = 0;
	beginTime = -1;
	timers = timerFrame->timers;

	for (i = 0; i < 40; ++i)
	{
		if (timers[i].isActive)
		{
			if (timers[i].beginTime < beginTime)
			{
				beginTime = timers[i].beginTime;
			}
			if (totalTime < timers[i].totalTime + timers[i].beginTime)
			{
				totalTime = timers[i].totalTime + timers[i].beginTime;
			}
		}
	}

	totalTime = timerFrame->timers[5].beginTime;
	totalTime -= beginTime;
	totalTime = timerFrame->timers[5].totalTime;
	timerFrame->beginTime = beginTime;
	timerFrame->timers[11].beginTime = timerFrame->timers[16].beginTime;
	totalTime = timerFrame->timers[9].totalTime + timerFrame->timers[10].totalTime;
	timerFrame->timers[2].beginTime = totalTime;
	totalTime += timerFrame->timers[8].totalTime;
	timerFrame->timers[27].beginTime = timerFrame->timers[28].beginTime;
	totalTime += timerFrame->timers[7].totalTime;
	totalTime = timerFrame->timers[6].totalTime;
	timerFrame->totalTime = totalTime;
	s_totalTime = totalTime;
	totalTime += totalTime;
	totalTime = timerFrame->timers[23].totalTime + timerFrame->timers[25].totalTime + timerFrame->timers[31].totalTime;
	timerFrame->timers[2].totalTime = totalTime + totalTime;
	totalTime += timerFrame->timers[21].totalTime + timerFrame->timers[22].totalTime;
	timerFrame->timers[3].totalTime = totalTime;
	totalTime += timerFrame->timers[19].totalTime;
	timerFrame->timers[4].totalTime = totalTime;
	totalTime += timerFrame->timers[16].totalTime + timerFrame->timers[17].totalTime + timerFrame->timers[18].totalTime;
	timerFrame->timers[27].totalTime = timerFrame->timers[28].totalTime;
	timerFrame->timers[11].totalTime = timerFrame->timers[12].totalTime + timerFrame->timers[13].totalTime + totalTime;

	if (s_displayMode == GPU_TIMER_DISPLAY_MODE_ACTIVE_IN_PLACE_SIMPLE)
	{
		totalTime = timerFrame->timers[35].totalTime + timerFrame->timers[38].totalTime;
		timerFrame->timers[39].beginTime = timerFrame->timers[35].beginTime;
		timerFrame->timers[39].totalTime = totalTime;
		timerFrame->timers[35].isActive = 0;
		timerFrame->timers[38].isActive = 0;
		timerFrame->timers[39].isActive = 1;
	}
}

/*
==============
R_GPU_CalcTimers
==============
*/
void R_GPU_CalcTimers(GPUTimerFrame *timerFrame)
{
	GPUTimer* timers;
	GPUTimeStamp* firstTimeStamp;
	unsigned __int64 beginTime;
	unsigned __int64 endTime;
	unsigned int frameEndTime;
	unsigned int frameBeginTime;
	D3D11_QUERY_DATA_TIMESTAMP_DISJOINT disjoint;
	int i, j;

	frameBeginTime = -1;
	frameEndTime = 0;
	Sys_EnterCriticalSection(CRITSECT_DXCONTEXT);
	timers = timerFrame->timers;
	for (i = 0; i < 40; ++i)
	{
		assert(!timers[i].currentTimeStamp);
		if (timers[i].firstTimeStamp)
		{
			for (firstTimeStamp = timers[i].firstTimeStamp; firstTimeStamp; firstTimeStamp = firstTimeStamp->next)
			{
				while (dx.context->GetData(firstTimeStamp->beginQuery, &beginTime, sizeof(__int64), 0))
					Sleep(0);
				while (dx.context->GetData(firstTimeStamp->endQuery, &endTime, sizeof(__int64), 0))
					Sleep(0);
				while (dx.context->GetData(firstTimeStamp->disjoint, &disjoint, sizeof(D3D11_QUERY_DATA_TIMESTAMP_DISJOINT), 0))
					Sleep(0);

				timers[i].beginTime = beginTime / (disjoint.Frequency / 0xF4240);
				timers[i].totalTime += ((endTime - beginTime) / (disjoint.Frequency / 0xF4240));
				s_firstFreeTimeStamp = firstTimeStamp;
			}
			LastGoodElapsed[i] = timers[i].totalTime;
			LastGoodTime = timers[i].beginTime;
		}
		else
		{
			timers[i].beginTime = LastGoodTime;
		}
		
		if (timers[i].beginTime < frameBeginTime)
		{
			frameBeginTime = timers[i].beginTime;
		}
		if (frameEndTime < (((timers[i].totalTime + timers[i].adjustTime) < 0 ? 0 : timers[i].totalTime + timers[i].adjustTime) + timers[i].beginTime))
		{
			frameEndTime = timers[i].beginTime;
		}
	}
	if (frameBeginTime > frameEndTime)
	{
		for (j = 40; j; --j)
		{
			timers[j].beginTime -= INT_MAX;
		}
	}
	Sys_LeaveCriticalSection(CRITSECT_DXCONTEXT);
}

/*
==============
R_GPU_FreeInterveningTimeStamps
==============
*/
void R_GPU_FreeInterveningTimeStamps(int lastReadIndex, int readIndex)
{
	int m_readIndex;
	GPUTimeStamp* m_firstFreeTimeStamp;
	GPUTimer* timer;
	GPUTimeStamp* next;
	int i, j;

	m_readIndex = readIndex;

	if (readIndex < lastReadIndex)
	{
		m_readIndex = readIndex + 64;
		readIndex += 64;
	}
	if (lastReadIndex + 1 < m_readIndex)
	{
		m_firstFreeTimeStamp = s_firstFreeTimeStamp;
		for (i = lastReadIndex + 1; i < readIndex; ++i)
		{
			for (j = 40; j; --j)
			{
				timer = &s_timerFrames[i % 64].timers[j];
				if (!timer->currentTimeStamp)
				{
					AssertMsg("(!timer->currentTimeStamp)");
					m_firstFreeTimeStamp = s_firstFreeTimeStamp;
				}

				m_firstFreeTimeStamp = s_timerFrames[i % 64].timers[j].firstTimeStamp;

				if (timer)
				{
					do
					{
						next = m_firstFreeTimeStamp->next;
						m_firstFreeTimeStamp->next = m_firstFreeTimeStamp;
						m_firstFreeTimeStamp = next;
					} while (next);
					s_firstFreeTimeStamp = m_firstFreeTimeStamp;
					timer = NULL;
				}
			}
		}
	}
}

int s_writeIndex;
int s_readIndex;
int s_callbackIndex;

/*
==============
R_GPU_EndFrameCallback
==============
*/
void R_GPU_EndFrameCallback()
{
	int i;

	s_readIndex = s_callbackIndex;
	s_callbackIndex = (s_callbackIndex + 1) % 64;

	for (i = 40; i; --i)
	{
		s_timerFrames[i].timers[0].totalTime = 0;
	}
}

unsigned int s_frameIndex;

/*
==============
R_GPU_BeginFrame
==============
*/
void R_GPU_BeginFrame()
{
	int i;

	s_displayMode = (GPUTimerDisplayMode)Dvar_GetInt(r_gpuTimers);

	if (s_displayMode)
	{
		s_timerFrames[s_writeIndex].frameIndex = s_frameIndex;
		assert(!s_timerFrames[s_writeIndex].isCurrent);

		s_timerFrames[s_writeIndex].isCurrent = 1;
		for (i = 40; i; --i)
		{
			s_timerFrames[s_writeIndex].timers[i].isActive = 0;
			s_timerFrames[s_writeIndex].timers[i].firstTimeStamp = NULL;
		}
		if (Dvar_GetBool(r_vsync))
		{
			Dvar_SetBool(r_vsync, false);
		}
	}
	else
	{
		s_frameIndex = 0;
	}
}

GPUTimer* s_currentTimer;

/*
==============
R_GPU_EndFrame
==============
*/
void R_GPU_EndFrame()
{
	GPUTimerFrame* timerFrame;
	unsigned int newIndex;

	if (s_displayMode)
	{
		assert(!s_currentTimer);

		timerFrame = &s_timerFrames[s_writeIndex];
		assert(timerFrame->isCurrent);

		newIndex = (s_writeIndex + 1) & 0x8000003F;
		timerFrame->isCurrent = 0;
		if (s_writeIndex + 1 < 0)
		{
			newIndex = (((s_writeIndex + 1) & 0x8000003F) - 1 | 0xFFFFFFC0) + 1;
		}
		s_writeIndex = newIndex;
		R_GPU_EndFrameCallback();
	}
}

/*
==============
R_GPU_BeginTimer
==============
*/
void R_GPU_BeginTimer(GPUTimerId timerId)
{
	GPUTimerFrame* timerFrame;
	GPUTimer* timer;
	GPUTimeStamp* newTimer;
	GPUTimeStamp* next;

	if (s_displayMode)
	{
		timerFrame = &s_timerFrames[s_writeIndex];

		assert(timerFrame->isCurrent);
		assertEq((timerId >= 0 && static_cast<uint>(timerId) < GPU_TIMER_COUNT));

		timer = &timerFrame->timers[timerId];
		if (s_currentTimer)
		{
			if (s_currentTimer != timer)
			{
				AssertMsg("(s_currentTimer != timer)");
			}
			s_currentTimer->hasChild = 1;
		}
		timer->parent = s_currentTimer;
		s_currentTimer = timer;
		timer->hasChild = 1;
		timer->bucket = 0;

		assertEq(s_firstFreeTimeStamp == 0);
		newTimer = s_firstFreeTimeStamp;
		next = s_firstFreeTimeStamp->next;
		s_firstFreeTimeStamp->next = NULL;
		newTimer->next = timer->firstTimeStamp;
		s_firstFreeTimeStamp = next;
		timer->firstTimeStamp = newTimer;
		timer->currentTimeStamp = newTimer;

		Sys_EnterCriticalSection(CRITSECT_DXCONTEXT);
		dx.context->Begin(newTimer->disjoint);
		dx.context->End(newTimer->beginQuery);
		Sys_LeaveCriticalSection(CRITSECT_DXCONTEXT);
	}
}

/*
==============
R_GPU_EndTimer
==============
*/
void R_GPU_EndTimer()
{
	GPUTimeStamp* currentTimeStamp;

	if (s_displayMode)
	{
		assert(s_currentTimer);
		assertEq(s_currentTimer->currentTimeStamp != s_currentTimer->firstTimeStamp);

		currentTimeStamp = s_currentTimer->currentTimeStamp;
		s_currentTimer->currentTimeStamp = NULL;

		Sys_EnterCriticalSection(CRITSECT_DXCONTEXT);
		dx.context->End(currentTimeStamp->endQuery);
		dx.context->End(currentTimeStamp->disjoint);
		Sys_LeaveCriticalSection(CRITSECT_DXCONTEXT);

		s_currentTimer = (GPUTimer*)s_currentTimer->parent;
	}
}

int s_lastReadIndex;
PerfTimerFrameHistory s_gpuTimerFrameHistory;

PerfTimerDisplayMode s_gpuPerfMode[14] =
{
  PERF_TIMER_MODE_UNKNOWN,
  PERF_TIMER_MODE_ACTIVE,
  PERF_TIMER_MODE_ACTIVE,
  PERF_TIMER_MODE_ALL,
  PERF_TIMER_MODE_TOP,
  PERF_TIMER_MODE_ALL,
  PERF_TIMER_MODE_ACTIVE,
  PERF_TIMER_MODE_MAJOR,
  PERF_TIMER_MODE_MINOR,
  PERF_TIMER_MODE_MAJOR,
  PERF_TIMER_MODE_MINOR,
  PERF_TIMER_MODE_ALL,
  PERF_TIMER_MODE_ACTIVE,
  PERF_TIMER_MODE_ACTIVE
};

PerfTimerDisplayType s_gpuPerfType[14] =
{
  PERF_TIMER_TYPE_UNKNOWN,
  PERF_TIMER_TYPE_IN_PLACE,
  PERF_TIMER_TYPE_IN_PLACE,
  PERF_TIMER_TYPE_IN_PLACE,
  PERF_TIMER_TYPE_STANDARD,
  PERF_TIMER_TYPE_STANDARD,
  PERF_TIMER_TYPE_STANDARD,
  PERF_TIMER_TYPE_STANDARD,
  PERF_TIMER_TYPE_STANDARD,
  PERF_TIMER_TYPE_IN_PLACE,
  PERF_TIMER_TYPE_IN_PLACE,
  PERF_TIMER_TYPE_COM_ONLY,
  PERF_TIMER_TYPE_COM_ONLY,
  PERF_TIMER_TYPE_COM_ONLY
};

/*
==============
R_GPU_DrawTimers
==============
*/
void R_GPU_DrawTimers()
{
	int m_readIndex;
	GPUTimerFrame* timer;
	unsigned int beginTime;
	unsigned int totalTime;

	int g_gpuTimerSimpleNamesMaxLength;
	int g_gpuTimerNamesMaxLength;

	const char* g_gpuTimerSimpleNames[40] =
	{
	  "UI3D",
	  "sonar",
	  "ShadowTotal",
	  "SunShadowTotal",
	  "SpotShadowTotal",
	  "Dynamic sun shadows",
	  "SunShadow1",
	  "Dynamic primary shadows",
	  "SpotShadow1",
	  "SpotShadow2",
	  "SpotShadow3",
	  "Mainpass Total",
	  "ClearScreen",
	  "View Model",
	  "DepthPrepass",
	  "ZCull Reload",
	  "Lit BSP Surfaces (In Dyn Shadow)",
	  "Lit Static Models (In Dyn Shadow)",
	  "Lit Other (In Dyn Shadow)",
	  "Lightmap",
	  "Emissive Opaque",
	  "LitQuasiOpaque (eg foliage)",
	  "ResolveScene",
	  "Scene Reflection (In Dyn Shadow)",
	  "Scene Reflection",
	  "Transparent",
	  "Sun Flare",
	  "Emissive Total",
	  "Particle FX",
	  "Transparent post FX",
	  "ViewModelFX",
	  "ViewModelTrans",
	  "Superflare",
	  "ExtraCam",
	  "FXAA",
	  "Bloom",
	  "Dof",
	  "Upscale",
	  "2D",
	  "Bloom,ADS,2D,HUD"
	};

	const char* g_gpuTimerNames[40] =
	{
	  "UI3D",
	  "sonar",
	  "ShadowTotal",
	  "SunShadowTotal",
	  "SpotShadowTotal",
	  "SunShadow0",
	  "SunShadow1",
	  "SpotShadow0",
	  "SpotShadow1",
	  "SpotShadow2",
	  "SpotShadow3",
	  "Mainpass Total",
	  "ClearScreen",
	  "Depth Hack",
	  "DepthPrepass",
	  "ZCull Reload",
	  "Lit BSP",
	  "Lit SModel",
	  "Lit",
	  "Lightmap",
	  "Emissive Opaque",
	  "LitQuasiOpaque",
	  "ResolveScene",
	  "LitPostResolve",
	  "LightmapPostResolve",
	  "Trans",
	  "Sun+corona",
	  "Emissive Total",
	  "Emissive FX",
	  "Trans post FX",
	  "ViewModelFX",
	  "ViewModelTrans",
	  "Superflare",
	  "ExtraCam",
	  "FXAA",
	  "Bloom",
	  "Dof",
	  "Upscale",
	  "2D",
	  "2D Toral"
	};

	if (s_displayMode)
	{
		PIXBeginNamedEvent(-1, "R_GPU_DrawTimers");
		m_readIndex = s_readIndex;
		R_GPU_FreeInterveningTimeStamps(s_lastReadIndex, s_readIndex);

		timer = &s_timerFrames[m_readIndex];
		s_lastReadIndex = m_readIndex;
		R_GPU_CalcTimers(timer);
		R_GPU_CalcDerivedTimers(timer);

		beginTime = timer->beginTime;
		totalTime = timer->totalTime;
		s_gpuTimerFrameHistory.currentFrame = m_readIndex;
		s_gpuTimerFrameHistory.frames[m_readIndex].beginTime = beginTime;
		s_gpuTimerFrameHistory.frames[s_gpuTimerFrameHistory.currentFrame].totalTime = totalTime;

		s_gpuTimerStyle.displayMode = s_gpuPerfMode[s_displayMode];
		s_gpuTimerStyle.displayType = s_gpuPerfType[s_displayMode];

		if (s_displayMode != GPU_TIMER_DISPLAY_MODE_COLLECT_ONLY)
		{
			if (!s_gpuTimerStyle.font)
			{
				R_GetFontPathFromName("consoleFont");
				s_gpuTimerStyle.font = R_RegisterFont();
				s_gpuTimerStyle.fontWidth = R_TextWidth(INVALID_LOCAL_CLIENT, "#", 1, s_gpuTimerStyle.font);
				s_gpuTimerStyle.fontHeight = R_TextHeight(s_gpuTimerStyle.font);
			}
			if (s_displayMode == GPU_TIMER_DISPLAY_MODE_ACTIVE_IN_PLACE_SIMPLE)
			{
				s_gpuTimerStyle.timerNameCharCount = g_gpuTimerSimpleNamesMaxLength;
				s_gpuTimerStyle.timerNames = g_gpuTimerSimpleNames;
			}
			else
			{
				s_gpuTimerStyle.timerNameCharCount = g_gpuTimerNamesMaxLength;
				s_gpuTimerStyle.timerNames = g_gpuTimerNames;
			}
			R_Perf_DrawTimers(&s_gpuTimerFrameHistory, &s_gpuTimerStyle);
		}
		if (Sys_IsRenderThread())
		{
			D3DPERF_EndEvent();
		}
	}
}

