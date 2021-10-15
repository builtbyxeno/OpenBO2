#include "types.h"
#include "vars.h"
#include <qcommon/qcommon_public.h>
#include <universal/q_shared.h>
#include <qcommon/cmd.h>

cmd_function_s Con_FilterList_f_VAR;
cmd_function_s Con_FilterRemove_f_VAR;
cmd_function_s Con_FilterAdd_f_VAR;
cmd_function_s Con_ChannelList_f_VAR;

const int CON_MAX_CHANNELS = 256;

static PrintChannelGlob pcGlob;

char con_gameMsgWindowNFilter_Names[4][25];
char con_gameMsgWindowNFilter_Descs[4][91];

const char* defaultGameWindowFilters[4] =
{ "gamenotify obituary", "boldgame", "subtitle", "objnotify" };


const char* builtinChannels[52] =
{
  "dontfilter",
  "error",
  "gamenotify",
  "boldgame",
  "objnotify",
  "subtitle",
  "obituary",
  "coop",
  "logonly",
  "cononly",
  "system",
  "network",
  "task",
  "gfx",
  "sound",
  "file",
  "ui",
  "ai",
  "anim",
  "physics",
  "fx",
  "script",
  "tl",
  "perf",
  "devgui",
  "client",
  "server",
  "playerweap",
  "live",
  "fromscript",
  "spawn",
  "ldrboards",
  "ddl",
  "spu",
  "userprofile",
  "presence",
  "rumble",
  "unlockables",
  "voip",
  "http",
  "gfwl",
  "ipak",
  "webm",
  "prober",
  "mipster",
  "steam",
  "social",
  "dcache",
  "streamer",
  "scheduler",
  "matchrecord",
  "migrate"
};

/*
==============
Con_OpenChannel
==============
*/
bool Con_OpenChannel(const char *name, bool allowScript)
{
	int index;
	bool alreadyExists;

	alreadyExists = 0;
	for (index = 0; index < 256 && pcGlob.openChannels[index].name[0]; ++index)
	{
		if (!I_strnicmp(pcGlob.openChannels[index].name, name, 32))
		{
			alreadyExists = 1;
			break;
		}
	}
	if (index >= 256)
	{
		return 0;
	}
	if (!alreadyExists)
	{
		I_strncpyz(pcGlob.openChannels[index].name, name, 32);
		pcGlob.openChannels[index].allowScript = allowScript;
	}
	return 1;
}

/*
==============
Con_ScriptHasPermission
==============
*/
bool Con_ScriptHasPermission(int channel)
{
	if (channel <= 0xFF && pcGlob.openChannels[channel].name[0])
	{
		return pcGlob.openChannels[channel].allowScript;
	}
	else
	{
		return 0;
	}
}

/*
==============
Con_GetChannel
==============
*/
BOOL Con_GetChannel(const char *name, int *channel_result)
{
	int channel;

	for (channel = 0; channel < 256; ++channel)
	{
		if (pcGlob.openChannels[channel].name[0] && !I_stricmp(name, pcGlob.openChannels[channel].name))
		{
			*channel_result = channel;
			return channel < 256;
		}
	}
	return channel < 256;
}

/*
==============
Con_IsChannelOpen
==============
*/
bool Con_IsChannelOpen(int channel)
{
	return channel <= 0xFF && pcGlob.openChannels[channel].name[0] != 0;
}

/*
==============
Con_FilterShowChannel
==============
*/
void Con_FilterShowChannel(print_msg_dest_t dest, const char *channelName, bool show)
{
	int channel;
	int count;

	count = 0;
	for (channel = 1; channel < 256; ++channel)
	{
		if (pcGlob.openChannels[channel].name[0] && !I_stricmpwild(channelName, pcGlob.openChannels[channel].name))
		{
			if (show)
			{
				if (!Com_BitCheckAssert(pcGlob.filters[dest], channel, 32))
				{
					Com_BitSetAssert(pcGlob.filters[dest], channel, 32);
					Com_Printf(0, "Adding channel: %s\n", &pcGlob.openChannels[channel]);
					++count;
				}
			}
			else if (Com_BitCheckAssert(pcGlob.filters[dest], channel, 32))
			{
				Com_BitClearAssert(pcGlob.filters[dest], channel, 32);
				Com_Printf(0, "Hiding channel: %s\n", &pcGlob.openChannels[channel]);
				++count;
			}
		}
	}

	if (!count)
	{
		Com_Printf(0, "No channels added or hidden\n");
	}
}

