#include "types.h"
#include "functions.h"

/*
==============
GetExpressionCount
==============
*/
int GetExpressionCount(sval_u exprlist)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
TRACK_scr_compiler
==============
*/
void TRACK_scr_compiler()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Scr_CompileRemoveRefToString
==============
*/
void Scr_CompileRemoveRefToString(scriptInstance_t inst, unsigned int stringValue)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
EmitCanonicalString
==============
*/
void EmitCanonicalString(scriptInstance_t inst, unsigned int stringValue)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CompileTransferRefToString
==============
*/
void CompileTransferRefToString(scriptInstance_t inst, unsigned int stringValue, unsigned int user)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
EmitAssignmentPos
==============
*/
void EmitAssignmentPos(scriptInstance_t inst)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
EmitCodepos
==============
*/
void EmitCodepos(scriptInstance_t inst, unsigned __int8 *pos)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
EmitShort
==============
*/
void EmitShort(scriptInstance_t inst, __int16 value)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
EvalUndefined
==============
*/
void EvalUndefined(sval_u sourcePos, VariableCompileValue *constValue)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
EvalInteger
==============
*/
void EvalInteger(int value, sval_u sourcePos, VariableCompileValue *constValue)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
EmitGetInteger
==============
*/
void EmitGetInteger(scriptInstance_t inst, int value, sval_u sourcePos)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
EvalFloat
==============
*/
void EvalFloat(float value, sval_u sourcePos, VariableCompileValue *constValue)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
EmitAnimTree
==============
*/

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
}

/*
==============
Scr_InitFromChildBlocks
==============
*/
void Scr_InitFromChildBlocks(scr_block_s **childBlocks, int childCount, scr_block_s *block)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Scr_TransferBlock
==============
*/
void Scr_TransferBlock(scr_block_s *from, scr_block_s *to)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
EvalString
==============
*/
void EvalString(unsigned int value, sval_u sourcePos, VariableCompileValue *constValue)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
EmitGetString
==============
*/

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
}

/*
==============
EvalIString
==============
*/
void EvalIString(unsigned int value, sval_u sourcePos, VariableCompileValue *constValue)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
EmitGetIString
==============
*/

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
}

