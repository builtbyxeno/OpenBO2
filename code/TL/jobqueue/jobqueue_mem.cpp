/*
==============
jqSetCheckContext
==============
*/
void jqSetCheckContext(const char *desc)
{
  jqCheckContext = desc;
}

/*
==============
jqCheckDMALS
==============
*/
void jqCheckDMALS(const void *addr)
{
  if ( !addr )
    tlFatal("%s (LS) is NULL.", jqCheckContext);
  if ( (unsigned __int8)addr & 0xF )
    tlFatal("%s 0x%x (LS) not 16byte aligned.", jqCheckContext, addr);
  if ( (unsigned int)addr > 0x40000 )
    tlFatal("%s 0x%x (LS) is > 256k.", jqCheckContext, addr);
  if ( (unsigned int)addr < 0x4000 )
    tlFatal("%s 0x%x (LS) is in kernel memory.", jqCheckContext, addr);
}

/*
==============
jqCheckDMAMain
==============
*/
void jqCheckDMAMain(const void *addr)
{
  if ( !addr )
    tlFatal("%s (Main) is NULL.", jqCheckContext);
  if ( (unsigned __int8)addr & 0xF )
    tlFatal("%s 0x%x (Main) not 16byte aligned.", jqCheckContext, addr);
  if ( (unsigned int)addr < 0x40000 )
    tlFatal("%s 0x%x (Main) is < 256k.", jqCheckContext, addr);
}

/*
==============
jqCheckDMASize
==============
*/
void jqCheckDMASize(unsigned int size)
{
  if ( size & 0xF )
    tlFatal("%s size %d not 16byte aligned.", jqCheckContext, size);
}

/*
==============
jqCheckDMATag
==============
*/
void jqCheckDMATag(int tag)
{
  if ( tag < 0 || tag >= 31 )
    tlFatal("%s invalid DMA tag %d.", jqCheckContext, tag);
}

/*
==============
jqCheckRange
==============
*/
void jqCheckRange(int val, int mn, int mx)
{
  if ( val < mn || val > mx )
    tlFatal("%s %d out of range [%d-%d].", jqCheckContext, val, mn, mx);
}

/*
==============
jqCheckStack
==============
*/
void jqCheckStack(void)
{
	//Failed decompiling
}

/*
==============
jqFetch
==============
*/
void *jqFetch(void *dest, const void *src, unsigned int size)
{
  if ( size )
    memcpy((char *)dest, (char *)src, size);
  return dest;
}

/*
==============
jqStore
==============
*/
void jqStore(void *dest, const void *src, unsigned int size)
{
  if ( size )
    memcpy((char *)dest, (char *)src, size);
}

/*
==============
jqFetchAsync
==============
*/
void *jqFetchAsync(void *dest, const void *src, unsigned int size)
{
  if ( size )
    memcpy((char *)dest, (char *)src, size);
  return dest;
}

/*
==============
jqStoreAsync
==============
*/
void jqStoreAsync(void *dest, const void *src, unsigned int size)
{
  if ( size )
    memcpy((char *)dest, (char *)src, size);
}

/*
==============
jqWait
==============
*/
void jqWait(uint)
{
	//Failed decompiling
}

/*
==============
jqWaitMultiple
==============
*/
void jqWaitMultiple(uint)
{
	//Failed decompiling
}

/*
==============
jqSetMemBase
==============
*/
void jqSetMemBase(void const *)
{
	//Failed decompiling
}

/*
==============
jqSetStackSize
==============
*/
void jqSetStackSize(int)
{
	//Failed decompiling
}

/*
==============
jqGetMemAvailable
==============
*/
int jqGetMemAvailable()
{
  return 0;
}

/*
==============
jqAlloc
==============
*/
void *jqAlloc()
{
  return 0;
}

/*
==============
jqGetMemBase
==============
*/
void *jqGetMemBase()
{
  return 0;
}

