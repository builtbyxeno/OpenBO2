#include "types.h"
#include "functions.h"

/*
==============
LiveVote_History_FileshareToVoteCategory
==============
*/
dwVoteCategory_e LiveVote_History_FileshareToVoteCategory(int fileshareCategory)
{
	UNIMPLEMENTED(__FUNCTION__);
	dwVoteCategory_e tmp;
	return tmp;
}

/*
==============
LiveVote_History_GetEntryLinear
==============
*/
int LiveVote_History_GetEntryLinear(int startIndex, unsigned __int64 entityID, dwVoteCategory_e category)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LiveVote_History_GetEntry
==============
*/
int LiveVote_History_GetEntry(const ControllerIndex_t localControllerIndex, dwVoteCategory_e category, unsigned __int64 entityToFind)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LiveVote_History_SortComparator
==============
*/
int LiveVote_History_SortComparator(const void *a, const void *b)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LiveVote_History_Sort
==============
*/
void LiveVote_History_Sort()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
LiveVote_History_RecordVote
==============
*/
void LiveVote_History_RecordVote(dwVoteCategory_e a1, const ControllerIndex_t localControllerIndex, unsigned __int64 entity, dwVoteCategory_e category, dwVote_e vote)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
LiveVote_History_GetVoteForEntity
==============
*/
int LiveVote_History_GetVoteForEntity(dwVoteCategory_e a1, ControllerIndex_t a2, const ControllerIndex_t localControllerIndex, unsigned __int64 entity, dwVoteCategory_e category)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LiveVote_RecentlyLiked_Build
==============
*/
void LiveVote_RecentlyLiked_Build(const ControllerIndex_t localControllerIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
LiveVote_RecentlyLiked_Remove
==============
*/
void LiveVote_RecentlyLiked_Remove(const ControllerIndex_t localControllerIndex, unsigned __int64 entity, dwVoteCategory_e category)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
LiveVote_RecentlyLiked_Add
==============
*/
void LiveVote_RecentlyLiked_Add(const ControllerIndex_t localControllerIndex, unsigned __int64 entity, dwVoteCategory_e category)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
LiveVote_Task_SubmitVoteSuccess
==============
*/
char __cdecl LiveVote_Task_SubmitVoteSuccess(TaskRecord *task)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LiveVote_Task_SubmitVoteFailure
==============
*/
char LiveVote_Task_SubmitVoteFailure(TaskRecord *task)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LiveVote_Task_SubmitVote
==============
*/
TaskRecord *LiveVote_Task_SubmitVote(const ControllerIndex_t localControllerIndex, unsigned __int64 entity, dwVoteCategory_e category, dwVote_e vote)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
LiveVote_Task_DownloadHistoryFailure
==============
*/
char LiveVote_Task_DownloadHistoryFailure(TaskRecord *task)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LiveVote_SubmitCmd
==============
*/
void __cdecl LiveVote_SubmitCmd(dwVote_e vote)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
LiveVote_SubmitLikeCmd
==============
*/
void LiveVote_SubmitLikeCmd()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
LiveVote_SubmitDislikeCmd
==============
*/
void LiveVote_SubmitDislikeCmd()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
LiveVote_GetHistoryCmd
==============
*/
void LiveVote_GetHistoryCmd()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
LiveVote_GetVoteCmd
==============
*/
void LiveVote_GetVoteCmd()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
LiveVote_FillVoteHistoryCmd
==============
*/
void LiveVote_FillVoteHistoryCmd()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
LiveVote_Init
==============
*/
void LiveVote_Init()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
LiveVote_Task_DownloadHistorySuccess
==============
*/
char LiveVote_Task_DownloadHistorySuccess(TaskRecord *task)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

