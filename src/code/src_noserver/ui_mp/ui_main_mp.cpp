#include "types.h"
#include "vars.h"
#include <ui/ui_public.h>
#include <client/client_public.h>
#include <sound/sound_public.h>
#include <qcommon/qcommon_public.h>
#include <client_mp/client_mp_public.h>
#include <demo/demo_public.h>
#include <cgame_mp/cgame_mp_public.h>
#include <client/client.h>

/*
==============
UI_Project_Zombie_RegisterDvars
==============
*/
const dvar_t *UI_Project_Zombie_RegisterDvars()
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
UI_Project_RegisterDvars
==============
*/
void UI_Project_RegisterDvars()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_Project_AssetCache
==============
*/
void UI_Project_AssetCache()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_Project_Refresh
==============
*/
void UI_Project_Refresh(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_KeyClearStates_f
==============
*/
void UI_KeyClearStates_f()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_SetMap
==============
*/
void UI_SetMap(const char *mapname, const char *gametype)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_DrawBlurMaterial
==============
*/
void UI_DrawBlurMaterial(UIContextIndex_t contextIndex, rectDef_s *rect, vec4_t *color)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_GetMapTableName
==============
*/
const char *UI_GetMapTableName()
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
UI_GetMapName
==============
*/
const char *UI_GetMapName(const char *inputMapName, bool returnStringRef)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
UI_GetGameTypeName
==============
*/
const char *UI_GetGameTypeName(const char *inputGameType, bool returnStringRef, const char *inputMapName)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
UI_GetZMMapStartLocName
==============
*/
const char *UI_GetZMMapStartLocName(const char *inputZMMapStartLoc, bool returnStringRef)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
UI_GetOverlayMapNameFromIndex
==============
*/
const char *UI_GetOverlayMapNameFromIndex(int mapIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
UI_DrawWagerTier
==============
*/
void UI_DrawWagerTier(const LocalClientNum_t localClientNum, rectDef_s *rect, Font_s *font, vec4_t *color, float textScale, int style, float text_x, float text_y, int textAlignMode)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
EditPlaylistPopulationTexture::ReplaceTextureWithCpuWriteAccessTexture
==============
*/
/*void EditPlaylistPopulationTexture::ReplaceTextureWithCpuWriteAccessTexture(GfxImage *img)
{
	UNIMPLEMENTED(__FUNCTION__);
}*/

/*
==============
CompareGeoPoint
==============
*/
int CompareGeoPoint(const void *a, const void *b)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
UI_DrawPartyMemberDownloadProgress
==============
*/
void UI_DrawPartyMemberDownloadProgress(UIContextIndex_t contextIndex, const rectDef_s *rect, const vec4_t *color)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_DrawHeatMap
==============
*/
void UI_DrawHeatMap(UIContextIndex_t contextIndex, const rectDef_s *rect, const vec4_t *color)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_CalculateDeclination
==============
*/
long double UI_CalculateDeclination()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
UI_StartServer
==============
*/
void UI_StartServer(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_Project_RunMenuScript
==============
*/
void UI_Project_RunMenuScript(LocalClientNum_t localClientNum, UIContextIndex_t contextIndex, const char *name, const char **args, const char *actualScript)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_Project_InitOnceForAllClients
==============
*/
void UI_Project_InitOnceForAllClients()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_ShowErrorPopupIfNecessary
==============
*/
void UI_ShowErrorPopupIfNecessary(LocalClientNum_t localClientNum, uiInfo_s *uiInfo)
{
    assert(uiInfo);
    UI_OpenErrorPopup();
}

/*
==============
UI_SetupLobby
==============
*/
void UI_SetupLobby(LocalClientNum_t localClientNum, bool partyLobby, const char *menuName, const eGameModes currentLobbyMode, const dvar_t *playerCountDvar, const dvar_t *localPlayerCountDvar, bool clearDemoInformation)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_SetActiveMenu
==============
*/
int __cdecl UI_SetActiveMenu(LocalClientNum_t localClientNum, int menu)
{
    UiContext* Info;
	const char* buf;

	Info = UI_GetInfo(localClientNum);

    // this should be the ONLY way the menu system is brought up
    if (Info->menuCount > 0)
    {
        assert(menu != UIMENU_SCRIPT_POPUP);
        switch (menu)
        {
        case UIMENU_NONE:
            Key_RemoveCatcher(localClientNum, -9);
            Dvar_SetInt(cl_paused, 0);
            Menus_CloseAll(localClientNum, Info);
            return 1;
        case UIMENU_MAIN:
            UI_ShowErrorPopupIfNecessary(localClientNum, (uiInfo_s*)Info);
            Menus_CloseAllBehindMain(localClientNum, Info);
            SND_FadeIn();
            return 1;
        case UIMENU_INGAME:
            if (Com_SessionMode_CanPauseZombiesGame())
            {
                Dvar_SetInt(cl_paused, 1);
                CL_ForceNewSnapshots();
            }
            Key_SetCatcher(localClientNum, 8);
            Menus_CloseAll(localClientNum, Info);
            if (Demo_IsPlaying())
            {
                if (Demo_IsClipPreviewRunning())
                {
                    Demo_CancelPreview();
                    return 1;
                }
                else
                {
                    Menus_OpenByName(localClientNum, Info, "demo_ingame");
                    if (!Demo_IsPaused())
                        Demo_Pause();
                    return 1;
                }
            }
            else
            {
                if (!Menus_OpenByName(localClientNum, Info, CG_ScriptMainMenu(localClientNum)))
                {
                    Menus_OpenByName(localClientNum, Info, "main");
                    Menus_CloseAllBehindMain(localClientNum, Info);
                }
                return 1;
            }
        case UIMENU_PREGAME:
            Key_ClearStates(localClientNum);
            Key_SetCatcher(localClientNum, 8);
            Menus_CloseAll(localClientNum, Info);
            Menus_OpenByName(localClientNum, Info, "pregame_loaderror_mp");
            return 1;
        case UIMENU_WM_QUICKMESSAGE:
            if (!Menus_FindByName(Info, "quickmessage"))
                return 0;
            Info->cursor.x = 639.0;
            Info->cursor.y = 479.0;
            UI_SetSystemCursorPos(Info, 639.0, 479.0);
            Key_SetCatcher(localClientNum, 8);
            CL_LocalClient_SetCUIFlag(localClientNum, 64);
            Menus_CloseAll(localClientNum, Info);
            Menus_OpenByName(localClientNum, Info, "quickmessage");
            return 1;
        case UIMENU_SCOREBOARD:
            Key_SetCatcher(localClientNum, 8);
            Menus_CloseAll(localClientNum, Info);
            UI_ShowErrorPopupIfNecessary(localClientNum, (uiInfo_s*)Info);
            return 1;
        case UIMENU_GAMERCARD:
            Key_SetCatcher(localClientNum, 8);
            Menus_OpenByName(localClientNum, Info, "menu_playercard");
            UI_ShowErrorPopupIfNecessary(localClientNum, (uiInfo_s*)Info);
            return 1;
        case UIMENU_MUTEERROR:
            Key_SetCatcher(localClientNum, 8);
            Menus_OpenByName(localClientNum, Info, "unmute_error_popup_live");
            UI_ShowErrorPopupIfNecessary(localClientNum, (uiInfo_s*)Info);
            return 1;
        case UIMENU_SPLITSCREENGAMESETUP:
            Key_SetCatcher(localClientNum, 8);
            Menus_OpenByName(localClientNum, Info, "main");
            Menus_SetFocusToItem(localClientNum, Info, "main", "splitscreen");
            Menus_OpenByName(localClientNum, Info, "menu_gamesetup_splitscreen");
            UI_ShowErrorPopupIfNecessary(localClientNum, (uiInfo_s*)Info);
            Menus_CloseAllBehindMain(localClientNum, Info);
            SND_FadeIn();
        case UIMENU_SYSTEMLINKJOINGAME:
            Key_SetCatcher(localClientNum, 8);
            Menus_OpenByName(localClientNum, Info, "main");
            Menus_SetFocusToItem(localClientNum, Info, "main", "system_link");
            Menus_OpenByName(localClientNum, Info, "menu_systemlink_lobby");
            UI_ShowErrorPopupIfNecessary(localClientNum, (uiInfo_s*)Info);
            Menus_CloseAllBehindMain(localClientNum, Info);
            SND_FadeIn();
        case UIMENU_PARTY:
            UI_SetupLobby(localClientNum, 1, "PlayerMatchPartyLobby", GAMEMODE_PUBLIC_MATCH, party_maxplayers_partylobby, party_maxlocalplayers_playermatch, 1);
            return 1;
        case UIMENU_LEAGUE_PARTY:
            UI_SetupLobby(localClientNum, 1, "LeaguePlayPartyLobby", GAMEMODE_LEAGUE_MATCH, party_maxplayers_partylobby, party_maxplayers_leaguematch, 1);
        case UIMENU_WAGER_PARTY:
            UI_SetupLobby(localClientNum, 1, "PlayerMatchWagerLobby", GAMEMODE_WAGER_MATCH, party_maxplayers_wagerpartylobby, party_maxlocalplayers_wagermatch, 1);
            return 1;
        case UIMENU_GAMELOBBY:
            UI_SetupLobby(localClientNum, 0, "PublicGameLobby", GAMEMODE_PUBLIC_MATCH, 0, party_maxlocalplayers_playermatch, 1);
            return 1;
        case UIMENU_WAGERLOBBY:
            UI_SetupLobby(localClientNum, 0, "PlayerMatchWagerLobby", GAMEMODE_WAGER_MATCH, party_maxplayers_wagermatch, party_maxlocalplayers_wagermatch, 1);
            return 1;
        case UIMENU_PRIVATELOBBY:
            UI_SetupLobby(localClientNum, 0, "PrivateOnlineGameLobby", GAMEMODE_PRIVATE_MATCH, party_maxplayers_privatematch, party_maxlocalplayers_privatematch, 1);
            return 1;
        case UIMENU_LEAGUELOBBY:
            UI_SetupLobby(localClientNum, 0, "LeagueGameLobby", GAMEMODE_LEAGUE_MATCH, 0, party_maxplayers_leaguematch, 1);
            return 1;
        case UIMENU_LOCALGAMELOBBY:
            UI_SetupLobby(localClientNum, 0, "PrivateLocalGameLobby", GAMEMODE_PRIVATE_MATCH, party_maxplayers_local_splitscreen, party_maxlocalplayers_local_splitscreen, 1);
            Com_SessionMode_SetOnlineGame(0);
            Com_SessionMode_SetMode(SESSIONMODE_OFFLINE, 0);
            Com_SessionMode_SetMode(SESSIONMODE_SYSTEMLINK, 1);
            return 1;
        case UIMENU_THEATERLOBBY:
            UI_SetupLobby(localClientNum, 0, "TheaterLobby", GAMEMODE_THEATER, party_maxplayers_theater, party_maxlocalplayers_theater, 0);
            // FIX MAYBE???
            return 1;
        case UIMENU_MIGRATION:
            Key_SetCatcher(localClientNum, 8);
            Menus_CloseAll(localClientNum, Info);
            Menus_OpenByName(localClientNum, Info, "migration");
            return 1;
        }
    }

    return 0;
}

/*
==============
UI_TranslateIntegerToOrdinal
==============
*/
const char *UI_TranslateIntegerToOrdinal(int integer)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
UI_Popup
==============
*/
int UI_Popup(LocalClientNum_t localClientNum, const char *menu)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
UI_ShouldDrawCrosshair
==============
*/
bool UI_ShouldDrawCrosshair()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
UI_GetGameTypeDisplayNameCaps
==============
*/
const char *UI_GetGameTypeDisplayNameCaps(const char *pszGameType, const char *pszMap)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
UI_SetMapStartLocation
==============
*/
void UI_SetMapStartLocation(const char *mapStartLocation, bool isFromParty)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_SetGameModeGroup
==============
*/
void UI_SetGameModeGroup(const char *gameMode)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_GetMapDisplayNameCaps
==============
*/
const char *UI_GetMapDisplayNameCaps(const char *pszMap)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
UI_GetMapLocationName
==============
*/
char *UI_GetMapLocationName(const char *pszMap)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
UI_DrawConnectScreen
==============
*/
void UI_DrawConnectScreen(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_GetGameTypeOnMapName
==============
*/
void UI_GetGameTypeOnMapName(char *outputString, const char *inputMapName, const char *inputGameType)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_DrawGameTypeOnMapName
==============
*/
void UI_DrawGameTypeOnMapName(const LocalClientNum_t localClientNum, rectDef_s *rect, Font_s *font, vec4_t *color, float textScale, int style)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
EditPlaylistPopulationTexture::EditPlaylistPopulationTexture
==============
*/
/*void EditPlaylistPopulationTexture::EditPlaylistPopulationTexture(EditPlaylistPopulationTexture *notthis, GfxImage *img)
{
	UNIMPLEMENTED(__FUNCTION__);
}*/

/*
==============
UI_GeneratePlaylistPopulationTextureInternal
==============
*/
void UI_GeneratePlaylistPopulationTextureInternal(GfxImage *img, unsigned __int8 *heatmap)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_GeneratePlaylistPopulationTexture
==============
*/
void UI_GeneratePlaylistPopulationTexture()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_DrawPlaylistPopulation
==============
*/
void UI_DrawPlaylistPopulation(UIContextIndex_t contextIndex, const rectDef_s *rect, const vec4_t *color)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_Project_OwnerDraw
==============
*/
void UI_Project_OwnerDraw(const vec4_t *a1, LocalClientNum_t localClientNum, itemDef_s *item, float x, float y, float w, float h, int horzAlign, int vertAlign, int ownerDraw, int ownerDrawFlags, vec4_t *color)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_Project_OwnerDrawText
==============
*/
void UI_Project_OwnerDrawText(const LocalClientNum_t localClientNum, UIContextIndex_t contextIndex, itemDef_s *item, float x, float y, float w, float h, int horzAlign, int vertAlign, float text_x, float text_y, int ownerDraw, int ownerDrawFlags, int align, Font_s *font, float scale, vec4_t *color, Material *material, int textStyle, rectDef_s parentRect, int textAlignMode)
{
	UNIMPLEMENTED(__FUNCTION__);
}

