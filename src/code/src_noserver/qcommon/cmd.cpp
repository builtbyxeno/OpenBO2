#include "types.h"
#include "vars.h"
#include <qcommon/qcommon_public.h>
#include <qcommon/cmd.h>
#include <clientscript/clientscript_public.h>
#include <universal/universal_public.h>
#include <client/client_public.h>
#include <stringed/stringed_public.h>
#include <database/database_public.h>
#include <live/live_public.h>
#include <gfx_d3d/r_pix_profile.h>
#include <server/server_public.h>
#include <server_mp/server_mp_public.h>

static CmdArgs sv_cmd_args;
static CmdArgs g_cmd_args[2];

static unsigned char sv_cmd_text_buf[65536];
static CmdText sv_cmd_text;
static CmdText cmd_textArray[1];
static unsigned char cmd_text_buf[1][65536];
static bool cmd_insideCBufExecute[1];

static cmd_function_s* sv_cmd_functions;
static cmd_function_s* cmd_functions;

static cmd_function_s Cmd_IfMP_f_VAR;
static cmd_function_s Cmd_IfSP_f_VAR;
static cmd_function_s Cmd_ForwardCommand_f_VAR;
static cmd_function_s Cmd_ForwardCommand_f_VAR_0;
static cmd_function_s Cmd_ForwardCommand_f_VAR_1;
static cmd_function_s Cmd_ForwardCommand_f_VAR_2;
static cmd_function_s Cmd_ForwardCommand_f_VAR_3;
static cmd_function_s Cmd_ForwardCommand_f_VAR_4;
static cmd_function_s Cmd_ForwardCommand_f_VAR_5;
static cmd_function_s Cmd_ForwardCommand_f_VAR_6;
static cmd_function_s Cmd_ForwardCommand_f_VAR_7;
static cmd_function_s Cmd_ForwardCommand_f_VAR_8;
static cmd_function_s Cmd_ForwardCommand_f_VAR_9;
static cmd_function_s Cmd_ForwardCommand_f_VAR_10;
static cmd_function_s Cmd_ForwardCommand_f_VAR_11;
static cmd_function_s Cmd_ForwardCommand_f_VAR_12;
static cmd_function_s Cmd_ForwardCommand_f_VAR_13;
static cmd_function_s Cmd_ForwardCommand_f_VAR_14;
static cmd_function_s Cmd_ForwardCommand_f_VAR_15;
static cmd_function_s Cmd_ForwardCommand_f_VAR_16;
static cmd_function_s Cmd_ForwardCommand_f_VAR_17;
static cmd_function_s Cmd_ForwardCommand_f_VAR_18;
static cmd_function_s Cmd_ForwardCommand_f_VAR_19;
static cmd_function_s Cmd_ForwardCommand_f_VAR_20;
static cmd_function_s Cmd_ForwardCommand_f_VAR_21;
static cmd_function_s Cmd_DObjDump_VAR;
static cmd_function_s Cmd_ForwardCommand_f_VAR_22;
static cmd_function_s Cmd_SetZM_f_VAR;
static cmd_function_s Cmd_Wait_f_VAR;
static cmd_function_s Cmd_ExecAddText_f_VAR;
static cmd_function_s Cmd_Exec_f_VAR;
static cmd_function_s Cmd_List_f_VAR;

static int cmd_wait;

/*
==============
TRACK_cmd
==============
*/
void TRACK_cmd()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Cmd_SetZM_f
==============
*/
void Cmd_SetZM_f()
{
	Com_Printf(CON_CHANNEL_SYSTEM, "Cmd_SetZM_f: zombie session mode set!!!!!\n");
	Com_SessionMode_SetMode(SESSIONMODE_ZOMBIES, 1);
}

/*
==============
Cmd_Wait_f
==============
*/
void Cmd_Wait_f()
{
	if (Cmd_Argc() == 2)
	{
		cmd_wait = atoi(Cmd_Argv(1));
	}
	else
	{
		cmd_wait = 1;
	}
}

/*
==============
Cbuf_Init
==============
*/
void Cbuf_Init()
{
	Sys_EnterCriticalSection(CRITSECT_CBUF);
	cmd_textArray[0].data = cmd_text_buf[0];
	cmd_textArray[0].maxsize = 0x10000;
	cmd_textArray[0].cmdsize = 0;
	cmd_insideCBufExecute[0] = 0;
	sv_cmd_text.data = sv_cmd_text_buf;
	sv_cmd_text.maxsize = 0x10000;
	sv_cmd_text.cmdsize = 0;
	Sys_LeaveCriticalSection(CRITSECT_CBUF);
}

/*
==============
Cmd_ShiftArgs
==============
*/
void Cmd_ShiftArgs(int count, CmdArgs *args)
{
	int dest_arg;
	int src_arg;

	if (args->argc[args->nesting] < count)
	{
		count = args->argc[args->nesting];
	}
	else
	{
		count = count;
	}

	src_arg = count;
	dest_arg = 0;
	while (dest_arg < args->argc[args->nesting])
	{
		if (src_arg < args->argc[args->nesting])
		{
			args->argv[args->nesting][dest_arg] = args->argv[args->nesting][src_arg];
		}
		else
		{
			args->argv[args->nesting][dest_arg] = NULL;
		}
		++dest_arg;
		++src_arg;
	}
	args->argshift[args->nesting] += count;
	args->argc[args->nesting] -= count;
}

/*
==============
Cbuf_AddText
==============
*/
void Cbuf_AddText(LocalClientNum_t localClientNum, const char *text)
{
	CmdText* cmd_text;
	int length;

	Sys_EnterCriticalSection(CRITSECT_CBUF);
	if ((*text == 112 || *text == 80) && text[1] >= 48 && text[1] < 49)
	{
		localClientNum = (LocalClientNum_t)(text[1] - 48);
		for (text += 2; *text == 32; ++text)
		{
			;
		}
	}

	cmd_text = &cmd_textArray[localClientNum];
	length = strlen(text);
	if (cmd_text->cmdsize + length < cmd_text->maxsize)
	{
		memcpy(&cmd_text->data[cmd_text->cmdsize], text, length + 1);
		cmd_text->cmdsize += length;
		Scr_MonitorCommand(text, SCRIPTINSTANCE_SERVER);
	}
	else
	{
		Com_Printf(CON_CHANNEL_SYSTEM, "Cbuf_AddText: overflow\n");
	}
	Sys_LeaveCriticalSection(CRITSECT_CBUF);
}

