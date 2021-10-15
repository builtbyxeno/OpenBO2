#include <types.h>

struct tlFileBuf {
	char* Buf;
	unsigned int Size;
	unsigned int UserData;
};

struct tagTHREADNAME_INFO
{
	unsigned int dwType;
	const char* szName;
	unsigned int dwThreadID;
	unsigned int dwFlags;
};

struct tlSystemCallbacks
{
	bool(__cdecl* ReadFile)(const char*, tlFileBuf*, unsigned int, unsigned int);
	void(__cdecl* ReleaseFile)(tlFileBuf*);
	void(__cdecl* CriticalError)(const char*);
	void(__cdecl* Warning)(const char*);
	void(__cdecl* DebugPrint)(const char*);
	void* (__cdecl* MemAlloc)(unsigned int, unsigned int, unsigned int);
	void* (__cdecl* MemRealloc)(void*, unsigned int, unsigned int, unsigned int);
	void(__cdecl* MemFree)(void*);
};

void tlSetSystemCallbacks(const tlSystemCallbacks* Callbacks);
void tlSetFileServerRootPC(const char* Path);
void tlMemFree(void* Ptr);
void tlReleaseFile(tlFileBuf* File);
void tlPrint(const char* txt);
int tlGetVersion();
void tlStackRangeInit();
bool tlFatalHandler(const char* Msg);
void tlDebugPrint(const char* txt);
void tlVPrintf(const char* Format, char* args);
void tlPrintf(const char* Format, ...);
char _tlAssert(const char* file, int line, const char* expr, const char* desc);
void tlFatal(const char* Format, ...);
void* tlMemAlloc(unsigned int Size, unsigned int Align, unsigned int Flags);
void* tlMemRealloc(void* Ptr, unsigned int Size, unsigned int Align, unsigned int Flags);
unsigned int tlGetFreeMemory();
void* tlScratchPadInit();
void tlScratchPadReset();
void tlWarning(const char* Format, ...);

static tlSystemCallbacks tlCurSystemCallbacks;
static char tlHostPrefix[256];
static int tlMemAllocCounter;
static void* tlStackBegin;
static void* tlStackEnd;
static int tlScratchPadRefCount;
static void* tlScratchPadPtr;