/*
==============
EmitGetVector
==============
*/
void EmitGetVector(scriptInstance_t inst, const float *value, sval_u sourcePos)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
EmitValue
==============
*/
void EmitValue(scriptInstance_t inst, VariableCompileValue *constValue)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Scr_PushValue
==============
*/
void Scr_PushValue(scriptInstance_t inst, VariableCompileValue *constValue)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
EmitExpressionList
==============
*/
int EmitExpressionList(scriptInstance_t inst, sval_u exprlist, scr_block_s *block)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
AddFilePrecache
==============
*/
void AddFilePrecache(scriptInstance_t inst, unsigned int filename, unsigned int sourcePos, bool include, unsigned int *filePosId, unsigned int *fileCountId)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
EmitFunction
==============
*/
void EmitFunction(scriptInstance_t inst, sval_u func, sval_u sourcePos)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Scr_GetBuiltin
==============
*/
unsigned int Scr_GetBuiltin(scriptInstance_t inst, sval_u func_name)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Scr_BeginDevScript
==============
*/
void Scr_BeginDevScript(scriptInstance_t inst, int *type, unsigned __int8 **savedPos)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Scr_EndDevScript
==============
*/
void Scr_EndDevScript(scriptInstance_t inst, int type, unsigned __int8 **savedPos)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Scr_GetCacheType
==============
*/
int Scr_GetCacheType(int type)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Scr_GetUncacheType
==============
*/
int Scr_GetUncacheType(int type)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Scr_CreateVector
==============
*/
void Scr_CreateVector(scriptInstance_t inst, VariableCompileValue *constValue, VariableValue *value)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
EvalBinaryOperatorExpression
==============
*/
char EvalBinaryOperatorExpression(scriptInstance_t inst, sval_u expr1, sval_u expr2, sval_u opcode, sval_u sourcePos, VariableCompileValue *constValue)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
ConnectBreakStatements
==============
*/
void ConnectBreakStatements(scriptInstance_t inst)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
ConnectContinueStatements
==============
*/
void ConnectContinueStatements(scriptInstance_t inst)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Scr_AddBreakBlock
==============
*/
void Scr_AddBreakBlock(scriptInstance_t inst, scr_block_s *block)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Scr_AddContinueBlock
==============
*/
void Scr_AddContinueBlock(scriptInstance_t inst, scr_block_s *block)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CompareCaseInfo
==============
*/
int CompareCaseInfo(const void *elem1, const void *elem2)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
EmitCaseStatementInfo
==============
*/
void EmitCaseStatementInfo(scriptInstance_t inst, unsigned int name, sval_u sourcePos)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
EmitStatementList
==============
*/
void EmitStatementList(scriptInstance_t inst, sval_u val, bool lastStatement, unsigned int endSourcePos, scr_block_s *block)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
EmitOpcode
==============
*/
void EmitOpcode(VariableCompileValue *a1, scriptInstance_t inst, unsigned int op, int offset, int callType)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Scr_FindLocalVarIndex
==============
*/
int Scr_FindLocalVarIndex(scriptInstance_t inst, unsigned int name, sval_u sourcePos, bool create, scr_block_s *block)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
EmitCreateLocalVars
==============
*/
void EmitCreateLocalVars(VariableCompileValue *a1, scriptInstance_t inst, scr_block_s *block)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
EmitRemoveLocalVars
==============
*/
void EmitRemoveLocalVars(scriptInstance_t inst, scr_block_s *block, scr_block_s *outerBlock)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
EmitNOP2
==============
*/

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
}

/*
==============
EmitSelfObject
==============
*/
void EmitSelfObject(scriptInstance_t inst, sval_u sourcePos)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
EmitLevelObject
==============
*/
void EmitLevelObject(scriptInstance_t inst, sval_u sourcePos)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
EmitAnimObject
==============
*/
void EmitAnimObject(scriptInstance_t inst, sval_u sourcePos)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
EmitLocalVariable
==============
*/

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
}

/*
==============
EmitLocalVariableRef
==============
*/

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
}

/*
==============
EmitAnimation
==============
*/
void EmitAnimation(scriptInstance_t inst, sval_u anim, sval_u sourcePos)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
EmitAnimationAnimTree
==============
*/
void EmitAnimationAnimTree(scriptInstance_t inst, sval_u anim, sval_u animtree, sval_u sourcePos)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
EmitObject
==============
*/
void EmitObject(scriptInstance_t inst, sval_u expr, sval_u sourcePos)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
EmitCastFieldObject
==============
*/
void EmitCastFieldObject(scriptInstance_t inst, sval_u sourcePos)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
EmitArrayVariable
==============
*/
void EmitArrayVariable(scriptInstance_t inst, sval_u expr, sval_u index, sval_u sourcePos, sval_u indexSourcePos, scr_block_s *block)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
EmitCallBuiltinMethodOpcode
==============
*/
void EmitCallBuiltinMethodOpcode(scriptInstance_t inst, int param_count, sval_u sourcePos)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
EmitCall
==============
*/
void EmitCall(scriptInstance_t inst, sval_u func_name, sval_u params, bool bStatement, scr_block_s *block)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
EmitMethod
==============
*/
void EmitMethod(scriptInstance_t inst, sval_u expr, sval_u func_name, sval_u params, sval_u methodSourcePos, bool bStatement, scr_block_s *block)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
EmitCallExpression
==============
*/

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
}

/*
==============
EmitCallExpressionFieldObject
==============
*/

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
}

