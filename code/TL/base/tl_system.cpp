#include "tl_system.h"

/*
==============
tlSetSystemCallbacks
==============
*/
void tlSetSystemCallbacks(const tlSystemCallbacks *Callbacks) {
  memcpy_s(&tlCurSystemCallbacks, sizeof(tlCurSystemCallbacks), Callbacks, sizeof(Callbacks));
}

/*
==============
tlSetFileServerRootPC
==============
*/
void tlSetFileServerRootPC(const char *Path)
{
  strcpy(tlHostPrefix, Path);
}

/*
==============
tlMemFree
==============
*/
void tlMemFree(void *Ptr)
{
  --tlMemAllocCounter;
  if ( tlCurSystemCallbacks.MemFree )
      tlCurSystemCallbacks.MemFree(Ptr);
  else
    _aligned_free(Ptr);
}

/*
==============
tlReleaseFile
==============
*/
void tlReleaseFile(tlFileBuf *File)
{
    if (tlCurSystemCallbacks.ReleaseFile)
    {
        tlCurSystemCallbacks.ReleaseFile(File);
    }
    else
    {
        --tlMemAllocCounter;
        if (tlCurSystemCallbacks.MemFree)
            tlCurSystemCallbacks.MemFree(File->Buf);
        else
            _aligned_free(File->Buf);
        File->Buf = 0;
        File->Size = 0;
        File->UserData = 0;
    }
}

/*
==============
tlPcGetTick
==============
*/
_LARGE_INTEGER tlPcGetTick()
{
  _LARGE_INTEGER li;

  QueryPerformanceCounter(&li);
  return li;
}

/*
==============
tlPrint
==============
*/
void tlPrint(const char *txt)
{
  OutputDebugString(txt);
}

/*
==============
tlGetVersion
==============
*/
int tlGetVersion()
{
  return 66560;
}

/*
==============
tlStackRangeInit
==============
*/
void tlStackRangeInit()
{
  tlStackBegin = NULL;
  tlStackEnd = NULL;
}

/*
==============
tlFatalHandler
==============
*/
bool tlFatalHandler(const char *Msg)
{
    if (tlCurSystemCallbacks.CriticalError)
    {
        tlCurSystemCallbacks.CriticalError(Msg);
        return 0;
    }
    else
    {
        OutputDebugString("TL Fatal Error: ");
        OutputDebugString(Msg);
        OutputDebugString("\n");
        return 1;
    }
}

/*
==============
tlDebugPrint
==============
*/
void tlDebugPrint(const char *txt)
{
    if (tlCurSystemCallbacks.DebugPrint)
        tlCurSystemCallbacks.DebugPrint(txt);
    else
        OutputDebugString(txt);
}

/*
==============
tlVPrintf
==============
*/
void tlVPrintf(const char *Format, char *args)
{
    char Work[512];

    vsprintf(Work, Format, args);
    if (tlCurSystemCallbacks.DebugPrint)
        tlCurSystemCallbacks.DebugPrint(Work);
    else
        OutputDebugString(Work);
}

/*
==============
tlPrintf
==============
*/
void tlPrintf(const char *Format, ...)
{
    char Work[512];
    va_list ap;

    va_start(ap, Format);
    vsprintf(Work, Format, ap);
    if (tlCurSystemCallbacks.DebugPrint)
        tlCurSystemCallbacks.DebugPrint(Work);
    else
        OutputDebugString(Work);
}

/*
==============
_tlAssert
==============
*/
char _tlAssert(const char *file, int line, const char *expr, const char *desc)
{
    bool result;
    char Buf[256];

    snprintf(Buf, 0x100u, "ASSERT in %s(%d):\n\"%s\" - %s", file, line, expr, desc);
    Buf[255] = 0;
    if (tlCurSystemCallbacks.CriticalError)
    {
        tlCurSystemCallbacks.CriticalError(Buf);
        return false;
    }
    else
    {
        OutputDebugString("TL Fatal Error: ");
        OutputDebugString(Buf);
        OutputDebugString("\n");
        return true;
    }
}

