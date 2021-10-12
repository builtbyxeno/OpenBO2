#include "types.h"
#include "vars.h"
#include <qcommon/qcommon_public.h>
#include <qcommon/cmd.h>
#include <win32/win32_public.h>
#include <server_mp/server_mp_public.h>
#include <client/client_public.h>
#include <live/live_public.h>
#include <game/game_public.h>
#include <demo/demo_public.h>

char info1[1024];
char info2[20480];

/*
==============
TRACK_dvar_cmds
==============
*/
void TRACK_dvar_cmds()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Cmd_GetCombinedString
==============
*/
void Cmd_GetCombinedString(char *combined, int first)
{
	int c;
	int l;
	int len;
	int i;

	c = Cmd_Argc();
	*combined = 0;
	l = 0;
	for (i = first; i < c; ++i)
	{
		len = strlen(Cmd_Argv(i)) + 1;
		if (len + l >= 4094)
		{
			break;
		}

		I_strncat(combined, 4096, Cmd_Argv(i));
		if (i != c - 1)
		{
			I_strncat(combined, 4096, " ");
		}
		l += len;
	}
}

/*
==============
Dvar_Command
==============
*/
int Dvar_Command()
{
	DvarLimits limits;
	char combined[4096];
	dvar_t* dvar;

	dvar = Dvar_FindVar(Cmd_Argv(0));
	if (!dvar)
	{
		return 0;
	}

	else if (Cmd_Argc() == 1)
	{
		Com_Printf(0, "\"%s\" is: \"%s^7\" default: \"%s^7\"\n", dvar->name, Dvar_DisplayableValue(dvar),
			Dvar_DisplayableResetValue(dvar));

		if (Dvar_HasLatchedValue(dvar))
		{
			Com_Printf(0, "latched: \"%s\"\n", Dvar_DisplayableLatchedValue(dvar));
		}

		limits.integer64.min = dvar->domain.integer64.min;
		limits.integer64.max = dvar->domain.integer64.max;
		Dvar_PrintDomain(dvar->type, limits);

		return 1;
	}
	else
	{
		Cmd_GetCombinedString(combined, 1);
		Dvar_SetCommand(Cmd_Argv(0), combined);

		return 1;
	}
}

