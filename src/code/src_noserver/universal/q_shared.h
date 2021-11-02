#include "types.h"

/*
==============
AssignToSmallerType<short>
==============
*/
/*void AssignToSmallerType<short>(__int16 *dest, int src)
{
	UNIMPLEMENTED(__FUNCTION__);
}*/

/*
==============
Com_BitCheckAssert
==============
*/
inline BOOL Com_BitCheckAssert(const unsigned int *array, int bitNum, int size)
{
	assert(array);

	assertIn(bitNum, size * 8);

	return (array[bitNum >> 5] & (1 << (bitNum & 0x1F))) != 0;
}

/*
==============
Com_IsRagdollTrajectory
==============
*/
inline BOOL Com_IsRagdollTrajectory(const trajectory_t *trajectory)
{
	assert(trajectory);

	return trajectory->trType >= 12u && trajectory->trType <= 14u;
}

/*
==============
Com_OnSameTeam
==============
*/
inline BOOL Com_OnSameTeam(team_t team1, team_t team2)
{
	return team1 && team1 == team2;
}

/*
==============
renderOptions_s::GetStowedRenderOptions
==============
*/
/*renderOptions_s renderOptions_s::GetStowedRenderOptions(renderOptions_s *notthis, unsigned int camo, char camoa)
{
	UNIMPLEMENTED(__FUNCTION__);
	renderOptions_s tmp;
	return tmp;
}*/

/*
==============
Com_BitSetAssert
==============
*/
inline void Com_BitSetAssert(unsigned int *array, int bitNum, int size)
{
	assert(array);

	assertIn(bitNum, size * 8);
	array[bitNum >> 5] |= 1 << (bitNum & 0x1F);
}

/*
==============
Com_BitClearAssert
==============
*/
inline void Com_BitClearAssert(unsigned int *array, int bitNum, int size)
{
	assert(array);
	assertIn(bitNum, size * 8);
	array[bitNum >> 5] &= ~(1 << (bitNum & 0x1F));
}

/*
==============
Com_HashString
==============
*/
inline int Com_HashString(const char *fname, int len)
{
	int hash;
	int i;

	if (!fname)
	{
		return 0;
	}

	hash = 5381;
	for (i = 0; fname[i] && (!len || i < len); ++i)
	{
		hash = tolower(fname[i]) + 33 * hash;
	}
	return hash;
}

/*
==============
AssignToSmallerType<signed char>
==============
*/
/*void AssignToSmallerType<signed char>(char *dest, int src)
{
	UNIMPLEMENTED(__FUNCTION__);
}*/

/*
==============
Com_HashLowerString
==============
*/
inline int Com_HashLowerString(const char *fname)
{
	return Com_HashString(fname, 0);
}

/*
==============
Com_HashCatString
==============
*/
inline int Com_HashCatString(int hash, const char *fname, int len)
{
	int i;

	if (!fname)
	{
		return hash;
	}

	for (i = 0; fname[i] && (!len || i < len); ++i)
	{
		hash = tolower(fname[i]) + 33 * hash;
	}
	return hash;
}