/*
==============
tlFatal
==============
*/
void tlFatal(const char *Format, ...)
{
  char Work[512];
  va_list ap;

  va_start(ap, Format);
  vsprintf(Work, Format, ap);
  if (tlCurSystemCallbacks.CriticalError)
  {
      tlCurSystemCallbacks.CriticalError(Work);
  }
  else
  {
    OutputDebugString("TL Fatal Error: ");
    OutputDebugString(Work);
    OutputDebugString("\n");
    __debugbreak();
  }
}

/*
==============
tlMemAlloc
==============
*/
void *tlMemAlloc(unsigned int Size, unsigned int Align, unsigned int Flags)
{
    void* memPtr;

    if (!Align && (Size & 0xF) == 0)
        Align = 0;
    ++tlMemAllocCounter;
    if (tlCurSystemCallbacks.MemAlloc)
        memPtr = tlCurSystemCallbacks.MemAlloc(Size, Align, Flags);
    else
        memPtr = _aligned_malloc(Size, Align);
    if ((Flags & 2) == 0 && !memPtr && Size)
        tlFatal("Memory allocation failed. %d bytes, %d align", Size, Align);
    return memPtr;
}

/*
==============
tlMemRealloc
==============
*/
void *tlMemRealloc(void *Ptr, unsigned int Size, unsigned int Align, unsigned int Flags)
{
    void* memPtr;

    if (!Align && (Size & 0xF) == 0)
        Align = 0;
    if (tlCurSystemCallbacks.MemRealloc)
        memPtr = tlCurSystemCallbacks.MemRealloc(Ptr, Size, Align, Flags);
    else
        memPtr = _aligned_realloc(Ptr, Size, Align);
    if ((Flags & 2) == 0 && !memPtr && Size)
        tlFatal("Memory reallocation failed.");
    return memPtr;
}

/*
==============
tlGetFreeMemory
==============
*/
unsigned int tlGetFreeMemory()
{
    unsigned int freeMemory;
    HANDLE currentProcess;
    PROCESS_MEMORY_COUNTERS pmc;
    MEMORYSTATUS stat;

    freeMemory = 0;
    GlobalMemoryStatus(&stat);
    GetCurrentProcess();
    currentProcess = OpenProcess(0x410u, 0, GetCurrentProcessId());
    if (GetProcessMemoryInfo(currentProcess, &pmc, 40))
        freeMemory = stat.dwTotalPhys - pmc.PeakWorkingSetSize;
    CloseHandle(currentProcess);
    return freeMemory;
}

/*
==============
tlScratchPadInit
==============
*/
void *tlScratchPadInit()
{
    void* scratchPadPtr;

    if (tlScratchPadRefCount++)
        return tlScratchPadPtr;
    ++tlMemAllocCounter;
    if (tlCurSystemCallbacks.MemAlloc)
        scratchPadPtr = tlCurSystemCallbacks.MemAlloc(0x4000u, 0x10u, 0);
    else
        scratchPadPtr = _aligned_malloc(0x4000u, 0x10u);
    if (!scratchPadPtr)
        tlFatal("Memory allocation failed. %d bytes, %d align", 0x4000, 16);
    tlScratchPadPtr = scratchPadPtr;
    return scratchPadPtr;
}

/*
==============
tlScratchPadReset
==============
*/
void tlScratchPadReset()
{
    if (tlScratchPadRefCount < 1
        && _tlAssert(__FILE__, __LINE__, "tlScratchPadRefCount >= 1", "Scratchpad reset underflow."))
    {
        __debugbreak();
    }
    if (!--tlScratchPadRefCount)
    {
        --tlMemAllocCounter;
        if (tlCurSystemCallbacks.MemFree)
            tlCurSystemCallbacks.MemFree(tlScratchPadPtr);
        else
            _aligned_free(tlScratchPadPtr);
        tlScratchPadPtr = 0;
    }
}

/*
==============
tlWarning
==============
*/
void tlWarning(const char *Format, ...)
{
    char Work[512];
    va_list ap;

    va_start(ap, Format);
    vsprintf(Work, Format, ap);
    if (tlCurSystemCallbacks.Warning)
        tlCurSystemCallbacks.Warning(Work);
    else
        tlPrintf("%s", Work);
}