/*
==============
Dvar_ToggleSimple
==============
*/
bool Dvar_ToggleSimple(dvar_t *dvar)
{
	bool Bool;
	float domain_value_min;
	float domain_value_max;
	int DomainIntMax;
	int DomainIntMin;
	int DomainEnumStringCount;
	__int64 DomainInt64Min;
	__int64 DomainInt64Max;

	assert(dvar);

	switch (Dvar_GetType(dvar))
	{
	case DVAR_TYPE_BOOL:
		Bool = Dvar_GetBool(dvar);
		Dvar_SetBoolFromSource(dvar, !Bool, DVAR_SOURCE_EXTERNAL);
		return true;
	case DVAR_TYPE_FLOAT:
		domain_value_min = Dvar_GetDomainFloatMin(dvar);
		domain_value_max = Dvar_GetDomainFloatMax(dvar);
		if (domain_value_min > 0.0 || domain_value_max < 1.0)
		{
			if (Dvar_GetFloat(dvar) == domain_value_min)
				Dvar_SetFloatFromSource(dvar, domain_value_max, DVAR_SOURCE_EXTERNAL);
			else
				Dvar_SetFloatFromSource(dvar, domain_value_min, DVAR_SOURCE_EXTERNAL);
		}
		else if (Dvar_GetFloat(dvar) == 0.0)
		{
			Dvar_SetFloatFromSource(dvar, 1.0, DVAR_SOURCE_EXTERNAL);
		}
		else
			Dvar_SetFloatFromSource(dvar, 0.0, DVAR_SOURCE_EXTERNAL);
		return true;
	case DVAR_TYPE_FLOAT_2:
	case DVAR_TYPE_FLOAT_3:
	case DVAR_TYPE_FLOAT_4:
	case DVAR_TYPE_STRING:
	case DVAR_TYPE_COLOR:
	case DVAR_TYPE_LINEAR_COLOR_RGB:
	case DVAR_TYPE_COLOR_XYZ:
		Com_Printf(0, "'toggle' with no arguments makes no sense for dvar '%s'\n", Dvar_GetName(dvar));
		return false;
	case DVAR_TYPE_INT:
		DomainIntMax = Dvar_GetDomainIntMax(dvar);
		DomainIntMin = Dvar_GetDomainIntMin(dvar);
		if (DomainIntMin > 0 || DomainIntMax < 1)
		{
			if (Dvar_GetInt(dvar) == DomainIntMin)
				Dvar_SetIntFromSource(dvar, DomainIntMax, DVAR_SOURCE_EXTERNAL);
			else
				Dvar_SetIntFromSource(dvar, DomainIntMin, DVAR_SOURCE_EXTERNAL);
		}
		else
		{
			if (Dvar_GetInt(dvar))
				Dvar_SetIntFromSource(dvar, 0, DVAR_SOURCE_EXTERNAL);
			else
				Dvar_SetIntFromSource(dvar, 1, DVAR_SOURCE_EXTERNAL);
		}
		return true;
	case DVAR_TYPE_ENUM:
		DomainEnumStringCount = Dvar_GetDomainEnumStringCount(dvar);
		if (DomainEnumStringCount)
		{
			Dvar_SetIntFromSource(dvar, (Dvar_GetInt(dvar) + 1) % DomainEnumStringCount, DVAR_SOURCE_EXTERNAL);
		}
		return true;
	case DVAR_TYPE_INT64:
		DomainInt64Min = Dvar_GetDomainInt64Min(dvar);
		DomainInt64Max = Dvar_GetDomainInt64Max(dvar);
		domain_value_max = DomainInt64Max;
		if (DomainInt64Min > 0 || DomainInt64Max <= 0)
		{
			if (Dvar_GetInt64(dvar) == DomainInt64Min)
				Dvar_SetInt64FromSource(dvar, domain_value_max, DVAR_SOURCE_EXTERNAL);
			else
				Dvar_SetInt64FromSource(dvar, DomainInt64Min, DVAR_SOURCE_EXTERNAL);
		}
		else
		{
			if (Dvar_GetInt64(dvar))
				Dvar_SetInt64FromSource(dvar, 0i64, DVAR_SOURCE_EXTERNAL);
			else
				Dvar_SetInt64FromSource(dvar, 1i64, DVAR_SOURCE_EXTERNAL);
		}
		return true;
	default:
		Com_Printf(0, "unhandled case %i\n", Dvar_GetType(dvar));
		return false;
	}
}

/*
==============
Dvar_ToggleInternal
==============
*/
bool Dvar_ToggleInternal()
{
	const char* string;
	int argIndex;
	const char* argString;
	const char* dvarName;
	dvar_t* dvar;
	const char* enumString;

	if (Cmd_Argc() < 2)
	{
		assert(Cmd_Argv(0));
		Com_Printf(0, "USAGE: %s <variable> <optional value sequence>\n", Cmd_Argv(0));
		return 0;
	}

	dvarName = Cmd_Argv(1);
	assert(dvarName);
	dvar = Dvar_FindVar(dvarName);
	if (!dvar)
	{
		Com_Printf(0, "toggle failed: dvar '%s' not found.\n", dvarName);
		return 0;
	}

	if (Cmd_Argc() != 2)
	{
		string = Dvar_DisplayableValue(dvar);
		for (argIndex = 2; argIndex + 1 < Cmd_Argc(); ++argIndex)
		{
			argString = Cmd_Argv(argIndex);
			if (dvar->type == DVAR_TYPE_ENUM)
			{
				enumString = Dvar_IndexStringToEnumString(dvar, argString);
				if (strlen(enumString))
				{
					argString = (char*)enumString;
				}
			}
			if (!I_stricmp(string, argString))
			{
				Dvar_SetCommand(dvarName, Cmd_Argv(argIndex + 1));
				return 1;
			}
		}

		argString = Cmd_Argv(2);
		if (dvar->type == DVAR_TYPE_ENUM)
		{
			enumString = Dvar_IndexStringToEnumString(dvar, argString);
			if (strlen(enumString))
			{
				argString = (char*)enumString;
			}
		}
		Dvar_SetCommand(dvarName, argString);

		return 1;
	}

	return Dvar_ToggleSimple(dvar);
}

