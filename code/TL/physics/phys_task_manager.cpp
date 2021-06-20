/*
==============
phys_task_manager_init
==============
*/
void phys_task_manager_init()
{
  if ( g_phys_task_manager_inited
    && _tlAssert("source/phys_task_manager.cpp", 30, "g_phys_task_manager_inited == 0", (const char *)&pBlock) )
  {
    __debugbreak();
  }
  if ( g_phys_task_manager_current_worker_count
    && _tlAssert(
         "source/phys_task_manager.cpp",
         31,
         "g_phys_task_manager_current_worker_count == 0",
         (const char *)&pBlock) )
  {
    __debugbreak();
  }
  g_phys_task_manager_inited = 1;
  g_phys_task_manager_batch.Module = NULL;
  g_phys_task_manager_batch.Input = NULL;
  g_phys_task_manager_batch.Output = NULL;
}

/*
==============
phys_task_manager_shutdown
==============
*/
void phys_task_manager_shutdown()
{
  if ( g_phys_task_manager_inited != 1
    && _tlAssert("source/phys_task_manager.cpp", 49, "g_phys_task_manager_inited == 1", (const char *)&pBlock) )
  {
    __debugbreak();
  }
  if ( g_phys_task_manager_current_worker_count
    && _tlAssert(
         "source/phys_task_manager.cpp",
         50,
         "g_phys_task_manager_current_worker_count == 0",
         (const char *)&pBlock) )
  {
    __debugbreak();
  }
  g_phys_task_manager_inited = 0;
}

/*
==============
phys_task_manager_needs_flush
==============
*/
bool phys_task_manager_needs_flush()
{
  if ( g_phys_task_manager_inited != 1
    && _tlAssert("source/phys_task_manager.cpp", 83, "g_phys_task_manager_inited == 1", (const char *)&pBlock) )
  {
    __debugbreak();
  }
  return g_phys_task_manager_current_worker_count > 0;
}

/*
==============
phys_task_manager_flush
==============
*/
void phys_task_manager_flush()
{
  if ( g_phys_task_manager_inited != 1
    && _tlAssert("source/phys_task_manager.cpp", 89, "g_phys_task_manager_inited == 1", (const char *)&pBlock) )
  {
    __debugbreak();
  }
  if ( g_phys_task_manager_current_worker_count > 0 )
  {
    g_phys_task_manager_current_worker_count = 0;
    IW_task_manager_flush();
  }
}

/*
==============
phys_task_manager_process
==============
*/
void phys_task_manager_process(jqModule *module, void *input, const int input_count)
{
  int v3; // eax
  int v4; // esi

  if ( g_phys_task_manager_inited != 1
    && _tlAssert("source/phys_task_manager.cpp", 60, "g_phys_task_manager_inited == 1", (const char *)&pBlock) )
  {
    __debugbreak();
  }
  if ( g_phys_task_manager_current_worker_count
    && _tlAssert(
         "source/phys_task_manager.cpp",
         61,
         "g_phys_task_manager_current_worker_count == 0",
         (const char *)&pBlock) )
  {
    __debugbreak();
  }
  v3 = input_count;
  if ( input_count )
  {
    if ( input_count > 6 )
      v3 = 6;
    g_phys_task_manager_current_worker_count = v3;
    g_phys_task_manager_batch.Module = module;
    g_phys_task_manager_batch.Input = input;
    if ( v3 > 0 )
    {
      v4 = v3;
      do
      {
        IW_task_manager_add_batch(&g_phys_task_manager_batch);
        --v4;
      }
      while ( v4 );
    }
  }
}

