#include "types.h"
#include "vars.h"
#include "functions.h"

/*
==============
FileWrapper_Open
==============
*/
FILE *FileWrapper_Open(const char *ospath, const char *mode)
{
    FILE* file;

    errno = 0;
    file = fopen(ospath, mode);
    if (file != (FILE*)-1)
    {
        return file;
    }

    assertMsg(va("Couldn't open file: %s %s", ospath, strerror(errno)));

    return 0;
}

/*
==============
FileWrapper_Seek
==============
*/
int FileWrapper_Seek(int h, int offset, int origin)
{
    switch (origin)
    {
    case 0:
        return fseek((FILE*)h, offset, 1);
    case 1:
        return fseek((FILE*)h, offset, 2);
    case 2:
        return fseek((FILE*)h, offset, 0);
    }
    assertMsg(va("Bad origin %i in FS_Seek", origin));

    return 0;
}

/*
==============
FileWrapper_GetFileSize
==============
*/
int FileWrapper_GetFileSize(int h)
{
    int startPos;
    int fileSize;

    startPos = ftell((FILE*)h);
    fseek((FILE*)h, 0, 2);

    fileSize = ftell((FILE*)h);
    fseek((FILE*)h, startPos, 0);

    return fileSize;
}