/*
==============
Dvar_Toggle_f
==============
*/
bool Dvar_Toggle_f()
{
	return Dvar_ToggleInternal();
}

/*
==============
Dvar_TogglePrint_f
==============
*/
void Dvar_TogglePrint_f()
{
	const char* string;
	const char* dvarName;
	dvar_t* dvar;

	if (Dvar_ToggleInternal())
	{
		assertMsg((Cmd_Argc() >= 2), "(Cmd_Argc()) = %i", Cmd_Argc());
		dvarName = Cmd_Argv(1);
		assert(dvarName);
		dvar = Dvar_FindVar(dvarName);

		assert(dvar);
		string = Dvar_DisplayableValue(dvar);

		assert(string);
		Com_Printf(0, "%s toggled to %s\n", dvarName, string);
	}
}

/*
==============
Dvar_Set_f
==============
*/
void Dvar_Set_f()
{
	char combined[4096];
	const char* dvarName;

	if (Cmd_Argc() >= 3)
	{
		dvarName = Cmd_Argv(1);
		if (Dvar_IsValidName(dvarName))
		{
			Cmd_GetCombinedString(combined, 2);
			Dvar_SetCommand(Cmd_Argv(1), combined);
		}
		else
		{
			Com_Printf(0, "invalid variable name: %s\n", Cmd_Argv(1));
		}
	}
	else
	{
		Com_Printf(0, "USAGE: set <variable> <value>\n");
	}
}

/*
==============
Dvar_RegisterBool_f
==============
*/
void Dvar_RegisterBool_f()
{
	const char* dvarName;
	dvar_t* dvar;
	bool value;

	if (Cmd_Argc() == 3)
	{
		dvarName = Cmd_Argv(1);
		value = atoi(Cmd_Argv(2)) != 0;
		dvar = Dvar_FindVar(dvarName);
		if (dvar && (dvar->type != 7 || !(dvar->flags & 0x4000)))
		{
			if (dvar->type)
			{
				Com_Printf(0, "dvar '%s' is not a boolean dvar\n", dvar->name);
			}
		}
		else
		{
			_Dvar_RegisterBool(dvarName, value, 0x4000u, "External Dvar");
		}
	}
	else
	{
		Com_Printf(0, "USAGE: %s <name> <default>\n", Cmd_Argv(0));
	}
}

/*
==============
Dvar_RegisterInt_f
==============
*/
void Dvar_RegisterInt_f()
{
	int max;
	int min;
	int value;
	const char* name;
	dvarType_t Type;
	dvar_t* Var;

	if (Cmd_Argc() == 4)
	{
		name = Cmd_Argv(1);
		value = atoi(Cmd_Argv(2));
		min = atoi(Cmd_Argv(3));
		max = atoi(Cmd_Argv(4));
		if (min > max)
		{
			Com_Printf(0, "dvar %s: min %i should not be greater than max %i\n", name, min, max);
			return;
		}
		Var = Dvar_FindVar(name);
		Type = Dvar_GetType(Var);
		if (!Var)
		{
			_Dvar_RegisterInt(name, value, min, max, 0x4000u, "External Dvar");
			return;
		}
		if (Type == DVAR_TYPE_STRING)
		{
			if ((Dvar_GetFlags(Var) & 0x4000) != 0)
			{
				_Dvar_RegisterInt(name, value, min, max, 0x4000u, "External Dvar");
				return;
			}
			name = Dvar_GetName(Var);
			Com_Printf(0, "dvar '%s' is not an integer dvar\n", name);
			return;
		}
		if (Type != DVAR_TYPE_INT && Type != DVAR_TYPE_ENUM)
		{
			name = Dvar_GetName(Var);
			Com_Printf(0, "dvar '%s' is not an integer dvar\n", name);
			return;
		}
	}
	else
	{
		Com_Printf(0, "USAGE: %s <name> <default> <min> <max>\n", Cmd_Argv(0));
		return;
	}
}

