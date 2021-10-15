#include "types.h"
#include "vars.h"
#include <gfx_d3d/gfx_d3d_public.h>
#include <qcommon/qcommon_public.h>

int g_destroy_window;

/*
==============
TRACK_r_init
==============
*/
void TRACK_r_init()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_ErrorDescription
==============
*/
const char *R_ErrorDescription(int hr)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
R_IsNullRenderer
==============
*/
bool __cdecl R_IsNullRenderer(LocalClientNum_t a1)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
R_GetFontPathFromName
==============
*/
char *R_GetFontPathFromName(const char *fontName)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
R_SetBrightness
==============
*/
void R_SetBrightness(float brightness)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_SetColorMappings
==============
*/
void R_SetColorMappings()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_GammaCorrect
==============
*/
void R_GammaCorrect(unsigned __int8 *buffer, int bufSize)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SetGfxConfig
==============
*/
void SetGfxConfig(const GfxConfiguration *config)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_MakeDedicated
==============
*/
void R_MakeDedicated(const GfxConfiguration *notthis)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_SetVidRestart
==============
*/
void R_SetVidRestart()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_AllocateMinimalResources
==============
*/
void R_AllocateMinimalResources()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_SetIsMultiplayer
==============
*/
void R_SetIsMultiplayer(bool isMp)
{
	r_glob.isMultiplayer = isMp;
}

/*
==============
R_SetIsZombie
==============
*/
void R_SetIsZombie(bool isZM)
{
	r_glob.isZombie = isZM;
}

/*
==============
R_ShutdownStreams
==============
*/
void R_ShutdownStreams()
{
	if (dx.device)
		R_ClearAllStreamSources(&gfxCmdBufState.prim);
}

/*
==============
R_Shutdown
==============
*/
void R_Shutdown(int destroyWindow)
{
	g_destroy_window = destroyWindow;
	Sys_SetD3DShutdownEvent();
	while (Sys_QueryD3DShutdownEvent())
		NET_Sleep(0);
}

/*
==============
R_UnloadWorld
==============
*/
void R_UnloadWorld()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_BeginRegistration
==============
*/
void R_BeginRegistration(vidConfig_t *vidConfigOut)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_EndRegistration
==============
*/
void R_EndRegistration()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_TrackStatistics
==============
*/
void R_TrackStatistics(trStatistics_t *stats)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_ConfigureRenderer
==============
*/
void R_ConfigureRenderer(const GfxConfiguration *notthis)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_StereoActivated
==============
*/
bool R_StereoActivated()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
R_InitOnce
==============
*/
void R_InitOnce()
{
	;
}

/*
==============
R_InitThreads
==============
*/
void R_InitThreads()
{
	UNIMPLEMENTED(__FUNCTION__);
}

