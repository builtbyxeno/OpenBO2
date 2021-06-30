/*
 * Copyright (c) 2020-2021 OpenIW
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms and conditions of the GNU General Public License,
 * version 2, as published by the Free Software Foundation.
 *
 * This program is distributed in the hope it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef COMMON_H
#define COMMON_H

enum consoleChannel_e : __int32
{
	CON_CHANNEL_DONT_FILTER = 0x0,
	CON_CHANNEL_ERROR = 0x1,
	CON_CHANNEL_GAMENOTIFY = 0x2,
	CON_CHANNEL_BOLDGAME = 0x3,
	CON_CHANNEL_OBJNOTIFY = 0x4,
	CON_CHANNEL_SUBTITLE = 0x5,
	CON_CHANNEL_OBITUARY = 0x6,
	CON_CHANNEL_COOPINFO = 0x7,
	CON_CHANNEL_LOGFILEONLY = 0x8,
	CON_CHANNEL_CONSOLEONLY = 0x9,
	CON_CHANNEL_SYSTEM = 0xA,
	CON_CHANNEL_NETWORK = 0xB,
	CON_CHANNEL_TASK = 0xC,
	CON_CHANNEL_GFX = 0xD,
	CON_CHANNEL_SOUND = 0xE,
	CON_CHANNEL_FILES = 0xF,
	CON_CHANNEL_UI = 0x10,
	CON_CHANNEL_AI = 0x11,
	CON_CHANNEL_ANIM = 0x12,
	CON_CHANNEL_PHYS = 0x13,
	CON_CHANNEL_FX = 0x14,
	CON_CHANNEL_SCRIPT = 0x15,
	CON_CHANNEL_TL = 0x16,
	CON_CHANNEL_PERFORMANCE = 0x17,
	CON_CHANNEL_DEVGUI = 0x18,
	CON_CHANNEL_CLIENT = 0x19,
	CON_CHANNEL_SERVER = 0x1A,
	CON_CHANNEL_PLAYERWEAP = 0x1B,
	CON_CHANNEL_LIVE = 0x1C,
	CON_CHANNEL_FROMSCRIPT = 0x1D,
	CON_CHANNEL_SPAWNSYSTEM = 0x1E,
	CON_CHANNEL_LEADERBOARDS = 0x1F,
	CON_CHANNEL_DDL = 0x20,
	CON_CHANNEL_SPU = 0x21,
	CON_CHANNEL_GAMERPROFILE = 0x22,
	CON_CHANNEL_PRESENCE = 0x23,
	CON_CHANNEL_RUMBLE = 0x24,
	CON_CHANNEL_UNLOCKABLES = 0x25,
	CON_CHANNEL_VOICE = 0x26,
	CON_CHANNEL_HTTP = 0x27,
	CON_CHANNEL_GFWL = 0x28,
	CON_CHANNEL_IPAK = 0x29,
	CON_CHANNEL_WEBM = 0x2A,
	CON_CHANNEL_PROBER = 0x2B,
	CON_CHANNEL_MIPSTER = 0x2C,
	CON_CHANNEL_STEAM = 0x2D,
	CON_CHANNEL_SOCIAL = 0x2E,
	CON_CHANNEL_DCACHE = 0x2F,
	CON_CHANNEL_RSTREAM = 0x30,
	CON_CHANNEL_SCHEDULER = 0x31,
	CON_CHANNEL_MATCHRECORD = 0x32,
	CON_CHANNEL_MIGRATE = 0x33,
	CON_BUILTIN_CHANNEL_COUNT = 0x34,
	CON_FIRST_DEBUG_CHANNEL = 0x2E,
};

typedef enum errorParm_t : __int32
{
	ERR_FATAL = 0x0,
	ERR_DROP = 0x1,
	ERR_FROM_STARTUP = 0x2,
	ERR_SERVERDISCONNECT = 0x3,
	ERR_DISCONNECT = 0x4,
	ERR_SCRIPT = 0x5,
	ERR_SCRIPT_DROP = 0x6,
	ERR_LOCALIZATION = 0x7,
} errorParm_t;

extern int logfile;

void* Com_LiveAllocate(const unsigned int);
void Com_LiveDeallocate(void*);
unsigned char* Com_LiveRealloc(void*, unsigned int);
unsigned char* Com_LiveCalloc(unsigned int num, unsigned int size);
void TRACK_common(void);
void Com_NTPSync_f(void);
bool Com_IsRunningMenuLevel(char const*);
bool Com_IsMenuLevel(char const*);
void Com_BeginRedirect(char*, unsigned int, void (*)(char*));
void Com_EndRedirect(void);
void Com_OpenLogFile(void);
void Com_LogPrintMessage(int, char const*);
void Com_PrintMessage(int, char const*, int);
void Com_Printf(int, char const*, ...);
void Com_DPrintf(int, char const*, ...);
void Com_PrintError(int, char const*, ...);
void Com_PrintWarning(int, char const*, ...);
void Com_InitDynamicRender(void);
void Com_ShutdownDynamicMemorySystems(void);
float Com_GetTimeScale(void);
void Com_SetTimeScale(float);
bool Com_ErrorIsNotice(char const*);
void Com_SetLocalizedErrorMessage(char const*, char const*);
void Com_SetErrorMessage(char const*);
void Com_PrintStackTrace(int, void (*)(char const*));
void Com_ErrorAbort(void);
void Com_Error(enum errorParm_t, char const*, ...);
void Com_ParseCommandLine(char*);
int Com_SafeMode(void);
bool Com_StartupProcessSetCommand(int, char const*);
void Com_StartupVariable(char const*);
void Com_AddStartupCommands(void);
void Info_Print(char const*);
void* Com_AllocEvent(int);
void Com_PacketEventLoop(enum LocalClientNum_t, struct msg_t*);
void Com_ClientPacketEvent(void);
void Com_ServerPacketEvent(void);
void Com_EventLoop(void);
void Com_Error_f(void);
void Com_Freeze_f(void);
void Com_Crash_f(void);
int Com_CompressWithZLib(unsigned char const*, int, unsigned char*, int);
int Com_DecompressWithZLib(unsigned char const*, int, unsigned char*, int);
void Com_InitDvars(void);
void Com_CheckForInvites_f(void);
void Com_RunAutoExec(enum LocalClientNum_t, enum ControllerIndex_t);
void Com_ExecStartupConfigs(enum LocalClientNum_t, char const*);
void Com_WriteConfigToFile(enum LocalClientNum_t, char const*);
bool Com_isFullyInitialized(void);
void Com_WriteConfig_f(void);
void Com_WriteKeyConfig_f(void);
void Com_WriteDefaults_f(void);
float Com_GetTimescaleForSnd(void);
void Com_SetSlowMotion(float, float, int);
void Com_ResetSlowMotion(void);
void Com_SetSlowMotionDelayed(float, float, int, int);
float Com_ViewScaleMsec(float);
void Com_Frame_Try_Block_Function(void);
char* Com_GetLevelSharedFastFile(char const*);
void Com_LoadCommonFastFile(void);
void Com_UnloadLevelFastFiles(void);
void Com_LoadLevelFastFiles(char const*);
void Com_LoadLevelFastFiles_BlockForOverlay(char const*);
void Com_UnloadFrontEnd(bool);
void Com_ResetFrametime(void);
void Com_CheckSyncFrame(void);
bool Com_LogFileOpen(void);
void Field_Clear(struct field_t*);
void Com_Restart(void);
void* CG_AllocAnimTree(int);
void* MT_AllocAnimTree(int);
struct XAnimTree_s* Com_XAnimCreateSmallTree(struct XAnim_s*);
void Com_XAnimFreeSmallTree(struct XAnimTree_s*);
void Com_SetWeaponInfoMemory(int);
void Com_FreeWeaponInfoMemory(int);
int Com_GetWeaponInfoMemory(void);
int Com_AddToString(char const*, char*, int, int, int);
char Com_GetDecimalDelimiter(void);
void Com_LocalizedFloatToString(float, char*, unsigned int, unsigned int);
void Com_SyncThreads(void);
char const* Com_DisplayName(char const*, char const*, int);
char const* CS_DisplayName(struct clientState_s const*, int);
int Com_GetPrivateClients(void);
void NetAdr_SetType(struct netadr_t*, enum netadrtype_t);
bool Com_UseRawUDP(void);
void Com_Quit_f(void);
void Com_InitDynamicMemorySystems(void);
void Com_ErrorCleanup(void);
void Com_Init_Try_Block_Function(char*);
void Com_Frame(void);
bool Com_SetPrivateClients(int);
void Com_Shutdown(char const*);
void Com_Init(char*, bool);

#endif