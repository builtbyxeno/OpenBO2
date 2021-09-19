#pragma once

#include "types.h"

//t6/code/src_noserver/ui_mp/ui_feeders_mp.cpp
int UI_GetMapCount();
int UI_Project_FeederCount(;
int UI_GetMapIdForNum(const int num);
const GfxViewParms *UI_FeederItemText_Maps(;
bool UI_FeederItemColor_InGamePlayerList(;
bool UI_FeederItemColor_ClanMembers(;
bool UI_FeederItemColor_AARScoreboard(;
void UI_Project_FeederItemColor(ControllerIndex_t,UIContextIndex_t,itemDef_s *,float,int,int,vec4_t &,bool);
int UI_GetCurrentIndexForSplitscreen(int index);
void UI_FeederDoubleClickDlcMaps(;
contentPackInfo *UI_GetMapLoadNameForCurrentIndex(int index);
void UI_OverrideCursorPos_Maps(UIContextIndex_t contextIndex, listBoxDef_s *listPtr);
void UI_OverrideCursorPos_Gametypes(;
void UI_OverrideCursorPos_Contracts(;
// bool UI_Project_OverrideCursorPos@<al>(;
void UI_FeederSelection_Maps(UIContextIndex_t contextIndex, float feederID, int index);
void UI_FeederSelection_GametypesBase(;
void UI_Project_FeederSelection(;
bool UI_Project_FeederDataExtended(;
void UI_FeederBackColor(;

//t6/code/src_noserver/ui_mp/ui_gameinfo_mp.cpp
void UI_LoadMaps();
void UI_LoadZombieGameMode();
void UI_LoadCustomMatchGameTypes();

//t6/code/src_noserver/ui_mp/ui_main_mp.cpp
const dvar_t *UI_Project_Zombie_RegisterDvars();
void UI_Project_RegisterDvars();
void UI_Project_AssetCache();
void UI_Project_Refresh(LocalClientNum_t localClientNum);
void UI_KeyClearStates_f();
void UI_SetMap(const char *mapname, const char *gametype);
void UI_DrawBlurMaterial(UIContextIndex_t contextIndex, rectDef_s *rect, vec4_t *color);
const char *UI_GetMapTableName();
const char *UI_GetMapName(const char *inputMapName, bool returnStringRef);
const char *UI_GetGameTypeName(const char *inputGameType, bool returnStringRef, const char *inputMapName);
const char *UI_GetZMMapStartLocName(const char *inputZMMapStartLoc, bool returnStringRef);
const char *UI_GetOverlayMapNameFromIndex(int mapIndex);
void UI_DrawWagerTier(;
// void EditPlaylistPopulationTexture::ReplaceTextureWithCpuWriteAccessTexture(GfxImage *img);
int CompareGeoPoint(const void *a, const void *b);
void UI_DrawPartyMemberDownloadProgress(;
void UI_DrawHeatMap(UIContextIndex_t contextIndex, const rectDef_s *rect, const vec4_t *color);
long double UI_CalculateDeclination();
void UI_StartServer(LocalClientNum_t localClientNum);
void UI_Project_RunMenuScript(;
void UI_Project_InitOnceForAllClients();
void UI_ShowErrorPopupIfNecessary(LocalClientNum_t localClientNum, uiInfo_s *uiInfo);
void UI_SetupLobby(;
int UI_SetActiveMenu(LocalClientNum_t localClientNum, int menu);
const char *UI_TranslateIntegerToOrdinal(int integer);
int UI_Popup(LocalClientNum_t localClientNum, const char *menu);
bool UI_ShouldDrawCrosshair();
const char *UI_GetGameTypeDisplayNameCaps(const char *pszGameType, const char *pszMap);
void UI_SetMapStartLocation(const char *mapStartLocation, bool isFromParty);
void UI_SetGameModeGroup(const char *gameMode);
const char *UI_GetMapDisplayNameCaps(const char *pszMap);
char *UI_GetMapLocationName(const char *pszMap);
void UI_DrawConnectScreen(LocalClientNum_t localClientNum);
void UI_GetGameTypeOnMapName(char *outputString, const char *inputMapName, const char *inputGameType);
void UI_DrawGameTypeOnMapName(;
// void __thiscall EditPlaylistPopulationTexture::EditPlaylistPopulationTexture(;
void UI_GeneratePlaylistPopulationTextureInternal(GfxImage *img, unsigned __int8 *heatmap);
void UI_GeneratePlaylistPopulationTexture();
void UI_DrawPlaylistPopulation(UIContextIndex_t contextIndex, const rectDef_s *rect, const vec4_t *color);
void UI_Project_OwnerDraw(;
void UI_Project_OwnerDrawText(;

