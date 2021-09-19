#include "types.h"
#include "functions.h"

/*
==============
TRACK_scr_evaluate
==============
*/
void TRACK_scr_evaluate()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Scr_InitEvaluate
==============
*/
void Scr_InitEvaluate()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Scr_GetValueString
==============
*/
void Scr_GetValueString(scriptInstance_t inst, unsigned int localId, VariableValue *value, int len, char *s)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Scr_ClearValue
==============
*/
void Scr_ClearValue(scriptInstance_t inst, VariableValue *value)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Scr_EvalArrayVariableInternal
==============
*/
void Scr_EvalArrayVariableInternal(scriptInstance_t inst, VariableValue *parentValue, VariableValue *value)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Scr_EvalLocalVariable
==============
*/
void Scr_EvalLocalVariable(scriptInstance_t inst, sval_u expr, unsigned int localId, VariableValue *value)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Scr_EvalObject
==============
*/
unsigned int Scr_EvalObject(scriptInstance_t inst, sval_u classnum, sval_u entnum, VariableValue *value)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Scr_EvalSelfValue
==============
*/
void Scr_EvalSelfValue(scriptInstance_t inst, VariableValue *value)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Scr_GetValue
==============
*/
void Scr_GetValue(scriptInstance_t inst, unsigned int index, VariableValue *value)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Scr_EvalFieldVariableInternal
==============
*/
void Scr_EvalFieldVariableInternal(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Scr_CompilePrimitiveExpressionList
==============
*/
void Scr_CompilePrimitiveExpressionList(scriptInstance_t inst, sval_u *exprlist)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Scr_CompileCallExpressionList
==============
*/
void Scr_CompileCallExpressionList(scriptInstance_t inst, sval_u *exprlist)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Scr_CompileFunction
==============
*/
bool Scr_CompileFunction(scriptInstance_t inst, sval_u *func_name, sval_u *params)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Scr_CompileMethod
==============
*/
char Scr_CompileMethod(scriptInstance_t inst, sval_u *expr, sval_u *func_name, sval_u *params)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Scr_CompileCallExpression
==============
*/
char Scr_CompileCallExpression(scriptInstance_t inst, sval_u *expr)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Scr_PreEvalBuiltin
==============
*/
void Scr_PreEvalBuiltin(scriptInstance_t inst, sval_u params, unsigned int localId)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Scr_PostEvalBuiltin
==============
*/
void Scr_PostEvalBuiltin(scriptInstance_t inst, VariableValue *value)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Scr_EvalFunction
==============
*/
void Scr_EvalFunction(scriptInstance_t inst, sval_u func_name, sval_u params, unsigned int localId)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Scr_EvalMethod
==============
*/
void Scr_EvalMethod(scriptInstance_t inst, sval_u expr, sval_u func_name, sval_u params, unsigned int localId)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Scr_EvalCallExpression
==============
*/
void Scr_EvalCallExpression(scriptInstance_t inst, sval_u expr, unsigned int localId, VariableValue *value)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Scr_EvalBoolOrExpression
==============
*/
void Scr_EvalBoolOrExpression(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Scr_EvalBoolAndExpression
==============
*/
void Scr_EvalBoolAndExpression(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Scr_EvalVector
==============
*/
void Scr_EvalVector(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Scr_FreeDebugExprValue
==============
*/
void Scr_FreeDebugExprValue(scriptInstance_t inst, sval_u val)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Scr_EvalPrimitiveExpressionFieldObject
==============
*/
unsigned int Scr_EvalPrimitiveExpressionFieldObject(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Scr_CompilePrimitiveExpressionFieldObject
==============
*/
void Scr_CompilePrimitiveExpressionFieldObject(scriptInstance_t inst, sval_u *expr)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Scr_EvalVariableExpression
==============
*/
void Scr_EvalVariableExpression(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Scr_CompileVariableExpression
==============
*/
/*void Scr_CompileVariableExpression(sval_u *a1@<edx>, scriptInstance_t inst, sval_u *expr)
{
	UNIMPLEMENTED(__FUNCTION__);
}*/

/*
==============
Scr_EvalPrimitiveExpression
==============
*/
void Scr_EvalPrimitiveExpression(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Scr_CompilePrimitiveExpression
==============
*/
void Scr_CompilePrimitiveExpression(scriptInstance_t inst, sval_u *expr)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Scr_EvalExpression
==============
*/
void Scr_EvalExpression(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Scr_CompileExpression
==============
*/
void Scr_CompileExpression(scriptInstance_t inst, sval_u *expr)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Scr_CompileTextInternal
==============
*/
void Scr_CompileTextInternal(scriptInstance_t inst, const char *text, ScriptExpression_t *scriptExpr)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Scr_CompileText
==============
*/
void Scr_CompileText(scriptInstance_t inst, const char *text, ScriptExpression_t *scriptExpr)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Scr_EvalScriptExpression
==============
*/
char Scr_EvalScriptExpression(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Scr_GetValue
==============
*/
VariableValue *Scr_GetValue(scriptInstance_t inst, unsigned int index)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

