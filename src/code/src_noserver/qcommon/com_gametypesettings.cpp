#include "types.h"
#include "functions.h"

/*
==============
Com_GametypeSetting_CacheDDLState
==============
*/
int Com_GametypeSetting_CacheDDLState()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Com_GametypeSettings_GetCACRoot
==============
*/
const CACRoot *Com_GametypeSettings_GetCACRoot(const CACRoot *result, team_t team)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Com_GametypeSettings_GetDDLMemberTypeForSetting
==============
*/
int Com_GametypeSettings_GetDDLMemberTypeForSetting(const char *settingName)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Com_GametypeSettings_GetUInt
==============
*/
unsigned int Com_GametypeSettings_GetUInt(GameTypeSettingsType setting)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Com_GametypeSettings_GetUInt
==============
*/
unsigned int Com_GametypeSettings_GetUInt(const char *settingName, bool getDefault)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Com_GametypeSettings_GetFloat
==============
*/
double Com_GametypeSettings_GetFloat(const char *settingName, bool getDefault)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Com_GametypeSettings_SetUInt
==============
*/
bool Com_GametypeSettings_SetUInt(const char *settingName, unsigned int newValue)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Com_GametypeSettings_SetFloat
==============
*/
bool Com_GametypeSettings_SetFloat(const char *settingName, float newValue)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Com_GametypeSettings_GametypeSetting_f
==============
*/
void Com_GametypeSettings_GametypeSetting_f()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Com_GametypeSettings_AreSettingsDirty
==============
*/
bool Com_GametypeSettings_AreSettingsDirty()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Com_GametypeSettings_ClearDirtyFlag
==============
*/
void Com_GametypeSettings_ClearDirtyFlag()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Com_GametypeSettings_Read
==============
*/
char Com_GametypeSettings_Read(msg_t *msg)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Com_GametypeSettings_Write
==============
*/
void Com_GametypeSettings_Write(msg_t *msg)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Com_GametypeSettings_ResetClassesToDefault
==============
*/
int Com_GametypeSettings_ResetClassesToDefault()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Com_GametypeSettings_GetCurrentPresetClassTeam
==============
*/
team_t Com_GametypeSettings_GetCurrentPresetClassTeam()
{
	UNIMPLEMENTED(__FUNCTION__);
	team_t tmp;
	return tmp;
}

/*
==============
Com_GametypeSettings_IsItemIndexRestricted
==============
*/
bool Com_GametypeSettings_IsItemIndexRestricted(int itemIndex, bool getDefault)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Com_GametypeSettings_IsAttachmentIndexRestricted
==============
*/
bool Com_GametypeSettings_IsAttachmentIndexRestricted(int attachmentIndex, bool getDefault)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Com_GametypeSettings_UploadSuccess
==============
*/
void Com_GametypeSettings_UploadSuccess(const ControllerIndex_t controllerIndex, unsigned __int64 fileID)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Com_GametypeSettings_UploadFailure
==============
*/
void Com_GametypeSettings_UploadFailure(const ControllerIndex_t controllerIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Com_GametypeSetting_SetMetada
==============
*/
bool Com_GametypeSetting_SetMetada(const ControllerIndex_t controllerIndex, unsigned __int8 *metaData, int metaDataSize)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Com_GametypeSetting_Upload
==============
*/
void Com_GametypeSetting_Upload(const ControllerIndex_t controllerIndex, int slot)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Com_GametypeSetting_DownloadFailure
==============
*/
void Com_GametypeSetting_DownloadFailure()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Com_GametypeSettings_Upload_f
==============
*/
void Com_GametypeSettings_Upload_f()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Com_GametypeSettings_ClearUploadInfo_f
==============
*/
void Com_GametypeSettings_ClearUploadInfo_f()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Com_GametypeSettings_SetName
==============
*/
void Com_GametypeSettings_SetName(const char *name)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Com_GametypeSettings_SetDescription
==============
*/
void Com_GametypeSettings_SetDescription(const char *description)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Com_GametypeSettings_SetGametype
==============
*/
void Com_GametypeSettings_SetGametype(const char *a1, const dvar_t *a2, char *a3, const char *gametype, bool loadDefaultSettings)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Com_GametypeSettings_SetGametype_f
==============
*/
void Com_GametypeSettings_SetGametype_f()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Com_GametypeSettings_RestrictItem_f
==============
*/
void Com_GametypeSettings_RestrictItem_f()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Com_GametypeSettings_RestrictAttachment_f
==============
*/
void Com_GametypeSettings_RestrictAttachment_f()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Com_GametypeSetting_DownloadSuccess
==============
*/
void Com_GametypeSetting_DownloadSuccess(const ControllerIndex_t controllerIndex, dwFileShareReadFileTask *task)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Com_GametypeSetting_Download
==============
*/
void Com_GametypeSetting_Download(const ControllerIndex_t controllerIndex, unsigned __int64 fileID, const char *gameType)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Com_GametypeSettings_Download_f
==============
*/
void __cdecl Com_GametypeSettings_Download_f()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Com_GametypeSettings_Init
==============
*/
void Com_GametypeSettings_Init()
{
	UNIMPLEMENTED(__FUNCTION__);
}