/*
==============
Con_IsChannelVisible
==============
*/
bool Con_IsChannelVisible(print_msg_dest_t dest, int channel, int errorflags)
{
	int error;

	assertMsg((channel >= 0 && channel < CON_MAX_CHANNELS), "(channel) = %i", channel);
	if (!pcGlob.openChannels[channel].name[0])
	{
		return false;
	}

	if (dest == 1)
	{
		if (channel == 2 || channel == 3 || channel == 4)
		{
			return false;
		}
		dest = CON_DEST_CONSOLE;
	}

	if (dest == CON_DEST_CONSOLE && !channel)
	{
		return true;
	}

	if (Com_BitCheckAssert(pcGlob.filters[dest], channel, 32))
	{
		return true;
	}

	error = (errorflags >> 5) & 0x1F;
	return (error == 3 || error == 2) && Com_BitCheckAssert(pcGlob.filters[dest], 1, 32);
}

/*
==============
Con_ChannelList_f
==============
*/
void Con_ChannelList_f()
{
	int channel;

	for (channel = 0; channel < 256; ++channel)
	{
		if (channel)
		{
			if (pcGlob.openChannels[channel].name[0])
			{
				Com_Printf(0, "%s\n", &pcGlob.openChannels[channel]);
			}
		}
	}
}

/*
==============
Con_FilterAdd
==============
*/
void Con_FilterAdd(bool show)
{
	int arg;
	int argc;

	argc = Cmd_Argc();
	if (argc >= 2)
	{
		for (arg = 1; arg < argc; ++arg)
		{
			Con_FilterShowChannel(CON_DEST_CONSOLE, Cmd_Argv(arg), show);
		}
		g_dvar_modifiedFlags |= 1;
	}
	else
	{
		Com_Printf(0, "USAGE: %s <channel>\n<channel> may include wildcards */?\n", Cmd_Argv(0));
	}
}

/*
==============
Con_FilterAdd_f
==============
*/
void Con_FilterAdd_f()
{
	Con_FilterAdd(1);
}

/*
==============
Con_FilterRemove_f
==============
*/
void Con_FilterRemove_f()
{
	Con_FilterAdd(0);
}

/*
==============
Con_FilterList_f
==============
*/
void Con_FilterList_f()
{
	int channel;

	for (channel = 0; channel < 256; ++channel)
	{
		if (channel)
		{
			if (Con_IsChannelVisible(CON_DEST_CONSOLE, channel, 0))
			{
				Com_Printf(0, "%s\n", &pcGlob.openChannels[channel]);
			}
		}
	}
}

/*
==============
Con_WriteFilterConfigString
==============
*/
void Con_WriteFilterConfigString(int f)
{
	int channel;

	FS_Printf(f, "con_hidechannel *; con_showchannel");
	for (channel = 0; channel < 256; ++channel)
	{
		if (Con_IsChannelVisible(CON_DEST_CONSOLE, channel, 0))
		{
			FS_Printf(f, " %s", &pcGlob.openChannels[channel]);
		}
	}
	FS_Printf(f, "\n");
}

/*
==============
Con_InitChannelsForDestFromList
==============
*/
void Con_InitChannelsForDestFromList(print_msg_dest_t dest, const char *channelNames)
{
	char channelName[256];
	unsigned int channelNamesLen;
	unsigned int charIndex;
	unsigned int channelNameLength;
	bool foundChannelName;
	unsigned int channelNameStart;

	assert(channelNames);
	channelNamesLen = strlen(channelNames);
	foundChannelName = 0;
	channelNameStart = 0;
	Con_FilterShowChannel(dest, "*", 0);
	for (charIndex = 0; charIndex <= channelNamesLen; ++charIndex)
	{
		if (channelNames[charIndex] != 32 && channelNames[charIndex] != 44 && channelNames[charIndex])
		{
			if (!foundChannelName)
			{
				channelNameStart = charIndex;
				foundChannelName = 1;
			}
		}
		else if (foundChannelName)
		{
			channelNameLength = charIndex - channelNameStart;
			if (charIndex - channelNameStart + 1 > 0x100)
			{
				Com_Error(ERR_DROP, "Channel name too long in specified list: \"%s\"\n", channelNames);
			}

			memcpy(channelName, &channelNames[channelNameStart], channelNameLength);
			channelName[channelNameLength] = 0;
			Con_FilterShowChannel(dest, channelName, 1);
			foundChannelName = 0;
		}
	}
}

