//#include <include/tl_thread.h>
#include "types.h"
#include "functions.h"
#include "mjpeg_public.h"

void *mjpeg_hEvent;
bool mjpeg_run_encoder;
bool mjpeg_quit_encoder;
bool mjpeg_inited;

void (*mjpeg_current_callback)(char *, char *, char *);

/*
==============
mjpeg_initonce

==============
*/
void mjpeg_initonce()
{
    unsigned int threadId;

    mjpeg_hEvent = CreateEventA(NULL, 0, 0, NULL);
    CreateThread(NULL, 0x10000u, mjpeg_thread, NULL, 0, (LPDWORD)&threadId);
    SetThreadName(threadId, "MJPEG Thread");
    mjpeg_inited = 1;
}

/*
==============
mjpeg_set_callback

==============
*/
void mjpeg_set_callback(void (*callback)(char *, char *, char *))
{
    mjpeg_current_callback = callback;
}

/*
==============
mjpeg_init

==============
*/
void mjpeg_init()
{
    mjpeg_set_callback(mjpeg_add_frame);
}

/*
==============
mjpeg_is_encoding

==============
*/
bool mjpeg_is_encoding()
{
    return mjpeg_run_encoder;
}

/*
==============
mjpeg_thread
==============
*/
DWORD WINAPI mjpeg_thread(void *context)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
mjpeg_close

==============
*/
void mjpeg_close()
{
    if ( !mjpeg_run_encoder )
    {
        return;
    }

    mjpeg_quit_encoder = 1;
    while ( mjpeg_quit_encoder )
    {
        PulseEvent(mjpeg_hEvent);
        Sleep(0xAu);
    }
}

/*
==============
mjpeg_draw

==============
*/
void mjpeg_draw(IDirect3DDevice9* device, IDirect3DTexture9* frame)
{
    if ( mjpeg_run_encoder && yuv_encode_frame() )
    {
        PulseEvent(mjpeg_hEvent);
    }
}