/*
==============
Cbuf_InsertText
==============
*/
void Cbuf_InsertText(LocalClientNum_t localClientNum, const char *text)
{
	CmdText* cmd_text;
	int i;
	int length;

	assertIn(localClientNum, MAX_LOCAL_CLIENTS);
	Sys_EnterCriticalSection(CRITSECT_CBUF);
	cmd_text = &cmd_textArray[localClientNum];

	length = strlen(text) + 1;
	if (length + cmd_text->cmdsize > cmd_text->maxsize)
	{
		Com_PrintError(1, "Cbuf_InsertText overflowed\n");
		Sys_LeaveCriticalSection(CRITSECT_CBUF);
		return;
	}

	// move the existing command text
	for (i = cmd_text->cmdsize - 1; i >= 0; --i)
	{
		cmd_text->data[i + length] = cmd_text->data[i];
	}

	// copy the new text in
	memcpy(cmd_text->data, text, length - 1);

	// add a \n
	cmd_text->data[length - 1] = '\n';

	cmd_text->cmdsize += length;

	Sys_LeaveCriticalSection(CRITSECT_CBUF);
}

/*
==============
Cbuf_AddServerText_f
==============
*/
void Cbuf_AddServerText_f()
{
	assertMsg(false, "Cbuf_AddServerText_f was called.");
}

/*
==============
Cmd_AddServerCommandInternal
==============
*/
void Cmd_AddServerCommandInternal(const char *cmdName, void (*function)(), cmd_function_s *allocedCmd)
{
	cmd_function_s* cmd;

	assert(cmdName);
	for (cmd = sv_cmd_functions; ; cmd = cmd->next)
	{
		if (!cmd)
		{
			allocedCmd->name = cmdName;
			allocedCmd->function = function;
			allocedCmd->next = sv_cmd_functions;
			sv_cmd_functions = allocedCmd;
			return;
		}

		if (!strcmp(cmdName, cmd->name))
		{
			break;
		}
	}

	assert(cmd == allocedCmd);
	if (function)
	{
		Com_Printf(CON_CHANNEL_SYSTEM, "Cmd_AddServerCommand: %s already defined\n", cmdName);
	}
}

/*
==============
Cmd_ExecFromDiskAddText
==============
*/
bool Cmd_ExecFromDiskAddText(LocalClientNum_t localClientNum, ControllerIndex_t controllerIndex, const char *filename)
{
	char* text;

	FS_ReadFile(filename, (void**)&text);
	if (!text)
	{
		Com_Printf(CON_CHANNEL_SYSTEM, "Exec From Disk failed to open %s\n", filename);
		return 0;
	}

	Com_Printf(CON_CHANNEL_SYSTEM, "execing %s from disk to command buffer\n", filename);
	Cbuf_AddText(localClientNum, text);
	FS_FreeFile(text);

	return 1;
}

/*
==============
Cmd_ExecAddText_f
==============
*/
void Cmd_ExecAddText_f()
{
	char filename[128];
	LocalClientNum_t localClientNum;

	if (Cmd_Argc() != 2)
	{
		Com_Printf(0, "exec_addtext <filename> : execute a script file, appending the contents to the command buffer\n");
		return;
	}

	I_strncpyz(filename, Cmd_Argv(1), sizeof(filename));
	Com_DefaultExtension(filename, sizeof(filename), ".cfg");
	localClientNum = (LocalClientNum_t)0;
	if (!Cmd_ExecFromDiskAddText(localClientNum, CONTROLLER_INDEX_0, filename))
	{
		Com_PrintError(1, "couldn't exec %s\n", Cmd_Argv(1));
	}
}

/*
==============
SV_Cmd_ArgvBuffer
==============
*/
void SV_Cmd_ArgvBuffer(int arg, char *buffer, int bufferLength)
{
	I_strncpyz(buffer, SV_Cmd_Argv(arg), bufferLength);
}

/*
==============
Cmd_ArgsBuffer
==============
*/
void Cmd_ArgsBuffer(int start, char *buffer, int bufLength)
{
	CmdArgs* cmd_args;
	const char* src;
	int argIndex;
	const char** argv;
	char* dst;
	int argc;

	cmd_args = Cmd_Args();
	assert(Sys_IsMainThread());
	assert(start >= 0);
	assert(buffer);
	assert(bufLength >= 2);

	dst = buffer;
	bufLength = bufLength - 1;
	argc = cmd_args->argc[cmd_args->nesting];
	argv = cmd_args->argv[cmd_args->nesting];

	for (argIndex = start; argIndex < argc; ++argIndex)
	{
		src = argv[argIndex];
		while (*src)
		{
			*dst++ = *src++;
			bufLength--;
			if (bufLength == 0)
			{
				*dst = 0;
				return;
			}
		}

		if (bufLength == 1)
		{
			*dst = 0;
			return;
		}

		if (argIndex != argc - 1)
		{
			*dst++ = ' ';
			--bufLength;
		}
	}

	*dst = 0;
}

/*
==============
Cmd_IsWhiteSpaceChar
==============
*/
bool Cmd_IsWhiteSpaceChar(char letter)
{
	assert(letter != '\0');
	if (letter == '\x14' || letter == '\x15' || letter == '\x16')
	{
		return 0;
	}

	if ((unsigned char)letter <= 32)
	{
		return Key_IsValidGamePadChar(letter) == 0;
	}

	return 0;
}

/*
==============
Cmd_EmitChar
==============
*/
void Cmd_EmitChar(char letter, CmdArgs *argsPriv)
{
	int size;

	argsPriv->textPool[argsPriv->totalUsedTextPool] = letter;
	size = argsPriv->totalUsedTextPool + 1;
	if (size >= 8190)
		size = 8190;
	argsPriv->totalUsedTextPool = size;
}