/*
==============
Con_InitGameMsgChannels
==============
*/
void Con_InitGameMsgChannels()
{
	unsigned int gameWindowIndex;
	char* dvarDesc;
	char* dvarName;
	static bool inited = false;

	if (!inited)
	{
		inited = 1;
		for (gameWindowIndex = 0; gameWindowIndex < 4; ++gameWindowIndex)
		{
			dvarName = con_gameMsgWindowNFilter_Names[gameWindowIndex];
			dvarDesc = con_gameMsgWindowNFilter_Descs[gameWindowIndex];
			sprintf(dvarName, "con_gameMsgWindow%dFilter", gameWindowIndex);
			assert(strlen(dvarName) == sizeof(con_gameMsgWindowNFilter_Names[gameWindowIndex]) - 1);

			sprintf(dvarDesc,
				"Space-separated list of console channels that should be displayed in game message window %d",
				gameWindowIndex);

			assert(strlen(dvarDesc) == sizeof(con_gameMsgWindowNFilter_Descs[gameWindowIndex]) - 1);

			con_gameMsgWindowNFilter[gameWindowIndex] = _Dvar_RegisterString(
				con_gameMsgWindowNFilter_Names[gameWindowIndex],
				defaultGameWindowFilters[gameWindowIndex],
				0x21u,
				dvarDesc);
		}

		for (gameWindowIndex = 0; gameWindowIndex < 4; ++gameWindowIndex)
		{
			Con_InitChannelsForDestFromList((print_msg_dest_t)(CON_DEST_GAME_FIRST + gameWindowIndex),
				Dvar_GetString(con_gameMsgWindowNFilter[gameWindowIndex]));
		}
	}
}

/*
==============
Con_InitChannels
==============
*/
void Con_InitChannels()
{
	int i;
	unsigned int channel;

	memset(&pcGlob, 0, sizeof(PrintChannelGlob));
	for (channel = 0; channel < 52; ++channel)
	{
		Con_OpenChannel(builtinChannels[channel], 0);
	}
	pcGlob.openChannels[21].allowScript = 1;
	con_debug_console_filter = _Dvar_RegisterBool("con_debug_console_filter", 0, 0, "Display channel adding/hiding text in the output");
	Con_FilterShowChannel(CON_DEST_CONSOLE, Dvar_GetString(con_default_console_filter), 1);
	Con_FilterShowChannel(CON_DEST_MINICON, "std", 1);
	Con_FilterShowChannel(CON_DEST_MINICON, "error", 1);
	Con_FilterShowChannel(CON_DEST_ERROR, "error", 1);
	for (i = 46; i < 52; ++i)
	{
		Con_FilterShowChannel(CON_DEST_CONSOLE, builtinChannels[i], 0);
	}
	Con_InitGameMsgChannels();
	Cmd_AddCommandInternal("con_channellist", Con_ChannelList_f, &Con_ChannelList_f_VAR);
	Cmd_AddCommandInternal("con_showchannel", Con_FilterAdd_f, &Con_FilterAdd_f_VAR);
	Cmd_AddCommandInternal("con_hidechannel", Con_FilterRemove_f, &Con_FilterRemove_f_VAR);
	Cmd_AddCommandInternal("con_visiblechannellist", Con_FilterList_f, &Con_FilterList_f_VAR);
}

/*
==============
Con_ShutdownChannels
==============
*/
void Con_ShutdownChannels()
{
	int channel;
	unsigned int filter;

	for (channel = 0; channel < 256; ++channel)
	{
		assertIn(channel, CON_MAX_CHANNELS);
		if (pcGlob.openChannels[channel].name[0])
		{
			pcGlob.openChannels[channel].name[0] = 0;
			for (filter = 0; filter < 6; ++filter)
			{
				Com_BitClearAssert(pcGlob.filters[filter], channel, 32);
			}
		}
	}
}