/*
==============
Dvar_RegisterFloat_f
==============
*/
void Dvar_RegisterFloat_f()
{
	float max;
	float min;
	float value;
	const char* name;
	dvarType_t Type;
	dvar_t* Var;

	if (Cmd_Argc() == 4)
	{
		name = Cmd_Argv(1);
		value = atof(Cmd_Argv(2));
		min = atof(Cmd_Argv(3));
		max = atof(Cmd_Argv(4));
		if (min > max)
		{
			Com_Printf(0, "dvar %s: min %g should not be greater than max %g\n", name, min, max);
			return;
		}
		Var = Dvar_FindVar(name);
		Type = Dvar_GetType(Var);
		if (!Var)
		{
			_Dvar_RegisterFloat(name, value, min, max, 0x4000u, "External Dvar");
			return;
		}
		if (Type == DVAR_TYPE_STRING)
		{
			if ((Dvar_GetFlags(Var) & 0x4000) != 0)
			{
				_Dvar_RegisterFloat(name, value, min, max, 0x4000u, "External Dvar");
				return;
			}
			name = Dvar_GetName(Var);
			Com_Printf(0, "dvar '%s' is not an float dvar\n", name);
			return;
		}
		if (Type != DVAR_TYPE_FLOAT)
		{
			name = Dvar_GetName(Var);
			Com_Printf(0, "dvar '%s' is not an float dvar\n", name);
			return;
		}
	}
	else
	{
		Com_Printf(0, "USAGE: %s <name> <default> <min> <max>\n", Cmd_Argv(0));
		return;
	}
}

/*
==============
Dvar_RegisterColor_f
==============
*/
void Dvar_RegisterColor_f()
{
	dvar_t* Var;
	const char* name;
	float r, g, b, a;

	int argc = Cmd_Argc();
	if (argc == 5 || 6)
	{
		name = Cmd_Argv(1);
		r = atof(Cmd_Argv(2));
		g = atof(Cmd_Argv(3));
		b = atof(Cmd_Argv(4));
		if (argc == 6)
			a = atof(Cmd_Argv(5));
		else
			a = 1.0;
		Var = Dvar_FindVar(name);
		if (!Var || Dvar_GetType(Var) == DVAR_TYPE_STRING && (Dvar_GetFlags(Var) & 0x4000) != 0)
			_Dvar_RegisterColor(name, r, g, b, a, 0x4000u, "External Dvar");
	}
	else
	{
		Com_Printf(0, "USAGE: %s <name> <r> <g> <b> [a]\n", Cmd_Argv(0));
	}
}

/*
==============
Dvar_SetA_f
==============
*/
void Dvar_SetA_f()
{
	const char* name;
	dvar_t* Var;

	if (Cmd_Argc() == 3)
	{
		Dvar_Set_f();
		name = Cmd_Argv(1);
		Var = Dvar_FindVar(name);
		if (Var)
			Dvar_AddFlags(Var, 1);
	}
	else
		Com_Printf(0, "USAGE: seta <variable> <value>\n");
}

/*
==============
Dvar_SetToTime_f
==============
*/
void Dvar_SetToTime_f()
{
	const char* name;

	if (Cmd_Argc() == 2)
	{
		name = Cmd_Argv(1);
		if (Dvar_IsValidName(name))
		{
			Dvar_SetCommand(Cmd_Argv(1), va("%i", Sys_Milliseconds()));
		}
		else
		{
			Com_Printf(0, "invalid variable name: %s\n", Cmd_Argv(1));
		}
	}
	else
	{
		Com_Printf(0, "USAGE: set <variable>\n");
	}
}

