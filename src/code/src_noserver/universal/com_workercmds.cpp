#include "types.h"
#include "functions.h"

/*
==============
Sys_WorkerCmdInit
==============
*/
void Sys_WorkerCmdInit()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Sys_IsWorkerCmdReady
==============
*/
bool Sys_IsWorkerCmdReady()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
jqCommitMemory
==============
*/
unsigned int *jqCommitMemory(jqBatch *batch, void *input, unsigned int dataSize)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
jqSafeFlush
==============
*/
void jqSafeFlush(jqBatchGroup *group, unsigned __int64 batchCount)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
jqCallbackPre
==============
*/
unsigned int *jqCallbackPre(jqBatch *batch, const char *name)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
jqCallbackPost
==============
*/
void jqCallbackPost(jqBatch *batch, void *data, bool finished)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Sys_AddWorkerCmdToQueueInternal
==============
*/
void Sys_AddWorkerCmdToQueueInternal(jqWorkerCmd *name, void *data, jqQueue *toQueue, WorkerCmdConditional *cond)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Sys_AddWorkerCmdInternal
==============
*/
void Sys_AddWorkerCmdInternal(jqWorkerCmd *name, void *data, WorkerCmdConditional *cond)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Sys_AddWorkerCmdGroupedToQueueInternal
==============
*/
void Sys_AddWorkerCmdGroupedToQueueInternal(jqWorkerCmd *name, void *data, jqBatchGroup *group, jqQueue *toQueue, WorkerCmdConditional *cond)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Sys_AddWorkerCmdGroupedInternal
==============
*/
void Sys_AddWorkerCmdGroupedInternal(jqWorkerCmd *name, void *data, jqBatchGroup *group, WorkerCmdConditional *cond)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Sys_WaitWorkerCmdInternal
==============
*/
void Sys_WaitWorkerCmdInternal(jqWorkerCmd *name)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Sys_AssistSingleCallback
==============
*/
BOOL Sys_AssistSingleCallback(void *context)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Sys_AssistSingle
==============
*/
void Sys_AssistSingle()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Sys_AssistNeeded
==============
*/
bool Sys_AssistNeeded()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Sys_GetWorkerQueuedCountInternal
==============
*/
int Sys_GetWorkerQueuedCountInternal(jqWorkerCmd *name)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
R_FinishedFrontendWorkerCmds
==============
*/
BOOL R_FinishedFrontendWorkerCmds()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
R_WaitFrontendWorkerCmds
==============
*/
void R_WaitFrontendWorkerCmds()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Sys_AssistAndWaitWorkerCmdInternal
==============
*/
void Sys_AssistAndWaitWorkerCmdInternal(jqBatchGroup *group)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Sys_AssistAndWaitWorkerCmdInternal
==============
*/
void Sys_AssistAndWaitWorkerCmdInternal(jqWorkerCmd *name)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_WaitDrawWorkerCmdsOfType
==============
*/
void R_WaitDrawWorkerCmdsOfType(GfxWorkerData *workerData, unsigned __int8 cmdbufType)
{
	UNIMPLEMENTED(__FUNCTION__);
}

