#include "types.h"
#include "vars.h"
#include "client_public.h"
#include <qcommon/qcommon_public.h>
#include <gfx_d3d/gfx_d3d_public.h>

/*
==============
CL_AnyLocalClientsRunning
==============
*/
char CL_AnyLocalClientsRunning()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CL_Command_DisableAllButPrimaryClients
==============
*/
void CL_Command_DisableAllButPrimaryClients()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CL_Command_SetClientBeingUsedAndPrimary
==============
*/
void CL_Command_SetClientBeingUsedAndPrimary()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CL_Command_SetClientBeingUsedAndPrimaryAndActive
==============
*/
void CL_Command_SetClientBeingUsedAndPrimaryAndActive()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CL_Command_SetClientPrimary
==============
*/
void CL_Command_SetClientPrimary()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CL_Command_SetClientBeingUsed
==============
*/
void CL_Command_SetClientBeingUsed()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CL_Command_SetClientBeingUsedAndActive
==============
*/
void CL_Command_SetClientBeingUsedAndActive()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CL_Command_DisableAllClients
==============
*/
void CL_Command_DisableAllClients()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CL_Command_SignClientOutOfUI
==============
*/
void CL_Command_SignClientOutOfUI()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CL_Command_SignClientIn
==============
*/
void CL_Command_SignClientIn()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CL_SetupClientsForIngame
==============
*/
void CL_SetupClientsForIngame()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CL_DrawFramedPicPhysical
==============
*/
void CL_DrawFramedPicPhysical(float x, float y, float w, float h, float thicknessW, float thicknessH, float thicknessTex, int sides, const vec4_t *color, Material *material)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CL_ForwardToServer_f
==============
*/
void CL_ForwardToServer_f()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CL_Setenv_f
==============
*/
void CL_Setenv_f()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CL_SkipLevel_f
==============
*/
void CL_SkipLevel_f()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CL_Vid_Restart_f
==============
*/
void CL_Vid_Restart_f()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CL_Snd_Restart_f
==============
*/
void CL_Snd_Restart_f()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CL_OpenedIWDList_f
==============
*/
void CL_OpenedIWDList_f()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CL_ReferencedIWDList_f
==============
*/
void CL_ReferencedIWDList_f()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CL_Configstrings_f
==============
*/
void CL_Configstrings_f()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CL_Clientinfo_f
==============
*/
void CL_Clientinfo_f()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CL_WasMapAlreadyLoaded
==============
*/
bool CL_WasMapAlreadyLoaded()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CL_Live_StopAllParties
==============
*/
void CL_Live_StopAllParties()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CL_Live_StopPrivateParty
==============
*/
void CL_Live_StopPrivateParty()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CL_Live_LeaveParty
==============
*/
void CL_Live_LeaveParty(PartyData_s *party, ControllerIndex_t localControllerIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CL_Live_LeaveAllParties
==============
*/
void CL_Live_LeaveAllParties(ControllerIndex_t localControllerIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CL_Live_LocalClientJoinParty
==============
*/
char CL_Live_LocalClientJoinParty(PartyData_s *party, ControllerIndex_t localControllerIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CL_Live_StopParty
==============
*/
void CL_Live_StopParty(bool keepPartyTogether)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CL_Live_PartySwitchLobbies
==============
*/
void CL_Live_PartySwitchLobbies()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CL_ExecControllerBindings_f
==============
*/
void CL_ExecControllerBindings_f()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CL_Live_ShowFriendsList
==============
*/
void CL_Live_ShowFriendsList()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CL_Live_StartPartyHost
==============
*/
void CL_Live_StartPartyHost(ControllerIndex_t localControllerIndex, bool silentFail)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CL_Live_StartPartyHost
==============
*/
void CL_Live_StartPartyHost()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CL_Live_PartyMapVeto
==============
*/
void CL_Live_PartyMapVeto()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CL_Live_UpdatePartyState
==============
*/
void CL_Live_UpdatePartyState()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CL_Live_PartyMapReady
==============
*/
void CL_Live_PartyMapReady()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CL_UpdateSession
==============
*/
void CL_UpdateSession(PartyData_s *party, SessionData *session, int maxplayers)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CL_GetUserMaxPlayerSetting
==============
*/
int CL_GetUserMaxPlayerSetting(ControllerIndex_t controllerIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CL_Live_SessionUpdate
==============
*/
void CL_Live_SessionUpdate()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CL_AnimateUI_f
==============
*/
void CL_AnimateUI_f()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CL_ResetSelectedPlayerXuid_f
==============
*/
void __cdecl CL_ResetSelectedPlayerXuid_f()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CL_DrawSpinnerPhysical
==============
*/
void CL_DrawSpinnerPhysical(float x, float y, float w, float h, const vec4_t *color)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CL_DrawSpinner
==============
*/
void CL_DrawSpinner(const ScreenPlacement *scrPlace, float x, float y, float w, float h, int horzAlign, int vertAlign, const vec4_t *color)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CL_DrawSpinnerLoadbarPhysical
==============
*/
void CL_DrawSpinnerLoadbarPhysical(float x, float y, float w, float h, const vec4_t *color, float percentDone)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CL_DrawSpinnerLoadbar
==============
*/
void CL_DrawSpinnerLoadbar(const ScreenPlacement *scrPlace, float x, float y, float w, float h, int horzAlign, int vertAlign, const vec4_t *color, float percentDone)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CL_ShutdownHunkUsers
==============
*/
void CL_ShutdownHunkUsers()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CL_SendBlackboxSession
==============
*/
void CL_SendBlackboxSession(ControllerIndex_t controllerIndex, bool isserver, const char *mapname, const char *gametype)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CL_ResetSkeletonCache
==============
*/
void CL_ResetSkeletonCache(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CL_HighestPriorityStatPacket
==============
*/
int CL_HighestPriorityStatPacket(clientConnection_t *clc, int numCompressedStatsPackets)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CL_CheckForResend
==============
*/
void CL_CheckForResend(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CL_DisconnectError
==============
*/
void CL_DisconnectError(const char *message)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CL_DisconnectPacket
==============
*/
void CL_DisconnectPacket(LocalClientNum_t localClientNum, netadr_t from, const char *reason)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CL_HandleRelayPacket
==============
*/
void CL_HandleRelayPacket(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CL_HandleVoiceTypePacket
==============
*/
char CL_HandleVoiceTypePacket(LocalClientNum_t localClientNum, msg_t *msg)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CL_SetupForNewServerMap
==============
*/
void CL_SetupForNewServerMap(LocalClientNum_t localClientNum, const char *pszMapName, const char *pszGametype)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CL_AuthRequestPacket
==============
*/
void CL_AuthRequestPacket(LocalClientNum_t localClientNum, unsigned __int64 serverSteamID)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CL_DispatchConnectionlessPacket
==============
*/
bool CL_DispatchConnectionlessPacket(LocalClientNum_t localClientNum, netadr_t from, msg_t *msg, int time)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CL_ConnectionlessPacket
==============
*/
bool CL_ConnectionlessPacket(int a1, LocalClientNum_t localClientNum, netadr_t from, msg_t *msg)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CL_PacketEvent
==============
*/
bool CL_PacketEvent(LocalClientNum_t localClientNum, netadr_t from, msg_t *msg, int time, bool connectionlesss_packets_only)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CL_LocalClientIsInGame
==============
*/
BOOL CL_LocalClientIsInGame(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CL_IsClientLocal
==============
*/
char CL_IsClientLocal(ClientNum_t clientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CL_ParseBadPacket_f
==============
*/
void CL_ParseBadPacket_f()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CL_SetupViewport
==============
*/
void CL_SetupViewport()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CL_SetupViewport_f
==============
*/
void __cdecl CL_SetupViewport_f()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CL_InitRenderer
==============
*/
void CL_InitRenderer()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CL_DevGuiDvar_f
==============
*/
void CL_DevGuiDvar_f()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CL_DevGuiDvarList_f
==============
*/
void CL_DevGuiDvarList_f()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CL_DevGuiCmd_f
==============
*/
void CL_DevGuiCmd_f()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CL_DevGuiOpen_f
==============
*/
void CL_DevGuiOpen_f()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CL_InitDevGui
==============
*/
void CL_InitDevGui()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CL_StartHunkUsers
==============
*/
void CL_StartHunkUsers()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CL_ScaledMilliseconds
==============
*/
int CL_ScaledMilliseconds()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CL_InitDedicated
==============
*/
void CL_InitDedicated()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CL_startSingleplayer_f
==============
*/
void CL_startSingleplayer_f()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CL_startZombies_f
==============
*/
void CL_startZombies_f()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CL_startMultiplayer_f
==============
*/
void CL_startMultiplayer_f()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CL_PlayLogo_f
==============
*/
void CL_PlayLogo_f()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CL_OpenScriptMenu_f
==============
*/
void CL_OpenScriptMenu_f()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Playlist_ReadFromDisk
==============
*/
char Playlist_ReadFromDisk()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Playlist_CmdReadFromDisk
==============
*/
char __cdecl Playlist_CmdReadFromDisk()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CL_VoiceFail_f
==============
*/
void CL_VoiceFail_f()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CL_ForceVoiceFail_f
==============
*/
void CL_ForceVoiceFail_f()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CL_MigrateHost_f
==============
*/
void CL_MigrateHost_f()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CL_SetNatStrict_f
==============
*/
void CL_SetNatStrict_f()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CL_SetNatOpen_f
==============
*/
void CL_SetNatOpen_f()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CL_LoadFFOTD_f
==============
*/
void CL_LoadFFOTD_f()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CL_ChooseNextPlaylist
==============
*/
void CL_ChooseNextPlaylist()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CL_ChoosePreviousPlaylist
==============
*/
void CL_ChoosePreviousPlaylist()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CL_LocalServers_f
==============
*/
void CL_LocalServers_f()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CL_FlushGump
==============
*/
void CL_FlushGump(int slot)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CL_FlushGumps
==============
*/
void __cdecl CL_FlushGumps()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CL_LoadGump
==============
*/
void CL_LoadGump()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CL_AddListenIn_f
==============
*/
void CL_AddListenIn_f()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CL_RemoveListenIn_f
==============
*/
void CL_RemoveListenIn_f()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CL_ResetListenIn_f
==============
*/
void CL_ResetListenIn_f()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CL_SetListenIn_f
==============
*/
void CL_SetListenIn_f()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CL_RemoveCommands
==============
*/
void CL_RemoveCommands()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CL_RegisterDvars
==============
*/
void CL_RegisterDvars()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CL_IsServerLoadingMap
==============
*/
bool CL_IsServerLoadingMap()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CL_IsWaitingOnServerToLoadMap
==============
*/
bool CL_IsWaitingOnServerToLoadMap(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CL_SetWaitingOnServerToLoadMap
==============
*/
void CL_SetWaitingOnServerToLoadMap(LocalClientNum_t localClientNum, bool waiting)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CL_DrawTextPhysical
==============
*/
void CL_DrawTextPhysical(const char *text, int maxChars, Font_s *font, float x, float y, float w, float xScale, float yScale, const vec4_t *color, int style, float padding)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CL_DrawTextPhysicalWithEffects
==============
*/
void CL_DrawTextPhysicalWithEffects(const char *text, int maxChars, Font_s *font, float x, float y, float w, float xScale, float yScale, const vec4_t *color, int style, const vec4_t *glowColor, Material *fxMaterial, Material *fxMaterialGlow, int fxBirthTime, int fxLetterTime, int fxDecayStartTime, int fxDecayDuration)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CL_DrawText
==============
*/
void CL_DrawText(const ScreenPlacement *scrPlace, const char *text, int maxChars, Font_s *font, float x, float y, int horzAlign, int vertAlign, float xScale, float yScale, const vec4_t *color, int style)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CL_DrawTextRotate
==============
*/
void CL_DrawTextRotate(const ScreenPlacement *scrPlace, const char *text, int maxChars, Font_s *font, float x, float y, float rotation, int horzAlign, int vertAlign, float xScale, float yScale, const vec4_t *color, int style)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CL_DrawTextPhysicalWithCursor
==============
*/
void CL_DrawTextPhysicalWithCursor(const char *text, int maxChars, Font_s *font, float x, float y, float xScale, float yScale, const vec4_t *color, int style, int cursorPos, char cursor)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CL_DrawTextWithCursor
==============
*/
void CL_DrawTextWithCursor(const ScreenPlacement *scrPlace, const char *text, int maxChars, Font_s *font, float x, float y, int horzAlign, int vertAlign, float xScale, float yScale, const vec4_t *color, int style, int cursorPos, char cursor)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CL_DrawTextWithEffects
==============
*/
void CL_DrawTextWithEffects(const ScreenPlacement *scrPlace, const char *text, int maxChars, Font_s *font, float x, float y, float rotation, int horzAlign, int vertAlign, float xScale, float yScale, const vec4_t *color, int style, const vec4_t *glowColor, Material *fxMaterial, Material *fxMaterialGlow, int fxBirthTime, int fxLetterTime, int fxDecayStartTime, int fxDecayDuration)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CL_DrawTextWithCOD7TypeWriterEffects
==============
*/
void CL_DrawTextWithCOD7TypeWriterEffects(const ScreenPlacement *scrPlace, const char *text, int maxChars, Font_s *font, float x, float y, float rotation, int horzAlign, int vertAlign, float xScale, float yScale, const vec4_t *color, int style, const vec4_t *glowColor, Material *fxMaterial, Material *fxMaterialGlow, int fxBirthTime, int fxLetterTime, int fxDecayStartTime, int fxDecayDuration)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CL_DrawTextPhysicalWithCOD7TypeWriterEffects
==============
*/
void CL_DrawTextPhysicalWithCOD7TypeWriterEffects(const char *text, int maxChars, Font_s *font, float x, float y, float xScale, float yScale, const vec4_t *color, int style, const vec4_t *glowColor, Material *fxMaterial, Material *fxMaterialGlow, int fxBirthTime, int fxLetterTime, int fxDecayStartTime, int fxDecayDuration)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CL_DrawTextWithRedactEffects
==============
*/
void CL_DrawTextWithRedactEffects(const ScreenPlacement *scrPlace, const char *text, int maxChars, Font_s *font, float x, float y, int horzAlign, int vertAlign, float xScale, float yScale, const vec4_t *color, int style, const vec4_t *glowColor, Material *fxMaterial, Material *fxMaterialGlow, int fxBirthTime, int fxLetterTime, int fxDecayStartTime, int fxDecayDuration, int fxRedactDecayStartTime, int fxRedactDecayDuration)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CL_DrawTextPhysicalWithCOD7DecodeEffects
==============
*/
void CL_DrawTextPhysicalWithCOD7DecodeEffects(const char *text, int maxChars, Font_s *font, float x, float y, float xScale, float yScale, const vec4_t *color, int style, const vec4_t *glowColor, Material *fxMaterial, Material *fxMaterialGlow, int fxBirthTime, int fxLetterTime, int fxDecayStartTime, int fxDecayDuration)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CL_DrawTextPhysicalWithRedactEffects
==============
*/
void CL_DrawTextPhysicalWithRedactEffects(const char *text, int maxChars, Font_s *font, float x, float y, float xScale, float yScale, const vec4_t *color, int style, const vec4_t *glowColor, Material *fxMaterial, Material *fxMaterialGlow, int fxBirthTime, int fxLetterTime, int fxDecayStartTime, int fxDecayDuration, int fxRedactDecayStartTime, int fxRedactDecayDuration)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CL_DrawTextWithPopInEffects
==============
*/
void CL_DrawTextWithPopInEffects(const ScreenPlacement *scrPlace, const char *text, int maxChars, Font_s *font, float x, float y, float rotation, int horzAlign, int vertAlign, float xScale, float yScale, const vec4_t *color, int style, const vec4_t *glowColor, Material *fxMaterial, Material *fxMaterialGlow, int fxBirthTime, int fxLetterTime, int fxDecayStartTime, int fxDecayDuration)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CL_ShouldDisplayHud
==============
*/
char CL_ShouldDisplayHud(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CL_IsUIActive
==============
*/
BOOL CL_IsUIActive(const LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CL_RegisterFont
==============
*/
Font_s *CL_RegisterFont(const char *fontName, int imageTrack)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
CL_GetMapCenter
==============
*/
vec3_t *CL_GetMapCenter()
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
CL_ConnectFromParty
==============
*/
void CL_ConnectFromParty(ControllerIndex_t controllerIndex, XSESSION_INFO *hostInfo, netadr_t addr, int numPublicSlots, int numPrivateSlots, const char *mapname)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CL_SanitizeClanName
==============
*/
void CL_SanitizeClanName(ControllerIndex_t controllerIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CL_UploadStatsForController
==============
*/
void CL_UploadStatsForController(const ControllerIndex_t localControllerIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CL_ClearState
==============
*/
void CL_ClearState(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CL_MapLoading_SetupDevmapParty
==============
*/
void CL_MapLoading_SetupDevmapParty()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CL_Live_StopParty
==============
*/
void CL_Live_StopParty()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CL_Live_StopPartyKeepPartyTogether
==============
*/
void CL_Live_StopPartyKeepPartyTogether()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CL_ShutdownAll
==============
*/
void CL_ShutdownRenderer(int destroyWindow)
{
	cls.rendererStarted = 0;
	Com_ShutdownWorld();
	if (Dvar_GetBool(useFastFile) && destroyWindow)
	{
		CM_Shutdown();
	}
	R_Shutdown(destroyWindow);
	cls.whiteMaterial = 0;
	cls.consoleMaterial = 0;
	cls.consoleFont = 0;
	cls.spinnerMaterial = 0;
}

/*
==============
CL_ShutdownAll
==============
*/
void CL_ShutdownAll()
{
	if (cls.rendererStarted)
	{
		CL_ShutdownRenderer(0);
	}
}

/*
==============
CL_MapLoading
==============
*/
void CL_MapLoading(const char *mapname)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CL_DownloadsComplete
==============
*/
void CL_DownloadsComplete(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CL_InitLoad
==============
*/
void CL_InitLoad(const char *mapname, const char *gametype)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CL_ShutdownRef
==============
*/
void CL_ShutdownRef()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CL_DrawLogo
==============
*/
void CL_DrawLogo(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CL_ShowIP_f
==============
*/
void CL_ShowIP_f(bdCommonAddr *notthis)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CL_RegisterCommands
==============
*/
void CL_RegisterCommands()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CL_InitOnceForAllClients
==============
*/
void CL_InitOnceForAllClients()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CL_SetupClientsForFrontend
==============
*/
void CL_SetupClientsForFrontend()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
TRACK_cl_main
==============
*/
void TRACK_cl_main()
{
	UNIMPLEMENTED(__FUNCTION__);
}

