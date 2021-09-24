#include "types.h"

/*
==============
UI_EmblemPool_Get
==============
*/
emblemDownloadData_t *UI_EmblemPool_Get(unsigned __int64 fileID)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
UI_EmblemClampLayer
==============
*/
void UI_EmblemClampLayer(CompositeEmblemLayer *layer)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_DrawCustomEmblem
==============
*/
void UI_DrawCustomEmblem(UIContextIndex_t contextIndex, const rectDef_s *rect, const vec4_t *color)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_DrawEmblemSelector
==============
*/
void UI_DrawEmblemSelector(const LocalClientNum_t localClientNum, UIContextIndex_t contextIndex, itemDef_s *item, const rectDef_s *rect, const vec4_t *color)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_DrawEmblemIconThumbnail
==============
*/
void UI_DrawEmblemIconThumbnail(UIContextIndex_t contextIndex, const rectDef_s *rect, const vec4_t *color)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_EmblemUpdate
==============
*/
void UI_EmblemUpdate()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_EmblemGetSelectedLayer
==============
*/
int UI_EmblemGetSelectedLayer()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
UI_EmblemCanOutlineLayer
==============
*/
bool UI_EmblemCanOutlineLayer(int layer)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
UI_EmblemCanDuplicateLayer
==============
*/
BOOL UI_EmblemCanDuplicateLayer(ControllerIndex_t controllerIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
UI_EmblemDuplicate_f
==============
*/
void UI_EmblemDuplicate_f()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_EmblemGetLayerName
==============
*/
const GfxViewParms *UI_EmblemGetLayerName(int layer)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
UI_EmblemGetSelectedBackgroundID
==============
*/
__int16 UI_EmblemGetSelectedBackgroundID()
{
	UNIMPLEMENTED(__FUNCTION__);
	__int16 tmp;
	return tmp;
}

/*
==============
UI_EmblemGetStateDisplay
==============
*/
const char *UI_EmblemGetStateDisplay(ControllerIndex_t controllerIndex, int idx)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
UI_EmblemGetCategoryDisplay
==============
*/
char *UI_EmblemGetCategoryDisplay(ControllerIndex_t controllerIndex, int idx)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
UI_EmblemGetFilterCount
==============
*/
int UI_EmblemGetFilterCount(ControllerIndex_t controllerIndex, int state, int category)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
UI_EmblemGetFilterIconID
==============
*/
__int16 UI_EmblemGetFilterIconID(ControllerIndex_t controllerIndex, int state, int category, int index)
{
	UNIMPLEMENTED(__FUNCTION__);
	__int16 tmp;
	return tmp;
}

/*
==============
UI_EmblemUpload_SetMetada
==============
*/
bool UI_EmblemUpload_SetMetada(const ControllerIndex_t controllerIndex, unsigned __int8 *metaData, int metaDataSize)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
UI_EmblemUploadToSlotSuccess
==============
*/
void UI_EmblemUploadToSlotSuccess(const ControllerIndex_t controllerIndex, unsigned __int64 fileID)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_EmblemUploadToSlotFailure
==============
*/
void UI_EmblemUploadToSlotFailure(const ControllerIndex_t controllerIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_EmblemUploadToSlot
==============
*/
void UI_EmblemUploadToSlot(const ControllerIndex_t controllerIndex, int slot, bool setToProfile)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_EmblemSetName
==============
*/
void UI_EmblemSetName(const char *name)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_EmblemSetDescription
==============
*/
void UI_EmblemSetDescription(const char *description)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_EmblemClearUploadInfo_f
==============
*/
void UI_EmblemClearUploadInfo_f()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_EmblemSelect_f
==============
*/
void UI_EmblemSelect_f()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_EmblemReset_f
==============
*/
void UI_EmblemReset_f()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_EmblemClear_f
==============
*/
void UI_EmblemClear_f()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_EmblemDelete_f
==============
*/
void UI_EmblemDelete_f()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_EmblemClearAll_f
==============
*/
void UI_EmblemClearAll_f()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_EmblemClearClipboard_f
==============
*/
void UI_EmblemClearClipboard_f()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_EmblemRotate_f
==============
*/
void UI_EmblemRotate_f()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_EmblemMove_f
==============
*/
void UI_EmblemMove_f()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_EmblemScale_f
==============
*/
void UI_EmblemScale_f()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_EmblemIcon_f
==============
*/
void UI_EmblemIcon_f()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_EmblemSetSelectedLayerIconId_f
==============
*/
void UI_EmblemSetSelectedLayerIconId_f()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_EmblemSetEmptyBoxIconId_f
==============
*/
void UI_EmblemSetEmptyBoxIconId_f()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_EmblemPalette_f
==============
*/
void UI_EmblemPalette_f()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_EmblemOutline_f
==============
*/
void UI_EmblemOutline_f()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_EmblemToggleOutline_f
==============
*/
void UI_EmblemToggleOutline_f()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_EmblemFlip_f
==============
*/
void UI_EmblemFlip_f()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_EmblemToggleFlip_f
==============
*/
void UI_EmblemToggleFlip_f()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_EmblemLayerIncreaseOpacity_f
==============
*/
void UI_EmblemLayerIncreaseOpacity_f()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_EmblemLayerDecreaseOpacity_f
==============
*/
void UI_EmblemLayerDecreaseOpacity_f()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_EmblemLayerSetOpacity_f
==============
*/
void UI_EmblemLayerSetOpacity_f()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_EmblemSetScaleMode_f
==============
*/
void UI_EmblemSetScaleMode_f()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_EmblemMoveLayer
==============
*/
void UI_EmblemMoveLayer(ControllerIndex_t controllerIndex, int targetz)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_EmblemSetLayerColorRGB_f
==============
*/
void UI_EmblemSetLayerColorRGB_f()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_EmblemSetSelectedRecentColor_f
==============
*/
void UI_EmblemSetSelectedRecentColor_f()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_EmblemSetRecentColorRGBA_f
==============
*/
void UI_EmblemSetRecentColorRGBA_f()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_EmblemSetRGBTweakedColor_f
==============
*/
void UI_EmblemSetRGBTweakedColor_f()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_EmblemMoveLayer_f
==============
*/
void UI_EmblemMoveLayer_f()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_EmblemMoveLayerRelative_f
==============
*/
void UI_EmblemMoveLayerRelative_f()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_EmblemCopy_f
==============
*/
void UI_EmblemCopy_f()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_EmblemCopyLayer_f
==============
*/
void UI_EmblemCopyLayer_f()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_EmblemPasteLayer_f
==============
*/
void UI_EmblemPasteLayer_f()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_EmblemRevertColorChanges_f
==============
*/
void UI_EmblemRevertColorChanges_f()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_EmblemBeginEdit_f
==============
*/
void UI_EmblemBeginEdit_f()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_EmblemEndEdit_f
==============
*/
void UI_EmblemEndEdit_f()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_EmblemSelectBackground_f
==============
*/
void UI_EmblemSelectBackground_f()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_EmblemDump_f
==============
*/
void UI_EmblemDump_f()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_EmblemClearDefaults_f
==============
*/
void __cdecl UI_EmblemClearDefaults_f()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_EmblemSetAsDefault_f
==============
*/
void UI_EmblemSetAsDefault_f()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_EmblemSetFromDefault_f
==============
*/
void UI_EmblemSetFromDefault_f()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_EmblemUploadToSlot_f
==============
*/
void __cdecl UI_EmblemUploadToSlot_f()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_EmblemLoadFromFile_f
==============
*/
void UI_EmblemLoadFromFile_f()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_EmblemSetLeagueIdentity_f
==============
*/
void UI_EmblemSetLeagueIdentity_f()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_EmblemSetClanIdentity_f
==============
*/
void UI_EmblemSetClanIdentity_f()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_EmblemMoveUpRepeatEnabled_f
==============
*/
void UI_EmblemMoveUpRepeatEnabled_f()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_EmblemMoveDownRepeatEnabled_f
==============
*/
void UI_EmblemMoveDownRepeatEnabled_f()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_EmblemMoveLeftRepeatEnabled_f
==============
*/
void UI_EmblemMoveLeftRepeatEnabled_f()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_EmblemMoveRightRepeatEnabled_f
==============
*/
void UI_EmblemMoveRightRepeatEnabled_f()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_EmblemScaleUpRepeatEnabled_f
==============
*/
void UI_EmblemScaleUpRepeatEnabled_f()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_EmblemScaleDownRepeatEnabled_f
==============
*/
void UI_EmblemScaleDownRepeatEnabled_f()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_EmblemRotateLeftRepeatEnabled_f
==============
*/
void UI_EmblemRotateLeftRepeatEnabled_f()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_EmblemRotateRightRepeatEnabled_f
==============
*/
void UI_EmblemRotateRightRepeatEnabled_f()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_EmblemRepeatBttnsLooseFocus_f
==============
*/
void UI_EmblemRepeatBttnsLooseFocus_f()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_EmblemSetPosition_f
==============
*/
void UI_EmblemSetPosition_f()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_EmblemShowFileID_f
==============
*/
void UI_EmblemShowFileID_f()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_GetSlectedSwatchElementColor
==============
*/
vec4_t *UI_GetSlectedSwatchElementColor(vec4_t *result, int row, int column, int totalRows, int totalColumns)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
UI_EmblemSetLayerColorFromSwatch_f
==============
*/
void UI_EmblemSetLayerColorFromSwatch_f()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_EmblemRegisterCmds
==============
*/
void UI_EmblemRegisterCmds()
{
	UNIMPLEMENTED(__FUNCTION__);
}