/*
==============
Cmd_EmitString
==============
*/
void Cmd_EmitString(const char *str, CmdArgs *argsPriv)
{
	char i;
	unsigned int totalUsedTextPool;

	for (i = *str; i; i = *++str)
	{
		totalUsedTextPool = argsPriv->totalUsedTextPool;
		if (totalUsedTextPool >= 0x1FFF)
			break;
		argsPriv->textPool[totalUsedTextPool] = i;
		++argsPriv->totalUsedTextPool;
	}
	argsPriv->textPool[argsPriv->totalUsedTextPool++] = 0;
}

/*
==============
Cmd_EvaluateExpression
==============
*/
void Cmd_EvaluateExpression(const char **text_in, CmdArgs *argsPriv)
{
	char compileBuffer[3072];
	const char* result;

	assert(text_in);
	assert(*text_in);

	for (result = GetExpressionResultStringCompile((LocalClientNum_t)0, Cmd_ItemDef(), text_in, compileBuffer, 3072); *result; ++result)
	{
		argsPriv->textPool[argsPriv->totalUsedTextPool] = *result;
		if (argsPriv->totalUsedTextPool + 1 < 8190)
		{
			argsPriv->totalUsedTextPool = argsPriv->totalUsedTextPool + 1;
		}
		else
		{
			argsPriv->totalUsedTextPool = 8190;
		}
	}

	argsPriv->textPool[argsPriv->totalUsedTextPool] = 0;
	if (argsPriv->totalUsedTextPool + 1 < 8190)
	{
		argsPriv->totalUsedTextPool = argsPriv->totalUsedTextPool + 1;
	}
	else
	{
		argsPriv->totalUsedTextPool = 8190;
	}
}

/*
==============
Cmd_TokenizeStringInternal
==============
*/
int Cmd_TokenizeStringInternal(const char *text_in, int max_tokens, bool evalExpressions, const char **argv, CmdArgs *argsPriv)
{
	unsigned int locCharCount;
	const char* translatedString;
	char locToken[48];
	const char* text;
	int argc;

	assert(text_in);
	argc = 0;
	text = text_in;
	while (1)
	{
		while (1)
		{
			while (1)
			{
				if (!*text)
				{
					return argc;
				}
				if (!Cmd_IsWhiteSpaceChar(*text))
				{
					break;
				}
				++text;
			}

			if (*text == '/' && text[1] == '/')
			{
				return argc;
			}
			if (*text != 47 || text[1] != 42)
			{
				break;
			}
			for (text += 2; *text && (*text != '*' || text[1] != '/'); ++text)
			{
				;
			}
			if (!*text)
			{
				return argc;
			}
			text += 2;
		}

		argv[argc++] = &argsPriv->textPool[argsPriv->totalUsedTextPool];
		if (!--max_tokens)
		{
			break;
		}

		if (evalExpressions && *text == '(')
		{
			Cmd_EvaluateExpression(&text, argsPriv);
			if (!text || !*text)
			{
				return argc;
			}
		}
		else if (evalExpressions && *text == 64)
		{
			for (locCharCount = 0;
				locCharCount < 0x30 && *text && !Cmd_IsWhiteSpaceChar(*text);
				locToken[locCharCount++] = *text++)
			{
				;
			}
			locToken[locCharCount] = 0;
			translatedString = SEH_StringEd_GetString(&locToken[1]);
			if (translatedString)
			{
				Cmd_EmitString(translatedString, argsPriv);
			}
			else
			{
				Cmd_EmitString(locToken, argsPriv);
			}
			if (!*text)
			{
				return argc;
			}
		}
		else if (*text == '"')
		{
			++text;
			while (*text && *text != '"')
			{
				if (*text == '\\' && text[1] == '"')
				{
					++text;
				}
				argsPriv->textPool[argsPriv->totalUsedTextPool] = *text;
				if (argsPriv->totalUsedTextPool + 1 < 8190)
				{
					argsPriv->totalUsedTextPool = argsPriv->totalUsedTextPool + 1;
				}
				else
				{
					argsPriv->totalUsedTextPool = 8190;
				}
				++text;
			}
			argsPriv->textPool[argsPriv->totalUsedTextPool] = 0;
			if (argsPriv->totalUsedTextPool + 1 < 8190)
			{
				argsPriv->totalUsedTextPool = argsPriv->totalUsedTextPool + 1;
			}
			else
			{
				argsPriv->totalUsedTextPool = 8190;
			}

			if (!*text)
			{
				return argc;
			}
			if (!*++text)
			{
				return argc;
			}
		}
		else
		{
			do
			{
				argsPriv->textPool[argsPriv->totalUsedTextPool] = *text;
				if (argsPriv->totalUsedTextPool + 1 < 8190)
				{
					argsPriv->totalUsedTextPool = argsPriv->totalUsedTextPool + 1;
				}
				else
				{
					argsPriv->totalUsedTextPool = 8190;
				}

				if (!*++text)
				{
					argsPriv->textPool[argsPriv->totalUsedTextPool] = 0;
					if (argsPriv->totalUsedTextPool + 1 < 8190)
					{
						argsPriv->totalUsedTextPool = argsPriv->totalUsedTextPool + 1;
					}
					else
					{
						argsPriv->totalUsedTextPool = 8190;
					}

					return argc;
				}
			} while (!Cmd_IsWhiteSpaceChar(*text) && (*text != '/' || text[1] != '/' && text[1] != '*'));

			argsPriv->textPool[argsPriv->totalUsedTextPool] = 0;
			if (argsPriv->totalUsedTextPool + 1 < 8190)
			{
				argsPriv->totalUsedTextPool = argsPriv->totalUsedTextPool + 1;
			}
			else
			{
				argsPriv->totalUsedTextPool = 8190;
			}

		}
	}

	while (1)
	{
		argsPriv->textPool[argsPriv->totalUsedTextPool] = *text;
		argsPriv->totalUsedTextPool = argsPriv->totalUsedTextPool + 1 < 8190 ? argsPriv->totalUsedTextPool + 1 : 8190;
		if (!*text)
		{
			break;
		}
		++text;
	}

	return argc;
}

