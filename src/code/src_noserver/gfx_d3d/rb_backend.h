#include "types.h"
#include "vars.h"
#include <gfx_d3d/gfx_d3d_public.h>

/*
==============
RB_CheckTessOverflow
==============
*/
inline void RB_CheckTessOverflow(int vertexCount, int indexCount)
{
    assertMsg((vertexCount <= 5450), "(vertexCount) = %i", vertexCount);
    assertMsg((indexCount <= ((2 * 1024 * 1024) / 2)), "(indexCount) = %i", indexCount);
    if (vertexCount + tess.vertexCount > 5450 || indexCount + tess.indexCount > 0x100000)
    {
        RB_TessOverflow();
    }
}
