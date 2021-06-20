#ifndef R_PIX_PROFILE_H
#define R_PIX_PROFILE_H

#include <qcommon/threads.h>
#include <d3d9.h>

extern "C" {
    void PIXBeginNamedEvent(int Color, const char* Name, ...) {
        wchar_t w[256]; // [esp+0h] [ebp-204h] BYREF

        if (Sys_IsRenderThread())
        {
            MultiByteToWideChar(0, 0, Name, -1, w, 256);
            D3DPERF_BeginEvent(Color, w);
        }
    }

    void PIXSetMarker(int Color, const char* Name, ...)
    {
        wchar_t w[256]; // [esp+0h] [ebp-204h] BYREF

        if (Sys_IsRenderThread())
        {
            MultiByteToWideChar(0, 0, Name, -1, w, 256);
            D3DPERF_SetMarker(Color, w);
        }
    }
}

#endif // R_PIX_PROFILE_H