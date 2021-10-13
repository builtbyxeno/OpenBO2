#include "types.h"
#include "vars.h"
#include <win32/win32_public.h>

/*
==============
Sys_SystemMemoryMB
==============
*/
int Sys_SystemMemoryMB()
{
    const char* title;
    const char* body;
    HWND hwnd;
    int result;
    int sysMB;
    HINSTANCE hm;
    _MEMORYSTATUS status;
    int (WINAPI * MemStatEx)(_MEMORYSTATUSEX*);
    _MEMORYSTATUSEX statusEx;

    hm = GetModuleHandleA("kernel32.dll");
    if (hm && (MemStatEx = (int (WINAPI*)(_MEMORYSTATUSEX*))GetProcAddress(hm, "GlobalMemoryStatusEx")) != NULL)
    {
        statusEx.dwLength = 64;
        MemStatEx(&statusEx);
        if (statusEx.ullAvailVirtual < 0x8000000)
        {
            title = Win_LocalizeRef("WIN_LOW_MEMORY_TITLE");
            body = Win_LocalizeRef("WIN_LOW_MEMORY_BODY");
            hwnd = GetActiveWindow();
            if (MessageBoxA(hwnd, body, title, 0x34u) != 6)
            {
                //Sys_NormalExit();
                exit(0);
            }
        }

        sysMB = (int)((statusEx.ullTotalPhys * 0.00000095367432) + 0.4999999990686774);
        if (statusEx.ullTotalPhys > sysMB * 1048576.0 || sysMB > 1024)
        {
            sysMB = 4096;
        }
        return sysMB;
    }
    else
    {
        status.dwLength = 32;
        GlobalMemoryStatus(&status);
        if (status.dwAvailVirtual < 0x8000000)
        {
            title = Win_LocalizeRef("WIN_LOW_MEMORY_TITLE");
            body = Win_LocalizeRef("WIN_LOW_MEMORY_BODY");
            hwnd = GetActiveWindow();
            if (MessageBoxA(hwnd, body, title, 0x34u) != 6)
            {
                //Sys_NormalExit();
                exit(0);
            }
        }

        sysMB = (int)(status.dwTotalPhys * 0.00000095367432 + 0.4999999990686774);
        if (status.dwTotalPhys > sysMB * 1048576.0 || sysMB > 1024)
        {
            sysMB = 4096;
        }
        return sysMB;
    }
}

/*
==============
Sys_DetectVideoCard
==============
*/
void Sys_DetectVideoCard(int descLimit, char *description)
{
    IDXGIAdapter* adapter;
    IDXGIFactory* factory;
    DXGI_ADAPTER_DESC AdapterDesc;

    if (CreateDXGIFactory(__uuidof(IDXGIFactory), (void**)&factory) >= 0)
    {
        if (factory->EnumAdapters(0, &adapter) >= 0)
        {
            adapter->GetDesc(&AdapterDesc);
            adapter->Release();
            wcstombs(description, AdapterDesc.Description, descLimit);
        }
        factory->Release();
    }
}

/*
==============
Sys_CopyCpuidString
==============
*/
void Sys_CopyCpuidString(char *dest, const char *source, unsigned int maxLen)
{
    unsigned int from;
    unsigned int to;

    for (from = 0; from < maxLen; ++from)
    {
        if (source[from] != ' ')
        {
            break;
        }
    }

    to = 0;
    while (from < maxLen && source[from])
    {
        dest[to++] = source[from++];
    }
    dest[to] = 0;
}

/*
==============
Sys_DetectCpuVendorAndName
==============
*/
void Sys_DetectCpuVendorAndName(char *vendor, char *name)
{
    int CPUInfo[4] = { -1 };
    unsigned nExIds, i = 0;
    int regs[4] = { 0 };

    // Get the information associated with each extended ID.
    __cpuid(CPUInfo, 0x80000000);
    nExIds = CPUInfo[0];
    for (i = 0x80000000; i <= nExIds; ++i)
    {
        __cpuid(CPUInfo, i);
        // Interpret CPU brand string
        if (i == 0x80000002)
            memcpy(name, CPUInfo, sizeof(CPUInfo));
        else if (i == 0x80000003)
            memcpy(name + 16, CPUInfo, sizeof(CPUInfo));
        else if (i == 0x80000004)
            memcpy(name + 32, CPUInfo, sizeof(CPUInfo));
    }

    __cpuid(regs, 0);              // mov eax,0; cpuid
    memcpy(vendor, &regs[1], 4);   // copy EBX
    memcpy(vendor + 4, &regs[3], 4); // copy EDX
    memcpy(vendor + 8, &regs[2], 4); // copy ECX
    vendor[12] = '\0';
}

/*
==============
Sys_AddApicIdIfUnique
==============
*/
unsigned int Sys_AddApicIdIfUnique(unsigned int apicId, unsigned int *existingApicId, unsigned int existingCount)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Sys_GetPhysicalCpuCount
==============
*/
void Sys_GetPhysicalCpuCount(SysInfo *sysInfo)
{
    unsigned int logicalPerPhysical;
    unsigned regs[4];

    __cpuid((int*)regs, (int)1);
    sysInfo->logicalCpuCount = (regs[1] >> 16) & 0xff;
    sysInfo->physicalCpuCount = sysInfo->logicalCpuCount;

    if (strcmp(sysInfo->cpuVendor, "GenuineIntel"))
    {
        __cpuid((int*)regs, (int)4);
        sysInfo->physicalCpuCount = ((regs[0] >> 26) & 0x3f) + 1;
    }
    else if (sysInfo->cpuVendor, "AuthenticAMD") {
        __cpuid((int*)regs, (int)0x80000008);
        sysInfo->physicalCpuCount = ((unsigned)(regs[2] & 0xff)) + 1;
    }
}

/*
==============
Sys_BenchmarkGHz
==============
*/
long double Sys_BenchmarkGHz()
{
    HANDLE threadInfo;
    int priority;
    LARGE_INTEGER qwWait, qwStart, qwCurrent;

    threadInfo = GetCurrentThread();
    priority = GetThreadPriority(threadInfo);
    SetThreadPriority(threadInfo, 15);

    QueryPerformanceCounter(&qwStart);
    QueryPerformanceFrequency(&qwWait);
    qwWait.QuadPart >>= 5;
    unsigned __int64 Start = __rdtsc();
    do
    {
        QueryPerformanceCounter(&qwCurrent);
    } while (qwCurrent.QuadPart - qwStart.QuadPart < qwWait.QuadPart);
    SetThreadPriority(threadInfo, priority);
    return ((__rdtsc() - Start) << 5) / 1000000.0;
}

/*
==============
Sys_SetAutoConfigureGHz
==============
*/
void Sys_SetAutoConfigureGHz(SysInfo *sysInfo)
{
    double multiCpuFactor;

    Sys_GetPhysicalCpuCount(sysInfo);

    sysInfo->physicalCpuCount = 4;

    assertMsg(!(sysInfo->physicalCpuCount < 1), "sysInfo->physicalCpuCount >= 1\n\t%i, %i", sysInfo->physicalCpuCount, 1)

    if (sysInfo->physicalCpuCount == 1)
    {
        multiCpuFactor = 1.0;
    }
    else if (sysInfo->physicalCpuCount == 2)
    {
        multiCpuFactor = 1.75;
    }
    else
    {
        multiCpuFactor = 2.0;
    }
    sysInfo->configureGHz = Sys_BenchmarkGHz() * multiCpuFactor;
}

