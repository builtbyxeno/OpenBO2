#include "types.h"
#include "functions.h"

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
/*void __thiscall ScriptTokenizer::ParseIntoTokens(ScriptTokenizer *this, const char *strString)
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

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
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

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
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

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
}

/*
==============
Scr_CreateAllAnimTreeData
==============
*/

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
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

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
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
/*void __thiscall ScriptTokenizer::PushNextToken(ScriptTokenizer *this)
{
	UNIMPLEMENTED(__FUNCTION__);
}*/

/*
==============
Scr_UsingTree
==============
*/

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
}

/*
==============
ScriptTokenizer::PopToken
==============
*/
/*const char *__thiscall ScriptTokenizer::PopToken(ScriptTokenizer *this)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}*/

/*
==============
ScriptTokenizer::PeekIsChar
==============
*/
/*bool __thiscall ScriptTokenizer::PeekIsChar(ScriptTokenizer *this, char cTestChar)
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

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
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

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
}

