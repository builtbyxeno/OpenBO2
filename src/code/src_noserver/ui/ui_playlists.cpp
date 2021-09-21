#include "types.h"
#include "functions.h"

/*
==============
Playlist_GetPlaylistFilename
==============
*/
const char *Playlist_GetPlaylistFilename()
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Playlist_Strdup
==============
*/
char *Playlist_Strdup(const char *src)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Playlist_Strdup_Newline
==============
*/
const char *Playlist_Strdup_Newline(const char *src)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Playlist_BeginRules
==============
*/
char *Playlist_BeginRules()
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Playlist_AppendRules
==============
*/
bool Playlist_AppendRules(const char *base, const char *token)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Playlist_GetLanguage
==============
*/
const char *Playlist_GetLanguage()
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Playlist_GetCategoryIdByName
==============
*/
int Playlist_GetCategoryIdByName(const char *name)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Playlist_GetSuperCategoryIdByName
==============
*/
int Playlist_GetSuperCategoryIdByName(const char *name)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
ParseIntRange
==============
*/
int ParseIntRange(const char *field, const char **pData, int min, int max)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Playlist_ParseRequiredDLC
==============
*/
char Playlist_ParseRequiredDLC(const char **pData, const char *name, const char **string)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Playlist_SetPlaylistEntry
==============
*/
void Playlist_SetPlaylistEntry(const int playlistNum, const char *mapName, const char *gameType, const char *startLoc, int weight)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Playlist_GetNumEntries
==============
*/
int Playlist_GetNumEntries(int playlistId)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Playlist_GetEntry
==============
*/
playlistEntry *Playlist_GetEntry(int playlistId, int entry)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Playlist_GetLeagueID
==============
*/
int Playlist_GetLeagueID(int playlistId)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Playlist_IsLeaguePlaylist
==============
*/
BOOL Playlist_IsLeaguePlaylist(int playlistId)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Playlist_GetParkingPlaylistForRealPlaylist
==============
*/
int Playlist_GetParkingPlaylistForRealPlaylist(int realPlaylist)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Playlist_GetPlaylistDescription
==============
*/
const char *Playlist_GetPlaylistDescription(const ControllerIndex_t controllerIndex, const int playlistId)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Playlist_IsLocked
==============
*/
int Playlist_IsLocked(const ControllerIndex_t controllerIndex, const int playlistId)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Playlist_CategoryIsLocked
==============
*/
int Playlist_CategoryIsLocked(const ControllerIndex_t controllerIndex, const int categoryId)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Playlist_GetMapPacksUsedByPlaylist
==============
*/
int Playlist_GetMapPacksUsedByPlaylist(const int playlistId)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Playlist_CanWeHostThisPlaylist
==============
*/
char Playlist_CanWeHostThisPlaylist(const ControllerIndex_t controllerIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Playlist_ResetWeights
==============
*/
void Playlist_ResetWeights(const int playlistId, const PartyData_s *party)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Playlist_ResetWeights
==============
*/
void Playlist_ResetWeights(const int playlistId)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Playlist_CalcTotalWeights
==============
*/
int Playlist_CalcTotalWeights(const int playlistId, const int lastSelection, const int lastToLastSelection)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Playlist_FindEntryByWeight
==============
*/
int Playlist_FindEntryByWeight(const int playlistId, const int selectedWeight, const int lastSelection, const int lastToLastSelection)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Playlist_FindGametype
==============
*/
playlistGametype *Playlist_FindGametype(const char *gametypeInternalName)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Playlist_FindMaplist
==============
*/
playlistMapList *Playlist_FindMaplist(const char *name)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Playlist_GetGametypeCount
==============
*/
int Playlist_GetGametypeCount()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Playlist_GetGametypeLocalizedName
==============
*/
const char *Playlist_GetGametypeLocalizedName(int index)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Playlist_GetGametypeInternalName
==============
*/
const char *Playlist_GetGametypeInternalName(int index)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Playlist_GetVersionNumber
==============
*/
int Playlist_GetVersionNumber()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Playlist_GetUnlockXp
==============
*/
int Playlist_GetUnlockXp(const ControllerIndex_t localControllerIndex, const int playlistId)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Playlist_GetUnlockPLevel
==============
*/
int Playlist_GetUnlockPLevel(const ControllerIndex_t localControllerIndex, const int playlistId)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Playlist_GetMaxPartySize
==============
*/
int Playlist_GetMaxPartySize(const ControllerIndex_t localControllerIndex, const int playlistId)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Playlist_GetMinPartySize
==============
*/
int Playlist_GetMinPartySize(const ControllerIndex_t localControllerIndex, const int playlistId)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Playlist_IsGametypeBannable
==============
*/
bool Playlist_IsGametypeBannable(const ControllerIndex_t localControllerIndex, const int playlistId)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Playlist_GetCategoryId
==============
*/
int Playlist_GetCategoryId(int playlistId)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Playlist_GetCurrentId
==============
*/
int Playlist_GetCurrentId()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Playlist_SetCurrentId
==============
*/
void Playlist_SetCurrentId(int newId)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Playlist_RegisterDvars
==============
*/
const dvar_t *Playlist_RegisterDvars()
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Playlist_Init
==============
*/

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
}

/*
==============
Playlist_ParsePlaylists
==============
*/
void Playlist_ParsePlaylists(const char *buffer)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Playlist_GetCategoryLocalizedName
==============
*/
const char *Playlist_GetCategoryLocalizedName(const ControllerIndex_t controllerIndex, const int categoryId)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Playlist_GetPlaylistName
==============
*/
const char *Playlist_GetPlaylistName(const ControllerIndex_t controllerIndex, const int playlistId)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Playlist_ChooseEntry
==============
*/

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
}

/*
==============
Playlist_ChooseEntry
==============
*/

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
}

/*
==============
Playlist_MigrateHost
==============
*/
void Playlist_MigrateHost(const ControllerIndex_t localControllerIndex, unsigned __int8 *lastEntries, int numEntries)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Playlist_GetMapName
==============
*/
const GfxViewParms *Playlist_GetMapName(const ControllerIndex_t localControllerIndex, const int entryNum)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Playlist_GetScriptGameTypeName
==============
*/
const GfxViewParms *Playlist_GetScriptGameTypeName(const ControllerIndex_t localControllerIndex, const int entryNum)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Playlist_RunRules
==============
*/
char Playlist_RunRules(const ControllerIndex_t localControllerIndex, const int entryNum)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Playlist_DoesMapMatchPlaylistEntry
==============
*/
bool Playlist_DoesMapMatchPlaylistEntry(const int entryNum, const char *mapname)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Playlist_DoesGametypeMatchPlaylistEntry
==============
*/
bool Playlist_DoesGametypeMatchPlaylistEntry(const int entryNum, const char *gametype)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Playlist_GetLocalizedGametypeName
==============
*/
const char *Playlist_GetLocalizedGametypeName(const ControllerIndex_t localControllerIndex, const int entryNum)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