/*
==============
AssertCmdArgsConsistency
==============
*/
void AssertCmdArgsConsistency(const CmdArgs *args)
{
	int totalUsedTextPool;
	int totalUsedArgvPool;
	int arg;
	int nesting;

	totalUsedArgvPool = 0;
	totalUsedTextPool = 0;
	for (nesting = 0; nesting <= args->nesting; ++nesting)
	{
		totalUsedArgvPool += args->argshift[nesting] + args->argc[nesting];
		totalUsedTextPool += args->usedTextPool[nesting];
	}
	if (totalUsedArgvPool != args->totalUsedArgvPool)
	{
		Com_Printf(CON_CHANNEL_SYSTEM, "About to assert totalUsedArgvPool\n");
		for (nesting = 0; nesting <= args->nesting; ++nesting)
		{
			for (arg = 0; arg < args->argc[nesting]; ++arg)
			{
				Com_Printf(CON_CHANNEL_SYSTEM, "nesting %i, arg %i: '%s'\n", nesting, arg, args->argv[nesting][arg]);
			}
		}
	}

	assertMsg(totalUsedArgvPool == args->totalUsedArgvPool, va(
		"totalUsedArgvPool is %i, args->totalUsedArgvPool is %i, args->nesting is %i, args->argc[0] is %i, args->argc["
		"1] is %i, args->argc[2] is %i, args->argc[3] is %i",
		totalUsedArgvPool,
		args->totalUsedArgvPool,
		args->nesting,
		args->argc[0],
		args->argc[1],
		args->argc[2],
		args->argc[3]));
	assertMsg(!(totalUsedArgvPool != args->totalUsedTextPool), "totalUsedTextPool == args->totalUsedTextPool\n\t%i, %i", totalUsedTextPool, args->totalUsedTextPool)
}

/*
==============
Cmd_TokenizeStringKernel
==============
*/
void Cmd_TokenizeStringKernel(LocalClientNum_t localClientNum, ControllerIndex_t localControllerIndex, itemDef_s *item, const char *text_in, int max_tokens, bool evalExpressions, CmdArgs *args)
{
	assertMsg(!(max_tokens > 512 - args->totalUsedArgvPool), "max_tokens <= MAX_TOKENS_SIZE - args->totalUsedArgvPool\n\t%i, %i", max_tokens, 512 - args->totalUsedArgvPool)
	AssertCmdArgsConsistency(args);
	++args->nesting;
	assertIn(args->nesting, CMD_MAX_NESTING);
	args->usedTextPool[args->nesting] = -args->totalUsedTextPool;
	args->itemDef[args->nesting] = item;
	args->localClientNum[args->nesting] = localClientNum;
	args->controllerIndex[args->nesting] = localControllerIndex;
	args->argv[args->nesting] = &args->argvPool[args->totalUsedArgvPool];
	args->argshift[args->nesting] = 0;
	args->argc[args->nesting] = Cmd_TokenizeStringInternal(
		text_in,
		max_tokens,
		evalExpressions,
		args->argv[args->nesting],
		args);
	args->totalUsedArgvPool += args->argc[args->nesting];
	args->usedTextPool[args->nesting] += args->totalUsedTextPool;
	AssertCmdArgsConsistency(args);
}

/*
==============
Cmd_EndTokenizedStringKernel
==============
*/
void Cmd_EndTokenizedStringKernel(CmdArgs *args)
{
	AssertCmdArgsConsistency(args);
	if (args->nesting != -1)
	{
		assertIn(args->nesting, CMD_MAX_NESTING);
		args->totalUsedArgvPool -= args->argc[args->nesting];
		args->totalUsedArgvPool -= args->argshift[args->nesting];
		args->totalUsedTextPool -= args->usedTextPool[args->nesting];
		args->nesting--;
		AssertCmdArgsConsistency(args);
	}
}

/*
==============
Cmd_TokenizeStringWithLimit
==============
*/
void Cmd_TokenizeStringWithLimit(const char *text_in, int max_tokens)
{
	Cmd_TokenizeStringKernel((LocalClientNum_t)-1, (ControllerIndex_t)0, NULL, text_in, max_tokens, 1, Cmd_Args());
}

/*
==============
Cmd_TokenizeString
==============
*/
void Cmd_TokenizeString(const char *text_in)
{
	Cmd_TokenizeStringWithLimit(text_in, 512 - Cmd_Args()->totalUsedArgvPool);
}

/*
==============
Cmd_TokenizeStringWithLimitNoEval

==============
*/
inline void Cmd_TokenizeStringWithLimitNoEval(const char* text_in, int max_tokens)
{
	Cmd_TokenizeStringKernel((LocalClientNum_t)-1, (ControllerIndex_t)0, NULL, text_in, max_tokens, 0, Cmd_Args());
}

/*
==============
Cmd_TokenizeStringNoEval
==============
*/
void Cmd_TokenizeStringNoEval(const char *text_in)
{
	Cmd_TokenizeStringWithLimitNoEval(text_in, 512 - Cmd_Args()->totalUsedArgvPool);
}

/*
==============
Cmd_EndTokenizedString
==============
*/
void Cmd_EndTokenizedString()
{
	Cmd_EndTokenizedStringKernel(Cmd_Args());
}

/*
==============
SV_Cmd_TokenizeString
==============
*/
void SV_Cmd_TokenizeString(const char *text_in)
{
	Cmd_TokenizeStringKernel((LocalClientNum_t)-1, (ControllerIndex_t)0, NULL, text_in, 512 - sv_cmd_args.totalUsedArgvPool, 1, &sv_cmd_args);
}

/*
==============
SV_Cmd_EndTokenizedString
==============
*/
void SV_Cmd_EndTokenizedString()
{
	Cmd_EndTokenizedStringKernel(&sv_cmd_args);
}

/*
==============
Cmd_FindCommand
==============
*/
cmd_function_s *Cmd_FindCommand(const char *cmdName)
{
	cmd_function_s* cmd;

	for (cmd = cmd_functions; cmd; cmd = cmd->next)
	{
		if (!strcmp(cmdName, cmd->name))
		{
			return cmd;
		}
	}
	return NULL;
}

/*
==============
Cmd_AddCommandInternal
==============
*/
void Cmd_AddCommandInternal(const char *cmdName, void (*function)(), cmd_function_s *allocedCmd)
{
	cmd_function_s* cmd;

	assert(cmdName);

	// fail if the command already exists
	cmd = Cmd_FindCommand(cmdName);
	if (cmd)
	{
		assert(cmd == allocedCmd);
		if (function != NULL)
		{
			Com_Printf(CON_CHANNEL_SYSTEM, "Cmd_AddCommand: %s already defined\n", cmdName);
		}
		return;
	}

	allocedCmd->name = cmdName;
	allocedCmd->function = function;
	allocedCmd->next = cmd_functions;
	cmd_functions = allocedCmd;
}

