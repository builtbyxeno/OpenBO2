#include "types.h"
#include "vars.h"
#include <game/game_public.h>
#include <qcommon/qcommon_public.h>
#include <server/server_public.h>
#include <demo/demo_public.h>
#include <cgame_mp/cgame_mp_public.h>

bool bInBackupState_0;
int sSessionModeState;

/*
==============
Com_SessionMode_IsMode
==============
*/
bool Com_SessionMode_IsMode(eSessionModes mode)
{
	return ((1 << mode) & sSessionModeState) != 0;
}

/*
==============
Com_SessionMode_WriteModes
==============
*/
void Com_SessionMode_WriteModes(msg_t *msg)
{
	assert((sSessionModeState >= 0 && sSessionModeState < 0xFF));
	MSG_WriteByte(msg, sSessionModeState);
}

/*
==============
Com_SessionMode_ReadModes
==============
*/
bool Com_SessionMode_ReadModes(msg_t *msg)
{
	int newState;
	bool sameMode;

	newState = MSG_ReadByte(msg);
	assert(newState >= 0 && newState < 0xFF);
	assert((sSessionModeState & (1 << SESSIONMODE_ZOMBIES)) == (newState & (1 << SESSIONMODE_ZOMBIES)));
	assert(((sSessionModeState & (1 << SESSIONMODE_ONLINE)) == (newState & (1 << SESSIONMODE_ONLINE))) || ((sSessionModeState & (1 << SESSIONMODE_SYSTEMLINK)) ^ (newState & (1 << SESSIONMODE_SYSTEMLINK))) || ((sSessionModeState & (1 << SESSIONMODE_OFFLINE)) ^ (newState & (1 << SESSIONMODE_OFFLINE))));
	sameMode = newState == sSessionModeState;
	sSessionModeState = newState;
	return !sameMode;
}

/*
==============
BG_EmblemsInit
==============
*/
bool BG_EmblemsInit()
{
#if DEDICATED
	return G_ExitAfterConnectPaths();
#else
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
#endif
}

/*
==============
Com_SessionMode_IsOnlineGame
==============
*/
bool Com_SessionMode_IsOnlineGame()
{
	return (sSessionModeState & 4) != 0;
}

/*
==============
Com_SessionMode_SetMode
==============
*/
void Com_SessionMode_SetMode(eSessionModes mode, bool value)
{
	if (bInBackupState_0)
		Com_Error(ERR_FATAL, "\x15", "Com_GameMode_SetMode: Can not set the mode when in backup block!");
	G_ExitAfterConnectPaths();
	if (value)
		sSessionModeState |= 1 << mode;
	else
		sSessionModeState &= ~(1 << mode);
}

/*
==============
Com_SessionMode_IsPrivateOnlineGame
==============
*/
bool Com_SessionMode_IsPrivateOnlineGame()
{
	return (sSessionModeState & 4) != 0 && (sSessionModeState & 8) != 0;
}

/*
==============
Com_SessionMode_IsPublicOnlineGame
==============
*/
bool Com_SessionMode_IsPublicOnlineGame()
{
	return (sSessionModeState & 4) != 0 && (sSessionModeState & 8) == 0;
}

/*
==============
Com_SessionMode_IsZombiesGame
==============
*/
bool Com_SessionMode_IsZombiesGame()
{
	return (sSessionModeState & 0x10) != 0;
}

/*
==============
Com_SessionMode_CanPauseZombiesGame
==============
*/
bool Com_SessionMode_CanPauseZombiesGame()
{
	if ((sSessionModeState & 0x10) == 0)
		return 0;
	if (!Dvar_GetBool(tu15_zombie_local_player_test_honors_client_server_divide) || Dvar_GetBool(com_sv_running))
		return SV_AllClientsAreLocal();
	return !Demo_IsPlaying() && CG_AllClientsAreLocal();
}

/*
==============
Com_SessionMode_ResetModes
==============
*/
void Com_SessionMode_ResetModes()
{
	if (bInBackupState_0)
	{
		Com_Error(ERR_FATAL, "\x15", "Com_SessionMode_ResetModes: Can not reset the modes when in backup block!");
		if (bInBackupState_0)
			Com_Error(ERR_FATAL, "\x15", "Com_SessionMode_ResetModes: Can not reset the modes when in backup block!");
	}
	G_ExitAfterConnectPaths();
	sSessionModeState &= ~4u;
	if (bInBackupState_0)
		Com_Error(ERR_FATAL, "\x15", "Com_SessionMode_ResetModes: Can not reset the modes when in backup block!");
	G_ExitAfterConnectPaths();
	sSessionModeState &= ~8u;
	if (bInBackupState_0)
		Com_Error(ERR_FATAL, "\x15", "Com_SessionMode_ResetModes: Can not reset the modes when in backup block!");
	G_ExitAfterConnectPaths();
	sSessionModeState &= ~2u;
	if (bInBackupState_0)
		Com_Error(ERR_FATAL, "\x15", "Com_SessionMode_ResetModes: Can not reset the modes when in backup block!");
	G_ExitAfterConnectPaths();
	sSessionModeState &= ~1u;
}

/*
==============
Com_SessionMode_SetOnlineGame
==============
*/
void Com_SessionMode_SetOnlineGame(bool onlineGame)
{
	if (bInBackupState_0)
		Com_Error(ERR_FATAL, "\x15", "Com_SessionMode_SetOnlineGame: Can not reset the modes when in backup block!");
	G_ExitAfterConnectPaths();
	if (onlineGame)
		sSessionModeState |= 4u;
	else
		sSessionModeState &= ~4u;
}

/*
==============
Com_SessionMode_IsPublicBotGame
==============
*/
bool Com_SessionMode_IsPublicBotGame()
{
	return (sSessionModeState & 0x10) == 0 && (sSessionModeState & 4) != 0 && (sSessionModeState & 8) == 0 && Dvar_GetInt(bot_enemies) > 0;
}