/*
==============
Dvar_Reset_f
==============
*/
void Dvar_Reset_f()
{
	dvar_t* Var;

	if (Cmd_Argc() == 2)
	{
		Var = Dvar_FindVar(Cmd_Argv(1));
		if (Var)
			Dvar_Reset(Var, DVAR_SOURCE_EXTERNAL);
	}
	else
	{
		Com_Printf(0, "USAGE: reset <variable>\n");
	}
}

/*
==============
Dvar_WriteSingleVariable
==============
*/
void Dvar_WriteSingleVariable(const dvar_t *dvar, void *userData)
{
	int f;

	if (I_stricmp(Dvar_GetName(dvar), "cl_cdkey"))
	{
		if ((Dvar_GetFlags(dvar) & 1))
		{
			f = *(int*)userData;
			FS_Printf(f, "seta %s \"%s\"\n", Dvar_GetName(dvar), Dvar_DisplayableLatchedValue(dvar));
		}
	}
}

/*
==============
Dvar_WriteVariables
==============
*/
void Dvar_WriteVariables(int f)
{
	Dvar_ForEach(Dvar_WriteSingleVariable, &f);
}

/*
==============
Dvar_WriteSingleDefault
==============
*/
void Dvar_WriteSingleDefault(const dvar_t *dvar, void *userData)
{
	int f;

	if (I_stricmp(Dvar_GetName(dvar), "cl_cdkey"))
	{
		if ((Dvar_GetFlags(dvar) & 0x40C0 == 0))
		{
			f = *(int*)userData;
			FS_Printf(f, "set %s \"%s\"\n", Dvar_GetName(dvar), Dvar_DisplayableResetValue(dvar));
		}
	}
}

/*
==============
Dvar_WriteDefaults
==============
*/
void Dvar_WriteDefaults(int f)
{
	Dvar_ForEach(Dvar_WriteSingleDefault, &f);
}

/*
==============
Dvar_ListSingle
==============
*/
void Dvar_ListSingle(const dvar_t *dvar, void *userData)
{
	const char* name;
	__int16 Flags;

	if (!userData || (name = Dvar_GetName(dvar), Com_Filter((const char*)userData, name, 0)))
	{
		Flags = Dvar_GetFlags(dvar);
		if ((Flags & 0x404) != 0)
			Com_Printf(0, "S,");
		else
			Com_Printf(0, " ,");
		if ((Flags & 2) != 0)
			Com_Printf(0, "U,");
		else
			Com_Printf(0, " ,");
		if ((Flags & 0x40) != 0)
			Com_Printf(0, "R,");
		else
			Com_Printf(0, " ,");
		if ((Flags & 0x10) != 0)
			Com_Printf(0, "I,");
		else
			Com_Printf(0, " ,");
		if ((Flags & 1) != 0)
			Com_Printf(0, "A,");
		else
			Com_Printf(0, " ,");
		if ((Flags & 0x20) != 0)
			Com_Printf(0, "L,");
		else
			Com_Printf(0, " ,");
		if ((Flags & 0x80u) == 0)
			Com_Printf(0, " ,");
		else
			Com_Printf(0, "C,");
		if ((Flags & 8) != 0)
			Com_Printf(0, "Y,");
		else
			Com_Printf(0, " ,");
		if ((Flags & 0x100) != 0)
			Com_Printf(0, "D,");
		else
			Com_Printf(0, " ,");
		Com_Printf(0, " ,");
		if ((Flags & 0x8000) != 0)
			Com_Printf(0, "X,");
		else
			Com_Printf(0, " ,");
		if ((Flags & 0x4000) != 0)
			Com_Printf(0, "E,");
		else
			Com_Printf(0, " ,");
		if ((Flags & 0x1000) != 0)
			Com_Printf(0, "V,");
		else
			Com_Printf(0, " ,");
		Com_Printf(0, "%s,\"%s\"\n", Dvar_GetName(dvar), Dvar_DisplayableValue(dvar));
	}
}