/*
==============
Cmd_RemoveCommand
==============
*/
void Cmd_RemoveCommand(const char *cmdName)
{
	cmd_function_s* cmd, ** back;

	back = &cmd_functions;
	while (1)
	{
		cmd = *back;
		if (!cmd)
		{
			// command wasn't active
			return;
		}

		if (!strcmp(cmdName, cmd->name))
		{
			*back = cmd->next;
			return;
		}
		back = &cmd->next;
	}
}

/*
==============
Cmd_SetAutoComplete
==============
*/
void Cmd_SetAutoComplete(const char *cmdName, const char *dir, const char *ext)
{
	cmd_function_s* cmd;

	assert(cmdName);
	assert(dir);
	assert(ext);
	cmd = Cmd_FindCommand(cmdName);

	assert(cmd);
	assert(cmd->autoCompleteDir == NULL);
	assert(cmd->autoCompleteExt == NULL);

	cmd->autoCompleteDir = dir;
	cmd->autoCompleteExt = ext;
}

/*
==============
Cmd_Shutdown
==============
*/
void Cmd_Shutdown()
{
	cmd_functions = NULL;
	sv_cmd_functions = NULL;
}

/*
==============
Cmd_ForEach
==============
*/
void Cmd_ForEach(void (*callback)(const char *))
{
	cmd_function_s* cmd;

	for (cmd = cmd_functions; cmd; cmd = cmd->next)
	{
		callback(cmd->name);
	}
}

/*
==============
Cmd_ForEach
==============
*/
void Cmd_ForEach(LocalClientNum_t localClientNum, void (*callback)(LocalClientNum_t, const char *))
{
	cmd_function_s* i;

	for (i = cmd_functions; i; i = i->next)
		callback(localClientNum, i->name);
}

/*
==============
Cmd_GetAutoCompleteFileList
==============
*/
const char **Cmd_GetAutoCompleteFileList(const char *cmdName, int *fileCount, int allocTrackType)
{
	cmd_function_s* cmd;

	assert(cmdName);
	assert(fileCount);
	*fileCount = 0;
	cmd = Cmd_FindCommand(cmdName);
	if (cmd && cmd->autoCompleteDir && cmd->autoCompleteExt)
	{
		return FS_ListFiles(cmd->autoCompleteDir, cmd->autoCompleteExt, FS_LIST_PURE_ONLY, fileCount);
	}

	return NULL;
}

/*
==============
Cmd_ResetArgs

==============
*/
inline void Cmd_ResetArgs(CmdArgs* args)
{
	args->nesting = -1;
	args->totalUsedArgvPool = 0;
	args->totalUsedTextPool = 0;
}

/*
==============
Cmd_ComErrorCleanup
==============
*/
void Cmd_ComErrorCleanup()
{
	int client;

	Cmd_ResetArgs(Cmd_Args());
	Cmd_ResetArgs(&sv_cmd_args);
	for (client = 0; client < 1; ++client)
	{
		cmd_insideCBufExecute[client] = 0;
	}
}

/*
==============
Cmd_List_f
==============
*/
void Cmd_List_f()
{
	const char* match;
	int i;
	cmd_function_s* cmd;

	if (Cmd_Argc() > 1)
	{
		match = Cmd_Argv(1);
	}
	else
	{
		match = NULL;
	}

	i = 0;
	for (cmd = cmd_functions; cmd; cmd = cmd->next)
	{
		if (match && !Com_Filter(match, cmd->name, 0))
		{
			continue;
		}

		Com_Printf(0, "%s\n", cmd->name);
		++i;
	}
	Com_Printf(0, "%i commands\n", i);
}

/*
==============
Cmd_DObjDump
==============
*/
void Cmd_DObjDump()
{
	Com_DObjDump();
}

/*
==============
Cmd_HandleMissingCommand
==============
*/
void Cmd_HandleMissingCommand(const char *msg, bool fromRemoteConsole)
{
	if (!Dvar_GetBool(missingCommandWillError) || fromRemoteConsole)
		Com_Printf(CON_CHANNEL_CLIENT, "Unknown command \"%s\"\n", msg);
	else
		Com_Error(ERR_DROP, "Unknown command \"%s\"\n", msg);
}

/*
==============
Cmd_ExecuteServerString
==============
*/
void Cmd_ExecuteServerString(const char *text)
{
	unsigned int nesting;
	const char* nestedArg;
	const char* arg1;
	cmd_function_s* cmd;
	cmd_function_s** p_next;

	Cmd_TokenizeStringKernel(INVALID_LOCAL_CLIENT, CONTROLLER_INDEX_FIRST, 0, text, 512 - sv_cmd_args.totalUsedArgvPool, 1, &sv_cmd_args);
	nesting = sv_cmd_args.nesting;
	if (sv_cmd_args.nesting >= 8)
	{
		AssertMsg("sv_cmd_args.nesting doesn't index CMD_MAX_NESTING\n\t%i not in [0, %i)", sv_cmd_args.nesting, 8);
		nesting = sv_cmd_args.nesting;
	}
	if (sv_cmd_args.argc[nesting])
	{
		if (nesting >= 8)
		{
			AssertMsg("sv_cmd_args.nesting doesn't index CMD_MAX_NESTING\n\t%i not in [0, %i)", sv_cmd_args.nesting, 8);
			nesting = sv_cmd_args.nesting;
		}
		if (sv_cmd_args.argc[nesting] <= 0)
			nestedArg = "";
		else
			nestedArg = *sv_cmd_args.argv[nesting];
		if (!I_stricmp(nestedArg, "if") && SV_Cmd_Argc() > 2)
		{
			arg1 = SV_Cmd_Argv(1);
			if (!atoi(arg1))
				Cmd_EndTokenizedStringKernel(&sv_cmd_args);
			Cmd_ShiftArgs(2, &sv_cmd_args);
		}
		nesting = sv_cmd_args.nesting;
		if (sv_cmd_args.nesting >= 8u)
		{
			AssertMsg("sv_cmd_args.nesting doesn't index CMD_MAX_NESTING\n\t%i not in [0, %i)", sv_cmd_args.nesting, 8);
			nesting = sv_cmd_args.nesting;
		}
		if (sv_cmd_args.argc[nesting] <= 0)
			nestedArg = "";
		else
			nestedArg = *sv_cmd_args.argv[nesting];
		if (sv_cmd_functions)
		{
			for (p_next = &sv_cmd_functions; ; *p_next = cmd->next)
			{
				if (!I_stricmp(nestedArg, cmd->name))
					break;
				if (!cmd->next)
					Cmd_EndTokenizedStringKernel(&sv_cmd_args);
			}
			if (cmd->function)
				cmd->function();
		}
	}
}