/*
==============
EvalPrimitiveExpressionList
==============
*/
bool EvalPrimitiveExpressionList(scriptInstance_t inst, sval_u exprlist, sval_u sourcePos, VariableCompileValue *constValue)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
EmitOrEvalPrimitiveExpressionList
==============
*/
bool EmitOrEvalPrimitiveExpressionList(VariableCompileValue *a1, scriptInstance_t inst, sval_u exprlist, sval_u sourcePos, VariableCompileValue *constValue, scr_block_s *block)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
EmitExpressionListFieldObject
==============
*/
void EmitExpressionListFieldObject(scriptInstance_t inst, sval_u exprlist, sval_u sourcePos, scr_block_s *block)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
EvalPrimitiveExpression
==============
*/

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
}

/*
==============
EmitBoolOrExpression
==============
*/
void EmitBoolOrExpression(scriptInstance_t inst, sval_u expr1, sval_u expr2, sval_u expr1sourcePos, sval_u expr2sourcePos, scr_block_s *block)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
EmitBoolAndExpression
==============
*/
void EmitBoolAndExpression(scriptInstance_t inst, sval_u expr1, sval_u expr2, sval_u expr1sourcePos, sval_u expr2sourcePos, scr_block_s *block)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
EmitOrEvalBinaryOperatorExpression
==============
*/
bool EmitOrEvalBinaryOperatorExpression(scriptInstance_t inst, sval_u expr1, sval_u expr2, sval_u opcode, sval_u sourcePos, VariableCompileValue *constValue, scr_block_s *block)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
EmitArrayPrimitiveExpressionRef
==============
*/
void EmitArrayPrimitiveExpressionRef(scriptInstance_t inst, sval_u expr, sval_u sourcePos, scr_block_s *block)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
EmitPrimitiveExpressionFieldObject
==============
*/

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
}

/*
==============
EmitCallExpressionStatement
==============
*/

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
}

/*
==============
EmitEndStatement
==============
*/
void EmitEndStatement(scriptInstance_t inst, sval_u sourcePos, scr_block_s *block)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
EmitFormalWaittillParameterListRefInternal
==============
*/
void EmitFormalWaittillParameterListRefInternal(scriptInstance_t inst, sval_u *node, scr_block_s *block)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
EmitCaseStatement
==============
*/

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
}

/*
==============
EmitSwitchStatementList
==============
*/
void EmitSwitchStatementList(scriptInstance_t inst, sval_u val, bool lastStatement, unsigned int endSourcePos, scr_block_s *block)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
EmitBreakStatement
==============
*/

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
}

/*
==============
EmitContinueStatement
==============
*/

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
}

/*
==============
EmitDeveloperStatementList
==============
*/
void EmitDeveloperStatementList(scriptInstance_t inst, sval_u val, sval_u sourcePos, scr_block_s *block, sval_u *devStatBlock)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
EmitClearFieldVariable
==============
*/
void EmitClearFieldVariable(scriptInstance_t inst, sval_u expr, sval_u field, sval_u sourcePos, sval_u rhsSourcePos, scr_block_s *block)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
EmitVariableExpression
==============
*/

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
}

/*
==============
EmitOrEvalPrimitiveExpression
==============
*/
bool EmitOrEvalPrimitiveExpression(VariableCompileValue *a1, scriptInstance_t inst, sval_u expr, VariableCompileValue *constValue, scr_block_s *block)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
EmitOrEvalExpression
==============
*/
/*bool EmitOrEvalExpression@<al>(const char *a1@<edi>, scriptInstance_t inst, sval_u expr, VariableCompileValue *constValue, scr_block_s *block)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}*/

