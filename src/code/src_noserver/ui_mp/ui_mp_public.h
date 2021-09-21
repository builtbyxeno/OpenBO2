#pragma once

#include "types.h"

//t6/code/src_noserver/ui_mp/ui_feeders_mp.cpp
int UI_GetMapCount();
int UI_Project_FeederCount(const LocalClientNum_t localClientNum, UIContextIndex_t contextIndex, float feederID);
int UI_GetMapIdForNum(const int num);
const GfxViewParms *UI_FeederItemText_Maps(ControllerIndex_t controllerIndex, itemDef_s *item, int index, int column, Material **handle);
bool UI_FeederItemColor_InGamePlayerList(ControllerIndex_t controllerIndex, UIContextIndex_t contextIndex, itemDef_s *item, int index, int column, vec4_t *color, bool onFocus, team_t team);
bool UI_FeederItemColor_ClanMembers(ControllerIndex_t controllerIndex, UIContextIndex_t contextIndex, itemDef_s *item, int index, int column, vec4_t *color, bool onFocus);
bool UI_FeederItemColor_AARScoreboard(ControllerIndex_t controllerIndex, UIContextIndex_t contextIndex, float feederID, itemDef_s *item, int index, int column, vec4_t *color);
bool UI_Project_FeederItemColor(UIContextIndex_t a1, ControllerIndex_t controllerIndex, UIContextIndex_t contextIndex, itemDef_s *item, const float feederID, int index, int column);
int UI_GetCurrentIndexForSplitscreen(int index);
void UI_FeederDoubleClickDlcMaps(const LocalClientNum_t localClientNum, UIContextIndex_t contextIndex, int index);
contentPackInfo *UI_GetMapLoadNameForCurrentIndex(int index);
void UI_OverrideCursorPos_Maps(UIContextIndex_t contextIndex, listBoxDef_s *listPtr);
void UI_OverrideCursorPos_Gametypes(const LocalClientNum_t localClientNum, UIContextIndex_t contextIndex, listBoxDef_s *listPtr, float feederID);
void UI_OverrideCursorPos_Contracts(const LocalClientNum_t localClientNum, UIContextIndex_t contextIndex, itemDef_s *item, listBoxDef_s *listPtr);
bool UI_Project_OverrideCursorPos(itemDef_s *a1, listBoxDef_s *a2, const LocalClientNum_t localClientNum, UIContextIndex_t contextIndex, itemDef_s *item);
void UI_FeederSelection_Maps(UIContextIndex_t contextIndex, float feederID, int index);
void UI_FeederSelection_GametypesBase(LocalClientNum_t localClientNum, UIContextIndex_t contextIndex, float feederID, int index);
void UI_Project_FeederSelection(const LocalClientNum_t localClientNum, UIContextIndex_t contextIndex, float feederID, int index);
bool UI_Project_FeederDataExtended(ControllerIndex_t controllerIndex, UIContextIndex_t contextIndex, int feederID, listBoxDef_s *listBox, const char *field);
void UI_FeederBackColor(const LocalClientNum_t localClientNum, UIContextIndex_t contextIndex, itemDef_s *item, const float feederID, int index, vec4_t *color);

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
void UI_DrawWagerTier(const LocalClientNum_t localClientNum, rectDef_s *rect, Font_s *font, vec4_t *color, float textScale, int style, float text_x, float text_y, int textAlignMode);
// void EditPlaylistPopulationTexture::ReplaceTextureWithCpuWriteAccessTexture(GfxImage *img);
int CompareGeoPoint(const void *a, const void *b);
void UI_DrawPartyMemberDownloadProgress(UIContextIndex_t contextIndex, const rectDef_s *rect, const vec4_t *color);
void UI_DrawHeatMap(UIContextIndex_t contextIndex, const rectDef_s *rect, const vec4_t *color);
long double UI_CalculateDeclination();
void UI_StartServer(LocalClientNum_t localClientNum);
void UI_Project_RunMenuScript(LocalClientNum_t localClientNum, UIContextIndex_t contextIndex, const char *name, const char **args, const char *actualScript);
void UI_Project_InitOnceForAllClients();
void UI_ShowErrorPopupIfNecessary(LocalClientNum_t localClientNum, uiInfo_s *uiInfo);
void UI_SetupLobby(LocalClientNum_t localClientNum, bool partyLobby, const char *menuName, const eGameModes currentLobbyMode, const dvar_t *playerCountDvar, const dvar_t *localPlayerCountDvar, bool clearDemoInformation);
int __cdecl UI_SetActiveMenu(LocalClientNum_t localClientNum, int menu);
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
void UI_DrawGameTypeOnMapName(const LocalClientNum_t localClientNum, rectDef_s *rect, Font_s *font, vec4_t *color, float textScale, int style);
// void EditPlaylistPopulationTexture::EditPlaylistPopulationTexture(EditPlaylistPopulationTexture *notthis, GfxImage *img);
void UI_GeneratePlaylistPopulationTextureInternal(GfxImage *img, unsigned __int8 *heatmap);
void UI_GeneratePlaylistPopulationTexture();
void UI_DrawPlaylistPopulation(UIContextIndex_t contextIndex, const rectDef_s *rect, const vec4_t *color);
void UI_Project_OwnerDraw(const vec4_t *a1, LocalClientNum_t localClientNum, itemDef_s *item, float x, float y, float w, float h, int horzAlign, int vertAlign, int ownerDraw, int ownerDrawFlags, vec4_t *color);
void UI_Project_OwnerDrawText(const LocalClientNum_t localClientNum, UIContextIndex_t contextIndex, itemDef_s *item, float x, float y, float w, float h, int horzAlign, int vertAlign, float text_x, float text_y, int ownerDraw, int ownerDrawFlags, int align, Font_s *font, float scale, vec4_t *color, Material *material, int textStyle, rectDef_s parentRect, int textAlignMode);

