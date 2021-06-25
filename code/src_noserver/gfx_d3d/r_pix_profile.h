/*
 * Copyright (c) 2020-2021 OpenIW
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms and conditions of the GNU General Public License,
 * version 2, as published by the Free Software Foundation.
 *
 * This program is distributed in the hope it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

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