/*
==============
Dvar_List_f
==============
*/
void Dvar_List_f()
{
	const char* match;

	if (Cmd_Argc() <= 1)
	{
		Dvar_ForEach(Dvar_ListSingle, NULL);
	}
	else
	{
		match = Cmd_Argv(1);
		Dvar_ForEach(Dvar_ListSingle, (void*)match);
	}
	Com_Printf(0, "\n%i total dvars\n", g_dvarCount);
}

/*
==============
Com_DvarDumpSingle
==============
*/
void Com_DvarDumpSingle(const dvar_t *dvar, void *userData)
{
	DvarDumpInfo* dumpInfo;
	char message[2048];

	dumpInfo = (DvarDumpInfo*)userData;

	++dumpInfo->count;
	if (!dumpInfo->match || Com_Filter(dumpInfo->match, dvar->name, 0))
	{
		if (Dvar_HasLatchedValue(dvar))
		{
			Com_sprintf(message, 2048, "      %s \"%s\" -- latched \"%s\"\n", dvar->name,
				Dvar_DisplayableValue(dvar), Dvar_DisplayableLatchedValue(dvar));
		}
		else
		{
			Com_sprintf(message, 2048, "      %s \"%s\"\n", dvar->name, Dvar_DisplayableValue(dvar));
		}
		Com_PrintMessage(dumpInfo->channel, message, 0);
	}
}

/*
==============
Com_DvarDump
==============
*/
void Com_DvarDump(int channel, const char *match)
{
	DvarDumpInfo dumpInfo;
	char summary[128];

	if (channel != CON_CHANNEL_LOGFILEONLY || com_logfile && com_logfile->current.integer)
	{
		Com_PrintMessage(channel, "=============================== DVAR DUMP ========================================\n", 0);
		dumpInfo.count = 0;
		dumpInfo.channel = channel;
		dumpInfo.match = match;
		Dvar_ForEach(Com_DvarDumpSingle, &dumpInfo);
		Com_sprintf(summary, 128, "\n%i total dvars\n%i dvar indexes\n", dumpInfo.count, g_dvarCount);
		Com_PrintMessage(channel, summary, 0);
		Com_PrintMessage(
			channel,
			"=============================== END DVAR DUMP =====================================\n",
			0);
	}
}

/*
==============
Dvar_Dump_f
==============
*/
void Dvar_Dump_f()
{
	const char* match;

	if (Cmd_Argc() <= 1)
	{
		Com_DvarDump(0, NULL);
	}
	else
	{
		match = Cmd_Argv(1);
		Com_DvarDump(0, match);
	}
}

/*
==============
SV_SetConfigDvar
==============
*/
void SV_SetConfigDvar(const dvar_t *dvar, void *userData)
{
	DvarSetConfigInfo info;

	info = *(DvarSetConfigInfo*)userData;

	if (info.bit & Dvar_GetFlags(dvar))
	{
		SV_SetConfigValueForKey(info.start, info.max, dvar->name, Dvar_DisplayableValue(dvar));
	}
}

/*
==============
SV_SetConfig
==============
*/
void SV_SetConfig(int start, int max, int bit)
{
	DvarSetConfigInfo info;

	info.start = start;
	info.max = max;
	info.bit = bit;
	Dvar_ForEach(SV_SetConfigDvar, &info);
}

/*
==============
Dvar_InfoStringSingle
==============
*/
void Dvar_InfoStringSingle(const dvar_t *dvar, void *userData)
{
	if ((Dvar_GetFlags(dvar) & *(int*)userData))
	{
		Info_SetValueForKey(info1, Dvar_GetName(dvar), Dvar_DisplayableValue(dvar));
	}
}

/*
==============
Dvar_InfoStringSingle_Big
==============
*/
void Dvar_InfoStringSingle_Big(const dvar_t *dvar, void *userData)
{
	if (Dvar_GetFlags(dvar) & *(int*)userData)
	{
		Info_SetValueForKey_Big(info2, Dvar_GetName(dvar), Dvar_DisplayableValue(dvar));
	}
}

