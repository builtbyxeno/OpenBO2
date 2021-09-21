#include "types.h"
#include "functions.h"

/*
==============
ChunkAllocate
==============
*/
int ChunkAllocate(int index, int blocks)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
ChunkFree
==============
*/
void ChunkFree(int index, int blocks)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Task_Allocate
==============
*/
int Task_Allocate(int bytes)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Task_Deallocate
==============
*/
void Task_Deallocate(void *ptr, int bytes)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
TaskManager2_GetTaskRuleErrors
==============
*/
BOOL TaskManager2_GetTaskRuleErrors()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
TaskManager2_IsTimedIn
==============
*/
bool TaskManager2_IsTimedIn(TaskRecord *task)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
TaskManager2_ProcessXOverlappedTask
==============
*/
void TaskManager2_ProcessXOverlappedTask(TaskRecord *task)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
TaskManager2_RevertTask
==============
*/
void TaskManager2_RevertTask(TaskRecord *task)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
TaskManager2_ClearTask
==============
*/
void TaskManager2_ClearTask(TaskRecord *task)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
TaskManager2_ClearTasks
==============
*/
void TaskManager2_ClearTasks(const TaskDefinition *definition)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
TaskManager2_SkipCallbacksForTaskAfterComplete
==============
*/
void TaskManager2_SkipCallbacksForTaskAfterComplete(TaskRecord *task)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
TaskManager2_SkipCallbacksForTasksAfterComplete
==============
*/
void TaskManager2_SkipCallbacksForTasksAfterComplete(const TaskDefinition *definition)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
TaskManger2_TaskGetInProgressForControllerByName
==============
*/
char TaskManger2_TaskGetInProgressForControllerByName(const char *taskName, const ControllerIndex_t controllerIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
TaskManager2_TaskIsPending
==============
*/
BOOL TaskManager2_TaskIsPending(const TaskRecord *task)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
TaskManager2_DumpTasks
==============
*/
void TaskManager2_DumpTasks()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
TaskManager2_RunTaskRules
==============
*/
void TaskManager2_RunTaskRules(TaskRecord *task)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
TaskManager2_RecordTaskInfo
==============
*/
void TaskManager2_RecordTaskInfo(TaskRecord *task)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
TaskManager2_Init
==============
*/
void TaskManager2_Init()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
TaskManager2_ReportTaskComplete
==============
*/
void TaskManager2_ReportTaskComplete(TaskRecord *task, bool success, const char *reason, unsigned int errorcode)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
TaskManager2_FreeAllPendingTasksInternal
==============
*/
void TaskManager2_FreeAllPendingTasksInternal(const ControllerIndex_t localControllerIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
TaskManager2_HandleTimedOutTask
==============
*/
void TaskManager2_HandleTimedOutTask(TaskRecord *TimedOutTask)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
TaskManager2_ProcessLocalTask
==============
*/

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
}

/*
==============
TaskManager2_CancelEndlessTasks
==============
*/
void TaskManager2_CancelEndlessTasks(ControllerIndex_t localControllerIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
TaskManager2_ProcessDemonwareTask
==============
*/
void TaskManager2_ProcessDemonwareTask(TaskRecord *task)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
TaskManager2_ProcessNestedTask
==============
*/

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
}

/*
==============
TaskManager2_CreateTask
==============
*/
TaskRecord *TaskManager2_CreateTask(const TaskDefinition *definition, const ControllerIndex_t controllerIndex, TaskRecord *nestTask, int timeout)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
TaskManager2_EnumTasksInProgress
==============
*/
void TaskManager2_EnumTasksInProgress(void (*func)(TaskRecord *, void *), void *inData)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
TaskManager2_TaskGetInProgressForController
==============
*/
TaskRecord *TaskManager2_TaskGetInProgressForController(const TaskDefinition *definition, const ControllerIndex_t controllerIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
TaskManager2_TaskGetInProgress
==============
*/
TaskRecord *TaskManager2_TaskGetInProgress(const TaskDefinition *definition)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
TaskManager2_TaskGetInProgressCallBackSkipCallbacks
==============
*/
TaskRecord *TaskManager2_TaskGetInProgressCallBackSkipCallbacks(const TaskDefinition *definition)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
TaskManager2_TaskIsInProgressForController
==============
*/
BOOL TaskManager2_TaskIsInProgressForController(const TaskDefinition *definition, const ControllerIndex_t controllerIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
TaskManager2_TaskIsInProgress
==============
*/
BOOL TaskManager2_TaskIsInProgress(const TaskDefinition *definition)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
TaskManager2_CountTasksInProgress
==============
*/
int TaskManager2_CountTasksInProgress(const TaskDefinition *definition)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
TaskManager2_CountTasksInProgressForControllerByType
==============
*/
int TaskManager2_CountTasksInProgressForControllerByType(const int controllerindex, const unsigned __int64 type)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
TaskManager2_FreeDeadTasks
==============
*/
void TaskManager2_FreeDeadTasks(const ControllerIndex_t localControllerIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
TaskManager2_ProcessTasks
==============
*/
void TaskManager2_ProcessTasks(const ControllerIndex_t localControllerIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
TaskManager2_StartTask
==============
*/
void TaskManager2_StartTask(TaskRecord *task)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
TaskManager2_SetupNestedTask
==============
*/
TaskRecord *TaskManager2_SetupNestedTask(const TaskDefinition *taskdef, ControllerIndex_t controllerIndex, TaskRecord *nestedTask, void *payload)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
TaskManager2_SetupRemoteTask
==============
*/
TaskRecord *TaskManager2_SetupRemoteTask(const TaskDefinition *definition, const ControllerIndex_t controllerIndex, bdRemoteTask *remoteTask, void *payload)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
TaskManager2_ComErrorCleanup
==============
*/
void TaskManager2_ComErrorCleanup()
{
	UNIMPLEMENTED(__FUNCTION__);
}