/*
==============
Cbuf_SV_Execute
==============
*/
void Cbuf_SV_Execute()
{
	int idx;
	char quotes;
	int i;
	char line[4096];
	unsigned char* text;

	while (sv_cmd_text.cmdsize)
	{
		text = sv_cmd_text.data;
		quotes = 0;
		for (i = 0; i < sv_cmd_text.cmdsize; ++i)
		{
			if (text[i] == 34)
			{
				++quotes;
			}

			if (!(quotes & 1) && text[i] == 59 || text[i] == 10 || text[i] == 13)
			{
				break;
			}
		}

		if (i >= 4095)
		{
			i = 4095;
		}

		memcpy(line, text, i);
		line[i] = 0;
		if (i == sv_cmd_text.cmdsize)
		{
			sv_cmd_text.cmdsize = 0;
		}
		else
		{
			idx = i + 1;
			sv_cmd_text.cmdsize -= idx;
			memmove(text, &text[idx], sv_cmd_text.cmdsize);
		}

		SV_WaitServer();
		assert(!com_inServerFrame);
		Cmd_ExecuteServerString(line);
	}
}

/*
==============
Cmd_ExecuteSingleCommandInternal
==============
*/
void Cmd_ExecuteSingleCommandInternal(LocalClientNum_t localClientNum, ControllerIndex_t controllerIndex, itemDef_s *item, const char *text, bool fromRemoteConsole)
{
	CmdArgs* args;
	const char* arg0;
	const char* predicate;
	cmd_function_s** prev;
	cmd_function_s* cmd;

	assertMsg(!(localClientNum < -1 || localClientNum >= 1), "%s\n\t(localClientNum) = %i", "(localClientNum >= (-1) && localClientNum < 1)", localClientNum);

	args = Cmd_Args();

	Cmd_TokenizeStringKernel(localClientNum, controllerIndex, item, text, 512 - args->totalUsedArgvPool, 1, args);
	if (!Cmd_Argc())
		Cmd_EndTokenizedString();
	if (!I_stricmp(Cmd_Argv(0), "if") && Cmd_Argc() > 2)
	{
		predicate = Cmd_Argv(1);
		if (!atoi(predicate))
			Cmd_EndTokenizedString();
		Cmd_ShiftArgs(2, Cmd_Args());
	}
	arg0 = Cmd_Argv(0);
	if (strchr(arg0, 32))
	{
		Com_PrintError(1, "Command arg0 contains whitespace (\"%s\"), most likely an error: %s\n", arg0, text);
		Cmd_EndTokenizedString();
		return;
	}
	for (prev = &cmd_functions; ; prev = &cmd->next)
	{
		if (!*prev)
		{
			if (!Dvar_Command() && (!Dvar_GetBool(com_sv_running) || !SV_GameCommand()))
			{
				if (Dvar_GetBool(missingCommandWillError))
					Com_Error(ERR_DROP, "Unknown command \"%s\"\n", arg0);
				else
					Com_Printf(CON_CHANNEL_CLIENT, "Unknown command \"%s\"\n", arg0);
			}
		}
		cmd = *prev;
		if (!I_stricmp(arg0, (*prev)->name))
			break;
	}
	if (cmd->function)
	{
		if (cmd->function == Cbuf_AddServerText_f)
		{
			SV_WaitServer();
			assert(!com_inServerFrame);
			Cmd_ExecuteServerString(text);
		}
		else
			cmd->function();
	}
	else
	{
		if (!Dvar_Command() && (!Dvar_GetBool(com_sv_running) || !SV_GameCommand()))
		{
			if (Dvar_GetBool(missingCommandWillError))
				Com_Error(ERR_DROP, "Unknown command \"%s\"\n", arg0);
			else
				Com_Printf(CON_CHANNEL_CLIENT, "Unknown command \"%s\"\n", arg0);
		}
	}
	Cmd_EndTokenizedString();
}

/*
==============
Cmd_ExecuteSingleCommand
==============
*/
void Cmd_ExecuteSingleCommand(LocalClientNum_t localClientNum, ControllerIndex_t controllerIndex, const char *text, bool fromRemoteConsole)
{
	Cmd_ExecuteSingleCommandInternal(localClientNum, controllerIndex, 0, text, fromRemoteConsole);
}

/*
==============
SV_Cmd_ExecuteString
==============
*/
void SV_Cmd_ExecuteString(LocalClientNum_t localClientNum, ControllerIndex_t controllerIndex, const char *text)
{
	Cmd_ExecuteSingleCommandInternal(localClientNum, controllerIndex, 0, text, 0);
}

/*
==============
ExecuteRestOfCommand
==============
*/
void ExecuteRestOfCommand()
{
	int i;
	char cmd[1024];

	cmd[0] = 0;
	for (i = 1; i < Cmd_Argc(); ++i)
	{
		I_strncat(cmd, 1024, Cmd_Argv(i));
		if (i < Cmd_Argc() - 1)
			I_strncat(cmd, 1024, " ");
	}
	Cmd_ExecuteSingleCommandInternal(LOCAL_CLIENT_FIRST, CONTROLLER_INDEX_FIRST, 0, cmd, 0);
}

/*
==============
Cmd_IfMP_f
==============
*/
void Cmd_IfMP_f()
{
	ExecuteRestOfCommand();
}