/*
==============
Dvar_InfoString
==============
*/
char *Dvar_InfoString(LocalClientNum_t localClientNum, int bit)
{
	ControllerIndex_t ControllerIndex;
	const char* Username;
	const char* Name;
	char* XuidString;
	bdNATType LocalNatType;
	int AvailableContentPacks;
	__int64 UserSteamIDAsXUID;
	int ZombieLastDaysPlayed;
	unsigned __int64 leagueTeamID;
	unsigned __int64 subdivisionID;
	int memberCount;
	unsigned __int64 teamID;
	char rank[4];
	char lastDaysPlayed[4];
	int divisionID;
	char prestige[4];
	char natType[2];
	LeagueStats stats;
	char clientSteamIDStr[32];
	char availableMapPackFlags[21];
	char xPGroupMask[21];
	char idstr[21];
	char content_available[6];

	info1[0] = 0;
	Dvar_ForEach(Dvar_InfoStringSingle, &bit);
	if ((bit & 2) != 0 && !G_ExitAfterConnectPaths())
	{
		ControllerIndex = Com_LocalClient_GetControllerIndex(localClientNum);
		Username = (const char*)CL_ControllerIndex_GetUsername(ControllerIndex);
		Info_SetValueForKey(info1, "name", Username);
		Name = (const char*)Clan_GetName();
		Info_SetValueForKey(info1, "clanAbbrev", Name);
		XuidString = CL_ControllerIndex_GetXuidString(ControllerIndex);
		Info_SetValueForKey(info1, "xuid", XuidString);
		LocalNatType = Live_GetLocalNatType();
		Com_sprintf(natType, 2, "%i", LocalNatType);
		Info_SetValueForKey(info1, "natType", natType);
		Com_sprintf(rank, 4, "%i", LiveStats_GetRank(ControllerIndex));
		if (Com_SessionMode_IsZombiesGame())
		{
			ZombieLastDaysPlayed = LiveStats_GetZombieLastDaysPlayed(ControllerIndex);
			Com_sprintf(lastDaysPlayed, 4, "%i", ZombieLastDaysPlayed);
		}
		else
		{
			Com_sprintf(prestige, 4, "%i", LiveStats_GetPrestige(ControllerIndex));
		}
		Info_SetValueForKey(info1, "rank", rank);
		if (Com_SessionMode_IsZombiesGame())
			Info_SetValueForKey(info1, "lastdaysplayed", lastDaysPlayed);
		else
			Info_SetValueForKey(info1, "prestige", prestige);
		teamID = LiveElite_GetTeamID(ControllerIndex);
		XUIDToString(&teamID, idstr);
		Info_SetValueForKey(info1, "teamid", idstr);
		bool validatedClanN = !LiveElite_IsClanAbbrevValidated(ControllerIndex);
		char* validatedClanChar = "1";
		if (validatedClanN)
			validatedClanChar = "0";
		Info_SetValueForKey(info1, "clanAbbrevEV", validatedClanChar);
		char* splitScreen;
		if (CL_LocalClient_GetActiveCount() <= 1 || (validatedClanN = !CL_LocalClient_IsSplitscreen(), splitScreen = "1", !validatedClanN))
			splitScreen = "0";
		Info_SetValueForKey(info1, "secondScreenClient", splitScreen);
		Com_sprintf(xPGroupMask, 21, "%i", Live_DoubleXPGetGroupMaskForController(ControllerIndex));
		Info_SetValueForKey(info1, "xPGroupMask", xPGroupMask);
		AvailableContentPacks = Content_GetAvailableContentPacks();
		Com_sprintf(availableMapPackFlags, 21, "%i", AvailableContentPacks);
		if (Dvar_GetBool(tu11_AddMapPackFlagsUserInfo) && Demo_IsVersionAtLeast(12))
			Info_SetValueForKey(info1, "availableMapPackFlags", availableMapPackFlags);
		if (Com_SessionMode_IsZombiesGame())
		{
			Com_sprintf(content_available, 6, "%i", Content_GetAvailableContentPacks());
			Info_SetValueForKey(info1, "contentAvailable", content_available);
		}
		if (Com_GameMode_IsMode(GAMEMODE_LEAGUE_MATCH))
		{
			if (League_GetCurrentTeamID(ControllerIndex, &leagueTeamID, &memberCount, &subdivisionID, &divisionID))
			{
				XUIDToString(&leagueTeamID, idstr);
				Info_SetValueForKey(info1, "leagueteamid", idstr);
				XUIDToString(&subdivisionID, idstr);
				Info_SetValueForKey(info1, "subdivisionid", idstr);
				Info_SetValueForKey(info1, "divisionid", va("%d", divisionID));
				if (League_GetCurrentStats(ControllerIndex, &stats))
				{
					Info_SetValueForKey(info1, "subdivisionrank", va("%d", stats.rank));
				}
				else
				{
					Info_SetValueForKey(info1, "subdivisionrank", "0");
				}
			}
			else
			{
				Com_Error(ERR_DROP, "Attempting to join league game but league data is not available");
			}
		}
		UserSteamIDAsXUID = LiveSteam_GetUserSteamIDAsXUID();
		Int64ToString(UserSteamIDAsXUID, clientSteamIDStr);
		Info_SetValueForKey(info1, "steamid", clientSteamIDStr);
	}
	return info1;
}

