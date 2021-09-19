#pragma once

#include "types.h"

//t6/code/src_noserver/devgui/devgui.cpp
void TRACK_devgui();
const dvar_t *DevGui_RegisterDvars();
DevMenuItem *DevGui_GetMenu(unsigned __int16 handle);
unsigned __int16 DevGui_GetMenuParent(unsigned __int16 handle);
bool DevGui_EditableMenuItem(const DevMenuItem *menu);
void DevGui_FreeMenu_r(unsigned __int16 handle);
unsigned __int16 DevGui_FindMenu(unsigned __int16 parentHandle, const char *label);
int DevGui_PathToken(const char **pathInOut, char *label, __int16 *sortKeyOut);
unsigned __int16 DevGui_ConstructPath_r(unsigned __int16 parent, const char *path);
bool DevGui_IsValidPath(const char *path);
void DevGui_AddDvar(const char *path, const dvar_t *dvar);
void DevGui_AddDvarList(const char *path, const dvar_t *dvar);
void DevGui_AddCommand(const char *path, const char *command);
bool DevGui_DoesMenuExist(const char *path);
void DevGui_RemoveMenu(const char *path);
void DevGui_OpenMenu(const char *path);
int DevGui_MaxChildMenuWidth(LocalClientNum_t localClientNum, const DevMenuItem *menu);
void DevGui_DrawMenuVertically(;
void DevGui_DrawMenuHorizontally(;
void DevGui_DrawMenu(;
void DevGui_ChooseOrigin(LocalClientNum_t localClientNum, int *origin);
unsigned int DevGui_GetSliderPath(unsigned __int16 menuHandle, char *path, int pathLen);
void DevGui_DrawSliderTitle(int x, int y, const DevMenuItem *menu);
void DevGui_DrawSingleSlider(;
;
int DevGui_MenuRowCount(const DevMenuItem *menu);
const dvar_t *DevGui_SelectedDvarFromMenu(const DevMenuItem *menu);
void DevGui_DrawSliders(const DevMenuItem *menu);
void DevGui_DrawBindNextKey();
void DevGui_DrawGraph(const DevMenuItem *menu, LocalClientNum_t localClientNum);
void DevGui_Draw(LocalClientNum_t localClientNum);
void DevGui_AdvanceChildNum(int numberToAdvance);
void DevGui_SelectTopLevelChild();
void DevGui_Init();
void DevGui_Shutdown();
void DevGui_KeyPressed(int key);
void DevGui_Toggle();
bool DevGui_IsActive();
void DevGui_AddGraph(const char *path, DevGraph *graph);

//t6/code/src_noserver/devgui/devgui_input.cpp
void DevGui_InputInit();
void DevGui_InputShutdown();
void DevGui_SelectGamepad(ControllerIndex_t gamePadIndex);
void DevGui_MouseEvent(int dx, int dy);
bool DevGui_IsButtonDown(DevGuiInputButton button);

//t6/code/src_noserver/devgui/devgui_util.cpp
int DevGui_GetScreenXPad();
void DevGui_DrawBevelBox(int x, int y, int w, int h);
void DevGui_DrawLine(vec2_t *start, vec2_t *end, int width, const unsigned __int8 *color);

