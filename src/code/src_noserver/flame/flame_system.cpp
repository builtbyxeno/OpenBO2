#include "types.h"
#include "functions.h"

/*
==============
FlameAlloc
==============
*/
/*unsigned __int8 *FlameAlloc@<eax>(const char *a1@<edx>, char *a2@<ecx>, unsigned int size, const char *name)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}*/

/*
==============
FlameFree
==============
*/
void FlameFree(void *ptr, const char *name)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Flame_Init_FlameVars
==============
*/
void Flame_Init_FlameVars()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Flame_Init_DVars
==============
*/
void Flame_Init_DVars()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Flame_CMD_PrintDVarsToConsol
==============
*/
void Flame_CMD_PrintDVarsToConsol()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Flame_CMD_Test_Toggle
==============
*/
void Flame_CMD_Test_Toggle()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Flame_CMD_Use_Dvars_Toggle
==============
*/
void Flame_CMD_Use_Dvars_Toggle()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Flame_DVarsToFlameVars
==============
*/
void Flame_DVarsToFlameVars(flameTable *fTable)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Flame_FindFlameTable
==============
*/
flameTable *Flame_FindFlameTable(const char *tableName)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Flame_SwayRand
==============
*/
long double Flame_SwayRand(float x, float y, int time)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
SV_Flame_Source_Get
==============
*/
flameSource_t *SV_Flame_Source_Get(int entityNum)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Flame_Source_Get
==============
*/
flameSource_t *Flame_Source_Get(int entityNum)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Flame_Get_FlameRender
==============
*/
flameRender_s *Flame_Get_FlameRender(const char *name)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Flame_Item_Init
==============
*/
void Flame_Item_Init(flameGeneric_s *item, int itemSize)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Flame_List_Init
==============
*/
void Flame_List_Init(flameGeneric_s *list, int itemSize, int listSize)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Flame_List_Move_Global
==============
*/
void Flame_List_Move_Global(flameGeneric_s *item, flameGeneric_s **fromList, flameGeneric_s **toList)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Flame_List_Add_Local
==============
*/
void Flame_List_Add_Local(flameGeneric_s *item, flameGeneric_s **localList)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Flame_List_Sub_Local
==============
*/
void Flame_List_Sub_Local(flameGeneric_s *item, flameGeneric_s **localList)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Flame_Source_Alloc
==============
*/
flameSource_t *Flame_Source_Alloc(int entityNum)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
SV_Flame_Source_Alloc
==============
*/
flameSource_t *SV_Flame_Source_Alloc(int entityNum)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Flame_Render_Sprite
==============
*/
void Flame_Render_Sprite(cg_t *clientGlobals, Material *material, flameGeneric_s *flameGeneric, float alpha, float frame, unsigned __int8 col)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Flame_Render_Sprites
==============
*/
void Flame_Render_Sprites(int a1, cg_t *clientGlobals, Material *material, flameGeneric_s **flameGenericList, int numItems, unsigned __int8 col)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Flame_GetLocalClientFlameSource
==============
*/
int Flame_GetLocalClientFlameSource(LocalClientNum_t localClientNum, int EntNum)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Flame_GetLocalClientSourceRange
==============
*/
char Flame_GetLocalClientSourceRange(LocalClientNum_t localClientNum, int EntNum)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Flame_GetTrueFlameSourceEntityNum
==============
*/
int Flame_GetTrueFlameSourceEntityNum(int EntNum)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
SV_Flame_Update_Source_Internal
==============
*/
void SV_Flame_Update_Source_Internal(flameSource_t *source, int entityNum, flameWeaponConfig_t *weaponConfig, int time)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SV_Flame_Update_Source
==============
*/
void SV_Flame_Update_Source(int entityNum, flameWeaponConfig_t *weaponConfig, int time)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Flame_Generate_Verts
==============
*/
void Flame_Generate_Verts(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_Flame_Update_ViewModel
==============
*/
void CG_Flame_Update_ViewModel(LocalClientNum_t localClientNum, centity_t *cent)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Flame_Random
==============
*/
double Flame_Random(bool is_server)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Flame_CRandom
==============
*/
double Flame_CRandom(bool is_server)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Flame_CalcTimeScale
==============
*/
double Flame_CalcTimeScale(int startTime, int endTime)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Flame_CalcInvStartSpeed
==============
*/
double Flame_CalcInvStartSpeed(float invInitialSpeed, float speedScale)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Flame_System_Allocate
==============
*/
void Flame_System_Allocate(int max_flame_sources)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Flame_System_Release
==============
*/
void Flame_System_Release()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Flame_Init_Sources
==============
*/
void Flame_Init_Sources()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Flame_InitDevGui
==============
*/
void Flame_InitDevGui()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Flame_Init
==============
*/
void Flame_Init()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Flame_Reset
==============
*/
void Flame_Reset()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_Flame_Age_All_Objects
==============
*/
void CG_Flame_Age_All_Objects(int time, LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SV_Flame_Age_All_Objects
==============
*/
void SV_Flame_Age_All_Objects(int time)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_Flame_Update_Source
==============
*/

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
}

/*
==============
Flame_Enable_And_Allocate
==============
*/
void Flame_Enable_And_Allocate(void *buffer, unsigned int bufsize, int max_flame_sources, int max_flame_chunks, int max_flame_drips, int max_flame_fire, int max_flame_smoke, int max_flame_streams)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Flame_System_Disable
==============
*/
void Flame_System_Disable()
{
	UNIMPLEMENTED(__FUNCTION__);
}