/*
==============
Dvar_InfoString_Big
==============
*/
char *Dvar_InfoString_Big(int bit)
{
	info2[0] = 0;
	Dvar_ForEach(Dvar_InfoStringSingle_Big, &bit);
	return info2;
}

/*
==============
Dvar_AddConfigFlag_f
==============
*/
void Dvar_AddConfigFlag_f()
{
	dvar_t* Var;

	if (Cmd_Argc() == 2)
	{
		Var = Dvar_FindVar(Cmd_Argv(1));
		if (Var)
		{
			Dvar_AddFlags(Var, 0x20000);
		}
	}
}

/*
==============
Dvar_ListByCount_f
==============
*/
void Dvar_ListByCount_f()
{
	;
}

/*
==============
Dvar_AddCommands
==============
*/
void Dvar_AddCommands()
{
	Cmd_AddCommandInternal("toggle", (void(__cdecl*)())Dvar_Toggle_f, &Dvar_Toggle_f_VAR);
	Cmd_AddCommandInternal("togglep", Dvar_TogglePrint_f, &Dvar_TogglePrint_f_VAR);
	Cmd_AddCommandInternal("set", Dvar_Set_f, &Dvar_Set_f_VAR);
	Cmd_AddCommandInternal("seta", Dvar_SetA_f, &Dvar_SetA_f_VAR);
	Cmd_AddCommandInternal("setdvartotime", Dvar_SetToTime_f, &Dvar_SetToTime_f_VAR);
	Cmd_AddCommandInternal("reset", Dvar_Reset_f, &Dvar_Reset_f_VAR);
	Cmd_AddCommandInternal("dvarlist", Dvar_List_f, &Dvar_List_f_VAR);
	Cmd_AddCommandInternal("dvardump", Dvar_Dump_f, &Dvar_Dump_f_VAR);
	Cmd_AddCommandInternal("dvar_bool", Dvar_RegisterBool_f, &Dvar_RegisterBool_f_VAR);
	Cmd_AddCommandInternal("dvar_int", Dvar_RegisterInt_f, &Dvar_RegisterInt_f_VAR);
	Cmd_AddCommandInternal("dvar_float", Dvar_RegisterFloat_f, &Dvar_RegisterFloat_f_VAR);
	Cmd_AddCommandInternal("dvar_color", Dvar_RegisterColor_f, &Dvar_RegisterColor_f_VAR);
	Cmd_AddCommandInternal("dvarAddConfigFlag", Dvar_AddConfigFlag_f, &Dvar_AddConfigFlag_f_VAR);
	Cmd_AddCommandInternal("restoreDvars", NULL, &Dvar_RestoreDvars_VAR);
	Cmd_AddCommandInternal("dvarListByCount", Dvar_ListByCount_f, &Dvar_ListByCount_f_VAR);
}

