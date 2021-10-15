#pragma once

#include "types.h"

//cod/codsrc/src/mjpeg/avi.cpp
unsigned int mjpeg_write_thread(void *__formal);
// void __thiscall avi_s::write_thread();
void mjpeg_create(const char *szFile, int width, int height, int fps);
// void __thiscall avi_s::create(const char *szFile, int width, int height, int fps);
void mjpeg_add_frame(char *y, char *u, char *v);
// void __thiscall avi_s::add_frame(avi_s *this, char *y, char *u, char *v);
// unsigned int __thiscall avi_s::output_data(void *data, unsigned int size);
void mjpeg_close_int();
// void __thiscall avi_s::close(avi_s *this);
// void __thiscall avi_s::flush_samples(avi_s *this);
void mjpeg_add_samples(short *in, int count);
// void __thiscall avi_s::add_samples(avi_s *this, short *in, int count);

//#include "mjpeg/avi.h"

//cod/codsrc/src/mjpeg/jpeg.cpp
// void jpeg_encode::dct(short *out, char *in, int pitch);
// void __thiscall jpeg_encode::init_quant(jpeg_encode *this, int quality_factor);
// void jpeg_encode::quant(short *out, short *in, unsigned short *quant_table_ptr);
// char *__thiscall jpeg_encode::huffman(jpeg_encode *this, char *out, short *in, jpeg_encode_state *channel);
// char *__thiscall jpeg_encode::do_block(jpeg_encode *this, char *out, char *in, int pitch, jpeg_encode_state *channel);
void Out32(char **out, unsigned int d);
void OutRational(char **out, float val, int div);
// char *jpeg_encode::write_header@<eax>(jpeg_encode *this@<ecx>, float a2@<ebp>, char *out, int width, int height, bool greyscale, bool tables, jpeg_exif *exif);
// char *__thiscall jpeg_encode::begin(jpeg_encode *this, char *out, int width, int height, int quality, bool tables, jpeg_exif *exif);
// char *__thiscall jpeg_encode::end(char *out);
// char *__thiscall jpeg_encode::encode(jpeg_encode *this, char *out, int width, int height, int pitch, int quality, char *y, char *u, char *v, bool tables, jpeg_exif *exif);

//cod/codsrc/src/mjpeg/jpeg_screenshot.cpp
void jpeg_screenshot_set_frame_info(int width, int height, int row, int col, int tiles, float tileX, float tileY, int yOffset, float yAspect, float progress);
char *jpeg_screenshot_chunk(char *out, jpeg_encode *encode);
void jpeg_screenshot_tile(char *outY, char *outU, char *outV);
char *jpeg_screenshot_row(char *out, char *inY, char *inU, char *inV, int row, jpeg_encode *encode);

//cod/codsrc/src/mjpeg/mjpeg.cpp
void mjpeg_initonce();
void mjpeg_set_callback(void (*callback)(char *, char *, char *));
void mjpeg_init();
bool mjpeg_is_encoding();
DWORD WINAPI mjpeg_thread(void *context);
void mjpeg_close();
void mjpeg_draw(IDirect3DDevice9* device, IDirect3DTexture9* frame);

//cod/codsrc/src/mjpeg/vpx.cpp
void vpx_init(const char *filename, int width, int height);
void write_ivf_file_header(FILE *outfile, vpx_codec_enc_cfg *cfg, int frame_cnt);
void mem_put_le16(char *mem, unsigned int val);
void mem_put_le32(char *mem, unsigned int val);
void vpx_encode_frame(char *y, char *u, char *v, bool eof);
void write_ivf_frame_header(FILE *outfile, vpx_codec_cx_pkt *pkt);
void vpx_shutdown();

//cod/codsrc/src/mjpeg/yuv.cpp
void yuv_init_internal();
void yuv_init(int width, int height, bool double_buffer);
char yuv_encode_frame();
void yuv_get_buffers(char **y, char **u, char **v);
void yuv_shutdown_internal();
void yuv_shutdown();
void yuv_lost_device();
void yuv_recover_device();

