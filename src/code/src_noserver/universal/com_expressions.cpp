#include "types.h"

/*
==============
GetOperandAsString
==============
*/
char *GetOperandAsString(Operand operand)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Expression_Free
==============
*/
void Expression_Free(ExpressionStatement *statement)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Expression_Alloc
==============
*/
expressionEntry *Expression_Alloc(ExpressionAllocState *allocState, int size)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Expression_ParseOperatorToken
==============
*/
int Expression_ParseOperatorToken(const char *token)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Expression_HashOperand
==============
*/
expressionEntry *Expression_HashOperand(int a1, ExpressionAllocState *a2, const char *str)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
MakeRPN
==============
*/
expressionRpn *MakeRPN(expressionEntry *entry, int *length)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Expression_Parse
==============
*/
char Expression_Parse(const char **text, ExpressionStatement *statement, void *compileBuffer, int compileBufferSize)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Expression_Read
==============
*/
char Expression_Read(int handle, ExpressionStatement *statement)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Expression_Init
==============
*/
void Expression_Init()
{
	UNIMPLEMENTED(__FUNCTION__);
}

