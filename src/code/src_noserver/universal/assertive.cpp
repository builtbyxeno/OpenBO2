#include "types.h"
#include "functions.h"

/*
==============
HideWindowCallback
==============
*/
int HideWindowCallback(HWND__ *hwnd, int lParam)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
FixWindowsDesktop
==============
*/
void FixWindowsDesktop()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
TRACK_assertive
==============
*/
void TRACK_assertive()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SkipLines
==============
*/
char SkipLines(int lineCount, _iobuf *fp)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
ParseMapFile
==============
*/
bool ParseMapFile(_iobuf *fp, unsigned int baseAddress, const char *mapName)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
GetModuleBase
==============
*/
unsigned int GetModuleBase(const char *name)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LoadMapFilesForDir
==============
*/
void LoadMapFilesForDir(const char *dir)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
StackTrace_ResolveSymbols
==============
*/
int StackTrace_ResolveSymbols()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
StackTrace_Generate
==============
*/
int StackTrace_Generate(int len, char *msg)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
StackTrace_Walk
==============
*/
int StackTrace_Walk(int ignoreCount, void *context)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
StackTrace_GetAddressInfo
==============
*/
AddressInfo_s *StackTrace_GetAddressInfo(int *addressCount)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
StackTrace_ResetAddressInfo
==============
*/
void StackTrace_ResetAddressInfo()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CopyMessageToClipboard
==============
*/
void CopyMessageToClipboard(const char *msg)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
AssertNotify
==============
*/
char AssertNotify(int type, AssertOccurance occurance)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Assert_BuildAssertMessageWithStack
==============
*/
int Assert_BuildAssertMessageWithStack(const char *expr, const char *extra, const char *filename, int line, int type, int messageLen, char *message)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
IsDebuggerConnected
==============
*/
BOOL IsDebuggerConnected()
{
	return IsDebuggerPresent();
}

/*
==============
RefreshQuitOnErrorCondition
==============
*/
void RefreshQuitOnErrorCondition()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
QuitOnError
==============
*/
bool QuitOnError()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