/*
==============
Cbuf_ExecuteBufferInternal
==============
*/
void Cbuf_ExecuteBufferInternal(LocalClientNum_t localClientNum, ControllerIndex_t controllerIndex, itemDef_s *item, const char *buffer)
{
	int bufferLen;
	int remainingBuffer;
	int i;
	LocalClientNum_t m_localClientNum;
	ControllerIndex_t localControllerIndex;
	CmdArgs* args;
	char quotes;
	const char* text;
	char currChar;
	char dst;

	assert(buffer);
	bufferLen = strlen(buffer);
	while (bufferLen)
	{
		quotes = 0;
		for (i = 0; i < bufferLen; ++i)
		{
			currChar = buffer[i];
			if (text[i] == '"')
			{
				++quotes;
			}
			if (!(quotes & 1) && currChar == ';' || currChar == '\n' || currChar == '\r')
			{
				break;
			}
		}
		if (i >= 4095)
		{
			i = 4095;
		}
		memcpy(&dst, buffer, i);
		*(&dst + i) = 0;
		if (i != bufferLen)
			++i;
		remainingBuffer = bufferLen - i;
		text = &buffer[i];
		m_localClientNum = localClientNum;
		if ((dst == 'p' || dst == 'P') && text[1] >= '0' && text[1] < '1')
		{
			m_localClientNum = (LocalClientNum_t)(text[1] - 48);
			if (m_localClientNum != localClientNum)
			{
				m_localClientNum = (LocalClientNum_t)(text[1] - 48);
				localControllerIndex = Com_LocalClient_GetControllerIndex(m_localClientNum);
			}
		}
		Cmd_ExecuteSingleCommandInternal(m_localClientNum, controllerIndex, item, buffer, 1);
		bufferLen = remainingBuffer;
		if (!remainingBuffer)
			return;
		buffer = text;
	}
}

/*
==============
Cbuf_ExecuteBuffer
==============
*/
void Cbuf_ExecuteBuffer(LocalClientNum_t localClientNum, ControllerIndex_t controllerIndex, const char *buffer)
{
	Cbuf_ExecuteBufferInternal(localClientNum, controllerIndex, 0, buffer);
}

/*
==============
Cbuf_ExecuteBufferUI
==============
*/
void Cbuf_ExecuteBufferUI(LocalClientNum_t localClientNum, ControllerIndex_t controllerIndex, itemDef_s *item, const char *buffer)
{
	Cbuf_ExecuteBufferInternal(localClientNum, controllerIndex, item, buffer);
}

/*
==============
Cbuf_ExecuteInternal
==============
*/
void Cbuf_ExecuteInternal(LocalClientNum_t localClientNum, ControllerIndex_t controllerIndex)
{
	char quotes;
	CmdText* cmd_text;
	int i;
	char line[4096];
	unsigned char* text;

	Sys_EnterCriticalSection(CRITSECT_CBUF);
	cmd_text = &cmd_textArray[localClientNum];
	while (cmd_text->cmdsize)
	{
		if (cmd_wait)
		{
			--cmd_wait;
			break;
		}

		text = cmd_text->data;
		quotes = 0;
		for (i = 0; i < cmd_text->cmdsize; ++i)
		{
			if (text[i] == 34)
			{
				++quotes;
			}
			if (!(quotes & 1) && text[i] == 59 || text[i] == 10 || text[i] == 13)
			{
				break;
			}
		}

		if (i >= 4095)
		{
			i = 4095;
		}

		memcpy(line, text, i);
		line[i] = 0;
		if (i == cmd_text->cmdsize)
		{
			cmd_text->cmdsize = 0;
		}
		else
		{
			cmd_text->cmdsize -= i + 1;
			memmove(text, &text[i + 1], cmd_text->cmdsize);
		}
		Sys_LeaveCriticalSection(CRITSECT_CBUF);
		Cmd_ExecuteSingleCommand(localClientNum, controllerIndex, line, 1);
		Sys_EnterCriticalSection(CRITSECT_CBUF);
	}
	Sys_LeaveCriticalSection(CRITSECT_CBUF);
}

/*
==============
Cbuf_Execute
==============
*/
void Cbuf_Execute(LocalClientNum_t localClientNum, ControllerIndex_t controllerIndex)
{
	PIXBeginNamedEvent(-1, "Cbuf_Execute");
	assertMsg(!cmd_insideCBufExecute[localClientNum], "Nesting Cbuf_Execute() is not allowed.");
	cmd_insideCBufExecute[localClientNum] = 1;
	Cbuf_ExecuteInternal(localClientNum, controllerIndex);
	cmd_insideCBufExecute[localClientNum] = 0;
	Cbuf_SV_Execute();
	if (Sys_IsRenderThread())
		D3DPERF_EndEvent();
}

/*
==============
Cmd_ExecFromDisk
==============
*/
bool Cmd_ExecFromDisk(LocalClientNum_t localClientNum, ControllerIndex_t controllerIndex, const char *filename)
{
	char* text;

	FS_ReadFile(filename, (void**)&text);
	if (text)
	{
		Com_Printf(CON_CHANNEL_SYSTEM, "execing %s from disk\n", filename);
		Cbuf_ExecuteBufferInternal(localClientNum, controllerIndex, 0, text);
		FS_FreeFile(text);
		return 1;
	}
	else
	{
		Com_Printf(CON_CHANNEL_SYSTEM, "Exec From Disk failed to open %s\n", filename);
		return 0;
	}
}

inline bool Cmd_ExecFromFastFile(const char* filename, LocalClientNum_t localClientNum, ControllerIndex_t controllerIndex)
{
	XAssetHeader asset;

	asset.xmodelPieces = DB_FindXAssetHeader(ASSET_TYPE_RAWFILE, filename, 1, -1).xmodelPieces;
	asset.xmodelPieces = DB_FindXAssetHeader(ASSET_TYPE_RAWFILE, filename, 1, -1).xmodelPieces;
	if (!asset.xmodelPieces)
		return 0;
	Com_Printf(CON_CHANNEL_SYSTEM, "execing %s from fastfile\n");
	Cbuf_ExecuteBufferInternal(localClientNum, controllerIndex, 0, (const char*)asset.xmodelPieces->pieces); // ??? don't ask me.
	return 1;
}

