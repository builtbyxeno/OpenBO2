#include "types.h"
#include "functions.h"

/*
==============
TRACK_r_buffers
==============
*/
void TRACK_r_buffers()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_LockVertexBuffer
==============
*/
char *R_LockVertexBuffer(ID3D11DeviceContext *device, ID3D11Buffer *handle, int offset, int bytes, int lockFlags)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
R_UnlockVertexBuffer
==============
*/
void R_UnlockVertexBuffer(ID3D11DeviceContext *device, ID3D11Buffer *handle)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_LockIndexBuffer
==============
*/
char *R_LockIndexBuffer(ID3D11DeviceContext *device, ID3D11Buffer *handle, int offset, int bytes, int lockFlags)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
R_UnlockIndexBuffer
==============
*/
void R_UnlockIndexBuffer(ID3D11DeviceContext *device, ID3D11Buffer *handle)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_AllocDynamicVertexBuffer
==============
*/
void *R_AllocDynamicVertexBuffer(ID3D11Buffer **vb, int sizeInBytes)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
R_AllocStaticVertexBuffer
==============
*/
void *R_AllocStaticVertexBuffer(ID3D11Buffer **vb, int sizeInBytes, const void *data)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
R_AllocDynamicIndexBuffer
==============
*/
void *R_AllocDynamicIndexBuffer(ID3D11Buffer **ib, int sizeInBytes)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
R_AllocStaticIndexBuffer
==============
*/
void *R_AllocStaticIndexBuffer(ID3D11Buffer **ib, int sizeInBytes, const void *data)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Load_IndexBuffer
==============
*/
void Load_IndexBuffer(ID3D11Buffer **ib, void *bufferData, int indexCount)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Load_VertexBuffer
==============
*/
void Load_VertexBuffer(ID3D11Buffer **vb, void *bufferData, int sizeInBytes)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_InitDynamicVertexBufferState
==============
*/
void R_InitDynamicVertexBufferState(GfxVertexBufferState *vb, int bytes)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_InitSkinnedVertexBuffers
==============
*/
void R_InitSkinnedVertexBuffers(const SkinnedVertsDef *sv)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_FreeStaticVertexBuffer
==============
*/
void R_FreeStaticVertexBuffer(ID3D11Buffer *vb)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_FreeStaticIndexBuffer
==============
*/
void R_FreeStaticIndexBuffer(ID3D11Buffer *ib)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_ShutdownSkinnedVertexBuffers
==============
*/
void R_ShutdownSkinnedVertexBuffers()
{
	UNIMPLEMENTED(__FUNCTION__);
}

