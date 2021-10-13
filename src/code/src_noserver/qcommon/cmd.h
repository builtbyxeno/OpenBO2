#include "types.h"
#include "vars.h"

extern CmdArgs sv_cmd_args;
extern CmdArgs g_cmd_args[2];

/*
==============
Cmd_Args
==============
*/
inline CmdArgs *Cmd_Args()
{
	CmdArgs* cmd_args;

	cmd_args = (CmdArgs*)Sys_GetValue(THREAD_VALUE_CMD);
	assert(cmd_args != NULL);

	return cmd_args;
}

/*
==============
Cmd_Argc
==============
*/
inline int Cmd_Argc()
{
	CmdArgs* cmd_args;

	cmd_args = Cmd_Args();
	assertIn(cmd_args->nesting, CMD_MAX_NESTING);
	return cmd_args->argc[cmd_args->nesting];
}

/*
==============
Cmd_Argv
==============
*/
inline const char *Cmd_Argv(int argIndex)
{
	CmdArgs* cmd_args;

	cmd_args = Cmd_Args();
	assertIn(cmd_args->nesting, CMD_MAX_NESTING);
	assertMsg((argIndex >= 0), "(argIndex) = %i", argIndex);
	if (argIndex < cmd_args->argc[cmd_args->nesting])
	{
		return cmd_args->argv[cmd_args->nesting][argIndex];
	}

	return "";
}

/*
==============
SV_Cmd_Argc
==============
*/
inline int SV_Cmd_Argc()
{
	assertIn(sv_cmd_args.nesting, CMD_MAX_NESTING);
	return sv_cmd_args.argc[sv_cmd_args.nesting];
}

/*
==============
SV_Cmd_Argv
==============
*/
inline const char *SV_Cmd_Argv(int argIndex)
{
	assertIn(sv_cmd_args.nesting, CMD_MAX_NESTING);
	assertMsg((argIndex >= 0), "(argIndex) = %i", argIndex);
	if (argIndex < sv_cmd_args.argc[sv_cmd_args.nesting])
	{
		return sv_cmd_args.argv[sv_cmd_args.nesting][argIndex];
	}

	return "";
}

/*
==============
Cmd_ItemDef
==============
*/
inline itemDef_s *Cmd_ItemDef()
{
	CmdArgs* cmd_args;

	cmd_args = Cmd_Args();
	assertIn(cmd_args->nesting, CMD_MAX_NESTING);
	return cmd_args->itemDef[cmd_args->nesting];
}