/*
==============
Cmd_Exec_f
==============
*/
void Cmd_Exec_f()
{
	unsigned __int64 Xuid;
	const char* arg0;
	const char* arg1;
	char filename[128]; 
	bool nAddText = false;
	XAssetHeader asset;

	if (Cmd_Argc() != 2)
	{
		Com_Printf(CON_CHANNEL_DONT_FILTER, "exec <filename> : execute a script file\n");
		return;
	}
	arg0 = Cmd_Argv(0);
	arg1 = Cmd_Argv(1);
	I_strncpyz(filename, arg0, 128);
	if (!I_strcmp(filename, "exec_addtext"))
		nAddText = true;
	I_strncpyz(filename, arg1, 128);
	Com_DefaultExtension(filename, 128, ".cfg");
	if (Dvar_GetBool(useFastFile))
	{
		asset.xmodelPieces = DB_FindXAssetHeader(ASSET_TYPE_RAWFILE, filename, 1, -1).xmodelPieces;
		if (asset.xmodelPieces)
		{
			Com_Printf(CON_CHANNEL_SYSTEM, "execing %s from fastfile\n", filename);
			Cbuf_ExecuteBufferInternal(LOCAL_CLIENT_FIRST, CONTROLLER_INDEX_FIRST, 0, (const char*)asset.xmodelPieces->pieces);
			return;
		}
		Com_isFullyInitialized();
	}
	if (!nAddText || !Cmd_ExecFromDiskAddText(LOCAL_CLIENT_FIRST, CONTROLLER_INDEX_FIRST, filename))
	{
		if (Cmd_ExecFromDisk(LOCAL_CLIENT_FIRST, CONTROLLER_INDEX_FIRST, filename))
		{
			if (Live_IsUserSignedInToDemonware(CONTROLLER_INDEX_FIRST))
			{
				Xuid = Live_GetXuid(CONTROLLER_INDEX_FIRST);
				LiveTracker_WriteByID(TRACKER_EXEC_DISC_CFG, Xuid, 1);
			}
		}
		else
		{
			if (Live_IsUserSignedInToDemonware(CONTROLLER_INDEX_FIRST))
			{
				LiveTracker_WriteByID(TRACKER_EXEC_UNKN_CFG, Live_GetXuid(CONTROLLER_INDEX_FIRST), 1);
			}
			Com_PrintError( 1, "couldn't exec %s\n", filename);
		}
	}
}

/*
==============
Cmd_Init
==============
*/
void Cmd_Init()
{
	Cmd_AddCommandInternal("cmdlist", Cmd_List_f, &Cmd_List_f_VAR);
	Cmd_AddCommandInternal("exec", Cmd_Exec_f, &Cmd_Exec_f_VAR);
	Cmd_AddCommandInternal("exec_addtext", (void(__cdecl*)())Cmd_ExecAddText_f, &Cmd_ExecAddText_f_VAR);
	Cmd_AddCommandInternal("wait", Cmd_Wait_f, &Cmd_Wait_f_VAR);
	Cmd_AddCommandInternal("zm", Cmd_SetZM_f, &Cmd_SetZM_f_VAR);
	Cmd_AddCommandInternal("say", nullptr, &Cmd_ForwardCommand_f_VAR_22);
	Cmd_AddCommandInternal("dobjdump", Cmd_DObjDump, &Cmd_DObjDump_VAR);
	Cmd_AddCommandInternal("say_team", nullptr, &Cmd_ForwardCommand_f_VAR_21);
	Cmd_AddCommandInternal("follownext", nullptr, &Cmd_ForwardCommand_f_VAR_20);
	Cmd_AddCommandInternal("followprev", nullptr, &Cmd_ForwardCommand_f_VAR_19);
	Cmd_AddCommandInternal("mr", nullptr, &Cmd_ForwardCommand_f_VAR_18);
	Cmd_AddCommandInternal("give", nullptr, &Cmd_ForwardCommand_f_VAR_17);
	Cmd_AddCommandInternal("take", nullptr, &Cmd_ForwardCommand_f_VAR_16);
	Cmd_AddCommandInternal("god", nullptr, &Cmd_ForwardCommand_f_VAR_15);
	Cmd_AddCommandInternal("demigod", nullptr, &Cmd_ForwardCommand_f_VAR_14);
	Cmd_AddCommandInternal("ufo", nullptr, &Cmd_ForwardCommand_f_VAR_13);
	Cmd_AddCommandInternal("kill", nullptr, &Cmd_ForwardCommand_f_VAR_12);
	Cmd_AddCommandInternal("setviewpos", nullptr, &Cmd_ForwardCommand_f_VAR_11);
	Cmd_AddCommandInternal("printentities", nullptr, &Cmd_ForwardCommand_f_VAR_10);
	Cmd_AddCommandInternal("entitycount", nullptr, &Cmd_ForwardCommand_f_VAR_9);
	Cmd_AddCommandInternal("printclientfields", nullptr, &Cmd_ForwardCommand_f_VAR_8);
	Cmd_AddCommandInternal("ai", nullptr, &Cmd_ForwardCommand_f_VAR_7);
	Cmd_AddCommandInternal("noclip", nullptr, &Cmd_ForwardCommand_f_VAR_6);
	Cmd_AddCommandInternal("notarget", nullptr, &Cmd_ForwardCommand_f_VAR_5);
	Cmd_AddCommandInternal("where", nullptr, &Cmd_ForwardCommand_f_VAR_4);
	Cmd_AddCommandInternal("callvote", nullptr, &Cmd_ForwardCommand_f_VAR_3);
	Cmd_AddCommandInternal("vote", nullptr, &Cmd_ForwardCommand_f_VAR_2);
	Cmd_AddCommandInternal("visionsetnaked", nullptr, &Cmd_ForwardCommand_f_VAR_1);
	Cmd_AddCommandInternal("visionsetnight", nullptr, &Cmd_ForwardCommand_f_VAR_0);
	Cmd_AddCommandInternal("spawndebug_user_badspawn", nullptr, &Cmd_ForwardCommand_f_VAR);
	Cmd_AddCommandInternal("if_sp", nullptr, &Cmd_IfSP_f_VAR);
	Cmd_AddCommandInternal("if_mp", Cmd_IfMP_f, &Cmd_IfMP_f_VAR);
}

