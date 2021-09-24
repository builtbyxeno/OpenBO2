#include "types.h"

/*
==============
TRACK_scr_animtree
==============
*/
void TRACK_scr_animtree()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
AnimTreeCompileError
==============
*/
void AnimTreeCompileError(scriptInstance_t inst, const char *msg)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
ScriptTokenizer::ParseIntoTokens
==============
*/
/*void ScriptTokenizer::ParseIntoTokens(ScriptTokenizer *notthis, const char *strString)
{
	UNIMPLEMENTED(__FUNCTION__);
}*/

/*
==============
SetAnimCheck
==============
*/
void SetAnimCheck(scriptInstance_t inst, int bAnimCheck)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Scr_EmitAnimationInternal
==============
*/
void Scr_EmitAnimationInternal(scriptInstance_t inst, unsigned __int8 *pos, unsigned int animName, unsigned int names, unsigned int sourcePos)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Scr_EmitAnimation
==============
*/
void Scr_EmitAnimation(scriptInstance_t a1, unsigned int a2, scriptInstance_t inst, unsigned __int8 *pos, unsigned int animName, unsigned int sourcePos)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Hunk_AllocXAnimPrecache
==============
*/
unsigned __int8 *Hunk_AllocXAnimPrecache(int size)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Scr_GetAnimTreeSize
==============
*/
int Scr_GetAnimTreeSize(scriptInstance_t inst, unsigned int parentNode)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Scr_GetAnimTreeValueCount
==============
*/
int Scr_GetAnimTreeValueCount(scriptInstance_t inst, unsigned int rootData)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
ConnectScriptToAnim
==============
*/
void ConnectScriptToAnim(scriptInstance_t inst, unsigned int names, int index, unsigned int filename, unsigned int name, int treeIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Scr_GetAnimsIndex
==============
*/
int Scr_GetAnimsIndex(scriptInstance_t inst, const XAnim_s *anims)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Scr_GetClientAnims
==============
*/
XAnim_s *Scr_GetClientAnims(scriptInstance_t inst, unsigned int index)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Scr_GetAnims
==============
*/
XAnim_s *Scr_GetAnims(scriptInstance_t inst, unsigned int index)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Scr_ProcessNodeValues
==============
*/
void Scr_ProcessNodeValues(scriptInstance_t inst, XAnim_s *anims, unsigned int name, unsigned int rootNode, unsigned int animIndex, unsigned int arrayNode, void *(*Alloc)(int))
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Scr_CreateAnimationTree
==============
*/
int __cdecl Scr_CreateAnimationTree(scriptInstance_t inst, unsigned int parentNode, unsigned int rootData, unsigned int names, XAnim_s *anims, unsigned int childIndex, const char *parentName, unsigned int parentIndex, unsigned int filename, int treeIndex, unsigned __int16 flags, void *(__cdecl *Alloc)(int), unsigned int paramMap)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CreateValues
==============
*/
void CreateValues(scriptInstance_t inst, XAnim_s *anims, unsigned int valueArray)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Scr_CheckAnimsDefined
==============
*/
void Scr_CheckAnimsDefined(scriptInstance_t inst, unsigned int names, unsigned int filename)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Scr_PrecacheAnimationTree
==============
*/
void Scr_PrecacheAnimationTree(scriptInstance_t inst, unsigned int parentNode)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Scr_UsingTreeInternal
==============
*/
unsigned int Scr_UsingTreeInternal(scriptInstance_t inst, const char *filename, unsigned int *index, int user)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Scr_ClientUsingTree
==============
*/
void __cdecl Scr_ClientUsingTree(scriptInstance_t inst, const char *filename)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Scr_CreateAllAnimTreeData
==============
*/
int Scr_CreateAllAnimTreeData(scriptInstance_t inst, unsigned int rootData, unsigned int names, scr_animtree_t *animtree, unsigned int filenameId, unsigned int index, void *(__cdecl *Alloc)(int))
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CScr_RetrieveAnimTree
==============
*/
scr_animtree_t CScr_RetrieveAnimTree(const char *strAnimTreeName, unsigned int names, unsigned int filename, int iOurTreeIx)
{
	UNIMPLEMENTED(__FUNCTION__);
	scr_animtree_t tmp;
	return tmp;
}

/*
==============
Scr_FindAnimTree
==============
*/
scr_animtree_t Scr_FindAnimTree(scriptInstance_t inst, const char *filename)
{
	UNIMPLEMENTED(__FUNCTION__);
	scr_animtree_t tmp;
	return tmp;
}

/*
==============
Scr_FindAnim
==============
*/
void __cdecl Scr_FindAnim(scriptInstance_t inst, const char *filename, const char *animName, scr_anim_s *anim, int user)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Scr_ShutdownAnimTrees
==============
*/
void Scr_ShutdownAnimTrees(int user)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
ScriptTokenizer::PushNextToken
==============
*/
/*void ScriptTokenizer::PushNextToken(ScriptTokenizer *notthis)
{
	UNIMPLEMENTED(__FUNCTION__);
}*/

/*
==============
Scr_UsingTree
==============
*/
void __cdecl Scr_UsingTree(scriptInstance_t inst, const char *filename, unsigned int sourcePos)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
ScriptTokenizer::PopToken
==============
*/
/*const char *ScriptTokenizer::PopToken(ScriptTokenizer *notthis)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}*/

/*
==============
ScriptTokenizer::PeekIsChar
==============
*/
/*bool ScriptTokenizer::PeekIsChar(ScriptTokenizer *notthis, char cTestChar)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}*/

/*
==============
GetAnimTreeParseProperties
==============
*/
int GetAnimTreeParseProperties(ScriptTokenizer *tokenizer, unsigned int currentAnim, int *piNumComponents)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
DetermineValueType
==============
*/
ValueType DetermineValueType(ScriptTokenizer *tokenizer)
{
	UNIMPLEMENTED(__FUNCTION__);
	ValueType tmp;
	return tmp;
}

/*
==============
ParseValueFromValueList
==============
*/
unsigned int ParseValueFromValueList(ScriptTokenizer *tokenizer, scriptInstance_t inst, unsigned int valueName)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
ParseNode
==============
*/
char ParseNode(int *a1, ScriptTokenizer *tokenizer, scriptInstance_t inst, unsigned int parentNode, unsigned int rootData, unsigned int names, bool bLoop, bool bComplete)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
AnimTreeParseInternal
==============
*/
bool AnimTreeParseInternal(scriptInstance_t inst, unsigned int parentNode, unsigned int names, bool bIncludeParent, bool bLoop, bool bComplete)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Scr_AnimTreeParse
==============
*/
void Scr_AnimTreeParse(scriptInstance_t inst, const char *pos, unsigned int parentNode, unsigned int names)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Scr_LoadAnimTreeInternal
==============
*/
bool Scr_LoadAnimTreeInternal(scriptInstance_t inst, const char *filename, unsigned int parentNode, unsigned int names)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Scr_LoadAnimTreeAtIndex
==============
*/
void __cdecl Scr_LoadAnimTreeAtIndex(scriptInstance_t inst, unsigned int index, void *(__cdecl *Alloc)(int), int user, bool modCheckSum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