/*
==============
EmitExpression
==============
*/
void EmitExpression(scriptInstance_t inst, sval_u expr, scr_block_s *block)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
EmitReturnStatement
==============
*/
void EmitReturnStatement(scriptInstance_t inst, sval_u expr, sval_u sourcePos, scr_block_s *block)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
EmitIfStatement
==============
*/
void EmitIfStatement(scriptInstance_t inst, sval_u expr, sval_u stmt, sval_u sourcePos, bool lastStatement, unsigned int endSourcePos, scr_block_s *block, sval_u *ifStatBlock)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
EmitIfElseStatement
==============
*/
void EmitIfElseStatement(scriptInstance_t inst, sval_u expr, sval_u stmt1, sval_u stmt2, sval_u sourcePos, sval_u elseSourcePos, bool lastStatement, unsigned int endSourcePos, scr_block_s *block, sval_u *ifStatBlock, sval_u *elseStatBlock)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
EmitWhileStatement
==============
*/
void EmitWhileStatement(scriptInstance_t inst, sval_u expr, sval_u stmt, sval_u sourcePos, sval_u whileSourcePos, scr_block_s *block, sval_u *whileStatBlock)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
EmitForStatement
==============
*/
void EmitForStatement(scriptInstance_t inst, sval_u stmt1, sval_u expr, sval_u stmt2, sval_u stmt, sval_u sourcePos, sval_u forSourcePos, scr_block_s *block, sval_u *forStatBlock, sval_u *forStatPostBlock)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
EmitWaittillStatement
==============
*/
void EmitWaittillStatement(scriptInstance_t inst, sval_u obj, sval_u exprlist, sval_u sourcePos, sval_u waitSourcePos, scr_block_s *block)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
EmitWaittillmatchStatement
==============
*/
void EmitWaittillmatchStatement(scriptInstance_t inst, sval_u obj, sval_u exprlist, sval_u sourcePos, sval_u waitSourcePos, scr_block_s *block)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
EmitNotifyStatement
==============
*/
void EmitNotifyStatement(scriptInstance_t inst, sval_u obj, sval_u exprlist, sval_u sourcePos, sval_u notifySourcePos, scr_block_s *block)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
EmitEndOnStatement
==============
*/
void EmitEndOnStatement(scriptInstance_t inst, sval_u obj, sval_u expr, sval_u sourcePos, sval_u exprSourcePos, scr_block_s *block)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
EmitSwitchStatement
==============
*/
/*void EmitSwitchStatement(const char *a1@<edi>, scriptInstance_t inst, sval_u expr, sval_u stmtlist, sval_u sourcePos, bool lastStatement, unsigned int endSourcePos, scr_block_s *block)
{
	UNIMPLEMENTED(__FUNCTION__);
}*/

/*
==============
EmitArrayVariableRef
==============
*/
void EmitArrayVariableRef(scriptInstance_t inst, sval_u expr, sval_u index, sval_u sourcePos, sval_u indexSourcePos, scr_block_s *block)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
EmitClearArrayVariable
==============
*/
void EmitClearArrayVariable(scriptInstance_t inst, sval_u expr, sval_u index, sval_u sourcePos, sval_u indexSourcePos, scr_block_s *block)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
EmitVariableExpressionRef
==============
*/

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
}

/*
==============
EmitClearVariableExpression
==============
*/

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
}

/*
==============
EmitAssignmentStatement
==============
*/
void EmitAssignmentStatement(scriptInstance_t inst, sval_u lhs, sval_u rhs, sval_u sourcePos, sval_u rhsSourcePos, scr_block_s *block)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
EmitIncStatement
==============
*/
void EmitIncStatement(scriptInstance_t inst, sval_u expr, sval_u sourcePos, scr_block_s *block)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
EmitDecStatement
==============
*/
void EmitDecStatement(scriptInstance_t inst, sval_u expr, sval_u sourcePos, scr_block_s *block)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
EmitBinaryEqualsOperatorExpression
==============
*/
void EmitBinaryEqualsOperatorExpression(scriptInstance_t inst, sval_u lhs, sval_u rhs, sval_u opcode, sval_u sourcePos, scr_block_s *block)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
EmitStatement
==============
*/

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
}

/*
==============
Scr_CompileStatement
==============
*/
void Scr_CompileStatement(scr_block_s *a1, scriptInstance_t inst, sval_u parseData)
{
	UNIMPLEMENTED(__FUNCTION__);
}

